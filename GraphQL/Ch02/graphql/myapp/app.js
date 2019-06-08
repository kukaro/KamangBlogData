var createError = require('http-errors');
var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');
var graphqlHTTP = require('express-graphql');
var {buildSchema} = require('graphql');

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

app.use('/', indexRouter);
app.use('/users', usersRouter);

class Person {
    constructor(name, age) {
        this.name = name;
        this.age = age;
    }
}

var schema = buildSchema(`
  type Person {
    name: String
    age: Int
  }

  type Query {
    hello: String
    persons(name: String): [Person]
  }
`);

var root = {
    hello: () => {
        return 'Hello world!';
    },
    persons: ({name}) => {
        let list = [
            {
                name: 'kukaro',
                age: 27
            },
            new Person('jiharu', 21),
        ];
        if(!name) {
            return list;
        }
        let result = [];
        list.forEach((value) => {
            if (value.name === name) {
                result.push(value);
            }
        });
        return result;
    }
};


app.use('/graphql', graphqlHTTP({
    schema: schema,
    rootValue: root,
    graphiql: true,
}));

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

module.exports = app;
