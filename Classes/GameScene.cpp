#include "GameScene.h"
#include "MyBodyParser.h"

USING_NS_CC;
int newX = 0;

Scene* GameScene::createScene()
{
    //PhysicsWorld
    auto scene = Scene::createWithPhysics();
    //scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);  //Quand activée cette comande rend les bords des objets rouge

    auto layer = GameScene::create();
    layer->SetPhysicsWorld(scene->getPhysicsWorld());
    scene->addChild(layer);


    return scene;
}

static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

bool GameScene::init()
{
    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    //Background
    auto BSprite = Sprite::create("Background2.png");
    BSprite->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 2) + origin.y));
    this->addChild(BSprite);


    //Honey
    auto HSprite = Sprite::create("honey.png");
    HSprite->setAnchorPoint(Vec2(0.0, 0.0));
    HSprite->setPosition(Point(origin.x + 1700 , origin.y + 30 ));
    this->addChild(HSprite);
    

    //Go back
    auto menu_item_1 = MenuItemImage::create("GoBack.png", "GoBack.png", CC_CALLBACK_1(GameScene::GoBack, this));
    menu_item_1->setPosition(Point(visibleSize.width / 10, (visibleSize.height / 10) * 9));
    auto* menu = Menu::create(menu_item_1, NULL);
    menu->setPosition(Point(0, 0));
    this->addChild(menu);


    //Rectangular static Sprite Physics Body FLOOR
    auto sprite2 = Sprite::create("Object.png");
    sprite2->setPosition(Point(visibleSize.width / 2 + origin.x, origin.y + 29 ));
    auto spriteBody2 = PhysicsBody::createBox(sprite2->getContentSize(), PhysicsMaterial(0, 1, 0));
    spriteBody2->setDynamic(false); //si on commante cette phrase l'objet deviens dynamic
    sprite2->setPhysicsBody(spriteBody2);
    this->addChild(sprite2);
    


    



    
    //Rectangular static Sprite Physics Body BUTTON
    auto button = Sprite::create("button.png");
    button->setPosition(Point(origin.x +300, origin.y + 70));
    auto buttonBody = PhysicsBody::createCircle(button->getContentSize().width/2 , PhysicsMaterial(0, 0, 0));
    buttonBody->setContactTestBitmask(0xFFFFFFFF);
    buttonBody->setDynamic(false);
    button->setPhysicsBody(buttonBody);
    this->addChild(button);

    //Rectangular static Sprite Physics Body BUTTON
    auto button2 = Sprite::create("button.png");
    button2->setPosition(Point(origin.x + 600, origin.y + 70));
    auto buttonBody2 = PhysicsBody::createCircle(button2->getContentSize().width / 2, PhysicsMaterial(0, 0, 0));
    buttonBody2->setContactTestBitmask(0xFFFFFFFF);
    buttonBody2->setDynamic(false);
    button2->setPhysicsBody(buttonBody2);
    this->addChild(button2);

    //Rectangular static Sprite Physics Body BUTTON
    auto button3 = Sprite::create("button.png");
    button3->setPosition(Point(origin.x + 900, origin.y + 70));
    auto buttonBody3 = PhysicsBody::createCircle(button3->getContentSize().width / 2, PhysicsMaterial(0, 0, 0));
    buttonBody3->setContactTestBitmask(0xFFFFFFFF);
    buttonBody3->setDynamic(false);
    button3->setPhysicsBody(buttonBody3);
    this->addChild(button3);

    //Rectangular static Sprite Physics Body BUTTON
    auto button4 = Sprite::create("button.png");
    button4->setPosition(Point(origin.x + 1100, origin.y + 70));
    auto buttonBody4 = PhysicsBody::createCircle(button4->getContentSize().width / 2, PhysicsMaterial(0, 0, 0));
    buttonBody4->setContactTestBitmask(0xFFFFFFFF);
    buttonBody4->setDynamic(false);
    button4->setPhysicsBody(buttonBody4);
    this->addChild(button4);

    //Rectangular static Sprite Physics Body BUTTON
    auto button5 = Sprite::create("button.png");
    button5->setPosition(Point(origin.x + 1300, origin.y + 70));
    auto buttonBody5 = PhysicsBody::createCircle(button5->getContentSize().width / 2, PhysicsMaterial(0, 0, 0));
    buttonBody5->setContactTestBitmask(0xFFFFFFFF);
    buttonBody5->setDynamic(false);
    button5->setPhysicsBody(buttonBody5);
    this->addChild(button5);

    //Rectangular static Sprite Physics Body BUTTON
    auto button6 = Sprite::create("button.png");
    button6->setPosition(Point(origin.x + 1500, origin.y + 70));
    auto buttonBody6 = PhysicsBody::createCircle(button6->getContentSize().width / 2, PhysicsMaterial(0, 0, 0));
    buttonBody6->setContactTestBitmask(0xFFFFFFFF);
    buttonBody6->setDynamic(false);
    button6->setPhysicsBody(buttonBody6);
    this->addChild(button6);
    
    


    //Bear Body
    bear = Sprite::create("Bear.png");
    bear->setPosition(Point(origin.x + 150, origin.y + 100));
    bear->setTag(10);
    MyBodyParser::getInstance()->parseJsonFile("Bear.json");
    auto bearBody = MyBodyParser::getInstance()->bodyFormJson(bear, "Bear", PhysicsMaterial(0, 0, 0));
    bearBody->setContactTestBitmask(0xFFFFFFFF);

    if (bearBody != nullptr)
    {
        bearBody->setDynamic(false);
        bear->setPhysicsBody(bearBody);
    }
    this->addChild(bear);

    
    //Contact
    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(GameScene::onContactBegin, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);
    

    //Keybord
    auto eventListener = EventListenerKeyboard::create();
    eventListener->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event)
    {
        switch (keyCode) {
        case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
        case EventKeyboard::KeyCode::KEY_A:
            newX -= 3.0f;
            break;
        case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
        case EventKeyboard::KeyCode::KEY_D:
            newX += 3.0f;
            break;
        }
    };

    eventListener->onKeyReleased = [=](EventKeyboard::KeyCode keyCode, Event* event)
    {
        switch (keyCode) {
        case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
        case EventKeyboard::KeyCode::KEY_A:
            newX += 3.0f;
            break;
        case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
        case EventKeyboard::KeyCode::KEY_D:
            newX -= 3.0f;
            break;
        }
    };
    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(eventListener, this);
    this->scheduleUpdate();

    //JUMP Keybord
    auto keventListener = EventListenerKeyboard::create();
    keventListener->onKeyPressed = [](EventKeyboard::KeyCode keyCode, Event* event) {
        float newY = event->getCurrentTarget()->getPositionY();
        switch (keyCode) {
        case EventKeyboard::KeyCode::KEY_UP_ARROW:
        case EventKeyboard::KeyCode::KEY_W:
            if ( newY == 100)
            {
                auto JumpAction = JumpBy::create(0.6, Point(0, 0), 200, 1);
                event->getCurrentTarget()->runAction(JumpAction);
            }
            break;
        }
    };
    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(keventListener, bear);

    
    

    return true;
}


//Go back
void GameScene::GoBack(cocos2d::Ref* pSender)
{
    Director::getInstance()->popScene();
}


//Keyboard function
void GameScene::update(float dt)
{
    float newPosX = bear->getPositionX() + (newX);
    float newPosY = bear->getPositionY();

    if (newPosX > 1700)
    {
        Director::getInstance()->popScene();
    }
    else if (newPosX < 30)
    {
        newPosX += 3;
    }
    
    bear->setPosition(newPosX, newPosY);
}

bool GameScene::onContactBegin(cocos2d::PhysicsContact& contact)
{
    auto nodeA = contact.getShapeA()->getBody()->getNode();
    auto nodeB = contact.getShapeB()->getBody()->getNode();

    if (nodeA && nodeB)
    {
        if (nodeA->getTag() == 10)
        {
            Director::getInstance()->popScene();
            auto scene = GameScene::createScene();
            Director::getInstance()->pushScene(scene);
        }
        else if (nodeB->getTag() == 10)
        {
            Director::getInstance()->popScene();
            auto scene = GameScene::createScene();
            Director::getInstance()->pushScene(scene);
        }
    }

    //bodies can collide
    return true;
}

