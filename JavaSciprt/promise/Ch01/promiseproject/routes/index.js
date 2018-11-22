var express = require('express');
var router = express.Router();
var axios = require('axios');

/* GET home page. */
router.get('/', function (req, res, next) {
    axios.get('http://www.naver.com').then((result) => {
        console.log("naver 자료 가져옴");
    });
    console.log("본문");
    res.render('index', {title: 'Express'});
});

module.exports = router;
