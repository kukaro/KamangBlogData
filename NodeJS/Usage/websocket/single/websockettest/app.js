var createError = require('http-errors');
var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');
var WebSocketServer = require('ws').Server;

var indexRouter = require('./routes/index');
var usersRouter = require('./routes/users');

var app = express();

// view engine setup
app.set('views', path.join(__dirname, 'views'));
app.set('view engine', 'ejs');

app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({extended: false}));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));
app.use(express.static(path.join(__dirname, 'node_modules')));

app.use('/', indexRouter);
app.use('/users', usersRouter);

// catch 404 and forward to error handler
app.use(function (req, res, next) {
    next(createError(404));
});

// error handler
app.use(function (err, req, res, next) {
    // set locals, only providing error in development
    res.locals.message = err.message;
    res.locals.error = req.app.get('env') === 'development' ? err : {};

    // render the error page
    res.status(err.status || 500);
    res.render('error');
});

var wss = new WebSocketServer({port: 3100});

wss.on('connection', (ws) => {
    ws.on('message', (message) => {
        let sendData = {event: 'res', data: null};
        message = JSON.parse(message);
        switch (message.event) {
            case 'open':
                console.log("Received: %s", message.event);
                break;
            case "req":
                sendData.data = message.data;
                ws.send(JSON.stringify(sendData));
                break;
            default:
        }
    });
});

module.exports = app;
