//
//  GamePerson.cpp
//  PaoNiu
//
//  Created by 叶孙松 on 14-1-9.
//
//

#include "GamePerson.h"

GamePerson::GamePerson(){

}

GamePerson::~GamePerson(){

}

void GamePerson::setCollisionArea(cocos2d::CCRect var){

}

CCRect GamePerson::getCollisionArea(){
    return CCRectMake(0, 0, 0, 0);
}

bool GamePerson::init(){
    if (!CCNode::init()) {
        return false;
    }
    createSkin();
    return true;
}

void GamePerson::createSkin(){
    std::cout<<"create skin"<<std::endl;
}