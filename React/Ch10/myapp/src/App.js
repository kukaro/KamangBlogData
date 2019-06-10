// Hello.js
import React, {Component} from 'react';
import Hello from './Hello'

class App extends Component {
    state = {
        name: 'kukaro'
    };

    getName(data) {
        this.setState({
            name: data
        });
    }

    constructor(props) {
        super(props);
    }

    render() {
        return (
            <div className="App">
                <Hello name={this.state.name} getName={this.getName.bind(this)}/>
            </div>
        );
    }
}

export default App;
