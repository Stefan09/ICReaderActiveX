// ICReader.h : CICReader 的声明

#pragma once
#include "resource.h"       // 主符号
#include <Windows.h>
#include "ICReaderActiveX_i.h"
#include "_IICReaderEvents_CP.h"

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE 平台(如不提供完全 DCOM 支持的 Windows Mobile 平台)上无法正确支持单线程 COM 对象。定义 _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA 可强制 ATL 支持创建单线程 COM 对象实现并允许使用其单线程 COM 对象实现。rgs 文件中的线程模型已被设置为“Free”，原因是该模型是非 DCOM Windows CE 平台支持的唯一线程模型。"
#endif

using namespace ATL;


/*函数入口*/
//判卡
typedef int(__stdcall *FPTRIsOurCard)(short, int);

//测试卡
typedef int(__stdcall *FPTRTestCard)(short, int, int, unsigned char[2], int);

//制用户卡
typedef int(__stdcall *FPTRWriteUserCard)(short, int, unsigned char*, char*, char*, double, int, int, const short);

//读用户卡
typedef int(__stdcall *FPTRReadCard)(short, int, char*, char*);

//还原卡
typedef int(__stdcall *FPTRCleanCard)(short, int);

//购气
typedef int(__stdcall *FPTRBuyGas)(short, int, double, char*, short, char*);


// CICReader继承了IICReader接口并对其中函数进行实现

class ATL_NO_VTABLE CICReader :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CICReader, &CLSID_ICReader>,
	public IConnectionPointContainerImpl<CICReader>,
	public CProxy_IICReaderEvents<CICReader>,
	public IObjectWithSiteImpl<CICReader>,
	public IDispatchImpl<IICReader, &IID_IICReader, &LIBID_ICReaderActiveXLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	/*成员变量*/
	//加载dll句柄
	HINSTANCE hInstLibrary;
	
	//IC卡属性
	short port = 3;
	int baud = 9600;
	//int cardkind;
	BSTR key = _T("11");   //写死11
	const short flag = 0x36A8;

	//错误码
	int errorcode;

	//操作卡函数
	FPTRIsOurCard _isOurCard;
	FPTRReadCard _ReadCard;
	FPTRWriteUserCard _WriteUserCard;
	FPTRCleanCard _CleanCard;
	FPTRBuyGas _BuyGas;

public:
	
	/*Constructor*/
	CICReader()
	{
		//L 表示使用Unicode编码
		hInstLibrary = LoadLibraryEx(L"D:\\Microsoft_VS\\Project\\ICReaderActiveX\\ICReaderActiveX\\SC_IC_DLL.dll", NULL, LOAD_WITH_ALTERED_SEARCH_PATH);
		errorcode = GetLastError();
		/*if (hInstLibrary == NULL)
		{
			FreeLibrary(hInstLibrary);
		}*/

		//测试卡
		_isOurCard = (FPTRIsOurCard)GetProcAddress(hInstLibrary, "IsOurCard");
		
		//读用户卡
		_ReadCard = (FPTRReadCard)GetProcAddress(hInstLibrary, "ReadCard");
		
		//制用户卡
		_WriteUserCard = (FPTRWriteUserCard)GetProcAddress(hInstLibrary, "WriteUserCard");

		//还原卡
		_CleanCard = (FPTRCleanCard)GetProcAddress(hInstLibrary, "CleanCard");

		//购气
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

//接口函数
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
