var myObj = {
    num1: 1,
    num2: 20,
    method: function () {
        console.log('outer: ' + this);
        console.log(this === yourObj);
    }
};

var yourObj = {
    method: myObj.method
};

yourObj.method();

