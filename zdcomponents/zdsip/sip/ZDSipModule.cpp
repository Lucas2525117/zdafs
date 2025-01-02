#include "ZDSipModule.h"

CZDSipModule::CZDSipModule()
{
}

CZDSipModule::~CZDSipModule()
{
}

bool CZDSipModule::Init()
{
	static struct pjsip_module m =
	{
		nullptr, nullptr,
		{ (char*)"sipcontrolmodule", 16 },
		-1,
		PJSIP_MOD_PRIORITY_APPLICATION,
		nullptr,
		nullptr,
		nullptr,
		nullptr,
		&CZDSipModule::OnReceive,
		nullptr,
		nullptr,
		nullptr,
		nullptr,
	};

	m_module = &m;
	return CZDSipContext::GetInstance().RegisterModule(m_module);
}

void CZDSipModule::RegisterHandler(int type, DataCallback dataCB, void* user)
{
	std::shared_ptr<CZDEventHandler> handle = nullptr;
	switch (type)
	{
	case Type_Register:
		handle = std::make_shared<CZDRegisterHandler>();
		break;
	case Type_KeepAlive:
		handle = std::make_shared<CZDKeepAliveHandler>();
		break;
	case Type_RecvCatalog:
		handle = std::make_shared<CZDCatalogRecvHandler>();
		break;
	case Type_RecvDeviceInfo:
		handle = std::make_shared<CZDDeviceInfoHandler>();
		break;
	case Type_RecvDeviceStatus:
		handle = std::make_shared<CZDDeviceStatusHandler>();
		break;
	case Type_RecvRecordInfo:
		handle = std::make_shared<CZDRecordInfoHandler>();
		break;
	case Type_Download:
		handle = std::make_shared<CZDDownloadHandler>();
		break;
	case Type_Alarm:
		handle = std::make_shared<CZDAlarmHandler>();
		break;
	case Type_VoiceBroadcast:
		handle = std::make_shared<CZDVoiceBroadcastHandler>();
		break;
	case Type_Invite:
	case Type_VideoInvite:
		handle = std::make_shared<CZDInviteHandler>();
		break;
	case Type_Bye:
		handle = std::make_shared<CZDByeHandler>();
		break;
	case Type_SnapShotFinished:
		handle = std::make_shared<CZDDeviceConfigHandler>();
		break;
	default:
		break;
	}

	if (handle)
	{
		handle->RegisterCallback(type, dataCB, user);
		{
			RecursiveGuard mtx(rmutex_);
			m_handlers.push_back(handle);
		}
	}
}

void CZDSipModule::OnSubNotify(pjsip_rx_data* rdata)
{
	OnReceive(rdata);
}