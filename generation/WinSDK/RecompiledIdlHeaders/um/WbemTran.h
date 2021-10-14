

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

#ifndef __wbemtran_h__
#define __wbemtran_h__

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

#ifndef __IWbemTransport_FWD_DEFINED__
#define __IWbemTransport_FWD_DEFINED__
typedef interface IWbemTransport IWbemTransport;

#endif 	/* __IWbemTransport_FWD_DEFINED__ */


#ifndef __IWbemLevel1Login_FWD_DEFINED__
#define __IWbemLevel1Login_FWD_DEFINED__
typedef interface IWbemLevel1Login IWbemLevel1Login;

#endif 	/* __IWbemLevel1Login_FWD_DEFINED__ */


#ifndef __IWbemConnectorLogin_FWD_DEFINED__
#define __IWbemConnectorLogin_FWD_DEFINED__
typedef interface IWbemConnectorLogin IWbemConnectorLogin;

#endif 	/* __IWbemConnectorLogin_FWD_DEFINED__ */


#ifndef __IWbemAddressResolution_FWD_DEFINED__
#define __IWbemAddressResolution_FWD_DEFINED__
typedef interface IWbemAddressResolution IWbemAddressResolution;

#endif 	/* __IWbemAddressResolution_FWD_DEFINED__ */


#ifndef __WbemLevel1Login_FWD_DEFINED__
#define __WbemLevel1Login_FWD_DEFINED__

#ifdef __cplusplus
typedef class WbemLevel1Login WbemLevel1Login;
#else
typedef struct WbemLevel1Login WbemLevel1Login;
#endif /* __cplusplus */

#endif 	/* __WbemLevel1Login_FWD_DEFINED__ */


#ifndef __WbemLocalAddrRes_FWD_DEFINED__
#define __WbemLocalAddrRes_FWD_DEFINED__

#ifdef __cplusplus
typedef class WbemLocalAddrRes WbemLocalAddrRes;
#else
typedef struct WbemLocalAddrRes WbemLocalAddrRes;
#endif /* __cplusplus */

#endif 	/* __WbemLocalAddrRes_FWD_DEFINED__ */


#ifndef __WbemUninitializedClassObject_FWD_DEFINED__
#define __WbemUninitializedClassObject_FWD_DEFINED__

#ifdef __cplusplus
typedef class WbemUninitializedClassObject WbemUninitializedClassObject;
#else
typedef struct WbemUninitializedClassObject WbemUninitializedClassObject;
#endif /* __cplusplus */

#endif 	/* __WbemUninitializedClassObject_FWD_DEFINED__ */


#ifndef __IWbemClientTransport_FWD_DEFINED__
#define __IWbemClientTransport_FWD_DEFINED__
typedef interface IWbemClientTransport IWbemClientTransport;

#endif 	/* __IWbemClientTransport_FWD_DEFINED__ */


#ifndef __IWbemClientConnectionTransport_FWD_DEFINED__
#define __IWbemClientConnectionTransport_FWD_DEFINED__
typedef interface IWbemClientConnectionTransport IWbemClientConnectionTransport;

#endif 	/* __IWbemClientConnectionTransport_FWD_DEFINED__ */


#ifndef __WbemDCOMTransport_FWD_DEFINED__
#define __WbemDCOMTransport_FWD_DEFINED__

#ifdef __cplusplus
typedef class WbemDCOMTransport WbemDCOMTransport;
#else
typedef struct WbemDCOMTransport WbemDCOMTransport;
#endif /* __cplusplus */

#endif 	/* __WbemDCOMTransport_FWD_DEFINED__ */


#ifndef __IWbemLevel1Login_FWD_DEFINED__
#define __IWbemLevel1Login_FWD_DEFINED__
typedef interface IWbemLevel1Login IWbemLevel1Login;

#endif 	/* __IWbemLevel1Login_FWD_DEFINED__ */


#ifndef __IWbemConnectorLogin_FWD_DEFINED__
#define __IWbemConnectorLogin_FWD_DEFINED__
typedef interface IWbemConnectorLogin IWbemConnectorLogin;

#endif 	/* __IWbemConnectorLogin_FWD_DEFINED__ */


#ifndef __IWbemAddressResolution_FWD_DEFINED__
#define __IWbemAddressResolution_FWD_DEFINED__
typedef interface IWbemAddressResolution IWbemAddressResolution;

#endif 	/* __IWbemAddressResolution_FWD_DEFINED__ */


#ifndef __IWbemTransport_FWD_DEFINED__
#define __IWbemTransport_FWD_DEFINED__
typedef interface IWbemTransport IWbemTransport;

#endif 	/* __IWbemTransport_FWD_DEFINED__ */


#ifndef __IWbemConstructClassObject_FWD_DEFINED__
#define __IWbemConstructClassObject_FWD_DEFINED__
typedef interface IWbemConstructClassObject IWbemConstructClassObject;

#endif 	/* __IWbemConstructClassObject_FWD_DEFINED__ */


#ifndef __IWbemClientTransport_FWD_DEFINED__
#define __IWbemClientTransport_FWD_DEFINED__
typedef interface IWbemClientTransport IWbemClientTransport;

#endif 	/* __IWbemClientTransport_FWD_DEFINED__ */


#ifndef __IWbemClientConnectionTransport_FWD_DEFINED__
#define __IWbemClientConnectionTransport_FWD_DEFINED__
typedef interface IWbemClientConnectionTransport IWbemClientConnectionTransport;

#endif 	/* __IWbemClientConnectionTransport_FWD_DEFINED__ */


/* header files for imported files */
#include "objidl.h"
#include "oleidl.h"
#include "oaidl.h"
#include "wbemcli.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_wbemtran_0000_0000 */
/* [local] */ 

/*******************************************************************************/
/*                                                                             */
/*    Copyright (c) Microsoft Corporation.  All rights reserved.               */
/*                                                                             */
/*    This IDL file contains interfaces needed only by implementors of custom  */
/*    transports and custom security systems. These interfaces are not needed  */
/*    for either client or provider access to CIMOM.                           */
/*                                                                             */
/*    See WBEMCLI.IDL for client interfaces, and WBEMPROV.IDL for provider     */
/*    extensions                                                               */
/*                                                                             */
/*******************************************************************************/
#include <winapifamily.h>
#pragma region Desktop Family or WinMgmt Package
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_PKG_WINMGMT)


extern RPC_IF_HANDLE __MIDL_itf_wbemtran_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_wbemtran_0000_0000_v0_0_s_ifspec;


#ifndef __WbemTransports_v1_LIBRARY_DEFINED__
#define __WbemTransports_v1_LIBRARY_DEFINED__

/* library WbemTransports_v1 */
/* [uuid] */ 





typedef 
enum tag_WBEM_LOGIN_TYPE
    {
        WBEM_FLAG_INPROC_LOGIN	= 0,
        WBEM_FLAG_LOCAL_LOGIN	= 1,
        WBEM_FLAG_REMOTE_LOGIN	= 2,
        WBEM_AUTHENTICATION_METHOD_MASK	= 0xf,
        WBEM_FLAG_USE_MULTIPLE_CHALLENGES	= 0x10
    } 	WBEM_LOGIN_TYPE;

typedef /* [length_is][size_is] */ BYTE *WBEM_128BITS;




EXTERN_C const IID LIBID_WbemTransports_v1;

#ifndef __IWbemTransport_INTERFACE_DEFINED__
#define __IWbemTransport_INTERFACE_DEFINED__

/* interface IWbemTransport */
/* [uuid][object][local][restricted] */ 


EXTERN_C const IID IID_IWbemTransport;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("553fe584-2156-11d0-b6ae-00aa003240c7")
    IWbemTransport : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Initialize( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWbemTransportVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWbemTransport * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWbemTransport * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWbemTransport * This);
        
        DECLSPEC_XFGVIRT(IWbemTransport, Initialize)
        HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            IWbemTransport * This);
        
        END_INTERFACE
    } IWbemTransportVtbl;

    interface IWbemTransport
    {
        CONST_VTBL struct IWbemTransportVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWbemTransport_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWbemTransport_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWbemTransport_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWbemTransport_Initialize(This)	\
    ( (This)->lpVtbl -> Initialize(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWbemTransport_INTERFACE_DEFINED__ */


#ifndef __IWbemLevel1Login_INTERFACE_DEFINED__
#define __IWbemLevel1Login_INTERFACE_DEFINED__

/* interface IWbemLevel1Login */
/* [unique][uuid][restricted][object] */ 


EXTERN_C const IID IID_IWbemLevel1Login;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F309AD18-D86A-11d0-A075-00C04FB68820")
    IWbemLevel1Login : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE EstablishPosition( 
            /* [annotation][string][unique][in] */ 
            _In_  LPWSTR wszLocaleList,
            /* [annotation][in] */ 
            _In_  DWORD dwNumLocales,
            /* [annotation][out] */ 
            _Out_  DWORD *reserved) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RequestChallenge( 
            /* [annotation][string][unique][in] */ 
            _In_  LPWSTR wszNetworkResource,
            /* [annotation][string][unique][in] */ 
            _In_  LPWSTR wszUser,
            /* [annotation][out] */ 
            _Out_  WBEM_128BITS Nonce) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE WBEMLogin( 
            /* [annotation][string][unique][in] */ 
            _In_  LPWSTR wszPreferredLocale,
            /* [annotation][unique][in] */ 
            _In_  WBEM_128BITS AccessToken,
            /* [annotation][in] */ 
            _In_  long lFlags,
            /* [annotation][in] */ 
            _In_  IWbemContext *pCtx,
            /* [annotation][out] */ 
            _Out_  IWbemServices **ppNamespace) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE NTLMLogin( 
            /* [annotation][string][unique][in] */ 
            _In_  LPWSTR wszNetworkResource,
            /* [annotation][string][unique][in] */ 
            _In_  LPWSTR wszPreferredLocale,
            /* [annotation][in] */ 
            _In_  long lFlags,
            /* [annotation][in] */ 
            _In_  IWbemContext *pCtx,
            /* [annotation][out] */ 
            _Out_  IWbemServices **ppNamespace) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWbemLevel1LoginVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IWbemLevel1Login * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IWbemLevel1Login * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IWbemLevel1Login * This);
        
        DECLSPEC_XFGVIRT(IWbemLevel1Login, EstablishPosition)
        HRESULT ( STDMETHODCALLTYPE *EstablishPosition )( 
            __RPC__in IWbemLevel1Login * This,
            /* [annotation][string][unique][in] */ 
            _In_  LPWSTR wszLocaleList,
            /* [annotation][in] */ 
            _In_  DWORD dwNumLocales,
            /* [annotation][out] */ 
            _Out_  DWORD *reserved);
        
        DECLSPEC_XFGVIRT(IWbemLevel1Login, RequestChallenge)
        HRESULT ( STDMETHODCALLTYPE *RequestChallenge )( 
            __RPC__in IWbemLevel1Login * This,
            /* [annotation][string][unique][in] */ 
            _In_  LPWSTR wszNetworkResource,
            /* [annotation][string][unique][in] */ 
            _In_  LPWSTR wszUser,
            /* [annotation][out] */ 
            _Out_  WBEM_128BITS Nonce);
        
        DECLSPEC_XFGVIRT(IWbemLevel1Login, WBEMLogin)
        HRESULT ( STDMETHODCALLTYPE *WBEMLogin )( 
            __RPC__in IWbemLevel1Login * This,
            /* [annotation][string][unique][in] */ 
            _In_  LPWSTR wszPreferredLocale,
            /* [annotation][unique][in] */ 
            _In_  WBEM_128BITS AccessToken,
            /* [annotation][in] */ 
            _In_  long lFlags,
            /* [annotation][in] */ 
            _In_  IWbemContext *pCtx,
            /* [annotation][out] */ 
            _Out_  IWbemServices **ppNamespace);
        
        DECLSPEC_XFGVIRT(IWbemLevel1Login, NTLMLogin)
        HRESULT ( STDMETHODCALLTYPE *NTLMLogin )( 
            __RPC__in IWbemLevel1Login * This,
            /* [annotation][string][unique][in] */ 
            _In_  LPWSTR wszNetworkResource,
            /* [annotation][string][unique][in] */ 
            _In_  LPWSTR wszPreferredLocale,
            /* [annotation][in] */ 
            _In_  long lFlags,
            /* [annotation][in] */ 
            _In_  IWbemContext *pCtx,
            /* [annotation][out] */ 
            _Out_  IWbemServices **ppNamespace);
        
        END_INTERFACE
    } IWbemLevel1LoginVtbl;

    interface IWbemLevel1Login
    {
        CONST_VTBL struct IWbemLevel1LoginVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWbemLevel1Login_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWbemLevel1Login_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWbemLevel1Login_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWbemLevel1Login_EstablishPosition(This,wszLocaleList,dwNumLocales,reserved)	\
    ( (This)->lpVtbl -> EstablishPosition(This,wszLocaleList,dwNumLocales,reserved) ) 

#define IWbemLevel1Login_RequestChallenge(This,wszNetworkResource,wszUser,Nonce)	\
    ( (This)->lpVtbl -> RequestChallenge(This,wszNetworkResource,wszUser,Nonce) ) 

#define IWbemLevel1Login_WBEMLogin(This,wszPreferredLocale,AccessToken,lFlags,pCtx,ppNamespace)	\
    ( (This)->lpVtbl -> WBEMLogin(This,wszPreferredLocale,AccessToken,lFlags,pCtx,ppNamespace) ) 

#define IWbemLevel1Login_NTLMLogin(This,wszNetworkResource,wszPreferredLocale,lFlags,pCtx,ppNamespace)	\
    ( (This)->lpVtbl -> NTLMLogin(This,wszNetworkResource,wszPreferredLocale,lFlags,pCtx,ppNamespace) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWbemLevel1Login_INTERFACE_DEFINED__ */


#ifndef __IWbemConnectorLogin_INTERFACE_DEFINED__
#define __IWbemConnectorLogin_INTERFACE_DEFINED__

/* interface IWbemConnectorLogin */
/* [unique][uuid][restricted][object] */ 


EXTERN_C const IID IID_IWbemConnectorLogin;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("d8ec9cb1-b135-4f10-8b1b-c7188bb0d186")
    IWbemConnectorLogin : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ConnectorLogin( 
            /* [annotation][string][unique][in] */ 
            _In_  LPWSTR wszNetworkResource,
            /* [annotation][string][unique][in] */ 
            _In_  LPWSTR wszPreferredLocale,
            /* [annotation][in] */ 
            _In_  long lFlags,
            /* [annotation][in] */ 
            _In_  IWbemContext *pCtx,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **pInterface) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWbemConnectorLoginVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IWbemConnectorLogin * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IWbemConnectorLogin * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IWbemConnectorLogin * This);
        
        DECLSPEC_XFGVIRT(IWbemConnectorLogin, ConnectorLogin)
        HRESULT ( STDMETHODCALLTYPE *ConnectorLogin )( 
            __RPC__in IWbemConnectorLogin * This,
            /* [annotation][string][unique][in] */ 
            _In_  LPWSTR wszNetworkResource,
            /* [annotation][string][unique][in] */ 
            _In_  LPWSTR wszPreferredLocale,
            /* [annotation][in] */ 
            _In_  long lFlags,
            /* [annotation][in] */ 
            _In_  IWbemContext *pCtx,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **pInterface);
        
        END_INTERFACE
    } IWbemConnectorLoginVtbl;

    interface IWbemConnectorLogin
    {
        CONST_VTBL struct IWbemConnectorLoginVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWbemConnectorLogin_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWbemConnectorLogin_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWbemConnectorLogin_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWbemConnectorLogin_ConnectorLogin(This,wszNetworkResource,wszPreferredLocale,lFlags,pCtx,riid,pInterface)	\
    ( (This)->lpVtbl -> ConnectorLogin(This,wszNetworkResource,wszPreferredLocale,lFlags,pCtx,riid,pInterface) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWbemConnectorLogin_INTERFACE_DEFINED__ */


#ifndef __IWbemAddressResolution_INTERFACE_DEFINED__
#define __IWbemAddressResolution_INTERFACE_DEFINED__

/* interface IWbemAddressResolution */
/* [unique][restricted][uuid][local][object] */ 


EXTERN_C const IID IID_IWbemAddressResolution;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F7CE2E12-8C90-11d1-9E7B-00C04FC324A8")
    IWbemAddressResolution : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Resolve( 
            /* [annotation][in] */ 
            _In_  LPWSTR wszNamespacePath,
            /* [annotation][out] */ 
            _Out_  LPWSTR wszAddressType,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwAddressLength,
            /* [annotation][size_is][size_is][out] */ 
            _Out_  BYTE **pabBinaryAddress) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWbemAddressResolutionVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWbemAddressResolution * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWbemAddressResolution * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWbemAddressResolution * This);
        
        DECLSPEC_XFGVIRT(IWbemAddressResolution, Resolve)
        HRESULT ( STDMETHODCALLTYPE *Resolve )( 
            IWbemAddressResolution * This,
            /* [annotation][in] */ 
            _In_  LPWSTR wszNamespacePath,
            /* [annotation][out] */ 
            _Out_  LPWSTR wszAddressType,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwAddressLength,
            /* [annotation][size_is][size_is][out] */ 
            _Out_  BYTE **pabBinaryAddress);
        
        END_INTERFACE
    } IWbemAddressResolutionVtbl;

    interface IWbemAddressResolution
    {
        CONST_VTBL struct IWbemAddressResolutionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWbemAddressResolution_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWbemAddressResolution_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWbemAddressResolution_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWbemAddressResolution_Resolve(This,wszNamespacePath,wszAddressType,pdwAddressLength,pabBinaryAddress)	\
    ( (This)->lpVtbl -> Resolve(This,wszNamespacePath,wszAddressType,pdwAddressLength,pabBinaryAddress) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWbemAddressResolution_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_WbemLevel1Login;

#ifdef __cplusplus

class DECLSPEC_UUID("8BC3F05E-D86B-11d0-A075-00C04FB68820")
WbemLevel1Login;
#endif

EXTERN_C const CLSID CLSID_WbemLocalAddrRes;

#ifdef __cplusplus

class DECLSPEC_UUID("A1044801-8F7E-11d1-9E7C-00C04FC324A8")
WbemLocalAddrRes;
#endif

EXTERN_C const CLSID CLSID_WbemUninitializedClassObject;

#ifdef __cplusplus

class DECLSPEC_UUID("7a0227f6-7108-11d1-ad90-00c04fd8fdff")
WbemUninitializedClassObject;
#endif

#ifndef __IWbemClientTransport_INTERFACE_DEFINED__
#define __IWbemClientTransport_INTERFACE_DEFINED__

/* interface IWbemClientTransport */
/* [unique][restricted][uuid][local][object] */ 


EXTERN_C const IID IID_IWbemClientTransport;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F7CE2E11-8C90-11d1-9E7B-00C04FC324A8")
    IWbemClientTransport : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ConnectServer( 
            /* [annotation][in] */ 
            _In_  BSTR strAddressType,
            /* [annotation][in] */ 
            _In_  DWORD dwBinaryAddressLength,
            /* [annotation][size_is][in] */ 
            _In_reads_(dwBinaryAddressLength)  BYTE *abBinaryAddress,
            /* [annotation][in] */ 
            _In_  BSTR strNetworkResource,
            /* [annotation][in] */ 
            _In_  BSTR strUser,
            /* [annotation][in] */ 
            _In_  BSTR strPassword,
            /* [annotation][in] */ 
            _In_  BSTR strLocale,
            /* [annotation][in] */ 
            _In_  long lSecurityFlags,
            /* [annotation][in] */ 
            _In_  BSTR strAuthority,
            /* [annotation][in] */ 
            _In_  IWbemContext *pCtx,
            /* [annotation][out] */ 
            _Out_  IWbemServices **ppNamespace) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWbemClientTransportVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWbemClientTransport * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWbemClientTransport * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWbemClientTransport * This);
        
        DECLSPEC_XFGVIRT(IWbemClientTransport, ConnectServer)
        HRESULT ( STDMETHODCALLTYPE *ConnectServer )( 
            IWbemClientTransport * This,
            /* [annotation][in] */ 
            _In_  BSTR strAddressType,
            /* [annotation][in] */ 
            _In_  DWORD dwBinaryAddressLength,
            /* [annotation][size_is][in] */ 
            _In_reads_(dwBinaryAddressLength)  BYTE *abBinaryAddress,
            /* [annotation][in] */ 
            _In_  BSTR strNetworkResource,
            /* [annotation][in] */ 
            _In_  BSTR strUser,
            /* [annotation][in] */ 
            _In_  BSTR strPassword,
            /* [annotation][in] */ 
            _In_  BSTR strLocale,
            /* [annotation][in] */ 
            _In_  long lSecurityFlags,
            /* [annotation][in] */ 
            _In_  BSTR strAuthority,
            /* [annotation][in] */ 
            _In_  IWbemContext *pCtx,
            /* [annotation][out] */ 
            _Out_  IWbemServices **ppNamespace);
        
        END_INTERFACE
    } IWbemClientTransportVtbl;

    interface IWbemClientTransport
    {
        CONST_VTBL struct IWbemClientTransportVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWbemClientTransport_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWbemClientTransport_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWbemClientTransport_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWbemClientTransport_ConnectServer(This,strAddressType,dwBinaryAddressLength,abBinaryAddress,strNetworkResource,strUser,strPassword,strLocale,lSecurityFlags,strAuthority,pCtx,ppNamespace)	\
    ( (This)->lpVtbl -> ConnectServer(This,strAddressType,dwBinaryAddressLength,abBinaryAddress,strNetworkResource,strUser,strPassword,strLocale,lSecurityFlags,strAuthority,pCtx,ppNamespace) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWbemClientTransport_INTERFACE_DEFINED__ */


#ifndef __IWbemClientConnectionTransport_INTERFACE_DEFINED__
#define __IWbemClientConnectionTransport_INTERFACE_DEFINED__

/* interface IWbemClientConnectionTransport */
/* [unique][restricted][uuid][local][object] */ 


EXTERN_C const IID IID_IWbemClientConnectionTransport;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("a889c72a-fcc1-4a9e-af61-ed071333fb5b")
    IWbemClientConnectionTransport : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Open( 
            /* [annotation][in] */ 
            _In_  BSTR strAddressType,
            /* [annotation][in] */ 
            _In_  DWORD dwBinaryAddressLength,
            /* [annotation][size_is][in] */ 
            _In_reads_(dwBinaryAddressLength)  BYTE *abBinaryAddress,
            /* [annotation][in] */ 
            _In_  const BSTR strObject,
            /* [annotation][in] */ 
            _In_  const BSTR strUser,
            /* [annotation][in] */ 
            _In_  const BSTR strPassword,
            /* [annotation][in] */ 
            _In_  const BSTR strLocale,
            /* [annotation][in] */ 
            _In_  long lFlags,
            /* [annotation][in] */ 
            _In_  IWbemContext *pCtx,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **pInterface,
            /* [annotation][out] */ 
            _Out_  IWbemCallResult **pCallRes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OpenAsync( 
            /* [annotation][in] */ 
            _In_  BSTR strAddressType,
            /* [annotation][in] */ 
            _In_  DWORD dwBinaryAddressLength,
            /* [annotation][size_is][in] */ 
            _In_reads_(dwBinaryAddressLength)  BYTE *abBinaryAddress,
            /* [annotation][in] */ 
            _In_  const BSTR strObject,
            /* [annotation][in] */ 
            _In_  const BSTR strUser,
            /* [annotation][in] */ 
            _In_  const BSTR strPassword,
            /* [annotation][in] */ 
            _In_  const BSTR strLocale,
            /* [annotation][in] */ 
            _In_  long lFlags,
            /* [annotation][in] */ 
            _In_  IWbemContext *pCtx,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  IWbemObjectSink *pResponseHandler) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Cancel( 
            /* [annotation][in] */ 
            _In_  long lFlags,
            /* [annotation][in] */ 
            _In_  IWbemObjectSink *pHandler) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWbemClientConnectionTransportVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWbemClientConnectionTransport * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWbemClientConnectionTransport * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWbemClientConnectionTransport * This);
        
        DECLSPEC_XFGVIRT(IWbemClientConnectionTransport, Open)
        HRESULT ( STDMETHODCALLTYPE *Open )( 
            IWbemClientConnectionTransport * This,
            /* [annotation][in] */ 
            _In_  BSTR strAddressType,
            /* [annotation][in] */ 
            _In_  DWORD dwBinaryAddressLength,
            /* [annotation][size_is][in] */ 
            _In_reads_(dwBinaryAddressLength)  BYTE *abBinaryAddress,
            /* [annotation][in] */ 
            _In_  const BSTR strObject,
            /* [annotation][in] */ 
            _In_  const BSTR strUser,
            /* [annotation][in] */ 
            _In_  const BSTR strPassword,
            /* [annotation][in] */ 
            _In_  const BSTR strLocale,
            /* [annotation][in] */ 
            _In_  long lFlags,
            /* [annotation][in] */ 
            _In_  IWbemContext *pCtx,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **pInterface,
            /* [annotation][out] */ 
            _Out_  IWbemCallResult **pCallRes);
        
        DECLSPEC_XFGVIRT(IWbemClientConnectionTransport, OpenAsync)
        HRESULT ( STDMETHODCALLTYPE *OpenAsync )( 
            IWbemClientConnectionTransport * This,
            /* [annotation][in] */ 
            _In_  BSTR strAddressType,
            /* [annotation][in] */ 
            _In_  DWORD dwBinaryAddressLength,
            /* [annotation][size_is][in] */ 
            _In_reads_(dwBinaryAddressLength)  BYTE *abBinaryAddress,
            /* [annotation][in] */ 
            _In_  const BSTR strObject,
            /* [annotation][in] */ 
            _In_  const BSTR strUser,
            /* [annotation][in] */ 
            _In_  const BSTR strPassword,
            /* [annotation][in] */ 
            _In_  const BSTR strLocale,
            /* [annotation][in] */ 
            _In_  long lFlags,
            /* [annotation][in] */ 
            _In_  IWbemContext *pCtx,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  IWbemObjectSink *pResponseHandler);
        
        DECLSPEC_XFGVIRT(IWbemClientConnectionTransport, Cancel)
        HRESULT ( STDMETHODCALLTYPE *Cancel )( 
            IWbemClientConnectionTransport * This,
            /* [annotation][in] */ 
            _In_  long lFlags,
            /* [annotation][in] */ 
            _In_  IWbemObjectSink *pHandler);
        
        END_INTERFACE
    } IWbemClientConnectionTransportVtbl;

    interface IWbemClientConnectionTransport
    {
        CONST_VTBL struct IWbemClientConnectionTransportVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWbemClientConnectionTransport_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWbemClientConnectionTransport_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWbemClientConnectionTransport_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWbemClientConnectionTransport_Open(This,strAddressType,dwBinaryAddressLength,abBinaryAddress,strObject,strUser,strPassword,strLocale,lFlags,pCtx,riid,pInterface,pCallRes)	\
    ( (This)->lpVtbl -> Open(This,strAddressType,dwBinaryAddressLength,abBinaryAddress,strObject,strUser,strPassword,strLocale,lFlags,pCtx,riid,pInterface,pCallRes) ) 

#define IWbemClientConnectionTransport_OpenAsync(This,strAddressType,dwBinaryAddressLength,abBinaryAddress,strObject,strUser,strPassword,strLocale,lFlags,pCtx,riid,pResponseHandler)	\
    ( (This)->lpVtbl -> OpenAsync(This,strAddressType,dwBinaryAddressLength,abBinaryAddress,strObject,strUser,strPassword,strLocale,lFlags,pCtx,riid,pResponseHandler) ) 

#define IWbemClientConnectionTransport_Cancel(This,lFlags,pHandler)	\
    ( (This)->lpVtbl -> Cancel(This,lFlags,pHandler) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWbemClientConnectionTransport_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_WbemDCOMTransport;

#ifdef __cplusplus

class DECLSPEC_UUID("F7CE2E13-8C90-11d1-9E7B-00C04FC324A8")
WbemDCOMTransport;
#endif
#endif /* __WbemTransports_v1_LIBRARY_DEFINED__ */

#ifndef __IWbemConstructClassObject_INTERFACE_DEFINED__
#define __IWbemConstructClassObject_INTERFACE_DEFINED__

/* interface IWbemConstructClassObject */
/* [uuid][object][local][restricted] */ 


EXTERN_C const IID IID_IWbemConstructClassObject;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9ef76194-70d5-11d1-ad90-00c04fd8fdff")
    IWbemConstructClassObject : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetInheritanceChain( 
            /* [annotation][in] */ 
            _In_  long lNumAntecedents,
            /* [annotation][string][size_is][in] */ 
            _In_reads_bytes_(lNumAntecedents)  LPWSTR *awszAntecedents) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPropertyOrigin( 
            /* [annotation][string][in] */ 
            _In_  LPCWSTR wszPropertyName,
            /* [annotation][in] */ 
            _In_  long lOriginIndex) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMethodOrigin( 
            /* [annotation][string][in] */ 
            _In_  LPCWSTR wszMethodName,
            /* [annotation][in] */ 
            _In_  long lOriginIndex) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetServerNamespace( 
            /* [annotation][string][in] */ 
            _In_  LPCWSTR wszServer,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR wszNamespace) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWbemConstructClassObjectVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWbemConstructClassObject * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWbemConstructClassObject * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWbemConstructClassObject * This);
        
        DECLSPEC_XFGVIRT(IWbemConstructClassObject, SetInheritanceChain)
        HRESULT ( STDMETHODCALLTYPE *SetInheritanceChain )( 
            IWbemConstructClassObject * This,
            /* [annotation][in] */ 
            _In_  long lNumAntecedents,
            /* [annotation][string][size_is][in] */ 
            _In_reads_bytes_(lNumAntecedents)  LPWSTR *awszAntecedents);
        
        DECLSPEC_XFGVIRT(IWbemConstructClassObject, SetPropertyOrigin)
        HRESULT ( STDMETHODCALLTYPE *SetPropertyOrigin )( 
            IWbemConstructClassObject * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR wszPropertyName,
            /* [annotation][in] */ 
            _In_  long lOriginIndex);
        
        DECLSPEC_XFGVIRT(IWbemConstructClassObject, SetMethodOrigin)
        HRESULT ( STDMETHODCALLTYPE *SetMethodOrigin )( 
            IWbemConstructClassObject * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR wszMethodName,
            /* [annotation][in] */ 
            _In_  long lOriginIndex);
        
        DECLSPEC_XFGVIRT(IWbemConstructClassObject, SetServerNamespace)
        HRESULT ( STDMETHODCALLTYPE *SetServerNamespace )( 
            IWbemConstructClassObject * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR wszServer,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR wszNamespace);
        
        END_INTERFACE
    } IWbemConstructClassObjectVtbl;

    interface IWbemConstructClassObject
    {
        CONST_VTBL struct IWbemConstructClassObjectVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWbemConstructClassObject_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWbemConstructClassObject_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWbemConstructClassObject_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWbemConstructClassObject_SetInheritanceChain(This,lNumAntecedents,awszAntecedents)	\
    ( (This)->lpVtbl -> SetInheritanceChain(This,lNumAntecedents,awszAntecedents) ) 

#define IWbemConstructClassObject_SetPropertyOrigin(This,wszPropertyName,lOriginIndex)	\
    ( (This)->lpVtbl -> SetPropertyOrigin(This,wszPropertyName,lOriginIndex) ) 

#define IWbemConstructClassObject_SetMethodOrigin(This,wszMethodName,lOriginIndex)	\
    ( (This)->lpVtbl -> SetMethodOrigin(This,wszMethodName,lOriginIndex) ) 

#define IWbemConstructClassObject_SetServerNamespace(This,wszServer,wszNamespace)	\
    ( (This)->lpVtbl -> SetServerNamespace(This,wszServer,wszNamespace) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWbemConstructClassObject_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_wbemtran_0000_0008 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_PKG_WINMGMT) */
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_wbemtran_0000_0008_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_wbemtran_0000_0008_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


