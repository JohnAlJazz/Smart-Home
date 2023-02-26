const app = require('./app');
const http = require('http');

const server = http.createServer(app);

const webSocket = require("socket.io")(server, {
    transports: ["websocket", "polling"]
  });

const PORT = 8081;

const serverData = {
    webSocket,
    PORT,
    server,
    app
};

module.exports = serverData;