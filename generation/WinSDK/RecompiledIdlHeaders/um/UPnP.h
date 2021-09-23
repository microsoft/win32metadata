

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

#ifndef __upnp_h__
#define __upnp_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IUPnPDeviceFinder_FWD_DEFINED__
#define __IUPnPDeviceFinder_FWD_DEFINED__
typedef interface IUPnPDeviceFinder IUPnPDeviceFinder;

#endif 	/* __IUPnPDeviceFinder_FWD_DEFINED__ */


#ifndef __IUPnPAddressFamilyControl_FWD_DEFINED__
#define __IUPnPAddressFamilyControl_FWD_DEFINED__
typedef interface IUPnPAddressFamilyControl IUPnPAddressFamilyControl;

#endif 	/* __IUPnPAddressFamilyControl_FWD_DEFINED__ */


#ifndef __IUPnPHttpHeaderControl_FWD_DEFINED__
#define __IUPnPHttpHeaderControl_FWD_DEFINED__
typedef interface IUPnPHttpHeaderControl IUPnPHttpHeaderControl;

#endif 	/* __IUPnPHttpHeaderControl_FWD_DEFINED__ */


#ifndef __IUPnPDeviceFinderCallback_FWD_DEFINED__
#define __IUPnPDeviceFinderCallback_FWD_DEFINED__
typedef interface IUPnPDeviceFinderCallback IUPnPDeviceFinderCallback;

#endif 	/* __IUPnPDeviceFinderCallback_FWD_DEFINED__ */


#ifndef __IUPnPServices_FWD_DEFINED__
#define __IUPnPServices_FWD_DEFINED__
typedef interface IUPnPServices IUPnPServices;

#endif 	/* __IUPnPServices_FWD_DEFINED__ */


#ifndef __IUPnPService_FWD_DEFINED__
#define __IUPnPService_FWD_DEFINED__
typedef interface IUPnPService IUPnPService;

#endif 	/* __IUPnPService_FWD_DEFINED__ */


#ifndef __IUPnPAsyncResult_FWD_DEFINED__
#define __IUPnPAsyncResult_FWD_DEFINED__
typedef interface IUPnPAsyncResult IUPnPAsyncResult;

#endif 	/* __IUPnPAsyncResult_FWD_DEFINED__ */


#ifndef __IUPnPServiceAsync_FWD_DEFINED__
#define __IUPnPServiceAsync_FWD_DEFINED__
typedef interface IUPnPServiceAsync IUPnPServiceAsync;

#endif 	/* __IUPnPServiceAsync_FWD_DEFINED__ */


#ifndef __IUPnPServiceCallback_FWD_DEFINED__
#define __IUPnPServiceCallback_FWD_DEFINED__
typedef interface IUPnPServiceCallback IUPnPServiceCallback;

#endif 	/* __IUPnPServiceCallback_FWD_DEFINED__ */


#ifndef __IUPnPServiceEnumProperty_FWD_DEFINED__
#define __IUPnPServiceEnumProperty_FWD_DEFINED__
typedef interface IUPnPServiceEnumProperty IUPnPServiceEnumProperty;

#endif 	/* __IUPnPServiceEnumProperty_FWD_DEFINED__ */


#ifndef __IUPnPServiceDocumentAccess_FWD_DEFINED__
#define __IUPnPServiceDocumentAccess_FWD_DEFINED__
typedef interface IUPnPServiceDocumentAccess IUPnPServiceDocumentAccess;

#endif 	/* __IUPnPServiceDocumentAccess_FWD_DEFINED__ */


#ifndef __IUPnPDevices_FWD_DEFINED__
#define __IUPnPDevices_FWD_DEFINED__
typedef interface IUPnPDevices IUPnPDevices;

#endif 	/* __IUPnPDevices_FWD_DEFINED__ */


#ifndef __IUPnPDevice_FWD_DEFINED__
#define __IUPnPDevice_FWD_DEFINED__
typedef interface IUPnPDevice IUPnPDevice;

#endif 	/* __IUPnPDevice_FWD_DEFINED__ */


#ifndef __IUPnPDeviceDocumentAccess_FWD_DEFINED__
#define __IUPnPDeviceDocumentAccess_FWD_DEFINED__
typedef interface IUPnPDeviceDocumentAccess IUPnPDeviceDocumentAccess;

#endif 	/* __IUPnPDeviceDocumentAccess_FWD_DEFINED__ */


#ifndef __IUPnPDeviceDocumentAccessEx_FWD_DEFINED__
#define __IUPnPDeviceDocumentAccessEx_FWD_DEFINED__
typedef interface IUPnPDeviceDocumentAccessEx IUPnPDeviceDocumentAccessEx;

#endif 	/* __IUPnPDeviceDocumentAccessEx_FWD_DEFINED__ */


#ifndef __IUPnPDescriptionDocument_FWD_DEFINED__
#define __IUPnPDescriptionDocument_FWD_DEFINED__
typedef interface IUPnPDescriptionDocument IUPnPDescriptionDocument;

#endif 	/* __IUPnPDescriptionDocument_FWD_DEFINED__ */


#ifndef __IUPnPDeviceFinderAddCallbackWithInterface_FWD_DEFINED__
#define __IUPnPDeviceFinderAddCallbackWithInterface_FWD_DEFINED__
typedef interface IUPnPDeviceFinderAddCallbackWithInterface IUPnPDeviceFinderAddCallbackWithInterface;

#endif 	/* __IUPnPDeviceFinderAddCallbackWithInterface_FWD_DEFINED__ */


#ifndef __IUPnPDescriptionDocumentCallback_FWD_DEFINED__
#define __IUPnPDescriptionDocumentCallback_FWD_DEFINED__
typedef interface IUPnPDescriptionDocumentCallback IUPnPDescriptionDocumentCallback;

#endif 	/* __IUPnPDescriptionDocumentCallback_FWD_DEFINED__ */


#ifndef __UPnPDeviceFinder_FWD_DEFINED__
#define __UPnPDeviceFinder_FWD_DEFINED__

#ifdef __cplusplus
typedef class UPnPDeviceFinder UPnPDeviceFinder;
#else
typedef struct UPnPDeviceFinder UPnPDeviceFinder;
#endif /* __cplusplus */

#endif 	/* __UPnPDeviceFinder_FWD_DEFINED__ */


#ifndef __UPnPDevices_FWD_DEFINED__
#define __UPnPDevices_FWD_DEFINED__

#ifdef __cplusplus
typedef class UPnPDevices UPnPDevices;
#else
typedef struct UPnPDevices UPnPDevices;
#endif /* __cplusplus */

#endif 	/* __UPnPDevices_FWD_DEFINED__ */


#ifndef __UPnPDevice_FWD_DEFINED__
#define __UPnPDevice_FWD_DEFINED__

#ifdef __cplusplus
typedef class UPnPDevice UPnPDevice;
#else
typedef struct UPnPDevice UPnPDevice;
#endif /* __cplusplus */

#endif 	/* __UPnPDevice_FWD_DEFINED__ */


#ifndef __UPnPServices_FWD_DEFINED__
#define __UPnPServices_FWD_DEFINED__

#ifdef __cplusplus
typedef class UPnPServices UPnPServices;
#else
typedef struct UPnPServices UPnPServices;
#endif /* __cplusplus */

#endif 	/* __UPnPServices_FWD_DEFINED__ */


#ifndef __UPnPService_FWD_DEFINED__
#define __UPnPService_FWD_DEFINED__

#ifdef __cplusplus
typedef class UPnPService UPnPService;
#else
typedef struct UPnPService UPnPService;
#endif /* __cplusplus */

#endif 	/* __UPnPService_FWD_DEFINED__ */


#ifndef __UPnPDescriptionDocument_FWD_DEFINED__
#define __UPnPDescriptionDocument_FWD_DEFINED__

#ifdef __cplusplus
typedef class UPnPDescriptionDocument UPnPDescriptionDocument;
#else
typedef struct UPnPDescriptionDocument UPnPDescriptionDocument;
#endif /* __cplusplus */

#endif 	/* __UPnPDescriptionDocument_FWD_DEFINED__ */


#ifndef __UPnPDeviceFinderEx_FWD_DEFINED__
#define __UPnPDeviceFinderEx_FWD_DEFINED__

#ifdef __cplusplus
typedef class UPnPDeviceFinderEx UPnPDeviceFinderEx;
#else
typedef struct UPnPDeviceFinderEx UPnPDeviceFinderEx;
#endif /* __cplusplus */

#endif 	/* __UPnPDeviceFinderEx_FWD_DEFINED__ */


#ifndef __UPnPDescriptionDocumentEx_FWD_DEFINED__
#define __UPnPDescriptionDocumentEx_FWD_DEFINED__

#ifdef __cplusplus
typedef class UPnPDescriptionDocumentEx UPnPDescriptionDocumentEx;
#else
typedef struct UPnPDescriptionDocumentEx UPnPDescriptionDocumentEx;
#endif /* __cplusplus */

#endif 	/* __UPnPDescriptionDocumentEx_FWD_DEFINED__ */


#ifndef __IUPnPDeviceDocumentAccess_FWD_DEFINED__
#define __IUPnPDeviceDocumentAccess_FWD_DEFINED__
typedef interface IUPnPDeviceDocumentAccess IUPnPDeviceDocumentAccess;

#endif 	/* __IUPnPDeviceDocumentAccess_FWD_DEFINED__ */


#ifndef __IUPnPDeviceDocumentAccessEx_FWD_DEFINED__
#define __IUPnPDeviceDocumentAccessEx_FWD_DEFINED__
typedef interface IUPnPDeviceDocumentAccessEx IUPnPDeviceDocumentAccessEx;

#endif 	/* __IUPnPDeviceDocumentAccessEx_FWD_DEFINED__ */


#ifndef __IUPnPDeviceFinderCallback_FWD_DEFINED__
#define __IUPnPDeviceFinderCallback_FWD_DEFINED__
typedef interface IUPnPDeviceFinderCallback IUPnPDeviceFinderCallback;

#endif 	/* __IUPnPDeviceFinderCallback_FWD_DEFINED__ */


#ifndef __IUPnPDeviceFinderAddCallbackWithInterface_FWD_DEFINED__
#define __IUPnPDeviceFinderAddCallbackWithInterface_FWD_DEFINED__
typedef interface IUPnPDeviceFinderAddCallbackWithInterface IUPnPDeviceFinderAddCallbackWithInterface;

#endif 	/* __IUPnPDeviceFinderAddCallbackWithInterface_FWD_DEFINED__ */


#ifndef __IUPnPServiceCallback_FWD_DEFINED__
#define __IUPnPServiceCallback_FWD_DEFINED__
typedef interface IUPnPServiceCallback IUPnPServiceCallback;

#endif 	/* __IUPnPServiceCallback_FWD_DEFINED__ */


#ifndef __IUPnPAsyncResult_FWD_DEFINED__
#define __IUPnPAsyncResult_FWD_DEFINED__
typedef interface IUPnPAsyncResult IUPnPAsyncResult;

#endif 	/* __IUPnPAsyncResult_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_upnp_0000_0000 */
/* [local] */ 

//+-------------------------------------------------------------------------
//
//  Microsoft Windows
//  Copyright (c) Microsoft Corporation. All rights reserved.
//
//--------------------------------------------------------------------------
#include <winapifamily.h>
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
#pragma warning(push)
#pragma warning(disable:4001) 
#pragma once
#pragma warning(push)
#pragma warning(disable:4001) 
#pragma once
#pragma warning(pop)
#pragma warning(pop)
#pragma region Desktop Family
#pragma endregion


















#define UPNP_E_ROOT_ELEMENT_EXPECTED     MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0200)
#define UPNP_E_DEVICE_ELEMENT_EXPECTED   MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0201)
#define UPNP_E_SERVICE_ELEMENT_EXPECTED  MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0202)
#define UPNP_E_SERVICE_NODE_INCOMPLETE   MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0203)
#define UPNP_E_DEVICE_NODE_INCOMPLETE    MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0204)
#define UPNP_E_ICON_ELEMENT_EXPECTED     MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0205)
#define UPNP_E_ICON_NODE_INCOMPLETE      MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0206)
#define UPNP_E_INVALID_ACTION            MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0207)
#define UPNP_E_INVALID_ARGUMENTS         MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0208)
#define UPNP_E_OUT_OF_SYNC               MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0209)
#define UPNP_E_ACTION_REQUEST_FAILED     MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0210)
#define UPNP_E_TRANSPORT_ERROR           MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0211)
#define UPNP_E_VARIABLE_VALUE_UNKNOWN    MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0212)
#define UPNP_E_INVALID_VARIABLE          MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0213)
#define UPNP_E_DEVICE_ERROR              MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0214)
#define UPNP_E_PROTOCOL_ERROR            MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0215)
#define UPNP_E_ERROR_PROCESSING_RESPONSE MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0216)
#define UPNP_E_DEVICE_TIMEOUT            MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0217)
#define UPNP_E_INVALID_DOCUMENT          MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0500)
#define UPNP_E_EVENT_SUBSCRIPTION_FAILED MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0501)
#define FAULT_INVALID_ACTION             401
#define FAULT_INVALID_ARG                402
#define FAULT_INVALID_SEQUENCE_NUMBER    403
#define FAULT_INVALID_VARIABLE           404
#define FAULT_DEVICE_INTERNAL_ERROR      501
#define FAULT_ACTION_SPECIFIC_BASE       600
#define FAULT_ACTION_SPECIFIC_MAX        899
#define UPNP_E_ACTION_SPECIFIC_BASE      MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0300)
#define UPNP_E_ACTION_SPECIFIC_MAX       (UPNP_E_ACTION_SPECIFIC_BASE + (FAULT_ACTION_SPECIFIC_MAX - FAULT_ACTION_SPECIFIC_BASE))
#ifndef UPNP_ADDRESSFAMILY_IPv4
#define UPNP_ADDRESSFAMILY_IPv4		0x1
#endif
#ifndef UPNP_ADDRESSFAMILY_IPv6
#define UPNP_ADDRESSFAMILY_IPv6		0x2
#endif
#ifndef UPNP_ADDRESSFAMILY_BOTH
#define UPNP_ADDRESSFAMILY_BOTH		0x3
#endif
#ifndef UPNP_SERVICE_DELAY_SCPD_AND_SUBSCRIPTION
#define UPNP_SERVICE_DELAY_SCPD_AND_SUBSCRIPTION		0x1
#endif


extern RPC_IF_HANDLE __MIDL_itf_upnp_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_upnp_0000_0000_v0_0_s_ifspec;

#ifndef __IUPnPDeviceFinder_INTERFACE_DEFINED__
#define __IUPnPDeviceFinder_INTERFACE_DEFINED__

/* interface IUPnPDeviceFinder */
/* [nonextensible][unique][oleautomation][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IUPnPDeviceFinder;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("ADDA3D55-6F72-4319-BFF9-18600A539B10")
    IUPnPDeviceFinder : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FindByType( 
            /* [annotation][in] */ 
            _In_  BSTR bstrTypeURI,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][retval][out] */ 
            _Out_retval_  IUPnPDevices **pDevices) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateAsyncFind( 
            /* [annotation][in] */ 
            _In_  BSTR bstrTypeURI,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][in] */ 
            _In_  IUnknown *punkDeviceFinderCallback,
            /* [annotation][retval][out] */ 
            _Out_retval_  LONG *plFindData) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE StartAsyncFind( 
            /* [annotation][in] */ 
            _In_  LONG lFindData) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CancelAsyncFind( 
            /* [annotation][in] */ 
            _In_  LONG lFindData) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FindByUDN( 
            /* [annotation][in] */ 
            _In_  BSTR bstrUDN,
            /* [annotation][retval][out] */ 
            _Out_retval_  IUPnPDevice **pDevice) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IUPnPDeviceFinderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IUPnPDeviceFinder * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IUPnPDeviceFinder * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IUPnPDeviceFinder * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IUPnPDeviceFinder * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IUPnPDeviceFinder * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IUPnPDeviceFinder * This,
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
            IUPnPDeviceFinder * This,
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
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FindByType )( 
            __RPC__in IUPnPDeviceFinder * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrTypeURI,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][retval][out] */ 
            _Out_retval_  IUPnPDevices **pDevices);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateAsyncFind )( 
            __RPC__in IUPnPDeviceFinder * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrTypeURI,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][in] */ 
            _In_  IUnknown *punkDeviceFinderCallback,
            /* [annotation][retval][out] */ 
            _Out_retval_  LONG *plFindData);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StartAsyncFind )( 
            __RPC__in IUPnPDeviceFinder * This,
            /* [annotation][in] */ 
            _In_  LONG lFindData);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CancelAsyncFind )( 
            __RPC__in IUPnPDeviceFinder * This,
            /* [annotation][in] */ 
            _In_  LONG lFindData);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FindByUDN )( 
            __RPC__in IUPnPDeviceFinder * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrUDN,
            /* [annotation][retval][out] */ 
            _Out_retval_  IUPnPDevice **pDevice);
        
        END_INTERFACE
    } IUPnPDeviceFinderVtbl;

    interface IUPnPDeviceFinder
    {
        CONST_VTBL struct IUPnPDeviceFinderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IUPnPDeviceFinder_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IUPnPDeviceFinder_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IUPnPDeviceFinder_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IUPnPDeviceFinder_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IUPnPDeviceFinder_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IUPnPDeviceFinder_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IUPnPDeviceFinder_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IUPnPDeviceFinder_FindByType(This,bstrTypeURI,dwFlags,pDevices)	\
    ( (This)->lpVtbl -> FindByType(This,bstrTypeURI,dwFlags,pDevices) ) 

#define IUPnPDeviceFinder_CreateAsyncFind(This,bstrTypeURI,dwFlags,punkDeviceFinderCallback,plFindData)	\
    ( (This)->lpVtbl -> CreateAsyncFind(This,bstrTypeURI,dwFlags,punkDeviceFinderCallback,plFindData) ) 

#define IUPnPDeviceFinder_StartAsyncFind(This,lFindData)	\
    ( (This)->lpVtbl -> StartAsyncFind(This,lFindData) ) 

#define IUPnPDeviceFinder_CancelAsyncFind(This,lFindData)	\
    ( (This)->lpVtbl -> CancelAsyncFind(This,lFindData) ) 

#define IUPnPDeviceFinder_FindByUDN(This,bstrUDN,pDevice)	\
    ( (This)->lpVtbl -> FindByUDN(This,bstrUDN,pDevice) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IUPnPDeviceFinder_INTERFACE_DEFINED__ */


#ifndef __IUPnPAddressFamilyControl_INTERFACE_DEFINED__
#define __IUPnPAddressFamilyControl_INTERFACE_DEFINED__

/* interface IUPnPAddressFamilyControl */
/* [unique][oleautomation][uuid][object] */ 


EXTERN_C const IID IID_IUPnPAddressFamilyControl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E3BF6178-694E-459F-A5A6-191EA0FFA1C7")
    IUPnPAddressFamilyControl : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetAddressFamily( 
            /* [annotation][in] */ 
            _In_  LONG dwFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAddressFamily( 
            /* [annotation][out] */ 
            _Out_  LONG *pdwFlags) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IUPnPAddressFamilyControlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IUPnPAddressFamilyControl * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IUPnPAddressFamilyControl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IUPnPAddressFamilyControl * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetAddressFamily )( 
            __RPC__in IUPnPAddressFamilyControl * This,
            /* [annotation][in] */ 
            _In_  LONG dwFlags);
        
        HRESULT ( STDMETHODCALLTYPE *GetAddressFamily )( 
            __RPC__in IUPnPAddressFamilyControl * This,
            /* [annotation][out] */ 
            _Out_  LONG *pdwFlags);
        
        END_INTERFACE
    } IUPnPAddressFamilyControlVtbl;

    interface IUPnPAddressFamilyControl
    {
        CONST_VTBL struct IUPnPAddressFamilyControlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IUPnPAddressFamilyControl_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IUPnPAddressFamilyControl_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IUPnPAddressFamilyControl_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IUPnPAddressFamilyControl_SetAddressFamily(This,dwFlags)	\
    ( (This)->lpVtbl -> SetAddressFamily(This,dwFlags) ) 

#define IUPnPAddressFamilyControl_GetAddressFamily(This,pdwFlags)	\
    ( (This)->lpVtbl -> GetAddressFamily(This,pdwFlags) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IUPnPAddressFamilyControl_INTERFACE_DEFINED__ */


#ifndef __IUPnPHttpHeaderControl_INTERFACE_DEFINED__
#define __IUPnPHttpHeaderControl_INTERFACE_DEFINED__

/* interface IUPnPHttpHeaderControl */
/* [unique][oleautomation][uuid][object] */ 


EXTERN_C const IID IID_IUPnPHttpHeaderControl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0405AF4F-8B5C-447C-80F2-B75984A31F3C")
    IUPnPHttpHeaderControl : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AddRequestHeaders( 
            /* [annotation][in] */ 
            _In_  BSTR bstrHttpHeaders) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IUPnPHttpHeaderControlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IUPnPHttpHeaderControl * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IUPnPHttpHeaderControl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IUPnPHttpHeaderControl * This);
        
        HRESULT ( STDMETHODCALLTYPE *AddRequestHeaders )( 
            __RPC__in IUPnPHttpHeaderControl * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrHttpHeaders);
        
        END_INTERFACE
    } IUPnPHttpHeaderControlVtbl;

    interface IUPnPHttpHeaderControl
    {
        CONST_VTBL struct IUPnPHttpHeaderControlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IUPnPHttpHeaderControl_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IUPnPHttpHeaderControl_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IUPnPHttpHeaderControl_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IUPnPHttpHeaderControl_AddRequestHeaders(This,bstrHttpHeaders)	\
    ( (This)->lpVtbl -> AddRequestHeaders(This,bstrHttpHeaders) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IUPnPHttpHeaderControl_INTERFACE_DEFINED__ */


#ifndef __IUPnPDeviceFinderCallback_INTERFACE_DEFINED__
#define __IUPnPDeviceFinderCallback_INTERFACE_DEFINED__

/* interface IUPnPDeviceFinderCallback */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IUPnPDeviceFinderCallback;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("415A984A-88B3-49F3-92AF-0508BEDF0D6C")
    IUPnPDeviceFinderCallback : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE DeviceAdded( 
            /* [annotation][in] */ 
            _In_  LONG lFindData,
            /* [annotation][in] */ 
            _In_  IUPnPDevice *pDevice) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DeviceRemoved( 
            /* [annotation][in] */ 
            _In_  LONG lFindData,
            /* [annotation][in] */ 
            _In_  BSTR bstrUDN) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SearchComplete( 
            /* [annotation][in] */ 
            _In_  LONG lFindData) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IUPnPDeviceFinderCallbackVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IUPnPDeviceFinderCallback * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IUPnPDeviceFinderCallback * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IUPnPDeviceFinderCallback * This);
        
        HRESULT ( STDMETHODCALLTYPE *DeviceAdded )( 
            __RPC__in IUPnPDeviceFinderCallback * This,
            /* [annotation][in] */ 
            _In_  LONG lFindData,
            /* [annotation][in] */ 
            _In_  IUPnPDevice *pDevice);
        
        HRESULT ( STDMETHODCALLTYPE *DeviceRemoved )( 
            __RPC__in IUPnPDeviceFinderCallback * This,
            /* [annotation][in] */ 
            _In_  LONG lFindData,
            /* [annotation][in] */ 
            _In_  BSTR bstrUDN);
        
        HRESULT ( STDMETHODCALLTYPE *SearchComplete )( 
            __RPC__in IUPnPDeviceFinderCallback * This,
            /* [annotation][in] */ 
            _In_  LONG lFindData);
        
        END_INTERFACE
    } IUPnPDeviceFinderCallbackVtbl;

    interface IUPnPDeviceFinderCallback
    {
        CONST_VTBL struct IUPnPDeviceFinderCallbackVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IUPnPDeviceFinderCallback_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IUPnPDeviceFinderCallback_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IUPnPDeviceFinderCallback_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IUPnPDeviceFinderCallback_DeviceAdded(This,lFindData,pDevice)	\
    ( (This)->lpVtbl -> DeviceAdded(This,lFindData,pDevice) ) 

#define IUPnPDeviceFinderCallback_DeviceRemoved(This,lFindData,bstrUDN)	\
    ( (This)->lpVtbl -> DeviceRemoved(This,lFindData,bstrUDN) ) 

#define IUPnPDeviceFinderCallback_SearchComplete(This,lFindData)	\
    ( (This)->lpVtbl -> SearchComplete(This,lFindData) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IUPnPDeviceFinderCallback_INTERFACE_DEFINED__ */


#ifndef __IUPnPServices_INTERFACE_DEFINED__
#define __IUPnPServices_INTERFACE_DEFINED__

/* interface IUPnPServices */
/* [nonextensible][unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IUPnPServices;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3F8C8E9E-9A7A-4DC8-BC41-FF31FA374956")
    IUPnPServices : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plCount) = 0;
        
        virtual /* [helpstring][hidden][restricted][id][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [annotation][retval][out] */ 
            _Out_retval_  LPUNKNOWN *ppunk) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [annotation][in] */ 
            _In_  BSTR bstrServiceId,
            /* [annotation][retval][out] */ 
            _Out_retval_  IUPnPService **ppService) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IUPnPServicesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IUPnPServices * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IUPnPServices * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IUPnPServices * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IUPnPServices * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IUPnPServices * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IUPnPServices * This,
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
            IUPnPServices * This,
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
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            __RPC__in IUPnPServices * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plCount);
        
        /* [helpstring][hidden][restricted][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            __RPC__in IUPnPServices * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  LPUNKNOWN *ppunk);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            __RPC__in IUPnPServices * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrServiceId,
            /* [annotation][retval][out] */ 
            _Out_retval_  IUPnPService **ppService);
        
        END_INTERFACE
    } IUPnPServicesVtbl;

    interface IUPnPServices
    {
        CONST_VTBL struct IUPnPServicesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IUPnPServices_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IUPnPServices_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IUPnPServices_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IUPnPServices_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IUPnPServices_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IUPnPServices_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IUPnPServices_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IUPnPServices_get_Count(This,plCount)	\
    ( (This)->lpVtbl -> get_Count(This,plCount) ) 

#define IUPnPServices_get__NewEnum(This,ppunk)	\
    ( (This)->lpVtbl -> get__NewEnum(This,ppunk) ) 

#define IUPnPServices_get_Item(This,bstrServiceId,ppService)	\
    ( (This)->lpVtbl -> get_Item(This,bstrServiceId,ppService) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IUPnPServices_INTERFACE_DEFINED__ */


#ifndef __IUPnPService_INTERFACE_DEFINED__
#define __IUPnPService_INTERFACE_DEFINED__

/* interface IUPnPService */
/* [nonextensible][unique][oleautomation][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IUPnPService;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A295019C-DC65-47DD-90DC-7FE918A1AB44")
    IUPnPService : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE QueryStateVariable( 
            /* [annotation][in] */ 
            _In_  BSTR bstrVariableName,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT *pValue) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE InvokeAction( 
            /* [annotation][in] */ 
            _In_  BSTR bstrActionName,
            /* [annotation][in] */ 
            _In_  VARIANT vInActionArgs,
            /* [annotation][out][in] */ 
            _Inout_  VARIANT *pvOutActionArgs,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT *pvRetVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ServiceTypeIdentifier( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddCallback( 
            /* [annotation][in] */ 
            _In_  IUnknown *pUnkCallback) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Id( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrId) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LastTransportStatus( 
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plValue) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IUPnPServiceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IUPnPService * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IUPnPService * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IUPnPService * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IUPnPService * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IUPnPService * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IUPnPService * This,
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
            IUPnPService * This,
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
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *QueryStateVariable )( 
            __RPC__in IUPnPService * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrVariableName,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT *pValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *InvokeAction )( 
            __RPC__in IUPnPService * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrActionName,
            /* [annotation][in] */ 
            _In_  VARIANT vInActionArgs,
            /* [annotation][out][in] */ 
            _Inout_  VARIANT *pvOutActionArgs,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT *pvRetVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ServiceTypeIdentifier )( 
            __RPC__in IUPnPService * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddCallback )( 
            __RPC__in IUPnPService * This,
            /* [annotation][in] */ 
            _In_  IUnknown *pUnkCallback);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Id )( 
            __RPC__in IUPnPService * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrId);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LastTransportStatus )( 
            __RPC__in IUPnPService * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plValue);
        
        END_INTERFACE
    } IUPnPServiceVtbl;

    interface IUPnPService
    {
        CONST_VTBL struct IUPnPServiceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IUPnPService_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IUPnPService_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IUPnPService_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IUPnPService_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IUPnPService_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IUPnPService_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IUPnPService_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IUPnPService_QueryStateVariable(This,bstrVariableName,pValue)	\
    ( (This)->lpVtbl -> QueryStateVariable(This,bstrVariableName,pValue) ) 

#define IUPnPService_InvokeAction(This,bstrActionName,vInActionArgs,pvOutActionArgs,pvRetVal)	\
    ( (This)->lpVtbl -> InvokeAction(This,bstrActionName,vInActionArgs,pvOutActionArgs,pvRetVal) ) 

#define IUPnPService_get_ServiceTypeIdentifier(This,pVal)	\
    ( (This)->lpVtbl -> get_ServiceTypeIdentifier(This,pVal) ) 

#define IUPnPService_AddCallback(This,pUnkCallback)	\
    ( (This)->lpVtbl -> AddCallback(This,pUnkCallback) ) 

#define IUPnPService_get_Id(This,pbstrId)	\
    ( (This)->lpVtbl -> get_Id(This,pbstrId) ) 

#define IUPnPService_get_LastTransportStatus(This,plValue)	\
    ( (This)->lpVtbl -> get_LastTransportStatus(This,plValue) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IUPnPService_INTERFACE_DEFINED__ */


#ifndef __IUPnPAsyncResult_INTERFACE_DEFINED__
#define __IUPnPAsyncResult_INTERFACE_DEFINED__

/* interface IUPnPAsyncResult */
/* [unique][oleautomation][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IUPnPAsyncResult;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4D65FD08-D13E-4274-9C8B-DD8D028C8644")
    IUPnPAsyncResult : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AsyncOperationComplete( 
            /* [annotation][in] */ 
            _In_  ULONG64 ullRequestID) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IUPnPAsyncResultVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IUPnPAsyncResult * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IUPnPAsyncResult * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IUPnPAsyncResult * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AsyncOperationComplete )( 
            __RPC__in IUPnPAsyncResult * This,
            /* [annotation][in] */ 
            _In_  ULONG64 ullRequestID);
        
        END_INTERFACE
    } IUPnPAsyncResultVtbl;

    interface IUPnPAsyncResult
    {
        CONST_VTBL struct IUPnPAsyncResultVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IUPnPAsyncResult_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IUPnPAsyncResult_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IUPnPAsyncResult_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IUPnPAsyncResult_AsyncOperationComplete(This,ullRequestID)	\
    ( (This)->lpVtbl -> AsyncOperationComplete(This,ullRequestID) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IUPnPAsyncResult_INTERFACE_DEFINED__ */


#ifndef __IUPnPServiceAsync_INTERFACE_DEFINED__
#define __IUPnPServiceAsync_INTERFACE_DEFINED__

/* interface IUPnPServiceAsync */
/* [unique][oleautomation][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IUPnPServiceAsync;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("098BDAF5-5EC1-49e7-A260-B3A11DD8680C")
    IUPnPServiceAsync : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE BeginInvokeAction( 
            /* [annotation][in] */ 
            _In_  BSTR bstrActionName,
            /* [annotation][in] */ 
            _In_  VARIANT vInActionArgs,
            /* [annotation][in] */ 
            _In_  IUPnPAsyncResult *pAsyncResult,
            /* [annotation][out] */ 
            _Out_  PULONG64 pullRequestID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EndInvokeAction( 
            /* [annotation][in] */ 
            _In_  ULONG64 ullRequestID,
            /* [annotation][out][in] */ 
            _Inout_  VARIANT *pvOutActionArgs,
            /* [annotation][out][in] */ 
            _Inout_  VARIANT *pvRetVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE BeginQueryStateVariable( 
            /* [annotation][in] */ 
            _In_  BSTR bstrVariableName,
            /* [annotation][in] */ 
            _In_  IUPnPAsyncResult *pAsyncResult,
            /* [annotation][out] */ 
            _Out_  PULONG64 pullRequestID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EndQueryStateVariable( 
            /* [annotation][in] */ 
            _In_  ULONG64 ullRequestID,
            /* [annotation][out][in] */ 
            _Inout_  VARIANT *pValue) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE BeginSubscribeToEvents( 
            /* [annotation][in] */ 
            _In_  IUnknown *pUnkCallback,
            /* [annotation][in] */ 
            _In_  IUPnPAsyncResult *pAsyncResult,
            /* [annotation][out] */ 
            _Out_  PULONG64 pullRequestID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EndSubscribeToEvents( 
            /* [annotation][in] */ 
            _In_  ULONG64 ullRequestID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE BeginSCPDDownload( 
            /* [annotation][in] */ 
            _In_  IUPnPAsyncResult *pAsyncResult,
            /* [annotation][out] */ 
            _Out_  PULONG64 pullRequestID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EndSCPDDownload( 
            /* [annotation][in] */ 
            _In_  ULONG64 ullRequestID,
            /* [annotation][out] */ 
            _Out_  BSTR *pbstrSCPDDoc) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CancelAsyncOperation( 
            /* [annotation][in] */ 
            _In_  ULONG64 ullRequestID) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IUPnPServiceAsyncVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IUPnPServiceAsync * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IUPnPServiceAsync * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IUPnPServiceAsync * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *BeginInvokeAction )( 
            __RPC__in IUPnPServiceAsync * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrActionName,
            /* [annotation][in] */ 
            _In_  VARIANT vInActionArgs,
            /* [annotation][in] */ 
            _In_  IUPnPAsyncResult *pAsyncResult,
            /* [annotation][out] */ 
            _Out_  PULONG64 pullRequestID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EndInvokeAction )( 
            __RPC__in IUPnPServiceAsync * This,
            /* [annotation][in] */ 
            _In_  ULONG64 ullRequestID,
            /* [annotation][out][in] */ 
            _Inout_  VARIANT *pvOutActionArgs,
            /* [annotation][out][in] */ 
            _Inout_  VARIANT *pvRetVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *BeginQueryStateVariable )( 
            __RPC__in IUPnPServiceAsync * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrVariableName,
            /* [annotation][in] */ 
            _In_  IUPnPAsyncResult *pAsyncResult,
            /* [annotation][out] */ 
            _Out_  PULONG64 pullRequestID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EndQueryStateVariable )( 
            __RPC__in IUPnPServiceAsync * This,
            /* [annotation][in] */ 
            _In_  ULONG64 ullRequestID,
            /* [annotation][out][in] */ 
            _Inout_  VARIANT *pValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *BeginSubscribeToEvents )( 
            __RPC__in IUPnPServiceAsync * This,
            /* [annotation][in] */ 
            _In_  IUnknown *pUnkCallback,
            /* [annotation][in] */ 
            _In_  IUPnPAsyncResult *pAsyncResult,
            /* [annotation][out] */ 
            _Out_  PULONG64 pullRequestID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EndSubscribeToEvents )( 
            __RPC__in IUPnPServiceAsync * This,
            /* [annotation][in] */ 
            _In_  ULONG64 ullRequestID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *BeginSCPDDownload )( 
            __RPC__in IUPnPServiceAsync * This,
            /* [annotation][in] */ 
            _In_  IUPnPAsyncResult *pAsyncResult,
            /* [annotation][out] */ 
            _Out_  PULONG64 pullRequestID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EndSCPDDownload )( 
            __RPC__in IUPnPServiceAsync * This,
            /* [annotation][in] */ 
            _In_  ULONG64 ullRequestID,
            /* [annotation][out] */ 
            _Out_  BSTR *pbstrSCPDDoc);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CancelAsyncOperation )( 
            __RPC__in IUPnPServiceAsync * This,
            /* [annotation][in] */ 
            _In_  ULONG64 ullRequestID);
        
        END_INTERFACE
    } IUPnPServiceAsyncVtbl;

    interface IUPnPServiceAsync
    {
        CONST_VTBL struct IUPnPServiceAsyncVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IUPnPServiceAsync_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IUPnPServiceAsync_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IUPnPServiceAsync_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IUPnPServiceAsync_BeginInvokeAction(This,bstrActionName,vInActionArgs,pAsyncResult,pullRequestID)	\
    ( (This)->lpVtbl -> BeginInvokeAction(This,bstrActionName,vInActionArgs,pAsyncResult,pullRequestID) ) 

#define IUPnPServiceAsync_EndInvokeAction(This,ullRequestID,pvOutActionArgs,pvRetVal)	\
    ( (This)->lpVtbl -> EndInvokeAction(This,ullRequestID,pvOutActionArgs,pvRetVal) ) 

#define IUPnPServiceAsync_BeginQueryStateVariable(This,bstrVariableName,pAsyncResult,pullRequestID)	\
    ( (This)->lpVtbl -> BeginQueryStateVariable(This,bstrVariableName,pAsyncResult,pullRequestID) ) 

#define IUPnPServiceAsync_EndQueryStateVariable(This,ullRequestID,pValue)	\
    ( (This)->lpVtbl -> EndQueryStateVariable(This,ullRequestID,pValue) ) 

#define IUPnPServiceAsync_BeginSubscribeToEvents(This,pUnkCallback,pAsyncResult,pullRequestID)	\
    ( (This)->lpVtbl -> BeginSubscribeToEvents(This,pUnkCallback,pAsyncResult,pullRequestID) ) 

#define IUPnPServiceAsync_EndSubscribeToEvents(This,ullRequestID)	\
    ( (This)->lpVtbl -> EndSubscribeToEvents(This,ullRequestID) ) 

#define IUPnPServiceAsync_BeginSCPDDownload(This,pAsyncResult,pullRequestID)	\
    ( (This)->lpVtbl -> BeginSCPDDownload(This,pAsyncResult,pullRequestID) ) 

#define IUPnPServiceAsync_EndSCPDDownload(This,ullRequestID,pbstrSCPDDoc)	\
    ( (This)->lpVtbl -> EndSCPDDownload(This,ullRequestID,pbstrSCPDDoc) ) 

#define IUPnPServiceAsync_CancelAsyncOperation(This,ullRequestID)	\
    ( (This)->lpVtbl -> CancelAsyncOperation(This,ullRequestID) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IUPnPServiceAsync_INTERFACE_DEFINED__ */


#ifndef __IUPnPServiceCallback_INTERFACE_DEFINED__
#define __IUPnPServiceCallback_INTERFACE_DEFINED__

/* interface IUPnPServiceCallback */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IUPnPServiceCallback;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("31fadca9-ab73-464b-b67d-5c1d0f83c8b8")
    IUPnPServiceCallback : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE StateVariableChanged( 
            /* [annotation][in] */ 
            _In_  IUPnPService *pus,
            /* [annotation][in] */ 
            _In_  LPCWSTR pcwszStateVarName,
            /* [annotation][in] */ 
            _In_  VARIANT vaValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ServiceInstanceDied( 
            /* [annotation][in] */ 
            _In_  IUPnPService *pus) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IUPnPServiceCallbackVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IUPnPServiceCallback * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IUPnPServiceCallback * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IUPnPServiceCallback * This);
        
        HRESULT ( STDMETHODCALLTYPE *StateVariableChanged )( 
            __RPC__in IUPnPServiceCallback * This,
            /* [annotation][in] */ 
            _In_  IUPnPService *pus,
            /* [annotation][in] */ 
            _In_  LPCWSTR pcwszStateVarName,
            /* [annotation][in] */ 
            _In_  VARIANT vaValue);
        
        HRESULT ( STDMETHODCALLTYPE *ServiceInstanceDied )( 
            __RPC__in IUPnPServiceCallback * This,
            /* [annotation][in] */ 
            _In_  IUPnPService *pus);
        
        END_INTERFACE
    } IUPnPServiceCallbackVtbl;

    interface IUPnPServiceCallback
    {
        CONST_VTBL struct IUPnPServiceCallbackVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IUPnPServiceCallback_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IUPnPServiceCallback_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IUPnPServiceCallback_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IUPnPServiceCallback_StateVariableChanged(This,pus,pcwszStateVarName,vaValue)	\
    ( (This)->lpVtbl -> StateVariableChanged(This,pus,pcwszStateVarName,vaValue) ) 

#define IUPnPServiceCallback_ServiceInstanceDied(This,pus)	\
    ( (This)->lpVtbl -> ServiceInstanceDied(This,pus) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IUPnPServiceCallback_INTERFACE_DEFINED__ */


#ifndef __IUPnPServiceEnumProperty_INTERFACE_DEFINED__
#define __IUPnPServiceEnumProperty_INTERFACE_DEFINED__

/* interface IUPnPServiceEnumProperty */
/* [unique][oleautomation][uuid][object] */ 


EXTERN_C const IID IID_IUPnPServiceEnumProperty;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("38873B37-91BB-49f4-B249-2E8EFBB8A816")
    IUPnPServiceEnumProperty : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetServiceEnumProperty( 
            /* [annotation][in] */ 
            _In_  DWORD dwMask) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IUPnPServiceEnumPropertyVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IUPnPServiceEnumProperty * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IUPnPServiceEnumProperty * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IUPnPServiceEnumProperty * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetServiceEnumProperty )( 
            __RPC__in IUPnPServiceEnumProperty * This,
            /* [annotation][in] */ 
            _In_  DWORD dwMask);
        
        END_INTERFACE
    } IUPnPServiceEnumPropertyVtbl;

    interface IUPnPServiceEnumProperty
    {
        CONST_VTBL struct IUPnPServiceEnumPropertyVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IUPnPServiceEnumProperty_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IUPnPServiceEnumProperty_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IUPnPServiceEnumProperty_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IUPnPServiceEnumProperty_SetServiceEnumProperty(This,dwMask)	\
    ( (This)->lpVtbl -> SetServiceEnumProperty(This,dwMask) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IUPnPServiceEnumProperty_INTERFACE_DEFINED__ */


#ifndef __IUPnPServiceDocumentAccess_INTERFACE_DEFINED__
#define __IUPnPServiceDocumentAccess_INTERFACE_DEFINED__

/* interface IUPnPServiceDocumentAccess */
/* [unique][oleautomation][uuid][object] */ 


EXTERN_C const IID IID_IUPnPServiceDocumentAccess;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("21905529-0A5E-4589-825D-7E6D87EA6998")
    IUPnPServiceDocumentAccess : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetDocumentURL( 
            /* [annotation][out] */ 
            _Out_  BSTR *pbstrDocUrl) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDocument( 
            /* [annotation][out] */ 
            _Out_  BSTR *pbstrDoc) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IUPnPServiceDocumentAccessVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IUPnPServiceDocumentAccess * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IUPnPServiceDocumentAccess * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IUPnPServiceDocumentAccess * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetDocumentURL )( 
            __RPC__in IUPnPServiceDocumentAccess * This,
            /* [annotation][out] */ 
            _Out_  BSTR *pbstrDocUrl);
        
        HRESULT ( STDMETHODCALLTYPE *GetDocument )( 
            __RPC__in IUPnPServiceDocumentAccess * This,
            /* [annotation][out] */ 
            _Out_  BSTR *pbstrDoc);
        
        END_INTERFACE
    } IUPnPServiceDocumentAccessVtbl;

    interface IUPnPServiceDocumentAccess
    {
        CONST_VTBL struct IUPnPServiceDocumentAccessVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IUPnPServiceDocumentAccess_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IUPnPServiceDocumentAccess_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IUPnPServiceDocumentAccess_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IUPnPServiceDocumentAccess_GetDocumentURL(This,pbstrDocUrl)	\
    ( (This)->lpVtbl -> GetDocumentURL(This,pbstrDocUrl) ) 

#define IUPnPServiceDocumentAccess_GetDocument(This,pbstrDoc)	\
    ( (This)->lpVtbl -> GetDocument(This,pbstrDoc) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IUPnPServiceDocumentAccess_INTERFACE_DEFINED__ */


#ifndef __IUPnPDevices_INTERFACE_DEFINED__
#define __IUPnPDevices_INTERFACE_DEFINED__

/* interface IUPnPDevices */
/* [nonextensible][unique][oleautomation][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IUPnPDevices;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("FDBC0C73-BDA3-4C66-AC4F-F2D96FDAD68C")
    IUPnPDevices : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plCount) = 0;
        
        virtual /* [helpstring][hidden][restricted][id][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [annotation][retval][out] */ 
            _Out_retval_  LPUNKNOWN *ppunk) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [annotation][in] */ 
            _In_  BSTR bstrUDN,
            /* [annotation][retval][out] */ 
            _Out_retval_  IUPnPDevice **ppDevice) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IUPnPDevicesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IUPnPDevices * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IUPnPDevices * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IUPnPDevices * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IUPnPDevices * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IUPnPDevices * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IUPnPDevices * This,
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
            IUPnPDevices * This,
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
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            __RPC__in IUPnPDevices * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plCount);
        
        /* [helpstring][hidden][restricted][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            __RPC__in IUPnPDevices * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  LPUNKNOWN *ppunk);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            __RPC__in IUPnPDevices * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrUDN,
            /* [annotation][retval][out] */ 
            _Out_retval_  IUPnPDevice **ppDevice);
        
        END_INTERFACE
    } IUPnPDevicesVtbl;

    interface IUPnPDevices
    {
        CONST_VTBL struct IUPnPDevicesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IUPnPDevices_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IUPnPDevices_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IUPnPDevices_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IUPnPDevices_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IUPnPDevices_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IUPnPDevices_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IUPnPDevices_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IUPnPDevices_get_Count(This,plCount)	\
    ( (This)->lpVtbl -> get_Count(This,plCount) ) 

#define IUPnPDevices_get__NewEnum(This,ppunk)	\
    ( (This)->lpVtbl -> get__NewEnum(This,ppunk) ) 

#define IUPnPDevices_get_Item(This,bstrUDN,ppDevice)	\
    ( (This)->lpVtbl -> get_Item(This,bstrUDN,ppDevice) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IUPnPDevices_INTERFACE_DEFINED__ */


#ifndef __IUPnPDevice_INTERFACE_DEFINED__
#define __IUPnPDevice_INTERFACE_DEFINED__

/* interface IUPnPDevice */
/* [nonextensible][unique][oleautomation][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IUPnPDevice;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3D44D0D1-98C9-4889-ACD1-F9D674BF2221")
    IUPnPDevice : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IsRootDevice( 
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pvarb) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RootDevice( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IUPnPDevice **ppudRootDevice) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ParentDevice( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IUPnPDevice **ppudDeviceParent) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_HasChildren( 
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pvarb) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Children( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IUPnPDevices **ppudChildren) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UniqueDeviceName( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstr) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FriendlyName( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstr) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Type( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstr) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PresentationURL( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstr) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ManufacturerName( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstr) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ManufacturerURL( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstr) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ModelName( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstr) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ModelNumber( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstr) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Description( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstr) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ModelURL( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstr) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UPC( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstr) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SerialNumber( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstr) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IconURL( 
            /* [annotation][in] */ 
            _In_  BSTR bstrEncodingFormat,
            /* [annotation][in] */ 
            _In_  LONG lSizeX,
            /* [annotation][in] */ 
            _In_  LONG lSizeY,
            /* [annotation][in] */ 
            _In_  LONG lBitDepth,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrIconURL) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Services( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IUPnPServices **ppusServices) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IUPnPDeviceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IUPnPDevice * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IUPnPDevice * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IUPnPDevice * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IUPnPDevice * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IUPnPDevice * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IUPnPDevice * This,
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
            IUPnPDevice * This,
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
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsRootDevice )( 
            __RPC__in IUPnPDevice * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pvarb);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RootDevice )( 
            __RPC__in IUPnPDevice * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IUPnPDevice **ppudRootDevice);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ParentDevice )( 
            __RPC__in IUPnPDevice * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IUPnPDevice **ppudDeviceParent);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HasChildren )( 
            __RPC__in IUPnPDevice * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pvarb);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Children )( 
            __RPC__in IUPnPDevice * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IUPnPDevices **ppudChildren);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UniqueDeviceName )( 
            __RPC__in IUPnPDevice * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FriendlyName )( 
            __RPC__in IUPnPDevice * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Type )( 
            __RPC__in IUPnPDevice * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PresentationURL )( 
            __RPC__in IUPnPDevice * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ManufacturerName )( 
            __RPC__in IUPnPDevice * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ManufacturerURL )( 
            __RPC__in IUPnPDevice * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ModelName )( 
            __RPC__in IUPnPDevice * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ModelNumber )( 
            __RPC__in IUPnPDevice * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Description )( 
            __RPC__in IUPnPDevice * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ModelURL )( 
            __RPC__in IUPnPDevice * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UPC )( 
            __RPC__in IUPnPDevice * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SerialNumber )( 
            __RPC__in IUPnPDevice * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IconURL )( 
            __RPC__in IUPnPDevice * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrEncodingFormat,
            /* [annotation][in] */ 
            _In_  LONG lSizeX,
            /* [annotation][in] */ 
            _In_  LONG lSizeY,
            /* [annotation][in] */ 
            _In_  LONG lBitDepth,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrIconURL);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Services )( 
            __RPC__in IUPnPDevice * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IUPnPServices **ppusServices);
        
        END_INTERFACE
    } IUPnPDeviceVtbl;

    interface IUPnPDevice
    {
        CONST_VTBL struct IUPnPDeviceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IUPnPDevice_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IUPnPDevice_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IUPnPDevice_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IUPnPDevice_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IUPnPDevice_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IUPnPDevice_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IUPnPDevice_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IUPnPDevice_get_IsRootDevice(This,pvarb)	\
    ( (This)->lpVtbl -> get_IsRootDevice(This,pvarb) ) 

#define IUPnPDevice_get_RootDevice(This,ppudRootDevice)	\
    ( (This)->lpVtbl -> get_RootDevice(This,ppudRootDevice) ) 

#define IUPnPDevice_get_ParentDevice(This,ppudDeviceParent)	\
    ( (This)->lpVtbl -> get_ParentDevice(This,ppudDeviceParent) ) 

#define IUPnPDevice_get_HasChildren(This,pvarb)	\
    ( (This)->lpVtbl -> get_HasChildren(This,pvarb) ) 

#define IUPnPDevice_get_Children(This,ppudChildren)	\
    ( (This)->lpVtbl -> get_Children(This,ppudChildren) ) 

#define IUPnPDevice_get_UniqueDeviceName(This,pbstr)	\
    ( (This)->lpVtbl -> get_UniqueDeviceName(This,pbstr) ) 

#define IUPnPDevice_get_FriendlyName(This,pbstr)	\
    ( (This)->lpVtbl -> get_FriendlyName(This,pbstr) ) 

#define IUPnPDevice_get_Type(This,pbstr)	\
    ( (This)->lpVtbl -> get_Type(This,pbstr) ) 

#define IUPnPDevice_get_PresentationURL(This,pbstr)	\
    ( (This)->lpVtbl -> get_PresentationURL(This,pbstr) ) 

#define IUPnPDevice_get_ManufacturerName(This,pbstr)	\
    ( (This)->lpVtbl -> get_ManufacturerName(This,pbstr) ) 

#define IUPnPDevice_get_ManufacturerURL(This,pbstr)	\
    ( (This)->lpVtbl -> get_ManufacturerURL(This,pbstr) ) 

#define IUPnPDevice_get_ModelName(This,pbstr)	\
    ( (This)->lpVtbl -> get_ModelName(This,pbstr) ) 

#define IUPnPDevice_get_ModelNumber(This,pbstr)	\
    ( (This)->lpVtbl -> get_ModelNumber(This,pbstr) ) 

#define IUPnPDevice_get_Description(This,pbstr)	\
    ( (This)->lpVtbl -> get_Description(This,pbstr) ) 

#define IUPnPDevice_get_ModelURL(This,pbstr)	\
    ( (This)->lpVtbl -> get_ModelURL(This,pbstr) ) 

#define IUPnPDevice_get_UPC(This,pbstr)	\
    ( (This)->lpVtbl -> get_UPC(This,pbstr) ) 

#define IUPnPDevice_get_SerialNumber(This,pbstr)	\
    ( (This)->lpVtbl -> get_SerialNumber(This,pbstr) ) 

#define IUPnPDevice_IconURL(This,bstrEncodingFormat,lSizeX,lSizeY,lBitDepth,pbstrIconURL)	\
    ( (This)->lpVtbl -> IconURL(This,bstrEncodingFormat,lSizeX,lSizeY,lBitDepth,pbstrIconURL) ) 

#define IUPnPDevice_get_Services(This,ppusServices)	\
    ( (This)->lpVtbl -> get_Services(This,ppusServices) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IUPnPDevice_INTERFACE_DEFINED__ */


#ifndef __IUPnPDeviceDocumentAccess_INTERFACE_DEFINED__
#define __IUPnPDeviceDocumentAccess_INTERFACE_DEFINED__

/* interface IUPnPDeviceDocumentAccess */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IUPnPDeviceDocumentAccess;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E7772804-3287-418e-9072-CF2B47238981")
    IUPnPDeviceDocumentAccess : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetDocumentURL( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrDocument) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IUPnPDeviceDocumentAccessVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IUPnPDeviceDocumentAccess * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IUPnPDeviceDocumentAccess * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IUPnPDeviceDocumentAccess * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetDocumentURL )( 
            __RPC__in IUPnPDeviceDocumentAccess * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrDocument);
        
        END_INTERFACE
    } IUPnPDeviceDocumentAccessVtbl;

    interface IUPnPDeviceDocumentAccess
    {
        CONST_VTBL struct IUPnPDeviceDocumentAccessVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IUPnPDeviceDocumentAccess_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IUPnPDeviceDocumentAccess_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IUPnPDeviceDocumentAccess_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IUPnPDeviceDocumentAccess_GetDocumentURL(This,pbstrDocument)	\
    ( (This)->lpVtbl -> GetDocumentURL(This,pbstrDocument) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IUPnPDeviceDocumentAccess_INTERFACE_DEFINED__ */


#ifndef __IUPnPDeviceDocumentAccessEx_INTERFACE_DEFINED__
#define __IUPnPDeviceDocumentAccessEx_INTERFACE_DEFINED__

/* interface IUPnPDeviceDocumentAccessEx */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IUPnPDeviceDocumentAccessEx;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C4BC4050-6178-4BD1-A4B8-6398321F3247")
    IUPnPDeviceDocumentAccessEx : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetDocument( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrDocument) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IUPnPDeviceDocumentAccessExVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IUPnPDeviceDocumentAccessEx * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IUPnPDeviceDocumentAccessEx * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IUPnPDeviceDocumentAccessEx * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetDocument )( 
            __RPC__in IUPnPDeviceDocumentAccessEx * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrDocument);
        
        END_INTERFACE
    } IUPnPDeviceDocumentAccessExVtbl;

    interface IUPnPDeviceDocumentAccessEx
    {
        CONST_VTBL struct IUPnPDeviceDocumentAccessExVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IUPnPDeviceDocumentAccessEx_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IUPnPDeviceDocumentAccessEx_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IUPnPDeviceDocumentAccessEx_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IUPnPDeviceDocumentAccessEx_GetDocument(This,pbstrDocument)	\
    ( (This)->lpVtbl -> GetDocument(This,pbstrDocument) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IUPnPDeviceDocumentAccessEx_INTERFACE_DEFINED__ */


#ifndef __IUPnPDescriptionDocument_INTERFACE_DEFINED__
#define __IUPnPDescriptionDocument_INTERFACE_DEFINED__

/* interface IUPnPDescriptionDocument */
/* [nonextensible][unique][oleautomation][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IUPnPDescriptionDocument;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("11d1c1b2-7daa-4c9e-9595-7f82ed206d1e")
    IUPnPDescriptionDocument : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ReadyState( 
            /* [annotation][retval][out] */ 
            _Out_retval_  LONG *plReadyState) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Load( 
            /* [annotation][in] */ 
            _In_  BSTR bstrUrl) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LoadAsync( 
            /* [annotation][in] */ 
            _In_  BSTR bstrUrl,
            /* [annotation][in] */ 
            _In_  IUnknown *punkCallback) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LoadResult( 
            /* [annotation][retval][out] */ 
            _Out_retval_  long *phrError) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Abort( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RootDevice( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IUPnPDevice **ppudRootDevice) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeviceByUDN( 
            /* [annotation][in] */ 
            _In_  BSTR bstrUDN,
            /* [annotation][retval][out] */ 
            _Out_retval_  IUPnPDevice **ppudDevice) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IUPnPDescriptionDocumentVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IUPnPDescriptionDocument * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IUPnPDescriptionDocument * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IUPnPDescriptionDocument * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IUPnPDescriptionDocument * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IUPnPDescriptionDocument * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IUPnPDescriptionDocument * This,
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
            IUPnPDescriptionDocument * This,
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
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ReadyState )( 
            __RPC__in IUPnPDescriptionDocument * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  LONG *plReadyState);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Load )( 
            __RPC__in IUPnPDescriptionDocument * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrUrl);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LoadAsync )( 
            __RPC__in IUPnPDescriptionDocument * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrUrl,
            /* [annotation][in] */ 
            _In_  IUnknown *punkCallback);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LoadResult )( 
            __RPC__in IUPnPDescriptionDocument * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *phrError);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Abort )( 
            __RPC__in IUPnPDescriptionDocument * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RootDevice )( 
            __RPC__in IUPnPDescriptionDocument * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IUPnPDevice **ppudRootDevice);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeviceByUDN )( 
            __RPC__in IUPnPDescriptionDocument * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrUDN,
            /* [annotation][retval][out] */ 
            _Out_retval_  IUPnPDevice **ppudDevice);
        
        END_INTERFACE
    } IUPnPDescriptionDocumentVtbl;

    interface IUPnPDescriptionDocument
    {
        CONST_VTBL struct IUPnPDescriptionDocumentVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IUPnPDescriptionDocument_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IUPnPDescriptionDocument_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IUPnPDescriptionDocument_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IUPnPDescriptionDocument_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IUPnPDescriptionDocument_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IUPnPDescriptionDocument_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IUPnPDescriptionDocument_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IUPnPDescriptionDocument_get_ReadyState(This,plReadyState)	\
    ( (This)->lpVtbl -> get_ReadyState(This,plReadyState) ) 

#define IUPnPDescriptionDocument_Load(This,bstrUrl)	\
    ( (This)->lpVtbl -> Load(This,bstrUrl) ) 

#define IUPnPDescriptionDocument_LoadAsync(This,bstrUrl,punkCallback)	\
    ( (This)->lpVtbl -> LoadAsync(This,bstrUrl,punkCallback) ) 

#define IUPnPDescriptionDocument_get_LoadResult(This,phrError)	\
    ( (This)->lpVtbl -> get_LoadResult(This,phrError) ) 

#define IUPnPDescriptionDocument_Abort(This)	\
    ( (This)->lpVtbl -> Abort(This) ) 

#define IUPnPDescriptionDocument_RootDevice(This,ppudRootDevice)	\
    ( (This)->lpVtbl -> RootDevice(This,ppudRootDevice) ) 

#define IUPnPDescriptionDocument_DeviceByUDN(This,bstrUDN,ppudDevice)	\
    ( (This)->lpVtbl -> DeviceByUDN(This,bstrUDN,ppudDevice) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IUPnPDescriptionDocument_INTERFACE_DEFINED__ */


#ifndef __IUPnPDeviceFinderAddCallbackWithInterface_INTERFACE_DEFINED__
#define __IUPnPDeviceFinderAddCallbackWithInterface_INTERFACE_DEFINED__

/* interface IUPnPDeviceFinderAddCallbackWithInterface */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IUPnPDeviceFinderAddCallbackWithInterface;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("983dfc0b-1796-44df-8975-ca545b620ee5")
    IUPnPDeviceFinderAddCallbackWithInterface : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE DeviceAddedWithInterface( 
            /* [annotation][in] */ 
            _In_  LONG lFindData,
            /* [annotation][in] */ 
            _In_  IUPnPDevice *pDevice,
            /* [annotation][in] */ 
            _In_  GUID *pguidInterface) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IUPnPDeviceFinderAddCallbackWithInterfaceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IUPnPDeviceFinderAddCallbackWithInterface * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IUPnPDeviceFinderAddCallbackWithInterface * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IUPnPDeviceFinderAddCallbackWithInterface * This);
        
        HRESULT ( STDMETHODCALLTYPE *DeviceAddedWithInterface )( 
            __RPC__in IUPnPDeviceFinderAddCallbackWithInterface * This,
            /* [annotation][in] */ 
            _In_  LONG lFindData,
            /* [annotation][in] */ 
            _In_  IUPnPDevice *pDevice,
            /* [annotation][in] */ 
            _In_  GUID *pguidInterface);
        
        END_INTERFACE
    } IUPnPDeviceFinderAddCallbackWithInterfaceVtbl;

    interface IUPnPDeviceFinderAddCallbackWithInterface
    {
        CONST_VTBL struct IUPnPDeviceFinderAddCallbackWithInterfaceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IUPnPDeviceFinderAddCallbackWithInterface_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IUPnPDeviceFinderAddCallbackWithInterface_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IUPnPDeviceFinderAddCallbackWithInterface_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IUPnPDeviceFinderAddCallbackWithInterface_DeviceAddedWithInterface(This,lFindData,pDevice,pguidInterface)	\
    ( (This)->lpVtbl -> DeviceAddedWithInterface(This,lFindData,pDevice,pguidInterface) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IUPnPDeviceFinderAddCallbackWithInterface_INTERFACE_DEFINED__ */


#ifndef __IUPnPDescriptionDocumentCallback_INTERFACE_DEFINED__
#define __IUPnPDescriptionDocumentCallback_INTERFACE_DEFINED__

/* interface IUPnPDescriptionDocumentCallback */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IUPnPDescriptionDocumentCallback;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("77394c69-5486-40d6-9bc3-4991983e02da")
    IUPnPDescriptionDocumentCallback : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE LoadComplete( 
            /* [annotation][in] */ 
            _In_  HRESULT hrLoadResult) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IUPnPDescriptionDocumentCallbackVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IUPnPDescriptionDocumentCallback * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IUPnPDescriptionDocumentCallback * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IUPnPDescriptionDocumentCallback * This);
        
        HRESULT ( STDMETHODCALLTYPE *LoadComplete )( 
            __RPC__in IUPnPDescriptionDocumentCallback * This,
            /* [annotation][in] */ 
            _In_  HRESULT hrLoadResult);
        
        END_INTERFACE
    } IUPnPDescriptionDocumentCallbackVtbl;

    interface IUPnPDescriptionDocumentCallback
    {
        CONST_VTBL struct IUPnPDescriptionDocumentCallbackVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IUPnPDescriptionDocumentCallback_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IUPnPDescriptionDocumentCallback_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IUPnPDescriptionDocumentCallback_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IUPnPDescriptionDocumentCallback_LoadComplete(This,hrLoadResult)	\
    ( (This)->lpVtbl -> LoadComplete(This,hrLoadResult) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IUPnPDescriptionDocumentCallback_INTERFACE_DEFINED__ */



#ifndef __UPNPLib_LIBRARY_DEFINED__
#define __UPNPLib_LIBRARY_DEFINED__

/* library UPNPLib */
/* [helpstring][version][uuid] */ 








EXTERN_C const IID LIBID_UPNPLib;

EXTERN_C const CLSID CLSID_UPnPDeviceFinder;

#ifdef __cplusplus

class DECLSPEC_UUID("E2085F28-FEB7-404A-B8E7-E659BDEAAA02")
UPnPDeviceFinder;
#endif

EXTERN_C const CLSID CLSID_UPnPDevices;

#ifdef __cplusplus

class DECLSPEC_UUID("B9E84FFD-AD3C-40A4-B835-0882EBCBAAA8")
UPnPDevices;
#endif

EXTERN_C const CLSID CLSID_UPnPDevice;

#ifdef __cplusplus

class DECLSPEC_UUID("A32552C5-BA61-457A-B59A-A2561E125E33")
UPnPDevice;
#endif

EXTERN_C const CLSID CLSID_UPnPServices;

#ifdef __cplusplus

class DECLSPEC_UUID("C0BC4B4A-A406-4EFC-932F-B8546B8100CC")
UPnPServices;
#endif

EXTERN_C const CLSID CLSID_UPnPService;

#ifdef __cplusplus

class DECLSPEC_UUID("C624BA95-FBCB-4409-8C03-8CCEEC533EF1")
UPnPService;
#endif

EXTERN_C const CLSID CLSID_UPnPDescriptionDocument;

#ifdef __cplusplus

class DECLSPEC_UUID("1d8a9b47-3a28-4ce2-8a4b-bd34e45bceeb")
UPnPDescriptionDocument;
#endif

EXTERN_C const CLSID CLSID_UPnPDeviceFinderEx;

#ifdef __cplusplus

class DECLSPEC_UUID("181b54fc-380b-4a75-b3f1-4ac45e9605b0")
UPnPDeviceFinderEx;
#endif

EXTERN_C const CLSID CLSID_UPnPDescriptionDocumentEx;

#ifdef __cplusplus

class DECLSPEC_UUID("33fd0563-d81a-4393-83cc-0195b1da2f91")
UPnPDescriptionDocumentEx;
#endif
#endif /* __UPNPLib_LIBRARY_DEFINED__ */

/* interface __MIDL_itf_upnp_0000_0019 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_upnp_0000_0019_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_upnp_0000_0019_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     __RPC__in unsigned long *, unsigned long            , __RPC__in BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     __RPC__in unsigned long *, __RPC__in BSTR * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     __RPC__in unsigned long *, unsigned long            , __RPC__in VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree(     __RPC__in unsigned long *, __RPC__in VARIANT * ); 

unsigned long             __RPC_USER  BSTR_UserSize64(     __RPC__in unsigned long *, unsigned long            , __RPC__in BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal64(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal64(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out BSTR * ); 
void                      __RPC_USER  BSTR_UserFree64(     __RPC__in unsigned long *, __RPC__in BSTR * ); 

unsigned long             __RPC_USER  VARIANT_UserSize64(     __RPC__in unsigned long *, unsigned long            , __RPC__in VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal64(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal64(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree64(     __RPC__in unsigned long *, __RPC__in VARIANT * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


