#ifndef __START_SCENE_H__
#define __START_SCENE_H__

#include "cocos2d.h"

class StartScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();


    // implement the "static create()" method manually
    CREATE_FUNC(StartScene);


private:
    void GoToMenuScene(cocos2d::Ref* sender);


};

#endif // __START_SCENE_H__
