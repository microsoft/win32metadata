

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

#ifndef __fsrmpipeline_h__
#define __fsrmpipeline_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IFsrmPropertyDefinition_FWD_DEFINED__
#define __IFsrmPropertyDefinition_FWD_DEFINED__
typedef interface IFsrmPropertyDefinition IFsrmPropertyDefinition;

#endif 	/* __IFsrmPropertyDefinition_FWD_DEFINED__ */


#ifndef __IFsrmPropertyDefinition2_FWD_DEFINED__
#define __IFsrmPropertyDefinition2_FWD_DEFINED__
typedef interface IFsrmPropertyDefinition2 IFsrmPropertyDefinition2;

#endif 	/* __IFsrmPropertyDefinition2_FWD_DEFINED__ */


#ifndef __IFsrmPropertyDefinitionValue_FWD_DEFINED__
#define __IFsrmPropertyDefinitionValue_FWD_DEFINED__
typedef interface IFsrmPropertyDefinitionValue IFsrmPropertyDefinitionValue;

#endif 	/* __IFsrmPropertyDefinitionValue_FWD_DEFINED__ */


#ifndef __IFsrmProperty_FWD_DEFINED__
#define __IFsrmProperty_FWD_DEFINED__
typedef interface IFsrmProperty IFsrmProperty;

#endif 	/* __IFsrmProperty_FWD_DEFINED__ */


#ifndef __IFsrmRule_FWD_DEFINED__
#define __IFsrmRule_FWD_DEFINED__
typedef interface IFsrmRule IFsrmRule;

#endif 	/* __IFsrmRule_FWD_DEFINED__ */


#ifndef __IFsrmClassificationRule_FWD_DEFINED__
#define __IFsrmClassificationRule_FWD_DEFINED__
typedef interface IFsrmClassificationRule IFsrmClassificationRule;

#endif 	/* __IFsrmClassificationRule_FWD_DEFINED__ */


#ifndef __IFsrmPipelineModuleDefinition_FWD_DEFINED__
#define __IFsrmPipelineModuleDefinition_FWD_DEFINED__
typedef interface IFsrmPipelineModuleDefinition IFsrmPipelineModuleDefinition;

#endif 	/* __IFsrmPipelineModuleDefinition_FWD_DEFINED__ */


#ifndef __IFsrmClassifierModuleDefinition_FWD_DEFINED__
#define __IFsrmClassifierModuleDefinition_FWD_DEFINED__
typedef interface IFsrmClassifierModuleDefinition IFsrmClassifierModuleDefinition;

#endif 	/* __IFsrmClassifierModuleDefinition_FWD_DEFINED__ */


#ifndef __IFsrmStorageModuleDefinition_FWD_DEFINED__
#define __IFsrmStorageModuleDefinition_FWD_DEFINED__
typedef interface IFsrmStorageModuleDefinition IFsrmStorageModuleDefinition;

#endif 	/* __IFsrmStorageModuleDefinition_FWD_DEFINED__ */


#ifndef __IFsrmClassificationManager_FWD_DEFINED__
#define __IFsrmClassificationManager_FWD_DEFINED__
typedef interface IFsrmClassificationManager IFsrmClassificationManager;

#endif 	/* __IFsrmClassificationManager_FWD_DEFINED__ */


#ifndef __IFsrmClassificationManager2_FWD_DEFINED__
#define __IFsrmClassificationManager2_FWD_DEFINED__
typedef interface IFsrmClassificationManager2 IFsrmClassificationManager2;

#endif 	/* __IFsrmClassificationManager2_FWD_DEFINED__ */


#ifndef __IFsrmPropertyBag_FWD_DEFINED__
#define __IFsrmPropertyBag_FWD_DEFINED__
typedef interface IFsrmPropertyBag IFsrmPropertyBag;

#endif 	/* __IFsrmPropertyBag_FWD_DEFINED__ */


#ifndef __IFsrmPropertyBag2_FWD_DEFINED__
#define __IFsrmPropertyBag2_FWD_DEFINED__
typedef interface IFsrmPropertyBag2 IFsrmPropertyBag2;

#endif 	/* __IFsrmPropertyBag2_FWD_DEFINED__ */


#ifndef __IFsrmPipelineModuleImplementation_FWD_DEFINED__
#define __IFsrmPipelineModuleImplementation_FWD_DEFINED__
typedef interface IFsrmPipelineModuleImplementation IFsrmPipelineModuleImplementation;

#endif 	/* __IFsrmPipelineModuleImplementation_FWD_DEFINED__ */


#ifndef __IFsrmClassifierModuleImplementation_FWD_DEFINED__
#define __IFsrmClassifierModuleImplementation_FWD_DEFINED__
typedef interface IFsrmClassifierModuleImplementation IFsrmClassifierModuleImplementation;

#endif 	/* __IFsrmClassifierModuleImplementation_FWD_DEFINED__ */


#ifndef __IFsrmStorageModuleImplementation_FWD_DEFINED__
#define __IFsrmStorageModuleImplementation_FWD_DEFINED__
typedef interface IFsrmStorageModuleImplementation IFsrmStorageModuleImplementation;

#endif 	/* __IFsrmStorageModuleImplementation_FWD_DEFINED__ */


#ifndef __IFsrmPipelineModuleConnector_FWD_DEFINED__
#define __IFsrmPipelineModuleConnector_FWD_DEFINED__
typedef interface IFsrmPipelineModuleConnector IFsrmPipelineModuleConnector;

#endif 	/* __IFsrmPipelineModuleConnector_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "fsrm.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_fsrmpipeline_0000_0000 */
/* [local] */ 

#include <winapifamily.h>
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
















#define	FSRM_DISPID_PROPERTY_DEFINITION	( ( FSRM_DISPID_FEATURE_CLASSIFICATION | 0x100000 )  )

#define	FSRM_DISPID_PROPERTY_DEFINITION2	( ( FSRM_DISPID_PROPERTY_DEFINITION | 0x10000 )  )

#define	FSRM_DISPID_PROPERTY	( ( FSRM_DISPID_FEATURE_CLASSIFICATION | 0x200000 )  )

#define	FSRM_DISPID_RULE	( ( FSRM_DISPID_FEATURE_CLASSIFICATION | 0x300000 )  )

#define	FSRM_DISPID_CLASSIFICATION_RULE	( ( FSRM_DISPID_RULE | 0x10000 )  )

#define	FSRM_DISPID_EXPIRATION_RULE	( ( FSRM_DISPID_RULE | 0x20000 )  )

#define	FSRM_DISPID_PIPELINE_MODULE_DEFINITION	( ( FSRM_DISPID_FEATURE_CLASSIFICATION | 0x400000 )  )

#define	FSRM_DISPID_CLASSIFIER_MODULE_DEFINITION	( ( FSRM_DISPID_PIPELINE_MODULE_DEFINITION | 0x10000 )  )

#define	FSRM_DISPID_STORAGE_MODULE_DEFINITION	( ( FSRM_DISPID_PIPELINE_MODULE_DEFINITION | 0x20000 )  )

#define	FSRM_DISPID_CLASSIFICATION_MANAGER	( ( FSRM_DISPID_FEATURE_CLASSIFICATION | 0x500000 )  )

#define	FSRM_DISPID_CLASSIFICATION_MANAGER2	( ( FSRM_DISPID_CLASSIFICATION_MANAGER | 0x10000 )  )

#define	FSRM_DISPID_CLASSIFICATION_EVENTS	( ( FSRM_DISPID_FEATURE_CLASSIFICATION | 0x600000 )  )

#define	FSRM_DISPID_PROPERTY_DEFINITION_VALUE	( ( FSRM_DISPID_FEATURE_CLASSIFICATION | 0x700000 )  )

#define	FSRM_DISPID_PROPERTY_BAG	( ( FSRM_DISPID_FEATURE_PIPELINE | 0x100000 )  )

#define	FSRM_DISPID_PROPERTY_BAG2	( ( FSRM_DISPID_PROPERTY_BAG | 0x10000 )  )

#define	FSRM_DISPID_PIPELINE_MODULE_IMPLEMENTATION	( ( FSRM_DISPID_FEATURE_PIPELINE | 0x200000 )  )

#define	FSRM_DISPID_CLASSIFIER_MODULE_IMPLEMENTATION	( ( FSRM_DISPID_PIPELINE_MODULE_IMPLEMENTATION | 0x10000 )  )

#define	FSRM_DISPID_STORAGE_MODULE_IMPLEMENTATION	( ( FSRM_DISPID_PIPELINE_MODULE_IMPLEMENTATION | 0x20000 )  )

#define	FSRM_DISPID_PIPELINE_MODULE_CONNECTOR	( ( FSRM_DISPID_FEATURE_PIPELINE | 0x300000 )  )

#define	FsrmMaxNumberPropertyDefinitions	( 100 )



extern RPC_IF_HANDLE __MIDL_itf_fsrmpipeline_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_fsrmpipeline_0000_0000_v0_0_s_ifspec;

#ifndef __IFsrmPropertyDefinition_INTERFACE_DEFINED__
#define __IFsrmPropertyDefinition_INTERFACE_DEFINED__

/* interface IFsrmPropertyDefinition */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IFsrmPropertyDefinition;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("ede0150f-e9a3-419c-877c-01fe5d24c5d3")
    IFsrmPropertyDefinition : public IFsrmObject
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *name) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [annotation][in] */ 
            _In_  BSTR name) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Type( 
            /* [annotation][retval][out] */ 
            _Out_retval_  FsrmPropertyDefinitionType *type) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Type( 
            /* [annotation][in] */ 
            _In_  FsrmPropertyDefinitionType type) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PossibleValues( 
            /* [annotation][retval][out] */ 
            _Out_retval_  SAFEARRAY * *possibleValues) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_PossibleValues( 
            /* [annotation][in] */ 
            _In_  SAFEARRAY * possibleValues) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ValueDescriptions( 
            /* [annotation][retval][out] */ 
            _Out_retval_  SAFEARRAY * *valueDescriptions) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ValueDescriptions( 
            /* [annotation][in] */ 
            _In_  SAFEARRAY * valueDescriptions) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Parameters( 
            /* [annotation][retval][out] */ 
            _Out_retval_  SAFEARRAY * *parameters) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Parameters( 
            /* [annotation][in] */ 
            _In_  SAFEARRAY * parameters) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IFsrmPropertyDefinitionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IFsrmPropertyDefinition * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IFsrmPropertyDefinition * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IFsrmPropertyDefinition * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IFsrmPropertyDefinition * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IFsrmPropertyDefinition * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IFsrmPropertyDefinition * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][size_is][in] */ 
            _In_reads_(cNames)  LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cNames)  DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFsrmPropertyDefinition * This,
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
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Id )( 
            __RPC__in IFsrmPropertyDefinition * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  FSRM_OBJECT_ID *id);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Description )( 
            __RPC__in IFsrmPropertyDefinition * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *description);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Description )( 
            __RPC__in IFsrmPropertyDefinition * This,
            /* [annotation][in] */ 
            _In_  BSTR description);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            __RPC__in IFsrmPropertyDefinition * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Commit )( 
            __RPC__in IFsrmPropertyDefinition * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            __RPC__in IFsrmPropertyDefinition * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *name);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            __RPC__in IFsrmPropertyDefinition * This,
            /* [annotation][in] */ 
            _In_  BSTR name);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Type )( 
            __RPC__in IFsrmPropertyDefinition * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  FsrmPropertyDefinitionType *type);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Type )( 
            __RPC__in IFsrmPropertyDefinition * This,
            /* [annotation][in] */ 
            _In_  FsrmPropertyDefinitionType type);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PossibleValues )( 
            __RPC__in IFsrmPropertyDefinition * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  SAFEARRAY * *possibleValues);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PossibleValues )( 
            __RPC__in IFsrmPropertyDefinition * This,
            /* [annotation][in] */ 
            _In_  SAFEARRAY * possibleValues);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ValueDescriptions )( 
            __RPC__in IFsrmPropertyDefinition * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  SAFEARRAY * *valueDescriptions);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ValueDescriptions )( 
            __RPC__in IFsrmPropertyDefinition * This,
            /* [annotation][in] */ 
            _In_  SAFEARRAY * valueDescriptions);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Parameters )( 
            __RPC__in IFsrmPropertyDefinition * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  SAFEARRAY * *parameters);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Parameters )( 
            __RPC__in IFsrmPropertyDefinition * This,
            /* [annotation][in] */ 
            _In_  SAFEARRAY * parameters);
        
        END_INTERFACE
    } IFsrmPropertyDefinitionVtbl;

    interface IFsrmPropertyDefinition
    {
        CONST_VTBL struct IFsrmPropertyDefinitionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFsrmPropertyDefinition_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFsrmPropertyDefinition_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFsrmPropertyDefinition_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFsrmPropertyDefinition_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFsrmPropertyDefinition_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFsrmPropertyDefinition_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFsrmPropertyDefinition_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IFsrmPropertyDefinition_get_Id(This,id)	\
    ( (This)->lpVtbl -> get_Id(This,id) ) 

#define IFsrmPropertyDefinition_get_Description(This,description)	\
    ( (This)->lpVtbl -> get_Description(This,description) ) 

#define IFsrmPropertyDefinition_put_Description(This,description)	\
    ( (This)->lpVtbl -> put_Description(This,description) ) 

#define IFsrmPropertyDefinition_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define IFsrmPropertyDefinition_Commit(This)	\
    ( (This)->lpVtbl -> Commit(This) ) 


#define IFsrmPropertyDefinition_get_Name(This,name)	\
    ( (This)->lpVtbl -> get_Name(This,name) ) 

#define IFsrmPropertyDefinition_put_Name(This,name)	\
    ( (This)->lpVtbl -> put_Name(This,name) ) 

#define IFsrmPropertyDefinition_get_Type(This,type)	\
    ( (This)->lpVtbl -> get_Type(This,type) ) 

#define IFsrmPropertyDefinition_put_Type(This,type)	\
    ( (This)->lpVtbl -> put_Type(This,type) ) 

#define IFsrmPropertyDefinition_get_PossibleValues(This,possibleValues)	\
    ( (This)->lpVtbl -> get_PossibleValues(This,possibleValues) ) 

#define IFsrmPropertyDefinition_put_PossibleValues(This,possibleValues)	\
    ( (This)->lpVtbl -> put_PossibleValues(This,possibleValues) ) 

#define IFsrmPropertyDefinition_get_ValueDescriptions(This,valueDescriptions)	\
    ( (This)->lpVtbl -> get_ValueDescriptions(This,valueDescriptions) ) 

#define IFsrmPropertyDefinition_put_ValueDescriptions(This,valueDescriptions)	\
    ( (This)->lpVtbl -> put_ValueDescriptions(This,valueDescriptions) ) 

#define IFsrmPropertyDefinition_get_Parameters(This,parameters)	\
    ( (This)->lpVtbl -> get_Parameters(This,parameters) ) 

#define IFsrmPropertyDefinition_put_Parameters(This,parameters)	\
    ( (This)->lpVtbl -> put_Parameters(This,parameters) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFsrmPropertyDefinition_INTERFACE_DEFINED__ */


#ifndef __IFsrmPropertyDefinition2_INTERFACE_DEFINED__
#define __IFsrmPropertyDefinition2_INTERFACE_DEFINED__

/* interface IFsrmPropertyDefinition2 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IFsrmPropertyDefinition2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("47782152-d16c-4229-b4e1-0ddfe308b9f6")
    IFsrmPropertyDefinition2 : public IFsrmPropertyDefinition
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PropertyDefinitionFlags( 
            /* [annotation][retval][out] */ 
            _Out_retval_  long *propertyDefinitionFlags) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DisplayName( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *name) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DisplayName( 
            /* [annotation][in] */ 
            _In_  BSTR name) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AppliesTo( 
            /* [annotation][retval][out] */ 
            _Out_retval_  long *appliesTo) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ValueDefinitions( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmCollection **valueDefinitions) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IFsrmPropertyDefinition2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IFsrmPropertyDefinition2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IFsrmPropertyDefinition2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IFsrmPropertyDefinition2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IFsrmPropertyDefinition2 * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IFsrmPropertyDefinition2 * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IFsrmPropertyDefinition2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][size_is][in] */ 
            _In_reads_(cNames)  LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cNames)  DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFsrmPropertyDefinition2 * This,
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
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Id )( 
            __RPC__in IFsrmPropertyDefinition2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  FSRM_OBJECT_ID *id);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Description )( 
            __RPC__in IFsrmPropertyDefinition2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *description);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Description )( 
            __RPC__in IFsrmPropertyDefinition2 * This,
            /* [annotation][in] */ 
            _In_  BSTR description);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            __RPC__in IFsrmPropertyDefinition2 * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Commit )( 
            __RPC__in IFsrmPropertyDefinition2 * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            __RPC__in IFsrmPropertyDefinition2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *name);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            __RPC__in IFsrmPropertyDefinition2 * This,
            /* [annotation][in] */ 
            _In_  BSTR name);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Type )( 
            __RPC__in IFsrmPropertyDefinition2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  FsrmPropertyDefinitionType *type);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Type )( 
            __RPC__in IFsrmPropertyDefinition2 * This,
            /* [annotation][in] */ 
            _In_  FsrmPropertyDefinitionType type);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PossibleValues )( 
            __RPC__in IFsrmPropertyDefinition2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  SAFEARRAY * *possibleValues);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PossibleValues )( 
            __RPC__in IFsrmPropertyDefinition2 * This,
            /* [annotation][in] */ 
            _In_  SAFEARRAY * possibleValues);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ValueDescriptions )( 
            __RPC__in IFsrmPropertyDefinition2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  SAFEARRAY * *valueDescriptions);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ValueDescriptions )( 
            __RPC__in IFsrmPropertyDefinition2 * This,
            /* [annotation][in] */ 
            _In_  SAFEARRAY * valueDescriptions);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Parameters )( 
            __RPC__in IFsrmPropertyDefinition2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  SAFEARRAY * *parameters);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Parameters )( 
            __RPC__in IFsrmPropertyDefinition2 * This,
            /* [annotation][in] */ 
            _In_  SAFEARRAY * parameters);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PropertyDefinitionFlags )( 
            __RPC__in IFsrmPropertyDefinition2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *propertyDefinitionFlags);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DisplayName )( 
            __RPC__in IFsrmPropertyDefinition2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *name);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DisplayName )( 
            __RPC__in IFsrmPropertyDefinition2 * This,
            /* [annotation][in] */ 
            _In_  BSTR name);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AppliesTo )( 
            __RPC__in IFsrmPropertyDefinition2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *appliesTo);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ValueDefinitions )( 
            __RPC__in IFsrmPropertyDefinition2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmCollection **valueDefinitions);
        
        END_INTERFACE
    } IFsrmPropertyDefinition2Vtbl;

    interface IFsrmPropertyDefinition2
    {
        CONST_VTBL struct IFsrmPropertyDefinition2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFsrmPropertyDefinition2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFsrmPropertyDefinition2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFsrmPropertyDefinition2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFsrmPropertyDefinition2_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFsrmPropertyDefinition2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFsrmPropertyDefinition2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFsrmPropertyDefinition2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IFsrmPropertyDefinition2_get_Id(This,id)	\
    ( (This)->lpVtbl -> get_Id(This,id) ) 

#define IFsrmPropertyDefinition2_get_Description(This,description)	\
    ( (This)->lpVtbl -> get_Description(This,description) ) 

#define IFsrmPropertyDefinition2_put_Description(This,description)	\
    ( (This)->lpVtbl -> put_Description(This,description) ) 

#define IFsrmPropertyDefinition2_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define IFsrmPropertyDefinition2_Commit(This)	\
    ( (This)->lpVtbl -> Commit(This) ) 


#define IFsrmPropertyDefinition2_get_Name(This,name)	\
    ( (This)->lpVtbl -> get_Name(This,name) ) 

#define IFsrmPropertyDefinition2_put_Name(This,name)	\
    ( (This)->lpVtbl -> put_Name(This,name) ) 

#define IFsrmPropertyDefinition2_get_Type(This,type)	\
    ( (This)->lpVtbl -> get_Type(This,type) ) 

#define IFsrmPropertyDefinition2_put_Type(This,type)	\
    ( (This)->lpVtbl -> put_Type(This,type) ) 

#define IFsrmPropertyDefinition2_get_PossibleValues(This,possibleValues)	\
    ( (This)->lpVtbl -> get_PossibleValues(This,possibleValues) ) 

#define IFsrmPropertyDefinition2_put_PossibleValues(This,possibleValues)	\
    ( (This)->lpVtbl -> put_PossibleValues(This,possibleValues) ) 

#define IFsrmPropertyDefinition2_get_ValueDescriptions(This,valueDescriptions)	\
    ( (This)->lpVtbl -> get_ValueDescriptions(This,valueDescriptions) ) 

#define IFsrmPropertyDefinition2_put_ValueDescriptions(This,valueDescriptions)	\
    ( (This)->lpVtbl -> put_ValueDescriptions(This,valueDescriptions) ) 

#define IFsrmPropertyDefinition2_get_Parameters(This,parameters)	\
    ( (This)->lpVtbl -> get_Parameters(This,parameters) ) 

#define IFsrmPropertyDefinition2_put_Parameters(This,parameters)	\
    ( (This)->lpVtbl -> put_Parameters(This,parameters) ) 


#define IFsrmPropertyDefinition2_get_PropertyDefinitionFlags(This,propertyDefinitionFlags)	\
    ( (This)->lpVtbl -> get_PropertyDefinitionFlags(This,propertyDefinitionFlags) ) 

#define IFsrmPropertyDefinition2_get_DisplayName(This,name)	\
    ( (This)->lpVtbl -> get_DisplayName(This,name) ) 

#define IFsrmPropertyDefinition2_put_DisplayName(This,name)	\
    ( (This)->lpVtbl -> put_DisplayName(This,name) ) 

#define IFsrmPropertyDefinition2_get_AppliesTo(This,appliesTo)	\
    ( (This)->lpVtbl -> get_AppliesTo(This,appliesTo) ) 

#define IFsrmPropertyDefinition2_get_ValueDefinitions(This,valueDefinitions)	\
    ( (This)->lpVtbl -> get_ValueDefinitions(This,valueDefinitions) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFsrmPropertyDefinition2_INTERFACE_DEFINED__ */


#ifndef __IFsrmPropertyDefinitionValue_INTERFACE_DEFINED__
#define __IFsrmPropertyDefinitionValue_INTERFACE_DEFINED__

/* interface IFsrmPropertyDefinitionValue */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IFsrmPropertyDefinitionValue;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E946D148-BD67-4178-8E22-1C44925ED710")
    IFsrmPropertyDefinitionValue : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *name) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DisplayName( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *displayName) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Description( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *description) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UniqueID( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *uniqueID) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IFsrmPropertyDefinitionValueVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IFsrmPropertyDefinitionValue * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IFsrmPropertyDefinitionValue * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IFsrmPropertyDefinitionValue * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IFsrmPropertyDefinitionValue * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IFsrmPropertyDefinitionValue * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IFsrmPropertyDefinitionValue * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][size_is][in] */ 
            _In_reads_(cNames)  LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cNames)  DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFsrmPropertyDefinitionValue * This,
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
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            __RPC__in IFsrmPropertyDefinitionValue * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *name);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DisplayName )( 
            __RPC__in IFsrmPropertyDefinitionValue * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *displayName);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Description )( 
            __RPC__in IFsrmPropertyDefinitionValue * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *description);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UniqueID )( 
            __RPC__in IFsrmPropertyDefinitionValue * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *uniqueID);
        
        END_INTERFACE
    } IFsrmPropertyDefinitionValueVtbl;

    interface IFsrmPropertyDefinitionValue
    {
        CONST_VTBL struct IFsrmPropertyDefinitionValueVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFsrmPropertyDefinitionValue_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFsrmPropertyDefinitionValue_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFsrmPropertyDefinitionValue_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFsrmPropertyDefinitionValue_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFsrmPropertyDefinitionValue_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFsrmPropertyDefinitionValue_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFsrmPropertyDefinitionValue_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IFsrmPropertyDefinitionValue_get_Name(This,name)	\
    ( (This)->lpVtbl -> get_Name(This,name) ) 

#define IFsrmPropertyDefinitionValue_get_DisplayName(This,displayName)	\
    ( (This)->lpVtbl -> get_DisplayName(This,displayName) ) 

#define IFsrmPropertyDefinitionValue_get_Description(This,description)	\
    ( (This)->lpVtbl -> get_Description(This,description) ) 

#define IFsrmPropertyDefinitionValue_get_UniqueID(This,uniqueID)	\
    ( (This)->lpVtbl -> get_UniqueID(This,uniqueID) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFsrmPropertyDefinitionValue_INTERFACE_DEFINED__ */


#ifndef __IFsrmProperty_INTERFACE_DEFINED__
#define __IFsrmProperty_INTERFACE_DEFINED__

/* interface IFsrmProperty */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IFsrmProperty;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4a73fee4-4102-4fcc-9ffb-38614f9ee768")
    IFsrmProperty : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *name) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Value( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *value) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Sources( 
            /* [annotation][retval][out] */ 
            _Out_retval_  SAFEARRAY * *sources) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PropertyFlags( 
            /* [annotation][retval][out] */ 
            _Out_retval_  long *flags) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IFsrmPropertyVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IFsrmProperty * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IFsrmProperty * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IFsrmProperty * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IFsrmProperty * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IFsrmProperty * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IFsrmProperty * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][size_is][in] */ 
            _In_reads_(cNames)  LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cNames)  DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFsrmProperty * This,
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
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            __RPC__in IFsrmProperty * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *name);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Value )( 
            __RPC__in IFsrmProperty * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *value);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Sources )( 
            __RPC__in IFsrmProperty * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  SAFEARRAY * *sources);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PropertyFlags )( 
            __RPC__in IFsrmProperty * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *flags);
        
        END_INTERFACE
    } IFsrmPropertyVtbl;

    interface IFsrmProperty
    {
        CONST_VTBL struct IFsrmPropertyVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFsrmProperty_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFsrmProperty_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFsrmProperty_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFsrmProperty_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFsrmProperty_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFsrmProperty_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFsrmProperty_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IFsrmProperty_get_Name(This,name)	\
    ( (This)->lpVtbl -> get_Name(This,name) ) 

#define IFsrmProperty_get_Value(This,value)	\
    ( (This)->lpVtbl -> get_Value(This,value) ) 

#define IFsrmProperty_get_Sources(This,sources)	\
    ( (This)->lpVtbl -> get_Sources(This,sources) ) 

#define IFsrmProperty_get_PropertyFlags(This,flags)	\
    ( (This)->lpVtbl -> get_PropertyFlags(This,flags) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFsrmProperty_INTERFACE_DEFINED__ */


#ifndef __IFsrmRule_INTERFACE_DEFINED__
#define __IFsrmRule_INTERFACE_DEFINED__

/* interface IFsrmRule */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IFsrmRule;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("cb0df960-16f5-4495-9079-3f9360d831df")
    IFsrmRule : public IFsrmObject
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *name) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [annotation][in] */ 
            _In_  BSTR name) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RuleType( 
            /* [annotation][retval][out] */ 
            _Out_retval_  FsrmRuleType *ruleType) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ModuleDefinitionName( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *moduleDefinitionName) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ModuleDefinitionName( 
            /* [annotation][in] */ 
            _In_  BSTR moduleDefinitionName) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_NamespaceRoots( 
            /* [annotation][retval][out] */ 
            _Out_retval_  SAFEARRAY * *namespaceRoots) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_NamespaceRoots( 
            /* [annotation][in] */ 
            _In_  SAFEARRAY * namespaceRoots) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RuleFlags( 
            /* [annotation][retval][out] */ 
            _Out_retval_  long *ruleFlags) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_RuleFlags( 
            /* [annotation][in] */ 
            _In_  long ruleFlags) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Parameters( 
            /* [annotation][retval][out] */ 
            _Out_retval_  SAFEARRAY * *parameters) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Parameters( 
            /* [annotation][in] */ 
            _In_  SAFEARRAY * parameters) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LastModified( 
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT *lastModified) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IFsrmRuleVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IFsrmRule * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IFsrmRule * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IFsrmRule * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IFsrmRule * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IFsrmRule * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IFsrmRule * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][size_is][in] */ 
            _In_reads_(cNames)  LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cNames)  DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFsrmRule * This,
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
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Id )( 
            __RPC__in IFsrmRule * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  FSRM_OBJECT_ID *id);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Description )( 
            __RPC__in IFsrmRule * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *description);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Description )( 
            __RPC__in IFsrmRule * This,
            /* [annotation][in] */ 
            _In_  BSTR description);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            __RPC__in IFsrmRule * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Commit )( 
            __RPC__in IFsrmRule * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            __RPC__in IFsrmRule * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *name);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            __RPC__in IFsrmRule * This,
            /* [annotation][in] */ 
            _In_  BSTR name);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RuleType )( 
            __RPC__in IFsrmRule * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  FsrmRuleType *ruleType);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ModuleDefinitionName )( 
            __RPC__in IFsrmRule * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *moduleDefinitionName);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ModuleDefinitionName )( 
            __RPC__in IFsrmRule * This,
            /* [annotation][in] */ 
            _In_  BSTR moduleDefinitionName);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NamespaceRoots )( 
            __RPC__in IFsrmRule * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  SAFEARRAY * *namespaceRoots);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_NamespaceRoots )( 
            __RPC__in IFsrmRule * This,
            /* [annotation][in] */ 
            _In_  SAFEARRAY * namespaceRoots);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RuleFlags )( 
            __RPC__in IFsrmRule * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *ruleFlags);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RuleFlags )( 
            __RPC__in IFsrmRule * This,
            /* [annotation][in] */ 
            _In_  long ruleFlags);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Parameters )( 
            __RPC__in IFsrmRule * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  SAFEARRAY * *parameters);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Parameters )( 
            __RPC__in IFsrmRule * This,
            /* [annotation][in] */ 
            _In_  SAFEARRAY * parameters);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LastModified )( 
            __RPC__in IFsrmRule * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT *lastModified);
        
        END_INTERFACE
    } IFsrmRuleVtbl;

    interface IFsrmRule
    {
        CONST_VTBL struct IFsrmRuleVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFsrmRule_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFsrmRule_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFsrmRule_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFsrmRule_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFsrmRule_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFsrmRule_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFsrmRule_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IFsrmRule_get_Id(This,id)	\
    ( (This)->lpVtbl -> get_Id(This,id) ) 

#define IFsrmRule_get_Description(This,description)	\
    ( (This)->lpVtbl -> get_Description(This,description) ) 

#define IFsrmRule_put_Description(This,description)	\
    ( (This)->lpVtbl -> put_Description(This,description) ) 

#define IFsrmRule_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define IFsrmRule_Commit(This)	\
    ( (This)->lpVtbl -> Commit(This) ) 


#define IFsrmRule_get_Name(This,name)	\
    ( (This)->lpVtbl -> get_Name(This,name) ) 

#define IFsrmRule_put_Name(This,name)	\
    ( (This)->lpVtbl -> put_Name(This,name) ) 

#define IFsrmRule_get_RuleType(This,ruleType)	\
    ( (This)->lpVtbl -> get_RuleType(This,ruleType) ) 

#define IFsrmRule_get_ModuleDefinitionName(This,moduleDefinitionName)	\
    ( (This)->lpVtbl -> get_ModuleDefinitionName(This,moduleDefinitionName) ) 

#define IFsrmRule_put_ModuleDefinitionName(This,moduleDefinitionName)	\
    ( (This)->lpVtbl -> put_ModuleDefinitionName(This,moduleDefinitionName) ) 

#define IFsrmRule_get_NamespaceRoots(This,namespaceRoots)	\
    ( (This)->lpVtbl -> get_NamespaceRoots(This,namespaceRoots) ) 

#define IFsrmRule_put_NamespaceRoots(This,namespaceRoots)	\
    ( (This)->lpVtbl -> put_NamespaceRoots(This,namespaceRoots) ) 

#define IFsrmRule_get_RuleFlags(This,ruleFlags)	\
    ( (This)->lpVtbl -> get_RuleFlags(This,ruleFlags) ) 

#define IFsrmRule_put_RuleFlags(This,ruleFlags)	\
    ( (This)->lpVtbl -> put_RuleFlags(This,ruleFlags) ) 

#define IFsrmRule_get_Parameters(This,parameters)	\
    ( (This)->lpVtbl -> get_Parameters(This,parameters) ) 

#define IFsrmRule_put_Parameters(This,parameters)	\
    ( (This)->lpVtbl -> put_Parameters(This,parameters) ) 

#define IFsrmRule_get_LastModified(This,lastModified)	\
    ( (This)->lpVtbl -> get_LastModified(This,lastModified) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFsrmRule_INTERFACE_DEFINED__ */


#ifndef __IFsrmClassificationRule_INTERFACE_DEFINED__
#define __IFsrmClassificationRule_INTERFACE_DEFINED__

/* interface IFsrmClassificationRule */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IFsrmClassificationRule;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("afc052c2-5315-45ab-841b-c6db0e120148")
    IFsrmClassificationRule : public IFsrmRule
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ExecutionOption( 
            /* [annotation][retval][out] */ 
            _Out_retval_  FsrmExecutionOption *executionOption) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ExecutionOption( 
            /* [annotation][in] */ 
            _In_  FsrmExecutionOption executionOption) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PropertyAffected( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *property) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_PropertyAffected( 
            /* [annotation][in] */ 
            _In_  BSTR property) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Value( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *value) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Value( 
            /* [annotation][in] */ 
            _In_  BSTR value) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IFsrmClassificationRuleVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IFsrmClassificationRule * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IFsrmClassificationRule * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IFsrmClassificationRule * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IFsrmClassificationRule * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IFsrmClassificationRule * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IFsrmClassificationRule * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][size_is][in] */ 
            _In_reads_(cNames)  LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cNames)  DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFsrmClassificationRule * This,
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
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Id )( 
            __RPC__in IFsrmClassificationRule * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  FSRM_OBJECT_ID *id);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Description )( 
            __RPC__in IFsrmClassificationRule * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *description);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Description )( 
            __RPC__in IFsrmClassificationRule * This,
            /* [annotation][in] */ 
            _In_  BSTR description);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            __RPC__in IFsrmClassificationRule * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Commit )( 
            __RPC__in IFsrmClassificationRule * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            __RPC__in IFsrmClassificationRule * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *name);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            __RPC__in IFsrmClassificationRule * This,
            /* [annotation][in] */ 
            _In_  BSTR name);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RuleType )( 
            __RPC__in IFsrmClassificationRule * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  FsrmRuleType *ruleType);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ModuleDefinitionName )( 
            __RPC__in IFsrmClassificationRule * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *moduleDefinitionName);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ModuleDefinitionName )( 
            __RPC__in IFsrmClassificationRule * This,
            /* [annotation][in] */ 
            _In_  BSTR moduleDefinitionName);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NamespaceRoots )( 
            __RPC__in IFsrmClassificationRule * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  SAFEARRAY * *namespaceRoots);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_NamespaceRoots )( 
            __RPC__in IFsrmClassificationRule * This,
            /* [annotation][in] */ 
            _In_  SAFEARRAY * namespaceRoots);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RuleFlags )( 
            __RPC__in IFsrmClassificationRule * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *ruleFlags);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RuleFlags )( 
            __RPC__in IFsrmClassificationRule * This,
            /* [annotation][in] */ 
            _In_  long ruleFlags);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Parameters )( 
            __RPC__in IFsrmClassificationRule * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  SAFEARRAY * *parameters);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Parameters )( 
            __RPC__in IFsrmClassificationRule * This,
            /* [annotation][in] */ 
            _In_  SAFEARRAY * parameters);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LastModified )( 
            __RPC__in IFsrmClassificationRule * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT *lastModified);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ExecutionOption )( 
            __RPC__in IFsrmClassificationRule * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  FsrmExecutionOption *executionOption);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ExecutionOption )( 
            __RPC__in IFsrmClassificationRule * This,
            /* [annotation][in] */ 
            _In_  FsrmExecutionOption executionOption);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PropertyAffected )( 
            __RPC__in IFsrmClassificationRule * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *property);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PropertyAffected )( 
            __RPC__in IFsrmClassificationRule * This,
            /* [annotation][in] */ 
            _In_  BSTR property);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Value )( 
            __RPC__in IFsrmClassificationRule * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *value);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Value )( 
            __RPC__in IFsrmClassificationRule * This,
            /* [annotation][in] */ 
            _In_  BSTR value);
        
        END_INTERFACE
    } IFsrmClassificationRuleVtbl;

    interface IFsrmClassificationRule
    {
        CONST_VTBL struct IFsrmClassificationRuleVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFsrmClassificationRule_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFsrmClassificationRule_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFsrmClassificationRule_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFsrmClassificationRule_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFsrmClassificationRule_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFsrmClassificationRule_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFsrmClassificationRule_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IFsrmClassificationRule_get_Id(This,id)	\
    ( (This)->lpVtbl -> get_Id(This,id) ) 

#define IFsrmClassificationRule_get_Description(This,description)	\
    ( (This)->lpVtbl -> get_Description(This,description) ) 

#define IFsrmClassificationRule_put_Description(This,description)	\
    ( (This)->lpVtbl -> put_Description(This,description) ) 

#define IFsrmClassificationRule_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define IFsrmClassificationRule_Commit(This)	\
    ( (This)->lpVtbl -> Commit(This) ) 


#define IFsrmClassificationRule_get_Name(This,name)	\
    ( (This)->lpVtbl -> get_Name(This,name) ) 

#define IFsrmClassificationRule_put_Name(This,name)	\
    ( (This)->lpVtbl -> put_Name(This,name) ) 

#define IFsrmClassificationRule_get_RuleType(This,ruleType)	\
    ( (This)->lpVtbl -> get_RuleType(This,ruleType) ) 

#define IFsrmClassificationRule_get_ModuleDefinitionName(This,moduleDefinitionName)	\
    ( (This)->lpVtbl -> get_ModuleDefinitionName(This,moduleDefinitionName) ) 

#define IFsrmClassificationRule_put_ModuleDefinitionName(This,moduleDefinitionName)	\
    ( (This)->lpVtbl -> put_ModuleDefinitionName(This,moduleDefinitionName) ) 

#define IFsrmClassificationRule_get_NamespaceRoots(This,namespaceRoots)	\
    ( (This)->lpVtbl -> get_NamespaceRoots(This,namespaceRoots) ) 

#define IFsrmClassificationRule_put_NamespaceRoots(This,namespaceRoots)	\
    ( (This)->lpVtbl -> put_NamespaceRoots(This,namespaceRoots) ) 

#define IFsrmClassificationRule_get_RuleFlags(This,ruleFlags)	\
    ( (This)->lpVtbl -> get_RuleFlags(This,ruleFlags) ) 

#define IFsrmClassificationRule_put_RuleFlags(This,ruleFlags)	\
    ( (This)->lpVtbl -> put_RuleFlags(This,ruleFlags) ) 

#define IFsrmClassificationRule_get_Parameters(This,parameters)	\
    ( (This)->lpVtbl -> get_Parameters(This,parameters) ) 

#define IFsrmClassificationRule_put_Parameters(This,parameters)	\
    ( (This)->lpVtbl -> put_Parameters(This,parameters) ) 

#define IFsrmClassificationRule_get_LastModified(This,lastModified)	\
    ( (This)->lpVtbl -> get_LastModified(This,lastModified) ) 


#define IFsrmClassificationRule_get_ExecutionOption(This,executionOption)	\
    ( (This)->lpVtbl -> get_ExecutionOption(This,executionOption) ) 

#define IFsrmClassificationRule_put_ExecutionOption(This,executionOption)	\
    ( (This)->lpVtbl -> put_ExecutionOption(This,executionOption) ) 

#define IFsrmClassificationRule_get_PropertyAffected(This,property)	\
    ( (This)->lpVtbl -> get_PropertyAffected(This,property) ) 

#define IFsrmClassificationRule_put_PropertyAffected(This,property)	\
    ( (This)->lpVtbl -> put_PropertyAffected(This,property) ) 

#define IFsrmClassificationRule_get_Value(This,value)	\
    ( (This)->lpVtbl -> get_Value(This,value) ) 

#define IFsrmClassificationRule_put_Value(This,value)	\
    ( (This)->lpVtbl -> put_Value(This,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFsrmClassificationRule_INTERFACE_DEFINED__ */


#ifndef __IFsrmPipelineModuleDefinition_INTERFACE_DEFINED__
#define __IFsrmPipelineModuleDefinition_INTERFACE_DEFINED__

/* interface IFsrmPipelineModuleDefinition */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IFsrmPipelineModuleDefinition;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("515c1277-2c81-440e-8fcf-367921ed4f59")
    IFsrmPipelineModuleDefinition : public IFsrmObject
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ModuleClsid( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *moduleClsid) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ModuleClsid( 
            /* [annotation][in] */ 
            _In_  BSTR moduleClsid) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *name) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [annotation][in] */ 
            _In_  BSTR name) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Company( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *company) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Company( 
            /* [annotation][in] */ 
            _In_  BSTR company) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Version( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *version) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Version( 
            /* [annotation][in] */ 
            _In_  BSTR version) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ModuleType( 
            /* [annotation][retval][out] */ 
            _Out_retval_  FsrmPipelineModuleType *moduleType) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Enabled( 
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *enabled) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Enabled( 
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL enabled) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_NeedsFileContent( 
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *needsFileContent) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_NeedsFileContent( 
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL needsFileContent) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Account( 
            /* [annotation][retval][out] */ 
            _Out_retval_  FsrmAccountType *retrievalAccount) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Account( 
            /* [annotation][in] */ 
            _In_  FsrmAccountType retrievalAccount) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SupportedExtensions( 
            /* [annotation][retval][out] */ 
            _Out_retval_  SAFEARRAY * *supportedExtensions) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SupportedExtensions( 
            /* [annotation][in] */ 
            _In_  SAFEARRAY * supportedExtensions) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Parameters( 
            /* [annotation][retval][out] */ 
            _Out_retval_  SAFEARRAY * *parameters) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Parameters( 
            /* [annotation][in] */ 
            _In_  SAFEARRAY * parameters) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IFsrmPipelineModuleDefinitionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IFsrmPipelineModuleDefinition * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IFsrmPipelineModuleDefinition * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IFsrmPipelineModuleDefinition * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IFsrmPipelineModuleDefinition * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IFsrmPipelineModuleDefinition * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IFsrmPipelineModuleDefinition * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][size_is][in] */ 
            _In_reads_(cNames)  LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cNames)  DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFsrmPipelineModuleDefinition * This,
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
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Id )( 
            __RPC__in IFsrmPipelineModuleDefinition * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  FSRM_OBJECT_ID *id);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Description )( 
            __RPC__in IFsrmPipelineModuleDefinition * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *description);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Description )( 
            __RPC__in IFsrmPipelineModuleDefinition * This,
            /* [annotation][in] */ 
            _In_  BSTR description);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            __RPC__in IFsrmPipelineModuleDefinition * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Commit )( 
            __RPC__in IFsrmPipelineModuleDefinition * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ModuleClsid )( 
            __RPC__in IFsrmPipelineModuleDefinition * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *moduleClsid);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ModuleClsid )( 
            __RPC__in IFsrmPipelineModuleDefinition * This,
            /* [annotation][in] */ 
            _In_  BSTR moduleClsid);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            __RPC__in IFsrmPipelineModuleDefinition * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *name);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            __RPC__in IFsrmPipelineModuleDefinition * This,
            /* [annotation][in] */ 
            _In_  BSTR name);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Company )( 
            __RPC__in IFsrmPipelineModuleDefinition * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *company);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Company )( 
            __RPC__in IFsrmPipelineModuleDefinition * This,
            /* [annotation][in] */ 
            _In_  BSTR company);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Version )( 
            __RPC__in IFsrmPipelineModuleDefinition * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *version);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Version )( 
            __RPC__in IFsrmPipelineModuleDefinition * This,
            /* [annotation][in] */ 
            _In_  BSTR version);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ModuleType )( 
            __RPC__in IFsrmPipelineModuleDefinition * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  FsrmPipelineModuleType *moduleType);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Enabled )( 
            __RPC__in IFsrmPipelineModuleDefinition * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *enabled);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Enabled )( 
            __RPC__in IFsrmPipelineModuleDefinition * This,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL enabled);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NeedsFileContent )( 
            __RPC__in IFsrmPipelineModuleDefinition * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *needsFileContent);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_NeedsFileContent )( 
            __RPC__in IFsrmPipelineModuleDefinition * This,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL needsFileContent);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Account )( 
            __RPC__in IFsrmPipelineModuleDefinition * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  FsrmAccountType *retrievalAccount);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Account )( 
            __RPC__in IFsrmPipelineModuleDefinition * This,
            /* [annotation][in] */ 
            _In_  FsrmAccountType retrievalAccount);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SupportedExtensions )( 
            __RPC__in IFsrmPipelineModuleDefinition * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  SAFEARRAY * *supportedExtensions);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SupportedExtensions )( 
            __RPC__in IFsrmPipelineModuleDefinition * This,
            /* [annotation][in] */ 
            _In_  SAFEARRAY * supportedExtensions);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Parameters )( 
            __RPC__in IFsrmPipelineModuleDefinition * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  SAFEARRAY * *parameters);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Parameters )( 
            __RPC__in IFsrmPipelineModuleDefinition * This,
            /* [annotation][in] */ 
            _In_  SAFEARRAY * parameters);
        
        END_INTERFACE
    } IFsrmPipelineModuleDefinitionVtbl;

    interface IFsrmPipelineModuleDefinition
    {
        CONST_VTBL struct IFsrmPipelineModuleDefinitionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFsrmPipelineModuleDefinition_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFsrmPipelineModuleDefinition_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFsrmPipelineModuleDefinition_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFsrmPipelineModuleDefinition_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFsrmPipelineModuleDefinition_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFsrmPipelineModuleDefinition_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFsrmPipelineModuleDefinition_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IFsrmPipelineModuleDefinition_get_Id(This,id)	\
    ( (This)->lpVtbl -> get_Id(This,id) ) 

#define IFsrmPipelineModuleDefinition_get_Description(This,description)	\
    ( (This)->lpVtbl -> get_Description(This,description) ) 

#define IFsrmPipelineModuleDefinition_put_Description(This,description)	\
    ( (This)->lpVtbl -> put_Description(This,description) ) 

#define IFsrmPipelineModuleDefinition_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define IFsrmPipelineModuleDefinition_Commit(This)	\
    ( (This)->lpVtbl -> Commit(This) ) 


#define IFsrmPipelineModuleDefinition_get_ModuleClsid(This,moduleClsid)	\
    ( (This)->lpVtbl -> get_ModuleClsid(This,moduleClsid) ) 

#define IFsrmPipelineModuleDefinition_put_ModuleClsid(This,moduleClsid)	\
    ( (This)->lpVtbl -> put_ModuleClsid(This,moduleClsid) ) 

#define IFsrmPipelineModuleDefinition_get_Name(This,name)	\
    ( (This)->lpVtbl -> get_Name(This,name) ) 

#define IFsrmPipelineModuleDefinition_put_Name(This,name)	\
    ( (This)->lpVtbl -> put_Name(This,name) ) 

#define IFsrmPipelineModuleDefinition_get_Company(This,company)	\
    ( (This)->lpVtbl -> get_Company(This,company) ) 

#define IFsrmPipelineModuleDefinition_put_Company(This,company)	\
    ( (This)->lpVtbl -> put_Company(This,company) ) 

#define IFsrmPipelineModuleDefinition_get_Version(This,version)	\
    ( (This)->lpVtbl -> get_Version(This,version) ) 

#define IFsrmPipelineModuleDefinition_put_Version(This,version)	\
    ( (This)->lpVtbl -> put_Version(This,version) ) 

#define IFsrmPipelineModuleDefinition_get_ModuleType(This,moduleType)	\
    ( (This)->lpVtbl -> get_ModuleType(This,moduleType) ) 

#define IFsrmPipelineModuleDefinition_get_Enabled(This,enabled)	\
    ( (This)->lpVtbl -> get_Enabled(This,enabled) ) 

#define IFsrmPipelineModuleDefinition_put_Enabled(This,enabled)	\
    ( (This)->lpVtbl -> put_Enabled(This,enabled) ) 

#define IFsrmPipelineModuleDefinition_get_NeedsFileContent(This,needsFileContent)	\
    ( (This)->lpVtbl -> get_NeedsFileContent(This,needsFileContent) ) 

#define IFsrmPipelineModuleDefinition_put_NeedsFileContent(This,needsFileContent)	\
    ( (This)->lpVtbl -> put_NeedsFileContent(This,needsFileContent) ) 

#define IFsrmPipelineModuleDefinition_get_Account(This,retrievalAccount)	\
    ( (This)->lpVtbl -> get_Account(This,retrievalAccount) ) 

#define IFsrmPipelineModuleDefinition_put_Account(This,retrievalAccount)	\
    ( (This)->lpVtbl -> put_Account(This,retrievalAccount) ) 

#define IFsrmPipelineModuleDefinition_get_SupportedExtensions(This,supportedExtensions)	\
    ( (This)->lpVtbl -> get_SupportedExtensions(This,supportedExtensions) ) 

#define IFsrmPipelineModuleDefinition_put_SupportedExtensions(This,supportedExtensions)	\
    ( (This)->lpVtbl -> put_SupportedExtensions(This,supportedExtensions) ) 

#define IFsrmPipelineModuleDefinition_get_Parameters(This,parameters)	\
    ( (This)->lpVtbl -> get_Parameters(This,parameters) ) 

#define IFsrmPipelineModuleDefinition_put_Parameters(This,parameters)	\
    ( (This)->lpVtbl -> put_Parameters(This,parameters) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFsrmPipelineModuleDefinition_INTERFACE_DEFINED__ */


#ifndef __IFsrmClassifierModuleDefinition_INTERFACE_DEFINED__
#define __IFsrmClassifierModuleDefinition_INTERFACE_DEFINED__

/* interface IFsrmClassifierModuleDefinition */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IFsrmClassifierModuleDefinition;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("bb36ea26-6318-4b8c-8592-f72dd602e7a5")
    IFsrmClassifierModuleDefinition : public IFsrmPipelineModuleDefinition
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PropertiesAffected( 
            /* [annotation][retval][out] */ 
            _Out_retval_  SAFEARRAY * *propertiesAffected) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_PropertiesAffected( 
            /* [annotation][in] */ 
            _In_  SAFEARRAY * propertiesAffected) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PropertiesUsed( 
            /* [annotation][retval][out] */ 
            _Out_retval_  SAFEARRAY * *propertiesUsed) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_PropertiesUsed( 
            /* [annotation][in] */ 
            _In_  SAFEARRAY * propertiesUsed) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_NeedsExplicitValue( 
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *needsExplicitValue) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_NeedsExplicitValue( 
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL needsExplicitValue) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IFsrmClassifierModuleDefinitionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IFsrmClassifierModuleDefinition * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IFsrmClassifierModuleDefinition * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IFsrmClassifierModuleDefinition * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IFsrmClassifierModuleDefinition * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IFsrmClassifierModuleDefinition * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IFsrmClassifierModuleDefinition * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][size_is][in] */ 
            _In_reads_(cNames)  LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cNames)  DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFsrmClassifierModuleDefinition * This,
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
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Id )( 
            __RPC__in IFsrmClassifierModuleDefinition * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  FSRM_OBJECT_ID *id);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Description )( 
            __RPC__in IFsrmClassifierModuleDefinition * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *description);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Description )( 
            __RPC__in IFsrmClassifierModuleDefinition * This,
            /* [annotation][in] */ 
            _In_  BSTR description);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            __RPC__in IFsrmClassifierModuleDefinition * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Commit )( 
            __RPC__in IFsrmClassifierModuleDefinition * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ModuleClsid )( 
            __RPC__in IFsrmClassifierModuleDefinition * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *moduleClsid);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ModuleClsid )( 
            __RPC__in IFsrmClassifierModuleDefinition * This,
            /* [annotation][in] */ 
            _In_  BSTR moduleClsid);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            __RPC__in IFsrmClassifierModuleDefinition * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *name);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            __RPC__in IFsrmClassifierModuleDefinition * This,
            /* [annotation][in] */ 
            _In_  BSTR name);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Company )( 
            __RPC__in IFsrmClassifierModuleDefinition * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *company);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Company )( 
            __RPC__in IFsrmClassifierModuleDefinition * This,
            /* [annotation][in] */ 
            _In_  BSTR company);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Version )( 
            __RPC__in IFsrmClassifierModuleDefinition * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *version);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Version )( 
            __RPC__in IFsrmClassifierModuleDefinition * This,
            /* [annotation][in] */ 
            _In_  BSTR version);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ModuleType )( 
            __RPC__in IFsrmClassifierModuleDefinition * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  FsrmPipelineModuleType *moduleType);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Enabled )( 
            __RPC__in IFsrmClassifierModuleDefinition * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *enabled);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Enabled )( 
            __RPC__in IFsrmClassifierModuleDefinition * This,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL enabled);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NeedsFileContent )( 
            __RPC__in IFsrmClassifierModuleDefinition * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *needsFileContent);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_NeedsFileContent )( 
            __RPC__in IFsrmClassifierModuleDefinition * This,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL needsFileContent);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Account )( 
            __RPC__in IFsrmClassifierModuleDefinition * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  FsrmAccountType *retrievalAccount);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Account )( 
            __RPC__in IFsrmClassifierModuleDefinition * This,
            /* [annotation][in] */ 
            _In_  FsrmAccountType retrievalAccount);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SupportedExtensions )( 
            __RPC__in IFsrmClassifierModuleDefinition * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  SAFEARRAY * *supportedExtensions);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SupportedExtensions )( 
            __RPC__in IFsrmClassifierModuleDefinition * This,
            /* [annotation][in] */ 
            _In_  SAFEARRAY * supportedExtensions);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Parameters )( 
            __RPC__in IFsrmClassifierModuleDefinition * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  SAFEARRAY * *parameters);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Parameters )( 
            __RPC__in IFsrmClassifierModuleDefinition * This,
            /* [annotation][in] */ 
            _In_  SAFEARRAY * parameters);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PropertiesAffected )( 
            __RPC__in IFsrmClassifierModuleDefinition * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  SAFEARRAY * *propertiesAffected);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PropertiesAffected )( 
            __RPC__in IFsrmClassifierModuleDefinition * This,
            /* [annotation][in] */ 
            _In_  SAFEARRAY * propertiesAffected);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PropertiesUsed )( 
            __RPC__in IFsrmClassifierModuleDefinition * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  SAFEARRAY * *propertiesUsed);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PropertiesUsed )( 
            __RPC__in IFsrmClassifierModuleDefinition * This,
            /* [annotation][in] */ 
            _In_  SAFEARRAY * propertiesUsed);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NeedsExplicitValue )( 
            __RPC__in IFsrmClassifierModuleDefinition * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *needsExplicitValue);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_NeedsExplicitValue )( 
            __RPC__in IFsrmClassifierModuleDefinition * This,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL needsExplicitValue);
        
        END_INTERFACE
    } IFsrmClassifierModuleDefinitionVtbl;

    interface IFsrmClassifierModuleDefinition
    {
        CONST_VTBL struct IFsrmClassifierModuleDefinitionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFsrmClassifierModuleDefinition_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFsrmClassifierModuleDefinition_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFsrmClassifierModuleDefinition_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFsrmClassifierModuleDefinition_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFsrmClassifierModuleDefinition_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFsrmClassifierModuleDefinition_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFsrmClassifierModuleDefinition_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IFsrmClassifierModuleDefinition_get_Id(This,id)	\
    ( (This)->lpVtbl -> get_Id(This,id) ) 

#define IFsrmClassifierModuleDefinition_get_Description(This,description)	\
    ( (This)->lpVtbl -> get_Description(This,description) ) 

#define IFsrmClassifierModuleDefinition_put_Description(This,description)	\
    ( (This)->lpVtbl -> put_Description(This,description) ) 

#define IFsrmClassifierModuleDefinition_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define IFsrmClassifierModuleDefinition_Commit(This)	\
    ( (This)->lpVtbl -> Commit(This) ) 


#define IFsrmClassifierModuleDefinition_get_ModuleClsid(This,moduleClsid)	\
    ( (This)->lpVtbl -> get_ModuleClsid(This,moduleClsid) ) 

#define IFsrmClassifierModuleDefinition_put_ModuleClsid(This,moduleClsid)	\
    ( (This)->lpVtbl -> put_ModuleClsid(This,moduleClsid) ) 

#define IFsrmClassifierModuleDefinition_get_Name(This,name)	\
    ( (This)->lpVtbl -> get_Name(This,name) ) 

#define IFsrmClassifierModuleDefinition_put_Name(This,name)	\
    ( (This)->lpVtbl -> put_Name(This,name) ) 

#define IFsrmClassifierModuleDefinition_get_Company(This,company)	\
    ( (This)->lpVtbl -> get_Company(This,company) ) 

#define IFsrmClassifierModuleDefinition_put_Company(This,company)	\
    ( (This)->lpVtbl -> put_Company(This,company) ) 

#define IFsrmClassifierModuleDefinition_get_Version(This,version)	\
    ( (This)->lpVtbl -> get_Version(This,version) ) 

#define IFsrmClassifierModuleDefinition_put_Version(This,version)	\
    ( (This)->lpVtbl -> put_Version(This,version) ) 

#define IFsrmClassifierModuleDefinition_get_ModuleType(This,moduleType)	\
    ( (This)->lpVtbl -> get_ModuleType(This,moduleType) ) 

#define IFsrmClassifierModuleDefinition_get_Enabled(This,enabled)	\
    ( (This)->lpVtbl -> get_Enabled(This,enabled) ) 

#define IFsrmClassifierModuleDefinition_put_Enabled(This,enabled)	\
    ( (This)->lpVtbl -> put_Enabled(This,enabled) ) 

#define IFsrmClassifierModuleDefinition_get_NeedsFileContent(This,needsFileContent)	\
    ( (This)->lpVtbl -> get_NeedsFileContent(This,needsFileContent) ) 

#define IFsrmClassifierModuleDefinition_put_NeedsFileContent(This,needsFileContent)	\
    ( (This)->lpVtbl -> put_NeedsFileContent(This,needsFileContent) ) 

#define IFsrmClassifierModuleDefinition_get_Account(This,retrievalAccount)	\
    ( (This)->lpVtbl -> get_Account(This,retrievalAccount) ) 

#define IFsrmClassifierModuleDefinition_put_Account(This,retrievalAccount)	\
    ( (This)->lpVtbl -> put_Account(This,retrievalAccount) ) 

#define IFsrmClassifierModuleDefinition_get_SupportedExtensions(This,supportedExtensions)	\
    ( (This)->lpVtbl -> get_SupportedExtensions(This,supportedExtensions) ) 

#define IFsrmClassifierModuleDefinition_put_SupportedExtensions(This,supportedExtensions)	\
    ( (This)->lpVtbl -> put_SupportedExtensions(This,supportedExtensions) ) 

#define IFsrmClassifierModuleDefinition_get_Parameters(This,parameters)	\
    ( (This)->lpVtbl -> get_Parameters(This,parameters) ) 

#define IFsrmClassifierModuleDefinition_put_Parameters(This,parameters)	\
    ( (This)->lpVtbl -> put_Parameters(This,parameters) ) 


#define IFsrmClassifierModuleDefinition_get_PropertiesAffected(This,propertiesAffected)	\
    ( (This)->lpVtbl -> get_PropertiesAffected(This,propertiesAffected) ) 

#define IFsrmClassifierModuleDefinition_put_PropertiesAffected(This,propertiesAffected)	\
    ( (This)->lpVtbl -> put_PropertiesAffected(This,propertiesAffected) ) 

#define IFsrmClassifierModuleDefinition_get_PropertiesUsed(This,propertiesUsed)	\
    ( (This)->lpVtbl -> get_PropertiesUsed(This,propertiesUsed) ) 

#define IFsrmClassifierModuleDefinition_put_PropertiesUsed(This,propertiesUsed)	\
    ( (This)->lpVtbl -> put_PropertiesUsed(This,propertiesUsed) ) 

#define IFsrmClassifierModuleDefinition_get_NeedsExplicitValue(This,needsExplicitValue)	\
    ( (This)->lpVtbl -> get_NeedsExplicitValue(This,needsExplicitValue) ) 

#define IFsrmClassifierModuleDefinition_put_NeedsExplicitValue(This,needsExplicitValue)	\
    ( (This)->lpVtbl -> put_NeedsExplicitValue(This,needsExplicitValue) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFsrmClassifierModuleDefinition_INTERFACE_DEFINED__ */


#ifndef __IFsrmStorageModuleDefinition_INTERFACE_DEFINED__
#define __IFsrmStorageModuleDefinition_INTERFACE_DEFINED__

/* interface IFsrmStorageModuleDefinition */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IFsrmStorageModuleDefinition;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("15a81350-497d-4aba-80e9-d4dbcc5521fe")
    IFsrmStorageModuleDefinition : public IFsrmPipelineModuleDefinition
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Capabilities( 
            /* [annotation][retval][out] */ 
            _Out_retval_  FsrmStorageModuleCaps *capabilities) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Capabilities( 
            /* [annotation][in] */ 
            _In_  FsrmStorageModuleCaps capabilities) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StorageType( 
            /* [annotation][retval][out] */ 
            _Out_retval_  FsrmStorageModuleType *storageType) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_StorageType( 
            /* [annotation][in] */ 
            _In_  FsrmStorageModuleType storageType) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UpdatesFileContent( 
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *updatesFileContent) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_UpdatesFileContent( 
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL updatesFileContent) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IFsrmStorageModuleDefinitionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IFsrmStorageModuleDefinition * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IFsrmStorageModuleDefinition * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IFsrmStorageModuleDefinition * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IFsrmStorageModuleDefinition * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IFsrmStorageModuleDefinition * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IFsrmStorageModuleDefinition * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][size_is][in] */ 
            _In_reads_(cNames)  LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cNames)  DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFsrmStorageModuleDefinition * This,
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
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Id )( 
            __RPC__in IFsrmStorageModuleDefinition * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  FSRM_OBJECT_ID *id);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Description )( 
            __RPC__in IFsrmStorageModuleDefinition * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *description);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Description )( 
            __RPC__in IFsrmStorageModuleDefinition * This,
            /* [annotation][in] */ 
            _In_  BSTR description);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            __RPC__in IFsrmStorageModuleDefinition * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Commit )( 
            __RPC__in IFsrmStorageModuleDefinition * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ModuleClsid )( 
            __RPC__in IFsrmStorageModuleDefinition * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *moduleClsid);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ModuleClsid )( 
            __RPC__in IFsrmStorageModuleDefinition * This,
            /* [annotation][in] */ 
            _In_  BSTR moduleClsid);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            __RPC__in IFsrmStorageModuleDefinition * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *name);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            __RPC__in IFsrmStorageModuleDefinition * This,
            /* [annotation][in] */ 
            _In_  BSTR name);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Company )( 
            __RPC__in IFsrmStorageModuleDefinition * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *company);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Company )( 
            __RPC__in IFsrmStorageModuleDefinition * This,
            /* [annotation][in] */ 
            _In_  BSTR company);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Version )( 
            __RPC__in IFsrmStorageModuleDefinition * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *version);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Version )( 
            __RPC__in IFsrmStorageModuleDefinition * This,
            /* [annotation][in] */ 
            _In_  BSTR version);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ModuleType )( 
            __RPC__in IFsrmStorageModuleDefinition * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  FsrmPipelineModuleType *moduleType);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Enabled )( 
            __RPC__in IFsrmStorageModuleDefinition * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *enabled);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Enabled )( 
            __RPC__in IFsrmStorageModuleDefinition * This,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL enabled);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NeedsFileContent )( 
            __RPC__in IFsrmStorageModuleDefinition * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *needsFileContent);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_NeedsFileContent )( 
            __RPC__in IFsrmStorageModuleDefinition * This,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL needsFileContent);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Account )( 
            __RPC__in IFsrmStorageModuleDefinition * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  FsrmAccountType *retrievalAccount);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Account )( 
            __RPC__in IFsrmStorageModuleDefinition * This,
            /* [annotation][in] */ 
            _In_  FsrmAccountType retrievalAccount);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SupportedExtensions )( 
            __RPC__in IFsrmStorageModuleDefinition * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  SAFEARRAY * *supportedExtensions);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SupportedExtensions )( 
            __RPC__in IFsrmStorageModuleDefinition * This,
            /* [annotation][in] */ 
            _In_  SAFEARRAY * supportedExtensions);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Parameters )( 
            __RPC__in IFsrmStorageModuleDefinition * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  SAFEARRAY * *parameters);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Parameters )( 
            __RPC__in IFsrmStorageModuleDefinition * This,
            /* [annotation][in] */ 
            _In_  SAFEARRAY * parameters);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Capabilities )( 
            __RPC__in IFsrmStorageModuleDefinition * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  FsrmStorageModuleCaps *capabilities);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Capabilities )( 
            __RPC__in IFsrmStorageModuleDefinition * This,
            /* [annotation][in] */ 
            _In_  FsrmStorageModuleCaps capabilities);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StorageType )( 
            __RPC__in IFsrmStorageModuleDefinition * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  FsrmStorageModuleType *storageType);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_StorageType )( 
            __RPC__in IFsrmStorageModuleDefinition * This,
            /* [annotation][in] */ 
            _In_  FsrmStorageModuleType storageType);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UpdatesFileContent )( 
            __RPC__in IFsrmStorageModuleDefinition * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *updatesFileContent);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UpdatesFileContent )( 
            __RPC__in IFsrmStorageModuleDefinition * This,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL updatesFileContent);
        
        END_INTERFACE
    } IFsrmStorageModuleDefinitionVtbl;

    interface IFsrmStorageModuleDefinition
    {
        CONST_VTBL struct IFsrmStorageModuleDefinitionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFsrmStorageModuleDefinition_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFsrmStorageModuleDefinition_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFsrmStorageModuleDefinition_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFsrmStorageModuleDefinition_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFsrmStorageModuleDefinition_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFsrmStorageModuleDefinition_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFsrmStorageModuleDefinition_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IFsrmStorageModuleDefinition_get_Id(This,id)	\
    ( (This)->lpVtbl -> get_Id(This,id) ) 

#define IFsrmStorageModuleDefinition_get_Description(This,description)	\
    ( (This)->lpVtbl -> get_Description(This,description) ) 

#define IFsrmStorageModuleDefinition_put_Description(This,description)	\
    ( (This)->lpVtbl -> put_Description(This,description) ) 

#define IFsrmStorageModuleDefinition_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define IFsrmStorageModuleDefinition_Commit(This)	\
    ( (This)->lpVtbl -> Commit(This) ) 


#define IFsrmStorageModuleDefinition_get_ModuleClsid(This,moduleClsid)	\
    ( (This)->lpVtbl -> get_ModuleClsid(This,moduleClsid) ) 

#define IFsrmStorageModuleDefinition_put_ModuleClsid(This,moduleClsid)	\
    ( (This)->lpVtbl -> put_ModuleClsid(This,moduleClsid) ) 

#define IFsrmStorageModuleDefinition_get_Name(This,name)	\
    ( (This)->lpVtbl -> get_Name(This,name) ) 

#define IFsrmStorageModuleDefinition_put_Name(This,name)	\
    ( (This)->lpVtbl -> put_Name(This,name) ) 

#define IFsrmStorageModuleDefinition_get_Company(This,company)	\
    ( (This)->lpVtbl -> get_Company(This,company) ) 

#define IFsrmStorageModuleDefinition_put_Company(This,company)	\
    ( (This)->lpVtbl -> put_Company(This,company) ) 

#define IFsrmStorageModuleDefinition_get_Version(This,version)	\
    ( (This)->lpVtbl -> get_Version(This,version) ) 

#define IFsrmStorageModuleDefinition_put_Version(This,version)	\
    ( (This)->lpVtbl -> put_Version(This,version) ) 

#define IFsrmStorageModuleDefinition_get_ModuleType(This,moduleType)	\
    ( (This)->lpVtbl -> get_ModuleType(This,moduleType) ) 

#define IFsrmStorageModuleDefinition_get_Enabled(This,enabled)	\
    ( (This)->lpVtbl -> get_Enabled(This,enabled) ) 

#define IFsrmStorageModuleDefinition_put_Enabled(This,enabled)	\
    ( (This)->lpVtbl -> put_Enabled(This,enabled) ) 

#define IFsrmStorageModuleDefinition_get_NeedsFileContent(This,needsFileContent)	\
    ( (This)->lpVtbl -> get_NeedsFileContent(This,needsFileContent) ) 

#define IFsrmStorageModuleDefinition_put_NeedsFileContent(This,needsFileContent)	\
    ( (This)->lpVtbl -> put_NeedsFileContent(This,needsFileContent) ) 

#define IFsrmStorageModuleDefinition_get_Account(This,retrievalAccount)	\
    ( (This)->lpVtbl -> get_Account(This,retrievalAccount) ) 

#define IFsrmStorageModuleDefinition_put_Account(This,retrievalAccount)	\
    ( (This)->lpVtbl -> put_Account(This,retrievalAccount) ) 

#define IFsrmStorageModuleDefinition_get_SupportedExtensions(This,supportedExtensions)	\
    ( (This)->lpVtbl -> get_SupportedExtensions(This,supportedExtensions) ) 

#define IFsrmStorageModuleDefinition_put_SupportedExtensions(This,supportedExtensions)	\
    ( (This)->lpVtbl -> put_SupportedExtensions(This,supportedExtensions) ) 

#define IFsrmStorageModuleDefinition_get_Parameters(This,parameters)	\
    ( (This)->lpVtbl -> get_Parameters(This,parameters) ) 

#define IFsrmStorageModuleDefinition_put_Parameters(This,parameters)	\
    ( (This)->lpVtbl -> put_Parameters(This,parameters) ) 


#define IFsrmStorageModuleDefinition_get_Capabilities(This,capabilities)	\
    ( (This)->lpVtbl -> get_Capabilities(This,capabilities) ) 

#define IFsrmStorageModuleDefinition_put_Capabilities(This,capabilities)	\
    ( (This)->lpVtbl -> put_Capabilities(This,capabilities) ) 

#define IFsrmStorageModuleDefinition_get_StorageType(This,storageType)	\
    ( (This)->lpVtbl -> get_StorageType(This,storageType) ) 

#define IFsrmStorageModuleDefinition_put_StorageType(This,storageType)	\
    ( (This)->lpVtbl -> put_StorageType(This,storageType) ) 

#define IFsrmStorageModuleDefinition_get_UpdatesFileContent(This,updatesFileContent)	\
    ( (This)->lpVtbl -> get_UpdatesFileContent(This,updatesFileContent) ) 

#define IFsrmStorageModuleDefinition_put_UpdatesFileContent(This,updatesFileContent)	\
    ( (This)->lpVtbl -> put_UpdatesFileContent(This,updatesFileContent) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFsrmStorageModuleDefinition_INTERFACE_DEFINED__ */


#ifndef __IFsrmClassificationManager_INTERFACE_DEFINED__
#define __IFsrmClassificationManager_INTERFACE_DEFINED__

/* interface IFsrmClassificationManager */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IFsrmClassificationManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("d2dc89da-ee91-48a0-85d8-cc72a56f7d04")
    IFsrmClassificationManager : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ClassificationReportFormats( 
            /* [annotation][retval][out] */ 
            _Out_retval_  SAFEARRAY * *formats) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ClassificationReportFormats( 
            /* [annotation][in] */ 
            _In_  SAFEARRAY * formats) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Logging( 
            /* [annotation][retval][out] */ 
            _Out_retval_  long *logging) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Logging( 
            /* [annotation][in] */ 
            _In_  long logging) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ClassificationReportMailTo( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *mailTo) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ClassificationReportMailTo( 
            /* [annotation][in] */ 
            _In_  BSTR mailTo) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ClassificationReportEnabled( 
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *reportEnabled) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ClassificationReportEnabled( 
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL reportEnabled) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ClassificationLastReportPathWithoutExtension( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *lastReportPath) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ClassificationLastError( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *lastError) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ClassificationRunningStatus( 
            /* [annotation][retval][out] */ 
            _Out_retval_  FsrmReportRunningStatus *runningStatus) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EnumPropertyDefinitions( 
            /* [annotation][defaultvalue][in] */ 
            _In_  FsrmEnumOptions options,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmCollection **propertyDefinitions) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreatePropertyDefinition( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmPropertyDefinition **propertyDefinition) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetPropertyDefinition( 
            /* [annotation][in] */ 
            _In_  BSTR propertyName,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmPropertyDefinition **propertyDefinition) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EnumRules( 
            /* [annotation][in] */ 
            _In_  FsrmRuleType ruleType,
            /* [annotation][defaultvalue][in] */ 
            _In_  FsrmEnumOptions options,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmCollection **Rules) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateRule( 
            /* [annotation][in] */ 
            _In_  FsrmRuleType ruleType,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmRule **Rule) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetRule( 
            /* [annotation][in] */ 
            _In_  BSTR ruleName,
            /* [annotation][in] */ 
            _In_  FsrmRuleType ruleType,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmRule **Rule) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EnumModuleDefinitions( 
            /* [annotation][in] */ 
            _In_  FsrmPipelineModuleType moduleType,
            /* [annotation][defaultvalue][in] */ 
            _In_  FsrmEnumOptions options,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmCollection **moduleDefinitions) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateModuleDefinition( 
            /* [annotation][in] */ 
            _In_  FsrmPipelineModuleType moduleType,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmPipelineModuleDefinition **moduleDefinition) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetModuleDefinition( 
            /* [annotation][in] */ 
            _In_  BSTR moduleName,
            /* [annotation][in] */ 
            _In_  FsrmPipelineModuleType moduleType,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmPipelineModuleDefinition **moduleDefinition) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RunClassification( 
            /* [annotation][in] */ 
            _In_  FsrmReportGenerationContext context,
            /* [annotation][in] */ 
            _In_  BSTR reserved) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WaitForClassificationCompletion( 
            /* [annotation][in] */ 
            _In_  long waitSeconds,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *completed) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CancelClassification( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EnumFileProperties( 
            /* [annotation][in] */ 
            _In_  BSTR filePath,
            /* [annotation][defaultvalue][in] */ 
            _In_  FsrmGetFilePropertyOptions options,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmCollection **fileProperties) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetFileProperty( 
            /* [annotation][in] */ 
            _In_  BSTR filePath,
            /* [annotation][in] */ 
            _In_  BSTR propertyName,
            /* [annotation][defaultvalue][in] */ 
            _In_  FsrmGetFilePropertyOptions options,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmProperty **property) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetFileProperty( 
            /* [annotation][in] */ 
            _In_  BSTR filePath,
            /* [annotation][in] */ 
            _In_  BSTR propertyName,
            /* [annotation][in] */ 
            _In_  BSTR propertyValue) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ClearFileProperty( 
            /* [annotation][in] */ 
            _In_  BSTR filePath,
            /* [annotation][in] */ 
            _In_  BSTR property) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IFsrmClassificationManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IFsrmClassificationManager * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IFsrmClassificationManager * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IFsrmClassificationManager * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IFsrmClassificationManager * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IFsrmClassificationManager * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IFsrmClassificationManager * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][size_is][in] */ 
            _In_reads_(cNames)  LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cNames)  DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFsrmClassificationManager * This,
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
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClassificationReportFormats )( 
            __RPC__in IFsrmClassificationManager * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  SAFEARRAY * *formats);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ClassificationReportFormats )( 
            __RPC__in IFsrmClassificationManager * This,
            /* [annotation][in] */ 
            _In_  SAFEARRAY * formats);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Logging )( 
            __RPC__in IFsrmClassificationManager * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *logging);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Logging )( 
            __RPC__in IFsrmClassificationManager * This,
            /* [annotation][in] */ 
            _In_  long logging);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClassificationReportMailTo )( 
            __RPC__in IFsrmClassificationManager * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *mailTo);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ClassificationReportMailTo )( 
            __RPC__in IFsrmClassificationManager * This,
            /* [annotation][in] */ 
            _In_  BSTR mailTo);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClassificationReportEnabled )( 
            __RPC__in IFsrmClassificationManager * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *reportEnabled);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ClassificationReportEnabled )( 
            __RPC__in IFsrmClassificationManager * This,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL reportEnabled);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClassificationLastReportPathWithoutExtension )( 
            __RPC__in IFsrmClassificationManager * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *lastReportPath);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClassificationLastError )( 
            __RPC__in IFsrmClassificationManager * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *lastError);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClassificationRunningStatus )( 
            __RPC__in IFsrmClassificationManager * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  FsrmReportRunningStatus *runningStatus);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EnumPropertyDefinitions )( 
            __RPC__in IFsrmClassificationManager * This,
            /* [annotation][defaultvalue][in] */ 
            _In_  FsrmEnumOptions options,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmCollection **propertyDefinitions);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreatePropertyDefinition )( 
            __RPC__in IFsrmClassificationManager * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmPropertyDefinition **propertyDefinition);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetPropertyDefinition )( 
            __RPC__in IFsrmClassificationManager * This,
            /* [annotation][in] */ 
            _In_  BSTR propertyName,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmPropertyDefinition **propertyDefinition);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EnumRules )( 
            __RPC__in IFsrmClassificationManager * This,
            /* [annotation][in] */ 
            _In_  FsrmRuleType ruleType,
            /* [annotation][defaultvalue][in] */ 
            _In_  FsrmEnumOptions options,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmCollection **Rules);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateRule )( 
            __RPC__in IFsrmClassificationManager * This,
            /* [annotation][in] */ 
            _In_  FsrmRuleType ruleType,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmRule **Rule);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetRule )( 
            __RPC__in IFsrmClassificationManager * This,
            /* [annotation][in] */ 
            _In_  BSTR ruleName,
            /* [annotation][in] */ 
            _In_  FsrmRuleType ruleType,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmRule **Rule);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EnumModuleDefinitions )( 
            __RPC__in IFsrmClassificationManager * This,
            /* [annotation][in] */ 
            _In_  FsrmPipelineModuleType moduleType,
            /* [annotation][defaultvalue][in] */ 
            _In_  FsrmEnumOptions options,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmCollection **moduleDefinitions);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateModuleDefinition )( 
            __RPC__in IFsrmClassificationManager * This,
            /* [annotation][in] */ 
            _In_  FsrmPipelineModuleType moduleType,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmPipelineModuleDefinition **moduleDefinition);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetModuleDefinition )( 
            __RPC__in IFsrmClassificationManager * This,
            /* [annotation][in] */ 
            _In_  BSTR moduleName,
            /* [annotation][in] */ 
            _In_  FsrmPipelineModuleType moduleType,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmPipelineModuleDefinition **moduleDefinition);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RunClassification )( 
            __RPC__in IFsrmClassificationManager * This,
            /* [annotation][in] */ 
            _In_  FsrmReportGenerationContext context,
            /* [annotation][in] */ 
            _In_  BSTR reserved);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WaitForClassificationCompletion )( 
            __RPC__in IFsrmClassificationManager * This,
            /* [annotation][in] */ 
            _In_  long waitSeconds,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *completed);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CancelClassification )( 
            __RPC__in IFsrmClassificationManager * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EnumFileProperties )( 
            __RPC__in IFsrmClassificationManager * This,
            /* [annotation][in] */ 
            _In_  BSTR filePath,
            /* [annotation][defaultvalue][in] */ 
            _In_  FsrmGetFilePropertyOptions options,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmCollection **fileProperties);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetFileProperty )( 
            __RPC__in IFsrmClassificationManager * This,
            /* [annotation][in] */ 
            _In_  BSTR filePath,
            /* [annotation][in] */ 
            _In_  BSTR propertyName,
            /* [annotation][defaultvalue][in] */ 
            _In_  FsrmGetFilePropertyOptions options,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmProperty **property);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetFileProperty )( 
            __RPC__in IFsrmClassificationManager * This,
            /* [annotation][in] */ 
            _In_  BSTR filePath,
            /* [annotation][in] */ 
            _In_  BSTR propertyName,
            /* [annotation][in] */ 
            _In_  BSTR propertyValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ClearFileProperty )( 
            __RPC__in IFsrmClassificationManager * This,
            /* [annotation][in] */ 
            _In_  BSTR filePath,
            /* [annotation][in] */ 
            _In_  BSTR property);
        
        END_INTERFACE
    } IFsrmClassificationManagerVtbl;

    interface IFsrmClassificationManager
    {
        CONST_VTBL struct IFsrmClassificationManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFsrmClassificationManager_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFsrmClassificationManager_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFsrmClassificationManager_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFsrmClassificationManager_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFsrmClassificationManager_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFsrmClassificationManager_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFsrmClassificationManager_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IFsrmClassificationManager_get_ClassificationReportFormats(This,formats)	\
    ( (This)->lpVtbl -> get_ClassificationReportFormats(This,formats) ) 

#define IFsrmClassificationManager_put_ClassificationReportFormats(This,formats)	\
    ( (This)->lpVtbl -> put_ClassificationReportFormats(This,formats) ) 

#define IFsrmClassificationManager_get_Logging(This,logging)	\
    ( (This)->lpVtbl -> get_Logging(This,logging) ) 

#define IFsrmClassificationManager_put_Logging(This,logging)	\
    ( (This)->lpVtbl -> put_Logging(This,logging) ) 

#define IFsrmClassificationManager_get_ClassificationReportMailTo(This,mailTo)	\
    ( (This)->lpVtbl -> get_ClassificationReportMailTo(This,mailTo) ) 

#define IFsrmClassificationManager_put_ClassificationReportMailTo(This,mailTo)	\
    ( (This)->lpVtbl -> put_ClassificationReportMailTo(This,mailTo) ) 

#define IFsrmClassificationManager_get_ClassificationReportEnabled(This,reportEnabled)	\
    ( (This)->lpVtbl -> get_ClassificationReportEnabled(This,reportEnabled) ) 

#define IFsrmClassificationManager_put_ClassificationReportEnabled(This,reportEnabled)	\
    ( (This)->lpVtbl -> put_ClassificationReportEnabled(This,reportEnabled) ) 

#define IFsrmClassificationManager_get_ClassificationLastReportPathWithoutExtension(This,lastReportPath)	\
    ( (This)->lpVtbl -> get_ClassificationLastReportPathWithoutExtension(This,lastReportPath) ) 

#define IFsrmClassificationManager_get_ClassificationLastError(This,lastError)	\
    ( (This)->lpVtbl -> get_ClassificationLastError(This,lastError) ) 

#define IFsrmClassificationManager_get_ClassificationRunningStatus(This,runningStatus)	\
    ( (This)->lpVtbl -> get_ClassificationRunningStatus(This,runningStatus) ) 

#define IFsrmClassificationManager_EnumPropertyDefinitions(This,options,propertyDefinitions)	\
    ( (This)->lpVtbl -> EnumPropertyDefinitions(This,options,propertyDefinitions) ) 

#define IFsrmClassificationManager_CreatePropertyDefinition(This,propertyDefinition)	\
    ( (This)->lpVtbl -> CreatePropertyDefinition(This,propertyDefinition) ) 

#define IFsrmClassificationManager_GetPropertyDefinition(This,propertyName,propertyDefinition)	\
    ( (This)->lpVtbl -> GetPropertyDefinition(This,propertyName,propertyDefinition) ) 

#define IFsrmClassificationManager_EnumRules(This,ruleType,options,Rules)	\
    ( (This)->lpVtbl -> EnumRules(This,ruleType,options,Rules) ) 

#define IFsrmClassificationManager_CreateRule(This,ruleType,Rule)	\
    ( (This)->lpVtbl -> CreateRule(This,ruleType,Rule) ) 

#define IFsrmClassificationManager_GetRule(This,ruleName,ruleType,Rule)	\
    ( (This)->lpVtbl -> GetRule(This,ruleName,ruleType,Rule) ) 

#define IFsrmClassificationManager_EnumModuleDefinitions(This,moduleType,options,moduleDefinitions)	\
    ( (This)->lpVtbl -> EnumModuleDefinitions(This,moduleType,options,moduleDefinitions) ) 

#define IFsrmClassificationManager_CreateModuleDefinition(This,moduleType,moduleDefinition)	\
    ( (This)->lpVtbl -> CreateModuleDefinition(This,moduleType,moduleDefinition) ) 

#define IFsrmClassificationManager_GetModuleDefinition(This,moduleName,moduleType,moduleDefinition)	\
    ( (This)->lpVtbl -> GetModuleDefinition(This,moduleName,moduleType,moduleDefinition) ) 

#define IFsrmClassificationManager_RunClassification(This,context,reserved)	\
    ( (This)->lpVtbl -> RunClassification(This,context,reserved) ) 

#define IFsrmClassificationManager_WaitForClassificationCompletion(This,waitSeconds,completed)	\
    ( (This)->lpVtbl -> WaitForClassificationCompletion(This,waitSeconds,completed) ) 

#define IFsrmClassificationManager_CancelClassification(This)	\
    ( (This)->lpVtbl -> CancelClassification(This) ) 

#define IFsrmClassificationManager_EnumFileProperties(This,filePath,options,fileProperties)	\
    ( (This)->lpVtbl -> EnumFileProperties(This,filePath,options,fileProperties) ) 

#define IFsrmClassificationManager_GetFileProperty(This,filePath,propertyName,options,property)	\
    ( (This)->lpVtbl -> GetFileProperty(This,filePath,propertyName,options,property) ) 

#define IFsrmClassificationManager_SetFileProperty(This,filePath,propertyName,propertyValue)	\
    ( (This)->lpVtbl -> SetFileProperty(This,filePath,propertyName,propertyValue) ) 

#define IFsrmClassificationManager_ClearFileProperty(This,filePath,property)	\
    ( (This)->lpVtbl -> ClearFileProperty(This,filePath,property) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFsrmClassificationManager_INTERFACE_DEFINED__ */


#ifndef __IFsrmClassificationManager2_INTERFACE_DEFINED__
#define __IFsrmClassificationManager2_INTERFACE_DEFINED__

/* interface IFsrmClassificationManager2 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IFsrmClassificationManager2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0004c1c9-127e-4765-ba07-6a3147bca112")
    IFsrmClassificationManager2 : public IFsrmClassificationManager
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ClassifyFiles( 
            /* [annotation][in] */ 
            _In_  SAFEARRAY * filePaths,
            /* [annotation][unique][in] */ 
            _In_  SAFEARRAY * propertyNames,
            /* [annotation][unique][in] */ 
            _In_  SAFEARRAY * propertyValues,
            /* [annotation][defaultvalue][in] */ 
            _In_  FsrmGetFilePropertyOptions options = FsrmGetFilePropertyOptions_None) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IFsrmClassificationManager2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IFsrmClassificationManager2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IFsrmClassificationManager2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IFsrmClassificationManager2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IFsrmClassificationManager2 * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IFsrmClassificationManager2 * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IFsrmClassificationManager2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][size_is][in] */ 
            _In_reads_(cNames)  LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cNames)  DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFsrmClassificationManager2 * This,
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
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClassificationReportFormats )( 
            __RPC__in IFsrmClassificationManager2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  SAFEARRAY * *formats);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ClassificationReportFormats )( 
            __RPC__in IFsrmClassificationManager2 * This,
            /* [annotation][in] */ 
            _In_  SAFEARRAY * formats);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Logging )( 
            __RPC__in IFsrmClassificationManager2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *logging);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Logging )( 
            __RPC__in IFsrmClassificationManager2 * This,
            /* [annotation][in] */ 
            _In_  long logging);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClassificationReportMailTo )( 
            __RPC__in IFsrmClassificationManager2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *mailTo);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ClassificationReportMailTo )( 
            __RPC__in IFsrmClassificationManager2 * This,
            /* [annotation][in] */ 
            _In_  BSTR mailTo);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClassificationReportEnabled )( 
            __RPC__in IFsrmClassificationManager2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *reportEnabled);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ClassificationReportEnabled )( 
            __RPC__in IFsrmClassificationManager2 * This,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL reportEnabled);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClassificationLastReportPathWithoutExtension )( 
            __RPC__in IFsrmClassificationManager2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *lastReportPath);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClassificationLastError )( 
            __RPC__in IFsrmClassificationManager2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *lastError);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClassificationRunningStatus )( 
            __RPC__in IFsrmClassificationManager2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  FsrmReportRunningStatus *runningStatus);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EnumPropertyDefinitions )( 
            __RPC__in IFsrmClassificationManager2 * This,
            /* [annotation][defaultvalue][in] */ 
            _In_  FsrmEnumOptions options,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmCollection **propertyDefinitions);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreatePropertyDefinition )( 
            __RPC__in IFsrmClassificationManager2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmPropertyDefinition **propertyDefinition);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetPropertyDefinition )( 
            __RPC__in IFsrmClassificationManager2 * This,
            /* [annotation][in] */ 
            _In_  BSTR propertyName,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmPropertyDefinition **propertyDefinition);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EnumRules )( 
            __RPC__in IFsrmClassificationManager2 * This,
            /* [annotation][in] */ 
            _In_  FsrmRuleType ruleType,
            /* [annotation][defaultvalue][in] */ 
            _In_  FsrmEnumOptions options,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmCollection **Rules);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateRule )( 
            __RPC__in IFsrmClassificationManager2 * This,
            /* [annotation][in] */ 
            _In_  FsrmRuleType ruleType,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmRule **Rule);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetRule )( 
            __RPC__in IFsrmClassificationManager2 * This,
            /* [annotation][in] */ 
            _In_  BSTR ruleName,
            /* [annotation][in] */ 
            _In_  FsrmRuleType ruleType,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmRule **Rule);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EnumModuleDefinitions )( 
            __RPC__in IFsrmClassificationManager2 * This,
            /* [annotation][in] */ 
            _In_  FsrmPipelineModuleType moduleType,
            /* [annotation][defaultvalue][in] */ 
            _In_  FsrmEnumOptions options,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmCollection **moduleDefinitions);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateModuleDefinition )( 
            __RPC__in IFsrmClassificationManager2 * This,
            /* [annotation][in] */ 
            _In_  FsrmPipelineModuleType moduleType,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmPipelineModuleDefinition **moduleDefinition);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetModuleDefinition )( 
            __RPC__in IFsrmClassificationManager2 * This,
            /* [annotation][in] */ 
            _In_  BSTR moduleName,
            /* [annotation][in] */ 
            _In_  FsrmPipelineModuleType moduleType,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmPipelineModuleDefinition **moduleDefinition);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RunClassification )( 
            __RPC__in IFsrmClassificationManager2 * This,
            /* [annotation][in] */ 
            _In_  FsrmReportGenerationContext context,
            /* [annotation][in] */ 
            _In_  BSTR reserved);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WaitForClassificationCompletion )( 
            __RPC__in IFsrmClassificationManager2 * This,
            /* [annotation][in] */ 
            _In_  long waitSeconds,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *completed);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CancelClassification )( 
            __RPC__in IFsrmClassificationManager2 * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EnumFileProperties )( 
            __RPC__in IFsrmClassificationManager2 * This,
            /* [annotation][in] */ 
            _In_  BSTR filePath,
            /* [annotation][defaultvalue][in] */ 
            _In_  FsrmGetFilePropertyOptions options,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmCollection **fileProperties);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetFileProperty )( 
            __RPC__in IFsrmClassificationManager2 * This,
            /* [annotation][in] */ 
            _In_  BSTR filePath,
            /* [annotation][in] */ 
            _In_  BSTR propertyName,
            /* [annotation][defaultvalue][in] */ 
            _In_  FsrmGetFilePropertyOptions options,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmProperty **property);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetFileProperty )( 
            __RPC__in IFsrmClassificationManager2 * This,
            /* [annotation][in] */ 
            _In_  BSTR filePath,
            /* [annotation][in] */ 
            _In_  BSTR propertyName,
            /* [annotation][in] */ 
            _In_  BSTR propertyValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ClearFileProperty )( 
            __RPC__in IFsrmClassificationManager2 * This,
            /* [annotation][in] */ 
            _In_  BSTR filePath,
            /* [annotation][in] */ 
            _In_  BSTR property);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ClassifyFiles )( 
            __RPC__in IFsrmClassificationManager2 * This,
            /* [annotation][in] */ 
            _In_  SAFEARRAY * filePaths,
            /* [annotation][unique][in] */ 
            _In_  SAFEARRAY * propertyNames,
            /* [annotation][unique][in] */ 
            _In_  SAFEARRAY * propertyValues,
            /* [annotation][defaultvalue][in] */ 
            _In_  FsrmGetFilePropertyOptions options);
        
        END_INTERFACE
    } IFsrmClassificationManager2Vtbl;

    interface IFsrmClassificationManager2
    {
        CONST_VTBL struct IFsrmClassificationManager2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFsrmClassificationManager2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFsrmClassificationManager2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFsrmClassificationManager2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFsrmClassificationManager2_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFsrmClassificationManager2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFsrmClassificationManager2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFsrmClassificationManager2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IFsrmClassificationManager2_get_ClassificationReportFormats(This,formats)	\
    ( (This)->lpVtbl -> get_ClassificationReportFormats(This,formats) ) 

#define IFsrmClassificationManager2_put_ClassificationReportFormats(This,formats)	\
    ( (This)->lpVtbl -> put_ClassificationReportFormats(This,formats) ) 

#define IFsrmClassificationManager2_get_Logging(This,logging)	\
    ( (This)->lpVtbl -> get_Logging(This,logging) ) 

#define IFsrmClassificationManager2_put_Logging(This,logging)	\
    ( (This)->lpVtbl -> put_Logging(This,logging) ) 

#define IFsrmClassificationManager2_get_ClassificationReportMailTo(This,mailTo)	\
    ( (This)->lpVtbl -> get_ClassificationReportMailTo(This,mailTo) ) 

#define IFsrmClassificationManager2_put_ClassificationReportMailTo(This,mailTo)	\
    ( (This)->lpVtbl -> put_ClassificationReportMailTo(This,mailTo) ) 

#define IFsrmClassificationManager2_get_ClassificationReportEnabled(This,reportEnabled)	\
    ( (This)->lpVtbl -> get_ClassificationReportEnabled(This,reportEnabled) ) 

#define IFsrmClassificationManager2_put_ClassificationReportEnabled(This,reportEnabled)	\
    ( (This)->lpVtbl -> put_ClassificationReportEnabled(This,reportEnabled) ) 

#define IFsrmClassificationManager2_get_ClassificationLastReportPathWithoutExtension(This,lastReportPath)	\
    ( (This)->lpVtbl -> get_ClassificationLastReportPathWithoutExtension(This,lastReportPath) ) 

#define IFsrmClassificationManager2_get_ClassificationLastError(This,lastError)	\
    ( (This)->lpVtbl -> get_ClassificationLastError(This,lastError) ) 

#define IFsrmClassificationManager2_get_ClassificationRunningStatus(This,runningStatus)	\
    ( (This)->lpVtbl -> get_ClassificationRunningStatus(This,runningStatus) ) 

#define IFsrmClassificationManager2_EnumPropertyDefinitions(This,options,propertyDefinitions)	\
    ( (This)->lpVtbl -> EnumPropertyDefinitions(This,options,propertyDefinitions) ) 

#define IFsrmClassificationManager2_CreatePropertyDefinition(This,propertyDefinition)	\
    ( (This)->lpVtbl -> CreatePropertyDefinition(This,propertyDefinition) ) 

#define IFsrmClassificationManager2_GetPropertyDefinition(This,propertyName,propertyDefinition)	\
    ( (This)->lpVtbl -> GetPropertyDefinition(This,propertyName,propertyDefinition) ) 

#define IFsrmClassificationManager2_EnumRules(This,ruleType,options,Rules)	\
    ( (This)->lpVtbl -> EnumRules(This,ruleType,options,Rules) ) 

#define IFsrmClassificationManager2_CreateRule(This,ruleType,Rule)	\
    ( (This)->lpVtbl -> CreateRule(This,ruleType,Rule) ) 

#define IFsrmClassificationManager2_GetRule(This,ruleName,ruleType,Rule)	\
    ( (This)->lpVtbl -> GetRule(This,ruleName,ruleType,Rule) ) 

#define IFsrmClassificationManager2_EnumModuleDefinitions(This,moduleType,options,moduleDefinitions)	\
    ( (This)->lpVtbl -> EnumModuleDefinitions(This,moduleType,options,moduleDefinitions) ) 

#define IFsrmClassificationManager2_CreateModuleDefinition(This,moduleType,moduleDefinition)	\
    ( (This)->lpVtbl -> CreateModuleDefinition(This,moduleType,moduleDefinition) ) 

#define IFsrmClassificationManager2_GetModuleDefinition(This,moduleName,moduleType,moduleDefinition)	\
    ( (This)->lpVtbl -> GetModuleDefinition(This,moduleName,moduleType,moduleDefinition) ) 

#define IFsrmClassificationManager2_RunClassification(This,context,reserved)	\
    ( (This)->lpVtbl -> RunClassification(This,context,reserved) ) 

#define IFsrmClassificationManager2_WaitForClassificationCompletion(This,waitSeconds,completed)	\
    ( (This)->lpVtbl -> WaitForClassificationCompletion(This,waitSeconds,completed) ) 

#define IFsrmClassificationManager2_CancelClassification(This)	\
    ( (This)->lpVtbl -> CancelClassification(This) ) 

#define IFsrmClassificationManager2_EnumFileProperties(This,filePath,options,fileProperties)	\
    ( (This)->lpVtbl -> EnumFileProperties(This,filePath,options,fileProperties) ) 

#define IFsrmClassificationManager2_GetFileProperty(This,filePath,propertyName,options,property)	\
    ( (This)->lpVtbl -> GetFileProperty(This,filePath,propertyName,options,property) ) 

#define IFsrmClassificationManager2_SetFileProperty(This,filePath,propertyName,propertyValue)	\
    ( (This)->lpVtbl -> SetFileProperty(This,filePath,propertyName,propertyValue) ) 

#define IFsrmClassificationManager2_ClearFileProperty(This,filePath,property)	\
    ( (This)->lpVtbl -> ClearFileProperty(This,filePath,property) ) 


#define IFsrmClassificationManager2_ClassifyFiles(This,filePaths,propertyNames,propertyValues,options)	\
    ( (This)->lpVtbl -> ClassifyFiles(This,filePaths,propertyNames,propertyValues,options) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFsrmClassificationManager2_INTERFACE_DEFINED__ */


#ifndef __IFsrmPropertyBag_INTERFACE_DEFINED__
#define __IFsrmPropertyBag_INTERFACE_DEFINED__

/* interface IFsrmPropertyBag */
/* [unique][helpstring][dual][uuid][object] */ 

#define	MessageSizeLimit	( 4096 )


EXTERN_C const IID IID_IFsrmPropertyBag;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("774589d1-d300-4f7a-9a24-f7b766800250")
    IFsrmPropertyBag : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *name) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RelativePath( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *path) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_VolumeName( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *volumeName) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RelativeNamespaceRoot( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *relativeNamespaceRoot) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_VolumeIndex( 
            /* [annotation][retval][out] */ 
            _Out_retval_  unsigned long *volumeId) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FileId( 
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT *fileId) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ParentDirectoryId( 
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT *parentDirectoryId) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Size( 
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT *size) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SizeAllocated( 
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT *sizeAllocated) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CreationTime( 
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT *creationTime) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LastAccessTime( 
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT *lastAccessTime) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LastModificationTime( 
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT *lastModificationTime) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Attributes( 
            /* [annotation][retval][out] */ 
            _Out_retval_  unsigned long *attributes) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OwnerSid( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *ownerSid) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FilePropertyNames( 
            /* [annotation][retval][out] */ 
            _Out_retval_  SAFEARRAY * *filePropertyNames) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Messages( 
            /* [annotation][retval][out] */ 
            _Out_retval_  SAFEARRAY * *messages) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PropertyBagFlags( 
            /* [annotation][retval][out] */ 
            _Out_retval_  unsigned long *flags) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetFileProperty( 
            /* [annotation][in] */ 
            _In_  BSTR name,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmProperty **fileProperty) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetFileProperty( 
            /* [annotation][in] */ 
            _In_  BSTR name,
            /* [annotation][in] */ 
            _In_  BSTR value) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddMessage( 
            /* [annotation][in] */ 
            _In_  BSTR message) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetFileStreamInterface( 
            /* [annotation][in] */ 
            _In_  FsrmFileStreamingMode accessMode,
            /* [annotation][in] */ 
            _In_  FsrmFileStreamingInterfaceType interfaceType,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT *pStreamInterface) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IFsrmPropertyBagVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IFsrmPropertyBag * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IFsrmPropertyBag * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IFsrmPropertyBag * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IFsrmPropertyBag * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IFsrmPropertyBag * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IFsrmPropertyBag * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][size_is][in] */ 
            _In_reads_(cNames)  LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cNames)  DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFsrmPropertyBag * This,
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
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            __RPC__in IFsrmPropertyBag * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *name);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RelativePath )( 
            __RPC__in IFsrmPropertyBag * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *path);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_VolumeName )( 
            __RPC__in IFsrmPropertyBag * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *volumeName);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RelativeNamespaceRoot )( 
            __RPC__in IFsrmPropertyBag * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *relativeNamespaceRoot);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_VolumeIndex )( 
            __RPC__in IFsrmPropertyBag * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  unsigned long *volumeId);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FileId )( 
            __RPC__in IFsrmPropertyBag * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT *fileId);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ParentDirectoryId )( 
            __RPC__in IFsrmPropertyBag * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT *parentDirectoryId);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Size )( 
            __RPC__in IFsrmPropertyBag * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT *size);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SizeAllocated )( 
            __RPC__in IFsrmPropertyBag * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT *sizeAllocated);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CreationTime )( 
            __RPC__in IFsrmPropertyBag * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT *creationTime);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LastAccessTime )( 
            __RPC__in IFsrmPropertyBag * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT *lastAccessTime);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LastModificationTime )( 
            __RPC__in IFsrmPropertyBag * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT *lastModificationTime);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Attributes )( 
            __RPC__in IFsrmPropertyBag * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  unsigned long *attributes);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OwnerSid )( 
            __RPC__in IFsrmPropertyBag * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *ownerSid);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FilePropertyNames )( 
            __RPC__in IFsrmPropertyBag * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  SAFEARRAY * *filePropertyNames);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Messages )( 
            __RPC__in IFsrmPropertyBag * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  SAFEARRAY * *messages);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PropertyBagFlags )( 
            __RPC__in IFsrmPropertyBag * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  unsigned long *flags);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetFileProperty )( 
            __RPC__in IFsrmPropertyBag * This,
            /* [annotation][in] */ 
            _In_  BSTR name,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmProperty **fileProperty);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetFileProperty )( 
            __RPC__in IFsrmPropertyBag * This,
            /* [annotation][in] */ 
            _In_  BSTR name,
            /* [annotation][in] */ 
            _In_  BSTR value);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddMessage )( 
            __RPC__in IFsrmPropertyBag * This,
            /* [annotation][in] */ 
            _In_  BSTR message);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetFileStreamInterface )( 
            __RPC__in IFsrmPropertyBag * This,
            /* [annotation][in] */ 
            _In_  FsrmFileStreamingMode accessMode,
            /* [annotation][in] */ 
            _In_  FsrmFileStreamingInterfaceType interfaceType,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT *pStreamInterface);
        
        END_INTERFACE
    } IFsrmPropertyBagVtbl;

    interface IFsrmPropertyBag
    {
        CONST_VTBL struct IFsrmPropertyBagVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFsrmPropertyBag_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFsrmPropertyBag_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFsrmPropertyBag_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFsrmPropertyBag_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFsrmPropertyBag_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFsrmPropertyBag_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFsrmPropertyBag_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IFsrmPropertyBag_get_Name(This,name)	\
    ( (This)->lpVtbl -> get_Name(This,name) ) 

#define IFsrmPropertyBag_get_RelativePath(This,path)	\
    ( (This)->lpVtbl -> get_RelativePath(This,path) ) 

#define IFsrmPropertyBag_get_VolumeName(This,volumeName)	\
    ( (This)->lpVtbl -> get_VolumeName(This,volumeName) ) 

#define IFsrmPropertyBag_get_RelativeNamespaceRoot(This,relativeNamespaceRoot)	\
    ( (This)->lpVtbl -> get_RelativeNamespaceRoot(This,relativeNamespaceRoot) ) 

#define IFsrmPropertyBag_get_VolumeIndex(This,volumeId)	\
    ( (This)->lpVtbl -> get_VolumeIndex(This,volumeId) ) 

#define IFsrmPropertyBag_get_FileId(This,fileId)	\
    ( (This)->lpVtbl -> get_FileId(This,fileId) ) 

#define IFsrmPropertyBag_get_ParentDirectoryId(This,parentDirectoryId)	\
    ( (This)->lpVtbl -> get_ParentDirectoryId(This,parentDirectoryId) ) 

#define IFsrmPropertyBag_get_Size(This,size)	\
    ( (This)->lpVtbl -> get_Size(This,size) ) 

#define IFsrmPropertyBag_get_SizeAllocated(This,sizeAllocated)	\
    ( (This)->lpVtbl -> get_SizeAllocated(This,sizeAllocated) ) 

#define IFsrmPropertyBag_get_CreationTime(This,creationTime)	\
    ( (This)->lpVtbl -> get_CreationTime(This,creationTime) ) 

#define IFsrmPropertyBag_get_LastAccessTime(This,lastAccessTime)	\
    ( (This)->lpVtbl -> get_LastAccessTime(This,lastAccessTime) ) 

#define IFsrmPropertyBag_get_LastModificationTime(This,lastModificationTime)	\
    ( (This)->lpVtbl -> get_LastModificationTime(This,lastModificationTime) ) 

#define IFsrmPropertyBag_get_Attributes(This,attributes)	\
    ( (This)->lpVtbl -> get_Attributes(This,attributes) ) 

#define IFsrmPropertyBag_get_OwnerSid(This,ownerSid)	\
    ( (This)->lpVtbl -> get_OwnerSid(This,ownerSid) ) 

#define IFsrmPropertyBag_get_FilePropertyNames(This,filePropertyNames)	\
    ( (This)->lpVtbl -> get_FilePropertyNames(This,filePropertyNames) ) 

#define IFsrmPropertyBag_get_Messages(This,messages)	\
    ( (This)->lpVtbl -> get_Messages(This,messages) ) 

#define IFsrmPropertyBag_get_PropertyBagFlags(This,flags)	\
    ( (This)->lpVtbl -> get_PropertyBagFlags(This,flags) ) 

#define IFsrmPropertyBag_GetFileProperty(This,name,fileProperty)	\
    ( (This)->lpVtbl -> GetFileProperty(This,name,fileProperty) ) 

#define IFsrmPropertyBag_SetFileProperty(This,name,value)	\
    ( (This)->lpVtbl -> SetFileProperty(This,name,value) ) 

#define IFsrmPropertyBag_AddMessage(This,message)	\
    ( (This)->lpVtbl -> AddMessage(This,message) ) 

#define IFsrmPropertyBag_GetFileStreamInterface(This,accessMode,interfaceType,pStreamInterface)	\
    ( (This)->lpVtbl -> GetFileStreamInterface(This,accessMode,interfaceType,pStreamInterface) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFsrmPropertyBag_INTERFACE_DEFINED__ */


#ifndef __IFsrmPropertyBag2_INTERFACE_DEFINED__
#define __IFsrmPropertyBag2_INTERFACE_DEFINED__

/* interface IFsrmPropertyBag2 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IFsrmPropertyBag2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0e46bdbd-2402-4fed-9c30-9266e6eb2cc9")
    IFsrmPropertyBag2 : public IFsrmPropertyBag
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetFieldValue( 
            /* [annotation][in] */ 
            _In_  FsrmPropertyBagField field,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT *value) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetUntrustedInFileProperties( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmCollection **props) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IFsrmPropertyBag2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IFsrmPropertyBag2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IFsrmPropertyBag2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IFsrmPropertyBag2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IFsrmPropertyBag2 * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IFsrmPropertyBag2 * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IFsrmPropertyBag2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][size_is][in] */ 
            _In_reads_(cNames)  LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cNames)  DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFsrmPropertyBag2 * This,
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
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            __RPC__in IFsrmPropertyBag2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *name);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RelativePath )( 
            __RPC__in IFsrmPropertyBag2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *path);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_VolumeName )( 
            __RPC__in IFsrmPropertyBag2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *volumeName);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RelativeNamespaceRoot )( 
            __RPC__in IFsrmPropertyBag2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *relativeNamespaceRoot);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_VolumeIndex )( 
            __RPC__in IFsrmPropertyBag2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  unsigned long *volumeId);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FileId )( 
            __RPC__in IFsrmPropertyBag2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT *fileId);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ParentDirectoryId )( 
            __RPC__in IFsrmPropertyBag2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT *parentDirectoryId);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Size )( 
            __RPC__in IFsrmPropertyBag2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT *size);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SizeAllocated )( 
            __RPC__in IFsrmPropertyBag2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT *sizeAllocated);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CreationTime )( 
            __RPC__in IFsrmPropertyBag2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT *creationTime);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LastAccessTime )( 
            __RPC__in IFsrmPropertyBag2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT *lastAccessTime);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LastModificationTime )( 
            __RPC__in IFsrmPropertyBag2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT *lastModificationTime);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Attributes )( 
            __RPC__in IFsrmPropertyBag2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  unsigned long *attributes);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OwnerSid )( 
            __RPC__in IFsrmPropertyBag2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *ownerSid);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FilePropertyNames )( 
            __RPC__in IFsrmPropertyBag2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  SAFEARRAY * *filePropertyNames);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Messages )( 
            __RPC__in IFsrmPropertyBag2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  SAFEARRAY * *messages);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PropertyBagFlags )( 
            __RPC__in IFsrmPropertyBag2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  unsigned long *flags);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetFileProperty )( 
            __RPC__in IFsrmPropertyBag2 * This,
            /* [annotation][in] */ 
            _In_  BSTR name,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmProperty **fileProperty);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetFileProperty )( 
            __RPC__in IFsrmPropertyBag2 * This,
            /* [annotation][in] */ 
            _In_  BSTR name,
            /* [annotation][in] */ 
            _In_  BSTR value);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddMessage )( 
            __RPC__in IFsrmPropertyBag2 * This,
            /* [annotation][in] */ 
            _In_  BSTR message);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetFileStreamInterface )( 
            __RPC__in IFsrmPropertyBag2 * This,
            /* [annotation][in] */ 
            _In_  FsrmFileStreamingMode accessMode,
            /* [annotation][in] */ 
            _In_  FsrmFileStreamingInterfaceType interfaceType,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT *pStreamInterface);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetFieldValue )( 
            __RPC__in IFsrmPropertyBag2 * This,
            /* [annotation][in] */ 
            _In_  FsrmPropertyBagField field,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT *value);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetUntrustedInFileProperties )( 
            __RPC__in IFsrmPropertyBag2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmCollection **props);
        
        END_INTERFACE
    } IFsrmPropertyBag2Vtbl;

    interface IFsrmPropertyBag2
    {
        CONST_VTBL struct IFsrmPropertyBag2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFsrmPropertyBag2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFsrmPropertyBag2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFsrmPropertyBag2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFsrmPropertyBag2_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFsrmPropertyBag2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFsrmPropertyBag2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFsrmPropertyBag2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IFsrmPropertyBag2_get_Name(This,name)	\
    ( (This)->lpVtbl -> get_Name(This,name) ) 

#define IFsrmPropertyBag2_get_RelativePath(This,path)	\
    ( (This)->lpVtbl -> get_RelativePath(This,path) ) 

#define IFsrmPropertyBag2_get_VolumeName(This,volumeName)	\
    ( (This)->lpVtbl -> get_VolumeName(This,volumeName) ) 

#define IFsrmPropertyBag2_get_RelativeNamespaceRoot(This,relativeNamespaceRoot)	\
    ( (This)->lpVtbl -> get_RelativeNamespaceRoot(This,relativeNamespaceRoot) ) 

#define IFsrmPropertyBag2_get_VolumeIndex(This,volumeId)	\
    ( (This)->lpVtbl -> get_VolumeIndex(This,volumeId) ) 

#define IFsrmPropertyBag2_get_FileId(This,fileId)	\
    ( (This)->lpVtbl -> get_FileId(This,fileId) ) 

#define IFsrmPropertyBag2_get_ParentDirectoryId(This,parentDirectoryId)	\
    ( (This)->lpVtbl -> get_ParentDirectoryId(This,parentDirectoryId) ) 

#define IFsrmPropertyBag2_get_Size(This,size)	\
    ( (This)->lpVtbl -> get_Size(This,size) ) 

#define IFsrmPropertyBag2_get_SizeAllocated(This,sizeAllocated)	\
    ( (This)->lpVtbl -> get_SizeAllocated(This,sizeAllocated) ) 

#define IFsrmPropertyBag2_get_CreationTime(This,creationTime)	\
    ( (This)->lpVtbl -> get_CreationTime(This,creationTime) ) 

#define IFsrmPropertyBag2_get_LastAccessTime(This,lastAccessTime)	\
    ( (This)->lpVtbl -> get_LastAccessTime(This,lastAccessTime) ) 

#define IFsrmPropertyBag2_get_LastModificationTime(This,lastModificationTime)	\
    ( (This)->lpVtbl -> get_LastModificationTime(This,lastModificationTime) ) 

#define IFsrmPropertyBag2_get_Attributes(This,attributes)	\
    ( (This)->lpVtbl -> get_Attributes(This,attributes) ) 

#define IFsrmPropertyBag2_get_OwnerSid(This,ownerSid)	\
    ( (This)->lpVtbl -> get_OwnerSid(This,ownerSid) ) 

#define IFsrmPropertyBag2_get_FilePropertyNames(This,filePropertyNames)	\
    ( (This)->lpVtbl -> get_FilePropertyNames(This,filePropertyNames) ) 

#define IFsrmPropertyBag2_get_Messages(This,messages)	\
    ( (This)->lpVtbl -> get_Messages(This,messages) ) 

#define IFsrmPropertyBag2_get_PropertyBagFlags(This,flags)	\
    ( (This)->lpVtbl -> get_PropertyBagFlags(This,flags) ) 

#define IFsrmPropertyBag2_GetFileProperty(This,name,fileProperty)	\
    ( (This)->lpVtbl -> GetFileProperty(This,name,fileProperty) ) 

#define IFsrmPropertyBag2_SetFileProperty(This,name,value)	\
    ( (This)->lpVtbl -> SetFileProperty(This,name,value) ) 

#define IFsrmPropertyBag2_AddMessage(This,message)	\
    ( (This)->lpVtbl -> AddMessage(This,message) ) 

#define IFsrmPropertyBag2_GetFileStreamInterface(This,accessMode,interfaceType,pStreamInterface)	\
    ( (This)->lpVtbl -> GetFileStreamInterface(This,accessMode,interfaceType,pStreamInterface) ) 


#define IFsrmPropertyBag2_GetFieldValue(This,field,value)	\
    ( (This)->lpVtbl -> GetFieldValue(This,field,value) ) 

#define IFsrmPropertyBag2_GetUntrustedInFileProperties(This,props)	\
    ( (This)->lpVtbl -> GetUntrustedInFileProperties(This,props) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFsrmPropertyBag2_INTERFACE_DEFINED__ */


#ifndef __IFsrmPipelineModuleImplementation_INTERFACE_DEFINED__
#define __IFsrmPipelineModuleImplementation_INTERFACE_DEFINED__

/* interface IFsrmPipelineModuleImplementation */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IFsrmPipelineModuleImplementation;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("b7907906-2b02-4cb5-84a9-fdf54613d6cd")
    IFsrmPipelineModuleImplementation : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnLoad( 
            /* [annotation][in] */ 
            _In_  IFsrmPipelineModuleDefinition *moduleDefinition,
            /* [annotation][out] */ 
            _Out_  IFsrmPipelineModuleConnector **moduleConnector) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnUnload( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IFsrmPipelineModuleImplementationVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IFsrmPipelineModuleImplementation * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IFsrmPipelineModuleImplementation * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IFsrmPipelineModuleImplementation * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IFsrmPipelineModuleImplementation * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IFsrmPipelineModuleImplementation * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IFsrmPipelineModuleImplementation * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][size_is][in] */ 
            _In_reads_(cNames)  LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cNames)  DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFsrmPipelineModuleImplementation * This,
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
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnLoad )( 
            __RPC__in IFsrmPipelineModuleImplementation * This,
            /* [annotation][in] */ 
            _In_  IFsrmPipelineModuleDefinition *moduleDefinition,
            /* [annotation][out] */ 
            _Out_  IFsrmPipelineModuleConnector **moduleConnector);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnUnload )( 
            __RPC__in IFsrmPipelineModuleImplementation * This);
        
        END_INTERFACE
    } IFsrmPipelineModuleImplementationVtbl;

    interface IFsrmPipelineModuleImplementation
    {
        CONST_VTBL struct IFsrmPipelineModuleImplementationVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFsrmPipelineModuleImplementation_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFsrmPipelineModuleImplementation_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFsrmPipelineModuleImplementation_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFsrmPipelineModuleImplementation_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFsrmPipelineModuleImplementation_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFsrmPipelineModuleImplementation_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFsrmPipelineModuleImplementation_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IFsrmPipelineModuleImplementation_OnLoad(This,moduleDefinition,moduleConnector)	\
    ( (This)->lpVtbl -> OnLoad(This,moduleDefinition,moduleConnector) ) 

#define IFsrmPipelineModuleImplementation_OnUnload(This)	\
    ( (This)->lpVtbl -> OnUnload(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFsrmPipelineModuleImplementation_INTERFACE_DEFINED__ */


#ifndef __IFsrmClassifierModuleImplementation_INTERFACE_DEFINED__
#define __IFsrmClassifierModuleImplementation_INTERFACE_DEFINED__

/* interface IFsrmClassifierModuleImplementation */
/* [unique][helpstring][dual][uuid][object] */ 

#define FsrmNeverModified  ((ULONGLONG) 0x0000000000000000ui64)
#define FsrmAlwaysModified ((ULONGLONG) 0xFFFFFFFFFFFFFFFFui64)

EXTERN_C const IID IID_IFsrmClassifierModuleImplementation;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4c968fc6-6edb-4051-9c18-73b7291ae106")
    IFsrmClassifierModuleImplementation : public IFsrmPipelineModuleImplementation
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LastModified( 
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT *lastModified) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UseRulesAndDefinitions( 
            /* [annotation][in] */ 
            _In_  IFsrmCollection *rules,
            /* [annotation][in] */ 
            _In_  IFsrmCollection *propertyDefinitions) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnBeginFile( 
            /* [annotation][in] */ 
            _In_  IFsrmPropertyBag *propertyBag,
            /* [annotation][in] */ 
            _In_  SAFEARRAY * arrayRuleIds) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DoesPropertyValueApply( 
            /* [annotation][in] */ 
            _In_  BSTR property,
            /* [annotation][in] */ 
            _In_  BSTR value,
            /* [annotation][out] */ 
            _Out_  VARIANT_BOOL *applyValue,
            /* [annotation][in] */ 
            _In_  FSRM_OBJECT_ID idRule,
            /* [annotation][in] */ 
            _In_  FSRM_OBJECT_ID idPropDef) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetPropertyValueToApply( 
            /* [annotation][in] */ 
            _In_  BSTR property,
            /* [annotation][out] */ 
            _Out_  BSTR *value,
            /* [annotation][in] */ 
            _In_  FSRM_OBJECT_ID idRule,
            /* [annotation][in] */ 
            _In_  FSRM_OBJECT_ID idPropDef) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnEndFile( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IFsrmClassifierModuleImplementationVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IFsrmClassifierModuleImplementation * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IFsrmClassifierModuleImplementation * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IFsrmClassifierModuleImplementation * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IFsrmClassifierModuleImplementation * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IFsrmClassifierModuleImplementation * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IFsrmClassifierModuleImplementation * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][size_is][in] */ 
            _In_reads_(cNames)  LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cNames)  DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFsrmClassifierModuleImplementation * This,
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
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnLoad )( 
            __RPC__in IFsrmClassifierModuleImplementation * This,
            /* [annotation][in] */ 
            _In_  IFsrmPipelineModuleDefinition *moduleDefinition,
            /* [annotation][out] */ 
            _Out_  IFsrmPipelineModuleConnector **moduleConnector);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnUnload )( 
            __RPC__in IFsrmClassifierModuleImplementation * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LastModified )( 
            __RPC__in IFsrmClassifierModuleImplementation * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT *lastModified);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UseRulesAndDefinitions )( 
            __RPC__in IFsrmClassifierModuleImplementation * This,
            /* [annotation][in] */ 
            _In_  IFsrmCollection *rules,
            /* [annotation][in] */ 
            _In_  IFsrmCollection *propertyDefinitions);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnBeginFile )( 
            __RPC__in IFsrmClassifierModuleImplementation * This,
            /* [annotation][in] */ 
            _In_  IFsrmPropertyBag *propertyBag,
            /* [annotation][in] */ 
            _In_  SAFEARRAY * arrayRuleIds);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DoesPropertyValueApply )( 
            __RPC__in IFsrmClassifierModuleImplementation * This,
            /* [annotation][in] */ 
            _In_  BSTR property,
            /* [annotation][in] */ 
            _In_  BSTR value,
            /* [annotation][out] */ 
            _Out_  VARIANT_BOOL *applyValue,
            /* [annotation][in] */ 
            _In_  FSRM_OBJECT_ID idRule,
            /* [annotation][in] */ 
            _In_  FSRM_OBJECT_ID idPropDef);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetPropertyValueToApply )( 
            __RPC__in IFsrmClassifierModuleImplementation * This,
            /* [annotation][in] */ 
            _In_  BSTR property,
            /* [annotation][out] */ 
            _Out_  BSTR *value,
            /* [annotation][in] */ 
            _In_  FSRM_OBJECT_ID idRule,
            /* [annotation][in] */ 
            _In_  FSRM_OBJECT_ID idPropDef);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnEndFile )( 
            __RPC__in IFsrmClassifierModuleImplementation * This);
        
        END_INTERFACE
    } IFsrmClassifierModuleImplementationVtbl;

    interface IFsrmClassifierModuleImplementation
    {
        CONST_VTBL struct IFsrmClassifierModuleImplementationVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFsrmClassifierModuleImplementation_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFsrmClassifierModuleImplementation_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFsrmClassifierModuleImplementation_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFsrmClassifierModuleImplementation_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFsrmClassifierModuleImplementation_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFsrmClassifierModuleImplementation_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFsrmClassifierModuleImplementation_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IFsrmClassifierModuleImplementation_OnLoad(This,moduleDefinition,moduleConnector)	\
    ( (This)->lpVtbl -> OnLoad(This,moduleDefinition,moduleConnector) ) 

#define IFsrmClassifierModuleImplementation_OnUnload(This)	\
    ( (This)->lpVtbl -> OnUnload(This) ) 


#define IFsrmClassifierModuleImplementation_get_LastModified(This,lastModified)	\
    ( (This)->lpVtbl -> get_LastModified(This,lastModified) ) 

#define IFsrmClassifierModuleImplementation_UseRulesAndDefinitions(This,rules,propertyDefinitions)	\
    ( (This)->lpVtbl -> UseRulesAndDefinitions(This,rules,propertyDefinitions) ) 

#define IFsrmClassifierModuleImplementation_OnBeginFile(This,propertyBag,arrayRuleIds)	\
    ( (This)->lpVtbl -> OnBeginFile(This,propertyBag,arrayRuleIds) ) 

#define IFsrmClassifierModuleImplementation_DoesPropertyValueApply(This,property,value,applyValue,idRule,idPropDef)	\
    ( (This)->lpVtbl -> DoesPropertyValueApply(This,property,value,applyValue,idRule,idPropDef) ) 

#define IFsrmClassifierModuleImplementation_GetPropertyValueToApply(This,property,value,idRule,idPropDef)	\
    ( (This)->lpVtbl -> GetPropertyValueToApply(This,property,value,idRule,idPropDef) ) 

#define IFsrmClassifierModuleImplementation_OnEndFile(This)	\
    ( (This)->lpVtbl -> OnEndFile(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFsrmClassifierModuleImplementation_INTERFACE_DEFINED__ */


#ifndef __IFsrmStorageModuleImplementation_INTERFACE_DEFINED__
#define __IFsrmStorageModuleImplementation_INTERFACE_DEFINED__

/* interface IFsrmStorageModuleImplementation */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IFsrmStorageModuleImplementation;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0af4a0da-895a-4e50-8712-a96724bcec64")
    IFsrmStorageModuleImplementation : public IFsrmPipelineModuleImplementation
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UseDefinitions( 
            /* [annotation][in] */ 
            _In_  IFsrmCollection *propertyDefinitions) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LoadProperties( 
            /* [annotation][in] */ 
            _In_  IFsrmPropertyBag *propertyBag) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SaveProperties( 
            /* [annotation][in] */ 
            _In_  IFsrmPropertyBag *propertyBag) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IFsrmStorageModuleImplementationVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IFsrmStorageModuleImplementation * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IFsrmStorageModuleImplementation * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IFsrmStorageModuleImplementation * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IFsrmStorageModuleImplementation * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IFsrmStorageModuleImplementation * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IFsrmStorageModuleImplementation * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][size_is][in] */ 
            _In_reads_(cNames)  LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cNames)  DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFsrmStorageModuleImplementation * This,
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
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnLoad )( 
            __RPC__in IFsrmStorageModuleImplementation * This,
            /* [annotation][in] */ 
            _In_  IFsrmPipelineModuleDefinition *moduleDefinition,
            /* [annotation][out] */ 
            _Out_  IFsrmPipelineModuleConnector **moduleConnector);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnUnload )( 
            __RPC__in IFsrmStorageModuleImplementation * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UseDefinitions )( 
            __RPC__in IFsrmStorageModuleImplementation * This,
            /* [annotation][in] */ 
            _In_  IFsrmCollection *propertyDefinitions);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LoadProperties )( 
            __RPC__in IFsrmStorageModuleImplementation * This,
            /* [annotation][in] */ 
            _In_  IFsrmPropertyBag *propertyBag);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SaveProperties )( 
            __RPC__in IFsrmStorageModuleImplementation * This,
            /* [annotation][in] */ 
            _In_  IFsrmPropertyBag *propertyBag);
        
        END_INTERFACE
    } IFsrmStorageModuleImplementationVtbl;

    interface IFsrmStorageModuleImplementation
    {
        CONST_VTBL struct IFsrmStorageModuleImplementationVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFsrmStorageModuleImplementation_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFsrmStorageModuleImplementation_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFsrmStorageModuleImplementation_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFsrmStorageModuleImplementation_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFsrmStorageModuleImplementation_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFsrmStorageModuleImplementation_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFsrmStorageModuleImplementation_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IFsrmStorageModuleImplementation_OnLoad(This,moduleDefinition,moduleConnector)	\
    ( (This)->lpVtbl -> OnLoad(This,moduleDefinition,moduleConnector) ) 

#define IFsrmStorageModuleImplementation_OnUnload(This)	\
    ( (This)->lpVtbl -> OnUnload(This) ) 


#define IFsrmStorageModuleImplementation_UseDefinitions(This,propertyDefinitions)	\
    ( (This)->lpVtbl -> UseDefinitions(This,propertyDefinitions) ) 

#define IFsrmStorageModuleImplementation_LoadProperties(This,propertyBag)	\
    ( (This)->lpVtbl -> LoadProperties(This,propertyBag) ) 

#define IFsrmStorageModuleImplementation_SaveProperties(This,propertyBag)	\
    ( (This)->lpVtbl -> SaveProperties(This,propertyBag) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFsrmStorageModuleImplementation_INTERFACE_DEFINED__ */


#ifndef __IFsrmPipelineModuleConnector_INTERFACE_DEFINED__
#define __IFsrmPipelineModuleConnector_INTERFACE_DEFINED__

/* interface IFsrmPipelineModuleConnector */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IFsrmPipelineModuleConnector;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("c16014f3-9aa1-46b3-b0a7-ab146eb205f2")
    IFsrmPipelineModuleConnector : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ModuleImplementation( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmPipelineModuleImplementation **pipelineModuleImplementation) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ModuleName( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *userName) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_HostingUserAccount( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *userAccount) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_HostingProcessPid( 
            /* [annotation][retval][out] */ 
            _Out_retval_  long *pid) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Bind( 
            /* [annotation][in] */ 
            _In_  IFsrmPipelineModuleDefinition *moduleDefinition,
            /* [annotation][in] */ 
            _In_  IFsrmPipelineModuleImplementation *moduleImplementation) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IFsrmPipelineModuleConnectorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IFsrmPipelineModuleConnector * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IFsrmPipelineModuleConnector * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IFsrmPipelineModuleConnector * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IFsrmPipelineModuleConnector * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IFsrmPipelineModuleConnector * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IFsrmPipelineModuleConnector * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][size_is][in] */ 
            _In_reads_(cNames)  LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cNames)  DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFsrmPipelineModuleConnector * This,
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
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ModuleImplementation )( 
            __RPC__in IFsrmPipelineModuleConnector * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmPipelineModuleImplementation **pipelineModuleImplementation);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ModuleName )( 
            __RPC__in IFsrmPipelineModuleConnector * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *userName);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HostingUserAccount )( 
            __RPC__in IFsrmPipelineModuleConnector * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *userAccount);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HostingProcessPid )( 
            __RPC__in IFsrmPipelineModuleConnector * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *pid);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Bind )( 
            __RPC__in IFsrmPipelineModuleConnector * This,
            /* [annotation][in] */ 
            _In_  IFsrmPipelineModuleDefinition *moduleDefinition,
            /* [annotation][in] */ 
            _In_  IFsrmPipelineModuleImplementation *moduleImplementation);
        
        END_INTERFACE
    } IFsrmPipelineModuleConnectorVtbl;

    interface IFsrmPipelineModuleConnector
    {
        CONST_VTBL struct IFsrmPipelineModuleConnectorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFsrmPipelineModuleConnector_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFsrmPipelineModuleConnector_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFsrmPipelineModuleConnector_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFsrmPipelineModuleConnector_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFsrmPipelineModuleConnector_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFsrmPipelineModuleConnector_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFsrmPipelineModuleConnector_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IFsrmPipelineModuleConnector_get_ModuleImplementation(This,pipelineModuleImplementation)	\
    ( (This)->lpVtbl -> get_ModuleImplementation(This,pipelineModuleImplementation) ) 

#define IFsrmPipelineModuleConnector_get_ModuleName(This,userName)	\
    ( (This)->lpVtbl -> get_ModuleName(This,userName) ) 

#define IFsrmPipelineModuleConnector_get_HostingUserAccount(This,userAccount)	\
    ( (This)->lpVtbl -> get_HostingUserAccount(This,userAccount) ) 

#define IFsrmPipelineModuleConnector_get_HostingProcessPid(This,pid)	\
    ( (This)->lpVtbl -> get_HostingProcessPid(This,pid) ) 

#define IFsrmPipelineModuleConnector_Bind(This,moduleDefinition,moduleImplementation)	\
    ( (This)->lpVtbl -> Bind(This,moduleDefinition,moduleImplementation) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFsrmPipelineModuleConnector_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_fsrmpipeline_0000_0017 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_fsrmpipeline_0000_0017_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_fsrmpipeline_0000_0017_v0_0_s_ifspec;

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


