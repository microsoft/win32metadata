

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

#ifndef __urlhist_h__
#define __urlhist_h__

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

#ifndef __IEnumSTATURL_FWD_DEFINED__
#define __IEnumSTATURL_FWD_DEFINED__
typedef interface IEnumSTATURL IEnumSTATURL;

#endif 	/* __IEnumSTATURL_FWD_DEFINED__ */


#ifndef __IUrlHistoryStg_FWD_DEFINED__
#define __IUrlHistoryStg_FWD_DEFINED__
typedef interface IUrlHistoryStg IUrlHistoryStg;

#endif 	/* __IUrlHistoryStg_FWD_DEFINED__ */


#ifndef __IUrlHistoryStg2_FWD_DEFINED__
#define __IUrlHistoryStg2_FWD_DEFINED__
typedef interface IUrlHistoryStg2 IUrlHistoryStg2;

#endif 	/* __IUrlHistoryStg2_FWD_DEFINED__ */


#ifndef __IUrlHistoryNotify_FWD_DEFINED__
#define __IUrlHistoryNotify_FWD_DEFINED__
typedef interface IUrlHistoryNotify IUrlHistoryNotify;

#endif 	/* __IUrlHistoryNotify_FWD_DEFINED__ */


/* header files for imported files */
#include "objidl.h"
#include "oleidl.h"
#include "oaidl.h"
#include "docobj.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_urlhist_0000_0000 */
/* [local] */ 

//=--------------------------------------------------------------------------=
// UrlHist.h
//=--------------------------------------------------------------------------=
// (C) Copyright Microsoft Corporation.  All Rights Reserved.
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//=--------------------------------------------------------------------------=

#pragma comment(lib,"uuid.lib")

//---------------------------------------------------------------------------=
// Url History Interfaces.

#include <winapifamily.h>
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)


#define STATURL_QUERYFLAG_ISCACHED		0x00010000
#define STATURL_QUERYFLAG_NOURL              0x00020000
#define STATURL_QUERYFLAG_NOTITLE            0x00040000
#define STATURL_QUERYFLAG_TOPLEVEL           0x00080000
#define STATURLFLAG_ISCACHED		0x00000001
#define STATURLFLAG_ISTOPLEVEL       0x00000002
typedef 
enum _ADDURL_FLAG
    {
        ADDURL_FIRST	= 0,
        ADDURL_ADDTOHISTORYANDCACHE	= 0,
        ADDURL_ADDTOCACHE	= 1,
        ADDURL_Max	= 2147483647L
    } 	ADDURL_FLAG;


////////////////////////////////////////////////////////////////////////////
//  Interface Definitions
#ifndef _LPENUMSTATURL_DEFINED
#define _LPENUMSTATURL_DEFINED


extern RPC_IF_HANDLE __MIDL_itf_urlhist_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_urlhist_0000_0000_v0_0_s_ifspec;

#ifndef __IEnumSTATURL_INTERFACE_DEFINED__
#define __IEnumSTATURL_INTERFACE_DEFINED__

/* interface IEnumSTATURL */
/* [unique][uuid][object] */ 

typedef /* [unique] */  __RPC_unique_pointer IEnumSTATURL *LPENUMSTATURL;

typedef struct _STATURL
    {
    DWORD cbSize;
    LPWSTR pwcsUrl;
    LPWSTR pwcsTitle;
    FILETIME ftLastVisited;
    FILETIME ftLastUpdated;
    FILETIME ftExpires;
    DWORD dwFlags;
    } 	STATURL;

typedef struct _STATURL *LPSTATURL;


EXTERN_C const IID IID_IEnumSTATURL;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3C374A42-BAE4-11CF-BF7D-00AA006946EE")
    IEnumSTATURL : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [annotation][in] */ 
            _In_  ULONG celt,
            /* [annotation][out][in] */ 
            _Inout_  LPSTATURL rgelt,
            /* [annotation][out][in] */ 
            _Inout_  ULONG *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [annotation][in] */ 
            _In_  ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [annotation][out] */ 
            _Out_  IEnumSTATURL **ppenum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetFilter( 
            /* [annotation][unique][in] */ 
            _In_  LPCOLESTR poszFilter,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IEnumSTATURLVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IEnumSTATURL * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IEnumSTATURL * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IEnumSTATURL * This);
        
        DECLSPEC_XFGVIRT(IEnumSTATURL, Next)
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            __RPC__in IEnumSTATURL * This,
            /* [annotation][in] */ 
            _In_  ULONG celt,
            /* [annotation][out][in] */ 
            _Inout_  LPSTATURL rgelt,
            /* [annotation][out][in] */ 
            _Inout_  ULONG *pceltFetched);
        
        DECLSPEC_XFGVIRT(IEnumSTATURL, Skip)
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            __RPC__in IEnumSTATURL * This,
            /* [annotation][in] */ 
            _In_  ULONG celt);
        
        DECLSPEC_XFGVIRT(IEnumSTATURL, Reset)
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            __RPC__in IEnumSTATURL * This);
        
        DECLSPEC_XFGVIRT(IEnumSTATURL, Clone)
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            __RPC__in IEnumSTATURL * This,
            /* [annotation][out] */ 
            _Out_  IEnumSTATURL **ppenum);
        
        DECLSPEC_XFGVIRT(IEnumSTATURL, SetFilter)
        HRESULT ( STDMETHODCALLTYPE *SetFilter )( 
            __RPC__in IEnumSTATURL * This,
            /* [annotation][unique][in] */ 
            _In_  LPCOLESTR poszFilter,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags);
        
        END_INTERFACE
    } IEnumSTATURLVtbl;

    interface IEnumSTATURL
    {
        CONST_VTBL struct IEnumSTATURLVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumSTATURL_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEnumSTATURL_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEnumSTATURL_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IEnumSTATURL_Next(This,celt,rgelt,pceltFetched)	\
    ( (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched) ) 

#define IEnumSTATURL_Skip(This,celt)	\
    ( (This)->lpVtbl -> Skip(This,celt) ) 

#define IEnumSTATURL_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define IEnumSTATURL_Clone(This,ppenum)	\
    ( (This)->lpVtbl -> Clone(This,ppenum) ) 

#define IEnumSTATURL_SetFilter(This,poszFilter,dwFlags)	\
    ( (This)->lpVtbl -> SetFilter(This,poszFilter,dwFlags) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IEnumSTATURL_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_urlhist_0000_0001 */
/* [local] */ 

#endif
#ifndef _LPURLHISTORYSTG_DEFINED
#define _LPURLHISTORYSTG_DEFINED


extern RPC_IF_HANDLE __MIDL_itf_urlhist_0000_0001_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_urlhist_0000_0001_v0_0_s_ifspec;

#ifndef __IUrlHistoryStg_INTERFACE_DEFINED__
#define __IUrlHistoryStg_INTERFACE_DEFINED__

/* interface IUrlHistoryStg */
/* [unique][uuid][object] */ 

typedef /* [unique] */  __RPC_unique_pointer IUrlHistoryStg *LPURLHISTORYSTG;


EXTERN_C const IID IID_IUrlHistoryStg;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3C374A41-BAE4-11CF-BF7D-00AA006946EE")
    IUrlHistoryStg : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AddUrl( 
            /* [annotation][in] */ 
            _In_  LPCOLESTR pocsUrl,
            /* [annotation][unique][in] */ 
            _In_  LPCOLESTR pocsTitle,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DeleteUrl( 
            /* [annotation][in] */ 
            _In_  LPCOLESTR pocsUrl,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryUrl( 
            /* [annotation][in] */ 
            _In_  LPCOLESTR pocsUrl,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][unique][out][in] */ 
            _Inout_  LPSTATURL lpSTATURL) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE BindToObject( 
            /* [annotation][in] */ 
            _In_  LPCOLESTR pocsUrl,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumUrls( 
            /* [annotation][out] */ 
            _Out_  IEnumSTATURL **ppEnum) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IUrlHistoryStgVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IUrlHistoryStg * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IUrlHistoryStg * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IUrlHistoryStg * This);
        
        DECLSPEC_XFGVIRT(IUrlHistoryStg, AddUrl)
        HRESULT ( STDMETHODCALLTYPE *AddUrl )( 
            __RPC__in IUrlHistoryStg * This,
            /* [annotation][in] */ 
            _In_  LPCOLESTR pocsUrl,
            /* [annotation][unique][in] */ 
            _In_  LPCOLESTR pocsTitle,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags);
        
        DECLSPEC_XFGVIRT(IUrlHistoryStg, DeleteUrl)
        HRESULT ( STDMETHODCALLTYPE *DeleteUrl )( 
            __RPC__in IUrlHistoryStg * This,
            /* [annotation][in] */ 
            _In_  LPCOLESTR pocsUrl,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags);
        
        DECLSPEC_XFGVIRT(IUrlHistoryStg, QueryUrl)
        HRESULT ( STDMETHODCALLTYPE *QueryUrl )( 
            __RPC__in IUrlHistoryStg * This,
            /* [annotation][in] */ 
            _In_  LPCOLESTR pocsUrl,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][unique][out][in] */ 
            _Inout_  LPSTATURL lpSTATURL);
        
        DECLSPEC_XFGVIRT(IUrlHistoryStg, BindToObject)
        HRESULT ( STDMETHODCALLTYPE *BindToObject )( 
            __RPC__in IUrlHistoryStg * This,
            /* [annotation][in] */ 
            _In_  LPCOLESTR pocsUrl,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvOut);
        
        DECLSPEC_XFGVIRT(IUrlHistoryStg, EnumUrls)
        HRESULT ( STDMETHODCALLTYPE *EnumUrls )( 
            __RPC__in IUrlHistoryStg * This,
            /* [annotation][out] */ 
            _Out_  IEnumSTATURL **ppEnum);
        
        END_INTERFACE
    } IUrlHistoryStgVtbl;

    interface IUrlHistoryStg
    {
        CONST_VTBL struct IUrlHistoryStgVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IUrlHistoryStg_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IUrlHistoryStg_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IUrlHistoryStg_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IUrlHistoryStg_AddUrl(This,pocsUrl,pocsTitle,dwFlags)	\
    ( (This)->lpVtbl -> AddUrl(This,pocsUrl,pocsTitle,dwFlags) ) 

#define IUrlHistoryStg_DeleteUrl(This,pocsUrl,dwFlags)	\
    ( (This)->lpVtbl -> DeleteUrl(This,pocsUrl,dwFlags) ) 

#define IUrlHistoryStg_QueryUrl(This,pocsUrl,dwFlags,lpSTATURL)	\
    ( (This)->lpVtbl -> QueryUrl(This,pocsUrl,dwFlags,lpSTATURL) ) 

#define IUrlHistoryStg_BindToObject(This,pocsUrl,riid,ppvOut)	\
    ( (This)->lpVtbl -> BindToObject(This,pocsUrl,riid,ppvOut) ) 

#define IUrlHistoryStg_EnumUrls(This,ppEnum)	\
    ( (This)->lpVtbl -> EnumUrls(This,ppEnum) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IUrlHistoryStg_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_urlhist_0000_0002 */
/* [local] */ 

#endif
#ifndef _LPURLHISTORYSTG2_DEFINED
#define _LPURLHISTORYSTG2_DEFINED


extern RPC_IF_HANDLE __MIDL_itf_urlhist_0000_0002_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_urlhist_0000_0002_v0_0_s_ifspec;

#ifndef __IUrlHistoryStg2_INTERFACE_DEFINED__
#define __IUrlHistoryStg2_INTERFACE_DEFINED__

/* interface IUrlHistoryStg2 */
/* [unique][uuid][object] */ 

typedef /* [unique] */  __RPC_unique_pointer IUrlHistoryStg2 *LPURLHISTORYSTG2;


EXTERN_C const IID IID_IUrlHistoryStg2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("AFA0DC11-C313-11d0-831A-00C04FD5AE38")
    IUrlHistoryStg2 : public IUrlHistoryStg
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AddUrlAndNotify( 
            /* [annotation][in] */ 
            _In_  LPCOLESTR pocsUrl,
            /* [annotation][unique][in] */ 
            _In_  LPCOLESTR pocsTitle,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][in] */ 
            _In_  BOOL fWriteHistory,
            /* [annotation][in] */ 
            _In_  IOleCommandTarget *poctNotify,
            /* [annotation][unique][in] */ 
            _In_  IUnknown *punkISFolder) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ClearHistory( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IUrlHistoryStg2Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IUrlHistoryStg2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IUrlHistoryStg2 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IUrlHistoryStg2 * This);
        
        DECLSPEC_XFGVIRT(IUrlHistoryStg, AddUrl)
        HRESULT ( STDMETHODCALLTYPE *AddUrl )( 
            __RPC__in IUrlHistoryStg2 * This,
            /* [annotation][in] */ 
            _In_  LPCOLESTR pocsUrl,
            /* [annotation][unique][in] */ 
            _In_  LPCOLESTR pocsTitle,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags);
        
        DECLSPEC_XFGVIRT(IUrlHistoryStg, DeleteUrl)
        HRESULT ( STDMETHODCALLTYPE *DeleteUrl )( 
            __RPC__in IUrlHistoryStg2 * This,
            /* [annotation][in] */ 
            _In_  LPCOLESTR pocsUrl,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags);
        
        DECLSPEC_XFGVIRT(IUrlHistoryStg, QueryUrl)
        HRESULT ( STDMETHODCALLTYPE *QueryUrl )( 
            __RPC__in IUrlHistoryStg2 * This,
            /* [annotation][in] */ 
            _In_  LPCOLESTR pocsUrl,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][unique][out][in] */ 
            _Inout_  LPSTATURL lpSTATURL);
        
        DECLSPEC_XFGVIRT(IUrlHistoryStg, BindToObject)
        HRESULT ( STDMETHODCALLTYPE *BindToObject )( 
            __RPC__in IUrlHistoryStg2 * This,
            /* [annotation][in] */ 
            _In_  LPCOLESTR pocsUrl,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvOut);
        
        DECLSPEC_XFGVIRT(IUrlHistoryStg, EnumUrls)
        HRESULT ( STDMETHODCALLTYPE *EnumUrls )( 
            __RPC__in IUrlHistoryStg2 * This,
            /* [annotation][out] */ 
            _Out_  IEnumSTATURL **ppEnum);
        
        DECLSPEC_XFGVIRT(IUrlHistoryStg2, AddUrlAndNotify)
        HRESULT ( STDMETHODCALLTYPE *AddUrlAndNotify )( 
            __RPC__in IUrlHistoryStg2 * This,
            /* [annotation][in] */ 
            _In_  LPCOLESTR pocsUrl,
            /* [annotation][unique][in] */ 
            _In_  LPCOLESTR pocsTitle,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][in] */ 
            _In_  BOOL fWriteHistory,
            /* [annotation][in] */ 
            _In_  IOleCommandTarget *poctNotify,
            /* [annotation][unique][in] */ 
            _In_  IUnknown *punkISFolder);
        
        DECLSPEC_XFGVIRT(IUrlHistoryStg2, ClearHistory)
        HRESULT ( STDMETHODCALLTYPE *ClearHistory )( 
            __RPC__in IUrlHistoryStg2 * This);
        
        END_INTERFACE
    } IUrlHistoryStg2Vtbl;

    interface IUrlHistoryStg2
    {
        CONST_VTBL struct IUrlHistoryStg2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IUrlHistoryStg2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IUrlHistoryStg2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IUrlHistoryStg2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IUrlHistoryStg2_AddUrl(This,pocsUrl,pocsTitle,dwFlags)	\
    ( (This)->lpVtbl -> AddUrl(This,pocsUrl,pocsTitle,dwFlags) ) 

#define IUrlHistoryStg2_DeleteUrl(This,pocsUrl,dwFlags)	\
    ( (This)->lpVtbl -> DeleteUrl(This,pocsUrl,dwFlags) ) 

#define IUrlHistoryStg2_QueryUrl(This,pocsUrl,dwFlags,lpSTATURL)	\
    ( (This)->lpVtbl -> QueryUrl(This,pocsUrl,dwFlags,lpSTATURL) ) 

#define IUrlHistoryStg2_BindToObject(This,pocsUrl,riid,ppvOut)	\
    ( (This)->lpVtbl -> BindToObject(This,pocsUrl,riid,ppvOut) ) 

#define IUrlHistoryStg2_EnumUrls(This,ppEnum)	\
    ( (This)->lpVtbl -> EnumUrls(This,ppEnum) ) 


#define IUrlHistoryStg2_AddUrlAndNotify(This,pocsUrl,pocsTitle,dwFlags,fWriteHistory,poctNotify,punkISFolder)	\
    ( (This)->lpVtbl -> AddUrlAndNotify(This,pocsUrl,pocsTitle,dwFlags,fWriteHistory,poctNotify,punkISFolder) ) 

#define IUrlHistoryStg2_ClearHistory(This)	\
    ( (This)->lpVtbl -> ClearHistory(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IUrlHistoryStg2_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_urlhist_0000_0003 */
/* [local] */ 

#endif
#ifndef _LPURLHISTORYNOTIFY_DEFINED
#define _LPURLHISTORYNOTIFY_DEFINED


extern RPC_IF_HANDLE __MIDL_itf_urlhist_0000_0003_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_urlhist_0000_0003_v0_0_s_ifspec;

#ifndef __IUrlHistoryNotify_INTERFACE_DEFINED__
#define __IUrlHistoryNotify_INTERFACE_DEFINED__

/* interface IUrlHistoryNotify */
/* [unique][uuid][object] */ 

typedef /* [unique] */  __RPC_unique_pointer IUrlHistoryNotify *LPURLHISTORYNOTIFY;


EXTERN_C const IID IID_IUrlHistoryNotify;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BC40BEC1-C493-11d0-831B-00C04FD5AE38")
    IUrlHistoryNotify : public IOleCommandTarget
    {
    public:
    };
    
    
#else 	/* C style interface */

    typedef struct IUrlHistoryNotifyVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IUrlHistoryNotify * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IUrlHistoryNotify * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IUrlHistoryNotify * This);
        
        DECLSPEC_XFGVIRT(IOleCommandTarget, QueryStatus)
        /* [input_sync] */ HRESULT ( STDMETHODCALLTYPE *QueryStatus )( 
            __RPC__in IUrlHistoryNotify * This,
            /* [annotation][unique][in] */ 
            _In_  const GUID *pguidCmdGroup,
            /* [annotation][in] */ 
            _In_  ULONG cCmds,
            /* [annotation][out][in][size_is] */ 
            _Inout_  OLECMD prgCmds[  ],
            /* [annotation][unique][out][in] */ 
            _Inout_  OLECMDTEXT *pCmdText);
        
        DECLSPEC_XFGVIRT(IOleCommandTarget, Exec)
        HRESULT ( STDMETHODCALLTYPE *Exec )( 
            __RPC__in IUrlHistoryNotify * This,
            /* [annotation][unique][in] */ 
            _In_  const GUID *pguidCmdGroup,
            /* [annotation][in] */ 
            _In_  DWORD nCmdID,
            /* [annotation][in] */ 
            _In_  DWORD nCmdexecopt,
            /* [annotation][unique][in] */ 
            _In_  VARIANT *pvaIn,
            /* [annotation][unique][out][in] */ 
            _Inout_  VARIANT *pvaOut);
        
        END_INTERFACE
    } IUrlHistoryNotifyVtbl;

    interface IUrlHistoryNotify
    {
        CONST_VTBL struct IUrlHistoryNotifyVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IUrlHistoryNotify_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IUrlHistoryNotify_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IUrlHistoryNotify_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IUrlHistoryNotify_QueryStatus(This,pguidCmdGroup,cCmds,prgCmds,pCmdText)	\
    ( (This)->lpVtbl -> QueryStatus(This,pguidCmdGroup,cCmds,prgCmds,pCmdText) ) 

#define IUrlHistoryNotify_Exec(This,pguidCmdGroup,nCmdID,nCmdexecopt,pvaIn,pvaOut)	\
    ( (This)->lpVtbl -> Exec(This,pguidCmdGroup,nCmdID,nCmdexecopt,pvaIn,pvaOut) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IUrlHistoryNotify_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_urlhist_0000_0004 */
/* [local] */ 

#endif
#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_urlhist_0000_0004_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_urlhist_0000_0004_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


