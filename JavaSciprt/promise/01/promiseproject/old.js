var axios = require('axios');

//main.js
function f1(callback) {
    axios.get('https://www.naver.com').then((result) => {
        console.log('function1 main : ' + result.status);
        callback();
    });
}

function f2(callback) {
    axios.get('https://www.daum.net').then((result) => {
        console.log('function2 main : ' + result.status);
        callback();
    });
}

function f3(callback) {
    axios.get('https://nate.com').then((result) => {
        console.log('function3 main : ' + result.status);
        callback();
    });
}

var globalNum = 10;

f1(() => {
    console.log('function1 callback');
    f2(() => {
        console.log('function2 callback');
        f3(() => {
            console.log('function3 callback');
        });
    });
});

console.log('main : ' + globalNum);

