#include "ThirdGameScene.h"
#include "MyBodyParser.h"

USING_NS_CC;
int posX = 0;


Scene* ThirdGameScene::createScene()
{
    //PhysicsWorld
    auto scene = Scene::createWithPhysics();
    //scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);  //Quand activée cette comande rend les bords des objets rouge

    auto layer = ThirdGameScene::create();
    layer->SetPhysicsWorld(scene->getPhysicsWorld());
    scene->addChild(layer);


    return scene;
}

static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

bool ThirdGameScene::init()
{
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();


    //Background
    auto BSprite = Sprite::create("Background1.png");
    BSprite->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 2) + origin.y));
    this->addChild(BSprite);



    //Go back
    auto menu_item_1 = MenuItemImage::create("GoBack.png", "GoBack.png", CC_CALLBACK_1(ThirdGameScene::GoBack, this));
    menu_item_1->setPosition(Point(visibleSize.width / 10, (visibleSize.height / 10) * 9));
    auto* menu = Menu::create(menu_item_1, NULL);
    menu->setPosition(Point(0, 0));
    this->addChild(menu);



    //Screen Boundary
    auto edgeBody = PhysicsBody::createEdgeBox(visibleSize, PhysicsMaterial(0, 0, 0) , 200);
    auto edgeNode = Node::create();
    edgeNode->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 3 + origin.y + 90));
    edgeNode->setPhysicsBody(edgeBody);
    this->addChild(edgeNode);



    //limitBody
    auto sprite2 = Sprite::create("Blimit.png");
    sprite2->setPosition(Point(visibleSize.width / 2 + origin.x, origin.y + 37));
    sprite2->setTag(20);
    auto spriteBody2 = PhysicsBody::createBox(sprite2->getContentSize(), PhysicsMaterial(0, 1, 0));
    spriteBody2->setContactTestBitmask(0xFFFFFFFF);
    spriteBody2->setDynamic(false);
    sprite2->setPhysicsBody(spriteBody2);
    this->addChild(sprite2);


   
    //Block1
    auto B1 = Sprite::create("block1.png");
    B1->setPosition(190, 636);
    B1->setAnchorPoint(Vec2(0.0, 0.0));
    auto B1Body = PhysicsBody::createBox(B1->getContentSize(), PhysicsMaterial(0, 0, 0));
    //collision
    B1Body->setContactTestBitmask(0xFFFFFFFF);
    B1Body->setDynamic(false); 
    B1->setPhysicsBody(B1Body);
    this->addChild(B1);

    //Block2
    auto B2 = Sprite::create("block1.png");
    B2->setPosition(300, 636);
    B2->setAnchorPoint(Vec2(0.0, 0.0));
    auto B2Body = PhysicsBody::createBox(B2->getContentSize(), PhysicsMaterial(0, 0, 0));
    //collision
    B2Body->setContactTestBitmask(0xFFFFFFFF);
    B2Body->setDynamic(false); 
    B2->setPhysicsBody(B2Body);
    this->addChild(B2);

    //Block3
    auto B3 = Sprite::create("block1.png");
    B3->setPosition(410, 636);
    B3->setAnchorPoint(Vec2(0.0, 0.0));
    auto B3Body = PhysicsBody::createBox(B3->getContentSize(), PhysicsMaterial(0, 0, 0));
    //collision
    B3Body->setContactTestBitmask(0xFFFFFFFF);
    B3Body->setDynamic(false); 
    B3->setPhysicsBody(B3Body);
    this->addChild(B3);

    //Block4
    auto B4 = Sprite::create("block1.png");
    B4->setPosition(520, 636);
    B4->setAnchorPoint(Vec2(0.0, 0.0));
    auto B4Body = PhysicsBody::createBox(B4->getContentSize(), PhysicsMaterial(0, 0, 0));
    //collision
    B4Body->setContactTestBitmask(0xFFFFFFFF);
    B4Body->setDynamic(false); 
    B4->setPhysicsBody(B4Body);
    this->addChild(B4);

    //Block5
    auto B5 = Sprite::create("block1.png");
    B5->setPosition(630, 636);
    B5->setAnchorPoint(Vec2(0.0, 0.0));
    auto B5Body = PhysicsBody::createBox(B5->getContentSize(), PhysicsMaterial(0, 0, 0));
    //collision
    B5Body->setContactTestBitmask(0xFFFFFFFF);
    B5Body->setDynamic(false); 
    B5->setPhysicsBody(B5Body);
    this->addChild(B5);

    //Block6
    auto B6 = Sprite::create("block1.png");
    B6->setPosition(740, 636);
    B6->setAnchorPoint(Vec2(0.0, 0.0));
    auto B6Body = PhysicsBody::createBox(B6->getContentSize(), PhysicsMaterial(0, 0, 0));
    //collision
    B6Body->setContactTestBitmask(0xFFFFFFFF);
    B6Body->setDynamic(false);
    B6->setPhysicsBody(B6Body);
    this->addChild(B6);

    //Block7
    auto B7 = Sprite::create("block1.png");
    B7->setPosition(850, 636);
    B7->setAnchorPoint(Vec2(0.0, 0.0));
    auto B7Body = PhysicsBody::createBox(B7->getContentSize(), PhysicsMaterial(0, 0, 0));
    //collision
    B7Body->setContactTestBitmask(0xFFFFFFFF);
    B7Body->setDynamic(false); 
    B7->setPhysicsBody(B7Body);
    this->addChild(B7);

    //Block8
    auto B8 = Sprite::create("block1.png");
    B8->setPosition(960, 636);
    B8->setAnchorPoint(Vec2(0.0, 0.0));
    auto B8Body = PhysicsBody::createBox(B8->getContentSize(), PhysicsMaterial(0, 0, 0));
    //collision
    B8Body->setContactTestBitmask(0xFFFFFFFF);
    B8Body->setDynamic(false); 
    B8->setPhysicsBody(B8Body);
    this->addChild(B8);

    //Block9
    auto B9 = Sprite::create("block1.png");
    B9->setPosition(1070, 636);
    B9->setAnchorPoint(Vec2(0.0, 0.0));
    auto B9Body = PhysicsBody::createBox(B9->getContentSize(), PhysicsMaterial(0, 0, 0));
    //collision
    B9Body->setContactTestBitmask(0xFFFFFFFF);
    B9Body->setDynamic(false); 
    B9->setPhysicsBody(B9Body);
    this->addChild(B9);

    //Block10
    auto B10 = Sprite::create("block1.png");
    B10->setPosition(1180, 636);
    B10->setAnchorPoint(Vec2(0.0, 0.0));
    auto B10Body = PhysicsBody::createBox(B10->getContentSize(), PhysicsMaterial(0, 0, 0));
    //collision
    B10Body->setContactTestBitmask(0xFFFFFFFF);
    B10Body->setDynamic(false); 
    B10->setPhysicsBody(B10Body);
    this->addChild(B10);

    //Block11
    auto B11 = Sprite::create("block1.png");
    B11->setPosition(1290, 636);
    B11->setAnchorPoint(Vec2(0.0, 0.0));
    auto B11Body = PhysicsBody::createBox(B11->getContentSize(), PhysicsMaterial(0, 0, 0));
    //collision
    B11Body->setContactTestBitmask(0xFFFFFFFF);
    B11Body->setDynamic(false); 
    B11->setPhysicsBody(B11Body);
    this->addChild(B11);

    //Block12
    auto B12 = Sprite::create("block1.png");
    B12->setPosition(1400, 636);
    B12->setAnchorPoint(Vec2(0.0, 0.0));
    auto B12Body = PhysicsBody::createBox(B12->getContentSize(), PhysicsMaterial(0, 0, 0));
    //collision
    B12Body->setContactTestBitmask(0xFFFFFFFF);
    B12Body->setDynamic(false); 
    B12->setPhysicsBody(B12Body);
    this->addChild(B12);

    //Block13
    auto B13 = Sprite::create("block1.png");
    B13->setPosition(1510, 636);
    B13->setAnchorPoint(Vec2(0.0, 0.0));
    auto B13Body = PhysicsBody::createBox(B13->getContentSize(), PhysicsMaterial(0, 0, 0));
    //collision
    B13Body->setContactTestBitmask(0xFFFFFFFF);
    B13Body->setDynamic(false); 
    B13->setPhysicsBody(B13Body);
    this->addChild(B13);

    //Block14
    auto B14 = Sprite::create("block1.png");
    B14->setPosition(1620, 636);
    B14->setAnchorPoint(Vec2(0.0, 0.0));
    auto B14Body = PhysicsBody::createBox(B14->getContentSize(), PhysicsMaterial(0, 0, 0));
    //collision
    B14Body->setContactTestBitmask(0xFFFFFFFF);
    B14Body->setDynamic(false);
    B14->setPhysicsBody(B14Body);
    this->addChild(B14);
    

    //ball
    ball = Sprite::create("ball.png");
    ball->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 2) + origin.y));
    ball->setTag(10);
    auto ballBody = PhysicsBody::createCircle(ball->getContentSize().width / 2, PhysicsMaterial(0, 1.7, 0));
    //collision
    ballBody->setContactTestBitmask(0xFFFFFFFF);
    ball->setPhysicsBody(ballBody);
    this->addChild(ball);

    //Bear Body
    bear = Sprite::create("Bear.png");
    bear->setPosition(Point(visibleSize.width / 2 + origin.x, origin.y + 158));
    MyBodyParser::getInstance()->parseJsonFile("Bear.json");
    auto bearBody = MyBodyParser::getInstance()->bodyFormJson(bear, "Bear", PhysicsMaterial(0, 1, 0));

    if (bearBody != nullptr)
    {
        bearBody->setDynamic(false);
        bear->setPhysicsBody(bearBody);
    }
    this->addChild(bear);


    //Contact
    auto contactListener = EventListenerPhysicsContact::create();
    contactListener-> onContactBegin = CC_CALLBACK_1(ThirdGameScene::onContactBegin, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);

    //Contact2
    auto contactListener2 = EventListenerPhysicsContact::create();
    contactListener2 -> onContactBegin = CC_CALLBACK_1(ThirdGameScene::onContactRestart, this);
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener2, this);





    //Keyboard
    auto eventListener = EventListenerKeyboard::create();
    eventListener->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event)
    {
        switch (keyCode) {
        case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
        case EventKeyboard::KeyCode::KEY_A:
            posX -= 8.0f;
            break;
        case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
        case EventKeyboard::KeyCode::KEY_D:
            posX += 8.0f;
            break;
        }
    };

    eventListener->onKeyReleased = [=](EventKeyboard::KeyCode keyCode, Event* event)
    {
        switch (keyCode) {
        case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
        case EventKeyboard::KeyCode::KEY_A:
            posX += 8.0f;
            break;
        case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
        case EventKeyboard::KeyCode::KEY_D:
            posX -= 8.0f;
            break;
        }
    };
    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(eventListener, this);
    this->scheduleUpdate();

    return true;
}

//Go back
void ThirdGameScene::GoBack(cocos2d::Ref* pSender)
{
    Director::getInstance()->popScene();
}

//Keyboard function
void ThirdGameScene::update(float dt)
{
    float newPosX = bear->getPositionX() + (posX);
    float newPosY = bear->getPositionY();

    if (newPosX > 1700)
    {
        newPosX -= 8;
    }
    else if (newPosX < 220)
    {
        newPosX += 8;
    }

    bear->setPosition(newPosX, newPosY);
}

//collision to remove blocks
bool ThirdGameScene::onContactBegin(cocos2d::PhysicsContact& contact)
{
    auto nodeA = contact.getShapeA()->getBody()->getNode();
    auto nodeB = contact.getShapeB()->getBody()->getNode();

    if ( nodeA && nodeB )
    {
        if (nodeA->getTag() == 10)
        {
            nodeB->removeFromParentAndCleanup(true);
        }
        else if (nodeB->getTag() == 10)
        {
            nodeA->removeFromParentAndCleanup(true);
        }
    }

    //bodies can collide
    return true;
}


bool ThirdGameScene::onContactRestart(cocos2d::PhysicsContact& contact)
{
    auto nodeA = contact.getShapeA()->getBody()->getNode();
    auto nodeB = contact.getShapeB()->getBody()->getNode();

    if (nodeA && nodeB)
    {
        if (nodeA->getTag() == 20)
        {
            Director::getInstance()->popScene();
            auto scene = ThirdGameScene::createScene();
            Director::getInstance()->pushScene(scene);
        }
        else if (nodeB->getTag() == 20)
        {
            Director::getInstance()->popScene();
            auto scene = ThirdGameScene::createScene();
            Director::getInstance()->pushScene(scene);
        }
    }

    //bodies can collide
    return true;
}










