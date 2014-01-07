//#include "GameController.h"

//USING_NS_CC;
//using namespace cocos2d;

#include "GameController.h";

//USING_NS_CC;
USING_NS_CC;
/*
CCScene* GameController::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    GameController *layer = GameController::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}
*/
// on "init" you need to initialize your instance
bool GameController::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
	/*
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(GameController::menuCloseCallback));
    
	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
                                origin.y + pCloseItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);
	*/
    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    CCLabelTTF* pLabel = CCLabelTTF::create("Hello World", "Arial", 24);
    
    // position the label on the center of the screen
    pLabel->setPosition(ccp(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - pLabel->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(pLabel, 1);

    // add "HelloWorld" splash screen"
    CCSprite* pSprite = CCSprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(pSprite, 0);


	view = GameScene::create();
    this->addChild(view, 0); 
    
    return true;
}
/*
bool GameController::init(){ 
    bool bRet = false; 
    do{ 
        // �ȵ��ó����init���� 
        //CC_BREAK_IF(! CCLayer::init()); 

		// 1. super init first
		if ( !CCLayer::init() )
		{
			return false;
		}
  
        view = GameScene::create();
        this->addChild(view, 0); 
  
        bRet = true; 
    }while(0) ;
  
    return bRet; 
} 

CCScene* GameController::scene(){ 
    CCScene *scene = NULL; 
    do{ 
        scene = CCScene::create();
        CC_BREAK_IF(!scene); 
  
        GameController *layer = GameController::create();
        CC_BREAK_IF(!layer); 
  
        scene->addChild(layer); 
    }while(0); 
  
    return scene; 
}
*/