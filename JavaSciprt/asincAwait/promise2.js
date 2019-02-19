async function f(a) {
    if (a > 10) {
        return a + 10;
    } else {
        throw a - 10;
    }
}

async function g(b) {
    if (typeof b === "number") {
        return 'b is number';
    } else {
        throw 'b is not number';
    }
}

async function h(c) {
    if (c.length <= 11) {
        return 'short';
    } else {
        throw 'long';
    }
}

function main(num) {
    f(num)
        .then(g)
        .then(h)
        .then((value) => {
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
    });
}

async function main(num) {
    try{
        const a = await f(num);
        const b = await g(a);
        const c = await h(b);
        console.log(c);
    }catch (e) {
        console.log(e)
    }
}

main(11);
