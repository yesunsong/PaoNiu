#ifndef _GirlController_h
#define _GirlController_h


//
//  Fish.h
//  FishingJoy
//
//  Created by Ringo_D on 12-9-12.
//
//
#include "cocos2d.h"
typedef enum{
    k_Girl_Type_Red = 0,
    k_Girl_Type_Yellow,
    k_Girl_Type_Count
}GirlType;
class GirlController : public cocos2d::CCNode
{
public:
    static GirlController* create(GirlType type = k_Girl_Type_Red);
    bool init(GirlType type = k_Girl_Type_Red);
    
    CC_SYNTHESIZE_READONLY(cocos2d::CCSprite*, _girlSprite, GirlSprite);
    CC_SYNTHESIZE_READONLY(int, _type, Type);
    
    cocos2d::CCRect getCollisionArea();
    //���ű���׽�Ķ���
    void beCaught();
    
    //�ƶ��㵽destination
    void moveTo(cocos2d::CCPoint destination);
    //�������״̬
    void reset();
protected:
    void moveEnd();
    void beCaught_CallFunc();
};





#endif
