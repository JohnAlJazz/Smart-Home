import "../css/application.css"

import React, { useState, useEffect } from 'react';

import loggerService from "../services/logger_init_service";
import io from "socket.io-client";

import { LoggerRow } from "./logger_row";
import { SortSelector } from "./sort_event_select";

const socket = io("http://localhost:8081", {
  transports: ["websocket", "polling"]
});

async function FetchLoggerDataOnInit(cb,setContainData,setServerError) {
    try {
        const { data } = await loggerService.getLoggerData();
        setServerError(false);
        if(data.length) {
            cb(data);
            setContainData(true);
        }
    }
    catch {
        console.log("no data base.....");
    }
}

function getNewLoggerMessage(loggerData,updateLoggerData,setContainData) {
        socket.on('connected', (message) => {
            const messages = [...loggerData];
            messages.push(message);
            updateLoggerData(messages);
            setContainData(true);
        });
}

export const Logger = () => {
    const [loggerData,updateLoggerData] = useState([]);
    const [containData,setContainData] = useState(false);
    const [serverError,setServerError] = useState(true);

    useEffect(() => {
        FetchLoggerDataOnInit(updateLoggerData,setContainData,setServerError);
    },[]);
    
    getNewLoggerMessage(loggerData,updateLoggerData,setContainData);
    
    return (
        <React.Fragment>
        {containData && (
                <React.Fragment>
                    <SortSelector loggerData = {loggerData} updateLoggerData = {updateLoggerData} />
                    {loggerData.map((dataObj)=> {
                        return <LoggerRow key={dataObj.key} dataObj = {dataObj}/>
                    })}
                </React.Fragment>
            )}
            {!containData && !serverError && (
                <p className="logger-empty" >logger empty</p>
            )}
            
            {serverError &&  (
                <p className="logger-error">Unexpected error has accured , please try again later</p>
            )}
        
        </React.Fragment>
    );
};