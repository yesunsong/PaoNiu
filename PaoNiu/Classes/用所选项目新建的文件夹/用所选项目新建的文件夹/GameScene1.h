#ifndef _GameScene_h
#define _GameScene_h
#include "cocos2d.h"

//#include "InfoLayer.h"
#include "GirlLayer.h"
#include "GameLayer.h"
#include "TouchController.h"
#include "GirlController.h"
//#include "PapawControler.h"
//#include "GameObjEnemy.h"
//#include "GameMark.h"
using namespace cocos2d;

typedef enum{
    k_Operate_Pause = 0,
    k_Operate_Resume
}OperateFlag;

class GameScene : public cocos2d::CCScene
{
public:
    CREATE_FUNC(GameScene);
    bool init();
    //~GameScene();

    //�˵�ҳ����صĺ���
    //void pause();
    //void resume();
    //void sound();
    //void music();
    //void reset();
    //void transToMainMenu();

	int addMark ;

	int subGold;

	bool isPapaw;

	bool hasGold();

	void setIsPapaw(bool status);


    //����ҳ����صĺ���
    void papawShowAt(cocos2d::CCPoint target);
    void cannonShootTo(cocos2d::CCPoint target);

    void scheduleTimeUp();
//	InfoLayer * _infoLayer;
	GirlLayer * _girlLayer;
	GameLayer * _gameLayer;

	TouchController * _touch; 
   
protected:
	


	void update(float delta);

	 //��ײ������
    void checkOutCollision();
	void girlWillBeCaught(GirlController* girl);
	void boyWillBeCaught(BoyController* boy);
};


#endif
