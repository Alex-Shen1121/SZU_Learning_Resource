#include "MazeScene.h"

USING_NS_CC;
int STAGE = 1;
Scene* MazeScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = MazeScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool MazeScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	m_map = nullptr;
	//Ѱ·���ָ��
	m_origin = nullptr;
	//Ѱ·�յ�ָ��
	m_destination = nullptr;
	//�ж��Ƿ�����ڵ�ͼ���ƶ�
	m_isReadyToMove = true;

	//�����Ļ�ߴ�
	m_visibleSize = Director::getInstance()->getVisibleSize();
	//�����ͼ�������õ��ʵ�λ��

	if (STAGE == 1) {
		auto tileMap = TMXTiledMap::create("Chapter11/superMaze.tmx");
		tileMap->setPosition(0, m_visibleSize.height - MAP_HEIGHT * UNIT);
		this->addChild(tileMap, 1);
		//��ȡ��ͼ�е���ͼ��
		m_mapLayer = tileMap->getLayer("mainLayer");
	}
	else if (STAGE == 2) {
		auto tileMap = TMXTiledMap::create("Chapter11/superMaze2.tmx");
		tileMap->setPosition(0, m_visibleSize.height - MAP_HEIGHT * UNIT);
		this->addChild(tileMap, 1);
		//��ȡ��ͼ�е���ͼ��
		m_mapLayer = tileMap->getLayer("mainLayer");
	}



	//��ʼ����ͼ����
	initMap();
	//����Ļ�׶�������ʾ��˸�Ĳ�����ʾ
	auto playTip = LabelTTF::create("Click Map To Put Treasure", "Arial", 40);
	playTip->setPosition(m_visibleSize.width / 2, 0.5 * (m_visibleSize.height - MAP_HEIGHT * UNIT));
	this->addChild(playTip, 1);
	auto blink = Blink::create(5, 10);
	playTip->runAction(blink);
	//Ԥ���ҵ��������ʾ����������Ϊ���ɼ�
	auto successTip = Label::createWithBMFont("fonts/futura-48.fnt", "Found Treasure!");
	successTip->setPosition(m_visibleSize.width / 2, m_visibleSize.height / 2);
	this->addChild(successTip, 2, TIP_TAG);
	successTip->setVisible(false);
	//�ڵ�ͼ������Ѱ������
	auto smileSprite = Sprite::create("Chapter11/smile.png");
	smileSprite->setPosition(0.5 * UNIT, m_visibleSize.height - 0.5 * UNIT);
	this->addChild(smileSprite, 3, SMILE_TAG);
	//Ԥ�ñ��侫�飬��������Ϊ���ɼ�
	auto boxSprite = Sprite::create("Chapter11/box.png");
	boxSprite->setPosition(m_visibleSize.width / 2, m_visibleSize.height / 2);
	boxSprite->setVisible(false);
	this->addChild(boxSprite, 3, BOX_TAG);
	//Ԥ�ý�ֹ����ͼ�꣬��������Ϊ���ɼ�
	auto forbidSprite = Sprite::create("Chapter11/forbid.png");
	forbidSprite->setPosition(m_visibleSize.width / 2, m_visibleSize.height / 2);
	forbidSprite->setVisible(false);
	this->addChild(forbidSprite, 4, FORBID_TAG);
	//��ӻ�ͼ�ڵ�
	m_draw = DrawNode::create();
	this->addChild(m_draw, 2, DRAW_TAG);
	//�����Ļ��������
	addTouchListener();
	addKeyPressedListener();
	//���ö�ʱ������
	this->scheduleUpdate();
	return true;
}


void MazeScene::update(float delta)
{
	auto smile = this->getChildByTag(SMILE_TAG);
	auto box = this->getChildByTag(BOX_TAG);
	//���Ц������ﵽ����λ��
	if (smile->getBoundingBox().intersectsRect(box->getBoundingBox()))
	{
		//���ر���
		box->setVisible(false);
		//����ͼ����ָ���ʼ״̬
		for (int i = 0; i < MAP_WIDTH; i++)
		{
			for (int j = 0; j < MAP_HEIGHT; j++)
			{
				if (m_map[i][j].status != NOT_ACCESS)
				{
					mapNode temp = { ACCESS, i, j, 0, 0, 0, nullptr };
					m_map[i][j] = temp;
				}
			}
		}
		//����ǰ��Ԫ��Ϊ���
		m_origin = m_destination;
		m_origin->status = ORIGIN;
		//������Ƶ�·��
		m_draw->clear();
		//�����ٴ��ƶ�
		m_isReadyToMove = true;
		//��ʾѰ·�ɹ��ı�ǩ��ʾ
		auto tip = this->getChildByTag(TIP_TAG);
		tip->setVisible(true);
	}
}

void MazeScene::initMap()
{
	srand((unsigned)time(NULL));
	//���ݵ�ͼ���߷�������ռ�
	m_map = new mapNode * [MAP_WIDTH];
	for (int n = 0; n < MAP_WIDTH; n++)
		m_map[n] = new mapNode[MAP_HEIGHT];
	//����ɨ���ͼ����ÿһ����Ԫ
	for (int i = 0; i < MAP_WIDTH; i++)
	{
		for (int j = 0; j < MAP_HEIGHT; j++)
		{
			//����ǰλ��Ϊǽ����Ƭ����Ϊ����ͨ��
			if (m_mapLayer->getTileGIDAt(Vec2(i, j)) == NOT_ACCESS_TILE)
			{
				mapNode temp = { NOT_ACCESS, i, j, 0, 0, 0, nullptr };
				m_map[i][j] = temp;
			}

			//��������Ϊ����ͨ��
			else
			{
				int randnum = rand() % (MAP_WIDTH * MAP_HEIGHT) + 1;
				mapNode temp = { ACCESS, i, j, 0, 0, 0, nullptr };
				m_map[i][j] = temp;

				if (randnum < MAP_WIDTH * MAP_HEIGHT / 50) {
					m_mapLayer->setTileGID(341, Vec2(i, j));
					m_map[i][j].isDangerous = true;
				}

			}
		}
	}
	//��ʼ�����Ϊ��0��0����Ԫ
	m_map[0][0].status = ORIGIN;
	m_origin = &m_map[0][0];
}

int MazeScene::aStar(mapNode** map, mapNode* origin, mapNode* destination)
{
	openList* open = new openList;
	open->next = nullptr;
	open->openNode = origin;
	closedList* close = new closedList;
	close->next = nullptr;
	close->closedNode = nullptr;
	//ѭ������8����������ڽڵ�
	while (checkNeighboringNodes(map, open, open->openNode, destination))
	{
		//��OPEN����ѡȡ�ڵ����CLOSED��
		insertNodeToClosedList(close, open);
		//��OPEN��Ϊ�գ�����Ѱ·ʧ��
		if (open == nullptr)
		{
			//��Ļ������ʾѰ·ʧ�ܵ���ʾ
			auto failedTip = Label::createWithBMFont("fonts/futura-48.fnt", "No Way!");
			failedTip->setPosition(m_visibleSize.width / 2, m_visibleSize.height / 2);
			this->addChild(failedTip, 2, TIP_TAG);
			break;
		}
		//���յ���OPEN���У�����Ѱ·�ɹ�
		if (open->openNode->status == DESTINATION)
		{
			mapNode* tempNode = open->openNode;
			//����moveOnPath�����������ƾ�����·�����ƶ�
			moveOnPath(tempNode);
			break;
		}
	}
	return 0;
}

void MazeScene::moveOnPath(mapNode* tempNode)
{
	string next;
	//�����洢·������Ľṹ��
	struct pathCoordinate { int x; int y; bool isDangerous; };
	//����·������ṹ������
	pathCoordinate* path = new pathCoordinate[MAP_WIDTH * MAP_HEIGHT];
	//���ø��ڵ���Ϣ����洢·������
	int loopNum = 0;
	while (tempNode != nullptr)
	{
		path[loopNum].x = tempNode->xCoordinate;
		path[loopNum].y = tempNode->yCoordinate;
		path[loopNum].isDangerous = tempNode->isDangerous;
		loopNum++;
		tempNode = tempNode->parent;
	}
	//��Ц������������Ϊ�����߶����
	auto smile = this->getChildByTag(SMILE_TAG);
	int fromX = smile->getPositionX();
	int fromY = smile->getPositionY();
	//�������������洢��������
	Vector<FiniteTimeAction*> actionVector;
	//�ӽṹ������β����ʼɨ��
	for (int j = loopNum - 2; j >= 0; j--)
	{
		//����ͼ��������ת��Ϊ��Ļʵ������
		int realX = (path[j].x + 0.5) * UNIT;
		int realY = m_visibleSize.height - (path[j].y + 0.5) * UNIT;
		//���ƴ���㵽��һ����ͼ��Ԫ���߶�
		m_draw->drawLine(Vec2(fromX, fromY), Vec2(realX, realY), Color4F(1.0, 1.0, 1.0, 1.0));
		if (path[j].isDangerous) {
			next = "dangerous";
			break;
		}
		if (path[j].x == 3 && path[j].y == 0 && STAGE == 1) {
			next = "next_stage";
			break;
		}
		else if (path[j].x == 15 && path[j].y == 2 && STAGE == 2) {
			next = "front_stage";
			break;
		}
		//�����ƶ����������붯������
		auto moveAction = MoveTo::create(0.2, Vec2(realX, realY));
		actionVector.pushBack(moveAction);
		//����ǰ���걣��Ϊ��һ�λ��Ƶ����
		fromX = realX;
		fromY = realY;
	}
	//������������
	auto actionSequence = Sequence::create(actionVector);
	//Ц������ִ���ƶ���������
	smile->runAction(Sequence::create(actionSequence, CallFunc::create(CC_CALLBACK_0(MazeScene::Next, this, next)), NULL));
}

void MazeScene::Next(string s) {
	if (s == "dangerous") {
		//��Ļ������ʾʧ�ܵ���ʾ
		auto failedTip = Label::createWithBMFont("fonts/futura-48.fnt", "Dangerous!You're Dead!");
		failedTip->setPosition(m_visibleSize.width / 2, m_visibleSize.height / 2);
		this->addChild(failedTip, 2, TIP_TAG);
	}
	else if (s == "next_stage") {
		STAGE++;
		Director::getInstance()->replaceScene(MazeScene::createScene());
	}
	else if (s == "front_stage") {
		STAGE--;
		Director::getInstance()->replaceScene(MazeScene::createScene());
	}
}

void MazeScene::addTouchListener()
{
	//��ü�����
	auto listener = EventListenerTouchOneByOne::create();
	//Ϊ������ʼ�ʹ����������ûص�����
	listener->onTouchBegan = CC_CALLBACK_2(MazeScene::onTouchBegan, this);
	listener->onTouchEnded = CC_CALLBACK_2(MazeScene::onTouchEnded, this);
	//���ô����������ȼ�
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}

void MazeScene::addKeyPressedListener()
{
	auto listener = EventListenerKeyboard::create();
	listener->onKeyPressed = CC_CALLBACK_2(MazeScene::onKeyPressedBegan, this);
	listener->onKeyReleased = CC_CALLBACK_2(MazeScene::onKeyPressedEnded, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

}

bool MazeScene::onTouchBegan(Touch* touch, Event* unused_event)
{
	//������������ת��Ϊ��ͼ��������
	int x = (int)(touch->getLocation().x / UNIT);
	int y = (int)((m_visibleSize.height - touch->getLocation().y) / UNIT);
	//���õ�ͼ��ԪΪǽ��򳬳���ͼ��Χ�����ý�ֹͼ��
	if (m_map[x][y].status == NOT_ACCESS || y >= MAP_HEIGHT || (m_destination && x == m_destination->xCoordinate && y == m_destination->yCoordinate))
	{
		auto forbid = this->getChildByTag(FORBID_TAG);
		forbid->setPosition(0.5 * UNIT + x * UNIT, m_visibleSize.height - 0.5 * UNIT - y * UNIT);
		forbid->setVisible(true);
		return true;
	}
	else
	{
		//���õ�ͼ��Ԫ�ɵ����������ƶ�
		if (m_isReadyToMove)
		{
			//Ϊ�����յ�ǰ���������ƶ�
			m_isReadyToMove = false;
			//����ǰ��ͼ��Ԫ����Ϊ�յ�
			m_map[x][y].status = DESTINATION;
			m_destination = &m_map[x][y];
			if (x != 3 && y != 0) {
				//�ڵ�ǰ��ͼ��Ԫ��ӱ��侫��
				auto box = this->getChildByTag(BOX_TAG);
				box->setPosition(0.5 * UNIT + x * UNIT, m_visibleSize.height - 0.5 * UNIT - y * UNIT);
				box->setVisible(true);
			}
			//����A*�㷨��ʼѰ·
			aStar(m_map, m_origin, m_destination);
			//����һ��Ѱ·�ɹ�����ʾ����
			auto tip = this->getChildByTag(TIP_TAG);
			tip->setVisible(false);
			return false;
		}
		//���������ƶ����ڸõ�ͼ��Ԫ���ý�ֹͼ��
		else
		{
			auto forbid = this->getChildByTag(FORBID_TAG);
			forbid->setPosition(0.5 * UNIT + x * UNIT, m_visibleSize.height - 0.5 * UNIT - y * UNIT);
			forbid->setVisible(true);
			return true;
		}
	}
}

void MazeScene::onTouchEnded(Touch* touch, Event* unused_event)
{
	//���ؽ�ֹͼ��
	auto forbid = this->getChildByTag(FORBID_TAG);
	forbid->setVisible(false);
	//����Ѱ·�ɹ���ʾ
	auto tip = this->getChildByTag(TIP_TAG);
	tip->setVisible(false);
}

bool MazeScene::onKeyPressedBegan(EventKeyboard::KeyCode keycode, Event* unused_event)
{
	if (keycode == EventKeyboard::KeyCode::KEY_R) {
		Director::getInstance()->replaceScene(MazeScene::createScene());
	};
	return true;
}

void MazeScene::onKeyPressedEnded(EventKeyboard::KeyCode keycode, Event* unused_event)
{
	return;
}
