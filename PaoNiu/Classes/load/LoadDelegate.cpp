//
//  LoadDelegate.cpp
//  PaoNiu
//
//  Created by 叶孙松 on 14-1-8.
//
//

#include "LoadDelegate.h"
#include <iostream>
#include "MainScene.h"

void LoadDelegate::loadFinsh(){
    std::cout<<"load fish"<<std::endl;
    CCDirector::sharedDirector()->replaceScene(MainScene::create());
}