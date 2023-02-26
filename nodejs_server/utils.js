function CreateLoggerObj(data) {
    const date = new Date(data.timeNew * 1000);
    const timeArr = [date , date.toString()];

    return {
        type: data.type,
        location: data.location,
        payload: data.payload,
        time:  timeArr,
        id: data.id,
        priority: data.priority
    }
}

const utils = {
    CreateLoggerObj
}

module.exports = utils;