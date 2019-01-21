/**
 * Circle객체는 x,y점을 원점으로 가지고 r을 반지름으로 한다.
 * @param x {number}
 * @param y {number}
 * @param r {number}
 * @constructor 각각의 값이 내부 변수로 대입된다.
 */
var Circle = function (x, y, r) {
    /**
     * Circle의 x좌표
     */
    this.x = x;
    /**
     * Circle의 y좌표
     */
    this.y = y;
    /**
     * Circle의 반지름
     */
    this.r = r;
};

/**
 * Circle에서 사용하는 속성
 */
Circle.prototype.pi = 3.14;

/**
 * Circle에서 넓이를 반환하는 메소드
 * @returns {number}
 */
Circle.prototype.getArea = function () {
    return this.pi * this.r;
};

/**
 * Circle에서 원점을 반환하는 메소드
 * @returns {[number,number]}
 */
Circle.prototype.getPoint = function () {
    return [this.x, this.y];
};

/**
 * Circle을 인수로 받아서 circle의 정보를 출력하는 메소드
 * @param circle {Circle}
 */
function infoCircle(circle) {
    console.log(circle);
};

var c = new Circle(1, 1, 3);
infoCircle(c);