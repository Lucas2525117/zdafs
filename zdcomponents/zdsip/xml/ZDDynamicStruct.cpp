#include "ZDDynamicStruct.h"

CZDDynamicStruct::CZDDynamicStruct()
{
}

CZDDynamicStruct::~CZDDynamicStruct()
{
}

void CZDDynamicStruct::Set(std::shared_ptr<TiXmlDocument> xml)
{
	TiXmlNode* rootNode = xml->RootElement();
	m_option = StructAdd(rootNode);
}

void CZDDynamicStruct::Set(std::string key, std::string value)
{
	m_option[key] = value;
}

bool CZDDynamicStruct::Has(std::string key)
{
	return m_option.find(key) != m_option.end();
}

DynamicStruct CZDDynamicStruct::StructAdd(TiXmlNode* rootNode)
{
	DynamicStruct result;
	for (auto node = rootNode->FirstChild(); node != nullptr; node = node->NextSibling())
	{
		if (node->Type() != TiXmlNode::TINYXML_DOCUMENT)
		{
			std::string key = node->Value();
			if (isArray(node))
			{
				Json::Value records;
				if (0 == key.compare("DeviceList")
					|| 0 == key.compare("RecordList")
					|| 0 == key.compare("SnapShotList"))
				{
					DeviceListAdd(node, records);
				}
		
				if (!records.empty()) 
					result.insert(std::make_pair(key, records.toStyledString()));
			}
			else if (isTextNode(node))
			{
				// ·ÀÖ¹±ÀÀ£
				if (0 == key.compare("Info"))
					continue;

				result.insert(std::make_pair(key, GetNodeValue(node)));
			}
		}
	}

	return result;
}

void CZDDynamicStruct::DeviceListAdd(TiXmlNode* rootNode, Json::Value& records)
{
	for (auto node = rootNode->FirstChild(); node != nullptr; node = node->NextSibling())
	{
		if (node->Type() != TiXmlNode::TINYXML_DOCUMENT)
		{
			auto itemElement = node->ToElement();
			Json::Value record;
			for (auto element = itemElement->FirstChildElement();
				element;
				element = element->NextSiblingElement())
			{
				std::string value = element->GetText();
				record[element->Value()] = value.c_str();
			}

			records.append(record);
		}
	}
}
