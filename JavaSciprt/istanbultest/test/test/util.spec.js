//util.spec.js
const expect = require('chai').expect;
const util = require('../src/util');

describe('util', () => {
    it('function', (done) => {
        const result = 'hi';
        expect(result).to.equal(util.hi());
        done();
    })

    it('sum', (done) => {
        const value1 = 10;
        const value2 = 15;
        const result = 24;
        expect(result).to.equal(util.sum(value1, value2));
        done();
    })
});