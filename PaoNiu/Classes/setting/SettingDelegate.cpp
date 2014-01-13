//
//  SettingDelegate.cpp
//  PaoNiu
//
//  Created by 叶孙松 on 14-1-8.
//
//

#include "SettingDelegate.h"
#include "MainScene.h"

void SettingDelegate::backToMain(){
    std::cout<<"backToMain"<<std::endl;
    CCDirector::sharedDirector()->replaceScene(MainScene::create());
}

void SettingDelegate::sendFeedback(){
    std::cout<<"sendFeedback"<<std::endl;
}