var myObj = {
    num1: 1,
    num2: 20,
    method: function () {
        console.log('outer: ' + this);
        console.log(this === myObj);
    }
};

myObj.method();

function test(callback) {
    callback();
}

test(myObj.method);

