//Hello.js
import React, {Component} from 'react';

class Hello extends Component {
    render() {
        return (
            <div className="Hello">
                hello {this.props.name}!
            </div>
        );
    }
}

Hello.defaultProps = {
    name: 'jiharu'
};

export default Hello;