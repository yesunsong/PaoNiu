#include "NetConnect.h"
#include "cocos-ext.h"   

USING_NS_CC_EXT; 



void NetConnect::getData()
{
	CCHttpClient* httpClient = CCHttpClient::getInstance();

	CCHttpRequest* httpReq =new CCHttpRequest();

	httpReq->setRequestType(CCHttpRequest::kHttpGet);
	httpReq->setUrl("http://www.baidu.com");
	httpReq->setResponseCallback(this,callfuncND_selector(NetConnect::httpReqFinished));
	httpReq->setTag("FirstNet");
	httpClient->setTimeoutForConnect(30);
	httpClient->send(httpReq);

	httpReq->release();

}

void NetConnect::httpReqFinished( CCNode* node,CCObject* obj )
{
	CCHttpResponse* response = (CCHttpResponse*)obj;
	if (!response->isSucceed())
	{
		CCLog("Receive Error! %s\n",response->getErrorBuffer());
		return ; 
	}

	const char* tag = response->getHttpRequest()->getTag();
	if ( 0 == strcmp("FirstNet",tag))
	{
		std::vector<char> *data = response->getResponseData();
		int data_length =  data->size();
		std::string res;
		for (int i = 0;i<data_length;++i)
		{
			res+=(*data)[i];
		}
		res+='\0';
		CCLog("%s",res.c_str());
	}
}