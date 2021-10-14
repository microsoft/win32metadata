

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

#ifndef __notificationactivationcallback_h__
#define __notificationactivationcallback_h__

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

#ifndef __INotificationActivationCallback_FWD_DEFINED__
#define __INotificationActivationCallback_FWD_DEFINED__
typedef interface INotificationActivationCallback INotificationActivationCallback;

#endif 	/* __INotificationActivationCallback_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_notificationactivationcallback_0000_0000 */
/* [local] */ 

#include <winapifamily.h>
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)
#if (NTDDI_VERSION >= NTDDI_WIN10)
typedef struct NOTIFICATION_USER_INPUT_DATA
    {
    LPCWSTR Key;
    LPCWSTR Value;
    } 	NOTIFICATION_USER_INPUT_DATA;



extern RPC_IF_HANDLE __MIDL_itf_notificationactivationcallback_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_notificationactivationcallback_0000_0000_v0_0_s_ifspec;

#ifndef __INotificationActivationCallback_INTERFACE_DEFINED__
#define __INotificationActivationCallback_INTERFACE_DEFINED__

/* interface INotificationActivationCallback */
/* [ref][uuid][object] */ 


EXTERN_C const IID IID_INotificationActivationCallback;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("53E31837-6600-4A81-9395-75CFFE746F94")
    INotificationActivationCallback : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Activate( 
            /* [annotation][string][in] */ 
            _In_  LPCWSTR appUserModelId,
            /* [annotation][unique][string][in] */ 
            _In_  LPCWSTR invokedArgs,
            /* [annotation][unique][size_is][in] */ 
            _In_reads_(count)  const NOTIFICATION_USER_INPUT_DATA *data,
            /* [annotation][in] */ 
            _In_  ULONG count) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct INotificationActivationCallbackVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in INotificationActivationCallback * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in INotificationActivationCallback * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in INotificationActivationCallback * This);
        
        DECLSPEC_XFGVIRT(INotificationActivationCallback, Activate)
        HRESULT ( STDMETHODCALLTYPE *Activate )( 
            __RPC__in INotificationActivationCallback * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR appUserModelId,
            /* [annotation][unique][string][in] */ 
            _In_  LPCWSTR invokedArgs,
            /* [annotation][unique][size_is][in] */ 
            _In_reads_(count)  const NOTIFICATION_USER_INPUT_DATA *data,
            /* [annotation][in] */ 
            _In_  ULONG count);
        
        END_INTERFACE
    } INotificationActivationCallbackVtbl;

    interface INotificationActivationCallback
    {
        CONST_VTBL struct INotificationActivationCallbackVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INotificationActivationCallback_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define INotificationActivationCallback_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define INotificationActivationCallback_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define INotificationActivationCallback_Activate(This,appUserModelId,invokedArgs,data,count)	\
    ( (This)->lpVtbl -> Activate(This,appUserModelId,invokedArgs,data,count) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __INotificationActivationCallback_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_notificationactivationcallback_0000_0001 */
/* [local] */ 

#endif // NTDDI_WIN10
#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) */


extern RPC_IF_HANDLE __MIDL_itf_notificationactivationcallback_0000_0001_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_notificationactivationcallback_0000_0001_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


