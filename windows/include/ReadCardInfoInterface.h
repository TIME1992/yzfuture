#pragma once
#include "Type.h"

typedef void(__stdcall *cardReadProgress)(unsigned int nProgress, YZWLHandle nhandle);

YZWLHandle __stdcall cardOpenDevice(int nouttime, int nDeviceNo = 0);
bool __stdcall setCardType(YZWLHandle nDeviceHandle, cardType ctype);
bool __stdcall cardFindCard(YZWLHandle nDeviceHandle, bool &bmove);

bool __stdcall cardGetCardDN(YZWLHandle nDeviceHandle, char* szsn, int &nlen);
bool __stdcall cardGetCardSN(YZWLHandle nDeviceHandle, char* szsn, int &nlen);

bool __stdcall cardGetDeviceNO(YZWLHandle nDeviceHandle, char* szno, int &nlen);
bool __stdcall cardGetDeviceSN(YZWLHandle nDeviceHandle, char* szsn, int &nlen);

bool __stdcall cardReadTwoCard(YZWLHandle nDeviceHandle, cardReadProgress cardCB, 
	char* szFactoryFlag, char* szServerIp, int nServerPort,
	TwoIdInfoStructEx &cardinfo, bool bTest);

const char* __stdcall cardGetSerialNumber(YZWLHandle nDeviceHandle);

bool __stdcall cardBeep(YZWLHandle nDeviceHandle);

void __stdcall cardCloseDevice(YZWLHandle nDeviceHandle);

int __stdcall	cardGetLastErrorCode(YZWLHandle nDeviceHandle);
const char*	__stdcall cardGetErrorInfo(YZWLHandle nDeviceHandle, int &nlen, int nErrorCode);
const char*	__stdcall cardGetLastError(YZWLHandle nDeviceHandle, int &nlen);

// srcimage���ȹ̶�Ϊ1024 
// outimage��С�������Լ����룬��С��С��40KB
// outlen����ʱΪoutimageʵ�ʴ�С������ʱΪʵ��ͼƬ��С
bool __stdcall decodeCardImage(unsigned char* srcimage, char* outimage, int& outlen);

//ע�����
int	__stdcall	regeditGetVerificationCode(char* szserverip, unsigned int nserverport,
	char* szphoto, char* szError, int &nError);
int	__stdcall	regeditGetLogonAppKey(char* szserverip, unsigned int nserverport, char* szphoto,
	char* szverCode, char* szuserName, char* szret, int &nret, char* szError, int &nError);
int	__stdcall	regeditGetAppKeyUseNum(char* szserverip, unsigned int nserverport,
	char* szAppkey, char* szError, int &nError);
