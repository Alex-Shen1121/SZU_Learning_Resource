#pragma once
#include "cocos2d.h"					//����ͷ�ļ�

using namespace cocos2d;				//ʹ��cocos2d�����ռ�

class MyFirstScene : public Layer		//�½�һ���࣬�̳в㣨Layer��
{
public:
    static Scene* createScene();		//MyFirstScene��������ʵ��

    virtual bool init();				//MyFirstScene��ĳ�ʼ��

    CREATE_FUNC(MyFirstScene);			//����MyFirstScene��Create����

    void EnterSecondScene(Ref* pSender);	//����һ���˵��ص�����������ʵ���˳�������ת
};