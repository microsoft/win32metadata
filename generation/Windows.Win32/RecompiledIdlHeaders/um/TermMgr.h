

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

#ifndef __termmgr_h__
#define __termmgr_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ITTerminalControl_FWD_DEFINED__
#define __ITTerminalControl_FWD_DEFINED__
typedef interface ITTerminalControl ITTerminalControl;

#endif 	/* __ITTerminalControl_FWD_DEFINED__ */


#ifndef __ITPluggableTerminalInitialization_FWD_DEFINED__
#define __ITPluggableTerminalInitialization_FWD_DEFINED__
typedef interface ITPluggableTerminalInitialization ITPluggableTerminalInitialization;

#endif 	/* __ITPluggableTerminalInitialization_FWD_DEFINED__ */


#ifndef __ITTerminalManager_FWD_DEFINED__
#define __ITTerminalManager_FWD_DEFINED__
typedef interface ITTerminalManager ITTerminalManager;

#endif 	/* __ITTerminalManager_FWD_DEFINED__ */


#ifndef __ITTerminalManager2_FWD_DEFINED__
#define __ITTerminalManager2_FWD_DEFINED__
typedef interface ITTerminalManager2 ITTerminalManager2;

#endif 	/* __ITTerminalManager2_FWD_DEFINED__ */


#ifndef __ITPluggableTerminalClassRegistration_FWD_DEFINED__
#define __ITPluggableTerminalClassRegistration_FWD_DEFINED__
typedef interface ITPluggableTerminalClassRegistration ITPluggableTerminalClassRegistration;

#endif 	/* __ITPluggableTerminalClassRegistration_FWD_DEFINED__ */


#ifndef __ITPluggableTerminalSuperclassRegistration_FWD_DEFINED__
#define __ITPluggableTerminalSuperclassRegistration_FWD_DEFINED__
typedef interface ITPluggableTerminalSuperclassRegistration ITPluggableTerminalSuperclassRegistration;

#endif 	/* __ITPluggableTerminalSuperclassRegistration_FWD_DEFINED__ */


#ifndef __TerminalManager_FWD_DEFINED__
#define __TerminalManager_FWD_DEFINED__

#ifdef __cplusplus
typedef class TerminalManager TerminalManager;
#else
typedef struct TerminalManager TerminalManager;
#endif /* __cplusplus */

#endif 	/* __TerminalManager_FWD_DEFINED__ */


#ifndef __PluggableSuperclassRegistration_FWD_DEFINED__
#define __PluggableSuperclassRegistration_FWD_DEFINED__

#ifdef __cplusplus
typedef class PluggableSuperclassRegistration PluggableSuperclassRegistration;
#else
typedef struct PluggableSuperclassRegistration PluggableSuperclassRegistration;
#endif /* __cplusplus */

#endif 	/* __PluggableSuperclassRegistration_FWD_DEFINED__ */


#ifndef __PluggableTerminalRegistration_FWD_DEFINED__
#define __PluggableTerminalRegistration_FWD_DEFINED__

#ifdef __cplusplus
typedef class PluggableTerminalRegistration PluggableTerminalRegistration;
#else
typedef struct PluggableTerminalRegistration PluggableTerminalRegistration;
#endif /* __cplusplus */

#endif 	/* __PluggableTerminalRegistration_FWD_DEFINED__ */


/* header files for imported files */
#include "Objsafe.h"
#include "tapi3if.h"
#include "tapi3ds.h"
#include "msp.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_termmgr_0000_0000 */
/* [local] */ 

/* Copyright (c) Microsoft Corporation. All rights reserved. */
#include <winapifamily.h>
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
typedef /* [public][public][public] */ 
enum __MIDL___MIDL_itf_termmgr_0000_0000_0001
    {
        TMGR_TD_CAPTURE	= 1,
        TMGR_TD_RENDER	= 2,
        TMGR_TD_BOTH	= 3
    } 	TMGR_DIRECTION;

#define	CLSID_String_VideoSuperclass	( L"{714C6F8C-6244-4685-87B3-B91F3F9EADA7}" )

#define	CLSID_String_StreamingSuperclass	( L"{214F4ACC-AE0B-4464-8405-07029003F8E2}" )

#define	CLSID_String_FileSuperclass	( L"{B4790031-56DB-4d3e-88C8-6FFAAFA08A91}" )



extern RPC_IF_HANDLE __MIDL_itf_termmgr_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_termmgr_0000_0000_v0_0_s_ifspec;

#ifndef __ITTerminalControl_INTERFACE_DEFINED__
#define __ITTerminalControl_INTERFACE_DEFINED__

/* interface ITTerminalControl */
/* [object][dual][helpstring][uuid] */ 


EXTERN_C const IID IID_ITTerminalControl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("AED6483B-3304-11d2-86F1-006008B0E5D2")
    ITTerminalControl : public IUnknown
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_AddressHandle( 
            /* [annotation][out] */ 
            _Out_  MSP_HANDLE *phtAddress) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ConnectTerminal( 
            /* [annotation][in] */ 
            _In_  IGraphBuilder *pGraph,
            /* [annotation][in] */ 
            _In_  DWORD dwTerminalDirection,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pdwNumPins,
            /* [annotation][out] */ 
            _Out_  IPin **ppPins) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CompleteConnectTerminal( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DisconnectTerminal( 
            /* [annotation][in] */ 
            _In_  IGraphBuilder *pGraph,
            /* [annotation][in] */ 
            _In_  DWORD dwReserved) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RunRenderFilter( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE StopRenderFilter( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITTerminalControlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ITTerminalControl * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ITTerminalControl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ITTerminalControl * This);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_AddressHandle )( 
            __RPC__in ITTerminalControl * This,
            /* [annotation][out] */ 
            _Out_  MSP_HANDLE *phtAddress);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ConnectTerminal )( 
            __RPC__in ITTerminalControl * This,
            /* [annotation][in] */ 
            _In_  IGraphBuilder *pGraph,
            /* [annotation][in] */ 
            _In_  DWORD dwTerminalDirection,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pdwNumPins,
            /* [annotation][out] */ 
            _Out_  IPin **ppPins);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CompleteConnectTerminal )( 
            __RPC__in ITTerminalControl * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DisconnectTerminal )( 
            __RPC__in ITTerminalControl * This,
            /* [annotation][in] */ 
            _In_  IGraphBuilder *pGraph,
            /* [annotation][in] */ 
            _In_  DWORD dwReserved);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RunRenderFilter )( 
            __RPC__in ITTerminalControl * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StopRenderFilter )( 
            __RPC__in ITTerminalControl * This);
        
        END_INTERFACE
    } ITTerminalControlVtbl;

    interface ITTerminalControl
    {
        CONST_VTBL struct ITTerminalControlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITTerminalControl_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITTerminalControl_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITTerminalControl_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITTerminalControl_get_AddressHandle(This,phtAddress)	\
    ( (This)->lpVtbl -> get_AddressHandle(This,phtAddress) ) 

#define ITTerminalControl_ConnectTerminal(This,pGraph,dwTerminalDirection,pdwNumPins,ppPins)	\
    ( (This)->lpVtbl -> ConnectTerminal(This,pGraph,dwTerminalDirection,pdwNumPins,ppPins) ) 

#define ITTerminalControl_CompleteConnectTerminal(This)	\
    ( (This)->lpVtbl -> CompleteConnectTerminal(This) ) 

#define ITTerminalControl_DisconnectTerminal(This,pGraph,dwReserved)	\
    ( (This)->lpVtbl -> DisconnectTerminal(This,pGraph,dwReserved) ) 

#define ITTerminalControl_RunRenderFilter(This)	\
    ( (This)->lpVtbl -> RunRenderFilter(This) ) 

#define ITTerminalControl_StopRenderFilter(This)	\
    ( (This)->lpVtbl -> StopRenderFilter(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITTerminalControl_INTERFACE_DEFINED__ */


#ifndef __ITPluggableTerminalInitialization_INTERFACE_DEFINED__
#define __ITPluggableTerminalInitialization_INTERFACE_DEFINED__

/* interface ITPluggableTerminalInitialization */
/* [object][dual][helpstring][uuid] */ 


EXTERN_C const IID IID_ITPluggableTerminalInitialization;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("AED6483C-3304-11d2-86F1-006008B0E5D2")
    ITPluggableTerminalInitialization : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE InitializeDynamic( 
            /* [annotation][in] */ 
            _In_  IID iidTerminalClass,
            /* [annotation][in] */ 
            _In_  DWORD dwMediaType,
            /* [annotation][in] */ 
            _In_  TERMINAL_DIRECTION Direction,
            /* [annotation][in] */ 
            _In_  MSP_HANDLE htAddress) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITPluggableTerminalInitializationVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ITPluggableTerminalInitialization * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ITPluggableTerminalInitialization * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ITPluggableTerminalInitialization * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *InitializeDynamic )( 
            __RPC__in ITPluggableTerminalInitialization * This,
            /* [annotation][in] */ 
            _In_  IID iidTerminalClass,
            /* [annotation][in] */ 
            _In_  DWORD dwMediaType,
            /* [annotation][in] */ 
            _In_  TERMINAL_DIRECTION Direction,
            /* [annotation][in] */ 
            _In_  MSP_HANDLE htAddress);
        
        END_INTERFACE
    } ITPluggableTerminalInitializationVtbl;

    interface ITPluggableTerminalInitialization
    {
        CONST_VTBL struct ITPluggableTerminalInitializationVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITPluggableTerminalInitialization_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITPluggableTerminalInitialization_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITPluggableTerminalInitialization_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITPluggableTerminalInitialization_InitializeDynamic(This,iidTerminalClass,dwMediaType,Direction,htAddress)	\
    ( (This)->lpVtbl -> InitializeDynamic(This,iidTerminalClass,dwMediaType,Direction,htAddress) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITPluggableTerminalInitialization_INTERFACE_DEFINED__ */


#ifndef __ITTerminalManager_INTERFACE_DEFINED__
#define __ITTerminalManager_INTERFACE_DEFINED__

/* interface ITTerminalManager */
/* [hidden][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ITTerminalManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7170F2DE-9BE3-11D0-A009-00AA00B605A4")
    ITTerminalManager : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDynamicTerminalClasses( 
            /* [annotation][in] */ 
            _In_  DWORD dwMediaTypes,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pdwNumClasses,
            /* [annotation][out] */ 
            _Out_  IID *pTerminalClasses) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateDynamicTerminal( 
            /* [annotation][in] */ 
            _In_  IUnknown *pOuterUnknown,
            /* [annotation][in] */ 
            _In_  IID iidTerminalClass,
            /* [annotation][in] */ 
            _In_  DWORD dwMediaType,
            /* [annotation][in] */ 
            _In_  TERMINAL_DIRECTION Direction,
            /* [annotation][in] */ 
            _In_  MSP_HANDLE htAddress,
            /* [annotation][out] */ 
            _Out_  ITTerminal **ppTerminal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITTerminalManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ITTerminalManager * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ITTerminalManager * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ITTerminalManager * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetDynamicTerminalClasses )( 
            __RPC__in ITTerminalManager * This,
            /* [annotation][in] */ 
            _In_  DWORD dwMediaTypes,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pdwNumClasses,
            /* [annotation][out] */ 
            _Out_  IID *pTerminalClasses);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateDynamicTerminal )( 
            __RPC__in ITTerminalManager * This,
            /* [annotation][in] */ 
            _In_  IUnknown *pOuterUnknown,
            /* [annotation][in] */ 
            _In_  IID iidTerminalClass,
            /* [annotation][in] */ 
            _In_  DWORD dwMediaType,
            /* [annotation][in] */ 
            _In_  TERMINAL_DIRECTION Direction,
            /* [annotation][in] */ 
            _In_  MSP_HANDLE htAddress,
            /* [annotation][out] */ 
            _Out_  ITTerminal **ppTerminal);
        
        END_INTERFACE
    } ITTerminalManagerVtbl;

    interface ITTerminalManager
    {
        CONST_VTBL struct ITTerminalManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITTerminalManager_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITTerminalManager_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITTerminalManager_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITTerminalManager_GetDynamicTerminalClasses(This,dwMediaTypes,pdwNumClasses,pTerminalClasses)	\
    ( (This)->lpVtbl -> GetDynamicTerminalClasses(This,dwMediaTypes,pdwNumClasses,pTerminalClasses) ) 

#define ITTerminalManager_CreateDynamicTerminal(This,pOuterUnknown,iidTerminalClass,dwMediaType,Direction,htAddress,ppTerminal)	\
    ( (This)->lpVtbl -> CreateDynamicTerminal(This,pOuterUnknown,iidTerminalClass,dwMediaType,Direction,htAddress,ppTerminal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITTerminalManager_INTERFACE_DEFINED__ */


#ifndef __ITTerminalManager2_INTERFACE_DEFINED__
#define __ITTerminalManager2_INTERFACE_DEFINED__

/* interface ITTerminalManager2 */
/* [object][hidden][unique][helpstring][uuid] */ 


EXTERN_C const IID IID_ITTerminalManager2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BB33DEC6-B2C7-46E6-9ED1-498B91FA85AC")
    ITTerminalManager2 : public ITTerminalManager
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetPluggableSuperclasses( 
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pdwNumSuperclasses,
            /* [annotation][out] */ 
            _Out_  IID *pSuperclasses) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetPluggableTerminalClasses( 
            /* [annotation][in] */ 
            _In_  IID iidSuperclass,
            /* [annotation][in] */ 
            _In_  DWORD dwMediaTypes,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pdwNumClasses,
            /* [annotation][out] */ 
            _Out_  IID *pTerminalClasses) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITTerminalManager2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ITTerminalManager2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ITTerminalManager2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ITTerminalManager2 * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetDynamicTerminalClasses )( 
            __RPC__in ITTerminalManager2 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwMediaTypes,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pdwNumClasses,
            /* [annotation][out] */ 
            _Out_  IID *pTerminalClasses);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateDynamicTerminal )( 
            __RPC__in ITTerminalManager2 * This,
            /* [annotation][in] */ 
            _In_  IUnknown *pOuterUnknown,
            /* [annotation][in] */ 
            _In_  IID iidTerminalClass,
            /* [annotation][in] */ 
            _In_  DWORD dwMediaType,
            /* [annotation][in] */ 
            _In_  TERMINAL_DIRECTION Direction,
            /* [annotation][in] */ 
            _In_  MSP_HANDLE htAddress,
            /* [annotation][out] */ 
            _Out_  ITTerminal **ppTerminal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetPluggableSuperclasses )( 
            __RPC__in ITTerminalManager2 * This,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pdwNumSuperclasses,
            /* [annotation][out] */ 
            _Out_  IID *pSuperclasses);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetPluggableTerminalClasses )( 
            __RPC__in ITTerminalManager2 * This,
            /* [annotation][in] */ 
            _In_  IID iidSuperclass,
            /* [annotation][in] */ 
            _In_  DWORD dwMediaTypes,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pdwNumClasses,
            /* [annotation][out] */ 
            _Out_  IID *pTerminalClasses);
        
        END_INTERFACE
    } ITTerminalManager2Vtbl;

    interface ITTerminalManager2
    {
        CONST_VTBL struct ITTerminalManager2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITTerminalManager2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITTerminalManager2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITTerminalManager2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITTerminalManager2_GetDynamicTerminalClasses(This,dwMediaTypes,pdwNumClasses,pTerminalClasses)	\
    ( (This)->lpVtbl -> GetDynamicTerminalClasses(This,dwMediaTypes,pdwNumClasses,pTerminalClasses) ) 

#define ITTerminalManager2_CreateDynamicTerminal(This,pOuterUnknown,iidTerminalClass,dwMediaType,Direction,htAddress,ppTerminal)	\
    ( (This)->lpVtbl -> CreateDynamicTerminal(This,pOuterUnknown,iidTerminalClass,dwMediaType,Direction,htAddress,ppTerminal) ) 


#define ITTerminalManager2_GetPluggableSuperclasses(This,pdwNumSuperclasses,pSuperclasses)	\
    ( (This)->lpVtbl -> GetPluggableSuperclasses(This,pdwNumSuperclasses,pSuperclasses) ) 

#define ITTerminalManager2_GetPluggableTerminalClasses(This,iidSuperclass,dwMediaTypes,pdwNumClasses,pTerminalClasses)	\
    ( (This)->lpVtbl -> GetPluggableTerminalClasses(This,iidSuperclass,dwMediaTypes,pdwNumClasses,pTerminalClasses) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITTerminalManager2_INTERFACE_DEFINED__ */


#ifndef __ITPluggableTerminalClassRegistration_INTERFACE_DEFINED__
#define __ITPluggableTerminalClassRegistration_INTERFACE_DEFINED__

/* interface ITPluggableTerminalClassRegistration */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ITPluggableTerminalClassRegistration;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("924A3723-A00B-4f5f-9FEE-8E9AEB9E82AA")
    ITPluggableTerminalClassRegistration : public IDispatch
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pName) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [annotation][in] */ 
            _In_  BSTR bstrName) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Company( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pCompany) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Company( 
            /* [annotation][in] */ 
            _In_  BSTR bstrCompany) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Version( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pVersion) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Version( 
            /* [annotation][in] */ 
            _In_  BSTR bstrVersion) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_TerminalClass( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pTerminalClass) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_TerminalClass( 
            /* [annotation][in] */ 
            _In_  BSTR bstrTerminalClass) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_CLSID( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pCLSID) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_CLSID( 
            /* [annotation][in] */ 
            _In_  BSTR bstrCLSID) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Direction( 
            /* [annotation][retval][out] */ 
            _Out_retval_  TMGR_DIRECTION *pDirection) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Direction( 
            /* [annotation][in] */ 
            _In_  TMGR_DIRECTION nDirection) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_MediaTypes( 
            /* [annotation][retval][out] */ 
            _Out_retval_  long *pMediaTypes) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_MediaTypes( 
            /* [annotation][in] */ 
            _In_  long nMediaTypes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [annotation][in] */ 
            _In_  BSTR bstrSuperclass) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Delete( 
            /* [annotation][in] */ 
            _In_  BSTR bstrSuperclass) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetTerminalClassInfo( 
            /* [annotation][in] */ 
            _In_  BSTR bstrSuperclass) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITPluggableTerminalClassRegistrationVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ITPluggableTerminalClassRegistration * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ITPluggableTerminalClassRegistration * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ITPluggableTerminalClassRegistration * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in ITPluggableTerminalClassRegistration * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in ITPluggableTerminalClassRegistration * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in ITPluggableTerminalClassRegistration * This,
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
            ITPluggableTerminalClassRegistration * This,
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
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            __RPC__in ITPluggableTerminalClassRegistration * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pName);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            __RPC__in ITPluggableTerminalClassRegistration * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrName);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Company )( 
            __RPC__in ITPluggableTerminalClassRegistration * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pCompany);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Company )( 
            __RPC__in ITPluggableTerminalClassRegistration * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrCompany);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Version )( 
            __RPC__in ITPluggableTerminalClassRegistration * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pVersion);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Version )( 
            __RPC__in ITPluggableTerminalClassRegistration * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrVersion);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_TerminalClass )( 
            __RPC__in ITPluggableTerminalClassRegistration * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pTerminalClass);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_TerminalClass )( 
            __RPC__in ITPluggableTerminalClassRegistration * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrTerminalClass);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_CLSID )( 
            __RPC__in ITPluggableTerminalClassRegistration * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pCLSID);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_CLSID )( 
            __RPC__in ITPluggableTerminalClassRegistration * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrCLSID);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Direction )( 
            __RPC__in ITPluggableTerminalClassRegistration * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  TMGR_DIRECTION *pDirection);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Direction )( 
            __RPC__in ITPluggableTerminalClassRegistration * This,
            /* [annotation][in] */ 
            _In_  TMGR_DIRECTION nDirection);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_MediaTypes )( 
            __RPC__in ITPluggableTerminalClassRegistration * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *pMediaTypes);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_MediaTypes )( 
            __RPC__in ITPluggableTerminalClassRegistration * This,
            /* [annotation][in] */ 
            _In_  long nMediaTypes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            __RPC__in ITPluggableTerminalClassRegistration * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrSuperclass);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            __RPC__in ITPluggableTerminalClassRegistration * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrSuperclass);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetTerminalClassInfo )( 
            __RPC__in ITPluggableTerminalClassRegistration * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrSuperclass);
        
        END_INTERFACE
    } ITPluggableTerminalClassRegistrationVtbl;

    interface ITPluggableTerminalClassRegistration
    {
        CONST_VTBL struct ITPluggableTerminalClassRegistrationVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITPluggableTerminalClassRegistration_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITPluggableTerminalClassRegistration_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITPluggableTerminalClassRegistration_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITPluggableTerminalClassRegistration_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ITPluggableTerminalClassRegistration_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ITPluggableTerminalClassRegistration_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ITPluggableTerminalClassRegistration_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ITPluggableTerminalClassRegistration_get_Name(This,pName)	\
    ( (This)->lpVtbl -> get_Name(This,pName) ) 

#define ITPluggableTerminalClassRegistration_put_Name(This,bstrName)	\
    ( (This)->lpVtbl -> put_Name(This,bstrName) ) 

#define ITPluggableTerminalClassRegistration_get_Company(This,pCompany)	\
    ( (This)->lpVtbl -> get_Company(This,pCompany) ) 

#define ITPluggableTerminalClassRegistration_put_Company(This,bstrCompany)	\
    ( (This)->lpVtbl -> put_Company(This,bstrCompany) ) 

#define ITPluggableTerminalClassRegistration_get_Version(This,pVersion)	\
    ( (This)->lpVtbl -> get_Version(This,pVersion) ) 

#define ITPluggableTerminalClassRegistration_put_Version(This,bstrVersion)	\
    ( (This)->lpVtbl -> put_Version(This,bstrVersion) ) 

#define ITPluggableTerminalClassRegistration_get_TerminalClass(This,pTerminalClass)	\
    ( (This)->lpVtbl -> get_TerminalClass(This,pTerminalClass) ) 

#define ITPluggableTerminalClassRegistration_put_TerminalClass(This,bstrTerminalClass)	\
    ( (This)->lpVtbl -> put_TerminalClass(This,bstrTerminalClass) ) 

#define ITPluggableTerminalClassRegistration_get_CLSID(This,pCLSID)	\
    ( (This)->lpVtbl -> get_CLSID(This,pCLSID) ) 

#define ITPluggableTerminalClassRegistration_put_CLSID(This,bstrCLSID)	\
    ( (This)->lpVtbl -> put_CLSID(This,bstrCLSID) ) 

#define ITPluggableTerminalClassRegistration_get_Direction(This,pDirection)	\
    ( (This)->lpVtbl -> get_Direction(This,pDirection) ) 

#define ITPluggableTerminalClassRegistration_put_Direction(This,nDirection)	\
    ( (This)->lpVtbl -> put_Direction(This,nDirection) ) 

#define ITPluggableTerminalClassRegistration_get_MediaTypes(This,pMediaTypes)	\
    ( (This)->lpVtbl -> get_MediaTypes(This,pMediaTypes) ) 

#define ITPluggableTerminalClassRegistration_put_MediaTypes(This,nMediaTypes)	\
    ( (This)->lpVtbl -> put_MediaTypes(This,nMediaTypes) ) 

#define ITPluggableTerminalClassRegistration_Add(This,bstrSuperclass)	\
    ( (This)->lpVtbl -> Add(This,bstrSuperclass) ) 

#define ITPluggableTerminalClassRegistration_Delete(This,bstrSuperclass)	\
    ( (This)->lpVtbl -> Delete(This,bstrSuperclass) ) 

#define ITPluggableTerminalClassRegistration_GetTerminalClassInfo(This,bstrSuperclass)	\
    ( (This)->lpVtbl -> GetTerminalClassInfo(This,bstrSuperclass) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITPluggableTerminalClassRegistration_INTERFACE_DEFINED__ */


#ifndef __ITPluggableTerminalSuperclassRegistration_INTERFACE_DEFINED__
#define __ITPluggableTerminalSuperclassRegistration_INTERFACE_DEFINED__

/* interface ITPluggableTerminalSuperclassRegistration */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ITPluggableTerminalSuperclassRegistration;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("60D3C08A-C13E-4195-9AB0-8DE768090F25")
    ITPluggableTerminalSuperclassRegistration : public IDispatch
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pName) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [annotation][in] */ 
            _In_  BSTR bstrName) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_CLSID( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pCLSID) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_CLSID( 
            /* [annotation][in] */ 
            _In_  BSTR bstrCLSID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Add( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Delete( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetTerminalSuperclassInfo( void) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_TerminalClasses( 
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT *pTerminals) = 0;
        
        virtual /* [hidden][helpstring][id] */ HRESULT STDMETHODCALLTYPE EnumerateTerminalClasses( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IEnumTerminalClass **ppTerminals) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITPluggableTerminalSuperclassRegistrationVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ITPluggableTerminalSuperclassRegistration * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ITPluggableTerminalSuperclassRegistration * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ITPluggableTerminalSuperclassRegistration * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in ITPluggableTerminalSuperclassRegistration * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in ITPluggableTerminalSuperclassRegistration * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in ITPluggableTerminalSuperclassRegistration * This,
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
            ITPluggableTerminalSuperclassRegistration * This,
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
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            __RPC__in ITPluggableTerminalSuperclassRegistration * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pName);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            __RPC__in ITPluggableTerminalSuperclassRegistration * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrName);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_CLSID )( 
            __RPC__in ITPluggableTerminalSuperclassRegistration * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pCLSID);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_CLSID )( 
            __RPC__in ITPluggableTerminalSuperclassRegistration * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrCLSID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            __RPC__in ITPluggableTerminalSuperclassRegistration * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            __RPC__in ITPluggableTerminalSuperclassRegistration * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetTerminalSuperclassInfo )( 
            __RPC__in ITPluggableTerminalSuperclassRegistration * This);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_TerminalClasses )( 
            __RPC__in ITPluggableTerminalSuperclassRegistration * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT *pTerminals);
        
        /* [hidden][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EnumerateTerminalClasses )( 
            __RPC__in ITPluggableTerminalSuperclassRegistration * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IEnumTerminalClass **ppTerminals);
        
        END_INTERFACE
    } ITPluggableTerminalSuperclassRegistrationVtbl;

    interface ITPluggableTerminalSuperclassRegistration
    {
        CONST_VTBL struct ITPluggableTerminalSuperclassRegistrationVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITPluggableTerminalSuperclassRegistration_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITPluggableTerminalSuperclassRegistration_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITPluggableTerminalSuperclassRegistration_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITPluggableTerminalSuperclassRegistration_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ITPluggableTerminalSuperclassRegistration_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ITPluggableTerminalSuperclassRegistration_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ITPluggableTerminalSuperclassRegistration_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ITPluggableTerminalSuperclassRegistration_get_Name(This,pName)	\
    ( (This)->lpVtbl -> get_Name(This,pName) ) 

#define ITPluggableTerminalSuperclassRegistration_put_Name(This,bstrName)	\
    ( (This)->lpVtbl -> put_Name(This,bstrName) ) 

#define ITPluggableTerminalSuperclassRegistration_get_CLSID(This,pCLSID)	\
    ( (This)->lpVtbl -> get_CLSID(This,pCLSID) ) 

#define ITPluggableTerminalSuperclassRegistration_put_CLSID(This,bstrCLSID)	\
    ( (This)->lpVtbl -> put_CLSID(This,bstrCLSID) ) 

#define ITPluggableTerminalSuperclassRegistration_Add(This)	\
    ( (This)->lpVtbl -> Add(This) ) 

#define ITPluggableTerminalSuperclassRegistration_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define ITPluggableTerminalSuperclassRegistration_GetTerminalSuperclassInfo(This)	\
    ( (This)->lpVtbl -> GetTerminalSuperclassInfo(This) ) 

#define ITPluggableTerminalSuperclassRegistration_get_TerminalClasses(This,pTerminals)	\
    ( (This)->lpVtbl -> get_TerminalClasses(This,pTerminals) ) 

#define ITPluggableTerminalSuperclassRegistration_EnumerateTerminalClasses(This,ppTerminals)	\
    ( (This)->lpVtbl -> EnumerateTerminalClasses(This,ppTerminals) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITPluggableTerminalSuperclassRegistration_INTERFACE_DEFINED__ */



#ifndef __TERMMGRLib_LIBRARY_DEFINED__
#define __TERMMGRLib_LIBRARY_DEFINED__

/* library TERMMGRLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_TERMMGRLib;

EXTERN_C const CLSID CLSID_TerminalManager;

#ifdef __cplusplus

class DECLSPEC_UUID("7170F2E0-9BE3-11D0-A009-00AA00B605A4")
TerminalManager;
#endif

EXTERN_C const CLSID CLSID_PluggableSuperclassRegistration;

#ifdef __cplusplus

class DECLSPEC_UUID("BB918E32-2A5C-4986-AB40-1686A034390A")
PluggableSuperclassRegistration;
#endif

EXTERN_C const CLSID CLSID_PluggableTerminalRegistration;

#ifdef __cplusplus

class DECLSPEC_UUID("45234E3E-61CC-4311-A3AB-248082554482")
PluggableTerminalRegistration;
#endif
#endif /* __TERMMGRLib_LIBRARY_DEFINED__ */

/* interface __MIDL_itf_termmgr_0000_0007 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_termmgr_0000_0007_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_termmgr_0000_0007_v0_0_s_ifspec;

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


