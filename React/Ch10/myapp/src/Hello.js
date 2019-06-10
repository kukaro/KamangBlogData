// Hello.js
import React, {Component} from 'react'

class Hello extends Component {
    onMyClick = ()=> {
        this.props.getName(this.props.name + '!');
    }

    render() {
        return (
            <div className="Hello" onClick={this.onMyClick}> hello {this.props.name}!
            </div>
        );
    }
}

export default Hello;