var axios = require('axios');

function func1(parent_func) {
    return new Promise((resolve, reject) => {
        axios.get('http://www.naver.com').then((result) => {
            console.log('function1 routine**********');
            console.log(parent_func);
            resolve('function1에서 왔습니다.');
        });
    });
}

function func2(parent_func) {
    return new Promise((resolve, reject) => {
        axios.get('http://www.daum.net/').then((result) => {
            console.log('function2 routine**********');
            console.log(parent_func);
            resolve('function2에서 왔습니다.');
        });
    });
}

function func3(parent_func) {
    return new Promise((resolve, reject) => {
        axios.get('http://www.daum.net/').then((result) => {
            console.log('function3 routine**********');
            console.log(parent_func);
            resolve('function3에서 왔습니다.');
        });
    });
}


var start_str = 'main에서 왔습니다.';

console.log('main routine**********');
func1(start_str).then((parent_func) => {
    console.log('function1 callback**********');
    console.log(parent_func);
    return parent_func
}).then(func2)
    .then(func3);

console.log("main 종료");

