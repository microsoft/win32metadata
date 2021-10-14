

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

#ifndef __tvratings_h__
#define __tvratings_h__

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

#ifndef __IXDSToRat_FWD_DEFINED__
#define __IXDSToRat_FWD_DEFINED__
typedef interface IXDSToRat IXDSToRat;

#endif 	/* __IXDSToRat_FWD_DEFINED__ */


#ifndef __IEvalRat_FWD_DEFINED__
#define __IEvalRat_FWD_DEFINED__
typedef interface IEvalRat IEvalRat;

#endif 	/* __IEvalRat_FWD_DEFINED__ */


#ifndef __XDSToRat_FWD_DEFINED__
#define __XDSToRat_FWD_DEFINED__

#ifdef __cplusplus
typedef class XDSToRat XDSToRat;
#else
typedef struct XDSToRat XDSToRat;
#endif /* __cplusplus */

#endif 	/* __XDSToRat_FWD_DEFINED__ */


#ifndef __EvalRat_FWD_DEFINED__
#define __EvalRat_FWD_DEFINED__

#ifdef __cplusplus
typedef class EvalRat EvalRat;
#else
typedef struct EvalRat EvalRat;
#endif /* __cplusplus */

#endif 	/* __EvalRat_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "encdec.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_tvratings_0000_0000 */
/* [local] */ 

#include <winapifamily.h>
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)


extern RPC_IF_HANDLE __MIDL_itf_tvratings_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_tvratings_0000_0000_v0_0_s_ifspec;

#ifndef __IXDSToRat_INTERFACE_DEFINED__
#define __IXDSToRat_INTERFACE_DEFINED__

/* interface IXDSToRat */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IXDSToRat;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C5C5C5B0-3ABC-11D6-B25B-00C04FA0C026")
    IXDSToRat : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Init( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ParseXDSBytePair( 
            /* [annotation][in] */ 
            _In_  BYTE byte1,
            /* [annotation][in] */ 
            _In_  BYTE byte2,
            /* [annotation][out] */ 
            _Out_  EnTvRat_System *pEnSystem,
            /* [annotation][out] */ 
            _Out_  EnTvRat_GenericLevel *pEnLevel,
            /* [annotation][out] */ 
            _Out_  LONG *plBfEnAttributes) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IXDSToRatVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IXDSToRat * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IXDSToRat * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IXDSToRat * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IXDSToRat * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IXDSToRat * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IXDSToRat * This,
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
            IXDSToRat * This,
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
        
        DECLSPEC_XFGVIRT(IXDSToRat, Init)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Init )( 
            __RPC__in IXDSToRat * This);
        
        DECLSPEC_XFGVIRT(IXDSToRat, ParseXDSBytePair)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ParseXDSBytePair )( 
            __RPC__in IXDSToRat * This,
            /* [annotation][in] */ 
            _In_  BYTE byte1,
            /* [annotation][in] */ 
            _In_  BYTE byte2,
            /* [annotation][out] */ 
            _Out_  EnTvRat_System *pEnSystem,
            /* [annotation][out] */ 
            _Out_  EnTvRat_GenericLevel *pEnLevel,
            /* [annotation][out] */ 
            _Out_  LONG *plBfEnAttributes);
        
        END_INTERFACE
    } IXDSToRatVtbl;

    interface IXDSToRat
    {
        CONST_VTBL struct IXDSToRatVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IXDSToRat_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IXDSToRat_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IXDSToRat_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IXDSToRat_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IXDSToRat_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IXDSToRat_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IXDSToRat_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IXDSToRat_Init(This)	\
    ( (This)->lpVtbl -> Init(This) ) 

#define IXDSToRat_ParseXDSBytePair(This,byte1,byte2,pEnSystem,pEnLevel,plBfEnAttributes)	\
    ( (This)->lpVtbl -> ParseXDSBytePair(This,byte1,byte2,pEnSystem,pEnLevel,plBfEnAttributes) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IXDSToRat_INTERFACE_DEFINED__ */


#ifndef __IEvalRat_INTERFACE_DEFINED__
#define __IEvalRat_INTERFACE_DEFINED__

/* interface IEvalRat */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IEvalRat;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C5C5C5B1-3ABC-11D6-B25B-00C04FA0C026")
    IEvalRat : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_BlockedRatingAttributes( 
            /* [annotation][in] */ 
            _In_  EnTvRat_System enSystem,
            /* [annotation][in] */ 
            _In_  EnTvRat_GenericLevel enLevel,
            /* [annotation][retval][out] */ 
            _Out_retval_  LONG *plbfAttrs) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_BlockedRatingAttributes( 
            /* [annotation][in] */ 
            _In_  EnTvRat_System enSystem,
            /* [annotation][in] */ 
            _In_  EnTvRat_GenericLevel enLevel,
            /* [annotation][in] */ 
            _In_  LONG lbfAttrs) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_BlockUnRated( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BOOL *pfBlockUnRatedShows) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_BlockUnRated( 
            /* [annotation][in] */ 
            _In_  BOOL fBlockUnRatedShows) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MostRestrictiveRating( 
            /* [annotation][in] */ 
            _In_  EnTvRat_System enSystem1,
            /* [annotation][in] */ 
            _In_  EnTvRat_GenericLevel enEnLevel1,
            /* [annotation][in] */ 
            _In_  LONG lbfEnAttr1,
            /* [annotation][in] */ 
            _In_  EnTvRat_System enSystem2,
            /* [annotation][in] */ 
            _In_  EnTvRat_GenericLevel enEnLevel2,
            /* [annotation][in] */ 
            _In_  LONG lbfEnAttr2,
            /* [annotation][out] */ 
            _Out_  EnTvRat_System *penSystem,
            /* [annotation][out] */ 
            _Out_  EnTvRat_GenericLevel *penEnLevel,
            /* [annotation][out] */ 
            _Out_  LONG *plbfEnAttr) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE TestRating( 
            /* [annotation][in] */ 
            _In_  EnTvRat_System enShowSystem,
            /* [annotation][in] */ 
            _In_  EnTvRat_GenericLevel enShowLevel,
            /* [annotation][in] */ 
            _In_  LONG lbfEnShowAttributes) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IEvalRatVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IEvalRat * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IEvalRat * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IEvalRat * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IEvalRat * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IEvalRat * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IEvalRat * This,
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
            IEvalRat * This,
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
        
        DECLSPEC_XFGVIRT(IEvalRat, get_BlockedRatingAttributes)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BlockedRatingAttributes )( 
            __RPC__in IEvalRat * This,
            /* [annotation][in] */ 
            _In_  EnTvRat_System enSystem,
            /* [annotation][in] */ 
            _In_  EnTvRat_GenericLevel enLevel,
            /* [annotation][retval][out] */ 
            _Out_retval_  LONG *plbfAttrs);
        
        DECLSPEC_XFGVIRT(IEvalRat, put_BlockedRatingAttributes)
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BlockedRatingAttributes )( 
            __RPC__in IEvalRat * This,
            /* [annotation][in] */ 
            _In_  EnTvRat_System enSystem,
            /* [annotation][in] */ 
            _In_  EnTvRat_GenericLevel enLevel,
            /* [annotation][in] */ 
            _In_  LONG lbfAttrs);
        
        DECLSPEC_XFGVIRT(IEvalRat, get_BlockUnRated)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BlockUnRated )( 
            __RPC__in IEvalRat * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BOOL *pfBlockUnRatedShows);
        
        DECLSPEC_XFGVIRT(IEvalRat, put_BlockUnRated)
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BlockUnRated )( 
            __RPC__in IEvalRat * This,
            /* [annotation][in] */ 
            _In_  BOOL fBlockUnRatedShows);
        
        DECLSPEC_XFGVIRT(IEvalRat, MostRestrictiveRating)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MostRestrictiveRating )( 
            __RPC__in IEvalRat * This,
            /* [annotation][in] */ 
            _In_  EnTvRat_System enSystem1,
            /* [annotation][in] */ 
            _In_  EnTvRat_GenericLevel enEnLevel1,
            /* [annotation][in] */ 
            _In_  LONG lbfEnAttr1,
            /* [annotation][in] */ 
            _In_  EnTvRat_System enSystem2,
            /* [annotation][in] */ 
            _In_  EnTvRat_GenericLevel enEnLevel2,
            /* [annotation][in] */ 
            _In_  LONG lbfEnAttr2,
            /* [annotation][out] */ 
            _Out_  EnTvRat_System *penSystem,
            /* [annotation][out] */ 
            _Out_  EnTvRat_GenericLevel *penEnLevel,
            /* [annotation][out] */ 
            _Out_  LONG *plbfEnAttr);
        
        DECLSPEC_XFGVIRT(IEvalRat, TestRating)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *TestRating )( 
            __RPC__in IEvalRat * This,
            /* [annotation][in] */ 
            _In_  EnTvRat_System enShowSystem,
            /* [annotation][in] */ 
            _In_  EnTvRat_GenericLevel enShowLevel,
            /* [annotation][in] */ 
            _In_  LONG lbfEnShowAttributes);
        
        END_INTERFACE
    } IEvalRatVtbl;

    interface IEvalRat
    {
        CONST_VTBL struct IEvalRatVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEvalRat_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEvalRat_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEvalRat_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IEvalRat_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IEvalRat_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IEvalRat_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IEvalRat_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IEvalRat_get_BlockedRatingAttributes(This,enSystem,enLevel,plbfAttrs)	\
    ( (This)->lpVtbl -> get_BlockedRatingAttributes(This,enSystem,enLevel,plbfAttrs) ) 

#define IEvalRat_put_BlockedRatingAttributes(This,enSystem,enLevel,lbfAttrs)	\
    ( (This)->lpVtbl -> put_BlockedRatingAttributes(This,enSystem,enLevel,lbfAttrs) ) 

#define IEvalRat_get_BlockUnRated(This,pfBlockUnRatedShows)	\
    ( (This)->lpVtbl -> get_BlockUnRated(This,pfBlockUnRatedShows) ) 

#define IEvalRat_put_BlockUnRated(This,fBlockUnRatedShows)	\
    ( (This)->lpVtbl -> put_BlockUnRated(This,fBlockUnRatedShows) ) 

#define IEvalRat_MostRestrictiveRating(This,enSystem1,enEnLevel1,lbfEnAttr1,enSystem2,enEnLevel2,lbfEnAttr2,penSystem,penEnLevel,plbfEnAttr)	\
    ( (This)->lpVtbl -> MostRestrictiveRating(This,enSystem1,enEnLevel1,lbfEnAttr1,enSystem2,enEnLevel2,lbfEnAttr2,penSystem,penEnLevel,plbfEnAttr) ) 

#define IEvalRat_TestRating(This,enShowSystem,enShowLevel,lbfEnShowAttributes)	\
    ( (This)->lpVtbl -> TestRating(This,enShowSystem,enShowLevel,lbfEnShowAttributes) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IEvalRat_INTERFACE_DEFINED__ */



#ifndef __TVRATINGSLib_LIBRARY_DEFINED__
#define __TVRATINGSLib_LIBRARY_DEFINED__

/* library TVRATINGSLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_TVRATINGSLib;

EXTERN_C const CLSID CLSID_XDSToRat;

#ifdef __cplusplus

class DECLSPEC_UUID("C5C5C5F0-3ABC-11D6-B25B-00C04FA0C026")
XDSToRat;
#endif

EXTERN_C const CLSID CLSID_EvalRat;

#ifdef __cplusplus

class DECLSPEC_UUID("C5C5C5F1-3ABC-11D6-B25B-00C04FA0C026")
EvalRat;
#endif
#endif /* __TVRATINGSLib_LIBRARY_DEFINED__ */

/* interface __MIDL_itf_tvratings_0000_0003 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_tvratings_0000_0003_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_tvratings_0000_0003_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


