

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

#ifndef __workspaceruntime_h__
#define __workspaceruntime_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IWorkspace_FWD_DEFINED__
#define __IWorkspace_FWD_DEFINED__
typedef interface IWorkspace IWorkspace;

#endif 	/* __IWorkspace_FWD_DEFINED__ */


#ifndef __IWorkspace2_FWD_DEFINED__
#define __IWorkspace2_FWD_DEFINED__
typedef interface IWorkspace2 IWorkspace2;

#endif 	/* __IWorkspace2_FWD_DEFINED__ */


#ifndef __IWorkspace3_FWD_DEFINED__
#define __IWorkspace3_FWD_DEFINED__
typedef interface IWorkspace3 IWorkspace3;

#endif 	/* __IWorkspace3_FWD_DEFINED__ */


#ifndef __IWorkspaceRegistration_FWD_DEFINED__
#define __IWorkspaceRegistration_FWD_DEFINED__
typedef interface IWorkspaceRegistration IWorkspaceRegistration;

#endif 	/* __IWorkspaceRegistration_FWD_DEFINED__ */


#ifndef __IWorkspaceRegistration2_FWD_DEFINED__
#define __IWorkspaceRegistration2_FWD_DEFINED__
typedef interface IWorkspaceRegistration2 IWorkspaceRegistration2;

#endif 	/* __IWorkspaceRegistration2_FWD_DEFINED__ */


#ifndef __IWorkspaceScriptable_FWD_DEFINED__
#define __IWorkspaceScriptable_FWD_DEFINED__
typedef interface IWorkspaceScriptable IWorkspaceScriptable;

#endif 	/* __IWorkspaceScriptable_FWD_DEFINED__ */


#ifndef __IWorkspaceScriptable2_FWD_DEFINED__
#define __IWorkspaceScriptable2_FWD_DEFINED__
typedef interface IWorkspaceScriptable2 IWorkspaceScriptable2;

#endif 	/* __IWorkspaceScriptable2_FWD_DEFINED__ */


#ifndef __IWorkspaceScriptable3_FWD_DEFINED__
#define __IWorkspaceScriptable3_FWD_DEFINED__
typedef interface IWorkspaceScriptable3 IWorkspaceScriptable3;

#endif 	/* __IWorkspaceScriptable3_FWD_DEFINED__ */


#ifndef __IWorkspaceReportMessage_FWD_DEFINED__
#define __IWorkspaceReportMessage_FWD_DEFINED__
typedef interface IWorkspaceReportMessage IWorkspaceReportMessage;

#endif 	/* __IWorkspaceReportMessage_FWD_DEFINED__ */


#ifndef ___ITSWkspEvents_FWD_DEFINED__
#define ___ITSWkspEvents_FWD_DEFINED__
typedef interface _ITSWkspEvents _ITSWkspEvents;

#endif 	/* ___ITSWkspEvents_FWD_DEFINED__ */


#ifndef __Workspace_FWD_DEFINED__
#define __Workspace_FWD_DEFINED__

#ifdef __cplusplus
typedef class Workspace Workspace;
#else
typedef struct Workspace Workspace;
#endif /* __cplusplus */

#endif 	/* __Workspace_FWD_DEFINED__ */


/* header files for imported files */
#include "workspaceruntimeclientext.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_workspaceruntime_0000_0000 */
/* [local] */ 

#include <winapifamily.h>
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
#define WKS_FLAG_CLEAR_CREDS_ON_LAST_RESOURCE 1
#define WKS_FLAG_PASSWORD_ENCRYPTED   2
#define WKS_FLAG_CREDS_AUTHENTICATED  4


extern RPC_IF_HANDLE __MIDL_itf_workspaceruntime_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_workspaceruntime_0000_0000_v0_0_s_ifspec;

#ifndef __IWorkspace_INTERFACE_DEFINED__
#define __IWorkspace_INTERFACE_DEFINED__

/* interface IWorkspace */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWorkspace;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B922BBB8-4C55-4FEA-8496-BEB0B44285E5")
    IWorkspace : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetWorkspaceNames( 
            /* [annotation][out] */ 
            _Out_  SAFEARRAY * *psaWkspNames) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE StartRemoteApplication( 
            /* [annotation][in] */ 
            _In_  BSTR bstrWorkspaceId,
            /* [annotation][in] */ 
            _In_  SAFEARRAY * psaParams) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetProcessId( 
            /* [annotation][retval][out] */ 
            _Out_retval_  ULONG *pulProcessId) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWorkspaceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IWorkspace * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IWorkspace * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IWorkspace * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetWorkspaceNames )( 
            __RPC__in IWorkspace * This,
            /* [annotation][out] */ 
            _Out_  SAFEARRAY * *psaWkspNames);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *StartRemoteApplication )( 
            __RPC__in IWorkspace * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrWorkspaceId,
            /* [annotation][in] */ 
            _In_  SAFEARRAY * psaParams);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetProcessId )( 
            __RPC__in IWorkspace * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  ULONG *pulProcessId);
        
        END_INTERFACE
    } IWorkspaceVtbl;

    interface IWorkspace
    {
        CONST_VTBL struct IWorkspaceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWorkspace_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWorkspace_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWorkspace_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWorkspace_GetWorkspaceNames(This,psaWkspNames)	\
    ( (This)->lpVtbl -> GetWorkspaceNames(This,psaWkspNames) ) 

#define IWorkspace_StartRemoteApplication(This,bstrWorkspaceId,psaParams)	\
    ( (This)->lpVtbl -> StartRemoteApplication(This,bstrWorkspaceId,psaParams) ) 

#define IWorkspace_GetProcessId(This,pulProcessId)	\
    ( (This)->lpVtbl -> GetProcessId(This,pulProcessId) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWorkspace_INTERFACE_DEFINED__ */


#ifndef __IWorkspace2_INTERFACE_DEFINED__
#define __IWorkspace2_INTERFACE_DEFINED__

/* interface IWorkspace2 */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWorkspace2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("96D8D7CF-783E-4286-834C-EBC0E95F783C")
    IWorkspace2 : public IWorkspace
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE StartRemoteApplicationEx( 
            /* [annotation][in] */ 
            _In_  BSTR bstrWorkspaceId,
            /* [annotation][in] */ 
            _In_  BSTR bstrRequestingAppId,
            /* [annotation][in] */ 
            _In_  BSTR bstrRequestingAppFamilyName,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL bLaunchIntoImmersiveClient,
            /* [annotation][in] */ 
            _In_  BSTR bstrImmersiveClientActivationContext,
            /* [annotation][in] */ 
            _In_  SAFEARRAY * psaParams) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWorkspace2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IWorkspace2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IWorkspace2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IWorkspace2 * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetWorkspaceNames )( 
            __RPC__in IWorkspace2 * This,
            /* [annotation][out] */ 
            _Out_  SAFEARRAY * *psaWkspNames);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *StartRemoteApplication )( 
            __RPC__in IWorkspace2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrWorkspaceId,
            /* [annotation][in] */ 
            _In_  SAFEARRAY * psaParams);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetProcessId )( 
            __RPC__in IWorkspace2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  ULONG *pulProcessId);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *StartRemoteApplicationEx )( 
            __RPC__in IWorkspace2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrWorkspaceId,
            /* [annotation][in] */ 
            _In_  BSTR bstrRequestingAppId,
            /* [annotation][in] */ 
            _In_  BSTR bstrRequestingAppFamilyName,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL bLaunchIntoImmersiveClient,
            /* [annotation][in] */ 
            _In_  BSTR bstrImmersiveClientActivationContext,
            /* [annotation][in] */ 
            _In_  SAFEARRAY * psaParams);
        
        END_INTERFACE
    } IWorkspace2Vtbl;

    interface IWorkspace2
    {
        CONST_VTBL struct IWorkspace2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWorkspace2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWorkspace2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWorkspace2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWorkspace2_GetWorkspaceNames(This,psaWkspNames)	\
    ( (This)->lpVtbl -> GetWorkspaceNames(This,psaWkspNames) ) 

#define IWorkspace2_StartRemoteApplication(This,bstrWorkspaceId,psaParams)	\
    ( (This)->lpVtbl -> StartRemoteApplication(This,bstrWorkspaceId,psaParams) ) 

#define IWorkspace2_GetProcessId(This,pulProcessId)	\
    ( (This)->lpVtbl -> GetProcessId(This,pulProcessId) ) 


#define IWorkspace2_StartRemoteApplicationEx(This,bstrWorkspaceId,bstrRequestingAppId,bstrRequestingAppFamilyName,bLaunchIntoImmersiveClient,bstrImmersiveClientActivationContext,psaParams)	\
    ( (This)->lpVtbl -> StartRemoteApplicationEx(This,bstrWorkspaceId,bstrRequestingAppId,bstrRequestingAppFamilyName,bLaunchIntoImmersiveClient,bstrImmersiveClientActivationContext,psaParams) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWorkspace2_INTERFACE_DEFINED__ */


#ifndef __IWorkspace3_INTERFACE_DEFINED__
#define __IWorkspace3_INTERFACE_DEFINED__

/* interface IWorkspace3 */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWorkspace3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1BECBE4A-D654-423B-AFEB-BE8D532C13C6")
    IWorkspace3 : public IWorkspace2
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetClaimsToken2( 
            /* [annotation][in] */ 
            _In_  BSTR bstrClaimsHint,
            /* [annotation][in] */ 
            _In_  BSTR bstrUserHint,
            /* [annotation][in] */ 
            _In_  ULONG claimCookie,
            /* [annotation][in] */ 
            _In_  ULONG hwndCredUiParent,
            /* [annotation][in] */ 
            _In_  RECT rectCredUiParent,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrAccessToken) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetClaimsToken( 
            /* [annotation][in] */ 
            _In_  BSTR bstrAccessToken,
            /* [annotation][in] */ 
            _In_  ULONGLONG ullAccessTokenExpiration,
            /* [annotation][in] */ 
            _In_  BSTR bstrRefreshToken) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWorkspace3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IWorkspace3 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IWorkspace3 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IWorkspace3 * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetWorkspaceNames )( 
            __RPC__in IWorkspace3 * This,
            /* [annotation][out] */ 
            _Out_  SAFEARRAY * *psaWkspNames);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *StartRemoteApplication )( 
            __RPC__in IWorkspace3 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrWorkspaceId,
            /* [annotation][in] */ 
            _In_  SAFEARRAY * psaParams);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetProcessId )( 
            __RPC__in IWorkspace3 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  ULONG *pulProcessId);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *StartRemoteApplicationEx )( 
            __RPC__in IWorkspace3 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrWorkspaceId,
            /* [annotation][in] */ 
            _In_  BSTR bstrRequestingAppId,
            /* [annotation][in] */ 
            _In_  BSTR bstrRequestingAppFamilyName,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL bLaunchIntoImmersiveClient,
            /* [annotation][in] */ 
            _In_  BSTR bstrImmersiveClientActivationContext,
            /* [annotation][in] */ 
            _In_  SAFEARRAY * psaParams);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetClaimsToken2 )( 
            __RPC__in IWorkspace3 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrClaimsHint,
            /* [annotation][in] */ 
            _In_  BSTR bstrUserHint,
            /* [annotation][in] */ 
            _In_  ULONG claimCookie,
            /* [annotation][in] */ 
            _In_  ULONG hwndCredUiParent,
            /* [annotation][in] */ 
            _In_  RECT rectCredUiParent,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrAccessToken);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetClaimsToken )( 
            __RPC__in IWorkspace3 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrAccessToken,
            /* [annotation][in] */ 
            _In_  ULONGLONG ullAccessTokenExpiration,
            /* [annotation][in] */ 
            _In_  BSTR bstrRefreshToken);
        
        END_INTERFACE
    } IWorkspace3Vtbl;

    interface IWorkspace3
    {
        CONST_VTBL struct IWorkspace3Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWorkspace3_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWorkspace3_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWorkspace3_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWorkspace3_GetWorkspaceNames(This,psaWkspNames)	\
    ( (This)->lpVtbl -> GetWorkspaceNames(This,psaWkspNames) ) 

#define IWorkspace3_StartRemoteApplication(This,bstrWorkspaceId,psaParams)	\
    ( (This)->lpVtbl -> StartRemoteApplication(This,bstrWorkspaceId,psaParams) ) 

#define IWorkspace3_GetProcessId(This,pulProcessId)	\
    ( (This)->lpVtbl -> GetProcessId(This,pulProcessId) ) 


#define IWorkspace3_StartRemoteApplicationEx(This,bstrWorkspaceId,bstrRequestingAppId,bstrRequestingAppFamilyName,bLaunchIntoImmersiveClient,bstrImmersiveClientActivationContext,psaParams)	\
    ( (This)->lpVtbl -> StartRemoteApplicationEx(This,bstrWorkspaceId,bstrRequestingAppId,bstrRequestingAppFamilyName,bLaunchIntoImmersiveClient,bstrImmersiveClientActivationContext,psaParams) ) 


#define IWorkspace3_GetClaimsToken2(This,bstrClaimsHint,bstrUserHint,claimCookie,hwndCredUiParent,rectCredUiParent,pbstrAccessToken)	\
    ( (This)->lpVtbl -> GetClaimsToken2(This,bstrClaimsHint,bstrUserHint,claimCookie,hwndCredUiParent,rectCredUiParent,pbstrAccessToken) ) 

#define IWorkspace3_SetClaimsToken(This,bstrAccessToken,ullAccessTokenExpiration,bstrRefreshToken)	\
    ( (This)->lpVtbl -> SetClaimsToken(This,bstrAccessToken,ullAccessTokenExpiration,bstrRefreshToken) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWorkspace3_INTERFACE_DEFINED__ */


#ifndef __IWorkspaceRegistration_INTERFACE_DEFINED__
#define __IWorkspaceRegistration_INTERFACE_DEFINED__

/* interface IWorkspaceRegistration */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWorkspaceRegistration;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B922BBB8-4C55-4FEA-8496-BEB0B44285E6")
    IWorkspaceRegistration : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AddResource( 
            /* [annotation][in] */ 
            _In_  IWorkspaceClientExt *pUnk,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwCookie) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RemoveResource( 
            /* [annotation][in] */ 
            _In_  DWORD dwCookieConnection) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWorkspaceRegistrationVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IWorkspaceRegistration * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IWorkspaceRegistration * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IWorkspaceRegistration * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AddResource )( 
            __RPC__in IWorkspaceRegistration * This,
            /* [annotation][in] */ 
            _In_  IWorkspaceClientExt *pUnk,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwCookie);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *RemoveResource )( 
            __RPC__in IWorkspaceRegistration * This,
            /* [annotation][in] */ 
            _In_  DWORD dwCookieConnection);
        
        END_INTERFACE
    } IWorkspaceRegistrationVtbl;

    interface IWorkspaceRegistration
    {
        CONST_VTBL struct IWorkspaceRegistrationVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWorkspaceRegistration_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWorkspaceRegistration_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWorkspaceRegistration_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWorkspaceRegistration_AddResource(This,pUnk,pdwCookie)	\
    ( (This)->lpVtbl -> AddResource(This,pUnk,pdwCookie) ) 

#define IWorkspaceRegistration_RemoveResource(This,dwCookieConnection)	\
    ( (This)->lpVtbl -> RemoveResource(This,dwCookieConnection) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWorkspaceRegistration_INTERFACE_DEFINED__ */


#ifndef __IWorkspaceRegistration2_INTERFACE_DEFINED__
#define __IWorkspaceRegistration2_INTERFACE_DEFINED__

/* interface IWorkspaceRegistration2 */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWorkspaceRegistration2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CF59F654-39BB-44D8-94D0-4635728957E9")
    IWorkspaceRegistration2 : public IWorkspaceRegistration
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AddResourceEx( 
            /* [annotation][in] */ 
            _In_  IWorkspaceClientExt *pUnk,
            /* [annotation][in] */ 
            _In_  BSTR bstrEventLogUploadAddress,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwCookie,
            /* [annotation][in] */ 
            _In_  GUID correlationId) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RemoveResourceEx( 
            /* [annotation][in] */ 
            _In_  DWORD dwCookieConnection,
            /* [annotation][in] */ 
            _In_  GUID correlationId) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWorkspaceRegistration2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IWorkspaceRegistration2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IWorkspaceRegistration2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IWorkspaceRegistration2 * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AddResource )( 
            __RPC__in IWorkspaceRegistration2 * This,
            /* [annotation][in] */ 
            _In_  IWorkspaceClientExt *pUnk,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwCookie);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *RemoveResource )( 
            __RPC__in IWorkspaceRegistration2 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwCookieConnection);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AddResourceEx )( 
            __RPC__in IWorkspaceRegistration2 * This,
            /* [annotation][in] */ 
            _In_  IWorkspaceClientExt *pUnk,
            /* [annotation][in] */ 
            _In_  BSTR bstrEventLogUploadAddress,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwCookie,
            /* [annotation][in] */ 
            _In_  GUID correlationId);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *RemoveResourceEx )( 
            __RPC__in IWorkspaceRegistration2 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwCookieConnection,
            /* [annotation][in] */ 
            _In_  GUID correlationId);
        
        END_INTERFACE
    } IWorkspaceRegistration2Vtbl;

    interface IWorkspaceRegistration2
    {
        CONST_VTBL struct IWorkspaceRegistration2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWorkspaceRegistration2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWorkspaceRegistration2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWorkspaceRegistration2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWorkspaceRegistration2_AddResource(This,pUnk,pdwCookie)	\
    ( (This)->lpVtbl -> AddResource(This,pUnk,pdwCookie) ) 

#define IWorkspaceRegistration2_RemoveResource(This,dwCookieConnection)	\
    ( (This)->lpVtbl -> RemoveResource(This,dwCookieConnection) ) 


#define IWorkspaceRegistration2_AddResourceEx(This,pUnk,bstrEventLogUploadAddress,pdwCookie,correlationId)	\
    ( (This)->lpVtbl -> AddResourceEx(This,pUnk,bstrEventLogUploadAddress,pdwCookie,correlationId) ) 

#define IWorkspaceRegistration2_RemoveResourceEx(This,dwCookieConnection,correlationId)	\
    ( (This)->lpVtbl -> RemoveResourceEx(This,dwCookieConnection,correlationId) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWorkspaceRegistration2_INTERFACE_DEFINED__ */


#ifndef __IWorkspaceScriptable_INTERFACE_DEFINED__
#define __IWorkspaceScriptable_INTERFACE_DEFINED__

/* interface IWorkspaceScriptable */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IWorkspaceScriptable;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("EFEA49A2-DDA5-429D-8F42-B23B92C4C347")
    IWorkspaceScriptable : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DisconnectWorkspace( 
            /* [annotation][in] */ 
            _In_  BSTR bstrWorkspaceId) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE StartWorkspace( 
            /* [annotation][in] */ 
            _In_  BSTR bstrWorkspaceId,
            /* [annotation][in] */ 
            _In_  BSTR bstrUserName,
            /* [annotation][in] */ 
            _In_  BSTR bstrPassword,
            /* [annotation][in] */ 
            _In_  BSTR bstrWorkspaceParams,
            /* [annotation][in] */ 
            _In_  LONG lTimeout,
            /* [annotation][in] */ 
            _In_  LONG lFlags) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsWorkspaceCredentialSpecified( 
            /* [annotation][in] */ 
            _In_  BSTR bstrWorkspaceId,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL bCountUnauthenticatedCredentials,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pbCredExist) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsWorkspaceSSOEnabled( 
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pbSSOEnabled) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ClearWorkspaceCredential( 
            /* [annotation][in] */ 
            _In_  BSTR bstrWorkspaceId) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnAuthenticated( 
            /* [annotation][in] */ 
            _In_  BSTR bstrWorkspaceId,
            /* [annotation][in] */ 
            _In_  BSTR bstrUserName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DisconnectWorkspaceByFriendlyName( 
            /* [annotation][in] */ 
            _In_  BSTR bstrWorkspaceFriendlyName) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWorkspaceScriptableVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IWorkspaceScriptable * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IWorkspaceScriptable * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IWorkspaceScriptable * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IWorkspaceScriptable * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IWorkspaceScriptable * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IWorkspaceScriptable * This,
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
            IWorkspaceScriptable * This,
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
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DisconnectWorkspace )( 
            __RPC__in IWorkspaceScriptable * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrWorkspaceId);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StartWorkspace )( 
            __RPC__in IWorkspaceScriptable * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrWorkspaceId,
            /* [annotation][in] */ 
            _In_  BSTR bstrUserName,
            /* [annotation][in] */ 
            _In_  BSTR bstrPassword,
            /* [annotation][in] */ 
            _In_  BSTR bstrWorkspaceParams,
            /* [annotation][in] */ 
            _In_  LONG lTimeout,
            /* [annotation][in] */ 
            _In_  LONG lFlags);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsWorkspaceCredentialSpecified )( 
            __RPC__in IWorkspaceScriptable * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrWorkspaceId,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL bCountUnauthenticatedCredentials,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pbCredExist);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsWorkspaceSSOEnabled )( 
            __RPC__in IWorkspaceScriptable * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pbSSOEnabled);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ClearWorkspaceCredential )( 
            __RPC__in IWorkspaceScriptable * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrWorkspaceId);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnAuthenticated )( 
            __RPC__in IWorkspaceScriptable * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrWorkspaceId,
            /* [annotation][in] */ 
            _In_  BSTR bstrUserName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DisconnectWorkspaceByFriendlyName )( 
            __RPC__in IWorkspaceScriptable * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrWorkspaceFriendlyName);
        
        END_INTERFACE
    } IWorkspaceScriptableVtbl;

    interface IWorkspaceScriptable
    {
        CONST_VTBL struct IWorkspaceScriptableVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWorkspaceScriptable_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWorkspaceScriptable_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWorkspaceScriptable_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWorkspaceScriptable_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IWorkspaceScriptable_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IWorkspaceScriptable_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IWorkspaceScriptable_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IWorkspaceScriptable_DisconnectWorkspace(This,bstrWorkspaceId)	\
    ( (This)->lpVtbl -> DisconnectWorkspace(This,bstrWorkspaceId) ) 

#define IWorkspaceScriptable_StartWorkspace(This,bstrWorkspaceId,bstrUserName,bstrPassword,bstrWorkspaceParams,lTimeout,lFlags)	\
    ( (This)->lpVtbl -> StartWorkspace(This,bstrWorkspaceId,bstrUserName,bstrPassword,bstrWorkspaceParams,lTimeout,lFlags) ) 

#define IWorkspaceScriptable_IsWorkspaceCredentialSpecified(This,bstrWorkspaceId,bCountUnauthenticatedCredentials,pbCredExist)	\
    ( (This)->lpVtbl -> IsWorkspaceCredentialSpecified(This,bstrWorkspaceId,bCountUnauthenticatedCredentials,pbCredExist) ) 

#define IWorkspaceScriptable_IsWorkspaceSSOEnabled(This,pbSSOEnabled)	\
    ( (This)->lpVtbl -> IsWorkspaceSSOEnabled(This,pbSSOEnabled) ) 

#define IWorkspaceScriptable_ClearWorkspaceCredential(This,bstrWorkspaceId)	\
    ( (This)->lpVtbl -> ClearWorkspaceCredential(This,bstrWorkspaceId) ) 

#define IWorkspaceScriptable_OnAuthenticated(This,bstrWorkspaceId,bstrUserName)	\
    ( (This)->lpVtbl -> OnAuthenticated(This,bstrWorkspaceId,bstrUserName) ) 

#define IWorkspaceScriptable_DisconnectWorkspaceByFriendlyName(This,bstrWorkspaceFriendlyName)	\
    ( (This)->lpVtbl -> DisconnectWorkspaceByFriendlyName(This,bstrWorkspaceFriendlyName) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWorkspaceScriptable_INTERFACE_DEFINED__ */


#ifndef __IWorkspaceScriptable2_INTERFACE_DEFINED__
#define __IWorkspaceScriptable2_INTERFACE_DEFINED__

/* interface IWorkspaceScriptable2 */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IWorkspaceScriptable2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("EFEA49A2-DDA5-429D-8F42-B33BA2C4C348")
    IWorkspaceScriptable2 : public IWorkspaceScriptable
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE StartWorkspaceEx( 
            /* [annotation][in] */ 
            _In_  BSTR bstrWorkspaceId,
            /* [annotation][in] */ 
            _In_  BSTR bstrWorkspaceFriendlyName,
            /* [annotation][in] */ 
            _In_  BSTR bstrRedirectorName,
            /* [annotation][in] */ 
            _In_  BSTR bstrUserName,
            /* [annotation][in] */ 
            _In_  BSTR bstrPassword,
            /* [annotation][in] */ 
            _In_  BSTR bstrAppContainer,
            /* [annotation][in] */ 
            _In_  BSTR bstrWorkspaceParams,
            /* [annotation][in] */ 
            _In_  LONG lTimeout,
            /* [annotation][in] */ 
            _In_  LONG lFlags) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ResourceDismissed( 
            /* [annotation][in] */ 
            _In_  BSTR bstrWorkspaceId,
            /* [annotation][in] */ 
            _In_  BSTR bstrWorkspaceFriendlyName) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWorkspaceScriptable2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IWorkspaceScriptable2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IWorkspaceScriptable2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IWorkspaceScriptable2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IWorkspaceScriptable2 * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IWorkspaceScriptable2 * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IWorkspaceScriptable2 * This,
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
            IWorkspaceScriptable2 * This,
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
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DisconnectWorkspace )( 
            __RPC__in IWorkspaceScriptable2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrWorkspaceId);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StartWorkspace )( 
            __RPC__in IWorkspaceScriptable2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrWorkspaceId,
            /* [annotation][in] */ 
            _In_  BSTR bstrUserName,
            /* [annotation][in] */ 
            _In_  BSTR bstrPassword,
            /* [annotation][in] */ 
            _In_  BSTR bstrWorkspaceParams,
            /* [annotation][in] */ 
            _In_  LONG lTimeout,
            /* [annotation][in] */ 
            _In_  LONG lFlags);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsWorkspaceCredentialSpecified )( 
            __RPC__in IWorkspaceScriptable2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrWorkspaceId,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL bCountUnauthenticatedCredentials,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pbCredExist);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsWorkspaceSSOEnabled )( 
            __RPC__in IWorkspaceScriptable2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pbSSOEnabled);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ClearWorkspaceCredential )( 
            __RPC__in IWorkspaceScriptable2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrWorkspaceId);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnAuthenticated )( 
            __RPC__in IWorkspaceScriptable2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrWorkspaceId,
            /* [annotation][in] */ 
            _In_  BSTR bstrUserName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DisconnectWorkspaceByFriendlyName )( 
            __RPC__in IWorkspaceScriptable2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrWorkspaceFriendlyName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StartWorkspaceEx )( 
            __RPC__in IWorkspaceScriptable2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrWorkspaceId,
            /* [annotation][in] */ 
            _In_  BSTR bstrWorkspaceFriendlyName,
            /* [annotation][in] */ 
            _In_  BSTR bstrRedirectorName,
            /* [annotation][in] */ 
            _In_  BSTR bstrUserName,
            /* [annotation][in] */ 
            _In_  BSTR bstrPassword,
            /* [annotation][in] */ 
            _In_  BSTR bstrAppContainer,
            /* [annotation][in] */ 
            _In_  BSTR bstrWorkspaceParams,
            /* [annotation][in] */ 
            _In_  LONG lTimeout,
            /* [annotation][in] */ 
            _In_  LONG lFlags);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ResourceDismissed )( 
            __RPC__in IWorkspaceScriptable2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrWorkspaceId,
            /* [annotation][in] */ 
            _In_  BSTR bstrWorkspaceFriendlyName);
        
        END_INTERFACE
    } IWorkspaceScriptable2Vtbl;

    interface IWorkspaceScriptable2
    {
        CONST_VTBL struct IWorkspaceScriptable2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWorkspaceScriptable2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWorkspaceScriptable2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWorkspaceScriptable2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWorkspaceScriptable2_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IWorkspaceScriptable2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IWorkspaceScriptable2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IWorkspaceScriptable2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IWorkspaceScriptable2_DisconnectWorkspace(This,bstrWorkspaceId)	\
    ( (This)->lpVtbl -> DisconnectWorkspace(This,bstrWorkspaceId) ) 

#define IWorkspaceScriptable2_StartWorkspace(This,bstrWorkspaceId,bstrUserName,bstrPassword,bstrWorkspaceParams,lTimeout,lFlags)	\
    ( (This)->lpVtbl -> StartWorkspace(This,bstrWorkspaceId,bstrUserName,bstrPassword,bstrWorkspaceParams,lTimeout,lFlags) ) 

#define IWorkspaceScriptable2_IsWorkspaceCredentialSpecified(This,bstrWorkspaceId,bCountUnauthenticatedCredentials,pbCredExist)	\
    ( (This)->lpVtbl -> IsWorkspaceCredentialSpecified(This,bstrWorkspaceId,bCountUnauthenticatedCredentials,pbCredExist) ) 

#define IWorkspaceScriptable2_IsWorkspaceSSOEnabled(This,pbSSOEnabled)	\
    ( (This)->lpVtbl -> IsWorkspaceSSOEnabled(This,pbSSOEnabled) ) 

#define IWorkspaceScriptable2_ClearWorkspaceCredential(This,bstrWorkspaceId)	\
    ( (This)->lpVtbl -> ClearWorkspaceCredential(This,bstrWorkspaceId) ) 

#define IWorkspaceScriptable2_OnAuthenticated(This,bstrWorkspaceId,bstrUserName)	\
    ( (This)->lpVtbl -> OnAuthenticated(This,bstrWorkspaceId,bstrUserName) ) 

#define IWorkspaceScriptable2_DisconnectWorkspaceByFriendlyName(This,bstrWorkspaceFriendlyName)	\
    ( (This)->lpVtbl -> DisconnectWorkspaceByFriendlyName(This,bstrWorkspaceFriendlyName) ) 


#define IWorkspaceScriptable2_StartWorkspaceEx(This,bstrWorkspaceId,bstrWorkspaceFriendlyName,bstrRedirectorName,bstrUserName,bstrPassword,bstrAppContainer,bstrWorkspaceParams,lTimeout,lFlags)	\
    ( (This)->lpVtbl -> StartWorkspaceEx(This,bstrWorkspaceId,bstrWorkspaceFriendlyName,bstrRedirectorName,bstrUserName,bstrPassword,bstrAppContainer,bstrWorkspaceParams,lTimeout,lFlags) ) 

#define IWorkspaceScriptable2_ResourceDismissed(This,bstrWorkspaceId,bstrWorkspaceFriendlyName)	\
    ( (This)->lpVtbl -> ResourceDismissed(This,bstrWorkspaceId,bstrWorkspaceFriendlyName) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWorkspaceScriptable2_INTERFACE_DEFINED__ */


#ifndef __IWorkspaceScriptable3_INTERFACE_DEFINED__
#define __IWorkspaceScriptable3_INTERFACE_DEFINED__

/* interface IWorkspaceScriptable3 */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IWorkspaceScriptable3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("531E6512-2CBF-4BD2-80A5-D90A71636A9A")
    IWorkspaceScriptable3 : public IWorkspaceScriptable2
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE StartWorkspaceEx2( 
            /* [annotation][in] */ 
            _In_  BSTR bstrWorkspaceId,
            /* [annotation][in] */ 
            _In_  BSTR bstrWorkspaceFriendlyName,
            /* [annotation][in] */ 
            _In_  BSTR bstrRedirectorName,
            /* [annotation][in] */ 
            _In_  BSTR bstrUserName,
            /* [annotation][in] */ 
            _In_  BSTR bstrPassword,
            /* [annotation][in] */ 
            _In_  BSTR bstrAppContainer,
            /* [annotation][in] */ 
            _In_  BSTR bstrWorkspaceParams,
            /* [annotation][in] */ 
            _In_  LONG lTimeout,
            /* [annotation][in] */ 
            _In_  LONG lFlags,
            /* [annotation][in] */ 
            _In_  BSTR bstrEventLogUploadAddress,
            /* [annotation][in] */ 
            _In_  GUID correlationId) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWorkspaceScriptable3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IWorkspaceScriptable3 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IWorkspaceScriptable3 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IWorkspaceScriptable3 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IWorkspaceScriptable3 * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IWorkspaceScriptable3 * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IWorkspaceScriptable3 * This,
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
            IWorkspaceScriptable3 * This,
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
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DisconnectWorkspace )( 
            __RPC__in IWorkspaceScriptable3 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrWorkspaceId);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StartWorkspace )( 
            __RPC__in IWorkspaceScriptable3 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrWorkspaceId,
            /* [annotation][in] */ 
            _In_  BSTR bstrUserName,
            /* [annotation][in] */ 
            _In_  BSTR bstrPassword,
            /* [annotation][in] */ 
            _In_  BSTR bstrWorkspaceParams,
            /* [annotation][in] */ 
            _In_  LONG lTimeout,
            /* [annotation][in] */ 
            _In_  LONG lFlags);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsWorkspaceCredentialSpecified )( 
            __RPC__in IWorkspaceScriptable3 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrWorkspaceId,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL bCountUnauthenticatedCredentials,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pbCredExist);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsWorkspaceSSOEnabled )( 
            __RPC__in IWorkspaceScriptable3 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pbSSOEnabled);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ClearWorkspaceCredential )( 
            __RPC__in IWorkspaceScriptable3 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrWorkspaceId);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnAuthenticated )( 
            __RPC__in IWorkspaceScriptable3 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrWorkspaceId,
            /* [annotation][in] */ 
            _In_  BSTR bstrUserName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DisconnectWorkspaceByFriendlyName )( 
            __RPC__in IWorkspaceScriptable3 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrWorkspaceFriendlyName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StartWorkspaceEx )( 
            __RPC__in IWorkspaceScriptable3 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrWorkspaceId,
            /* [annotation][in] */ 
            _In_  BSTR bstrWorkspaceFriendlyName,
            /* [annotation][in] */ 
            _In_  BSTR bstrRedirectorName,
            /* [annotation][in] */ 
            _In_  BSTR bstrUserName,
            /* [annotation][in] */ 
            _In_  BSTR bstrPassword,
            /* [annotation][in] */ 
            _In_  BSTR bstrAppContainer,
            /* [annotation][in] */ 
            _In_  BSTR bstrWorkspaceParams,
            /* [annotation][in] */ 
            _In_  LONG lTimeout,
            /* [annotation][in] */ 
            _In_  LONG lFlags);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ResourceDismissed )( 
            __RPC__in IWorkspaceScriptable3 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrWorkspaceId,
            /* [annotation][in] */ 
            _In_  BSTR bstrWorkspaceFriendlyName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StartWorkspaceEx2 )( 
            __RPC__in IWorkspaceScriptable3 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrWorkspaceId,
            /* [annotation][in] */ 
            _In_  BSTR bstrWorkspaceFriendlyName,
            /* [annotation][in] */ 
            _In_  BSTR bstrRedirectorName,
            /* [annotation][in] */ 
            _In_  BSTR bstrUserName,
            /* [annotation][in] */ 
            _In_  BSTR bstrPassword,
            /* [annotation][in] */ 
            _In_  BSTR bstrAppContainer,
            /* [annotation][in] */ 
            _In_  BSTR bstrWorkspaceParams,
            /* [annotation][in] */ 
            _In_  LONG lTimeout,
            /* [annotation][in] */ 
            _In_  LONG lFlags,
            /* [annotation][in] */ 
            _In_  BSTR bstrEventLogUploadAddress,
            /* [annotation][in] */ 
            _In_  GUID correlationId);
        
        END_INTERFACE
    } IWorkspaceScriptable3Vtbl;

    interface IWorkspaceScriptable3
    {
        CONST_VTBL struct IWorkspaceScriptable3Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWorkspaceScriptable3_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWorkspaceScriptable3_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWorkspaceScriptable3_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWorkspaceScriptable3_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IWorkspaceScriptable3_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IWorkspaceScriptable3_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IWorkspaceScriptable3_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IWorkspaceScriptable3_DisconnectWorkspace(This,bstrWorkspaceId)	\
    ( (This)->lpVtbl -> DisconnectWorkspace(This,bstrWorkspaceId) ) 

#define IWorkspaceScriptable3_StartWorkspace(This,bstrWorkspaceId,bstrUserName,bstrPassword,bstrWorkspaceParams,lTimeout,lFlags)	\
    ( (This)->lpVtbl -> StartWorkspace(This,bstrWorkspaceId,bstrUserName,bstrPassword,bstrWorkspaceParams,lTimeout,lFlags) ) 

#define IWorkspaceScriptable3_IsWorkspaceCredentialSpecified(This,bstrWorkspaceId,bCountUnauthenticatedCredentials,pbCredExist)	\
    ( (This)->lpVtbl -> IsWorkspaceCredentialSpecified(This,bstrWorkspaceId,bCountUnauthenticatedCredentials,pbCredExist) ) 

#define IWorkspaceScriptable3_IsWorkspaceSSOEnabled(This,pbSSOEnabled)	\
    ( (This)->lpVtbl -> IsWorkspaceSSOEnabled(This,pbSSOEnabled) ) 

#define IWorkspaceScriptable3_ClearWorkspaceCredential(This,bstrWorkspaceId)	\
    ( (This)->lpVtbl -> ClearWorkspaceCredential(This,bstrWorkspaceId) ) 

#define IWorkspaceScriptable3_OnAuthenticated(This,bstrWorkspaceId,bstrUserName)	\
    ( (This)->lpVtbl -> OnAuthenticated(This,bstrWorkspaceId,bstrUserName) ) 

#define IWorkspaceScriptable3_DisconnectWorkspaceByFriendlyName(This,bstrWorkspaceFriendlyName)	\
    ( (This)->lpVtbl -> DisconnectWorkspaceByFriendlyName(This,bstrWorkspaceFriendlyName) ) 


#define IWorkspaceScriptable3_StartWorkspaceEx(This,bstrWorkspaceId,bstrWorkspaceFriendlyName,bstrRedirectorName,bstrUserName,bstrPassword,bstrAppContainer,bstrWorkspaceParams,lTimeout,lFlags)	\
    ( (This)->lpVtbl -> StartWorkspaceEx(This,bstrWorkspaceId,bstrWorkspaceFriendlyName,bstrRedirectorName,bstrUserName,bstrPassword,bstrAppContainer,bstrWorkspaceParams,lTimeout,lFlags) ) 

#define IWorkspaceScriptable3_ResourceDismissed(This,bstrWorkspaceId,bstrWorkspaceFriendlyName)	\
    ( (This)->lpVtbl -> ResourceDismissed(This,bstrWorkspaceId,bstrWorkspaceFriendlyName) ) 


#define IWorkspaceScriptable3_StartWorkspaceEx2(This,bstrWorkspaceId,bstrWorkspaceFriendlyName,bstrRedirectorName,bstrUserName,bstrPassword,bstrAppContainer,bstrWorkspaceParams,lTimeout,lFlags,bstrEventLogUploadAddress,correlationId)	\
    ( (This)->lpVtbl -> StartWorkspaceEx2(This,bstrWorkspaceId,bstrWorkspaceFriendlyName,bstrRedirectorName,bstrUserName,bstrPassword,bstrAppContainer,bstrWorkspaceParams,lTimeout,lFlags,bstrEventLogUploadAddress,correlationId) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWorkspaceScriptable3_INTERFACE_DEFINED__ */


#ifndef __IWorkspaceReportMessage_INTERFACE_DEFINED__
#define __IWorkspaceReportMessage_INTERFACE_DEFINED__

/* interface IWorkspaceReportMessage */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWorkspaceReportMessage;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("a7c06739-500f-4e8c-99a8-2bd6955899eb")
    IWorkspaceReportMessage : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RegisterErrorLogMessage( 
            /* [annotation][in] */ 
            _In_  BSTR bstrMessage) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE IsErrorMessageRegistered( 
            /* [annotation][in] */ 
            _In_  BSTR bstrWkspId,
            /* [annotation][in] */ 
            _In_  DWORD dwErrorType,
            /* [annotation][in] */ 
            _In_  BSTR bstrErrorMessageType,
            /* [annotation][in] */ 
            _In_  DWORD dwErrorCode,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pfErrorExist) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RegisterErrorEvent( 
            /* [annotation][in] */ 
            _In_  BSTR bstrWkspId,
            /* [annotation][in] */ 
            _In_  DWORD dwErrorType,
            /* [annotation][in] */ 
            _In_  BSTR bstrErrorMessageType,
            /* [annotation][in] */ 
            _In_  DWORD dwErrorCode) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWorkspaceReportMessageVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IWorkspaceReportMessage * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IWorkspaceReportMessage * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IWorkspaceReportMessage * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *RegisterErrorLogMessage )( 
            __RPC__in IWorkspaceReportMessage * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrMessage);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *IsErrorMessageRegistered )( 
            __RPC__in IWorkspaceReportMessage * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrWkspId,
            /* [annotation][in] */ 
            _In_  DWORD dwErrorType,
            /* [annotation][in] */ 
            _In_  BSTR bstrErrorMessageType,
            /* [annotation][in] */ 
            _In_  DWORD dwErrorCode,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pfErrorExist);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *RegisterErrorEvent )( 
            __RPC__in IWorkspaceReportMessage * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrWkspId,
            /* [annotation][in] */ 
            _In_  DWORD dwErrorType,
            /* [annotation][in] */ 
            _In_  BSTR bstrErrorMessageType,
            /* [annotation][in] */ 
            _In_  DWORD dwErrorCode);
        
        END_INTERFACE
    } IWorkspaceReportMessageVtbl;

    interface IWorkspaceReportMessage
    {
        CONST_VTBL struct IWorkspaceReportMessageVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWorkspaceReportMessage_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWorkspaceReportMessage_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWorkspaceReportMessage_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWorkspaceReportMessage_RegisterErrorLogMessage(This,bstrMessage)	\
    ( (This)->lpVtbl -> RegisterErrorLogMessage(This,bstrMessage) ) 

#define IWorkspaceReportMessage_IsErrorMessageRegistered(This,bstrWkspId,dwErrorType,bstrErrorMessageType,dwErrorCode,pfErrorExist)	\
    ( (This)->lpVtbl -> IsErrorMessageRegistered(This,bstrWkspId,dwErrorType,bstrErrorMessageType,dwErrorCode,pfErrorExist) ) 

#define IWorkspaceReportMessage_RegisterErrorEvent(This,bstrWkspId,dwErrorType,bstrErrorMessageType,dwErrorCode)	\
    ( (This)->lpVtbl -> RegisterErrorEvent(This,bstrWkspId,dwErrorType,bstrErrorMessageType,dwErrorCode) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWorkspaceReportMessage_INTERFACE_DEFINED__ */



#ifndef __WorkspaceRuntimeLib_LIBRARY_DEFINED__
#define __WorkspaceRuntimeLib_LIBRARY_DEFINED__

/* library WorkspaceRuntimeLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_WorkspaceRuntimeLib;

#ifndef ___ITSWkspEvents_DISPINTERFACE_DEFINED__
#define ___ITSWkspEvents_DISPINTERFACE_DEFINED__

/* dispinterface _ITSWkspEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__ITSWkspEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("B922BBB8-4C55-4FEA-8496-BEB0B44285E9")
    _ITSWkspEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _ITSWkspEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in _ITSWkspEvents * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in _ITSWkspEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in _ITSWkspEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in _ITSWkspEvents * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in _ITSWkspEvents * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in _ITSWkspEvents * This,
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
            _ITSWkspEvents * This,
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
        
        END_INTERFACE
    } _ITSWkspEventsVtbl;

    interface _ITSWkspEvents
    {
        CONST_VTBL struct _ITSWkspEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _ITSWkspEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _ITSWkspEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _ITSWkspEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _ITSWkspEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _ITSWkspEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _ITSWkspEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _ITSWkspEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___ITSWkspEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_Workspace;

#ifdef __cplusplus

class DECLSPEC_UUID("4F1DFCA6-3AAD-48E1-8406-4BC21A501D7C")
Workspace;
#endif
#endif /* __WorkspaceRuntimeLib_LIBRARY_DEFINED__ */

/* interface __MIDL_itf_workspaceruntime_0000_0010 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_workspaceruntime_0000_0010_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_workspaceruntime_0000_0010_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     __RPC__in unsigned long *, unsigned long            , __RPC__in BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     __RPC__in unsigned long *, __RPC__in BSTR * ); 

unsigned long             __RPC_USER  LPSAFEARRAY_UserSize(     __RPC__in unsigned long *, unsigned long            , __RPC__in LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserMarshal(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserUnmarshal(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out LPSAFEARRAY * ); 
void                      __RPC_USER  LPSAFEARRAY_UserFree(     __RPC__in unsigned long *, __RPC__in LPSAFEARRAY * ); 

unsigned long             __RPC_USER  BSTR_UserSize64(     __RPC__in unsigned long *, unsigned long            , __RPC__in BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal64(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal64(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out BSTR * ); 
void                      __RPC_USER  BSTR_UserFree64(     __RPC__in unsigned long *, __RPC__in BSTR * ); 

unsigned long             __RPC_USER  LPSAFEARRAY_UserSize64(     __RPC__in unsigned long *, unsigned long            , __RPC__in LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserMarshal64(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserUnmarshal64(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out LPSAFEARRAY * ); 
void                      __RPC_USER  LPSAFEARRAY_UserFree64(     __RPC__in unsigned long *, __RPC__in LPSAFEARRAY * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


