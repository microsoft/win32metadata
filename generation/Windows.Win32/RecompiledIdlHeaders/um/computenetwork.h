// computenetwork.ext: ApiSet Contract for ext-ms-win-hyperv-computenetwork-l1
// Copyright (c) Microsoft Corporation. All rights reserved.

#pragma once

#ifndef HCN_CLIENT_H
#define HCN_CLIENT_H

#include <apiset.h>
#include <apisetcconv.h>
#include <minwindef.h>

#pragma region Desktop Family or OneCore Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////////////////
/// Notifications

/// Notifications indicated to callbacks 
typedef enum HCN_NOTIFICATIONS
{
       HcnNotificationInvalid                         = 0x00000000,

       /// Notifications for HCN_SERVICE handles
       HcnNotificationNetworkPreCreate                = 0x00000001,
       HcnNotificationNetworkCreate                   = 0x00000002,
       HcnNotificationNetworkPreDelete                = 0x00000003,
       HcnNotificationNetworkDelete                   = 0x00000004,
       // Namespace Notifications
       HcnNotificationNamespaceCreate                 = 0x00000005,
       HcnNotificationNamespaceDelete                 = 0x00000006,

       /// Common notifications
       HcnNotificationServiceDisconnect               = 0x01000000,

       /// The upper 4 bits are reserved for flags
       HcnNotificationFlagsReserved                   = 0xF0000000
} HCN_NOTIFICATIONS;

/// Handle to a callback registered on a hns object
typedef void* HCN_CALLBACK;

/// Function type for HNS notification callbacks
typedef void (CALLBACK *HCN_NOTIFICATION_CALLBACK)(
    _In_            DWORD  NotificationType,
    _In_opt_        void*  Context,
    _In_            HRESULT NotificationStatus,
    _In_opt_        PCWSTR NotificationData
    );

/////////////////////////////////////////////////////////////////////////
/// Hcn Networks

/// Context handle referencing a Network in HNS
typedef void*           HCN_NETWORK;
typedef HCN_NETWORK*    PHCN_NETWORK;

/// Return a list of existing Networks
HRESULT
WINAPI
HcnEnumerateNetworks(
    _In_ PCWSTR Query,
    _Outptr_ PWSTR* Networks,
    _Outptr_opt_ PWSTR* ErrorRecord
    );


/// Create a Network
HRESULT
WINAPI
HcnCreateNetwork(
    _In_ REFGUID Id,
    _In_ PCWSTR Settings,
    _Out_ PHCN_NETWORK Network,
    _Outptr_opt_ PWSTR* ErrorRecord
    );


/// Lookup an existing network
HRESULT
WINAPI
HcnOpenNetwork(
    _In_ REFGUID Id,
    _Out_ PHCN_NETWORK Network,
    _Outptr_opt_ PWSTR* ErrorRecord
    );


/// Modify the settings of a Network
HRESULT
WINAPI
HcnModifyNetwork(
    _In_ HCN_NETWORK Network,
    _In_ PCWSTR Settings,
    _Outptr_opt_ PWSTR* ErrorRecord
    );


/// Query Network settings
HRESULT
WINAPI
HcnQueryNetworkProperties(
    _In_ HCN_NETWORK Network,
    _In_ PCWSTR Query,
    _Outptr_ PWSTR* Properties,
    _Outptr_opt_ PWSTR* ErrorRecord
    );


/// Delete a Network
HRESULT
WINAPI
HcnDeleteNetwork(
    _In_ REFGUID Id,
    _Outptr_opt_ PWSTR* ErrorRecord
    );


/// Close a handle to a Network
HRESULT
WINAPI
HcnCloseNetwork(
    _In_ HCN_NETWORK Network
    );


/////////////////////////////////////////////////////////////////////////
/// Hcn Namespace

/// Context handle referencing a Namespace in HNS
typedef void*           HCN_NAMESPACE;
typedef HCN_NAMESPACE*  PHCN_NAMESPACE;

/// Return a list of existing Namespaces
HRESULT
WINAPI
HcnEnumerateNamespaces(
    _In_ PCWSTR Query,
    _Outptr_ PWSTR* Namespaces,
    _Outptr_opt_ PWSTR* ErrorRecord
    );


/// Create a Namespace
HRESULT
WINAPI
HcnCreateNamespace(
    _In_ REFGUID Id,
    _In_ PCWSTR Settings,
    _Out_ PHCN_NAMESPACE Namespace,
    _Outptr_opt_ PWSTR* ErrorRecord
    );


/// Lookup an existing Namespace
HRESULT
WINAPI
HcnOpenNamespace(
    _In_ REFGUID Id,
    _Out_ PHCN_NAMESPACE Namespace,
    _Outptr_opt_ PWSTR* ErrorRecord
    );


/// Modify the settings of a Namespace
HRESULT
WINAPI
HcnModifyNamespace(
    _In_ HCN_NAMESPACE Namespace,
    _In_ PCWSTR Settings,
    _Outptr_opt_ PWSTR* ErrorRecord
    );


/// Query Namespace settings
HRESULT
WINAPI
HcnQueryNamespaceProperties(
    _In_ HCN_NAMESPACE Namespace,
    _In_ PCWSTR Query,
    _Outptr_ PWSTR* Properties,
    _Outptr_opt_ PWSTR* ErrorRecord
    );


/// Delete a Namespace
HRESULT
WINAPI
HcnDeleteNamespace(
    _In_ REFGUID Id,
    _Outptr_opt_ PWSTR* ErrorRecord
    );


/// Close a handle to a Namespace
HRESULT
WINAPI
HcnCloseNamespace(
    _In_ HCN_NAMESPACE Namespace
    );


/////////////////////////////////////////////////////////////////////////
/// Hcn Endpoint

/// Context handle referencing an Endpoint in HNS
typedef void*           HCN_ENDPOINT;
typedef HCN_ENDPOINT*   PHCN_ENDPOINT;

/// Return a list of existing Endpoints
HRESULT
WINAPI
HcnEnumerateEndpoints(
    _In_ PCWSTR Query,
    _Outptr_ PWSTR* Endpoints,
    _Outptr_opt_ PWSTR* ErrorRecord
    );


/// Create an Endpoint
HRESULT
WINAPI
HcnCreateEndpoint(
    _In_ HCN_NETWORK Network,
    _In_ REFGUID Id,
    _In_ PCWSTR Settings,
    _Out_ PHCN_ENDPOINT Endpoint,
    _Outptr_opt_ PWSTR* ErrorRecord
    );


/// Lookup an existing Endpoint
HRESULT
WINAPI
HcnOpenEndpoint(
    _In_ REFGUID Id,
    _Out_ PHCN_ENDPOINT Endpoint,
    _Outptr_opt_ PWSTR* ErrorRecord
    );


/// Modify the settings of an Endpoint
HRESULT
WINAPI
HcnModifyEndpoint(
    _In_ HCN_ENDPOINT Endpoint,
    _In_ PCWSTR Settings,
    _Outptr_opt_ PWSTR* ErrorRecord
    );


/// Query Endpoint properties
HRESULT
WINAPI
HcnQueryEndpointProperties(
    _In_ HCN_ENDPOINT Endpoint,
    _In_ PCWSTR Query,
    _Outptr_ PWSTR* Properties,
    _Outptr_opt_ PWSTR* ErrorRecord
    );


/// Delete an Endpoint
HRESULT
WINAPI
HcnDeleteEndpoint(
    _In_ REFGUID Id,
    _Outptr_opt_ PWSTR* ErrorRecord
    );


/// Close a handle to an Endpoint
HRESULT
WINAPI
HcnCloseEndpoint(
    _In_ HCN_ENDPOINT Endpoint
    );


/////////////////////////////////////////////////////////////////////////
/// Hcn LoadBalancer

/// Context handle referencing a LoadBalancer in HNS
typedef void*               HCN_LOADBALANCER;
typedef HCN_LOADBALANCER*     PHCN_LOADBALANCER;

/// Return a list of existing LoadBalancers
HRESULT
WINAPI
HcnEnumerateLoadBalancers(
    _In_ PCWSTR Query,
    _Outptr_ PWSTR* LoadBalancer,
    _Outptr_opt_ PWSTR* ErrorRecord
    );


/// Create a LoadBalancer
HRESULT
WINAPI
HcnCreateLoadBalancer(
    _In_ REFGUID Id,
    _In_ PCWSTR Settings,
    _Out_ PHCN_LOADBALANCER LoadBalancer,
    _Outptr_opt_ PWSTR* ErrorRecord
    );


/// Lookup an existing LoadBalancer
HRESULT
WINAPI
HcnOpenLoadBalancer(
    _In_ REFGUID Id,
    _Out_ PHCN_LOADBALANCER LoadBalancer,
    _Outptr_opt_ PWSTR* ErrorRecord
    );


/// Modify the settings of a PolcyList
HRESULT
WINAPI
HcnModifyLoadBalancer(
    _In_ HCN_LOADBALANCER LoadBalancer,
    _In_ PCWSTR Settings,
    _Outptr_opt_ PWSTR* ErrorRecord
    );


/// Query PolcyList settings
HRESULT
WINAPI
HcnQueryLoadBalancerProperties(
    _In_ HCN_LOADBALANCER LoadBalancer,
    _In_ PCWSTR Query,
    _Outptr_ PWSTR* Properties,
    _Outptr_opt_ PWSTR* ErrorRecord
    );


/// Delete a LoadBalancer
HRESULT
WINAPI
HcnDeleteLoadBalancer(
    _In_ REFGUID Id,
    _Outptr_opt_ PWSTR* ErrorRecord
    );


/// Close a handle to a LoadBalancer
HRESULT
WINAPI
HcnCloseLoadBalancer(
    _In_ HCN_LOADBALANCER LoadBalancer
    );


/////////////////////////////////////////////////////////////////////////
/// Hcn Service

/// Context handle referencing the HNS service
typedef void* HCN_SERVICE;
typedef HCN_SERVICE* PHCN_SERVICE;

/// Registers a callback function to receive notifications of service-wide events
HRESULT
WINAPI
HcnRegisterServiceCallback(
    _In_ HCN_NOTIFICATION_CALLBACK Callback,
    _In_ void* Context,
    _Outptr_ HCN_CALLBACK* CallbackHandle
    );


/// Unregisters from service-wide notifications
HRESULT
WINAPI
HcnUnregisterServiceCallback(
    _In_ HCN_CALLBACK CallbackHandle
    );


#ifdef __cplusplus
}
#endif

#endif // WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)
#pragma endregion

#endif


#ifndef ext_ms_win_hyperv_computenetwork_l1_1_0_query_routines
#define ext_ms_win_hyperv_computenetwork_l1_1_0_query_routines



//
//Private Extension API Query Routines
//

#ifdef __cplusplus
extern "C" {
#endif

BOOLEAN
__stdcall
IsHcnEnumerateNetworksPresent(
    VOID
    );

BOOLEAN
__stdcall
IsHcnCreateNetworkPresent(
    VOID
    );

BOOLEAN
__stdcall
IsHcnOpenNetworkPresent(
    VOID
    );

BOOLEAN
__stdcall
IsHcnModifyNetworkPresent(
    VOID
    );

BOOLEAN
__stdcall
IsHcnQueryNetworkPropertiesPresent(
    VOID
    );

BOOLEAN
__stdcall
IsHcnDeleteNetworkPresent(
    VOID
    );

BOOLEAN
__stdcall
IsHcnCloseNetworkPresent(
    VOID
    );

BOOLEAN
__stdcall
IsHcnEnumerateNamespacesPresent(
    VOID
    );

BOOLEAN
__stdcall
IsHcnCreateNamespacePresent(
    VOID
    );

BOOLEAN
__stdcall
IsHcnOpenNamespacePresent(
    VOID
    );

BOOLEAN
__stdcall
IsHcnModifyNamespacePresent(
    VOID
    );

BOOLEAN
__stdcall
IsHcnQueryNamespacePropertiesPresent(
    VOID
    );

BOOLEAN
__stdcall
IsHcnDeleteNamespacePresent(
    VOID
    );

BOOLEAN
__stdcall
IsHcnCloseNamespacePresent(
    VOID
    );

BOOLEAN
__stdcall
IsHcnEnumerateEndpointsPresent(
    VOID
    );

BOOLEAN
__stdcall
IsHcnCreateEndpointPresent(
    VOID
    );

BOOLEAN
__stdcall
IsHcnOpenEndpointPresent(
    VOID
    );

BOOLEAN
__stdcall
IsHcnModifyEndpointPresent(
    VOID
    );

BOOLEAN
__stdcall
IsHcnQueryEndpointPropertiesPresent(
    VOID
    );

BOOLEAN
__stdcall
IsHcnDeleteEndpointPresent(
    VOID
    );

BOOLEAN
__stdcall
IsHcnCloseEndpointPresent(
    VOID
    );

BOOLEAN
__stdcall
IsHcnEnumerateLoadBalancersPresent(
    VOID
    );

BOOLEAN
__stdcall
IsHcnCreateLoadBalancerPresent(
    VOID
    );

BOOLEAN
__stdcall
IsHcnOpenLoadBalancerPresent(
    VOID
    );

BOOLEAN
__stdcall
IsHcnModifyLoadBalancerPresent(
    VOID
    );

BOOLEAN
__stdcall
IsHcnQueryLoadBalancerPropertiesPresent(
    VOID
    );

BOOLEAN
__stdcall
IsHcnDeleteLoadBalancerPresent(
    VOID
    );

BOOLEAN
__stdcall
IsHcnCloseLoadBalancerPresent(
    VOID
    );

BOOLEAN
__stdcall
IsHcnRegisterServiceCallbackPresent(
    VOID
    );

BOOLEAN
__stdcall
IsHcnUnregisterServiceCallbackPresent(
    VOID
    );

#ifdef __cplusplus
}
#endif

#endif // endof guard

