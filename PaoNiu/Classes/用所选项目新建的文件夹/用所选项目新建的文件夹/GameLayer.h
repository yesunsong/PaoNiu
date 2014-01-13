//
//  Cannon.h
//  FishingJoy
//
//  Created by Ringo_D on 12-9-11.
//
//

#ifndef _GameLayer__
#define _GameLayer__
#include "cocos2d.h"
#include "PapawController.h"
class GameLayer : public cocos2d::CCLayer
{
public:
    CREATE_FUNC(GameLayer);
    bool init();
    CC_SYNTHESIZE_READONLY(PapawController*, _papaw, PapawController);
    
    bool shootTo(cocos2d::CCPoint touchLocation);
    void papawShow(cocos2d::CCPoint target);
protected:
    //ÇÐ»»ÅÚÌ¨
    void switchPapaw(cocos2d::CCObject* sender);
    cocos2d::CCMenuItemSprite* _subItem;
    cocos2d::CCMenuItemSprite* _addItem;
};

#endif /* defined(__FishingJoy__Cannon__) */
