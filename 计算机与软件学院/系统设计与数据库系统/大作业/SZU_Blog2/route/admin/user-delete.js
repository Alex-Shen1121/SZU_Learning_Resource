
const {User}=require('../../model/user');
module.exports=async (req,res) => {
    //获取要删除的用户的id
    // res.send(req.query.id);
    //根据id删除用户
    await User.findOneAndDelete({_id:req.query.id});
    res.redirect('/admin/user');
}