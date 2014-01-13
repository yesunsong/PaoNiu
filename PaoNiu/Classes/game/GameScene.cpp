//
//  GameScene.cpp
//  PaoNiu
//
//  Created by 叶孙松 on 14-1-8.
//
//

#include "GameScene.h"
#include "GameLayer.h"
#include "GameInfoLayer.h"
#include "GameDelegate.h"

bool GameScene::init(){
    if (!CCScene::init()) {
        return false;
    }
    GameDelegate* delegate=new GameDelegate();
    
    GameInfoLayer *infoLayer=GameInfoLayer::create();
    infoLayer->setDelegate(delegate);
    addChild(infoLayer);
    
    GameLayer* gameLayer=GameLayer::create();
    addChild(gameLayer);
    
    return true;
}