//
//  DynamicData.h
//  FishingJoy
//
//  Created by Ringo_D on 12-9-30.
//
//

#ifndef _DynamicData_h_
#define _DynamicData_h_
#include "cocos2d.h"
class DynamicData : public cocos2d::CCObject
{
public:
    static DynamicData* sharedDynamicData();

	CC_SYNTHESIZE(int , _mark, Mark);


    CC_SYNTHESIZE(int , _gold, Gold);
    CC_SYNTHESIZE(bool, _isBeginner, IsBeginner);
    CC_SYNTHESIZE(float, _soundVolume, SoundVolume);
    CC_SYNTHESIZE(float, _musicVolume, MusicVolume);
    
    /**
     *	@brief	 内存不足时调用
     */
    void purge();
    
    /**
     *	@brief	 将数据从内存保存到外部文件中
     */
    void flush();
    
    /**
     *	@brief	 对Gold的操作
     *
     *	@param 	delta 	正负值均可
     */
    void alterGold(int delta);
    /**
     *	@brief	 重置游戏数据为默认数值
     */
    void reset();
protected:
    DynamicData();
    ~DynamicData();
    bool init();
};

#endif /* defined(__FishingJoy__DynamicData__) */
