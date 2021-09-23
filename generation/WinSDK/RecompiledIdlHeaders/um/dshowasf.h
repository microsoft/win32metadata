

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

#ifndef __dshowasf_h__
#define __dshowasf_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IAMWMBufferPass_FWD_DEFINED__
#define __IAMWMBufferPass_FWD_DEFINED__
typedef interface IAMWMBufferPass IAMWMBufferPass;

#endif 	/* __IAMWMBufferPass_FWD_DEFINED__ */


#ifndef __IAMWMBufferPassCallback_FWD_DEFINED__
#define __IAMWMBufferPassCallback_FWD_DEFINED__
typedef interface IAMWMBufferPassCallback IAMWMBufferPassCallback;

#endif 	/* __IAMWMBufferPassCallback_FWD_DEFINED__ */


#ifndef __IConfigAsfWriter_FWD_DEFINED__
#define __IConfigAsfWriter_FWD_DEFINED__
typedef interface IConfigAsfWriter IConfigAsfWriter;

#endif 	/* __IConfigAsfWriter_FWD_DEFINED__ */


#ifndef __IConfigAsfWriter2_FWD_DEFINED__
#define __IConfigAsfWriter2_FWD_DEFINED__
typedef interface IConfigAsfWriter2 IConfigAsfWriter2;

#endif 	/* __IConfigAsfWriter2_FWD_DEFINED__ */


/* header files for imported files */
#include "unknwn.h"
#include "objidl.h"
#include "strmif.h"
#include "wmsdkidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_dshowasf_0000_0000 */
/* [local] */ 

//=========================================================================
//
// Microsoft Windows Media Technologies
// Copyright (C) Microsoft Corporation.  All Rights Reserved.
//
//=========================================================================
#include <winapifamily.h>
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
EXTERN_GUID( IID_IConfigAsfWriter2,0x7989ccaa, 0x53f0, 0x44f0, 0x88, 0x4a, 0xf3, 0xb0, 0x3f, 0x6a, 0xe0, 0x66 );
EXTERN_GUID( IID_IConfigAsfWriter,0x45086030,0xF7E4,0x486a,0xB5,0x04,0x82,0x6B,0xB5,0x79,0x2A,0x3B );
EXTERN_GUID( IID_IAMWMBufferPass,0x6dd816d7, 0xe740, 0x4123, 0x9e, 0x24, 0x24, 0x44, 0x41, 0x26, 0x44, 0xd8 );
EXTERN_GUID( IID_IAMWMBufferPassCallback,0xb25b8372, 0xd2d2, 0x44b2, 0x86, 0x53, 0x1b, 0x8d, 0xae, 0x33, 0x24, 0x89 );
#ifndef EC_PREPROCESS_COMPLETE
#define EC_PREPROCESS_COMPLETE 0x56
#endif








extern RPC_IF_HANDLE __MIDL_itf_dshowasf_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_dshowasf_0000_0000_v0_0_s_ifspec;

#ifndef __IAMWMBufferPass_INTERFACE_DEFINED__
#define __IAMWMBufferPass_INTERFACE_DEFINED__

/* interface IAMWMBufferPass */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IAMWMBufferPass;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6DD816D7-E740-4123-9E24-2444412644D8")
    IAMWMBufferPass : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetNotify( 
            /* [annotation][in] */ 
            _In_  IAMWMBufferPassCallback *pCallback) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAMWMBufferPassVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IAMWMBufferPass * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IAMWMBufferPass * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IAMWMBufferPass * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetNotify )( 
            __RPC__in IAMWMBufferPass * This,
            /* [annotation][in] */ 
            _In_  IAMWMBufferPassCallback *pCallback);
        
        END_INTERFACE
    } IAMWMBufferPassVtbl;

    interface IAMWMBufferPass
    {
        CONST_VTBL struct IAMWMBufferPassVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAMWMBufferPass_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAMWMBufferPass_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAMWMBufferPass_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAMWMBufferPass_SetNotify(This,pCallback)	\
    ( (This)->lpVtbl -> SetNotify(This,pCallback) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAMWMBufferPass_INTERFACE_DEFINED__ */


#ifndef __IAMWMBufferPassCallback_INTERFACE_DEFINED__
#define __IAMWMBufferPassCallback_INTERFACE_DEFINED__

/* interface IAMWMBufferPassCallback */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IAMWMBufferPassCallback;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B25B8372-D2D2-44b2-8653-1B8DAE332489")
    IAMWMBufferPassCallback : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Notify( 
            /* [annotation][in] */ 
            _In_  INSSBuffer3 *pNSSBuffer3,
            /* [annotation][in] */ 
            _In_  IPin *pPin,
            /* [annotation][in] */ 
            _In_  REFERENCE_TIME *prtStart,
            /* [annotation][in] */ 
            _In_  REFERENCE_TIME *prtEnd) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAMWMBufferPassCallbackVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IAMWMBufferPassCallback * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IAMWMBufferPassCallback * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IAMWMBufferPassCallback * This);
        
        HRESULT ( STDMETHODCALLTYPE *Notify )( 
            __RPC__in IAMWMBufferPassCallback * This,
            /* [annotation][in] */ 
            _In_  INSSBuffer3 *pNSSBuffer3,
            /* [annotation][in] */ 
            _In_  IPin *pPin,
            /* [annotation][in] */ 
            _In_  REFERENCE_TIME *prtStart,
            /* [annotation][in] */ 
            _In_  REFERENCE_TIME *prtEnd);
        
        END_INTERFACE
    } IAMWMBufferPassCallbackVtbl;

    interface IAMWMBufferPassCallback
    {
        CONST_VTBL struct IAMWMBufferPassCallbackVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAMWMBufferPassCallback_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAMWMBufferPassCallback_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAMWMBufferPassCallback_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAMWMBufferPassCallback_Notify(This,pNSSBuffer3,pPin,prtStart,prtEnd)	\
    ( (This)->lpVtbl -> Notify(This,pNSSBuffer3,pPin,prtStart,prtEnd) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAMWMBufferPassCallback_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_dshowasf_0000_0002 */
/* [local] */ 


enum _AM_ASFWRITERCONFIG_PARAM
    {
        AM_CONFIGASFWRITER_PARAM_AUTOINDEX	= 1,
        AM_CONFIGASFWRITER_PARAM_MULTIPASS	= ( AM_CONFIGASFWRITER_PARAM_AUTOINDEX + 1 ) ,
        AM_CONFIGASFWRITER_PARAM_DONTCOMPRESS	= ( AM_CONFIGASFWRITER_PARAM_MULTIPASS + 1 ) 
    } ;


extern RPC_IF_HANDLE __MIDL_itf_dshowasf_0000_0002_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_dshowasf_0000_0002_v0_0_s_ifspec;

#ifndef __IConfigAsfWriter_INTERFACE_DEFINED__
#define __IConfigAsfWriter_INTERFACE_DEFINED__

/* interface IConfigAsfWriter */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IConfigAsfWriter;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("45086030-F7E4-486a-B504-826BB5792A3B")
    IConfigAsfWriter : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ConfigureFilterUsingProfileId( 
            /* [annotation][in] */ 
            _In_  DWORD dwProfileId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCurrentProfileId( 
            /* [annotation][out] */ 
            _Out_  DWORD *pdwProfileId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ConfigureFilterUsingProfileGuid( 
            /* [annotation][in] */ 
            _In_  REFGUID guidProfile) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCurrentProfileGuid( 
            /* [annotation][out] */ 
            _Out_  GUID *pProfileGuid) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ConfigureFilterUsingProfile( 
            /* [annotation][in] */ 
            _In_  IWMProfile *pProfile) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCurrentProfile( 
            /* [annotation][out] */ 
            _Out_  IWMProfile **ppProfile) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetIndexMode( 
            /* [annotation][in] */ 
            _In_  BOOL bIndexFile) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetIndexMode( 
            /* [annotation][out] */ 
            _Out_  BOOL *pbIndexFile) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IConfigAsfWriterVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IConfigAsfWriter * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IConfigAsfWriter * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IConfigAsfWriter * This);
        
        HRESULT ( STDMETHODCALLTYPE *ConfigureFilterUsingProfileId )( 
            __RPC__in IConfigAsfWriter * This,
            /* [annotation][in] */ 
            _In_  DWORD dwProfileId);
        
        HRESULT ( STDMETHODCALLTYPE *GetCurrentProfileId )( 
            __RPC__in IConfigAsfWriter * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwProfileId);
        
        HRESULT ( STDMETHODCALLTYPE *ConfigureFilterUsingProfileGuid )( 
            __RPC__in IConfigAsfWriter * This,
            /* [annotation][in] */ 
            _In_  REFGUID guidProfile);
        
        HRESULT ( STDMETHODCALLTYPE *GetCurrentProfileGuid )( 
            __RPC__in IConfigAsfWriter * This,
            /* [annotation][out] */ 
            _Out_  GUID *pProfileGuid);
        
        HRESULT ( STDMETHODCALLTYPE *ConfigureFilterUsingProfile )( 
            __RPC__in IConfigAsfWriter * This,
            /* [annotation][in] */ 
            _In_  IWMProfile *pProfile);
        
        HRESULT ( STDMETHODCALLTYPE *GetCurrentProfile )( 
            __RPC__in IConfigAsfWriter * This,
            /* [annotation][out] */ 
            _Out_  IWMProfile **ppProfile);
        
        HRESULT ( STDMETHODCALLTYPE *SetIndexMode )( 
            __RPC__in IConfigAsfWriter * This,
            /* [annotation][in] */ 
            _In_  BOOL bIndexFile);
        
        HRESULT ( STDMETHODCALLTYPE *GetIndexMode )( 
            __RPC__in IConfigAsfWriter * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pbIndexFile);
        
        END_INTERFACE
    } IConfigAsfWriterVtbl;

    interface IConfigAsfWriter
    {
        CONST_VTBL struct IConfigAsfWriterVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IConfigAsfWriter_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IConfigAsfWriter_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IConfigAsfWriter_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IConfigAsfWriter_ConfigureFilterUsingProfileId(This,dwProfileId)	\
    ( (This)->lpVtbl -> ConfigureFilterUsingProfileId(This,dwProfileId) ) 

#define IConfigAsfWriter_GetCurrentProfileId(This,pdwProfileId)	\
    ( (This)->lpVtbl -> GetCurrentProfileId(This,pdwProfileId) ) 

#define IConfigAsfWriter_ConfigureFilterUsingProfileGuid(This,guidProfile)	\
    ( (This)->lpVtbl -> ConfigureFilterUsingProfileGuid(This,guidProfile) ) 

#define IConfigAsfWriter_GetCurrentProfileGuid(This,pProfileGuid)	\
    ( (This)->lpVtbl -> GetCurrentProfileGuid(This,pProfileGuid) ) 

#define IConfigAsfWriter_ConfigureFilterUsingProfile(This,pProfile)	\
    ( (This)->lpVtbl -> ConfigureFilterUsingProfile(This,pProfile) ) 

#define IConfigAsfWriter_GetCurrentProfile(This,ppProfile)	\
    ( (This)->lpVtbl -> GetCurrentProfile(This,ppProfile) ) 

#define IConfigAsfWriter_SetIndexMode(This,bIndexFile)	\
    ( (This)->lpVtbl -> SetIndexMode(This,bIndexFile) ) 

#define IConfigAsfWriter_GetIndexMode(This,pbIndexFile)	\
    ( (This)->lpVtbl -> GetIndexMode(This,pbIndexFile) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IConfigAsfWriter_INTERFACE_DEFINED__ */


#ifndef __IConfigAsfWriter2_INTERFACE_DEFINED__
#define __IConfigAsfWriter2_INTERFACE_DEFINED__

/* interface IConfigAsfWriter2 */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IConfigAsfWriter2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7989CCAA-53F0-44f0-884A-F3B03F6AE066")
    IConfigAsfWriter2 : public IConfigAsfWriter
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE StreamNumFromPin( 
            /* [annotation][in] */ 
            _In_  IPin *pPin,
            /* [annotation][out] */ 
            _Out_  WORD *pwStreamNum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetParam( 
            /* [annotation][in] */ 
            _In_  DWORD dwParam,
            /* [annotation][in] */ 
            _In_  DWORD dwParam1,
            /* [annotation][in] */ 
            _In_  DWORD dwParam2) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetParam( 
            /* [annotation][in] */ 
            _In_  DWORD dwParam,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwParam1,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwParam2) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ResetMultiPassState( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IConfigAsfWriter2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IConfigAsfWriter2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IConfigAsfWriter2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IConfigAsfWriter2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *ConfigureFilterUsingProfileId )( 
            __RPC__in IConfigAsfWriter2 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwProfileId);
        
        HRESULT ( STDMETHODCALLTYPE *GetCurrentProfileId )( 
            __RPC__in IConfigAsfWriter2 * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwProfileId);
        
        HRESULT ( STDMETHODCALLTYPE *ConfigureFilterUsingProfileGuid )( 
            __RPC__in IConfigAsfWriter2 * This,
            /* [annotation][in] */ 
            _In_  REFGUID guidProfile);
        
        HRESULT ( STDMETHODCALLTYPE *GetCurrentProfileGuid )( 
            __RPC__in IConfigAsfWriter2 * This,
            /* [annotation][out] */ 
            _Out_  GUID *pProfileGuid);
        
        HRESULT ( STDMETHODCALLTYPE *ConfigureFilterUsingProfile )( 
            __RPC__in IConfigAsfWriter2 * This,
            /* [annotation][in] */ 
            _In_  IWMProfile *pProfile);
        
        HRESULT ( STDMETHODCALLTYPE *GetCurrentProfile )( 
            __RPC__in IConfigAsfWriter2 * This,
            /* [annotation][out] */ 
            _Out_  IWMProfile **ppProfile);
        
        HRESULT ( STDMETHODCALLTYPE *SetIndexMode )( 
            __RPC__in IConfigAsfWriter2 * This,
            /* [annotation][in] */ 
            _In_  BOOL bIndexFile);
        
        HRESULT ( STDMETHODCALLTYPE *GetIndexMode )( 
            __RPC__in IConfigAsfWriter2 * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pbIndexFile);
        
        HRESULT ( STDMETHODCALLTYPE *StreamNumFromPin )( 
            __RPC__in IConfigAsfWriter2 * This,
            /* [annotation][in] */ 
            _In_  IPin *pPin,
            /* [annotation][out] */ 
            _Out_  WORD *pwStreamNum);
        
        HRESULT ( STDMETHODCALLTYPE *SetParam )( 
            __RPC__in IConfigAsfWriter2 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwParam,
            /* [annotation][in] */ 
            _In_  DWORD dwParam1,
            /* [annotation][in] */ 
            _In_  DWORD dwParam2);
        
        HRESULT ( STDMETHODCALLTYPE *GetParam )( 
            __RPC__in IConfigAsfWriter2 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwParam,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwParam1,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwParam2);
        
        HRESULT ( STDMETHODCALLTYPE *ResetMultiPassState )( 
            __RPC__in IConfigAsfWriter2 * This);
        
        END_INTERFACE
    } IConfigAsfWriter2Vtbl;

    interface IConfigAsfWriter2
    {
        CONST_VTBL struct IConfigAsfWriter2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IConfigAsfWriter2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IConfigAsfWriter2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IConfigAsfWriter2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IConfigAsfWriter2_ConfigureFilterUsingProfileId(This,dwProfileId)	\
    ( (This)->lpVtbl -> ConfigureFilterUsingProfileId(This,dwProfileId) ) 

#define IConfigAsfWriter2_GetCurrentProfileId(This,pdwProfileId)	\
    ( (This)->lpVtbl -> GetCurrentProfileId(This,pdwProfileId) ) 

#define IConfigAsfWriter2_ConfigureFilterUsingProfileGuid(This,guidProfile)	\
    ( (This)->lpVtbl -> ConfigureFilterUsingProfileGuid(This,guidProfile) ) 

#define IConfigAsfWriter2_GetCurrentProfileGuid(This,pProfileGuid)	\
    ( (This)->lpVtbl -> GetCurrentProfileGuid(This,pProfileGuid) ) 

#define IConfigAsfWriter2_ConfigureFilterUsingProfile(This,pProfile)	\
    ( (This)->lpVtbl -> ConfigureFilterUsingProfile(This,pProfile) ) 

#define IConfigAsfWriter2_GetCurrentProfile(This,ppProfile)	\
    ( (This)->lpVtbl -> GetCurrentProfile(This,ppProfile) ) 

#define IConfigAsfWriter2_SetIndexMode(This,bIndexFile)	\
    ( (This)->lpVtbl -> SetIndexMode(This,bIndexFile) ) 

#define IConfigAsfWriter2_GetIndexMode(This,pbIndexFile)	\
    ( (This)->lpVtbl -> GetIndexMode(This,pbIndexFile) ) 


#define IConfigAsfWriter2_StreamNumFromPin(This,pPin,pwStreamNum)	\
    ( (This)->lpVtbl -> StreamNumFromPin(This,pPin,pwStreamNum) ) 

#define IConfigAsfWriter2_SetParam(This,dwParam,dwParam1,dwParam2)	\
    ( (This)->lpVtbl -> SetParam(This,dwParam,dwParam1,dwParam2) ) 

#define IConfigAsfWriter2_GetParam(This,dwParam,pdwParam1,pdwParam2)	\
    ( (This)->lpVtbl -> GetParam(This,dwParam,pdwParam1,pdwParam2) ) 

#define IConfigAsfWriter2_ResetMultiPassState(This)	\
    ( (This)->lpVtbl -> ResetMultiPassState(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IConfigAsfWriter2_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_dshowasf_0000_0004 */
/* [local] */ 

////////////////////////////////////////////////////////////////
//
// Windows Media Filters compatibility option flags
//
static DWORD EXCLUDE_SCRIPT_STREAM_DELIVERY_SYNCHRONIZATION = 0x00000001;

////////////////////////////////////////////////////////////////
//
// ATOM strings to match compatibility option flags above for certain applications that don't want to (or not allowed to) update registry entries
// These need to be setup by the application using the WM filters to enable the particular functionality
//
static const WCHAR* g_wszExcludeScriptStreamDeliverySynchronization = L"ExcludeScriptStreamDeliverySynchronization";

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_dshowasf_0000_0004_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_dshowasf_0000_0004_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


