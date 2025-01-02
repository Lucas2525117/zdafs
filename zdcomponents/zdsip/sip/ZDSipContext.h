#ifndef _ZD_SIP_CONTEXT_H_
#define _ZD_SIP_CONTEXT_H_

#include <string>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <iosfwd>
#include <sstream>
#include <thread>
#include <mutex>
#include "ZDSip.h"
#include "ZDSipHeader.h"
#include "ZDGBDevice.h"

#define NoHead     0
#define DateHead   1
#define AuthenHead 2

#define SUBTYPE_XML   0
#define SUBTYPE_SDP   1

#define SiralNum  "015359105"

class CZDSipContext
{
public:
	static CZDSipContext& GetInstance()
	{
		static CZDSipContext ctx;
		return ctx;
	}

	bool Init(const std::string& concat, int logLevel);

	bool UnInit();

	bool RegisterCallback(pjsip_inv_callback* callback);

	bool InitModule();
	bool RegisterModule(pjsip_module* module);
	bool UnRegisterModule(pjsip_module* module);

	bool CreateWorkThread(pj_thread_proc* proc, pj_thread_t* workthread, void* arg, const std::string& threadName);
	bool DestroyThread(pj_thread_t* thread);
	void PJThreadSleep(int msec);

	void HandleEvent(pj_time_val* delay);

	bool Invite(pjsip_dialog* dlg, GB28181MediaContext mediaContext, std::string sdp);

	bool Subscribe(pjsip_dialog* dlg, pjsip_evsub_user* pres_user, const std::string& eventName, const std::string& xmlText, const GBSubscribeContext& subContext);

	void Response(pjsip_rx_data* rdata, int st_code, int headType, const std::string& text = "", int subType = SUBTYPE_XML);

	pjsip_response_addr GetResponseAddr(pjsip_rx_data* rdata);

	void QueryDeviceInfo(CZDGBDevice* device, const std::string& gbid, const std::string& scheme = "Catalog");

	void QueryRecordInfo(CZDGBDevice* device, const std::string& gbid, const std::string& startTime, const std::string& endTime, const std::string& scheme);

	int VoiceBroadcast(CZDGBDevice* device, const std::string& sourceID, const std::string& targetID);

	int PTZControl(CZDGBDevice* device, const std::string& gbid, PTZControlType ptzType, int paramValue);

	std::string GetMessageBody(pjsip_rx_data* rdata);

	std::string GetConcat() { return m_concat; }

	pj_str_t StrToPjstr(const std::string& input);

	std::string GetSipIP() const;
	std::string GetSipCode() const;

	int SendSipMessage(CZDGBDevice* device, const std::string& sipMsg);

private:
	CZDSipContext();
	~CZDSipContext();

	static pj_status_t lookup(pj_pool_t* pool,
		const pj_str_t* realm,
		const pj_str_t* accName,
		pjsip_cred_info* credInfo)
	{
		return PJSIP_SC_OK;
	}

private:
	int GetPort();
	std::string GetLocalDomain();
	
	std::string ParsePTZCmd(CZDGBDevice* device, const std::string& gbid, PTZControlType ptzType, int paramValue);

private:
	std::string        m_concat;
	pj_pool_t*         m_pool = nullptr;
	pj_caching_pool    m_cachingPool;
	pjsip_endpoint*    m_endPoint = nullptr;
	pjsip_auth_srv     m_authentication;

	typedef std::lock_guard<std::recursive_mutex> RecursiveGuard;
	mutable std::recursive_mutex rmutex_;
};

#endif  // _ZD_SIP_CONTEXT_H_

