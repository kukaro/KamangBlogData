var myObj = {
    num1: 1,
    num2: 20,
    method: () => {
        console.log('method: ' + this);
        console.log(this === myObj);
    }
};

myObj.method();