function serializeToJson(form){
    var result={};
      //[{name:'email',value:'用户输入的内容'}]
   var f= form.serializeArray();
   f.forEach(function(item){
       //result.email
    result[item.name]=item.value;
   });
   return result;
}
 
//为表单添加提交事件
