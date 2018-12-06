var myObj = {
    num1: 1,
    num2: 20,
    outer: function () {
        console.log('outer: ' + this);
        console.log(this === myObj);

        function inner() {
            console.log('inner: ' + this);
            console.log(this === myObj)
        }

        inner.bind(this)();
    }
};

myObj.outer();