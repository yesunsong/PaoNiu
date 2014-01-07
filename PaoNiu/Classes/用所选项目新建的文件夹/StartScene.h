//
//  StartScene.h
//  FishingJoy
//
//  Created by Ringo_D on 12-9-8.
//
//

#ifndef _StartScene_h_
#define _StartScene_h_
#include "cocos2d.h"
#include "ProgressDelegate.h"
#include "ProgressBar.h"

USING_NS_CC;

class StartScene : public cocos2d::CCLayer, public ProgressDelegate
{
public:
    static cocos2d::CCScene* scene();
    bool init();
    CREATE_FUNC(StartScene);
    void loadingFinished();
    void progressPercentageSetter(float percentage);

protected:
    ProgressBar* _progressBar;
    cocos2d::CCLabelTTF* _progressFg;
    void transition(CCObject* pSender);
    void loading(CCObject* pObj);
    void cacheInit();
    void audioAndUserDataInit();
    void initializationCompleted();
};
#endif 
