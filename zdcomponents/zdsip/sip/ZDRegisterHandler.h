#ifndef _ZD_REGISTER_HANDLER_H_
#define _ZD_REGISTER_HANDLER_H_

#include "ZDGBDevice.h"
#include "ZDEventHandler.h"
#include "ZDGBDeviceManager.h"
#include <memory>
#include <winsock.h>

class CZDRegisterHandler : public CZDEventHandler
{
public:
	CZDRegisterHandler();
	virtual ~CZDRegisterHandler();

	virtual bool OnReceive(pjsip_rx_data* rdata);

	void OnWork();

private:
	void QureryDeviceInfo(pjsip_rx_data* rdata);
	void UpdateDeviceStatus_();
	void StopUpdateDeviceStatus_();

private:
	ZDGBDevicePtr                m_device;
	pj_thread_t*                 m_queryStatusThread = nullptr;
	int                          m_queryStatusInterval = 30*1000;
	bool                         m_hasDevice = false;
	bool                         m_running = true;
	std::string                  m_dstIp;
	int                          m_dstPort;
};

#endif // _ZD_REGISTER_HANDLER_H_

