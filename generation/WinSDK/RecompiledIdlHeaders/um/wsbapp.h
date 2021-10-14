

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

#ifndef __wsbapp_h__
#define __wsbapp_h__

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

#ifndef __IWsbApplicationBackupSupport_FWD_DEFINED__
#define __IWsbApplicationBackupSupport_FWD_DEFINED__
typedef interface IWsbApplicationBackupSupport IWsbApplicationBackupSupport;

#endif 	/* __IWsbApplicationBackupSupport_FWD_DEFINED__ */


#ifndef __IWsbApplicationRestoreSupport_FWD_DEFINED__
#define __IWsbApplicationRestoreSupport_FWD_DEFINED__
typedef interface IWsbApplicationRestoreSupport IWsbApplicationRestoreSupport;

#endif 	/* __IWsbApplicationRestoreSupport_FWD_DEFINED__ */


#ifndef __IWsbApplicationAsync_FWD_DEFINED__
#define __IWsbApplicationAsync_FWD_DEFINED__
typedef interface IWsbApplicationAsync IWsbApplicationAsync;

#endif 	/* __IWsbApplicationAsync_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_wsbapp_0000_0000 */
/* [local] */ 

#include <winapifamily.h>
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)



extern RPC_IF_HANDLE __MIDL_itf_wsbapp_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_wsbapp_0000_0000_v0_0_s_ifspec;

#ifndef __IWsbApplicationBackupSupport_INTERFACE_DEFINED__
#define __IWsbApplicationBackupSupport_INTERFACE_DEFINED__

/* interface IWsbApplicationBackupSupport */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWsbApplicationBackupSupport;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1EFF3510-4A27-46ad-B9E0-08332F0F4F6D")
    IWsbApplicationBackupSupport : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CheckConsistency( 
            /* [annotation][string][unique][in] */ 
            _In_  LPWSTR wszWriterMetadata,
            /* [annotation][string][unique][in] */ 
            _In_  LPWSTR wszComponentName,
            /* [annotation][string][unique][in] */ 
            _In_  LPWSTR wszComponentLogicalPath,
            /* [annotation][in][range] */ 
            _In_  DWORD cVolumes,
            /* [annotation][size_is][string][unique][in] */ 
            _In_reads_(cVolumes)  LPWSTR *rgwszSourceVolumePath,
            /* [annotation][size_is][string][unique][in] */ 
            _In_reads_(cVolumes)  LPWSTR *rgwszSnapshotVolumePath,
            /* [annotation][out] */ 
            _Out_  IWsbApplicationAsync **ppAsync) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWsbApplicationBackupSupportVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IWsbApplicationBackupSupport * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IWsbApplicationBackupSupport * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IWsbApplicationBackupSupport * This);
        
        DECLSPEC_XFGVIRT(IWsbApplicationBackupSupport, CheckConsistency)
        HRESULT ( STDMETHODCALLTYPE *CheckConsistency )( 
            __RPC__in IWsbApplicationBackupSupport * This,
            /* [annotation][string][unique][in] */ 
            _In_  LPWSTR wszWriterMetadata,
            /* [annotation][string][unique][in] */ 
            _In_  LPWSTR wszComponentName,
            /* [annotation][string][unique][in] */ 
            _In_  LPWSTR wszComponentLogicalPath,
            /* [annotation][in][range] */ 
            _In_  DWORD cVolumes,
            /* [annotation][size_is][string][unique][in] */ 
            _In_reads_(cVolumes)  LPWSTR *rgwszSourceVolumePath,
            /* [annotation][size_is][string][unique][in] */ 
            _In_reads_(cVolumes)  LPWSTR *rgwszSnapshotVolumePath,
            /* [annotation][out] */ 
            _Out_  IWsbApplicationAsync **ppAsync);
        
        END_INTERFACE
    } IWsbApplicationBackupSupportVtbl;

    interface IWsbApplicationBackupSupport
    {
        CONST_VTBL struct IWsbApplicationBackupSupportVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWsbApplicationBackupSupport_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWsbApplicationBackupSupport_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWsbApplicationBackupSupport_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWsbApplicationBackupSupport_CheckConsistency(This,wszWriterMetadata,wszComponentName,wszComponentLogicalPath,cVolumes,rgwszSourceVolumePath,rgwszSnapshotVolumePath,ppAsync)	\
    ( (This)->lpVtbl -> CheckConsistency(This,wszWriterMetadata,wszComponentName,wszComponentLogicalPath,cVolumes,rgwszSourceVolumePath,rgwszSnapshotVolumePath,ppAsync) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWsbApplicationBackupSupport_INTERFACE_DEFINED__ */


#ifndef __IWsbApplicationRestoreSupport_INTERFACE_DEFINED__
#define __IWsbApplicationRestoreSupport_INTERFACE_DEFINED__

/* interface IWsbApplicationRestoreSupport */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWsbApplicationRestoreSupport;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8D3BDB38-4EE8-4718-85F9-C7DBC4AB77AA")
    IWsbApplicationRestoreSupport : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE PreRestore( 
            /* [annotation][string][unique][in] */ 
            _In_  LPWSTR wszWriterMetadata,
            /* [annotation][string][unique][in] */ 
            _In_  LPWSTR wszComponentName,
            /* [annotation][string][unique][in] */ 
            _In_  LPWSTR wszComponentLogicalPath,
            /* [annotation][in] */ 
            _In_  BOOLEAN bNoRollForward) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PostRestore( 
            /* [annotation][string][unique][in] */ 
            _In_  LPWSTR wszWriterMetadata,
            /* [annotation][string][unique][in] */ 
            _In_  LPWSTR wszComponentName,
            /* [annotation][string][unique][in] */ 
            _In_  LPWSTR wszComponentLogicalPath,
            /* [annotation][in] */ 
            _In_  BOOLEAN bNoRollForward) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OrderComponents( 
            /* [annotation][in][range] */ 
            _In_  DWORD cComponents,
            /* [annotation][size_is][string][in] */ 
            _In_reads_(cComponents)  LPWSTR *rgComponentName,
            /* [annotation][size_is][string][in] */ 
            _In_reads_(cComponents)  LPWSTR *rgComponentLogicalPaths,
            /* [annotation][size_is][size_is][string][out] */ 
            _Out_writes_(cComponents)  LPWSTR **prgComponentName,
            /* [annotation][size_is][size_is][string][out] */ 
            _Out_writes_(cComponents)  LPWSTR **prgComponentLogicalPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsRollForwardSupported( 
            /* [annotation][out] */ 
            _Out_  BOOLEAN *pbRollForwardSupported) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWsbApplicationRestoreSupportVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IWsbApplicationRestoreSupport * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IWsbApplicationRestoreSupport * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IWsbApplicationRestoreSupport * This);
        
        DECLSPEC_XFGVIRT(IWsbApplicationRestoreSupport, PreRestore)
        HRESULT ( STDMETHODCALLTYPE *PreRestore )( 
            __RPC__in IWsbApplicationRestoreSupport * This,
            /* [annotation][string][unique][in] */ 
            _In_  LPWSTR wszWriterMetadata,
            /* [annotation][string][unique][in] */ 
            _In_  LPWSTR wszComponentName,
            /* [annotation][string][unique][in] */ 
            _In_  LPWSTR wszComponentLogicalPath,
            /* [annotation][in] */ 
            _In_  BOOLEAN bNoRollForward);
        
        DECLSPEC_XFGVIRT(IWsbApplicationRestoreSupport, PostRestore)
        HRESULT ( STDMETHODCALLTYPE *PostRestore )( 
            __RPC__in IWsbApplicationRestoreSupport * This,
            /* [annotation][string][unique][in] */ 
            _In_  LPWSTR wszWriterMetadata,
            /* [annotation][string][unique][in] */ 
            _In_  LPWSTR wszComponentName,
            /* [annotation][string][unique][in] */ 
            _In_  LPWSTR wszComponentLogicalPath,
            /* [annotation][in] */ 
            _In_  BOOLEAN bNoRollForward);
        
        DECLSPEC_XFGVIRT(IWsbApplicationRestoreSupport, OrderComponents)
        HRESULT ( STDMETHODCALLTYPE *OrderComponents )( 
            __RPC__in IWsbApplicationRestoreSupport * This,
            /* [annotation][in][range] */ 
            _In_  DWORD cComponents,
            /* [annotation][size_is][string][in] */ 
            _In_reads_(cComponents)  LPWSTR *rgComponentName,
            /* [annotation][size_is][string][in] */ 
            _In_reads_(cComponents)  LPWSTR *rgComponentLogicalPaths,
            /* [annotation][size_is][size_is][string][out] */ 
            _Out_writes_(cComponents)  LPWSTR **prgComponentName,
            /* [annotation][size_is][size_is][string][out] */ 
            _Out_writes_(cComponents)  LPWSTR **prgComponentLogicalPath);
        
        DECLSPEC_XFGVIRT(IWsbApplicationRestoreSupport, IsRollForwardSupported)
        HRESULT ( STDMETHODCALLTYPE *IsRollForwardSupported )( 
            __RPC__in IWsbApplicationRestoreSupport * This,
            /* [annotation][out] */ 
            _Out_  BOOLEAN *pbRollForwardSupported);
        
        END_INTERFACE
    } IWsbApplicationRestoreSupportVtbl;

    interface IWsbApplicationRestoreSupport
    {
        CONST_VTBL struct IWsbApplicationRestoreSupportVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWsbApplicationRestoreSupport_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWsbApplicationRestoreSupport_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWsbApplicationRestoreSupport_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWsbApplicationRestoreSupport_PreRestore(This,wszWriterMetadata,wszComponentName,wszComponentLogicalPath,bNoRollForward)	\
    ( (This)->lpVtbl -> PreRestore(This,wszWriterMetadata,wszComponentName,wszComponentLogicalPath,bNoRollForward) ) 

#define IWsbApplicationRestoreSupport_PostRestore(This,wszWriterMetadata,wszComponentName,wszComponentLogicalPath,bNoRollForward)	\
    ( (This)->lpVtbl -> PostRestore(This,wszWriterMetadata,wszComponentName,wszComponentLogicalPath,bNoRollForward) ) 

#define IWsbApplicationRestoreSupport_OrderComponents(This,cComponents,rgComponentName,rgComponentLogicalPaths,prgComponentName,prgComponentLogicalPath)	\
    ( (This)->lpVtbl -> OrderComponents(This,cComponents,rgComponentName,rgComponentLogicalPaths,prgComponentName,prgComponentLogicalPath) ) 

#define IWsbApplicationRestoreSupport_IsRollForwardSupported(This,pbRollForwardSupported)	\
    ( (This)->lpVtbl -> IsRollForwardSupported(This,pbRollForwardSupported) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWsbApplicationRestoreSupport_INTERFACE_DEFINED__ */


#ifndef __IWsbApplicationAsync_INTERFACE_DEFINED__
#define __IWsbApplicationAsync_INTERFACE_DEFINED__

/* interface IWsbApplicationAsync */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWsbApplicationAsync;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0843F6F7-895C-44a6-B0C2-05A5022AA3A1")
    IWsbApplicationAsync : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE QueryStatus( 
            /* [annotation][out] */ 
            _Out_  HRESULT *phrResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Abort( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWsbApplicationAsyncVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IWsbApplicationAsync * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IWsbApplicationAsync * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IWsbApplicationAsync * This);
        
        DECLSPEC_XFGVIRT(IWsbApplicationAsync, QueryStatus)
        HRESULT ( STDMETHODCALLTYPE *QueryStatus )( 
            __RPC__in IWsbApplicationAsync * This,
            /* [annotation][out] */ 
            _Out_  HRESULT *phrResult);
        
        DECLSPEC_XFGVIRT(IWsbApplicationAsync, Abort)
        HRESULT ( STDMETHODCALLTYPE *Abort )( 
            __RPC__in IWsbApplicationAsync * This);
        
        END_INTERFACE
    } IWsbApplicationAsyncVtbl;

    interface IWsbApplicationAsync
    {
        CONST_VTBL struct IWsbApplicationAsyncVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWsbApplicationAsync_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWsbApplicationAsync_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWsbApplicationAsync_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWsbApplicationAsync_QueryStatus(This,phrResult)	\
    ( (This)->lpVtbl -> QueryStatus(This,phrResult) ) 

#define IWsbApplicationAsync_Abort(This)	\
    ( (This)->lpVtbl -> Abort(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWsbApplicationAsync_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_wsbapp_0000_0003 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_wsbapp_0000_0003_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_wsbapp_0000_0003_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


