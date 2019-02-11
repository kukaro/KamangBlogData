// module.exports = {
//     '사용자는 검색어를 입력 후 검색어가 포함된 자동 완성 리스트를 볼 수 있다.': function (browser) {
//         browser
//             .url('http://www.google.com')
//             .waitForElementVisible('body', 1000)
//             .setValue('input[type=text]', 'nightwatch')
//             .pause(1000)
//             .assert.containsText('##sbtc', 'nightwatch')
//             .end();
//     }
// };
// module.exports = {
//     '버튼 누르면 채팅에 추가 됨': (browser)=>{
//         browser
//             .url('http://localhost:5500/index.html')
//             .waitForElementVisible('body', 1000)
//             .pause(200)
//             .setValue('input[type=text]#mytext', '안녕하십니까')
//             .pause(200)
//             .click('input[type=button]#mybtn')
//             .pause(1000)
//             .assert.value('textarea#myarea','안녕하십니까\n')
//             .end();
//     }
// }
//tests/mytest.js
module.exports = {
    '버튼 누르면 채팅에 추가 됨': (browser)=>{
        browser
            .url('http://localhost:5500/index.html')
            .waitForElementVisible('body', 1000)
            .pause(200)
            .setValue('input[type=text]#mytext', '안녕하십니까')
            .pause(200)
            .click('input[type=button]#mybtn')
            .pause(1000)
            .assert.value('textarea#myarea','안녕하십니까\n')
            .end();
    }
}
