/*
 * ÍøÂçÁ¬½ÓÄ£¿é
 * NetConnect.h
 * 
 * Created by fansy [2013-6-30]
 */


#ifndef _NET_CONNECTION_H_
#define _NET_CONNECTION_H_

#include <cocos2d.h>

USING_NS_CC;

class NetConnect: public CCObject
{
public:
	

	virtual bool init();

	void getData();

	void httpReqFinished(CCNode* node,CCObject* obj);

	CREATE_FUNC(NetConnect);

};


#endif