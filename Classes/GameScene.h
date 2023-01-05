#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"

class GameScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);



    //GoBack
    void GoBack(Ref* pSender);


    //Keyboard
    void update(float dt);

    //oncontact method 
    bool onContactBegin(cocos2d::PhysicsContact& contact);


    cocos2d::Sprite* bear;


    //PhysicsWorld
private:
    cocos2d::PhysicsWorld* sceneWorld;

    void SetPhysicsWorld(cocos2d::PhysicsWorld* world) { sceneWorld = world; };

    

};

#endif // __GAME_SCENE_H__
