

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

#ifndef __useractivityinterop_h__
#define __useractivityinterop_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IUserActivityInterop_FWD_DEFINED__
#define __IUserActivityInterop_FWD_DEFINED__
typedef interface IUserActivityInterop IUserActivityInterop;

#endif 	/* __IUserActivityInterop_FWD_DEFINED__ */


#ifndef __IUserActivitySourceHostInterop_FWD_DEFINED__
#define __IUserActivitySourceHostInterop_FWD_DEFINED__
typedef interface IUserActivitySourceHostInterop IUserActivitySourceHostInterop;

#endif 	/* __IUserActivitySourceHostInterop_FWD_DEFINED__ */


#ifndef __IUserActivityRequestManagerInterop_FWD_DEFINED__
#define __IUserActivityRequestManagerInterop_FWD_DEFINED__
typedef interface IUserActivityRequestManagerInterop IUserActivityRequestManagerInterop;

#endif 	/* __IUserActivityRequestManagerInterop_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "Inspectable.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_useractivityinterop_0000_0000 */
/* [local] */ 

#include <winapifamily.h>
#if (NTDDI_VERSION >= NTDDI_WIN10_RS4)
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)


extern RPC_IF_HANDLE __MIDL_itf_useractivityinterop_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_useractivityinterop_0000_0000_v0_0_s_ifspec;

#ifndef __IUserActivityInterop_INTERFACE_DEFINED__
#define __IUserActivityInterop_INTERFACE_DEFINED__

/* interface IUserActivityInterop */
/* [local][object][uuid] */ 


EXTERN_C const IID IID_IUserActivityInterop;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1ADE314D-0E0A-40D9-824C-9A088A50059F")
    IUserActivityInterop : public IInspectable
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CreateSessionForWindow( 
            /* [annotation][in] */ 
            _In_  HWND window,
            /* [annotation][in] */ 
            _In_  REFIID iid,
            /* [annotation][retval][iid_is][out] */ 
            _COM_Outptr_retval_  void **value) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IUserActivityInteropVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IUserActivityInterop * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IUserActivityInterop * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IUserActivityInterop * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetIids )( 
            IUserActivityInterop * This,
            /* [out] */ ULONG *iidCount,
            /* [size_is][size_is][out] */ IID **iids);
        
        HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )( 
            IUserActivityInterop * This,
            /* [out] */ HSTRING *className);
        
        HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )( 
            IUserActivityInterop * This,
            /* [out] */ TrustLevel *trustLevel);
        
        HRESULT ( STDMETHODCALLTYPE *CreateSessionForWindow )( 
            IUserActivityInterop * This,
            /* [annotation][in] */ 
            _In_  HWND window,
            /* [annotation][in] */ 
            _In_  REFIID iid,
            /* [annotation][retval][iid_is][out] */ 
            _COM_Outptr_retval_  void **value);
        
        END_INTERFACE
    } IUserActivityInteropVtbl;

    interface IUserActivityInterop
    {
        CONST_VTBL struct IUserActivityInteropVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IUserActivityInterop_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IUserActivityInterop_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IUserActivityInterop_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IUserActivityInterop_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define IUserActivityInterop_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define IUserActivityInterop_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define IUserActivityInterop_CreateSessionForWindow(This,window,iid,value)	\
    ( (This)->lpVtbl -> CreateSessionForWindow(This,window,iid,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IUserActivityInterop_INTERFACE_DEFINED__ */


#ifndef __IUserActivitySourceHostInterop_INTERFACE_DEFINED__
#define __IUserActivitySourceHostInterop_INTERFACE_DEFINED__

/* interface IUserActivitySourceHostInterop */
/* [local][object][uuid] */ 


EXTERN_C const IID IID_IUserActivitySourceHostInterop;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C15DF8BC-8844-487A-B85B-7578E0F61419")
    IUserActivitySourceHostInterop : public IInspectable
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetActivitySourceHost( 
            /* [annotation][in] */ 
            _In_  HSTRING activitySourceHost) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IUserActivitySourceHostInteropVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IUserActivitySourceHostInterop * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IUserActivitySourceHostInterop * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IUserActivitySourceHostInterop * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetIids )( 
            IUserActivitySourceHostInterop * This,
            /* [out] */ ULONG *iidCount,
            /* [size_is][size_is][out] */ IID **iids);
        
        HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )( 
            IUserActivitySourceHostInterop * This,
            /* [out] */ HSTRING *className);
        
        HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )( 
            IUserActivitySourceHostInterop * This,
            /* [out] */ TrustLevel *trustLevel);
        
        HRESULT ( STDMETHODCALLTYPE *SetActivitySourceHost )( 
            IUserActivitySourceHostInterop * This,
            /* [annotation][in] */ 
            _In_  HSTRING activitySourceHost);
        
        END_INTERFACE
    } IUserActivitySourceHostInteropVtbl;

    interface IUserActivitySourceHostInterop
    {
        CONST_VTBL struct IUserActivitySourceHostInteropVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IUserActivitySourceHostInterop_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IUserActivitySourceHostInterop_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IUserActivitySourceHostInterop_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IUserActivitySourceHostInterop_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define IUserActivitySourceHostInterop_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define IUserActivitySourceHostInterop_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define IUserActivitySourceHostInterop_SetActivitySourceHost(This,activitySourceHost)	\
    ( (This)->lpVtbl -> SetActivitySourceHost(This,activitySourceHost) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IUserActivitySourceHostInterop_INTERFACE_DEFINED__ */


#ifndef __IUserActivityRequestManagerInterop_INTERFACE_DEFINED__
#define __IUserActivityRequestManagerInterop_INTERFACE_DEFINED__

/* interface IUserActivityRequestManagerInterop */
/* [local][object][uuid] */ 


EXTERN_C const IID IID_IUserActivityRequestManagerInterop;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DD69F876-9699-4715-9095-E37EA30DFA1B")
    IUserActivityRequestManagerInterop : public IInspectable
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetForWindow( 
            /* [annotation][in] */ 
            _In_  HWND window,
            /* [annotation][in] */ 
            _In_  REFIID iid,
            /* [annotation][retval][iid_is][out] */ 
            _COM_Outptr_retval_  void **value) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IUserActivityRequestManagerInteropVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IUserActivityRequestManagerInterop * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IUserActivityRequestManagerInterop * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IUserActivityRequestManagerInterop * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetIids )( 
            IUserActivityRequestManagerInterop * This,
            /* [out] */ ULONG *iidCount,
            /* [size_is][size_is][out] */ IID **iids);
        
        HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )( 
            IUserActivityRequestManagerInterop * This,
            /* [out] */ HSTRING *className);
        
        HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )( 
            IUserActivityRequestManagerInterop * This,
            /* [out] */ TrustLevel *trustLevel);
        
        HRESULT ( STDMETHODCALLTYPE *GetForWindow )( 
            IUserActivityRequestManagerInterop * This,
            /* [annotation][in] */ 
            _In_  HWND window,
            /* [annotation][in] */ 
            _In_  REFIID iid,
            /* [annotation][retval][iid_is][out] */ 
            _COM_Outptr_retval_  void **value);
        
        END_INTERFACE
    } IUserActivityRequestManagerInteropVtbl;

    interface IUserActivityRequestManagerInterop
    {
        CONST_VTBL struct IUserActivityRequestManagerInteropVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IUserActivityRequestManagerInterop_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IUserActivityRequestManagerInterop_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IUserActivityRequestManagerInterop_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IUserActivityRequestManagerInterop_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define IUserActivityRequestManagerInterop_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define IUserActivityRequestManagerInterop_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define IUserActivityRequestManagerInterop_GetForWindow(This,window,iid,value)	\
    ( (This)->lpVtbl -> GetForWindow(This,window,iid,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IUserActivityRequestManagerInterop_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_useractivityinterop_0000_0003 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion
#endif /* (NTDDI_VERSION >= NTDDI_WIN10_RS4) */


extern RPC_IF_HANDLE __MIDL_itf_useractivityinterop_0000_0003_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_useractivityinterop_0000_0003_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


