
const {Article}=require('../../model/article');
module.exports=async (req,res) => {
    //获取要删除的文章的id
    // res.send(req.query.id);
    //根据id删除文章
    await Article.findOneAndDelete({_id:req.query.id});
    res.redirect('/admin/article');
}