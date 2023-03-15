

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

#ifndef __fhcfg_h__
#define __fhcfg_h__

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

#ifndef __IFhTarget_FWD_DEFINED__
#define __IFhTarget_FWD_DEFINED__
typedef interface IFhTarget IFhTarget;

#endif 	/* __IFhTarget_FWD_DEFINED__ */


#ifndef __IFhScopeIterator_FWD_DEFINED__
#define __IFhScopeIterator_FWD_DEFINED__
typedef interface IFhScopeIterator IFhScopeIterator;

#endif 	/* __IFhScopeIterator_FWD_DEFINED__ */


#ifndef __IFhConfigMgr_FWD_DEFINED__
#define __IFhConfigMgr_FWD_DEFINED__
typedef interface IFhConfigMgr IFhConfigMgr;

#endif 	/* __IFhConfigMgr_FWD_DEFINED__ */


#ifndef __IFhReassociation_FWD_DEFINED__
#define __IFhReassociation_FWD_DEFINED__
typedef interface IFhReassociation IFhReassociation;

#endif 	/* __IFhReassociation_FWD_DEFINED__ */


#ifndef __FhConfigMgr_FWD_DEFINED__
#define __FhConfigMgr_FWD_DEFINED__

#ifdef __cplusplus
typedef class FhConfigMgr FhConfigMgr;
#else
typedef struct FhConfigMgr FhConfigMgr;
#endif /* __cplusplus */

#endif 	/* __FhConfigMgr_FWD_DEFINED__ */


#ifndef __FhReassociation_FWD_DEFINED__
#define __FhReassociation_FWD_DEFINED__

#ifdef __cplusplus
typedef class FhReassociation FhReassociation;
#else
typedef struct FhReassociation FhReassociation;
#endif /* __cplusplus */

#endif 	/* __FhReassociation_FWD_DEFINED__ */


/* header files for imported files */
#include "ocidl.h"
#include "shobjidl_core.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_fhcfg_0000_0000 */
/* [local] */ 

/*******************************************************************************/
/*                                                                             */
/*    Copyright (C) 2010 Microsoft Corporation.  All rights reserved.          */
/*                                                                             */
/*    IDL source for File History Configuration Manager COM API.               */
/*                                                                             */
/*******************************************************************************/
#include <winapifamily.h>
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
#if NTDDI_VERSION >= NTDDI_WIN8
typedef 
enum _FH_TARGET_PROPERTY_TYPE
    {
        FH_TARGET_NAME	= 0,
        FH_TARGET_URL	= ( FH_TARGET_NAME + 1 ) ,
        FH_TARGET_DRIVE_TYPE	= ( FH_TARGET_URL + 1 ) ,
        MAX_TARGET_PROPERTY	= ( FH_TARGET_DRIVE_TYPE + 1 ) 
    } 	FH_TARGET_PROPERTY_TYPE;

typedef enum _FH_TARGET_PROPERTY_TYPE *PFH_TARGET_PROPERTY_TYPE;

typedef 
enum _FH_TARGET_DRIVE_TYPES
    {
        FH_DRIVE_UNKNOWN	= 0,
        FH_DRIVE_REMOVABLE	= 2,
        FH_DRIVE_FIXED	= 3,
        FH_DRIVE_REMOTE	= 4
    } 	FH_TARGET_DRIVE_TYPES;

#pragma deprecated(IFhTarget)


extern RPC_IF_HANDLE __MIDL_itf_fhcfg_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_fhcfg_0000_0000_v0_0_s_ifspec;

#ifndef __IFhTarget_INTERFACE_DEFINED__
#define __IFhTarget_INTERFACE_DEFINED__

/* interface IFhTarget */
/* [uuid][object] */ 


EXTERN_C const IID IID_IFhTarget;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D87965FD-2BAD-4657-BD3B-9567EB300CED")
    IFhTarget : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetStringProperty( 
            /* [annotation][in] */ 
            _In_  FH_TARGET_PROPERTY_TYPE PropertyType,
            /* [annotation][out] */ 
            _Out_  BSTR *PropertyValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNumericalProperty( 
            /* [annotation][in] */ 
            _In_  FH_TARGET_PROPERTY_TYPE PropertyType,
            /* [annotation][out] */ 
            _Out_  ULONGLONG *PropertyValue) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IFhTargetVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IFhTarget * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IFhTarget * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IFhTarget * This);
        
        DECLSPEC_XFGVIRT(IFhTarget, GetStringProperty)
        HRESULT ( STDMETHODCALLTYPE *GetStringProperty )( 
            __RPC__in IFhTarget * This,
            /* [annotation][in] */ 
            _In_  FH_TARGET_PROPERTY_TYPE PropertyType,
            /* [annotation][out] */ 
            _Out_  BSTR *PropertyValue);
        
        DECLSPEC_XFGVIRT(IFhTarget, GetNumericalProperty)
        HRESULT ( STDMETHODCALLTYPE *GetNumericalProperty )( 
            __RPC__in IFhTarget * This,
            /* [annotation][in] */ 
            _In_  FH_TARGET_PROPERTY_TYPE PropertyType,
            /* [annotation][out] */ 
            _Out_  ULONGLONG *PropertyValue);
        
        END_INTERFACE
    } IFhTargetVtbl;

    interface IFhTarget
    {
        CONST_VTBL struct IFhTargetVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFhTarget_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFhTarget_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFhTarget_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFhTarget_GetStringProperty(This,PropertyType,PropertyValue)	\
    ( (This)->lpVtbl -> GetStringProperty(This,PropertyType,PropertyValue) ) 

#define IFhTarget_GetNumericalProperty(This,PropertyType,PropertyValue)	\
    ( (This)->lpVtbl -> GetNumericalProperty(This,PropertyType,PropertyValue) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFhTarget_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_fhcfg_0000_0001 */
/* [local] */ 

#pragma deprecated(IFhScopeIterator)


extern RPC_IF_HANDLE __MIDL_itf_fhcfg_0000_0001_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_fhcfg_0000_0001_v0_0_s_ifspec;

#ifndef __IFhScopeIterator_INTERFACE_DEFINED__
#define __IFhScopeIterator_INTERFACE_DEFINED__

/* interface IFhScopeIterator */
/* [uuid][object] */ 


EXTERN_C const IID IID_IFhScopeIterator;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3197ABCE-532A-44C6-8615-F3666566A720")
    IFhScopeIterator : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE MoveToNextItem( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetItem( 
            /* [annotation][out] */ 
            _Out_  BSTR *Item) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IFhScopeIteratorVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IFhScopeIterator * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IFhScopeIterator * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IFhScopeIterator * This);
        
        DECLSPEC_XFGVIRT(IFhScopeIterator, MoveToNextItem)
        HRESULT ( STDMETHODCALLTYPE *MoveToNextItem )( 
            __RPC__in IFhScopeIterator * This);
        
        DECLSPEC_XFGVIRT(IFhScopeIterator, GetItem)
        HRESULT ( STDMETHODCALLTYPE *GetItem )( 
            __RPC__in IFhScopeIterator * This,
            /* [annotation][out] */ 
            _Out_  BSTR *Item);
        
        END_INTERFACE
    } IFhScopeIteratorVtbl;

    interface IFhScopeIterator
    {
        CONST_VTBL struct IFhScopeIteratorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFhScopeIterator_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFhScopeIterator_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFhScopeIterator_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFhScopeIterator_MoveToNextItem(This)	\
    ( (This)->lpVtbl -> MoveToNextItem(This) ) 

#define IFhScopeIterator_GetItem(This,Item)	\
    ( (This)->lpVtbl -> GetItem(This,Item) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFhScopeIterator_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_fhcfg_0000_0002 */
/* [local] */ 

typedef 
enum _FH_PROTECTED_ITEM_CATEGORY
    {
        FH_FOLDER	= 0,
        FH_LIBRARY	= ( FH_FOLDER + 1 ) ,
        MAX_PROTECTED_ITEM_CATEGORY	= ( FH_LIBRARY + 1 ) 
    } 	FH_PROTECTED_ITEM_CATEGORY;

typedef enum _FH_PROTECTED_ITEM_CATEGORY *PFH_PROTECTED_ITEM_CATEGORY;

typedef 
enum _FH_LOCAL_POLICY_TYPE
    {
        FH_FREQUENCY	= 0,
        FH_RETENTION_TYPE	= ( FH_FREQUENCY + 1 ) ,
        FH_RETENTION_AGE	= ( FH_RETENTION_TYPE + 1 ) ,
        MAX_LOCAL_POLICY	= ( FH_RETENTION_AGE + 1 ) 
    } 	FH_LOCAL_POLICY_TYPE;

typedef enum _FH_LOCAL_POLICY_TYPE *PFH_LOCAL_POLICY_TYPE;

typedef 
enum _FH_RETENTION_TYPES
    {
        FH_RETENTION_DISABLED	= 0,
        FH_RETENTION_UNLIMITED	= ( FH_RETENTION_DISABLED + 1 ) ,
        FH_RETENTION_AGE_BASED	= ( FH_RETENTION_UNLIMITED + 1 ) ,
        MAX_RETENTION_TYPE	= ( FH_RETENTION_AGE_BASED + 1 ) 
    } 	FH_RETENTION_TYPES;

typedef 
enum _FH_BACKUP_STATUS
    {
        FH_STATUS_DISABLED	= 0,
        FH_STATUS_DISABLED_BY_GP	= ( FH_STATUS_DISABLED + 1 ) ,
        FH_STATUS_ENABLED	= ( FH_STATUS_DISABLED_BY_GP + 1 ) ,
        FH_STATUS_REHYDRATING	= ( FH_STATUS_ENABLED + 1 ) ,
        MAX_BACKUP_STATUS	= ( FH_STATUS_REHYDRATING + 1 ) 
    } 	FH_BACKUP_STATUS;

typedef 
enum _FH_DEVICE_VALIDATION_RESULT
    {
        FH_ACCESS_DENIED	= 0,
        FH_INVALID_DRIVE_TYPE	= ( FH_ACCESS_DENIED + 1 ) ,
        FH_READ_ONLY_PERMISSION	= ( FH_INVALID_DRIVE_TYPE + 1 ) ,
        FH_CURRENT_DEFAULT	= ( FH_READ_ONLY_PERMISSION + 1 ) ,
        FH_NAMESPACE_EXISTS	= ( FH_CURRENT_DEFAULT + 1 ) ,
        FH_TARGET_PART_OF_LIBRARY	= ( FH_NAMESPACE_EXISTS + 1 ) ,
        FH_VALID_TARGET	= ( FH_TARGET_PART_OF_LIBRARY + 1 ) ,
        MAX_VALIDATION_RESULT	= ( FH_VALID_TARGET + 1 ) 
    } 	FH_DEVICE_VALIDATION_RESULT;

typedef enum _FH_DEVICE_VALIDATION_RESULT *PFH_DEVICE_VALIDATION_RESULT;

#pragma deprecated(IFhConfigMgr)


extern RPC_IF_HANDLE __MIDL_itf_fhcfg_0000_0002_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_fhcfg_0000_0002_v0_0_s_ifspec;

#ifndef __IFhConfigMgr_INTERFACE_DEFINED__
#define __IFhConfigMgr_INTERFACE_DEFINED__

/* interface IFhConfigMgr */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IFhConfigMgr;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6A5FEA5B-BF8F-4EE5-B8C3-44D8A0D7331C")
    IFhConfigMgr : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE LoadConfiguration( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateDefaultConfiguration( 
            /* [annotation][in] */ 
            _In_  BOOL OverwriteIfExists) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SaveConfiguration( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddRemoveExcludeRule( 
            /* [annotation][in] */ 
            _In_  BOOL Add,
            /* [annotation][in] */ 
            _In_  FH_PROTECTED_ITEM_CATEGORY Category,
            /* [annotation][in] */ 
            _In_  BSTR Item) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetIncludeExcludeRules( 
            /* [annotation][in] */ 
            _In_  BOOL Include,
            /* [annotation][in] */ 
            _In_  FH_PROTECTED_ITEM_CATEGORY Category,
            /* [annotation][out] */ 
            _Out_  IFhScopeIterator **Iterator) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLocalPolicy( 
            /* [annotation][in] */ 
            _In_  FH_LOCAL_POLICY_TYPE LocalPolicyType,
            /* [annotation][out] */ 
            _Out_  ULONGLONG *PolicyValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetLocalPolicy( 
            /* [annotation][in] */ 
            _In_  FH_LOCAL_POLICY_TYPE LocalPolicyType,
            /* [annotation][in] */ 
            _In_  ULONGLONG PolicyValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBackupStatus( 
            /* [annotation][out] */ 
            _Out_  FH_BACKUP_STATUS *BackupStatus) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetBackupStatus( 
            /* [annotation][in] */ 
            _In_  FH_BACKUP_STATUS BackupStatus) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDefaultTarget( 
            /* [annotation][out] */ 
            _Out_  IFhTarget **DefaultTarget) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ValidateTarget( 
            /* [annotation][in] */ 
            _In_  BSTR TargetUrl,
            /* [annotation][out] */ 
            _Out_  PFH_DEVICE_VALIDATION_RESULT ValidationResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ProvisionAndSetNewTarget( 
            /* [annotation][in] */ 
            _In_  BSTR TargetUrl,
            /* [annotation][in] */ 
            _In_  BSTR TargetName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ChangeDefaultTargetRecommendation( 
            /* [annotation][in] */ 
            _In_  BOOL Recommend) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryProtectionStatus( 
            /* [annotation][out] */ 
            _Out_  DWORD *ProtectionState,
            /* [annotation][out] */ 
            _Out_  BSTR *ProtectedUntilTime) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IFhConfigMgrVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IFhConfigMgr * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IFhConfigMgr * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IFhConfigMgr * This);
        
        DECLSPEC_XFGVIRT(IFhConfigMgr, LoadConfiguration)
        HRESULT ( STDMETHODCALLTYPE *LoadConfiguration )( 
            __RPC__in IFhConfigMgr * This);
        
        DECLSPEC_XFGVIRT(IFhConfigMgr, CreateDefaultConfiguration)
        HRESULT ( STDMETHODCALLTYPE *CreateDefaultConfiguration )( 
            __RPC__in IFhConfigMgr * This,
            /* [annotation][in] */ 
            _In_  BOOL OverwriteIfExists);
        
        DECLSPEC_XFGVIRT(IFhConfigMgr, SaveConfiguration)
        HRESULT ( STDMETHODCALLTYPE *SaveConfiguration )( 
            __RPC__in IFhConfigMgr * This);
        
        DECLSPEC_XFGVIRT(IFhConfigMgr, AddRemoveExcludeRule)
        HRESULT ( STDMETHODCALLTYPE *AddRemoveExcludeRule )( 
            __RPC__in IFhConfigMgr * This,
            /* [annotation][in] */ 
            _In_  BOOL Add,
            /* [annotation][in] */ 
            _In_  FH_PROTECTED_ITEM_CATEGORY Category,
            /* [annotation][in] */ 
            _In_  BSTR Item);
        
        DECLSPEC_XFGVIRT(IFhConfigMgr, GetIncludeExcludeRules)
        HRESULT ( STDMETHODCALLTYPE *GetIncludeExcludeRules )( 
            __RPC__in IFhConfigMgr * This,
            /* [annotation][in] */ 
            _In_  BOOL Include,
            /* [annotation][in] */ 
            _In_  FH_PROTECTED_ITEM_CATEGORY Category,
            /* [annotation][out] */ 
            _Out_  IFhScopeIterator **Iterator);
        
        DECLSPEC_XFGVIRT(IFhConfigMgr, GetLocalPolicy)
        HRESULT ( STDMETHODCALLTYPE *GetLocalPolicy )( 
            __RPC__in IFhConfigMgr * This,
            /* [annotation][in] */ 
            _In_  FH_LOCAL_POLICY_TYPE LocalPolicyType,
            /* [annotation][out] */ 
            _Out_  ULONGLONG *PolicyValue);
        
        DECLSPEC_XFGVIRT(IFhConfigMgr, SetLocalPolicy)
        HRESULT ( STDMETHODCALLTYPE *SetLocalPolicy )( 
            __RPC__in IFhConfigMgr * This,
            /* [annotation][in] */ 
            _In_  FH_LOCAL_POLICY_TYPE LocalPolicyType,
            /* [annotation][in] */ 
            _In_  ULONGLONG PolicyValue);
        
        DECLSPEC_XFGVIRT(IFhConfigMgr, GetBackupStatus)
        HRESULT ( STDMETHODCALLTYPE *GetBackupStatus )( 
            __RPC__in IFhConfigMgr * This,
            /* [annotation][out] */ 
            _Out_  FH_BACKUP_STATUS *BackupStatus);
        
        DECLSPEC_XFGVIRT(IFhConfigMgr, SetBackupStatus)
        HRESULT ( STDMETHODCALLTYPE *SetBackupStatus )( 
            __RPC__in IFhConfigMgr * This,
            /* [annotation][in] */ 
            _In_  FH_BACKUP_STATUS BackupStatus);
        
        DECLSPEC_XFGVIRT(IFhConfigMgr, GetDefaultTarget)
        HRESULT ( STDMETHODCALLTYPE *GetDefaultTarget )( 
            __RPC__in IFhConfigMgr * This,
            /* [annotation][out] */ 
            _Out_  IFhTarget **DefaultTarget);
        
        DECLSPEC_XFGVIRT(IFhConfigMgr, ValidateTarget)
        HRESULT ( STDMETHODCALLTYPE *ValidateTarget )( 
            __RPC__in IFhConfigMgr * This,
            /* [annotation][in] */ 
            _In_  BSTR TargetUrl,
            /* [annotation][out] */ 
            _Out_  PFH_DEVICE_VALIDATION_RESULT ValidationResult);
        
        DECLSPEC_XFGVIRT(IFhConfigMgr, ProvisionAndSetNewTarget)
        HRESULT ( STDMETHODCALLTYPE *ProvisionAndSetNewTarget )( 
            __RPC__in IFhConfigMgr * This,
            /* [annotation][in] */ 
            _In_  BSTR TargetUrl,
            /* [annotation][in] */ 
            _In_  BSTR TargetName);
        
        DECLSPEC_XFGVIRT(IFhConfigMgr, ChangeDefaultTargetRecommendation)
        HRESULT ( STDMETHODCALLTYPE *ChangeDefaultTargetRecommendation )( 
            __RPC__in IFhConfigMgr * This,
            /* [annotation][in] */ 
            _In_  BOOL Recommend);
        
        DECLSPEC_XFGVIRT(IFhConfigMgr, QueryProtectionStatus)
        HRESULT ( STDMETHODCALLTYPE *QueryProtectionStatus )( 
            __RPC__in IFhConfigMgr * This,
            /* [annotation][out] */ 
            _Out_  DWORD *ProtectionState,
            /* [annotation][out] */ 
            _Out_  BSTR *ProtectedUntilTime);
        
        END_INTERFACE
    } IFhConfigMgrVtbl;

    interface IFhConfigMgr
    {
        CONST_VTBL struct IFhConfigMgrVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFhConfigMgr_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFhConfigMgr_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFhConfigMgr_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFhConfigMgr_LoadConfiguration(This)	\
    ( (This)->lpVtbl -> LoadConfiguration(This) ) 

#define IFhConfigMgr_CreateDefaultConfiguration(This,OverwriteIfExists)	\
    ( (This)->lpVtbl -> CreateDefaultConfiguration(This,OverwriteIfExists) ) 

#define IFhConfigMgr_SaveConfiguration(This)	\
    ( (This)->lpVtbl -> SaveConfiguration(This) ) 

#define IFhConfigMgr_AddRemoveExcludeRule(This,Add,Category,Item)	\
    ( (This)->lpVtbl -> AddRemoveExcludeRule(This,Add,Category,Item) ) 

#define IFhConfigMgr_GetIncludeExcludeRules(This,Include,Category,Iterator)	\
    ( (This)->lpVtbl -> GetIncludeExcludeRules(This,Include,Category,Iterator) ) 

#define IFhConfigMgr_GetLocalPolicy(This,LocalPolicyType,PolicyValue)	\
    ( (This)->lpVtbl -> GetLocalPolicy(This,LocalPolicyType,PolicyValue) ) 

#define IFhConfigMgr_SetLocalPolicy(This,LocalPolicyType,PolicyValue)	\
    ( (This)->lpVtbl -> SetLocalPolicy(This,LocalPolicyType,PolicyValue) ) 

#define IFhConfigMgr_GetBackupStatus(This,BackupStatus)	\
    ( (This)->lpVtbl -> GetBackupStatus(This,BackupStatus) ) 

#define IFhConfigMgr_SetBackupStatus(This,BackupStatus)	\
    ( (This)->lpVtbl -> SetBackupStatus(This,BackupStatus) ) 

#define IFhConfigMgr_GetDefaultTarget(This,DefaultTarget)	\
    ( (This)->lpVtbl -> GetDefaultTarget(This,DefaultTarget) ) 

#define IFhConfigMgr_ValidateTarget(This,TargetUrl,ValidationResult)	\
    ( (This)->lpVtbl -> ValidateTarget(This,TargetUrl,ValidationResult) ) 

#define IFhConfigMgr_ProvisionAndSetNewTarget(This,TargetUrl,TargetName)	\
    ( (This)->lpVtbl -> ProvisionAndSetNewTarget(This,TargetUrl,TargetName) ) 

#define IFhConfigMgr_ChangeDefaultTargetRecommendation(This,Recommend)	\
    ( (This)->lpVtbl -> ChangeDefaultTargetRecommendation(This,Recommend) ) 

#define IFhConfigMgr_QueryProtectionStatus(This,ProtectionState,ProtectedUntilTime)	\
    ( (This)->lpVtbl -> QueryProtectionStatus(This,ProtectionState,ProtectedUntilTime) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFhConfigMgr_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_fhcfg_0000_0003 */
/* [local] */ 

#pragma deprecated(IFhReassociation)


extern RPC_IF_HANDLE __MIDL_itf_fhcfg_0000_0003_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_fhcfg_0000_0003_v0_0_s_ifspec;

#ifndef __IFhReassociation_INTERFACE_DEFINED__
#define __IFhReassociation_INTERFACE_DEFINED__

/* interface IFhReassociation */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IFhReassociation;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6544A28A-F68D-47ac-91EF-16B2B36AA3EE")
    IFhReassociation : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ValidateTarget( 
            /* [annotation][in] */ 
            _In_  BSTR TargetUrl,
            /* [annotation][out] */ 
            _Out_  PFH_DEVICE_VALIDATION_RESULT ValidationResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ScanTargetForConfigurations( 
            /* [annotation][in] */ 
            _In_  BSTR TargetUrl) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetConfigurationDetails( 
            /* [annotation][in] */ 
            _In_  DWORD Index,
            /* [annotation][out] */ 
            _Out_  BSTR *UserName,
            /* [annotation][out] */ 
            _Out_  BSTR *PcName,
            /* [annotation][out] */ 
            _Out_  FILETIME *BackupTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SelectConfiguration( 
            /* [annotation][in] */ 
            _In_  DWORD Index) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PerformReassociation( 
            /* [annotation][in] */ 
            _In_  BOOL OverwriteIfExists) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IFhReassociationVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IFhReassociation * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IFhReassociation * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IFhReassociation * This);
        
        DECLSPEC_XFGVIRT(IFhReassociation, ValidateTarget)
        HRESULT ( STDMETHODCALLTYPE *ValidateTarget )( 
            __RPC__in IFhReassociation * This,
            /* [annotation][in] */ 
            _In_  BSTR TargetUrl,
            /* [annotation][out] */ 
            _Out_  PFH_DEVICE_VALIDATION_RESULT ValidationResult);
        
        DECLSPEC_XFGVIRT(IFhReassociation, ScanTargetForConfigurations)
        HRESULT ( STDMETHODCALLTYPE *ScanTargetForConfigurations )( 
            __RPC__in IFhReassociation * This,
            /* [annotation][in] */ 
            _In_  BSTR TargetUrl);
        
        DECLSPEC_XFGVIRT(IFhReassociation, GetConfigurationDetails)
        HRESULT ( STDMETHODCALLTYPE *GetConfigurationDetails )( 
            __RPC__in IFhReassociation * This,
            /* [annotation][in] */ 
            _In_  DWORD Index,
            /* [annotation][out] */ 
            _Out_  BSTR *UserName,
            /* [annotation][out] */ 
            _Out_  BSTR *PcName,
            /* [annotation][out] */ 
            _Out_  FILETIME *BackupTime);
        
        DECLSPEC_XFGVIRT(IFhReassociation, SelectConfiguration)
        HRESULT ( STDMETHODCALLTYPE *SelectConfiguration )( 
            __RPC__in IFhReassociation * This,
            /* [annotation][in] */ 
            _In_  DWORD Index);
        
        DECLSPEC_XFGVIRT(IFhReassociation, PerformReassociation)
        HRESULT ( STDMETHODCALLTYPE *PerformReassociation )( 
            __RPC__in IFhReassociation * This,
            /* [annotation][in] */ 
            _In_  BOOL OverwriteIfExists);
        
        END_INTERFACE
    } IFhReassociationVtbl;

    interface IFhReassociation
    {
        CONST_VTBL struct IFhReassociationVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFhReassociation_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFhReassociation_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFhReassociation_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFhReassociation_ValidateTarget(This,TargetUrl,ValidationResult)	\
    ( (This)->lpVtbl -> ValidateTarget(This,TargetUrl,ValidationResult) ) 

#define IFhReassociation_ScanTargetForConfigurations(This,TargetUrl)	\
    ( (This)->lpVtbl -> ScanTargetForConfigurations(This,TargetUrl) ) 

#define IFhReassociation_GetConfigurationDetails(This,Index,UserName,PcName,BackupTime)	\
    ( (This)->lpVtbl -> GetConfigurationDetails(This,Index,UserName,PcName,BackupTime) ) 

#define IFhReassociation_SelectConfiguration(This,Index)	\
    ( (This)->lpVtbl -> SelectConfiguration(This,Index) ) 

#define IFhReassociation_PerformReassociation(This,OverwriteIfExists)	\
    ( (This)->lpVtbl -> PerformReassociation(This,OverwriteIfExists) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFhReassociation_INTERFACE_DEFINED__ */



#ifndef __FhConfigMgrLib_LIBRARY_DEFINED__
#define __FhConfigMgrLib_LIBRARY_DEFINED__

/* library FhConfigMgrLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_FhConfigMgrLib;

EXTERN_C const CLSID CLSID_FhConfigMgr;

#ifdef __cplusplus

class DECLSPEC_UUID("ED43BB3C-09E9-498a-9DF6-2177244C6DB4")
FhConfigMgr;
#endif

EXTERN_C const CLSID CLSID_FhReassociation;

#ifdef __cplusplus

class DECLSPEC_UUID("4D728E35-16FA-4320-9E8B-BFD7100A8846")
FhReassociation;
#endif
#endif /* __FhConfigMgrLib_LIBRARY_DEFINED__ */

/* interface __MIDL_itf_fhcfg_0000_0005 */
/* [local] */ 

#endif // if NTDDI_VERSION >= NTDDI_WIN8
#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_fhcfg_0000_0005_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_fhcfg_0000_0005_v0_0_s_ifspec;

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


