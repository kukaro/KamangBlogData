/**
 * Created by YS on 2017-11-20.
 */
module.exports = {
    port: 3380,
    ssl_port: 3300,
    mode: "local",

    logging: [{
        level: "verbose",
        type: "Console",
        colorize: true,
        timestamp: true
    }, {
        level: "file",
        type: "File",
        timestamp: true,
        filename: "/dev/null"
    }],


    https_options: {
        key: './config/keys/imqa_key.pem',
        cert: './config/keys/imqa_cert.pem'
    },

    database: {
        aosShardNodes: {
            aosShard00: 1
        },
        iosShardNodes: {
            iosShard00: 1
        },
        nodes: {
            user: {
                host: "127.0.0.1",
                port: "3306",
                user: "root",
                password: "root",
                database: "imqa_user",
                connectionLimit: 50,
                waitForConnections: false
            },
            aosShard00: {
                host: "127.0.0.1",
                port: "3306",
                user: "root",
                password: "root",
                database: "imqa",
                connectionLimit: 50,
                waitForConnections: false
            },
            iosShard00: {
                host: "127.0.0.1",
                port: "3306",
                user: "root",
                password: "root",
                database: "imqa",
                connectionLimit: 50,
                waitForConnections: false
            }
            /*
                  user:{
                    host: "52.231.207.19",
                    port: "15772",
                    user: "root",
                    password: "asdf12",
                    database: "imqa_user",
                    connectionLimit:50,
                    waitForConnections:false
            },    
                     aosShard00:{
                         host: "52.231.207.19",
             port: "15772",
             user: "root",
             password: "!@hyperion78*",
                         database: "imqa",
                         connectionLimit:50,
                         waitForConnections:false
                     },    
                     iosShard00:{
                         host: "52.231.207.19",
             port: "15772",
             user: "root",
             password: "!@hyperion78*",
                         database: "imqa",
                         connectionLimit:50,
                         waitForConnections:false
            }
            */
        },
        crash: {
            aos: 'imqa',
            ios: 'imqa_crash_cocoa'
        },
        mpm: {
            aos: 'imqa_mpm_analysis',
            ios: 'imqa_mpm_apple' // not yet
        }
    },

    cookie: {
        session: 'IMQA_SESSION',
        domain: 'localhost'
    },

    analysisFile: {
        local: "/home/onycom/IMQA-WebApi/uploads",
        maxFileSize: 100 * 1000 * 1000 // 100MB
    },

    storage: {
        name: "oteanalysisfilestorage",
        key: "XtkEXK0pFJqGxGqrJu/2ziCWuM1vqhVUfdiNzsS+p0jY36m34QyvUq2JlrW7R0EbyDFZpG9kxmFYuXvDoZSKHA=="
    },

    docs: {
        location: "/home/onycom/IMQA-Crash-WebApi/utils/install_guide",
        filename: "IMQA_Crash_Report_Install_Guide"
    },

    redis: [{
        master: {
            host: "127.0.0.1",
            port: 6379,
            pass: "!@hyperion78*"
        },
        /*
        master:{
         host: "52.231.188.192",
         port: 63785,
         pass: "!@hyperion78*"
        },
        slaves: [{
         host: "127.0.0.1",
         port: 6379,
         pass: ""
        }]
        */
    }],

    mongodb: {
        host: '10.0.0.14',
        port: '28617',
        dbname: 'mpm_raw_db'
    },

    mongoSchemaSet: {
        resourceSchemaSet: './schemas/resourceSchemaSet'
    },

    mongooseOption: {
        useMongoClient: true,
        user: 'admin',
        pass: '!@hyperion78*',
    },

    replHosts: 'mongodb://10.0.0.14:28617/mpm_raw_db',

    pack_secret: 'mpm project key generater',

    jwtsecret: 'imqa mpm key secret',
    saltRound: 5,

    jwt: {
        issuer: 'mpm.imqa.io',
        subject: 'mpm',
        algorithm: 'HS256'
    },


    mail: {
        server: "mail.onycom.com",
        port: 587,
        id: "youngsoo@onycom.com",
        pass: "onycom.com!!",
        name: "ImQA"
    },


    gmail: {
        server: "gmail",
        id: "no-reply@imqa.io",
        password: "Djslzja0080",
        client_id: "258651742311-p76f1aup3tce249s2jm1au0g3rr1sasg.apps.googleusercontent.com",
        client_secret: "9ZyY99WhfEnMqsInbB7a8g1I",
        refresh_token: "1/Gt_GSsUGxOeqf1mJAkoEAxhzajZxD59Td6AO8qWDL5E",
        access_token: "ya29.GlswBeSNjJ4hF-QdfS4Myv4pianbnqfW5nsLnfxtZFcQ5Ljq4n8fcLKt5JJxvWaH1zMtgUVKgYRkW9ORUvOMKEyxINycPXj-bwLayjmGnZs4kFNIwXt1hqbtSgGL",
        name: "IMQA"
    },

    approve_host: "http://localhost",
}