// SubButton.js
import React, {Component} from 'react';
import {sub} from './actions'

class SubButton extends Component {
    constructor(props) {
        super(props);
    }

    render() {
        return (
            <input value={'-'} type="button" onClick={this.subNumber}/>
        )
    }

    subNumber = () => {
        this.props.store.dispatch(sub());
    }
}

export default SubButton;