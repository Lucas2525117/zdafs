#ifndef _ZD_KEEPALIVE_HANDLER_H_
#define _ZD_KEEPALIVE_HANDLER_H_

#include "ZDEventHandler.h"
#include "ZDSipContext.h"
#include "ZDXmlParser.h"
#include "ZDDynamicStruct.h"
#include <string>

class CZDKeepAliveHandler : public CZDEventHandler
{
public:
	CZDKeepAliveHandler() {}

	virtual bool OnReceive(pjsip_rx_data* rdata) override;
};

#endif // _ZD_KEEPALIVE_HANDLER_H_

