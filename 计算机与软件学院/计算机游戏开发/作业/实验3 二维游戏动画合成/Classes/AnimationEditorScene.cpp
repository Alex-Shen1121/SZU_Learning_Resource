#include "AnimationEditorScene.h"

AnimationEditorScene::AnimationEditorScene()
{
	m_startAnimation = false;
	m_armature = NULL;
}

AnimationEditorScene::~AnimationEditorScene()
{

}

bool AnimationEditorScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	// add a "close" icon to exit the progress. it's an autorelease object
	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(AnimationEditorScene::menuCloseCallback, this));

	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
		origin.y + closeItem->getContentSize().height/2));

	// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	// show tips
	auto tips = Label::createWithSystemFont("click \" animation \" to start , pause and resume the animation","Î¢ÈíÑÅºÚ",14);
	tips->setPosition(Vec2(230,visibleSize.height - 25));
	this->addChild(tips,5);

	// load ui
	auto layout_root = GUIReader::getInstance()->widgetFromJsonFile("Chapter06/Editor/NewUI_1.json");
	if (layout_root == NULL)
	{
		CCLOG("load ui failed!");
		return false;
	}

	// show ui
	this->addChild(layout_root);

	// add button click callback
	auto btn_test_ani = (Button *)layout_root->getChildByTag(5);
	btn_test_ani->addTouchEventListener(CC_CALLBACK_2(AnimationEditorScene::onClick,this));

	// load animation
	ArmatureDataManager::getInstance()->addArmatureFileInfo("Chapter06/Editor/test_ani.ExportJson");
	m_armature = Armature::create("test_ani");
	if (m_armature == NULL)
	{
		CCLOG("animation load failed!");
		return false;
	}
	m_armature->setPosition(visibleSize.width/2 + 100, visibleSize.height/2 - 100);
	this->addChild(m_armature);

	return true;
}

Scene* AnimationEditorScene::createScene()
{
	auto scene = Scene::create();
	auto layer = AnimationEditorScene::create();
	scene->addChild(layer);
	return scene;
}

// button test callback
void AnimationEditorScene::onClick(Ref *pSender, Widget::TouchEventType type)
{
	switch (type)
	{
		break;
	case cocos2d::ui::Widget::TouchEventType::ENDED:

		if (!m_startAnimation && (m_armature->getAnimation()->isPause() == true)) 
		{
			m_armature->getAnimation()->playWithIndex(0);  // start animation
		} else if (m_armature->getAnimation()->isPause() == true)  
		{
			m_armature->getAnimation()->resume();  // resume animation			
		} else
		{
			m_armature->getAnimation()->pause();  // stop animation 
		}

		m_startAnimation = true;
		break;
	default:
		break;
	}
}

void AnimationEditorScene::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
	return;
#endif

	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}