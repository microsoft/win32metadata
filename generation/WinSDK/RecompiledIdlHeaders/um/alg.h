

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

#ifndef __alg_h__
#define __alg_h__

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

#ifndef __IAdapterInfo_FWD_DEFINED__
#define __IAdapterInfo_FWD_DEFINED__
typedef interface IAdapterInfo IAdapterInfo;

#endif 	/* __IAdapterInfo_FWD_DEFINED__ */


#ifndef __IPendingProxyConnection_FWD_DEFINED__
#define __IPendingProxyConnection_FWD_DEFINED__
typedef interface IPendingProxyConnection IPendingProxyConnection;

#endif 	/* __IPendingProxyConnection_FWD_DEFINED__ */


#ifndef __IDataChannel_FWD_DEFINED__
#define __IDataChannel_FWD_DEFINED__
typedef interface IDataChannel IDataChannel;

#endif 	/* __IDataChannel_FWD_DEFINED__ */


#ifndef __IPersistentDataChannel_FWD_DEFINED__
#define __IPersistentDataChannel_FWD_DEFINED__
typedef interface IPersistentDataChannel IPersistentDataChannel;

#endif 	/* __IPersistentDataChannel_FWD_DEFINED__ */


#ifndef __IPrimaryControlChannel_FWD_DEFINED__
#define __IPrimaryControlChannel_FWD_DEFINED__
typedef interface IPrimaryControlChannel IPrimaryControlChannel;

#endif 	/* __IPrimaryControlChannel_FWD_DEFINED__ */


#ifndef __ISecondaryControlChannel_FWD_DEFINED__
#define __ISecondaryControlChannel_FWD_DEFINED__
typedef interface ISecondaryControlChannel ISecondaryControlChannel;

#endif 	/* __ISecondaryControlChannel_FWD_DEFINED__ */


#ifndef __IEnumAdapterInfo_FWD_DEFINED__
#define __IEnumAdapterInfo_FWD_DEFINED__
typedef interface IEnumAdapterInfo IEnumAdapterInfo;

#endif 	/* __IEnumAdapterInfo_FWD_DEFINED__ */


#ifndef __IAdapterNotificationSink_FWD_DEFINED__
#define __IAdapterNotificationSink_FWD_DEFINED__
typedef interface IAdapterNotificationSink IAdapterNotificationSink;

#endif 	/* __IAdapterNotificationSink_FWD_DEFINED__ */


#ifndef __IApplicationGatewayServices_FWD_DEFINED__
#define __IApplicationGatewayServices_FWD_DEFINED__
typedef interface IApplicationGatewayServices IApplicationGatewayServices;

#endif 	/* __IApplicationGatewayServices_FWD_DEFINED__ */


#ifndef __IApplicationGateway_FWD_DEFINED__
#define __IApplicationGateway_FWD_DEFINED__
typedef interface IApplicationGateway IApplicationGateway;

#endif 	/* __IApplicationGateway_FWD_DEFINED__ */


#ifndef __ApplicationGatewayServices_FWD_DEFINED__
#define __ApplicationGatewayServices_FWD_DEFINED__

#ifdef __cplusplus
typedef class ApplicationGatewayServices ApplicationGatewayServices;
#else
typedef struct ApplicationGatewayServices ApplicationGatewayServices;
#endif /* __cplusplus */

#endif 	/* __ApplicationGatewayServices_FWD_DEFINED__ */


#ifndef __PrimaryControlChannel_FWD_DEFINED__
#define __PrimaryControlChannel_FWD_DEFINED__

#ifdef __cplusplus
typedef class PrimaryControlChannel PrimaryControlChannel;
#else
typedef struct PrimaryControlChannel PrimaryControlChannel;
#endif /* __cplusplus */

#endif 	/* __PrimaryControlChannel_FWD_DEFINED__ */


#ifndef __SecondaryControlChannel_FWD_DEFINED__
#define __SecondaryControlChannel_FWD_DEFINED__

#ifdef __cplusplus
typedef class SecondaryControlChannel SecondaryControlChannel;
#else
typedef struct SecondaryControlChannel SecondaryControlChannel;
#endif /* __cplusplus */

#endif 	/* __SecondaryControlChannel_FWD_DEFINED__ */


#ifndef __AdapterInfo_FWD_DEFINED__
#define __AdapterInfo_FWD_DEFINED__

#ifdef __cplusplus
typedef class AdapterInfo AdapterInfo;
#else
typedef struct AdapterInfo AdapterInfo;
#endif /* __cplusplus */

#endif 	/* __AdapterInfo_FWD_DEFINED__ */


#ifndef __EnumAdapterInfo_FWD_DEFINED__
#define __EnumAdapterInfo_FWD_DEFINED__

#ifdef __cplusplus
typedef class EnumAdapterInfo EnumAdapterInfo;
#else
typedef struct EnumAdapterInfo EnumAdapterInfo;
#endif /* __cplusplus */

#endif 	/* __EnumAdapterInfo_FWD_DEFINED__ */


#ifndef __PendingProxyConnection_FWD_DEFINED__
#define __PendingProxyConnection_FWD_DEFINED__

#ifdef __cplusplus
typedef class PendingProxyConnection PendingProxyConnection;
#else
typedef struct PendingProxyConnection PendingProxyConnection;
#endif /* __cplusplus */

#endif 	/* __PendingProxyConnection_FWD_DEFINED__ */


#ifndef __DataChannel_FWD_DEFINED__
#define __DataChannel_FWD_DEFINED__

#ifdef __cplusplus
typedef class DataChannel DataChannel;
#else
typedef struct DataChannel DataChannel;
#endif /* __cplusplus */

#endif 	/* __DataChannel_FWD_DEFINED__ */


#ifndef __PersistentDataChannel_FWD_DEFINED__
#define __PersistentDataChannel_FWD_DEFINED__

#ifdef __cplusplus
typedef class PersistentDataChannel PersistentDataChannel;
#else
typedef struct PersistentDataChannel PersistentDataChannel;
#endif /* __cplusplus */

#endif 	/* __PersistentDataChannel_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_alg_0000_0000 */
/* [local] */ 

//+-------------------------------------------------------------------------
//
//  Microsoft Windows
//  Copyright (C) Microsoft Corporation, 1992-2001.
//
//--------------------------------------------------------------------------
//  MODULE: alg.h
//
#include <winapifamily.h>
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
#define	ALG_MAXIMUM_PORT_RANGE_SIZE	( 10 )

typedef 
enum _ALG_PROTOCOL
    {
        eALG_TCP	= 0x1,
        eALG_UDP	= 0x2
    } 	ALG_PROTOCOL;

typedef 
enum _ALG_CAPTURE
    {
        eALG_SOURCE_CAPTURE	= 0x1,
        eALG_DESTINATION_CAPTURE	= 0x2
    } 	ALG_CAPTURE;

typedef 
enum _ALG_DIRECTION
    {
        eALG_INBOUND	= 0x1,
        eALG_OUTBOUND	= 0x2,
        eALG_BOTH	= 0x3
    } 	ALG_DIRECTION;

typedef 
enum _ALG_ADAPTER_TYPE
    {
        eALG_PRIVATE	= 0x1,
        eALG_BOUNDARY	= 0x2,
        eALG_FIREWALLED	= 0x4
    } 	ALG_ADAPTER_TYPE;

typedef 
enum _ALG_NOTIFICATION
    {
        eALG_NONE	= 0,
        eALG_SESSION_CREATION	= 0x1,
        eALG_SESSION_DELETION	= 0x2,
        eALG_SESSION_BOTH	= 0x3
    } 	ALG_NOTIFICATION;

typedef struct _ALG_PRIMARY_CHANNEL_PROPERTIES
    {
    ALG_PROTOCOL eProtocol;
    USHORT usCapturePort;
    ALG_CAPTURE eCaptureType;
    BOOL fCaptureInbound;
    ULONG ulListeningAddress;
    USHORT usListeningPort;
    ULONG ulAdapterIndex;
    } 	ALG_PRIMARY_CHANNEL_PROPERTIES;

typedef struct _ALG_SECONDARY_CHANNEL_PROPERTIES
    {
    ALG_PROTOCOL eProtocol;
    ULONG ulPrivateAddress;
    USHORT usPrivatePort;
    ULONG ulPublicAddress;
    USHORT usPublicPort;
    ULONG ulRemoteAddress;
    USHORT usRemotePort;
    ULONG ulListenAddress;
    USHORT usListenPort;
    ALG_DIRECTION eDirection;
    BOOL fPersistent;
    } 	ALG_SECONDARY_CHANNEL_PROPERTIES;

typedef struct _ALG_DATA_CHANNEL_PROPERTIES
    {
    ALG_PROTOCOL eProtocol;
    ULONG ulPrivateAddress;
    USHORT usPrivatePort;
    ULONG ulPublicAddress;
    USHORT usPublicPort;
    ULONG ulRemoteAddress;
    USHORT usRemotePort;
    ALG_DIRECTION eDirection;
    ALG_NOTIFICATION eDesiredNotification;
    } 	ALG_DATA_CHANNEL_PROPERTIES;

typedef struct _ALG_PERSISTENT_DATA_CHANNEL_PROPERTIES
    {
    ALG_PROTOCOL eProtocol;
    ULONG ulPrivateAddress;
    USHORT usPrivatePort;
    ULONG ulPublicAddress;
    USHORT usPublicPort;
    ULONG ulRemoteAddress;
    USHORT usRemotePort;
    ALG_DIRECTION eDirection;
    } 	ALG_PERSISTENT_DATA_CHANNEL_PROPERTIES;



extern RPC_IF_HANDLE __MIDL_itf_alg_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_alg_0000_0000_v0_0_s_ifspec;

#ifndef __IAdapterInfo_INTERFACE_DEFINED__
#define __IAdapterInfo_INTERFACE_DEFINED__

/* interface IAdapterInfo */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IAdapterInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("480BF94A-09FD-4F8A-A3E0-B0700282D84D")
    IAdapterInfo : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetAdapterIndex( 
            /* [annotation][out] */ 
            _Out_  ULONG *pulIndex) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAdapterType( 
            /* [annotation][out] */ 
            _Out_  ALG_ADAPTER_TYPE *pAdapterType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAdapterAddresses( 
            /* [annotation][out] */ 
            _Out_  ULONG *pulAddressCount,
            /* [annotation][size_is][size_is][out] */ 
            _Out_writes_(*pulAddressCount)  ULONG **prgAddresses) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAdapterInfoVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IAdapterInfo * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IAdapterInfo * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IAdapterInfo * This);
        
        DECLSPEC_XFGVIRT(IAdapterInfo, GetAdapterIndex)
        HRESULT ( STDMETHODCALLTYPE *GetAdapterIndex )( 
            __RPC__in IAdapterInfo * This,
            /* [annotation][out] */ 
            _Out_  ULONG *pulIndex);
        
        DECLSPEC_XFGVIRT(IAdapterInfo, GetAdapterType)
        HRESULT ( STDMETHODCALLTYPE *GetAdapterType )( 
            __RPC__in IAdapterInfo * This,
            /* [annotation][out] */ 
            _Out_  ALG_ADAPTER_TYPE *pAdapterType);
        
        DECLSPEC_XFGVIRT(IAdapterInfo, GetAdapterAddresses)
        HRESULT ( STDMETHODCALLTYPE *GetAdapterAddresses )( 
            __RPC__in IAdapterInfo * This,
            /* [annotation][out] */ 
            _Out_  ULONG *pulAddressCount,
            /* [annotation][size_is][size_is][out] */ 
            _Out_writes_(*pulAddressCount)  ULONG **prgAddresses);
        
        END_INTERFACE
    } IAdapterInfoVtbl;

    interface IAdapterInfo
    {
        CONST_VTBL struct IAdapterInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAdapterInfo_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAdapterInfo_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAdapterInfo_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAdapterInfo_GetAdapterIndex(This,pulIndex)	\
    ( (This)->lpVtbl -> GetAdapterIndex(This,pulIndex) ) 

#define IAdapterInfo_GetAdapterType(This,pAdapterType)	\
    ( (This)->lpVtbl -> GetAdapterType(This,pAdapterType) ) 

#define IAdapterInfo_GetAdapterAddresses(This,pulAddressCount,prgAddresses)	\
    ( (This)->lpVtbl -> GetAdapterAddresses(This,pulAddressCount,prgAddresses) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAdapterInfo_INTERFACE_DEFINED__ */


#ifndef __IPendingProxyConnection_INTERFACE_DEFINED__
#define __IPendingProxyConnection_INTERFACE_DEFINED__

/* interface IPendingProxyConnection */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IPendingProxyConnection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B68E5043-3E3D-4CC2-B9C1-5F8F88FEE81C")
    IPendingProxyConnection : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Cancel( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IPendingProxyConnectionVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IPendingProxyConnection * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IPendingProxyConnection * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IPendingProxyConnection * This);
        
        DECLSPEC_XFGVIRT(IPendingProxyConnection, Cancel)
        HRESULT ( STDMETHODCALLTYPE *Cancel )( 
            __RPC__in IPendingProxyConnection * This);
        
        END_INTERFACE
    } IPendingProxyConnectionVtbl;

    interface IPendingProxyConnection
    {
        CONST_VTBL struct IPendingProxyConnectionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPendingProxyConnection_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPendingProxyConnection_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPendingProxyConnection_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPendingProxyConnection_Cancel(This)	\
    ( (This)->lpVtbl -> Cancel(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPendingProxyConnection_INTERFACE_DEFINED__ */


#ifndef __IDataChannel_INTERFACE_DEFINED__
#define __IDataChannel_INTERFACE_DEFINED__

/* interface IDataChannel */
/* [local][unique][uuid][object] */ 


EXTERN_C const IID IID_IDataChannel;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("AD42D12A-4AD0-4856-919E-E854C91D1856")
    IDataChannel : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Cancel( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetChannelProperties( 
            /* [annotation][out] */ 
            _Out_  ALG_DATA_CHANNEL_PROPERTIES **ppProperties) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSessionCreationEventHandle( 
            /* [annotation][out] */ 
            _Out_  HANDLE *pHandle) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSessionDeletionEventHandle( 
            /* [annotation][out] */ 
            _Out_  HANDLE *pHandle) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IDataChannelVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDataChannel * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDataChannel * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDataChannel * This);
        
        DECLSPEC_XFGVIRT(IDataChannel, Cancel)
        HRESULT ( STDMETHODCALLTYPE *Cancel )( 
            IDataChannel * This);
        
        DECLSPEC_XFGVIRT(IDataChannel, GetChannelProperties)
        HRESULT ( STDMETHODCALLTYPE *GetChannelProperties )( 
            IDataChannel * This,
            /* [annotation][out] */ 
            _Out_  ALG_DATA_CHANNEL_PROPERTIES **ppProperties);
        
        DECLSPEC_XFGVIRT(IDataChannel, GetSessionCreationEventHandle)
        HRESULT ( STDMETHODCALLTYPE *GetSessionCreationEventHandle )( 
            IDataChannel * This,
            /* [annotation][out] */ 
            _Out_  HANDLE *pHandle);
        
        DECLSPEC_XFGVIRT(IDataChannel, GetSessionDeletionEventHandle)
        HRESULT ( STDMETHODCALLTYPE *GetSessionDeletionEventHandle )( 
            IDataChannel * This,
            /* [annotation][out] */ 
            _Out_  HANDLE *pHandle);
        
        END_INTERFACE
    } IDataChannelVtbl;

    interface IDataChannel
    {
        CONST_VTBL struct IDataChannelVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDataChannel_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDataChannel_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDataChannel_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDataChannel_Cancel(This)	\
    ( (This)->lpVtbl -> Cancel(This) ) 

#define IDataChannel_GetChannelProperties(This,ppProperties)	\
    ( (This)->lpVtbl -> GetChannelProperties(This,ppProperties) ) 

#define IDataChannel_GetSessionCreationEventHandle(This,pHandle)	\
    ( (This)->lpVtbl -> GetSessionCreationEventHandle(This,pHandle) ) 

#define IDataChannel_GetSessionDeletionEventHandle(This,pHandle)	\
    ( (This)->lpVtbl -> GetSessionDeletionEventHandle(This,pHandle) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDataChannel_INTERFACE_DEFINED__ */


#ifndef __IPersistentDataChannel_INTERFACE_DEFINED__
#define __IPersistentDataChannel_INTERFACE_DEFINED__

/* interface IPersistentDataChannel */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IPersistentDataChannel;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A180E934-D92A-415D-9144-759F8054E8F6")
    IPersistentDataChannel : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Cancel( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetChannelProperties( 
            /* [annotation][out] */ 
            _Out_  ALG_PERSISTENT_DATA_CHANNEL_PROPERTIES **ppProperties) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IPersistentDataChannelVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IPersistentDataChannel * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IPersistentDataChannel * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IPersistentDataChannel * This);
        
        DECLSPEC_XFGVIRT(IPersistentDataChannel, Cancel)
        HRESULT ( STDMETHODCALLTYPE *Cancel )( 
            __RPC__in IPersistentDataChannel * This);
        
        DECLSPEC_XFGVIRT(IPersistentDataChannel, GetChannelProperties)
        HRESULT ( STDMETHODCALLTYPE *GetChannelProperties )( 
            __RPC__in IPersistentDataChannel * This,
            /* [annotation][out] */ 
            _Out_  ALG_PERSISTENT_DATA_CHANNEL_PROPERTIES **ppProperties);
        
        END_INTERFACE
    } IPersistentDataChannelVtbl;

    interface IPersistentDataChannel
    {
        CONST_VTBL struct IPersistentDataChannelVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPersistentDataChannel_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPersistentDataChannel_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPersistentDataChannel_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPersistentDataChannel_Cancel(This)	\
    ( (This)->lpVtbl -> Cancel(This) ) 

#define IPersistentDataChannel_GetChannelProperties(This,ppProperties)	\
    ( (This)->lpVtbl -> GetChannelProperties(This,ppProperties) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPersistentDataChannel_INTERFACE_DEFINED__ */


#ifndef __IPrimaryControlChannel_INTERFACE_DEFINED__
#define __IPrimaryControlChannel_INTERFACE_DEFINED__

/* interface IPrimaryControlChannel */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IPrimaryControlChannel;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1A2E8B62-9012-4BE6-84AE-32BD66BA657A")
    IPrimaryControlChannel : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Cancel( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetChannelProperties( 
            /* [annotation][out] */ 
            _Out_  ALG_PRIMARY_CHANNEL_PROPERTIES **ppProperties) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetOriginalDestinationInformation( 
            /* [annotation][in] */ 
            _In_  ULONG ulSourceAddress,
            /* [annotation][in] */ 
            _In_  USHORT usSourcePort,
            /* [annotation][out] */ 
            _Out_  ULONG *pulOriginalDestinationAddress,
            /* [annotation][out] */ 
            _Out_  USHORT *pusOriginalDestinationPort,
            /* [annotation][out] */ 
            _Out_  ULONG *pulRemapDestinationAddress,
            /* [annotation][out] */ 
            _Out_  USHORT *pulRemapDestinationPort,
            /* [annotation][out] */ 
            _Out_  IAdapterInfo **ppReceiveAdapter) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IPrimaryControlChannelVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IPrimaryControlChannel * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IPrimaryControlChannel * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IPrimaryControlChannel * This);
        
        DECLSPEC_XFGVIRT(IPrimaryControlChannel, Cancel)
        HRESULT ( STDMETHODCALLTYPE *Cancel )( 
            __RPC__in IPrimaryControlChannel * This);
        
        DECLSPEC_XFGVIRT(IPrimaryControlChannel, GetChannelProperties)
        HRESULT ( STDMETHODCALLTYPE *GetChannelProperties )( 
            __RPC__in IPrimaryControlChannel * This,
            /* [annotation][out] */ 
            _Out_  ALG_PRIMARY_CHANNEL_PROPERTIES **ppProperties);
        
        DECLSPEC_XFGVIRT(IPrimaryControlChannel, GetOriginalDestinationInformation)
        HRESULT ( STDMETHODCALLTYPE *GetOriginalDestinationInformation )( 
            __RPC__in IPrimaryControlChannel * This,
            /* [annotation][in] */ 
            _In_  ULONG ulSourceAddress,
            /* [annotation][in] */ 
            _In_  USHORT usSourcePort,
            /* [annotation][out] */ 
            _Out_  ULONG *pulOriginalDestinationAddress,
            /* [annotation][out] */ 
            _Out_  USHORT *pusOriginalDestinationPort,
            /* [annotation][out] */ 
            _Out_  ULONG *pulRemapDestinationAddress,
            /* [annotation][out] */ 
            _Out_  USHORT *pulRemapDestinationPort,
            /* [annotation][out] */ 
            _Out_  IAdapterInfo **ppReceiveAdapter);
        
        END_INTERFACE
    } IPrimaryControlChannelVtbl;

    interface IPrimaryControlChannel
    {
        CONST_VTBL struct IPrimaryControlChannelVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPrimaryControlChannel_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPrimaryControlChannel_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPrimaryControlChannel_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPrimaryControlChannel_Cancel(This)	\
    ( (This)->lpVtbl -> Cancel(This) ) 

#define IPrimaryControlChannel_GetChannelProperties(This,ppProperties)	\
    ( (This)->lpVtbl -> GetChannelProperties(This,ppProperties) ) 

#define IPrimaryControlChannel_GetOriginalDestinationInformation(This,ulSourceAddress,usSourcePort,pulOriginalDestinationAddress,pusOriginalDestinationPort,pulRemapDestinationAddress,pulRemapDestinationPort,ppReceiveAdapter)	\
    ( (This)->lpVtbl -> GetOriginalDestinationInformation(This,ulSourceAddress,usSourcePort,pulOriginalDestinationAddress,pusOriginalDestinationPort,pulRemapDestinationAddress,pulRemapDestinationPort,ppReceiveAdapter) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPrimaryControlChannel_INTERFACE_DEFINED__ */


#ifndef __ISecondaryControlChannel_INTERFACE_DEFINED__
#define __ISecondaryControlChannel_INTERFACE_DEFINED__

/* interface ISecondaryControlChannel */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_ISecondaryControlChannel;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A23F9D10-714C-41FE-8471-FFB19BC28454")
    ISecondaryControlChannel : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Cancel( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetChannelProperties( 
            /* [annotation][out] */ 
            _Out_  ALG_SECONDARY_CHANNEL_PROPERTIES **ppProperties) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetOriginalDestinationInformation( 
            /* [annotation][in] */ 
            _In_  ULONG ulSourceAddress,
            /* [annotation][in] */ 
            _In_  USHORT usSourcePort,
            /* [annotation][out] */ 
            _Out_  ULONG *pulOriginalDestinationAddress,
            /* [annotation][out] */ 
            _Out_  USHORT *pusOriginalDestinationPort,
            /* [annotation][out] */ 
            _Out_  IAdapterInfo **ppReceiveAdapter) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISecondaryControlChannelVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISecondaryControlChannel * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISecondaryControlChannel * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISecondaryControlChannel * This);
        
        DECLSPEC_XFGVIRT(ISecondaryControlChannel, Cancel)
        HRESULT ( STDMETHODCALLTYPE *Cancel )( 
            __RPC__in ISecondaryControlChannel * This);
        
        DECLSPEC_XFGVIRT(ISecondaryControlChannel, GetChannelProperties)
        HRESULT ( STDMETHODCALLTYPE *GetChannelProperties )( 
            __RPC__in ISecondaryControlChannel * This,
            /* [annotation][out] */ 
            _Out_  ALG_SECONDARY_CHANNEL_PROPERTIES **ppProperties);
        
        DECLSPEC_XFGVIRT(ISecondaryControlChannel, GetOriginalDestinationInformation)
        HRESULT ( STDMETHODCALLTYPE *GetOriginalDestinationInformation )( 
            __RPC__in ISecondaryControlChannel * This,
            /* [annotation][in] */ 
            _In_  ULONG ulSourceAddress,
            /* [annotation][in] */ 
            _In_  USHORT usSourcePort,
            /* [annotation][out] */ 
            _Out_  ULONG *pulOriginalDestinationAddress,
            /* [annotation][out] */ 
            _Out_  USHORT *pusOriginalDestinationPort,
            /* [annotation][out] */ 
            _Out_  IAdapterInfo **ppReceiveAdapter);
        
        END_INTERFACE
    } ISecondaryControlChannelVtbl;

    interface ISecondaryControlChannel
    {
        CONST_VTBL struct ISecondaryControlChannelVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISecondaryControlChannel_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISecondaryControlChannel_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISecondaryControlChannel_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISecondaryControlChannel_Cancel(This)	\
    ( (This)->lpVtbl -> Cancel(This) ) 

#define ISecondaryControlChannel_GetChannelProperties(This,ppProperties)	\
    ( (This)->lpVtbl -> GetChannelProperties(This,ppProperties) ) 

#define ISecondaryControlChannel_GetOriginalDestinationInformation(This,ulSourceAddress,usSourcePort,pulOriginalDestinationAddress,pusOriginalDestinationPort,ppReceiveAdapter)	\
    ( (This)->lpVtbl -> GetOriginalDestinationInformation(This,ulSourceAddress,usSourcePort,pulOriginalDestinationAddress,pusOriginalDestinationPort,ppReceiveAdapter) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISecondaryControlChannel_INTERFACE_DEFINED__ */


#ifndef __IEnumAdapterInfo_INTERFACE_DEFINED__
#define __IEnumAdapterInfo_INTERFACE_DEFINED__

/* interface IEnumAdapterInfo */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IEnumAdapterInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A23F9D11-714C-41FE-8471-FFB19BC28454")
    IEnumAdapterInfo : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [annotation][in] */ 
            _In_  ULONG celt,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(celt,*pCeltFetched)  IAdapterInfo **rgAI,
            /* [annotation][out] */ 
            _Out_  ULONG *pCeltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [annotation][in] */ 
            _In_  ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [annotation][out] */ 
            _Out_  IEnumAdapterInfo **ppEnum) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IEnumAdapterInfoVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IEnumAdapterInfo * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IEnumAdapterInfo * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IEnumAdapterInfo * This);
        
        DECLSPEC_XFGVIRT(IEnumAdapterInfo, Next)
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            __RPC__in IEnumAdapterInfo * This,
            /* [annotation][in] */ 
            _In_  ULONG celt,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(celt,*pCeltFetched)  IAdapterInfo **rgAI,
            /* [annotation][out] */ 
            _Out_  ULONG *pCeltFetched);
        
        DECLSPEC_XFGVIRT(IEnumAdapterInfo, Skip)
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            __RPC__in IEnumAdapterInfo * This,
            /* [annotation][in] */ 
            _In_  ULONG celt);
        
        DECLSPEC_XFGVIRT(IEnumAdapterInfo, Reset)
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            __RPC__in IEnumAdapterInfo * This);
        
        DECLSPEC_XFGVIRT(IEnumAdapterInfo, Clone)
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            __RPC__in IEnumAdapterInfo * This,
            /* [annotation][out] */ 
            _Out_  IEnumAdapterInfo **ppEnum);
        
        END_INTERFACE
    } IEnumAdapterInfoVtbl;

    interface IEnumAdapterInfo
    {
        CONST_VTBL struct IEnumAdapterInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumAdapterInfo_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEnumAdapterInfo_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEnumAdapterInfo_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IEnumAdapterInfo_Next(This,celt,rgAI,pCeltFetched)	\
    ( (This)->lpVtbl -> Next(This,celt,rgAI,pCeltFetched) ) 

#define IEnumAdapterInfo_Skip(This,celt)	\
    ( (This)->lpVtbl -> Skip(This,celt) ) 

#define IEnumAdapterInfo_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define IEnumAdapterInfo_Clone(This,ppEnum)	\
    ( (This)->lpVtbl -> Clone(This,ppEnum) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IEnumAdapterInfo_INTERFACE_DEFINED__ */


#ifndef __IAdapterNotificationSink_INTERFACE_DEFINED__
#define __IAdapterNotificationSink_INTERFACE_DEFINED__

/* interface IAdapterNotificationSink */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAdapterNotificationSink;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("44AB2DC3-23B2-47DE-8228-2E1CCEEB9911")
    IAdapterNotificationSink : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AdapterAdded( 
            __RPC__in_opt IAdapterInfo *pAdapter) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AdapterRemoved( 
            __RPC__in_opt IAdapterInfo *pAdapter) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AdapterModified( 
            __RPC__in_opt IAdapterInfo *pAdapter) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AdapterUpdatePortMapping( 
            __RPC__in_opt IAdapterInfo *pAdapter) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAdapterNotificationSinkVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IAdapterNotificationSink * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IAdapterNotificationSink * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IAdapterNotificationSink * This);
        
        DECLSPEC_XFGVIRT(IAdapterNotificationSink, AdapterAdded)
        HRESULT ( STDMETHODCALLTYPE *AdapterAdded )( 
            __RPC__in IAdapterNotificationSink * This,
            __RPC__in_opt IAdapterInfo *pAdapter);
        
        DECLSPEC_XFGVIRT(IAdapterNotificationSink, AdapterRemoved)
        HRESULT ( STDMETHODCALLTYPE *AdapterRemoved )( 
            __RPC__in IAdapterNotificationSink * This,
            __RPC__in_opt IAdapterInfo *pAdapter);
        
        DECLSPEC_XFGVIRT(IAdapterNotificationSink, AdapterModified)
        HRESULT ( STDMETHODCALLTYPE *AdapterModified )( 
            __RPC__in IAdapterNotificationSink * This,
            __RPC__in_opt IAdapterInfo *pAdapter);
        
        DECLSPEC_XFGVIRT(IAdapterNotificationSink, AdapterUpdatePortMapping)
        HRESULT ( STDMETHODCALLTYPE *AdapterUpdatePortMapping )( 
            __RPC__in IAdapterNotificationSink * This,
            __RPC__in_opt IAdapterInfo *pAdapter);
        
        END_INTERFACE
    } IAdapterNotificationSinkVtbl;

    interface IAdapterNotificationSink
    {
        CONST_VTBL struct IAdapterNotificationSinkVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAdapterNotificationSink_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAdapterNotificationSink_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAdapterNotificationSink_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAdapterNotificationSink_AdapterAdded(This,pAdapter)	\
    ( (This)->lpVtbl -> AdapterAdded(This,pAdapter) ) 

#define IAdapterNotificationSink_AdapterRemoved(This,pAdapter)	\
    ( (This)->lpVtbl -> AdapterRemoved(This,pAdapter) ) 

#define IAdapterNotificationSink_AdapterModified(This,pAdapter)	\
    ( (This)->lpVtbl -> AdapterModified(This,pAdapter) ) 

#define IAdapterNotificationSink_AdapterUpdatePortMapping(This,pAdapter)	\
    ( (This)->lpVtbl -> AdapterUpdatePortMapping(This,pAdapter) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAdapterNotificationSink_INTERFACE_DEFINED__ */


#ifndef __IApplicationGatewayServices_INTERFACE_DEFINED__
#define __IApplicationGatewayServices_INTERFACE_DEFINED__

/* interface IApplicationGatewayServices */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IApplicationGatewayServices;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5134842A-FDCE-485D-93CD-DE1640643BBE")
    IApplicationGatewayServices : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CreatePrimaryControlChannel( 
            /* [annotation][in] */ 
            _In_  ULONG uAdapterIndex,
            /* [annotation][in] */ 
            _In_  ALG_PROTOCOL eProtocol,
            /* [annotation][in] */ 
            _In_  USHORT usPortToCapture,
            /* [annotation][in] */ 
            _In_  ALG_CAPTURE eCaptureType,
            /* [annotation][in] */ 
            _In_  BOOL fCaptureInbound,
            /* [annotation][in] */ 
            _In_  ULONG ulListenAddress,
            /* [annotation][in] */ 
            _In_  USHORT usListenPort,
            /* [annotation][out] */ 
            _Out_  IPrimaryControlChannel **ppIControlChannel) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateSecondaryControlChannel( 
            /* [annotation][in] */ 
            _In_  ALG_PROTOCOL eProtocol,
            /* [annotation][in] */ 
            _In_  ULONG ulPrivateAddress,
            /* [annotation][in] */ 
            _In_  USHORT usPrivatePort,
            /* [annotation][in] */ 
            _In_  ULONG ulPublicAddress,
            /* [annotation][in] */ 
            _In_  USHORT usPublicPort,
            /* [annotation][in] */ 
            _In_  ULONG ulRemoteAddress,
            /* [annotation][in] */ 
            _In_  USHORT usRemotePort,
            /* [annotation][in] */ 
            _In_  ULONG ulListenAddress,
            /* [annotation][in] */ 
            _In_  USHORT usListenPort,
            /* [annotation][in] */ 
            _In_  ALG_DIRECTION eDirection,
            /* [annotation][in] */ 
            _In_  BOOL fPersistent,
            /* [annotation][out] */ 
            _Out_  ISecondaryControlChannel **ppControlChannel) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBestSourceAddressForDestinationAddress( 
            /* [annotation][in] */ 
            _In_  ULONG ulDstAddress,
            /* [annotation][in] */ 
            _In_  BOOL fDemandDial,
            /* [annotation][out] */ 
            _Out_  ULONG *pulBestSrcAddress) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PrepareProxyConnection( 
            /* [annotation][in] */ 
            _In_  ALG_PROTOCOL eProtocol,
            /* [annotation][in] */ 
            _In_  ULONG ulSrcAddress,
            /* [annotation][in] */ 
            _In_  USHORT usSrcPort,
            /* [annotation][in] */ 
            _In_  ULONG ulDstAddress,
            /* [annotation][in] */ 
            _In_  USHORT usDstPort,
            /* [annotation][in] */ 
            _In_  BOOL fNoTimeout,
            /* [annotation][out] */ 
            _Out_  IPendingProxyConnection **ppPendingConnection) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PrepareSourceModifiedProxyConnection( 
            /* [annotation][in] */ 
            _In_  ALG_PROTOCOL eProtocol,
            /* [annotation][in] */ 
            _In_  ULONG ulSrcAddress,
            /* [annotation][in] */ 
            _In_  USHORT usSrcPort,
            /* [annotation][in] */ 
            _In_  ULONG ulDstAddress,
            /* [annotation][in] */ 
            _In_  USHORT usDstPort,
            /* [annotation][in] */ 
            _In_  ULONG ulNewSrcAddress,
            /* [annotation][in] */ 
            _In_  USHORT usNewSourcePort,
            /* [annotation][out] */ 
            _Out_  IPendingProxyConnection **ppPendingConnection) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateDataChannel( 
            /* [annotation][in] */ 
            _In_  ALG_PROTOCOL eProtocol,
            /* [annotation][in] */ 
            _In_  ULONG ulPrivateAddress,
            /* [annotation][in] */ 
            _In_  USHORT usPrivatePort,
            /* [annotation][in] */ 
            _In_  ULONG ulPublicAddress,
            /* [annotation][in] */ 
            _In_  USHORT usPublicPort,
            /* [annotation][in] */ 
            _In_  ULONG ulRemoteAddress,
            /* [annotation][in] */ 
            _In_  USHORT usRemotePort,
            /* [annotation][in] */ 
            _In_  ALG_DIRECTION eDirection,
            /* [annotation][in] */ 
            _In_  ALG_NOTIFICATION eDesiredNotification,
            /* [annotation][in] */ 
            _In_  BOOL fNoTimeout,
            /* [annotation][out] */ 
            _Out_  IDataChannel **ppDataChannel) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreatePersistentDataChannel( 
            /* [annotation][in] */ 
            _In_  ALG_PROTOCOL eProtocol,
            /* [annotation][in] */ 
            _In_  ULONG ulPrivateAddress,
            /* [annotation][in] */ 
            _In_  USHORT usPrivatePort,
            /* [annotation][in] */ 
            _In_  ULONG ulPublicAddress,
            /* [annotation][in] */ 
            _In_  USHORT usPublicPort,
            /* [annotation][in] */ 
            _In_  ULONG ulRemoteAddress,
            /* [annotation][in] */ 
            _In_  USHORT usRemotePort,
            /* [annotation][in] */ 
            _In_  ALG_DIRECTION eDirection,
            /* [annotation][out] */ 
            _Out_  IPersistentDataChannel **ppIPersistentDataChannel) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReservePort( 
            /* [annotation][in] */ 
            _In_  USHORT usPortCount,
            /* [annotation][out] */ 
            _Out_  USHORT *pusReservedPort) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReleaseReservedPort( 
            /* [annotation][in] */ 
            _In_  USHORT usReservedPortBase,
            /* [annotation][in] */ 
            _In_  USHORT usPortCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumerateAdapters( 
            /* [annotation][out] */ 
            _Out_  IEnumAdapterInfo **ppIEnumAdapterInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StartAdapterNotifications( 
            /* [annotation][in] */ 
            _In_  IAdapterNotificationSink *pSink,
            /* [annotation][in] */ 
            _In_  DWORD *pdwCookie) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StopAdapterNotifications( 
            /* [annotation][in] */ 
            _In_  DWORD dwCookieOfSink) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LookupAdapterPortMapping( 
            /* [annotation][in] */ 
            _In_  ULONG ulAdapterIndex,
            /* [annotation][in] */ 
            _In_  UCHAR Protocol,
            /* [annotation][in] */ 
            _In_  ULONG ulDestinationAddress,
            /* [annotation][in] */ 
            _In_  USHORT usDestinationPort,
            /* [annotation][out] */ 
            _Out_  ULONG *pulRemapAddress,
            /* [annotation][out] */ 
            _Out_  USHORT *pusRemapPort) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IApplicationGatewayServicesVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IApplicationGatewayServices * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IApplicationGatewayServices * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IApplicationGatewayServices * This);
        
        DECLSPEC_XFGVIRT(IApplicationGatewayServices, CreatePrimaryControlChannel)
        HRESULT ( STDMETHODCALLTYPE *CreatePrimaryControlChannel )( 
            __RPC__in IApplicationGatewayServices * This,
            /* [annotation][in] */ 
            _In_  ULONG uAdapterIndex,
            /* [annotation][in] */ 
            _In_  ALG_PROTOCOL eProtocol,
            /* [annotation][in] */ 
            _In_  USHORT usPortToCapture,
            /* [annotation][in] */ 
            _In_  ALG_CAPTURE eCaptureType,
            /* [annotation][in] */ 
            _In_  BOOL fCaptureInbound,
            /* [annotation][in] */ 
            _In_  ULONG ulListenAddress,
            /* [annotation][in] */ 
            _In_  USHORT usListenPort,
            /* [annotation][out] */ 
            _Out_  IPrimaryControlChannel **ppIControlChannel);
        
        DECLSPEC_XFGVIRT(IApplicationGatewayServices, CreateSecondaryControlChannel)
        HRESULT ( STDMETHODCALLTYPE *CreateSecondaryControlChannel )( 
            __RPC__in IApplicationGatewayServices * This,
            /* [annotation][in] */ 
            _In_  ALG_PROTOCOL eProtocol,
            /* [annotation][in] */ 
            _In_  ULONG ulPrivateAddress,
            /* [annotation][in] */ 
            _In_  USHORT usPrivatePort,
            /* [annotation][in] */ 
            _In_  ULONG ulPublicAddress,
            /* [annotation][in] */ 
            _In_  USHORT usPublicPort,
            /* [annotation][in] */ 
            _In_  ULONG ulRemoteAddress,
            /* [annotation][in] */ 
            _In_  USHORT usRemotePort,
            /* [annotation][in] */ 
            _In_  ULONG ulListenAddress,
            /* [annotation][in] */ 
            _In_  USHORT usListenPort,
            /* [annotation][in] */ 
            _In_  ALG_DIRECTION eDirection,
            /* [annotation][in] */ 
            _In_  BOOL fPersistent,
            /* [annotation][out] */ 
            _Out_  ISecondaryControlChannel **ppControlChannel);
        
        DECLSPEC_XFGVIRT(IApplicationGatewayServices, GetBestSourceAddressForDestinationAddress)
        HRESULT ( STDMETHODCALLTYPE *GetBestSourceAddressForDestinationAddress )( 
            __RPC__in IApplicationGatewayServices * This,
            /* [annotation][in] */ 
            _In_  ULONG ulDstAddress,
            /* [annotation][in] */ 
            _In_  BOOL fDemandDial,
            /* [annotation][out] */ 
            _Out_  ULONG *pulBestSrcAddress);
        
        DECLSPEC_XFGVIRT(IApplicationGatewayServices, PrepareProxyConnection)
        HRESULT ( STDMETHODCALLTYPE *PrepareProxyConnection )( 
            __RPC__in IApplicationGatewayServices * This,
            /* [annotation][in] */ 
            _In_  ALG_PROTOCOL eProtocol,
            /* [annotation][in] */ 
            _In_  ULONG ulSrcAddress,
            /* [annotation][in] */ 
            _In_  USHORT usSrcPort,
            /* [annotation][in] */ 
            _In_  ULONG ulDstAddress,
            /* [annotation][in] */ 
            _In_  USHORT usDstPort,
            /* [annotation][in] */ 
            _In_  BOOL fNoTimeout,
            /* [annotation][out] */ 
            _Out_  IPendingProxyConnection **ppPendingConnection);
        
        DECLSPEC_XFGVIRT(IApplicationGatewayServices, PrepareSourceModifiedProxyConnection)
        HRESULT ( STDMETHODCALLTYPE *PrepareSourceModifiedProxyConnection )( 
            __RPC__in IApplicationGatewayServices * This,
            /* [annotation][in] */ 
            _In_  ALG_PROTOCOL eProtocol,
            /* [annotation][in] */ 
            _In_  ULONG ulSrcAddress,
            /* [annotation][in] */ 
            _In_  USHORT usSrcPort,
            /* [annotation][in] */ 
            _In_  ULONG ulDstAddress,
            /* [annotation][in] */ 
            _In_  USHORT usDstPort,
            /* [annotation][in] */ 
            _In_  ULONG ulNewSrcAddress,
            /* [annotation][in] */ 
            _In_  USHORT usNewSourcePort,
            /* [annotation][out] */ 
            _Out_  IPendingProxyConnection **ppPendingConnection);
        
        DECLSPEC_XFGVIRT(IApplicationGatewayServices, CreateDataChannel)
        HRESULT ( STDMETHODCALLTYPE *CreateDataChannel )( 
            __RPC__in IApplicationGatewayServices * This,
            /* [annotation][in] */ 
            _In_  ALG_PROTOCOL eProtocol,
            /* [annotation][in] */ 
            _In_  ULONG ulPrivateAddress,
            /* [annotation][in] */ 
            _In_  USHORT usPrivatePort,
            /* [annotation][in] */ 
            _In_  ULONG ulPublicAddress,
            /* [annotation][in] */ 
            _In_  USHORT usPublicPort,
            /* [annotation][in] */ 
            _In_  ULONG ulRemoteAddress,
            /* [annotation][in] */ 
            _In_  USHORT usRemotePort,
            /* [annotation][in] */ 
            _In_  ALG_DIRECTION eDirection,
            /* [annotation][in] */ 
            _In_  ALG_NOTIFICATION eDesiredNotification,
            /* [annotation][in] */ 
            _In_  BOOL fNoTimeout,
            /* [annotation][out] */ 
            _Out_  IDataChannel **ppDataChannel);
        
        DECLSPEC_XFGVIRT(IApplicationGatewayServices, CreatePersistentDataChannel)
        HRESULT ( STDMETHODCALLTYPE *CreatePersistentDataChannel )( 
            __RPC__in IApplicationGatewayServices * This,
            /* [annotation][in] */ 
            _In_  ALG_PROTOCOL eProtocol,
            /* [annotation][in] */ 
            _In_  ULONG ulPrivateAddress,
            /* [annotation][in] */ 
            _In_  USHORT usPrivatePort,
            /* [annotation][in] */ 
            _In_  ULONG ulPublicAddress,
            /* [annotation][in] */ 
            _In_  USHORT usPublicPort,
            /* [annotation][in] */ 
            _In_  ULONG ulRemoteAddress,
            /* [annotation][in] */ 
            _In_  USHORT usRemotePort,
            /* [annotation][in] */ 
            _In_  ALG_DIRECTION eDirection,
            /* [annotation][out] */ 
            _Out_  IPersistentDataChannel **ppIPersistentDataChannel);
        
        DECLSPEC_XFGVIRT(IApplicationGatewayServices, ReservePort)
        HRESULT ( STDMETHODCALLTYPE *ReservePort )( 
            __RPC__in IApplicationGatewayServices * This,
            /* [annotation][in] */ 
            _In_  USHORT usPortCount,
            /* [annotation][out] */ 
            _Out_  USHORT *pusReservedPort);
        
        DECLSPEC_XFGVIRT(IApplicationGatewayServices, ReleaseReservedPort)
        HRESULT ( STDMETHODCALLTYPE *ReleaseReservedPort )( 
            __RPC__in IApplicationGatewayServices * This,
            /* [annotation][in] */ 
            _In_  USHORT usReservedPortBase,
            /* [annotation][in] */ 
            _In_  USHORT usPortCount);
        
        DECLSPEC_XFGVIRT(IApplicationGatewayServices, EnumerateAdapters)
        HRESULT ( STDMETHODCALLTYPE *EnumerateAdapters )( 
            __RPC__in IApplicationGatewayServices * This,
            /* [annotation][out] */ 
            _Out_  IEnumAdapterInfo **ppIEnumAdapterInfo);
        
        DECLSPEC_XFGVIRT(IApplicationGatewayServices, StartAdapterNotifications)
        HRESULT ( STDMETHODCALLTYPE *StartAdapterNotifications )( 
            __RPC__in IApplicationGatewayServices * This,
            /* [annotation][in] */ 
            _In_  IAdapterNotificationSink *pSink,
            /* [annotation][in] */ 
            _In_  DWORD *pdwCookie);
        
        DECLSPEC_XFGVIRT(IApplicationGatewayServices, StopAdapterNotifications)
        HRESULT ( STDMETHODCALLTYPE *StopAdapterNotifications )( 
            __RPC__in IApplicationGatewayServices * This,
            /* [annotation][in] */ 
            _In_  DWORD dwCookieOfSink);
        
        DECLSPEC_XFGVIRT(IApplicationGatewayServices, LookupAdapterPortMapping)
        HRESULT ( STDMETHODCALLTYPE *LookupAdapterPortMapping )( 
            __RPC__in IApplicationGatewayServices * This,
            /* [annotation][in] */ 
            _In_  ULONG ulAdapterIndex,
            /* [annotation][in] */ 
            _In_  UCHAR Protocol,
            /* [annotation][in] */ 
            _In_  ULONG ulDestinationAddress,
            /* [annotation][in] */ 
            _In_  USHORT usDestinationPort,
            /* [annotation][out] */ 
            _Out_  ULONG *pulRemapAddress,
            /* [annotation][out] */ 
            _Out_  USHORT *pusRemapPort);
        
        END_INTERFACE
    } IApplicationGatewayServicesVtbl;

    interface IApplicationGatewayServices
    {
        CONST_VTBL struct IApplicationGatewayServicesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IApplicationGatewayServices_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IApplicationGatewayServices_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IApplicationGatewayServices_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IApplicationGatewayServices_CreatePrimaryControlChannel(This,uAdapterIndex,eProtocol,usPortToCapture,eCaptureType,fCaptureInbound,ulListenAddress,usListenPort,ppIControlChannel)	\
    ( (This)->lpVtbl -> CreatePrimaryControlChannel(This,uAdapterIndex,eProtocol,usPortToCapture,eCaptureType,fCaptureInbound,ulListenAddress,usListenPort,ppIControlChannel) ) 

#define IApplicationGatewayServices_CreateSecondaryControlChannel(This,eProtocol,ulPrivateAddress,usPrivatePort,ulPublicAddress,usPublicPort,ulRemoteAddress,usRemotePort,ulListenAddress,usListenPort,eDirection,fPersistent,ppControlChannel)	\
    ( (This)->lpVtbl -> CreateSecondaryControlChannel(This,eProtocol,ulPrivateAddress,usPrivatePort,ulPublicAddress,usPublicPort,ulRemoteAddress,usRemotePort,ulListenAddress,usListenPort,eDirection,fPersistent,ppControlChannel) ) 

#define IApplicationGatewayServices_GetBestSourceAddressForDestinationAddress(This,ulDstAddress,fDemandDial,pulBestSrcAddress)	\
    ( (This)->lpVtbl -> GetBestSourceAddressForDestinationAddress(This,ulDstAddress,fDemandDial,pulBestSrcAddress) ) 

#define IApplicationGatewayServices_PrepareProxyConnection(This,eProtocol,ulSrcAddress,usSrcPort,ulDstAddress,usDstPort,fNoTimeout,ppPendingConnection)	\
    ( (This)->lpVtbl -> PrepareProxyConnection(This,eProtocol,ulSrcAddress,usSrcPort,ulDstAddress,usDstPort,fNoTimeout,ppPendingConnection) ) 

#define IApplicationGatewayServices_PrepareSourceModifiedProxyConnection(This,eProtocol,ulSrcAddress,usSrcPort,ulDstAddress,usDstPort,ulNewSrcAddress,usNewSourcePort,ppPendingConnection)	\
    ( (This)->lpVtbl -> PrepareSourceModifiedProxyConnection(This,eProtocol,ulSrcAddress,usSrcPort,ulDstAddress,usDstPort,ulNewSrcAddress,usNewSourcePort,ppPendingConnection) ) 

#define IApplicationGatewayServices_CreateDataChannel(This,eProtocol,ulPrivateAddress,usPrivatePort,ulPublicAddress,usPublicPort,ulRemoteAddress,usRemotePort,eDirection,eDesiredNotification,fNoTimeout,ppDataChannel)	\
    ( (This)->lpVtbl -> CreateDataChannel(This,eProtocol,ulPrivateAddress,usPrivatePort,ulPublicAddress,usPublicPort,ulRemoteAddress,usRemotePort,eDirection,eDesiredNotification,fNoTimeout,ppDataChannel) ) 

#define IApplicationGatewayServices_CreatePersistentDataChannel(This,eProtocol,ulPrivateAddress,usPrivatePort,ulPublicAddress,usPublicPort,ulRemoteAddress,usRemotePort,eDirection,ppIPersistentDataChannel)	\
    ( (This)->lpVtbl -> CreatePersistentDataChannel(This,eProtocol,ulPrivateAddress,usPrivatePort,ulPublicAddress,usPublicPort,ulRemoteAddress,usRemotePort,eDirection,ppIPersistentDataChannel) ) 

#define IApplicationGatewayServices_ReservePort(This,usPortCount,pusReservedPort)	\
    ( (This)->lpVtbl -> ReservePort(This,usPortCount,pusReservedPort) ) 

#define IApplicationGatewayServices_ReleaseReservedPort(This,usReservedPortBase,usPortCount)	\
    ( (This)->lpVtbl -> ReleaseReservedPort(This,usReservedPortBase,usPortCount) ) 

#define IApplicationGatewayServices_EnumerateAdapters(This,ppIEnumAdapterInfo)	\
    ( (This)->lpVtbl -> EnumerateAdapters(This,ppIEnumAdapterInfo) ) 

#define IApplicationGatewayServices_StartAdapterNotifications(This,pSink,pdwCookie)	\
    ( (This)->lpVtbl -> StartAdapterNotifications(This,pSink,pdwCookie) ) 

#define IApplicationGatewayServices_StopAdapterNotifications(This,dwCookieOfSink)	\
    ( (This)->lpVtbl -> StopAdapterNotifications(This,dwCookieOfSink) ) 

#define IApplicationGatewayServices_LookupAdapterPortMapping(This,ulAdapterIndex,Protocol,ulDestinationAddress,usDestinationPort,pulRemapAddress,pusRemapPort)	\
    ( (This)->lpVtbl -> LookupAdapterPortMapping(This,ulAdapterIndex,Protocol,ulDestinationAddress,usDestinationPort,pulRemapAddress,pusRemapPort) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IApplicationGatewayServices_INTERFACE_DEFINED__ */


#ifndef __IApplicationGateway_INTERFACE_DEFINED__
#define __IApplicationGateway_INTERFACE_DEFINED__

/* interface IApplicationGateway */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IApplicationGateway;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5134842B-FDCE-485D-93CD-DE1640643BBE")
    IApplicationGateway : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Initialize( 
            /* [annotation][in] */ 
            _In_  IApplicationGatewayServices *pAlgServices) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Stop( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IApplicationGatewayVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IApplicationGateway * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IApplicationGateway * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IApplicationGateway * This);
        
        DECLSPEC_XFGVIRT(IApplicationGateway, Initialize)
        HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            __RPC__in IApplicationGateway * This,
            /* [annotation][in] */ 
            _In_  IApplicationGatewayServices *pAlgServices);
        
        DECLSPEC_XFGVIRT(IApplicationGateway, Stop)
        HRESULT ( STDMETHODCALLTYPE *Stop )( 
            __RPC__in IApplicationGateway * This);
        
        END_INTERFACE
    } IApplicationGatewayVtbl;

    interface IApplicationGateway
    {
        CONST_VTBL struct IApplicationGatewayVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IApplicationGateway_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IApplicationGateway_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IApplicationGateway_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IApplicationGateway_Initialize(This,pAlgServices)	\
    ( (This)->lpVtbl -> Initialize(This,pAlgServices) ) 

#define IApplicationGateway_Stop(This)	\
    ( (This)->lpVtbl -> Stop(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IApplicationGateway_INTERFACE_DEFINED__ */



#ifndef __ALGLib_LIBRARY_DEFINED__
#define __ALGLib_LIBRARY_DEFINED__

/* library ALGLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_ALGLib;

EXTERN_C const CLSID CLSID_ApplicationGatewayServices;

#ifdef __cplusplus

class DECLSPEC_UUID("F8ADE1D3-49DF-4B75-9005-EF9508E6A337")
ApplicationGatewayServices;
#endif

EXTERN_C const CLSID CLSID_PrimaryControlChannel;

#ifdef __cplusplus

class DECLSPEC_UUID("3CEB5509-C1CD-432F-9D8F-65D1E286AA80")
PrimaryControlChannel;
#endif

EXTERN_C const CLSID CLSID_SecondaryControlChannel;

#ifdef __cplusplus

class DECLSPEC_UUID("7B3181A0-C92F-4567-B0FA-CD9A10ECD7D1")
SecondaryControlChannel;
#endif

EXTERN_C const CLSID CLSID_AdapterInfo;

#ifdef __cplusplus

class DECLSPEC_UUID("6F9942C9-C1B1-4AB5-93DA-6058991DC8F3")
AdapterInfo;
#endif

EXTERN_C const CLSID CLSID_EnumAdapterInfo;

#ifdef __cplusplus

class DECLSPEC_UUID("6F9942CA-C1B1-4AB5-93DA-6058991DC8F3")
EnumAdapterInfo;
#endif

EXTERN_C const CLSID CLSID_PendingProxyConnection;

#ifdef __cplusplus

class DECLSPEC_UUID("D8A68E5E-2B37-426C-A329-C117C14C429E")
PendingProxyConnection;
#endif

EXTERN_C const CLSID CLSID_DataChannel;

#ifdef __cplusplus

class DECLSPEC_UUID("BBB36F15-408D-4056-8C27-920843D40BE5")
DataChannel;
#endif

EXTERN_C const CLSID CLSID_PersistentDataChannel;

#ifdef __cplusplus

class DECLSPEC_UUID("BC9B54AB-7883-4C13-909F-033D03267990")
PersistentDataChannel;
#endif
#endif /* __ALGLib_LIBRARY_DEFINED__ */

/* interface __MIDL_itf_alg_0000_0011 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_alg_0000_0011_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_alg_0000_0011_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


