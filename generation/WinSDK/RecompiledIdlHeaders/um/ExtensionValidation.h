

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

#ifndef __extensionvalidation_h__
#define __extensionvalidation_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IExtensionValidation_FWD_DEFINED__
#define __IExtensionValidation_FWD_DEFINED__
typedef interface IExtensionValidation IExtensionValidation;

#endif 	/* __IExtensionValidation_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "Mshtml.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_extensionvalidation_0000_0000 */
/* [local] */ 

/*******************************************************
 *                                                     *
 *     Copyright (C) Microsoft. All rights reserved.   *
 *                                                     *
 *******************************************************/
#ifdef _MSC_VER
#pragma once
#endif

#pragma comment(lib,"uuid.lib")

#include <winapifamily.h>
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
typedef 
enum ExtensionValidationContexts
    {
        ExtensionValidationContextNone	= 0,
        ExtensionValidationContextDynamic	= 0x1,
        ExtensionValidationContextParsed	= 0x2
    } 	ExtensionValidationContexts;

typedef 
enum ExtensionValidationResults
    {
        ExtensionValidationResultNone	= 0,
        ExtensionValidationResultDoNotInstantiate	= 0x1,
        ExtensionValidationResultArrestPageLoad	= 0x2
    } 	ExtensionValidationResults;



extern RPC_IF_HANDLE __MIDL_itf_extensionvalidation_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_extensionvalidation_0000_0000_v0_0_s_ifspec;

#ifndef __IExtensionValidation_INTERFACE_DEFINED__
#define __IExtensionValidation_INTERFACE_DEFINED__

/* interface IExtensionValidation */
/* [uuid][unique][object][local] */ 


EXTERN_C const IID IID_IExtensionValidation;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7d33f73d-8525-4e0f-87db-830288baff44")
    IExtensionValidation : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Validate( 
            /* [annotation][in] */ 
            _In_  REFGUID extensionGuid,
            /* [annotation][string][in] */ 
            _In_  LPWSTR extensionModulePath,
            /* [annotation][in] */ 
            _In_  DWORD extensionFileVersionMS,
            /* [annotation][in] */ 
            _In_  DWORD extensionFileVersionLS,
            /* [annotation][in] */ 
            _In_  IHTMLDocument2 *htmlDocumentTop,
            /* [annotation][in] */ 
            _In_  IHTMLDocument2 *htmlDocumentSubframe,
            /* [annotation][in] */ 
            _In_  IHTMLElement *htmlElement,
            /* [annotation][in] */ 
            _In_  ExtensionValidationContexts contexts,
            /* [annotation][out] */ 
            _Out_  ExtensionValidationResults *results) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DisplayName( 
            /* [annotation][string][out] */ 
            _Out_  LPWSTR *displayName) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IExtensionValidationVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IExtensionValidation * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IExtensionValidation * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IExtensionValidation * This);
        
        HRESULT ( STDMETHODCALLTYPE *Validate )( 
            IExtensionValidation * This,
            /* [annotation][in] */ 
            _In_  REFGUID extensionGuid,
            /* [annotation][string][in] */ 
            _In_  LPWSTR extensionModulePath,
            /* [annotation][in] */ 
            _In_  DWORD extensionFileVersionMS,
            /* [annotation][in] */ 
            _In_  DWORD extensionFileVersionLS,
            /* [annotation][in] */ 
            _In_  IHTMLDocument2 *htmlDocumentTop,
            /* [annotation][in] */ 
            _In_  IHTMLDocument2 *htmlDocumentSubframe,
            /* [annotation][in] */ 
            _In_  IHTMLElement *htmlElement,
            /* [annotation][in] */ 
            _In_  ExtensionValidationContexts contexts,
            /* [annotation][out] */ 
            _Out_  ExtensionValidationResults *results);
        
        HRESULT ( STDMETHODCALLTYPE *DisplayName )( 
            IExtensionValidation * This,
            /* [annotation][string][out] */ 
            _Out_  LPWSTR *displayName);
        
        END_INTERFACE
    } IExtensionValidationVtbl;

    interface IExtensionValidation
    {
        CONST_VTBL struct IExtensionValidationVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IExtensionValidation_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IExtensionValidation_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IExtensionValidation_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IExtensionValidation_Validate(This,extensionGuid,extensionModulePath,extensionFileVersionMS,extensionFileVersionLS,htmlDocumentTop,htmlDocumentSubframe,htmlElement,contexts,results)	\
    ( (This)->lpVtbl -> Validate(This,extensionGuid,extensionModulePath,extensionFileVersionMS,extensionFileVersionLS,htmlDocumentTop,htmlDocumentSubframe,htmlElement,contexts,results) ) 

#define IExtensionValidation_DisplayName(This,displayName)	\
    ( (This)->lpVtbl -> DisplayName(This,displayName) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IExtensionValidation_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_extensionvalidation_0000_0001 */
/* [local] */ 

EXTERN_C GUID CATID_ExtensionValidation;
#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_extensionvalidation_0000_0001_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_extensionvalidation_0000_0001_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


