

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

#ifndef __workspaceruntimeclientext_h__
#define __workspaceruntimeclientext_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IWorkspaceClientExt_FWD_DEFINED__
#define __IWorkspaceClientExt_FWD_DEFINED__
typedef interface IWorkspaceClientExt IWorkspaceClientExt;

#endif 	/* __IWorkspaceClientExt_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_workspaceruntimeclientext_0000_0000 */
/* [local] */ 

#include <winapifamily.h>
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)


extern RPC_IF_HANDLE __MIDL_itf_workspaceruntimeclientext_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_workspaceruntimeclientext_0000_0000_v0_0_s_ifspec;

#ifndef __IWorkspaceClientExt_INTERFACE_DEFINED__
#define __IWorkspaceClientExt_INTERFACE_DEFINED__

/* interface IWorkspaceClientExt */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWorkspaceClientExt;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("12B952F4-41CA-4F21-A829-A6D07D9A16E5")
    IWorkspaceClientExt : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetResourceId( 
            /* [annotation][out] */ 
            _Out_  BSTR *bstrWorkspaceId) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetResourceDisplayName( 
            /* [annotation][out] */ 
            _Out_  BSTR *bstrWorkspaceDisplayName) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE IssueDisconnect( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWorkspaceClientExtVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IWorkspaceClientExt * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IWorkspaceClientExt * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IWorkspaceClientExt * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetResourceId )( 
            __RPC__in IWorkspaceClientExt * This,
            /* [annotation][out] */ 
            _Out_  BSTR *bstrWorkspaceId);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetResourceDisplayName )( 
            __RPC__in IWorkspaceClientExt * This,
            /* [annotation][out] */ 
            _Out_  BSTR *bstrWorkspaceDisplayName);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *IssueDisconnect )( 
            __RPC__in IWorkspaceClientExt * This);
        
        END_INTERFACE
    } IWorkspaceClientExtVtbl;

    interface IWorkspaceClientExt
    {
        CONST_VTBL struct IWorkspaceClientExtVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWorkspaceClientExt_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWorkspaceClientExt_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWorkspaceClientExt_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWorkspaceClientExt_GetResourceId(This,bstrWorkspaceId)	\
    ( (This)->lpVtbl -> GetResourceId(This,bstrWorkspaceId) ) 

#define IWorkspaceClientExt_GetResourceDisplayName(This,bstrWorkspaceDisplayName)	\
    ( (This)->lpVtbl -> GetResourceDisplayName(This,bstrWorkspaceDisplayName) ) 

#define IWorkspaceClientExt_IssueDisconnect(This)	\
    ( (This)->lpVtbl -> IssueDisconnect(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWorkspaceClientExt_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_workspaceruntimeclientext_0000_0001 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_workspaceruntimeclientext_0000_0001_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_workspaceruntimeclientext_0000_0001_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     __RPC__in unsigned long *, unsigned long            , __RPC__in BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     __RPC__in unsigned long *, __RPC__in BSTR * ); 

unsigned long             __RPC_USER  BSTR_UserSize64(     __RPC__in unsigned long *, unsigned long            , __RPC__in BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal64(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal64(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out BSTR * ); 
void                      __RPC_USER  BSTR_UserFree64(     __RPC__in unsigned long *, __RPC__in BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


