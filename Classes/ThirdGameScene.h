#ifndef __THIRDGAME_SCENE_H__
#define __THIRDGAME_SCENE_H__

#include "cocos2d.h"

class ThirdGameScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(ThirdGameScene);

    //sprites
    cocos2d::Sprite* bear;
    cocos2d::Sprite* ball;


    //Go back
    void GoBack(Ref* pSender);
    

    //Keyboard
    void update(float dt);

    
    //oncontact method 
    bool onContactBegin(cocos2d::PhysicsContact& contact);
    bool onContactRestart(cocos2d::PhysicsContact& contact);
    


    //PhysicsWorld
private:
    cocos2d::PhysicsWorld* sceneWorld;

    void SetPhysicsWorld(cocos2d::PhysicsWorld* world) { sceneWorld = world; };

    

};

#endif // __THIRDGAME_SCENE_H__
