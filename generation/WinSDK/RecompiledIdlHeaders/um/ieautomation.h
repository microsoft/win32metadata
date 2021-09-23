

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

#ifndef __ieautomation_h__
#define __ieautomation_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IEnumManagerFrames_FWD_DEFINED__
#define __IEnumManagerFrames_FWD_DEFINED__
typedef interface IEnumManagerFrames IEnumManagerFrames;

#endif 	/* __IEnumManagerFrames_FWD_DEFINED__ */


#ifndef __IInternetExplorerManager_FWD_DEFINED__
#define __IInternetExplorerManager_FWD_DEFINED__
typedef interface IInternetExplorerManager IInternetExplorerManager;

#endif 	/* __IInternetExplorerManager_FWD_DEFINED__ */


#ifndef __IInternetExplorerManager2_FWD_DEFINED__
#define __IInternetExplorerManager2_FWD_DEFINED__
typedef interface IInternetExplorerManager2 IInternetExplorerManager2;

#endif 	/* __IInternetExplorerManager2_FWD_DEFINED__ */


#ifndef __InternetExplorerManager_FWD_DEFINED__
#define __InternetExplorerManager_FWD_DEFINED__

#ifdef __cplusplus
typedef class InternetExplorerManager InternetExplorerManager;
#else
typedef struct InternetExplorerManager InternetExplorerManager;
#endif /* __cplusplus */

#endif 	/* __InternetExplorerManager_FWD_DEFINED__ */


/* header files for imported files */
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_ieautomation_0000_0000 */
/* [local] */ 

//=--------------------------------------------------------------------------=
// ieautomation.h
//=--------------------------------------------------------------------------=
// (C) Copyright Microsoft Corporation.  All Rights Reserved.
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//=--------------------------------------------------------------------------=

#include <winapifamily.h>
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
typedef /* [helpstring][uuid] */  DECLSPEC_UUID("44EC9B57-DCAB-4CDE-B373-EE94962950E3") 
enum INTERNETEXPLORERCONFIGURATION
    {
        INTERNETEXPLORERCONFIGURATION_HOST	= 0x1,
        INTERNETEXPLORERCONFIGURATION_WEB_DRIVER	= 0x2,
        INTERNETEXPLORERCONFIGURATION_WEB_DRIVER_EDGE	= 0x4
    } 	INTERNETEXPLORERCONFIGURATION;



extern RPC_IF_HANDLE __MIDL_itf_ieautomation_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ieautomation_0000_0000_v0_0_s_ifspec;

#ifndef __IEnumManagerFrames_INTERFACE_DEFINED__
#define __IEnumManagerFrames_INTERFACE_DEFINED__

/* interface IEnumManagerFrames */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IEnumManagerFrames;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3CAA826A-9B1F-4A79-BC81-F0430DED1648")
    IEnumManagerFrames : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [annotation][in] */ 
            _In_  ULONG celt,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(celt,*pceltFetched)  HWND **ppWindows,
            /* [annotation][out] */ 
            _Out_  ULONG *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Count( 
            /* [annotation][out] */ 
            _Out_  ULONG *pcelt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [annotation][in] */ 
            _In_  ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [annotation][out] */ 
            _Out_  IEnumManagerFrames **ppEnum) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IEnumManagerFramesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IEnumManagerFrames * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IEnumManagerFrames * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IEnumManagerFrames * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            __RPC__in IEnumManagerFrames * This,
            /* [annotation][in] */ 
            _In_  ULONG celt,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(celt,*pceltFetched)  HWND **ppWindows,
            /* [annotation][out] */ 
            _Out_  ULONG *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Count )( 
            __RPC__in IEnumManagerFrames * This,
            /* [annotation][out] */ 
            _Out_  ULONG *pcelt);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            __RPC__in IEnumManagerFrames * This,
            /* [annotation][in] */ 
            _In_  ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            __RPC__in IEnumManagerFrames * This);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            __RPC__in IEnumManagerFrames * This,
            /* [annotation][out] */ 
            _Out_  IEnumManagerFrames **ppEnum);
        
        END_INTERFACE
    } IEnumManagerFramesVtbl;

    interface IEnumManagerFrames
    {
        CONST_VTBL struct IEnumManagerFramesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumManagerFrames_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEnumManagerFrames_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEnumManagerFrames_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IEnumManagerFrames_Next(This,celt,ppWindows,pceltFetched)	\
    ( (This)->lpVtbl -> Next(This,celt,ppWindows,pceltFetched) ) 

#define IEnumManagerFrames_Count(This,pcelt)	\
    ( (This)->lpVtbl -> Count(This,pcelt) ) 

#define IEnumManagerFrames_Skip(This,celt)	\
    ( (This)->lpVtbl -> Skip(This,celt) ) 

#define IEnumManagerFrames_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define IEnumManagerFrames_Clone(This,ppEnum)	\
    ( (This)->lpVtbl -> Clone(This,ppEnum) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IEnumManagerFrames_INTERFACE_DEFINED__ */


#ifndef __IInternetExplorerManager_INTERFACE_DEFINED__
#define __IInternetExplorerManager_INTERFACE_DEFINED__

/* interface IInternetExplorerManager */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IInternetExplorerManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("ACC84351-04FF-44F9-B23F-655ED168C6D5")
    IInternetExplorerManager : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CreateObject( 
            /* [annotation][in] */ 
            _In_  DWORD dwConfig,
            /* [annotation][string][unique][in] */ 
            _In_  LPCWSTR pszURL,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppv) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IInternetExplorerManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IInternetExplorerManager * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IInternetExplorerManager * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IInternetExplorerManager * This);
        
        HRESULT ( STDMETHODCALLTYPE *CreateObject )( 
            __RPC__in IInternetExplorerManager * This,
            /* [annotation][in] */ 
            _In_  DWORD dwConfig,
            /* [annotation][string][unique][in] */ 
            _In_  LPCWSTR pszURL,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppv);
        
        END_INTERFACE
    } IInternetExplorerManagerVtbl;

    interface IInternetExplorerManager
    {
        CONST_VTBL struct IInternetExplorerManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInternetExplorerManager_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInternetExplorerManager_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInternetExplorerManager_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInternetExplorerManager_CreateObject(This,dwConfig,pszURL,riid,ppv)	\
    ( (This)->lpVtbl -> CreateObject(This,dwConfig,pszURL,riid,ppv) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInternetExplorerManager_INTERFACE_DEFINED__ */


#ifndef __IInternetExplorerManager2_INTERFACE_DEFINED__
#define __IInternetExplorerManager2_INTERFACE_DEFINED__

/* interface IInternetExplorerManager2 */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IInternetExplorerManager2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DFBB5136-9259-4895-B4A7-C1934429919A")
    IInternetExplorerManager2 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE EnumFrameWindows( 
            /* [annotation][out] */ 
            _Out_  IEnumManagerFrames **ppEnum) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IInternetExplorerManager2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IInternetExplorerManager2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IInternetExplorerManager2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IInternetExplorerManager2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *EnumFrameWindows )( 
            __RPC__in IInternetExplorerManager2 * This,
            /* [annotation][out] */ 
            _Out_  IEnumManagerFrames **ppEnum);
        
        END_INTERFACE
    } IInternetExplorerManager2Vtbl;

    interface IInternetExplorerManager2
    {
        CONST_VTBL struct IInternetExplorerManager2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInternetExplorerManager2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInternetExplorerManager2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInternetExplorerManager2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInternetExplorerManager2_EnumFrameWindows(This,ppEnum)	\
    ( (This)->lpVtbl -> EnumFrameWindows(This,ppEnum) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInternetExplorerManager2_INTERFACE_DEFINED__ */



#ifndef __InternetExplorerAutomationLib_LIBRARY_DEFINED__
#define __InternetExplorerAutomationLib_LIBRARY_DEFINED__

/* library InternetExplorerAutomationLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_InternetExplorerAutomationLib;

EXTERN_C const CLSID CLSID_InternetExplorerManager;

#ifdef __cplusplus

class DECLSPEC_UUID("DF4FCC34-067A-4E0A-8352-4A1A5095346E")
InternetExplorerManager;
#endif
#endif /* __InternetExplorerAutomationLib_LIBRARY_DEFINED__ */

/* interface __MIDL_itf_ieautomation_0000_0004 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_ieautomation_0000_0004_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ieautomation_0000_0004_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  HWND_UserSize(     __RPC__in unsigned long *, unsigned long            , __RPC__in HWND * ); 
unsigned char * __RPC_USER  HWND_UserMarshal(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in HWND * ); 
unsigned char * __RPC_USER  HWND_UserUnmarshal(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out HWND * ); 
void                      __RPC_USER  HWND_UserFree(     __RPC__in unsigned long *, __RPC__in HWND * ); 

unsigned long             __RPC_USER  HWND_UserSize64(     __RPC__in unsigned long *, unsigned long            , __RPC__in HWND * ); 
unsigned char * __RPC_USER  HWND_UserMarshal64(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in HWND * ); 
unsigned char * __RPC_USER  HWND_UserUnmarshal64(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out HWND * ); 
void                      __RPC_USER  HWND_UserFree64(     __RPC__in unsigned long *, __RPC__in HWND * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


