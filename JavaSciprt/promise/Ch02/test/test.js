var fs = require('fs');

var filename = 'text.txt';
var text = null;

function f1(filename) {
    return new Promise((resolve, reject) => {
        text = fs.readFile(filename, 'utf8', (err, data) => {
            console.log(err)
            console.log(data);
            if (err === null) {
                resolve(data);
            } else {
                reject(err);
            }
        });
    })
}

function f2(data) {
    return new Promise((resolve, reject) => {
        console.log('에러없이 데이터 전송됨');
        console.log(data);
    });
}

function f3(err) {
    return new Promise((resolve, reject) => {
        console.log('에러 발생됨');
        console.log(err);
    });
}
f1(filename)
    .then(f2)
    .catch(f3)
    .then(f1(filename)
        .then(f2)
        .then(f3))
;
