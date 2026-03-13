

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

#ifndef __tsvirtualchannels_h__
#define __tsvirtualchannels_h__

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

#ifndef __IWTSPlugin_FWD_DEFINED__
#define __IWTSPlugin_FWD_DEFINED__
typedef interface IWTSPlugin IWTSPlugin;

#endif 	/* __IWTSPlugin_FWD_DEFINED__ */


#ifndef __IWTSListener_FWD_DEFINED__
#define __IWTSListener_FWD_DEFINED__
typedef interface IWTSListener IWTSListener;

#endif 	/* __IWTSListener_FWD_DEFINED__ */


#ifndef __IWTSListenerCallback_FWD_DEFINED__
#define __IWTSListenerCallback_FWD_DEFINED__
typedef interface IWTSListenerCallback IWTSListenerCallback;

#endif 	/* __IWTSListenerCallback_FWD_DEFINED__ */


#ifndef __IWTSVirtualChannelCallback_FWD_DEFINED__
#define __IWTSVirtualChannelCallback_FWD_DEFINED__
typedef interface IWTSVirtualChannelCallback IWTSVirtualChannelCallback;

#endif 	/* __IWTSVirtualChannelCallback_FWD_DEFINED__ */


#ifndef __IWTSVirtualChannelManager_FWD_DEFINED__
#define __IWTSVirtualChannelManager_FWD_DEFINED__
typedef interface IWTSVirtualChannelManager IWTSVirtualChannelManager;

#endif 	/* __IWTSVirtualChannelManager_FWD_DEFINED__ */


#ifndef __IWTSVirtualChannel_FWD_DEFINED__
#define __IWTSVirtualChannel_FWD_DEFINED__
typedef interface IWTSVirtualChannel IWTSVirtualChannel;

#endif 	/* __IWTSVirtualChannel_FWD_DEFINED__ */


#ifndef __IWTSPluginServiceProvider_FWD_DEFINED__
#define __IWTSPluginServiceProvider_FWD_DEFINED__
typedef interface IWTSPluginServiceProvider IWTSPluginServiceProvider;

#endif 	/* __IWTSPluginServiceProvider_FWD_DEFINED__ */


#ifndef __IWTSBitmapRenderer_FWD_DEFINED__
#define __IWTSBitmapRenderer_FWD_DEFINED__
typedef interface IWTSBitmapRenderer IWTSBitmapRenderer;

#endif 	/* __IWTSBitmapRenderer_FWD_DEFINED__ */


#ifndef __IWTSBitmapRendererCallback_FWD_DEFINED__
#define __IWTSBitmapRendererCallback_FWD_DEFINED__
typedef interface IWTSBitmapRendererCallback IWTSBitmapRendererCallback;

#endif 	/* __IWTSBitmapRendererCallback_FWD_DEFINED__ */


#ifndef __IWTSBitmapRenderService_FWD_DEFINED__
#define __IWTSBitmapRenderService_FWD_DEFINED__
typedef interface IWTSBitmapRenderService IWTSBitmapRenderService;

#endif 	/* __IWTSBitmapRenderService_FWD_DEFINED__ */


#ifndef __IWTSRemoteAppWindowInfoService_FWD_DEFINED__
#define __IWTSRemoteAppWindowInfoService_FWD_DEFINED__
typedef interface IWTSRemoteAppWindowInfoService IWTSRemoteAppWindowInfoService;

#endif 	/* __IWTSRemoteAppWindowInfoService_FWD_DEFINED__ */


#ifndef __IWTSWindowChangedCallback_FWD_DEFINED__
#define __IWTSWindowChangedCallback_FWD_DEFINED__
typedef interface IWTSWindowChangedCallback IWTSWindowChangedCallback;

#endif 	/* __IWTSWindowChangedCallback_FWD_DEFINED__ */


#ifndef __IWTSWindowInfoService_FWD_DEFINED__
#define __IWTSWindowInfoService_FWD_DEFINED__
typedef interface IWTSWindowInfoService IWTSWindowInfoService;

#endif 	/* __IWTSWindowInfoService_FWD_DEFINED__ */


/* header files for imported files */
#include "unknwn.h"
#include "oaidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_tsvirtualchannels_0000_0000 */
/* [local] */ 

#include <winapifamily.h>
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)






#define  WTS_PROPERTY_DEFAULT_CONFIG  L"DefaultConfig"
#define E_MAPPEDRENDERER_SHUTDOWN    HRESULT_FROM_WIN32(ERROR_INVALID_STATE)
#define E_DUPLICATE_WINDOW_HINT      HRESULT_FROM_WIN32(ERROR_ALREADY_EXISTS)
EXTERN_C __declspec(selectany) const IID IID_IWTSPlugin = {0xA1230201, 0x1439, 0x4e62, { 0xa4, 0x14, 0x19, 0x0d, 0x0a, 0xc3, 0xd4, 0x0e}};


extern RPC_IF_HANDLE __MIDL_itf_tsvirtualchannels_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_tsvirtualchannels_0000_0000_v0_0_s_ifspec;

#ifndef __IWTSPlugin_INTERFACE_DEFINED__
#define __IWTSPlugin_INTERFACE_DEFINED__

/* interface IWTSPlugin */
/* [helpstring][oleautomation][uuid][object] */ 


EXTERN_C const IID IID_IWTSPlugin;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A1230201-1439-4e62-a414-190d0ac3d40e")
    IWTSPlugin : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Initialize( 
            /* [annotation][in] */ 
            _In_  IWTSVirtualChannelManager *pChannelMgr) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Connected( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Disconnected( 
            DWORD dwDisconnectCode) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Terminated( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWTSPluginVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IWTSPlugin * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IWTSPlugin * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IWTSPlugin * This);
        
        DECLSPEC_XFGVIRT(IWTSPlugin, Initialize)
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            __RPC__in IWTSPlugin * This,
            /* [annotation][in] */ 
            _In_  IWTSVirtualChannelManager *pChannelMgr);
        
        DECLSPEC_XFGVIRT(IWTSPlugin, Connected)
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Connected )( 
            __RPC__in IWTSPlugin * This);
        
        DECLSPEC_XFGVIRT(IWTSPlugin, Disconnected)
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Disconnected )( 
            __RPC__in IWTSPlugin * This,
            DWORD dwDisconnectCode);
        
        DECLSPEC_XFGVIRT(IWTSPlugin, Terminated)
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Terminated )( 
            __RPC__in IWTSPlugin * This);
        
        END_INTERFACE
    } IWTSPluginVtbl;

    interface IWTSPlugin
    {
        CONST_VTBL struct IWTSPluginVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWTSPlugin_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWTSPlugin_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWTSPlugin_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWTSPlugin_Initialize(This,pChannelMgr)	\
    ( (This)->lpVtbl -> Initialize(This,pChannelMgr) ) 

#define IWTSPlugin_Connected(This)	\
    ( (This)->lpVtbl -> Connected(This) ) 

#define IWTSPlugin_Disconnected(This,dwDisconnectCode)	\
    ( (This)->lpVtbl -> Disconnected(This,dwDisconnectCode) ) 

#define IWTSPlugin_Terminated(This)	\
    ( (This)->lpVtbl -> Terminated(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWTSPlugin_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_tsvirtualchannels_0000_0001 */
/* [local] */ 

EXTERN_C __declspec(selectany) const IID IID_IWTSListener = {0xA1230206, 0x9a39, 0x4d58, {0x86, 0x74, 0xcd, 0xb4, 0xdf, 0xf4, 0xe7, 0x3b}};


extern RPC_IF_HANDLE __MIDL_itf_tsvirtualchannels_0000_0001_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_tsvirtualchannels_0000_0001_v0_0_s_ifspec;

#ifndef __IWTSListener_INTERFACE_DEFINED__
#define __IWTSListener_INTERFACE_DEFINED__

/* interface IWTSListener */
/* [helpstring][oleautomation][uuid][object] */ 


EXTERN_C const IID IID_IWTSListener;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A1230206-9a39-4d58-8674-cdb4dff4e73b")
    IWTSListener : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetConfiguration( 
            /* [annotation][out] */ 
            _Out_  IPropertyBag **ppPropertyBag) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWTSListenerVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IWTSListener * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IWTSListener * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IWTSListener * This);
        
        DECLSPEC_XFGVIRT(IWTSListener, GetConfiguration)
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetConfiguration )( 
            __RPC__in IWTSListener * This,
            /* [annotation][out] */ 
            _Out_  IPropertyBag **ppPropertyBag);
        
        END_INTERFACE
    } IWTSListenerVtbl;

    interface IWTSListener
    {
        CONST_VTBL struct IWTSListenerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWTSListener_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWTSListener_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWTSListener_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWTSListener_GetConfiguration(This,ppPropertyBag)	\
    ( (This)->lpVtbl -> GetConfiguration(This,ppPropertyBag) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWTSListener_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_tsvirtualchannels_0000_0002 */
/* [local] */ 

EXTERN_C __declspec(selectany) const IID IID_IWTSListenerCallback = {0xA1230203, 0xd6a7, 0x11d8, {0xb9, 0xfd, 0x00, 0x0b, 0xdb, 0xd1, 0xf1, 0x98}};


extern RPC_IF_HANDLE __MIDL_itf_tsvirtualchannels_0000_0002_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_tsvirtualchannels_0000_0002_v0_0_s_ifspec;

#ifndef __IWTSListenerCallback_INTERFACE_DEFINED__
#define __IWTSListenerCallback_INTERFACE_DEFINED__

/* interface IWTSListenerCallback */
/* [helpstring][oleautomation][uuid][object] */ 


EXTERN_C const IID IID_IWTSListenerCallback;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A1230203-d6a7-11d8-b9fd-000bdbd1f198")
    IWTSListenerCallback : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnNewChannelConnection( 
            /* [annotation][in] */ 
            _In_  IWTSVirtualChannel *pChannel,
            /* [full][in] */ __RPC__in_opt BSTR data,
            /* [annotation][out] */ 
            _Out_  BOOL *pbAccept,
            /* [annotation][out] */ 
            _Out_  IWTSVirtualChannelCallback **ppCallback) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWTSListenerCallbackVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IWTSListenerCallback * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IWTSListenerCallback * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IWTSListenerCallback * This);
        
        DECLSPEC_XFGVIRT(IWTSListenerCallback, OnNewChannelConnection)
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *OnNewChannelConnection )( 
            __RPC__in IWTSListenerCallback * This,
            /* [annotation][in] */ 
            _In_  IWTSVirtualChannel *pChannel,
            /* [full][in] */ __RPC__in_opt BSTR data,
            /* [annotation][out] */ 
            _Out_  BOOL *pbAccept,
            /* [annotation][out] */ 
            _Out_  IWTSVirtualChannelCallback **ppCallback);
        
        END_INTERFACE
    } IWTSListenerCallbackVtbl;

    interface IWTSListenerCallback
    {
        CONST_VTBL struct IWTSListenerCallbackVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWTSListenerCallback_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWTSListenerCallback_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWTSListenerCallback_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWTSListenerCallback_OnNewChannelConnection(This,pChannel,data,pbAccept,ppCallback)	\
    ( (This)->lpVtbl -> OnNewChannelConnection(This,pChannel,data,pbAccept,ppCallback) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWTSListenerCallback_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_tsvirtualchannels_0000_0003 */
/* [local] */ 

EXTERN_C __declspec(selectany) const IID IID_IWTSVirtualChannelCallback = {0xA1230204, 0xd6a7, 0x11d8, {0xb9, 0xfd, 0x00, 0x0b, 0xdb, 0xd1, 0xf1, 0x98}};


extern RPC_IF_HANDLE __MIDL_itf_tsvirtualchannels_0000_0003_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_tsvirtualchannels_0000_0003_v0_0_s_ifspec;

#ifndef __IWTSVirtualChannelCallback_INTERFACE_DEFINED__
#define __IWTSVirtualChannelCallback_INTERFACE_DEFINED__

/* interface IWTSVirtualChannelCallback */
/* [helpstring][oleautomation][uuid][object] */ 


EXTERN_C const IID IID_IWTSVirtualChannelCallback;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A1230204-d6a7-11d8-b9fd-000bdbd1f198")
    IWTSVirtualChannelCallback : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnDataReceived( 
            /* [annotation][in] */ 
            _In_  ULONG cbSize,
            /* [annotation][size_is][in] */ 
            _In_reads_(cbSize)  BYTE *pBuffer) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnClose( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWTSVirtualChannelCallbackVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IWTSVirtualChannelCallback * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IWTSVirtualChannelCallback * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IWTSVirtualChannelCallback * This);
        
        DECLSPEC_XFGVIRT(IWTSVirtualChannelCallback, OnDataReceived)
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *OnDataReceived )( 
            __RPC__in IWTSVirtualChannelCallback * This,
            /* [annotation][in] */ 
            _In_  ULONG cbSize,
            /* [annotation][size_is][in] */ 
            _In_reads_(cbSize)  BYTE *pBuffer);
        
        DECLSPEC_XFGVIRT(IWTSVirtualChannelCallback, OnClose)
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *OnClose )( 
            __RPC__in IWTSVirtualChannelCallback * This);
        
        END_INTERFACE
    } IWTSVirtualChannelCallbackVtbl;

    interface IWTSVirtualChannelCallback
    {
        CONST_VTBL struct IWTSVirtualChannelCallbackVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWTSVirtualChannelCallback_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWTSVirtualChannelCallback_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWTSVirtualChannelCallback_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWTSVirtualChannelCallback_OnDataReceived(This,cbSize,pBuffer)	\
    ( (This)->lpVtbl -> OnDataReceived(This,cbSize,pBuffer) ) 

#define IWTSVirtualChannelCallback_OnClose(This)	\
    ( (This)->lpVtbl -> OnClose(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWTSVirtualChannelCallback_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_tsvirtualchannels_0000_0004 */
/* [local] */ 

EXTERN_C __declspec(selectany) const IID IID_IWTSVirtualChannelManager = {0xA1230205,0xd6a7,0x11d8,{0xb9,0xfd,0x00,0x0b,0xdb,0xd1,0xf1,0x98}};
#define  TS_VC_LISTENER_STATIC_CHANNEL   0x00000001


extern RPC_IF_HANDLE __MIDL_itf_tsvirtualchannels_0000_0004_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_tsvirtualchannels_0000_0004_v0_0_s_ifspec;

#ifndef __IWTSVirtualChannelManager_INTERFACE_DEFINED__
#define __IWTSVirtualChannelManager_INTERFACE_DEFINED__

/* interface IWTSVirtualChannelManager */
/* [helpstring][oleautomation][uuid][object] */ 


EXTERN_C const IID IID_IWTSVirtualChannelManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A1230205-d6a7-11d8-b9fd-000bdbd1f198")
    IWTSVirtualChannelManager : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CreateListener( 
            /* [annotation][string][in] */ 
            _In_  const unsigned char *pszChannelName,
            /* [annotation][in] */ 
            _In_  ULONG uFlags,
            /* [annotation][in] */ 
            _In_  IWTSListenerCallback *pListenerCallback,
            /* [annotation][out] */ 
            _Out_  IWTSListener **ppListener) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWTSVirtualChannelManagerVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IWTSVirtualChannelManager * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IWTSVirtualChannelManager * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IWTSVirtualChannelManager * This);
        
        DECLSPEC_XFGVIRT(IWTSVirtualChannelManager, CreateListener)
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CreateListener )( 
            __RPC__in IWTSVirtualChannelManager * This,
            /* [annotation][string][in] */ 
            _In_  const unsigned char *pszChannelName,
            /* [annotation][in] */ 
            _In_  ULONG uFlags,
            /* [annotation][in] */ 
            _In_  IWTSListenerCallback *pListenerCallback,
            /* [annotation][out] */ 
            _Out_  IWTSListener **ppListener);
        
        END_INTERFACE
    } IWTSVirtualChannelManagerVtbl;

    interface IWTSVirtualChannelManager
    {
        CONST_VTBL struct IWTSVirtualChannelManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWTSVirtualChannelManager_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWTSVirtualChannelManager_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWTSVirtualChannelManager_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWTSVirtualChannelManager_CreateListener(This,pszChannelName,uFlags,pListenerCallback,ppListener)	\
    ( (This)->lpVtbl -> CreateListener(This,pszChannelName,uFlags,pListenerCallback,ppListener) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWTSVirtualChannelManager_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_tsvirtualchannels_0000_0005 */
/* [local] */ 

EXTERN_C __declspec(selectany) const IID IID_IWTSVirtualChannel = { 0xA1230207, 0xd6a7, 0x11d8, { 0xb9, 0xfd, 0x00, 0x0b, 0xdb, 0xd1, 0xf1, 0x98} };


extern RPC_IF_HANDLE __MIDL_itf_tsvirtualchannels_0000_0005_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_tsvirtualchannels_0000_0005_v0_0_s_ifspec;

#ifndef __IWTSVirtualChannel_INTERFACE_DEFINED__
#define __IWTSVirtualChannel_INTERFACE_DEFINED__

/* interface IWTSVirtualChannel */
/* [helpstring][oleautomation][uuid][object] */ 


EXTERN_C const IID IID_IWTSVirtualChannel;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A1230207-d6a7-11d8-b9fd-000bdbd1f198")
    IWTSVirtualChannel : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Write( 
            /* [annotation][in] */ 
            _In_  ULONG cbSize,
            /* [annotation][size_is][in] */ 
            _In_reads_(cbSize)  BYTE *pBuffer,
            /* [annotation][in] */ 
            _In_  IUnknown *pReserved) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Close( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWTSVirtualChannelVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IWTSVirtualChannel * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IWTSVirtualChannel * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IWTSVirtualChannel * This);
        
        DECLSPEC_XFGVIRT(IWTSVirtualChannel, Write)
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Write )( 
            __RPC__in IWTSVirtualChannel * This,
            /* [annotation][in] */ 
            _In_  ULONG cbSize,
            /* [annotation][size_is][in] */ 
            _In_reads_(cbSize)  BYTE *pBuffer,
            /* [annotation][in] */ 
            _In_  IUnknown *pReserved);
        
        DECLSPEC_XFGVIRT(IWTSVirtualChannel, Close)
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Close )( 
            __RPC__in IWTSVirtualChannel * This);
        
        END_INTERFACE
    } IWTSVirtualChannelVtbl;

    interface IWTSVirtualChannel
    {
        CONST_VTBL struct IWTSVirtualChannelVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWTSVirtualChannel_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWTSVirtualChannel_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWTSVirtualChannel_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWTSVirtualChannel_Write(This,cbSize,pBuffer,pReserved)	\
    ( (This)->lpVtbl -> Write(This,cbSize,pBuffer,pReserved) ) 

#define IWTSVirtualChannel_Close(This)	\
    ( (This)->lpVtbl -> Close(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWTSVirtualChannel_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_tsvirtualchannels_0000_0006 */
/* [local] */ 

EXTERN_GUID( RDCLIENT_BITMAP_RENDER_SERVICE, 0xe4cc08cb, 0x942e, 0x4b19, 0x85, 0x4, 0xbd, 0x5a, 0x89, 0xa7, 0x47, 0xf5);
EXTERN_GUID( RDCLIENT_REMOTE_APP_WINDOW_INFO_SERVICE, 0x10d23864, 0xcfa3, 0x447b, 0x89, 0x9f, 0x3f, 0xcf, 0x69, 0x80, 0x81, 0x2a);
EXTERN_GUID( RDCLIENT_WINDOW_INFO_SERVICE, 0xa9a17a6b, 0xcdb3, 0x4e81, 0xb5, 0xc8, 0xbd, 0x63, 0x82, 0x2a, 0x8d, 0x6c);
EXTERN_C __declspec(selectany) const IID IID_IWTSPluginServiceProvider = { 0xd3e07363, 0x87c, 0x476c, { 0x86, 0xa7, 0xdb, 0xb1, 0x5f, 0x46, 0xdd, 0xb4 } };


extern RPC_IF_HANDLE __MIDL_itf_tsvirtualchannels_0000_0006_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_tsvirtualchannels_0000_0006_v0_0_s_ifspec;

#ifndef __IWTSPluginServiceProvider_INTERFACE_DEFINED__
#define __IWTSPluginServiceProvider_INTERFACE_DEFINED__

/* interface IWTSPluginServiceProvider */
/* [helpstring][oleautomation][uuid][object] */ 


EXTERN_C const IID IID_IWTSPluginServiceProvider;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D3E07363-087C-476C-86A7-DBB15F46DDB4")
    IWTSPluginServiceProvider : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetService( 
            /* [annotation][in] */ 
            _In_  GUID ServiceId,
            /* [annotation][out] */ 
            _Out_  IUnknown **ppunkObject) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWTSPluginServiceProviderVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IWTSPluginServiceProvider * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IWTSPluginServiceProvider * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IWTSPluginServiceProvider * This);
        
        DECLSPEC_XFGVIRT(IWTSPluginServiceProvider, GetService)
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetService )( 
            __RPC__in IWTSPluginServiceProvider * This,
            /* [annotation][in] */ 
            _In_  GUID ServiceId,
            /* [annotation][out] */ 
            _Out_  IUnknown **ppunkObject);
        
        END_INTERFACE
    } IWTSPluginServiceProviderVtbl;

    interface IWTSPluginServiceProvider
    {
        CONST_VTBL struct IWTSPluginServiceProviderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWTSPluginServiceProvider_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWTSPluginServiceProvider_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWTSPluginServiceProvider_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWTSPluginServiceProvider_GetService(This,ServiceId,ppunkObject)	\
    ( (This)->lpVtbl -> GetService(This,ServiceId,ppunkObject) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWTSPluginServiceProvider_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_tsvirtualchannels_0000_0007 */
/* [local] */ 

typedef struct __BITMAP_RENDERER_STATISTICS
    {
    DWORD dwFramesDelivered;
    DWORD dwFramesDropped;
    } 	BITMAP_RENDERER_STATISTICS;

typedef struct __BITMAP_RENDERER_STATISTICS *PBITMAP_RENDERER_STATISTICS;

EXTERN_C __declspec(selectany) const IID IID_IWTSBitmapRenderer = { 0x5b7acc97, 0xf3c9, 0x46f7, { 0x8c, 0x5b, 0xfa, 0x68, 0x5d, 0x34, 0x41, 0xb1 } };


extern RPC_IF_HANDLE __MIDL_itf_tsvirtualchannels_0000_0007_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_tsvirtualchannels_0000_0007_v0_0_s_ifspec;

#ifndef __IWTSBitmapRenderer_INTERFACE_DEFINED__
#define __IWTSBitmapRenderer_INTERFACE_DEFINED__

/* interface IWTSBitmapRenderer */
/* [helpstring][oleautomation][uuid][object] */ 


EXTERN_C const IID IID_IWTSBitmapRenderer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5B7ACC97-F3C9-46F7-8C5B-FA685D3441B1")
    IWTSBitmapRenderer : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Render( 
            /* [annotation][in] */ 
            _In_  GUID imageFormat,
            /* [annotation][in] */ 
            _In_  DWORD dwWidth,
            /* [annotation][in] */ 
            _In_  DWORD dwHeight,
            /* [annotation][in] */ 
            _In_  LONG cbStride,
            /* [annotation][in] */ 
            _In_  DWORD cbImageBuffer,
            /* [annotation][size_is][in] */ 
            _In_reads_(cbImageBuffer)  BYTE *pImageBuffer) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetRendererStatistics( 
            /* [annotation][out] */ 
            _Out_  BITMAP_RENDERER_STATISTICS *pStatistics) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RemoveMapping( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWTSBitmapRendererVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IWTSBitmapRenderer * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IWTSBitmapRenderer * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IWTSBitmapRenderer * This);
        
        DECLSPEC_XFGVIRT(IWTSBitmapRenderer, Render)
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Render )( 
            __RPC__in IWTSBitmapRenderer * This,
            /* [annotation][in] */ 
            _In_  GUID imageFormat,
            /* [annotation][in] */ 
            _In_  DWORD dwWidth,
            /* [annotation][in] */ 
            _In_  DWORD dwHeight,
            /* [annotation][in] */ 
            _In_  LONG cbStride,
            /* [annotation][in] */ 
            _In_  DWORD cbImageBuffer,
            /* [annotation][size_is][in] */ 
            _In_reads_(cbImageBuffer)  BYTE *pImageBuffer);
        
        DECLSPEC_XFGVIRT(IWTSBitmapRenderer, GetRendererStatistics)
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetRendererStatistics )( 
            __RPC__in IWTSBitmapRenderer * This,
            /* [annotation][out] */ 
            _Out_  BITMAP_RENDERER_STATISTICS *pStatistics);
        
        DECLSPEC_XFGVIRT(IWTSBitmapRenderer, RemoveMapping)
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *RemoveMapping )( 
            __RPC__in IWTSBitmapRenderer * This);
        
        END_INTERFACE
    } IWTSBitmapRendererVtbl;

    interface IWTSBitmapRenderer
    {
        CONST_VTBL struct IWTSBitmapRendererVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWTSBitmapRenderer_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWTSBitmapRenderer_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWTSBitmapRenderer_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWTSBitmapRenderer_Render(This,imageFormat,dwWidth,dwHeight,cbStride,cbImageBuffer,pImageBuffer)	\
    ( (This)->lpVtbl -> Render(This,imageFormat,dwWidth,dwHeight,cbStride,cbImageBuffer,pImageBuffer) ) 

#define IWTSBitmapRenderer_GetRendererStatistics(This,pStatistics)	\
    ( (This)->lpVtbl -> GetRendererStatistics(This,pStatistics) ) 

#define IWTSBitmapRenderer_RemoveMapping(This)	\
    ( (This)->lpVtbl -> RemoveMapping(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWTSBitmapRenderer_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_tsvirtualchannels_0000_0008 */
/* [local] */ 

EXTERN_C __declspec(selectany) const IID IID_IWTSBitmapRendererCallback = { 0xd782928e, 0xfe4e, 0x4e77, { 0xae, 0x90, 0x9c, 0xd0, 0xb3, 0xe3, 0xb3, 0x53 } };


extern RPC_IF_HANDLE __MIDL_itf_tsvirtualchannels_0000_0008_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_tsvirtualchannels_0000_0008_v0_0_s_ifspec;

#ifndef __IWTSBitmapRendererCallback_INTERFACE_DEFINED__
#define __IWTSBitmapRendererCallback_INTERFACE_DEFINED__

/* interface IWTSBitmapRendererCallback */
/* [helpstring][oleautomation][uuid][object] */ 


EXTERN_C const IID IID_IWTSBitmapRendererCallback;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D782928E-FE4E-4E77-AE90-9CD0B3E3B353")
    IWTSBitmapRendererCallback : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnTargetSizeChanged( 
            /* [annotation][in] */ 
            _In_  RECT rcNewSize) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWTSBitmapRendererCallbackVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IWTSBitmapRendererCallback * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IWTSBitmapRendererCallback * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IWTSBitmapRendererCallback * This);
        
        DECLSPEC_XFGVIRT(IWTSBitmapRendererCallback, OnTargetSizeChanged)
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *OnTargetSizeChanged )( 
            __RPC__in IWTSBitmapRendererCallback * This,
            /* [annotation][in] */ 
            _In_  RECT rcNewSize);
        
        END_INTERFACE
    } IWTSBitmapRendererCallbackVtbl;

    interface IWTSBitmapRendererCallback
    {
        CONST_VTBL struct IWTSBitmapRendererCallbackVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWTSBitmapRendererCallback_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWTSBitmapRendererCallback_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWTSBitmapRendererCallback_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWTSBitmapRendererCallback_OnTargetSizeChanged(This,rcNewSize)	\
    ( (This)->lpVtbl -> OnTargetSizeChanged(This,rcNewSize) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWTSBitmapRendererCallback_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_tsvirtualchannels_0000_0009 */
/* [local] */ 

EXTERN_C __declspec(selectany) const IID IID_IWTSBitmapRenderService = { 0xea326091, 0x5fe, 0x40c1, { 0xb4, 0x9c, 0x3d, 0x2e, 0xf4, 0x62, 0x6a, 0xe } };


extern RPC_IF_HANDLE __MIDL_itf_tsvirtualchannels_0000_0009_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_tsvirtualchannels_0000_0009_v0_0_s_ifspec;

#ifndef __IWTSBitmapRenderService_INTERFACE_DEFINED__
#define __IWTSBitmapRenderService_INTERFACE_DEFINED__

/* interface IWTSBitmapRenderService */
/* [helpstring][oleautomation][uuid][object] */ 


EXTERN_C const IID IID_IWTSBitmapRenderService;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("EA326091-05FE-40C1-B49C-3D2EF4626A0E")
    IWTSBitmapRenderService : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetMappedRenderer( 
            /* [annotation][in] */ 
            _In_  UINT64 mappingId,
            /* [annotation][in] */ 
            _In_  IWTSBitmapRendererCallback *pMappedRendererCallback,
            /* [annotation][out] */ 
            _Out_  IWTSBitmapRenderer **ppMappedRenderer) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWTSBitmapRenderServiceVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IWTSBitmapRenderService * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IWTSBitmapRenderService * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IWTSBitmapRenderService * This);
        
        DECLSPEC_XFGVIRT(IWTSBitmapRenderService, GetMappedRenderer)
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetMappedRenderer )( 
            __RPC__in IWTSBitmapRenderService * This,
            /* [annotation][in] */ 
            _In_  UINT64 mappingId,
            /* [annotation][in] */ 
            _In_  IWTSBitmapRendererCallback *pMappedRendererCallback,
            /* [annotation][out] */ 
            _Out_  IWTSBitmapRenderer **ppMappedRenderer);
        
        END_INTERFACE
    } IWTSBitmapRenderServiceVtbl;

    interface IWTSBitmapRenderService
    {
        CONST_VTBL struct IWTSBitmapRenderServiceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWTSBitmapRenderService_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWTSBitmapRenderService_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWTSBitmapRenderService_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWTSBitmapRenderService_GetMappedRenderer(This,mappingId,pMappedRendererCallback,ppMappedRenderer)	\
    ( (This)->lpVtbl -> GetMappedRenderer(This,mappingId,pMappedRendererCallback,ppMappedRenderer) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWTSBitmapRenderService_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_tsvirtualchannels_0000_0010 */
/* [local] */ 

EXTERN_C __declspec(selectany) const IID IID_IWTSRemoteAppWindowInfoService = { 0x3869f11a, 0xde41, 0x427f, { 0x80, 0x28, 0x2d, 0x15, 0xd2, 0xec, 0x94, 0x98 } };


extern RPC_IF_HANDLE __MIDL_itf_tsvirtualchannels_0000_0010_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_tsvirtualchannels_0000_0010_v0_0_s_ifspec;

#ifndef __IWTSRemoteAppWindowInfoService_INTERFACE_DEFINED__
#define __IWTSRemoteAppWindowInfoService_INTERFACE_DEFINED__

/* interface IWTSRemoteAppWindowInfoService */
/* [helpstring][oleautomation][uuid][object] */ 


EXTERN_C const IID IID_IWTSRemoteAppWindowInfoService;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3869F11A-DE41-427F-8028-2D15D2EC9498")
    IWTSRemoteAppWindowInfoService : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetLocalHwnd( 
            /* [annotation][in] */ 
            _In_  unsigned int remoteWindowId,
            /* [annotation][retval][out] */ 
            _Out_retval_  HWND *localHwnd) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWTSRemoteAppWindowInfoServiceVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IWTSRemoteAppWindowInfoService * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IWTSRemoteAppWindowInfoService * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IWTSRemoteAppWindowInfoService * This);
        
        DECLSPEC_XFGVIRT(IWTSRemoteAppWindowInfoService, GetLocalHwnd)
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetLocalHwnd )( 
            __RPC__in IWTSRemoteAppWindowInfoService * This,
            /* [annotation][in] */ 
            _In_  unsigned int remoteWindowId,
            /* [annotation][retval][out] */ 
            _Out_retval_  HWND *localHwnd);
        
        END_INTERFACE
    } IWTSRemoteAppWindowInfoServiceVtbl;

    interface IWTSRemoteAppWindowInfoService
    {
        CONST_VTBL struct IWTSRemoteAppWindowInfoServiceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWTSRemoteAppWindowInfoService_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWTSRemoteAppWindowInfoService_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWTSRemoteAppWindowInfoService_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWTSRemoteAppWindowInfoService_GetLocalHwnd(This,remoteWindowId,localHwnd)	\
    ( (This)->lpVtbl -> GetLocalHwnd(This,remoteWindowId,localHwnd) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWTSRemoteAppWindowInfoService_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_tsvirtualchannels_0000_0011 */
/* [local] */ 

typedef 
enum RdpSessionType
    {
        Desktop	= 0,
        RemoteApp	= 1
    } 	RdpSessionType;

typedef struct WTSWindowInfo
    {
    HWND Hwnd;
    int Height;
    int Width;
    int ViewWidth;
    int ViewHeight;
    int ViewOffsetX;
    int ViewOffsetY;
    float Scale;
    } 	WTSWindowInfo;

EXTERN_C __declspec(selectany) const IID IID_IWTSWindowChangedCallback = { 0xe8a47fd3, 0x1af5, 0x4d7f, { 0x8e, 0x15, 0x51, 0x5c, 0xca, 0xe1, 0xc0, 0x0c } };


extern RPC_IF_HANDLE __MIDL_itf_tsvirtualchannels_0000_0011_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_tsvirtualchannels_0000_0011_v0_0_s_ifspec;

#ifndef __IWTSWindowChangedCallback_INTERFACE_DEFINED__
#define __IWTSWindowChangedCallback_INTERFACE_DEFINED__

/* interface IWTSWindowChangedCallback */
/* [helpstring][oleautomation][uuid][object] */ 


EXTERN_C const IID IID_IWTSWindowChangedCallback;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E8A47FD3-1AF6-4D7F-8E15-515CCAE1C00C")
    IWTSWindowChangedCallback : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE WindowChanged( 
            /* [annotation][in] */ 
            _In_  const WTSWindowInfo *windowInfo) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWTSWindowChangedCallbackVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IWTSWindowChangedCallback * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IWTSWindowChangedCallback * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IWTSWindowChangedCallback * This);
        
        DECLSPEC_XFGVIRT(IWTSWindowChangedCallback, WindowChanged)
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *WindowChanged )( 
            __RPC__in IWTSWindowChangedCallback * This,
            /* [annotation][in] */ 
            _In_  const WTSWindowInfo *windowInfo);
        
        END_INTERFACE
    } IWTSWindowChangedCallbackVtbl;

    interface IWTSWindowChangedCallback
    {
        CONST_VTBL struct IWTSWindowChangedCallbackVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWTSWindowChangedCallback_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWTSWindowChangedCallback_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWTSWindowChangedCallback_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWTSWindowChangedCallback_WindowChanged(This,windowInfo)	\
    ( (This)->lpVtbl -> WindowChanged(This,windowInfo) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWTSWindowChangedCallback_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_tsvirtualchannels_0000_0012 */
/* [local] */ 

EXTERN_C __declspec(selectany) const IID IID_IWTSWindowInfoService = { 0x2a002c7b, 0x0120, 0x4d04, { 0xbf, 0xb1, 0x3c, 0x73, 0x11, 0x0c, 0x85, 0x81 } };


extern RPC_IF_HANDLE __MIDL_itf_tsvirtualchannels_0000_0012_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_tsvirtualchannels_0000_0012_v0_0_s_ifspec;

#ifndef __IWTSWindowInfoService_INTERFACE_DEFINED__
#define __IWTSWindowInfoService_INTERFACE_DEFINED__

/* interface IWTSWindowInfoService */
/* [helpstring][oleautomation][uuid][object] */ 


EXTERN_C const IID IID_IWTSWindowInfoService;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2A002C7B-0120-4D04-BFB1-3C73110C8581")
    IWTSWindowInfoService : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetWindowInfo( 
            /* [annotation][in] */ 
            _In_  HWND remoteHwnd,
            /* [annotation][out] */ 
            _Out_  WTSWindowInfo *windowInfo) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetRdpClientProcessId( 
            /* [annotation][retval][out] */ 
            _Out_retval_  unsigned long *processId) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetRdpSessionType( 
            /* [annotation][retval][out] */ 
            _Out_retval_  RdpSessionType *sessionType) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SubscribeWindowChanged( 
            /* [annotation][in] */ 
            _In_  HWND remoteHwnd,
            /* [annotation][in] */ 
            _In_  IWTSWindowChangedCallback *windowChanged) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE UnsubscribeWindowChanged( 
            /* [annotation][in] */ 
            _In_  HWND remoteHwnd,
            /* [annotation][in] */ 
            _In_  IWTSWindowChangedCallback *windowChanged) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWTSWindowInfoServiceVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IWTSWindowInfoService * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IWTSWindowInfoService * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IWTSWindowInfoService * This);
        
        DECLSPEC_XFGVIRT(IWTSWindowInfoService, GetWindowInfo)
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetWindowInfo )( 
            __RPC__in IWTSWindowInfoService * This,
            /* [annotation][in] */ 
            _In_  HWND remoteHwnd,
            /* [annotation][out] */ 
            _Out_  WTSWindowInfo *windowInfo);
        
        DECLSPEC_XFGVIRT(IWTSWindowInfoService, GetRdpClientProcessId)
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetRdpClientProcessId )( 
            __RPC__in IWTSWindowInfoService * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  unsigned long *processId);
        
        DECLSPEC_XFGVIRT(IWTSWindowInfoService, GetRdpSessionType)
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetRdpSessionType )( 
            __RPC__in IWTSWindowInfoService * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  RdpSessionType *sessionType);
        
        DECLSPEC_XFGVIRT(IWTSWindowInfoService, SubscribeWindowChanged)
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SubscribeWindowChanged )( 
            __RPC__in IWTSWindowInfoService * This,
            /* [annotation][in] */ 
            _In_  HWND remoteHwnd,
            /* [annotation][in] */ 
            _In_  IWTSWindowChangedCallback *windowChanged);
        
        DECLSPEC_XFGVIRT(IWTSWindowInfoService, UnsubscribeWindowChanged)
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *UnsubscribeWindowChanged )( 
            __RPC__in IWTSWindowInfoService * This,
            /* [annotation][in] */ 
            _In_  HWND remoteHwnd,
            /* [annotation][in] */ 
            _In_  IWTSWindowChangedCallback *windowChanged);
        
        END_INTERFACE
    } IWTSWindowInfoServiceVtbl;

    interface IWTSWindowInfoService
    {
        CONST_VTBL struct IWTSWindowInfoServiceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWTSWindowInfoService_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWTSWindowInfoService_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWTSWindowInfoService_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWTSWindowInfoService_GetWindowInfo(This,remoteHwnd,windowInfo)	\
    ( (This)->lpVtbl -> GetWindowInfo(This,remoteHwnd,windowInfo) ) 

#define IWTSWindowInfoService_GetRdpClientProcessId(This,processId)	\
    ( (This)->lpVtbl -> GetRdpClientProcessId(This,processId) ) 

#define IWTSWindowInfoService_GetRdpSessionType(This,sessionType)	\
    ( (This)->lpVtbl -> GetRdpSessionType(This,sessionType) ) 

#define IWTSWindowInfoService_SubscribeWindowChanged(This,remoteHwnd,windowChanged)	\
    ( (This)->lpVtbl -> SubscribeWindowChanged(This,remoteHwnd,windowChanged) ) 

#define IWTSWindowInfoService_UnsubscribeWindowChanged(This,remoteHwnd,windowChanged)	\
    ( (This)->lpVtbl -> UnsubscribeWindowChanged(This,remoteHwnd,windowChanged) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWTSWindowInfoService_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_tsvirtualchannels_0000_0013 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_tsvirtualchannels_0000_0013_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_tsvirtualchannels_0000_0013_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     __RPC__in unsigned long *, unsigned long            , __RPC__in BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     __RPC__in unsigned long *, __RPC__in BSTR * ); 

unsigned long             __RPC_USER  HWND_UserSize(     __RPC__in unsigned long *, unsigned long            , __RPC__in HWND * ); 
unsigned char * __RPC_USER  HWND_UserMarshal(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in HWND * ); 
unsigned char * __RPC_USER  HWND_UserUnmarshal(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out HWND * ); 
void                      __RPC_USER  HWND_UserFree(     __RPC__in unsigned long *, __RPC__in HWND * ); 

unsigned long             __RPC_USER  BSTR_UserSize64(     __RPC__in unsigned long *, unsigned long            , __RPC__in BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal64(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal64(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out BSTR * ); 
void                      __RPC_USER  BSTR_UserFree64(     __RPC__in unsigned long *, __RPC__in BSTR * ); 

unsigned long             __RPC_USER  HWND_UserSize64(     __RPC__in unsigned long *, unsigned long            , __RPC__in HWND * ); 
unsigned char * __RPC_USER  HWND_UserMarshal64(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in HWND * ); 
unsigned char * __RPC_USER  HWND_UserUnmarshal64(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out HWND * ); 
void                      __RPC_USER  HWND_UserFree64(     __RPC__in unsigned long *, __RPC__in HWND * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


