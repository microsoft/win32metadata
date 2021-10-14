

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

#ifndef __fsrmscreen_h__
#define __fsrmscreen_h__

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

#ifndef __IFsrmFileGroup_FWD_DEFINED__
#define __IFsrmFileGroup_FWD_DEFINED__
typedef interface IFsrmFileGroup IFsrmFileGroup;

#endif 	/* __IFsrmFileGroup_FWD_DEFINED__ */


#ifndef __IFsrmFileGroupImported_FWD_DEFINED__
#define __IFsrmFileGroupImported_FWD_DEFINED__
typedef interface IFsrmFileGroupImported IFsrmFileGroupImported;

#endif 	/* __IFsrmFileGroupImported_FWD_DEFINED__ */


#ifndef __IFsrmFileGroupManager_FWD_DEFINED__
#define __IFsrmFileGroupManager_FWD_DEFINED__
typedef interface IFsrmFileGroupManager IFsrmFileGroupManager;

#endif 	/* __IFsrmFileGroupManager_FWD_DEFINED__ */


#ifndef __IFsrmFileScreenBase_FWD_DEFINED__
#define __IFsrmFileScreenBase_FWD_DEFINED__
typedef interface IFsrmFileScreenBase IFsrmFileScreenBase;

#endif 	/* __IFsrmFileScreenBase_FWD_DEFINED__ */


#ifndef __IFsrmFileScreen_FWD_DEFINED__
#define __IFsrmFileScreen_FWD_DEFINED__
typedef interface IFsrmFileScreen IFsrmFileScreen;

#endif 	/* __IFsrmFileScreen_FWD_DEFINED__ */


#ifndef __IFsrmFileScreenException_FWD_DEFINED__
#define __IFsrmFileScreenException_FWD_DEFINED__
typedef interface IFsrmFileScreenException IFsrmFileScreenException;

#endif 	/* __IFsrmFileScreenException_FWD_DEFINED__ */


#ifndef __IFsrmFileScreenManager_FWD_DEFINED__
#define __IFsrmFileScreenManager_FWD_DEFINED__
typedef interface IFsrmFileScreenManager IFsrmFileScreenManager;

#endif 	/* __IFsrmFileScreenManager_FWD_DEFINED__ */


#ifndef __IFsrmFileScreenTemplate_FWD_DEFINED__
#define __IFsrmFileScreenTemplate_FWD_DEFINED__
typedef interface IFsrmFileScreenTemplate IFsrmFileScreenTemplate;

#endif 	/* __IFsrmFileScreenTemplate_FWD_DEFINED__ */


#ifndef __IFsrmFileScreenTemplateImported_FWD_DEFINED__
#define __IFsrmFileScreenTemplateImported_FWD_DEFINED__
typedef interface IFsrmFileScreenTemplateImported IFsrmFileScreenTemplateImported;

#endif 	/* __IFsrmFileScreenTemplateImported_FWD_DEFINED__ */


#ifndef __IFsrmFileScreenTemplateManager_FWD_DEFINED__
#define __IFsrmFileScreenTemplateManager_FWD_DEFINED__
typedef interface IFsrmFileScreenTemplateManager IFsrmFileScreenTemplateManager;

#endif 	/* __IFsrmFileScreenTemplateManager_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "fsrmenums.h"
#include "fsrm.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_fsrmscreen_0000_0000 */
/* [local] */ 

#include <winapifamily.h>
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)










#define	FSRM_DISPID_FILEGROUP	( ( FSRM_DISPID_FEATURE_FILESCREEN | 0x100000 )  )

#define	FSRM_DISPID_FILEGROUP_IMPORTED	( ( FSRM_DISPID_FILEGROUP | 0x10000 )  )

#define	FSRM_DISPID_FILEGROUP_MANAGER	( ( FSRM_DISPID_FEATURE_FILESCREEN | 0x200000 )  )

#define	FSRM_DISPID_FILESCREEN_BASE	( ( FSRM_DISPID_FEATURE_FILESCREEN | 0x300000 )  )

#define	FSRM_DISPID_FILESCREEN	( ( FSRM_DISPID_FILESCREEN_BASE | 0x10000 )  )

#define	FSRM_DISPID_FILESCREEN_TEMPLATE	( ( FSRM_DISPID_FILESCREEN_BASE | 0x20000 )  )

#define	FSRM_DISPID_FILESCREEN_TEMPLATE_IMPORTED	( ( FSRM_DISPID_FILESCREEN_TEMPLATE | 0x1000 )  )

#define	FSRM_DISPID_FILESCREEN_EXCEPTION	( ( FSRM_DISPID_FEATURE_FILESCREEN | 0x400000 )  )

#define	FSRM_DISPID_FILESCREEN_MANAGER	( ( FSRM_DISPID_FEATURE_FILESCREEN | 0x500000 )  )

#define	FSRM_DISPID_FILESCREEN_TEMPLATE_MANAGER	( ( FSRM_DISPID_FEATURE_FILESCREEN | 0x600000 )  )



extern RPC_IF_HANDLE __MIDL_itf_fsrmscreen_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_fsrmscreen_0000_0000_v0_0_s_ifspec;

#ifndef __IFsrmFileGroup_INTERFACE_DEFINED__
#define __IFsrmFileGroup_INTERFACE_DEFINED__

/* interface IFsrmFileGroup */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IFsrmFileGroup;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8dd04909-0e34-4d55-afaa-89e1f1a1bbb9")
    IFsrmFileGroup : public IFsrmObject
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *name) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [annotation][in] */ 
            _In_  BSTR name) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Members( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmMutableCollection **members) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Members( 
            /* [annotation][in] */ 
            _In_  IFsrmMutableCollection *members) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_NonMembers( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmMutableCollection **nonMembers) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_NonMembers( 
            /* [annotation][in] */ 
            _In_  IFsrmMutableCollection *nonMembers) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IFsrmFileGroupVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IFsrmFileGroup * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IFsrmFileGroup * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IFsrmFileGroup * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IFsrmFileGroup * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IFsrmFileGroup * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IFsrmFileGroup * This,
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
            IFsrmFileGroup * This,
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
        
        DECLSPEC_XFGVIRT(IFsrmObject, get_Id)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Id )( 
            __RPC__in IFsrmFileGroup * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  FSRM_OBJECT_ID *id);
        
        DECLSPEC_XFGVIRT(IFsrmObject, get_Description)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Description )( 
            __RPC__in IFsrmFileGroup * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *description);
        
        DECLSPEC_XFGVIRT(IFsrmObject, put_Description)
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Description )( 
            __RPC__in IFsrmFileGroup * This,
            /* [annotation][in] */ 
            _In_  BSTR description);
        
        DECLSPEC_XFGVIRT(IFsrmObject, Delete)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            __RPC__in IFsrmFileGroup * This);
        
        DECLSPEC_XFGVIRT(IFsrmObject, Commit)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Commit )( 
            __RPC__in IFsrmFileGroup * This);
        
        DECLSPEC_XFGVIRT(IFsrmFileGroup, get_Name)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            __RPC__in IFsrmFileGroup * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *name);
        
        DECLSPEC_XFGVIRT(IFsrmFileGroup, put_Name)
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            __RPC__in IFsrmFileGroup * This,
            /* [annotation][in] */ 
            _In_  BSTR name);
        
        DECLSPEC_XFGVIRT(IFsrmFileGroup, get_Members)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Members )( 
            __RPC__in IFsrmFileGroup * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmMutableCollection **members);
        
        DECLSPEC_XFGVIRT(IFsrmFileGroup, put_Members)
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Members )( 
            __RPC__in IFsrmFileGroup * This,
            /* [annotation][in] */ 
            _In_  IFsrmMutableCollection *members);
        
        DECLSPEC_XFGVIRT(IFsrmFileGroup, get_NonMembers)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NonMembers )( 
            __RPC__in IFsrmFileGroup * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmMutableCollection **nonMembers);
        
        DECLSPEC_XFGVIRT(IFsrmFileGroup, put_NonMembers)
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_NonMembers )( 
            __RPC__in IFsrmFileGroup * This,
            /* [annotation][in] */ 
            _In_  IFsrmMutableCollection *nonMembers);
        
        END_INTERFACE
    } IFsrmFileGroupVtbl;

    interface IFsrmFileGroup
    {
        CONST_VTBL struct IFsrmFileGroupVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFsrmFileGroup_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFsrmFileGroup_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFsrmFileGroup_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFsrmFileGroup_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFsrmFileGroup_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFsrmFileGroup_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFsrmFileGroup_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IFsrmFileGroup_get_Id(This,id)	\
    ( (This)->lpVtbl -> get_Id(This,id) ) 

#define IFsrmFileGroup_get_Description(This,description)	\
    ( (This)->lpVtbl -> get_Description(This,description) ) 

#define IFsrmFileGroup_put_Description(This,description)	\
    ( (This)->lpVtbl -> put_Description(This,description) ) 

#define IFsrmFileGroup_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define IFsrmFileGroup_Commit(This)	\
    ( (This)->lpVtbl -> Commit(This) ) 


#define IFsrmFileGroup_get_Name(This,name)	\
    ( (This)->lpVtbl -> get_Name(This,name) ) 

#define IFsrmFileGroup_put_Name(This,name)	\
    ( (This)->lpVtbl -> put_Name(This,name) ) 

#define IFsrmFileGroup_get_Members(This,members)	\
    ( (This)->lpVtbl -> get_Members(This,members) ) 

#define IFsrmFileGroup_put_Members(This,members)	\
    ( (This)->lpVtbl -> put_Members(This,members) ) 

#define IFsrmFileGroup_get_NonMembers(This,nonMembers)	\
    ( (This)->lpVtbl -> get_NonMembers(This,nonMembers) ) 

#define IFsrmFileGroup_put_NonMembers(This,nonMembers)	\
    ( (This)->lpVtbl -> put_NonMembers(This,nonMembers) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFsrmFileGroup_INTERFACE_DEFINED__ */


#ifndef __IFsrmFileGroupImported_INTERFACE_DEFINED__
#define __IFsrmFileGroupImported_INTERFACE_DEFINED__

/* interface IFsrmFileGroupImported */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IFsrmFileGroupImported;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("ad55f10b-5f11-4be7-94ef-d9ee2e470ded")
    IFsrmFileGroupImported : public IFsrmFileGroup
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OverwriteOnCommit( 
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *overwrite) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_OverwriteOnCommit( 
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL overwrite) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IFsrmFileGroupImportedVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IFsrmFileGroupImported * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IFsrmFileGroupImported * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IFsrmFileGroupImported * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IFsrmFileGroupImported * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IFsrmFileGroupImported * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IFsrmFileGroupImported * This,
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
            IFsrmFileGroupImported * This,
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
        
        DECLSPEC_XFGVIRT(IFsrmObject, get_Id)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Id )( 
            __RPC__in IFsrmFileGroupImported * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  FSRM_OBJECT_ID *id);
        
        DECLSPEC_XFGVIRT(IFsrmObject, get_Description)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Description )( 
            __RPC__in IFsrmFileGroupImported * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *description);
        
        DECLSPEC_XFGVIRT(IFsrmObject, put_Description)
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Description )( 
            __RPC__in IFsrmFileGroupImported * This,
            /* [annotation][in] */ 
            _In_  BSTR description);
        
        DECLSPEC_XFGVIRT(IFsrmObject, Delete)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            __RPC__in IFsrmFileGroupImported * This);
        
        DECLSPEC_XFGVIRT(IFsrmObject, Commit)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Commit )( 
            __RPC__in IFsrmFileGroupImported * This);
        
        DECLSPEC_XFGVIRT(IFsrmFileGroup, get_Name)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            __RPC__in IFsrmFileGroupImported * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *name);
        
        DECLSPEC_XFGVIRT(IFsrmFileGroup, put_Name)
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            __RPC__in IFsrmFileGroupImported * This,
            /* [annotation][in] */ 
            _In_  BSTR name);
        
        DECLSPEC_XFGVIRT(IFsrmFileGroup, get_Members)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Members )( 
            __RPC__in IFsrmFileGroupImported * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmMutableCollection **members);
        
        DECLSPEC_XFGVIRT(IFsrmFileGroup, put_Members)
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Members )( 
            __RPC__in IFsrmFileGroupImported * This,
            /* [annotation][in] */ 
            _In_  IFsrmMutableCollection *members);
        
        DECLSPEC_XFGVIRT(IFsrmFileGroup, get_NonMembers)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NonMembers )( 
            __RPC__in IFsrmFileGroupImported * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmMutableCollection **nonMembers);
        
        DECLSPEC_XFGVIRT(IFsrmFileGroup, put_NonMembers)
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_NonMembers )( 
            __RPC__in IFsrmFileGroupImported * This,
            /* [annotation][in] */ 
            _In_  IFsrmMutableCollection *nonMembers);
        
        DECLSPEC_XFGVIRT(IFsrmFileGroupImported, get_OverwriteOnCommit)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OverwriteOnCommit )( 
            __RPC__in IFsrmFileGroupImported * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *overwrite);
        
        DECLSPEC_XFGVIRT(IFsrmFileGroupImported, put_OverwriteOnCommit)
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OverwriteOnCommit )( 
            __RPC__in IFsrmFileGroupImported * This,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL overwrite);
        
        END_INTERFACE
    } IFsrmFileGroupImportedVtbl;

    interface IFsrmFileGroupImported
    {
        CONST_VTBL struct IFsrmFileGroupImportedVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFsrmFileGroupImported_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFsrmFileGroupImported_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFsrmFileGroupImported_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFsrmFileGroupImported_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFsrmFileGroupImported_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFsrmFileGroupImported_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFsrmFileGroupImported_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IFsrmFileGroupImported_get_Id(This,id)	\
    ( (This)->lpVtbl -> get_Id(This,id) ) 

#define IFsrmFileGroupImported_get_Description(This,description)	\
    ( (This)->lpVtbl -> get_Description(This,description) ) 

#define IFsrmFileGroupImported_put_Description(This,description)	\
    ( (This)->lpVtbl -> put_Description(This,description) ) 

#define IFsrmFileGroupImported_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define IFsrmFileGroupImported_Commit(This)	\
    ( (This)->lpVtbl -> Commit(This) ) 


#define IFsrmFileGroupImported_get_Name(This,name)	\
    ( (This)->lpVtbl -> get_Name(This,name) ) 

#define IFsrmFileGroupImported_put_Name(This,name)	\
    ( (This)->lpVtbl -> put_Name(This,name) ) 

#define IFsrmFileGroupImported_get_Members(This,members)	\
    ( (This)->lpVtbl -> get_Members(This,members) ) 

#define IFsrmFileGroupImported_put_Members(This,members)	\
    ( (This)->lpVtbl -> put_Members(This,members) ) 

#define IFsrmFileGroupImported_get_NonMembers(This,nonMembers)	\
    ( (This)->lpVtbl -> get_NonMembers(This,nonMembers) ) 

#define IFsrmFileGroupImported_put_NonMembers(This,nonMembers)	\
    ( (This)->lpVtbl -> put_NonMembers(This,nonMembers) ) 


#define IFsrmFileGroupImported_get_OverwriteOnCommit(This,overwrite)	\
    ( (This)->lpVtbl -> get_OverwriteOnCommit(This,overwrite) ) 

#define IFsrmFileGroupImported_put_OverwriteOnCommit(This,overwrite)	\
    ( (This)->lpVtbl -> put_OverwriteOnCommit(This,overwrite) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFsrmFileGroupImported_INTERFACE_DEFINED__ */


#ifndef __IFsrmFileGroupManager_INTERFACE_DEFINED__
#define __IFsrmFileGroupManager_INTERFACE_DEFINED__

/* interface IFsrmFileGroupManager */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IFsrmFileGroupManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("426677d5-018c-485c-8a51-20b86d00bdc4")
    IFsrmFileGroupManager : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateFileGroup( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmFileGroup **fileGroup) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetFileGroup( 
            /* [annotation][in] */ 
            _In_  BSTR name,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmFileGroup **fileGroup) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EnumFileGroups( 
            /* [annotation][defaultvalue][in] */ 
            _In_  FsrmEnumOptions options,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmCommittableCollection **fileGroups) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ExportFileGroups( 
            /* [annotation][defaultvalue][in] */ 
            _In_  VARIANT *fileGroupNamesArray,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *serializedFileGroups) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ImportFileGroups( 
            /* [annotation][in] */ 
            _In_  BSTR serializedFileGroups,
            /* [annotation][defaultvalue][in] */ 
            _In_  VARIANT *fileGroupNamesArray,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmCommittableCollection **fileGroups) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IFsrmFileGroupManagerVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IFsrmFileGroupManager * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IFsrmFileGroupManager * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IFsrmFileGroupManager * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IFsrmFileGroupManager * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IFsrmFileGroupManager * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IFsrmFileGroupManager * This,
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
            IFsrmFileGroupManager * This,
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
        
        DECLSPEC_XFGVIRT(IFsrmFileGroupManager, CreateFileGroup)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateFileGroup )( 
            __RPC__in IFsrmFileGroupManager * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmFileGroup **fileGroup);
        
        DECLSPEC_XFGVIRT(IFsrmFileGroupManager, GetFileGroup)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetFileGroup )( 
            __RPC__in IFsrmFileGroupManager * This,
            /* [annotation][in] */ 
            _In_  BSTR name,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmFileGroup **fileGroup);
        
        DECLSPEC_XFGVIRT(IFsrmFileGroupManager, EnumFileGroups)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EnumFileGroups )( 
            __RPC__in IFsrmFileGroupManager * This,
            /* [annotation][defaultvalue][in] */ 
            _In_  FsrmEnumOptions options,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmCommittableCollection **fileGroups);
        
        DECLSPEC_XFGVIRT(IFsrmFileGroupManager, ExportFileGroups)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ExportFileGroups )( 
            __RPC__in IFsrmFileGroupManager * This,
            /* [annotation][defaultvalue][in] */ 
            _In_  VARIANT *fileGroupNamesArray,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *serializedFileGroups);
        
        DECLSPEC_XFGVIRT(IFsrmFileGroupManager, ImportFileGroups)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ImportFileGroups )( 
            __RPC__in IFsrmFileGroupManager * This,
            /* [annotation][in] */ 
            _In_  BSTR serializedFileGroups,
            /* [annotation][defaultvalue][in] */ 
            _In_  VARIANT *fileGroupNamesArray,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmCommittableCollection **fileGroups);
        
        END_INTERFACE
    } IFsrmFileGroupManagerVtbl;

    interface IFsrmFileGroupManager
    {
        CONST_VTBL struct IFsrmFileGroupManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFsrmFileGroupManager_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFsrmFileGroupManager_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFsrmFileGroupManager_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFsrmFileGroupManager_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFsrmFileGroupManager_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFsrmFileGroupManager_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFsrmFileGroupManager_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IFsrmFileGroupManager_CreateFileGroup(This,fileGroup)	\
    ( (This)->lpVtbl -> CreateFileGroup(This,fileGroup) ) 

#define IFsrmFileGroupManager_GetFileGroup(This,name,fileGroup)	\
    ( (This)->lpVtbl -> GetFileGroup(This,name,fileGroup) ) 

#define IFsrmFileGroupManager_EnumFileGroups(This,options,fileGroups)	\
    ( (This)->lpVtbl -> EnumFileGroups(This,options,fileGroups) ) 

#define IFsrmFileGroupManager_ExportFileGroups(This,fileGroupNamesArray,serializedFileGroups)	\
    ( (This)->lpVtbl -> ExportFileGroups(This,fileGroupNamesArray,serializedFileGroups) ) 

#define IFsrmFileGroupManager_ImportFileGroups(This,serializedFileGroups,fileGroupNamesArray,fileGroups)	\
    ( (This)->lpVtbl -> ImportFileGroups(This,serializedFileGroups,fileGroupNamesArray,fileGroups) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFsrmFileGroupManager_INTERFACE_DEFINED__ */


#ifndef __IFsrmFileScreenBase_INTERFACE_DEFINED__
#define __IFsrmFileScreenBase_INTERFACE_DEFINED__

/* interface IFsrmFileScreenBase */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IFsrmFileScreenBase;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("f3637e80-5b22-4a2b-a637-bbb642b41cfc")
    IFsrmFileScreenBase : public IFsrmObject
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_BlockedFileGroups( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmMutableCollection **blockList) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_BlockedFileGroups( 
            /* [annotation][in] */ 
            _In_  IFsrmMutableCollection *blockList) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FileScreenFlags( 
            /* [annotation][retval][out] */ 
            _Out_retval_  long *fileScreenFlags) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FileScreenFlags( 
            /* [annotation][in] */ 
            _In_  long fileScreenFlags) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateAction( 
            /* [annotation][in] */ 
            _In_  FsrmActionType actionType,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmAction **action) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EnumActions( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmCollection **actions) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IFsrmFileScreenBaseVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IFsrmFileScreenBase * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IFsrmFileScreenBase * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IFsrmFileScreenBase * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IFsrmFileScreenBase * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IFsrmFileScreenBase * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IFsrmFileScreenBase * This,
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
            IFsrmFileScreenBase * This,
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
        
        DECLSPEC_XFGVIRT(IFsrmObject, get_Id)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Id )( 
            __RPC__in IFsrmFileScreenBase * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  FSRM_OBJECT_ID *id);
        
        DECLSPEC_XFGVIRT(IFsrmObject, get_Description)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Description )( 
            __RPC__in IFsrmFileScreenBase * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *description);
        
        DECLSPEC_XFGVIRT(IFsrmObject, put_Description)
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Description )( 
            __RPC__in IFsrmFileScreenBase * This,
            /* [annotation][in] */ 
            _In_  BSTR description);
        
        DECLSPEC_XFGVIRT(IFsrmObject, Delete)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            __RPC__in IFsrmFileScreenBase * This);
        
        DECLSPEC_XFGVIRT(IFsrmObject, Commit)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Commit )( 
            __RPC__in IFsrmFileScreenBase * This);
        
        DECLSPEC_XFGVIRT(IFsrmFileScreenBase, get_BlockedFileGroups)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BlockedFileGroups )( 
            __RPC__in IFsrmFileScreenBase * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmMutableCollection **blockList);
        
        DECLSPEC_XFGVIRT(IFsrmFileScreenBase, put_BlockedFileGroups)
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BlockedFileGroups )( 
            __RPC__in IFsrmFileScreenBase * This,
            /* [annotation][in] */ 
            _In_  IFsrmMutableCollection *blockList);
        
        DECLSPEC_XFGVIRT(IFsrmFileScreenBase, get_FileScreenFlags)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FileScreenFlags )( 
            __RPC__in IFsrmFileScreenBase * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *fileScreenFlags);
        
        DECLSPEC_XFGVIRT(IFsrmFileScreenBase, put_FileScreenFlags)
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FileScreenFlags )( 
            __RPC__in IFsrmFileScreenBase * This,
            /* [annotation][in] */ 
            _In_  long fileScreenFlags);
        
        DECLSPEC_XFGVIRT(IFsrmFileScreenBase, CreateAction)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateAction )( 
            __RPC__in IFsrmFileScreenBase * This,
            /* [annotation][in] */ 
            _In_  FsrmActionType actionType,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmAction **action);
        
        DECLSPEC_XFGVIRT(IFsrmFileScreenBase, EnumActions)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EnumActions )( 
            __RPC__in IFsrmFileScreenBase * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmCollection **actions);
        
        END_INTERFACE
    } IFsrmFileScreenBaseVtbl;

    interface IFsrmFileScreenBase
    {
        CONST_VTBL struct IFsrmFileScreenBaseVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFsrmFileScreenBase_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFsrmFileScreenBase_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFsrmFileScreenBase_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFsrmFileScreenBase_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFsrmFileScreenBase_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFsrmFileScreenBase_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFsrmFileScreenBase_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IFsrmFileScreenBase_get_Id(This,id)	\
    ( (This)->lpVtbl -> get_Id(This,id) ) 

#define IFsrmFileScreenBase_get_Description(This,description)	\
    ( (This)->lpVtbl -> get_Description(This,description) ) 

#define IFsrmFileScreenBase_put_Description(This,description)	\
    ( (This)->lpVtbl -> put_Description(This,description) ) 

#define IFsrmFileScreenBase_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define IFsrmFileScreenBase_Commit(This)	\
    ( (This)->lpVtbl -> Commit(This) ) 


#define IFsrmFileScreenBase_get_BlockedFileGroups(This,blockList)	\
    ( (This)->lpVtbl -> get_BlockedFileGroups(This,blockList) ) 

#define IFsrmFileScreenBase_put_BlockedFileGroups(This,blockList)	\
    ( (This)->lpVtbl -> put_BlockedFileGroups(This,blockList) ) 

#define IFsrmFileScreenBase_get_FileScreenFlags(This,fileScreenFlags)	\
    ( (This)->lpVtbl -> get_FileScreenFlags(This,fileScreenFlags) ) 

#define IFsrmFileScreenBase_put_FileScreenFlags(This,fileScreenFlags)	\
    ( (This)->lpVtbl -> put_FileScreenFlags(This,fileScreenFlags) ) 

#define IFsrmFileScreenBase_CreateAction(This,actionType,action)	\
    ( (This)->lpVtbl -> CreateAction(This,actionType,action) ) 

#define IFsrmFileScreenBase_EnumActions(This,actions)	\
    ( (This)->lpVtbl -> EnumActions(This,actions) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFsrmFileScreenBase_INTERFACE_DEFINED__ */


#ifndef __IFsrmFileScreen_INTERFACE_DEFINED__
#define __IFsrmFileScreen_INTERFACE_DEFINED__

/* interface IFsrmFileScreen */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IFsrmFileScreen;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5f6325d3-ce88-4733-84c1-2d6aefc5ea07")
    IFsrmFileScreen : public IFsrmFileScreenBase
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Path( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *path) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SourceTemplateName( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *fileScreenTemplateName) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MatchesSourceTemplate( 
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *matches) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UserSid( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *userSid) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UserAccount( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *userAccount) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ApplyTemplate( 
            /* [annotation][in] */ 
            _In_  BSTR fileScreenTemplateName) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IFsrmFileScreenVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IFsrmFileScreen * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IFsrmFileScreen * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IFsrmFileScreen * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IFsrmFileScreen * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IFsrmFileScreen * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IFsrmFileScreen * This,
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
            IFsrmFileScreen * This,
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
        
        DECLSPEC_XFGVIRT(IFsrmObject, get_Id)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Id )( 
            __RPC__in IFsrmFileScreen * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  FSRM_OBJECT_ID *id);
        
        DECLSPEC_XFGVIRT(IFsrmObject, get_Description)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Description )( 
            __RPC__in IFsrmFileScreen * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *description);
        
        DECLSPEC_XFGVIRT(IFsrmObject, put_Description)
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Description )( 
            __RPC__in IFsrmFileScreen * This,
            /* [annotation][in] */ 
            _In_  BSTR description);
        
        DECLSPEC_XFGVIRT(IFsrmObject, Delete)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            __RPC__in IFsrmFileScreen * This);
        
        DECLSPEC_XFGVIRT(IFsrmObject, Commit)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Commit )( 
            __RPC__in IFsrmFileScreen * This);
        
        DECLSPEC_XFGVIRT(IFsrmFileScreenBase, get_BlockedFileGroups)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BlockedFileGroups )( 
            __RPC__in IFsrmFileScreen * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmMutableCollection **blockList);
        
        DECLSPEC_XFGVIRT(IFsrmFileScreenBase, put_BlockedFileGroups)
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BlockedFileGroups )( 
            __RPC__in IFsrmFileScreen * This,
            /* [annotation][in] */ 
            _In_  IFsrmMutableCollection *blockList);
        
        DECLSPEC_XFGVIRT(IFsrmFileScreenBase, get_FileScreenFlags)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FileScreenFlags )( 
            __RPC__in IFsrmFileScreen * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *fileScreenFlags);
        
        DECLSPEC_XFGVIRT(IFsrmFileScreenBase, put_FileScreenFlags)
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FileScreenFlags )( 
            __RPC__in IFsrmFileScreen * This,
            /* [annotation][in] */ 
            _In_  long fileScreenFlags);
        
        DECLSPEC_XFGVIRT(IFsrmFileScreenBase, CreateAction)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateAction )( 
            __RPC__in IFsrmFileScreen * This,
            /* [annotation][in] */ 
            _In_  FsrmActionType actionType,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmAction **action);
        
        DECLSPEC_XFGVIRT(IFsrmFileScreenBase, EnumActions)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EnumActions )( 
            __RPC__in IFsrmFileScreen * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmCollection **actions);
        
        DECLSPEC_XFGVIRT(IFsrmFileScreen, get_Path)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Path )( 
            __RPC__in IFsrmFileScreen * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *path);
        
        DECLSPEC_XFGVIRT(IFsrmFileScreen, get_SourceTemplateName)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SourceTemplateName )( 
            __RPC__in IFsrmFileScreen * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *fileScreenTemplateName);
        
        DECLSPEC_XFGVIRT(IFsrmFileScreen, get_MatchesSourceTemplate)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MatchesSourceTemplate )( 
            __RPC__in IFsrmFileScreen * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *matches);
        
        DECLSPEC_XFGVIRT(IFsrmFileScreen, get_UserSid)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UserSid )( 
            __RPC__in IFsrmFileScreen * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *userSid);
        
        DECLSPEC_XFGVIRT(IFsrmFileScreen, get_UserAccount)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UserAccount )( 
            __RPC__in IFsrmFileScreen * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *userAccount);
        
        DECLSPEC_XFGVIRT(IFsrmFileScreen, ApplyTemplate)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ApplyTemplate )( 
            __RPC__in IFsrmFileScreen * This,
            /* [annotation][in] */ 
            _In_  BSTR fileScreenTemplateName);
        
        END_INTERFACE
    } IFsrmFileScreenVtbl;

    interface IFsrmFileScreen
    {
        CONST_VTBL struct IFsrmFileScreenVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFsrmFileScreen_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFsrmFileScreen_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFsrmFileScreen_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFsrmFileScreen_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFsrmFileScreen_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFsrmFileScreen_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFsrmFileScreen_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IFsrmFileScreen_get_Id(This,id)	\
    ( (This)->lpVtbl -> get_Id(This,id) ) 

#define IFsrmFileScreen_get_Description(This,description)	\
    ( (This)->lpVtbl -> get_Description(This,description) ) 

#define IFsrmFileScreen_put_Description(This,description)	\
    ( (This)->lpVtbl -> put_Description(This,description) ) 

#define IFsrmFileScreen_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define IFsrmFileScreen_Commit(This)	\
    ( (This)->lpVtbl -> Commit(This) ) 


#define IFsrmFileScreen_get_BlockedFileGroups(This,blockList)	\
    ( (This)->lpVtbl -> get_BlockedFileGroups(This,blockList) ) 

#define IFsrmFileScreen_put_BlockedFileGroups(This,blockList)	\
    ( (This)->lpVtbl -> put_BlockedFileGroups(This,blockList) ) 

#define IFsrmFileScreen_get_FileScreenFlags(This,fileScreenFlags)	\
    ( (This)->lpVtbl -> get_FileScreenFlags(This,fileScreenFlags) ) 

#define IFsrmFileScreen_put_FileScreenFlags(This,fileScreenFlags)	\
    ( (This)->lpVtbl -> put_FileScreenFlags(This,fileScreenFlags) ) 

#define IFsrmFileScreen_CreateAction(This,actionType,action)	\
    ( (This)->lpVtbl -> CreateAction(This,actionType,action) ) 

#define IFsrmFileScreen_EnumActions(This,actions)	\
    ( (This)->lpVtbl -> EnumActions(This,actions) ) 


#define IFsrmFileScreen_get_Path(This,path)	\
    ( (This)->lpVtbl -> get_Path(This,path) ) 

#define IFsrmFileScreen_get_SourceTemplateName(This,fileScreenTemplateName)	\
    ( (This)->lpVtbl -> get_SourceTemplateName(This,fileScreenTemplateName) ) 

#define IFsrmFileScreen_get_MatchesSourceTemplate(This,matches)	\
    ( (This)->lpVtbl -> get_MatchesSourceTemplate(This,matches) ) 

#define IFsrmFileScreen_get_UserSid(This,userSid)	\
    ( (This)->lpVtbl -> get_UserSid(This,userSid) ) 

#define IFsrmFileScreen_get_UserAccount(This,userAccount)	\
    ( (This)->lpVtbl -> get_UserAccount(This,userAccount) ) 

#define IFsrmFileScreen_ApplyTemplate(This,fileScreenTemplateName)	\
    ( (This)->lpVtbl -> ApplyTemplate(This,fileScreenTemplateName) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFsrmFileScreen_INTERFACE_DEFINED__ */


#ifndef __IFsrmFileScreenException_INTERFACE_DEFINED__
#define __IFsrmFileScreenException_INTERFACE_DEFINED__

/* interface IFsrmFileScreenException */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IFsrmFileScreenException;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("bee7ce02-df77-4515-9389-78f01c5afc1a")
    IFsrmFileScreenException : public IFsrmObject
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Path( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *path) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AllowedFileGroups( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmMutableCollection **allowList) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AllowedFileGroups( 
            /* [annotation][in] */ 
            _In_  IFsrmMutableCollection *allowList) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IFsrmFileScreenExceptionVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IFsrmFileScreenException * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IFsrmFileScreenException * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IFsrmFileScreenException * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IFsrmFileScreenException * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IFsrmFileScreenException * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IFsrmFileScreenException * This,
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
            IFsrmFileScreenException * This,
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
        
        DECLSPEC_XFGVIRT(IFsrmObject, get_Id)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Id )( 
            __RPC__in IFsrmFileScreenException * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  FSRM_OBJECT_ID *id);
        
        DECLSPEC_XFGVIRT(IFsrmObject, get_Description)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Description )( 
            __RPC__in IFsrmFileScreenException * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *description);
        
        DECLSPEC_XFGVIRT(IFsrmObject, put_Description)
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Description )( 
            __RPC__in IFsrmFileScreenException * This,
            /* [annotation][in] */ 
            _In_  BSTR description);
        
        DECLSPEC_XFGVIRT(IFsrmObject, Delete)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            __RPC__in IFsrmFileScreenException * This);
        
        DECLSPEC_XFGVIRT(IFsrmObject, Commit)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Commit )( 
            __RPC__in IFsrmFileScreenException * This);
        
        DECLSPEC_XFGVIRT(IFsrmFileScreenException, get_Path)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Path )( 
            __RPC__in IFsrmFileScreenException * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *path);
        
        DECLSPEC_XFGVIRT(IFsrmFileScreenException, get_AllowedFileGroups)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AllowedFileGroups )( 
            __RPC__in IFsrmFileScreenException * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmMutableCollection **allowList);
        
        DECLSPEC_XFGVIRT(IFsrmFileScreenException, put_AllowedFileGroups)
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AllowedFileGroups )( 
            __RPC__in IFsrmFileScreenException * This,
            /* [annotation][in] */ 
            _In_  IFsrmMutableCollection *allowList);
        
        END_INTERFACE
    } IFsrmFileScreenExceptionVtbl;

    interface IFsrmFileScreenException
    {
        CONST_VTBL struct IFsrmFileScreenExceptionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFsrmFileScreenException_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFsrmFileScreenException_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFsrmFileScreenException_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFsrmFileScreenException_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFsrmFileScreenException_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFsrmFileScreenException_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFsrmFileScreenException_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IFsrmFileScreenException_get_Id(This,id)	\
    ( (This)->lpVtbl -> get_Id(This,id) ) 

#define IFsrmFileScreenException_get_Description(This,description)	\
    ( (This)->lpVtbl -> get_Description(This,description) ) 

#define IFsrmFileScreenException_put_Description(This,description)	\
    ( (This)->lpVtbl -> put_Description(This,description) ) 

#define IFsrmFileScreenException_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define IFsrmFileScreenException_Commit(This)	\
    ( (This)->lpVtbl -> Commit(This) ) 


#define IFsrmFileScreenException_get_Path(This,path)	\
    ( (This)->lpVtbl -> get_Path(This,path) ) 

#define IFsrmFileScreenException_get_AllowedFileGroups(This,allowList)	\
    ( (This)->lpVtbl -> get_AllowedFileGroups(This,allowList) ) 

#define IFsrmFileScreenException_put_AllowedFileGroups(This,allowList)	\
    ( (This)->lpVtbl -> put_AllowedFileGroups(This,allowList) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFsrmFileScreenException_INTERFACE_DEFINED__ */


#ifndef __IFsrmFileScreenManager_INTERFACE_DEFINED__
#define __IFsrmFileScreenManager_INTERFACE_DEFINED__

/* interface IFsrmFileScreenManager */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IFsrmFileScreenManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("ff4fa04e-5a94-4bda-a3a0-d5b4d3c52eba")
    IFsrmFileScreenManager : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActionVariables( 
            /* [annotation][retval][out] */ 
            _Out_retval_  SAFEARRAY * *variables) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActionVariableDescriptions( 
            /* [annotation][retval][out] */ 
            _Out_retval_  SAFEARRAY * *descriptions) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateFileScreen( 
            /* [annotation][in] */ 
            _In_  BSTR path,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmFileScreen **fileScreen) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetFileScreen( 
            /* [annotation][in] */ 
            _In_  BSTR path,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmFileScreen **fileScreen) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EnumFileScreens( 
            /* [annotation][defaultvalue][in] */ 
            _In_  BSTR path,
            /* [annotation][defaultvalue][in] */ 
            _In_  FsrmEnumOptions options,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmCommittableCollection **fileScreens) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateFileScreenException( 
            /* [annotation][in] */ 
            _In_  BSTR path,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmFileScreenException **fileScreenException) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetFileScreenException( 
            /* [annotation][in] */ 
            _In_  BSTR path,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmFileScreenException **fileScreenException) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EnumFileScreenExceptions( 
            /* [annotation][defaultvalue][in] */ 
            _In_  BSTR path,
            /* [annotation][defaultvalue][in] */ 
            _In_  FsrmEnumOptions options,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmCommittableCollection **fileScreenExceptions) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateFileScreenCollection( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmCommittableCollection **collection) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IFsrmFileScreenManagerVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IFsrmFileScreenManager * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IFsrmFileScreenManager * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IFsrmFileScreenManager * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IFsrmFileScreenManager * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IFsrmFileScreenManager * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IFsrmFileScreenManager * This,
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
            IFsrmFileScreenManager * This,
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
        
        DECLSPEC_XFGVIRT(IFsrmFileScreenManager, get_ActionVariables)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActionVariables )( 
            __RPC__in IFsrmFileScreenManager * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  SAFEARRAY * *variables);
        
        DECLSPEC_XFGVIRT(IFsrmFileScreenManager, get_ActionVariableDescriptions)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActionVariableDescriptions )( 
            __RPC__in IFsrmFileScreenManager * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  SAFEARRAY * *descriptions);
        
        DECLSPEC_XFGVIRT(IFsrmFileScreenManager, CreateFileScreen)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateFileScreen )( 
            __RPC__in IFsrmFileScreenManager * This,
            /* [annotation][in] */ 
            _In_  BSTR path,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmFileScreen **fileScreen);
        
        DECLSPEC_XFGVIRT(IFsrmFileScreenManager, GetFileScreen)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetFileScreen )( 
            __RPC__in IFsrmFileScreenManager * This,
            /* [annotation][in] */ 
            _In_  BSTR path,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmFileScreen **fileScreen);
        
        DECLSPEC_XFGVIRT(IFsrmFileScreenManager, EnumFileScreens)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EnumFileScreens )( 
            __RPC__in IFsrmFileScreenManager * This,
            /* [annotation][defaultvalue][in] */ 
            _In_  BSTR path,
            /* [annotation][defaultvalue][in] */ 
            _In_  FsrmEnumOptions options,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmCommittableCollection **fileScreens);
        
        DECLSPEC_XFGVIRT(IFsrmFileScreenManager, CreateFileScreenException)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateFileScreenException )( 
            __RPC__in IFsrmFileScreenManager * This,
            /* [annotation][in] */ 
            _In_  BSTR path,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmFileScreenException **fileScreenException);
        
        DECLSPEC_XFGVIRT(IFsrmFileScreenManager, GetFileScreenException)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetFileScreenException )( 
            __RPC__in IFsrmFileScreenManager * This,
            /* [annotation][in] */ 
            _In_  BSTR path,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmFileScreenException **fileScreenException);
        
        DECLSPEC_XFGVIRT(IFsrmFileScreenManager, EnumFileScreenExceptions)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EnumFileScreenExceptions )( 
            __RPC__in IFsrmFileScreenManager * This,
            /* [annotation][defaultvalue][in] */ 
            _In_  BSTR path,
            /* [annotation][defaultvalue][in] */ 
            _In_  FsrmEnumOptions options,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmCommittableCollection **fileScreenExceptions);
        
        DECLSPEC_XFGVIRT(IFsrmFileScreenManager, CreateFileScreenCollection)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateFileScreenCollection )( 
            __RPC__in IFsrmFileScreenManager * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmCommittableCollection **collection);
        
        END_INTERFACE
    } IFsrmFileScreenManagerVtbl;

    interface IFsrmFileScreenManager
    {
        CONST_VTBL struct IFsrmFileScreenManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFsrmFileScreenManager_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFsrmFileScreenManager_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFsrmFileScreenManager_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFsrmFileScreenManager_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFsrmFileScreenManager_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFsrmFileScreenManager_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFsrmFileScreenManager_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IFsrmFileScreenManager_get_ActionVariables(This,variables)	\
    ( (This)->lpVtbl -> get_ActionVariables(This,variables) ) 

#define IFsrmFileScreenManager_get_ActionVariableDescriptions(This,descriptions)	\
    ( (This)->lpVtbl -> get_ActionVariableDescriptions(This,descriptions) ) 

#define IFsrmFileScreenManager_CreateFileScreen(This,path,fileScreen)	\
    ( (This)->lpVtbl -> CreateFileScreen(This,path,fileScreen) ) 

#define IFsrmFileScreenManager_GetFileScreen(This,path,fileScreen)	\
    ( (This)->lpVtbl -> GetFileScreen(This,path,fileScreen) ) 

#define IFsrmFileScreenManager_EnumFileScreens(This,path,options,fileScreens)	\
    ( (This)->lpVtbl -> EnumFileScreens(This,path,options,fileScreens) ) 

#define IFsrmFileScreenManager_CreateFileScreenException(This,path,fileScreenException)	\
    ( (This)->lpVtbl -> CreateFileScreenException(This,path,fileScreenException) ) 

#define IFsrmFileScreenManager_GetFileScreenException(This,path,fileScreenException)	\
    ( (This)->lpVtbl -> GetFileScreenException(This,path,fileScreenException) ) 

#define IFsrmFileScreenManager_EnumFileScreenExceptions(This,path,options,fileScreenExceptions)	\
    ( (This)->lpVtbl -> EnumFileScreenExceptions(This,path,options,fileScreenExceptions) ) 

#define IFsrmFileScreenManager_CreateFileScreenCollection(This,collection)	\
    ( (This)->lpVtbl -> CreateFileScreenCollection(This,collection) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFsrmFileScreenManager_INTERFACE_DEFINED__ */


#ifndef __IFsrmFileScreenTemplate_INTERFACE_DEFINED__
#define __IFsrmFileScreenTemplate_INTERFACE_DEFINED__

/* interface IFsrmFileScreenTemplate */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IFsrmFileScreenTemplate;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("205bebf8-dd93-452a-95a6-32b566b35828")
    IFsrmFileScreenTemplate : public IFsrmFileScreenBase
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *name) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [annotation][in] */ 
            _In_  BSTR name) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CopyTemplate( 
            /* [annotation][in] */ 
            _In_  BSTR fileScreenTemplateName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CommitAndUpdateDerived( 
            /* [annotation][in] */ 
            _In_  FsrmCommitOptions commitOptions,
            /* [annotation][in] */ 
            _In_  FsrmTemplateApplyOptions applyOptions,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmDerivedObjectsResult **derivedObjectsResult) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IFsrmFileScreenTemplateVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IFsrmFileScreenTemplate * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IFsrmFileScreenTemplate * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IFsrmFileScreenTemplate * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IFsrmFileScreenTemplate * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IFsrmFileScreenTemplate * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IFsrmFileScreenTemplate * This,
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
            IFsrmFileScreenTemplate * This,
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
        
        DECLSPEC_XFGVIRT(IFsrmObject, get_Id)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Id )( 
            __RPC__in IFsrmFileScreenTemplate * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  FSRM_OBJECT_ID *id);
        
        DECLSPEC_XFGVIRT(IFsrmObject, get_Description)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Description )( 
            __RPC__in IFsrmFileScreenTemplate * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *description);
        
        DECLSPEC_XFGVIRT(IFsrmObject, put_Description)
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Description )( 
            __RPC__in IFsrmFileScreenTemplate * This,
            /* [annotation][in] */ 
            _In_  BSTR description);
        
        DECLSPEC_XFGVIRT(IFsrmObject, Delete)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            __RPC__in IFsrmFileScreenTemplate * This);
        
        DECLSPEC_XFGVIRT(IFsrmObject, Commit)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Commit )( 
            __RPC__in IFsrmFileScreenTemplate * This);
        
        DECLSPEC_XFGVIRT(IFsrmFileScreenBase, get_BlockedFileGroups)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BlockedFileGroups )( 
            __RPC__in IFsrmFileScreenTemplate * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmMutableCollection **blockList);
        
        DECLSPEC_XFGVIRT(IFsrmFileScreenBase, put_BlockedFileGroups)
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BlockedFileGroups )( 
            __RPC__in IFsrmFileScreenTemplate * This,
            /* [annotation][in] */ 
            _In_  IFsrmMutableCollection *blockList);
        
        DECLSPEC_XFGVIRT(IFsrmFileScreenBase, get_FileScreenFlags)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FileScreenFlags )( 
            __RPC__in IFsrmFileScreenTemplate * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *fileScreenFlags);
        
        DECLSPEC_XFGVIRT(IFsrmFileScreenBase, put_FileScreenFlags)
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FileScreenFlags )( 
            __RPC__in IFsrmFileScreenTemplate * This,
            /* [annotation][in] */ 
            _In_  long fileScreenFlags);
        
        DECLSPEC_XFGVIRT(IFsrmFileScreenBase, CreateAction)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateAction )( 
            __RPC__in IFsrmFileScreenTemplate * This,
            /* [annotation][in] */ 
            _In_  FsrmActionType actionType,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmAction **action);
        
        DECLSPEC_XFGVIRT(IFsrmFileScreenBase, EnumActions)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EnumActions )( 
            __RPC__in IFsrmFileScreenTemplate * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmCollection **actions);
        
        DECLSPEC_XFGVIRT(IFsrmFileScreenTemplate, get_Name)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            __RPC__in IFsrmFileScreenTemplate * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *name);
        
        DECLSPEC_XFGVIRT(IFsrmFileScreenTemplate, put_Name)
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            __RPC__in IFsrmFileScreenTemplate * This,
            /* [annotation][in] */ 
            _In_  BSTR name);
        
        DECLSPEC_XFGVIRT(IFsrmFileScreenTemplate, CopyTemplate)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CopyTemplate )( 
            __RPC__in IFsrmFileScreenTemplate * This,
            /* [annotation][in] */ 
            _In_  BSTR fileScreenTemplateName);
        
        DECLSPEC_XFGVIRT(IFsrmFileScreenTemplate, CommitAndUpdateDerived)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CommitAndUpdateDerived )( 
            __RPC__in IFsrmFileScreenTemplate * This,
            /* [annotation][in] */ 
            _In_  FsrmCommitOptions commitOptions,
            /* [annotation][in] */ 
            _In_  FsrmTemplateApplyOptions applyOptions,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmDerivedObjectsResult **derivedObjectsResult);
        
        END_INTERFACE
    } IFsrmFileScreenTemplateVtbl;

    interface IFsrmFileScreenTemplate
    {
        CONST_VTBL struct IFsrmFileScreenTemplateVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFsrmFileScreenTemplate_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFsrmFileScreenTemplate_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFsrmFileScreenTemplate_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFsrmFileScreenTemplate_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFsrmFileScreenTemplate_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFsrmFileScreenTemplate_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFsrmFileScreenTemplate_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IFsrmFileScreenTemplate_get_Id(This,id)	\
    ( (This)->lpVtbl -> get_Id(This,id) ) 

#define IFsrmFileScreenTemplate_get_Description(This,description)	\
    ( (This)->lpVtbl -> get_Description(This,description) ) 

#define IFsrmFileScreenTemplate_put_Description(This,description)	\
    ( (This)->lpVtbl -> put_Description(This,description) ) 

#define IFsrmFileScreenTemplate_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define IFsrmFileScreenTemplate_Commit(This)	\
    ( (This)->lpVtbl -> Commit(This) ) 


#define IFsrmFileScreenTemplate_get_BlockedFileGroups(This,blockList)	\
    ( (This)->lpVtbl -> get_BlockedFileGroups(This,blockList) ) 

#define IFsrmFileScreenTemplate_put_BlockedFileGroups(This,blockList)	\
    ( (This)->lpVtbl -> put_BlockedFileGroups(This,blockList) ) 

#define IFsrmFileScreenTemplate_get_FileScreenFlags(This,fileScreenFlags)	\
    ( (This)->lpVtbl -> get_FileScreenFlags(This,fileScreenFlags) ) 

#define IFsrmFileScreenTemplate_put_FileScreenFlags(This,fileScreenFlags)	\
    ( (This)->lpVtbl -> put_FileScreenFlags(This,fileScreenFlags) ) 

#define IFsrmFileScreenTemplate_CreateAction(This,actionType,action)	\
    ( (This)->lpVtbl -> CreateAction(This,actionType,action) ) 

#define IFsrmFileScreenTemplate_EnumActions(This,actions)	\
    ( (This)->lpVtbl -> EnumActions(This,actions) ) 


#define IFsrmFileScreenTemplate_get_Name(This,name)	\
    ( (This)->lpVtbl -> get_Name(This,name) ) 

#define IFsrmFileScreenTemplate_put_Name(This,name)	\
    ( (This)->lpVtbl -> put_Name(This,name) ) 

#define IFsrmFileScreenTemplate_CopyTemplate(This,fileScreenTemplateName)	\
    ( (This)->lpVtbl -> CopyTemplate(This,fileScreenTemplateName) ) 

#define IFsrmFileScreenTemplate_CommitAndUpdateDerived(This,commitOptions,applyOptions,derivedObjectsResult)	\
    ( (This)->lpVtbl -> CommitAndUpdateDerived(This,commitOptions,applyOptions,derivedObjectsResult) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFsrmFileScreenTemplate_INTERFACE_DEFINED__ */


#ifndef __IFsrmFileScreenTemplateImported_INTERFACE_DEFINED__
#define __IFsrmFileScreenTemplateImported_INTERFACE_DEFINED__

/* interface IFsrmFileScreenTemplateImported */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IFsrmFileScreenTemplateImported;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("e1010359-3e5d-4ecd-9fe4-ef48622fdf30")
    IFsrmFileScreenTemplateImported : public IFsrmFileScreenTemplate
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OverwriteOnCommit( 
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *overwrite) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_OverwriteOnCommit( 
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL overwrite) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IFsrmFileScreenTemplateImportedVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IFsrmFileScreenTemplateImported * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IFsrmFileScreenTemplateImported * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IFsrmFileScreenTemplateImported * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IFsrmFileScreenTemplateImported * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IFsrmFileScreenTemplateImported * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IFsrmFileScreenTemplateImported * This,
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
            IFsrmFileScreenTemplateImported * This,
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
        
        DECLSPEC_XFGVIRT(IFsrmObject, get_Id)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Id )( 
            __RPC__in IFsrmFileScreenTemplateImported * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  FSRM_OBJECT_ID *id);
        
        DECLSPEC_XFGVIRT(IFsrmObject, get_Description)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Description )( 
            __RPC__in IFsrmFileScreenTemplateImported * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *description);
        
        DECLSPEC_XFGVIRT(IFsrmObject, put_Description)
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Description )( 
            __RPC__in IFsrmFileScreenTemplateImported * This,
            /* [annotation][in] */ 
            _In_  BSTR description);
        
        DECLSPEC_XFGVIRT(IFsrmObject, Delete)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            __RPC__in IFsrmFileScreenTemplateImported * This);
        
        DECLSPEC_XFGVIRT(IFsrmObject, Commit)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Commit )( 
            __RPC__in IFsrmFileScreenTemplateImported * This);
        
        DECLSPEC_XFGVIRT(IFsrmFileScreenBase, get_BlockedFileGroups)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BlockedFileGroups )( 
            __RPC__in IFsrmFileScreenTemplateImported * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmMutableCollection **blockList);
        
        DECLSPEC_XFGVIRT(IFsrmFileScreenBase, put_BlockedFileGroups)
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BlockedFileGroups )( 
            __RPC__in IFsrmFileScreenTemplateImported * This,
            /* [annotation][in] */ 
            _In_  IFsrmMutableCollection *blockList);
        
        DECLSPEC_XFGVIRT(IFsrmFileScreenBase, get_FileScreenFlags)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FileScreenFlags )( 
            __RPC__in IFsrmFileScreenTemplateImported * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *fileScreenFlags);
        
        DECLSPEC_XFGVIRT(IFsrmFileScreenBase, put_FileScreenFlags)
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FileScreenFlags )( 
            __RPC__in IFsrmFileScreenTemplateImported * This,
            /* [annotation][in] */ 
            _In_  long fileScreenFlags);
        
        DECLSPEC_XFGVIRT(IFsrmFileScreenBase, CreateAction)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateAction )( 
            __RPC__in IFsrmFileScreenTemplateImported * This,
            /* [annotation][in] */ 
            _In_  FsrmActionType actionType,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmAction **action);
        
        DECLSPEC_XFGVIRT(IFsrmFileScreenBase, EnumActions)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EnumActions )( 
            __RPC__in IFsrmFileScreenTemplateImported * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmCollection **actions);
        
        DECLSPEC_XFGVIRT(IFsrmFileScreenTemplate, get_Name)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            __RPC__in IFsrmFileScreenTemplateImported * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *name);
        
        DECLSPEC_XFGVIRT(IFsrmFileScreenTemplate, put_Name)
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            __RPC__in IFsrmFileScreenTemplateImported * This,
            /* [annotation][in] */ 
            _In_  BSTR name);
        
        DECLSPEC_XFGVIRT(IFsrmFileScreenTemplate, CopyTemplate)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CopyTemplate )( 
            __RPC__in IFsrmFileScreenTemplateImported * This,
            /* [annotation][in] */ 
            _In_  BSTR fileScreenTemplateName);
        
        DECLSPEC_XFGVIRT(IFsrmFileScreenTemplate, CommitAndUpdateDerived)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CommitAndUpdateDerived )( 
            __RPC__in IFsrmFileScreenTemplateImported * This,
            /* [annotation][in] */ 
            _In_  FsrmCommitOptions commitOptions,
            /* [annotation][in] */ 
            _In_  FsrmTemplateApplyOptions applyOptions,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmDerivedObjectsResult **derivedObjectsResult);
        
        DECLSPEC_XFGVIRT(IFsrmFileScreenTemplateImported, get_OverwriteOnCommit)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OverwriteOnCommit )( 
            __RPC__in IFsrmFileScreenTemplateImported * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *overwrite);
        
        DECLSPEC_XFGVIRT(IFsrmFileScreenTemplateImported, put_OverwriteOnCommit)
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OverwriteOnCommit )( 
            __RPC__in IFsrmFileScreenTemplateImported * This,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL overwrite);
        
        END_INTERFACE
    } IFsrmFileScreenTemplateImportedVtbl;

    interface IFsrmFileScreenTemplateImported
    {
        CONST_VTBL struct IFsrmFileScreenTemplateImportedVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFsrmFileScreenTemplateImported_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFsrmFileScreenTemplateImported_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFsrmFileScreenTemplateImported_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFsrmFileScreenTemplateImported_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFsrmFileScreenTemplateImported_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFsrmFileScreenTemplateImported_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFsrmFileScreenTemplateImported_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IFsrmFileScreenTemplateImported_get_Id(This,id)	\
    ( (This)->lpVtbl -> get_Id(This,id) ) 

#define IFsrmFileScreenTemplateImported_get_Description(This,description)	\
    ( (This)->lpVtbl -> get_Description(This,description) ) 

#define IFsrmFileScreenTemplateImported_put_Description(This,description)	\
    ( (This)->lpVtbl -> put_Description(This,description) ) 

#define IFsrmFileScreenTemplateImported_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define IFsrmFileScreenTemplateImported_Commit(This)	\
    ( (This)->lpVtbl -> Commit(This) ) 


#define IFsrmFileScreenTemplateImported_get_BlockedFileGroups(This,blockList)	\
    ( (This)->lpVtbl -> get_BlockedFileGroups(This,blockList) ) 

#define IFsrmFileScreenTemplateImported_put_BlockedFileGroups(This,blockList)	\
    ( (This)->lpVtbl -> put_BlockedFileGroups(This,blockList) ) 

#define IFsrmFileScreenTemplateImported_get_FileScreenFlags(This,fileScreenFlags)	\
    ( (This)->lpVtbl -> get_FileScreenFlags(This,fileScreenFlags) ) 

#define IFsrmFileScreenTemplateImported_put_FileScreenFlags(This,fileScreenFlags)	\
    ( (This)->lpVtbl -> put_FileScreenFlags(This,fileScreenFlags) ) 

#define IFsrmFileScreenTemplateImported_CreateAction(This,actionType,action)	\
    ( (This)->lpVtbl -> CreateAction(This,actionType,action) ) 

#define IFsrmFileScreenTemplateImported_EnumActions(This,actions)	\
    ( (This)->lpVtbl -> EnumActions(This,actions) ) 


#define IFsrmFileScreenTemplateImported_get_Name(This,name)	\
    ( (This)->lpVtbl -> get_Name(This,name) ) 

#define IFsrmFileScreenTemplateImported_put_Name(This,name)	\
    ( (This)->lpVtbl -> put_Name(This,name) ) 

#define IFsrmFileScreenTemplateImported_CopyTemplate(This,fileScreenTemplateName)	\
    ( (This)->lpVtbl -> CopyTemplate(This,fileScreenTemplateName) ) 

#define IFsrmFileScreenTemplateImported_CommitAndUpdateDerived(This,commitOptions,applyOptions,derivedObjectsResult)	\
    ( (This)->lpVtbl -> CommitAndUpdateDerived(This,commitOptions,applyOptions,derivedObjectsResult) ) 


#define IFsrmFileScreenTemplateImported_get_OverwriteOnCommit(This,overwrite)	\
    ( (This)->lpVtbl -> get_OverwriteOnCommit(This,overwrite) ) 

#define IFsrmFileScreenTemplateImported_put_OverwriteOnCommit(This,overwrite)	\
    ( (This)->lpVtbl -> put_OverwriteOnCommit(This,overwrite) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFsrmFileScreenTemplateImported_INTERFACE_DEFINED__ */


#ifndef __IFsrmFileScreenTemplateManager_INTERFACE_DEFINED__
#define __IFsrmFileScreenTemplateManager_INTERFACE_DEFINED__

/* interface IFsrmFileScreenTemplateManager */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IFsrmFileScreenTemplateManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("cfe36cba-1949-4e74-a14f-f1d580ceaf13")
    IFsrmFileScreenTemplateManager : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateTemplate( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmFileScreenTemplate **fileScreenTemplate) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetTemplate( 
            /* [annotation][in] */ 
            _In_  BSTR name,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmFileScreenTemplate **fileScreenTemplate) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EnumTemplates( 
            /* [annotation][defaultvalue][in] */ 
            _In_  FsrmEnumOptions options,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmCommittableCollection **fileScreenTemplates) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ExportTemplates( 
            /* [annotation][defaultvalue][in] */ 
            _In_  VARIANT *fileScreenTemplateNamesArray,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *serializedFileScreenTemplates) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ImportTemplates( 
            /* [annotation][in] */ 
            _In_  BSTR serializedFileScreenTemplates,
            /* [annotation][defaultvalue][in] */ 
            _In_  VARIANT *fileScreenTemplateNamesArray,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmCommittableCollection **fileScreenTemplates) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IFsrmFileScreenTemplateManagerVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IFsrmFileScreenTemplateManager * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IFsrmFileScreenTemplateManager * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IFsrmFileScreenTemplateManager * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IFsrmFileScreenTemplateManager * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IFsrmFileScreenTemplateManager * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IFsrmFileScreenTemplateManager * This,
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
            IFsrmFileScreenTemplateManager * This,
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
        
        DECLSPEC_XFGVIRT(IFsrmFileScreenTemplateManager, CreateTemplate)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateTemplate )( 
            __RPC__in IFsrmFileScreenTemplateManager * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmFileScreenTemplate **fileScreenTemplate);
        
        DECLSPEC_XFGVIRT(IFsrmFileScreenTemplateManager, GetTemplate)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetTemplate )( 
            __RPC__in IFsrmFileScreenTemplateManager * This,
            /* [annotation][in] */ 
            _In_  BSTR name,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmFileScreenTemplate **fileScreenTemplate);
        
        DECLSPEC_XFGVIRT(IFsrmFileScreenTemplateManager, EnumTemplates)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EnumTemplates )( 
            __RPC__in IFsrmFileScreenTemplateManager * This,
            /* [annotation][defaultvalue][in] */ 
            _In_  FsrmEnumOptions options,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmCommittableCollection **fileScreenTemplates);
        
        DECLSPEC_XFGVIRT(IFsrmFileScreenTemplateManager, ExportTemplates)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ExportTemplates )( 
            __RPC__in IFsrmFileScreenTemplateManager * This,
            /* [annotation][defaultvalue][in] */ 
            _In_  VARIANT *fileScreenTemplateNamesArray,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *serializedFileScreenTemplates);
        
        DECLSPEC_XFGVIRT(IFsrmFileScreenTemplateManager, ImportTemplates)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ImportTemplates )( 
            __RPC__in IFsrmFileScreenTemplateManager * This,
            /* [annotation][in] */ 
            _In_  BSTR serializedFileScreenTemplates,
            /* [annotation][defaultvalue][in] */ 
            _In_  VARIANT *fileScreenTemplateNamesArray,
            /* [annotation][retval][out] */ 
            _Out_retval_  IFsrmCommittableCollection **fileScreenTemplates);
        
        END_INTERFACE
    } IFsrmFileScreenTemplateManagerVtbl;

    interface IFsrmFileScreenTemplateManager
    {
        CONST_VTBL struct IFsrmFileScreenTemplateManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFsrmFileScreenTemplateManager_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFsrmFileScreenTemplateManager_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFsrmFileScreenTemplateManager_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFsrmFileScreenTemplateManager_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFsrmFileScreenTemplateManager_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFsrmFileScreenTemplateManager_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFsrmFileScreenTemplateManager_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IFsrmFileScreenTemplateManager_CreateTemplate(This,fileScreenTemplate)	\
    ( (This)->lpVtbl -> CreateTemplate(This,fileScreenTemplate) ) 

#define IFsrmFileScreenTemplateManager_GetTemplate(This,name,fileScreenTemplate)	\
    ( (This)->lpVtbl -> GetTemplate(This,name,fileScreenTemplate) ) 

#define IFsrmFileScreenTemplateManager_EnumTemplates(This,options,fileScreenTemplates)	\
    ( (This)->lpVtbl -> EnumTemplates(This,options,fileScreenTemplates) ) 

#define IFsrmFileScreenTemplateManager_ExportTemplates(This,fileScreenTemplateNamesArray,serializedFileScreenTemplates)	\
    ( (This)->lpVtbl -> ExportTemplates(This,fileScreenTemplateNamesArray,serializedFileScreenTemplates) ) 

#define IFsrmFileScreenTemplateManager_ImportTemplates(This,serializedFileScreenTemplates,fileScreenTemplateNamesArray,fileScreenTemplates)	\
    ( (This)->lpVtbl -> ImportTemplates(This,serializedFileScreenTemplates,fileScreenTemplateNamesArray,fileScreenTemplates) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFsrmFileScreenTemplateManager_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_fsrmscreen_0000_0010 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_fsrmscreen_0000_0010_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_fsrmscreen_0000_0010_v0_0_s_ifspec;

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


