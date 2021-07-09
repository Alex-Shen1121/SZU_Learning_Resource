# express-art-template

[![NPM Version](https://img.shields.io/npm/v/express-art-template.svg)](https://npmjs.org/package/express-art-template)
[![Node.js Version](https://img.shields.io/node/v/express-art-template.svg)](http://nodejs.org/download/)

art-template for express

## Install

```shell
npm install --save art-template
npm install --save express-art-template
```

## Example

```js
var express = require('express');
var app = express();
app.engine('art', require('express-art-template'));
app.set('view options', {
    debug: process.env.NODE_ENV !== 'production'
});

app.get('/', function (req, res) {
    res.render('index.art', {
        user: {
            name: 'aui',
            tags: ['art', 'template', 'nodejs']
        }
    });
});
```

## Options

You can pass [art-template options](https://github.com/aui/art-template)