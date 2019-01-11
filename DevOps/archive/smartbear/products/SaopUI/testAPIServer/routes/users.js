var express = require('express');
var router = express.Router();

/* GET users listing. */
router.get('/', function (req, res, next) {
    var json = {};
    var name = 'kukaro';
    var id = 'jiharu';
    var age = 26;
    var language = ['java', 'c', 'c++'];
    json.name = name;
    json.id = id;
    json.age = age;
    json.language = language;
    res.send(json);
});

module.exports = router;
