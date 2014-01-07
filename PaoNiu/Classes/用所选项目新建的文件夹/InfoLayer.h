#ifndef _InfoLayer_h
#define _InfoLayer_h
#include "cocos2d.h"
#include "MarkController.h"
#include "GoldController.h"

//#include "GameObjEnemy.h"
//#include "GameMark.h"
using namespace cocos2d;
class InfoLayer : public cocos2d::CCLayer
{
public:
    //static GameScene sGameScene;
    
    virtual bool init();

	void addMark(int addMark);
	void subGold(int subGold);
    //virtual void update(float time);
    //static cocos2d::CCScene* scene();
	/*
    void releaseenemyBullet(int x,int y);
    void releaseheroBullet(int x,int y);
    bool isCollion(CCPoint p1,CCPoint p2,int w1,int h1,int w2,int h2);
    void setherohurt();
    void resetreduce();
    GameMark* gamemark;
	*/
	cocos2d:: CCLabelBMFont*    m_label0;
	//倒计时
	cocos2d:: CCLabelBMFont*    lfTime;
	float mTime ;
	//加个计时更新
	void gameTimer(float dt);

	MarkController* gamemark;

	GoldController* gameGold;

    CREATE_FUNC(InfoLayer);

};


#endif
