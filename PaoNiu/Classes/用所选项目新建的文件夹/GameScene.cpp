#include "GameScene.h"
#include "GameMenuScene.h"


USING_NS_CC;

/*
CCScene* GameScene::scene()
{
    CCScene *scene = CCScene::create();
    
    GameScene *layer = GameScene::create();
    
    scene->addChild(layer);
    
    return scene;
}
*/

int addMark = 1;

int subGold = 1;


bool GameScene::init(){ 
  
    
    // 先调用超类的init方法 
    //CC_BREAK_IF(! CCLayer::init()); 

	if ( !CCScene::init())
	{
		return false;
	}

	_infoLayer = InfoLayer::create();
	this->addChild(_infoLayer,0);
	_infoLayer->gameGold->setGold(100);

	_girlLayer = GirlLayer::create();
	this->addChild(_girlLayer,0);

	_gameLayer = GameLayer::create();
	this->addChild(_gameLayer,1);

	_touch = TouchController::create();
	//_touch->setPosition(ccp(200, 200)); 
    this->addChild(_touch);
	/*
	char x[10];
	char y[10];
	sprintf(x, "%.0f",_touch->getPositionX());
	sprintf(y, "%.0f",_touch->getPositionY());
	CCLog(x);
	CCLog(y);
	*/

	_touch->setTouchEnabled(true);

	//_infoLayer->addMark(0);
	//_infoLayer->subGold(0);

    //CCLabelTTF *label = CCLabelTTF::create("Hello World from view", "Marker Felt", 48); 
        // 获取窗体的尺寸 
    //CCSize size = CCDirector::sharedDirector()->getWinSize(); 
    //label->setPosition(ccp(size.width/2, size.height/2)); 
    //this->addChild(label, 0); 
  
    this->setIsPapaw(false);
	this->scheduleUpdate();
    return true; 
}
void GameScene::update(float delta)
{
    //CCLog("checkOutCollision");
	checkOutCollision();
}
void GameScene::papawShowAt(CCPoint target)
{
    _gameLayer->papawShow(target);
}

void GameScene::setIsPapaw(bool status)
{
    isPapaw = status;
}

bool GameScene::hasGold()
{
	if(_infoLayer->gameGold->gold > 0)
	{
		return true;
	}
	else
	{
		return false;
	}

}

void GameScene::checkOutCollision()
{
    PapawController * papaw = _gameLayer->getPapawController();
	CCRect papawCollision = papaw->getCollisionArea();
	CCArray* girls = _girlLayer->getGirls();
	CCArray* boys = _girlLayer->getBoys();
    CCObject* iterator;
    CCARRAY_FOREACH(girls, iterator){
        GirlController* girl = (GirlController*)iterator;
        //isRunnning判断fish是否已经在屏幕上显示
        if(girl->isRunning() && isPapaw){
            CCRect girlCollisionArea = girl->getCollisionArea();
            //两个矩形是否有交叉区域
			
			CCLog("isRunning");
			char x[10] = "girl x ";
			char y[10] = "girl y ";;
			sprintf(x, "%.0f",girl->getPositionX());
			sprintf(y, "%.0f",girl->getPositionY());
			CCLog(x);
			CCLog(y);
			char px[10] = "papaw x ";
			char py[10] = "papaw y ";;
			sprintf(px, "%.0f",papaw->getPositionX());
			sprintf(py, "%.0f",papaw->getPositionY());
			CCLog(px);
			CCLog(py);
			
            bool isCollision = girlCollisionArea.intersectsRect(papawCollision);
            if(isCollision){
                CCLog("fishWillBeCaught");
				this->setIsPapaw(false);
				//_infoLayer.gamemark->addnumber(200);
				_infoLayer->addMark(1);
				_infoLayer->subGold(1);
				this->girlWillBeCaught(girl);
            }
        }
    }
	CCARRAY_FOREACH(boys, iterator){
        BoyController* boy = (BoyController*)iterator;
        //isRunnning判断fish是否已经在屏幕上显示
        if(boy->isRunning() && isPapaw){
            CCRect girlCollisionArea = boy->getCollisionArea();
            //两个矩形是否有交叉区域
			
			
			
            bool isCollision = girlCollisionArea.intersectsRect(papawCollision);
            if(isCollision){                
				this->setIsPapaw(false);
				//_infoLayer.gamemark->addnumber(200);				
				this->boyWillBeCaught(boy);
            }
        }
    }
}

void GameScene::girlWillBeCaught(GirlController* girl)
{
    
	/*
	
	CCArray* girls = _girlLayer->getGirls();
    CCObject* iterator;
    CCARRAY_FOREACH(girls, iterator){
        GirlController* newgirl = (GirlController*)iterator;
		newgirl->stopAllActions();
		//if(newgirl != girl)
		//newgirl->removeFromParent();
	}
	*/
	girl->beCaught();
	/*
	int weaponType = 1;
    int girlType = 1;
    float girl_percentage = STATIC_DATA_FLOAT(CCString::createWithFormat(STATIC_DATA_STRING("fish_percentage_format"),girlType)->getCString());
    float weapon_percentage = STATIC_DATA_FLOAT(CCString::createWithFormat(STATIC_DATA_STRING("weapon_percentage_format"),weaponType)->getCString());
    float percentage = weapon_percentage * girl_percentage;
    if(CCRANDOM_0_1() < percentage){
        girl->beCaught();
        
        //int reward = STATIC_DATA_INT(CCString::createWithFormat(STATIC_DATA_STRING("reward_format"),fishType)->getCString());
        //this->alterGold(reward);
    }
	*/
}
void GameScene::boyWillBeCaught(BoyController* boy)
{
    
	/*
	
	CCArray* girls = _girlLayer->getGirls();
    CCObject* iterator;
    CCARRAY_FOREACH(girls, iterator){
        GirlController* newgirl = (GirlController*)iterator;
		newgirl->stopAllActions();
		//if(newgirl != girl)
		//newgirl->removeFromParent();
	}
	*/
	CCDirector::sharedDirector()->replaceScene(GameMenu::scene());
}