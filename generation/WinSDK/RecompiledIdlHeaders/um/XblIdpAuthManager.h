

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0626 */
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

#ifndef __xblidpauthmanager_h__
#define __xblidpauthmanager_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef DECLSPEC_XFGVIRT
#if _CONTROL_FLOW_GUARD_XFG
#define DECLSPEC_XFGVIRT(base, func) __declspec(xfg_virtual(base, func))
#else
#define DECLSPEC_XFGVIRT(base, func)
#endif
#endif

/* Forward Declarations */ 

#ifndef __IXblIdpAuthManager_FWD_DEFINED__
#define __IXblIdpAuthManager_FWD_DEFINED__
typedef interface IXblIdpAuthManager IXblIdpAuthManager;

#endif 	/* __IXblIdpAuthManager_FWD_DEFINED__ */


#ifndef __IXblIdpAuthTokenResult_FWD_DEFINED__
#define __IXblIdpAuthTokenResult_FWD_DEFINED__
typedef interface IXblIdpAuthTokenResult IXblIdpAuthTokenResult;

#endif 	/* __IXblIdpAuthTokenResult_FWD_DEFINED__ */


#ifndef __IXblIdpAuthTokenResult2_FWD_DEFINED__
#define __IXblIdpAuthTokenResult2_FWD_DEFINED__
typedef interface IXblIdpAuthTokenResult2 IXblIdpAuthTokenResult2;

#endif 	/* __IXblIdpAuthTokenResult2_FWD_DEFINED__ */


#ifndef __XblIdpAuthManager_FWD_DEFINED__
#define __XblIdpAuthManager_FWD_DEFINED__

#ifdef __cplusplus
typedef class XblIdpAuthManager XblIdpAuthManager;
#else
typedef struct XblIdpAuthManager XblIdpAuthManager;
#endif /* __cplusplus */

#endif 	/* __XblIdpAuthManager_FWD_DEFINED__ */


#ifndef __XblIdpAuthTokenResult_FWD_DEFINED__
#define __XblIdpAuthTokenResult_FWD_DEFINED__

#ifdef __cplusplus
typedef class XblIdpAuthTokenResult XblIdpAuthTokenResult;
#else
typedef struct XblIdpAuthTokenResult XblIdpAuthTokenResult;
#endif /* __cplusplus */

#endif 	/* __XblIdpAuthTokenResult_FWD_DEFINED__ */


/* header files for imported files */
#include "objidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_xblidpauthmanager_0000_0000 */
/* [local] */ 

#include <winapifamily.h>
#pragma region Application Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP)

typedef 
enum _XBL_IDP_AUTH_TOKEN_STATUS
    {
        XBL_IDP_AUTH_TOKEN_STATUS_SUCCESS	= 0,
        XBL_IDP_AUTH_TOKEN_STATUS_OFFLINE_SUCCESS	= ( XBL_IDP_AUTH_TOKEN_STATUS_SUCCESS + 1 ) ,
        XBL_IDP_AUTH_TOKEN_STATUS_NO_ACCOUNT_SET	= ( XBL_IDP_AUTH_TOKEN_STATUS_OFFLINE_SUCCESS + 1 ) ,
        XBL_IDP_AUTH_TOKEN_STATUS_LOAD_MSA_ACCOUNT_FAILED	= ( XBL_IDP_AUTH_TOKEN_STATUS_NO_ACCOUNT_SET + 1 ) ,
        XBL_IDP_AUTH_TOKEN_STATUS_XBOX_VETO	= ( XBL_IDP_AUTH_TOKEN_STATUS_LOAD_MSA_ACCOUNT_FAILED + 1 ) ,
        XBL_IDP_AUTH_TOKEN_STATUS_MSA_INTERRUPT	= ( XBL_IDP_AUTH_TOKEN_STATUS_XBOX_VETO + 1 ) ,
        XBL_IDP_AUTH_TOKEN_STATUS_OFFLINE_NO_CONSENT	= ( XBL_IDP_AUTH_TOKEN_STATUS_MSA_INTERRUPT + 1 ) ,
        XBL_IDP_AUTH_TOKEN_STATUS_VIEW_NOT_SET	= ( XBL_IDP_AUTH_TOKEN_STATUS_OFFLINE_NO_CONSENT + 1 ) ,
        XBL_IDP_AUTH_TOKEN_STATUS_UNKNOWN	= 0xffffffff
    } 	XBL_IDP_AUTH_TOKEN_STATUS;



extern RPC_IF_HANDLE __MIDL_itf_xblidpauthmanager_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_xblidpauthmanager_0000_0000_v0_0_s_ifspec;

#ifndef __IXblIdpAuthManager_INTERFACE_DEFINED__
#define __IXblIdpAuthManager_INTERFACE_DEFINED__

/* interface IXblIdpAuthManager */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IXblIdpAuthManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("eb5ddb08-8bbf-449b-ac21-b02ddeb3b136")
    IXblIdpAuthManager : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetGamerAccount( 
            /* [annotation][unique][string][in] */ 
            _In_  LPCWSTR msaAccountId,
            /* [annotation][unique][string][in] */ 
            _In_  LPCWSTR xuid) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetGamerAccount( 
            /* [annotation][string][out] */ 
            _Out_  LPWSTR *msaAccountId,
            /* [annotation][string][out] */ 
            _Out_  LPWSTR *xuid) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAppViewInitialized( 
            /* [annotation][string][in] */ 
            _In_  LPCWSTR appSid,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR msaAccountId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEnvironment( 
            /* [annotation][string][out] */ 
            _Out_  LPWSTR *environment) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSandbox( 
            /* [annotation][string][out] */ 
            _Out_  LPWSTR *sandbox) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTokenAndSignatureWithTokenResult( 
            /* [annotation][unique][string][in] */ 
            _In_  LPCWSTR msaAccountId,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR appSid,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR msaTarget,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR msaPolicy,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR httpMethod,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR uri,
            /* [annotation][unique][string][in] */ 
            _In_  LPCWSTR headers,
            /* [annotation][size_is][unique][in] */ 
            _In_reads_(bodySize)  BYTE *body,
            /* [annotation][in] */ 
            _In_  DWORD bodySize,
            /* [annotation][in] */ 
            _In_  BOOL forceRefresh,
            /* [annotation][out] */ 
            _Out_  IXblIdpAuthTokenResult **result) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IXblIdpAuthManagerVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IXblIdpAuthManager * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IXblIdpAuthManager * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IXblIdpAuthManager * This);
        
        DECLSPEC_XFGVIRT(IXblIdpAuthManager, SetGamerAccount)
        HRESULT ( STDMETHODCALLTYPE *SetGamerAccount )( 
            __RPC__in IXblIdpAuthManager * This,
            /* [annotation][unique][string][in] */ 
            _In_  LPCWSTR msaAccountId,
            /* [annotation][unique][string][in] */ 
            _In_  LPCWSTR xuid);
        
        DECLSPEC_XFGVIRT(IXblIdpAuthManager, GetGamerAccount)
        HRESULT ( STDMETHODCALLTYPE *GetGamerAccount )( 
            __RPC__in IXblIdpAuthManager * This,
            /* [annotation][string][out] */ 
            _Out_  LPWSTR *msaAccountId,
            /* [annotation][string][out] */ 
            _Out_  LPWSTR *xuid);
        
        DECLSPEC_XFGVIRT(IXblIdpAuthManager, SetAppViewInitialized)
        HRESULT ( STDMETHODCALLTYPE *SetAppViewInitialized )( 
            __RPC__in IXblIdpAuthManager * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR appSid,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR msaAccountId);
        
        DECLSPEC_XFGVIRT(IXblIdpAuthManager, GetEnvironment)
        HRESULT ( STDMETHODCALLTYPE *GetEnvironment )( 
            __RPC__in IXblIdpAuthManager * This,
            /* [annotation][string][out] */ 
            _Out_  LPWSTR *environment);
        
        DECLSPEC_XFGVIRT(IXblIdpAuthManager, GetSandbox)
        HRESULT ( STDMETHODCALLTYPE *GetSandbox )( 
            __RPC__in IXblIdpAuthManager * This,
            /* [annotation][string][out] */ 
            _Out_  LPWSTR *sandbox);
        
        DECLSPEC_XFGVIRT(IXblIdpAuthManager, GetTokenAndSignatureWithTokenResult)
        HRESULT ( STDMETHODCALLTYPE *GetTokenAndSignatureWithTokenResult )( 
            __RPC__in IXblIdpAuthManager * This,
            /* [annotation][unique][string][in] */ 
            _In_  LPCWSTR msaAccountId,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR appSid,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR msaTarget,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR msaPolicy,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR httpMethod,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR uri,
            /* [annotation][unique][string][in] */ 
            _In_  LPCWSTR headers,
            /* [annotation][size_is][unique][in] */ 
            _In_reads_(bodySize)  BYTE *body,
            /* [annotation][in] */ 
            _In_  DWORD bodySize,
            /* [annotation][in] */ 
            _In_  BOOL forceRefresh,
            /* [annotation][out] */ 
            _Out_  IXblIdpAuthTokenResult **result);
        
        END_INTERFACE
    } IXblIdpAuthManagerVtbl;

    interface IXblIdpAuthManager
    {
        CONST_VTBL struct IXblIdpAuthManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IXblIdpAuthManager_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IXblIdpAuthManager_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IXblIdpAuthManager_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IXblIdpAuthManager_SetGamerAccount(This,msaAccountId,xuid)	\
    ( (This)->lpVtbl -> SetGamerAccount(This,msaAccountId,xuid) ) 

#define IXblIdpAuthManager_GetGamerAccount(This,msaAccountId,xuid)	\
    ( (This)->lpVtbl -> GetGamerAccount(This,msaAccountId,xuid) ) 

#define IXblIdpAuthManager_SetAppViewInitialized(This,appSid,msaAccountId)	\
    ( (This)->lpVtbl -> SetAppViewInitialized(This,appSid,msaAccountId) ) 

#define IXblIdpAuthManager_GetEnvironment(This,environment)	\
    ( (This)->lpVtbl -> GetEnvironment(This,environment) ) 

#define IXblIdpAuthManager_GetSandbox(This,sandbox)	\
    ( (This)->lpVtbl -> GetSandbox(This,sandbox) ) 

#define IXblIdpAuthManager_GetTokenAndSignatureWithTokenResult(This,msaAccountId,appSid,msaTarget,msaPolicy,httpMethod,uri,headers,body,bodySize,forceRefresh,result)	\
    ( (This)->lpVtbl -> GetTokenAndSignatureWithTokenResult(This,msaAccountId,appSid,msaTarget,msaPolicy,httpMethod,uri,headers,body,bodySize,forceRefresh,result) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IXblIdpAuthManager_INTERFACE_DEFINED__ */


#ifndef __IXblIdpAuthTokenResult_INTERFACE_DEFINED__
#define __IXblIdpAuthTokenResult_INTERFACE_DEFINED__

/* interface IXblIdpAuthTokenResult */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IXblIdpAuthTokenResult;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("46ce0225-f267-4d68-b299-b2762552dec1")
    IXblIdpAuthTokenResult : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetStatus( 
            /* [annotation][out] */ 
            _Out_  XBL_IDP_AUTH_TOKEN_STATUS *status) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetErrorCode( 
            /* [annotation][out] */ 
            _Out_  HRESULT *errorCode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetToken( 
            /* [annotation][string][retval][out] */ 
            _Out_retval_  LPWSTR *token) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSignature( 
            /* [annotation][string][retval][out] */ 
            _Out_retval_  LPWSTR *signature) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSandbox( 
            /* [annotation][string][retval][out] */ 
            _Out_retval_  LPWSTR *sandbox) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEnvironment( 
            /* [annotation][string][retval][out] */ 
            _Out_retval_  LPWSTR *environment) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMsaAccountId( 
            /* [annotation][string][retval][out] */ 
            _Out_retval_  LPWSTR *msaAccountId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetXuid( 
            /* [annotation][string][retval][out] */ 
            _Out_retval_  LPWSTR *xuid) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetGamertag( 
            /* [annotation][string][retval][out] */ 
            _Out_retval_  LPWSTR *gamertag) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAgeGroup( 
            /* [annotation][string][retval][out] */ 
            _Out_retval_  LPWSTR *ageGroup) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPrivileges( 
            /* [annotation][string][retval][out] */ 
            _Out_retval_  LPWSTR *privileges) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMsaTarget( 
            /* [annotation][string][retval][out] */ 
            _Out_retval_  LPWSTR *msaTarget) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMsaPolicy( 
            /* [annotation][string][retval][out] */ 
            _Out_retval_  LPWSTR *msaPolicy) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMsaAppId( 
            /* [annotation][string][retval][out] */ 
            _Out_retval_  LPWSTR *msaAppId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRedirect( 
            /* [annotation][string][retval][out] */ 
            _Out_retval_  LPWSTR *redirect) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMessage( 
            /* [annotation][string][retval][out] */ 
            _Out_retval_  LPWSTR *message) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetHelpId( 
            /* [annotation][string][retval][out] */ 
            _Out_retval_  LPWSTR *helpId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEnforcementBans( 
            /* [annotation][string][retval][out] */ 
            _Out_retval_  LPWSTR *enforcementBans) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRestrictions( 
            /* [annotation][string][retval][out] */ 
            _Out_retval_  LPWSTR *restrictions) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTitleRestrictions( 
            /* [annotation][string][retval][out] */ 
            _Out_retval_  LPWSTR *titleRestrictions) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IXblIdpAuthTokenResultVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IXblIdpAuthTokenResult * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IXblIdpAuthTokenResult * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IXblIdpAuthTokenResult * This);
        
        DECLSPEC_XFGVIRT(IXblIdpAuthTokenResult, GetStatus)
        HRESULT ( STDMETHODCALLTYPE *GetStatus )( 
            __RPC__in IXblIdpAuthTokenResult * This,
            /* [annotation][out] */ 
            _Out_  XBL_IDP_AUTH_TOKEN_STATUS *status);
        
        DECLSPEC_XFGVIRT(IXblIdpAuthTokenResult, GetErrorCode)
        HRESULT ( STDMETHODCALLTYPE *GetErrorCode )( 
            __RPC__in IXblIdpAuthTokenResult * This,
            /* [annotation][out] */ 
            _Out_  HRESULT *errorCode);
        
        DECLSPEC_XFGVIRT(IXblIdpAuthTokenResult, GetToken)
        HRESULT ( STDMETHODCALLTYPE *GetToken )( 
            __RPC__in IXblIdpAuthTokenResult * This,
            /* [annotation][string][retval][out] */ 
            _Out_retval_  LPWSTR *token);
        
        DECLSPEC_XFGVIRT(IXblIdpAuthTokenResult, GetSignature)
        HRESULT ( STDMETHODCALLTYPE *GetSignature )( 
            __RPC__in IXblIdpAuthTokenResult * This,
            /* [annotation][string][retval][out] */ 
            _Out_retval_  LPWSTR *signature);
        
        DECLSPEC_XFGVIRT(IXblIdpAuthTokenResult, GetSandbox)
        HRESULT ( STDMETHODCALLTYPE *GetSandbox )( 
            __RPC__in IXblIdpAuthTokenResult * This,
            /* [annotation][string][retval][out] */ 
            _Out_retval_  LPWSTR *sandbox);
        
        DECLSPEC_XFGVIRT(IXblIdpAuthTokenResult, GetEnvironment)
        HRESULT ( STDMETHODCALLTYPE *GetEnvironment )( 
            __RPC__in IXblIdpAuthTokenResult * This,
            /* [annotation][string][retval][out] */ 
            _Out_retval_  LPWSTR *environment);
        
        DECLSPEC_XFGVIRT(IXblIdpAuthTokenResult, GetMsaAccountId)
        HRESULT ( STDMETHODCALLTYPE *GetMsaAccountId )( 
            __RPC__in IXblIdpAuthTokenResult * This,
            /* [annotation][string][retval][out] */ 
            _Out_retval_  LPWSTR *msaAccountId);
        
        DECLSPEC_XFGVIRT(IXblIdpAuthTokenResult, GetXuid)
        HRESULT ( STDMETHODCALLTYPE *GetXuid )( 
            __RPC__in IXblIdpAuthTokenResult * This,
            /* [annotation][string][retval][out] */ 
            _Out_retval_  LPWSTR *xuid);
        
        DECLSPEC_XFGVIRT(IXblIdpAuthTokenResult, GetGamertag)
        HRESULT ( STDMETHODCALLTYPE *GetGamertag )( 
            __RPC__in IXblIdpAuthTokenResult * This,
            /* [annotation][string][retval][out] */ 
            _Out_retval_  LPWSTR *gamertag);
        
        DECLSPEC_XFGVIRT(IXblIdpAuthTokenResult, GetAgeGroup)
        HRESULT ( STDMETHODCALLTYPE *GetAgeGroup )( 
            __RPC__in IXblIdpAuthTokenResult * This,
            /* [annotation][string][retval][out] */ 
            _Out_retval_  LPWSTR *ageGroup);
        
        DECLSPEC_XFGVIRT(IXblIdpAuthTokenResult, GetPrivileges)
        HRESULT ( STDMETHODCALLTYPE *GetPrivileges )( 
            __RPC__in IXblIdpAuthTokenResult * This,
            /* [annotation][string][retval][out] */ 
            _Out_retval_  LPWSTR *privileges);
        
        DECLSPEC_XFGVIRT(IXblIdpAuthTokenResult, GetMsaTarget)
        HRESULT ( STDMETHODCALLTYPE *GetMsaTarget )( 
            __RPC__in IXblIdpAuthTokenResult * This,
            /* [annotation][string][retval][out] */ 
            _Out_retval_  LPWSTR *msaTarget);
        
        DECLSPEC_XFGVIRT(IXblIdpAuthTokenResult, GetMsaPolicy)
        HRESULT ( STDMETHODCALLTYPE *GetMsaPolicy )( 
            __RPC__in IXblIdpAuthTokenResult * This,
            /* [annotation][string][retval][out] */ 
            _Out_retval_  LPWSTR *msaPolicy);
        
        DECLSPEC_XFGVIRT(IXblIdpAuthTokenResult, GetMsaAppId)
        HRESULT ( STDMETHODCALLTYPE *GetMsaAppId )( 
            __RPC__in IXblIdpAuthTokenResult * This,
            /* [annotation][string][retval][out] */ 
            _Out_retval_  LPWSTR *msaAppId);
        
        DECLSPEC_XFGVIRT(IXblIdpAuthTokenResult, GetRedirect)
        HRESULT ( STDMETHODCALLTYPE *GetRedirect )( 
            __RPC__in IXblIdpAuthTokenResult * This,
            /* [annotation][string][retval][out] */ 
            _Out_retval_  LPWSTR *redirect);
        
        DECLSPEC_XFGVIRT(IXblIdpAuthTokenResult, GetMessage)
        HRESULT ( STDMETHODCALLTYPE *GetMessage )( 
            __RPC__in IXblIdpAuthTokenResult * This,
            /* [annotation][string][retval][out] */ 
            _Out_retval_  LPWSTR *message);
        
        DECLSPEC_XFGVIRT(IXblIdpAuthTokenResult, GetHelpId)
        HRESULT ( STDMETHODCALLTYPE *GetHelpId )( 
            __RPC__in IXblIdpAuthTokenResult * This,
            /* [annotation][string][retval][out] */ 
            _Out_retval_  LPWSTR *helpId);
        
        DECLSPEC_XFGVIRT(IXblIdpAuthTokenResult, GetEnforcementBans)
        HRESULT ( STDMETHODCALLTYPE *GetEnforcementBans )( 
            __RPC__in IXblIdpAuthTokenResult * This,
            /* [annotation][string][retval][out] */ 
            _Out_retval_  LPWSTR *enforcementBans);
        
        DECLSPEC_XFGVIRT(IXblIdpAuthTokenResult, GetRestrictions)
        HRESULT ( STDMETHODCALLTYPE *GetRestrictions )( 
            __RPC__in IXblIdpAuthTokenResult * This,
            /* [annotation][string][retval][out] */ 
            _Out_retval_  LPWSTR *restrictions);
        
        DECLSPEC_XFGVIRT(IXblIdpAuthTokenResult, GetTitleRestrictions)
        HRESULT ( STDMETHODCALLTYPE *GetTitleRestrictions )( 
            __RPC__in IXblIdpAuthTokenResult * This,
            /* [annotation][string][retval][out] */ 
            _Out_retval_  LPWSTR *titleRestrictions);
        
        END_INTERFACE
    } IXblIdpAuthTokenResultVtbl;

    interface IXblIdpAuthTokenResult
    {
        CONST_VTBL struct IXblIdpAuthTokenResultVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IXblIdpAuthTokenResult_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IXblIdpAuthTokenResult_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IXblIdpAuthTokenResult_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IXblIdpAuthTokenResult_GetStatus(This,status)	\
    ( (This)->lpVtbl -> GetStatus(This,status) ) 

#define IXblIdpAuthTokenResult_GetErrorCode(This,errorCode)	\
    ( (This)->lpVtbl -> GetErrorCode(This,errorCode) ) 

#define IXblIdpAuthTokenResult_GetToken(This,token)	\
    ( (This)->lpVtbl -> GetToken(This,token) ) 

#define IXblIdpAuthTokenResult_GetSignature(This,signature)	\
    ( (This)->lpVtbl -> GetSignature(This,signature) ) 

#define IXblIdpAuthTokenResult_GetSandbox(This,sandbox)	\
    ( (This)->lpVtbl -> GetSandbox(This,sandbox) ) 

#define IXblIdpAuthTokenResult_GetEnvironment(This,environment)	\
    ( (This)->lpVtbl -> GetEnvironment(This,environment) ) 

#define IXblIdpAuthTokenResult_GetMsaAccountId(This,msaAccountId)	\
    ( (This)->lpVtbl -> GetMsaAccountId(This,msaAccountId) ) 

#define IXblIdpAuthTokenResult_GetXuid(This,xuid)	\
    ( (This)->lpVtbl -> GetXuid(This,xuid) ) 

#define IXblIdpAuthTokenResult_GetGamertag(This,gamertag)	\
    ( (This)->lpVtbl -> GetGamertag(This,gamertag) ) 

#define IXblIdpAuthTokenResult_GetAgeGroup(This,ageGroup)	\
    ( (This)->lpVtbl -> GetAgeGroup(This,ageGroup) ) 

#define IXblIdpAuthTokenResult_GetPrivileges(This,privileges)	\
    ( (This)->lpVtbl -> GetPrivileges(This,privileges) ) 

#define IXblIdpAuthTokenResult_GetMsaTarget(This,msaTarget)	\
    ( (This)->lpVtbl -> GetMsaTarget(This,msaTarget) ) 

#define IXblIdpAuthTokenResult_GetMsaPolicy(This,msaPolicy)	\
    ( (This)->lpVtbl -> GetMsaPolicy(This,msaPolicy) ) 

#define IXblIdpAuthTokenResult_GetMsaAppId(This,msaAppId)	\
    ( (This)->lpVtbl -> GetMsaAppId(This,msaAppId) ) 

#define IXblIdpAuthTokenResult_GetRedirect(This,redirect)	\
    ( (This)->lpVtbl -> GetRedirect(This,redirect) ) 

#define IXblIdpAuthTokenResult_GetMessage(This,message)	\
    ( (This)->lpVtbl -> GetMessage(This,message) ) 

#define IXblIdpAuthTokenResult_GetHelpId(This,helpId)	\
    ( (This)->lpVtbl -> GetHelpId(This,helpId) ) 

#define IXblIdpAuthTokenResult_GetEnforcementBans(This,enforcementBans)	\
    ( (This)->lpVtbl -> GetEnforcementBans(This,enforcementBans) ) 

#define IXblIdpAuthTokenResult_GetRestrictions(This,restrictions)	\
    ( (This)->lpVtbl -> GetRestrictions(This,restrictions) ) 

#define IXblIdpAuthTokenResult_GetTitleRestrictions(This,titleRestrictions)	\
    ( (This)->lpVtbl -> GetTitleRestrictions(This,titleRestrictions) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IXblIdpAuthTokenResult_INTERFACE_DEFINED__ */


#ifndef __IXblIdpAuthTokenResult2_INTERFACE_DEFINED__
#define __IXblIdpAuthTokenResult2_INTERFACE_DEFINED__

/* interface IXblIdpAuthTokenResult2 */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IXblIdpAuthTokenResult2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("75d760b0-60b9-412d-994f-26b2cd5f7812")
    IXblIdpAuthTokenResult2 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetModernGamertag( 
            /* [annotation][string][retval][out] */ 
            _Out_retval_  LPWSTR *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetModernGamertagSuffix( 
            /* [annotation][string][retval][out] */ 
            _Out_retval_  LPWSTR *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetUniqueModernGamertag( 
            /* [annotation][string][retval][out] */ 
            _Out_retval_  LPWSTR *value) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IXblIdpAuthTokenResult2Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IXblIdpAuthTokenResult2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IXblIdpAuthTokenResult2 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IXblIdpAuthTokenResult2 * This);
        
        DECLSPEC_XFGVIRT(IXblIdpAuthTokenResult2, GetModernGamertag)
        HRESULT ( STDMETHODCALLTYPE *GetModernGamertag )( 
            __RPC__in IXblIdpAuthTokenResult2 * This,
            /* [annotation][string][retval][out] */ 
            _Out_retval_  LPWSTR *value);
        
        DECLSPEC_XFGVIRT(IXblIdpAuthTokenResult2, GetModernGamertagSuffix)
        HRESULT ( STDMETHODCALLTYPE *GetModernGamertagSuffix )( 
            __RPC__in IXblIdpAuthTokenResult2 * This,
            /* [annotation][string][retval][out] */ 
            _Out_retval_  LPWSTR *value);
        
        DECLSPEC_XFGVIRT(IXblIdpAuthTokenResult2, GetUniqueModernGamertag)
        HRESULT ( STDMETHODCALLTYPE *GetUniqueModernGamertag )( 
            __RPC__in IXblIdpAuthTokenResult2 * This,
            /* [annotation][string][retval][out] */ 
            _Out_retval_  LPWSTR *value);
        
        END_INTERFACE
    } IXblIdpAuthTokenResult2Vtbl;

    interface IXblIdpAuthTokenResult2
    {
        CONST_VTBL struct IXblIdpAuthTokenResult2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IXblIdpAuthTokenResult2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IXblIdpAuthTokenResult2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IXblIdpAuthTokenResult2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IXblIdpAuthTokenResult2_GetModernGamertag(This,value)	\
    ( (This)->lpVtbl -> GetModernGamertag(This,value) ) 

#define IXblIdpAuthTokenResult2_GetModernGamertagSuffix(This,value)	\
    ( (This)->lpVtbl -> GetModernGamertagSuffix(This,value) ) 

#define IXblIdpAuthTokenResult2_GetUniqueModernGamertag(This,value)	\
    ( (This)->lpVtbl -> GetUniqueModernGamertag(This,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IXblIdpAuthTokenResult2_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_xblidpauthmanager_0000_0003 */
/* [local] */ 

#ifdef __cplusplus

class DECLSPEC_UUID("ce23534b-56d8-4978-86a2-7ee570640468")
XblIdpAuthManager;
#endif


extern RPC_IF_HANDLE __MIDL_itf_xblidpauthmanager_0000_0003_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_xblidpauthmanager_0000_0003_v0_0_s_ifspec;

/* interface __MIDL_itf_xblidpauthmanager_0000_0004 */
/* [local] */ 

#ifdef __cplusplus

class DECLSPEC_UUID("9f493441-744a-410c-ae2b-9a22f7c7731f")
XblIdpAuthTokenResult;
#endif


extern RPC_IF_HANDLE __MIDL_itf_xblidpauthmanager_0000_0004_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_xblidpauthmanager_0000_0004_v0_0_s_ifspec;

/* interface __MIDL_itf_xblidpauthmanager_0000_0005 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP) */
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_xblidpauthmanager_0000_0005_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_xblidpauthmanager_0000_0005_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


