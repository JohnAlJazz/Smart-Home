import http from "./http_service";
import { APIURL } from "./server_config";

import "./server_config"

function getLoggerData(){
    return http.get(`${APIURL}/logger`);
}

const loggerService = {
    getLoggerData
};

export default loggerService;