var axios = require('axios');

function getStatusCode() {
    return new Promise((resolve, reject) => {
        axios.get('http://www.naver.com').then((result) => {
            console.log("naver 자료 가져옴 : " + result.status);
            resolve(result)
        });
    });
}

function getStatusCode2([res,num]) {
    return new Promise((resolve, reject) => {
        axios.get('http://www.naver.com').then((result) => {
            console.log("naver 자료 가져옴 : " + result.status);
            console.log("res는 이거임 : " + res.status);
            console.log("res는 이거임 : " + num);
            resolve(result)
        });
    });
}

getStatusCode().then((result) => {
    console.log("result 자료 가져옴 : " + result.status);
    let num = 10;
    return [result,num]
}).then(getStatusCode2);


// function main(){
//     var str1 = 'status 코드는';
//     var str2 = '입니다.';
//
// }

console.log("본문");

