// step1.js
var express = require('express');
var router = express.Router();

router.get('/', function(req, res, next) {
    console.log('step1');
    next();
});

module.exports = router;