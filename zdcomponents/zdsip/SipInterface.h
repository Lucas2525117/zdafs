#ifndef _SIP_INTERFACE_H_
#define _SIP_INTERFACE_H_

#include <string>
#include "ZDSipHeader.h"
#include "ZDSipMedia.h"
#include "SipSDKPublic.h"

#if defined(ZD_SIP_DECL)
	#undef ZD_SIP_DECL
	#define ZD_SIP_DECL
#else
	#ifdef WIN32
		#ifdef ZD_SIP_EXPORTS
			#define ZD_SIP_DECL	__declspec(dllexport)
		#else
			#define ZD_SIP_DECL	__declspec(dllimport)
		#endif
	#else
		#if defined(__GNUC__) && __GNUC__>=4
			#define ZD_SIP_DECL	__attribute__((visibility("default")))
		#else
			#define ZD_SIP_DECL
		#endif
	#endif
#endif

#ifdef __cplusplus
#define ZD_SIP_API extern "C" ZD_SIP_DECL
#else
#define ZD_SIP_API ZD_SIP_DECL
#endif

typedef void* GB_TOKEN;

ZD_SIP_API bool GB_Init(const char* concat, int loglevel);

ZD_SIP_API bool GB_UnInit();

ZD_SIP_API void GB_Register(int handleType, DataCallback dataCB, void* user = nullptr);

ZD_SIP_API int GB_PTZControl(const char* gbid, int controlType, int paramValue);

ZD_SIP_API int GB_DeviceControl(const char* gbid, const char* method, const char* request);

ZD_SIP_API int GB_DeviceConfig(const char* gbid, const char* method, const char* request);

ZD_SIP_API bool GB_Invite(const GB28181MediaContext& mediaContext, GB_TOKEN* token);

ZD_SIP_API bool GB_Subscribe(const GBSubscribeContext& subContext, GB_TOKEN* token);

ZD_SIP_API int GB_QueryNetDeviceInfo(int type, const char* gbid);

ZD_SIP_API void GB_QueryRecordInfo(const char* gbid, const GB28181MediaContext& mediaContext);

ZD_SIP_API int GB_VoiceBroadcast(const char* gbid, const char* sourceID, const char* targetID);

ZD_SIP_API bool GB_Bye(const char* token);

#endif // _SIP_INTERFACE_H_

