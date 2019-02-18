let arr = [2, 4, 6, 8, 10];

console.log(add(...arr));

function add(a, b) {
    return a + b;
}

console.log(...arr);
console.log([...arr])

f(arr)
function f(...a) {
    console.log(a)
}