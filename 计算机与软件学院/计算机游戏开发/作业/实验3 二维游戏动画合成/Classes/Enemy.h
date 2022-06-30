#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "config_set.h"

class Enemy : public Sprite
{
public:
	Enemy();
	~Enemy();

	static Enemy* create(Vec2 position);

	void update(float delta);

	void play(State state); // ���Ŷ���
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
	State m_state;    // ���ﶯ��״̬
	bool m_isrunning; // �Ƿ������ܶ�
	bool m_isdead;    // �Ƿ�����
	bool m_isAttack;  // ����״̬

	bool m_ishurt;    // ����״̬

	int m_life;       // ����ֵ

	int m_max_life;   // �������ֵ
};

#endif