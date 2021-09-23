

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

#ifndef __perhist_h__
#define __perhist_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IPersistHistory_FWD_DEFINED__
#define __IPersistHistory_FWD_DEFINED__
typedef interface IPersistHistory IPersistHistory;

#endif 	/* __IPersistHistory_FWD_DEFINED__ */


/* header files for imported files */
#include "objidl.h"
#include "oleidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_perhist_0000_0000 */
/* [local] */ 

//=--------------------------------------------------------------------------=
// perhist.h
//=--------------------------------------------------------------------------=
// (C) Copyright 1995-1998 Microsoft Corporation.  All Rights Reserved.
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

//---------------------------------------------------------------------------=
// IPersistHistory Interface.


#ifndef _LPPERSISTHISTORY_DEFINED
#define _LPPERSISTHISTORY_DEFINED


extern RPC_IF_HANDLE __MIDL_itf_perhist_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_perhist_0000_0000_v0_0_s_ifspec;

#ifndef __IPersistHistory_INTERFACE_DEFINED__
#define __IPersistHistory_INTERFACE_DEFINED__

/* interface IPersistHistory */
/* [unique][uuid][object] */ 

typedef /* [unique] */  __RPC_unique_pointer IPersistHistory *LPPERSISTHISTORY;


EXTERN_C const IID IID_IPersistHistory;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("91A565C1-E38F-11d0-94BF-00A0C9055CBF")
    IPersistHistory : public IPersist
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE LoadHistory( 
            /* [annotation][in] */ 
            _In_  IStream *pStream,
            /* [annotation][in] */ 
            _In_  IBindCtx *pbc) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SaveHistory( 
            /* [annotation][in] */ 
            _In_  IStream *pStream) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPositionCookie( 
            /* [annotation][in] */ 
            _In_  DWORD dwPositioncookie) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPositionCookie( 
            /* [annotation][out] */ 
            _Out_  DWORD *pdwPositioncookie) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IPersistHistoryVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IPersistHistory * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IPersistHistory * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IPersistHistory * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetClassID )( 
            __RPC__in IPersistHistory * This,
            /* [annotation][out] */ 
            _Out_  CLSID *pClassID);
        
        HRESULT ( STDMETHODCALLTYPE *LoadHistory )( 
            __RPC__in IPersistHistory * This,
            /* [annotation][in] */ 
            _In_  IStream *pStream,
            /* [annotation][in] */ 
            _In_  IBindCtx *pbc);
        
        HRESULT ( STDMETHODCALLTYPE *SaveHistory )( 
            __RPC__in IPersistHistory * This,
            /* [annotation][in] */ 
            _In_  IStream *pStream);
        
        HRESULT ( STDMETHODCALLTYPE *SetPositionCookie )( 
            __RPC__in IPersistHistory * This,
            /* [annotation][in] */ 
            _In_  DWORD dwPositioncookie);
        
        HRESULT ( STDMETHODCALLTYPE *GetPositionCookie )( 
            __RPC__in IPersistHistory * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwPositioncookie);
        
        END_INTERFACE
    } IPersistHistoryVtbl;

    interface IPersistHistory
    {
        CONST_VTBL struct IPersistHistoryVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPersistHistory_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPersistHistory_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPersistHistory_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPersistHistory_GetClassID(This,pClassID)	\
    ( (This)->lpVtbl -> GetClassID(This,pClassID) ) 


#define IPersistHistory_LoadHistory(This,pStream,pbc)	\
    ( (This)->lpVtbl -> LoadHistory(This,pStream,pbc) ) 

#define IPersistHistory_SaveHistory(This,pStream)	\
    ( (This)->lpVtbl -> SaveHistory(This,pStream) ) 

#define IPersistHistory_SetPositionCookie(This,dwPositioncookie)	\
    ( (This)->lpVtbl -> SetPositionCookie(This,dwPositioncookie) ) 

#define IPersistHistory_GetPositionCookie(This,pdwPositioncookie)	\
    ( (This)->lpVtbl -> GetPositionCookie(This,pdwPositioncookie) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPersistHistory_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_perhist_0000_0001 */
/* [local] */ 

#endif
#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_perhist_0000_0001_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_perhist_0000_0001_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


