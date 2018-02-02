

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Tue Jan 30 15:07:40 2018
 */
/* Compiler settings for ICReaderActiveX.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0603 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __ICReaderActiveX_i_h__
#define __ICReaderActiveX_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IICReader_FWD_DEFINED__
#define __IICReader_FWD_DEFINED__
typedef interface IICReader IICReader;

#endif 	/* __IICReader_FWD_DEFINED__ */


#ifndef ___IICReaderEvents_FWD_DEFINED__
#define ___IICReaderEvents_FWD_DEFINED__
typedef interface _IICReaderEvents _IICReaderEvents;

#endif 	/* ___IICReaderEvents_FWD_DEFINED__ */


#ifndef __ICReader_FWD_DEFINED__
#define __ICReader_FWD_DEFINED__

#ifdef __cplusplus
typedef class ICReader ICReader;
#else
typedef struct ICReader ICReader;
#endif /* __cplusplus */

#endif 	/* __ICReader_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IICReader_INTERFACE_DEFINED__
#define __IICReader_INTERFACE_DEFINED__

/* interface IICReader */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IICReader;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("AFAC9F21-7ED5-4EE2-8760-04710BA16D22")
    IICReader : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE TestICCard( 
            /* [retval][out] */ LONG *ReturnCode) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE isOurCard( 
            /* [retval][out] */ LONG *isFlag) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE add( 
            /* [in] */ LONG arg1,
            /* [in] */ LONG arg2,
            /* [retval][out] */ SHORT *result) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ReadCard( 
            /* [retval][out] */ BSTR *readinfo) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE WriteUserCard( 
            /* [in] */ BSTR param,
            /* [retval][out] */ LONG *returncode) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE CleanCard( 
            /* [retval][out] */ LONG *returncode) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE BuyGas( 
            /* [in] */ DOUBLE gas,
            /* [in] */ BSTR userid,
            /* [in] */ SHORT buytimes,
            /* [retval][out] */ LONG *returncode) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IICReaderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IICReader * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IICReader * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IICReader * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IICReader * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IICReader * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IICReader * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IICReader * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *TestICCard )( 
            IICReader * This,
            /* [retval][out] */ LONG *ReturnCode);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *isOurCard )( 
            IICReader * This,
            /* [retval][out] */ LONG *isFlag);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *add )( 
            IICReader * This,
            /* [in] */ LONG arg1,
            /* [in] */ LONG arg2,
            /* [retval][out] */ SHORT *result);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ReadCard )( 
            IICReader * This,
            /* [retval][out] */ BSTR *readinfo);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *WriteUserCard )( 
            IICReader * This,
            /* [in] */ BSTR param,
            /* [retval][out] */ LONG *returncode);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *CleanCard )( 
            IICReader * This,
            /* [retval][out] */ LONG *returncode);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *BuyGas )( 
            IICReader * This,
            /* [in] */ DOUBLE gas,
            /* [in] */ BSTR userid,
            /* [in] */ SHORT buytimes,
            /* [retval][out] */ LONG *returncode);
        
        END_INTERFACE
    } IICReaderVtbl;

    interface IICReader
    {
        CONST_VTBL struct IICReaderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IICReader_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IICReader_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IICReader_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IICReader_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IICReader_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IICReader_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IICReader_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IICReader_TestICCard(This,ReturnCode)	\
    ( (This)->lpVtbl -> TestICCard(This,ReturnCode) ) 

#define IICReader_isOurCard(This,isFlag)	\
    ( (This)->lpVtbl -> isOurCard(This,isFlag) ) 

#define IICReader_add(This,arg1,arg2,result)	\
    ( (This)->lpVtbl -> add(This,arg1,arg2,result) ) 

#define IICReader_ReadCard(This,readinfo)	\
    ( (This)->lpVtbl -> ReadCard(This,readinfo) ) 

#define IICReader_WriteUserCard(This,param,returncode)	\
    ( (This)->lpVtbl -> WriteUserCard(This,param,returncode) ) 

#define IICReader_CleanCard(This,returncode)	\
    ( (This)->lpVtbl -> CleanCard(This,returncode) ) 

#define IICReader_BuyGas(This,gas,userid,buytimes,returncode)	\
    ( (This)->lpVtbl -> BuyGas(This,gas,userid,buytimes,returncode) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IICReader_INTERFACE_DEFINED__ */



#ifndef __ICReaderActiveXLib_LIBRARY_DEFINED__
#define __ICReaderActiveXLib_LIBRARY_DEFINED__

/* library ICReaderActiveXLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_ICReaderActiveXLib;

#ifndef ___IICReaderEvents_DISPINTERFACE_DEFINED__
#define ___IICReaderEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IICReaderEvents */
/* [uuid] */ 


EXTERN_C const IID DIID__IICReaderEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("49494802-7BFF-4B8B-8664-8DE4F4AA1370")
    _IICReaderEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IICReaderEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IICReaderEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IICReaderEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IICReaderEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IICReaderEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IICReaderEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IICReaderEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IICReaderEvents * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } _IICReaderEventsVtbl;

    interface _IICReaderEvents
    {
        CONST_VTBL struct _IICReaderEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IICReaderEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IICReaderEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IICReaderEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IICReaderEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IICReaderEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IICReaderEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IICReaderEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IICReaderEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ICReader;

#ifdef __cplusplus

class DECLSPEC_UUID("E99E58DB-ED4C-4DE9-AD1E-C8C275056B8F")
ICReader;
#endif
#endif /* __ICReaderActiveXLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


