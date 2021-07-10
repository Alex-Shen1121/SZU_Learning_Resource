#ifndef __BULLET_H__
#define __BULLET_H__

#include "BaseObject.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;

#define BULLET_UP      1	  // BULLET����״̬
#define BULLET_DOWN    2      // BULLET����״̬
#define BULLET_LEFT    3      // BULLET����״̬
#define BULLET_RIGHT   4      // BULLET����״̬

class Bullet : public BaseObject
{
public:
	Bullet();
	~Bullet();
	static Bullet* create(Vec2 position, float speed, int dir, int kind, int id, int life);

	void blast();

private:
	virtual bool init(Vec2 position, float speed, int dir, int kind, int id, int life);
	void update(float delta);

private:
	Sprite*     m_sprite;       // ͼƬ����
	Texture2D*  m_texture;      // ����
};

#endif
