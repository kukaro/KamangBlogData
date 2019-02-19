function f(a) {
    return new Promise((resolve, reject) => {
        if (a > 10) {
            resolve(a + 10);
        } else {
            reject(a - 10);
        }
    });
}

function g(b) {
    return new Promise((resolve, reject) => {
        if (typeof b === "number") {
            resolve('b is number');
        } else {
            reject('b is not number');
        }
    });
}

function h(c) {
    return new Promise((resolve, reject) => {
        if (c.length <= 11) {
            resolve('short');
        } else {
            reject('long');
        }
    });
}

function main(num) {
    f(num)
        .then(g)
        .then(h)
        .then((value)=>{
            console.log(value);
        })
}

function main(num) {
    f(num).then((a) => {
        console.log(a);
        return a;
    }).then(g).then((b) => {
        console.log(b);
        return b;
    }).then(h).then((c) => {
        console.log(c);
        return c;
    }).then((value) => {
        console.log(value)
    })
}

async function main(num) {
    const a = await f(num);
    const b = await g(a);
    const c = await h(b);
    console.log(c);
}

main(12);
