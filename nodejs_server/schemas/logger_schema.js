const mongoose = require('mongoose');

const userSchema = new mongoose.Schema({
    type: {
        type: String,
        required: true,
    },
    location: {
        type:String,
        required: true,
    },
    payload: {
        type: String,
    },
    time: {
        type : [],
        required: true,
    },
    id: {
        type : String,
        required: true,
        unique:true
    },
    priority : {
        type : String,
        required: true,
    }
});

const Logger = mongoose.model('Logger', userSchema, 'logger');

module.exports = { Logger };