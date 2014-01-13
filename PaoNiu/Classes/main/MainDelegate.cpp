//
//  MainDelegate.cpp
//  PaoNiu
//
//  Created by 叶孙松 on 14-1-8.
//
//

#include "MainDelegate.h"
#include "cocos2d.h"
#include "SettingScene.h"
#include "GameScene.h"
USING_NS_CC;

void MainDelegate::openHelpPage(){
    std::cout<<"openHelpPage"<<std::endl;
}

void MainDelegate::openStorePage(){
    std::cout<<"openStorePage"<<std::endl;
}

void MainDelegate::openHPropPage(){
    std::cout<<"penHPropPage"<<std::endl;
}

void MainDelegate::openSettingPage(){
    std::cout<<"openSettingPage"<<std::endl;
    CCDirector::sharedDirector()->replaceScene(SettingScene::create());
}

void MainDelegate::openMailPage(){
    std::cout<<"openMailPage"<<std::endl;
}

void MainDelegate::turnToMainGame(){
    std::cout<<"turnToMainGame"<<std::endl;
    CCDirector::sharedDirector()->replaceScene(GameScene::create());
}