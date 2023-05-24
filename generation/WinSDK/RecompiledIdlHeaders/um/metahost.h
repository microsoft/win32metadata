

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0628 */
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

/* verify that the <rpcsal.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCSAL_H_VERSION__
#define __REQUIRED_RPCSAL_H_VERSION__ 100
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __metahost_h__
#define __metahost_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef DECLSPEC_XFGVIRT
#if defined(_CONTROL_FLOW_GUARD_XFG)
#define DECLSPEC_XFGVIRT(base, func) __declspec(xfg_virtual(base, func))
#else
#define DECLSPEC_XFGVIRT(base, func)
#endif
#endif

/* Forward Declarations */ 

#ifndef __ICLRMetaHost_FWD_DEFINED__
#define __ICLRMetaHost_FWD_DEFINED__
typedef interface ICLRMetaHost ICLRMetaHost;

#endif 	/* __ICLRMetaHost_FWD_DEFINED__ */


#ifndef __ICLRMetaHostPolicy_FWD_DEFINED__
#define __ICLRMetaHostPolicy_FWD_DEFINED__
typedef interface ICLRMetaHostPolicy ICLRMetaHostPolicy;

#endif 	/* __ICLRMetaHostPolicy_FWD_DEFINED__ */


#ifndef __ICLRProfiling_FWD_DEFINED__
#define __ICLRProfiling_FWD_DEFINED__
typedef interface ICLRProfiling ICLRProfiling;

#endif 	/* __ICLRProfiling_FWD_DEFINED__ */


#ifndef __ICLRDebuggingLibraryProvider_FWD_DEFINED__
#define __ICLRDebuggingLibraryProvider_FWD_DEFINED__
typedef interface ICLRDebuggingLibraryProvider ICLRDebuggingLibraryProvider;

#endif 	/* __ICLRDebuggingLibraryProvider_FWD_DEFINED__ */


#ifndef __ICLRDebugging_FWD_DEFINED__
#define __ICLRDebugging_FWD_DEFINED__
typedef interface ICLRDebugging ICLRDebugging;

#endif 	/* __ICLRDebugging_FWD_DEFINED__ */


#ifndef __ICLRRuntimeInfo_FWD_DEFINED__
#define __ICLRRuntimeInfo_FWD_DEFINED__
typedef interface ICLRRuntimeInfo ICLRRuntimeInfo;

#endif 	/* __ICLRRuntimeInfo_FWD_DEFINED__ */


#ifndef __ICLRStrongName_FWD_DEFINED__
#define __ICLRStrongName_FWD_DEFINED__
typedef interface ICLRStrongName ICLRStrongName;

#endif 	/* __ICLRStrongName_FWD_DEFINED__ */


#ifndef __ICLRStrongName2_FWD_DEFINED__
#define __ICLRStrongName2_FWD_DEFINED__
typedef interface ICLRStrongName2 ICLRStrongName2;

#endif 	/* __ICLRStrongName2_FWD_DEFINED__ */


#ifndef __ICLRStrongName3_FWD_DEFINED__
#define __ICLRStrongName3_FWD_DEFINED__
typedef interface ICLRStrongName3 ICLRStrongName3;

#endif 	/* __ICLRStrongName3_FWD_DEFINED__ */


#ifndef __ICLRMetaHost_FWD_DEFINED__
#define __ICLRMetaHost_FWD_DEFINED__
typedef interface ICLRMetaHost ICLRMetaHost;

#endif 	/* __ICLRMetaHost_FWD_DEFINED__ */


#ifndef __ICLRMetaHostPolicy_FWD_DEFINED__
#define __ICLRMetaHostPolicy_FWD_DEFINED__
typedef interface ICLRMetaHostPolicy ICLRMetaHostPolicy;

#endif 	/* __ICLRMetaHostPolicy_FWD_DEFINED__ */


#ifndef __ICLRProfiling_FWD_DEFINED__
#define __ICLRProfiling_FWD_DEFINED__
typedef interface ICLRProfiling ICLRProfiling;

#endif 	/* __ICLRProfiling_FWD_DEFINED__ */


#ifndef __ICLRDebuggingLibraryProvider_FWD_DEFINED__
#define __ICLRDebuggingLibraryProvider_FWD_DEFINED__
typedef interface ICLRDebuggingLibraryProvider ICLRDebuggingLibraryProvider;

#endif 	/* __ICLRDebuggingLibraryProvider_FWD_DEFINED__ */


#ifndef __ICLRDebugging_FWD_DEFINED__
#define __ICLRDebugging_FWD_DEFINED__
typedef interface ICLRDebugging ICLRDebugging;

#endif 	/* __ICLRDebugging_FWD_DEFINED__ */


#ifndef __ICLRRuntimeInfo_FWD_DEFINED__
#define __ICLRRuntimeInfo_FWD_DEFINED__
typedef interface ICLRRuntimeInfo ICLRRuntimeInfo;

#endif 	/* __ICLRRuntimeInfo_FWD_DEFINED__ */


#ifndef __ICLRStrongName_FWD_DEFINED__
#define __ICLRStrongName_FWD_DEFINED__
typedef interface ICLRStrongName ICLRStrongName;

#endif 	/* __ICLRStrongName_FWD_DEFINED__ */


/* header files for imported files */
#include "unknwn.h"
#include "oaidl.h"
#include "ocidl.h"
#include "mscoree.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_metahost_0000_0000 */
/* [local] */ 

#include <winapifamily.h>
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
STDAPI CLRCreateInstance(REFCLSID clsid, REFIID riid, /*iid_is(riid)*/ LPVOID *ppInterface);
EXTERN_GUID(CLSID_CLRStrongName, 0xB79B0ACD, 0xF5CD, 0x409b, 0xB5, 0xA5, 0xA1, 0x62, 0x44, 0x61, 0x0B, 0x92);
EXTERN_GUID(IID_ICLRMetaHost, 0xD332DB9E, 0xB9B3, 0x4125, 0x82, 0x07, 0xA1, 0x48, 0x84, 0xF5, 0x32, 0x16);
EXTERN_GUID(CLSID_CLRMetaHost, 0x9280188d, 0xe8e, 0x4867, 0xb3, 0xc, 0x7f, 0xa8, 0x38, 0x84, 0xe8, 0xde);
EXTERN_GUID(IID_ICLRMetaHostPolicy, 0xE2190695, 0x77B2, 0x492e, 0x8E, 0x14, 0xC4, 0xB3, 0xA7, 0xFD, 0xD5, 0x93);
EXTERN_GUID(CLSID_CLRMetaHostPolicy, 0x2ebcd49a, 0x1b47, 0x4a61, 0xb1, 0x3a, 0x4a, 0x3, 0x70, 0x1e, 0x59, 0x4b);
EXTERN_GUID(IID_ICLRDebugging, 0xd28f3c5a, 0x9634, 0x4206, 0xa5, 0x9, 0x47, 0x75, 0x52, 0xee, 0xfb, 0x10);
EXTERN_GUID(CLSID_CLRDebugging, 0xbacc578d, 0xfbdd, 0x48a4, 0x96, 0x9f, 0x2, 0xd9, 0x32, 0xb7, 0x46, 0x34);
EXTERN_GUID(IID_ICLRRuntimeInfo, 0xBD39D1D2, 0xBA2F, 0x486a, 0x89, 0xB0, 0xB4, 0xB0, 0xCB, 0x46, 0x68, 0x91);
EXTERN_GUID(IID_ICLRStrongName, 0x9FD93CCF, 0x3280, 0x4391, 0xB3, 0xA9, 0x96, 0xE1, 0xCD, 0xE7, 0x7C, 0x8D);
EXTERN_GUID(IID_ICLRStrongName2, 0xC22ED5C5, 0x4B59, 0x4975, 0x90, 0xEB, 0x85, 0xEA, 0x55, 0xC0, 0x06, 0x9B);
EXTERN_GUID(IID_ICLRStrongName3, 0x22c7089b, 0xbbd3, 0x414a, 0xb6, 0x98, 0x21, 0x0f, 0x26, 0x3f, 0x1f, 0xed);
EXTERN_GUID(CLSID_CLRDebuggingLegacy, 0xDF8395B5, 0xA4BA, 0x450b, 0xA7, 0x7C, 0xA9, 0xA4, 0x77, 0x62, 0xC5, 0x20);
EXTERN_GUID(CLSID_CLRProfiling, 0xbd097ed8, 0x733e, 0x43fe, 0x8e, 0xd7, 0xa9, 0x5f, 0xf9, 0xa8, 0x44, 0x8c);
EXTERN_GUID(IID_ICLRProfiling, 0xb349abe3, 0xb56f, 0x4689, 0xbf, 0xcd, 0x76, 0xbf, 0x39, 0xd8, 0x88, 0xea);
EXTERN_GUID(IID_ICLRDebuggingLibraryProvider, 0x3151c08d, 0x4d09, 0x4f9b, 0x88, 0x38, 0x28, 0x80, 0xbf, 0x18, 0xfe, 0x51);
typedef HRESULT ( __stdcall *CLRCreateInstanceFnPtr )( 
    REFCLSID clsid,
    REFIID riid,
    LPVOID *ppInterface);

typedef HRESULT ( __stdcall *CreateInterfaceFnPtr )( 
    REFCLSID clsid,
    REFIID riid,
    LPVOID *ppInterface);


typedef HRESULT ( __stdcall *CallbackThreadSetFnPtr )( void);

typedef HRESULT ( __stdcall *CallbackThreadUnsetFnPtr )( void);

typedef void ( __stdcall *RuntimeLoadedCallbackFnPtr )( 
    ICLRRuntimeInfo *pRuntimeInfo,
    CallbackThreadSetFnPtr pfnCallbackThreadSet,
    CallbackThreadUnsetFnPtr pfnCallbackThreadUnset);



extern RPC_IF_HANDLE __MIDL_itf_metahost_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_metahost_0000_0000_v0_0_s_ifspec;

#ifndef __ICLRMetaHost_INTERFACE_DEFINED__
#define __ICLRMetaHost_INTERFACE_DEFINED__

/* interface ICLRMetaHost */
/* [object][local][helpstring][version][uuid] */ 


EXTERN_C const IID IID_ICLRMetaHost;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D332DB9E-B9B3-4125-8207-A14884F53216")
    ICLRMetaHost : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetRuntime( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pwzVersion,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][retval][iid_is][out] */ 
            _COM_Outptr_retval_  LPVOID *ppRuntime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetVersionFromFile( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pwzFilePath,
            /* [annotation][size_is][out] */ 
            _Out_writes_all_(*pcchBuffer)  LPWSTR pwzBuffer,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcchBuffer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumerateInstalledRuntimes( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IEnumUnknown **ppEnumerator) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumerateLoadedRuntimes( 
            /* [annotation][in] */ 
            _In_  HANDLE hndProcess,
            /* [annotation][retval][out] */ 
            _Out_retval_  IEnumUnknown **ppEnumerator) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RequestRuntimeLoadedNotification( 
            /* [annotation][in] */ 
            _In_  RuntimeLoadedCallbackFnPtr pCallbackFunction) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryLegacyV2RuntimeBinding( 
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][retval][iid_is][out] */ 
            _COM_Outptr_retval_  LPVOID *ppUnk) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ExitProcess( 
            /* [annotation][in] */ 
            _In_  INT32 iExitCode) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICLRMetaHostVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICLRMetaHost * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICLRMetaHost * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICLRMetaHost * This);
        
        DECLSPEC_XFGVIRT(ICLRMetaHost, GetRuntime)
        HRESULT ( STDMETHODCALLTYPE *GetRuntime )( 
            ICLRMetaHost * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pwzVersion,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][retval][iid_is][out] */ 
            _COM_Outptr_retval_  LPVOID *ppRuntime);
        
        DECLSPEC_XFGVIRT(ICLRMetaHost, GetVersionFromFile)
        HRESULT ( STDMETHODCALLTYPE *GetVersionFromFile )( 
            ICLRMetaHost * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pwzFilePath,
            /* [annotation][size_is][out] */ 
            _Out_writes_all_(*pcchBuffer)  LPWSTR pwzBuffer,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcchBuffer);
        
        DECLSPEC_XFGVIRT(ICLRMetaHost, EnumerateInstalledRuntimes)
        HRESULT ( STDMETHODCALLTYPE *EnumerateInstalledRuntimes )( 
            ICLRMetaHost * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IEnumUnknown **ppEnumerator);
        
        DECLSPEC_XFGVIRT(ICLRMetaHost, EnumerateLoadedRuntimes)
        HRESULT ( STDMETHODCALLTYPE *EnumerateLoadedRuntimes )( 
            ICLRMetaHost * This,
            /* [annotation][in] */ 
            _In_  HANDLE hndProcess,
            /* [annotation][retval][out] */ 
            _Out_retval_  IEnumUnknown **ppEnumerator);
        
        DECLSPEC_XFGVIRT(ICLRMetaHost, RequestRuntimeLoadedNotification)
        HRESULT ( STDMETHODCALLTYPE *RequestRuntimeLoadedNotification )( 
            ICLRMetaHost * This,
            /* [annotation][in] */ 
            _In_  RuntimeLoadedCallbackFnPtr pCallbackFunction);
        
        DECLSPEC_XFGVIRT(ICLRMetaHost, QueryLegacyV2RuntimeBinding)
        HRESULT ( STDMETHODCALLTYPE *QueryLegacyV2RuntimeBinding )( 
            ICLRMetaHost * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][retval][iid_is][out] */ 
            _COM_Outptr_retval_  LPVOID *ppUnk);
        
        DECLSPEC_XFGVIRT(ICLRMetaHost, ExitProcess)
        HRESULT ( STDMETHODCALLTYPE *ExitProcess )( 
            ICLRMetaHost * This,
            /* [annotation][in] */ 
            _In_  INT32 iExitCode);
        
        END_INTERFACE
    } ICLRMetaHostVtbl;

    interface ICLRMetaHost
    {
        CONST_VTBL struct ICLRMetaHostVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICLRMetaHost_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICLRMetaHost_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICLRMetaHost_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICLRMetaHost_GetRuntime(This,pwzVersion,riid,ppRuntime)	\
    ( (This)->lpVtbl -> GetRuntime(This,pwzVersion,riid,ppRuntime) ) 

#define ICLRMetaHost_GetVersionFromFile(This,pwzFilePath,pwzBuffer,pcchBuffer)	\
    ( (This)->lpVtbl -> GetVersionFromFile(This,pwzFilePath,pwzBuffer,pcchBuffer) ) 

#define ICLRMetaHost_EnumerateInstalledRuntimes(This,ppEnumerator)	\
    ( (This)->lpVtbl -> EnumerateInstalledRuntimes(This,ppEnumerator) ) 

#define ICLRMetaHost_EnumerateLoadedRuntimes(This,hndProcess,ppEnumerator)	\
    ( (This)->lpVtbl -> EnumerateLoadedRuntimes(This,hndProcess,ppEnumerator) ) 

#define ICLRMetaHost_RequestRuntimeLoadedNotification(This,pCallbackFunction)	\
    ( (This)->lpVtbl -> RequestRuntimeLoadedNotification(This,pCallbackFunction) ) 

#define ICLRMetaHost_QueryLegacyV2RuntimeBinding(This,riid,ppUnk)	\
    ( (This)->lpVtbl -> QueryLegacyV2RuntimeBinding(This,riid,ppUnk) ) 

#define ICLRMetaHost_ExitProcess(This,iExitCode)	\
    ( (This)->lpVtbl -> ExitProcess(This,iExitCode) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICLRMetaHost_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_metahost_0000_0001 */
/* [local] */ 

typedef /* [public][public] */ 
enum __MIDL___MIDL_itf_metahost_0000_0001_0001
    {
        METAHOST_POLICY_HIGHCOMPAT	= 0,
        METAHOST_POLICY_APPLY_UPGRADE_POLICY	= 0x8,
        METAHOST_POLICY_EMULATE_EXE_LAUNCH	= 0x10,
        METAHOST_POLICY_SHOW_ERROR_DIALOG	= 0x20,
        METAHOST_POLICY_USE_PROCESS_IMAGE_PATH	= 0x40,
        METAHOST_POLICY_ENSURE_SKU_SUPPORTED	= 0x80,
        METAHOST_POLICY_IGNORE_ERROR_MODE	= 0x1000
    } 	METAHOST_POLICY_FLAGS;

typedef /* [public] */ 
enum __MIDL___MIDL_itf_metahost_0000_0001_0002
    {
        METAHOST_CONFIG_FLAGS_LEGACY_V2_ACTIVATION_POLICY_UNSET	= 0,
        METAHOST_CONFIG_FLAGS_LEGACY_V2_ACTIVATION_POLICY_TRUE	= 0x1,
        METAHOST_CONFIG_FLAGS_LEGACY_V2_ACTIVATION_POLICY_FALSE	= 0x2,
        METAHOST_CONFIG_FLAGS_LEGACY_V2_ACTIVATION_POLICY_MASK	= 0x3
    } 	METAHOST_CONFIG_FLAGS;



extern RPC_IF_HANDLE __MIDL_itf_metahost_0000_0001_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_metahost_0000_0001_v0_0_s_ifspec;

#ifndef __ICLRMetaHostPolicy_INTERFACE_DEFINED__
#define __ICLRMetaHostPolicy_INTERFACE_DEFINED__

/* interface ICLRMetaHostPolicy */
/* [object][local][helpstring][version][uuid] */ 


EXTERN_C const IID IID_ICLRMetaHostPolicy;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2190695-77B2-492e-8E14-C4B3A7FDD593")
    ICLRMetaHostPolicy : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetRequestedRuntime( 
            /* [annotation][in] */ 
            _In_  METAHOST_POLICY_FLAGS dwPolicyFlags,
            /* [annotation][in] */ 
            _In_  LPCWSTR pwzBinary,
            /* [annotation][in] */ 
            _In_  IStream *pCfgStream,
            /* [annotation][size_is][out][in] */ 
            _Inout_updates_all_opt_(*pcchVersion)  LPWSTR pwzVersion,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcchVersion,
            /* [annotation][size_is][out] */ 
            _Out_writes_all_opt_(*pcchImageVersion)  LPWSTR pwzImageVersion,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcchImageVersion,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwConfigFlags,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][retval][iid_is][out] */ 
            _COM_Outptr_retval_  LPVOID *ppRuntime) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICLRMetaHostPolicyVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICLRMetaHostPolicy * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICLRMetaHostPolicy * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICLRMetaHostPolicy * This);
        
        DECLSPEC_XFGVIRT(ICLRMetaHostPolicy, GetRequestedRuntime)
        HRESULT ( STDMETHODCALLTYPE *GetRequestedRuntime )( 
            ICLRMetaHostPolicy * This,
            /* [annotation][in] */ 
            _In_  METAHOST_POLICY_FLAGS dwPolicyFlags,
            /* [annotation][in] */ 
            _In_  LPCWSTR pwzBinary,
            /* [annotation][in] */ 
            _In_  IStream *pCfgStream,
            /* [annotation][size_is][out][in] */ 
            _Inout_updates_all_opt_(*pcchVersion)  LPWSTR pwzVersion,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcchVersion,
            /* [annotation][size_is][out] */ 
            _Out_writes_all_opt_(*pcchImageVersion)  LPWSTR pwzImageVersion,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcchImageVersion,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwConfigFlags,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][retval][iid_is][out] */ 
            _COM_Outptr_retval_  LPVOID *ppRuntime);
        
        END_INTERFACE
    } ICLRMetaHostPolicyVtbl;

    interface ICLRMetaHostPolicy
    {
        CONST_VTBL struct ICLRMetaHostPolicyVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICLRMetaHostPolicy_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICLRMetaHostPolicy_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICLRMetaHostPolicy_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICLRMetaHostPolicy_GetRequestedRuntime(This,dwPolicyFlags,pwzBinary,pCfgStream,pwzVersion,pcchVersion,pwzImageVersion,pcchImageVersion,pdwConfigFlags,riid,ppRuntime)	\
    ( (This)->lpVtbl -> GetRequestedRuntime(This,dwPolicyFlags,pwzBinary,pCfgStream,pwzVersion,pcchVersion,pwzImageVersion,pcchImageVersion,pdwConfigFlags,riid,ppRuntime) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICLRMetaHostPolicy_INTERFACE_DEFINED__ */


#ifndef __ICLRProfiling_INTERFACE_DEFINED__
#define __ICLRProfiling_INTERFACE_DEFINED__

/* interface ICLRProfiling */
/* [object][local][helpstring][version][uuid] */ 


EXTERN_C const IID IID_ICLRProfiling;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B349ABE3-B56F-4689-BFCD-76BF39D888EA")
    ICLRProfiling : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AttachProfiler( 
            /* [annotation][in] */ 
            _In_  DWORD dwProfileeProcessID,
            /* [annotation][in] */ 
            _In_  DWORD dwMillisecondsMax,
            /* [annotation][in] */ 
            _In_  const CLSID *pClsidProfiler,
            /* [annotation][in] */ 
            _In_  LPCWSTR wszProfilerPath,
            /* [annotation][size_is][in] */ 
            _In_reads_(cbClientData)  void *pvClientData,
            /* [annotation][in] */ 
            _In_  UINT cbClientData) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICLRProfilingVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICLRProfiling * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICLRProfiling * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICLRProfiling * This);
        
        DECLSPEC_XFGVIRT(ICLRProfiling, AttachProfiler)
        HRESULT ( STDMETHODCALLTYPE *AttachProfiler )( 
            ICLRProfiling * This,
            /* [annotation][in] */ 
            _In_  DWORD dwProfileeProcessID,
            /* [annotation][in] */ 
            _In_  DWORD dwMillisecondsMax,
            /* [annotation][in] */ 
            _In_  const CLSID *pClsidProfiler,
            /* [annotation][in] */ 
            _In_  LPCWSTR wszProfilerPath,
            /* [annotation][size_is][in] */ 
            _In_reads_(cbClientData)  void *pvClientData,
            /* [annotation][in] */ 
            _In_  UINT cbClientData);
        
        END_INTERFACE
    } ICLRProfilingVtbl;

    interface ICLRProfiling
    {
        CONST_VTBL struct ICLRProfilingVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICLRProfiling_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICLRProfiling_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICLRProfiling_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICLRProfiling_AttachProfiler(This,dwProfileeProcessID,dwMillisecondsMax,pClsidProfiler,wszProfilerPath,pvClientData,cbClientData)	\
    ( (This)->lpVtbl -> AttachProfiler(This,dwProfileeProcessID,dwMillisecondsMax,pClsidProfiler,wszProfilerPath,pvClientData,cbClientData) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICLRProfiling_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_metahost_0000_0003 */
/* [local] */ 

typedef struct _CLR_DEBUGGING_VERSION
    {
    WORD wStructVersion;
    WORD wMajor;
    WORD wMinor;
    WORD wBuild;
    WORD wRevision;
    } 	CLR_DEBUGGING_VERSION;

typedef /* [public][public] */ 
enum __MIDL___MIDL_itf_metahost_0000_0003_0001
    {
        CLR_DEBUGGING_MANAGED_EVENT_PENDING	= 1,
        CLR_DEBUGGING_MANAGED_EVENT_DEBUGGER_LAUNCH	= 2
    } 	CLR_DEBUGGING_PROCESS_FLAGS;



extern RPC_IF_HANDLE __MIDL_itf_metahost_0000_0003_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_metahost_0000_0003_v0_0_s_ifspec;

#ifndef __ICLRDebuggingLibraryProvider_INTERFACE_DEFINED__
#define __ICLRDebuggingLibraryProvider_INTERFACE_DEFINED__

/* interface ICLRDebuggingLibraryProvider */
/* [object][local][helpstring][version][uuid] */ 


EXTERN_C const IID IID_ICLRDebuggingLibraryProvider;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3151C08D-4D09-4f9b-8838-2880BF18FE51")
    ICLRDebuggingLibraryProvider : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ProvideLibrary( 
            /* [annotation][in] */ 
            _In_  const WCHAR *pwszFileName,
            /* [annotation][in] */ 
            _In_  DWORD dwTimestamp,
            /* [annotation][in] */ 
            _In_  DWORD dwSizeOfImage,
            /* [annotation][out] */ 
            _Out_  HMODULE *phModule) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICLRDebuggingLibraryProviderVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICLRDebuggingLibraryProvider * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICLRDebuggingLibraryProvider * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICLRDebuggingLibraryProvider * This);
        
        DECLSPEC_XFGVIRT(ICLRDebuggingLibraryProvider, ProvideLibrary)
        HRESULT ( STDMETHODCALLTYPE *ProvideLibrary )( 
            ICLRDebuggingLibraryProvider * This,
            /* [annotation][in] */ 
            _In_  const WCHAR *pwszFileName,
            /* [annotation][in] */ 
            _In_  DWORD dwTimestamp,
            /* [annotation][in] */ 
            _In_  DWORD dwSizeOfImage,
            /* [annotation][out] */ 
            _Out_  HMODULE *phModule);
        
        END_INTERFACE
    } ICLRDebuggingLibraryProviderVtbl;

    interface ICLRDebuggingLibraryProvider
    {
        CONST_VTBL struct ICLRDebuggingLibraryProviderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICLRDebuggingLibraryProvider_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICLRDebuggingLibraryProvider_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICLRDebuggingLibraryProvider_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICLRDebuggingLibraryProvider_ProvideLibrary(This,pwszFileName,dwTimestamp,dwSizeOfImage,phModule)	\
    ( (This)->lpVtbl -> ProvideLibrary(This,pwszFileName,dwTimestamp,dwSizeOfImage,phModule) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICLRDebuggingLibraryProvider_INTERFACE_DEFINED__ */


#ifndef __ICLRDebugging_INTERFACE_DEFINED__
#define __ICLRDebugging_INTERFACE_DEFINED__

/* interface ICLRDebugging */
/* [object][local][helpstring][version][uuid] */ 


EXTERN_C const IID IID_ICLRDebugging;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D28F3C5A-9634-4206-A509-477552EEFB10")
    ICLRDebugging : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OpenVirtualProcess( 
            /* [annotation][in] */ 
            _In_  ULONG64 moduleBaseAddress,
            /* [annotation][in] */ 
            _In_  IUnknown *pDataTarget,
            /* [annotation][in] */ 
            _In_  ICLRDebuggingLibraryProvider *pLibraryProvider,
            /* [annotation][in] */ 
            _In_  CLR_DEBUGGING_VERSION *pMaxDebuggerSupportedVersion,
            /* [annotation][in] */ 
            _In_  REFIID riidProcess,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  IUnknown **ppProcess,
            /* [annotation][out][in] */ 
            _Inout_  CLR_DEBUGGING_VERSION *pVersion,
            /* [annotation][out] */ 
            _Out_  CLR_DEBUGGING_PROCESS_FLAGS *pdwFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CanUnloadNow( 
            HMODULE hModule) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICLRDebuggingVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICLRDebugging * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICLRDebugging * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICLRDebugging * This);
        
        DECLSPEC_XFGVIRT(ICLRDebugging, OpenVirtualProcess)
        HRESULT ( STDMETHODCALLTYPE *OpenVirtualProcess )( 
            ICLRDebugging * This,
            /* [annotation][in] */ 
            _In_  ULONG64 moduleBaseAddress,
            /* [annotation][in] */ 
            _In_  IUnknown *pDataTarget,
            /* [annotation][in] */ 
            _In_  ICLRDebuggingLibraryProvider *pLibraryProvider,
            /* [annotation][in] */ 
            _In_  CLR_DEBUGGING_VERSION *pMaxDebuggerSupportedVersion,
            /* [annotation][in] */ 
            _In_  REFIID riidProcess,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  IUnknown **ppProcess,
            /* [annotation][out][in] */ 
            _Inout_  CLR_DEBUGGING_VERSION *pVersion,
            /* [annotation][out] */ 
            _Out_  CLR_DEBUGGING_PROCESS_FLAGS *pdwFlags);
        
        DECLSPEC_XFGVIRT(ICLRDebugging, CanUnloadNow)
        HRESULT ( STDMETHODCALLTYPE *CanUnloadNow )( 
            ICLRDebugging * This,
            HMODULE hModule);
        
        END_INTERFACE
    } ICLRDebuggingVtbl;

    interface ICLRDebugging
    {
        CONST_VTBL struct ICLRDebuggingVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICLRDebugging_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICLRDebugging_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICLRDebugging_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICLRDebugging_OpenVirtualProcess(This,moduleBaseAddress,pDataTarget,pLibraryProvider,pMaxDebuggerSupportedVersion,riidProcess,ppProcess,pVersion,pdwFlags)	\
    ( (This)->lpVtbl -> OpenVirtualProcess(This,moduleBaseAddress,pDataTarget,pLibraryProvider,pMaxDebuggerSupportedVersion,riidProcess,ppProcess,pVersion,pdwFlags) ) 

#define ICLRDebugging_CanUnloadNow(This,hModule)	\
    ( (This)->lpVtbl -> CanUnloadNow(This,hModule) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICLRDebugging_INTERFACE_DEFINED__ */


#ifndef __ICLRRuntimeInfo_INTERFACE_DEFINED__
#define __ICLRRuntimeInfo_INTERFACE_DEFINED__

/* interface ICLRRuntimeInfo */
/* [object][local][helpstring][version][uuid] */ 


EXTERN_C const IID IID_ICLRRuntimeInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BD39D1D2-BA2F-486a-89B0-B4B0CB466891")
    ICLRRuntimeInfo : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetVersionString( 
            /* [annotation][size_is][out] */ 
            _Out_writes_all_opt_(*pcchBuffer)  LPWSTR pwzBuffer,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcchBuffer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRuntimeDirectory( 
            /* [annotation][size_is][out] */ 
            _Out_writes_all_(*pcchBuffer)  LPWSTR pwzBuffer,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcchBuffer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsLoaded( 
            /* [annotation][in] */ 
            _In_  HANDLE hndProcess,
            /* [annotation][retval][out] */ 
            _Out_retval_  BOOL *pbLoaded) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadErrorString( 
            /* [annotation][in] */ 
            _In_  UINT iResourceID,
            /* [annotation][size_is][out] */ 
            _Out_writes_all_(*pcchBuffer)  LPWSTR pwzBuffer,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcchBuffer,
            /* [lcid][in] */ LONG iLocaleID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadLibrary( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pwzDllName,
            /* [annotation][retval][out] */ 
            _Out_retval_  HMODULE *phndModule) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetProcAddress( 
            /* [annotation][in] */ 
            _In_  LPCSTR pszProcName,
            /* [annotation][retval][out] */ 
            _Out_retval_  LPVOID *ppProc) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetInterface( 
            /* [annotation][in] */ 
            _In_  REFCLSID rclsid,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][retval][iid_is][out] */ 
            _COM_Outptr_retval_  LPVOID *ppUnk) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsLoadable( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BOOL *pbLoadable) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDefaultStartupFlags( 
            /* [annotation][in] */ 
            _In_  DWORD dwStartupFlags,
            /* [annotation][in] */ 
            _In_  LPCWSTR pwzHostConfigFile) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDefaultStartupFlags( 
            /* [annotation][out] */ 
            _Out_  DWORD *pdwStartupFlags,
            /* [annotation][size_is][out] */ 
            _Out_writes_all_opt_(*pcchHostConfigFile)  LPWSTR pwzHostConfigFile,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcchHostConfigFile) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE BindAsLegacyV2Runtime( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsStarted( 
            /* [annotation][out] */ 
            _Out_  BOOL *pbStarted,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwStartupFlags) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICLRRuntimeInfoVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICLRRuntimeInfo * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICLRRuntimeInfo * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICLRRuntimeInfo * This);
        
        DECLSPEC_XFGVIRT(ICLRRuntimeInfo, GetVersionString)
        HRESULT ( STDMETHODCALLTYPE *GetVersionString )( 
            ICLRRuntimeInfo * This,
            /* [annotation][size_is][out] */ 
            _Out_writes_all_opt_(*pcchBuffer)  LPWSTR pwzBuffer,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcchBuffer);
        
        DECLSPEC_XFGVIRT(ICLRRuntimeInfo, GetRuntimeDirectory)
        HRESULT ( STDMETHODCALLTYPE *GetRuntimeDirectory )( 
            ICLRRuntimeInfo * This,
            /* [annotation][size_is][out] */ 
            _Out_writes_all_(*pcchBuffer)  LPWSTR pwzBuffer,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcchBuffer);
        
        DECLSPEC_XFGVIRT(ICLRRuntimeInfo, IsLoaded)
        HRESULT ( STDMETHODCALLTYPE *IsLoaded )( 
            ICLRRuntimeInfo * This,
            /* [annotation][in] */ 
            _In_  HANDLE hndProcess,
            /* [annotation][retval][out] */ 
            _Out_retval_  BOOL *pbLoaded);
        
        DECLSPEC_XFGVIRT(ICLRRuntimeInfo, LoadErrorString)
        HRESULT ( STDMETHODCALLTYPE *LoadErrorString )( 
            ICLRRuntimeInfo * This,
            /* [annotation][in] */ 
            _In_  UINT iResourceID,
            /* [annotation][size_is][out] */ 
            _Out_writes_all_(*pcchBuffer)  LPWSTR pwzBuffer,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcchBuffer,
            /* [lcid][in] */ LONG iLocaleID);
        
        DECLSPEC_XFGVIRT(ICLRRuntimeInfo, LoadLibrary)
        HRESULT ( STDMETHODCALLTYPE *LoadLibrary )( 
            ICLRRuntimeInfo * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pwzDllName,
            /* [annotation][retval][out] */ 
            _Out_retval_  HMODULE *phndModule);
        
        DECLSPEC_XFGVIRT(ICLRRuntimeInfo, GetProcAddress)
        HRESULT ( STDMETHODCALLTYPE *GetProcAddress )( 
            ICLRRuntimeInfo * This,
            /* [annotation][in] */ 
            _In_  LPCSTR pszProcName,
            /* [annotation][retval][out] */ 
            _Out_retval_  LPVOID *ppProc);
        
        DECLSPEC_XFGVIRT(ICLRRuntimeInfo, GetInterface)
        HRESULT ( STDMETHODCALLTYPE *GetInterface )( 
            ICLRRuntimeInfo * This,
            /* [annotation][in] */ 
            _In_  REFCLSID rclsid,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][retval][iid_is][out] */ 
            _COM_Outptr_retval_  LPVOID *ppUnk);
        
        DECLSPEC_XFGVIRT(ICLRRuntimeInfo, IsLoadable)
        HRESULT ( STDMETHODCALLTYPE *IsLoadable )( 
            ICLRRuntimeInfo * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BOOL *pbLoadable);
        
        DECLSPEC_XFGVIRT(ICLRRuntimeInfo, SetDefaultStartupFlags)
        HRESULT ( STDMETHODCALLTYPE *SetDefaultStartupFlags )( 
            ICLRRuntimeInfo * This,
            /* [annotation][in] */ 
            _In_  DWORD dwStartupFlags,
            /* [annotation][in] */ 
            _In_  LPCWSTR pwzHostConfigFile);
        
        DECLSPEC_XFGVIRT(ICLRRuntimeInfo, GetDefaultStartupFlags)
        HRESULT ( STDMETHODCALLTYPE *GetDefaultStartupFlags )( 
            ICLRRuntimeInfo * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwStartupFlags,
            /* [annotation][size_is][out] */ 
            _Out_writes_all_opt_(*pcchHostConfigFile)  LPWSTR pwzHostConfigFile,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcchHostConfigFile);
        
        DECLSPEC_XFGVIRT(ICLRRuntimeInfo, BindAsLegacyV2Runtime)
        HRESULT ( STDMETHODCALLTYPE *BindAsLegacyV2Runtime )( 
            ICLRRuntimeInfo * This);
        
        DECLSPEC_XFGVIRT(ICLRRuntimeInfo, IsStarted)
        HRESULT ( STDMETHODCALLTYPE *IsStarted )( 
            ICLRRuntimeInfo * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pbStarted,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwStartupFlags);
        
        END_INTERFACE
    } ICLRRuntimeInfoVtbl;

    interface ICLRRuntimeInfo
    {
        CONST_VTBL struct ICLRRuntimeInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICLRRuntimeInfo_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICLRRuntimeInfo_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICLRRuntimeInfo_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICLRRuntimeInfo_GetVersionString(This,pwzBuffer,pcchBuffer)	\
    ( (This)->lpVtbl -> GetVersionString(This,pwzBuffer,pcchBuffer) ) 

#define ICLRRuntimeInfo_GetRuntimeDirectory(This,pwzBuffer,pcchBuffer)	\
    ( (This)->lpVtbl -> GetRuntimeDirectory(This,pwzBuffer,pcchBuffer) ) 

#define ICLRRuntimeInfo_IsLoaded(This,hndProcess,pbLoaded)	\
    ( (This)->lpVtbl -> IsLoaded(This,hndProcess,pbLoaded) ) 

#define ICLRRuntimeInfo_LoadErrorString(This,iResourceID,pwzBuffer,pcchBuffer,iLocaleID)	\
    ( (This)->lpVtbl -> LoadErrorString(This,iResourceID,pwzBuffer,pcchBuffer,iLocaleID) ) 

#define ICLRRuntimeInfo_LoadLibrary(This,pwzDllName,phndModule)	\
    ( (This)->lpVtbl -> LoadLibrary(This,pwzDllName,phndModule) ) 

#define ICLRRuntimeInfo_GetProcAddress(This,pszProcName,ppProc)	\
    ( (This)->lpVtbl -> GetProcAddress(This,pszProcName,ppProc) ) 

#define ICLRRuntimeInfo_GetInterface(This,rclsid,riid,ppUnk)	\
    ( (This)->lpVtbl -> GetInterface(This,rclsid,riid,ppUnk) ) 

#define ICLRRuntimeInfo_IsLoadable(This,pbLoadable)	\
    ( (This)->lpVtbl -> IsLoadable(This,pbLoadable) ) 

#define ICLRRuntimeInfo_SetDefaultStartupFlags(This,dwStartupFlags,pwzHostConfigFile)	\
    ( (This)->lpVtbl -> SetDefaultStartupFlags(This,dwStartupFlags,pwzHostConfigFile) ) 

#define ICLRRuntimeInfo_GetDefaultStartupFlags(This,pdwStartupFlags,pwzHostConfigFile,pcchHostConfigFile)	\
    ( (This)->lpVtbl -> GetDefaultStartupFlags(This,pdwStartupFlags,pwzHostConfigFile,pcchHostConfigFile) ) 

#define ICLRRuntimeInfo_BindAsLegacyV2Runtime(This)	\
    ( (This)->lpVtbl -> BindAsLegacyV2Runtime(This) ) 

#define ICLRRuntimeInfo_IsStarted(This,pbStarted,pdwStartupFlags)	\
    ( (This)->lpVtbl -> IsStarted(This,pbStarted,pdwStartupFlags) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICLRRuntimeInfo_INTERFACE_DEFINED__ */


#ifndef __ICLRStrongName_INTERFACE_DEFINED__
#define __ICLRStrongName_INTERFACE_DEFINED__

/* interface ICLRStrongName */
/* [object][local][helpstring][version][uuid] */ 


EXTERN_C const IID IID_ICLRStrongName;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9FD93CCF-3280-4391-B3A9-96E1CDE77C8D")
    ICLRStrongName : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetHashFromAssemblyFile( 
            /* [annotation][in] */ 
            _In_  LPCSTR pszFilePath,
            /* [annotation][out][in] */ 
            _Inout_  unsigned int *piHashAlg,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(cchHash,*pchHash)  BYTE *pbHash,
            /* [annotation][in] */ 
            _In_  DWORD cchHash,
            /* [annotation][out] */ 
            _Out_  DWORD *pchHash) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetHashFromAssemblyFileW( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pwzFilePath,
            /* [annotation][out][in] */ 
            _Inout_  unsigned int *piHashAlg,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(cchHash,*pchHash)  BYTE *pbHash,
            /* [annotation][in] */ 
            _In_  DWORD cchHash,
            /* [annotation][out] */ 
            _Out_  DWORD *pchHash) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetHashFromBlob( 
            /* [annotation][in] */ 
            _In_  BYTE *pbBlob,
            /* [annotation][in] */ 
            _In_  DWORD cchBlob,
            /* [annotation][out][in] */ 
            _Inout_  unsigned int *piHashAlg,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(cchHash,*pchHash)  BYTE *pbHash,
            /* [annotation][in] */ 
            _In_  DWORD cchHash,
            /* [annotation][out] */ 
            _Out_  DWORD *pchHash) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetHashFromFile( 
            /* [annotation][in] */ 
            _In_  LPCSTR pszFilePath,
            /* [annotation][out][in] */ 
            _Inout_  unsigned int *piHashAlg,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(cchHash,*pchHash)  BYTE *pbHash,
            /* [annotation][in] */ 
            _In_  DWORD cchHash,
            /* [annotation][out] */ 
            _Out_  DWORD *pchHash) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetHashFromFileW( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pwzFilePath,
            /* [annotation][out][in] */ 
            _Inout_  unsigned int *piHashAlg,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(cchHash,*pchHash)  BYTE *pbHash,
            /* [annotation][in] */ 
            _In_  DWORD cchHash,
            /* [annotation][out] */ 
            _Out_  DWORD *pchHash) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetHashFromHandle( 
            /* [annotation][in] */ 
            _In_  HANDLE hFile,
            /* [annotation][out][in] */ 
            _Inout_  unsigned int *piHashAlg,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(cchHash,*pchHash)  BYTE *pbHash,
            /* [annotation][in] */ 
            _In_  DWORD cchHash,
            /* [annotation][out] */ 
            _Out_  DWORD *pchHash) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StrongNameCompareAssemblies( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pwzAssembly1,
            /* [annotation][in] */ 
            _In_  LPCWSTR pwzAssembly2,
            /* [annotation][retval][out] */ 
            _Out_retval_  DWORD *pdwResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StrongNameFreeBuffer( 
            /* [annotation][in] */ 
            _In_  BYTE *pbMemory) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StrongNameGetBlob( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pwzFilePath,
            /* [annotation][length_is][size_is][out][in] */ 
            _Inout_updates_to_(*pcbBlob,*pcbBlob)  BYTE *pbBlob,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcbBlob) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StrongNameGetBlobFromImage( 
            /* [annotation][size_is][in] */ 
            _In_reads_(dwLength)  BYTE *pbBase,
            /* [annotation][in] */ 
            _In_  DWORD dwLength,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(*pcbBlob,*pcbBlob)  BYTE *pbBlob,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcbBlob) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StrongNameGetPublicKey( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pwzKeyContainer,
            /* [annotation][in] */ 
            _In_  BYTE *pbKeyBlob,
            /* [annotation][in] */ 
            _In_  ULONG cbKeyBlob,
            /* [annotation][out] */ 
            _Out_  BYTE **ppbPublicKeyBlob,
            /* [annotation][out] */ 
            _Out_  ULONG *pcbPublicKeyBlob) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StrongNameHashSize( 
            /* [annotation][in] */ 
            _In_  ULONG ulHashAlg,
            /* [annotation][retval][out] */ 
            _Out_retval_  DWORD *pcbSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StrongNameKeyDelete( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pwzKeyContainer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StrongNameKeyGen( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pwzKeyContainer,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][out] */ 
            _Out_  BYTE **ppbKeyBlob,
            /* [annotation][out] */ 
            _Out_  ULONG *pcbKeyBlob) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StrongNameKeyGenEx( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pwzKeyContainer,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][in] */ 
            _In_  DWORD dwKeySize,
            /* [annotation][out] */ 
            _Out_  BYTE **ppbKeyBlob,
            /* [annotation][out] */ 
            _Out_  ULONG *pcbKeyBlob) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StrongNameKeyInstall( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pwzKeyContainer,
            /* [annotation][in] */ 
            _In_  BYTE *pbKeyBlob,
            /* [annotation][in] */ 
            _In_  ULONG cbKeyBlob) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StrongNameSignatureGeneration( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pwzFilePath,
            /* [annotation][in] */ 
            _In_  LPCWSTR pwzKeyContainer,
            /* [annotation][in] */ 
            _In_  BYTE *pbKeyBlob,
            /* [annotation][in] */ 
            _In_  ULONG cbKeyBlob,
            /* [annotation][out] */ 
            _Out_  BYTE **ppbSignatureBlob,
            /* [annotation][out] */ 
            _Out_  ULONG *pcbSignatureBlob) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StrongNameSignatureGenerationEx( 
            /* [annotation][in] */ 
            _In_  LPCWSTR wszFilePath,
            /* [annotation][in] */ 
            _In_  LPCWSTR wszKeyContainer,
            /* [annotation][in] */ 
            _In_  BYTE *pbKeyBlob,
            /* [annotation][in] */ 
            _In_  ULONG cbKeyBlob,
            /* [annotation][out] */ 
            _Out_  BYTE **ppbSignatureBlob,
            /* [annotation][out] */ 
            _Out_  ULONG *pcbSignatureBlob,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StrongNameSignatureSize( 
            /* [annotation][in] */ 
            _In_  BYTE *pbPublicKeyBlob,
            /* [annotation][in] */ 
            _In_  ULONG cbPublicKeyBlob,
            /* [annotation][in] */ 
            _In_  DWORD *pcbSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StrongNameSignatureVerification( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pwzFilePath,
            /* [annotation][in] */ 
            _In_  DWORD dwInFlags,
            /* [annotation][retval][out] */ 
            _Out_retval_  DWORD *pdwOutFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StrongNameSignatureVerificationEx( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pwzFilePath,
            /* [annotation][in] */ 
            _In_  BOOLEAN fForceVerification,
            /* [annotation][retval][out] */ 
            _Out_retval_  BOOLEAN *pfWasVerified) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StrongNameSignatureVerificationFromImage( 
            /* [annotation][in] */ 
            _In_  BYTE *pbBase,
            /* [annotation][in] */ 
            _In_  DWORD dwLength,
            /* [annotation][in] */ 
            _In_  DWORD dwInFlags,
            /* [annotation][retval][out] */ 
            _Out_retval_  DWORD *pdwOutFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StrongNameTokenFromAssembly( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pwzFilePath,
            /* [annotation][out] */ 
            _Out_  BYTE **ppbStrongNameToken,
            /* [annotation][out] */ 
            _Out_  ULONG *pcbStrongNameToken) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StrongNameTokenFromAssemblyEx( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pwzFilePath,
            /* [annotation][out] */ 
            _Out_  BYTE **ppbStrongNameToken,
            /* [annotation][out] */ 
            _Out_  ULONG *pcbStrongNameToken,
            /* [annotation][out] */ 
            _Out_  BYTE **ppbPublicKeyBlob,
            /* [annotation][out] */ 
            _Out_  ULONG *pcbPublicKeyBlob) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StrongNameTokenFromPublicKey( 
            /* [annotation][in] */ 
            _In_  BYTE *pbPublicKeyBlob,
            /* [annotation][in] */ 
            _In_  ULONG cbPublicKeyBlob,
            /* [annotation][out] */ 
            _Out_  BYTE **ppbStrongNameToken,
            /* [annotation][out] */ 
            _Out_  ULONG *pcbStrongNameToken) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICLRStrongNameVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICLRStrongName * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICLRStrongName * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICLRStrongName * This);
        
        DECLSPEC_XFGVIRT(ICLRStrongName, GetHashFromAssemblyFile)
        HRESULT ( STDMETHODCALLTYPE *GetHashFromAssemblyFile )( 
            ICLRStrongName * This,
            /* [annotation][in] */ 
            _In_  LPCSTR pszFilePath,
            /* [annotation][out][in] */ 
            _Inout_  unsigned int *piHashAlg,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(cchHash,*pchHash)  BYTE *pbHash,
            /* [annotation][in] */ 
            _In_  DWORD cchHash,
            /* [annotation][out] */ 
            _Out_  DWORD *pchHash);
        
        DECLSPEC_XFGVIRT(ICLRStrongName, GetHashFromAssemblyFileW)
        HRESULT ( STDMETHODCALLTYPE *GetHashFromAssemblyFileW )( 
            ICLRStrongName * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pwzFilePath,
            /* [annotation][out][in] */ 
            _Inout_  unsigned int *piHashAlg,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(cchHash,*pchHash)  BYTE *pbHash,
            /* [annotation][in] */ 
            _In_  DWORD cchHash,
            /* [annotation][out] */ 
            _Out_  DWORD *pchHash);
        
        DECLSPEC_XFGVIRT(ICLRStrongName, GetHashFromBlob)
        HRESULT ( STDMETHODCALLTYPE *GetHashFromBlob )( 
            ICLRStrongName * This,
            /* [annotation][in] */ 
            _In_  BYTE *pbBlob,
            /* [annotation][in] */ 
            _In_  DWORD cchBlob,
            /* [annotation][out][in] */ 
            _Inout_  unsigned int *piHashAlg,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(cchHash,*pchHash)  BYTE *pbHash,
            /* [annotation][in] */ 
            _In_  DWORD cchHash,
            /* [annotation][out] */ 
            _Out_  DWORD *pchHash);
        
        DECLSPEC_XFGVIRT(ICLRStrongName, GetHashFromFile)
        HRESULT ( STDMETHODCALLTYPE *GetHashFromFile )( 
            ICLRStrongName * This,
            /* [annotation][in] */ 
            _In_  LPCSTR pszFilePath,
            /* [annotation][out][in] */ 
            _Inout_  unsigned int *piHashAlg,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(cchHash,*pchHash)  BYTE *pbHash,
            /* [annotation][in] */ 
            _In_  DWORD cchHash,
            /* [annotation][out] */ 
            _Out_  DWORD *pchHash);
        
        DECLSPEC_XFGVIRT(ICLRStrongName, GetHashFromFileW)
        HRESULT ( STDMETHODCALLTYPE *GetHashFromFileW )( 
            ICLRStrongName * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pwzFilePath,
            /* [annotation][out][in] */ 
            _Inout_  unsigned int *piHashAlg,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(cchHash,*pchHash)  BYTE *pbHash,
            /* [annotation][in] */ 
            _In_  DWORD cchHash,
            /* [annotation][out] */ 
            _Out_  DWORD *pchHash);
        
        DECLSPEC_XFGVIRT(ICLRStrongName, GetHashFromHandle)
        HRESULT ( STDMETHODCALLTYPE *GetHashFromHandle )( 
            ICLRStrongName * This,
            /* [annotation][in] */ 
            _In_  HANDLE hFile,
            /* [annotation][out][in] */ 
            _Inout_  unsigned int *piHashAlg,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(cchHash,*pchHash)  BYTE *pbHash,
            /* [annotation][in] */ 
            _In_  DWORD cchHash,
            /* [annotation][out] */ 
            _Out_  DWORD *pchHash);
        
        DECLSPEC_XFGVIRT(ICLRStrongName, StrongNameCompareAssemblies)
        HRESULT ( STDMETHODCALLTYPE *StrongNameCompareAssemblies )( 
            ICLRStrongName * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pwzAssembly1,
            /* [annotation][in] */ 
            _In_  LPCWSTR pwzAssembly2,
            /* [annotation][retval][out] */ 
            _Out_retval_  DWORD *pdwResult);
        
        DECLSPEC_XFGVIRT(ICLRStrongName, StrongNameFreeBuffer)
        HRESULT ( STDMETHODCALLTYPE *StrongNameFreeBuffer )( 
            ICLRStrongName * This,
            /* [annotation][in] */ 
            _In_  BYTE *pbMemory);
        
        DECLSPEC_XFGVIRT(ICLRStrongName, StrongNameGetBlob)
        HRESULT ( STDMETHODCALLTYPE *StrongNameGetBlob )( 
            ICLRStrongName * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pwzFilePath,
            /* [annotation][length_is][size_is][out][in] */ 
            _Inout_updates_to_(*pcbBlob,*pcbBlob)  BYTE *pbBlob,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcbBlob);
        
        DECLSPEC_XFGVIRT(ICLRStrongName, StrongNameGetBlobFromImage)
        HRESULT ( STDMETHODCALLTYPE *StrongNameGetBlobFromImage )( 
            ICLRStrongName * This,
            /* [annotation][size_is][in] */ 
            _In_reads_(dwLength)  BYTE *pbBase,
            /* [annotation][in] */ 
            _In_  DWORD dwLength,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(*pcbBlob,*pcbBlob)  BYTE *pbBlob,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcbBlob);
        
        DECLSPEC_XFGVIRT(ICLRStrongName, StrongNameGetPublicKey)
        HRESULT ( STDMETHODCALLTYPE *StrongNameGetPublicKey )( 
            ICLRStrongName * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pwzKeyContainer,
            /* [annotation][in] */ 
            _In_  BYTE *pbKeyBlob,
            /* [annotation][in] */ 
            _In_  ULONG cbKeyBlob,
            /* [annotation][out] */ 
            _Out_  BYTE **ppbPublicKeyBlob,
            /* [annotation][out] */ 
            _Out_  ULONG *pcbPublicKeyBlob);
        
        DECLSPEC_XFGVIRT(ICLRStrongName, StrongNameHashSize)
        HRESULT ( STDMETHODCALLTYPE *StrongNameHashSize )( 
            ICLRStrongName * This,
            /* [annotation][in] */ 
            _In_  ULONG ulHashAlg,
            /* [annotation][retval][out] */ 
            _Out_retval_  DWORD *pcbSize);
        
        DECLSPEC_XFGVIRT(ICLRStrongName, StrongNameKeyDelete)
        HRESULT ( STDMETHODCALLTYPE *StrongNameKeyDelete )( 
            ICLRStrongName * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pwzKeyContainer);
        
        DECLSPEC_XFGVIRT(ICLRStrongName, StrongNameKeyGen)
        HRESULT ( STDMETHODCALLTYPE *StrongNameKeyGen )( 
            ICLRStrongName * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pwzKeyContainer,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][out] */ 
            _Out_  BYTE **ppbKeyBlob,
            /* [annotation][out] */ 
            _Out_  ULONG *pcbKeyBlob);
        
        DECLSPEC_XFGVIRT(ICLRStrongName, StrongNameKeyGenEx)
        HRESULT ( STDMETHODCALLTYPE *StrongNameKeyGenEx )( 
            ICLRStrongName * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pwzKeyContainer,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][in] */ 
            _In_  DWORD dwKeySize,
            /* [annotation][out] */ 
            _Out_  BYTE **ppbKeyBlob,
            /* [annotation][out] */ 
            _Out_  ULONG *pcbKeyBlob);
        
        DECLSPEC_XFGVIRT(ICLRStrongName, StrongNameKeyInstall)
        HRESULT ( STDMETHODCALLTYPE *StrongNameKeyInstall )( 
            ICLRStrongName * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pwzKeyContainer,
            /* [annotation][in] */ 
            _In_  BYTE *pbKeyBlob,
            /* [annotation][in] */ 
            _In_  ULONG cbKeyBlob);
        
        DECLSPEC_XFGVIRT(ICLRStrongName, StrongNameSignatureGeneration)
        HRESULT ( STDMETHODCALLTYPE *StrongNameSignatureGeneration )( 
            ICLRStrongName * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pwzFilePath,
            /* [annotation][in] */ 
            _In_  LPCWSTR pwzKeyContainer,
            /* [annotation][in] */ 
            _In_  BYTE *pbKeyBlob,
            /* [annotation][in] */ 
            _In_  ULONG cbKeyBlob,
            /* [annotation][out] */ 
            _Out_  BYTE **ppbSignatureBlob,
            /* [annotation][out] */ 
            _Out_  ULONG *pcbSignatureBlob);
        
        DECLSPEC_XFGVIRT(ICLRStrongName, StrongNameSignatureGenerationEx)
        HRESULT ( STDMETHODCALLTYPE *StrongNameSignatureGenerationEx )( 
            ICLRStrongName * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR wszFilePath,
            /* [annotation][in] */ 
            _In_  LPCWSTR wszKeyContainer,
            /* [annotation][in] */ 
            _In_  BYTE *pbKeyBlob,
            /* [annotation][in] */ 
            _In_  ULONG cbKeyBlob,
            /* [annotation][out] */ 
            _Out_  BYTE **ppbSignatureBlob,
            /* [annotation][out] */ 
            _Out_  ULONG *pcbSignatureBlob,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags);
        
        DECLSPEC_XFGVIRT(ICLRStrongName, StrongNameSignatureSize)
        HRESULT ( STDMETHODCALLTYPE *StrongNameSignatureSize )( 
            ICLRStrongName * This,
            /* [annotation][in] */ 
            _In_  BYTE *pbPublicKeyBlob,
            /* [annotation][in] */ 
            _In_  ULONG cbPublicKeyBlob,
            /* [annotation][in] */ 
            _In_  DWORD *pcbSize);
        
        DECLSPEC_XFGVIRT(ICLRStrongName, StrongNameSignatureVerification)
        HRESULT ( STDMETHODCALLTYPE *StrongNameSignatureVerification )( 
            ICLRStrongName * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pwzFilePath,
            /* [annotation][in] */ 
            _In_  DWORD dwInFlags,
            /* [annotation][retval][out] */ 
            _Out_retval_  DWORD *pdwOutFlags);
        
        DECLSPEC_XFGVIRT(ICLRStrongName, StrongNameSignatureVerificationEx)
        HRESULT ( STDMETHODCALLTYPE *StrongNameSignatureVerificationEx )( 
            ICLRStrongName * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pwzFilePath,
            /* [annotation][in] */ 
            _In_  BOOLEAN fForceVerification,
            /* [annotation][retval][out] */ 
            _Out_retval_  BOOLEAN *pfWasVerified);
        
        DECLSPEC_XFGVIRT(ICLRStrongName, StrongNameSignatureVerificationFromImage)
        HRESULT ( STDMETHODCALLTYPE *StrongNameSignatureVerificationFromImage )( 
            ICLRStrongName * This,
            /* [annotation][in] */ 
            _In_  BYTE *pbBase,
            /* [annotation][in] */ 
            _In_  DWORD dwLength,
            /* [annotation][in] */ 
            _In_  DWORD dwInFlags,
            /* [annotation][retval][out] */ 
            _Out_retval_  DWORD *pdwOutFlags);
        
        DECLSPEC_XFGVIRT(ICLRStrongName, StrongNameTokenFromAssembly)
        HRESULT ( STDMETHODCALLTYPE *StrongNameTokenFromAssembly )( 
            ICLRStrongName * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pwzFilePath,
            /* [annotation][out] */ 
            _Out_  BYTE **ppbStrongNameToken,
            /* [annotation][out] */ 
            _Out_  ULONG *pcbStrongNameToken);
        
        DECLSPEC_XFGVIRT(ICLRStrongName, StrongNameTokenFromAssemblyEx)
        HRESULT ( STDMETHODCALLTYPE *StrongNameTokenFromAssemblyEx )( 
            ICLRStrongName * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pwzFilePath,
            /* [annotation][out] */ 
            _Out_  BYTE **ppbStrongNameToken,
            /* [annotation][out] */ 
            _Out_  ULONG *pcbStrongNameToken,
            /* [annotation][out] */ 
            _Out_  BYTE **ppbPublicKeyBlob,
            /* [annotation][out] */ 
            _Out_  ULONG *pcbPublicKeyBlob);
        
        DECLSPEC_XFGVIRT(ICLRStrongName, StrongNameTokenFromPublicKey)
        HRESULT ( STDMETHODCALLTYPE *StrongNameTokenFromPublicKey )( 
            ICLRStrongName * This,
            /* [annotation][in] */ 
            _In_  BYTE *pbPublicKeyBlob,
            /* [annotation][in] */ 
            _In_  ULONG cbPublicKeyBlob,
            /* [annotation][out] */ 
            _Out_  BYTE **ppbStrongNameToken,
            /* [annotation][out] */ 
            _Out_  ULONG *pcbStrongNameToken);
        
        END_INTERFACE
    } ICLRStrongNameVtbl;

    interface ICLRStrongName
    {
        CONST_VTBL struct ICLRStrongNameVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICLRStrongName_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICLRStrongName_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICLRStrongName_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICLRStrongName_GetHashFromAssemblyFile(This,pszFilePath,piHashAlg,pbHash,cchHash,pchHash)	\
    ( (This)->lpVtbl -> GetHashFromAssemblyFile(This,pszFilePath,piHashAlg,pbHash,cchHash,pchHash) ) 

#define ICLRStrongName_GetHashFromAssemblyFileW(This,pwzFilePath,piHashAlg,pbHash,cchHash,pchHash)	\
    ( (This)->lpVtbl -> GetHashFromAssemblyFileW(This,pwzFilePath,piHashAlg,pbHash,cchHash,pchHash) ) 

#define ICLRStrongName_GetHashFromBlob(This,pbBlob,cchBlob,piHashAlg,pbHash,cchHash,pchHash)	\
    ( (This)->lpVtbl -> GetHashFromBlob(This,pbBlob,cchBlob,piHashAlg,pbHash,cchHash,pchHash) ) 

#define ICLRStrongName_GetHashFromFile(This,pszFilePath,piHashAlg,pbHash,cchHash,pchHash)	\
    ( (This)->lpVtbl -> GetHashFromFile(This,pszFilePath,piHashAlg,pbHash,cchHash,pchHash) ) 

#define ICLRStrongName_GetHashFromFileW(This,pwzFilePath,piHashAlg,pbHash,cchHash,pchHash)	\
    ( (This)->lpVtbl -> GetHashFromFileW(This,pwzFilePath,piHashAlg,pbHash,cchHash,pchHash) ) 

#define ICLRStrongName_GetHashFromHandle(This,hFile,piHashAlg,pbHash,cchHash,pchHash)	\
    ( (This)->lpVtbl -> GetHashFromHandle(This,hFile,piHashAlg,pbHash,cchHash,pchHash) ) 

#define ICLRStrongName_StrongNameCompareAssemblies(This,pwzAssembly1,pwzAssembly2,pdwResult)	\
    ( (This)->lpVtbl -> StrongNameCompareAssemblies(This,pwzAssembly1,pwzAssembly2,pdwResult) ) 

#define ICLRStrongName_StrongNameFreeBuffer(This,pbMemory)	\
    ( (This)->lpVtbl -> StrongNameFreeBuffer(This,pbMemory) ) 

#define ICLRStrongName_StrongNameGetBlob(This,pwzFilePath,pbBlob,pcbBlob)	\
    ( (This)->lpVtbl -> StrongNameGetBlob(This,pwzFilePath,pbBlob,pcbBlob) ) 

#define ICLRStrongName_StrongNameGetBlobFromImage(This,pbBase,dwLength,pbBlob,pcbBlob)	\
    ( (This)->lpVtbl -> StrongNameGetBlobFromImage(This,pbBase,dwLength,pbBlob,pcbBlob) ) 

#define ICLRStrongName_StrongNameGetPublicKey(This,pwzKeyContainer,pbKeyBlob,cbKeyBlob,ppbPublicKeyBlob,pcbPublicKeyBlob)	\
    ( (This)->lpVtbl -> StrongNameGetPublicKey(This,pwzKeyContainer,pbKeyBlob,cbKeyBlob,ppbPublicKeyBlob,pcbPublicKeyBlob) ) 

#define ICLRStrongName_StrongNameHashSize(This,ulHashAlg,pcbSize)	\
    ( (This)->lpVtbl -> StrongNameHashSize(This,ulHashAlg,pcbSize) ) 

#define ICLRStrongName_StrongNameKeyDelete(This,pwzKeyContainer)	\
    ( (This)->lpVtbl -> StrongNameKeyDelete(This,pwzKeyContainer) ) 

#define ICLRStrongName_StrongNameKeyGen(This,pwzKeyContainer,dwFlags,ppbKeyBlob,pcbKeyBlob)	\
    ( (This)->lpVtbl -> StrongNameKeyGen(This,pwzKeyContainer,dwFlags,ppbKeyBlob,pcbKeyBlob) ) 

#define ICLRStrongName_StrongNameKeyGenEx(This,pwzKeyContainer,dwFlags,dwKeySize,ppbKeyBlob,pcbKeyBlob)	\
    ( (This)->lpVtbl -> StrongNameKeyGenEx(This,pwzKeyContainer,dwFlags,dwKeySize,ppbKeyBlob,pcbKeyBlob) ) 

#define ICLRStrongName_StrongNameKeyInstall(This,pwzKeyContainer,pbKeyBlob,cbKeyBlob)	\
    ( (This)->lpVtbl -> StrongNameKeyInstall(This,pwzKeyContainer,pbKeyBlob,cbKeyBlob) ) 

#define ICLRStrongName_StrongNameSignatureGeneration(This,pwzFilePath,pwzKeyContainer,pbKeyBlob,cbKeyBlob,ppbSignatureBlob,pcbSignatureBlob)	\
    ( (This)->lpVtbl -> StrongNameSignatureGeneration(This,pwzFilePath,pwzKeyContainer,pbKeyBlob,cbKeyBlob,ppbSignatureBlob,pcbSignatureBlob) ) 

#define ICLRStrongName_StrongNameSignatureGenerationEx(This,wszFilePath,wszKeyContainer,pbKeyBlob,cbKeyBlob,ppbSignatureBlob,pcbSignatureBlob,dwFlags)	\
    ( (This)->lpVtbl -> StrongNameSignatureGenerationEx(This,wszFilePath,wszKeyContainer,pbKeyBlob,cbKeyBlob,ppbSignatureBlob,pcbSignatureBlob,dwFlags) ) 

#define ICLRStrongName_StrongNameSignatureSize(This,pbPublicKeyBlob,cbPublicKeyBlob,pcbSize)	\
    ( (This)->lpVtbl -> StrongNameSignatureSize(This,pbPublicKeyBlob,cbPublicKeyBlob,pcbSize) ) 

#define ICLRStrongName_StrongNameSignatureVerification(This,pwzFilePath,dwInFlags,pdwOutFlags)	\
    ( (This)->lpVtbl -> StrongNameSignatureVerification(This,pwzFilePath,dwInFlags,pdwOutFlags) ) 

#define ICLRStrongName_StrongNameSignatureVerificationEx(This,pwzFilePath,fForceVerification,pfWasVerified)	\
    ( (This)->lpVtbl -> StrongNameSignatureVerificationEx(This,pwzFilePath,fForceVerification,pfWasVerified) ) 

#define ICLRStrongName_StrongNameSignatureVerificationFromImage(This,pbBase,dwLength,dwInFlags,pdwOutFlags)	\
    ( (This)->lpVtbl -> StrongNameSignatureVerificationFromImage(This,pbBase,dwLength,dwInFlags,pdwOutFlags) ) 

#define ICLRStrongName_StrongNameTokenFromAssembly(This,pwzFilePath,ppbStrongNameToken,pcbStrongNameToken)	\
    ( (This)->lpVtbl -> StrongNameTokenFromAssembly(This,pwzFilePath,ppbStrongNameToken,pcbStrongNameToken) ) 

#define ICLRStrongName_StrongNameTokenFromAssemblyEx(This,pwzFilePath,ppbStrongNameToken,pcbStrongNameToken,ppbPublicKeyBlob,pcbPublicKeyBlob)	\
    ( (This)->lpVtbl -> StrongNameTokenFromAssemblyEx(This,pwzFilePath,ppbStrongNameToken,pcbStrongNameToken,ppbPublicKeyBlob,pcbPublicKeyBlob) ) 

#define ICLRStrongName_StrongNameTokenFromPublicKey(This,pbPublicKeyBlob,cbPublicKeyBlob,ppbStrongNameToken,pcbStrongNameToken)	\
    ( (This)->lpVtbl -> StrongNameTokenFromPublicKey(This,pbPublicKeyBlob,cbPublicKeyBlob,ppbStrongNameToken,pcbStrongNameToken) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICLRStrongName_INTERFACE_DEFINED__ */


#ifndef __ICLRStrongName2_INTERFACE_DEFINED__
#define __ICLRStrongName2_INTERFACE_DEFINED__

/* interface ICLRStrongName2 */
/* [object][local][helpstring][version][uuid] */ 


EXTERN_C const IID IID_ICLRStrongName2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C22ED5C5-4B59-4975-90EB-85EA55C0069B")
    ICLRStrongName2 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE StrongNameGetPublicKeyEx( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pwzKeyContainer,
            /* [annotation][in] */ 
            _In_  BYTE *pbKeyBlob,
            /* [annotation][in] */ 
            _In_  ULONG cbKeyBlob,
            /* [annotation][out] */ 
            _Out_  BYTE **ppbPublicKeyBlob,
            /* [annotation][out] */ 
            _Out_  ULONG *pcbPublicKeyBlob,
            /* [annotation][in] */ 
            _In_  ULONG uHashAlgId,
            /* [annotation][in] */ 
            _In_  ULONG uReserved) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StrongNameSignatureVerificationEx2( 
            /* [annotation][in] */ 
            _In_  LPCWSTR wszFilePath,
            /* [annotation][in] */ 
            _In_  BOOLEAN fForceVerification,
            /* [annotation][in] */ 
            _In_  BYTE *pbEcmaPublicKey,
            /* [annotation][in] */ 
            _In_  DWORD cbEcmaPublicKey,
            /* [annotation][out] */ 
            _Out_  BOOLEAN *pfWasVerified) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICLRStrongName2Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICLRStrongName2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICLRStrongName2 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICLRStrongName2 * This);
        
        DECLSPEC_XFGVIRT(ICLRStrongName2, StrongNameGetPublicKeyEx)
        HRESULT ( STDMETHODCALLTYPE *StrongNameGetPublicKeyEx )( 
            ICLRStrongName2 * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pwzKeyContainer,
            /* [annotation][in] */ 
            _In_  BYTE *pbKeyBlob,
            /* [annotation][in] */ 
            _In_  ULONG cbKeyBlob,
            /* [annotation][out] */ 
            _Out_  BYTE **ppbPublicKeyBlob,
            /* [annotation][out] */ 
            _Out_  ULONG *pcbPublicKeyBlob,
            /* [annotation][in] */ 
            _In_  ULONG uHashAlgId,
            /* [annotation][in] */ 
            _In_  ULONG uReserved);
        
        DECLSPEC_XFGVIRT(ICLRStrongName2, StrongNameSignatureVerificationEx2)
        HRESULT ( STDMETHODCALLTYPE *StrongNameSignatureVerificationEx2 )( 
            ICLRStrongName2 * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR wszFilePath,
            /* [annotation][in] */ 
            _In_  BOOLEAN fForceVerification,
            /* [annotation][in] */ 
            _In_  BYTE *pbEcmaPublicKey,
            /* [annotation][in] */ 
            _In_  DWORD cbEcmaPublicKey,
            /* [annotation][out] */ 
            _Out_  BOOLEAN *pfWasVerified);
        
        END_INTERFACE
    } ICLRStrongName2Vtbl;

    interface ICLRStrongName2
    {
        CONST_VTBL struct ICLRStrongName2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICLRStrongName2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICLRStrongName2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICLRStrongName2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICLRStrongName2_StrongNameGetPublicKeyEx(This,pwzKeyContainer,pbKeyBlob,cbKeyBlob,ppbPublicKeyBlob,pcbPublicKeyBlob,uHashAlgId,uReserved)	\
    ( (This)->lpVtbl -> StrongNameGetPublicKeyEx(This,pwzKeyContainer,pbKeyBlob,cbKeyBlob,ppbPublicKeyBlob,pcbPublicKeyBlob,uHashAlgId,uReserved) ) 

#define ICLRStrongName2_StrongNameSignatureVerificationEx2(This,wszFilePath,fForceVerification,pbEcmaPublicKey,cbEcmaPublicKey,pfWasVerified)	\
    ( (This)->lpVtbl -> StrongNameSignatureVerificationEx2(This,wszFilePath,fForceVerification,pbEcmaPublicKey,cbEcmaPublicKey,pfWasVerified) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICLRStrongName2_INTERFACE_DEFINED__ */


#ifndef __ICLRStrongName3_INTERFACE_DEFINED__
#define __ICLRStrongName3_INTERFACE_DEFINED__

/* interface ICLRStrongName3 */
/* [object][local][helpstring][version][uuid] */ 


EXTERN_C const IID IID_ICLRStrongName3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("22c7089b-bbd3-414a-b698-210f263f1fed")
    ICLRStrongName3 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE StrongNameDigestGenerate( 
            /* [annotation][in] */ 
            _In_  LPCWSTR wszFilePath,
            /* [annotation][out] */ 
            _Out_  BYTE **ppbDigestBlob,
            /* [annotation][out] */ 
            _Out_  ULONG *pcbDigestBlob,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StrongNameDigestSign( 
            /* [annotation][in] */ 
            _In_  LPCWSTR wszKeyContainer,
            /* [annotation][size_is][in] */ 
            _In_reads_(cbKeyBlob)  BYTE *pbKeyBlob,
            /* [annotation][in] */ 
            _In_  ULONG cbKeyBlob,
            /* [annotation][size_is][in] */ 
            _In_reads_(cbDigestBlob)  BYTE *pbDigestBlob,
            /* [annotation][in] */ 
            _In_  ULONG cbDigestBlob,
            /* [annotation][in] */ 
            _In_  DWORD hashAlgId,
            /* [annotation][out] */ 
            _Out_  BYTE **ppbSignatureBlob,
            /* [annotation][out] */ 
            _Out_  ULONG *pcbSignatureBlob,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StrongNameDigestEmbed( 
            /* [annotation][in] */ 
            _In_  LPCWSTR wszFilePath,
            /* [annotation][size_is][in] */ 
            _In_reads_(cbSignatureBlob)  BYTE *pbSignatureBlob,
            /* [annotation][in] */ 
            _In_  ULONG cbSignatureBlob) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICLRStrongName3Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICLRStrongName3 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICLRStrongName3 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICLRStrongName3 * This);
        
        DECLSPEC_XFGVIRT(ICLRStrongName3, StrongNameDigestGenerate)
        HRESULT ( STDMETHODCALLTYPE *StrongNameDigestGenerate )( 
            ICLRStrongName3 * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR wszFilePath,
            /* [annotation][out] */ 
            _Out_  BYTE **ppbDigestBlob,
            /* [annotation][out] */ 
            _Out_  ULONG *pcbDigestBlob,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags);
        
        DECLSPEC_XFGVIRT(ICLRStrongName3, StrongNameDigestSign)
        HRESULT ( STDMETHODCALLTYPE *StrongNameDigestSign )( 
            ICLRStrongName3 * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR wszKeyContainer,
            /* [annotation][size_is][in] */ 
            _In_reads_(cbKeyBlob)  BYTE *pbKeyBlob,
            /* [annotation][in] */ 
            _In_  ULONG cbKeyBlob,
            /* [annotation][size_is][in] */ 
            _In_reads_(cbDigestBlob)  BYTE *pbDigestBlob,
            /* [annotation][in] */ 
            _In_  ULONG cbDigestBlob,
            /* [annotation][in] */ 
            _In_  DWORD hashAlgId,
            /* [annotation][out] */ 
            _Out_  BYTE **ppbSignatureBlob,
            /* [annotation][out] */ 
            _Out_  ULONG *pcbSignatureBlob,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags);
        
        DECLSPEC_XFGVIRT(ICLRStrongName3, StrongNameDigestEmbed)
        HRESULT ( STDMETHODCALLTYPE *StrongNameDigestEmbed )( 
            ICLRStrongName3 * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR wszFilePath,
            /* [annotation][size_is][in] */ 
            _In_reads_(cbSignatureBlob)  BYTE *pbSignatureBlob,
            /* [annotation][in] */ 
            _In_  ULONG cbSignatureBlob);
        
        END_INTERFACE
    } ICLRStrongName3Vtbl;

    interface ICLRStrongName3
    {
        CONST_VTBL struct ICLRStrongName3Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICLRStrongName3_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICLRStrongName3_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICLRStrongName3_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICLRStrongName3_StrongNameDigestGenerate(This,wszFilePath,ppbDigestBlob,pcbDigestBlob,dwFlags)	\
    ( (This)->lpVtbl -> StrongNameDigestGenerate(This,wszFilePath,ppbDigestBlob,pcbDigestBlob,dwFlags) ) 

#define ICLRStrongName3_StrongNameDigestSign(This,wszKeyContainer,pbKeyBlob,cbKeyBlob,pbDigestBlob,cbDigestBlob,hashAlgId,ppbSignatureBlob,pcbSignatureBlob,dwFlags)	\
    ( (This)->lpVtbl -> StrongNameDigestSign(This,wszKeyContainer,pbKeyBlob,cbKeyBlob,pbDigestBlob,cbDigestBlob,hashAlgId,ppbSignatureBlob,pcbSignatureBlob,dwFlags) ) 

#define ICLRStrongName3_StrongNameDigestEmbed(This,wszFilePath,pbSignatureBlob,cbSignatureBlob)	\
    ( (This)->lpVtbl -> StrongNameDigestEmbed(This,wszFilePath,pbSignatureBlob,cbSignatureBlob) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICLRStrongName3_INTERFACE_DEFINED__ */



#ifndef __CLRMetaHost_LIBRARY_DEFINED__
#define __CLRMetaHost_LIBRARY_DEFINED__

/* library CLRMetaHost */
/* [version][uuid] */ 









EXTERN_C const IID LIBID_CLRMetaHost;
#endif /* __CLRMetaHost_LIBRARY_DEFINED__ */

/* interface __MIDL_itf_metahost_0000_0010 */
/* [local] */ 

#endif // WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)


extern RPC_IF_HANDLE __MIDL_itf_metahost_0000_0010_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_metahost_0000_0010_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


