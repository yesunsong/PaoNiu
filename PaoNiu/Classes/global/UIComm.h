//
//  MarketComm.h
//  Test
//
//  Created by 叶孙松 on 13-11-12.
//
//

#ifndef __Test__MarketComm__
#define __Test__MarketComm__

#include "cocos2d.h"
#include "cocos-ext.h"
#include <vector>
USING_NS_CC;
USING_NS_CC_EXT;
using namespace std;

string iToStr(int type);

CCEditBox * createEditBox(const char *pFileName,CCSize size,const char* pFontName, int fontSize,const ccColor3B& color,int maxLength,const char* pPlaceHolderText,EditBoxInputMode inputMode,EditBoxInputFlag inputFlag,KeyboardReturnType returnType);

CCControlButton * createControlButton(const char *pUpFile,const char *pDownFile,const char *pDisableFile,CCSize preferredSize,bool zoomOnTouchDown=false);

CCMenuItemLabel* createMenuitemLabel(const char *label);

#endif /* defined(__Test__MarketComm__) */