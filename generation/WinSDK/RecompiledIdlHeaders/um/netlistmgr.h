

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

#ifndef __netlistmgr_h__
#define __netlistmgr_h__

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

#ifndef __INetworkListManager_FWD_DEFINED__
#define __INetworkListManager_FWD_DEFINED__
typedef interface INetworkListManager INetworkListManager;

#endif 	/* __INetworkListManager_FWD_DEFINED__ */


#ifndef __INetworkListManagerEvents_FWD_DEFINED__
#define __INetworkListManagerEvents_FWD_DEFINED__
typedef interface INetworkListManagerEvents INetworkListManagerEvents;

#endif 	/* __INetworkListManagerEvents_FWD_DEFINED__ */


#ifndef __INetwork_FWD_DEFINED__
#define __INetwork_FWD_DEFINED__
typedef interface INetwork INetwork;

#endif 	/* __INetwork_FWD_DEFINED__ */


#ifndef __IEnumNetworks_FWD_DEFINED__
#define __IEnumNetworks_FWD_DEFINED__
typedef interface IEnumNetworks IEnumNetworks;

#endif 	/* __IEnumNetworks_FWD_DEFINED__ */


#ifndef __INetworkEvents_FWD_DEFINED__
#define __INetworkEvents_FWD_DEFINED__
typedef interface INetworkEvents INetworkEvents;

#endif 	/* __INetworkEvents_FWD_DEFINED__ */


#ifndef __INetworkConnection_FWD_DEFINED__
#define __INetworkConnection_FWD_DEFINED__
typedef interface INetworkConnection INetworkConnection;

#endif 	/* __INetworkConnection_FWD_DEFINED__ */


#ifndef __IEnumNetworkConnections_FWD_DEFINED__
#define __IEnumNetworkConnections_FWD_DEFINED__
typedef interface IEnumNetworkConnections IEnumNetworkConnections;

#endif 	/* __IEnumNetworkConnections_FWD_DEFINED__ */


#ifndef __INetworkConnectionEvents_FWD_DEFINED__
#define __INetworkConnectionEvents_FWD_DEFINED__
typedef interface INetworkConnectionEvents INetworkConnectionEvents;

#endif 	/* __INetworkConnectionEvents_FWD_DEFINED__ */


#ifndef __INetworkCostManager_FWD_DEFINED__
#define __INetworkCostManager_FWD_DEFINED__
typedef interface INetworkCostManager INetworkCostManager;

#endif 	/* __INetworkCostManager_FWD_DEFINED__ */


#ifndef __INetworkCostManagerEvents_FWD_DEFINED__
#define __INetworkCostManagerEvents_FWD_DEFINED__
typedef interface INetworkCostManagerEvents INetworkCostManagerEvents;

#endif 	/* __INetworkCostManagerEvents_FWD_DEFINED__ */


#ifndef __INetworkConnectionCost_FWD_DEFINED__
#define __INetworkConnectionCost_FWD_DEFINED__
typedef interface INetworkConnectionCost INetworkConnectionCost;

#endif 	/* __INetworkConnectionCost_FWD_DEFINED__ */


#ifndef __INetworkConnectionCostEvents_FWD_DEFINED__
#define __INetworkConnectionCostEvents_FWD_DEFINED__
typedef interface INetworkConnectionCostEvents INetworkConnectionCostEvents;

#endif 	/* __INetworkConnectionCostEvents_FWD_DEFINED__ */


#ifndef __INetworkConnectionCost_FWD_DEFINED__
#define __INetworkConnectionCost_FWD_DEFINED__
typedef interface INetworkConnectionCost INetworkConnectionCost;

#endif 	/* __INetworkConnectionCost_FWD_DEFINED__ */


#ifndef __NetworkListManager_FWD_DEFINED__
#define __NetworkListManager_FWD_DEFINED__

#ifdef __cplusplus
typedef class NetworkListManager NetworkListManager;
#else
typedef struct NetworkListManager NetworkListManager;
#endif /* __cplusplus */

#endif 	/* __NetworkListManager_FWD_DEFINED__ */


/* header files for imported files */
#include "unknwn.h"
#include "objidl.h"
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_netlistmgr_0000_0000 */
/* [local] */ 

#include <winapifamily.h>
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)












#define NA_DomainAuthenticationFailed  L"NA_DomainAuthenticationFailed"
#define NA_NetworkClass  L"NA_NetworkClass"
#define NA_NameSetByPolicy  L"NA_NameSetByPolicy"
#define NA_IconSetByPolicy  L"NA_IconSetByPolicy"
#define NA_DescriptionSetByPolicy  L"NA_DescriptionSetByPolicy"
#define NA_CategorySetByPolicy  L"NA_CategorySetByPolicy"
#define NA_NameReadOnly  L"NA_NameReadOnly"
#define NA_IconReadOnly  L"NA_IconReadOnly"
#define NA_DescriptionReadOnly  L"NA_DescriptionReadOnly"
#define NA_CategoryReadOnly  L"NA_CategoryReadOnly"
#define NA_AllowMerge  L"NA_AllowMerge"
#define NA_InternetConnectivityV4 L"NA_InternetConnectivityV4"
#define NA_InternetConnectivityV6 L"NA_InternetConnectivityV6"
#define	NLM_MAX_ADDRESS_LIST_SIZE	( 10 )

#define	NLM_UNKNOWN_DATAPLAN_STATUS	( 0xffffffff )

typedef /* [helpstring][v1_enum][version] */ 
enum NLM_CONNECTION_COST
    {
        NLM_CONNECTION_COST_UNKNOWN	= 0,
        NLM_CONNECTION_COST_UNRESTRICTED	= 0x1,
        NLM_CONNECTION_COST_FIXED	= 0x2,
        NLM_CONNECTION_COST_VARIABLE	= 0x4,
        NLM_CONNECTION_COST_OVERDATALIMIT	= 0x10000,
        NLM_CONNECTION_COST_CONGESTED	= 0x20000,
        NLM_CONNECTION_COST_ROAMING	= 0x40000,
        NLM_CONNECTION_COST_APPROACHINGDATALIMIT	= 0x80000
    } 	NLM_CONNECTION_COST;

typedef /* [helpstring][version] */ struct NLM_USAGE_DATA
    {
    DWORD UsageInMegabytes;
    FILETIME LastSyncTime;
    } 	NLM_USAGE_DATA;

typedef /* [helpstring][version] */ struct NLM_DATAPLAN_STATUS
    {
    GUID InterfaceGuid;
    NLM_USAGE_DATA UsageData;
    DWORD DataLimitInMegabytes;
    DWORD InboundBandwidthInKbps;
    DWORD OutboundBandwidthInKbps;
    FILETIME NextBillingCycle;
    DWORD MaxTransferSizeInMegabytes;
    DWORD Reserved;
    } 	NLM_DATAPLAN_STATUS;

typedef /* [helpstring][version] */ struct NLM_SOCKADDR
    {
    BYTE data[ 128 ];
    } 	NLM_SOCKADDR;

typedef /* [v1_enum] */ 
enum NLM_NETWORK_CLASS
    {
        NLM_NETWORK_IDENTIFYING	= 0x1,
        NLM_NETWORK_IDENTIFIED	= 0x2,
        NLM_NETWORK_UNIDENTIFIED	= 0x3
    } 	NLM_NETWORK_CLASS;

typedef /* [helpstring][version] */ struct NLM_SIMULATED_PROFILE_INFO
    {
    WCHAR ProfileName[ 256 ];
    NLM_CONNECTION_COST cost;
    DWORD UsageInMegabytes;
    DWORD DataLimitInMegabytes;
    } 	NLM_SIMULATED_PROFILE_INFO;

typedef /* [v1_enum] */ 
enum NLM_INTERNET_CONNECTIVITY
    {
        NLM_INTERNET_CONNECTIVITY_WEBHIJACK	= 0x1,
        NLM_INTERNET_CONNECTIVITY_PROXIED	= 0x2,
        NLM_INTERNET_CONNECTIVITY_CORPORATE	= 0x4
    } 	NLM_INTERNET_CONNECTIVITY;

typedef /* [v1_enum] */ 
enum NLM_CONNECTIVITY
    {
        NLM_CONNECTIVITY_DISCONNECTED	= 0,
        NLM_CONNECTIVITY_IPV4_NOTRAFFIC	= 0x1,
        NLM_CONNECTIVITY_IPV6_NOTRAFFIC	= 0x2,
        NLM_CONNECTIVITY_IPV4_SUBNET	= 0x10,
        NLM_CONNECTIVITY_IPV4_LOCALNETWORK	= 0x20,
        NLM_CONNECTIVITY_IPV4_INTERNET	= 0x40,
        NLM_CONNECTIVITY_IPV6_SUBNET	= 0x100,
        NLM_CONNECTIVITY_IPV6_LOCALNETWORK	= 0x200,
        NLM_CONNECTIVITY_IPV6_INTERNET	= 0x400
    } 	NLM_CONNECTIVITY;

typedef 
enum NLM_DOMAIN_TYPE
    {
        NLM_DOMAIN_TYPE_NON_DOMAIN_NETWORK	= 0,
        NLM_DOMAIN_TYPE_DOMAIN_NETWORK	= 0x1,
        NLM_DOMAIN_TYPE_DOMAIN_AUTHENTICATED	= 0x2
    } 	NLM_DOMAIN_TYPE;



extern RPC_IF_HANDLE __MIDL_itf_netlistmgr_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_netlistmgr_0000_0000_v0_0_s_ifspec;

#ifndef __INetworkListManager_INTERFACE_DEFINED__
#define __INetworkListManager_INTERFACE_DEFINED__

/* interface INetworkListManager */
/* [dual][unique][oleautomation][object][helpstring][uuid] */ 

typedef /* [v1_enum] */ 
enum NLM_ENUM_NETWORK
    {
        NLM_ENUM_NETWORK_CONNECTED	= 0x1,
        NLM_ENUM_NETWORK_DISCONNECTED	= 0x2,
        NLM_ENUM_NETWORK_ALL	= 0x3
    } 	NLM_ENUM_NETWORK;


EXTERN_C const IID IID_INetworkListManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DCB00000-570F-4A9B-8D69-199FDBA5723B")
    INetworkListManager : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetNetworks( 
            /* [annotation][in] */ 
            _In_  NLM_ENUM_NETWORK Flags,
            /* [annotation][retval][out] */ 
            _Out_retval_  IEnumNetworks **ppEnumNetwork) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetNetwork( 
            /* [annotation][in] */ 
            _In_  GUID gdNetworkId,
            /* [annotation][retval][out] */ 
            _Out_retval_  INetwork **ppNetwork) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetNetworkConnections( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IEnumNetworkConnections **ppEnum) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetNetworkConnection( 
            /* [annotation][in] */ 
            _In_  GUID gdNetworkConnectionId,
            /* [annotation][retval][out] */ 
            _Out_retval_  INetworkConnection **ppNetworkConnection) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IsConnectedToInternet( 
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pbIsConnected) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IsConnected( 
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pbIsConnected) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetConnectivity( 
            /* [annotation][retval][out] */ 
            _Out_retval_  NLM_CONNECTIVITY *pConnectivity) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetSimulatedProfileInfo( 
            /* [annotation][in] */ 
            _In_  NLM_SIMULATED_PROFILE_INFO *pSimulatedInfo) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ClearSimulatedProfileInfo( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct INetworkListManagerVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in INetworkListManager * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in INetworkListManager * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in INetworkListManager * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in INetworkListManager * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in INetworkListManager * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in INetworkListManager * This,
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
            INetworkListManager * This,
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
        
        DECLSPEC_XFGVIRT(INetworkListManager, GetNetworks)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetNetworks )( 
            __RPC__in INetworkListManager * This,
            /* [annotation][in] */ 
            _In_  NLM_ENUM_NETWORK Flags,
            /* [annotation][retval][out] */ 
            _Out_retval_  IEnumNetworks **ppEnumNetwork);
        
        DECLSPEC_XFGVIRT(INetworkListManager, GetNetwork)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetNetwork )( 
            __RPC__in INetworkListManager * This,
            /* [annotation][in] */ 
            _In_  GUID gdNetworkId,
            /* [annotation][retval][out] */ 
            _Out_retval_  INetwork **ppNetwork);
        
        DECLSPEC_XFGVIRT(INetworkListManager, GetNetworkConnections)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetNetworkConnections )( 
            __RPC__in INetworkListManager * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IEnumNetworkConnections **ppEnum);
        
        DECLSPEC_XFGVIRT(INetworkListManager, GetNetworkConnection)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetNetworkConnection )( 
            __RPC__in INetworkListManager * This,
            /* [annotation][in] */ 
            _In_  GUID gdNetworkConnectionId,
            /* [annotation][retval][out] */ 
            _Out_retval_  INetworkConnection **ppNetworkConnection);
        
        DECLSPEC_XFGVIRT(INetworkListManager, get_IsConnectedToInternet)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsConnectedToInternet )( 
            __RPC__in INetworkListManager * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pbIsConnected);
        
        DECLSPEC_XFGVIRT(INetworkListManager, get_IsConnected)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsConnected )( 
            __RPC__in INetworkListManager * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pbIsConnected);
        
        DECLSPEC_XFGVIRT(INetworkListManager, GetConnectivity)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetConnectivity )( 
            __RPC__in INetworkListManager * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  NLM_CONNECTIVITY *pConnectivity);
        
        DECLSPEC_XFGVIRT(INetworkListManager, SetSimulatedProfileInfo)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetSimulatedProfileInfo )( 
            __RPC__in INetworkListManager * This,
            /* [annotation][in] */ 
            _In_  NLM_SIMULATED_PROFILE_INFO *pSimulatedInfo);
        
        DECLSPEC_XFGVIRT(INetworkListManager, ClearSimulatedProfileInfo)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ClearSimulatedProfileInfo )( 
            __RPC__in INetworkListManager * This);
        
        END_INTERFACE
    } INetworkListManagerVtbl;

    interface INetworkListManager
    {
        CONST_VTBL struct INetworkListManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INetworkListManager_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define INetworkListManager_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define INetworkListManager_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define INetworkListManager_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define INetworkListManager_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define INetworkListManager_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define INetworkListManager_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define INetworkListManager_GetNetworks(This,Flags,ppEnumNetwork)	\
    ( (This)->lpVtbl -> GetNetworks(This,Flags,ppEnumNetwork) ) 

#define INetworkListManager_GetNetwork(This,gdNetworkId,ppNetwork)	\
    ( (This)->lpVtbl -> GetNetwork(This,gdNetworkId,ppNetwork) ) 

#define INetworkListManager_GetNetworkConnections(This,ppEnum)	\
    ( (This)->lpVtbl -> GetNetworkConnections(This,ppEnum) ) 

#define INetworkListManager_GetNetworkConnection(This,gdNetworkConnectionId,ppNetworkConnection)	\
    ( (This)->lpVtbl -> GetNetworkConnection(This,gdNetworkConnectionId,ppNetworkConnection) ) 

#define INetworkListManager_get_IsConnectedToInternet(This,pbIsConnected)	\
    ( (This)->lpVtbl -> get_IsConnectedToInternet(This,pbIsConnected) ) 

#define INetworkListManager_get_IsConnected(This,pbIsConnected)	\
    ( (This)->lpVtbl -> get_IsConnected(This,pbIsConnected) ) 

#define INetworkListManager_GetConnectivity(This,pConnectivity)	\
    ( (This)->lpVtbl -> GetConnectivity(This,pConnectivity) ) 

#define INetworkListManager_SetSimulatedProfileInfo(This,pSimulatedInfo)	\
    ( (This)->lpVtbl -> SetSimulatedProfileInfo(This,pSimulatedInfo) ) 

#define INetworkListManager_ClearSimulatedProfileInfo(This)	\
    ( (This)->lpVtbl -> ClearSimulatedProfileInfo(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __INetworkListManager_INTERFACE_DEFINED__ */


#ifndef __INetworkListManagerEvents_INTERFACE_DEFINED__
#define __INetworkListManagerEvents_INTERFACE_DEFINED__

/* interface INetworkListManagerEvents */
/* [unique][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_INetworkListManagerEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DCB00001-570F-4A9B-8D69-199FDBA5723B")
    INetworkListManagerEvents : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ConnectivityChanged( 
            /* [annotation][in] */ 
            _In_  NLM_CONNECTIVITY newConnectivity) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct INetworkListManagerEventsVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in INetworkListManagerEvents * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in INetworkListManagerEvents * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in INetworkListManagerEvents * This);
        
        DECLSPEC_XFGVIRT(INetworkListManagerEvents, ConnectivityChanged)
        HRESULT ( STDMETHODCALLTYPE *ConnectivityChanged )( 
            __RPC__in INetworkListManagerEvents * This,
            /* [annotation][in] */ 
            _In_  NLM_CONNECTIVITY newConnectivity);
        
        END_INTERFACE
    } INetworkListManagerEventsVtbl;

    interface INetworkListManagerEvents
    {
        CONST_VTBL struct INetworkListManagerEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INetworkListManagerEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define INetworkListManagerEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define INetworkListManagerEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define INetworkListManagerEvents_ConnectivityChanged(This,newConnectivity)	\
    ( (This)->lpVtbl -> ConnectivityChanged(This,newConnectivity) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __INetworkListManagerEvents_INTERFACE_DEFINED__ */


#ifndef __INetwork_INTERFACE_DEFINED__
#define __INetwork_INTERFACE_DEFINED__

/* interface INetwork */
/* [dual][unique][oleautomation][object][helpstring][uuid] */ 

typedef 
enum NLM_NETWORK_CATEGORY
    {
        NLM_NETWORK_CATEGORY_PUBLIC	= 0,
        NLM_NETWORK_CATEGORY_PRIVATE	= 0x1,
        NLM_NETWORK_CATEGORY_DOMAIN_AUTHENTICATED	= 0x2
    } 	NLM_NETWORK_CATEGORY;


EXTERN_C const IID IID_INetwork;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DCB00002-570F-4A9B-8D69-199FDBA5723B")
    INetwork : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetName( 
            /* [annotation][retval][string][out] */ 
            _Out_retval_  BSTR *pszNetworkName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetName( 
            /* [annotation][string][in] */ 
            _In_  BSTR szNetworkNewName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDescription( 
            /* [annotation][retval][string][out] */ 
            _Out_retval_  BSTR *pszDescription) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetDescription( 
            /* [annotation][string][in] */ 
            _In_  BSTR szDescription) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetNetworkId( 
            /* [annotation][retval][out] */ 
            _Out_retval_  GUID *pgdGuidNetworkId) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDomainType( 
            /* [annotation][retval][out] */ 
            _Out_retval_  NLM_DOMAIN_TYPE *pNetworkType) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetNetworkConnections( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IEnumNetworkConnections **ppEnumNetworkConnection) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetTimeCreatedAndConnected( 
            /* [annotation][out] */ 
            _Out_  DWORD *pdwLowDateTimeCreated,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwHighDateTimeCreated,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwLowDateTimeConnected,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwHighDateTimeConnected) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IsConnectedToInternet( 
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pbIsConnected) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IsConnected( 
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pbIsConnected) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetConnectivity( 
            /* [annotation][retval][out] */ 
            _Out_retval_  NLM_CONNECTIVITY *pConnectivity) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCategory( 
            /* [annotation][retval][out] */ 
            _Out_retval_  NLM_NETWORK_CATEGORY *pCategory) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetCategory( 
            /* [annotation][in] */ 
            _In_  NLM_NETWORK_CATEGORY NewCategory) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct INetworkVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in INetwork * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in INetwork * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in INetwork * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in INetwork * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in INetwork * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in INetwork * This,
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
            INetwork * This,
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
        
        DECLSPEC_XFGVIRT(INetwork, GetName)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetName )( 
            __RPC__in INetwork * This,
            /* [annotation][retval][string][out] */ 
            _Out_retval_  BSTR *pszNetworkName);
        
        DECLSPEC_XFGVIRT(INetwork, SetName)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetName )( 
            __RPC__in INetwork * This,
            /* [annotation][string][in] */ 
            _In_  BSTR szNetworkNewName);
        
        DECLSPEC_XFGVIRT(INetwork, GetDescription)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetDescription )( 
            __RPC__in INetwork * This,
            /* [annotation][retval][string][out] */ 
            _Out_retval_  BSTR *pszDescription);
        
        DECLSPEC_XFGVIRT(INetwork, SetDescription)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetDescription )( 
            __RPC__in INetwork * This,
            /* [annotation][string][in] */ 
            _In_  BSTR szDescription);
        
        DECLSPEC_XFGVIRT(INetwork, GetNetworkId)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetNetworkId )( 
            __RPC__in INetwork * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  GUID *pgdGuidNetworkId);
        
        DECLSPEC_XFGVIRT(INetwork, GetDomainType)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetDomainType )( 
            __RPC__in INetwork * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  NLM_DOMAIN_TYPE *pNetworkType);
        
        DECLSPEC_XFGVIRT(INetwork, GetNetworkConnections)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetNetworkConnections )( 
            __RPC__in INetwork * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IEnumNetworkConnections **ppEnumNetworkConnection);
        
        DECLSPEC_XFGVIRT(INetwork, GetTimeCreatedAndConnected)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetTimeCreatedAndConnected )( 
            __RPC__in INetwork * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwLowDateTimeCreated,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwHighDateTimeCreated,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwLowDateTimeConnected,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwHighDateTimeConnected);
        
        DECLSPEC_XFGVIRT(INetwork, get_IsConnectedToInternet)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsConnectedToInternet )( 
            __RPC__in INetwork * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pbIsConnected);
        
        DECLSPEC_XFGVIRT(INetwork, get_IsConnected)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsConnected )( 
            __RPC__in INetwork * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pbIsConnected);
        
        DECLSPEC_XFGVIRT(INetwork, GetConnectivity)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetConnectivity )( 
            __RPC__in INetwork * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  NLM_CONNECTIVITY *pConnectivity);
        
        DECLSPEC_XFGVIRT(INetwork, GetCategory)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetCategory )( 
            __RPC__in INetwork * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  NLM_NETWORK_CATEGORY *pCategory);
        
        DECLSPEC_XFGVIRT(INetwork, SetCategory)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetCategory )( 
            __RPC__in INetwork * This,
            /* [annotation][in] */ 
            _In_  NLM_NETWORK_CATEGORY NewCategory);
        
        END_INTERFACE
    } INetworkVtbl;

    interface INetwork
    {
        CONST_VTBL struct INetworkVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INetwork_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define INetwork_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define INetwork_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define INetwork_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define INetwork_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define INetwork_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define INetwork_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define INetwork_GetName(This,pszNetworkName)	\
    ( (This)->lpVtbl -> GetName(This,pszNetworkName) ) 

#define INetwork_SetName(This,szNetworkNewName)	\
    ( (This)->lpVtbl -> SetName(This,szNetworkNewName) ) 

#define INetwork_GetDescription(This,pszDescription)	\
    ( (This)->lpVtbl -> GetDescription(This,pszDescription) ) 

#define INetwork_SetDescription(This,szDescription)	\
    ( (This)->lpVtbl -> SetDescription(This,szDescription) ) 

#define INetwork_GetNetworkId(This,pgdGuidNetworkId)	\
    ( (This)->lpVtbl -> GetNetworkId(This,pgdGuidNetworkId) ) 

#define INetwork_GetDomainType(This,pNetworkType)	\
    ( (This)->lpVtbl -> GetDomainType(This,pNetworkType) ) 

#define INetwork_GetNetworkConnections(This,ppEnumNetworkConnection)	\
    ( (This)->lpVtbl -> GetNetworkConnections(This,ppEnumNetworkConnection) ) 

#define INetwork_GetTimeCreatedAndConnected(This,pdwLowDateTimeCreated,pdwHighDateTimeCreated,pdwLowDateTimeConnected,pdwHighDateTimeConnected)	\
    ( (This)->lpVtbl -> GetTimeCreatedAndConnected(This,pdwLowDateTimeCreated,pdwHighDateTimeCreated,pdwLowDateTimeConnected,pdwHighDateTimeConnected) ) 

#define INetwork_get_IsConnectedToInternet(This,pbIsConnected)	\
    ( (This)->lpVtbl -> get_IsConnectedToInternet(This,pbIsConnected) ) 

#define INetwork_get_IsConnected(This,pbIsConnected)	\
    ( (This)->lpVtbl -> get_IsConnected(This,pbIsConnected) ) 

#define INetwork_GetConnectivity(This,pConnectivity)	\
    ( (This)->lpVtbl -> GetConnectivity(This,pConnectivity) ) 

#define INetwork_GetCategory(This,pCategory)	\
    ( (This)->lpVtbl -> GetCategory(This,pCategory) ) 

#define INetwork_SetCategory(This,NewCategory)	\
    ( (This)->lpVtbl -> SetCategory(This,NewCategory) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __INetwork_INTERFACE_DEFINED__ */


#ifndef __IEnumNetworks_INTERFACE_DEFINED__
#define __IEnumNetworks_INTERFACE_DEFINED__

/* interface IEnumNetworks */
/* [dual][unique][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_IEnumNetworks;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DCB00003-570F-4A9B-8D69-199FDBA5723B")
    IEnumNetworks : public IDispatch
    {
    public:
        virtual /* [restricted][hidden][propget][id] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IEnumVARIANT **ppEnumVar) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Next( 
            /* [annotation][in] */ 
            _In_  ULONG celt,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(celt,*pceltFetched)  INetwork **rgelt,
            /* [full][out][in] */ __RPC__inout_opt ULONG *pceltFetched) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Skip( 
            /* [annotation][in] */ 
            _In_  ULONG celt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Clone( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IEnumNetworks **ppEnumNetwork) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IEnumNetworksVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IEnumNetworks * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IEnumNetworks * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IEnumNetworks * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IEnumNetworks * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IEnumNetworks * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IEnumNetworks * This,
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
            IEnumNetworks * This,
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
        
        DECLSPEC_XFGVIRT(IEnumNetworks, get__NewEnum)
        /* [restricted][hidden][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            __RPC__in IEnumNetworks * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IEnumVARIANT **ppEnumVar);
        
        DECLSPEC_XFGVIRT(IEnumNetworks, Next)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Next )( 
            __RPC__in IEnumNetworks * This,
            /* [annotation][in] */ 
            _In_  ULONG celt,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(celt,*pceltFetched)  INetwork **rgelt,
            /* [full][out][in] */ __RPC__inout_opt ULONG *pceltFetched);
        
        DECLSPEC_XFGVIRT(IEnumNetworks, Skip)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Skip )( 
            __RPC__in IEnumNetworks * This,
            /* [annotation][in] */ 
            _In_  ULONG celt);
        
        DECLSPEC_XFGVIRT(IEnumNetworks, Reset)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Reset )( 
            __RPC__in IEnumNetworks * This);
        
        DECLSPEC_XFGVIRT(IEnumNetworks, Clone)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Clone )( 
            __RPC__in IEnumNetworks * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IEnumNetworks **ppEnumNetwork);
        
        END_INTERFACE
    } IEnumNetworksVtbl;

    interface IEnumNetworks
    {
        CONST_VTBL struct IEnumNetworksVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumNetworks_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEnumNetworks_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEnumNetworks_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IEnumNetworks_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IEnumNetworks_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IEnumNetworks_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IEnumNetworks_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IEnumNetworks_get__NewEnum(This,ppEnumVar)	\
    ( (This)->lpVtbl -> get__NewEnum(This,ppEnumVar) ) 

#define IEnumNetworks_Next(This,celt,rgelt,pceltFetched)	\
    ( (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched) ) 

#define IEnumNetworks_Skip(This,celt)	\
    ( (This)->lpVtbl -> Skip(This,celt) ) 

#define IEnumNetworks_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define IEnumNetworks_Clone(This,ppEnumNetwork)	\
    ( (This)->lpVtbl -> Clone(This,ppEnumNetwork) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IEnumNetworks_INTERFACE_DEFINED__ */


#ifndef __INetworkEvents_INTERFACE_DEFINED__
#define __INetworkEvents_INTERFACE_DEFINED__

/* interface INetworkEvents */
/* [unique][oleautomation][object][helpstring][uuid] */ 

typedef 
enum NLM_NETWORK_PROPERTY_CHANGE
    {
        NLM_NETWORK_PROPERTY_CHANGE_CONNECTION	= 0x1,
        NLM_NETWORK_PROPERTY_CHANGE_DESCRIPTION	= 0x2,
        NLM_NETWORK_PROPERTY_CHANGE_NAME	= 0x4,
        NLM_NETWORK_PROPERTY_CHANGE_ICON	= 0x8,
        NLM_NETWORK_PROPERTY_CHANGE_CATEGORY_VALUE	= 0x10
    } 	NLM_NETWORK_PROPERTY_CHANGE;


EXTERN_C const IID IID_INetworkEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DCB00004-570F-4A9B-8D69-199FDBA5723B")
    INetworkEvents : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE NetworkAdded( 
            /* [annotation][in] */ 
            _In_  GUID networkId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE NetworkDeleted( 
            /* [annotation][in] */ 
            _In_  GUID networkId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE NetworkConnectivityChanged( 
            /* [annotation][in] */ 
            _In_  GUID networkId,
            /* [annotation][in] */ 
            _In_  NLM_CONNECTIVITY newConnectivity) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE NetworkPropertyChanged( 
            /* [annotation][in] */ 
            _In_  GUID networkId,
            /* [annotation][in] */ 
            _In_  NLM_NETWORK_PROPERTY_CHANGE flags) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct INetworkEventsVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in INetworkEvents * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in INetworkEvents * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in INetworkEvents * This);
        
        DECLSPEC_XFGVIRT(INetworkEvents, NetworkAdded)
        HRESULT ( STDMETHODCALLTYPE *NetworkAdded )( 
            __RPC__in INetworkEvents * This,
            /* [annotation][in] */ 
            _In_  GUID networkId);
        
        DECLSPEC_XFGVIRT(INetworkEvents, NetworkDeleted)
        HRESULT ( STDMETHODCALLTYPE *NetworkDeleted )( 
            __RPC__in INetworkEvents * This,
            /* [annotation][in] */ 
            _In_  GUID networkId);
        
        DECLSPEC_XFGVIRT(INetworkEvents, NetworkConnectivityChanged)
        HRESULT ( STDMETHODCALLTYPE *NetworkConnectivityChanged )( 
            __RPC__in INetworkEvents * This,
            /* [annotation][in] */ 
            _In_  GUID networkId,
            /* [annotation][in] */ 
            _In_  NLM_CONNECTIVITY newConnectivity);
        
        DECLSPEC_XFGVIRT(INetworkEvents, NetworkPropertyChanged)
        HRESULT ( STDMETHODCALLTYPE *NetworkPropertyChanged )( 
            __RPC__in INetworkEvents * This,
            /* [annotation][in] */ 
            _In_  GUID networkId,
            /* [annotation][in] */ 
            _In_  NLM_NETWORK_PROPERTY_CHANGE flags);
        
        END_INTERFACE
    } INetworkEventsVtbl;

    interface INetworkEvents
    {
        CONST_VTBL struct INetworkEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INetworkEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define INetworkEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define INetworkEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define INetworkEvents_NetworkAdded(This,networkId)	\
    ( (This)->lpVtbl -> NetworkAdded(This,networkId) ) 

#define INetworkEvents_NetworkDeleted(This,networkId)	\
    ( (This)->lpVtbl -> NetworkDeleted(This,networkId) ) 

#define INetworkEvents_NetworkConnectivityChanged(This,networkId,newConnectivity)	\
    ( (This)->lpVtbl -> NetworkConnectivityChanged(This,networkId,newConnectivity) ) 

#define INetworkEvents_NetworkPropertyChanged(This,networkId,flags)	\
    ( (This)->lpVtbl -> NetworkPropertyChanged(This,networkId,flags) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __INetworkEvents_INTERFACE_DEFINED__ */


#ifndef __INetworkConnection_INTERFACE_DEFINED__
#define __INetworkConnection_INTERFACE_DEFINED__

/* interface INetworkConnection */
/* [dual][unique][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_INetworkConnection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DCB00005-570F-4A9B-8D69-199FDBA5723B")
    INetworkConnection : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetNetwork( 
            /* [annotation][retval][out] */ 
            _Out_retval_  INetwork **ppNetwork) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IsConnectedToInternet( 
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pbIsConnected) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IsConnected( 
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pbIsConnected) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetConnectivity( 
            /* [annotation][retval][out] */ 
            _Out_retval_  NLM_CONNECTIVITY *pConnectivity) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetConnectionId( 
            /* [annotation][retval][out] */ 
            _Out_retval_  GUID *pgdConnectionId) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetAdapterId( 
            /* [annotation][retval][out] */ 
            _Out_retval_  GUID *pgdAdapterId) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDomainType( 
            /* [annotation][retval][out] */ 
            _Out_retval_  NLM_DOMAIN_TYPE *pDomainType) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct INetworkConnectionVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in INetworkConnection * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in INetworkConnection * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in INetworkConnection * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in INetworkConnection * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in INetworkConnection * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in INetworkConnection * This,
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
            INetworkConnection * This,
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
        
        DECLSPEC_XFGVIRT(INetworkConnection, GetNetwork)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetNetwork )( 
            __RPC__in INetworkConnection * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  INetwork **ppNetwork);
        
        DECLSPEC_XFGVIRT(INetworkConnection, get_IsConnectedToInternet)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsConnectedToInternet )( 
            __RPC__in INetworkConnection * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pbIsConnected);
        
        DECLSPEC_XFGVIRT(INetworkConnection, get_IsConnected)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsConnected )( 
            __RPC__in INetworkConnection * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pbIsConnected);
        
        DECLSPEC_XFGVIRT(INetworkConnection, GetConnectivity)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetConnectivity )( 
            __RPC__in INetworkConnection * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  NLM_CONNECTIVITY *pConnectivity);
        
        DECLSPEC_XFGVIRT(INetworkConnection, GetConnectionId)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetConnectionId )( 
            __RPC__in INetworkConnection * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  GUID *pgdConnectionId);
        
        DECLSPEC_XFGVIRT(INetworkConnection, GetAdapterId)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetAdapterId )( 
            __RPC__in INetworkConnection * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  GUID *pgdAdapterId);
        
        DECLSPEC_XFGVIRT(INetworkConnection, GetDomainType)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetDomainType )( 
            __RPC__in INetworkConnection * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  NLM_DOMAIN_TYPE *pDomainType);
        
        END_INTERFACE
    } INetworkConnectionVtbl;

    interface INetworkConnection
    {
        CONST_VTBL struct INetworkConnectionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INetworkConnection_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define INetworkConnection_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define INetworkConnection_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define INetworkConnection_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define INetworkConnection_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define INetworkConnection_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define INetworkConnection_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define INetworkConnection_GetNetwork(This,ppNetwork)	\
    ( (This)->lpVtbl -> GetNetwork(This,ppNetwork) ) 

#define INetworkConnection_get_IsConnectedToInternet(This,pbIsConnected)	\
    ( (This)->lpVtbl -> get_IsConnectedToInternet(This,pbIsConnected) ) 

#define INetworkConnection_get_IsConnected(This,pbIsConnected)	\
    ( (This)->lpVtbl -> get_IsConnected(This,pbIsConnected) ) 

#define INetworkConnection_GetConnectivity(This,pConnectivity)	\
    ( (This)->lpVtbl -> GetConnectivity(This,pConnectivity) ) 

#define INetworkConnection_GetConnectionId(This,pgdConnectionId)	\
    ( (This)->lpVtbl -> GetConnectionId(This,pgdConnectionId) ) 

#define INetworkConnection_GetAdapterId(This,pgdAdapterId)	\
    ( (This)->lpVtbl -> GetAdapterId(This,pgdAdapterId) ) 

#define INetworkConnection_GetDomainType(This,pDomainType)	\
    ( (This)->lpVtbl -> GetDomainType(This,pDomainType) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __INetworkConnection_INTERFACE_DEFINED__ */


#ifndef __IEnumNetworkConnections_INTERFACE_DEFINED__
#define __IEnumNetworkConnections_INTERFACE_DEFINED__

/* interface IEnumNetworkConnections */
/* [dual][unique][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_IEnumNetworkConnections;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DCB00006-570F-4A9B-8D69-199FDBA5723B")
    IEnumNetworkConnections : public IDispatch
    {
    public:
        virtual /* [restricted][hidden][propget][id] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IEnumVARIANT **ppEnumVar) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Next( 
            /* [annotation][in] */ 
            _In_  ULONG celt,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(celt,*pceltFetched)  INetworkConnection **rgelt,
            /* [full][out][in] */ __RPC__inout_opt ULONG *pceltFetched) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Skip( 
            /* [annotation][in] */ 
            _In_  ULONG celt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Clone( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IEnumNetworkConnections **ppEnumNetwork) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IEnumNetworkConnectionsVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IEnumNetworkConnections * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IEnumNetworkConnections * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IEnumNetworkConnections * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IEnumNetworkConnections * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IEnumNetworkConnections * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IEnumNetworkConnections * This,
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
            IEnumNetworkConnections * This,
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
        
        DECLSPEC_XFGVIRT(IEnumNetworkConnections, get__NewEnum)
        /* [restricted][hidden][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            __RPC__in IEnumNetworkConnections * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IEnumVARIANT **ppEnumVar);
        
        DECLSPEC_XFGVIRT(IEnumNetworkConnections, Next)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Next )( 
            __RPC__in IEnumNetworkConnections * This,
            /* [annotation][in] */ 
            _In_  ULONG celt,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(celt,*pceltFetched)  INetworkConnection **rgelt,
            /* [full][out][in] */ __RPC__inout_opt ULONG *pceltFetched);
        
        DECLSPEC_XFGVIRT(IEnumNetworkConnections, Skip)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Skip )( 
            __RPC__in IEnumNetworkConnections * This,
            /* [annotation][in] */ 
            _In_  ULONG celt);
        
        DECLSPEC_XFGVIRT(IEnumNetworkConnections, Reset)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Reset )( 
            __RPC__in IEnumNetworkConnections * This);
        
        DECLSPEC_XFGVIRT(IEnumNetworkConnections, Clone)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Clone )( 
            __RPC__in IEnumNetworkConnections * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IEnumNetworkConnections **ppEnumNetwork);
        
        END_INTERFACE
    } IEnumNetworkConnectionsVtbl;

    interface IEnumNetworkConnections
    {
        CONST_VTBL struct IEnumNetworkConnectionsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumNetworkConnections_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEnumNetworkConnections_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEnumNetworkConnections_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IEnumNetworkConnections_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IEnumNetworkConnections_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IEnumNetworkConnections_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IEnumNetworkConnections_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IEnumNetworkConnections_get__NewEnum(This,ppEnumVar)	\
    ( (This)->lpVtbl -> get__NewEnum(This,ppEnumVar) ) 

#define IEnumNetworkConnections_Next(This,celt,rgelt,pceltFetched)	\
    ( (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched) ) 

#define IEnumNetworkConnections_Skip(This,celt)	\
    ( (This)->lpVtbl -> Skip(This,celt) ) 

#define IEnumNetworkConnections_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define IEnumNetworkConnections_Clone(This,ppEnumNetwork)	\
    ( (This)->lpVtbl -> Clone(This,ppEnumNetwork) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IEnumNetworkConnections_INTERFACE_DEFINED__ */


#ifndef __INetworkConnectionEvents_INTERFACE_DEFINED__
#define __INetworkConnectionEvents_INTERFACE_DEFINED__

/* interface INetworkConnectionEvents */
/* [unique][oleautomation][object][helpstring][uuid] */ 

typedef 
enum NLM_CONNECTION_PROPERTY_CHANGE
    {
        NLM_CONNECTION_PROPERTY_CHANGE_AUTHENTICATION	= 0x1
    } 	NLM_CONNECTION_PROPERTY_CHANGE;


EXTERN_C const IID IID_INetworkConnectionEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DCB00007-570F-4A9B-8D69-199FDBA5723B")
    INetworkConnectionEvents : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE NetworkConnectionConnectivityChanged( 
            /* [annotation][in] */ 
            _In_  GUID connectionId,
            /* [annotation][in] */ 
            _In_  NLM_CONNECTIVITY newConnectivity) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE NetworkConnectionPropertyChanged( 
            /* [annotation][in] */ 
            _In_  GUID connectionId,
            /* [annotation][in] */ 
            _In_  NLM_CONNECTION_PROPERTY_CHANGE flags) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct INetworkConnectionEventsVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in INetworkConnectionEvents * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in INetworkConnectionEvents * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in INetworkConnectionEvents * This);
        
        DECLSPEC_XFGVIRT(INetworkConnectionEvents, NetworkConnectionConnectivityChanged)
        HRESULT ( STDMETHODCALLTYPE *NetworkConnectionConnectivityChanged )( 
            __RPC__in INetworkConnectionEvents * This,
            /* [annotation][in] */ 
            _In_  GUID connectionId,
            /* [annotation][in] */ 
            _In_  NLM_CONNECTIVITY newConnectivity);
        
        DECLSPEC_XFGVIRT(INetworkConnectionEvents, NetworkConnectionPropertyChanged)
        HRESULT ( STDMETHODCALLTYPE *NetworkConnectionPropertyChanged )( 
            __RPC__in INetworkConnectionEvents * This,
            /* [annotation][in] */ 
            _In_  GUID connectionId,
            /* [annotation][in] */ 
            _In_  NLM_CONNECTION_PROPERTY_CHANGE flags);
        
        END_INTERFACE
    } INetworkConnectionEventsVtbl;

    interface INetworkConnectionEvents
    {
        CONST_VTBL struct INetworkConnectionEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INetworkConnectionEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define INetworkConnectionEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define INetworkConnectionEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define INetworkConnectionEvents_NetworkConnectionConnectivityChanged(This,connectionId,newConnectivity)	\
    ( (This)->lpVtbl -> NetworkConnectionConnectivityChanged(This,connectionId,newConnectivity) ) 

#define INetworkConnectionEvents_NetworkConnectionPropertyChanged(This,connectionId,flags)	\
    ( (This)->lpVtbl -> NetworkConnectionPropertyChanged(This,connectionId,flags) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __INetworkConnectionEvents_INTERFACE_DEFINED__ */


#ifndef __INetworkCostManager_INTERFACE_DEFINED__
#define __INetworkCostManager_INTERFACE_DEFINED__

/* interface INetworkCostManager */
/* [unique][object][helpstring][uuid] */ 


EXTERN_C const IID IID_INetworkCostManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DCB00008-570F-4A9B-8D69-199FDBA5723B")
    INetworkCostManager : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCost( 
            /* [annotation][out] */ 
            _Out_  DWORD *pCost,
            /* [annotation][unique][in] */ 
            _In_  NLM_SOCKADDR *pDestIPAddr) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDataPlanStatus( 
            /* [annotation][out] */ 
            _Out_  NLM_DATAPLAN_STATUS *pDataPlanStatus,
            /* [annotation][unique][in] */ 
            _In_  NLM_SOCKADDR *pDestIPAddr) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetDestinationAddresses( 
            /* [range][in] */ __RPC__in_range(0,NLM_MAX_ADDRESS_LIST_SIZE) UINT32 length,
            /* [annotation][unique][size_is][in] */ 
            _In_reads_(length)  NLM_SOCKADDR *pDestIPAddrList,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL bAppend) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct INetworkCostManagerVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in INetworkCostManager * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in INetworkCostManager * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in INetworkCostManager * This);
        
        DECLSPEC_XFGVIRT(INetworkCostManager, GetCost)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetCost )( 
            __RPC__in INetworkCostManager * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pCost,
            /* [annotation][unique][in] */ 
            _In_  NLM_SOCKADDR *pDestIPAddr);
        
        DECLSPEC_XFGVIRT(INetworkCostManager, GetDataPlanStatus)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetDataPlanStatus )( 
            __RPC__in INetworkCostManager * This,
            /* [annotation][out] */ 
            _Out_  NLM_DATAPLAN_STATUS *pDataPlanStatus,
            /* [annotation][unique][in] */ 
            _In_  NLM_SOCKADDR *pDestIPAddr);
        
        DECLSPEC_XFGVIRT(INetworkCostManager, SetDestinationAddresses)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetDestinationAddresses )( 
            __RPC__in INetworkCostManager * This,
            /* [range][in] */ __RPC__in_range(0,NLM_MAX_ADDRESS_LIST_SIZE) UINT32 length,
            /* [annotation][unique][size_is][in] */ 
            _In_reads_(length)  NLM_SOCKADDR *pDestIPAddrList,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL bAppend);
        
        END_INTERFACE
    } INetworkCostManagerVtbl;

    interface INetworkCostManager
    {
        CONST_VTBL struct INetworkCostManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INetworkCostManager_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define INetworkCostManager_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define INetworkCostManager_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define INetworkCostManager_GetCost(This,pCost,pDestIPAddr)	\
    ( (This)->lpVtbl -> GetCost(This,pCost,pDestIPAddr) ) 

#define INetworkCostManager_GetDataPlanStatus(This,pDataPlanStatus,pDestIPAddr)	\
    ( (This)->lpVtbl -> GetDataPlanStatus(This,pDataPlanStatus,pDestIPAddr) ) 

#define INetworkCostManager_SetDestinationAddresses(This,length,pDestIPAddrList,bAppend)	\
    ( (This)->lpVtbl -> SetDestinationAddresses(This,length,pDestIPAddrList,bAppend) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __INetworkCostManager_INTERFACE_DEFINED__ */


#ifndef __INetworkCostManagerEvents_INTERFACE_DEFINED__
#define __INetworkCostManagerEvents_INTERFACE_DEFINED__

/* interface INetworkCostManagerEvents */
/* [unique][object][helpstring][uuid] */ 


EXTERN_C const IID IID_INetworkCostManagerEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DCB00009-570F-4A9B-8D69-199FDBA5723B")
    INetworkCostManagerEvents : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CostChanged( 
            /* [annotation][in] */ 
            _In_  DWORD newCost,
            /* [annotation][unique][in] */ 
            _In_  NLM_SOCKADDR *pDestAddr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DataPlanStatusChanged( 
            /* [annotation][unique][in] */ 
            _In_  NLM_SOCKADDR *pDestAddr) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct INetworkCostManagerEventsVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in INetworkCostManagerEvents * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in INetworkCostManagerEvents * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in INetworkCostManagerEvents * This);
        
        DECLSPEC_XFGVIRT(INetworkCostManagerEvents, CostChanged)
        HRESULT ( STDMETHODCALLTYPE *CostChanged )( 
            __RPC__in INetworkCostManagerEvents * This,
            /* [annotation][in] */ 
            _In_  DWORD newCost,
            /* [annotation][unique][in] */ 
            _In_  NLM_SOCKADDR *pDestAddr);
        
        DECLSPEC_XFGVIRT(INetworkCostManagerEvents, DataPlanStatusChanged)
        HRESULT ( STDMETHODCALLTYPE *DataPlanStatusChanged )( 
            __RPC__in INetworkCostManagerEvents * This,
            /* [annotation][unique][in] */ 
            _In_  NLM_SOCKADDR *pDestAddr);
        
        END_INTERFACE
    } INetworkCostManagerEventsVtbl;

    interface INetworkCostManagerEvents
    {
        CONST_VTBL struct INetworkCostManagerEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INetworkCostManagerEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define INetworkCostManagerEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define INetworkCostManagerEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define INetworkCostManagerEvents_CostChanged(This,newCost,pDestAddr)	\
    ( (This)->lpVtbl -> CostChanged(This,newCost,pDestAddr) ) 

#define INetworkCostManagerEvents_DataPlanStatusChanged(This,pDestAddr)	\
    ( (This)->lpVtbl -> DataPlanStatusChanged(This,pDestAddr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __INetworkCostManagerEvents_INTERFACE_DEFINED__ */


#ifndef __INetworkConnectionCost_INTERFACE_DEFINED__
#define __INetworkConnectionCost_INTERFACE_DEFINED__

/* interface INetworkConnectionCost */
/* [unique][object][helpstring][uuid] */ 


EXTERN_C const IID IID_INetworkConnectionCost;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DCB0000a-570F-4A9B-8D69-199FDBA5723B")
    INetworkConnectionCost : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCost( 
            /* [annotation][out] */ 
            _Out_  DWORD *pCost) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDataPlanStatus( 
            /* [annotation][out] */ 
            _Out_  NLM_DATAPLAN_STATUS *pDataPlanStatus) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct INetworkConnectionCostVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in INetworkConnectionCost * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in INetworkConnectionCost * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in INetworkConnectionCost * This);
        
        DECLSPEC_XFGVIRT(INetworkConnectionCost, GetCost)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetCost )( 
            __RPC__in INetworkConnectionCost * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pCost);
        
        DECLSPEC_XFGVIRT(INetworkConnectionCost, GetDataPlanStatus)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetDataPlanStatus )( 
            __RPC__in INetworkConnectionCost * This,
            /* [annotation][out] */ 
            _Out_  NLM_DATAPLAN_STATUS *pDataPlanStatus);
        
        END_INTERFACE
    } INetworkConnectionCostVtbl;

    interface INetworkConnectionCost
    {
        CONST_VTBL struct INetworkConnectionCostVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INetworkConnectionCost_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define INetworkConnectionCost_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define INetworkConnectionCost_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define INetworkConnectionCost_GetCost(This,pCost)	\
    ( (This)->lpVtbl -> GetCost(This,pCost) ) 

#define INetworkConnectionCost_GetDataPlanStatus(This,pDataPlanStatus)	\
    ( (This)->lpVtbl -> GetDataPlanStatus(This,pDataPlanStatus) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __INetworkConnectionCost_INTERFACE_DEFINED__ */


#ifndef __INetworkConnectionCostEvents_INTERFACE_DEFINED__
#define __INetworkConnectionCostEvents_INTERFACE_DEFINED__

/* interface INetworkConnectionCostEvents */
/* [unique][object][helpstring][uuid] */ 


EXTERN_C const IID IID_INetworkConnectionCostEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DCB0000b-570F-4A9B-8D69-199FDBA5723B")
    INetworkConnectionCostEvents : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ConnectionCostChanged( 
            /* [annotation][in] */ 
            _In_  GUID connectionId,
            /* [annotation][in] */ 
            _In_  DWORD newCost) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ConnectionDataPlanStatusChanged( 
            /* [annotation][in] */ 
            _In_  GUID connectionId) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct INetworkConnectionCostEventsVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in INetworkConnectionCostEvents * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in INetworkConnectionCostEvents * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in INetworkConnectionCostEvents * This);
        
        DECLSPEC_XFGVIRT(INetworkConnectionCostEvents, ConnectionCostChanged)
        HRESULT ( STDMETHODCALLTYPE *ConnectionCostChanged )( 
            __RPC__in INetworkConnectionCostEvents * This,
            /* [annotation][in] */ 
            _In_  GUID connectionId,
            /* [annotation][in] */ 
            _In_  DWORD newCost);
        
        DECLSPEC_XFGVIRT(INetworkConnectionCostEvents, ConnectionDataPlanStatusChanged)
        HRESULT ( STDMETHODCALLTYPE *ConnectionDataPlanStatusChanged )( 
            __RPC__in INetworkConnectionCostEvents * This,
            /* [annotation][in] */ 
            _In_  GUID connectionId);
        
        END_INTERFACE
    } INetworkConnectionCostEventsVtbl;

    interface INetworkConnectionCostEvents
    {
        CONST_VTBL struct INetworkConnectionCostEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INetworkConnectionCostEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define INetworkConnectionCostEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define INetworkConnectionCostEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define INetworkConnectionCostEvents_ConnectionCostChanged(This,connectionId,newCost)	\
    ( (This)->lpVtbl -> ConnectionCostChanged(This,connectionId,newCost) ) 

#define INetworkConnectionCostEvents_ConnectionDataPlanStatusChanged(This,connectionId)	\
    ( (This)->lpVtbl -> ConnectionDataPlanStatusChanged(This,connectionId) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __INetworkConnectionCostEvents_INTERFACE_DEFINED__ */



#ifndef __NETWORKLIST_LIBRARY_DEFINED__
#define __NETWORKLIST_LIBRARY_DEFINED__

/* library NETWORKLIST */
/* [helpstring][version][uuid] */ 




EXTERN_C const IID LIBID_NETWORKLIST;

EXTERN_C const CLSID CLSID_NetworkListManager;

#ifdef __cplusplus

class DECLSPEC_UUID("DCB00C01-570F-4A9B-8D69-199FDBA5723B")
NetworkListManager;
#endif
#endif /* __NETWORKLIST_LIBRARY_DEFINED__ */

/* interface __MIDL_itf_netlistmgr_0000_0013 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_netlistmgr_0000_0013_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_netlistmgr_0000_0013_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     __RPC__in unsigned long *, unsigned long            , __RPC__in BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     __RPC__in unsigned long *, __RPC__in BSTR * ); 

unsigned long             __RPC_USER  BSTR_UserSize64(     __RPC__in unsigned long *, unsigned long            , __RPC__in BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal64(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal64(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out BSTR * ); 
void                      __RPC_USER  BSTR_UserFree64(     __RPC__in unsigned long *, __RPC__in BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


