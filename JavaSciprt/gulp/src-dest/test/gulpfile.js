const gulp = require('gulp');
const browserify = require('gulp-browserify');

gulp.task('bundling', function () {
    let src = 'src/main.js';
    //let src = 'src/*.js';
    let dest = 'dist/js';

    console.log('bundling task');
    let stream = gulp.src(src)
        .pipe(browserify())
        .pipe(gulp.dest(dest));
    // return stream;
});

gulp.task('default', ['bundling'], function () {
    console.log('default task');
});
