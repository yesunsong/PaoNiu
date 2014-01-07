#ifndef _GameController_h
#define _GameController_h

#include "cocos2d.h"
#include "GameScene.h"

class GameController : public cocos2d::CCLayer{
public: 
	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    //static cocos2d::CCScene* scene();


    GameScene *view; 
    // ... 
  
    // implement the "static node()" method manually 
    CREATE_FUNC(GameController); 
};

#endif