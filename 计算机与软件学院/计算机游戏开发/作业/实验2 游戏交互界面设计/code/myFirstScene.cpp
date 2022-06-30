#include "MyFirstScene.h"
#include"HelloWorldScene.h"

//MyFirstScene场景创建实现
Scene* MyFirstScene::createScene()
{
	auto scene = Scene::create();	//创建一个场景
	auto layer = MyFirstScene::create();//创建一个MyFirstScene层
	scene->addChild(layer);		//把MyFirstScene层加入刚刚创建的场景中，
	return scene;			//返回这个场景
}

bool MyFirstScene::init()
{
	if (!Layer::init())	//先初始化父类的init方法，如何初始化失败，则创建MyFirstScene层失败
	{
		return false;
	}
	Size VisibleSize = Director::getInstance()->getVisibleSize();	//获得屏幕大小

	auto label = Label::createWithSystemFont("Click to start the Game!", "fonts/arial.ttf", 30);//创建一个标签
	//菜单条目的创建有多种，之前的HelloWorld.cpp中实现的是图片菜单条目(MenuItemImage)，即根据图片来创建菜单条目
	//这里是根据标签来创建菜单条目,然后设置回调函数
	auto menuitem = MenuItemLabel::create(label, CC_CALLBACK_1(MyFirstScene::EnterSecondScene, this));
	//创建好了菜单条目，就需要加入菜单中，所以下面就是创建菜单
	auto menu = Menu::create(menuitem, NULL);
	//把菜单添加到MyFirstScene层中
	this->addChild(menu);

	return true;
}
//菜单回调函数的实现
void MyFirstScene::EnterSecondScene(Ref* pSender)
{
	//我们知道，如果需要跳转场景，就会想到一个类，它就是Director类，它就是管理场景的
	//这里跳转场景调用到的是导演类的这个接口：replaceScene(Scene *scene),里面传进去的是就是一个场景，这里需要注意的是场景二的头文件这是要加上的
	Director::getInstance()->replaceScene(HelloWorld::createScene());
}