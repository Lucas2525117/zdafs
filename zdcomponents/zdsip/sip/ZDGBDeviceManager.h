#ifndef _ZD_GB_DEVICE_MANAGER_H_
#define _ZD_GB_DEVICE_MANAGER_H_

#include "ZDGBDevice.h"
#include <unordered_map>
#include <mutex>

class CZDGBDeviceManager
{
public:
	static CZDGBDeviceManager& GetInstance()
	{
		static CZDGBDeviceManager mgr;
		return mgr;
	}

	// �����豸���
	ZDGBDevicePtr Add(const std::string& user, const std::string& addr, int port);

	// �����豸ɾ��
	void Remove(const std::string& user);

	// ��ȡȫ���豸
	std::unordered_map<std::string, ZDGBDevicePtr>& GetAllDevice();

	ZDGBDevicePtr GetDeviceById(const std::string& gbid);

private:
	CZDGBDeviceManager();
	~CZDGBDeviceManager();

private:
	typedef std::unordered_map<std::string, ZDGBDevicePtr> GBDeviceGroupMap;
	GBDeviceGroupMap m_devices;

	typedef std::lock_guard<std::recursive_mutex> RecursiveGuard;
	std::recursive_mutex m_recursive_mutex;   //�ݹ���
};

#endif //_ZD_GB_DEVICE_MANAGER_H_

