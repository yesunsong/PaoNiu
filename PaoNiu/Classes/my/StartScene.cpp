//
//  StartScene.cpp
//  PaoNiu
//
//  Created by 叶孙松 on 14-1-7.
//
//

#include "StartScene.h"
#include "StartLayer.h"

//StartScene* StartScene::scene(){
//    CCScene *scene=CCScene::create();
//    return scene;
//}

bool StartScene::init(){
    if (!CCScene::init()) {
        return false;
    }

    CCTextureCache::sharedTextureCache()->addImage("fishingjoy_resource.png");
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("fishingjoy_resource.plist");
    
    addChild(StartLayer::create());
    return true;
}
