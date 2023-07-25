

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


#ifndef __httprequest_h__
#define __httprequest_h__

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

#ifndef __IWinHttpRequest_FWD_DEFINED__
#define __IWinHttpRequest_FWD_DEFINED__
typedef interface IWinHttpRequest IWinHttpRequest;

#endif 	/* __IWinHttpRequest_FWD_DEFINED__ */


#ifndef __IWinHttpRequestEvents_FWD_DEFINED__
#define __IWinHttpRequestEvents_FWD_DEFINED__
typedef interface IWinHttpRequestEvents IWinHttpRequestEvents;

#endif 	/* __IWinHttpRequestEvents_FWD_DEFINED__ */


#ifndef __WinHttpRequest_FWD_DEFINED__
#define __WinHttpRequest_FWD_DEFINED__

#ifdef __cplusplus
typedef class WinHttpRequest WinHttpRequest;
#else
typedef struct WinHttpRequest WinHttpRequest;
#endif /* __cplusplus */

#endif 	/* __WinHttpRequest_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_httprequest_0000_0000 */
/* [local] */ 

//+-------------------------------------------------------------------------
//
//  Microsoft Windows HTTP Services (WinHTTP) version 5.1
//  Copyright (C) Microsoft Corporation. All rights reserved.
//
//--------------------------------------------------------------------------
#include <winapifamily.h>
#pragma region Desktop Family or OneCore Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)
#pragma warning(push)
#pragma warning(disable:4001) 
#pragma once
#pragma warning(push)
#pragma warning(disable:4001) 
#pragma once
#pragma warning(pop)
#pragma warning(pop)
#pragma region Desktop Family or OneCore Family
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_httprequest_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_httprequest_0000_0000_v0_0_s_ifspec;


#ifndef __WinHttp_LIBRARY_DEFINED__
#define __WinHttp_LIBRARY_DEFINED__

/* library WinHttp */
/* [version][lcid][helpstring][uuid] */ 

typedef /* [public] */ long HTTPREQUEST_PROXY_SETTING;

#define	HTTPREQUEST_PROXYSETTING_DEFAULT	( 0 )

#define	HTTPREQUEST_PROXYSETTING_PRECONFIG	( 0 )

#define	HTTPREQUEST_PROXYSETTING_DIRECT	( 0x1 )

#define	HTTPREQUEST_PROXYSETTING_PROXY	( 0x2 )

typedef /* [public] */ long HTTPREQUEST_SETCREDENTIALS_FLAGS;

#define	HTTPREQUEST_SETCREDENTIALS_FOR_SERVER	( 0 )

#define	HTTPREQUEST_SETCREDENTIALS_FOR_PROXY	( 0x1 )

typedef /* [helpstring][uuid] */  DECLSPEC_UUID("12782009-FE90-4877-9730-E5E183669B19") 
enum WinHttpRequestOption
    {
        WinHttpRequestOption_UserAgentString	= 0,
        WinHttpRequestOption_URL	= ( WinHttpRequestOption_UserAgentString + 1 ) ,
        WinHttpRequestOption_URLCodePage	= ( WinHttpRequestOption_URL + 1 ) ,
        WinHttpRequestOption_EscapePercentInURL	= ( WinHttpRequestOption_URLCodePage + 1 ) ,
        WinHttpRequestOption_SslErrorIgnoreFlags	= ( WinHttpRequestOption_EscapePercentInURL + 1 ) ,
        WinHttpRequestOption_SelectCertificate	= ( WinHttpRequestOption_SslErrorIgnoreFlags + 1 ) ,
        WinHttpRequestOption_EnableRedirects	= ( WinHttpRequestOption_SelectCertificate + 1 ) ,
        WinHttpRequestOption_UrlEscapeDisable	= ( WinHttpRequestOption_EnableRedirects + 1 ) ,
        WinHttpRequestOption_UrlEscapeDisableQuery	= ( WinHttpRequestOption_UrlEscapeDisable + 1 ) ,
        WinHttpRequestOption_SecureProtocols	= ( WinHttpRequestOption_UrlEscapeDisableQuery + 1 ) ,
        WinHttpRequestOption_EnableTracing	= ( WinHttpRequestOption_SecureProtocols + 1 ) ,
        WinHttpRequestOption_RevertImpersonationOverSsl	= ( WinHttpRequestOption_EnableTracing + 1 ) ,
        WinHttpRequestOption_EnableHttpsToHttpRedirects	= ( WinHttpRequestOption_RevertImpersonationOverSsl + 1 ) ,
        WinHttpRequestOption_EnablePassportAuthentication	= ( WinHttpRequestOption_EnableHttpsToHttpRedirects + 1 ) ,
        WinHttpRequestOption_MaxAutomaticRedirects	= ( WinHttpRequestOption_EnablePassportAuthentication + 1 ) ,
        WinHttpRequestOption_MaxResponseHeaderSize	= ( WinHttpRequestOption_MaxAutomaticRedirects + 1 ) ,
        WinHttpRequestOption_MaxResponseDrainSize	= ( WinHttpRequestOption_MaxResponseHeaderSize + 1 ) ,
        WinHttpRequestOption_EnableHttp1_1	= ( WinHttpRequestOption_MaxResponseDrainSize + 1 ) ,
        WinHttpRequestOption_EnableCertificateRevocationCheck	= ( WinHttpRequestOption_EnableHttp1_1 + 1 ) ,
        WinHttpRequestOption_RejectUserpwd	= ( WinHttpRequestOption_EnableCertificateRevocationCheck + 1 ) 
    } 	WinHttpRequestOption;

typedef /* [uuid] */  DECLSPEC_UUID("9d8a6df8-13de-4b1f-a330-67c719d62514") 
enum WinHttpRequestAutoLogonPolicy
    {
        AutoLogonPolicy_Always	= 0,
        AutoLogonPolicy_OnlyIfBypassProxy	= ( AutoLogonPolicy_Always + 1 ) ,
        AutoLogonPolicy_Never	= ( AutoLogonPolicy_OnlyIfBypassProxy + 1 ) 
    } 	WinHttpRequestAutoLogonPolicy;

typedef /* [uuid] */  DECLSPEC_UUID("152a1ca2-55a9-43a3-b187-0605bb886349") 
enum WinHttpRequestSslErrorFlags
    {
        SslErrorFlag_UnknownCA	= 0x100,
        SslErrorFlag_CertWrongUsage	= 0x200,
        SslErrorFlag_CertCNInvalid	= 0x1000,
        SslErrorFlag_CertDateInvalid	= 0x2000,
        SslErrorFlag_Ignore_All	= 0x3300
    } 	WinHttpRequestSslErrorFlags;

typedef /* [uuid] */  DECLSPEC_UUID("6b2c51c1-a8ea-46bd-b928-c9b76f9f14dd") 
enum WinHttpRequestSecureProtocols
    {
        SecureProtocol_SSL2	= 0x8,
        SecureProtocol_SSL3	= 0x20,
        SecureProtocol_TLS1	= 0x80,
        SecureProtocol_TLS1_1	= 0x200,
        SecureProtocol_TLS1_2	= 0x800,
        SecureProtocol_ALL	= 0xa8
    } 	WinHttpRequestSecureProtocols;


EXTERN_C const IID LIBID_WinHttp;

#ifndef __IWinHttpRequest_INTERFACE_DEFINED__
#define __IWinHttpRequest_INTERFACE_DEFINED__

/* interface IWinHttpRequest */
/* [unique][helpstring][nonextensible][oleautomation][dual][uuid][object] */ 


EXTERN_C const IID IID_IWinHttpRequest;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("016fe2ec-b2c8-45f8-b23b-39e53a75396b")
    IWinHttpRequest : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetProxy( 
            /* [annotation][in] */ 
            _In_  HTTPREQUEST_PROXY_SETTING ProxySetting,
            /* [optional][in] */ VARIANT ProxyServer,
            /* [optional][in] */ VARIANT BypassList) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetCredentials( 
            /* [annotation][in] */ 
            _In_  BSTR UserName,
            /* [annotation][in] */ 
            _In_  BSTR Password,
            /* [annotation][in] */ 
            _In_  HTTPREQUEST_SETCREDENTIALS_FLAGS Flags) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Open( 
            /* [annotation][in] */ 
            _In_  BSTR Method,
            /* [annotation][in] */ 
            _In_  BSTR Url,
            /* [optional][in] */ VARIANT Async) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetRequestHeader( 
            /* [annotation][in] */ 
            _In_  BSTR Header,
            /* [annotation][in] */ 
            _In_  BSTR Value) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetResponseHeader( 
            /* [annotation][in] */ 
            _In_  BSTR Header,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *Value) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetAllResponseHeaders( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *Headers) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Send( 
            /* [optional][in] */ VARIANT Body) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Status( 
            /* [annotation][retval][out] */ 
            _Out_retval_  long *Status) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StatusText( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *Status) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ResponseText( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *Body) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ResponseBody( 
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT *Body) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ResponseStream( 
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT *Body) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Option( 
            /* [annotation][in] */ 
            _In_  WinHttpRequestOption Option,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT *Value) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Option( 
            /* [annotation][in] */ 
            _In_  WinHttpRequestOption Option,
            /* [annotation][in] */ 
            _In_  VARIANT Value) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WaitForResponse( 
            /* [optional][in] */ VARIANT Timeout,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *Succeeded) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Abort( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetTimeouts( 
            /* [annotation][in] */ 
            _In_  long ResolveTimeout,
            /* [annotation][in] */ 
            _In_  long ConnectTimeout,
            /* [annotation][in] */ 
            _In_  long SendTimeout,
            /* [annotation][in] */ 
            _In_  long ReceiveTimeout) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetClientCertificate( 
            /* [annotation][in] */ 
            _In_  BSTR ClientCertificate) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetAutoLogonPolicy( 
            /* [annotation][in] */ 
            _In_  WinHttpRequestAutoLogonPolicy AutoLogonPolicy) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWinHttpRequestVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IWinHttpRequest * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IWinHttpRequest * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IWinHttpRequest * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IWinHttpRequest * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IWinHttpRequest * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IWinHttpRequest * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][size_is][in] */ 
            _In_reads_(cNames)  LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cNames)  DISPID *rgDispId);
        
        DECLSPEC_XFGVIRT(IDispatch, Invoke)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IWinHttpRequest * This,
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
        
        DECLSPEC_XFGVIRT(IWinHttpRequest, SetProxy)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetProxy )( 
            __RPC__in IWinHttpRequest * This,
            /* [annotation][in] */ 
            _In_  HTTPREQUEST_PROXY_SETTING ProxySetting,
            /* [optional][in] */ VARIANT ProxyServer,
            /* [optional][in] */ VARIANT BypassList);
        
        DECLSPEC_XFGVIRT(IWinHttpRequest, SetCredentials)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetCredentials )( 
            __RPC__in IWinHttpRequest * This,
            /* [annotation][in] */ 
            _In_  BSTR UserName,
            /* [annotation][in] */ 
            _In_  BSTR Password,
            /* [annotation][in] */ 
            _In_  HTTPREQUEST_SETCREDENTIALS_FLAGS Flags);
        
        DECLSPEC_XFGVIRT(IWinHttpRequest, Open)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Open )( 
            __RPC__in IWinHttpRequest * This,
            /* [annotation][in] */ 
            _In_  BSTR Method,
            /* [annotation][in] */ 
            _In_  BSTR Url,
            /* [optional][in] */ VARIANT Async);
        
        DECLSPEC_XFGVIRT(IWinHttpRequest, SetRequestHeader)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetRequestHeader )( 
            __RPC__in IWinHttpRequest * This,
            /* [annotation][in] */ 
            _In_  BSTR Header,
            /* [annotation][in] */ 
            _In_  BSTR Value);
        
        DECLSPEC_XFGVIRT(IWinHttpRequest, GetResponseHeader)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetResponseHeader )( 
            __RPC__in IWinHttpRequest * This,
            /* [annotation][in] */ 
            _In_  BSTR Header,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *Value);
        
        DECLSPEC_XFGVIRT(IWinHttpRequest, GetAllResponseHeaders)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetAllResponseHeaders )( 
            __RPC__in IWinHttpRequest * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *Headers);
        
        DECLSPEC_XFGVIRT(IWinHttpRequest, Send)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Send )( 
            __RPC__in IWinHttpRequest * This,
            /* [optional][in] */ VARIANT Body);
        
        DECLSPEC_XFGVIRT(IWinHttpRequest, get_Status)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Status )( 
            __RPC__in IWinHttpRequest * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *Status);
        
        DECLSPEC_XFGVIRT(IWinHttpRequest, get_StatusText)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StatusText )( 
            __RPC__in IWinHttpRequest * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *Status);
        
        DECLSPEC_XFGVIRT(IWinHttpRequest, get_ResponseText)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ResponseText )( 
            __RPC__in IWinHttpRequest * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *Body);
        
        DECLSPEC_XFGVIRT(IWinHttpRequest, get_ResponseBody)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ResponseBody )( 
            __RPC__in IWinHttpRequest * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT *Body);
        
        DECLSPEC_XFGVIRT(IWinHttpRequest, get_ResponseStream)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ResponseStream )( 
            __RPC__in IWinHttpRequest * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT *Body);
        
        DECLSPEC_XFGVIRT(IWinHttpRequest, get_Option)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Option )( 
            __RPC__in IWinHttpRequest * This,
            /* [annotation][in] */ 
            _In_  WinHttpRequestOption Option,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT *Value);
        
        DECLSPEC_XFGVIRT(IWinHttpRequest, put_Option)
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Option )( 
            __RPC__in IWinHttpRequest * This,
            /* [annotation][in] */ 
            _In_  WinHttpRequestOption Option,
            /* [annotation][in] */ 
            _In_  VARIANT Value);
        
        DECLSPEC_XFGVIRT(IWinHttpRequest, WaitForResponse)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WaitForResponse )( 
            __RPC__in IWinHttpRequest * This,
            /* [optional][in] */ VARIANT Timeout,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *Succeeded);
        
        DECLSPEC_XFGVIRT(IWinHttpRequest, Abort)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Abort )( 
            __RPC__in IWinHttpRequest * This);
        
        DECLSPEC_XFGVIRT(IWinHttpRequest, SetTimeouts)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetTimeouts )( 
            __RPC__in IWinHttpRequest * This,
            /* [annotation][in] */ 
            _In_  long ResolveTimeout,
            /* [annotation][in] */ 
            _In_  long ConnectTimeout,
            /* [annotation][in] */ 
            _In_  long SendTimeout,
            /* [annotation][in] */ 
            _In_  long ReceiveTimeout);
        
        DECLSPEC_XFGVIRT(IWinHttpRequest, SetClientCertificate)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetClientCertificate )( 
            __RPC__in IWinHttpRequest * This,
            /* [annotation][in] */ 
            _In_  BSTR ClientCertificate);
        
        DECLSPEC_XFGVIRT(IWinHttpRequest, SetAutoLogonPolicy)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetAutoLogonPolicy )( 
            __RPC__in IWinHttpRequest * This,
            /* [annotation][in] */ 
            _In_  WinHttpRequestAutoLogonPolicy AutoLogonPolicy);
        
        END_INTERFACE
    } IWinHttpRequestVtbl;

    interface IWinHttpRequest
    {
        CONST_VTBL struct IWinHttpRequestVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWinHttpRequest_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWinHttpRequest_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWinHttpRequest_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWinHttpRequest_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IWinHttpRequest_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IWinHttpRequest_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IWinHttpRequest_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IWinHttpRequest_SetProxy(This,ProxySetting,ProxyServer,BypassList)	\
    ( (This)->lpVtbl -> SetProxy(This,ProxySetting,ProxyServer,BypassList) ) 

#define IWinHttpRequest_SetCredentials(This,UserName,Password,Flags)	\
    ( (This)->lpVtbl -> SetCredentials(This,UserName,Password,Flags) ) 

#define IWinHttpRequest_Open(This,Method,Url,Async)	\
    ( (This)->lpVtbl -> Open(This,Method,Url,Async) ) 

#define IWinHttpRequest_SetRequestHeader(This,Header,Value)	\
    ( (This)->lpVtbl -> SetRequestHeader(This,Header,Value) ) 

#define IWinHttpRequest_GetResponseHeader(This,Header,Value)	\
    ( (This)->lpVtbl -> GetResponseHeader(This,Header,Value) ) 

#define IWinHttpRequest_GetAllResponseHeaders(This,Headers)	\
    ( (This)->lpVtbl -> GetAllResponseHeaders(This,Headers) ) 

#define IWinHttpRequest_Send(This,Body)	\
    ( (This)->lpVtbl -> Send(This,Body) ) 

#define IWinHttpRequest_get_Status(This,Status)	\
    ( (This)->lpVtbl -> get_Status(This,Status) ) 

#define IWinHttpRequest_get_StatusText(This,Status)	\
    ( (This)->lpVtbl -> get_StatusText(This,Status) ) 

#define IWinHttpRequest_get_ResponseText(This,Body)	\
    ( (This)->lpVtbl -> get_ResponseText(This,Body) ) 

#define IWinHttpRequest_get_ResponseBody(This,Body)	\
    ( (This)->lpVtbl -> get_ResponseBody(This,Body) ) 

#define IWinHttpRequest_get_ResponseStream(This,Body)	\
    ( (This)->lpVtbl -> get_ResponseStream(This,Body) ) 

#define IWinHttpRequest_get_Option(This,Option,Value)	\
    ( (This)->lpVtbl -> get_Option(This,Option,Value) ) 

#define IWinHttpRequest_put_Option(This,Option,Value)	\
    ( (This)->lpVtbl -> put_Option(This,Option,Value) ) 

#define IWinHttpRequest_WaitForResponse(This,Timeout,Succeeded)	\
    ( (This)->lpVtbl -> WaitForResponse(This,Timeout,Succeeded) ) 

#define IWinHttpRequest_Abort(This)	\
    ( (This)->lpVtbl -> Abort(This) ) 

#define IWinHttpRequest_SetTimeouts(This,ResolveTimeout,ConnectTimeout,SendTimeout,ReceiveTimeout)	\
    ( (This)->lpVtbl -> SetTimeouts(This,ResolveTimeout,ConnectTimeout,SendTimeout,ReceiveTimeout) ) 

#define IWinHttpRequest_SetClientCertificate(This,ClientCertificate)	\
    ( (This)->lpVtbl -> SetClientCertificate(This,ClientCertificate) ) 

#define IWinHttpRequest_SetAutoLogonPolicy(This,AutoLogonPolicy)	\
    ( (This)->lpVtbl -> SetAutoLogonPolicy(This,AutoLogonPolicy) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWinHttpRequest_INTERFACE_DEFINED__ */


#ifndef __IWinHttpRequestEvents_INTERFACE_DEFINED__
#define __IWinHttpRequestEvents_INTERFACE_DEFINED__

/* interface IWinHttpRequestEvents */
/* [unique][helpstring][nonextensible][oleautomation][uuid][object] */ 


EXTERN_C const IID IID_IWinHttpRequestEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("f97f4e15-b787-4212-80d1-d380cbbf982e")
    IWinHttpRequestEvents : public IUnknown
    {
    public:
        virtual void STDMETHODCALLTYPE OnResponseStart( 
            /* [annotation][in] */ 
            _In_  long Status,
            /* [annotation][in] */ 
            _In_  BSTR ContentType) = 0;
        
        virtual void STDMETHODCALLTYPE OnResponseDataAvailable( 
            /* [annotation][in] */ 
            _In_  SAFEARRAY * *Data) = 0;
        
        virtual void STDMETHODCALLTYPE OnResponseFinished( void) = 0;
        
        virtual void STDMETHODCALLTYPE OnError( 
            /* [annotation][in] */ 
            _In_  long ErrorNumber,
            /* [annotation][in] */ 
            _In_  BSTR ErrorDescription) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWinHttpRequestEventsVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IWinHttpRequestEvents * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IWinHttpRequestEvents * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IWinHttpRequestEvents * This);
        
        DECLSPEC_XFGVIRT(IWinHttpRequestEvents, OnResponseStart)
        void ( STDMETHODCALLTYPE *OnResponseStart )( 
            __RPC__in IWinHttpRequestEvents * This,
            /* [annotation][in] */ 
            _In_  long Status,
            /* [annotation][in] */ 
            _In_  BSTR ContentType);
        
        DECLSPEC_XFGVIRT(IWinHttpRequestEvents, OnResponseDataAvailable)
        void ( STDMETHODCALLTYPE *OnResponseDataAvailable )( 
            __RPC__in IWinHttpRequestEvents * This,
            /* [annotation][in] */ 
            _In_  SAFEARRAY * *Data);
        
        DECLSPEC_XFGVIRT(IWinHttpRequestEvents, OnResponseFinished)
        void ( STDMETHODCALLTYPE *OnResponseFinished )( 
            __RPC__in IWinHttpRequestEvents * This);
        
        DECLSPEC_XFGVIRT(IWinHttpRequestEvents, OnError)
        void ( STDMETHODCALLTYPE *OnError )( 
            __RPC__in IWinHttpRequestEvents * This,
            /* [annotation][in] */ 
            _In_  long ErrorNumber,
            /* [annotation][in] */ 
            _In_  BSTR ErrorDescription);
        
        END_INTERFACE
    } IWinHttpRequestEventsVtbl;

    interface IWinHttpRequestEvents
    {
        CONST_VTBL struct IWinHttpRequestEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWinHttpRequestEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWinHttpRequestEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWinHttpRequestEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWinHttpRequestEvents_OnResponseStart(This,Status,ContentType)	\
    ( (This)->lpVtbl -> OnResponseStart(This,Status,ContentType) ) 

#define IWinHttpRequestEvents_OnResponseDataAvailable(This,Data)	\
    ( (This)->lpVtbl -> OnResponseDataAvailable(This,Data) ) 

#define IWinHttpRequestEvents_OnResponseFinished(This)	\
    ( (This)->lpVtbl -> OnResponseFinished(This) ) 

#define IWinHttpRequestEvents_OnError(This,ErrorNumber,ErrorDescription)	\
    ( (This)->lpVtbl -> OnError(This,ErrorNumber,ErrorDescription) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWinHttpRequestEvents_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_WinHttpRequest;

#ifdef __cplusplus

class DECLSPEC_UUID("2087c2f4-2cef-4953-a8ab-66779b670495")
WinHttpRequest;
#endif
#endif /* __WinHttp_LIBRARY_DEFINED__ */

/* interface __MIDL_itf_httprequest_0000_0001 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) */
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_httprequest_0000_0001_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_httprequest_0000_0001_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


