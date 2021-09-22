

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

#ifndef __msfeeds_h__
#define __msfeeds_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IXFeedsManager_FWD_DEFINED__
#define __IXFeedsManager_FWD_DEFINED__
typedef interface IXFeedsManager IXFeedsManager;

#endif 	/* __IXFeedsManager_FWD_DEFINED__ */


#ifndef __IXFeedsEnum_FWD_DEFINED__
#define __IXFeedsEnum_FWD_DEFINED__
typedef interface IXFeedsEnum IXFeedsEnum;

#endif 	/* __IXFeedsEnum_FWD_DEFINED__ */


#ifndef __IXFeedFolder_FWD_DEFINED__
#define __IXFeedFolder_FWD_DEFINED__
typedef interface IXFeedFolder IXFeedFolder;

#endif 	/* __IXFeedFolder_FWD_DEFINED__ */


#ifndef __IXFeedFolderEvents_FWD_DEFINED__
#define __IXFeedFolderEvents_FWD_DEFINED__
typedef interface IXFeedFolderEvents IXFeedFolderEvents;

#endif 	/* __IXFeedFolderEvents_FWD_DEFINED__ */


#ifndef __IXFeed_FWD_DEFINED__
#define __IXFeed_FWD_DEFINED__
typedef interface IXFeed IXFeed;

#endif 	/* __IXFeed_FWD_DEFINED__ */


#ifndef __IXFeed2_FWD_DEFINED__
#define __IXFeed2_FWD_DEFINED__
typedef interface IXFeed2 IXFeed2;

#endif 	/* __IXFeed2_FWD_DEFINED__ */


#ifndef __IXFeedEvents_FWD_DEFINED__
#define __IXFeedEvents_FWD_DEFINED__
typedef interface IXFeedEvents IXFeedEvents;

#endif 	/* __IXFeedEvents_FWD_DEFINED__ */


#ifndef __IXFeedItem_FWD_DEFINED__
#define __IXFeedItem_FWD_DEFINED__
typedef interface IXFeedItem IXFeedItem;

#endif 	/* __IXFeedItem_FWD_DEFINED__ */


#ifndef __IXFeedItem2_FWD_DEFINED__
#define __IXFeedItem2_FWD_DEFINED__
typedef interface IXFeedItem2 IXFeedItem2;

#endif 	/* __IXFeedItem2_FWD_DEFINED__ */


#ifndef __IXFeedEnclosure_FWD_DEFINED__
#define __IXFeedEnclosure_FWD_DEFINED__
typedef interface IXFeedEnclosure IXFeedEnclosure;

#endif 	/* __IXFeedEnclosure_FWD_DEFINED__ */


#ifndef __IFeedsManager_FWD_DEFINED__
#define __IFeedsManager_FWD_DEFINED__
typedef interface IFeedsManager IFeedsManager;

#endif 	/* __IFeedsManager_FWD_DEFINED__ */


#ifndef __IFeedsEnum_FWD_DEFINED__
#define __IFeedsEnum_FWD_DEFINED__
typedef interface IFeedsEnum IFeedsEnum;

#endif 	/* __IFeedsEnum_FWD_DEFINED__ */


#ifndef __IFeedFolder_FWD_DEFINED__
#define __IFeedFolder_FWD_DEFINED__
typedef interface IFeedFolder IFeedFolder;

#endif 	/* __IFeedFolder_FWD_DEFINED__ */


#ifndef __IFeedFolderEvents_FWD_DEFINED__
#define __IFeedFolderEvents_FWD_DEFINED__
typedef interface IFeedFolderEvents IFeedFolderEvents;

#endif 	/* __IFeedFolderEvents_FWD_DEFINED__ */


#ifndef __IFeed_FWD_DEFINED__
#define __IFeed_FWD_DEFINED__
typedef interface IFeed IFeed;

#endif 	/* __IFeed_FWD_DEFINED__ */


#ifndef __IFeed2_FWD_DEFINED__
#define __IFeed2_FWD_DEFINED__
typedef interface IFeed2 IFeed2;

#endif 	/* __IFeed2_FWD_DEFINED__ */


#ifndef __IFeedEvents_FWD_DEFINED__
#define __IFeedEvents_FWD_DEFINED__
typedef interface IFeedEvents IFeedEvents;

#endif 	/* __IFeedEvents_FWD_DEFINED__ */


#ifndef __IFeedItem_FWD_DEFINED__
#define __IFeedItem_FWD_DEFINED__
typedef interface IFeedItem IFeedItem;

#endif 	/* __IFeedItem_FWD_DEFINED__ */


#ifndef __IFeedItem2_FWD_DEFINED__
#define __IFeedItem2_FWD_DEFINED__
typedef interface IFeedItem2 IFeedItem2;

#endif 	/* __IFeedItem2_FWD_DEFINED__ */


#ifndef __IFeedEnclosure_FWD_DEFINED__
#define __IFeedEnclosure_FWD_DEFINED__
typedef interface IFeedEnclosure IFeedEnclosure;

#endif 	/* __IFeedEnclosure_FWD_DEFINED__ */


#ifndef __FeedsManager_FWD_DEFINED__
#define __FeedsManager_FWD_DEFINED__

#ifdef __cplusplus
typedef class FeedsManager FeedsManager;
#else
typedef struct FeedsManager FeedsManager;
#endif /* __cplusplus */

#endif 	/* __FeedsManager_FWD_DEFINED__ */


#ifndef __FeedFolderWatcher_FWD_DEFINED__
#define __FeedFolderWatcher_FWD_DEFINED__

#ifdef __cplusplus
typedef class FeedFolderWatcher FeedFolderWatcher;
#else
typedef struct FeedFolderWatcher FeedFolderWatcher;
#endif /* __cplusplus */

#endif 	/* __FeedFolderWatcher_FWD_DEFINED__ */


#ifndef __FeedWatcher_FWD_DEFINED__
#define __FeedWatcher_FWD_DEFINED__

#ifdef __cplusplus
typedef class FeedWatcher FeedWatcher;
#else
typedef struct FeedWatcher FeedWatcher;
#endif /* __cplusplus */

#endif 	/* __FeedWatcher_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_msfeeds_0000_0000 */
/* [local] */ 

//=--------------------------------------------------------------------------=
// msfeeds.h
//=--------------------------------------------------------------------------=
// (C) Copyright Microsoft Corporation.  All Rights Reserved.
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//=--------------------------------------------------------------------------=
// RSS Platform Interfaces.

#include <winapifamily.h>
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
// {FE6B11C3-C72E-4061-86C6-9D163121F229}
DEFINE_GUID(CLSID_XFeedsManager, 0xfe6b11c3, 0xc72e, 0x4061, 0x86, 0xc6, 0x9d, 0x16, 0x31, 0x21, 0xf2, 0x29);
typedef /* [v1_enum] */ 
enum FEEDS_BACKGROUNDSYNC_ACTION
    {
        FBSA_DISABLE	= 0,
        FBSA_ENABLE	= 1,
        FBSA_RUNNOW	= 2
    } 	FEEDS_BACKGROUNDSYNC_ACTION;

typedef /* [v1_enum] */ 
enum FEEDS_BACKGROUNDSYNC_STATUS
    {
        FBSS_DISABLED	= 0,
        FBSS_ENABLED	= 1
    } 	FEEDS_BACKGROUNDSYNC_STATUS;

typedef /* [v1_enum] */ 
enum FEEDS_EVENTS_SCOPE
    {
        FES_ALL	= 0,
        FES_SELF_ONLY	= 1,
        FES_SELF_AND_CHILDREN_ONLY	= 2
    } 	FEEDS_EVENTS_SCOPE;

typedef /* [v1_enum] */ 
enum FEEDS_EVENTS_MASK
    {
        FEM_FOLDEREVENTS	= 0x1,
        FEM_FEEDEVENTS	= 0x2
    } 	FEEDS_EVENTS_MASK;


#define FEEDS_XML_COUNT_MAX ((UINT)-1)

typedef /* [v1_enum] */ 
enum FEEDS_XML_SORT_PROPERTY
    {
        FXSP_NONE	= 0,
        FXSP_PUBDATE	= 1,
        FXSP_DOWNLOADTIME	= 2
    } 	FEEDS_XML_SORT_PROPERTY;

typedef /* [v1_enum] */ 
enum FEEDS_XML_SORT_ORDER
    {
        FXSO_NONE	= 0,
        FXSO_ASCENDING	= 1,
        FXSO_DESCENDING	= 2
    } 	FEEDS_XML_SORT_ORDER;

typedef /* [v1_enum] */ 
enum FEEDS_XML_FILTER_FLAGS
    {
        FXFF_ALL	= 0,
        FXFF_UNREAD	= 0x1,
        FXFF_READ	= 0x2
    } 	FEEDS_XML_FILTER_FLAGS;

typedef /* [v1_enum] */ 
enum FEEDS_XML_INCLUDE_FLAGS
    {
        FXIF_NONE	= 0,
        FXIF_CF_EXTENSIONS	= 0x1
    } 	FEEDS_XML_INCLUDE_FLAGS;

typedef /* [v1_enum] */ 
enum FEEDS_DOWNLOAD_STATUS
    {
        FDS_NONE	= 0,
        FDS_PENDING	= 1,
        FDS_DOWNLOADING	= 2,
        FDS_DOWNLOADED	= 3,
        FDS_DOWNLOAD_FAILED	= 4
    } 	FEEDS_DOWNLOAD_STATUS;

typedef /* [v1_enum] */ 
enum FEEDS_SYNC_SETTING
    {
        FSS_DEFAULT	= 0,
        FSS_INTERVAL	= 1,
        FSS_MANUAL	= 2,
        FSS_SUGGESTED	= 3
    } 	FEEDS_SYNC_SETTING;

typedef /* [v1_enum] */ 
enum FEEDS_DOWNLOAD_ERROR
    {
        FDE_NONE	= 0,
        FDE_DOWNLOAD_FAILED	= 1,
        FDE_INVALID_FEED_FORMAT	= 2,
        FDE_NORMALIZATION_FAILED	= 3,
        FDE_PERSISTENCE_FAILED	= 4,
        FDE_DOWNLOAD_BLOCKED	= 5,
        FDE_CANCELED	= 6,
        FDE_UNSUPPORTED_AUTH	= 7,
        FDE_BACKGROUND_DOWNLOAD_DISABLED	= 8,
        FDE_NOT_EXIST	= 9,
        FDE_UNSUPPORTED_MSXML	= 10,
        FDE_UNSUPPORTED_DTD	= 11,
        FDE_DOWNLOAD_SIZE_LIMIT_EXCEEDED	= 12,
        FDE_ACCESS_DENIED	= 13,
        FDE_AUTH_FAILED	= 14,
        FDE_INVALID_AUTH	= 15
    } 	FEEDS_DOWNLOAD_ERROR;

typedef /* [v1_enum] */ 
enum FEEDS_EVENTS_ITEM_COUNT_FLAGS
    {
        FEICF_READ_ITEM_COUNT_CHANGED	= 0x1,
        FEICF_UNREAD_ITEM_COUNT_CHANGED	= 0x2
    } 	FEEDS_EVENTS_ITEM_COUNT_FLAGS;

typedef int FEICF;

typedef 
enum FEEDS_ERROR_CODE
    {
        FEC_E_ERRORBASE	= 0xc0040200L,
        FEC_E_INVALIDMSXMLPROPERTY	= FEC_E_ERRORBASE,
        FEC_E_DOWNLOADSIZELIMITEXCEEDED	= ( FEC_E_INVALIDMSXMLPROPERTY + 1 ) 
    } 	FEEDS_ERROR_CODE;



extern RPC_IF_HANDLE __MIDL_itf_msfeeds_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_msfeeds_0000_0000_v0_0_s_ifspec;

#ifndef __IXFeedsManager_INTERFACE_DEFINED__
#define __IXFeedsManager_INTERFACE_DEFINED__

/* interface IXFeedsManager */
/* [object][uuid] */ 


EXTERN_C const IID IID_IXFeedsManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5357e238-fb12-4aca-a930-cab7832b84bf")
    IXFeedsManager : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE RootFolder( 
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppv) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsSubscribed( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszUrl,
            /* [annotation][out] */ 
            _Out_  BOOL *pbSubscribed) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ExistsFeed( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPath,
            /* [annotation][out] */ 
            _Out_  BOOL *pbFeedExists) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFeed( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPath,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppv) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFeedByUrl( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszUrl,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppv) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ExistsFolder( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPath,
            /* [annotation][out] */ 
            _Out_  BOOL *pbFolderExists) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFolder( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPath,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppv) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DeleteFeed( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DeleteFolder( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE BackgroundSync( 
            /* [annotation][in] */ 
            _In_  FEEDS_BACKGROUNDSYNC_ACTION fbsa) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE BackgroundSyncStatus( 
            /* [annotation][out] */ 
            _Out_  FEEDS_BACKGROUNDSYNC_STATUS *pfbss) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DefaultInterval( 
            /* [annotation][out] */ 
            _Out_  UINT *puiInterval) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDefaultInterval( 
            /* [annotation][in] */ 
            _In_  UINT uiInterval) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AsyncSyncAll( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Normalize( 
            /* [annotation][in] */ 
            _In_  IStream *pStreamIn,
            /* [annotation][out] */ 
            _Out_  IStream **ppStreamOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ItemCountLimit( 
            /* [annotation][out] */ 
            _Out_  UINT *puiItemCountLimit) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IXFeedsManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IXFeedsManager * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IXFeedsManager * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IXFeedsManager * This);
        
        HRESULT ( STDMETHODCALLTYPE *RootFolder )( 
            __RPC__in IXFeedsManager * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppv);
        
        HRESULT ( STDMETHODCALLTYPE *IsSubscribed )( 
            __RPC__in IXFeedsManager * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszUrl,
            /* [annotation][out] */ 
            _Out_  BOOL *pbSubscribed);
        
        HRESULT ( STDMETHODCALLTYPE *ExistsFeed )( 
            __RPC__in IXFeedsManager * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPath,
            /* [annotation][out] */ 
            _Out_  BOOL *pbFeedExists);
        
        HRESULT ( STDMETHODCALLTYPE *GetFeed )( 
            __RPC__in IXFeedsManager * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPath,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppv);
        
        HRESULT ( STDMETHODCALLTYPE *GetFeedByUrl )( 
            __RPC__in IXFeedsManager * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszUrl,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppv);
        
        HRESULT ( STDMETHODCALLTYPE *ExistsFolder )( 
            __RPC__in IXFeedsManager * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPath,
            /* [annotation][out] */ 
            _Out_  BOOL *pbFolderExists);
        
        HRESULT ( STDMETHODCALLTYPE *GetFolder )( 
            __RPC__in IXFeedsManager * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPath,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppv);
        
        HRESULT ( STDMETHODCALLTYPE *DeleteFeed )( 
            __RPC__in IXFeedsManager * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPath);
        
        HRESULT ( STDMETHODCALLTYPE *DeleteFolder )( 
            __RPC__in IXFeedsManager * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPath);
        
        HRESULT ( STDMETHODCALLTYPE *BackgroundSync )( 
            __RPC__in IXFeedsManager * This,
            /* [annotation][in] */ 
            _In_  FEEDS_BACKGROUNDSYNC_ACTION fbsa);
        
        HRESULT ( STDMETHODCALLTYPE *BackgroundSyncStatus )( 
            __RPC__in IXFeedsManager * This,
            /* [annotation][out] */ 
            _Out_  FEEDS_BACKGROUNDSYNC_STATUS *pfbss);
        
        HRESULT ( STDMETHODCALLTYPE *DefaultInterval )( 
            __RPC__in IXFeedsManager * This,
            /* [annotation][out] */ 
            _Out_  UINT *puiInterval);
        
        HRESULT ( STDMETHODCALLTYPE *SetDefaultInterval )( 
            __RPC__in IXFeedsManager * This,
            /* [annotation][in] */ 
            _In_  UINT uiInterval);
        
        HRESULT ( STDMETHODCALLTYPE *AsyncSyncAll )( 
            __RPC__in IXFeedsManager * This);
        
        HRESULT ( STDMETHODCALLTYPE *Normalize )( 
            __RPC__in IXFeedsManager * This,
            /* [annotation][in] */ 
            _In_  IStream *pStreamIn,
            /* [annotation][out] */ 
            _Out_  IStream **ppStreamOut);
        
        HRESULT ( STDMETHODCALLTYPE *ItemCountLimit )( 
            __RPC__in IXFeedsManager * This,
            /* [annotation][out] */ 
            _Out_  UINT *puiItemCountLimit);
        
        END_INTERFACE
    } IXFeedsManagerVtbl;

    interface IXFeedsManager
    {
        CONST_VTBL struct IXFeedsManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IXFeedsManager_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IXFeedsManager_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IXFeedsManager_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IXFeedsManager_RootFolder(This,riid,ppv)	\
    ( (This)->lpVtbl -> RootFolder(This,riid,ppv) ) 

#define IXFeedsManager_IsSubscribed(This,pszUrl,pbSubscribed)	\
    ( (This)->lpVtbl -> IsSubscribed(This,pszUrl,pbSubscribed) ) 

#define IXFeedsManager_ExistsFeed(This,pszPath,pbFeedExists)	\
    ( (This)->lpVtbl -> ExistsFeed(This,pszPath,pbFeedExists) ) 

#define IXFeedsManager_GetFeed(This,pszPath,riid,ppv)	\
    ( (This)->lpVtbl -> GetFeed(This,pszPath,riid,ppv) ) 

#define IXFeedsManager_GetFeedByUrl(This,pszUrl,riid,ppv)	\
    ( (This)->lpVtbl -> GetFeedByUrl(This,pszUrl,riid,ppv) ) 

#define IXFeedsManager_ExistsFolder(This,pszPath,pbFolderExists)	\
    ( (This)->lpVtbl -> ExistsFolder(This,pszPath,pbFolderExists) ) 

#define IXFeedsManager_GetFolder(This,pszPath,riid,ppv)	\
    ( (This)->lpVtbl -> GetFolder(This,pszPath,riid,ppv) ) 

#define IXFeedsManager_DeleteFeed(This,pszPath)	\
    ( (This)->lpVtbl -> DeleteFeed(This,pszPath) ) 

#define IXFeedsManager_DeleteFolder(This,pszPath)	\
    ( (This)->lpVtbl -> DeleteFolder(This,pszPath) ) 

#define IXFeedsManager_BackgroundSync(This,fbsa)	\
    ( (This)->lpVtbl -> BackgroundSync(This,fbsa) ) 

#define IXFeedsManager_BackgroundSyncStatus(This,pfbss)	\
    ( (This)->lpVtbl -> BackgroundSyncStatus(This,pfbss) ) 

#define IXFeedsManager_DefaultInterval(This,puiInterval)	\
    ( (This)->lpVtbl -> DefaultInterval(This,puiInterval) ) 

#define IXFeedsManager_SetDefaultInterval(This,uiInterval)	\
    ( (This)->lpVtbl -> SetDefaultInterval(This,uiInterval) ) 

#define IXFeedsManager_AsyncSyncAll(This)	\
    ( (This)->lpVtbl -> AsyncSyncAll(This) ) 

#define IXFeedsManager_Normalize(This,pStreamIn,ppStreamOut)	\
    ( (This)->lpVtbl -> Normalize(This,pStreamIn,ppStreamOut) ) 

#define IXFeedsManager_ItemCountLimit(This,puiItemCountLimit)	\
    ( (This)->lpVtbl -> ItemCountLimit(This,puiItemCountLimit) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IXFeedsManager_INTERFACE_DEFINED__ */


#ifndef __IXFeedsEnum_INTERFACE_DEFINED__
#define __IXFeedsEnum_INTERFACE_DEFINED__

/* interface IXFeedsEnum */
/* [object][uuid] */ 


EXTERN_C const IID IID_IXFeedsEnum;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("dc43a9d5-5015-4301-8c96-a47434b4d658")
    IXFeedsEnum : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Count( 
            /* [annotation][out] */ 
            _Out_  UINT *puiCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Item( 
            /* [annotation][in] */ 
            _In_  UINT uiIndex,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppv) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IXFeedsEnumVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IXFeedsEnum * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IXFeedsEnum * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IXFeedsEnum * This);
        
        HRESULT ( STDMETHODCALLTYPE *Count )( 
            __RPC__in IXFeedsEnum * This,
            /* [annotation][out] */ 
            _Out_  UINT *puiCount);
        
        HRESULT ( STDMETHODCALLTYPE *Item )( 
            __RPC__in IXFeedsEnum * This,
            /* [annotation][in] */ 
            _In_  UINT uiIndex,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppv);
        
        END_INTERFACE
    } IXFeedsEnumVtbl;

    interface IXFeedsEnum
    {
        CONST_VTBL struct IXFeedsEnumVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IXFeedsEnum_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IXFeedsEnum_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IXFeedsEnum_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IXFeedsEnum_Count(This,puiCount)	\
    ( (This)->lpVtbl -> Count(This,puiCount) ) 

#define IXFeedsEnum_Item(This,uiIndex,riid,ppv)	\
    ( (This)->lpVtbl -> Item(This,uiIndex,riid,ppv) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IXFeedsEnum_INTERFACE_DEFINED__ */


#ifndef __IXFeedFolder_INTERFACE_DEFINED__
#define __IXFeedFolder_INTERFACE_DEFINED__

/* interface IXFeedFolder */
/* [object][uuid] */ 


EXTERN_C const IID IID_IXFeedFolder;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4c963678-3a51-4b88-8531-98b90b6508f2")
    IXFeedFolder : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Feeds( 
            /* [annotation][out] */ 
            _Out_  IXFeedsEnum **ppfe) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Subfolders( 
            /* [annotation][out] */ 
            _Out_  IXFeedsEnum **ppfe) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateFeed( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszUrl,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppv) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateSubfolder( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppv) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ExistsFeed( 
            __RPC__in LPCWSTR pszName,
            __RPC__in BOOL *pbFeedExists) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ExistsSubfolder( 
            __RPC__in LPCWSTR pszName,
            __RPC__in BOOL *pbSubfolderExists) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFeed( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppv) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSubfolder( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppv) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Delete( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Name( 
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Rename( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Path( 
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Move( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Parent( 
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppv) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsRoot( 
            /* [annotation][out] */ 
            _Out_  BOOL *pbIsRootFeedFolder) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetWatcher( 
            /* [annotation][in] */ 
            _In_  FEEDS_EVENTS_SCOPE scope,
            /* [annotation][in] */ 
            _In_  FEEDS_EVENTS_MASK mask,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppv) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE TotalUnreadItemCount( 
            /* [annotation][out] */ 
            _Out_  UINT *puiTotalUnreadItemCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE TotalItemCount( 
            /* [annotation][out] */ 
            _Out_  UINT *puiTotalItemCount) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IXFeedFolderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IXFeedFolder * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IXFeedFolder * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IXFeedFolder * This);
        
        HRESULT ( STDMETHODCALLTYPE *Feeds )( 
            __RPC__in IXFeedFolder * This,
            /* [annotation][out] */ 
            _Out_  IXFeedsEnum **ppfe);
        
        HRESULT ( STDMETHODCALLTYPE *Subfolders )( 
            __RPC__in IXFeedFolder * This,
            /* [annotation][out] */ 
            _Out_  IXFeedsEnum **ppfe);
        
        HRESULT ( STDMETHODCALLTYPE *CreateFeed )( 
            __RPC__in IXFeedFolder * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszUrl,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppv);
        
        HRESULT ( STDMETHODCALLTYPE *CreateSubfolder )( 
            __RPC__in IXFeedFolder * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppv);
        
        HRESULT ( STDMETHODCALLTYPE *ExistsFeed )( 
            __RPC__in IXFeedFolder * This,
            __RPC__in LPCWSTR pszName,
            __RPC__in BOOL *pbFeedExists);
        
        HRESULT ( STDMETHODCALLTYPE *ExistsSubfolder )( 
            __RPC__in IXFeedFolder * This,
            __RPC__in LPCWSTR pszName,
            __RPC__in BOOL *pbSubfolderExists);
        
        HRESULT ( STDMETHODCALLTYPE *GetFeed )( 
            __RPC__in IXFeedFolder * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppv);
        
        HRESULT ( STDMETHODCALLTYPE *GetSubfolder )( 
            __RPC__in IXFeedFolder * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppv);
        
        HRESULT ( STDMETHODCALLTYPE *Delete )( 
            __RPC__in IXFeedFolder * This);
        
        HRESULT ( STDMETHODCALLTYPE *Name )( 
            __RPC__in IXFeedFolder * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszName);
        
        HRESULT ( STDMETHODCALLTYPE *Rename )( 
            __RPC__in IXFeedFolder * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszName);
        
        HRESULT ( STDMETHODCALLTYPE *Path )( 
            __RPC__in IXFeedFolder * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszPath);
        
        HRESULT ( STDMETHODCALLTYPE *Move )( 
            __RPC__in IXFeedFolder * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPath);
        
        HRESULT ( STDMETHODCALLTYPE *Parent )( 
            __RPC__in IXFeedFolder * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppv);
        
        HRESULT ( STDMETHODCALLTYPE *IsRoot )( 
            __RPC__in IXFeedFolder * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pbIsRootFeedFolder);
        
        HRESULT ( STDMETHODCALLTYPE *GetWatcher )( 
            __RPC__in IXFeedFolder * This,
            /* [annotation][in] */ 
            _In_  FEEDS_EVENTS_SCOPE scope,
            /* [annotation][in] */ 
            _In_  FEEDS_EVENTS_MASK mask,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppv);
        
        HRESULT ( STDMETHODCALLTYPE *TotalUnreadItemCount )( 
            __RPC__in IXFeedFolder * This,
            /* [annotation][out] */ 
            _Out_  UINT *puiTotalUnreadItemCount);
        
        HRESULT ( STDMETHODCALLTYPE *TotalItemCount )( 
            __RPC__in IXFeedFolder * This,
            /* [annotation][out] */ 
            _Out_  UINT *puiTotalItemCount);
        
        END_INTERFACE
    } IXFeedFolderVtbl;

    interface IXFeedFolder
    {
        CONST_VTBL struct IXFeedFolderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IXFeedFolder_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IXFeedFolder_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IXFeedFolder_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IXFeedFolder_Feeds(This,ppfe)	\
    ( (This)->lpVtbl -> Feeds(This,ppfe) ) 

#define IXFeedFolder_Subfolders(This,ppfe)	\
    ( (This)->lpVtbl -> Subfolders(This,ppfe) ) 

#define IXFeedFolder_CreateFeed(This,pszName,pszUrl,riid,ppv)	\
    ( (This)->lpVtbl -> CreateFeed(This,pszName,pszUrl,riid,ppv) ) 

#define IXFeedFolder_CreateSubfolder(This,pszName,riid,ppv)	\
    ( (This)->lpVtbl -> CreateSubfolder(This,pszName,riid,ppv) ) 

#define IXFeedFolder_ExistsFeed(This,pszName,pbFeedExists)	\
    ( (This)->lpVtbl -> ExistsFeed(This,pszName,pbFeedExists) ) 

#define IXFeedFolder_ExistsSubfolder(This,pszName,pbSubfolderExists)	\
    ( (This)->lpVtbl -> ExistsSubfolder(This,pszName,pbSubfolderExists) ) 

#define IXFeedFolder_GetFeed(This,pszName,riid,ppv)	\
    ( (This)->lpVtbl -> GetFeed(This,pszName,riid,ppv) ) 

#define IXFeedFolder_GetSubfolder(This,pszName,riid,ppv)	\
    ( (This)->lpVtbl -> GetSubfolder(This,pszName,riid,ppv) ) 

#define IXFeedFolder_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define IXFeedFolder_Name(This,ppszName)	\
    ( (This)->lpVtbl -> Name(This,ppszName) ) 

#define IXFeedFolder_Rename(This,pszName)	\
    ( (This)->lpVtbl -> Rename(This,pszName) ) 

#define IXFeedFolder_Path(This,ppszPath)	\
    ( (This)->lpVtbl -> Path(This,ppszPath) ) 

#define IXFeedFolder_Move(This,pszPath)	\
    ( (This)->lpVtbl -> Move(This,pszPath) ) 

#define IXFeedFolder_Parent(This,riid,ppv)	\
    ( (This)->lpVtbl -> Parent(This,riid,ppv) ) 

#define IXFeedFolder_IsRoot(This,pbIsRootFeedFolder)	\
    ( (This)->lpVtbl -> IsRoot(This,pbIsRootFeedFolder) ) 

#define IXFeedFolder_GetWatcher(This,scope,mask,riid,ppv)	\
    ( (This)->lpVtbl -> GetWatcher(This,scope,mask,riid,ppv) ) 

#define IXFeedFolder_TotalUnreadItemCount(This,puiTotalUnreadItemCount)	\
    ( (This)->lpVtbl -> TotalUnreadItemCount(This,puiTotalUnreadItemCount) ) 

#define IXFeedFolder_TotalItemCount(This,puiTotalItemCount)	\
    ( (This)->lpVtbl -> TotalItemCount(This,puiTotalItemCount) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IXFeedFolder_INTERFACE_DEFINED__ */


#ifndef __IXFeedFolderEvents_INTERFACE_DEFINED__
#define __IXFeedFolderEvents_INTERFACE_DEFINED__

/* interface IXFeedFolderEvents */
/* [object][uuid] */ 


EXTERN_C const IID IID_IXFeedFolderEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7964b769-234a-4bb1-a5f4-90454c8ad07e")
    IXFeedFolderEvents : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Error( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FolderAdded( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FolderDeleted( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FolderRenamed( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPath,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszOldPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FolderMovedFrom( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPath,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszOldPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FolderMovedTo( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPath,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszOldPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FolderItemCountChanged( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPath,
            /* [annotation][in] */ 
            _In_  FEICF feicfFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FeedAdded( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FeedDeleted( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FeedRenamed( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPath,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszOldPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FeedUrlChanged( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FeedMovedFrom( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPath,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszOldPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FeedMovedTo( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPath,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszOldPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FeedDownloading( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FeedDownloadCompleted( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPath,
            /* [annotation][in] */ 
            _In_  FEEDS_DOWNLOAD_ERROR fde) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FeedItemCountChanged( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPath,
            /* [annotation][in] */ 
            _In_  FEICF feicfFlags) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IXFeedFolderEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IXFeedFolderEvents * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IXFeedFolderEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IXFeedFolderEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *Error )( 
            __RPC__in IXFeedFolderEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *FolderAdded )( 
            __RPC__in IXFeedFolderEvents * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPath);
        
        HRESULT ( STDMETHODCALLTYPE *FolderDeleted )( 
            __RPC__in IXFeedFolderEvents * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPath);
        
        HRESULT ( STDMETHODCALLTYPE *FolderRenamed )( 
            __RPC__in IXFeedFolderEvents * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPath,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszOldPath);
        
        HRESULT ( STDMETHODCALLTYPE *FolderMovedFrom )( 
            __RPC__in IXFeedFolderEvents * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPath,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszOldPath);
        
        HRESULT ( STDMETHODCALLTYPE *FolderMovedTo )( 
            __RPC__in IXFeedFolderEvents * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPath,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszOldPath);
        
        HRESULT ( STDMETHODCALLTYPE *FolderItemCountChanged )( 
            __RPC__in IXFeedFolderEvents * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPath,
            /* [annotation][in] */ 
            _In_  FEICF feicfFlags);
        
        HRESULT ( STDMETHODCALLTYPE *FeedAdded )( 
            __RPC__in IXFeedFolderEvents * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPath);
        
        HRESULT ( STDMETHODCALLTYPE *FeedDeleted )( 
            __RPC__in IXFeedFolderEvents * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPath);
        
        HRESULT ( STDMETHODCALLTYPE *FeedRenamed )( 
            __RPC__in IXFeedFolderEvents * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPath,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszOldPath);
        
        HRESULT ( STDMETHODCALLTYPE *FeedUrlChanged )( 
            __RPC__in IXFeedFolderEvents * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPath);
        
        HRESULT ( STDMETHODCALLTYPE *FeedMovedFrom )( 
            __RPC__in IXFeedFolderEvents * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPath,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszOldPath);
        
        HRESULT ( STDMETHODCALLTYPE *FeedMovedTo )( 
            __RPC__in IXFeedFolderEvents * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPath,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszOldPath);
        
        HRESULT ( STDMETHODCALLTYPE *FeedDownloading )( 
            __RPC__in IXFeedFolderEvents * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPath);
        
        HRESULT ( STDMETHODCALLTYPE *FeedDownloadCompleted )( 
            __RPC__in IXFeedFolderEvents * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPath,
            /* [annotation][in] */ 
            _In_  FEEDS_DOWNLOAD_ERROR fde);
        
        HRESULT ( STDMETHODCALLTYPE *FeedItemCountChanged )( 
            __RPC__in IXFeedFolderEvents * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPath,
            /* [annotation][in] */ 
            _In_  FEICF feicfFlags);
        
        END_INTERFACE
    } IXFeedFolderEventsVtbl;

    interface IXFeedFolderEvents
    {
        CONST_VTBL struct IXFeedFolderEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IXFeedFolderEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IXFeedFolderEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IXFeedFolderEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IXFeedFolderEvents_Error(This)	\
    ( (This)->lpVtbl -> Error(This) ) 

#define IXFeedFolderEvents_FolderAdded(This,pszPath)	\
    ( (This)->lpVtbl -> FolderAdded(This,pszPath) ) 

#define IXFeedFolderEvents_FolderDeleted(This,pszPath)	\
    ( (This)->lpVtbl -> FolderDeleted(This,pszPath) ) 

#define IXFeedFolderEvents_FolderRenamed(This,pszPath,pszOldPath)	\
    ( (This)->lpVtbl -> FolderRenamed(This,pszPath,pszOldPath) ) 

#define IXFeedFolderEvents_FolderMovedFrom(This,pszPath,pszOldPath)	\
    ( (This)->lpVtbl -> FolderMovedFrom(This,pszPath,pszOldPath) ) 

#define IXFeedFolderEvents_FolderMovedTo(This,pszPath,pszOldPath)	\
    ( (This)->lpVtbl -> FolderMovedTo(This,pszPath,pszOldPath) ) 

#define IXFeedFolderEvents_FolderItemCountChanged(This,pszPath,feicfFlags)	\
    ( (This)->lpVtbl -> FolderItemCountChanged(This,pszPath,feicfFlags) ) 

#define IXFeedFolderEvents_FeedAdded(This,pszPath)	\
    ( (This)->lpVtbl -> FeedAdded(This,pszPath) ) 

#define IXFeedFolderEvents_FeedDeleted(This,pszPath)	\
    ( (This)->lpVtbl -> FeedDeleted(This,pszPath) ) 

#define IXFeedFolderEvents_FeedRenamed(This,pszPath,pszOldPath)	\
    ( (This)->lpVtbl -> FeedRenamed(This,pszPath,pszOldPath) ) 

#define IXFeedFolderEvents_FeedUrlChanged(This,pszPath)	\
    ( (This)->lpVtbl -> FeedUrlChanged(This,pszPath) ) 

#define IXFeedFolderEvents_FeedMovedFrom(This,pszPath,pszOldPath)	\
    ( (This)->lpVtbl -> FeedMovedFrom(This,pszPath,pszOldPath) ) 

#define IXFeedFolderEvents_FeedMovedTo(This,pszPath,pszOldPath)	\
    ( (This)->lpVtbl -> FeedMovedTo(This,pszPath,pszOldPath) ) 

#define IXFeedFolderEvents_FeedDownloading(This,pszPath)	\
    ( (This)->lpVtbl -> FeedDownloading(This,pszPath) ) 

#define IXFeedFolderEvents_FeedDownloadCompleted(This,pszPath,fde)	\
    ( (This)->lpVtbl -> FeedDownloadCompleted(This,pszPath,fde) ) 

#define IXFeedFolderEvents_FeedItemCountChanged(This,pszPath,feicfFlags)	\
    ( (This)->lpVtbl -> FeedItemCountChanged(This,pszPath,feicfFlags) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IXFeedFolderEvents_INTERFACE_DEFINED__ */


#ifndef __IXFeed_INTERFACE_DEFINED__
#define __IXFeed_INTERFACE_DEFINED__

/* interface IXFeed */
/* [object][uuid] */ 


EXTERN_C const IID IID_IXFeed;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("a44179a4-e0f6-403b-af8d-d080f425a451")
    IXFeed : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Xml( 
            /* [annotation][in] */ 
            _In_  UINT uiItemCount,
            /* [annotation][in] */ 
            _In_  FEEDS_XML_SORT_PROPERTY sortProperty,
            /* [annotation][in] */ 
            _In_  FEEDS_XML_SORT_ORDER sortOrder,
            /* [annotation][in] */ 
            _In_  FEEDS_XML_FILTER_FLAGS filterFlags,
            /* [annotation][in] */ 
            _In_  FEEDS_XML_INCLUDE_FLAGS includeFlags,
            /* [annotation][out] */ 
            _Out_  IStream **pps) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Name( 
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Rename( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Url( 
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszUrl) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetUrl( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszUrl) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LocalId( 
            /* [annotation][out] */ 
            _Out_  GUID *pguid) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Path( 
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Move( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Parent( 
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppv) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LastWriteTime( 
            /* [annotation][out] */ 
            _Out_  SYSTEMTIME *pstLastWriteTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Delete( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Download( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AsyncDownload( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CancelAsyncDownload( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SyncSetting( 
            /* [annotation][out] */ 
            _Out_  FEEDS_SYNC_SETTING *pfss) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetSyncSetting( 
            /* [annotation][in] */ 
            _In_  FEEDS_SYNC_SETTING fss) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Interval( 
            /* [annotation][out] */ 
            _Out_  UINT *puiInterval) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetInterval( 
            /* [annotation][in] */ 
            _In_  UINT uiInterval) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LastDownloadTime( 
            /* [annotation][out] */ 
            _Out_  SYSTEMTIME *pstLastDownloadTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LocalEnclosurePath( 
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Items( 
            /* [annotation][out] */ 
            _Out_  IXFeedsEnum **ppfe) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetItem( 
            /* [annotation][in] */ 
            _In_  UINT uiId,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppv) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE MarkAllItemsRead( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE MaxItemCount( 
            /* [annotation][out] */ 
            _Out_  UINT *puiMaxItemCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMaxItemCount( 
            /* [annotation][in] */ 
            _In_  UINT uiMaxItemCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DownloadEnclosuresAutomatically( 
            /* [annotation][out] */ 
            _Out_  BOOL *pbDownloadEnclosuresAutomatically) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDownloadEnclosuresAutomatically( 
            /* [annotation][in] */ 
            _In_  BOOL bDownloadEnclosuresAutomatically) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DownloadStatus( 
            /* [annotation][out] */ 
            _Out_  FEEDS_DOWNLOAD_STATUS *pfds) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LastDownloadError( 
            /* [annotation][out] */ 
            _Out_  FEEDS_DOWNLOAD_ERROR *pfde) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Merge( 
            /* [annotation][in] */ 
            _In_  IStream *pStream,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszUrl) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DownloadUrl( 
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszUrl) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Title( 
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszTitle) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Description( 
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszDescription) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Link( 
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszHomePage) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Image( 
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszImageUrl) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LastBuildDate( 
            /* [annotation][out] */ 
            _Out_  SYSTEMTIME *pstLastBuildDate) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PubDate( 
            /* [annotation][out] */ 
            _Out_  SYSTEMTIME *pstPubDate) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Ttl( 
            /* [annotation][out] */ 
            _Out_  UINT *puiTtl) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Language( 
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszLanguage) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Copyright( 
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszCopyright) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsList( 
            /* [annotation][out] */ 
            _Out_  BOOL *pbIsList) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetWatcher( 
            /* [annotation][in] */ 
            _In_  FEEDS_EVENTS_SCOPE scope,
            /* [annotation][in] */ 
            _In_  FEEDS_EVENTS_MASK mask,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppv) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UnreadItemCount( 
            /* [annotation][out] */ 
            _Out_  UINT *puiUnreadItemCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ItemCount( 
            /* [annotation][out] */ 
            _Out_  UINT *puiItemCount) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IXFeedVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IXFeed * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IXFeed * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IXFeed * This);
        
        HRESULT ( STDMETHODCALLTYPE *Xml )( 
            __RPC__in IXFeed * This,
            /* [annotation][in] */ 
            _In_  UINT uiItemCount,
            /* [annotation][in] */ 
            _In_  FEEDS_XML_SORT_PROPERTY sortProperty,
            /* [annotation][in] */ 
            _In_  FEEDS_XML_SORT_ORDER sortOrder,
            /* [annotation][in] */ 
            _In_  FEEDS_XML_FILTER_FLAGS filterFlags,
            /* [annotation][in] */ 
            _In_  FEEDS_XML_INCLUDE_FLAGS includeFlags,
            /* [annotation][out] */ 
            _Out_  IStream **pps);
        
        HRESULT ( STDMETHODCALLTYPE *Name )( 
            __RPC__in IXFeed * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszName);
        
        HRESULT ( STDMETHODCALLTYPE *Rename )( 
            __RPC__in IXFeed * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszName);
        
        HRESULT ( STDMETHODCALLTYPE *Url )( 
            __RPC__in IXFeed * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszUrl);
        
        HRESULT ( STDMETHODCALLTYPE *SetUrl )( 
            __RPC__in IXFeed * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszUrl);
        
        HRESULT ( STDMETHODCALLTYPE *LocalId )( 
            __RPC__in IXFeed * This,
            /* [annotation][out] */ 
            _Out_  GUID *pguid);
        
        HRESULT ( STDMETHODCALLTYPE *Path )( 
            __RPC__in IXFeed * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszPath);
        
        HRESULT ( STDMETHODCALLTYPE *Move )( 
            __RPC__in IXFeed * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPath);
        
        HRESULT ( STDMETHODCALLTYPE *Parent )( 
            __RPC__in IXFeed * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppv);
        
        HRESULT ( STDMETHODCALLTYPE *LastWriteTime )( 
            __RPC__in IXFeed * This,
            /* [annotation][out] */ 
            _Out_  SYSTEMTIME *pstLastWriteTime);
        
        HRESULT ( STDMETHODCALLTYPE *Delete )( 
            __RPC__in IXFeed * This);
        
        HRESULT ( STDMETHODCALLTYPE *Download )( 
            __RPC__in IXFeed * This);
        
        HRESULT ( STDMETHODCALLTYPE *AsyncDownload )( 
            __RPC__in IXFeed * This);
        
        HRESULT ( STDMETHODCALLTYPE *CancelAsyncDownload )( 
            __RPC__in IXFeed * This);
        
        HRESULT ( STDMETHODCALLTYPE *SyncSetting )( 
            __RPC__in IXFeed * This,
            /* [annotation][out] */ 
            _Out_  FEEDS_SYNC_SETTING *pfss);
        
        HRESULT ( STDMETHODCALLTYPE *SetSyncSetting )( 
            __RPC__in IXFeed * This,
            /* [annotation][in] */ 
            _In_  FEEDS_SYNC_SETTING fss);
        
        HRESULT ( STDMETHODCALLTYPE *Interval )( 
            __RPC__in IXFeed * This,
            /* [annotation][out] */ 
            _Out_  UINT *puiInterval);
        
        HRESULT ( STDMETHODCALLTYPE *SetInterval )( 
            __RPC__in IXFeed * This,
            /* [annotation][in] */ 
            _In_  UINT uiInterval);
        
        HRESULT ( STDMETHODCALLTYPE *LastDownloadTime )( 
            __RPC__in IXFeed * This,
            /* [annotation][out] */ 
            _Out_  SYSTEMTIME *pstLastDownloadTime);
        
        HRESULT ( STDMETHODCALLTYPE *LocalEnclosurePath )( 
            __RPC__in IXFeed * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszPath);
        
        HRESULT ( STDMETHODCALLTYPE *Items )( 
            __RPC__in IXFeed * This,
            /* [annotation][out] */ 
            _Out_  IXFeedsEnum **ppfe);
        
        HRESULT ( STDMETHODCALLTYPE *GetItem )( 
            __RPC__in IXFeed * This,
            /* [annotation][in] */ 
            _In_  UINT uiId,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppv);
        
        HRESULT ( STDMETHODCALLTYPE *MarkAllItemsRead )( 
            __RPC__in IXFeed * This);
        
        HRESULT ( STDMETHODCALLTYPE *MaxItemCount )( 
            __RPC__in IXFeed * This,
            /* [annotation][out] */ 
            _Out_  UINT *puiMaxItemCount);
        
        HRESULT ( STDMETHODCALLTYPE *SetMaxItemCount )( 
            __RPC__in IXFeed * This,
            /* [annotation][in] */ 
            _In_  UINT uiMaxItemCount);
        
        HRESULT ( STDMETHODCALLTYPE *DownloadEnclosuresAutomatically )( 
            __RPC__in IXFeed * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pbDownloadEnclosuresAutomatically);
        
        HRESULT ( STDMETHODCALLTYPE *SetDownloadEnclosuresAutomatically )( 
            __RPC__in IXFeed * This,
            /* [annotation][in] */ 
            _In_  BOOL bDownloadEnclosuresAutomatically);
        
        HRESULT ( STDMETHODCALLTYPE *DownloadStatus )( 
            __RPC__in IXFeed * This,
            /* [annotation][out] */ 
            _Out_  FEEDS_DOWNLOAD_STATUS *pfds);
        
        HRESULT ( STDMETHODCALLTYPE *LastDownloadError )( 
            __RPC__in IXFeed * This,
            /* [annotation][out] */ 
            _Out_  FEEDS_DOWNLOAD_ERROR *pfde);
        
        HRESULT ( STDMETHODCALLTYPE *Merge )( 
            __RPC__in IXFeed * This,
            /* [annotation][in] */ 
            _In_  IStream *pStream,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszUrl);
        
        HRESULT ( STDMETHODCALLTYPE *DownloadUrl )( 
            __RPC__in IXFeed * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszUrl);
        
        HRESULT ( STDMETHODCALLTYPE *Title )( 
            __RPC__in IXFeed * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszTitle);
        
        HRESULT ( STDMETHODCALLTYPE *Description )( 
            __RPC__in IXFeed * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszDescription);
        
        HRESULT ( STDMETHODCALLTYPE *Link )( 
            __RPC__in IXFeed * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszHomePage);
        
        HRESULT ( STDMETHODCALLTYPE *Image )( 
            __RPC__in IXFeed * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszImageUrl);
        
        HRESULT ( STDMETHODCALLTYPE *LastBuildDate )( 
            __RPC__in IXFeed * This,
            /* [annotation][out] */ 
            _Out_  SYSTEMTIME *pstLastBuildDate);
        
        HRESULT ( STDMETHODCALLTYPE *PubDate )( 
            __RPC__in IXFeed * This,
            /* [annotation][out] */ 
            _Out_  SYSTEMTIME *pstPubDate);
        
        HRESULT ( STDMETHODCALLTYPE *Ttl )( 
            __RPC__in IXFeed * This,
            /* [annotation][out] */ 
            _Out_  UINT *puiTtl);
        
        HRESULT ( STDMETHODCALLTYPE *Language )( 
            __RPC__in IXFeed * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszLanguage);
        
        HRESULT ( STDMETHODCALLTYPE *Copyright )( 
            __RPC__in IXFeed * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszCopyright);
        
        HRESULT ( STDMETHODCALLTYPE *IsList )( 
            __RPC__in IXFeed * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pbIsList);
        
        HRESULT ( STDMETHODCALLTYPE *GetWatcher )( 
            __RPC__in IXFeed * This,
            /* [annotation][in] */ 
            _In_  FEEDS_EVENTS_SCOPE scope,
            /* [annotation][in] */ 
            _In_  FEEDS_EVENTS_MASK mask,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppv);
        
        HRESULT ( STDMETHODCALLTYPE *UnreadItemCount )( 
            __RPC__in IXFeed * This,
            /* [annotation][out] */ 
            _Out_  UINT *puiUnreadItemCount);
        
        HRESULT ( STDMETHODCALLTYPE *ItemCount )( 
            __RPC__in IXFeed * This,
            /* [annotation][out] */ 
            _Out_  UINT *puiItemCount);
        
        END_INTERFACE
    } IXFeedVtbl;

    interface IXFeed
    {
        CONST_VTBL struct IXFeedVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IXFeed_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IXFeed_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IXFeed_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IXFeed_Xml(This,uiItemCount,sortProperty,sortOrder,filterFlags,includeFlags,pps)	\
    ( (This)->lpVtbl -> Xml(This,uiItemCount,sortProperty,sortOrder,filterFlags,includeFlags,pps) ) 

#define IXFeed_Name(This,ppszName)	\
    ( (This)->lpVtbl -> Name(This,ppszName) ) 

#define IXFeed_Rename(This,pszName)	\
    ( (This)->lpVtbl -> Rename(This,pszName) ) 

#define IXFeed_Url(This,ppszUrl)	\
    ( (This)->lpVtbl -> Url(This,ppszUrl) ) 

#define IXFeed_SetUrl(This,pszUrl)	\
    ( (This)->lpVtbl -> SetUrl(This,pszUrl) ) 

#define IXFeed_LocalId(This,pguid)	\
    ( (This)->lpVtbl -> LocalId(This,pguid) ) 

#define IXFeed_Path(This,ppszPath)	\
    ( (This)->lpVtbl -> Path(This,ppszPath) ) 

#define IXFeed_Move(This,pszPath)	\
    ( (This)->lpVtbl -> Move(This,pszPath) ) 

#define IXFeed_Parent(This,riid,ppv)	\
    ( (This)->lpVtbl -> Parent(This,riid,ppv) ) 

#define IXFeed_LastWriteTime(This,pstLastWriteTime)	\
    ( (This)->lpVtbl -> LastWriteTime(This,pstLastWriteTime) ) 

#define IXFeed_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define IXFeed_Download(This)	\
    ( (This)->lpVtbl -> Download(This) ) 

#define IXFeed_AsyncDownload(This)	\
    ( (This)->lpVtbl -> AsyncDownload(This) ) 

#define IXFeed_CancelAsyncDownload(This)	\
    ( (This)->lpVtbl -> CancelAsyncDownload(This) ) 

#define IXFeed_SyncSetting(This,pfss)	\
    ( (This)->lpVtbl -> SyncSetting(This,pfss) ) 

#define IXFeed_SetSyncSetting(This,fss)	\
    ( (This)->lpVtbl -> SetSyncSetting(This,fss) ) 

#define IXFeed_Interval(This,puiInterval)	\
    ( (This)->lpVtbl -> Interval(This,puiInterval) ) 

#define IXFeed_SetInterval(This,uiInterval)	\
    ( (This)->lpVtbl -> SetInterval(This,uiInterval) ) 

#define IXFeed_LastDownloadTime(This,pstLastDownloadTime)	\
    ( (This)->lpVtbl -> LastDownloadTime(This,pstLastDownloadTime) ) 

#define IXFeed_LocalEnclosurePath(This,ppszPath)	\
    ( (This)->lpVtbl -> LocalEnclosurePath(This,ppszPath) ) 

#define IXFeed_Items(This,ppfe)	\
    ( (This)->lpVtbl -> Items(This,ppfe) ) 

#define IXFeed_GetItem(This,uiId,riid,ppv)	\
    ( (This)->lpVtbl -> GetItem(This,uiId,riid,ppv) ) 

#define IXFeed_MarkAllItemsRead(This)	\
    ( (This)->lpVtbl -> MarkAllItemsRead(This) ) 

#define IXFeed_MaxItemCount(This,puiMaxItemCount)	\
    ( (This)->lpVtbl -> MaxItemCount(This,puiMaxItemCount) ) 

#define IXFeed_SetMaxItemCount(This,uiMaxItemCount)	\
    ( (This)->lpVtbl -> SetMaxItemCount(This,uiMaxItemCount) ) 

#define IXFeed_DownloadEnclosuresAutomatically(This,pbDownloadEnclosuresAutomatically)	\
    ( (This)->lpVtbl -> DownloadEnclosuresAutomatically(This,pbDownloadEnclosuresAutomatically) ) 

#define IXFeed_SetDownloadEnclosuresAutomatically(This,bDownloadEnclosuresAutomatically)	\
    ( (This)->lpVtbl -> SetDownloadEnclosuresAutomatically(This,bDownloadEnclosuresAutomatically) ) 

#define IXFeed_DownloadStatus(This,pfds)	\
    ( (This)->lpVtbl -> DownloadStatus(This,pfds) ) 

#define IXFeed_LastDownloadError(This,pfde)	\
    ( (This)->lpVtbl -> LastDownloadError(This,pfde) ) 

#define IXFeed_Merge(This,pStream,pszUrl)	\
    ( (This)->lpVtbl -> Merge(This,pStream,pszUrl) ) 

#define IXFeed_DownloadUrl(This,ppszUrl)	\
    ( (This)->lpVtbl -> DownloadUrl(This,ppszUrl) ) 

#define IXFeed_Title(This,ppszTitle)	\
    ( (This)->lpVtbl -> Title(This,ppszTitle) ) 

#define IXFeed_Description(This,ppszDescription)	\
    ( (This)->lpVtbl -> Description(This,ppszDescription) ) 

#define IXFeed_Link(This,ppszHomePage)	\
    ( (This)->lpVtbl -> Link(This,ppszHomePage) ) 

#define IXFeed_Image(This,ppszImageUrl)	\
    ( (This)->lpVtbl -> Image(This,ppszImageUrl) ) 

#define IXFeed_LastBuildDate(This,pstLastBuildDate)	\
    ( (This)->lpVtbl -> LastBuildDate(This,pstLastBuildDate) ) 

#define IXFeed_PubDate(This,pstPubDate)	\
    ( (This)->lpVtbl -> PubDate(This,pstPubDate) ) 

#define IXFeed_Ttl(This,puiTtl)	\
    ( (This)->lpVtbl -> Ttl(This,puiTtl) ) 

#define IXFeed_Language(This,ppszLanguage)	\
    ( (This)->lpVtbl -> Language(This,ppszLanguage) ) 

#define IXFeed_Copyright(This,ppszCopyright)	\
    ( (This)->lpVtbl -> Copyright(This,ppszCopyright) ) 

#define IXFeed_IsList(This,pbIsList)	\
    ( (This)->lpVtbl -> IsList(This,pbIsList) ) 

#define IXFeed_GetWatcher(This,scope,mask,riid,ppv)	\
    ( (This)->lpVtbl -> GetWatcher(This,scope,mask,riid,ppv) ) 

#define IXFeed_UnreadItemCount(This,puiUnreadItemCount)	\
    ( (This)->lpVtbl -> UnreadItemCount(This,puiUnreadItemCount) ) 

#define IXFeed_ItemCount(This,puiItemCount)	\
    ( (This)->lpVtbl -> ItemCount(This,puiItemCount) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IXFeed_INTERFACE_DEFINED__ */


#ifndef __IXFeed2_INTERFACE_DEFINED__
#define __IXFeed2_INTERFACE_DEFINED__

/* interface IXFeed2 */
/* [object][uuid] */ 


EXTERN_C const IID IID_IXFeed2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("ce528e77-3716-4eb7-956d-f5e37502e12a")
    IXFeed2 : public IXFeed
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetItemByEffectiveId( 
            /* [annotation][in] */ 
            _In_  UINT uiEffectiveId,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppv) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LastItemDownloadTime( 
            /* [annotation][out] */ 
            _Out_  SYSTEMTIME *pstLastItemDownloadTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Username( 
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszUsername) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Password( 
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszPassword) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetCredentials( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszUsername,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPassword) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ClearCredentials( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IXFeed2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IXFeed2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IXFeed2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IXFeed2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *Xml )( 
            __RPC__in IXFeed2 * This,
            /* [annotation][in] */ 
            _In_  UINT uiItemCount,
            /* [annotation][in] */ 
            _In_  FEEDS_XML_SORT_PROPERTY sortProperty,
            /* [annotation][in] */ 
            _In_  FEEDS_XML_SORT_ORDER sortOrder,
            /* [annotation][in] */ 
            _In_  FEEDS_XML_FILTER_FLAGS filterFlags,
            /* [annotation][in] */ 
            _In_  FEEDS_XML_INCLUDE_FLAGS includeFlags,
            /* [annotation][out] */ 
            _Out_  IStream **pps);
        
        HRESULT ( STDMETHODCALLTYPE *Name )( 
            __RPC__in IXFeed2 * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszName);
        
        HRESULT ( STDMETHODCALLTYPE *Rename )( 
            __RPC__in IXFeed2 * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszName);
        
        HRESULT ( STDMETHODCALLTYPE *Url )( 
            __RPC__in IXFeed2 * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszUrl);
        
        HRESULT ( STDMETHODCALLTYPE *SetUrl )( 
            __RPC__in IXFeed2 * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszUrl);
        
        HRESULT ( STDMETHODCALLTYPE *LocalId )( 
            __RPC__in IXFeed2 * This,
            /* [annotation][out] */ 
            _Out_  GUID *pguid);
        
        HRESULT ( STDMETHODCALLTYPE *Path )( 
            __RPC__in IXFeed2 * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszPath);
        
        HRESULT ( STDMETHODCALLTYPE *Move )( 
            __RPC__in IXFeed2 * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPath);
        
        HRESULT ( STDMETHODCALLTYPE *Parent )( 
            __RPC__in IXFeed2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppv);
        
        HRESULT ( STDMETHODCALLTYPE *LastWriteTime )( 
            __RPC__in IXFeed2 * This,
            /* [annotation][out] */ 
            _Out_  SYSTEMTIME *pstLastWriteTime);
        
        HRESULT ( STDMETHODCALLTYPE *Delete )( 
            __RPC__in IXFeed2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *Download )( 
            __RPC__in IXFeed2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *AsyncDownload )( 
            __RPC__in IXFeed2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *CancelAsyncDownload )( 
            __RPC__in IXFeed2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *SyncSetting )( 
            __RPC__in IXFeed2 * This,
            /* [annotation][out] */ 
            _Out_  FEEDS_SYNC_SETTING *pfss);
        
        HRESULT ( STDMETHODCALLTYPE *SetSyncSetting )( 
            __RPC__in IXFeed2 * This,
            /* [annotation][in] */ 
            _In_  FEEDS_SYNC_SETTING fss);
        
        HRESULT ( STDMETHODCALLTYPE *Interval )( 
            __RPC__in IXFeed2 * This,
            /* [annotation][out] */ 
            _Out_  UINT *puiInterval);
        
        HRESULT ( STDMETHODCALLTYPE *SetInterval )( 
            __RPC__in IXFeed2 * This,
            /* [annotation][in] */ 
            _In_  UINT uiInterval);
        
        HRESULT ( STDMETHODCALLTYPE *LastDownloadTime )( 
            __RPC__in IXFeed2 * This,
            /* [annotation][out] */ 
            _Out_  SYSTEMTIME *pstLastDownloadTime);
        
        HRESULT ( STDMETHODCALLTYPE *LocalEnclosurePath )( 
            __RPC__in IXFeed2 * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszPath);
        
        HRESULT ( STDMETHODCALLTYPE *Items )( 
            __RPC__in IXFeed2 * This,
            /* [annotation][out] */ 
            _Out_  IXFeedsEnum **ppfe);
        
        HRESULT ( STDMETHODCALLTYPE *GetItem )( 
            __RPC__in IXFeed2 * This,
            /* [annotation][in] */ 
            _In_  UINT uiId,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppv);
        
        HRESULT ( STDMETHODCALLTYPE *MarkAllItemsRead )( 
            __RPC__in IXFeed2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *MaxItemCount )( 
            __RPC__in IXFeed2 * This,
            /* [annotation][out] */ 
            _Out_  UINT *puiMaxItemCount);
        
        HRESULT ( STDMETHODCALLTYPE *SetMaxItemCount )( 
            __RPC__in IXFeed2 * This,
            /* [annotation][in] */ 
            _In_  UINT uiMaxItemCount);
        
        HRESULT ( STDMETHODCALLTYPE *DownloadEnclosuresAutomatically )( 
            __RPC__in IXFeed2 * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pbDownloadEnclosuresAutomatically);
        
        HRESULT ( STDMETHODCALLTYPE *SetDownloadEnclosuresAutomatically )( 
            __RPC__in IXFeed2 * This,
            /* [annotation][in] */ 
            _In_  BOOL bDownloadEnclosuresAutomatically);
        
        HRESULT ( STDMETHODCALLTYPE *DownloadStatus )( 
            __RPC__in IXFeed2 * This,
            /* [annotation][out] */ 
            _Out_  FEEDS_DOWNLOAD_STATUS *pfds);
        
        HRESULT ( STDMETHODCALLTYPE *LastDownloadError )( 
            __RPC__in IXFeed2 * This,
            /* [annotation][out] */ 
            _Out_  FEEDS_DOWNLOAD_ERROR *pfde);
        
        HRESULT ( STDMETHODCALLTYPE *Merge )( 
            __RPC__in IXFeed2 * This,
            /* [annotation][in] */ 
            _In_  IStream *pStream,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszUrl);
        
        HRESULT ( STDMETHODCALLTYPE *DownloadUrl )( 
            __RPC__in IXFeed2 * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszUrl);
        
        HRESULT ( STDMETHODCALLTYPE *Title )( 
            __RPC__in IXFeed2 * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszTitle);
        
        HRESULT ( STDMETHODCALLTYPE *Description )( 
            __RPC__in IXFeed2 * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszDescription);
        
        HRESULT ( STDMETHODCALLTYPE *Link )( 
            __RPC__in IXFeed2 * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszHomePage);
        
        HRESULT ( STDMETHODCALLTYPE *Image )( 
            __RPC__in IXFeed2 * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszImageUrl);
        
        HRESULT ( STDMETHODCALLTYPE *LastBuildDate )( 
            __RPC__in IXFeed2 * This,
            /* [annotation][out] */ 
            _Out_  SYSTEMTIME *pstLastBuildDate);
        
        HRESULT ( STDMETHODCALLTYPE *PubDate )( 
            __RPC__in IXFeed2 * This,
            /* [annotation][out] */ 
            _Out_  SYSTEMTIME *pstPubDate);
        
        HRESULT ( STDMETHODCALLTYPE *Ttl )( 
            __RPC__in IXFeed2 * This,
            /* [annotation][out] */ 
            _Out_  UINT *puiTtl);
        
        HRESULT ( STDMETHODCALLTYPE *Language )( 
            __RPC__in IXFeed2 * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszLanguage);
        
        HRESULT ( STDMETHODCALLTYPE *Copyright )( 
            __RPC__in IXFeed2 * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszCopyright);
        
        HRESULT ( STDMETHODCALLTYPE *IsList )( 
            __RPC__in IXFeed2 * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pbIsList);
        
        HRESULT ( STDMETHODCALLTYPE *GetWatcher )( 
            __RPC__in IXFeed2 * This,
            /* [annotation][in] */ 
            _In_  FEEDS_EVENTS_SCOPE scope,
            /* [annotation][in] */ 
            _In_  FEEDS_EVENTS_MASK mask,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppv);
        
        HRESULT ( STDMETHODCALLTYPE *UnreadItemCount )( 
            __RPC__in IXFeed2 * This,
            /* [annotation][out] */ 
            _Out_  UINT *puiUnreadItemCount);
        
        HRESULT ( STDMETHODCALLTYPE *ItemCount )( 
            __RPC__in IXFeed2 * This,
            /* [annotation][out] */ 
            _Out_  UINT *puiItemCount);
        
        HRESULT ( STDMETHODCALLTYPE *GetItemByEffectiveId )( 
            __RPC__in IXFeed2 * This,
            /* [annotation][in] */ 
            _In_  UINT uiEffectiveId,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppv);
        
        HRESULT ( STDMETHODCALLTYPE *LastItemDownloadTime )( 
            __RPC__in IXFeed2 * This,
            /* [annotation][out] */ 
            _Out_  SYSTEMTIME *pstLastItemDownloadTime);
        
        HRESULT ( STDMETHODCALLTYPE *Username )( 
            __RPC__in IXFeed2 * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszUsername);
        
        HRESULT ( STDMETHODCALLTYPE *Password )( 
            __RPC__in IXFeed2 * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszPassword);
        
        HRESULT ( STDMETHODCALLTYPE *SetCredentials )( 
            __RPC__in IXFeed2 * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszUsername,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPassword);
        
        HRESULT ( STDMETHODCALLTYPE *ClearCredentials )( 
            __RPC__in IXFeed2 * This);
        
        END_INTERFACE
    } IXFeed2Vtbl;

    interface IXFeed2
    {
        CONST_VTBL struct IXFeed2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IXFeed2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IXFeed2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IXFeed2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IXFeed2_Xml(This,uiItemCount,sortProperty,sortOrder,filterFlags,includeFlags,pps)	\
    ( (This)->lpVtbl -> Xml(This,uiItemCount,sortProperty,sortOrder,filterFlags,includeFlags,pps) ) 

#define IXFeed2_Name(This,ppszName)	\
    ( (This)->lpVtbl -> Name(This,ppszName) ) 

#define IXFeed2_Rename(This,pszName)	\
    ( (This)->lpVtbl -> Rename(This,pszName) ) 

#define IXFeed2_Url(This,ppszUrl)	\
    ( (This)->lpVtbl -> Url(This,ppszUrl) ) 

#define IXFeed2_SetUrl(This,pszUrl)	\
    ( (This)->lpVtbl -> SetUrl(This,pszUrl) ) 

#define IXFeed2_LocalId(This,pguid)	\
    ( (This)->lpVtbl -> LocalId(This,pguid) ) 

#define IXFeed2_Path(This,ppszPath)	\
    ( (This)->lpVtbl -> Path(This,ppszPath) ) 

#define IXFeed2_Move(This,pszPath)	\
    ( (This)->lpVtbl -> Move(This,pszPath) ) 

#define IXFeed2_Parent(This,riid,ppv)	\
    ( (This)->lpVtbl -> Parent(This,riid,ppv) ) 

#define IXFeed2_LastWriteTime(This,pstLastWriteTime)	\
    ( (This)->lpVtbl -> LastWriteTime(This,pstLastWriteTime) ) 

#define IXFeed2_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define IXFeed2_Download(This)	\
    ( (This)->lpVtbl -> Download(This) ) 

#define IXFeed2_AsyncDownload(This)	\
    ( (This)->lpVtbl -> AsyncDownload(This) ) 

#define IXFeed2_CancelAsyncDownload(This)	\
    ( (This)->lpVtbl -> CancelAsyncDownload(This) ) 

#define IXFeed2_SyncSetting(This,pfss)	\
    ( (This)->lpVtbl -> SyncSetting(This,pfss) ) 

#define IXFeed2_SetSyncSetting(This,fss)	\
    ( (This)->lpVtbl -> SetSyncSetting(This,fss) ) 

#define IXFeed2_Interval(This,puiInterval)	\
    ( (This)->lpVtbl -> Interval(This,puiInterval) ) 

#define IXFeed2_SetInterval(This,uiInterval)	\
    ( (This)->lpVtbl -> SetInterval(This,uiInterval) ) 

#define IXFeed2_LastDownloadTime(This,pstLastDownloadTime)	\
    ( (This)->lpVtbl -> LastDownloadTime(This,pstLastDownloadTime) ) 

#define IXFeed2_LocalEnclosurePath(This,ppszPath)	\
    ( (This)->lpVtbl -> LocalEnclosurePath(This,ppszPath) ) 

#define IXFeed2_Items(This,ppfe)	\
    ( (This)->lpVtbl -> Items(This,ppfe) ) 

#define IXFeed2_GetItem(This,uiId,riid,ppv)	\
    ( (This)->lpVtbl -> GetItem(This,uiId,riid,ppv) ) 

#define IXFeed2_MarkAllItemsRead(This)	\
    ( (This)->lpVtbl -> MarkAllItemsRead(This) ) 

#define IXFeed2_MaxItemCount(This,puiMaxItemCount)	\
    ( (This)->lpVtbl -> MaxItemCount(This,puiMaxItemCount) ) 

#define IXFeed2_SetMaxItemCount(This,uiMaxItemCount)	\
    ( (This)->lpVtbl -> SetMaxItemCount(This,uiMaxItemCount) ) 

#define IXFeed2_DownloadEnclosuresAutomatically(This,pbDownloadEnclosuresAutomatically)	\
    ( (This)->lpVtbl -> DownloadEnclosuresAutomatically(This,pbDownloadEnclosuresAutomatically) ) 

#define IXFeed2_SetDownloadEnclosuresAutomatically(This,bDownloadEnclosuresAutomatically)	\
    ( (This)->lpVtbl -> SetDownloadEnclosuresAutomatically(This,bDownloadEnclosuresAutomatically) ) 

#define IXFeed2_DownloadStatus(This,pfds)	\
    ( (This)->lpVtbl -> DownloadStatus(This,pfds) ) 

#define IXFeed2_LastDownloadError(This,pfde)	\
    ( (This)->lpVtbl -> LastDownloadError(This,pfde) ) 

#define IXFeed2_Merge(This,pStream,pszUrl)	\
    ( (This)->lpVtbl -> Merge(This,pStream,pszUrl) ) 

#define IXFeed2_DownloadUrl(This,ppszUrl)	\
    ( (This)->lpVtbl -> DownloadUrl(This,ppszUrl) ) 

#define IXFeed2_Title(This,ppszTitle)	\
    ( (This)->lpVtbl -> Title(This,ppszTitle) ) 

#define IXFeed2_Description(This,ppszDescription)	\
    ( (This)->lpVtbl -> Description(This,ppszDescription) ) 

#define IXFeed2_Link(This,ppszHomePage)	\
    ( (This)->lpVtbl -> Link(This,ppszHomePage) ) 

#define IXFeed2_Image(This,ppszImageUrl)	\
    ( (This)->lpVtbl -> Image(This,ppszImageUrl) ) 

#define IXFeed2_LastBuildDate(This,pstLastBuildDate)	\
    ( (This)->lpVtbl -> LastBuildDate(This,pstLastBuildDate) ) 

#define IXFeed2_PubDate(This,pstPubDate)	\
    ( (This)->lpVtbl -> PubDate(This,pstPubDate) ) 

#define IXFeed2_Ttl(This,puiTtl)	\
    ( (This)->lpVtbl -> Ttl(This,puiTtl) ) 

#define IXFeed2_Language(This,ppszLanguage)	\
    ( (This)->lpVtbl -> Language(This,ppszLanguage) ) 

#define IXFeed2_Copyright(This,ppszCopyright)	\
    ( (This)->lpVtbl -> Copyright(This,ppszCopyright) ) 

#define IXFeed2_IsList(This,pbIsList)	\
    ( (This)->lpVtbl -> IsList(This,pbIsList) ) 

#define IXFeed2_GetWatcher(This,scope,mask,riid,ppv)	\
    ( (This)->lpVtbl -> GetWatcher(This,scope,mask,riid,ppv) ) 

#define IXFeed2_UnreadItemCount(This,puiUnreadItemCount)	\
    ( (This)->lpVtbl -> UnreadItemCount(This,puiUnreadItemCount) ) 

#define IXFeed2_ItemCount(This,puiItemCount)	\
    ( (This)->lpVtbl -> ItemCount(This,puiItemCount) ) 


#define IXFeed2_GetItemByEffectiveId(This,uiEffectiveId,riid,ppv)	\
    ( (This)->lpVtbl -> GetItemByEffectiveId(This,uiEffectiveId,riid,ppv) ) 

#define IXFeed2_LastItemDownloadTime(This,pstLastItemDownloadTime)	\
    ( (This)->lpVtbl -> LastItemDownloadTime(This,pstLastItemDownloadTime) ) 

#define IXFeed2_Username(This,ppszUsername)	\
    ( (This)->lpVtbl -> Username(This,ppszUsername) ) 

#define IXFeed2_Password(This,ppszPassword)	\
    ( (This)->lpVtbl -> Password(This,ppszPassword) ) 

#define IXFeed2_SetCredentials(This,pszUsername,pszPassword)	\
    ( (This)->lpVtbl -> SetCredentials(This,pszUsername,pszPassword) ) 

#define IXFeed2_ClearCredentials(This)	\
    ( (This)->lpVtbl -> ClearCredentials(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IXFeed2_INTERFACE_DEFINED__ */


#ifndef __IXFeedEvents_INTERFACE_DEFINED__
#define __IXFeedEvents_INTERFACE_DEFINED__

/* interface IXFeedEvents */
/* [object][uuid] */ 


EXTERN_C const IID IID_IXFeedEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1630852e-1263-465b-98e5-fe60ffec4ac2")
    IXFeedEvents : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Error( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FeedDeleted( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FeedRenamed( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPath,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszOldPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FeedUrlChanged( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FeedMoved( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPath,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszOldPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FeedDownloading( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FeedDownloadCompleted( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPath,
            /* [annotation][in] */ 
            _In_  FEEDS_DOWNLOAD_ERROR fde) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FeedItemCountChanged( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPath,
            /* [annotation][in] */ 
            _In_  FEICF feicfFlags) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IXFeedEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IXFeedEvents * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IXFeedEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IXFeedEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *Error )( 
            __RPC__in IXFeedEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *FeedDeleted )( 
            __RPC__in IXFeedEvents * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPath);
        
        HRESULT ( STDMETHODCALLTYPE *FeedRenamed )( 
            __RPC__in IXFeedEvents * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPath,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszOldPath);
        
        HRESULT ( STDMETHODCALLTYPE *FeedUrlChanged )( 
            __RPC__in IXFeedEvents * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPath);
        
        HRESULT ( STDMETHODCALLTYPE *FeedMoved )( 
            __RPC__in IXFeedEvents * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPath,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszOldPath);
        
        HRESULT ( STDMETHODCALLTYPE *FeedDownloading )( 
            __RPC__in IXFeedEvents * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPath);
        
        HRESULT ( STDMETHODCALLTYPE *FeedDownloadCompleted )( 
            __RPC__in IXFeedEvents * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPath,
            /* [annotation][in] */ 
            _In_  FEEDS_DOWNLOAD_ERROR fde);
        
        HRESULT ( STDMETHODCALLTYPE *FeedItemCountChanged )( 
            __RPC__in IXFeedEvents * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPath,
            /* [annotation][in] */ 
            _In_  FEICF feicfFlags);
        
        END_INTERFACE
    } IXFeedEventsVtbl;

    interface IXFeedEvents
    {
        CONST_VTBL struct IXFeedEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IXFeedEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IXFeedEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IXFeedEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IXFeedEvents_Error(This)	\
    ( (This)->lpVtbl -> Error(This) ) 

#define IXFeedEvents_FeedDeleted(This,pszPath)	\
    ( (This)->lpVtbl -> FeedDeleted(This,pszPath) ) 

#define IXFeedEvents_FeedRenamed(This,pszPath,pszOldPath)	\
    ( (This)->lpVtbl -> FeedRenamed(This,pszPath,pszOldPath) ) 

#define IXFeedEvents_FeedUrlChanged(This,pszPath)	\
    ( (This)->lpVtbl -> FeedUrlChanged(This,pszPath) ) 

#define IXFeedEvents_FeedMoved(This,pszPath,pszOldPath)	\
    ( (This)->lpVtbl -> FeedMoved(This,pszPath,pszOldPath) ) 

#define IXFeedEvents_FeedDownloading(This,pszPath)	\
    ( (This)->lpVtbl -> FeedDownloading(This,pszPath) ) 

#define IXFeedEvents_FeedDownloadCompleted(This,pszPath,fde)	\
    ( (This)->lpVtbl -> FeedDownloadCompleted(This,pszPath,fde) ) 

#define IXFeedEvents_FeedItemCountChanged(This,pszPath,feicfFlags)	\
    ( (This)->lpVtbl -> FeedItemCountChanged(This,pszPath,feicfFlags) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IXFeedEvents_INTERFACE_DEFINED__ */


#ifndef __IXFeedItem_INTERFACE_DEFINED__
#define __IXFeedItem_INTERFACE_DEFINED__

/* interface IXFeedItem */
/* [object][uuid] */ 


EXTERN_C const IID IID_IXFeedItem;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("e757b2f5-e73e-434e-a1bf-2bd7c3e60fcb")
    IXFeedItem : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Xml( 
            /* [annotation][in] */ 
            _In_  FEEDS_XML_INCLUDE_FLAGS fxif,
            /* [annotation][out] */ 
            _Out_  IStream **pps) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Title( 
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszTitle) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Link( 
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszUrl) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Guid( 
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszGuid) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Description( 
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszDescription) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PubDate( 
            /* [annotation][out] */ 
            _Out_  SYSTEMTIME *pstPubDate) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Comments( 
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszUrl) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Author( 
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszAuthor) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Enclosure( 
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppv) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsRead( 
            /* [annotation][out] */ 
            _Out_  BOOL *pbIsRead) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetIsRead( 
            /* [annotation][in] */ 
            _In_  BOOL bIsRead) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LocalId( 
            /* [annotation][out] */ 
            _Out_  UINT *puiId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Parent( 
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppv) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Delete( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DownloadUrl( 
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszUrl) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LastDownloadTime( 
            /* [annotation][out] */ 
            _Out_  SYSTEMTIME *pstLastDownloadTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Modified( 
            /* [annotation][out] */ 
            _Out_  SYSTEMTIME *pstModifiedTime) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IXFeedItemVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IXFeedItem * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IXFeedItem * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IXFeedItem * This);
        
        HRESULT ( STDMETHODCALLTYPE *Xml )( 
            __RPC__in IXFeedItem * This,
            /* [annotation][in] */ 
            _In_  FEEDS_XML_INCLUDE_FLAGS fxif,
            /* [annotation][out] */ 
            _Out_  IStream **pps);
        
        HRESULT ( STDMETHODCALLTYPE *Title )( 
            __RPC__in IXFeedItem * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszTitle);
        
        HRESULT ( STDMETHODCALLTYPE *Link )( 
            __RPC__in IXFeedItem * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszUrl);
        
        HRESULT ( STDMETHODCALLTYPE *Guid )( 
            __RPC__in IXFeedItem * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszGuid);
        
        HRESULT ( STDMETHODCALLTYPE *Description )( 
            __RPC__in IXFeedItem * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszDescription);
        
        HRESULT ( STDMETHODCALLTYPE *PubDate )( 
            __RPC__in IXFeedItem * This,
            /* [annotation][out] */ 
            _Out_  SYSTEMTIME *pstPubDate);
        
        HRESULT ( STDMETHODCALLTYPE *Comments )( 
            __RPC__in IXFeedItem * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszUrl);
        
        HRESULT ( STDMETHODCALLTYPE *Author )( 
            __RPC__in IXFeedItem * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszAuthor);
        
        HRESULT ( STDMETHODCALLTYPE *Enclosure )( 
            __RPC__in IXFeedItem * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppv);
        
        HRESULT ( STDMETHODCALLTYPE *IsRead )( 
            __RPC__in IXFeedItem * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pbIsRead);
        
        HRESULT ( STDMETHODCALLTYPE *SetIsRead )( 
            __RPC__in IXFeedItem * This,
            /* [annotation][in] */ 
            _In_  BOOL bIsRead);
        
        HRESULT ( STDMETHODCALLTYPE *LocalId )( 
            __RPC__in IXFeedItem * This,
            /* [annotation][out] */ 
            _Out_  UINT *puiId);
        
        HRESULT ( STDMETHODCALLTYPE *Parent )( 
            __RPC__in IXFeedItem * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppv);
        
        HRESULT ( STDMETHODCALLTYPE *Delete )( 
            __RPC__in IXFeedItem * This);
        
        HRESULT ( STDMETHODCALLTYPE *DownloadUrl )( 
            __RPC__in IXFeedItem * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszUrl);
        
        HRESULT ( STDMETHODCALLTYPE *LastDownloadTime )( 
            __RPC__in IXFeedItem * This,
            /* [annotation][out] */ 
            _Out_  SYSTEMTIME *pstLastDownloadTime);
        
        HRESULT ( STDMETHODCALLTYPE *Modified )( 
            __RPC__in IXFeedItem * This,
            /* [annotation][out] */ 
            _Out_  SYSTEMTIME *pstModifiedTime);
        
        END_INTERFACE
    } IXFeedItemVtbl;

    interface IXFeedItem
    {
        CONST_VTBL struct IXFeedItemVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IXFeedItem_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IXFeedItem_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IXFeedItem_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IXFeedItem_Xml(This,fxif,pps)	\
    ( (This)->lpVtbl -> Xml(This,fxif,pps) ) 

#define IXFeedItem_Title(This,ppszTitle)	\
    ( (This)->lpVtbl -> Title(This,ppszTitle) ) 

#define IXFeedItem_Link(This,ppszUrl)	\
    ( (This)->lpVtbl -> Link(This,ppszUrl) ) 

#define IXFeedItem_Guid(This,ppszGuid)	\
    ( (This)->lpVtbl -> Guid(This,ppszGuid) ) 

#define IXFeedItem_Description(This,ppszDescription)	\
    ( (This)->lpVtbl -> Description(This,ppszDescription) ) 

#define IXFeedItem_PubDate(This,pstPubDate)	\
    ( (This)->lpVtbl -> PubDate(This,pstPubDate) ) 

#define IXFeedItem_Comments(This,ppszUrl)	\
    ( (This)->lpVtbl -> Comments(This,ppszUrl) ) 

#define IXFeedItem_Author(This,ppszAuthor)	\
    ( (This)->lpVtbl -> Author(This,ppszAuthor) ) 

#define IXFeedItem_Enclosure(This,riid,ppv)	\
    ( (This)->lpVtbl -> Enclosure(This,riid,ppv) ) 

#define IXFeedItem_IsRead(This,pbIsRead)	\
    ( (This)->lpVtbl -> IsRead(This,pbIsRead) ) 

#define IXFeedItem_SetIsRead(This,bIsRead)	\
    ( (This)->lpVtbl -> SetIsRead(This,bIsRead) ) 

#define IXFeedItem_LocalId(This,puiId)	\
    ( (This)->lpVtbl -> LocalId(This,puiId) ) 

#define IXFeedItem_Parent(This,riid,ppv)	\
    ( (This)->lpVtbl -> Parent(This,riid,ppv) ) 

#define IXFeedItem_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define IXFeedItem_DownloadUrl(This,ppszUrl)	\
    ( (This)->lpVtbl -> DownloadUrl(This,ppszUrl) ) 

#define IXFeedItem_LastDownloadTime(This,pstLastDownloadTime)	\
    ( (This)->lpVtbl -> LastDownloadTime(This,pstLastDownloadTime) ) 

#define IXFeedItem_Modified(This,pstModifiedTime)	\
    ( (This)->lpVtbl -> Modified(This,pstModifiedTime) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IXFeedItem_INTERFACE_DEFINED__ */


#ifndef __IXFeedItem2_INTERFACE_DEFINED__
#define __IXFeedItem2_INTERFACE_DEFINED__

/* interface IXFeedItem2 */
/* [object][uuid] */ 


EXTERN_C const IID IID_IXFeedItem2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6cda2dc7-9013-4522-9970-2a9dd9ead5a3")
    IXFeedItem2 : public IXFeedItem
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE EffectiveId( 
            /* [annotation][out] */ 
            _Out_  UINT *puiEffectiveId) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IXFeedItem2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IXFeedItem2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IXFeedItem2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IXFeedItem2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *Xml )( 
            __RPC__in IXFeedItem2 * This,
            /* [annotation][in] */ 
            _In_  FEEDS_XML_INCLUDE_FLAGS fxif,
            /* [annotation][out] */ 
            _Out_  IStream **pps);
        
        HRESULT ( STDMETHODCALLTYPE *Title )( 
            __RPC__in IXFeedItem2 * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszTitle);
        
        HRESULT ( STDMETHODCALLTYPE *Link )( 
            __RPC__in IXFeedItem2 * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszUrl);
        
        HRESULT ( STDMETHODCALLTYPE *Guid )( 
            __RPC__in IXFeedItem2 * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszGuid);
        
        HRESULT ( STDMETHODCALLTYPE *Description )( 
            __RPC__in IXFeedItem2 * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszDescription);
        
        HRESULT ( STDMETHODCALLTYPE *PubDate )( 
            __RPC__in IXFeedItem2 * This,
            /* [annotation][out] */ 
            _Out_  SYSTEMTIME *pstPubDate);
        
        HRESULT ( STDMETHODCALLTYPE *Comments )( 
            __RPC__in IXFeedItem2 * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszUrl);
        
        HRESULT ( STDMETHODCALLTYPE *Author )( 
            __RPC__in IXFeedItem2 * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszAuthor);
        
        HRESULT ( STDMETHODCALLTYPE *Enclosure )( 
            __RPC__in IXFeedItem2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppv);
        
        HRESULT ( STDMETHODCALLTYPE *IsRead )( 
            __RPC__in IXFeedItem2 * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pbIsRead);
        
        HRESULT ( STDMETHODCALLTYPE *SetIsRead )( 
            __RPC__in IXFeedItem2 * This,
            /* [annotation][in] */ 
            _In_  BOOL bIsRead);
        
        HRESULT ( STDMETHODCALLTYPE *LocalId )( 
            __RPC__in IXFeedItem2 * This,
            /* [annotation][out] */ 
            _Out_  UINT *puiId);
        
        HRESULT ( STDMETHODCALLTYPE *Parent )( 
            __RPC__in IXFeedItem2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppv);
        
        HRESULT ( STDMETHODCALLTYPE *Delete )( 
            __RPC__in IXFeedItem2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *DownloadUrl )( 
            __RPC__in IXFeedItem2 * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszUrl);
        
        HRESULT ( STDMETHODCALLTYPE *LastDownloadTime )( 
            __RPC__in IXFeedItem2 * This,
            /* [annotation][out] */ 
            _Out_  SYSTEMTIME *pstLastDownloadTime);
        
        HRESULT ( STDMETHODCALLTYPE *Modified )( 
            __RPC__in IXFeedItem2 * This,
            /* [annotation][out] */ 
            _Out_  SYSTEMTIME *pstModifiedTime);
        
        HRESULT ( STDMETHODCALLTYPE *EffectiveId )( 
            __RPC__in IXFeedItem2 * This,
            /* [annotation][out] */ 
            _Out_  UINT *puiEffectiveId);
        
        END_INTERFACE
    } IXFeedItem2Vtbl;

    interface IXFeedItem2
    {
        CONST_VTBL struct IXFeedItem2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IXFeedItem2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IXFeedItem2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IXFeedItem2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IXFeedItem2_Xml(This,fxif,pps)	\
    ( (This)->lpVtbl -> Xml(This,fxif,pps) ) 

#define IXFeedItem2_Title(This,ppszTitle)	\
    ( (This)->lpVtbl -> Title(This,ppszTitle) ) 

#define IXFeedItem2_Link(This,ppszUrl)	\
    ( (This)->lpVtbl -> Link(This,ppszUrl) ) 

#define IXFeedItem2_Guid(This,ppszGuid)	\
    ( (This)->lpVtbl -> Guid(This,ppszGuid) ) 

#define IXFeedItem2_Description(This,ppszDescription)	\
    ( (This)->lpVtbl -> Description(This,ppszDescription) ) 

#define IXFeedItem2_PubDate(This,pstPubDate)	\
    ( (This)->lpVtbl -> PubDate(This,pstPubDate) ) 

#define IXFeedItem2_Comments(This,ppszUrl)	\
    ( (This)->lpVtbl -> Comments(This,ppszUrl) ) 

#define IXFeedItem2_Author(This,ppszAuthor)	\
    ( (This)->lpVtbl -> Author(This,ppszAuthor) ) 

#define IXFeedItem2_Enclosure(This,riid,ppv)	\
    ( (This)->lpVtbl -> Enclosure(This,riid,ppv) ) 

#define IXFeedItem2_IsRead(This,pbIsRead)	\
    ( (This)->lpVtbl -> IsRead(This,pbIsRead) ) 

#define IXFeedItem2_SetIsRead(This,bIsRead)	\
    ( (This)->lpVtbl -> SetIsRead(This,bIsRead) ) 

#define IXFeedItem2_LocalId(This,puiId)	\
    ( (This)->lpVtbl -> LocalId(This,puiId) ) 

#define IXFeedItem2_Parent(This,riid,ppv)	\
    ( (This)->lpVtbl -> Parent(This,riid,ppv) ) 

#define IXFeedItem2_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define IXFeedItem2_DownloadUrl(This,ppszUrl)	\
    ( (This)->lpVtbl -> DownloadUrl(This,ppszUrl) ) 

#define IXFeedItem2_LastDownloadTime(This,pstLastDownloadTime)	\
    ( (This)->lpVtbl -> LastDownloadTime(This,pstLastDownloadTime) ) 

#define IXFeedItem2_Modified(This,pstModifiedTime)	\
    ( (This)->lpVtbl -> Modified(This,pstModifiedTime) ) 


#define IXFeedItem2_EffectiveId(This,puiEffectiveId)	\
    ( (This)->lpVtbl -> EffectiveId(This,puiEffectiveId) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IXFeedItem2_INTERFACE_DEFINED__ */


#ifndef __IXFeedEnclosure_INTERFACE_DEFINED__
#define __IXFeedEnclosure_INTERFACE_DEFINED__

/* interface IXFeedEnclosure */
/* [object][uuid] */ 


EXTERN_C const IID IID_IXFeedEnclosure;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BFBFB953-644F-4792-B69C-DFACA4CBF89A")
    IXFeedEnclosure : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Url( 
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszUrl) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Type( 
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszMimeType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Length( 
            /* [annotation][out] */ 
            _Out_  UINT *puiLength) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AsyncDownload( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CancelAsyncDownload( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DownloadStatus( 
            /* [annotation][out] */ 
            _Out_  FEEDS_DOWNLOAD_STATUS *pfds) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LastDownloadError( 
            /* [annotation][out] */ 
            _Out_  FEEDS_DOWNLOAD_ERROR *pfde) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LocalPath( 
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Parent( 
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppv) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DownloadUrl( 
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszUrl) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DownloadMimeType( 
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszMimeType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveFile( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetFile( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszDownloadUrl,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszDownloadFilePath,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszDownloadMimeType,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszEnclosureFilename) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IXFeedEnclosureVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IXFeedEnclosure * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IXFeedEnclosure * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IXFeedEnclosure * This);
        
        HRESULT ( STDMETHODCALLTYPE *Url )( 
            __RPC__in IXFeedEnclosure * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszUrl);
        
        HRESULT ( STDMETHODCALLTYPE *Type )( 
            __RPC__in IXFeedEnclosure * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszMimeType);
        
        HRESULT ( STDMETHODCALLTYPE *Length )( 
            __RPC__in IXFeedEnclosure * This,
            /* [annotation][out] */ 
            _Out_  UINT *puiLength);
        
        HRESULT ( STDMETHODCALLTYPE *AsyncDownload )( 
            __RPC__in IXFeedEnclosure * This);
        
        HRESULT ( STDMETHODCALLTYPE *CancelAsyncDownload )( 
            __RPC__in IXFeedEnclosure * This);
        
        HRESULT ( STDMETHODCALLTYPE *DownloadStatus )( 
            __RPC__in IXFeedEnclosure * This,
            /* [annotation][out] */ 
            _Out_  FEEDS_DOWNLOAD_STATUS *pfds);
        
        HRESULT ( STDMETHODCALLTYPE *LastDownloadError )( 
            __RPC__in IXFeedEnclosure * This,
            /* [annotation][out] */ 
            _Out_  FEEDS_DOWNLOAD_ERROR *pfde);
        
        HRESULT ( STDMETHODCALLTYPE *LocalPath )( 
            __RPC__in IXFeedEnclosure * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszPath);
        
        HRESULT ( STDMETHODCALLTYPE *Parent )( 
            __RPC__in IXFeedEnclosure * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppv);
        
        HRESULT ( STDMETHODCALLTYPE *DownloadUrl )( 
            __RPC__in IXFeedEnclosure * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszUrl);
        
        HRESULT ( STDMETHODCALLTYPE *DownloadMimeType )( 
            __RPC__in IXFeedEnclosure * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszMimeType);
        
        HRESULT ( STDMETHODCALLTYPE *RemoveFile )( 
            __RPC__in IXFeedEnclosure * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetFile )( 
            __RPC__in IXFeedEnclosure * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszDownloadUrl,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszDownloadFilePath,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszDownloadMimeType,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszEnclosureFilename);
        
        END_INTERFACE
    } IXFeedEnclosureVtbl;

    interface IXFeedEnclosure
    {
        CONST_VTBL struct IXFeedEnclosureVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IXFeedEnclosure_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IXFeedEnclosure_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IXFeedEnclosure_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IXFeedEnclosure_Url(This,ppszUrl)	\
    ( (This)->lpVtbl -> Url(This,ppszUrl) ) 

#define IXFeedEnclosure_Type(This,ppszMimeType)	\
    ( (This)->lpVtbl -> Type(This,ppszMimeType) ) 

#define IXFeedEnclosure_Length(This,puiLength)	\
    ( (This)->lpVtbl -> Length(This,puiLength) ) 

#define IXFeedEnclosure_AsyncDownload(This)	\
    ( (This)->lpVtbl -> AsyncDownload(This) ) 

#define IXFeedEnclosure_CancelAsyncDownload(This)	\
    ( (This)->lpVtbl -> CancelAsyncDownload(This) ) 

#define IXFeedEnclosure_DownloadStatus(This,pfds)	\
    ( (This)->lpVtbl -> DownloadStatus(This,pfds) ) 

#define IXFeedEnclosure_LastDownloadError(This,pfde)	\
    ( (This)->lpVtbl -> LastDownloadError(This,pfde) ) 

#define IXFeedEnclosure_LocalPath(This,ppszPath)	\
    ( (This)->lpVtbl -> LocalPath(This,ppszPath) ) 

#define IXFeedEnclosure_Parent(This,riid,ppv)	\
    ( (This)->lpVtbl -> Parent(This,riid,ppv) ) 

#define IXFeedEnclosure_DownloadUrl(This,ppszUrl)	\
    ( (This)->lpVtbl -> DownloadUrl(This,ppszUrl) ) 

#define IXFeedEnclosure_DownloadMimeType(This,ppszMimeType)	\
    ( (This)->lpVtbl -> DownloadMimeType(This,ppszMimeType) ) 

#define IXFeedEnclosure_RemoveFile(This)	\
    ( (This)->lpVtbl -> RemoveFile(This) ) 

#define IXFeedEnclosure_SetFile(This,pszDownloadUrl,pszDownloadFilePath,pszDownloadMimeType,pszEnclosureFilename)	\
    ( (This)->lpVtbl -> SetFile(This,pszDownloadUrl,pszDownloadFilePath,pszDownloadMimeType,pszEnclosureFilename) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IXFeedEnclosure_INTERFACE_DEFINED__ */



#ifndef __Feeds_LIBRARY_DEFINED__
#define __Feeds_LIBRARY_DEFINED__

/* library Feeds */
/* [custom][version][lcid][helpstring][uuid] */ 

#pragma warning(push)
#pragma warning(disable:4001) 
#pragma once
#pragma warning(push)
#pragma warning(disable:4001) 
#pragma once
#pragma warning(pop)
#pragma warning(pop)
#pragma region Desktop Family
#pragma endregion

EXTERN_C const IID LIBID_Feeds;

#ifndef __IFeedsManager_INTERFACE_DEFINED__
#define __IFeedsManager_INTERFACE_DEFINED__

/* interface IFeedsManager */
/* [object][oleautomation][dual][uuid] */ 


EXTERN_C const IID IID_IFeedsManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("a74029cc-1f1a-4906-88f0-810638d86591")
    IFeedsManager : public IDispatch
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_RootFolder( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IDispatch **disp) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsSubscribed( 
            /* [annotation][in] */ 
            _In_  BSTR feedUrl,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *subscribed) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ExistsFeed( 
            /* [annotation][in] */ 
            _In_  BSTR feedPath,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *exists) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetFeed( 
            /* [annotation][in] */ 
            _In_  BSTR feedPath,
            /* [annotation][retval][out] */ 
            _Out_retval_  IDispatch **disp) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetFeedByUrl( 
            /* [annotation][in] */ 
            _In_  BSTR feedUrl,
            /* [annotation][retval][out] */ 
            _Out_retval_  IDispatch **disp) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ExistsFolder( 
            /* [annotation][in] */ 
            _In_  BSTR folderPath,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *exists) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetFolder( 
            /* [annotation][in] */ 
            _In_  BSTR folderPath,
            /* [annotation][retval][out] */ 
            _Out_retval_  IDispatch **disp) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteFeed( 
            /* [annotation][in] */ 
            _In_  BSTR feedPath) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteFolder( 
            /* [annotation][in] */ 
            _In_  BSTR folderPath) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE BackgroundSync( 
            /* [annotation][in] */ 
            _In_  FEEDS_BACKGROUNDSYNC_ACTION action) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_BackgroundSyncStatus( 
            /* [annotation][retval][out] */ 
            _Out_retval_  FEEDS_BACKGROUNDSYNC_STATUS *status) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DefaultInterval( 
            /* [annotation][retval][out] */ 
            _Out_retval_  LONG *minutes) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_DefaultInterval( 
            /* [annotation][in] */ 
            _In_  LONG minutes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AsyncSyncAll( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Normalize( 
            /* [annotation][in] */ 
            _In_  BSTR feedXmlIn,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *feedXmlOut) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ItemCountLimit( 
            /* [annotation][retval][out] */ 
            _Out_retval_  LONG *itemCountLimit) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IFeedsManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IFeedsManager * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IFeedsManager * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IFeedsManager * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IFeedsManager * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IFeedsManager * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IFeedsManager * This,
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
            IFeedsManager * This,
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
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_RootFolder )( 
            __RPC__in IFeedsManager * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IDispatch **disp);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsSubscribed )( 
            __RPC__in IFeedsManager * This,
            /* [annotation][in] */ 
            _In_  BSTR feedUrl,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *subscribed);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ExistsFeed )( 
            __RPC__in IFeedsManager * This,
            /* [annotation][in] */ 
            _In_  BSTR feedPath,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *exists);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetFeed )( 
            __RPC__in IFeedsManager * This,
            /* [annotation][in] */ 
            _In_  BSTR feedPath,
            /* [annotation][retval][out] */ 
            _Out_retval_  IDispatch **disp);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetFeedByUrl )( 
            __RPC__in IFeedsManager * This,
            /* [annotation][in] */ 
            _In_  BSTR feedUrl,
            /* [annotation][retval][out] */ 
            _Out_retval_  IDispatch **disp);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ExistsFolder )( 
            __RPC__in IFeedsManager * This,
            /* [annotation][in] */ 
            _In_  BSTR folderPath,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *exists);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetFolder )( 
            __RPC__in IFeedsManager * This,
            /* [annotation][in] */ 
            _In_  BSTR folderPath,
            /* [annotation][retval][out] */ 
            _Out_retval_  IDispatch **disp);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeleteFeed )( 
            __RPC__in IFeedsManager * This,
            /* [annotation][in] */ 
            _In_  BSTR feedPath);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeleteFolder )( 
            __RPC__in IFeedsManager * This,
            /* [annotation][in] */ 
            _In_  BSTR folderPath);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *BackgroundSync )( 
            __RPC__in IFeedsManager * This,
            /* [annotation][in] */ 
            _In_  FEEDS_BACKGROUNDSYNC_ACTION action);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_BackgroundSyncStatus )( 
            __RPC__in IFeedsManager * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  FEEDS_BACKGROUNDSYNC_STATUS *status);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultInterval )( 
            __RPC__in IFeedsManager * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  LONG *minutes);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultInterval )( 
            __RPC__in IFeedsManager * This,
            /* [annotation][in] */ 
            _In_  LONG minutes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AsyncSyncAll )( 
            __RPC__in IFeedsManager * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Normalize )( 
            __RPC__in IFeedsManager * This,
            /* [annotation][in] */ 
            _In_  BSTR feedXmlIn,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *feedXmlOut);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ItemCountLimit )( 
            __RPC__in IFeedsManager * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  LONG *itemCountLimit);
        
        END_INTERFACE
    } IFeedsManagerVtbl;

    interface IFeedsManager
    {
        CONST_VTBL struct IFeedsManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFeedsManager_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFeedsManager_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFeedsManager_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFeedsManager_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFeedsManager_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFeedsManager_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFeedsManager_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IFeedsManager_get_RootFolder(This,disp)	\
    ( (This)->lpVtbl -> get_RootFolder(This,disp) ) 

#define IFeedsManager_IsSubscribed(This,feedUrl,subscribed)	\
    ( (This)->lpVtbl -> IsSubscribed(This,feedUrl,subscribed) ) 

#define IFeedsManager_ExistsFeed(This,feedPath,exists)	\
    ( (This)->lpVtbl -> ExistsFeed(This,feedPath,exists) ) 

#define IFeedsManager_GetFeed(This,feedPath,disp)	\
    ( (This)->lpVtbl -> GetFeed(This,feedPath,disp) ) 

#define IFeedsManager_GetFeedByUrl(This,feedUrl,disp)	\
    ( (This)->lpVtbl -> GetFeedByUrl(This,feedUrl,disp) ) 

#define IFeedsManager_ExistsFolder(This,folderPath,exists)	\
    ( (This)->lpVtbl -> ExistsFolder(This,folderPath,exists) ) 

#define IFeedsManager_GetFolder(This,folderPath,disp)	\
    ( (This)->lpVtbl -> GetFolder(This,folderPath,disp) ) 

#define IFeedsManager_DeleteFeed(This,feedPath)	\
    ( (This)->lpVtbl -> DeleteFeed(This,feedPath) ) 

#define IFeedsManager_DeleteFolder(This,folderPath)	\
    ( (This)->lpVtbl -> DeleteFolder(This,folderPath) ) 

#define IFeedsManager_BackgroundSync(This,action)	\
    ( (This)->lpVtbl -> BackgroundSync(This,action) ) 

#define IFeedsManager_get_BackgroundSyncStatus(This,status)	\
    ( (This)->lpVtbl -> get_BackgroundSyncStatus(This,status) ) 

#define IFeedsManager_get_DefaultInterval(This,minutes)	\
    ( (This)->lpVtbl -> get_DefaultInterval(This,minutes) ) 

#define IFeedsManager_put_DefaultInterval(This,minutes)	\
    ( (This)->lpVtbl -> put_DefaultInterval(This,minutes) ) 

#define IFeedsManager_AsyncSyncAll(This)	\
    ( (This)->lpVtbl -> AsyncSyncAll(This) ) 

#define IFeedsManager_Normalize(This,feedXmlIn,feedXmlOut)	\
    ( (This)->lpVtbl -> Normalize(This,feedXmlIn,feedXmlOut) ) 

#define IFeedsManager_get_ItemCountLimit(This,itemCountLimit)	\
    ( (This)->lpVtbl -> get_ItemCountLimit(This,itemCountLimit) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFeedsManager_INTERFACE_DEFINED__ */


#ifndef __IFeedsEnum_INTERFACE_DEFINED__
#define __IFeedsEnum_INTERFACE_DEFINED__

/* interface IFeedsEnum */
/* [object][oleautomation][dual][uuid] */ 


EXTERN_C const IID IID_IFeedsEnum;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("e3cd0028-2eed-4c60-8fae-a3225309a836")
    IFeedsEnum : public IDispatch
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [annotation][retval][out] */ 
            _Out_retval_  LONG *count) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Item( 
            /* [annotation][in] */ 
            _In_  LONG index,
            /* [annotation][retval][out] */ 
            _Out_retval_  IDispatch **disp) = 0;
        
        virtual /* [restricted][hidden][propget][id] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IEnumVARIANT **enumVar) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IFeedsEnumVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IFeedsEnum * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IFeedsEnum * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IFeedsEnum * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IFeedsEnum * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IFeedsEnum * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IFeedsEnum * This,
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
            IFeedsEnum * This,
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
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            __RPC__in IFeedsEnum * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  LONG *count);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Item )( 
            __RPC__in IFeedsEnum * This,
            /* [annotation][in] */ 
            _In_  LONG index,
            /* [annotation][retval][out] */ 
            _Out_retval_  IDispatch **disp);
        
        /* [restricted][hidden][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            __RPC__in IFeedsEnum * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IEnumVARIANT **enumVar);
        
        END_INTERFACE
    } IFeedsEnumVtbl;

    interface IFeedsEnum
    {
        CONST_VTBL struct IFeedsEnumVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFeedsEnum_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFeedsEnum_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFeedsEnum_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFeedsEnum_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFeedsEnum_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFeedsEnum_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFeedsEnum_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IFeedsEnum_get_Count(This,count)	\
    ( (This)->lpVtbl -> get_Count(This,count) ) 

#define IFeedsEnum_Item(This,index,disp)	\
    ( (This)->lpVtbl -> Item(This,index,disp) ) 

#define IFeedsEnum_get__NewEnum(This,enumVar)	\
    ( (This)->lpVtbl -> get__NewEnum(This,enumVar) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFeedsEnum_INTERFACE_DEFINED__ */


#ifndef __IFeedFolder_INTERFACE_DEFINED__
#define __IFeedFolder_INTERFACE_DEFINED__

/* interface IFeedFolder */
/* [object][oleautomation][dual][uuid] */ 


EXTERN_C const IID IID_IFeedFolder;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("81f04ad1-4194-4d7d-86d6-11813cec163c")
    IFeedFolder : public IDispatch
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Feeds( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IDispatch **disp) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Subfolders( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IDispatch **disp) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateFeed( 
            /* [annotation][in] */ 
            _In_  BSTR feedName,
            /* [annotation][in] */ 
            _In_  BSTR feedUrl,
            /* [annotation][retval][out] */ 
            _Out_retval_  IDispatch **disp) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateSubfolder( 
            /* [annotation][in] */ 
            _In_  BSTR folderName,
            /* [annotation][retval][out] */ 
            _Out_retval_  IDispatch **disp) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ExistsFeed( 
            /* [annotation][in] */ 
            _In_  BSTR feedName,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *exists) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetFeed( 
            /* [annotation][in] */ 
            _In_  BSTR feedName,
            /* [annotation][retval][out] */ 
            _Out_retval_  IDispatch **disp) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ExistsSubfolder( 
            /* [annotation][in] */ 
            _In_  BSTR folderName,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *exists) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetSubfolder( 
            /* [annotation][in] */ 
            _In_  BSTR folderName,
            /* [annotation][retval][out] */ 
            _Out_retval_  IDispatch **disp) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Delete( void) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *folderName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Rename( 
            /* [annotation][in] */ 
            _In_  BSTR folderName) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Path( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *folderPath) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Move( 
            /* [annotation][in] */ 
            _In_  BSTR newParentPath) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Parent( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IDispatch **disp) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_IsRoot( 
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *isRoot) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_TotalUnreadItemCount( 
            /* [annotation][retval][out] */ 
            _Out_retval_  LONG *count) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_TotalItemCount( 
            /* [annotation][retval][out] */ 
            _Out_retval_  LONG *count) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetWatcher( 
            /* [annotation][in] */ 
            _In_  FEEDS_EVENTS_SCOPE scope,
            /* [annotation][in] */ 
            _In_  FEEDS_EVENTS_MASK mask,
            /* [annotation][retval][out] */ 
            _Out_retval_  IDispatch **disp) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IFeedFolderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IFeedFolder * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IFeedFolder * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IFeedFolder * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IFeedFolder * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IFeedFolder * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IFeedFolder * This,
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
            IFeedFolder * This,
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
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Feeds )( 
            __RPC__in IFeedFolder * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IDispatch **disp);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Subfolders )( 
            __RPC__in IFeedFolder * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IDispatch **disp);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateFeed )( 
            __RPC__in IFeedFolder * This,
            /* [annotation][in] */ 
            _In_  BSTR feedName,
            /* [annotation][in] */ 
            _In_  BSTR feedUrl,
            /* [annotation][retval][out] */ 
            _Out_retval_  IDispatch **disp);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateSubfolder )( 
            __RPC__in IFeedFolder * This,
            /* [annotation][in] */ 
            _In_  BSTR folderName,
            /* [annotation][retval][out] */ 
            _Out_retval_  IDispatch **disp);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ExistsFeed )( 
            __RPC__in IFeedFolder * This,
            /* [annotation][in] */ 
            _In_  BSTR feedName,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *exists);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetFeed )( 
            __RPC__in IFeedFolder * This,
            /* [annotation][in] */ 
            _In_  BSTR feedName,
            /* [annotation][retval][out] */ 
            _Out_retval_  IDispatch **disp);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ExistsSubfolder )( 
            __RPC__in IFeedFolder * This,
            /* [annotation][in] */ 
            _In_  BSTR folderName,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *exists);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetSubfolder )( 
            __RPC__in IFeedFolder * This,
            /* [annotation][in] */ 
            _In_  BSTR folderName,
            /* [annotation][retval][out] */ 
            _Out_retval_  IDispatch **disp);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            __RPC__in IFeedFolder * This);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            __RPC__in IFeedFolder * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *folderName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Rename )( 
            __RPC__in IFeedFolder * This,
            /* [annotation][in] */ 
            _In_  BSTR folderName);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Path )( 
            __RPC__in IFeedFolder * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *folderPath);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Move )( 
            __RPC__in IFeedFolder * This,
            /* [annotation][in] */ 
            _In_  BSTR newParentPath);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Parent )( 
            __RPC__in IFeedFolder * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IDispatch **disp);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_IsRoot )( 
            __RPC__in IFeedFolder * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *isRoot);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_TotalUnreadItemCount )( 
            __RPC__in IFeedFolder * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  LONG *count);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_TotalItemCount )( 
            __RPC__in IFeedFolder * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  LONG *count);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetWatcher )( 
            __RPC__in IFeedFolder * This,
            /* [annotation][in] */ 
            _In_  FEEDS_EVENTS_SCOPE scope,
            /* [annotation][in] */ 
            _In_  FEEDS_EVENTS_MASK mask,
            /* [annotation][retval][out] */ 
            _Out_retval_  IDispatch **disp);
        
        END_INTERFACE
    } IFeedFolderVtbl;

    interface IFeedFolder
    {
        CONST_VTBL struct IFeedFolderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFeedFolder_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFeedFolder_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFeedFolder_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFeedFolder_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFeedFolder_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFeedFolder_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFeedFolder_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IFeedFolder_get_Feeds(This,disp)	\
    ( (This)->lpVtbl -> get_Feeds(This,disp) ) 

#define IFeedFolder_get_Subfolders(This,disp)	\
    ( (This)->lpVtbl -> get_Subfolders(This,disp) ) 

#define IFeedFolder_CreateFeed(This,feedName,feedUrl,disp)	\
    ( (This)->lpVtbl -> CreateFeed(This,feedName,feedUrl,disp) ) 

#define IFeedFolder_CreateSubfolder(This,folderName,disp)	\
    ( (This)->lpVtbl -> CreateSubfolder(This,folderName,disp) ) 

#define IFeedFolder_ExistsFeed(This,feedName,exists)	\
    ( (This)->lpVtbl -> ExistsFeed(This,feedName,exists) ) 

#define IFeedFolder_GetFeed(This,feedName,disp)	\
    ( (This)->lpVtbl -> GetFeed(This,feedName,disp) ) 

#define IFeedFolder_ExistsSubfolder(This,folderName,exists)	\
    ( (This)->lpVtbl -> ExistsSubfolder(This,folderName,exists) ) 

#define IFeedFolder_GetSubfolder(This,folderName,disp)	\
    ( (This)->lpVtbl -> GetSubfolder(This,folderName,disp) ) 

#define IFeedFolder_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define IFeedFolder_get_Name(This,folderName)	\
    ( (This)->lpVtbl -> get_Name(This,folderName) ) 

#define IFeedFolder_Rename(This,folderName)	\
    ( (This)->lpVtbl -> Rename(This,folderName) ) 

#define IFeedFolder_get_Path(This,folderPath)	\
    ( (This)->lpVtbl -> get_Path(This,folderPath) ) 

#define IFeedFolder_Move(This,newParentPath)	\
    ( (This)->lpVtbl -> Move(This,newParentPath) ) 

#define IFeedFolder_get_Parent(This,disp)	\
    ( (This)->lpVtbl -> get_Parent(This,disp) ) 

#define IFeedFolder_get_IsRoot(This,isRoot)	\
    ( (This)->lpVtbl -> get_IsRoot(This,isRoot) ) 

#define IFeedFolder_get_TotalUnreadItemCount(This,count)	\
    ( (This)->lpVtbl -> get_TotalUnreadItemCount(This,count) ) 

#define IFeedFolder_get_TotalItemCount(This,count)	\
    ( (This)->lpVtbl -> get_TotalItemCount(This,count) ) 

#define IFeedFolder_GetWatcher(This,scope,mask,disp)	\
    ( (This)->lpVtbl -> GetWatcher(This,scope,mask,disp) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFeedFolder_INTERFACE_DEFINED__ */


#ifndef __IFeedFolderEvents_INTERFACE_DEFINED__
#define __IFeedFolderEvents_INTERFACE_DEFINED__

/* interface IFeedFolderEvents */
/* [object][oleautomation][dual][uuid] */ 


EXTERN_C const IID IID_IFeedFolderEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("20a59fa6-a844-4630-9e98-175f70b4d55b")
    IFeedFolderEvents : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Error( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FolderAdded( 
            /* [annotation][in] */ 
            _In_  const BSTR path) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FolderDeleted( 
            /* [annotation][in] */ 
            _In_  const BSTR path) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FolderRenamed( 
            /* [annotation][in] */ 
            _In_  const BSTR path,
            /* [annotation][in] */ 
            _In_  const BSTR oldPath) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FolderMovedFrom( 
            /* [annotation][in] */ 
            _In_  const BSTR path,
            /* [annotation][in] */ 
            _In_  const BSTR oldPath) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FolderMovedTo( 
            /* [annotation][in] */ 
            _In_  const BSTR path,
            /* [annotation][in] */ 
            _In_  const BSTR oldPath) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FolderItemCountChanged( 
            /* [annotation][in] */ 
            _In_  const BSTR path,
            /* [annotation][in] */ 
            _In_  LONG itemCountType) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FeedAdded( 
            /* [annotation][in] */ 
            _In_  const BSTR path) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FeedDeleted( 
            /* [annotation][in] */ 
            _In_  const BSTR path) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FeedRenamed( 
            /* [annotation][in] */ 
            _In_  const BSTR path,
            /* [annotation][in] */ 
            _In_  const BSTR oldPath) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FeedUrlChanged( 
            /* [annotation][in] */ 
            _In_  const BSTR path) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FeedMovedFrom( 
            /* [annotation][in] */ 
            _In_  const BSTR path,
            /* [annotation][in] */ 
            _In_  const BSTR oldPath) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FeedMovedTo( 
            /* [annotation][in] */ 
            _In_  const BSTR path,
            /* [annotation][in] */ 
            _In_  const BSTR oldPath) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FeedDownloading( 
            /* [annotation][in] */ 
            _In_  const BSTR path) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FeedDownloadCompleted( 
            /* [annotation][in] */ 
            _In_  const BSTR path,
            /* [annotation][in] */ 
            _In_  FEEDS_DOWNLOAD_ERROR error) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FeedItemCountChanged( 
            /* [annotation][in] */ 
            _In_  const BSTR path,
            /* [annotation][in] */ 
            _In_  LONG itemCountType) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IFeedFolderEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IFeedFolderEvents * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IFeedFolderEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IFeedFolderEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IFeedFolderEvents * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IFeedFolderEvents * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IFeedFolderEvents * This,
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
            IFeedFolderEvents * This,
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
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Error )( 
            __RPC__in IFeedFolderEvents * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FolderAdded )( 
            __RPC__in IFeedFolderEvents * This,
            /* [annotation][in] */ 
            _In_  const BSTR path);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FolderDeleted )( 
            __RPC__in IFeedFolderEvents * This,
            /* [annotation][in] */ 
            _In_  const BSTR path);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FolderRenamed )( 
            __RPC__in IFeedFolderEvents * This,
            /* [annotation][in] */ 
            _In_  const BSTR path,
            /* [annotation][in] */ 
            _In_  const BSTR oldPath);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FolderMovedFrom )( 
            __RPC__in IFeedFolderEvents * This,
            /* [annotation][in] */ 
            _In_  const BSTR path,
            /* [annotation][in] */ 
            _In_  const BSTR oldPath);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FolderMovedTo )( 
            __RPC__in IFeedFolderEvents * This,
            /* [annotation][in] */ 
            _In_  const BSTR path,
            /* [annotation][in] */ 
            _In_  const BSTR oldPath);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FolderItemCountChanged )( 
            __RPC__in IFeedFolderEvents * This,
            /* [annotation][in] */ 
            _In_  const BSTR path,
            /* [annotation][in] */ 
            _In_  LONG itemCountType);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FeedAdded )( 
            __RPC__in IFeedFolderEvents * This,
            /* [annotation][in] */ 
            _In_  const BSTR path);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FeedDeleted )( 
            __RPC__in IFeedFolderEvents * This,
            /* [annotation][in] */ 
            _In_  const BSTR path);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FeedRenamed )( 
            __RPC__in IFeedFolderEvents * This,
            /* [annotation][in] */ 
            _In_  const BSTR path,
            /* [annotation][in] */ 
            _In_  const BSTR oldPath);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FeedUrlChanged )( 
            __RPC__in IFeedFolderEvents * This,
            /* [annotation][in] */ 
            _In_  const BSTR path);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FeedMovedFrom )( 
            __RPC__in IFeedFolderEvents * This,
            /* [annotation][in] */ 
            _In_  const BSTR path,
            /* [annotation][in] */ 
            _In_  const BSTR oldPath);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FeedMovedTo )( 
            __RPC__in IFeedFolderEvents * This,
            /* [annotation][in] */ 
            _In_  const BSTR path,
            /* [annotation][in] */ 
            _In_  const BSTR oldPath);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FeedDownloading )( 
            __RPC__in IFeedFolderEvents * This,
            /* [annotation][in] */ 
            _In_  const BSTR path);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FeedDownloadCompleted )( 
            __RPC__in IFeedFolderEvents * This,
            /* [annotation][in] */ 
            _In_  const BSTR path,
            /* [annotation][in] */ 
            _In_  FEEDS_DOWNLOAD_ERROR error);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FeedItemCountChanged )( 
            __RPC__in IFeedFolderEvents * This,
            /* [annotation][in] */ 
            _In_  const BSTR path,
            /* [annotation][in] */ 
            _In_  LONG itemCountType);
        
        END_INTERFACE
    } IFeedFolderEventsVtbl;

    interface IFeedFolderEvents
    {
        CONST_VTBL struct IFeedFolderEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFeedFolderEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFeedFolderEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFeedFolderEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFeedFolderEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFeedFolderEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFeedFolderEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFeedFolderEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IFeedFolderEvents_Error(This)	\
    ( (This)->lpVtbl -> Error(This) ) 

#define IFeedFolderEvents_FolderAdded(This,path)	\
    ( (This)->lpVtbl -> FolderAdded(This,path) ) 

#define IFeedFolderEvents_FolderDeleted(This,path)	\
    ( (This)->lpVtbl -> FolderDeleted(This,path) ) 

#define IFeedFolderEvents_FolderRenamed(This,path,oldPath)	\
    ( (This)->lpVtbl -> FolderRenamed(This,path,oldPath) ) 

#define IFeedFolderEvents_FolderMovedFrom(This,path,oldPath)	\
    ( (This)->lpVtbl -> FolderMovedFrom(This,path,oldPath) ) 

#define IFeedFolderEvents_FolderMovedTo(This,path,oldPath)	\
    ( (This)->lpVtbl -> FolderMovedTo(This,path,oldPath) ) 

#define IFeedFolderEvents_FolderItemCountChanged(This,path,itemCountType)	\
    ( (This)->lpVtbl -> FolderItemCountChanged(This,path,itemCountType) ) 

#define IFeedFolderEvents_FeedAdded(This,path)	\
    ( (This)->lpVtbl -> FeedAdded(This,path) ) 

#define IFeedFolderEvents_FeedDeleted(This,path)	\
    ( (This)->lpVtbl -> FeedDeleted(This,path) ) 

#define IFeedFolderEvents_FeedRenamed(This,path,oldPath)	\
    ( (This)->lpVtbl -> FeedRenamed(This,path,oldPath) ) 

#define IFeedFolderEvents_FeedUrlChanged(This,path)	\
    ( (This)->lpVtbl -> FeedUrlChanged(This,path) ) 

#define IFeedFolderEvents_FeedMovedFrom(This,path,oldPath)	\
    ( (This)->lpVtbl -> FeedMovedFrom(This,path,oldPath) ) 

#define IFeedFolderEvents_FeedMovedTo(This,path,oldPath)	\
    ( (This)->lpVtbl -> FeedMovedTo(This,path,oldPath) ) 

#define IFeedFolderEvents_FeedDownloading(This,path)	\
    ( (This)->lpVtbl -> FeedDownloading(This,path) ) 

#define IFeedFolderEvents_FeedDownloadCompleted(This,path,error)	\
    ( (This)->lpVtbl -> FeedDownloadCompleted(This,path,error) ) 

#define IFeedFolderEvents_FeedItemCountChanged(This,path,itemCountType)	\
    ( (This)->lpVtbl -> FeedItemCountChanged(This,path,itemCountType) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFeedFolderEvents_INTERFACE_DEFINED__ */


#ifndef __IFeed_INTERFACE_DEFINED__
#define __IFeed_INTERFACE_DEFINED__

/* interface IFeed */
/* [object][oleautomation][dual][uuid] */ 


EXTERN_C const IID IID_IFeed;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("f7f915d8-2ede-42bc-98e7-a5d05063a757")
    IFeed : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Xml( 
            /* [annotation][in] */ 
            _In_  LONG count,
            /* [annotation][in] */ 
            _In_  FEEDS_XML_SORT_PROPERTY sortProperty,
            /* [annotation][in] */ 
            _In_  FEEDS_XML_SORT_ORDER sortOrder,
            /* [annotation][in] */ 
            _In_  FEEDS_XML_FILTER_FLAGS filterFlags,
            /* [annotation][in] */ 
            _In_  FEEDS_XML_INCLUDE_FLAGS includeFlags,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *xml) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *name) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Rename( 
            /* [annotation][in] */ 
            _In_  BSTR name) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Url( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *feedUrl) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Url( 
            /* [annotation][in] */ 
            _In_  BSTR feedUrl) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_LocalId( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *feedGuid) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Path( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *path) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Move( 
            /* [annotation][in] */ 
            _In_  BSTR newParentPath) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Parent( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IDispatch **disp) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_LastWriteTime( 
            /* [annotation][retval][out] */ 
            _Out_retval_  DATE *lastWrite) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Delete( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Download( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AsyncDownload( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CancelAsyncDownload( void) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_SyncSetting( 
            /* [annotation][retval][out] */ 
            _Out_retval_  FEEDS_SYNC_SETTING *syncSetting) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_SyncSetting( 
            /* [annotation][in] */ 
            _In_  FEEDS_SYNC_SETTING syncSetting) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Interval( 
            /* [annotation][retval][out] */ 
            _Out_retval_  LONG *minutes) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Interval( 
            /* [annotation][in] */ 
            _In_  LONG minutes) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_LastDownloadTime( 
            /* [annotation][retval][out] */ 
            _Out_retval_  DATE *lastDownload) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_LocalEnclosurePath( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Items( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IDispatch **disp) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetItem( 
            /* [annotation][in] */ 
            _In_  LONG itemId,
            /* [annotation][retval][out] */ 
            _Out_retval_  IDispatch **disp) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Title( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *title) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Description( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *description) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Link( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *homePage) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Image( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *imageUrl) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_LastBuildDate( 
            /* [annotation][retval][out] */ 
            _Out_retval_  DATE *lastBuildDate) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_PubDate( 
            /* [annotation][retval][out] */ 
            _Out_retval_  DATE *lastPopulateDate) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Ttl( 
            /* [annotation][retval][out] */ 
            _Out_retval_  LONG *ttl) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Language( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *language) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Copyright( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *copyright) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_MaxItemCount( 
            /* [annotation][retval][out] */ 
            _Out_retval_  LONG *count) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_MaxItemCount( 
            /* [annotation][in] */ 
            _In_  LONG count) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DownloadEnclosuresAutomatically( 
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *downloadEnclosuresAutomatically) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_DownloadEnclosuresAutomatically( 
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL downloadEnclosuresAutomatically) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DownloadStatus( 
            /* [annotation][retval][out] */ 
            _Out_retval_  FEEDS_DOWNLOAD_STATUS *status) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_LastDownloadError( 
            /* [annotation][retval][out] */ 
            _Out_retval_  FEEDS_DOWNLOAD_ERROR *error) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Merge( 
            /* [annotation][in] */ 
            _In_  BSTR feedXml,
            /* [annotation][in] */ 
            _In_  BSTR feedUrl) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DownloadUrl( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *feedUrl) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_IsList( 
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *isList) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MarkAllItemsRead( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetWatcher( 
            /* [annotation][in] */ 
            _In_  FEEDS_EVENTS_SCOPE scope,
            /* [annotation][in] */ 
            _In_  FEEDS_EVENTS_MASK mask,
            /* [annotation][retval][out] */ 
            _Out_retval_  IDispatch **disp) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_UnreadItemCount( 
            /* [annotation][retval][out] */ 
            _Out_retval_  LONG *count) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ItemCount( 
            /* [annotation][retval][out] */ 
            _Out_retval_  LONG *count) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IFeedVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IFeed * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IFeed * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IFeed * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IFeed * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IFeed * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IFeed * This,
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
            IFeed * This,
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
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Xml )( 
            __RPC__in IFeed * This,
            /* [annotation][in] */ 
            _In_  LONG count,
            /* [annotation][in] */ 
            _In_  FEEDS_XML_SORT_PROPERTY sortProperty,
            /* [annotation][in] */ 
            _In_  FEEDS_XML_SORT_ORDER sortOrder,
            /* [annotation][in] */ 
            _In_  FEEDS_XML_FILTER_FLAGS filterFlags,
            /* [annotation][in] */ 
            _In_  FEEDS_XML_INCLUDE_FLAGS includeFlags,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *xml);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            __RPC__in IFeed * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *name);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Rename )( 
            __RPC__in IFeed * This,
            /* [annotation][in] */ 
            _In_  BSTR name);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Url )( 
            __RPC__in IFeed * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *feedUrl);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Url )( 
            __RPC__in IFeed * This,
            /* [annotation][in] */ 
            _In_  BSTR feedUrl);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_LocalId )( 
            __RPC__in IFeed * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *feedGuid);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Path )( 
            __RPC__in IFeed * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *path);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Move )( 
            __RPC__in IFeed * This,
            /* [annotation][in] */ 
            _In_  BSTR newParentPath);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Parent )( 
            __RPC__in IFeed * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IDispatch **disp);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_LastWriteTime )( 
            __RPC__in IFeed * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  DATE *lastWrite);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            __RPC__in IFeed * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Download )( 
            __RPC__in IFeed * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AsyncDownload )( 
            __RPC__in IFeed * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CancelAsyncDownload )( 
            __RPC__in IFeed * This);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_SyncSetting )( 
            __RPC__in IFeed * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  FEEDS_SYNC_SETTING *syncSetting);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_SyncSetting )( 
            __RPC__in IFeed * This,
            /* [annotation][in] */ 
            _In_  FEEDS_SYNC_SETTING syncSetting);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Interval )( 
            __RPC__in IFeed * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  LONG *minutes);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Interval )( 
            __RPC__in IFeed * This,
            /* [annotation][in] */ 
            _In_  LONG minutes);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_LastDownloadTime )( 
            __RPC__in IFeed * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  DATE *lastDownload);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_LocalEnclosurePath )( 
            __RPC__in IFeed * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Items )( 
            __RPC__in IFeed * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IDispatch **disp);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetItem )( 
            __RPC__in IFeed * This,
            /* [annotation][in] */ 
            _In_  LONG itemId,
            /* [annotation][retval][out] */ 
            _Out_retval_  IDispatch **disp);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Title )( 
            __RPC__in IFeed * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *title);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Description )( 
            __RPC__in IFeed * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *description);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Link )( 
            __RPC__in IFeed * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *homePage);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Image )( 
            __RPC__in IFeed * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *imageUrl);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_LastBuildDate )( 
            __RPC__in IFeed * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  DATE *lastBuildDate);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_PubDate )( 
            __RPC__in IFeed * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  DATE *lastPopulateDate);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Ttl )( 
            __RPC__in IFeed * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  LONG *ttl);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Language )( 
            __RPC__in IFeed * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *language);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Copyright )( 
            __RPC__in IFeed * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *copyright);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_MaxItemCount )( 
            __RPC__in IFeed * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  LONG *count);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_MaxItemCount )( 
            __RPC__in IFeed * This,
            /* [annotation][in] */ 
            _In_  LONG count);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DownloadEnclosuresAutomatically )( 
            __RPC__in IFeed * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *downloadEnclosuresAutomatically);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_DownloadEnclosuresAutomatically )( 
            __RPC__in IFeed * This,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL downloadEnclosuresAutomatically);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DownloadStatus )( 
            __RPC__in IFeed * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  FEEDS_DOWNLOAD_STATUS *status);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_LastDownloadError )( 
            __RPC__in IFeed * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  FEEDS_DOWNLOAD_ERROR *error);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Merge )( 
            __RPC__in IFeed * This,
            /* [annotation][in] */ 
            _In_  BSTR feedXml,
            /* [annotation][in] */ 
            _In_  BSTR feedUrl);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DownloadUrl )( 
            __RPC__in IFeed * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *feedUrl);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_IsList )( 
            __RPC__in IFeed * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *isList);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MarkAllItemsRead )( 
            __RPC__in IFeed * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetWatcher )( 
            __RPC__in IFeed * This,
            /* [annotation][in] */ 
            _In_  FEEDS_EVENTS_SCOPE scope,
            /* [annotation][in] */ 
            _In_  FEEDS_EVENTS_MASK mask,
            /* [annotation][retval][out] */ 
            _Out_retval_  IDispatch **disp);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_UnreadItemCount )( 
            __RPC__in IFeed * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  LONG *count);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ItemCount )( 
            __RPC__in IFeed * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  LONG *count);
        
        END_INTERFACE
    } IFeedVtbl;

    interface IFeed
    {
        CONST_VTBL struct IFeedVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFeed_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFeed_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFeed_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFeed_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFeed_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFeed_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFeed_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IFeed_Xml(This,count,sortProperty,sortOrder,filterFlags,includeFlags,xml)	\
    ( (This)->lpVtbl -> Xml(This,count,sortProperty,sortOrder,filterFlags,includeFlags,xml) ) 

#define IFeed_get_Name(This,name)	\
    ( (This)->lpVtbl -> get_Name(This,name) ) 

#define IFeed_Rename(This,name)	\
    ( (This)->lpVtbl -> Rename(This,name) ) 

#define IFeed_get_Url(This,feedUrl)	\
    ( (This)->lpVtbl -> get_Url(This,feedUrl) ) 

#define IFeed_put_Url(This,feedUrl)	\
    ( (This)->lpVtbl -> put_Url(This,feedUrl) ) 

#define IFeed_get_LocalId(This,feedGuid)	\
    ( (This)->lpVtbl -> get_LocalId(This,feedGuid) ) 

#define IFeed_get_Path(This,path)	\
    ( (This)->lpVtbl -> get_Path(This,path) ) 

#define IFeed_Move(This,newParentPath)	\
    ( (This)->lpVtbl -> Move(This,newParentPath) ) 

#define IFeed_get_Parent(This,disp)	\
    ( (This)->lpVtbl -> get_Parent(This,disp) ) 

#define IFeed_get_LastWriteTime(This,lastWrite)	\
    ( (This)->lpVtbl -> get_LastWriteTime(This,lastWrite) ) 

#define IFeed_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define IFeed_Download(This)	\
    ( (This)->lpVtbl -> Download(This) ) 

#define IFeed_AsyncDownload(This)	\
    ( (This)->lpVtbl -> AsyncDownload(This) ) 

#define IFeed_CancelAsyncDownload(This)	\
    ( (This)->lpVtbl -> CancelAsyncDownload(This) ) 

#define IFeed_get_SyncSetting(This,syncSetting)	\
    ( (This)->lpVtbl -> get_SyncSetting(This,syncSetting) ) 

#define IFeed_put_SyncSetting(This,syncSetting)	\
    ( (This)->lpVtbl -> put_SyncSetting(This,syncSetting) ) 

#define IFeed_get_Interval(This,minutes)	\
    ( (This)->lpVtbl -> get_Interval(This,minutes) ) 

#define IFeed_put_Interval(This,minutes)	\
    ( (This)->lpVtbl -> put_Interval(This,minutes) ) 

#define IFeed_get_LastDownloadTime(This,lastDownload)	\
    ( (This)->lpVtbl -> get_LastDownloadTime(This,lastDownload) ) 

#define IFeed_get_LocalEnclosurePath(This,path)	\
    ( (This)->lpVtbl -> get_LocalEnclosurePath(This,path) ) 

#define IFeed_get_Items(This,disp)	\
    ( (This)->lpVtbl -> get_Items(This,disp) ) 

#define IFeed_GetItem(This,itemId,disp)	\
    ( (This)->lpVtbl -> GetItem(This,itemId,disp) ) 

#define IFeed_get_Title(This,title)	\
    ( (This)->lpVtbl -> get_Title(This,title) ) 

#define IFeed_get_Description(This,description)	\
    ( (This)->lpVtbl -> get_Description(This,description) ) 

#define IFeed_get_Link(This,homePage)	\
    ( (This)->lpVtbl -> get_Link(This,homePage) ) 

#define IFeed_get_Image(This,imageUrl)	\
    ( (This)->lpVtbl -> get_Image(This,imageUrl) ) 

#define IFeed_get_LastBuildDate(This,lastBuildDate)	\
    ( (This)->lpVtbl -> get_LastBuildDate(This,lastBuildDate) ) 

#define IFeed_get_PubDate(This,lastPopulateDate)	\
    ( (This)->lpVtbl -> get_PubDate(This,lastPopulateDate) ) 

#define IFeed_get_Ttl(This,ttl)	\
    ( (This)->lpVtbl -> get_Ttl(This,ttl) ) 

#define IFeed_get_Language(This,language)	\
    ( (This)->lpVtbl -> get_Language(This,language) ) 

#define IFeed_get_Copyright(This,copyright)	\
    ( (This)->lpVtbl -> get_Copyright(This,copyright) ) 

#define IFeed_get_MaxItemCount(This,count)	\
    ( (This)->lpVtbl -> get_MaxItemCount(This,count) ) 

#define IFeed_put_MaxItemCount(This,count)	\
    ( (This)->lpVtbl -> put_MaxItemCount(This,count) ) 

#define IFeed_get_DownloadEnclosuresAutomatically(This,downloadEnclosuresAutomatically)	\
    ( (This)->lpVtbl -> get_DownloadEnclosuresAutomatically(This,downloadEnclosuresAutomatically) ) 

#define IFeed_put_DownloadEnclosuresAutomatically(This,downloadEnclosuresAutomatically)	\
    ( (This)->lpVtbl -> put_DownloadEnclosuresAutomatically(This,downloadEnclosuresAutomatically) ) 

#define IFeed_get_DownloadStatus(This,status)	\
    ( (This)->lpVtbl -> get_DownloadStatus(This,status) ) 

#define IFeed_get_LastDownloadError(This,error)	\
    ( (This)->lpVtbl -> get_LastDownloadError(This,error) ) 

#define IFeed_Merge(This,feedXml,feedUrl)	\
    ( (This)->lpVtbl -> Merge(This,feedXml,feedUrl) ) 

#define IFeed_get_DownloadUrl(This,feedUrl)	\
    ( (This)->lpVtbl -> get_DownloadUrl(This,feedUrl) ) 

#define IFeed_get_IsList(This,isList)	\
    ( (This)->lpVtbl -> get_IsList(This,isList) ) 

#define IFeed_MarkAllItemsRead(This)	\
    ( (This)->lpVtbl -> MarkAllItemsRead(This) ) 

#define IFeed_GetWatcher(This,scope,mask,disp)	\
    ( (This)->lpVtbl -> GetWatcher(This,scope,mask,disp) ) 

#define IFeed_get_UnreadItemCount(This,count)	\
    ( (This)->lpVtbl -> get_UnreadItemCount(This,count) ) 

#define IFeed_get_ItemCount(This,count)	\
    ( (This)->lpVtbl -> get_ItemCount(This,count) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFeed_INTERFACE_DEFINED__ */


#ifndef __IFeed2_INTERFACE_DEFINED__
#define __IFeed2_INTERFACE_DEFINED__

/* interface IFeed2 */
/* [object][oleautomation][dual][uuid] */ 


EXTERN_C const IID IID_IFeed2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("33f2ea09-1398-4ab9-b6a4-f94b49d0a42e")
    IFeed2 : public IFeed
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetItemByEffectiveId( 
            /* [annotation][in] */ 
            _In_  LONG itemEffectiveId,
            /* [annotation][retval][out] */ 
            _Out_retval_  IDispatch **disp) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_LastItemDownloadTime( 
            /* [annotation][retval][out] */ 
            _Out_retval_  DATE *lastItemDownloadTime) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Username( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *username) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Password( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *password) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetCredentials( 
            /* [annotation][in] */ 
            _In_  BSTR username,
            /* [annotation][in] */ 
            _In_  BSTR password) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ClearCredentials( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IFeed2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IFeed2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IFeed2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IFeed2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IFeed2 * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IFeed2 * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IFeed2 * This,
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
            IFeed2 * This,
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
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Xml )( 
            __RPC__in IFeed2 * This,
            /* [annotation][in] */ 
            _In_  LONG count,
            /* [annotation][in] */ 
            _In_  FEEDS_XML_SORT_PROPERTY sortProperty,
            /* [annotation][in] */ 
            _In_  FEEDS_XML_SORT_ORDER sortOrder,
            /* [annotation][in] */ 
            _In_  FEEDS_XML_FILTER_FLAGS filterFlags,
            /* [annotation][in] */ 
            _In_  FEEDS_XML_INCLUDE_FLAGS includeFlags,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *xml);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            __RPC__in IFeed2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *name);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Rename )( 
            __RPC__in IFeed2 * This,
            /* [annotation][in] */ 
            _In_  BSTR name);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Url )( 
            __RPC__in IFeed2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *feedUrl);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Url )( 
            __RPC__in IFeed2 * This,
            /* [annotation][in] */ 
            _In_  BSTR feedUrl);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_LocalId )( 
            __RPC__in IFeed2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *feedGuid);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Path )( 
            __RPC__in IFeed2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *path);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Move )( 
            __RPC__in IFeed2 * This,
            /* [annotation][in] */ 
            _In_  BSTR newParentPath);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Parent )( 
            __RPC__in IFeed2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IDispatch **disp);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_LastWriteTime )( 
            __RPC__in IFeed2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  DATE *lastWrite);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            __RPC__in IFeed2 * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Download )( 
            __RPC__in IFeed2 * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AsyncDownload )( 
            __RPC__in IFeed2 * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CancelAsyncDownload )( 
            __RPC__in IFeed2 * This);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_SyncSetting )( 
            __RPC__in IFeed2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  FEEDS_SYNC_SETTING *syncSetting);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_SyncSetting )( 
            __RPC__in IFeed2 * This,
            /* [annotation][in] */ 
            _In_  FEEDS_SYNC_SETTING syncSetting);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Interval )( 
            __RPC__in IFeed2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  LONG *minutes);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Interval )( 
            __RPC__in IFeed2 * This,
            /* [annotation][in] */ 
            _In_  LONG minutes);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_LastDownloadTime )( 
            __RPC__in IFeed2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  DATE *lastDownload);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_LocalEnclosurePath )( 
            __RPC__in IFeed2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Items )( 
            __RPC__in IFeed2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IDispatch **disp);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetItem )( 
            __RPC__in IFeed2 * This,
            /* [annotation][in] */ 
            _In_  LONG itemId,
            /* [annotation][retval][out] */ 
            _Out_retval_  IDispatch **disp);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Title )( 
            __RPC__in IFeed2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *title);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Description )( 
            __RPC__in IFeed2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *description);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Link )( 
            __RPC__in IFeed2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *homePage);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Image )( 
            __RPC__in IFeed2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *imageUrl);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_LastBuildDate )( 
            __RPC__in IFeed2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  DATE *lastBuildDate);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_PubDate )( 
            __RPC__in IFeed2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  DATE *lastPopulateDate);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Ttl )( 
            __RPC__in IFeed2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  LONG *ttl);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Language )( 
            __RPC__in IFeed2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *language);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Copyright )( 
            __RPC__in IFeed2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *copyright);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_MaxItemCount )( 
            __RPC__in IFeed2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  LONG *count);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_MaxItemCount )( 
            __RPC__in IFeed2 * This,
            /* [annotation][in] */ 
            _In_  LONG count);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DownloadEnclosuresAutomatically )( 
            __RPC__in IFeed2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *downloadEnclosuresAutomatically);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_DownloadEnclosuresAutomatically )( 
            __RPC__in IFeed2 * This,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL downloadEnclosuresAutomatically);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DownloadStatus )( 
            __RPC__in IFeed2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  FEEDS_DOWNLOAD_STATUS *status);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_LastDownloadError )( 
            __RPC__in IFeed2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  FEEDS_DOWNLOAD_ERROR *error);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Merge )( 
            __RPC__in IFeed2 * This,
            /* [annotation][in] */ 
            _In_  BSTR feedXml,
            /* [annotation][in] */ 
            _In_  BSTR feedUrl);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DownloadUrl )( 
            __RPC__in IFeed2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *feedUrl);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_IsList )( 
            __RPC__in IFeed2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *isList);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MarkAllItemsRead )( 
            __RPC__in IFeed2 * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetWatcher )( 
            __RPC__in IFeed2 * This,
            /* [annotation][in] */ 
            _In_  FEEDS_EVENTS_SCOPE scope,
            /* [annotation][in] */ 
            _In_  FEEDS_EVENTS_MASK mask,
            /* [annotation][retval][out] */ 
            _Out_retval_  IDispatch **disp);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_UnreadItemCount )( 
            __RPC__in IFeed2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  LONG *count);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ItemCount )( 
            __RPC__in IFeed2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  LONG *count);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetItemByEffectiveId )( 
            __RPC__in IFeed2 * This,
            /* [annotation][in] */ 
            _In_  LONG itemEffectiveId,
            /* [annotation][retval][out] */ 
            _Out_retval_  IDispatch **disp);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_LastItemDownloadTime )( 
            __RPC__in IFeed2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  DATE *lastItemDownloadTime);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Username )( 
            __RPC__in IFeed2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *username);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Password )( 
            __RPC__in IFeed2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *password);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetCredentials )( 
            __RPC__in IFeed2 * This,
            /* [annotation][in] */ 
            _In_  BSTR username,
            /* [annotation][in] */ 
            _In_  BSTR password);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ClearCredentials )( 
            __RPC__in IFeed2 * This);
        
        END_INTERFACE
    } IFeed2Vtbl;

    interface IFeed2
    {
        CONST_VTBL struct IFeed2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFeed2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFeed2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFeed2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFeed2_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFeed2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFeed2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFeed2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IFeed2_Xml(This,count,sortProperty,sortOrder,filterFlags,includeFlags,xml)	\
    ( (This)->lpVtbl -> Xml(This,count,sortProperty,sortOrder,filterFlags,includeFlags,xml) ) 

#define IFeed2_get_Name(This,name)	\
    ( (This)->lpVtbl -> get_Name(This,name) ) 

#define IFeed2_Rename(This,name)	\
    ( (This)->lpVtbl -> Rename(This,name) ) 

#define IFeed2_get_Url(This,feedUrl)	\
    ( (This)->lpVtbl -> get_Url(This,feedUrl) ) 

#define IFeed2_put_Url(This,feedUrl)	\
    ( (This)->lpVtbl -> put_Url(This,feedUrl) ) 

#define IFeed2_get_LocalId(This,feedGuid)	\
    ( (This)->lpVtbl -> get_LocalId(This,feedGuid) ) 

#define IFeed2_get_Path(This,path)	\
    ( (This)->lpVtbl -> get_Path(This,path) ) 

#define IFeed2_Move(This,newParentPath)	\
    ( (This)->lpVtbl -> Move(This,newParentPath) ) 

#define IFeed2_get_Parent(This,disp)	\
    ( (This)->lpVtbl -> get_Parent(This,disp) ) 

#define IFeed2_get_LastWriteTime(This,lastWrite)	\
    ( (This)->lpVtbl -> get_LastWriteTime(This,lastWrite) ) 

#define IFeed2_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define IFeed2_Download(This)	\
    ( (This)->lpVtbl -> Download(This) ) 

#define IFeed2_AsyncDownload(This)	\
    ( (This)->lpVtbl -> AsyncDownload(This) ) 

#define IFeed2_CancelAsyncDownload(This)	\
    ( (This)->lpVtbl -> CancelAsyncDownload(This) ) 

#define IFeed2_get_SyncSetting(This,syncSetting)	\
    ( (This)->lpVtbl -> get_SyncSetting(This,syncSetting) ) 

#define IFeed2_put_SyncSetting(This,syncSetting)	\
    ( (This)->lpVtbl -> put_SyncSetting(This,syncSetting) ) 

#define IFeed2_get_Interval(This,minutes)	\
    ( (This)->lpVtbl -> get_Interval(This,minutes) ) 

#define IFeed2_put_Interval(This,minutes)	\
    ( (This)->lpVtbl -> put_Interval(This,minutes) ) 

#define IFeed2_get_LastDownloadTime(This,lastDownload)	\
    ( (This)->lpVtbl -> get_LastDownloadTime(This,lastDownload) ) 

#define IFeed2_get_LocalEnclosurePath(This,path)	\
    ( (This)->lpVtbl -> get_LocalEnclosurePath(This,path) ) 

#define IFeed2_get_Items(This,disp)	\
    ( (This)->lpVtbl -> get_Items(This,disp) ) 

#define IFeed2_GetItem(This,itemId,disp)	\
    ( (This)->lpVtbl -> GetItem(This,itemId,disp) ) 

#define IFeed2_get_Title(This,title)	\
    ( (This)->lpVtbl -> get_Title(This,title) ) 

#define IFeed2_get_Description(This,description)	\
    ( (This)->lpVtbl -> get_Description(This,description) ) 

#define IFeed2_get_Link(This,homePage)	\
    ( (This)->lpVtbl -> get_Link(This,homePage) ) 

#define IFeed2_get_Image(This,imageUrl)	\
    ( (This)->lpVtbl -> get_Image(This,imageUrl) ) 

#define IFeed2_get_LastBuildDate(This,lastBuildDate)	\
    ( (This)->lpVtbl -> get_LastBuildDate(This,lastBuildDate) ) 

#define IFeed2_get_PubDate(This,lastPopulateDate)	\
    ( (This)->lpVtbl -> get_PubDate(This,lastPopulateDate) ) 

#define IFeed2_get_Ttl(This,ttl)	\
    ( (This)->lpVtbl -> get_Ttl(This,ttl) ) 

#define IFeed2_get_Language(This,language)	\
    ( (This)->lpVtbl -> get_Language(This,language) ) 

#define IFeed2_get_Copyright(This,copyright)	\
    ( (This)->lpVtbl -> get_Copyright(This,copyright) ) 

#define IFeed2_get_MaxItemCount(This,count)	\
    ( (This)->lpVtbl -> get_MaxItemCount(This,count) ) 

#define IFeed2_put_MaxItemCount(This,count)	\
    ( (This)->lpVtbl -> put_MaxItemCount(This,count) ) 

#define IFeed2_get_DownloadEnclosuresAutomatically(This,downloadEnclosuresAutomatically)	\
    ( (This)->lpVtbl -> get_DownloadEnclosuresAutomatically(This,downloadEnclosuresAutomatically) ) 

#define IFeed2_put_DownloadEnclosuresAutomatically(This,downloadEnclosuresAutomatically)	\
    ( (This)->lpVtbl -> put_DownloadEnclosuresAutomatically(This,downloadEnclosuresAutomatically) ) 

#define IFeed2_get_DownloadStatus(This,status)	\
    ( (This)->lpVtbl -> get_DownloadStatus(This,status) ) 

#define IFeed2_get_LastDownloadError(This,error)	\
    ( (This)->lpVtbl -> get_LastDownloadError(This,error) ) 

#define IFeed2_Merge(This,feedXml,feedUrl)	\
    ( (This)->lpVtbl -> Merge(This,feedXml,feedUrl) ) 

#define IFeed2_get_DownloadUrl(This,feedUrl)	\
    ( (This)->lpVtbl -> get_DownloadUrl(This,feedUrl) ) 

#define IFeed2_get_IsList(This,isList)	\
    ( (This)->lpVtbl -> get_IsList(This,isList) ) 

#define IFeed2_MarkAllItemsRead(This)	\
    ( (This)->lpVtbl -> MarkAllItemsRead(This) ) 

#define IFeed2_GetWatcher(This,scope,mask,disp)	\
    ( (This)->lpVtbl -> GetWatcher(This,scope,mask,disp) ) 

#define IFeed2_get_UnreadItemCount(This,count)	\
    ( (This)->lpVtbl -> get_UnreadItemCount(This,count) ) 

#define IFeed2_get_ItemCount(This,count)	\
    ( (This)->lpVtbl -> get_ItemCount(This,count) ) 


#define IFeed2_GetItemByEffectiveId(This,itemEffectiveId,disp)	\
    ( (This)->lpVtbl -> GetItemByEffectiveId(This,itemEffectiveId,disp) ) 

#define IFeed2_get_LastItemDownloadTime(This,lastItemDownloadTime)	\
    ( (This)->lpVtbl -> get_LastItemDownloadTime(This,lastItemDownloadTime) ) 

#define IFeed2_get_Username(This,username)	\
    ( (This)->lpVtbl -> get_Username(This,username) ) 

#define IFeed2_get_Password(This,password)	\
    ( (This)->lpVtbl -> get_Password(This,password) ) 

#define IFeed2_SetCredentials(This,username,password)	\
    ( (This)->lpVtbl -> SetCredentials(This,username,password) ) 

#define IFeed2_ClearCredentials(This)	\
    ( (This)->lpVtbl -> ClearCredentials(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFeed2_INTERFACE_DEFINED__ */


#ifndef __IFeedEvents_INTERFACE_DEFINED__
#define __IFeedEvents_INTERFACE_DEFINED__

/* interface IFeedEvents */
/* [object][oleautomation][dual][uuid] */ 


EXTERN_C const IID IID_IFeedEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("abf35c99-0681-47ea-9a8c-1436a375a99e")
    IFeedEvents : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Error( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FeedDeleted( 
            /* [annotation][in] */ 
            _In_  const BSTR path) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FeedRenamed( 
            /* [annotation][in] */ 
            _In_  const BSTR path,
            /* [annotation][in] */ 
            _In_  const BSTR oldPath) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FeedUrlChanged( 
            /* [annotation][in] */ 
            _In_  const BSTR path) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FeedMoved( 
            /* [annotation][in] */ 
            _In_  const BSTR path,
            /* [annotation][in] */ 
            _In_  const BSTR oldPath) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FeedDownloading( 
            /* [annotation][in] */ 
            _In_  const BSTR path) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FeedDownloadCompleted( 
            /* [annotation][in] */ 
            _In_  const BSTR path,
            /* [annotation][in] */ 
            _In_  FEEDS_DOWNLOAD_ERROR error) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FeedItemCountChanged( 
            /* [annotation][in] */ 
            _In_  const BSTR path,
            /* [annotation][in] */ 
            _In_  LONG itemCountType) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IFeedEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IFeedEvents * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IFeedEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IFeedEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IFeedEvents * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IFeedEvents * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IFeedEvents * This,
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
            IFeedEvents * This,
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
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Error )( 
            __RPC__in IFeedEvents * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FeedDeleted )( 
            __RPC__in IFeedEvents * This,
            /* [annotation][in] */ 
            _In_  const BSTR path);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FeedRenamed )( 
            __RPC__in IFeedEvents * This,
            /* [annotation][in] */ 
            _In_  const BSTR path,
            /* [annotation][in] */ 
            _In_  const BSTR oldPath);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FeedUrlChanged )( 
            __RPC__in IFeedEvents * This,
            /* [annotation][in] */ 
            _In_  const BSTR path);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FeedMoved )( 
            __RPC__in IFeedEvents * This,
            /* [annotation][in] */ 
            _In_  const BSTR path,
            /* [annotation][in] */ 
            _In_  const BSTR oldPath);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FeedDownloading )( 
            __RPC__in IFeedEvents * This,
            /* [annotation][in] */ 
            _In_  const BSTR path);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FeedDownloadCompleted )( 
            __RPC__in IFeedEvents * This,
            /* [annotation][in] */ 
            _In_  const BSTR path,
            /* [annotation][in] */ 
            _In_  FEEDS_DOWNLOAD_ERROR error);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FeedItemCountChanged )( 
            __RPC__in IFeedEvents * This,
            /* [annotation][in] */ 
            _In_  const BSTR path,
            /* [annotation][in] */ 
            _In_  LONG itemCountType);
        
        END_INTERFACE
    } IFeedEventsVtbl;

    interface IFeedEvents
    {
        CONST_VTBL struct IFeedEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFeedEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFeedEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFeedEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFeedEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFeedEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFeedEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFeedEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IFeedEvents_Error(This)	\
    ( (This)->lpVtbl -> Error(This) ) 

#define IFeedEvents_FeedDeleted(This,path)	\
    ( (This)->lpVtbl -> FeedDeleted(This,path) ) 

#define IFeedEvents_FeedRenamed(This,path,oldPath)	\
    ( (This)->lpVtbl -> FeedRenamed(This,path,oldPath) ) 

#define IFeedEvents_FeedUrlChanged(This,path)	\
    ( (This)->lpVtbl -> FeedUrlChanged(This,path) ) 

#define IFeedEvents_FeedMoved(This,path,oldPath)	\
    ( (This)->lpVtbl -> FeedMoved(This,path,oldPath) ) 

#define IFeedEvents_FeedDownloading(This,path)	\
    ( (This)->lpVtbl -> FeedDownloading(This,path) ) 

#define IFeedEvents_FeedDownloadCompleted(This,path,error)	\
    ( (This)->lpVtbl -> FeedDownloadCompleted(This,path,error) ) 

#define IFeedEvents_FeedItemCountChanged(This,path,itemCountType)	\
    ( (This)->lpVtbl -> FeedItemCountChanged(This,path,itemCountType) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFeedEvents_INTERFACE_DEFINED__ */


#ifndef __IFeedItem_INTERFACE_DEFINED__
#define __IFeedItem_INTERFACE_DEFINED__

/* interface IFeedItem */
/* [object][oleautomation][dual][uuid] */ 


EXTERN_C const IID IID_IFeedItem;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0a1e6cad-0a47-4da2-a13d-5baaa5c8bd4f")
    IFeedItem : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Xml( 
            /* [annotation][in] */ 
            _In_  FEEDS_XML_INCLUDE_FLAGS includeFlags,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *xml) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Title( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *title) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Link( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *linkUrl) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Guid( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *itemGuid) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Description( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *description) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_PubDate( 
            /* [annotation][retval][out] */ 
            _Out_retval_  DATE *pubDate) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Comments( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *comments) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Author( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *author) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Enclosure( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IDispatch **disp) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_IsRead( 
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *isRead) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_IsRead( 
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL isRead) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_LocalId( 
            /* [annotation][retval][out] */ 
            _Out_retval_  LONG *itemId) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Parent( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IDispatch **disp) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Delete( void) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DownloadUrl( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *itemUrl) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_LastDownloadTime( 
            /* [annotation][retval][out] */ 
            _Out_retval_  DATE *lastDownload) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Modified( 
            /* [annotation][retval][out] */ 
            _Out_retval_  DATE *modified) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IFeedItemVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IFeedItem * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IFeedItem * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IFeedItem * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IFeedItem * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IFeedItem * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IFeedItem * This,
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
            IFeedItem * This,
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
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Xml )( 
            __RPC__in IFeedItem * This,
            /* [annotation][in] */ 
            _In_  FEEDS_XML_INCLUDE_FLAGS includeFlags,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *xml);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Title )( 
            __RPC__in IFeedItem * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *title);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Link )( 
            __RPC__in IFeedItem * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *linkUrl);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Guid )( 
            __RPC__in IFeedItem * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *itemGuid);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Description )( 
            __RPC__in IFeedItem * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *description);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_PubDate )( 
            __RPC__in IFeedItem * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  DATE *pubDate);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Comments )( 
            __RPC__in IFeedItem * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *comments);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Author )( 
            __RPC__in IFeedItem * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *author);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Enclosure )( 
            __RPC__in IFeedItem * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IDispatch **disp);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_IsRead )( 
            __RPC__in IFeedItem * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *isRead);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_IsRead )( 
            __RPC__in IFeedItem * This,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL isRead);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_LocalId )( 
            __RPC__in IFeedItem * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  LONG *itemId);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Parent )( 
            __RPC__in IFeedItem * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IDispatch **disp);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            __RPC__in IFeedItem * This);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DownloadUrl )( 
            __RPC__in IFeedItem * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *itemUrl);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_LastDownloadTime )( 
            __RPC__in IFeedItem * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  DATE *lastDownload);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Modified )( 
            __RPC__in IFeedItem * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  DATE *modified);
        
        END_INTERFACE
    } IFeedItemVtbl;

    interface IFeedItem
    {
        CONST_VTBL struct IFeedItemVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFeedItem_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFeedItem_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFeedItem_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFeedItem_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFeedItem_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFeedItem_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFeedItem_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IFeedItem_Xml(This,includeFlags,xml)	\
    ( (This)->lpVtbl -> Xml(This,includeFlags,xml) ) 

#define IFeedItem_get_Title(This,title)	\
    ( (This)->lpVtbl -> get_Title(This,title) ) 

#define IFeedItem_get_Link(This,linkUrl)	\
    ( (This)->lpVtbl -> get_Link(This,linkUrl) ) 

#define IFeedItem_get_Guid(This,itemGuid)	\
    ( (This)->lpVtbl -> get_Guid(This,itemGuid) ) 

#define IFeedItem_get_Description(This,description)	\
    ( (This)->lpVtbl -> get_Description(This,description) ) 

#define IFeedItem_get_PubDate(This,pubDate)	\
    ( (This)->lpVtbl -> get_PubDate(This,pubDate) ) 

#define IFeedItem_get_Comments(This,comments)	\
    ( (This)->lpVtbl -> get_Comments(This,comments) ) 

#define IFeedItem_get_Author(This,author)	\
    ( (This)->lpVtbl -> get_Author(This,author) ) 

#define IFeedItem_get_Enclosure(This,disp)	\
    ( (This)->lpVtbl -> get_Enclosure(This,disp) ) 

#define IFeedItem_get_IsRead(This,isRead)	\
    ( (This)->lpVtbl -> get_IsRead(This,isRead) ) 

#define IFeedItem_put_IsRead(This,isRead)	\
    ( (This)->lpVtbl -> put_IsRead(This,isRead) ) 

#define IFeedItem_get_LocalId(This,itemId)	\
    ( (This)->lpVtbl -> get_LocalId(This,itemId) ) 

#define IFeedItem_get_Parent(This,disp)	\
    ( (This)->lpVtbl -> get_Parent(This,disp) ) 

#define IFeedItem_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define IFeedItem_get_DownloadUrl(This,itemUrl)	\
    ( (This)->lpVtbl -> get_DownloadUrl(This,itemUrl) ) 

#define IFeedItem_get_LastDownloadTime(This,lastDownload)	\
    ( (This)->lpVtbl -> get_LastDownloadTime(This,lastDownload) ) 

#define IFeedItem_get_Modified(This,modified)	\
    ( (This)->lpVtbl -> get_Modified(This,modified) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFeedItem_INTERFACE_DEFINED__ */


#ifndef __IFeedItem2_INTERFACE_DEFINED__
#define __IFeedItem2_INTERFACE_DEFINED__

/* interface IFeedItem2 */
/* [object][oleautomation][dual][uuid] */ 


EXTERN_C const IID IID_IFeedItem2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("79ac9ef4-f9c1-4d2b-a50b-a7ffba4dcf37")
    IFeedItem2 : public IFeedItem
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_EffectiveId( 
            /* [annotation][retval][out] */ 
            _Out_retval_  LONG *effectiveId) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IFeedItem2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IFeedItem2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IFeedItem2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IFeedItem2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IFeedItem2 * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IFeedItem2 * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IFeedItem2 * This,
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
            IFeedItem2 * This,
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
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Xml )( 
            __RPC__in IFeedItem2 * This,
            /* [annotation][in] */ 
            _In_  FEEDS_XML_INCLUDE_FLAGS includeFlags,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *xml);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Title )( 
            __RPC__in IFeedItem2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *title);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Link )( 
            __RPC__in IFeedItem2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *linkUrl);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Guid )( 
            __RPC__in IFeedItem2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *itemGuid);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Description )( 
            __RPC__in IFeedItem2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *description);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_PubDate )( 
            __RPC__in IFeedItem2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  DATE *pubDate);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Comments )( 
            __RPC__in IFeedItem2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *comments);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Author )( 
            __RPC__in IFeedItem2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *author);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Enclosure )( 
            __RPC__in IFeedItem2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IDispatch **disp);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_IsRead )( 
            __RPC__in IFeedItem2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *isRead);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_IsRead )( 
            __RPC__in IFeedItem2 * This,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL isRead);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_LocalId )( 
            __RPC__in IFeedItem2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  LONG *itemId);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Parent )( 
            __RPC__in IFeedItem2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IDispatch **disp);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            __RPC__in IFeedItem2 * This);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DownloadUrl )( 
            __RPC__in IFeedItem2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *itemUrl);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_LastDownloadTime )( 
            __RPC__in IFeedItem2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  DATE *lastDownload);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Modified )( 
            __RPC__in IFeedItem2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  DATE *modified);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_EffectiveId )( 
            __RPC__in IFeedItem2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  LONG *effectiveId);
        
        END_INTERFACE
    } IFeedItem2Vtbl;

    interface IFeedItem2
    {
        CONST_VTBL struct IFeedItem2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFeedItem2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFeedItem2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFeedItem2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFeedItem2_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFeedItem2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFeedItem2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFeedItem2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IFeedItem2_Xml(This,includeFlags,xml)	\
    ( (This)->lpVtbl -> Xml(This,includeFlags,xml) ) 

#define IFeedItem2_get_Title(This,title)	\
    ( (This)->lpVtbl -> get_Title(This,title) ) 

#define IFeedItem2_get_Link(This,linkUrl)	\
    ( (This)->lpVtbl -> get_Link(This,linkUrl) ) 

#define IFeedItem2_get_Guid(This,itemGuid)	\
    ( (This)->lpVtbl -> get_Guid(This,itemGuid) ) 

#define IFeedItem2_get_Description(This,description)	\
    ( (This)->lpVtbl -> get_Description(This,description) ) 

#define IFeedItem2_get_PubDate(This,pubDate)	\
    ( (This)->lpVtbl -> get_PubDate(This,pubDate) ) 

#define IFeedItem2_get_Comments(This,comments)	\
    ( (This)->lpVtbl -> get_Comments(This,comments) ) 

#define IFeedItem2_get_Author(This,author)	\
    ( (This)->lpVtbl -> get_Author(This,author) ) 

#define IFeedItem2_get_Enclosure(This,disp)	\
    ( (This)->lpVtbl -> get_Enclosure(This,disp) ) 

#define IFeedItem2_get_IsRead(This,isRead)	\
    ( (This)->lpVtbl -> get_IsRead(This,isRead) ) 

#define IFeedItem2_put_IsRead(This,isRead)	\
    ( (This)->lpVtbl -> put_IsRead(This,isRead) ) 

#define IFeedItem2_get_LocalId(This,itemId)	\
    ( (This)->lpVtbl -> get_LocalId(This,itemId) ) 

#define IFeedItem2_get_Parent(This,disp)	\
    ( (This)->lpVtbl -> get_Parent(This,disp) ) 

#define IFeedItem2_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define IFeedItem2_get_DownloadUrl(This,itemUrl)	\
    ( (This)->lpVtbl -> get_DownloadUrl(This,itemUrl) ) 

#define IFeedItem2_get_LastDownloadTime(This,lastDownload)	\
    ( (This)->lpVtbl -> get_LastDownloadTime(This,lastDownload) ) 

#define IFeedItem2_get_Modified(This,modified)	\
    ( (This)->lpVtbl -> get_Modified(This,modified) ) 


#define IFeedItem2_get_EffectiveId(This,effectiveId)	\
    ( (This)->lpVtbl -> get_EffectiveId(This,effectiveId) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFeedItem2_INTERFACE_DEFINED__ */


#ifndef __IFeedEnclosure_INTERFACE_DEFINED__
#define __IFeedEnclosure_INTERFACE_DEFINED__

/* interface IFeedEnclosure */
/* [object][oleautomation][dual][uuid] */ 


EXTERN_C const IID IID_IFeedEnclosure;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("361C26F7-90A4-4e67-AE09-3A36A546436A")
    IFeedEnclosure : public IDispatch
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Url( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *enclosureUrl) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Type( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *mimeType) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Length( 
            /* [annotation][retval][out] */ 
            _Out_retval_  LONG *length) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AsyncDownload( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CancelAsyncDownload( void) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DownloadStatus( 
            /* [annotation][retval][out] */ 
            _Out_retval_  FEEDS_DOWNLOAD_STATUS *status) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_LastDownloadError( 
            /* [annotation][retval][out] */ 
            _Out_retval_  FEEDS_DOWNLOAD_ERROR *error) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_LocalPath( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *localPath) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Parent( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IDispatch **disp) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DownloadUrl( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *enclosureUrl) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DownloadMimeType( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *mimeType) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RemoveFile( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetFile( 
            /* [annotation][in] */ 
            _In_  BSTR downloadUrl,
            /* [annotation][in] */ 
            _In_  BSTR downloadFilePath,
            /* [annotation][in] */ 
            _In_  BSTR downloadMimeType,
            /* [annotation][in] */ 
            _In_  BSTR enclosureFilename) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IFeedEnclosureVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IFeedEnclosure * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IFeedEnclosure * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IFeedEnclosure * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IFeedEnclosure * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IFeedEnclosure * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IFeedEnclosure * This,
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
            IFeedEnclosure * This,
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
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Url )( 
            __RPC__in IFeedEnclosure * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *enclosureUrl);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Type )( 
            __RPC__in IFeedEnclosure * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *mimeType);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Length )( 
            __RPC__in IFeedEnclosure * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  LONG *length);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AsyncDownload )( 
            __RPC__in IFeedEnclosure * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CancelAsyncDownload )( 
            __RPC__in IFeedEnclosure * This);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DownloadStatus )( 
            __RPC__in IFeedEnclosure * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  FEEDS_DOWNLOAD_STATUS *status);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_LastDownloadError )( 
            __RPC__in IFeedEnclosure * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  FEEDS_DOWNLOAD_ERROR *error);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_LocalPath )( 
            __RPC__in IFeedEnclosure * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *localPath);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Parent )( 
            __RPC__in IFeedEnclosure * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IDispatch **disp);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DownloadUrl )( 
            __RPC__in IFeedEnclosure * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *enclosureUrl);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DownloadMimeType )( 
            __RPC__in IFeedEnclosure * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *mimeType);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RemoveFile )( 
            __RPC__in IFeedEnclosure * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetFile )( 
            __RPC__in IFeedEnclosure * This,
            /* [annotation][in] */ 
            _In_  BSTR downloadUrl,
            /* [annotation][in] */ 
            _In_  BSTR downloadFilePath,
            /* [annotation][in] */ 
            _In_  BSTR downloadMimeType,
            /* [annotation][in] */ 
            _In_  BSTR enclosureFilename);
        
        END_INTERFACE
    } IFeedEnclosureVtbl;

    interface IFeedEnclosure
    {
        CONST_VTBL struct IFeedEnclosureVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFeedEnclosure_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFeedEnclosure_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFeedEnclosure_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFeedEnclosure_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFeedEnclosure_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFeedEnclosure_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFeedEnclosure_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IFeedEnclosure_get_Url(This,enclosureUrl)	\
    ( (This)->lpVtbl -> get_Url(This,enclosureUrl) ) 

#define IFeedEnclosure_get_Type(This,mimeType)	\
    ( (This)->lpVtbl -> get_Type(This,mimeType) ) 

#define IFeedEnclosure_get_Length(This,length)	\
    ( (This)->lpVtbl -> get_Length(This,length) ) 

#define IFeedEnclosure_AsyncDownload(This)	\
    ( (This)->lpVtbl -> AsyncDownload(This) ) 

#define IFeedEnclosure_CancelAsyncDownload(This)	\
    ( (This)->lpVtbl -> CancelAsyncDownload(This) ) 

#define IFeedEnclosure_get_DownloadStatus(This,status)	\
    ( (This)->lpVtbl -> get_DownloadStatus(This,status) ) 

#define IFeedEnclosure_get_LastDownloadError(This,error)	\
    ( (This)->lpVtbl -> get_LastDownloadError(This,error) ) 

#define IFeedEnclosure_get_LocalPath(This,localPath)	\
    ( (This)->lpVtbl -> get_LocalPath(This,localPath) ) 

#define IFeedEnclosure_get_Parent(This,disp)	\
    ( (This)->lpVtbl -> get_Parent(This,disp) ) 

#define IFeedEnclosure_get_DownloadUrl(This,enclosureUrl)	\
    ( (This)->lpVtbl -> get_DownloadUrl(This,enclosureUrl) ) 

#define IFeedEnclosure_get_DownloadMimeType(This,mimeType)	\
    ( (This)->lpVtbl -> get_DownloadMimeType(This,mimeType) ) 

#define IFeedEnclosure_RemoveFile(This)	\
    ( (This)->lpVtbl -> RemoveFile(This) ) 

#define IFeedEnclosure_SetFile(This,downloadUrl,downloadFilePath,downloadMimeType,enclosureFilename)	\
    ( (This)->lpVtbl -> SetFile(This,downloadUrl,downloadFilePath,downloadMimeType,enclosureFilename) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFeedEnclosure_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_FeedsManager;

#ifdef __cplusplus

class DECLSPEC_UUID("faeb54c4-f66f-4806-83a0-805299f5e3ad")
FeedsManager;
#endif

EXTERN_C const CLSID CLSID_FeedFolderWatcher;

#ifdef __cplusplus

class DECLSPEC_UUID("281001ed-7765-4cb0-84af-e9b387af01ff")
FeedFolderWatcher;
#endif

EXTERN_C const CLSID CLSID_FeedWatcher;

#ifdef __cplusplus

class DECLSPEC_UUID("18a6737b-f433-4687-89bc-a1b4dfb9f123")
FeedWatcher;
#endif
#endif /* __Feeds_LIBRARY_DEFINED__ */

/* interface __MIDL_itf_msfeeds_0000_0011 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_msfeeds_0000_0011_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_msfeeds_0000_0011_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


