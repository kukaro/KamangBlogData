// vue.config.js
module.exports = {
    pages:{
        page1:{
            entry: 'src/pages/page1/main.js',
            template: 'public/page1.html',
            filename: 'page1.out.html'
        },
        page2:{
            entry: 'src/pages/page2/main.js',
            template: 'public/page2.html',
            filename: 'page2.out.html'
        }
    },
};