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

	// 国标设备添加
	ZDGBDevicePtr Add(const std::string& user, const std::string& addr, int port);

	// 国标设备删除
	void Remove(const std::string& user);

	// 获取全部设备
	std::unordered_map<std::string, ZDGBDevicePtr>& GetAllDevice();

	ZDGBDevicePtr GetDeviceById(const std::string& gbid);

private:
	CZDGBDeviceManager();
	~CZDGBDeviceManager();

private:
	typedef std::unordered_map<std::string, ZDGBDevicePtr> GBDeviceGroupMap;
	GBDeviceGroupMap m_devices;

	typedef std::lock_guard<std::recursive_mutex> RecursiveGuard;
	std::recursive_mutex m_recursive_mutex;   //递归锁
};

#endif //_ZD_GB_DEVICE_MANAGER_H_

