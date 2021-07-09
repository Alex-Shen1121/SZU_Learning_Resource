//引入formidable第三方模块
const formidable=require('formidable');
const path=require('path');
const {Article}=require("../../model/article");
module.exports =  (req, res) => {
    //1.创建表单解析对象
    const form=new formidable.IncomingForm();
    //2.配置上传文件的存放位置
    form.uploadDir=path.join(__dirname,'../','../','public','uploads');
    //3.保留上传文件的后缀
    form.keepExtensions=true;
    form.parse(req,async(err,fields,files)=>{
        //接收客户端传递过来的请求参数
        const { cover,title,publishDate,content } = req.body;
        const id = req.query.id;

        let article = await Article.findOne({ _id: id });
        // 1.err错误对象 如果表单解析失败 err里面储存错误信息 如果表单解析成功 err将会是null
        //2.fields 对象类型 保存普通表单数据
        //3.files对象类型 保存了和上传文件相关的数据
        // console.log(files.cover.path.split('public')[1]);
        // res.send(files);
        await Article.updateOne({ _id: id }, {
            cover:files.cover.path.split('public')[1],
            title:fields.title,
            publishDate:fields.publishDate,
            content:fields.content
        });
        //将页面重定向到列表页面
        res.redirect('/admin/article');
    })
    
   

    // const isValid = await bcrypt.compare(password, user.password);
    // //密码比对成功
    // if (isValid) {
    //     // res.send('密码比对成功');
    //     await User.updateOne({ _id: id }, {
    //         username: username,
    //         email: email,
    //         role: role,
    //         state: state
    //     });
    //     //将页面重定向到用户列表页面
    //     res.redirect('/admin/user');
    // } else {
    //     // 密码比对失败
    //     let obj = { path: '/admin/user-edit', message: '密码比对失败,不能进行用户信息的修改', id: id }
    //     next(JSON.stringify(obj));
    // }
    // // res.send(user);
}