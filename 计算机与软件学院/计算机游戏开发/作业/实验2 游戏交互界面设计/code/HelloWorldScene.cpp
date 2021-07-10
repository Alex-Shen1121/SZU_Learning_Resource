#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = HelloWorld::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// ����ת�������ַ���GBKתUTF-8��
std::string GBKToUTF8_2(const std::string& strGBK) {
	std::string strOutUTF8 = "";
	WCHAR* str1;
	int n = MultiByteToWideChar(CP_ACP, 0, strGBK.c_str(), -1, NULL, 0);
	str1 = new WCHAR[n];
	MultiByteToWideChar(CP_ACP, 0, strGBK.c_str(), -1, str1, n);
	n = WideCharToMultiByte(CP_UTF8, 0, str1, -1, NULL, 0, NULL, NULL);
	char* str2 = new char[n];
	WideCharToMultiByte(CP_UTF8, 0, str1, -1, str2, n, NULL, NULL);
	strOutUTF8 = str2;
	delete[]str1;
	str1 = NULL;
	delete[]str2;
	str2 = NULL;
	return strOutUTF8;
}

static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

bool HelloWorld::init()
{
	if (!Layer::init())
	{
		return false;
	}


	visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//�����ɫ��
	auto colorLayer = LayerColor::create(Color4B(128, 125, 200, 255), 480, visibleSize.height);
	colorLayer->setPosition(Vec2(200, 0));
	this->addChild(colorLayer);

	// add a "close" icon to exit the progress. it's an autorelease object
	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2,
		origin.y + closeItem->getContentSize().height / 2));

	// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	auto replayItem = MenuItemImage::create(
		"replay.png",
		"replay.png",
		CC_CALLBACK_1(HelloWorld::menuReplayCallback, this));

	replayItem->setPosition(Vec2(origin.x + visibleSize.width - replayItem->getContentSize().width / 2 - 200,
		origin.y + replayItem->getContentSize().height / 2));

	// create menu, it's an autorelease object
	auto menu2 = Menu::create(replayItem, NULL);
	menu2->setPosition(Vec2::ZERO);
	this->addChild(menu2, 2);

	
	if (scoreboard == nullptr)
	{
		problemLoading("'fonts/Marker Felt.ttf'");
	}
	else
	{
		// position the label on the center of the screen
		scoreboard->setPosition(Vec2(origin.x + visibleSize.width / 3, origin.y + visibleSize.height - scoreboard->getContentSize().height));
		scoreboard->setName("scoreboard");
		// add the label as a child to this layer
		this->addChild(scoreboard, 1);
	}

	//�ƶ�����
	bean = Sprite::create("Chapter10/bean.png");
	bean->setPosition(Point(visibleSize.width / 2, 100));
	this->addChild(bean, 6);

	// ҡ��
	m_joystick = Joystick::create(Vec2(100, 100), 50.0f, "Chapter10/j-btn.png", "Chapter10/j-bg.png");
	this->addChild(m_joystick, 4);

	this->schedule(schedule_selector(HelloWorld::addBall1), 1.0f);
	this->schedule(schedule_selector(HelloWorld::addBall2), 2.0f);
	this->schedule(schedule_selector(HelloWorld::addBall3), 3.0f);
	this->scheduleUpdate();

	return true;
}
void HelloWorld::addBall1(float dt) {
	auto ball1 = Sprite::create("Chapter10/ball.png");//ʹ��ͼƬ����С��
	ball1->setPosition(Point(207 + rand() % 460, visibleSize.height));//����С��ĳ�ʼλ�ã�������x����ʹ�����������randʹ��С�������λ�ó���
	this->addChild(ball1, 5);
	this->ballVector.pushBack(ball1);//��С��Ž�Vector����
	auto moveTo = MoveTo::create(rand() % 5, Point(ball1->getPositionX(), -10));//�ƶ�����
	auto actionDone = CallFunc::create(CC_CALLBACK_0(HelloWorld::removeBall, this, ball1));//��С���ƶ�����Ļ�·�ʱ�ص�removeBall�������Ƴ�С��
	auto sequence = Sequence::create(moveTo, actionDone, nullptr);
	ball1->runAction(sequence);//ִ�ж���
}

void HelloWorld::addBall2(float dt) {
	auto ball2 = Sprite::create("Chapter10/ball1.png");
	ball2->setPosition(Point(207 + rand() % 460, visibleSize.height));
	this->addChild(ball2, 5);
	this->ballVector.pushBack(ball2);
	auto moveTo = MoveTo::create(rand() % 5, Point(ball2->getPositionX(), -10));
	auto actionDone = CallFunc::create(CC_CALLBACK_0(HelloWorld::removeBall, this, ball2));
	auto sequence = Sequence::create(moveTo, actionDone, nullptr);
	ball2->runAction(sequence);
}
void HelloWorld::addBall3(float dt) {
	auto ball3 = Sprite::create("Chapter10/ball2.png");
	ball3->setPosition(Point(207 + rand() % 460, visibleSize.height));
	this->addChild(ball3, 5);
	this->ballVector.pushBack(ball3);
	auto moveTo = MoveTo::create(rand() % 5, Point(ball3->getPositionX(), -10));
	auto actionDone = CallFunc::create(CC_CALLBACK_0(HelloWorld::removeBall, this, ball3));
	auto sequence = Sequence::create(moveTo, actionDone, nullptr);
	ball3->runAction(sequence);
}
void HelloWorld::removeBall(Sprite* ball) {
	this->removeChild(ball);
	ballVector.eraseObject(ball);
}
void HelloWorld::update(float dt) {
	for (auto ball : ballVector)
	{
		
		
		
		//������ײ���
		if (bean->getBoundingBox().intersectsRect(ball->getBoundingBox()))
		{
			auto actionDown = CallFunc::create(CC_CALLBACK_0(HelloWorld::removeBall, this, ball));
			ball->runAction(actionDown);
			if (ball->getResourceName() == "Chapter10/ball.png")
				score += 1;
			else if (ball->getResourceName() == "Chapter10/ball1.png")
				score += 2;
			else if (ball->getResourceName() == "Chapter10/ball2.png")
				score += 3;
			scoreboard->setString("Score Board: " + std::to_string(score));
		}
	}

	
	Vec2 angle = m_joystick->getDirection();
	if (angle.x == 0 && angle.y == 0)
	{
		bean->setPositionX(bean->getPositionX());
		bean->setPositionY(bean->getPositionY());
	}
	else {
		if (bean->getPositionY() - bean->getContentSize().height / 2 >= 0 && bean->getPositionY() - bean->getContentSize().height / 2 <= 200) {
			bean->setPositionY(bean->getPositionY() + m_joystick->getVelocity() * angle.y / sqrt(angle.x * angle.x + angle.y * angle.y));
		}
		else if (bean->getPositionY() - bean->getContentSize().height / 2 < 0)
			bean->setPositionY(0 + bean->getContentSize().height / 2);
		else if (bean->getPositionY() - bean->getContentSize().height / 2 > 200)
			bean->setPositionY(200 + bean->getContentSize().height / 2);

		if (bean->getPositionX() + bean->getContentSize().width / 2 <= 680 && bean->getPositionX() - bean->getContentSize().width / 2 >= 200) {
			bean->setPositionX(bean->getPositionX() + m_joystick->getVelocity() * angle.x / sqrt(angle.x * angle.x + angle.y * angle.y));
		}
		else if (bean->getPositionX() + bean->getContentSize().width / 2 > 680)
			bean->setPositionX(680 - bean->getContentSize().width / 2);
		else if (bean->getPositionX() - bean->getContentSize().width / 2 < 200)
			bean->setPositionX(200 + bean->getContentSize().width / 2);
	}
	//}

	//if (score > 5) {
	//	Director::getInstance()->stopAnimation();
	//	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//	auto replayItem = MenuItemImage::create(
	//		"CloseNormal.png",
	//		"CloseSelected.png",
	//		CC_CALLBACK_1(HelloWorld::menuReplayCallback, this));

	//	replayItem->setPosition(Vec2(origin.x + visibleSize.width - replayItem->getContentSize().width / 2-300,
	//		origin.y + replayItem->getContentSize().height / 2));

	//	// create menu, it's an autorelease object
	//	auto menu = Menu::create(replayItem, NULL);
	//	menu->setPosition(Vec2::ZERO);
	//	this->addChild(menu, 1);
	//}
	if (score > 5) {
		Director::getInstance()->pause();
		Vec2 origin = Director::getInstance()->getVisibleOrigin();
		Label* success = Label::createWithTTF("SUCCESS!", "fonts/Marker Felt.ttf", 72);
		if (success == nullptr)
		{
			problemLoading("'fonts/Marker Felt.ttf'");
		}
		else
		{
			// position the label on the center of the screen
			success->setPosition(Vec2(origin.x + visibleSize.width / 2.5, origin.y + visibleSize.height / 2));
			success->setName("success");
			// add the label as a child to this layer
			this->addChild(success, 1);
		}
	}

}
void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.", "Alert");
	return;
#endif
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}

void HelloWorld::menuReplayCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.", "Alert");
	return;
#endif
	score =0;
	Director::getInstance()->replaceScene(HelloWorld::createScene());
	Director::getInstance()->resume();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}
