

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

#ifndef __tssbx_h__
#define __tssbx_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IWTSSBPlugin_FWD_DEFINED__
#define __IWTSSBPlugin_FWD_DEFINED__
typedef interface IWTSSBPlugin IWTSSBPlugin;

#endif 	/* __IWTSSBPlugin_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_tssbx_0000_0000 */
/* [local] */ 

#include <winapifamily.h>
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)

#define PLUGIN_CAPABILITY_EXTERNAL_REDIRECTION 0x1



extern RPC_IF_HANDLE __MIDL_itf_tssbx_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_tssbx_0000_0000_v0_0_s_ifspec;

#ifndef __IWTSSBPlugin_INTERFACE_DEFINED__
#define __IWTSSBPlugin_INTERFACE_DEFINED__

/* interface IWTSSBPlugin */
/* [helpstring][uuid][object] */ 

#define	MaxFQDN_Len	( 256 )

#define	MaxNetBiosName_Len	( 16 )

#define	MaxNumOfExposed_IPs	( 12 )

#define	MaxUserName_Len	( 104 )

#define	MaxDomainName_Len	( 256 )

#define	MaxFarm_Len	( 256 )

#define	MaxAppName_Len	( 256 )

typedef /* [public][public][public] */ 
enum __MIDL_IWTSSBPlugin_0001
    {
        WTSSBX_MACHINE_DRAIN_UNSPEC	= 0,
        WTSSBX_MACHINE_DRAIN_OFF	= 0x1,
        WTSSBX_MACHINE_DRAIN_ON	= 0x2
    } 	WTSSBX_MACHINE_DRAIN;

typedef /* [public][public][public] */ 
enum __MIDL_IWTSSBPlugin_0002
    {
        WTSSBX_MACHINE_SESSION_MODE_UNSPEC	= 0,
        WTSSBX_MACHINE_SESSION_MODE_SINGLE	= 0x1,
        WTSSBX_MACHINE_SESSION_MODE_MULTIPLE	= 0x2
    } 	WTSSBX_MACHINE_SESSION_MODE;

typedef /* [public][public][public][public][public][public][public][public] */ 
enum __MIDL_IWTSSBPlugin_0003
    {
        WTSSBX_ADDRESS_FAMILY_AF_UNSPEC	= 0,
        WTSSBX_ADDRESS_FAMILY_AF_INET	= 0x1,
        WTSSBX_ADDRESS_FAMILY_AF_INET6	= 0x2,
        WTSSBX_ADDRESS_FAMILY_AF_IPX	= 0x3,
        WTSSBX_ADDRESS_FAMILY_AF_NETBIOS	= 0x4
    } 	WTSSBX_ADDRESS_FAMILY;

typedef /* [public][public][public][public][public][public][public][public] */ struct __MIDL_IWTSSBPlugin_0004
    {
    WTSSBX_ADDRESS_FAMILY AddressFamily;
    BYTE Address[ 16 ];
    unsigned short PortNumber;
    DWORD dwScope;
    } 	WTSSBX_IP_ADDRESS;

typedef /* [public][public][public] */ 
enum __MIDL_IWTSSBPlugin_0005
    {
        WTSSBX_MACHINE_STATE_UNSPEC	= 0,
        WTSSBX_MACHINE_STATE_READY	= 0x1,
        WTSSBX_MACHINE_STATE_SYNCHRONIZING	= 0x2
    } 	WTSSBX_MACHINE_STATE;

typedef /* [public][public][public][public] */ struct __MIDL_IWTSSBPlugin_0006
    {
    WCHAR wczMachineFQDN[ 257 ];
    WCHAR wczMachineNetBiosName[ 17 ];
    DWORD dwNumOfIPAddr;
    WTSSBX_IP_ADDRESS IPaddr[ 12 ];
    } 	WTSSBX_MACHINE_CONNECT_INFO;

typedef /* [public][public] */ struct __MIDL_IWTSSBPlugin_0007
    {
    WTSSBX_MACHINE_CONNECT_INFO ClientConnectInfo;
    WCHAR wczFarmName[ 257 ];
    WTSSBX_IP_ADDRESS InternalIPAddress;
    DWORD dwMaxSessionsLimit;
    DWORD ServerWeight;
    WTSSBX_MACHINE_SESSION_MODE SingleSessionMode;
    WTSSBX_MACHINE_DRAIN InDrain;
    WTSSBX_MACHINE_STATE MachineState;
    } 	WTSSBX_MACHINE_INFO;

typedef /* [public][public][public] */ 
enum __MIDL_IWTSSBPlugin_0008
    {
        WTSSBX_SESSION_STATE_UNSPEC	= 0,
        WTSSBX_SESSION_STATE_ACTIVE	= 0x1,
        WTSSBX_SESSION_STATE_DISCONNECTED	= 0x2
    } 	WTSSBX_SESSION_STATE;

typedef /* [public][public] */ struct __MIDL_IWTSSBPlugin_0009
    {
    WCHAR wszUserName[ 105 ];
    WCHAR wszDomainName[ 257 ];
    WCHAR ApplicationType[ 257 ];
    DWORD dwSessionId;
    FILETIME CreateTime;
    FILETIME DisconnectTime;
    WTSSBX_SESSION_STATE SessionState;
    } 	WTSSBX_SESSION_INFO;

typedef /* [public][public][public] */ 
enum __MIDL_IWTSSBPlugin_0010
    {
        WTSSBX_NOTIFICATION_REMOVED	= 0x1,
        WTSSBX_NOTIFICATION_CHANGED	= 0x2,
        WTSSBX_NOTIFICATION_ADDED	= 0x4,
        WTSSBX_NOTIFICATION_RESYNC	= 0x8
    } 	WTSSBX_NOTIFICATION_TYPE;


EXTERN_C const IID IID_IWTSSBPlugin;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DC44BE78-B18D-4399-B210-641BF67A002C")
    IWTSSBPlugin : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Initialize( 
            /* [annotation][out] */ 
            _Out_  DWORD *PluginCapabilities) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE WTSSBX_MachineChangeNotification( 
            /* [annotation][in] */ 
            _In_  WTSSBX_NOTIFICATION_TYPE NotificationType,
            /* [annotation][in] */ 
            _In_  long MachineId,
            /* [annotation][in] */ 
            _In_  WTSSBX_MACHINE_INFO *pMachineInfo) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE WTSSBX_SessionChangeNotification( 
            /* [annotation][in] */ 
            _In_  WTSSBX_NOTIFICATION_TYPE NotificationType,
            /* [annotation][in] */ 
            _In_  long MachineId,
            /* [annotation][in] */ 
            _In_  DWORD NumOfSessions,
            /* [annotation][size_is][in] */ 
            _In_reads_(NumOfSessions)  WTSSBX_SESSION_INFO SessionInfo[  ]) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE WTSSBX_GetMostSuitableServer( 
            /* [annotation][string][in] */ 
            _In_  WCHAR *UserName,
            /* [annotation][string][in] */ 
            _In_  WCHAR *DomainName,
            /* [annotation][string][in] */ 
            _In_  WCHAR *ApplicationType,
            /* [annotation][string][in] */ 
            _In_  WCHAR *FarmName,
            /* [annotation][out][in] */ 
            _Inout_  long *pMachineId) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Terminated( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE WTSSBX_GetUserExternalSession( 
            /* [annotation][string][in] */ 
            _In_  WCHAR *UserName,
            /* [annotation][string][in] */ 
            _In_  WCHAR *DomainName,
            /* [annotation][string][in] */ 
            _In_  WCHAR *ApplicationType,
            /* [annotation][in] */ 
            _In_  WTSSBX_IP_ADDRESS *RedirectorInternalIP,
            /* [annotation][out] */ 
            _Out_  DWORD *pSessionId,
            /* [annotation][out] */ 
            _Out_  WTSSBX_MACHINE_CONNECT_INFO *pMachineConnectInfo) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWTSSBPluginVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IWTSSBPlugin * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IWTSSBPlugin * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IWTSSBPlugin * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            __RPC__in IWTSSBPlugin * This,
            /* [annotation][out] */ 
            _Out_  DWORD *PluginCapabilities);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *WTSSBX_MachineChangeNotification )( 
            __RPC__in IWTSSBPlugin * This,
            /* [annotation][in] */ 
            _In_  WTSSBX_NOTIFICATION_TYPE NotificationType,
            /* [annotation][in] */ 
            _In_  long MachineId,
            /* [annotation][in] */ 
            _In_  WTSSBX_MACHINE_INFO *pMachineInfo);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *WTSSBX_SessionChangeNotification )( 
            __RPC__in IWTSSBPlugin * This,
            /* [annotation][in] */ 
            _In_  WTSSBX_NOTIFICATION_TYPE NotificationType,
            /* [annotation][in] */ 
            _In_  long MachineId,
            /* [annotation][in] */ 
            _In_  DWORD NumOfSessions,
            /* [annotation][size_is][in] */ 
            _In_reads_(NumOfSessions)  WTSSBX_SESSION_INFO SessionInfo[  ]);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *WTSSBX_GetMostSuitableServer )( 
            __RPC__in IWTSSBPlugin * This,
            /* [annotation][string][in] */ 
            _In_  WCHAR *UserName,
            /* [annotation][string][in] */ 
            _In_  WCHAR *DomainName,
            /* [annotation][string][in] */ 
            _In_  WCHAR *ApplicationType,
            /* [annotation][string][in] */ 
            _In_  WCHAR *FarmName,
            /* [annotation][out][in] */ 
            _Inout_  long *pMachineId);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Terminated )( 
            __RPC__in IWTSSBPlugin * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *WTSSBX_GetUserExternalSession )( 
            __RPC__in IWTSSBPlugin * This,
            /* [annotation][string][in] */ 
            _In_  WCHAR *UserName,
            /* [annotation][string][in] */ 
            _In_  WCHAR *DomainName,
            /* [annotation][string][in] */ 
            _In_  WCHAR *ApplicationType,
            /* [annotation][in] */ 
            _In_  WTSSBX_IP_ADDRESS *RedirectorInternalIP,
            /* [annotation][out] */ 
            _Out_  DWORD *pSessionId,
            /* [annotation][out] */ 
            _Out_  WTSSBX_MACHINE_CONNECT_INFO *pMachineConnectInfo);
        
        END_INTERFACE
    } IWTSSBPluginVtbl;

    interface IWTSSBPlugin
    {
        CONST_VTBL struct IWTSSBPluginVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWTSSBPlugin_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWTSSBPlugin_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWTSSBPlugin_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWTSSBPlugin_Initialize(This,PluginCapabilities)	\
    ( (This)->lpVtbl -> Initialize(This,PluginCapabilities) ) 

#define IWTSSBPlugin_WTSSBX_MachineChangeNotification(This,NotificationType,MachineId,pMachineInfo)	\
    ( (This)->lpVtbl -> WTSSBX_MachineChangeNotification(This,NotificationType,MachineId,pMachineInfo) ) 

#define IWTSSBPlugin_WTSSBX_SessionChangeNotification(This,NotificationType,MachineId,NumOfSessions,SessionInfo)	\
    ( (This)->lpVtbl -> WTSSBX_SessionChangeNotification(This,NotificationType,MachineId,NumOfSessions,SessionInfo) ) 

#define IWTSSBPlugin_WTSSBX_GetMostSuitableServer(This,UserName,DomainName,ApplicationType,FarmName,pMachineId)	\
    ( (This)->lpVtbl -> WTSSBX_GetMostSuitableServer(This,UserName,DomainName,ApplicationType,FarmName,pMachineId) ) 

#define IWTSSBPlugin_Terminated(This)	\
    ( (This)->lpVtbl -> Terminated(This) ) 

#define IWTSSBPlugin_WTSSBX_GetUserExternalSession(This,UserName,DomainName,ApplicationType,RedirectorInternalIP,pSessionId,pMachineConnectInfo)	\
    ( (This)->lpVtbl -> WTSSBX_GetUserExternalSession(This,UserName,DomainName,ApplicationType,RedirectorInternalIP,pSessionId,pMachineConnectInfo) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWTSSBPlugin_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_tssbx_0000_0001 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_tssbx_0000_0001_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_tssbx_0000_0001_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


