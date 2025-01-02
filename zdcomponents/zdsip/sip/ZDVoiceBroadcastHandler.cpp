#include "ZDVoiceBroadcastHandler.h"

CZDVoiceBroadcastHandler::CZDVoiceBroadcastHandler()
{
}

CZDVoiceBroadcastHandler::~CZDVoiceBroadcastHandler()
{
}

bool CZDVoiceBroadcastHandler::OnReceive(pjsip_rx_data* rdata)
{
	if (PJSIP_OTHER_METHOD == rdata->msg_info.cseq->method.id)
	{
		CZDXmlParser xmlParser(CZDSipContext::GetInstance().GetMessageBody(rdata));
		CZDDynamicStruct dynamicStruct;
		dynamicStruct.Set(xmlParser.GetXml());

		auto cmd = xmlParser.GetXml()->RootElement()->Value();
		auto cmdType = dynamicStruct.Get("CmdType");
		if ("Broadcast" != cmdType)
			return false;

		CMyBroadcastInfo broadcastInfo;
		broadcastInfo.deviceID = dynamicStruct.Get("DeviceID");
		broadcastInfo.result = dynamicStruct.Get("Result");

		if (m_dataCB)
			m_dataCB(m_handleType, m_user, &broadcastInfo);

		Response(rdata, PJSIP_SC_OK, NoHead);
		return true;
	}

	return false;
}
