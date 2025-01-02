#ifndef _ZD_DOWNLOAD_HANDLER_H_
#define _ZD_DOWNLOAD_HANDLER_H_

#include "ZDEventHandler.h"
#include "ZDXmlParser.h"
#include "ZDDynamicStruct.h"
#include "ZDSipContext.h"
#include "ZDSipInfo.h"

class CZDDownloadHandler : public CZDEventHandler
{
public:
	CZDDownloadHandler();
	virtual ~CZDDownloadHandler();

	virtual bool OnReceive(pjsip_rx_data* rdata) override;
};

#endif // _ZD_DOWNLOAD_HANDLER_H_

