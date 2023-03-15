

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

#ifndef __mfcontentdecryptionmodule_h__
#define __mfcontentdecryptionmodule_h__

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

#ifndef __IMFContentDecryptionModuleSession_FWD_DEFINED__
#define __IMFContentDecryptionModuleSession_FWD_DEFINED__
typedef interface IMFContentDecryptionModuleSession IMFContentDecryptionModuleSession;

#endif 	/* __IMFContentDecryptionModuleSession_FWD_DEFINED__ */


#ifndef __IMFContentDecryptionModuleSessionCallbacks_FWD_DEFINED__
#define __IMFContentDecryptionModuleSessionCallbacks_FWD_DEFINED__
typedef interface IMFContentDecryptionModuleSessionCallbacks IMFContentDecryptionModuleSessionCallbacks;

#endif 	/* __IMFContentDecryptionModuleSessionCallbacks_FWD_DEFINED__ */


#ifndef __IMFContentDecryptionModule_FWD_DEFINED__
#define __IMFContentDecryptionModule_FWD_DEFINED__
typedef interface IMFContentDecryptionModule IMFContentDecryptionModule;

#endif 	/* __IMFContentDecryptionModule_FWD_DEFINED__ */


#ifndef __IMFContentDecryptionModuleAccess_FWD_DEFINED__
#define __IMFContentDecryptionModuleAccess_FWD_DEFINED__
typedef interface IMFContentDecryptionModuleAccess IMFContentDecryptionModuleAccess;

#endif 	/* __IMFContentDecryptionModuleAccess_FWD_DEFINED__ */


#ifndef __IMFContentDecryptionModuleFactory_FWD_DEFINED__
#define __IMFContentDecryptionModuleFactory_FWD_DEFINED__
typedef interface IMFContentDecryptionModuleFactory IMFContentDecryptionModuleFactory;

#endif 	/* __IMFContentDecryptionModuleFactory_FWD_DEFINED__ */


/* header files for imported files */
#include "mfmediaengine.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_mfcontentdecryptionmodule_0000_0000 */
/* [local] */ 

#pragma region Application Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP)


extern RPC_IF_HANDLE __MIDL_itf_mfcontentdecryptionmodule_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_mfcontentdecryptionmodule_0000_0000_v0_0_s_ifspec;

#ifndef __IMFContentDecryptionModuleSession_INTERFACE_DEFINED__
#define __IMFContentDecryptionModuleSession_INTERFACE_DEFINED__

/* interface IMFContentDecryptionModuleSession */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IMFContentDecryptionModuleSession;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4e233efd-1dd2-49e8-b577-d63eee4c0d33")
    IMFContentDecryptionModuleSession : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetSessionId( 
            /* [annotation][out] */ 
            _Out_  LPWSTR *sessionId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetExpiration( 
            /* [annotation][out] */ 
            _Out_  double *expiration) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetKeyStatuses( 
            /* [annotation][size_is][size_is][out] */ 
            _Out_writes_(*numKeyStatuses)  MFMediaKeyStatus **keyStatuses,
            /* [annotation][out] */ 
            _Out_  UINT *numKeyStatuses) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Load( 
            /* [annotation][in] */ 
            _In_  LPCWSTR sessionId,
            /* [annotation][out] */ 
            _Out_  BOOL *loaded) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GenerateRequest( 
            /* [annotation][in] */ 
            _In_  LPCWSTR initDataType,
            /* [annotation][size_is][in] */ 
            _In_reads_(initDataSize)  const BYTE *initData,
            /* [annotation][in] */ 
            _In_  DWORD initDataSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Update( 
            /* [annotation][size_is][in] */ 
            _In_reads_(responseSize)  const BYTE *response,
            /* [annotation][in] */ 
            _In_  DWORD responseSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Close( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Remove( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IMFContentDecryptionModuleSessionVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IMFContentDecryptionModuleSession * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IMFContentDecryptionModuleSession * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IMFContentDecryptionModuleSession * This);
        
        DECLSPEC_XFGVIRT(IMFContentDecryptionModuleSession, GetSessionId)
        HRESULT ( STDMETHODCALLTYPE *GetSessionId )( 
            __RPC__in IMFContentDecryptionModuleSession * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *sessionId);
        
        DECLSPEC_XFGVIRT(IMFContentDecryptionModuleSession, GetExpiration)
        HRESULT ( STDMETHODCALLTYPE *GetExpiration )( 
            __RPC__in IMFContentDecryptionModuleSession * This,
            /* [annotation][out] */ 
            _Out_  double *expiration);
        
        DECLSPEC_XFGVIRT(IMFContentDecryptionModuleSession, GetKeyStatuses)
        HRESULT ( STDMETHODCALLTYPE *GetKeyStatuses )( 
            __RPC__in IMFContentDecryptionModuleSession * This,
            /* [annotation][size_is][size_is][out] */ 
            _Out_writes_(*numKeyStatuses)  MFMediaKeyStatus **keyStatuses,
            /* [annotation][out] */ 
            _Out_  UINT *numKeyStatuses);
        
        DECLSPEC_XFGVIRT(IMFContentDecryptionModuleSession, Load)
        HRESULT ( STDMETHODCALLTYPE *Load )( 
            __RPC__in IMFContentDecryptionModuleSession * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR sessionId,
            /* [annotation][out] */ 
            _Out_  BOOL *loaded);
        
        DECLSPEC_XFGVIRT(IMFContentDecryptionModuleSession, GenerateRequest)
        HRESULT ( STDMETHODCALLTYPE *GenerateRequest )( 
            __RPC__in IMFContentDecryptionModuleSession * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR initDataType,
            /* [annotation][size_is][in] */ 
            _In_reads_(initDataSize)  const BYTE *initData,
            /* [annotation][in] */ 
            _In_  DWORD initDataSize);
        
        DECLSPEC_XFGVIRT(IMFContentDecryptionModuleSession, Update)
        HRESULT ( STDMETHODCALLTYPE *Update )( 
            __RPC__in IMFContentDecryptionModuleSession * This,
            /* [annotation][size_is][in] */ 
            _In_reads_(responseSize)  const BYTE *response,
            /* [annotation][in] */ 
            _In_  DWORD responseSize);
        
        DECLSPEC_XFGVIRT(IMFContentDecryptionModuleSession, Close)
        HRESULT ( STDMETHODCALLTYPE *Close )( 
            __RPC__in IMFContentDecryptionModuleSession * This);
        
        DECLSPEC_XFGVIRT(IMFContentDecryptionModuleSession, Remove)
        HRESULT ( STDMETHODCALLTYPE *Remove )( 
            __RPC__in IMFContentDecryptionModuleSession * This);
        
        END_INTERFACE
    } IMFContentDecryptionModuleSessionVtbl;

    interface IMFContentDecryptionModuleSession
    {
        CONST_VTBL struct IMFContentDecryptionModuleSessionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMFContentDecryptionModuleSession_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMFContentDecryptionModuleSession_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMFContentDecryptionModuleSession_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMFContentDecryptionModuleSession_GetSessionId(This,sessionId)	\
    ( (This)->lpVtbl -> GetSessionId(This,sessionId) ) 

#define IMFContentDecryptionModuleSession_GetExpiration(This,expiration)	\
    ( (This)->lpVtbl -> GetExpiration(This,expiration) ) 

#define IMFContentDecryptionModuleSession_GetKeyStatuses(This,keyStatuses,numKeyStatuses)	\
    ( (This)->lpVtbl -> GetKeyStatuses(This,keyStatuses,numKeyStatuses) ) 

#define IMFContentDecryptionModuleSession_Load(This,sessionId,loaded)	\
    ( (This)->lpVtbl -> Load(This,sessionId,loaded) ) 

#define IMFContentDecryptionModuleSession_GenerateRequest(This,initDataType,initData,initDataSize)	\
    ( (This)->lpVtbl -> GenerateRequest(This,initDataType,initData,initDataSize) ) 

#define IMFContentDecryptionModuleSession_Update(This,response,responseSize)	\
    ( (This)->lpVtbl -> Update(This,response,responseSize) ) 

#define IMFContentDecryptionModuleSession_Close(This)	\
    ( (This)->lpVtbl -> Close(This) ) 

#define IMFContentDecryptionModuleSession_Remove(This)	\
    ( (This)->lpVtbl -> Remove(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMFContentDecryptionModuleSession_INTERFACE_DEFINED__ */


#ifndef __IMFContentDecryptionModuleSessionCallbacks_INTERFACE_DEFINED__
#define __IMFContentDecryptionModuleSessionCallbacks_INTERFACE_DEFINED__

/* interface IMFContentDecryptionModuleSessionCallbacks */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IMFContentDecryptionModuleSessionCallbacks;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3f96ee40-ad81-4096-8470-59a4b770f89a")
    IMFContentDecryptionModuleSessionCallbacks : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE KeyMessage( 
            /* [annotation][in] */ 
            _In_  MF_MEDIAKEYSESSION_MESSAGETYPE messageType,
            /* [annotation][size_is][in] */ 
            _In_reads_(messageSize)  const BYTE *message,
            /* [annotation][in] */ 
            _In_  DWORD messageSize,
            /* [optional][in] */ __RPC__in LPCWSTR destinationURL) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE KeyStatusChanged( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IMFContentDecryptionModuleSessionCallbacksVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IMFContentDecryptionModuleSessionCallbacks * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IMFContentDecryptionModuleSessionCallbacks * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IMFContentDecryptionModuleSessionCallbacks * This);
        
        DECLSPEC_XFGVIRT(IMFContentDecryptionModuleSessionCallbacks, KeyMessage)
        HRESULT ( STDMETHODCALLTYPE *KeyMessage )( 
            __RPC__in IMFContentDecryptionModuleSessionCallbacks * This,
            /* [annotation][in] */ 
            _In_  MF_MEDIAKEYSESSION_MESSAGETYPE messageType,
            /* [annotation][size_is][in] */ 
            _In_reads_(messageSize)  const BYTE *message,
            /* [annotation][in] */ 
            _In_  DWORD messageSize,
            /* [optional][in] */ __RPC__in LPCWSTR destinationURL);
        
        DECLSPEC_XFGVIRT(IMFContentDecryptionModuleSessionCallbacks, KeyStatusChanged)
        HRESULT ( STDMETHODCALLTYPE *KeyStatusChanged )( 
            __RPC__in IMFContentDecryptionModuleSessionCallbacks * This);
        
        END_INTERFACE
    } IMFContentDecryptionModuleSessionCallbacksVtbl;

    interface IMFContentDecryptionModuleSessionCallbacks
    {
        CONST_VTBL struct IMFContentDecryptionModuleSessionCallbacksVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMFContentDecryptionModuleSessionCallbacks_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMFContentDecryptionModuleSessionCallbacks_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMFContentDecryptionModuleSessionCallbacks_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMFContentDecryptionModuleSessionCallbacks_KeyMessage(This,messageType,message,messageSize,destinationURL)	\
    ( (This)->lpVtbl -> KeyMessage(This,messageType,message,messageSize,destinationURL) ) 

#define IMFContentDecryptionModuleSessionCallbacks_KeyStatusChanged(This)	\
    ( (This)->lpVtbl -> KeyStatusChanged(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMFContentDecryptionModuleSessionCallbacks_INTERFACE_DEFINED__ */


#ifndef __IMFContentDecryptionModule_INTERFACE_DEFINED__
#define __IMFContentDecryptionModule_INTERFACE_DEFINED__

/* interface IMFContentDecryptionModule */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IMFContentDecryptionModule;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("87be986c-10be-4943-bf48-4b54ce1983a2")
    IMFContentDecryptionModule : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetContentEnabler( 
            /* [annotation][in] */ 
            _In_  IMFContentEnabler *contentEnabler,
            /* [annotation][in] */ 
            _In_  IMFAsyncResult *result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSuspendNotify( 
            /* [annotation][out] */ 
            _Out_  IMFCdmSuspendNotify **notify) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPMPHostApp( 
            /* [annotation][in] */ 
            _In_  IMFPMPHostApp *pmpHostApp) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateSession( 
            /* [annotation][in] */ 
            _In_  MF_MEDIAKEYSESSION_TYPE sessionType,
            /* [annotation][in] */ 
            _In_  IMFContentDecryptionModuleSessionCallbacks *callbacks,
            /* [annotation][out] */ 
            _Out_  IMFContentDecryptionModuleSession **session) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetServerCertificate( 
            /* [annotation][size_is][in] */ 
            _In_reads_(certificateSize)  const BYTE *certificate,
            /* [annotation][in] */ 
            _In_  DWORD certificateSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateTrustedInput( 
            /* [annotation][size_is][in] */ 
            _In_reads_(contentInitDataSize)  const BYTE *contentInitData,
            /* [annotation][in] */ 
            _In_  DWORD contentInitDataSize,
            /* [annotation][out] */ 
            _Out_  IMFTrustedInput **trustedInput) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetProtectionSystemIds( 
            /* [annotation][size_is][size_is][out] */ 
            _Out_writes_(*count)  GUID **systemIds,
            /* [annotation][out] */ 
            _Out_  DWORD *count) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IMFContentDecryptionModuleVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IMFContentDecryptionModule * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IMFContentDecryptionModule * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IMFContentDecryptionModule * This);
        
        DECLSPEC_XFGVIRT(IMFContentDecryptionModule, SetContentEnabler)
        HRESULT ( STDMETHODCALLTYPE *SetContentEnabler )( 
            __RPC__in IMFContentDecryptionModule * This,
            /* [annotation][in] */ 
            _In_  IMFContentEnabler *contentEnabler,
            /* [annotation][in] */ 
            _In_  IMFAsyncResult *result);
        
        DECLSPEC_XFGVIRT(IMFContentDecryptionModule, GetSuspendNotify)
        HRESULT ( STDMETHODCALLTYPE *GetSuspendNotify )( 
            __RPC__in IMFContentDecryptionModule * This,
            /* [annotation][out] */ 
            _Out_  IMFCdmSuspendNotify **notify);
        
        DECLSPEC_XFGVIRT(IMFContentDecryptionModule, SetPMPHostApp)
        HRESULT ( STDMETHODCALLTYPE *SetPMPHostApp )( 
            __RPC__in IMFContentDecryptionModule * This,
            /* [annotation][in] */ 
            _In_  IMFPMPHostApp *pmpHostApp);
        
        DECLSPEC_XFGVIRT(IMFContentDecryptionModule, CreateSession)
        HRESULT ( STDMETHODCALLTYPE *CreateSession )( 
            __RPC__in IMFContentDecryptionModule * This,
            /* [annotation][in] */ 
            _In_  MF_MEDIAKEYSESSION_TYPE sessionType,
            /* [annotation][in] */ 
            _In_  IMFContentDecryptionModuleSessionCallbacks *callbacks,
            /* [annotation][out] */ 
            _Out_  IMFContentDecryptionModuleSession **session);
        
        DECLSPEC_XFGVIRT(IMFContentDecryptionModule, SetServerCertificate)
        HRESULT ( STDMETHODCALLTYPE *SetServerCertificate )( 
            __RPC__in IMFContentDecryptionModule * This,
            /* [annotation][size_is][in] */ 
            _In_reads_(certificateSize)  const BYTE *certificate,
            /* [annotation][in] */ 
            _In_  DWORD certificateSize);
        
        DECLSPEC_XFGVIRT(IMFContentDecryptionModule, CreateTrustedInput)
        HRESULT ( STDMETHODCALLTYPE *CreateTrustedInput )( 
            __RPC__in IMFContentDecryptionModule * This,
            /* [annotation][size_is][in] */ 
            _In_reads_(contentInitDataSize)  const BYTE *contentInitData,
            /* [annotation][in] */ 
            _In_  DWORD contentInitDataSize,
            /* [annotation][out] */ 
            _Out_  IMFTrustedInput **trustedInput);
        
        DECLSPEC_XFGVIRT(IMFContentDecryptionModule, GetProtectionSystemIds)
        HRESULT ( STDMETHODCALLTYPE *GetProtectionSystemIds )( 
            __RPC__in IMFContentDecryptionModule * This,
            /* [annotation][size_is][size_is][out] */ 
            _Out_writes_(*count)  GUID **systemIds,
            /* [annotation][out] */ 
            _Out_  DWORD *count);
        
        END_INTERFACE
    } IMFContentDecryptionModuleVtbl;

    interface IMFContentDecryptionModule
    {
        CONST_VTBL struct IMFContentDecryptionModuleVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMFContentDecryptionModule_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMFContentDecryptionModule_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMFContentDecryptionModule_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMFContentDecryptionModule_SetContentEnabler(This,contentEnabler,result)	\
    ( (This)->lpVtbl -> SetContentEnabler(This,contentEnabler,result) ) 

#define IMFContentDecryptionModule_GetSuspendNotify(This,notify)	\
    ( (This)->lpVtbl -> GetSuspendNotify(This,notify) ) 

#define IMFContentDecryptionModule_SetPMPHostApp(This,pmpHostApp)	\
    ( (This)->lpVtbl -> SetPMPHostApp(This,pmpHostApp) ) 

#define IMFContentDecryptionModule_CreateSession(This,sessionType,callbacks,session)	\
    ( (This)->lpVtbl -> CreateSession(This,sessionType,callbacks,session) ) 

#define IMFContentDecryptionModule_SetServerCertificate(This,certificate,certificateSize)	\
    ( (This)->lpVtbl -> SetServerCertificate(This,certificate,certificateSize) ) 

#define IMFContentDecryptionModule_CreateTrustedInput(This,contentInitData,contentInitDataSize,trustedInput)	\
    ( (This)->lpVtbl -> CreateTrustedInput(This,contentInitData,contentInitDataSize,trustedInput) ) 

#define IMFContentDecryptionModule_GetProtectionSystemIds(This,systemIds,count)	\
    ( (This)->lpVtbl -> GetProtectionSystemIds(This,systemIds,count) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMFContentDecryptionModule_INTERFACE_DEFINED__ */


#ifndef __IMFContentDecryptionModuleAccess_INTERFACE_DEFINED__
#define __IMFContentDecryptionModuleAccess_INTERFACE_DEFINED__

/* interface IMFContentDecryptionModuleAccess */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IMFContentDecryptionModuleAccess;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("a853d1f4-e2a0-4303-9edc-f1a68ee43136")
    IMFContentDecryptionModuleAccess : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CreateContentDecryptionModule( 
            /* [annotation][in] */ 
            _In_  IPropertyStore *contentDecryptionModuleProperties,
            /* [annotation][out] */ 
            _Out_  IMFContentDecryptionModule **contentDecryptionModule) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetConfiguration( 
            /* [annotation][out] */ 
            _Out_  IPropertyStore **configuration) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetKeySystem( 
            /* [annotation][out] */ 
            _Out_  LPWSTR *keySystem) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IMFContentDecryptionModuleAccessVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IMFContentDecryptionModuleAccess * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IMFContentDecryptionModuleAccess * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IMFContentDecryptionModuleAccess * This);
        
        DECLSPEC_XFGVIRT(IMFContentDecryptionModuleAccess, CreateContentDecryptionModule)
        HRESULT ( STDMETHODCALLTYPE *CreateContentDecryptionModule )( 
            __RPC__in IMFContentDecryptionModuleAccess * This,
            /* [annotation][in] */ 
            _In_  IPropertyStore *contentDecryptionModuleProperties,
            /* [annotation][out] */ 
            _Out_  IMFContentDecryptionModule **contentDecryptionModule);
        
        DECLSPEC_XFGVIRT(IMFContentDecryptionModuleAccess, GetConfiguration)
        HRESULT ( STDMETHODCALLTYPE *GetConfiguration )( 
            __RPC__in IMFContentDecryptionModuleAccess * This,
            /* [annotation][out] */ 
            _Out_  IPropertyStore **configuration);
        
        DECLSPEC_XFGVIRT(IMFContentDecryptionModuleAccess, GetKeySystem)
        HRESULT ( STDMETHODCALLTYPE *GetKeySystem )( 
            __RPC__in IMFContentDecryptionModuleAccess * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *keySystem);
        
        END_INTERFACE
    } IMFContentDecryptionModuleAccessVtbl;

    interface IMFContentDecryptionModuleAccess
    {
        CONST_VTBL struct IMFContentDecryptionModuleAccessVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMFContentDecryptionModuleAccess_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMFContentDecryptionModuleAccess_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMFContentDecryptionModuleAccess_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMFContentDecryptionModuleAccess_CreateContentDecryptionModule(This,contentDecryptionModuleProperties,contentDecryptionModule)	\
    ( (This)->lpVtbl -> CreateContentDecryptionModule(This,contentDecryptionModuleProperties,contentDecryptionModule) ) 

#define IMFContentDecryptionModuleAccess_GetConfiguration(This,configuration)	\
    ( (This)->lpVtbl -> GetConfiguration(This,configuration) ) 

#define IMFContentDecryptionModuleAccess_GetKeySystem(This,keySystem)	\
    ( (This)->lpVtbl -> GetKeySystem(This,keySystem) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMFContentDecryptionModuleAccess_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_mfcontentdecryptionmodule_0000_0004 */
/* [local] */ 

EXTERN_C const DECLSPEC_SELECTANY PROPERTYKEY MF_CONTENTDECRYPTIONMODULE_INPRIVATESTOREPATH = { { 0x730cb3ac, 0x51dc, 0x49da, { 0xa5, 0x78, 0xb9, 0x53, 0x86, 0xb6, 0x2a, 0xfe } }, 0x01 }; 
EXTERN_C const DECLSPEC_SELECTANY PROPERTYKEY MF_CONTENTDECRYPTIONMODULE_STOREPATH =          { { 0x77d993b9, 0xba61, 0x4bb7, { 0x92, 0xc6, 0x18, 0xc8, 0x6a, 0x18, 0x9c, 0x06 } }, 0x02 }; 
EXTERN_C const DECLSPEC_SELECTANY PROPERTYKEY MF_CONTENTDECRYPTIONMODULE_PMPSTORECONTEXT =    { { 0x6d2a2835, 0xc3a9, 0x4681, { 0x97, 0xf2, 0x0a, 0xf5, 0x6b, 0xe9, 0x34, 0x46 } }, 0x03 }; 


extern RPC_IF_HANDLE __MIDL_itf_mfcontentdecryptionmodule_0000_0004_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_mfcontentdecryptionmodule_0000_0004_v0_0_s_ifspec;

#ifndef __IMFContentDecryptionModuleFactory_INTERFACE_DEFINED__
#define __IMFContentDecryptionModuleFactory_INTERFACE_DEFINED__

/* interface IMFContentDecryptionModuleFactory */
/* [local][uuid][object] */ 


EXTERN_C const IID IID_IMFContentDecryptionModuleFactory;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7d5abf16-4cbb-4e08-b977-9ba59049943e")
    IMFContentDecryptionModuleFactory : public IUnknown
    {
    public:
        virtual BOOL STDMETHODCALLTYPE IsTypeSupported( 
            /* [annotation][in] */ 
            _In_  LPCWSTR keySystem,
            /* [optional][in] */ LPCWSTR contentType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateContentDecryptionModuleAccess( 
            /* [annotation][in] */ 
            _In_  LPCWSTR keySystem,
            /* [annotation][size_is][size_is][in] */ 
            _In_reads_(numConfigurations)  IPropertyStore **configurations,
            /* [annotation][in] */ 
            _In_  DWORD numConfigurations,
            /* [annotation][out] */ 
            _Out_  IMFContentDecryptionModuleAccess **contentDecryptionModuleAccess) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IMFContentDecryptionModuleFactoryVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMFContentDecryptionModuleFactory * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMFContentDecryptionModuleFactory * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMFContentDecryptionModuleFactory * This);
        
        DECLSPEC_XFGVIRT(IMFContentDecryptionModuleFactory, IsTypeSupported)
        BOOL ( STDMETHODCALLTYPE *IsTypeSupported )( 
            IMFContentDecryptionModuleFactory * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR keySystem,
            /* [optional][in] */ LPCWSTR contentType);
        
        DECLSPEC_XFGVIRT(IMFContentDecryptionModuleFactory, CreateContentDecryptionModuleAccess)
        HRESULT ( STDMETHODCALLTYPE *CreateContentDecryptionModuleAccess )( 
            IMFContentDecryptionModuleFactory * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR keySystem,
            /* [annotation][size_is][size_is][in] */ 
            _In_reads_(numConfigurations)  IPropertyStore **configurations,
            /* [annotation][in] */ 
            _In_  DWORD numConfigurations,
            /* [annotation][out] */ 
            _Out_  IMFContentDecryptionModuleAccess **contentDecryptionModuleAccess);
        
        END_INTERFACE
    } IMFContentDecryptionModuleFactoryVtbl;

    interface IMFContentDecryptionModuleFactory
    {
        CONST_VTBL struct IMFContentDecryptionModuleFactoryVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMFContentDecryptionModuleFactory_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMFContentDecryptionModuleFactory_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMFContentDecryptionModuleFactory_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMFContentDecryptionModuleFactory_IsTypeSupported(This,keySystem,contentType)	\
    ( (This)->lpVtbl -> IsTypeSupported(This,keySystem,contentType) ) 

#define IMFContentDecryptionModuleFactory_CreateContentDecryptionModuleAccess(This,keySystem,configurations,numConfigurations,contentDecryptionModuleAccess)	\
    ( (This)->lpVtbl -> CreateContentDecryptionModuleAccess(This,keySystem,configurations,numConfigurations,contentDecryptionModuleAccess) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMFContentDecryptionModuleFactory_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_mfcontentdecryptionmodule_0000_0005 */
/* [local] */ 

EXTERN_GUID( MF_CONTENTDECRYPTIONMODULE_SERVICE, 0x15320c45, 0xff80, 0x484a, 0x9d, 0xcb, 0xd, 0xf8, 0x94, 0xe6, 0x9a, 0x1);
STDAPI MFCreateEncryptedMediaExtensionsStoreActivate(
    _In_ IMFPMPHostApp *pmpHost,
    _In_ IStream *objectStream,
    _In_ LPCWSTR classId,
    _Outptr_ IMFActivate** activate
    );
#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP) */
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_mfcontentdecryptionmodule_0000_0005_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_mfcontentdecryptionmodule_0000_0005_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


