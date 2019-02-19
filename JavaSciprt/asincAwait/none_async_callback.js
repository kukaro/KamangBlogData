function f(a, callback) {
    callback(a);
    console.log('f function : ' + a)
}

f(10, (num) => {
    console.log('inner function : ' + num);
});