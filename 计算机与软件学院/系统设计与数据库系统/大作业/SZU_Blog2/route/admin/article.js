//将文章集合的构造函数导入到当前文件中
const {Article}=require('../../model/article');
const pagination=require('mongoose-sex-page');
module.exports= async(req, res) => {
       var id=req.app.locals.userInfo.id;
        //标识 标识当前访问的是文章管理页面
        req.app.locals.currentLink='article';
        //查询文章数据 
        //如果是普通用户，查询根据自己的id查询自己文章的数据 
        //如果是超级管理员用户，查询所有的文章数据 
        let articles;
        if(req.app.locals.userInfo.role=='normal')
             articles=await Article.find({"author":id}).populate('author').lean();
        else  articles=await Article.find().populate('author').lean();

        //渲染文章模板，并传递查询到文章数据 articles
        res.render('admin/article.art',{
            articles:articles
        });
}