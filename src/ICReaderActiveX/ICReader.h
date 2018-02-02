// ICReader.h : CICReader ������

#pragma once
#include "resource.h"       // ������
#include <Windows.h>
#include "ICReaderActiveX_i.h"
#include "_IICReaderEvents_CP.h"

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
#endif

using namespace ATL;


/*�������*/
//�п�
typedef int(__stdcall *FPTRIsOurCard)(short, int);

//���Կ�
typedef int(__stdcall *FPTRTestCard)(short, int, int, unsigned char[2], int);

//���û���
typedef int(__stdcall *FPTRWriteUserCard)(short, int, unsigned char*, char*, char*, double, int, int, const short);

//���û���
typedef int(__stdcall *FPTRReadCard)(short, int, char*, char*);

//��ԭ��
typedef int(__stdcall *FPTRCleanCard)(short, int);

//����
typedef int(__stdcall *FPTRBuyGas)(short, int, double, char*, short, char*);


// CICReader�̳���IICReader�ӿڲ������к�������ʵ��

class ATL_NO_VTABLE CICReader :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CICReader, &CLSID_ICReader>,
	public IConnectionPointContainerImpl<CICReader>,
	public CProxy_IICReaderEvents<CICReader>,
	public IObjectWithSiteImpl<CICReader>,
	public IDispatchImpl<IICReader, &IID_IICReader, &LIBID_ICReaderActiveXLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	/*��Ա����*/
	//����dll���
	HINSTANCE hInstLibrary;
	
	//IC������
	short port = 3;
	int baud = 9600;
	//int cardkind;
	BSTR key = _T("11");   //д��11
	const short flag = 0x36A8;

	//������
	int errorcode;

	//����������
	FPTRIsOurCard _isOurCard;
	FPTRReadCard _ReadCard;
	FPTRWriteUserCard _WriteUserCard;
	FPTRCleanCard _CleanCard;
	FPTRBuyGas _BuyGas;

public:
	
	/*Constructor*/
	CICReader()
	{
		//L ��ʾʹ��Unicode����
		hInstLibrary = LoadLibraryEx(L"D:\\Microsoft_VS\\Project\\ICReaderActiveX\\ICReaderActiveX\\SC_IC_DLL.dll", NULL, LOAD_WITH_ALTERED_SEARCH_PATH);
		errorcode = GetLastError();
		/*if (hInstLibrary == NULL)
		{
			FreeLibrary(hInstLibrary);
		}*/

		//���Կ�
		_isOurCard = (FPTRIsOurCard)GetProcAddress(hInstLibrary, "IsOurCard");
		
		//���û���
		_ReadCard = (FPTRReadCard)GetProcAddress(hInstLibrary, "ReadCard");
		
		//���û���
		_WriteUserCard = (FPTRWriteUserCard)GetProcAddress(hInstLibrary, "WriteUserCard");

		//��ԭ��
		_CleanCard = (FPTRCleanCard)GetProcAddress(hInstLibrary, "CleanCard");

		//����
		_BuyGas = (FPTRBuyGas)GetProcAddress(hInstLibrary, "BuyGas");
	}


DECLARE_REGISTRY_RESOURCEID(IDR_ICREADER)


BEGIN_COM_MAP(CICReader)
	COM_INTERFACE_ENTRY(IICReader)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
	COM_INTERFACE_ENTRY(IObjectWithSite)
END_COM_MAP()

BEGIN_CONNECTION_POINT_MAP(CICReader)
	CONNECTION_POINT_ENTRY(__uuidof(_IICReaderEvents))
END_CONNECTION_POINT_MAP()


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

//�ӿں���
public:

	STDMETHOD(TestICCard)(LONG* ReturnCode);
	STDMETHOD(isOurCard)(LONG* isFlag);
	STDMETHOD(add)(LONG arg1, LONG arg2, SHORT* result);
	STDMETHOD(ReadCard)(BSTR* readinfo);
	STDMETHOD(WriteUserCard)(BSTR param, LONG* returncode);
	STDMETHOD(CleanCard)(LONG* returncode);
	STDMETHOD(BuyGas)(DOUBLE gas, BSTR userid, SHORT buytimes,LONG* returncode);
};

OBJECT_ENTRY_AUTO(__uuidof(ICReader), CICReader)
