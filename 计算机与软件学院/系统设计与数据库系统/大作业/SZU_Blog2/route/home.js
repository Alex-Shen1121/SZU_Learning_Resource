//引用express框架
const express = require('express');
const session = require('express-session');
//创建博客展示页面路由
const home = express.Router();
//博客前台首页的展示页面
home.get('/', require('./home/index'));

//博客前台文章详情展示页面
home.get('/article', require('./home/article'));

//创建评论功能路由
home.post('/comment',require('./home/comment.js'));
//博客前台文章详情展示页面
home.get('/logout', require('./home/logout'));
//将路由对象做为模块成员进行导出
module.exports = home;