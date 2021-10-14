

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

#ifndef __comadmin_h__
#define __comadmin_h__

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

#ifndef __ICOMAdminCatalog_FWD_DEFINED__
#define __ICOMAdminCatalog_FWD_DEFINED__
typedef interface ICOMAdminCatalog ICOMAdminCatalog;

#endif 	/* __ICOMAdminCatalog_FWD_DEFINED__ */


#ifndef __ICOMAdminCatalog2_FWD_DEFINED__
#define __ICOMAdminCatalog2_FWD_DEFINED__
typedef interface ICOMAdminCatalog2 ICOMAdminCatalog2;

#endif 	/* __ICOMAdminCatalog2_FWD_DEFINED__ */


#ifndef __ICatalogObject_FWD_DEFINED__
#define __ICatalogObject_FWD_DEFINED__
typedef interface ICatalogObject ICatalogObject;

#endif 	/* __ICatalogObject_FWD_DEFINED__ */


#ifndef __ICatalogCollection_FWD_DEFINED__
#define __ICatalogCollection_FWD_DEFINED__
typedef interface ICatalogCollection ICatalogCollection;

#endif 	/* __ICatalogCollection_FWD_DEFINED__ */


#ifndef __COMAdminCatalog_FWD_DEFINED__
#define __COMAdminCatalog_FWD_DEFINED__

#ifdef __cplusplus
typedef class COMAdminCatalog COMAdminCatalog;
#else
typedef struct COMAdminCatalog COMAdminCatalog;
#endif /* __cplusplus */

#endif 	/* __COMAdminCatalog_FWD_DEFINED__ */


#ifndef __COMAdminCatalogObject_FWD_DEFINED__
#define __COMAdminCatalogObject_FWD_DEFINED__

#ifdef __cplusplus
typedef class COMAdminCatalogObject COMAdminCatalogObject;
#else
typedef struct COMAdminCatalogObject COMAdminCatalogObject;
#endif /* __cplusplus */

#endif 	/* __COMAdminCatalogObject_FWD_DEFINED__ */


#ifndef __COMAdminCatalogCollection_FWD_DEFINED__
#define __COMAdminCatalogCollection_FWD_DEFINED__

#ifdef __cplusplus
typedef class COMAdminCatalogCollection COMAdminCatalogCollection;
#else
typedef struct COMAdminCatalogCollection COMAdminCatalogCollection;
#endif /* __cplusplus */

#endif 	/* __COMAdminCatalogCollection_FWD_DEFINED__ */


/* header files for imported files */
#include "unknwn.h"
#include "oaidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_comadmin_0000_0000 */
/* [local] */ 

// -----------------------------------------------------------------------   
// comadmin.h  -- COM Administration Programming Interfaces                  
//                                                                           
// This file provides the prototypes for the APIs and COM interfaces         
// used by Microsoft COM applications.                                       
//                                                                           
// Copyright (c) 1995-2001 Microsoft Corporation.  All Rights Reserved.      
// -----------------------------------------------------------------------   
#include <winapifamily.h>
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
#include <objbase.h>
#ifndef DECLSPEC_UUID
#if (_MSC_VER >= 1100) && defined (__cplusplus)
#define DECLSPEC_UUID(x)    __declspec(uuid(x))
#else
#define DECLSPEC_UUID(x)
#endif
#endif
#pragma once
#pragma warning(push)
#pragma warning(disable:4668) 
#pragma once
#pragma region Input Buffer SAL 1 compatibility macros
#pragma endregion Input Buffer SAL 1 compatibility macros
#pragma once
#pragma once
#pragma warning(pop)


extern RPC_IF_HANDLE __MIDL_itf_comadmin_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_comadmin_0000_0000_v0_0_s_ifspec;

#ifndef __ICOMAdminCatalog_INTERFACE_DEFINED__
#define __ICOMAdminCatalog_INTERFACE_DEFINED__

/* interface ICOMAdminCatalog */
/* [unique][helpstring][dual][uuid][object] */ 




EXTERN_C const IID IID_ICOMAdminCatalog;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DD662187-DFC2-11d1-A2CF-00805FC79235")
    ICOMAdminCatalog : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCollection( 
            /* [annotation][in] */ 
            _In_  BSTR bstrCollName,
            /* [annotation][retval][out] */ 
            _Out_retval_  IDispatch **ppCatalogCollection) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Connect( 
            /* [annotation][in] */ 
            _In_  BSTR bstrCatalogServerName,
            /* [annotation][retval][out] */ 
            _Out_retval_  IDispatch **ppCatalogCollection) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MajorVersion( 
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plMajorVersion) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MinorVersion( 
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plMinorVersion) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCollectionByQuery( 
            /* [annotation][in] */ 
            _In_  BSTR bstrCollName,
            /* [annotation][in] */ 
            _In_  SAFEARRAY * *ppsaVarQuery,
            /* [annotation][retval][out] */ 
            _Out_retval_  IDispatch **ppCatalogCollection) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ImportComponent( 
            /* [annotation][in] */ 
            _In_  BSTR bstrApplIDOrName,
            /* [annotation][in] */ 
            _In_  BSTR bstrCLSIDOrProgID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE InstallComponent( 
            /* [annotation][in] */ 
            _In_  BSTR bstrApplIDOrName,
            /* [annotation][in] */ 
            _In_  BSTR bstrDLL,
            /* [annotation][in] */ 
            _In_  BSTR bstrTLB,
            /* [annotation][in] */ 
            _In_  BSTR bstrPSDLL) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ShutdownApplication( 
            /* [annotation][in] */ 
            _In_  BSTR bstrApplIDOrName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ExportApplication( 
            /* [annotation][in] */ 
            _In_  BSTR bstrApplIDOrName,
            /* [annotation][in] */ 
            _In_  BSTR bstrApplicationFile,
            /* [annotation][in] */ 
            _In_  long lOptions) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE InstallApplication( 
            /* [annotation][in] */ 
            _In_  BSTR bstrApplicationFile,
            /* [optional][in] */ __RPC__in BSTR bstrDestinationDirectory,
            /* [optional][in] */ long lOptions,
            /* [optional][in] */ __RPC__in BSTR bstrUserId,
            /* [optional][in] */ __RPC__in BSTR bstrPassword,
            /* [optional][in] */ __RPC__in BSTR bstrRSN) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE StopRouter( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RefreshRouter( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE StartRouter( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Reserved1( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Reserved2( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE InstallMultipleComponents( 
            /* [annotation][in] */ 
            _In_  BSTR bstrApplIDOrName,
            /* [annotation][in] */ 
            _In_  SAFEARRAY * *ppsaVarFileNames,
            /* [annotation][in] */ 
            _In_  SAFEARRAY * *ppsaVarCLSIDs) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetMultipleComponentsInfo( 
            /* [annotation][in] */ 
            _In_  BSTR bstrApplIdOrName,
            /* [annotation][in] */ 
            _In_  SAFEARRAY * *ppsaVarFileNames,
            /* [annotation][out] */ 
            _Out_  SAFEARRAY * *ppsaVarCLSIDs,
            /* [annotation][out] */ 
            _Out_  SAFEARRAY * *ppsaVarClassNames,
            /* [annotation][out] */ 
            _Out_  SAFEARRAY * *ppsaVarFileFlags,
            /* [annotation][out] */ 
            _Out_  SAFEARRAY * *ppsaVarComponentFlags) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RefreshComponents( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE BackupREGDB( 
            /* [annotation][in] */ 
            _In_  BSTR bstrBackupFilePath) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RestoreREGDB( 
            /* [annotation][in] */ 
            _In_  BSTR bstrBackupFilePath) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE QueryApplicationFile( 
            /* [annotation][in] */ 
            _In_  BSTR bstrApplicationFile,
            /* [annotation][out] */ 
            _Out_  BSTR *pbstrApplicationName,
            /* [annotation][out] */ 
            _Out_  BSTR *pbstrApplicationDescription,
            /* [annotation][out] */ 
            _Out_  VARIANT_BOOL *pbHasUsers,
            /* [annotation][out] */ 
            _Out_  VARIANT_BOOL *pbIsProxy,
            /* [annotation][out] */ 
            _Out_  SAFEARRAY * *ppsaVarFileNames) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE StartApplication( 
            /* [annotation][in] */ 
            _In_  BSTR bstrApplIdOrName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ServiceCheck( 
            /* [annotation][in] */ 
            _In_  long lService,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plStatus) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE InstallMultipleEventClasses( 
            /* [annotation][in] */ 
            _In_  BSTR bstrApplIdOrName,
            /* [annotation][in] */ 
            _In_  SAFEARRAY * *ppsaVarFileNames,
            /* [annotation][in] */ 
            _In_  SAFEARRAY * *ppsaVarCLSIDS) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE InstallEventClass( 
            /* [annotation][in] */ 
            _In_  BSTR bstrApplIdOrName,
            /* [annotation][in] */ 
            _In_  BSTR bstrDLL,
            /* [annotation][in] */ 
            _In_  BSTR bstrTLB,
            /* [annotation][in] */ 
            _In_  BSTR bstrPSDLL) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetEventClassesForIID( 
            /* [annotation][in] */ 
            _In_  BSTR bstrIID,
            /* [annotation][out] */ 
            _Out_  SAFEARRAY * *ppsaVarCLSIDs,
            /* [annotation][out] */ 
            _Out_  SAFEARRAY * *ppsaVarProgIDs,
            /* [annotation][out] */ 
            _Out_  SAFEARRAY * *ppsaVarDescriptions) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICOMAdminCatalogVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ICOMAdminCatalog * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ICOMAdminCatalog * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ICOMAdminCatalog * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in ICOMAdminCatalog * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in ICOMAdminCatalog * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in ICOMAdminCatalog * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][size_is][in] */ 
            _In_reads_(cNames)  LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cNames)  DISPID *rgDispId);
        
        DECLSPEC_XFGVIRT(IDispatch, Invoke)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICOMAdminCatalog * This,
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
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog, GetCollection)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetCollection )( 
            __RPC__in ICOMAdminCatalog * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrCollName,
            /* [annotation][retval][out] */ 
            _Out_retval_  IDispatch **ppCatalogCollection);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog, Connect)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Connect )( 
            __RPC__in ICOMAdminCatalog * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrCatalogServerName,
            /* [annotation][retval][out] */ 
            _Out_retval_  IDispatch **ppCatalogCollection);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog, get_MajorVersion)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MajorVersion )( 
            __RPC__in ICOMAdminCatalog * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plMajorVersion);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog, get_MinorVersion)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MinorVersion )( 
            __RPC__in ICOMAdminCatalog * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plMinorVersion);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog, GetCollectionByQuery)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetCollectionByQuery )( 
            __RPC__in ICOMAdminCatalog * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrCollName,
            /* [annotation][in] */ 
            _In_  SAFEARRAY * *ppsaVarQuery,
            /* [annotation][retval][out] */ 
            _Out_retval_  IDispatch **ppCatalogCollection);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog, ImportComponent)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ImportComponent )( 
            __RPC__in ICOMAdminCatalog * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrApplIDOrName,
            /* [annotation][in] */ 
            _In_  BSTR bstrCLSIDOrProgID);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog, InstallComponent)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *InstallComponent )( 
            __RPC__in ICOMAdminCatalog * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrApplIDOrName,
            /* [annotation][in] */ 
            _In_  BSTR bstrDLL,
            /* [annotation][in] */ 
            _In_  BSTR bstrTLB,
            /* [annotation][in] */ 
            _In_  BSTR bstrPSDLL);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog, ShutdownApplication)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ShutdownApplication )( 
            __RPC__in ICOMAdminCatalog * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrApplIDOrName);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog, ExportApplication)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ExportApplication )( 
            __RPC__in ICOMAdminCatalog * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrApplIDOrName,
            /* [annotation][in] */ 
            _In_  BSTR bstrApplicationFile,
            /* [annotation][in] */ 
            _In_  long lOptions);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog, InstallApplication)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *InstallApplication )( 
            __RPC__in ICOMAdminCatalog * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrApplicationFile,
            /* [optional][in] */ __RPC__in BSTR bstrDestinationDirectory,
            /* [optional][in] */ long lOptions,
            /* [optional][in] */ __RPC__in BSTR bstrUserId,
            /* [optional][in] */ __RPC__in BSTR bstrPassword,
            /* [optional][in] */ __RPC__in BSTR bstrRSN);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog, StopRouter)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StopRouter )( 
            __RPC__in ICOMAdminCatalog * This);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog, RefreshRouter)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RefreshRouter )( 
            __RPC__in ICOMAdminCatalog * This);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog, StartRouter)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StartRouter )( 
            __RPC__in ICOMAdminCatalog * This);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog, Reserved1)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Reserved1 )( 
            __RPC__in ICOMAdminCatalog * This);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog, Reserved2)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Reserved2 )( 
            __RPC__in ICOMAdminCatalog * This);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog, InstallMultipleComponents)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *InstallMultipleComponents )( 
            __RPC__in ICOMAdminCatalog * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrApplIDOrName,
            /* [annotation][in] */ 
            _In_  SAFEARRAY * *ppsaVarFileNames,
            /* [annotation][in] */ 
            _In_  SAFEARRAY * *ppsaVarCLSIDs);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog, GetMultipleComponentsInfo)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetMultipleComponentsInfo )( 
            __RPC__in ICOMAdminCatalog * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrApplIdOrName,
            /* [annotation][in] */ 
            _In_  SAFEARRAY * *ppsaVarFileNames,
            /* [annotation][out] */ 
            _Out_  SAFEARRAY * *ppsaVarCLSIDs,
            /* [annotation][out] */ 
            _Out_  SAFEARRAY * *ppsaVarClassNames,
            /* [annotation][out] */ 
            _Out_  SAFEARRAY * *ppsaVarFileFlags,
            /* [annotation][out] */ 
            _Out_  SAFEARRAY * *ppsaVarComponentFlags);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog, RefreshComponents)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RefreshComponents )( 
            __RPC__in ICOMAdminCatalog * This);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog, BackupREGDB)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *BackupREGDB )( 
            __RPC__in ICOMAdminCatalog * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrBackupFilePath);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog, RestoreREGDB)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RestoreREGDB )( 
            __RPC__in ICOMAdminCatalog * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrBackupFilePath);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog, QueryApplicationFile)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *QueryApplicationFile )( 
            __RPC__in ICOMAdminCatalog * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrApplicationFile,
            /* [annotation][out] */ 
            _Out_  BSTR *pbstrApplicationName,
            /* [annotation][out] */ 
            _Out_  BSTR *pbstrApplicationDescription,
            /* [annotation][out] */ 
            _Out_  VARIANT_BOOL *pbHasUsers,
            /* [annotation][out] */ 
            _Out_  VARIANT_BOOL *pbIsProxy,
            /* [annotation][out] */ 
            _Out_  SAFEARRAY * *ppsaVarFileNames);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog, StartApplication)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StartApplication )( 
            __RPC__in ICOMAdminCatalog * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrApplIdOrName);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog, ServiceCheck)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ServiceCheck )( 
            __RPC__in ICOMAdminCatalog * This,
            /* [annotation][in] */ 
            _In_  long lService,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plStatus);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog, InstallMultipleEventClasses)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *InstallMultipleEventClasses )( 
            __RPC__in ICOMAdminCatalog * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrApplIdOrName,
            /* [annotation][in] */ 
            _In_  SAFEARRAY * *ppsaVarFileNames,
            /* [annotation][in] */ 
            _In_  SAFEARRAY * *ppsaVarCLSIDS);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog, InstallEventClass)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *InstallEventClass )( 
            __RPC__in ICOMAdminCatalog * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrApplIdOrName,
            /* [annotation][in] */ 
            _In_  BSTR bstrDLL,
            /* [annotation][in] */ 
            _In_  BSTR bstrTLB,
            /* [annotation][in] */ 
            _In_  BSTR bstrPSDLL);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog, GetEventClassesForIID)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetEventClassesForIID )( 
            __RPC__in ICOMAdminCatalog * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrIID,
            /* [annotation][out] */ 
            _Out_  SAFEARRAY * *ppsaVarCLSIDs,
            /* [annotation][out] */ 
            _Out_  SAFEARRAY * *ppsaVarProgIDs,
            /* [annotation][out] */ 
            _Out_  SAFEARRAY * *ppsaVarDescriptions);
        
        END_INTERFACE
    } ICOMAdminCatalogVtbl;

    interface ICOMAdminCatalog
    {
        CONST_VTBL struct ICOMAdminCatalogVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICOMAdminCatalog_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICOMAdminCatalog_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICOMAdminCatalog_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICOMAdminCatalog_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ICOMAdminCatalog_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ICOMAdminCatalog_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ICOMAdminCatalog_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ICOMAdminCatalog_GetCollection(This,bstrCollName,ppCatalogCollection)	\
    ( (This)->lpVtbl -> GetCollection(This,bstrCollName,ppCatalogCollection) ) 

#define ICOMAdminCatalog_Connect(This,bstrCatalogServerName,ppCatalogCollection)	\
    ( (This)->lpVtbl -> Connect(This,bstrCatalogServerName,ppCatalogCollection) ) 

#define ICOMAdminCatalog_get_MajorVersion(This,plMajorVersion)	\
    ( (This)->lpVtbl -> get_MajorVersion(This,plMajorVersion) ) 

#define ICOMAdminCatalog_get_MinorVersion(This,plMinorVersion)	\
    ( (This)->lpVtbl -> get_MinorVersion(This,plMinorVersion) ) 

#define ICOMAdminCatalog_GetCollectionByQuery(This,bstrCollName,ppsaVarQuery,ppCatalogCollection)	\
    ( (This)->lpVtbl -> GetCollectionByQuery(This,bstrCollName,ppsaVarQuery,ppCatalogCollection) ) 

#define ICOMAdminCatalog_ImportComponent(This,bstrApplIDOrName,bstrCLSIDOrProgID)	\
    ( (This)->lpVtbl -> ImportComponent(This,bstrApplIDOrName,bstrCLSIDOrProgID) ) 

#define ICOMAdminCatalog_InstallComponent(This,bstrApplIDOrName,bstrDLL,bstrTLB,bstrPSDLL)	\
    ( (This)->lpVtbl -> InstallComponent(This,bstrApplIDOrName,bstrDLL,bstrTLB,bstrPSDLL) ) 

#define ICOMAdminCatalog_ShutdownApplication(This,bstrApplIDOrName)	\
    ( (This)->lpVtbl -> ShutdownApplication(This,bstrApplIDOrName) ) 

#define ICOMAdminCatalog_ExportApplication(This,bstrApplIDOrName,bstrApplicationFile,lOptions)	\
    ( (This)->lpVtbl -> ExportApplication(This,bstrApplIDOrName,bstrApplicationFile,lOptions) ) 

#define ICOMAdminCatalog_InstallApplication(This,bstrApplicationFile,bstrDestinationDirectory,lOptions,bstrUserId,bstrPassword,bstrRSN)	\
    ( (This)->lpVtbl -> InstallApplication(This,bstrApplicationFile,bstrDestinationDirectory,lOptions,bstrUserId,bstrPassword,bstrRSN) ) 

#define ICOMAdminCatalog_StopRouter(This)	\
    ( (This)->lpVtbl -> StopRouter(This) ) 

#define ICOMAdminCatalog_RefreshRouter(This)	\
    ( (This)->lpVtbl -> RefreshRouter(This) ) 

#define ICOMAdminCatalog_StartRouter(This)	\
    ( (This)->lpVtbl -> StartRouter(This) ) 

#define ICOMAdminCatalog_Reserved1(This)	\
    ( (This)->lpVtbl -> Reserved1(This) ) 

#define ICOMAdminCatalog_Reserved2(This)	\
    ( (This)->lpVtbl -> Reserved2(This) ) 

#define ICOMAdminCatalog_InstallMultipleComponents(This,bstrApplIDOrName,ppsaVarFileNames,ppsaVarCLSIDs)	\
    ( (This)->lpVtbl -> InstallMultipleComponents(This,bstrApplIDOrName,ppsaVarFileNames,ppsaVarCLSIDs) ) 

#define ICOMAdminCatalog_GetMultipleComponentsInfo(This,bstrApplIdOrName,ppsaVarFileNames,ppsaVarCLSIDs,ppsaVarClassNames,ppsaVarFileFlags,ppsaVarComponentFlags)	\
    ( (This)->lpVtbl -> GetMultipleComponentsInfo(This,bstrApplIdOrName,ppsaVarFileNames,ppsaVarCLSIDs,ppsaVarClassNames,ppsaVarFileFlags,ppsaVarComponentFlags) ) 

#define ICOMAdminCatalog_RefreshComponents(This)	\
    ( (This)->lpVtbl -> RefreshComponents(This) ) 

#define ICOMAdminCatalog_BackupREGDB(This,bstrBackupFilePath)	\
    ( (This)->lpVtbl -> BackupREGDB(This,bstrBackupFilePath) ) 

#define ICOMAdminCatalog_RestoreREGDB(This,bstrBackupFilePath)	\
    ( (This)->lpVtbl -> RestoreREGDB(This,bstrBackupFilePath) ) 

#define ICOMAdminCatalog_QueryApplicationFile(This,bstrApplicationFile,pbstrApplicationName,pbstrApplicationDescription,pbHasUsers,pbIsProxy,ppsaVarFileNames)	\
    ( (This)->lpVtbl -> QueryApplicationFile(This,bstrApplicationFile,pbstrApplicationName,pbstrApplicationDescription,pbHasUsers,pbIsProxy,ppsaVarFileNames) ) 

#define ICOMAdminCatalog_StartApplication(This,bstrApplIdOrName)	\
    ( (This)->lpVtbl -> StartApplication(This,bstrApplIdOrName) ) 

#define ICOMAdminCatalog_ServiceCheck(This,lService,plStatus)	\
    ( (This)->lpVtbl -> ServiceCheck(This,lService,plStatus) ) 

#define ICOMAdminCatalog_InstallMultipleEventClasses(This,bstrApplIdOrName,ppsaVarFileNames,ppsaVarCLSIDS)	\
    ( (This)->lpVtbl -> InstallMultipleEventClasses(This,bstrApplIdOrName,ppsaVarFileNames,ppsaVarCLSIDS) ) 

#define ICOMAdminCatalog_InstallEventClass(This,bstrApplIdOrName,bstrDLL,bstrTLB,bstrPSDLL)	\
    ( (This)->lpVtbl -> InstallEventClass(This,bstrApplIdOrName,bstrDLL,bstrTLB,bstrPSDLL) ) 

#define ICOMAdminCatalog_GetEventClassesForIID(This,bstrIID,ppsaVarCLSIDs,ppsaVarProgIDs,ppsaVarDescriptions)	\
    ( (This)->lpVtbl -> GetEventClassesForIID(This,bstrIID,ppsaVarCLSIDs,ppsaVarProgIDs,ppsaVarDescriptions) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICOMAdminCatalog_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_comadmin_0000_0001 */
/* [local] */ 

typedef /* [helpstring] */ 
enum COMAdminInUse
    {
        COMAdminNotInUse	= 0,
        COMAdminInUseByCatalog	= 0x1,
        COMAdminInUseByRegistryUnknown	= 0x2,
        COMAdminInUseByRegistryProxyStub	= 0x3,
        COMAdminInUseByRegistryTypeLib	= 0x4,
        COMAdminInUseByRegistryClsid	= 0x5
    } 	COMAdminInUse;



extern RPC_IF_HANDLE __MIDL_itf_comadmin_0000_0001_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_comadmin_0000_0001_v0_0_s_ifspec;

#ifndef __ICOMAdminCatalog2_INTERFACE_DEFINED__
#define __ICOMAdminCatalog2_INTERFACE_DEFINED__

/* interface ICOMAdminCatalog2 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ICOMAdminCatalog2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("790C6E0B-9194-4cc9-9426-A48A63185696")
    ICOMAdminCatalog2 : public ICOMAdminCatalog
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCollectionByQuery2( 
            /* [annotation][in] */ 
            _In_  BSTR bstrCollectionName,
            /* [annotation][in] */ 
            _In_  VARIANT *pVarQueryStrings,
            /* [annotation][retval][out] */ 
            _Out_retval_  IDispatch **ppCatalogCollection) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetApplicationInstanceIDFromProcessID( 
            /* [annotation][in] */ 
            _In_  long lProcessID,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrApplicationInstanceID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ShutdownApplicationInstances( 
            /* [annotation][in] */ 
            _In_  VARIANT *pVarApplicationInstanceID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PauseApplicationInstances( 
            /* [annotation][in] */ 
            _In_  VARIANT *pVarApplicationInstanceID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ResumeApplicationInstances( 
            /* [annotation][in] */ 
            _In_  VARIANT *pVarApplicationInstanceID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RecycleApplicationInstances( 
            /* [annotation][in] */ 
            _In_  VARIANT *pVarApplicationInstanceID,
            /* [annotation][in] */ 
            _In_  long lReasonCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AreApplicationInstancesPaused( 
            /* [annotation][in] */ 
            _In_  VARIANT *pVarApplicationInstanceID,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pVarBoolPaused) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DumpApplicationInstance( 
            /* [annotation][in] */ 
            _In_  BSTR bstrApplicationInstanceID,
            /* [annotation][in] */ 
            _In_  BSTR bstrDirectory,
            /* [annotation][in] */ 
            _In_  long lMaxImages,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrDumpFile) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IsApplicationInstanceDumpSupported( 
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pVarBoolDumpSupported) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateServiceForApplication( 
            /* [annotation][in] */ 
            _In_  BSTR bstrApplicationIDOrName,
            /* [annotation][in] */ 
            _In_  BSTR bstrServiceName,
            /* [annotation][in] */ 
            _In_  BSTR bstrStartType,
            /* [annotation][in] */ 
            _In_  BSTR bstrErrorControl,
            /* [annotation][in] */ 
            _In_  BSTR bstrDependencies,
            /* [annotation][in] */ 
            _In_  BSTR bstrRunAs,
            /* [annotation][in] */ 
            _In_  BSTR bstrPassword,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL bDesktopOk) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteServiceForApplication( 
            /* [annotation][in] */ 
            _In_  BSTR bstrApplicationIDOrName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetPartitionID( 
            /* [annotation][in] */ 
            _In_  BSTR bstrApplicationIDOrName,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrPartitionID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetPartitionName( 
            /* [annotation][in] */ 
            _In_  BSTR bstrApplicationIDOrName,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrPartitionName) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CurrentPartition( 
            /* [annotation][in] */ 
            _In_  BSTR bstrPartitionIDOrName) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CurrentPartitionID( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrPartitionID) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CurrentPartitionName( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrPartitionName) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_GlobalPartitionID( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrGlobalPartitionID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FlushPartitionCache( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CopyApplications( 
            /* [annotation][in] */ 
            _In_  BSTR bstrSourcePartitionIDOrName,
            /* [annotation][in] */ 
            _In_  VARIANT *pVarApplicationID,
            /* [annotation][in] */ 
            _In_  BSTR bstrDestinationPartitionIDOrName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CopyComponents( 
            /* [annotation][in] */ 
            _In_  BSTR bstrSourceApplicationIDOrName,
            /* [annotation][in] */ 
            _In_  VARIANT *pVarCLSIDOrProgID,
            /* [annotation][in] */ 
            _In_  BSTR bstrDestinationApplicationIDOrName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MoveComponents( 
            /* [annotation][in] */ 
            _In_  BSTR bstrSourceApplicationIDOrName,
            /* [annotation][in] */ 
            _In_  VARIANT *pVarCLSIDOrProgID,
            /* [annotation][in] */ 
            _In_  BSTR bstrDestinationApplicationIDOrName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AliasComponent( 
            /* [annotation][in] */ 
            _In_  BSTR bstrSrcApplicationIDOrName,
            /* [annotation][in] */ 
            _In_  BSTR bstrCLSIDOrProgID,
            /* [annotation][in] */ 
            _In_  BSTR bstrDestApplicationIDOrName,
            /* [annotation][in] */ 
            _In_  BSTR bstrNewProgId,
            /* [annotation][in] */ 
            _In_  BSTR bstrNewClsid) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsSafeToDelete( 
            /* [annotation][in] */ 
            _In_  BSTR bstrDllName,
            /* [annotation][retval][out] */ 
            _Out_retval_  COMAdminInUse *pCOMAdminInUse) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ImportUnconfiguredComponents( 
            /* [annotation][in] */ 
            _In_  BSTR bstrApplicationIDOrName,
            /* [annotation][in] */ 
            _In_  VARIANT *pVarCLSIDOrProgID,
            /* [optional][in] */ __RPC__in VARIANT *pVarComponentType) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PromoteUnconfiguredComponents( 
            /* [annotation][in] */ 
            _In_  BSTR bstrApplicationIDOrName,
            /* [annotation][in] */ 
            _In_  VARIANT *pVarCLSIDOrProgID,
            /* [optional][in] */ __RPC__in VARIANT *pVarComponentType) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ImportComponents( 
            /* [annotation][in] */ 
            _In_  BSTR bstrApplicationIDOrName,
            /* [annotation][in] */ 
            _In_  VARIANT *pVarCLSIDOrProgID,
            /* [optional][in] */ __RPC__in VARIANT *pVarComponentType) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Is64BitCatalogServer( 
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pbIs64Bit) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ExportPartition( 
            /* [annotation][in] */ 
            _In_  BSTR bstrPartitionIDOrName,
            /* [annotation][in] */ 
            _In_  BSTR bstrPartitionFileName,
            /* [annotation][in] */ 
            _In_  long lOptions) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE InstallPartition( 
            /* [annotation][in] */ 
            _In_  BSTR bstrFileName,
            /* [annotation][in] */ 
            _In_  BSTR bstrDestDirectory,
            /* [annotation][in] */ 
            _In_  long lOptions,
            /* [annotation][in] */ 
            _In_  BSTR bstrUserID,
            /* [annotation][in] */ 
            _In_  BSTR bstrPassword,
            /* [annotation][in] */ 
            _In_  BSTR bstrRSN) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE QueryApplicationFile2( 
            /* [annotation][in] */ 
            _In_  BSTR bstrApplicationFile,
            /* [annotation][retval][out] */ 
            _Out_retval_  IDispatch **ppFilesForImport) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetComponentVersionCount( 
            /* [annotation][in] */ 
            _In_  BSTR bstrCLSIDOrProgID,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plVersionCount) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICOMAdminCatalog2Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ICOMAdminCatalog2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ICOMAdminCatalog2 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ICOMAdminCatalog2 * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in ICOMAdminCatalog2 * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in ICOMAdminCatalog2 * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in ICOMAdminCatalog2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][size_is][in] */ 
            _In_reads_(cNames)  LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cNames)  DISPID *rgDispId);
        
        DECLSPEC_XFGVIRT(IDispatch, Invoke)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICOMAdminCatalog2 * This,
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
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog, GetCollection)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetCollection )( 
            __RPC__in ICOMAdminCatalog2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrCollName,
            /* [annotation][retval][out] */ 
            _Out_retval_  IDispatch **ppCatalogCollection);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog, Connect)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Connect )( 
            __RPC__in ICOMAdminCatalog2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrCatalogServerName,
            /* [annotation][retval][out] */ 
            _Out_retval_  IDispatch **ppCatalogCollection);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog, get_MajorVersion)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MajorVersion )( 
            __RPC__in ICOMAdminCatalog2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plMajorVersion);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog, get_MinorVersion)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MinorVersion )( 
            __RPC__in ICOMAdminCatalog2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plMinorVersion);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog, GetCollectionByQuery)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetCollectionByQuery )( 
            __RPC__in ICOMAdminCatalog2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrCollName,
            /* [annotation][in] */ 
            _In_  SAFEARRAY * *ppsaVarQuery,
            /* [annotation][retval][out] */ 
            _Out_retval_  IDispatch **ppCatalogCollection);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog, ImportComponent)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ImportComponent )( 
            __RPC__in ICOMAdminCatalog2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrApplIDOrName,
            /* [annotation][in] */ 
            _In_  BSTR bstrCLSIDOrProgID);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog, InstallComponent)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *InstallComponent )( 
            __RPC__in ICOMAdminCatalog2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrApplIDOrName,
            /* [annotation][in] */ 
            _In_  BSTR bstrDLL,
            /* [annotation][in] */ 
            _In_  BSTR bstrTLB,
            /* [annotation][in] */ 
            _In_  BSTR bstrPSDLL);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog, ShutdownApplication)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ShutdownApplication )( 
            __RPC__in ICOMAdminCatalog2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrApplIDOrName);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog, ExportApplication)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ExportApplication )( 
            __RPC__in ICOMAdminCatalog2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrApplIDOrName,
            /* [annotation][in] */ 
            _In_  BSTR bstrApplicationFile,
            /* [annotation][in] */ 
            _In_  long lOptions);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog, InstallApplication)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *InstallApplication )( 
            __RPC__in ICOMAdminCatalog2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrApplicationFile,
            /* [optional][in] */ __RPC__in BSTR bstrDestinationDirectory,
            /* [optional][in] */ long lOptions,
            /* [optional][in] */ __RPC__in BSTR bstrUserId,
            /* [optional][in] */ __RPC__in BSTR bstrPassword,
            /* [optional][in] */ __RPC__in BSTR bstrRSN);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog, StopRouter)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StopRouter )( 
            __RPC__in ICOMAdminCatalog2 * This);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog, RefreshRouter)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RefreshRouter )( 
            __RPC__in ICOMAdminCatalog2 * This);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog, StartRouter)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StartRouter )( 
            __RPC__in ICOMAdminCatalog2 * This);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog, Reserved1)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Reserved1 )( 
            __RPC__in ICOMAdminCatalog2 * This);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog, Reserved2)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Reserved2 )( 
            __RPC__in ICOMAdminCatalog2 * This);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog, InstallMultipleComponents)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *InstallMultipleComponents )( 
            __RPC__in ICOMAdminCatalog2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrApplIDOrName,
            /* [annotation][in] */ 
            _In_  SAFEARRAY * *ppsaVarFileNames,
            /* [annotation][in] */ 
            _In_  SAFEARRAY * *ppsaVarCLSIDs);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog, GetMultipleComponentsInfo)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetMultipleComponentsInfo )( 
            __RPC__in ICOMAdminCatalog2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrApplIdOrName,
            /* [annotation][in] */ 
            _In_  SAFEARRAY * *ppsaVarFileNames,
            /* [annotation][out] */ 
            _Out_  SAFEARRAY * *ppsaVarCLSIDs,
            /* [annotation][out] */ 
            _Out_  SAFEARRAY * *ppsaVarClassNames,
            /* [annotation][out] */ 
            _Out_  SAFEARRAY * *ppsaVarFileFlags,
            /* [annotation][out] */ 
            _Out_  SAFEARRAY * *ppsaVarComponentFlags);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog, RefreshComponents)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RefreshComponents )( 
            __RPC__in ICOMAdminCatalog2 * This);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog, BackupREGDB)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *BackupREGDB )( 
            __RPC__in ICOMAdminCatalog2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrBackupFilePath);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog, RestoreREGDB)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RestoreREGDB )( 
            __RPC__in ICOMAdminCatalog2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrBackupFilePath);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog, QueryApplicationFile)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *QueryApplicationFile )( 
            __RPC__in ICOMAdminCatalog2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrApplicationFile,
            /* [annotation][out] */ 
            _Out_  BSTR *pbstrApplicationName,
            /* [annotation][out] */ 
            _Out_  BSTR *pbstrApplicationDescription,
            /* [annotation][out] */ 
            _Out_  VARIANT_BOOL *pbHasUsers,
            /* [annotation][out] */ 
            _Out_  VARIANT_BOOL *pbIsProxy,
            /* [annotation][out] */ 
            _Out_  SAFEARRAY * *ppsaVarFileNames);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog, StartApplication)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StartApplication )( 
            __RPC__in ICOMAdminCatalog2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrApplIdOrName);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog, ServiceCheck)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ServiceCheck )( 
            __RPC__in ICOMAdminCatalog2 * This,
            /* [annotation][in] */ 
            _In_  long lService,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plStatus);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog, InstallMultipleEventClasses)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *InstallMultipleEventClasses )( 
            __RPC__in ICOMAdminCatalog2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrApplIdOrName,
            /* [annotation][in] */ 
            _In_  SAFEARRAY * *ppsaVarFileNames,
            /* [annotation][in] */ 
            _In_  SAFEARRAY * *ppsaVarCLSIDS);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog, InstallEventClass)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *InstallEventClass )( 
            __RPC__in ICOMAdminCatalog2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrApplIdOrName,
            /* [annotation][in] */ 
            _In_  BSTR bstrDLL,
            /* [annotation][in] */ 
            _In_  BSTR bstrTLB,
            /* [annotation][in] */ 
            _In_  BSTR bstrPSDLL);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog, GetEventClassesForIID)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetEventClassesForIID )( 
            __RPC__in ICOMAdminCatalog2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrIID,
            /* [annotation][out] */ 
            _Out_  SAFEARRAY * *ppsaVarCLSIDs,
            /* [annotation][out] */ 
            _Out_  SAFEARRAY * *ppsaVarProgIDs,
            /* [annotation][out] */ 
            _Out_  SAFEARRAY * *ppsaVarDescriptions);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog2, GetCollectionByQuery2)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetCollectionByQuery2 )( 
            __RPC__in ICOMAdminCatalog2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrCollectionName,
            /* [annotation][in] */ 
            _In_  VARIANT *pVarQueryStrings,
            /* [annotation][retval][out] */ 
            _Out_retval_  IDispatch **ppCatalogCollection);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog2, GetApplicationInstanceIDFromProcessID)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetApplicationInstanceIDFromProcessID )( 
            __RPC__in ICOMAdminCatalog2 * This,
            /* [annotation][in] */ 
            _In_  long lProcessID,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrApplicationInstanceID);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog2, ShutdownApplicationInstances)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ShutdownApplicationInstances )( 
            __RPC__in ICOMAdminCatalog2 * This,
            /* [annotation][in] */ 
            _In_  VARIANT *pVarApplicationInstanceID);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog2, PauseApplicationInstances)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PauseApplicationInstances )( 
            __RPC__in ICOMAdminCatalog2 * This,
            /* [annotation][in] */ 
            _In_  VARIANT *pVarApplicationInstanceID);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog2, ResumeApplicationInstances)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ResumeApplicationInstances )( 
            __RPC__in ICOMAdminCatalog2 * This,
            /* [annotation][in] */ 
            _In_  VARIANT *pVarApplicationInstanceID);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog2, RecycleApplicationInstances)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RecycleApplicationInstances )( 
            __RPC__in ICOMAdminCatalog2 * This,
            /* [annotation][in] */ 
            _In_  VARIANT *pVarApplicationInstanceID,
            /* [annotation][in] */ 
            _In_  long lReasonCode);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog2, AreApplicationInstancesPaused)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AreApplicationInstancesPaused )( 
            __RPC__in ICOMAdminCatalog2 * This,
            /* [annotation][in] */ 
            _In_  VARIANT *pVarApplicationInstanceID,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pVarBoolPaused);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog2, DumpApplicationInstance)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DumpApplicationInstance )( 
            __RPC__in ICOMAdminCatalog2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrApplicationInstanceID,
            /* [annotation][in] */ 
            _In_  BSTR bstrDirectory,
            /* [annotation][in] */ 
            _In_  long lMaxImages,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrDumpFile);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog2, get_IsApplicationInstanceDumpSupported)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsApplicationInstanceDumpSupported )( 
            __RPC__in ICOMAdminCatalog2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pVarBoolDumpSupported);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog2, CreateServiceForApplication)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateServiceForApplication )( 
            __RPC__in ICOMAdminCatalog2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrApplicationIDOrName,
            /* [annotation][in] */ 
            _In_  BSTR bstrServiceName,
            /* [annotation][in] */ 
            _In_  BSTR bstrStartType,
            /* [annotation][in] */ 
            _In_  BSTR bstrErrorControl,
            /* [annotation][in] */ 
            _In_  BSTR bstrDependencies,
            /* [annotation][in] */ 
            _In_  BSTR bstrRunAs,
            /* [annotation][in] */ 
            _In_  BSTR bstrPassword,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL bDesktopOk);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog2, DeleteServiceForApplication)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeleteServiceForApplication )( 
            __RPC__in ICOMAdminCatalog2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrApplicationIDOrName);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog2, GetPartitionID)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetPartitionID )( 
            __RPC__in ICOMAdminCatalog2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrApplicationIDOrName,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrPartitionID);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog2, GetPartitionName)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetPartitionName )( 
            __RPC__in ICOMAdminCatalog2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrApplicationIDOrName,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrPartitionName);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog2, put_CurrentPartition)
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CurrentPartition )( 
            __RPC__in ICOMAdminCatalog2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrPartitionIDOrName);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog2, get_CurrentPartitionID)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CurrentPartitionID )( 
            __RPC__in ICOMAdminCatalog2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrPartitionID);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog2, get_CurrentPartitionName)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CurrentPartitionName )( 
            __RPC__in ICOMAdminCatalog2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrPartitionName);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog2, get_GlobalPartitionID)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_GlobalPartitionID )( 
            __RPC__in ICOMAdminCatalog2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrGlobalPartitionID);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog2, FlushPartitionCache)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FlushPartitionCache )( 
            __RPC__in ICOMAdminCatalog2 * This);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog2, CopyApplications)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CopyApplications )( 
            __RPC__in ICOMAdminCatalog2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrSourcePartitionIDOrName,
            /* [annotation][in] */ 
            _In_  VARIANT *pVarApplicationID,
            /* [annotation][in] */ 
            _In_  BSTR bstrDestinationPartitionIDOrName);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog2, CopyComponents)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CopyComponents )( 
            __RPC__in ICOMAdminCatalog2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrSourceApplicationIDOrName,
            /* [annotation][in] */ 
            _In_  VARIANT *pVarCLSIDOrProgID,
            /* [annotation][in] */ 
            _In_  BSTR bstrDestinationApplicationIDOrName);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog2, MoveComponents)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MoveComponents )( 
            __RPC__in ICOMAdminCatalog2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrSourceApplicationIDOrName,
            /* [annotation][in] */ 
            _In_  VARIANT *pVarCLSIDOrProgID,
            /* [annotation][in] */ 
            _In_  BSTR bstrDestinationApplicationIDOrName);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog2, AliasComponent)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AliasComponent )( 
            __RPC__in ICOMAdminCatalog2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrSrcApplicationIDOrName,
            /* [annotation][in] */ 
            _In_  BSTR bstrCLSIDOrProgID,
            /* [annotation][in] */ 
            _In_  BSTR bstrDestApplicationIDOrName,
            /* [annotation][in] */ 
            _In_  BSTR bstrNewProgId,
            /* [annotation][in] */ 
            _In_  BSTR bstrNewClsid);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog2, IsSafeToDelete)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsSafeToDelete )( 
            __RPC__in ICOMAdminCatalog2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrDllName,
            /* [annotation][retval][out] */ 
            _Out_retval_  COMAdminInUse *pCOMAdminInUse);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog2, ImportUnconfiguredComponents)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ImportUnconfiguredComponents )( 
            __RPC__in ICOMAdminCatalog2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrApplicationIDOrName,
            /* [annotation][in] */ 
            _In_  VARIANT *pVarCLSIDOrProgID,
            /* [optional][in] */ __RPC__in VARIANT *pVarComponentType);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog2, PromoteUnconfiguredComponents)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PromoteUnconfiguredComponents )( 
            __RPC__in ICOMAdminCatalog2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrApplicationIDOrName,
            /* [annotation][in] */ 
            _In_  VARIANT *pVarCLSIDOrProgID,
            /* [optional][in] */ __RPC__in VARIANT *pVarComponentType);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog2, ImportComponents)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ImportComponents )( 
            __RPC__in ICOMAdminCatalog2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrApplicationIDOrName,
            /* [annotation][in] */ 
            _In_  VARIANT *pVarCLSIDOrProgID,
            /* [optional][in] */ __RPC__in VARIANT *pVarComponentType);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog2, get_Is64BitCatalogServer)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Is64BitCatalogServer )( 
            __RPC__in ICOMAdminCatalog2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pbIs64Bit);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog2, ExportPartition)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ExportPartition )( 
            __RPC__in ICOMAdminCatalog2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrPartitionIDOrName,
            /* [annotation][in] */ 
            _In_  BSTR bstrPartitionFileName,
            /* [annotation][in] */ 
            _In_  long lOptions);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog2, InstallPartition)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *InstallPartition )( 
            __RPC__in ICOMAdminCatalog2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrFileName,
            /* [annotation][in] */ 
            _In_  BSTR bstrDestDirectory,
            /* [annotation][in] */ 
            _In_  long lOptions,
            /* [annotation][in] */ 
            _In_  BSTR bstrUserID,
            /* [annotation][in] */ 
            _In_  BSTR bstrPassword,
            /* [annotation][in] */ 
            _In_  BSTR bstrRSN);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog2, QueryApplicationFile2)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *QueryApplicationFile2 )( 
            __RPC__in ICOMAdminCatalog2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrApplicationFile,
            /* [annotation][retval][out] */ 
            _Out_retval_  IDispatch **ppFilesForImport);
        
        DECLSPEC_XFGVIRT(ICOMAdminCatalog2, GetComponentVersionCount)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetComponentVersionCount )( 
            __RPC__in ICOMAdminCatalog2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrCLSIDOrProgID,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plVersionCount);
        
        END_INTERFACE
    } ICOMAdminCatalog2Vtbl;

    interface ICOMAdminCatalog2
    {
        CONST_VTBL struct ICOMAdminCatalog2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICOMAdminCatalog2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICOMAdminCatalog2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICOMAdminCatalog2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICOMAdminCatalog2_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ICOMAdminCatalog2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ICOMAdminCatalog2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ICOMAdminCatalog2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ICOMAdminCatalog2_GetCollection(This,bstrCollName,ppCatalogCollection)	\
    ( (This)->lpVtbl -> GetCollection(This,bstrCollName,ppCatalogCollection) ) 

#define ICOMAdminCatalog2_Connect(This,bstrCatalogServerName,ppCatalogCollection)	\
    ( (This)->lpVtbl -> Connect(This,bstrCatalogServerName,ppCatalogCollection) ) 

#define ICOMAdminCatalog2_get_MajorVersion(This,plMajorVersion)	\
    ( (This)->lpVtbl -> get_MajorVersion(This,plMajorVersion) ) 

#define ICOMAdminCatalog2_get_MinorVersion(This,plMinorVersion)	\
    ( (This)->lpVtbl -> get_MinorVersion(This,plMinorVersion) ) 

#define ICOMAdminCatalog2_GetCollectionByQuery(This,bstrCollName,ppsaVarQuery,ppCatalogCollection)	\
    ( (This)->lpVtbl -> GetCollectionByQuery(This,bstrCollName,ppsaVarQuery,ppCatalogCollection) ) 

#define ICOMAdminCatalog2_ImportComponent(This,bstrApplIDOrName,bstrCLSIDOrProgID)	\
    ( (This)->lpVtbl -> ImportComponent(This,bstrApplIDOrName,bstrCLSIDOrProgID) ) 

#define ICOMAdminCatalog2_InstallComponent(This,bstrApplIDOrName,bstrDLL,bstrTLB,bstrPSDLL)	\
    ( (This)->lpVtbl -> InstallComponent(This,bstrApplIDOrName,bstrDLL,bstrTLB,bstrPSDLL) ) 

#define ICOMAdminCatalog2_ShutdownApplication(This,bstrApplIDOrName)	\
    ( (This)->lpVtbl -> ShutdownApplication(This,bstrApplIDOrName) ) 

#define ICOMAdminCatalog2_ExportApplication(This,bstrApplIDOrName,bstrApplicationFile,lOptions)	\
    ( (This)->lpVtbl -> ExportApplication(This,bstrApplIDOrName,bstrApplicationFile,lOptions) ) 

#define ICOMAdminCatalog2_InstallApplication(This,bstrApplicationFile,bstrDestinationDirectory,lOptions,bstrUserId,bstrPassword,bstrRSN)	\
    ( (This)->lpVtbl -> InstallApplication(This,bstrApplicationFile,bstrDestinationDirectory,lOptions,bstrUserId,bstrPassword,bstrRSN) ) 

#define ICOMAdminCatalog2_StopRouter(This)	\
    ( (This)->lpVtbl -> StopRouter(This) ) 

#define ICOMAdminCatalog2_RefreshRouter(This)	\
    ( (This)->lpVtbl -> RefreshRouter(This) ) 

#define ICOMAdminCatalog2_StartRouter(This)	\
    ( (This)->lpVtbl -> StartRouter(This) ) 

#define ICOMAdminCatalog2_Reserved1(This)	\
    ( (This)->lpVtbl -> Reserved1(This) ) 

#define ICOMAdminCatalog2_Reserved2(This)	\
    ( (This)->lpVtbl -> Reserved2(This) ) 

#define ICOMAdminCatalog2_InstallMultipleComponents(This,bstrApplIDOrName,ppsaVarFileNames,ppsaVarCLSIDs)	\
    ( (This)->lpVtbl -> InstallMultipleComponents(This,bstrApplIDOrName,ppsaVarFileNames,ppsaVarCLSIDs) ) 

#define ICOMAdminCatalog2_GetMultipleComponentsInfo(This,bstrApplIdOrName,ppsaVarFileNames,ppsaVarCLSIDs,ppsaVarClassNames,ppsaVarFileFlags,ppsaVarComponentFlags)	\
    ( (This)->lpVtbl -> GetMultipleComponentsInfo(This,bstrApplIdOrName,ppsaVarFileNames,ppsaVarCLSIDs,ppsaVarClassNames,ppsaVarFileFlags,ppsaVarComponentFlags) ) 

#define ICOMAdminCatalog2_RefreshComponents(This)	\
    ( (This)->lpVtbl -> RefreshComponents(This) ) 

#define ICOMAdminCatalog2_BackupREGDB(This,bstrBackupFilePath)	\
    ( (This)->lpVtbl -> BackupREGDB(This,bstrBackupFilePath) ) 

#define ICOMAdminCatalog2_RestoreREGDB(This,bstrBackupFilePath)	\
    ( (This)->lpVtbl -> RestoreREGDB(This,bstrBackupFilePath) ) 

#define ICOMAdminCatalog2_QueryApplicationFile(This,bstrApplicationFile,pbstrApplicationName,pbstrApplicationDescription,pbHasUsers,pbIsProxy,ppsaVarFileNames)	\
    ( (This)->lpVtbl -> QueryApplicationFile(This,bstrApplicationFile,pbstrApplicationName,pbstrApplicationDescription,pbHasUsers,pbIsProxy,ppsaVarFileNames) ) 

#define ICOMAdminCatalog2_StartApplication(This,bstrApplIdOrName)	\
    ( (This)->lpVtbl -> StartApplication(This,bstrApplIdOrName) ) 

#define ICOMAdminCatalog2_ServiceCheck(This,lService,plStatus)	\
    ( (This)->lpVtbl -> ServiceCheck(This,lService,plStatus) ) 

#define ICOMAdminCatalog2_InstallMultipleEventClasses(This,bstrApplIdOrName,ppsaVarFileNames,ppsaVarCLSIDS)	\
    ( (This)->lpVtbl -> InstallMultipleEventClasses(This,bstrApplIdOrName,ppsaVarFileNames,ppsaVarCLSIDS) ) 

#define ICOMAdminCatalog2_InstallEventClass(This,bstrApplIdOrName,bstrDLL,bstrTLB,bstrPSDLL)	\
    ( (This)->lpVtbl -> InstallEventClass(This,bstrApplIdOrName,bstrDLL,bstrTLB,bstrPSDLL) ) 

#define ICOMAdminCatalog2_GetEventClassesForIID(This,bstrIID,ppsaVarCLSIDs,ppsaVarProgIDs,ppsaVarDescriptions)	\
    ( (This)->lpVtbl -> GetEventClassesForIID(This,bstrIID,ppsaVarCLSIDs,ppsaVarProgIDs,ppsaVarDescriptions) ) 


#define ICOMAdminCatalog2_GetCollectionByQuery2(This,bstrCollectionName,pVarQueryStrings,ppCatalogCollection)	\
    ( (This)->lpVtbl -> GetCollectionByQuery2(This,bstrCollectionName,pVarQueryStrings,ppCatalogCollection) ) 

#define ICOMAdminCatalog2_GetApplicationInstanceIDFromProcessID(This,lProcessID,pbstrApplicationInstanceID)	\
    ( (This)->lpVtbl -> GetApplicationInstanceIDFromProcessID(This,lProcessID,pbstrApplicationInstanceID) ) 

#define ICOMAdminCatalog2_ShutdownApplicationInstances(This,pVarApplicationInstanceID)	\
    ( (This)->lpVtbl -> ShutdownApplicationInstances(This,pVarApplicationInstanceID) ) 

#define ICOMAdminCatalog2_PauseApplicationInstances(This,pVarApplicationInstanceID)	\
    ( (This)->lpVtbl -> PauseApplicationInstances(This,pVarApplicationInstanceID) ) 

#define ICOMAdminCatalog2_ResumeApplicationInstances(This,pVarApplicationInstanceID)	\
    ( (This)->lpVtbl -> ResumeApplicationInstances(This,pVarApplicationInstanceID) ) 

#define ICOMAdminCatalog2_RecycleApplicationInstances(This,pVarApplicationInstanceID,lReasonCode)	\
    ( (This)->lpVtbl -> RecycleApplicationInstances(This,pVarApplicationInstanceID,lReasonCode) ) 

#define ICOMAdminCatalog2_AreApplicationInstancesPaused(This,pVarApplicationInstanceID,pVarBoolPaused)	\
    ( (This)->lpVtbl -> AreApplicationInstancesPaused(This,pVarApplicationInstanceID,pVarBoolPaused) ) 

#define ICOMAdminCatalog2_DumpApplicationInstance(This,bstrApplicationInstanceID,bstrDirectory,lMaxImages,pbstrDumpFile)	\
    ( (This)->lpVtbl -> DumpApplicationInstance(This,bstrApplicationInstanceID,bstrDirectory,lMaxImages,pbstrDumpFile) ) 

#define ICOMAdminCatalog2_get_IsApplicationInstanceDumpSupported(This,pVarBoolDumpSupported)	\
    ( (This)->lpVtbl -> get_IsApplicationInstanceDumpSupported(This,pVarBoolDumpSupported) ) 

#define ICOMAdminCatalog2_CreateServiceForApplication(This,bstrApplicationIDOrName,bstrServiceName,bstrStartType,bstrErrorControl,bstrDependencies,bstrRunAs,bstrPassword,bDesktopOk)	\
    ( (This)->lpVtbl -> CreateServiceForApplication(This,bstrApplicationIDOrName,bstrServiceName,bstrStartType,bstrErrorControl,bstrDependencies,bstrRunAs,bstrPassword,bDesktopOk) ) 

#define ICOMAdminCatalog2_DeleteServiceForApplication(This,bstrApplicationIDOrName)	\
    ( (This)->lpVtbl -> DeleteServiceForApplication(This,bstrApplicationIDOrName) ) 

#define ICOMAdminCatalog2_GetPartitionID(This,bstrApplicationIDOrName,pbstrPartitionID)	\
    ( (This)->lpVtbl -> GetPartitionID(This,bstrApplicationIDOrName,pbstrPartitionID) ) 

#define ICOMAdminCatalog2_GetPartitionName(This,bstrApplicationIDOrName,pbstrPartitionName)	\
    ( (This)->lpVtbl -> GetPartitionName(This,bstrApplicationIDOrName,pbstrPartitionName) ) 

#define ICOMAdminCatalog2_put_CurrentPartition(This,bstrPartitionIDOrName)	\
    ( (This)->lpVtbl -> put_CurrentPartition(This,bstrPartitionIDOrName) ) 

#define ICOMAdminCatalog2_get_CurrentPartitionID(This,pbstrPartitionID)	\
    ( (This)->lpVtbl -> get_CurrentPartitionID(This,pbstrPartitionID) ) 

#define ICOMAdminCatalog2_get_CurrentPartitionName(This,pbstrPartitionName)	\
    ( (This)->lpVtbl -> get_CurrentPartitionName(This,pbstrPartitionName) ) 

#define ICOMAdminCatalog2_get_GlobalPartitionID(This,pbstrGlobalPartitionID)	\
    ( (This)->lpVtbl -> get_GlobalPartitionID(This,pbstrGlobalPartitionID) ) 

#define ICOMAdminCatalog2_FlushPartitionCache(This)	\
    ( (This)->lpVtbl -> FlushPartitionCache(This) ) 

#define ICOMAdminCatalog2_CopyApplications(This,bstrSourcePartitionIDOrName,pVarApplicationID,bstrDestinationPartitionIDOrName)	\
    ( (This)->lpVtbl -> CopyApplications(This,bstrSourcePartitionIDOrName,pVarApplicationID,bstrDestinationPartitionIDOrName) ) 

#define ICOMAdminCatalog2_CopyComponents(This,bstrSourceApplicationIDOrName,pVarCLSIDOrProgID,bstrDestinationApplicationIDOrName)	\
    ( (This)->lpVtbl -> CopyComponents(This,bstrSourceApplicationIDOrName,pVarCLSIDOrProgID,bstrDestinationApplicationIDOrName) ) 

#define ICOMAdminCatalog2_MoveComponents(This,bstrSourceApplicationIDOrName,pVarCLSIDOrProgID,bstrDestinationApplicationIDOrName)	\
    ( (This)->lpVtbl -> MoveComponents(This,bstrSourceApplicationIDOrName,pVarCLSIDOrProgID,bstrDestinationApplicationIDOrName) ) 

#define ICOMAdminCatalog2_AliasComponent(This,bstrSrcApplicationIDOrName,bstrCLSIDOrProgID,bstrDestApplicationIDOrName,bstrNewProgId,bstrNewClsid)	\
    ( (This)->lpVtbl -> AliasComponent(This,bstrSrcApplicationIDOrName,bstrCLSIDOrProgID,bstrDestApplicationIDOrName,bstrNewProgId,bstrNewClsid) ) 

#define ICOMAdminCatalog2_IsSafeToDelete(This,bstrDllName,pCOMAdminInUse)	\
    ( (This)->lpVtbl -> IsSafeToDelete(This,bstrDllName,pCOMAdminInUse) ) 

#define ICOMAdminCatalog2_ImportUnconfiguredComponents(This,bstrApplicationIDOrName,pVarCLSIDOrProgID,pVarComponentType)	\
    ( (This)->lpVtbl -> ImportUnconfiguredComponents(This,bstrApplicationIDOrName,pVarCLSIDOrProgID,pVarComponentType) ) 

#define ICOMAdminCatalog2_PromoteUnconfiguredComponents(This,bstrApplicationIDOrName,pVarCLSIDOrProgID,pVarComponentType)	\
    ( (This)->lpVtbl -> PromoteUnconfiguredComponents(This,bstrApplicationIDOrName,pVarCLSIDOrProgID,pVarComponentType) ) 

#define ICOMAdminCatalog2_ImportComponents(This,bstrApplicationIDOrName,pVarCLSIDOrProgID,pVarComponentType)	\
    ( (This)->lpVtbl -> ImportComponents(This,bstrApplicationIDOrName,pVarCLSIDOrProgID,pVarComponentType) ) 

#define ICOMAdminCatalog2_get_Is64BitCatalogServer(This,pbIs64Bit)	\
    ( (This)->lpVtbl -> get_Is64BitCatalogServer(This,pbIs64Bit) ) 

#define ICOMAdminCatalog2_ExportPartition(This,bstrPartitionIDOrName,bstrPartitionFileName,lOptions)	\
    ( (This)->lpVtbl -> ExportPartition(This,bstrPartitionIDOrName,bstrPartitionFileName,lOptions) ) 

#define ICOMAdminCatalog2_InstallPartition(This,bstrFileName,bstrDestDirectory,lOptions,bstrUserID,bstrPassword,bstrRSN)	\
    ( (This)->lpVtbl -> InstallPartition(This,bstrFileName,bstrDestDirectory,lOptions,bstrUserID,bstrPassword,bstrRSN) ) 

#define ICOMAdminCatalog2_QueryApplicationFile2(This,bstrApplicationFile,ppFilesForImport)	\
    ( (This)->lpVtbl -> QueryApplicationFile2(This,bstrApplicationFile,ppFilesForImport) ) 

#define ICOMAdminCatalog2_GetComponentVersionCount(This,bstrCLSIDOrProgID,plVersionCount)	\
    ( (This)->lpVtbl -> GetComponentVersionCount(This,bstrCLSIDOrProgID,plVersionCount) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICOMAdminCatalog2_INTERFACE_DEFINED__ */


#ifndef __ICatalogObject_INTERFACE_DEFINED__
#define __ICatalogObject_INTERFACE_DEFINED__

/* interface ICatalogObject */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ICatalogObject;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6eb22871-8a19-11d0-81b6-00a0c9231c29")
    ICatalogObject : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Value( 
            /* [annotation][in] */ 
            _In_  BSTR bstrPropName,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT *pvarRetVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Value( 
            /* [annotation][in] */ 
            _In_  BSTR bstrPropName,
            /* [annotation][in] */ 
            _In_  VARIANT val) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Key( 
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT *pvarRetVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT *pvarRetVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsPropertyReadOnly( 
            /* [annotation][in] */ 
            _In_  BSTR bstrPropName,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pbRetVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Valid( 
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pbRetVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsPropertyWriteOnly( 
            /* [annotation][in] */ 
            _In_  BSTR bstrPropName,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pbRetVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICatalogObjectVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ICatalogObject * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ICatalogObject * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ICatalogObject * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in ICatalogObject * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in ICatalogObject * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in ICatalogObject * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][size_is][in] */ 
            _In_reads_(cNames)  LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cNames)  DISPID *rgDispId);
        
        DECLSPEC_XFGVIRT(IDispatch, Invoke)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICatalogObject * This,
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
        
        DECLSPEC_XFGVIRT(ICatalogObject, get_Value)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Value )( 
            __RPC__in ICatalogObject * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrPropName,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT *pvarRetVal);
        
        DECLSPEC_XFGVIRT(ICatalogObject, put_Value)
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Value )( 
            __RPC__in ICatalogObject * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrPropName,
            /* [annotation][in] */ 
            _In_  VARIANT val);
        
        DECLSPEC_XFGVIRT(ICatalogObject, get_Key)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Key )( 
            __RPC__in ICatalogObject * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT *pvarRetVal);
        
        DECLSPEC_XFGVIRT(ICatalogObject, get_Name)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            __RPC__in ICatalogObject * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT *pvarRetVal);
        
        DECLSPEC_XFGVIRT(ICatalogObject, IsPropertyReadOnly)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsPropertyReadOnly )( 
            __RPC__in ICatalogObject * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrPropName,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pbRetVal);
        
        DECLSPEC_XFGVIRT(ICatalogObject, get_Valid)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Valid )( 
            __RPC__in ICatalogObject * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pbRetVal);
        
        DECLSPEC_XFGVIRT(ICatalogObject, IsPropertyWriteOnly)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsPropertyWriteOnly )( 
            __RPC__in ICatalogObject * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrPropName,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pbRetVal);
        
        END_INTERFACE
    } ICatalogObjectVtbl;

    interface ICatalogObject
    {
        CONST_VTBL struct ICatalogObjectVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICatalogObject_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICatalogObject_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICatalogObject_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICatalogObject_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ICatalogObject_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ICatalogObject_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ICatalogObject_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ICatalogObject_get_Value(This,bstrPropName,pvarRetVal)	\
    ( (This)->lpVtbl -> get_Value(This,bstrPropName,pvarRetVal) ) 

#define ICatalogObject_put_Value(This,bstrPropName,val)	\
    ( (This)->lpVtbl -> put_Value(This,bstrPropName,val) ) 

#define ICatalogObject_get_Key(This,pvarRetVal)	\
    ( (This)->lpVtbl -> get_Key(This,pvarRetVal) ) 

#define ICatalogObject_get_Name(This,pvarRetVal)	\
    ( (This)->lpVtbl -> get_Name(This,pvarRetVal) ) 

#define ICatalogObject_IsPropertyReadOnly(This,bstrPropName,pbRetVal)	\
    ( (This)->lpVtbl -> IsPropertyReadOnly(This,bstrPropName,pbRetVal) ) 

#define ICatalogObject_get_Valid(This,pbRetVal)	\
    ( (This)->lpVtbl -> get_Valid(This,pbRetVal) ) 

#define ICatalogObject_IsPropertyWriteOnly(This,bstrPropName,pbRetVal)	\
    ( (This)->lpVtbl -> IsPropertyWriteOnly(This,bstrPropName,pbRetVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICatalogObject_INTERFACE_DEFINED__ */


#ifndef __ICatalogCollection_INTERFACE_DEFINED__
#define __ICatalogCollection_INTERFACE_DEFINED__

/* interface ICatalogCollection */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ICatalogCollection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6eb22872-8a19-11d0-81b6-00a0c9231c29")
    ICatalogCollection : public IDispatch
    {
    public:
        virtual /* [id][restricted][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IUnknown **ppEnumVariant) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [annotation][in] */ 
            _In_  long lIndex,
            /* [annotation][retval][out] */ 
            _Out_retval_  IDispatch **ppCatalogObject) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plObjectCount) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Remove( 
            /* [annotation][in] */ 
            _In_  long lIndex) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IDispatch **ppCatalogObject) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Populate( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SaveChanges( 
            /* [annotation][retval][out] */ 
            _Out_retval_  long *pcChanges) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCollection( 
            /* [annotation][in] */ 
            _In_  BSTR bstrCollName,
            /* [annotation][in] */ 
            _In_  VARIANT varObjectKey,
            /* [annotation][retval][out] */ 
            _Out_retval_  IDispatch **ppCatalogCollection) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT *pVarNamel) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AddEnabled( 
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pVarBool) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RemoveEnabled( 
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pVarBool) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetUtilInterface( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IDispatch **ppIDispatch) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DataStoreMajorVersion( 
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plMajorVersion) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DataStoreMinorVersion( 
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plMinorVersionl) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PopulateByKey( 
            /* [annotation][in] */ 
            _In_  SAFEARRAY * psaKeys) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PopulateByQuery( 
            /* [annotation][in] */ 
            _In_  BSTR bstrQueryString,
            /* [annotation][in] */ 
            _In_  long lQueryType) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICatalogCollectionVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ICatalogCollection * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ICatalogCollection * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ICatalogCollection * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in ICatalogCollection * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in ICatalogCollection * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in ICatalogCollection * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][size_is][in] */ 
            _In_reads_(cNames)  LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cNames)  DISPID *rgDispId);
        
        DECLSPEC_XFGVIRT(IDispatch, Invoke)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICatalogCollection * This,
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
        
        DECLSPEC_XFGVIRT(ICatalogCollection, get__NewEnum)
        /* [id][restricted][propget] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            __RPC__in ICatalogCollection * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IUnknown **ppEnumVariant);
        
        DECLSPEC_XFGVIRT(ICatalogCollection, get_Item)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            __RPC__in ICatalogCollection * This,
            /* [annotation][in] */ 
            _In_  long lIndex,
            /* [annotation][retval][out] */ 
            _Out_retval_  IDispatch **ppCatalogObject);
        
        DECLSPEC_XFGVIRT(ICatalogCollection, get_Count)
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            __RPC__in ICatalogCollection * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plObjectCount);
        
        DECLSPEC_XFGVIRT(ICatalogCollection, Remove)
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Remove )( 
            __RPC__in ICatalogCollection * This,
            /* [annotation][in] */ 
            _In_  long lIndex);
        
        DECLSPEC_XFGVIRT(ICatalogCollection, Add)
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            __RPC__in ICatalogCollection * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IDispatch **ppCatalogObject);
        
        DECLSPEC_XFGVIRT(ICatalogCollection, Populate)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Populate )( 
            __RPC__in ICatalogCollection * This);
        
        DECLSPEC_XFGVIRT(ICatalogCollection, SaveChanges)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SaveChanges )( 
            __RPC__in ICatalogCollection * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *pcChanges);
        
        DECLSPEC_XFGVIRT(ICatalogCollection, GetCollection)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetCollection )( 
            __RPC__in ICatalogCollection * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrCollName,
            /* [annotation][in] */ 
            _In_  VARIANT varObjectKey,
            /* [annotation][retval][out] */ 
            _Out_retval_  IDispatch **ppCatalogCollection);
        
        DECLSPEC_XFGVIRT(ICatalogCollection, get_Name)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            __RPC__in ICatalogCollection * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT *pVarNamel);
        
        DECLSPEC_XFGVIRT(ICatalogCollection, get_AddEnabled)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AddEnabled )( 
            __RPC__in ICatalogCollection * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pVarBool);
        
        DECLSPEC_XFGVIRT(ICatalogCollection, get_RemoveEnabled)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RemoveEnabled )( 
            __RPC__in ICatalogCollection * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pVarBool);
        
        DECLSPEC_XFGVIRT(ICatalogCollection, GetUtilInterface)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetUtilInterface )( 
            __RPC__in ICatalogCollection * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IDispatch **ppIDispatch);
        
        DECLSPEC_XFGVIRT(ICatalogCollection, get_DataStoreMajorVersion)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DataStoreMajorVersion )( 
            __RPC__in ICatalogCollection * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plMajorVersion);
        
        DECLSPEC_XFGVIRT(ICatalogCollection, get_DataStoreMinorVersion)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DataStoreMinorVersion )( 
            __RPC__in ICatalogCollection * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plMinorVersionl);
        
        DECLSPEC_XFGVIRT(ICatalogCollection, PopulateByKey)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PopulateByKey )( 
            __RPC__in ICatalogCollection * This,
            /* [annotation][in] */ 
            _In_  SAFEARRAY * psaKeys);
        
        DECLSPEC_XFGVIRT(ICatalogCollection, PopulateByQuery)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PopulateByQuery )( 
            __RPC__in ICatalogCollection * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrQueryString,
            /* [annotation][in] */ 
            _In_  long lQueryType);
        
        END_INTERFACE
    } ICatalogCollectionVtbl;

    interface ICatalogCollection
    {
        CONST_VTBL struct ICatalogCollectionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICatalogCollection_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICatalogCollection_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICatalogCollection_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICatalogCollection_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ICatalogCollection_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ICatalogCollection_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ICatalogCollection_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ICatalogCollection_get__NewEnum(This,ppEnumVariant)	\
    ( (This)->lpVtbl -> get__NewEnum(This,ppEnumVariant) ) 

#define ICatalogCollection_get_Item(This,lIndex,ppCatalogObject)	\
    ( (This)->lpVtbl -> get_Item(This,lIndex,ppCatalogObject) ) 

#define ICatalogCollection_get_Count(This,plObjectCount)	\
    ( (This)->lpVtbl -> get_Count(This,plObjectCount) ) 

#define ICatalogCollection_Remove(This,lIndex)	\
    ( (This)->lpVtbl -> Remove(This,lIndex) ) 

#define ICatalogCollection_Add(This,ppCatalogObject)	\
    ( (This)->lpVtbl -> Add(This,ppCatalogObject) ) 

#define ICatalogCollection_Populate(This)	\
    ( (This)->lpVtbl -> Populate(This) ) 

#define ICatalogCollection_SaveChanges(This,pcChanges)	\
    ( (This)->lpVtbl -> SaveChanges(This,pcChanges) ) 

#define ICatalogCollection_GetCollection(This,bstrCollName,varObjectKey,ppCatalogCollection)	\
    ( (This)->lpVtbl -> GetCollection(This,bstrCollName,varObjectKey,ppCatalogCollection) ) 

#define ICatalogCollection_get_Name(This,pVarNamel)	\
    ( (This)->lpVtbl -> get_Name(This,pVarNamel) ) 

#define ICatalogCollection_get_AddEnabled(This,pVarBool)	\
    ( (This)->lpVtbl -> get_AddEnabled(This,pVarBool) ) 

#define ICatalogCollection_get_RemoveEnabled(This,pVarBool)	\
    ( (This)->lpVtbl -> get_RemoveEnabled(This,pVarBool) ) 

#define ICatalogCollection_GetUtilInterface(This,ppIDispatch)	\
    ( (This)->lpVtbl -> GetUtilInterface(This,ppIDispatch) ) 

#define ICatalogCollection_get_DataStoreMajorVersion(This,plMajorVersion)	\
    ( (This)->lpVtbl -> get_DataStoreMajorVersion(This,plMajorVersion) ) 

#define ICatalogCollection_get_DataStoreMinorVersion(This,plMinorVersionl)	\
    ( (This)->lpVtbl -> get_DataStoreMinorVersion(This,plMinorVersionl) ) 

#define ICatalogCollection_PopulateByKey(This,psaKeys)	\
    ( (This)->lpVtbl -> PopulateByKey(This,psaKeys) ) 

#define ICatalogCollection_PopulateByQuery(This,bstrQueryString,lQueryType)	\
    ( (This)->lpVtbl -> PopulateByQuery(This,bstrQueryString,lQueryType) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICatalogCollection_INTERFACE_DEFINED__ */



#ifndef __COMAdmin_LIBRARY_DEFINED__
#define __COMAdmin_LIBRARY_DEFINED__

/* library COMAdmin */
/* [helpstring][version][uuid] */ 

typedef /* [helpstring] */ 
enum COMAdminComponentType
    {
        COMAdmin32BitComponent	= 0x1,
        COMAdmin64BitComponent	= 0x2
    } 	COMAdminComponentType;

typedef /* [helpstring] */ 
enum COMAdminApplicationInstallOptions
    {
        COMAdminInstallNoUsers	= 0,
        COMAdminInstallUsers	= 1,
        COMAdminInstallForceOverwriteOfFiles	= 2
    } 	COMAdminApplicationInstallOptions;

typedef /* [helpstring] */ 
enum COMAdminApplicationExportOptions
    {
        COMAdminExportNoUsers	= 0,
        COMAdminExportUsers	= 1,
        COMAdminExportApplicationProxy	= 2,
        COMAdminExportForceOverwriteOfFiles	= 4,
        COMAdminExportIn10Format	= 16
    } 	COMAdminApplicationExportOptions;

typedef /* [helpstring] */ 
enum COMAdminThreadingModels
    {
        COMAdminThreadingModelApartment	= 0,
        COMAdminThreadingModelFree	= 1,
        COMAdminThreadingModelMain	= 2,
        COMAdminThreadingModelBoth	= 3,
        COMAdminThreadingModelNeutral	= 4,
        COMAdminThreadingModelNotSpecified	= 5
    } 	COMAdminThreadingModels;

typedef /* [helpstring] */ 
enum COMAdminTransactionOptions
    {
        COMAdminTransactionIgnored	= 0,
        COMAdminTransactionNone	= 1,
        COMAdminTransactionSupported	= 2,
        COMAdminTransactionRequired	= 3,
        COMAdminTransactionRequiresNew	= 4
    } 	COMAdminTransactionOptions;

typedef /* [helpstring] */ 
enum COMAdminTxIsolationLevelOptions
    {
        COMAdminTxIsolationLevelAny	= 0,
        COMAdminTxIsolationLevelReadUnCommitted	= ( COMAdminTxIsolationLevelAny + 1 ) ,
        COMAdminTxIsolationLevelReadCommitted	= ( COMAdminTxIsolationLevelReadUnCommitted + 1 ) ,
        COMAdminTxIsolationLevelRepeatableRead	= ( COMAdminTxIsolationLevelReadCommitted + 1 ) ,
        COMAdminTxIsolationLevelSerializable	= ( COMAdminTxIsolationLevelRepeatableRead + 1 ) 
    } 	COMAdminTxIsolationLevelOptions;

typedef /* [helpstring] */ 
enum COMAdminSynchronizationOptions
    {
        COMAdminSynchronizationIgnored	= 0,
        COMAdminSynchronizationNone	= 1,
        COMAdminSynchronizationSupported	= 2,
        COMAdminSynchronizationRequired	= 3,
        COMAdminSynchronizationRequiresNew	= 4
    } 	COMAdminSynchronizationOptions;

typedef /* [helpstring] */ 
enum COMAdminActivationOptions
    {
        COMAdminActivationInproc	= 0,
        COMAdminActivationLocal	= 1
    } 	COMAdminActivationOptions;

typedef /* [helpstring] */ 
enum COMAdminAccessChecksLevelOptions
    {
        COMAdminAccessChecksApplicationLevel	= 0,
        COMAdminAccessChecksApplicationComponentLevel	= 1
    } 	COMAdminAccessChecksLevelOptions;

typedef /* [helpstring] */ 
enum COMAdminAuthenticationLevelOptions
    {
        COMAdminAuthenticationDefault	= 0,
        COMAdminAuthenticationNone	= 1,
        COMAdminAuthenticationConnect	= 2,
        COMAdminAuthenticationCall	= 3,
        COMAdminAuthenticationPacket	= 4,
        COMAdminAuthenticationIntegrity	= 5,
        COMAdminAuthenticationPrivacy	= 6
    } 	COMAdminAuthenticationLevelOptions;

typedef /* [helpstring] */ 
enum COMAdminImpersonationLevelOptions
    {
        COMAdminImpersonationAnonymous	= 1,
        COMAdminImpersonationIdentify	= 2,
        COMAdminImpersonationImpersonate	= 3,
        COMAdminImpersonationDelegate	= 4
    } 	COMAdminImpersonationLevelOptions;

typedef /* [helpstring] */ 
enum COMAdminAuthenticationCapabilitiesOptions
    {
        COMAdminAuthenticationCapabilitiesNone	= 0,
        COMAdminAuthenticationCapabilitiesSecureReference	= 0x2,
        COMAdminAuthenticationCapabilitiesStaticCloaking	= 0x20,
        COMAdminAuthenticationCapabilitiesDynamicCloaking	= 0x40
    } 	COMAdminAuthenticationCapabilitiesOptions;

typedef /* [helpstring] */ 
enum COMAdminOS
    {
        COMAdminOSNotInitialized	= 0,
        COMAdminOSWindows3_1	= 1,
        COMAdminOSWindows9x	= 2,
        COMAdminOSWindows2000	= 3,
        COMAdminOSWindows2000AdvancedServer	= 4,
        COMAdminOSWindows2000Unknown	= 5,
        COMAdminOSUnknown	= 6,
        COMAdminOSWindowsXPPersonal	= 11,
        COMAdminOSWindowsXPProfessional	= 12,
        COMAdminOSWindowsNETStandardServer	= 13,
        COMAdminOSWindowsNETEnterpriseServer	= 14,
        COMAdminOSWindowsNETDatacenterServer	= 15,
        COMAdminOSWindowsNETWebServer	= 16,
        COMAdminOSWindowsLonghornPersonal	= 17,
        COMAdminOSWindowsLonghornProfessional	= 18,
        COMAdminOSWindowsLonghornStandardServer	= 19,
        COMAdminOSWindowsLonghornEnterpriseServer	= 20,
        COMAdminOSWindowsLonghornDatacenterServer	= 21,
        COMAdminOSWindowsLonghornWebServer	= 22,
        COMAdminOSWindows7Personal	= 23,
        COMAdminOSWindows7Professional	= 24,
        COMAdminOSWindows7StandardServer	= 25,
        COMAdminOSWindows7EnterpriseServer	= 26,
        COMAdminOSWindows7DatacenterServer	= 27,
        COMAdminOSWindows7WebServer	= 28,
        COMAdminOSWindows8Personal	= 29,
        COMAdminOSWindows8Professional	= 30,
        COMAdminOSWindows8StandardServer	= 31,
        COMAdminOSWindows8EnterpriseServer	= 32,
        COMAdminOSWindows8DatacenterServer	= 33,
        COMAdminOSWindows8WebServer	= 34,
        COMAdminOSWindowsBluePersonal	= 35,
        COMAdminOSWindowsBlueProfessional	= 36,
        COMAdminOSWindowsBlueStandardServer	= 37,
        COMAdminOSWindowsBlueEnterpriseServer	= 38,
        COMAdminOSWindowsBlueDatacenterServer	= 39,
        COMAdminOSWindowsBlueWebServer	= 40
    } 	COMAdminOS;

typedef /* [helpstring] */ 
enum COMAdminServiceOptions
    {
        COMAdminServiceLoadBalanceRouter	= 1
    } 	COMAdminServiceOptions;

typedef /* [helpstring] */ 
enum COMAdminServiceStatusOptions
    {
        COMAdminServiceStopped	= 0,
        COMAdminServiceStartPending	= ( COMAdminServiceStopped + 1 ) ,
        COMAdminServiceStopPending	= ( COMAdminServiceStartPending + 1 ) ,
        COMAdminServiceRunning	= ( COMAdminServiceStopPending + 1 ) ,
        COMAdminServiceContinuePending	= ( COMAdminServiceRunning + 1 ) ,
        COMAdminServicePausePending	= ( COMAdminServiceContinuePending + 1 ) ,
        COMAdminServicePaused	= ( COMAdminServicePausePending + 1 ) ,
        COMAdminServiceUnknownState	= ( COMAdminServicePaused + 1 ) 
    } 	COMAdminServiceStatusOptions;

typedef /* [helpstring] */ 
enum COMAdminQCMessageAuthenticateOptions
    {
        COMAdminQCMessageAuthenticateSecureApps	= 0,
        COMAdminQCMessageAuthenticateOff	= 1,
        COMAdminQCMessageAuthenticateOn	= 2
    } 	COMAdminQCMessageAuthenticateOptions;

typedef /* [helpstring] */ 
enum COMAdminFileFlags
    {
        COMAdminFileFlagLoadable	= 0x1,
        COMAdminFileFlagCOM	= 0x2,
        COMAdminFileFlagContainsPS	= 0x4,
        COMAdminFileFlagContainsComp	= 0x8,
        COMAdminFileFlagContainsTLB	= 0x10,
        COMAdminFileFlagSelfReg	= 0x20,
        COMAdminFileFlagSelfUnReg	= 0x40,
        COMAdminFileFlagUnloadableDLL	= 0x80,
        COMAdminFileFlagDoesNotExist	= 0x100,
        COMAdminFileFlagAlreadyInstalled	= 0x200,
        COMAdminFileFlagBadTLB	= 0x400,
        COMAdminFileFlagGetClassObjFailed	= 0x800,
        COMAdminFileFlagClassNotAvailable	= 0x1000,
        COMAdminFileFlagRegistrar	= 0x2000,
        COMAdminFileFlagNoRegistrar	= 0x4000,
        COMAdminFileFlagDLLRegsvrFailed	= 0x8000,
        COMAdminFileFlagRegTLBFailed	= 0x10000,
        COMAdminFileFlagRegistrarFailed	= 0x20000,
        COMAdminFileFlagError	= 0x40000
    } 	COMAdminFileFlags;

typedef /* [helpstring] */ 
enum COMAdminComponentFlags
    {
        COMAdminCompFlagTypeInfoFound	= 0x1,
        COMAdminCompFlagCOMPlusPropertiesFound	= 0x2,
        COMAdminCompFlagProxyFound	= 0x4,
        COMAdminCompFlagInterfacesFound	= 0x8,
        COMAdminCompFlagAlreadyInstalled	= 0x10,
        COMAdminCompFlagNotInApplication	= 0x20
    } 	COMAdminComponentFlags;

#define	COMAdminCollectionRoot	( "Root" )

#define	COMAdminCollectionApplications	( "Applications" )

#define	COMAdminCollectionComponents	( "Components" )

#define	COMAdminCollectionComputerList	( "ComputerList" )

#define	COMAdminCollectionApplicationCluster	( "ApplicationCluster" )

#define	COMAdminCollectionLocalComputer	( "LocalComputer" )

#define	COMAdminCollectionInprocServers	( "InprocServers" )

#define	COMAdminCollectionRelatedCollectionInfo	( "RelatedCollectionInfo" )

#define	COMAdminCollectionPropertyInfo	( "PropertyInfo" )

#define	COMAdminCollectionRoles	( "Roles" )

#define	COMAdminCollectionErrorInfo	( "ErrorInfo" )

#define	COMAdminCollectionInterfacesForComponent	( "InterfacesForComponent" )

#define	COMAdminCollectionRolesForComponent	( "RolesForComponent" )

#define	COMAdminCollectionMethodsForInterface	( "MethodsForInterface" )

#define	COMAdminCollectionRolesForInterface	( "RolesForInterface" )

#define	COMAdminCollectionRolesForMethod	( "RolesForMethod" )

#define	COMAdminCollectionUsersInRole	( "UsersInRole" )

#define	COMAdminCollectionDCOMProtocols	( "DCOMProtocols" )

#define	COMAdminCollectionPartitions	( "Partitions" )

typedef /* [helpstring] */ 
enum COMAdminErrorCodes
    {
        COMAdminErrObjectErrors	= ( HRESULT  )0x80110401L,
        COMAdminErrObjectInvalid	= ( HRESULT  )0x80110402L,
        COMAdminErrKeyMissing	= ( HRESULT  )0x80110403L,
        COMAdminErrAlreadyInstalled	= ( HRESULT  )0x80110404L,
        COMAdminErrAppFileWriteFail	= ( HRESULT  )0x80110407L,
        COMAdminErrAppFileReadFail	= ( HRESULT  )0x80110408L,
        COMAdminErrAppFileVersion	= ( HRESULT  )0x80110409L,
        COMAdminErrBadPath	= ( HRESULT  )0x8011040aL,
        COMAdminErrApplicationExists	= ( HRESULT  )0x8011040bL,
        COMAdminErrRoleExists	= ( HRESULT  )0x8011040cL,
        COMAdminErrCantCopyFile	= ( HRESULT  )0x8011040dL,
        COMAdminErrNoUser	= ( HRESULT  )0x8011040fL,
        COMAdminErrInvalidUserids	= ( HRESULT  )0x80110410L,
        COMAdminErrNoRegistryCLSID	= ( HRESULT  )0x80110411L,
        COMAdminErrBadRegistryProgID	= ( HRESULT  )0x80110412L,
        COMAdminErrAuthenticationLevel	= ( HRESULT  )0x80110413L,
        COMAdminErrUserPasswdNotValid	= ( HRESULT  )0x80110414L,
        COMAdminErrCLSIDOrIIDMismatch	= ( HRESULT  )0x80110418L,
        COMAdminErrRemoteInterface	= ( HRESULT  )0x80110419L,
        COMAdminErrDllRegisterServer	= ( HRESULT  )0x8011041aL,
        COMAdminErrNoServerShare	= ( HRESULT  )0x8011041bL,
        COMAdminErrDllLoadFailed	= ( HRESULT  )0x8011041dL,
        COMAdminErrBadRegistryLibID	= ( HRESULT  )0x8011041eL,
        COMAdminErrAppDirNotFound	= ( HRESULT  )0x8011041fL,
        COMAdminErrRegistrarFailed	= ( HRESULT  )0x80110423L,
        COMAdminErrCompFileDoesNotExist	= ( HRESULT  )0x80110424L,
        COMAdminErrCompFileLoadDLLFail	= ( HRESULT  )0x80110425L,
        COMAdminErrCompFileGetClassObj	= ( HRESULT  )0x80110426L,
        COMAdminErrCompFileClassNotAvail	= ( HRESULT  )0x80110427L,
        COMAdminErrCompFileBadTLB	= ( HRESULT  )0x80110428L,
        COMAdminErrCompFileNotInstallable	= ( HRESULT  )0x80110429L,
        COMAdminErrNotChangeable	= ( HRESULT  )0x8011042aL,
        COMAdminErrNotDeletable	= ( HRESULT  )0x8011042bL,
        COMAdminErrSession	= ( HRESULT  )0x8011042cL,
        COMAdminErrCompMoveLocked	= ( HRESULT  )0x8011042dL,
        COMAdminErrCompMoveBadDest	= ( HRESULT  )0x8011042eL,
        COMAdminErrRegisterTLB	= ( HRESULT  )0x80110430L,
        COMAdminErrSystemApp	= ( HRESULT  )0x80110433L,
        COMAdminErrCompFileNoRegistrar	= ( HRESULT  )0x80110434L,
        COMAdminErrCoReqCompInstalled	= ( HRESULT  )0x80110435L,
        COMAdminErrServiceNotInstalled	= ( HRESULT  )0x80110436L,
        COMAdminErrPropertySaveFailed	= ( HRESULT  )0x80110437L,
        COMAdminErrObjectExists	= ( HRESULT  )0x80110438L,
        COMAdminErrComponentExists	= ( HRESULT  )0x80110439L,
        COMAdminErrRegFileCorrupt	= ( HRESULT  )0x8011043bL,
        COMAdminErrPropertyOverflow	= ( HRESULT  )0x8011043cL,
        COMAdminErrNotInRegistry	= ( HRESULT  )0x8011043eL,
        COMAdminErrObjectNotPoolable	= ( HRESULT  )0x8011043fL,
        COMAdminErrApplidMatchesClsid	= ( HRESULT  )0x80110446L,
        COMAdminErrRoleDoesNotExist	= ( HRESULT  )0x80110447L,
        COMAdminErrStartAppNeedsComponents	= ( HRESULT  )0x80110448L,
        COMAdminErrRequiresDifferentPlatform	= ( HRESULT  )0x80110449L,
        COMAdminErrQueuingServiceNotAvailable	= ( HRESULT  )0x80110602L,
        COMAdminErrObjectParentMissing	= ( HRESULT  )0x80110808L,
        COMAdminErrObjectDoesNotExist	= ( HRESULT  )0x80110809L,
        COMAdminErrCanNotExportAppProxy	= ( HRESULT  )0x8011044aL,
        COMAdminErrCanNotStartApp	= ( HRESULT  )0x8011044bL,
        COMAdminErrCanNotExportSystemApp	= ( HRESULT  )0x8011044cL,
        COMAdminErrCanNotSubscribeToComponent	= ( HRESULT  )0x8011044dL,
        COMAdminErrAppNotRunning	= ( HRESULT  )0x8011080aL,
        COMAdminErrEventClassCannotBeSubscriber	= ( HRESULT  )0x8011044eL,
        COMAdminErrLibAppProxyIncompatible	= ( HRESULT  )0x8011044fL,
        COMAdminErrBasePartitionOnly	= ( HRESULT  )0x80110450L,
        COMAdminErrDuplicatePartitionName	= ( HRESULT  )0x80110457L,
        COMAdminErrPartitionInUse	= ( HRESULT  )0x80110459L,
        COMAdminErrImportedComponentsNotAllowed	= ( HRESULT  )0x8011045bL,
        COMAdminErrRegdbNotInitialized	= ( HRESULT  )0x80110472L,
        COMAdminErrRegdbNotOpen	= ( HRESULT  )0x80110473L,
        COMAdminErrRegdbSystemErr	= ( HRESULT  )0x80110474L,
        COMAdminErrRegdbAlreadyRunning	= ( HRESULT  )0x80110475L,
        COMAdminErrMigVersionNotSupported	= ( HRESULT  )0x80110480L,
        COMAdminErrMigSchemaNotFound	= ( HRESULT  )0x80110481L,
        COMAdminErrCatBitnessMismatch	= ( HRESULT  )0x80110482L,
        COMAdminErrCatUnacceptableBitness	= ( HRESULT  )0x80110483L,
        COMAdminErrCatWrongAppBitnessBitness	= ( HRESULT  )0x80110484L,
        COMAdminErrCatPauseResumeNotSupported	= ( HRESULT  )0x80110485L,
        COMAdminErrCatServerFault	= ( HRESULT  )0x80110486L,
        COMAdminErrCantRecycleLibraryApps	= ( HRESULT  )0x8011080fL,
        COMAdminErrCantRecycleServiceApps	= ( HRESULT  )0x80110811L,
        COMAdminErrProcessAlreadyRecycled	= ( HRESULT  )0x80110812L,
        COMAdminErrPausedProcessMayNotBeRecycled	= ( HRESULT  )0x80110813L,
        COMAdminErrInvalidPartition	= ( HRESULT  )0x8011080bL,
        COMAdminErrPartitionMsiOnly	= ( HRESULT  )0x80110819L,
        COMAdminErrStartAppDisabled	= ( HRESULT  )0x80110451L,
        COMAdminErrCompMoveSource	= ( HRESULT  )0x8011081cL,
        COMAdminErrCompMoveDest	= ( HRESULT  )0x8011081dL,
        COMAdminErrCompMovePrivate	= ( HRESULT  )0x8011081eL,
        COMAdminErrCannotCopyEventClass	= ( HRESULT  )0x80110820L
    } 	COMAdminErrorCodes;


EXTERN_C const IID LIBID_COMAdmin;

EXTERN_C const CLSID CLSID_COMAdminCatalog;

#ifdef __cplusplus

class DECLSPEC_UUID("F618C514-DFB8-11d1-A2CF-00805FC79235")
COMAdminCatalog;
#endif

EXTERN_C const CLSID CLSID_COMAdminCatalogObject;

#ifdef __cplusplus

class DECLSPEC_UUID("F618C515-DFB8-11d1-A2CF-00805FC79235")
COMAdminCatalogObject;
#endif

EXTERN_C const CLSID CLSID_COMAdminCatalogCollection;

#ifdef __cplusplus

class DECLSPEC_UUID("F618C516-DFB8-11d1-A2CF-00805FC79235")
COMAdminCatalogCollection;
#endif
#endif /* __COMAdmin_LIBRARY_DEFINED__ */

/* interface __MIDL_itf_comadmin_0000_0005 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_comadmin_0000_0005_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_comadmin_0000_0005_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     __RPC__in unsigned long *, unsigned long            , __RPC__in BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     __RPC__in unsigned long *, __RPC__in BSTR * ); 

unsigned long             __RPC_USER  LPSAFEARRAY_UserSize(     __RPC__in unsigned long *, unsigned long            , __RPC__in LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserMarshal(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserUnmarshal(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out LPSAFEARRAY * ); 
void                      __RPC_USER  LPSAFEARRAY_UserFree(     __RPC__in unsigned long *, __RPC__in LPSAFEARRAY * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     __RPC__in unsigned long *, unsigned long            , __RPC__in VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree(     __RPC__in unsigned long *, __RPC__in VARIANT * ); 

unsigned long             __RPC_USER  BSTR_UserSize64(     __RPC__in unsigned long *, unsigned long            , __RPC__in BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal64(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal64(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out BSTR * ); 
void                      __RPC_USER  BSTR_UserFree64(     __RPC__in unsigned long *, __RPC__in BSTR * ); 

unsigned long             __RPC_USER  LPSAFEARRAY_UserSize64(     __RPC__in unsigned long *, unsigned long            , __RPC__in LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserMarshal64(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserUnmarshal64(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out LPSAFEARRAY * ); 
void                      __RPC_USER  LPSAFEARRAY_UserFree64(     __RPC__in unsigned long *, __RPC__in LPSAFEARRAY * ); 

unsigned long             __RPC_USER  VARIANT_UserSize64(     __RPC__in unsigned long *, unsigned long            , __RPC__in VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal64(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal64(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree64(     __RPC__in unsigned long *, __RPC__in VARIANT * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


