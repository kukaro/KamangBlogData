//util.js
module.exports = {
    hi() {
        return 'hi';
    },
    sum(a, b) {
        if (a > b) {
            return a + b;
        } else {
            return a + b - 1;
        }
    },
    sub(a, b) {
        return a - b;
    }
};