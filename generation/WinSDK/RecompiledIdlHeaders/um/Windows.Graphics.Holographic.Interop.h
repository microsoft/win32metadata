

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

#ifndef __windows2Egraphics2Eholographic2Einterop_h__
#define __windows2Egraphics2Eholographic2Einterop_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IHolographicCameraInterop_FWD_DEFINED__
#define __IHolographicCameraInterop_FWD_DEFINED__
typedef interface IHolographicCameraInterop IHolographicCameraInterop;

#endif 	/* __IHolographicCameraInterop_FWD_DEFINED__ */


#ifndef __IHolographicCameraRenderingParametersInterop_FWD_DEFINED__
#define __IHolographicCameraRenderingParametersInterop_FWD_DEFINED__
typedef interface IHolographicCameraRenderingParametersInterop IHolographicCameraRenderingParametersInterop;

#endif 	/* __IHolographicCameraRenderingParametersInterop_FWD_DEFINED__ */


#ifndef __IHolographicQuadLayerInterop_FWD_DEFINED__
#define __IHolographicQuadLayerInterop_FWD_DEFINED__
typedef interface IHolographicQuadLayerInterop IHolographicQuadLayerInterop;

#endif 	/* __IHolographicQuadLayerInterop_FWD_DEFINED__ */


#ifndef __IHolographicQuadLayerUpdateParametersInterop_FWD_DEFINED__
#define __IHolographicQuadLayerUpdateParametersInterop_FWD_DEFINED__
typedef interface IHolographicQuadLayerUpdateParametersInterop IHolographicQuadLayerUpdateParametersInterop;

#endif 	/* __IHolographicQuadLayerUpdateParametersInterop_FWD_DEFINED__ */


/* header files for imported files */
#include "inspectable.h"
#include "d3d12.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_windows2Egraphics2Eholographic2Einterop_0000_0000 */
/* [local] */ 

#pragma warning(push)
#pragma warning(disable:4668) 
#pragma warning(disable:4001) 
#pragma once
#pragma warning(pop)
#include <winapifamily.h>
#if (NTDDI_VERSION >= NTDDI_WIN10_RS2)
#pragma region Modern Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP)


extern RPC_IF_HANDLE __MIDL_itf_windows2Egraphics2Eholographic2Einterop_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_windows2Egraphics2Eholographic2Einterop_0000_0000_v0_0_s_ifspec;

#ifndef __IHolographicCameraInterop_INTERFACE_DEFINED__
#define __IHolographicCameraInterop_INTERFACE_DEFINED__

/* interface IHolographicCameraInterop */
/* [object][uuid] */ 


EXTERN_C const IID IID_IHolographicCameraInterop;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7cc1f9c5-6d02-41fa-9500-e1809eb48eec")
    IHolographicCameraInterop : public IInspectable
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CreateDirect3D12BackBufferResource( 
            /* [annotation][in] */ 
            _In_  ID3D12Device *pDevice,
            /* [annotation][in] */ 
            _In_  D3D12_RESOURCE_DESC *pTexture2DDesc,
            /* [annotation][retval][out] */ 
            _Out_retval_  ID3D12Resource **ppCreatedTexture2DResource) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateDirect3D12HardwareProtectedBackBufferResource( 
            /* [annotation][in] */ 
            _In_  ID3D12Device *pDevice,
            /* [annotation][in] */ 
            _In_  D3D12_RESOURCE_DESC *pTexture2DDesc,
            /* [annotation][in] */ 
            _In_  ID3D12ProtectedResourceSession *pProtectedResourceSession,
            /* [annotation][retval][out] */ 
            _Out_retval_  ID3D12Resource **ppCreatedTexture2DResource) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AcquireDirect3D12BufferResource( 
            /* [annotation][in] */ 
            _In_  ID3D12Resource *pResourceToAcquire,
            /* [annotation][in] */ 
            _In_  ID3D12CommandQueue *pCommandQueue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AcquireDirect3D12BufferResourceWithTimeout( 
            /* [annotation][in] */ 
            _In_  ID3D12Resource *pResourceToAcquire,
            /* [annotation][in] */ 
            _In_  ID3D12CommandQueue *pCommandQueue,
            /* [annotation][in] */ 
            _In_  UINT64 duration) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UnacquireDirect3D12BufferResource( 
            /* [annotation][in] */ 
            _In_  ID3D12Resource *pResourceToUnacquire) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IHolographicCameraInteropVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IHolographicCameraInterop * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IHolographicCameraInterop * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IHolographicCameraInterop * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetIids )( 
            __RPC__in IHolographicCameraInterop * This,
            /* [out] */ __RPC__out ULONG *iidCount,
            /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids);
        
        HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )( 
            __RPC__in IHolographicCameraInterop * This,
            /* [out] */ __RPC__deref_out_opt HSTRING *className);
        
        HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )( 
            __RPC__in IHolographicCameraInterop * This,
            /* [out] */ __RPC__out TrustLevel *trustLevel);
        
        HRESULT ( STDMETHODCALLTYPE *CreateDirect3D12BackBufferResource )( 
            __RPC__in IHolographicCameraInterop * This,
            /* [annotation][in] */ 
            _In_  ID3D12Device *pDevice,
            /* [annotation][in] */ 
            _In_  D3D12_RESOURCE_DESC *pTexture2DDesc,
            /* [annotation][retval][out] */ 
            _Out_retval_  ID3D12Resource **ppCreatedTexture2DResource);
        
        HRESULT ( STDMETHODCALLTYPE *CreateDirect3D12HardwareProtectedBackBufferResource )( 
            __RPC__in IHolographicCameraInterop * This,
            /* [annotation][in] */ 
            _In_  ID3D12Device *pDevice,
            /* [annotation][in] */ 
            _In_  D3D12_RESOURCE_DESC *pTexture2DDesc,
            /* [annotation][in] */ 
            _In_  ID3D12ProtectedResourceSession *pProtectedResourceSession,
            /* [annotation][retval][out] */ 
            _Out_retval_  ID3D12Resource **ppCreatedTexture2DResource);
        
        HRESULT ( STDMETHODCALLTYPE *AcquireDirect3D12BufferResource )( 
            __RPC__in IHolographicCameraInterop * This,
            /* [annotation][in] */ 
            _In_  ID3D12Resource *pResourceToAcquire,
            /* [annotation][in] */ 
            _In_  ID3D12CommandQueue *pCommandQueue);
        
        HRESULT ( STDMETHODCALLTYPE *AcquireDirect3D12BufferResourceWithTimeout )( 
            __RPC__in IHolographicCameraInterop * This,
            /* [annotation][in] */ 
            _In_  ID3D12Resource *pResourceToAcquire,
            /* [annotation][in] */ 
            _In_  ID3D12CommandQueue *pCommandQueue,
            /* [annotation][in] */ 
            _In_  UINT64 duration);
        
        HRESULT ( STDMETHODCALLTYPE *UnacquireDirect3D12BufferResource )( 
            __RPC__in IHolographicCameraInterop * This,
            /* [annotation][in] */ 
            _In_  ID3D12Resource *pResourceToUnacquire);
        
        END_INTERFACE
    } IHolographicCameraInteropVtbl;

    interface IHolographicCameraInterop
    {
        CONST_VTBL struct IHolographicCameraInteropVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHolographicCameraInterop_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IHolographicCameraInterop_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IHolographicCameraInterop_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IHolographicCameraInterop_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define IHolographicCameraInterop_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define IHolographicCameraInterop_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define IHolographicCameraInterop_CreateDirect3D12BackBufferResource(This,pDevice,pTexture2DDesc,ppCreatedTexture2DResource)	\
    ( (This)->lpVtbl -> CreateDirect3D12BackBufferResource(This,pDevice,pTexture2DDesc,ppCreatedTexture2DResource) ) 

#define IHolographicCameraInterop_CreateDirect3D12HardwareProtectedBackBufferResource(This,pDevice,pTexture2DDesc,pProtectedResourceSession,ppCreatedTexture2DResource)	\
    ( (This)->lpVtbl -> CreateDirect3D12HardwareProtectedBackBufferResource(This,pDevice,pTexture2DDesc,pProtectedResourceSession,ppCreatedTexture2DResource) ) 

#define IHolographicCameraInterop_AcquireDirect3D12BufferResource(This,pResourceToAcquire,pCommandQueue)	\
    ( (This)->lpVtbl -> AcquireDirect3D12BufferResource(This,pResourceToAcquire,pCommandQueue) ) 

#define IHolographicCameraInterop_AcquireDirect3D12BufferResourceWithTimeout(This,pResourceToAcquire,pCommandQueue,duration)	\
    ( (This)->lpVtbl -> AcquireDirect3D12BufferResourceWithTimeout(This,pResourceToAcquire,pCommandQueue,duration) ) 

#define IHolographicCameraInterop_UnacquireDirect3D12BufferResource(This,pResourceToUnacquire)	\
    ( (This)->lpVtbl -> UnacquireDirect3D12BufferResource(This,pResourceToUnacquire) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IHolographicCameraInterop_INTERFACE_DEFINED__ */


#ifndef __IHolographicCameraRenderingParametersInterop_INTERFACE_DEFINED__
#define __IHolographicCameraRenderingParametersInterop_INTERFACE_DEFINED__

/* interface IHolographicCameraRenderingParametersInterop */
/* [object][uuid] */ 


EXTERN_C const IID IID_IHolographicCameraRenderingParametersInterop;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("f75b68d6-d1fd-4707-aafd-fa6f4c0e3bf4")
    IHolographicCameraRenderingParametersInterop : public IInspectable
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CommitDirect3D12Resource( 
            /* [annotation][in] */ 
            _In_  ID3D12Resource *pColorResourceToCommit,
            /* [annotation][in] */ 
            _In_  ID3D12Fence *pColorResourceFence,
            /* [annotation][in] */ 
            _In_  UINT64 colorResourceFenceSignalValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CommitDirect3D12ResourceWithDepthData( 
            /* [annotation][in] */ 
            _In_  ID3D12Resource *pColorResourceToCommit,
            /* [annotation][in] */ 
            _In_  ID3D12Fence *pColorResourceFence,
            /* [annotation][in] */ 
            _In_  UINT64 colorResourceFenceSignalValue,
            /* [annotation][in] */ 
            _In_  ID3D12Resource *pDepthResourceToCommit,
            /* [annotation][in] */ 
            _In_  ID3D12Fence *pDepthResourceFence,
            /* [annotation][in] */ 
            _In_  UINT64 depthResourceFenceSignalValue) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IHolographicCameraRenderingParametersInteropVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IHolographicCameraRenderingParametersInterop * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IHolographicCameraRenderingParametersInterop * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IHolographicCameraRenderingParametersInterop * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetIids )( 
            __RPC__in IHolographicCameraRenderingParametersInterop * This,
            /* [out] */ __RPC__out ULONG *iidCount,
            /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids);
        
        HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )( 
            __RPC__in IHolographicCameraRenderingParametersInterop * This,
            /* [out] */ __RPC__deref_out_opt HSTRING *className);
        
        HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )( 
            __RPC__in IHolographicCameraRenderingParametersInterop * This,
            /* [out] */ __RPC__out TrustLevel *trustLevel);
        
        HRESULT ( STDMETHODCALLTYPE *CommitDirect3D12Resource )( 
            __RPC__in IHolographicCameraRenderingParametersInterop * This,
            /* [annotation][in] */ 
            _In_  ID3D12Resource *pColorResourceToCommit,
            /* [annotation][in] */ 
            _In_  ID3D12Fence *pColorResourceFence,
            /* [annotation][in] */ 
            _In_  UINT64 colorResourceFenceSignalValue);
        
        HRESULT ( STDMETHODCALLTYPE *CommitDirect3D12ResourceWithDepthData )( 
            __RPC__in IHolographicCameraRenderingParametersInterop * This,
            /* [annotation][in] */ 
            _In_  ID3D12Resource *pColorResourceToCommit,
            /* [annotation][in] */ 
            _In_  ID3D12Fence *pColorResourceFence,
            /* [annotation][in] */ 
            _In_  UINT64 colorResourceFenceSignalValue,
            /* [annotation][in] */ 
            _In_  ID3D12Resource *pDepthResourceToCommit,
            /* [annotation][in] */ 
            _In_  ID3D12Fence *pDepthResourceFence,
            /* [annotation][in] */ 
            _In_  UINT64 depthResourceFenceSignalValue);
        
        END_INTERFACE
    } IHolographicCameraRenderingParametersInteropVtbl;

    interface IHolographicCameraRenderingParametersInterop
    {
        CONST_VTBL struct IHolographicCameraRenderingParametersInteropVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHolographicCameraRenderingParametersInterop_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IHolographicCameraRenderingParametersInterop_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IHolographicCameraRenderingParametersInterop_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IHolographicCameraRenderingParametersInterop_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define IHolographicCameraRenderingParametersInterop_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define IHolographicCameraRenderingParametersInterop_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define IHolographicCameraRenderingParametersInterop_CommitDirect3D12Resource(This,pColorResourceToCommit,pColorResourceFence,colorResourceFenceSignalValue)	\
    ( (This)->lpVtbl -> CommitDirect3D12Resource(This,pColorResourceToCommit,pColorResourceFence,colorResourceFenceSignalValue) ) 

#define IHolographicCameraRenderingParametersInterop_CommitDirect3D12ResourceWithDepthData(This,pColorResourceToCommit,pColorResourceFence,colorResourceFenceSignalValue,pDepthResourceToCommit,pDepthResourceFence,depthResourceFenceSignalValue)	\
    ( (This)->lpVtbl -> CommitDirect3D12ResourceWithDepthData(This,pColorResourceToCommit,pColorResourceFence,colorResourceFenceSignalValue,pDepthResourceToCommit,pDepthResourceFence,depthResourceFenceSignalValue) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IHolographicCameraRenderingParametersInterop_INTERFACE_DEFINED__ */


#ifndef __IHolographicQuadLayerInterop_INTERFACE_DEFINED__
#define __IHolographicQuadLayerInterop_INTERFACE_DEFINED__

/* interface IHolographicQuadLayerInterop */
/* [object][uuid] */ 


EXTERN_C const IID IID_IHolographicQuadLayerInterop;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("cfa688f0-639e-4a47-83d7-6b7f5ebf7fed")
    IHolographicQuadLayerInterop : public IInspectable
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CreateDirect3D12ContentBufferResource( 
            /* [annotation][in] */ 
            _In_  ID3D12Device *pDevice,
            /* [annotation][in] */ 
            _In_  D3D12_RESOURCE_DESC *pTexture2DDesc,
            /* [annotation][retval][out] */ 
            _Out_retval_  ID3D12Resource **ppTexture2DResource) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateDirect3D12HardwareProtectedContentBufferResource( 
            /* [annotation][in] */ 
            _In_  ID3D12Device *pDevice,
            /* [annotation][in] */ 
            _In_  D3D12_RESOURCE_DESC *pTexture2DDesc,
            /* [annotation][in] */ 
            _In_  ID3D12ProtectedResourceSession *pProtectedResourceSession,
            /* [annotation][retval][out] */ 
            _Out_retval_  ID3D12Resource **ppCreatedTexture2DResource) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AcquireDirect3D12BufferResource( 
            /* [annotation][in] */ 
            _In_  ID3D12Resource *pResourceToAcquire,
            /* [annotation][in] */ 
            _In_  ID3D12CommandQueue *pCommandQueue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AcquireDirect3D12BufferResourceWithTimeout( 
            /* [annotation][in] */ 
            _In_  ID3D12Resource *pResourceToAcquire,
            /* [annotation][in] */ 
            _In_  ID3D12CommandQueue *pCommandQueue,
            /* [annotation][in] */ 
            _In_  UINT64 duration) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UnacquireDirect3D12BufferResource( 
            /* [annotation][in] */ 
            _In_  ID3D12Resource *pResourceToUnacquire) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IHolographicQuadLayerInteropVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IHolographicQuadLayerInterop * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IHolographicQuadLayerInterop * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IHolographicQuadLayerInterop * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetIids )( 
            __RPC__in IHolographicQuadLayerInterop * This,
            /* [out] */ __RPC__out ULONG *iidCount,
            /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids);
        
        HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )( 
            __RPC__in IHolographicQuadLayerInterop * This,
            /* [out] */ __RPC__deref_out_opt HSTRING *className);
        
        HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )( 
            __RPC__in IHolographicQuadLayerInterop * This,
            /* [out] */ __RPC__out TrustLevel *trustLevel);
        
        HRESULT ( STDMETHODCALLTYPE *CreateDirect3D12ContentBufferResource )( 
            __RPC__in IHolographicQuadLayerInterop * This,
            /* [annotation][in] */ 
            _In_  ID3D12Device *pDevice,
            /* [annotation][in] */ 
            _In_  D3D12_RESOURCE_DESC *pTexture2DDesc,
            /* [annotation][retval][out] */ 
            _Out_retval_  ID3D12Resource **ppTexture2DResource);
        
        HRESULT ( STDMETHODCALLTYPE *CreateDirect3D12HardwareProtectedContentBufferResource )( 
            __RPC__in IHolographicQuadLayerInterop * This,
            /* [annotation][in] */ 
            _In_  ID3D12Device *pDevice,
            /* [annotation][in] */ 
            _In_  D3D12_RESOURCE_DESC *pTexture2DDesc,
            /* [annotation][in] */ 
            _In_  ID3D12ProtectedResourceSession *pProtectedResourceSession,
            /* [annotation][retval][out] */ 
            _Out_retval_  ID3D12Resource **ppCreatedTexture2DResource);
        
        HRESULT ( STDMETHODCALLTYPE *AcquireDirect3D12BufferResource )( 
            __RPC__in IHolographicQuadLayerInterop * This,
            /* [annotation][in] */ 
            _In_  ID3D12Resource *pResourceToAcquire,
            /* [annotation][in] */ 
            _In_  ID3D12CommandQueue *pCommandQueue);
        
        HRESULT ( STDMETHODCALLTYPE *AcquireDirect3D12BufferResourceWithTimeout )( 
            __RPC__in IHolographicQuadLayerInterop * This,
            /* [annotation][in] */ 
            _In_  ID3D12Resource *pResourceToAcquire,
            /* [annotation][in] */ 
            _In_  ID3D12CommandQueue *pCommandQueue,
            /* [annotation][in] */ 
            _In_  UINT64 duration);
        
        HRESULT ( STDMETHODCALLTYPE *UnacquireDirect3D12BufferResource )( 
            __RPC__in IHolographicQuadLayerInterop * This,
            /* [annotation][in] */ 
            _In_  ID3D12Resource *pResourceToUnacquire);
        
        END_INTERFACE
    } IHolographicQuadLayerInteropVtbl;

    interface IHolographicQuadLayerInterop
    {
        CONST_VTBL struct IHolographicQuadLayerInteropVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHolographicQuadLayerInterop_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IHolographicQuadLayerInterop_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IHolographicQuadLayerInterop_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IHolographicQuadLayerInterop_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define IHolographicQuadLayerInterop_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define IHolographicQuadLayerInterop_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define IHolographicQuadLayerInterop_CreateDirect3D12ContentBufferResource(This,pDevice,pTexture2DDesc,ppTexture2DResource)	\
    ( (This)->lpVtbl -> CreateDirect3D12ContentBufferResource(This,pDevice,pTexture2DDesc,ppTexture2DResource) ) 

#define IHolographicQuadLayerInterop_CreateDirect3D12HardwareProtectedContentBufferResource(This,pDevice,pTexture2DDesc,pProtectedResourceSession,ppCreatedTexture2DResource)	\
    ( (This)->lpVtbl -> CreateDirect3D12HardwareProtectedContentBufferResource(This,pDevice,pTexture2DDesc,pProtectedResourceSession,ppCreatedTexture2DResource) ) 

#define IHolographicQuadLayerInterop_AcquireDirect3D12BufferResource(This,pResourceToAcquire,pCommandQueue)	\
    ( (This)->lpVtbl -> AcquireDirect3D12BufferResource(This,pResourceToAcquire,pCommandQueue) ) 

#define IHolographicQuadLayerInterop_AcquireDirect3D12BufferResourceWithTimeout(This,pResourceToAcquire,pCommandQueue,duration)	\
    ( (This)->lpVtbl -> AcquireDirect3D12BufferResourceWithTimeout(This,pResourceToAcquire,pCommandQueue,duration) ) 

#define IHolographicQuadLayerInterop_UnacquireDirect3D12BufferResource(This,pResourceToUnacquire)	\
    ( (This)->lpVtbl -> UnacquireDirect3D12BufferResource(This,pResourceToUnacquire) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IHolographicQuadLayerInterop_INTERFACE_DEFINED__ */


#ifndef __IHolographicQuadLayerUpdateParametersInterop_INTERFACE_DEFINED__
#define __IHolographicQuadLayerUpdateParametersInterop_INTERFACE_DEFINED__

/* interface IHolographicQuadLayerUpdateParametersInterop */
/* [object][uuid] */ 


EXTERN_C const IID IID_IHolographicQuadLayerUpdateParametersInterop;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("e5f549cd-c909-444f-8809-7cc18a9c8920")
    IHolographicQuadLayerUpdateParametersInterop : public IInspectable
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CommitDirect3D12Resource( 
            /* [annotation][in] */ 
            _In_  ID3D12Resource *pColorResourceToCommit,
            /* [annotation][in] */ 
            _In_  ID3D12Fence *pColorResourceFence,
            /* [annotation][in] */ 
            _In_  UINT64 colorResourceFenceSignalValue) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IHolographicQuadLayerUpdateParametersInteropVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IHolographicQuadLayerUpdateParametersInterop * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IHolographicQuadLayerUpdateParametersInterop * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IHolographicQuadLayerUpdateParametersInterop * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetIids )( 
            __RPC__in IHolographicQuadLayerUpdateParametersInterop * This,
            /* [out] */ __RPC__out ULONG *iidCount,
            /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*iidCount) IID **iids);
        
        HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )( 
            __RPC__in IHolographicQuadLayerUpdateParametersInterop * This,
            /* [out] */ __RPC__deref_out_opt HSTRING *className);
        
        HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )( 
            __RPC__in IHolographicQuadLayerUpdateParametersInterop * This,
            /* [out] */ __RPC__out TrustLevel *trustLevel);
        
        HRESULT ( STDMETHODCALLTYPE *CommitDirect3D12Resource )( 
            __RPC__in IHolographicQuadLayerUpdateParametersInterop * This,
            /* [annotation][in] */ 
            _In_  ID3D12Resource *pColorResourceToCommit,
            /* [annotation][in] */ 
            _In_  ID3D12Fence *pColorResourceFence,
            /* [annotation][in] */ 
            _In_  UINT64 colorResourceFenceSignalValue);
        
        END_INTERFACE
    } IHolographicQuadLayerUpdateParametersInteropVtbl;

    interface IHolographicQuadLayerUpdateParametersInterop
    {
        CONST_VTBL struct IHolographicQuadLayerUpdateParametersInteropVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHolographicQuadLayerUpdateParametersInterop_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IHolographicQuadLayerUpdateParametersInterop_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IHolographicQuadLayerUpdateParametersInterop_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IHolographicQuadLayerUpdateParametersInterop_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define IHolographicQuadLayerUpdateParametersInterop_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define IHolographicQuadLayerUpdateParametersInterop_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define IHolographicQuadLayerUpdateParametersInterop_CommitDirect3D12Resource(This,pColorResourceToCommit,pColorResourceFence,colorResourceFenceSignalValue)	\
    ( (This)->lpVtbl -> CommitDirect3D12Resource(This,pColorResourceToCommit,pColorResourceFence,colorResourceFenceSignalValue) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IHolographicQuadLayerUpdateParametersInterop_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_windows2Egraphics2Eholographic2Einterop_0000_0004 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP) */
#pragma endregion
#endif //(NTDDI_VERSION >= NTDDI_WIN10)


extern RPC_IF_HANDLE __MIDL_itf_windows2Egraphics2Eholographic2Einterop_0000_0004_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_windows2Egraphics2Eholographic2Einterop_0000_0004_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


