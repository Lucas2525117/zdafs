#ifndef _ZD_DEVICECONFIG_HANDLER_H_
#define _ZD_DEVICECONFIG_HANDLER_H_

#include "ZDEventHandler.h"
#include "ZDXmlParser.h"
#include "ZDDynamicStruct.h"
#include "ZDSipContext.h"
#include "ZDSipInfo.h"

class CZDDeviceConfigHandler : public CZDEventHandler
{
public:
	CZDDeviceConfigHandler();
	virtual ~CZDDeviceConfigHandler();

	virtual bool OnReceive(pjsip_rx_data* rdata) override;
};

#endif // _ZD_DEVICECONFIG_HANDLER_H_

