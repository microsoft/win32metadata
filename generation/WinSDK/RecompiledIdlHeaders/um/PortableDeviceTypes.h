

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

#ifndef __portabledevicetypes_h__
#define __portabledevicetypes_h__

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

#ifndef __IWpdSerializer_FWD_DEFINED__
#define __IWpdSerializer_FWD_DEFINED__
typedef interface IWpdSerializer IWpdSerializer;

#endif 	/* __IWpdSerializer_FWD_DEFINED__ */


#ifndef __IPortableDeviceValues_FWD_DEFINED__
#define __IPortableDeviceValues_FWD_DEFINED__
typedef interface IPortableDeviceValues IPortableDeviceValues;

#endif 	/* __IPortableDeviceValues_FWD_DEFINED__ */


#ifndef __IPortableDeviceKeyCollection_FWD_DEFINED__
#define __IPortableDeviceKeyCollection_FWD_DEFINED__
typedef interface IPortableDeviceKeyCollection IPortableDeviceKeyCollection;

#endif 	/* __IPortableDeviceKeyCollection_FWD_DEFINED__ */


#ifndef __IPortableDevicePropVariantCollection_FWD_DEFINED__
#define __IPortableDevicePropVariantCollection_FWD_DEFINED__
typedef interface IPortableDevicePropVariantCollection IPortableDevicePropVariantCollection;

#endif 	/* __IPortableDevicePropVariantCollection_FWD_DEFINED__ */


#ifndef __IPortableDeviceValuesCollection_FWD_DEFINED__
#define __IPortableDeviceValuesCollection_FWD_DEFINED__
typedef interface IPortableDeviceValuesCollection IPortableDeviceValuesCollection;

#endif 	/* __IPortableDeviceValuesCollection_FWD_DEFINED__ */


#ifndef __WpdSerializer_FWD_DEFINED__
#define __WpdSerializer_FWD_DEFINED__

#ifdef __cplusplus
typedef class WpdSerializer WpdSerializer;
#else
typedef struct WpdSerializer WpdSerializer;
#endif /* __cplusplus */

#endif 	/* __WpdSerializer_FWD_DEFINED__ */


#ifndef __PortableDeviceValues_FWD_DEFINED__
#define __PortableDeviceValues_FWD_DEFINED__

#ifdef __cplusplus
typedef class PortableDeviceValues PortableDeviceValues;
#else
typedef struct PortableDeviceValues PortableDeviceValues;
#endif /* __cplusplus */

#endif 	/* __PortableDeviceValues_FWD_DEFINED__ */


#ifndef __PortableDeviceKeyCollection_FWD_DEFINED__
#define __PortableDeviceKeyCollection_FWD_DEFINED__

#ifdef __cplusplus
typedef class PortableDeviceKeyCollection PortableDeviceKeyCollection;
#else
typedef struct PortableDeviceKeyCollection PortableDeviceKeyCollection;
#endif /* __cplusplus */

#endif 	/* __PortableDeviceKeyCollection_FWD_DEFINED__ */


#ifndef __PortableDevicePropVariantCollection_FWD_DEFINED__
#define __PortableDevicePropVariantCollection_FWD_DEFINED__

#ifdef __cplusplus
typedef class PortableDevicePropVariantCollection PortableDevicePropVariantCollection;
#else
typedef struct PortableDevicePropVariantCollection PortableDevicePropVariantCollection;
#endif /* __cplusplus */

#endif 	/* __PortableDevicePropVariantCollection_FWD_DEFINED__ */


#ifndef __PortableDeviceValuesCollection_FWD_DEFINED__
#define __PortableDeviceValuesCollection_FWD_DEFINED__

#ifdef __cplusplus
typedef class PortableDeviceValuesCollection PortableDeviceValuesCollection;
#else
typedef struct PortableDeviceValuesCollection PortableDeviceValuesCollection;
#endif /* __cplusplus */

#endif 	/* __PortableDeviceValuesCollection_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "propsys.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_portabledevicetypes_0000_0000 */
/* [local] */ 

#include <winapifamily.h>
#if (_WIN32_WINNT >= 0x0501) // XP and later
#pragma region Application Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP)
typedef 
enum tagWPD_STREAM_UNITS
    {
        WPD_STREAM_UNITS_BYTES	= 0L,
        WPD_STREAM_UNITS_FRAMES	= 0x1L,
        WPD_STREAM_UNITS_ROWS	= 0x2L,
        WPD_STREAM_UNITS_MILLISECONDS	= 0x4L,
        WPD_STREAM_UNITS_MICROSECONDS	= 0x8L
    } 	WPD_STREAM_UNITS;






#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP) */
#pragma endregion
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)


extern RPC_IF_HANDLE __MIDL_itf_portabledevicetypes_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_portabledevicetypes_0000_0000_v0_0_s_ifspec;

#ifndef __IWpdSerializer_INTERFACE_DEFINED__
#define __IWpdSerializer_INTERFACE_DEFINED__

/* interface IWpdSerializer */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWpdSerializer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("b32f4002-bb27-45ff-af4f-06631c1e8dad")
    IWpdSerializer : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetIPortableDeviceValuesFromBuffer( 
            /* [annotation][size_is][in] */ 
            _In_reads_(dwInputBufferLength)  BYTE *pBuffer,
            /* [annotation][in] */ 
            _In_  DWORD dwInputBufferLength,
            /* [annotation][out] */ 
            _Out_  IPortableDeviceValues **ppParams) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE WriteIPortableDeviceValuesToBuffer( 
            /* [annotation][in] */ 
            _In_  DWORD dwOutputBufferLength,
            /* [annotation][in] */ 
            _In_  IPortableDeviceValues *pResults,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(dwOutputBufferLength,*pdwBytesWritten)  BYTE *pBuffer,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwBytesWritten) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBufferFromIPortableDeviceValues( 
            /* [annotation][in] */ 
            _In_  IPortableDeviceValues *pSource,
            /* [annotation][size_is][size_is][out] */ 
            _Out_writes_(*pdwBufferSize)  BYTE **ppBuffer,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwBufferSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSerializedSize( 
            /* [annotation][in] */ 
            _In_  IPortableDeviceValues *pSource,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwSize) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWpdSerializerVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IWpdSerializer * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IWpdSerializer * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IWpdSerializer * This);
        
        DECLSPEC_XFGVIRT(IWpdSerializer, GetIPortableDeviceValuesFromBuffer)
        HRESULT ( STDMETHODCALLTYPE *GetIPortableDeviceValuesFromBuffer )( 
            __RPC__in IWpdSerializer * This,
            /* [annotation][size_is][in] */ 
            _In_reads_(dwInputBufferLength)  BYTE *pBuffer,
            /* [annotation][in] */ 
            _In_  DWORD dwInputBufferLength,
            /* [annotation][out] */ 
            _Out_  IPortableDeviceValues **ppParams);
        
        DECLSPEC_XFGVIRT(IWpdSerializer, WriteIPortableDeviceValuesToBuffer)
        HRESULT ( STDMETHODCALLTYPE *WriteIPortableDeviceValuesToBuffer )( 
            __RPC__in IWpdSerializer * This,
            /* [annotation][in] */ 
            _In_  DWORD dwOutputBufferLength,
            /* [annotation][in] */ 
            _In_  IPortableDeviceValues *pResults,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(dwOutputBufferLength,*pdwBytesWritten)  BYTE *pBuffer,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwBytesWritten);
        
        DECLSPEC_XFGVIRT(IWpdSerializer, GetBufferFromIPortableDeviceValues)
        HRESULT ( STDMETHODCALLTYPE *GetBufferFromIPortableDeviceValues )( 
            __RPC__in IWpdSerializer * This,
            /* [annotation][in] */ 
            _In_  IPortableDeviceValues *pSource,
            /* [annotation][size_is][size_is][out] */ 
            _Out_writes_(*pdwBufferSize)  BYTE **ppBuffer,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwBufferSize);
        
        DECLSPEC_XFGVIRT(IWpdSerializer, GetSerializedSize)
        HRESULT ( STDMETHODCALLTYPE *GetSerializedSize )( 
            __RPC__in IWpdSerializer * This,
            /* [annotation][in] */ 
            _In_  IPortableDeviceValues *pSource,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwSize);
        
        END_INTERFACE
    } IWpdSerializerVtbl;

    interface IWpdSerializer
    {
        CONST_VTBL struct IWpdSerializerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWpdSerializer_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWpdSerializer_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWpdSerializer_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWpdSerializer_GetIPortableDeviceValuesFromBuffer(This,pBuffer,dwInputBufferLength,ppParams)	\
    ( (This)->lpVtbl -> GetIPortableDeviceValuesFromBuffer(This,pBuffer,dwInputBufferLength,ppParams) ) 

#define IWpdSerializer_WriteIPortableDeviceValuesToBuffer(This,dwOutputBufferLength,pResults,pBuffer,pdwBytesWritten)	\
    ( (This)->lpVtbl -> WriteIPortableDeviceValuesToBuffer(This,dwOutputBufferLength,pResults,pBuffer,pdwBytesWritten) ) 

#define IWpdSerializer_GetBufferFromIPortableDeviceValues(This,pSource,ppBuffer,pdwBufferSize)	\
    ( (This)->lpVtbl -> GetBufferFromIPortableDeviceValues(This,pSource,ppBuffer,pdwBufferSize) ) 

#define IWpdSerializer_GetSerializedSize(This,pSource,pdwSize)	\
    ( (This)->lpVtbl -> GetSerializedSize(This,pSource,pdwSize) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWpdSerializer_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_portabledevicetypes_0000_0001 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP) && !WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
#define IPropertyStore IUnknown
#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP) && !WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma region Application Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP)


extern RPC_IF_HANDLE __MIDL_itf_portabledevicetypes_0000_0001_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_portabledevicetypes_0000_0001_v0_0_s_ifspec;

#ifndef __IPortableDeviceValues_INTERFACE_DEFINED__
#define __IPortableDeviceValues_INTERFACE_DEFINED__

/* interface IPortableDeviceValues */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IPortableDeviceValues;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6848f6f2-3155-4f86-b6f5-263eeeab3143")
    IPortableDeviceValues : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetCount( 
            /* [annotation][in] */ 
            _In_  DWORD *pcelt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAt( 
            /* [annotation][in] */ 
            _In_  const DWORD index,
            /* [annotation][unique][out][in] */ 
            _Inout_  PROPERTYKEY *pKey,
            /* [annotation][unique][out][in] */ 
            _Inout_  PROPVARIANT *pValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetValue( 
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY key,
            /* [annotation][in] */ 
            _In_  const PROPVARIANT *pValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetValue( 
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY key,
            /* [annotation][out] */ 
            _Out_  PROPVARIANT *pValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetStringValue( 
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY key,
            /* [annotation][in] */ 
            _In_  LPCWSTR Value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStringValue( 
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY key,
            /* [annotation][out] */ 
            _Out_  LPWSTR *pValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetUnsignedIntegerValue( 
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY key,
            /* [annotation][in] */ 
            _In_  const ULONG Value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetUnsignedIntegerValue( 
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY key,
            /* [annotation][out] */ 
            _Out_  ULONG *pValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetSignedIntegerValue( 
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY key,
            /* [annotation][in] */ 
            _In_  const LONG Value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSignedIntegerValue( 
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY key,
            /* [annotation][out] */ 
            _Out_  LONG *pValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetUnsignedLargeIntegerValue( 
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY key,
            /* [annotation][in] */ 
            _In_  const ULONGLONG Value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetUnsignedLargeIntegerValue( 
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY key,
            /* [annotation][out] */ 
            _Out_  ULONGLONG *pValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetSignedLargeIntegerValue( 
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY key,
            /* [annotation][in] */ 
            _In_  const LONGLONG Value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSignedLargeIntegerValue( 
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY key,
            /* [annotation][out] */ 
            _Out_  LONGLONG *pValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetFloatValue( 
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY key,
            /* [annotation][in] */ 
            _In_  const FLOAT Value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFloatValue( 
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY key,
            /* [annotation][out] */ 
            _Out_  FLOAT *pValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetErrorValue( 
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY key,
            /* [annotation][in] */ 
            _In_  const HRESULT Value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetErrorValue( 
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY key,
            /* [annotation][out] */ 
            _Out_  HRESULT *pValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetKeyValue( 
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY key,
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY Value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetKeyValue( 
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY key,
            /* [annotation][out] */ 
            _Out_  PROPERTYKEY *pValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetBoolValue( 
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY key,
            /* [annotation][in] */ 
            _In_  const BOOL Value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBoolValue( 
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY key,
            /* [annotation][out] */ 
            _Out_  BOOL *pValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetIUnknownValue( 
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY key,
            /* [annotation][in] */ 
            _In_  IUnknown *pValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetIUnknownValue( 
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY key,
            /* [annotation][out] */ 
            _Out_  IUnknown **ppValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetGuidValue( 
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY key,
            /* [annotation][in] */ 
            _In_  REFGUID Value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetGuidValue( 
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY key,
            /* [annotation][out] */ 
            _Out_  GUID *pValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetBufferValue( 
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY key,
            /* [annotation][size_is][in] */ 
            _In_reads_(cbValue)  BYTE *pValue,
            /* [annotation][in] */ 
            _In_  DWORD cbValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBufferValue( 
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY key,
            /* [annotation][size_is][size_is][out] */ 
            _Out_writes_(*pcbValue)  BYTE **ppValue,
            /* [annotation][out] */ 
            _Out_  DWORD *pcbValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetIPortableDeviceValuesValue( 
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY key,
            /* [annotation][in] */ 
            _In_  IPortableDeviceValues *pValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetIPortableDeviceValuesValue( 
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY key,
            /* [annotation][out] */ 
            _Out_  IPortableDeviceValues **ppValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetIPortableDevicePropVariantCollectionValue( 
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY key,
            /* [annotation][in] */ 
            _In_  IPortableDevicePropVariantCollection *pValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetIPortableDevicePropVariantCollectionValue( 
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY key,
            /* [annotation][out] */ 
            _Out_  IPortableDevicePropVariantCollection **ppValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetIPortableDeviceKeyCollectionValue( 
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY key,
            /* [annotation][in] */ 
            _In_  IPortableDeviceKeyCollection *pValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetIPortableDeviceKeyCollectionValue( 
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY key,
            /* [annotation][out] */ 
            _Out_  IPortableDeviceKeyCollection **ppValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetIPortableDeviceValuesCollectionValue( 
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY key,
            /* [annotation][in] */ 
            _In_  IPortableDeviceValuesCollection *pValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetIPortableDeviceValuesCollectionValue( 
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY key,
            /* [annotation][out] */ 
            _Out_  IPortableDeviceValuesCollection **ppValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveValue( 
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY key) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CopyValuesFromPropertyStore( 
            /* [annotation][in] */ 
            _In_  IPropertyStore *pStore) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CopyValuesToPropertyStore( 
            /* [annotation][in] */ 
            _In_  IPropertyStore *pStore) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clear( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IPortableDeviceValuesVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IPortableDeviceValues * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IPortableDeviceValues * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IPortableDeviceValues * This);
        
        DECLSPEC_XFGVIRT(IPortableDeviceValues, GetCount)
        HRESULT ( STDMETHODCALLTYPE *GetCount )( 
            __RPC__in IPortableDeviceValues * This,
            /* [annotation][in] */ 
            _In_  DWORD *pcelt);
        
        DECLSPEC_XFGVIRT(IPortableDeviceValues, GetAt)
        HRESULT ( STDMETHODCALLTYPE *GetAt )( 
            __RPC__in IPortableDeviceValues * This,
            /* [annotation][in] */ 
            _In_  const DWORD index,
            /* [annotation][unique][out][in] */ 
            _Inout_  PROPERTYKEY *pKey,
            /* [annotation][unique][out][in] */ 
            _Inout_  PROPVARIANT *pValue);
        
        DECLSPEC_XFGVIRT(IPortableDeviceValues, SetValue)
        HRESULT ( STDMETHODCALLTYPE *SetValue )( 
            __RPC__in IPortableDeviceValues * This,
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY key,
            /* [annotation][in] */ 
            _In_  const PROPVARIANT *pValue);
        
        DECLSPEC_XFGVIRT(IPortableDeviceValues, GetValue)
        HRESULT ( STDMETHODCALLTYPE *GetValue )( 
            __RPC__in IPortableDeviceValues * This,
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY key,
            /* [annotation][out] */ 
            _Out_  PROPVARIANT *pValue);
        
        DECLSPEC_XFGVIRT(IPortableDeviceValues, SetStringValue)
        HRESULT ( STDMETHODCALLTYPE *SetStringValue )( 
            __RPC__in IPortableDeviceValues * This,
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY key,
            /* [annotation][in] */ 
            _In_  LPCWSTR Value);
        
        DECLSPEC_XFGVIRT(IPortableDeviceValues, GetStringValue)
        HRESULT ( STDMETHODCALLTYPE *GetStringValue )( 
            __RPC__in IPortableDeviceValues * This,
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY key,
            /* [annotation][out] */ 
            _Out_  LPWSTR *pValue);
        
        DECLSPEC_XFGVIRT(IPortableDeviceValues, SetUnsignedIntegerValue)
        HRESULT ( STDMETHODCALLTYPE *SetUnsignedIntegerValue )( 
            __RPC__in IPortableDeviceValues * This,
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY key,
            /* [annotation][in] */ 
            _In_  const ULONG Value);
        
        DECLSPEC_XFGVIRT(IPortableDeviceValues, GetUnsignedIntegerValue)
        HRESULT ( STDMETHODCALLTYPE *GetUnsignedIntegerValue )( 
            __RPC__in IPortableDeviceValues * This,
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY key,
            /* [annotation][out] */ 
            _Out_  ULONG *pValue);
        
        DECLSPEC_XFGVIRT(IPortableDeviceValues, SetSignedIntegerValue)
        HRESULT ( STDMETHODCALLTYPE *SetSignedIntegerValue )( 
            __RPC__in IPortableDeviceValues * This,
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY key,
            /* [annotation][in] */ 
            _In_  const LONG Value);
        
        DECLSPEC_XFGVIRT(IPortableDeviceValues, GetSignedIntegerValue)
        HRESULT ( STDMETHODCALLTYPE *GetSignedIntegerValue )( 
            __RPC__in IPortableDeviceValues * This,
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY key,
            /* [annotation][out] */ 
            _Out_  LONG *pValue);
        
        DECLSPEC_XFGVIRT(IPortableDeviceValues, SetUnsignedLargeIntegerValue)
        HRESULT ( STDMETHODCALLTYPE *SetUnsignedLargeIntegerValue )( 
            __RPC__in IPortableDeviceValues * This,
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY key,
            /* [annotation][in] */ 
            _In_  const ULONGLONG Value);
        
        DECLSPEC_XFGVIRT(IPortableDeviceValues, GetUnsignedLargeIntegerValue)
        HRESULT ( STDMETHODCALLTYPE *GetUnsignedLargeIntegerValue )( 
            __RPC__in IPortableDeviceValues * This,
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY key,
            /* [annotation][out] */ 
            _Out_  ULONGLONG *pValue);
        
        DECLSPEC_XFGVIRT(IPortableDeviceValues, SetSignedLargeIntegerValue)
        HRESULT ( STDMETHODCALLTYPE *SetSignedLargeIntegerValue )( 
            __RPC__in IPortableDeviceValues * This,
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY key,
            /* [annotation][in] */ 
            _In_  const LONGLONG Value);
        
        DECLSPEC_XFGVIRT(IPortableDeviceValues, GetSignedLargeIntegerValue)
        HRESULT ( STDMETHODCALLTYPE *GetSignedLargeIntegerValue )( 
            __RPC__in IPortableDeviceValues * This,
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY key,
            /* [annotation][out] */ 
            _Out_  LONGLONG *pValue);
        
        DECLSPEC_XFGVIRT(IPortableDeviceValues, SetFloatValue)
        HRESULT ( STDMETHODCALLTYPE *SetFloatValue )( 
            __RPC__in IPortableDeviceValues * This,
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY key,
            /* [annotation][in] */ 
            _In_  const FLOAT Value);
        
        DECLSPEC_XFGVIRT(IPortableDeviceValues, GetFloatValue)
        HRESULT ( STDMETHODCALLTYPE *GetFloatValue )( 
            __RPC__in IPortableDeviceValues * This,
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY key,
            /* [annotation][out] */ 
            _Out_  FLOAT *pValue);
        
        DECLSPEC_XFGVIRT(IPortableDeviceValues, SetErrorValue)
        HRESULT ( STDMETHODCALLTYPE *SetErrorValue )( 
            __RPC__in IPortableDeviceValues * This,
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY key,
            /* [annotation][in] */ 
            _In_  const HRESULT Value);
        
        DECLSPEC_XFGVIRT(IPortableDeviceValues, GetErrorValue)
        HRESULT ( STDMETHODCALLTYPE *GetErrorValue )( 
            __RPC__in IPortableDeviceValues * This,
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY key,
            /* [annotation][out] */ 
            _Out_  HRESULT *pValue);
        
        DECLSPEC_XFGVIRT(IPortableDeviceValues, SetKeyValue)
        HRESULT ( STDMETHODCALLTYPE *SetKeyValue )( 
            __RPC__in IPortableDeviceValues * This,
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY key,
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY Value);
        
        DECLSPEC_XFGVIRT(IPortableDeviceValues, GetKeyValue)
        HRESULT ( STDMETHODCALLTYPE *GetKeyValue )( 
            __RPC__in IPortableDeviceValues * This,
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY key,
            /* [annotation][out] */ 
            _Out_  PROPERTYKEY *pValue);
        
        DECLSPEC_XFGVIRT(IPortableDeviceValues, SetBoolValue)
        HRESULT ( STDMETHODCALLTYPE *SetBoolValue )( 
            __RPC__in IPortableDeviceValues * This,
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY key,
            /* [annotation][in] */ 
            _In_  const BOOL Value);
        
        DECLSPEC_XFGVIRT(IPortableDeviceValues, GetBoolValue)
        HRESULT ( STDMETHODCALLTYPE *GetBoolValue )( 
            __RPC__in IPortableDeviceValues * This,
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY key,
            /* [annotation][out] */ 
            _Out_  BOOL *pValue);
        
        DECLSPEC_XFGVIRT(IPortableDeviceValues, SetIUnknownValue)
        HRESULT ( STDMETHODCALLTYPE *SetIUnknownValue )( 
            __RPC__in IPortableDeviceValues * This,
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY key,
            /* [annotation][in] */ 
            _In_  IUnknown *pValue);
        
        DECLSPEC_XFGVIRT(IPortableDeviceValues, GetIUnknownValue)
        HRESULT ( STDMETHODCALLTYPE *GetIUnknownValue )( 
            __RPC__in IPortableDeviceValues * This,
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY key,
            /* [annotation][out] */ 
            _Out_  IUnknown **ppValue);
        
        DECLSPEC_XFGVIRT(IPortableDeviceValues, SetGuidValue)
        HRESULT ( STDMETHODCALLTYPE *SetGuidValue )( 
            __RPC__in IPortableDeviceValues * This,
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY key,
            /* [annotation][in] */ 
            _In_  REFGUID Value);
        
        DECLSPEC_XFGVIRT(IPortableDeviceValues, GetGuidValue)
        HRESULT ( STDMETHODCALLTYPE *GetGuidValue )( 
            __RPC__in IPortableDeviceValues * This,
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY key,
            /* [annotation][out] */ 
            _Out_  GUID *pValue);
        
        DECLSPEC_XFGVIRT(IPortableDeviceValues, SetBufferValue)
        HRESULT ( STDMETHODCALLTYPE *SetBufferValue )( 
            __RPC__in IPortableDeviceValues * This,
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY key,
            /* [annotation][size_is][in] */ 
            _In_reads_(cbValue)  BYTE *pValue,
            /* [annotation][in] */ 
            _In_  DWORD cbValue);
        
        DECLSPEC_XFGVIRT(IPortableDeviceValues, GetBufferValue)
        HRESULT ( STDMETHODCALLTYPE *GetBufferValue )( 
            __RPC__in IPortableDeviceValues * This,
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY key,
            /* [annotation][size_is][size_is][out] */ 
            _Out_writes_(*pcbValue)  BYTE **ppValue,
            /* [annotation][out] */ 
            _Out_  DWORD *pcbValue);
        
        DECLSPEC_XFGVIRT(IPortableDeviceValues, SetIPortableDeviceValuesValue)
        HRESULT ( STDMETHODCALLTYPE *SetIPortableDeviceValuesValue )( 
            __RPC__in IPortableDeviceValues * This,
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY key,
            /* [annotation][in] */ 
            _In_  IPortableDeviceValues *pValue);
        
        DECLSPEC_XFGVIRT(IPortableDeviceValues, GetIPortableDeviceValuesValue)
        HRESULT ( STDMETHODCALLTYPE *GetIPortableDeviceValuesValue )( 
            __RPC__in IPortableDeviceValues * This,
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY key,
            /* [annotation][out] */ 
            _Out_  IPortableDeviceValues **ppValue);
        
        DECLSPEC_XFGVIRT(IPortableDeviceValues, SetIPortableDevicePropVariantCollectionValue)
        HRESULT ( STDMETHODCALLTYPE *SetIPortableDevicePropVariantCollectionValue )( 
            __RPC__in IPortableDeviceValues * This,
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY key,
            /* [annotation][in] */ 
            _In_  IPortableDevicePropVariantCollection *pValue);
        
        DECLSPEC_XFGVIRT(IPortableDeviceValues, GetIPortableDevicePropVariantCollectionValue)
        HRESULT ( STDMETHODCALLTYPE *GetIPortableDevicePropVariantCollectionValue )( 
            __RPC__in IPortableDeviceValues * This,
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY key,
            /* [annotation][out] */ 
            _Out_  IPortableDevicePropVariantCollection **ppValue);
        
        DECLSPEC_XFGVIRT(IPortableDeviceValues, SetIPortableDeviceKeyCollectionValue)
        HRESULT ( STDMETHODCALLTYPE *SetIPortableDeviceKeyCollectionValue )( 
            __RPC__in IPortableDeviceValues * This,
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY key,
            /* [annotation][in] */ 
            _In_  IPortableDeviceKeyCollection *pValue);
        
        DECLSPEC_XFGVIRT(IPortableDeviceValues, GetIPortableDeviceKeyCollectionValue)
        HRESULT ( STDMETHODCALLTYPE *GetIPortableDeviceKeyCollectionValue )( 
            __RPC__in IPortableDeviceValues * This,
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY key,
            /* [annotation][out] */ 
            _Out_  IPortableDeviceKeyCollection **ppValue);
        
        DECLSPEC_XFGVIRT(IPortableDeviceValues, SetIPortableDeviceValuesCollectionValue)
        HRESULT ( STDMETHODCALLTYPE *SetIPortableDeviceValuesCollectionValue )( 
            __RPC__in IPortableDeviceValues * This,
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY key,
            /* [annotation][in] */ 
            _In_  IPortableDeviceValuesCollection *pValue);
        
        DECLSPEC_XFGVIRT(IPortableDeviceValues, GetIPortableDeviceValuesCollectionValue)
        HRESULT ( STDMETHODCALLTYPE *GetIPortableDeviceValuesCollectionValue )( 
            __RPC__in IPortableDeviceValues * This,
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY key,
            /* [annotation][out] */ 
            _Out_  IPortableDeviceValuesCollection **ppValue);
        
        DECLSPEC_XFGVIRT(IPortableDeviceValues, RemoveValue)
        HRESULT ( STDMETHODCALLTYPE *RemoveValue )( 
            __RPC__in IPortableDeviceValues * This,
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY key);
        
        DECLSPEC_XFGVIRT(IPortableDeviceValues, CopyValuesFromPropertyStore)
        HRESULT ( STDMETHODCALLTYPE *CopyValuesFromPropertyStore )( 
            __RPC__in IPortableDeviceValues * This,
            /* [annotation][in] */ 
            _In_  IPropertyStore *pStore);
        
        DECLSPEC_XFGVIRT(IPortableDeviceValues, CopyValuesToPropertyStore)
        HRESULT ( STDMETHODCALLTYPE *CopyValuesToPropertyStore )( 
            __RPC__in IPortableDeviceValues * This,
            /* [annotation][in] */ 
            _In_  IPropertyStore *pStore);
        
        DECLSPEC_XFGVIRT(IPortableDeviceValues, Clear)
        HRESULT ( STDMETHODCALLTYPE *Clear )( 
            __RPC__in IPortableDeviceValues * This);
        
        END_INTERFACE
    } IPortableDeviceValuesVtbl;

    interface IPortableDeviceValues
    {
        CONST_VTBL struct IPortableDeviceValuesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPortableDeviceValues_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPortableDeviceValues_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPortableDeviceValues_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPortableDeviceValues_GetCount(This,pcelt)	\
    ( (This)->lpVtbl -> GetCount(This,pcelt) ) 

#define IPortableDeviceValues_GetAt(This,index,pKey,pValue)	\
    ( (This)->lpVtbl -> GetAt(This,index,pKey,pValue) ) 

#define IPortableDeviceValues_SetValue(This,key,pValue)	\
    ( (This)->lpVtbl -> SetValue(This,key,pValue) ) 

#define IPortableDeviceValues_GetValue(This,key,pValue)	\
    ( (This)->lpVtbl -> GetValue(This,key,pValue) ) 

#define IPortableDeviceValues_SetStringValue(This,key,Value)	\
    ( (This)->lpVtbl -> SetStringValue(This,key,Value) ) 

#define IPortableDeviceValues_GetStringValue(This,key,pValue)	\
    ( (This)->lpVtbl -> GetStringValue(This,key,pValue) ) 

#define IPortableDeviceValues_SetUnsignedIntegerValue(This,key,Value)	\
    ( (This)->lpVtbl -> SetUnsignedIntegerValue(This,key,Value) ) 

#define IPortableDeviceValues_GetUnsignedIntegerValue(This,key,pValue)	\
    ( (This)->lpVtbl -> GetUnsignedIntegerValue(This,key,pValue) ) 

#define IPortableDeviceValues_SetSignedIntegerValue(This,key,Value)	\
    ( (This)->lpVtbl -> SetSignedIntegerValue(This,key,Value) ) 

#define IPortableDeviceValues_GetSignedIntegerValue(This,key,pValue)	\
    ( (This)->lpVtbl -> GetSignedIntegerValue(This,key,pValue) ) 

#define IPortableDeviceValues_SetUnsignedLargeIntegerValue(This,key,Value)	\
    ( (This)->lpVtbl -> SetUnsignedLargeIntegerValue(This,key,Value) ) 

#define IPortableDeviceValues_GetUnsignedLargeIntegerValue(This,key,pValue)	\
    ( (This)->lpVtbl -> GetUnsignedLargeIntegerValue(This,key,pValue) ) 

#define IPortableDeviceValues_SetSignedLargeIntegerValue(This,key,Value)	\
    ( (This)->lpVtbl -> SetSignedLargeIntegerValue(This,key,Value) ) 

#define IPortableDeviceValues_GetSignedLargeIntegerValue(This,key,pValue)	\
    ( (This)->lpVtbl -> GetSignedLargeIntegerValue(This,key,pValue) ) 

#define IPortableDeviceValues_SetFloatValue(This,key,Value)	\
    ( (This)->lpVtbl -> SetFloatValue(This,key,Value) ) 

#define IPortableDeviceValues_GetFloatValue(This,key,pValue)	\
    ( (This)->lpVtbl -> GetFloatValue(This,key,pValue) ) 

#define IPortableDeviceValues_SetErrorValue(This,key,Value)	\
    ( (This)->lpVtbl -> SetErrorValue(This,key,Value) ) 

#define IPortableDeviceValues_GetErrorValue(This,key,pValue)	\
    ( (This)->lpVtbl -> GetErrorValue(This,key,pValue) ) 

#define IPortableDeviceValues_SetKeyValue(This,key,Value)	\
    ( (This)->lpVtbl -> SetKeyValue(This,key,Value) ) 

#define IPortableDeviceValues_GetKeyValue(This,key,pValue)	\
    ( (This)->lpVtbl -> GetKeyValue(This,key,pValue) ) 

#define IPortableDeviceValues_SetBoolValue(This,key,Value)	\
    ( (This)->lpVtbl -> SetBoolValue(This,key,Value) ) 

#define IPortableDeviceValues_GetBoolValue(This,key,pValue)	\
    ( (This)->lpVtbl -> GetBoolValue(This,key,pValue) ) 

#define IPortableDeviceValues_SetIUnknownValue(This,key,pValue)	\
    ( (This)->lpVtbl -> SetIUnknownValue(This,key,pValue) ) 

#define IPortableDeviceValues_GetIUnknownValue(This,key,ppValue)	\
    ( (This)->lpVtbl -> GetIUnknownValue(This,key,ppValue) ) 

#define IPortableDeviceValues_SetGuidValue(This,key,Value)	\
    ( (This)->lpVtbl -> SetGuidValue(This,key,Value) ) 

#define IPortableDeviceValues_GetGuidValue(This,key,pValue)	\
    ( (This)->lpVtbl -> GetGuidValue(This,key,pValue) ) 

#define IPortableDeviceValues_SetBufferValue(This,key,pValue,cbValue)	\
    ( (This)->lpVtbl -> SetBufferValue(This,key,pValue,cbValue) ) 

#define IPortableDeviceValues_GetBufferValue(This,key,ppValue,pcbValue)	\
    ( (This)->lpVtbl -> GetBufferValue(This,key,ppValue,pcbValue) ) 

#define IPortableDeviceValues_SetIPortableDeviceValuesValue(This,key,pValue)	\
    ( (This)->lpVtbl -> SetIPortableDeviceValuesValue(This,key,pValue) ) 

#define IPortableDeviceValues_GetIPortableDeviceValuesValue(This,key,ppValue)	\
    ( (This)->lpVtbl -> GetIPortableDeviceValuesValue(This,key,ppValue) ) 

#define IPortableDeviceValues_SetIPortableDevicePropVariantCollectionValue(This,key,pValue)	\
    ( (This)->lpVtbl -> SetIPortableDevicePropVariantCollectionValue(This,key,pValue) ) 

#define IPortableDeviceValues_GetIPortableDevicePropVariantCollectionValue(This,key,ppValue)	\
    ( (This)->lpVtbl -> GetIPortableDevicePropVariantCollectionValue(This,key,ppValue) ) 

#define IPortableDeviceValues_SetIPortableDeviceKeyCollectionValue(This,key,pValue)	\
    ( (This)->lpVtbl -> SetIPortableDeviceKeyCollectionValue(This,key,pValue) ) 

#define IPortableDeviceValues_GetIPortableDeviceKeyCollectionValue(This,key,ppValue)	\
    ( (This)->lpVtbl -> GetIPortableDeviceKeyCollectionValue(This,key,ppValue) ) 

#define IPortableDeviceValues_SetIPortableDeviceValuesCollectionValue(This,key,pValue)	\
    ( (This)->lpVtbl -> SetIPortableDeviceValuesCollectionValue(This,key,pValue) ) 

#define IPortableDeviceValues_GetIPortableDeviceValuesCollectionValue(This,key,ppValue)	\
    ( (This)->lpVtbl -> GetIPortableDeviceValuesCollectionValue(This,key,ppValue) ) 

#define IPortableDeviceValues_RemoveValue(This,key)	\
    ( (This)->lpVtbl -> RemoveValue(This,key) ) 

#define IPortableDeviceValues_CopyValuesFromPropertyStore(This,pStore)	\
    ( (This)->lpVtbl -> CopyValuesFromPropertyStore(This,pStore) ) 

#define IPortableDeviceValues_CopyValuesToPropertyStore(This,pStore)	\
    ( (This)->lpVtbl -> CopyValuesToPropertyStore(This,pStore) ) 

#define IPortableDeviceValues_Clear(This)	\
    ( (This)->lpVtbl -> Clear(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPortableDeviceValues_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_portabledevicetypes_0000_0002 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP) */
#pragma endregion
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP) && !WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
#undef IPropertyStore
#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP) && !WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma region Application Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP)


extern RPC_IF_HANDLE __MIDL_itf_portabledevicetypes_0000_0002_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_portabledevicetypes_0000_0002_v0_0_s_ifspec;

#ifndef __IPortableDeviceKeyCollection_INTERFACE_DEFINED__
#define __IPortableDeviceKeyCollection_INTERFACE_DEFINED__

/* interface IPortableDeviceKeyCollection */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IPortableDeviceKeyCollection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("dada2357-e0ad-492e-98db-dd61c53ba353")
    IPortableDeviceKeyCollection : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetCount( 
            /* [annotation][in] */ 
            _In_  DWORD *pcElems) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAt( 
            /* [annotation][in] */ 
            _In_  const DWORD dwIndex,
            /* [annotation][in] */ 
            _In_  PROPERTYKEY *pKey) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Add( 
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY Key) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clear( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveAt( 
            /* [annotation][in] */ 
            _In_  const DWORD dwIndex) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IPortableDeviceKeyCollectionVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IPortableDeviceKeyCollection * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IPortableDeviceKeyCollection * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IPortableDeviceKeyCollection * This);
        
        DECLSPEC_XFGVIRT(IPortableDeviceKeyCollection, GetCount)
        HRESULT ( STDMETHODCALLTYPE *GetCount )( 
            __RPC__in IPortableDeviceKeyCollection * This,
            /* [annotation][in] */ 
            _In_  DWORD *pcElems);
        
        DECLSPEC_XFGVIRT(IPortableDeviceKeyCollection, GetAt)
        HRESULT ( STDMETHODCALLTYPE *GetAt )( 
            __RPC__in IPortableDeviceKeyCollection * This,
            /* [annotation][in] */ 
            _In_  const DWORD dwIndex,
            /* [annotation][in] */ 
            _In_  PROPERTYKEY *pKey);
        
        DECLSPEC_XFGVIRT(IPortableDeviceKeyCollection, Add)
        HRESULT ( STDMETHODCALLTYPE *Add )( 
            __RPC__in IPortableDeviceKeyCollection * This,
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY Key);
        
        DECLSPEC_XFGVIRT(IPortableDeviceKeyCollection, Clear)
        HRESULT ( STDMETHODCALLTYPE *Clear )( 
            __RPC__in IPortableDeviceKeyCollection * This);
        
        DECLSPEC_XFGVIRT(IPortableDeviceKeyCollection, RemoveAt)
        HRESULT ( STDMETHODCALLTYPE *RemoveAt )( 
            __RPC__in IPortableDeviceKeyCollection * This,
            /* [annotation][in] */ 
            _In_  const DWORD dwIndex);
        
        END_INTERFACE
    } IPortableDeviceKeyCollectionVtbl;

    interface IPortableDeviceKeyCollection
    {
        CONST_VTBL struct IPortableDeviceKeyCollectionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPortableDeviceKeyCollection_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPortableDeviceKeyCollection_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPortableDeviceKeyCollection_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPortableDeviceKeyCollection_GetCount(This,pcElems)	\
    ( (This)->lpVtbl -> GetCount(This,pcElems) ) 

#define IPortableDeviceKeyCollection_GetAt(This,dwIndex,pKey)	\
    ( (This)->lpVtbl -> GetAt(This,dwIndex,pKey) ) 

#define IPortableDeviceKeyCollection_Add(This,Key)	\
    ( (This)->lpVtbl -> Add(This,Key) ) 

#define IPortableDeviceKeyCollection_Clear(This)	\
    ( (This)->lpVtbl -> Clear(This) ) 

#define IPortableDeviceKeyCollection_RemoveAt(This,dwIndex)	\
    ( (This)->lpVtbl -> RemoveAt(This,dwIndex) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPortableDeviceKeyCollection_INTERFACE_DEFINED__ */


#ifndef __IPortableDevicePropVariantCollection_INTERFACE_DEFINED__
#define __IPortableDevicePropVariantCollection_INTERFACE_DEFINED__

/* interface IPortableDevicePropVariantCollection */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IPortableDevicePropVariantCollection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("89b2e422-4f1b-4316-bcef-a44afea83eb3")
    IPortableDevicePropVariantCollection : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetCount( 
            /* [annotation][in] */ 
            _In_  DWORD *pcElems) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAt( 
            /* [annotation][in] */ 
            _In_  const DWORD dwIndex,
            /* [annotation][in] */ 
            _In_  PROPVARIANT *pValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Add( 
            /* [annotation][in] */ 
            _In_  const PROPVARIANT *pValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetType( 
            /* [annotation][out] */ 
            _Out_  VARTYPE *pvt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ChangeType( 
            /* [annotation][in] */ 
            _In_  const VARTYPE vt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clear( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveAt( 
            /* [annotation][in] */ 
            _In_  const DWORD dwIndex) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IPortableDevicePropVariantCollectionVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IPortableDevicePropVariantCollection * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IPortableDevicePropVariantCollection * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IPortableDevicePropVariantCollection * This);
        
        DECLSPEC_XFGVIRT(IPortableDevicePropVariantCollection, GetCount)
        HRESULT ( STDMETHODCALLTYPE *GetCount )( 
            __RPC__in IPortableDevicePropVariantCollection * This,
            /* [annotation][in] */ 
            _In_  DWORD *pcElems);
        
        DECLSPEC_XFGVIRT(IPortableDevicePropVariantCollection, GetAt)
        HRESULT ( STDMETHODCALLTYPE *GetAt )( 
            __RPC__in IPortableDevicePropVariantCollection * This,
            /* [annotation][in] */ 
            _In_  const DWORD dwIndex,
            /* [annotation][in] */ 
            _In_  PROPVARIANT *pValue);
        
        DECLSPEC_XFGVIRT(IPortableDevicePropVariantCollection, Add)
        HRESULT ( STDMETHODCALLTYPE *Add )( 
            __RPC__in IPortableDevicePropVariantCollection * This,
            /* [annotation][in] */ 
            _In_  const PROPVARIANT *pValue);
        
        DECLSPEC_XFGVIRT(IPortableDevicePropVariantCollection, GetType)
        HRESULT ( STDMETHODCALLTYPE *GetType )( 
            __RPC__in IPortableDevicePropVariantCollection * This,
            /* [annotation][out] */ 
            _Out_  VARTYPE *pvt);
        
        DECLSPEC_XFGVIRT(IPortableDevicePropVariantCollection, ChangeType)
        HRESULT ( STDMETHODCALLTYPE *ChangeType )( 
            __RPC__in IPortableDevicePropVariantCollection * This,
            /* [annotation][in] */ 
            _In_  const VARTYPE vt);
        
        DECLSPEC_XFGVIRT(IPortableDevicePropVariantCollection, Clear)
        HRESULT ( STDMETHODCALLTYPE *Clear )( 
            __RPC__in IPortableDevicePropVariantCollection * This);
        
        DECLSPEC_XFGVIRT(IPortableDevicePropVariantCollection, RemoveAt)
        HRESULT ( STDMETHODCALLTYPE *RemoveAt )( 
            __RPC__in IPortableDevicePropVariantCollection * This,
            /* [annotation][in] */ 
            _In_  const DWORD dwIndex);
        
        END_INTERFACE
    } IPortableDevicePropVariantCollectionVtbl;

    interface IPortableDevicePropVariantCollection
    {
        CONST_VTBL struct IPortableDevicePropVariantCollectionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPortableDevicePropVariantCollection_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPortableDevicePropVariantCollection_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPortableDevicePropVariantCollection_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPortableDevicePropVariantCollection_GetCount(This,pcElems)	\
    ( (This)->lpVtbl -> GetCount(This,pcElems) ) 

#define IPortableDevicePropVariantCollection_GetAt(This,dwIndex,pValue)	\
    ( (This)->lpVtbl -> GetAt(This,dwIndex,pValue) ) 

#define IPortableDevicePropVariantCollection_Add(This,pValue)	\
    ( (This)->lpVtbl -> Add(This,pValue) ) 

#define IPortableDevicePropVariantCollection_GetType(This,pvt)	\
    ( (This)->lpVtbl -> GetType(This,pvt) ) 

#define IPortableDevicePropVariantCollection_ChangeType(This,vt)	\
    ( (This)->lpVtbl -> ChangeType(This,vt) ) 

#define IPortableDevicePropVariantCollection_Clear(This)	\
    ( (This)->lpVtbl -> Clear(This) ) 

#define IPortableDevicePropVariantCollection_RemoveAt(This,dwIndex)	\
    ( (This)->lpVtbl -> RemoveAt(This,dwIndex) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPortableDevicePropVariantCollection_INTERFACE_DEFINED__ */


#ifndef __IPortableDeviceValuesCollection_INTERFACE_DEFINED__
#define __IPortableDeviceValuesCollection_INTERFACE_DEFINED__

/* interface IPortableDeviceValuesCollection */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IPortableDeviceValuesCollection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6e3f2d79-4e07-48c4-8208-d8c2e5af4a99")
    IPortableDeviceValuesCollection : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetCount( 
            /* [annotation][in] */ 
            _In_  DWORD *pcElems) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAt( 
            /* [annotation][in] */ 
            _In_  const DWORD dwIndex,
            /* [annotation][out] */ 
            _Out_  IPortableDeviceValues **ppValues) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Add( 
            /* [annotation][in] */ 
            _In_  IPortableDeviceValues *pValues) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clear( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveAt( 
            /* [annotation][in] */ 
            _In_  const DWORD dwIndex) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IPortableDeviceValuesCollectionVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IPortableDeviceValuesCollection * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IPortableDeviceValuesCollection * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IPortableDeviceValuesCollection * This);
        
        DECLSPEC_XFGVIRT(IPortableDeviceValuesCollection, GetCount)
        HRESULT ( STDMETHODCALLTYPE *GetCount )( 
            __RPC__in IPortableDeviceValuesCollection * This,
            /* [annotation][in] */ 
            _In_  DWORD *pcElems);
        
        DECLSPEC_XFGVIRT(IPortableDeviceValuesCollection, GetAt)
        HRESULT ( STDMETHODCALLTYPE *GetAt )( 
            __RPC__in IPortableDeviceValuesCollection * This,
            /* [annotation][in] */ 
            _In_  const DWORD dwIndex,
            /* [annotation][out] */ 
            _Out_  IPortableDeviceValues **ppValues);
        
        DECLSPEC_XFGVIRT(IPortableDeviceValuesCollection, Add)
        HRESULT ( STDMETHODCALLTYPE *Add )( 
            __RPC__in IPortableDeviceValuesCollection * This,
            /* [annotation][in] */ 
            _In_  IPortableDeviceValues *pValues);
        
        DECLSPEC_XFGVIRT(IPortableDeviceValuesCollection, Clear)
        HRESULT ( STDMETHODCALLTYPE *Clear )( 
            __RPC__in IPortableDeviceValuesCollection * This);
        
        DECLSPEC_XFGVIRT(IPortableDeviceValuesCollection, RemoveAt)
        HRESULT ( STDMETHODCALLTYPE *RemoveAt )( 
            __RPC__in IPortableDeviceValuesCollection * This,
            /* [annotation][in] */ 
            _In_  const DWORD dwIndex);
        
        END_INTERFACE
    } IPortableDeviceValuesCollectionVtbl;

    interface IPortableDeviceValuesCollection
    {
        CONST_VTBL struct IPortableDeviceValuesCollectionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPortableDeviceValuesCollection_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPortableDeviceValuesCollection_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPortableDeviceValuesCollection_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPortableDeviceValuesCollection_GetCount(This,pcElems)	\
    ( (This)->lpVtbl -> GetCount(This,pcElems) ) 

#define IPortableDeviceValuesCollection_GetAt(This,dwIndex,ppValues)	\
    ( (This)->lpVtbl -> GetAt(This,dwIndex,ppValues) ) 

#define IPortableDeviceValuesCollection_Add(This,pValues)	\
    ( (This)->lpVtbl -> Add(This,pValues) ) 

#define IPortableDeviceValuesCollection_Clear(This)	\
    ( (This)->lpVtbl -> Clear(This) ) 

#define IPortableDeviceValuesCollection_RemoveAt(This,dwIndex)	\
    ( (This)->lpVtbl -> RemoveAt(This,dwIndex) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPortableDeviceValuesCollection_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_portabledevicetypes_0000_0005 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP) */
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_portabledevicetypes_0000_0005_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_portabledevicetypes_0000_0005_v0_0_s_ifspec;


#ifndef __PortableDeviceTypesLib_LIBRARY_DEFINED__
#define __PortableDeviceTypesLib_LIBRARY_DEFINED__

/* library PortableDeviceTypesLib */
/* [helpstring][version][uuid] */ 

#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion
#pragma region Application Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP)
#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP) */
#pragma endregion

EXTERN_C const IID LIBID_PortableDeviceTypesLib;

EXTERN_C const CLSID CLSID_WpdSerializer;

#ifdef __cplusplus

class DECLSPEC_UUID("0b91a74b-ad7c-4a9d-b563-29eef9167172")
WpdSerializer;
#endif

EXTERN_C const CLSID CLSID_PortableDeviceValues;

#ifdef __cplusplus

class DECLSPEC_UUID("0c15d503-d017-47ce-9016-7b3f978721cc")
PortableDeviceValues;
#endif

EXTERN_C const CLSID CLSID_PortableDeviceKeyCollection;

#ifdef __cplusplus

class DECLSPEC_UUID("de2d022d-2480-43be-97f0-d1fa2cf98f4f")
PortableDeviceKeyCollection;
#endif

EXTERN_C const CLSID CLSID_PortableDevicePropVariantCollection;

#ifdef __cplusplus

class DECLSPEC_UUID("08a99e2f-6d6d-4b80-af5a-baf2bcbe4cb9")
PortableDevicePropVariantCollection;
#endif

EXTERN_C const CLSID CLSID_PortableDeviceValuesCollection;

#ifdef __cplusplus

class DECLSPEC_UUID("3882134d-14cf-4220-9cb4-435f86d83f60")
PortableDeviceValuesCollection;
#endif
#endif /* __PortableDeviceTypesLib_LIBRARY_DEFINED__ */

/* interface __MIDL_itf_portabledevicetypes_0000_0006 */
/* [local] */ 

#endif // (_WIN32_WINNT >= 0x0501)


extern RPC_IF_HANDLE __MIDL_itf_portabledevicetypes_0000_0006_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_portabledevicetypes_0000_0006_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     __RPC__in unsigned long *, unsigned long            , __RPC__in BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     __RPC__in unsigned long *, __RPC__in BSTR * ); 

unsigned long             __RPC_USER  LPSAFEARRAY_UserSize(     __RPC__in unsigned long *, unsigned long            , __RPC__in LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserMarshal(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserUnmarshal(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out LPSAFEARRAY * ); 
void                      __RPC_USER  LPSAFEARRAY_UserFree(     __RPC__in unsigned long *, __RPC__in LPSAFEARRAY * ); 

unsigned long             __RPC_USER  BSTR_UserSize64(     __RPC__in unsigned long *, unsigned long            , __RPC__in BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal64(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal64(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out BSTR * ); 
void                      __RPC_USER  BSTR_UserFree64(     __RPC__in unsigned long *, __RPC__in BSTR * ); 

unsigned long             __RPC_USER  LPSAFEARRAY_UserSize64(     __RPC__in unsigned long *, unsigned long            , __RPC__in LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserMarshal64(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserUnmarshal64(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out LPSAFEARRAY * ); 
void                      __RPC_USER  LPSAFEARRAY_UserFree64(     __RPC__in unsigned long *, __RPC__in LPSAFEARRAY * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


