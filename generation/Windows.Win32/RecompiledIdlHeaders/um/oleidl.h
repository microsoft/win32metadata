

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

#ifndef __oleidl_h__
#define __oleidl_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IOleAdviseHolder_FWD_DEFINED__
#define __IOleAdviseHolder_FWD_DEFINED__
typedef interface IOleAdviseHolder IOleAdviseHolder;

#endif 	/* __IOleAdviseHolder_FWD_DEFINED__ */


#ifndef __IOleCache_FWD_DEFINED__
#define __IOleCache_FWD_DEFINED__
typedef interface IOleCache IOleCache;

#endif 	/* __IOleCache_FWD_DEFINED__ */


#ifndef __IOleCache2_FWD_DEFINED__
#define __IOleCache2_FWD_DEFINED__
typedef interface IOleCache2 IOleCache2;

#endif 	/* __IOleCache2_FWD_DEFINED__ */


#ifndef __IOleCacheControl_FWD_DEFINED__
#define __IOleCacheControl_FWD_DEFINED__
typedef interface IOleCacheControl IOleCacheControl;

#endif 	/* __IOleCacheControl_FWD_DEFINED__ */


#ifndef __IParseDisplayName_FWD_DEFINED__
#define __IParseDisplayName_FWD_DEFINED__
typedef interface IParseDisplayName IParseDisplayName;

#endif 	/* __IParseDisplayName_FWD_DEFINED__ */


#ifndef __IOleContainer_FWD_DEFINED__
#define __IOleContainer_FWD_DEFINED__
typedef interface IOleContainer IOleContainer;

#endif 	/* __IOleContainer_FWD_DEFINED__ */


#ifndef __IOleClientSite_FWD_DEFINED__
#define __IOleClientSite_FWD_DEFINED__
typedef interface IOleClientSite IOleClientSite;

#endif 	/* __IOleClientSite_FWD_DEFINED__ */


#ifndef __IOleObject_FWD_DEFINED__
#define __IOleObject_FWD_DEFINED__
typedef interface IOleObject IOleObject;

#endif 	/* __IOleObject_FWD_DEFINED__ */


#ifndef __IOleWindow_FWD_DEFINED__
#define __IOleWindow_FWD_DEFINED__
typedef interface IOleWindow IOleWindow;

#endif 	/* __IOleWindow_FWD_DEFINED__ */


#ifndef __IOleLink_FWD_DEFINED__
#define __IOleLink_FWD_DEFINED__
typedef interface IOleLink IOleLink;

#endif 	/* __IOleLink_FWD_DEFINED__ */


#ifndef __IOleItemContainer_FWD_DEFINED__
#define __IOleItemContainer_FWD_DEFINED__
typedef interface IOleItemContainer IOleItemContainer;

#endif 	/* __IOleItemContainer_FWD_DEFINED__ */


#ifndef __IOleInPlaceUIWindow_FWD_DEFINED__
#define __IOleInPlaceUIWindow_FWD_DEFINED__
typedef interface IOleInPlaceUIWindow IOleInPlaceUIWindow;

#endif 	/* __IOleInPlaceUIWindow_FWD_DEFINED__ */


#ifndef __IOleInPlaceActiveObject_FWD_DEFINED__
#define __IOleInPlaceActiveObject_FWD_DEFINED__
typedef interface IOleInPlaceActiveObject IOleInPlaceActiveObject;

#endif 	/* __IOleInPlaceActiveObject_FWD_DEFINED__ */


#ifndef __IOleInPlaceFrame_FWD_DEFINED__
#define __IOleInPlaceFrame_FWD_DEFINED__
typedef interface IOleInPlaceFrame IOleInPlaceFrame;

#endif 	/* __IOleInPlaceFrame_FWD_DEFINED__ */


#ifndef __IOleInPlaceObject_FWD_DEFINED__
#define __IOleInPlaceObject_FWD_DEFINED__
typedef interface IOleInPlaceObject IOleInPlaceObject;

#endif 	/* __IOleInPlaceObject_FWD_DEFINED__ */


#ifndef __IOleInPlaceSite_FWD_DEFINED__
#define __IOleInPlaceSite_FWD_DEFINED__
typedef interface IOleInPlaceSite IOleInPlaceSite;

#endif 	/* __IOleInPlaceSite_FWD_DEFINED__ */


#ifndef __IContinue_FWD_DEFINED__
#define __IContinue_FWD_DEFINED__
typedef interface IContinue IContinue;

#endif 	/* __IContinue_FWD_DEFINED__ */


#ifndef __IViewObject_FWD_DEFINED__
#define __IViewObject_FWD_DEFINED__
typedef interface IViewObject IViewObject;

#endif 	/* __IViewObject_FWD_DEFINED__ */


#ifndef __IViewObject2_FWD_DEFINED__
#define __IViewObject2_FWD_DEFINED__
typedef interface IViewObject2 IViewObject2;

#endif 	/* __IViewObject2_FWD_DEFINED__ */


#ifndef __IDropSource_FWD_DEFINED__
#define __IDropSource_FWD_DEFINED__
typedef interface IDropSource IDropSource;

#endif 	/* __IDropSource_FWD_DEFINED__ */


#ifndef __IDropTarget_FWD_DEFINED__
#define __IDropTarget_FWD_DEFINED__
typedef interface IDropTarget IDropTarget;

#endif 	/* __IDropTarget_FWD_DEFINED__ */


#ifndef __IDropSourceNotify_FWD_DEFINED__
#define __IDropSourceNotify_FWD_DEFINED__
typedef interface IDropSourceNotify IDropSourceNotify;

#endif 	/* __IDropSourceNotify_FWD_DEFINED__ */


#ifndef __IEnterpriseDropTarget_FWD_DEFINED__
#define __IEnterpriseDropTarget_FWD_DEFINED__
typedef interface IEnterpriseDropTarget IEnterpriseDropTarget;

#endif 	/* __IEnterpriseDropTarget_FWD_DEFINED__ */


#ifndef __IEnumOLEVERB_FWD_DEFINED__
#define __IEnumOLEVERB_FWD_DEFINED__
typedef interface IEnumOLEVERB IEnumOLEVERB;

#endif 	/* __IEnumOLEVERB_FWD_DEFINED__ */


/* header files for imported files */
#include "objidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_oleidl_0000_0000 */
/* [local] */ 

//+-------------------------------------------------------------------------
//
//  Microsoft Windows
//  Copyright (c) Microsoft Corporation. All rights reserved.
//
//--------------------------------------------------------------------------
#if ( _MSC_VER >= 1020 )
#pragma once
#endif
#include <winapifamily.h>
#if _MSC_VER >= 1200
#pragma warning(push)
#pragma warning(disable:4820) /* padding added after data member */
#endif
#pragma region Desktop Family or OneCore Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)




extern RPC_IF_HANDLE __MIDL_itf_oleidl_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_oleidl_0000_0000_v0_0_s_ifspec;

#ifndef __IOleAdviseHolder_INTERFACE_DEFINED__
#define __IOleAdviseHolder_INTERFACE_DEFINED__

/* interface IOleAdviseHolder */
/* [uuid][object][local] */ 

typedef /* [unique] */ IOleAdviseHolder *LPOLEADVISEHOLDER;


EXTERN_C const IID IID_IOleAdviseHolder;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("00000111-0000-0000-C000-000000000046")
    IOleAdviseHolder : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Advise( 
            /* [annotation][unique][in] */ 
            _In_  IAdviseSink *pAdvise,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwConnection) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Unadvise( 
            /* [annotation][in] */ 
            _In_  DWORD dwConnection) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumAdvise( 
            /* [annotation][out] */ 
            _Outptr_  IEnumSTATDATA **ppenumAdvise) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SendOnRename( 
            /* [annotation][unique][in] */ 
            _In_  IMoniker *pmk) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SendOnSave( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SendOnClose( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IOleAdviseHolderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IOleAdviseHolder * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IOleAdviseHolder * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IOleAdviseHolder * This);
        
        HRESULT ( STDMETHODCALLTYPE *Advise )( 
            IOleAdviseHolder * This,
            /* [annotation][unique][in] */ 
            _In_  IAdviseSink *pAdvise,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwConnection);
        
        HRESULT ( STDMETHODCALLTYPE *Unadvise )( 
            IOleAdviseHolder * This,
            /* [annotation][in] */ 
            _In_  DWORD dwConnection);
        
        HRESULT ( STDMETHODCALLTYPE *EnumAdvise )( 
            IOleAdviseHolder * This,
            /* [annotation][out] */ 
            _Outptr_  IEnumSTATDATA **ppenumAdvise);
        
        HRESULT ( STDMETHODCALLTYPE *SendOnRename )( 
            IOleAdviseHolder * This,
            /* [annotation][unique][in] */ 
            _In_  IMoniker *pmk);
        
        HRESULT ( STDMETHODCALLTYPE *SendOnSave )( 
            IOleAdviseHolder * This);
        
        HRESULT ( STDMETHODCALLTYPE *SendOnClose )( 
            IOleAdviseHolder * This);
        
        END_INTERFACE
    } IOleAdviseHolderVtbl;

    interface IOleAdviseHolder
    {
        CONST_VTBL struct IOleAdviseHolderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOleAdviseHolder_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOleAdviseHolder_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOleAdviseHolder_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOleAdviseHolder_Advise(This,pAdvise,pdwConnection)	\
    ( (This)->lpVtbl -> Advise(This,pAdvise,pdwConnection) ) 

#define IOleAdviseHolder_Unadvise(This,dwConnection)	\
    ( (This)->lpVtbl -> Unadvise(This,dwConnection) ) 

#define IOleAdviseHolder_EnumAdvise(This,ppenumAdvise)	\
    ( (This)->lpVtbl -> EnumAdvise(This,ppenumAdvise) ) 

#define IOleAdviseHolder_SendOnRename(This,pmk)	\
    ( (This)->lpVtbl -> SendOnRename(This,pmk) ) 

#define IOleAdviseHolder_SendOnSave(This)	\
    ( (This)->lpVtbl -> SendOnSave(This) ) 

#define IOleAdviseHolder_SendOnClose(This)	\
    ( (This)->lpVtbl -> SendOnClose(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOleAdviseHolder_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_oleidl_0000_0001 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) */
#pragma endregion
#pragma region Application Family or OneCore Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM)


extern RPC_IF_HANDLE __MIDL_itf_oleidl_0000_0001_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_oleidl_0000_0001_v0_0_s_ifspec;

#ifndef __IOleCache_INTERFACE_DEFINED__
#define __IOleCache_INTERFACE_DEFINED__

/* interface IOleCache */
/* [unique][uuid][object] */ 

typedef /* [unique] */  __RPC_unique_pointer IOleCache *LPOLECACHE;


EXTERN_C const IID IID_IOleCache;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0000011e-0000-0000-C000-000000000046")
    IOleCache : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Cache( 
            /* [annotation][unique][in] */ 
            _In_  FORMATETC *pformatetc,
            /* [annotation][in] */ 
            _In_  DWORD advf,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwConnection) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Uncache( 
            /* [annotation][in] */ 
            _In_  DWORD dwConnection) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumCache( 
            /* [annotation][out] */ 
            _Out_  IEnumSTATDATA **ppenumSTATDATA) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InitCache( 
            /* [annotation][unique][in] */ 
            _In_  IDataObject *pDataObject) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetData( 
            /* [annotation][unique][in] */ 
            _In_  FORMATETC *pformatetc,
            /* [annotation][unique][in] */ 
            _In_  STGMEDIUM *pmedium,
            /* [annotation][in] */ 
            _In_  BOOL fRelease) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IOleCacheVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IOleCache * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IOleCache * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IOleCache * This);
        
        HRESULT ( STDMETHODCALLTYPE *Cache )( 
            __RPC__in IOleCache * This,
            /* [annotation][unique][in] */ 
            _In_  FORMATETC *pformatetc,
            /* [annotation][in] */ 
            _In_  DWORD advf,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwConnection);
        
        HRESULT ( STDMETHODCALLTYPE *Uncache )( 
            __RPC__in IOleCache * This,
            /* [annotation][in] */ 
            _In_  DWORD dwConnection);
        
        HRESULT ( STDMETHODCALLTYPE *EnumCache )( 
            __RPC__in IOleCache * This,
            /* [annotation][out] */ 
            _Out_  IEnumSTATDATA **ppenumSTATDATA);
        
        HRESULT ( STDMETHODCALLTYPE *InitCache )( 
            __RPC__in IOleCache * This,
            /* [annotation][unique][in] */ 
            _In_  IDataObject *pDataObject);
        
        HRESULT ( STDMETHODCALLTYPE *SetData )( 
            __RPC__in IOleCache * This,
            /* [annotation][unique][in] */ 
            _In_  FORMATETC *pformatetc,
            /* [annotation][unique][in] */ 
            _In_  STGMEDIUM *pmedium,
            /* [annotation][in] */ 
            _In_  BOOL fRelease);
        
        END_INTERFACE
    } IOleCacheVtbl;

    interface IOleCache
    {
        CONST_VTBL struct IOleCacheVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOleCache_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOleCache_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOleCache_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOleCache_Cache(This,pformatetc,advf,pdwConnection)	\
    ( (This)->lpVtbl -> Cache(This,pformatetc,advf,pdwConnection) ) 

#define IOleCache_Uncache(This,dwConnection)	\
    ( (This)->lpVtbl -> Uncache(This,dwConnection) ) 

#define IOleCache_EnumCache(This,ppenumSTATDATA)	\
    ( (This)->lpVtbl -> EnumCache(This,ppenumSTATDATA) ) 

#define IOleCache_InitCache(This,pDataObject)	\
    ( (This)->lpVtbl -> InitCache(This,pDataObject) ) 

#define IOleCache_SetData(This,pformatetc,pmedium,fRelease)	\
    ( (This)->lpVtbl -> SetData(This,pformatetc,pmedium,fRelease) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOleCache_INTERFACE_DEFINED__ */


#ifndef __IOleCache2_INTERFACE_DEFINED__
#define __IOleCache2_INTERFACE_DEFINED__

/* interface IOleCache2 */
/* [unique][uuid][object] */ 

typedef /* [unique] */  __RPC_unique_pointer IOleCache2 *LPOLECACHE2;

#define	UPDFCACHE_NODATACACHE	( 0x1 )

#define	UPDFCACHE_ONSAVECACHE	( 0x2 )

#define	UPDFCACHE_ONSTOPCACHE	( 0x4 )

#define	UPDFCACHE_NORMALCACHE	( 0x8 )

#define	UPDFCACHE_IFBLANK	( 0x10 )

#define	UPDFCACHE_ONLYIFBLANK	( 0x80000000 )

#define	UPDFCACHE_IFBLANKORONSAVECACHE	( ( UPDFCACHE_IFBLANK | UPDFCACHE_ONSAVECACHE )  )

#define	UPDFCACHE_ALL	( ( DWORD  )~UPDFCACHE_ONLYIFBLANK )

#define	UPDFCACHE_ALLBUTNODATACACHE	( ( UPDFCACHE_ALL & ( DWORD  )~UPDFCACHE_NODATACACHE )  )

typedef /* [v1_enum] */ 
enum tagDISCARDCACHE
    {
        DISCARDCACHE_SAVEIFDIRTY	= 0,
        DISCARDCACHE_NOSAVE	= 1
    } 	DISCARDCACHE;


EXTERN_C const IID IID_IOleCache2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("00000128-0000-0000-C000-000000000046")
    IOleCache2 : public IOleCache
    {
    public:
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE UpdateCache( 
            /* [annotation][in] */ 
            _In_  LPDATAOBJECT pDataObject,
            /* [annotation][in] */ 
            _In_  DWORD grfUpdf,
            /* [annotation][in] */ 
            _Reserved_  LPVOID pReserved) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DiscardCache( 
            /* [annotation][in] */ 
            _In_  DWORD dwDiscardOptions) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IOleCache2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IOleCache2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IOleCache2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IOleCache2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *Cache )( 
            __RPC__in IOleCache2 * This,
            /* [annotation][unique][in] */ 
            _In_  FORMATETC *pformatetc,
            /* [annotation][in] */ 
            _In_  DWORD advf,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwConnection);
        
        HRESULT ( STDMETHODCALLTYPE *Uncache )( 
            __RPC__in IOleCache2 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwConnection);
        
        HRESULT ( STDMETHODCALLTYPE *EnumCache )( 
            __RPC__in IOleCache2 * This,
            /* [annotation][out] */ 
            _Out_  IEnumSTATDATA **ppenumSTATDATA);
        
        HRESULT ( STDMETHODCALLTYPE *InitCache )( 
            __RPC__in IOleCache2 * This,
            /* [annotation][unique][in] */ 
            _In_  IDataObject *pDataObject);
        
        HRESULT ( STDMETHODCALLTYPE *SetData )( 
            __RPC__in IOleCache2 * This,
            /* [annotation][unique][in] */ 
            _In_  FORMATETC *pformatetc,
            /* [annotation][unique][in] */ 
            _In_  STGMEDIUM *pmedium,
            /* [annotation][in] */ 
            _In_  BOOL fRelease);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *UpdateCache )( 
            IOleCache2 * This,
            /* [annotation][in] */ 
            _In_  LPDATAOBJECT pDataObject,
            /* [annotation][in] */ 
            _In_  DWORD grfUpdf,
            /* [annotation][in] */ 
            _Reserved_  LPVOID pReserved);
        
        HRESULT ( STDMETHODCALLTYPE *DiscardCache )( 
            __RPC__in IOleCache2 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwDiscardOptions);
        
        END_INTERFACE
    } IOleCache2Vtbl;

    interface IOleCache2
    {
        CONST_VTBL struct IOleCache2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOleCache2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOleCache2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOleCache2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOleCache2_Cache(This,pformatetc,advf,pdwConnection)	\
    ( (This)->lpVtbl -> Cache(This,pformatetc,advf,pdwConnection) ) 

#define IOleCache2_Uncache(This,dwConnection)	\
    ( (This)->lpVtbl -> Uncache(This,dwConnection) ) 

#define IOleCache2_EnumCache(This,ppenumSTATDATA)	\
    ( (This)->lpVtbl -> EnumCache(This,ppenumSTATDATA) ) 

#define IOleCache2_InitCache(This,pDataObject)	\
    ( (This)->lpVtbl -> InitCache(This,pDataObject) ) 

#define IOleCache2_SetData(This,pformatetc,pmedium,fRelease)	\
    ( (This)->lpVtbl -> SetData(This,pformatetc,pmedium,fRelease) ) 


#define IOleCache2_UpdateCache(This,pDataObject,grfUpdf,pReserved)	\
    ( (This)->lpVtbl -> UpdateCache(This,pDataObject,grfUpdf,pReserved) ) 

#define IOleCache2_DiscardCache(This,dwDiscardOptions)	\
    ( (This)->lpVtbl -> DiscardCache(This,dwDiscardOptions) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT STDMETHODCALLTYPE IOleCache2_RemoteUpdateCache_Proxy( 
    __RPC__in IOleCache2 * This,
    /* [annotation][in] */ 
    _In_  LPDATAOBJECT pDataObject,
    /* [annotation][in] */ 
    _In_  DWORD grfUpdf,
    /* [annotation][in] */ 
    _In_  LONG_PTR pReserved);


void __RPC_STUB IOleCache2_RemoteUpdateCache_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IOleCache2_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_oleidl_0000_0003 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM) */
#pragma endregion
#pragma region Desktop Family or OneCore Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)


extern RPC_IF_HANDLE __MIDL_itf_oleidl_0000_0003_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_oleidl_0000_0003_v0_0_s_ifspec;

#ifndef __IOleCacheControl_INTERFACE_DEFINED__
#define __IOleCacheControl_INTERFACE_DEFINED__

/* interface IOleCacheControl */
/* [uuid][object] */ 

typedef /* [unique] */  __RPC_unique_pointer IOleCacheControl *LPOLECACHECONTROL;


EXTERN_C const IID IID_IOleCacheControl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("00000129-0000-0000-C000-000000000046")
    IOleCacheControl : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnRun( 
            __RPC__in_opt LPDATAOBJECT pDataObject) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnStop( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IOleCacheControlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IOleCacheControl * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IOleCacheControl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IOleCacheControl * This);
        
        HRESULT ( STDMETHODCALLTYPE *OnRun )( 
            __RPC__in IOleCacheControl * This,
            __RPC__in_opt LPDATAOBJECT pDataObject);
        
        HRESULT ( STDMETHODCALLTYPE *OnStop )( 
            __RPC__in IOleCacheControl * This);
        
        END_INTERFACE
    } IOleCacheControlVtbl;

    interface IOleCacheControl
    {
        CONST_VTBL struct IOleCacheControlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOleCacheControl_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOleCacheControl_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOleCacheControl_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOleCacheControl_OnRun(This,pDataObject)	\
    ( (This)->lpVtbl -> OnRun(This,pDataObject) ) 

#define IOleCacheControl_OnStop(This)	\
    ( (This)->lpVtbl -> OnStop(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOleCacheControl_INTERFACE_DEFINED__ */


#ifndef __IParseDisplayName_INTERFACE_DEFINED__
#define __IParseDisplayName_INTERFACE_DEFINED__

/* interface IParseDisplayName */
/* [unique][uuid][object] */ 

typedef /* [unique] */  __RPC_unique_pointer IParseDisplayName *LPPARSEDISPLAYNAME;


EXTERN_C const IID IID_IParseDisplayName;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0000011a-0000-0000-C000-000000000046")
    IParseDisplayName : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ParseDisplayName( 
            /* [annotation][unique][in] */ 
            _In_  IBindCtx *pbc,
            /* [annotation][in] */ 
            _In_  LPOLESTR pszDisplayName,
            /* [annotation][out] */ 
            _Out_  ULONG *pchEaten,
            /* [annotation][out] */ 
            _Out_  IMoniker **ppmkOut) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IParseDisplayNameVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IParseDisplayName * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IParseDisplayName * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IParseDisplayName * This);
        
        HRESULT ( STDMETHODCALLTYPE *ParseDisplayName )( 
            __RPC__in IParseDisplayName * This,
            /* [annotation][unique][in] */ 
            _In_  IBindCtx *pbc,
            /* [annotation][in] */ 
            _In_  LPOLESTR pszDisplayName,
            /* [annotation][out] */ 
            _Out_  ULONG *pchEaten,
            /* [annotation][out] */ 
            _Out_  IMoniker **ppmkOut);
        
        END_INTERFACE
    } IParseDisplayNameVtbl;

    interface IParseDisplayName
    {
        CONST_VTBL struct IParseDisplayNameVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IParseDisplayName_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IParseDisplayName_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IParseDisplayName_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IParseDisplayName_ParseDisplayName(This,pbc,pszDisplayName,pchEaten,ppmkOut)	\
    ( (This)->lpVtbl -> ParseDisplayName(This,pbc,pszDisplayName,pchEaten,ppmkOut) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IParseDisplayName_INTERFACE_DEFINED__ */


#ifndef __IOleContainer_INTERFACE_DEFINED__
#define __IOleContainer_INTERFACE_DEFINED__

/* interface IOleContainer */
/* [unique][uuid][object] */ 

typedef /* [unique] */  __RPC_unique_pointer IOleContainer *LPOLECONTAINER;


EXTERN_C const IID IID_IOleContainer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0000011b-0000-0000-C000-000000000046")
    IOleContainer : public IParseDisplayName
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE EnumObjects( 
            /* [annotation][in] */ 
            _In_  DWORD grfFlags,
            /* [annotation][out] */ 
            _Out_  IEnumUnknown **ppenum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LockContainer( 
            /* [annotation][in] */ 
            _In_  BOOL fLock) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IOleContainerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IOleContainer * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IOleContainer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IOleContainer * This);
        
        HRESULT ( STDMETHODCALLTYPE *ParseDisplayName )( 
            __RPC__in IOleContainer * This,
            /* [annotation][unique][in] */ 
            _In_  IBindCtx *pbc,
            /* [annotation][in] */ 
            _In_  LPOLESTR pszDisplayName,
            /* [annotation][out] */ 
            _Out_  ULONG *pchEaten,
            /* [annotation][out] */ 
            _Out_  IMoniker **ppmkOut);
        
        HRESULT ( STDMETHODCALLTYPE *EnumObjects )( 
            __RPC__in IOleContainer * This,
            /* [annotation][in] */ 
            _In_  DWORD grfFlags,
            /* [annotation][out] */ 
            _Out_  IEnumUnknown **ppenum);
        
        HRESULT ( STDMETHODCALLTYPE *LockContainer )( 
            __RPC__in IOleContainer * This,
            /* [annotation][in] */ 
            _In_  BOOL fLock);
        
        END_INTERFACE
    } IOleContainerVtbl;

    interface IOleContainer
    {
        CONST_VTBL struct IOleContainerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOleContainer_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOleContainer_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOleContainer_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOleContainer_ParseDisplayName(This,pbc,pszDisplayName,pchEaten,ppmkOut)	\
    ( (This)->lpVtbl -> ParseDisplayName(This,pbc,pszDisplayName,pchEaten,ppmkOut) ) 


#define IOleContainer_EnumObjects(This,grfFlags,ppenum)	\
    ( (This)->lpVtbl -> EnumObjects(This,grfFlags,ppenum) ) 

#define IOleContainer_LockContainer(This,fLock)	\
    ( (This)->lpVtbl -> LockContainer(This,fLock) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOleContainer_INTERFACE_DEFINED__ */


#ifndef __IOleClientSite_INTERFACE_DEFINED__
#define __IOleClientSite_INTERFACE_DEFINED__

/* interface IOleClientSite */
/* [unique][uuid][object] */ 

typedef /* [unique] */  __RPC_unique_pointer IOleClientSite *LPOLECLIENTSITE;


EXTERN_C const IID IID_IOleClientSite;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("00000118-0000-0000-C000-000000000046")
    IOleClientSite : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SaveObject( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMoniker( 
            /* [annotation][in] */ 
            _In_  DWORD dwAssign,
            /* [annotation][in] */ 
            _In_  DWORD dwWhichMoniker,
            /* [annotation][out] */ 
            _Out_  IMoniker **ppmk) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetContainer( 
            /* [annotation][out] */ 
            _Out_  IOleContainer **ppContainer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ShowObject( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnShowWindow( 
            /* [annotation][in] */ 
            _In_  BOOL fShow) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RequestNewObjectLayout( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IOleClientSiteVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IOleClientSite * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IOleClientSite * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IOleClientSite * This);
        
        HRESULT ( STDMETHODCALLTYPE *SaveObject )( 
            __RPC__in IOleClientSite * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetMoniker )( 
            __RPC__in IOleClientSite * This,
            /* [annotation][in] */ 
            _In_  DWORD dwAssign,
            /* [annotation][in] */ 
            _In_  DWORD dwWhichMoniker,
            /* [annotation][out] */ 
            _Out_  IMoniker **ppmk);
        
        HRESULT ( STDMETHODCALLTYPE *GetContainer )( 
            __RPC__in IOleClientSite * This,
            /* [annotation][out] */ 
            _Out_  IOleContainer **ppContainer);
        
        HRESULT ( STDMETHODCALLTYPE *ShowObject )( 
            __RPC__in IOleClientSite * This);
        
        HRESULT ( STDMETHODCALLTYPE *OnShowWindow )( 
            __RPC__in IOleClientSite * This,
            /* [annotation][in] */ 
            _In_  BOOL fShow);
        
        HRESULT ( STDMETHODCALLTYPE *RequestNewObjectLayout )( 
            __RPC__in IOleClientSite * This);
        
        END_INTERFACE
    } IOleClientSiteVtbl;

    interface IOleClientSite
    {
        CONST_VTBL struct IOleClientSiteVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOleClientSite_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOleClientSite_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOleClientSite_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOleClientSite_SaveObject(This)	\
    ( (This)->lpVtbl -> SaveObject(This) ) 

#define IOleClientSite_GetMoniker(This,dwAssign,dwWhichMoniker,ppmk)	\
    ( (This)->lpVtbl -> GetMoniker(This,dwAssign,dwWhichMoniker,ppmk) ) 

#define IOleClientSite_GetContainer(This,ppContainer)	\
    ( (This)->lpVtbl -> GetContainer(This,ppContainer) ) 

#define IOleClientSite_ShowObject(This)	\
    ( (This)->lpVtbl -> ShowObject(This) ) 

#define IOleClientSite_OnShowWindow(This,fShow)	\
    ( (This)->lpVtbl -> OnShowWindow(This,fShow) ) 

#define IOleClientSite_RequestNewObjectLayout(This)	\
    ( (This)->lpVtbl -> RequestNewObjectLayout(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOleClientSite_INTERFACE_DEFINED__ */


#ifndef __IOleObject_INTERFACE_DEFINED__
#define __IOleObject_INTERFACE_DEFINED__

/* interface IOleObject */
/* [unique][uuid][object] */ 

typedef /* [unique] */  __RPC_unique_pointer IOleObject *LPOLEOBJECT;

typedef 
enum tagOLEGETMONIKER
    {
        OLEGETMONIKER_ONLYIFTHERE	= 1,
        OLEGETMONIKER_FORCEASSIGN	= 2,
        OLEGETMONIKER_UNASSIGN	= 3,
        OLEGETMONIKER_TEMPFORUSER	= 4
    } 	OLEGETMONIKER;

typedef 
enum tagOLEWHICHMK
    {
        OLEWHICHMK_CONTAINER	= 1,
        OLEWHICHMK_OBJREL	= 2,
        OLEWHICHMK_OBJFULL	= 3
    } 	OLEWHICHMK;

typedef 
enum tagUSERCLASSTYPE
    {
        USERCLASSTYPE_FULL	= 1,
        USERCLASSTYPE_SHORT	= 2,
        USERCLASSTYPE_APPNAME	= 3
    } 	USERCLASSTYPE;

typedef 
enum tagOLEMISC
    {
        OLEMISC_RECOMPOSEONRESIZE	= 0x1,
        OLEMISC_ONLYICONIC	= 0x2,
        OLEMISC_INSERTNOTREPLACE	= 0x4,
        OLEMISC_STATIC	= 0x8,
        OLEMISC_CANTLINKINSIDE	= 0x10,
        OLEMISC_CANLINKBYOLE1	= 0x20,
        OLEMISC_ISLINKOBJECT	= 0x40,
        OLEMISC_INSIDEOUT	= 0x80,
        OLEMISC_ACTIVATEWHENVISIBLE	= 0x100,
        OLEMISC_RENDERINGISDEVICEINDEPENDENT	= 0x200,
        OLEMISC_INVISIBLEATRUNTIME	= 0x400,
        OLEMISC_ALWAYSRUN	= 0x800,
        OLEMISC_ACTSLIKEBUTTON	= 0x1000,
        OLEMISC_ACTSLIKELABEL	= 0x2000,
        OLEMISC_NOUIACTIVATE	= 0x4000,
        OLEMISC_ALIGNABLE	= 0x8000,
        OLEMISC_SIMPLEFRAME	= 0x10000,
        OLEMISC_SETCLIENTSITEFIRST	= 0x20000,
        OLEMISC_IMEMODE	= 0x40000,
        OLEMISC_IGNOREACTIVATEWHENVISIBLE	= 0x80000,
        OLEMISC_WANTSTOMENUMERGE	= 0x100000,
        OLEMISC_SUPPORTSMULTILEVELUNDO	= 0x200000
    } 	OLEMISC;

typedef 
enum tagOLECLOSE
    {
        OLECLOSE_SAVEIFDIRTY	= 0,
        OLECLOSE_NOSAVE	= 1,
        OLECLOSE_PROMPTSAVE	= 2
    } 	OLECLOSE;


EXTERN_C const IID IID_IOleObject;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("00000112-0000-0000-C000-000000000046")
    IOleObject : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetClientSite( 
            /* [annotation][unique][in] */ 
            _In_  IOleClientSite *pClientSite) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetClientSite( 
            /* [annotation][out] */ 
            _Out_  IOleClientSite **ppClientSite) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetHostNames( 
            /* [annotation][in] */ 
            _In_  LPCOLESTR szContainerApp,
            /* [annotation][unique][in] */ 
            _In_  LPCOLESTR szContainerObj) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Close( 
            /* [annotation][in] */ 
            _In_  DWORD dwSaveOption) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMoniker( 
            /* [annotation][in] */ 
            _In_  DWORD dwWhichMoniker,
            /* [annotation][unique][in] */ 
            _In_  IMoniker *pmk) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMoniker( 
            /* [annotation][in] */ 
            _In_  DWORD dwAssign,
            /* [annotation][in] */ 
            _In_  DWORD dwWhichMoniker,
            /* [annotation][out] */ 
            _Out_  IMoniker **ppmk) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InitFromData( 
            /* [annotation][unique][in] */ 
            _In_  IDataObject *pDataObject,
            /* [annotation][in] */ 
            _In_  BOOL fCreation,
            /* [annotation][in] */ 
            _In_  DWORD dwReserved) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetClipboardData( 
            /* [annotation][in] */ 
            _In_  DWORD dwReserved,
            /* [annotation][out] */ 
            _Out_  IDataObject **ppDataObject) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DoVerb( 
            /* [annotation][in] */ 
            _In_  LONG iVerb,
            /* [annotation][unique][in] */ 
            _In_  LPMSG lpmsg,
            /* [annotation][unique][in] */ 
            _In_  IOleClientSite *pActiveSite,
            /* [annotation][in] */ 
            _In_  LONG lindex,
            /* [annotation][in] */ 
            _In_  HWND hwndParent,
            /* [annotation][unique][in] */ 
            _In_  LPCRECT lprcPosRect) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumVerbs( 
            /* [annotation][out] */ 
            _Out_  IEnumOLEVERB **ppEnumOleVerb) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Update( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsUpToDate( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetUserClassID( 
            /* [annotation][out] */ 
            _Out_  CLSID *pClsid) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetUserType( 
            /* [annotation][in] */ 
            _In_  DWORD dwFormOfType,
            /* [annotation][out] */ 
            _Out_  LPOLESTR *pszUserType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetExtent( 
            /* [annotation][in] */ 
            _In_  DWORD dwDrawAspect,
            /* [annotation][in] */ 
            _In_  SIZEL *psizel) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetExtent( 
            /* [annotation][in] */ 
            _In_  DWORD dwDrawAspect,
            /* [annotation][out] */ 
            _Out_  SIZEL *psizel) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Advise( 
            /* [annotation][unique][in] */ 
            _In_  IAdviseSink *pAdvSink,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwConnection) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Unadvise( 
            /* [annotation][in] */ 
            _In_  DWORD dwConnection) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumAdvise( 
            /* [annotation][out] */ 
            _Out_  IEnumSTATDATA **ppenumAdvise) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMiscStatus( 
            /* [annotation][in] */ 
            _In_  DWORD dwAspect,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwStatus) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetColorScheme( 
            /* [annotation][in] */ 
            _In_  LOGPALETTE *pLogpal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IOleObjectVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IOleObject * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IOleObject * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IOleObject * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetClientSite )( 
            __RPC__in IOleObject * This,
            /* [annotation][unique][in] */ 
            _In_  IOleClientSite *pClientSite);
        
        HRESULT ( STDMETHODCALLTYPE *GetClientSite )( 
            __RPC__in IOleObject * This,
            /* [annotation][out] */ 
            _Out_  IOleClientSite **ppClientSite);
        
        HRESULT ( STDMETHODCALLTYPE *SetHostNames )( 
            __RPC__in IOleObject * This,
            /* [annotation][in] */ 
            _In_  LPCOLESTR szContainerApp,
            /* [annotation][unique][in] */ 
            _In_  LPCOLESTR szContainerObj);
        
        HRESULT ( STDMETHODCALLTYPE *Close )( 
            __RPC__in IOleObject * This,
            /* [annotation][in] */ 
            _In_  DWORD dwSaveOption);
        
        HRESULT ( STDMETHODCALLTYPE *SetMoniker )( 
            __RPC__in IOleObject * This,
            /* [annotation][in] */ 
            _In_  DWORD dwWhichMoniker,
            /* [annotation][unique][in] */ 
            _In_  IMoniker *pmk);
        
        HRESULT ( STDMETHODCALLTYPE *GetMoniker )( 
            __RPC__in IOleObject * This,
            /* [annotation][in] */ 
            _In_  DWORD dwAssign,
            /* [annotation][in] */ 
            _In_  DWORD dwWhichMoniker,
            /* [annotation][out] */ 
            _Out_  IMoniker **ppmk);
        
        HRESULT ( STDMETHODCALLTYPE *InitFromData )( 
            __RPC__in IOleObject * This,
            /* [annotation][unique][in] */ 
            _In_  IDataObject *pDataObject,
            /* [annotation][in] */ 
            _In_  BOOL fCreation,
            /* [annotation][in] */ 
            _In_  DWORD dwReserved);
        
        HRESULT ( STDMETHODCALLTYPE *GetClipboardData )( 
            __RPC__in IOleObject * This,
            /* [annotation][in] */ 
            _In_  DWORD dwReserved,
            /* [annotation][out] */ 
            _Out_  IDataObject **ppDataObject);
        
        HRESULT ( STDMETHODCALLTYPE *DoVerb )( 
            __RPC__in IOleObject * This,
            /* [annotation][in] */ 
            _In_  LONG iVerb,
            /* [annotation][unique][in] */ 
            _In_  LPMSG lpmsg,
            /* [annotation][unique][in] */ 
            _In_  IOleClientSite *pActiveSite,
            /* [annotation][in] */ 
            _In_  LONG lindex,
            /* [annotation][in] */ 
            _In_  HWND hwndParent,
            /* [annotation][unique][in] */ 
            _In_  LPCRECT lprcPosRect);
        
        HRESULT ( STDMETHODCALLTYPE *EnumVerbs )( 
            __RPC__in IOleObject * This,
            /* [annotation][out] */ 
            _Out_  IEnumOLEVERB **ppEnumOleVerb);
        
        HRESULT ( STDMETHODCALLTYPE *Update )( 
            __RPC__in IOleObject * This);
        
        HRESULT ( STDMETHODCALLTYPE *IsUpToDate )( 
            __RPC__in IOleObject * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetUserClassID )( 
            __RPC__in IOleObject * This,
            /* [annotation][out] */ 
            _Out_  CLSID *pClsid);
        
        HRESULT ( STDMETHODCALLTYPE *GetUserType )( 
            __RPC__in IOleObject * This,
            /* [annotation][in] */ 
            _In_  DWORD dwFormOfType,
            /* [annotation][out] */ 
            _Out_  LPOLESTR *pszUserType);
        
        HRESULT ( STDMETHODCALLTYPE *SetExtent )( 
            __RPC__in IOleObject * This,
            /* [annotation][in] */ 
            _In_  DWORD dwDrawAspect,
            /* [annotation][in] */ 
            _In_  SIZEL *psizel);
        
        HRESULT ( STDMETHODCALLTYPE *GetExtent )( 
            __RPC__in IOleObject * This,
            /* [annotation][in] */ 
            _In_  DWORD dwDrawAspect,
            /* [annotation][out] */ 
            _Out_  SIZEL *psizel);
        
        HRESULT ( STDMETHODCALLTYPE *Advise )( 
            __RPC__in IOleObject * This,
            /* [annotation][unique][in] */ 
            _In_  IAdviseSink *pAdvSink,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwConnection);
        
        HRESULT ( STDMETHODCALLTYPE *Unadvise )( 
            __RPC__in IOleObject * This,
            /* [annotation][in] */ 
            _In_  DWORD dwConnection);
        
        HRESULT ( STDMETHODCALLTYPE *EnumAdvise )( 
            __RPC__in IOleObject * This,
            /* [annotation][out] */ 
            _Out_  IEnumSTATDATA **ppenumAdvise);
        
        HRESULT ( STDMETHODCALLTYPE *GetMiscStatus )( 
            __RPC__in IOleObject * This,
            /* [annotation][in] */ 
            _In_  DWORD dwAspect,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwStatus);
        
        HRESULT ( STDMETHODCALLTYPE *SetColorScheme )( 
            __RPC__in IOleObject * This,
            /* [annotation][in] */ 
            _In_  LOGPALETTE *pLogpal);
        
        END_INTERFACE
    } IOleObjectVtbl;

    interface IOleObject
    {
        CONST_VTBL struct IOleObjectVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOleObject_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOleObject_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOleObject_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOleObject_SetClientSite(This,pClientSite)	\
    ( (This)->lpVtbl -> SetClientSite(This,pClientSite) ) 

#define IOleObject_GetClientSite(This,ppClientSite)	\
    ( (This)->lpVtbl -> GetClientSite(This,ppClientSite) ) 

#define IOleObject_SetHostNames(This,szContainerApp,szContainerObj)	\
    ( (This)->lpVtbl -> SetHostNames(This,szContainerApp,szContainerObj) ) 

#define IOleObject_Close(This,dwSaveOption)	\
    ( (This)->lpVtbl -> Close(This,dwSaveOption) ) 

#define IOleObject_SetMoniker(This,dwWhichMoniker,pmk)	\
    ( (This)->lpVtbl -> SetMoniker(This,dwWhichMoniker,pmk) ) 

#define IOleObject_GetMoniker(This,dwAssign,dwWhichMoniker,ppmk)	\
    ( (This)->lpVtbl -> GetMoniker(This,dwAssign,dwWhichMoniker,ppmk) ) 

#define IOleObject_InitFromData(This,pDataObject,fCreation,dwReserved)	\
    ( (This)->lpVtbl -> InitFromData(This,pDataObject,fCreation,dwReserved) ) 

#define IOleObject_GetClipboardData(This,dwReserved,ppDataObject)	\
    ( (This)->lpVtbl -> GetClipboardData(This,dwReserved,ppDataObject) ) 

#define IOleObject_DoVerb(This,iVerb,lpmsg,pActiveSite,lindex,hwndParent,lprcPosRect)	\
    ( (This)->lpVtbl -> DoVerb(This,iVerb,lpmsg,pActiveSite,lindex,hwndParent,lprcPosRect) ) 

#define IOleObject_EnumVerbs(This,ppEnumOleVerb)	\
    ( (This)->lpVtbl -> EnumVerbs(This,ppEnumOleVerb) ) 

#define IOleObject_Update(This)	\
    ( (This)->lpVtbl -> Update(This) ) 

#define IOleObject_IsUpToDate(This)	\
    ( (This)->lpVtbl -> IsUpToDate(This) ) 

#define IOleObject_GetUserClassID(This,pClsid)	\
    ( (This)->lpVtbl -> GetUserClassID(This,pClsid) ) 

#define IOleObject_GetUserType(This,dwFormOfType,pszUserType)	\
    ( (This)->lpVtbl -> GetUserType(This,dwFormOfType,pszUserType) ) 

#define IOleObject_SetExtent(This,dwDrawAspect,psizel)	\
    ( (This)->lpVtbl -> SetExtent(This,dwDrawAspect,psizel) ) 

#define IOleObject_GetExtent(This,dwDrawAspect,psizel)	\
    ( (This)->lpVtbl -> GetExtent(This,dwDrawAspect,psizel) ) 

#define IOleObject_Advise(This,pAdvSink,pdwConnection)	\
    ( (This)->lpVtbl -> Advise(This,pAdvSink,pdwConnection) ) 

#define IOleObject_Unadvise(This,dwConnection)	\
    ( (This)->lpVtbl -> Unadvise(This,dwConnection) ) 

#define IOleObject_EnumAdvise(This,ppenumAdvise)	\
    ( (This)->lpVtbl -> EnumAdvise(This,ppenumAdvise) ) 

#define IOleObject_GetMiscStatus(This,dwAspect,pdwStatus)	\
    ( (This)->lpVtbl -> GetMiscStatus(This,dwAspect,pdwStatus) ) 

#define IOleObject_SetColorScheme(This,pLogpal)	\
    ( (This)->lpVtbl -> SetColorScheme(This,pLogpal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOleObject_INTERFACE_DEFINED__ */


#ifndef __IOLETypes_INTERFACE_DEFINED__
#define __IOLETypes_INTERFACE_DEFINED__

/* interface IOLETypes */
/* [uuid] */ 

typedef 
enum tagOLERENDER
    {
        OLERENDER_NONE	= 0,
        OLERENDER_DRAW	= 1,
        OLERENDER_FORMAT	= 2,
        OLERENDER_ASIS	= 3
    } 	OLERENDER;

typedef OLERENDER *LPOLERENDER;

typedef struct tagOBJECTDESCRIPTOR
    {
    ULONG cbSize;
    CLSID clsid;
    DWORD dwDrawAspect;
    SIZEL sizel;
    POINTL pointl;
    DWORD dwStatus;
    DWORD dwFullUserTypeName;
    DWORD dwSrcOfCopy;
    } 	OBJECTDESCRIPTOR;

typedef struct tagOBJECTDESCRIPTOR *POBJECTDESCRIPTOR;

typedef struct tagOBJECTDESCRIPTOR *LPOBJECTDESCRIPTOR;

typedef struct tagOBJECTDESCRIPTOR LINKSRCDESCRIPTOR;

typedef struct tagOBJECTDESCRIPTOR *PLINKSRCDESCRIPTOR;

typedef struct tagOBJECTDESCRIPTOR *LPLINKSRCDESCRIPTOR;



extern RPC_IF_HANDLE IOLETypes_v0_0_c_ifspec;
extern RPC_IF_HANDLE IOLETypes_v0_0_s_ifspec;
#endif /* __IOLETypes_INTERFACE_DEFINED__ */

#ifndef __IOleWindow_INTERFACE_DEFINED__
#define __IOleWindow_INTERFACE_DEFINED__

/* interface IOleWindow */
/* [unique][uuid][object] */ 

typedef /* [unique] */  __RPC_unique_pointer IOleWindow *LPOLEWINDOW;


EXTERN_C const IID IID_IOleWindow;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("00000114-0000-0000-C000-000000000046")
    IOleWindow : public IUnknown
    {
    public:
        virtual /* [input_sync] */ HRESULT STDMETHODCALLTYPE GetWindow( 
            /* [annotation][out] */ 
            _Out_  HWND *phwnd) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ContextSensitiveHelp( 
            /* [annotation][in] */ 
            _In_  BOOL fEnterMode) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IOleWindowVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IOleWindow * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IOleWindow * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IOleWindow * This);
        
        /* [input_sync] */ HRESULT ( STDMETHODCALLTYPE *GetWindow )( 
            __RPC__in IOleWindow * This,
            /* [annotation][out] */ 
            _Out_  HWND *phwnd);
        
        HRESULT ( STDMETHODCALLTYPE *ContextSensitiveHelp )( 
            __RPC__in IOleWindow * This,
            /* [annotation][in] */ 
            _In_  BOOL fEnterMode);
        
        END_INTERFACE
    } IOleWindowVtbl;

    interface IOleWindow
    {
        CONST_VTBL struct IOleWindowVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOleWindow_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOleWindow_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOleWindow_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOleWindow_GetWindow(This,phwnd)	\
    ( (This)->lpVtbl -> GetWindow(This,phwnd) ) 

#define IOleWindow_ContextSensitiveHelp(This,fEnterMode)	\
    ( (This)->lpVtbl -> ContextSensitiveHelp(This,fEnterMode) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOleWindow_INTERFACE_DEFINED__ */


#ifndef __IOleLink_INTERFACE_DEFINED__
#define __IOleLink_INTERFACE_DEFINED__

/* interface IOleLink */
/* [uuid][object] */ 

typedef /* [unique] */  __RPC_unique_pointer IOleLink *LPOLELINK;

typedef 
enum tagOLEUPDATE
    {
        OLEUPDATE_ALWAYS	= 1,
        OLEUPDATE_ONCALL	= 3
    } 	OLEUPDATE;

typedef OLEUPDATE *LPOLEUPDATE;

typedef OLEUPDATE *POLEUPDATE;

typedef 
enum tagOLELINKBIND
    {
        OLELINKBIND_EVENIFCLASSDIFF	= 1
    } 	OLELINKBIND;


EXTERN_C const IID IID_IOleLink;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0000011d-0000-0000-C000-000000000046")
    IOleLink : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetUpdateOptions( 
            /* [annotation][in] */ 
            _In_  DWORD dwUpdateOpt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetUpdateOptions( 
            /* [annotation][out] */ 
            _Out_  DWORD *pdwUpdateOpt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetSourceMoniker( 
            /* [annotation][unique][in] */ 
            _In_  IMoniker *pmk,
            /* [annotation][in] */ 
            _In_  REFCLSID rclsid) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSourceMoniker( 
            /* [annotation][out] */ 
            _Out_  IMoniker **ppmk) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetSourceDisplayName( 
            /* [annotation][in] */ 
            _In_  LPCOLESTR pszStatusText) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSourceDisplayName( 
            /* [annotation][out] */ 
            _Out_  LPOLESTR *ppszDisplayName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE BindToSource( 
            /* [annotation][in] */ 
            _In_  DWORD bindflags,
            /* [annotation][unique][in] */ 
            _In_  IBindCtx *pbc) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE BindIfRunning( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBoundSource( 
            /* [annotation][out] */ 
            _Out_  IUnknown **ppunk) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UnbindSource( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Update( 
            /* [annotation][unique][in] */ 
            _In_  IBindCtx *pbc) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IOleLinkVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IOleLink * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IOleLink * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IOleLink * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetUpdateOptions )( 
            __RPC__in IOleLink * This,
            /* [annotation][in] */ 
            _In_  DWORD dwUpdateOpt);
        
        HRESULT ( STDMETHODCALLTYPE *GetUpdateOptions )( 
            __RPC__in IOleLink * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwUpdateOpt);
        
        HRESULT ( STDMETHODCALLTYPE *SetSourceMoniker )( 
            __RPC__in IOleLink * This,
            /* [annotation][unique][in] */ 
            _In_  IMoniker *pmk,
            /* [annotation][in] */ 
            _In_  REFCLSID rclsid);
        
        HRESULT ( STDMETHODCALLTYPE *GetSourceMoniker )( 
            __RPC__in IOleLink * This,
            /* [annotation][out] */ 
            _Out_  IMoniker **ppmk);
        
        HRESULT ( STDMETHODCALLTYPE *SetSourceDisplayName )( 
            __RPC__in IOleLink * This,
            /* [annotation][in] */ 
            _In_  LPCOLESTR pszStatusText);
        
        HRESULT ( STDMETHODCALLTYPE *GetSourceDisplayName )( 
            __RPC__in IOleLink * This,
            /* [annotation][out] */ 
            _Out_  LPOLESTR *ppszDisplayName);
        
        HRESULT ( STDMETHODCALLTYPE *BindToSource )( 
            __RPC__in IOleLink * This,
            /* [annotation][in] */ 
            _In_  DWORD bindflags,
            /* [annotation][unique][in] */ 
            _In_  IBindCtx *pbc);
        
        HRESULT ( STDMETHODCALLTYPE *BindIfRunning )( 
            __RPC__in IOleLink * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetBoundSource )( 
            __RPC__in IOleLink * This,
            /* [annotation][out] */ 
            _Out_  IUnknown **ppunk);
        
        HRESULT ( STDMETHODCALLTYPE *UnbindSource )( 
            __RPC__in IOleLink * This);
        
        HRESULT ( STDMETHODCALLTYPE *Update )( 
            __RPC__in IOleLink * This,
            /* [annotation][unique][in] */ 
            _In_  IBindCtx *pbc);
        
        END_INTERFACE
    } IOleLinkVtbl;

    interface IOleLink
    {
        CONST_VTBL struct IOleLinkVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOleLink_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOleLink_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOleLink_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOleLink_SetUpdateOptions(This,dwUpdateOpt)	\
    ( (This)->lpVtbl -> SetUpdateOptions(This,dwUpdateOpt) ) 

#define IOleLink_GetUpdateOptions(This,pdwUpdateOpt)	\
    ( (This)->lpVtbl -> GetUpdateOptions(This,pdwUpdateOpt) ) 

#define IOleLink_SetSourceMoniker(This,pmk,rclsid)	\
    ( (This)->lpVtbl -> SetSourceMoniker(This,pmk,rclsid) ) 

#define IOleLink_GetSourceMoniker(This,ppmk)	\
    ( (This)->lpVtbl -> GetSourceMoniker(This,ppmk) ) 

#define IOleLink_SetSourceDisplayName(This,pszStatusText)	\
    ( (This)->lpVtbl -> SetSourceDisplayName(This,pszStatusText) ) 

#define IOleLink_GetSourceDisplayName(This,ppszDisplayName)	\
    ( (This)->lpVtbl -> GetSourceDisplayName(This,ppszDisplayName) ) 

#define IOleLink_BindToSource(This,bindflags,pbc)	\
    ( (This)->lpVtbl -> BindToSource(This,bindflags,pbc) ) 

#define IOleLink_BindIfRunning(This)	\
    ( (This)->lpVtbl -> BindIfRunning(This) ) 

#define IOleLink_GetBoundSource(This,ppunk)	\
    ( (This)->lpVtbl -> GetBoundSource(This,ppunk) ) 

#define IOleLink_UnbindSource(This)	\
    ( (This)->lpVtbl -> UnbindSource(This) ) 

#define IOleLink_Update(This,pbc)	\
    ( (This)->lpVtbl -> Update(This,pbc) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOleLink_INTERFACE_DEFINED__ */


#ifndef __IOleItemContainer_INTERFACE_DEFINED__
#define __IOleItemContainer_INTERFACE_DEFINED__

/* interface IOleItemContainer */
/* [unique][uuid][object] */ 

typedef /* [unique] */  __RPC_unique_pointer IOleItemContainer *LPOLEITEMCONTAINER;

typedef 
enum tagBINDSPEED
    {
        BINDSPEED_INDEFINITE	= 1,
        BINDSPEED_MODERATE	= 2,
        BINDSPEED_IMMEDIATE	= 3
    } 	BINDSPEED;

typedef /* [v1_enum] */ 
enum tagOLECONTF
    {
        OLECONTF_EMBEDDINGS	= 1,
        OLECONTF_LINKS	= 2,
        OLECONTF_OTHERS	= 4,
        OLECONTF_ONLYUSER	= 8,
        OLECONTF_ONLYIFRUNNING	= 16
    } 	OLECONTF;


EXTERN_C const IID IID_IOleItemContainer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0000011c-0000-0000-C000-000000000046")
    IOleItemContainer : public IOleContainer
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetObject( 
            /* [annotation][in] */ 
            _In_  LPOLESTR pszItem,
            /* [annotation][in] */ 
            _In_  DWORD dwSpeedNeeded,
            /* [annotation][unique][in] */ 
            _In_  IBindCtx *pbc,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetObjectStorage( 
            /* [annotation][in] */ 
            _In_  LPOLESTR pszItem,
            /* [annotation][unique][in] */ 
            _In_  IBindCtx *pbc,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvStorage) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsRunning( 
            /* [annotation][in] */ 
            _In_  LPOLESTR pszItem) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IOleItemContainerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IOleItemContainer * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IOleItemContainer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IOleItemContainer * This);
        
        HRESULT ( STDMETHODCALLTYPE *ParseDisplayName )( 
            __RPC__in IOleItemContainer * This,
            /* [annotation][unique][in] */ 
            _In_  IBindCtx *pbc,
            /* [annotation][in] */ 
            _In_  LPOLESTR pszDisplayName,
            /* [annotation][out] */ 
            _Out_  ULONG *pchEaten,
            /* [annotation][out] */ 
            _Out_  IMoniker **ppmkOut);
        
        HRESULT ( STDMETHODCALLTYPE *EnumObjects )( 
            __RPC__in IOleItemContainer * This,
            /* [annotation][in] */ 
            _In_  DWORD grfFlags,
            /* [annotation][out] */ 
            _Out_  IEnumUnknown **ppenum);
        
        HRESULT ( STDMETHODCALLTYPE *LockContainer )( 
            __RPC__in IOleItemContainer * This,
            /* [annotation][in] */ 
            _In_  BOOL fLock);
        
        HRESULT ( STDMETHODCALLTYPE *GetObject )( 
            __RPC__in IOleItemContainer * This,
            /* [annotation][in] */ 
            _In_  LPOLESTR pszItem,
            /* [annotation][in] */ 
            _In_  DWORD dwSpeedNeeded,
            /* [annotation][unique][in] */ 
            _In_  IBindCtx *pbc,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        HRESULT ( STDMETHODCALLTYPE *GetObjectStorage )( 
            __RPC__in IOleItemContainer * This,
            /* [annotation][in] */ 
            _In_  LPOLESTR pszItem,
            /* [annotation][unique][in] */ 
            _In_  IBindCtx *pbc,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvStorage);
        
        HRESULT ( STDMETHODCALLTYPE *IsRunning )( 
            __RPC__in IOleItemContainer * This,
            /* [annotation][in] */ 
            _In_  LPOLESTR pszItem);
        
        END_INTERFACE
    } IOleItemContainerVtbl;

    interface IOleItemContainer
    {
        CONST_VTBL struct IOleItemContainerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOleItemContainer_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOleItemContainer_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOleItemContainer_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOleItemContainer_ParseDisplayName(This,pbc,pszDisplayName,pchEaten,ppmkOut)	\
    ( (This)->lpVtbl -> ParseDisplayName(This,pbc,pszDisplayName,pchEaten,ppmkOut) ) 


#define IOleItemContainer_EnumObjects(This,grfFlags,ppenum)	\
    ( (This)->lpVtbl -> EnumObjects(This,grfFlags,ppenum) ) 

#define IOleItemContainer_LockContainer(This,fLock)	\
    ( (This)->lpVtbl -> LockContainer(This,fLock) ) 


#define IOleItemContainer_GetObject(This,pszItem,dwSpeedNeeded,pbc,riid,ppvObject)	\
    ( (This)->lpVtbl -> GetObject(This,pszItem,dwSpeedNeeded,pbc,riid,ppvObject) ) 

#define IOleItemContainer_GetObjectStorage(This,pszItem,pbc,riid,ppvStorage)	\
    ( (This)->lpVtbl -> GetObjectStorage(This,pszItem,pbc,riid,ppvStorage) ) 

#define IOleItemContainer_IsRunning(This,pszItem)	\
    ( (This)->lpVtbl -> IsRunning(This,pszItem) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOleItemContainer_INTERFACE_DEFINED__ */


#ifndef __IOleInPlaceUIWindow_INTERFACE_DEFINED__
#define __IOleInPlaceUIWindow_INTERFACE_DEFINED__

/* interface IOleInPlaceUIWindow */
/* [unique][uuid][object] */ 

typedef /* [unique] */  __RPC_unique_pointer IOleInPlaceUIWindow *LPOLEINPLACEUIWINDOW;

typedef RECT BORDERWIDTHS;

typedef LPRECT LPBORDERWIDTHS;

typedef LPCRECT LPCBORDERWIDTHS;


EXTERN_C const IID IID_IOleInPlaceUIWindow;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("00000115-0000-0000-C000-000000000046")
    IOleInPlaceUIWindow : public IOleWindow
    {
    public:
        virtual /* [input_sync] */ HRESULT STDMETHODCALLTYPE GetBorder( 
            /* [annotation][out] */ 
            _Out_  LPRECT lprectBorder) = 0;
        
        virtual /* [input_sync] */ HRESULT STDMETHODCALLTYPE RequestBorderSpace( 
            /* [annotation][unique][in] */ 
            _In_  LPCBORDERWIDTHS pborderwidths) = 0;
        
        virtual /* [input_sync] */ HRESULT STDMETHODCALLTYPE SetBorderSpace( 
            /* [annotation][unique][in] */ 
            _In_  LPCBORDERWIDTHS pborderwidths) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetActiveObject( 
            /* [annotation][unique][in] */ 
            _In_  IOleInPlaceActiveObject *pActiveObject,
            /* [annotation][unique][string][in] */ 
            _In_  LPCOLESTR pszObjName) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IOleInPlaceUIWindowVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IOleInPlaceUIWindow * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IOleInPlaceUIWindow * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IOleInPlaceUIWindow * This);
        
        /* [input_sync] */ HRESULT ( STDMETHODCALLTYPE *GetWindow )( 
            __RPC__in IOleInPlaceUIWindow * This,
            /* [annotation][out] */ 
            _Out_  HWND *phwnd);
        
        HRESULT ( STDMETHODCALLTYPE *ContextSensitiveHelp )( 
            __RPC__in IOleInPlaceUIWindow * This,
            /* [annotation][in] */ 
            _In_  BOOL fEnterMode);
        
        /* [input_sync] */ HRESULT ( STDMETHODCALLTYPE *GetBorder )( 
            __RPC__in IOleInPlaceUIWindow * This,
            /* [annotation][out] */ 
            _Out_  LPRECT lprectBorder);
        
        /* [input_sync] */ HRESULT ( STDMETHODCALLTYPE *RequestBorderSpace )( 
            __RPC__in IOleInPlaceUIWindow * This,
            /* [annotation][unique][in] */ 
            _In_  LPCBORDERWIDTHS pborderwidths);
        
        /* [input_sync] */ HRESULT ( STDMETHODCALLTYPE *SetBorderSpace )( 
            __RPC__in IOleInPlaceUIWindow * This,
            /* [annotation][unique][in] */ 
            _In_  LPCBORDERWIDTHS pborderwidths);
        
        HRESULT ( STDMETHODCALLTYPE *SetActiveObject )( 
            __RPC__in IOleInPlaceUIWindow * This,
            /* [annotation][unique][in] */ 
            _In_  IOleInPlaceActiveObject *pActiveObject,
            /* [annotation][unique][string][in] */ 
            _In_  LPCOLESTR pszObjName);
        
        END_INTERFACE
    } IOleInPlaceUIWindowVtbl;

    interface IOleInPlaceUIWindow
    {
        CONST_VTBL struct IOleInPlaceUIWindowVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOleInPlaceUIWindow_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOleInPlaceUIWindow_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOleInPlaceUIWindow_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOleInPlaceUIWindow_GetWindow(This,phwnd)	\
    ( (This)->lpVtbl -> GetWindow(This,phwnd) ) 

#define IOleInPlaceUIWindow_ContextSensitiveHelp(This,fEnterMode)	\
    ( (This)->lpVtbl -> ContextSensitiveHelp(This,fEnterMode) ) 


#define IOleInPlaceUIWindow_GetBorder(This,lprectBorder)	\
    ( (This)->lpVtbl -> GetBorder(This,lprectBorder) ) 

#define IOleInPlaceUIWindow_RequestBorderSpace(This,pborderwidths)	\
    ( (This)->lpVtbl -> RequestBorderSpace(This,pborderwidths) ) 

#define IOleInPlaceUIWindow_SetBorderSpace(This,pborderwidths)	\
    ( (This)->lpVtbl -> SetBorderSpace(This,pborderwidths) ) 

#define IOleInPlaceUIWindow_SetActiveObject(This,pActiveObject,pszObjName)	\
    ( (This)->lpVtbl -> SetActiveObject(This,pActiveObject,pszObjName) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOleInPlaceUIWindow_INTERFACE_DEFINED__ */


#ifndef __IOleInPlaceActiveObject_INTERFACE_DEFINED__
#define __IOleInPlaceActiveObject_INTERFACE_DEFINED__

/* interface IOleInPlaceActiveObject */
/* [uuid][object] */ 

typedef /* [unique] */  __RPC_unique_pointer IOleInPlaceActiveObject *LPOLEINPLACEACTIVEOBJECT;


EXTERN_C const IID IID_IOleInPlaceActiveObject;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("00000117-0000-0000-C000-000000000046")
    IOleInPlaceActiveObject : public IOleWindow
    {
    public:
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE TranslateAccelerator( 
            /* [annotation][in] */ 
            _In_opt_  LPMSG lpmsg) = 0;
        
        virtual /* [input_sync] */ HRESULT STDMETHODCALLTYPE OnFrameWindowActivate( 
            /* [annotation][in] */ 
            _In_  BOOL fActivate) = 0;
        
        virtual /* [input_sync] */ HRESULT STDMETHODCALLTYPE OnDocWindowActivate( 
            /* [annotation][in] */ 
            _In_  BOOL fActivate) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE ResizeBorder( 
            /* [annotation][in] */ 
            _In_  LPCRECT prcBorder,
            /* [annotation][unique][in] */ 
            _In_  IOleInPlaceUIWindow *pUIWindow,
            /* [annotation][in] */ 
            _In_  BOOL fFrameWindow) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnableModeless( 
            /* [annotation][in] */ 
            _In_  BOOL fEnable) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IOleInPlaceActiveObjectVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IOleInPlaceActiveObject * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IOleInPlaceActiveObject * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IOleInPlaceActiveObject * This);
        
        /* [input_sync] */ HRESULT ( STDMETHODCALLTYPE *GetWindow )( 
            __RPC__in IOleInPlaceActiveObject * This,
            /* [annotation][out] */ 
            _Out_  HWND *phwnd);
        
        HRESULT ( STDMETHODCALLTYPE *ContextSensitiveHelp )( 
            __RPC__in IOleInPlaceActiveObject * This,
            /* [annotation][in] */ 
            _In_  BOOL fEnterMode);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *TranslateAccelerator )( 
            IOleInPlaceActiveObject * This,
            /* [annotation][in] */ 
            _In_opt_  LPMSG lpmsg);
        
        /* [input_sync] */ HRESULT ( STDMETHODCALLTYPE *OnFrameWindowActivate )( 
            __RPC__in IOleInPlaceActiveObject * This,
            /* [annotation][in] */ 
            _In_  BOOL fActivate);
        
        /* [input_sync] */ HRESULT ( STDMETHODCALLTYPE *OnDocWindowActivate )( 
            __RPC__in IOleInPlaceActiveObject * This,
            /* [annotation][in] */ 
            _In_  BOOL fActivate);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *ResizeBorder )( 
            IOleInPlaceActiveObject * This,
            /* [annotation][in] */ 
            _In_  LPCRECT prcBorder,
            /* [annotation][unique][in] */ 
            _In_  IOleInPlaceUIWindow *pUIWindow,
            /* [annotation][in] */ 
            _In_  BOOL fFrameWindow);
        
        HRESULT ( STDMETHODCALLTYPE *EnableModeless )( 
            __RPC__in IOleInPlaceActiveObject * This,
            /* [annotation][in] */ 
            _In_  BOOL fEnable);
        
        END_INTERFACE
    } IOleInPlaceActiveObjectVtbl;

    interface IOleInPlaceActiveObject
    {
        CONST_VTBL struct IOleInPlaceActiveObjectVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOleInPlaceActiveObject_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOleInPlaceActiveObject_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOleInPlaceActiveObject_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOleInPlaceActiveObject_GetWindow(This,phwnd)	\
    ( (This)->lpVtbl -> GetWindow(This,phwnd) ) 

#define IOleInPlaceActiveObject_ContextSensitiveHelp(This,fEnterMode)	\
    ( (This)->lpVtbl -> ContextSensitiveHelp(This,fEnterMode) ) 


#define IOleInPlaceActiveObject_TranslateAccelerator(This,lpmsg)	\
    ( (This)->lpVtbl -> TranslateAccelerator(This,lpmsg) ) 

#define IOleInPlaceActiveObject_OnFrameWindowActivate(This,fActivate)	\
    ( (This)->lpVtbl -> OnFrameWindowActivate(This,fActivate) ) 

#define IOleInPlaceActiveObject_OnDocWindowActivate(This,fActivate)	\
    ( (This)->lpVtbl -> OnDocWindowActivate(This,fActivate) ) 

#define IOleInPlaceActiveObject_ResizeBorder(This,prcBorder,pUIWindow,fFrameWindow)	\
    ( (This)->lpVtbl -> ResizeBorder(This,prcBorder,pUIWindow,fFrameWindow) ) 

#define IOleInPlaceActiveObject_EnableModeless(This,fEnable)	\
    ( (This)->lpVtbl -> EnableModeless(This,fEnable) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT STDMETHODCALLTYPE IOleInPlaceActiveObject_RemoteTranslateAccelerator_Proxy( 
    __RPC__in IOleInPlaceActiveObject * This);


void __RPC_STUB IOleInPlaceActiveObject_RemoteTranslateAccelerator_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [input_sync][call_as] */ HRESULT STDMETHODCALLTYPE IOleInPlaceActiveObject_RemoteResizeBorder_Proxy( 
    __RPC__in IOleInPlaceActiveObject * This,
    /* [annotation][in] */ 
    _In_  LPCRECT prcBorder,
    /* [annotation][in] */ 
    _In_  REFIID riid,
    /* [annotation][iid_is][unique][in] */ 
    _In_  IOleInPlaceUIWindow *pUIWindow,
    /* [annotation][in] */ 
    _In_  BOOL fFrameWindow);


void __RPC_STUB IOleInPlaceActiveObject_RemoteResizeBorder_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IOleInPlaceActiveObject_INTERFACE_DEFINED__ */


#ifndef __IOleInPlaceFrame_INTERFACE_DEFINED__
#define __IOleInPlaceFrame_INTERFACE_DEFINED__

/* interface IOleInPlaceFrame */
/* [unique][uuid][object] */ 

typedef /* [unique] */  __RPC_unique_pointer IOleInPlaceFrame *LPOLEINPLACEFRAME;

typedef struct tagOIFI
    {
    UINT cb;
    BOOL fMDIApp;
    HWND hwndFrame;
    HACCEL haccel;
    UINT cAccelEntries;
    } 	OLEINPLACEFRAMEINFO;

typedef struct tagOIFI *LPOLEINPLACEFRAMEINFO;

typedef struct tagOleMenuGroupWidths
    {
    LONG width[ 6 ];
    } 	OLEMENUGROUPWIDTHS;

typedef struct tagOleMenuGroupWidths *LPOLEMENUGROUPWIDTHS;

typedef HGLOBAL HOLEMENU;


EXTERN_C const IID IID_IOleInPlaceFrame;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("00000116-0000-0000-C000-000000000046")
    IOleInPlaceFrame : public IOleInPlaceUIWindow
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE InsertMenus( 
            /* [annotation][in] */ 
            _In_  HMENU hmenuShared,
            /* [annotation][out][in] */ 
            _Inout_  LPOLEMENUGROUPWIDTHS lpMenuWidths) = 0;
        
        virtual /* [input_sync] */ HRESULT STDMETHODCALLTYPE SetMenu( 
            /* [annotation][in] */ 
            _In_  HMENU hmenuShared,
            /* [annotation][in] */ 
            _In_  HOLEMENU holemenu,
            /* [annotation][in] */ 
            _In_  HWND hwndActiveObject) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveMenus( 
            /* [annotation][in] */ 
            _In_  HMENU hmenuShared) = 0;
        
        virtual /* [input_sync] */ HRESULT STDMETHODCALLTYPE SetStatusText( 
            /* [annotation][unique][in] */ 
            _In_  LPCOLESTR pszStatusText) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnableModeless( 
            /* [annotation][in] */ 
            _In_  BOOL fEnable) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE TranslateAccelerator( 
            /* [annotation][in] */ 
            _In_  LPMSG lpmsg,
            /* [annotation][in] */ 
            _In_  WORD wID) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IOleInPlaceFrameVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IOleInPlaceFrame * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IOleInPlaceFrame * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IOleInPlaceFrame * This);
        
        /* [input_sync] */ HRESULT ( STDMETHODCALLTYPE *GetWindow )( 
            __RPC__in IOleInPlaceFrame * This,
            /* [annotation][out] */ 
            _Out_  HWND *phwnd);
        
        HRESULT ( STDMETHODCALLTYPE *ContextSensitiveHelp )( 
            __RPC__in IOleInPlaceFrame * This,
            /* [annotation][in] */ 
            _In_  BOOL fEnterMode);
        
        /* [input_sync] */ HRESULT ( STDMETHODCALLTYPE *GetBorder )( 
            __RPC__in IOleInPlaceFrame * This,
            /* [annotation][out] */ 
            _Out_  LPRECT lprectBorder);
        
        /* [input_sync] */ HRESULT ( STDMETHODCALLTYPE *RequestBorderSpace )( 
            __RPC__in IOleInPlaceFrame * This,
            /* [annotation][unique][in] */ 
            _In_  LPCBORDERWIDTHS pborderwidths);
        
        /* [input_sync] */ HRESULT ( STDMETHODCALLTYPE *SetBorderSpace )( 
            __RPC__in IOleInPlaceFrame * This,
            /* [annotation][unique][in] */ 
            _In_  LPCBORDERWIDTHS pborderwidths);
        
        HRESULT ( STDMETHODCALLTYPE *SetActiveObject )( 
            __RPC__in IOleInPlaceFrame * This,
            /* [annotation][unique][in] */ 
            _In_  IOleInPlaceActiveObject *pActiveObject,
            /* [annotation][unique][string][in] */ 
            _In_  LPCOLESTR pszObjName);
        
        HRESULT ( STDMETHODCALLTYPE *InsertMenus )( 
            __RPC__in IOleInPlaceFrame * This,
            /* [annotation][in] */ 
            _In_  HMENU hmenuShared,
            /* [annotation][out][in] */ 
            _Inout_  LPOLEMENUGROUPWIDTHS lpMenuWidths);
        
        /* [input_sync] */ HRESULT ( STDMETHODCALLTYPE *SetMenu )( 
            __RPC__in IOleInPlaceFrame * This,
            /* [annotation][in] */ 
            _In_  HMENU hmenuShared,
            /* [annotation][in] */ 
            _In_  HOLEMENU holemenu,
            /* [annotation][in] */ 
            _In_  HWND hwndActiveObject);
        
        HRESULT ( STDMETHODCALLTYPE *RemoveMenus )( 
            __RPC__in IOleInPlaceFrame * This,
            /* [annotation][in] */ 
            _In_  HMENU hmenuShared);
        
        /* [input_sync] */ HRESULT ( STDMETHODCALLTYPE *SetStatusText )( 
            __RPC__in IOleInPlaceFrame * This,
            /* [annotation][unique][in] */ 
            _In_  LPCOLESTR pszStatusText);
        
        HRESULT ( STDMETHODCALLTYPE *EnableModeless )( 
            __RPC__in IOleInPlaceFrame * This,
            /* [annotation][in] */ 
            _In_  BOOL fEnable);
        
        HRESULT ( STDMETHODCALLTYPE *TranslateAccelerator )( 
            __RPC__in IOleInPlaceFrame * This,
            /* [annotation][in] */ 
            _In_  LPMSG lpmsg,
            /* [annotation][in] */ 
            _In_  WORD wID);
        
        END_INTERFACE
    } IOleInPlaceFrameVtbl;

    interface IOleInPlaceFrame
    {
        CONST_VTBL struct IOleInPlaceFrameVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOleInPlaceFrame_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOleInPlaceFrame_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOleInPlaceFrame_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOleInPlaceFrame_GetWindow(This,phwnd)	\
    ( (This)->lpVtbl -> GetWindow(This,phwnd) ) 

#define IOleInPlaceFrame_ContextSensitiveHelp(This,fEnterMode)	\
    ( (This)->lpVtbl -> ContextSensitiveHelp(This,fEnterMode) ) 


#define IOleInPlaceFrame_GetBorder(This,lprectBorder)	\
    ( (This)->lpVtbl -> GetBorder(This,lprectBorder) ) 

#define IOleInPlaceFrame_RequestBorderSpace(This,pborderwidths)	\
    ( (This)->lpVtbl -> RequestBorderSpace(This,pborderwidths) ) 

#define IOleInPlaceFrame_SetBorderSpace(This,pborderwidths)	\
    ( (This)->lpVtbl -> SetBorderSpace(This,pborderwidths) ) 

#define IOleInPlaceFrame_SetActiveObject(This,pActiveObject,pszObjName)	\
    ( (This)->lpVtbl -> SetActiveObject(This,pActiveObject,pszObjName) ) 


#define IOleInPlaceFrame_InsertMenus(This,hmenuShared,lpMenuWidths)	\
    ( (This)->lpVtbl -> InsertMenus(This,hmenuShared,lpMenuWidths) ) 

#define IOleInPlaceFrame_SetMenu(This,hmenuShared,holemenu,hwndActiveObject)	\
    ( (This)->lpVtbl -> SetMenu(This,hmenuShared,holemenu,hwndActiveObject) ) 

#define IOleInPlaceFrame_RemoveMenus(This,hmenuShared)	\
    ( (This)->lpVtbl -> RemoveMenus(This,hmenuShared) ) 

#define IOleInPlaceFrame_SetStatusText(This,pszStatusText)	\
    ( (This)->lpVtbl -> SetStatusText(This,pszStatusText) ) 

#define IOleInPlaceFrame_EnableModeless(This,fEnable)	\
    ( (This)->lpVtbl -> EnableModeless(This,fEnable) ) 

#define IOleInPlaceFrame_TranslateAccelerator(This,lpmsg,wID)	\
    ( (This)->lpVtbl -> TranslateAccelerator(This,lpmsg,wID) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOleInPlaceFrame_INTERFACE_DEFINED__ */


#ifndef __IOleInPlaceObject_INTERFACE_DEFINED__
#define __IOleInPlaceObject_INTERFACE_DEFINED__

/* interface IOleInPlaceObject */
/* [unique][uuid][object] */ 

typedef /* [unique] */  __RPC_unique_pointer IOleInPlaceObject *LPOLEINPLACEOBJECT;


EXTERN_C const IID IID_IOleInPlaceObject;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("00000113-0000-0000-C000-000000000046")
    IOleInPlaceObject : public IOleWindow
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE InPlaceDeactivate( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UIDeactivate( void) = 0;
        
        virtual /* [input_sync] */ HRESULT STDMETHODCALLTYPE SetObjectRects( 
            /* [annotation][in] */ 
            _In_  LPCRECT lprcPosRect,
            /* [annotation][in] */ 
            _In_  LPCRECT lprcClipRect) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReactivateAndUndo( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IOleInPlaceObjectVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IOleInPlaceObject * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IOleInPlaceObject * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IOleInPlaceObject * This);
        
        /* [input_sync] */ HRESULT ( STDMETHODCALLTYPE *GetWindow )( 
            __RPC__in IOleInPlaceObject * This,
            /* [annotation][out] */ 
            _Out_  HWND *phwnd);
        
        HRESULT ( STDMETHODCALLTYPE *ContextSensitiveHelp )( 
            __RPC__in IOleInPlaceObject * This,
            /* [annotation][in] */ 
            _In_  BOOL fEnterMode);
        
        HRESULT ( STDMETHODCALLTYPE *InPlaceDeactivate )( 
            __RPC__in IOleInPlaceObject * This);
        
        HRESULT ( STDMETHODCALLTYPE *UIDeactivate )( 
            __RPC__in IOleInPlaceObject * This);
        
        /* [input_sync] */ HRESULT ( STDMETHODCALLTYPE *SetObjectRects )( 
            __RPC__in IOleInPlaceObject * This,
            /* [annotation][in] */ 
            _In_  LPCRECT lprcPosRect,
            /* [annotation][in] */ 
            _In_  LPCRECT lprcClipRect);
        
        HRESULT ( STDMETHODCALLTYPE *ReactivateAndUndo )( 
            __RPC__in IOleInPlaceObject * This);
        
        END_INTERFACE
    } IOleInPlaceObjectVtbl;

    interface IOleInPlaceObject
    {
        CONST_VTBL struct IOleInPlaceObjectVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOleInPlaceObject_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOleInPlaceObject_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOleInPlaceObject_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOleInPlaceObject_GetWindow(This,phwnd)	\
    ( (This)->lpVtbl -> GetWindow(This,phwnd) ) 

#define IOleInPlaceObject_ContextSensitiveHelp(This,fEnterMode)	\
    ( (This)->lpVtbl -> ContextSensitiveHelp(This,fEnterMode) ) 


#define IOleInPlaceObject_InPlaceDeactivate(This)	\
    ( (This)->lpVtbl -> InPlaceDeactivate(This) ) 

#define IOleInPlaceObject_UIDeactivate(This)	\
    ( (This)->lpVtbl -> UIDeactivate(This) ) 

#define IOleInPlaceObject_SetObjectRects(This,lprcPosRect,lprcClipRect)	\
    ( (This)->lpVtbl -> SetObjectRects(This,lprcPosRect,lprcClipRect) ) 

#define IOleInPlaceObject_ReactivateAndUndo(This)	\
    ( (This)->lpVtbl -> ReactivateAndUndo(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOleInPlaceObject_INTERFACE_DEFINED__ */


#ifndef __IOleInPlaceSite_INTERFACE_DEFINED__
#define __IOleInPlaceSite_INTERFACE_DEFINED__

/* interface IOleInPlaceSite */
/* [unique][uuid][object] */ 

typedef /* [unique] */  __RPC_unique_pointer IOleInPlaceSite *LPOLEINPLACESITE;


EXTERN_C const IID IID_IOleInPlaceSite;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("00000119-0000-0000-C000-000000000046")
    IOleInPlaceSite : public IOleWindow
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CanInPlaceActivate( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnInPlaceActivate( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnUIActivate( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetWindowContext( 
            /* [annotation][out] */ 
            _Out_  IOleInPlaceFrame **ppFrame,
            /* [annotation][out] */ 
            _Out_  IOleInPlaceUIWindow **ppDoc,
            /* [annotation][out] */ 
            _Out_  LPRECT lprcPosRect,
            /* [annotation][out] */ 
            _Out_  LPRECT lprcClipRect,
            /* [annotation][out][in] */ 
            _Inout_  LPOLEINPLACEFRAMEINFO lpFrameInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Scroll( 
            /* [annotation][in] */ 
            _In_  SIZE scrollExtant) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnUIDeactivate( 
            /* [annotation][in] */ 
            _In_  BOOL fUndoable) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnInPlaceDeactivate( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DiscardUndoState( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DeactivateAndUndo( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnPosRectChange( 
            /* [annotation][in] */ 
            _In_  LPCRECT lprcPosRect) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IOleInPlaceSiteVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IOleInPlaceSite * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IOleInPlaceSite * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IOleInPlaceSite * This);
        
        /* [input_sync] */ HRESULT ( STDMETHODCALLTYPE *GetWindow )( 
            __RPC__in IOleInPlaceSite * This,
            /* [annotation][out] */ 
            _Out_  HWND *phwnd);
        
        HRESULT ( STDMETHODCALLTYPE *ContextSensitiveHelp )( 
            __RPC__in IOleInPlaceSite * This,
            /* [annotation][in] */ 
            _In_  BOOL fEnterMode);
        
        HRESULT ( STDMETHODCALLTYPE *CanInPlaceActivate )( 
            __RPC__in IOleInPlaceSite * This);
        
        HRESULT ( STDMETHODCALLTYPE *OnInPlaceActivate )( 
            __RPC__in IOleInPlaceSite * This);
        
        HRESULT ( STDMETHODCALLTYPE *OnUIActivate )( 
            __RPC__in IOleInPlaceSite * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetWindowContext )( 
            __RPC__in IOleInPlaceSite * This,
            /* [annotation][out] */ 
            _Out_  IOleInPlaceFrame **ppFrame,
            /* [annotation][out] */ 
            _Out_  IOleInPlaceUIWindow **ppDoc,
            /* [annotation][out] */ 
            _Out_  LPRECT lprcPosRect,
            /* [annotation][out] */ 
            _Out_  LPRECT lprcClipRect,
            /* [annotation][out][in] */ 
            _Inout_  LPOLEINPLACEFRAMEINFO lpFrameInfo);
        
        HRESULT ( STDMETHODCALLTYPE *Scroll )( 
            __RPC__in IOleInPlaceSite * This,
            /* [annotation][in] */ 
            _In_  SIZE scrollExtant);
        
        HRESULT ( STDMETHODCALLTYPE *OnUIDeactivate )( 
            __RPC__in IOleInPlaceSite * This,
            /* [annotation][in] */ 
            _In_  BOOL fUndoable);
        
        HRESULT ( STDMETHODCALLTYPE *OnInPlaceDeactivate )( 
            __RPC__in IOleInPlaceSite * This);
        
        HRESULT ( STDMETHODCALLTYPE *DiscardUndoState )( 
            __RPC__in IOleInPlaceSite * This);
        
        HRESULT ( STDMETHODCALLTYPE *DeactivateAndUndo )( 
            __RPC__in IOleInPlaceSite * This);
        
        HRESULT ( STDMETHODCALLTYPE *OnPosRectChange )( 
            __RPC__in IOleInPlaceSite * This,
            /* [annotation][in] */ 
            _In_  LPCRECT lprcPosRect);
        
        END_INTERFACE
    } IOleInPlaceSiteVtbl;

    interface IOleInPlaceSite
    {
        CONST_VTBL struct IOleInPlaceSiteVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOleInPlaceSite_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOleInPlaceSite_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOleInPlaceSite_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOleInPlaceSite_GetWindow(This,phwnd)	\
    ( (This)->lpVtbl -> GetWindow(This,phwnd) ) 

#define IOleInPlaceSite_ContextSensitiveHelp(This,fEnterMode)	\
    ( (This)->lpVtbl -> ContextSensitiveHelp(This,fEnterMode) ) 


#define IOleInPlaceSite_CanInPlaceActivate(This)	\
    ( (This)->lpVtbl -> CanInPlaceActivate(This) ) 

#define IOleInPlaceSite_OnInPlaceActivate(This)	\
    ( (This)->lpVtbl -> OnInPlaceActivate(This) ) 

#define IOleInPlaceSite_OnUIActivate(This)	\
    ( (This)->lpVtbl -> OnUIActivate(This) ) 

#define IOleInPlaceSite_GetWindowContext(This,ppFrame,ppDoc,lprcPosRect,lprcClipRect,lpFrameInfo)	\
    ( (This)->lpVtbl -> GetWindowContext(This,ppFrame,ppDoc,lprcPosRect,lprcClipRect,lpFrameInfo) ) 

#define IOleInPlaceSite_Scroll(This,scrollExtant)	\
    ( (This)->lpVtbl -> Scroll(This,scrollExtant) ) 

#define IOleInPlaceSite_OnUIDeactivate(This,fUndoable)	\
    ( (This)->lpVtbl -> OnUIDeactivate(This,fUndoable) ) 

#define IOleInPlaceSite_OnInPlaceDeactivate(This)	\
    ( (This)->lpVtbl -> OnInPlaceDeactivate(This) ) 

#define IOleInPlaceSite_DiscardUndoState(This)	\
    ( (This)->lpVtbl -> DiscardUndoState(This) ) 

#define IOleInPlaceSite_DeactivateAndUndo(This)	\
    ( (This)->lpVtbl -> DeactivateAndUndo(This) ) 

#define IOleInPlaceSite_OnPosRectChange(This,lprcPosRect)	\
    ( (This)->lpVtbl -> OnPosRectChange(This,lprcPosRect) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOleInPlaceSite_INTERFACE_DEFINED__ */


#ifndef __IContinue_INTERFACE_DEFINED__
#define __IContinue_INTERFACE_DEFINED__

/* interface IContinue */
/* [uuid][object] */ 


EXTERN_C const IID IID_IContinue;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0000012a-0000-0000-C000-000000000046")
    IContinue : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE FContinue( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IContinueVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IContinue * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IContinue * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IContinue * This);
        
        HRESULT ( STDMETHODCALLTYPE *FContinue )( 
            __RPC__in IContinue * This);
        
        END_INTERFACE
    } IContinueVtbl;

    interface IContinue
    {
        CONST_VTBL struct IContinueVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IContinue_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IContinue_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IContinue_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IContinue_FContinue(This)	\
    ( (This)->lpVtbl -> FContinue(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IContinue_INTERFACE_DEFINED__ */


#ifndef __IViewObject_INTERFACE_DEFINED__
#define __IViewObject_INTERFACE_DEFINED__

/* interface IViewObject */
/* [uuid][object] */ 

typedef /* [unique] */  __RPC_unique_pointer IViewObject *LPVIEWOBJECT;


EXTERN_C const IID IID_IViewObject;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0000010d-0000-0000-C000-000000000046")
    IViewObject : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE Draw( 
            /* [annotation][in] */ 
            _In_  DWORD dwDrawAspect,
            /* [annotation][in] */ 
            _In_  LONG lindex,
            /* [annotation][unique][in] */ 
            _Null_  void *pvAspect,
            /* [annotation][unique][in] */ 
            _In_opt_  DVTARGETDEVICE *ptd,
            /* [annotation][in] */ 
            _In_opt_  HDC hdcTargetDev,
            /* [annotation][in] */ 
            _In_  HDC hdcDraw,
            /* [annotation][in] */ 
            _In_opt_  LPCRECTL lprcBounds,
            /* [annotation][unique][in] */ 
            _In_opt_  LPCRECTL lprcWBounds,
            /* [annotation][in] */ 
            _In_opt_  BOOL ( STDMETHODCALLTYPE *pfnContinue )( 
                ULONG_PTR dwContinue),
            /* [annotation][in] */ 
            _In_  ULONG_PTR dwContinue) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE GetColorSet( 
            /* [annotation][in] */ 
            _In_  DWORD dwDrawAspect,
            /* [annotation][in] */ 
            _In_  LONG lindex,
            /* [annotation][unique][in] */ 
            _Null_  void *pvAspect,
            /* [annotation][unique][in] */ 
            _In_opt_  DVTARGETDEVICE *ptd,
            /* [annotation][in] */ 
            _In_opt_  HDC hicTargetDev,
            /* [annotation][out] */ 
            _Outptr_  LOGPALETTE **ppColorSet) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE Freeze( 
            /* [annotation][in] */ 
            _In_  DWORD dwDrawAspect,
            /* [annotation][in] */ 
            _In_  LONG lindex,
            /* [annotation][unique][in] */ 
            _Null_  void *pvAspect,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwFreeze) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Unfreeze( 
            /* [annotation][in] */ 
            _In_  DWORD dwFreeze) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAdvise( 
            /* [annotation][in] */ 
            _In_  DWORD aspects,
            /* [annotation][in] */ 
            _In_  DWORD advf,
            /* [annotation][unique][in] */ 
            _In_  IAdviseSink *pAdvSink) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE GetAdvise( 
            /* [annotation][unique][out] */ 
            _Out_opt_  DWORD *pAspects,
            /* [annotation][unique][out] */ 
            _Out_opt_  DWORD *pAdvf,
            /* [annotation][out] */ 
            _Outptr_  IAdviseSink **ppAdvSink) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IViewObjectVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IViewObject * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IViewObject * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IViewObject * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Draw )( 
            IViewObject * This,
            /* [annotation][in] */ 
            _In_  DWORD dwDrawAspect,
            /* [annotation][in] */ 
            _In_  LONG lindex,
            /* [annotation][unique][in] */ 
            _Null_  void *pvAspect,
            /* [annotation][unique][in] */ 
            _In_opt_  DVTARGETDEVICE *ptd,
            /* [annotation][in] */ 
            _In_opt_  HDC hdcTargetDev,
            /* [annotation][in] */ 
            _In_  HDC hdcDraw,
            /* [annotation][in] */ 
            _In_opt_  LPCRECTL lprcBounds,
            /* [annotation][unique][in] */ 
            _In_opt_  LPCRECTL lprcWBounds,
            /* [annotation][in] */ 
            _In_opt_  BOOL ( STDMETHODCALLTYPE *pfnContinue )( 
                ULONG_PTR dwContinue),
            /* [annotation][in] */ 
            _In_  ULONG_PTR dwContinue);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *GetColorSet )( 
            IViewObject * This,
            /* [annotation][in] */ 
            _In_  DWORD dwDrawAspect,
            /* [annotation][in] */ 
            _In_  LONG lindex,
            /* [annotation][unique][in] */ 
            _Null_  void *pvAspect,
            /* [annotation][unique][in] */ 
            _In_opt_  DVTARGETDEVICE *ptd,
            /* [annotation][in] */ 
            _In_opt_  HDC hicTargetDev,
            /* [annotation][out] */ 
            _Outptr_  LOGPALETTE **ppColorSet);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Freeze )( 
            IViewObject * This,
            /* [annotation][in] */ 
            _In_  DWORD dwDrawAspect,
            /* [annotation][in] */ 
            _In_  LONG lindex,
            /* [annotation][unique][in] */ 
            _Null_  void *pvAspect,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwFreeze);
        
        HRESULT ( STDMETHODCALLTYPE *Unfreeze )( 
            __RPC__in IViewObject * This,
            /* [annotation][in] */ 
            _In_  DWORD dwFreeze);
        
        HRESULT ( STDMETHODCALLTYPE *SetAdvise )( 
            __RPC__in IViewObject * This,
            /* [annotation][in] */ 
            _In_  DWORD aspects,
            /* [annotation][in] */ 
            _In_  DWORD advf,
            /* [annotation][unique][in] */ 
            _In_  IAdviseSink *pAdvSink);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *GetAdvise )( 
            IViewObject * This,
            /* [annotation][unique][out] */ 
            _Out_opt_  DWORD *pAspects,
            /* [annotation][unique][out] */ 
            _Out_opt_  DWORD *pAdvf,
            /* [annotation][out] */ 
            _Outptr_  IAdviseSink **ppAdvSink);
        
        END_INTERFACE
    } IViewObjectVtbl;

    interface IViewObject
    {
        CONST_VTBL struct IViewObjectVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IViewObject_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IViewObject_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IViewObject_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IViewObject_Draw(This,dwDrawAspect,lindex,pvAspect,ptd,hdcTargetDev,hdcDraw,lprcBounds,lprcWBounds,pfnContinue,dwContinue)	\
    ( (This)->lpVtbl -> Draw(This,dwDrawAspect,lindex,pvAspect,ptd,hdcTargetDev,hdcDraw,lprcBounds,lprcWBounds,pfnContinue,dwContinue) ) 

#define IViewObject_GetColorSet(This,dwDrawAspect,lindex,pvAspect,ptd,hicTargetDev,ppColorSet)	\
    ( (This)->lpVtbl -> GetColorSet(This,dwDrawAspect,lindex,pvAspect,ptd,hicTargetDev,ppColorSet) ) 

#define IViewObject_Freeze(This,dwDrawAspect,lindex,pvAspect,pdwFreeze)	\
    ( (This)->lpVtbl -> Freeze(This,dwDrawAspect,lindex,pvAspect,pdwFreeze) ) 

#define IViewObject_Unfreeze(This,dwFreeze)	\
    ( (This)->lpVtbl -> Unfreeze(This,dwFreeze) ) 

#define IViewObject_SetAdvise(This,aspects,advf,pAdvSink)	\
    ( (This)->lpVtbl -> SetAdvise(This,aspects,advf,pAdvSink) ) 

#define IViewObject_GetAdvise(This,pAspects,pAdvf,ppAdvSink)	\
    ( (This)->lpVtbl -> GetAdvise(This,pAspects,pAdvf,ppAdvSink) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT STDMETHODCALLTYPE IViewObject_RemoteDraw_Proxy( 
    __RPC__in IViewObject * This,
    /* [annotation][in] */ 
    _In_  DWORD dwDrawAspect,
    /* [annotation][in] */ 
    _In_  LONG lindex,
    /* [annotation][in] */ 
    _In_  ULONG_PTR pvAspect,
    /* [annotation][unique][in] */ 
    _In_  DVTARGETDEVICE *ptd,
    /* [annotation][in] */ 
    _In_  HDC hdcTargetDev,
    /* [annotation][in] */ 
    _In_  HDC hdcDraw,
    /* [annotation][unique][in] */ 
    _In_  LPCRECTL lprcBounds,
    /* [annotation][unique][in] */ 
    _In_  LPCRECTL lprcWBounds,
    /* [annotation][in] */ 
    _In_  IContinue *pContinue);


void __RPC_STUB IViewObject_RemoteDraw_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IViewObject_RemoteGetColorSet_Proxy( 
    __RPC__in IViewObject * This,
    /* [annotation][in] */ 
    _In_  DWORD dwDrawAspect,
    /* [annotation][in] */ 
    _In_  LONG lindex,
    /* [annotation][in] */ 
    _In_  ULONG_PTR pvAspect,
    /* [annotation][unique][in] */ 
    _In_  DVTARGETDEVICE *ptd,
    /* [annotation][in] */ 
    _In_  ULONG_PTR hicTargetDev,
    /* [annotation][out] */ 
    _Out_  LOGPALETTE **ppColorSet);


void __RPC_STUB IViewObject_RemoteGetColorSet_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IViewObject_RemoteFreeze_Proxy( 
    __RPC__in IViewObject * This,
    /* [annotation][in] */ 
    _In_  DWORD dwDrawAspect,
    /* [annotation][in] */ 
    _In_  LONG lindex,
    /* [annotation][in] */ 
    _In_  ULONG_PTR pvAspect,
    /* [annotation][out] */ 
    _Out_  DWORD *pdwFreeze);


void __RPC_STUB IViewObject_RemoteFreeze_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IViewObject_RemoteGetAdvise_Proxy( 
    __RPC__in IViewObject * This,
    /* [annotation][out] */ 
    _Out_  DWORD *pAspects,
    /* [annotation][out] */ 
    _Out_  DWORD *pAdvf,
    /* [annotation][out] */ 
    _Out_  IAdviseSink **ppAdvSink);


void __RPC_STUB IViewObject_RemoteGetAdvise_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IViewObject_INTERFACE_DEFINED__ */


#ifndef __IViewObject2_INTERFACE_DEFINED__
#define __IViewObject2_INTERFACE_DEFINED__

/* interface IViewObject2 */
/* [uuid][object] */ 

typedef /* [unique] */  __RPC_unique_pointer IViewObject2 *LPVIEWOBJECT2;


EXTERN_C const IID IID_IViewObject2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("00000127-0000-0000-C000-000000000046")
    IViewObject2 : public IViewObject
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetExtent( 
            /* [annotation][in] */ 
            _In_  DWORD dwDrawAspect,
            /* [annotation][in] */ 
            _In_  LONG lindex,
            /* [annotation][unique][in] */ 
            _In_  DVTARGETDEVICE *ptd,
            /* [annotation][out] */ 
            _Out_  LPSIZEL lpsizel) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IViewObject2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IViewObject2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IViewObject2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IViewObject2 * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Draw )( 
            IViewObject2 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwDrawAspect,
            /* [annotation][in] */ 
            _In_  LONG lindex,
            /* [annotation][unique][in] */ 
            _Null_  void *pvAspect,
            /* [annotation][unique][in] */ 
            _In_opt_  DVTARGETDEVICE *ptd,
            /* [annotation][in] */ 
            _In_opt_  HDC hdcTargetDev,
            /* [annotation][in] */ 
            _In_  HDC hdcDraw,
            /* [annotation][in] */ 
            _In_opt_  LPCRECTL lprcBounds,
            /* [annotation][unique][in] */ 
            _In_opt_  LPCRECTL lprcWBounds,
            /* [annotation][in] */ 
            _In_opt_  BOOL ( STDMETHODCALLTYPE *pfnContinue )( 
                ULONG_PTR dwContinue),
            /* [annotation][in] */ 
            _In_  ULONG_PTR dwContinue);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *GetColorSet )( 
            IViewObject2 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwDrawAspect,
            /* [annotation][in] */ 
            _In_  LONG lindex,
            /* [annotation][unique][in] */ 
            _Null_  void *pvAspect,
            /* [annotation][unique][in] */ 
            _In_opt_  DVTARGETDEVICE *ptd,
            /* [annotation][in] */ 
            _In_opt_  HDC hicTargetDev,
            /* [annotation][out] */ 
            _Outptr_  LOGPALETTE **ppColorSet);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Freeze )( 
            IViewObject2 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwDrawAspect,
            /* [annotation][in] */ 
            _In_  LONG lindex,
            /* [annotation][unique][in] */ 
            _Null_  void *pvAspect,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwFreeze);
        
        HRESULT ( STDMETHODCALLTYPE *Unfreeze )( 
            __RPC__in IViewObject2 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwFreeze);
        
        HRESULT ( STDMETHODCALLTYPE *SetAdvise )( 
            __RPC__in IViewObject2 * This,
            /* [annotation][in] */ 
            _In_  DWORD aspects,
            /* [annotation][in] */ 
            _In_  DWORD advf,
            /* [annotation][unique][in] */ 
            _In_  IAdviseSink *pAdvSink);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *GetAdvise )( 
            IViewObject2 * This,
            /* [annotation][unique][out] */ 
            _Out_opt_  DWORD *pAspects,
            /* [annotation][unique][out] */ 
            _Out_opt_  DWORD *pAdvf,
            /* [annotation][out] */ 
            _Outptr_  IAdviseSink **ppAdvSink);
        
        HRESULT ( STDMETHODCALLTYPE *GetExtent )( 
            __RPC__in IViewObject2 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwDrawAspect,
            /* [annotation][in] */ 
            _In_  LONG lindex,
            /* [annotation][unique][in] */ 
            _In_  DVTARGETDEVICE *ptd,
            /* [annotation][out] */ 
            _Out_  LPSIZEL lpsizel);
        
        END_INTERFACE
    } IViewObject2Vtbl;

    interface IViewObject2
    {
        CONST_VTBL struct IViewObject2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IViewObject2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IViewObject2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IViewObject2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IViewObject2_Draw(This,dwDrawAspect,lindex,pvAspect,ptd,hdcTargetDev,hdcDraw,lprcBounds,lprcWBounds,pfnContinue,dwContinue)	\
    ( (This)->lpVtbl -> Draw(This,dwDrawAspect,lindex,pvAspect,ptd,hdcTargetDev,hdcDraw,lprcBounds,lprcWBounds,pfnContinue,dwContinue) ) 

#define IViewObject2_GetColorSet(This,dwDrawAspect,lindex,pvAspect,ptd,hicTargetDev,ppColorSet)	\
    ( (This)->lpVtbl -> GetColorSet(This,dwDrawAspect,lindex,pvAspect,ptd,hicTargetDev,ppColorSet) ) 

#define IViewObject2_Freeze(This,dwDrawAspect,lindex,pvAspect,pdwFreeze)	\
    ( (This)->lpVtbl -> Freeze(This,dwDrawAspect,lindex,pvAspect,pdwFreeze) ) 

#define IViewObject2_Unfreeze(This,dwFreeze)	\
    ( (This)->lpVtbl -> Unfreeze(This,dwFreeze) ) 

#define IViewObject2_SetAdvise(This,aspects,advf,pAdvSink)	\
    ( (This)->lpVtbl -> SetAdvise(This,aspects,advf,pAdvSink) ) 

#define IViewObject2_GetAdvise(This,pAspects,pAdvf,ppAdvSink)	\
    ( (This)->lpVtbl -> GetAdvise(This,pAspects,pAdvf,ppAdvSink) ) 


#define IViewObject2_GetExtent(This,dwDrawAspect,lindex,ptd,lpsizel)	\
    ( (This)->lpVtbl -> GetExtent(This,dwDrawAspect,lindex,ptd,lpsizel) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IViewObject2_INTERFACE_DEFINED__ */


#ifndef __IDropSource_INTERFACE_DEFINED__
#define __IDropSource_INTERFACE_DEFINED__

/* interface IDropSource */
/* [uuid][object][local] */ 

typedef /* [unique] */ IDropSource *LPDROPSOURCE;


EXTERN_C const IID IID_IDropSource;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("00000121-0000-0000-C000-000000000046")
    IDropSource : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE QueryContinueDrag( 
            /* [annotation][in] */ 
            _In_  BOOL fEscapePressed,
            /* [annotation][in] */ 
            _In_  DWORD grfKeyState) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GiveFeedback( 
            /* [annotation][in] */ 
            _In_  DWORD dwEffect) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IDropSourceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDropSource * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDropSource * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDropSource * This);
        
        HRESULT ( STDMETHODCALLTYPE *QueryContinueDrag )( 
            IDropSource * This,
            /* [annotation][in] */ 
            _In_  BOOL fEscapePressed,
            /* [annotation][in] */ 
            _In_  DWORD grfKeyState);
        
        HRESULT ( STDMETHODCALLTYPE *GiveFeedback )( 
            IDropSource * This,
            /* [annotation][in] */ 
            _In_  DWORD dwEffect);
        
        END_INTERFACE
    } IDropSourceVtbl;

    interface IDropSource
    {
        CONST_VTBL struct IDropSourceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDropSource_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDropSource_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDropSource_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDropSource_QueryContinueDrag(This,fEscapePressed,grfKeyState)	\
    ( (This)->lpVtbl -> QueryContinueDrag(This,fEscapePressed,grfKeyState) ) 

#define IDropSource_GiveFeedback(This,dwEffect)	\
    ( (This)->lpVtbl -> GiveFeedback(This,dwEffect) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDropSource_INTERFACE_DEFINED__ */


#ifndef __IDropTarget_INTERFACE_DEFINED__
#define __IDropTarget_INTERFACE_DEFINED__

/* interface IDropTarget */
/* [unique][uuid][object] */ 

typedef /* [unique] */  __RPC_unique_pointer IDropTarget *LPDROPTARGET;

#define	MK_ALT	( 0x20 )

#define	DROPEFFECT_NONE	( 0 )

#define	DROPEFFECT_COPY	( 1 )

#define	DROPEFFECT_MOVE	( 2 )

#define	DROPEFFECT_LINK	( 4 )

#define	DROPEFFECT_SCROLL	( 0x80000000 )

// default inset-width of the hot zone, in pixels
//   typical use: GetProfileInt("windows","DragScrollInset",DD_DEFSCROLLINSET)
#define	DD_DEFSCROLLINSET	( 11 )

// default delay before scrolling, in milliseconds
//   typical use: GetProfileInt("windows","DragScrollDelay",DD_DEFSCROLLDELAY)
#define	DD_DEFSCROLLDELAY	( 50 )

// default scroll interval, in milliseconds
//   typical use: GetProfileInt("windows","DragScrollInterval", DD_DEFSCROLLINTERVAL)
#define	DD_DEFSCROLLINTERVAL	( 50 )

// default delay before dragging should start, in milliseconds
//   typical use: GetProfileInt("windows", "DragDelay", DD_DEFDRAGDELAY)
#define	DD_DEFDRAGDELAY	( 200 )

// default minimum distance (radius) before dragging should start, in pixels
//   typical use: GetProfileInt("windows", "DragMinDist", DD_DEFDRAGMINDIST)
#define	DD_DEFDRAGMINDIST	( 2 )


EXTERN_C const IID IID_IDropTarget;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("00000122-0000-0000-C000-000000000046")
    IDropTarget : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE DragEnter( 
            /* [annotation][unique][in] */ 
            _In_  IDataObject *pDataObj,
            /* [annotation][in] */ 
            _In_  DWORD grfKeyState,
            /* [annotation][in] */ 
            _In_  POINTL pt,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pdwEffect) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DragOver( 
            /* [annotation][in] */ 
            _In_  DWORD grfKeyState,
            /* [annotation][in] */ 
            _In_  POINTL pt,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pdwEffect) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DragLeave( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Drop( 
            /* [annotation][unique][in] */ 
            _In_  IDataObject *pDataObj,
            /* [annotation][in] */ 
            _In_  DWORD grfKeyState,
            /* [annotation][in] */ 
            _In_  POINTL pt,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pdwEffect) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IDropTargetVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IDropTarget * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IDropTarget * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IDropTarget * This);
        
        HRESULT ( STDMETHODCALLTYPE *DragEnter )( 
            __RPC__in IDropTarget * This,
            /* [annotation][unique][in] */ 
            _In_  IDataObject *pDataObj,
            /* [annotation][in] */ 
            _In_  DWORD grfKeyState,
            /* [annotation][in] */ 
            _In_  POINTL pt,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pdwEffect);
        
        HRESULT ( STDMETHODCALLTYPE *DragOver )( 
            __RPC__in IDropTarget * This,
            /* [annotation][in] */ 
            _In_  DWORD grfKeyState,
            /* [annotation][in] */ 
            _In_  POINTL pt,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pdwEffect);
        
        HRESULT ( STDMETHODCALLTYPE *DragLeave )( 
            __RPC__in IDropTarget * This);
        
        HRESULT ( STDMETHODCALLTYPE *Drop )( 
            __RPC__in IDropTarget * This,
            /* [annotation][unique][in] */ 
            _In_  IDataObject *pDataObj,
            /* [annotation][in] */ 
            _In_  DWORD grfKeyState,
            /* [annotation][in] */ 
            _In_  POINTL pt,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pdwEffect);
        
        END_INTERFACE
    } IDropTargetVtbl;

    interface IDropTarget
    {
        CONST_VTBL struct IDropTargetVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDropTarget_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDropTarget_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDropTarget_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDropTarget_DragEnter(This,pDataObj,grfKeyState,pt,pdwEffect)	\
    ( (This)->lpVtbl -> DragEnter(This,pDataObj,grfKeyState,pt,pdwEffect) ) 

#define IDropTarget_DragOver(This,grfKeyState,pt,pdwEffect)	\
    ( (This)->lpVtbl -> DragOver(This,grfKeyState,pt,pdwEffect) ) 

#define IDropTarget_DragLeave(This)	\
    ( (This)->lpVtbl -> DragLeave(This) ) 

#define IDropTarget_Drop(This,pDataObj,grfKeyState,pt,pdwEffect)	\
    ( (This)->lpVtbl -> Drop(This,pDataObj,grfKeyState,pt,pdwEffect) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDropTarget_INTERFACE_DEFINED__ */


#ifndef __IDropSourceNotify_INTERFACE_DEFINED__
#define __IDropSourceNotify_INTERFACE_DEFINED__

/* interface IDropSourceNotify */
/* [unique][uuid][object][local] */ 


EXTERN_C const IID IID_IDropSourceNotify;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0000012B-0000-0000-C000-000000000046")
    IDropSourceNotify : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE DragEnterTarget( 
            /* [annotation][in] */ 
            _In_  HWND hwndTarget) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DragLeaveTarget( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IDropSourceNotifyVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDropSourceNotify * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDropSourceNotify * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDropSourceNotify * This);
        
        HRESULT ( STDMETHODCALLTYPE *DragEnterTarget )( 
            IDropSourceNotify * This,
            /* [annotation][in] */ 
            _In_  HWND hwndTarget);
        
        HRESULT ( STDMETHODCALLTYPE *DragLeaveTarget )( 
            IDropSourceNotify * This);
        
        END_INTERFACE
    } IDropSourceNotifyVtbl;

    interface IDropSourceNotify
    {
        CONST_VTBL struct IDropSourceNotifyVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDropSourceNotify_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDropSourceNotify_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDropSourceNotify_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDropSourceNotify_DragEnterTarget(This,hwndTarget)	\
    ( (This)->lpVtbl -> DragEnterTarget(This,hwndTarget) ) 

#define IDropSourceNotify_DragLeaveTarget(This)	\
    ( (This)->lpVtbl -> DragLeaveTarget(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDropSourceNotify_INTERFACE_DEFINED__ */


#ifndef __IEnterpriseDropTarget_INTERFACE_DEFINED__
#define __IEnterpriseDropTarget_INTERFACE_DEFINED__

/* interface IEnterpriseDropTarget */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IEnterpriseDropTarget;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("390E3878-FD55-4E18-819D-4682081C0CFD")
    IEnterpriseDropTarget : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetDropSourceEnterpriseId( 
            /* [annotation][in] */ 
            _In_  LPCWSTR identity) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsEvaluatingEdpPolicy( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BOOL *value) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IEnterpriseDropTargetVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IEnterpriseDropTarget * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IEnterpriseDropTarget * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IEnterpriseDropTarget * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetDropSourceEnterpriseId )( 
            __RPC__in IEnterpriseDropTarget * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR identity);
        
        HRESULT ( STDMETHODCALLTYPE *IsEvaluatingEdpPolicy )( 
            __RPC__in IEnterpriseDropTarget * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BOOL *value);
        
        END_INTERFACE
    } IEnterpriseDropTargetVtbl;

    interface IEnterpriseDropTarget
    {
        CONST_VTBL struct IEnterpriseDropTargetVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnterpriseDropTarget_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEnterpriseDropTarget_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEnterpriseDropTarget_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IEnterpriseDropTarget_SetDropSourceEnterpriseId(This,identity)	\
    ( (This)->lpVtbl -> SetDropSourceEnterpriseId(This,identity) ) 

#define IEnterpriseDropTarget_IsEvaluatingEdpPolicy(This,value)	\
    ( (This)->lpVtbl -> IsEvaluatingEdpPolicy(This,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IEnterpriseDropTarget_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_oleidl_0000_0024 */
/* [local] */ 

#define CFSTR_ENTERPRISE_ID (TEXT("EnterpriseDataProtectionId"))
#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) */
#pragma endregion
#pragma region Application Family or OneCore Family or Games Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)


extern RPC_IF_HANDLE __MIDL_itf_oleidl_0000_0024_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_oleidl_0000_0024_v0_0_s_ifspec;

#ifndef __IEnumOLEVERB_INTERFACE_DEFINED__
#define __IEnumOLEVERB_INTERFACE_DEFINED__

/* interface IEnumOLEVERB */
/* [unique][uuid][object] */ 

typedef /* [unique] */  __RPC_unique_pointer IEnumOLEVERB *LPENUMOLEVERB;

typedef struct tagOLEVERB
    {
    LONG lVerb;
    LPOLESTR lpszVerbName;
    DWORD fuFlags;
    DWORD grfAttribs;
    } 	OLEVERB;

typedef struct tagOLEVERB *LPOLEVERB;

typedef /* [v1_enum] */ 
enum tagOLEVERBATTRIB
    {
        OLEVERBATTRIB_NEVERDIRTIES	= 1,
        OLEVERBATTRIB_ONCONTAINERMENU	= 2
    } 	OLEVERBATTRIB;


EXTERN_C const IID IID_IEnumOLEVERB;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("00000104-0000-0000-C000-000000000046")
    IEnumOLEVERB : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE Next( 
            /* [annotation][in] */ 
            _In_  ULONG celt,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(celt, *pceltFetched)  LPOLEVERB rgelt,
            /* [annotation][out] */ 
            _Out_opt_  ULONG *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [annotation][in] */ 
            _In_  ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [annotation][out] */ 
            _Out_  IEnumOLEVERB **ppenum) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IEnumOLEVERBVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IEnumOLEVERB * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IEnumOLEVERB * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IEnumOLEVERB * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Next )( 
            IEnumOLEVERB * This,
            /* [annotation][in] */ 
            _In_  ULONG celt,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(celt, *pceltFetched)  LPOLEVERB rgelt,
            /* [annotation][out] */ 
            _Out_opt_  ULONG *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            __RPC__in IEnumOLEVERB * This,
            /* [annotation][in] */ 
            _In_  ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            __RPC__in IEnumOLEVERB * This);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            __RPC__in IEnumOLEVERB * This,
            /* [annotation][out] */ 
            _Out_  IEnumOLEVERB **ppenum);
        
        END_INTERFACE
    } IEnumOLEVERBVtbl;

    interface IEnumOLEVERB
    {
        CONST_VTBL struct IEnumOLEVERBVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumOLEVERB_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEnumOLEVERB_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEnumOLEVERB_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IEnumOLEVERB_Next(This,celt,rgelt,pceltFetched)	\
    ( (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched) ) 

#define IEnumOLEVERB_Skip(This,celt)	\
    ( (This)->lpVtbl -> Skip(This,celt) ) 

#define IEnumOLEVERB_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define IEnumOLEVERB_Clone(This,ppenum)	\
    ( (This)->lpVtbl -> Clone(This,ppenum) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT STDMETHODCALLTYPE IEnumOLEVERB_RemoteNext_Proxy( 
    __RPC__in IEnumOLEVERB * This,
    /* [annotation][in] */ 
    _In_  ULONG celt,
    /* [annotation][length_is][size_is][out] */ 
    _Out_writes_to_(celt,*pceltFetched)  LPOLEVERB rgelt,
    /* [annotation][out] */ 
    _Out_  ULONG *pceltFetched);


void __RPC_STUB IEnumOLEVERB_RemoteNext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEnumOLEVERB_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_oleidl_0000_0025 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */
#pragma endregion
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


extern RPC_IF_HANDLE __MIDL_itf_oleidl_0000_0025_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_oleidl_0000_0025_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  CLIPFORMAT_UserSize(     __RPC__in unsigned long *, unsigned long            , __RPC__in CLIPFORMAT * ); 
unsigned char * __RPC_USER  CLIPFORMAT_UserMarshal(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in CLIPFORMAT * ); 
unsigned char * __RPC_USER  CLIPFORMAT_UserUnmarshal(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out CLIPFORMAT * ); 
void                      __RPC_USER  CLIPFORMAT_UserFree(     __RPC__in unsigned long *, __RPC__in CLIPFORMAT * ); 

unsigned long             __RPC_USER  HACCEL_UserSize(     __RPC__in unsigned long *, unsigned long            , __RPC__in HACCEL * ); 
unsigned char * __RPC_USER  HACCEL_UserMarshal(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in HACCEL * ); 
unsigned char * __RPC_USER  HACCEL_UserUnmarshal(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out HACCEL * ); 
void                      __RPC_USER  HACCEL_UserFree(     __RPC__in unsigned long *, __RPC__in HACCEL * ); 

unsigned long             __RPC_USER  HDC_UserSize(     __RPC__in unsigned long *, unsigned long            , __RPC__in HDC * ); 
unsigned char * __RPC_USER  HDC_UserMarshal(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in HDC * ); 
unsigned char * __RPC_USER  HDC_UserUnmarshal(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out HDC * ); 
void                      __RPC_USER  HDC_UserFree(     __RPC__in unsigned long *, __RPC__in HDC * ); 

unsigned long             __RPC_USER  HGLOBAL_UserSize(     __RPC__in unsigned long *, unsigned long            , __RPC__in HGLOBAL * ); 
unsigned char * __RPC_USER  HGLOBAL_UserMarshal(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in HGLOBAL * ); 
unsigned char * __RPC_USER  HGLOBAL_UserUnmarshal(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out HGLOBAL * ); 
void                      __RPC_USER  HGLOBAL_UserFree(     __RPC__in unsigned long *, __RPC__in HGLOBAL * ); 

unsigned long             __RPC_USER  HMENU_UserSize(     __RPC__in unsigned long *, unsigned long            , __RPC__in HMENU * ); 
unsigned char * __RPC_USER  HMENU_UserMarshal(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in HMENU * ); 
unsigned char * __RPC_USER  HMENU_UserUnmarshal(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out HMENU * ); 
void                      __RPC_USER  HMENU_UserFree(     __RPC__in unsigned long *, __RPC__in HMENU * ); 

unsigned long             __RPC_USER  HWND_UserSize(     __RPC__in unsigned long *, unsigned long            , __RPC__in HWND * ); 
unsigned char * __RPC_USER  HWND_UserMarshal(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in HWND * ); 
unsigned char * __RPC_USER  HWND_UserUnmarshal(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out HWND * ); 
void                      __RPC_USER  HWND_UserFree(     __RPC__in unsigned long *, __RPC__in HWND * ); 

unsigned long             __RPC_USER  STGMEDIUM_UserSize(     __RPC__in unsigned long *, unsigned long            , __RPC__in STGMEDIUM * ); 
unsigned char * __RPC_USER  STGMEDIUM_UserMarshal(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in STGMEDIUM * ); 
unsigned char * __RPC_USER  STGMEDIUM_UserUnmarshal(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out STGMEDIUM * ); 
void                      __RPC_USER  STGMEDIUM_UserFree(     __RPC__in unsigned long *, __RPC__in STGMEDIUM * ); 

unsigned long             __RPC_USER  CLIPFORMAT_UserSize64(     __RPC__in unsigned long *, unsigned long            , __RPC__in CLIPFORMAT * ); 
unsigned char * __RPC_USER  CLIPFORMAT_UserMarshal64(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in CLIPFORMAT * ); 
unsigned char * __RPC_USER  CLIPFORMAT_UserUnmarshal64(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out CLIPFORMAT * ); 
void                      __RPC_USER  CLIPFORMAT_UserFree64(     __RPC__in unsigned long *, __RPC__in CLIPFORMAT * ); 

unsigned long             __RPC_USER  HACCEL_UserSize64(     __RPC__in unsigned long *, unsigned long            , __RPC__in HACCEL * ); 
unsigned char * __RPC_USER  HACCEL_UserMarshal64(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in HACCEL * ); 
unsigned char * __RPC_USER  HACCEL_UserUnmarshal64(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out HACCEL * ); 
void                      __RPC_USER  HACCEL_UserFree64(     __RPC__in unsigned long *, __RPC__in HACCEL * ); 

unsigned long             __RPC_USER  HDC_UserSize64(     __RPC__in unsigned long *, unsigned long            , __RPC__in HDC * ); 
unsigned char * __RPC_USER  HDC_UserMarshal64(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in HDC * ); 
unsigned char * __RPC_USER  HDC_UserUnmarshal64(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out HDC * ); 
void                      __RPC_USER  HDC_UserFree64(     __RPC__in unsigned long *, __RPC__in HDC * ); 

unsigned long             __RPC_USER  HGLOBAL_UserSize64(     __RPC__in unsigned long *, unsigned long            , __RPC__in HGLOBAL * ); 
unsigned char * __RPC_USER  HGLOBAL_UserMarshal64(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in HGLOBAL * ); 
unsigned char * __RPC_USER  HGLOBAL_UserUnmarshal64(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out HGLOBAL * ); 
void                      __RPC_USER  HGLOBAL_UserFree64(     __RPC__in unsigned long *, __RPC__in HGLOBAL * ); 

unsigned long             __RPC_USER  HMENU_UserSize64(     __RPC__in unsigned long *, unsigned long            , __RPC__in HMENU * ); 
unsigned char * __RPC_USER  HMENU_UserMarshal64(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in HMENU * ); 
unsigned char * __RPC_USER  HMENU_UserUnmarshal64(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out HMENU * ); 
void                      __RPC_USER  HMENU_UserFree64(     __RPC__in unsigned long *, __RPC__in HMENU * ); 

unsigned long             __RPC_USER  HWND_UserSize64(     __RPC__in unsigned long *, unsigned long            , __RPC__in HWND * ); 
unsigned char * __RPC_USER  HWND_UserMarshal64(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in HWND * ); 
unsigned char * __RPC_USER  HWND_UserUnmarshal64(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out HWND * ); 
void                      __RPC_USER  HWND_UserFree64(     __RPC__in unsigned long *, __RPC__in HWND * ); 

unsigned long             __RPC_USER  STGMEDIUM_UserSize64(     __RPC__in unsigned long *, unsigned long            , __RPC__in STGMEDIUM * ); 
unsigned char * __RPC_USER  STGMEDIUM_UserMarshal64(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in STGMEDIUM * ); 
unsigned char * __RPC_USER  STGMEDIUM_UserUnmarshal64(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out STGMEDIUM * ); 
void                      __RPC_USER  STGMEDIUM_UserFree64(     __RPC__in unsigned long *, __RPC__in STGMEDIUM * ); 

/* [local] */ HRESULT STDMETHODCALLTYPE IOleCache2_UpdateCache_Proxy( 
    IOleCache2 * This,
    /* [annotation][in] */ 
    _In_  LPDATAOBJECT pDataObject,
    /* [annotation][in] */ 
    _In_  DWORD grfUpdf,
    /* [annotation][in] */ 
    _Reserved_  LPVOID pReserved);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IOleCache2_UpdateCache_Stub( 
    __RPC__in IOleCache2 * This,
    /* [annotation][in] */ 
    _In_  LPDATAOBJECT pDataObject,
    /* [annotation][in] */ 
    _In_  DWORD grfUpdf,
    /* [annotation][in] */ 
    _In_  LONG_PTR pReserved);

/* [local] */ HRESULT STDMETHODCALLTYPE IOleInPlaceActiveObject_TranslateAccelerator_Proxy( 
    IOleInPlaceActiveObject * This,
    /* [annotation][in] */ 
    _In_opt_  LPMSG lpmsg);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IOleInPlaceActiveObject_TranslateAccelerator_Stub( 
    __RPC__in IOleInPlaceActiveObject * This);

/* [local] */ HRESULT STDMETHODCALLTYPE IOleInPlaceActiveObject_ResizeBorder_Proxy( 
    IOleInPlaceActiveObject * This,
    /* [annotation][in] */ 
    _In_  LPCRECT prcBorder,
    /* [annotation][unique][in] */ 
    _In_  IOleInPlaceUIWindow *pUIWindow,
    /* [annotation][in] */ 
    _In_  BOOL fFrameWindow);


/* [input_sync][call_as] */ HRESULT STDMETHODCALLTYPE IOleInPlaceActiveObject_ResizeBorder_Stub( 
    __RPC__in IOleInPlaceActiveObject * This,
    /* [annotation][in] */ 
    _In_  LPCRECT prcBorder,
    /* [annotation][in] */ 
    _In_  REFIID riid,
    /* [annotation][iid_is][unique][in] */ 
    _In_  IOleInPlaceUIWindow *pUIWindow,
    /* [annotation][in] */ 
    _In_  BOOL fFrameWindow);

/* [local] */ HRESULT STDMETHODCALLTYPE IViewObject_Draw_Proxy( 
    IViewObject * This,
    /* [annotation][in] */ 
    _In_  DWORD dwDrawAspect,
    /* [annotation][in] */ 
    _In_  LONG lindex,
    /* [annotation][unique][in] */ 
    _Null_  void *pvAspect,
    /* [annotation][unique][in] */ 
    _In_opt_  DVTARGETDEVICE *ptd,
    /* [annotation][in] */ 
    _In_opt_  HDC hdcTargetDev,
    /* [annotation][in] */ 
    _In_  HDC hdcDraw,
    /* [annotation][in] */ 
    _In_opt_  LPCRECTL lprcBounds,
    /* [annotation][unique][in] */ 
    _In_opt_  LPCRECTL lprcWBounds,
    /* [annotation][in] */ 
    _In_opt_  BOOL ( STDMETHODCALLTYPE *pfnContinue )( 
        ULONG_PTR dwContinue),
    /* [annotation][in] */ 
    _In_  ULONG_PTR dwContinue);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IViewObject_Draw_Stub( 
    __RPC__in IViewObject * This,
    /* [annotation][in] */ 
    _In_  DWORD dwDrawAspect,
    /* [annotation][in] */ 
    _In_  LONG lindex,
    /* [annotation][in] */ 
    _In_  ULONG_PTR pvAspect,
    /* [annotation][unique][in] */ 
    _In_  DVTARGETDEVICE *ptd,
    /* [annotation][in] */ 
    _In_  HDC hdcTargetDev,
    /* [annotation][in] */ 
    _In_  HDC hdcDraw,
    /* [annotation][unique][in] */ 
    _In_  LPCRECTL lprcBounds,
    /* [annotation][unique][in] */ 
    _In_  LPCRECTL lprcWBounds,
    /* [annotation][in] */ 
    _In_  IContinue *pContinue);

/* [local] */ HRESULT STDMETHODCALLTYPE IViewObject_GetColorSet_Proxy( 
    IViewObject * This,
    /* [annotation][in] */ 
    _In_  DWORD dwDrawAspect,
    /* [annotation][in] */ 
    _In_  LONG lindex,
    /* [annotation][unique][in] */ 
    _Null_  void *pvAspect,
    /* [annotation][unique][in] */ 
    _In_opt_  DVTARGETDEVICE *ptd,
    /* [annotation][in] */ 
    _In_opt_  HDC hicTargetDev,
    /* [annotation][out] */ 
    _Outptr_  LOGPALETTE **ppColorSet);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IViewObject_GetColorSet_Stub( 
    __RPC__in IViewObject * This,
    /* [annotation][in] */ 
    _In_  DWORD dwDrawAspect,
    /* [annotation][in] */ 
    _In_  LONG lindex,
    /* [annotation][in] */ 
    _In_  ULONG_PTR pvAspect,
    /* [annotation][unique][in] */ 
    _In_  DVTARGETDEVICE *ptd,
    /* [annotation][in] */ 
    _In_  ULONG_PTR hicTargetDev,
    /* [annotation][out] */ 
    _Out_  LOGPALETTE **ppColorSet);

/* [local] */ HRESULT STDMETHODCALLTYPE IViewObject_Freeze_Proxy( 
    IViewObject * This,
    /* [annotation][in] */ 
    _In_  DWORD dwDrawAspect,
    /* [annotation][in] */ 
    _In_  LONG lindex,
    /* [annotation][unique][in] */ 
    _Null_  void *pvAspect,
    /* [annotation][out] */ 
    _Out_  DWORD *pdwFreeze);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IViewObject_Freeze_Stub( 
    __RPC__in IViewObject * This,
    /* [annotation][in] */ 
    _In_  DWORD dwDrawAspect,
    /* [annotation][in] */ 
    _In_  LONG lindex,
    /* [annotation][in] */ 
    _In_  ULONG_PTR pvAspect,
    /* [annotation][out] */ 
    _Out_  DWORD *pdwFreeze);

/* [local] */ HRESULT STDMETHODCALLTYPE IViewObject_GetAdvise_Proxy( 
    IViewObject * This,
    /* [annotation][unique][out] */ 
    _Out_opt_  DWORD *pAspects,
    /* [annotation][unique][out] */ 
    _Out_opt_  DWORD *pAdvf,
    /* [annotation][out] */ 
    _Outptr_  IAdviseSink **ppAdvSink);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IViewObject_GetAdvise_Stub( 
    __RPC__in IViewObject * This,
    /* [annotation][out] */ 
    _Out_  DWORD *pAspects,
    /* [annotation][out] */ 
    _Out_  DWORD *pAdvf,
    /* [annotation][out] */ 
    _Out_  IAdviseSink **ppAdvSink);

/* [local] */ HRESULT STDMETHODCALLTYPE IEnumOLEVERB_Next_Proxy( 
    IEnumOLEVERB * This,
    /* [annotation][in] */ 
    _In_  ULONG celt,
    /* [annotation][length_is][size_is][out] */ 
    _Out_writes_to_(celt, *pceltFetched)  LPOLEVERB rgelt,
    /* [annotation][out] */ 
    _Out_opt_  ULONG *pceltFetched);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IEnumOLEVERB_Next_Stub( 
    __RPC__in IEnumOLEVERB * This,
    /* [annotation][in] */ 
    _In_  ULONG celt,
    /* [annotation][length_is][size_is][out] */ 
    _Out_writes_to_(celt,*pceltFetched)  LPOLEVERB rgelt,
    /* [annotation][out] */ 
    _Out_  ULONG *pceltFetched);



/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


