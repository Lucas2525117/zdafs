#ifndef _ZD_XML_PARSER_H_
#define _ZD_XML_PARSER_H_

#include "windows.h"
#include "tinyxml.h"
#include <string>
#include <stringapiset.h>
#include <memory>
#include <sstream>

#define MaxXmlLength (10 *1024)
#define Times 2

class CZDXmlParser
{
public:
	CZDXmlParser(std::string url);
	~CZDXmlParser();

    std::shared_ptr<TiXmlDocument> GetXml() { return m_xml;}

private:
	char* UnicodeToGB2312(const char* src);
	char* GB2312ToUnicode(const char* src, int len);

    std::string StrReplace(std::string str, const std::string& from, const std::string& to);

private:
    typedef std::shared_ptr<TiXmlDocument> TiXmlDocumentPtr;
    TiXmlDocumentPtr m_xml;
};

#endif

