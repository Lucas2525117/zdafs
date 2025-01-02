// �豸����(������)
#ifndef _GB_DEVICECONTROL_H_
#define _GB_DEVICECONTROL_H_

#include <string>
#include "ZDGBDeviceManager.h"
#include "ZDGBDevice.h"
#include "ZDSipContext.h"
#include "ZDSipInfo.h"
#include "json/json.h"

class CGBDeviceControl
{
public:
	static CGBDeviceControl& GetInstance()
	{
		static CGBDeviceControl gbDeviceControl;
		return gbDeviceControl;
	}

	int SetCommand(const std::string& gbid, const std::string& method, const std::string& request);

private:
	static std::string GetControlSN()
	{
		static std::recursive_mutex mutex_;
		static unsigned int m_sn = 1;
		std::ostringstream sn;

		RecursiveGuard mtx(mutex_);
		sn << m_sn++;
		return sn.str();
	}

	// ��̨����
	int PTZControl_(CZDGBDevice* device, const std::string& deviceID, const std::string& request);

	// Զ������
	int TeleRebootControl_(CZDGBDevice* device, const std::string& deviceID, const std::string& request);

	// ¼�����
	int RecordControl_(CZDGBDevice* device, const std::string& deviceID, const std::string& request);

	// ����/����
	int GuardControl_(CZDGBDevice* device, const std::string& deviceID, const std::string& request);

	// ������λ
	int AlarmResetControl_(CZDGBDevice* device, const std::string& deviceID, const std::string& request);

	// ǿ�ƹؼ�֡(�豸�յ����������̷���һ��IDR֡)
	int IFrameControl_(CZDGBDevice* device, const std::string& deviceID, const std::string& request);

	// ����Ŵ�
	int DragZoomInControl_(CZDGBDevice* device, const std::string& deviceID, const std::string& request);

	// ������С
	int DragZoomOutControl_(CZDGBDevice* device, const std::string& deviceID, const std::string& request);

	// ����λ����
	int HomePositionControl_(CZDGBDevice* device, const std::string& deviceID, const std::string& request);

	// PTZ��׼����
	int PTZPreciseControl_(CZDGBDevice* device, const std::string& deviceID, const std::string& request);

	// �豸�������
	int DeviceUpgradeControl_(CZDGBDevice* device, const std::string& deviceID, const std::string& request);

	// �洢����ʽ��
	int FormatSDCardControl_(CZDGBDevice* device, const std::string& deviceID, const std::string& request);

	// Ŀ�����
	int TargetTrackControl_(CZDGBDevice* device, const std::string& deviceID, const std::string& request);

private:
	CGBDeviceControl();
	~CGBDeviceControl();

private:
	typedef std::lock_guard<std::recursive_mutex> RecursiveGuard;
};

#endif
