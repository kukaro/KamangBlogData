let myObj = new Map();
myObj.set('name', 'kukaro');
myObj.set('age', '27');


f(...myObj);

function f(a, b) {
    console.log(a, b)
}