

#ifndef _PersonalAudioEngine_h_
#define _PersonalAudioEngine_h_
#include "SimpleAudioEngine.h"
#include "cocos2d.h"
class PersonalAudioEngine : public CocosDenshion::SimpleAudioEngine
{
public:
    void setBackgroundMusicVolume(float volume);
    void setEffectsVolume(float volume);
    
    static PersonalAudioEngine* sharedEngine();
    
    void purge();
    bool init();
protected:
    PersonalAudioEngine();
    ~PersonalAudioEngine();
};

#endif /* defined(__FishingJoy__PersonalAudioEngine__) */
