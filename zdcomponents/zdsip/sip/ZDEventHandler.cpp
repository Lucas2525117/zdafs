#include "ZDEventHandler.h"

void CZDEventHandler::RegisterCallback(int type, DataCallback dataCB, void* user)
{
	m_handleType = type;
	m_dataCB = dataCB;
	m_user = user;
}

void CZDEventHandler::Response(pjsip_rx_data* rdata, int st_code, int headType, const std::string& text, int subType)
{
	CZDSipContext::GetInstance().Response(rdata, st_code, headType, text, subType);
}