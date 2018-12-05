class Point {
    constructor(x, y) {
        this.x = x;
        this.y = y;
    }

    info(v, w) {
        console.log(`x: ${this.x}, y: ${this.y}, v: ${v}, w: ${w}`);
    }
}

var point = new Point(10, 20);

point.info(1, 2,);

var customPoint = {x: 100, y: 200};

point.info.call(customPoint, 20, 30);
point.info.apply(customPoint, [2, 3]);
