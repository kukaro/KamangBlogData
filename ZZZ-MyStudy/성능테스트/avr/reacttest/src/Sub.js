import React, {Component} from 'react';

class Sub extends Component {
    constructor(props) {
        super(props);
    }

    render() {
        return (
            <div className="Sub" style={{position:'relative'}}>
                {this.props.arr.map((value,key)=>{
                    return(<div style={value}></div>);
                })}
            </div>
        );
    }
}

Sub.defaultProps = {
    arr: (function () {
        let n = 10000;
        let ret = new Array(n).fill(0);
        ret = ret.map(() => {
            return {
                width: Math.random() * 100 + 'px',
                height: Math.random() * 100 + 'px',
                top: Math.random() * 100 + 'px',
                left: Math.random() * 100 + 'px',
                backgroundColor: '#' + Math.floor(Math.random() * 10) + Math.floor(Math.random() * 10) + Math.floor(Math.random() * 10),
                position: 'absolute',
            }
        });
        return ret;
    })(),
};
export default Sub;
