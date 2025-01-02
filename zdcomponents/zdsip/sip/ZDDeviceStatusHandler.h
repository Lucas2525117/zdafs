#ifndef _ZD_DEVICESTATUS_HANDLER_H_
#define _ZD_DEVICESTATUS_HANDLER_H_

#include "ZDEventHandler.h"
#include "ZDXmlParser.h"
#include "ZDDynamicStruct.h"
#include "ZDSipContext.h"
#include "ZDSipInfo.h"

class CZDDeviceStatusHandler : public CZDEventHandler
{
public:
	CZDDeviceStatusHandler();
	virtual ~CZDDeviceStatusHandler();

	virtual bool OnReceive(pjsip_rx_data* rdata) override;
};

#endif // _ZD_DEVICESTATUS_HANDLER_H_

