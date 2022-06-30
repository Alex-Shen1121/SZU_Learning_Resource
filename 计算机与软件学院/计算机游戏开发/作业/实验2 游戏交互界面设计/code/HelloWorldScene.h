#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "Joystick.h"

class HelloWorld : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
	void menuReplayCallback(Ref* pSender);
	void addBall1(float dt);
	void addBall2(float dt);
	void addBall3(float dt);
	void removeBall(Sprite* ball);
	
	void update(float dt);
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
private:
	Sprite* bean;
	Size visibleSize;
	Joystick* m_joystick;
	Vector<Sprite*> ballVector;
	int score = 0;
	Label* scoreboard = Label::createWithTTF("Score Board: "+std::to_string(score), "fonts/Marker Felt.ttf", 48);

};

#endif // __HELLOWORLD_SCENE_H__
