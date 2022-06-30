#include "MyFirstScene.h"
#include"HelloWorldScene.h"

//MyFirstScene��������ʵ��
Scene* MyFirstScene::createScene()
{
	auto scene = Scene::create();	//����һ������
	auto layer = MyFirstScene::create();//����һ��MyFirstScene��
	scene->addChild(layer);		//��MyFirstScene�����ոմ����ĳ����У�
	return scene;			//�����������
}

bool MyFirstScene::init()
{
	if (!Layer::init())	//�ȳ�ʼ�������init��������γ�ʼ��ʧ�ܣ��򴴽�MyFirstScene��ʧ��
	{
		return false;
	}
	Size VisibleSize = Director::getInstance()->getVisibleSize();	//�����Ļ��С

	auto label = Label::createWithSystemFont("Click to start the Game!", "fonts/arial.ttf", 30);//����һ����ǩ
	//�˵���Ŀ�Ĵ����ж��֣�֮ǰ��HelloWorld.cpp��ʵ�ֵ���ͼƬ�˵���Ŀ(MenuItemImage)��������ͼƬ�������˵���Ŀ
	//�����Ǹ��ݱ�ǩ�������˵���Ŀ,Ȼ�����ûص�����
	auto menuitem = MenuItemLabel::create(label, CC_CALLBACK_1(MyFirstScene::EnterSecondScene, this));
	//�������˲˵���Ŀ������Ҫ����˵��У�����������Ǵ����˵�
	auto menu = Menu::create(menuitem, NULL);
	//�Ѳ˵���ӵ�MyFirstScene����
	this->addChild(menu);

	return true;
}
//�˵��ص�������ʵ��
void MyFirstScene::EnterSecondScene(Ref* pSender)
{
	//����֪���������Ҫ��ת�������ͻ��뵽һ���࣬������Director�࣬�����ǹ�������
	//������ת�������õ����ǵ����������ӿڣ�replaceScene(Scene *scene),���洫��ȥ���Ǿ���һ��������������Ҫע����ǳ�������ͷ�ļ�����Ҫ���ϵ�
	Director::getInstance()->replaceScene(HelloWorld::createScene());
}