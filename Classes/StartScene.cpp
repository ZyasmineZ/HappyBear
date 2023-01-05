#include "StartScene.h"
#include "MenuScene.h"
#include "Definitions.h"

USING_NS_CC;

Scene* StartScene::createScene()
{
    return StartScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool StartScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    
    //Background
    auto backgroundsptite = Sprite::create("SBackground.png");
    backgroundsptite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(backgroundsptite);



    //Tap to start
    auto menu_item_1 = MenuItemImage::create("Start.png", "Start.png", CC_CALLBACK_1(StartScene::GoToMenuScene, this));
    menu_item_1->setPosition(Point((visibleSize.width / 5) * 3, visibleSize.height / 4));


    auto* menu = Menu::create(menu_item_1, NULL);
    menu->setPosition(Point(0, 0));
    this->addChild(menu);


    //hand sprite
    auto HSprite = Sprite::create("H.png");
    HSprite->setPosition(Point((visibleSize.width / 7) * 5, visibleSize.height / 4));
    this->addChild(HSprite);
    //Repeat Jump action
    auto action = RepeatForever::create(JumpBy::create(1, Point(0, 0), 40, 1));
    HSprite->runAction(action);


    return true;
}

void StartScene::GoToMenuScene(cocos2d::Ref* sender)
{
    auto scene = MenuScene::createScene();
    Director::getInstance()->replaceScene( TransitionFade::create(TRANSITION_TIME, scene));
}