const gulp = require('gulp');

gulp.task('hello', function () {
    console.log('hello');
});

gulp.task('default', ['hello'], function () {
    console.log('default');
});