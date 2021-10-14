

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

#ifndef __wmsbuffer_h__
#define __wmsbuffer_h__

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

#ifndef __INSSBuffer_FWD_DEFINED__
#define __INSSBuffer_FWD_DEFINED__
typedef interface INSSBuffer INSSBuffer;

#endif 	/* __INSSBuffer_FWD_DEFINED__ */


#ifndef __INSSBuffer2_FWD_DEFINED__
#define __INSSBuffer2_FWD_DEFINED__
typedef interface INSSBuffer2 INSSBuffer2;

#endif 	/* __INSSBuffer2_FWD_DEFINED__ */


#ifndef __INSSBuffer3_FWD_DEFINED__
#define __INSSBuffer3_FWD_DEFINED__
typedef interface INSSBuffer3 INSSBuffer3;

#endif 	/* __INSSBuffer3_FWD_DEFINED__ */


#ifndef __INSSBuffer4_FWD_DEFINED__
#define __INSSBuffer4_FWD_DEFINED__
typedef interface INSSBuffer4 INSSBuffer4;

#endif 	/* __INSSBuffer4_FWD_DEFINED__ */


#ifndef __IWMSBufferAllocator_FWD_DEFINED__
#define __IWMSBufferAllocator_FWD_DEFINED__
typedef interface IWMSBufferAllocator IWMSBufferAllocator;

#endif 	/* __IWMSBufferAllocator_FWD_DEFINED__ */


/* header files for imported files */
#include "objidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_wmsbuffer_0000_0000 */
/* [local] */ 

//=========================================================================
//
// Microsoft Windows Media Technologies
// Copyright (C) Microsoft Corporation.  All Rights Reserved.
//
//=========================================================================
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <winapifamily.h>
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
EXTERN_GUID( IID_INSSBuffer, 0xE1CD3524,0x03D7,0x11d2,0x9E,0xED,0x00,0x60,0x97,0xD2,0xD7,0xCF );
EXTERN_GUID( IID_IWMSBuffer, 0xE1CD3524,0x03D7,0x11d2,0x9E,0xED,0x00,0x60,0x97,0xD2,0xD7,0xCF );
EXTERN_GUID( IID_INSSBuffer2,0x4f528693,0x1035,0x43fe,0xb4,0x28,0x75,0x75,0x61,0xad,0x3a,0x68 );
EXTERN_GUID( IID_INSSBuffer3,0xc87ceaaf,0x75be,0x4bc4,0x84,0xeb,0xac,0x27,0x98,0x50,0x76,0x72 );
EXTERN_GUID( IID_INSSBuffer4,0xb6b8fd5a,0x32e2,0x49d4,0xa9,0x10,0xc2,0x6c,0xc8,0x54,0x65,0xed );
EXTERN_GUID( IID_IWMSBufferAllocator, 0x61103CA4,0x2033,0x11d2,0x9E,0xF1,0x00,0x60,0x97,0xD2,0xD7,0xCF );
#define IWMSBuffer INSSBuffer



extern RPC_IF_HANDLE __MIDL_itf_wmsbuffer_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_wmsbuffer_0000_0000_v0_0_s_ifspec;

#ifndef __INSSBuffer_INTERFACE_DEFINED__
#define __INSSBuffer_INTERFACE_DEFINED__

/* interface INSSBuffer */
/* [version][uuid][unique][object][local] */ 


EXTERN_C const IID IID_INSSBuffer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E1CD3524-03D7-11d2-9EED-006097D2D7CF")
    INSSBuffer : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetLength( 
            /* [annotation][out] */ 
            _Out_  DWORD *pdwLength) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetLength( 
            /* [annotation][in] */ 
            _In_  DWORD dwLength) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMaxLength( 
            /* [annotation][out] */ 
            _Out_  DWORD *pdwLength) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBuffer( 
            /* [annotation][out] */ 
            _Out_  BYTE **ppdwBuffer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBufferAndLength( 
            /* [annotation][out] */ 
            _Out_  BYTE **ppdwBuffer,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwLength) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct INSSBufferVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            INSSBuffer * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            INSSBuffer * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            INSSBuffer * This);
        
        DECLSPEC_XFGVIRT(INSSBuffer, GetLength)
        HRESULT ( STDMETHODCALLTYPE *GetLength )( 
            INSSBuffer * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwLength);
        
        DECLSPEC_XFGVIRT(INSSBuffer, SetLength)
        HRESULT ( STDMETHODCALLTYPE *SetLength )( 
            INSSBuffer * This,
            /* [annotation][in] */ 
            _In_  DWORD dwLength);
        
        DECLSPEC_XFGVIRT(INSSBuffer, GetMaxLength)
        HRESULT ( STDMETHODCALLTYPE *GetMaxLength )( 
            INSSBuffer * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwLength);
        
        DECLSPEC_XFGVIRT(INSSBuffer, GetBuffer)
        HRESULT ( STDMETHODCALLTYPE *GetBuffer )( 
            INSSBuffer * This,
            /* [annotation][out] */ 
            _Out_  BYTE **ppdwBuffer);
        
        DECLSPEC_XFGVIRT(INSSBuffer, GetBufferAndLength)
        HRESULT ( STDMETHODCALLTYPE *GetBufferAndLength )( 
            INSSBuffer * This,
            /* [annotation][out] */ 
            _Out_  BYTE **ppdwBuffer,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwLength);
        
        END_INTERFACE
    } INSSBufferVtbl;

    interface INSSBuffer
    {
        CONST_VTBL struct INSSBufferVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INSSBuffer_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define INSSBuffer_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define INSSBuffer_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define INSSBuffer_GetLength(This,pdwLength)	\
    ( (This)->lpVtbl -> GetLength(This,pdwLength) ) 

#define INSSBuffer_SetLength(This,dwLength)	\
    ( (This)->lpVtbl -> SetLength(This,dwLength) ) 

#define INSSBuffer_GetMaxLength(This,pdwLength)	\
    ( (This)->lpVtbl -> GetMaxLength(This,pdwLength) ) 

#define INSSBuffer_GetBuffer(This,ppdwBuffer)	\
    ( (This)->lpVtbl -> GetBuffer(This,ppdwBuffer) ) 

#define INSSBuffer_GetBufferAndLength(This,ppdwBuffer,pdwLength)	\
    ( (This)->lpVtbl -> GetBufferAndLength(This,ppdwBuffer,pdwLength) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __INSSBuffer_INTERFACE_DEFINED__ */


#ifndef __INSSBuffer2_INTERFACE_DEFINED__
#define __INSSBuffer2_INTERFACE_DEFINED__

/* interface INSSBuffer2 */
/* [version][uuid][unique][object][local] */ 


EXTERN_C const IID IID_INSSBuffer2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4F528693-1035-43fe-B428-757561AD3A68")
    INSSBuffer2 : public INSSBuffer
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetSampleProperties( 
            /* [annotation][in] */ 
            _In_  DWORD cbProperties,
            /* [annotation][out] */ 
            _Out_  BYTE *pbProperties) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetSampleProperties( 
            /* [annotation][in] */ 
            _In_  DWORD cbProperties,
            /* [annotation][in] */ 
            _In_  BYTE *pbProperties) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct INSSBuffer2Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            INSSBuffer2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            INSSBuffer2 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            INSSBuffer2 * This);
        
        DECLSPEC_XFGVIRT(INSSBuffer, GetLength)
        HRESULT ( STDMETHODCALLTYPE *GetLength )( 
            INSSBuffer2 * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwLength);
        
        DECLSPEC_XFGVIRT(INSSBuffer, SetLength)
        HRESULT ( STDMETHODCALLTYPE *SetLength )( 
            INSSBuffer2 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwLength);
        
        DECLSPEC_XFGVIRT(INSSBuffer, GetMaxLength)
        HRESULT ( STDMETHODCALLTYPE *GetMaxLength )( 
            INSSBuffer2 * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwLength);
        
        DECLSPEC_XFGVIRT(INSSBuffer, GetBuffer)
        HRESULT ( STDMETHODCALLTYPE *GetBuffer )( 
            INSSBuffer2 * This,
            /* [annotation][out] */ 
            _Out_  BYTE **ppdwBuffer);
        
        DECLSPEC_XFGVIRT(INSSBuffer, GetBufferAndLength)
        HRESULT ( STDMETHODCALLTYPE *GetBufferAndLength )( 
            INSSBuffer2 * This,
            /* [annotation][out] */ 
            _Out_  BYTE **ppdwBuffer,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwLength);
        
        DECLSPEC_XFGVIRT(INSSBuffer2, GetSampleProperties)
        HRESULT ( STDMETHODCALLTYPE *GetSampleProperties )( 
            INSSBuffer2 * This,
            /* [annotation][in] */ 
            _In_  DWORD cbProperties,
            /* [annotation][out] */ 
            _Out_  BYTE *pbProperties);
        
        DECLSPEC_XFGVIRT(INSSBuffer2, SetSampleProperties)
        HRESULT ( STDMETHODCALLTYPE *SetSampleProperties )( 
            INSSBuffer2 * This,
            /* [annotation][in] */ 
            _In_  DWORD cbProperties,
            /* [annotation][in] */ 
            _In_  BYTE *pbProperties);
        
        END_INTERFACE
    } INSSBuffer2Vtbl;

    interface INSSBuffer2
    {
        CONST_VTBL struct INSSBuffer2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INSSBuffer2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define INSSBuffer2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define INSSBuffer2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define INSSBuffer2_GetLength(This,pdwLength)	\
    ( (This)->lpVtbl -> GetLength(This,pdwLength) ) 

#define INSSBuffer2_SetLength(This,dwLength)	\
    ( (This)->lpVtbl -> SetLength(This,dwLength) ) 

#define INSSBuffer2_GetMaxLength(This,pdwLength)	\
    ( (This)->lpVtbl -> GetMaxLength(This,pdwLength) ) 

#define INSSBuffer2_GetBuffer(This,ppdwBuffer)	\
    ( (This)->lpVtbl -> GetBuffer(This,ppdwBuffer) ) 

#define INSSBuffer2_GetBufferAndLength(This,ppdwBuffer,pdwLength)	\
    ( (This)->lpVtbl -> GetBufferAndLength(This,ppdwBuffer,pdwLength) ) 


#define INSSBuffer2_GetSampleProperties(This,cbProperties,pbProperties)	\
    ( (This)->lpVtbl -> GetSampleProperties(This,cbProperties,pbProperties) ) 

#define INSSBuffer2_SetSampleProperties(This,cbProperties,pbProperties)	\
    ( (This)->lpVtbl -> SetSampleProperties(This,cbProperties,pbProperties) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __INSSBuffer2_INTERFACE_DEFINED__ */


#ifndef __INSSBuffer3_INTERFACE_DEFINED__
#define __INSSBuffer3_INTERFACE_DEFINED__

/* interface INSSBuffer3 */
/* [version][uuid][unique][object][local] */ 


EXTERN_C const IID IID_INSSBuffer3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C87CEAAF-75BE-4bc4-84EB-AC2798507672")
    INSSBuffer3 : public INSSBuffer2
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetProperty( 
            /* [annotation][in] */ 
            _In_  GUID guidBufferProperty,
            /* [annotation][in] */ 
            _In_  void *pvBufferProperty,
            /* [annotation][in] */ 
            _In_  DWORD dwBufferPropertySize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetProperty( 
            /* [annotation][in] */ 
            _In_  GUID guidBufferProperty,
            /* [annotation][out] */ 
            _Out_  void *pvBufferProperty,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pdwBufferPropertySize) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct INSSBuffer3Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            INSSBuffer3 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            INSSBuffer3 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            INSSBuffer3 * This);
        
        DECLSPEC_XFGVIRT(INSSBuffer, GetLength)
        HRESULT ( STDMETHODCALLTYPE *GetLength )( 
            INSSBuffer3 * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwLength);
        
        DECLSPEC_XFGVIRT(INSSBuffer, SetLength)
        HRESULT ( STDMETHODCALLTYPE *SetLength )( 
            INSSBuffer3 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwLength);
        
        DECLSPEC_XFGVIRT(INSSBuffer, GetMaxLength)
        HRESULT ( STDMETHODCALLTYPE *GetMaxLength )( 
            INSSBuffer3 * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwLength);
        
        DECLSPEC_XFGVIRT(INSSBuffer, GetBuffer)
        HRESULT ( STDMETHODCALLTYPE *GetBuffer )( 
            INSSBuffer3 * This,
            /* [annotation][out] */ 
            _Out_  BYTE **ppdwBuffer);
        
        DECLSPEC_XFGVIRT(INSSBuffer, GetBufferAndLength)
        HRESULT ( STDMETHODCALLTYPE *GetBufferAndLength )( 
            INSSBuffer3 * This,
            /* [annotation][out] */ 
            _Out_  BYTE **ppdwBuffer,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwLength);
        
        DECLSPEC_XFGVIRT(INSSBuffer2, GetSampleProperties)
        HRESULT ( STDMETHODCALLTYPE *GetSampleProperties )( 
            INSSBuffer3 * This,
            /* [annotation][in] */ 
            _In_  DWORD cbProperties,
            /* [annotation][out] */ 
            _Out_  BYTE *pbProperties);
        
        DECLSPEC_XFGVIRT(INSSBuffer2, SetSampleProperties)
        HRESULT ( STDMETHODCALLTYPE *SetSampleProperties )( 
            INSSBuffer3 * This,
            /* [annotation][in] */ 
            _In_  DWORD cbProperties,
            /* [annotation][in] */ 
            _In_  BYTE *pbProperties);
        
        DECLSPEC_XFGVIRT(INSSBuffer3, SetProperty)
        HRESULT ( STDMETHODCALLTYPE *SetProperty )( 
            INSSBuffer3 * This,
            /* [annotation][in] */ 
            _In_  GUID guidBufferProperty,
            /* [annotation][in] */ 
            _In_  void *pvBufferProperty,
            /* [annotation][in] */ 
            _In_  DWORD dwBufferPropertySize);
        
        DECLSPEC_XFGVIRT(INSSBuffer3, GetProperty)
        HRESULT ( STDMETHODCALLTYPE *GetProperty )( 
            INSSBuffer3 * This,
            /* [annotation][in] */ 
            _In_  GUID guidBufferProperty,
            /* [annotation][out] */ 
            _Out_  void *pvBufferProperty,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pdwBufferPropertySize);
        
        END_INTERFACE
    } INSSBuffer3Vtbl;

    interface INSSBuffer3
    {
        CONST_VTBL struct INSSBuffer3Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INSSBuffer3_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define INSSBuffer3_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define INSSBuffer3_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define INSSBuffer3_GetLength(This,pdwLength)	\
    ( (This)->lpVtbl -> GetLength(This,pdwLength) ) 

#define INSSBuffer3_SetLength(This,dwLength)	\
    ( (This)->lpVtbl -> SetLength(This,dwLength) ) 

#define INSSBuffer3_GetMaxLength(This,pdwLength)	\
    ( (This)->lpVtbl -> GetMaxLength(This,pdwLength) ) 

#define INSSBuffer3_GetBuffer(This,ppdwBuffer)	\
    ( (This)->lpVtbl -> GetBuffer(This,ppdwBuffer) ) 

#define INSSBuffer3_GetBufferAndLength(This,ppdwBuffer,pdwLength)	\
    ( (This)->lpVtbl -> GetBufferAndLength(This,ppdwBuffer,pdwLength) ) 


#define INSSBuffer3_GetSampleProperties(This,cbProperties,pbProperties)	\
    ( (This)->lpVtbl -> GetSampleProperties(This,cbProperties,pbProperties) ) 

#define INSSBuffer3_SetSampleProperties(This,cbProperties,pbProperties)	\
    ( (This)->lpVtbl -> SetSampleProperties(This,cbProperties,pbProperties) ) 


#define INSSBuffer3_SetProperty(This,guidBufferProperty,pvBufferProperty,dwBufferPropertySize)	\
    ( (This)->lpVtbl -> SetProperty(This,guidBufferProperty,pvBufferProperty,dwBufferPropertySize) ) 

#define INSSBuffer3_GetProperty(This,guidBufferProperty,pvBufferProperty,pdwBufferPropertySize)	\
    ( (This)->lpVtbl -> GetProperty(This,guidBufferProperty,pvBufferProperty,pdwBufferPropertySize) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __INSSBuffer3_INTERFACE_DEFINED__ */


#ifndef __INSSBuffer4_INTERFACE_DEFINED__
#define __INSSBuffer4_INTERFACE_DEFINED__

/* interface INSSBuffer4 */
/* [version][uuid][unique][object][local] */ 


EXTERN_C const IID IID_INSSBuffer4;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B6B8FD5A-32E2-49d4-A910-C26CC85465ED")
    INSSBuffer4 : public INSSBuffer3
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetPropertyCount( 
            /* [annotation][out] */ 
            _Out_  DWORD *pcBufferProperties) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPropertyByIndex( 
            /* [annotation][in] */ 
            _In_  DWORD dwBufferPropertyIndex,
            /* [annotation][out] */ 
            _Out_  GUID *pguidBufferProperty,
            /* [annotation][out] */ 
            _Out_  void *pvBufferProperty,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pdwBufferPropertySize) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct INSSBuffer4Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            INSSBuffer4 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            INSSBuffer4 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            INSSBuffer4 * This);
        
        DECLSPEC_XFGVIRT(INSSBuffer, GetLength)
        HRESULT ( STDMETHODCALLTYPE *GetLength )( 
            INSSBuffer4 * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwLength);
        
        DECLSPEC_XFGVIRT(INSSBuffer, SetLength)
        HRESULT ( STDMETHODCALLTYPE *SetLength )( 
            INSSBuffer4 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwLength);
        
        DECLSPEC_XFGVIRT(INSSBuffer, GetMaxLength)
        HRESULT ( STDMETHODCALLTYPE *GetMaxLength )( 
            INSSBuffer4 * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwLength);
        
        DECLSPEC_XFGVIRT(INSSBuffer, GetBuffer)
        HRESULT ( STDMETHODCALLTYPE *GetBuffer )( 
            INSSBuffer4 * This,
            /* [annotation][out] */ 
            _Out_  BYTE **ppdwBuffer);
        
        DECLSPEC_XFGVIRT(INSSBuffer, GetBufferAndLength)
        HRESULT ( STDMETHODCALLTYPE *GetBufferAndLength )( 
            INSSBuffer4 * This,
            /* [annotation][out] */ 
            _Out_  BYTE **ppdwBuffer,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwLength);
        
        DECLSPEC_XFGVIRT(INSSBuffer2, GetSampleProperties)
        HRESULT ( STDMETHODCALLTYPE *GetSampleProperties )( 
            INSSBuffer4 * This,
            /* [annotation][in] */ 
            _In_  DWORD cbProperties,
            /* [annotation][out] */ 
            _Out_  BYTE *pbProperties);
        
        DECLSPEC_XFGVIRT(INSSBuffer2, SetSampleProperties)
        HRESULT ( STDMETHODCALLTYPE *SetSampleProperties )( 
            INSSBuffer4 * This,
            /* [annotation][in] */ 
            _In_  DWORD cbProperties,
            /* [annotation][in] */ 
            _In_  BYTE *pbProperties);
        
        DECLSPEC_XFGVIRT(INSSBuffer3, SetProperty)
        HRESULT ( STDMETHODCALLTYPE *SetProperty )( 
            INSSBuffer4 * This,
            /* [annotation][in] */ 
            _In_  GUID guidBufferProperty,
            /* [annotation][in] */ 
            _In_  void *pvBufferProperty,
            /* [annotation][in] */ 
            _In_  DWORD dwBufferPropertySize);
        
        DECLSPEC_XFGVIRT(INSSBuffer3, GetProperty)
        HRESULT ( STDMETHODCALLTYPE *GetProperty )( 
            INSSBuffer4 * This,
            /* [annotation][in] */ 
            _In_  GUID guidBufferProperty,
            /* [annotation][out] */ 
            _Out_  void *pvBufferProperty,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pdwBufferPropertySize);
        
        DECLSPEC_XFGVIRT(INSSBuffer4, GetPropertyCount)
        HRESULT ( STDMETHODCALLTYPE *GetPropertyCount )( 
            INSSBuffer4 * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pcBufferProperties);
        
        DECLSPEC_XFGVIRT(INSSBuffer4, GetPropertyByIndex)
        HRESULT ( STDMETHODCALLTYPE *GetPropertyByIndex )( 
            INSSBuffer4 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwBufferPropertyIndex,
            /* [annotation][out] */ 
            _Out_  GUID *pguidBufferProperty,
            /* [annotation][out] */ 
            _Out_  void *pvBufferProperty,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pdwBufferPropertySize);
        
        END_INTERFACE
    } INSSBuffer4Vtbl;

    interface INSSBuffer4
    {
        CONST_VTBL struct INSSBuffer4Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INSSBuffer4_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define INSSBuffer4_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define INSSBuffer4_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define INSSBuffer4_GetLength(This,pdwLength)	\
    ( (This)->lpVtbl -> GetLength(This,pdwLength) ) 

#define INSSBuffer4_SetLength(This,dwLength)	\
    ( (This)->lpVtbl -> SetLength(This,dwLength) ) 

#define INSSBuffer4_GetMaxLength(This,pdwLength)	\
    ( (This)->lpVtbl -> GetMaxLength(This,pdwLength) ) 

#define INSSBuffer4_GetBuffer(This,ppdwBuffer)	\
    ( (This)->lpVtbl -> GetBuffer(This,ppdwBuffer) ) 

#define INSSBuffer4_GetBufferAndLength(This,ppdwBuffer,pdwLength)	\
    ( (This)->lpVtbl -> GetBufferAndLength(This,ppdwBuffer,pdwLength) ) 


#define INSSBuffer4_GetSampleProperties(This,cbProperties,pbProperties)	\
    ( (This)->lpVtbl -> GetSampleProperties(This,cbProperties,pbProperties) ) 

#define INSSBuffer4_SetSampleProperties(This,cbProperties,pbProperties)	\
    ( (This)->lpVtbl -> SetSampleProperties(This,cbProperties,pbProperties) ) 


#define INSSBuffer4_SetProperty(This,guidBufferProperty,pvBufferProperty,dwBufferPropertySize)	\
    ( (This)->lpVtbl -> SetProperty(This,guidBufferProperty,pvBufferProperty,dwBufferPropertySize) ) 

#define INSSBuffer4_GetProperty(This,guidBufferProperty,pvBufferProperty,pdwBufferPropertySize)	\
    ( (This)->lpVtbl -> GetProperty(This,guidBufferProperty,pvBufferProperty,pdwBufferPropertySize) ) 


#define INSSBuffer4_GetPropertyCount(This,pcBufferProperties)	\
    ( (This)->lpVtbl -> GetPropertyCount(This,pcBufferProperties) ) 

#define INSSBuffer4_GetPropertyByIndex(This,dwBufferPropertyIndex,pguidBufferProperty,pvBufferProperty,pdwBufferPropertySize)	\
    ( (This)->lpVtbl -> GetPropertyByIndex(This,dwBufferPropertyIndex,pguidBufferProperty,pvBufferProperty,pdwBufferPropertySize) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __INSSBuffer4_INTERFACE_DEFINED__ */


#ifndef __IWMSBufferAllocator_INTERFACE_DEFINED__
#define __IWMSBufferAllocator_INTERFACE_DEFINED__

/* interface IWMSBufferAllocator */
/* [version][uuid][unique][object][local] */ 


EXTERN_C const IID IID_IWMSBufferAllocator;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("61103CA4-2033-11d2-9EF1-006097D2D7CF")
    IWMSBufferAllocator : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AllocateBuffer( 
            /* [annotation][in] */ 
            _In_  DWORD dwMaxBufferSize,
            /* [annotation][out] */ 
            _Out_  INSSBuffer **ppBuffer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AllocatePageSizeBuffer( 
            /* [annotation][in] */ 
            _In_  DWORD dwMaxBufferSize,
            /* [annotation][out] */ 
            _Out_  INSSBuffer **ppBuffer) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMSBufferAllocatorVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMSBufferAllocator * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMSBufferAllocator * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMSBufferAllocator * This);
        
        DECLSPEC_XFGVIRT(IWMSBufferAllocator, AllocateBuffer)
        HRESULT ( STDMETHODCALLTYPE *AllocateBuffer )( 
            IWMSBufferAllocator * This,
            /* [annotation][in] */ 
            _In_  DWORD dwMaxBufferSize,
            /* [annotation][out] */ 
            _Out_  INSSBuffer **ppBuffer);
        
        DECLSPEC_XFGVIRT(IWMSBufferAllocator, AllocatePageSizeBuffer)
        HRESULT ( STDMETHODCALLTYPE *AllocatePageSizeBuffer )( 
            IWMSBufferAllocator * This,
            /* [annotation][in] */ 
            _In_  DWORD dwMaxBufferSize,
            /* [annotation][out] */ 
            _Out_  INSSBuffer **ppBuffer);
        
        END_INTERFACE
    } IWMSBufferAllocatorVtbl;

    interface IWMSBufferAllocator
    {
        CONST_VTBL struct IWMSBufferAllocatorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMSBufferAllocator_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMSBufferAllocator_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMSBufferAllocator_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMSBufferAllocator_AllocateBuffer(This,dwMaxBufferSize,ppBuffer)	\
    ( (This)->lpVtbl -> AllocateBuffer(This,dwMaxBufferSize,ppBuffer) ) 

#define IWMSBufferAllocator_AllocatePageSizeBuffer(This,dwMaxBufferSize,ppBuffer)	\
    ( (This)->lpVtbl -> AllocatePageSizeBuffer(This,dwMaxBufferSize,ppBuffer) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMSBufferAllocator_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_wmsbuffer_0000_0005 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_wmsbuffer_0000_0005_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_wmsbuffer_0000_0005_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


