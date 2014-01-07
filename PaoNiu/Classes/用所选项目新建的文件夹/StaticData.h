//
//  StaticData.h
//  FishingJoy
//
//  Created by Ringo_D on 12-9-25.
//
//

#ifndef _StaticData_h_
#define _StaticData_h_

#include "cocos2d.h"
#define STATIC_DATA_STRING(key) StaticData::sharedStaticData()->stringFromKey(key)
#define STATIC_DATA_INT(key) StaticData::sharedStaticData()->intFromKey(key)
#define STATIC_DATA_FLOAT(key) StaticData::sharedStaticData()->floatFromKey(key)
#define STATIC_DATA_BOOLEAN(key) StaticData::sharedStaticData()->booleanFromKey(key)
#define STATIC_DATA_POINT(key) StaticData::sharedStaticData()->pointFromKey(key)
#define STATIC_DATA_RECT(key) StaticData::sharedStaticData()->rectFromKey(key)
#define STATIC_DATA_SIZE(key) StaticData::sharedStaticData()->sizeFromKey(key)

class StaticData : public cocos2d::CCObject
{
public:    
    static StaticData* sharedStaticData();

    /**
     *	@brief	 �ⲿ���ʽӿ�
     *
     *	@param 	key 	��Ӧ��static_data.plist�е�Key
     *
     *	@return	��Ӧ��Value
     */
    const char* stringFromKey(std::string key);
    int intFromKey(std::string key);
    float floatFromKey(std::string key);
    bool booleanFromKey(std::string key);
    cocos2d::CCPoint pointFromKey(std::string key);
    cocos2d::CCRect rectFromKey(std::string key);
    cocos2d::CCSize sizeFromKey(std::string key);
    
    /**
     *	@brief	 �ڴ治��ʱ����
     */
    void purge();
    
    CC_SYNTHESIZE_READONLY(std::string, _staticDataPath, StaticDataPath);

protected:
    cocos2d::CCDictionary* _dictionary;
private:
    StaticData();
    ~StaticData();
    bool init();
};
#endif /* defined(__FishingJoy__StaticData__) */
