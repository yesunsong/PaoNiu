#include "GameScene.h"
#include "GameMenuScene.h"


USING_NS_CC;

int addMark = 1;
int subGold = 1;

bool GameScene::init(){
	if ( !CCScene::init())
	{
		return false;
	}
    
//	_infoLayer = InfoLayer::create();
//	this->addChild(_infoLayer,0);
//	_infoLayer->gameGold->setGold(100);
    
	_girlLayer = GirlLayer::create();
	this->addChild(_girlLayer,0);
    
    //网
	_gameLayer = GameLayer::create();
	this->addChild(_gameLayer,1);
    
	_touch = TouchController::create();
    this->addChild(_touch);
	_touch->setTouchEnabled(true);
    
    
    this->setIsPapaw(false);
	this->scheduleUpdate();
    return true;
}
void GameScene::update(float delta)
{
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
//	if(_infoLayer->gameGold->gold > 0)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
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
        //isRunnning≈–∂œfish «∑Ò“—æ≠‘⁄∆¡ƒª…œœ‘ æ
        if(girl->isRunning() && isPapaw){
            CCRect girlCollisionArea = girl->getCollisionArea();
            //¡Ω∏ˆæÿ–Œ «∑Ò”–Ωª≤Ê«¯”Ú
			
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
				this->girlWillBeCaught(girl);
            }
        }
    }
    
	CCARRAY_FOREACH(boys, iterator){
        BoyController* boy = (BoyController*)iterator;
        //isRunnning≈–∂œfish «∑Ò“—æ≠‘⁄∆¡ƒª…œœ‘ æ
        if(boy->isRunning() && isPapaw){
            CCRect girlCollisionArea = boy->getCollisionArea();
			
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
	girl->beCaught();
}
void GameScene::boyWillBeCaught(BoyController* boy)
{
	CCDirector::sharedDirector()->replaceScene(GameMenu::scene());
}