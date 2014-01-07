#include "GirlLayer.h"
USING_NS_CC;

GirlLayer::~GirlLayer()
{
    CC_SAFE_RELEASE(_girls);
}

bool GirlLayer::init()
{
    if(CCLayer::init()){
        int capacity = 50;
        _girls = CCArray::createWithCapacity(capacity);
        CC_SAFE_RETAIN(_girls);
        
        for(int i = 0;i < capacity;i++){
            int type = CCRANDOM_0_1()*2;
            GirlController* girl = GirlController::create((GirlType)0);
            _girls->addObject(girl);
        }

		_boys = CCArray::createWithCapacity(capacity);
        CC_SAFE_RETAIN(_boys);
        
        for(int i = 0;i < capacity;i++){
            int type = CCRANDOM_0_1()*2;
            GirlController* boy = GirlController::create((GirlType)1);
            _boys->addObject(boy);
        }

        this->schedule(schedule_selector(GirlLayer::addGirl), 3.0);
		this->schedule(schedule_selector(GirlLayer::addBoy), 5.0);
        return true;
    }
    return false;
}
void GirlLayer::addGirl(float dt)
{
    int countToAdd = CCRANDOM_0_1() * 10 + 1;
    int countHasAdded = 0;
    CCObject* iterator;
    CCARRAY_FOREACH(_girls,  iterator)
	{
        GirlController* girl = (GirlController*)iterator;
        if(girl->getParent() == NULL){
            this->addChild(girl);
            this->resetGirl(girl);
            countHasAdded++;
            if(countToAdd == countHasAdded){
                break;
            }
        }
    }
}

void GirlLayer::resetGirl(GirlController* girl)
{
    girl->reset();
    CCPoint start, destination;
    float startX, startY, endX, endY;
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    CCSize girlSize = girl->getGirlSprite()->getContentSize();
    //int direction = CCRANDOM_0_1()*2;
   // if(direction)
	//{
        girl->setRotation(180);
        startY = winSize.height + girlSize.height*0.5;
        endY = -girlSize.height*0.5;
    //}
	//else
	//{
     //   girl->setRotation(0);
    //    startY = -girlSize.height*0.5;
    //    endY = winSize.height + girlSize.height*0.5;
   // }
    startX = CCRANDOM_0_1()*(winSize.width-2*girlSize.width)+girlSize.width;
    endX = startX;
    
    start = CCPointMake(startX, startY);
    destination = CCPointMake(endX, endY);
    girl->setPosition(start);
    girl->moveTo(destination);
}

void GirlLayer::addBoy(float dt)
{
    int countToAdd = CCRANDOM_0_1() * 10 + 1;
    int countHasAdded = 0;
    CCObject* iterator;
    CCARRAY_FOREACH(_boys,  iterator)
	{
        BoyController* boy = (BoyController*)iterator;
        if(boy->getParent() == NULL){
            this->addChild(boy);
            this->resetBoy(boy);
            countHasAdded++;
            if(countToAdd == countHasAdded){
                break;
            }
        }
    }
}

void GirlLayer::resetBoy(BoyController* boy)
{
    boy->reset();
    CCPoint start, destination;
    float startX, startY, endX, endY;
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    CCSize boySize = boy->getBoySprite()->getContentSize();
    //int direction = CCRANDOM_0_1()*2;
   // if(direction)
	//{
        boy->setRotation(180);
        startY = winSize.height + boySize.height*0.5;
        endY = -boySize.height*0.5;
    //}
	//else
	//{
     //   girl->setRotation(0);
    //    startY = -girlSize.height*0.5;
    //    endY = winSize.height + girlSize.height*0.5;
   // }
    startX = CCRANDOM_0_1()*(winSize.width-2*boySize.width)+boySize.width;
    endX = startX;
    
    start = CCPointMake(startX, startY);
    destination = CCPointMake(endX, endY);
    boy->setPosition(start);
    boy->moveTo(destination);
}