//
//  FishingNet.h
//  FishingJoy
//
//  Created by Ringo_D on 12-9-18.
//
//

#ifndef _GoldController_h_
#define _GoldController_h_
#include "cocos2d.h"

using namespace cocos2d;

class GoldController : public CCNode
{
public:
    GoldController(void);
    virtual ~GoldController(void);
    virtual void onEnter();
    virtual void onExit();
    CCArray *bits;
    int gold;
    void subNumber(int var);
	void setGold(int var);
    CCTexture2D* ui;
};

#endif