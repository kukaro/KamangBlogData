/*chat.js*/
var express = require('express');
var router = express.Router();
var session = require('../session');

router.post('/', function (req, res, next) {

});

router.get('/', function (req, res, next) {
    res.writeHead(200, {
        'Content-Type': 'text/html; charset=UTF-8',
        'Transfer-Encoding': 'chunked'
    });
    session.resList.push(res);
});

module.exports = router;