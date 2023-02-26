import React from "react";

export const LoggerRow = ({ dataObj }) => {
  return (
        <tr>
        <td  >{dataObj.type}</td>
        <td >{dataObj.location}</td>
        <td >{dataObj.payload}</td>
        <td >{dataObj.time[1]}</td>
        <td >{dataObj.priority}</td>
        </tr>
  )
};