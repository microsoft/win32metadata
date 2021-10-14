

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

#ifndef __correngine_h__
#define __correngine_h__

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

#ifndef __ICorrelationEngine_FWD_DEFINED__
#define __ICorrelationEngine_FWD_DEFINED__
typedef interface ICorrelationEngine ICorrelationEngine;

#endif 	/* __ICorrelationEngine_FWD_DEFINED__ */


#ifndef __CorrelationEngine_FWD_DEFINED__
#define __CorrelationEngine_FWD_DEFINED__

#ifdef __cplusplus
typedef class CorrelationEngine CorrelationEngine;
#else
typedef struct CorrelationEngine CorrelationEngine;
#endif /* __cplusplus */

#endif 	/* __CorrelationEngine_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_correngine_0000_0000 */
/* [local] */ 

//+--------------------------------------------------------------------------
//
//  Microsoft Windows
//  Copyright (C) Microsoft Corporation, 1992-2007.
//
//---------------------------------------------------------------------------
#include <winapifamily.h>
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)


extern RPC_IF_HANDLE __MIDL_itf_correngine_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_correngine_0000_0000_v0_0_s_ifspec;

#ifndef __ICorrelationEngine_INTERFACE_DEFINED__
#define __ICorrelationEngine_INTERFACE_DEFINED__

/* interface ICorrelationEngine */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ICorrelationEngine;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A188440E-DB11-45B8-B42C-B2149FA71453")
    ICorrelationEngine : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RetainGlobalEvents( 
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_RetainGlobalEvents( 
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Filter( 
            /* [annotation][in] */ 
            _In_  BSTR InputTraceFile,
            /* [annotation][in] */ 
            _In_  BSTR OutputTraceFile,
            /* [annotation][in] */ 
            _In_  BSTR FilterActivityId) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Normalize( 
            /* [annotation][in] */ 
            _In_  BSTR InputTraceFile,
            /* [annotation][in] */ 
            _In_  BSTR OutputTraceFile) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RetainPII( 
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_RetainPII( 
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RetainCorrelationEvents( 
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_RetainCorrelationEvents( 
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL newVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICorrelationEngineVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ICorrelationEngine * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ICorrelationEngine * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ICorrelationEngine * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in ICorrelationEngine * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in ICorrelationEngine * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in ICorrelationEngine * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][size_is][in] */ 
            _In_reads_(cNames)  LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cNames)  DISPID *rgDispId);
        
        DECLSPEC_XFGVIRT(IDispatch, Invoke)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICorrelationEngine * This,
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
        
        DECLSPEC_XFGVIRT(ICorrelationEngine, get_RetainGlobalEvents)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RetainGlobalEvents )( 
            __RPC__in ICorrelationEngine * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pVal);
        
        DECLSPEC_XFGVIRT(ICorrelationEngine, put_RetainGlobalEvents)
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RetainGlobalEvents )( 
            __RPC__in ICorrelationEngine * This,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL newVal);
        
        DECLSPEC_XFGVIRT(ICorrelationEngine, Filter)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Filter )( 
            __RPC__in ICorrelationEngine * This,
            /* [annotation][in] */ 
            _In_  BSTR InputTraceFile,
            /* [annotation][in] */ 
            _In_  BSTR OutputTraceFile,
            /* [annotation][in] */ 
            _In_  BSTR FilterActivityId);
        
        DECLSPEC_XFGVIRT(ICorrelationEngine, Normalize)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Normalize )( 
            __RPC__in ICorrelationEngine * This,
            /* [annotation][in] */ 
            _In_  BSTR InputTraceFile,
            /* [annotation][in] */ 
            _In_  BSTR OutputTraceFile);
        
        DECLSPEC_XFGVIRT(ICorrelationEngine, get_RetainPII)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RetainPII )( 
            __RPC__in ICorrelationEngine * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pVal);
        
        DECLSPEC_XFGVIRT(ICorrelationEngine, put_RetainPII)
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RetainPII )( 
            __RPC__in ICorrelationEngine * This,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL newVal);
        
        DECLSPEC_XFGVIRT(ICorrelationEngine, get_RetainCorrelationEvents)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RetainCorrelationEvents )( 
            __RPC__in ICorrelationEngine * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pVal);
        
        DECLSPEC_XFGVIRT(ICorrelationEngine, put_RetainCorrelationEvents)
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RetainCorrelationEvents )( 
            __RPC__in ICorrelationEngine * This,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL newVal);
        
        END_INTERFACE
    } ICorrelationEngineVtbl;

    interface ICorrelationEngine
    {
        CONST_VTBL struct ICorrelationEngineVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICorrelationEngine_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICorrelationEngine_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICorrelationEngine_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICorrelationEngine_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ICorrelationEngine_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ICorrelationEngine_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ICorrelationEngine_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ICorrelationEngine_get_RetainGlobalEvents(This,pVal)	\
    ( (This)->lpVtbl -> get_RetainGlobalEvents(This,pVal) ) 

#define ICorrelationEngine_put_RetainGlobalEvents(This,newVal)	\
    ( (This)->lpVtbl -> put_RetainGlobalEvents(This,newVal) ) 

#define ICorrelationEngine_Filter(This,InputTraceFile,OutputTraceFile,FilterActivityId)	\
    ( (This)->lpVtbl -> Filter(This,InputTraceFile,OutputTraceFile,FilterActivityId) ) 

#define ICorrelationEngine_Normalize(This,InputTraceFile,OutputTraceFile)	\
    ( (This)->lpVtbl -> Normalize(This,InputTraceFile,OutputTraceFile) ) 

#define ICorrelationEngine_get_RetainPII(This,pVal)	\
    ( (This)->lpVtbl -> get_RetainPII(This,pVal) ) 

#define ICorrelationEngine_put_RetainPII(This,newVal)	\
    ( (This)->lpVtbl -> put_RetainPII(This,newVal) ) 

#define ICorrelationEngine_get_RetainCorrelationEvents(This,pVal)	\
    ( (This)->lpVtbl -> get_RetainCorrelationEvents(This,pVal) ) 

#define ICorrelationEngine_put_RetainCorrelationEvents(This,newVal)	\
    ( (This)->lpVtbl -> put_RetainCorrelationEvents(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICorrelationEngine_INTERFACE_DEFINED__ */



#ifndef __CorrEngineLib_LIBRARY_DEFINED__
#define __CorrEngineLib_LIBRARY_DEFINED__

/* library CorrEngineLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_CorrEngineLib;

EXTERN_C const CLSID CLSID_CorrelationEngine;

#ifdef __cplusplus

class DECLSPEC_UUID("FCDC2CF5-ABCD-4BA5-94DA-1823AE06FE2B")
CorrelationEngine;
#endif
#endif /* __CorrEngineLib_LIBRARY_DEFINED__ */

/* interface __MIDL_itf_correngine_0000_0002 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_correngine_0000_0002_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_correngine_0000_0002_v0_0_s_ifspec;

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


