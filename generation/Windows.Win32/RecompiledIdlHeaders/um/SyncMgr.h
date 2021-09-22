

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

#ifndef __syncmgr_h__
#define __syncmgr_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ISyncMgrHandlerCollection_FWD_DEFINED__
#define __ISyncMgrHandlerCollection_FWD_DEFINED__
typedef interface ISyncMgrHandlerCollection ISyncMgrHandlerCollection;

#endif 	/* __ISyncMgrHandlerCollection_FWD_DEFINED__ */


#ifndef __ISyncMgrHandler_FWD_DEFINED__
#define __ISyncMgrHandler_FWD_DEFINED__
typedef interface ISyncMgrHandler ISyncMgrHandler;

#endif 	/* __ISyncMgrHandler_FWD_DEFINED__ */


#ifndef __ISyncMgrHandlerInfo_FWD_DEFINED__
#define __ISyncMgrHandlerInfo_FWD_DEFINED__
typedef interface ISyncMgrHandlerInfo ISyncMgrHandlerInfo;

#endif 	/* __ISyncMgrHandlerInfo_FWD_DEFINED__ */


#ifndef __ISyncMgrSyncItemContainer_FWD_DEFINED__
#define __ISyncMgrSyncItemContainer_FWD_DEFINED__
typedef interface ISyncMgrSyncItemContainer ISyncMgrSyncItemContainer;

#endif 	/* __ISyncMgrSyncItemContainer_FWD_DEFINED__ */


#ifndef __ISyncMgrSyncItem_FWD_DEFINED__
#define __ISyncMgrSyncItem_FWD_DEFINED__
typedef interface ISyncMgrSyncItem ISyncMgrSyncItem;

#endif 	/* __ISyncMgrSyncItem_FWD_DEFINED__ */


#ifndef __ISyncMgrSyncItemInfo_FWD_DEFINED__
#define __ISyncMgrSyncItemInfo_FWD_DEFINED__
typedef interface ISyncMgrSyncItemInfo ISyncMgrSyncItemInfo;

#endif 	/* __ISyncMgrSyncItemInfo_FWD_DEFINED__ */


#ifndef __IEnumSyncMgrSyncItems_FWD_DEFINED__
#define __IEnumSyncMgrSyncItems_FWD_DEFINED__
typedef interface IEnumSyncMgrSyncItems IEnumSyncMgrSyncItems;

#endif 	/* __IEnumSyncMgrSyncItems_FWD_DEFINED__ */


#ifndef __ISyncMgrSessionCreator_FWD_DEFINED__
#define __ISyncMgrSessionCreator_FWD_DEFINED__
typedef interface ISyncMgrSessionCreator ISyncMgrSessionCreator;

#endif 	/* __ISyncMgrSessionCreator_FWD_DEFINED__ */


#ifndef __ISyncMgrSyncCallback_FWD_DEFINED__
#define __ISyncMgrSyncCallback_FWD_DEFINED__
typedef interface ISyncMgrSyncCallback ISyncMgrSyncCallback;

#endif 	/* __ISyncMgrSyncCallback_FWD_DEFINED__ */


#ifndef __ISyncMgrUIOperation_FWD_DEFINED__
#define __ISyncMgrUIOperation_FWD_DEFINED__
typedef interface ISyncMgrUIOperation ISyncMgrUIOperation;

#endif 	/* __ISyncMgrUIOperation_FWD_DEFINED__ */


#ifndef __ISyncMgrEventLinkUIOperation_FWD_DEFINED__
#define __ISyncMgrEventLinkUIOperation_FWD_DEFINED__
typedef interface ISyncMgrEventLinkUIOperation ISyncMgrEventLinkUIOperation;

#endif 	/* __ISyncMgrEventLinkUIOperation_FWD_DEFINED__ */


#ifndef __ISyncMgrScheduleWizardUIOperation_FWD_DEFINED__
#define __ISyncMgrScheduleWizardUIOperation_FWD_DEFINED__
typedef interface ISyncMgrScheduleWizardUIOperation ISyncMgrScheduleWizardUIOperation;

#endif 	/* __ISyncMgrScheduleWizardUIOperation_FWD_DEFINED__ */


#ifndef __ISyncMgrSyncResult_FWD_DEFINED__
#define __ISyncMgrSyncResult_FWD_DEFINED__
typedef interface ISyncMgrSyncResult ISyncMgrSyncResult;

#endif 	/* __ISyncMgrSyncResult_FWD_DEFINED__ */


#ifndef __ISyncMgrControl_FWD_DEFINED__
#define __ISyncMgrControl_FWD_DEFINED__
typedef interface ISyncMgrControl ISyncMgrControl;

#endif 	/* __ISyncMgrControl_FWD_DEFINED__ */


#ifndef __ISyncMgrEventStore_FWD_DEFINED__
#define __ISyncMgrEventStore_FWD_DEFINED__
typedef interface ISyncMgrEventStore ISyncMgrEventStore;

#endif 	/* __ISyncMgrEventStore_FWD_DEFINED__ */


#ifndef __ISyncMgrEvent_FWD_DEFINED__
#define __ISyncMgrEvent_FWD_DEFINED__
typedef interface ISyncMgrEvent ISyncMgrEvent;

#endif 	/* __ISyncMgrEvent_FWD_DEFINED__ */


#ifndef __IEnumSyncMgrEvents_FWD_DEFINED__
#define __IEnumSyncMgrEvents_FWD_DEFINED__
typedef interface IEnumSyncMgrEvents IEnumSyncMgrEvents;

#endif 	/* __IEnumSyncMgrEvents_FWD_DEFINED__ */


#ifndef __ISyncMgrConflictStore_FWD_DEFINED__
#define __ISyncMgrConflictStore_FWD_DEFINED__
typedef interface ISyncMgrConflictStore ISyncMgrConflictStore;

#endif 	/* __ISyncMgrConflictStore_FWD_DEFINED__ */


#ifndef __IEnumSyncMgrConflict_FWD_DEFINED__
#define __IEnumSyncMgrConflict_FWD_DEFINED__
typedef interface IEnumSyncMgrConflict IEnumSyncMgrConflict;

#endif 	/* __IEnumSyncMgrConflict_FWD_DEFINED__ */


#ifndef __ISyncMgrConflict_FWD_DEFINED__
#define __ISyncMgrConflict_FWD_DEFINED__
typedef interface ISyncMgrConflict ISyncMgrConflict;

#endif 	/* __ISyncMgrConflict_FWD_DEFINED__ */


#ifndef __ISyncMgrResolutionHandler_FWD_DEFINED__
#define __ISyncMgrResolutionHandler_FWD_DEFINED__
typedef interface ISyncMgrResolutionHandler ISyncMgrResolutionHandler;

#endif 	/* __ISyncMgrResolutionHandler_FWD_DEFINED__ */


#ifndef __ISyncMgrConflictPresenter_FWD_DEFINED__
#define __ISyncMgrConflictPresenter_FWD_DEFINED__
typedef interface ISyncMgrConflictPresenter ISyncMgrConflictPresenter;

#endif 	/* __ISyncMgrConflictPresenter_FWD_DEFINED__ */


#ifndef __ISyncMgrConflictResolveInfo_FWD_DEFINED__
#define __ISyncMgrConflictResolveInfo_FWD_DEFINED__
typedef interface ISyncMgrConflictResolveInfo ISyncMgrConflictResolveInfo;

#endif 	/* __ISyncMgrConflictResolveInfo_FWD_DEFINED__ */


#ifndef __ISyncMgrConflictFolder_FWD_DEFINED__
#define __ISyncMgrConflictFolder_FWD_DEFINED__
typedef interface ISyncMgrConflictFolder ISyncMgrConflictFolder;

#endif 	/* __ISyncMgrConflictFolder_FWD_DEFINED__ */


#ifndef __ISyncMgrConflictItems_FWD_DEFINED__
#define __ISyncMgrConflictItems_FWD_DEFINED__
typedef interface ISyncMgrConflictItems ISyncMgrConflictItems;

#endif 	/* __ISyncMgrConflictItems_FWD_DEFINED__ */


#ifndef __ISyncMgrConflictResolutionItems_FWD_DEFINED__
#define __ISyncMgrConflictResolutionItems_FWD_DEFINED__
typedef interface ISyncMgrConflictResolutionItems ISyncMgrConflictResolutionItems;

#endif 	/* __ISyncMgrConflictResolutionItems_FWD_DEFINED__ */


#ifndef __SyncMgrClient_FWD_DEFINED__
#define __SyncMgrClient_FWD_DEFINED__

#ifdef __cplusplus
typedef class SyncMgrClient SyncMgrClient;
#else
typedef struct SyncMgrClient SyncMgrClient;
#endif /* __cplusplus */

#endif 	/* __SyncMgrClient_FWD_DEFINED__ */


#ifndef __SyncMgrControl_FWD_DEFINED__
#define __SyncMgrControl_FWD_DEFINED__

#ifdef __cplusplus
typedef class SyncMgrControl SyncMgrControl;
#else
typedef struct SyncMgrControl SyncMgrControl;
#endif /* __cplusplus */

#endif 	/* __SyncMgrControl_FWD_DEFINED__ */


#ifndef __SyncMgrScheduleWizard_FWD_DEFINED__
#define __SyncMgrScheduleWizard_FWD_DEFINED__

#ifdef __cplusplus
typedef class SyncMgrScheduleWizard SyncMgrScheduleWizard;
#else
typedef struct SyncMgrScheduleWizard SyncMgrScheduleWizard;
#endif /* __cplusplus */

#endif 	/* __SyncMgrScheduleWizard_FWD_DEFINED__ */


#ifndef __SyncMgrFolder_FWD_DEFINED__
#define __SyncMgrFolder_FWD_DEFINED__

#ifdef __cplusplus
typedef class SyncMgrFolder SyncMgrFolder;
#else
typedef struct SyncMgrFolder SyncMgrFolder;
#endif /* __cplusplus */

#endif 	/* __SyncMgrFolder_FWD_DEFINED__ */


#ifndef __SyncSetupFolder_FWD_DEFINED__
#define __SyncSetupFolder_FWD_DEFINED__

#ifdef __cplusplus
typedef class SyncSetupFolder SyncSetupFolder;
#else
typedef struct SyncSetupFolder SyncSetupFolder;
#endif /* __cplusplus */

#endif 	/* __SyncSetupFolder_FWD_DEFINED__ */


#ifndef __ConflictFolder_FWD_DEFINED__
#define __ConflictFolder_FWD_DEFINED__

#ifdef __cplusplus
typedef class ConflictFolder ConflictFolder;
#else
typedef struct ConflictFolder ConflictFolder;
#endif /* __cplusplus */

#endif 	/* __ConflictFolder_FWD_DEFINED__ */


#ifndef __SyncResultsFolder_FWD_DEFINED__
#define __SyncResultsFolder_FWD_DEFINED__

#ifdef __cplusplus
typedef class SyncResultsFolder SyncResultsFolder;
#else
typedef struct SyncResultsFolder SyncResultsFolder;
#endif /* __cplusplus */

#endif 	/* __SyncResultsFolder_FWD_DEFINED__ */


#ifndef __SimpleConflictPresenter_FWD_DEFINED__
#define __SimpleConflictPresenter_FWD_DEFINED__

#ifdef __cplusplus
typedef class SimpleConflictPresenter SimpleConflictPresenter;
#else
typedef struct SimpleConflictPresenter SimpleConflictPresenter;
#endif /* __cplusplus */

#endif 	/* __SimpleConflictPresenter_FWD_DEFINED__ */


/* header files for imported files */
#include "objidl.h"
#include "oleidl.h"
#include "shobjidl_core.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_syncmgr_0000_0000 */
/* [local] */ 

#include <winapifamily.h>
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
























#define	MAX_SYNCMGR_ID	( 64 )

#define	MAX_SYNCMGR_PROGRESSTEXT	( 260 )

#define	MAX_SYNCMGR_NAME	( 128 )



extern RPC_IF_HANDLE __MIDL_itf_syncmgr_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_syncmgr_0000_0000_v0_0_s_ifspec;

#ifndef __ISyncMgrHandlerCollection_INTERFACE_DEFINED__
#define __ISyncMgrHandlerCollection_INTERFACE_DEFINED__

/* interface ISyncMgrHandlerCollection */
/* [uuid][object] */ 


EXTERN_C const IID IID_ISyncMgrHandlerCollection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("a7f337a3-d20b-45cb-9ed7-87d094ca5045")
    ISyncMgrHandlerCollection : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetHandlerEnumerator( 
            /* [annotation][out] */ 
            _Out_  IEnumString **ppenum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE BindToHandler( 
            /* [string][ref][in] */ __RPC__in_string LPCWSTR pszHandlerID,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppv) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISyncMgrHandlerCollectionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISyncMgrHandlerCollection * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISyncMgrHandlerCollection * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISyncMgrHandlerCollection * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetHandlerEnumerator )( 
            __RPC__in ISyncMgrHandlerCollection * This,
            /* [annotation][out] */ 
            _Out_  IEnumString **ppenum);
        
        HRESULT ( STDMETHODCALLTYPE *BindToHandler )( 
            __RPC__in ISyncMgrHandlerCollection * This,
            /* [string][ref][in] */ __RPC__in_string LPCWSTR pszHandlerID,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppv);
        
        END_INTERFACE
    } ISyncMgrHandlerCollectionVtbl;

    interface ISyncMgrHandlerCollection
    {
        CONST_VTBL struct ISyncMgrHandlerCollectionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISyncMgrHandlerCollection_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISyncMgrHandlerCollection_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISyncMgrHandlerCollection_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISyncMgrHandlerCollection_GetHandlerEnumerator(This,ppenum)	\
    ( (This)->lpVtbl -> GetHandlerEnumerator(This,ppenum) ) 

#define ISyncMgrHandlerCollection_BindToHandler(This,pszHandlerID,riid,ppv)	\
    ( (This)->lpVtbl -> BindToHandler(This,pszHandlerID,riid,ppv) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISyncMgrHandlerCollection_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_syncmgr_0000_0001 */
/* [local] */ 

typedef /* [v1_enum] */ 
enum SYNCMGR_HANDLER_CAPABILITIES
    {
        SYNCMGR_HCM_NONE	= 0,
        SYNCMGR_HCM_PROVIDES_ICON	= 0x1,
        SYNCMGR_HCM_EVENT_STORE	= 0x2,
        SYNCMGR_HCM_CONFLICT_STORE	= 0x4,
        SYNCMGR_HCM_SUPPORTS_CONCURRENT_SESSIONS	= 0x10,
        SYNCMGR_HCM_CAN_BROWSE_CONTENT	= 0x10000,
        SYNCMGR_HCM_CAN_SHOW_SCHEDULE	= 0x20000,
        SYNCMGR_HCM_QUERY_BEFORE_ACTIVATE	= 0x100000,
        SYNCMGR_HCM_QUERY_BEFORE_DEACTIVATE	= 0x200000,
        SYNCMGR_HCM_QUERY_BEFORE_ENABLE	= 0x400000,
        SYNCMGR_HCM_QUERY_BEFORE_DISABLE	= 0x800000,
        SYNCMGR_HCM_VALID_MASK	= 0xf30017
    } 	SYNCMGR_HANDLER_CAPABILITIES;

typedef /* [v1_enum] */ 
enum SYNCMGR_HANDLER_POLICIES
    {
        SYNCMGR_HPM_NONE	= 0,
        SYNCMGR_HPM_PREVENT_ACTIVATE	= 0x1,
        SYNCMGR_HPM_PREVENT_DEACTIVATE	= 0x2,
        SYNCMGR_HPM_PREVENT_ENABLE	= 0x4,
        SYNCMGR_HPM_PREVENT_DISABLE	= 0x8,
        SYNCMGR_HPM_PREVENT_START_SYNC	= 0x10,
        SYNCMGR_HPM_PREVENT_STOP_SYNC	= 0x20,
        SYNCMGR_HPM_DISABLE_ENABLE	= 0x100,
        SYNCMGR_HPM_DISABLE_DISABLE	= 0x200,
        SYNCMGR_HPM_DISABLE_START_SYNC	= 0x400,
        SYNCMGR_HPM_DISABLE_STOP_SYNC	= 0x800,
        SYNCMGR_HPM_DISABLE_BROWSE	= 0x1000,
        SYNCMGR_HPM_DISABLE_SCHEDULE	= 0x2000,
        SYNCMGR_HPM_HIDDEN_BY_DEFAULT	= 0x10000,
        SYNCMGR_HPM_BACKGROUND_SYNC_ONLY	= ( SYNCMGR_HPM_PREVENT_START_SYNC | SYNCMGR_HPM_PREVENT_STOP_SYNC ) ,
        SYNCMGR_HPM_VALID_MASK	= 0x12f3f
    } 	SYNCMGR_HANDLER_POLICIES;



extern RPC_IF_HANDLE __MIDL_itf_syncmgr_0000_0001_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_syncmgr_0000_0001_v0_0_s_ifspec;

#ifndef __ISyncMgrHandler_INTERFACE_DEFINED__
#define __ISyncMgrHandler_INTERFACE_DEFINED__

/* interface ISyncMgrHandler */
/* [uuid][object] */ 


EXTERN_C const IID IID_ISyncMgrHandler;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("04ec2e43-ac77-49f9-9b98-0307ef7a72a2")
    ISyncMgrHandler : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetName( 
            /* [annotation][string][out] */ 
            _Out_  LPWSTR *ppszName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetHandlerInfo( 
            /* [annotation][out] */ 
            _Out_  ISyncMgrHandlerInfo **ppHandlerInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetObject( 
            /* [annotation][in] */ 
            _In_  REFGUID rguidObjectID,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppv) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCapabilities( 
            /* [annotation][out] */ 
            _Out_  SYNCMGR_HANDLER_CAPABILITIES *pmCapabilities) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPolicies( 
            /* [annotation][out] */ 
            _Out_  SYNCMGR_HANDLER_POLICIES *pmPolicies) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Activate( 
            /* [annotation][in] */ 
            _In_  BOOL fActivate) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Enable( 
            /* [annotation][in] */ 
            _In_  BOOL fEnable) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Synchronize( 
            /* [size_is][string][ref][in] */ __RPC__in_ecount_full(cItems) LPCWSTR *ppszItemIDs,
            /* [annotation][in] */ 
            _In_  ULONG cItems,
            /* [annotation][unique][in] */ 
            _In_  HWND hwndOwner,
            /* [annotation][in] */ 
            _In_  ISyncMgrSessionCreator *pSessionCreator,
            /* [annotation][unique][in] */ 
            _In_  IUnknown *punk) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISyncMgrHandlerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISyncMgrHandler * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISyncMgrHandler * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISyncMgrHandler * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetName )( 
            __RPC__in ISyncMgrHandler * This,
            /* [annotation][string][out] */ 
            _Out_  LPWSTR *ppszName);
        
        HRESULT ( STDMETHODCALLTYPE *GetHandlerInfo )( 
            __RPC__in ISyncMgrHandler * This,
            /* [annotation][out] */ 
            _Out_  ISyncMgrHandlerInfo **ppHandlerInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetObject )( 
            __RPC__in ISyncMgrHandler * This,
            /* [annotation][in] */ 
            _In_  REFGUID rguidObjectID,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppv);
        
        HRESULT ( STDMETHODCALLTYPE *GetCapabilities )( 
            __RPC__in ISyncMgrHandler * This,
            /* [annotation][out] */ 
            _Out_  SYNCMGR_HANDLER_CAPABILITIES *pmCapabilities);
        
        HRESULT ( STDMETHODCALLTYPE *GetPolicies )( 
            __RPC__in ISyncMgrHandler * This,
            /* [annotation][out] */ 
            _Out_  SYNCMGR_HANDLER_POLICIES *pmPolicies);
        
        HRESULT ( STDMETHODCALLTYPE *Activate )( 
            __RPC__in ISyncMgrHandler * This,
            /* [annotation][in] */ 
            _In_  BOOL fActivate);
        
        HRESULT ( STDMETHODCALLTYPE *Enable )( 
            __RPC__in ISyncMgrHandler * This,
            /* [annotation][in] */ 
            _In_  BOOL fEnable);
        
        HRESULT ( STDMETHODCALLTYPE *Synchronize )( 
            __RPC__in ISyncMgrHandler * This,
            /* [size_is][string][ref][in] */ __RPC__in_ecount_full(cItems) LPCWSTR *ppszItemIDs,
            /* [annotation][in] */ 
            _In_  ULONG cItems,
            /* [annotation][unique][in] */ 
            _In_  HWND hwndOwner,
            /* [annotation][in] */ 
            _In_  ISyncMgrSessionCreator *pSessionCreator,
            /* [annotation][unique][in] */ 
            _In_  IUnknown *punk);
        
        END_INTERFACE
    } ISyncMgrHandlerVtbl;

    interface ISyncMgrHandler
    {
        CONST_VTBL struct ISyncMgrHandlerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISyncMgrHandler_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISyncMgrHandler_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISyncMgrHandler_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISyncMgrHandler_GetName(This,ppszName)	\
    ( (This)->lpVtbl -> GetName(This,ppszName) ) 

#define ISyncMgrHandler_GetHandlerInfo(This,ppHandlerInfo)	\
    ( (This)->lpVtbl -> GetHandlerInfo(This,ppHandlerInfo) ) 

#define ISyncMgrHandler_GetObject(This,rguidObjectID,riid,ppv)	\
    ( (This)->lpVtbl -> GetObject(This,rguidObjectID,riid,ppv) ) 

#define ISyncMgrHandler_GetCapabilities(This,pmCapabilities)	\
    ( (This)->lpVtbl -> GetCapabilities(This,pmCapabilities) ) 

#define ISyncMgrHandler_GetPolicies(This,pmPolicies)	\
    ( (This)->lpVtbl -> GetPolicies(This,pmPolicies) ) 

#define ISyncMgrHandler_Activate(This,fActivate)	\
    ( (This)->lpVtbl -> Activate(This,fActivate) ) 

#define ISyncMgrHandler_Enable(This,fEnable)	\
    ( (This)->lpVtbl -> Enable(This,fEnable) ) 

#define ISyncMgrHandler_Synchronize(This,ppszItemIDs,cItems,hwndOwner,pSessionCreator,punk)	\
    ( (This)->lpVtbl -> Synchronize(This,ppszItemIDs,cItems,hwndOwner,pSessionCreator,punk) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISyncMgrHandler_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_syncmgr_0000_0002 */
/* [local] */ 

typedef /* [v1_enum] */ 
enum SYNCMGR_HANDLER_TYPE
    {
        SYNCMGR_HT_UNSPECIFIED	= 0,
        SYNCMGR_HT_APPLICATION	= 1,
        SYNCMGR_HT_DEVICE	= 2,
        SYNCMGR_HT_FOLDER	= 3,
        SYNCMGR_HT_SERVICE	= 4,
        SYNCMGR_HT_COMPUTER	= 5,
        SYNCMGR_HT_MIN	= 0,
        SYNCMGR_HT_MAX	= SYNCMGR_HT_COMPUTER
    } 	SYNCMGR_HANDLER_TYPE;



extern RPC_IF_HANDLE __MIDL_itf_syncmgr_0000_0002_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_syncmgr_0000_0002_v0_0_s_ifspec;

#ifndef __ISyncMgrHandlerInfo_INTERFACE_DEFINED__
#define __ISyncMgrHandlerInfo_INTERFACE_DEFINED__

/* interface ISyncMgrHandlerInfo */
/* [uuid][object] */ 


EXTERN_C const IID IID_ISyncMgrHandlerInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4ff1d798-ecf7-4524-aa81-1e362a0aef3a")
    ISyncMgrHandlerInfo : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetType( 
            /* [annotation][out] */ 
            _Out_  SYNCMGR_HANDLER_TYPE *pnType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTypeLabel( 
            /* [annotation][string][out] */ 
            _Out_  LPWSTR *ppszTypeLabel) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetComment( 
            /* [annotation][string][out] */ 
            _Out_  LPWSTR *ppszComment) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLastSyncTime( 
            /* [annotation][out] */ 
            _Out_  FILETIME *pftLastSync) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsActive( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsEnabled( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsConnected( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISyncMgrHandlerInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISyncMgrHandlerInfo * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISyncMgrHandlerInfo * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISyncMgrHandlerInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetType )( 
            __RPC__in ISyncMgrHandlerInfo * This,
            /* [annotation][out] */ 
            _Out_  SYNCMGR_HANDLER_TYPE *pnType);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeLabel )( 
            __RPC__in ISyncMgrHandlerInfo * This,
            /* [annotation][string][out] */ 
            _Out_  LPWSTR *ppszTypeLabel);
        
        HRESULT ( STDMETHODCALLTYPE *GetComment )( 
            __RPC__in ISyncMgrHandlerInfo * This,
            /* [annotation][string][out] */ 
            _Out_  LPWSTR *ppszComment);
        
        HRESULT ( STDMETHODCALLTYPE *GetLastSyncTime )( 
            __RPC__in ISyncMgrHandlerInfo * This,
            /* [annotation][out] */ 
            _Out_  FILETIME *pftLastSync);
        
        HRESULT ( STDMETHODCALLTYPE *IsActive )( 
            __RPC__in ISyncMgrHandlerInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *IsEnabled )( 
            __RPC__in ISyncMgrHandlerInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *IsConnected )( 
            __RPC__in ISyncMgrHandlerInfo * This);
        
        END_INTERFACE
    } ISyncMgrHandlerInfoVtbl;

    interface ISyncMgrHandlerInfo
    {
        CONST_VTBL struct ISyncMgrHandlerInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISyncMgrHandlerInfo_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISyncMgrHandlerInfo_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISyncMgrHandlerInfo_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISyncMgrHandlerInfo_GetType(This,pnType)	\
    ( (This)->lpVtbl -> GetType(This,pnType) ) 

#define ISyncMgrHandlerInfo_GetTypeLabel(This,ppszTypeLabel)	\
    ( (This)->lpVtbl -> GetTypeLabel(This,ppszTypeLabel) ) 

#define ISyncMgrHandlerInfo_GetComment(This,ppszComment)	\
    ( (This)->lpVtbl -> GetComment(This,ppszComment) ) 

#define ISyncMgrHandlerInfo_GetLastSyncTime(This,pftLastSync)	\
    ( (This)->lpVtbl -> GetLastSyncTime(This,pftLastSync) ) 

#define ISyncMgrHandlerInfo_IsActive(This)	\
    ( (This)->lpVtbl -> IsActive(This) ) 

#define ISyncMgrHandlerInfo_IsEnabled(This)	\
    ( (This)->lpVtbl -> IsEnabled(This) ) 

#define ISyncMgrHandlerInfo_IsConnected(This)	\
    ( (This)->lpVtbl -> IsConnected(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISyncMgrHandlerInfo_INTERFACE_DEFINED__ */


#ifndef __ISyncMgrSyncItemContainer_INTERFACE_DEFINED__
#define __ISyncMgrSyncItemContainer_INTERFACE_DEFINED__

/* interface ISyncMgrSyncItemContainer */
/* [uuid][object] */ 


EXTERN_C const IID IID_ISyncMgrSyncItemContainer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("90701133-be32-4129-a65c-99e616cafff4")
    ISyncMgrSyncItemContainer : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetSyncItem( 
            /* [string][ref][in] */ __RPC__in_string LPCWSTR pszItemID,
            /* [annotation][out] */ 
            _Out_  ISyncMgrSyncItem **ppItem) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSyncItemEnumerator( 
            /* [annotation][out] */ 
            _Out_  IEnumSyncMgrSyncItems **ppenum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSyncItemCount( 
            /* [annotation][out] */ 
            _Out_  ULONG *pcItems) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISyncMgrSyncItemContainerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISyncMgrSyncItemContainer * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISyncMgrSyncItemContainer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISyncMgrSyncItemContainer * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetSyncItem )( 
            __RPC__in ISyncMgrSyncItemContainer * This,
            /* [string][ref][in] */ __RPC__in_string LPCWSTR pszItemID,
            /* [annotation][out] */ 
            _Out_  ISyncMgrSyncItem **ppItem);
        
        HRESULT ( STDMETHODCALLTYPE *GetSyncItemEnumerator )( 
            __RPC__in ISyncMgrSyncItemContainer * This,
            /* [annotation][out] */ 
            _Out_  IEnumSyncMgrSyncItems **ppenum);
        
        HRESULT ( STDMETHODCALLTYPE *GetSyncItemCount )( 
            __RPC__in ISyncMgrSyncItemContainer * This,
            /* [annotation][out] */ 
            _Out_  ULONG *pcItems);
        
        END_INTERFACE
    } ISyncMgrSyncItemContainerVtbl;

    interface ISyncMgrSyncItemContainer
    {
        CONST_VTBL struct ISyncMgrSyncItemContainerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISyncMgrSyncItemContainer_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISyncMgrSyncItemContainer_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISyncMgrSyncItemContainer_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISyncMgrSyncItemContainer_GetSyncItem(This,pszItemID,ppItem)	\
    ( (This)->lpVtbl -> GetSyncItem(This,pszItemID,ppItem) ) 

#define ISyncMgrSyncItemContainer_GetSyncItemEnumerator(This,ppenum)	\
    ( (This)->lpVtbl -> GetSyncItemEnumerator(This,ppenum) ) 

#define ISyncMgrSyncItemContainer_GetSyncItemCount(This,pcItems)	\
    ( (This)->lpVtbl -> GetSyncItemCount(This,pcItems) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISyncMgrSyncItemContainer_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_syncmgr_0000_0004 */
/* [local] */ 

typedef /* [v1_enum] */ 
enum SYNCMGR_ITEM_CAPABILITIES
    {
        SYNCMGR_ICM_NONE	= 0,
        SYNCMGR_ICM_PROVIDES_ICON	= 0x1,
        SYNCMGR_ICM_EVENT_STORE	= 0x2,
        SYNCMGR_ICM_CONFLICT_STORE	= 0x4,
        SYNCMGR_ICM_CAN_DELETE	= 0x10,
        SYNCMGR_ICM_CAN_BROWSE_CONTENT	= 0x10000,
        SYNCMGR_ICM_QUERY_BEFORE_ENABLE	= 0x100000,
        SYNCMGR_ICM_QUERY_BEFORE_DISABLE	= 0x200000,
        SYNCMGR_ICM_QUERY_BEFORE_DELETE	= 0x400000,
        SYNCMGR_ICM_VALID_MASK	= 0x710017
    } 	SYNCMGR_ITEM_CAPABILITIES;

typedef /* [v1_enum] */ 
enum SYNCMGR_ITEM_POLICIES
    {
        SYNCMGR_IPM_NONE	= 0,
        SYNCMGR_IPM_PREVENT_ENABLE	= 0x1,
        SYNCMGR_IPM_PREVENT_DISABLE	= 0x2,
        SYNCMGR_IPM_PREVENT_START_SYNC	= 0x4,
        SYNCMGR_IPM_PREVENT_STOP_SYNC	= 0x8,
        SYNCMGR_IPM_DISABLE_ENABLE	= 0x10,
        SYNCMGR_IPM_DISABLE_DISABLE	= 0x20,
        SYNCMGR_IPM_DISABLE_START_SYNC	= 0x40,
        SYNCMGR_IPM_DISABLE_STOP_SYNC	= 0x80,
        SYNCMGR_IPM_DISABLE_BROWSE	= 0x100,
        SYNCMGR_IPM_DISABLE_DELETE	= 0x200,
        SYNCMGR_IPM_HIDDEN_BY_DEFAULT	= 0x10000,
        SYNCMGR_IPM_VALID_MASK	= 0x102ff
    } 	SYNCMGR_ITEM_POLICIES;



extern RPC_IF_HANDLE __MIDL_itf_syncmgr_0000_0004_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_syncmgr_0000_0004_v0_0_s_ifspec;

#ifndef __ISyncMgrSyncItem_INTERFACE_DEFINED__
#define __ISyncMgrSyncItem_INTERFACE_DEFINED__

/* interface ISyncMgrSyncItem */
/* [uuid][object] */ 


EXTERN_C const IID IID_ISyncMgrSyncItem;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("b20b24ce-2593-4f04-bd8b-7ad6c45051cd")
    ISyncMgrSyncItem : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetItemID( 
            /* [annotation][string][out] */ 
            _Out_  LPWSTR *ppszItemID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetName( 
            /* [annotation][string][out] */ 
            _Out_  LPWSTR *ppszName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetItemInfo( 
            /* [annotation][out] */ 
            _Out_  ISyncMgrSyncItemInfo **ppItemInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetObject( 
            /* [annotation][in] */ 
            _In_  REFGUID rguidObjectID,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppv) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCapabilities( 
            /* [annotation][out] */ 
            _Out_  SYNCMGR_ITEM_CAPABILITIES *pmCapabilities) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPolicies( 
            /* [annotation][out] */ 
            _Out_  SYNCMGR_ITEM_POLICIES *pmPolicies) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Enable( 
            /* [annotation][in] */ 
            _In_  BOOL fEnable) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Delete( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISyncMgrSyncItemVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISyncMgrSyncItem * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISyncMgrSyncItem * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISyncMgrSyncItem * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetItemID )( 
            __RPC__in ISyncMgrSyncItem * This,
            /* [annotation][string][out] */ 
            _Out_  LPWSTR *ppszItemID);
        
        HRESULT ( STDMETHODCALLTYPE *GetName )( 
            __RPC__in ISyncMgrSyncItem * This,
            /* [annotation][string][out] */ 
            _Out_  LPWSTR *ppszName);
        
        HRESULT ( STDMETHODCALLTYPE *GetItemInfo )( 
            __RPC__in ISyncMgrSyncItem * This,
            /* [annotation][out] */ 
            _Out_  ISyncMgrSyncItemInfo **ppItemInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetObject )( 
            __RPC__in ISyncMgrSyncItem * This,
            /* [annotation][in] */ 
            _In_  REFGUID rguidObjectID,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppv);
        
        HRESULT ( STDMETHODCALLTYPE *GetCapabilities )( 
            __RPC__in ISyncMgrSyncItem * This,
            /* [annotation][out] */ 
            _Out_  SYNCMGR_ITEM_CAPABILITIES *pmCapabilities);
        
        HRESULT ( STDMETHODCALLTYPE *GetPolicies )( 
            __RPC__in ISyncMgrSyncItem * This,
            /* [annotation][out] */ 
            _Out_  SYNCMGR_ITEM_POLICIES *pmPolicies);
        
        HRESULT ( STDMETHODCALLTYPE *Enable )( 
            __RPC__in ISyncMgrSyncItem * This,
            /* [annotation][in] */ 
            _In_  BOOL fEnable);
        
        HRESULT ( STDMETHODCALLTYPE *Delete )( 
            __RPC__in ISyncMgrSyncItem * This);
        
        END_INTERFACE
    } ISyncMgrSyncItemVtbl;

    interface ISyncMgrSyncItem
    {
        CONST_VTBL struct ISyncMgrSyncItemVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISyncMgrSyncItem_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISyncMgrSyncItem_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISyncMgrSyncItem_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISyncMgrSyncItem_GetItemID(This,ppszItemID)	\
    ( (This)->lpVtbl -> GetItemID(This,ppszItemID) ) 

#define ISyncMgrSyncItem_GetName(This,ppszName)	\
    ( (This)->lpVtbl -> GetName(This,ppszName) ) 

#define ISyncMgrSyncItem_GetItemInfo(This,ppItemInfo)	\
    ( (This)->lpVtbl -> GetItemInfo(This,ppItemInfo) ) 

#define ISyncMgrSyncItem_GetObject(This,rguidObjectID,riid,ppv)	\
    ( (This)->lpVtbl -> GetObject(This,rguidObjectID,riid,ppv) ) 

#define ISyncMgrSyncItem_GetCapabilities(This,pmCapabilities)	\
    ( (This)->lpVtbl -> GetCapabilities(This,pmCapabilities) ) 

#define ISyncMgrSyncItem_GetPolicies(This,pmPolicies)	\
    ( (This)->lpVtbl -> GetPolicies(This,pmPolicies) ) 

#define ISyncMgrSyncItem_Enable(This,fEnable)	\
    ( (This)->lpVtbl -> Enable(This,fEnable) ) 

#define ISyncMgrSyncItem_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISyncMgrSyncItem_INTERFACE_DEFINED__ */


#ifndef __ISyncMgrSyncItemInfo_INTERFACE_DEFINED__
#define __ISyncMgrSyncItemInfo_INTERFACE_DEFINED__

/* interface ISyncMgrSyncItemInfo */
/* [uuid][object] */ 


EXTERN_C const IID IID_ISyncMgrSyncItemInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("e7fd9502-be0c-4464-90a1-2b5277031232")
    ISyncMgrSyncItemInfo : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetTypeLabel( 
            /* [annotation][string][out] */ 
            _Out_  LPWSTR *ppszTypeLabel) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetComment( 
            /* [annotation][string][out] */ 
            _Out_  LPWSTR *ppszComment) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLastSyncTime( 
            /* [annotation][out] */ 
            _Out_  FILETIME *pftLastSync) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsEnabled( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsConnected( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISyncMgrSyncItemInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISyncMgrSyncItemInfo * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISyncMgrSyncItemInfo * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISyncMgrSyncItemInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeLabel )( 
            __RPC__in ISyncMgrSyncItemInfo * This,
            /* [annotation][string][out] */ 
            _Out_  LPWSTR *ppszTypeLabel);
        
        HRESULT ( STDMETHODCALLTYPE *GetComment )( 
            __RPC__in ISyncMgrSyncItemInfo * This,
            /* [annotation][string][out] */ 
            _Out_  LPWSTR *ppszComment);
        
        HRESULT ( STDMETHODCALLTYPE *GetLastSyncTime )( 
            __RPC__in ISyncMgrSyncItemInfo * This,
            /* [annotation][out] */ 
            _Out_  FILETIME *pftLastSync);
        
        HRESULT ( STDMETHODCALLTYPE *IsEnabled )( 
            __RPC__in ISyncMgrSyncItemInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *IsConnected )( 
            __RPC__in ISyncMgrSyncItemInfo * This);
        
        END_INTERFACE
    } ISyncMgrSyncItemInfoVtbl;

    interface ISyncMgrSyncItemInfo
    {
        CONST_VTBL struct ISyncMgrSyncItemInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISyncMgrSyncItemInfo_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISyncMgrSyncItemInfo_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISyncMgrSyncItemInfo_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISyncMgrSyncItemInfo_GetTypeLabel(This,ppszTypeLabel)	\
    ( (This)->lpVtbl -> GetTypeLabel(This,ppszTypeLabel) ) 

#define ISyncMgrSyncItemInfo_GetComment(This,ppszComment)	\
    ( (This)->lpVtbl -> GetComment(This,ppszComment) ) 

#define ISyncMgrSyncItemInfo_GetLastSyncTime(This,pftLastSync)	\
    ( (This)->lpVtbl -> GetLastSyncTime(This,pftLastSync) ) 

#define ISyncMgrSyncItemInfo_IsEnabled(This)	\
    ( (This)->lpVtbl -> IsEnabled(This) ) 

#define ISyncMgrSyncItemInfo_IsConnected(This)	\
    ( (This)->lpVtbl -> IsConnected(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISyncMgrSyncItemInfo_INTERFACE_DEFINED__ */


#ifndef __IEnumSyncMgrSyncItems_INTERFACE_DEFINED__
#define __IEnumSyncMgrSyncItems_INTERFACE_DEFINED__

/* interface IEnumSyncMgrSyncItems */
/* [uuid][object] */ 


EXTERN_C const IID IID_IEnumSyncMgrSyncItems;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("54b3abf3-f085-4181-b546-e29c403c726b")
    IEnumSyncMgrSyncItems : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [annotation][in] */ 
            _In_  ULONG celt,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(celt,*pceltFetched)  ISyncMgrSyncItem **rgelt,
            /* [annotation][out] */ 
            _Out_  ULONG *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [annotation][in] */ 
            _In_  ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [annotation][out] */ 
            _Out_  IEnumSyncMgrSyncItems **ppenum) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IEnumSyncMgrSyncItemsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IEnumSyncMgrSyncItems * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IEnumSyncMgrSyncItems * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IEnumSyncMgrSyncItems * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            __RPC__in IEnumSyncMgrSyncItems * This,
            /* [annotation][in] */ 
            _In_  ULONG celt,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(celt,*pceltFetched)  ISyncMgrSyncItem **rgelt,
            /* [annotation][out] */ 
            _Out_  ULONG *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            __RPC__in IEnumSyncMgrSyncItems * This,
            /* [annotation][in] */ 
            _In_  ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            __RPC__in IEnumSyncMgrSyncItems * This);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            __RPC__in IEnumSyncMgrSyncItems * This,
            /* [annotation][out] */ 
            _Out_  IEnumSyncMgrSyncItems **ppenum);
        
        END_INTERFACE
    } IEnumSyncMgrSyncItemsVtbl;

    interface IEnumSyncMgrSyncItems
    {
        CONST_VTBL struct IEnumSyncMgrSyncItemsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumSyncMgrSyncItems_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEnumSyncMgrSyncItems_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEnumSyncMgrSyncItems_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IEnumSyncMgrSyncItems_Next(This,celt,rgelt,pceltFetched)	\
    ( (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched) ) 

#define IEnumSyncMgrSyncItems_Skip(This,celt)	\
    ( (This)->lpVtbl -> Skip(This,celt) ) 

#define IEnumSyncMgrSyncItems_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define IEnumSyncMgrSyncItems_Clone(This,ppenum)	\
    ( (This)->lpVtbl -> Clone(This,ppenum) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IEnumSyncMgrSyncItems_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_syncmgr_0000_0007 */
/* [local] */ 

typedef /* [v1_enum] */ 
enum SYNCMGR_PROGRESS_STATUS
    {
        SYNCMGR_PS_UPDATING	= 1,
        SYNCMGR_PS_UPDATING_INDETERMINATE	= 2,
        SYNCMGR_PS_SUCCEEDED	= 3,
        SYNCMGR_PS_FAILED	= 4,
        SYNCMGR_PS_CANCELED	= 5,
        SYNCMGR_PS_DISCONNECTED	= 6,
        SYNCMGR_PS_MAX	= SYNCMGR_PS_DISCONNECTED
    } 	SYNCMGR_PROGRESS_STATUS;

typedef /* [v1_enum] */ 
enum SYNCMGR_CANCEL_REQUEST
    {
        SYNCMGR_CR_NONE	= 0,
        SYNCMGR_CR_CANCEL_ITEM	= 1,
        SYNCMGR_CR_CANCEL_ALL	= 2,
        SYNCMGR_CR_MAX	= SYNCMGR_CR_CANCEL_ALL
    } 	SYNCMGR_CANCEL_REQUEST;

typedef /* [v1_enum] */ 
enum SYNCMGR_EVENT_LEVEL
    {
        SYNCMGR_EL_INFORMATION	= 1,
        SYNCMGR_EL_WARNING	= 2,
        SYNCMGR_EL_ERROR	= 3,
        SYNCMGR_EL_MAX	= SYNCMGR_EL_ERROR
    } 	SYNCMGR_EVENT_LEVEL;

typedef /* [v1_enum] */ 
enum SYNCMGR_EVENT_FLAGS
    {
        SYNCMGR_EF_NONE	= 0,
        SYNCMGR_EF_VALID	= 0
    } 	SYNCMGR_EVENT_FLAGS;



extern RPC_IF_HANDLE __MIDL_itf_syncmgr_0000_0007_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_syncmgr_0000_0007_v0_0_s_ifspec;

#ifndef __ISyncMgrSessionCreator_INTERFACE_DEFINED__
#define __ISyncMgrSessionCreator_INTERFACE_DEFINED__

/* interface ISyncMgrSessionCreator */
/* [uuid][object] */ 


EXTERN_C const IID IID_ISyncMgrSessionCreator;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("17f48517-f305-4321-a08d-b25a834918fd")
    ISyncMgrSessionCreator : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CreateSession( 
            /* [string][ref][in] */ __RPC__in_string LPCWSTR pszHandlerID,
            /* [annotation][size_is][string][unique][in] */ 
            _In_reads_(cItems)  LPCWSTR *ppszItemIDs,
            /* [annotation][in] */ 
            _In_  ULONG cItems,
            /* [annotation][out] */ 
            _Out_  ISyncMgrSyncCallback **ppCallback) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISyncMgrSessionCreatorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISyncMgrSessionCreator * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISyncMgrSessionCreator * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISyncMgrSessionCreator * This);
        
        HRESULT ( STDMETHODCALLTYPE *CreateSession )( 
            __RPC__in ISyncMgrSessionCreator * This,
            /* [string][ref][in] */ __RPC__in_string LPCWSTR pszHandlerID,
            /* [annotation][size_is][string][unique][in] */ 
            _In_reads_(cItems)  LPCWSTR *ppszItemIDs,
            /* [annotation][in] */ 
            _In_  ULONG cItems,
            /* [annotation][out] */ 
            _Out_  ISyncMgrSyncCallback **ppCallback);
        
        END_INTERFACE
    } ISyncMgrSessionCreatorVtbl;

    interface ISyncMgrSessionCreator
    {
        CONST_VTBL struct ISyncMgrSessionCreatorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISyncMgrSessionCreator_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISyncMgrSessionCreator_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISyncMgrSessionCreator_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISyncMgrSessionCreator_CreateSession(This,pszHandlerID,ppszItemIDs,cItems,ppCallback)	\
    ( (This)->lpVtbl -> CreateSession(This,pszHandlerID,ppszItemIDs,cItems,ppCallback) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISyncMgrSessionCreator_INTERFACE_DEFINED__ */


#ifndef __ISyncMgrSyncCallback_INTERFACE_DEFINED__
#define __ISyncMgrSyncCallback_INTERFACE_DEFINED__

/* interface ISyncMgrSyncCallback */
/* [uuid][object] */ 


EXTERN_C const IID IID_ISyncMgrSyncCallback;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("884ccd87-b139-4937-a4ba-4f8e19513fbe")
    ISyncMgrSyncCallback : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ReportProgress( 
            /* [string][ref][in] */ __RPC__in_string LPCWSTR pszItemID,
            /* [annotation][string][unique][in] */ 
            _In_  LPCWSTR pszProgressText,
            /* [annotation][in] */ 
            _In_  SYNCMGR_PROGRESS_STATUS nStatus,
            /* [annotation][in] */ 
            _In_  ULONG uCurrentStep,
            /* [annotation][in] */ 
            _In_  ULONG uMaxStep,
            /* [annotation][unique][out][in] */ 
            _Inout_  SYNCMGR_CANCEL_REQUEST *pnCancelRequest) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetHandlerProgressText( 
            /* [string][ref][in] */ __RPC__in_string LPCWSTR pszProgressText,
            /* [annotation][unique][out][in] */ 
            _Inout_  SYNCMGR_CANCEL_REQUEST *pnCancelRequest) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReportEvent( 
            /* [annotation][string][unique][in] */ 
            _In_  LPCWSTR pszItemID,
            /* [annotation][in] */ 
            _In_  SYNCMGR_EVENT_LEVEL nLevel,
            /* [annotation][in] */ 
            _In_  SYNCMGR_EVENT_FLAGS nFlags,
            /* [string][ref][in] */ __RPC__in_string LPCWSTR pszName,
            /* [string][ref][in] */ __RPC__in_string LPCWSTR pszDescription,
            /* [annotation][string][unique][in] */ 
            _In_  LPCWSTR pszLinkText,
            /* [annotation][string][unique][in] */ 
            _In_  LPCWSTR pszLinkReference,
            /* [annotation][string][unique][in] */ 
            _In_  LPCWSTR pszContext,
            /* [annotation][out] */ 
            _Out_  GUID *pguidEventID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CanContinue( 
            /* [string][ref][in] */ __RPC__in_string LPCWSTR pszItemID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryForAdditionalItems( 
            /* [annotation][out] */ 
            _Out_  IEnumString **ppenumItemIDs,
            /* [annotation][out] */ 
            _Out_  IEnumUnknown **ppenumPunks) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddItemToSession( 
            /* [string][ref][in] */ __RPC__in_string LPCWSTR pszItemID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddIUnknownToSession( 
            /* [annotation][in] */ 
            _In_  IUnknown *punk) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ProposeItem( 
            /* [annotation][in] */ 
            _In_  ISyncMgrSyncItem *pNewItem) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CommitItem( 
            /* [string][ref][in] */ __RPC__in_string LPCWSTR pszItemID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReportManualSync( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISyncMgrSyncCallbackVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISyncMgrSyncCallback * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISyncMgrSyncCallback * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISyncMgrSyncCallback * This);
        
        HRESULT ( STDMETHODCALLTYPE *ReportProgress )( 
            __RPC__in ISyncMgrSyncCallback * This,
            /* [string][ref][in] */ __RPC__in_string LPCWSTR pszItemID,
            /* [annotation][string][unique][in] */ 
            _In_  LPCWSTR pszProgressText,
            /* [annotation][in] */ 
            _In_  SYNCMGR_PROGRESS_STATUS nStatus,
            /* [annotation][in] */ 
            _In_  ULONG uCurrentStep,
            /* [annotation][in] */ 
            _In_  ULONG uMaxStep,
            /* [annotation][unique][out][in] */ 
            _Inout_  SYNCMGR_CANCEL_REQUEST *pnCancelRequest);
        
        HRESULT ( STDMETHODCALLTYPE *SetHandlerProgressText )( 
            __RPC__in ISyncMgrSyncCallback * This,
            /* [string][ref][in] */ __RPC__in_string LPCWSTR pszProgressText,
            /* [annotation][unique][out][in] */ 
            _Inout_  SYNCMGR_CANCEL_REQUEST *pnCancelRequest);
        
        HRESULT ( STDMETHODCALLTYPE *ReportEvent )( 
            __RPC__in ISyncMgrSyncCallback * This,
            /* [annotation][string][unique][in] */ 
            _In_  LPCWSTR pszItemID,
            /* [annotation][in] */ 
            _In_  SYNCMGR_EVENT_LEVEL nLevel,
            /* [annotation][in] */ 
            _In_  SYNCMGR_EVENT_FLAGS nFlags,
            /* [string][ref][in] */ __RPC__in_string LPCWSTR pszName,
            /* [string][ref][in] */ __RPC__in_string LPCWSTR pszDescription,
            /* [annotation][string][unique][in] */ 
            _In_  LPCWSTR pszLinkText,
            /* [annotation][string][unique][in] */ 
            _In_  LPCWSTR pszLinkReference,
            /* [annotation][string][unique][in] */ 
            _In_  LPCWSTR pszContext,
            /* [annotation][out] */ 
            _Out_  GUID *pguidEventID);
        
        HRESULT ( STDMETHODCALLTYPE *CanContinue )( 
            __RPC__in ISyncMgrSyncCallback * This,
            /* [string][ref][in] */ __RPC__in_string LPCWSTR pszItemID);
        
        HRESULT ( STDMETHODCALLTYPE *QueryForAdditionalItems )( 
            __RPC__in ISyncMgrSyncCallback * This,
            /* [annotation][out] */ 
            _Out_  IEnumString **ppenumItemIDs,
            /* [annotation][out] */ 
            _Out_  IEnumUnknown **ppenumPunks);
        
        HRESULT ( STDMETHODCALLTYPE *AddItemToSession )( 
            __RPC__in ISyncMgrSyncCallback * This,
            /* [string][ref][in] */ __RPC__in_string LPCWSTR pszItemID);
        
        HRESULT ( STDMETHODCALLTYPE *AddIUnknownToSession )( 
            __RPC__in ISyncMgrSyncCallback * This,
            /* [annotation][in] */ 
            _In_  IUnknown *punk);
        
        HRESULT ( STDMETHODCALLTYPE *ProposeItem )( 
            __RPC__in ISyncMgrSyncCallback * This,
            /* [annotation][in] */ 
            _In_  ISyncMgrSyncItem *pNewItem);
        
        HRESULT ( STDMETHODCALLTYPE *CommitItem )( 
            __RPC__in ISyncMgrSyncCallback * This,
            /* [string][ref][in] */ __RPC__in_string LPCWSTR pszItemID);
        
        HRESULT ( STDMETHODCALLTYPE *ReportManualSync )( 
            __RPC__in ISyncMgrSyncCallback * This);
        
        END_INTERFACE
    } ISyncMgrSyncCallbackVtbl;

    interface ISyncMgrSyncCallback
    {
        CONST_VTBL struct ISyncMgrSyncCallbackVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISyncMgrSyncCallback_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISyncMgrSyncCallback_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISyncMgrSyncCallback_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISyncMgrSyncCallback_ReportProgress(This,pszItemID,pszProgressText,nStatus,uCurrentStep,uMaxStep,pnCancelRequest)	\
    ( (This)->lpVtbl -> ReportProgress(This,pszItemID,pszProgressText,nStatus,uCurrentStep,uMaxStep,pnCancelRequest) ) 

#define ISyncMgrSyncCallback_SetHandlerProgressText(This,pszProgressText,pnCancelRequest)	\
    ( (This)->lpVtbl -> SetHandlerProgressText(This,pszProgressText,pnCancelRequest) ) 

#define ISyncMgrSyncCallback_ReportEvent(This,pszItemID,nLevel,nFlags,pszName,pszDescription,pszLinkText,pszLinkReference,pszContext,pguidEventID)	\
    ( (This)->lpVtbl -> ReportEvent(This,pszItemID,nLevel,nFlags,pszName,pszDescription,pszLinkText,pszLinkReference,pszContext,pguidEventID) ) 

#define ISyncMgrSyncCallback_CanContinue(This,pszItemID)	\
    ( (This)->lpVtbl -> CanContinue(This,pszItemID) ) 

#define ISyncMgrSyncCallback_QueryForAdditionalItems(This,ppenumItemIDs,ppenumPunks)	\
    ( (This)->lpVtbl -> QueryForAdditionalItems(This,ppenumItemIDs,ppenumPunks) ) 

#define ISyncMgrSyncCallback_AddItemToSession(This,pszItemID)	\
    ( (This)->lpVtbl -> AddItemToSession(This,pszItemID) ) 

#define ISyncMgrSyncCallback_AddIUnknownToSession(This,punk)	\
    ( (This)->lpVtbl -> AddIUnknownToSession(This,punk) ) 

#define ISyncMgrSyncCallback_ProposeItem(This,pNewItem)	\
    ( (This)->lpVtbl -> ProposeItem(This,pNewItem) ) 

#define ISyncMgrSyncCallback_CommitItem(This,pszItemID)	\
    ( (This)->lpVtbl -> CommitItem(This,pszItemID) ) 

#define ISyncMgrSyncCallback_ReportManualSync(This)	\
    ( (This)->lpVtbl -> ReportManualSync(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISyncMgrSyncCallback_INTERFACE_DEFINED__ */


#ifndef __ISyncMgrUIOperation_INTERFACE_DEFINED__
#define __ISyncMgrUIOperation_INTERFACE_DEFINED__

/* interface ISyncMgrUIOperation */
/* [uuid][object] */ 


EXTERN_C const IID IID_ISyncMgrUIOperation;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("fc7cfa47-dfe1-45b5-a049-8cfd82bec271")
    ISyncMgrUIOperation : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Run( 
            /* [annotation][unique][in] */ 
            _In_  HWND hwndOwner) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISyncMgrUIOperationVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISyncMgrUIOperation * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISyncMgrUIOperation * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISyncMgrUIOperation * This);
        
        HRESULT ( STDMETHODCALLTYPE *Run )( 
            __RPC__in ISyncMgrUIOperation * This,
            /* [annotation][unique][in] */ 
            _In_  HWND hwndOwner);
        
        END_INTERFACE
    } ISyncMgrUIOperationVtbl;

    interface ISyncMgrUIOperation
    {
        CONST_VTBL struct ISyncMgrUIOperationVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISyncMgrUIOperation_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISyncMgrUIOperation_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISyncMgrUIOperation_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISyncMgrUIOperation_Run(This,hwndOwner)	\
    ( (This)->lpVtbl -> Run(This,hwndOwner) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISyncMgrUIOperation_INTERFACE_DEFINED__ */


#ifndef __ISyncMgrEventLinkUIOperation_INTERFACE_DEFINED__
#define __ISyncMgrEventLinkUIOperation_INTERFACE_DEFINED__

/* interface ISyncMgrEventLinkUIOperation */
/* [uuid][object] */ 


EXTERN_C const IID IID_ISyncMgrEventLinkUIOperation;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("64522e52-848b-4015-89ce-5a36f00b94ff")
    ISyncMgrEventLinkUIOperation : public ISyncMgrUIOperation
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Init( 
            /* [annotation][in] */ 
            _In_  REFGUID rguidEventID,
            /* [annotation][in] */ 
            _In_  ISyncMgrEvent *pEvent) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISyncMgrEventLinkUIOperationVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISyncMgrEventLinkUIOperation * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISyncMgrEventLinkUIOperation * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISyncMgrEventLinkUIOperation * This);
        
        HRESULT ( STDMETHODCALLTYPE *Run )( 
            __RPC__in ISyncMgrEventLinkUIOperation * This,
            /* [annotation][unique][in] */ 
            _In_  HWND hwndOwner);
        
        HRESULT ( STDMETHODCALLTYPE *Init )( 
            __RPC__in ISyncMgrEventLinkUIOperation * This,
            /* [annotation][in] */ 
            _In_  REFGUID rguidEventID,
            /* [annotation][in] */ 
            _In_  ISyncMgrEvent *pEvent);
        
        END_INTERFACE
    } ISyncMgrEventLinkUIOperationVtbl;

    interface ISyncMgrEventLinkUIOperation
    {
        CONST_VTBL struct ISyncMgrEventLinkUIOperationVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISyncMgrEventLinkUIOperation_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISyncMgrEventLinkUIOperation_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISyncMgrEventLinkUIOperation_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISyncMgrEventLinkUIOperation_Run(This,hwndOwner)	\
    ( (This)->lpVtbl -> Run(This,hwndOwner) ) 


#define ISyncMgrEventLinkUIOperation_Init(This,rguidEventID,pEvent)	\
    ( (This)->lpVtbl -> Init(This,rguidEventID,pEvent) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISyncMgrEventLinkUIOperation_INTERFACE_DEFINED__ */


#ifndef __ISyncMgrScheduleWizardUIOperation_INTERFACE_DEFINED__
#define __ISyncMgrScheduleWizardUIOperation_INTERFACE_DEFINED__

/* interface ISyncMgrScheduleWizardUIOperation */
/* [uuid][object] */ 


EXTERN_C const IID IID_ISyncMgrScheduleWizardUIOperation;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("459a6c84-21d2-4ddc-8a53-f023a46066f2")
    ISyncMgrScheduleWizardUIOperation : public ISyncMgrUIOperation
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE InitWizard( 
            /* [string][ref][in] */ __RPC__in_string LPCWSTR pszHandlerID) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISyncMgrScheduleWizardUIOperationVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISyncMgrScheduleWizardUIOperation * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISyncMgrScheduleWizardUIOperation * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISyncMgrScheduleWizardUIOperation * This);
        
        HRESULT ( STDMETHODCALLTYPE *Run )( 
            __RPC__in ISyncMgrScheduleWizardUIOperation * This,
            /* [annotation][unique][in] */ 
            _In_  HWND hwndOwner);
        
        HRESULT ( STDMETHODCALLTYPE *InitWizard )( 
            __RPC__in ISyncMgrScheduleWizardUIOperation * This,
            /* [string][ref][in] */ __RPC__in_string LPCWSTR pszHandlerID);
        
        END_INTERFACE
    } ISyncMgrScheduleWizardUIOperationVtbl;

    interface ISyncMgrScheduleWizardUIOperation
    {
        CONST_VTBL struct ISyncMgrScheduleWizardUIOperationVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISyncMgrScheduleWizardUIOperation_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISyncMgrScheduleWizardUIOperation_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISyncMgrScheduleWizardUIOperation_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISyncMgrScheduleWizardUIOperation_Run(This,hwndOwner)	\
    ( (This)->lpVtbl -> Run(This,hwndOwner) ) 


#define ISyncMgrScheduleWizardUIOperation_InitWizard(This,pszHandlerID)	\
    ( (This)->lpVtbl -> InitWizard(This,pszHandlerID) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISyncMgrScheduleWizardUIOperation_INTERFACE_DEFINED__ */


#ifndef __ISyncMgrSyncResult_INTERFACE_DEFINED__
#define __ISyncMgrSyncResult_INTERFACE_DEFINED__

/* interface ISyncMgrSyncResult */
/* [uuid][object] */ 


EXTERN_C const IID IID_ISyncMgrSyncResult;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2b90f17e-5a3e-4b33-bb7f-1bc48056b94d")
    ISyncMgrSyncResult : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Result( 
            /* [annotation][in] */ 
            _In_  SYNCMGR_PROGRESS_STATUS nStatus,
            /* [annotation][in] */ 
            _In_  UINT cError,
            /* [annotation][in] */ 
            _In_  UINT cConflicts) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISyncMgrSyncResultVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISyncMgrSyncResult * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISyncMgrSyncResult * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISyncMgrSyncResult * This);
        
        HRESULT ( STDMETHODCALLTYPE *Result )( 
            __RPC__in ISyncMgrSyncResult * This,
            /* [annotation][in] */ 
            _In_  SYNCMGR_PROGRESS_STATUS nStatus,
            /* [annotation][in] */ 
            _In_  UINT cError,
            /* [annotation][in] */ 
            _In_  UINT cConflicts);
        
        END_INTERFACE
    } ISyncMgrSyncResultVtbl;

    interface ISyncMgrSyncResult
    {
        CONST_VTBL struct ISyncMgrSyncResultVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISyncMgrSyncResult_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISyncMgrSyncResult_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISyncMgrSyncResult_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISyncMgrSyncResult_Result(This,nStatus,cError,cConflicts)	\
    ( (This)->lpVtbl -> Result(This,nStatus,cError,cConflicts) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISyncMgrSyncResult_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_syncmgr_0000_0013 */
/* [local] */ 

typedef /* [v1_enum] */ 
enum SYNCMGR_CONTROL_FLAGS
    {
        SYNCMGR_CF_NONE	= 0,
        SYNCMGR_CF_NOWAIT	= 0,
        SYNCMGR_CF_WAIT	= 0x1,
        SYNCMGR_CF_NOUI	= 0x2,
        SYNCMGR_CF_VALID	= 0x3
    } 	SYNCMGR_CONTROL_FLAGS;

typedef /* [v1_enum] */ 
enum SYNCMGR_SYNC_CONTROL_FLAGS
    {
        SYNCMGR_SCF_NONE	= 0,
        SYNCMGR_SCF_IGNORE_IF_ALREADY_SYNCING	= 0x1,
        SYNCMGR_SCF_VALID	= 0x1
    } 	SYNCMGR_SYNC_CONTROL_FLAGS;

typedef /* [v1_enum] */ 
enum SYNCMGR_UPDATE_REASON
    {
        SYNCMGR_UR_ADDED	= 0,
        SYNCMGR_UR_CHANGED	= 1,
        SYNCMGR_UR_REMOVED	= 2,
        SYNCMGR_UR_MAX	= SYNCMGR_UR_REMOVED
    } 	SYNCMGR_UPDATE_REASON;



extern RPC_IF_HANDLE __MIDL_itf_syncmgr_0000_0013_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_syncmgr_0000_0013_v0_0_s_ifspec;

#ifndef __ISyncMgrControl_INTERFACE_DEFINED__
#define __ISyncMgrControl_INTERFACE_DEFINED__

/* interface ISyncMgrControl */
/* [uuid][object] */ 


EXTERN_C const IID IID_ISyncMgrControl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9B63616C-36B2-46BC-959F-C1593952D19B")
    ISyncMgrControl : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE StartHandlerSync( 
            /* [string][ref][in] */ __RPC__in_string LPCWSTR pszHandlerID,
            /* [annotation][unique][in] */ 
            _In_  HWND hwndOwner,
            /* [annotation][unique][in] */ 
            _In_  IUnknown *punk,
            /* [annotation][in] */ 
            _In_  SYNCMGR_SYNC_CONTROL_FLAGS nSyncControlFlags,
            /* [annotation][unique][in] */ 
            _In_  ISyncMgrSyncResult *pResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StartItemSync( 
            /* [string][ref][in] */ __RPC__in_string LPCWSTR pszHandlerID,
            /* [size_is][string][ref][in] */ __RPC__in_ecount_full(cItems) LPCWSTR *ppszItemIDs,
            /* [annotation][in] */ 
            _In_  ULONG cItems,
            /* [annotation][unique][in] */ 
            _In_  HWND hwndOwner,
            /* [annotation][unique][in] */ 
            _In_  IUnknown *punk,
            /* [annotation][in] */ 
            _In_  SYNCMGR_SYNC_CONTROL_FLAGS nSyncControlFlags,
            /* [annotation][unique][in] */ 
            _In_  ISyncMgrSyncResult *pResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StartSyncAll( 
            /* [annotation][unique][in] */ 
            _In_  HWND hwndOwner) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StopHandlerSync( 
            /* [string][ref][in] */ __RPC__in_string LPCWSTR pszHandlerID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StopItemSync( 
            /* [string][ref][in] */ __RPC__in_string LPCWSTR pszHandlerID,
            /* [size_is][string][ref][in] */ __RPC__in_ecount_full(cItems) LPCWSTR *ppszItemIDs,
            /* [annotation][in] */ 
            _In_  ULONG cItems) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StopSyncAll( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UpdateHandlerCollection( 
            /* [annotation][in] */ 
            _In_  REFCLSID rclsidCollectionID,
            /* [annotation][in] */ 
            _In_  SYNCMGR_CONTROL_FLAGS nControlFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UpdateHandler( 
            /* [string][ref][in] */ __RPC__in_string LPCWSTR pszHandlerID,
            /* [annotation][in] */ 
            _In_  SYNCMGR_CONTROL_FLAGS nControlFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UpdateItem( 
            /* [string][ref][in] */ __RPC__in_string LPCWSTR pszHandlerID,
            /* [string][ref][in] */ __RPC__in_string LPCWSTR pszItemID,
            /* [annotation][in] */ 
            _In_  SYNCMGR_CONTROL_FLAGS nControlFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UpdateEvents( 
            /* [string][ref][in] */ __RPC__in_string LPCWSTR pszHandlerID,
            /* [annotation][string][unique][in] */ 
            _In_  LPCWSTR pszItemID,
            /* [annotation][in] */ 
            _In_  SYNCMGR_CONTROL_FLAGS nControlFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UpdateConflict( 
            /* [string][ref][in] */ __RPC__in_string LPCWSTR pszHandlerID,
            /* [annotation][string][unique][in] */ 
            _In_  LPCWSTR pszItemID,
            /* [annotation][in] */ 
            _In_  ISyncMgrConflict *pConflict,
            /* [annotation][in] */ 
            _In_  SYNCMGR_UPDATE_REASON nReason) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UpdateConflicts( 
            /* [string][ref][in] */ __RPC__in_string LPCWSTR pszHandlerID,
            /* [annotation][string][unique][in] */ 
            _In_  LPCWSTR pszItemID,
            /* [annotation][in] */ 
            _In_  SYNCMGR_CONTROL_FLAGS nControlFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ActivateHandler( 
            /* [annotation][in] */ 
            _In_  BOOL fActivate,
            /* [string][ref][in] */ __RPC__in_string LPCWSTR pszHandlerID,
            /* [annotation][unique][in] */ 
            _In_  HWND hwndOwner,
            /* [annotation][in] */ 
            _In_  SYNCMGR_CONTROL_FLAGS nControlFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnableHandler( 
            /* [annotation][in] */ 
            _In_  BOOL fEnable,
            /* [string][ref][in] */ __RPC__in_string LPCWSTR pszHandlerID,
            /* [annotation][unique][in] */ 
            _In_  HWND hwndOwner,
            /* [annotation][in] */ 
            _In_  SYNCMGR_CONTROL_FLAGS nControlFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnableItem( 
            /* [annotation][in] */ 
            _In_  BOOL fEnable,
            /* [string][ref][in] */ __RPC__in_string LPCWSTR pszHandlerID,
            /* [string][ref][in] */ __RPC__in_string LPCWSTR pszItemID,
            /* [annotation][unique][in] */ 
            _In_  HWND hwndOwner,
            /* [annotation][in] */ 
            _In_  SYNCMGR_CONTROL_FLAGS nControlFlags) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISyncMgrControlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISyncMgrControl * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISyncMgrControl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISyncMgrControl * This);
        
        HRESULT ( STDMETHODCALLTYPE *StartHandlerSync )( 
            __RPC__in ISyncMgrControl * This,
            /* [string][ref][in] */ __RPC__in_string LPCWSTR pszHandlerID,
            /* [annotation][unique][in] */ 
            _In_  HWND hwndOwner,
            /* [annotation][unique][in] */ 
            _In_  IUnknown *punk,
            /* [annotation][in] */ 
            _In_  SYNCMGR_SYNC_CONTROL_FLAGS nSyncControlFlags,
            /* [annotation][unique][in] */ 
            _In_  ISyncMgrSyncResult *pResult);
        
        HRESULT ( STDMETHODCALLTYPE *StartItemSync )( 
            __RPC__in ISyncMgrControl * This,
            /* [string][ref][in] */ __RPC__in_string LPCWSTR pszHandlerID,
            /* [size_is][string][ref][in] */ __RPC__in_ecount_full(cItems) LPCWSTR *ppszItemIDs,
            /* [annotation][in] */ 
            _In_  ULONG cItems,
            /* [annotation][unique][in] */ 
            _In_  HWND hwndOwner,
            /* [annotation][unique][in] */ 
            _In_  IUnknown *punk,
            /* [annotation][in] */ 
            _In_  SYNCMGR_SYNC_CONTROL_FLAGS nSyncControlFlags,
            /* [annotation][unique][in] */ 
            _In_  ISyncMgrSyncResult *pResult);
        
        HRESULT ( STDMETHODCALLTYPE *StartSyncAll )( 
            __RPC__in ISyncMgrControl * This,
            /* [annotation][unique][in] */ 
            _In_  HWND hwndOwner);
        
        HRESULT ( STDMETHODCALLTYPE *StopHandlerSync )( 
            __RPC__in ISyncMgrControl * This,
            /* [string][ref][in] */ __RPC__in_string LPCWSTR pszHandlerID);
        
        HRESULT ( STDMETHODCALLTYPE *StopItemSync )( 
            __RPC__in ISyncMgrControl * This,
            /* [string][ref][in] */ __RPC__in_string LPCWSTR pszHandlerID,
            /* [size_is][string][ref][in] */ __RPC__in_ecount_full(cItems) LPCWSTR *ppszItemIDs,
            /* [annotation][in] */ 
            _In_  ULONG cItems);
        
        HRESULT ( STDMETHODCALLTYPE *StopSyncAll )( 
            __RPC__in ISyncMgrControl * This);
        
        HRESULT ( STDMETHODCALLTYPE *UpdateHandlerCollection )( 
            __RPC__in ISyncMgrControl * This,
            /* [annotation][in] */ 
            _In_  REFCLSID rclsidCollectionID,
            /* [annotation][in] */ 
            _In_  SYNCMGR_CONTROL_FLAGS nControlFlags);
        
        HRESULT ( STDMETHODCALLTYPE *UpdateHandler )( 
            __RPC__in ISyncMgrControl * This,
            /* [string][ref][in] */ __RPC__in_string LPCWSTR pszHandlerID,
            /* [annotation][in] */ 
            _In_  SYNCMGR_CONTROL_FLAGS nControlFlags);
        
        HRESULT ( STDMETHODCALLTYPE *UpdateItem )( 
            __RPC__in ISyncMgrControl * This,
            /* [string][ref][in] */ __RPC__in_string LPCWSTR pszHandlerID,
            /* [string][ref][in] */ __RPC__in_string LPCWSTR pszItemID,
            /* [annotation][in] */ 
            _In_  SYNCMGR_CONTROL_FLAGS nControlFlags);
        
        HRESULT ( STDMETHODCALLTYPE *UpdateEvents )( 
            __RPC__in ISyncMgrControl * This,
            /* [string][ref][in] */ __RPC__in_string LPCWSTR pszHandlerID,
            /* [annotation][string][unique][in] */ 
            _In_  LPCWSTR pszItemID,
            /* [annotation][in] */ 
            _In_  SYNCMGR_CONTROL_FLAGS nControlFlags);
        
        HRESULT ( STDMETHODCALLTYPE *UpdateConflict )( 
            __RPC__in ISyncMgrControl * This,
            /* [string][ref][in] */ __RPC__in_string LPCWSTR pszHandlerID,
            /* [annotation][string][unique][in] */ 
            _In_  LPCWSTR pszItemID,
            /* [annotation][in] */ 
            _In_  ISyncMgrConflict *pConflict,
            /* [annotation][in] */ 
            _In_  SYNCMGR_UPDATE_REASON nReason);
        
        HRESULT ( STDMETHODCALLTYPE *UpdateConflicts )( 
            __RPC__in ISyncMgrControl * This,
            /* [string][ref][in] */ __RPC__in_string LPCWSTR pszHandlerID,
            /* [annotation][string][unique][in] */ 
            _In_  LPCWSTR pszItemID,
            /* [annotation][in] */ 
            _In_  SYNCMGR_CONTROL_FLAGS nControlFlags);
        
        HRESULT ( STDMETHODCALLTYPE *ActivateHandler )( 
            __RPC__in ISyncMgrControl * This,
            /* [annotation][in] */ 
            _In_  BOOL fActivate,
            /* [string][ref][in] */ __RPC__in_string LPCWSTR pszHandlerID,
            /* [annotation][unique][in] */ 
            _In_  HWND hwndOwner,
            /* [annotation][in] */ 
            _In_  SYNCMGR_CONTROL_FLAGS nControlFlags);
        
        HRESULT ( STDMETHODCALLTYPE *EnableHandler )( 
            __RPC__in ISyncMgrControl * This,
            /* [annotation][in] */ 
            _In_  BOOL fEnable,
            /* [string][ref][in] */ __RPC__in_string LPCWSTR pszHandlerID,
            /* [annotation][unique][in] */ 
            _In_  HWND hwndOwner,
            /* [annotation][in] */ 
            _In_  SYNCMGR_CONTROL_FLAGS nControlFlags);
        
        HRESULT ( STDMETHODCALLTYPE *EnableItem )( 
            __RPC__in ISyncMgrControl * This,
            /* [annotation][in] */ 
            _In_  BOOL fEnable,
            /* [string][ref][in] */ __RPC__in_string LPCWSTR pszHandlerID,
            /* [string][ref][in] */ __RPC__in_string LPCWSTR pszItemID,
            /* [annotation][unique][in] */ 
            _In_  HWND hwndOwner,
            /* [annotation][in] */ 
            _In_  SYNCMGR_CONTROL_FLAGS nControlFlags);
        
        END_INTERFACE
    } ISyncMgrControlVtbl;

    interface ISyncMgrControl
    {
        CONST_VTBL struct ISyncMgrControlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISyncMgrControl_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISyncMgrControl_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISyncMgrControl_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISyncMgrControl_StartHandlerSync(This,pszHandlerID,hwndOwner,punk,nSyncControlFlags,pResult)	\
    ( (This)->lpVtbl -> StartHandlerSync(This,pszHandlerID,hwndOwner,punk,nSyncControlFlags,pResult) ) 

#define ISyncMgrControl_StartItemSync(This,pszHandlerID,ppszItemIDs,cItems,hwndOwner,punk,nSyncControlFlags,pResult)	\
    ( (This)->lpVtbl -> StartItemSync(This,pszHandlerID,ppszItemIDs,cItems,hwndOwner,punk,nSyncControlFlags,pResult) ) 

#define ISyncMgrControl_StartSyncAll(This,hwndOwner)	\
    ( (This)->lpVtbl -> StartSyncAll(This,hwndOwner) ) 

#define ISyncMgrControl_StopHandlerSync(This,pszHandlerID)	\
    ( (This)->lpVtbl -> StopHandlerSync(This,pszHandlerID) ) 

#define ISyncMgrControl_StopItemSync(This,pszHandlerID,ppszItemIDs,cItems)	\
    ( (This)->lpVtbl -> StopItemSync(This,pszHandlerID,ppszItemIDs,cItems) ) 

#define ISyncMgrControl_StopSyncAll(This)	\
    ( (This)->lpVtbl -> StopSyncAll(This) ) 

#define ISyncMgrControl_UpdateHandlerCollection(This,rclsidCollectionID,nControlFlags)	\
    ( (This)->lpVtbl -> UpdateHandlerCollection(This,rclsidCollectionID,nControlFlags) ) 

#define ISyncMgrControl_UpdateHandler(This,pszHandlerID,nControlFlags)	\
    ( (This)->lpVtbl -> UpdateHandler(This,pszHandlerID,nControlFlags) ) 

#define ISyncMgrControl_UpdateItem(This,pszHandlerID,pszItemID,nControlFlags)	\
    ( (This)->lpVtbl -> UpdateItem(This,pszHandlerID,pszItemID,nControlFlags) ) 

#define ISyncMgrControl_UpdateEvents(This,pszHandlerID,pszItemID,nControlFlags)	\
    ( (This)->lpVtbl -> UpdateEvents(This,pszHandlerID,pszItemID,nControlFlags) ) 

#define ISyncMgrControl_UpdateConflict(This,pszHandlerID,pszItemID,pConflict,nReason)	\
    ( (This)->lpVtbl -> UpdateConflict(This,pszHandlerID,pszItemID,pConflict,nReason) ) 

#define ISyncMgrControl_UpdateConflicts(This,pszHandlerID,pszItemID,nControlFlags)	\
    ( (This)->lpVtbl -> UpdateConflicts(This,pszHandlerID,pszItemID,nControlFlags) ) 

#define ISyncMgrControl_ActivateHandler(This,fActivate,pszHandlerID,hwndOwner,nControlFlags)	\
    ( (This)->lpVtbl -> ActivateHandler(This,fActivate,pszHandlerID,hwndOwner,nControlFlags) ) 

#define ISyncMgrControl_EnableHandler(This,fEnable,pszHandlerID,hwndOwner,nControlFlags)	\
    ( (This)->lpVtbl -> EnableHandler(This,fEnable,pszHandlerID,hwndOwner,nControlFlags) ) 

#define ISyncMgrControl_EnableItem(This,fEnable,pszHandlerID,pszItemID,hwndOwner,nControlFlags)	\
    ( (This)->lpVtbl -> EnableItem(This,fEnable,pszHandlerID,pszItemID,hwndOwner,nControlFlags) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISyncMgrControl_INTERFACE_DEFINED__ */


#ifndef __ISyncMgrEventStore_INTERFACE_DEFINED__
#define __ISyncMgrEventStore_INTERFACE_DEFINED__

/* interface ISyncMgrEventStore */
/* [uuid][object] */ 


EXTERN_C const IID IID_ISyncMgrEventStore;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("37e412f9-016e-44c2-81ff-db3add774266")
    ISyncMgrEventStore : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetEventEnumerator( 
            /* [annotation][out] */ 
            _Out_  IEnumSyncMgrEvents **ppenum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEventCount( 
            /* [annotation][out] */ 
            _Out_  ULONG *pcEvents) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEvent( 
            /* [annotation][in] */ 
            _In_  REFGUID rguidEventID,
            /* [annotation][out] */ 
            _Out_  ISyncMgrEvent **ppEvent) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveEvent( 
            /* [size_is][ref][in] */ __RPC__in_ecount_full(cEvents) GUID *pguidEventIDs,
            /* [annotation][in] */ 
            _In_  ULONG cEvents) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISyncMgrEventStoreVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISyncMgrEventStore * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISyncMgrEventStore * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISyncMgrEventStore * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetEventEnumerator )( 
            __RPC__in ISyncMgrEventStore * This,
            /* [annotation][out] */ 
            _Out_  IEnumSyncMgrEvents **ppenum);
        
        HRESULT ( STDMETHODCALLTYPE *GetEventCount )( 
            __RPC__in ISyncMgrEventStore * This,
            /* [annotation][out] */ 
            _Out_  ULONG *pcEvents);
        
        HRESULT ( STDMETHODCALLTYPE *GetEvent )( 
            __RPC__in ISyncMgrEventStore * This,
            /* [annotation][in] */ 
            _In_  REFGUID rguidEventID,
            /* [annotation][out] */ 
            _Out_  ISyncMgrEvent **ppEvent);
        
        HRESULT ( STDMETHODCALLTYPE *RemoveEvent )( 
            __RPC__in ISyncMgrEventStore * This,
            /* [size_is][ref][in] */ __RPC__in_ecount_full(cEvents) GUID *pguidEventIDs,
            /* [annotation][in] */ 
            _In_  ULONG cEvents);
        
        END_INTERFACE
    } ISyncMgrEventStoreVtbl;

    interface ISyncMgrEventStore
    {
        CONST_VTBL struct ISyncMgrEventStoreVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISyncMgrEventStore_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISyncMgrEventStore_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISyncMgrEventStore_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISyncMgrEventStore_GetEventEnumerator(This,ppenum)	\
    ( (This)->lpVtbl -> GetEventEnumerator(This,ppenum) ) 

#define ISyncMgrEventStore_GetEventCount(This,pcEvents)	\
    ( (This)->lpVtbl -> GetEventCount(This,pcEvents) ) 

#define ISyncMgrEventStore_GetEvent(This,rguidEventID,ppEvent)	\
    ( (This)->lpVtbl -> GetEvent(This,rguidEventID,ppEvent) ) 

#define ISyncMgrEventStore_RemoveEvent(This,pguidEventIDs,cEvents)	\
    ( (This)->lpVtbl -> RemoveEvent(This,pguidEventIDs,cEvents) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISyncMgrEventStore_INTERFACE_DEFINED__ */


#ifndef __ISyncMgrEvent_INTERFACE_DEFINED__
#define __ISyncMgrEvent_INTERFACE_DEFINED__

/* interface ISyncMgrEvent */
/* [uuid][object] */ 


EXTERN_C const IID IID_ISyncMgrEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("fee0ef8b-46bd-4db4-b7e6-ff2c687313bc")
    ISyncMgrEvent : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetEventID( 
            /* [ref][out] */ __RPC__out GUID *pguidEventID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetHandlerID( 
            /* [string][ref][out] */ __RPC__deref_out_opt_string LPWSTR *ppszHandlerID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetItemID( 
            /* [string][ref][out] */ __RPC__deref_out_opt_string LPWSTR *ppszItemID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLevel( 
            /* [ref][out] */ __RPC__out SYNCMGR_EVENT_LEVEL *pnLevel) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFlags( 
            /* [ref][out] */ __RPC__out SYNCMGR_EVENT_FLAGS *pnFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTime( 
            /* [ref][out] */ __RPC__out FILETIME *pfCreationTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetName( 
            /* [string][ref][out] */ __RPC__deref_out_opt_string LPWSTR *ppszName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDescription( 
            /* [string][ref][out] */ __RPC__deref_out_opt_string LPWSTR *ppszDescription) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLinkText( 
            /* [string][ref][out] */ __RPC__deref_out_opt_string LPWSTR *ppszLinkText) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLinkReference( 
            /* [string][ref][out] */ __RPC__deref_out_opt_string LPWSTR *ppszLinkReference) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetContext( 
            /* [string][ref][out] */ __RPC__deref_out_opt_string LPWSTR *ppszContext) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISyncMgrEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISyncMgrEvent * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISyncMgrEvent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISyncMgrEvent * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetEventID )( 
            __RPC__in ISyncMgrEvent * This,
            /* [ref][out] */ __RPC__out GUID *pguidEventID);
        
        HRESULT ( STDMETHODCALLTYPE *GetHandlerID )( 
            __RPC__in ISyncMgrEvent * This,
            /* [string][ref][out] */ __RPC__deref_out_opt_string LPWSTR *ppszHandlerID);
        
        HRESULT ( STDMETHODCALLTYPE *GetItemID )( 
            __RPC__in ISyncMgrEvent * This,
            /* [string][ref][out] */ __RPC__deref_out_opt_string LPWSTR *ppszItemID);
        
        HRESULT ( STDMETHODCALLTYPE *GetLevel )( 
            __RPC__in ISyncMgrEvent * This,
            /* [ref][out] */ __RPC__out SYNCMGR_EVENT_LEVEL *pnLevel);
        
        HRESULT ( STDMETHODCALLTYPE *GetFlags )( 
            __RPC__in ISyncMgrEvent * This,
            /* [ref][out] */ __RPC__out SYNCMGR_EVENT_FLAGS *pnFlags);
        
        HRESULT ( STDMETHODCALLTYPE *GetTime )( 
            __RPC__in ISyncMgrEvent * This,
            /* [ref][out] */ __RPC__out FILETIME *pfCreationTime);
        
        HRESULT ( STDMETHODCALLTYPE *GetName )( 
            __RPC__in ISyncMgrEvent * This,
            /* [string][ref][out] */ __RPC__deref_out_opt_string LPWSTR *ppszName);
        
        HRESULT ( STDMETHODCALLTYPE *GetDescription )( 
            __RPC__in ISyncMgrEvent * This,
            /* [string][ref][out] */ __RPC__deref_out_opt_string LPWSTR *ppszDescription);
        
        HRESULT ( STDMETHODCALLTYPE *GetLinkText )( 
            __RPC__in ISyncMgrEvent * This,
            /* [string][ref][out] */ __RPC__deref_out_opt_string LPWSTR *ppszLinkText);
        
        HRESULT ( STDMETHODCALLTYPE *GetLinkReference )( 
            __RPC__in ISyncMgrEvent * This,
            /* [string][ref][out] */ __RPC__deref_out_opt_string LPWSTR *ppszLinkReference);
        
        HRESULT ( STDMETHODCALLTYPE *GetContext )( 
            __RPC__in ISyncMgrEvent * This,
            /* [string][ref][out] */ __RPC__deref_out_opt_string LPWSTR *ppszContext);
        
        END_INTERFACE
    } ISyncMgrEventVtbl;

    interface ISyncMgrEvent
    {
        CONST_VTBL struct ISyncMgrEventVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISyncMgrEvent_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISyncMgrEvent_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISyncMgrEvent_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISyncMgrEvent_GetEventID(This,pguidEventID)	\
    ( (This)->lpVtbl -> GetEventID(This,pguidEventID) ) 

#define ISyncMgrEvent_GetHandlerID(This,ppszHandlerID)	\
    ( (This)->lpVtbl -> GetHandlerID(This,ppszHandlerID) ) 

#define ISyncMgrEvent_GetItemID(This,ppszItemID)	\
    ( (This)->lpVtbl -> GetItemID(This,ppszItemID) ) 

#define ISyncMgrEvent_GetLevel(This,pnLevel)	\
    ( (This)->lpVtbl -> GetLevel(This,pnLevel) ) 

#define ISyncMgrEvent_GetFlags(This,pnFlags)	\
    ( (This)->lpVtbl -> GetFlags(This,pnFlags) ) 

#define ISyncMgrEvent_GetTime(This,pfCreationTime)	\
    ( (This)->lpVtbl -> GetTime(This,pfCreationTime) ) 

#define ISyncMgrEvent_GetName(This,ppszName)	\
    ( (This)->lpVtbl -> GetName(This,ppszName) ) 

#define ISyncMgrEvent_GetDescription(This,ppszDescription)	\
    ( (This)->lpVtbl -> GetDescription(This,ppszDescription) ) 

#define ISyncMgrEvent_GetLinkText(This,ppszLinkText)	\
    ( (This)->lpVtbl -> GetLinkText(This,ppszLinkText) ) 

#define ISyncMgrEvent_GetLinkReference(This,ppszLinkReference)	\
    ( (This)->lpVtbl -> GetLinkReference(This,ppszLinkReference) ) 

#define ISyncMgrEvent_GetContext(This,ppszContext)	\
    ( (This)->lpVtbl -> GetContext(This,ppszContext) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISyncMgrEvent_INTERFACE_DEFINED__ */


#ifndef __IEnumSyncMgrEvents_INTERFACE_DEFINED__
#define __IEnumSyncMgrEvents_INTERFACE_DEFINED__

/* interface IEnumSyncMgrEvents */
/* [uuid][object] */ 


EXTERN_C const IID IID_IEnumSyncMgrEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("c81a1d4e-8cf7-4683-80e0-bcae88d677b6")
    IEnumSyncMgrEvents : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [annotation][in] */ 
            _In_  ULONG celt,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(celt,*pceltFetched)  ISyncMgrEvent **rgelt,
            /* [annotation][out] */ 
            _Out_  ULONG *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [annotation][in] */ 
            _In_  ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [annotation][out] */ 
            _Out_  IEnumSyncMgrEvents **ppenum) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IEnumSyncMgrEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IEnumSyncMgrEvents * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IEnumSyncMgrEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IEnumSyncMgrEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            __RPC__in IEnumSyncMgrEvents * This,
            /* [annotation][in] */ 
            _In_  ULONG celt,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(celt,*pceltFetched)  ISyncMgrEvent **rgelt,
            /* [annotation][out] */ 
            _Out_  ULONG *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            __RPC__in IEnumSyncMgrEvents * This,
            /* [annotation][in] */ 
            _In_  ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            __RPC__in IEnumSyncMgrEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            __RPC__in IEnumSyncMgrEvents * This,
            /* [annotation][out] */ 
            _Out_  IEnumSyncMgrEvents **ppenum);
        
        END_INTERFACE
    } IEnumSyncMgrEventsVtbl;

    interface IEnumSyncMgrEvents
    {
        CONST_VTBL struct IEnumSyncMgrEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumSyncMgrEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEnumSyncMgrEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEnumSyncMgrEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IEnumSyncMgrEvents_Next(This,celt,rgelt,pceltFetched)	\
    ( (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched) ) 

#define IEnumSyncMgrEvents_Skip(This,celt)	\
    ( (This)->lpVtbl -> Skip(This,celt) ) 

#define IEnumSyncMgrEvents_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define IEnumSyncMgrEvents_Clone(This,ppenum)	\
    ( (This)->lpVtbl -> Clone(This,ppenum) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IEnumSyncMgrEvents_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_syncmgr_0000_0017 */
/* [local] */ 

typedef struct SYNCMGR_CONFLICT_ID_INFO
    {
    /* [unique] */ BYTE_BLOB *pblobID;
    /* [unique] */ BYTE_BLOB *pblobExtra;
    } 	SYNCMGR_CONFLICT_ID_INFO;

typedef struct SYNCMGR_CONFLICT_ID_INFO *PSYNCMGR_CONFLICT_ID_INFO;



extern RPC_IF_HANDLE __MIDL_itf_syncmgr_0000_0017_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_syncmgr_0000_0017_v0_0_s_ifspec;

#ifndef __ISyncMgrConflictStore_INTERFACE_DEFINED__
#define __ISyncMgrConflictStore_INTERFACE_DEFINED__

/* interface ISyncMgrConflictStore */
/* [object][unique][uuid] */ 


EXTERN_C const IID IID_ISyncMgrConflictStore;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("cf8fc579-c396-4774-85f1-d908a831156e")
    ISyncMgrConflictStore : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE EnumConflicts( 
            /* [string][ref][in] */ __RPC__in_string LPCWSTR pszHandlerID,
            /* [annotation][string][unique][in] */ 
            _In_  LPCWSTR pszItemID,
            /* [annotation][out] */ 
            _Out_  IEnumSyncMgrConflict **ppEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE BindToConflict( 
            /* [annotation][in] */ 
            _In_  const SYNCMGR_CONFLICT_ID_INFO *pConflictIdInfo,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppv) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveConflicts( 
            /* [annotation][size_is][in] */ 
            _In_reads_(cConflicts)  const SYNCMGR_CONFLICT_ID_INFO *rgConflictIdInfo,
            /* [annotation][in] */ 
            _In_  DWORD cConflicts) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCount( 
            /* [string][ref][in] */ __RPC__in_string LPCWSTR pszHandlerID,
            /* [annotation][string][unique][in] */ 
            _In_  LPCWSTR pszItemID,
            /* [annotation][out] */ 
            _Out_  DWORD *pnConflicts) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISyncMgrConflictStoreVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISyncMgrConflictStore * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISyncMgrConflictStore * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISyncMgrConflictStore * This);
        
        HRESULT ( STDMETHODCALLTYPE *EnumConflicts )( 
            __RPC__in ISyncMgrConflictStore * This,
            /* [string][ref][in] */ __RPC__in_string LPCWSTR pszHandlerID,
            /* [annotation][string][unique][in] */ 
            _In_  LPCWSTR pszItemID,
            /* [annotation][out] */ 
            _Out_  IEnumSyncMgrConflict **ppEnum);
        
        HRESULT ( STDMETHODCALLTYPE *BindToConflict )( 
            __RPC__in ISyncMgrConflictStore * This,
            /* [annotation][in] */ 
            _In_  const SYNCMGR_CONFLICT_ID_INFO *pConflictIdInfo,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppv);
        
        HRESULT ( STDMETHODCALLTYPE *RemoveConflicts )( 
            __RPC__in ISyncMgrConflictStore * This,
            /* [annotation][size_is][in] */ 
            _In_reads_(cConflicts)  const SYNCMGR_CONFLICT_ID_INFO *rgConflictIdInfo,
            /* [annotation][in] */ 
            _In_  DWORD cConflicts);
        
        HRESULT ( STDMETHODCALLTYPE *GetCount )( 
            __RPC__in ISyncMgrConflictStore * This,
            /* [string][ref][in] */ __RPC__in_string LPCWSTR pszHandlerID,
            /* [annotation][string][unique][in] */ 
            _In_  LPCWSTR pszItemID,
            /* [annotation][out] */ 
            _Out_  DWORD *pnConflicts);
        
        END_INTERFACE
    } ISyncMgrConflictStoreVtbl;

    interface ISyncMgrConflictStore
    {
        CONST_VTBL struct ISyncMgrConflictStoreVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISyncMgrConflictStore_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISyncMgrConflictStore_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISyncMgrConflictStore_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISyncMgrConflictStore_EnumConflicts(This,pszHandlerID,pszItemID,ppEnum)	\
    ( (This)->lpVtbl -> EnumConflicts(This,pszHandlerID,pszItemID,ppEnum) ) 

#define ISyncMgrConflictStore_BindToConflict(This,pConflictIdInfo,riid,ppv)	\
    ( (This)->lpVtbl -> BindToConflict(This,pConflictIdInfo,riid,ppv) ) 

#define ISyncMgrConflictStore_RemoveConflicts(This,rgConflictIdInfo,cConflicts)	\
    ( (This)->lpVtbl -> RemoveConflicts(This,rgConflictIdInfo,cConflicts) ) 

#define ISyncMgrConflictStore_GetCount(This,pszHandlerID,pszItemID,pnConflicts)	\
    ( (This)->lpVtbl -> GetCount(This,pszHandlerID,pszItemID,pnConflicts) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISyncMgrConflictStore_INTERFACE_DEFINED__ */


#ifndef __IEnumSyncMgrConflict_INTERFACE_DEFINED__
#define __IEnumSyncMgrConflict_INTERFACE_DEFINED__

/* interface IEnumSyncMgrConflict */
/* [object][unique][uuid] */ 


EXTERN_C const IID IID_IEnumSyncMgrConflict;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("82705914-dda3-4893-ba99-49de6c8c8036")
    IEnumSyncMgrConflict : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [annotation][in] */ 
            _In_  ULONG celt,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(celt,*pceltFetched)  ISyncMgrConflict **rgelt,
            /* [annotation][out] */ 
            _Out_  ULONG *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [annotation][in] */ 
            _In_  ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [annotation][out] */ 
            _Out_  IEnumSyncMgrConflict **ppenum) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IEnumSyncMgrConflictVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IEnumSyncMgrConflict * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IEnumSyncMgrConflict * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IEnumSyncMgrConflict * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            __RPC__in IEnumSyncMgrConflict * This,
            /* [annotation][in] */ 
            _In_  ULONG celt,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(celt,*pceltFetched)  ISyncMgrConflict **rgelt,
            /* [annotation][out] */ 
            _Out_  ULONG *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            __RPC__in IEnumSyncMgrConflict * This,
            /* [annotation][in] */ 
            _In_  ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            __RPC__in IEnumSyncMgrConflict * This);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            __RPC__in IEnumSyncMgrConflict * This,
            /* [annotation][out] */ 
            _Out_  IEnumSyncMgrConflict **ppenum);
        
        END_INTERFACE
    } IEnumSyncMgrConflictVtbl;

    interface IEnumSyncMgrConflict
    {
        CONST_VTBL struct IEnumSyncMgrConflictVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumSyncMgrConflict_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEnumSyncMgrConflict_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEnumSyncMgrConflict_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IEnumSyncMgrConflict_Next(This,celt,rgelt,pceltFetched)	\
    ( (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched) ) 

#define IEnumSyncMgrConflict_Skip(This,celt)	\
    ( (This)->lpVtbl -> Skip(This,celt) ) 

#define IEnumSyncMgrConflict_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define IEnumSyncMgrConflict_Clone(This,ppenum)	\
    ( (This)->lpVtbl -> Clone(This,ppenum) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IEnumSyncMgrConflict_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_syncmgr_0000_0019 */
/* [local] */ 

typedef /* [v1_enum] */ 
enum SYNCMGR_CONFLICT_ITEM_TYPE
    {
        SYNCMGR_CIT_UPDATED	= 0x1,
        SYNCMGR_CIT_DELETED	= 0x2
    } 	SYNCMGR_CONFLICT_ITEM_TYPE;

typedef DWORD SYNCMGR_CONFLICT_ITEM_TYPE_FLAG;





extern RPC_IF_HANDLE __MIDL_itf_syncmgr_0000_0019_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_syncmgr_0000_0019_v0_0_s_ifspec;

#ifndef __ISyncMgrConflict_INTERFACE_DEFINED__
#define __ISyncMgrConflict_INTERFACE_DEFINED__

/* interface ISyncMgrConflict */
/* [object][unique][uuid] */ 


EXTERN_C const IID IID_ISyncMgrConflict;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9c204249-c443-4ba4-85ed-c972681db137")
    ISyncMgrConflict : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetProperty( 
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY propkey,
            /* [annotation][out] */ 
            _Out_  PROPVARIANT *ppropvar) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetConflictIdInfo( 
            /* [annotation][out] */ 
            _Out_  SYNCMGR_CONFLICT_ID_INFO *pConflictIdInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetItemsArray( 
            /* [annotation][out] */ 
            _Out_  ISyncMgrConflictItems **ppArray) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Resolve( 
            /* [annotation][in] */ 
            _In_  ISyncMgrConflictResolveInfo *pResolveInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetResolutionHandler( 
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvResolutionHandler) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISyncMgrConflictVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISyncMgrConflict * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISyncMgrConflict * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISyncMgrConflict * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetProperty )( 
            __RPC__in ISyncMgrConflict * This,
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY propkey,
            /* [annotation][out] */ 
            _Out_  PROPVARIANT *ppropvar);
        
        HRESULT ( STDMETHODCALLTYPE *GetConflictIdInfo )( 
            __RPC__in ISyncMgrConflict * This,
            /* [annotation][out] */ 
            _Out_  SYNCMGR_CONFLICT_ID_INFO *pConflictIdInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetItemsArray )( 
            __RPC__in ISyncMgrConflict * This,
            /* [annotation][out] */ 
            _Out_  ISyncMgrConflictItems **ppArray);
        
        HRESULT ( STDMETHODCALLTYPE *Resolve )( 
            __RPC__in ISyncMgrConflict * This,
            /* [annotation][in] */ 
            _In_  ISyncMgrConflictResolveInfo *pResolveInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetResolutionHandler )( 
            __RPC__in ISyncMgrConflict * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvResolutionHandler);
        
        END_INTERFACE
    } ISyncMgrConflictVtbl;

    interface ISyncMgrConflict
    {
        CONST_VTBL struct ISyncMgrConflictVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISyncMgrConflict_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISyncMgrConflict_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISyncMgrConflict_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISyncMgrConflict_GetProperty(This,propkey,ppropvar)	\
    ( (This)->lpVtbl -> GetProperty(This,propkey,ppropvar) ) 

#define ISyncMgrConflict_GetConflictIdInfo(This,pConflictIdInfo)	\
    ( (This)->lpVtbl -> GetConflictIdInfo(This,pConflictIdInfo) ) 

#define ISyncMgrConflict_GetItemsArray(This,ppArray)	\
    ( (This)->lpVtbl -> GetItemsArray(This,ppArray) ) 

#define ISyncMgrConflict_Resolve(This,pResolveInfo)	\
    ( (This)->lpVtbl -> Resolve(This,pResolveInfo) ) 

#define ISyncMgrConflict_GetResolutionHandler(This,riid,ppvResolutionHandler)	\
    ( (This)->lpVtbl -> GetResolutionHandler(This,riid,ppvResolutionHandler) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISyncMgrConflict_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_syncmgr_0000_0020 */
/* [local] */ 

typedef /* [v1_enum] */ 
enum SYNCMGR_RESOLUTION_ABILITIES
    {
        SYNCMGR_RA_KEEPOTHER	= 0x1,
        SYNCMGR_RA_KEEPRECENT	= 0x2,
        SYNCMGR_RA_REMOVEFROMSYNCSET	= 0x4,
        SYNCMGR_RA_KEEP_SINGLE	= 0x8,
        SYNCMGR_RA_KEEP_MULTIPLE	= 0x10,
        SYNCMGR_RA_VALID	= 0x1f
    } 	SYNCMGR_RESOLUTION_ABILITIES;

typedef DWORD SYNCMGR_RESOLUTION_ABILITIES_FLAGS;

typedef /* [v1_enum] */ 
enum SYNCMGR_RESOLUTION_FEEDBACK
    {
        SYNCMGR_RF_CONTINUE	= 0,
        SYNCMGR_RF_REFRESH	= ( SYNCMGR_RF_CONTINUE + 1 ) ,
        SYNCMGR_RF_CANCEL	= ( SYNCMGR_RF_REFRESH + 1 ) 
    } 	SYNCMGR_RESOLUTION_FEEDBACK;



extern RPC_IF_HANDLE __MIDL_itf_syncmgr_0000_0020_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_syncmgr_0000_0020_v0_0_s_ifspec;

#ifndef __ISyncMgrResolutionHandler_INTERFACE_DEFINED__
#define __ISyncMgrResolutionHandler_INTERFACE_DEFINED__

/* interface ISyncMgrResolutionHandler */
/* [object][unique][uuid] */ 


EXTERN_C const IID IID_ISyncMgrResolutionHandler;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("40A3D052-8BFF-4c4b-A338-D4A395700DE9")
    ISyncMgrResolutionHandler : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE QueryAbilities( 
            /* [annotation][out] */ 
            _Out_  SYNCMGR_RESOLUTION_ABILITIES_FLAGS *pdwAbilities) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE KeepOther( 
            /* [annotation][in] */ 
            _In_  IShellItem *psiOther,
            /* [annotation][out] */ 
            _Out_  SYNCMGR_RESOLUTION_FEEDBACK *pFeedback) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE KeepRecent( 
            /* [annotation][out] */ 
            _Out_  SYNCMGR_RESOLUTION_FEEDBACK *pFeedback) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveFromSyncSet( 
            /* [annotation][out] */ 
            _Out_  SYNCMGR_RESOLUTION_FEEDBACK *pFeedback) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE KeepItems( 
            /* [annotation][in] */ 
            _In_  ISyncMgrConflictResolutionItems *pArray,
            /* [annotation][out] */ 
            _Out_  SYNCMGR_RESOLUTION_FEEDBACK *pFeedback) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISyncMgrResolutionHandlerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISyncMgrResolutionHandler * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISyncMgrResolutionHandler * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISyncMgrResolutionHandler * This);
        
        HRESULT ( STDMETHODCALLTYPE *QueryAbilities )( 
            __RPC__in ISyncMgrResolutionHandler * This,
            /* [annotation][out] */ 
            _Out_  SYNCMGR_RESOLUTION_ABILITIES_FLAGS *pdwAbilities);
        
        HRESULT ( STDMETHODCALLTYPE *KeepOther )( 
            __RPC__in ISyncMgrResolutionHandler * This,
            /* [annotation][in] */ 
            _In_  IShellItem *psiOther,
            /* [annotation][out] */ 
            _Out_  SYNCMGR_RESOLUTION_FEEDBACK *pFeedback);
        
        HRESULT ( STDMETHODCALLTYPE *KeepRecent )( 
            __RPC__in ISyncMgrResolutionHandler * This,
            /* [annotation][out] */ 
            _Out_  SYNCMGR_RESOLUTION_FEEDBACK *pFeedback);
        
        HRESULT ( STDMETHODCALLTYPE *RemoveFromSyncSet )( 
            __RPC__in ISyncMgrResolutionHandler * This,
            /* [annotation][out] */ 
            _Out_  SYNCMGR_RESOLUTION_FEEDBACK *pFeedback);
        
        HRESULT ( STDMETHODCALLTYPE *KeepItems )( 
            __RPC__in ISyncMgrResolutionHandler * This,
            /* [annotation][in] */ 
            _In_  ISyncMgrConflictResolutionItems *pArray,
            /* [annotation][out] */ 
            _Out_  SYNCMGR_RESOLUTION_FEEDBACK *pFeedback);
        
        END_INTERFACE
    } ISyncMgrResolutionHandlerVtbl;

    interface ISyncMgrResolutionHandler
    {
        CONST_VTBL struct ISyncMgrResolutionHandlerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISyncMgrResolutionHandler_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISyncMgrResolutionHandler_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISyncMgrResolutionHandler_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISyncMgrResolutionHandler_QueryAbilities(This,pdwAbilities)	\
    ( (This)->lpVtbl -> QueryAbilities(This,pdwAbilities) ) 

#define ISyncMgrResolutionHandler_KeepOther(This,psiOther,pFeedback)	\
    ( (This)->lpVtbl -> KeepOther(This,psiOther,pFeedback) ) 

#define ISyncMgrResolutionHandler_KeepRecent(This,pFeedback)	\
    ( (This)->lpVtbl -> KeepRecent(This,pFeedback) ) 

#define ISyncMgrResolutionHandler_RemoveFromSyncSet(This,pFeedback)	\
    ( (This)->lpVtbl -> RemoveFromSyncSet(This,pFeedback) ) 

#define ISyncMgrResolutionHandler_KeepItems(This,pArray,pFeedback)	\
    ( (This)->lpVtbl -> KeepItems(This,pArray,pFeedback) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISyncMgrResolutionHandler_INTERFACE_DEFINED__ */


#ifndef __ISyncMgrConflictPresenter_INTERFACE_DEFINED__
#define __ISyncMgrConflictPresenter_INTERFACE_DEFINED__

/* interface ISyncMgrConflictPresenter */
/* [object][unique][uuid] */ 


EXTERN_C const IID IID_ISyncMgrConflictPresenter;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0b4f5353-fd2b-42cd-8763-4779f2d508a3")
    ISyncMgrConflictPresenter : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE PresentConflict( 
            /* [annotation][in] */ 
            _In_  ISyncMgrConflict *pConflict,
            /* [annotation][in] */ 
            _In_  ISyncMgrConflictResolveInfo *pResolveInfo) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISyncMgrConflictPresenterVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISyncMgrConflictPresenter * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISyncMgrConflictPresenter * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISyncMgrConflictPresenter * This);
        
        HRESULT ( STDMETHODCALLTYPE *PresentConflict )( 
            __RPC__in ISyncMgrConflictPresenter * This,
            /* [annotation][in] */ 
            _In_  ISyncMgrConflict *pConflict,
            /* [annotation][in] */ 
            _In_  ISyncMgrConflictResolveInfo *pResolveInfo);
        
        END_INTERFACE
    } ISyncMgrConflictPresenterVtbl;

    interface ISyncMgrConflictPresenter
    {
        CONST_VTBL struct ISyncMgrConflictPresenterVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISyncMgrConflictPresenter_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISyncMgrConflictPresenter_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISyncMgrConflictPresenter_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISyncMgrConflictPresenter_PresentConflict(This,pConflict,pResolveInfo)	\
    ( (This)->lpVtbl -> PresentConflict(This,pConflict,pResolveInfo) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISyncMgrConflictPresenter_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_syncmgr_0000_0022 */
/* [local] */ 

typedef /* [v1_enum] */ 
enum SYNCMGR_PRESENTER_NEXT_STEP
    {
        SYNCMGR_PNS_CONTINUE	= 0,
        SYNCMGR_PNS_DEFAULT	= ( SYNCMGR_PNS_CONTINUE + 1 ) ,
        SYNCMGR_PNS_CANCEL	= ( SYNCMGR_PNS_DEFAULT + 1 ) 
    } 	SYNCMGR_PRESENTER_NEXT_STEP;

typedef /* [v1_enum] */ 
enum SYNCMGR_PRESENTER_CHOICE
    {
        SYNCMGR_PC_NO_CHOICE	= 0,
        SYNCMGR_PC_KEEP_ONE	= ( SYNCMGR_PC_NO_CHOICE + 1 ) ,
        SYNCMGR_PC_KEEP_MULTIPLE	= ( SYNCMGR_PC_KEEP_ONE + 1 ) ,
        SYNCMGR_PC_KEEP_RECENT	= ( SYNCMGR_PC_KEEP_MULTIPLE + 1 ) ,
        SYNCMGR_PC_REMOVE_FROM_SYNC_SET	= ( SYNCMGR_PC_KEEP_RECENT + 1 ) ,
        SYNCMGR_PC_SKIP	= ( SYNCMGR_PC_REMOVE_FROM_SYNC_SET + 1 ) 
    } 	SYNCMGR_PRESENTER_CHOICE;



extern RPC_IF_HANDLE __MIDL_itf_syncmgr_0000_0022_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_syncmgr_0000_0022_v0_0_s_ifspec;

#ifndef __ISyncMgrConflictResolveInfo_INTERFACE_DEFINED__
#define __ISyncMgrConflictResolveInfo_INTERFACE_DEFINED__

/* interface ISyncMgrConflictResolveInfo */
/* [uuid][local][object] */ 


EXTERN_C const IID IID_ISyncMgrConflictResolveInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("c405a219-25a2-442e-8743-b845a2cee93f")
    ISyncMgrConflictResolveInfo : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetIterationInfo( 
            /* [annotation][out] */ 
            _Out_  UINT *pnCurrentConflict,
            /* [annotation][out] */ 
            _Out_  UINT *pcConflicts,
            /* [annotation][out] */ 
            _Out_  UINT *pcRemainingForApplyToAll) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPresenterNextStep( 
            /* [annotation][out] */ 
            _Out_  SYNCMGR_PRESENTER_NEXT_STEP *pnPresenterNextStep) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPresenterChoice( 
            /* [annotation][out] */ 
            _Out_  SYNCMGR_PRESENTER_CHOICE *pnPresenterChoice,
            /* [annotation][out] */ 
            _Out_  BOOL *pfApplyToAll) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetItemChoiceCount( 
            /* [annotation][out] */ 
            _Out_  UINT *pcChoices) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetItemChoice( 
            /* [annotation][in] */ 
            _In_  UINT iChoice,
            /* [annotation][out] */ 
            _Out_  UINT *piChoiceIndex) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPresenterNextStep( 
            /* [annotation][in] */ 
            _In_  SYNCMGR_PRESENTER_NEXT_STEP nPresenterNextStep) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPresenterChoice( 
            /* [annotation][in] */ 
            _In_  SYNCMGR_PRESENTER_CHOICE nPresenterChoice,
            /* [annotation][in] */ 
            _In_  BOOL fApplyToAll) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetItemChoices( 
            /* [size_is][ref][in] */ UINT *prgiConflictItemIndexes,
            /* [annotation][in] */ 
            _In_  UINT cChoices) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISyncMgrConflictResolveInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISyncMgrConflictResolveInfo * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISyncMgrConflictResolveInfo * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISyncMgrConflictResolveInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetIterationInfo )( 
            ISyncMgrConflictResolveInfo * This,
            /* [annotation][out] */ 
            _Out_  UINT *pnCurrentConflict,
            /* [annotation][out] */ 
            _Out_  UINT *pcConflicts,
            /* [annotation][out] */ 
            _Out_  UINT *pcRemainingForApplyToAll);
        
        HRESULT ( STDMETHODCALLTYPE *GetPresenterNextStep )( 
            ISyncMgrConflictResolveInfo * This,
            /* [annotation][out] */ 
            _Out_  SYNCMGR_PRESENTER_NEXT_STEP *pnPresenterNextStep);
        
        HRESULT ( STDMETHODCALLTYPE *GetPresenterChoice )( 
            ISyncMgrConflictResolveInfo * This,
            /* [annotation][out] */ 
            _Out_  SYNCMGR_PRESENTER_CHOICE *pnPresenterChoice,
            /* [annotation][out] */ 
            _Out_  BOOL *pfApplyToAll);
        
        HRESULT ( STDMETHODCALLTYPE *GetItemChoiceCount )( 
            ISyncMgrConflictResolveInfo * This,
            /* [annotation][out] */ 
            _Out_  UINT *pcChoices);
        
        HRESULT ( STDMETHODCALLTYPE *GetItemChoice )( 
            ISyncMgrConflictResolveInfo * This,
            /* [annotation][in] */ 
            _In_  UINT iChoice,
            /* [annotation][out] */ 
            _Out_  UINT *piChoiceIndex);
        
        HRESULT ( STDMETHODCALLTYPE *SetPresenterNextStep )( 
            ISyncMgrConflictResolveInfo * This,
            /* [annotation][in] */ 
            _In_  SYNCMGR_PRESENTER_NEXT_STEP nPresenterNextStep);
        
        HRESULT ( STDMETHODCALLTYPE *SetPresenterChoice )( 
            ISyncMgrConflictResolveInfo * This,
            /* [annotation][in] */ 
            _In_  SYNCMGR_PRESENTER_CHOICE nPresenterChoice,
            /* [annotation][in] */ 
            _In_  BOOL fApplyToAll);
        
        HRESULT ( STDMETHODCALLTYPE *SetItemChoices )( 
            ISyncMgrConflictResolveInfo * This,
            /* [size_is][ref][in] */ UINT *prgiConflictItemIndexes,
            /* [annotation][in] */ 
            _In_  UINT cChoices);
        
        END_INTERFACE
    } ISyncMgrConflictResolveInfoVtbl;

    interface ISyncMgrConflictResolveInfo
    {
        CONST_VTBL struct ISyncMgrConflictResolveInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISyncMgrConflictResolveInfo_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISyncMgrConflictResolveInfo_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISyncMgrConflictResolveInfo_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISyncMgrConflictResolveInfo_GetIterationInfo(This,pnCurrentConflict,pcConflicts,pcRemainingForApplyToAll)	\
    ( (This)->lpVtbl -> GetIterationInfo(This,pnCurrentConflict,pcConflicts,pcRemainingForApplyToAll) ) 

#define ISyncMgrConflictResolveInfo_GetPresenterNextStep(This,pnPresenterNextStep)	\
    ( (This)->lpVtbl -> GetPresenterNextStep(This,pnPresenterNextStep) ) 

#define ISyncMgrConflictResolveInfo_GetPresenterChoice(This,pnPresenterChoice,pfApplyToAll)	\
    ( (This)->lpVtbl -> GetPresenterChoice(This,pnPresenterChoice,pfApplyToAll) ) 

#define ISyncMgrConflictResolveInfo_GetItemChoiceCount(This,pcChoices)	\
    ( (This)->lpVtbl -> GetItemChoiceCount(This,pcChoices) ) 

#define ISyncMgrConflictResolveInfo_GetItemChoice(This,iChoice,piChoiceIndex)	\
    ( (This)->lpVtbl -> GetItemChoice(This,iChoice,piChoiceIndex) ) 

#define ISyncMgrConflictResolveInfo_SetPresenterNextStep(This,nPresenterNextStep)	\
    ( (This)->lpVtbl -> SetPresenterNextStep(This,nPresenterNextStep) ) 

#define ISyncMgrConflictResolveInfo_SetPresenterChoice(This,nPresenterChoice,fApplyToAll)	\
    ( (This)->lpVtbl -> SetPresenterChoice(This,nPresenterChoice,fApplyToAll) ) 

#define ISyncMgrConflictResolveInfo_SetItemChoices(This,prgiConflictItemIndexes,cChoices)	\
    ( (This)->lpVtbl -> SetItemChoices(This,prgiConflictItemIndexes,cChoices) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISyncMgrConflictResolveInfo_INTERFACE_DEFINED__ */


#ifndef __ISyncMgrConflictFolder_INTERFACE_DEFINED__
#define __ISyncMgrConflictFolder_INTERFACE_DEFINED__

/* interface ISyncMgrConflictFolder */
/* [object][local][unique][uuid] */ 


EXTERN_C const IID IID_ISyncMgrConflictFolder;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("59287f5e-bc81-4fca-a7f1-e5a8ecdb1d69")
    ISyncMgrConflictFolder : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetConflictIDList( 
            /* [annotation][in] */ 
            _In_  ISyncMgrConflict *pConflict,
            /* [annotation][out] */ 
            _Out_  PIDLIST_RELATIVE *ppidlConflict) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISyncMgrConflictFolderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISyncMgrConflictFolder * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISyncMgrConflictFolder * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISyncMgrConflictFolder * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetConflictIDList )( 
            ISyncMgrConflictFolder * This,
            /* [annotation][in] */ 
            _In_  ISyncMgrConflict *pConflict,
            /* [annotation][out] */ 
            _Out_  PIDLIST_RELATIVE *ppidlConflict);
        
        END_INTERFACE
    } ISyncMgrConflictFolderVtbl;

    interface ISyncMgrConflictFolder
    {
        CONST_VTBL struct ISyncMgrConflictFolderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISyncMgrConflictFolder_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISyncMgrConflictFolder_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISyncMgrConflictFolder_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISyncMgrConflictFolder_GetConflictIDList(This,pConflict,ppidlConflict)	\
    ( (This)->lpVtbl -> GetConflictIDList(This,pConflict,ppidlConflict) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISyncMgrConflictFolder_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_syncmgr_0000_0024 */
/* [local] */ 

typedef struct CONFIRM_CONFLICT_ITEM
    {
    IShellItem2 *pShellItem;
    LPWSTR pszOriginalName;
    LPWSTR pszAlternateName;
    LPWSTR pszLocationShort;
    LPWSTR pszLocationFull;
    SYNCMGR_CONFLICT_ITEM_TYPE nType;
    } 	CONFIRM_CONFLICT_ITEM;

#if defined(__cplusplus) && !defined(CINTERFACE)
__inline void FreeConfirmConflictItem(_Inout_ CONFIRM_CONFLICT_ITEM *pcci)
{
    if (pcci->pShellItem)
    {
        pcci->pShellItem->Release();
    }
    ::CoTaskMemFree(pcci->pszOriginalName);
    ::CoTaskMemFree(pcci->pszAlternateName);
    ::CoTaskMemFree(pcci->pszLocationShort);
    ::CoTaskMemFree(pcci->pszLocationFull);
    ::ZeroMemory(pcci, sizeof(*pcci));
}
#endif // defined(__cplusplus) && !defined(CINTERFACE)
typedef struct CONFIRM_CONFLICT_RESULT_INFO
    {
    LPWSTR pszNewName;
    UINT iItemIndex;
    } 	CONFIRM_CONFLICT_RESULT_INFO;



extern RPC_IF_HANDLE __MIDL_itf_syncmgr_0000_0024_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_syncmgr_0000_0024_v0_0_s_ifspec;

#ifndef __ISyncMgrConflictItems_INTERFACE_DEFINED__
#define __ISyncMgrConflictItems_INTERFACE_DEFINED__

/* interface ISyncMgrConflictItems */
/* [object][unique][uuid] */ 


EXTERN_C const IID IID_ISyncMgrConflictItems;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9C7EAD52-8023-4936-A4DB-D2A9A99E436A")
    ISyncMgrConflictItems : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetCount( 
            /* [annotation][out] */ 
            _Out_  UINT *pCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetItem( 
            /* [annotation][in] */ 
            _In_  UINT iIndex,
            /* [annotation][out] */ 
            _Out_  CONFIRM_CONFLICT_ITEM *pItemInfo) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISyncMgrConflictItemsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISyncMgrConflictItems * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISyncMgrConflictItems * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISyncMgrConflictItems * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetCount )( 
            __RPC__in ISyncMgrConflictItems * This,
            /* [annotation][out] */ 
            _Out_  UINT *pCount);
        
        HRESULT ( STDMETHODCALLTYPE *GetItem )( 
            __RPC__in ISyncMgrConflictItems * This,
            /* [annotation][in] */ 
            _In_  UINT iIndex,
            /* [annotation][out] */ 
            _Out_  CONFIRM_CONFLICT_ITEM *pItemInfo);
        
        END_INTERFACE
    } ISyncMgrConflictItemsVtbl;

    interface ISyncMgrConflictItems
    {
        CONST_VTBL struct ISyncMgrConflictItemsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISyncMgrConflictItems_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISyncMgrConflictItems_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISyncMgrConflictItems_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISyncMgrConflictItems_GetCount(This,pCount)	\
    ( (This)->lpVtbl -> GetCount(This,pCount) ) 

#define ISyncMgrConflictItems_GetItem(This,iIndex,pItemInfo)	\
    ( (This)->lpVtbl -> GetItem(This,iIndex,pItemInfo) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISyncMgrConflictItems_INTERFACE_DEFINED__ */


#ifndef __ISyncMgrConflictResolutionItems_INTERFACE_DEFINED__
#define __ISyncMgrConflictResolutionItems_INTERFACE_DEFINED__

/* interface ISyncMgrConflictResolutionItems */
/* [object][unique][uuid] */ 


EXTERN_C const IID IID_ISyncMgrConflictResolutionItems;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("458725B9-129D-4135-A998-9CEAFEC27007")
    ISyncMgrConflictResolutionItems : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetCount( 
            /* [annotation][out] */ 
            _Out_  UINT *pCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetItem( 
            /* [annotation][in] */ 
            _In_  UINT iIndex,
            /* [annotation][out] */ 
            _Out_  CONFIRM_CONFLICT_RESULT_INFO *pItemInfo) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISyncMgrConflictResolutionItemsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISyncMgrConflictResolutionItems * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISyncMgrConflictResolutionItems * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISyncMgrConflictResolutionItems * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetCount )( 
            __RPC__in ISyncMgrConflictResolutionItems * This,
            /* [annotation][out] */ 
            _Out_  UINT *pCount);
        
        HRESULT ( STDMETHODCALLTYPE *GetItem )( 
            __RPC__in ISyncMgrConflictResolutionItems * This,
            /* [annotation][in] */ 
            _In_  UINT iIndex,
            /* [annotation][out] */ 
            _Out_  CONFIRM_CONFLICT_RESULT_INFO *pItemInfo);
        
        END_INTERFACE
    } ISyncMgrConflictResolutionItemsVtbl;

    interface ISyncMgrConflictResolutionItems
    {
        CONST_VTBL struct ISyncMgrConflictResolutionItemsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISyncMgrConflictResolutionItems_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISyncMgrConflictResolutionItems_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISyncMgrConflictResolutionItems_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISyncMgrConflictResolutionItems_GetCount(This,pCount)	\
    ( (This)->lpVtbl -> GetCount(This,pCount) ) 

#define ISyncMgrConflictResolutionItems_GetItem(This,iIndex,pItemInfo)	\
    ( (This)->lpVtbl -> GetItem(This,iIndex,pItemInfo) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISyncMgrConflictResolutionItems_INTERFACE_DEFINED__ */



#ifndef __SyncMgrObjects_LIBRARY_DEFINED__
#define __SyncMgrObjects_LIBRARY_DEFINED__

/* library SyncMgrObjects */
/* [version][lcid][helpstring][uuid] */ 


EXTERN_C const IID LIBID_SyncMgrObjects;

EXTERN_C const CLSID CLSID_SyncMgrClient;

#ifdef __cplusplus

class DECLSPEC_UUID("1202db60-1dac-42c5-aed5-1abdd432248e")
SyncMgrClient;
#endif

EXTERN_C const CLSID CLSID_SyncMgrControl;

#ifdef __cplusplus

class DECLSPEC_UUID("1a1f4206-0688-4e7f-be03-d82ec69df9a5")
SyncMgrControl;
#endif

EXTERN_C const CLSID CLSID_SyncMgrScheduleWizard;

#ifdef __cplusplus

class DECLSPEC_UUID("8d8b8e30-c451-421b-8553-d2976afa648c")
SyncMgrScheduleWizard;
#endif

EXTERN_C const CLSID CLSID_SyncMgrFolder;

#ifdef __cplusplus

class DECLSPEC_UUID("9c73f5e5-7ae7-4e32-a8e8-8d23b85255bf")
SyncMgrFolder;
#endif

EXTERN_C const CLSID CLSID_SyncSetupFolder;

#ifdef __cplusplus

class DECLSPEC_UUID("2e9e59c0-b437-4981-a647-9c34b9b90891")
SyncSetupFolder;
#endif

EXTERN_C const CLSID CLSID_ConflictFolder;

#ifdef __cplusplus

class DECLSPEC_UUID("289978ac-a101-4341-a817-21eba7fd046d")
ConflictFolder;
#endif

EXTERN_C const CLSID CLSID_SyncResultsFolder;

#ifdef __cplusplus

class DECLSPEC_UUID("71d99464-3b6b-475c-b241-e15883207529")
SyncResultsFolder;
#endif

EXTERN_C const CLSID CLSID_SimpleConflictPresenter;

#ifdef __cplusplus

class DECLSPEC_UUID("7a0f6ab7-ed84-46b6-b47e-02aa159a152b")
SimpleConflictPresenter;
#endif
#endif /* __SyncMgrObjects_LIBRARY_DEFINED__ */

/* interface __MIDL_itf_syncmgr_0000_0027 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_syncmgr_0000_0027_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_syncmgr_0000_0027_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     __RPC__in unsigned long *, unsigned long            , __RPC__in BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     __RPC__in unsigned long *, __RPC__in BSTR * ); 

unsigned long             __RPC_USER  HWND_UserSize(     __RPC__in unsigned long *, unsigned long            , __RPC__in HWND * ); 
unsigned char * __RPC_USER  HWND_UserMarshal(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in HWND * ); 
unsigned char * __RPC_USER  HWND_UserUnmarshal(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out HWND * ); 
void                      __RPC_USER  HWND_UserFree(     __RPC__in unsigned long *, __RPC__in HWND * ); 

unsigned long             __RPC_USER  LPSAFEARRAY_UserSize(     __RPC__in unsigned long *, unsigned long            , __RPC__in LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserMarshal(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserUnmarshal(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out LPSAFEARRAY * ); 
void                      __RPC_USER  LPSAFEARRAY_UserFree(     __RPC__in unsigned long *, __RPC__in LPSAFEARRAY * ); 

unsigned long             __RPC_USER  BSTR_UserSize64(     __RPC__in unsigned long *, unsigned long            , __RPC__in BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal64(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal64(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out BSTR * ); 
void                      __RPC_USER  BSTR_UserFree64(     __RPC__in unsigned long *, __RPC__in BSTR * ); 

unsigned long             __RPC_USER  HWND_UserSize64(     __RPC__in unsigned long *, unsigned long            , __RPC__in HWND * ); 
unsigned char * __RPC_USER  HWND_UserMarshal64(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in HWND * ); 
unsigned char * __RPC_USER  HWND_UserUnmarshal64(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out HWND * ); 
void                      __RPC_USER  HWND_UserFree64(     __RPC__in unsigned long *, __RPC__in HWND * ); 

unsigned long             __RPC_USER  LPSAFEARRAY_UserSize64(     __RPC__in unsigned long *, unsigned long            , __RPC__in LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserMarshal64(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserUnmarshal64(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out LPSAFEARRAY * ); 
void                      __RPC_USER  LPSAFEARRAY_UserFree64(     __RPC__in unsigned long *, __RPC__in LPSAFEARRAY * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


