

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0628 */
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 501
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

#ifndef __windows2Edevices2Ealljoyn2Einterop_h__
#define __windows2Edevices2Ealljoyn2Einterop_h__

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

#ifndef __IWindowsDevicesAllJoynBusAttachmentInterop_FWD_DEFINED__
#define __IWindowsDevicesAllJoynBusAttachmentInterop_FWD_DEFINED__
typedef interface IWindowsDevicesAllJoynBusAttachmentInterop IWindowsDevicesAllJoynBusAttachmentInterop;

#endif 	/* __IWindowsDevicesAllJoynBusAttachmentInterop_FWD_DEFINED__ */


#ifndef __IWindowsDevicesAllJoynBusAttachmentFactoryInterop_FWD_DEFINED__
#define __IWindowsDevicesAllJoynBusAttachmentFactoryInterop_FWD_DEFINED__
typedef interface IWindowsDevicesAllJoynBusAttachmentFactoryInterop IWindowsDevicesAllJoynBusAttachmentFactoryInterop;

#endif 	/* __IWindowsDevicesAllJoynBusAttachmentFactoryInterop_FWD_DEFINED__ */


#ifndef __IWindowsDevicesAllJoynBusObjectInterop_FWD_DEFINED__
#define __IWindowsDevicesAllJoynBusObjectInterop_FWD_DEFINED__
typedef interface IWindowsDevicesAllJoynBusObjectInterop IWindowsDevicesAllJoynBusObjectInterop;

#endif 	/* __IWindowsDevicesAllJoynBusObjectInterop_FWD_DEFINED__ */


#ifndef __IWindowsDevicesAllJoynBusObjectFactoryInterop_FWD_DEFINED__
#define __IWindowsDevicesAllJoynBusObjectFactoryInterop_FWD_DEFINED__
typedef interface IWindowsDevicesAllJoynBusObjectFactoryInterop IWindowsDevicesAllJoynBusObjectFactoryInterop;

#endif 	/* __IWindowsDevicesAllJoynBusObjectFactoryInterop_FWD_DEFINED__ */


/* header files for imported files */
#include "Inspectable.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_windows2Edevices2Ealljoyn2Einterop_0000_0000 */
/* [local] */ 

//
//   The following declarations within the 'if 0' block are dummy typedefs used to make
//   the Windows.Devices.AllJoyn.idl file build.  The actual definitions are contained in MsgArg.h
//
#if 0
typedef void *alljoyn_msgarg;

typedef const CHAR *PCSTR;

#endif
#include <alljoyn_c\BusAttachment.h>
#include <alljoyn_c\BusObject.h>
#include <alljoyn_c\MsgArg.h>
#if (NTDDI_VERSION >= NTDDI_WINTHRESHOLD)


extern RPC_IF_HANDLE __MIDL_itf_windows2Edevices2Ealljoyn2Einterop_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_windows2Edevices2Ealljoyn2Einterop_0000_0000_v0_0_s_ifspec;

#ifndef __IWindowsDevicesAllJoynBusAttachmentInterop_INTERFACE_DEFINED__
#define __IWindowsDevicesAllJoynBusAttachmentInterop_INTERFACE_DEFINED__

/* interface IWindowsDevicesAllJoynBusAttachmentInterop */
/* [object][uuid][local] */ 


EXTERN_C const IID IID_IWindowsDevicesAllJoynBusAttachmentInterop;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("fd89c65b-b50e-4a19-9d0c-b42b783281cd")
    IWindowsDevicesAllJoynBusAttachmentInterop : public IInspectable
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Win32Handle( 
            /* [retval][out] */ UINT64 *value) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWindowsDevicesAllJoynBusAttachmentInteropVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWindowsDevicesAllJoynBusAttachmentInterop * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWindowsDevicesAllJoynBusAttachmentInterop * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWindowsDevicesAllJoynBusAttachmentInterop * This);
        
        DECLSPEC_XFGVIRT(IInspectable, GetIids)
        HRESULT ( STDMETHODCALLTYPE *GetIids )( 
            IWindowsDevicesAllJoynBusAttachmentInterop * This,
            /* [out] */ ULONG *iidCount,
            /* [size_is][size_is][out] */ IID **iids);
        
        DECLSPEC_XFGVIRT(IInspectable, GetRuntimeClassName)
        HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )( 
            IWindowsDevicesAllJoynBusAttachmentInterop * This,
            /* [out] */ HSTRING *className);
        
        DECLSPEC_XFGVIRT(IInspectable, GetTrustLevel)
        HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )( 
            IWindowsDevicesAllJoynBusAttachmentInterop * This,
            /* [out] */ TrustLevel *trustLevel);
        
        DECLSPEC_XFGVIRT(IWindowsDevicesAllJoynBusAttachmentInterop, get_Win32Handle)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Win32Handle )( 
            IWindowsDevicesAllJoynBusAttachmentInterop * This,
            /* [retval][out] */ UINT64 *value);
        
        END_INTERFACE
    } IWindowsDevicesAllJoynBusAttachmentInteropVtbl;

    interface IWindowsDevicesAllJoynBusAttachmentInterop
    {
        CONST_VTBL struct IWindowsDevicesAllJoynBusAttachmentInteropVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWindowsDevicesAllJoynBusAttachmentInterop_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWindowsDevicesAllJoynBusAttachmentInterop_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWindowsDevicesAllJoynBusAttachmentInterop_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWindowsDevicesAllJoynBusAttachmentInterop_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define IWindowsDevicesAllJoynBusAttachmentInterop_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define IWindowsDevicesAllJoynBusAttachmentInterop_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define IWindowsDevicesAllJoynBusAttachmentInterop_get_Win32Handle(This,value)	\
    ( (This)->lpVtbl -> get_Win32Handle(This,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWindowsDevicesAllJoynBusAttachmentInterop_INTERFACE_DEFINED__ */


#ifndef __IWindowsDevicesAllJoynBusAttachmentFactoryInterop_INTERFACE_DEFINED__
#define __IWindowsDevicesAllJoynBusAttachmentFactoryInterop_INTERFACE_DEFINED__

/* interface IWindowsDevicesAllJoynBusAttachmentFactoryInterop */
/* [object][uuid][local] */ 


EXTERN_C const IID IID_IWindowsDevicesAllJoynBusAttachmentFactoryInterop;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4b8f7505-b239-4e7b-88af-f6682575d861")
    IWindowsDevicesAllJoynBusAttachmentFactoryInterop : public IInspectable
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CreateFromWin32Handle( 
            /* [in] */ UINT64 win32handle,
            /* [in] */ boolean enableAboutData,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppv) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWindowsDevicesAllJoynBusAttachmentFactoryInteropVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWindowsDevicesAllJoynBusAttachmentFactoryInterop * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWindowsDevicesAllJoynBusAttachmentFactoryInterop * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWindowsDevicesAllJoynBusAttachmentFactoryInterop * This);
        
        DECLSPEC_XFGVIRT(IInspectable, GetIids)
        HRESULT ( STDMETHODCALLTYPE *GetIids )( 
            IWindowsDevicesAllJoynBusAttachmentFactoryInterop * This,
            /* [out] */ ULONG *iidCount,
            /* [size_is][size_is][out] */ IID **iids);
        
        DECLSPEC_XFGVIRT(IInspectable, GetRuntimeClassName)
        HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )( 
            IWindowsDevicesAllJoynBusAttachmentFactoryInterop * This,
            /* [out] */ HSTRING *className);
        
        DECLSPEC_XFGVIRT(IInspectable, GetTrustLevel)
        HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )( 
            IWindowsDevicesAllJoynBusAttachmentFactoryInterop * This,
            /* [out] */ TrustLevel *trustLevel);
        
        DECLSPEC_XFGVIRT(IWindowsDevicesAllJoynBusAttachmentFactoryInterop, CreateFromWin32Handle)
        HRESULT ( STDMETHODCALLTYPE *CreateFromWin32Handle )( 
            IWindowsDevicesAllJoynBusAttachmentFactoryInterop * This,
            /* [in] */ UINT64 win32handle,
            /* [in] */ boolean enableAboutData,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppv);
        
        END_INTERFACE
    } IWindowsDevicesAllJoynBusAttachmentFactoryInteropVtbl;

    interface IWindowsDevicesAllJoynBusAttachmentFactoryInterop
    {
        CONST_VTBL struct IWindowsDevicesAllJoynBusAttachmentFactoryInteropVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWindowsDevicesAllJoynBusAttachmentFactoryInterop_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWindowsDevicesAllJoynBusAttachmentFactoryInterop_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWindowsDevicesAllJoynBusAttachmentFactoryInterop_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWindowsDevicesAllJoynBusAttachmentFactoryInterop_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define IWindowsDevicesAllJoynBusAttachmentFactoryInterop_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define IWindowsDevicesAllJoynBusAttachmentFactoryInterop_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define IWindowsDevicesAllJoynBusAttachmentFactoryInterop_CreateFromWin32Handle(This,win32handle,enableAboutData,riid,ppv)	\
    ( (This)->lpVtbl -> CreateFromWin32Handle(This,win32handle,enableAboutData,riid,ppv) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWindowsDevicesAllJoynBusAttachmentFactoryInterop_INTERFACE_DEFINED__ */


#ifndef __IWindowsDevicesAllJoynBusObjectInterop_INTERFACE_DEFINED__
#define __IWindowsDevicesAllJoynBusObjectInterop_INTERFACE_DEFINED__

/* interface IWindowsDevicesAllJoynBusObjectInterop */
/* [object][uuid][local] */ 


EXTERN_C const IID IID_IWindowsDevicesAllJoynBusObjectInterop;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("d78aa3d5-5054-428f-99f2-ec3a5de3c3bc")
    IWindowsDevicesAllJoynBusObjectInterop : public IInspectable
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AddPropertyGetHandler( 
            /* [in] */ PVOID context,
            /* [in] */ HSTRING interfaceName,
            /* [in] */ INT32 ( STDMETHODCALLTYPE *callback )( 
                PVOID context,
                HSTRING interfaceName,
                HSTRING propertyName,
                alljoyn_msgarg value)) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddPropertySetHandler( 
            /* [in] */ PVOID context,
            /* [in] */ HSTRING interfaceName,
            /* [in] */ INT32 ( STDMETHODCALLTYPE *callback )( 
                PVOID context,
                HSTRING interfaceName,
                HSTRING propertyName,
                alljoyn_msgarg value)) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Win32Handle( 
            /* [retval][out] */ UINT64 *value) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWindowsDevicesAllJoynBusObjectInteropVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWindowsDevicesAllJoynBusObjectInterop * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWindowsDevicesAllJoynBusObjectInterop * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWindowsDevicesAllJoynBusObjectInterop * This);
        
        DECLSPEC_XFGVIRT(IInspectable, GetIids)
        HRESULT ( STDMETHODCALLTYPE *GetIids )( 
            IWindowsDevicesAllJoynBusObjectInterop * This,
            /* [out] */ ULONG *iidCount,
            /* [size_is][size_is][out] */ IID **iids);
        
        DECLSPEC_XFGVIRT(IInspectable, GetRuntimeClassName)
        HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )( 
            IWindowsDevicesAllJoynBusObjectInterop * This,
            /* [out] */ HSTRING *className);
        
        DECLSPEC_XFGVIRT(IInspectable, GetTrustLevel)
        HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )( 
            IWindowsDevicesAllJoynBusObjectInterop * This,
            /* [out] */ TrustLevel *trustLevel);
        
        DECLSPEC_XFGVIRT(IWindowsDevicesAllJoynBusObjectInterop, AddPropertyGetHandler)
        HRESULT ( STDMETHODCALLTYPE *AddPropertyGetHandler )( 
            IWindowsDevicesAllJoynBusObjectInterop * This,
            /* [in] */ PVOID context,
            /* [in] */ HSTRING interfaceName,
            /* [in] */ INT32 ( STDMETHODCALLTYPE *callback )( 
                PVOID context,
                HSTRING interfaceName,
                HSTRING propertyName,
                alljoyn_msgarg value));
        
        DECLSPEC_XFGVIRT(IWindowsDevicesAllJoynBusObjectInterop, AddPropertySetHandler)
        HRESULT ( STDMETHODCALLTYPE *AddPropertySetHandler )( 
            IWindowsDevicesAllJoynBusObjectInterop * This,
            /* [in] */ PVOID context,
            /* [in] */ HSTRING interfaceName,
            /* [in] */ INT32 ( STDMETHODCALLTYPE *callback )( 
                PVOID context,
                HSTRING interfaceName,
                HSTRING propertyName,
                alljoyn_msgarg value));
        
        DECLSPEC_XFGVIRT(IWindowsDevicesAllJoynBusObjectInterop, get_Win32Handle)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Win32Handle )( 
            IWindowsDevicesAllJoynBusObjectInterop * This,
            /* [retval][out] */ UINT64 *value);
        
        END_INTERFACE
    } IWindowsDevicesAllJoynBusObjectInteropVtbl;

    interface IWindowsDevicesAllJoynBusObjectInterop
    {
        CONST_VTBL struct IWindowsDevicesAllJoynBusObjectInteropVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWindowsDevicesAllJoynBusObjectInterop_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWindowsDevicesAllJoynBusObjectInterop_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWindowsDevicesAllJoynBusObjectInterop_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWindowsDevicesAllJoynBusObjectInterop_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define IWindowsDevicesAllJoynBusObjectInterop_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define IWindowsDevicesAllJoynBusObjectInterop_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define IWindowsDevicesAllJoynBusObjectInterop_AddPropertyGetHandler(This,context,interfaceName,callback)	\
    ( (This)->lpVtbl -> AddPropertyGetHandler(This,context,interfaceName,callback) ) 

#define IWindowsDevicesAllJoynBusObjectInterop_AddPropertySetHandler(This,context,interfaceName,callback)	\
    ( (This)->lpVtbl -> AddPropertySetHandler(This,context,interfaceName,callback) ) 

#define IWindowsDevicesAllJoynBusObjectInterop_get_Win32Handle(This,value)	\
    ( (This)->lpVtbl -> get_Win32Handle(This,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWindowsDevicesAllJoynBusObjectInterop_INTERFACE_DEFINED__ */


#ifndef __IWindowsDevicesAllJoynBusObjectFactoryInterop_INTERFACE_DEFINED__
#define __IWindowsDevicesAllJoynBusObjectFactoryInterop_INTERFACE_DEFINED__

/* interface IWindowsDevicesAllJoynBusObjectFactoryInterop */
/* [object][uuid][local] */ 


EXTERN_C const IID IID_IWindowsDevicesAllJoynBusObjectFactoryInterop;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6174e506-8b95-4e36-95c0-b88fed34938c")
    IWindowsDevicesAllJoynBusObjectFactoryInterop : public IInspectable
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CreateFromWin32Handle( 
            /* [in] */ UINT64 win32handle,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppv) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWindowsDevicesAllJoynBusObjectFactoryInteropVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWindowsDevicesAllJoynBusObjectFactoryInterop * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWindowsDevicesAllJoynBusObjectFactoryInterop * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWindowsDevicesAllJoynBusObjectFactoryInterop * This);
        
        DECLSPEC_XFGVIRT(IInspectable, GetIids)
        HRESULT ( STDMETHODCALLTYPE *GetIids )( 
            IWindowsDevicesAllJoynBusObjectFactoryInterop * This,
            /* [out] */ ULONG *iidCount,
            /* [size_is][size_is][out] */ IID **iids);
        
        DECLSPEC_XFGVIRT(IInspectable, GetRuntimeClassName)
        HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )( 
            IWindowsDevicesAllJoynBusObjectFactoryInterop * This,
            /* [out] */ HSTRING *className);
        
        DECLSPEC_XFGVIRT(IInspectable, GetTrustLevel)
        HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )( 
            IWindowsDevicesAllJoynBusObjectFactoryInterop * This,
            /* [out] */ TrustLevel *trustLevel);
        
        DECLSPEC_XFGVIRT(IWindowsDevicesAllJoynBusObjectFactoryInterop, CreateFromWin32Handle)
        HRESULT ( STDMETHODCALLTYPE *CreateFromWin32Handle )( 
            IWindowsDevicesAllJoynBusObjectFactoryInterop * This,
            /* [in] */ UINT64 win32handle,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppv);
        
        END_INTERFACE
    } IWindowsDevicesAllJoynBusObjectFactoryInteropVtbl;

    interface IWindowsDevicesAllJoynBusObjectFactoryInterop
    {
        CONST_VTBL struct IWindowsDevicesAllJoynBusObjectFactoryInteropVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWindowsDevicesAllJoynBusObjectFactoryInterop_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWindowsDevicesAllJoynBusObjectFactoryInterop_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWindowsDevicesAllJoynBusObjectFactoryInterop_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWindowsDevicesAllJoynBusObjectFactoryInterop_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define IWindowsDevicesAllJoynBusObjectFactoryInterop_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define IWindowsDevicesAllJoynBusObjectFactoryInterop_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define IWindowsDevicesAllJoynBusObjectFactoryInterop_CreateFromWin32Handle(This,win32handle,riid,ppv)	\
    ( (This)->lpVtbl -> CreateFromWin32Handle(This,win32handle,riid,ppv) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWindowsDevicesAllJoynBusObjectFactoryInterop_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_windows2Edevices2Ealljoyn2Einterop_0000_0004 */
/* [local] */ 

#endif //(NTDDI_VERSION >= NTDDI_WINTHRESHOLD)


extern RPC_IF_HANDLE __MIDL_itf_windows2Edevices2Ealljoyn2Einterop_0000_0004_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_windows2Edevices2Ealljoyn2Einterop_0000_0004_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


