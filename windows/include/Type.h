#pragma once

#include <stdint.h>

//#define		FOR_WINDOWS10					//WINDOWS 10 ��long long
#ifdef FOR_WINDOWS10
typedef long long YZWLHandle;				//��Ծ������������� ���ڸĶ�
#else
typedef long YZWLHandle;				//��Ծ������������� ���ڸĶ�
#endif

#if 1 //��ΪVC demo����ͷ�ļ� ��0��Ϊ1
typedef int		 					BOOL;
typedef unsigned char		 		byte;

#define		RT_NOT_HALT				0x26
#define		RT_ALL					0x52

#define		AM_A					0x60
#define		AM_B					0x61
#endif

typedef enum ErrorType
{
	//YZWL_DEVICEMIXERROR = -19999,

	// ����������
	// ������ֵ
	YZWL_FIRSTAPPLYFAILED = -25000, // �״μ�Ȩ����
	YZWL_DEVICEAPPLYFAILED, // �豸��Ȩ����
	YZWL_GETSERVERFAILED, // ��ȡ��������Ϣʱʧ��
	YZWL_GETPASSPORTFAILED, // ��ȡ������Ϣʱʧ��
	YZWL_GETCARDTYPEFAILED, // ��ȡ��Ƭ����ʧ��

	// ��������ֵ
	YZWL_CURLFAILED = -29999, // �������Ŀ�ʼ��
	YZWL_PARSEUSERINFOFAILED, // �����û���Ϣʧ��
	YZWL_PARSESERVERINFOFAILED, // �������֤��������Ϣʧ��
	YZWL_PARSECARDINFOFAILED, // �������֤��Ϣʧ��
	YZWL_PARSECARDINFOEXCEPTION, // �������֤��Ϣ�쳣
	YZWL_PARSEEPASSPORTFAILED, // �������շ�������Ϣ�쳣
	YZWL_PARSEPASSPORTFAILED, // ����������Ϣʧ��
	YZWL_PARSEPASSPORTEXCEPTION, // ����������Ϣ�쳣
	YZWL_SAVEINFOTOSERVERFAILED, // ���濨Ƭ��Ϣʧ��

	YZWL_RETCMDERROR, // ���ذ�����ID����
	YZWL_RETERRORDATAERROR, // ���ش���IDʧ��
	YZWL_RETERPARSEERROR, // ���ذ��������ݳ���
	YZWL_RETERFORMATERROR, // ���ذ���ʽ����
	// ����������,����

	YZWL_FACTORYEMPTY = -39999, // ������ϢΪ��
	YZWL_CREATEDEVICEFAILED, // �����豸ʧ��
	YZWL_READDEVICENOOPEN, // ������û�д�
	YZWL_FINDREQUESRFAILED, // Ѱ��ѡ��ʧ��
	YZWL_GETSNDNFAILED, // ��ȡSN��DNʧ��
	YZWL_GETDEVICEINFOFAILED, // ��ȡ��������Ϣʧ��
	YZWL_GETTWOCARDINFOFAILED, // ��ȡ���֤��Ϣʧ��
	YZWL_DECODETWOCARDFAILED, // �������֤��Ϣʧ��
	YZWL_SERVEDRINFOEXCEPTION, // ���֤�����������ַ�쳣

	YZWL_GETDEVICENOFAILED, // ��ȡ���������к�ʧ��
	YZWL_GETDEVICESNFAILED, // ��ȡ������оƬ���к�ʧ��

	YZWL_INPUTBUFSPACENENOUGH, // ����ռ䲻��
	YZWL_OUTPUTBUFSPACENENOUGH, // ����ռ䲻��
	YZWL_LOADLABLIRYFAILED, // ���ض�̬��ʧ��
	YZWL_IMPORTFUNFAILED, // ���붯̬����ʧ��
	YZWL_IMAGEDECODEFAILED, // ͼƬ����ʧ��

	YZWL_CALLBACKFUNEMPTY, // �ص�����Ϊ��
	YZWL_CONNECTSERVERFAILED, // ���ӷ�����ʧ��
	YZWL_SENDDATAFAILED, //  ���ݷ���ʧ��
	YZWL_TALKDATAFAILED, // �����������ʧ��
};

typedef struct TwoIdInfoStructEx
{
	char arrTwoIdName[30];					//���� UNICODE
	char arrTwoIdSex[2];					//�Ա� UNICODE
	char arrTwoIdNation[4];					//���� UNICODE
	char arrTwoIdBirthday[16];				//�������� UNICODE YYYYMMDD
	char arrTwoIdAddress[70];				//סַ UNICODE
	char arrTwoIdNo[36];					//���֤���� UNICODE
	char arrTwoIdSignedDepartment[30];		//ǩ������ UNICODE
	char arrTwoIdValidityPeriodBegin[16];	//��Ч����ʼ���� UNICODE YYYYMMDD
	char arrTwoIdValidityPeriodEnd[16];		//��Ч�ڽ�ֹ���� UNICODE YYYYMMDD ��Ч��Ϊ����ʱ�洢�����ڡ�

	char arrTwoOtherNO[18]; // ͨ��֤�����
	char arrTwoSignNum[4];		// ǩ������
	char arrTwoRemark1[6];	// Ԥ����
	char arrTwoType[2];		// ֤�����ͱ�ʶ
	char arrTwoRemark2[6];	// Ԥ����

	char arrTwoIdNewAddress[70];			//����סַ UNICODE
	char arrReserve[2];						//�����ֽ� �ֽڶ�����
	unsigned char arrTwoIdPhoto[1024];		//��Ƭ��Ϣ
	unsigned char arrTwoIdFingerprint[1024];//ָ����Ϣ
	unsigned char arrTwoIdPhotoJpeg[4096];	//��Ƭ��Ϣ JPEG ��ʽ
	unsigned int  unTwoIdPhotoJpegLength;	//��Ƭ��Ϣ���� JPEG��ʽ
};

typedef struct _EPassportInfoStruct{
	// ������Ϣ

	// ֤������(��д)
	char szPaperType[100];
	// ֤�����ͣ�ȫ�ƣ�
	char szTypeFullName[100];
	// ǩ�����һ�ǩ������
	char szSignedDepartment[100];
	// Ӣ����
	char szENName[100];
	// ������
	char szCNName[100];
	// ֤������
	char szIdNo[100];
	// ����ID���㷨��ʱ�����
	char szDocumentID[100];
	// ����
	char szCountry[100];
	// �������� UNICODE YYMMDD
	char szBirthday[6];
	// �Ա� UNICODE
	char szSex[1];
	// ��Ч�ڽ�ֹ���� UNICODE YYMMDD
	char szValidityPeriodEnd[6];
	// ��Ƭ��Ϣ
	char faceImage[1024 * 40];
}EPassportInfoStruct;
