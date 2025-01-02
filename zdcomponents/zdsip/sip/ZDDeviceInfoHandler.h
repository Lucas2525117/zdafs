#ifndef _ZD_DEVICEINFO_HANDLER_H_
#define _ZD_DEVICEINFO_HANDLER_H_

#include "ZDEventHandler.h"
#include "ZDXmlParser.h"
#include "ZDDynamicStruct.h"
#include "ZDSipContext.h"
#include "ZDSipInfo.h"

class CZDDeviceInfoHandler : public CZDEventHandler
{
public:
	CZDDeviceInfoHandler();
	virtual ~CZDDeviceInfoHandler();

	virtual bool OnReceive(pjsip_rx_data* rdata) override;
};

#endif // _ZD_DEVICEINFO_HANDLER_H_

