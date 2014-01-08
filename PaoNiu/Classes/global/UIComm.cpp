//
//  MarketComm.cpp
//  Test
//
//  Created by 叶孙松 on 13-11-12.
//
//

#include "UIComm.h"
#include <strstream>
using namespace std;

string iToStr(int type){
    strstream ss;
    ss<<type;
    string s;
    ss>>s;
    return s;
}

CCEditBox * createEditBox(const char *pFileName,CCSize size,const char* pFontName, int fontSize,const ccColor3B& color,int maxLength,const char* pPlaceHolderText,EditBoxInputMode inputMode,EditBoxInputFlag inputFlag,KeyboardReturnType returnType){
    CCScale9Sprite *scale9Sprite=CCScale9Sprite::createWithSpriteFrameName(pFileName);
    CCEditBox *editbox=CCEditBox::create(size, scale9Sprite);
    editbox->setFontColor(color);
    editbox->setFont(pFontName, fontSize);
    editbox->setInputFlag(inputFlag);
    editbox->setPlaceHolder(pPlaceHolderText);
    editbox->setInputMode(inputMode);
    editbox->setReturnType(returnType);
    editbox->setMaxLength(maxLength);
    return editbox;
}

CCControlButton * createControlButton(const char *pUpFile,const char *pDownFile,const char *pDisableFile,CCSize preferredSize,bool zoomOnTouchDown){
    CCScale9Sprite* upSprite=CCScale9Sprite::createWithSpriteFrameName(pUpFile);
    
    CCControlButton *controlButton=CCControlButton::create(upSprite);
    if (pDownFile) {
        CCScale9Sprite* downSprite=CCScale9Sprite::createWithSpriteFrameName(pDownFile);
        controlButton->setBackgroundSpriteForState(downSprite, CCControlStateHighlighted);
    }
    if (pDisableFile) {
        CCScale9Sprite* disabledSprite=CCScale9Sprite::createWithSpriteFrameName(pDisableFile);
        controlButton->setBackgroundSpriteForState(disabledSprite, CCControlStateDisabled);
    }
    
    controlButton->setZoomOnTouchDown(zoomOnTouchDown);
    controlButton->setPreferredSize(preferredSize);
    return controlButton;
}

CCMenuItemLabel* createMenuitemLabel(const char *label){
    if (strlen(label)==0) {
        return NULL;
    }
    CCMenuItemLabel* menuItem=CCMenuItemLabel::create(CCLabelTTF::create(label, "", 20), NULL, NULL);
    return menuItem;    
}