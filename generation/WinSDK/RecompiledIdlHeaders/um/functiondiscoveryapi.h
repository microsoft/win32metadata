

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0628 */
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

#ifndef __functiondiscoveryapi_h__
#define __functiondiscoveryapi_h__

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

#ifndef __IFunctionDiscoveryNotification_FWD_DEFINED__
#define __IFunctionDiscoveryNotification_FWD_DEFINED__
typedef interface IFunctionDiscoveryNotification IFunctionDiscoveryNotification;

#endif 	/* __IFunctionDiscoveryNotification_FWD_DEFINED__ */


#ifndef __IFunctionDiscovery_FWD_DEFINED__
#define __IFunctionDiscovery_FWD_DEFINED__
typedef interface IFunctionDiscovery IFunctionDiscovery;

#endif 	/* __IFunctionDiscovery_FWD_DEFINED__ */


#ifndef __IFunctionInstance_FWD_DEFINED__
#define __IFunctionInstance_FWD_DEFINED__
typedef interface IFunctionInstance IFunctionInstance;

#endif 	/* __IFunctionInstance_FWD_DEFINED__ */


#ifndef __IFunctionInstanceCollection_FWD_DEFINED__
#define __IFunctionInstanceCollection_FWD_DEFINED__
typedef interface IFunctionInstanceCollection IFunctionInstanceCollection;

#endif 	/* __IFunctionInstanceCollection_FWD_DEFINED__ */


#ifndef __IPropertyStoreCollection_FWD_DEFINED__
#define __IPropertyStoreCollection_FWD_DEFINED__
typedef interface IPropertyStoreCollection IPropertyStoreCollection;

#endif 	/* __IPropertyStoreCollection_FWD_DEFINED__ */


#ifndef __IFunctionInstanceQuery_FWD_DEFINED__
#define __IFunctionInstanceQuery_FWD_DEFINED__
typedef interface IFunctionInstanceQuery IFunctionInstanceQuery;

#endif 	/* __IFunctionInstanceQuery_FWD_DEFINED__ */


#ifndef __IFunctionInstanceCollectionQuery_FWD_DEFINED__
#define __IFunctionInstanceCollectionQuery_FWD_DEFINED__
typedef interface IFunctionInstanceCollectionQuery IFunctionInstanceCollectionQuery;

#endif 	/* __IFunctionInstanceCollectionQuery_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "propsys.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_functiondiscoveryapi_0000_0000 */
/* [local] */ 

#include <winapifamily.h>
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
#pragma once
#pragma warning(push)
#pragma warning(disable:4001) 
#pragma once
#pragma warning(push)
#pragma warning(disable:4001) 
#pragma once
#pragma warning(pop)
#pragma warning(pop)
#pragma region Desktop Family
typedef 
enum tagPropertyConstraint
    {
        QC_EQUALS	= 0,
        QC_NOTEQUAL	= 1,
        QC_LESSTHAN	= 2,
        QC_LESSTHANOREQUAL	= 3,
        QC_GREATERTHAN	= 4,
        QC_GREATERTHANOREQUAL	= 5,
        QC_STARTSWITH	= 6,
        QC_EXISTS	= 7,
        QC_DOESNOTEXIST	= 8,
        QC_CONTAINS	= 9
    } 	PropertyConstraint;

#pragma endregion
//#if ( WINVER >= 0x0600 )
#ifndef FD_LONGHORN
#define FD_LONGHORN 1
#endif
#ifndef FDPropertyConstraint
#define FDPropertyConstraint
#endif
#include "FunctionDiscoveryCategories.h"
#include "FunctionDiscoveryError.h"
#include "FunctionDiscoveryKeys.h"
#include "FunctionDiscoveryServiceIDs.h"
#include "FunctionDiscoveryConstraints.h"







typedef DWORDLONG FDQUERYCONTEXT;

typedef 
enum tagSystemVisibilityFlags
    {
        SVF_SYSTEM	= 0,
        SVF_USER	= 1
    } 	SystemVisibilityFlags;

typedef 
enum tagQueryUpdateAction
    {
        QUA_ADD	= 0,
        QUA_REMOVE	= 1,
        QUA_CHANGE	= 2
    } 	QueryUpdateAction;

typedef 
enum tagQueryCategoryType
    {
        QCT_PROVIDER	= 0,
        QCT_LAYERED	= 1
    } 	QueryCategoryType;



extern RPC_IF_HANDLE __MIDL_itf_functiondiscoveryapi_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_functiondiscoveryapi_0000_0000_v0_0_s_ifspec;

#ifndef __IFunctionDiscoveryNotification_INTERFACE_DEFINED__
#define __IFunctionDiscoveryNotification_INTERFACE_DEFINED__

/* interface IFunctionDiscoveryNotification */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IFunctionDiscoveryNotification;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5f6c1ba8-5330-422e-a368-572b244d3f87")
    IFunctionDiscoveryNotification : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnUpdate( 
            /* [annotation][in] */ 
            _In_  QueryUpdateAction enumQueryUpdateAction,
            /* [annotation][in] */ 
            _In_  FDQUERYCONTEXT fdqcQueryContext,
            /* [annotation][in] */ 
            _In_  IFunctionInstance *pIFunctionInstance) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnError( 
            /* [annotation][in] */ 
            _In_  HRESULT hr,
            /* [annotation][in] */ 
            _In_  FDQUERYCONTEXT fdqcQueryContext,
            /* [annotation][string][in] */ 
            _In_  const WCHAR *pszProvider) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnEvent( 
            /* [annotation][in] */ 
            _In_  DWORD dwEventID,
            /* [annotation][in] */ 
            _In_  FDQUERYCONTEXT fdqcQueryContext,
            /* [annotation][string][in] */ 
            _In_  const WCHAR *pszProvider) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IFunctionDiscoveryNotificationVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IFunctionDiscoveryNotification * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IFunctionDiscoveryNotification * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IFunctionDiscoveryNotification * This);
        
        DECLSPEC_XFGVIRT(IFunctionDiscoveryNotification, OnUpdate)
        HRESULT ( STDMETHODCALLTYPE *OnUpdate )( 
            __RPC__in IFunctionDiscoveryNotification * This,
            /* [annotation][in] */ 
            _In_  QueryUpdateAction enumQueryUpdateAction,
            /* [annotation][in] */ 
            _In_  FDQUERYCONTEXT fdqcQueryContext,
            /* [annotation][in] */ 
            _In_  IFunctionInstance *pIFunctionInstance);
        
        DECLSPEC_XFGVIRT(IFunctionDiscoveryNotification, OnError)
        HRESULT ( STDMETHODCALLTYPE *OnError )( 
            __RPC__in IFunctionDiscoveryNotification * This,
            /* [annotation][in] */ 
            _In_  HRESULT hr,
            /* [annotation][in] */ 
            _In_  FDQUERYCONTEXT fdqcQueryContext,
            /* [annotation][string][in] */ 
            _In_  const WCHAR *pszProvider);
        
        DECLSPEC_XFGVIRT(IFunctionDiscoveryNotification, OnEvent)
        HRESULT ( STDMETHODCALLTYPE *OnEvent )( 
            __RPC__in IFunctionDiscoveryNotification * This,
            /* [annotation][in] */ 
            _In_  DWORD dwEventID,
            /* [annotation][in] */ 
            _In_  FDQUERYCONTEXT fdqcQueryContext,
            /* [annotation][string][in] */ 
            _In_  const WCHAR *pszProvider);
        
        END_INTERFACE
    } IFunctionDiscoveryNotificationVtbl;

    interface IFunctionDiscoveryNotification
    {
        CONST_VTBL struct IFunctionDiscoveryNotificationVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFunctionDiscoveryNotification_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFunctionDiscoveryNotification_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFunctionDiscoveryNotification_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFunctionDiscoveryNotification_OnUpdate(This,enumQueryUpdateAction,fdqcQueryContext,pIFunctionInstance)	\
    ( (This)->lpVtbl -> OnUpdate(This,enumQueryUpdateAction,fdqcQueryContext,pIFunctionInstance) ) 

#define IFunctionDiscoveryNotification_OnError(This,hr,fdqcQueryContext,pszProvider)	\
    ( (This)->lpVtbl -> OnError(This,hr,fdqcQueryContext,pszProvider) ) 

#define IFunctionDiscoveryNotification_OnEvent(This,dwEventID,fdqcQueryContext,pszProvider)	\
    ( (This)->lpVtbl -> OnEvent(This,dwEventID,fdqcQueryContext,pszProvider) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFunctionDiscoveryNotification_INTERFACE_DEFINED__ */


#ifndef __IFunctionDiscovery_INTERFACE_DEFINED__
#define __IFunctionDiscovery_INTERFACE_DEFINED__

/* interface IFunctionDiscovery */
/* [restricted][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IFunctionDiscovery;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4df99b70-e148-4432-b004-4c9eeb535a5e")
    IFunctionDiscovery : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetInstanceCollection( 
            /* [annotation][string][in] */ 
            _In_  const WCHAR *pszCategory,
            /* [annotation][unique][string][in] */ 
            _In_  const WCHAR *pszSubCategory,
            /* [annotation][in] */ 
            _In_  BOOL fIncludeAllSubCategories,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFunctionInstanceCollection **ppIFunctionInstanceCollection) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetInstance( 
            /* [annotation][string][in] */ 
            _In_  const WCHAR *pszFunctionInstanceIdentity,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFunctionInstance **ppIFunctionInstance) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateInstanceCollectionQuery( 
            /* [annotation][string][in] */ 
            _In_  const WCHAR *pszCategory,
            /* [annotation][unique][string][in] */ 
            _In_  const WCHAR *pszSubCategory,
            /* [annotation][in] */ 
            _In_  BOOL fIncludeAllSubCategories,
            /* [annotation][in] */ 
            _In_  IFunctionDiscoveryNotification *pIFunctionDiscoveryNotification,
            /* [annotation][unique][out][in] */ 
            _Inout_  FDQUERYCONTEXT *pfdqcQueryContext,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFunctionInstanceCollectionQuery **ppIFunctionInstanceCollectionQuery) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateInstanceQuery( 
            /* [annotation][string][in] */ 
            _In_  const WCHAR *pszFunctionInstanceIdentity,
            /* [annotation][in] */ 
            _In_  IFunctionDiscoveryNotification *pIFunctionDiscoveryNotification,
            /* [annotation][unique][out][in] */ 
            _Inout_  FDQUERYCONTEXT *pfdqcQueryContext,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFunctionInstanceQuery **ppIFunctionInstanceQuery) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddInstance( 
            /* [annotation][in] */ 
            _In_  SystemVisibilityFlags enumSystemVisibility,
            /* [annotation][string][in] */ 
            _In_  const WCHAR *pszCategory,
            /* [annotation][unique][string][in] */ 
            _In_  const WCHAR *pszSubCategory,
            /* [annotation][string][in] */ 
            _In_  const WCHAR *pszCategoryIdentity,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFunctionInstance **ppIFunctionInstance) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveInstance( 
            /* [annotation][in] */ 
            _In_  SystemVisibilityFlags enumSystemVisibility,
            /* [annotation][string][in] */ 
            _In_  const WCHAR *pszCategory,
            /* [annotation][unique][string][in] */ 
            _In_  const WCHAR *pszSubCategory,
            /* [annotation][string][in] */ 
            _In_  const WCHAR *pszCategoryIdentity) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IFunctionDiscoveryVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IFunctionDiscovery * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IFunctionDiscovery * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IFunctionDiscovery * This);
        
        DECLSPEC_XFGVIRT(IFunctionDiscovery, GetInstanceCollection)
        HRESULT ( STDMETHODCALLTYPE *GetInstanceCollection )( 
            __RPC__in IFunctionDiscovery * This,
            /* [annotation][string][in] */ 
            _In_  const WCHAR *pszCategory,
            /* [annotation][unique][string][in] */ 
            _In_  const WCHAR *pszSubCategory,
            /* [annotation][in] */ 
            _In_  BOOL fIncludeAllSubCategories,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFunctionInstanceCollection **ppIFunctionInstanceCollection);
        
        DECLSPEC_XFGVIRT(IFunctionDiscovery, GetInstance)
        HRESULT ( STDMETHODCALLTYPE *GetInstance )( 
            __RPC__in IFunctionDiscovery * This,
            /* [annotation][string][in] */ 
            _In_  const WCHAR *pszFunctionInstanceIdentity,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFunctionInstance **ppIFunctionInstance);
        
        DECLSPEC_XFGVIRT(IFunctionDiscovery, CreateInstanceCollectionQuery)
        HRESULT ( STDMETHODCALLTYPE *CreateInstanceCollectionQuery )( 
            __RPC__in IFunctionDiscovery * This,
            /* [annotation][string][in] */ 
            _In_  const WCHAR *pszCategory,
            /* [annotation][unique][string][in] */ 
            _In_  const WCHAR *pszSubCategory,
            /* [annotation][in] */ 
            _In_  BOOL fIncludeAllSubCategories,
            /* [annotation][in] */ 
            _In_  IFunctionDiscoveryNotification *pIFunctionDiscoveryNotification,
            /* [annotation][unique][out][in] */ 
            _Inout_  FDQUERYCONTEXT *pfdqcQueryContext,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFunctionInstanceCollectionQuery **ppIFunctionInstanceCollectionQuery);
        
        DECLSPEC_XFGVIRT(IFunctionDiscovery, CreateInstanceQuery)
        HRESULT ( STDMETHODCALLTYPE *CreateInstanceQuery )( 
            __RPC__in IFunctionDiscovery * This,
            /* [annotation][string][in] */ 
            _In_  const WCHAR *pszFunctionInstanceIdentity,
            /* [annotation][in] */ 
            _In_  IFunctionDiscoveryNotification *pIFunctionDiscoveryNotification,
            /* [annotation][unique][out][in] */ 
            _Inout_  FDQUERYCONTEXT *pfdqcQueryContext,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFunctionInstanceQuery **ppIFunctionInstanceQuery);
        
        DECLSPEC_XFGVIRT(IFunctionDiscovery, AddInstance)
        HRESULT ( STDMETHODCALLTYPE *AddInstance )( 
            __RPC__in IFunctionDiscovery * This,
            /* [annotation][in] */ 
            _In_  SystemVisibilityFlags enumSystemVisibility,
            /* [annotation][string][in] */ 
            _In_  const WCHAR *pszCategory,
            /* [annotation][unique][string][in] */ 
            _In_  const WCHAR *pszSubCategory,
            /* [annotation][string][in] */ 
            _In_  const WCHAR *pszCategoryIdentity,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFunctionInstance **ppIFunctionInstance);
        
        DECLSPEC_XFGVIRT(IFunctionDiscovery, RemoveInstance)
        HRESULT ( STDMETHODCALLTYPE *RemoveInstance )( 
            __RPC__in IFunctionDiscovery * This,
            /* [annotation][in] */ 
            _In_  SystemVisibilityFlags enumSystemVisibility,
            /* [annotation][string][in] */ 
            _In_  const WCHAR *pszCategory,
            /* [annotation][unique][string][in] */ 
            _In_  const WCHAR *pszSubCategory,
            /* [annotation][string][in] */ 
            _In_  const WCHAR *pszCategoryIdentity);
        
        END_INTERFACE
    } IFunctionDiscoveryVtbl;

    interface IFunctionDiscovery
    {
        CONST_VTBL struct IFunctionDiscoveryVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFunctionDiscovery_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFunctionDiscovery_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFunctionDiscovery_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFunctionDiscovery_GetInstanceCollection(This,pszCategory,pszSubCategory,fIncludeAllSubCategories,ppIFunctionInstanceCollection)	\
    ( (This)->lpVtbl -> GetInstanceCollection(This,pszCategory,pszSubCategory,fIncludeAllSubCategories,ppIFunctionInstanceCollection) ) 

#define IFunctionDiscovery_GetInstance(This,pszFunctionInstanceIdentity,ppIFunctionInstance)	\
    ( (This)->lpVtbl -> GetInstance(This,pszFunctionInstanceIdentity,ppIFunctionInstance) ) 

#define IFunctionDiscovery_CreateInstanceCollectionQuery(This,pszCategory,pszSubCategory,fIncludeAllSubCategories,pIFunctionDiscoveryNotification,pfdqcQueryContext,ppIFunctionInstanceCollectionQuery)	\
    ( (This)->lpVtbl -> CreateInstanceCollectionQuery(This,pszCategory,pszSubCategory,fIncludeAllSubCategories,pIFunctionDiscoveryNotification,pfdqcQueryContext,ppIFunctionInstanceCollectionQuery) ) 

#define IFunctionDiscovery_CreateInstanceQuery(This,pszFunctionInstanceIdentity,pIFunctionDiscoveryNotification,pfdqcQueryContext,ppIFunctionInstanceQuery)	\
    ( (This)->lpVtbl -> CreateInstanceQuery(This,pszFunctionInstanceIdentity,pIFunctionDiscoveryNotification,pfdqcQueryContext,ppIFunctionInstanceQuery) ) 

#define IFunctionDiscovery_AddInstance(This,enumSystemVisibility,pszCategory,pszSubCategory,pszCategoryIdentity,ppIFunctionInstance)	\
    ( (This)->lpVtbl -> AddInstance(This,enumSystemVisibility,pszCategory,pszSubCategory,pszCategoryIdentity,ppIFunctionInstance) ) 

#define IFunctionDiscovery_RemoveInstance(This,enumSystemVisibility,pszCategory,pszSubCategory,pszCategoryIdentity)	\
    ( (This)->lpVtbl -> RemoveInstance(This,enumSystemVisibility,pszCategory,pszSubCategory,pszCategoryIdentity) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFunctionDiscovery_INTERFACE_DEFINED__ */


#ifndef __IFunctionInstance_INTERFACE_DEFINED__
#define __IFunctionInstance_INTERFACE_DEFINED__

/* interface IFunctionInstance */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IFunctionInstance;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("33591c10-0bed-4f02-b0ab-1530d5533ee9")
    IFunctionInstance : public IServiceProvider
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetID( 
            /* [annotation][retval][string][out] */ 
            _Out_retval_  WCHAR **ppszCoMemIdentity) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetProviderInstanceID( 
            /* [annotation][retval][string][out] */ 
            _Out_retval_  WCHAR **ppszCoMemProviderInstanceIdentity) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OpenPropertyStore( 
            /* [annotation][in] */ 
            _In_  DWORD dwStgAccess,
            /* [annotation][retval][out] */ 
            _Out_retval_  IPropertyStore **ppIPropertyStore) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCategory( 
            /* [annotation][string][out] */ 
            _Out_  WCHAR **ppszCoMemCategory,
            /* [annotation][string][out] */ 
            _Out_  WCHAR **ppszCoMemSubCategory) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IFunctionInstanceVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IFunctionInstance * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IFunctionInstance * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IFunctionInstance * This);
        
        DECLSPEC_XFGVIRT(IServiceProvider, QueryService)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *QueryService )( 
            IFunctionInstance * This,
            /* [annotation][in] */ 
            _In_  REFGUID guidService,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][out] */ 
            _Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IFunctionInstance, GetID)
        HRESULT ( STDMETHODCALLTYPE *GetID )( 
            __RPC__in IFunctionInstance * This,
            /* [annotation][retval][string][out] */ 
            _Out_retval_  WCHAR **ppszCoMemIdentity);
        
        DECLSPEC_XFGVIRT(IFunctionInstance, GetProviderInstanceID)
        HRESULT ( STDMETHODCALLTYPE *GetProviderInstanceID )( 
            __RPC__in IFunctionInstance * This,
            /* [annotation][retval][string][out] */ 
            _Out_retval_  WCHAR **ppszCoMemProviderInstanceIdentity);
        
        DECLSPEC_XFGVIRT(IFunctionInstance, OpenPropertyStore)
        HRESULT ( STDMETHODCALLTYPE *OpenPropertyStore )( 
            __RPC__in IFunctionInstance * This,
            /* [annotation][in] */ 
            _In_  DWORD dwStgAccess,
            /* [annotation][retval][out] */ 
            _Out_retval_  IPropertyStore **ppIPropertyStore);
        
        DECLSPEC_XFGVIRT(IFunctionInstance, GetCategory)
        HRESULT ( STDMETHODCALLTYPE *GetCategory )( 
            __RPC__in IFunctionInstance * This,
            /* [annotation][string][out] */ 
            _Out_  WCHAR **ppszCoMemCategory,
            /* [annotation][string][out] */ 
            _Out_  WCHAR **ppszCoMemSubCategory);
        
        END_INTERFACE
    } IFunctionInstanceVtbl;

    interface IFunctionInstance
    {
        CONST_VTBL struct IFunctionInstanceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFunctionInstance_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFunctionInstance_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFunctionInstance_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFunctionInstance_QueryService(This,guidService,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryService(This,guidService,riid,ppvObject) ) 


#define IFunctionInstance_GetID(This,ppszCoMemIdentity)	\
    ( (This)->lpVtbl -> GetID(This,ppszCoMemIdentity) ) 

#define IFunctionInstance_GetProviderInstanceID(This,ppszCoMemProviderInstanceIdentity)	\
    ( (This)->lpVtbl -> GetProviderInstanceID(This,ppszCoMemProviderInstanceIdentity) ) 

#define IFunctionInstance_OpenPropertyStore(This,dwStgAccess,ppIPropertyStore)	\
    ( (This)->lpVtbl -> OpenPropertyStore(This,dwStgAccess,ppIPropertyStore) ) 

#define IFunctionInstance_GetCategory(This,ppszCoMemCategory,ppszCoMemSubCategory)	\
    ( (This)->lpVtbl -> GetCategory(This,ppszCoMemCategory,ppszCoMemSubCategory) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFunctionInstance_INTERFACE_DEFINED__ */


#ifndef __IFunctionInstanceCollection_INTERFACE_DEFINED__
#define __IFunctionInstanceCollection_INTERFACE_DEFINED__

/* interface IFunctionInstanceCollection */
/* [restricted][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IFunctionInstanceCollection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("f0a3d895-855c-42a2-948d-2f97d450ecb1")
    IFunctionInstanceCollection : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetCount( 
            /* [annotation][retval][out] */ 
            _Out_retval_  DWORD *pdwCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Get( 
            /* [annotation][string][in] */ 
            _In_  const WCHAR *pszInstanceIdentity,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwIndex,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFunctionInstance **ppIFunctionInstance) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Item( 
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFunctionInstance **ppIFunctionInstance) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Add( 
            /* [annotation][in] */ 
            _In_  IFunctionInstance *pIFunctionInstance) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Remove( 
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFunctionInstance **ppIFunctionInstance) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Delete( 
            /* [annotation][in] */ 
            _In_  DWORD dwIndex) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DeleteAll( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IFunctionInstanceCollectionVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IFunctionInstanceCollection * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IFunctionInstanceCollection * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IFunctionInstanceCollection * This);
        
        DECLSPEC_XFGVIRT(IFunctionInstanceCollection, GetCount)
        HRESULT ( STDMETHODCALLTYPE *GetCount )( 
            __RPC__in IFunctionInstanceCollection * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  DWORD *pdwCount);
        
        DECLSPEC_XFGVIRT(IFunctionInstanceCollection, Get)
        HRESULT ( STDMETHODCALLTYPE *Get )( 
            __RPC__in IFunctionInstanceCollection * This,
            /* [annotation][string][in] */ 
            _In_  const WCHAR *pszInstanceIdentity,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwIndex,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFunctionInstance **ppIFunctionInstance);
        
        DECLSPEC_XFGVIRT(IFunctionInstanceCollection, Item)
        HRESULT ( STDMETHODCALLTYPE *Item )( 
            __RPC__in IFunctionInstanceCollection * This,
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFunctionInstance **ppIFunctionInstance);
        
        DECLSPEC_XFGVIRT(IFunctionInstanceCollection, Add)
        HRESULT ( STDMETHODCALLTYPE *Add )( 
            __RPC__in IFunctionInstanceCollection * This,
            /* [annotation][in] */ 
            _In_  IFunctionInstance *pIFunctionInstance);
        
        DECLSPEC_XFGVIRT(IFunctionInstanceCollection, Remove)
        HRESULT ( STDMETHODCALLTYPE *Remove )( 
            __RPC__in IFunctionInstanceCollection * This,
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFunctionInstance **ppIFunctionInstance);
        
        DECLSPEC_XFGVIRT(IFunctionInstanceCollection, Delete)
        HRESULT ( STDMETHODCALLTYPE *Delete )( 
            __RPC__in IFunctionInstanceCollection * This,
            /* [annotation][in] */ 
            _In_  DWORD dwIndex);
        
        DECLSPEC_XFGVIRT(IFunctionInstanceCollection, DeleteAll)
        HRESULT ( STDMETHODCALLTYPE *DeleteAll )( 
            __RPC__in IFunctionInstanceCollection * This);
        
        END_INTERFACE
    } IFunctionInstanceCollectionVtbl;

    interface IFunctionInstanceCollection
    {
        CONST_VTBL struct IFunctionInstanceCollectionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFunctionInstanceCollection_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFunctionInstanceCollection_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFunctionInstanceCollection_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFunctionInstanceCollection_GetCount(This,pdwCount)	\
    ( (This)->lpVtbl -> GetCount(This,pdwCount) ) 

#define IFunctionInstanceCollection_Get(This,pszInstanceIdentity,pdwIndex,ppIFunctionInstance)	\
    ( (This)->lpVtbl -> Get(This,pszInstanceIdentity,pdwIndex,ppIFunctionInstance) ) 

#define IFunctionInstanceCollection_Item(This,dwIndex,ppIFunctionInstance)	\
    ( (This)->lpVtbl -> Item(This,dwIndex,ppIFunctionInstance) ) 

#define IFunctionInstanceCollection_Add(This,pIFunctionInstance)	\
    ( (This)->lpVtbl -> Add(This,pIFunctionInstance) ) 

#define IFunctionInstanceCollection_Remove(This,dwIndex,ppIFunctionInstance)	\
    ( (This)->lpVtbl -> Remove(This,dwIndex,ppIFunctionInstance) ) 

#define IFunctionInstanceCollection_Delete(This,dwIndex)	\
    ( (This)->lpVtbl -> Delete(This,dwIndex) ) 

#define IFunctionInstanceCollection_DeleteAll(This)	\
    ( (This)->lpVtbl -> DeleteAll(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFunctionInstanceCollection_INTERFACE_DEFINED__ */


#ifndef __IPropertyStoreCollection_INTERFACE_DEFINED__
#define __IPropertyStoreCollection_INTERFACE_DEFINED__

/* interface IPropertyStoreCollection */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IPropertyStoreCollection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D14D9C30-12D2-42d8-BCE4-C60C2BB226FA")
    IPropertyStoreCollection : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetCount( 
            /* [annotation][retval][out] */ 
            _Out_retval_  LPDWORD pdwCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Get( 
            /* [annotation][string][in] */ 
            _In_  const WCHAR *pszInstanceIdentity,
            /* [annotation][out] */ 
            _Out_  LPDWORD pdwIndex,
            /* [annotation][retval][out] */ 
            _Out_retval_  IPropertyStore **ppIPropertyStore) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Item( 
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][retval][out] */ 
            _Out_retval_  IPropertyStore **ppIPropertyStore) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Add( 
            /* [annotation][in] */ 
            _In_  IPropertyStore *pIPropertyStore) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Remove( 
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][retval][out] */ 
            _Out_retval_  IPropertyStore **pIPropertyStore) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Delete( 
            /* [annotation][in] */ 
            _In_  DWORD dwIndex) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DeleteAll( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IPropertyStoreCollectionVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IPropertyStoreCollection * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IPropertyStoreCollection * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IPropertyStoreCollection * This);
        
        DECLSPEC_XFGVIRT(IPropertyStoreCollection, GetCount)
        HRESULT ( STDMETHODCALLTYPE *GetCount )( 
            __RPC__in IPropertyStoreCollection * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  LPDWORD pdwCount);
        
        DECLSPEC_XFGVIRT(IPropertyStoreCollection, Get)
        HRESULT ( STDMETHODCALLTYPE *Get )( 
            __RPC__in IPropertyStoreCollection * This,
            /* [annotation][string][in] */ 
            _In_  const WCHAR *pszInstanceIdentity,
            /* [annotation][out] */ 
            _Out_  LPDWORD pdwIndex,
            /* [annotation][retval][out] */ 
            _Out_retval_  IPropertyStore **ppIPropertyStore);
        
        DECLSPEC_XFGVIRT(IPropertyStoreCollection, Item)
        HRESULT ( STDMETHODCALLTYPE *Item )( 
            __RPC__in IPropertyStoreCollection * This,
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][retval][out] */ 
            _Out_retval_  IPropertyStore **ppIPropertyStore);
        
        DECLSPEC_XFGVIRT(IPropertyStoreCollection, Add)
        HRESULT ( STDMETHODCALLTYPE *Add )( 
            __RPC__in IPropertyStoreCollection * This,
            /* [annotation][in] */ 
            _In_  IPropertyStore *pIPropertyStore);
        
        DECLSPEC_XFGVIRT(IPropertyStoreCollection, Remove)
        HRESULT ( STDMETHODCALLTYPE *Remove )( 
            __RPC__in IPropertyStoreCollection * This,
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][retval][out] */ 
            _Out_retval_  IPropertyStore **pIPropertyStore);
        
        DECLSPEC_XFGVIRT(IPropertyStoreCollection, Delete)
        HRESULT ( STDMETHODCALLTYPE *Delete )( 
            __RPC__in IPropertyStoreCollection * This,
            /* [annotation][in] */ 
            _In_  DWORD dwIndex);
        
        DECLSPEC_XFGVIRT(IPropertyStoreCollection, DeleteAll)
        HRESULT ( STDMETHODCALLTYPE *DeleteAll )( 
            __RPC__in IPropertyStoreCollection * This);
        
        END_INTERFACE
    } IPropertyStoreCollectionVtbl;

    interface IPropertyStoreCollection
    {
        CONST_VTBL struct IPropertyStoreCollectionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPropertyStoreCollection_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPropertyStoreCollection_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPropertyStoreCollection_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPropertyStoreCollection_GetCount(This,pdwCount)	\
    ( (This)->lpVtbl -> GetCount(This,pdwCount) ) 

#define IPropertyStoreCollection_Get(This,pszInstanceIdentity,pdwIndex,ppIPropertyStore)	\
    ( (This)->lpVtbl -> Get(This,pszInstanceIdentity,pdwIndex,ppIPropertyStore) ) 

#define IPropertyStoreCollection_Item(This,dwIndex,ppIPropertyStore)	\
    ( (This)->lpVtbl -> Item(This,dwIndex,ppIPropertyStore) ) 

#define IPropertyStoreCollection_Add(This,pIPropertyStore)	\
    ( (This)->lpVtbl -> Add(This,pIPropertyStore) ) 

#define IPropertyStoreCollection_Remove(This,dwIndex,pIPropertyStore)	\
    ( (This)->lpVtbl -> Remove(This,dwIndex,pIPropertyStore) ) 

#define IPropertyStoreCollection_Delete(This,dwIndex)	\
    ( (This)->lpVtbl -> Delete(This,dwIndex) ) 

#define IPropertyStoreCollection_DeleteAll(This)	\
    ( (This)->lpVtbl -> DeleteAll(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPropertyStoreCollection_INTERFACE_DEFINED__ */


#ifndef __IFunctionInstanceQuery_INTERFACE_DEFINED__
#define __IFunctionInstanceQuery_INTERFACE_DEFINED__

/* interface IFunctionInstanceQuery */
/* [restricted][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IFunctionInstanceQuery;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6242bc6b-90ec-4b37-bb46-e229fd84ed95")
    IFunctionInstanceQuery : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Execute( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IFunctionInstance **ppIFunctionInstance) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IFunctionInstanceQueryVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IFunctionInstanceQuery * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IFunctionInstanceQuery * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IFunctionInstanceQuery * This);
        
        DECLSPEC_XFGVIRT(IFunctionInstanceQuery, Execute)
        HRESULT ( STDMETHODCALLTYPE *Execute )( 
            __RPC__in IFunctionInstanceQuery * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFunctionInstance **ppIFunctionInstance);
        
        END_INTERFACE
    } IFunctionInstanceQueryVtbl;

    interface IFunctionInstanceQuery
    {
        CONST_VTBL struct IFunctionInstanceQueryVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFunctionInstanceQuery_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFunctionInstanceQuery_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFunctionInstanceQuery_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFunctionInstanceQuery_Execute(This,ppIFunctionInstance)	\
    ( (This)->lpVtbl -> Execute(This,ppIFunctionInstance) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFunctionInstanceQuery_INTERFACE_DEFINED__ */


#ifndef __IFunctionInstanceCollectionQuery_INTERFACE_DEFINED__
#define __IFunctionInstanceCollectionQuery_INTERFACE_DEFINED__

/* interface IFunctionInstanceCollectionQuery */
/* [restricted][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IFunctionInstanceCollectionQuery;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("57cc6fd2-c09a-4289-bb72-25f04142058e")
    IFunctionInstanceCollectionQuery : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AddQueryConstraint( 
            /* [annotation][string][in] */ 
            _In_  const WCHAR *pszConstraintName,
            /* [annotation][string][in] */ 
            _In_  const WCHAR *pszConstraintValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddPropertyConstraint( 
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY Key,
            /* [annotation][in] */ 
            _In_  const PROPVARIANT *pv,
            /* [annotation][in] */ 
            _In_  PropertyConstraint enumPropertyConstraint) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Execute( 
            /* [annotation][out] */ 
            _Out_  IFunctionInstanceCollection **ppIFunctionInstanceCollection) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IFunctionInstanceCollectionQueryVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IFunctionInstanceCollectionQuery * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IFunctionInstanceCollectionQuery * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IFunctionInstanceCollectionQuery * This);
        
        DECLSPEC_XFGVIRT(IFunctionInstanceCollectionQuery, AddQueryConstraint)
        HRESULT ( STDMETHODCALLTYPE *AddQueryConstraint )( 
            __RPC__in IFunctionInstanceCollectionQuery * This,
            /* [annotation][string][in] */ 
            _In_  const WCHAR *pszConstraintName,
            /* [annotation][string][in] */ 
            _In_  const WCHAR *pszConstraintValue);
        
        DECLSPEC_XFGVIRT(IFunctionInstanceCollectionQuery, AddPropertyConstraint)
        HRESULT ( STDMETHODCALLTYPE *AddPropertyConstraint )( 
            __RPC__in IFunctionInstanceCollectionQuery * This,
            /* [annotation][in] */ 
            _In_  REFPROPERTYKEY Key,
            /* [annotation][in] */ 
            _In_  const PROPVARIANT *pv,
            /* [annotation][in] */ 
            _In_  PropertyConstraint enumPropertyConstraint);
        
        DECLSPEC_XFGVIRT(IFunctionInstanceCollectionQuery, Execute)
        HRESULT ( STDMETHODCALLTYPE *Execute )( 
            __RPC__in IFunctionInstanceCollectionQuery * This,
            /* [annotation][out] */ 
            _Out_  IFunctionInstanceCollection **ppIFunctionInstanceCollection);
        
        END_INTERFACE
    } IFunctionInstanceCollectionQueryVtbl;

    interface IFunctionInstanceCollectionQuery
    {
        CONST_VTBL struct IFunctionInstanceCollectionQueryVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFunctionInstanceCollectionQuery_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFunctionInstanceCollectionQuery_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFunctionInstanceCollectionQuery_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFunctionInstanceCollectionQuery_AddQueryConstraint(This,pszConstraintName,pszConstraintValue)	\
    ( (This)->lpVtbl -> AddQueryConstraint(This,pszConstraintName,pszConstraintValue) ) 

#define IFunctionInstanceCollectionQuery_AddPropertyConstraint(This,Key,pv,enumPropertyConstraint)	\
    ( (This)->lpVtbl -> AddPropertyConstraint(This,Key,pv,enumPropertyConstraint) ) 

#define IFunctionInstanceCollectionQuery_Execute(This,ppIFunctionInstanceCollection)	\
    ( (This)->lpVtbl -> Execute(This,ppIFunctionInstanceCollection) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFunctionInstanceCollectionQuery_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_functiondiscoveryapi_0000_0007 */
/* [local] */ 

#include "FunctionDiscoveryNotification.h"
#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_functiondiscoveryapi_0000_0007_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_functiondiscoveryapi_0000_0007_v0_0_s_ifspec;

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


