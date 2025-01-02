#ifndef _ZD_VOICE_BROADCAST_HANDLER_H_
#define _ZD_VOICE_BROADCAST_HANDLER_H_

#include "ZDEventHandler.h"
#include "ZDXmlParser.h"
#include "ZDDynamicStruct.h"
#include "ZDSipContext.h"
#include "ZDSipInfo.h"

class CZDVoiceBroadcastHandler : public CZDEventHandler
{
public:
	CZDVoiceBroadcastHandler();
	virtual ~CZDVoiceBroadcastHandler();

	virtual bool OnReceive(pjsip_rx_data* rdata) override;
};

#endif  // _ZD_VOICE_BROADCAST_HANDLER_H_

