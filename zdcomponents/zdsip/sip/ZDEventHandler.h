#ifndef _ZD_EVENT_HANDLER_H_
#define _ZD_EVENT_HANDLER_H_

#include "ZDSipContext.h"
#include "SipSDKPublic.h"

class CZDEventHandler
{
public:
	CZDEventHandler() {}
	~CZDEventHandler() {}

	virtual bool OnReceive(pjsip_rx_data* rdata) = 0;

	void RegisterCallback(int type, DataCallback dataCB, void* user);

protected:
	void Response(pjsip_rx_data* rdata, int st_code, int headType, const std::string& text = "", int subType = SUBTYPE_XML);

	int             m_handleType   = 0;
	DataCallback    m_dataCB = nullptr;
	void*           m_user   = nullptr;
};

typedef std::shared_ptr<CZDEventHandler> ZDEventHandlerPtr;

#endif // _ZD_EVENT_HANDLER_H_

