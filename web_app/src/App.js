 import './App.css';
import "./css/application.css"
import React from 'react';

import { Logger } from './components/logger';

function App() {
  return (
    <React.Fragment>
    <div className='header'>
    <h1 className='h1'>Logger App</h1>
    </div>
    <table className="styled-table">
    <thead>
        <tr>
            <th>Type</th>
            <th>Location</th>
            <th>Paylod</th>
            <th>Time</th>
            <th>Prtiority</th>
        </tr>
    </thead>
    <tbody>
    <Logger/>
    </tbody>
</table>

  </React.Fragment>

  )
}

export default App;