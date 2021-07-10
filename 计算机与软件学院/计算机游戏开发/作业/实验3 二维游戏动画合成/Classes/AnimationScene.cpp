#include "AnimationScene.h"

USING_NS_CC;

int gamecnt = 0;
AnimationScene::AnimationScene()
{

}

AnimationScene::~AnimationScene()
{

}

bool AnimationScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();

	// ±³¾°
	auto background = LayerColor::create(Color4B(128, 128, 128, 255), 960, 640);
	background->setPosition(Vec2(0, 0));
	background->setTag(110);
	this->addChild(background);
	auto cloud_1 = Sprite::create("Chapter06/AnimationScene/animation/background/cloud.png");
	cloud_1->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	cloud_1->setTag(112);
	this->addChild(cloud_1);
	auto cloud_2 = Sprite::create("Chapter06/AnimationScene/animation/background/cloud.png");
	cloud_2->setPosition(Vec2(cloud_1->getPositionX() + cloud_1->getContentSize().width, visibleSize.height / 2));
	cloud_2->setTag(113);
	this->addChild(cloud_2);

	// ±³¾°ÎÄ×ÖVS
	auto tips_vs = Label::createWithBMFont("fonts/futura-48.fnt", "VS");
	tips_vs->setPosition(Vec2(visibleSize.width / 2, visibleSize.height - 80));
	this->addChild(tips_vs, 5);

	// Ò¡¸Ë
	m_joystick = Joystick::create(Vec2(100, 100), 50.0f, "Chapter06/AnimationScene/animation/control/j-btn.png", "Chapter06/AnimationScene/animation/control/j-bg.png");
	this->addChild(m_joystick, 4);

	// ¹¥»÷
	auto attackItem = MenuItemImage::create(
		"Chapter06/AnimationScene/animation/control/j-btn.png",
		"Chapter06/AnimationScene/animation/control/j-btn.png",
		CC_CALLBACK_1(AnimationScene::attackCallback, this));

	attackItem->setPosition(Vec2(visibleSize.width - 80, 200));

	auto defendItem = MenuItemImage::create(
		"Chapter06/AnimationScene/animation/control/j-btn.png",
		"Chapter06/AnimationScene/animation/control/j-btn.png",
		CC_CALLBACK_1(AnimationScene::defendCallback, this));

	defendItem->setPosition(Vec2(visibleSize.width - 200, 200));

	auto act1 = FadeOut::create(1);
	auto act2 = FadeIn::create(1);
	auto act3 = Sequence::create(act1, act2, NULL);
	auto act = RepeatForever::create(act3);  // °´Å¥ÉÁË¸
	attackItem->runAction(act);
	//defendItem->runAction(act);
	auto menu = Menu::create(attackItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 5);
	auto menu2 = Menu::create(defendItem, NULL);
	menu2->setPosition(Vec2::ZERO);
	this->addChild(menu2, 6);

	auto replayItem = MenuItemImage::create(
		"replay.png",
		"replay.png",
		CC_CALLBACK_1(AnimationScene::menuReplayCallback, this));

	replayItem->setPosition(Vec2(visibleSize.width - 50, 50));
	// create menu, it's an autorelease object
	menu2 = Menu::create(replayItem, NULL);
	menu2->setPosition(Vec2::ZERO);
	this->addChild(menu2, 7);
	// position the label on the center of the screen
	scoreboard= Label::createWithTTF("Successful Round: " + std::to_string(gamecnt), "fonts/Marker Felt.ttf", 48);
	scoreboard->setPosition(Vec2(visibleSize.width / 2, visibleSize.height - scoreboard->getContentSize().height - 200));
	// add the label as a child to this layer
	this->addChild(scoreboard, 1);
	// µØÍ¼
	auto map = TMXTiledMap::create("Chapter06/AnimationScene/animation/background/background.tmx");
	if (map == NULL)
	{
		CCLOG("map load failed!");
		return false;
	}
	Size mapSize = map->getMapSize();
	Size tiledSize = map->getTileSize();
	map->setPosition(Vec2(0, 0));
	map->setTag(111);
	this->addChild(map, 2);

	// enemy
	m_enemy = Enemy::create(Vec2(visibleSize.width - 200, 150));
	this->addChild(m_enemy, 3);

	// hero
	m_player = Hero::create(Vec2(visibleSize.width / 4, 100));
	this->addChild(m_player, 3);

	// AI 
	m_aimanager = AIManager::create(this);
	m_aimanager->setAI(m_enemy, m_player);

	// Åö×²¼ì²â
	m_contactListener = MyContactListener::create(this, m_player, m_enemy);

	// ÑªÌõ
	m_bloodBar_h = Sprite::create("Chapter06/AnimationScene/animation/background/1-new.png");
	m_bloodBar_h->setTag(10000);
	auto blood_bg_h = Sprite::create("Chapter06/AnimationScene/animation/background/1-new-f.png");
	m_bloodBar_h->setPosition(Vec2(m_bloodBar_h->getContentSize().width / 2 + 5, visibleSize.height - 50));
	blood_bg_h->setPosition(Vec2(m_bloodBar_h->getContentSize().width / 2 + 5, visibleSize.height - 50));

	this->addChild(blood_bg_h, 5);
	this->addChild(m_bloodBar_h, 5);

	m_bloodBar_e = Sprite::create("Chapter06/AnimationScene/animation/background/2-new.png");
	m_bloodBar_e->setTag(10001);
	auto blood_bg_e = Sprite::create("Chapter06/AnimationScene/animation/background/2-new-f.png");
	m_bloodBar_e->setPosition(Vec2(visibleSize.width - m_bloodBar_e->getContentSize().width / 2 - 5, visibleSize.height - 50));
	blood_bg_e->setPosition(Vec2(visibleSize.width - m_bloodBar_e->getContentSize().width / 2 - 5, visibleSize.height - 50));

	this->addChild(blood_bg_e, 5);
	this->addChild(m_bloodBar_e, 5);

	// update
	this->scheduleUpdate();

	return true;
}

Scene* AnimationScene::createScene()
{
	auto scene = Scene::create();
	auto layer = AnimationScene::create();
	scene->addChild(layer);
	return scene;
}

void AnimationScene::update(float delta)
{
	// ±³¾°ÔÆ¶¯»­
	Size visibleSize = Director::getInstance()->getVisibleSize();
	auto cloud_1 = (Sprite*)getChildByTag(112);
	auto cloud_2 = (Sprite*)getChildByTag(113);
	if (cloud_1->getPositionX() > -(3 / 2 * cloud_1->getContentSize().width - visibleSize.width))
	{
		cloud_1->setPositionX(cloud_1->getPositionX() - 1);
	}
	else
	{
		cloud_1->setPositionX(visibleSize.width / 2);
	}
	cloud_2->setPositionX(cloud_1->getPositionX() + cloud_1->getContentSize().width);

	// ¸üÐÂÑªÌõ
	float temp_e = float(m_enemy->getLife()) / m_enemy->getMaxLife();
	float x = 44 + (354 - 88 - 44) * (1 - temp_e);
	m_bloodBar_e->setTextureRect(Rect(x, 0, 354 - x, m_bloodBar_e->getContentSize().height));
	m_bloodBar_e->setPositionX(visibleSize.width - m_bloodBar_e->getContentSize().width / 2 - 5);

	float temp_h = float(m_player->getLife()) / m_player->getMaxLife();
	m_bloodBar_h->setTextureRect(Rect(0, 0, 88 + (354 - 88 - 44) * temp_h, m_bloodBar_h->getContentSize().height));
	m_bloodBar_h->setPositionX(m_bloodBar_h->getContentSize().width / 2 + 5);

	// ¿ØÖÆ½ÇÉ«ÒÆ¶¯
	if (m_joystick->getDirection() == Joystick_dir::_RIGHT)
	{
		m_player->play(MOVERIGHT);
	}
	else if (m_joystick->getDirection() == Joystick_dir::_LEFT)
	{
		m_player->play(MOVELEFT);
	}
	else if (m_joystick->getDirection() == Joystick_dir::_STOP)
	{
		m_player->play(STAND);
	}

	if (m_enemy->isDeath()) {
		Label* success = Label::createWithTTF("SUCCESS!", "fonts/Marker Felt.ttf", 72);

		{
			// position the label on the center of the screen
			success->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
			success->setName("success");
			// add the label as a child to this layer
			this->addChild(success, 1);
		}
	}
}

void AnimationScene::attackCallback(Ref* pSender)
{
	if (m_player->isAttack() == false)
		m_player->play(ATTACK);
	// m_enemy->play(ATTACK);
}

void AnimationScene::defendCallback(Ref* pSender)
{
	m_player->play(DEFEND);
}
void AnimationScene::menuReplayCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.", "Alert");
	return;
#endif
	if (m_enemy->isDeath()) {
		gamecnt++;
		scoreboard->setString("Successful Round: " + std::to_string(gamecnt));
	}
	Director::getInstance()->replaceScene(AnimationScene::createScene());
	Director::getInstance()->resume();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}