// server.js
var express = require('express');
var app = express();

app.engine('html', require('../'));
app.set('views', __dirname + '/views');
app.set('view options', {
    debug: process.env.NODE_ENV !== 'production'
});

app.get('/', function (req, res) {
    res.render('index.html', {
        user: {
            name: 'aui',
            tags: ['art', 'template', 'nodejs']
        }
    });
});

app.listen(8080);
console.log('8080 is the magic port');