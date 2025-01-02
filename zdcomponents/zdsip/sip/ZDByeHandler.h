#ifndef _ZD_BYE_HANDLER_H_
#define _ZD_BYE_HANDLER_H_

#include "ZDEventHandler.h"
#include "ZDXmlParser.h"
#include "ZDDynamicStruct.h"
#include "ZDSipContext.h"
#include "ZDSipInfo.h"

class CZDByeHandler : public CZDEventHandler
{
public:
	CZDByeHandler();
	virtual ~CZDByeHandler();

	virtual bool OnReceive(pjsip_rx_data* rdata) override;
};

#endif // _ZD_BYE_HANDLER_H_

