// App.js
import React, {Component} from 'react'
import AddButton from './AddButton'
import SubButton from './SubButton'

class App extends Component {

    constructor(props) {
        super(props);
    }

    render() {
        return (
            <div className="App">
                <span>{this.props.store.getState().data.number}</span><br/>
                <AddButton store={this.props.store}/><SubButton store={this.props.store}/>
            </div>
        );
    }
}

export default App;
