#ifndef _BoyController_h
#define _BoyController_h


//
//  Fish.h
//  FishingJoy
//
//  Created by Ringo_D on 12-9-12.
//
//
#include "cocos2d.h"
typedef enum{
    k_Boy_Type_Red = 0,
    k_Boy_Type_Yellow,
    k_Boy_Type_Count
}BoyType;
class BoyController : public cocos2d::CCNode
{
public:
    static BoyController* create(BoyType type = k_Boy_Type_Red);
    bool init(BoyType type = k_Boy_Type_Red);
    
    CC_SYNTHESIZE_READONLY(cocos2d::CCSprite*, _boySprite, BoySprite);
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
