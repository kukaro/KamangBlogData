/*msg.js*/
var express = require('express');
var router = express.Router();
var session = require('../session');

router.post('/', function (req, res, next) {
    console.log(req.body.sendData);
    let data = `<script>parent.$('#chatArea').val(parent.$('#chatArea').val() + '${req.body.sendData}\\n');</script>`;
    for (let atom of session.resList) {
        atom.write(data);
    }
});

router.get('/', function (req, res, next) {
});

module.exports = router;