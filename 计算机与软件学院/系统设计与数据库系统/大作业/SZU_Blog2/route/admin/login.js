//导入bcrypt
const bcrypt =require('bcrypt');
//导入用户集合构造函数
const {User}=require('../../model/user')
module.exports=async(req, res) => {
    //接受请求参数
    const{email,password}=req.body;
    //验证输入的合法性，防止javascript失效
    if(email.trim().length==0||password.trim().length==0){
        return res.status(400).render('admin/error',{msg:'邮件地址或者密码错误'});
    }  
    //根据邮箱地址查询用户信息
    //如果查询到了用户 user变量值为对象 对象中存储的是用户信息
    //如果没有查询到用户 user为空
     let user= await User.findOne({email});
     if(user){
          //将客户端传递过来的密码和用户信息中的密码进行比对
          //true比对成功
          //false比对失败
          let isValid=await bcrypt.compare(password,user.password);
          if(isValid){
              //登陆成功
              //将用户名存储在请求对象中
              req.session.username=user.username;
              //将用户角色存储在session对象中
              req.session.role=user.role;
              // res.send('登陆成功')
              req.app.locals.userInfo=user;
              //对用户的角色进行判断
              if(user.role=='admin'){
                  //重定向到用户列表页面
                  res.redirect('/admin/user');
              }else{
                  //重定向到博客首页
                  res.redirect('/home');
              }
          }
          else {
              //登陆失败
              res.status(400).render('admin/error',{msg:'邮件地址或者密码错误'});
          }
     }
     else{
      res.status(400).render('admin/error',{msg:'邮件地址或者密码错误'});
     }
  } 
