

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

#ifndef __pluginauthenticator_h__
#define __pluginauthenticator_h__

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

#ifndef __EXPERIMENTAL_IPluginAuthenticator_FWD_DEFINED__
#define __EXPERIMENTAL_IPluginAuthenticator_FWD_DEFINED__
typedef interface EXPERIMENTAL_IPluginAuthenticator EXPERIMENTAL_IPluginAuthenticator;

#endif 	/* __EXPERIMENTAL_IPluginAuthenticator_FWD_DEFINED__ */


#ifndef __IPluginAuthenticator_FWD_DEFINED__
#define __IPluginAuthenticator_FWD_DEFINED__
typedef interface IPluginAuthenticator IPluginAuthenticator;

#endif 	/* __IPluginAuthenticator_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_pluginauthenticator_0000_0000 */
/* [local] */ 

typedef 
enum _WEBAUTHN_PLUGIN_REQUEST_TYPE
    {
        WEBAUTHN_PLUGIN_REQUEST_TYPE_CTAP2_CBOR	= 0x1
    } 	WEBAUTHN_PLUGIN_REQUEST_TYPE;

typedef struct _EXPERIMENTAL_WEBAUTHN_PLUGIN_OPERATION_REQUEST
    {
    HWND hWnd;
    GUID transactionId;
    DWORD cbRequestSignature;
    /* [size_is] */ byte *pbRequestSignature;
    DWORD cbEncodedRequest;
    /* [size_is] */ byte *pbEncodedRequest;
    } 	EXPERIMENTAL_WEBAUTHN_PLUGIN_OPERATION_REQUEST;

typedef struct _EXPERIMENTAL_WEBAUTHN_PLUGIN_OPERATION_REQUEST *EXPERIMENTAL_PWEBAUTHN_PLUGIN_OPERATION_REQUEST;

typedef const EXPERIMENTAL_WEBAUTHN_PLUGIN_OPERATION_REQUEST *EXPERIMENTAL_PCWEBAUTHN_PLUGIN_OPERATION_REQUEST;

typedef struct _WEBAUTHN_PLUGIN_OPERATION_REQUEST
    {
    HWND hWnd;
    GUID transactionId;
    DWORD cbRequestSignature;
    /* [size_is] */ byte *pbRequestSignature;
    WEBAUTHN_PLUGIN_REQUEST_TYPE requestType;
    DWORD cbEncodedRequest;
    /* [size_is] */ byte *pbEncodedRequest;
    } 	WEBAUTHN_PLUGIN_OPERATION_REQUEST;

typedef struct _WEBAUTHN_PLUGIN_OPERATION_REQUEST *PWEBAUTHN_PLUGIN_OPERATION_REQUEST;

typedef const WEBAUTHN_PLUGIN_OPERATION_REQUEST *PCWEBAUTHN_PLUGIN_OPERATION_REQUEST;

typedef struct _EXPERIMENTAL_WEBAUTHN_PLUGIN_OPERATION_RESPONSE
    {
    DWORD cbEncodedResponse;
    /* [size_is] */ byte *pbEncodedResponse;
    } 	EXPERIMENTAL_WEBAUTHN_PLUGIN_OPERATION_RESPONSE;

typedef struct _EXPERIMENTAL_WEBAUTHN_PLUGIN_OPERATION_RESPONSE *EXPERIMENTAL_PWEBAUTHN_PLUGIN_OPERATION_RESPONSE;

typedef const EXPERIMENTAL_WEBAUTHN_PLUGIN_OPERATION_RESPONSE *EXPERIMENTAL_PCWEBAUTHN_PLUGIN_OPERATION_RESPONSE;

typedef struct _WEBAUTHN_PLUGIN_OPERATION_RESPONSE
    {
    DWORD cbEncodedResponse;
    /* [size_is] */ byte *pbEncodedResponse;
    } 	WEBAUTHN_PLUGIN_OPERATION_RESPONSE;

typedef struct _WEBAUTHN_PLUGIN_OPERATION_RESPONSE *PWEBAUTHN_PLUGIN_OPERATION_RESPONSE;

typedef const WEBAUTHN_PLUGIN_OPERATION_RESPONSE *PCWEBAUTHN_PLUGIN_OPERATION_RESPONSE;

typedef struct _EXPERIMENTAL_WEBAUTHN_PLUGIN_CANCEL_OPERATION_REQUEST
    {
    GUID transactionId;
    DWORD cbRequestSignature;
    /* [size_is] */ byte *pbRequestSignature;
    } 	EXPERIMENTAL_WEBAUTHN_PLUGIN_CANCEL_OPERATION_REQUEST;

typedef struct _EXPERIMENTAL_WEBAUTHN_PLUGIN_CANCEL_OPERATION_REQUEST *EXPERIMENTAL_PWEBAUTHN_PLUGIN_CANCEL_OPERATION_REQUEST;

typedef const EXPERIMENTAL_WEBAUTHN_PLUGIN_CANCEL_OPERATION_REQUEST *EXPERIMENTAL_PCWEBAUTHN_PLUGIN_CANCEL_OPERATION_REQUEST;

typedef struct _WEBAUTHN_PLUGIN_CANCEL_OPERATION_REQUEST
    {
    GUID transactionId;
    DWORD cbRequestSignature;
    /* [size_is] */ byte *pbRequestSignature;
    } 	WEBAUTHN_PLUGIN_CANCEL_OPERATION_REQUEST;

typedef struct _WEBAUTHN_PLUGIN_CANCEL_OPERATION_REQUEST *PWEBAUTHN_PLUGIN_CANCEL_OPERATION_REQUEST;

typedef const WEBAUTHN_PLUGIN_CANCEL_OPERATION_REQUEST *PCWEBAUTHN_PLUGIN_CANCEL_OPERATION_REQUEST;

typedef 
enum _PLUGIN_LOCK_STATUS
    {
        PluginLocked	= 0,
        PluginUnlocked	= ( PluginLocked + 1 ) 
    } 	PLUGIN_LOCK_STATUS;



extern RPC_IF_HANDLE __MIDL_itf_pluginauthenticator_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_pluginauthenticator_0000_0000_v0_0_s_ifspec;

#ifndef __EXPERIMENTAL_IPluginAuthenticator_INTERFACE_DEFINED__
#define __EXPERIMENTAL_IPluginAuthenticator_INTERFACE_DEFINED__

/* interface EXPERIMENTAL_IPluginAuthenticator */
/* [unique][version][uuid][object] */ 


EXTERN_C const IID IID_EXPERIMENTAL_IPluginAuthenticator;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("e6466e9a-b2f3-47c5-b88d-89bc14a8d998")
    EXPERIMENTAL_IPluginAuthenticator : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE EXPERIMENTAL_PluginMakeCredential( 
            /* [annotation][in] */ 
            _In_  EXPERIMENTAL_PCWEBAUTHN_PLUGIN_OPERATION_REQUEST request,
            /* [annotation][out] */ 
            _Out_  EXPERIMENTAL_PWEBAUTHN_PLUGIN_OPERATION_RESPONSE *response) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EXPERIMENTAL_PluginGetAssertion( 
            /* [annotation][in] */ 
            _In_  EXPERIMENTAL_PCWEBAUTHN_PLUGIN_OPERATION_REQUEST request,
            /* [annotation][out] */ 
            _Out_  EXPERIMENTAL_PWEBAUTHN_PLUGIN_OPERATION_RESPONSE *response) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EXPERIMENTAL_PluginCancelOperation( 
            /* [annotation][in] */ 
            _In_  EXPERIMENTAL_PCWEBAUTHN_PLUGIN_CANCEL_OPERATION_REQUEST request) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct EXPERIMENTAL_IPluginAuthenticatorVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in EXPERIMENTAL_IPluginAuthenticator * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in EXPERIMENTAL_IPluginAuthenticator * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in EXPERIMENTAL_IPluginAuthenticator * This);
        
        DECLSPEC_XFGVIRT(EXPERIMENTAL_IPluginAuthenticator, EXPERIMENTAL_PluginMakeCredential)
        HRESULT ( STDMETHODCALLTYPE *EXPERIMENTAL_PluginMakeCredential )( 
            __RPC__in EXPERIMENTAL_IPluginAuthenticator * This,
            /* [annotation][in] */ 
            _In_  EXPERIMENTAL_PCWEBAUTHN_PLUGIN_OPERATION_REQUEST request,
            /* [annotation][out] */ 
            _Out_  EXPERIMENTAL_PWEBAUTHN_PLUGIN_OPERATION_RESPONSE *response);
        
        DECLSPEC_XFGVIRT(EXPERIMENTAL_IPluginAuthenticator, EXPERIMENTAL_PluginGetAssertion)
        HRESULT ( STDMETHODCALLTYPE *EXPERIMENTAL_PluginGetAssertion )( 
            __RPC__in EXPERIMENTAL_IPluginAuthenticator * This,
            /* [annotation][in] */ 
            _In_  EXPERIMENTAL_PCWEBAUTHN_PLUGIN_OPERATION_REQUEST request,
            /* [annotation][out] */ 
            _Out_  EXPERIMENTAL_PWEBAUTHN_PLUGIN_OPERATION_RESPONSE *response);
        
        DECLSPEC_XFGVIRT(EXPERIMENTAL_IPluginAuthenticator, EXPERIMENTAL_PluginCancelOperation)
        HRESULT ( STDMETHODCALLTYPE *EXPERIMENTAL_PluginCancelOperation )( 
            __RPC__in EXPERIMENTAL_IPluginAuthenticator * This,
            /* [annotation][in] */ 
            _In_  EXPERIMENTAL_PCWEBAUTHN_PLUGIN_CANCEL_OPERATION_REQUEST request);
        
        END_INTERFACE
    } EXPERIMENTAL_IPluginAuthenticatorVtbl;

    interface EXPERIMENTAL_IPluginAuthenticator
    {
        CONST_VTBL struct EXPERIMENTAL_IPluginAuthenticatorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define EXPERIMENTAL_IPluginAuthenticator_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define EXPERIMENTAL_IPluginAuthenticator_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define EXPERIMENTAL_IPluginAuthenticator_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define EXPERIMENTAL_IPluginAuthenticator_EXPERIMENTAL_PluginMakeCredential(This,request,response)	\
    ( (This)->lpVtbl -> EXPERIMENTAL_PluginMakeCredential(This,request,response) ) 

#define EXPERIMENTAL_IPluginAuthenticator_EXPERIMENTAL_PluginGetAssertion(This,request,response)	\
    ( (This)->lpVtbl -> EXPERIMENTAL_PluginGetAssertion(This,request,response) ) 

#define EXPERIMENTAL_IPluginAuthenticator_EXPERIMENTAL_PluginCancelOperation(This,request)	\
    ( (This)->lpVtbl -> EXPERIMENTAL_PluginCancelOperation(This,request) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __EXPERIMENTAL_IPluginAuthenticator_INTERFACE_DEFINED__ */


#ifndef __IPluginAuthenticator_INTERFACE_DEFINED__
#define __IPluginAuthenticator_INTERFACE_DEFINED__

/* interface IPluginAuthenticator */
/* [ref][version][uuid][object] */ 


EXTERN_C const IID IID_IPluginAuthenticator;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("d26bcf6f-b54c-43ff-9f06-d5bf148625f7")
    IPluginAuthenticator : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE MakeCredential( 
            /* [annotation][in] */ 
            _In_  PCWEBAUTHN_PLUGIN_OPERATION_REQUEST request,
            /* [annotation][retval][out] */ 
            _Out_retval_  PWEBAUTHN_PLUGIN_OPERATION_RESPONSE response) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAssertion( 
            /* [annotation][in] */ 
            _In_  PCWEBAUTHN_PLUGIN_OPERATION_REQUEST request,
            /* [annotation][retval][out] */ 
            _Out_retval_  PWEBAUTHN_PLUGIN_OPERATION_RESPONSE response) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CancelOperation( 
            /* [annotation][in] */ 
            _In_  PCWEBAUTHN_PLUGIN_CANCEL_OPERATION_REQUEST request) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLockStatus( 
            /* [annotation][retval][out] */ 
            _Out_retval_  PLUGIN_LOCK_STATUS *lockStatus) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IPluginAuthenticatorVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IPluginAuthenticator * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IPluginAuthenticator * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IPluginAuthenticator * This);
        
        DECLSPEC_XFGVIRT(IPluginAuthenticator, MakeCredential)
        HRESULT ( STDMETHODCALLTYPE *MakeCredential )( 
            __RPC__in IPluginAuthenticator * This,
            /* [annotation][in] */ 
            _In_  PCWEBAUTHN_PLUGIN_OPERATION_REQUEST request,
            /* [annotation][retval][out] */ 
            _Out_retval_  PWEBAUTHN_PLUGIN_OPERATION_RESPONSE response);
        
        DECLSPEC_XFGVIRT(IPluginAuthenticator, GetAssertion)
        HRESULT ( STDMETHODCALLTYPE *GetAssertion )( 
            __RPC__in IPluginAuthenticator * This,
            /* [annotation][in] */ 
            _In_  PCWEBAUTHN_PLUGIN_OPERATION_REQUEST request,
            /* [annotation][retval][out] */ 
            _Out_retval_  PWEBAUTHN_PLUGIN_OPERATION_RESPONSE response);
        
        DECLSPEC_XFGVIRT(IPluginAuthenticator, CancelOperation)
        HRESULT ( STDMETHODCALLTYPE *CancelOperation )( 
            __RPC__in IPluginAuthenticator * This,
            /* [annotation][in] */ 
            _In_  PCWEBAUTHN_PLUGIN_CANCEL_OPERATION_REQUEST request);
        
        DECLSPEC_XFGVIRT(IPluginAuthenticator, GetLockStatus)
        HRESULT ( STDMETHODCALLTYPE *GetLockStatus )( 
            __RPC__in IPluginAuthenticator * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  PLUGIN_LOCK_STATUS *lockStatus);
        
        END_INTERFACE
    } IPluginAuthenticatorVtbl;

    interface IPluginAuthenticator
    {
        CONST_VTBL struct IPluginAuthenticatorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPluginAuthenticator_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPluginAuthenticator_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPluginAuthenticator_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPluginAuthenticator_MakeCredential(This,request,response)	\
    ( (This)->lpVtbl -> MakeCredential(This,request,response) ) 

#define IPluginAuthenticator_GetAssertion(This,request,response)	\
    ( (This)->lpVtbl -> GetAssertion(This,request,response) ) 

#define IPluginAuthenticator_CancelOperation(This,request)	\
    ( (This)->lpVtbl -> CancelOperation(This,request) ) 

#define IPluginAuthenticator_GetLockStatus(This,lockStatus)	\
    ( (This)->lpVtbl -> GetLockStatus(This,lockStatus) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPluginAuthenticator_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  HWND_UserSize(     __RPC__in unsigned long *, unsigned long            , __RPC__in HWND * ); 
unsigned char * __RPC_USER  HWND_UserMarshal(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in HWND * ); 
unsigned char * __RPC_USER  HWND_UserUnmarshal(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out HWND * ); 
void                      __RPC_USER  HWND_UserFree(     __RPC__in unsigned long *, __RPC__in HWND * ); 

unsigned long             __RPC_USER  HWND_UserSize64(     __RPC__in unsigned long *, unsigned long            , __RPC__in HWND * ); 
unsigned char * __RPC_USER  HWND_UserMarshal64(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in HWND * ); 
unsigned char * __RPC_USER  HWND_UserUnmarshal64(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out HWND * ); 
void                      __RPC_USER  HWND_UserFree64(     __RPC__in unsigned long *, __RPC__in HWND * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


