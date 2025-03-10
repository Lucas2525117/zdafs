#ifndef _ZD_CATALOG_RECV_HANDLER_H_
#define _ZD_CATALOG_RECV_HANDLER_H_

#include "ZDEventHandler.h"
#include "ZDXmlParser.h"
#include "ZDDynamicStruct.h"
#include "ZDSipContext.h"
#include "ZDSipInfo.h"
#include <string>

class CZDCatalogRecvHandler : public CZDEventHandler
{
public:
	CZDCatalogRecvHandler();
	virtual ~CZDCatalogRecvHandler();

	virtual bool OnReceive(pjsip_rx_data* rdata) override;

private:
	static std::string WstringToString(const std::wstring& widestring)
	{
		std::locale mLocale("");

		auto srcStr = widestring.c_str();
		auto srcLastStr = widestring.c_str() + widestring.size();
		const wchar_t* data_from_next = nullptr;

		auto wcharSize = 4;
		auto dstStr = new char[(widestring.size() + 1) * wcharSize];
		auto dstLastStr = dstStr + (widestring.size() + 1) * wcharSize;
		char* data_to_next = nullptr;

		memset(dstStr, 0, (widestring.size() + 1) * wcharSize);

		typedef std::codecvt<wchar_t, char, mbstate_t> convert_facet;
		mbstate_t state = { 0 };
		auto result = std::use_facet<convert_facet>(mLocale).out(
			state, srcStr, srcLastStr, data_from_next,
			dstStr, dstLastStr, data_to_next);
		if (result == convert_facet::ok)
		{
			std::string dst = dstStr;
			delete[] dstStr;
			return dst;
		}
		else
		{
			delete[] dstStr;
			return std::string("");
		}
	}
};

#endif // _ZD_CATALOG_RECV_HANDLER_H_

