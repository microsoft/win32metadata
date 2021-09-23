

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

#ifndef __knownfolderpathscom_h__
#define __knownfolderpathscom_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IUserDataPathsInterop_FWD_DEFINED__
#define __IUserDataPathsInterop_FWD_DEFINED__
typedef interface IUserDataPathsInterop IUserDataPathsInterop;

#endif 	/* __IUserDataPathsInterop_FWD_DEFINED__ */


#ifndef __ISystemDataPathsInterop_FWD_DEFINED__
#define __ISystemDataPathsInterop_FWD_DEFINED__
typedef interface ISystemDataPathsInterop ISystemDataPathsInterop;

#endif 	/* __ISystemDataPathsInterop_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_knownfolderpathscom_0000_0000 */
/* [local] */ 

#include <winapifamily.h>
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)


extern RPC_IF_HANDLE __MIDL_itf_knownfolderpathscom_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_knownfolderpathscom_0000_0000_v0_0_s_ifspec;

#ifndef __IUserDataPathsInterop_INTERFACE_DEFINED__
#define __IUserDataPathsInterop_INTERFACE_DEFINED__

/* interface IUserDataPathsInterop */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IUserDataPathsInterop;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F12EF0B5-BEFB-46C9-9EE5-8A0681F13F8C")
    IUserDataPathsInterop : public IUnknown
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_AdminTools( 
            /* [annotation][retval][string][out] */ 
            _Out_retval_  LPWSTR *value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CDBurning( 
            /* [annotation][retval][string][out] */ 
            _Out_retval_  LPWSTR *value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_NetworkShortcuts( 
            /* [annotation][retval][string][out] */ 
            _Out_retval_  LPWSTR *value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Programs( 
            /* [annotation][retval][string][out] */ 
            _Out_retval_  LPWSTR *value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_SendTo( 
            /* [annotation][retval][string][out] */ 
            _Out_retval_  LPWSTR *value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_StartMenu( 
            /* [annotation][retval][string][out] */ 
            _Out_retval_  LPWSTR *value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Startup( 
            /* [annotation][retval][string][out] */ 
            _Out_retval_  LPWSTR *value) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IUserDataPathsInteropVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IUserDataPathsInterop * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IUserDataPathsInterop * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IUserDataPathsInterop * This);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_AdminTools )( 
            __RPC__in IUserDataPathsInterop * This,
            /* [annotation][retval][string][out] */ 
            _Out_retval_  LPWSTR *value);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_CDBurning )( 
            __RPC__in IUserDataPathsInterop * This,
            /* [annotation][retval][string][out] */ 
            _Out_retval_  LPWSTR *value);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_NetworkShortcuts )( 
            __RPC__in IUserDataPathsInterop * This,
            /* [annotation][retval][string][out] */ 
            _Out_retval_  LPWSTR *value);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Programs )( 
            __RPC__in IUserDataPathsInterop * This,
            /* [annotation][retval][string][out] */ 
            _Out_retval_  LPWSTR *value);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_SendTo )( 
            __RPC__in IUserDataPathsInterop * This,
            /* [annotation][retval][string][out] */ 
            _Out_retval_  LPWSTR *value);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_StartMenu )( 
            __RPC__in IUserDataPathsInterop * This,
            /* [annotation][retval][string][out] */ 
            _Out_retval_  LPWSTR *value);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Startup )( 
            __RPC__in IUserDataPathsInterop * This,
            /* [annotation][retval][string][out] */ 
            _Out_retval_  LPWSTR *value);
        
        END_INTERFACE
    } IUserDataPathsInteropVtbl;

    interface IUserDataPathsInterop
    {
        CONST_VTBL struct IUserDataPathsInteropVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IUserDataPathsInterop_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IUserDataPathsInterop_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IUserDataPathsInterop_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IUserDataPathsInterop_get_AdminTools(This,value)	\
    ( (This)->lpVtbl -> get_AdminTools(This,value) ) 

#define IUserDataPathsInterop_get_CDBurning(This,value)	\
    ( (This)->lpVtbl -> get_CDBurning(This,value) ) 

#define IUserDataPathsInterop_get_NetworkShortcuts(This,value)	\
    ( (This)->lpVtbl -> get_NetworkShortcuts(This,value) ) 

#define IUserDataPathsInterop_get_Programs(This,value)	\
    ( (This)->lpVtbl -> get_Programs(This,value) ) 

#define IUserDataPathsInterop_get_SendTo(This,value)	\
    ( (This)->lpVtbl -> get_SendTo(This,value) ) 

#define IUserDataPathsInterop_get_StartMenu(This,value)	\
    ( (This)->lpVtbl -> get_StartMenu(This,value) ) 

#define IUserDataPathsInterop_get_Startup(This,value)	\
    ( (This)->lpVtbl -> get_Startup(This,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IUserDataPathsInterop_INTERFACE_DEFINED__ */


#ifndef __ISystemDataPathsInterop_INTERFACE_DEFINED__
#define __ISystemDataPathsInterop_INTERFACE_DEFINED__

/* interface ISystemDataPathsInterop */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_ISystemDataPathsInterop;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("864D0B26-3A37-4251-9A02-B231198DE060")
    ISystemDataPathsInterop : public IUnknown
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CommonAdminTools( 
            /* [annotation][retval][string][out] */ 
            _Out_retval_  LPWSTR *value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CommonOemLinks( 
            /* [annotation][retval][string][out] */ 
            _Out_retval_  LPWSTR *value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CommonPrograms( 
            /* [annotation][retval][string][out] */ 
            _Out_retval_  LPWSTR *value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CommonStartMenu( 
            /* [annotation][retval][string][out] */ 
            _Out_retval_  LPWSTR *value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CommonStartup( 
            /* [annotation][retval][string][out] */ 
            _Out_retval_  LPWSTR *value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CommonTemplates( 
            /* [annotation][retval][string][out] */ 
            _Out_retval_  LPWSTR *value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_LocalizedResources( 
            /* [annotation][retval][string][out] */ 
            _Out_retval_  LPWSTR *value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_ProgramFiles( 
            /* [annotation][retval][string][out] */ 
            _Out_retval_  LPWSTR *value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_ProgramFilesCommon( 
            /* [annotation][retval][string][out] */ 
            _Out_retval_  LPWSTR *value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_ProgramFilesCommonHost( 
            /* [annotation][retval][string][out] */ 
            _Out_retval_  LPWSTR *value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_ProgramFilesCommonX64( 
            /* [annotation][retval][string][out] */ 
            _Out_retval_  LPWSTR *value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_ProgramFilesCommonX86( 
            /* [annotation][retval][string][out] */ 
            _Out_retval_  LPWSTR *value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_ProgramFilesCommonArm( 
            /* [annotation][retval][string][out] */ 
            _Out_retval_  LPWSTR *value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_ProgramFilesHost( 
            /* [annotation][retval][string][out] */ 
            _Out_retval_  LPWSTR *value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_ProgramFilesX64( 
            /* [annotation][retval][string][out] */ 
            _Out_retval_  LPWSTR *value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_ProgramFilesX86( 
            /* [annotation][retval][string][out] */ 
            _Out_retval_  LPWSTR *value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_ProgramFilesArm( 
            /* [annotation][retval][string][out] */ 
            _Out_retval_  LPWSTR *value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Resource( 
            /* [annotation][retval][string][out] */ 
            _Out_retval_  LPWSTR *value) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISystemDataPathsInteropVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISystemDataPathsInterop * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISystemDataPathsInterop * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISystemDataPathsInterop * This);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_CommonAdminTools )( 
            __RPC__in ISystemDataPathsInterop * This,
            /* [annotation][retval][string][out] */ 
            _Out_retval_  LPWSTR *value);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_CommonOemLinks )( 
            __RPC__in ISystemDataPathsInterop * This,
            /* [annotation][retval][string][out] */ 
            _Out_retval_  LPWSTR *value);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_CommonPrograms )( 
            __RPC__in ISystemDataPathsInterop * This,
            /* [annotation][retval][string][out] */ 
            _Out_retval_  LPWSTR *value);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_CommonStartMenu )( 
            __RPC__in ISystemDataPathsInterop * This,
            /* [annotation][retval][string][out] */ 
            _Out_retval_  LPWSTR *value);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_CommonStartup )( 
            __RPC__in ISystemDataPathsInterop * This,
            /* [annotation][retval][string][out] */ 
            _Out_retval_  LPWSTR *value);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_CommonTemplates )( 
            __RPC__in ISystemDataPathsInterop * This,
            /* [annotation][retval][string][out] */ 
            _Out_retval_  LPWSTR *value);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_LocalizedResources )( 
            __RPC__in ISystemDataPathsInterop * This,
            /* [annotation][retval][string][out] */ 
            _Out_retval_  LPWSTR *value);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_ProgramFiles )( 
            __RPC__in ISystemDataPathsInterop * This,
            /* [annotation][retval][string][out] */ 
            _Out_retval_  LPWSTR *value);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_ProgramFilesCommon )( 
            __RPC__in ISystemDataPathsInterop * This,
            /* [annotation][retval][string][out] */ 
            _Out_retval_  LPWSTR *value);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_ProgramFilesCommonHost )( 
            __RPC__in ISystemDataPathsInterop * This,
            /* [annotation][retval][string][out] */ 
            _Out_retval_  LPWSTR *value);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_ProgramFilesCommonX64 )( 
            __RPC__in ISystemDataPathsInterop * This,
            /* [annotation][retval][string][out] */ 
            _Out_retval_  LPWSTR *value);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_ProgramFilesCommonX86 )( 
            __RPC__in ISystemDataPathsInterop * This,
            /* [annotation][retval][string][out] */ 
            _Out_retval_  LPWSTR *value);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_ProgramFilesCommonArm )( 
            __RPC__in ISystemDataPathsInterop * This,
            /* [annotation][retval][string][out] */ 
            _Out_retval_  LPWSTR *value);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_ProgramFilesHost )( 
            __RPC__in ISystemDataPathsInterop * This,
            /* [annotation][retval][string][out] */ 
            _Out_retval_  LPWSTR *value);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_ProgramFilesX64 )( 
            __RPC__in ISystemDataPathsInterop * This,
            /* [annotation][retval][string][out] */ 
            _Out_retval_  LPWSTR *value);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_ProgramFilesX86 )( 
            __RPC__in ISystemDataPathsInterop * This,
            /* [annotation][retval][string][out] */ 
            _Out_retval_  LPWSTR *value);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_ProgramFilesArm )( 
            __RPC__in ISystemDataPathsInterop * This,
            /* [annotation][retval][string][out] */ 
            _Out_retval_  LPWSTR *value);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Resource )( 
            __RPC__in ISystemDataPathsInterop * This,
            /* [annotation][retval][string][out] */ 
            _Out_retval_  LPWSTR *value);
        
        END_INTERFACE
    } ISystemDataPathsInteropVtbl;

    interface ISystemDataPathsInterop
    {
        CONST_VTBL struct ISystemDataPathsInteropVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISystemDataPathsInterop_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISystemDataPathsInterop_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISystemDataPathsInterop_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISystemDataPathsInterop_get_CommonAdminTools(This,value)	\
    ( (This)->lpVtbl -> get_CommonAdminTools(This,value) ) 

#define ISystemDataPathsInterop_get_CommonOemLinks(This,value)	\
    ( (This)->lpVtbl -> get_CommonOemLinks(This,value) ) 

#define ISystemDataPathsInterop_get_CommonPrograms(This,value)	\
    ( (This)->lpVtbl -> get_CommonPrograms(This,value) ) 

#define ISystemDataPathsInterop_get_CommonStartMenu(This,value)	\
    ( (This)->lpVtbl -> get_CommonStartMenu(This,value) ) 

#define ISystemDataPathsInterop_get_CommonStartup(This,value)	\
    ( (This)->lpVtbl -> get_CommonStartup(This,value) ) 

#define ISystemDataPathsInterop_get_CommonTemplates(This,value)	\
    ( (This)->lpVtbl -> get_CommonTemplates(This,value) ) 

#define ISystemDataPathsInterop_get_LocalizedResources(This,value)	\
    ( (This)->lpVtbl -> get_LocalizedResources(This,value) ) 

#define ISystemDataPathsInterop_get_ProgramFiles(This,value)	\
    ( (This)->lpVtbl -> get_ProgramFiles(This,value) ) 

#define ISystemDataPathsInterop_get_ProgramFilesCommon(This,value)	\
    ( (This)->lpVtbl -> get_ProgramFilesCommon(This,value) ) 

#define ISystemDataPathsInterop_get_ProgramFilesCommonHost(This,value)	\
    ( (This)->lpVtbl -> get_ProgramFilesCommonHost(This,value) ) 

#define ISystemDataPathsInterop_get_ProgramFilesCommonX64(This,value)	\
    ( (This)->lpVtbl -> get_ProgramFilesCommonX64(This,value) ) 

#define ISystemDataPathsInterop_get_ProgramFilesCommonX86(This,value)	\
    ( (This)->lpVtbl -> get_ProgramFilesCommonX86(This,value) ) 

#define ISystemDataPathsInterop_get_ProgramFilesCommonArm(This,value)	\
    ( (This)->lpVtbl -> get_ProgramFilesCommonArm(This,value) ) 

#define ISystemDataPathsInterop_get_ProgramFilesHost(This,value)	\
    ( (This)->lpVtbl -> get_ProgramFilesHost(This,value) ) 

#define ISystemDataPathsInterop_get_ProgramFilesX64(This,value)	\
    ( (This)->lpVtbl -> get_ProgramFilesX64(This,value) ) 

#define ISystemDataPathsInterop_get_ProgramFilesX86(This,value)	\
    ( (This)->lpVtbl -> get_ProgramFilesX86(This,value) ) 

#define ISystemDataPathsInterop_get_ProgramFilesArm(This,value)	\
    ( (This)->lpVtbl -> get_ProgramFilesArm(This,value) ) 

#define ISystemDataPathsInterop_get_Resource(This,value)	\
    ( (This)->lpVtbl -> get_Resource(This,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISystemDataPathsInterop_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_knownfolderpathscom_0000_0002 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_knownfolderpathscom_0000_0002_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_knownfolderpathscom_0000_0002_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


