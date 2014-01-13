//
//  FishingNet.h
//  FishingJoy
//
//  Created by Ringo_D on 12-9-18.
//
//

#ifndef _PapawController_h_
#define _PapawController_h_
#include "cocos2d.h"
typedef enum{
    k_Papaw_Type_1 = 0,
    k_Papaw_Type_2,
    k_Papaw_Type_Count,
    k_Papaw_Type_Invalid
}PapawType;


class PapawController : public cocos2d::CCNode
{
public:
    CREATE_FUNC(PapawController);
	static PapawController* create(PapawType type = k_Papaw_Type_1);
    bool init(PapawType type = k_Papaw_Type_1);
    //bool init();
    //使PapawController在屏幕上出现
    void showAt(cocos2d::CCPoint pos);
    cocos2d::CCRect getCollisionArea();

protected:
    cocos2d::CCSprite *_papawSprite;
    cocos2d::CCAction* netAction();
};
#endif /* defined(__FishingJoy__FishingNet__) */
