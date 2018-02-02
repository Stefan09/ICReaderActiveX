// dllmain.h : 模块类的声明。

class CICReaderActiveXModule : public ATL::CAtlDllModuleT< CICReaderActiveXModule >
{
public :
	DECLARE_LIBID(LIBID_ICReaderActiveXLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_ICREADERACTIVEX, "{45D3B8B5-0B77-4A63-82ED-EFFF35BE40EC}")
};

extern class CICReaderActiveXModule _AtlModule;
