

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

#ifndef __htiframe_h__
#define __htiframe_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ITargetNotify_FWD_DEFINED__
#define __ITargetNotify_FWD_DEFINED__
typedef interface ITargetNotify ITargetNotify;

#endif 	/* __ITargetNotify_FWD_DEFINED__ */


#ifndef __ITargetNotify2_FWD_DEFINED__
#define __ITargetNotify2_FWD_DEFINED__
typedef interface ITargetNotify2 ITargetNotify2;

#endif 	/* __ITargetNotify2_FWD_DEFINED__ */


#ifndef __ITargetFrame2_FWD_DEFINED__
#define __ITargetFrame2_FWD_DEFINED__
typedef interface ITargetFrame2 ITargetFrame2;

#endif 	/* __ITargetFrame2_FWD_DEFINED__ */


#ifndef __ITargetContainer_FWD_DEFINED__
#define __ITargetContainer_FWD_DEFINED__
typedef interface ITargetContainer ITargetContainer;

#endif 	/* __ITargetContainer_FWD_DEFINED__ */


/* header files for imported files */
#include "objidl.h"
#include "oleidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_htiframe_0000_0000 */
/* [local] */ 

//=--------------------------------------------------------------------------=
// HTIframe.h
//=--------------------------------------------------------------------------=
// (C) Copyright Microsoft Corporation.  All Rights Reserved.
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//=--------------------------------------------------------------------------=

#include <winapifamily.h>
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
#pragma comment(lib,"uuid.lib")

//--------------------------------------------------------------------------
// OLE Hyperlinking ITargetFrame2 Interfaces.



EXTERN_C const IID IID_ITargetFrame2;
EXTERN_C const IID IID_ITargetContainer;
#ifndef _LPTARGETFRAME2_DEFINED
#define _LPTARGETFRAME2_DEFINED
#define TF_NAVIGATE 0x7FAEABAC
#define TARGET_NOTIFY_OBJECT_NAME L"863a99a0-21bc-11d0-82b4-00a0c90c29c5"


extern RPC_IF_HANDLE __MIDL_itf_htiframe_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_htiframe_0000_0000_v0_0_s_ifspec;

#ifndef __ITargetNotify_INTERFACE_DEFINED__
#define __ITargetNotify_INTERFACE_DEFINED__

/* interface ITargetNotify */
/* [unique][uuid][object] */ 

typedef /* [unique] */  __RPC_unique_pointer ITargetNotify *LPTARGETNOTIFY;


EXTERN_C const IID IID_ITargetNotify;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("863a99a0-21bc-11d0-82b4-00a0c90c29c5")
    ITargetNotify : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnCreate( 
            /* [annotation][in] */ 
            _In_  IUnknown *pUnkDestination,
            /* [annotation][in] */ 
            _In_  ULONG cbCookie) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnReuse( 
            /* [annotation][in] */ 
            _In_  IUnknown *pUnkDestination) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITargetNotifyVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ITargetNotify * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ITargetNotify * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ITargetNotify * This);
        
        HRESULT ( STDMETHODCALLTYPE *OnCreate )( 
            __RPC__in ITargetNotify * This,
            /* [annotation][in] */ 
            _In_  IUnknown *pUnkDestination,
            /* [annotation][in] */ 
            _In_  ULONG cbCookie);
        
        HRESULT ( STDMETHODCALLTYPE *OnReuse )( 
            __RPC__in ITargetNotify * This,
            /* [annotation][in] */ 
            _In_  IUnknown *pUnkDestination);
        
        END_INTERFACE
    } ITargetNotifyVtbl;

    interface ITargetNotify
    {
        CONST_VTBL struct ITargetNotifyVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITargetNotify_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITargetNotify_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITargetNotify_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITargetNotify_OnCreate(This,pUnkDestination,cbCookie)	\
    ( (This)->lpVtbl -> OnCreate(This,pUnkDestination,cbCookie) ) 

#define ITargetNotify_OnReuse(This,pUnkDestination)	\
    ( (This)->lpVtbl -> OnReuse(This,pUnkDestination) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITargetNotify_INTERFACE_DEFINED__ */


#ifndef __ITargetNotify2_INTERFACE_DEFINED__
#define __ITargetNotify2_INTERFACE_DEFINED__

/* interface ITargetNotify2 */
/* [unique][uuid][object] */ 

typedef /* [unique] */  __RPC_unique_pointer ITargetNotify2 *LPTARGETNOTIFY2;


EXTERN_C const IID IID_ITargetNotify2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3050f6b1-98b5-11cf-bb82-00aa00bdce0b")
    ITargetNotify2 : public ITargetNotify
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetOptionString( 
            /* [annotation][out][in] */ 
            _Inout_  BSTR *pbstrOptions) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITargetNotify2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ITargetNotify2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ITargetNotify2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ITargetNotify2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *OnCreate )( 
            __RPC__in ITargetNotify2 * This,
            /* [annotation][in] */ 
            _In_  IUnknown *pUnkDestination,
            /* [annotation][in] */ 
            _In_  ULONG cbCookie);
        
        HRESULT ( STDMETHODCALLTYPE *OnReuse )( 
            __RPC__in ITargetNotify2 * This,
            /* [annotation][in] */ 
            _In_  IUnknown *pUnkDestination);
        
        HRESULT ( STDMETHODCALLTYPE *GetOptionString )( 
            __RPC__in ITargetNotify2 * This,
            /* [annotation][out][in] */ 
            _Inout_  BSTR *pbstrOptions);
        
        END_INTERFACE
    } ITargetNotify2Vtbl;

    interface ITargetNotify2
    {
        CONST_VTBL struct ITargetNotify2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITargetNotify2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITargetNotify2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITargetNotify2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITargetNotify2_OnCreate(This,pUnkDestination,cbCookie)	\
    ( (This)->lpVtbl -> OnCreate(This,pUnkDestination,cbCookie) ) 

#define ITargetNotify2_OnReuse(This,pUnkDestination)	\
    ( (This)->lpVtbl -> OnReuse(This,pUnkDestination) ) 


#define ITargetNotify2_GetOptionString(This,pbstrOptions)	\
    ( (This)->lpVtbl -> GetOptionString(This,pbstrOptions) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITargetNotify2_INTERFACE_DEFINED__ */


#ifndef __ITargetFrame2_INTERFACE_DEFINED__
#define __ITargetFrame2_INTERFACE_DEFINED__

/* interface ITargetFrame2 */
/* [unique][uuid][object] */ 

typedef /* [unique] */  __RPC_unique_pointer ITargetFrame2 *LPTARGETFRAME2;

typedef /* [public] */ 
enum __MIDL_ITargetFrame2_0001
    {
        FINDFRAME_NONE	= 0,
        FINDFRAME_JUSTTESTEXISTENCE	= 1,
        FINDFRAME_INTERNAL	= 0x80000000
    } 	FINDFRAME_FLAGS;

typedef /* [public] */ 
enum __MIDL_ITargetFrame2_0002
    {
        FRAMEOPTIONS_SCROLL_YES	= 0x1,
        FRAMEOPTIONS_SCROLL_NO	= 0x2,
        FRAMEOPTIONS_SCROLL_AUTO	= 0x4,
        FRAMEOPTIONS_NORESIZE	= 0x8,
        FRAMEOPTIONS_NO3DBORDER	= 0x10,
        FRAMEOPTIONS_DESKTOP	= 0x20,
        FRAMEOPTIONS_BROWSERBAND	= 0x40
    } 	FRAMEOPTIONS_FLAGS;


EXTERN_C const IID IID_ITargetFrame2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("86D52E11-94A8-11d0-82AF-00C04FD5AE38")
    ITargetFrame2 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetFrameName( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszFrameName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFrameName( 
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszFrameName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetParentFrame( 
            /* [annotation][out] */ 
            _Out_  IUnknown **ppunkParent) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetFrameSrc( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszFrameSrc) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFrameSrc( 
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszFrameSrc) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFramesContainer( 
            /* [annotation][out] */ 
            _Out_  IOleContainer **ppContainer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetFrameOptions( 
            /* [annotation][in] */ 
            _In_  DWORD dwFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFrameOptions( 
            /* [annotation][out] */ 
            _Out_  DWORD *pdwFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetFrameMargins( 
            /* [annotation][in] */ 
            _In_  DWORD dwWidth,
            /* [annotation][in] */ 
            _In_  DWORD dwHeight) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFrameMargins( 
            /* [annotation][out] */ 
            _Out_  DWORD *pdwWidth,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwHeight) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FindFrame( 
            /* [annotation][unique][in] */ 
            _In_  LPCWSTR pszTargetName,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][out] */ 
            _Out_  IUnknown **ppunkTargetFrame) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTargetAlias( 
            /* [annotation][unique][in] */ 
            _In_  LPCWSTR pszTargetName,
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszTargetAlias) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITargetFrame2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ITargetFrame2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ITargetFrame2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ITargetFrame2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetFrameName )( 
            __RPC__in ITargetFrame2 * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszFrameName);
        
        HRESULT ( STDMETHODCALLTYPE *GetFrameName )( 
            __RPC__in ITargetFrame2 * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszFrameName);
        
        HRESULT ( STDMETHODCALLTYPE *GetParentFrame )( 
            __RPC__in ITargetFrame2 * This,
            /* [annotation][out] */ 
            _Out_  IUnknown **ppunkParent);
        
        HRESULT ( STDMETHODCALLTYPE *SetFrameSrc )( 
            __RPC__in ITargetFrame2 * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszFrameSrc);
        
        HRESULT ( STDMETHODCALLTYPE *GetFrameSrc )( 
            __RPC__in ITargetFrame2 * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszFrameSrc);
        
        HRESULT ( STDMETHODCALLTYPE *GetFramesContainer )( 
            __RPC__in ITargetFrame2 * This,
            /* [annotation][out] */ 
            _Out_  IOleContainer **ppContainer);
        
        HRESULT ( STDMETHODCALLTYPE *SetFrameOptions )( 
            __RPC__in ITargetFrame2 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags);
        
        HRESULT ( STDMETHODCALLTYPE *GetFrameOptions )( 
            __RPC__in ITargetFrame2 * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwFlags);
        
        HRESULT ( STDMETHODCALLTYPE *SetFrameMargins )( 
            __RPC__in ITargetFrame2 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwWidth,
            /* [annotation][in] */ 
            _In_  DWORD dwHeight);
        
        HRESULT ( STDMETHODCALLTYPE *GetFrameMargins )( 
            __RPC__in ITargetFrame2 * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwWidth,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwHeight);
        
        HRESULT ( STDMETHODCALLTYPE *FindFrame )( 
            __RPC__in ITargetFrame2 * This,
            /* [annotation][unique][in] */ 
            _In_  LPCWSTR pszTargetName,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][out] */ 
            _Out_  IUnknown **ppunkTargetFrame);
        
        HRESULT ( STDMETHODCALLTYPE *GetTargetAlias )( 
            __RPC__in ITargetFrame2 * This,
            /* [annotation][unique][in] */ 
            _In_  LPCWSTR pszTargetName,
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszTargetAlias);
        
        END_INTERFACE
    } ITargetFrame2Vtbl;

    interface ITargetFrame2
    {
        CONST_VTBL struct ITargetFrame2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITargetFrame2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITargetFrame2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITargetFrame2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITargetFrame2_SetFrameName(This,pszFrameName)	\
    ( (This)->lpVtbl -> SetFrameName(This,pszFrameName) ) 

#define ITargetFrame2_GetFrameName(This,ppszFrameName)	\
    ( (This)->lpVtbl -> GetFrameName(This,ppszFrameName) ) 

#define ITargetFrame2_GetParentFrame(This,ppunkParent)	\
    ( (This)->lpVtbl -> GetParentFrame(This,ppunkParent) ) 

#define ITargetFrame2_SetFrameSrc(This,pszFrameSrc)	\
    ( (This)->lpVtbl -> SetFrameSrc(This,pszFrameSrc) ) 

#define ITargetFrame2_GetFrameSrc(This,ppszFrameSrc)	\
    ( (This)->lpVtbl -> GetFrameSrc(This,ppszFrameSrc) ) 

#define ITargetFrame2_GetFramesContainer(This,ppContainer)	\
    ( (This)->lpVtbl -> GetFramesContainer(This,ppContainer) ) 

#define ITargetFrame2_SetFrameOptions(This,dwFlags)	\
    ( (This)->lpVtbl -> SetFrameOptions(This,dwFlags) ) 

#define ITargetFrame2_GetFrameOptions(This,pdwFlags)	\
    ( (This)->lpVtbl -> GetFrameOptions(This,pdwFlags) ) 

#define ITargetFrame2_SetFrameMargins(This,dwWidth,dwHeight)	\
    ( (This)->lpVtbl -> SetFrameMargins(This,dwWidth,dwHeight) ) 

#define ITargetFrame2_GetFrameMargins(This,pdwWidth,pdwHeight)	\
    ( (This)->lpVtbl -> GetFrameMargins(This,pdwWidth,pdwHeight) ) 

#define ITargetFrame2_FindFrame(This,pszTargetName,dwFlags,ppunkTargetFrame)	\
    ( (This)->lpVtbl -> FindFrame(This,pszTargetName,dwFlags,ppunkTargetFrame) ) 

#define ITargetFrame2_GetTargetAlias(This,pszTargetName,ppszTargetAlias)	\
    ( (This)->lpVtbl -> GetTargetAlias(This,pszTargetName,ppszTargetAlias) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITargetFrame2_INTERFACE_DEFINED__ */


#ifndef __ITargetContainer_INTERFACE_DEFINED__
#define __ITargetContainer_INTERFACE_DEFINED__

/* interface ITargetContainer */
/* [unique][uuid][object] */ 

typedef /* [unique] */  __RPC_unique_pointer ITargetContainer *LPTARGETCONTAINER;


EXTERN_C const IID IID_ITargetContainer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7847EC01-2BEC-11d0-82B4-00A0C90C29C5")
    ITargetContainer : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetFrameUrl( 
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszFrameSrc) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFramesContainer( 
            /* [annotation][out] */ 
            _Out_  IOleContainer **ppContainer) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITargetContainerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ITargetContainer * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ITargetContainer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ITargetContainer * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetFrameUrl )( 
            __RPC__in ITargetContainer * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszFrameSrc);
        
        HRESULT ( STDMETHODCALLTYPE *GetFramesContainer )( 
            __RPC__in ITargetContainer * This,
            /* [annotation][out] */ 
            _Out_  IOleContainer **ppContainer);
        
        END_INTERFACE
    } ITargetContainerVtbl;

    interface ITargetContainer
    {
        CONST_VTBL struct ITargetContainerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITargetContainer_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITargetContainer_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITargetContainer_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITargetContainer_GetFrameUrl(This,ppszFrameSrc)	\
    ( (This)->lpVtbl -> GetFrameUrl(This,ppszFrameSrc) ) 

#define ITargetContainer_GetFramesContainer(This,ppContainer)	\
    ( (This)->lpVtbl -> GetFramesContainer(This,ppContainer) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITargetContainer_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_htiframe_0000_0004 */
/* [local] */ 

#endif
#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_htiframe_0000_0004_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_htiframe_0000_0004_v0_0_s_ifspec;

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


