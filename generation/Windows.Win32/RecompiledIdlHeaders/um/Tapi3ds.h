

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

#ifndef __tapi3ds_h__
#define __tapi3ds_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ITAMMediaFormat_FWD_DEFINED__
#define __ITAMMediaFormat_FWD_DEFINED__
typedef interface ITAMMediaFormat ITAMMediaFormat;

#endif 	/* __ITAMMediaFormat_FWD_DEFINED__ */


#ifndef __ITAllocatorProperties_FWD_DEFINED__
#define __ITAllocatorProperties_FWD_DEFINED__
typedef interface ITAllocatorProperties ITAllocatorProperties;

#endif 	/* __ITAllocatorProperties_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "strmif.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_tapi3ds_0000_0000 */
/* [local] */ 

/* Copyright (c) Microsoft Corporation. All rights reserved. */
#include <winapifamily.h>
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)


extern RPC_IF_HANDLE __MIDL_itf_tapi3ds_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_tapi3ds_0000_0000_v0_0_s_ifspec;

#ifndef __ITAMMediaFormat_INTERFACE_DEFINED__
#define __ITAMMediaFormat_INTERFACE_DEFINED__

/* interface ITAMMediaFormat */
/* [object][helpstring][uuid] */ 


EXTERN_C const IID IID_ITAMMediaFormat;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0364EB00-4A77-11D1-A671-006097C9A2E8")
    ITAMMediaFormat : public IUnknown
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MediaFormat( 
            /* [annotation][retval][out] */ 
            _Out_retval_  AM_MEDIA_TYPE **ppmt) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MediaFormat( 
            /* [annotation][in] */ 
            _In_  const AM_MEDIA_TYPE *pmt) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITAMMediaFormatVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ITAMMediaFormat * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ITAMMediaFormat * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ITAMMediaFormat * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MediaFormat )( 
            __RPC__in ITAMMediaFormat * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  AM_MEDIA_TYPE **ppmt);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MediaFormat )( 
            __RPC__in ITAMMediaFormat * This,
            /* [annotation][in] */ 
            _In_  const AM_MEDIA_TYPE *pmt);
        
        END_INTERFACE
    } ITAMMediaFormatVtbl;

    interface ITAMMediaFormat
    {
        CONST_VTBL struct ITAMMediaFormatVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITAMMediaFormat_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITAMMediaFormat_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITAMMediaFormat_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITAMMediaFormat_get_MediaFormat(This,ppmt)	\
    ( (This)->lpVtbl -> get_MediaFormat(This,ppmt) ) 

#define ITAMMediaFormat_put_MediaFormat(This,pmt)	\
    ( (This)->lpVtbl -> put_MediaFormat(This,pmt) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITAMMediaFormat_INTERFACE_DEFINED__ */


#ifndef __ITAllocatorProperties_INTERFACE_DEFINED__
#define __ITAllocatorProperties_INTERFACE_DEFINED__

/* interface ITAllocatorProperties */
/* [object][helpstring][uuid] */ 


EXTERN_C const IID IID_ITAllocatorProperties;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C1BC3C90-BCFE-11D1-9745-00C04FD91AC0")
    ITAllocatorProperties : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetAllocatorProperties( 
            /* [annotation][in] */ 
            _In_  ALLOCATOR_PROPERTIES *pAllocProperties) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetAllocatorProperties( 
            /* [annotation][out] */ 
            _Out_  ALLOCATOR_PROPERTIES *pAllocProperties) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetAllocateBuffers( 
            /* [annotation][in] */ 
            _In_  BOOL bAllocBuffers) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetAllocateBuffers( 
            /* [annotation][out] */ 
            _Out_  BOOL *pbAllocBuffers) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetBufferSize( 
            /* [annotation][in] */ 
            _In_  DWORD BufferSize) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetBufferSize( 
            /* [annotation][out] */ 
            _Out_  DWORD *pBufferSize) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITAllocatorPropertiesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ITAllocatorProperties * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ITAllocatorProperties * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ITAllocatorProperties * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetAllocatorProperties )( 
            __RPC__in ITAllocatorProperties * This,
            /* [annotation][in] */ 
            _In_  ALLOCATOR_PROPERTIES *pAllocProperties);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetAllocatorProperties )( 
            __RPC__in ITAllocatorProperties * This,
            /* [annotation][out] */ 
            _Out_  ALLOCATOR_PROPERTIES *pAllocProperties);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetAllocateBuffers )( 
            __RPC__in ITAllocatorProperties * This,
            /* [annotation][in] */ 
            _In_  BOOL bAllocBuffers);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetAllocateBuffers )( 
            __RPC__in ITAllocatorProperties * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pbAllocBuffers);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetBufferSize )( 
            __RPC__in ITAllocatorProperties * This,
            /* [annotation][in] */ 
            _In_  DWORD BufferSize);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetBufferSize )( 
            __RPC__in ITAllocatorProperties * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pBufferSize);
        
        END_INTERFACE
    } ITAllocatorPropertiesVtbl;

    interface ITAllocatorProperties
    {
        CONST_VTBL struct ITAllocatorPropertiesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITAllocatorProperties_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITAllocatorProperties_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITAllocatorProperties_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITAllocatorProperties_SetAllocatorProperties(This,pAllocProperties)	\
    ( (This)->lpVtbl -> SetAllocatorProperties(This,pAllocProperties) ) 

#define ITAllocatorProperties_GetAllocatorProperties(This,pAllocProperties)	\
    ( (This)->lpVtbl -> GetAllocatorProperties(This,pAllocProperties) ) 

#define ITAllocatorProperties_SetAllocateBuffers(This,bAllocBuffers)	\
    ( (This)->lpVtbl -> SetAllocateBuffers(This,bAllocBuffers) ) 

#define ITAllocatorProperties_GetAllocateBuffers(This,pbAllocBuffers)	\
    ( (This)->lpVtbl -> GetAllocateBuffers(This,pbAllocBuffers) ) 

#define ITAllocatorProperties_SetBufferSize(This,BufferSize)	\
    ( (This)->lpVtbl -> SetBufferSize(This,BufferSize) ) 

#define ITAllocatorProperties_GetBufferSize(This,pBufferSize)	\
    ( (This)->lpVtbl -> GetBufferSize(This,pBufferSize) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITAllocatorProperties_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_tapi3ds_0000_0002 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_tapi3ds_0000_0002_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_tapi3ds_0000_0002_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


