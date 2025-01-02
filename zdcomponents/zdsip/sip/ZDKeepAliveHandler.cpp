#include "ZDKeepAliveHandler.h"

bool CZDKeepAliveHandler::OnReceive(pjsip_rx_data* rdata)
{
	if (PJSIP_OTHER_METHOD == rdata->msg_info.cseq->method.id)
	{
		CZDXmlParser xmlParser(CZDSipContext::GetInstance().GetMessageBody(rdata));
		CZDDynamicStruct dynamicStruct;
		dynamicStruct.Set(xmlParser.GetXml());
		std::string cmd = xmlParser.GetXml()->RootElement()->Value();
		std::string cmdType = dynamicStruct.Get("CmdType");
		if ("Notify" != cmd || "Keepalive" != cmdType) 
			return false;

		CZDSipContext::GetInstance().Response(rdata, PJSIP_SC_OK, NoHead);
	}

	return true;
}