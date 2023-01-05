#include "SecondGameScene.h"
#include "MyBodyParser.h"
#include "SimpleAudioEngine.h"


USING_NS_CC;
int DirX = 0;

Scene* SecondGameScene::createScene()
{
    //PhysicsWorld
    auto scene = Scene::createWithPhysics();
    //scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);  //Quand activée cette comande rend les bords des objets rouge

    auto layer = SecondGameScene::create();
    layer->SetPhysicsWorld(scene->getPhysicsWorld());
    scene->addChild(layer);


    return scene;
}

static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

bool SecondGameScene::init()
{
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();


    //audio
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("audio/lose.mp3");


    //Background
    BSprite = Sprite::create("road.png");
    BSprite->setAnchorPoint(Vec2(0.0, 0.0));
    BSprite->setPosition(Point(origin.x, origin.y ));
    this->addChild(BSprite);
    //moveby action
    auto action = MoveBy::create(10, Point(0, -3970));
    BSprite->runAction(action);



    //Go back
    auto menu_item_1 = MenuItemImage::create("GoBack.png", "GoBack.png", CC_CALLBACK_1(SecondGameScene::GoBack, this));
    menu_item_1->setPosition(Point(visibleSize.width / 10, (visibleSize.height / 10) * 9));
    auto* menu = Menu::create(menu_item_1, NULL);
    menu->setPosition(Point(0, 0));
    this->addChild(menu);



    //Rectangular static Sprite Physics Body CAR
    car = Sprite::create("car.png");
    car->setPosition(Point(visibleSize.width / 2 + origin.x, origin.y + 500));
    car->setTag(10);
    MyBodyParser::getInstance()->parseJsonFile("car.json");
    auto carBody = MyBodyParser::getInstance()->bodyFormJson(car, "car", PhysicsMaterial(0, 0, 0));
    carBody->setContactTestBitmask(0xFFFFFFFF);
    if (carBody != nullptr)
    {
        carBody->setDynamic(false);
        car->setPhysicsBody(carBody);
    }
    this->addChild(car);
    //moveby action
    auto action10 = MoveBy::create(10, Point(0, 0));
    auto action11 = MoveBy::create(2, Point(0, 350));
    auto action13 = Sequence::create(action10, action11, NULL);
    car->runAction(action13);

    
    
    //Rectangular static Sprite Physics Body WHEEL
    auto wheel = Sprite::create("wheel.png");
    wheel->setPosition(Point(visibleSize.width / 2 + origin.x +130 , origin.y + 900));
    auto wheelBody = PhysicsBody::createCircle(wheel->getContentSize().width / 2, PhysicsMaterial(0, 0, 0));
    wheelBody->setContactTestBitmask(0xFFFFFFFF);
    wheelBody->setDynamic(false);
    wheel->setPhysicsBody(wheelBody);
    this->addChild(wheel);
    auto action1 = MoveBy::create(10, Point(0, -3970));
    wheel->runAction(action1);

    

    //Rectangular static Sprite Physics Body WHEEL
    auto wheel2 = Sprite::create("wheel.png");
    wheel2->setPosition(Point(visibleSize.width / 2 + origin.x - 130, origin.y + 1500));
    auto wheelBody2 = PhysicsBody::createCircle(wheel2->getContentSize().width / 2, PhysicsMaterial(0, 0, 0));
    wheelBody2->setContactTestBitmask(0xFFFFFFFF);
    wheelBody2->setDynamic(false);
    wheel2->setPhysicsBody(wheelBody2);
    this->addChild(wheel2);
    auto action2 = MoveBy::create(10, Point(0, -3970));
    wheel2->runAction(action2);
    
    

    //Rectangular static Sprite Physics Body WHEEL
    auto wheel3 = Sprite::create("wheel.png");
    wheel3->setPosition(Point(visibleSize.width / 2 + origin.x , origin.y + 2000));
    auto wheelBody3 = PhysicsBody::createCircle(wheel3->getContentSize().width / 2, PhysicsMaterial(0, 0, 0));
    wheelBody3->setContactTestBitmask(0xFFFFFFFF);
    wheelBody3->setDynamic(false);
    wheel3->setPhysicsBody(wheelBody3);
    this->addChild(wheel3);
    auto action3 = MoveBy::create(10, Point(0, -3970));
    wheel3->runAction(action3);

   
    
    //Rectangular static Sprite Physics Body WHEEL
    auto wheel4 = Sprite::create("wheel.png");
    wheel4->setPosition(Point(visibleSize.width / 2 + origin.x - 130, origin.y + 2500));
    auto wheelBody4 = PhysicsBody::createCircle(wheel4->getContentSize().width / 2, PhysicsMaterial(0, 0, 0));
    wheelBody4->setContactTestBitmask(0xFFFFFFFF);
    wheelBody4->setDynamic(false);
    wheel4->setPhysicsBody(wheelBody4);
    this->addChild(wheel4);
    auto action4 = MoveBy::create(10, Point(0, -3970));
    wheel4->runAction(action4);



    //Rectangular static Sprite Physics Body WHEEL
    auto wheel5 = Sprite::create("wheel.png");
    wheel5->setPosition(Point(visibleSize.width / 2 + origin.x + 130, origin.y + 3000));
    auto wheelBody5 = PhysicsBody::createCircle(wheel5->getContentSize().width / 2, PhysicsMaterial(0, 0, 0));
    wheelBody5->setContactTestBitmask(0xFFFFFFFF);
    wheelBody5->setDynamic(false);
    wheel5->setPhysicsBody(wheelBody5);
    this->addChild(wheel5);
    auto action5 = MoveBy::create(10, Point(0, -3970));
    wheel5->runAction(action5);


    //Rectangular static Sprite Physics Body WHEEL
    auto wheel6 = Sprite::create("wheel.png");
    wheel6->setPosition(Point(visibleSize.width / 2 + origin.x , origin.y + 3000));
    auto wheelBody6 = PhysicsBody::createCircle(wheel6->getContentSize().width / 2, PhysicsMaterial(0, 0, 0));
    wheelBody6->setContactTestBitmask(0xFFFFFFFF);
    wheelBody6->setDynamic(false);
    wheel6->setPhysicsBody(wheelBody6);
    this->addChild(wheel6);
    auto action6 = MoveBy::create(10, Point(0, -3970));
    wheel6->runAction(action6);



    //Rectangular static Sprite Physics Body WHEEL
    auto wheel7 = Sprite::create("wheel.png");
    wheel7->setPosition(Point(visibleSize.width / 2 -140 + origin.x, origin.y + 3500));
    auto wheelBody7 = PhysicsBody::createCircle(wheel7->getContentSize().width / 2, PhysicsMaterial(0, 0, 0));
    wheelBody7->setContactTestBitmask(0xFFFFFFFF);
    wheelBody7->setDynamic(false);
    wheel7->setPhysicsBody(wheelBody7);
    this->addChild(wheel7);
    auto action7 = MoveBy::create(10, Point(0, -3970));
    wheel7->runAction(action7);


    //Rectangular static Sprite Physics Body WHEEL
    auto wheel8 = Sprite::create("wheel.png");
    wheel8->setPosition(Point(visibleSize.width / 2 + 140 + origin.x, origin.y + 3500));
    auto wheelBody8 = PhysicsBody::createCircle(wheel8->getContentSize().width / 2, PhysicsMaterial(0, 0, 0));
    wheelBody8->setContactTestBitmask(0xFFFFFFFF);
    wheelBody8->setDynamic(false);
    wheel8->setPhysicsBody(wheelBody8);
    this->addChild(wheel8);
    auto action8 = MoveBy::create(10, Point(0, -3970));
    wheel8->runAction(action8);


    //Rectangular static Sprite Physics Body WHEEL
    auto wheel9 = Sprite::create("wheel.png");
    wheel9->setPosition(Point(visibleSize.width / 2 + origin.x, origin.y + 4000));
    auto wheelBody9 = PhysicsBody::createCircle(wheel9->getContentSize().width / 2, PhysicsMaterial(0, 0, 0));
    wheelBody9->setContactTestBitmask(0xFFFFFFFF);
    wheelBody9->setDynamic(false);
    wheel9->setPhysicsBody(wheelBody9);
    this->addChild(wheel9);
    auto action9 = MoveBy::create(10, Point(0, -3970));
    wheel9->runAction(action9);

    

    //Contact
    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(SecondGameScene::onContactBegin, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);



    //left right Keyboard
    auto eventListener = EventListenerKeyboard::create();
    eventListener->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event)
    {
        switch (keyCode) {
        case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
        case EventKeyboard::KeyCode::KEY_A:
            DirX -= 8.0f;
            break;
        case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
        case EventKeyboard::KeyCode::KEY_D:
            DirX += 8.0f;
            break;
        }
    };

    eventListener->onKeyReleased = [=](EventKeyboard::KeyCode keyCode, Event* event)
    {
        switch (keyCode) {
        case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
        case EventKeyboard::KeyCode::KEY_A:
            DirX += 8.0f;
            break;
        case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
        case EventKeyboard::KeyCode::KEY_D:
            DirX -= 8.0f;
            break;
        }
    };
    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(eventListener, this);
    this->scheduleUpdate();

    return true;
}

//Go back
void SecondGameScene::GoBack(cocos2d::Ref* pSender)
{
    Director::getInstance()->popScene();
}

//Keyboard function
void SecondGameScene::update(float dt)
{
    float newPosX = car->getPositionX() + (DirX);
    float newPosY = car->getPositionY();

    if (newPosX > 1170)
    {
        newPosX -= 8;
    }
    else if (newPosX < 750)
    {
        newPosX += 8;
    }
    else if (newPosY == 850)
    {
        Director::getInstance()->popScene();
    }
    

    car->setPosition(newPosX, newPosY);
}

//onContact lossing method
bool SecondGameScene::onContactBegin(cocos2d::PhysicsContact& contact)
{
    auto nodeA = contact.getShapeA()->getBody()->getNode();
    auto nodeB = contact.getShapeB()->getBody()->getNode();

    if (nodeA && nodeB)
    {
        if (nodeA->getTag() == 10)
        {
            Director::getInstance()->popScene();
            auto scene = SecondGameScene::createScene();
            Director::getInstance()->pushScene(scene);
            //audio
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/lose.mp3");
        }
        else if (nodeB->getTag() == 10)
        {
            Director::getInstance()->popScene();
            auto scene = SecondGameScene::createScene();
            Director::getInstance()->pushScene(scene);
            //audio
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/lose.mp3");
        }
    }

    //bodies can collide
    return true;
}