const express = require("express");
const app = express();
const http = require('http');
const server = http.createServer(app);
const socket = require('./sockets');
const { Logger } = require("./schemas/logger_schema");
const utils = require("./utils");
const cors = require('cors');
const bp = require('body-parser');

const loggerRoute = require('./routes/logger_routes');

const config = require('config');
const PORT = config.get('port');
const  connections = require('./data_base/connections');

const webSocket = require("socket.io")(server, {
  transports: ["websocket", "polling"]
});

connections.connectMongoDb();

app.use(cors());
app.use(bp.json());
app.use(bp.urlencoded({ extended: true }));
app.use('/',loggerRoute);


app.post('/', async (req,res)=> {
  let IsEventExist;
  try {
    IsEventExist = await Logger.findOne({id : req.body.id});
  }

  catch(err) {
    console.log(err);
    return res.status(403);
  }

  if(IsEventExist) {
      return res.status(403);
  }

  const msgObj = utils.CreateLoggerObj(req.body);

  let newMessageObj;
  
  try {
    newMessageObj = new Logger(msgObj);
    newMessageObj.save();
    socket.broadCastClients(webSocket,msgObj);
  }
  catch(err) {
    console.log(err);
  }
});

server.listen(PORT, () => {console.log(`Listening on port: ${PORT}`)});