import './App.css';
import TextForm from './components/TextForm';
import About from './components/About';
import Navbar from './components/Navbar';
import React, { useState } from 'react'
import {
  BrowserRouter as Router,
  Routes,
  Route,
} from "react-router-dom";
function App() {
  const [mode, setmode] = useState('light')
  const toggleMode = () => {
    if (mode === 'light') {
      setmode('dark');
      document.body.style.backgroundColor = 'grey';
    }
    else {
      setmode('light');
      document.body.style.backgroundColor = 'white';
    }
  }
  return (
    <>
      <Router>
        <Navbar title="Textutils " mode={mode} toggleMode={toggleMode} />
        <div className="container my-3">
            <TextForm heading="Enter Text For Analyze" mode={mode}/>
        </div>
        <Routes>
            <Route exact path ='/About' element={<About/>}>
            </Route>
        </Routes>
      </Router>
    </>
  );
}
export default App;
