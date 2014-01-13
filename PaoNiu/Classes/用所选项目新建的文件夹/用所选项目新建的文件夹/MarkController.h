//
//  FishingNet.h
//  FishingJoy
//
//  Created by Ringo_D on 12-9-18.
//
//

#ifndef _MarkController_h_
#define _MarkController_h_
#include "cocos2d.h"

using namespace cocos2d;

class MarkController : public CCNode
{
public:
    MarkController(void);
    virtual ~MarkController(void);
    virtual void onEnter();
    virtual void onExit();
    CCArray *bits;
    int mark;
    void addnumber(int var);
    CCTexture2D* ui;
};

#endif