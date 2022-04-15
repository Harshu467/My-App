import React, { useState } from 'react'

export default function TextForm(props) {
    const handleUpClick = () => {
        let newtext = text.toUpperCase();
        setText(newtext)
    }
    const handleLoClick = () => {
        let newtext = text.toLowerCase();
        setText(newtext)
    }
    const handleClearClick = () => {
        let newtext = '';
        setText(newtext)
    }
    const handleInvClick = () => {
        let newtext = text.split("");
        let rev = newtext.reverse();
        let ans = rev.join("");
        setText(ans)
    }
    const handleOnClick = (event) => {
        setText(event.target.value)
    }

    const [text, setText] = useState('');

    return (
        <>
            <div className='container' style={{color:props.mode==='dark'?'white':'black'}}>
                <h2>{props.heading}</h2>
                <div className="mb-3">
                    <textarea className="form-control" style={{backgroundColor:props.mode==='dark'?'grey':'white',
                     color:props.mode==='dark'?'white':'black'}} value={text} onChange={handleOnClick} id="mybox" rows="8"></textarea>
                </div>
                <button className="btn btn-primary mx-1" onClick={handleUpClick}>Convert to Uppercase</button>
                <button className="btn btn-primary mx-1" onClick={handleLoClick}>Convert to Lowercase</button>
                <button className="btn btn-primary mx-1" onClick={handleClearClick}>Clear</button>
                <button className="btn btn-primary mx-1" onClick={handleInvClick}>Inverse Text</button>
            </div>
            <div className="container my-3" style={{color:props.mode==='dark'?'white':'black'}}>
                <h2>Your Text Summary</h2>
                <p>{text.split(" ").length-1} words and {text.length} characters</p>
                <p>{0.008*text.split(" ").length} minutes to read</p>
                <h2>Preview</h2>
                <p>{text}</p>
            </div>
        </>
    )
}
