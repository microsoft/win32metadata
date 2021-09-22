

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
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

#ifndef __netcon_h__
#define __netcon_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IEnumNetConnection_FWD_DEFINED__
#define __IEnumNetConnection_FWD_DEFINED__
typedef interface IEnumNetConnection IEnumNetConnection;

#endif 	/* __IEnumNetConnection_FWD_DEFINED__ */


#ifndef __INetConnection_FWD_DEFINED__
#define __INetConnection_FWD_DEFINED__
typedef interface INetConnection INetConnection;

#endif 	/* __INetConnection_FWD_DEFINED__ */


#ifndef __INetConnectionManager_FWD_DEFINED__
#define __INetConnectionManager_FWD_DEFINED__
typedef interface INetConnectionManager INetConnectionManager;

#endif 	/* __INetConnectionManager_FWD_DEFINED__ */


#ifndef __INetConnectionConnectUi_FWD_DEFINED__
#define __INetConnectionConnectUi_FWD_DEFINED__
typedef interface INetConnectionConnectUi INetConnectionConnectUi;

#endif 	/* __INetConnectionConnectUi_FWD_DEFINED__ */


#ifndef __IEnumNetSharingPortMapping_FWD_DEFINED__
#define __IEnumNetSharingPortMapping_FWD_DEFINED__
typedef interface IEnumNetSharingPortMapping IEnumNetSharingPortMapping;

#endif 	/* __IEnumNetSharingPortMapping_FWD_DEFINED__ */


#ifndef __INetSharingPortMappingProps_FWD_DEFINED__
#define __INetSharingPortMappingProps_FWD_DEFINED__
typedef interface INetSharingPortMappingProps INetSharingPortMappingProps;

#endif 	/* __INetSharingPortMappingProps_FWD_DEFINED__ */


#ifndef __INetSharingPortMapping_FWD_DEFINED__
#define __INetSharingPortMapping_FWD_DEFINED__
typedef interface INetSharingPortMapping INetSharingPortMapping;

#endif 	/* __INetSharingPortMapping_FWD_DEFINED__ */


#ifndef __IEnumNetSharingEveryConnection_FWD_DEFINED__
#define __IEnumNetSharingEveryConnection_FWD_DEFINED__
typedef interface IEnumNetSharingEveryConnection IEnumNetSharingEveryConnection;

#endif 	/* __IEnumNetSharingEveryConnection_FWD_DEFINED__ */


#ifndef __IEnumNetSharingPublicConnection_FWD_DEFINED__
#define __IEnumNetSharingPublicConnection_FWD_DEFINED__
typedef interface IEnumNetSharingPublicConnection IEnumNetSharingPublicConnection;

#endif 	/* __IEnumNetSharingPublicConnection_FWD_DEFINED__ */


#ifndef __IEnumNetSharingPrivateConnection_FWD_DEFINED__
#define __IEnumNetSharingPrivateConnection_FWD_DEFINED__
typedef interface IEnumNetSharingPrivateConnection IEnumNetSharingPrivateConnection;

#endif 	/* __IEnumNetSharingPrivateConnection_FWD_DEFINED__ */


#ifndef __INetSharingPortMappingCollection_FWD_DEFINED__
#define __INetSharingPortMappingCollection_FWD_DEFINED__
typedef interface INetSharingPortMappingCollection INetSharingPortMappingCollection;

#endif 	/* __INetSharingPortMappingCollection_FWD_DEFINED__ */


#ifndef __INetConnectionProps_FWD_DEFINED__
#define __INetConnectionProps_FWD_DEFINED__
typedef interface INetConnectionProps INetConnectionProps;

#endif 	/* __INetConnectionProps_FWD_DEFINED__ */


#ifndef __INetSharingConfiguration_FWD_DEFINED__
#define __INetSharingConfiguration_FWD_DEFINED__
typedef interface INetSharingConfiguration INetSharingConfiguration;

#endif 	/* __INetSharingConfiguration_FWD_DEFINED__ */


#ifndef __INetSharingEveryConnectionCollection_FWD_DEFINED__
#define __INetSharingEveryConnectionCollection_FWD_DEFINED__
typedef interface INetSharingEveryConnectionCollection INetSharingEveryConnectionCollection;

#endif 	/* __INetSharingEveryConnectionCollection_FWD_DEFINED__ */


#ifndef __INetSharingPublicConnectionCollection_FWD_DEFINED__
#define __INetSharingPublicConnectionCollection_FWD_DEFINED__
typedef interface INetSharingPublicConnectionCollection INetSharingPublicConnectionCollection;

#endif 	/* __INetSharingPublicConnectionCollection_FWD_DEFINED__ */


#ifndef __INetSharingPrivateConnectionCollection_FWD_DEFINED__
#define __INetSharingPrivateConnectionCollection_FWD_DEFINED__
typedef interface INetSharingPrivateConnectionCollection INetSharingPrivateConnectionCollection;

#endif 	/* __INetSharingPrivateConnectionCollection_FWD_DEFINED__ */


#ifndef __INetSharingManager_FWD_DEFINED__
#define __INetSharingManager_FWD_DEFINED__
typedef interface INetSharingManager INetSharingManager;

#endif 	/* __INetSharingManager_FWD_DEFINED__ */


#ifndef __NetSharingManager_FWD_DEFINED__
#define __NetSharingManager_FWD_DEFINED__

#ifdef __cplusplus
typedef class NetSharingManager NetSharingManager;
#else
typedef struct NetSharingManager NetSharingManager;
#endif /* __cplusplus */

#endif 	/* __NetSharingManager_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "prsht.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_netcon_0000_0000 */
/* [local] */ 

//+-------------------------------------------------------------------------
//
//  Microsoft Windows
//  Copyright (c) Microsoft Corporation. All rights reserved.
//
//--------------------------------------------------------------------------
#include <winapifamily.h>
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
#if ( _MSC_VER >= 800 )
#pragma warning(disable:4201)
#endif

EXTERN_C const CLSID CLSID_ConnectionManager;
EXTERN_C const CLSID CLSID_NetSharingManager;

#define NETCON_MAX_NAME_LEN 256















extern RPC_IF_HANDLE __MIDL_itf_netcon_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_netcon_0000_0000_v0_0_s_ifspec;

#ifndef __IEnumNetConnection_INTERFACE_DEFINED__
#define __IEnumNetConnection_INTERFACE_DEFINED__

/* interface IEnumNetConnection */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IEnumNetConnection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C08956A0-1CD3-11D1-B1C5-00805FC1270E")
    IEnumNetConnection : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [annotation][in] */ 
            _In_  ULONG celt,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(celt,*pceltFetched)  INetConnection **rgelt,
            /* [annotation][out] */ 
            _Out_  ULONG *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [annotation][in] */ 
            _In_  ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [annotation][out] */ 
            _Out_  IEnumNetConnection **ppenum) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IEnumNetConnectionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IEnumNetConnection * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IEnumNetConnection * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IEnumNetConnection * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            __RPC__in IEnumNetConnection * This,
            /* [annotation][in] */ 
            _In_  ULONG celt,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(celt,*pceltFetched)  INetConnection **rgelt,
            /* [annotation][out] */ 
            _Out_  ULONG *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            __RPC__in IEnumNetConnection * This,
            /* [annotation][in] */ 
            _In_  ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            __RPC__in IEnumNetConnection * This);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            __RPC__in IEnumNetConnection * This,
            /* [annotation][out] */ 
            _Out_  IEnumNetConnection **ppenum);
        
        END_INTERFACE
    } IEnumNetConnectionVtbl;

    interface IEnumNetConnection
    {
        CONST_VTBL struct IEnumNetConnectionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumNetConnection_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEnumNetConnection_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEnumNetConnection_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IEnumNetConnection_Next(This,celt,rgelt,pceltFetched)	\
    ( (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched) ) 

#define IEnumNetConnection_Skip(This,celt)	\
    ( (This)->lpVtbl -> Skip(This,celt) ) 

#define IEnumNetConnection_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define IEnumNetConnection_Clone(This,ppenum)	\
    ( (This)->lpVtbl -> Clone(This,ppenum) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IEnumNetConnection_INTERFACE_DEFINED__ */


#ifndef __INetConnection_INTERFACE_DEFINED__
#define __INetConnection_INTERFACE_DEFINED__

/* interface INetConnection */
/* [unique][uuid][object] */ 

typedef 
enum tagNETCON_CHARACTERISTIC_FLAGS
    {
        NCCF_NONE	= 0,
        NCCF_ALL_USERS	= 0x1,
        NCCF_ALLOW_DUPLICATION	= 0x2,
        NCCF_ALLOW_REMOVAL	= 0x4,
        NCCF_ALLOW_RENAME	= 0x8,
        NCCF_INCOMING_ONLY	= 0x20,
        NCCF_OUTGOING_ONLY	= 0x40,
        NCCF_BRANDED	= 0x80,
        NCCF_SHARED	= 0x100,
        NCCF_BRIDGED	= 0x200,
        NCCF_FIREWALLED	= 0x400,
        NCCF_DEFAULT	= 0x800,
        NCCF_HOMENET_CAPABLE	= 0x1000,
        NCCF_SHARED_PRIVATE	= 0x2000,
        NCCF_QUARANTINED	= 0x4000,
        NCCF_RESERVED	= 0x8000,
        NCCF_HOSTED_NETWORK	= 0x10000,
        NCCF_VIRTUAL_STATION	= 0x20000,
        NCCF_WIFI_DIRECT	= 0x40000,
        NCCF_BLUETOOTH_MASK	= 0xf0000,
        NCCF_LAN_MASK	= 0xf00000
    } 	NETCON_CHARACTERISTIC_FLAGS;

typedef 
enum tagNETCON_STATUS
    {
        NCS_DISCONNECTED	= 0,
        NCS_CONNECTING	= ( NCS_DISCONNECTED + 1 ) ,
        NCS_CONNECTED	= ( NCS_CONNECTING + 1 ) ,
        NCS_DISCONNECTING	= ( NCS_CONNECTED + 1 ) ,
        NCS_HARDWARE_NOT_PRESENT	= ( NCS_DISCONNECTING + 1 ) ,
        NCS_HARDWARE_DISABLED	= ( NCS_HARDWARE_NOT_PRESENT + 1 ) ,
        NCS_HARDWARE_MALFUNCTION	= ( NCS_HARDWARE_DISABLED + 1 ) ,
        NCS_MEDIA_DISCONNECTED	= ( NCS_HARDWARE_MALFUNCTION + 1 ) ,
        NCS_AUTHENTICATING	= ( NCS_MEDIA_DISCONNECTED + 1 ) ,
        NCS_AUTHENTICATION_SUCCEEDED	= ( NCS_AUTHENTICATING + 1 ) ,
        NCS_AUTHENTICATION_FAILED	= ( NCS_AUTHENTICATION_SUCCEEDED + 1 ) ,
        NCS_INVALID_ADDRESS	= ( NCS_AUTHENTICATION_FAILED + 1 ) ,
        NCS_CREDENTIALS_REQUIRED	= ( NCS_INVALID_ADDRESS + 1 ) ,
        NCS_ACTION_REQUIRED	= ( NCS_CREDENTIALS_REQUIRED + 1 ) ,
        NCS_ACTION_REQUIRED_RETRY	= ( NCS_ACTION_REQUIRED + 1 ) ,
        NCS_CONNECT_FAILED	= ( NCS_ACTION_REQUIRED_RETRY + 1 ) 
    } 	NETCON_STATUS;

typedef 
enum tagNETCON_TYPE
    {
        NCT_DIRECT_CONNECT	= 0,
        NCT_INBOUND	= 1,
        NCT_INTERNET	= ( NCT_INBOUND + 1 ) ,
        NCT_LAN	= ( NCT_INTERNET + 1 ) ,
        NCT_PHONE	= ( NCT_LAN + 1 ) ,
        NCT_TUNNEL	= ( NCT_PHONE + 1 ) ,
        NCT_BRIDGE	= ( NCT_TUNNEL + 1 ) 
    } 	NETCON_TYPE;

typedef 
enum tagNETCON_MEDIATYPE
    {
        NCM_NONE	= 0,
        NCM_DIRECT	= ( NCM_NONE + 1 ) ,
        NCM_ISDN	= 2,
        NCM_LAN	= ( NCM_ISDN + 1 ) ,
        NCM_PHONE	= ( NCM_LAN + 1 ) ,
        NCM_TUNNEL	= ( NCM_PHONE + 1 ) ,
        NCM_PPPOE	= ( NCM_TUNNEL + 1 ) ,
        NCM_BRIDGE	= ( NCM_PPPOE + 1 ) ,
        NCM_SHAREDACCESSHOST_LAN	= ( NCM_BRIDGE + 1 ) ,
        NCM_SHAREDACCESSHOST_RAS	= ( NCM_SHAREDACCESSHOST_LAN + 1 ) 
    } 	NETCON_MEDIATYPE;

typedef struct tagNETCON_PROPERTIES
    {
    GUID guidId;
    /* [string] */ LPWSTR pszwName;
    /* [string] */ LPWSTR pszwDeviceName;
    NETCON_STATUS Status;
    NETCON_MEDIATYPE MediaType;
    DWORD dwCharacter;
    CLSID clsidThisObject;
    CLSID clsidUiObject;
    } 	NETCON_PROPERTIES;

#define S_OBJECT_NO_LONGER_VALID ((HRESULT)0x00000002L)

EXTERN_C const IID IID_INetConnection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C08956A1-1CD3-11D1-B1C5-00805FC1270E")
    INetConnection : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Connect( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Disconnect( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Delete( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Duplicate( 
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszwDuplicateName,
            /* [annotation][out] */ 
            _Out_  INetConnection **ppCon) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetProperties( 
            /* [annotation][out] */ 
            _Out_  NETCON_PROPERTIES **ppProps) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetUiObjectClassId( 
            /* [ref][out] */ __RPC__out CLSID *pclsid) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Rename( 
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszwNewName) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct INetConnectionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in INetConnection * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in INetConnection * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in INetConnection * This);
        
        HRESULT ( STDMETHODCALLTYPE *Connect )( 
            __RPC__in INetConnection * This);
        
        HRESULT ( STDMETHODCALLTYPE *Disconnect )( 
            __RPC__in INetConnection * This);
        
        HRESULT ( STDMETHODCALLTYPE *Delete )( 
            __RPC__in INetConnection * This);
        
        HRESULT ( STDMETHODCALLTYPE *Duplicate )( 
            __RPC__in INetConnection * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszwDuplicateName,
            /* [annotation][out] */ 
            _Out_  INetConnection **ppCon);
        
        HRESULT ( STDMETHODCALLTYPE *GetProperties )( 
            __RPC__in INetConnection * This,
            /* [annotation][out] */ 
            _Out_  NETCON_PROPERTIES **ppProps);
        
        HRESULT ( STDMETHODCALLTYPE *GetUiObjectClassId )( 
            __RPC__in INetConnection * This,
            /* [ref][out] */ __RPC__out CLSID *pclsid);
        
        HRESULT ( STDMETHODCALLTYPE *Rename )( 
            __RPC__in INetConnection * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszwNewName);
        
        END_INTERFACE
    } INetConnectionVtbl;

    interface INetConnection
    {
        CONST_VTBL struct INetConnectionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INetConnection_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define INetConnection_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define INetConnection_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define INetConnection_Connect(This)	\
    ( (This)->lpVtbl -> Connect(This) ) 

#define INetConnection_Disconnect(This)	\
    ( (This)->lpVtbl -> Disconnect(This) ) 

#define INetConnection_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define INetConnection_Duplicate(This,pszwDuplicateName,ppCon)	\
    ( (This)->lpVtbl -> Duplicate(This,pszwDuplicateName,ppCon) ) 

#define INetConnection_GetProperties(This,ppProps)	\
    ( (This)->lpVtbl -> GetProperties(This,ppProps) ) 

#define INetConnection_GetUiObjectClassId(This,pclsid)	\
    ( (This)->lpVtbl -> GetUiObjectClassId(This,pclsid) ) 

#define INetConnection_Rename(This,pszwNewName)	\
    ( (This)->lpVtbl -> Rename(This,pszwNewName) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __INetConnection_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_netcon_0000_0002 */
/* [local] */ 


STDAPI_(VOID) NcFreeNetconProperties (NETCON_PROPERTIES* pProps);


STDAPI_(BOOL) NcIsValidConnectionName (PCWSTR pszwName);



extern RPC_IF_HANDLE __MIDL_itf_netcon_0000_0002_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_netcon_0000_0002_v0_0_s_ifspec;

#ifndef __INetConnectionManager_INTERFACE_DEFINED__
#define __INetConnectionManager_INTERFACE_DEFINED__

/* interface INetConnectionManager */
/* [unique][uuid][object] */ 

typedef 
enum tagNETCONMGR_ENUM_FLAGS
    {
        NCME_DEFAULT	= 0,
        NCME_HIDDEN	= 0x1
    } 	NETCONMGR_ENUM_FLAGS;


EXTERN_C const IID IID_INetConnectionManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C08956A2-1CD3-11D1-B1C5-00805FC1270E")
    INetConnectionManager : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE EnumConnections( 
            /* [annotation][in] */ 
            _In_  NETCONMGR_ENUM_FLAGS Flags,
            /* [annotation][out] */ 
            _Out_  IEnumNetConnection **ppEnum) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct INetConnectionManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in INetConnectionManager * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in INetConnectionManager * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in INetConnectionManager * This);
        
        HRESULT ( STDMETHODCALLTYPE *EnumConnections )( 
            __RPC__in INetConnectionManager * This,
            /* [annotation][in] */ 
            _In_  NETCONMGR_ENUM_FLAGS Flags,
            /* [annotation][out] */ 
            _Out_  IEnumNetConnection **ppEnum);
        
        END_INTERFACE
    } INetConnectionManagerVtbl;

    interface INetConnectionManager
    {
        CONST_VTBL struct INetConnectionManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INetConnectionManager_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define INetConnectionManager_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define INetConnectionManager_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define INetConnectionManager_EnumConnections(This,Flags,ppEnum)	\
    ( (This)->lpVtbl -> EnumConnections(This,Flags,ppEnum) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __INetConnectionManager_INTERFACE_DEFINED__ */


#ifndef __INetConnectionConnectUi_INTERFACE_DEFINED__
#define __INetConnectionConnectUi_INTERFACE_DEFINED__

/* interface INetConnectionConnectUi */
/* [unique][uuid][object] */ 

typedef 
enum tagNETCONUI_CONNECT_FLAGS
    {
        NCUC_DEFAULT	= 0,
        NCUC_NO_UI	= 0x1,
        NCUC_ENABLE_DISABLE	= 0x2
    } 	NETCONUI_CONNECT_FLAGS;


EXTERN_C const IID IID_INetConnectionConnectUi;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C08956A3-1CD3-11D1-B1C5-00805FC1270E")
    INetConnectionConnectUi : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetConnection( 
            /* [annotation][in] */ 
            _In_  INetConnection *pCon) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Connect( 
            /* [annotation][in] */ 
            _In_  HWND hwndParent,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Disconnect( 
            /* [annotation][in] */ 
            _In_  HWND hwndParent,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct INetConnectionConnectUiVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in INetConnectionConnectUi * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in INetConnectionConnectUi * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in INetConnectionConnectUi * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetConnection )( 
            __RPC__in INetConnectionConnectUi * This,
            /* [annotation][in] */ 
            _In_  INetConnection *pCon);
        
        HRESULT ( STDMETHODCALLTYPE *Connect )( 
            __RPC__in INetConnectionConnectUi * This,
            /* [annotation][in] */ 
            _In_  HWND hwndParent,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags);
        
        HRESULT ( STDMETHODCALLTYPE *Disconnect )( 
            __RPC__in INetConnectionConnectUi * This,
            /* [annotation][in] */ 
            _In_  HWND hwndParent,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags);
        
        END_INTERFACE
    } INetConnectionConnectUiVtbl;

    interface INetConnectionConnectUi
    {
        CONST_VTBL struct INetConnectionConnectUiVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INetConnectionConnectUi_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define INetConnectionConnectUi_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define INetConnectionConnectUi_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define INetConnectionConnectUi_SetConnection(This,pCon)	\
    ( (This)->lpVtbl -> SetConnection(This,pCon) ) 

#define INetConnectionConnectUi_Connect(This,hwndParent,dwFlags)	\
    ( (This)->lpVtbl -> Connect(This,hwndParent,dwFlags) ) 

#define INetConnectionConnectUi_Disconnect(This,hwndParent,dwFlags)	\
    ( (This)->lpVtbl -> Disconnect(This,hwndParent,dwFlags) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __INetConnectionConnectUi_INTERFACE_DEFINED__ */


#ifndef __IEnumNetSharingPortMapping_INTERFACE_DEFINED__
#define __IEnumNetSharingPortMapping_INTERFACE_DEFINED__

/* interface IEnumNetSharingPortMapping */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IEnumNetSharingPortMapping;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C08956B0-1CD3-11D1-B1C5-00805FC1270E")
    IEnumNetSharingPortMapping : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [annotation][in] */ 
            _In_  ULONG celt,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(celt,*pceltFetched)  VARIANT *rgVar,
            /* [annotation][out] */ 
            _Out_  ULONG *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [annotation][in] */ 
            _In_  ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [annotation][out] */ 
            _Out_  IEnumNetSharingPortMapping **ppenum) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IEnumNetSharingPortMappingVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IEnumNetSharingPortMapping * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IEnumNetSharingPortMapping * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IEnumNetSharingPortMapping * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            __RPC__in IEnumNetSharingPortMapping * This,
            /* [annotation][in] */ 
            _In_  ULONG celt,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(celt,*pceltFetched)  VARIANT *rgVar,
            /* [annotation][out] */ 
            _Out_  ULONG *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            __RPC__in IEnumNetSharingPortMapping * This,
            /* [annotation][in] */ 
            _In_  ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            __RPC__in IEnumNetSharingPortMapping * This);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            __RPC__in IEnumNetSharingPortMapping * This,
            /* [annotation][out] */ 
            _Out_  IEnumNetSharingPortMapping **ppenum);
        
        END_INTERFACE
    } IEnumNetSharingPortMappingVtbl;

    interface IEnumNetSharingPortMapping
    {
        CONST_VTBL struct IEnumNetSharingPortMappingVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumNetSharingPortMapping_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEnumNetSharingPortMapping_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEnumNetSharingPortMapping_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IEnumNetSharingPortMapping_Next(This,celt,rgVar,pceltFetched)	\
    ( (This)->lpVtbl -> Next(This,celt,rgVar,pceltFetched) ) 

#define IEnumNetSharingPortMapping_Skip(This,celt)	\
    ( (This)->lpVtbl -> Skip(This,celt) ) 

#define IEnumNetSharingPortMapping_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define IEnumNetSharingPortMapping_Clone(This,ppenum)	\
    ( (This)->lpVtbl -> Clone(This,ppenum) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IEnumNetSharingPortMapping_INTERFACE_DEFINED__ */


#ifndef __INetSharingPortMappingProps_INTERFACE_DEFINED__
#define __INetSharingPortMappingProps_INTERFACE_DEFINED__

/* interface INetSharingPortMappingProps */
/* [unique][dual][oleautomation][uuid][object] */ 


EXTERN_C const IID IID_INetSharingPortMappingProps;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("24B7E9B5-E38F-4685-851B-00892CF5F940")
    INetSharingPortMappingProps : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrName) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IPProtocol( 
            /* [annotation][retval][out] */ 
            _Out_retval_  UCHAR *pucIPProt) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ExternalPort( 
            /* [annotation][retval][out] */ 
            _Out_retval_  long *pusPort) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_InternalPort( 
            /* [annotation][retval][out] */ 
            _Out_retval_  long *pusPort) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Options( 
            /* [annotation][retval][out] */ 
            _Out_retval_  long *pdwOptions) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_TargetName( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrTargetName) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_TargetIPAddress( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrTargetIPAddress) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Enabled( 
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pbool) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct INetSharingPortMappingPropsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in INetSharingPortMappingProps * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in INetSharingPortMappingProps * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in INetSharingPortMappingProps * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in INetSharingPortMappingProps * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in INetSharingPortMappingProps * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in INetSharingPortMappingProps * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][size_is][in] */ 
            _In_reads_(cNames)  LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cNames)  DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            INetSharingPortMappingProps * This,
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
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            __RPC__in INetSharingPortMappingProps * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrName);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IPProtocol )( 
            __RPC__in INetSharingPortMappingProps * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  UCHAR *pucIPProt);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ExternalPort )( 
            __RPC__in INetSharingPortMappingProps * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *pusPort);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InternalPort )( 
            __RPC__in INetSharingPortMappingProps * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *pusPort);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Options )( 
            __RPC__in INetSharingPortMappingProps * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *pdwOptions);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TargetName )( 
            __RPC__in INetSharingPortMappingProps * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrTargetName);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TargetIPAddress )( 
            __RPC__in INetSharingPortMappingProps * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrTargetIPAddress);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Enabled )( 
            __RPC__in INetSharingPortMappingProps * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pbool);
        
        END_INTERFACE
    } INetSharingPortMappingPropsVtbl;

    interface INetSharingPortMappingProps
    {
        CONST_VTBL struct INetSharingPortMappingPropsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INetSharingPortMappingProps_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define INetSharingPortMappingProps_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define INetSharingPortMappingProps_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define INetSharingPortMappingProps_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define INetSharingPortMappingProps_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define INetSharingPortMappingProps_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define INetSharingPortMappingProps_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define INetSharingPortMappingProps_get_Name(This,pbstrName)	\
    ( (This)->lpVtbl -> get_Name(This,pbstrName) ) 

#define INetSharingPortMappingProps_get_IPProtocol(This,pucIPProt)	\
    ( (This)->lpVtbl -> get_IPProtocol(This,pucIPProt) ) 

#define INetSharingPortMappingProps_get_ExternalPort(This,pusPort)	\
    ( (This)->lpVtbl -> get_ExternalPort(This,pusPort) ) 

#define INetSharingPortMappingProps_get_InternalPort(This,pusPort)	\
    ( (This)->lpVtbl -> get_InternalPort(This,pusPort) ) 

#define INetSharingPortMappingProps_get_Options(This,pdwOptions)	\
    ( (This)->lpVtbl -> get_Options(This,pdwOptions) ) 

#define INetSharingPortMappingProps_get_TargetName(This,pbstrTargetName)	\
    ( (This)->lpVtbl -> get_TargetName(This,pbstrTargetName) ) 

#define INetSharingPortMappingProps_get_TargetIPAddress(This,pbstrTargetIPAddress)	\
    ( (This)->lpVtbl -> get_TargetIPAddress(This,pbstrTargetIPAddress) ) 

#define INetSharingPortMappingProps_get_Enabled(This,pbool)	\
    ( (This)->lpVtbl -> get_Enabled(This,pbool) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __INetSharingPortMappingProps_INTERFACE_DEFINED__ */


#ifndef __INetSharingPortMapping_INTERFACE_DEFINED__
#define __INetSharingPortMapping_INTERFACE_DEFINED__

/* interface INetSharingPortMapping */
/* [unique][dual][oleautomation][uuid][object] */ 


EXTERN_C const IID IID_INetSharingPortMapping;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C08956B1-1CD3-11D1-B1C5-00805FC1270E")
    INetSharingPortMapping : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Disable( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Enable( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Properties( 
            /* [annotation][retval][out] */ 
            _Out_retval_  INetSharingPortMappingProps **ppNSPMP) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Delete( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct INetSharingPortMappingVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in INetSharingPortMapping * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in INetSharingPortMapping * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in INetSharingPortMapping * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in INetSharingPortMapping * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in INetSharingPortMapping * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in INetSharingPortMapping * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][size_is][in] */ 
            _In_reads_(cNames)  LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cNames)  DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            INetSharingPortMapping * This,
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
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Disable )( 
            __RPC__in INetSharingPortMapping * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Enable )( 
            __RPC__in INetSharingPortMapping * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Properties )( 
            __RPC__in INetSharingPortMapping * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  INetSharingPortMappingProps **ppNSPMP);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            __RPC__in INetSharingPortMapping * This);
        
        END_INTERFACE
    } INetSharingPortMappingVtbl;

    interface INetSharingPortMapping
    {
        CONST_VTBL struct INetSharingPortMappingVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INetSharingPortMapping_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define INetSharingPortMapping_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define INetSharingPortMapping_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define INetSharingPortMapping_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define INetSharingPortMapping_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define INetSharingPortMapping_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define INetSharingPortMapping_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define INetSharingPortMapping_Disable(This)	\
    ( (This)->lpVtbl -> Disable(This) ) 

#define INetSharingPortMapping_Enable(This)	\
    ( (This)->lpVtbl -> Enable(This) ) 

#define INetSharingPortMapping_get_Properties(This,ppNSPMP)	\
    ( (This)->lpVtbl -> get_Properties(This,ppNSPMP) ) 

#define INetSharingPortMapping_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __INetSharingPortMapping_INTERFACE_DEFINED__ */


#ifndef __IEnumNetSharingEveryConnection_INTERFACE_DEFINED__
#define __IEnumNetSharingEveryConnection_INTERFACE_DEFINED__

/* interface IEnumNetSharingEveryConnection */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IEnumNetSharingEveryConnection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C08956B8-1CD3-11D1-B1C5-00805FC1270E")
    IEnumNetSharingEveryConnection : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [annotation][in] */ 
            _In_  ULONG celt,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(celt,*pceltFetched)  VARIANT *rgVar,
            /* [annotation][out] */ 
            _Out_  ULONG *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [annotation][in] */ 
            _In_  ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [annotation][out] */ 
            _Out_  IEnumNetSharingEveryConnection **ppenum) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IEnumNetSharingEveryConnectionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IEnumNetSharingEveryConnection * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IEnumNetSharingEveryConnection * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IEnumNetSharingEveryConnection * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            __RPC__in IEnumNetSharingEveryConnection * This,
            /* [annotation][in] */ 
            _In_  ULONG celt,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(celt,*pceltFetched)  VARIANT *rgVar,
            /* [annotation][out] */ 
            _Out_  ULONG *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            __RPC__in IEnumNetSharingEveryConnection * This,
            /* [annotation][in] */ 
            _In_  ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            __RPC__in IEnumNetSharingEveryConnection * This);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            __RPC__in IEnumNetSharingEveryConnection * This,
            /* [annotation][out] */ 
            _Out_  IEnumNetSharingEveryConnection **ppenum);
        
        END_INTERFACE
    } IEnumNetSharingEveryConnectionVtbl;

    interface IEnumNetSharingEveryConnection
    {
        CONST_VTBL struct IEnumNetSharingEveryConnectionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumNetSharingEveryConnection_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEnumNetSharingEveryConnection_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEnumNetSharingEveryConnection_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IEnumNetSharingEveryConnection_Next(This,celt,rgVar,pceltFetched)	\
    ( (This)->lpVtbl -> Next(This,celt,rgVar,pceltFetched) ) 

#define IEnumNetSharingEveryConnection_Skip(This,celt)	\
    ( (This)->lpVtbl -> Skip(This,celt) ) 

#define IEnumNetSharingEveryConnection_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define IEnumNetSharingEveryConnection_Clone(This,ppenum)	\
    ( (This)->lpVtbl -> Clone(This,ppenum) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IEnumNetSharingEveryConnection_INTERFACE_DEFINED__ */


#ifndef __IEnumNetSharingPublicConnection_INTERFACE_DEFINED__
#define __IEnumNetSharingPublicConnection_INTERFACE_DEFINED__

/* interface IEnumNetSharingPublicConnection */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IEnumNetSharingPublicConnection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C08956B4-1CD3-11D1-B1C5-00805FC1270E")
    IEnumNetSharingPublicConnection : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [annotation][in] */ 
            _In_  ULONG celt,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(celt,*pceltFetched)  VARIANT *rgVar,
            /* [annotation][out] */ 
            _Out_  ULONG *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [annotation][in] */ 
            _In_  ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [annotation][out] */ 
            _Out_  IEnumNetSharingPublicConnection **ppenum) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IEnumNetSharingPublicConnectionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IEnumNetSharingPublicConnection * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IEnumNetSharingPublicConnection * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IEnumNetSharingPublicConnection * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            __RPC__in IEnumNetSharingPublicConnection * This,
            /* [annotation][in] */ 
            _In_  ULONG celt,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(celt,*pceltFetched)  VARIANT *rgVar,
            /* [annotation][out] */ 
            _Out_  ULONG *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            __RPC__in IEnumNetSharingPublicConnection * This,
            /* [annotation][in] */ 
            _In_  ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            __RPC__in IEnumNetSharingPublicConnection * This);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            __RPC__in IEnumNetSharingPublicConnection * This,
            /* [annotation][out] */ 
            _Out_  IEnumNetSharingPublicConnection **ppenum);
        
        END_INTERFACE
    } IEnumNetSharingPublicConnectionVtbl;

    interface IEnumNetSharingPublicConnection
    {
        CONST_VTBL struct IEnumNetSharingPublicConnectionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumNetSharingPublicConnection_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEnumNetSharingPublicConnection_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEnumNetSharingPublicConnection_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IEnumNetSharingPublicConnection_Next(This,celt,rgVar,pceltFetched)	\
    ( (This)->lpVtbl -> Next(This,celt,rgVar,pceltFetched) ) 

#define IEnumNetSharingPublicConnection_Skip(This,celt)	\
    ( (This)->lpVtbl -> Skip(This,celt) ) 

#define IEnumNetSharingPublicConnection_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define IEnumNetSharingPublicConnection_Clone(This,ppenum)	\
    ( (This)->lpVtbl -> Clone(This,ppenum) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IEnumNetSharingPublicConnection_INTERFACE_DEFINED__ */


#ifndef __IEnumNetSharingPrivateConnection_INTERFACE_DEFINED__
#define __IEnumNetSharingPrivateConnection_INTERFACE_DEFINED__

/* interface IEnumNetSharingPrivateConnection */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IEnumNetSharingPrivateConnection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C08956B5-1CD3-11D1-B1C5-00805FC1270E")
    IEnumNetSharingPrivateConnection : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [annotation][in] */ 
            _In_  ULONG celt,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(celt,*pCeltFetched)  VARIANT *rgVar,
            /* [annotation][out] */ 
            _Out_  ULONG *pCeltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [annotation][in] */ 
            _In_  ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [annotation][out] */ 
            _Out_  IEnumNetSharingPrivateConnection **ppenum) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IEnumNetSharingPrivateConnectionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IEnumNetSharingPrivateConnection * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IEnumNetSharingPrivateConnection * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IEnumNetSharingPrivateConnection * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            __RPC__in IEnumNetSharingPrivateConnection * This,
            /* [annotation][in] */ 
            _In_  ULONG celt,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(celt,*pCeltFetched)  VARIANT *rgVar,
            /* [annotation][out] */ 
            _Out_  ULONG *pCeltFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            __RPC__in IEnumNetSharingPrivateConnection * This,
            /* [annotation][in] */ 
            _In_  ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            __RPC__in IEnumNetSharingPrivateConnection * This);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            __RPC__in IEnumNetSharingPrivateConnection * This,
            /* [annotation][out] */ 
            _Out_  IEnumNetSharingPrivateConnection **ppenum);
        
        END_INTERFACE
    } IEnumNetSharingPrivateConnectionVtbl;

    interface IEnumNetSharingPrivateConnection
    {
        CONST_VTBL struct IEnumNetSharingPrivateConnectionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumNetSharingPrivateConnection_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEnumNetSharingPrivateConnection_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEnumNetSharingPrivateConnection_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IEnumNetSharingPrivateConnection_Next(This,celt,rgVar,pCeltFetched)	\
    ( (This)->lpVtbl -> Next(This,celt,rgVar,pCeltFetched) ) 

#define IEnumNetSharingPrivateConnection_Skip(This,celt)	\
    ( (This)->lpVtbl -> Skip(This,celt) ) 

#define IEnumNetSharingPrivateConnection_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define IEnumNetSharingPrivateConnection_Clone(This,ppenum)	\
    ( (This)->lpVtbl -> Clone(This,ppenum) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IEnumNetSharingPrivateConnection_INTERFACE_DEFINED__ */


#ifndef __INetSharingPortMappingCollection_INTERFACE_DEFINED__
#define __INetSharingPortMappingCollection_INTERFACE_DEFINED__

/* interface INetSharingPortMappingCollection */
/* [unique][helpstring][dual][oleautomation][uuid][object] */ 


EXTERN_C const IID IID_INetSharingPortMappingCollection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("02E4A2DE-DA20-4E34-89C8-AC22275A010B")
    INetSharingPortMappingCollection : public IDispatch
    {
    public:
        virtual /* [helpstring][restricted][id][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IUnknown **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [annotation][retval][out] */ 
            _Out_retval_  long *pVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct INetSharingPortMappingCollectionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in INetSharingPortMappingCollection * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in INetSharingPortMappingCollection * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in INetSharingPortMappingCollection * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in INetSharingPortMappingCollection * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in INetSharingPortMappingCollection * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in INetSharingPortMappingCollection * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][size_is][in] */ 
            _In_reads_(cNames)  LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cNames)  DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            INetSharingPortMappingCollection * This,
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
        
        /* [helpstring][restricted][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            __RPC__in INetSharingPortMappingCollection * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IUnknown **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            __RPC__in INetSharingPortMappingCollection * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *pVal);
        
        END_INTERFACE
    } INetSharingPortMappingCollectionVtbl;

    interface INetSharingPortMappingCollection
    {
        CONST_VTBL struct INetSharingPortMappingCollectionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INetSharingPortMappingCollection_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define INetSharingPortMappingCollection_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define INetSharingPortMappingCollection_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define INetSharingPortMappingCollection_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define INetSharingPortMappingCollection_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define INetSharingPortMappingCollection_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define INetSharingPortMappingCollection_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define INetSharingPortMappingCollection_get__NewEnum(This,pVal)	\
    ( (This)->lpVtbl -> get__NewEnum(This,pVal) ) 

#define INetSharingPortMappingCollection_get_Count(This,pVal)	\
    ( (This)->lpVtbl -> get_Count(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __INetSharingPortMappingCollection_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_netcon_0000_0011 */
/* [local] */ 

// properties for INetConnection (wraps NETCON_PROPERTIES)


extern RPC_IF_HANDLE __MIDL_itf_netcon_0000_0011_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_netcon_0000_0011_v0_0_s_ifspec;

#ifndef __INetConnectionProps_INTERFACE_DEFINED__
#define __INetConnectionProps_INTERFACE_DEFINED__

/* interface INetConnectionProps */
/* [unique][helpstring][dual][oleautomation][uuid][object] */ 


EXTERN_C const IID IID_INetConnectionProps;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F4277C95-CE5B-463D-8167-5662D9BCAA72")
    INetConnectionProps : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Guid( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrGuid) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrName) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DeviceName( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrDeviceName) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Status( 
            /* [annotation][retval][out] */ 
            _Out_retval_  NETCON_STATUS *pStatus) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MediaType( 
            /* [annotation][retval][out] */ 
            _Out_retval_  NETCON_MEDIATYPE *pMediaType) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Characteristics( 
            /* [annotation][retval][out] */ 
            _Out_retval_  DWORD *pdwFlags) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct INetConnectionPropsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in INetConnectionProps * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in INetConnectionProps * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in INetConnectionProps * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in INetConnectionProps * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in INetConnectionProps * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in INetConnectionProps * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][size_is][in] */ 
            _In_reads_(cNames)  LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cNames)  DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            INetConnectionProps * This,
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
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Guid )( 
            __RPC__in INetConnectionProps * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrGuid);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            __RPC__in INetConnectionProps * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrName);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DeviceName )( 
            __RPC__in INetConnectionProps * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrDeviceName);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Status )( 
            __RPC__in INetConnectionProps * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  NETCON_STATUS *pStatus);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MediaType )( 
            __RPC__in INetConnectionProps * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  NETCON_MEDIATYPE *pMediaType);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Characteristics )( 
            __RPC__in INetConnectionProps * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  DWORD *pdwFlags);
        
        END_INTERFACE
    } INetConnectionPropsVtbl;

    interface INetConnectionProps
    {
        CONST_VTBL struct INetConnectionPropsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INetConnectionProps_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define INetConnectionProps_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define INetConnectionProps_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define INetConnectionProps_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define INetConnectionProps_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define INetConnectionProps_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define INetConnectionProps_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define INetConnectionProps_get_Guid(This,pbstrGuid)	\
    ( (This)->lpVtbl -> get_Guid(This,pbstrGuid) ) 

#define INetConnectionProps_get_Name(This,pbstrName)	\
    ( (This)->lpVtbl -> get_Name(This,pbstrName) ) 

#define INetConnectionProps_get_DeviceName(This,pbstrDeviceName)	\
    ( (This)->lpVtbl -> get_DeviceName(This,pbstrDeviceName) ) 

#define INetConnectionProps_get_Status(This,pStatus)	\
    ( (This)->lpVtbl -> get_Status(This,pStatus) ) 

#define INetConnectionProps_get_MediaType(This,pMediaType)	\
    ( (This)->lpVtbl -> get_MediaType(This,pMediaType) ) 

#define INetConnectionProps_get_Characteristics(This,pdwFlags)	\
    ( (This)->lpVtbl -> get_Characteristics(This,pdwFlags) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __INetConnectionProps_INTERFACE_DEFINED__ */


#ifndef __INetSharingConfiguration_INTERFACE_DEFINED__
#define __INetSharingConfiguration_INTERFACE_DEFINED__

/* interface INetSharingConfiguration */
/* [unique][dual][oleautomation][uuid][object] */ 

typedef 
enum tagSHARINGCONNECTIONTYPE
    {
        ICSSHARINGTYPE_PUBLIC	= 0,
        ICSSHARINGTYPE_PRIVATE	= ( ICSSHARINGTYPE_PUBLIC + 1 ) 
    } 	SHARINGCONNECTIONTYPE;

typedef enum tagSHARINGCONNECTIONTYPE *LPSHARINGCONNECTIONTYPE;

typedef 
enum tagSHARINGCONNECTION_ENUM_FLAGS
    {
        ICSSC_DEFAULT	= 0,
        ICSSC_ENABLED	= ( ICSSC_DEFAULT + 1 ) 
    } 	SHARINGCONNECTION_ENUM_FLAGS;

typedef 
enum tagICS_TARGETTYPE
    {
        ICSTT_NAME	= 0,
        ICSTT_IPADDRESS	= ( ICSTT_NAME + 1 ) 
    } 	ICS_TARGETTYPE;


EXTERN_C const IID IID_INetSharingConfiguration;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C08956B6-1CD3-11D1-B1C5-00805FC1270E")
    INetSharingConfiguration : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SharingEnabled( 
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pbEnabled) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SharingConnectionType( 
            /* [annotation][retval][out] */ 
            _Out_retval_  SHARINGCONNECTIONTYPE *pType) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DisableSharing( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EnableSharing( 
            /* [annotation][in] */ 
            _In_  SHARINGCONNECTIONTYPE Type) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_InternetFirewallEnabled( 
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pbEnabled) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DisableInternetFirewall( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EnableInternetFirewall( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EnumPortMappings( 
            /* [annotation][in] */ 
            _In_  SHARINGCONNECTION_ENUM_FLAGS Flags,
            /* [annotation][retval][out] */ 
            _Out_retval_  INetSharingPortMappingCollection **ppColl) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddPortMapping( 
            /* [annotation][in] */ 
            _In_  BSTR bstrName,
            /* [annotation][in] */ 
            _In_  UCHAR ucIPProtocol,
            /* [annotation][in] */ 
            _In_  USHORT usExternalPort,
            /* [annotation][in] */ 
            _In_  USHORT usInternalPort,
            /* [annotation][in] */ 
            _In_  DWORD dwOptions,
            /* [annotation][in] */ 
            _In_  BSTR bstrTargetNameOrIPAddress,
            /* [annotation][in] */ 
            _In_  ICS_TARGETTYPE eTargetType,
            /* [annotation][retval][out] */ 
            _Out_retval_  INetSharingPortMapping **ppMapping) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RemovePortMapping( 
            /* [annotation][in] */ 
            _In_  INetSharingPortMapping *pMapping) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct INetSharingConfigurationVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in INetSharingConfiguration * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in INetSharingConfiguration * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in INetSharingConfiguration * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in INetSharingConfiguration * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in INetSharingConfiguration * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in INetSharingConfiguration * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][size_is][in] */ 
            _In_reads_(cNames)  LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cNames)  DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            INetSharingConfiguration * This,
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
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SharingEnabled )( 
            __RPC__in INetSharingConfiguration * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pbEnabled);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SharingConnectionType )( 
            __RPC__in INetSharingConfiguration * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  SHARINGCONNECTIONTYPE *pType);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DisableSharing )( 
            __RPC__in INetSharingConfiguration * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EnableSharing )( 
            __RPC__in INetSharingConfiguration * This,
            /* [annotation][in] */ 
            _In_  SHARINGCONNECTIONTYPE Type);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InternetFirewallEnabled )( 
            __RPC__in INetSharingConfiguration * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pbEnabled);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DisableInternetFirewall )( 
            __RPC__in INetSharingConfiguration * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EnableInternetFirewall )( 
            __RPC__in INetSharingConfiguration * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnumPortMappings )( 
            __RPC__in INetSharingConfiguration * This,
            /* [annotation][in] */ 
            _In_  SHARINGCONNECTION_ENUM_FLAGS Flags,
            /* [annotation][retval][out] */ 
            _Out_retval_  INetSharingPortMappingCollection **ppColl);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddPortMapping )( 
            __RPC__in INetSharingConfiguration * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrName,
            /* [annotation][in] */ 
            _In_  UCHAR ucIPProtocol,
            /* [annotation][in] */ 
            _In_  USHORT usExternalPort,
            /* [annotation][in] */ 
            _In_  USHORT usInternalPort,
            /* [annotation][in] */ 
            _In_  DWORD dwOptions,
            /* [annotation][in] */ 
            _In_  BSTR bstrTargetNameOrIPAddress,
            /* [annotation][in] */ 
            _In_  ICS_TARGETTYPE eTargetType,
            /* [annotation][retval][out] */ 
            _Out_retval_  INetSharingPortMapping **ppMapping);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RemovePortMapping )( 
            __RPC__in INetSharingConfiguration * This,
            /* [annotation][in] */ 
            _In_  INetSharingPortMapping *pMapping);
        
        END_INTERFACE
    } INetSharingConfigurationVtbl;

    interface INetSharingConfiguration
    {
        CONST_VTBL struct INetSharingConfigurationVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INetSharingConfiguration_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define INetSharingConfiguration_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define INetSharingConfiguration_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define INetSharingConfiguration_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define INetSharingConfiguration_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define INetSharingConfiguration_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define INetSharingConfiguration_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define INetSharingConfiguration_get_SharingEnabled(This,pbEnabled)	\
    ( (This)->lpVtbl -> get_SharingEnabled(This,pbEnabled) ) 

#define INetSharingConfiguration_get_SharingConnectionType(This,pType)	\
    ( (This)->lpVtbl -> get_SharingConnectionType(This,pType) ) 

#define INetSharingConfiguration_DisableSharing(This)	\
    ( (This)->lpVtbl -> DisableSharing(This) ) 

#define INetSharingConfiguration_EnableSharing(This,Type)	\
    ( (This)->lpVtbl -> EnableSharing(This,Type) ) 

#define INetSharingConfiguration_get_InternetFirewallEnabled(This,pbEnabled)	\
    ( (This)->lpVtbl -> get_InternetFirewallEnabled(This,pbEnabled) ) 

#define INetSharingConfiguration_DisableInternetFirewall(This)	\
    ( (This)->lpVtbl -> DisableInternetFirewall(This) ) 

#define INetSharingConfiguration_EnableInternetFirewall(This)	\
    ( (This)->lpVtbl -> EnableInternetFirewall(This) ) 

#define INetSharingConfiguration_get_EnumPortMappings(This,Flags,ppColl)	\
    ( (This)->lpVtbl -> get_EnumPortMappings(This,Flags,ppColl) ) 

#define INetSharingConfiguration_AddPortMapping(This,bstrName,ucIPProtocol,usExternalPort,usInternalPort,dwOptions,bstrTargetNameOrIPAddress,eTargetType,ppMapping)	\
    ( (This)->lpVtbl -> AddPortMapping(This,bstrName,ucIPProtocol,usExternalPort,usInternalPort,dwOptions,bstrTargetNameOrIPAddress,eTargetType,ppMapping) ) 

#define INetSharingConfiguration_RemovePortMapping(This,pMapping)	\
    ( (This)->lpVtbl -> RemovePortMapping(This,pMapping) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __INetSharingConfiguration_INTERFACE_DEFINED__ */


#ifndef __INetSharingEveryConnectionCollection_INTERFACE_DEFINED__
#define __INetSharingEveryConnectionCollection_INTERFACE_DEFINED__

/* interface INetSharingEveryConnectionCollection */
/* [unique][helpstring][dual][oleautomation][uuid][object] */ 


EXTERN_C const IID IID_INetSharingEveryConnectionCollection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("33C4643C-7811-46FA-A89A-768597BD7223")
    INetSharingEveryConnectionCollection : public IDispatch
    {
    public:
        virtual /* [helpstring][restricted][id][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IUnknown **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [annotation][retval][out] */ 
            _Out_retval_  long *pVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct INetSharingEveryConnectionCollectionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in INetSharingEveryConnectionCollection * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in INetSharingEveryConnectionCollection * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in INetSharingEveryConnectionCollection * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in INetSharingEveryConnectionCollection * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in INetSharingEveryConnectionCollection * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in INetSharingEveryConnectionCollection * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][size_is][in] */ 
            _In_reads_(cNames)  LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cNames)  DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            INetSharingEveryConnectionCollection * This,
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
        
        /* [helpstring][restricted][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            __RPC__in INetSharingEveryConnectionCollection * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IUnknown **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            __RPC__in INetSharingEveryConnectionCollection * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *pVal);
        
        END_INTERFACE
    } INetSharingEveryConnectionCollectionVtbl;

    interface INetSharingEveryConnectionCollection
    {
        CONST_VTBL struct INetSharingEveryConnectionCollectionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INetSharingEveryConnectionCollection_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define INetSharingEveryConnectionCollection_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define INetSharingEveryConnectionCollection_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define INetSharingEveryConnectionCollection_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define INetSharingEveryConnectionCollection_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define INetSharingEveryConnectionCollection_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define INetSharingEveryConnectionCollection_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define INetSharingEveryConnectionCollection_get__NewEnum(This,pVal)	\
    ( (This)->lpVtbl -> get__NewEnum(This,pVal) ) 

#define INetSharingEveryConnectionCollection_get_Count(This,pVal)	\
    ( (This)->lpVtbl -> get_Count(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __INetSharingEveryConnectionCollection_INTERFACE_DEFINED__ */


#ifndef __INetSharingPublicConnectionCollection_INTERFACE_DEFINED__
#define __INetSharingPublicConnectionCollection_INTERFACE_DEFINED__

/* interface INetSharingPublicConnectionCollection */
/* [unique][helpstring][dual][oleautomation][uuid][object] */ 


EXTERN_C const IID IID_INetSharingPublicConnectionCollection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7D7A6355-F372-4971-A149-BFC927BE762A")
    INetSharingPublicConnectionCollection : public IDispatch
    {
    public:
        virtual /* [helpstring][restricted][id][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IUnknown **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [annotation][retval][out] */ 
            _Out_retval_  long *pVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct INetSharingPublicConnectionCollectionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in INetSharingPublicConnectionCollection * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in INetSharingPublicConnectionCollection * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in INetSharingPublicConnectionCollection * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in INetSharingPublicConnectionCollection * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in INetSharingPublicConnectionCollection * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in INetSharingPublicConnectionCollection * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][size_is][in] */ 
            _In_reads_(cNames)  LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cNames)  DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            INetSharingPublicConnectionCollection * This,
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
        
        /* [helpstring][restricted][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            __RPC__in INetSharingPublicConnectionCollection * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IUnknown **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            __RPC__in INetSharingPublicConnectionCollection * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *pVal);
        
        END_INTERFACE
    } INetSharingPublicConnectionCollectionVtbl;

    interface INetSharingPublicConnectionCollection
    {
        CONST_VTBL struct INetSharingPublicConnectionCollectionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INetSharingPublicConnectionCollection_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define INetSharingPublicConnectionCollection_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define INetSharingPublicConnectionCollection_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define INetSharingPublicConnectionCollection_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define INetSharingPublicConnectionCollection_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define INetSharingPublicConnectionCollection_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define INetSharingPublicConnectionCollection_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define INetSharingPublicConnectionCollection_get__NewEnum(This,pVal)	\
    ( (This)->lpVtbl -> get__NewEnum(This,pVal) ) 

#define INetSharingPublicConnectionCollection_get_Count(This,pVal)	\
    ( (This)->lpVtbl -> get_Count(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __INetSharingPublicConnectionCollection_INTERFACE_DEFINED__ */


#ifndef __INetSharingPrivateConnectionCollection_INTERFACE_DEFINED__
#define __INetSharingPrivateConnectionCollection_INTERFACE_DEFINED__

/* interface INetSharingPrivateConnectionCollection */
/* [unique][helpstring][dual][oleautomation][uuid][object] */ 


EXTERN_C const IID IID_INetSharingPrivateConnectionCollection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("38AE69E0-4409-402A-A2CB-E965C727F840")
    INetSharingPrivateConnectionCollection : public IDispatch
    {
    public:
        virtual /* [helpstring][restricted][id][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IUnknown **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [annotation][retval][out] */ 
            _Out_retval_  long *pVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct INetSharingPrivateConnectionCollectionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in INetSharingPrivateConnectionCollection * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in INetSharingPrivateConnectionCollection * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in INetSharingPrivateConnectionCollection * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in INetSharingPrivateConnectionCollection * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in INetSharingPrivateConnectionCollection * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in INetSharingPrivateConnectionCollection * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][size_is][in] */ 
            _In_reads_(cNames)  LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cNames)  DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            INetSharingPrivateConnectionCollection * This,
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
        
        /* [helpstring][restricted][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            __RPC__in INetSharingPrivateConnectionCollection * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IUnknown **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            __RPC__in INetSharingPrivateConnectionCollection * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *pVal);
        
        END_INTERFACE
    } INetSharingPrivateConnectionCollectionVtbl;

    interface INetSharingPrivateConnectionCollection
    {
        CONST_VTBL struct INetSharingPrivateConnectionCollectionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INetSharingPrivateConnectionCollection_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define INetSharingPrivateConnectionCollection_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define INetSharingPrivateConnectionCollection_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define INetSharingPrivateConnectionCollection_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define INetSharingPrivateConnectionCollection_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define INetSharingPrivateConnectionCollection_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define INetSharingPrivateConnectionCollection_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define INetSharingPrivateConnectionCollection_get__NewEnum(This,pVal)	\
    ( (This)->lpVtbl -> get__NewEnum(This,pVal) ) 

#define INetSharingPrivateConnectionCollection_get_Count(This,pVal)	\
    ( (This)->lpVtbl -> get_Count(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __INetSharingPrivateConnectionCollection_INTERFACE_DEFINED__ */


#ifndef __INetSharingManager_INTERFACE_DEFINED__
#define __INetSharingManager_INTERFACE_DEFINED__

/* interface INetSharingManager */
/* [unique][dual][oleautomation][uuid][object] */ 


EXTERN_C const IID IID_INetSharingManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C08956B7-1CD3-11D1-B1C5-00805FC1270E")
    INetSharingManager : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SharingInstalled( 
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pbInstalled) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EnumPublicConnections( 
            /* [annotation][in] */ 
            _In_  SHARINGCONNECTION_ENUM_FLAGS Flags,
            /* [annotation][retval][out] */ 
            _Out_retval_  INetSharingPublicConnectionCollection **ppColl) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EnumPrivateConnections( 
            /* [annotation][in] */ 
            _In_  SHARINGCONNECTION_ENUM_FLAGS Flags,
            /* [annotation][retval][out] */ 
            _Out_retval_  INetSharingPrivateConnectionCollection **ppColl) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_INetSharingConfigurationForINetConnection( 
            /* [annotation][in] */ 
            _In_  INetConnection *pNetConnection,
            /* [annotation][retval][out] */ 
            _Out_retval_  INetSharingConfiguration **ppNetSharingConfiguration) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EnumEveryConnection( 
            /* [annotation][retval][out] */ 
            _Out_retval_  INetSharingEveryConnectionCollection **ppColl) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_NetConnectionProps( 
            /* [annotation][in] */ 
            _In_  INetConnection *pNetConnection,
            /* [annotation][retval][out] */ 
            _Out_retval_  INetConnectionProps **ppProps) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct INetSharingManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in INetSharingManager * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in INetSharingManager * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in INetSharingManager * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in INetSharingManager * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in INetSharingManager * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in INetSharingManager * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][size_is][in] */ 
            _In_reads_(cNames)  LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cNames)  DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            INetSharingManager * This,
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
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SharingInstalled )( 
            __RPC__in INetSharingManager * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pbInstalled);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnumPublicConnections )( 
            __RPC__in INetSharingManager * This,
            /* [annotation][in] */ 
            _In_  SHARINGCONNECTION_ENUM_FLAGS Flags,
            /* [annotation][retval][out] */ 
            _Out_retval_  INetSharingPublicConnectionCollection **ppColl);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnumPrivateConnections )( 
            __RPC__in INetSharingManager * This,
            /* [annotation][in] */ 
            _In_  SHARINGCONNECTION_ENUM_FLAGS Flags,
            /* [annotation][retval][out] */ 
            _Out_retval_  INetSharingPrivateConnectionCollection **ppColl);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_INetSharingConfigurationForINetConnection )( 
            __RPC__in INetSharingManager * This,
            /* [annotation][in] */ 
            _In_  INetConnection *pNetConnection,
            /* [annotation][retval][out] */ 
            _Out_retval_  INetSharingConfiguration **ppNetSharingConfiguration);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnumEveryConnection )( 
            __RPC__in INetSharingManager * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  INetSharingEveryConnectionCollection **ppColl);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NetConnectionProps )( 
            __RPC__in INetSharingManager * This,
            /* [annotation][in] */ 
            _In_  INetConnection *pNetConnection,
            /* [annotation][retval][out] */ 
            _Out_retval_  INetConnectionProps **ppProps);
        
        END_INTERFACE
    } INetSharingManagerVtbl;

    interface INetSharingManager
    {
        CONST_VTBL struct INetSharingManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INetSharingManager_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define INetSharingManager_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define INetSharingManager_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define INetSharingManager_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define INetSharingManager_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define INetSharingManager_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define INetSharingManager_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define INetSharingManager_get_SharingInstalled(This,pbInstalled)	\
    ( (This)->lpVtbl -> get_SharingInstalled(This,pbInstalled) ) 

#define INetSharingManager_get_EnumPublicConnections(This,Flags,ppColl)	\
    ( (This)->lpVtbl -> get_EnumPublicConnections(This,Flags,ppColl) ) 

#define INetSharingManager_get_EnumPrivateConnections(This,Flags,ppColl)	\
    ( (This)->lpVtbl -> get_EnumPrivateConnections(This,Flags,ppColl) ) 

#define INetSharingManager_get_INetSharingConfigurationForINetConnection(This,pNetConnection,ppNetSharingConfiguration)	\
    ( (This)->lpVtbl -> get_INetSharingConfigurationForINetConnection(This,pNetConnection,ppNetSharingConfiguration) ) 

#define INetSharingManager_get_EnumEveryConnection(This,ppColl)	\
    ( (This)->lpVtbl -> get_EnumEveryConnection(This,ppColl) ) 

#define INetSharingManager_get_NetConnectionProps(This,pNetConnection,ppProps)	\
    ( (This)->lpVtbl -> get_NetConnectionProps(This,pNetConnection,ppProps) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __INetSharingManager_INTERFACE_DEFINED__ */



#ifndef __NETCONLib_LIBRARY_DEFINED__
#define __NETCONLib_LIBRARY_DEFINED__

/* library NETCONLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_NETCONLib;

EXTERN_C const CLSID CLSID_NetSharingManager;

#ifdef __cplusplus

class DECLSPEC_UUID("5C63C1AD-3956-4FF8-8486-40034758315B")
NetSharingManager;
#endif
#endif /* __NETCONLib_LIBRARY_DEFINED__ */

/* interface __MIDL_itf_netcon_0000_0018 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_netcon_0000_0018_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_netcon_0000_0018_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     __RPC__in unsigned long *, unsigned long            , __RPC__in BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     __RPC__in unsigned long *, __RPC__in BSTR * ); 

unsigned long             __RPC_USER  HWND_UserSize(     __RPC__in unsigned long *, unsigned long            , __RPC__in HWND * ); 
unsigned char * __RPC_USER  HWND_UserMarshal(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in HWND * ); 
unsigned char * __RPC_USER  HWND_UserUnmarshal(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out HWND * ); 
void                      __RPC_USER  HWND_UserFree(     __RPC__in unsigned long *, __RPC__in HWND * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     __RPC__in unsigned long *, unsigned long            , __RPC__in VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree(     __RPC__in unsigned long *, __RPC__in VARIANT * ); 

unsigned long             __RPC_USER  BSTR_UserSize64(     __RPC__in unsigned long *, unsigned long            , __RPC__in BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal64(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal64(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out BSTR * ); 
void                      __RPC_USER  BSTR_UserFree64(     __RPC__in unsigned long *, __RPC__in BSTR * ); 

unsigned long             __RPC_USER  HWND_UserSize64(     __RPC__in unsigned long *, unsigned long            , __RPC__in HWND * ); 
unsigned char * __RPC_USER  HWND_UserMarshal64(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in HWND * ); 
unsigned char * __RPC_USER  HWND_UserUnmarshal64(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out HWND * ); 
void                      __RPC_USER  HWND_UserFree64(     __RPC__in unsigned long *, __RPC__in HWND * ); 

unsigned long             __RPC_USER  VARIANT_UserSize64(     __RPC__in unsigned long *, unsigned long            , __RPC__in VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal64(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal64(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree64(     __RPC__in unsigned long *, __RPC__in VARIANT * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


