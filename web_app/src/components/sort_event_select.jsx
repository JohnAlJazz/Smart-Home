import React, { useState, useEffect } from 'react';
import Select from 'react-select';

export const SortSelector = ({loggerData,updateLoggerData}) => {
    const options = [
        { value: 'sort by time start to end', label: 'sort by time start to end' },
        { value: 'sort by time end to begin', label: 'sort by time end to begin' },
        { value: 'sort by priority most to least', label: 'sort by priority most to least' },
        { value: 'sort by priority least to most', label: 'sort by priority least to most' }
      ];

      const [selectedOption] = useState(null);

      const sortByTimeStartToEnd = (arr) => {
        arr.sort ((p1, p2) => (p1.time[0] > p2.time[0]) ? 1 :
                                 (p1.time[0] < p2.time[0]) ? -1 : 0);
      }

      const sortByTimeEndToStart = (arr) => {
        arr.sort ((p1, p2) => (p1.time[0] < p2.time[0]) ? 1 :
                                 (p1.time[0] > p2.time[0]) ? -1 : 0);
      }

      const sortByPriorityMostToLast =  (arr) => {
        arr.sort ((p1, p2) => (p1.priority < p2.priority) ? 1 :
          (p1.priority > p2.priority) ? -1 : 0);
      }

      const sortByPriorityLeastToMost =  (arr) => {
        arr.sort ((p1, p2) => (p1.priority > p2.priority) ? 1 :
          (p1.priority < p2.priority) ? -1 : 0);
      }

      const lookUpSort = {
        'sort by time start to end' : sortByTimeStartToEnd,
        'sort by time end to begin' : sortByTimeEndToStart,
        'sort by priority most to least' : sortByPriorityMostToLast,
        'sort by priority least to most' : sortByPriorityLeastToMost,
      }

      const handleChange = (selectedOption) => {
        lookUpSort[selectedOption.value](loggerData);
        const sortedArr = [...loggerData];
        updateLoggerData(sortedArr);
      };

    return (
        <React.Fragment>
            <Select 
            defaultValue={selectedOption}
            onChange={handleChange} options={options}
            />
        </React.Fragment>
    );
};