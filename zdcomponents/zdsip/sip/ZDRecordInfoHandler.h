#ifndef _ZD_RECORDINFO_HANDLER_H_
#define _ZD_RECORDINFO_HANDLER_H_

#include "ZDEventHandler.h"
#include "ZDXmlParser.h"
#include "ZDDynamicStruct.h"
#include "ZDSipInfo.h"

class CZDRecordInfoHandler : public CZDEventHandler
{
public:
	CZDRecordInfoHandler();
	virtual ~CZDRecordInfoHandler();

	virtual bool OnReceive(pjsip_rx_data* rdata) override;
};

#endif // _ZD_RECORDINFO_HANDLER_H_

