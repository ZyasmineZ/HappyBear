#ifndef __MENU_SCENE_H__
#define __MENU_SCENE_H__

#include "cocos2d.h"

class MenuScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();


    // implement the "static create()" method manually
    CREATE_FUNC(MenuScene);


    
    //Menu buttons
    void L1(Ref* pSender);
    void L2(Ref* pSender);
    void L3(Ref* pSender);

};

#endif // __MENU_SCENE_H__
