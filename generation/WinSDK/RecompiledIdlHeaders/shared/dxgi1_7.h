

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0628 */
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

#ifndef __dxgi1_7_h__
#define __dxgi1_7_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef DECLSPEC_XFGVIRT
#if defined(_CONTROL_FLOW_GUARD_XFG)
#define DECLSPEC_XFGVIRT(base, func) __declspec(xfg_virtual(base, func))
#else
#define DECLSPEC_XFGVIRT(base, func)
#endif
#endif

/* Forward Declarations */ 

#ifndef __IDXGIAdapter5_FWD_DEFINED__
#define __IDXGIAdapter5_FWD_DEFINED__
typedef interface IDXGIAdapter5 IDXGIAdapter5;

#endif 	/* __IDXGIAdapter5_FWD_DEFINED__ */


#ifndef __IDXGISwapChain5_FWD_DEFINED__
#define __IDXGISwapChain5_FWD_DEFINED__
typedef interface IDXGISwapChain5 IDXGISwapChain5;

#endif 	/* __IDXGISwapChain5_FWD_DEFINED__ */


#ifndef __IDXGIFactory8_FWD_DEFINED__
#define __IDXGIFactory8_FWD_DEFINED__
typedef interface IDXGIFactory8 IDXGIFactory8;

#endif 	/* __IDXGIFactory8_FWD_DEFINED__ */


#ifndef __IDXGIFactoryMedia2_FWD_DEFINED__
#define __IDXGIFactoryMedia2_FWD_DEFINED__
typedef interface IDXGIFactoryMedia2 IDXGIFactoryMedia2;

#endif 	/* __IDXGIFactoryMedia2_FWD_DEFINED__ */


/* header files for imported files */
#include "dxgi1_6.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_dxgi1_7_0000_0000 */
/* [local] */ 

// Copyright (c) Microsoft Corporation.  All Rights Reserved
#include <winapifamily.h>
#pragma region App Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_GAMES)
typedef 
enum DXGI_SINGLE_ADAPTER_HYBRID_MODE
    {
        DXGI_SINGLE_ADAPTER_HYBRID_MODE_UNSPECIFIED	= 0,
        DXGI_SINGLE_ADAPTER_HYBRID_MODE_MINIMUM_POWER	= 1,
        DXGI_SINGLE_ADAPTER_HYBRID_MODE_HIGH_PERFORMANCE	= 2,
        DXGI_SINGLE_ADAPTER_HYBRID_MODE_FORCE_DWORD	= 0xffffffff
    } 	DXGI_SINGLE_ADAPTER_HYBRID_MODE;

typedef 
enum DXGI_ADAPTER_FLAG4
    {
        DXGI_ADAPTER_FLAG4_NONE	= 0,
        DXGI_ADAPTER_FLAG4_REMOTE	= 1,
        DXGI_ADAPTER_FLAG4_SOFTWARE	= 2,
        DXGI_ADAPTER_FLAG4_ACG_COMPATIBLE	= 4,
        DXGI_ADAPTER_FLAG4_SUPPORT_MONITORED_FENCES	= 8,
        DXGI_ADAPTER_FLAG4_SUPPORT_NON_MONITORED_FENCES	= 0x10,
        DXGI_ADAPTER_FLAG4_KEYED_MUTEX_CONFORMANCE	= 0x20,
        DXGI_ADAPTER_FLAG4_SUPPORT_SINGLE_ADAPTER_HYBRID_MODE	= 0x40,
        DXGI_ADAPTER_FLAG4_FORCE_DWORD	= 0xffffffff
    } 	DXGI_ADAPTER_FLAG4;

DEFINE_ENUM_FLAG_OPERATORS( DXGI_ADAPTER_FLAG4 );
typedef struct DXGI_ADAPTER_DESC4
    {
    WCHAR Description[ 128 ];
    UINT VendorId;
    UINT DeviceId;
    UINT SubSysId;
    UINT Revision;
    SIZE_T DedicatedVideoMemory;
    SIZE_T DedicatedSystemMemory;
    SIZE_T SharedSystemMemory;
    LUID AdapterLuid;
    DXGI_ADAPTER_FLAG4 Flags;
    DXGI_GRAPHICS_PREEMPTION_GRANULARITY GraphicsPreemptionGranularity;
    DXGI_COMPUTE_PREEMPTION_GRANULARITY ComputePreemptionGranularity;
    } 	DXGI_ADAPTER_DESC4;



extern RPC_IF_HANDLE __MIDL_itf_dxgi1_7_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_dxgi1_7_0000_0000_v0_0_s_ifspec;

#ifndef __IDXGIAdapter5_INTERFACE_DEFINED__
#define __IDXGIAdapter5_INTERFACE_DEFINED__

/* interface IDXGIAdapter5 */
/* [unique][local][uuid][object] */ 


EXTERN_C const IID IID_IDXGIAdapter5;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9464643c-c95b-4674-8a7d-ee0548e8c022")
    IDXGIAdapter5 : public IDXGIAdapter4
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetDesc4( 
            /* [annotation][out] */ 
            _Out_  DXGI_ADAPTER_DESC4 *pDesc) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSingleAdapterHybridMode( 
            /* [annotation][out] */ 
            _Out_  DXGI_SINGLE_ADAPTER_HYBRID_MODE *pSingleAdapterHybridMode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetSingleAdapterHybridMode( 
            /* [annotation][in] */ 
            _In_  DXGI_SINGLE_ADAPTER_HYBRID_MODE SingleAdapterHybridMode) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IDXGIAdapter5Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDXGIAdapter5 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDXGIAdapter5 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDXGIAdapter5 * This);
        
        DECLSPEC_XFGVIRT(IDXGIObject, SetPrivateData)
        HRESULT ( STDMETHODCALLTYPE *SetPrivateData )( 
            IDXGIAdapter5 * This,
            /* [annotation][in] */ 
            _In_  REFGUID Name,
            /* [annotation][in] */ 
            _In_  UINT DataSize,
            /* [annotation][in] */ 
            _In_reads_bytes_(DataSize)  const void *pData);
        
        DECLSPEC_XFGVIRT(IDXGIObject, SetPrivateDataInterface)
        HRESULT ( STDMETHODCALLTYPE *SetPrivateDataInterface )( 
            IDXGIAdapter5 * This,
            /* [annotation][in] */ 
            _In_  REFGUID Name,
            /* [annotation][in] */ 
            _In_opt_  const IUnknown *pUnknown);
        
        DECLSPEC_XFGVIRT(IDXGIObject, GetPrivateData)
        HRESULT ( STDMETHODCALLTYPE *GetPrivateData )( 
            IDXGIAdapter5 * This,
            /* [annotation][in] */ 
            _In_  REFGUID Name,
            /* [annotation][out][in] */ 
            _Inout_  UINT *pDataSize,
            /* [annotation][out] */ 
            _Out_writes_bytes_(*pDataSize)  void *pData);
        
        DECLSPEC_XFGVIRT(IDXGIObject, GetParent)
        HRESULT ( STDMETHODCALLTYPE *GetParent )( 
            IDXGIAdapter5 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][retval][out] */ 
            _COM_Outptr_  void **ppParent);
        
        DECLSPEC_XFGVIRT(IDXGIAdapter, EnumOutputs)
        HRESULT ( STDMETHODCALLTYPE *EnumOutputs )( 
            IDXGIAdapter5 * This,
            /* [annotation][in] */ 
            _In_  UINT Output,
            /* [annotation][out][in] */ 
            _COM_Outptr_  IDXGIOutput **ppOutput);
        
        DECLSPEC_XFGVIRT(IDXGIAdapter, GetDesc)
        HRESULT ( STDMETHODCALLTYPE *GetDesc )( 
            IDXGIAdapter5 * This,
            /* [annotation][out] */ 
            _Out_  DXGI_ADAPTER_DESC *pDesc);
        
        DECLSPEC_XFGVIRT(IDXGIAdapter, CheckInterfaceSupport)
        HRESULT ( STDMETHODCALLTYPE *CheckInterfaceSupport )( 
            IDXGIAdapter5 * This,
            /* [annotation][in] */ 
            _In_  REFGUID InterfaceName,
            /* [annotation][out] */ 
            _Out_  LARGE_INTEGER *pUMDVersion);
        
        DECLSPEC_XFGVIRT(IDXGIAdapter1, GetDesc1)
        HRESULT ( STDMETHODCALLTYPE *GetDesc1 )( 
            IDXGIAdapter5 * This,
            /* [annotation][out] */ 
            _Out_  DXGI_ADAPTER_DESC1 *pDesc);
        
        DECLSPEC_XFGVIRT(IDXGIAdapter2, GetDesc2)
        HRESULT ( STDMETHODCALLTYPE *GetDesc2 )( 
            IDXGIAdapter5 * This,
            /* [annotation][out] */ 
            _Out_  DXGI_ADAPTER_DESC2 *pDesc);
        
        DECLSPEC_XFGVIRT(IDXGIAdapter3, RegisterHardwareContentProtectionTeardownStatusEvent)
        HRESULT ( STDMETHODCALLTYPE *RegisterHardwareContentProtectionTeardownStatusEvent )( 
            IDXGIAdapter5 * This,
            /* [annotation][in] */ 
            _In_  HANDLE hEvent,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwCookie);
        
        DECLSPEC_XFGVIRT(IDXGIAdapter3, UnregisterHardwareContentProtectionTeardownStatus)
        void ( STDMETHODCALLTYPE *UnregisterHardwareContentProtectionTeardownStatus )( 
            IDXGIAdapter5 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwCookie);
        
        DECLSPEC_XFGVIRT(IDXGIAdapter3, QueryVideoMemoryInfo)
        HRESULT ( STDMETHODCALLTYPE *QueryVideoMemoryInfo )( 
            IDXGIAdapter5 * This,
            /* [annotation][in] */ 
            _In_  UINT NodeIndex,
            /* [annotation][in] */ 
            _In_  DXGI_MEMORY_SEGMENT_GROUP MemorySegmentGroup,
            /* [annotation][out] */ 
            _Out_  DXGI_QUERY_VIDEO_MEMORY_INFO *pVideoMemoryInfo);
        
        DECLSPEC_XFGVIRT(IDXGIAdapter3, SetVideoMemoryReservation)
        HRESULT ( STDMETHODCALLTYPE *SetVideoMemoryReservation )( 
            IDXGIAdapter5 * This,
            /* [annotation][in] */ 
            _In_  UINT NodeIndex,
            /* [annotation][in] */ 
            _In_  DXGI_MEMORY_SEGMENT_GROUP MemorySegmentGroup,
            /* [annotation][in] */ 
            _In_  UINT64 Reservation);
        
        DECLSPEC_XFGVIRT(IDXGIAdapter3, RegisterVideoMemoryBudgetChangeNotificationEvent)
        HRESULT ( STDMETHODCALLTYPE *RegisterVideoMemoryBudgetChangeNotificationEvent )( 
            IDXGIAdapter5 * This,
            /* [annotation][in] */ 
            _In_  HANDLE hEvent,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwCookie);
        
        DECLSPEC_XFGVIRT(IDXGIAdapter3, UnregisterVideoMemoryBudgetChangeNotification)
        void ( STDMETHODCALLTYPE *UnregisterVideoMemoryBudgetChangeNotification )( 
            IDXGIAdapter5 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwCookie);
        
        DECLSPEC_XFGVIRT(IDXGIAdapter4, GetDesc3)
        HRESULT ( STDMETHODCALLTYPE *GetDesc3 )( 
            IDXGIAdapter5 * This,
            /* [annotation][out] */ 
            _Out_  DXGI_ADAPTER_DESC3 *pDesc);
        
        DECLSPEC_XFGVIRT(IDXGIAdapter5, GetDesc4)
        HRESULT ( STDMETHODCALLTYPE *GetDesc4 )( 
            IDXGIAdapter5 * This,
            /* [annotation][out] */ 
            _Out_  DXGI_ADAPTER_DESC4 *pDesc);
        
        DECLSPEC_XFGVIRT(IDXGIAdapter5, GetSingleAdapterHybridMode)
        HRESULT ( STDMETHODCALLTYPE *GetSingleAdapterHybridMode )( 
            IDXGIAdapter5 * This,
            /* [annotation][out] */ 
            _Out_  DXGI_SINGLE_ADAPTER_HYBRID_MODE *pSingleAdapterHybridMode);
        
        DECLSPEC_XFGVIRT(IDXGIAdapter5, SetSingleAdapterHybridMode)
        HRESULT ( STDMETHODCALLTYPE *SetSingleAdapterHybridMode )( 
            IDXGIAdapter5 * This,
            /* [annotation][in] */ 
            _In_  DXGI_SINGLE_ADAPTER_HYBRID_MODE SingleAdapterHybridMode);
        
        END_INTERFACE
    } IDXGIAdapter5Vtbl;

    interface IDXGIAdapter5
    {
        CONST_VTBL struct IDXGIAdapter5Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDXGIAdapter5_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDXGIAdapter5_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDXGIAdapter5_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDXGIAdapter5_SetPrivateData(This,Name,DataSize,pData)	\
    ( (This)->lpVtbl -> SetPrivateData(This,Name,DataSize,pData) ) 

#define IDXGIAdapter5_SetPrivateDataInterface(This,Name,pUnknown)	\
    ( (This)->lpVtbl -> SetPrivateDataInterface(This,Name,pUnknown) ) 

#define IDXGIAdapter5_GetPrivateData(This,Name,pDataSize,pData)	\
    ( (This)->lpVtbl -> GetPrivateData(This,Name,pDataSize,pData) ) 

#define IDXGIAdapter5_GetParent(This,riid,ppParent)	\
    ( (This)->lpVtbl -> GetParent(This,riid,ppParent) ) 


#define IDXGIAdapter5_EnumOutputs(This,Output,ppOutput)	\
    ( (This)->lpVtbl -> EnumOutputs(This,Output,ppOutput) ) 

#define IDXGIAdapter5_GetDesc(This,pDesc)	\
    ( (This)->lpVtbl -> GetDesc(This,pDesc) ) 

#define IDXGIAdapter5_CheckInterfaceSupport(This,InterfaceName,pUMDVersion)	\
    ( (This)->lpVtbl -> CheckInterfaceSupport(This,InterfaceName,pUMDVersion) ) 


#define IDXGIAdapter5_GetDesc1(This,pDesc)	\
    ( (This)->lpVtbl -> GetDesc1(This,pDesc) ) 


#define IDXGIAdapter5_GetDesc2(This,pDesc)	\
    ( (This)->lpVtbl -> GetDesc2(This,pDesc) ) 


#define IDXGIAdapter5_RegisterHardwareContentProtectionTeardownStatusEvent(This,hEvent,pdwCookie)	\
    ( (This)->lpVtbl -> RegisterHardwareContentProtectionTeardownStatusEvent(This,hEvent,pdwCookie) ) 

#define IDXGIAdapter5_UnregisterHardwareContentProtectionTeardownStatus(This,dwCookie)	\
    ( (This)->lpVtbl -> UnregisterHardwareContentProtectionTeardownStatus(This,dwCookie) ) 

#define IDXGIAdapter5_QueryVideoMemoryInfo(This,NodeIndex,MemorySegmentGroup,pVideoMemoryInfo)	\
    ( (This)->lpVtbl -> QueryVideoMemoryInfo(This,NodeIndex,MemorySegmentGroup,pVideoMemoryInfo) ) 

#define IDXGIAdapter5_SetVideoMemoryReservation(This,NodeIndex,MemorySegmentGroup,Reservation)	\
    ( (This)->lpVtbl -> SetVideoMemoryReservation(This,NodeIndex,MemorySegmentGroup,Reservation) ) 

#define IDXGIAdapter5_RegisterVideoMemoryBudgetChangeNotificationEvent(This,hEvent,pdwCookie)	\
    ( (This)->lpVtbl -> RegisterVideoMemoryBudgetChangeNotificationEvent(This,hEvent,pdwCookie) ) 

#define IDXGIAdapter5_UnregisterVideoMemoryBudgetChangeNotification(This,dwCookie)	\
    ( (This)->lpVtbl -> UnregisterVideoMemoryBudgetChangeNotification(This,dwCookie) ) 


#define IDXGIAdapter5_GetDesc3(This,pDesc)	\
    ( (This)->lpVtbl -> GetDesc3(This,pDesc) ) 


#define IDXGIAdapter5_GetDesc4(This,pDesc)	\
    ( (This)->lpVtbl -> GetDesc4(This,pDesc) ) 

#define IDXGIAdapter5_GetSingleAdapterHybridMode(This,pSingleAdapterHybridMode)	\
    ( (This)->lpVtbl -> GetSingleAdapterHybridMode(This,pSingleAdapterHybridMode) ) 

#define IDXGIAdapter5_SetSingleAdapterHybridMode(This,SingleAdapterHybridMode)	\
    ( (This)->lpVtbl -> SetSingleAdapterHybridMode(This,SingleAdapterHybridMode) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDXGIAdapter5_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_dxgi1_7_0000_0001 */
/* [local] */ 

typedef struct DXGI_SWAP_CHAIN_DESC2
    {
    UINT Width;
    UINT Height;
    DXGI_FORMAT Format;
    BOOL Stereo;
    DXGI_SAMPLE_DESC SampleDesc;
    DXGI_USAGE BufferUsage;
    UINT BufferCount;
    DXGI_SCALING Scaling;
    DXGI_SWAP_EFFECT SwapEffect;
    DXGI_ALPHA_MODE AlphaMode;
    UINT Flags;
    DXGI_COLOR_SPACE_TYPE ColorSpace;
    } 	DXGI_SWAP_CHAIN_DESC2;



extern RPC_IF_HANDLE __MIDL_itf_dxgi1_7_0000_0001_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_dxgi1_7_0000_0001_v0_0_s_ifspec;

#ifndef __IDXGISwapChain5_INTERFACE_DEFINED__
#define __IDXGISwapChain5_INTERFACE_DEFINED__

/* interface IDXGISwapChain5 */
/* [unique][local][uuid][object] */ 


EXTERN_C const IID IID_IDXGISwapChain5;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9086bf22-9338-43bb-87ce-7790b6438a7f")
    IDXGISwapChain5 : public IDXGISwapChain4
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetDesc2( 
            /* [annotation][out] */ 
            _Out_  DXGI_SWAP_CHAIN_DESC2 *pDesc) = 0;
        
        virtual DXGI_COLOR_SPACE_TYPE STDMETHODCALLTYPE GetColorSpace1( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ResizeBuffers2( 
            /* [annotation][in] */ 
            _In_  UINT BufferCount,
            /* [annotation][in] */ 
            _In_  UINT Width,
            /* [annotation][in] */ 
            _In_  UINT Height,
            /* [annotation][in] */ 
            _In_  DXGI_FORMAT Format,
            /* [annotation][in] */ 
            _In_  UINT SwapChainFlags,
            /* [annotation][in] */ 
            _In_reads_opt_(BufferCount)  const UINT *pCreationNodeMask,
            /* [annotation][in] */ 
            _In_reads_opt_(BufferCount)  IUnknown *const *ppPresentQueue,
            /* [annotation][in] */ 
            _In_  DXGI_COLOR_SPACE_TYPE ColorSpace) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IDXGISwapChain5Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDXGISwapChain5 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDXGISwapChain5 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDXGISwapChain5 * This);
        
        DECLSPEC_XFGVIRT(IDXGIObject, SetPrivateData)
        HRESULT ( STDMETHODCALLTYPE *SetPrivateData )( 
            IDXGISwapChain5 * This,
            /* [annotation][in] */ 
            _In_  REFGUID Name,
            /* [annotation][in] */ 
            _In_  UINT DataSize,
            /* [annotation][in] */ 
            _In_reads_bytes_(DataSize)  const void *pData);
        
        DECLSPEC_XFGVIRT(IDXGIObject, SetPrivateDataInterface)
        HRESULT ( STDMETHODCALLTYPE *SetPrivateDataInterface )( 
            IDXGISwapChain5 * This,
            /* [annotation][in] */ 
            _In_  REFGUID Name,
            /* [annotation][in] */ 
            _In_opt_  const IUnknown *pUnknown);
        
        DECLSPEC_XFGVIRT(IDXGIObject, GetPrivateData)
        HRESULT ( STDMETHODCALLTYPE *GetPrivateData )( 
            IDXGISwapChain5 * This,
            /* [annotation][in] */ 
            _In_  REFGUID Name,
            /* [annotation][out][in] */ 
            _Inout_  UINT *pDataSize,
            /* [annotation][out] */ 
            _Out_writes_bytes_(*pDataSize)  void *pData);
        
        DECLSPEC_XFGVIRT(IDXGIObject, GetParent)
        HRESULT ( STDMETHODCALLTYPE *GetParent )( 
            IDXGISwapChain5 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][retval][out] */ 
            _COM_Outptr_  void **ppParent);
        
        DECLSPEC_XFGVIRT(IDXGIDeviceSubObject, GetDevice)
        HRESULT ( STDMETHODCALLTYPE *GetDevice )( 
            IDXGISwapChain5 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][retval][out] */ 
            _COM_Outptr_  void **ppDevice);
        
        DECLSPEC_XFGVIRT(IDXGISwapChain, Present)
        HRESULT ( STDMETHODCALLTYPE *Present )( 
            IDXGISwapChain5 * This,
            /* [annotation][in] */ 
            _In_  UINT SyncInterval,
            /* [annotation][in] */ 
            _In_  UINT Flags);
        
        DECLSPEC_XFGVIRT(IDXGISwapChain, GetBuffer)
        HRESULT ( STDMETHODCALLTYPE *GetBuffer )( 
            IDXGISwapChain5 * This,
            /* [annotation][in] */ 
            _In_  UINT Buffer,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][out][in] */ 
            _COM_Outptr_  void **ppSurface);
        
        DECLSPEC_XFGVIRT(IDXGISwapChain, SetFullscreenState)
        HRESULT ( STDMETHODCALLTYPE *SetFullscreenState )( 
            IDXGISwapChain5 * This,
            /* [annotation][in] */ 
            _In_  BOOL Fullscreen,
            /* [annotation][in] */ 
            _In_opt_  IDXGIOutput *pTarget);
        
        DECLSPEC_XFGVIRT(IDXGISwapChain, GetFullscreenState)
        HRESULT ( STDMETHODCALLTYPE *GetFullscreenState )( 
            IDXGISwapChain5 * This,
            /* [annotation][out] */ 
            _Out_opt_  BOOL *pFullscreen,
            /* [annotation][out] */ 
            _COM_Outptr_opt_result_maybenull_  IDXGIOutput **ppTarget);
        
        DECLSPEC_XFGVIRT(IDXGISwapChain, GetDesc)
        HRESULT ( STDMETHODCALLTYPE *GetDesc )( 
            IDXGISwapChain5 * This,
            /* [annotation][out] */ 
            _Out_  DXGI_SWAP_CHAIN_DESC *pDesc);
        
        DECLSPEC_XFGVIRT(IDXGISwapChain, ResizeBuffers)
        HRESULT ( STDMETHODCALLTYPE *ResizeBuffers )( 
            IDXGISwapChain5 * This,
            /* [annotation][in] */ 
            _In_  UINT BufferCount,
            /* [annotation][in] */ 
            _In_  UINT Width,
            /* [annotation][in] */ 
            _In_  UINT Height,
            /* [annotation][in] */ 
            _In_  DXGI_FORMAT NewFormat,
            /* [annotation][in] */ 
            _In_  UINT SwapChainFlags);
        
        DECLSPEC_XFGVIRT(IDXGISwapChain, ResizeTarget)
        HRESULT ( STDMETHODCALLTYPE *ResizeTarget )( 
            IDXGISwapChain5 * This,
            /* [annotation][in] */ 
            _In_  const DXGI_MODE_DESC *pNewTargetParameters);
        
        DECLSPEC_XFGVIRT(IDXGISwapChain, GetContainingOutput)
        HRESULT ( STDMETHODCALLTYPE *GetContainingOutput )( 
            IDXGISwapChain5 * This,
            /* [annotation][out] */ 
            _COM_Outptr_  IDXGIOutput **ppOutput);
        
        DECLSPEC_XFGVIRT(IDXGISwapChain, GetFrameStatistics)
        HRESULT ( STDMETHODCALLTYPE *GetFrameStatistics )( 
            IDXGISwapChain5 * This,
            /* [annotation][out] */ 
            _Out_  DXGI_FRAME_STATISTICS *pStats);
        
        DECLSPEC_XFGVIRT(IDXGISwapChain, GetLastPresentCount)
        HRESULT ( STDMETHODCALLTYPE *GetLastPresentCount )( 
            IDXGISwapChain5 * This,
            /* [annotation][out] */ 
            _Out_  UINT *pLastPresentCount);
        
        DECLSPEC_XFGVIRT(IDXGISwapChain1, GetDesc1)
        HRESULT ( STDMETHODCALLTYPE *GetDesc1 )( 
            IDXGISwapChain5 * This,
            /* [annotation][out] */ 
            _Out_  DXGI_SWAP_CHAIN_DESC1 *pDesc);
        
        DECLSPEC_XFGVIRT(IDXGISwapChain1, GetFullscreenDesc)
        HRESULT ( STDMETHODCALLTYPE *GetFullscreenDesc )( 
            IDXGISwapChain5 * This,
            /* [annotation][out] */ 
            _Out_  DXGI_SWAP_CHAIN_FULLSCREEN_DESC *pDesc);
        
        DECLSPEC_XFGVIRT(IDXGISwapChain1, GetHwnd)
        HRESULT ( STDMETHODCALLTYPE *GetHwnd )( 
            IDXGISwapChain5 * This,
            /* [annotation][out] */ 
            _Out_  HWND *pHwnd);
        
        DECLSPEC_XFGVIRT(IDXGISwapChain1, GetCoreWindow)
        HRESULT ( STDMETHODCALLTYPE *GetCoreWindow )( 
            IDXGISwapChain5 * This,
            /* [annotation][in] */ 
            _In_  REFIID refiid,
            /* [annotation][out] */ 
            _COM_Outptr_  void **ppUnk);
        
        DECLSPEC_XFGVIRT(IDXGISwapChain1, Present1)
        HRESULT ( STDMETHODCALLTYPE *Present1 )( 
            IDXGISwapChain5 * This,
            /* [annotation][in] */ 
            _In_  UINT SyncInterval,
            /* [annotation][in] */ 
            _In_  UINT PresentFlags,
            /* [annotation][in] */ 
            _In_  const DXGI_PRESENT_PARAMETERS *pPresentParameters);
        
        DECLSPEC_XFGVIRT(IDXGISwapChain1, IsTemporaryMonoSupported)
        BOOL ( STDMETHODCALLTYPE *IsTemporaryMonoSupported )( 
            IDXGISwapChain5 * This);
        
        DECLSPEC_XFGVIRT(IDXGISwapChain1, GetRestrictToOutput)
        HRESULT ( STDMETHODCALLTYPE *GetRestrictToOutput )( 
            IDXGISwapChain5 * This,
            /* [annotation][out] */ 
            _Out_  IDXGIOutput **ppRestrictToOutput);
        
        DECLSPEC_XFGVIRT(IDXGISwapChain1, SetBackgroundColor)
        HRESULT ( STDMETHODCALLTYPE *SetBackgroundColor )( 
            IDXGISwapChain5 * This,
            /* [annotation][in] */ 
            _In_  const DXGI_RGBA *pColor);
        
        DECLSPEC_XFGVIRT(IDXGISwapChain1, GetBackgroundColor)
        HRESULT ( STDMETHODCALLTYPE *GetBackgroundColor )( 
            IDXGISwapChain5 * This,
            /* [annotation][out] */ 
            _Out_  DXGI_RGBA *pColor);
        
        DECLSPEC_XFGVIRT(IDXGISwapChain1, SetRotation)
        HRESULT ( STDMETHODCALLTYPE *SetRotation )( 
            IDXGISwapChain5 * This,
            /* [annotation][in] */ 
            _In_  DXGI_MODE_ROTATION Rotation);
        
        DECLSPEC_XFGVIRT(IDXGISwapChain1, GetRotation)
        HRESULT ( STDMETHODCALLTYPE *GetRotation )( 
            IDXGISwapChain5 * This,
            /* [annotation][out] */ 
            _Out_  DXGI_MODE_ROTATION *pRotation);
        
        DECLSPEC_XFGVIRT(IDXGISwapChain2, SetSourceSize)
        HRESULT ( STDMETHODCALLTYPE *SetSourceSize )( 
            IDXGISwapChain5 * This,
            UINT Width,
            UINT Height);
        
        DECLSPEC_XFGVIRT(IDXGISwapChain2, GetSourceSize)
        HRESULT ( STDMETHODCALLTYPE *GetSourceSize )( 
            IDXGISwapChain5 * This,
            /* [annotation][out] */ 
            _Out_  UINT *pWidth,
            /* [annotation][out] */ 
            _Out_  UINT *pHeight);
        
        DECLSPEC_XFGVIRT(IDXGISwapChain2, SetMaximumFrameLatency)
        HRESULT ( STDMETHODCALLTYPE *SetMaximumFrameLatency )( 
            IDXGISwapChain5 * This,
            UINT MaxLatency);
        
        DECLSPEC_XFGVIRT(IDXGISwapChain2, GetMaximumFrameLatency)
        HRESULT ( STDMETHODCALLTYPE *GetMaximumFrameLatency )( 
            IDXGISwapChain5 * This,
            /* [annotation][out] */ 
            _Out_  UINT *pMaxLatency);
        
        DECLSPEC_XFGVIRT(IDXGISwapChain2, GetFrameLatencyWaitableObject)
        HANDLE ( STDMETHODCALLTYPE *GetFrameLatencyWaitableObject )( 
            IDXGISwapChain5 * This);
        
        DECLSPEC_XFGVIRT(IDXGISwapChain2, SetMatrixTransform)
        HRESULT ( STDMETHODCALLTYPE *SetMatrixTransform )( 
            IDXGISwapChain5 * This,
            const DXGI_MATRIX_3X2_F *pMatrix);
        
        DECLSPEC_XFGVIRT(IDXGISwapChain2, GetMatrixTransform)
        HRESULT ( STDMETHODCALLTYPE *GetMatrixTransform )( 
            IDXGISwapChain5 * This,
            /* [annotation][out] */ 
            _Out_  DXGI_MATRIX_3X2_F *pMatrix);
        
        DECLSPEC_XFGVIRT(IDXGISwapChain3, GetCurrentBackBufferIndex)
        UINT ( STDMETHODCALLTYPE *GetCurrentBackBufferIndex )( 
            IDXGISwapChain5 * This);
        
        DECLSPEC_XFGVIRT(IDXGISwapChain3, CheckColorSpaceSupport)
        HRESULT ( STDMETHODCALLTYPE *CheckColorSpaceSupport )( 
            IDXGISwapChain5 * This,
            /* [annotation][in] */ 
            _In_  DXGI_COLOR_SPACE_TYPE ColorSpace,
            /* [annotation][out] */ 
            _Out_  UINT *pColorSpaceSupport);
        
        DECLSPEC_XFGVIRT(IDXGISwapChain3, SetColorSpace1)
        HRESULT ( STDMETHODCALLTYPE *SetColorSpace1 )( 
            IDXGISwapChain5 * This,
            /* [annotation][in] */ 
            _In_  DXGI_COLOR_SPACE_TYPE ColorSpace);
        
        DECLSPEC_XFGVIRT(IDXGISwapChain3, ResizeBuffers1)
        HRESULT ( STDMETHODCALLTYPE *ResizeBuffers1 )( 
            IDXGISwapChain5 * This,
            /* [annotation][in] */ 
            _In_  UINT BufferCount,
            /* [annotation][in] */ 
            _In_  UINT Width,
            /* [annotation][in] */ 
            _In_  UINT Height,
            /* [annotation][in] */ 
            _In_  DXGI_FORMAT Format,
            /* [annotation][in] */ 
            _In_  UINT SwapChainFlags,
            /* [annotation][in] */ 
            _In_reads_(BufferCount)  const UINT *pCreationNodeMask,
            /* [annotation][in] */ 
            _In_reads_(BufferCount)  IUnknown *const *ppPresentQueue);
        
        DECLSPEC_XFGVIRT(IDXGISwapChain4, SetHDRMetaData)
        HRESULT ( STDMETHODCALLTYPE *SetHDRMetaData )( 
            IDXGISwapChain5 * This,
            /* [annotation][in] */ 
            _In_  DXGI_HDR_METADATA_TYPE Type,
            /* [annotation][in] */ 
            _In_  UINT Size,
            /* [annotation][size_is][in] */ 
            _In_reads_opt_(Size)  void *pMetaData);
        
        DECLSPEC_XFGVIRT(IDXGISwapChain5, GetDesc2)
        HRESULT ( STDMETHODCALLTYPE *GetDesc2 )( 
            IDXGISwapChain5 * This,
            /* [annotation][out] */ 
            _Out_  DXGI_SWAP_CHAIN_DESC2 *pDesc);
        
        DECLSPEC_XFGVIRT(IDXGISwapChain5, GetColorSpace1)
        DXGI_COLOR_SPACE_TYPE ( STDMETHODCALLTYPE *GetColorSpace1 )( 
            IDXGISwapChain5 * This);
        
        DECLSPEC_XFGVIRT(IDXGISwapChain5, ResizeBuffers2)
        HRESULT ( STDMETHODCALLTYPE *ResizeBuffers2 )( 
            IDXGISwapChain5 * This,
            /* [annotation][in] */ 
            _In_  UINT BufferCount,
            /* [annotation][in] */ 
            _In_  UINT Width,
            /* [annotation][in] */ 
            _In_  UINT Height,
            /* [annotation][in] */ 
            _In_  DXGI_FORMAT Format,
            /* [annotation][in] */ 
            _In_  UINT SwapChainFlags,
            /* [annotation][in] */ 
            _In_reads_opt_(BufferCount)  const UINT *pCreationNodeMask,
            /* [annotation][in] */ 
            _In_reads_opt_(BufferCount)  IUnknown *const *ppPresentQueue,
            /* [annotation][in] */ 
            _In_  DXGI_COLOR_SPACE_TYPE ColorSpace);
        
        END_INTERFACE
    } IDXGISwapChain5Vtbl;

    interface IDXGISwapChain5
    {
        CONST_VTBL struct IDXGISwapChain5Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDXGISwapChain5_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDXGISwapChain5_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDXGISwapChain5_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDXGISwapChain5_SetPrivateData(This,Name,DataSize,pData)	\
    ( (This)->lpVtbl -> SetPrivateData(This,Name,DataSize,pData) ) 

#define IDXGISwapChain5_SetPrivateDataInterface(This,Name,pUnknown)	\
    ( (This)->lpVtbl -> SetPrivateDataInterface(This,Name,pUnknown) ) 

#define IDXGISwapChain5_GetPrivateData(This,Name,pDataSize,pData)	\
    ( (This)->lpVtbl -> GetPrivateData(This,Name,pDataSize,pData) ) 

#define IDXGISwapChain5_GetParent(This,riid,ppParent)	\
    ( (This)->lpVtbl -> GetParent(This,riid,ppParent) ) 


#define IDXGISwapChain5_GetDevice(This,riid,ppDevice)	\
    ( (This)->lpVtbl -> GetDevice(This,riid,ppDevice) ) 


#define IDXGISwapChain5_Present(This,SyncInterval,Flags)	\
    ( (This)->lpVtbl -> Present(This,SyncInterval,Flags) ) 

#define IDXGISwapChain5_GetBuffer(This,Buffer,riid,ppSurface)	\
    ( (This)->lpVtbl -> GetBuffer(This,Buffer,riid,ppSurface) ) 

#define IDXGISwapChain5_SetFullscreenState(This,Fullscreen,pTarget)	\
    ( (This)->lpVtbl -> SetFullscreenState(This,Fullscreen,pTarget) ) 

#define IDXGISwapChain5_GetFullscreenState(This,pFullscreen,ppTarget)	\
    ( (This)->lpVtbl -> GetFullscreenState(This,pFullscreen,ppTarget) ) 

#define IDXGISwapChain5_GetDesc(This,pDesc)	\
    ( (This)->lpVtbl -> GetDesc(This,pDesc) ) 

#define IDXGISwapChain5_ResizeBuffers(This,BufferCount,Width,Height,NewFormat,SwapChainFlags)	\
    ( (This)->lpVtbl -> ResizeBuffers(This,BufferCount,Width,Height,NewFormat,SwapChainFlags) ) 

#define IDXGISwapChain5_ResizeTarget(This,pNewTargetParameters)	\
    ( (This)->lpVtbl -> ResizeTarget(This,pNewTargetParameters) ) 

#define IDXGISwapChain5_GetContainingOutput(This,ppOutput)	\
    ( (This)->lpVtbl -> GetContainingOutput(This,ppOutput) ) 

#define IDXGISwapChain5_GetFrameStatistics(This,pStats)	\
    ( (This)->lpVtbl -> GetFrameStatistics(This,pStats) ) 

#define IDXGISwapChain5_GetLastPresentCount(This,pLastPresentCount)	\
    ( (This)->lpVtbl -> GetLastPresentCount(This,pLastPresentCount) ) 


#define IDXGISwapChain5_GetDesc1(This,pDesc)	\
    ( (This)->lpVtbl -> GetDesc1(This,pDesc) ) 

#define IDXGISwapChain5_GetFullscreenDesc(This,pDesc)	\
    ( (This)->lpVtbl -> GetFullscreenDesc(This,pDesc) ) 

#define IDXGISwapChain5_GetHwnd(This,pHwnd)	\
    ( (This)->lpVtbl -> GetHwnd(This,pHwnd) ) 

#define IDXGISwapChain5_GetCoreWindow(This,refiid,ppUnk)	\
    ( (This)->lpVtbl -> GetCoreWindow(This,refiid,ppUnk) ) 

#define IDXGISwapChain5_Present1(This,SyncInterval,PresentFlags,pPresentParameters)	\
    ( (This)->lpVtbl -> Present1(This,SyncInterval,PresentFlags,pPresentParameters) ) 

#define IDXGISwapChain5_IsTemporaryMonoSupported(This)	\
    ( (This)->lpVtbl -> IsTemporaryMonoSupported(This) ) 

#define IDXGISwapChain5_GetRestrictToOutput(This,ppRestrictToOutput)	\
    ( (This)->lpVtbl -> GetRestrictToOutput(This,ppRestrictToOutput) ) 

#define IDXGISwapChain5_SetBackgroundColor(This,pColor)	\
    ( (This)->lpVtbl -> SetBackgroundColor(This,pColor) ) 

#define IDXGISwapChain5_GetBackgroundColor(This,pColor)	\
    ( (This)->lpVtbl -> GetBackgroundColor(This,pColor) ) 

#define IDXGISwapChain5_SetRotation(This,Rotation)	\
    ( (This)->lpVtbl -> SetRotation(This,Rotation) ) 

#define IDXGISwapChain5_GetRotation(This,pRotation)	\
    ( (This)->lpVtbl -> GetRotation(This,pRotation) ) 


#define IDXGISwapChain5_SetSourceSize(This,Width,Height)	\
    ( (This)->lpVtbl -> SetSourceSize(This,Width,Height) ) 

#define IDXGISwapChain5_GetSourceSize(This,pWidth,pHeight)	\
    ( (This)->lpVtbl -> GetSourceSize(This,pWidth,pHeight) ) 

#define IDXGISwapChain5_SetMaximumFrameLatency(This,MaxLatency)	\
    ( (This)->lpVtbl -> SetMaximumFrameLatency(This,MaxLatency) ) 

#define IDXGISwapChain5_GetMaximumFrameLatency(This,pMaxLatency)	\
    ( (This)->lpVtbl -> GetMaximumFrameLatency(This,pMaxLatency) ) 

#define IDXGISwapChain5_GetFrameLatencyWaitableObject(This)	\
    ( (This)->lpVtbl -> GetFrameLatencyWaitableObject(This) ) 

#define IDXGISwapChain5_SetMatrixTransform(This,pMatrix)	\
    ( (This)->lpVtbl -> SetMatrixTransform(This,pMatrix) ) 

#define IDXGISwapChain5_GetMatrixTransform(This,pMatrix)	\
    ( (This)->lpVtbl -> GetMatrixTransform(This,pMatrix) ) 


#define IDXGISwapChain5_GetCurrentBackBufferIndex(This)	\
    ( (This)->lpVtbl -> GetCurrentBackBufferIndex(This) ) 

#define IDXGISwapChain5_CheckColorSpaceSupport(This,ColorSpace,pColorSpaceSupport)	\
    ( (This)->lpVtbl -> CheckColorSpaceSupport(This,ColorSpace,pColorSpaceSupport) ) 

#define IDXGISwapChain5_SetColorSpace1(This,ColorSpace)	\
    ( (This)->lpVtbl -> SetColorSpace1(This,ColorSpace) ) 

#define IDXGISwapChain5_ResizeBuffers1(This,BufferCount,Width,Height,Format,SwapChainFlags,pCreationNodeMask,ppPresentQueue)	\
    ( (This)->lpVtbl -> ResizeBuffers1(This,BufferCount,Width,Height,Format,SwapChainFlags,pCreationNodeMask,ppPresentQueue) ) 


#define IDXGISwapChain5_SetHDRMetaData(This,Type,Size,pMetaData)	\
    ( (This)->lpVtbl -> SetHDRMetaData(This,Type,Size,pMetaData) ) 


#define IDXGISwapChain5_GetDesc2(This,pDesc)	\
    ( (This)->lpVtbl -> GetDesc2(This,pDesc) ) 

#define IDXGISwapChain5_GetColorSpace1(This)	\
    ( (This)->lpVtbl -> GetColorSpace1(This) ) 

#define IDXGISwapChain5_ResizeBuffers2(This,BufferCount,Width,Height,Format,SwapChainFlags,pCreationNodeMask,ppPresentQueue,ColorSpace)	\
    ( (This)->lpVtbl -> ResizeBuffers2(This,BufferCount,Width,Height,Format,SwapChainFlags,pCreationNodeMask,ppPresentQueue,ColorSpace) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDXGISwapChain5_INTERFACE_DEFINED__ */


#ifndef __IDXGIFactory8_INTERFACE_DEFINED__
#define __IDXGIFactory8_INTERFACE_DEFINED__

/* interface IDXGIFactory8 */
/* [unique][local][uuid][object] */ 


EXTERN_C const IID IID_IDXGIFactory8;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("693c45c1-39a7-4c1f-bdd3-d9a3229b8321")
    IDXGIFactory8 : public IDXGIFactory7
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CreateSwapChainForHwnd1( 
            /* [annotation][in] */ 
            _In_  IUnknown *pDevice,
            /* [annotation][in] */ 
            _In_  HWND hWnd,
            /* [annotation][in] */ 
            _In_  const DXGI_SWAP_CHAIN_DESC2 *pDesc,
            /* [annotation][in] */ 
            _In_opt_  const DXGI_SWAP_CHAIN_FULLSCREEN_DESC *pFullscreenDesc,
            /* [annotation][in] */ 
            _In_opt_  IDXGIOutput *pRestrictToOutput,
            /* [annotation][out] */ 
            _COM_Outptr_  IDXGISwapChain5 **ppSwapChain) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateSwapChainForCoreWindow1( 
            /* [annotation][in] */ 
            _In_  IUnknown *pDevice,
            /* [annotation][in] */ 
            _In_  IUnknown *pWindow,
            /* [annotation][in] */ 
            _In_  const DXGI_SWAP_CHAIN_DESC2 *pDesc,
            /* [annotation][in] */ 
            _In_opt_  IDXGIOutput *pRestrictToOutput,
            /* [annotation][out] */ 
            _COM_Outptr_  IDXGISwapChain5 **ppSwapChain) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateSwapChainForComposition1( 
            /* [annotation][in] */ 
            _In_  IUnknown *pDevice,
            /* [annotation][in] */ 
            _In_  const DXGI_SWAP_CHAIN_DESC2 *pDesc,
            /* [annotation][in] */ 
            _In_opt_  IDXGIOutput *pRestrictToOutput,
            /* [annotation][out] */ 
            _COM_Outptr_  IDXGISwapChain5 **ppSwapChain) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IDXGIFactory8Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDXGIFactory8 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDXGIFactory8 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDXGIFactory8 * This);
        
        DECLSPEC_XFGVIRT(IDXGIObject, SetPrivateData)
        HRESULT ( STDMETHODCALLTYPE *SetPrivateData )( 
            IDXGIFactory8 * This,
            /* [annotation][in] */ 
            _In_  REFGUID Name,
            /* [annotation][in] */ 
            _In_  UINT DataSize,
            /* [annotation][in] */ 
            _In_reads_bytes_(DataSize)  const void *pData);
        
        DECLSPEC_XFGVIRT(IDXGIObject, SetPrivateDataInterface)
        HRESULT ( STDMETHODCALLTYPE *SetPrivateDataInterface )( 
            IDXGIFactory8 * This,
            /* [annotation][in] */ 
            _In_  REFGUID Name,
            /* [annotation][in] */ 
            _In_opt_  const IUnknown *pUnknown);
        
        DECLSPEC_XFGVIRT(IDXGIObject, GetPrivateData)
        HRESULT ( STDMETHODCALLTYPE *GetPrivateData )( 
            IDXGIFactory8 * This,
            /* [annotation][in] */ 
            _In_  REFGUID Name,
            /* [annotation][out][in] */ 
            _Inout_  UINT *pDataSize,
            /* [annotation][out] */ 
            _Out_writes_bytes_(*pDataSize)  void *pData);
        
        DECLSPEC_XFGVIRT(IDXGIObject, GetParent)
        HRESULT ( STDMETHODCALLTYPE *GetParent )( 
            IDXGIFactory8 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][retval][out] */ 
            _COM_Outptr_  void **ppParent);
        
        DECLSPEC_XFGVIRT(IDXGIFactory, EnumAdapters)
        HRESULT ( STDMETHODCALLTYPE *EnumAdapters )( 
            IDXGIFactory8 * This,
            /* [annotation][in] */ 
            _In_  UINT Adapter,
            /* [annotation][out] */ 
            _COM_Outptr_  IDXGIAdapter **ppAdapter);
        
        DECLSPEC_XFGVIRT(IDXGIFactory, MakeWindowAssociation)
        HRESULT ( STDMETHODCALLTYPE *MakeWindowAssociation )( 
            IDXGIFactory8 * This,
            HWND WindowHandle,
            UINT Flags);
        
        DECLSPEC_XFGVIRT(IDXGIFactory, GetWindowAssociation)
        HRESULT ( STDMETHODCALLTYPE *GetWindowAssociation )( 
            IDXGIFactory8 * This,
            /* [annotation][out] */ 
            _Out_  HWND *pWindowHandle);
        
        DECLSPEC_XFGVIRT(IDXGIFactory, CreateSwapChain)
        HRESULT ( STDMETHODCALLTYPE *CreateSwapChain )( 
            IDXGIFactory8 * This,
            /* [annotation][in] */ 
            _In_  IUnknown *pDevice,
            /* [annotation][in] */ 
            _In_  DXGI_SWAP_CHAIN_DESC *pDesc,
            /* [annotation][out] */ 
            _COM_Outptr_  IDXGISwapChain **ppSwapChain);
        
        DECLSPEC_XFGVIRT(IDXGIFactory, CreateSoftwareAdapter)
        HRESULT ( STDMETHODCALLTYPE *CreateSoftwareAdapter )( 
            IDXGIFactory8 * This,
            /* [annotation][in] */ 
            _In_  HMODULE Module,
            /* [annotation][out] */ 
            _COM_Outptr_  IDXGIAdapter **ppAdapter);
        
        DECLSPEC_XFGVIRT(IDXGIFactory1, EnumAdapters1)
        HRESULT ( STDMETHODCALLTYPE *EnumAdapters1 )( 
            IDXGIFactory8 * This,
            /* [annotation][in] */ 
            _In_  UINT Adapter,
            /* [annotation][out] */ 
            _COM_Outptr_  IDXGIAdapter1 **ppAdapter);
        
        DECLSPEC_XFGVIRT(IDXGIFactory1, IsCurrent)
        BOOL ( STDMETHODCALLTYPE *IsCurrent )( 
            IDXGIFactory8 * This);
        
        DECLSPEC_XFGVIRT(IDXGIFactory2, IsWindowedStereoEnabled)
        BOOL ( STDMETHODCALLTYPE *IsWindowedStereoEnabled )( 
            IDXGIFactory8 * This);
        
        DECLSPEC_XFGVIRT(IDXGIFactory2, CreateSwapChainForHwnd)
        HRESULT ( STDMETHODCALLTYPE *CreateSwapChainForHwnd )( 
            IDXGIFactory8 * This,
            /* [annotation][in] */ 
            _In_  IUnknown *pDevice,
            /* [annotation][in] */ 
            _In_  HWND hWnd,
            /* [annotation][in] */ 
            _In_  const DXGI_SWAP_CHAIN_DESC1 *pDesc,
            /* [annotation][in] */ 
            _In_opt_  const DXGI_SWAP_CHAIN_FULLSCREEN_DESC *pFullscreenDesc,
            /* [annotation][in] */ 
            _In_opt_  IDXGIOutput *pRestrictToOutput,
            /* [annotation][out] */ 
            _COM_Outptr_  IDXGISwapChain1 **ppSwapChain);
        
        DECLSPEC_XFGVIRT(IDXGIFactory2, CreateSwapChainForCoreWindow)
        HRESULT ( STDMETHODCALLTYPE *CreateSwapChainForCoreWindow )( 
            IDXGIFactory8 * This,
            /* [annotation][in] */ 
            _In_  IUnknown *pDevice,
            /* [annotation][in] */ 
            _In_  IUnknown *pWindow,
            /* [annotation][in] */ 
            _In_  const DXGI_SWAP_CHAIN_DESC1 *pDesc,
            /* [annotation][in] */ 
            _In_opt_  IDXGIOutput *pRestrictToOutput,
            /* [annotation][out] */ 
            _COM_Outptr_  IDXGISwapChain1 **ppSwapChain);
        
        DECLSPEC_XFGVIRT(IDXGIFactory2, GetSharedResourceAdapterLuid)
        HRESULT ( STDMETHODCALLTYPE *GetSharedResourceAdapterLuid )( 
            IDXGIFactory8 * This,
            /* [annotation] */ 
            _In_  HANDLE hResource,
            /* [annotation] */ 
            _Out_  LUID *pLuid);
        
        DECLSPEC_XFGVIRT(IDXGIFactory2, RegisterStereoStatusWindow)
        HRESULT ( STDMETHODCALLTYPE *RegisterStereoStatusWindow )( 
            IDXGIFactory8 * This,
            /* [annotation][in] */ 
            _In_  HWND WindowHandle,
            /* [annotation][in] */ 
            _In_  UINT wMsg,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwCookie);
        
        DECLSPEC_XFGVIRT(IDXGIFactory2, RegisterStereoStatusEvent)
        HRESULT ( STDMETHODCALLTYPE *RegisterStereoStatusEvent )( 
            IDXGIFactory8 * This,
            /* [annotation][in] */ 
            _In_  HANDLE hEvent,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwCookie);
        
        DECLSPEC_XFGVIRT(IDXGIFactory2, UnregisterStereoStatus)
        void ( STDMETHODCALLTYPE *UnregisterStereoStatus )( 
            IDXGIFactory8 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwCookie);
        
        DECLSPEC_XFGVIRT(IDXGIFactory2, RegisterOcclusionStatusWindow)
        HRESULT ( STDMETHODCALLTYPE *RegisterOcclusionStatusWindow )( 
            IDXGIFactory8 * This,
            /* [annotation][in] */ 
            _In_  HWND WindowHandle,
            /* [annotation][in] */ 
            _In_  UINT wMsg,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwCookie);
        
        DECLSPEC_XFGVIRT(IDXGIFactory2, RegisterOcclusionStatusEvent)
        HRESULT ( STDMETHODCALLTYPE *RegisterOcclusionStatusEvent )( 
            IDXGIFactory8 * This,
            /* [annotation][in] */ 
            _In_  HANDLE hEvent,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwCookie);
        
        DECLSPEC_XFGVIRT(IDXGIFactory2, UnregisterOcclusionStatus)
        void ( STDMETHODCALLTYPE *UnregisterOcclusionStatus )( 
            IDXGIFactory8 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwCookie);
        
        DECLSPEC_XFGVIRT(IDXGIFactory2, CreateSwapChainForComposition)
        HRESULT ( STDMETHODCALLTYPE *CreateSwapChainForComposition )( 
            IDXGIFactory8 * This,
            /* [annotation][in] */ 
            _In_  IUnknown *pDevice,
            /* [annotation][in] */ 
            _In_  const DXGI_SWAP_CHAIN_DESC1 *pDesc,
            /* [annotation][in] */ 
            _In_opt_  IDXGIOutput *pRestrictToOutput,
            /* [annotation][out] */ 
            _COM_Outptr_  IDXGISwapChain1 **ppSwapChain);
        
        DECLSPEC_XFGVIRT(IDXGIFactory3, GetCreationFlags)
        UINT ( STDMETHODCALLTYPE *GetCreationFlags )( 
            IDXGIFactory8 * This);
        
        DECLSPEC_XFGVIRT(IDXGIFactory4, EnumAdapterByLuid)
        HRESULT ( STDMETHODCALLTYPE *EnumAdapterByLuid )( 
            IDXGIFactory8 * This,
            /* [annotation] */ 
            _In_  LUID AdapterLuid,
            /* [annotation] */ 
            _In_  REFIID riid,
            /* [annotation] */ 
            _COM_Outptr_  void **ppvAdapter);
        
        DECLSPEC_XFGVIRT(IDXGIFactory4, EnumWarpAdapter)
        HRESULT ( STDMETHODCALLTYPE *EnumWarpAdapter )( 
            IDXGIFactory8 * This,
            /* [annotation] */ 
            _In_  REFIID riid,
            /* [annotation] */ 
            _COM_Outptr_  void **ppvAdapter);
        
        DECLSPEC_XFGVIRT(IDXGIFactory5, CheckFeatureSupport)
        HRESULT ( STDMETHODCALLTYPE *CheckFeatureSupport )( 
            IDXGIFactory8 * This,
            DXGI_FEATURE Feature,
            /* [annotation] */ 
            _Inout_updates_bytes_(FeatureSupportDataSize)  void *pFeatureSupportData,
            UINT FeatureSupportDataSize);
        
        DECLSPEC_XFGVIRT(IDXGIFactory6, EnumAdapterByGpuPreference)
        HRESULT ( STDMETHODCALLTYPE *EnumAdapterByGpuPreference )( 
            IDXGIFactory8 * This,
            /* [annotation] */ 
            _In_  UINT Adapter,
            /* [annotation] */ 
            _In_  DXGI_GPU_PREFERENCE GpuPreference,
            /* [annotation] */ 
            _In_  REFIID riid,
            /* [annotation] */ 
            _COM_Outptr_  void **ppvAdapter);
        
        DECLSPEC_XFGVIRT(IDXGIFactory7, RegisterAdaptersChangedEvent)
        HRESULT ( STDMETHODCALLTYPE *RegisterAdaptersChangedEvent )( 
            IDXGIFactory8 * This,
            /* [annotation][in] */ 
            _In_  HANDLE hEvent,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwCookie);
        
        DECLSPEC_XFGVIRT(IDXGIFactory7, UnregisterAdaptersChangedEvent)
        HRESULT ( STDMETHODCALLTYPE *UnregisterAdaptersChangedEvent )( 
            IDXGIFactory8 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwCookie);
        
        DECLSPEC_XFGVIRT(IDXGIFactory8, CreateSwapChainForHwnd1)
        HRESULT ( STDMETHODCALLTYPE *CreateSwapChainForHwnd1 )( 
            IDXGIFactory8 * This,
            /* [annotation][in] */ 
            _In_  IUnknown *pDevice,
            /* [annotation][in] */ 
            _In_  HWND hWnd,
            /* [annotation][in] */ 
            _In_  const DXGI_SWAP_CHAIN_DESC2 *pDesc,
            /* [annotation][in] */ 
            _In_opt_  const DXGI_SWAP_CHAIN_FULLSCREEN_DESC *pFullscreenDesc,
            /* [annotation][in] */ 
            _In_opt_  IDXGIOutput *pRestrictToOutput,
            /* [annotation][out] */ 
            _COM_Outptr_  IDXGISwapChain5 **ppSwapChain);
        
        DECLSPEC_XFGVIRT(IDXGIFactory8, CreateSwapChainForCoreWindow1)
        HRESULT ( STDMETHODCALLTYPE *CreateSwapChainForCoreWindow1 )( 
            IDXGIFactory8 * This,
            /* [annotation][in] */ 
            _In_  IUnknown *pDevice,
            /* [annotation][in] */ 
            _In_  IUnknown *pWindow,
            /* [annotation][in] */ 
            _In_  const DXGI_SWAP_CHAIN_DESC2 *pDesc,
            /* [annotation][in] */ 
            _In_opt_  IDXGIOutput *pRestrictToOutput,
            /* [annotation][out] */ 
            _COM_Outptr_  IDXGISwapChain5 **ppSwapChain);
        
        DECLSPEC_XFGVIRT(IDXGIFactory8, CreateSwapChainForComposition1)
        HRESULT ( STDMETHODCALLTYPE *CreateSwapChainForComposition1 )( 
            IDXGIFactory8 * This,
            /* [annotation][in] */ 
            _In_  IUnknown *pDevice,
            /* [annotation][in] */ 
            _In_  const DXGI_SWAP_CHAIN_DESC2 *pDesc,
            /* [annotation][in] */ 
            _In_opt_  IDXGIOutput *pRestrictToOutput,
            /* [annotation][out] */ 
            _COM_Outptr_  IDXGISwapChain5 **ppSwapChain);
        
        END_INTERFACE
    } IDXGIFactory8Vtbl;

    interface IDXGIFactory8
    {
        CONST_VTBL struct IDXGIFactory8Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDXGIFactory8_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDXGIFactory8_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDXGIFactory8_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDXGIFactory8_SetPrivateData(This,Name,DataSize,pData)	\
    ( (This)->lpVtbl -> SetPrivateData(This,Name,DataSize,pData) ) 

#define IDXGIFactory8_SetPrivateDataInterface(This,Name,pUnknown)	\
    ( (This)->lpVtbl -> SetPrivateDataInterface(This,Name,pUnknown) ) 

#define IDXGIFactory8_GetPrivateData(This,Name,pDataSize,pData)	\
    ( (This)->lpVtbl -> GetPrivateData(This,Name,pDataSize,pData) ) 

#define IDXGIFactory8_GetParent(This,riid,ppParent)	\
    ( (This)->lpVtbl -> GetParent(This,riid,ppParent) ) 


#define IDXGIFactory8_EnumAdapters(This,Adapter,ppAdapter)	\
    ( (This)->lpVtbl -> EnumAdapters(This,Adapter,ppAdapter) ) 

#define IDXGIFactory8_MakeWindowAssociation(This,WindowHandle,Flags)	\
    ( (This)->lpVtbl -> MakeWindowAssociation(This,WindowHandle,Flags) ) 

#define IDXGIFactory8_GetWindowAssociation(This,pWindowHandle)	\
    ( (This)->lpVtbl -> GetWindowAssociation(This,pWindowHandle) ) 

#define IDXGIFactory8_CreateSwapChain(This,pDevice,pDesc,ppSwapChain)	\
    ( (This)->lpVtbl -> CreateSwapChain(This,pDevice,pDesc,ppSwapChain) ) 

#define IDXGIFactory8_CreateSoftwareAdapter(This,Module,ppAdapter)	\
    ( (This)->lpVtbl -> CreateSoftwareAdapter(This,Module,ppAdapter) ) 


#define IDXGIFactory8_EnumAdapters1(This,Adapter,ppAdapter)	\
    ( (This)->lpVtbl -> EnumAdapters1(This,Adapter,ppAdapter) ) 

#define IDXGIFactory8_IsCurrent(This)	\
    ( (This)->lpVtbl -> IsCurrent(This) ) 


#define IDXGIFactory8_IsWindowedStereoEnabled(This)	\
    ( (This)->lpVtbl -> IsWindowedStereoEnabled(This) ) 

#define IDXGIFactory8_CreateSwapChainForHwnd(This,pDevice,hWnd,pDesc,pFullscreenDesc,pRestrictToOutput,ppSwapChain)	\
    ( (This)->lpVtbl -> CreateSwapChainForHwnd(This,pDevice,hWnd,pDesc,pFullscreenDesc,pRestrictToOutput,ppSwapChain) ) 

#define IDXGIFactory8_CreateSwapChainForCoreWindow(This,pDevice,pWindow,pDesc,pRestrictToOutput,ppSwapChain)	\
    ( (This)->lpVtbl -> CreateSwapChainForCoreWindow(This,pDevice,pWindow,pDesc,pRestrictToOutput,ppSwapChain) ) 

#define IDXGIFactory8_GetSharedResourceAdapterLuid(This,hResource,pLuid)	\
    ( (This)->lpVtbl -> GetSharedResourceAdapterLuid(This,hResource,pLuid) ) 

#define IDXGIFactory8_RegisterStereoStatusWindow(This,WindowHandle,wMsg,pdwCookie)	\
    ( (This)->lpVtbl -> RegisterStereoStatusWindow(This,WindowHandle,wMsg,pdwCookie) ) 

#define IDXGIFactory8_RegisterStereoStatusEvent(This,hEvent,pdwCookie)	\
    ( (This)->lpVtbl -> RegisterStereoStatusEvent(This,hEvent,pdwCookie) ) 

#define IDXGIFactory8_UnregisterStereoStatus(This,dwCookie)	\
    ( (This)->lpVtbl -> UnregisterStereoStatus(This,dwCookie) ) 

#define IDXGIFactory8_RegisterOcclusionStatusWindow(This,WindowHandle,wMsg,pdwCookie)	\
    ( (This)->lpVtbl -> RegisterOcclusionStatusWindow(This,WindowHandle,wMsg,pdwCookie) ) 

#define IDXGIFactory8_RegisterOcclusionStatusEvent(This,hEvent,pdwCookie)	\
    ( (This)->lpVtbl -> RegisterOcclusionStatusEvent(This,hEvent,pdwCookie) ) 

#define IDXGIFactory8_UnregisterOcclusionStatus(This,dwCookie)	\
    ( (This)->lpVtbl -> UnregisterOcclusionStatus(This,dwCookie) ) 

#define IDXGIFactory8_CreateSwapChainForComposition(This,pDevice,pDesc,pRestrictToOutput,ppSwapChain)	\
    ( (This)->lpVtbl -> CreateSwapChainForComposition(This,pDevice,pDesc,pRestrictToOutput,ppSwapChain) ) 


#define IDXGIFactory8_GetCreationFlags(This)	\
    ( (This)->lpVtbl -> GetCreationFlags(This) ) 


#define IDXGIFactory8_EnumAdapterByLuid(This,AdapterLuid,riid,ppvAdapter)	\
    ( (This)->lpVtbl -> EnumAdapterByLuid(This,AdapterLuid,riid,ppvAdapter) ) 

#define IDXGIFactory8_EnumWarpAdapter(This,riid,ppvAdapter)	\
    ( (This)->lpVtbl -> EnumWarpAdapter(This,riid,ppvAdapter) ) 


#define IDXGIFactory8_CheckFeatureSupport(This,Feature,pFeatureSupportData,FeatureSupportDataSize)	\
    ( (This)->lpVtbl -> CheckFeatureSupport(This,Feature,pFeatureSupportData,FeatureSupportDataSize) ) 


#define IDXGIFactory8_EnumAdapterByGpuPreference(This,Adapter,GpuPreference,riid,ppvAdapter)	\
    ( (This)->lpVtbl -> EnumAdapterByGpuPreference(This,Adapter,GpuPreference,riid,ppvAdapter) ) 


#define IDXGIFactory8_RegisterAdaptersChangedEvent(This,hEvent,pdwCookie)	\
    ( (This)->lpVtbl -> RegisterAdaptersChangedEvent(This,hEvent,pdwCookie) ) 

#define IDXGIFactory8_UnregisterAdaptersChangedEvent(This,dwCookie)	\
    ( (This)->lpVtbl -> UnregisterAdaptersChangedEvent(This,dwCookie) ) 


#define IDXGIFactory8_CreateSwapChainForHwnd1(This,pDevice,hWnd,pDesc,pFullscreenDesc,pRestrictToOutput,ppSwapChain)	\
    ( (This)->lpVtbl -> CreateSwapChainForHwnd1(This,pDevice,hWnd,pDesc,pFullscreenDesc,pRestrictToOutput,ppSwapChain) ) 

#define IDXGIFactory8_CreateSwapChainForCoreWindow1(This,pDevice,pWindow,pDesc,pRestrictToOutput,ppSwapChain)	\
    ( (This)->lpVtbl -> CreateSwapChainForCoreWindow1(This,pDevice,pWindow,pDesc,pRestrictToOutput,ppSwapChain) ) 

#define IDXGIFactory8_CreateSwapChainForComposition1(This,pDevice,pDesc,pRestrictToOutput,ppSwapChain)	\
    ( (This)->lpVtbl -> CreateSwapChainForComposition1(This,pDevice,pDesc,pRestrictToOutput,ppSwapChain) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDXGIFactory8_INTERFACE_DEFINED__ */


#ifndef __IDXGIFactoryMedia2_INTERFACE_DEFINED__
#define __IDXGIFactoryMedia2_INTERFACE_DEFINED__

/* interface IDXGIFactoryMedia2 */
/* [unique][local][uuid][object] */ 


EXTERN_C const IID IID_IDXGIFactoryMedia2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("98ec0b90-2b18-42a6-9fcf-43b46f654022")
    IDXGIFactoryMedia2 : public IDXGIFactoryMedia
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CreateSwapChainForCompositionSurfaceHandle1( 
            /* [annotation][in] */ 
            _In_  IUnknown *pDevice,
            /* [annotation][in] */ 
            _In_opt_  HANDLE hSurface,
            /* [annotation][in] */ 
            _In_  const DXGI_SWAP_CHAIN_DESC2 *pDesc,
            /* [annotation][in] */ 
            _In_opt_  IDXGIOutput *pRestrictToOutput,
            /* [annotation][out] */ 
            _COM_Outptr_  IDXGISwapChain5 **ppSwapChain) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IDXGIFactoryMedia2Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDXGIFactoryMedia2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDXGIFactoryMedia2 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDXGIFactoryMedia2 * This);
        
        DECLSPEC_XFGVIRT(IDXGIFactoryMedia, CreateSwapChainForCompositionSurfaceHandle)
        HRESULT ( STDMETHODCALLTYPE *CreateSwapChainForCompositionSurfaceHandle )( 
            IDXGIFactoryMedia2 * This,
            /* [annotation][in] */ 
            _In_  IUnknown *pDevice,
            /* [annotation][in] */ 
            _In_opt_  HANDLE hSurface,
            /* [annotation][in] */ 
            _In_  const DXGI_SWAP_CHAIN_DESC1 *pDesc,
            /* [annotation][in] */ 
            _In_opt_  IDXGIOutput *pRestrictToOutput,
            /* [annotation][out] */ 
            _COM_Outptr_  IDXGISwapChain1 **ppSwapChain);
        
        DECLSPEC_XFGVIRT(IDXGIFactoryMedia, CreateDecodeSwapChainForCompositionSurfaceHandle)
        HRESULT ( STDMETHODCALLTYPE *CreateDecodeSwapChainForCompositionSurfaceHandle )( 
            IDXGIFactoryMedia2 * This,
            /* [annotation][in] */ 
            _In_  IUnknown *pDevice,
            /* [annotation][in] */ 
            _In_opt_  HANDLE hSurface,
            /* [annotation][in] */ 
            _In_  DXGI_DECODE_SWAP_CHAIN_DESC *pDesc,
            /* [annotation][in] */ 
            _In_  IDXGIResource *pYuvDecodeBuffers,
            /* [annotation][in] */ 
            _In_opt_  IDXGIOutput *pRestrictToOutput,
            /* [annotation][out] */ 
            _COM_Outptr_  IDXGIDecodeSwapChain **ppSwapChain);
        
        DECLSPEC_XFGVIRT(IDXGIFactoryMedia2, CreateSwapChainForCompositionSurfaceHandle1)
        HRESULT ( STDMETHODCALLTYPE *CreateSwapChainForCompositionSurfaceHandle1 )( 
            IDXGIFactoryMedia2 * This,
            /* [annotation][in] */ 
            _In_  IUnknown *pDevice,
            /* [annotation][in] */ 
            _In_opt_  HANDLE hSurface,
            /* [annotation][in] */ 
            _In_  const DXGI_SWAP_CHAIN_DESC2 *pDesc,
            /* [annotation][in] */ 
            _In_opt_  IDXGIOutput *pRestrictToOutput,
            /* [annotation][out] */ 
            _COM_Outptr_  IDXGISwapChain5 **ppSwapChain);
        
        END_INTERFACE
    } IDXGIFactoryMedia2Vtbl;

    interface IDXGIFactoryMedia2
    {
        CONST_VTBL struct IDXGIFactoryMedia2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDXGIFactoryMedia2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDXGIFactoryMedia2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDXGIFactoryMedia2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDXGIFactoryMedia2_CreateSwapChainForCompositionSurfaceHandle(This,pDevice,hSurface,pDesc,pRestrictToOutput,ppSwapChain)	\
    ( (This)->lpVtbl -> CreateSwapChainForCompositionSurfaceHandle(This,pDevice,hSurface,pDesc,pRestrictToOutput,ppSwapChain) ) 

#define IDXGIFactoryMedia2_CreateDecodeSwapChainForCompositionSurfaceHandle(This,pDevice,hSurface,pDesc,pYuvDecodeBuffers,pRestrictToOutput,ppSwapChain)	\
    ( (This)->lpVtbl -> CreateDecodeSwapChainForCompositionSurfaceHandle(This,pDevice,hSurface,pDesc,pYuvDecodeBuffers,pRestrictToOutput,ppSwapChain) ) 


#define IDXGIFactoryMedia2_CreateSwapChainForCompositionSurfaceHandle1(This,pDevice,hSurface,pDesc,pRestrictToOutput,ppSwapChain)	\
    ( (This)->lpVtbl -> CreateSwapChainForCompositionSurfaceHandle1(This,pDevice,hSurface,pDesc,pRestrictToOutput,ppSwapChain) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDXGIFactoryMedia2_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_dxgi1_7_0000_0004 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_GAMES) */
#pragma endregion
DEFINE_GUID(IID_IDXGIAdapter5,0x9464643c,0xc95b,0x4674,0x8a,0x7d,0xee,0x05,0x48,0xe8,0xc0,0x22);
DEFINE_GUID(IID_IDXGISwapChain5,0x9086bf22,0x9338,0x43bb,0x87,0xce,0x77,0x90,0xb6,0x43,0x8a,0x7f);
DEFINE_GUID(IID_IDXGIFactory8,0x693c45c1,0x39a7,0x4c1f,0xbd,0xd3,0xd9,0xa3,0x22,0x9b,0x83,0x21);
DEFINE_GUID(IID_IDXGIFactoryMedia2,0x98ec0b90,0x2b18,0x42a6,0x9f,0xcf,0x43,0xb4,0x6f,0x65,0x40,0x22);


extern RPC_IF_HANDLE __MIDL_itf_dxgi1_7_0000_0004_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_dxgi1_7_0000_0004_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


