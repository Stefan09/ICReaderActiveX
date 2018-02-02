

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


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


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_IICReader,0xAFAC9F21,0x7ED5,0x4EE2,0x87,0x60,0x04,0x71,0x0B,0xA1,0x6D,0x22);


MIDL_DEFINE_GUID(IID, LIBID_ICReaderActiveXLib,0x3DB5E82B,0xD104,0x438A,0x92,0x31,0x22,0xFB,0x16,0x56,0x49,0xC4);


MIDL_DEFINE_GUID(IID, DIID__IICReaderEvents,0x49494802,0x7BFF,0x4B8B,0x86,0x64,0x8D,0xE4,0xF4,0xAA,0x13,0x70);


MIDL_DEFINE_GUID(CLSID, CLSID_ICReader,0xE99E58DB,0xED4C,0x4DE9,0xAD,0x1E,0xC8,0xC2,0x75,0x05,0x6B,0x8F);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



