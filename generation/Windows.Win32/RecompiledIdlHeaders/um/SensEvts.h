

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


#ifndef __sensevts_h__
#define __sensevts_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ISensNetwork_FWD_DEFINED__
#define __ISensNetwork_FWD_DEFINED__
typedef interface ISensNetwork ISensNetwork;

#endif 	/* __ISensNetwork_FWD_DEFINED__ */


#ifndef __ISensOnNow_FWD_DEFINED__
#define __ISensOnNow_FWD_DEFINED__
typedef interface ISensOnNow ISensOnNow;

#endif 	/* __ISensOnNow_FWD_DEFINED__ */


#ifndef __ISensLogon_FWD_DEFINED__
#define __ISensLogon_FWD_DEFINED__
typedef interface ISensLogon ISensLogon;

#endif 	/* __ISensLogon_FWD_DEFINED__ */


#ifndef __ISensLogon2_FWD_DEFINED__
#define __ISensLogon2_FWD_DEFINED__
typedef interface ISensLogon2 ISensLogon2;

#endif 	/* __ISensLogon2_FWD_DEFINED__ */


#ifndef __SENS_FWD_DEFINED__
#define __SENS_FWD_DEFINED__

#ifdef __cplusplus
typedef class SENS SENS;
#else
typedef struct SENS SENS;
#endif /* __cplusplus */

#endif 	/* __SENS_FWD_DEFINED__ */


/* header files for imported files */
#include "wtypes.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_sensevts_0000_0000 */
/* [local] */ 

#include <winapifamily.h>
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)


extern RPC_IF_HANDLE __MIDL_itf_sensevts_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sensevts_0000_0000_v0_0_s_ifspec;


#ifndef __SensEvents_LIBRARY_DEFINED__
#define __SensEvents_LIBRARY_DEFINED__

/* library SensEvents */
/* [helpstring][version][uuid] */ 

typedef /* [uuid] */  DECLSPEC_UUID("d597fad1-5b9f-11d1-8dd2-00aa004abd5e") struct SENS_QOCINFO
    {
    DWORD dwSize;
    DWORD dwFlags;
    DWORD dwOutSpeed;
    DWORD dwInSpeed;
    } 	SENS_QOCINFO;

typedef SENS_QOCINFO *LPSENS_QOCINFO;


EXTERN_C const IID LIBID_SensEvents;

#ifndef __ISensNetwork_INTERFACE_DEFINED__
#define __ISensNetwork_INTERFACE_DEFINED__

/* interface ISensNetwork */
/* [dual][helpstring][version][uuid][object] */ 


EXTERN_C const IID IID_ISensNetwork;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("d597bab1-5b9f-11d1-8dd2-00aa004abd5e")
    ISensNetwork : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ConnectionMade( 
            /* [annotation][in] */ 
            _In_  BSTR bstrConnection,
            /* [annotation][in] */ 
            _In_  ULONG ulType,
            /* [annotation][in] */ 
            _In_  LPSENS_QOCINFO lpQOCInfo) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ConnectionMadeNoQOCInfo( 
            /* [annotation][in] */ 
            _In_  BSTR bstrConnection,
            /* [annotation][in] */ 
            _In_  ULONG ulType) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ConnectionLost( 
            /* [annotation][in] */ 
            _In_  BSTR bstrConnection,
            /* [annotation][in] */ 
            _In_  ULONG ulType) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE DestinationReachable( 
            /* [annotation][in] */ 
            _In_  BSTR bstrDestination,
            /* [annotation][in] */ 
            _In_  BSTR bstrConnection,
            /* [annotation][in] */ 
            _In_  ULONG ulType,
            /* [annotation][in] */ 
            _In_  LPSENS_QOCINFO lpQOCInfo) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE DestinationReachableNoQOCInfo( 
            /* [annotation][in] */ 
            _In_  BSTR bstrDestination,
            /* [annotation][in] */ 
            _In_  BSTR bstrConnection,
            /* [annotation][in] */ 
            _In_  ULONG ulType) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISensNetworkVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISensNetwork * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISensNetwork * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISensNetwork * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in ISensNetwork * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in ISensNetwork * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in ISensNetwork * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][size_is][in] */ 
            _In_reads_(cNames)  LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cNames)  DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISensNetwork * This,
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
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ConnectionMade )( 
            __RPC__in ISensNetwork * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrConnection,
            /* [annotation][in] */ 
            _In_  ULONG ulType,
            /* [annotation][in] */ 
            _In_  LPSENS_QOCINFO lpQOCInfo);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ConnectionMadeNoQOCInfo )( 
            __RPC__in ISensNetwork * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrConnection,
            /* [annotation][in] */ 
            _In_  ULONG ulType);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ConnectionLost )( 
            __RPC__in ISensNetwork * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrConnection,
            /* [annotation][in] */ 
            _In_  ULONG ulType);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *DestinationReachable )( 
            __RPC__in ISensNetwork * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrDestination,
            /* [annotation][in] */ 
            _In_  BSTR bstrConnection,
            /* [annotation][in] */ 
            _In_  ULONG ulType,
            /* [annotation][in] */ 
            _In_  LPSENS_QOCINFO lpQOCInfo);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *DestinationReachableNoQOCInfo )( 
            __RPC__in ISensNetwork * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrDestination,
            /* [annotation][in] */ 
            _In_  BSTR bstrConnection,
            /* [annotation][in] */ 
            _In_  ULONG ulType);
        
        END_INTERFACE
    } ISensNetworkVtbl;

    interface ISensNetwork
    {
        CONST_VTBL struct ISensNetworkVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISensNetwork_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISensNetwork_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISensNetwork_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISensNetwork_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISensNetwork_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISensNetwork_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISensNetwork_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISensNetwork_ConnectionMade(This,bstrConnection,ulType,lpQOCInfo)	\
    ( (This)->lpVtbl -> ConnectionMade(This,bstrConnection,ulType,lpQOCInfo) ) 

#define ISensNetwork_ConnectionMadeNoQOCInfo(This,bstrConnection,ulType)	\
    ( (This)->lpVtbl -> ConnectionMadeNoQOCInfo(This,bstrConnection,ulType) ) 

#define ISensNetwork_ConnectionLost(This,bstrConnection,ulType)	\
    ( (This)->lpVtbl -> ConnectionLost(This,bstrConnection,ulType) ) 

#define ISensNetwork_DestinationReachable(This,bstrDestination,bstrConnection,ulType,lpQOCInfo)	\
    ( (This)->lpVtbl -> DestinationReachable(This,bstrDestination,bstrConnection,ulType,lpQOCInfo) ) 

#define ISensNetwork_DestinationReachableNoQOCInfo(This,bstrDestination,bstrConnection,ulType)	\
    ( (This)->lpVtbl -> DestinationReachableNoQOCInfo(This,bstrDestination,bstrConnection,ulType) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISensNetwork_INTERFACE_DEFINED__ */


#ifndef __ISensOnNow_INTERFACE_DEFINED__
#define __ISensOnNow_INTERFACE_DEFINED__

/* interface ISensOnNow */
/* [dual][helpstring][version][uuid][object] */ 


EXTERN_C const IID IID_ISensOnNow;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("d597bab2-5b9f-11d1-8dd2-00aa004abd5e")
    ISensOnNow : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE OnACPower( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE OnBatteryPower( 
            /* [annotation][in] */ 
            _In_  DWORD dwBatteryLifePercent) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE BatteryLow( 
            /* [annotation][in] */ 
            _In_  DWORD dwBatteryLifePercent) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISensOnNowVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISensOnNow * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISensOnNow * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISensOnNow * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in ISensOnNow * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in ISensOnNow * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in ISensOnNow * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][size_is][in] */ 
            _In_reads_(cNames)  LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cNames)  DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISensOnNow * This,
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
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *OnACPower )( 
            __RPC__in ISensOnNow * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *OnBatteryPower )( 
            __RPC__in ISensOnNow * This,
            /* [annotation][in] */ 
            _In_  DWORD dwBatteryLifePercent);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *BatteryLow )( 
            __RPC__in ISensOnNow * This,
            /* [annotation][in] */ 
            _In_  DWORD dwBatteryLifePercent);
        
        END_INTERFACE
    } ISensOnNowVtbl;

    interface ISensOnNow
    {
        CONST_VTBL struct ISensOnNowVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISensOnNow_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISensOnNow_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISensOnNow_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISensOnNow_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISensOnNow_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISensOnNow_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISensOnNow_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISensOnNow_OnACPower(This)	\
    ( (This)->lpVtbl -> OnACPower(This) ) 

#define ISensOnNow_OnBatteryPower(This,dwBatteryLifePercent)	\
    ( (This)->lpVtbl -> OnBatteryPower(This,dwBatteryLifePercent) ) 

#define ISensOnNow_BatteryLow(This,dwBatteryLifePercent)	\
    ( (This)->lpVtbl -> BatteryLow(This,dwBatteryLifePercent) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISensOnNow_INTERFACE_DEFINED__ */


#ifndef __ISensLogon_INTERFACE_DEFINED__
#define __ISensLogon_INTERFACE_DEFINED__

/* interface ISensLogon */
/* [dual][helpstring][version][uuid][object] */ 


EXTERN_C const IID IID_ISensLogon;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("d597bab3-5b9f-11d1-8dd2-00aa004abd5e")
    ISensLogon : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Logon( 
            /* [annotation][in] */ 
            _In_  BSTR bstrUserName) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Logoff( 
            /* [annotation][in] */ 
            _In_  BSTR bstrUserName) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE StartShell( 
            /* [annotation][in] */ 
            _In_  BSTR bstrUserName) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE DisplayLock( 
            /* [annotation][in] */ 
            _In_  BSTR bstrUserName) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE DisplayUnlock( 
            /* [annotation][in] */ 
            _In_  BSTR bstrUserName) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE StartScreenSaver( 
            /* [annotation][in] */ 
            _In_  BSTR bstrUserName) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE StopScreenSaver( 
            /* [annotation][in] */ 
            _In_  BSTR bstrUserName) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISensLogonVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISensLogon * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISensLogon * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISensLogon * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in ISensLogon * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in ISensLogon * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in ISensLogon * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][size_is][in] */ 
            _In_reads_(cNames)  LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cNames)  DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISensLogon * This,
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
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Logon )( 
            __RPC__in ISensLogon * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrUserName);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Logoff )( 
            __RPC__in ISensLogon * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrUserName);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *StartShell )( 
            __RPC__in ISensLogon * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrUserName);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *DisplayLock )( 
            __RPC__in ISensLogon * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrUserName);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *DisplayUnlock )( 
            __RPC__in ISensLogon * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrUserName);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *StartScreenSaver )( 
            __RPC__in ISensLogon * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrUserName);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *StopScreenSaver )( 
            __RPC__in ISensLogon * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrUserName);
        
        END_INTERFACE
    } ISensLogonVtbl;

    interface ISensLogon
    {
        CONST_VTBL struct ISensLogonVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISensLogon_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISensLogon_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISensLogon_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISensLogon_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISensLogon_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISensLogon_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISensLogon_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISensLogon_Logon(This,bstrUserName)	\
    ( (This)->lpVtbl -> Logon(This,bstrUserName) ) 

#define ISensLogon_Logoff(This,bstrUserName)	\
    ( (This)->lpVtbl -> Logoff(This,bstrUserName) ) 

#define ISensLogon_StartShell(This,bstrUserName)	\
    ( (This)->lpVtbl -> StartShell(This,bstrUserName) ) 

#define ISensLogon_DisplayLock(This,bstrUserName)	\
    ( (This)->lpVtbl -> DisplayLock(This,bstrUserName) ) 

#define ISensLogon_DisplayUnlock(This,bstrUserName)	\
    ( (This)->lpVtbl -> DisplayUnlock(This,bstrUserName) ) 

#define ISensLogon_StartScreenSaver(This,bstrUserName)	\
    ( (This)->lpVtbl -> StartScreenSaver(This,bstrUserName) ) 

#define ISensLogon_StopScreenSaver(This,bstrUserName)	\
    ( (This)->lpVtbl -> StopScreenSaver(This,bstrUserName) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISensLogon_INTERFACE_DEFINED__ */


#ifndef __ISensLogon2_INTERFACE_DEFINED__
#define __ISensLogon2_INTERFACE_DEFINED__

/* interface ISensLogon2 */
/* [dual][helpstring][version][uuid][object] */ 


EXTERN_C const IID IID_ISensLogon2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("d597bab4-5b9f-11d1-8dd2-00aa004abd5e")
    ISensLogon2 : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Logon( 
            /* [annotation][in] */ 
            _In_  BSTR bstrUserName,
            /* [annotation][in] */ 
            _In_  DWORD dwSessionId) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Logoff( 
            /* [annotation][in] */ 
            _In_  BSTR bstrUserName,
            /* [annotation][in] */ 
            _In_  DWORD dwSessionId) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SessionDisconnect( 
            /* [annotation][in] */ 
            _In_  BSTR bstrUserName,
            /* [annotation][in] */ 
            _In_  DWORD dwSessionId) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SessionReconnect( 
            /* [annotation][in] */ 
            _In_  BSTR bstrUserName,
            /* [annotation][in] */ 
            _In_  DWORD dwSessionId) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE PostShell( 
            /* [annotation][in] */ 
            _In_  BSTR bstrUserName,
            /* [annotation][in] */ 
            _In_  DWORD dwSessionId) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISensLogon2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISensLogon2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISensLogon2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISensLogon2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in ISensLogon2 * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in ISensLogon2 * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in ISensLogon2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][size_is][in] */ 
            _In_reads_(cNames)  LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cNames)  DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISensLogon2 * This,
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
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Logon )( 
            __RPC__in ISensLogon2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrUserName,
            /* [annotation][in] */ 
            _In_  DWORD dwSessionId);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Logoff )( 
            __RPC__in ISensLogon2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrUserName,
            /* [annotation][in] */ 
            _In_  DWORD dwSessionId);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SessionDisconnect )( 
            __RPC__in ISensLogon2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrUserName,
            /* [annotation][in] */ 
            _In_  DWORD dwSessionId);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SessionReconnect )( 
            __RPC__in ISensLogon2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrUserName,
            /* [annotation][in] */ 
            _In_  DWORD dwSessionId);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *PostShell )( 
            __RPC__in ISensLogon2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrUserName,
            /* [annotation][in] */ 
            _In_  DWORD dwSessionId);
        
        END_INTERFACE
    } ISensLogon2Vtbl;

    interface ISensLogon2
    {
        CONST_VTBL struct ISensLogon2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISensLogon2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISensLogon2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISensLogon2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISensLogon2_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISensLogon2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISensLogon2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISensLogon2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISensLogon2_Logon(This,bstrUserName,dwSessionId)	\
    ( (This)->lpVtbl -> Logon(This,bstrUserName,dwSessionId) ) 

#define ISensLogon2_Logoff(This,bstrUserName,dwSessionId)	\
    ( (This)->lpVtbl -> Logoff(This,bstrUserName,dwSessionId) ) 

#define ISensLogon2_SessionDisconnect(This,bstrUserName,dwSessionId)	\
    ( (This)->lpVtbl -> SessionDisconnect(This,bstrUserName,dwSessionId) ) 

#define ISensLogon2_SessionReconnect(This,bstrUserName,dwSessionId)	\
    ( (This)->lpVtbl -> SessionReconnect(This,bstrUserName,dwSessionId) ) 

#define ISensLogon2_PostShell(This,bstrUserName,dwSessionId)	\
    ( (This)->lpVtbl -> PostShell(This,bstrUserName,dwSessionId) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISensLogon2_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_SENS;

#ifdef __cplusplus

class DECLSPEC_UUID("d597cafe-5b9f-11d1-8dd2-00aa004abd5e")
SENS;
#endif
#endif /* __SensEvents_LIBRARY_DEFINED__ */

/* interface __MIDL_itf_sensevts_0000_0001 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_sensevts_0000_0001_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sensevts_0000_0001_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


