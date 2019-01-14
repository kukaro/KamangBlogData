var items = ['1', '2', '3', '4'];

function printStuff(a, b, c) {
    console.log(`Printing: ${a} ${b} ${c}`);
}

printStuff(items[0], items[1], items[2]);
printStuff(...items);
