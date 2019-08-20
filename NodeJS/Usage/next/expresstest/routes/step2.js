// step2.js
var express = require('express');
var router = express.Router();

router.get('/', function (req, res, next) {
    console.log('step2');
    res.send('respond with a resource');
});

module.exports = router;
