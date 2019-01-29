var express = require('express');
var router = express.Router();

/* GET home page. */
router.get('/', function (req, res, next) {
    res.writeHead(200, {
        'Content-Type': 'text/html; charset=UTF-8',
        'Transfer-Encoding': 'chunked'
    });
    for (var i = 0; i < 10; i++) {
        setTimeout(() => {
            res.write('<script>console.log("hihi");</script>');
        }, i * 1000);
    }
});

module.exports = router;
