//
//  MainDelegate.h
//  PaoNiu
//
//  Created by 叶孙松 on 14-1-8.
//
//

#ifndef __PaoNiu__MainDelegate__
#define __PaoNiu__MainDelegate__

#include <iostream>
class MainDelegate{
public:
    virtual void openHelpPage();
    virtual void openStorePage();
    virtual void openHPropPage();
    virtual void openSettingPage();
    virtual void openMailPage();
    virtual void turnToMainGame();
};

#endif /* defined(__PaoNiu__MainDelegate__) */
