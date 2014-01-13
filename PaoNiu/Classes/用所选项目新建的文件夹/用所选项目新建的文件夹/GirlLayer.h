

#ifndef _GirlLayer_h_
#define _GirlLayer_h_
#include "cocos2d.h"
#include "GirlController.h"
#include "BoyController.h"
class GirlLayer : public cocos2d::CCLayer
{
public:
    CREATE_FUNC(GirlLayer);
    bool init();
    CC_SYNTHESIZE_READONLY(cocos2d::CCArray*, _girls, Girls);
	CC_SYNTHESIZE_READONLY(cocos2d::CCArray*, _boys, Boys);
    ~GirlLayer();
protected:
    void addGirl(float dt);
    void resetGirl(GirlController* girl);
	void addBoy(float dt);
    void resetBoy(BoyController* girl);
};

#endif /* defined(__FishingJoy__FishLayer__) */
