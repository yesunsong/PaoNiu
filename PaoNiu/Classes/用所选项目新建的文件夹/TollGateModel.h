#ifndef _TollGateModel_h
#define _TollGateModel_h
#include "cocos2d.h"
using namespace cocos2d;

class TollGateModel : public CCNode, public CCTargetedTouchDelegate
{
public:
    CCSprite *boom;
    CCSprite *mainbody;
    TollGateModel(void);
    virtual ~TollGateModel(void);
    void releasebullet();
    virtual void onEnter();
    virtual void onExit();
    //void movestart();
    void restart();
    void setdie();
    short type;
    bool islife;
    void setType(short var);
};


#endif