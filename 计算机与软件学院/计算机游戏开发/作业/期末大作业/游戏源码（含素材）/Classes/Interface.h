#pragma once
#include "cocos2d.h"
#include "BattleScene.h"
#include "cocostudio/CocoStudio.h"
#include "SimpleAudioEngine.h"
#include "ui/CocosGUI.h"
using namespace cocos2d;
using namespace ui;
using namespace CocosDenshion;

class Interface : public Scene
{
public:
	Interface();
	~Interface();
	static Interface* create();
	bool init();
	void start();
	static void pauseScene(cocos2d::Ref* pSender); //���ڰ�����ͣ����
	static void pausescene(); //����ʤ��/ʧ�ܺ���ͣ����
	static void resumeScene(cocos2d::Ref* pSender);
	void gameinterface();
	void quit();
	void showhelp();
	void return_mainscene();
	void showchoose();
	void choosefirst();
	void choosesecond();
	void choosethird();
	void showranking_List();
	void game_return();
	void replay();
	void updateranking_List();
	void successOrFail();
	void game_next();
	void playmusic();
private:
	static BattleScene* gamescene;
	Label* enemylife_score;
	Label* palyerlife_score;
	Label* score_sum;
	Label* FirstScore;
	Label* SecondScore;
	Label* ThirdScore;
	void update(float delta);
	bool flag;//�ж��Ƿ��һ�ν���Ϸ
	bool Wflag;//�ж��Ƿ�����Ϸ����
	bool Mflag;//���Ƴɹ�ʧ����Чѭ������
	bool ismusic;//�ж����ֿ����
};