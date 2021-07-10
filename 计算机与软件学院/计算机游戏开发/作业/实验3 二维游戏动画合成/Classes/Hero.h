#ifndef __HERO_H__
#define __HERO_H__

#include "config_set.h"

class Hero : public Sprite
{
public:
	Hero();
	~Hero();

	static Hero* create(Vec2 position);

	void update(float delta);

	void play(State state);
	void hurt();  // ������

	void showBloodTips(int s);  // ��ʾ��Ѫ����
	void flyend(Label* label);  // ��Ѫ�����ƶ�����ʧ

	virtual bool init(Vec2 position);
	void onFrameEvent(cocostudio::Bone *bone, const std::string& evt, int originFrameIndex, int currentFrameIndex);  

	// set and get
	Armature* getArmature() { return m_armature; }
	
	bool isAttack() { return m_isAttack; }
	void setAttack(bool attack) { m_isAttack = attack; }

	int getLife() { return m_life; }
	void setLife(int life) { m_life = life; }

	bool isDeath() { return m_isdead; }

	int getMaxLife() { return m_max_life; }

private:
	Armature* m_armature;
	State m_state;
	bool m_isrunning;
	bool m_isdead;
	bool m_isAttack;  // �Ƿ����ڹ���
	bool m_ishurt;    // ����״̬
	bool m_defence;   // ������״̬
	int m_life;       // ����ֵ
	int m_max_life;   // �������ֵ
};

#endif