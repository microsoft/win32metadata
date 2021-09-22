

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

#ifndef __portabledeviceapi_h__
#define __portabledeviceapi_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IPortableDeviceManager_FWD_DEFINED__
#define __IPortableDeviceManager_FWD_DEFINED__
typedef interface IPortableDeviceManager IPortableDeviceManager;

#endif 	/* __IPortableDeviceManager_FWD_DEFINED__ */


#ifndef __IPortableDevice_FWD_DEFINED__
#define __IPortableDevice_FWD_DEFINED__
typedef interface IPortableDevice IPortableDevice;

#endif 	/* __IPortableDevice_FWD_DEFINED__ */


#ifndef __IPortableDeviceContent_FWD_DEFINED__
#define __IPortableDeviceContent_FWD_DEFINED__
typedef interface IPortableDeviceContent IPortableDeviceContent;

#endif 	/* __IPortableDeviceContent_FWD_DEFINED__ */


#ifndef __IPortableDeviceContent2_FWD_DEFINED__
#define __IPortableDeviceContent2_FWD_DEFINED__
typedef interface IPortableDeviceContent2 IPortableDeviceContent2;

#endif 	/* __IPortableDeviceContent2_FWD_DEFINED__ */


#ifndef __IEnumPortableDeviceObjectIDs_FWD_DEFINED__
#define __IEnumPortableDeviceObjectIDs_FWD_DEFINED__
typedef interface IEnumPortableDeviceObjectIDs IEnumPortableDeviceObjectIDs;

#endif 	/* __IEnumPortableDeviceObjectIDs_FWD_DEFINED__ */


#ifndef __IPortableDeviceProperties_FWD_DEFINED__
#define __IPortableDeviceProperties_FWD_DEFINED__
typedef interface IPortableDeviceProperties IPortableDeviceProperties;

#endif 	/* __IPortableDeviceProperties_FWD_DEFINED__ */


#ifndef __IPortableDeviceResources_FWD_DEFINED__
#define __IPortableDeviceResources_FWD_DEFINED__
typedef interface IPortableDeviceResources IPortableDeviceResources;

#endif 	/* __IPortableDeviceResources_FWD_DEFINED__ */


#ifndef __IPortableDeviceCapabilities_FWD_DEFINED__
#define __IPortableDeviceCapabilities_FWD_DEFINED__
typedef interface IPortableDeviceCapabilities IPortableDeviceCapabilities;

#endif 	/* __IPortableDeviceCapabilities_FWD_DEFINED__ */


#ifndef __IPortableDeviceEventCallback_FWD_DEFINED__
#define __IPortableDeviceEventCallback_FWD_DEFINED__
typedef interface IPortableDeviceEventCallback IPortableDeviceEventCallback;

#endif 	/* __IPortableDeviceEventCallback_FWD_DEFINED__ */


#ifndef __IPortableDeviceDataStream_FWD_DEFINED__
#define __IPortableDeviceDataStream_FWD_DEFINED__
typedef interface IPortableDeviceDataStream IPortableDeviceDataStream;

#endif 	/* __IPortableDeviceDataStream_FWD_DEFINED__ */


#ifndef __IPortableDeviceUnitsStream_FWD_DEFINED__
#define __IPortableDeviceUnitsStream_FWD_DEFINED__
typedef interface IPortableDeviceUnitsStream IPortableDeviceUnitsStream;

#endif 	/* __IPortableDeviceUnitsStream_FWD_DEFINED__ */


#ifndef __IPortableDevicePropertiesBulk_FWD_DEFINED__
#define __IPortableDevicePropertiesBulk_FWD_DEFINED__
typedef interface IPortableDevicePropertiesBulk IPortableDevicePropertiesBulk;

#endif 	/* __IPortableDevicePropertiesBulk_FWD_DEFINED__ */


#ifndef __IPortableDevicePropertiesBulkCallback_FWD_DEFINED__
#define __IPortableDevicePropertiesBulkCallback_FWD_DEFINED__
typedef interface IPortableDevicePropertiesBulkCallback IPortableDevicePropertiesBulkCallback;

#endif 	/* __IPortableDevicePropertiesBulkCallback_FWD_DEFINED__ */


#ifndef __IPortableDeviceServiceManager_FWD_DEFINED__
#define __IPortableDeviceServiceManager_FWD_DEFINED__
typedef interface IPortableDeviceServiceManager IPortableDeviceServiceManager;

#endif 	/* __IPortableDeviceServiceManager_FWD_DEFINED__ */


#ifndef __IPortableDeviceService_FWD_DEFINED__
#define __IPortableDeviceService_FWD_DEFINED__
typedef interface IPortableDeviceService IPortableDeviceService;

#endif 	/* __IPortableDeviceService_FWD_DEFINED__ */


#ifndef __IPortableDeviceServiceCapabilities_FWD_DEFINED__
#define __IPortableDeviceServiceCapabilities_FWD_DEFINED__
typedef interface IPortableDeviceServiceCapabilities IPortableDeviceServiceCapabilities;

#endif 	/* __IPortableDeviceServiceCapabilities_FWD_DEFINED__ */


#ifndef __IPortableDeviceServiceMethods_FWD_DEFINED__
#define __IPortableDeviceServiceMethods_FWD_DEFINED__
typedef interface IPortableDeviceServiceMethods IPortableDeviceServiceMethods;

#endif 	/* __IPortableDeviceServiceMethods_FWD_DEFINED__ */


#ifndef __IPortableDeviceServiceMethodCallback_FWD_DEFINED__
#define __IPortableDeviceServiceMethodCallback_FWD_DEFINED__
typedef interface IPortableDeviceServiceMethodCallback IPortableDeviceServiceMethodCallback;

#endif 	/* __IPortableDeviceServiceMethodCallback_FWD_DEFINED__ */


#ifndef __IPortableDeviceServiceActivation_FWD_DEFINED__
#define __IPortableDeviceServiceActivation_FWD_DEFINED__
typedef interface IPortableDeviceServiceActivation IPortableDeviceServiceActivation;

#endif 	/* __IPortableDeviceServiceActivation_FWD_DEFINED__ */


#ifndef __IPortableDeviceServiceOpenCallback_FWD_DEFINED__
#define __IPortableDeviceServiceOpenCallback_FWD_DEFINED__
typedef interface IPortableDeviceServiceOpenCallback IPortableDeviceServiceOpenCallback;

#endif 	/* __IPortableDeviceServiceOpenCallback_FWD_DEFINED__ */


#ifndef __IPortableDeviceDispatchFactory_FWD_DEFINED__
#define __IPortableDeviceDispatchFactory_FWD_DEFINED__
typedef interface IPortableDeviceDispatchFactory IPortableDeviceDispatchFactory;

#endif 	/* __IPortableDeviceDispatchFactory_FWD_DEFINED__ */


#ifndef __IPortableDeviceWebControl_FWD_DEFINED__
#define __IPortableDeviceWebControl_FWD_DEFINED__
typedef interface IPortableDeviceWebControl IPortableDeviceWebControl;

#endif 	/* __IPortableDeviceWebControl_FWD_DEFINED__ */


#ifndef __PortableDevice_FWD_DEFINED__
#define __PortableDevice_FWD_DEFINED__

#ifdef __cplusplus
typedef class PortableDevice PortableDevice;
#else
typedef struct PortableDevice PortableDevice;
#endif /* __cplusplus */

#endif 	/* __PortableDevice_FWD_DEFINED__ */


#ifndef __PortableDeviceManager_FWD_DEFINED__
#define __PortableDeviceManager_FWD_DEFINED__

#ifdef __cplusplus
typedef class PortableDeviceManager PortableDeviceManager;
#else
typedef struct PortableDeviceManager PortableDeviceManager;
#endif /* __cplusplus */

#endif 	/* __PortableDeviceManager_FWD_DEFINED__ */


#ifndef __PortableDeviceService_FWD_DEFINED__
#define __PortableDeviceService_FWD_DEFINED__

#ifdef __cplusplus
typedef class PortableDeviceService PortableDeviceService;
#else
typedef struct PortableDeviceService PortableDeviceService;
#endif /* __cplusplus */

#endif 	/* __PortableDeviceService_FWD_DEFINED__ */


#ifndef __PortableDeviceDispatchFactory_FWD_DEFINED__
#define __PortableDeviceDispatchFactory_FWD_DEFINED__

#ifdef __cplusplus
typedef class PortableDeviceDispatchFactory PortableDeviceDispatchFactory;
#else
typedef struct PortableDeviceDispatchFactory PortableDeviceDispatchFactory;
#endif /* __cplusplus */

#endif 	/* __PortableDeviceDispatchFactory_FWD_DEFINED__ */


#ifndef __PortableDeviceFTM_FWD_DEFINED__
#define __PortableDeviceFTM_FWD_DEFINED__

#ifdef __cplusplus
typedef class PortableDeviceFTM PortableDeviceFTM;
#else
typedef struct PortableDeviceFTM PortableDeviceFTM;
#endif /* __cplusplus */

#endif 	/* __PortableDeviceFTM_FWD_DEFINED__ */


#ifndef __PortableDeviceServiceFTM_FWD_DEFINED__
#define __PortableDeviceServiceFTM_FWD_DEFINED__

#ifdef __cplusplus
typedef class PortableDeviceServiceFTM PortableDeviceServiceFTM;
#else
typedef struct PortableDeviceServiceFTM PortableDeviceServiceFTM;
#endif /* __cplusplus */

#endif 	/* __PortableDeviceServiceFTM_FWD_DEFINED__ */


#ifndef __PortableDeviceWebControl_FWD_DEFINED__
#define __PortableDeviceWebControl_FWD_DEFINED__

#ifdef __cplusplus
typedef class PortableDeviceWebControl PortableDeviceWebControl;
#else
typedef struct PortableDeviceWebControl PortableDeviceWebControl;
#endif /* __cplusplus */

#endif 	/* __PortableDeviceWebControl_FWD_DEFINED__ */


/* header files for imported files */
#include "propidl.h"
#include "PortableDeviceTypes.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_portabledeviceapi_0000_0000 */
/* [local] */ 

#include <winapifamily.h>
#if (_WIN32_WINNT >= 0x0501) // XP and later
#pragma region Application Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP)






















extern RPC_IF_HANDLE __MIDL_itf_portabledeviceapi_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_portabledeviceapi_0000_0000_v0_0_s_ifspec;

#ifndef __IPortableDeviceManager_INTERFACE_DEFINED__
#define __IPortableDeviceManager_INTERFACE_DEFINED__

/* interface IPortableDeviceManager */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IPortableDeviceManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("a1567595-4c2f-4574-a6fa-ecef917b9a40")
    IPortableDeviceManager : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetDevices( 
            /* [annotation][unique][out][in] */ 
            _Inout_  LPWSTR *pPnPDeviceIDs,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcPnPDeviceIDs) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RefreshDeviceList( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDeviceFriendlyName( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPnPDeviceID,
            /* [annotation][unique][out][in] */ 
            _Inout_  WCHAR *pDeviceFriendlyName,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcchDeviceFriendlyName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDeviceDescription( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPnPDeviceID,
            /* [annotation][unique][out][in] */ 
            _Inout_  WCHAR *pDeviceDescription,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcchDeviceDescription) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDeviceManufacturer( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPnPDeviceID,
            /* [annotation][unique][out][in] */ 
            _Inout_  WCHAR *pDeviceManufacturer,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcchDeviceManufacturer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDeviceProperty( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPnPDeviceID,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszDevicePropertyName,
            /* [annotation][unique][out][in] */ 
            _Inout_  BYTE *pData,
            /* [annotation][unique][out][in] */ 
            _Inout_  DWORD *pcbData,
            /* [annotation][unique][out][in] */ 
            _Inout_  DWORD *pdwType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPrivateDevices( 
            /* [annotation][unique][out][in] */ 
            _Inout_  LPWSTR *pPnPDeviceIDs,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcPnPDeviceIDs) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IPortableDeviceManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IPortableDeviceManager * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IPortableDeviceManager * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IPortableDeviceManager * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetDevices )( 
            __RPC__in IPortableDeviceManager * This,
            /* [annotation][unique][out][in] */ 
            _Inout_  LPWSTR *pPnPDeviceIDs,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcPnPDeviceIDs);
        
        HRESULT ( STDMETHODCALLTYPE *RefreshDeviceList )( 
            __RPC__in IPortableDeviceManager * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetDeviceFriendlyName )( 
            __RPC__in IPortableDeviceManager * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPnPDeviceID,
            /* [annotation][unique][out][in] */ 
            _Inout_  WCHAR *pDeviceFriendlyName,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcchDeviceFriendlyName);
        
        HRESULT ( STDMETHODCALLTYPE *GetDeviceDescription )( 
            __RPC__in IPortableDeviceManager * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPnPDeviceID,
            /* [annotation][unique][out][in] */ 
            _Inout_  WCHAR *pDeviceDescription,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcchDeviceDescription);
        
        HRESULT ( STDMETHODCALLTYPE *GetDeviceManufacturer )( 
            __RPC__in IPortableDeviceManager * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPnPDeviceID,
            /* [annotation][unique][out][in] */ 
            _Inout_  WCHAR *pDeviceManufacturer,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcchDeviceManufacturer);
        
        HRESULT ( STDMETHODCALLTYPE *GetDeviceProperty )( 
            __RPC__in IPortableDeviceManager * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPnPDeviceID,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszDevicePropertyName,
            /* [annotation][unique][out][in] */ 
            _Inout_  BYTE *pData,
            /* [annotation][unique][out][in] */ 
            _Inout_  DWORD *pcbData,
            /* [annotation][unique][out][in] */ 
            _Inout_  DWORD *pdwType);
        
        HRESULT ( STDMETHODCALLTYPE *GetPrivateDevices )( 
            __RPC__in IPortableDeviceManager * This,
            /* [annotation][unique][out][in] */ 
            _Inout_  LPWSTR *pPnPDeviceIDs,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcPnPDeviceIDs);
        
        END_INTERFACE
    } IPortableDeviceManagerVtbl;

    interface IPortableDeviceManager
    {
        CONST_VTBL struct IPortableDeviceManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPortableDeviceManager_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPortableDeviceManager_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPortableDeviceManager_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPortableDeviceManager_GetDevices(This,pPnPDeviceIDs,pcPnPDeviceIDs)	\
    ( (This)->lpVtbl -> GetDevices(This,pPnPDeviceIDs,pcPnPDeviceIDs) ) 

#define IPortableDeviceManager_RefreshDeviceList(This)	\
    ( (This)->lpVtbl -> RefreshDeviceList(This) ) 

#define IPortableDeviceManager_GetDeviceFriendlyName(This,pszPnPDeviceID,pDeviceFriendlyName,pcchDeviceFriendlyName)	\
    ( (This)->lpVtbl -> GetDeviceFriendlyName(This,pszPnPDeviceID,pDeviceFriendlyName,pcchDeviceFriendlyName) ) 

#define IPortableDeviceManager_GetDeviceDescription(This,pszPnPDeviceID,pDeviceDescription,pcchDeviceDescription)	\
    ( (This)->lpVtbl -> GetDeviceDescription(This,pszPnPDeviceID,pDeviceDescription,pcchDeviceDescription) ) 

#define IPortableDeviceManager_GetDeviceManufacturer(This,pszPnPDeviceID,pDeviceManufacturer,pcchDeviceManufacturer)	\
    ( (This)->lpVtbl -> GetDeviceManufacturer(This,pszPnPDeviceID,pDeviceManufacturer,pcchDeviceManufacturer) ) 

#define IPortableDeviceManager_GetDeviceProperty(This,pszPnPDeviceID,pszDevicePropertyName,pData,pcbData,pdwType)	\
    ( (This)->lpVtbl -> GetDeviceProperty(This,pszPnPDeviceID,pszDevicePropertyName,pData,pcbData,pdwType) ) 

#define IPortableDeviceManager_GetPrivateDevices(This,pPnPDeviceIDs,pcPnPDeviceIDs)	\
    ( (This)->lpVtbl -> GetPrivateDevices(This,pPnPDeviceIDs,pcPnPDeviceIDs) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPortableDeviceManager_INTERFACE_DEFINED__ */


#ifndef __IPortableDevice_INTERFACE_DEFINED__
#define __IPortableDevice_INTERFACE_DEFINED__

/* interface IPortableDevice */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IPortableDevice;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("625e2df8-6392-4cf0-9ad1-3cfa5f17775c")
    IPortableDevice : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Open( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPnPDeviceID,
            /* [annotation][in] */ 
            _In_  IPortableDeviceValues *pClientInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SendCommand( 
            /* [annotation][in] */ 
            _In_  const DWORD dwFlags,
            /* [annotation][in] */ 
            _In_  IPortableDeviceValues *pParameters,
            /* [annotation][out] */ 
            _Out_  IPortableDeviceValues **ppResults) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Content( 
            /* [annotation][out] */ 
            _Out_  IPortableDeviceContent **ppContent) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Capabilities( 
            /* [annotation][out] */ 
            _Out_  IPortableDeviceCapabilities **ppCapabilities) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Cancel( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Close( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Advise( 
            /* [annotation][in] */ 
            _In_  const DWORD dwFlags,
            /* [annotation][in] */ 
            _In_  IPortableDeviceEventCallback *pCallback,
            /* [annotation][unique][in] */ 
            _In_  IPortableDeviceValues *pParameters,
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszCookie) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Unadvise( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszCookie) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPnPDeviceID( 
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszPnPDeviceID) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IPortableDeviceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IPortableDevice * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IPortableDevice * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IPortableDevice * This);
        
        HRESULT ( STDMETHODCALLTYPE *Open )( 
            __RPC__in IPortableDevice * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPnPDeviceID,
            /* [annotation][in] */ 
            _In_  IPortableDeviceValues *pClientInfo);
        
        HRESULT ( STDMETHODCALLTYPE *SendCommand )( 
            __RPC__in IPortableDevice * This,
            /* [annotation][in] */ 
            _In_  const DWORD dwFlags,
            /* [annotation][in] */ 
            _In_  IPortableDeviceValues *pParameters,
            /* [annotation][out] */ 
            _Out_  IPortableDeviceValues **ppResults);
        
        HRESULT ( STDMETHODCALLTYPE *Content )( 
            __RPC__in IPortableDevice * This,
            /* [annotation][out] */ 
            _Out_  IPortableDeviceContent **ppContent);
        
        HRESULT ( STDMETHODCALLTYPE *Capabilities )( 
            __RPC__in IPortableDevice * This,
            /* [annotation][out] */ 
            _Out_  IPortableDeviceCapabilities **ppCapabilities);
        
        HRESULT ( STDMETHODCALLTYPE *Cancel )( 
            __RPC__in IPortableDevice * This);
        
        HRESULT ( STDMETHODCALLTYPE *Close )( 
            __RPC__in IPortableDevice * This);
        
        HRESULT ( STDMETHODCALLTYPE *Advise )( 
            __RPC__in IPortableDevice * This,
            /* [annotation][in] */ 
            _In_  const DWORD dwFlags,
            /* [annotation][in] */ 
            _In_  IPortableDeviceEventCallback *pCallback,
            /* [annotation][unique][in] */ 
            _In_  IPortableDeviceValues *pParameters,
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszCookie);
        
        HRESULT ( STDMETHODCALLTYPE *Unadvise )( 
            __RPC__in IPortableDevice * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszCookie);
        
        HRESULT ( STDMETHODCALLTYPE *GetPnPDeviceID )( 
            __RPC__in IPortableDevice * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszPnPDeviceID);
        
        END_INTERFACE
    } IPortableDeviceVtbl;

    interface IPortableDevice
    {
        CONST_VTBL struct IPortableDeviceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPortableDevice_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPortableDevice_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPortableDevice_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPortableDevice_Open(This,pszPnPDeviceID,pClientInfo)	\
    ( (This)->lpVtbl -> Open(This,pszPnPDeviceID,pClientInfo) ) 

#define IPortableDevice_SendCommand(This,dwFlags,pParameters,ppResults)	\
    ( (This)->lpVtbl -> SendCommand(This,dwFlags,pParameters,ppResults) ) 

#define IPortableDevice_Content(This,ppContent)	\
    ( (This)->lpVtbl -> Content(This,ppContent) ) 

#define IPortableDevice_Capabilities(This,ppCapabilities)	\
    ( (This)->lpVtbl -> Capabilities(This,ppCapabilities) ) 

#define IPortableDevice_Cancel(This)	\
    ( (This)->lpVtbl -> Cancel(This) ) 

#define IPortableDevice_Close(This)	\
    ( (This)->lpVtbl -> Close(This) ) 

#define IPortableDevice_Advise(This,dwFlags,pCallback,pParameters,ppszCookie)	\
    ( (This)->lpVtbl -> Advise(This,dwFlags,pCallback,pParameters,ppszCookie) ) 

#define IPortableDevice_Unadvise(This,pszCookie)	\
    ( (This)->lpVtbl -> Unadvise(This,pszCookie) ) 

#define IPortableDevice_GetPnPDeviceID(This,ppszPnPDeviceID)	\
    ( (This)->lpVtbl -> GetPnPDeviceID(This,ppszPnPDeviceID) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPortableDevice_INTERFACE_DEFINED__ */


#ifndef __IPortableDeviceContent_INTERFACE_DEFINED__
#define __IPortableDeviceContent_INTERFACE_DEFINED__

/* interface IPortableDeviceContent */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IPortableDeviceContent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6a96ed84-7c73-4480-9938-bf5af477d426")
    IPortableDeviceContent : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE EnumObjects( 
            /* [annotation][in] */ 
            _In_  const DWORD dwFlags,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszParentObjectID,
            /* [annotation][unique][in] */ 
            _In_  IPortableDeviceValues *pFilter,
            /* [annotation][out] */ 
            _Out_  IEnumPortableDeviceObjectIDs **ppEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Properties( 
            /* [annotation][out] */ 
            _Out_  IPortableDeviceProperties **ppProperties) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Transfer( 
            /* [annotation][out] */ 
            _Out_  IPortableDeviceResources **ppResources) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateObjectWithPropertiesOnly( 
            /* [annotation][in] */ 
            _In_  IPortableDeviceValues *pValues,
            /* [annotation][unique][out][in] */ 
            _Inout_  LPWSTR *ppszObjectID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateObjectWithPropertiesAndData( 
            /* [annotation][in] */ 
            _In_  IPortableDeviceValues *pValues,
            /* [annotation][out] */ 
            _Out_  IStream **ppData,
            /* [annotation][unique][out][in] */ 
            _Inout_  DWORD *pdwOptimalWriteBufferSize,
            /* [annotation][unique][out][in] */ 
            _Inout_  LPWSTR *ppszCookie) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Delete( 
            /* [annotation][in] */ 
            _In_  const DWORD dwOptions,
            /* [annotation][in] */ 
            _In_  IPortableDevicePropVariantCollection *pObjectIDs,
            /* [annotation][unique][out][in] */ 
            _Inout_  IPortableDevicePropVariantCollection **ppResults) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetObjectIDsFromPersistentUniqueIDs( 
            /* [annotation][in] */ 
            _In_  IPortableDevicePropVariantCollection *pPersistentUniqueIDs,
            /* [annotation][out] */ 
            _Out_  IPortableDevicePropVariantCollection **ppObjectIDs) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Cancel( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Move( 
            /* [annotation][in] */ 
            _In_  IPortableDevicePropVariantCollection *pObjectIDs,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszDestinationFolderObjectID,
            /* [annotation][unique][out][in] */ 
            _Inout_  IPortableDevicePropVariantCollection **ppResults) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Copy( 
            /* [annotation][in] */ 
            _In_  IPortableDevicePropVariantCollection *pObjectIDs,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszDestinationFolderObjectID,
            /* [annotation][unique][out][in] */ 
            _Inout_  IPortableDevicePropVariantCollection **ppResults) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IPortableDeviceContentVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IPortableDeviceContent * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IPortableDeviceContent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IPortableDeviceContent * This);
        
        HRESULT ( STDMETHODCALLTYPE *EnumObjects )( 
            __RPC__in IPortableDeviceContent * This,
            /* [annotation][in] */ 
            _In_  const DWORD dwFlags,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszParentObjectID,
            /* [annotation][unique][in] */ 
            _In_  IPortableDeviceValues *pFilter,
            /* [annotation][out] */ 
            _Out_  IEnumPortableDeviceObjectIDs **ppEnum);
        
        HRESULT ( STDMETHODCALLTYPE *Properties )( 
            __RPC__in IPortableDeviceContent * This,
            /* [annotation][out] */ 
            _Out_  IPortableDeviceProperties **ppProperties);
        
        HRESULT ( STDMETHODCALLTYPE *Transfer )( 
            __RPC__in IPortableDeviceContent * This,
            /* [annotation][out] */ 
            _Out_  IPortableDeviceResources **ppResources);
        
        HRESULT ( STDMETHODCALLTYPE *CreateObjectWithPropertiesOnly )( 
            __RPC__in IPortableDeviceContent * This,
            /* [annotation][in] */ 
            _In_  IPortableDeviceValues *pValues,
            /* [annotation][unique][out][in] */ 
            _Inout_  LPWSTR *ppszObjectID);
        
        HRESULT ( STDMETHODCALLTYPE *CreateObjectWithPropertiesAndData )( 
            __RPC__in IPortableDeviceContent * This,
            /* [annotation][in] */ 
            _In_  IPortableDeviceValues *pValues,
            /* [annotation][out] */ 
            _Out_  IStream **ppData,
            /* [annotation][unique][out][in] */ 
            _Inout_  DWORD *pdwOptimalWriteBufferSize,
            /* [annotation][unique][out][in] */ 
            _Inout_  LPWSTR *ppszCookie);
        
        HRESULT ( STDMETHODCALLTYPE *Delete )( 
            __RPC__in IPortableDeviceContent * This,
            /* [annotation][in] */ 
            _In_  const DWORD dwOptions,
            /* [annotation][in] */ 
            _In_  IPortableDevicePropVariantCollection *pObjectIDs,
            /* [annotation][unique][out][in] */ 
            _Inout_  IPortableDevicePropVariantCollection **ppResults);
        
        HRESULT ( STDMETHODCALLTYPE *GetObjectIDsFromPersistentUniqueIDs )( 
            __RPC__in IPortableDeviceContent * This,
            /* [annotation][in] */ 
            _In_  IPortableDevicePropVariantCollection *pPersistentUniqueIDs,
            /* [annotation][out] */ 
            _Out_  IPortableDevicePropVariantCollection **ppObjectIDs);
        
        HRESULT ( STDMETHODCALLTYPE *Cancel )( 
            __RPC__in IPortableDeviceContent * This);
        
        HRESULT ( STDMETHODCALLTYPE *Move )( 
            __RPC__in IPortableDeviceContent * This,
            /* [annotation][in] */ 
            _In_  IPortableDevicePropVariantCollection *pObjectIDs,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszDestinationFolderObjectID,
            /* [annotation][unique][out][in] */ 
            _Inout_  IPortableDevicePropVariantCollection **ppResults);
        
        HRESULT ( STDMETHODCALLTYPE *Copy )( 
            __RPC__in IPortableDeviceContent * This,
            /* [annotation][in] */ 
            _In_  IPortableDevicePropVariantCollection *pObjectIDs,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszDestinationFolderObjectID,
            /* [annotation][unique][out][in] */ 
            _Inout_  IPortableDevicePropVariantCollection **ppResults);
        
        END_INTERFACE
    } IPortableDeviceContentVtbl;

    interface IPortableDeviceContent
    {
        CONST_VTBL struct IPortableDeviceContentVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPortableDeviceContent_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPortableDeviceContent_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPortableDeviceContent_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPortableDeviceContent_EnumObjects(This,dwFlags,pszParentObjectID,pFilter,ppEnum)	\
    ( (This)->lpVtbl -> EnumObjects(This,dwFlags,pszParentObjectID,pFilter,ppEnum) ) 

#define IPortableDeviceContent_Properties(This,ppProperties)	\
    ( (This)->lpVtbl -> Properties(This,ppProperties) ) 

#define IPortableDeviceContent_Transfer(This,ppResources)	\
    ( (This)->lpVtbl -> Transfer(This,ppResources) ) 

#define IPortableDeviceContent_CreateObjectWithPropertiesOnly(This,pValues,ppszObjectID)	\
    ( (This)->lpVtbl -> CreateObjectWithPropertiesOnly(This,pValues,ppszObjectID) ) 

#define IPortableDeviceContent_CreateObjectWithPropertiesAndData(This,pValues,ppData,pdwOptimalWriteBufferSize,ppszCookie)	\
    ( (This)->lpVtbl -> CreateObjectWithPropertiesAndData(This,pValues,ppData,pdwOptimalWriteBufferSize,ppszCookie) ) 

#define IPortableDeviceContent_Delete(This,dwOptions,pObjectIDs,ppResults)	\
    ( (This)->lpVtbl -> Delete(This,dwOptions,pObjectIDs,ppResults) ) 

#define IPortableDeviceContent_GetObjectIDsFromPersistentUniqueIDs(This,pPersistentUniqueIDs,ppObjectIDs)	\
    ( (This)->lpVtbl -> GetObjectIDsFromPersistentUniqueIDs(This,pPersistentUniqueIDs,ppObjectIDs) ) 

#define IPortableDeviceContent_Cancel(This)	\
    ( (This)->lpVtbl -> Cancel(This) ) 

#define IPortableDeviceContent_Move(This,pObjectIDs,pszDestinationFolderObjectID,ppResults)	\
    ( (This)->lpVtbl -> Move(This,pObjectIDs,pszDestinationFolderObjectID,ppResults) ) 

#define IPortableDeviceContent_Copy(This,pObjectIDs,pszDestinationFolderObjectID,ppResults)	\
    ( (This)->lpVtbl -> Copy(This,pObjectIDs,pszDestinationFolderObjectID,ppResults) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPortableDeviceContent_INTERFACE_DEFINED__ */


#ifndef __IPortableDeviceContent2_INTERFACE_DEFINED__
#define __IPortableDeviceContent2_INTERFACE_DEFINED__

/* interface IPortableDeviceContent2 */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IPortableDeviceContent2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9b4add96-f6bf-4034-8708-eca72bf10554")
    IPortableDeviceContent2 : public IPortableDeviceContent
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE UpdateObjectWithPropertiesAndData( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszObjectID,
            /* [annotation][in] */ 
            _In_  IPortableDeviceValues *pProperties,
            /* [annotation][out] */ 
            _Out_  IStream **ppData,
            /* [annotation][unique][out][in] */ 
            _Inout_  DWORD *pdwOptimalWriteBufferSize) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IPortableDeviceContent2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IPortableDeviceContent2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IPortableDeviceContent2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IPortableDeviceContent2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *EnumObjects )( 
            __RPC__in IPortableDeviceContent2 * This,
            /* [annotation][in] */ 
            _In_  const DWORD dwFlags,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszParentObjectID,
            /* [annotation][unique][in] */ 
            _In_  IPortableDeviceValues *pFilter,
            /* [annotation][out] */ 
            _Out_  IEnumPortableDeviceObjectIDs **ppEnum);
        
        HRESULT ( STDMETHODCALLTYPE *Properties )( 
            __RPC__in IPortableDeviceContent2 * This,
            /* [annotation][out] */ 
            _Out_  IPortableDeviceProperties **ppProperties);
        
        HRESULT ( STDMETHODCALLTYPE *Transfer )( 
            __RPC__in IPortableDeviceContent2 * This,
            /* [annotation][out] */ 
            _Out_  IPortableDeviceResources **ppResources);
        
        HRESULT ( STDMETHODCALLTYPE *CreateObjectWithPropertiesOnly )( 
            __RPC__in IPortableDeviceContent2 * This,
            /* [annotation][in] */ 
            _In_  IPortableDeviceValues *pValues,
            /* [annotation][unique][out][in] */ 
            _Inout_  LPWSTR *ppszObjectID);
        
        HRESULT ( STDMETHODCALLTYPE *CreateObjectWithPropertiesAndData )( 
            __RPC__in IPortableDeviceContent2 * This,
            /* [annotation][in] */ 
            _In_  IPortableDeviceValues *pValues,
            /* [annotation][out] */ 
            _Out_  IStream **ppData,
            /* [annotation][unique][out][in] */ 
            _Inout_  DWORD *pdwOptimalWriteBufferSize,
            /* [annotation][unique][out][in] */ 
            _Inout_  LPWSTR *ppszCookie);
        
        HRESULT ( STDMETHODCALLTYPE *Delete )( 
            __RPC__in IPortableDeviceContent2 * This,
            /* [annotation][in] */ 
            _In_  const DWORD dwOptions,
            /* [annotation][in] */ 
            _In_  IPortableDevicePropVariantCollection *pObjectIDs,
            /* [annotation][unique][out][in] */ 
            _Inout_  IPortableDevicePropVariantCollection **ppResults);
        
        HRESULT ( STDMETHODCALLTYPE *GetObjectIDsFromPersistentUniqueIDs )( 
            __RPC__in IPortableDeviceContent2 * This,
            /* [annotation][in] */ 
            _In_  IPortableDevicePropVariantCollection *pPersistentUniqueIDs,
            /* [annotation][out] */ 
            _Out_  IPortableDevicePropVariantCollection **ppObjectIDs);
        
        HRESULT ( STDMETHODCALLTYPE *Cancel )( 
            __RPC__in IPortableDeviceContent2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *Move )( 
            __RPC__in IPortableDeviceContent2 * This,
            /* [annotation][in] */ 
            _In_  IPortableDevicePropVariantCollection *pObjectIDs,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszDestinationFolderObjectID,
            /* [annotation][unique][out][in] */ 
            _Inout_  IPortableDevicePropVariantCollection **ppResults);
        
        HRESULT ( STDMETHODCALLTYPE *Copy )( 
            __RPC__in IPortableDeviceContent2 * This,
            /* [annotation][in] */ 
            _In_  IPortableDevicePropVariantCollection *pObjectIDs,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszDestinationFolderObjectID,
            /* [annotation][unique][out][in] */ 
            _Inout_  IPortableDevicePropVariantCollection **ppResults);
        
        HRESULT ( STDMETHODCALLTYPE *UpdateObjectWithPropertiesAndData )( 
            __RPC__in IPortableDeviceContent2 * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszObjectID,
            /* [annotation][in] */ 
            _In_  IPortableDeviceValues *pProperties,
            /* [annotation][out] */ 
            _Out_  IStream **ppData,
            /* [annotation][unique][out][in] */ 
            _Inout_  DWORD *pdwOptimalWriteBufferSize);
        
        END_INTERFACE
    } IPortableDeviceContent2Vtbl;

    interface IPortableDeviceContent2
    {
        CONST_VTBL struct IPortableDeviceContent2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPortableDeviceContent2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPortableDeviceContent2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPortableDeviceContent2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPortableDeviceContent2_EnumObjects(This,dwFlags,pszParentObjectID,pFilter,ppEnum)	\
    ( (This)->lpVtbl -> EnumObjects(This,dwFlags,pszParentObjectID,pFilter,ppEnum) ) 

#define IPortableDeviceContent2_Properties(This,ppProperties)	\
    ( (This)->lpVtbl -> Properties(This,ppProperties) ) 

#define IPortableDeviceContent2_Transfer(This,ppResources)	\
    ( (This)->lpVtbl -> Transfer(This,ppResources) ) 

#define IPortableDeviceContent2_CreateObjectWithPropertiesOnly(This,pValues,ppszObjectID)	\
    ( (This)->lpVtbl -> CreateObjectWithPropertiesOnly(This,pValues,ppszObjectID) ) 

#define IPortableDeviceContent2_CreateObjectWithPropertiesAndData(This,pValues,ppData,pdwOptimalWriteBufferSize,ppszCookie)	\
    ( (This)->lpVtbl -> CreateObjectWithPropertiesAndData(This,pValues,ppData,pdwOptimalWriteBufferSize,ppszCookie) ) 

#define IPortableDeviceContent2_Delete(This,dwOptions,pObjectIDs,ppResults)	\
    ( (This)->lpVtbl -> Delete(This,dwOptions,pObjectIDs,ppResults) ) 

#define IPortableDeviceContent2_GetObjectIDsFromPersistentUniqueIDs(This,pPersistentUniqueIDs,ppObjectIDs)	\
    ( (This)->lpVtbl -> GetObjectIDsFromPersistentUniqueIDs(This,pPersistentUniqueIDs,ppObjectIDs) ) 

#define IPortableDeviceContent2_Cancel(This)	\
    ( (This)->lpVtbl -> Cancel(This) ) 

#define IPortableDeviceContent2_Move(This,pObjectIDs,pszDestinationFolderObjectID,ppResults)	\
    ( (This)->lpVtbl -> Move(This,pObjectIDs,pszDestinationFolderObjectID,ppResults) ) 

#define IPortableDeviceContent2_Copy(This,pObjectIDs,pszDestinationFolderObjectID,ppResults)	\
    ( (This)->lpVtbl -> Copy(This,pObjectIDs,pszDestinationFolderObjectID,ppResults) ) 


#define IPortableDeviceContent2_UpdateObjectWithPropertiesAndData(This,pszObjectID,pProperties,ppData,pdwOptimalWriteBufferSize)	\
    ( (This)->lpVtbl -> UpdateObjectWithPropertiesAndData(This,pszObjectID,pProperties,ppData,pdwOptimalWriteBufferSize) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPortableDeviceContent2_INTERFACE_DEFINED__ */


#ifndef __IEnumPortableDeviceObjectIDs_INTERFACE_DEFINED__
#define __IEnumPortableDeviceObjectIDs_INTERFACE_DEFINED__

/* interface IEnumPortableDeviceObjectIDs */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IEnumPortableDeviceObjectIDs;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("10ece955-cf41-4728-bfa0-41eedf1bbf19")
    IEnumPortableDeviceObjectIDs : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [annotation][in] */ 
            _In_  ULONG cObjects,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(cObjects,*pcFetched)  LPWSTR *pObjIDs,
            /* [annotation][unique][out][in] */ 
            _Inout_  ULONG *pcFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [annotation][in] */ 
            _In_  ULONG cObjects) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [annotation][out] */ 
            _Out_  IEnumPortableDeviceObjectIDs **ppEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Cancel( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IEnumPortableDeviceObjectIDsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IEnumPortableDeviceObjectIDs * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IEnumPortableDeviceObjectIDs * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IEnumPortableDeviceObjectIDs * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            __RPC__in IEnumPortableDeviceObjectIDs * This,
            /* [annotation][in] */ 
            _In_  ULONG cObjects,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(cObjects,*pcFetched)  LPWSTR *pObjIDs,
            /* [annotation][unique][out][in] */ 
            _Inout_  ULONG *pcFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            __RPC__in IEnumPortableDeviceObjectIDs * This,
            /* [annotation][in] */ 
            _In_  ULONG cObjects);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            __RPC__in IEnumPortableDeviceObjectIDs * This);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            __RPC__in IEnumPortableDeviceObjectIDs * This,
            /* [annotation][out] */ 
            _Out_  IEnumPortableDeviceObjectIDs **ppEnum);
        
        HRESULT ( STDMETHODCALLTYPE *Cancel )( 
            __RPC__in IEnumPortableDeviceObjectIDs * This);
        
        END_INTERFACE
    } IEnumPortableDeviceObjectIDsVtbl;

    interface IEnumPortableDeviceObjectIDs
    {
        CONST_VTBL struct IEnumPortableDeviceObjectIDsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumPortableDeviceObjectIDs_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEnumPortableDeviceObjectIDs_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEnumPortableDeviceObjectIDs_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IEnumPortableDeviceObjectIDs_Next(This,cObjects,pObjIDs,pcFetched)	\
    ( (This)->lpVtbl -> Next(This,cObjects,pObjIDs,pcFetched) ) 

#define IEnumPortableDeviceObjectIDs_Skip(This,cObjects)	\
    ( (This)->lpVtbl -> Skip(This,cObjects) ) 

#define IEnumPortableDeviceObjectIDs_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define IEnumPortableDeviceObjectIDs_Clone(This,ppEnum)	\
    ( (This)->lpVtbl -> Clone(This,ppEnum) ) 

#define IEnumPortableDeviceObjectIDs_Cancel(This)	\
    ( (This)->lpVtbl -> Cancel(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IEnumPortableDeviceObjectIDs_INTERFACE_DEFINED__ */


#ifndef __IPortableDeviceProperties_INTERFACE_DEFINED__
#define __IPortableDeviceProperties_INTERFACE_DEFINED__

/* interface IPortableDeviceProperties */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IPortableDeviceProperties;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7f6d695c-03df-4439-a809-59266beee3a6")
    IPortableDeviceProperties : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetSupportedProperties( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszObjectID,
            /* [annotation][out] */ 
            _Out_  IPortableDeviceKeyCollection **ppKeys) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPropertyAttributes( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszObjectID,
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY Key,
            /* [annotation][out] */ 
            _Out_  IPortableDeviceValues **ppAttributes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetValues( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszObjectID,
            /* [annotation][unique][in] */ 
            _In_  IPortableDeviceKeyCollection *pKeys,
            /* [annotation][out] */ 
            _Out_  IPortableDeviceValues **ppValues) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetValues( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszObjectID,
            /* [annotation][in] */ 
            _In_  IPortableDeviceValues *pValues,
            /* [annotation][out] */ 
            _Out_  IPortableDeviceValues **ppResults) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Delete( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszObjectID,
            /* [annotation][in] */ 
            _In_  IPortableDeviceKeyCollection *pKeys) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Cancel( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IPortableDevicePropertiesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IPortableDeviceProperties * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IPortableDeviceProperties * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IPortableDeviceProperties * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetSupportedProperties )( 
            __RPC__in IPortableDeviceProperties * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszObjectID,
            /* [annotation][out] */ 
            _Out_  IPortableDeviceKeyCollection **ppKeys);
        
        HRESULT ( STDMETHODCALLTYPE *GetPropertyAttributes )( 
            __RPC__in IPortableDeviceProperties * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszObjectID,
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY Key,
            /* [annotation][out] */ 
            _Out_  IPortableDeviceValues **ppAttributes);
        
        HRESULT ( STDMETHODCALLTYPE *GetValues )( 
            __RPC__in IPortableDeviceProperties * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszObjectID,
            /* [annotation][unique][in] */ 
            _In_  IPortableDeviceKeyCollection *pKeys,
            /* [annotation][out] */ 
            _Out_  IPortableDeviceValues **ppValues);
        
        HRESULT ( STDMETHODCALLTYPE *SetValues )( 
            __RPC__in IPortableDeviceProperties * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszObjectID,
            /* [annotation][in] */ 
            _In_  IPortableDeviceValues *pValues,
            /* [annotation][out] */ 
            _Out_  IPortableDeviceValues **ppResults);
        
        HRESULT ( STDMETHODCALLTYPE *Delete )( 
            __RPC__in IPortableDeviceProperties * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszObjectID,
            /* [annotation][in] */ 
            _In_  IPortableDeviceKeyCollection *pKeys);
        
        HRESULT ( STDMETHODCALLTYPE *Cancel )( 
            __RPC__in IPortableDeviceProperties * This);
        
        END_INTERFACE
    } IPortableDevicePropertiesVtbl;

    interface IPortableDeviceProperties
    {
        CONST_VTBL struct IPortableDevicePropertiesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPortableDeviceProperties_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPortableDeviceProperties_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPortableDeviceProperties_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPortableDeviceProperties_GetSupportedProperties(This,pszObjectID,ppKeys)	\
    ( (This)->lpVtbl -> GetSupportedProperties(This,pszObjectID,ppKeys) ) 

#define IPortableDeviceProperties_GetPropertyAttributes(This,pszObjectID,Key,ppAttributes)	\
    ( (This)->lpVtbl -> GetPropertyAttributes(This,pszObjectID,Key,ppAttributes) ) 

#define IPortableDeviceProperties_GetValues(This,pszObjectID,pKeys,ppValues)	\
    ( (This)->lpVtbl -> GetValues(This,pszObjectID,pKeys,ppValues) ) 

#define IPortableDeviceProperties_SetValues(This,pszObjectID,pValues,ppResults)	\
    ( (This)->lpVtbl -> SetValues(This,pszObjectID,pValues,ppResults) ) 

#define IPortableDeviceProperties_Delete(This,pszObjectID,pKeys)	\
    ( (This)->lpVtbl -> Delete(This,pszObjectID,pKeys) ) 

#define IPortableDeviceProperties_Cancel(This)	\
    ( (This)->lpVtbl -> Cancel(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPortableDeviceProperties_INTERFACE_DEFINED__ */


#ifndef __IPortableDeviceResources_INTERFACE_DEFINED__
#define __IPortableDeviceResources_INTERFACE_DEFINED__

/* interface IPortableDeviceResources */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IPortableDeviceResources;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("fd8878ac-d841-4d17-891c-e6829cdb6934")
    IPortableDeviceResources : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetSupportedResources( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszObjectID,
            /* [annotation][out] */ 
            _Out_  IPortableDeviceKeyCollection **ppKeys) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetResourceAttributes( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszObjectID,
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY Key,
            /* [annotation][out] */ 
            _Out_  IPortableDeviceValues **ppResourceAttributes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStream( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszObjectID,
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY Key,
            /* [annotation][in] */ 
            _In_  const DWORD dwMode,
            /* [annotation][unique][out][in] */ 
            _Inout_  DWORD *pdwOptimalBufferSize,
            /* [annotation][out] */ 
            _Out_  IStream **ppStream) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Delete( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszObjectID,
            /* [annotation][in] */ 
            _In_  IPortableDeviceKeyCollection *pKeys) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Cancel( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateResource( 
            /* [annotation][in] */ 
            _In_  IPortableDeviceValues *pResourceAttributes,
            /* [annotation][out] */ 
            _Out_  IStream **ppData,
            /* [annotation][unique][out][in] */ 
            _Inout_  DWORD *pdwOptimalWriteBufferSize,
            /* [annotation][unique][out][in] */ 
            _Inout_  LPWSTR *ppszCookie) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IPortableDeviceResourcesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IPortableDeviceResources * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IPortableDeviceResources * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IPortableDeviceResources * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetSupportedResources )( 
            __RPC__in IPortableDeviceResources * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszObjectID,
            /* [annotation][out] */ 
            _Out_  IPortableDeviceKeyCollection **ppKeys);
        
        HRESULT ( STDMETHODCALLTYPE *GetResourceAttributes )( 
            __RPC__in IPortableDeviceResources * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszObjectID,
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY Key,
            /* [annotation][out] */ 
            _Out_  IPortableDeviceValues **ppResourceAttributes);
        
        HRESULT ( STDMETHODCALLTYPE *GetStream )( 
            __RPC__in IPortableDeviceResources * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszObjectID,
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY Key,
            /* [annotation][in] */ 
            _In_  const DWORD dwMode,
            /* [annotation][unique][out][in] */ 
            _Inout_  DWORD *pdwOptimalBufferSize,
            /* [annotation][out] */ 
            _Out_  IStream **ppStream);
        
        HRESULT ( STDMETHODCALLTYPE *Delete )( 
            __RPC__in IPortableDeviceResources * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszObjectID,
            /* [annotation][in] */ 
            _In_  IPortableDeviceKeyCollection *pKeys);
        
        HRESULT ( STDMETHODCALLTYPE *Cancel )( 
            __RPC__in IPortableDeviceResources * This);
        
        HRESULT ( STDMETHODCALLTYPE *CreateResource )( 
            __RPC__in IPortableDeviceResources * This,
            /* [annotation][in] */ 
            _In_  IPortableDeviceValues *pResourceAttributes,
            /* [annotation][out] */ 
            _Out_  IStream **ppData,
            /* [annotation][unique][out][in] */ 
            _Inout_  DWORD *pdwOptimalWriteBufferSize,
            /* [annotation][unique][out][in] */ 
            _Inout_  LPWSTR *ppszCookie);
        
        END_INTERFACE
    } IPortableDeviceResourcesVtbl;

    interface IPortableDeviceResources
    {
        CONST_VTBL struct IPortableDeviceResourcesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPortableDeviceResources_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPortableDeviceResources_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPortableDeviceResources_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPortableDeviceResources_GetSupportedResources(This,pszObjectID,ppKeys)	\
    ( (This)->lpVtbl -> GetSupportedResources(This,pszObjectID,ppKeys) ) 

#define IPortableDeviceResources_GetResourceAttributes(This,pszObjectID,Key,ppResourceAttributes)	\
    ( (This)->lpVtbl -> GetResourceAttributes(This,pszObjectID,Key,ppResourceAttributes) ) 

#define IPortableDeviceResources_GetStream(This,pszObjectID,Key,dwMode,pdwOptimalBufferSize,ppStream)	\
    ( (This)->lpVtbl -> GetStream(This,pszObjectID,Key,dwMode,pdwOptimalBufferSize,ppStream) ) 

#define IPortableDeviceResources_Delete(This,pszObjectID,pKeys)	\
    ( (This)->lpVtbl -> Delete(This,pszObjectID,pKeys) ) 

#define IPortableDeviceResources_Cancel(This)	\
    ( (This)->lpVtbl -> Cancel(This) ) 

#define IPortableDeviceResources_CreateResource(This,pResourceAttributes,ppData,pdwOptimalWriteBufferSize,ppszCookie)	\
    ( (This)->lpVtbl -> CreateResource(This,pResourceAttributes,ppData,pdwOptimalWriteBufferSize,ppszCookie) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPortableDeviceResources_INTERFACE_DEFINED__ */


#ifndef __IPortableDeviceCapabilities_INTERFACE_DEFINED__
#define __IPortableDeviceCapabilities_INTERFACE_DEFINED__

/* interface IPortableDeviceCapabilities */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IPortableDeviceCapabilities;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2c8c6dbf-e3dc-4061-becc-8542e810d126")
    IPortableDeviceCapabilities : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetSupportedCommands( 
            /* [annotation][out] */ 
            _Out_  IPortableDeviceKeyCollection **ppCommands) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCommandOptions( 
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY Command,
            /* [annotation][out] */ 
            _Out_  IPortableDeviceValues **ppOptions) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFunctionalCategories( 
            /* [annotation][out] */ 
            _Out_  IPortableDevicePropVariantCollection **ppCategories) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFunctionalObjects( 
            /* [annotation][in] */ 
            _In_  REFGUID Category,
            /* [annotation][out] */ 
            _Out_  IPortableDevicePropVariantCollection **ppObjectIDs) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSupportedContentTypes( 
            /* [annotation][in] */ 
            _In_  REFGUID Category,
            /* [annotation][out] */ 
            _Out_  IPortableDevicePropVariantCollection **ppContentTypes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSupportedFormats( 
            /* [annotation][in] */ 
            _In_  REFGUID ContentType,
            /* [annotation][out] */ 
            _Out_  IPortableDevicePropVariantCollection **ppFormats) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSupportedFormatProperties( 
            /* [annotation][in] */ 
            _In_  REFGUID Format,
            /* [annotation][out] */ 
            _Out_  IPortableDeviceKeyCollection **ppKeys) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFixedPropertyAttributes( 
            /* [annotation][in] */ 
            _In_  REFGUID Format,
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY Key,
            /* [annotation][out] */ 
            _Out_  IPortableDeviceValues **ppAttributes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Cancel( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSupportedEvents( 
            /* [annotation][out] */ 
            _Out_  IPortableDevicePropVariantCollection **ppEvents) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEventOptions( 
            /* [annotation][in] */ 
            _In_  REFGUID Event,
            /* [annotation][out] */ 
            _Out_  IPortableDeviceValues **ppOptions) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IPortableDeviceCapabilitiesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IPortableDeviceCapabilities * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IPortableDeviceCapabilities * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IPortableDeviceCapabilities * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetSupportedCommands )( 
            __RPC__in IPortableDeviceCapabilities * This,
            /* [annotation][out] */ 
            _Out_  IPortableDeviceKeyCollection **ppCommands);
        
        HRESULT ( STDMETHODCALLTYPE *GetCommandOptions )( 
            __RPC__in IPortableDeviceCapabilities * This,
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY Command,
            /* [annotation][out] */ 
            _Out_  IPortableDeviceValues **ppOptions);
        
        HRESULT ( STDMETHODCALLTYPE *GetFunctionalCategories )( 
            __RPC__in IPortableDeviceCapabilities * This,
            /* [annotation][out] */ 
            _Out_  IPortableDevicePropVariantCollection **ppCategories);
        
        HRESULT ( STDMETHODCALLTYPE *GetFunctionalObjects )( 
            __RPC__in IPortableDeviceCapabilities * This,
            /* [annotation][in] */ 
            _In_  REFGUID Category,
            /* [annotation][out] */ 
            _Out_  IPortableDevicePropVariantCollection **ppObjectIDs);
        
        HRESULT ( STDMETHODCALLTYPE *GetSupportedContentTypes )( 
            __RPC__in IPortableDeviceCapabilities * This,
            /* [annotation][in] */ 
            _In_  REFGUID Category,
            /* [annotation][out] */ 
            _Out_  IPortableDevicePropVariantCollection **ppContentTypes);
        
        HRESULT ( STDMETHODCALLTYPE *GetSupportedFormats )( 
            __RPC__in IPortableDeviceCapabilities * This,
            /* [annotation][in] */ 
            _In_  REFGUID ContentType,
            /* [annotation][out] */ 
            _Out_  IPortableDevicePropVariantCollection **ppFormats);
        
        HRESULT ( STDMETHODCALLTYPE *GetSupportedFormatProperties )( 
            __RPC__in IPortableDeviceCapabilities * This,
            /* [annotation][in] */ 
            _In_  REFGUID Format,
            /* [annotation][out] */ 
            _Out_  IPortableDeviceKeyCollection **ppKeys);
        
        HRESULT ( STDMETHODCALLTYPE *GetFixedPropertyAttributes )( 
            __RPC__in IPortableDeviceCapabilities * This,
            /* [annotation][in] */ 
            _In_  REFGUID Format,
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY Key,
            /* [annotation][out] */ 
            _Out_  IPortableDeviceValues **ppAttributes);
        
        HRESULT ( STDMETHODCALLTYPE *Cancel )( 
            __RPC__in IPortableDeviceCapabilities * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetSupportedEvents )( 
            __RPC__in IPortableDeviceCapabilities * This,
            /* [annotation][out] */ 
            _Out_  IPortableDevicePropVariantCollection **ppEvents);
        
        HRESULT ( STDMETHODCALLTYPE *GetEventOptions )( 
            __RPC__in IPortableDeviceCapabilities * This,
            /* [annotation][in] */ 
            _In_  REFGUID Event,
            /* [annotation][out] */ 
            _Out_  IPortableDeviceValues **ppOptions);
        
        END_INTERFACE
    } IPortableDeviceCapabilitiesVtbl;

    interface IPortableDeviceCapabilities
    {
        CONST_VTBL struct IPortableDeviceCapabilitiesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPortableDeviceCapabilities_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPortableDeviceCapabilities_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPortableDeviceCapabilities_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPortableDeviceCapabilities_GetSupportedCommands(This,ppCommands)	\
    ( (This)->lpVtbl -> GetSupportedCommands(This,ppCommands) ) 

#define IPortableDeviceCapabilities_GetCommandOptions(This,Command,ppOptions)	\
    ( (This)->lpVtbl -> GetCommandOptions(This,Command,ppOptions) ) 

#define IPortableDeviceCapabilities_GetFunctionalCategories(This,ppCategories)	\
    ( (This)->lpVtbl -> GetFunctionalCategories(This,ppCategories) ) 

#define IPortableDeviceCapabilities_GetFunctionalObjects(This,Category,ppObjectIDs)	\
    ( (This)->lpVtbl -> GetFunctionalObjects(This,Category,ppObjectIDs) ) 

#define IPortableDeviceCapabilities_GetSupportedContentTypes(This,Category,ppContentTypes)	\
    ( (This)->lpVtbl -> GetSupportedContentTypes(This,Category,ppContentTypes) ) 

#define IPortableDeviceCapabilities_GetSupportedFormats(This,ContentType,ppFormats)	\
    ( (This)->lpVtbl -> GetSupportedFormats(This,ContentType,ppFormats) ) 

#define IPortableDeviceCapabilities_GetSupportedFormatProperties(This,Format,ppKeys)	\
    ( (This)->lpVtbl -> GetSupportedFormatProperties(This,Format,ppKeys) ) 

#define IPortableDeviceCapabilities_GetFixedPropertyAttributes(This,Format,Key,ppAttributes)	\
    ( (This)->lpVtbl -> GetFixedPropertyAttributes(This,Format,Key,ppAttributes) ) 

#define IPortableDeviceCapabilities_Cancel(This)	\
    ( (This)->lpVtbl -> Cancel(This) ) 

#define IPortableDeviceCapabilities_GetSupportedEvents(This,ppEvents)	\
    ( (This)->lpVtbl -> GetSupportedEvents(This,ppEvents) ) 

#define IPortableDeviceCapabilities_GetEventOptions(This,Event,ppOptions)	\
    ( (This)->lpVtbl -> GetEventOptions(This,Event,ppOptions) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPortableDeviceCapabilities_INTERFACE_DEFINED__ */


#ifndef __IPortableDeviceEventCallback_INTERFACE_DEFINED__
#define __IPortableDeviceEventCallback_INTERFACE_DEFINED__

/* interface IPortableDeviceEventCallback */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IPortableDeviceEventCallback;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("a8792a31-f385-493c-a893-40f64eb45f6e")
    IPortableDeviceEventCallback : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnEvent( 
            /* [annotation][in] */ 
            _In_  IPortableDeviceValues *pEventParameters) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IPortableDeviceEventCallbackVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IPortableDeviceEventCallback * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IPortableDeviceEventCallback * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IPortableDeviceEventCallback * This);
        
        HRESULT ( STDMETHODCALLTYPE *OnEvent )( 
            __RPC__in IPortableDeviceEventCallback * This,
            /* [annotation][in] */ 
            _In_  IPortableDeviceValues *pEventParameters);
        
        END_INTERFACE
    } IPortableDeviceEventCallbackVtbl;

    interface IPortableDeviceEventCallback
    {
        CONST_VTBL struct IPortableDeviceEventCallbackVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPortableDeviceEventCallback_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPortableDeviceEventCallback_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPortableDeviceEventCallback_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPortableDeviceEventCallback_OnEvent(This,pEventParameters)	\
    ( (This)->lpVtbl -> OnEvent(This,pEventParameters) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPortableDeviceEventCallback_INTERFACE_DEFINED__ */


#ifndef __IPortableDeviceDataStream_INTERFACE_DEFINED__
#define __IPortableDeviceDataStream_INTERFACE_DEFINED__

/* interface IPortableDeviceDataStream */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IPortableDeviceDataStream;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("88e04db3-1012-4d64-9996-f703a950d3f4")
    IPortableDeviceDataStream : public IStream
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetObjectID( 
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszObjectID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Cancel( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IPortableDeviceDataStreamVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IPortableDeviceDataStream * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IPortableDeviceDataStream * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IPortableDeviceDataStream * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Read )( 
            IPortableDeviceDataStream * This,
            /* [annotation] */ 
            _Out_writes_bytes_to_(cb, *pcbRead)  void *pv,
            /* [annotation][in] */ 
            _In_  ULONG cb,
            /* [annotation] */ 
            _Out_opt_  ULONG *pcbRead);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Write )( 
            IPortableDeviceDataStream * This,
            /* [annotation] */ 
            _In_reads_bytes_(cb)  const void *pv,
            /* [annotation][in] */ 
            _In_  ULONG cb,
            /* [annotation] */ 
            _Out_opt_  ULONG *pcbWritten);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Seek )( 
            IPortableDeviceDataStream * This,
            /* [annotation][in] */ 
            _In_  LARGE_INTEGER dlibMove,
            /* [annotation][in] */ 
            _In_  DWORD dwOrigin,
            /* [annotation] */ 
            _Out_opt_  ULARGE_INTEGER *plibNewPosition);
        
        HRESULT ( STDMETHODCALLTYPE *SetSize )( 
            __RPC__in IPortableDeviceDataStream * This,
            /* [annotation][in] */ 
            _In_  ULARGE_INTEGER libNewSize);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *CopyTo )( 
            IPortableDeviceDataStream * This,
            /* [annotation][unique][in] */ 
            _In_  IStream *pstm,
            /* [annotation][in] */ 
            _In_  ULARGE_INTEGER cb,
            /* [annotation] */ 
            _Out_opt_  ULARGE_INTEGER *pcbRead,
            /* [annotation] */ 
            _Out_opt_  ULARGE_INTEGER *pcbWritten);
        
        HRESULT ( STDMETHODCALLTYPE *Commit )( 
            __RPC__in IPortableDeviceDataStream * This,
            /* [annotation][in] */ 
            _In_  DWORD grfCommitFlags);
        
        HRESULT ( STDMETHODCALLTYPE *Revert )( 
            __RPC__in IPortableDeviceDataStream * This);
        
        HRESULT ( STDMETHODCALLTYPE *LockRegion )( 
            __RPC__in IPortableDeviceDataStream * This,
            /* [annotation][in] */ 
            _In_  ULARGE_INTEGER libOffset,
            /* [annotation][in] */ 
            _In_  ULARGE_INTEGER cb,
            /* [annotation][in] */ 
            _In_  DWORD dwLockType);
        
        HRESULT ( STDMETHODCALLTYPE *UnlockRegion )( 
            __RPC__in IPortableDeviceDataStream * This,
            /* [annotation][in] */ 
            _In_  ULARGE_INTEGER libOffset,
            /* [annotation][in] */ 
            _In_  ULARGE_INTEGER cb,
            /* [annotation][in] */ 
            _In_  DWORD dwLockType);
        
        HRESULT ( STDMETHODCALLTYPE *Stat )( 
            __RPC__in IPortableDeviceDataStream * This,
            /* [annotation][out] */ 
            _Out_  STATSTG *pstatstg,
            /* [annotation][in] */ 
            _In_  DWORD grfStatFlag);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            __RPC__in IPortableDeviceDataStream * This,
            /* [annotation][out] */ 
            _Out_  IStream **ppstm);
        
        HRESULT ( STDMETHODCALLTYPE *GetObjectID )( 
            __RPC__in IPortableDeviceDataStream * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszObjectID);
        
        HRESULT ( STDMETHODCALLTYPE *Cancel )( 
            __RPC__in IPortableDeviceDataStream * This);
        
        END_INTERFACE
    } IPortableDeviceDataStreamVtbl;

    interface IPortableDeviceDataStream
    {
        CONST_VTBL struct IPortableDeviceDataStreamVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPortableDeviceDataStream_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPortableDeviceDataStream_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPortableDeviceDataStream_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPortableDeviceDataStream_Read(This,pv,cb,pcbRead)	\
    ( (This)->lpVtbl -> Read(This,pv,cb,pcbRead) ) 

#define IPortableDeviceDataStream_Write(This,pv,cb,pcbWritten)	\
    ( (This)->lpVtbl -> Write(This,pv,cb,pcbWritten) ) 


#define IPortableDeviceDataStream_Seek(This,dlibMove,dwOrigin,plibNewPosition)	\
    ( (This)->lpVtbl -> Seek(This,dlibMove,dwOrigin,plibNewPosition) ) 

#define IPortableDeviceDataStream_SetSize(This,libNewSize)	\
    ( (This)->lpVtbl -> SetSize(This,libNewSize) ) 

#define IPortableDeviceDataStream_CopyTo(This,pstm,cb,pcbRead,pcbWritten)	\
    ( (This)->lpVtbl -> CopyTo(This,pstm,cb,pcbRead,pcbWritten) ) 

#define IPortableDeviceDataStream_Commit(This,grfCommitFlags)	\
    ( (This)->lpVtbl -> Commit(This,grfCommitFlags) ) 

#define IPortableDeviceDataStream_Revert(This)	\
    ( (This)->lpVtbl -> Revert(This) ) 

#define IPortableDeviceDataStream_LockRegion(This,libOffset,cb,dwLockType)	\
    ( (This)->lpVtbl -> LockRegion(This,libOffset,cb,dwLockType) ) 

#define IPortableDeviceDataStream_UnlockRegion(This,libOffset,cb,dwLockType)	\
    ( (This)->lpVtbl -> UnlockRegion(This,libOffset,cb,dwLockType) ) 

#define IPortableDeviceDataStream_Stat(This,pstatstg,grfStatFlag)	\
    ( (This)->lpVtbl -> Stat(This,pstatstg,grfStatFlag) ) 

#define IPortableDeviceDataStream_Clone(This,ppstm)	\
    ( (This)->lpVtbl -> Clone(This,ppstm) ) 


#define IPortableDeviceDataStream_GetObjectID(This,ppszObjectID)	\
    ( (This)->lpVtbl -> GetObjectID(This,ppszObjectID) ) 

#define IPortableDeviceDataStream_Cancel(This)	\
    ( (This)->lpVtbl -> Cancel(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPortableDeviceDataStream_INTERFACE_DEFINED__ */


#ifndef __IPortableDeviceUnitsStream_INTERFACE_DEFINED__
#define __IPortableDeviceUnitsStream_INTERFACE_DEFINED__

/* interface IPortableDeviceUnitsStream */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IPortableDeviceUnitsStream;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5e98025f-bfc4-47a2-9a5f-bc900a507c67")
    IPortableDeviceUnitsStream : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE SeekInUnits( 
            /* [annotation][in] */ 
            _In_  LARGE_INTEGER dlibMove,
            /* [annotation][in] */ 
            _In_  WPD_STREAM_UNITS units,
            /* [annotation][in] */ 
            _In_  DWORD dwOrigin,
            /* [annotation] */ 
            _Out_opt_  ULARGE_INTEGER *plibNewPosition) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Cancel( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IPortableDeviceUnitsStreamVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IPortableDeviceUnitsStream * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IPortableDeviceUnitsStream * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IPortableDeviceUnitsStream * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *SeekInUnits )( 
            IPortableDeviceUnitsStream * This,
            /* [annotation][in] */ 
            _In_  LARGE_INTEGER dlibMove,
            /* [annotation][in] */ 
            _In_  WPD_STREAM_UNITS units,
            /* [annotation][in] */ 
            _In_  DWORD dwOrigin,
            /* [annotation] */ 
            _Out_opt_  ULARGE_INTEGER *plibNewPosition);
        
        HRESULT ( STDMETHODCALLTYPE *Cancel )( 
            __RPC__in IPortableDeviceUnitsStream * This);
        
        END_INTERFACE
    } IPortableDeviceUnitsStreamVtbl;

    interface IPortableDeviceUnitsStream
    {
        CONST_VTBL struct IPortableDeviceUnitsStreamVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPortableDeviceUnitsStream_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPortableDeviceUnitsStream_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPortableDeviceUnitsStream_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPortableDeviceUnitsStream_SeekInUnits(This,dlibMove,units,dwOrigin,plibNewPosition)	\
    ( (This)->lpVtbl -> SeekInUnits(This,dlibMove,units,dwOrigin,plibNewPosition) ) 

#define IPortableDeviceUnitsStream_Cancel(This)	\
    ( (This)->lpVtbl -> Cancel(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT STDMETHODCALLTYPE IPortableDeviceUnitsStream_RemoteSeekInUnits_Proxy( 
    __RPC__in IPortableDeviceUnitsStream * This,
    /* [annotation][in] */ 
    _In_  LARGE_INTEGER dlibMove,
    /* [annotation][in] */ 
    _In_  WPD_STREAM_UNITS units,
    /* [annotation][in] */ 
    _In_  DWORD dwOrigin,
    /* [annotation][out] */ 
    _Out_  ULARGE_INTEGER *plibNewPosition);


void __RPC_STUB IPortableDeviceUnitsStream_RemoteSeekInUnits_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPortableDeviceUnitsStream_INTERFACE_DEFINED__ */


#ifndef __IPortableDevicePropertiesBulk_INTERFACE_DEFINED__
#define __IPortableDevicePropertiesBulk_INTERFACE_DEFINED__

/* interface IPortableDevicePropertiesBulk */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IPortableDevicePropertiesBulk;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("482b05c0-4056-44ed-9e0f-5e23b009da93")
    IPortableDevicePropertiesBulk : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE QueueGetValuesByObjectList( 
            /* [annotation][in] */ 
            _In_  IPortableDevicePropVariantCollection *pObjectIDs,
            /* [annotation][in] */ 
            _In_  IPortableDeviceKeyCollection *pKeys,
            /* [annotation][in] */ 
            _In_  IPortableDevicePropertiesBulkCallback *pCallback,
            /* [annotation][out] */ 
            _Out_  GUID *pContext) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueueGetValuesByObjectFormat( 
            /* [annotation][in] */ 
            _In_  REFGUID pguidObjectFormat,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszParentObjectID,
            /* [annotation][in] */ 
            _In_  const DWORD dwDepth,
            /* [annotation][in] */ 
            _In_  IPortableDeviceKeyCollection *pKeys,
            /* [annotation][in] */ 
            _In_  IPortableDevicePropertiesBulkCallback *pCallback,
            /* [annotation][out] */ 
            _Out_  GUID *pContext) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueueSetValuesByObjectList( 
            /* [annotation][in] */ 
            _In_  IPortableDeviceValuesCollection *pObjectValues,
            /* [annotation][in] */ 
            _In_  IPortableDevicePropertiesBulkCallback *pCallback,
            /* [annotation][out] */ 
            _Out_  GUID *pContext) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Start( 
            /* [annotation][in] */ 
            _In_  REFGUID pContext) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Cancel( 
            /* [annotation][in] */ 
            _In_  REFGUID pContext) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IPortableDevicePropertiesBulkVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IPortableDevicePropertiesBulk * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IPortableDevicePropertiesBulk * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IPortableDevicePropertiesBulk * This);
        
        HRESULT ( STDMETHODCALLTYPE *QueueGetValuesByObjectList )( 
            __RPC__in IPortableDevicePropertiesBulk * This,
            /* [annotation][in] */ 
            _In_  IPortableDevicePropVariantCollection *pObjectIDs,
            /* [annotation][in] */ 
            _In_  IPortableDeviceKeyCollection *pKeys,
            /* [annotation][in] */ 
            _In_  IPortableDevicePropertiesBulkCallback *pCallback,
            /* [annotation][out] */ 
            _Out_  GUID *pContext);
        
        HRESULT ( STDMETHODCALLTYPE *QueueGetValuesByObjectFormat )( 
            __RPC__in IPortableDevicePropertiesBulk * This,
            /* [annotation][in] */ 
            _In_  REFGUID pguidObjectFormat,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszParentObjectID,
            /* [annotation][in] */ 
            _In_  const DWORD dwDepth,
            /* [annotation][in] */ 
            _In_  IPortableDeviceKeyCollection *pKeys,
            /* [annotation][in] */ 
            _In_  IPortableDevicePropertiesBulkCallback *pCallback,
            /* [annotation][out] */ 
            _Out_  GUID *pContext);
        
        HRESULT ( STDMETHODCALLTYPE *QueueSetValuesByObjectList )( 
            __RPC__in IPortableDevicePropertiesBulk * This,
            /* [annotation][in] */ 
            _In_  IPortableDeviceValuesCollection *pObjectValues,
            /* [annotation][in] */ 
            _In_  IPortableDevicePropertiesBulkCallback *pCallback,
            /* [annotation][out] */ 
            _Out_  GUID *pContext);
        
        HRESULT ( STDMETHODCALLTYPE *Start )( 
            __RPC__in IPortableDevicePropertiesBulk * This,
            /* [annotation][in] */ 
            _In_  REFGUID pContext);
        
        HRESULT ( STDMETHODCALLTYPE *Cancel )( 
            __RPC__in IPortableDevicePropertiesBulk * This,
            /* [annotation][in] */ 
            _In_  REFGUID pContext);
        
        END_INTERFACE
    } IPortableDevicePropertiesBulkVtbl;

    interface IPortableDevicePropertiesBulk
    {
        CONST_VTBL struct IPortableDevicePropertiesBulkVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPortableDevicePropertiesBulk_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPortableDevicePropertiesBulk_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPortableDevicePropertiesBulk_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPortableDevicePropertiesBulk_QueueGetValuesByObjectList(This,pObjectIDs,pKeys,pCallback,pContext)	\
    ( (This)->lpVtbl -> QueueGetValuesByObjectList(This,pObjectIDs,pKeys,pCallback,pContext) ) 

#define IPortableDevicePropertiesBulk_QueueGetValuesByObjectFormat(This,pguidObjectFormat,pszParentObjectID,dwDepth,pKeys,pCallback,pContext)	\
    ( (This)->lpVtbl -> QueueGetValuesByObjectFormat(This,pguidObjectFormat,pszParentObjectID,dwDepth,pKeys,pCallback,pContext) ) 

#define IPortableDevicePropertiesBulk_QueueSetValuesByObjectList(This,pObjectValues,pCallback,pContext)	\
    ( (This)->lpVtbl -> QueueSetValuesByObjectList(This,pObjectValues,pCallback,pContext) ) 

#define IPortableDevicePropertiesBulk_Start(This,pContext)	\
    ( (This)->lpVtbl -> Start(This,pContext) ) 

#define IPortableDevicePropertiesBulk_Cancel(This,pContext)	\
    ( (This)->lpVtbl -> Cancel(This,pContext) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPortableDevicePropertiesBulk_INTERFACE_DEFINED__ */


#ifndef __IPortableDevicePropertiesBulkCallback_INTERFACE_DEFINED__
#define __IPortableDevicePropertiesBulkCallback_INTERFACE_DEFINED__

/* interface IPortableDevicePropertiesBulkCallback */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IPortableDevicePropertiesBulkCallback;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9deacb80-11e8-40e3-a9f3-f557986a7845")
    IPortableDevicePropertiesBulkCallback : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnStart( 
            /* [annotation][in] */ 
            _In_  REFGUID pContext) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnProgress( 
            /* [annotation][in] */ 
            _In_  REFGUID pContext,
            /* [annotation][in] */ 
            _In_  IPortableDeviceValuesCollection *pResults) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnEnd( 
            /* [annotation][in] */ 
            _In_  REFGUID pContext,
            /* [annotation][in] */ 
            _In_  HRESULT hrStatus) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IPortableDevicePropertiesBulkCallbackVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IPortableDevicePropertiesBulkCallback * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IPortableDevicePropertiesBulkCallback * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IPortableDevicePropertiesBulkCallback * This);
        
        HRESULT ( STDMETHODCALLTYPE *OnStart )( 
            __RPC__in IPortableDevicePropertiesBulkCallback * This,
            /* [annotation][in] */ 
            _In_  REFGUID pContext);
        
        HRESULT ( STDMETHODCALLTYPE *OnProgress )( 
            __RPC__in IPortableDevicePropertiesBulkCallback * This,
            /* [annotation][in] */ 
            _In_  REFGUID pContext,
            /* [annotation][in] */ 
            _In_  IPortableDeviceValuesCollection *pResults);
        
        HRESULT ( STDMETHODCALLTYPE *OnEnd )( 
            __RPC__in IPortableDevicePropertiesBulkCallback * This,
            /* [annotation][in] */ 
            _In_  REFGUID pContext,
            /* [annotation][in] */ 
            _In_  HRESULT hrStatus);
        
        END_INTERFACE
    } IPortableDevicePropertiesBulkCallbackVtbl;

    interface IPortableDevicePropertiesBulkCallback
    {
        CONST_VTBL struct IPortableDevicePropertiesBulkCallbackVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPortableDevicePropertiesBulkCallback_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPortableDevicePropertiesBulkCallback_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPortableDevicePropertiesBulkCallback_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPortableDevicePropertiesBulkCallback_OnStart(This,pContext)	\
    ( (This)->lpVtbl -> OnStart(This,pContext) ) 

#define IPortableDevicePropertiesBulkCallback_OnProgress(This,pContext,pResults)	\
    ( (This)->lpVtbl -> OnProgress(This,pContext,pResults) ) 

#define IPortableDevicePropertiesBulkCallback_OnEnd(This,pContext,hrStatus)	\
    ( (This)->lpVtbl -> OnEnd(This,pContext,hrStatus) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPortableDevicePropertiesBulkCallback_INTERFACE_DEFINED__ */


#ifndef __IPortableDeviceServiceManager_INTERFACE_DEFINED__
#define __IPortableDeviceServiceManager_INTERFACE_DEFINED__

/* interface IPortableDeviceServiceManager */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IPortableDeviceServiceManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("a8abc4e9-a84a-47a9-80b3-c5d9b172a961")
    IPortableDeviceServiceManager : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetDeviceServices( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPnPDeviceID,
            /* [annotation][in] */ 
            _In_  REFGUID guidServiceCategory,
            /* [annotation][unique][out][in] */ 
            _Inout_  LPWSTR *pServices,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcServices) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDeviceForService( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPnPServiceID,
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszPnPDeviceID) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IPortableDeviceServiceManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IPortableDeviceServiceManager * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IPortableDeviceServiceManager * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IPortableDeviceServiceManager * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetDeviceServices )( 
            __RPC__in IPortableDeviceServiceManager * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPnPDeviceID,
            /* [annotation][in] */ 
            _In_  REFGUID guidServiceCategory,
            /* [annotation][unique][out][in] */ 
            _Inout_  LPWSTR *pServices,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcServices);
        
        HRESULT ( STDMETHODCALLTYPE *GetDeviceForService )( 
            __RPC__in IPortableDeviceServiceManager * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPnPServiceID,
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszPnPDeviceID);
        
        END_INTERFACE
    } IPortableDeviceServiceManagerVtbl;

    interface IPortableDeviceServiceManager
    {
        CONST_VTBL struct IPortableDeviceServiceManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPortableDeviceServiceManager_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPortableDeviceServiceManager_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPortableDeviceServiceManager_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPortableDeviceServiceManager_GetDeviceServices(This,pszPnPDeviceID,guidServiceCategory,pServices,pcServices)	\
    ( (This)->lpVtbl -> GetDeviceServices(This,pszPnPDeviceID,guidServiceCategory,pServices,pcServices) ) 

#define IPortableDeviceServiceManager_GetDeviceForService(This,pszPnPServiceID,ppszPnPDeviceID)	\
    ( (This)->lpVtbl -> GetDeviceForService(This,pszPnPServiceID,ppszPnPDeviceID) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPortableDeviceServiceManager_INTERFACE_DEFINED__ */


#ifndef __IPortableDeviceService_INTERFACE_DEFINED__
#define __IPortableDeviceService_INTERFACE_DEFINED__

/* interface IPortableDeviceService */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IPortableDeviceService;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("d3bd3a44-d7b5-40a9-98b7-2fa4d01dec08")
    IPortableDeviceService : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Open( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPnPServiceID,
            /* [annotation][in] */ 
            _In_  IPortableDeviceValues *pClientInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Capabilities( 
            /* [annotation][out] */ 
            _Out_  IPortableDeviceServiceCapabilities **ppCapabilities) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Content( 
            /* [annotation][out] */ 
            _Out_  IPortableDeviceContent2 **ppContent) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Methods( 
            /* [annotation][out] */ 
            _Out_  IPortableDeviceServiceMethods **ppMethods) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Cancel( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Close( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetServiceObjectID( 
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszServiceObjectID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPnPServiceID( 
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszPnPServiceID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Advise( 
            /* [annotation][in] */ 
            _In_  const DWORD dwFlags,
            /* [annotation][in] */ 
            _In_  IPortableDeviceEventCallback *pCallback,
            /* [annotation][unique][in] */ 
            _In_  IPortableDeviceValues *pParameters,
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszCookie) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Unadvise( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszCookie) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SendCommand( 
            /* [annotation][in] */ 
            _In_  const DWORD dwFlags,
            /* [annotation][in] */ 
            _In_  IPortableDeviceValues *pParameters,
            /* [annotation][out] */ 
            _Out_  IPortableDeviceValues **ppResults) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IPortableDeviceServiceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IPortableDeviceService * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IPortableDeviceService * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IPortableDeviceService * This);
        
        HRESULT ( STDMETHODCALLTYPE *Open )( 
            __RPC__in IPortableDeviceService * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPnPServiceID,
            /* [annotation][in] */ 
            _In_  IPortableDeviceValues *pClientInfo);
        
        HRESULT ( STDMETHODCALLTYPE *Capabilities )( 
            __RPC__in IPortableDeviceService * This,
            /* [annotation][out] */ 
            _Out_  IPortableDeviceServiceCapabilities **ppCapabilities);
        
        HRESULT ( STDMETHODCALLTYPE *Content )( 
            __RPC__in IPortableDeviceService * This,
            /* [annotation][out] */ 
            _Out_  IPortableDeviceContent2 **ppContent);
        
        HRESULT ( STDMETHODCALLTYPE *Methods )( 
            __RPC__in IPortableDeviceService * This,
            /* [annotation][out] */ 
            _Out_  IPortableDeviceServiceMethods **ppMethods);
        
        HRESULT ( STDMETHODCALLTYPE *Cancel )( 
            __RPC__in IPortableDeviceService * This);
        
        HRESULT ( STDMETHODCALLTYPE *Close )( 
            __RPC__in IPortableDeviceService * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetServiceObjectID )( 
            __RPC__in IPortableDeviceService * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszServiceObjectID);
        
        HRESULT ( STDMETHODCALLTYPE *GetPnPServiceID )( 
            __RPC__in IPortableDeviceService * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszPnPServiceID);
        
        HRESULT ( STDMETHODCALLTYPE *Advise )( 
            __RPC__in IPortableDeviceService * This,
            /* [annotation][in] */ 
            _In_  const DWORD dwFlags,
            /* [annotation][in] */ 
            _In_  IPortableDeviceEventCallback *pCallback,
            /* [annotation][unique][in] */ 
            _In_  IPortableDeviceValues *pParameters,
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppszCookie);
        
        HRESULT ( STDMETHODCALLTYPE *Unadvise )( 
            __RPC__in IPortableDeviceService * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszCookie);
        
        HRESULT ( STDMETHODCALLTYPE *SendCommand )( 
            __RPC__in IPortableDeviceService * This,
            /* [annotation][in] */ 
            _In_  const DWORD dwFlags,
            /* [annotation][in] */ 
            _In_  IPortableDeviceValues *pParameters,
            /* [annotation][out] */ 
            _Out_  IPortableDeviceValues **ppResults);
        
        END_INTERFACE
    } IPortableDeviceServiceVtbl;

    interface IPortableDeviceService
    {
        CONST_VTBL struct IPortableDeviceServiceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPortableDeviceService_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPortableDeviceService_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPortableDeviceService_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPortableDeviceService_Open(This,pszPnPServiceID,pClientInfo)	\
    ( (This)->lpVtbl -> Open(This,pszPnPServiceID,pClientInfo) ) 

#define IPortableDeviceService_Capabilities(This,ppCapabilities)	\
    ( (This)->lpVtbl -> Capabilities(This,ppCapabilities) ) 

#define IPortableDeviceService_Content(This,ppContent)	\
    ( (This)->lpVtbl -> Content(This,ppContent) ) 

#define IPortableDeviceService_Methods(This,ppMethods)	\
    ( (This)->lpVtbl -> Methods(This,ppMethods) ) 

#define IPortableDeviceService_Cancel(This)	\
    ( (This)->lpVtbl -> Cancel(This) ) 

#define IPortableDeviceService_Close(This)	\
    ( (This)->lpVtbl -> Close(This) ) 

#define IPortableDeviceService_GetServiceObjectID(This,ppszServiceObjectID)	\
    ( (This)->lpVtbl -> GetServiceObjectID(This,ppszServiceObjectID) ) 

#define IPortableDeviceService_GetPnPServiceID(This,ppszPnPServiceID)	\
    ( (This)->lpVtbl -> GetPnPServiceID(This,ppszPnPServiceID) ) 

#define IPortableDeviceService_Advise(This,dwFlags,pCallback,pParameters,ppszCookie)	\
    ( (This)->lpVtbl -> Advise(This,dwFlags,pCallback,pParameters,ppszCookie) ) 

#define IPortableDeviceService_Unadvise(This,pszCookie)	\
    ( (This)->lpVtbl -> Unadvise(This,pszCookie) ) 

#define IPortableDeviceService_SendCommand(This,dwFlags,pParameters,ppResults)	\
    ( (This)->lpVtbl -> SendCommand(This,dwFlags,pParameters,ppResults) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPortableDeviceService_INTERFACE_DEFINED__ */


#ifndef __IPortableDeviceServiceCapabilities_INTERFACE_DEFINED__
#define __IPortableDeviceServiceCapabilities_INTERFACE_DEFINED__

/* interface IPortableDeviceServiceCapabilities */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IPortableDeviceServiceCapabilities;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("24dbd89d-413e-43e0-bd5b-197f3c56c886")
    IPortableDeviceServiceCapabilities : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetSupportedMethods( 
            /* [annotation][out] */ 
            _Out_  IPortableDevicePropVariantCollection **ppMethods) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSupportedMethodsByFormat( 
            /* [annotation][in] */ 
            _In_  REFGUID Format,
            /* [annotation][out] */ 
            _Out_  IPortableDevicePropVariantCollection **ppMethods) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMethodAttributes( 
            /* [annotation][in] */ 
            _In_  REFGUID Method,
            /* [annotation][out] */ 
            _Out_  IPortableDeviceValues **ppAttributes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMethodParameterAttributes( 
            /* [annotation][in] */ 
            _In_  REFGUID Method,
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY Parameter,
            /* [annotation][out] */ 
            _Out_  IPortableDeviceValues **ppAttributes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSupportedFormats( 
            /* [annotation][out] */ 
            _Out_  IPortableDevicePropVariantCollection **ppFormats) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFormatAttributes( 
            /* [annotation][in] */ 
            _In_  REFGUID Format,
            /* [annotation][out] */ 
            _Out_  IPortableDeviceValues **ppAttributes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSupportedFormatProperties( 
            /* [annotation][in] */ 
            _In_  REFGUID Format,
            /* [annotation][out] */ 
            _Out_  IPortableDeviceKeyCollection **ppKeys) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFormatPropertyAttributes( 
            /* [annotation][in] */ 
            _In_  REFGUID Format,
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY Property,
            /* [annotation][out] */ 
            _Out_  IPortableDeviceValues **ppAttributes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSupportedEvents( 
            /* [annotation][out] */ 
            _Out_  IPortableDevicePropVariantCollection **ppEvents) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEventAttributes( 
            /* [annotation][in] */ 
            _In_  REFGUID Event,
            /* [annotation][out] */ 
            _Out_  IPortableDeviceValues **ppAttributes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEventParameterAttributes( 
            /* [annotation][in] */ 
            _In_  REFGUID Event,
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY Parameter,
            /* [annotation][out] */ 
            _Out_  IPortableDeviceValues **ppAttributes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetInheritedServices( 
            /* [annotation][in] */ 
            _In_  const DWORD dwInheritanceType,
            /* [annotation][out] */ 
            _Out_  IPortableDevicePropVariantCollection **ppServices) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFormatRenderingProfiles( 
            /* [annotation][in] */ 
            _In_  REFGUID Format,
            /* [annotation][out] */ 
            _Out_  IPortableDeviceValuesCollection **ppRenderingProfiles) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSupportedCommands( 
            /* [annotation][out] */ 
            _Out_  IPortableDeviceKeyCollection **ppCommands) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCommandOptions( 
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY Command,
            /* [annotation][out] */ 
            _Out_  IPortableDeviceValues **ppOptions) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Cancel( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IPortableDeviceServiceCapabilitiesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IPortableDeviceServiceCapabilities * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IPortableDeviceServiceCapabilities * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IPortableDeviceServiceCapabilities * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetSupportedMethods )( 
            __RPC__in IPortableDeviceServiceCapabilities * This,
            /* [annotation][out] */ 
            _Out_  IPortableDevicePropVariantCollection **ppMethods);
        
        HRESULT ( STDMETHODCALLTYPE *GetSupportedMethodsByFormat )( 
            __RPC__in IPortableDeviceServiceCapabilities * This,
            /* [annotation][in] */ 
            _In_  REFGUID Format,
            /* [annotation][out] */ 
            _Out_  IPortableDevicePropVariantCollection **ppMethods);
        
        HRESULT ( STDMETHODCALLTYPE *GetMethodAttributes )( 
            __RPC__in IPortableDeviceServiceCapabilities * This,
            /* [annotation][in] */ 
            _In_  REFGUID Method,
            /* [annotation][out] */ 
            _Out_  IPortableDeviceValues **ppAttributes);
        
        HRESULT ( STDMETHODCALLTYPE *GetMethodParameterAttributes )( 
            __RPC__in IPortableDeviceServiceCapabilities * This,
            /* [annotation][in] */ 
            _In_  REFGUID Method,
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY Parameter,
            /* [annotation][out] */ 
            _Out_  IPortableDeviceValues **ppAttributes);
        
        HRESULT ( STDMETHODCALLTYPE *GetSupportedFormats )( 
            __RPC__in IPortableDeviceServiceCapabilities * This,
            /* [annotation][out] */ 
            _Out_  IPortableDevicePropVariantCollection **ppFormats);
        
        HRESULT ( STDMETHODCALLTYPE *GetFormatAttributes )( 
            __RPC__in IPortableDeviceServiceCapabilities * This,
            /* [annotation][in] */ 
            _In_  REFGUID Format,
            /* [annotation][out] */ 
            _Out_  IPortableDeviceValues **ppAttributes);
        
        HRESULT ( STDMETHODCALLTYPE *GetSupportedFormatProperties )( 
            __RPC__in IPortableDeviceServiceCapabilities * This,
            /* [annotation][in] */ 
            _In_  REFGUID Format,
            /* [annotation][out] */ 
            _Out_  IPortableDeviceKeyCollection **ppKeys);
        
        HRESULT ( STDMETHODCALLTYPE *GetFormatPropertyAttributes )( 
            __RPC__in IPortableDeviceServiceCapabilities * This,
            /* [annotation][in] */ 
            _In_  REFGUID Format,
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY Property,
            /* [annotation][out] */ 
            _Out_  IPortableDeviceValues **ppAttributes);
        
        HRESULT ( STDMETHODCALLTYPE *GetSupportedEvents )( 
            __RPC__in IPortableDeviceServiceCapabilities * This,
            /* [annotation][out] */ 
            _Out_  IPortableDevicePropVariantCollection **ppEvents);
        
        HRESULT ( STDMETHODCALLTYPE *GetEventAttributes )( 
            __RPC__in IPortableDeviceServiceCapabilities * This,
            /* [annotation][in] */ 
            _In_  REFGUID Event,
            /* [annotation][out] */ 
            _Out_  IPortableDeviceValues **ppAttributes);
        
        HRESULT ( STDMETHODCALLTYPE *GetEventParameterAttributes )( 
            __RPC__in IPortableDeviceServiceCapabilities * This,
            /* [annotation][in] */ 
            _In_  REFGUID Event,
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY Parameter,
            /* [annotation][out] */ 
            _Out_  IPortableDeviceValues **ppAttributes);
        
        HRESULT ( STDMETHODCALLTYPE *GetInheritedServices )( 
            __RPC__in IPortableDeviceServiceCapabilities * This,
            /* [annotation][in] */ 
            _In_  const DWORD dwInheritanceType,
            /* [annotation][out] */ 
            _Out_  IPortableDevicePropVariantCollection **ppServices);
        
        HRESULT ( STDMETHODCALLTYPE *GetFormatRenderingProfiles )( 
            __RPC__in IPortableDeviceServiceCapabilities * This,
            /* [annotation][in] */ 
            _In_  REFGUID Format,
            /* [annotation][out] */ 
            _Out_  IPortableDeviceValuesCollection **ppRenderingProfiles);
        
        HRESULT ( STDMETHODCALLTYPE *GetSupportedCommands )( 
            __RPC__in IPortableDeviceServiceCapabilities * This,
            /* [annotation][out] */ 
            _Out_  IPortableDeviceKeyCollection **ppCommands);
        
        HRESULT ( STDMETHODCALLTYPE *GetCommandOptions )( 
            __RPC__in IPortableDeviceServiceCapabilities * This,
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY Command,
            /* [annotation][out] */ 
            _Out_  IPortableDeviceValues **ppOptions);
        
        HRESULT ( STDMETHODCALLTYPE *Cancel )( 
            __RPC__in IPortableDeviceServiceCapabilities * This);
        
        END_INTERFACE
    } IPortableDeviceServiceCapabilitiesVtbl;

    interface IPortableDeviceServiceCapabilities
    {
        CONST_VTBL struct IPortableDeviceServiceCapabilitiesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPortableDeviceServiceCapabilities_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPortableDeviceServiceCapabilities_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPortableDeviceServiceCapabilities_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPortableDeviceServiceCapabilities_GetSupportedMethods(This,ppMethods)	\
    ( (This)->lpVtbl -> GetSupportedMethods(This,ppMethods) ) 

#define IPortableDeviceServiceCapabilities_GetSupportedMethodsByFormat(This,Format,ppMethods)	\
    ( (This)->lpVtbl -> GetSupportedMethodsByFormat(This,Format,ppMethods) ) 

#define IPortableDeviceServiceCapabilities_GetMethodAttributes(This,Method,ppAttributes)	\
    ( (This)->lpVtbl -> GetMethodAttributes(This,Method,ppAttributes) ) 

#define IPortableDeviceServiceCapabilities_GetMethodParameterAttributes(This,Method,Parameter,ppAttributes)	\
    ( (This)->lpVtbl -> GetMethodParameterAttributes(This,Method,Parameter,ppAttributes) ) 

#define IPortableDeviceServiceCapabilities_GetSupportedFormats(This,ppFormats)	\
    ( (This)->lpVtbl -> GetSupportedFormats(This,ppFormats) ) 

#define IPortableDeviceServiceCapabilities_GetFormatAttributes(This,Format,ppAttributes)	\
    ( (This)->lpVtbl -> GetFormatAttributes(This,Format,ppAttributes) ) 

#define IPortableDeviceServiceCapabilities_GetSupportedFormatProperties(This,Format,ppKeys)	\
    ( (This)->lpVtbl -> GetSupportedFormatProperties(This,Format,ppKeys) ) 

#define IPortableDeviceServiceCapabilities_GetFormatPropertyAttributes(This,Format,Property,ppAttributes)	\
    ( (This)->lpVtbl -> GetFormatPropertyAttributes(This,Format,Property,ppAttributes) ) 

#define IPortableDeviceServiceCapabilities_GetSupportedEvents(This,ppEvents)	\
    ( (This)->lpVtbl -> GetSupportedEvents(This,ppEvents) ) 

#define IPortableDeviceServiceCapabilities_GetEventAttributes(This,Event,ppAttributes)	\
    ( (This)->lpVtbl -> GetEventAttributes(This,Event,ppAttributes) ) 

#define IPortableDeviceServiceCapabilities_GetEventParameterAttributes(This,Event,Parameter,ppAttributes)	\
    ( (This)->lpVtbl -> GetEventParameterAttributes(This,Event,Parameter,ppAttributes) ) 

#define IPortableDeviceServiceCapabilities_GetInheritedServices(This,dwInheritanceType,ppServices)	\
    ( (This)->lpVtbl -> GetInheritedServices(This,dwInheritanceType,ppServices) ) 

#define IPortableDeviceServiceCapabilities_GetFormatRenderingProfiles(This,Format,ppRenderingProfiles)	\
    ( (This)->lpVtbl -> GetFormatRenderingProfiles(This,Format,ppRenderingProfiles) ) 

#define IPortableDeviceServiceCapabilities_GetSupportedCommands(This,ppCommands)	\
    ( (This)->lpVtbl -> GetSupportedCommands(This,ppCommands) ) 

#define IPortableDeviceServiceCapabilities_GetCommandOptions(This,Command,ppOptions)	\
    ( (This)->lpVtbl -> GetCommandOptions(This,Command,ppOptions) ) 

#define IPortableDeviceServiceCapabilities_Cancel(This)	\
    ( (This)->lpVtbl -> Cancel(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPortableDeviceServiceCapabilities_INTERFACE_DEFINED__ */


#ifndef __IPortableDeviceServiceMethods_INTERFACE_DEFINED__
#define __IPortableDeviceServiceMethods_INTERFACE_DEFINED__

/* interface IPortableDeviceServiceMethods */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IPortableDeviceServiceMethods;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("e20333c9-fd34-412d-a381-cc6f2d820df7")
    IPortableDeviceServiceMethods : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Invoke( 
            /* [annotation][in] */ 
            _In_  REFGUID Method,
            /* [annotation][unique][in] */ 
            _In_  IPortableDeviceValues *pParameters,
            /* [annotation][unique][out][in] */ 
            _Inout_  IPortableDeviceValues **ppResults) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InvokeAsync( 
            /* [annotation][in] */ 
            _In_  REFGUID Method,
            /* [annotation][unique][in] */ 
            _In_  IPortableDeviceValues *pParameters,
            /* [annotation][unique][in] */ 
            _In_  IPortableDeviceServiceMethodCallback *pCallback) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Cancel( 
            /* [annotation][unique][in] */ 
            _In_  IPortableDeviceServiceMethodCallback *pCallback) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IPortableDeviceServiceMethodsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IPortableDeviceServiceMethods * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IPortableDeviceServiceMethods * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IPortableDeviceServiceMethods * This);
        
        HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            __RPC__in IPortableDeviceServiceMethods * This,
            /* [annotation][in] */ 
            _In_  REFGUID Method,
            /* [annotation][unique][in] */ 
            _In_  IPortableDeviceValues *pParameters,
            /* [annotation][unique][out][in] */ 
            _Inout_  IPortableDeviceValues **ppResults);
        
        HRESULT ( STDMETHODCALLTYPE *InvokeAsync )( 
            __RPC__in IPortableDeviceServiceMethods * This,
            /* [annotation][in] */ 
            _In_  REFGUID Method,
            /* [annotation][unique][in] */ 
            _In_  IPortableDeviceValues *pParameters,
            /* [annotation][unique][in] */ 
            _In_  IPortableDeviceServiceMethodCallback *pCallback);
        
        HRESULT ( STDMETHODCALLTYPE *Cancel )( 
            __RPC__in IPortableDeviceServiceMethods * This,
            /* [annotation][unique][in] */ 
            _In_  IPortableDeviceServiceMethodCallback *pCallback);
        
        END_INTERFACE
    } IPortableDeviceServiceMethodsVtbl;

    interface IPortableDeviceServiceMethods
    {
        CONST_VTBL struct IPortableDeviceServiceMethodsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPortableDeviceServiceMethods_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPortableDeviceServiceMethods_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPortableDeviceServiceMethods_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPortableDeviceServiceMethods_Invoke(This,Method,pParameters,ppResults)	\
    ( (This)->lpVtbl -> Invoke(This,Method,pParameters,ppResults) ) 

#define IPortableDeviceServiceMethods_InvokeAsync(This,Method,pParameters,pCallback)	\
    ( (This)->lpVtbl -> InvokeAsync(This,Method,pParameters,pCallback) ) 

#define IPortableDeviceServiceMethods_Cancel(This,pCallback)	\
    ( (This)->lpVtbl -> Cancel(This,pCallback) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPortableDeviceServiceMethods_INTERFACE_DEFINED__ */


#ifndef __IPortableDeviceServiceMethodCallback_INTERFACE_DEFINED__
#define __IPortableDeviceServiceMethodCallback_INTERFACE_DEFINED__

/* interface IPortableDeviceServiceMethodCallback */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IPortableDeviceServiceMethodCallback;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("c424233c-afce-4828-a756-7ed7a2350083")
    IPortableDeviceServiceMethodCallback : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnComplete( 
            /* [annotation][in] */ 
            _In_  HRESULT hrStatus,
            /* [annotation][in] */ 
            _In_  IPortableDeviceValues *pResults) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IPortableDeviceServiceMethodCallbackVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IPortableDeviceServiceMethodCallback * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IPortableDeviceServiceMethodCallback * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IPortableDeviceServiceMethodCallback * This);
        
        HRESULT ( STDMETHODCALLTYPE *OnComplete )( 
            __RPC__in IPortableDeviceServiceMethodCallback * This,
            /* [annotation][in] */ 
            _In_  HRESULT hrStatus,
            /* [annotation][in] */ 
            _In_  IPortableDeviceValues *pResults);
        
        END_INTERFACE
    } IPortableDeviceServiceMethodCallbackVtbl;

    interface IPortableDeviceServiceMethodCallback
    {
        CONST_VTBL struct IPortableDeviceServiceMethodCallbackVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPortableDeviceServiceMethodCallback_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPortableDeviceServiceMethodCallback_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPortableDeviceServiceMethodCallback_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPortableDeviceServiceMethodCallback_OnComplete(This,hrStatus,pResults)	\
    ( (This)->lpVtbl -> OnComplete(This,hrStatus,pResults) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPortableDeviceServiceMethodCallback_INTERFACE_DEFINED__ */


#ifndef __IPortableDeviceServiceActivation_INTERFACE_DEFINED__
#define __IPortableDeviceServiceActivation_INTERFACE_DEFINED__

/* interface IPortableDeviceServiceActivation */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IPortableDeviceServiceActivation;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("e56b0534-d9b9-425c-9b99-75f97cb3d7c8")
    IPortableDeviceServiceActivation : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OpenAsync( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPnPServiceID,
            /* [annotation][in] */ 
            _In_  IPortableDeviceValues *pClientInfo,
            /* [annotation][in] */ 
            _In_  IPortableDeviceServiceOpenCallback *pCallback) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CancelOpenAsync( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IPortableDeviceServiceActivationVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IPortableDeviceServiceActivation * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IPortableDeviceServiceActivation * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IPortableDeviceServiceActivation * This);
        
        HRESULT ( STDMETHODCALLTYPE *OpenAsync )( 
            __RPC__in IPortableDeviceServiceActivation * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPnPServiceID,
            /* [annotation][in] */ 
            _In_  IPortableDeviceValues *pClientInfo,
            /* [annotation][in] */ 
            _In_  IPortableDeviceServiceOpenCallback *pCallback);
        
        HRESULT ( STDMETHODCALLTYPE *CancelOpenAsync )( 
            __RPC__in IPortableDeviceServiceActivation * This);
        
        END_INTERFACE
    } IPortableDeviceServiceActivationVtbl;

    interface IPortableDeviceServiceActivation
    {
        CONST_VTBL struct IPortableDeviceServiceActivationVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPortableDeviceServiceActivation_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPortableDeviceServiceActivation_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPortableDeviceServiceActivation_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPortableDeviceServiceActivation_OpenAsync(This,pszPnPServiceID,pClientInfo,pCallback)	\
    ( (This)->lpVtbl -> OpenAsync(This,pszPnPServiceID,pClientInfo,pCallback) ) 

#define IPortableDeviceServiceActivation_CancelOpenAsync(This)	\
    ( (This)->lpVtbl -> CancelOpenAsync(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPortableDeviceServiceActivation_INTERFACE_DEFINED__ */


#ifndef __IPortableDeviceServiceOpenCallback_INTERFACE_DEFINED__
#define __IPortableDeviceServiceOpenCallback_INTERFACE_DEFINED__

/* interface IPortableDeviceServiceOpenCallback */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IPortableDeviceServiceOpenCallback;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("bced49c8-8efe-41ed-960b-61313abd47a9")
    IPortableDeviceServiceOpenCallback : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnComplete( 
            /* [annotation][in] */ 
            _In_  HRESULT hrStatus) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IPortableDeviceServiceOpenCallbackVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IPortableDeviceServiceOpenCallback * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IPortableDeviceServiceOpenCallback * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IPortableDeviceServiceOpenCallback * This);
        
        HRESULT ( STDMETHODCALLTYPE *OnComplete )( 
            __RPC__in IPortableDeviceServiceOpenCallback * This,
            /* [annotation][in] */ 
            _In_  HRESULT hrStatus);
        
        END_INTERFACE
    } IPortableDeviceServiceOpenCallbackVtbl;

    interface IPortableDeviceServiceOpenCallback
    {
        CONST_VTBL struct IPortableDeviceServiceOpenCallbackVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPortableDeviceServiceOpenCallback_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPortableDeviceServiceOpenCallback_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPortableDeviceServiceOpenCallback_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPortableDeviceServiceOpenCallback_OnComplete(This,hrStatus)	\
    ( (This)->lpVtbl -> OnComplete(This,hrStatus) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPortableDeviceServiceOpenCallback_INTERFACE_DEFINED__ */


#ifndef __IPortableDeviceDispatchFactory_INTERFACE_DEFINED__
#define __IPortableDeviceDispatchFactory_INTERFACE_DEFINED__

/* interface IPortableDeviceDispatchFactory */
/* [uuid][local][object] */ 


EXTERN_C const IID IID_IPortableDeviceDispatchFactory;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5e1eafc3-e3d7-4132-96fa-759c0f9d1e0f")
    IPortableDeviceDispatchFactory : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetDeviceDispatch( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPnPDeviceID,
            /* [annotation][out] */ 
            _Out_  IDispatch **ppDeviceDispatch) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IPortableDeviceDispatchFactoryVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPortableDeviceDispatchFactory * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPortableDeviceDispatchFactory * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPortableDeviceDispatchFactory * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetDeviceDispatch )( 
            IPortableDeviceDispatchFactory * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPnPDeviceID,
            /* [annotation][out] */ 
            _Out_  IDispatch **ppDeviceDispatch);
        
        END_INTERFACE
    } IPortableDeviceDispatchFactoryVtbl;

    interface IPortableDeviceDispatchFactory
    {
        CONST_VTBL struct IPortableDeviceDispatchFactoryVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPortableDeviceDispatchFactory_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPortableDeviceDispatchFactory_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPortableDeviceDispatchFactory_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPortableDeviceDispatchFactory_GetDeviceDispatch(This,pszPnPDeviceID,ppDeviceDispatch)	\
    ( (This)->lpVtbl -> GetDeviceDispatch(This,pszPnPDeviceID,ppDeviceDispatch) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPortableDeviceDispatchFactory_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_portabledeviceapi_0000_0021 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP) */
#pragma endregion
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)


extern RPC_IF_HANDLE __MIDL_itf_portabledeviceapi_0000_0021_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_portabledeviceapi_0000_0021_v0_0_s_ifspec;

#ifndef __IPortableDeviceWebControl_INTERFACE_DEFINED__
#define __IPortableDeviceWebControl_INTERFACE_DEFINED__

/* interface IPortableDeviceWebControl */
/* [uuid][nonextensible][local][dual][object] */ 


EXTERN_C const IID IID_IPortableDeviceWebControl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("94fc7953-5ca1-483a-8aee-df52e7747d00")
    IPortableDeviceWebControl : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDeviceFromId( 
            /* [annotation][in] */ 
            _In_  BSTR deviceId,
            /* [annotation][retval][out] */ 
            _COM_Outptr_  IDispatch **ppDevice) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDeviceFromIdAsync( 
            /* [annotation][in] */ 
            _In_  BSTR deviceId,
            /* [annotation][in] */ 
            _In_  IDispatch *pCompletionHandler,
            /* [annotation][unique][in] */ 
            _In_opt_  IDispatch *pErrorHandler) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IPortableDeviceWebControlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPortableDeviceWebControl * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPortableDeviceWebControl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPortableDeviceWebControl * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IPortableDeviceWebControl * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IPortableDeviceWebControl * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IPortableDeviceWebControl * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][size_is][in] */ 
            _In_reads_(cNames)  LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cNames)  DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IPortableDeviceWebControl * This,
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
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetDeviceFromId )( 
            IPortableDeviceWebControl * This,
            /* [annotation][in] */ 
            _In_  BSTR deviceId,
            /* [annotation][retval][out] */ 
            _COM_Outptr_  IDispatch **ppDevice);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetDeviceFromIdAsync )( 
            IPortableDeviceWebControl * This,
            /* [annotation][in] */ 
            _In_  BSTR deviceId,
            /* [annotation][in] */ 
            _In_  IDispatch *pCompletionHandler,
            /* [annotation][unique][in] */ 
            _In_opt_  IDispatch *pErrorHandler);
        
        END_INTERFACE
    } IPortableDeviceWebControlVtbl;

    interface IPortableDeviceWebControl
    {
        CONST_VTBL struct IPortableDeviceWebControlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPortableDeviceWebControl_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPortableDeviceWebControl_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPortableDeviceWebControl_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPortableDeviceWebControl_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IPortableDeviceWebControl_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IPortableDeviceWebControl_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IPortableDeviceWebControl_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IPortableDeviceWebControl_GetDeviceFromId(This,deviceId,ppDevice)	\
    ( (This)->lpVtbl -> GetDeviceFromId(This,deviceId,ppDevice) ) 

#define IPortableDeviceWebControl_GetDeviceFromIdAsync(This,deviceId,pCompletionHandler,pErrorHandler)	\
    ( (This)->lpVtbl -> GetDeviceFromIdAsync(This,deviceId,pCompletionHandler,pErrorHandler) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPortableDeviceWebControl_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_portabledeviceapi_0000_0022 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_portabledeviceapi_0000_0022_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_portabledeviceapi_0000_0022_v0_0_s_ifspec;


#ifndef __PortableDeviceApiLib_LIBRARY_DEFINED__
#define __PortableDeviceApiLib_LIBRARY_DEFINED__

/* library PortableDeviceApiLib */
/* [helpstring][version][uuid] */ 

#pragma region Application Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP)
#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP) */
#pragma endregion
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion

EXTERN_C const IID LIBID_PortableDeviceApiLib;

EXTERN_C const CLSID CLSID_PortableDevice;

#ifdef __cplusplus

class DECLSPEC_UUID("728a21c5-3d9e-48d7-9810-864848f0f404")
PortableDevice;
#endif

EXTERN_C const CLSID CLSID_PortableDeviceManager;

#ifdef __cplusplus

class DECLSPEC_UUID("0af10cec-2ecd-4b92-9581-34f6ae0637f3")
PortableDeviceManager;
#endif

EXTERN_C const CLSID CLSID_PortableDeviceService;

#ifdef __cplusplus

class DECLSPEC_UUID("ef5db4c2-9312-422c-9152-411cd9c4dd84")
PortableDeviceService;
#endif

EXTERN_C const CLSID CLSID_PortableDeviceDispatchFactory;

#ifdef __cplusplus

class DECLSPEC_UUID("43232233-8338-4658-ae01-0b4ae830b6b0")
PortableDeviceDispatchFactory;
#endif

EXTERN_C const CLSID CLSID_PortableDeviceFTM;

#ifdef __cplusplus

class DECLSPEC_UUID("f7c0039a-4762-488a-b4b3-760ef9a1ba9b")
PortableDeviceFTM;
#endif

EXTERN_C const CLSID CLSID_PortableDeviceServiceFTM;

#ifdef __cplusplus

class DECLSPEC_UUID("1649b154-c794-497a-9b03-f3f0121302f3")
PortableDeviceServiceFTM;
#endif

EXTERN_C const CLSID CLSID_PortableDeviceWebControl;

#ifdef __cplusplus

class DECLSPEC_UUID("186dd02c-2dec-41b5-a7d4-b59056fade51")
PortableDeviceWebControl;
#endif
#endif /* __PortableDeviceApiLib_LIBRARY_DEFINED__ */

/* interface __MIDL_itf_portabledeviceapi_0000_0023 */
/* [local] */ 

#endif  // (_WIN32_WINNT >= 0x0501)


extern RPC_IF_HANDLE __MIDL_itf_portabledeviceapi_0000_0023_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_portabledeviceapi_0000_0023_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* [local] */ HRESULT STDMETHODCALLTYPE IPortableDeviceUnitsStream_SeekInUnits_Proxy( 
    IPortableDeviceUnitsStream * This,
    /* [annotation][in] */ 
    _In_  LARGE_INTEGER dlibMove,
    /* [annotation][in] */ 
    _In_  WPD_STREAM_UNITS units,
    /* [annotation][in] */ 
    _In_  DWORD dwOrigin,
    /* [annotation] */ 
    _Out_opt_  ULARGE_INTEGER *plibNewPosition);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IPortableDeviceUnitsStream_SeekInUnits_Stub( 
    __RPC__in IPortableDeviceUnitsStream * This,
    /* [annotation][in] */ 
    _In_  LARGE_INTEGER dlibMove,
    /* [annotation][in] */ 
    _In_  WPD_STREAM_UNITS units,
    /* [annotation][in] */ 
    _In_  DWORD dwOrigin,
    /* [annotation][out] */ 
    _Out_  ULARGE_INTEGER *plibNewPosition);



/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


