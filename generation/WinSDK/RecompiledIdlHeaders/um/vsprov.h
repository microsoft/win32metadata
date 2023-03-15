

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

#ifndef __vsprov_h__
#define __vsprov_h__

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

#ifndef __IVssSoftwareSnapshotProvider_FWD_DEFINED__
#define __IVssSoftwareSnapshotProvider_FWD_DEFINED__
typedef interface IVssSoftwareSnapshotProvider IVssSoftwareSnapshotProvider;

#endif 	/* __IVssSoftwareSnapshotProvider_FWD_DEFINED__ */


#ifndef __IVssProviderCreateSnapshotSet_FWD_DEFINED__
#define __IVssProviderCreateSnapshotSet_FWD_DEFINED__
typedef interface IVssProviderCreateSnapshotSet IVssProviderCreateSnapshotSet;

#endif 	/* __IVssProviderCreateSnapshotSet_FWD_DEFINED__ */


#ifndef __IVssProviderNotifications_FWD_DEFINED__
#define __IVssProviderNotifications_FWD_DEFINED__
typedef interface IVssProviderNotifications IVssProviderNotifications;

#endif 	/* __IVssProviderNotifications_FWD_DEFINED__ */


#ifndef __IVssHardwareSnapshotProvider_FWD_DEFINED__
#define __IVssHardwareSnapshotProvider_FWD_DEFINED__
typedef interface IVssHardwareSnapshotProvider IVssHardwareSnapshotProvider;

#endif 	/* __IVssHardwareSnapshotProvider_FWD_DEFINED__ */


#ifndef __IVssHardwareSnapshotProviderEx_FWD_DEFINED__
#define __IVssHardwareSnapshotProviderEx_FWD_DEFINED__
typedef interface IVssHardwareSnapshotProviderEx IVssHardwareSnapshotProviderEx;

#endif 	/* __IVssHardwareSnapshotProviderEx_FWD_DEFINED__ */


#ifndef __IVssFileShareSnapshotProvider_FWD_DEFINED__
#define __IVssFileShareSnapshotProvider_FWD_DEFINED__
typedef interface IVssFileShareSnapshotProvider IVssFileShareSnapshotProvider;

#endif 	/* __IVssFileShareSnapshotProvider_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "vss.h"
#include "vdslun.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_vsprov_0000_0000 */
/* [local] */ 

#include <winapifamily.h>
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)


typedef VSS_PWSZ *PVSS_PWSZ;



extern RPC_IF_HANDLE __MIDL_itf_vsprov_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vsprov_0000_0000_v0_0_s_ifspec;

#ifndef __IVssSoftwareSnapshotProvider_INTERFACE_DEFINED__
#define __IVssSoftwareSnapshotProvider_INTERFACE_DEFINED__

/* interface IVssSoftwareSnapshotProvider */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IVssSoftwareSnapshotProvider;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("609e123e-2c5a-44d3-8f01-0b1d9a47d1ff")
    IVssSoftwareSnapshotProvider : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetContext( 
            /* [annotation][in] */ 
            _In_  LONG lContext) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetSnapshotProperties( 
            /* [annotation][in] */ 
            _In_  VSS_ID SnapshotId,
            /* [annotation][out] */ 
            _Out_  VSS_SNAPSHOT_PROP *pProp) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Query( 
            /* [annotation][in] */ 
            _In_  VSS_ID QueriedObjectId,
            /* [annotation][in] */ 
            _In_  VSS_OBJECT_TYPE eQueriedObjectType,
            /* [annotation][in] */ 
            _In_  VSS_OBJECT_TYPE eReturnedObjectsType,
            /* [annotation][out] */ 
            _Out_  IVssEnumObject **ppEnum) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE DeleteSnapshots( 
            /* [annotation][in] */ 
            _In_  VSS_ID SourceObjectId,
            /* [annotation][in] */ 
            _In_  VSS_OBJECT_TYPE eSourceObjectType,
            /* [annotation][in] */ 
            _In_  BOOL bForceDelete,
            /* [annotation][out] */ 
            _Out_  LONG *plDeletedSnapshots,
            /* [annotation][out] */ 
            _Out_  VSS_ID *pNondeletedSnapshotID) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE BeginPrepareSnapshot( 
            /* [annotation][in] */ 
            _In_  VSS_ID SnapshotSetId,
            /* [annotation][in] */ 
            _In_  VSS_ID SnapshotId,
            /* [annotation][in] */ 
            _In_  VSS_PWSZ pwszVolumeName,
            /* [annotation][in] */ 
            _In_  LONG lNewContext) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE IsVolumeSupported( 
            /* [annotation][in] */ 
            _In_  VSS_PWSZ pwszVolumeName,
            /* [annotation][out] */ 
            _Out_  BOOL *pbSupportedByThisProvider) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE IsVolumeSnapshotted( 
            /* [annotation][in] */ 
            _In_  VSS_PWSZ pwszVolumeName,
            /* [annotation][out] */ 
            _Out_  BOOL *pbSnapshotsPresent,
            /* [annotation][out] */ 
            _Out_  LONG *plSnapshotCompatibility) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetSnapshotProperty( 
            /* [annotation][in] */ 
            _In_  VSS_ID SnapshotId,
            /* [annotation][in] */ 
            _In_  VSS_SNAPSHOT_PROPERTY_ID eSnapshotPropertyId,
            /* [annotation][in] */ 
            _In_  VARIANT vProperty) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RevertToSnapshot( 
            /* [annotation][in] */ 
            _In_  VSS_ID SnapshotId) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE QueryRevertStatus( 
            /* [annotation][in] */ 
            _In_  VSS_PWSZ pwszVolume,
            /* [annotation][out] */ 
            _Out_  IVssAsync **ppAsync) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IVssSoftwareSnapshotProviderVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IVssSoftwareSnapshotProvider * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IVssSoftwareSnapshotProvider * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IVssSoftwareSnapshotProvider * This);
        
        DECLSPEC_XFGVIRT(IVssSoftwareSnapshotProvider, SetContext)
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetContext )( 
            __RPC__in IVssSoftwareSnapshotProvider * This,
            /* [annotation][in] */ 
            _In_  LONG lContext);
        
        DECLSPEC_XFGVIRT(IVssSoftwareSnapshotProvider, GetSnapshotProperties)
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetSnapshotProperties )( 
            __RPC__in IVssSoftwareSnapshotProvider * This,
            /* [annotation][in] */ 
            _In_  VSS_ID SnapshotId,
            /* [annotation][out] */ 
            _Out_  VSS_SNAPSHOT_PROP *pProp);
        
        DECLSPEC_XFGVIRT(IVssSoftwareSnapshotProvider, Query)
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Query )( 
            __RPC__in IVssSoftwareSnapshotProvider * This,
            /* [annotation][in] */ 
            _In_  VSS_ID QueriedObjectId,
            /* [annotation][in] */ 
            _In_  VSS_OBJECT_TYPE eQueriedObjectType,
            /* [annotation][in] */ 
            _In_  VSS_OBJECT_TYPE eReturnedObjectsType,
            /* [annotation][out] */ 
            _Out_  IVssEnumObject **ppEnum);
        
        DECLSPEC_XFGVIRT(IVssSoftwareSnapshotProvider, DeleteSnapshots)
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *DeleteSnapshots )( 
            __RPC__in IVssSoftwareSnapshotProvider * This,
            /* [annotation][in] */ 
            _In_  VSS_ID SourceObjectId,
            /* [annotation][in] */ 
            _In_  VSS_OBJECT_TYPE eSourceObjectType,
            /* [annotation][in] */ 
            _In_  BOOL bForceDelete,
            /* [annotation][out] */ 
            _Out_  LONG *plDeletedSnapshots,
            /* [annotation][out] */ 
            _Out_  VSS_ID *pNondeletedSnapshotID);
        
        DECLSPEC_XFGVIRT(IVssSoftwareSnapshotProvider, BeginPrepareSnapshot)
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *BeginPrepareSnapshot )( 
            __RPC__in IVssSoftwareSnapshotProvider * This,
            /* [annotation][in] */ 
            _In_  VSS_ID SnapshotSetId,
            /* [annotation][in] */ 
            _In_  VSS_ID SnapshotId,
            /* [annotation][in] */ 
            _In_  VSS_PWSZ pwszVolumeName,
            /* [annotation][in] */ 
            _In_  LONG lNewContext);
        
        DECLSPEC_XFGVIRT(IVssSoftwareSnapshotProvider, IsVolumeSupported)
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *IsVolumeSupported )( 
            __RPC__in IVssSoftwareSnapshotProvider * This,
            /* [annotation][in] */ 
            _In_  VSS_PWSZ pwszVolumeName,
            /* [annotation][out] */ 
            _Out_  BOOL *pbSupportedByThisProvider);
        
        DECLSPEC_XFGVIRT(IVssSoftwareSnapshotProvider, IsVolumeSnapshotted)
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *IsVolumeSnapshotted )( 
            __RPC__in IVssSoftwareSnapshotProvider * This,
            /* [annotation][in] */ 
            _In_  VSS_PWSZ pwszVolumeName,
            /* [annotation][out] */ 
            _Out_  BOOL *pbSnapshotsPresent,
            /* [annotation][out] */ 
            _Out_  LONG *plSnapshotCompatibility);
        
        DECLSPEC_XFGVIRT(IVssSoftwareSnapshotProvider, SetSnapshotProperty)
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetSnapshotProperty )( 
            __RPC__in IVssSoftwareSnapshotProvider * This,
            /* [annotation][in] */ 
            _In_  VSS_ID SnapshotId,
            /* [annotation][in] */ 
            _In_  VSS_SNAPSHOT_PROPERTY_ID eSnapshotPropertyId,
            /* [annotation][in] */ 
            _In_  VARIANT vProperty);
        
        DECLSPEC_XFGVIRT(IVssSoftwareSnapshotProvider, RevertToSnapshot)
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *RevertToSnapshot )( 
            __RPC__in IVssSoftwareSnapshotProvider * This,
            /* [annotation][in] */ 
            _In_  VSS_ID SnapshotId);
        
        DECLSPEC_XFGVIRT(IVssSoftwareSnapshotProvider, QueryRevertStatus)
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *QueryRevertStatus )( 
            __RPC__in IVssSoftwareSnapshotProvider * This,
            /* [annotation][in] */ 
            _In_  VSS_PWSZ pwszVolume,
            /* [annotation][out] */ 
            _Out_  IVssAsync **ppAsync);
        
        END_INTERFACE
    } IVssSoftwareSnapshotProviderVtbl;

    interface IVssSoftwareSnapshotProvider
    {
        CONST_VTBL struct IVssSoftwareSnapshotProviderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVssSoftwareSnapshotProvider_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IVssSoftwareSnapshotProvider_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IVssSoftwareSnapshotProvider_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IVssSoftwareSnapshotProvider_SetContext(This,lContext)	\
    ( (This)->lpVtbl -> SetContext(This,lContext) ) 

#define IVssSoftwareSnapshotProvider_GetSnapshotProperties(This,SnapshotId,pProp)	\
    ( (This)->lpVtbl -> GetSnapshotProperties(This,SnapshotId,pProp) ) 

#define IVssSoftwareSnapshotProvider_Query(This,QueriedObjectId,eQueriedObjectType,eReturnedObjectsType,ppEnum)	\
    ( (This)->lpVtbl -> Query(This,QueriedObjectId,eQueriedObjectType,eReturnedObjectsType,ppEnum) ) 

#define IVssSoftwareSnapshotProvider_DeleteSnapshots(This,SourceObjectId,eSourceObjectType,bForceDelete,plDeletedSnapshots,pNondeletedSnapshotID)	\
    ( (This)->lpVtbl -> DeleteSnapshots(This,SourceObjectId,eSourceObjectType,bForceDelete,plDeletedSnapshots,pNondeletedSnapshotID) ) 

#define IVssSoftwareSnapshotProvider_BeginPrepareSnapshot(This,SnapshotSetId,SnapshotId,pwszVolumeName,lNewContext)	\
    ( (This)->lpVtbl -> BeginPrepareSnapshot(This,SnapshotSetId,SnapshotId,pwszVolumeName,lNewContext) ) 

#define IVssSoftwareSnapshotProvider_IsVolumeSupported(This,pwszVolumeName,pbSupportedByThisProvider)	\
    ( (This)->lpVtbl -> IsVolumeSupported(This,pwszVolumeName,pbSupportedByThisProvider) ) 

#define IVssSoftwareSnapshotProvider_IsVolumeSnapshotted(This,pwszVolumeName,pbSnapshotsPresent,plSnapshotCompatibility)	\
    ( (This)->lpVtbl -> IsVolumeSnapshotted(This,pwszVolumeName,pbSnapshotsPresent,plSnapshotCompatibility) ) 

#define IVssSoftwareSnapshotProvider_SetSnapshotProperty(This,SnapshotId,eSnapshotPropertyId,vProperty)	\
    ( (This)->lpVtbl -> SetSnapshotProperty(This,SnapshotId,eSnapshotPropertyId,vProperty) ) 

#define IVssSoftwareSnapshotProvider_RevertToSnapshot(This,SnapshotId)	\
    ( (This)->lpVtbl -> RevertToSnapshot(This,SnapshotId) ) 

#define IVssSoftwareSnapshotProvider_QueryRevertStatus(This,pwszVolume,ppAsync)	\
    ( (This)->lpVtbl -> QueryRevertStatus(This,pwszVolume,ppAsync) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IVssSoftwareSnapshotProvider_INTERFACE_DEFINED__ */


#ifndef __IVssProviderCreateSnapshotSet_INTERFACE_DEFINED__
#define __IVssProviderCreateSnapshotSet_INTERFACE_DEFINED__

/* interface IVssProviderCreateSnapshotSet */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IVssProviderCreateSnapshotSet;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5F894E5B-1E39-4778-8E23-9ABAD9F0E08C")
    IVssProviderCreateSnapshotSet : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE EndPrepareSnapshots( 
            /* [annotation][in] */ 
            _In_  VSS_ID SnapshotSetId) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE PreCommitSnapshots( 
            /* [annotation][in] */ 
            _In_  VSS_ID SnapshotSetId) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CommitSnapshots( 
            /* [annotation][in] */ 
            _In_  VSS_ID SnapshotSetId) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE PostCommitSnapshots( 
            /* [annotation][in] */ 
            _In_  VSS_ID SnapshotSetId,
            /* [annotation][in] */ 
            _In_  LONG lSnapshotsCount) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE PreFinalCommitSnapshots( 
            /* [annotation][in] */ 
            _In_  VSS_ID SnapshotSetId) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE PostFinalCommitSnapshots( 
            /* [annotation][in] */ 
            _In_  VSS_ID SnapshotSetId) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AbortSnapshots( 
            /* [annotation][in] */ 
            _In_  VSS_ID SnapshotSetId) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IVssProviderCreateSnapshotSetVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IVssProviderCreateSnapshotSet * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IVssProviderCreateSnapshotSet * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IVssProviderCreateSnapshotSet * This);
        
        DECLSPEC_XFGVIRT(IVssProviderCreateSnapshotSet, EndPrepareSnapshots)
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *EndPrepareSnapshots )( 
            __RPC__in IVssProviderCreateSnapshotSet * This,
            /* [annotation][in] */ 
            _In_  VSS_ID SnapshotSetId);
        
        DECLSPEC_XFGVIRT(IVssProviderCreateSnapshotSet, PreCommitSnapshots)
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *PreCommitSnapshots )( 
            __RPC__in IVssProviderCreateSnapshotSet * This,
            /* [annotation][in] */ 
            _In_  VSS_ID SnapshotSetId);
        
        DECLSPEC_XFGVIRT(IVssProviderCreateSnapshotSet, CommitSnapshots)
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CommitSnapshots )( 
            __RPC__in IVssProviderCreateSnapshotSet * This,
            /* [annotation][in] */ 
            _In_  VSS_ID SnapshotSetId);
        
        DECLSPEC_XFGVIRT(IVssProviderCreateSnapshotSet, PostCommitSnapshots)
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *PostCommitSnapshots )( 
            __RPC__in IVssProviderCreateSnapshotSet * This,
            /* [annotation][in] */ 
            _In_  VSS_ID SnapshotSetId,
            /* [annotation][in] */ 
            _In_  LONG lSnapshotsCount);
        
        DECLSPEC_XFGVIRT(IVssProviderCreateSnapshotSet, PreFinalCommitSnapshots)
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *PreFinalCommitSnapshots )( 
            __RPC__in IVssProviderCreateSnapshotSet * This,
            /* [annotation][in] */ 
            _In_  VSS_ID SnapshotSetId);
        
        DECLSPEC_XFGVIRT(IVssProviderCreateSnapshotSet, PostFinalCommitSnapshots)
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *PostFinalCommitSnapshots )( 
            __RPC__in IVssProviderCreateSnapshotSet * This,
            /* [annotation][in] */ 
            _In_  VSS_ID SnapshotSetId);
        
        DECLSPEC_XFGVIRT(IVssProviderCreateSnapshotSet, AbortSnapshots)
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AbortSnapshots )( 
            __RPC__in IVssProviderCreateSnapshotSet * This,
            /* [annotation][in] */ 
            _In_  VSS_ID SnapshotSetId);
        
        END_INTERFACE
    } IVssProviderCreateSnapshotSetVtbl;

    interface IVssProviderCreateSnapshotSet
    {
        CONST_VTBL struct IVssProviderCreateSnapshotSetVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVssProviderCreateSnapshotSet_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IVssProviderCreateSnapshotSet_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IVssProviderCreateSnapshotSet_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IVssProviderCreateSnapshotSet_EndPrepareSnapshots(This,SnapshotSetId)	\
    ( (This)->lpVtbl -> EndPrepareSnapshots(This,SnapshotSetId) ) 

#define IVssProviderCreateSnapshotSet_PreCommitSnapshots(This,SnapshotSetId)	\
    ( (This)->lpVtbl -> PreCommitSnapshots(This,SnapshotSetId) ) 

#define IVssProviderCreateSnapshotSet_CommitSnapshots(This,SnapshotSetId)	\
    ( (This)->lpVtbl -> CommitSnapshots(This,SnapshotSetId) ) 

#define IVssProviderCreateSnapshotSet_PostCommitSnapshots(This,SnapshotSetId,lSnapshotsCount)	\
    ( (This)->lpVtbl -> PostCommitSnapshots(This,SnapshotSetId,lSnapshotsCount) ) 

#define IVssProviderCreateSnapshotSet_PreFinalCommitSnapshots(This,SnapshotSetId)	\
    ( (This)->lpVtbl -> PreFinalCommitSnapshots(This,SnapshotSetId) ) 

#define IVssProviderCreateSnapshotSet_PostFinalCommitSnapshots(This,SnapshotSetId)	\
    ( (This)->lpVtbl -> PostFinalCommitSnapshots(This,SnapshotSetId) ) 

#define IVssProviderCreateSnapshotSet_AbortSnapshots(This,SnapshotSetId)	\
    ( (This)->lpVtbl -> AbortSnapshots(This,SnapshotSetId) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IVssProviderCreateSnapshotSet_INTERFACE_DEFINED__ */


#ifndef __IVssProviderNotifications_INTERFACE_DEFINED__
#define __IVssProviderNotifications_INTERFACE_DEFINED__

/* interface IVssProviderNotifications */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IVssProviderNotifications;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E561901F-03A5-4afe-86D0-72BAEECE7004")
    IVssProviderNotifications : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnLoad( 
            /* [annotation][unique][in] */ 
            _In_  IUnknown *pCallback) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnUnload( 
            /* [annotation][in] */ 
            _In_  BOOL bForceUnload) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IVssProviderNotificationsVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IVssProviderNotifications * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IVssProviderNotifications * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IVssProviderNotifications * This);
        
        DECLSPEC_XFGVIRT(IVssProviderNotifications, OnLoad)
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *OnLoad )( 
            __RPC__in IVssProviderNotifications * This,
            /* [annotation][unique][in] */ 
            _In_  IUnknown *pCallback);
        
        DECLSPEC_XFGVIRT(IVssProviderNotifications, OnUnload)
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *OnUnload )( 
            __RPC__in IVssProviderNotifications * This,
            /* [annotation][in] */ 
            _In_  BOOL bForceUnload);
        
        END_INTERFACE
    } IVssProviderNotificationsVtbl;

    interface IVssProviderNotifications
    {
        CONST_VTBL struct IVssProviderNotificationsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVssProviderNotifications_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IVssProviderNotifications_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IVssProviderNotifications_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IVssProviderNotifications_OnLoad(This,pCallback)	\
    ( (This)->lpVtbl -> OnLoad(This,pCallback) ) 

#define IVssProviderNotifications_OnUnload(This,bForceUnload)	\
    ( (This)->lpVtbl -> OnUnload(This,bForceUnload) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IVssProviderNotifications_INTERFACE_DEFINED__ */


#ifndef __IVssHardwareSnapshotProvider_INTERFACE_DEFINED__
#define __IVssHardwareSnapshotProvider_INTERFACE_DEFINED__

/* interface IVssHardwareSnapshotProvider */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IVssHardwareSnapshotProvider;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9593A157-44E9-4344-BBEB-44FBF9B06B10")
    IVssHardwareSnapshotProvider : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AreLunsSupported( 
            /* [annotation][in] */ 
            _In_  LONG lLunCount,
            /* [annotation][in] */ 
            _In_  LONG lContext,
            /* [annotation][size_is][unique][in] */ 
            _In_reads_(lLunCount)  VSS_PWSZ *rgwszDevices,
            /* [annotation][size_is][out][in] */ 
            _Inout_updates_(lLunCount)  VDS_LUN_INFORMATION *pLunInformation,
            /* [annotation][out] */ 
            _Out_  BOOL *pbIsSupported) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE FillInLunInfo( 
            /* [annotation][in] */ 
            _In_  VSS_PWSZ wszDeviceName,
            /* [annotation][out][in] */ 
            _Inout_  VDS_LUN_INFORMATION *pLunInfo,
            /* [annotation][out] */ 
            _Out_  BOOL *pbIsSupported) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE BeginPrepareSnapshot( 
            /* [annotation][in] */ 
            _In_  VSS_ID SnapshotSetId,
            /* [annotation][in] */ 
            _In_  VSS_ID SnapshotId,
            /* [annotation][in] */ 
            _In_  LONG lContext,
            /* [annotation][in] */ 
            _In_  LONG lLunCount,
            /* [annotation][size_is][unique][in] */ 
            _In_reads_(lLunCount)  VSS_PWSZ *rgDeviceNames,
            /* [annotation][size_is][out][in] */ 
            _Inout_updates_(lLunCount)  VDS_LUN_INFORMATION *rgLunInformation) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetTargetLuns( 
            /* [annotation][in] */ 
            _In_  LONG lLunCount,
            /* [annotation][size_is][unique][in] */ 
            _In_reads_(lLunCount)  VSS_PWSZ *rgDeviceNames,
            /* [annotation][size_is][unique][in] */ 
            _In_reads_(lLunCount)  VDS_LUN_INFORMATION *rgSourceLuns,
            /* [annotation][size_is][out][in] */ 
            _Inout_updates_(lLunCount)  VDS_LUN_INFORMATION *rgDestinationLuns) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE LocateLuns( 
            /* [annotation][in] */ 
            _In_  LONG lLunCount,
            /* [annotation][size_is][unique][in] */ 
            _In_reads_(lLunCount)  VDS_LUN_INFORMATION *rgSourceLuns) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnLunEmpty( 
            /* [annotation][unique][in] */ 
            _In_  VSS_PWSZ wszDeviceName,
            /* [annotation][unique][in] */ 
            _In_  VDS_LUN_INFORMATION *pInformation) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IVssHardwareSnapshotProviderVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IVssHardwareSnapshotProvider * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IVssHardwareSnapshotProvider * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IVssHardwareSnapshotProvider * This);
        
        DECLSPEC_XFGVIRT(IVssHardwareSnapshotProvider, AreLunsSupported)
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AreLunsSupported )( 
            __RPC__in IVssHardwareSnapshotProvider * This,
            /* [annotation][in] */ 
            _In_  LONG lLunCount,
            /* [annotation][in] */ 
            _In_  LONG lContext,
            /* [annotation][size_is][unique][in] */ 
            _In_reads_(lLunCount)  VSS_PWSZ *rgwszDevices,
            /* [annotation][size_is][out][in] */ 
            _Inout_updates_(lLunCount)  VDS_LUN_INFORMATION *pLunInformation,
            /* [annotation][out] */ 
            _Out_  BOOL *pbIsSupported);
        
        DECLSPEC_XFGVIRT(IVssHardwareSnapshotProvider, FillInLunInfo)
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *FillInLunInfo )( 
            __RPC__in IVssHardwareSnapshotProvider * This,
            /* [annotation][in] */ 
            _In_  VSS_PWSZ wszDeviceName,
            /* [annotation][out][in] */ 
            _Inout_  VDS_LUN_INFORMATION *pLunInfo,
            /* [annotation][out] */ 
            _Out_  BOOL *pbIsSupported);
        
        DECLSPEC_XFGVIRT(IVssHardwareSnapshotProvider, BeginPrepareSnapshot)
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *BeginPrepareSnapshot )( 
            __RPC__in IVssHardwareSnapshotProvider * This,
            /* [annotation][in] */ 
            _In_  VSS_ID SnapshotSetId,
            /* [annotation][in] */ 
            _In_  VSS_ID SnapshotId,
            /* [annotation][in] */ 
            _In_  LONG lContext,
            /* [annotation][in] */ 
            _In_  LONG lLunCount,
            /* [annotation][size_is][unique][in] */ 
            _In_reads_(lLunCount)  VSS_PWSZ *rgDeviceNames,
            /* [annotation][size_is][out][in] */ 
            _Inout_updates_(lLunCount)  VDS_LUN_INFORMATION *rgLunInformation);
        
        DECLSPEC_XFGVIRT(IVssHardwareSnapshotProvider, GetTargetLuns)
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetTargetLuns )( 
            __RPC__in IVssHardwareSnapshotProvider * This,
            /* [annotation][in] */ 
            _In_  LONG lLunCount,
            /* [annotation][size_is][unique][in] */ 
            _In_reads_(lLunCount)  VSS_PWSZ *rgDeviceNames,
            /* [annotation][size_is][unique][in] */ 
            _In_reads_(lLunCount)  VDS_LUN_INFORMATION *rgSourceLuns,
            /* [annotation][size_is][out][in] */ 
            _Inout_updates_(lLunCount)  VDS_LUN_INFORMATION *rgDestinationLuns);
        
        DECLSPEC_XFGVIRT(IVssHardwareSnapshotProvider, LocateLuns)
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *LocateLuns )( 
            __RPC__in IVssHardwareSnapshotProvider * This,
            /* [annotation][in] */ 
            _In_  LONG lLunCount,
            /* [annotation][size_is][unique][in] */ 
            _In_reads_(lLunCount)  VDS_LUN_INFORMATION *rgSourceLuns);
        
        DECLSPEC_XFGVIRT(IVssHardwareSnapshotProvider, OnLunEmpty)
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *OnLunEmpty )( 
            __RPC__in IVssHardwareSnapshotProvider * This,
            /* [annotation][unique][in] */ 
            _In_  VSS_PWSZ wszDeviceName,
            /* [annotation][unique][in] */ 
            _In_  VDS_LUN_INFORMATION *pInformation);
        
        END_INTERFACE
    } IVssHardwareSnapshotProviderVtbl;

    interface IVssHardwareSnapshotProvider
    {
        CONST_VTBL struct IVssHardwareSnapshotProviderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVssHardwareSnapshotProvider_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IVssHardwareSnapshotProvider_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IVssHardwareSnapshotProvider_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IVssHardwareSnapshotProvider_AreLunsSupported(This,lLunCount,lContext,rgwszDevices,pLunInformation,pbIsSupported)	\
    ( (This)->lpVtbl -> AreLunsSupported(This,lLunCount,lContext,rgwszDevices,pLunInformation,pbIsSupported) ) 

#define IVssHardwareSnapshotProvider_FillInLunInfo(This,wszDeviceName,pLunInfo,pbIsSupported)	\
    ( (This)->lpVtbl -> FillInLunInfo(This,wszDeviceName,pLunInfo,pbIsSupported) ) 

#define IVssHardwareSnapshotProvider_BeginPrepareSnapshot(This,SnapshotSetId,SnapshotId,lContext,lLunCount,rgDeviceNames,rgLunInformation)	\
    ( (This)->lpVtbl -> BeginPrepareSnapshot(This,SnapshotSetId,SnapshotId,lContext,lLunCount,rgDeviceNames,rgLunInformation) ) 

#define IVssHardwareSnapshotProvider_GetTargetLuns(This,lLunCount,rgDeviceNames,rgSourceLuns,rgDestinationLuns)	\
    ( (This)->lpVtbl -> GetTargetLuns(This,lLunCount,rgDeviceNames,rgSourceLuns,rgDestinationLuns) ) 

#define IVssHardwareSnapshotProvider_LocateLuns(This,lLunCount,rgSourceLuns)	\
    ( (This)->lpVtbl -> LocateLuns(This,lLunCount,rgSourceLuns) ) 

#define IVssHardwareSnapshotProvider_OnLunEmpty(This,wszDeviceName,pInformation)	\
    ( (This)->lpVtbl -> OnLunEmpty(This,wszDeviceName,pInformation) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IVssHardwareSnapshotProvider_INTERFACE_DEFINED__ */


#ifndef __IVssHardwareSnapshotProviderEx_INTERFACE_DEFINED__
#define __IVssHardwareSnapshotProviderEx_INTERFACE_DEFINED__

/* interface IVssHardwareSnapshotProviderEx */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IVssHardwareSnapshotProviderEx;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7F5BA925-CDB1-4d11-A71F-339EB7E709FD")
    IVssHardwareSnapshotProviderEx : public IVssHardwareSnapshotProvider
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetProviderCapabilities( 
            /* [annotation][out] */ 
            _Out_  ULONGLONG *pllOriginalCapabilityMask) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnLunStateChange( 
            /* [annotation][size_is][unique][in] */ 
            _In_reads_(dwCount)  VDS_LUN_INFORMATION *pSnapshotLuns,
            /* [annotation][size_is][unique][in] */ 
            _In_reads_(dwCount)  VDS_LUN_INFORMATION *pOriginalLuns,
            /* [annotation][in] */ 
            _In_  DWORD dwCount,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ResyncLuns( 
            /* [annotation][size_is][unique][in] */ 
            _In_reads_(dwCount)  VDS_LUN_INFORMATION *pSourceLuns,
            /* [annotation][size_is][unique][in] */ 
            _In_reads_(dwCount)  VDS_LUN_INFORMATION *pTargetLuns,
            /* [annotation][in] */ 
            _In_  DWORD dwCount,
            /* [annotation][out] */ 
            _Out_  IVssAsync **ppAsync) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnReuseLuns( 
            /* [annotation][size_is][unique][in] */ 
            _In_reads_(dwCount)  VDS_LUN_INFORMATION *pSnapshotLuns,
            /* [annotation][size_is][unique][in] */ 
            _In_reads_(dwCount)  VDS_LUN_INFORMATION *pOriginalLuns,
            /* [annotation][in] */ 
            _In_  DWORD dwCount) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IVssHardwareSnapshotProviderExVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IVssHardwareSnapshotProviderEx * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IVssHardwareSnapshotProviderEx * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IVssHardwareSnapshotProviderEx * This);
        
        DECLSPEC_XFGVIRT(IVssHardwareSnapshotProvider, AreLunsSupported)
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AreLunsSupported )( 
            __RPC__in IVssHardwareSnapshotProviderEx * This,
            /* [annotation][in] */ 
            _In_  LONG lLunCount,
            /* [annotation][in] */ 
            _In_  LONG lContext,
            /* [annotation][size_is][unique][in] */ 
            _In_reads_(lLunCount)  VSS_PWSZ *rgwszDevices,
            /* [annotation][size_is][out][in] */ 
            _Inout_updates_(lLunCount)  VDS_LUN_INFORMATION *pLunInformation,
            /* [annotation][out] */ 
            _Out_  BOOL *pbIsSupported);
        
        DECLSPEC_XFGVIRT(IVssHardwareSnapshotProvider, FillInLunInfo)
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *FillInLunInfo )( 
            __RPC__in IVssHardwareSnapshotProviderEx * This,
            /* [annotation][in] */ 
            _In_  VSS_PWSZ wszDeviceName,
            /* [annotation][out][in] */ 
            _Inout_  VDS_LUN_INFORMATION *pLunInfo,
            /* [annotation][out] */ 
            _Out_  BOOL *pbIsSupported);
        
        DECLSPEC_XFGVIRT(IVssHardwareSnapshotProvider, BeginPrepareSnapshot)
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *BeginPrepareSnapshot )( 
            __RPC__in IVssHardwareSnapshotProviderEx * This,
            /* [annotation][in] */ 
            _In_  VSS_ID SnapshotSetId,
            /* [annotation][in] */ 
            _In_  VSS_ID SnapshotId,
            /* [annotation][in] */ 
            _In_  LONG lContext,
            /* [annotation][in] */ 
            _In_  LONG lLunCount,
            /* [annotation][size_is][unique][in] */ 
            _In_reads_(lLunCount)  VSS_PWSZ *rgDeviceNames,
            /* [annotation][size_is][out][in] */ 
            _Inout_updates_(lLunCount)  VDS_LUN_INFORMATION *rgLunInformation);
        
        DECLSPEC_XFGVIRT(IVssHardwareSnapshotProvider, GetTargetLuns)
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetTargetLuns )( 
            __RPC__in IVssHardwareSnapshotProviderEx * This,
            /* [annotation][in] */ 
            _In_  LONG lLunCount,
            /* [annotation][size_is][unique][in] */ 
            _In_reads_(lLunCount)  VSS_PWSZ *rgDeviceNames,
            /* [annotation][size_is][unique][in] */ 
            _In_reads_(lLunCount)  VDS_LUN_INFORMATION *rgSourceLuns,
            /* [annotation][size_is][out][in] */ 
            _Inout_updates_(lLunCount)  VDS_LUN_INFORMATION *rgDestinationLuns);
        
        DECLSPEC_XFGVIRT(IVssHardwareSnapshotProvider, LocateLuns)
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *LocateLuns )( 
            __RPC__in IVssHardwareSnapshotProviderEx * This,
            /* [annotation][in] */ 
            _In_  LONG lLunCount,
            /* [annotation][size_is][unique][in] */ 
            _In_reads_(lLunCount)  VDS_LUN_INFORMATION *rgSourceLuns);
        
        DECLSPEC_XFGVIRT(IVssHardwareSnapshotProvider, OnLunEmpty)
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *OnLunEmpty )( 
            __RPC__in IVssHardwareSnapshotProviderEx * This,
            /* [annotation][unique][in] */ 
            _In_  VSS_PWSZ wszDeviceName,
            /* [annotation][unique][in] */ 
            _In_  VDS_LUN_INFORMATION *pInformation);
        
        DECLSPEC_XFGVIRT(IVssHardwareSnapshotProviderEx, GetProviderCapabilities)
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetProviderCapabilities )( 
            __RPC__in IVssHardwareSnapshotProviderEx * This,
            /* [annotation][out] */ 
            _Out_  ULONGLONG *pllOriginalCapabilityMask);
        
        DECLSPEC_XFGVIRT(IVssHardwareSnapshotProviderEx, OnLunStateChange)
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *OnLunStateChange )( 
            __RPC__in IVssHardwareSnapshotProviderEx * This,
            /* [annotation][size_is][unique][in] */ 
            _In_reads_(dwCount)  VDS_LUN_INFORMATION *pSnapshotLuns,
            /* [annotation][size_is][unique][in] */ 
            _In_reads_(dwCount)  VDS_LUN_INFORMATION *pOriginalLuns,
            /* [annotation][in] */ 
            _In_  DWORD dwCount,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags);
        
        DECLSPEC_XFGVIRT(IVssHardwareSnapshotProviderEx, ResyncLuns)
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ResyncLuns )( 
            __RPC__in IVssHardwareSnapshotProviderEx * This,
            /* [annotation][size_is][unique][in] */ 
            _In_reads_(dwCount)  VDS_LUN_INFORMATION *pSourceLuns,
            /* [annotation][size_is][unique][in] */ 
            _In_reads_(dwCount)  VDS_LUN_INFORMATION *pTargetLuns,
            /* [annotation][in] */ 
            _In_  DWORD dwCount,
            /* [annotation][out] */ 
            _Out_  IVssAsync **ppAsync);
        
        DECLSPEC_XFGVIRT(IVssHardwareSnapshotProviderEx, OnReuseLuns)
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *OnReuseLuns )( 
            __RPC__in IVssHardwareSnapshotProviderEx * This,
            /* [annotation][size_is][unique][in] */ 
            _In_reads_(dwCount)  VDS_LUN_INFORMATION *pSnapshotLuns,
            /* [annotation][size_is][unique][in] */ 
            _In_reads_(dwCount)  VDS_LUN_INFORMATION *pOriginalLuns,
            /* [annotation][in] */ 
            _In_  DWORD dwCount);
        
        END_INTERFACE
    } IVssHardwareSnapshotProviderExVtbl;

    interface IVssHardwareSnapshotProviderEx
    {
        CONST_VTBL struct IVssHardwareSnapshotProviderExVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVssHardwareSnapshotProviderEx_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IVssHardwareSnapshotProviderEx_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IVssHardwareSnapshotProviderEx_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IVssHardwareSnapshotProviderEx_AreLunsSupported(This,lLunCount,lContext,rgwszDevices,pLunInformation,pbIsSupported)	\
    ( (This)->lpVtbl -> AreLunsSupported(This,lLunCount,lContext,rgwszDevices,pLunInformation,pbIsSupported) ) 

#define IVssHardwareSnapshotProviderEx_FillInLunInfo(This,wszDeviceName,pLunInfo,pbIsSupported)	\
    ( (This)->lpVtbl -> FillInLunInfo(This,wszDeviceName,pLunInfo,pbIsSupported) ) 

#define IVssHardwareSnapshotProviderEx_BeginPrepareSnapshot(This,SnapshotSetId,SnapshotId,lContext,lLunCount,rgDeviceNames,rgLunInformation)	\
    ( (This)->lpVtbl -> BeginPrepareSnapshot(This,SnapshotSetId,SnapshotId,lContext,lLunCount,rgDeviceNames,rgLunInformation) ) 

#define IVssHardwareSnapshotProviderEx_GetTargetLuns(This,lLunCount,rgDeviceNames,rgSourceLuns,rgDestinationLuns)	\
    ( (This)->lpVtbl -> GetTargetLuns(This,lLunCount,rgDeviceNames,rgSourceLuns,rgDestinationLuns) ) 

#define IVssHardwareSnapshotProviderEx_LocateLuns(This,lLunCount,rgSourceLuns)	\
    ( (This)->lpVtbl -> LocateLuns(This,lLunCount,rgSourceLuns) ) 

#define IVssHardwareSnapshotProviderEx_OnLunEmpty(This,wszDeviceName,pInformation)	\
    ( (This)->lpVtbl -> OnLunEmpty(This,wszDeviceName,pInformation) ) 


#define IVssHardwareSnapshotProviderEx_GetProviderCapabilities(This,pllOriginalCapabilityMask)	\
    ( (This)->lpVtbl -> GetProviderCapabilities(This,pllOriginalCapabilityMask) ) 

#define IVssHardwareSnapshotProviderEx_OnLunStateChange(This,pSnapshotLuns,pOriginalLuns,dwCount,dwFlags)	\
    ( (This)->lpVtbl -> OnLunStateChange(This,pSnapshotLuns,pOriginalLuns,dwCount,dwFlags) ) 

#define IVssHardwareSnapshotProviderEx_ResyncLuns(This,pSourceLuns,pTargetLuns,dwCount,ppAsync)	\
    ( (This)->lpVtbl -> ResyncLuns(This,pSourceLuns,pTargetLuns,dwCount,ppAsync) ) 

#define IVssHardwareSnapshotProviderEx_OnReuseLuns(This,pSnapshotLuns,pOriginalLuns,dwCount)	\
    ( (This)->lpVtbl -> OnReuseLuns(This,pSnapshotLuns,pOriginalLuns,dwCount) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IVssHardwareSnapshotProviderEx_INTERFACE_DEFINED__ */


#ifndef __IVssFileShareSnapshotProvider_INTERFACE_DEFINED__
#define __IVssFileShareSnapshotProvider_INTERFACE_DEFINED__

/* interface IVssFileShareSnapshotProvider */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IVssFileShareSnapshotProvider;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("c8636060-7c2e-11df-8c4a-0800200c9a66")
    IVssFileShareSnapshotProvider : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetContext( 
            /* [annotation][in] */ 
            _In_  LONG lContext) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetSnapshotProperties( 
            /* [annotation][in] */ 
            _In_  VSS_ID SnapshotId,
            /* [annotation][out] */ 
            _Out_  VSS_SNAPSHOT_PROP *pProp) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Query( 
            /* [annotation][in] */ 
            _In_  VSS_ID QueriedObjectId,
            /* [annotation][in] */ 
            _In_  VSS_OBJECT_TYPE eQueriedObjectType,
            /* [annotation][in] */ 
            _In_  VSS_OBJECT_TYPE eReturnedObjectsType,
            /* [annotation][out] */ 
            _Out_  IVssEnumObject **ppEnum) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE DeleteSnapshots( 
            /* [annotation][in] */ 
            _In_  VSS_ID SourceObjectId,
            /* [annotation][in] */ 
            _In_  VSS_OBJECT_TYPE eSourceObjectType,
            /* [annotation][in] */ 
            _In_  BOOL bForceDelete,
            /* [annotation][out] */ 
            _Out_  LONG *plDeletedSnapshots,
            /* [annotation][out] */ 
            _Out_  VSS_ID *pNondeletedSnapshotID) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE BeginPrepareSnapshot( 
            /* [annotation][in] */ 
            _In_  VSS_ID SnapshotSetId,
            /* [annotation][in] */ 
            _In_  VSS_ID SnapshotId,
            /* [annotation][in] */ 
            _In_  VSS_PWSZ pwszSharePath,
            /* [annotation][in] */ 
            _In_  LONG lNewContext,
            /* [annotation][in] */ 
            _In_  VSS_ID ProviderId) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE IsPathSupported( 
            /* [annotation][in] */ 
            _In_  VSS_PWSZ pwszSharePath,
            /* [annotation][out] */ 
            _Out_  BOOL *pbSupportedByThisProvider) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE IsPathSnapshotted( 
            /* [annotation][in] */ 
            _In_  VSS_PWSZ pwszSharePath,
            /* [annotation][out] */ 
            _Out_  BOOL *pbSnapshotsPresent,
            /* [annotation][out] */ 
            _Out_  LONG *plSnapshotCompatibility) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetSnapshotProperty( 
            /* [annotation][in] */ 
            _In_  VSS_ID SnapshotId,
            /* [annotation][in] */ 
            _In_  VSS_SNAPSHOT_PROPERTY_ID eSnapshotPropertyId,
            /* [annotation][in] */ 
            _In_  VARIANT vProperty) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IVssFileShareSnapshotProviderVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IVssFileShareSnapshotProvider * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IVssFileShareSnapshotProvider * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IVssFileShareSnapshotProvider * This);
        
        DECLSPEC_XFGVIRT(IVssFileShareSnapshotProvider, SetContext)
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetContext )( 
            __RPC__in IVssFileShareSnapshotProvider * This,
            /* [annotation][in] */ 
            _In_  LONG lContext);
        
        DECLSPEC_XFGVIRT(IVssFileShareSnapshotProvider, GetSnapshotProperties)
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetSnapshotProperties )( 
            __RPC__in IVssFileShareSnapshotProvider * This,
            /* [annotation][in] */ 
            _In_  VSS_ID SnapshotId,
            /* [annotation][out] */ 
            _Out_  VSS_SNAPSHOT_PROP *pProp);
        
        DECLSPEC_XFGVIRT(IVssFileShareSnapshotProvider, Query)
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Query )( 
            __RPC__in IVssFileShareSnapshotProvider * This,
            /* [annotation][in] */ 
            _In_  VSS_ID QueriedObjectId,
            /* [annotation][in] */ 
            _In_  VSS_OBJECT_TYPE eQueriedObjectType,
            /* [annotation][in] */ 
            _In_  VSS_OBJECT_TYPE eReturnedObjectsType,
            /* [annotation][out] */ 
            _Out_  IVssEnumObject **ppEnum);
        
        DECLSPEC_XFGVIRT(IVssFileShareSnapshotProvider, DeleteSnapshots)
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *DeleteSnapshots )( 
            __RPC__in IVssFileShareSnapshotProvider * This,
            /* [annotation][in] */ 
            _In_  VSS_ID SourceObjectId,
            /* [annotation][in] */ 
            _In_  VSS_OBJECT_TYPE eSourceObjectType,
            /* [annotation][in] */ 
            _In_  BOOL bForceDelete,
            /* [annotation][out] */ 
            _Out_  LONG *plDeletedSnapshots,
            /* [annotation][out] */ 
            _Out_  VSS_ID *pNondeletedSnapshotID);
        
        DECLSPEC_XFGVIRT(IVssFileShareSnapshotProvider, BeginPrepareSnapshot)
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *BeginPrepareSnapshot )( 
            __RPC__in IVssFileShareSnapshotProvider * This,
            /* [annotation][in] */ 
            _In_  VSS_ID SnapshotSetId,
            /* [annotation][in] */ 
            _In_  VSS_ID SnapshotId,
            /* [annotation][in] */ 
            _In_  VSS_PWSZ pwszSharePath,
            /* [annotation][in] */ 
            _In_  LONG lNewContext,
            /* [annotation][in] */ 
            _In_  VSS_ID ProviderId);
        
        DECLSPEC_XFGVIRT(IVssFileShareSnapshotProvider, IsPathSupported)
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *IsPathSupported )( 
            __RPC__in IVssFileShareSnapshotProvider * This,
            /* [annotation][in] */ 
            _In_  VSS_PWSZ pwszSharePath,
            /* [annotation][out] */ 
            _Out_  BOOL *pbSupportedByThisProvider);
        
        DECLSPEC_XFGVIRT(IVssFileShareSnapshotProvider, IsPathSnapshotted)
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *IsPathSnapshotted )( 
            __RPC__in IVssFileShareSnapshotProvider * This,
            /* [annotation][in] */ 
            _In_  VSS_PWSZ pwszSharePath,
            /* [annotation][out] */ 
            _Out_  BOOL *pbSnapshotsPresent,
            /* [annotation][out] */ 
            _Out_  LONG *plSnapshotCompatibility);
        
        DECLSPEC_XFGVIRT(IVssFileShareSnapshotProvider, SetSnapshotProperty)
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetSnapshotProperty )( 
            __RPC__in IVssFileShareSnapshotProvider * This,
            /* [annotation][in] */ 
            _In_  VSS_ID SnapshotId,
            /* [annotation][in] */ 
            _In_  VSS_SNAPSHOT_PROPERTY_ID eSnapshotPropertyId,
            /* [annotation][in] */ 
            _In_  VARIANT vProperty);
        
        END_INTERFACE
    } IVssFileShareSnapshotProviderVtbl;

    interface IVssFileShareSnapshotProvider
    {
        CONST_VTBL struct IVssFileShareSnapshotProviderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVssFileShareSnapshotProvider_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IVssFileShareSnapshotProvider_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IVssFileShareSnapshotProvider_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IVssFileShareSnapshotProvider_SetContext(This,lContext)	\
    ( (This)->lpVtbl -> SetContext(This,lContext) ) 

#define IVssFileShareSnapshotProvider_GetSnapshotProperties(This,SnapshotId,pProp)	\
    ( (This)->lpVtbl -> GetSnapshotProperties(This,SnapshotId,pProp) ) 

#define IVssFileShareSnapshotProvider_Query(This,QueriedObjectId,eQueriedObjectType,eReturnedObjectsType,ppEnum)	\
    ( (This)->lpVtbl -> Query(This,QueriedObjectId,eQueriedObjectType,eReturnedObjectsType,ppEnum) ) 

#define IVssFileShareSnapshotProvider_DeleteSnapshots(This,SourceObjectId,eSourceObjectType,bForceDelete,plDeletedSnapshots,pNondeletedSnapshotID)	\
    ( (This)->lpVtbl -> DeleteSnapshots(This,SourceObjectId,eSourceObjectType,bForceDelete,plDeletedSnapshots,pNondeletedSnapshotID) ) 

#define IVssFileShareSnapshotProvider_BeginPrepareSnapshot(This,SnapshotSetId,SnapshotId,pwszSharePath,lNewContext,ProviderId)	\
    ( (This)->lpVtbl -> BeginPrepareSnapshot(This,SnapshotSetId,SnapshotId,pwszSharePath,lNewContext,ProviderId) ) 

#define IVssFileShareSnapshotProvider_IsPathSupported(This,pwszSharePath,pbSupportedByThisProvider)	\
    ( (This)->lpVtbl -> IsPathSupported(This,pwszSharePath,pbSupportedByThisProvider) ) 

#define IVssFileShareSnapshotProvider_IsPathSnapshotted(This,pwszSharePath,pbSnapshotsPresent,plSnapshotCompatibility)	\
    ( (This)->lpVtbl -> IsPathSnapshotted(This,pwszSharePath,pbSnapshotsPresent,plSnapshotCompatibility) ) 

#define IVssFileShareSnapshotProvider_SetSnapshotProperty(This,SnapshotId,eSnapshotPropertyId,vProperty)	\
    ( (This)->lpVtbl -> SetSnapshotProperty(This,SnapshotId,eSnapshotPropertyId,vProperty) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IVssFileShareSnapshotProvider_INTERFACE_DEFINED__ */



#ifndef __VSSProvider_LIBRARY_DEFINED__
#define __VSSProvider_LIBRARY_DEFINED__

/* library VSSProvider */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_VSSProvider;
#endif /* __VSSProvider_LIBRARY_DEFINED__ */

/* interface __MIDL_itf_vsprov_0000_0007 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_vsprov_0000_0007_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vsprov_0000_0007_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  VARIANT_UserSize(     __RPC__in unsigned long *, unsigned long            , __RPC__in VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree(     __RPC__in unsigned long *, __RPC__in VARIANT * ); 

unsigned long             __RPC_USER  VARIANT_UserSize64(     __RPC__in unsigned long *, unsigned long            , __RPC__in VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal64(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal64(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree64(     __RPC__in unsigned long *, __RPC__in VARIANT * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


