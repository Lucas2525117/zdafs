#ifndef _ZD_ALARM_HANDLER_H_
#define _ZD_ALARM_HANDLER_H_

#include "ZDEventHandler.h"
#include "ZDXmlParser.h"
#include "ZDDynamicStruct.h"
#include "ZDSipContext.h"
#include "ZDSipInfo.h"

class CZDAlarmHandler : public CZDEventHandler
{
public:
	CZDAlarmHandler();
	virtual ~CZDAlarmHandler();

	virtual bool OnReceive(pjsip_rx_data* rdata) override;
};

#endif // _ZD_ALARM_HANDLER_H_

