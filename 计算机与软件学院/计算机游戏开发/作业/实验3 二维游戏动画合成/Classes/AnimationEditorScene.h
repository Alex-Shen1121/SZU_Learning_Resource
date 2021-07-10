// 第六章例子1 -- 动画编辑器的应用

#ifndef __ANIMATION_EDITOR_SCENE_H__
#define __ANIMATION_EDITOR_SCENE_H__

// cocos2d
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
using namespace cocos2d;
using namespace cocostudio;
using namespace cocos2d::ui;

class AnimationEditorScene : public Layer
{
public:
	AnimationEditorScene();
	~AnimationEditorScene();
	CREATE_FUNC(AnimationEditorScene);
	virtual bool init();
	static Scene* createScene();

	// button callback
	void onClick(Ref *pSender, Widget::TouchEventType type);

	// close menu callback
	void menuCloseCallback(Ref* pSender);

private:

	// start animation first time
	bool m_startAnimation;

	// animation
	Armature *m_armature;
};

#endif // !__ANIMATION_EDITOR_SCENE_H__
