#include "Interface.h"

BattleScene* Interface::gamescene = nullptr;

Interface::Interface()
{
}

Interface::~Interface()
{
}

Interface* Interface::create()
{
	Interface* pRet = new(std::nothrow)Interface();
	if (pRet && pRet->init())
	{
		pRet->autorelease();
		return pRet;
	}
	else
	{
		delete pRet;
		pRet = NULL;
		return NULL;
	}
}

bool Interface::init()
{	
	flag = 0;
	Wflag = 0;
	Mflag = 0;
	ismusic = 1;
	char str[20] = "";

	//声音预加载
	SimpleAudioEngine::getInstance()->preloadEffect("music/fail.mp3");
	SimpleAudioEngine::getInstance()->preloadEffect("music/win.wav");
	SimpleAudioEngine::getInstance()->playBackgroundMusic("music/background.wav");
	SimpleAudioEngine::getInstance()->preloadEffect("music/explode.wav");
	SimpleAudioEngine::getInstance()->preloadEffect("music/shoot.mp3");
	SimpleAudioEngine::getInstance()->preloadEffect("music/hitWall.wav");

	//粒子特效
	ParticleSystemQuad* smoke = ParticleSystemQuad::create("particle/myparticle.plist");
	smoke->setScale(2.0);
	smoke->setPosition(Vec2(0, 336));
	smoke->setTag(500);
	smoke->setVisible(false);
	this->addChild(smoke, 100);

	//游戏主界面
	auto main_UI = GUIReader::getInstance()->widgetFromJsonFile("002_1/002_1.ExportJson");
	addChild(main_UI);
	main_UI->setTag(1001);

	auto btn1_main_UI = (Button*)main_UI->getChildByTag(2)->getChildByTag(3)->getChildByTag(4);
	btn1_main_UI->addClickEventListener(CC_CALLBACK_0(Interface::start, this));

	auto btn2_main_UI = (Button*)main_UI->getChildByTag(2)->getChildByTag(5)->getChildByTag(6);
	btn2_main_UI->addClickEventListener(CC_CALLBACK_0(Interface::showchoose, this));

	auto btn3_main_UI = (Button*)main_UI->getChildByTag(2)->getChildByTag(9)->getChildByTag(10);
	btn3_main_UI->addClickEventListener(CC_CALLBACK_0(Interface::showhelp, this));

	auto btn4_main_UI = (Button*)main_UI->getChildByTag(2)->getChildByTag(11)->getChildByTag(12);
	btn4_main_UI->addClickEventListener(CC_CALLBACK_0(Interface::quit, this));

	auto btn5_main_UI = (Button*)main_UI->getChildByTag(2)->getChildByTag(7)->getChildByTag(8);
	btn5_main_UI->addClickEventListener(CC_CALLBACK_0(Interface::showranking_List, this));

	//帮助界面
	auto help_UI = GUIReader::getInstance()->widgetFromJsonFile("003_1/003_1.ExportJson");
	addChild(help_UI);
	help_UI->setTag(1002);
	help_UI->setVisible(false);

	auto btn_help_UI = (Button*)help_UI->getChildByTag(2)->getChildByTag(3)->getChildByTag(7)->getChildByTag(8);
	btn_help_UI->addClickEventListener(CC_CALLBACK_0(Interface::return_mainscene, this));

	//排行榜界面
	auto list_UI = GUIReader::getInstance()->widgetFromJsonFile("004_1/004_1.ExportJson");
	addChild(list_UI);
	list_UI->setTag(1004);
	list_UI->setVisible(false);

	auto btn_list_UI = (Button*)list_UI->getChildByTag(2)->getChildByTag(3)->getChildByTag(7)->getChildByTag(8);
	btn_list_UI->addClickEventListener(CC_CALLBACK_0(Interface::return_mainscene, this));

	itoa(first_score, str, 10);
	FirstScore = Label::createWithTTF(str, "fonts/arial.ttf", 24);
	FirstScore->setPosition(Vec2(550, 475));
	FirstScore->setTag(300);
	FirstScore->setVisible(false);
	this->addChild(FirstScore, 1);

	itoa(second_score, str, 10);
	SecondScore = Label::createWithTTF(str, "fonts/arial.ttf", 24);
	SecondScore->setPosition(Vec2(550, 370));
	SecondScore->setTag(301);
	SecondScore->setVisible(false);
	this->addChild(SecondScore, 1);

	itoa(third_score, str, 10);
	ThirdScore = Label::createWithTTF(str, "fonts/arial.ttf", 24);
	ThirdScore->setPosition(Vec2(550, 255));
	ThirdScore->setTag(302);
	ThirdScore->setVisible(false);
	this->addChild(ThirdScore, 1);

	//选择关卡界面
	auto choose_UI = GUIReader::getInstance()->widgetFromJsonFile("005_1/005_1.ExportJson");
	addChild(choose_UI);
	choose_UI->setTag(1003);
	choose_UI->setVisible(false);

	auto btn1_choose_UI = (Button*)choose_UI->getChildByTag(2)->getChildByTag(3)->getChildByTag(7);
	btn1_choose_UI->addClickEventListener(CC_CALLBACK_0(Interface::choosefirst, this));

	auto btn2_choose_UI = (Button*)choose_UI->getChildByTag(2)->getChildByTag(4)->getChildByTag(8);
	btn2_choose_UI->addClickEventListener(CC_CALLBACK_0(Interface::choosesecond, this));

	auto btn3_choose_UI = (Button*)choose_UI->getChildByTag(2)->getChildByTag(5)->getChildByTag(9);
	btn3_choose_UI->addClickEventListener(CC_CALLBACK_0(Interface::choosethird, this));

	auto btn4_choose_UI = (Button*)choose_UI->getChildByTag(2)->getChildByTag(6);
	btn4_choose_UI->addClickEventListener(CC_CALLBACK_0(Interface::return_mainscene, this));

	return true;
}

void Interface::update(float delta)
{
	successOrFail();//判断输赢

	//更新所剩敌人数
	char str[20] = "";
	itoa(gamescene->enemy_life + gamescene->enemy_left, str, 10);
	enemylife_score->setString(str);

	//更新玩家剩余生命数
	itoa(gamescene->player_life, str, 10);
	palyerlife_score->setString(str);

	//更新得分
	itoa(player_score, str, 10);
	score_sum->setString(str);

}

void Interface::gameinterface()
{
	flag = 1;
	char str[20] = "";

	//所剩敌人数
	auto enemylife = Label::createWithTTF("Enemy:", "fonts/arial.ttf", 24);
	enemylife->setPosition(Vec2(1020, 630));
	enemylife->setTag(100);
	this->addChild(enemylife, 1);

	itoa(gamescene->enemy_life, str, 10);
	enemylife_score = Label::createWithTTF(str, "fonts/arial.ttf", 24);
	enemylife_score->setPosition(Vec2(1020, 580));
	enemylife_score->setTag(101);
	this->addChild(enemylife_score, 1);

	//玩家生命数
	auto palyerlife = Label::createWithTTF("Life:", "fonts/arial.ttf", 24);
	palyerlife->setPosition(Vec2(1020, 530));
	palyerlife->setTag(102);
	this->addChild(palyerlife, 1);

	itoa(gamescene->player_life, str, 10);
	palyerlife_score = Label::createWithTTF(str, "fonts/arial.ttf", 24);
	palyerlife_score->setPosition(Vec2(1020, 480));
	palyerlife_score->setTag(103);
	this->addChild(palyerlife_score, 1);

	//分数
	auto score = Label::createWithTTF("Your Score", "fonts/arial.ttf", 24);
	score->setPosition(Vec2(1020, 430));
	score->setTag(104);
	this->addChild(score, 1);

	itoa(player_score, str, 10);
	score_sum = Label::createWithTTF(str, "fonts/arial.ttf", 24);
	score_sum->setPosition(Vec2(1020, 380));
	score_sum->setTag(109);
	this->addChild(score_sum, 1);

	//重开按钮
	auto replay = Label::createWithTTF("Replay", "fonts/arial.ttf", 24);
	auto replayItem = MenuItemLabel::create(replay, CC_CALLBACK_0(Interface::replay, this));
	replayItem->setPosition(Vec2(470, -225));
	auto menu3 = Menu::create(replayItem, NULL);
	this->addChild(menu3, 1);
	menu3->setTag(108);

	//暂停按钮
	auto pause = Label::createWithTTF("Pause", "fonts/arial.ttf", 24);
	auto pauseItem = MenuItemLabel::create(pause, CC_CALLBACK_0(Interface::pauseScene, this));
	pauseItem->setPosition(Vec2(470, -75));
	auto menu2 = Menu::create(pauseItem, NULL);
	this->addChild(menu2, 1);
	menu2->setTag(105);

	//恢复按钮
	auto resume = Label::createWithTTF("Continue", "fonts/arial.ttf", 24);
	auto resumeItem = MenuItemLabel::create(resume, CC_CALLBACK_0(Interface::resumeScene, this));
	resumeItem->setPosition(Vec2(470, -150));
	auto menu1 = Menu::create(resumeItem, NULL);
	this->addChild(menu1, 1);
	menu1->setTag(106);

	//返回按钮
	auto return_main = Label::createWithTTF("Return", "fonts/arial.ttf", 24);
	auto returnItem = MenuItemLabel::create(return_main, CC_CALLBACK_0(Interface::game_return, this));
	returnItem->setPosition(Vec2(470, -300));
	auto menu = Menu::create(returnItem, NULL);
	this->addChild(menu, 1);
	menu->setTag(107);

	//音乐开关按钮
	auto music = Label::createWithTTF("Musicset", "fonts/arial.ttf", 24);
	auto musicItem = MenuItemLabel::create(music, CC_CALLBACK_0(Interface::playmusic, this));
	musicItem->setPosition(Vec2(470, 0));
	auto menu8 = Menu::create(musicItem, NULL);
	this->addChild(menu8, 1);
	menu8->setTag(110);

	//成功提示
	auto successflag = Label::createWithTTF("You Win!", "fonts/arial.ttf", 24);
	successflag->setScale(3);
	successflag->setColor(Color3B(255, 255, 0));
	successflag->setPosition(Vec2(480, 400));
	successflag->setTag(200);
	successflag->setVisible(false);
	this->addChild(successflag, 20);

	auto success_return_main = Label::createWithTTF("Return", "fonts/arial.ttf", 24);
	auto successreturnItem = MenuItemLabel::create(success_return_main, CC_CALLBACK_0(Interface::game_return, this));
	successreturnItem->setPosition(Vec2(50, -50));
	successreturnItem->setScale(2);
	successreturnItem->setColor(Color3B(255, 255, 0));
	auto menu6 = Menu::create(successreturnItem, NULL);
	this->addChild(menu6, 1);
	menu6->setTag(204);
	menu6->setVisible(false);

	auto success_next = Label::createWithTTF("Next", "fonts/arial.ttf", 24);
	auto nextItem = MenuItemLabel::create(success_next, CC_CALLBACK_0(Interface::game_next, this));
	nextItem->setPosition(Vec2(-170, -50));
	nextItem->setScale(2);
	nextItem->setColor(Color3B(255, 255, 0));
	auto menu7 = Menu::create(nextItem, NULL);
	this->addChild(menu7, 1);
	menu7->setTag(205);
	menu7->setVisible(false);

	//失败提示
	auto failflag1 = Label::createWithTTF("You Fail!", "fonts/arial.ttf", 24);
	failflag1->setScale(3);
	failflag1->setColor(Color3B(255, 0, 0));
	failflag1->setPosition(Vec2(480, 400));
	failflag1->setTag(201);
	failflag1->setVisible(false);
	this->addChild(failflag1, 20);
	
	auto fail_replay = Label::createWithTTF("Replay", "fonts/arial.ttf", 24);
	auto failreplayItem = MenuItemLabel::create(fail_replay, CC_CALLBACK_0(Interface::replay, this));
	failreplayItem->setPosition(Vec2(-170, -50));
	failreplayItem->setScale(2);
	failreplayItem->setColor(Color3B(255, 0, 0));
	auto menu4 = Menu::create(failreplayItem, NULL);
	this->addChild(menu4, 1);
	menu4->setTag(202);
	menu4->setVisible(false);

	auto fail_return_main = Label::createWithTTF("Return", "fonts/arial.ttf", 24);
	auto failreturnItem = MenuItemLabel::create(fail_return_main, CC_CALLBACK_0(Interface::game_return, this));
	failreturnItem->setPosition(Vec2(50, -50));
	failreturnItem->setScale(2);
	failreturnItem->setColor(Color3B(255, 0, 0));
	auto menu5 = Menu::create(failreturnItem, NULL);
	this->addChild(menu5, 1);
	menu5->setTag(203);
	menu5->setVisible(false);
}

//更新排行榜
void Interface::updateranking_List()
{
	if (player_score > first_score)
	{		
		third_score = second_score;
		second_score = first_score;
		first_score = player_score;
	}
	else if (player_score > second_score&&player_score < first_score)
	{
		third_score = second_score;
		second_score = player_score;
	}
	else if (player_score > third_score&&player_score < second_score)
	{
		third_score = player_score;
	}
	char str[20] = "";
	itoa(first_score, str, 10);
	FirstScore->setString(str);

	itoa(second_score, str, 10);
	SecondScore->setString(str);

	itoa(third_score, str, 10);
	ThirdScore->setString(str);
}

//重开函数
void Interface::replay()
{
	Mflag = 0;
	this->getChildByTag(201)->setVisible(false);
	this->getChildByTag(202)->setVisible(false);
	this->getChildByTag(203)->setVisible(false);
	updateranking_List();
	player_score = 0;
	gamescene->removeFromParent();
	gamescene = BattleScene::create(level);
	this->getParent()->addChild(gamescene);

}

//进入下一关
void Interface::game_next()
{
	Mflag = 0;
	if (level < 3)
	{
		level++;
		this->getChildByTag(200)->setVisible(false);
		this->getChildByTag(204)->setVisible(false);
		this->getChildByTag(205)->setVisible(false);
		gamescene->removeFromParent();
		gamescene = BattleScene::create(level);
		this->getParent()->addChild(gamescene);
	}
	else
		game_return();
}

//返回主界面
void Interface::return_mainscene()
{
	this->getChildByTag(300)->setVisible(false);
	this->getChildByTag(301)->setVisible(false);
	this->getChildByTag(302)->setVisible(false);
	this->getChildByTag(1004)->setVisible(false);
	this->getChildByTag(1003)->setVisible(false);
	this->getChildByTag(1002)->setVisible(false);
	this->getChildByTag(1001)->setVisible(true);
}

//返回
void Interface::game_return()
{
	level = 1;
	updateranking_List();
	player_score = 0;
	Wflag = 0;
	for (int i = 100; i < 111; i++)
		this->getChildByTag(i)->setVisible(false);	
	this->getChildByTag(200)->setVisible(false);
	this->getChildByTag(201)->setVisible(false);
	this->getChildByTag(202)->setVisible(false);
	this->getChildByTag(203)->setVisible(false);
	this->getChildByTag(204)->setVisible(false);
	this->getChildByTag(205)->setVisible(false);
	this->getChildByTag(500)->setVisible(false);
	this->getChildByTag(1001)->setVisible(true);	
	gamescene->removeFromParent();
}

//显示排行榜界面
void Interface::showranking_List()
{
	this->getChildByTag(300)->setVisible(true);
	this->getChildByTag(301)->setVisible(true);
	this->getChildByTag(302)->setVisible(true);
	this->getChildByTag(1001)->setVisible(false);
	this->getChildByTag(1004)->setVisible(true);
}

//显示选择关卡界面
void Interface::showchoose()
{
	this->getChildByTag(1001)->setVisible(false);
	this->getChildByTag(1003)->setVisible(true);
}

//选择第一关
void Interface::choosefirst()
{
	Mflag = 0;
	level = 1;
	this->getChildByTag(1003)->setVisible(false);
	this->getChildByTag(500)->setVisible(true);
	gamescene = BattleScene::create(level);
	Wflag = 1;
	this->getParent()->addChild(gamescene);
	if (flag == 0)
		gameinterface();
	else
	{
		for (int i = 100; i < 111; i++)
			this->getChildByTag(i)->setVisible(true);
	}
	this->scheduleUpdate();
}

//选择第二关
void Interface::choosesecond()
{
	Mflag = 0;
	level = 2;
	this->getChildByTag(1003)->setVisible(false);
	this->getChildByTag(500)->setVisible(true);
	gamescene = BattleScene::create(level);
	Wflag = 1;
	this->getParent()->addChild(gamescene);
	if (flag == 0)
		gameinterface();
	else
	{
		for (int i = 100; i < 111; i++)
			this->getChildByTag(i)->setVisible(true);
	}
	this->scheduleUpdate();
}

//选择第三关
void Interface::choosethird()
{
	Mflag = 0;
	level = 3;
	this->getChildByTag(1003)->setVisible(false);
	this->getChildByTag(500)->setVisible(true);
	gamescene = BattleScene::create(level);
	Wflag = 1;
	this->getParent()->addChild(gamescene);
	if (flag == 0)
		gameinterface();
	else
	{
		for (int i = 100; i < 111; i++)
			this->getChildByTag(i)->setVisible(true);
	}
	this->scheduleUpdate();
}

//显示帮助界面
void Interface::showhelp()
{
	this->getChildByTag(1001)->setVisible(false);
	this->getChildByTag(1002)->setVisible(true);
}

//退出游戏
void Interface::quit()
{
	Director::getInstance()->end();
}

//开始游戏
void Interface::start()
{
	Mflag = 0;
	this->getChildByTag(1001)->setVisible(false);
	this->getChildByTag(500)->setVisible(true);
	gamescene = BattleScene::create(level);
	this->getParent()->addChild(gamescene);
	if (flag == 0)
		gameinterface();
	else
	{
		for (int i = 100; i < 111; i++)
			this->getChildByTag(i)->setVisible(true);
	}
	Wflag = 1;
	this->scheduleUpdate();
}

//暂停
void Interface::pauseScene(Ref* pSender)
{
	auto vector = gamescene->getChildren();
	for (auto i = vector.begin(); i != vector.end(); ++i)
	{
		Node *node = *i;
		auto vector_ = node->getChildren();
		for (auto j = vector_.begin(); j != vector_.end(); ++j)
		{
			(*j)->pause();
		}
		(*i)->pause();
	}
	gamescene->pause();
}

void Interface::pausescene()
{
	std::stack<Node*> node_stack;
	node_stack.push(gamescene);
	while(!node_stack.empty())
	{
		Node* node = node_stack.top();
		node_stack.pop();
		auto vector = node->getChildren();
		for (auto i = vector.begin(); i != vector.end(); ++i)
			node_stack.push((*i));
		node->pause();
	}
}

//恢复
void Interface::resumeScene(Ref* pSender)
{
	std::stack<Node*> node_stack;
	node_stack.push(gamescene);
	while(!node_stack.empty())
	{
		Node* node = node_stack.top();
		node_stack.pop();
		auto vector = node->getChildren();
		for (auto i = vector.begin(); i != vector.end(); ++i)
			node_stack.push((*i));
		node->resume();
	}
}

//成败判定
void Interface::successOrFail()
{
	if ((gamescene->player_life <= 0 || gamescene->guard_life <= 0) && Wflag)
	{
		pausescene();
		this->getChildByTag(201)->setVisible(true);
		this->getChildByTag(202)->setVisible(true);
		this->getChildByTag(203)->setVisible(true);
		if (Mflag == 0)
		{
			SimpleAudioEngine::getInstance()->playEffect("music/fail.mp3");
			Mflag = 1;
		}
	}
	else if ((gamescene->enemy_left + gamescene->enemy_life )<= 0 && Wflag)
	{
		pausescene();
		this->getChildByTag(200)->setVisible(true);
		this->getChildByTag(204)->setVisible(true);
		this->getChildByTag(205)->setVisible(true);
		if (Mflag == 0)
		{
			SimpleAudioEngine::getInstance()->playEffect("music/win.wav");
			Mflag = 1;
		}
	}
}

//音乐开关
void Interface::playmusic()
{
	if (ismusic == 0)
	{
		SimpleAudioEngine::getInstance()->playBackgroundMusic("music/background.wav");
		ismusic = 1;
	}
	else
	{
		SimpleAudioEngine::getInstance()->stopBackgroundMusic();
		ismusic = 0;
	}
}


