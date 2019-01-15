var gulp = require('gulp');
var minify = require('gulp-minify');
var concat = require('gulp-concat');
var uglyfi = require('gulp-uglify');

const DIR = {
    SRC: 'src/*.js',
    DEST: 'dist'
};

gulp.task('hello', () => {
    console.log('hello');
});

gulp.task('default', () => {
    console.log('default');
    return gulp.src(DIR.SRC)
        // .pipe(uglyfi())
        .pipe(minify())
        .pipe(concat('all.js'))
        .pipe(gulp.dest(DIR.DEST));
});