#ifndef _ZD_SIP_MODULE_H_
#define _ZD_SIP_MODULE_H_

#include "ZDSipContext.h"
#include "ZDEventHandler.h"
#include "SipSDKPublic.h"
#include "ZDSipHeader.h"
#include "ZDRegisterHandler.h"
#include "ZDKeepAliveHandler.h"
#include "ZDCatalogRecvHandler.h"
#include "ZDDeviceInfoHandler.h"
#include "ZDDeviceStatusHandler.h"
#include "ZDRecordInfoHandler.h"
#include "ZDDownloadHandler.h"
#include "ZDAlarmHandler.h"
#include "ZDVoiceBroadcastHandler.h"
#include "ZDInviteHandler.h"
#include "ZDByeHandler.h"
#include "ZDDeviceConfigHandler.h"
#include <vector>
#include <memory>

class CZDSipModule
{
public:
	static CZDSipModule& GetInstance()
	{
		static CZDSipModule module;
		return module;
	}

	bool Init();

	void RegisterHandler(int type, DataCallback dataCB, void* user);

	void OnSubNotify(pjsip_rx_data* rdata);

private:
	CZDSipModule();
	~CZDSipModule();

	static pj_bool_t OnReceive(pjsip_rx_data* rdata)
	{
		RecursiveGuard mtx(GetInstance().rmutex_);
		for (auto& handle : GetInstance().m_handlers)
		{
			if(handle)
				handle->OnReceive(rdata);
		}
		return PJ_TRUE;
	}

private:
	std::vector<ZDEventHandlerPtr> m_handlers;
	pjsip_module* m_module;

	typedef std::lock_guard<std::recursive_mutex> RecursiveGuard;
	std::recursive_mutex rmutex_;
};

#endif // _ZD_SIP_MODULE_H_

