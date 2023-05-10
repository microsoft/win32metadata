

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

#ifndef __searchapi_h__
#define __searchapi_h__

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

#ifndef __IUrlAccessor_FWD_DEFINED__
#define __IUrlAccessor_FWD_DEFINED__
typedef interface IUrlAccessor IUrlAccessor;

#endif 	/* __IUrlAccessor_FWD_DEFINED__ */


#ifndef __IUrlAccessor2_FWD_DEFINED__
#define __IUrlAccessor2_FWD_DEFINED__
typedef interface IUrlAccessor2 IUrlAccessor2;

#endif 	/* __IUrlAccessor2_FWD_DEFINED__ */


#ifndef __IUrlAccessor3_FWD_DEFINED__
#define __IUrlAccessor3_FWD_DEFINED__
typedef interface IUrlAccessor3 IUrlAccessor3;

#endif 	/* __IUrlAccessor3_FWD_DEFINED__ */


#ifndef __IUrlAccessor4_FWD_DEFINED__
#define __IUrlAccessor4_FWD_DEFINED__
typedef interface IUrlAccessor4 IUrlAccessor4;

#endif 	/* __IUrlAccessor4_FWD_DEFINED__ */


#ifndef __IOpLockStatus_FWD_DEFINED__
#define __IOpLockStatus_FWD_DEFINED__
typedef interface IOpLockStatus IOpLockStatus;

#endif 	/* __IOpLockStatus_FWD_DEFINED__ */


#ifndef __ISearchProtocolThreadContext_FWD_DEFINED__
#define __ISearchProtocolThreadContext_FWD_DEFINED__
typedef interface ISearchProtocolThreadContext ISearchProtocolThreadContext;

#endif 	/* __ISearchProtocolThreadContext_FWD_DEFINED__ */


#ifndef __ISearchProtocol_FWD_DEFINED__
#define __ISearchProtocol_FWD_DEFINED__
typedef interface ISearchProtocol ISearchProtocol;

#endif 	/* __ISearchProtocol_FWD_DEFINED__ */


#ifndef __ISearchProtocol2_FWD_DEFINED__
#define __ISearchProtocol2_FWD_DEFINED__
typedef interface ISearchProtocol2 ISearchProtocol2;

#endif 	/* __ISearchProtocol2_FWD_DEFINED__ */


#ifndef __IProtocolHandlerSite_FWD_DEFINED__
#define __IProtocolHandlerSite_FWD_DEFINED__
typedef interface IProtocolHandlerSite IProtocolHandlerSite;

#endif 	/* __IProtocolHandlerSite_FWD_DEFINED__ */


#ifndef __ISearchRoot_FWD_DEFINED__
#define __ISearchRoot_FWD_DEFINED__
typedef interface ISearchRoot ISearchRoot;

#endif 	/* __ISearchRoot_FWD_DEFINED__ */


#ifndef __IEnumSearchRoots_FWD_DEFINED__
#define __IEnumSearchRoots_FWD_DEFINED__
typedef interface IEnumSearchRoots IEnumSearchRoots;

#endif 	/* __IEnumSearchRoots_FWD_DEFINED__ */


#ifndef __ISearchScopeRule_FWD_DEFINED__
#define __ISearchScopeRule_FWD_DEFINED__
typedef interface ISearchScopeRule ISearchScopeRule;

#endif 	/* __ISearchScopeRule_FWD_DEFINED__ */


#ifndef __IEnumSearchScopeRules_FWD_DEFINED__
#define __IEnumSearchScopeRules_FWD_DEFINED__
typedef interface IEnumSearchScopeRules IEnumSearchScopeRules;

#endif 	/* __IEnumSearchScopeRules_FWD_DEFINED__ */


#ifndef __ISearchCrawlScopeManager_FWD_DEFINED__
#define __ISearchCrawlScopeManager_FWD_DEFINED__
typedef interface ISearchCrawlScopeManager ISearchCrawlScopeManager;

#endif 	/* __ISearchCrawlScopeManager_FWD_DEFINED__ */


#ifndef __ISearchCrawlScopeManager2_FWD_DEFINED__
#define __ISearchCrawlScopeManager2_FWD_DEFINED__
typedef interface ISearchCrawlScopeManager2 ISearchCrawlScopeManager2;

#endif 	/* __ISearchCrawlScopeManager2_FWD_DEFINED__ */


#ifndef __ISearchItemsChangedSink_FWD_DEFINED__
#define __ISearchItemsChangedSink_FWD_DEFINED__
typedef interface ISearchItemsChangedSink ISearchItemsChangedSink;

#endif 	/* __ISearchItemsChangedSink_FWD_DEFINED__ */


#ifndef __ISearchPersistentItemsChangedSink_FWD_DEFINED__
#define __ISearchPersistentItemsChangedSink_FWD_DEFINED__
typedef interface ISearchPersistentItemsChangedSink ISearchPersistentItemsChangedSink;

#endif 	/* __ISearchPersistentItemsChangedSink_FWD_DEFINED__ */


#ifndef __ISearchViewChangedSink_FWD_DEFINED__
#define __ISearchViewChangedSink_FWD_DEFINED__
typedef interface ISearchViewChangedSink ISearchViewChangedSink;

#endif 	/* __ISearchViewChangedSink_FWD_DEFINED__ */


#ifndef __ISearchNotifyInlineSite_FWD_DEFINED__
#define __ISearchNotifyInlineSite_FWD_DEFINED__
typedef interface ISearchNotifyInlineSite ISearchNotifyInlineSite;

#endif 	/* __ISearchNotifyInlineSite_FWD_DEFINED__ */


#ifndef __ISearchCatalogManager_FWD_DEFINED__
#define __ISearchCatalogManager_FWD_DEFINED__
typedef interface ISearchCatalogManager ISearchCatalogManager;

#endif 	/* __ISearchCatalogManager_FWD_DEFINED__ */


#ifndef __ISearchCatalogManager2_FWD_DEFINED__
#define __ISearchCatalogManager2_FWD_DEFINED__
typedef interface ISearchCatalogManager2 ISearchCatalogManager2;

#endif 	/* __ISearchCatalogManager2_FWD_DEFINED__ */


#ifndef __ISearchQueryHelper_FWD_DEFINED__
#define __ISearchQueryHelper_FWD_DEFINED__
typedef interface ISearchQueryHelper ISearchQueryHelper;

#endif 	/* __ISearchQueryHelper_FWD_DEFINED__ */


#ifndef __IRowsetPrioritization_FWD_DEFINED__
#define __IRowsetPrioritization_FWD_DEFINED__
typedef interface IRowsetPrioritization IRowsetPrioritization;

#endif 	/* __IRowsetPrioritization_FWD_DEFINED__ */


#ifndef __IRowsetEvents_FWD_DEFINED__
#define __IRowsetEvents_FWD_DEFINED__
typedef interface IRowsetEvents IRowsetEvents;

#endif 	/* __IRowsetEvents_FWD_DEFINED__ */


#ifndef __ISearchManager_FWD_DEFINED__
#define __ISearchManager_FWD_DEFINED__
typedef interface ISearchManager ISearchManager;

#endif 	/* __ISearchManager_FWD_DEFINED__ */


#ifndef __ISearchManager2_FWD_DEFINED__
#define __ISearchManager2_FWD_DEFINED__
typedef interface ISearchManager2 ISearchManager2;

#endif 	/* __ISearchManager2_FWD_DEFINED__ */


#ifndef __ISearchLanguageSupport_FWD_DEFINED__
#define __ISearchLanguageSupport_FWD_DEFINED__
typedef interface ISearchLanguageSupport ISearchLanguageSupport;

#endif 	/* __ISearchLanguageSupport_FWD_DEFINED__ */


#ifndef __ISearchCatalogManager_FWD_DEFINED__
#define __ISearchCatalogManager_FWD_DEFINED__
typedef interface ISearchCatalogManager ISearchCatalogManager;

#endif 	/* __ISearchCatalogManager_FWD_DEFINED__ */


#ifndef __ISearchCatalogManager2_FWD_DEFINED__
#define __ISearchCatalogManager2_FWD_DEFINED__
typedef interface ISearchCatalogManager2 ISearchCatalogManager2;

#endif 	/* __ISearchCatalogManager2_FWD_DEFINED__ */


#ifndef __ISearchQueryHelper_FWD_DEFINED__
#define __ISearchQueryHelper_FWD_DEFINED__
typedef interface ISearchQueryHelper ISearchQueryHelper;

#endif 	/* __ISearchQueryHelper_FWD_DEFINED__ */


#ifndef __ISearchItemsChangedSink_FWD_DEFINED__
#define __ISearchItemsChangedSink_FWD_DEFINED__
typedef interface ISearchItemsChangedSink ISearchItemsChangedSink;

#endif 	/* __ISearchItemsChangedSink_FWD_DEFINED__ */


#ifndef __ISearchCrawlScopeManager_FWD_DEFINED__
#define __ISearchCrawlScopeManager_FWD_DEFINED__
typedef interface ISearchCrawlScopeManager ISearchCrawlScopeManager;

#endif 	/* __ISearchCrawlScopeManager_FWD_DEFINED__ */


#ifndef __IEnumSearchScopeRules_FWD_DEFINED__
#define __IEnumSearchScopeRules_FWD_DEFINED__
typedef interface IEnumSearchScopeRules IEnumSearchScopeRules;

#endif 	/* __IEnumSearchScopeRules_FWD_DEFINED__ */


#ifndef __ISearchManager_FWD_DEFINED__
#define __ISearchManager_FWD_DEFINED__
typedef interface ISearchManager ISearchManager;

#endif 	/* __ISearchManager_FWD_DEFINED__ */


#ifndef __ISearchManager2_FWD_DEFINED__
#define __ISearchManager2_FWD_DEFINED__
typedef interface ISearchManager2 ISearchManager2;

#endif 	/* __ISearchManager2_FWD_DEFINED__ */


#ifndef __CSearchManager_FWD_DEFINED__
#define __CSearchManager_FWD_DEFINED__

#ifdef __cplusplus
typedef class CSearchManager CSearchManager;
#else
typedef struct CSearchManager CSearchManager;
#endif /* __cplusplus */

#endif 	/* __CSearchManager_FWD_DEFINED__ */


#ifndef __CSearchRoot_FWD_DEFINED__
#define __CSearchRoot_FWD_DEFINED__

#ifdef __cplusplus
typedef class CSearchRoot CSearchRoot;
#else
typedef struct CSearchRoot CSearchRoot;
#endif /* __cplusplus */

#endif 	/* __CSearchRoot_FWD_DEFINED__ */


#ifndef __CSearchScopeRule_FWD_DEFINED__
#define __CSearchScopeRule_FWD_DEFINED__

#ifdef __cplusplus
typedef class CSearchScopeRule CSearchScopeRule;
#else
typedef struct CSearchScopeRule CSearchScopeRule;
#endif /* __cplusplus */

#endif 	/* __CSearchScopeRule_FWD_DEFINED__ */


#ifndef __FilterRegistration_FWD_DEFINED__
#define __FilterRegistration_FWD_DEFINED__

#ifdef __cplusplus
typedef class FilterRegistration FilterRegistration;
#else
typedef struct FilterRegistration FilterRegistration;
#endif /* __cplusplus */

#endif 	/* __FilterRegistration_FWD_DEFINED__ */


/* header files for imported files */
#include "unknwn.h"
#include "objidl.h"
#include "ocidl.h"
#include "propidl.h"
#include "filter.h"
#include "filtereg.h"
#include "propsys.h"
#include "oledb.h"
#include "StructuredQuery.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_searchapi_0000_0000 */
/* [local] */ 

//+----------------------------------------------------------------------------
//
//    Copyright (c) 2005 Microsoft Corporation.
//    Search API Interface
//
//-----------------------------------------------------------------------------
#include <winapifamily.h>
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
typedef LONG ITEMID;

#include <winapifamily.h>
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)


extern RPC_IF_HANDLE __MIDL_itf_searchapi_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_searchapi_0000_0000_v0_0_s_ifspec;

#ifndef __IUrlAccessor_INTERFACE_DEFINED__
#define __IUrlAccessor_INTERFACE_DEFINED__

/* interface IUrlAccessor */
/* [unique][public][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IUrlAccessor;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0b63e318-9ccc-11d0-bcdb-00805fccce04")
    IUrlAccessor : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AddRequestParameter( 
            /* [annotation][in] */ 
            _In_  PROPSPEC *pSpec,
            /* [annotation][in] */ 
            _In_  PROPVARIANT *pVar) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDocFormat( 
            /* [annotation][size_is][length_is][out] */ 
            _Out_writes_to_(dwSize,*pdwLength)  WCHAR wszDocFormat[  ],
            /* [annotation][in] */ 
            _In_  DWORD dwSize,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwLength) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCLSID( 
            /* [annotation][out] */ 
            _Out_  CLSID *pClsid) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetHost( 
            /* [annotation][size_is][length_is][out] */ 
            _Out_writes_to_(dwSize,*pdwLength)  WCHAR wszHost[  ],
            /* [annotation][in] */ 
            _In_  DWORD dwSize,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwLength) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsDirectory( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSize( 
            /* [annotation][out] */ 
            _Out_  ULONGLONG *pllSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLastModified( 
            /* [annotation][out] */ 
            _Out_  FILETIME *pftLastModified) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFileName( 
            /* [annotation][size_is][length_is][out] */ 
            _Out_writes_to_(dwSize,*pdwLength)  WCHAR wszFileName[  ],
            /* [annotation][in] */ 
            _In_  DWORD dwSize,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwLength) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSecurityDescriptor( 
            /* [annotation][size_is][out] */ 
            _Out_writes_(dwSize)  BYTE *pSD,
            /* [annotation][in] */ 
            _In_  DWORD dwSize,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwLength) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRedirectedURL( 
            /* [annotation][size_is][length_is][out] */ 
            _Out_writes_to_(dwSize,*pdwLength)  WCHAR wszRedirectedURL[  ],
            /* [annotation][in] */ 
            _In_  DWORD dwSize,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwLength) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSecurityProvider( 
            /* [annotation][out] */ 
            _Out_  CLSID *pSPClsid) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE BindToStream( 
            /* [annotation][out] */ 
            _Out_  IStream **ppStream) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE BindToFilter( 
            /* [annotation][out] */ 
            _Out_  IFilter **ppFilter) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IUrlAccessorVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IUrlAccessor * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IUrlAccessor * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IUrlAccessor * This);
        
        DECLSPEC_XFGVIRT(IUrlAccessor, AddRequestParameter)
        HRESULT ( STDMETHODCALLTYPE *AddRequestParameter )( 
            __RPC__in IUrlAccessor * This,
            /* [annotation][in] */ 
            _In_  PROPSPEC *pSpec,
            /* [annotation][in] */ 
            _In_  PROPVARIANT *pVar);
        
        DECLSPEC_XFGVIRT(IUrlAccessor, GetDocFormat)
        HRESULT ( STDMETHODCALLTYPE *GetDocFormat )( 
            __RPC__in IUrlAccessor * This,
            /* [annotation][size_is][length_is][out] */ 
            _Out_writes_to_(dwSize,*pdwLength)  WCHAR wszDocFormat[  ],
            /* [annotation][in] */ 
            _In_  DWORD dwSize,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwLength);
        
        DECLSPEC_XFGVIRT(IUrlAccessor, GetCLSID)
        HRESULT ( STDMETHODCALLTYPE *GetCLSID )( 
            __RPC__in IUrlAccessor * This,
            /* [annotation][out] */ 
            _Out_  CLSID *pClsid);
        
        DECLSPEC_XFGVIRT(IUrlAccessor, GetHost)
        HRESULT ( STDMETHODCALLTYPE *GetHost )( 
            __RPC__in IUrlAccessor * This,
            /* [annotation][size_is][length_is][out] */ 
            _Out_writes_to_(dwSize,*pdwLength)  WCHAR wszHost[  ],
            /* [annotation][in] */ 
            _In_  DWORD dwSize,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwLength);
        
        DECLSPEC_XFGVIRT(IUrlAccessor, IsDirectory)
        HRESULT ( STDMETHODCALLTYPE *IsDirectory )( 
            __RPC__in IUrlAccessor * This);
        
        DECLSPEC_XFGVIRT(IUrlAccessor, GetSize)
        HRESULT ( STDMETHODCALLTYPE *GetSize )( 
            __RPC__in IUrlAccessor * This,
            /* [annotation][out] */ 
            _Out_  ULONGLONG *pllSize);
        
        DECLSPEC_XFGVIRT(IUrlAccessor, GetLastModified)
        HRESULT ( STDMETHODCALLTYPE *GetLastModified )( 
            __RPC__in IUrlAccessor * This,
            /* [annotation][out] */ 
            _Out_  FILETIME *pftLastModified);
        
        DECLSPEC_XFGVIRT(IUrlAccessor, GetFileName)
        HRESULT ( STDMETHODCALLTYPE *GetFileName )( 
            __RPC__in IUrlAccessor * This,
            /* [annotation][size_is][length_is][out] */ 
            _Out_writes_to_(dwSize,*pdwLength)  WCHAR wszFileName[  ],
            /* [annotation][in] */ 
            _In_  DWORD dwSize,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwLength);
        
        DECLSPEC_XFGVIRT(IUrlAccessor, GetSecurityDescriptor)
        HRESULT ( STDMETHODCALLTYPE *GetSecurityDescriptor )( 
            __RPC__in IUrlAccessor * This,
            /* [annotation][size_is][out] */ 
            _Out_writes_(dwSize)  BYTE *pSD,
            /* [annotation][in] */ 
            _In_  DWORD dwSize,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwLength);
        
        DECLSPEC_XFGVIRT(IUrlAccessor, GetRedirectedURL)
        HRESULT ( STDMETHODCALLTYPE *GetRedirectedURL )( 
            __RPC__in IUrlAccessor * This,
            /* [annotation][size_is][length_is][out] */ 
            _Out_writes_to_(dwSize,*pdwLength)  WCHAR wszRedirectedURL[  ],
            /* [annotation][in] */ 
            _In_  DWORD dwSize,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwLength);
        
        DECLSPEC_XFGVIRT(IUrlAccessor, GetSecurityProvider)
        HRESULT ( STDMETHODCALLTYPE *GetSecurityProvider )( 
            __RPC__in IUrlAccessor * This,
            /* [annotation][out] */ 
            _Out_  CLSID *pSPClsid);
        
        DECLSPEC_XFGVIRT(IUrlAccessor, BindToStream)
        HRESULT ( STDMETHODCALLTYPE *BindToStream )( 
            __RPC__in IUrlAccessor * This,
            /* [annotation][out] */ 
            _Out_  IStream **ppStream);
        
        DECLSPEC_XFGVIRT(IUrlAccessor, BindToFilter)
        HRESULT ( STDMETHODCALLTYPE *BindToFilter )( 
            __RPC__in IUrlAccessor * This,
            /* [annotation][out] */ 
            _Out_  IFilter **ppFilter);
        
        END_INTERFACE
    } IUrlAccessorVtbl;

    interface IUrlAccessor
    {
        CONST_VTBL struct IUrlAccessorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IUrlAccessor_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IUrlAccessor_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IUrlAccessor_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IUrlAccessor_AddRequestParameter(This,pSpec,pVar)	\
    ( (This)->lpVtbl -> AddRequestParameter(This,pSpec,pVar) ) 

#define IUrlAccessor_GetDocFormat(This,wszDocFormat,dwSize,pdwLength)	\
    ( (This)->lpVtbl -> GetDocFormat(This,wszDocFormat,dwSize,pdwLength) ) 

#define IUrlAccessor_GetCLSID(This,pClsid)	\
    ( (This)->lpVtbl -> GetCLSID(This,pClsid) ) 

#define IUrlAccessor_GetHost(This,wszHost,dwSize,pdwLength)	\
    ( (This)->lpVtbl -> GetHost(This,wszHost,dwSize,pdwLength) ) 

#define IUrlAccessor_IsDirectory(This)	\
    ( (This)->lpVtbl -> IsDirectory(This) ) 

#define IUrlAccessor_GetSize(This,pllSize)	\
    ( (This)->lpVtbl -> GetSize(This,pllSize) ) 

#define IUrlAccessor_GetLastModified(This,pftLastModified)	\
    ( (This)->lpVtbl -> GetLastModified(This,pftLastModified) ) 

#define IUrlAccessor_GetFileName(This,wszFileName,dwSize,pdwLength)	\
    ( (This)->lpVtbl -> GetFileName(This,wszFileName,dwSize,pdwLength) ) 

#define IUrlAccessor_GetSecurityDescriptor(This,pSD,dwSize,pdwLength)	\
    ( (This)->lpVtbl -> GetSecurityDescriptor(This,pSD,dwSize,pdwLength) ) 

#define IUrlAccessor_GetRedirectedURL(This,wszRedirectedURL,dwSize,pdwLength)	\
    ( (This)->lpVtbl -> GetRedirectedURL(This,wszRedirectedURL,dwSize,pdwLength) ) 

#define IUrlAccessor_GetSecurityProvider(This,pSPClsid)	\
    ( (This)->lpVtbl -> GetSecurityProvider(This,pSPClsid) ) 

#define IUrlAccessor_BindToStream(This,ppStream)	\
    ( (This)->lpVtbl -> BindToStream(This,ppStream) ) 

#define IUrlAccessor_BindToFilter(This,ppFilter)	\
    ( (This)->lpVtbl -> BindToFilter(This,ppFilter) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IUrlAccessor_INTERFACE_DEFINED__ */


#ifndef __IUrlAccessor2_INTERFACE_DEFINED__
#define __IUrlAccessor2_INTERFACE_DEFINED__

/* interface IUrlAccessor2 */
/* [unique][public][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IUrlAccessor2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("c7310734-ac80-11d1-8df3-00c04fb6ef4f")
    IUrlAccessor2 : public IUrlAccessor
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetDisplayUrl( 
            /* [annotation][size_is][length_is][out] */ 
            _Out_writes_to_(dwSize,*pdwLength)  WCHAR wszDocUrl[  ],
            /* [annotation][in] */ 
            _In_  DWORD dwSize,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwLength) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsDocument( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCodePage( 
            /* [annotation][size_is][length_is][out] */ 
            _Out_writes_to_(dwSize,*pdwLength)  WCHAR wszCodePage[  ],
            /* [annotation][in] */ 
            _In_  DWORD dwSize,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwLength) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IUrlAccessor2Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IUrlAccessor2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IUrlAccessor2 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IUrlAccessor2 * This);
        
        DECLSPEC_XFGVIRT(IUrlAccessor, AddRequestParameter)
        HRESULT ( STDMETHODCALLTYPE *AddRequestParameter )( 
            __RPC__in IUrlAccessor2 * This,
            /* [annotation][in] */ 
            _In_  PROPSPEC *pSpec,
            /* [annotation][in] */ 
            _In_  PROPVARIANT *pVar);
        
        DECLSPEC_XFGVIRT(IUrlAccessor, GetDocFormat)
        HRESULT ( STDMETHODCALLTYPE *GetDocFormat )( 
            __RPC__in IUrlAccessor2 * This,
            /* [annotation][size_is][length_is][out] */ 
            _Out_writes_to_(dwSize,*pdwLength)  WCHAR wszDocFormat[  ],
            /* [annotation][in] */ 
            _In_  DWORD dwSize,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwLength);
        
        DECLSPEC_XFGVIRT(IUrlAccessor, GetCLSID)
        HRESULT ( STDMETHODCALLTYPE *GetCLSID )( 
            __RPC__in IUrlAccessor2 * This,
            /* [annotation][out] */ 
            _Out_  CLSID *pClsid);
        
        DECLSPEC_XFGVIRT(IUrlAccessor, GetHost)
        HRESULT ( STDMETHODCALLTYPE *GetHost )( 
            __RPC__in IUrlAccessor2 * This,
            /* [annotation][size_is][length_is][out] */ 
            _Out_writes_to_(dwSize,*pdwLength)  WCHAR wszHost[  ],
            /* [annotation][in] */ 
            _In_  DWORD dwSize,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwLength);
        
        DECLSPEC_XFGVIRT(IUrlAccessor, IsDirectory)
        HRESULT ( STDMETHODCALLTYPE *IsDirectory )( 
            __RPC__in IUrlAccessor2 * This);
        
        DECLSPEC_XFGVIRT(IUrlAccessor, GetSize)
        HRESULT ( STDMETHODCALLTYPE *GetSize )( 
            __RPC__in IUrlAccessor2 * This,
            /* [annotation][out] */ 
            _Out_  ULONGLONG *pllSize);
        
        DECLSPEC_XFGVIRT(IUrlAccessor, GetLastModified)
        HRESULT ( STDMETHODCALLTYPE *GetLastModified )( 
            __RPC__in IUrlAccessor2 * This,
            /* [annotation][out] */ 
            _Out_  FILETIME *pftLastModified);
        
        DECLSPEC_XFGVIRT(IUrlAccessor, GetFileName)
        HRESULT ( STDMETHODCALLTYPE *GetFileName )( 
            __RPC__in IUrlAccessor2 * This,
            /* [annotation][size_is][length_is][out] */ 
            _Out_writes_to_(dwSize,*pdwLength)  WCHAR wszFileName[  ],
            /* [annotation][in] */ 
            _In_  DWORD dwSize,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwLength);
        
        DECLSPEC_XFGVIRT(IUrlAccessor, GetSecurityDescriptor)
        HRESULT ( STDMETHODCALLTYPE *GetSecurityDescriptor )( 
            __RPC__in IUrlAccessor2 * This,
            /* [annotation][size_is][out] */ 
            _Out_writes_(dwSize)  BYTE *pSD,
            /* [annotation][in] */ 
            _In_  DWORD dwSize,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwLength);
        
        DECLSPEC_XFGVIRT(IUrlAccessor, GetRedirectedURL)
        HRESULT ( STDMETHODCALLTYPE *GetRedirectedURL )( 
            __RPC__in IUrlAccessor2 * This,
            /* [annotation][size_is][length_is][out] */ 
            _Out_writes_to_(dwSize,*pdwLength)  WCHAR wszRedirectedURL[  ],
            /* [annotation][in] */ 
            _In_  DWORD dwSize,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwLength);
        
        DECLSPEC_XFGVIRT(IUrlAccessor, GetSecurityProvider)
        HRESULT ( STDMETHODCALLTYPE *GetSecurityProvider )( 
            __RPC__in IUrlAccessor2 * This,
            /* [annotation][out] */ 
            _Out_  CLSID *pSPClsid);
        
        DECLSPEC_XFGVIRT(IUrlAccessor, BindToStream)
        HRESULT ( STDMETHODCALLTYPE *BindToStream )( 
            __RPC__in IUrlAccessor2 * This,
            /* [annotation][out] */ 
            _Out_  IStream **ppStream);
        
        DECLSPEC_XFGVIRT(IUrlAccessor, BindToFilter)
        HRESULT ( STDMETHODCALLTYPE *BindToFilter )( 
            __RPC__in IUrlAccessor2 * This,
            /* [annotation][out] */ 
            _Out_  IFilter **ppFilter);
        
        DECLSPEC_XFGVIRT(IUrlAccessor2, GetDisplayUrl)
        HRESULT ( STDMETHODCALLTYPE *GetDisplayUrl )( 
            __RPC__in IUrlAccessor2 * This,
            /* [annotation][size_is][length_is][out] */ 
            _Out_writes_to_(dwSize,*pdwLength)  WCHAR wszDocUrl[  ],
            /* [annotation][in] */ 
            _In_  DWORD dwSize,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwLength);
        
        DECLSPEC_XFGVIRT(IUrlAccessor2, IsDocument)
        HRESULT ( STDMETHODCALLTYPE *IsDocument )( 
            __RPC__in IUrlAccessor2 * This);
        
        DECLSPEC_XFGVIRT(IUrlAccessor2, GetCodePage)
        HRESULT ( STDMETHODCALLTYPE *GetCodePage )( 
            __RPC__in IUrlAccessor2 * This,
            /* [annotation][size_is][length_is][out] */ 
            _Out_writes_to_(dwSize,*pdwLength)  WCHAR wszCodePage[  ],
            /* [annotation][in] */ 
            _In_  DWORD dwSize,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwLength);
        
        END_INTERFACE
    } IUrlAccessor2Vtbl;

    interface IUrlAccessor2
    {
        CONST_VTBL struct IUrlAccessor2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IUrlAccessor2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IUrlAccessor2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IUrlAccessor2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IUrlAccessor2_AddRequestParameter(This,pSpec,pVar)	\
    ( (This)->lpVtbl -> AddRequestParameter(This,pSpec,pVar) ) 

#define IUrlAccessor2_GetDocFormat(This,wszDocFormat,dwSize,pdwLength)	\
    ( (This)->lpVtbl -> GetDocFormat(This,wszDocFormat,dwSize,pdwLength) ) 

#define IUrlAccessor2_GetCLSID(This,pClsid)	\
    ( (This)->lpVtbl -> GetCLSID(This,pClsid) ) 

#define IUrlAccessor2_GetHost(This,wszHost,dwSize,pdwLength)	\
    ( (This)->lpVtbl -> GetHost(This,wszHost,dwSize,pdwLength) ) 

#define IUrlAccessor2_IsDirectory(This)	\
    ( (This)->lpVtbl -> IsDirectory(This) ) 

#define IUrlAccessor2_GetSize(This,pllSize)	\
    ( (This)->lpVtbl -> GetSize(This,pllSize) ) 

#define IUrlAccessor2_GetLastModified(This,pftLastModified)	\
    ( (This)->lpVtbl -> GetLastModified(This,pftLastModified) ) 

#define IUrlAccessor2_GetFileName(This,wszFileName,dwSize,pdwLength)	\
    ( (This)->lpVtbl -> GetFileName(This,wszFileName,dwSize,pdwLength) ) 

#define IUrlAccessor2_GetSecurityDescriptor(This,pSD,dwSize,pdwLength)	\
    ( (This)->lpVtbl -> GetSecurityDescriptor(This,pSD,dwSize,pdwLength) ) 

#define IUrlAccessor2_GetRedirectedURL(This,wszRedirectedURL,dwSize,pdwLength)	\
    ( (This)->lpVtbl -> GetRedirectedURL(This,wszRedirectedURL,dwSize,pdwLength) ) 

#define IUrlAccessor2_GetSecurityProvider(This,pSPClsid)	\
    ( (This)->lpVtbl -> GetSecurityProvider(This,pSPClsid) ) 

#define IUrlAccessor2_BindToStream(This,ppStream)	\
    ( (This)->lpVtbl -> BindToStream(This,ppStream) ) 

#define IUrlAccessor2_BindToFilter(This,ppFilter)	\
    ( (This)->lpVtbl -> BindToFilter(This,ppFilter) ) 


#define IUrlAccessor2_GetDisplayUrl(This,wszDocUrl,dwSize,pdwLength)	\
    ( (This)->lpVtbl -> GetDisplayUrl(This,wszDocUrl,dwSize,pdwLength) ) 

#define IUrlAccessor2_IsDocument(This)	\
    ( (This)->lpVtbl -> IsDocument(This) ) 

#define IUrlAccessor2_GetCodePage(This,wszCodePage,dwSize,pdwLength)	\
    ( (This)->lpVtbl -> GetCodePage(This,wszCodePage,dwSize,pdwLength) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IUrlAccessor2_INTERFACE_DEFINED__ */


#ifndef __IUrlAccessor3_INTERFACE_DEFINED__
#define __IUrlAccessor3_INTERFACE_DEFINED__

/* interface IUrlAccessor3 */
/* [unique][public][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IUrlAccessor3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6FBC7005-0455-4874-B8FF-7439450241A3")
    IUrlAccessor3 : public IUrlAccessor2
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetImpersonationSidBlobs( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pcwszURL,
            /* [annotation][out] */ 
            _Out_  DWORD *pcSidCount,
            /* [annotation][out] */ 
            _Out_  BLOB **ppSidBlobs) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IUrlAccessor3Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IUrlAccessor3 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IUrlAccessor3 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IUrlAccessor3 * This);
        
        DECLSPEC_XFGVIRT(IUrlAccessor, AddRequestParameter)
        HRESULT ( STDMETHODCALLTYPE *AddRequestParameter )( 
            __RPC__in IUrlAccessor3 * This,
            /* [annotation][in] */ 
            _In_  PROPSPEC *pSpec,
            /* [annotation][in] */ 
            _In_  PROPVARIANT *pVar);
        
        DECLSPEC_XFGVIRT(IUrlAccessor, GetDocFormat)
        HRESULT ( STDMETHODCALLTYPE *GetDocFormat )( 
            __RPC__in IUrlAccessor3 * This,
            /* [annotation][size_is][length_is][out] */ 
            _Out_writes_to_(dwSize,*pdwLength)  WCHAR wszDocFormat[  ],
            /* [annotation][in] */ 
            _In_  DWORD dwSize,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwLength);
        
        DECLSPEC_XFGVIRT(IUrlAccessor, GetCLSID)
        HRESULT ( STDMETHODCALLTYPE *GetCLSID )( 
            __RPC__in IUrlAccessor3 * This,
            /* [annotation][out] */ 
            _Out_  CLSID *pClsid);
        
        DECLSPEC_XFGVIRT(IUrlAccessor, GetHost)
        HRESULT ( STDMETHODCALLTYPE *GetHost )( 
            __RPC__in IUrlAccessor3 * This,
            /* [annotation][size_is][length_is][out] */ 
            _Out_writes_to_(dwSize,*pdwLength)  WCHAR wszHost[  ],
            /* [annotation][in] */ 
            _In_  DWORD dwSize,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwLength);
        
        DECLSPEC_XFGVIRT(IUrlAccessor, IsDirectory)
        HRESULT ( STDMETHODCALLTYPE *IsDirectory )( 
            __RPC__in IUrlAccessor3 * This);
        
        DECLSPEC_XFGVIRT(IUrlAccessor, GetSize)
        HRESULT ( STDMETHODCALLTYPE *GetSize )( 
            __RPC__in IUrlAccessor3 * This,
            /* [annotation][out] */ 
            _Out_  ULONGLONG *pllSize);
        
        DECLSPEC_XFGVIRT(IUrlAccessor, GetLastModified)
        HRESULT ( STDMETHODCALLTYPE *GetLastModified )( 
            __RPC__in IUrlAccessor3 * This,
            /* [annotation][out] */ 
            _Out_  FILETIME *pftLastModified);
        
        DECLSPEC_XFGVIRT(IUrlAccessor, GetFileName)
        HRESULT ( STDMETHODCALLTYPE *GetFileName )( 
            __RPC__in IUrlAccessor3 * This,
            /* [annotation][size_is][length_is][out] */ 
            _Out_writes_to_(dwSize,*pdwLength)  WCHAR wszFileName[  ],
            /* [annotation][in] */ 
            _In_  DWORD dwSize,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwLength);
        
        DECLSPEC_XFGVIRT(IUrlAccessor, GetSecurityDescriptor)
        HRESULT ( STDMETHODCALLTYPE *GetSecurityDescriptor )( 
            __RPC__in IUrlAccessor3 * This,
            /* [annotation][size_is][out] */ 
            _Out_writes_(dwSize)  BYTE *pSD,
            /* [annotation][in] */ 
            _In_  DWORD dwSize,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwLength);
        
        DECLSPEC_XFGVIRT(IUrlAccessor, GetRedirectedURL)
        HRESULT ( STDMETHODCALLTYPE *GetRedirectedURL )( 
            __RPC__in IUrlAccessor3 * This,
            /* [annotation][size_is][length_is][out] */ 
            _Out_writes_to_(dwSize,*pdwLength)  WCHAR wszRedirectedURL[  ],
            /* [annotation][in] */ 
            _In_  DWORD dwSize,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwLength);
        
        DECLSPEC_XFGVIRT(IUrlAccessor, GetSecurityProvider)
        HRESULT ( STDMETHODCALLTYPE *GetSecurityProvider )( 
            __RPC__in IUrlAccessor3 * This,
            /* [annotation][out] */ 
            _Out_  CLSID *pSPClsid);
        
        DECLSPEC_XFGVIRT(IUrlAccessor, BindToStream)
        HRESULT ( STDMETHODCALLTYPE *BindToStream )( 
            __RPC__in IUrlAccessor3 * This,
            /* [annotation][out] */ 
            _Out_  IStream **ppStream);
        
        DECLSPEC_XFGVIRT(IUrlAccessor, BindToFilter)
        HRESULT ( STDMETHODCALLTYPE *BindToFilter )( 
            __RPC__in IUrlAccessor3 * This,
            /* [annotation][out] */ 
            _Out_  IFilter **ppFilter);
        
        DECLSPEC_XFGVIRT(IUrlAccessor2, GetDisplayUrl)
        HRESULT ( STDMETHODCALLTYPE *GetDisplayUrl )( 
            __RPC__in IUrlAccessor3 * This,
            /* [annotation][size_is][length_is][out] */ 
            _Out_writes_to_(dwSize,*pdwLength)  WCHAR wszDocUrl[  ],
            /* [annotation][in] */ 
            _In_  DWORD dwSize,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwLength);
        
        DECLSPEC_XFGVIRT(IUrlAccessor2, IsDocument)
        HRESULT ( STDMETHODCALLTYPE *IsDocument )( 
            __RPC__in IUrlAccessor3 * This);
        
        DECLSPEC_XFGVIRT(IUrlAccessor2, GetCodePage)
        HRESULT ( STDMETHODCALLTYPE *GetCodePage )( 
            __RPC__in IUrlAccessor3 * This,
            /* [annotation][size_is][length_is][out] */ 
            _Out_writes_to_(dwSize,*pdwLength)  WCHAR wszCodePage[  ],
            /* [annotation][in] */ 
            _In_  DWORD dwSize,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwLength);
        
        DECLSPEC_XFGVIRT(IUrlAccessor3, GetImpersonationSidBlobs)
        HRESULT ( STDMETHODCALLTYPE *GetImpersonationSidBlobs )( 
            __RPC__in IUrlAccessor3 * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pcwszURL,
            /* [annotation][out] */ 
            _Out_  DWORD *pcSidCount,
            /* [annotation][out] */ 
            _Out_  BLOB **ppSidBlobs);
        
        END_INTERFACE
    } IUrlAccessor3Vtbl;

    interface IUrlAccessor3
    {
        CONST_VTBL struct IUrlAccessor3Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IUrlAccessor3_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IUrlAccessor3_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IUrlAccessor3_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IUrlAccessor3_AddRequestParameter(This,pSpec,pVar)	\
    ( (This)->lpVtbl -> AddRequestParameter(This,pSpec,pVar) ) 

#define IUrlAccessor3_GetDocFormat(This,wszDocFormat,dwSize,pdwLength)	\
    ( (This)->lpVtbl -> GetDocFormat(This,wszDocFormat,dwSize,pdwLength) ) 

#define IUrlAccessor3_GetCLSID(This,pClsid)	\
    ( (This)->lpVtbl -> GetCLSID(This,pClsid) ) 

#define IUrlAccessor3_GetHost(This,wszHost,dwSize,pdwLength)	\
    ( (This)->lpVtbl -> GetHost(This,wszHost,dwSize,pdwLength) ) 

#define IUrlAccessor3_IsDirectory(This)	\
    ( (This)->lpVtbl -> IsDirectory(This) ) 

#define IUrlAccessor3_GetSize(This,pllSize)	\
    ( (This)->lpVtbl -> GetSize(This,pllSize) ) 

#define IUrlAccessor3_GetLastModified(This,pftLastModified)	\
    ( (This)->lpVtbl -> GetLastModified(This,pftLastModified) ) 

#define IUrlAccessor3_GetFileName(This,wszFileName,dwSize,pdwLength)	\
    ( (This)->lpVtbl -> GetFileName(This,wszFileName,dwSize,pdwLength) ) 

#define IUrlAccessor3_GetSecurityDescriptor(This,pSD,dwSize,pdwLength)	\
    ( (This)->lpVtbl -> GetSecurityDescriptor(This,pSD,dwSize,pdwLength) ) 

#define IUrlAccessor3_GetRedirectedURL(This,wszRedirectedURL,dwSize,pdwLength)	\
    ( (This)->lpVtbl -> GetRedirectedURL(This,wszRedirectedURL,dwSize,pdwLength) ) 

#define IUrlAccessor3_GetSecurityProvider(This,pSPClsid)	\
    ( (This)->lpVtbl -> GetSecurityProvider(This,pSPClsid) ) 

#define IUrlAccessor3_BindToStream(This,ppStream)	\
    ( (This)->lpVtbl -> BindToStream(This,ppStream) ) 

#define IUrlAccessor3_BindToFilter(This,ppFilter)	\
    ( (This)->lpVtbl -> BindToFilter(This,ppFilter) ) 


#define IUrlAccessor3_GetDisplayUrl(This,wszDocUrl,dwSize,pdwLength)	\
    ( (This)->lpVtbl -> GetDisplayUrl(This,wszDocUrl,dwSize,pdwLength) ) 

#define IUrlAccessor3_IsDocument(This)	\
    ( (This)->lpVtbl -> IsDocument(This) ) 

#define IUrlAccessor3_GetCodePage(This,wszCodePage,dwSize,pdwLength)	\
    ( (This)->lpVtbl -> GetCodePage(This,wszCodePage,dwSize,pdwLength) ) 


#define IUrlAccessor3_GetImpersonationSidBlobs(This,pcwszURL,pcSidCount,ppSidBlobs)	\
    ( (This)->lpVtbl -> GetImpersonationSidBlobs(This,pcwszURL,pcSidCount,ppSidBlobs) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IUrlAccessor3_INTERFACE_DEFINED__ */


#ifndef __IUrlAccessor4_INTERFACE_DEFINED__
#define __IUrlAccessor4_INTERFACE_DEFINED__

/* interface IUrlAccessor4 */
/* [unique][public][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IUrlAccessor4;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5CC51041-C8D2-41d7-BCA3-9E9E286297DC")
    IUrlAccessor4 : public IUrlAccessor3
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ShouldIndexItemContent( 
            /* [annotation][out] */ 
            _Out_  BOOL *pfIndexContent) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ShouldIndexProperty( 
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY key,
            /* [annotation][out] */ 
            _Out_  BOOL *pfIndexProperty) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IUrlAccessor4Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IUrlAccessor4 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IUrlAccessor4 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IUrlAccessor4 * This);
        
        DECLSPEC_XFGVIRT(IUrlAccessor, AddRequestParameter)
        HRESULT ( STDMETHODCALLTYPE *AddRequestParameter )( 
            __RPC__in IUrlAccessor4 * This,
            /* [annotation][in] */ 
            _In_  PROPSPEC *pSpec,
            /* [annotation][in] */ 
            _In_  PROPVARIANT *pVar);
        
        DECLSPEC_XFGVIRT(IUrlAccessor, GetDocFormat)
        HRESULT ( STDMETHODCALLTYPE *GetDocFormat )( 
            __RPC__in IUrlAccessor4 * This,
            /* [annotation][size_is][length_is][out] */ 
            _Out_writes_to_(dwSize,*pdwLength)  WCHAR wszDocFormat[  ],
            /* [annotation][in] */ 
            _In_  DWORD dwSize,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwLength);
        
        DECLSPEC_XFGVIRT(IUrlAccessor, GetCLSID)
        HRESULT ( STDMETHODCALLTYPE *GetCLSID )( 
            __RPC__in IUrlAccessor4 * This,
            /* [annotation][out] */ 
            _Out_  CLSID *pClsid);
        
        DECLSPEC_XFGVIRT(IUrlAccessor, GetHost)
        HRESULT ( STDMETHODCALLTYPE *GetHost )( 
            __RPC__in IUrlAccessor4 * This,
            /* [annotation][size_is][length_is][out] */ 
            _Out_writes_to_(dwSize,*pdwLength)  WCHAR wszHost[  ],
            /* [annotation][in] */ 
            _In_  DWORD dwSize,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwLength);
        
        DECLSPEC_XFGVIRT(IUrlAccessor, IsDirectory)
        HRESULT ( STDMETHODCALLTYPE *IsDirectory )( 
            __RPC__in IUrlAccessor4 * This);
        
        DECLSPEC_XFGVIRT(IUrlAccessor, GetSize)
        HRESULT ( STDMETHODCALLTYPE *GetSize )( 
            __RPC__in IUrlAccessor4 * This,
            /* [annotation][out] */ 
            _Out_  ULONGLONG *pllSize);
        
        DECLSPEC_XFGVIRT(IUrlAccessor, GetLastModified)
        HRESULT ( STDMETHODCALLTYPE *GetLastModified )( 
            __RPC__in IUrlAccessor4 * This,
            /* [annotation][out] */ 
            _Out_  FILETIME *pftLastModified);
        
        DECLSPEC_XFGVIRT(IUrlAccessor, GetFileName)
        HRESULT ( STDMETHODCALLTYPE *GetFileName )( 
            __RPC__in IUrlAccessor4 * This,
            /* [annotation][size_is][length_is][out] */ 
            _Out_writes_to_(dwSize,*pdwLength)  WCHAR wszFileName[  ],
            /* [annotation][in] */ 
            _In_  DWORD dwSize,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwLength);
        
        DECLSPEC_XFGVIRT(IUrlAccessor, GetSecurityDescriptor)
        HRESULT ( STDMETHODCALLTYPE *GetSecurityDescriptor )( 
            __RPC__in IUrlAccessor4 * This,
            /* [annotation][size_is][out] */ 
            _Out_writes_(dwSize)  BYTE *pSD,
            /* [annotation][in] */ 
            _In_  DWORD dwSize,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwLength);
        
        DECLSPEC_XFGVIRT(IUrlAccessor, GetRedirectedURL)
        HRESULT ( STDMETHODCALLTYPE *GetRedirectedURL )( 
            __RPC__in IUrlAccessor4 * This,
            /* [annotation][size_is][length_is][out] */ 
            _Out_writes_to_(dwSize,*pdwLength)  WCHAR wszRedirectedURL[  ],
            /* [annotation][in] */ 
            _In_  DWORD dwSize,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwLength);
        
        DECLSPEC_XFGVIRT(IUrlAccessor, GetSecurityProvider)
        HRESULT ( STDMETHODCALLTYPE *GetSecurityProvider )( 
            __RPC__in IUrlAccessor4 * This,
            /* [annotation][out] */ 
            _Out_  CLSID *pSPClsid);
        
        DECLSPEC_XFGVIRT(IUrlAccessor, BindToStream)
        HRESULT ( STDMETHODCALLTYPE *BindToStream )( 
            __RPC__in IUrlAccessor4 * This,
            /* [annotation][out] */ 
            _Out_  IStream **ppStream);
        
        DECLSPEC_XFGVIRT(IUrlAccessor, BindToFilter)
        HRESULT ( STDMETHODCALLTYPE *BindToFilter )( 
            __RPC__in IUrlAccessor4 * This,
            /* [annotation][out] */ 
            _Out_  IFilter **ppFilter);
        
        DECLSPEC_XFGVIRT(IUrlAccessor2, GetDisplayUrl)
        HRESULT ( STDMETHODCALLTYPE *GetDisplayUrl )( 
            __RPC__in IUrlAccessor4 * This,
            /* [annotation][size_is][length_is][out] */ 
            _Out_writes_to_(dwSize,*pdwLength)  WCHAR wszDocUrl[  ],
            /* [annotation][in] */ 
            _In_  DWORD dwSize,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwLength);
        
        DECLSPEC_XFGVIRT(IUrlAccessor2, IsDocument)
        HRESULT ( STDMETHODCALLTYPE *IsDocument )( 
            __RPC__in IUrlAccessor4 * This);
        
        DECLSPEC_XFGVIRT(IUrlAccessor2, GetCodePage)
        HRESULT ( STDMETHODCALLTYPE *GetCodePage )( 
            __RPC__in IUrlAccessor4 * This,
            /* [annotation][size_is][length_is][out] */ 
            _Out_writes_to_(dwSize,*pdwLength)  WCHAR wszCodePage[  ],
            /* [annotation][in] */ 
            _In_  DWORD dwSize,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwLength);
        
        DECLSPEC_XFGVIRT(IUrlAccessor3, GetImpersonationSidBlobs)
        HRESULT ( STDMETHODCALLTYPE *GetImpersonationSidBlobs )( 
            __RPC__in IUrlAccessor4 * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pcwszURL,
            /* [annotation][out] */ 
            _Out_  DWORD *pcSidCount,
            /* [annotation][out] */ 
            _Out_  BLOB **ppSidBlobs);
        
        DECLSPEC_XFGVIRT(IUrlAccessor4, ShouldIndexItemContent)
        HRESULT ( STDMETHODCALLTYPE *ShouldIndexItemContent )( 
            __RPC__in IUrlAccessor4 * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pfIndexContent);
        
        DECLSPEC_XFGVIRT(IUrlAccessor4, ShouldIndexProperty)
        HRESULT ( STDMETHODCALLTYPE *ShouldIndexProperty )( 
            __RPC__in IUrlAccessor4 * This,
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY key,
            /* [annotation][out] */ 
            _Out_  BOOL *pfIndexProperty);
        
        END_INTERFACE
    } IUrlAccessor4Vtbl;

    interface IUrlAccessor4
    {
        CONST_VTBL struct IUrlAccessor4Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IUrlAccessor4_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IUrlAccessor4_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IUrlAccessor4_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IUrlAccessor4_AddRequestParameter(This,pSpec,pVar)	\
    ( (This)->lpVtbl -> AddRequestParameter(This,pSpec,pVar) ) 

#define IUrlAccessor4_GetDocFormat(This,wszDocFormat,dwSize,pdwLength)	\
    ( (This)->lpVtbl -> GetDocFormat(This,wszDocFormat,dwSize,pdwLength) ) 

#define IUrlAccessor4_GetCLSID(This,pClsid)	\
    ( (This)->lpVtbl -> GetCLSID(This,pClsid) ) 

#define IUrlAccessor4_GetHost(This,wszHost,dwSize,pdwLength)	\
    ( (This)->lpVtbl -> GetHost(This,wszHost,dwSize,pdwLength) ) 

#define IUrlAccessor4_IsDirectory(This)	\
    ( (This)->lpVtbl -> IsDirectory(This) ) 

#define IUrlAccessor4_GetSize(This,pllSize)	\
    ( (This)->lpVtbl -> GetSize(This,pllSize) ) 

#define IUrlAccessor4_GetLastModified(This,pftLastModified)	\
    ( (This)->lpVtbl -> GetLastModified(This,pftLastModified) ) 

#define IUrlAccessor4_GetFileName(This,wszFileName,dwSize,pdwLength)	\
    ( (This)->lpVtbl -> GetFileName(This,wszFileName,dwSize,pdwLength) ) 

#define IUrlAccessor4_GetSecurityDescriptor(This,pSD,dwSize,pdwLength)	\
    ( (This)->lpVtbl -> GetSecurityDescriptor(This,pSD,dwSize,pdwLength) ) 

#define IUrlAccessor4_GetRedirectedURL(This,wszRedirectedURL,dwSize,pdwLength)	\
    ( (This)->lpVtbl -> GetRedirectedURL(This,wszRedirectedURL,dwSize,pdwLength) ) 

#define IUrlAccessor4_GetSecurityProvider(This,pSPClsid)	\
    ( (This)->lpVtbl -> GetSecurityProvider(This,pSPClsid) ) 

#define IUrlAccessor4_BindToStream(This,ppStream)	\
    ( (This)->lpVtbl -> BindToStream(This,ppStream) ) 

#define IUrlAccessor4_BindToFilter(This,ppFilter)	\
    ( (This)->lpVtbl -> BindToFilter(This,ppFilter) ) 


#define IUrlAccessor4_GetDisplayUrl(This,wszDocUrl,dwSize,pdwLength)	\
    ( (This)->lpVtbl -> GetDisplayUrl(This,wszDocUrl,dwSize,pdwLength) ) 

#define IUrlAccessor4_IsDocument(This)	\
    ( (This)->lpVtbl -> IsDocument(This) ) 

#define IUrlAccessor4_GetCodePage(This,wszCodePage,dwSize,pdwLength)	\
    ( (This)->lpVtbl -> GetCodePage(This,wszCodePage,dwSize,pdwLength) ) 


#define IUrlAccessor4_GetImpersonationSidBlobs(This,pcwszURL,pcSidCount,ppSidBlobs)	\
    ( (This)->lpVtbl -> GetImpersonationSidBlobs(This,pcwszURL,pcSidCount,ppSidBlobs) ) 


#define IUrlAccessor4_ShouldIndexItemContent(This,pfIndexContent)	\
    ( (This)->lpVtbl -> ShouldIndexItemContent(This,pfIndexContent) ) 

#define IUrlAccessor4_ShouldIndexProperty(This,key,pfIndexProperty)	\
    ( (This)->lpVtbl -> ShouldIndexProperty(This,key,pfIndexProperty) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IUrlAccessor4_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_searchapi_0000_0004 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion
#include <winapifamily.h>
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)



extern RPC_IF_HANDLE __MIDL_itf_searchapi_0000_0004_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_searchapi_0000_0004_v0_0_s_ifspec;

#ifndef __IOpLockStatus_INTERFACE_DEFINED__
#define __IOpLockStatus_INTERFACE_DEFINED__

/* interface IOpLockStatus */
/* [unique][local][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IOpLockStatus;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("c731065d-ac80-11d1-8df3-00c04fb6ef4f")
    IOpLockStatus : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE IsOplockValid( 
            /* [annotation][out] */ 
            _Out_  BOOL *pfIsOplockValid) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsOplockBroken( 
            /* [annotation][out] */ 
            _Out_  BOOL *pfIsOplockBroken) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetOplockEventHandle( 
            /* [annotation][out] */ 
            _Outptr_  HANDLE *phOplockEv) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IOpLockStatusVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IOpLockStatus * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IOpLockStatus * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IOpLockStatus * This);
        
        DECLSPEC_XFGVIRT(IOpLockStatus, IsOplockValid)
        HRESULT ( STDMETHODCALLTYPE *IsOplockValid )( 
            IOpLockStatus * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pfIsOplockValid);
        
        DECLSPEC_XFGVIRT(IOpLockStatus, IsOplockBroken)
        HRESULT ( STDMETHODCALLTYPE *IsOplockBroken )( 
            IOpLockStatus * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pfIsOplockBroken);
        
        DECLSPEC_XFGVIRT(IOpLockStatus, GetOplockEventHandle)
        HRESULT ( STDMETHODCALLTYPE *GetOplockEventHandle )( 
            IOpLockStatus * This,
            /* [annotation][out] */ 
            _Outptr_  HANDLE *phOplockEv);
        
        END_INTERFACE
    } IOpLockStatusVtbl;

    interface IOpLockStatus
    {
        CONST_VTBL struct IOpLockStatusVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOpLockStatus_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOpLockStatus_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOpLockStatus_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOpLockStatus_IsOplockValid(This,pfIsOplockValid)	\
    ( (This)->lpVtbl -> IsOplockValid(This,pfIsOplockValid) ) 

#define IOpLockStatus_IsOplockBroken(This,pfIsOplockBroken)	\
    ( (This)->lpVtbl -> IsOplockBroken(This,pfIsOplockBroken) ) 

#define IOpLockStatus_GetOplockEventHandle(This,phOplockEv)	\
    ( (This)->lpVtbl -> GetOplockEventHandle(This,phOplockEv) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOpLockStatus_INTERFACE_DEFINED__ */


#ifndef __ISearchProtocolThreadContext_INTERFACE_DEFINED__
#define __ISearchProtocolThreadContext_INTERFACE_DEFINED__

/* interface ISearchProtocolThreadContext */
/* [unique][local][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISearchProtocolThreadContext;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("c73106e1-ac80-11d1-8df3-00c04fb6ef4f")
    ISearchProtocolThreadContext : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ThreadInit( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ThreadShutdown( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ThreadIdle( 
            /* [annotation][in] */ 
            _In_  DWORD dwTimeElaspedSinceLastCallInMS) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISearchProtocolThreadContextVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISearchProtocolThreadContext * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISearchProtocolThreadContext * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISearchProtocolThreadContext * This);
        
        DECLSPEC_XFGVIRT(ISearchProtocolThreadContext, ThreadInit)
        HRESULT ( STDMETHODCALLTYPE *ThreadInit )( 
            ISearchProtocolThreadContext * This);
        
        DECLSPEC_XFGVIRT(ISearchProtocolThreadContext, ThreadShutdown)
        HRESULT ( STDMETHODCALLTYPE *ThreadShutdown )( 
            ISearchProtocolThreadContext * This);
        
        DECLSPEC_XFGVIRT(ISearchProtocolThreadContext, ThreadIdle)
        HRESULT ( STDMETHODCALLTYPE *ThreadIdle )( 
            ISearchProtocolThreadContext * This,
            /* [annotation][in] */ 
            _In_  DWORD dwTimeElaspedSinceLastCallInMS);
        
        END_INTERFACE
    } ISearchProtocolThreadContextVtbl;

    interface ISearchProtocolThreadContext
    {
        CONST_VTBL struct ISearchProtocolThreadContextVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISearchProtocolThreadContext_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISearchProtocolThreadContext_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISearchProtocolThreadContext_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISearchProtocolThreadContext_ThreadInit(This)	\
    ( (This)->lpVtbl -> ThreadInit(This) ) 

#define ISearchProtocolThreadContext_ThreadShutdown(This)	\
    ( (This)->lpVtbl -> ThreadShutdown(This) ) 

#define ISearchProtocolThreadContext_ThreadIdle(This,dwTimeElaspedSinceLastCallInMS)	\
    ( (This)->lpVtbl -> ThreadIdle(This,dwTimeElaspedSinceLastCallInMS) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISearchProtocolThreadContext_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_searchapi_0000_0006 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion
#include <winapifamily.h>
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)


#pragma pack(8)
typedef struct _TIMEOUT_INFO
    {
    DWORD dwSize;
    DWORD dwConnectTimeout;
    DWORD dwDataTimeout;
    } 	TIMEOUT_INFO;

typedef 
enum _PROXY_ACCESS
    {
        PROXY_ACCESS_PRECONFIG	= 0,
        PROXY_ACCESS_DIRECT	= ( PROXY_ACCESS_PRECONFIG + 1 ) ,
        PROXY_ACCESS_PROXY	= ( PROXY_ACCESS_DIRECT + 1 ) 
    } 	PROXY_ACCESS;

typedef struct _PROXY_INFO
    {
    DWORD dwSize;
    LPCWSTR pcwszUserAgent;
    PROXY_ACCESS paUseProxy;
    BOOL fLocalBypass;
    DWORD dwPortNumber;
    LPCWSTR pcwszProxyName;
    LPCWSTR pcwszBypassList;
    } 	PROXY_INFO;

typedef 
enum _AUTH_TYPE
    {
        eAUTH_TYPE_ANONYMOUS	= 0,
        eAUTH_TYPE_NTLM	= ( eAUTH_TYPE_ANONYMOUS + 1 ) ,
        eAUTH_TYPE_BASIC	= ( eAUTH_TYPE_NTLM + 1 ) 
    } 	AUTH_TYPE;

typedef struct _AUTHENTICATION_INFO
    {
    DWORD dwSize;
    AUTH_TYPE atAuthenticationType;
    LPCWSTR pcwszUser;
    LPCWSTR pcwszPassword;
    } 	AUTHENTICATION_INFO;

typedef struct _INCREMENTAL_ACCESS_INFO
    {
    DWORD dwSize;
    FILETIME ftLastModifiedTime;
    } 	INCREMENTAL_ACCESS_INFO;

typedef struct _ITEM_INFO
    {
    DWORD dwSize;
    LPCWSTR pcwszFromEMail;
    LPCWSTR pcwszApplicationName;
    LPCWSTR pcwszCatalogName;
    LPCWSTR pcwszContentClass;
    } 	ITEM_INFO;





extern RPC_IF_HANDLE __MIDL_itf_searchapi_0000_0006_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_searchapi_0000_0006_v0_0_s_ifspec;

#ifndef __ISearchProtocol_INTERFACE_DEFINED__
#define __ISearchProtocol_INTERFACE_DEFINED__

/* interface ISearchProtocol */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_ISearchProtocol;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("c73106ba-ac80-11d1-8df3-00c04fb6ef4f")
    ISearchProtocol : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Init( 
            /* [annotation][in] */ 
            _In_  TIMEOUT_INFO *pTimeoutInfo,
            /* [annotation][in] */ 
            _In_  IProtocolHandlerSite *pProtocolHandlerSite,
            /* [annotation][in] */ 
            _In_  PROXY_INFO *pProxyInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateAccessor( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pcwszURL,
            /* [annotation][in] */ 
            _In_  AUTHENTICATION_INFO *pAuthenticationInfo,
            /* [annotation][in] */ 
            _In_  INCREMENTAL_ACCESS_INFO *pIncrementalAccessInfo,
            /* [annotation][in] */ 
            _In_  ITEM_INFO *pItemInfo,
            /* [annotation][out] */ 
            _Out_  IUrlAccessor **ppAccessor) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CloseAccessor( 
            /* [annotation][in] */ 
            _In_  IUrlAccessor *pAccessor) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ShutDown( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISearchProtocolVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISearchProtocol * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISearchProtocol * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISearchProtocol * This);
        
        DECLSPEC_XFGVIRT(ISearchProtocol, Init)
        HRESULT ( STDMETHODCALLTYPE *Init )( 
            ISearchProtocol * This,
            /* [annotation][in] */ 
            _In_  TIMEOUT_INFO *pTimeoutInfo,
            /* [annotation][in] */ 
            _In_  IProtocolHandlerSite *pProtocolHandlerSite,
            /* [annotation][in] */ 
            _In_  PROXY_INFO *pProxyInfo);
        
        DECLSPEC_XFGVIRT(ISearchProtocol, CreateAccessor)
        HRESULT ( STDMETHODCALLTYPE *CreateAccessor )( 
            ISearchProtocol * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pcwszURL,
            /* [annotation][in] */ 
            _In_  AUTHENTICATION_INFO *pAuthenticationInfo,
            /* [annotation][in] */ 
            _In_  INCREMENTAL_ACCESS_INFO *pIncrementalAccessInfo,
            /* [annotation][in] */ 
            _In_  ITEM_INFO *pItemInfo,
            /* [annotation][out] */ 
            _Out_  IUrlAccessor **ppAccessor);
        
        DECLSPEC_XFGVIRT(ISearchProtocol, CloseAccessor)
        HRESULT ( STDMETHODCALLTYPE *CloseAccessor )( 
            ISearchProtocol * This,
            /* [annotation][in] */ 
            _In_  IUrlAccessor *pAccessor);
        
        DECLSPEC_XFGVIRT(ISearchProtocol, ShutDown)
        HRESULT ( STDMETHODCALLTYPE *ShutDown )( 
            ISearchProtocol * This);
        
        END_INTERFACE
    } ISearchProtocolVtbl;

    interface ISearchProtocol
    {
        CONST_VTBL struct ISearchProtocolVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISearchProtocol_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISearchProtocol_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISearchProtocol_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISearchProtocol_Init(This,pTimeoutInfo,pProtocolHandlerSite,pProxyInfo)	\
    ( (This)->lpVtbl -> Init(This,pTimeoutInfo,pProtocolHandlerSite,pProxyInfo) ) 

#define ISearchProtocol_CreateAccessor(This,pcwszURL,pAuthenticationInfo,pIncrementalAccessInfo,pItemInfo,ppAccessor)	\
    ( (This)->lpVtbl -> CreateAccessor(This,pcwszURL,pAuthenticationInfo,pIncrementalAccessInfo,pItemInfo,ppAccessor) ) 

#define ISearchProtocol_CloseAccessor(This,pAccessor)	\
    ( (This)->lpVtbl -> CloseAccessor(This,pAccessor) ) 

#define ISearchProtocol_ShutDown(This)	\
    ( (This)->lpVtbl -> ShutDown(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISearchProtocol_INTERFACE_DEFINED__ */


#ifndef __ISearchProtocol2_INTERFACE_DEFINED__
#define __ISearchProtocol2_INTERFACE_DEFINED__

/* interface ISearchProtocol2 */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_ISearchProtocol2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7789F0B2-B5B2-4722-8B65-5DBD150697A9")
    ISearchProtocol2 : public ISearchProtocol
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CreateAccessorEx( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pcwszURL,
            /* [annotation][in] */ 
            _In_  AUTHENTICATION_INFO *pAuthenticationInfo,
            /* [annotation][in] */ 
            _In_  INCREMENTAL_ACCESS_INFO *pIncrementalAccessInfo,
            /* [annotation][in] */ 
            _In_  ITEM_INFO *pItemInfo,
            /* [annotation][in] */ 
            _In_  const BLOB *pUserData,
            /* [annotation][out] */ 
            _Out_  IUrlAccessor **ppAccessor) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISearchProtocol2Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISearchProtocol2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISearchProtocol2 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISearchProtocol2 * This);
        
        DECLSPEC_XFGVIRT(ISearchProtocol, Init)
        HRESULT ( STDMETHODCALLTYPE *Init )( 
            ISearchProtocol2 * This,
            /* [annotation][in] */ 
            _In_  TIMEOUT_INFO *pTimeoutInfo,
            /* [annotation][in] */ 
            _In_  IProtocolHandlerSite *pProtocolHandlerSite,
            /* [annotation][in] */ 
            _In_  PROXY_INFO *pProxyInfo);
        
        DECLSPEC_XFGVIRT(ISearchProtocol, CreateAccessor)
        HRESULT ( STDMETHODCALLTYPE *CreateAccessor )( 
            ISearchProtocol2 * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pcwszURL,
            /* [annotation][in] */ 
            _In_  AUTHENTICATION_INFO *pAuthenticationInfo,
            /* [annotation][in] */ 
            _In_  INCREMENTAL_ACCESS_INFO *pIncrementalAccessInfo,
            /* [annotation][in] */ 
            _In_  ITEM_INFO *pItemInfo,
            /* [annotation][out] */ 
            _Out_  IUrlAccessor **ppAccessor);
        
        DECLSPEC_XFGVIRT(ISearchProtocol, CloseAccessor)
        HRESULT ( STDMETHODCALLTYPE *CloseAccessor )( 
            ISearchProtocol2 * This,
            /* [annotation][in] */ 
            _In_  IUrlAccessor *pAccessor);
        
        DECLSPEC_XFGVIRT(ISearchProtocol, ShutDown)
        HRESULT ( STDMETHODCALLTYPE *ShutDown )( 
            ISearchProtocol2 * This);
        
        DECLSPEC_XFGVIRT(ISearchProtocol2, CreateAccessorEx)
        HRESULT ( STDMETHODCALLTYPE *CreateAccessorEx )( 
            ISearchProtocol2 * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pcwszURL,
            /* [annotation][in] */ 
            _In_  AUTHENTICATION_INFO *pAuthenticationInfo,
            /* [annotation][in] */ 
            _In_  INCREMENTAL_ACCESS_INFO *pIncrementalAccessInfo,
            /* [annotation][in] */ 
            _In_  ITEM_INFO *pItemInfo,
            /* [annotation][in] */ 
            _In_  const BLOB *pUserData,
            /* [annotation][out] */ 
            _Out_  IUrlAccessor **ppAccessor);
        
        END_INTERFACE
    } ISearchProtocol2Vtbl;

    interface ISearchProtocol2
    {
        CONST_VTBL struct ISearchProtocol2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISearchProtocol2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISearchProtocol2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISearchProtocol2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISearchProtocol2_Init(This,pTimeoutInfo,pProtocolHandlerSite,pProxyInfo)	\
    ( (This)->lpVtbl -> Init(This,pTimeoutInfo,pProtocolHandlerSite,pProxyInfo) ) 

#define ISearchProtocol2_CreateAccessor(This,pcwszURL,pAuthenticationInfo,pIncrementalAccessInfo,pItemInfo,ppAccessor)	\
    ( (This)->lpVtbl -> CreateAccessor(This,pcwszURL,pAuthenticationInfo,pIncrementalAccessInfo,pItemInfo,ppAccessor) ) 

#define ISearchProtocol2_CloseAccessor(This,pAccessor)	\
    ( (This)->lpVtbl -> CloseAccessor(This,pAccessor) ) 

#define ISearchProtocol2_ShutDown(This)	\
    ( (This)->lpVtbl -> ShutDown(This) ) 


#define ISearchProtocol2_CreateAccessorEx(This,pcwszURL,pAuthenticationInfo,pIncrementalAccessInfo,pItemInfo,pUserData,ppAccessor)	\
    ( (This)->lpVtbl -> CreateAccessorEx(This,pcwszURL,pAuthenticationInfo,pIncrementalAccessInfo,pItemInfo,pUserData,ppAccessor) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISearchProtocol2_INTERFACE_DEFINED__ */


#ifndef __IProtocolHandlerSite_INTERFACE_DEFINED__
#define __IProtocolHandlerSite_INTERFACE_DEFINED__

/* interface IProtocolHandlerSite */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_IProtocolHandlerSite;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0b63e385-9ccc-11d0-bcdb-00805fccce04")
    IProtocolHandlerSite : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetFilter( 
            /* [annotation][in] */ 
            _In_  CLSID *pclsidObj,
            /* [annotation][in] */ 
            _In_  LPCWSTR pcwszContentType,
            /* [annotation][in] */ 
            _In_  LPCWSTR pcwszExtension,
            /* [annotation][out] */ 
            _Out_  IFilter **ppFilter) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IProtocolHandlerSiteVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IProtocolHandlerSite * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IProtocolHandlerSite * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IProtocolHandlerSite * This);
        
        DECLSPEC_XFGVIRT(IProtocolHandlerSite, GetFilter)
        HRESULT ( STDMETHODCALLTYPE *GetFilter )( 
            IProtocolHandlerSite * This,
            /* [annotation][in] */ 
            _In_  CLSID *pclsidObj,
            /* [annotation][in] */ 
            _In_  LPCWSTR pcwszContentType,
            /* [annotation][in] */ 
            _In_  LPCWSTR pcwszExtension,
            /* [annotation][out] */ 
            _Out_  IFilter **ppFilter);
        
        END_INTERFACE
    } IProtocolHandlerSiteVtbl;

    interface IProtocolHandlerSite
    {
        CONST_VTBL struct IProtocolHandlerSiteVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IProtocolHandlerSite_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IProtocolHandlerSite_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IProtocolHandlerSite_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IProtocolHandlerSite_GetFilter(This,pclsidObj,pcwszContentType,pcwszExtension,ppFilter)	\
    ( (This)->lpVtbl -> GetFilter(This,pclsidObj,pcwszContentType,pcwszExtension,ppFilter) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IProtocolHandlerSite_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_searchapi_0000_0009 */
/* [local] */ 


#pragma pack()
#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion
#include <winapifamily.h>
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)


extern RPC_IF_HANDLE __MIDL_itf_searchapi_0000_0009_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_searchapi_0000_0009_v0_0_s_ifspec;

#ifndef __ISearchRoot_INTERFACE_DEFINED__
#define __ISearchRoot_INTERFACE_DEFINED__

/* interface ISearchRoot */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_ISearchRoot;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("04C18CCF-1F57-4CBD-88CC-3900F5195CE3")
    ISearchRoot : public IUnknown
    {
    public:
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_Schedule( 
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszTaskArg) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Schedule( 
            /* [annotation][string][retval][out] */ 
            _Out_retval_  LPWSTR *ppszTaskArg) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_RootURL( 
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszURL) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_RootURL( 
            /* [annotation][string][retval][out] */ 
            _Out_retval_  LPWSTR *ppszURL) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_IsHierarchical( 
            /* [annotation][in] */ 
            _In_  BOOL fIsHierarchical) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_IsHierarchical( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BOOL *pfIsHierarchical) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_ProvidesNotifications( 
            /* [annotation][in] */ 
            _In_  BOOL fProvidesNotifications) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_ProvidesNotifications( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BOOL *pfProvidesNotifications) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_UseNotificationsOnly( 
            /* [annotation][in] */ 
            _In_  BOOL fUseNotificationsOnly) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_UseNotificationsOnly( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BOOL *pfUseNotificationsOnly) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_EnumerationDepth( 
            /* [annotation][in] */ 
            _In_  DWORD dwDepth) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_EnumerationDepth( 
            /* [annotation][retval][out] */ 
            _Out_retval_  DWORD *pdwDepth) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_HostDepth( 
            /* [annotation][in] */ 
            _In_  DWORD dwDepth) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_HostDepth( 
            /* [annotation][retval][out] */ 
            _Out_retval_  DWORD *pdwDepth) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_FollowDirectories( 
            /* [annotation][in] */ 
            _In_  BOOL fFollowDirectories) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_FollowDirectories( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BOOL *pfFollowDirectories) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_AuthenticationType( 
            /* [annotation][in] */ 
            _In_  AUTH_TYPE authType) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_AuthenticationType( 
            /* [annotation][retval][out] */ 
            _Out_retval_  AUTH_TYPE *pAuthType) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_User( 
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszUser) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_User( 
            /* [annotation][string][retval][out] */ 
            _Out_retval_  LPWSTR *ppszUser) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_Password( 
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszPassword) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Password( 
            /* [annotation][string][retval][out] */ 
            _Out_retval_  LPWSTR *ppszPassword) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISearchRootVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISearchRoot * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISearchRoot * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISearchRoot * This);
        
        DECLSPEC_XFGVIRT(ISearchRoot, put_Schedule)
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_Schedule )( 
            __RPC__in ISearchRoot * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszTaskArg);
        
        DECLSPEC_XFGVIRT(ISearchRoot, get_Schedule)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Schedule )( 
            __RPC__in ISearchRoot * This,
            /* [annotation][string][retval][out] */ 
            _Out_retval_  LPWSTR *ppszTaskArg);
        
        DECLSPEC_XFGVIRT(ISearchRoot, put_RootURL)
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_RootURL )( 
            __RPC__in ISearchRoot * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszURL);
        
        DECLSPEC_XFGVIRT(ISearchRoot, get_RootURL)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_RootURL )( 
            __RPC__in ISearchRoot * This,
            /* [annotation][string][retval][out] */ 
            _Out_retval_  LPWSTR *ppszURL);
        
        DECLSPEC_XFGVIRT(ISearchRoot, put_IsHierarchical)
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_IsHierarchical )( 
            __RPC__in ISearchRoot * This,
            /* [annotation][in] */ 
            _In_  BOOL fIsHierarchical);
        
        DECLSPEC_XFGVIRT(ISearchRoot, get_IsHierarchical)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsHierarchical )( 
            __RPC__in ISearchRoot * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BOOL *pfIsHierarchical);
        
        DECLSPEC_XFGVIRT(ISearchRoot, put_ProvidesNotifications)
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_ProvidesNotifications )( 
            __RPC__in ISearchRoot * This,
            /* [annotation][in] */ 
            _In_  BOOL fProvidesNotifications);
        
        DECLSPEC_XFGVIRT(ISearchRoot, get_ProvidesNotifications)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_ProvidesNotifications )( 
            __RPC__in ISearchRoot * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BOOL *pfProvidesNotifications);
        
        DECLSPEC_XFGVIRT(ISearchRoot, put_UseNotificationsOnly)
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_UseNotificationsOnly )( 
            __RPC__in ISearchRoot * This,
            /* [annotation][in] */ 
            _In_  BOOL fUseNotificationsOnly);
        
        DECLSPEC_XFGVIRT(ISearchRoot, get_UseNotificationsOnly)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_UseNotificationsOnly )( 
            __RPC__in ISearchRoot * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BOOL *pfUseNotificationsOnly);
        
        DECLSPEC_XFGVIRT(ISearchRoot, put_EnumerationDepth)
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_EnumerationDepth )( 
            __RPC__in ISearchRoot * This,
            /* [annotation][in] */ 
            _In_  DWORD dwDepth);
        
        DECLSPEC_XFGVIRT(ISearchRoot, get_EnumerationDepth)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnumerationDepth )( 
            __RPC__in ISearchRoot * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  DWORD *pdwDepth);
        
        DECLSPEC_XFGVIRT(ISearchRoot, put_HostDepth)
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_HostDepth )( 
            __RPC__in ISearchRoot * This,
            /* [annotation][in] */ 
            _In_  DWORD dwDepth);
        
        DECLSPEC_XFGVIRT(ISearchRoot, get_HostDepth)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_HostDepth )( 
            __RPC__in ISearchRoot * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  DWORD *pdwDepth);
        
        DECLSPEC_XFGVIRT(ISearchRoot, put_FollowDirectories)
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_FollowDirectories )( 
            __RPC__in ISearchRoot * This,
            /* [annotation][in] */ 
            _In_  BOOL fFollowDirectories);
        
        DECLSPEC_XFGVIRT(ISearchRoot, get_FollowDirectories)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_FollowDirectories )( 
            __RPC__in ISearchRoot * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BOOL *pfFollowDirectories);
        
        DECLSPEC_XFGVIRT(ISearchRoot, put_AuthenticationType)
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_AuthenticationType )( 
            __RPC__in ISearchRoot * This,
            /* [annotation][in] */ 
            _In_  AUTH_TYPE authType);
        
        DECLSPEC_XFGVIRT(ISearchRoot, get_AuthenticationType)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_AuthenticationType )( 
            __RPC__in ISearchRoot * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  AUTH_TYPE *pAuthType);
        
        DECLSPEC_XFGVIRT(ISearchRoot, put_User)
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_User )( 
            __RPC__in ISearchRoot * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszUser);
        
        DECLSPEC_XFGVIRT(ISearchRoot, get_User)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_User )( 
            __RPC__in ISearchRoot * This,
            /* [annotation][string][retval][out] */ 
            _Out_retval_  LPWSTR *ppszUser);
        
        DECLSPEC_XFGVIRT(ISearchRoot, put_Password)
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_Password )( 
            __RPC__in ISearchRoot * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszPassword);
        
        DECLSPEC_XFGVIRT(ISearchRoot, get_Password)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Password )( 
            __RPC__in ISearchRoot * This,
            /* [annotation][string][retval][out] */ 
            _Out_retval_  LPWSTR *ppszPassword);
        
        END_INTERFACE
    } ISearchRootVtbl;

    interface ISearchRoot
    {
        CONST_VTBL struct ISearchRootVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISearchRoot_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISearchRoot_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISearchRoot_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISearchRoot_put_Schedule(This,pszTaskArg)	\
    ( (This)->lpVtbl -> put_Schedule(This,pszTaskArg) ) 

#define ISearchRoot_get_Schedule(This,ppszTaskArg)	\
    ( (This)->lpVtbl -> get_Schedule(This,ppszTaskArg) ) 

#define ISearchRoot_put_RootURL(This,pszURL)	\
    ( (This)->lpVtbl -> put_RootURL(This,pszURL) ) 

#define ISearchRoot_get_RootURL(This,ppszURL)	\
    ( (This)->lpVtbl -> get_RootURL(This,ppszURL) ) 

#define ISearchRoot_put_IsHierarchical(This,fIsHierarchical)	\
    ( (This)->lpVtbl -> put_IsHierarchical(This,fIsHierarchical) ) 

#define ISearchRoot_get_IsHierarchical(This,pfIsHierarchical)	\
    ( (This)->lpVtbl -> get_IsHierarchical(This,pfIsHierarchical) ) 

#define ISearchRoot_put_ProvidesNotifications(This,fProvidesNotifications)	\
    ( (This)->lpVtbl -> put_ProvidesNotifications(This,fProvidesNotifications) ) 

#define ISearchRoot_get_ProvidesNotifications(This,pfProvidesNotifications)	\
    ( (This)->lpVtbl -> get_ProvidesNotifications(This,pfProvidesNotifications) ) 

#define ISearchRoot_put_UseNotificationsOnly(This,fUseNotificationsOnly)	\
    ( (This)->lpVtbl -> put_UseNotificationsOnly(This,fUseNotificationsOnly) ) 

#define ISearchRoot_get_UseNotificationsOnly(This,pfUseNotificationsOnly)	\
    ( (This)->lpVtbl -> get_UseNotificationsOnly(This,pfUseNotificationsOnly) ) 

#define ISearchRoot_put_EnumerationDepth(This,dwDepth)	\
    ( (This)->lpVtbl -> put_EnumerationDepth(This,dwDepth) ) 

#define ISearchRoot_get_EnumerationDepth(This,pdwDepth)	\
    ( (This)->lpVtbl -> get_EnumerationDepth(This,pdwDepth) ) 

#define ISearchRoot_put_HostDepth(This,dwDepth)	\
    ( (This)->lpVtbl -> put_HostDepth(This,dwDepth) ) 

#define ISearchRoot_get_HostDepth(This,pdwDepth)	\
    ( (This)->lpVtbl -> get_HostDepth(This,pdwDepth) ) 

#define ISearchRoot_put_FollowDirectories(This,fFollowDirectories)	\
    ( (This)->lpVtbl -> put_FollowDirectories(This,fFollowDirectories) ) 

#define ISearchRoot_get_FollowDirectories(This,pfFollowDirectories)	\
    ( (This)->lpVtbl -> get_FollowDirectories(This,pfFollowDirectories) ) 

#define ISearchRoot_put_AuthenticationType(This,authType)	\
    ( (This)->lpVtbl -> put_AuthenticationType(This,authType) ) 

#define ISearchRoot_get_AuthenticationType(This,pAuthType)	\
    ( (This)->lpVtbl -> get_AuthenticationType(This,pAuthType) ) 

#define ISearchRoot_put_User(This,pszUser)	\
    ( (This)->lpVtbl -> put_User(This,pszUser) ) 

#define ISearchRoot_get_User(This,ppszUser)	\
    ( (This)->lpVtbl -> get_User(This,ppszUser) ) 

#define ISearchRoot_put_Password(This,pszPassword)	\
    ( (This)->lpVtbl -> put_Password(This,pszPassword) ) 

#define ISearchRoot_get_Password(This,ppszPassword)	\
    ( (This)->lpVtbl -> get_Password(This,ppszPassword) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISearchRoot_INTERFACE_DEFINED__ */


#ifndef __IEnumSearchRoots_INTERFACE_DEFINED__
#define __IEnumSearchRoots_INTERFACE_DEFINED__

/* interface IEnumSearchRoots */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IEnumSearchRoots;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("AB310581-AC80-11D1-8DF3-00C04FB6EF52")
    IEnumSearchRoots : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [annotation][in] */ 
            _In_  ULONG celt,
            /* [annotation][size_is][out] */ 
            _Out_writes_(celt)  ISearchRoot **rgelt,
            /* [annotation][unique][out][in] */ 
            _Inout_  ULONG *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [annotation][in] */ 
            _In_  ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IEnumSearchRoots **ppenum) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IEnumSearchRootsVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IEnumSearchRoots * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IEnumSearchRoots * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IEnumSearchRoots * This);
        
        DECLSPEC_XFGVIRT(IEnumSearchRoots, Next)
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            __RPC__in IEnumSearchRoots * This,
            /* [annotation][in] */ 
            _In_  ULONG celt,
            /* [annotation][size_is][out] */ 
            _Out_writes_(celt)  ISearchRoot **rgelt,
            /* [annotation][unique][out][in] */ 
            _Inout_  ULONG *pceltFetched);
        
        DECLSPEC_XFGVIRT(IEnumSearchRoots, Skip)
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            __RPC__in IEnumSearchRoots * This,
            /* [annotation][in] */ 
            _In_  ULONG celt);
        
        DECLSPEC_XFGVIRT(IEnumSearchRoots, Reset)
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            __RPC__in IEnumSearchRoots * This);
        
        DECLSPEC_XFGVIRT(IEnumSearchRoots, Clone)
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            __RPC__in IEnumSearchRoots * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IEnumSearchRoots **ppenum);
        
        END_INTERFACE
    } IEnumSearchRootsVtbl;

    interface IEnumSearchRoots
    {
        CONST_VTBL struct IEnumSearchRootsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumSearchRoots_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEnumSearchRoots_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEnumSearchRoots_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IEnumSearchRoots_Next(This,celt,rgelt,pceltFetched)	\
    ( (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched) ) 

#define IEnumSearchRoots_Skip(This,celt)	\
    ( (This)->lpVtbl -> Skip(This,celt) ) 

#define IEnumSearchRoots_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define IEnumSearchRoots_Clone(This,ppenum)	\
    ( (This)->lpVtbl -> Clone(This,ppenum) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IEnumSearchRoots_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_searchapi_0000_0011 */
/* [local] */ 

typedef /* [v1_enum] */ 
enum _FOLLOW_FLAGS
    {
        FF_INDEXCOMPLEXURLS	= 0x1,
        FF_SUPPRESSINDEXING	= 0x2
    } 	FOLLOW_FLAGS;



extern RPC_IF_HANDLE __MIDL_itf_searchapi_0000_0011_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_searchapi_0000_0011_v0_0_s_ifspec;

#ifndef __ISearchScopeRule_INTERFACE_DEFINED__
#define __ISearchScopeRule_INTERFACE_DEFINED__

/* interface ISearchScopeRule */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_ISearchScopeRule;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("AB310581-AC80-11D1-8DF3-00C04FB6EF53")
    ISearchScopeRule : public IUnknown
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_PatternOrURL( 
            /* [annotation][string][retval][out] */ 
            _Out_retval_  LPWSTR *ppszPatternOrURL) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_IsIncluded( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BOOL *pfIsIncluded) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_IsDefault( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BOOL *pfIsDefault) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_FollowFlags( 
            /* [annotation][retval][out] */ 
            _Out_retval_  DWORD *pFollowFlags) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISearchScopeRuleVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISearchScopeRule * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISearchScopeRule * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISearchScopeRule * This);
        
        DECLSPEC_XFGVIRT(ISearchScopeRule, get_PatternOrURL)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_PatternOrURL )( 
            __RPC__in ISearchScopeRule * This,
            /* [annotation][string][retval][out] */ 
            _Out_retval_  LPWSTR *ppszPatternOrURL);
        
        DECLSPEC_XFGVIRT(ISearchScopeRule, get_IsIncluded)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsIncluded )( 
            __RPC__in ISearchScopeRule * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BOOL *pfIsIncluded);
        
        DECLSPEC_XFGVIRT(ISearchScopeRule, get_IsDefault)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsDefault )( 
            __RPC__in ISearchScopeRule * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BOOL *pfIsDefault);
        
        DECLSPEC_XFGVIRT(ISearchScopeRule, get_FollowFlags)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_FollowFlags )( 
            __RPC__in ISearchScopeRule * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  DWORD *pFollowFlags);
        
        END_INTERFACE
    } ISearchScopeRuleVtbl;

    interface ISearchScopeRule
    {
        CONST_VTBL struct ISearchScopeRuleVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISearchScopeRule_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISearchScopeRule_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISearchScopeRule_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISearchScopeRule_get_PatternOrURL(This,ppszPatternOrURL)	\
    ( (This)->lpVtbl -> get_PatternOrURL(This,ppszPatternOrURL) ) 

#define ISearchScopeRule_get_IsIncluded(This,pfIsIncluded)	\
    ( (This)->lpVtbl -> get_IsIncluded(This,pfIsIncluded) ) 

#define ISearchScopeRule_get_IsDefault(This,pfIsDefault)	\
    ( (This)->lpVtbl -> get_IsDefault(This,pfIsDefault) ) 

#define ISearchScopeRule_get_FollowFlags(This,pFollowFlags)	\
    ( (This)->lpVtbl -> get_FollowFlags(This,pFollowFlags) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISearchScopeRule_INTERFACE_DEFINED__ */


#ifndef __IEnumSearchScopeRules_INTERFACE_DEFINED__
#define __IEnumSearchScopeRules_INTERFACE_DEFINED__

/* interface IEnumSearchScopeRules */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IEnumSearchScopeRules;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("AB310581-AC80-11D1-8DF3-00C04FB6EF54")
    IEnumSearchScopeRules : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [annotation][in] */ 
            _In_  ULONG celt,
            /* [annotation][size_is][out] */ 
            _Out_writes_(celt)  ISearchScopeRule **pprgelt,
            /* [annotation][unique][out][in] */ 
            _Inout_  ULONG *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [annotation][in] */ 
            _In_  ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IEnumSearchScopeRules **ppenum) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IEnumSearchScopeRulesVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IEnumSearchScopeRules * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IEnumSearchScopeRules * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IEnumSearchScopeRules * This);
        
        DECLSPEC_XFGVIRT(IEnumSearchScopeRules, Next)
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            __RPC__in IEnumSearchScopeRules * This,
            /* [annotation][in] */ 
            _In_  ULONG celt,
            /* [annotation][size_is][out] */ 
            _Out_writes_(celt)  ISearchScopeRule **pprgelt,
            /* [annotation][unique][out][in] */ 
            _Inout_  ULONG *pceltFetched);
        
        DECLSPEC_XFGVIRT(IEnumSearchScopeRules, Skip)
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            __RPC__in IEnumSearchScopeRules * This,
            /* [annotation][in] */ 
            _In_  ULONG celt);
        
        DECLSPEC_XFGVIRT(IEnumSearchScopeRules, Reset)
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            __RPC__in IEnumSearchScopeRules * This);
        
        DECLSPEC_XFGVIRT(IEnumSearchScopeRules, Clone)
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            __RPC__in IEnumSearchScopeRules * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IEnumSearchScopeRules **ppenum);
        
        END_INTERFACE
    } IEnumSearchScopeRulesVtbl;

    interface IEnumSearchScopeRules
    {
        CONST_VTBL struct IEnumSearchScopeRulesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumSearchScopeRules_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEnumSearchScopeRules_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEnumSearchScopeRules_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IEnumSearchScopeRules_Next(This,celt,pprgelt,pceltFetched)	\
    ( (This)->lpVtbl -> Next(This,celt,pprgelt,pceltFetched) ) 

#define IEnumSearchScopeRules_Skip(This,celt)	\
    ( (This)->lpVtbl -> Skip(This,celt) ) 

#define IEnumSearchScopeRules_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define IEnumSearchScopeRules_Clone(This,ppenum)	\
    ( (This)->lpVtbl -> Clone(This,ppenum) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IEnumSearchScopeRules_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_searchapi_0000_0013 */
/* [local] */ 

typedef /* [public][public] */ 
enum __MIDL___MIDL_itf_searchapi_0000_0013_0001
    {
        CLUSIONREASON_UNKNOWNSCOPE	= 0,
        CLUSIONREASON_DEFAULT	= 1,
        CLUSIONREASON_USER	= 2,
        CLUSIONREASON_GROUPPOLICY	= 3
    } 	CLUSION_REASON;



extern RPC_IF_HANDLE __MIDL_itf_searchapi_0000_0013_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_searchapi_0000_0013_v0_0_s_ifspec;

#ifndef __ISearchCrawlScopeManager_INTERFACE_DEFINED__
#define __ISearchCrawlScopeManager_INTERFACE_DEFINED__

/* interface ISearchCrawlScopeManager */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_ISearchCrawlScopeManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("AB310581-AC80-11D1-8DF3-00C04FB6EF55")
    ISearchCrawlScopeManager : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AddDefaultScopeRule( 
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszURL,
            /* [annotation][in] */ 
            _In_  BOOL fInclude,
            /* [annotation][in] */ 
            _In_  DWORD fFollowFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddRoot( 
            /* [annotation][in] */ 
            _In_  ISearchRoot *pSearchRoot) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveRoot( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszURL) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumerateRoots( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IEnumSearchRoots **ppSearchRoots) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddHierarchicalScope( 
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszURL,
            /* [annotation][in] */ 
            _In_  BOOL fInclude,
            /* [annotation][in] */ 
            _In_  BOOL fDefault,
            /* [annotation][in] */ 
            _In_  BOOL fOverrideChildren) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddUserScopeRule( 
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszURL,
            /* [annotation][in] */ 
            _In_  BOOL fInclude,
            /* [annotation][in] */ 
            _In_  BOOL fOverrideChildren,
            /* [annotation][in] */ 
            _In_  DWORD fFollowFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveScopeRule( 
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszRule) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumerateScopeRules( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IEnumSearchScopeRules **ppSearchScopeRules) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE HasParentScopeRule( 
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszURL,
            /* [annotation][retval][out] */ 
            _Out_retval_  BOOL *pfHasParentRule) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE HasChildScopeRule( 
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszURL,
            /* [annotation][retval][out] */ 
            _Out_retval_  BOOL *pfHasChildRule) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IncludedInCrawlScope( 
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszURL,
            /* [annotation][retval][out] */ 
            _Out_retval_  BOOL *pfIsIncluded) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IncludedInCrawlScopeEx( 
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszURL,
            /* [annotation][out] */ 
            _Out_  BOOL *pfIsIncluded,
            /* [annotation][out] */ 
            _Out_  CLUSION_REASON *pReason) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RevertToDefaultScopes( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SaveAll( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetParentScopeVersionId( 
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszURL,
            /* [annotation][retval][out] */ 
            _Out_retval_  LONG *plScopeId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveDefaultScopeRule( 
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszURL) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISearchCrawlScopeManagerVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISearchCrawlScopeManager * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISearchCrawlScopeManager * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISearchCrawlScopeManager * This);
        
        DECLSPEC_XFGVIRT(ISearchCrawlScopeManager, AddDefaultScopeRule)
        HRESULT ( STDMETHODCALLTYPE *AddDefaultScopeRule )( 
            __RPC__in ISearchCrawlScopeManager * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszURL,
            /* [annotation][in] */ 
            _In_  BOOL fInclude,
            /* [annotation][in] */ 
            _In_  DWORD fFollowFlags);
        
        DECLSPEC_XFGVIRT(ISearchCrawlScopeManager, AddRoot)
        HRESULT ( STDMETHODCALLTYPE *AddRoot )( 
            __RPC__in ISearchCrawlScopeManager * This,
            /* [annotation][in] */ 
            _In_  ISearchRoot *pSearchRoot);
        
        DECLSPEC_XFGVIRT(ISearchCrawlScopeManager, RemoveRoot)
        HRESULT ( STDMETHODCALLTYPE *RemoveRoot )( 
            __RPC__in ISearchCrawlScopeManager * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszURL);
        
        DECLSPEC_XFGVIRT(ISearchCrawlScopeManager, EnumerateRoots)
        HRESULT ( STDMETHODCALLTYPE *EnumerateRoots )( 
            __RPC__in ISearchCrawlScopeManager * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IEnumSearchRoots **ppSearchRoots);
        
        DECLSPEC_XFGVIRT(ISearchCrawlScopeManager, AddHierarchicalScope)
        HRESULT ( STDMETHODCALLTYPE *AddHierarchicalScope )( 
            __RPC__in ISearchCrawlScopeManager * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszURL,
            /* [annotation][in] */ 
            _In_  BOOL fInclude,
            /* [annotation][in] */ 
            _In_  BOOL fDefault,
            /* [annotation][in] */ 
            _In_  BOOL fOverrideChildren);
        
        DECLSPEC_XFGVIRT(ISearchCrawlScopeManager, AddUserScopeRule)
        HRESULT ( STDMETHODCALLTYPE *AddUserScopeRule )( 
            __RPC__in ISearchCrawlScopeManager * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszURL,
            /* [annotation][in] */ 
            _In_  BOOL fInclude,
            /* [annotation][in] */ 
            _In_  BOOL fOverrideChildren,
            /* [annotation][in] */ 
            _In_  DWORD fFollowFlags);
        
        DECLSPEC_XFGVIRT(ISearchCrawlScopeManager, RemoveScopeRule)
        HRESULT ( STDMETHODCALLTYPE *RemoveScopeRule )( 
            __RPC__in ISearchCrawlScopeManager * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszRule);
        
        DECLSPEC_XFGVIRT(ISearchCrawlScopeManager, EnumerateScopeRules)
        HRESULT ( STDMETHODCALLTYPE *EnumerateScopeRules )( 
            __RPC__in ISearchCrawlScopeManager * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IEnumSearchScopeRules **ppSearchScopeRules);
        
        DECLSPEC_XFGVIRT(ISearchCrawlScopeManager, HasParentScopeRule)
        HRESULT ( STDMETHODCALLTYPE *HasParentScopeRule )( 
            __RPC__in ISearchCrawlScopeManager * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszURL,
            /* [annotation][retval][out] */ 
            _Out_retval_  BOOL *pfHasParentRule);
        
        DECLSPEC_XFGVIRT(ISearchCrawlScopeManager, HasChildScopeRule)
        HRESULT ( STDMETHODCALLTYPE *HasChildScopeRule )( 
            __RPC__in ISearchCrawlScopeManager * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszURL,
            /* [annotation][retval][out] */ 
            _Out_retval_  BOOL *pfHasChildRule);
        
        DECLSPEC_XFGVIRT(ISearchCrawlScopeManager, IncludedInCrawlScope)
        HRESULT ( STDMETHODCALLTYPE *IncludedInCrawlScope )( 
            __RPC__in ISearchCrawlScopeManager * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszURL,
            /* [annotation][retval][out] */ 
            _Out_retval_  BOOL *pfIsIncluded);
        
        DECLSPEC_XFGVIRT(ISearchCrawlScopeManager, IncludedInCrawlScopeEx)
        HRESULT ( STDMETHODCALLTYPE *IncludedInCrawlScopeEx )( 
            __RPC__in ISearchCrawlScopeManager * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszURL,
            /* [annotation][out] */ 
            _Out_  BOOL *pfIsIncluded,
            /* [annotation][out] */ 
            _Out_  CLUSION_REASON *pReason);
        
        DECLSPEC_XFGVIRT(ISearchCrawlScopeManager, RevertToDefaultScopes)
        HRESULT ( STDMETHODCALLTYPE *RevertToDefaultScopes )( 
            __RPC__in ISearchCrawlScopeManager * This);
        
        DECLSPEC_XFGVIRT(ISearchCrawlScopeManager, SaveAll)
        HRESULT ( STDMETHODCALLTYPE *SaveAll )( 
            __RPC__in ISearchCrawlScopeManager * This);
        
        DECLSPEC_XFGVIRT(ISearchCrawlScopeManager, GetParentScopeVersionId)
        HRESULT ( STDMETHODCALLTYPE *GetParentScopeVersionId )( 
            __RPC__in ISearchCrawlScopeManager * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszURL,
            /* [annotation][retval][out] */ 
            _Out_retval_  LONG *plScopeId);
        
        DECLSPEC_XFGVIRT(ISearchCrawlScopeManager, RemoveDefaultScopeRule)
        HRESULT ( STDMETHODCALLTYPE *RemoveDefaultScopeRule )( 
            __RPC__in ISearchCrawlScopeManager * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszURL);
        
        END_INTERFACE
    } ISearchCrawlScopeManagerVtbl;

    interface ISearchCrawlScopeManager
    {
        CONST_VTBL struct ISearchCrawlScopeManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISearchCrawlScopeManager_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISearchCrawlScopeManager_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISearchCrawlScopeManager_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISearchCrawlScopeManager_AddDefaultScopeRule(This,pszURL,fInclude,fFollowFlags)	\
    ( (This)->lpVtbl -> AddDefaultScopeRule(This,pszURL,fInclude,fFollowFlags) ) 

#define ISearchCrawlScopeManager_AddRoot(This,pSearchRoot)	\
    ( (This)->lpVtbl -> AddRoot(This,pSearchRoot) ) 

#define ISearchCrawlScopeManager_RemoveRoot(This,pszURL)	\
    ( (This)->lpVtbl -> RemoveRoot(This,pszURL) ) 

#define ISearchCrawlScopeManager_EnumerateRoots(This,ppSearchRoots)	\
    ( (This)->lpVtbl -> EnumerateRoots(This,ppSearchRoots) ) 

#define ISearchCrawlScopeManager_AddHierarchicalScope(This,pszURL,fInclude,fDefault,fOverrideChildren)	\
    ( (This)->lpVtbl -> AddHierarchicalScope(This,pszURL,fInclude,fDefault,fOverrideChildren) ) 

#define ISearchCrawlScopeManager_AddUserScopeRule(This,pszURL,fInclude,fOverrideChildren,fFollowFlags)	\
    ( (This)->lpVtbl -> AddUserScopeRule(This,pszURL,fInclude,fOverrideChildren,fFollowFlags) ) 

#define ISearchCrawlScopeManager_RemoveScopeRule(This,pszRule)	\
    ( (This)->lpVtbl -> RemoveScopeRule(This,pszRule) ) 

#define ISearchCrawlScopeManager_EnumerateScopeRules(This,ppSearchScopeRules)	\
    ( (This)->lpVtbl -> EnumerateScopeRules(This,ppSearchScopeRules) ) 

#define ISearchCrawlScopeManager_HasParentScopeRule(This,pszURL,pfHasParentRule)	\
    ( (This)->lpVtbl -> HasParentScopeRule(This,pszURL,pfHasParentRule) ) 

#define ISearchCrawlScopeManager_HasChildScopeRule(This,pszURL,pfHasChildRule)	\
    ( (This)->lpVtbl -> HasChildScopeRule(This,pszURL,pfHasChildRule) ) 

#define ISearchCrawlScopeManager_IncludedInCrawlScope(This,pszURL,pfIsIncluded)	\
    ( (This)->lpVtbl -> IncludedInCrawlScope(This,pszURL,pfIsIncluded) ) 

#define ISearchCrawlScopeManager_IncludedInCrawlScopeEx(This,pszURL,pfIsIncluded,pReason)	\
    ( (This)->lpVtbl -> IncludedInCrawlScopeEx(This,pszURL,pfIsIncluded,pReason) ) 

#define ISearchCrawlScopeManager_RevertToDefaultScopes(This)	\
    ( (This)->lpVtbl -> RevertToDefaultScopes(This) ) 

#define ISearchCrawlScopeManager_SaveAll(This)	\
    ( (This)->lpVtbl -> SaveAll(This) ) 

#define ISearchCrawlScopeManager_GetParentScopeVersionId(This,pszURL,plScopeId)	\
    ( (This)->lpVtbl -> GetParentScopeVersionId(This,pszURL,plScopeId) ) 

#define ISearchCrawlScopeManager_RemoveDefaultScopeRule(This,pszURL)	\
    ( (This)->lpVtbl -> RemoveDefaultScopeRule(This,pszURL) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISearchCrawlScopeManager_INTERFACE_DEFINED__ */


#ifndef __ISearchCrawlScopeManager2_INTERFACE_DEFINED__
#define __ISearchCrawlScopeManager2_INTERFACE_DEFINED__

/* interface ISearchCrawlScopeManager2 */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_ISearchCrawlScopeManager2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6292F7AD-4E19-4717-A534-8FC22BCD5CCD")
    ISearchCrawlScopeManager2 : public ISearchCrawlScopeManager
    {
    public:
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE GetVersion( 
            /* [annotation][out] */ 
            _Out_  long **plVersion,
            /* [annotation][out] */ 
            _Out_  HANDLE *phFileMapping) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISearchCrawlScopeManager2Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISearchCrawlScopeManager2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISearchCrawlScopeManager2 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISearchCrawlScopeManager2 * This);
        
        DECLSPEC_XFGVIRT(ISearchCrawlScopeManager, AddDefaultScopeRule)
        HRESULT ( STDMETHODCALLTYPE *AddDefaultScopeRule )( 
            __RPC__in ISearchCrawlScopeManager2 * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszURL,
            /* [annotation][in] */ 
            _In_  BOOL fInclude,
            /* [annotation][in] */ 
            _In_  DWORD fFollowFlags);
        
        DECLSPEC_XFGVIRT(ISearchCrawlScopeManager, AddRoot)
        HRESULT ( STDMETHODCALLTYPE *AddRoot )( 
            __RPC__in ISearchCrawlScopeManager2 * This,
            /* [annotation][in] */ 
            _In_  ISearchRoot *pSearchRoot);
        
        DECLSPEC_XFGVIRT(ISearchCrawlScopeManager, RemoveRoot)
        HRESULT ( STDMETHODCALLTYPE *RemoveRoot )( 
            __RPC__in ISearchCrawlScopeManager2 * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszURL);
        
        DECLSPEC_XFGVIRT(ISearchCrawlScopeManager, EnumerateRoots)
        HRESULT ( STDMETHODCALLTYPE *EnumerateRoots )( 
            __RPC__in ISearchCrawlScopeManager2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IEnumSearchRoots **ppSearchRoots);
        
        DECLSPEC_XFGVIRT(ISearchCrawlScopeManager, AddHierarchicalScope)
        HRESULT ( STDMETHODCALLTYPE *AddHierarchicalScope )( 
            __RPC__in ISearchCrawlScopeManager2 * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszURL,
            /* [annotation][in] */ 
            _In_  BOOL fInclude,
            /* [annotation][in] */ 
            _In_  BOOL fDefault,
            /* [annotation][in] */ 
            _In_  BOOL fOverrideChildren);
        
        DECLSPEC_XFGVIRT(ISearchCrawlScopeManager, AddUserScopeRule)
        HRESULT ( STDMETHODCALLTYPE *AddUserScopeRule )( 
            __RPC__in ISearchCrawlScopeManager2 * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszURL,
            /* [annotation][in] */ 
            _In_  BOOL fInclude,
            /* [annotation][in] */ 
            _In_  BOOL fOverrideChildren,
            /* [annotation][in] */ 
            _In_  DWORD fFollowFlags);
        
        DECLSPEC_XFGVIRT(ISearchCrawlScopeManager, RemoveScopeRule)
        HRESULT ( STDMETHODCALLTYPE *RemoveScopeRule )( 
            __RPC__in ISearchCrawlScopeManager2 * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszRule);
        
        DECLSPEC_XFGVIRT(ISearchCrawlScopeManager, EnumerateScopeRules)
        HRESULT ( STDMETHODCALLTYPE *EnumerateScopeRules )( 
            __RPC__in ISearchCrawlScopeManager2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IEnumSearchScopeRules **ppSearchScopeRules);
        
        DECLSPEC_XFGVIRT(ISearchCrawlScopeManager, HasParentScopeRule)
        HRESULT ( STDMETHODCALLTYPE *HasParentScopeRule )( 
            __RPC__in ISearchCrawlScopeManager2 * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszURL,
            /* [annotation][retval][out] */ 
            _Out_retval_  BOOL *pfHasParentRule);
        
        DECLSPEC_XFGVIRT(ISearchCrawlScopeManager, HasChildScopeRule)
        HRESULT ( STDMETHODCALLTYPE *HasChildScopeRule )( 
            __RPC__in ISearchCrawlScopeManager2 * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszURL,
            /* [annotation][retval][out] */ 
            _Out_retval_  BOOL *pfHasChildRule);
        
        DECLSPEC_XFGVIRT(ISearchCrawlScopeManager, IncludedInCrawlScope)
        HRESULT ( STDMETHODCALLTYPE *IncludedInCrawlScope )( 
            __RPC__in ISearchCrawlScopeManager2 * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszURL,
            /* [annotation][retval][out] */ 
            _Out_retval_  BOOL *pfIsIncluded);
        
        DECLSPEC_XFGVIRT(ISearchCrawlScopeManager, IncludedInCrawlScopeEx)
        HRESULT ( STDMETHODCALLTYPE *IncludedInCrawlScopeEx )( 
            __RPC__in ISearchCrawlScopeManager2 * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszURL,
            /* [annotation][out] */ 
            _Out_  BOOL *pfIsIncluded,
            /* [annotation][out] */ 
            _Out_  CLUSION_REASON *pReason);
        
        DECLSPEC_XFGVIRT(ISearchCrawlScopeManager, RevertToDefaultScopes)
        HRESULT ( STDMETHODCALLTYPE *RevertToDefaultScopes )( 
            __RPC__in ISearchCrawlScopeManager2 * This);
        
        DECLSPEC_XFGVIRT(ISearchCrawlScopeManager, SaveAll)
        HRESULT ( STDMETHODCALLTYPE *SaveAll )( 
            __RPC__in ISearchCrawlScopeManager2 * This);
        
        DECLSPEC_XFGVIRT(ISearchCrawlScopeManager, GetParentScopeVersionId)
        HRESULT ( STDMETHODCALLTYPE *GetParentScopeVersionId )( 
            __RPC__in ISearchCrawlScopeManager2 * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszURL,
            /* [annotation][retval][out] */ 
            _Out_retval_  LONG *plScopeId);
        
        DECLSPEC_XFGVIRT(ISearchCrawlScopeManager, RemoveDefaultScopeRule)
        HRESULT ( STDMETHODCALLTYPE *RemoveDefaultScopeRule )( 
            __RPC__in ISearchCrawlScopeManager2 * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszURL);
        
        DECLSPEC_XFGVIRT(ISearchCrawlScopeManager2, GetVersion)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *GetVersion )( 
            ISearchCrawlScopeManager2 * This,
            /* [annotation][out] */ 
            _Out_  long **plVersion,
            /* [annotation][out] */ 
            _Out_  HANDLE *phFileMapping);
        
        END_INTERFACE
    } ISearchCrawlScopeManager2Vtbl;

    interface ISearchCrawlScopeManager2
    {
        CONST_VTBL struct ISearchCrawlScopeManager2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISearchCrawlScopeManager2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISearchCrawlScopeManager2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISearchCrawlScopeManager2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISearchCrawlScopeManager2_AddDefaultScopeRule(This,pszURL,fInclude,fFollowFlags)	\
    ( (This)->lpVtbl -> AddDefaultScopeRule(This,pszURL,fInclude,fFollowFlags) ) 

#define ISearchCrawlScopeManager2_AddRoot(This,pSearchRoot)	\
    ( (This)->lpVtbl -> AddRoot(This,pSearchRoot) ) 

#define ISearchCrawlScopeManager2_RemoveRoot(This,pszURL)	\
    ( (This)->lpVtbl -> RemoveRoot(This,pszURL) ) 

#define ISearchCrawlScopeManager2_EnumerateRoots(This,ppSearchRoots)	\
    ( (This)->lpVtbl -> EnumerateRoots(This,ppSearchRoots) ) 

#define ISearchCrawlScopeManager2_AddHierarchicalScope(This,pszURL,fInclude,fDefault,fOverrideChildren)	\
    ( (This)->lpVtbl -> AddHierarchicalScope(This,pszURL,fInclude,fDefault,fOverrideChildren) ) 

#define ISearchCrawlScopeManager2_AddUserScopeRule(This,pszURL,fInclude,fOverrideChildren,fFollowFlags)	\
    ( (This)->lpVtbl -> AddUserScopeRule(This,pszURL,fInclude,fOverrideChildren,fFollowFlags) ) 

#define ISearchCrawlScopeManager2_RemoveScopeRule(This,pszRule)	\
    ( (This)->lpVtbl -> RemoveScopeRule(This,pszRule) ) 

#define ISearchCrawlScopeManager2_EnumerateScopeRules(This,ppSearchScopeRules)	\
    ( (This)->lpVtbl -> EnumerateScopeRules(This,ppSearchScopeRules) ) 

#define ISearchCrawlScopeManager2_HasParentScopeRule(This,pszURL,pfHasParentRule)	\
    ( (This)->lpVtbl -> HasParentScopeRule(This,pszURL,pfHasParentRule) ) 

#define ISearchCrawlScopeManager2_HasChildScopeRule(This,pszURL,pfHasChildRule)	\
    ( (This)->lpVtbl -> HasChildScopeRule(This,pszURL,pfHasChildRule) ) 

#define ISearchCrawlScopeManager2_IncludedInCrawlScope(This,pszURL,pfIsIncluded)	\
    ( (This)->lpVtbl -> IncludedInCrawlScope(This,pszURL,pfIsIncluded) ) 

#define ISearchCrawlScopeManager2_IncludedInCrawlScopeEx(This,pszURL,pfIsIncluded,pReason)	\
    ( (This)->lpVtbl -> IncludedInCrawlScopeEx(This,pszURL,pfIsIncluded,pReason) ) 

#define ISearchCrawlScopeManager2_RevertToDefaultScopes(This)	\
    ( (This)->lpVtbl -> RevertToDefaultScopes(This) ) 

#define ISearchCrawlScopeManager2_SaveAll(This)	\
    ( (This)->lpVtbl -> SaveAll(This) ) 

#define ISearchCrawlScopeManager2_GetParentScopeVersionId(This,pszURL,plScopeId)	\
    ( (This)->lpVtbl -> GetParentScopeVersionId(This,pszURL,plScopeId) ) 

#define ISearchCrawlScopeManager2_RemoveDefaultScopeRule(This,pszURL)	\
    ( (This)->lpVtbl -> RemoveDefaultScopeRule(This,pszURL) ) 


#define ISearchCrawlScopeManager2_GetVersion(This,plVersion,phFileMapping)	\
    ( (This)->lpVtbl -> GetVersion(This,plVersion,phFileMapping) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT STDMETHODCALLTYPE ISearchCrawlScopeManager2_RemoteGetVersion_Proxy( 
    __RPC__in ISearchCrawlScopeManager2 * This,
    /* [annotation][out] */ 
    _Out_  long *plVersion);


void __RPC_STUB ISearchCrawlScopeManager2_RemoteGetVersion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ISearchCrawlScopeManager2_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_searchapi_0000_0015 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion
#include <winapifamily.h>
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
typedef /* [v1_enum] */ 
enum _SEARCH_KIND_OF_CHANGE
    {
        SEARCH_CHANGE_ADD	= 0,
        SEARCH_CHANGE_DELETE	= 1,
        SEARCH_CHANGE_MODIFY	= 2,
        SEARCH_CHANGE_MOVE_RENAME	= 3,
        SEARCH_CHANGE_SEMANTICS_DIRECTORY	= 0x40000,
        SEARCH_CHANGE_SEMANTICS_SHALLOW	= 0x80000,
        SEARCH_CHANGE_SEMANTICS_UPDATE_SECURITY	= 0x400000
    } 	SEARCH_KIND_OF_CHANGE;

typedef 
enum _SEARCH_NOTIFICATION_PRIORITY
    {
        SEARCH_NORMAL_PRIORITY	= 0,
        SEARCH_HIGH_PRIORITY	= 1
    } 	SEARCH_NOTIFICATION_PRIORITY;



extern RPC_IF_HANDLE __MIDL_itf_searchapi_0000_0015_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_searchapi_0000_0015_v0_0_s_ifspec;

#ifndef __ISearchItemsChangedSink_INTERFACE_DEFINED__
#define __ISearchItemsChangedSink_INTERFACE_DEFINED__

/* interface ISearchItemsChangedSink */
/* [unique][uuid][object] */ 

typedef struct _SEARCH_ITEM_CHANGE
    {
    SEARCH_KIND_OF_CHANGE Change;
    SEARCH_NOTIFICATION_PRIORITY Priority;
    BLOB *pUserData;
    LPWSTR lpwszURL;
    /* [unique] */ LPWSTR lpwszOldURL;
    } 	SEARCH_ITEM_CHANGE;


EXTERN_C const IID IID_ISearchItemsChangedSink;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("AB310581-AC80-11D1-8DF3-00C04FB6EF58")
    ISearchItemsChangedSink : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE StartedMonitoringScope( 
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszURL) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StoppedMonitoringScope( 
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszURL) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnItemsChanged( 
            /* [annotation][in] */ 
            _In_  DWORD dwNumberOfChanges,
            /* [annotation][size_is][in] */ 
            _In_reads_(dwNumberOfChanges)  SEARCH_ITEM_CHANGE rgDataChangeEntries[  ],
            /* [annotation][size_is][out] */ 
            _Out_writes_(dwNumberOfChanges)  DWORD rgdwDocIds[  ],
            /* [annotation][size_is][out] */ 
            _Out_writes_(dwNumberOfChanges)  HRESULT rghrCompletionCodes[  ]) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISearchItemsChangedSinkVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISearchItemsChangedSink * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISearchItemsChangedSink * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISearchItemsChangedSink * This);
        
        DECLSPEC_XFGVIRT(ISearchItemsChangedSink, StartedMonitoringScope)
        HRESULT ( STDMETHODCALLTYPE *StartedMonitoringScope )( 
            __RPC__in ISearchItemsChangedSink * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszURL);
        
        DECLSPEC_XFGVIRT(ISearchItemsChangedSink, StoppedMonitoringScope)
        HRESULT ( STDMETHODCALLTYPE *StoppedMonitoringScope )( 
            __RPC__in ISearchItemsChangedSink * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszURL);
        
        DECLSPEC_XFGVIRT(ISearchItemsChangedSink, OnItemsChanged)
        HRESULT ( STDMETHODCALLTYPE *OnItemsChanged )( 
            __RPC__in ISearchItemsChangedSink * This,
            /* [annotation][in] */ 
            _In_  DWORD dwNumberOfChanges,
            /* [annotation][size_is][in] */ 
            _In_reads_(dwNumberOfChanges)  SEARCH_ITEM_CHANGE rgDataChangeEntries[  ],
            /* [annotation][size_is][out] */ 
            _Out_writes_(dwNumberOfChanges)  DWORD rgdwDocIds[  ],
            /* [annotation][size_is][out] */ 
            _Out_writes_(dwNumberOfChanges)  HRESULT rghrCompletionCodes[  ]);
        
        END_INTERFACE
    } ISearchItemsChangedSinkVtbl;

    interface ISearchItemsChangedSink
    {
        CONST_VTBL struct ISearchItemsChangedSinkVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISearchItemsChangedSink_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISearchItemsChangedSink_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISearchItemsChangedSink_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISearchItemsChangedSink_StartedMonitoringScope(This,pszURL)	\
    ( (This)->lpVtbl -> StartedMonitoringScope(This,pszURL) ) 

#define ISearchItemsChangedSink_StoppedMonitoringScope(This,pszURL)	\
    ( (This)->lpVtbl -> StoppedMonitoringScope(This,pszURL) ) 

#define ISearchItemsChangedSink_OnItemsChanged(This,dwNumberOfChanges,rgDataChangeEntries,rgdwDocIds,rghrCompletionCodes)	\
    ( (This)->lpVtbl -> OnItemsChanged(This,dwNumberOfChanges,rgDataChangeEntries,rgdwDocIds,rghrCompletionCodes) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISearchItemsChangedSink_INTERFACE_DEFINED__ */


#ifndef __ISearchPersistentItemsChangedSink_INTERFACE_DEFINED__
#define __ISearchPersistentItemsChangedSink_INTERFACE_DEFINED__

/* interface ISearchPersistentItemsChangedSink */
/* [unique][uuid][object] */ 

typedef struct _SEARCH_ITEM_PERSISTENT_CHANGE
    {
    SEARCH_KIND_OF_CHANGE Change;
    LPWSTR URL;
    /* [unique] */ LPWSTR OldURL;
    SEARCH_NOTIFICATION_PRIORITY Priority;
    } 	SEARCH_ITEM_PERSISTENT_CHANGE;


EXTERN_C const IID IID_ISearchPersistentItemsChangedSink;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A2FFDF9B-4758-4F84-B729-DF81A1A0612F")
    ISearchPersistentItemsChangedSink : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE StartedMonitoringScope( 
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszURL) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StoppedMonitoringScope( 
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszURL) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnItemsChanged( 
            /* [annotation][in] */ 
            _In_  DWORD dwNumberOfChanges,
            /* [annotation][size_is][in] */ 
            _In_reads_(dwNumberOfChanges)  SEARCH_ITEM_PERSISTENT_CHANGE DataChangeEntries[  ],
            /* [annotation][size_is][out] */ 
            _Out_writes_(dwNumberOfChanges)  HRESULT hrCompletionCodes[  ]) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISearchPersistentItemsChangedSinkVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISearchPersistentItemsChangedSink * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISearchPersistentItemsChangedSink * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISearchPersistentItemsChangedSink * This);
        
        DECLSPEC_XFGVIRT(ISearchPersistentItemsChangedSink, StartedMonitoringScope)
        HRESULT ( STDMETHODCALLTYPE *StartedMonitoringScope )( 
            __RPC__in ISearchPersistentItemsChangedSink * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszURL);
        
        DECLSPEC_XFGVIRT(ISearchPersistentItemsChangedSink, StoppedMonitoringScope)
        HRESULT ( STDMETHODCALLTYPE *StoppedMonitoringScope )( 
            __RPC__in ISearchPersistentItemsChangedSink * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszURL);
        
        DECLSPEC_XFGVIRT(ISearchPersistentItemsChangedSink, OnItemsChanged)
        HRESULT ( STDMETHODCALLTYPE *OnItemsChanged )( 
            __RPC__in ISearchPersistentItemsChangedSink * This,
            /* [annotation][in] */ 
            _In_  DWORD dwNumberOfChanges,
            /* [annotation][size_is][in] */ 
            _In_reads_(dwNumberOfChanges)  SEARCH_ITEM_PERSISTENT_CHANGE DataChangeEntries[  ],
            /* [annotation][size_is][out] */ 
            _Out_writes_(dwNumberOfChanges)  HRESULT hrCompletionCodes[  ]);
        
        END_INTERFACE
    } ISearchPersistentItemsChangedSinkVtbl;

    interface ISearchPersistentItemsChangedSink
    {
        CONST_VTBL struct ISearchPersistentItemsChangedSinkVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISearchPersistentItemsChangedSink_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISearchPersistentItemsChangedSink_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISearchPersistentItemsChangedSink_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISearchPersistentItemsChangedSink_StartedMonitoringScope(This,pszURL)	\
    ( (This)->lpVtbl -> StartedMonitoringScope(This,pszURL) ) 

#define ISearchPersistentItemsChangedSink_StoppedMonitoringScope(This,pszURL)	\
    ( (This)->lpVtbl -> StoppedMonitoringScope(This,pszURL) ) 

#define ISearchPersistentItemsChangedSink_OnItemsChanged(This,dwNumberOfChanges,DataChangeEntries,hrCompletionCodes)	\
    ( (This)->lpVtbl -> OnItemsChanged(This,dwNumberOfChanges,DataChangeEntries,hrCompletionCodes) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISearchPersistentItemsChangedSink_INTERFACE_DEFINED__ */


#ifndef __ISearchViewChangedSink_INTERFACE_DEFINED__
#define __ISearchViewChangedSink_INTERFACE_DEFINED__

/* interface ISearchViewChangedSink */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_ISearchViewChangedSink;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("AB310581-AC80-11D1-8DF3-00C04FB6EF65")
    ISearchViewChangedSink : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnChange( 
            /* [annotation][in] */ 
            _In_  ITEMID *pdwDocID,
            /* [annotation][in] */ 
            _In_  SEARCH_ITEM_CHANGE *pChange,
            /* [annotation][in] */ 
            _In_  BOOL *pfInView) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISearchViewChangedSinkVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISearchViewChangedSink * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISearchViewChangedSink * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISearchViewChangedSink * This);
        
        DECLSPEC_XFGVIRT(ISearchViewChangedSink, OnChange)
        HRESULT ( STDMETHODCALLTYPE *OnChange )( 
            __RPC__in ISearchViewChangedSink * This,
            /* [annotation][in] */ 
            _In_  ITEMID *pdwDocID,
            /* [annotation][in] */ 
            _In_  SEARCH_ITEM_CHANGE *pChange,
            /* [annotation][in] */ 
            _In_  BOOL *pfInView);
        
        END_INTERFACE
    } ISearchViewChangedSinkVtbl;

    interface ISearchViewChangedSink
    {
        CONST_VTBL struct ISearchViewChangedSinkVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISearchViewChangedSink_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISearchViewChangedSink_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISearchViewChangedSink_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISearchViewChangedSink_OnChange(This,pdwDocID,pChange,pfInView)	\
    ( (This)->lpVtbl -> OnChange(This,pdwDocID,pChange,pfInView) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISearchViewChangedSink_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_searchapi_0000_0018 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion
#include <winapifamily.h>
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)


extern RPC_IF_HANDLE __MIDL_itf_searchapi_0000_0018_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_searchapi_0000_0018_v0_0_s_ifspec;

#ifndef __ISearchNotifyInlineSite_INTERFACE_DEFINED__
#define __ISearchNotifyInlineSite_INTERFACE_DEFINED__

/* interface ISearchNotifyInlineSite */
/* [helpstring][unique][uuid][object] */ 

typedef 
enum _SEARCH_INDEXING_PHASE
    {
        SEARCH_INDEXING_PHASE_GATHERER	= 0,
        SEARCH_INDEXING_PHASE_QUERYABLE	= 1,
        SEARCH_INDEXING_PHASE_PERSISTED	= 2
    } 	SEARCH_INDEXING_PHASE;

typedef struct _SEARCH_ITEM_INDEXING_STATUS
    {
    DWORD dwDocID;
    HRESULT hrIndexingStatus;
    } 	SEARCH_ITEM_INDEXING_STATUS;


EXTERN_C const IID IID_ISearchNotifyInlineSite;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B5702E61-E75C-4B64-82A1-6CB4F832FCCF")
    ISearchNotifyInlineSite : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnItemIndexedStatusChange( 
            /* [annotation][in] */ 
            _In_  SEARCH_INDEXING_PHASE sipStatus,
            /* [annotation][in] */ 
            _In_  DWORD dwNumEntries,
            /* [annotation][size_is][in] */ 
            _In_reads_(dwNumEntries)  SEARCH_ITEM_INDEXING_STATUS rgItemStatusEntries[  ]) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnCatalogStatusChange( 
            /* [annotation][in] */ 
            _In_  REFGUID guidCatalogResetSignature,
            /* [annotation][in] */ 
            _In_  REFGUID guidCheckPointSignature,
            /* [annotation][in] */ 
            _In_  DWORD dwLastCheckPointNumber) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISearchNotifyInlineSiteVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISearchNotifyInlineSite * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISearchNotifyInlineSite * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISearchNotifyInlineSite * This);
        
        DECLSPEC_XFGVIRT(ISearchNotifyInlineSite, OnItemIndexedStatusChange)
        HRESULT ( STDMETHODCALLTYPE *OnItemIndexedStatusChange )( 
            __RPC__in ISearchNotifyInlineSite * This,
            /* [annotation][in] */ 
            _In_  SEARCH_INDEXING_PHASE sipStatus,
            /* [annotation][in] */ 
            _In_  DWORD dwNumEntries,
            /* [annotation][size_is][in] */ 
            _In_reads_(dwNumEntries)  SEARCH_ITEM_INDEXING_STATUS rgItemStatusEntries[  ]);
        
        DECLSPEC_XFGVIRT(ISearchNotifyInlineSite, OnCatalogStatusChange)
        HRESULT ( STDMETHODCALLTYPE *OnCatalogStatusChange )( 
            __RPC__in ISearchNotifyInlineSite * This,
            /* [annotation][in] */ 
            _In_  REFGUID guidCatalogResetSignature,
            /* [annotation][in] */ 
            _In_  REFGUID guidCheckPointSignature,
            /* [annotation][in] */ 
            _In_  DWORD dwLastCheckPointNumber);
        
        END_INTERFACE
    } ISearchNotifyInlineSiteVtbl;

    interface ISearchNotifyInlineSite
    {
        CONST_VTBL struct ISearchNotifyInlineSiteVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISearchNotifyInlineSite_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISearchNotifyInlineSite_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISearchNotifyInlineSite_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISearchNotifyInlineSite_OnItemIndexedStatusChange(This,sipStatus,dwNumEntries,rgItemStatusEntries)	\
    ( (This)->lpVtbl -> OnItemIndexedStatusChange(This,sipStatus,dwNumEntries,rgItemStatusEntries) ) 

#define ISearchNotifyInlineSite_OnCatalogStatusChange(This,guidCatalogResetSignature,guidCheckPointSignature,dwLastCheckPointNumber)	\
    ( (This)->lpVtbl -> OnCatalogStatusChange(This,guidCatalogResetSignature,guidCheckPointSignature,dwLastCheckPointNumber) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISearchNotifyInlineSite_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_searchapi_0000_0019 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion
#include <winapifamily.h>
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)

typedef 
enum _CatalogStatus
    {
        CATALOG_STATUS_IDLE	= 0,
        CATALOG_STATUS_PAUSED	= 1,
        CATALOG_STATUS_RECOVERING	= 2,
        CATALOG_STATUS_FULL_CRAWL	= 3,
        CATALOG_STATUS_INCREMENTAL_CRAWL	= 4,
        CATALOG_STATUS_PROCESSING_NOTIFICATIONS	= 5,
        CATALOG_STATUS_SHUTTING_DOWN	= 6
    } 	CatalogStatus;

typedef 
enum _CatalogPausedReason
    {
        CATALOG_PAUSED_REASON_NONE	= 0,
        CATALOG_PAUSED_REASON_HIGH_IO	= 1,
        CATALOG_PAUSED_REASON_HIGH_CPU	= 2,
        CATALOG_PAUSED_REASON_HIGH_NTF_RATE	= 3,
        CATALOG_PAUSED_REASON_LOW_BATTERY	= 4,
        CATALOG_PAUSED_REASON_LOW_MEMORY	= 5,
        CATALOG_PAUSED_REASON_LOW_DISK	= 6,
        CATALOG_PAUSED_REASON_DELAYED_RECOVERY	= 7,
        CATALOG_PAUSED_REASON_USER_ACTIVE	= 8,
        CATALOG_PAUSED_REASON_EXTERNAL	= 9,
        CATALOG_PAUSED_REASON_UPGRADING	= 10
    } 	CatalogPausedReason;



extern RPC_IF_HANDLE __MIDL_itf_searchapi_0000_0019_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_searchapi_0000_0019_v0_0_s_ifspec;

#ifndef __ISearchCatalogManager_INTERFACE_DEFINED__
#define __ISearchCatalogManager_INTERFACE_DEFINED__

/* interface ISearchCatalogManager */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_ISearchCatalogManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("AB310581-AC80-11D1-8DF3-00C04FB6EF50")
    ISearchCatalogManager : public IUnknown
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [annotation][string][retval][out] */ 
            _Out_retval_  LPWSTR *pszName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetParameter( 
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][retval][out] */ 
            _Out_retval_  PROPVARIANT **ppValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetParameter( 
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][in] */ 
            _In_  PROPVARIANT *pValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCatalogStatus( 
            /* [annotation][out] */ 
            _Out_  CatalogStatus *pStatus,
            /* [annotation][out] */ 
            _Out_  CatalogPausedReason *pPausedReason) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reindex( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReindexMatchingURLs( 
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszPattern) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReindexSearchRoot( 
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszRootURL) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_ConnectTimeout( 
            /* [annotation][in] */ 
            _In_  DWORD dwConnectTimeout) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_ConnectTimeout( 
            /* [annotation][retval][out] */ 
            _Out_retval_  DWORD *pdwConnectTimeout) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_DataTimeout( 
            /* [annotation][in] */ 
            _In_  DWORD dwDataTimeout) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_DataTimeout( 
            /* [annotation][retval][out] */ 
            _Out_retval_  DWORD *pdwDataTimeout) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE NumberOfItems( 
            /* [annotation][retval][out] */ 
            _Out_retval_  LONG *plCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE NumberOfItemsToIndex( 
            /* [annotation][out] */ 
            _Out_  LONG *plIncrementalCount,
            /* [annotation][out] */ 
            _Out_  LONG *plNotificationQueue,
            /* [annotation][out] */ 
            _Out_  LONG *plHighPriorityQueue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE URLBeingIndexed( 
            /* [annotation][string][retval][out] */ 
            _Out_retval_  LPWSTR *pszUrl) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetURLIndexingState( 
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszURL,
            /* [annotation][retval][out] */ 
            _Out_retval_  DWORD *pdwState) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPersistentItemsChangedSink( 
            /* [annotation][retval][out] */ 
            _Out_retval_  ISearchPersistentItemsChangedSink **ppISearchPersistentItemsChangedSink) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RegisterViewForNotification( 
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszView,
            /* [annotation][in] */ 
            _In_  ISearchViewChangedSink *pViewChangedSink,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwCookie) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetItemsChangedSink( 
            /* [annotation][in] */ 
            _In_  ISearchNotifyInlineSite *pISearchNotifyInlineSite,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppv,
            /* [annotation][out] */ 
            _Out_  GUID *pGUIDCatalogResetSignature,
            /* [annotation][out] */ 
            _Out_  GUID *pGUIDCheckPointSignature,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwLastCheckPointNumber) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UnregisterViewForNotification( 
            /* [annotation][in] */ 
            _In_  DWORD dwCookie) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetExtensionClusion( 
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszExtension,
            /* [annotation][in] */ 
            _In_  BOOL fExclude) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumerateExcludedExtensions( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IEnumString **ppExtensions) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetQueryHelper( 
            /* [annotation][retval][out] */ 
            _Out_retval_  ISearchQueryHelper **ppSearchQueryHelper) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_DiacriticSensitivity( 
            /* [annotation][in] */ 
            _In_  BOOL fDiacriticSensitive) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_DiacriticSensitivity( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BOOL *pfDiacriticSensitive) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCrawlScopeManager( 
            /* [annotation][retval][out] */ 
            _Out_retval_  ISearchCrawlScopeManager **ppCrawlScopeManager) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISearchCatalogManagerVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISearchCatalogManager * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISearchCatalogManager * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISearchCatalogManager * This);
        
        DECLSPEC_XFGVIRT(ISearchCatalogManager, get_Name)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            __RPC__in ISearchCatalogManager * This,
            /* [annotation][string][retval][out] */ 
            _Out_retval_  LPWSTR *pszName);
        
        DECLSPEC_XFGVIRT(ISearchCatalogManager, GetParameter)
        HRESULT ( STDMETHODCALLTYPE *GetParameter )( 
            __RPC__in ISearchCatalogManager * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][retval][out] */ 
            _Out_retval_  PROPVARIANT **ppValue);
        
        DECLSPEC_XFGVIRT(ISearchCatalogManager, SetParameter)
        HRESULT ( STDMETHODCALLTYPE *SetParameter )( 
            __RPC__in ISearchCatalogManager * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][in] */ 
            _In_  PROPVARIANT *pValue);
        
        DECLSPEC_XFGVIRT(ISearchCatalogManager, GetCatalogStatus)
        HRESULT ( STDMETHODCALLTYPE *GetCatalogStatus )( 
            __RPC__in ISearchCatalogManager * This,
            /* [annotation][out] */ 
            _Out_  CatalogStatus *pStatus,
            /* [annotation][out] */ 
            _Out_  CatalogPausedReason *pPausedReason);
        
        DECLSPEC_XFGVIRT(ISearchCatalogManager, Reset)
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            __RPC__in ISearchCatalogManager * This);
        
        DECLSPEC_XFGVIRT(ISearchCatalogManager, Reindex)
        HRESULT ( STDMETHODCALLTYPE *Reindex )( 
            __RPC__in ISearchCatalogManager * This);
        
        DECLSPEC_XFGVIRT(ISearchCatalogManager, ReindexMatchingURLs)
        HRESULT ( STDMETHODCALLTYPE *ReindexMatchingURLs )( 
            __RPC__in ISearchCatalogManager * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszPattern);
        
        DECLSPEC_XFGVIRT(ISearchCatalogManager, ReindexSearchRoot)
        HRESULT ( STDMETHODCALLTYPE *ReindexSearchRoot )( 
            __RPC__in ISearchCatalogManager * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszRootURL);
        
        DECLSPEC_XFGVIRT(ISearchCatalogManager, put_ConnectTimeout)
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_ConnectTimeout )( 
            __RPC__in ISearchCatalogManager * This,
            /* [annotation][in] */ 
            _In_  DWORD dwConnectTimeout);
        
        DECLSPEC_XFGVIRT(ISearchCatalogManager, get_ConnectTimeout)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_ConnectTimeout )( 
            __RPC__in ISearchCatalogManager * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  DWORD *pdwConnectTimeout);
        
        DECLSPEC_XFGVIRT(ISearchCatalogManager, put_DataTimeout)
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_DataTimeout )( 
            __RPC__in ISearchCatalogManager * This,
            /* [annotation][in] */ 
            _In_  DWORD dwDataTimeout);
        
        DECLSPEC_XFGVIRT(ISearchCatalogManager, get_DataTimeout)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_DataTimeout )( 
            __RPC__in ISearchCatalogManager * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  DWORD *pdwDataTimeout);
        
        DECLSPEC_XFGVIRT(ISearchCatalogManager, NumberOfItems)
        HRESULT ( STDMETHODCALLTYPE *NumberOfItems )( 
            __RPC__in ISearchCatalogManager * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  LONG *plCount);
        
        DECLSPEC_XFGVIRT(ISearchCatalogManager, NumberOfItemsToIndex)
        HRESULT ( STDMETHODCALLTYPE *NumberOfItemsToIndex )( 
            __RPC__in ISearchCatalogManager * This,
            /* [annotation][out] */ 
            _Out_  LONG *plIncrementalCount,
            /* [annotation][out] */ 
            _Out_  LONG *plNotificationQueue,
            /* [annotation][out] */ 
            _Out_  LONG *plHighPriorityQueue);
        
        DECLSPEC_XFGVIRT(ISearchCatalogManager, URLBeingIndexed)
        HRESULT ( STDMETHODCALLTYPE *URLBeingIndexed )( 
            __RPC__in ISearchCatalogManager * This,
            /* [annotation][string][retval][out] */ 
            _Out_retval_  LPWSTR *pszUrl);
        
        DECLSPEC_XFGVIRT(ISearchCatalogManager, GetURLIndexingState)
        HRESULT ( STDMETHODCALLTYPE *GetURLIndexingState )( 
            __RPC__in ISearchCatalogManager * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszURL,
            /* [annotation][retval][out] */ 
            _Out_retval_  DWORD *pdwState);
        
        DECLSPEC_XFGVIRT(ISearchCatalogManager, GetPersistentItemsChangedSink)
        HRESULT ( STDMETHODCALLTYPE *GetPersistentItemsChangedSink )( 
            __RPC__in ISearchCatalogManager * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  ISearchPersistentItemsChangedSink **ppISearchPersistentItemsChangedSink);
        
        DECLSPEC_XFGVIRT(ISearchCatalogManager, RegisterViewForNotification)
        HRESULT ( STDMETHODCALLTYPE *RegisterViewForNotification )( 
            __RPC__in ISearchCatalogManager * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszView,
            /* [annotation][in] */ 
            _In_  ISearchViewChangedSink *pViewChangedSink,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwCookie);
        
        DECLSPEC_XFGVIRT(ISearchCatalogManager, GetItemsChangedSink)
        HRESULT ( STDMETHODCALLTYPE *GetItemsChangedSink )( 
            __RPC__in ISearchCatalogManager * This,
            /* [annotation][in] */ 
            _In_  ISearchNotifyInlineSite *pISearchNotifyInlineSite,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppv,
            /* [annotation][out] */ 
            _Out_  GUID *pGUIDCatalogResetSignature,
            /* [annotation][out] */ 
            _Out_  GUID *pGUIDCheckPointSignature,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwLastCheckPointNumber);
        
        DECLSPEC_XFGVIRT(ISearchCatalogManager, UnregisterViewForNotification)
        HRESULT ( STDMETHODCALLTYPE *UnregisterViewForNotification )( 
            __RPC__in ISearchCatalogManager * This,
            /* [annotation][in] */ 
            _In_  DWORD dwCookie);
        
        DECLSPEC_XFGVIRT(ISearchCatalogManager, SetExtensionClusion)
        HRESULT ( STDMETHODCALLTYPE *SetExtensionClusion )( 
            __RPC__in ISearchCatalogManager * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszExtension,
            /* [annotation][in] */ 
            _In_  BOOL fExclude);
        
        DECLSPEC_XFGVIRT(ISearchCatalogManager, EnumerateExcludedExtensions)
        HRESULT ( STDMETHODCALLTYPE *EnumerateExcludedExtensions )( 
            __RPC__in ISearchCatalogManager * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IEnumString **ppExtensions);
        
        DECLSPEC_XFGVIRT(ISearchCatalogManager, GetQueryHelper)
        HRESULT ( STDMETHODCALLTYPE *GetQueryHelper )( 
            __RPC__in ISearchCatalogManager * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  ISearchQueryHelper **ppSearchQueryHelper);
        
        DECLSPEC_XFGVIRT(ISearchCatalogManager, put_DiacriticSensitivity)
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_DiacriticSensitivity )( 
            __RPC__in ISearchCatalogManager * This,
            /* [annotation][in] */ 
            _In_  BOOL fDiacriticSensitive);
        
        DECLSPEC_XFGVIRT(ISearchCatalogManager, get_DiacriticSensitivity)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_DiacriticSensitivity )( 
            __RPC__in ISearchCatalogManager * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BOOL *pfDiacriticSensitive);
        
        DECLSPEC_XFGVIRT(ISearchCatalogManager, GetCrawlScopeManager)
        HRESULT ( STDMETHODCALLTYPE *GetCrawlScopeManager )( 
            __RPC__in ISearchCatalogManager * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  ISearchCrawlScopeManager **ppCrawlScopeManager);
        
        END_INTERFACE
    } ISearchCatalogManagerVtbl;

    interface ISearchCatalogManager
    {
        CONST_VTBL struct ISearchCatalogManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISearchCatalogManager_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISearchCatalogManager_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISearchCatalogManager_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISearchCatalogManager_get_Name(This,pszName)	\
    ( (This)->lpVtbl -> get_Name(This,pszName) ) 

#define ISearchCatalogManager_GetParameter(This,pszName,ppValue)	\
    ( (This)->lpVtbl -> GetParameter(This,pszName,ppValue) ) 

#define ISearchCatalogManager_SetParameter(This,pszName,pValue)	\
    ( (This)->lpVtbl -> SetParameter(This,pszName,pValue) ) 

#define ISearchCatalogManager_GetCatalogStatus(This,pStatus,pPausedReason)	\
    ( (This)->lpVtbl -> GetCatalogStatus(This,pStatus,pPausedReason) ) 

#define ISearchCatalogManager_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define ISearchCatalogManager_Reindex(This)	\
    ( (This)->lpVtbl -> Reindex(This) ) 

#define ISearchCatalogManager_ReindexMatchingURLs(This,pszPattern)	\
    ( (This)->lpVtbl -> ReindexMatchingURLs(This,pszPattern) ) 

#define ISearchCatalogManager_ReindexSearchRoot(This,pszRootURL)	\
    ( (This)->lpVtbl -> ReindexSearchRoot(This,pszRootURL) ) 

#define ISearchCatalogManager_put_ConnectTimeout(This,dwConnectTimeout)	\
    ( (This)->lpVtbl -> put_ConnectTimeout(This,dwConnectTimeout) ) 

#define ISearchCatalogManager_get_ConnectTimeout(This,pdwConnectTimeout)	\
    ( (This)->lpVtbl -> get_ConnectTimeout(This,pdwConnectTimeout) ) 

#define ISearchCatalogManager_put_DataTimeout(This,dwDataTimeout)	\
    ( (This)->lpVtbl -> put_DataTimeout(This,dwDataTimeout) ) 

#define ISearchCatalogManager_get_DataTimeout(This,pdwDataTimeout)	\
    ( (This)->lpVtbl -> get_DataTimeout(This,pdwDataTimeout) ) 

#define ISearchCatalogManager_NumberOfItems(This,plCount)	\
    ( (This)->lpVtbl -> NumberOfItems(This,plCount) ) 

#define ISearchCatalogManager_NumberOfItemsToIndex(This,plIncrementalCount,plNotificationQueue,plHighPriorityQueue)	\
    ( (This)->lpVtbl -> NumberOfItemsToIndex(This,plIncrementalCount,plNotificationQueue,plHighPriorityQueue) ) 

#define ISearchCatalogManager_URLBeingIndexed(This,pszUrl)	\
    ( (This)->lpVtbl -> URLBeingIndexed(This,pszUrl) ) 

#define ISearchCatalogManager_GetURLIndexingState(This,pszURL,pdwState)	\
    ( (This)->lpVtbl -> GetURLIndexingState(This,pszURL,pdwState) ) 

#define ISearchCatalogManager_GetPersistentItemsChangedSink(This,ppISearchPersistentItemsChangedSink)	\
    ( (This)->lpVtbl -> GetPersistentItemsChangedSink(This,ppISearchPersistentItemsChangedSink) ) 

#define ISearchCatalogManager_RegisterViewForNotification(This,pszView,pViewChangedSink,pdwCookie)	\
    ( (This)->lpVtbl -> RegisterViewForNotification(This,pszView,pViewChangedSink,pdwCookie) ) 

#define ISearchCatalogManager_GetItemsChangedSink(This,pISearchNotifyInlineSite,riid,ppv,pGUIDCatalogResetSignature,pGUIDCheckPointSignature,pdwLastCheckPointNumber)	\
    ( (This)->lpVtbl -> GetItemsChangedSink(This,pISearchNotifyInlineSite,riid,ppv,pGUIDCatalogResetSignature,pGUIDCheckPointSignature,pdwLastCheckPointNumber) ) 

#define ISearchCatalogManager_UnregisterViewForNotification(This,dwCookie)	\
    ( (This)->lpVtbl -> UnregisterViewForNotification(This,dwCookie) ) 

#define ISearchCatalogManager_SetExtensionClusion(This,pszExtension,fExclude)	\
    ( (This)->lpVtbl -> SetExtensionClusion(This,pszExtension,fExclude) ) 

#define ISearchCatalogManager_EnumerateExcludedExtensions(This,ppExtensions)	\
    ( (This)->lpVtbl -> EnumerateExcludedExtensions(This,ppExtensions) ) 

#define ISearchCatalogManager_GetQueryHelper(This,ppSearchQueryHelper)	\
    ( (This)->lpVtbl -> GetQueryHelper(This,ppSearchQueryHelper) ) 

#define ISearchCatalogManager_put_DiacriticSensitivity(This,fDiacriticSensitive)	\
    ( (This)->lpVtbl -> put_DiacriticSensitivity(This,fDiacriticSensitive) ) 

#define ISearchCatalogManager_get_DiacriticSensitivity(This,pfDiacriticSensitive)	\
    ( (This)->lpVtbl -> get_DiacriticSensitivity(This,pfDiacriticSensitive) ) 

#define ISearchCatalogManager_GetCrawlScopeManager(This,ppCrawlScopeManager)	\
    ( (This)->lpVtbl -> GetCrawlScopeManager(This,ppCrawlScopeManager) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISearchCatalogManager_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_searchapi_0000_0020 */
/* [local] */ 

/* [v1_enum] */ 
enum tagPRIORITIZE_FLAGS
    {
        PRIORITIZE_FLAG_RETRYFAILEDITEMS	= 0x1,
        PRIORITIZE_FLAG_IGNOREFAILURECOUNT	= 0x2
    } ;
typedef int PRIORITIZE_FLAGS;



extern RPC_IF_HANDLE __MIDL_itf_searchapi_0000_0020_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_searchapi_0000_0020_v0_0_s_ifspec;

#ifndef __ISearchCatalogManager2_INTERFACE_DEFINED__
#define __ISearchCatalogManager2_INTERFACE_DEFINED__

/* interface ISearchCatalogManager2 */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_ISearchCatalogManager2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7AC3286D-4D1D-4817-84FC-C1C85E3AF0D9")
    ISearchCatalogManager2 : public ISearchCatalogManager
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE PrioritizeMatchingURLs( 
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszPattern,
            /* [annotation][in] */ 
            _In_  PRIORITIZE_FLAGS dwPrioritizeFlags) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISearchCatalogManager2Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISearchCatalogManager2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISearchCatalogManager2 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISearchCatalogManager2 * This);
        
        DECLSPEC_XFGVIRT(ISearchCatalogManager, get_Name)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            __RPC__in ISearchCatalogManager2 * This,
            /* [annotation][string][retval][out] */ 
            _Out_retval_  LPWSTR *pszName);
        
        DECLSPEC_XFGVIRT(ISearchCatalogManager, GetParameter)
        HRESULT ( STDMETHODCALLTYPE *GetParameter )( 
            __RPC__in ISearchCatalogManager2 * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][retval][out] */ 
            _Out_retval_  PROPVARIANT **ppValue);
        
        DECLSPEC_XFGVIRT(ISearchCatalogManager, SetParameter)
        HRESULT ( STDMETHODCALLTYPE *SetParameter )( 
            __RPC__in ISearchCatalogManager2 * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][in] */ 
            _In_  PROPVARIANT *pValue);
        
        DECLSPEC_XFGVIRT(ISearchCatalogManager, GetCatalogStatus)
        HRESULT ( STDMETHODCALLTYPE *GetCatalogStatus )( 
            __RPC__in ISearchCatalogManager2 * This,
            /* [annotation][out] */ 
            _Out_  CatalogStatus *pStatus,
            /* [annotation][out] */ 
            _Out_  CatalogPausedReason *pPausedReason);
        
        DECLSPEC_XFGVIRT(ISearchCatalogManager, Reset)
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            __RPC__in ISearchCatalogManager2 * This);
        
        DECLSPEC_XFGVIRT(ISearchCatalogManager, Reindex)
        HRESULT ( STDMETHODCALLTYPE *Reindex )( 
            __RPC__in ISearchCatalogManager2 * This);
        
        DECLSPEC_XFGVIRT(ISearchCatalogManager, ReindexMatchingURLs)
        HRESULT ( STDMETHODCALLTYPE *ReindexMatchingURLs )( 
            __RPC__in ISearchCatalogManager2 * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszPattern);
        
        DECLSPEC_XFGVIRT(ISearchCatalogManager, ReindexSearchRoot)
        HRESULT ( STDMETHODCALLTYPE *ReindexSearchRoot )( 
            __RPC__in ISearchCatalogManager2 * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszRootURL);
        
        DECLSPEC_XFGVIRT(ISearchCatalogManager, put_ConnectTimeout)
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_ConnectTimeout )( 
            __RPC__in ISearchCatalogManager2 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwConnectTimeout);
        
        DECLSPEC_XFGVIRT(ISearchCatalogManager, get_ConnectTimeout)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_ConnectTimeout )( 
            __RPC__in ISearchCatalogManager2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  DWORD *pdwConnectTimeout);
        
        DECLSPEC_XFGVIRT(ISearchCatalogManager, put_DataTimeout)
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_DataTimeout )( 
            __RPC__in ISearchCatalogManager2 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwDataTimeout);
        
        DECLSPEC_XFGVIRT(ISearchCatalogManager, get_DataTimeout)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_DataTimeout )( 
            __RPC__in ISearchCatalogManager2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  DWORD *pdwDataTimeout);
        
        DECLSPEC_XFGVIRT(ISearchCatalogManager, NumberOfItems)
        HRESULT ( STDMETHODCALLTYPE *NumberOfItems )( 
            __RPC__in ISearchCatalogManager2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  LONG *plCount);
        
        DECLSPEC_XFGVIRT(ISearchCatalogManager, NumberOfItemsToIndex)
        HRESULT ( STDMETHODCALLTYPE *NumberOfItemsToIndex )( 
            __RPC__in ISearchCatalogManager2 * This,
            /* [annotation][out] */ 
            _Out_  LONG *plIncrementalCount,
            /* [annotation][out] */ 
            _Out_  LONG *plNotificationQueue,
            /* [annotation][out] */ 
            _Out_  LONG *plHighPriorityQueue);
        
        DECLSPEC_XFGVIRT(ISearchCatalogManager, URLBeingIndexed)
        HRESULT ( STDMETHODCALLTYPE *URLBeingIndexed )( 
            __RPC__in ISearchCatalogManager2 * This,
            /* [annotation][string][retval][out] */ 
            _Out_retval_  LPWSTR *pszUrl);
        
        DECLSPEC_XFGVIRT(ISearchCatalogManager, GetURLIndexingState)
        HRESULT ( STDMETHODCALLTYPE *GetURLIndexingState )( 
            __RPC__in ISearchCatalogManager2 * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszURL,
            /* [annotation][retval][out] */ 
            _Out_retval_  DWORD *pdwState);
        
        DECLSPEC_XFGVIRT(ISearchCatalogManager, GetPersistentItemsChangedSink)
        HRESULT ( STDMETHODCALLTYPE *GetPersistentItemsChangedSink )( 
            __RPC__in ISearchCatalogManager2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  ISearchPersistentItemsChangedSink **ppISearchPersistentItemsChangedSink);
        
        DECLSPEC_XFGVIRT(ISearchCatalogManager, RegisterViewForNotification)
        HRESULT ( STDMETHODCALLTYPE *RegisterViewForNotification )( 
            __RPC__in ISearchCatalogManager2 * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszView,
            /* [annotation][in] */ 
            _In_  ISearchViewChangedSink *pViewChangedSink,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwCookie);
        
        DECLSPEC_XFGVIRT(ISearchCatalogManager, GetItemsChangedSink)
        HRESULT ( STDMETHODCALLTYPE *GetItemsChangedSink )( 
            __RPC__in ISearchCatalogManager2 * This,
            /* [annotation][in] */ 
            _In_  ISearchNotifyInlineSite *pISearchNotifyInlineSite,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppv,
            /* [annotation][out] */ 
            _Out_  GUID *pGUIDCatalogResetSignature,
            /* [annotation][out] */ 
            _Out_  GUID *pGUIDCheckPointSignature,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwLastCheckPointNumber);
        
        DECLSPEC_XFGVIRT(ISearchCatalogManager, UnregisterViewForNotification)
        HRESULT ( STDMETHODCALLTYPE *UnregisterViewForNotification )( 
            __RPC__in ISearchCatalogManager2 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwCookie);
        
        DECLSPEC_XFGVIRT(ISearchCatalogManager, SetExtensionClusion)
        HRESULT ( STDMETHODCALLTYPE *SetExtensionClusion )( 
            __RPC__in ISearchCatalogManager2 * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszExtension,
            /* [annotation][in] */ 
            _In_  BOOL fExclude);
        
        DECLSPEC_XFGVIRT(ISearchCatalogManager, EnumerateExcludedExtensions)
        HRESULT ( STDMETHODCALLTYPE *EnumerateExcludedExtensions )( 
            __RPC__in ISearchCatalogManager2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IEnumString **ppExtensions);
        
        DECLSPEC_XFGVIRT(ISearchCatalogManager, GetQueryHelper)
        HRESULT ( STDMETHODCALLTYPE *GetQueryHelper )( 
            __RPC__in ISearchCatalogManager2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  ISearchQueryHelper **ppSearchQueryHelper);
        
        DECLSPEC_XFGVIRT(ISearchCatalogManager, put_DiacriticSensitivity)
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_DiacriticSensitivity )( 
            __RPC__in ISearchCatalogManager2 * This,
            /* [annotation][in] */ 
            _In_  BOOL fDiacriticSensitive);
        
        DECLSPEC_XFGVIRT(ISearchCatalogManager, get_DiacriticSensitivity)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_DiacriticSensitivity )( 
            __RPC__in ISearchCatalogManager2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BOOL *pfDiacriticSensitive);
        
        DECLSPEC_XFGVIRT(ISearchCatalogManager, GetCrawlScopeManager)
        HRESULT ( STDMETHODCALLTYPE *GetCrawlScopeManager )( 
            __RPC__in ISearchCatalogManager2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  ISearchCrawlScopeManager **ppCrawlScopeManager);
        
        DECLSPEC_XFGVIRT(ISearchCatalogManager2, PrioritizeMatchingURLs)
        HRESULT ( STDMETHODCALLTYPE *PrioritizeMatchingURLs )( 
            __RPC__in ISearchCatalogManager2 * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszPattern,
            /* [annotation][in] */ 
            _In_  PRIORITIZE_FLAGS dwPrioritizeFlags);
        
        END_INTERFACE
    } ISearchCatalogManager2Vtbl;

    interface ISearchCatalogManager2
    {
        CONST_VTBL struct ISearchCatalogManager2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISearchCatalogManager2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISearchCatalogManager2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISearchCatalogManager2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISearchCatalogManager2_get_Name(This,pszName)	\
    ( (This)->lpVtbl -> get_Name(This,pszName) ) 

#define ISearchCatalogManager2_GetParameter(This,pszName,ppValue)	\
    ( (This)->lpVtbl -> GetParameter(This,pszName,ppValue) ) 

#define ISearchCatalogManager2_SetParameter(This,pszName,pValue)	\
    ( (This)->lpVtbl -> SetParameter(This,pszName,pValue) ) 

#define ISearchCatalogManager2_GetCatalogStatus(This,pStatus,pPausedReason)	\
    ( (This)->lpVtbl -> GetCatalogStatus(This,pStatus,pPausedReason) ) 

#define ISearchCatalogManager2_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define ISearchCatalogManager2_Reindex(This)	\
    ( (This)->lpVtbl -> Reindex(This) ) 

#define ISearchCatalogManager2_ReindexMatchingURLs(This,pszPattern)	\
    ( (This)->lpVtbl -> ReindexMatchingURLs(This,pszPattern) ) 

#define ISearchCatalogManager2_ReindexSearchRoot(This,pszRootURL)	\
    ( (This)->lpVtbl -> ReindexSearchRoot(This,pszRootURL) ) 

#define ISearchCatalogManager2_put_ConnectTimeout(This,dwConnectTimeout)	\
    ( (This)->lpVtbl -> put_ConnectTimeout(This,dwConnectTimeout) ) 

#define ISearchCatalogManager2_get_ConnectTimeout(This,pdwConnectTimeout)	\
    ( (This)->lpVtbl -> get_ConnectTimeout(This,pdwConnectTimeout) ) 

#define ISearchCatalogManager2_put_DataTimeout(This,dwDataTimeout)	\
    ( (This)->lpVtbl -> put_DataTimeout(This,dwDataTimeout) ) 

#define ISearchCatalogManager2_get_DataTimeout(This,pdwDataTimeout)	\
    ( (This)->lpVtbl -> get_DataTimeout(This,pdwDataTimeout) ) 

#define ISearchCatalogManager2_NumberOfItems(This,plCount)	\
    ( (This)->lpVtbl -> NumberOfItems(This,plCount) ) 

#define ISearchCatalogManager2_NumberOfItemsToIndex(This,plIncrementalCount,plNotificationQueue,plHighPriorityQueue)	\
    ( (This)->lpVtbl -> NumberOfItemsToIndex(This,plIncrementalCount,plNotificationQueue,plHighPriorityQueue) ) 

#define ISearchCatalogManager2_URLBeingIndexed(This,pszUrl)	\
    ( (This)->lpVtbl -> URLBeingIndexed(This,pszUrl) ) 

#define ISearchCatalogManager2_GetURLIndexingState(This,pszURL,pdwState)	\
    ( (This)->lpVtbl -> GetURLIndexingState(This,pszURL,pdwState) ) 

#define ISearchCatalogManager2_GetPersistentItemsChangedSink(This,ppISearchPersistentItemsChangedSink)	\
    ( (This)->lpVtbl -> GetPersistentItemsChangedSink(This,ppISearchPersistentItemsChangedSink) ) 

#define ISearchCatalogManager2_RegisterViewForNotification(This,pszView,pViewChangedSink,pdwCookie)	\
    ( (This)->lpVtbl -> RegisterViewForNotification(This,pszView,pViewChangedSink,pdwCookie) ) 

#define ISearchCatalogManager2_GetItemsChangedSink(This,pISearchNotifyInlineSite,riid,ppv,pGUIDCatalogResetSignature,pGUIDCheckPointSignature,pdwLastCheckPointNumber)	\
    ( (This)->lpVtbl -> GetItemsChangedSink(This,pISearchNotifyInlineSite,riid,ppv,pGUIDCatalogResetSignature,pGUIDCheckPointSignature,pdwLastCheckPointNumber) ) 

#define ISearchCatalogManager2_UnregisterViewForNotification(This,dwCookie)	\
    ( (This)->lpVtbl -> UnregisterViewForNotification(This,dwCookie) ) 

#define ISearchCatalogManager2_SetExtensionClusion(This,pszExtension,fExclude)	\
    ( (This)->lpVtbl -> SetExtensionClusion(This,pszExtension,fExclude) ) 

#define ISearchCatalogManager2_EnumerateExcludedExtensions(This,ppExtensions)	\
    ( (This)->lpVtbl -> EnumerateExcludedExtensions(This,ppExtensions) ) 

#define ISearchCatalogManager2_GetQueryHelper(This,ppSearchQueryHelper)	\
    ( (This)->lpVtbl -> GetQueryHelper(This,ppSearchQueryHelper) ) 

#define ISearchCatalogManager2_put_DiacriticSensitivity(This,fDiacriticSensitive)	\
    ( (This)->lpVtbl -> put_DiacriticSensitivity(This,fDiacriticSensitive) ) 

#define ISearchCatalogManager2_get_DiacriticSensitivity(This,pfDiacriticSensitive)	\
    ( (This)->lpVtbl -> get_DiacriticSensitivity(This,pfDiacriticSensitive) ) 

#define ISearchCatalogManager2_GetCrawlScopeManager(This,ppCrawlScopeManager)	\
    ( (This)->lpVtbl -> GetCrawlScopeManager(This,ppCrawlScopeManager) ) 


#define ISearchCatalogManager2_PrioritizeMatchingURLs(This,pszPattern,dwPrioritizeFlags)	\
    ( (This)->lpVtbl -> PrioritizeMatchingURLs(This,pszPattern,dwPrioritizeFlags) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISearchCatalogManager2_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_searchapi_0000_0021 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion
#include <winapifamily.h>
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)


extern RPC_IF_HANDLE __MIDL_itf_searchapi_0000_0021_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_searchapi_0000_0021_v0_0_s_ifspec;

#ifndef __ISearchQueryHelper_INTERFACE_DEFINED__
#define __ISearchQueryHelper_INTERFACE_DEFINED__

/* interface ISearchQueryHelper */
/* [unique][uuid][object] */ 

typedef 
enum _SEARCH_TERM_EXPANSION
    {
        SEARCH_TERM_NO_EXPANSION	= 0,
        SEARCH_TERM_PREFIX_ALL	= ( SEARCH_TERM_NO_EXPANSION + 1 ) ,
        SEARCH_TERM_STEM_ALL	= ( SEARCH_TERM_PREFIX_ALL + 1 ) 
    } 	SEARCH_TERM_EXPANSION;

typedef 
enum _SEARCH_QUERY_SYNTAX
    {
        SEARCH_NO_QUERY_SYNTAX	= 0,
        SEARCH_ADVANCED_QUERY_SYNTAX	= ( SEARCH_NO_QUERY_SYNTAX + 1 ) ,
        SEARCH_NATURAL_QUERY_SYNTAX	= ( SEARCH_ADVANCED_QUERY_SYNTAX + 1 ) 
    } 	SEARCH_QUERY_SYNTAX;

typedef struct _SEARCH_COLUMN_PROPERTIES
    {
    PROPVARIANT Value;
    LCID lcid;
    } 	SEARCH_COLUMN_PROPERTIES;


EXTERN_C const IID IID_ISearchQueryHelper;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("AB310581-AC80-11D1-8DF3-00C04FB6EF63")
    ISearchQueryHelper : public IUnknown
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_ConnectionString( 
            /* [annotation][string][retval][out] */ 
            _Out_retval_  LPWSTR *pszConnectionString) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_QueryContentLocale( 
            /* [annotation][in] */ 
            _In_  LCID lcid) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_QueryContentLocale( 
            /* [annotation][retval][out] */ 
            _Out_retval_  LCID *plcid) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_QueryKeywordLocale( 
            /* [annotation][in] */ 
            _In_  LCID lcid) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_QueryKeywordLocale( 
            /* [annotation][retval][out] */ 
            _Out_retval_  LCID *plcid) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_QueryTermExpansion( 
            /* [annotation][in] */ 
            _In_  SEARCH_TERM_EXPANSION expandTerms) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_QueryTermExpansion( 
            /* [annotation][retval][out] */ 
            _Out_retval_  SEARCH_TERM_EXPANSION *pExpandTerms) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_QuerySyntax( 
            /* [annotation][in] */ 
            _In_  SEARCH_QUERY_SYNTAX querySyntax) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_QuerySyntax( 
            /* [annotation][retval][out] */ 
            _Out_retval_  SEARCH_QUERY_SYNTAX *pQuerySyntax) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_QueryContentProperties( 
            /* [annotation][unique][string][in] */ 
            _In_  LPCWSTR pszContentProperties) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_QueryContentProperties( 
            /* [annotation][retval][string][out] */ 
            _Out_retval_  LPWSTR *ppszContentProperties) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_QuerySelectColumns( 
            /* [annotation][unique][string][in] */ 
            _In_  LPCWSTR pszSelectColumns) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_QuerySelectColumns( 
            /* [annotation][retval][string][out] */ 
            _Out_retval_  LPWSTR *ppszSelectColumns) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_QueryWhereRestrictions( 
            /* [annotation][unique][string][in] */ 
            _In_  LPCWSTR pszRestrictions) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_QueryWhereRestrictions( 
            /* [annotation][retval][string][out] */ 
            _Out_retval_  LPWSTR *ppszRestrictions) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_QuerySorting( 
            /* [annotation][unique][string][in] */ 
            _In_  LPCWSTR pszSorting) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_QuerySorting( 
            /* [annotation][retval][string][out] */ 
            _Out_retval_  LPWSTR *ppszSorting) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GenerateSQLFromUserQuery( 
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszQuery,
            /* [annotation][string][retval][out] */ 
            _Out_retval_  LPWSTR *ppszSQL) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE WriteProperties( 
            /* [annotation][in] */ 
            _In_  ITEMID itemID,
            /* [annotation][in] */ 
            _In_  DWORD dwNumberOfColumns,
            /* [annotation][size_is][in] */ 
            _In_reads_(dwNumberOfColumns)  PROPERTYKEY *pColumns,
            /* [annotation][size_is][in] */ 
            _In_reads_(dwNumberOfColumns)  SEARCH_COLUMN_PROPERTIES *pValues,
            /* [annotation][unique][in] */ 
            _In_  FILETIME *pftGatherModifiedTime) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_QueryMaxResults( 
            /* [annotation][in] */ 
            _In_  LONG cMaxResults) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_QueryMaxResults( 
            /* [annotation][retval][out] */ 
            _Out_retval_  LONG *pcMaxResults) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISearchQueryHelperVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISearchQueryHelper * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISearchQueryHelper * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISearchQueryHelper * This);
        
        DECLSPEC_XFGVIRT(ISearchQueryHelper, get_ConnectionString)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_ConnectionString )( 
            __RPC__in ISearchQueryHelper * This,
            /* [annotation][string][retval][out] */ 
            _Out_retval_  LPWSTR *pszConnectionString);
        
        DECLSPEC_XFGVIRT(ISearchQueryHelper, put_QueryContentLocale)
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_QueryContentLocale )( 
            __RPC__in ISearchQueryHelper * This,
            /* [annotation][in] */ 
            _In_  LCID lcid);
        
        DECLSPEC_XFGVIRT(ISearchQueryHelper, get_QueryContentLocale)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_QueryContentLocale )( 
            __RPC__in ISearchQueryHelper * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  LCID *plcid);
        
        DECLSPEC_XFGVIRT(ISearchQueryHelper, put_QueryKeywordLocale)
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_QueryKeywordLocale )( 
            __RPC__in ISearchQueryHelper * This,
            /* [annotation][in] */ 
            _In_  LCID lcid);
        
        DECLSPEC_XFGVIRT(ISearchQueryHelper, get_QueryKeywordLocale)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_QueryKeywordLocale )( 
            __RPC__in ISearchQueryHelper * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  LCID *plcid);
        
        DECLSPEC_XFGVIRT(ISearchQueryHelper, put_QueryTermExpansion)
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_QueryTermExpansion )( 
            __RPC__in ISearchQueryHelper * This,
            /* [annotation][in] */ 
            _In_  SEARCH_TERM_EXPANSION expandTerms);
        
        DECLSPEC_XFGVIRT(ISearchQueryHelper, get_QueryTermExpansion)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_QueryTermExpansion )( 
            __RPC__in ISearchQueryHelper * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  SEARCH_TERM_EXPANSION *pExpandTerms);
        
        DECLSPEC_XFGVIRT(ISearchQueryHelper, put_QuerySyntax)
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_QuerySyntax )( 
            __RPC__in ISearchQueryHelper * This,
            /* [annotation][in] */ 
            _In_  SEARCH_QUERY_SYNTAX querySyntax);
        
        DECLSPEC_XFGVIRT(ISearchQueryHelper, get_QuerySyntax)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_QuerySyntax )( 
            __RPC__in ISearchQueryHelper * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  SEARCH_QUERY_SYNTAX *pQuerySyntax);
        
        DECLSPEC_XFGVIRT(ISearchQueryHelper, put_QueryContentProperties)
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_QueryContentProperties )( 
            __RPC__in ISearchQueryHelper * This,
            /* [annotation][unique][string][in] */ 
            _In_  LPCWSTR pszContentProperties);
        
        DECLSPEC_XFGVIRT(ISearchQueryHelper, get_QueryContentProperties)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_QueryContentProperties )( 
            __RPC__in ISearchQueryHelper * This,
            /* [annotation][retval][string][out] */ 
            _Out_retval_  LPWSTR *ppszContentProperties);
        
        DECLSPEC_XFGVIRT(ISearchQueryHelper, put_QuerySelectColumns)
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_QuerySelectColumns )( 
            __RPC__in ISearchQueryHelper * This,
            /* [annotation][unique][string][in] */ 
            _In_  LPCWSTR pszSelectColumns);
        
        DECLSPEC_XFGVIRT(ISearchQueryHelper, get_QuerySelectColumns)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_QuerySelectColumns )( 
            __RPC__in ISearchQueryHelper * This,
            /* [annotation][retval][string][out] */ 
            _Out_retval_  LPWSTR *ppszSelectColumns);
        
        DECLSPEC_XFGVIRT(ISearchQueryHelper, put_QueryWhereRestrictions)
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_QueryWhereRestrictions )( 
            __RPC__in ISearchQueryHelper * This,
            /* [annotation][unique][string][in] */ 
            _In_  LPCWSTR pszRestrictions);
        
        DECLSPEC_XFGVIRT(ISearchQueryHelper, get_QueryWhereRestrictions)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_QueryWhereRestrictions )( 
            __RPC__in ISearchQueryHelper * This,
            /* [annotation][retval][string][out] */ 
            _Out_retval_  LPWSTR *ppszRestrictions);
        
        DECLSPEC_XFGVIRT(ISearchQueryHelper, put_QuerySorting)
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_QuerySorting )( 
            __RPC__in ISearchQueryHelper * This,
            /* [annotation][unique][string][in] */ 
            _In_  LPCWSTR pszSorting);
        
        DECLSPEC_XFGVIRT(ISearchQueryHelper, get_QuerySorting)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_QuerySorting )( 
            __RPC__in ISearchQueryHelper * This,
            /* [annotation][retval][string][out] */ 
            _Out_retval_  LPWSTR *ppszSorting);
        
        DECLSPEC_XFGVIRT(ISearchQueryHelper, GenerateSQLFromUserQuery)
        HRESULT ( STDMETHODCALLTYPE *GenerateSQLFromUserQuery )( 
            __RPC__in ISearchQueryHelper * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszQuery,
            /* [annotation][string][retval][out] */ 
            _Out_retval_  LPWSTR *ppszSQL);
        
        DECLSPEC_XFGVIRT(ISearchQueryHelper, WriteProperties)
        HRESULT ( STDMETHODCALLTYPE *WriteProperties )( 
            __RPC__in ISearchQueryHelper * This,
            /* [annotation][in] */ 
            _In_  ITEMID itemID,
            /* [annotation][in] */ 
            _In_  DWORD dwNumberOfColumns,
            /* [annotation][size_is][in] */ 
            _In_reads_(dwNumberOfColumns)  PROPERTYKEY *pColumns,
            /* [annotation][size_is][in] */ 
            _In_reads_(dwNumberOfColumns)  SEARCH_COLUMN_PROPERTIES *pValues,
            /* [annotation][unique][in] */ 
            _In_  FILETIME *pftGatherModifiedTime);
        
        DECLSPEC_XFGVIRT(ISearchQueryHelper, put_QueryMaxResults)
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_QueryMaxResults )( 
            __RPC__in ISearchQueryHelper * This,
            /* [annotation][in] */ 
            _In_  LONG cMaxResults);
        
        DECLSPEC_XFGVIRT(ISearchQueryHelper, get_QueryMaxResults)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_QueryMaxResults )( 
            __RPC__in ISearchQueryHelper * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  LONG *pcMaxResults);
        
        END_INTERFACE
    } ISearchQueryHelperVtbl;

    interface ISearchQueryHelper
    {
        CONST_VTBL struct ISearchQueryHelperVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISearchQueryHelper_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISearchQueryHelper_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISearchQueryHelper_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISearchQueryHelper_get_ConnectionString(This,pszConnectionString)	\
    ( (This)->lpVtbl -> get_ConnectionString(This,pszConnectionString) ) 

#define ISearchQueryHelper_put_QueryContentLocale(This,lcid)	\
    ( (This)->lpVtbl -> put_QueryContentLocale(This,lcid) ) 

#define ISearchQueryHelper_get_QueryContentLocale(This,plcid)	\
    ( (This)->lpVtbl -> get_QueryContentLocale(This,plcid) ) 

#define ISearchQueryHelper_put_QueryKeywordLocale(This,lcid)	\
    ( (This)->lpVtbl -> put_QueryKeywordLocale(This,lcid) ) 

#define ISearchQueryHelper_get_QueryKeywordLocale(This,plcid)	\
    ( (This)->lpVtbl -> get_QueryKeywordLocale(This,plcid) ) 

#define ISearchQueryHelper_put_QueryTermExpansion(This,expandTerms)	\
    ( (This)->lpVtbl -> put_QueryTermExpansion(This,expandTerms) ) 

#define ISearchQueryHelper_get_QueryTermExpansion(This,pExpandTerms)	\
    ( (This)->lpVtbl -> get_QueryTermExpansion(This,pExpandTerms) ) 

#define ISearchQueryHelper_put_QuerySyntax(This,querySyntax)	\
    ( (This)->lpVtbl -> put_QuerySyntax(This,querySyntax) ) 

#define ISearchQueryHelper_get_QuerySyntax(This,pQuerySyntax)	\
    ( (This)->lpVtbl -> get_QuerySyntax(This,pQuerySyntax) ) 

#define ISearchQueryHelper_put_QueryContentProperties(This,pszContentProperties)	\
    ( (This)->lpVtbl -> put_QueryContentProperties(This,pszContentProperties) ) 

#define ISearchQueryHelper_get_QueryContentProperties(This,ppszContentProperties)	\
    ( (This)->lpVtbl -> get_QueryContentProperties(This,ppszContentProperties) ) 

#define ISearchQueryHelper_put_QuerySelectColumns(This,pszSelectColumns)	\
    ( (This)->lpVtbl -> put_QuerySelectColumns(This,pszSelectColumns) ) 

#define ISearchQueryHelper_get_QuerySelectColumns(This,ppszSelectColumns)	\
    ( (This)->lpVtbl -> get_QuerySelectColumns(This,ppszSelectColumns) ) 

#define ISearchQueryHelper_put_QueryWhereRestrictions(This,pszRestrictions)	\
    ( (This)->lpVtbl -> put_QueryWhereRestrictions(This,pszRestrictions) ) 

#define ISearchQueryHelper_get_QueryWhereRestrictions(This,ppszRestrictions)	\
    ( (This)->lpVtbl -> get_QueryWhereRestrictions(This,ppszRestrictions) ) 

#define ISearchQueryHelper_put_QuerySorting(This,pszSorting)	\
    ( (This)->lpVtbl -> put_QuerySorting(This,pszSorting) ) 

#define ISearchQueryHelper_get_QuerySorting(This,ppszSorting)	\
    ( (This)->lpVtbl -> get_QuerySorting(This,ppszSorting) ) 

#define ISearchQueryHelper_GenerateSQLFromUserQuery(This,pszQuery,ppszSQL)	\
    ( (This)->lpVtbl -> GenerateSQLFromUserQuery(This,pszQuery,ppszSQL) ) 

#define ISearchQueryHelper_WriteProperties(This,itemID,dwNumberOfColumns,pColumns,pValues,pftGatherModifiedTime)	\
    ( (This)->lpVtbl -> WriteProperties(This,itemID,dwNumberOfColumns,pColumns,pValues,pftGatherModifiedTime) ) 

#define ISearchQueryHelper_put_QueryMaxResults(This,cMaxResults)	\
    ( (This)->lpVtbl -> put_QueryMaxResults(This,cMaxResults) ) 

#define ISearchQueryHelper_get_QueryMaxResults(This,pcMaxResults)	\
    ( (This)->lpVtbl -> get_QueryMaxResults(This,pcMaxResults) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISearchQueryHelper_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_searchapi_0000_0022 */
/* [local] */ 

typedef /* [public][public][public][v1_enum] */ 
enum __MIDL___MIDL_itf_searchapi_0000_0022_0001
    {
        PRIORITY_LEVEL_FOREGROUND	= 0,
        PRIORITY_LEVEL_HIGH	= 1,
        PRIORITY_LEVEL_LOW	= 2,
        PRIORITY_LEVEL_DEFAULT	= 3
    } 	PRIORITY_LEVEL;



extern RPC_IF_HANDLE __MIDL_itf_searchapi_0000_0022_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_searchapi_0000_0022_v0_0_s_ifspec;

#ifndef __IRowsetPrioritization_INTERFACE_DEFINED__
#define __IRowsetPrioritization_INTERFACE_DEFINED__

/* interface IRowsetPrioritization */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IRowsetPrioritization;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("42811652-079D-481B-87A2-09A69ECC5F44")
    IRowsetPrioritization : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetScopePriority( 
            /* [annotation][in] */ 
            _In_  PRIORITY_LEVEL priority,
            /* [annotation][in] */ 
            _In_  DWORD scopeStatisticsEventFrequency) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetScopePriority( 
            /* [annotation][out] */ 
            _Out_  PRIORITY_LEVEL *priority,
            /* [annotation][out] */ 
            _Out_  DWORD *scopeStatisticsEventFrequency) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetScopeStatistics( 
            /* [annotation][out] */ 
            _Out_  DWORD *indexedDocumentCount,
            /* [annotation][out] */ 
            _Out_  DWORD *oustandingAddCount,
            /* [annotation][out] */ 
            _Out_  DWORD *oustandingModifyCount) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRowsetPrioritizationVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IRowsetPrioritization * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IRowsetPrioritization * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IRowsetPrioritization * This);
        
        DECLSPEC_XFGVIRT(IRowsetPrioritization, SetScopePriority)
        HRESULT ( STDMETHODCALLTYPE *SetScopePriority )( 
            __RPC__in IRowsetPrioritization * This,
            /* [annotation][in] */ 
            _In_  PRIORITY_LEVEL priority,
            /* [annotation][in] */ 
            _In_  DWORD scopeStatisticsEventFrequency);
        
        DECLSPEC_XFGVIRT(IRowsetPrioritization, GetScopePriority)
        HRESULT ( STDMETHODCALLTYPE *GetScopePriority )( 
            __RPC__in IRowsetPrioritization * This,
            /* [annotation][out] */ 
            _Out_  PRIORITY_LEVEL *priority,
            /* [annotation][out] */ 
            _Out_  DWORD *scopeStatisticsEventFrequency);
        
        DECLSPEC_XFGVIRT(IRowsetPrioritization, GetScopeStatistics)
        HRESULT ( STDMETHODCALLTYPE *GetScopeStatistics )( 
            __RPC__in IRowsetPrioritization * This,
            /* [annotation][out] */ 
            _Out_  DWORD *indexedDocumentCount,
            /* [annotation][out] */ 
            _Out_  DWORD *oustandingAddCount,
            /* [annotation][out] */ 
            _Out_  DWORD *oustandingModifyCount);
        
        END_INTERFACE
    } IRowsetPrioritizationVtbl;

    interface IRowsetPrioritization
    {
        CONST_VTBL struct IRowsetPrioritizationVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRowsetPrioritization_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRowsetPrioritization_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRowsetPrioritization_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRowsetPrioritization_SetScopePriority(This,priority,scopeStatisticsEventFrequency)	\
    ( (This)->lpVtbl -> SetScopePriority(This,priority,scopeStatisticsEventFrequency) ) 

#define IRowsetPrioritization_GetScopePriority(This,priority,scopeStatisticsEventFrequency)	\
    ( (This)->lpVtbl -> GetScopePriority(This,priority,scopeStatisticsEventFrequency) ) 

#define IRowsetPrioritization_GetScopeStatistics(This,indexedDocumentCount,oustandingAddCount,oustandingModifyCount)	\
    ( (This)->lpVtbl -> GetScopeStatistics(This,indexedDocumentCount,oustandingAddCount,oustandingModifyCount) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRowsetPrioritization_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_searchapi_0000_0023 */
/* [local] */ 

typedef /* [public][public][public][public][public][v1_enum] */ 
enum __MIDL___MIDL_itf_searchapi_0000_0023_0001
    {
        ROWSETEVENT_ITEMSTATE_NOTINROWSET	= 0,
        ROWSETEVENT_ITEMSTATE_INROWSET	= 1,
        ROWSETEVENT_ITEMSTATE_UNKNOWN	= 2
    } 	ROWSETEVENT_ITEMSTATE;

typedef /* [public][public][v1_enum] */ 
enum __MIDL___MIDL_itf_searchapi_0000_0023_0002
    {
        ROWSETEVENT_TYPE_DATAEXPIRED	= 0,
        ROWSETEVENT_TYPE_FOREGROUNDLOST	= 1,
        ROWSETEVENT_TYPE_SCOPESTATISTICS	= 2
    } 	ROWSETEVENT_TYPE;



extern RPC_IF_HANDLE __MIDL_itf_searchapi_0000_0023_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_searchapi_0000_0023_v0_0_s_ifspec;

#ifndef __IRowsetEvents_INTERFACE_DEFINED__
#define __IRowsetEvents_INTERFACE_DEFINED__

/* interface IRowsetEvents */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IRowsetEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1551AEA5-5D66-4B11-86F5-D5634CB211B9")
    IRowsetEvents : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnNewItem( 
            /* [annotation][in] */ 
            _In_  REFPROPVARIANT itemID,
            /* [annotation][in] */ 
            _In_  ROWSETEVENT_ITEMSTATE newItemState) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnChangedItem( 
            /* [annotation][in] */ 
            _In_  REFPROPVARIANT itemID,
            /* [annotation][in] */ 
            _In_  ROWSETEVENT_ITEMSTATE rowsetItemState,
            /* [annotation][in] */ 
            _In_  ROWSETEVENT_ITEMSTATE changedItemState) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnDeletedItem( 
            /* [annotation][in] */ 
            _In_  REFPROPVARIANT itemID,
            /* [annotation][in] */ 
            _In_  ROWSETEVENT_ITEMSTATE deletedItemState) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnRowsetEvent( 
            /* [annotation][in] */ 
            _In_  ROWSETEVENT_TYPE eventType,
            /* [annotation][in] */ 
            _In_  REFPROPVARIANT eventData) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRowsetEventsVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IRowsetEvents * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IRowsetEvents * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IRowsetEvents * This);
        
        DECLSPEC_XFGVIRT(IRowsetEvents, OnNewItem)
        HRESULT ( STDMETHODCALLTYPE *OnNewItem )( 
            __RPC__in IRowsetEvents * This,
            /* [annotation][in] */ 
            _In_  REFPROPVARIANT itemID,
            /* [annotation][in] */ 
            _In_  ROWSETEVENT_ITEMSTATE newItemState);
        
        DECLSPEC_XFGVIRT(IRowsetEvents, OnChangedItem)
        HRESULT ( STDMETHODCALLTYPE *OnChangedItem )( 
            __RPC__in IRowsetEvents * This,
            /* [annotation][in] */ 
            _In_  REFPROPVARIANT itemID,
            /* [annotation][in] */ 
            _In_  ROWSETEVENT_ITEMSTATE rowsetItemState,
            /* [annotation][in] */ 
            _In_  ROWSETEVENT_ITEMSTATE changedItemState);
        
        DECLSPEC_XFGVIRT(IRowsetEvents, OnDeletedItem)
        HRESULT ( STDMETHODCALLTYPE *OnDeletedItem )( 
            __RPC__in IRowsetEvents * This,
            /* [annotation][in] */ 
            _In_  REFPROPVARIANT itemID,
            /* [annotation][in] */ 
            _In_  ROWSETEVENT_ITEMSTATE deletedItemState);
        
        DECLSPEC_XFGVIRT(IRowsetEvents, OnRowsetEvent)
        HRESULT ( STDMETHODCALLTYPE *OnRowsetEvent )( 
            __RPC__in IRowsetEvents * This,
            /* [annotation][in] */ 
            _In_  ROWSETEVENT_TYPE eventType,
            /* [annotation][in] */ 
            _In_  REFPROPVARIANT eventData);
        
        END_INTERFACE
    } IRowsetEventsVtbl;

    interface IRowsetEvents
    {
        CONST_VTBL struct IRowsetEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRowsetEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRowsetEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRowsetEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRowsetEvents_OnNewItem(This,itemID,newItemState)	\
    ( (This)->lpVtbl -> OnNewItem(This,itemID,newItemState) ) 

#define IRowsetEvents_OnChangedItem(This,itemID,rowsetItemState,changedItemState)	\
    ( (This)->lpVtbl -> OnChangedItem(This,itemID,rowsetItemState,changedItemState) ) 

#define IRowsetEvents_OnDeletedItem(This,itemID,deletedItemState)	\
    ( (This)->lpVtbl -> OnDeletedItem(This,itemID,deletedItemState) ) 

#define IRowsetEvents_OnRowsetEvent(This,eventType,eventData)	\
    ( (This)->lpVtbl -> OnRowsetEvent(This,eventType,eventData) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRowsetEvents_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_searchapi_0000_0024 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion
#include <winapifamily.h>
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)


extern RPC_IF_HANDLE __MIDL_itf_searchapi_0000_0024_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_searchapi_0000_0024_v0_0_s_ifspec;

#ifndef __ISearchManager_INTERFACE_DEFINED__
#define __ISearchManager_INTERFACE_DEFINED__

/* interface ISearchManager */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_ISearchManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("AB310581-AC80-11D1-8DF3-00C04FB6EF69")
    ISearchManager : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetIndexerVersionStr( 
            /* [annotation][string][out] */ 
            _Out_  LPWSTR *ppszVersionString) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetIndexerVersion( 
            /* [annotation][out] */ 
            _Out_  DWORD *pdwMajor,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwMinor) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetParameter( 
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][retval][out] */ 
            _Out_retval_  PROPVARIANT **ppValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetParameter( 
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][in] */ 
            _In_  const PROPVARIANT *pValue) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_ProxyName( 
            /* [annotation][string][retval][out] */ 
            _Out_retval_  LPWSTR *ppszProxyName) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_BypassList( 
            /* [annotation][string][retval][out] */ 
            _Out_retval_  LPWSTR *ppszBypassList) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetProxy( 
            /* [annotation][in] */ 
            _In_  PROXY_ACCESS sUseProxy,
            /* [annotation][in] */ 
            _In_  BOOL fLocalByPassProxy,
            /* [annotation][in] */ 
            _In_  DWORD dwPortNumber,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszProxyName,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszByPassList) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCatalog( 
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszCatalog,
            /* [annotation][retval][out] */ 
            _Out_retval_  ISearchCatalogManager **ppCatalogManager) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_UserAgent( 
            /* [annotation][string][retval][out] */ 
            _Out_retval_  LPWSTR *ppszUserAgent) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_UserAgent( 
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszUserAgent) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_UseProxy( 
            /* [annotation][retval][out] */ 
            _Out_retval_  PROXY_ACCESS *pUseProxy) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_LocalBypass( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BOOL *pfLocalBypass) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_PortNumber( 
            /* [annotation][retval][out] */ 
            _Out_retval_  DWORD *pdwPortNumber) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISearchManagerVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISearchManager * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISearchManager * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISearchManager * This);
        
        DECLSPEC_XFGVIRT(ISearchManager, GetIndexerVersionStr)
        HRESULT ( STDMETHODCALLTYPE *GetIndexerVersionStr )( 
            __RPC__in ISearchManager * This,
            /* [annotation][string][out] */ 
            _Out_  LPWSTR *ppszVersionString);
        
        DECLSPEC_XFGVIRT(ISearchManager, GetIndexerVersion)
        HRESULT ( STDMETHODCALLTYPE *GetIndexerVersion )( 
            __RPC__in ISearchManager * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwMajor,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwMinor);
        
        DECLSPEC_XFGVIRT(ISearchManager, GetParameter)
        HRESULT ( STDMETHODCALLTYPE *GetParameter )( 
            __RPC__in ISearchManager * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][retval][out] */ 
            _Out_retval_  PROPVARIANT **ppValue);
        
        DECLSPEC_XFGVIRT(ISearchManager, SetParameter)
        HRESULT ( STDMETHODCALLTYPE *SetParameter )( 
            __RPC__in ISearchManager * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][in] */ 
            _In_  const PROPVARIANT *pValue);
        
        DECLSPEC_XFGVIRT(ISearchManager, get_ProxyName)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_ProxyName )( 
            __RPC__in ISearchManager * This,
            /* [annotation][string][retval][out] */ 
            _Out_retval_  LPWSTR *ppszProxyName);
        
        DECLSPEC_XFGVIRT(ISearchManager, get_BypassList)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_BypassList )( 
            __RPC__in ISearchManager * This,
            /* [annotation][string][retval][out] */ 
            _Out_retval_  LPWSTR *ppszBypassList);
        
        DECLSPEC_XFGVIRT(ISearchManager, SetProxy)
        HRESULT ( STDMETHODCALLTYPE *SetProxy )( 
            __RPC__in ISearchManager * This,
            /* [annotation][in] */ 
            _In_  PROXY_ACCESS sUseProxy,
            /* [annotation][in] */ 
            _In_  BOOL fLocalByPassProxy,
            /* [annotation][in] */ 
            _In_  DWORD dwPortNumber,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszProxyName,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszByPassList);
        
        DECLSPEC_XFGVIRT(ISearchManager, GetCatalog)
        HRESULT ( STDMETHODCALLTYPE *GetCatalog )( 
            __RPC__in ISearchManager * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszCatalog,
            /* [annotation][retval][out] */ 
            _Out_retval_  ISearchCatalogManager **ppCatalogManager);
        
        DECLSPEC_XFGVIRT(ISearchManager, get_UserAgent)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_UserAgent )( 
            __RPC__in ISearchManager * This,
            /* [annotation][string][retval][out] */ 
            _Out_retval_  LPWSTR *ppszUserAgent);
        
        DECLSPEC_XFGVIRT(ISearchManager, put_UserAgent)
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_UserAgent )( 
            __RPC__in ISearchManager * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszUserAgent);
        
        DECLSPEC_XFGVIRT(ISearchManager, get_UseProxy)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_UseProxy )( 
            __RPC__in ISearchManager * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  PROXY_ACCESS *pUseProxy);
        
        DECLSPEC_XFGVIRT(ISearchManager, get_LocalBypass)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_LocalBypass )( 
            __RPC__in ISearchManager * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BOOL *pfLocalBypass);
        
        DECLSPEC_XFGVIRT(ISearchManager, get_PortNumber)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_PortNumber )( 
            __RPC__in ISearchManager * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  DWORD *pdwPortNumber);
        
        END_INTERFACE
    } ISearchManagerVtbl;

    interface ISearchManager
    {
        CONST_VTBL struct ISearchManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISearchManager_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISearchManager_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISearchManager_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISearchManager_GetIndexerVersionStr(This,ppszVersionString)	\
    ( (This)->lpVtbl -> GetIndexerVersionStr(This,ppszVersionString) ) 

#define ISearchManager_GetIndexerVersion(This,pdwMajor,pdwMinor)	\
    ( (This)->lpVtbl -> GetIndexerVersion(This,pdwMajor,pdwMinor) ) 

#define ISearchManager_GetParameter(This,pszName,ppValue)	\
    ( (This)->lpVtbl -> GetParameter(This,pszName,ppValue) ) 

#define ISearchManager_SetParameter(This,pszName,pValue)	\
    ( (This)->lpVtbl -> SetParameter(This,pszName,pValue) ) 

#define ISearchManager_get_ProxyName(This,ppszProxyName)	\
    ( (This)->lpVtbl -> get_ProxyName(This,ppszProxyName) ) 

#define ISearchManager_get_BypassList(This,ppszBypassList)	\
    ( (This)->lpVtbl -> get_BypassList(This,ppszBypassList) ) 

#define ISearchManager_SetProxy(This,sUseProxy,fLocalByPassProxy,dwPortNumber,pszProxyName,pszByPassList)	\
    ( (This)->lpVtbl -> SetProxy(This,sUseProxy,fLocalByPassProxy,dwPortNumber,pszProxyName,pszByPassList) ) 

#define ISearchManager_GetCatalog(This,pszCatalog,ppCatalogManager)	\
    ( (This)->lpVtbl -> GetCatalog(This,pszCatalog,ppCatalogManager) ) 

#define ISearchManager_get_UserAgent(This,ppszUserAgent)	\
    ( (This)->lpVtbl -> get_UserAgent(This,ppszUserAgent) ) 

#define ISearchManager_put_UserAgent(This,pszUserAgent)	\
    ( (This)->lpVtbl -> put_UserAgent(This,pszUserAgent) ) 

#define ISearchManager_get_UseProxy(This,pUseProxy)	\
    ( (This)->lpVtbl -> get_UseProxy(This,pUseProxy) ) 

#define ISearchManager_get_LocalBypass(This,pfLocalBypass)	\
    ( (This)->lpVtbl -> get_LocalBypass(This,pfLocalBypass) ) 

#define ISearchManager_get_PortNumber(This,pdwPortNumber)	\
    ( (This)->lpVtbl -> get_PortNumber(This,pdwPortNumber) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISearchManager_INTERFACE_DEFINED__ */


#ifndef __ISearchManager2_INTERFACE_DEFINED__
#define __ISearchManager2_INTERFACE_DEFINED__

/* interface ISearchManager2 */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_ISearchManager2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DBAB3F73-DB19-4A79-BFC0-A61A93886DDF")
    ISearchManager2 : public ISearchManager
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CreateCatalog( 
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszCatalog,
            /* [annotation][out] */ 
            _Out_  ISearchCatalogManager **ppCatalogManager) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DeleteCatalog( 
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszCatalog) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISearchManager2Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISearchManager2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISearchManager2 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISearchManager2 * This);
        
        DECLSPEC_XFGVIRT(ISearchManager, GetIndexerVersionStr)
        HRESULT ( STDMETHODCALLTYPE *GetIndexerVersionStr )( 
            __RPC__in ISearchManager2 * This,
            /* [annotation][string][out] */ 
            _Out_  LPWSTR *ppszVersionString);
        
        DECLSPEC_XFGVIRT(ISearchManager, GetIndexerVersion)
        HRESULT ( STDMETHODCALLTYPE *GetIndexerVersion )( 
            __RPC__in ISearchManager2 * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwMajor,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwMinor);
        
        DECLSPEC_XFGVIRT(ISearchManager, GetParameter)
        HRESULT ( STDMETHODCALLTYPE *GetParameter )( 
            __RPC__in ISearchManager2 * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][retval][out] */ 
            _Out_retval_  PROPVARIANT **ppValue);
        
        DECLSPEC_XFGVIRT(ISearchManager, SetParameter)
        HRESULT ( STDMETHODCALLTYPE *SetParameter )( 
            __RPC__in ISearchManager2 * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][in] */ 
            _In_  const PROPVARIANT *pValue);
        
        DECLSPEC_XFGVIRT(ISearchManager, get_ProxyName)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_ProxyName )( 
            __RPC__in ISearchManager2 * This,
            /* [annotation][string][retval][out] */ 
            _Out_retval_  LPWSTR *ppszProxyName);
        
        DECLSPEC_XFGVIRT(ISearchManager, get_BypassList)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_BypassList )( 
            __RPC__in ISearchManager2 * This,
            /* [annotation][string][retval][out] */ 
            _Out_retval_  LPWSTR *ppszBypassList);
        
        DECLSPEC_XFGVIRT(ISearchManager, SetProxy)
        HRESULT ( STDMETHODCALLTYPE *SetProxy )( 
            __RPC__in ISearchManager2 * This,
            /* [annotation][in] */ 
            _In_  PROXY_ACCESS sUseProxy,
            /* [annotation][in] */ 
            _In_  BOOL fLocalByPassProxy,
            /* [annotation][in] */ 
            _In_  DWORD dwPortNumber,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszProxyName,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszByPassList);
        
        DECLSPEC_XFGVIRT(ISearchManager, GetCatalog)
        HRESULT ( STDMETHODCALLTYPE *GetCatalog )( 
            __RPC__in ISearchManager2 * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszCatalog,
            /* [annotation][retval][out] */ 
            _Out_retval_  ISearchCatalogManager **ppCatalogManager);
        
        DECLSPEC_XFGVIRT(ISearchManager, get_UserAgent)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_UserAgent )( 
            __RPC__in ISearchManager2 * This,
            /* [annotation][string][retval][out] */ 
            _Out_retval_  LPWSTR *ppszUserAgent);
        
        DECLSPEC_XFGVIRT(ISearchManager, put_UserAgent)
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_UserAgent )( 
            __RPC__in ISearchManager2 * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszUserAgent);
        
        DECLSPEC_XFGVIRT(ISearchManager, get_UseProxy)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_UseProxy )( 
            __RPC__in ISearchManager2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  PROXY_ACCESS *pUseProxy);
        
        DECLSPEC_XFGVIRT(ISearchManager, get_LocalBypass)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_LocalBypass )( 
            __RPC__in ISearchManager2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BOOL *pfLocalBypass);
        
        DECLSPEC_XFGVIRT(ISearchManager, get_PortNumber)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_PortNumber )( 
            __RPC__in ISearchManager2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  DWORD *pdwPortNumber);
        
        DECLSPEC_XFGVIRT(ISearchManager2, CreateCatalog)
        HRESULT ( STDMETHODCALLTYPE *CreateCatalog )( 
            __RPC__in ISearchManager2 * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszCatalog,
            /* [annotation][out] */ 
            _Out_  ISearchCatalogManager **ppCatalogManager);
        
        DECLSPEC_XFGVIRT(ISearchManager2, DeleteCatalog)
        HRESULT ( STDMETHODCALLTYPE *DeleteCatalog )( 
            __RPC__in ISearchManager2 * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszCatalog);
        
        END_INTERFACE
    } ISearchManager2Vtbl;

    interface ISearchManager2
    {
        CONST_VTBL struct ISearchManager2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISearchManager2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISearchManager2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISearchManager2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISearchManager2_GetIndexerVersionStr(This,ppszVersionString)	\
    ( (This)->lpVtbl -> GetIndexerVersionStr(This,ppszVersionString) ) 

#define ISearchManager2_GetIndexerVersion(This,pdwMajor,pdwMinor)	\
    ( (This)->lpVtbl -> GetIndexerVersion(This,pdwMajor,pdwMinor) ) 

#define ISearchManager2_GetParameter(This,pszName,ppValue)	\
    ( (This)->lpVtbl -> GetParameter(This,pszName,ppValue) ) 

#define ISearchManager2_SetParameter(This,pszName,pValue)	\
    ( (This)->lpVtbl -> SetParameter(This,pszName,pValue) ) 

#define ISearchManager2_get_ProxyName(This,ppszProxyName)	\
    ( (This)->lpVtbl -> get_ProxyName(This,ppszProxyName) ) 

#define ISearchManager2_get_BypassList(This,ppszBypassList)	\
    ( (This)->lpVtbl -> get_BypassList(This,ppszBypassList) ) 

#define ISearchManager2_SetProxy(This,sUseProxy,fLocalByPassProxy,dwPortNumber,pszProxyName,pszByPassList)	\
    ( (This)->lpVtbl -> SetProxy(This,sUseProxy,fLocalByPassProxy,dwPortNumber,pszProxyName,pszByPassList) ) 

#define ISearchManager2_GetCatalog(This,pszCatalog,ppCatalogManager)	\
    ( (This)->lpVtbl -> GetCatalog(This,pszCatalog,ppCatalogManager) ) 

#define ISearchManager2_get_UserAgent(This,ppszUserAgent)	\
    ( (This)->lpVtbl -> get_UserAgent(This,ppszUserAgent) ) 

#define ISearchManager2_put_UserAgent(This,pszUserAgent)	\
    ( (This)->lpVtbl -> put_UserAgent(This,pszUserAgent) ) 

#define ISearchManager2_get_UseProxy(This,pUseProxy)	\
    ( (This)->lpVtbl -> get_UseProxy(This,pUseProxy) ) 

#define ISearchManager2_get_LocalBypass(This,pfLocalBypass)	\
    ( (This)->lpVtbl -> get_LocalBypass(This,pfLocalBypass) ) 

#define ISearchManager2_get_PortNumber(This,pdwPortNumber)	\
    ( (This)->lpVtbl -> get_PortNumber(This,pdwPortNumber) ) 


#define ISearchManager2_CreateCatalog(This,pszCatalog,ppCatalogManager)	\
    ( (This)->lpVtbl -> CreateCatalog(This,pszCatalog,ppCatalogManager) ) 

#define ISearchManager2_DeleteCatalog(This,pszCatalog)	\
    ( (This)->lpVtbl -> DeleteCatalog(This,pszCatalog) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISearchManager2_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_searchapi_0000_0026 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion
#include <winapifamily.h>
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
EXTERN_C const CLSID CLSID_CSearchLanguageSupport;
#ifdef __cplusplus
class DECLSPEC_UUID("6A68CC80-4337-4dbc-BD27-FBFB1053820B")
CSearchLanguageSupport;
#endif


extern RPC_IF_HANDLE __MIDL_itf_searchapi_0000_0026_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_searchapi_0000_0026_v0_0_s_ifspec;

#ifndef __ISearchLanguageSupport_INTERFACE_DEFINED__
#define __ISearchLanguageSupport_INTERFACE_DEFINED__

/* interface ISearchLanguageSupport */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_ISearchLanguageSupport;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("24C3CBAA-EBC1-491a-9EF1-9F6D8DEB1B8F")
    ISearchLanguageSupport : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetDiacriticSensitivity( 
            /* [annotation][in] */ 
            _In_  BOOL fDiacriticSensitive) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDiacriticSensitivity( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BOOL *pfDiacriticSensitive) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadWordBreaker( 
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppWordBreaker,
            /* [annotation][out] */ 
            _Out_  LCID *pLcidUsed) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadStemmer( 
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppStemmer,
            /* [annotation][out] */ 
            _Out_  LCID *pLcidUsed) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsPrefixNormalized( 
            /* [annotation][size_is][in] */ 
            _In_reads_(cwcQueryToken)  LPCWSTR pwcsQueryToken,
            /* [annotation][in] */ 
            _In_  ULONG cwcQueryToken,
            /* [annotation][size_is][in] */ 
            _In_reads_(cwcDocumentToken)  LPCWSTR pwcsDocumentToken,
            /* [annotation][in] */ 
            _In_  ULONG cwcDocumentToken,
            /* [annotation][out] */ 
            _Out_  ULONG *pulPrefixLength) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISearchLanguageSupportVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISearchLanguageSupport * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISearchLanguageSupport * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISearchLanguageSupport * This);
        
        DECLSPEC_XFGVIRT(ISearchLanguageSupport, SetDiacriticSensitivity)
        HRESULT ( STDMETHODCALLTYPE *SetDiacriticSensitivity )( 
            __RPC__in ISearchLanguageSupport * This,
            /* [annotation][in] */ 
            _In_  BOOL fDiacriticSensitive);
        
        DECLSPEC_XFGVIRT(ISearchLanguageSupport, GetDiacriticSensitivity)
        HRESULT ( STDMETHODCALLTYPE *GetDiacriticSensitivity )( 
            __RPC__in ISearchLanguageSupport * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BOOL *pfDiacriticSensitive);
        
        DECLSPEC_XFGVIRT(ISearchLanguageSupport, LoadWordBreaker)
        HRESULT ( STDMETHODCALLTYPE *LoadWordBreaker )( 
            __RPC__in ISearchLanguageSupport * This,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppWordBreaker,
            /* [annotation][out] */ 
            _Out_  LCID *pLcidUsed);
        
        DECLSPEC_XFGVIRT(ISearchLanguageSupport, LoadStemmer)
        HRESULT ( STDMETHODCALLTYPE *LoadStemmer )( 
            __RPC__in ISearchLanguageSupport * This,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppStemmer,
            /* [annotation][out] */ 
            _Out_  LCID *pLcidUsed);
        
        DECLSPEC_XFGVIRT(ISearchLanguageSupport, IsPrefixNormalized)
        HRESULT ( STDMETHODCALLTYPE *IsPrefixNormalized )( 
            __RPC__in ISearchLanguageSupport * This,
            /* [annotation][size_is][in] */ 
            _In_reads_(cwcQueryToken)  LPCWSTR pwcsQueryToken,
            /* [annotation][in] */ 
            _In_  ULONG cwcQueryToken,
            /* [annotation][size_is][in] */ 
            _In_reads_(cwcDocumentToken)  LPCWSTR pwcsDocumentToken,
            /* [annotation][in] */ 
            _In_  ULONG cwcDocumentToken,
            /* [annotation][out] */ 
            _Out_  ULONG *pulPrefixLength);
        
        END_INTERFACE
    } ISearchLanguageSupportVtbl;

    interface ISearchLanguageSupport
    {
        CONST_VTBL struct ISearchLanguageSupportVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISearchLanguageSupport_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISearchLanguageSupport_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISearchLanguageSupport_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISearchLanguageSupport_SetDiacriticSensitivity(This,fDiacriticSensitive)	\
    ( (This)->lpVtbl -> SetDiacriticSensitivity(This,fDiacriticSensitive) ) 

#define ISearchLanguageSupport_GetDiacriticSensitivity(This,pfDiacriticSensitive)	\
    ( (This)->lpVtbl -> GetDiacriticSensitivity(This,pfDiacriticSensitive) ) 

#define ISearchLanguageSupport_LoadWordBreaker(This,lcid,riid,ppWordBreaker,pLcidUsed)	\
    ( (This)->lpVtbl -> LoadWordBreaker(This,lcid,riid,ppWordBreaker,pLcidUsed) ) 

#define ISearchLanguageSupport_LoadStemmer(This,lcid,riid,ppStemmer,pLcidUsed)	\
    ( (This)->lpVtbl -> LoadStemmer(This,lcid,riid,ppStemmer,pLcidUsed) ) 

#define ISearchLanguageSupport_IsPrefixNormalized(This,pwcsQueryToken,cwcQueryToken,pwcsDocumentToken,cwcDocumentToken,pulPrefixLength)	\
    ( (This)->lpVtbl -> IsPrefixNormalized(This,pwcsQueryToken,cwcQueryToken,pwcsDocumentToken,cwcDocumentToken,pulPrefixLength) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISearchLanguageSupport_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_searchapi_0000_0027 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_searchapi_0000_0027_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_searchapi_0000_0027_v0_0_s_ifspec;


#ifndef __SearchAPILib_LIBRARY_DEFINED__
#define __SearchAPILib_LIBRARY_DEFINED__

/* library SearchAPILib */
/* [version][uuid] */ 









EXTERN_C const IID LIBID_SearchAPILib;

EXTERN_C const CLSID CLSID_CSearchManager;

#ifdef __cplusplus

class DECLSPEC_UUID("7D096C5F-AC08-4f1f-BEB7-5C22C517CE39")
CSearchManager;
#endif

EXTERN_C const CLSID CLSID_CSearchRoot;

#ifdef __cplusplus

class DECLSPEC_UUID("30766BD2-EA1C-4F28-BF27-0B44E2F68DB7")
CSearchRoot;
#endif

EXTERN_C const CLSID CLSID_CSearchScopeRule;

#ifdef __cplusplus

class DECLSPEC_UUID("E63DE750-3BD7-4BE5-9C84-6B4281988C44")
CSearchScopeRule;
#endif

EXTERN_C const CLSID CLSID_FilterRegistration;

#ifdef __cplusplus

class DECLSPEC_UUID("9E175B8D-F52A-11D8-B9A5-505054503030")
FilterRegistration;
#endif
#endif /* __SearchAPILib_LIBRARY_DEFINED__ */

/* interface __MIDL_itf_searchapi_0000_0028 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_searchapi_0000_0028_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_searchapi_0000_0028_v0_0_s_ifspec;

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

/* [local] */ HRESULT STDMETHODCALLTYPE ISearchCrawlScopeManager2_GetVersion_Proxy( 
    ISearchCrawlScopeManager2 * This,
    /* [annotation][out] */ 
    _Out_  long **plVersion,
    /* [annotation][out] */ 
    _Out_  HANDLE *phFileMapping);


/* [call_as] */ HRESULT STDMETHODCALLTYPE ISearchCrawlScopeManager2_GetVersion_Stub( 
    __RPC__in ISearchCrawlScopeManager2 * This,
    /* [annotation][out] */ 
    _Out_  long *plVersion);



/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


