const express = require('express');
const router = express.Router();
const utils = require("../utils");

const { Logger } = require("../schemas/logger_schema");
const socket = require('../sockets');

router.get('/api/logger',async(req,res)=> {
    const data = await Logger.find();
    res.send(data);
});

module.exports = router;