# ﻿![mongoose-sex-page](art/logo.gif)

# mongoose-sex-page [![Build Status](https://img.shields.io/travis/dtboy1995/mongoose-sex-page/master.svg)](https://travis-ci.org/dtboy1995/mongoose-sex-page)

:fire: api友好的mongoose分页小工具

# 安装
```
npm install --save mongoose-sex-page
```

# 用法

```javascript
const Dummy = mongoose.model('Dummy', DummySchema)
const P  = require('mongoose-sex-page')
```

- ### 简单

```javascript
P(Dummy)
  .page(1)
  .size(20)
  .exec()
  .then((result) => {

  })
```

- ### 复杂

```javascript
P(Dummy)
  .find({dummy: dummy})
  .page(1)
  .size(20)
  .display(8)
  .simple(true)
  .exec()
  .then((result) => {

  })
```

- ### 配置

```javascript
P().config({
  page_name: 'page',
  size_name: 'size',
  size: 20,
  display: 10,
  // 只返回数据数组
  light: true
})
```

- ### 方便

```javascript
// 业务的请求query参数一致如 /users?size=20&page=1 /news?size=20&page=1 可以配置完使用inject函数
P().config({
  page_name: 'page',
  size_name: 'size',
  size: 20
})
// 然后
P(Dummy)
  .find({dummy: dummy})
  .inject(req.query)
  .exec()
  .then((result) => {

  })
```

# 结果样本
``` json
{
  "page": 1,
  "size": 5,
  "total": 100,
  "records": [{
    "name": "Test1",
    "age": 1
  }, {
    "name": "Test2",
    "age": 2
  }, {
    "name": "Test3",
    "age": 3
  }, {
    "name": "Test4",
    "age": 4
  }, {
    "name": "Test5",
    "age": 5
  }],
  "pages": 20,
  "display": [1, 2, 3, 4, 5, 6]
}
```

# 测试
> npm test
