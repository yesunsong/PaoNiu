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
     *	@brief	 �ڴ治��ʱ����
     */
    void purge();
    
    /**
     *	@brief	 �����ݴ��ڴ汣�浽�ⲿ�ļ���
     */
    void flush();
    
    /**
     *	@brief	 ��Gold�Ĳ���
     *
     *	@param 	delta 	����ֵ����
     */
    void alterGold(int delta);
    /**
     *	@brief	 ������Ϸ����ΪĬ����ֵ
     */
    void reset();
protected:
    DynamicData();
    ~DynamicData();
    bool init();
};

#endif /* defined(__FishingJoy__DynamicData__) */
