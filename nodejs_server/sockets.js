function broadCastClients(webSocket,msg) {
    webSocket.emit("connected", msg);
}

const socket = {
    broadCastClients
}

module.exports = socket;