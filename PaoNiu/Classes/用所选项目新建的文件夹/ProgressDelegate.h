//
//  ProgressProtocol.h
//  FishingJoy
//
//  Created by Ringo_D on 12-9-30.
//
//

#ifndef _ProgressProtocol_h
#define _ProgressProtocol_h
class ProgressDelegate
{
public:
    virtual void loadingFinished() = 0;
    virtual void progressPercentageSetter(float percentage){return;};
};


#endif
