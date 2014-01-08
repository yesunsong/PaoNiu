//
//  StartScene.cpp
//  PaoNiu
//
//  Created by 叶孙松 on 14-1-7.
//
//

#include "LoginScene.h"
#include "LoginLayer.h"

bool LoginScene::init(){
    if (!CCScene::init()) {
        return false;
    }

    CCTextureCache::sharedTextureCache()->addImage("fishingjoy_resource.png");
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("fishingjoy_resource.plist");
    
    LoginDelegate* delegate=new LoginDelegate();
    
    LoginLayer* startLayer=LoginLayer::create();
    startLayer->setDelegate(delegate);
    addChild(startLayer);
    return true;
}