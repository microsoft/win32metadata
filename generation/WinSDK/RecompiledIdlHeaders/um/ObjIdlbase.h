

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

#ifndef __objidlbase_h__
#define __objidlbase_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IMarshal_FWD_DEFINED__
#define __IMarshal_FWD_DEFINED__
typedef interface IMarshal IMarshal;

#endif 	/* __IMarshal_FWD_DEFINED__ */


#ifndef __INoMarshal_FWD_DEFINED__
#define __INoMarshal_FWD_DEFINED__
typedef interface INoMarshal INoMarshal;

#endif 	/* __INoMarshal_FWD_DEFINED__ */


#ifndef __IAgileObject_FWD_DEFINED__
#define __IAgileObject_FWD_DEFINED__
typedef interface IAgileObject IAgileObject;

#endif 	/* __IAgileObject_FWD_DEFINED__ */


#ifndef __IActivationFilter_FWD_DEFINED__
#define __IActivationFilter_FWD_DEFINED__
typedef interface IActivationFilter IActivationFilter;

#endif 	/* __IActivationFilter_FWD_DEFINED__ */


#ifndef __IMarshal2_FWD_DEFINED__
#define __IMarshal2_FWD_DEFINED__
typedef interface IMarshal2 IMarshal2;

#endif 	/* __IMarshal2_FWD_DEFINED__ */


#ifndef __IMalloc_FWD_DEFINED__
#define __IMalloc_FWD_DEFINED__
typedef interface IMalloc IMalloc;

#endif 	/* __IMalloc_FWD_DEFINED__ */


#ifndef __IStdMarshalInfo_FWD_DEFINED__
#define __IStdMarshalInfo_FWD_DEFINED__
typedef interface IStdMarshalInfo IStdMarshalInfo;

#endif 	/* __IStdMarshalInfo_FWD_DEFINED__ */


#ifndef __IExternalConnection_FWD_DEFINED__
#define __IExternalConnection_FWD_DEFINED__
typedef interface IExternalConnection IExternalConnection;

#endif 	/* __IExternalConnection_FWD_DEFINED__ */


#ifndef __IMultiQI_FWD_DEFINED__
#define __IMultiQI_FWD_DEFINED__
typedef interface IMultiQI IMultiQI;

#endif 	/* __IMultiQI_FWD_DEFINED__ */


#ifndef __AsyncIMultiQI_FWD_DEFINED__
#define __AsyncIMultiQI_FWD_DEFINED__
typedef interface AsyncIMultiQI AsyncIMultiQI;

#endif 	/* __AsyncIMultiQI_FWD_DEFINED__ */


#ifndef __IInternalUnknown_FWD_DEFINED__
#define __IInternalUnknown_FWD_DEFINED__
typedef interface IInternalUnknown IInternalUnknown;

#endif 	/* __IInternalUnknown_FWD_DEFINED__ */


#ifndef __IEnumUnknown_FWD_DEFINED__
#define __IEnumUnknown_FWD_DEFINED__
typedef interface IEnumUnknown IEnumUnknown;

#endif 	/* __IEnumUnknown_FWD_DEFINED__ */


#ifndef __IEnumString_FWD_DEFINED__
#define __IEnumString_FWD_DEFINED__
typedef interface IEnumString IEnumString;

#endif 	/* __IEnumString_FWD_DEFINED__ */


#ifndef __ISequentialStream_FWD_DEFINED__
#define __ISequentialStream_FWD_DEFINED__
typedef interface ISequentialStream ISequentialStream;

#endif 	/* __ISequentialStream_FWD_DEFINED__ */


#ifndef __IStream_FWD_DEFINED__
#define __IStream_FWD_DEFINED__
typedef interface IStream IStream;

#endif 	/* __IStream_FWD_DEFINED__ */


#ifndef __IRpcChannelBuffer_FWD_DEFINED__
#define __IRpcChannelBuffer_FWD_DEFINED__
typedef interface IRpcChannelBuffer IRpcChannelBuffer;

#endif 	/* __IRpcChannelBuffer_FWD_DEFINED__ */


#ifndef __IRpcChannelBuffer2_FWD_DEFINED__
#define __IRpcChannelBuffer2_FWD_DEFINED__
typedef interface IRpcChannelBuffer2 IRpcChannelBuffer2;

#endif 	/* __IRpcChannelBuffer2_FWD_DEFINED__ */


#ifndef __IAsyncRpcChannelBuffer_FWD_DEFINED__
#define __IAsyncRpcChannelBuffer_FWD_DEFINED__
typedef interface IAsyncRpcChannelBuffer IAsyncRpcChannelBuffer;

#endif 	/* __IAsyncRpcChannelBuffer_FWD_DEFINED__ */


#ifndef __IRpcChannelBuffer3_FWD_DEFINED__
#define __IRpcChannelBuffer3_FWD_DEFINED__
typedef interface IRpcChannelBuffer3 IRpcChannelBuffer3;

#endif 	/* __IRpcChannelBuffer3_FWD_DEFINED__ */


#ifndef __IRpcSyntaxNegotiate_FWD_DEFINED__
#define __IRpcSyntaxNegotiate_FWD_DEFINED__
typedef interface IRpcSyntaxNegotiate IRpcSyntaxNegotiate;

#endif 	/* __IRpcSyntaxNegotiate_FWD_DEFINED__ */


#ifndef __IRpcProxyBuffer_FWD_DEFINED__
#define __IRpcProxyBuffer_FWD_DEFINED__
typedef interface IRpcProxyBuffer IRpcProxyBuffer;

#endif 	/* __IRpcProxyBuffer_FWD_DEFINED__ */


#ifndef __IRpcStubBuffer_FWD_DEFINED__
#define __IRpcStubBuffer_FWD_DEFINED__
typedef interface IRpcStubBuffer IRpcStubBuffer;

#endif 	/* __IRpcStubBuffer_FWD_DEFINED__ */


#ifndef __IPSFactoryBuffer_FWD_DEFINED__
#define __IPSFactoryBuffer_FWD_DEFINED__
typedef interface IPSFactoryBuffer IPSFactoryBuffer;

#endif 	/* __IPSFactoryBuffer_FWD_DEFINED__ */


#ifndef __IChannelHook_FWD_DEFINED__
#define __IChannelHook_FWD_DEFINED__
typedef interface IChannelHook IChannelHook;

#endif 	/* __IChannelHook_FWD_DEFINED__ */


#ifndef __IClientSecurity_FWD_DEFINED__
#define __IClientSecurity_FWD_DEFINED__
typedef interface IClientSecurity IClientSecurity;

#endif 	/* __IClientSecurity_FWD_DEFINED__ */


#ifndef __IServerSecurity_FWD_DEFINED__
#define __IServerSecurity_FWD_DEFINED__
typedef interface IServerSecurity IServerSecurity;

#endif 	/* __IServerSecurity_FWD_DEFINED__ */


#ifndef __IRpcOptions_FWD_DEFINED__
#define __IRpcOptions_FWD_DEFINED__
typedef interface IRpcOptions IRpcOptions;

#endif 	/* __IRpcOptions_FWD_DEFINED__ */


#ifndef __IGlobalOptions_FWD_DEFINED__
#define __IGlobalOptions_FWD_DEFINED__
typedef interface IGlobalOptions IGlobalOptions;

#endif 	/* __IGlobalOptions_FWD_DEFINED__ */


#ifndef __ISurrogate_FWD_DEFINED__
#define __ISurrogate_FWD_DEFINED__
typedef interface ISurrogate ISurrogate;

#endif 	/* __ISurrogate_FWD_DEFINED__ */


#ifndef __IGlobalInterfaceTable_FWD_DEFINED__
#define __IGlobalInterfaceTable_FWD_DEFINED__
typedef interface IGlobalInterfaceTable IGlobalInterfaceTable;

#endif 	/* __IGlobalInterfaceTable_FWD_DEFINED__ */


#ifndef __ISynchronize_FWD_DEFINED__
#define __ISynchronize_FWD_DEFINED__
typedef interface ISynchronize ISynchronize;

#endif 	/* __ISynchronize_FWD_DEFINED__ */


#ifndef __ISynchronizeHandle_FWD_DEFINED__
#define __ISynchronizeHandle_FWD_DEFINED__
typedef interface ISynchronizeHandle ISynchronizeHandle;

#endif 	/* __ISynchronizeHandle_FWD_DEFINED__ */


#ifndef __ISynchronizeEvent_FWD_DEFINED__
#define __ISynchronizeEvent_FWD_DEFINED__
typedef interface ISynchronizeEvent ISynchronizeEvent;

#endif 	/* __ISynchronizeEvent_FWD_DEFINED__ */


#ifndef __ISynchronizeContainer_FWD_DEFINED__
#define __ISynchronizeContainer_FWD_DEFINED__
typedef interface ISynchronizeContainer ISynchronizeContainer;

#endif 	/* __ISynchronizeContainer_FWD_DEFINED__ */


#ifndef __ISynchronizeMutex_FWD_DEFINED__
#define __ISynchronizeMutex_FWD_DEFINED__
typedef interface ISynchronizeMutex ISynchronizeMutex;

#endif 	/* __ISynchronizeMutex_FWD_DEFINED__ */


#ifndef __ICancelMethodCalls_FWD_DEFINED__
#define __ICancelMethodCalls_FWD_DEFINED__
typedef interface ICancelMethodCalls ICancelMethodCalls;

#endif 	/* __ICancelMethodCalls_FWD_DEFINED__ */


#ifndef __IAsyncManager_FWD_DEFINED__
#define __IAsyncManager_FWD_DEFINED__
typedef interface IAsyncManager IAsyncManager;

#endif 	/* __IAsyncManager_FWD_DEFINED__ */


#ifndef __ICallFactory_FWD_DEFINED__
#define __ICallFactory_FWD_DEFINED__
typedef interface ICallFactory ICallFactory;

#endif 	/* __ICallFactory_FWD_DEFINED__ */


#ifndef __IRpcHelper_FWD_DEFINED__
#define __IRpcHelper_FWD_DEFINED__
typedef interface IRpcHelper IRpcHelper;

#endif 	/* __IRpcHelper_FWD_DEFINED__ */


#ifndef __IReleaseMarshalBuffers_FWD_DEFINED__
#define __IReleaseMarshalBuffers_FWD_DEFINED__
typedef interface IReleaseMarshalBuffers IReleaseMarshalBuffers;

#endif 	/* __IReleaseMarshalBuffers_FWD_DEFINED__ */


#ifndef __IWaitMultiple_FWD_DEFINED__
#define __IWaitMultiple_FWD_DEFINED__
typedef interface IWaitMultiple IWaitMultiple;

#endif 	/* __IWaitMultiple_FWD_DEFINED__ */


#ifndef __IAddrTrackingControl_FWD_DEFINED__
#define __IAddrTrackingControl_FWD_DEFINED__
typedef interface IAddrTrackingControl IAddrTrackingControl;

#endif 	/* __IAddrTrackingControl_FWD_DEFINED__ */


#ifndef __IAddrExclusionControl_FWD_DEFINED__
#define __IAddrExclusionControl_FWD_DEFINED__
typedef interface IAddrExclusionControl IAddrExclusionControl;

#endif 	/* __IAddrExclusionControl_FWD_DEFINED__ */


#ifndef __IPipeByte_FWD_DEFINED__
#define __IPipeByte_FWD_DEFINED__
typedef interface IPipeByte IPipeByte;

#endif 	/* __IPipeByte_FWD_DEFINED__ */


#ifndef __AsyncIPipeByte_FWD_DEFINED__
#define __AsyncIPipeByte_FWD_DEFINED__
typedef interface AsyncIPipeByte AsyncIPipeByte;

#endif 	/* __AsyncIPipeByte_FWD_DEFINED__ */


#ifndef __IPipeLong_FWD_DEFINED__
#define __IPipeLong_FWD_DEFINED__
typedef interface IPipeLong IPipeLong;

#endif 	/* __IPipeLong_FWD_DEFINED__ */


#ifndef __AsyncIPipeLong_FWD_DEFINED__
#define __AsyncIPipeLong_FWD_DEFINED__
typedef interface AsyncIPipeLong AsyncIPipeLong;

#endif 	/* __AsyncIPipeLong_FWD_DEFINED__ */


#ifndef __IPipeDouble_FWD_DEFINED__
#define __IPipeDouble_FWD_DEFINED__
typedef interface IPipeDouble IPipeDouble;

#endif 	/* __IPipeDouble_FWD_DEFINED__ */


#ifndef __AsyncIPipeDouble_FWD_DEFINED__
#define __AsyncIPipeDouble_FWD_DEFINED__
typedef interface AsyncIPipeDouble AsyncIPipeDouble;

#endif 	/* __AsyncIPipeDouble_FWD_DEFINED__ */


#ifndef __IEnumContextProps_FWD_DEFINED__
#define __IEnumContextProps_FWD_DEFINED__
typedef interface IEnumContextProps IEnumContextProps;

#endif 	/* __IEnumContextProps_FWD_DEFINED__ */


#ifndef __IContext_FWD_DEFINED__
#define __IContext_FWD_DEFINED__
typedef interface IContext IContext;

#endif 	/* __IContext_FWD_DEFINED__ */


#ifndef __IComThreadingInfo_FWD_DEFINED__
#define __IComThreadingInfo_FWD_DEFINED__
typedef interface IComThreadingInfo IComThreadingInfo;

#endif 	/* __IComThreadingInfo_FWD_DEFINED__ */


#ifndef __IProcessInitControl_FWD_DEFINED__
#define __IProcessInitControl_FWD_DEFINED__
typedef interface IProcessInitControl IProcessInitControl;

#endif 	/* __IProcessInitControl_FWD_DEFINED__ */


#ifndef __IFastRundown_FWD_DEFINED__
#define __IFastRundown_FWD_DEFINED__
typedef interface IFastRundown IFastRundown;

#endif 	/* __IFastRundown_FWD_DEFINED__ */


#ifndef __IMarshalingStream_FWD_DEFINED__
#define __IMarshalingStream_FWD_DEFINED__
typedef interface IMarshalingStream IMarshalingStream;

#endif 	/* __IMarshalingStream_FWD_DEFINED__ */


#ifndef __IAgileReference_FWD_DEFINED__
#define __IAgileReference_FWD_DEFINED__
typedef interface IAgileReference IAgileReference;

#endif 	/* __IAgileReference_FWD_DEFINED__ */


/* header files for imported files */
#include "unknwnbase.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_objidlbase_0000_0000 */
/* [local] */ 

#include <winapifamily.h>
//+-------------------------------------------------------------------------
//+-------------------------------------------------------------------------
//
//  Microsoft Windows
//  Copyright (c) Microsoft Corporation. All rights reserved.
//
//--------------------------------------------------------------------------
#if(NTDDI_VERSION >= NTDDI_VISTA && !defined(_WIN32_WINNT))
#define _WIN32_WINNT 0x0600
#endif
#if(NTDDI_VERSION >= NTDDI_WS03 && !defined(_WIN32_WINNT))
#define _WIN32_WINNT 0x0502
#endif
#if(NTDDI_VERSION >= NTDDI_WINXP && !defined(_WIN32_WINNT))
#define _WIN32_WINNT 0x0501
#endif
#if(NTDDI_VERSION >= NTDDI_WIN2K && !defined(_WIN32_WINNT))
#define _WIN32_WINNT 0x0500
#endif



#if ( _MSC_VER >= 800 )
#if _MSC_VER >= 1200
#pragma warning(push)
#ifndef _MSC_EXTENSIONS
#pragma warning(disable:4309) /* truncation of constant value */
#endif
#pragma warning(disable:4820) /* padding added after data member */
#endif
#pragma warning(disable:4201)
#endif
#if ( _MSC_VER >= 1020 )
#pragma once
#endif
#include <limits.h>
#ifndef _OBJIDLBASE_
#pragma region Application Family or OneCore Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)


#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */
#pragma endregion
#pragma region Desktop Family or OneCore Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)



#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */
#pragma endregion
#pragma region Application Family or OneCore Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

typedef struct _COSERVERINFO
    {
    DWORD dwReserved1;
    LPWSTR pwszName;
    COAUTHINFO *pAuthInfo;
    DWORD dwReserved2;
    } 	COSERVERINFO;




extern RPC_IF_HANDLE __MIDL_itf_objidlbase_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_objidlbase_0000_0000_v0_0_s_ifspec;

#ifndef __IMarshal_INTERFACE_DEFINED__
#define __IMarshal_INTERFACE_DEFINED__

/* interface IMarshal */
/* [uuid][object][local] */ 

typedef /* [unique] */ IMarshal *LPMARSHAL;


EXTERN_C const IID IID_IMarshal;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("00000003-0000-0000-C000-000000000046")
    IMarshal : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetUnmarshalClass( 
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][unique][in] */ 
            _In_opt_  void *pv,
            /* [annotation][in] */ 
            _In_  DWORD dwDestContext,
            /* [annotation][unique][in] */ 
            _Reserved_  void *pvDestContext,
            /* [annotation][in] */ 
            _In_  DWORD mshlflags,
            /* [annotation][out] */ 
            _Out_  CLSID *pCid) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMarshalSizeMax( 
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][unique][in] */ 
            _In_opt_  void *pv,
            /* [annotation][in] */ 
            _In_  DWORD dwDestContext,
            /* [annotation][unique][in] */ 
            _Reserved_  void *pvDestContext,
            /* [annotation][in] */ 
            _In_  DWORD mshlflags,
            /* [annotation][out] */ 
            _Out_  DWORD *pSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE MarshalInterface( 
            /* [annotation][unique][in] */ 
            _In_  IStream *pStm,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][unique][in] */ 
            _In_opt_  void *pv,
            /* [annotation][in] */ 
            _In_  DWORD dwDestContext,
            /* [annotation][unique][in] */ 
            _Reserved_  void *pvDestContext,
            /* [annotation][in] */ 
            _In_  DWORD mshlflags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UnmarshalInterface( 
            /* [annotation][unique][in] */ 
            _In_  IStream *pStm,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][out] */ 
            _Outptr_  void **ppv) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReleaseMarshalData( 
            /* [annotation][unique][in] */ 
            _In_  IStream *pStm) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DisconnectObject( 
            /* [annotation][in] */ 
            _In_  DWORD dwReserved) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IMarshalVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMarshal * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMarshal * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMarshal * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetUnmarshalClass )( 
            IMarshal * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][unique][in] */ 
            _In_opt_  void *pv,
            /* [annotation][in] */ 
            _In_  DWORD dwDestContext,
            /* [annotation][unique][in] */ 
            _Reserved_  void *pvDestContext,
            /* [annotation][in] */ 
            _In_  DWORD mshlflags,
            /* [annotation][out] */ 
            _Out_  CLSID *pCid);
        
        HRESULT ( STDMETHODCALLTYPE *GetMarshalSizeMax )( 
            IMarshal * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][unique][in] */ 
            _In_opt_  void *pv,
            /* [annotation][in] */ 
            _In_  DWORD dwDestContext,
            /* [annotation][unique][in] */ 
            _Reserved_  void *pvDestContext,
            /* [annotation][in] */ 
            _In_  DWORD mshlflags,
            /* [annotation][out] */ 
            _Out_  DWORD *pSize);
        
        HRESULT ( STDMETHODCALLTYPE *MarshalInterface )( 
            IMarshal * This,
            /* [annotation][unique][in] */ 
            _In_  IStream *pStm,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][unique][in] */ 
            _In_opt_  void *pv,
            /* [annotation][in] */ 
            _In_  DWORD dwDestContext,
            /* [annotation][unique][in] */ 
            _Reserved_  void *pvDestContext,
            /* [annotation][in] */ 
            _In_  DWORD mshlflags);
        
        HRESULT ( STDMETHODCALLTYPE *UnmarshalInterface )( 
            IMarshal * This,
            /* [annotation][unique][in] */ 
            _In_  IStream *pStm,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][out] */ 
            _Outptr_  void **ppv);
        
        HRESULT ( STDMETHODCALLTYPE *ReleaseMarshalData )( 
            IMarshal * This,
            /* [annotation][unique][in] */ 
            _In_  IStream *pStm);
        
        HRESULT ( STDMETHODCALLTYPE *DisconnectObject )( 
            IMarshal * This,
            /* [annotation][in] */ 
            _In_  DWORD dwReserved);
        
        END_INTERFACE
    } IMarshalVtbl;

    interface IMarshal
    {
        CONST_VTBL struct IMarshalVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMarshal_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMarshal_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMarshal_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMarshal_GetUnmarshalClass(This,riid,pv,dwDestContext,pvDestContext,mshlflags,pCid)	\
    ( (This)->lpVtbl -> GetUnmarshalClass(This,riid,pv,dwDestContext,pvDestContext,mshlflags,pCid) ) 

#define IMarshal_GetMarshalSizeMax(This,riid,pv,dwDestContext,pvDestContext,mshlflags,pSize)	\
    ( (This)->lpVtbl -> GetMarshalSizeMax(This,riid,pv,dwDestContext,pvDestContext,mshlflags,pSize) ) 

#define IMarshal_MarshalInterface(This,pStm,riid,pv,dwDestContext,pvDestContext,mshlflags)	\
    ( (This)->lpVtbl -> MarshalInterface(This,pStm,riid,pv,dwDestContext,pvDestContext,mshlflags) ) 

#define IMarshal_UnmarshalInterface(This,pStm,riid,ppv)	\
    ( (This)->lpVtbl -> UnmarshalInterface(This,pStm,riid,ppv) ) 

#define IMarshal_ReleaseMarshalData(This,pStm)	\
    ( (This)->lpVtbl -> ReleaseMarshalData(This,pStm) ) 

#define IMarshal_DisconnectObject(This,dwReserved)	\
    ( (This)->lpVtbl -> DisconnectObject(This,dwReserved) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMarshal_INTERFACE_DEFINED__ */


#ifndef __INoMarshal_INTERFACE_DEFINED__
#define __INoMarshal_INTERFACE_DEFINED__

/* interface INoMarshal */
/* [uuid][object][local] */ 


EXTERN_C const IID IID_INoMarshal;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("ecc8691b-c1db-4dc0-855e-65f6c551af49")
    INoMarshal : public IUnknown
    {
    public:
    };
    
    
#else 	/* C style interface */

    typedef struct INoMarshalVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            INoMarshal * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            INoMarshal * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            INoMarshal * This);
        
        END_INTERFACE
    } INoMarshalVtbl;

    interface INoMarshal
    {
        CONST_VTBL struct INoMarshalVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INoMarshal_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define INoMarshal_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define INoMarshal_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __INoMarshal_INTERFACE_DEFINED__ */


#ifndef __IAgileObject_INTERFACE_DEFINED__
#define __IAgileObject_INTERFACE_DEFINED__

/* interface IAgileObject */
/* [uuid][object][local] */ 


EXTERN_C const IID IID_IAgileObject;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("94ea2b94-e9cc-49e0-c0ff-ee64ca8f5b90")
    IAgileObject : public IUnknown
    {
    public:
    };
    
    
#else 	/* C style interface */

    typedef struct IAgileObjectVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAgileObject * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAgileObject * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAgileObject * This);
        
        END_INTERFACE
    } IAgileObjectVtbl;

    interface IAgileObject
    {
        CONST_VTBL struct IAgileObjectVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgileObject_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAgileObject_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAgileObject_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAgileObject_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_objidlbase_0000_0003 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */
#pragma endregion
#pragma region Desktop Family or OneCore Family or OneCore Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)


extern RPC_IF_HANDLE __MIDL_itf_objidlbase_0000_0003_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_objidlbase_0000_0003_v0_0_s_ifspec;

#ifndef __IActivationFilter_INTERFACE_DEFINED__
#define __IActivationFilter_INTERFACE_DEFINED__

/* interface IActivationFilter */
/* [uuid][object][local] */ 

typedef 
enum tagACTIVATIONTYPE
    {
        ACTIVATIONTYPE_UNCATEGORIZED	= 0,
        ACTIVATIONTYPE_FROM_MONIKER	= 0x1,
        ACTIVATIONTYPE_FROM_DATA	= 0x2,
        ACTIVATIONTYPE_FROM_STORAGE	= 0x4,
        ACTIVATIONTYPE_FROM_STREAM	= 0x8,
        ACTIVATIONTYPE_FROM_FILE	= 0x10
    } 	ACTIVATIONTYPE;


EXTERN_C const IID IID_IActivationFilter;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("00000017-0000-0000-C000-000000000046")
    IActivationFilter : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE HandleActivation( 
            /* [annotation][in] */ 
            _In_  DWORD dwActivationType,
            /* [annotation][in] */ 
            _In_  REFCLSID rclsid,
            /* [annotation][out] */ 
            _Out_  CLSID *pReplacementClsId) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IActivationFilterVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IActivationFilter * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IActivationFilter * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IActivationFilter * This);
        
        HRESULT ( STDMETHODCALLTYPE *HandleActivation )( 
            IActivationFilter * This,
            /* [annotation][in] */ 
            _In_  DWORD dwActivationType,
            /* [annotation][in] */ 
            _In_  REFCLSID rclsid,
            /* [annotation][out] */ 
            _Out_  CLSID *pReplacementClsId);
        
        END_INTERFACE
    } IActivationFilterVtbl;

    interface IActivationFilter
    {
        CONST_VTBL struct IActivationFilterVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActivationFilter_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IActivationFilter_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IActivationFilter_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IActivationFilter_HandleActivation(This,dwActivationType,rclsid,pReplacementClsId)	\
    ( (This)->lpVtbl -> HandleActivation(This,dwActivationType,rclsid,pReplacementClsId) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IActivationFilter_INTERFACE_DEFINED__ */


#ifndef __IMarshal2_INTERFACE_DEFINED__
#define __IMarshal2_INTERFACE_DEFINED__

/* interface IMarshal2 */
/* [uuid][object][local] */ 

typedef /* [unique] */ IMarshal2 *LPMARSHAL2;


EXTERN_C const IID IID_IMarshal2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("000001cf-0000-0000-C000-000000000046")
    IMarshal2 : public IMarshal
    {
    public:
    };
    
    
#else 	/* C style interface */

    typedef struct IMarshal2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMarshal2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMarshal2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMarshal2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetUnmarshalClass )( 
            IMarshal2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][unique][in] */ 
            _In_opt_  void *pv,
            /* [annotation][in] */ 
            _In_  DWORD dwDestContext,
            /* [annotation][unique][in] */ 
            _Reserved_  void *pvDestContext,
            /* [annotation][in] */ 
            _In_  DWORD mshlflags,
            /* [annotation][out] */ 
            _Out_  CLSID *pCid);
        
        HRESULT ( STDMETHODCALLTYPE *GetMarshalSizeMax )( 
            IMarshal2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][unique][in] */ 
            _In_opt_  void *pv,
            /* [annotation][in] */ 
            _In_  DWORD dwDestContext,
            /* [annotation][unique][in] */ 
            _Reserved_  void *pvDestContext,
            /* [annotation][in] */ 
            _In_  DWORD mshlflags,
            /* [annotation][out] */ 
            _Out_  DWORD *pSize);
        
        HRESULT ( STDMETHODCALLTYPE *MarshalInterface )( 
            IMarshal2 * This,
            /* [annotation][unique][in] */ 
            _In_  IStream *pStm,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][unique][in] */ 
            _In_opt_  void *pv,
            /* [annotation][in] */ 
            _In_  DWORD dwDestContext,
            /* [annotation][unique][in] */ 
            _Reserved_  void *pvDestContext,
            /* [annotation][in] */ 
            _In_  DWORD mshlflags);
        
        HRESULT ( STDMETHODCALLTYPE *UnmarshalInterface )( 
            IMarshal2 * This,
            /* [annotation][unique][in] */ 
            _In_  IStream *pStm,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][out] */ 
            _Outptr_  void **ppv);
        
        HRESULT ( STDMETHODCALLTYPE *ReleaseMarshalData )( 
            IMarshal2 * This,
            /* [annotation][unique][in] */ 
            _In_  IStream *pStm);
        
        HRESULT ( STDMETHODCALLTYPE *DisconnectObject )( 
            IMarshal2 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwReserved);
        
        END_INTERFACE
    } IMarshal2Vtbl;

    interface IMarshal2
    {
        CONST_VTBL struct IMarshal2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMarshal2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMarshal2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMarshal2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMarshal2_GetUnmarshalClass(This,riid,pv,dwDestContext,pvDestContext,mshlflags,pCid)	\
    ( (This)->lpVtbl -> GetUnmarshalClass(This,riid,pv,dwDestContext,pvDestContext,mshlflags,pCid) ) 

#define IMarshal2_GetMarshalSizeMax(This,riid,pv,dwDestContext,pvDestContext,mshlflags,pSize)	\
    ( (This)->lpVtbl -> GetMarshalSizeMax(This,riid,pv,dwDestContext,pvDestContext,mshlflags,pSize) ) 

#define IMarshal2_MarshalInterface(This,pStm,riid,pv,dwDestContext,pvDestContext,mshlflags)	\
    ( (This)->lpVtbl -> MarshalInterface(This,pStm,riid,pv,dwDestContext,pvDestContext,mshlflags) ) 

#define IMarshal2_UnmarshalInterface(This,pStm,riid,ppv)	\
    ( (This)->lpVtbl -> UnmarshalInterface(This,pStm,riid,ppv) ) 

#define IMarshal2_ReleaseMarshalData(This,pStm)	\
    ( (This)->lpVtbl -> ReleaseMarshalData(This,pStm) ) 

#define IMarshal2_DisconnectObject(This,dwReserved)	\
    ( (This)->lpVtbl -> DisconnectObject(This,dwReserved) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMarshal2_INTERFACE_DEFINED__ */


#ifndef __IMalloc_INTERFACE_DEFINED__
#define __IMalloc_INTERFACE_DEFINED__

/* interface IMalloc */
/* [uuid][object][local] */ 

typedef /* [unique] */ IMalloc *LPMALLOC;


EXTERN_C const IID IID_IMalloc;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("00000002-0000-0000-C000-000000000046")
    IMalloc : public IUnknown
    {
    public:
        virtual void *STDMETHODCALLTYPE Alloc( 
            /* [annotation][in] */ 
            _In_  SIZE_T cb) = 0;
        
        virtual void *STDMETHODCALLTYPE Realloc( 
            /* [annotation][in] */ 
            _In_opt_  void *pv,
            /* [annotation][in] */ 
            _In_  SIZE_T cb) = 0;
        
        virtual void STDMETHODCALLTYPE Free( 
            /* [annotation][in] */ 
            _In_opt_  void *pv) = 0;
        
        virtual SIZE_T STDMETHODCALLTYPE GetSize( 
            /* [annotation][in] */ 
            _In_opt_ _Post_writable_byte_size_(return)  void *pv) = 0;
        
        virtual int STDMETHODCALLTYPE DidAlloc( 
            /* [annotation][in] */ 
            _In_opt_  void *pv) = 0;
        
        virtual void STDMETHODCALLTYPE HeapMinimize( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IMallocVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMalloc * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMalloc * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMalloc * This);
        
        void *( STDMETHODCALLTYPE *Alloc )( 
            IMalloc * This,
            /* [annotation][in] */ 
            _In_  SIZE_T cb);
        
        void *( STDMETHODCALLTYPE *Realloc )( 
            IMalloc * This,
            /* [annotation][in] */ 
            _In_opt_  void *pv,
            /* [annotation][in] */ 
            _In_  SIZE_T cb);
        
        void ( STDMETHODCALLTYPE *Free )( 
            IMalloc * This,
            /* [annotation][in] */ 
            _In_opt_  void *pv);
        
        SIZE_T ( STDMETHODCALLTYPE *GetSize )( 
            IMalloc * This,
            /* [annotation][in] */ 
            _In_opt_ _Post_writable_byte_size_(return)  void *pv);
        
        int ( STDMETHODCALLTYPE *DidAlloc )( 
            IMalloc * This,
            /* [annotation][in] */ 
            _In_opt_  void *pv);
        
        void ( STDMETHODCALLTYPE *HeapMinimize )( 
            IMalloc * This);
        
        END_INTERFACE
    } IMallocVtbl;

    interface IMalloc
    {
        CONST_VTBL struct IMallocVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMalloc_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMalloc_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMalloc_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMalloc_Alloc(This,cb)	\
    ( (This)->lpVtbl -> Alloc(This,cb) ) 

#define IMalloc_Realloc(This,pv,cb)	\
    ( (This)->lpVtbl -> Realloc(This,pv,cb) ) 

#define IMalloc_Free(This,pv)	\
    ( (This)->lpVtbl -> Free(This,pv) ) 

#define IMalloc_GetSize(This,pv)	\
    ( (This)->lpVtbl -> GetSize(This,pv) ) 

#define IMalloc_DidAlloc(This,pv)	\
    ( (This)->lpVtbl -> DidAlloc(This,pv) ) 

#define IMalloc_HeapMinimize(This)	\
    ( (This)->lpVtbl -> HeapMinimize(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMalloc_INTERFACE_DEFINED__ */


#ifndef __IStdMarshalInfo_INTERFACE_DEFINED__
#define __IStdMarshalInfo_INTERFACE_DEFINED__

/* interface IStdMarshalInfo */
/* [uuid][object][local] */ 

typedef /* [unique] */ IStdMarshalInfo *LPSTDMARSHALINFO;


EXTERN_C const IID IID_IStdMarshalInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("00000018-0000-0000-C000-000000000046")
    IStdMarshalInfo : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetClassForHandler( 
            /* [annotation][in] */ 
            _In_  DWORD dwDestContext,
            /* [annotation][unique][in] */ 
            _Reserved_  void *pvDestContext,
            /* [annotation][out] */ 
            _Out_  CLSID *pClsid) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IStdMarshalInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IStdMarshalInfo * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IStdMarshalInfo * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IStdMarshalInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetClassForHandler )( 
            IStdMarshalInfo * This,
            /* [annotation][in] */ 
            _In_  DWORD dwDestContext,
            /* [annotation][unique][in] */ 
            _Reserved_  void *pvDestContext,
            /* [annotation][out] */ 
            _Out_  CLSID *pClsid);
        
        END_INTERFACE
    } IStdMarshalInfoVtbl;

    interface IStdMarshalInfo
    {
        CONST_VTBL struct IStdMarshalInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IStdMarshalInfo_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IStdMarshalInfo_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IStdMarshalInfo_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IStdMarshalInfo_GetClassForHandler(This,dwDestContext,pvDestContext,pClsid)	\
    ( (This)->lpVtbl -> GetClassForHandler(This,dwDestContext,pvDestContext,pClsid) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IStdMarshalInfo_INTERFACE_DEFINED__ */


#ifndef __IExternalConnection_INTERFACE_DEFINED__
#define __IExternalConnection_INTERFACE_DEFINED__

/* interface IExternalConnection */
/* [uuid][local][object] */ 

typedef /* [unique] */ IExternalConnection *LPEXTERNALCONNECTION;

typedef 
enum tagEXTCONN
    {
        EXTCONN_STRONG	= 0x1,
        EXTCONN_WEAK	= 0x2,
        EXTCONN_CALLABLE	= 0x4
    } 	EXTCONN;


EXTERN_C const IID IID_IExternalConnection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("00000019-0000-0000-C000-000000000046")
    IExternalConnection : public IUnknown
    {
    public:
        virtual DWORD STDMETHODCALLTYPE AddConnection( 
            /* [annotation][in] */ 
            _In_  DWORD extconn,
            /* [annotation][in] */ 
            _In_  DWORD reserved) = 0;
        
        virtual DWORD STDMETHODCALLTYPE ReleaseConnection( 
            /* [annotation][in] */ 
            _In_  DWORD extconn,
            /* [annotation][in] */ 
            _In_  DWORD reserved,
            /* [annotation][in] */ 
            _In_  BOOL fLastReleaseCloses) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IExternalConnectionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IExternalConnection * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IExternalConnection * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IExternalConnection * This);
        
        DWORD ( STDMETHODCALLTYPE *AddConnection )( 
            IExternalConnection * This,
            /* [annotation][in] */ 
            _In_  DWORD extconn,
            /* [annotation][in] */ 
            _In_  DWORD reserved);
        
        DWORD ( STDMETHODCALLTYPE *ReleaseConnection )( 
            IExternalConnection * This,
            /* [annotation][in] */ 
            _In_  DWORD extconn,
            /* [annotation][in] */ 
            _In_  DWORD reserved,
            /* [annotation][in] */ 
            _In_  BOOL fLastReleaseCloses);
        
        END_INTERFACE
    } IExternalConnectionVtbl;

    interface IExternalConnection
    {
        CONST_VTBL struct IExternalConnectionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IExternalConnection_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IExternalConnection_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IExternalConnection_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IExternalConnection_AddConnection(This,extconn,reserved)	\
    ( (This)->lpVtbl -> AddConnection(This,extconn,reserved) ) 

#define IExternalConnection_ReleaseConnection(This,extconn,reserved,fLastReleaseCloses)	\
    ( (This)->lpVtbl -> ReleaseConnection(This,extconn,reserved,fLastReleaseCloses) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IExternalConnection_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_objidlbase_0000_0008 */
/* [local] */ 

typedef /* [unique] */  __RPC_unique_pointer IMultiQI *LPMULTIQI;

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */
#pragma endregion
#pragma region Application Family or OneCore Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)
typedef struct tagMULTI_QI
    {
    const IID *pIID;
    IUnknown *pItf;
    HRESULT hr;
    } 	MULTI_QI;



extern RPC_IF_HANDLE __MIDL_itf_objidlbase_0000_0008_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_objidlbase_0000_0008_v0_0_s_ifspec;

#ifndef __IMultiQI_INTERFACE_DEFINED__
#define __IMultiQI_INTERFACE_DEFINED__

/* interface IMultiQI */
/* [async_uuid][uuid][local][object] */ 


EXTERN_C const IID IID_IMultiQI;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("00000020-0000-0000-C000-000000000046")
    IMultiQI : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE QueryMultipleInterfaces( 
            /* [annotation][in] */ 
            _In_  ULONG cMQIs,
            /* [annotation][out][in] */ 
            _Inout_updates_(cMQIs)  MULTI_QI *pMQIs) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IMultiQIVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMultiQI * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMultiQI * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMultiQI * This);
        
        HRESULT ( STDMETHODCALLTYPE *QueryMultipleInterfaces )( 
            IMultiQI * This,
            /* [annotation][in] */ 
            _In_  ULONG cMQIs,
            /* [annotation][out][in] */ 
            _Inout_updates_(cMQIs)  MULTI_QI *pMQIs);
        
        END_INTERFACE
    } IMultiQIVtbl;

    interface IMultiQI
    {
        CONST_VTBL struct IMultiQIVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMultiQI_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMultiQI_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMultiQI_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMultiQI_QueryMultipleInterfaces(This,cMQIs,pMQIs)	\
    ( (This)->lpVtbl -> QueryMultipleInterfaces(This,cMQIs,pMQIs) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMultiQI_INTERFACE_DEFINED__ */


#ifndef __AsyncIMultiQI_INTERFACE_DEFINED__
#define __AsyncIMultiQI_INTERFACE_DEFINED__

/* interface AsyncIMultiQI */
/* [uuid][local][object] */ 


EXTERN_C const IID IID_AsyncIMultiQI;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("000e0020-0000-0000-C000-000000000046")
    AsyncIMultiQI : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Begin_QueryMultipleInterfaces( 
            /* [annotation][in] */ 
            _In_  ULONG cMQIs,
            /* [annotation][out][in] */ 
            _Inout_updates_(cMQIs)  MULTI_QI *pMQIs) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_QueryMultipleInterfaces( 
            /* [annotation][out][in] */ 
            _Inout_updates_(cMQIs)  MULTI_QI *pMQIs) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct AsyncIMultiQIVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            AsyncIMultiQI * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            AsyncIMultiQI * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            AsyncIMultiQI * This);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_QueryMultipleInterfaces )( 
            AsyncIMultiQI * This,
            /* [annotation][in] */ 
            _In_  ULONG cMQIs,
            /* [annotation][out][in] */ 
            _Inout_updates_(cMQIs)  MULTI_QI *pMQIs);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_QueryMultipleInterfaces )( 
            AsyncIMultiQI * This,
            /* [annotation][out][in] */ 
            _Inout_updates_(cMQIs)  MULTI_QI *pMQIs);
        
        END_INTERFACE
    } AsyncIMultiQIVtbl;

    interface AsyncIMultiQI
    {
        CONST_VTBL struct AsyncIMultiQIVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define AsyncIMultiQI_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define AsyncIMultiQI_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define AsyncIMultiQI_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define AsyncIMultiQI_Begin_QueryMultipleInterfaces(This,cMQIs,pMQIs)	\
    ( (This)->lpVtbl -> Begin_QueryMultipleInterfaces(This,cMQIs,pMQIs) ) 

#define AsyncIMultiQI_Finish_QueryMultipleInterfaces(This,pMQIs)	\
    ( (This)->lpVtbl -> Finish_QueryMultipleInterfaces(This,pMQIs) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __AsyncIMultiQI_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_objidlbase_0000_0009 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */
#pragma endregion
#pragma region Desktop Family or OneCore Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)


extern RPC_IF_HANDLE __MIDL_itf_objidlbase_0000_0009_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_objidlbase_0000_0009_v0_0_s_ifspec;

#ifndef __IInternalUnknown_INTERFACE_DEFINED__
#define __IInternalUnknown_INTERFACE_DEFINED__

/* interface IInternalUnknown */
/* [uuid][local][object] */ 


EXTERN_C const IID IID_IInternalUnknown;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("00000021-0000-0000-C000-000000000046")
    IInternalUnknown : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE QueryInternalInterface( 
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][out] */ 
            _Outptr_  void **ppv) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IInternalUnknownVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInternalUnknown * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInternalUnknown * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInternalUnknown * This);
        
        HRESULT ( STDMETHODCALLTYPE *QueryInternalInterface )( 
            IInternalUnknown * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][out] */ 
            _Outptr_  void **ppv);
        
        END_INTERFACE
    } IInternalUnknownVtbl;

    interface IInternalUnknown
    {
        CONST_VTBL struct IInternalUnknownVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInternalUnknown_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInternalUnknown_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInternalUnknown_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInternalUnknown_QueryInternalInterface(This,riid,ppv)	\
    ( (This)->lpVtbl -> QueryInternalInterface(This,riid,ppv) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInternalUnknown_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_objidlbase_0000_0010 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */
#pragma endregion
#pragma region Application Family or OneCore Family or OneCore Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)


extern RPC_IF_HANDLE __MIDL_itf_objidlbase_0000_0010_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_objidlbase_0000_0010_v0_0_s_ifspec;

#ifndef __IEnumUnknown_INTERFACE_DEFINED__
#define __IEnumUnknown_INTERFACE_DEFINED__

/* interface IEnumUnknown */
/* [unique][uuid][object] */ 

typedef /* [unique] */  __RPC_unique_pointer IEnumUnknown *LPENUMUNKNOWN;


EXTERN_C const IID IID_IEnumUnknown;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("00000100-0000-0000-C000-000000000046")
    IEnumUnknown : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE Next( 
            /* [annotation][in] */ 
            _In_  ULONG celt,
            /* [annotation][out] */ 
            _Out_writes_to_(celt,*pceltFetched)  IUnknown **rgelt,
            /* [annotation][out] */ 
            _Out_opt_  ULONG *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [annotation][in] */ 
            _In_  ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [annotation][out] */ 
            _Out_  IEnumUnknown **ppenum) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IEnumUnknownVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IEnumUnknown * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IEnumUnknown * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IEnumUnknown * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Next )( 
            IEnumUnknown * This,
            /* [annotation][in] */ 
            _In_  ULONG celt,
            /* [annotation][out] */ 
            _Out_writes_to_(celt,*pceltFetched)  IUnknown **rgelt,
            /* [annotation][out] */ 
            _Out_opt_  ULONG *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            __RPC__in IEnumUnknown * This,
            /* [annotation][in] */ 
            _In_  ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            __RPC__in IEnumUnknown * This);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            __RPC__in IEnumUnknown * This,
            /* [annotation][out] */ 
            _Out_  IEnumUnknown **ppenum);
        
        END_INTERFACE
    } IEnumUnknownVtbl;

    interface IEnumUnknown
    {
        CONST_VTBL struct IEnumUnknownVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumUnknown_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEnumUnknown_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEnumUnknown_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IEnumUnknown_Next(This,celt,rgelt,pceltFetched)	\
    ( (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched) ) 

#define IEnumUnknown_Skip(This,celt)	\
    ( (This)->lpVtbl -> Skip(This,celt) ) 

#define IEnumUnknown_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define IEnumUnknown_Clone(This,ppenum)	\
    ( (This)->lpVtbl -> Clone(This,ppenum) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT STDMETHODCALLTYPE IEnumUnknown_RemoteNext_Proxy( 
    __RPC__in IEnumUnknown * This,
    /* [annotation][in] */ 
    _In_  ULONG celt,
    /* [annotation][length_is][size_is][out] */ 
    _Out_writes_to_(celt,*pceltFetched)  IUnknown **rgelt,
    /* [annotation][out] */ 
    _Out_  ULONG *pceltFetched);


void __RPC_STUB IEnumUnknown_RemoteNext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEnumUnknown_INTERFACE_DEFINED__ */


#ifndef __IEnumString_INTERFACE_DEFINED__
#define __IEnumString_INTERFACE_DEFINED__

/* interface IEnumString */
/* [unique][uuid][object] */ 

typedef /* [unique] */  __RPC_unique_pointer IEnumString *LPENUMSTRING;


EXTERN_C const IID IID_IEnumString;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("00000101-0000-0000-C000-000000000046")
    IEnumString : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE Next( 
            /* [annotation][in] */ 
            _In_  ULONG celt,
            /* [annotation] */ 
            _Out_writes_to_(celt,*pceltFetched)  LPOLESTR *rgelt,
            /* [annotation] */ 
            _Out_opt_  ULONG *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [annotation][in] */ 
            _In_  ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [annotation][out] */ 
            _Out_  IEnumString **ppenum) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IEnumStringVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IEnumString * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IEnumString * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IEnumString * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Next )( 
            IEnumString * This,
            /* [annotation][in] */ 
            _In_  ULONG celt,
            /* [annotation] */ 
            _Out_writes_to_(celt,*pceltFetched)  LPOLESTR *rgelt,
            /* [annotation] */ 
            _Out_opt_  ULONG *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            __RPC__in IEnumString * This,
            /* [annotation][in] */ 
            _In_  ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            __RPC__in IEnumString * This);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            __RPC__in IEnumString * This,
            /* [annotation][out] */ 
            _Out_  IEnumString **ppenum);
        
        END_INTERFACE
    } IEnumStringVtbl;

    interface IEnumString
    {
        CONST_VTBL struct IEnumStringVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumString_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEnumString_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEnumString_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IEnumString_Next(This,celt,rgelt,pceltFetched)	\
    ( (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched) ) 

#define IEnumString_Skip(This,celt)	\
    ( (This)->lpVtbl -> Skip(This,celt) ) 

#define IEnumString_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define IEnumString_Clone(This,ppenum)	\
    ( (This)->lpVtbl -> Clone(This,ppenum) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT STDMETHODCALLTYPE IEnumString_RemoteNext_Proxy( 
    __RPC__in IEnumString * This,
    /* [annotation][in] */ 
    _In_  ULONG celt,
    /* [annotation][length_is][size_is][out] */ 
    _Out_writes_to_(celt,*pceltFetched)  LPOLESTR *rgelt,
    /* [annotation][out] */ 
    _Out_  ULONG *pceltFetched);


void __RPC_STUB IEnumString_RemoteNext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEnumString_INTERFACE_DEFINED__ */


#ifndef __ISequentialStream_INTERFACE_DEFINED__
#define __ISequentialStream_INTERFACE_DEFINED__

/* interface ISequentialStream */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_ISequentialStream;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733a30-2a1c-11ce-ade5-00aa0044773d")
    ISequentialStream : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE Read( 
            /* [annotation] */ 
            _Out_writes_bytes_to_(cb, *pcbRead)  void *pv,
            /* [annotation][in] */ 
            _In_  ULONG cb,
            /* [annotation] */ 
            _Out_opt_  ULONG *pcbRead) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE Write( 
            /* [annotation] */ 
            _In_reads_bytes_(cb)  const void *pv,
            /* [annotation][in] */ 
            _In_  ULONG cb,
            /* [annotation] */ 
            _Out_opt_  ULONG *pcbWritten) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISequentialStreamVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISequentialStream * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISequentialStream * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISequentialStream * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Read )( 
            ISequentialStream * This,
            /* [annotation] */ 
            _Out_writes_bytes_to_(cb, *pcbRead)  void *pv,
            /* [annotation][in] */ 
            _In_  ULONG cb,
            /* [annotation] */ 
            _Out_opt_  ULONG *pcbRead);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Write )( 
            ISequentialStream * This,
            /* [annotation] */ 
            _In_reads_bytes_(cb)  const void *pv,
            /* [annotation][in] */ 
            _In_  ULONG cb,
            /* [annotation] */ 
            _Out_opt_  ULONG *pcbWritten);
        
        END_INTERFACE
    } ISequentialStreamVtbl;

    interface ISequentialStream
    {
        CONST_VTBL struct ISequentialStreamVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISequentialStream_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISequentialStream_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISequentialStream_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISequentialStream_Read(This,pv,cb,pcbRead)	\
    ( (This)->lpVtbl -> Read(This,pv,cb,pcbRead) ) 

#define ISequentialStream_Write(This,pv,cb,pcbWritten)	\
    ( (This)->lpVtbl -> Write(This,pv,cb,pcbWritten) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT STDMETHODCALLTYPE ISequentialStream_RemoteRead_Proxy( 
    __RPC__in ISequentialStream * This,
    /* [annotation][length_is][size_is][out] */ 
    _Out_writes_to_(cb,*pcbRead)  byte *pv,
    /* [annotation][in] */ 
    _In_  ULONG cb,
    /* [annotation][out] */ 
    _Out_  ULONG *pcbRead);


void __RPC_STUB ISequentialStream_RemoteRead_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [call_as] */ HRESULT STDMETHODCALLTYPE ISequentialStream_RemoteWrite_Proxy( 
    __RPC__in ISequentialStream * This,
    /* [annotation][size_is][in] */ 
    _In_reads_(cb)  const byte *pv,
    /* [annotation][in] */ 
    _In_  ULONG cb,
    /* [annotation][out] */ 
    _Out_  ULONG *pcbWritten);


void __RPC_STUB ISequentialStream_RemoteWrite_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ISequentialStream_INTERFACE_DEFINED__ */


#ifndef __IStream_INTERFACE_DEFINED__
#define __IStream_INTERFACE_DEFINED__

/* interface IStream */
/* [unique][uuid][object] */ 

typedef /* [unique] */  __RPC_unique_pointer IStream *LPSTREAM;

typedef struct tagSTATSTG
    {
    LPOLESTR pwcsName;
    DWORD type;
    ULARGE_INTEGER cbSize;
    FILETIME mtime;
    FILETIME ctime;
    FILETIME atime;
    DWORD grfMode;
    DWORD grfLocksSupported;
    CLSID clsid;
    DWORD grfStateBits;
    DWORD reserved;
    } 	STATSTG;

typedef 
enum tagSTGTY
    {
        STGTY_STORAGE	= 1,
        STGTY_STREAM	= 2,
        STGTY_LOCKBYTES	= 3,
        STGTY_PROPERTY	= 4
    } 	STGTY;

typedef 
enum tagSTREAM_SEEK
    {
        STREAM_SEEK_SET	= 0,
        STREAM_SEEK_CUR	= 1,
        STREAM_SEEK_END	= 2
    } 	STREAM_SEEK;

typedef 
enum tagLOCKTYPE
    {
        LOCK_WRITE	= 1,
        LOCK_EXCLUSIVE	= 2,
        LOCK_ONLYONCE	= 4
    } 	LOCKTYPE;


EXTERN_C const IID IID_IStream;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0000000c-0000-0000-C000-000000000046")
    IStream : public ISequentialStream
    {
    public:
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE Seek( 
            /* [annotation][in] */ 
            _In_  LARGE_INTEGER dlibMove,
            /* [annotation][in] */ 
            _In_  DWORD dwOrigin,
            /* [annotation] */ 
            _Out_opt_  ULARGE_INTEGER *plibNewPosition) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetSize( 
            /* [annotation][in] */ 
            _In_  ULARGE_INTEGER libNewSize) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE CopyTo( 
            /* [annotation][unique][in] */ 
            _In_  IStream *pstm,
            /* [annotation][in] */ 
            _In_  ULARGE_INTEGER cb,
            /* [annotation] */ 
            _Out_opt_  ULARGE_INTEGER *pcbRead,
            /* [annotation] */ 
            _Out_opt_  ULARGE_INTEGER *pcbWritten) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Commit( 
            /* [annotation][in] */ 
            _In_  DWORD grfCommitFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Revert( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LockRegion( 
            /* [annotation][in] */ 
            _In_  ULARGE_INTEGER libOffset,
            /* [annotation][in] */ 
            _In_  ULARGE_INTEGER cb,
            /* [annotation][in] */ 
            _In_  DWORD dwLockType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UnlockRegion( 
            /* [annotation][in] */ 
            _In_  ULARGE_INTEGER libOffset,
            /* [annotation][in] */ 
            _In_  ULARGE_INTEGER cb,
            /* [annotation][in] */ 
            _In_  DWORD dwLockType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Stat( 
            /* [annotation][out] */ 
            _Out_  STATSTG *pstatstg,
            /* [annotation][in] */ 
            _In_  DWORD grfStatFlag) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [annotation][out] */ 
            _Out_  IStream **ppstm) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IStreamVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IStream * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IStream * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IStream * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Read )( 
            IStream * This,
            /* [annotation] */ 
            _Out_writes_bytes_to_(cb, *pcbRead)  void *pv,
            /* [annotation][in] */ 
            _In_  ULONG cb,
            /* [annotation] */ 
            _Out_opt_  ULONG *pcbRead);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Write )( 
            IStream * This,
            /* [annotation] */ 
            _In_reads_bytes_(cb)  const void *pv,
            /* [annotation][in] */ 
            _In_  ULONG cb,
            /* [annotation] */ 
            _Out_opt_  ULONG *pcbWritten);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Seek )( 
            IStream * This,
            /* [annotation][in] */ 
            _In_  LARGE_INTEGER dlibMove,
            /* [annotation][in] */ 
            _In_  DWORD dwOrigin,
            /* [annotation] */ 
            _Out_opt_  ULARGE_INTEGER *plibNewPosition);
        
        HRESULT ( STDMETHODCALLTYPE *SetSize )( 
            __RPC__in IStream * This,
            /* [annotation][in] */ 
            _In_  ULARGE_INTEGER libNewSize);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *CopyTo )( 
            IStream * This,
            /* [annotation][unique][in] */ 
            _In_  IStream *pstm,
            /* [annotation][in] */ 
            _In_  ULARGE_INTEGER cb,
            /* [annotation] */ 
            _Out_opt_  ULARGE_INTEGER *pcbRead,
            /* [annotation] */ 
            _Out_opt_  ULARGE_INTEGER *pcbWritten);
        
        HRESULT ( STDMETHODCALLTYPE *Commit )( 
            __RPC__in IStream * This,
            /* [annotation][in] */ 
            _In_  DWORD grfCommitFlags);
        
        HRESULT ( STDMETHODCALLTYPE *Revert )( 
            __RPC__in IStream * This);
        
        HRESULT ( STDMETHODCALLTYPE *LockRegion )( 
            __RPC__in IStream * This,
            /* [annotation][in] */ 
            _In_  ULARGE_INTEGER libOffset,
            /* [annotation][in] */ 
            _In_  ULARGE_INTEGER cb,
            /* [annotation][in] */ 
            _In_  DWORD dwLockType);
        
        HRESULT ( STDMETHODCALLTYPE *UnlockRegion )( 
            __RPC__in IStream * This,
            /* [annotation][in] */ 
            _In_  ULARGE_INTEGER libOffset,
            /* [annotation][in] */ 
            _In_  ULARGE_INTEGER cb,
            /* [annotation][in] */ 
            _In_  DWORD dwLockType);
        
        HRESULT ( STDMETHODCALLTYPE *Stat )( 
            __RPC__in IStream * This,
            /* [annotation][out] */ 
            _Out_  STATSTG *pstatstg,
            /* [annotation][in] */ 
            _In_  DWORD grfStatFlag);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            __RPC__in IStream * This,
            /* [annotation][out] */ 
            _Out_  IStream **ppstm);
        
        END_INTERFACE
    } IStreamVtbl;

    interface IStream
    {
        CONST_VTBL struct IStreamVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IStream_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IStream_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IStream_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IStream_Read(This,pv,cb,pcbRead)	\
    ( (This)->lpVtbl -> Read(This,pv,cb,pcbRead) ) 

#define IStream_Write(This,pv,cb,pcbWritten)	\
    ( (This)->lpVtbl -> Write(This,pv,cb,pcbWritten) ) 


#define IStream_Seek(This,dlibMove,dwOrigin,plibNewPosition)	\
    ( (This)->lpVtbl -> Seek(This,dlibMove,dwOrigin,plibNewPosition) ) 

#define IStream_SetSize(This,libNewSize)	\
    ( (This)->lpVtbl -> SetSize(This,libNewSize) ) 

#define IStream_CopyTo(This,pstm,cb,pcbRead,pcbWritten)	\
    ( (This)->lpVtbl -> CopyTo(This,pstm,cb,pcbRead,pcbWritten) ) 

#define IStream_Commit(This,grfCommitFlags)	\
    ( (This)->lpVtbl -> Commit(This,grfCommitFlags) ) 

#define IStream_Revert(This)	\
    ( (This)->lpVtbl -> Revert(This) ) 

#define IStream_LockRegion(This,libOffset,cb,dwLockType)	\
    ( (This)->lpVtbl -> LockRegion(This,libOffset,cb,dwLockType) ) 

#define IStream_UnlockRegion(This,libOffset,cb,dwLockType)	\
    ( (This)->lpVtbl -> UnlockRegion(This,libOffset,cb,dwLockType) ) 

#define IStream_Stat(This,pstatstg,grfStatFlag)	\
    ( (This)->lpVtbl -> Stat(This,pstatstg,grfStatFlag) ) 

#define IStream_Clone(This,ppstm)	\
    ( (This)->lpVtbl -> Clone(This,ppstm) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT STDMETHODCALLTYPE IStream_RemoteSeek_Proxy( 
    __RPC__in IStream * This,
    /* [annotation][in] */ 
    _In_  LARGE_INTEGER dlibMove,
    /* [annotation][in] */ 
    _In_  DWORD dwOrigin,
    /* [annotation][out] */ 
    _Out_  ULARGE_INTEGER *plibNewPosition);


void __RPC_STUB IStream_RemoteSeek_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IStream_RemoteCopyTo_Proxy( 
    __RPC__in IStream * This,
    /* [annotation][unique][in] */ 
    _In_  IStream *pstm,
    /* [annotation][in] */ 
    _In_  ULARGE_INTEGER cb,
    /* [annotation][out] */ 
    _Out_  ULARGE_INTEGER *pcbRead,
    /* [annotation][out] */ 
    _Out_  ULARGE_INTEGER *pcbWritten);


void __RPC_STUB IStream_RemoteCopyTo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IStream_INTERFACE_DEFINED__ */


#ifndef __IRpcChannelBuffer_INTERFACE_DEFINED__
#define __IRpcChannelBuffer_INTERFACE_DEFINED__

/* interface IRpcChannelBuffer */
/* [uuid][object][local] */ 

typedef ULONG RPCOLEDATAREP;

typedef struct tagRPCOLEMESSAGE
    {
    void *reserved1;
    RPCOLEDATAREP dataRepresentation;
    void *Buffer;
    ULONG cbBuffer;
    ULONG iMethod;
    void *reserved2[ 5 ];
    ULONG rpcFlags;
    } 	RPCOLEMESSAGE;

typedef RPCOLEMESSAGE *PRPCOLEMESSAGE;


EXTERN_C const IID IID_IRpcChannelBuffer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D5F56B60-593B-101A-B569-08002B2DBF7A")
    IRpcChannelBuffer : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetBuffer( 
            /* [annotation][out][in] */ 
            _Inout_  RPCOLEMESSAGE *pMessage,
            /* [annotation][in] */ 
            _In_  REFIID riid) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SendReceive( 
            /* [annotation][out][in] */ 
            _Inout_  RPCOLEMESSAGE *pMessage,
            /* [annotation][out] */ 
            _Out_opt_  ULONG *pStatus) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FreeBuffer( 
            /* [annotation][out][in] */ 
            _Inout_  RPCOLEMESSAGE *pMessage) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDestCtx( 
            /* [annotation][out] */ 
            _Out_  DWORD *pdwDestContext,
            /* [annotation][out] */ 
            _Outptr_result_maybenull_  void **ppvDestContext) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsConnected( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRpcChannelBufferVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRpcChannelBuffer * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRpcChannelBuffer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRpcChannelBuffer * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetBuffer )( 
            IRpcChannelBuffer * This,
            /* [annotation][out][in] */ 
            _Inout_  RPCOLEMESSAGE *pMessage,
            /* [annotation][in] */ 
            _In_  REFIID riid);
        
        HRESULT ( STDMETHODCALLTYPE *SendReceive )( 
            IRpcChannelBuffer * This,
            /* [annotation][out][in] */ 
            _Inout_  RPCOLEMESSAGE *pMessage,
            /* [annotation][out] */ 
            _Out_opt_  ULONG *pStatus);
        
        HRESULT ( STDMETHODCALLTYPE *FreeBuffer )( 
            IRpcChannelBuffer * This,
            /* [annotation][out][in] */ 
            _Inout_  RPCOLEMESSAGE *pMessage);
        
        HRESULT ( STDMETHODCALLTYPE *GetDestCtx )( 
            IRpcChannelBuffer * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwDestContext,
            /* [annotation][out] */ 
            _Outptr_result_maybenull_  void **ppvDestContext);
        
        HRESULT ( STDMETHODCALLTYPE *IsConnected )( 
            IRpcChannelBuffer * This);
        
        END_INTERFACE
    } IRpcChannelBufferVtbl;

    interface IRpcChannelBuffer
    {
        CONST_VTBL struct IRpcChannelBufferVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRpcChannelBuffer_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRpcChannelBuffer_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRpcChannelBuffer_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRpcChannelBuffer_GetBuffer(This,pMessage,riid)	\
    ( (This)->lpVtbl -> GetBuffer(This,pMessage,riid) ) 

#define IRpcChannelBuffer_SendReceive(This,pMessage,pStatus)	\
    ( (This)->lpVtbl -> SendReceive(This,pMessage,pStatus) ) 

#define IRpcChannelBuffer_FreeBuffer(This,pMessage)	\
    ( (This)->lpVtbl -> FreeBuffer(This,pMessage) ) 

#define IRpcChannelBuffer_GetDestCtx(This,pdwDestContext,ppvDestContext)	\
    ( (This)->lpVtbl -> GetDestCtx(This,pdwDestContext,ppvDestContext) ) 

#define IRpcChannelBuffer_IsConnected(This)	\
    ( (This)->lpVtbl -> IsConnected(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRpcChannelBuffer_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_objidlbase_0000_0015 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */
#pragma endregion
#pragma region Desktop Family or OneCore Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)


extern RPC_IF_HANDLE __MIDL_itf_objidlbase_0000_0015_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_objidlbase_0000_0015_v0_0_s_ifspec;

#ifndef __IRpcChannelBuffer2_INTERFACE_DEFINED__
#define __IRpcChannelBuffer2_INTERFACE_DEFINED__

/* interface IRpcChannelBuffer2 */
/* [uuid][object][local] */ 


EXTERN_C const IID IID_IRpcChannelBuffer2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("594f31d0-7f19-11d0-b194-00a0c90dc8bf")
    IRpcChannelBuffer2 : public IRpcChannelBuffer
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetProtocolVersion( 
            /* [annotation][out] */ 
            _Out_  DWORD *pdwVersion) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRpcChannelBuffer2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRpcChannelBuffer2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRpcChannelBuffer2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRpcChannelBuffer2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetBuffer )( 
            IRpcChannelBuffer2 * This,
            /* [annotation][out][in] */ 
            _Inout_  RPCOLEMESSAGE *pMessage,
            /* [annotation][in] */ 
            _In_  REFIID riid);
        
        HRESULT ( STDMETHODCALLTYPE *SendReceive )( 
            IRpcChannelBuffer2 * This,
            /* [annotation][out][in] */ 
            _Inout_  RPCOLEMESSAGE *pMessage,
            /* [annotation][out] */ 
            _Out_opt_  ULONG *pStatus);
        
        HRESULT ( STDMETHODCALLTYPE *FreeBuffer )( 
            IRpcChannelBuffer2 * This,
            /* [annotation][out][in] */ 
            _Inout_  RPCOLEMESSAGE *pMessage);
        
        HRESULT ( STDMETHODCALLTYPE *GetDestCtx )( 
            IRpcChannelBuffer2 * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwDestContext,
            /* [annotation][out] */ 
            _Outptr_result_maybenull_  void **ppvDestContext);
        
        HRESULT ( STDMETHODCALLTYPE *IsConnected )( 
            IRpcChannelBuffer2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetProtocolVersion )( 
            IRpcChannelBuffer2 * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwVersion);
        
        END_INTERFACE
    } IRpcChannelBuffer2Vtbl;

    interface IRpcChannelBuffer2
    {
        CONST_VTBL struct IRpcChannelBuffer2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRpcChannelBuffer2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRpcChannelBuffer2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRpcChannelBuffer2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRpcChannelBuffer2_GetBuffer(This,pMessage,riid)	\
    ( (This)->lpVtbl -> GetBuffer(This,pMessage,riid) ) 

#define IRpcChannelBuffer2_SendReceive(This,pMessage,pStatus)	\
    ( (This)->lpVtbl -> SendReceive(This,pMessage,pStatus) ) 

#define IRpcChannelBuffer2_FreeBuffer(This,pMessage)	\
    ( (This)->lpVtbl -> FreeBuffer(This,pMessage) ) 

#define IRpcChannelBuffer2_GetDestCtx(This,pdwDestContext,ppvDestContext)	\
    ( (This)->lpVtbl -> GetDestCtx(This,pdwDestContext,ppvDestContext) ) 

#define IRpcChannelBuffer2_IsConnected(This)	\
    ( (This)->lpVtbl -> IsConnected(This) ) 


#define IRpcChannelBuffer2_GetProtocolVersion(This,pdwVersion)	\
    ( (This)->lpVtbl -> GetProtocolVersion(This,pdwVersion) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRpcChannelBuffer2_INTERFACE_DEFINED__ */


#ifndef __IAsyncRpcChannelBuffer_INTERFACE_DEFINED__
#define __IAsyncRpcChannelBuffer_INTERFACE_DEFINED__

/* interface IAsyncRpcChannelBuffer */
/* [unique][uuid][object][local] */ 


EXTERN_C const IID IID_IAsyncRpcChannelBuffer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("a5029fb6-3c34-11d1-9c99-00c04fb998aa")
    IAsyncRpcChannelBuffer : public IRpcChannelBuffer2
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Send( 
            /* [annotation][out][in] */ 
            _Inout_  RPCOLEMESSAGE *pMsg,
            /* [annotation][in] */ 
            _In_  ISynchronize *pSync,
            /* [annotation][out] */ 
            _Out_  ULONG *pulStatus) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Receive( 
            /* [annotation][out][in] */ 
            _Inout_  RPCOLEMESSAGE *pMsg,
            /* [annotation][out] */ 
            _Out_  ULONG *pulStatus) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDestCtxEx( 
            /* [annotation][in] */ 
            _In_  RPCOLEMESSAGE *pMsg,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwDestContext,
            /* [annotation][out] */ 
            _Outptr_opt_result_maybenull_  void **ppvDestContext) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAsyncRpcChannelBufferVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAsyncRpcChannelBuffer * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAsyncRpcChannelBuffer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAsyncRpcChannelBuffer * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetBuffer )( 
            IAsyncRpcChannelBuffer * This,
            /* [annotation][out][in] */ 
            _Inout_  RPCOLEMESSAGE *pMessage,
            /* [annotation][in] */ 
            _In_  REFIID riid);
        
        HRESULT ( STDMETHODCALLTYPE *SendReceive )( 
            IAsyncRpcChannelBuffer * This,
            /* [annotation][out][in] */ 
            _Inout_  RPCOLEMESSAGE *pMessage,
            /* [annotation][out] */ 
            _Out_opt_  ULONG *pStatus);
        
        HRESULT ( STDMETHODCALLTYPE *FreeBuffer )( 
            IAsyncRpcChannelBuffer * This,
            /* [annotation][out][in] */ 
            _Inout_  RPCOLEMESSAGE *pMessage);
        
        HRESULT ( STDMETHODCALLTYPE *GetDestCtx )( 
            IAsyncRpcChannelBuffer * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwDestContext,
            /* [annotation][out] */ 
            _Outptr_result_maybenull_  void **ppvDestContext);
        
        HRESULT ( STDMETHODCALLTYPE *IsConnected )( 
            IAsyncRpcChannelBuffer * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetProtocolVersion )( 
            IAsyncRpcChannelBuffer * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwVersion);
        
        HRESULT ( STDMETHODCALLTYPE *Send )( 
            IAsyncRpcChannelBuffer * This,
            /* [annotation][out][in] */ 
            _Inout_  RPCOLEMESSAGE *pMsg,
            /* [annotation][in] */ 
            _In_  ISynchronize *pSync,
            /* [annotation][out] */ 
            _Out_  ULONG *pulStatus);
        
        HRESULT ( STDMETHODCALLTYPE *Receive )( 
            IAsyncRpcChannelBuffer * This,
            /* [annotation][out][in] */ 
            _Inout_  RPCOLEMESSAGE *pMsg,
            /* [annotation][out] */ 
            _Out_  ULONG *pulStatus);
        
        HRESULT ( STDMETHODCALLTYPE *GetDestCtxEx )( 
            IAsyncRpcChannelBuffer * This,
            /* [annotation][in] */ 
            _In_  RPCOLEMESSAGE *pMsg,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwDestContext,
            /* [annotation][out] */ 
            _Outptr_opt_result_maybenull_  void **ppvDestContext);
        
        END_INTERFACE
    } IAsyncRpcChannelBufferVtbl;

    interface IAsyncRpcChannelBuffer
    {
        CONST_VTBL struct IAsyncRpcChannelBufferVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAsyncRpcChannelBuffer_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAsyncRpcChannelBuffer_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAsyncRpcChannelBuffer_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAsyncRpcChannelBuffer_GetBuffer(This,pMessage,riid)	\
    ( (This)->lpVtbl -> GetBuffer(This,pMessage,riid) ) 

#define IAsyncRpcChannelBuffer_SendReceive(This,pMessage,pStatus)	\
    ( (This)->lpVtbl -> SendReceive(This,pMessage,pStatus) ) 

#define IAsyncRpcChannelBuffer_FreeBuffer(This,pMessage)	\
    ( (This)->lpVtbl -> FreeBuffer(This,pMessage) ) 

#define IAsyncRpcChannelBuffer_GetDestCtx(This,pdwDestContext,ppvDestContext)	\
    ( (This)->lpVtbl -> GetDestCtx(This,pdwDestContext,ppvDestContext) ) 

#define IAsyncRpcChannelBuffer_IsConnected(This)	\
    ( (This)->lpVtbl -> IsConnected(This) ) 


#define IAsyncRpcChannelBuffer_GetProtocolVersion(This,pdwVersion)	\
    ( (This)->lpVtbl -> GetProtocolVersion(This,pdwVersion) ) 


#define IAsyncRpcChannelBuffer_Send(This,pMsg,pSync,pulStatus)	\
    ( (This)->lpVtbl -> Send(This,pMsg,pSync,pulStatus) ) 

#define IAsyncRpcChannelBuffer_Receive(This,pMsg,pulStatus)	\
    ( (This)->lpVtbl -> Receive(This,pMsg,pulStatus) ) 

#define IAsyncRpcChannelBuffer_GetDestCtxEx(This,pMsg,pdwDestContext,ppvDestContext)	\
    ( (This)->lpVtbl -> GetDestCtxEx(This,pMsg,pdwDestContext,ppvDestContext) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAsyncRpcChannelBuffer_INTERFACE_DEFINED__ */


#ifndef __IRpcChannelBuffer3_INTERFACE_DEFINED__
#define __IRpcChannelBuffer3_INTERFACE_DEFINED__

/* interface IRpcChannelBuffer3 */
/* [uuid][object][local] */ 


EXTERN_C const IID IID_IRpcChannelBuffer3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("25B15600-0115-11d0-BF0D-00AA00B8DFD2")
    IRpcChannelBuffer3 : public IRpcChannelBuffer2
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Send( 
            /* [annotation][out][in] */ 
            _Inout_  RPCOLEMESSAGE *pMsg,
            /* [annotation][out] */ 
            _Out_  ULONG *pulStatus) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Receive( 
            /* [annotation][out][in] */ 
            _Inout_  RPCOLEMESSAGE *pMsg,
            /* [annotation][in] */ 
            _In_  ULONG ulSize,
            /* [annotation][out] */ 
            _Out_  ULONG *pulStatus) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Cancel( 
            /* [annotation][out][in] */ 
            _Inout_  RPCOLEMESSAGE *pMsg) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCallContext( 
            /* [annotation][in] */ 
            _In_  RPCOLEMESSAGE *pMsg,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][out] */ 
            _Outptr_  void **pInterface) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDestCtxEx( 
            /* [annotation][in] */ 
            _In_  RPCOLEMESSAGE *pMsg,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwDestContext,
            /* [annotation][out] */ 
            _Outptr_opt_result_maybenull_  void **ppvDestContext) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetState( 
            /* [annotation][in] */ 
            _In_  RPCOLEMESSAGE *pMsg,
            /* [annotation][out] */ 
            _Out_  DWORD *pState) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RegisterAsync( 
            /* [annotation][out][in] */ 
            _Inout_  RPCOLEMESSAGE *pMsg,
            /* [annotation][in] */ 
            _In_  IAsyncManager *pAsyncMgr) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRpcChannelBuffer3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRpcChannelBuffer3 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRpcChannelBuffer3 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRpcChannelBuffer3 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetBuffer )( 
            IRpcChannelBuffer3 * This,
            /* [annotation][out][in] */ 
            _Inout_  RPCOLEMESSAGE *pMessage,
            /* [annotation][in] */ 
            _In_  REFIID riid);
        
        HRESULT ( STDMETHODCALLTYPE *SendReceive )( 
            IRpcChannelBuffer3 * This,
            /* [annotation][out][in] */ 
            _Inout_  RPCOLEMESSAGE *pMessage,
            /* [annotation][out] */ 
            _Out_opt_  ULONG *pStatus);
        
        HRESULT ( STDMETHODCALLTYPE *FreeBuffer )( 
            IRpcChannelBuffer3 * This,
            /* [annotation][out][in] */ 
            _Inout_  RPCOLEMESSAGE *pMessage);
        
        HRESULT ( STDMETHODCALLTYPE *GetDestCtx )( 
            IRpcChannelBuffer3 * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwDestContext,
            /* [annotation][out] */ 
            _Outptr_result_maybenull_  void **ppvDestContext);
        
        HRESULT ( STDMETHODCALLTYPE *IsConnected )( 
            IRpcChannelBuffer3 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetProtocolVersion )( 
            IRpcChannelBuffer3 * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwVersion);
        
        HRESULT ( STDMETHODCALLTYPE *Send )( 
            IRpcChannelBuffer3 * This,
            /* [annotation][out][in] */ 
            _Inout_  RPCOLEMESSAGE *pMsg,
            /* [annotation][out] */ 
            _Out_  ULONG *pulStatus);
        
        HRESULT ( STDMETHODCALLTYPE *Receive )( 
            IRpcChannelBuffer3 * This,
            /* [annotation][out][in] */ 
            _Inout_  RPCOLEMESSAGE *pMsg,
            /* [annotation][in] */ 
            _In_  ULONG ulSize,
            /* [annotation][out] */ 
            _Out_  ULONG *pulStatus);
        
        HRESULT ( STDMETHODCALLTYPE *Cancel )( 
            IRpcChannelBuffer3 * This,
            /* [annotation][out][in] */ 
            _Inout_  RPCOLEMESSAGE *pMsg);
        
        HRESULT ( STDMETHODCALLTYPE *GetCallContext )( 
            IRpcChannelBuffer3 * This,
            /* [annotation][in] */ 
            _In_  RPCOLEMESSAGE *pMsg,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][out] */ 
            _Outptr_  void **pInterface);
        
        HRESULT ( STDMETHODCALLTYPE *GetDestCtxEx )( 
            IRpcChannelBuffer3 * This,
            /* [annotation][in] */ 
            _In_  RPCOLEMESSAGE *pMsg,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwDestContext,
            /* [annotation][out] */ 
            _Outptr_opt_result_maybenull_  void **ppvDestContext);
        
        HRESULT ( STDMETHODCALLTYPE *GetState )( 
            IRpcChannelBuffer3 * This,
            /* [annotation][in] */ 
            _In_  RPCOLEMESSAGE *pMsg,
            /* [annotation][out] */ 
            _Out_  DWORD *pState);
        
        HRESULT ( STDMETHODCALLTYPE *RegisterAsync )( 
            IRpcChannelBuffer3 * This,
            /* [annotation][out][in] */ 
            _Inout_  RPCOLEMESSAGE *pMsg,
            /* [annotation][in] */ 
            _In_  IAsyncManager *pAsyncMgr);
        
        END_INTERFACE
    } IRpcChannelBuffer3Vtbl;

    interface IRpcChannelBuffer3
    {
        CONST_VTBL struct IRpcChannelBuffer3Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRpcChannelBuffer3_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRpcChannelBuffer3_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRpcChannelBuffer3_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRpcChannelBuffer3_GetBuffer(This,pMessage,riid)	\
    ( (This)->lpVtbl -> GetBuffer(This,pMessage,riid) ) 

#define IRpcChannelBuffer3_SendReceive(This,pMessage,pStatus)	\
    ( (This)->lpVtbl -> SendReceive(This,pMessage,pStatus) ) 

#define IRpcChannelBuffer3_FreeBuffer(This,pMessage)	\
    ( (This)->lpVtbl -> FreeBuffer(This,pMessage) ) 

#define IRpcChannelBuffer3_GetDestCtx(This,pdwDestContext,ppvDestContext)	\
    ( (This)->lpVtbl -> GetDestCtx(This,pdwDestContext,ppvDestContext) ) 

#define IRpcChannelBuffer3_IsConnected(This)	\
    ( (This)->lpVtbl -> IsConnected(This) ) 


#define IRpcChannelBuffer3_GetProtocolVersion(This,pdwVersion)	\
    ( (This)->lpVtbl -> GetProtocolVersion(This,pdwVersion) ) 


#define IRpcChannelBuffer3_Send(This,pMsg,pulStatus)	\
    ( (This)->lpVtbl -> Send(This,pMsg,pulStatus) ) 

#define IRpcChannelBuffer3_Receive(This,pMsg,ulSize,pulStatus)	\
    ( (This)->lpVtbl -> Receive(This,pMsg,ulSize,pulStatus) ) 

#define IRpcChannelBuffer3_Cancel(This,pMsg)	\
    ( (This)->lpVtbl -> Cancel(This,pMsg) ) 

#define IRpcChannelBuffer3_GetCallContext(This,pMsg,riid,pInterface)	\
    ( (This)->lpVtbl -> GetCallContext(This,pMsg,riid,pInterface) ) 

#define IRpcChannelBuffer3_GetDestCtxEx(This,pMsg,pdwDestContext,ppvDestContext)	\
    ( (This)->lpVtbl -> GetDestCtxEx(This,pMsg,pdwDestContext,ppvDestContext) ) 

#define IRpcChannelBuffer3_GetState(This,pMsg,pState)	\
    ( (This)->lpVtbl -> GetState(This,pMsg,pState) ) 

#define IRpcChannelBuffer3_RegisterAsync(This,pMsg,pAsyncMgr)	\
    ( (This)->lpVtbl -> RegisterAsync(This,pMsg,pAsyncMgr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRpcChannelBuffer3_INTERFACE_DEFINED__ */


#ifndef __IRpcSyntaxNegotiate_INTERFACE_DEFINED__
#define __IRpcSyntaxNegotiate_INTERFACE_DEFINED__

/* interface IRpcSyntaxNegotiate */
/* [uuid][object][local] */ 


EXTERN_C const IID IID_IRpcSyntaxNegotiate;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("58a08519-24c8-4935-b482-3fd823333a4f")
    IRpcSyntaxNegotiate : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE NegotiateSyntax( 
            /* [annotation][out][in] */ 
            _Inout_  RPCOLEMESSAGE *pMsg) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRpcSyntaxNegotiateVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRpcSyntaxNegotiate * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRpcSyntaxNegotiate * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRpcSyntaxNegotiate * This);
        
        HRESULT ( STDMETHODCALLTYPE *NegotiateSyntax )( 
            IRpcSyntaxNegotiate * This,
            /* [annotation][out][in] */ 
            _Inout_  RPCOLEMESSAGE *pMsg);
        
        END_INTERFACE
    } IRpcSyntaxNegotiateVtbl;

    interface IRpcSyntaxNegotiate
    {
        CONST_VTBL struct IRpcSyntaxNegotiateVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRpcSyntaxNegotiate_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRpcSyntaxNegotiate_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRpcSyntaxNegotiate_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRpcSyntaxNegotiate_NegotiateSyntax(This,pMsg)	\
    ( (This)->lpVtbl -> NegotiateSyntax(This,pMsg) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRpcSyntaxNegotiate_INTERFACE_DEFINED__ */


#ifndef __IRpcProxyBuffer_INTERFACE_DEFINED__
#define __IRpcProxyBuffer_INTERFACE_DEFINED__

/* interface IRpcProxyBuffer */
/* [uuid][object][local] */ 


EXTERN_C const IID IID_IRpcProxyBuffer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D5F56A34-593B-101A-B569-08002B2DBF7A")
    IRpcProxyBuffer : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Connect( 
            /* [annotation][unique][in] */ 
            _In_  IRpcChannelBuffer *pRpcChannelBuffer) = 0;
        
        virtual void STDMETHODCALLTYPE Disconnect( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRpcProxyBufferVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRpcProxyBuffer * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRpcProxyBuffer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRpcProxyBuffer * This);
        
        HRESULT ( STDMETHODCALLTYPE *Connect )( 
            IRpcProxyBuffer * This,
            /* [annotation][unique][in] */ 
            _In_  IRpcChannelBuffer *pRpcChannelBuffer);
        
        void ( STDMETHODCALLTYPE *Disconnect )( 
            IRpcProxyBuffer * This);
        
        END_INTERFACE
    } IRpcProxyBufferVtbl;

    interface IRpcProxyBuffer
    {
        CONST_VTBL struct IRpcProxyBufferVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRpcProxyBuffer_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRpcProxyBuffer_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRpcProxyBuffer_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRpcProxyBuffer_Connect(This,pRpcChannelBuffer)	\
    ( (This)->lpVtbl -> Connect(This,pRpcChannelBuffer) ) 

#define IRpcProxyBuffer_Disconnect(This)	\
    ( (This)->lpVtbl -> Disconnect(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRpcProxyBuffer_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_objidlbase_0000_0020 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */
#pragma endregion
#pragma region Application Family or OneCore Family or OneCore Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)


extern RPC_IF_HANDLE __MIDL_itf_objidlbase_0000_0020_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_objidlbase_0000_0020_v0_0_s_ifspec;

#ifndef __IRpcStubBuffer_INTERFACE_DEFINED__
#define __IRpcStubBuffer_INTERFACE_DEFINED__

/* interface IRpcStubBuffer */
/* [uuid][object][local] */ 


EXTERN_C const IID IID_IRpcStubBuffer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D5F56AFC-593B-101A-B569-08002B2DBF7A")
    IRpcStubBuffer : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Connect( 
            /* [annotation][in] */ 
            _In_  IUnknown *pUnkServer) = 0;
        
        virtual void STDMETHODCALLTYPE Disconnect( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Invoke( 
            /* [annotation][out][in] */ 
            _Inout_  RPCOLEMESSAGE *_prpcmsg,
            /* [annotation][in] */ 
            _In_  IRpcChannelBuffer *_pRpcChannelBuffer) = 0;
        
        virtual IRpcStubBuffer *STDMETHODCALLTYPE IsIIDSupported( 
            /* [annotation][in] */ 
            _In_  REFIID riid) = 0;
        
        virtual ULONG STDMETHODCALLTYPE CountRefs( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DebugServerQueryInterface( 
            /* [annotation][out] */ 
            _Outptr_  void **ppv) = 0;
        
        virtual void STDMETHODCALLTYPE DebugServerRelease( 
            /* [annotation][in] */ 
            _In_  void *pv) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRpcStubBufferVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRpcStubBuffer * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRpcStubBuffer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRpcStubBuffer * This);
        
        HRESULT ( STDMETHODCALLTYPE *Connect )( 
            IRpcStubBuffer * This,
            /* [annotation][in] */ 
            _In_  IUnknown *pUnkServer);
        
        void ( STDMETHODCALLTYPE *Disconnect )( 
            IRpcStubBuffer * This);
        
        HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRpcStubBuffer * This,
            /* [annotation][out][in] */ 
            _Inout_  RPCOLEMESSAGE *_prpcmsg,
            /* [annotation][in] */ 
            _In_  IRpcChannelBuffer *_pRpcChannelBuffer);
        
        IRpcStubBuffer *( STDMETHODCALLTYPE *IsIIDSupported )( 
            IRpcStubBuffer * This,
            /* [annotation][in] */ 
            _In_  REFIID riid);
        
        ULONG ( STDMETHODCALLTYPE *CountRefs )( 
            IRpcStubBuffer * This);
        
        HRESULT ( STDMETHODCALLTYPE *DebugServerQueryInterface )( 
            IRpcStubBuffer * This,
            /* [annotation][out] */ 
            _Outptr_  void **ppv);
        
        void ( STDMETHODCALLTYPE *DebugServerRelease )( 
            IRpcStubBuffer * This,
            /* [annotation][in] */ 
            _In_  void *pv);
        
        END_INTERFACE
    } IRpcStubBufferVtbl;

    interface IRpcStubBuffer
    {
        CONST_VTBL struct IRpcStubBufferVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRpcStubBuffer_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRpcStubBuffer_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRpcStubBuffer_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRpcStubBuffer_Connect(This,pUnkServer)	\
    ( (This)->lpVtbl -> Connect(This,pUnkServer) ) 

#define IRpcStubBuffer_Disconnect(This)	\
    ( (This)->lpVtbl -> Disconnect(This) ) 

#define IRpcStubBuffer_Invoke(This,_prpcmsg,_pRpcChannelBuffer)	\
    ( (This)->lpVtbl -> Invoke(This,_prpcmsg,_pRpcChannelBuffer) ) 

#define IRpcStubBuffer_IsIIDSupported(This,riid)	\
    ( (This)->lpVtbl -> IsIIDSupported(This,riid) ) 

#define IRpcStubBuffer_CountRefs(This)	\
    ( (This)->lpVtbl -> CountRefs(This) ) 

#define IRpcStubBuffer_DebugServerQueryInterface(This,ppv)	\
    ( (This)->lpVtbl -> DebugServerQueryInterface(This,ppv) ) 

#define IRpcStubBuffer_DebugServerRelease(This,pv)	\
    ( (This)->lpVtbl -> DebugServerRelease(This,pv) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRpcStubBuffer_INTERFACE_DEFINED__ */


#ifndef __IPSFactoryBuffer_INTERFACE_DEFINED__
#define __IPSFactoryBuffer_INTERFACE_DEFINED__

/* interface IPSFactoryBuffer */
/* [uuid][object][local] */ 


EXTERN_C const IID IID_IPSFactoryBuffer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D5F569D0-593B-101A-B569-08002B2DBF7A")
    IPSFactoryBuffer : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CreateProxy( 
            /* [annotation][in] */ 
            _In_  IUnknown *pUnkOuter,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][out] */ 
            _Outptr_  IRpcProxyBuffer **ppProxy,
            /* [annotation][out] */ 
            _Outptr_  void **ppv) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateStub( 
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][unique][in] */ 
            _In_opt_  IUnknown *pUnkServer,
            /* [annotation][out] */ 
            _Outptr_  IRpcStubBuffer **ppStub) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IPSFactoryBufferVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPSFactoryBuffer * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPSFactoryBuffer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPSFactoryBuffer * This);
        
        HRESULT ( STDMETHODCALLTYPE *CreateProxy )( 
            IPSFactoryBuffer * This,
            /* [annotation][in] */ 
            _In_  IUnknown *pUnkOuter,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][out] */ 
            _Outptr_  IRpcProxyBuffer **ppProxy,
            /* [annotation][out] */ 
            _Outptr_  void **ppv);
        
        HRESULT ( STDMETHODCALLTYPE *CreateStub )( 
            IPSFactoryBuffer * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][unique][in] */ 
            _In_opt_  IUnknown *pUnkServer,
            /* [annotation][out] */ 
            _Outptr_  IRpcStubBuffer **ppStub);
        
        END_INTERFACE
    } IPSFactoryBufferVtbl;

    interface IPSFactoryBuffer
    {
        CONST_VTBL struct IPSFactoryBufferVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPSFactoryBuffer_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPSFactoryBuffer_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPSFactoryBuffer_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPSFactoryBuffer_CreateProxy(This,pUnkOuter,riid,ppProxy,ppv)	\
    ( (This)->lpVtbl -> CreateProxy(This,pUnkOuter,riid,ppProxy,ppv) ) 

#define IPSFactoryBuffer_CreateStub(This,riid,pUnkServer,ppStub)	\
    ( (This)->lpVtbl -> CreateStub(This,riid,pUnkServer,ppStub) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPSFactoryBuffer_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_objidlbase_0000_0022 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */
#pragma endregion
#pragma region Desktop Family or OneCore Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)
#if  (_WIN32_WINNT >= 0x0400 ) || defined(_WIN32_DCOM) // DCOM
// This interface is only valid on Windows NT 4.0
typedef struct SChannelHookCallInfo
    {
    IID iid;
    DWORD cbSize;
    GUID uCausality;
    DWORD dwServerPid;
    DWORD iMethod;
    void *pObject;
    } 	SChannelHookCallInfo;



extern RPC_IF_HANDLE __MIDL_itf_objidlbase_0000_0022_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_objidlbase_0000_0022_v0_0_s_ifspec;

#ifndef __IChannelHook_INTERFACE_DEFINED__
#define __IChannelHook_INTERFACE_DEFINED__

/* interface IChannelHook */
/* [uuid][object][local] */ 


EXTERN_C const IID IID_IChannelHook;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1008c4a0-7613-11cf-9af1-0020af6e72f4")
    IChannelHook : public IUnknown
    {
    public:
        virtual void STDMETHODCALLTYPE ClientGetSize( 
            /* [annotation][in] */ 
            _In_  REFGUID uExtent,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][out] */ 
            _Out_  ULONG *pDataSize) = 0;
        
        virtual void STDMETHODCALLTYPE ClientFillBuffer( 
            /* [annotation][in] */ 
            _In_  REFGUID uExtent,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][out][in] */ 
            _Inout_  ULONG *pDataSize,
            /* [annotation][in] */ 
            _In_  void *pDataBuffer) = 0;
        
        virtual void STDMETHODCALLTYPE ClientNotify( 
            /* [annotation][in] */ 
            _In_  REFGUID uExtent,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  ULONG cbDataSize,
            /* [annotation][in] */ 
            _In_  void *pDataBuffer,
            /* [annotation][in] */ 
            _In_  DWORD lDataRep,
            /* [annotation][in] */ 
            _In_  HRESULT hrFault) = 0;
        
        virtual void STDMETHODCALLTYPE ServerNotify( 
            /* [annotation][in] */ 
            _In_  REFGUID uExtent,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  ULONG cbDataSize,
            /* [annotation][in] */ 
            _In_  void *pDataBuffer,
            /* [annotation][in] */ 
            _In_  DWORD lDataRep) = 0;
        
        virtual void STDMETHODCALLTYPE ServerGetSize( 
            /* [annotation][in] */ 
            _In_  REFGUID uExtent,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  HRESULT hrFault,
            /* [annotation][out] */ 
            _Out_  ULONG *pDataSize) = 0;
        
        virtual void STDMETHODCALLTYPE ServerFillBuffer( 
            /* [annotation][in] */ 
            _In_  REFGUID uExtent,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][out][in] */ 
            _Inout_  ULONG *pDataSize,
            /* [annotation][in] */ 
            _In_  void *pDataBuffer,
            /* [annotation][in] */ 
            _In_  HRESULT hrFault) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IChannelHookVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IChannelHook * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IChannelHook * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IChannelHook * This);
        
        void ( STDMETHODCALLTYPE *ClientGetSize )( 
            IChannelHook * This,
            /* [annotation][in] */ 
            _In_  REFGUID uExtent,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][out] */ 
            _Out_  ULONG *pDataSize);
        
        void ( STDMETHODCALLTYPE *ClientFillBuffer )( 
            IChannelHook * This,
            /* [annotation][in] */ 
            _In_  REFGUID uExtent,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][out][in] */ 
            _Inout_  ULONG *pDataSize,
            /* [annotation][in] */ 
            _In_  void *pDataBuffer);
        
        void ( STDMETHODCALLTYPE *ClientNotify )( 
            IChannelHook * This,
            /* [annotation][in] */ 
            _In_  REFGUID uExtent,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  ULONG cbDataSize,
            /* [annotation][in] */ 
            _In_  void *pDataBuffer,
            /* [annotation][in] */ 
            _In_  DWORD lDataRep,
            /* [annotation][in] */ 
            _In_  HRESULT hrFault);
        
        void ( STDMETHODCALLTYPE *ServerNotify )( 
            IChannelHook * This,
            /* [annotation][in] */ 
            _In_  REFGUID uExtent,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  ULONG cbDataSize,
            /* [annotation][in] */ 
            _In_  void *pDataBuffer,
            /* [annotation][in] */ 
            _In_  DWORD lDataRep);
        
        void ( STDMETHODCALLTYPE *ServerGetSize )( 
            IChannelHook * This,
            /* [annotation][in] */ 
            _In_  REFGUID uExtent,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  HRESULT hrFault,
            /* [annotation][out] */ 
            _Out_  ULONG *pDataSize);
        
        void ( STDMETHODCALLTYPE *ServerFillBuffer )( 
            IChannelHook * This,
            /* [annotation][in] */ 
            _In_  REFGUID uExtent,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][out][in] */ 
            _Inout_  ULONG *pDataSize,
            /* [annotation][in] */ 
            _In_  void *pDataBuffer,
            /* [annotation][in] */ 
            _In_  HRESULT hrFault);
        
        END_INTERFACE
    } IChannelHookVtbl;

    interface IChannelHook
    {
        CONST_VTBL struct IChannelHookVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IChannelHook_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IChannelHook_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IChannelHook_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IChannelHook_ClientGetSize(This,uExtent,riid,pDataSize)	\
    ( (This)->lpVtbl -> ClientGetSize(This,uExtent,riid,pDataSize) ) 

#define IChannelHook_ClientFillBuffer(This,uExtent,riid,pDataSize,pDataBuffer)	\
    ( (This)->lpVtbl -> ClientFillBuffer(This,uExtent,riid,pDataSize,pDataBuffer) ) 

#define IChannelHook_ClientNotify(This,uExtent,riid,cbDataSize,pDataBuffer,lDataRep,hrFault)	\
    ( (This)->lpVtbl -> ClientNotify(This,uExtent,riid,cbDataSize,pDataBuffer,lDataRep,hrFault) ) 

#define IChannelHook_ServerNotify(This,uExtent,riid,cbDataSize,pDataBuffer,lDataRep)	\
    ( (This)->lpVtbl -> ServerNotify(This,uExtent,riid,cbDataSize,pDataBuffer,lDataRep) ) 

#define IChannelHook_ServerGetSize(This,uExtent,riid,hrFault,pDataSize)	\
    ( (This)->lpVtbl -> ServerGetSize(This,uExtent,riid,hrFault,pDataSize) ) 

#define IChannelHook_ServerFillBuffer(This,uExtent,riid,pDataSize,pDataBuffer,hrFault)	\
    ( (This)->lpVtbl -> ServerFillBuffer(This,uExtent,riid,pDataSize,pDataBuffer,hrFault) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IChannelHook_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_objidlbase_0000_0023 */
/* [local] */ 

#endif //DCOM
#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */
#pragma endregion
#if  (_WIN32_WINNT >= 0x0400 ) || defined(_WIN32_DCOM) // DCOM
// This interface is only valid on Windows NT 4.0
#pragma region Application Family or OneCore Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)


extern RPC_IF_HANDLE __MIDL_itf_objidlbase_0000_0023_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_objidlbase_0000_0023_v0_0_s_ifspec;

#ifndef __IClientSecurity_INTERFACE_DEFINED__
#define __IClientSecurity_INTERFACE_DEFINED__

/* interface IClientSecurity */
/* [uuid][object][local] */ 

typedef struct tagSOLE_AUTHENTICATION_SERVICE
    {
    DWORD dwAuthnSvc;
    DWORD dwAuthzSvc;
    OLECHAR *pPrincipalName;
    HRESULT hr;
    } 	SOLE_AUTHENTICATION_SERVICE;

typedef SOLE_AUTHENTICATION_SERVICE *PSOLE_AUTHENTICATION_SERVICE;

typedef 
enum tagEOLE_AUTHENTICATION_CAPABILITIES
    {
        EOAC_NONE	= 0,
        EOAC_MUTUAL_AUTH	= 0x1,
        EOAC_STATIC_CLOAKING	= 0x20,
        EOAC_DYNAMIC_CLOAKING	= 0x40,
        EOAC_ANY_AUTHORITY	= 0x80,
        EOAC_MAKE_FULLSIC	= 0x100,
        EOAC_DEFAULT	= 0x800,
        EOAC_SECURE_REFS	= 0x2,
        EOAC_ACCESS_CONTROL	= 0x4,
        EOAC_APPID	= 0x8,
        EOAC_DYNAMIC	= 0x10,
        EOAC_REQUIRE_FULLSIC	= 0x200,
        EOAC_AUTO_IMPERSONATE	= 0x400,
        EOAC_DISABLE_AAA	= 0x1000,
        EOAC_NO_CUSTOM_MARSHAL	= 0x2000,
        EOAC_RESERVED1	= 0x4000
    } 	EOLE_AUTHENTICATION_CAPABILITIES;

#define	COLE_DEFAULT_PRINCIPAL	( ( OLECHAR * )( INT_PTR  )-1 )

#define	COLE_DEFAULT_AUTHINFO	( ( void * )( INT_PTR  )-1 )

typedef struct tagSOLE_AUTHENTICATION_INFO
    {
    DWORD dwAuthnSvc;
    DWORD dwAuthzSvc;
    void *pAuthInfo;
    } 	SOLE_AUTHENTICATION_INFO;

typedef struct tagSOLE_AUTHENTICATION_INFO *PSOLE_AUTHENTICATION_INFO;

typedef struct tagSOLE_AUTHENTICATION_LIST
    {
    DWORD cAuthInfo;
    SOLE_AUTHENTICATION_INFO *aAuthInfo;
    } 	SOLE_AUTHENTICATION_LIST;

typedef struct tagSOLE_AUTHENTICATION_LIST *PSOLE_AUTHENTICATION_LIST;


EXTERN_C const IID IID_IClientSecurity;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0000013D-0000-0000-C000-000000000046")
    IClientSecurity : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE QueryBlanket( 
            /* [annotation][in] */ 
            _In_  IUnknown *pProxy,
            /* [annotation][out] */ 
            _Out_  DWORD *pAuthnSvc,
            /* [annotation][out] */ 
            _Out_opt_  DWORD *pAuthzSvc,
            /* [annotation][out] */ 
            __RPC__deref_out_opt  OLECHAR **pServerPrincName,
            /* [annotation][out] */ 
            _Out_opt_  DWORD *pAuthnLevel,
            /* [annotation][out] */ 
            _Out_opt_  DWORD *pImpLevel,
            /* [annotation][out] */ 
            _Outptr_result_maybenull_  void **pAuthInfo,
            /* [annotation][out] */ 
            _Out_opt_  DWORD *pCapabilites) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetBlanket( 
            /* [annotation][in] */ 
            _In_  IUnknown *pProxy,
            /* [annotation][in] */ 
            _In_  DWORD dwAuthnSvc,
            /* [annotation][in] */ 
            _In_  DWORD dwAuthzSvc,
            /* [annotation][in] */ 
            __RPC__in_opt  OLECHAR *pServerPrincName,
            /* [annotation][in] */ 
            _In_  DWORD dwAuthnLevel,
            /* [annotation][in] */ 
            _In_  DWORD dwImpLevel,
            /* [annotation][in] */ 
            _In_opt_  void *pAuthInfo,
            /* [annotation][in] */ 
            _In_  DWORD dwCapabilities) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CopyProxy( 
            /* [annotation][in] */ 
            _In_  IUnknown *pProxy,
            /* [annotation][out] */ 
            _Outptr_  IUnknown **ppCopy) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IClientSecurityVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IClientSecurity * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IClientSecurity * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IClientSecurity * This);
        
        HRESULT ( STDMETHODCALLTYPE *QueryBlanket )( 
            IClientSecurity * This,
            /* [annotation][in] */ 
            _In_  IUnknown *pProxy,
            /* [annotation][out] */ 
            _Out_  DWORD *pAuthnSvc,
            /* [annotation][out] */ 
            _Out_opt_  DWORD *pAuthzSvc,
            /* [annotation][out] */ 
            __RPC__deref_out_opt  OLECHAR **pServerPrincName,
            /* [annotation][out] */ 
            _Out_opt_  DWORD *pAuthnLevel,
            /* [annotation][out] */ 
            _Out_opt_  DWORD *pImpLevel,
            /* [annotation][out] */ 
            _Outptr_result_maybenull_  void **pAuthInfo,
            /* [annotation][out] */ 
            _Out_opt_  DWORD *pCapabilites);
        
        HRESULT ( STDMETHODCALLTYPE *SetBlanket )( 
            IClientSecurity * This,
            /* [annotation][in] */ 
            _In_  IUnknown *pProxy,
            /* [annotation][in] */ 
            _In_  DWORD dwAuthnSvc,
            /* [annotation][in] */ 
            _In_  DWORD dwAuthzSvc,
            /* [annotation][in] */ 
            __RPC__in_opt  OLECHAR *pServerPrincName,
            /* [annotation][in] */ 
            _In_  DWORD dwAuthnLevel,
            /* [annotation][in] */ 
            _In_  DWORD dwImpLevel,
            /* [annotation][in] */ 
            _In_opt_  void *pAuthInfo,
            /* [annotation][in] */ 
            _In_  DWORD dwCapabilities);
        
        HRESULT ( STDMETHODCALLTYPE *CopyProxy )( 
            IClientSecurity * This,
            /* [annotation][in] */ 
            _In_  IUnknown *pProxy,
            /* [annotation][out] */ 
            _Outptr_  IUnknown **ppCopy);
        
        END_INTERFACE
    } IClientSecurityVtbl;

    interface IClientSecurity
    {
        CONST_VTBL struct IClientSecurityVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IClientSecurity_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IClientSecurity_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IClientSecurity_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IClientSecurity_QueryBlanket(This,pProxy,pAuthnSvc,pAuthzSvc,pServerPrincName,pAuthnLevel,pImpLevel,pAuthInfo,pCapabilites)	\
    ( (This)->lpVtbl -> QueryBlanket(This,pProxy,pAuthnSvc,pAuthzSvc,pServerPrincName,pAuthnLevel,pImpLevel,pAuthInfo,pCapabilites) ) 

#define IClientSecurity_SetBlanket(This,pProxy,dwAuthnSvc,dwAuthzSvc,pServerPrincName,dwAuthnLevel,dwImpLevel,pAuthInfo,dwCapabilities)	\
    ( (This)->lpVtbl -> SetBlanket(This,pProxy,dwAuthnSvc,dwAuthzSvc,pServerPrincName,dwAuthnLevel,dwImpLevel,pAuthInfo,dwCapabilities) ) 

#define IClientSecurity_CopyProxy(This,pProxy,ppCopy)	\
    ( (This)->lpVtbl -> CopyProxy(This,pProxy,ppCopy) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IClientSecurity_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_objidlbase_0000_0024 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */
#pragma endregion
#pragma region Desktop Family or OneCore Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)


extern RPC_IF_HANDLE __MIDL_itf_objidlbase_0000_0024_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_objidlbase_0000_0024_v0_0_s_ifspec;

#ifndef __IServerSecurity_INTERFACE_DEFINED__
#define __IServerSecurity_INTERFACE_DEFINED__

/* interface IServerSecurity */
/* [uuid][object][local] */ 


EXTERN_C const IID IID_IServerSecurity;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0000013E-0000-0000-C000-000000000046")
    IServerSecurity : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE QueryBlanket( 
            /* [annotation][out] */ 
            _Out_opt_  DWORD *pAuthnSvc,
            /* [annotation][out] */ 
            _Out_opt_  DWORD *pAuthzSvc,
            /* [annotation][out] */ 
            __RPC__deref_out_opt  OLECHAR **pServerPrincName,
            /* [annotation][out] */ 
            _Out_opt_  DWORD *pAuthnLevel,
            /* [annotation][out] */ 
            _Out_opt_  DWORD *pImpLevel,
            /* [annotation][out] */ 
            _Outptr_result_maybenull_  void **pPrivs,
            /* [annotation][out][in] */ 
            _Inout_opt_  DWORD *pCapabilities) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ImpersonateClient( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RevertToSelf( void) = 0;
        
        virtual BOOL STDMETHODCALLTYPE IsImpersonating( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IServerSecurityVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IServerSecurity * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IServerSecurity * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IServerSecurity * This);
        
        HRESULT ( STDMETHODCALLTYPE *QueryBlanket )( 
            IServerSecurity * This,
            /* [annotation][out] */ 
            _Out_opt_  DWORD *pAuthnSvc,
            /* [annotation][out] */ 
            _Out_opt_  DWORD *pAuthzSvc,
            /* [annotation][out] */ 
            __RPC__deref_out_opt  OLECHAR **pServerPrincName,
            /* [annotation][out] */ 
            _Out_opt_  DWORD *pAuthnLevel,
            /* [annotation][out] */ 
            _Out_opt_  DWORD *pImpLevel,
            /* [annotation][out] */ 
            _Outptr_result_maybenull_  void **pPrivs,
            /* [annotation][out][in] */ 
            _Inout_opt_  DWORD *pCapabilities);
        
        HRESULT ( STDMETHODCALLTYPE *ImpersonateClient )( 
            IServerSecurity * This);
        
        HRESULT ( STDMETHODCALLTYPE *RevertToSelf )( 
            IServerSecurity * This);
        
        BOOL ( STDMETHODCALLTYPE *IsImpersonating )( 
            IServerSecurity * This);
        
        END_INTERFACE
    } IServerSecurityVtbl;

    interface IServerSecurity
    {
        CONST_VTBL struct IServerSecurityVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IServerSecurity_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IServerSecurity_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IServerSecurity_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IServerSecurity_QueryBlanket(This,pAuthnSvc,pAuthzSvc,pServerPrincName,pAuthnLevel,pImpLevel,pPrivs,pCapabilities)	\
    ( (This)->lpVtbl -> QueryBlanket(This,pAuthnSvc,pAuthzSvc,pServerPrincName,pAuthnLevel,pImpLevel,pPrivs,pCapabilities) ) 

#define IServerSecurity_ImpersonateClient(This)	\
    ( (This)->lpVtbl -> ImpersonateClient(This) ) 

#define IServerSecurity_RevertToSelf(This)	\
    ( (This)->lpVtbl -> RevertToSelf(This) ) 

#define IServerSecurity_IsImpersonating(This)	\
    ( (This)->lpVtbl -> IsImpersonating(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IServerSecurity_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_objidlbase_0000_0025 */
/* [local] */ 

typedef 
enum tagRPCOPT_PROPERTIES
    {
        COMBND_RPCTIMEOUT	= 0x1,
        COMBND_SERVER_LOCALITY	= 0x2,
        COMBND_RESERVED1	= 0x4,
        COMBND_RESERVED2	= 0x5,
        COMBND_RESERVED3	= 0x8,
        COMBND_RESERVED4	= 0x10
    } 	RPCOPT_PROPERTIES;

typedef 
enum tagRPCOPT_SERVER_LOCALITY_VALUES
    {
        SERVER_LOCALITY_PROCESS_LOCAL	= 0,
        SERVER_LOCALITY_MACHINE_LOCAL	= 1,
        SERVER_LOCALITY_REMOTE	= 2
    } 	RPCOPT_SERVER_LOCALITY_VALUES;



extern RPC_IF_HANDLE __MIDL_itf_objidlbase_0000_0025_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_objidlbase_0000_0025_v0_0_s_ifspec;

#ifndef __IRpcOptions_INTERFACE_DEFINED__
#define __IRpcOptions_INTERFACE_DEFINED__

/* interface IRpcOptions */
/* [uuid][local][object] */ 


EXTERN_C const IID IID_IRpcOptions;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("00000144-0000-0000-C000-000000000046")
    IRpcOptions : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Set( 
            /* [annotation][in] */ 
            _In_  IUnknown *pPrx,
            /* [annotation][in] */ 
            _In_  RPCOPT_PROPERTIES dwProperty,
            /* [annotation][in] */ 
            _In_  ULONG_PTR dwValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Query( 
            /* [annotation][in] */ 
            _In_  IUnknown *pPrx,
            /* [annotation][in] */ 
            _In_  RPCOPT_PROPERTIES dwProperty,
            /* [annotation][out] */ 
            _Out_  ULONG_PTR *pdwValue) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRpcOptionsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRpcOptions * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRpcOptions * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRpcOptions * This);
        
        HRESULT ( STDMETHODCALLTYPE *Set )( 
            IRpcOptions * This,
            /* [annotation][in] */ 
            _In_  IUnknown *pPrx,
            /* [annotation][in] */ 
            _In_  RPCOPT_PROPERTIES dwProperty,
            /* [annotation][in] */ 
            _In_  ULONG_PTR dwValue);
        
        HRESULT ( STDMETHODCALLTYPE *Query )( 
            IRpcOptions * This,
            /* [annotation][in] */ 
            _In_  IUnknown *pPrx,
            /* [annotation][in] */ 
            _In_  RPCOPT_PROPERTIES dwProperty,
            /* [annotation][out] */ 
            _Out_  ULONG_PTR *pdwValue);
        
        END_INTERFACE
    } IRpcOptionsVtbl;

    interface IRpcOptions
    {
        CONST_VTBL struct IRpcOptionsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRpcOptions_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRpcOptions_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRpcOptions_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRpcOptions_Set(This,pPrx,dwProperty,dwValue)	\
    ( (This)->lpVtbl -> Set(This,pPrx,dwProperty,dwValue) ) 

#define IRpcOptions_Query(This,pPrx,dwProperty,pdwValue)	\
    ( (This)->lpVtbl -> Query(This,pPrx,dwProperty,pdwValue) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRpcOptions_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_objidlbase_0000_0026 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */
#pragma endregion
#pragma region Application Family or OneCore Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)
typedef 
enum tagGLOBALOPT_PROPERTIES
    {
        COMGLB_EXCEPTION_HANDLING	= 1,
        COMGLB_APPID	= 2,
        COMGLB_RPC_THREADPOOL_SETTING	= 3,
        COMGLB_RO_SETTINGS	= 4,
        COMGLB_UNMARSHALING_POLICY	= 5,
        COMGLB_PROPERTIES_RESERVED1	= 6,
        COMGLB_PROPERTIES_RESERVED2	= 7,
        COMGLB_PROPERTIES_RESERVED3	= 8
    } 	GLOBALOPT_PROPERTIES;

typedef 
enum tagGLOBALOPT_EH_VALUES
    {
        COMGLB_EXCEPTION_HANDLE	= 0,
        COMGLB_EXCEPTION_DONOT_HANDLE_FATAL	= 1,
        COMGLB_EXCEPTION_DONOT_HANDLE	= COMGLB_EXCEPTION_DONOT_HANDLE_FATAL,
        COMGLB_EXCEPTION_DONOT_HANDLE_ANY	= 2
    } 	GLOBALOPT_EH_VALUES;

typedef 
enum tagGLOBALOPT_RPCTP_VALUES
    {
        COMGLB_RPC_THREADPOOL_SETTING_DEFAULT_POOL	= 0,
        COMGLB_RPC_THREADPOOL_SETTING_PRIVATE_POOL	= 1
    } 	GLOBALOPT_RPCTP_VALUES;

typedef 
enum tagGLOBALOPT_RO_FLAGS
    {
        COMGLB_STA_MODALLOOP_REMOVE_TOUCH_MESSAGES	= 0x1,
        COMGLB_STA_MODALLOOP_SHARED_QUEUE_REMOVE_INPUT_MESSAGES	= 0x2,
        COMGLB_STA_MODALLOOP_SHARED_QUEUE_DONOT_REMOVE_INPUT_MESSAGES	= 0x4,
        COMGLB_FAST_RUNDOWN	= 0x8,
        COMGLB_RESERVED1	= 0x10,
        COMGLB_RESERVED2	= 0x20,
        COMGLB_RESERVED3	= 0x40,
        COMGLB_STA_MODALLOOP_SHARED_QUEUE_REORDER_POINTER_MESSAGES	= 0x80,
        COMGLB_RESERVED4	= 0x100,
        COMGLB_RESERVED5	= 0x200,
        COMGLB_RESERVED6	= 0x400
    } 	GLOBALOPT_RO_FLAGS;

typedef 
enum tagGLOBALOPT_UNMARSHALING_POLICY_VALUES
    {
        COMGLB_UNMARSHALING_POLICY_NORMAL	= 0,
        COMGLB_UNMARSHALING_POLICY_STRONG	= 1,
        COMGLB_UNMARSHALING_POLICY_HYBRID	= 2
    } 	GLOBALOPT_UNMARSHALING_POLICY_VALUES;



extern RPC_IF_HANDLE __MIDL_itf_objidlbase_0000_0026_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_objidlbase_0000_0026_v0_0_s_ifspec;

#ifndef __IGlobalOptions_INTERFACE_DEFINED__
#define __IGlobalOptions_INTERFACE_DEFINED__

/* interface IGlobalOptions */
/* [uuid][unique][local][object] */ 


EXTERN_C const IID IID_IGlobalOptions;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0000015B-0000-0000-C000-000000000046")
    IGlobalOptions : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Set( 
            /* [annotation][in] */ 
            _In_  GLOBALOPT_PROPERTIES dwProperty,
            /* [annotation][in] */ 
            _In_  ULONG_PTR dwValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Query( 
            /* [annotation][in] */ 
            _In_  GLOBALOPT_PROPERTIES dwProperty,
            /* [annotation][out] */ 
            _Out_  ULONG_PTR *pdwValue) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IGlobalOptionsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IGlobalOptions * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IGlobalOptions * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IGlobalOptions * This);
        
        HRESULT ( STDMETHODCALLTYPE *Set )( 
            IGlobalOptions * This,
            /* [annotation][in] */ 
            _In_  GLOBALOPT_PROPERTIES dwProperty,
            /* [annotation][in] */ 
            _In_  ULONG_PTR dwValue);
        
        HRESULT ( STDMETHODCALLTYPE *Query )( 
            IGlobalOptions * This,
            /* [annotation][in] */ 
            _In_  GLOBALOPT_PROPERTIES dwProperty,
            /* [annotation][out] */ 
            _Out_  ULONG_PTR *pdwValue);
        
        END_INTERFACE
    } IGlobalOptionsVtbl;

    interface IGlobalOptions
    {
        CONST_VTBL struct IGlobalOptionsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGlobalOptions_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IGlobalOptions_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IGlobalOptions_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IGlobalOptions_Set(This,dwProperty,dwValue)	\
    ( (This)->lpVtbl -> Set(This,dwProperty,dwValue) ) 

#define IGlobalOptions_Query(This,dwProperty,pdwValue)	\
    ( (This)->lpVtbl -> Query(This,dwProperty,pdwValue) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGlobalOptions_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_objidlbase_0000_0027 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */
#pragma endregion
#endif //DCOM
#pragma region Application Family or OneCore Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)


extern RPC_IF_HANDLE __MIDL_itf_objidlbase_0000_0027_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_objidlbase_0000_0027_v0_0_s_ifspec;

#ifndef __ISurrogate_INTERFACE_DEFINED__
#define __ISurrogate_INTERFACE_DEFINED__

/* interface ISurrogate */
/* [object][unique][version][uuid] */ 

typedef /* [unique] */  __RPC_unique_pointer ISurrogate *LPSURROGATE;


EXTERN_C const IID IID_ISurrogate;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("00000022-0000-0000-C000-000000000046")
    ISurrogate : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE LoadDllServer( 
            /* [annotation][in] */ 
            _In_  REFCLSID Clsid) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FreeSurrogate( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISurrogateVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISurrogate * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISurrogate * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISurrogate * This);
        
        HRESULT ( STDMETHODCALLTYPE *LoadDllServer )( 
            __RPC__in ISurrogate * This,
            /* [annotation][in] */ 
            _In_  REFCLSID Clsid);
        
        HRESULT ( STDMETHODCALLTYPE *FreeSurrogate )( 
            __RPC__in ISurrogate * This);
        
        END_INTERFACE
    } ISurrogateVtbl;

    interface ISurrogate
    {
        CONST_VTBL struct ISurrogateVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISurrogate_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISurrogate_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISurrogate_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISurrogate_LoadDllServer(This,Clsid)	\
    ( (This)->lpVtbl -> LoadDllServer(This,Clsid) ) 

#define ISurrogate_FreeSurrogate(This)	\
    ( (This)->lpVtbl -> FreeSurrogate(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISurrogate_INTERFACE_DEFINED__ */


#ifndef __IGlobalInterfaceTable_INTERFACE_DEFINED__
#define __IGlobalInterfaceTable_INTERFACE_DEFINED__

/* interface IGlobalInterfaceTable */
/* [uuid][object][local] */ 

typedef /* [unique] */ IGlobalInterfaceTable *LPGLOBALINTERFACETABLE;


EXTERN_C const IID IID_IGlobalInterfaceTable;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("00000146-0000-0000-C000-000000000046")
    IGlobalInterfaceTable : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE RegisterInterfaceInGlobal( 
            /* [annotation][in] */ 
            _In_  IUnknown *pUnk,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwCookie) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RevokeInterfaceFromGlobal( 
            /* [annotation][in] */ 
            _In_  DWORD dwCookie) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetInterfaceFromGlobal( 
            /* [annotation][in] */ 
            _In_  DWORD dwCookie,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _Outptr_  void **ppv) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IGlobalInterfaceTableVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IGlobalInterfaceTable * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IGlobalInterfaceTable * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IGlobalInterfaceTable * This);
        
        HRESULT ( STDMETHODCALLTYPE *RegisterInterfaceInGlobal )( 
            IGlobalInterfaceTable * This,
            /* [annotation][in] */ 
            _In_  IUnknown *pUnk,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwCookie);
        
        HRESULT ( STDMETHODCALLTYPE *RevokeInterfaceFromGlobal )( 
            IGlobalInterfaceTable * This,
            /* [annotation][in] */ 
            _In_  DWORD dwCookie);
        
        HRESULT ( STDMETHODCALLTYPE *GetInterfaceFromGlobal )( 
            IGlobalInterfaceTable * This,
            /* [annotation][in] */ 
            _In_  DWORD dwCookie,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _Outptr_  void **ppv);
        
        END_INTERFACE
    } IGlobalInterfaceTableVtbl;

    interface IGlobalInterfaceTable
    {
        CONST_VTBL struct IGlobalInterfaceTableVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGlobalInterfaceTable_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IGlobalInterfaceTable_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IGlobalInterfaceTable_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IGlobalInterfaceTable_RegisterInterfaceInGlobal(This,pUnk,riid,pdwCookie)	\
    ( (This)->lpVtbl -> RegisterInterfaceInGlobal(This,pUnk,riid,pdwCookie) ) 

#define IGlobalInterfaceTable_RevokeInterfaceFromGlobal(This,dwCookie)	\
    ( (This)->lpVtbl -> RevokeInterfaceFromGlobal(This,dwCookie) ) 

#define IGlobalInterfaceTable_GetInterfaceFromGlobal(This,dwCookie,riid,ppv)	\
    ( (This)->lpVtbl -> GetInterfaceFromGlobal(This,dwCookie,riid,ppv) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGlobalInterfaceTable_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_objidlbase_0000_0029 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */
#pragma endregion
#pragma region Desktop Family or OneCore Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)


extern RPC_IF_HANDLE __MIDL_itf_objidlbase_0000_0029_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_objidlbase_0000_0029_v0_0_s_ifspec;

#ifndef __ISynchronize_INTERFACE_DEFINED__
#define __ISynchronize_INTERFACE_DEFINED__

/* interface ISynchronize */
/* [uuid][object] */ 


EXTERN_C const IID IID_ISynchronize;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("00000030-0000-0000-C000-000000000046")
    ISynchronize : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Wait( 
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][in] */ 
            _In_  DWORD dwMilliseconds) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Signal( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISynchronizeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISynchronize * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISynchronize * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISynchronize * This);
        
        HRESULT ( STDMETHODCALLTYPE *Wait )( 
            __RPC__in ISynchronize * This,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][in] */ 
            _In_  DWORD dwMilliseconds);
        
        HRESULT ( STDMETHODCALLTYPE *Signal )( 
            __RPC__in ISynchronize * This);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            __RPC__in ISynchronize * This);
        
        END_INTERFACE
    } ISynchronizeVtbl;

    interface ISynchronize
    {
        CONST_VTBL struct ISynchronizeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISynchronize_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISynchronize_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISynchronize_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISynchronize_Wait(This,dwFlags,dwMilliseconds)	\
    ( (This)->lpVtbl -> Wait(This,dwFlags,dwMilliseconds) ) 

#define ISynchronize_Signal(This)	\
    ( (This)->lpVtbl -> Signal(This) ) 

#define ISynchronize_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISynchronize_INTERFACE_DEFINED__ */


#ifndef __ISynchronizeHandle_INTERFACE_DEFINED__
#define __ISynchronizeHandle_INTERFACE_DEFINED__

/* interface ISynchronizeHandle */
/* [uuid][object][local] */ 


EXTERN_C const IID IID_ISynchronizeHandle;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("00000031-0000-0000-C000-000000000046")
    ISynchronizeHandle : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetHandle( 
            /* [annotation][out] */ 
            _Out_  HANDLE *ph) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISynchronizeHandleVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISynchronizeHandle * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISynchronizeHandle * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISynchronizeHandle * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetHandle )( 
            ISynchronizeHandle * This,
            /* [annotation][out] */ 
            _Out_  HANDLE *ph);
        
        END_INTERFACE
    } ISynchronizeHandleVtbl;

    interface ISynchronizeHandle
    {
        CONST_VTBL struct ISynchronizeHandleVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISynchronizeHandle_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISynchronizeHandle_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISynchronizeHandle_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISynchronizeHandle_GetHandle(This,ph)	\
    ( (This)->lpVtbl -> GetHandle(This,ph) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISynchronizeHandle_INTERFACE_DEFINED__ */


#ifndef __ISynchronizeEvent_INTERFACE_DEFINED__
#define __ISynchronizeEvent_INTERFACE_DEFINED__

/* interface ISynchronizeEvent */
/* [uuid][object][local] */ 


EXTERN_C const IID IID_ISynchronizeEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("00000032-0000-0000-C000-000000000046")
    ISynchronizeEvent : public ISynchronizeHandle
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetEventHandle( 
            /* [annotation][in] */ 
            _In_  HANDLE *ph) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISynchronizeEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISynchronizeEvent * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISynchronizeEvent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISynchronizeEvent * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetHandle )( 
            ISynchronizeEvent * This,
            /* [annotation][out] */ 
            _Out_  HANDLE *ph);
        
        HRESULT ( STDMETHODCALLTYPE *SetEventHandle )( 
            ISynchronizeEvent * This,
            /* [annotation][in] */ 
            _In_  HANDLE *ph);
        
        END_INTERFACE
    } ISynchronizeEventVtbl;

    interface ISynchronizeEvent
    {
        CONST_VTBL struct ISynchronizeEventVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISynchronizeEvent_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISynchronizeEvent_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISynchronizeEvent_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISynchronizeEvent_GetHandle(This,ph)	\
    ( (This)->lpVtbl -> GetHandle(This,ph) ) 


#define ISynchronizeEvent_SetEventHandle(This,ph)	\
    ( (This)->lpVtbl -> SetEventHandle(This,ph) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISynchronizeEvent_INTERFACE_DEFINED__ */


#ifndef __ISynchronizeContainer_INTERFACE_DEFINED__
#define __ISynchronizeContainer_INTERFACE_DEFINED__

/* interface ISynchronizeContainer */
/* [uuid][object][local] */ 


EXTERN_C const IID IID_ISynchronizeContainer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("00000033-0000-0000-C000-000000000046")
    ISynchronizeContainer : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AddSynchronize( 
            /* [annotation][in] */ 
            _In_  ISynchronize *pSync) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE WaitMultiple( 
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][in] */ 
            _In_  DWORD dwTimeOut,
            /* [annotation][out] */ 
            _Outptr_  ISynchronize **ppSync) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISynchronizeContainerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISynchronizeContainer * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISynchronizeContainer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISynchronizeContainer * This);
        
        HRESULT ( STDMETHODCALLTYPE *AddSynchronize )( 
            ISynchronizeContainer * This,
            /* [annotation][in] */ 
            _In_  ISynchronize *pSync);
        
        HRESULT ( STDMETHODCALLTYPE *WaitMultiple )( 
            ISynchronizeContainer * This,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][in] */ 
            _In_  DWORD dwTimeOut,
            /* [annotation][out] */ 
            _Outptr_  ISynchronize **ppSync);
        
        END_INTERFACE
    } ISynchronizeContainerVtbl;

    interface ISynchronizeContainer
    {
        CONST_VTBL struct ISynchronizeContainerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISynchronizeContainer_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISynchronizeContainer_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISynchronizeContainer_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISynchronizeContainer_AddSynchronize(This,pSync)	\
    ( (This)->lpVtbl -> AddSynchronize(This,pSync) ) 

#define ISynchronizeContainer_WaitMultiple(This,dwFlags,dwTimeOut,ppSync)	\
    ( (This)->lpVtbl -> WaitMultiple(This,dwFlags,dwTimeOut,ppSync) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISynchronizeContainer_INTERFACE_DEFINED__ */


#ifndef __ISynchronizeMutex_INTERFACE_DEFINED__
#define __ISynchronizeMutex_INTERFACE_DEFINED__

/* interface ISynchronizeMutex */
/* [uuid][object][local] */ 


EXTERN_C const IID IID_ISynchronizeMutex;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("00000025-0000-0000-C000-000000000046")
    ISynchronizeMutex : public ISynchronize
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ReleaseMutex( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISynchronizeMutexVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISynchronizeMutex * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISynchronizeMutex * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISynchronizeMutex * This);
        
        HRESULT ( STDMETHODCALLTYPE *Wait )( 
            ISynchronizeMutex * This,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][in] */ 
            _In_  DWORD dwMilliseconds);
        
        HRESULT ( STDMETHODCALLTYPE *Signal )( 
            ISynchronizeMutex * This);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            ISynchronizeMutex * This);
        
        HRESULT ( STDMETHODCALLTYPE *ReleaseMutex )( 
            ISynchronizeMutex * This);
        
        END_INTERFACE
    } ISynchronizeMutexVtbl;

    interface ISynchronizeMutex
    {
        CONST_VTBL struct ISynchronizeMutexVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISynchronizeMutex_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISynchronizeMutex_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISynchronizeMutex_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISynchronizeMutex_Wait(This,dwFlags,dwMilliseconds)	\
    ( (This)->lpVtbl -> Wait(This,dwFlags,dwMilliseconds) ) 

#define ISynchronizeMutex_Signal(This)	\
    ( (This)->lpVtbl -> Signal(This) ) 

#define ISynchronizeMutex_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 


#define ISynchronizeMutex_ReleaseMutex(This)	\
    ( (This)->lpVtbl -> ReleaseMutex(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISynchronizeMutex_INTERFACE_DEFINED__ */


#ifndef __ICancelMethodCalls_INTERFACE_DEFINED__
#define __ICancelMethodCalls_INTERFACE_DEFINED__

/* interface ICancelMethodCalls */
/* [uuid][object][local] */ 

typedef /* [unique] */ ICancelMethodCalls *LPCANCELMETHODCALLS;


EXTERN_C const IID IID_ICancelMethodCalls;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("00000029-0000-0000-C000-000000000046")
    ICancelMethodCalls : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Cancel( 
            /* [annotation][in] */ 
            _In_  ULONG ulSeconds) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE TestCancel( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICancelMethodCallsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICancelMethodCalls * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICancelMethodCalls * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICancelMethodCalls * This);
        
        HRESULT ( STDMETHODCALLTYPE *Cancel )( 
            ICancelMethodCalls * This,
            /* [annotation][in] */ 
            _In_  ULONG ulSeconds);
        
        HRESULT ( STDMETHODCALLTYPE *TestCancel )( 
            ICancelMethodCalls * This);
        
        END_INTERFACE
    } ICancelMethodCallsVtbl;

    interface ICancelMethodCalls
    {
        CONST_VTBL struct ICancelMethodCallsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICancelMethodCalls_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICancelMethodCalls_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICancelMethodCalls_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICancelMethodCalls_Cancel(This,ulSeconds)	\
    ( (This)->lpVtbl -> Cancel(This,ulSeconds) ) 

#define ICancelMethodCalls_TestCancel(This)	\
    ( (This)->lpVtbl -> TestCancel(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICancelMethodCalls_INTERFACE_DEFINED__ */


#ifndef __IAsyncManager_INTERFACE_DEFINED__
#define __IAsyncManager_INTERFACE_DEFINED__

/* interface IAsyncManager */
/* [uuid][object][local] */ 

typedef 
enum tagDCOM_CALL_STATE
    {
        DCOM_NONE	= 0,
        DCOM_CALL_COMPLETE	= 0x1,
        DCOM_CALL_CANCELED	= 0x2
    } 	DCOM_CALL_STATE;


EXTERN_C const IID IID_IAsyncManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0000002A-0000-0000-C000-000000000046")
    IAsyncManager : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CompleteCall( 
            /* [annotation][in] */ 
            _In_  HRESULT Result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCallContext( 
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][out] */ 
            _Outptr_  void **pInterface) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetState( 
            /* [annotation][out] */ 
            _Out_  ULONG *pulStateFlags) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAsyncManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAsyncManager * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAsyncManager * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAsyncManager * This);
        
        HRESULT ( STDMETHODCALLTYPE *CompleteCall )( 
            IAsyncManager * This,
            /* [annotation][in] */ 
            _In_  HRESULT Result);
        
        HRESULT ( STDMETHODCALLTYPE *GetCallContext )( 
            IAsyncManager * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][out] */ 
            _Outptr_  void **pInterface);
        
        HRESULT ( STDMETHODCALLTYPE *GetState )( 
            IAsyncManager * This,
            /* [annotation][out] */ 
            _Out_  ULONG *pulStateFlags);
        
        END_INTERFACE
    } IAsyncManagerVtbl;

    interface IAsyncManager
    {
        CONST_VTBL struct IAsyncManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAsyncManager_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAsyncManager_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAsyncManager_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAsyncManager_CompleteCall(This,Result)	\
    ( (This)->lpVtbl -> CompleteCall(This,Result) ) 

#define IAsyncManager_GetCallContext(This,riid,pInterface)	\
    ( (This)->lpVtbl -> GetCallContext(This,riid,pInterface) ) 

#define IAsyncManager_GetState(This,pulStateFlags)	\
    ( (This)->lpVtbl -> GetState(This,pulStateFlags) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAsyncManager_INTERFACE_DEFINED__ */


#ifndef __ICallFactory_INTERFACE_DEFINED__
#define __ICallFactory_INTERFACE_DEFINED__

/* interface ICallFactory */
/* [unique][uuid][object][local] */ 


EXTERN_C const IID IID_ICallFactory;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1c733a30-2a1c-11ce-ade5-00aa0044773d")
    ICallFactory : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CreateCall( 
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_opt_  IUnknown *pCtrlUnk,
            /* [annotation][in] */ 
            _In_  REFIID riid2,
            /* [annotation][iid_is][out] */ 
            _Outptr_  IUnknown **ppv) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICallFactoryVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICallFactory * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICallFactory * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICallFactory * This);
        
        HRESULT ( STDMETHODCALLTYPE *CreateCall )( 
            ICallFactory * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_opt_  IUnknown *pCtrlUnk,
            /* [annotation][in] */ 
            _In_  REFIID riid2,
            /* [annotation][iid_is][out] */ 
            _Outptr_  IUnknown **ppv);
        
        END_INTERFACE
    } ICallFactoryVtbl;

    interface ICallFactory
    {
        CONST_VTBL struct ICallFactoryVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICallFactory_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICallFactory_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICallFactory_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICallFactory_CreateCall(This,riid,pCtrlUnk,riid2,ppv)	\
    ( (This)->lpVtbl -> CreateCall(This,riid,pCtrlUnk,riid2,ppv) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICallFactory_INTERFACE_DEFINED__ */


#ifndef __IRpcHelper_INTERFACE_DEFINED__
#define __IRpcHelper_INTERFACE_DEFINED__

/* interface IRpcHelper */
/* [object][local][unique][version][uuid] */ 


EXTERN_C const IID IID_IRpcHelper;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("00000149-0000-0000-C000-000000000046")
    IRpcHelper : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetDCOMProtocolVersion( 
            /* [annotation][out] */ 
            _Out_  DWORD *pComVersion) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetIIDFromOBJREF( 
            /* [annotation][in] */ 
            _In_  void *pObjRef,
            /* [annotation][out] */ 
            _Outptr_  IID **piid) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRpcHelperVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRpcHelper * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRpcHelper * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRpcHelper * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetDCOMProtocolVersion )( 
            IRpcHelper * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pComVersion);
        
        HRESULT ( STDMETHODCALLTYPE *GetIIDFromOBJREF )( 
            IRpcHelper * This,
            /* [annotation][in] */ 
            _In_  void *pObjRef,
            /* [annotation][out] */ 
            _Outptr_  IID **piid);
        
        END_INTERFACE
    } IRpcHelperVtbl;

    interface IRpcHelper
    {
        CONST_VTBL struct IRpcHelperVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRpcHelper_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRpcHelper_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRpcHelper_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRpcHelper_GetDCOMProtocolVersion(This,pComVersion)	\
    ( (This)->lpVtbl -> GetDCOMProtocolVersion(This,pComVersion) ) 

#define IRpcHelper_GetIIDFromOBJREF(This,pObjRef,piid)	\
    ( (This)->lpVtbl -> GetIIDFromOBJREF(This,pObjRef,piid) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRpcHelper_INTERFACE_DEFINED__ */


#ifndef __IReleaseMarshalBuffers_INTERFACE_DEFINED__
#define __IReleaseMarshalBuffers_INTERFACE_DEFINED__

/* interface IReleaseMarshalBuffers */
/* [uuid][object][local] */ 


EXTERN_C const IID IID_IReleaseMarshalBuffers;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("eb0cb9e8-7996-11d2-872e-0000f8080859")
    IReleaseMarshalBuffers : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ReleaseMarshalBuffer( 
            /* [annotation][out][in] */ 
            _Inout_  RPCOLEMESSAGE *pMsg,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][unique][in] */ 
            _In_opt_  IUnknown *pChnl) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IReleaseMarshalBuffersVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IReleaseMarshalBuffers * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IReleaseMarshalBuffers * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IReleaseMarshalBuffers * This);
        
        HRESULT ( STDMETHODCALLTYPE *ReleaseMarshalBuffer )( 
            IReleaseMarshalBuffers * This,
            /* [annotation][out][in] */ 
            _Inout_  RPCOLEMESSAGE *pMsg,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][unique][in] */ 
            _In_opt_  IUnknown *pChnl);
        
        END_INTERFACE
    } IReleaseMarshalBuffersVtbl;

    interface IReleaseMarshalBuffers
    {
        CONST_VTBL struct IReleaseMarshalBuffersVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IReleaseMarshalBuffers_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IReleaseMarshalBuffers_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IReleaseMarshalBuffers_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IReleaseMarshalBuffers_ReleaseMarshalBuffer(This,pMsg,dwFlags,pChnl)	\
    ( (This)->lpVtbl -> ReleaseMarshalBuffer(This,pMsg,dwFlags,pChnl) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IReleaseMarshalBuffers_INTERFACE_DEFINED__ */


#ifndef __IWaitMultiple_INTERFACE_DEFINED__
#define __IWaitMultiple_INTERFACE_DEFINED__

/* interface IWaitMultiple */
/* [uuid][object][local] */ 


EXTERN_C const IID IID_IWaitMultiple;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0000002B-0000-0000-C000-000000000046")
    IWaitMultiple : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE WaitMultiple( 
            /* [annotation][in] */ 
            _In_  DWORD timeout,
            /* [annotation][out] */ 
            _Outptr_  ISynchronize **pSync) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddSynchronize( 
            /* [annotation][in] */ 
            _In_  ISynchronize *pSync) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWaitMultipleVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWaitMultiple * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWaitMultiple * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWaitMultiple * This);
        
        HRESULT ( STDMETHODCALLTYPE *WaitMultiple )( 
            IWaitMultiple * This,
            /* [annotation][in] */ 
            _In_  DWORD timeout,
            /* [annotation][out] */ 
            _Outptr_  ISynchronize **pSync);
        
        HRESULT ( STDMETHODCALLTYPE *AddSynchronize )( 
            IWaitMultiple * This,
            /* [annotation][in] */ 
            _In_  ISynchronize *pSync);
        
        END_INTERFACE
    } IWaitMultipleVtbl;

    interface IWaitMultiple
    {
        CONST_VTBL struct IWaitMultipleVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWaitMultiple_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWaitMultiple_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWaitMultiple_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWaitMultiple_WaitMultiple(This,timeout,pSync)	\
    ( (This)->lpVtbl -> WaitMultiple(This,timeout,pSync) ) 

#define IWaitMultiple_AddSynchronize(This,pSync)	\
    ( (This)->lpVtbl -> AddSynchronize(This,pSync) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWaitMultiple_INTERFACE_DEFINED__ */


#ifndef __IAddrTrackingControl_INTERFACE_DEFINED__
#define __IAddrTrackingControl_INTERFACE_DEFINED__

/* interface IAddrTrackingControl */
/* [uuid][object][local] */ 

typedef /* [unique] */ IAddrTrackingControl *LPADDRTRACKINGCONTROL;


EXTERN_C const IID IID_IAddrTrackingControl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("00000147-0000-0000-C000-000000000046")
    IAddrTrackingControl : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE EnableCOMDynamicAddrTracking( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DisableCOMDynamicAddrTracking( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAddrTrackingControlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAddrTrackingControl * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAddrTrackingControl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAddrTrackingControl * This);
        
        HRESULT ( STDMETHODCALLTYPE *EnableCOMDynamicAddrTracking )( 
            IAddrTrackingControl * This);
        
        HRESULT ( STDMETHODCALLTYPE *DisableCOMDynamicAddrTracking )( 
            IAddrTrackingControl * This);
        
        END_INTERFACE
    } IAddrTrackingControlVtbl;

    interface IAddrTrackingControl
    {
        CONST_VTBL struct IAddrTrackingControlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAddrTrackingControl_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAddrTrackingControl_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAddrTrackingControl_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAddrTrackingControl_EnableCOMDynamicAddrTracking(This)	\
    ( (This)->lpVtbl -> EnableCOMDynamicAddrTracking(This) ) 

#define IAddrTrackingControl_DisableCOMDynamicAddrTracking(This)	\
    ( (This)->lpVtbl -> DisableCOMDynamicAddrTracking(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAddrTrackingControl_INTERFACE_DEFINED__ */


#ifndef __IAddrExclusionControl_INTERFACE_DEFINED__
#define __IAddrExclusionControl_INTERFACE_DEFINED__

/* interface IAddrExclusionControl */
/* [uuid][object][local] */ 

typedef /* [unique] */ IAddrExclusionControl *LPADDREXCLUSIONCONTROL;


EXTERN_C const IID IID_IAddrExclusionControl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("00000148-0000-0000-C000-000000000046")
    IAddrExclusionControl : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetCurrentAddrExclusionList( 
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _Outptr_  void **ppEnumerator) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UpdateAddrExclusionList( 
            /* [annotation][in] */ 
            _In_  IUnknown *pEnumerator) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAddrExclusionControlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAddrExclusionControl * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAddrExclusionControl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAddrExclusionControl * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetCurrentAddrExclusionList )( 
            IAddrExclusionControl * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _Outptr_  void **ppEnumerator);
        
        HRESULT ( STDMETHODCALLTYPE *UpdateAddrExclusionList )( 
            IAddrExclusionControl * This,
            /* [annotation][in] */ 
            _In_  IUnknown *pEnumerator);
        
        END_INTERFACE
    } IAddrExclusionControlVtbl;

    interface IAddrExclusionControl
    {
        CONST_VTBL struct IAddrExclusionControlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAddrExclusionControl_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAddrExclusionControl_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAddrExclusionControl_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAddrExclusionControl_GetCurrentAddrExclusionList(This,riid,ppEnumerator)	\
    ( (This)->lpVtbl -> GetCurrentAddrExclusionList(This,riid,ppEnumerator) ) 

#define IAddrExclusionControl_UpdateAddrExclusionList(This,pEnumerator)	\
    ( (This)->lpVtbl -> UpdateAddrExclusionList(This,pEnumerator) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAddrExclusionControl_INTERFACE_DEFINED__ */


#ifndef __IPipeByte_INTERFACE_DEFINED__
#define __IPipeByte_INTERFACE_DEFINED__

/* interface IPipeByte */
/* [unique][async_uuid][uuid][object] */ 


EXTERN_C const IID IID_IPipeByte;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DB2F3ACA-2F86-11d1-8E04-00C04FB9989A")
    IPipeByte : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Pull( 
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(cRequest,*pcReturned)  BYTE *buf,
            /* [annotation][in] */ 
            _In_  ULONG cRequest,
            /* [annotation][out] */ 
            _Out_  ULONG *pcReturned) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Push( 
            /* [annotation][size_is][in] */ 
            _In_reads_(cSent)  BYTE *buf,
            /* [annotation][in] */ 
            _In_  ULONG cSent) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IPipeByteVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IPipeByte * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IPipeByte * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IPipeByte * This);
        
        HRESULT ( STDMETHODCALLTYPE *Pull )( 
            __RPC__in IPipeByte * This,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(cRequest,*pcReturned)  BYTE *buf,
            /* [annotation][in] */ 
            _In_  ULONG cRequest,
            /* [annotation][out] */ 
            _Out_  ULONG *pcReturned);
        
        HRESULT ( STDMETHODCALLTYPE *Push )( 
            __RPC__in IPipeByte * This,
            /* [annotation][size_is][in] */ 
            _In_reads_(cSent)  BYTE *buf,
            /* [annotation][in] */ 
            _In_  ULONG cSent);
        
        END_INTERFACE
    } IPipeByteVtbl;

    interface IPipeByte
    {
        CONST_VTBL struct IPipeByteVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPipeByte_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPipeByte_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPipeByte_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPipeByte_Pull(This,buf,cRequest,pcReturned)	\
    ( (This)->lpVtbl -> Pull(This,buf,cRequest,pcReturned) ) 

#define IPipeByte_Push(This,buf,cSent)	\
    ( (This)->lpVtbl -> Push(This,buf,cSent) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPipeByte_INTERFACE_DEFINED__ */


#ifndef __AsyncIPipeByte_INTERFACE_DEFINED__
#define __AsyncIPipeByte_INTERFACE_DEFINED__

/* interface AsyncIPipeByte */
/* [uuid][unique][object] */ 


EXTERN_C const IID IID_AsyncIPipeByte;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DB2F3ACB-2F86-11d1-8E04-00C04FB9989A")
    AsyncIPipeByte : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Begin_Pull( 
            /* [annotation][in] */ 
            _In_  ULONG cRequest) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_Pull( 
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(cRequest,*pcReturned)  BYTE *buf,
            /* [annotation][out] */ 
            _Out_  ULONG *pcReturned) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_Push( 
            /* [annotation][size_is][in] */ 
            _In_reads_(cSent)  BYTE *buf,
            /* [annotation][in] */ 
            _In_  ULONG cSent) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_Push( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct AsyncIPipeByteVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in AsyncIPipeByte * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in AsyncIPipeByte * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in AsyncIPipeByte * This);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_Pull )( 
            __RPC__in AsyncIPipeByte * This,
            /* [annotation][in] */ 
            _In_  ULONG cRequest);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_Pull )( 
            __RPC__in AsyncIPipeByte * This,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(cRequest,*pcReturned)  BYTE *buf,
            /* [annotation][out] */ 
            _Out_  ULONG *pcReturned);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_Push )( 
            __RPC__in AsyncIPipeByte * This,
            /* [annotation][size_is][in] */ 
            _In_reads_(cSent)  BYTE *buf,
            /* [annotation][in] */ 
            _In_  ULONG cSent);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_Push )( 
            __RPC__in AsyncIPipeByte * This);
        
        END_INTERFACE
    } AsyncIPipeByteVtbl;

    interface AsyncIPipeByte
    {
        CONST_VTBL struct AsyncIPipeByteVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define AsyncIPipeByte_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define AsyncIPipeByte_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define AsyncIPipeByte_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define AsyncIPipeByte_Begin_Pull(This,cRequest)	\
    ( (This)->lpVtbl -> Begin_Pull(This,cRequest) ) 

#define AsyncIPipeByte_Finish_Pull(This,buf,pcReturned)	\
    ( (This)->lpVtbl -> Finish_Pull(This,buf,pcReturned) ) 

#define AsyncIPipeByte_Begin_Push(This,buf,cSent)	\
    ( (This)->lpVtbl -> Begin_Push(This,buf,cSent) ) 

#define AsyncIPipeByte_Finish_Push(This)	\
    ( (This)->lpVtbl -> Finish_Push(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __AsyncIPipeByte_INTERFACE_DEFINED__ */


#ifndef __IPipeLong_INTERFACE_DEFINED__
#define __IPipeLong_INTERFACE_DEFINED__

/* interface IPipeLong */
/* [unique][async_uuid][uuid][object] */ 


EXTERN_C const IID IID_IPipeLong;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DB2F3ACC-2F86-11d1-8E04-00C04FB9989A")
    IPipeLong : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Pull( 
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(cRequest,*pcReturned)  LONG *buf,
            /* [annotation][in] */ 
            _In_  ULONG cRequest,
            /* [annotation][out] */ 
            _Out_  ULONG *pcReturned) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Push( 
            /* [annotation][size_is][in] */ 
            _In_reads_(cSent)  LONG *buf,
            /* [annotation][in] */ 
            _In_  ULONG cSent) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IPipeLongVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IPipeLong * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IPipeLong * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IPipeLong * This);
        
        HRESULT ( STDMETHODCALLTYPE *Pull )( 
            __RPC__in IPipeLong * This,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(cRequest,*pcReturned)  LONG *buf,
            /* [annotation][in] */ 
            _In_  ULONG cRequest,
            /* [annotation][out] */ 
            _Out_  ULONG *pcReturned);
        
        HRESULT ( STDMETHODCALLTYPE *Push )( 
            __RPC__in IPipeLong * This,
            /* [annotation][size_is][in] */ 
            _In_reads_(cSent)  LONG *buf,
            /* [annotation][in] */ 
            _In_  ULONG cSent);
        
        END_INTERFACE
    } IPipeLongVtbl;

    interface IPipeLong
    {
        CONST_VTBL struct IPipeLongVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPipeLong_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPipeLong_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPipeLong_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPipeLong_Pull(This,buf,cRequest,pcReturned)	\
    ( (This)->lpVtbl -> Pull(This,buf,cRequest,pcReturned) ) 

#define IPipeLong_Push(This,buf,cSent)	\
    ( (This)->lpVtbl -> Push(This,buf,cSent) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPipeLong_INTERFACE_DEFINED__ */


#ifndef __AsyncIPipeLong_INTERFACE_DEFINED__
#define __AsyncIPipeLong_INTERFACE_DEFINED__

/* interface AsyncIPipeLong */
/* [uuid][unique][object] */ 


EXTERN_C const IID IID_AsyncIPipeLong;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DB2F3ACD-2F86-11d1-8E04-00C04FB9989A")
    AsyncIPipeLong : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Begin_Pull( 
            /* [annotation][in] */ 
            _In_  ULONG cRequest) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_Pull( 
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(cRequest,*pcReturned)  LONG *buf,
            /* [annotation][out] */ 
            _Out_  ULONG *pcReturned) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_Push( 
            /* [annotation][size_is][in] */ 
            _In_reads_(cSent)  LONG *buf,
            /* [annotation][in] */ 
            _In_  ULONG cSent) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_Push( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct AsyncIPipeLongVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in AsyncIPipeLong * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in AsyncIPipeLong * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in AsyncIPipeLong * This);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_Pull )( 
            __RPC__in AsyncIPipeLong * This,
            /* [annotation][in] */ 
            _In_  ULONG cRequest);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_Pull )( 
            __RPC__in AsyncIPipeLong * This,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(cRequest,*pcReturned)  LONG *buf,
            /* [annotation][out] */ 
            _Out_  ULONG *pcReturned);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_Push )( 
            __RPC__in AsyncIPipeLong * This,
            /* [annotation][size_is][in] */ 
            _In_reads_(cSent)  LONG *buf,
            /* [annotation][in] */ 
            _In_  ULONG cSent);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_Push )( 
            __RPC__in AsyncIPipeLong * This);
        
        END_INTERFACE
    } AsyncIPipeLongVtbl;

    interface AsyncIPipeLong
    {
        CONST_VTBL struct AsyncIPipeLongVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define AsyncIPipeLong_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define AsyncIPipeLong_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define AsyncIPipeLong_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define AsyncIPipeLong_Begin_Pull(This,cRequest)	\
    ( (This)->lpVtbl -> Begin_Pull(This,cRequest) ) 

#define AsyncIPipeLong_Finish_Pull(This,buf,pcReturned)	\
    ( (This)->lpVtbl -> Finish_Pull(This,buf,pcReturned) ) 

#define AsyncIPipeLong_Begin_Push(This,buf,cSent)	\
    ( (This)->lpVtbl -> Begin_Push(This,buf,cSent) ) 

#define AsyncIPipeLong_Finish_Push(This)	\
    ( (This)->lpVtbl -> Finish_Push(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __AsyncIPipeLong_INTERFACE_DEFINED__ */


#ifndef __IPipeDouble_INTERFACE_DEFINED__
#define __IPipeDouble_INTERFACE_DEFINED__

/* interface IPipeDouble */
/* [unique][async_uuid][uuid][object] */ 


EXTERN_C const IID IID_IPipeDouble;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DB2F3ACE-2F86-11d1-8E04-00C04FB9989A")
    IPipeDouble : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Pull( 
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(cRequest,*pcReturned)  DOUBLE *buf,
            /* [annotation][in] */ 
            _In_  ULONG cRequest,
            /* [annotation][out] */ 
            _Out_  ULONG *pcReturned) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Push( 
            /* [annotation][size_is][in] */ 
            _In_reads_(cSent)  DOUBLE *buf,
            /* [annotation][in] */ 
            _In_  ULONG cSent) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IPipeDoubleVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IPipeDouble * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IPipeDouble * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IPipeDouble * This);
        
        HRESULT ( STDMETHODCALLTYPE *Pull )( 
            __RPC__in IPipeDouble * This,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(cRequest,*pcReturned)  DOUBLE *buf,
            /* [annotation][in] */ 
            _In_  ULONG cRequest,
            /* [annotation][out] */ 
            _Out_  ULONG *pcReturned);
        
        HRESULT ( STDMETHODCALLTYPE *Push )( 
            __RPC__in IPipeDouble * This,
            /* [annotation][size_is][in] */ 
            _In_reads_(cSent)  DOUBLE *buf,
            /* [annotation][in] */ 
            _In_  ULONG cSent);
        
        END_INTERFACE
    } IPipeDoubleVtbl;

    interface IPipeDouble
    {
        CONST_VTBL struct IPipeDoubleVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPipeDouble_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPipeDouble_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPipeDouble_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPipeDouble_Pull(This,buf,cRequest,pcReturned)	\
    ( (This)->lpVtbl -> Pull(This,buf,cRequest,pcReturned) ) 

#define IPipeDouble_Push(This,buf,cSent)	\
    ( (This)->lpVtbl -> Push(This,buf,cSent) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPipeDouble_INTERFACE_DEFINED__ */


#ifndef __AsyncIPipeDouble_INTERFACE_DEFINED__
#define __AsyncIPipeDouble_INTERFACE_DEFINED__

/* interface AsyncIPipeDouble */
/* [uuid][unique][object] */ 


EXTERN_C const IID IID_AsyncIPipeDouble;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DB2F3ACF-2F86-11d1-8E04-00C04FB9989A")
    AsyncIPipeDouble : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Begin_Pull( 
            /* [annotation][in] */ 
            _In_  ULONG cRequest) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_Pull( 
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(cRequest,*pcReturned)  DOUBLE *buf,
            /* [annotation][out] */ 
            _Out_  ULONG *pcReturned) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_Push( 
            /* [annotation][size_is][in] */ 
            _In_reads_(cSent)  DOUBLE *buf,
            /* [annotation][in] */ 
            _In_  ULONG cSent) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_Push( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct AsyncIPipeDoubleVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in AsyncIPipeDouble * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in AsyncIPipeDouble * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in AsyncIPipeDouble * This);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_Pull )( 
            __RPC__in AsyncIPipeDouble * This,
            /* [annotation][in] */ 
            _In_  ULONG cRequest);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_Pull )( 
            __RPC__in AsyncIPipeDouble * This,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(cRequest,*pcReturned)  DOUBLE *buf,
            /* [annotation][out] */ 
            _Out_  ULONG *pcReturned);
        
        HRESULT ( STDMETHODCALLTYPE *Begin_Push )( 
            __RPC__in AsyncIPipeDouble * This,
            /* [annotation][size_is][in] */ 
            _In_reads_(cSent)  DOUBLE *buf,
            /* [annotation][in] */ 
            _In_  ULONG cSent);
        
        HRESULT ( STDMETHODCALLTYPE *Finish_Push )( 
            __RPC__in AsyncIPipeDouble * This);
        
        END_INTERFACE
    } AsyncIPipeDoubleVtbl;

    interface AsyncIPipeDouble
    {
        CONST_VTBL struct AsyncIPipeDoubleVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define AsyncIPipeDouble_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define AsyncIPipeDouble_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define AsyncIPipeDouble_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define AsyncIPipeDouble_Begin_Pull(This,cRequest)	\
    ( (This)->lpVtbl -> Begin_Pull(This,cRequest) ) 

#define AsyncIPipeDouble_Finish_Pull(This,buf,pcReturned)	\
    ( (This)->lpVtbl -> Finish_Pull(This,buf,pcReturned) ) 

#define AsyncIPipeDouble_Begin_Push(This,buf,cSent)	\
    ( (This)->lpVtbl -> Begin_Push(This,buf,cSent) ) 

#define AsyncIPipeDouble_Finish_Push(This)	\
    ( (This)->lpVtbl -> Finish_Push(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __AsyncIPipeDouble_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_objidlbase_0000_0045 */
/* [local] */ 

#if defined USE_COM_CONTEXT_DEF || defined BUILDTYPE_COMSVCS || defined _COMBASEAPI_ || defined _OLE32_
typedef DWORD CPFLAGS;

typedef struct tagContextProperty
    {
    GUID policyId;
    CPFLAGS flags;
    /* [unique] */ IUnknown *pUnk;
    } 	ContextProperty;



extern RPC_IF_HANDLE __MIDL_itf_objidlbase_0000_0045_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_objidlbase_0000_0045_v0_0_s_ifspec;

#ifndef __IEnumContextProps_INTERFACE_DEFINED__
#define __IEnumContextProps_INTERFACE_DEFINED__

/* interface IEnumContextProps */
/* [unique][uuid][object][local] */ 

typedef /* [unique] */ IEnumContextProps *LPENUMCONTEXTPROPS;


EXTERN_C const IID IID_IEnumContextProps;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("000001c1-0000-0000-C000-000000000046")
    IEnumContextProps : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [annotation][in] */ 
            _In_  ULONG celt,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(celt, *pceltFetched)  ContextProperty *pContextProperties,
            /* [annotation][out] */ 
            _Out_  ULONG *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [annotation][in] */ 
            _In_  ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [annotation][out] */ 
            _Outptr_  IEnumContextProps **ppEnumContextProps) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Count( 
            /* [annotation][out] */ 
            _Out_  ULONG *pcelt) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IEnumContextPropsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEnumContextProps * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEnumContextProps * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEnumContextProps * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            IEnumContextProps * This,
            /* [annotation][in] */ 
            _In_  ULONG celt,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(celt, *pceltFetched)  ContextProperty *pContextProperties,
            /* [annotation][out] */ 
            _Out_  ULONG *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            IEnumContextProps * This,
            /* [annotation][in] */ 
            _In_  ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IEnumContextProps * This);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IEnumContextProps * This,
            /* [annotation][out] */ 
            _Outptr_  IEnumContextProps **ppEnumContextProps);
        
        HRESULT ( STDMETHODCALLTYPE *Count )( 
            IEnumContextProps * This,
            /* [annotation][out] */ 
            _Out_  ULONG *pcelt);
        
        END_INTERFACE
    } IEnumContextPropsVtbl;

    interface IEnumContextProps
    {
        CONST_VTBL struct IEnumContextPropsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumContextProps_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEnumContextProps_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEnumContextProps_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IEnumContextProps_Next(This,celt,pContextProperties,pceltFetched)	\
    ( (This)->lpVtbl -> Next(This,celt,pContextProperties,pceltFetched) ) 

#define IEnumContextProps_Skip(This,celt)	\
    ( (This)->lpVtbl -> Skip(This,celt) ) 

#define IEnumContextProps_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define IEnumContextProps_Clone(This,ppEnumContextProps)	\
    ( (This)->lpVtbl -> Clone(This,ppEnumContextProps) ) 

#define IEnumContextProps_Count(This,pcelt)	\
    ( (This)->lpVtbl -> Count(This,pcelt) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IEnumContextProps_INTERFACE_DEFINED__ */


#ifndef __IContext_INTERFACE_DEFINED__
#define __IContext_INTERFACE_DEFINED__

/* interface IContext */
/* [unique][uuid][object][local] */ 


EXTERN_C const IID IID_IContext;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("000001c0-0000-0000-C000-000000000046")
    IContext : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetProperty( 
            /* [annotation][in] */ 
            _In_  REFGUID rpolicyId,
            /* [annotation][in] */ 
            _In_  CPFLAGS flags,
            /* [annotation][in] */ 
            _In_  IUnknown *pUnk) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveProperty( 
            /* [annotation][in] */ 
            _In_  REFGUID rPolicyId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetProperty( 
            /* [annotation][in] */ 
            _In_  REFGUID rGuid,
            /* [annotation][out] */ 
            _Out_  CPFLAGS *pFlags,
            /* [annotation][out] */ 
            _Outptr_  IUnknown **ppUnk) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumContextProps( 
            /* [annotation][out] */ 
            _Outptr_  IEnumContextProps **ppEnumContextProps) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IContextVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IContext * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IContext * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IContext * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetProperty )( 
            IContext * This,
            /* [annotation][in] */ 
            _In_  REFGUID rpolicyId,
            /* [annotation][in] */ 
            _In_  CPFLAGS flags,
            /* [annotation][in] */ 
            _In_  IUnknown *pUnk);
        
        HRESULT ( STDMETHODCALLTYPE *RemoveProperty )( 
            IContext * This,
            /* [annotation][in] */ 
            _In_  REFGUID rPolicyId);
        
        HRESULT ( STDMETHODCALLTYPE *GetProperty )( 
            IContext * This,
            /* [annotation][in] */ 
            _In_  REFGUID rGuid,
            /* [annotation][out] */ 
            _Out_  CPFLAGS *pFlags,
            /* [annotation][out] */ 
            _Outptr_  IUnknown **ppUnk);
        
        HRESULT ( STDMETHODCALLTYPE *EnumContextProps )( 
            IContext * This,
            /* [annotation][out] */ 
            _Outptr_  IEnumContextProps **ppEnumContextProps);
        
        END_INTERFACE
    } IContextVtbl;

    interface IContext
    {
        CONST_VTBL struct IContextVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IContext_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IContext_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IContext_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IContext_SetProperty(This,rpolicyId,flags,pUnk)	\
    ( (This)->lpVtbl -> SetProperty(This,rpolicyId,flags,pUnk) ) 

#define IContext_RemoveProperty(This,rPolicyId)	\
    ( (This)->lpVtbl -> RemoveProperty(This,rPolicyId) ) 

#define IContext_GetProperty(This,rGuid,pFlags,ppUnk)	\
    ( (This)->lpVtbl -> GetProperty(This,rGuid,pFlags,ppUnk) ) 

#define IContext_EnumContextProps(This,ppEnumContextProps)	\
    ( (This)->lpVtbl -> EnumContextProps(This,ppEnumContextProps) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IContext_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_objidlbase_0000_0047 */
/* [local] */ 

#endif
#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */
#pragma endregion
#pragma region Application Family or OneCore Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)
typedef 
enum _APTTYPEQUALIFIER
    {
        APTTYPEQUALIFIER_NONE	= 0,
        APTTYPEQUALIFIER_IMPLICIT_MTA	= 1,
        APTTYPEQUALIFIER_NA_ON_MTA	= 2,
        APTTYPEQUALIFIER_NA_ON_STA	= 3,
        APTTYPEQUALIFIER_NA_ON_IMPLICIT_MTA	= 4,
        APTTYPEQUALIFIER_NA_ON_MAINSTA	= 5,
        APTTYPEQUALIFIER_APPLICATION_STA	= 6,
        APTTYPEQUALIFIER_RESERVED_1	= 7
    } 	APTTYPEQUALIFIER;

typedef 
enum _APTTYPE
    {
        APTTYPE_CURRENT	= -1,
        APTTYPE_STA	= 0,
        APTTYPE_MTA	= 1,
        APTTYPE_NA	= 2,
        APTTYPE_MAINSTA	= 3
    } 	APTTYPE;

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */
#pragma endregion
#pragma region Desktop Family or OneCore Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)
typedef 
enum _THDTYPE
    {
        THDTYPE_BLOCKMESSAGES	= 0,
        THDTYPE_PROCESSMESSAGES	= 1
    } 	THDTYPE;

typedef DWORD APARTMENTID;



extern RPC_IF_HANDLE __MIDL_itf_objidlbase_0000_0047_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_objidlbase_0000_0047_v0_0_s_ifspec;

#ifndef __IComThreadingInfo_INTERFACE_DEFINED__
#define __IComThreadingInfo_INTERFACE_DEFINED__

/* interface IComThreadingInfo */
/* [unique][uuid][object][local] */ 


EXTERN_C const IID IID_IComThreadingInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("000001ce-0000-0000-C000-000000000046")
    IComThreadingInfo : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetCurrentApartmentType( 
            /* [annotation][out] */ 
            _Out_  APTTYPE *pAptType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCurrentThreadType( 
            /* [annotation][out] */ 
            _Out_  THDTYPE *pThreadType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCurrentLogicalThreadId( 
            /* [annotation][out] */ 
            _Out_  GUID *pguidLogicalThreadId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetCurrentLogicalThreadId( 
            /* [annotation][in] */ 
            _In_  REFGUID rguid) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IComThreadingInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IComThreadingInfo * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IComThreadingInfo * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IComThreadingInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetCurrentApartmentType )( 
            IComThreadingInfo * This,
            /* [annotation][out] */ 
            _Out_  APTTYPE *pAptType);
        
        HRESULT ( STDMETHODCALLTYPE *GetCurrentThreadType )( 
            IComThreadingInfo * This,
            /* [annotation][out] */ 
            _Out_  THDTYPE *pThreadType);
        
        HRESULT ( STDMETHODCALLTYPE *GetCurrentLogicalThreadId )( 
            IComThreadingInfo * This,
            /* [annotation][out] */ 
            _Out_  GUID *pguidLogicalThreadId);
        
        HRESULT ( STDMETHODCALLTYPE *SetCurrentLogicalThreadId )( 
            IComThreadingInfo * This,
            /* [annotation][in] */ 
            _In_  REFGUID rguid);
        
        END_INTERFACE
    } IComThreadingInfoVtbl;

    interface IComThreadingInfo
    {
        CONST_VTBL struct IComThreadingInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IComThreadingInfo_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IComThreadingInfo_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IComThreadingInfo_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IComThreadingInfo_GetCurrentApartmentType(This,pAptType)	\
    ( (This)->lpVtbl -> GetCurrentApartmentType(This,pAptType) ) 

#define IComThreadingInfo_GetCurrentThreadType(This,pThreadType)	\
    ( (This)->lpVtbl -> GetCurrentThreadType(This,pThreadType) ) 

#define IComThreadingInfo_GetCurrentLogicalThreadId(This,pguidLogicalThreadId)	\
    ( (This)->lpVtbl -> GetCurrentLogicalThreadId(This,pguidLogicalThreadId) ) 

#define IComThreadingInfo_SetCurrentLogicalThreadId(This,rguid)	\
    ( (This)->lpVtbl -> SetCurrentLogicalThreadId(This,rguid) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IComThreadingInfo_INTERFACE_DEFINED__ */


#ifndef __IProcessInitControl_INTERFACE_DEFINED__
#define __IProcessInitControl_INTERFACE_DEFINED__

/* interface IProcessInitControl */
/* [uuid][unique][object] */ 


EXTERN_C const IID IID_IProcessInitControl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("72380d55-8d2b-43a3-8513-2b6ef31434e9")
    IProcessInitControl : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ResetInitializerTimeout( 
            /* [annotation][in] */ 
            _In_  DWORD dwSecondsRemaining) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IProcessInitControlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IProcessInitControl * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IProcessInitControl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IProcessInitControl * This);
        
        HRESULT ( STDMETHODCALLTYPE *ResetInitializerTimeout )( 
            __RPC__in IProcessInitControl * This,
            /* [annotation][in] */ 
            _In_  DWORD dwSecondsRemaining);
        
        END_INTERFACE
    } IProcessInitControlVtbl;

    interface IProcessInitControl
    {
        CONST_VTBL struct IProcessInitControlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IProcessInitControl_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IProcessInitControl_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IProcessInitControl_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IProcessInitControl_ResetInitializerTimeout(This,dwSecondsRemaining)	\
    ( (This)->lpVtbl -> ResetInitializerTimeout(This,dwSecondsRemaining) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IProcessInitControl_INTERFACE_DEFINED__ */


#ifndef __IFastRundown_INTERFACE_DEFINED__
#define __IFastRundown_INTERFACE_DEFINED__

/* interface IFastRundown */
/* [uuid][unique][local][object] */ 


EXTERN_C const IID IID_IFastRundown;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("00000040-0000-0000-C000-000000000046")
    IFastRundown : public IUnknown
    {
    public:
    };
    
    
#else 	/* C style interface */

    typedef struct IFastRundownVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFastRundown * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFastRundown * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFastRundown * This);
        
        END_INTERFACE
    } IFastRundownVtbl;

    interface IFastRundown
    {
        CONST_VTBL struct IFastRundownVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFastRundown_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFastRundown_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFastRundown_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFastRundown_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_objidlbase_0000_0050 */
/* [local] */ 

typedef 
enum CO_MARSHALING_CONTEXT_ATTRIBUTES
    {
        CO_MARSHALING_SOURCE_IS_APP_CONTAINER	= 0,
        CO_MARSHALING_CONTEXT_ATTRIBUTE_RESERVED_1	= 0x80000000,
        CO_MARSHALING_CONTEXT_ATTRIBUTE_RESERVED_2	= 0x80000001,
        CO_MARSHALING_CONTEXT_ATTRIBUTE_RESERVED_3	= 0x80000002,
        CO_MARSHALING_CONTEXT_ATTRIBUTE_RESERVED_4	= 0x80000003,
        CO_MARSHALING_CONTEXT_ATTRIBUTE_RESERVED_5	= 0x80000004,
        CO_MARSHALING_CONTEXT_ATTRIBUTE_RESERVED_6	= 0x80000005,
        CO_MARSHALING_CONTEXT_ATTRIBUTE_RESERVED_7	= 0x80000006,
        CO_MARSHALING_CONTEXT_ATTRIBUTE_RESERVED_8	= 0x80000007,
        CO_MARSHALING_CONTEXT_ATTRIBUTE_RESERVED_9	= 0x80000008,
        CO_MARSHALING_CONTEXT_ATTRIBUTE_RESERVED_10	= 0x80000009,
        CO_MARSHALING_CONTEXT_ATTRIBUTE_RESERVED_11	= 0x8000000a,
        CO_MARSHALING_CONTEXT_ATTRIBUTE_RESERVED_12	= 0x8000000b,
        CO_MARSHALING_CONTEXT_ATTRIBUTE_RESERVED_13	= 0x8000000c,
        CO_MARSHALING_CONTEXT_ATTRIBUTE_RESERVED_14	= 0x8000000d,
        CO_MARSHALING_CONTEXT_ATTRIBUTE_RESERVED_15	= 0x8000000e,
        CO_MARSHALING_CONTEXT_ATTRIBUTE_RESERVED_16	= 0x8000000f,
        CO_MARSHALING_CONTEXT_ATTRIBUTE_RESERVED_17	= 0x80000010,
        CO_MARSHALING_CONTEXT_ATTRIBUTE_RESERVED_18	= 0x80000011
    } 	CO_MARSHALING_CONTEXT_ATTRIBUTES;



extern RPC_IF_HANDLE __MIDL_itf_objidlbase_0000_0050_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_objidlbase_0000_0050_v0_0_s_ifspec;

#ifndef __IMarshalingStream_INTERFACE_DEFINED__
#define __IMarshalingStream_INTERFACE_DEFINED__

/* interface IMarshalingStream */
/* [unique][uuid][object][local] */ 


EXTERN_C const IID IID_IMarshalingStream;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D8F2F5E6-6102-4863-9F26-389A4676EFDE")
    IMarshalingStream : public IStream
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetMarshalingContextAttribute( 
            /* [annotation][in] */ 
            _In_  CO_MARSHALING_CONTEXT_ATTRIBUTES attribute,
            /* [annotation][out] */ 
            _Out_  ULONG_PTR *pAttributeValue) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IMarshalingStreamVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMarshalingStream * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMarshalingStream * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMarshalingStream * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Read )( 
            IMarshalingStream * This,
            /* [annotation] */ 
            _Out_writes_bytes_to_(cb, *pcbRead)  void *pv,
            /* [annotation][in] */ 
            _In_  ULONG cb,
            /* [annotation] */ 
            _Out_opt_  ULONG *pcbRead);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Write )( 
            IMarshalingStream * This,
            /* [annotation] */ 
            _In_reads_bytes_(cb)  const void *pv,
            /* [annotation][in] */ 
            _In_  ULONG cb,
            /* [annotation] */ 
            _Out_opt_  ULONG *pcbWritten);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Seek )( 
            IMarshalingStream * This,
            /* [annotation][in] */ 
            _In_  LARGE_INTEGER dlibMove,
            /* [annotation][in] */ 
            _In_  DWORD dwOrigin,
            /* [annotation] */ 
            _Out_opt_  ULARGE_INTEGER *plibNewPosition);
        
        HRESULT ( STDMETHODCALLTYPE *SetSize )( 
            IMarshalingStream * This,
            /* [annotation][in] */ 
            _In_  ULARGE_INTEGER libNewSize);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *CopyTo )( 
            IMarshalingStream * This,
            /* [annotation][unique][in] */ 
            _In_  IStream *pstm,
            /* [annotation][in] */ 
            _In_  ULARGE_INTEGER cb,
            /* [annotation] */ 
            _Out_opt_  ULARGE_INTEGER *pcbRead,
            /* [annotation] */ 
            _Out_opt_  ULARGE_INTEGER *pcbWritten);
        
        HRESULT ( STDMETHODCALLTYPE *Commit )( 
            IMarshalingStream * This,
            /* [annotation][in] */ 
            _In_  DWORD grfCommitFlags);
        
        HRESULT ( STDMETHODCALLTYPE *Revert )( 
            IMarshalingStream * This);
        
        HRESULT ( STDMETHODCALLTYPE *LockRegion )( 
            IMarshalingStream * This,
            /* [annotation][in] */ 
            _In_  ULARGE_INTEGER libOffset,
            /* [annotation][in] */ 
            _In_  ULARGE_INTEGER cb,
            /* [annotation][in] */ 
            _In_  DWORD dwLockType);
        
        HRESULT ( STDMETHODCALLTYPE *UnlockRegion )( 
            IMarshalingStream * This,
            /* [annotation][in] */ 
            _In_  ULARGE_INTEGER libOffset,
            /* [annotation][in] */ 
            _In_  ULARGE_INTEGER cb,
            /* [annotation][in] */ 
            _In_  DWORD dwLockType);
        
        HRESULT ( STDMETHODCALLTYPE *Stat )( 
            IMarshalingStream * This,
            /* [annotation][out] */ 
            _Out_  STATSTG *pstatstg,
            /* [annotation][in] */ 
            _In_  DWORD grfStatFlag);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IMarshalingStream * This,
            /* [annotation][out] */ 
            _Out_  IStream **ppstm);
        
        HRESULT ( STDMETHODCALLTYPE *GetMarshalingContextAttribute )( 
            IMarshalingStream * This,
            /* [annotation][in] */ 
            _In_  CO_MARSHALING_CONTEXT_ATTRIBUTES attribute,
            /* [annotation][out] */ 
            _Out_  ULONG_PTR *pAttributeValue);
        
        END_INTERFACE
    } IMarshalingStreamVtbl;

    interface IMarshalingStream
    {
        CONST_VTBL struct IMarshalingStreamVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMarshalingStream_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMarshalingStream_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMarshalingStream_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMarshalingStream_Read(This,pv,cb,pcbRead)	\
    ( (This)->lpVtbl -> Read(This,pv,cb,pcbRead) ) 

#define IMarshalingStream_Write(This,pv,cb,pcbWritten)	\
    ( (This)->lpVtbl -> Write(This,pv,cb,pcbWritten) ) 


#define IMarshalingStream_Seek(This,dlibMove,dwOrigin,plibNewPosition)	\
    ( (This)->lpVtbl -> Seek(This,dlibMove,dwOrigin,plibNewPosition) ) 

#define IMarshalingStream_SetSize(This,libNewSize)	\
    ( (This)->lpVtbl -> SetSize(This,libNewSize) ) 

#define IMarshalingStream_CopyTo(This,pstm,cb,pcbRead,pcbWritten)	\
    ( (This)->lpVtbl -> CopyTo(This,pstm,cb,pcbRead,pcbWritten) ) 

#define IMarshalingStream_Commit(This,grfCommitFlags)	\
    ( (This)->lpVtbl -> Commit(This,grfCommitFlags) ) 

#define IMarshalingStream_Revert(This)	\
    ( (This)->lpVtbl -> Revert(This) ) 

#define IMarshalingStream_LockRegion(This,libOffset,cb,dwLockType)	\
    ( (This)->lpVtbl -> LockRegion(This,libOffset,cb,dwLockType) ) 

#define IMarshalingStream_UnlockRegion(This,libOffset,cb,dwLockType)	\
    ( (This)->lpVtbl -> UnlockRegion(This,libOffset,cb,dwLockType) ) 

#define IMarshalingStream_Stat(This,pstatstg,grfStatFlag)	\
    ( (This)->lpVtbl -> Stat(This,pstatstg,grfStatFlag) ) 

#define IMarshalingStream_Clone(This,ppstm)	\
    ( (This)->lpVtbl -> Clone(This,ppstm) ) 


#define IMarshalingStream_GetMarshalingContextAttribute(This,attribute,pAttributeValue)	\
    ( (This)->lpVtbl -> GetMarshalingContextAttribute(This,attribute,pAttributeValue) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMarshalingStream_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_objidlbase_0000_0051 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */
#pragma endregion
#pragma region Application Family or OneCore Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)


extern RPC_IF_HANDLE __MIDL_itf_objidlbase_0000_0051_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_objidlbase_0000_0051_v0_0_s_ifspec;

#ifndef __IAgileReference_INTERFACE_DEFINED__
#define __IAgileReference_INTERFACE_DEFINED__

/* interface IAgileReference */
/* [unique][uuid][object][local] */ 

#if defined(__cplusplus) && !defined(CINTERFACE)
    EXTERN_C const IID IID_IAgileReference;
    extern "C++"
    {
        MIDL_INTERFACE("C03F6A43-65A4-9818-987E-E0B810D2A6F2")
        IAgileReference : public IUnknown
        {
        public:
            virtual HRESULT STDMETHODCALLTYPE Resolve( 
                /* [in] */ REFIID riid,
                /* [iid_is][retval][out] */ void **ppvObjectReference) = 0;

            template<class Q>
            HRESULT
#ifdef _M_CEE_PURE
            __clrcall
#else
            STDMETHODCALLTYPE
#endif
            Resolve(_COM_Outptr_ Q** pp)
            {
                return Resolve(__uuidof(Q), (void **)pp);
            }

        };
    } // extern C++
#else

EXTERN_C const IID IID_IAgileReference;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C03F6A43-65A4-9818-987E-E0B810D2A6F2")
    IAgileReference : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Resolve( 
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][retval][out] */ 
            _COM_Outptr_retval_  void **ppvObjectReference) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAgileReferenceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAgileReference * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAgileReference * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAgileReference * This);
        
        HRESULT ( STDMETHODCALLTYPE *Resolve )( 
            IAgileReference * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][retval][out] */ 
            _COM_Outptr_retval_  void **ppvObjectReference);
        
        END_INTERFACE
    } IAgileReferenceVtbl;

    interface IAgileReference
    {
        CONST_VTBL struct IAgileReferenceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgileReference_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAgileReference_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAgileReference_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAgileReference_Resolve(This,riid,ppvObjectReference)	\
    ( (This)->lpVtbl -> Resolve(This,riid,ppvObjectReference) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAgileReference_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_objidlbase_0000_0052 */
/* [local] */ 

#endif
#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */
#pragma endregion
#pragma region Application Family or OneCore Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)
EXTERN_C const GUID  IID_ICallbackWithNoReentrancyToApplicationSTA;
#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */
#pragma endregion
#define _OBJIDLBASE_
#endif
#if ( _MSC_VER >= 800 )
#if _MSC_VER >= 1200
#pragma warning(pop)
#else
#pragma warning(default:4201)
#endif
#endif


extern RPC_IF_HANDLE __MIDL_itf_objidlbase_0000_0052_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_objidlbase_0000_0052_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* [local] */ HRESULT STDMETHODCALLTYPE IEnumUnknown_Next_Proxy( 
    IEnumUnknown * This,
    /* [annotation][in] */ 
    _In_  ULONG celt,
    /* [annotation][out] */ 
    _Out_writes_to_(celt,*pceltFetched)  IUnknown **rgelt,
    /* [annotation][out] */ 
    _Out_opt_  ULONG *pceltFetched);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IEnumUnknown_Next_Stub( 
    __RPC__in IEnumUnknown * This,
    /* [annotation][in] */ 
    _In_  ULONG celt,
    /* [annotation][length_is][size_is][out] */ 
    _Out_writes_to_(celt,*pceltFetched)  IUnknown **rgelt,
    /* [annotation][out] */ 
    _Out_  ULONG *pceltFetched);

/* [local] */ HRESULT STDMETHODCALLTYPE IEnumString_Next_Proxy( 
    IEnumString * This,
    /* [annotation][in] */ 
    _In_  ULONG celt,
    /* [annotation] */ 
    _Out_writes_to_(celt,*pceltFetched)  LPOLESTR *rgelt,
    /* [annotation] */ 
    _Out_opt_  ULONG *pceltFetched);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IEnumString_Next_Stub( 
    __RPC__in IEnumString * This,
    /* [annotation][in] */ 
    _In_  ULONG celt,
    /* [annotation][length_is][size_is][out] */ 
    _Out_writes_to_(celt,*pceltFetched)  LPOLESTR *rgelt,
    /* [annotation][out] */ 
    _Out_  ULONG *pceltFetched);

/* [local] */ HRESULT STDMETHODCALLTYPE ISequentialStream_Read_Proxy( 
    ISequentialStream * This,
    /* [annotation] */ 
    _Out_writes_bytes_to_(cb, *pcbRead)  void *pv,
    /* [annotation][in] */ 
    _In_  ULONG cb,
    /* [annotation] */ 
    _Out_opt_  ULONG *pcbRead);


/* [call_as] */ HRESULT STDMETHODCALLTYPE ISequentialStream_Read_Stub( 
    __RPC__in ISequentialStream * This,
    /* [annotation][length_is][size_is][out] */ 
    _Out_writes_to_(cb,*pcbRead)  byte *pv,
    /* [annotation][in] */ 
    _In_  ULONG cb,
    /* [annotation][out] */ 
    _Out_  ULONG *pcbRead);

/* [local] */ HRESULT STDMETHODCALLTYPE ISequentialStream_Write_Proxy( 
    ISequentialStream * This,
    /* [annotation] */ 
    _In_reads_bytes_(cb)  const void *pv,
    /* [annotation][in] */ 
    _In_  ULONG cb,
    /* [annotation] */ 
    _Out_opt_  ULONG *pcbWritten);


/* [call_as] */ HRESULT STDMETHODCALLTYPE ISequentialStream_Write_Stub( 
    __RPC__in ISequentialStream * This,
    /* [annotation][size_is][in] */ 
    _In_reads_(cb)  const byte *pv,
    /* [annotation][in] */ 
    _In_  ULONG cb,
    /* [annotation][out] */ 
    _Out_  ULONG *pcbWritten);

/* [local] */ HRESULT STDMETHODCALLTYPE IStream_Seek_Proxy( 
    IStream * This,
    /* [annotation][in] */ 
    _In_  LARGE_INTEGER dlibMove,
    /* [annotation][in] */ 
    _In_  DWORD dwOrigin,
    /* [annotation] */ 
    _Out_opt_  ULARGE_INTEGER *plibNewPosition);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IStream_Seek_Stub( 
    __RPC__in IStream * This,
    /* [annotation][in] */ 
    _In_  LARGE_INTEGER dlibMove,
    /* [annotation][in] */ 
    _In_  DWORD dwOrigin,
    /* [annotation][out] */ 
    _Out_  ULARGE_INTEGER *plibNewPosition);

/* [local] */ HRESULT STDMETHODCALLTYPE IStream_CopyTo_Proxy( 
    IStream * This,
    /* [annotation][unique][in] */ 
    _In_  IStream *pstm,
    /* [annotation][in] */ 
    _In_  ULARGE_INTEGER cb,
    /* [annotation] */ 
    _Out_opt_  ULARGE_INTEGER *pcbRead,
    /* [annotation] */ 
    _Out_opt_  ULARGE_INTEGER *pcbWritten);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IStream_CopyTo_Stub( 
    __RPC__in IStream * This,
    /* [annotation][unique][in] */ 
    _In_  IStream *pstm,
    /* [annotation][in] */ 
    _In_  ULARGE_INTEGER cb,
    /* [annotation][out] */ 
    _Out_  ULARGE_INTEGER *pcbRead,
    /* [annotation][out] */ 
    _Out_  ULARGE_INTEGER *pcbWritten);



/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


