#include "InfoLayer.h"
#include "GameMenuScene.h"

#include "DynamicData.h"
USING_NS_CC;

//float mTime= 60;
/*
CCScene* InfoLayer::scene()
{
    CCScene *scene = CCScene::create();
    
    InfoLayer *layer = InfoLayer::create();
    
    scene->addChild(layer);
    
    return scene;
}
*/
bool InfoLayer::init(){ 
  
	if ( !CCLayer::init() )
	{
		return false;
	}

  
	gamemark = new MarkController();
    addChild(gamemark,4);

	//gamemark->mark = 0;
	gameGold = new GoldController();
	
	//gameGold->setGold(100);

    addChild(gameGold,5);



	//计时器的显示label

	//m_time0 = 60;

	CCSize size = CCDirector::sharedDirector()->getWinSize();
	lfTime = CCLabelBMFont::create("0", "bitmapFontTest4.fnt");
	this->addChild(lfTime);
	lfTime->setPosition(ccp(size.width/2,size.height-20));
		 //初始化时间变量
	mTime=60;
	gameTimer(0);

	//addMark(0);
	//subGold(0);
        //开始计时
	schedule(schedule_selector(InfoLayer::gameTimer));


    //CCLabelTTF *label = CCLabelTTF::create("i from Layer", "Marker Felt", 48); 
    //    // 获取窗体的尺寸 
    //CCSize size = CCDirector::sharedDirector()->getWinSize(); 
    //label->setPosition(ccp(size.width/2, size.height/2 + 100)); 
    //this->addChild(label, 0); 
  
  
  
    return true; 
}

void InfoLayer::gameTimer(float dt)
{
	
	mTime -= dt;
    char time[10] = {0};
    sprintf(time, "%2.1f", mTime);
    lfTime->setString(time);
	if(mTime < 0)
	CCDirector::sharedDirector()->replaceScene(GameMenu::scene());
	
}

void InfoLayer::addMark(int addMark){ 
  
	gamemark->addnumber(addMark);
}
void InfoLayer::subGold(int subGold){ 
  
	gameGold->subNumber(subGold);
}