#ifndef __SECONDGAME_SCENE_H__
#define __SECONDGAME_SCENE_H__

#include "cocos2d.h"

class SecondGameScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(SecondGameScene);


    //sprites
    cocos2d::Sprite* car;
    cocos2d::Sprite* BSprite;
    

    
    //GoBack
    void GoBack(Ref* pSender);

    
    //Keyboard
    void update(float dt);

    //oncontact method 
    bool onContactBegin(cocos2d::PhysicsContact& contact);



//PhysicsWorld
private:
    cocos2d::PhysicsWorld* sceneWorld;

    void SetPhysicsWorld(cocos2d::PhysicsWorld* world) { sceneWorld = world; };

};

#endif // __SECONDGAME_SCENE_H__
