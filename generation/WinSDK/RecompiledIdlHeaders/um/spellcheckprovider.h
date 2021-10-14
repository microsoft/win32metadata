

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

#ifndef __spellcheckprovider_h__
#define __spellcheckprovider_h__

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

#ifndef __ISpellCheckProvider_FWD_DEFINED__
#define __ISpellCheckProvider_FWD_DEFINED__
typedef interface ISpellCheckProvider ISpellCheckProvider;

#endif 	/* __ISpellCheckProvider_FWD_DEFINED__ */


#ifndef __IComprehensiveSpellCheckProvider_FWD_DEFINED__
#define __IComprehensiveSpellCheckProvider_FWD_DEFINED__
typedef interface IComprehensiveSpellCheckProvider IComprehensiveSpellCheckProvider;

#endif 	/* __IComprehensiveSpellCheckProvider_FWD_DEFINED__ */


#ifndef __ISpellCheckProviderFactory_FWD_DEFINED__
#define __ISpellCheckProviderFactory_FWD_DEFINED__
typedef interface ISpellCheckProviderFactory ISpellCheckProviderFactory;

#endif 	/* __ISpellCheckProviderFactory_FWD_DEFINED__ */


/* header files for imported files */
#include "SpellCheck.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_spellcheckprovider_0000_0000 */
/* [local] */ 

// Copyright (c) Microsoft Corporation. All Rights Reserved.
#include <winapifamily.h>
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
#ifndef MIN_SPELLING_NTDDI
#define MIN_SPELLING_NTDDI NTDDI_WIN8
#endif
#if NTDDI_VERSION >= MIN_SPELLING_NTDDI


extern RPC_IF_HANDLE __MIDL_itf_spellcheckprovider_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_spellcheckprovider_0000_0000_v0_0_s_ifspec;

#ifndef __ISpellCheckProvider_INTERFACE_DEFINED__
#define __ISpellCheckProvider_INTERFACE_DEFINED__

/* interface ISpellCheckProvider */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_ISpellCheckProvider;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("73E976E0-8ED4-4EB1-80D7-1BE0A16B0C38")
    ISpellCheckProvider : public IUnknown
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_LanguageTag( 
            /* [annotation][retval][out] */ 
            _Out_retval_  LPWSTR *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Check( 
            /* [annotation][in] */ 
            _In_  LPCWSTR text,
            /* [annotation][retval][out] */ 
            _Out_retval_  IEnumSpellingError **value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Suggest( 
            /* [annotation][in] */ 
            _In_  LPCWSTR word,
            /* [annotation][retval][out] */ 
            _Out_retval_  IEnumString **value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetOptionValue( 
            /* [annotation][in] */ 
            _In_  LPCWSTR optionId,
            /* [annotation][retval][out] */ 
            _Out_retval_  BYTE *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetOptionValue( 
            /* [annotation][in] */ 
            _In_  LPCWSTR optionId,
            /* [annotation][in] */ 
            _In_  BYTE value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_OptionIds( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IEnumString **value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Id( 
            /* [annotation][retval][out] */ 
            _Out_retval_  LPWSTR *value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_LocalizedName( 
            /* [annotation][retval][out] */ 
            _Out_retval_  LPWSTR *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetOptionDescription( 
            /* [annotation][in] */ 
            _In_  LPCWSTR optionId,
            /* [annotation][retval][out] */ 
            _Out_retval_  IOptionDescription **value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InitializeWordlist( 
            /* [annotation][in] */ 
            _In_  WORDLIST_TYPE wordlistType,
            /* [annotation][in] */ 
            _In_  IEnumString *words) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpellCheckProviderVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpellCheckProvider * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpellCheckProvider * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpellCheckProvider * This);
        
        DECLSPEC_XFGVIRT(ISpellCheckProvider, get_LanguageTag)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_LanguageTag )( 
            __RPC__in ISpellCheckProvider * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  LPWSTR *value);
        
        DECLSPEC_XFGVIRT(ISpellCheckProvider, Check)
        HRESULT ( STDMETHODCALLTYPE *Check )( 
            __RPC__in ISpellCheckProvider * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR text,
            /* [annotation][retval][out] */ 
            _Out_retval_  IEnumSpellingError **value);
        
        DECLSPEC_XFGVIRT(ISpellCheckProvider, Suggest)
        HRESULT ( STDMETHODCALLTYPE *Suggest )( 
            __RPC__in ISpellCheckProvider * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR word,
            /* [annotation][retval][out] */ 
            _Out_retval_  IEnumString **value);
        
        DECLSPEC_XFGVIRT(ISpellCheckProvider, GetOptionValue)
        HRESULT ( STDMETHODCALLTYPE *GetOptionValue )( 
            __RPC__in ISpellCheckProvider * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR optionId,
            /* [annotation][retval][out] */ 
            _Out_retval_  BYTE *value);
        
        DECLSPEC_XFGVIRT(ISpellCheckProvider, SetOptionValue)
        HRESULT ( STDMETHODCALLTYPE *SetOptionValue )( 
            __RPC__in ISpellCheckProvider * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR optionId,
            /* [annotation][in] */ 
            _In_  BYTE value);
        
        DECLSPEC_XFGVIRT(ISpellCheckProvider, get_OptionIds)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_OptionIds )( 
            __RPC__in ISpellCheckProvider * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IEnumString **value);
        
        DECLSPEC_XFGVIRT(ISpellCheckProvider, get_Id)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Id )( 
            __RPC__in ISpellCheckProvider * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  LPWSTR *value);
        
        DECLSPEC_XFGVIRT(ISpellCheckProvider, get_LocalizedName)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_LocalizedName )( 
            __RPC__in ISpellCheckProvider * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  LPWSTR *value);
        
        DECLSPEC_XFGVIRT(ISpellCheckProvider, GetOptionDescription)
        HRESULT ( STDMETHODCALLTYPE *GetOptionDescription )( 
            __RPC__in ISpellCheckProvider * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR optionId,
            /* [annotation][retval][out] */ 
            _Out_retval_  IOptionDescription **value);
        
        DECLSPEC_XFGVIRT(ISpellCheckProvider, InitializeWordlist)
        HRESULT ( STDMETHODCALLTYPE *InitializeWordlist )( 
            __RPC__in ISpellCheckProvider * This,
            /* [annotation][in] */ 
            _In_  WORDLIST_TYPE wordlistType,
            /* [annotation][in] */ 
            _In_  IEnumString *words);
        
        END_INTERFACE
    } ISpellCheckProviderVtbl;

    interface ISpellCheckProvider
    {
        CONST_VTBL struct ISpellCheckProviderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpellCheckProvider_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpellCheckProvider_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpellCheckProvider_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpellCheckProvider_get_LanguageTag(This,value)	\
    ( (This)->lpVtbl -> get_LanguageTag(This,value) ) 

#define ISpellCheckProvider_Check(This,text,value)	\
    ( (This)->lpVtbl -> Check(This,text,value) ) 

#define ISpellCheckProvider_Suggest(This,word,value)	\
    ( (This)->lpVtbl -> Suggest(This,word,value) ) 

#define ISpellCheckProvider_GetOptionValue(This,optionId,value)	\
    ( (This)->lpVtbl -> GetOptionValue(This,optionId,value) ) 

#define ISpellCheckProvider_SetOptionValue(This,optionId,value)	\
    ( (This)->lpVtbl -> SetOptionValue(This,optionId,value) ) 

#define ISpellCheckProvider_get_OptionIds(This,value)	\
    ( (This)->lpVtbl -> get_OptionIds(This,value) ) 

#define ISpellCheckProvider_get_Id(This,value)	\
    ( (This)->lpVtbl -> get_Id(This,value) ) 

#define ISpellCheckProvider_get_LocalizedName(This,value)	\
    ( (This)->lpVtbl -> get_LocalizedName(This,value) ) 

#define ISpellCheckProvider_GetOptionDescription(This,optionId,value)	\
    ( (This)->lpVtbl -> GetOptionDescription(This,optionId,value) ) 

#define ISpellCheckProvider_InitializeWordlist(This,wordlistType,words)	\
    ( (This)->lpVtbl -> InitializeWordlist(This,wordlistType,words) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpellCheckProvider_INTERFACE_DEFINED__ */


#ifndef __IComprehensiveSpellCheckProvider_INTERFACE_DEFINED__
#define __IComprehensiveSpellCheckProvider_INTERFACE_DEFINED__

/* interface IComprehensiveSpellCheckProvider */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IComprehensiveSpellCheckProvider;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0C58F8DE-8E94-479E-9717-70C42C4AD2C3")
    IComprehensiveSpellCheckProvider : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ComprehensiveCheck( 
            /* [annotation][in] */ 
            _In_  LPCWSTR text,
            /* [annotation][retval][out] */ 
            _Out_retval_  IEnumSpellingError **value) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IComprehensiveSpellCheckProviderVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IComprehensiveSpellCheckProvider * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IComprehensiveSpellCheckProvider * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IComprehensiveSpellCheckProvider * This);
        
        DECLSPEC_XFGVIRT(IComprehensiveSpellCheckProvider, ComprehensiveCheck)
        HRESULT ( STDMETHODCALLTYPE *ComprehensiveCheck )( 
            __RPC__in IComprehensiveSpellCheckProvider * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR text,
            /* [annotation][retval][out] */ 
            _Out_retval_  IEnumSpellingError **value);
        
        END_INTERFACE
    } IComprehensiveSpellCheckProviderVtbl;

    interface IComprehensiveSpellCheckProvider
    {
        CONST_VTBL struct IComprehensiveSpellCheckProviderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IComprehensiveSpellCheckProvider_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IComprehensiveSpellCheckProvider_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IComprehensiveSpellCheckProvider_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IComprehensiveSpellCheckProvider_ComprehensiveCheck(This,text,value)	\
    ( (This)->lpVtbl -> ComprehensiveCheck(This,text,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IComprehensiveSpellCheckProvider_INTERFACE_DEFINED__ */


#ifndef __ISpellCheckProviderFactory_INTERFACE_DEFINED__
#define __ISpellCheckProviderFactory_INTERFACE_DEFINED__

/* interface ISpellCheckProviderFactory */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_ISpellCheckProviderFactory;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9F671E11-77D6-4C92-AEFB-615215E3A4BE")
    ISpellCheckProviderFactory : public IUnknown
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_SupportedLanguages( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IEnumString **value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsSupported( 
            /* [annotation][in] */ 
            _In_  LPCWSTR languageTag,
            /* [annotation][retval][out] */ 
            _Out_retval_  BOOL *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateSpellCheckProvider( 
            /* [annotation][in] */ 
            _In_  LPCWSTR languageTag,
            /* [annotation][retval][out] */ 
            _Out_retval_  ISpellCheckProvider **value) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpellCheckProviderFactoryVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpellCheckProviderFactory * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpellCheckProviderFactory * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpellCheckProviderFactory * This);
        
        DECLSPEC_XFGVIRT(ISpellCheckProviderFactory, get_SupportedLanguages)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_SupportedLanguages )( 
            __RPC__in ISpellCheckProviderFactory * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IEnumString **value);
        
        DECLSPEC_XFGVIRT(ISpellCheckProviderFactory, IsSupported)
        HRESULT ( STDMETHODCALLTYPE *IsSupported )( 
            __RPC__in ISpellCheckProviderFactory * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR languageTag,
            /* [annotation][retval][out] */ 
            _Out_retval_  BOOL *value);
        
        DECLSPEC_XFGVIRT(ISpellCheckProviderFactory, CreateSpellCheckProvider)
        HRESULT ( STDMETHODCALLTYPE *CreateSpellCheckProvider )( 
            __RPC__in ISpellCheckProviderFactory * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR languageTag,
            /* [annotation][retval][out] */ 
            _Out_retval_  ISpellCheckProvider **value);
        
        END_INTERFACE
    } ISpellCheckProviderFactoryVtbl;

    interface ISpellCheckProviderFactory
    {
        CONST_VTBL struct ISpellCheckProviderFactoryVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpellCheckProviderFactory_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpellCheckProviderFactory_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpellCheckProviderFactory_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpellCheckProviderFactory_get_SupportedLanguages(This,value)	\
    ( (This)->lpVtbl -> get_SupportedLanguages(This,value) ) 

#define ISpellCheckProviderFactory_IsSupported(This,languageTag,value)	\
    ( (This)->lpVtbl -> IsSupported(This,languageTag,value) ) 

#define ISpellCheckProviderFactory_CreateSpellCheckProvider(This,languageTag,value)	\
    ( (This)->lpVtbl -> CreateSpellCheckProvider(This,languageTag,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpellCheckProviderFactory_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_spellcheckprovider_0000_0003 */
/* [local] */ 

#endif // (NTDDI >= MIN_SPELLING_NTDDI)
#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_spellcheckprovider_0000_0003_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_spellcheckprovider_0000_0003_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


