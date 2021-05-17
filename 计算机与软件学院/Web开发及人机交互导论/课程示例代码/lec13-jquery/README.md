# jQuery笔记
jQuery的理念：Write less,Do more.

## Hello World
首先需要下载jQuery的文件，目前jQuery有几个版本，2以后的版本不提供IE678的支持，如果需要支持则需要现在2以下的版本。下载后通过script标签引入既可以使用jQuery了。

## 基础知识

### jQuery操作css
- .css(attr,val) css单属性修改,如果属性值去掉最后px为数字则不需要加引号
- .css(attr) css单属性访问
- .css({attr1:val1,attr2:val2....}) css多属性修改，如果属性名不加引号则需要修改其为驼峰式命名法如：'background-color'转成backgroundColor。

### jQuery操作html
- .html(要修改的内容) 修改元素html值
- .html()  访问元素html值

### jQuery操作标签属性
- .attr(标签属性值,标签属性值) 修改标签属性
- .attr(标签属性值)  访问标签属性

## jQuery选择器

### 基本选择器
- el 选择所有标签为el的元素 $('p')
- #id 选择id为id的元素 $('#id')
- .class 选择类名为class的元素 $('.class')
- el.class 选择类名为class的el元素 $('el.class')
- el1,el2,el3 并集选择器 $('el1,el2,el3')
- ul li 后代选择 $('ul li')
- \* 通配符选择 $('*')
- div>span 子代选择 $('div>span')
- div+span div后面紧挨着的span $('div+span')
- div~span 选择div后面所有span $('div~span')

### 过滤选择器

#### 基本过滤选择器
- :eq(n) 选择索引值为n的元素，n从0开始 $('div:eq(0)')
- :first 选择索引值为0的元素 $('div:first')
- :last 最后一个 $('div:last')
- :not() 取非 $('div:not(:last)')
- :even 偶数元素 $('div:even')
- :odd 奇数元素 $('div:odd')
- :gt(n) 索引值大于n的元素 $('div:gt(2)')  greater than
- :lt(n) 索引值小于n的元素 $('div:lt(3)') less than
- :header 所有标题元素 $(':header') 同h1,h2,h3,h4,h5,h6
- :animated 正在进行动画的元素 $(':animated')
>过滤选择器是层层过滤，每过滤一次又将重新排序

#### 子元素过滤选择器
- :root 选择文档根标签 $(':root')
- :nth-child(n) 父元素的第n个孩子，n从1开始 $('div:nth-child(3)')
- :first-child 父元素的第一个孩子 $('div:first-child')
- :last-child 父元素的最后一个孩子 $('div:last-child')
- :nth-last-child(n) 父元素的倒数第n个孩子 $('div:nth-last-child(2)')
- :only-child 父元素唯一的孩子 $('div:only-child')
- :nth-child(even) :nth-child(2n) 排行为偶数的孩子 $('nth-child(even)')
- :nth-child(odd) :nth-child(2n+1) :nth-child(2n-1) 排行为奇数的孩子 $('nth-child(odd)')
- :nth-of-type(n) 父元素下同类元素的排行n $('div:nth-of-type(3)')
- :first-of-type 父元素下同类元素排行第一 $('div:first-of-type')
- :last-of-type 父元素下同类元素排行最后 $('div:last-of-type')
- :nth-last-of-type(n) 父元素下同类元素倒数排行第n $('div:nth-last-of-type(2)')
- :only-of-type 父元素下同类元素中唯一一个  $('div:only-of-type')
- :nth-of-type(even) :nth-of-type(2n) 父元素下同类元素排行为偶数的孩子 $('nth-of-type(even)')
- :nth-of-type(odd) :nth-of-type(2n+1) :nth-of-type(2n-1) 父元素下同类元素排行为奇数的孩子 $('nth-of-type(odd)')

#### 内容过滤选择器
- :contains() 包含某个字符的元素，包含的字符需要时纯文本 $('li:contains('我')')
- :has() 内容中包含有某个标签的元素 $('li:has("img")')
- :empty 选择内容为空的元素 $('li:empty')
- :parent 选择内容非空的元素 $('li:parent') === $('li:not(:empty)')

#### 可见性选择器
- :hidden 选择所有隐藏元素 $("li:hidden")
- :visible 选择所有显示元素 $("li:visible")

#### 属性过滤选择器
- [attr] 选择具有attr属性的元素 $('img[alt]')
- [attr='val'] 选择attr属性值为val的元素 $('img[attr="val"]')
- [attr!='val'] 选择attr属性值不为val的元素 $('img[attr!="val"]')
- [attr*='val'] 选择attr属性值中包含val的元素 $('img[attr*="val"]')
- [attr^='val'] 选择attr数值以val开头的计 $('img[attr^="val"]')
- [attr$='val'] 选择attr数值以val结尾的计 $('img[attr$="val"]')
- [attr1][attr2][attr3]... 可以写多个数值

#### 表单元素属性过滤选择器
- :input 选中所有的表单元素 $(':input')
- :text 所有文本框 $(':text')
- :password 所有密码框 $(':password')
- :radio 所以单选框 $(':radio')
- :checkbox 复选框 $(':checkbox')
- :submit 提交按钮 $(':submit')
- :image 图片按钮 $(':image')
- :reset 重置按钮 $(':reset')
- :button 普通按钮 $(':button')
- :file 文件上传按钮 $(':file')
- input:hidden 隐藏表元素 $('input:hidden')
- :enabled 所有可用表单元素 $(':enabled')
- :disabled 所有不可用表单元素 $(':disabled')
- :checked 选中的单选按钮和复选按钮 $(':checked')
- :selected 选中的下拉列表项 $(':selected')

### 筛选选择器

#### 过滤筛选选择器
- filter(选择器) filter中可以写选择器还是可写函数并有一个参数表示当前值
~~~
$img.filter(':gt(1):lt(4)').css('border', '3px solid red');
$img.filter(function(index){   //index是形参，表示当前过滤元素的索引值
    //过滤筛选保留索引值为2-5之间的元素
    if(index>=2 && index<=5){
        return true;    //满足条件的元素，只要return true，就会保留下来
    }
}).css('border', '3px solid red');
~~~
- eq(索引值) 选择第几个元素
~~~
$img.filter(':eq(1)').css('border', '3px solid red');
$img.eq(1).css('border', '3px solid red');
~~~
- not(选择器) 出...外
~~~
$img.filter(':not(:eq(1))').css('border', '3px solid red');
$img.not(':eq(1)').css('border', '3px solid red');
~~~
- slice(arg1,arg2) 索引值在arg1和arg2之间的包含arg1，是一次性筛选，不是层层筛选
~~~
$img.filter(':gt(1):lt(4)').css('border', '3px solid red');
$img.slice(2,6).css('border', '3px solid red');
~~~
- is(选择器) 判断是否满足后面的条件
~~~
$img.filter(':last').is('.man')
~~~

#### 查找筛选选择器
- parent() 查找选择元素的父级
~~~
$('li').parent().css('border', '1px solid blue');
~~~
- children() 查找选择元素的子级
~~~
$('ol').children().css('border', '1px solid blue');
~~~
- siblings() 查找选择元素的相邻元素
~~~
$('li:eq(2)').siblings().css('border', '1px solid blue');
~~~
- next() 查找选择元素后面紧挨着的唯一一个元素
~~~
$('li:eq(2)+li').css('border', '1px solid blue');
$('li:eq(2)').next().css('border', '1px solid blue');
~~~
- nextAll() 查找选择元素紧挨着的所有元素
~~~
$('li:eq(2)~li').css('border', '1px solid blue');
$('li:eq(2)').nextAll().css('border', '1px solid blue');
~~~
- prev() 查找选择元素前面紧挨着的唯一一个元素
~~~
$('li:eq(2)').prev().css('border', '1px solid blue');
~~~
- prevAll() 查找选择元素前面紧挨着所有元素
~~~
$('li:eq(2)').prevAll().css('border', '1px solid blue');
~~~
- find(选择器) 选择元素后代中查找
~~~
$('ol p').css('border', '1px solid blue');
$('ol').find('p').css('border', '1px solid blue');
~~~

#### 串联筛选选择器
- addBack() 添加上选中元素之前的元素
~~~
$('li:eq(2)').prev().addBack().css('border', '1px solid blue');
~~~
- end() 返回到最近一次破坏之前的状态
~~~
console.log($(this));
console.log($(this).siblings().css('border', '0 none').end());
~~~

### 其他

#### 链式编程
当选择的元素相同的时候，后面可以连续书写。
~~~
//方法一：
$(this).css('border', '5px solid red');
$(this).siblings().css('border', '0 none');
//方法二：
$(this).css('border', '5px solid red').siblings().css('border', '0 none');
~~~

#### 选择元素的索引值
选择元素的当前索引值。
~~~
$('ol li').click(function(){
    alert($(this).index());
});
~~~
> 当修改和访问表单元素属性的时候，用attr()方法有bug，需要用prop()代替。

## 动画

### 隐藏显示动画
- show(arg1,arg2,arg3) 显示选择元素，arg1表示动画时长毫秒数，arg2缓动曲线swing和linear，arg3当动画完成时的回调函数，三个参数都是可选。
- hide(arg1,arg2,arg3) 隐藏选择元素，参数同上
- toggle(arg1,arg2,arg3) 在显示和隐藏之间进行切换，参数同上 

### 滑动动画
- slideUp(arg1,arg2,arg3) 向上滑动隐藏，arg1表示动画时长毫秒数，arg2缓动曲线swing和linear，arg3当动画完成时的回调函数，三个参数都是可选。
- slideDown(arg1,arg2,arg3) 向下滑动显示，参数同上
- slideToggle(arg1,arg2,arg3)  动画隐藏和显示之间切换，参数同上

### 透明度动画
- fadeOut(arg1,arg2,arg3) 淡出，参数同上
- fadeIn(arg1,arg2,arg3) 淡入，参数同上
- fadeTo(arg1,arg2,arg3,arg4) 不透明度到多少，arg1表示动画时长，arg2不透明度到多少值(1完全不透明0完全透明)，arg3表示缓动曲线，arg4表单动画完成时的回调函数

### 自定义动画
animate({attr1:val1,attr2:val2.....},动画时长,缓动曲线,回调函数)
~~~
// 文字变化
$('div').animate({'font-size':'50px', 'border-width':20, paddingTop:30, paddingBottom:30}, 2000);
// 居中变化
$('img:eq(0)').animate({width:0, marginLeft:200}, 1000).animate({width:400, marginLeft:0}, 1000);
// 左右切换
$('img:eq(1)').animate({width:'toggle'}, 1000);
~~~

### 停止动画
- delay(延迟时长) 让动画在当前状态停留多长时间
- stop(是否清除动画的排队,是否调到动画的终止位置) 默认都是false，如果第一个参数为false表示停止当前动画，后面的动画继续，如果为true为停止所有动画通常用于清除动画排队机制造成的影响，如果第二个参数为false表示动画停留在当前位置，为true则表示停止动画并调到当前动画的终点
- finish() 停止所有动画，并调到最后一个动画的终止状态
> 属性值为纯数字的属性可以发生自定义动画如：width、height、padding-top、padding-left、border-width、margin-left等
> 属性值有几个特殊的取值：hide表示最小值、show表示最大值、toggle表示在两者之间切换

### 动画排队机制

#### 动画排队机制
动画是从前往后依次执行的，只有当前面的动画执行完毕时后面紧挨着的动画才会执行，也就是说如果当用户的操作特别快时动画还没执行完又有另一个动画触发那么久依次执行完毕
~~~
$('#ad').slideToggle(800).fadeOut(500).fadeIn(500);  //动画是从前往后依次排队执行的，只有当前面的动画执行完毕的时候，后面紧挨着的动画才会接着执行。
~~~

#### 清除动画的排队
有时动画排队会有不预期的效果，需要清除则需要使用stop(true)来清除动画排队造成的影响。

## DOM操作

### 元素操作
元素的操作主要为增、删、改、查、复制。

#### 查找元素
查找元素就是选择器选择的过程，查找元素是指查找已有的元素。

#### 增加元素
增加元素通常是增加到文档中需要自己创建元素在增加。
- append() 将创建元素追加到指定元素的内部的最后，选择元素为已存在的元素
~~~
$('ul:eq(1)').append('<li>我是新创建元素</li>');
~~~
- appendTo() 将创建元素追加到指定元素的内部的最后，选择元素为新创建的
~~~
$('<p>我是新创建元素</p>').appendTo($('div'));
~~~
- prepend() 将创建元素追加到指定元素的内部的最前，选择元素为已存在的元素
~~~
$('ul').prepend('<li>我是新创建元素</li>')
~~~
- prependTo() 将创建元素追加到指定元素的内部的最前，选择元素为新创建的
~~~
$('<li>我是新创建元素</li>').prependTo($('ul'));
~~~
- before() 将新创建元素添加到选中元素同级紧挨着的前面，选择元素为已存在的元素
~~~
$('#CloseUncle').before('<p>我是新创建元素</p>');
~~~
- insertBefore() 将新创建元素添加到选中元素同级紧挨着的前面，选择元素为新创建的
~~~
$('<p>我是新创建元素</p>').insertBefore($('#CloseUncle'));
~~~
- after() 将新创建元素添加到选中元素同级紧挨着的后面，选择元素为已存在的元素
~~~
$('#CloseUncle').after('<p>我是新创建元素</p>');
~~~
- insertAfter()  将新创建元素添加到选中元素同级紧挨着的后面，选择元素为新创建的
~~~
$('<p>我是新创建元素</p>').insertAfter($('#CloseUncle'));
~~~
- wrap() 用新创建的元素分别包裹选中的元素，选择元素为已存在的元素
~~~
// 给p,img和div标签分别包裹section
$('button:eq(0)').click(function(){
    $('p,img,div').wrap('<section></section>');
});
~~~
- wrapAll() 用新创建的元素整个包裹选中的元素，选择元素为已存在的元素
~~~
// 用section包裹p,img和div
$('button:eq(1)').click(function(){
    $('p,img,div').wrapAll('<section></section>');
});
~~~
- wrapInner() 用新创建元素包裹选中元素的内部，选择元素为已存在的元素
~~~
//用span分别包裹p和div的内部
$('button:eq(2)').click(function(){
    $('p,div').wrapInner('<span></span>');
});
~~~
> $.trim(字符串) 修剪掉字符串前后的空格

#### 删除元素
- remove() 删除选中元素，彻底删除连根拔起
~~~
$('ol').remove(); //ol包括li都删除
~~~
- empty() 清空选中元素，留空壳子
~~~
$('ul').empty(); //最后ul标签还存在
~~~
- detach() 删除选中的元素，但是不删除元素附带的资源(例如：其身上绑定的事件)
~~~
//创建图片
var $img = $('<img src="images/36/xiaolongnv.jpg" alt="">');
$img.mouseover(function(){
    $img.attr('src', 'images/36/dalongnv.jpg');
}).mouseout(function(){
    $img.attr('src', 'images/36/xiaolongnv.jpg');
});
// 删除图片
$('button:eq(3)').click(function(){
    $img.detach();
});
//当再次添加图片时事件都还在
~~~

#### 修改元素
- replaceWith() 用新创建元素替换选中元素，选择元素为已存在元素
~~~
$('.box').replaceWith('<img src="logo.png">');
~~~
- replaceAll() 用新创建元素替换选中元素，选择元素为新创建元素
~~~
$('<img src="logo.png">').replaceAll($('.box'));
~~~

#### 复制元素
使用clone()来复制元素
~~~
$('ol').append($('ul>li').clone());
~~~

### 属性操作
- attr(属性名,属性值) 修改或访问标签属性，一个参数表示访问，两个参数表示修改
- removeAttr(属性名) 删除标签属性
~~~
$('img').attr('title', ''); //删除后title属性还在只不过没有值
$('img').removeAttr('title'); //删除后title属性也删除
~~~
- addClass(类名) 给选中元素添加某个类
~~~
$('img').addClass('lanbian');
~~~
- removeClass(类名) 给选中元素删除某个类
~~~
$('img').removeClass('lanbian');
~~~
- toggleClass(类名) 给选中元素切换某个类
~~~
$('img').toggleClass('lanbian');
~~~
- hasClass(类名) 判断选中元素是否有某个类
~~~
alert($('img').hasClass('lanbian'));
~~~
- prop(属性名,属性值) 修改或访问表单元素的标签属性
~~~
// 访问表单元素的类型
// alert($('input').attr('type'));  
// 访问或修改表单元素属性的时候,.attr()有bug，需要使用.prop
alert($('input').prop('type'));
// 修改表单元素的类型
$('input').prop('type', 'range');
~~~
- val() 修改或访问表单元素的value值
~~~
// 修改表单元素的值
// $('input').prop('value', 80);
$('input').val(80);

// 访问表单元素的值
// alert($('input').prop('value'));
alert($('input').val());
~~~

### 文本操作
- html() 修改或访问选中元素的html
- text() 修改或访问选中元素的纯文本

### 样式操作
- css() css()单属性修改 多属性修改 单属性访问
~~~
// 设置box的CSS
/*
$('.box').css('background-color', '#ccc')
            .css('line-height', '200px')
            .css('text-align', 'center');
*/
$('.box').css({'background-color':'#ccc', lineHeight:'200px', textAlign:'center'});

// 获取box的字体大小
alert($('.box').css('font-size'));
~~~
- width() 修改或访问选中元素的宽度
~~~
// $('.box').css('width', 300);
$('.box').width(300);
~~~
- height() 修改或访问选中元素的高度
~~~
// $('.box').css('height', 300);
$('.box').height(300);
~~~
- innerWidth() 获取盒子的内容宽度+左右padding的宽度
- innerHeight() 获取盒子的内容高度+左右padding的高度
~~~
$('.box').innerWidth();   //盒子的内容宽度+左右padding的宽度
$('.box').innerHeight();   //盒子的内容高度+上下padding的高度
~~~
- outerWidth() 获取盒子的内容宽度+左右padding的宽度+左右border
- outerHeight() 获取盒子的内容高度+左右padding的高度+上下border
~~~
$('.box').outerWidth(); //盒子的内容宽度+左右padding的宽度+左右border
$('.box').outerHeight();//盒子的内容高度+上下padding的高度+上下border
~~~
- outerWidth(true) 获取盒子的内容宽度+左右padding的宽度+左右border+左右margin
- outerHeight(true) 获取盒子的内容高度+左右padding的高度+上下border+上下margin
~~~
// 盒子的内容宽度+左右padding的宽度+左右border+左右margin
$('.box').outerWidth(true);
// 盒子的内容高度+上下padding的高度+上下border+上下margin
$('.box').outerHeight(true);
~~~
- 获取浏览器窗口的宽高
~~~
$(window).width();   //浏览器窗口的宽度
$(window).height();  ////浏览器窗口的高度
~~~
> 获取到的浏览器可视范围的宽高

### 其他操作

#### 元素的滚动坐标值
隐藏在左侧内容的宽度，就叫做该元素滚动坐标值的横坐标，通过$el.scrollLeft()获取；
隐藏在上侧内容的高度，就叫做该元素滚动坐标值的纵坐标，通过$el.scrollTop()获取；
元素的滚动坐标值，常用于求窗口的滚动坐标值。

#### 滚动到页面指定位置
对象应该选$('html,body')，如果只选择$('html')，那么firefox和IE可行，但是chrome不可以；如果只选择$('body')，chrome可以，但是firefox和IE不可行，所以为了兼容所有的浏览器，应该选择$('html,body')作为对象。
在.animate()自定义动画中，提供了一个属性scrollTop属性，我们只要把需要滚动的纵坐标值付给scrollTop属性即可滚动对应的位置。
~~~
$('html,body').animate({scrollTop:0}, 500);
~~~

#### 元素的文档坐标值
相对左上角的偏移量
横向的偏移量，就是该元素的文档坐标值的横坐标，用$el.offset().left来获取;
纵向的偏移量，就是该元素的文档坐标值的纵坐标，用$el.offset().top来获取;
~~~
$('.box').offset().left;   //选中元素文档坐标值的横坐标
$('.box').offset().top;    //选中元素文档坐标值的纵坐标
~~~
#### 定位元素相对于定位点的坐标值
定位元素相对于定位点的坐标值：
$el.position().left;    选中元素相对于定位点的横坐标；
$el.position().top;    选中元素相对于定位点的纵坐标。
~~~
$('img').position().left;  // 选中元素相对于定位点的横坐标
$('img').position().top;   // 选中元素相对于定位点的纵坐标
~~~

## jQuery事件

### 标准DOM事件

#### UI事件
- unload 页面元素卸载时触发
- scroll 可滚动元素或者宽口滚动时触发，如果连续滚动就会连续触发
- resize 当窗口改变大小时触发
- select 当文本框或者文本域中的内容被选中时触发

#### 焦点事件
- click 点击选中元素时触发
- dblclick 双击选中元素时触发
- mousedown 鼠标在选中元素上按下时触发
- mouseup 在选中元素上松开鼠标按键时触发
- mouseover 鼠标移上选中元素时触发
- mouseout 鼠标离开选中元素时触发
- mousemove 鼠标在选中元素上移动时触发，移动多=多次，触发多次

####　键盘事件
- keydown 键盘的按键被按下时触发，事件源可以使文本框、文本域、window和document等
- keyup 键盘的按键松开时触发，事件源可以使文本框、文本域、window和document等
- keypress 鼠标按键被按下时触发
> keydown和keypress区别：如果按下的是字符键两者都会触发，如果按下的功能键(ctrl、shift、alt等)只有keydown会被触发，keypress不会触发

#### 表单事件
- submit 表单提交时触发，事件源需要时form
- change 表单元素的值发生改变时触发
> change和input的区别：input是只要值一发生改变就会触发，change当值发生改变并失去焦点的时候触发；input的事件源需要时文本框或者文本域，change的事件源可以是文本框、文本域   、单选、复选、下拉；input兼容性没有input好

### jQuery自定义事件

#### 页面载入事件
~~~
$(function(){

})
~~~
#### 鼠标事件
- mouseover(事件处理函数) 鼠标移上选中元素
- mouseout(事件处理函数) 鼠标离开选中元素
> 当事件源里面有子元素时，鼠标移到改子元素上时以上两个事件时有bug的，原因是：移上事件源里面的子元素上时会触发mouseout事件，然后以判断该子元素属于事件源的所以又触发mouseover。IE首先发现这个bug并提出了解决办法就是新增两个事件替换移上两个，其他浏览器厂商觉得也不错就采纳了。
~~~
/* 此处使用这两个有bug
$('.menu>li').mouseover(function(){
    $(this).children().slideDown();
}).mouseout(function(){
    $(this).children().slideUp();
});
*/
~~~
- mouseenter(事件处理函数) 鼠标移上选中元素
- mouseleave(事件处理函数) 鼠标离开选中元素
~~~
$('.menu>li').mouseenter(function(){
    $(this).children().stop(true).slideDown();
}).mouseleave(function(){
    $(this).children().stop(true).slideUp();
});
~~~
- hover(mouseenter事件处理函数,mouseleave事件处理函数) jQuery提供了mouseenter和mouseleave的合体形式，当事件处理函数相同时允许只写一个事件处理函数表示鼠标移上和离开都执行相同事件处理函数
~~~
$('.menu>li').hover(function(){
    // $(this).children().stop(true).slideDown();
    $(this).children().stop(true).slideToggle();
}).hover(function(){
    // $(this).children().stop(true).slideUp();
    $(this).children().stop(true).slideToggle();
});

$('.menu>li').hover(function(){
    $(this).children().stop(true).slideToggle();
});
~~~
> toggle事件类型在1.9后就废除了

#### 焦点事件
- focusin 表单元素获取焦点时
- focusout  表单元素失去焦点时
> focusin、focusout和focus、blur的区别：前者可以用于表单元素，也可以用于表单元素的父盒子；后者只能用于表单元素

#### 事件绑定
- 事件类型(fun) 快捷方式的事件绑定，不是所有事件类型都支持快捷方式
- bind('事件类型',fun) 事件绑定的原型方式，所有快捷方式都可以用原型绑定
- unbind() 解除bind绑定的事件，如果不写参数表示解绑选择元素的所有事件，如果写一个参数为事件类型表示解绑指定事件类型的所有事件，如果写两个参数事件类型和事件处理函数表示解绑执行事件类型和事件处理函数的事件
- one('事件类型',fun) 只给选中的元素绑定一次事件
- on() 凡是用bind绑定的事件都可以用on绑定
- off() 解除on绑定的事件，如果不写参数表示解绑选择元素的所有事件，如果写一个参数为事件类型表示解绑指定事件类型的所有事件，如果写两个参数事件类型和事件处理函数表示解绑执行事件类型和事件处理函数的事件
- error() 当选中元素出错时触发
~~~
//错误处理事件，可以将出错的图片替换
$('img').error(function(){
    //$(this).replaceWith('<img src="images/logo.png">');
    $(this).attr('src','images/logo.png');
});
~~~

#### 事件委托
- delegate('子代的选择器','事件类'.fun) 添加事件委托
- undelegate() 取消事件委托
> 凡是可以用delegate做委托的事件一律可以用on做事件委托，取消委托用off()
~~~
$('input:button').bind('click',function(){
    $('ul').prepend('<li>new<span>&times;</span></li>');
});

/*
// 使用delegate来做事件委托
// 通常将事件委托给他们的公共父级
$('ul').delegate('li span','click',function(){
    $(this).parent().remove();
});

//取消事件委托
//$('ul').undelegate();

*/

//用on来做事件委托
$('ul').on('click','li span',function(){
    $(this).parent().remove();
});

//取消事件委托
//$('ul').off();
~~~

#### 事件触发
事件类型触发的三种方式：
- 事件类型()
- trigger('事件类型')
- triggerHandler('事件类型')
> trigger和triggerHandler的区别：triggerHandler不会触发默认事件也不会产生事件冒泡；trigger会产生移上操作，可以用stopPropagation来阻止事件冒泡，可以用preventDefault()来阻止默认事件或者在事件处理函数中返回false；triggerHandler只触发jQuery对象集合中第一个元素的事件处理函数；triggerHandler返回的是事件处理函数的返回值而不是具有可链式的jQuery对象，trigger返回具有可链式jQuery对象，可以进行链式编程。推荐用前两种，triggerHandler不推荐。

### 事件对象

#### 事件发生位置
- 事件对象.pageX 事件发生地的横坐标
- 事件对象.pageY 事件发生地的纵坐标
> 也可以用clientX和clientY，jQuery已有兼容

#### 键盘信息
- 事件对象.which 得到按键的对应ascll码
- 当按下Ctrl键的时候，事件对象.ctrlKey为true，否则为false;
- 当按下Shift键的时候，事件对象.shiftKey为true，否则为false;
- 当按下Alt键的时候，事件对象.altKey为true，否则为false;
~~~
$(document).keydown(function(e){
    console.log(e.which);
    /*
        空格键                       32
            ↑                        38
            ↓                        40
            ←                        37
            →                        39

        当按下Ctrl键的时候，事件对象.ctrlKey为true，否则为false;
        当按下Shift键的时候，事件对象.shiftKey为true，否则为false;
        当按下Alt键的时候，事件对象.altKey为true，否则为false;
    */
}
~~~

#### 阻止事件冒泡
- 在事件处理函数的最后返回false
~~~
//阻止默认事件
return false;
~~~
- 事件对象.stopPropagation()来阻止事件冒泡
~~~
e.stopPropagation();
~~~
- 如果即允许冒泡又不想事件冒泡产生危害，可以判断
~~~
if(e.target==e.currentTarget){
    //e.target 表示最初触发事件的事件源
    //e.currentTarget 冒泡阶段中的当前事件对象
}
~~~

#### 阻止默认事件
- 在事件处理函数的最后返回false
- 事件对象.preventDefault()

## 深入jQuery

### jQuery对象与原生js对象的转换
jQuery对象在使用方面和原生JS对象有所不同，所以为了便于区分，我们通常在命名jQuery对象的时候， 以$开头，表示这是jQuery的对象，非原生JS的对象
#### jQuery对象转原生js对象
jQuery对象是一个数组对象，所以把它转为原生JS对象的方法：
- jQuery对象[索引值]
- jQuery对象.get(索引值)
~~~
$('ol lo:eq(1)')[0].style.background = '#f00';
$('ol lo:eq(1)').get(0).style.background = '#f00';
~~~

#### 原生js对象转jQuery对象
只需要用jQuery的选择函数选择就可以转成jQuery对象
- this -> $(this)
- window -> $(window)
- document -> $(document)
- el -> $(el)

#### $对象
通过查看源代码可以发现$就是jQuery，为避免冲突在项目中使用多种框架，并其他框架已使用$了，就需要把$替换成jQuery，也可以在页面载入事件将$以参数的形式传递就可以做使用了，如下：
~~~
jQuery(function($){
    jQuery('ul li:eq(1)').css('background','yellow');
    $('ul li:eq(2)').css('background','hotpink');
});
~~~

#### 加工函数(遍历函数)
对选中元素逐一进行遍历
~~~
//index 表示当前正在被遍历的元素的索引值
//el 表示当前正在被遍历的元素
$('ul li').each(function(index,el){
    $(this).css('background-position','left -'+index*24+'px');
});
~~~