const mongoose = require("mongoose");
const config = require('config');

function connectMongoDb() {
    const mongoDbConnection = config.get('mongoDb');

    mongoose.connect(`mongodb://${mongoDbConnection.host}/${mongoDbConnection.dbName}`, {
    useNewUrlParser: true,
    useUnifiedTopology: true,
    })
    .then(() => console.log('Connected to MongoDB...'))
    .catch(err => console.error("error ===>",err));
}

const connections = {
    connectMongoDb
};

module.exports = connections;