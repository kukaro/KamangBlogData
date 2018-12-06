var myObj = {
    num1: 1,
    num2: 20,
    method: function() {
        let test = function() {
            console.log('method: ' + this);
            console.log(this === myObj);
        };
        test.bind({});
        return test();
    }
};

myObj.method();