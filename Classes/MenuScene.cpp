#include "MenuScene.h"
#include "GameScene.h"
#include "SecondGameScene.h"
#include "ThirdGameScene.h"
#include "Definitions.h"

USING_NS_CC;

Scene* MenuScene::createScene()
{
    return MenuScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool MenuScene::init()
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
    auto BSprite = Sprite::create("menu.png");
    BSprite->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 2) + origin.y));
    this->addChild(BSprite);

    //Menu items
    auto menu_item_1 = MenuItemImage::create("ele.png", "ele.png", CC_CALLBACK_1(MenuScene::L1, this));
    auto menu_item_2 = MenuItemImage::create("ele.png", "ele.png", CC_CALLBACK_1(MenuScene::L2, this));
    auto menu_item_3 = MenuItemImage::create("ele.png", "ele.png", CC_CALLBACK_1(MenuScene::L3, this));


    menu_item_1->setPosition(Point((visibleSize.width / 4) , visibleSize.height / 2 -50));
    menu_item_2->setPosition(Point((visibleSize.width / 4 + 280) , visibleSize.height / 2 - 273));
    menu_item_3->setPosition(Point((visibleSize.width / 2 +245) , visibleSize.height / 3 +20 ));


    auto* menu = Menu::create(menu_item_1, menu_item_2, menu_item_3, NULL);
    menu->setPosition(Point(0, 0));
    this->addChild(menu);
    

    return true;
}

void MenuScene::L1(cocos2d::Ref* pSender)
{
    CCLOG("L1");
    auto scene = GameScene::createScene();
    Director::getInstance()->pushScene(scene);
}
void MenuScene::L2(cocos2d::Ref* pSender)
{
    CCLOG("L2");
    auto scene = SecondGameScene::createScene();
    Director::getInstance()->pushScene(scene);
}
void MenuScene::L3(cocos2d::Ref* pSender)
{
    CCLOG("L3");
    auto scene = ThirdGameScene::createScene();
    Director::getInstance()->pushScene(scene);
}
