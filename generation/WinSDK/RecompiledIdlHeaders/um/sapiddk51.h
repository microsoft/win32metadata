

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

#ifndef __sapiddk51_h__
#define __sapiddk51_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ISpTokenUI_FWD_DEFINED__
#define __ISpTokenUI_FWD_DEFINED__
typedef interface ISpTokenUI ISpTokenUI;

#endif 	/* __ISpTokenUI_FWD_DEFINED__ */


#ifndef __ISpObjectTokenEnumBuilder_FWD_DEFINED__
#define __ISpObjectTokenEnumBuilder_FWD_DEFINED__
typedef interface ISpObjectTokenEnumBuilder ISpObjectTokenEnumBuilder;

#endif 	/* __ISpObjectTokenEnumBuilder_FWD_DEFINED__ */


#ifndef __ISpErrorLog_FWD_DEFINED__
#define __ISpErrorLog_FWD_DEFINED__
typedef interface ISpErrorLog ISpErrorLog;

#endif 	/* __ISpErrorLog_FWD_DEFINED__ */


#ifndef __ISpGrammarCompiler_FWD_DEFINED__
#define __ISpGrammarCompiler_FWD_DEFINED__
typedef interface ISpGrammarCompiler ISpGrammarCompiler;

#endif 	/* __ISpGrammarCompiler_FWD_DEFINED__ */


#ifndef __ISpGramCompBackend_FWD_DEFINED__
#define __ISpGramCompBackend_FWD_DEFINED__
typedef interface ISpGramCompBackend ISpGramCompBackend;

#endif 	/* __ISpGramCompBackend_FWD_DEFINED__ */


#ifndef __ISpITNProcessor_FWD_DEFINED__
#define __ISpITNProcessor_FWD_DEFINED__
typedef interface ISpITNProcessor ISpITNProcessor;

#endif 	/* __ISpITNProcessor_FWD_DEFINED__ */


#ifndef __ISpPhraseBuilder_FWD_DEFINED__
#define __ISpPhraseBuilder_FWD_DEFINED__
typedef interface ISpPhraseBuilder ISpPhraseBuilder;

#endif 	/* __ISpPhraseBuilder_FWD_DEFINED__ */


#ifndef __ISpThreadControl_FWD_DEFINED__
#define __ISpThreadControl_FWD_DEFINED__
typedef interface ISpThreadControl ISpThreadControl;

#endif 	/* __ISpThreadControl_FWD_DEFINED__ */


#ifndef __ISpTaskManager_FWD_DEFINED__
#define __ISpTaskManager_FWD_DEFINED__
typedef interface ISpTaskManager ISpTaskManager;

#endif 	/* __ISpTaskManager_FWD_DEFINED__ */


#ifndef __ISpTTSEngineSite_FWD_DEFINED__
#define __ISpTTSEngineSite_FWD_DEFINED__
typedef interface ISpTTSEngineSite ISpTTSEngineSite;

#endif 	/* __ISpTTSEngineSite_FWD_DEFINED__ */


#ifndef __ISpTTSEngine_FWD_DEFINED__
#define __ISpTTSEngine_FWD_DEFINED__
typedef interface ISpTTSEngine ISpTTSEngine;

#endif 	/* __ISpTTSEngine_FWD_DEFINED__ */


#ifndef __ISpCFGInterpreterSite_FWD_DEFINED__
#define __ISpCFGInterpreterSite_FWD_DEFINED__
typedef interface ISpCFGInterpreterSite ISpCFGInterpreterSite;

#endif 	/* __ISpCFGInterpreterSite_FWD_DEFINED__ */


#ifndef __ISpCFGInterpreter_FWD_DEFINED__
#define __ISpCFGInterpreter_FWD_DEFINED__
typedef interface ISpCFGInterpreter ISpCFGInterpreter;

#endif 	/* __ISpCFGInterpreter_FWD_DEFINED__ */


#ifndef __ISpSREngineSite_FWD_DEFINED__
#define __ISpSREngineSite_FWD_DEFINED__
typedef interface ISpSREngineSite ISpSREngineSite;

#endif 	/* __ISpSREngineSite_FWD_DEFINED__ */


#ifndef __ISpSREngine_FWD_DEFINED__
#define __ISpSREngine_FWD_DEFINED__
typedef interface ISpSREngine ISpSREngine;

#endif 	/* __ISpSREngine_FWD_DEFINED__ */


#ifndef ___ISpPrivateEngineCall_FWD_DEFINED__
#define ___ISpPrivateEngineCall_FWD_DEFINED__
typedef interface _ISpPrivateEngineCall _ISpPrivateEngineCall;

#endif 	/* ___ISpPrivateEngineCall_FWD_DEFINED__ */


#ifndef __SpDataKey_FWD_DEFINED__
#define __SpDataKey_FWD_DEFINED__

#ifdef __cplusplus
typedef class SpDataKey SpDataKey;
#else
typedef struct SpDataKey SpDataKey;
#endif /* __cplusplus */

#endif 	/* __SpDataKey_FWD_DEFINED__ */


#ifndef __SpObjectTokenEnum_FWD_DEFINED__
#define __SpObjectTokenEnum_FWD_DEFINED__

#ifdef __cplusplus
typedef class SpObjectTokenEnum SpObjectTokenEnum;
#else
typedef struct SpObjectTokenEnum SpObjectTokenEnum;
#endif /* __cplusplus */

#endif 	/* __SpObjectTokenEnum_FWD_DEFINED__ */


#ifndef __SpPhraseBuilder_FWD_DEFINED__
#define __SpPhraseBuilder_FWD_DEFINED__

#ifdef __cplusplus
typedef class SpPhraseBuilder SpPhraseBuilder;
#else
typedef struct SpPhraseBuilder SpPhraseBuilder;
#endif /* __cplusplus */

#endif 	/* __SpPhraseBuilder_FWD_DEFINED__ */


#ifndef __SpITNProcessor_FWD_DEFINED__
#define __SpITNProcessor_FWD_DEFINED__

#ifdef __cplusplus
typedef class SpITNProcessor SpITNProcessor;
#else
typedef struct SpITNProcessor SpITNProcessor;
#endif /* __cplusplus */

#endif 	/* __SpITNProcessor_FWD_DEFINED__ */


#ifndef __SpGrammarCompiler_FWD_DEFINED__
#define __SpGrammarCompiler_FWD_DEFINED__

#ifdef __cplusplus
typedef class SpGrammarCompiler SpGrammarCompiler;
#else
typedef struct SpGrammarCompiler SpGrammarCompiler;
#endif /* __cplusplus */

#endif 	/* __SpGrammarCompiler_FWD_DEFINED__ */


#ifndef __SpGramCompBackend_FWD_DEFINED__
#define __SpGramCompBackend_FWD_DEFINED__

#ifdef __cplusplus
typedef class SpGramCompBackend SpGramCompBackend;
#else
typedef struct SpGramCompBackend SpGramCompBackend;
#endif /* __cplusplus */

#endif 	/* __SpGramCompBackend_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "sapi.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_sapiddk51_0000_0000 */
/* [local] */ 

#include <winapifamily.h>
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)





#define SPRECOEXTENSION   L"RecoExtension"
#define SPALTERNATESCLSID L"AlternatesCLSID"


extern RPC_IF_HANDLE __MIDL_itf_sapiddk51_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sapiddk51_0000_0000_v0_0_s_ifspec;

#ifndef __ISpTokenUI_INTERFACE_DEFINED__
#define __ISpTokenUI_INTERFACE_DEFINED__

/* interface ISpTokenUI */
/* [restricted][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpTokenUI;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F8E690F0-39CB-4843-B8D7-C84696E1119D")
    ISpTokenUI : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE IsUISupported( 
            /* [in] */ LPCWSTR pszTypeOfUI,
            /* [in] */ void *pvExtraData,
            /* [in] */ ULONG cbExtraData,
            /* [in] */ IUnknown *punkObject,
            /* [out] */ BOOL *pfSupported) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE DisplayUI( 
            /* [in] */ HWND hwndParent,
            /* [in][annotation] */ 
            _In_opt_  LPCWSTR pszTitle,
            /* [in] */ LPCWSTR pszTypeOfUI,
            /* [in] */ void *pvExtraData,
            /* [in] */ ULONG cbExtraData,
            /* [in] */ ISpObjectToken *pToken,
            /* [in] */ IUnknown *punkObject) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpTokenUIVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpTokenUI * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpTokenUI * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpTokenUI * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *IsUISupported )( 
            ISpTokenUI * This,
            /* [in] */ LPCWSTR pszTypeOfUI,
            /* [in] */ void *pvExtraData,
            /* [in] */ ULONG cbExtraData,
            /* [in] */ IUnknown *punkObject,
            /* [out] */ BOOL *pfSupported);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *DisplayUI )( 
            ISpTokenUI * This,
            /* [in] */ HWND hwndParent,
            /* [in][annotation] */ 
            _In_opt_  LPCWSTR pszTitle,
            /* [in] */ LPCWSTR pszTypeOfUI,
            /* [in] */ void *pvExtraData,
            /* [in] */ ULONG cbExtraData,
            /* [in] */ ISpObjectToken *pToken,
            /* [in] */ IUnknown *punkObject);
        
        END_INTERFACE
    } ISpTokenUIVtbl;

    interface ISpTokenUI
    {
        CONST_VTBL struct ISpTokenUIVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpTokenUI_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpTokenUI_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpTokenUI_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpTokenUI_IsUISupported(This,pszTypeOfUI,pvExtraData,cbExtraData,punkObject,pfSupported)	\
    ( (This)->lpVtbl -> IsUISupported(This,pszTypeOfUI,pvExtraData,cbExtraData,punkObject,pfSupported) ) 

#define ISpTokenUI_DisplayUI(This,hwndParent,pszTitle,pszTypeOfUI,pvExtraData,cbExtraData,pToken,punkObject)	\
    ( (This)->lpVtbl -> DisplayUI(This,hwndParent,pszTitle,pszTypeOfUI,pvExtraData,cbExtraData,pToken,punkObject) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpTokenUI_INTERFACE_DEFINED__ */


#ifndef __ISpObjectTokenEnumBuilder_INTERFACE_DEFINED__
#define __ISpObjectTokenEnumBuilder_INTERFACE_DEFINED__

/* interface ISpObjectTokenEnumBuilder */
/* [restricted][local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpObjectTokenEnumBuilder;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("06B64F9F-7FDA-11D2-B4F2-00C04F797396")
    ISpObjectTokenEnumBuilder : public IEnumSpObjectTokens
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetAttribs( 
            /* [in][annotation] */ 
            _In_opt_  LPCWSTR pszReqAttribs,
            /* [in][annotation] */ 
            _In_opt_  LPCWSTR pszOptAttribs) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddTokens( 
            /* [in] */ ULONG cTokens,
            /* [in] */ ISpObjectToken **pToken) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddTokensFromDataKey( 
            /* [in] */ ISpDataKey *pDataKey,
            /* [in] */ LPCWSTR pszSubKey,
            /* [in] */ LPCWSTR pszCategoryId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddTokensFromTokenEnum( 
            /* [in] */ IEnumSpObjectTokens *pTokenEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Sort( 
            /* [in] */ LPCWSTR pszTokenIdToListFirst) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpObjectTokenEnumBuilderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpObjectTokenEnumBuilder * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpObjectTokenEnumBuilder * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpObjectTokenEnumBuilder * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            ISpObjectTokenEnumBuilder * This,
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ ISpObjectToken **pelt,
            /* [out][annotation] */ 
            _Out_opt_  ULONG *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            ISpObjectTokenEnumBuilder * This,
            /* [in] */ ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            ISpObjectTokenEnumBuilder * This);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            ISpObjectTokenEnumBuilder * This,
            /* [out] */ IEnumSpObjectTokens **ppEnum);
        
        HRESULT ( STDMETHODCALLTYPE *Item )( 
            ISpObjectTokenEnumBuilder * This,
            /* [in] */ ULONG Index,
            /* [out] */ ISpObjectToken **ppToken);
        
        HRESULT ( STDMETHODCALLTYPE *GetCount )( 
            ISpObjectTokenEnumBuilder * This,
            /* [out] */ ULONG *pCount);
        
        HRESULT ( STDMETHODCALLTYPE *SetAttribs )( 
            ISpObjectTokenEnumBuilder * This,
            /* [in][annotation] */ 
            _In_opt_  LPCWSTR pszReqAttribs,
            /* [in][annotation] */ 
            _In_opt_  LPCWSTR pszOptAttribs);
        
        HRESULT ( STDMETHODCALLTYPE *AddTokens )( 
            ISpObjectTokenEnumBuilder * This,
            /* [in] */ ULONG cTokens,
            /* [in] */ ISpObjectToken **pToken);
        
        HRESULT ( STDMETHODCALLTYPE *AddTokensFromDataKey )( 
            ISpObjectTokenEnumBuilder * This,
            /* [in] */ ISpDataKey *pDataKey,
            /* [in] */ LPCWSTR pszSubKey,
            /* [in] */ LPCWSTR pszCategoryId);
        
        HRESULT ( STDMETHODCALLTYPE *AddTokensFromTokenEnum )( 
            ISpObjectTokenEnumBuilder * This,
            /* [in] */ IEnumSpObjectTokens *pTokenEnum);
        
        HRESULT ( STDMETHODCALLTYPE *Sort )( 
            ISpObjectTokenEnumBuilder * This,
            /* [in] */ LPCWSTR pszTokenIdToListFirst);
        
        END_INTERFACE
    } ISpObjectTokenEnumBuilderVtbl;

    interface ISpObjectTokenEnumBuilder
    {
        CONST_VTBL struct ISpObjectTokenEnumBuilderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpObjectTokenEnumBuilder_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpObjectTokenEnumBuilder_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpObjectTokenEnumBuilder_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpObjectTokenEnumBuilder_Next(This,celt,pelt,pceltFetched)	\
    ( (This)->lpVtbl -> Next(This,celt,pelt,pceltFetched) ) 

#define ISpObjectTokenEnumBuilder_Skip(This,celt)	\
    ( (This)->lpVtbl -> Skip(This,celt) ) 

#define ISpObjectTokenEnumBuilder_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define ISpObjectTokenEnumBuilder_Clone(This,ppEnum)	\
    ( (This)->lpVtbl -> Clone(This,ppEnum) ) 

#define ISpObjectTokenEnumBuilder_Item(This,Index,ppToken)	\
    ( (This)->lpVtbl -> Item(This,Index,ppToken) ) 

#define ISpObjectTokenEnumBuilder_GetCount(This,pCount)	\
    ( (This)->lpVtbl -> GetCount(This,pCount) ) 


#define ISpObjectTokenEnumBuilder_SetAttribs(This,pszReqAttribs,pszOptAttribs)	\
    ( (This)->lpVtbl -> SetAttribs(This,pszReqAttribs,pszOptAttribs) ) 

#define ISpObjectTokenEnumBuilder_AddTokens(This,cTokens,pToken)	\
    ( (This)->lpVtbl -> AddTokens(This,cTokens,pToken) ) 

#define ISpObjectTokenEnumBuilder_AddTokensFromDataKey(This,pDataKey,pszSubKey,pszCategoryId)	\
    ( (This)->lpVtbl -> AddTokensFromDataKey(This,pDataKey,pszSubKey,pszCategoryId) ) 

#define ISpObjectTokenEnumBuilder_AddTokensFromTokenEnum(This,pTokenEnum)	\
    ( (This)->lpVtbl -> AddTokensFromTokenEnum(This,pTokenEnum) ) 

#define ISpObjectTokenEnumBuilder_Sort(This,pszTokenIdToListFirst)	\
    ( (This)->lpVtbl -> Sort(This,pszTokenIdToListFirst) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpObjectTokenEnumBuilder_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_sapiddk51_0000_0002 */
/* [local] */ 

#if 0
typedef void *SPWORDHANDLE;

typedef void *SPRULEHANDLE;

typedef void *SPGRAMMARHANDLE;

typedef void *SPRECOCONTEXTHANDLE;

typedef void *SPPHRASERULEHANDLE;

typedef void *SPPHRASEPROPERTYHANDLE;

typedef void *SPTRANSITIONID;

#else
DECLARE_HANDLE(SPWORDHANDLE);
DECLARE_HANDLE(SPRULEHANDLE);
DECLARE_HANDLE(SPGRAMMARHANDLE);
DECLARE_HANDLE(SPRECOCONTEXTHANDLE);
DECLARE_HANDLE(SPPHRASERULEHANDLE);
DECLARE_HANDLE(SPPHRASEPROPERTYHANDLE);
DECLARE_HANDLE(SPTRANSITIONID);
#endif


extern RPC_IF_HANDLE __MIDL_itf_sapiddk51_0000_0002_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sapiddk51_0000_0002_v0_0_s_ifspec;

#ifndef __ISpErrorLog_INTERFACE_DEFINED__
#define __ISpErrorLog_INTERFACE_DEFINED__

/* interface ISpErrorLog */
/* [restricted][local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpErrorLog;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F4711347-E608-11D2-A086-00C04F8EF9B5")
    ISpErrorLog : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AddError( 
            /* [in] */ const long lLineNumber,
            /* [in] */ HRESULT hr,
            /* [in] */ LPCWSTR pszDescription,
            /* [in][annotation] */ 
            _In_opt_  LPCWSTR pszHelpFile,
            /* [in] */ DWORD dwHelpContext) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpErrorLogVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpErrorLog * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpErrorLog * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpErrorLog * This);
        
        HRESULT ( STDMETHODCALLTYPE *AddError )( 
            ISpErrorLog * This,
            /* [in] */ const long lLineNumber,
            /* [in] */ HRESULT hr,
            /* [in] */ LPCWSTR pszDescription,
            /* [in][annotation] */ 
            _In_opt_  LPCWSTR pszHelpFile,
            /* [in] */ DWORD dwHelpContext);
        
        END_INTERFACE
    } ISpErrorLogVtbl;

    interface ISpErrorLog
    {
        CONST_VTBL struct ISpErrorLogVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpErrorLog_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpErrorLog_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpErrorLog_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpErrorLog_AddError(This,lLineNumber,hr,pszDescription,pszHelpFile,dwHelpContext)	\
    ( (This)->lpVtbl -> AddError(This,lLineNumber,hr,pszDescription,pszHelpFile,dwHelpContext) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpErrorLog_INTERFACE_DEFINED__ */


#ifndef __ISpGrammarCompiler_INTERFACE_DEFINED__
#define __ISpGrammarCompiler_INTERFACE_DEFINED__

/* interface ISpGrammarCompiler */
/* [restricted][local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpGrammarCompiler;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B1E29D58-A675-11D2-8302-00C04F8EE6C0")
    ISpGrammarCompiler : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CompileStream( 
            /* [in] */ IStream *pSource,
            /* [out] */ IStream *pDest,
            /* [in][annotation] */ 
            _In_opt_  IStream *pHeader,
            /* [in][annotation] */ 
            _In_opt_  IUnknown *pReserved,
            /* [in][annotation] */ 
            _In_opt_  ISpErrorLog *pErrorLog,
            /* [in] */ DWORD dwFlags) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpGrammarCompilerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpGrammarCompiler * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpGrammarCompiler * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpGrammarCompiler * This);
        
        HRESULT ( STDMETHODCALLTYPE *CompileStream )( 
            ISpGrammarCompiler * This,
            /* [in] */ IStream *pSource,
            /* [out] */ IStream *pDest,
            /* [in][annotation] */ 
            _In_opt_  IStream *pHeader,
            /* [in][annotation] */ 
            _In_opt_  IUnknown *pReserved,
            /* [in][annotation] */ 
            _In_opt_  ISpErrorLog *pErrorLog,
            /* [in] */ DWORD dwFlags);
        
        END_INTERFACE
    } ISpGrammarCompilerVtbl;

    interface ISpGrammarCompiler
    {
        CONST_VTBL struct ISpGrammarCompilerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpGrammarCompiler_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpGrammarCompiler_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpGrammarCompiler_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpGrammarCompiler_CompileStream(This,pSource,pDest,pHeader,pReserved,pErrorLog,dwFlags)	\
    ( (This)->lpVtbl -> CompileStream(This,pSource,pDest,pHeader,pReserved,pErrorLog,dwFlags) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpGrammarCompiler_INTERFACE_DEFINED__ */


#ifndef __ISpGramCompBackend_INTERFACE_DEFINED__
#define __ISpGramCompBackend_INTERFACE_DEFINED__

/* interface ISpGramCompBackend */
/* [restricted][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpGramCompBackend;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3DDCA27C-665C-4786-9F97-8C90C3488B61")
    ISpGramCompBackend : public ISpGrammarBuilder
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetSaveObjects( 
            /* [in] */ __RPC__in_opt IStream *pStream,
            /* [in] */ __RPC__in_opt ISpErrorLog *pErrorLog) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InitFromBinaryGrammar( 
            /* [in] */ __RPC__in const SPBINARYGRAMMAR *pBinaryData) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpGramCompBackendVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpGramCompBackend * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpGramCompBackend * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpGramCompBackend * This);
        
        HRESULT ( STDMETHODCALLTYPE *ResetGrammar )( 
            __RPC__in ISpGramCompBackend * This,
            /* [in] */ WORD NewLanguage);
        
        HRESULT ( STDMETHODCALLTYPE *GetRule )( 
            __RPC__in ISpGramCompBackend * This,
            /* [in] */ __RPC__in LPCWSTR pszRuleName,
            /* [in] */ DWORD dwRuleId,
            /* [in] */ DWORD dwAttributes,
            /* [in] */ BOOL fCreateIfNotExist,
            /* [out] */ __RPC__deref_out_opt SPSTATEHANDLE *phInitialState);
        
        HRESULT ( STDMETHODCALLTYPE *ClearRule )( 
            __RPC__in ISpGramCompBackend * This,
            /* [in] */ __RPC__in SPSTATEHANDLE hState);
        
        HRESULT ( STDMETHODCALLTYPE *CreateNewState )( 
            __RPC__in ISpGramCompBackend * This,
            /* [in] */ __RPC__in SPSTATEHANDLE hState,
            /* [out] */ __RPC__deref_out_opt SPSTATEHANDLE *phState);
        
        HRESULT ( STDMETHODCALLTYPE *AddWordTransition )( 
            __RPC__in ISpGramCompBackend * This,
            /* [in] */ __RPC__in SPSTATEHANDLE hFromState,
            /* [in] */ __RPC__in SPSTATEHANDLE hToState,
            /* [in][annotation] */ 
            _In_opt_  LPCWSTR psz,
            /* [in][annotation] */ 
            _In_opt_  LPCWSTR pszSeparators,
            /* [in] */ SPGRAMMARWORDTYPE eWordType,
            /* [in] */ float Weight,
            /* [in] */ __RPC__in const SPPROPERTYINFO *pPropInfo);
        
        HRESULT ( STDMETHODCALLTYPE *AddRuleTransition )( 
            __RPC__in ISpGramCompBackend * This,
            /* [in] */ __RPC__in SPSTATEHANDLE hFromState,
            /* [in] */ __RPC__in SPSTATEHANDLE hToState,
            /* [in] */ __RPC__in SPSTATEHANDLE hRule,
            /* [in] */ float Weight,
            /* [in] */ __RPC__in const SPPROPERTYINFO *pPropInfo);
        
        HRESULT ( STDMETHODCALLTYPE *AddResource )( 
            __RPC__in ISpGramCompBackend * This,
            /* [in] */ __RPC__in SPSTATEHANDLE hRuleState,
            /* [in] */ __RPC__in LPCWSTR pszResourceName,
            /* [in][annotation] */ 
            _In_opt_  LPCWSTR pszResourceValue);
        
        HRESULT ( STDMETHODCALLTYPE *Commit )( 
            __RPC__in ISpGramCompBackend * This,
            /* [in] */ DWORD dwReserved);
        
        HRESULT ( STDMETHODCALLTYPE *SetSaveObjects )( 
            __RPC__in ISpGramCompBackend * This,
            /* [in] */ __RPC__in_opt IStream *pStream,
            /* [in] */ __RPC__in_opt ISpErrorLog *pErrorLog);
        
        HRESULT ( STDMETHODCALLTYPE *InitFromBinaryGrammar )( 
            __RPC__in ISpGramCompBackend * This,
            /* [in] */ __RPC__in const SPBINARYGRAMMAR *pBinaryData);
        
        END_INTERFACE
    } ISpGramCompBackendVtbl;

    interface ISpGramCompBackend
    {
        CONST_VTBL struct ISpGramCompBackendVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpGramCompBackend_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpGramCompBackend_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpGramCompBackend_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpGramCompBackend_ResetGrammar(This,NewLanguage)	\
    ( (This)->lpVtbl -> ResetGrammar(This,NewLanguage) ) 

#define ISpGramCompBackend_GetRule(This,pszRuleName,dwRuleId,dwAttributes,fCreateIfNotExist,phInitialState)	\
    ( (This)->lpVtbl -> GetRule(This,pszRuleName,dwRuleId,dwAttributes,fCreateIfNotExist,phInitialState) ) 

#define ISpGramCompBackend_ClearRule(This,hState)	\
    ( (This)->lpVtbl -> ClearRule(This,hState) ) 

#define ISpGramCompBackend_CreateNewState(This,hState,phState)	\
    ( (This)->lpVtbl -> CreateNewState(This,hState,phState) ) 

#define ISpGramCompBackend_AddWordTransition(This,hFromState,hToState,psz,pszSeparators,eWordType,Weight,pPropInfo)	\
    ( (This)->lpVtbl -> AddWordTransition(This,hFromState,hToState,psz,pszSeparators,eWordType,Weight,pPropInfo) ) 

#define ISpGramCompBackend_AddRuleTransition(This,hFromState,hToState,hRule,Weight,pPropInfo)	\
    ( (This)->lpVtbl -> AddRuleTransition(This,hFromState,hToState,hRule,Weight,pPropInfo) ) 

#define ISpGramCompBackend_AddResource(This,hRuleState,pszResourceName,pszResourceValue)	\
    ( (This)->lpVtbl -> AddResource(This,hRuleState,pszResourceName,pszResourceValue) ) 

#define ISpGramCompBackend_Commit(This,dwReserved)	\
    ( (This)->lpVtbl -> Commit(This,dwReserved) ) 


#define ISpGramCompBackend_SetSaveObjects(This,pStream,pErrorLog)	\
    ( (This)->lpVtbl -> SetSaveObjects(This,pStream,pErrorLog) ) 

#define ISpGramCompBackend_InitFromBinaryGrammar(This,pBinaryData)	\
    ( (This)->lpVtbl -> InitFromBinaryGrammar(This,pBinaryData) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpGramCompBackend_INTERFACE_DEFINED__ */


#ifndef __ISpITNProcessor_INTERFACE_DEFINED__
#define __ISpITNProcessor_INTERFACE_DEFINED__

/* interface ISpITNProcessor */
/* [restricted][local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpITNProcessor;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("12D7360F-A1C9-11D3-BC90-00C04F72DF9F")
    ISpITNProcessor : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE LoadITNGrammar( 
            /* [in][annotation] */ 
            _In_  LPWSTR pszCLSID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ITNPhrase( 
            /* [in] */ ISpPhraseBuilder *pPhrase) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpITNProcessorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpITNProcessor * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpITNProcessor * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpITNProcessor * This);
        
        HRESULT ( STDMETHODCALLTYPE *LoadITNGrammar )( 
            ISpITNProcessor * This,
            /* [in][annotation] */ 
            _In_  LPWSTR pszCLSID);
        
        HRESULT ( STDMETHODCALLTYPE *ITNPhrase )( 
            ISpITNProcessor * This,
            /* [in] */ ISpPhraseBuilder *pPhrase);
        
        END_INTERFACE
    } ISpITNProcessorVtbl;

    interface ISpITNProcessor
    {
        CONST_VTBL struct ISpITNProcessorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpITNProcessor_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpITNProcessor_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpITNProcessor_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpITNProcessor_LoadITNGrammar(This,pszCLSID)	\
    ( (This)->lpVtbl -> LoadITNGrammar(This,pszCLSID) ) 

#define ISpITNProcessor_ITNPhrase(This,pPhrase)	\
    ( (This)->lpVtbl -> ITNPhrase(This,pPhrase) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpITNProcessor_INTERFACE_DEFINED__ */


#ifndef __ISpPhraseBuilder_INTERFACE_DEFINED__
#define __ISpPhraseBuilder_INTERFACE_DEFINED__

/* interface ISpPhraseBuilder */
/* [restricted][unique][helpstring][local][uuid][object] */ 


EXTERN_C const IID IID_ISpPhraseBuilder;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("88A3342A-0BED-4834-922B-88D43173162F")
    ISpPhraseBuilder : public ISpPhrase
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE InitFromPhrase( 
            /* [in] */ const SPPHRASE *pPhrase) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InitFromSerializedPhrase( 
            /* [in] */ const SPSERIALIZEDPHRASE *pPhrase) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddElements( 
            /* [in] */ ULONG cElements,
            /* [in] */ const SPPHRASEELEMENT *pElement) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddRules( 
            /* [in] */ const SPPHRASERULEHANDLE hParent,
            /* [in] */ const SPPHRASERULE *pRule,
            /* [out] */ SPPHRASERULEHANDLE *phNewRule) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddProperties( 
            /* [in] */ const SPPHRASEPROPERTYHANDLE hParent,
            /* [in] */ const SPPHRASEPROPERTY *pProperty,
            /* [out] */ SPPHRASEPROPERTYHANDLE *phNewProperty) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddReplacements( 
            /* [in] */ ULONG cReplacements,
            /* [in] */ const SPPHRASEREPLACEMENT *pReplacements) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpPhraseBuilderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpPhraseBuilder * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpPhraseBuilder * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpPhraseBuilder * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetPhrase )( 
            ISpPhraseBuilder * This,
            /* [out][annotation] */ 
            _Outptr_  SPPHRASE **ppCoMemPhrase);
        
        HRESULT ( STDMETHODCALLTYPE *GetSerializedPhrase )( 
            ISpPhraseBuilder * This,
            /* [out][annotation] */ 
            _Outptr_  SPSERIALIZEDPHRASE **ppCoMemPhrase);
        
        HRESULT ( STDMETHODCALLTYPE *GetText )( 
            ISpPhraseBuilder * This,
            /* [in] */ ULONG ulStart,
            /* [in] */ ULONG ulCount,
            /* [in] */ BOOL fUseTextReplacements,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppszCoMemText,
            /* [optional][out][annotation] */ 
            _Out_writes_opt_(1)  BYTE *pbDisplayAttributes);
        
        HRESULT ( STDMETHODCALLTYPE *Discard )( 
            ISpPhraseBuilder * This,
            /* [in] */ DWORD dwValueTypes);
        
        HRESULT ( STDMETHODCALLTYPE *InitFromPhrase )( 
            ISpPhraseBuilder * This,
            /* [in] */ const SPPHRASE *pPhrase);
        
        HRESULT ( STDMETHODCALLTYPE *InitFromSerializedPhrase )( 
            ISpPhraseBuilder * This,
            /* [in] */ const SPSERIALIZEDPHRASE *pPhrase);
        
        HRESULT ( STDMETHODCALLTYPE *AddElements )( 
            ISpPhraseBuilder * This,
            /* [in] */ ULONG cElements,
            /* [in] */ const SPPHRASEELEMENT *pElement);
        
        HRESULT ( STDMETHODCALLTYPE *AddRules )( 
            ISpPhraseBuilder * This,
            /* [in] */ const SPPHRASERULEHANDLE hParent,
            /* [in] */ const SPPHRASERULE *pRule,
            /* [out] */ SPPHRASERULEHANDLE *phNewRule);
        
        HRESULT ( STDMETHODCALLTYPE *AddProperties )( 
            ISpPhraseBuilder * This,
            /* [in] */ const SPPHRASEPROPERTYHANDLE hParent,
            /* [in] */ const SPPHRASEPROPERTY *pProperty,
            /* [out] */ SPPHRASEPROPERTYHANDLE *phNewProperty);
        
        HRESULT ( STDMETHODCALLTYPE *AddReplacements )( 
            ISpPhraseBuilder * This,
            /* [in] */ ULONG cReplacements,
            /* [in] */ const SPPHRASEREPLACEMENT *pReplacements);
        
        END_INTERFACE
    } ISpPhraseBuilderVtbl;

    interface ISpPhraseBuilder
    {
        CONST_VTBL struct ISpPhraseBuilderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpPhraseBuilder_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpPhraseBuilder_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpPhraseBuilder_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpPhraseBuilder_GetPhrase(This,ppCoMemPhrase)	\
    ( (This)->lpVtbl -> GetPhrase(This,ppCoMemPhrase) ) 

#define ISpPhraseBuilder_GetSerializedPhrase(This,ppCoMemPhrase)	\
    ( (This)->lpVtbl -> GetSerializedPhrase(This,ppCoMemPhrase) ) 

#define ISpPhraseBuilder_GetText(This,ulStart,ulCount,fUseTextReplacements,ppszCoMemText,pbDisplayAttributes)	\
    ( (This)->lpVtbl -> GetText(This,ulStart,ulCount,fUseTextReplacements,ppszCoMemText,pbDisplayAttributes) ) 

#define ISpPhraseBuilder_Discard(This,dwValueTypes)	\
    ( (This)->lpVtbl -> Discard(This,dwValueTypes) ) 


#define ISpPhraseBuilder_InitFromPhrase(This,pPhrase)	\
    ( (This)->lpVtbl -> InitFromPhrase(This,pPhrase) ) 

#define ISpPhraseBuilder_InitFromSerializedPhrase(This,pPhrase)	\
    ( (This)->lpVtbl -> InitFromSerializedPhrase(This,pPhrase) ) 

#define ISpPhraseBuilder_AddElements(This,cElements,pElement)	\
    ( (This)->lpVtbl -> AddElements(This,cElements,pElement) ) 

#define ISpPhraseBuilder_AddRules(This,hParent,pRule,phNewRule)	\
    ( (This)->lpVtbl -> AddRules(This,hParent,pRule,phNewRule) ) 

#define ISpPhraseBuilder_AddProperties(This,hParent,pProperty,phNewProperty)	\
    ( (This)->lpVtbl -> AddProperties(This,hParent,pProperty,phNewProperty) ) 

#define ISpPhraseBuilder_AddReplacements(This,cReplacements,pReplacements)	\
    ( (This)->lpVtbl -> AddReplacements(This,cReplacements,pReplacements) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpPhraseBuilder_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_sapiddk51_0000_0007 */
/* [local] */ 

#if defined(__cplusplus)
interface ISpTask
{
virtual HRESULT STDMETHODCALLTYPE Execute(
                 void *pvTaskData,
                 volatile const BOOL* pfContinueProcessing) = 0;
};
#else
typedef void *ISpTask;

#endif
#if defined(__cplusplus)
interface ISpThreadTask
{
virtual HRESULT STDMETHODCALLTYPE InitThread(
                 void* pvTaskData,
                 HWND hwnd) = 0;
virtual HRESULT STDMETHODCALLTYPE ThreadProc(
                 void *pvTaskData,
                 HANDLE hExitThreadEvent,
                 HANDLE hNotifyEvent,
                 HWND hwndWorker,
                 volatile const BOOL* pfContinueProcessing) = 0;
virtual LRESULT STDMETHODCALLTYPE WindowMessage(
                 void *pvTaskData,
                 HWND hWnd,
                 UINT Msg,
                 WPARAM wParam,
                 LPARAM lParam) = 0;
};
#else
typedef void *ISpThreadTask;

#endif


extern RPC_IF_HANDLE __MIDL_itf_sapiddk51_0000_0007_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sapiddk51_0000_0007_v0_0_s_ifspec;

#ifndef __ISpThreadControl_INTERFACE_DEFINED__
#define __ISpThreadControl_INTERFACE_DEFINED__

/* interface ISpThreadControl */
/* [restricted][local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpThreadControl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A6BE4D73-4403-4358-B22D-0346E23B1764")
    ISpThreadControl : public ISpNotifySink
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE StartThread( 
            /* [in] */ DWORD dwFlags,
            /* [out] */ HWND *phwnd) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE WaitForThreadDone( 
            /* [in] */ BOOL fForceStop,
            /* [out] */ HRESULT *phrThreadResult,
            /* [in] */ ULONG msTimeOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE TerminateThread( void) = 0;
        
        virtual HANDLE STDMETHODCALLTYPE ThreadHandle( void) = 0;
        
        virtual DWORD STDMETHODCALLTYPE ThreadId( void) = 0;
        
        virtual HANDLE STDMETHODCALLTYPE NotifyEvent( void) = 0;
        
        virtual HWND STDMETHODCALLTYPE WindowHandle( void) = 0;
        
        virtual HANDLE STDMETHODCALLTYPE ThreadCompleteEvent( void) = 0;
        
        virtual HANDLE STDMETHODCALLTYPE ExitThreadEvent( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpThreadControlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpThreadControl * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpThreadControl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpThreadControl * This);
        
        HRESULT ( STDMETHODCALLTYPE *Notify )( 
            ISpThreadControl * This);
        
        HRESULT ( STDMETHODCALLTYPE *StartThread )( 
            ISpThreadControl * This,
            /* [in] */ DWORD dwFlags,
            /* [out] */ HWND *phwnd);
        
        HRESULT ( STDMETHODCALLTYPE *WaitForThreadDone )( 
            ISpThreadControl * This,
            /* [in] */ BOOL fForceStop,
            /* [out] */ HRESULT *phrThreadResult,
            /* [in] */ ULONG msTimeOut);
        
        HRESULT ( STDMETHODCALLTYPE *TerminateThread )( 
            ISpThreadControl * This);
        
        HANDLE ( STDMETHODCALLTYPE *ThreadHandle )( 
            ISpThreadControl * This);
        
        DWORD ( STDMETHODCALLTYPE *ThreadId )( 
            ISpThreadControl * This);
        
        HANDLE ( STDMETHODCALLTYPE *NotifyEvent )( 
            ISpThreadControl * This);
        
        HWND ( STDMETHODCALLTYPE *WindowHandle )( 
            ISpThreadControl * This);
        
        HANDLE ( STDMETHODCALLTYPE *ThreadCompleteEvent )( 
            ISpThreadControl * This);
        
        HANDLE ( STDMETHODCALLTYPE *ExitThreadEvent )( 
            ISpThreadControl * This);
        
        END_INTERFACE
    } ISpThreadControlVtbl;

    interface ISpThreadControl
    {
        CONST_VTBL struct ISpThreadControlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpThreadControl_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpThreadControl_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpThreadControl_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpThreadControl_Notify(This)	\
    ( (This)->lpVtbl -> Notify(This) ) 


#define ISpThreadControl_StartThread(This,dwFlags,phwnd)	\
    ( (This)->lpVtbl -> StartThread(This,dwFlags,phwnd) ) 

#define ISpThreadControl_WaitForThreadDone(This,fForceStop,phrThreadResult,msTimeOut)	\
    ( (This)->lpVtbl -> WaitForThreadDone(This,fForceStop,phrThreadResult,msTimeOut) ) 

#define ISpThreadControl_TerminateThread(This)	\
    ( (This)->lpVtbl -> TerminateThread(This) ) 

#define ISpThreadControl_ThreadHandle(This)	\
    ( (This)->lpVtbl -> ThreadHandle(This) ) 

#define ISpThreadControl_ThreadId(This)	\
    ( (This)->lpVtbl -> ThreadId(This) ) 

#define ISpThreadControl_NotifyEvent(This)	\
    ( (This)->lpVtbl -> NotifyEvent(This) ) 

#define ISpThreadControl_WindowHandle(This)	\
    ( (This)->lpVtbl -> WindowHandle(This) ) 

#define ISpThreadControl_ThreadCompleteEvent(This)	\
    ( (This)->lpVtbl -> ThreadCompleteEvent(This) ) 

#define ISpThreadControl_ExitThreadEvent(This)	\
    ( (This)->lpVtbl -> ExitThreadEvent(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpThreadControl_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_sapiddk51_0000_0008 */
/* [local] */ 

typedef /* [restricted] */ struct SPTMTHREADINFO
    {
    long lPoolSize;
    long lPriority;
    ULONG ulConcurrencyLimit;
    ULONG ulMaxQuickAllocThreads;
    } 	SPTMTHREADINFO;



extern RPC_IF_HANDLE __MIDL_itf_sapiddk51_0000_0008_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sapiddk51_0000_0008_v0_0_s_ifspec;

#ifndef __ISpTaskManager_INTERFACE_DEFINED__
#define __ISpTaskManager_INTERFACE_DEFINED__

/* interface ISpTaskManager */
/* [object][restricted][unique][helpstring][uuid][local] */ 


EXTERN_C const IID IID_ISpTaskManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2BAEEF81-2CA3-4331-98F3-26EC5ABEFB03")
    ISpTaskManager : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetThreadPoolInfo( 
            /* [in] */ const SPTMTHREADINFO *pPoolInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetThreadPoolInfo( 
            /* [out] */ SPTMTHREADINFO *pPoolInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueueTask( 
            /* [in] */ ISpTask *pTask,
            /* [in] */ void *pvTaskData,
            /* [in] */ HANDLE hCompEvent,
            /* [out][in] */ DWORD *pdwGroupId,
            /* [out] */ DWORD *pTaskID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateReoccurringTask( 
            /* [in] */ ISpTask *pTask,
            /* [in] */ void *pvTaskData,
            /* [in] */ HANDLE hCompEvent,
            /* [out] */ ISpNotifySink **ppTaskCtrl) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateThreadControl( 
            /* [in] */ ISpThreadTask *pTask,
            /* [in] */ void *pvTaskData,
            /* [in] */ long nPriority,
            /* [out][annotation] */ 
            _Outptr_  ISpThreadControl **ppTaskCtrl) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE TerminateTask( 
            /* [in] */ DWORD dwTaskId,
            /* [in] */ ULONG ulWaitPeriod) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE TerminateTaskGroup( 
            /* [in] */ DWORD dwGroupId,
            /* [in] */ ULONG ulWaitPeriod) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpTaskManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpTaskManager * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpTaskManager * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpTaskManager * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetThreadPoolInfo )( 
            ISpTaskManager * This,
            /* [in] */ const SPTMTHREADINFO *pPoolInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetThreadPoolInfo )( 
            ISpTaskManager * This,
            /* [out] */ SPTMTHREADINFO *pPoolInfo);
        
        HRESULT ( STDMETHODCALLTYPE *QueueTask )( 
            ISpTaskManager * This,
            /* [in] */ ISpTask *pTask,
            /* [in] */ void *pvTaskData,
            /* [in] */ HANDLE hCompEvent,
            /* [out][in] */ DWORD *pdwGroupId,
            /* [out] */ DWORD *pTaskID);
        
        HRESULT ( STDMETHODCALLTYPE *CreateReoccurringTask )( 
            ISpTaskManager * This,
            /* [in] */ ISpTask *pTask,
            /* [in] */ void *pvTaskData,
            /* [in] */ HANDLE hCompEvent,
            /* [out] */ ISpNotifySink **ppTaskCtrl);
        
        HRESULT ( STDMETHODCALLTYPE *CreateThreadControl )( 
            ISpTaskManager * This,
            /* [in] */ ISpThreadTask *pTask,
            /* [in] */ void *pvTaskData,
            /* [in] */ long nPriority,
            /* [out][annotation] */ 
            _Outptr_  ISpThreadControl **ppTaskCtrl);
        
        HRESULT ( STDMETHODCALLTYPE *TerminateTask )( 
            ISpTaskManager * This,
            /* [in] */ DWORD dwTaskId,
            /* [in] */ ULONG ulWaitPeriod);
        
        HRESULT ( STDMETHODCALLTYPE *TerminateTaskGroup )( 
            ISpTaskManager * This,
            /* [in] */ DWORD dwGroupId,
            /* [in] */ ULONG ulWaitPeriod);
        
        END_INTERFACE
    } ISpTaskManagerVtbl;

    interface ISpTaskManager
    {
        CONST_VTBL struct ISpTaskManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpTaskManager_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpTaskManager_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpTaskManager_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpTaskManager_SetThreadPoolInfo(This,pPoolInfo)	\
    ( (This)->lpVtbl -> SetThreadPoolInfo(This,pPoolInfo) ) 

#define ISpTaskManager_GetThreadPoolInfo(This,pPoolInfo)	\
    ( (This)->lpVtbl -> GetThreadPoolInfo(This,pPoolInfo) ) 

#define ISpTaskManager_QueueTask(This,pTask,pvTaskData,hCompEvent,pdwGroupId,pTaskID)	\
    ( (This)->lpVtbl -> QueueTask(This,pTask,pvTaskData,hCompEvent,pdwGroupId,pTaskID) ) 

#define ISpTaskManager_CreateReoccurringTask(This,pTask,pvTaskData,hCompEvent,ppTaskCtrl)	\
    ( (This)->lpVtbl -> CreateReoccurringTask(This,pTask,pvTaskData,hCompEvent,ppTaskCtrl) ) 

#define ISpTaskManager_CreateThreadControl(This,pTask,pvTaskData,nPriority,ppTaskCtrl)	\
    ( (This)->lpVtbl -> CreateThreadControl(This,pTask,pvTaskData,nPriority,ppTaskCtrl) ) 

#define ISpTaskManager_TerminateTask(This,dwTaskId,ulWaitPeriod)	\
    ( (This)->lpVtbl -> TerminateTask(This,dwTaskId,ulWaitPeriod) ) 

#define ISpTaskManager_TerminateTaskGroup(This,dwGroupId,ulWaitPeriod)	\
    ( (This)->lpVtbl -> TerminateTaskGroup(This,dwGroupId,ulWaitPeriod) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpTaskManager_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_sapiddk51_0000_0009 */
/* [local] */ 

typedef 
enum SPVSKIPTYPE
    {
        SPVST_SENTENCE	= ( 1L << 0 ) 
    } 	SPVSKIPTYPE;

typedef 
enum SPVESACTIONS
    {
        SPVES_CONTINUE	= 0,
        SPVES_ABORT	= ( 1L << 0 ) ,
        SPVES_SKIP	= ( 1L << 1 ) ,
        SPVES_RATE	= ( 1L << 2 ) ,
        SPVES_VOLUME	= ( 1L << 3 ) 
    } 	SPVESACTIONS;



extern RPC_IF_HANDLE __MIDL_itf_sapiddk51_0000_0009_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sapiddk51_0000_0009_v0_0_s_ifspec;

#ifndef __ISpTTSEngineSite_INTERFACE_DEFINED__
#define __ISpTTSEngineSite_INTERFACE_DEFINED__

/* interface ISpTTSEngineSite */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_ISpTTSEngineSite;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9880499B-CCE9-11D2-B503-00C04F797396")
    ISpTTSEngineSite : public ISpEventSink
    {
    public:
        virtual DWORD STDMETHODCALLTYPE GetActions( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Write( 
            /* [in] */ const void *pBuff,
            /* [in] */ ULONG cb,
            /* [out] */ ULONG *pcbWritten) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRate( 
            /* [out] */ long *pRateAdjust) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetVolume( 
            /* [out] */ USHORT *pusVolume) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSkipInfo( 
            /* [out] */ SPVSKIPTYPE *peType,
            /* [out] */ long *plNumItems) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CompleteSkip( 
            /* [in] */ long ulNumSkipped) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpTTSEngineSiteVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpTTSEngineSite * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpTTSEngineSite * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpTTSEngineSite * This);
        
        HRESULT ( STDMETHODCALLTYPE *AddEvents )( 
            ISpTTSEngineSite * This,
            /* [in] */ const SPEVENT *pEventArray,
            /* [in] */ ULONG ulCount);
        
        HRESULT ( STDMETHODCALLTYPE *GetEventInterest )( 
            ISpTTSEngineSite * This,
            /* [out] */ ULONGLONG *pullEventInterest);
        
        DWORD ( STDMETHODCALLTYPE *GetActions )( 
            ISpTTSEngineSite * This);
        
        HRESULT ( STDMETHODCALLTYPE *Write )( 
            ISpTTSEngineSite * This,
            /* [in] */ const void *pBuff,
            /* [in] */ ULONG cb,
            /* [out] */ ULONG *pcbWritten);
        
        HRESULT ( STDMETHODCALLTYPE *GetRate )( 
            ISpTTSEngineSite * This,
            /* [out] */ long *pRateAdjust);
        
        HRESULT ( STDMETHODCALLTYPE *GetVolume )( 
            ISpTTSEngineSite * This,
            /* [out] */ USHORT *pusVolume);
        
        HRESULT ( STDMETHODCALLTYPE *GetSkipInfo )( 
            ISpTTSEngineSite * This,
            /* [out] */ SPVSKIPTYPE *peType,
            /* [out] */ long *plNumItems);
        
        HRESULT ( STDMETHODCALLTYPE *CompleteSkip )( 
            ISpTTSEngineSite * This,
            /* [in] */ long ulNumSkipped);
        
        END_INTERFACE
    } ISpTTSEngineSiteVtbl;

    interface ISpTTSEngineSite
    {
        CONST_VTBL struct ISpTTSEngineSiteVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpTTSEngineSite_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpTTSEngineSite_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpTTSEngineSite_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpTTSEngineSite_AddEvents(This,pEventArray,ulCount)	\
    ( (This)->lpVtbl -> AddEvents(This,pEventArray,ulCount) ) 

#define ISpTTSEngineSite_GetEventInterest(This,pullEventInterest)	\
    ( (This)->lpVtbl -> GetEventInterest(This,pullEventInterest) ) 


#define ISpTTSEngineSite_GetActions(This)	\
    ( (This)->lpVtbl -> GetActions(This) ) 

#define ISpTTSEngineSite_Write(This,pBuff,cb,pcbWritten)	\
    ( (This)->lpVtbl -> Write(This,pBuff,cb,pcbWritten) ) 

#define ISpTTSEngineSite_GetRate(This,pRateAdjust)	\
    ( (This)->lpVtbl -> GetRate(This,pRateAdjust) ) 

#define ISpTTSEngineSite_GetVolume(This,pusVolume)	\
    ( (This)->lpVtbl -> GetVolume(This,pusVolume) ) 

#define ISpTTSEngineSite_GetSkipInfo(This,peType,plNumItems)	\
    ( (This)->lpVtbl -> GetSkipInfo(This,peType,plNumItems) ) 

#define ISpTTSEngineSite_CompleteSkip(This,ulNumSkipped)	\
    ( (This)->lpVtbl -> CompleteSkip(This,ulNumSkipped) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpTTSEngineSite_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_sapiddk51_0000_0010 */
/* [local] */ 

typedef struct SPVTEXTFRAG
    {
    struct SPVTEXTFRAG *pNext;
    SPVSTATE State;
    LPCWSTR pTextStart;
    ULONG ulTextLen;
    ULONG ulTextSrcOffset;
    } 	SPVTEXTFRAG;



extern RPC_IF_HANDLE __MIDL_itf_sapiddk51_0000_0010_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sapiddk51_0000_0010_v0_0_s_ifspec;

#ifndef __ISpTTSEngine_INTERFACE_DEFINED__
#define __ISpTTSEngine_INTERFACE_DEFINED__

/* interface ISpTTSEngine */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_ISpTTSEngine;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A74D7C8E-4CC5-4F2F-A6EB-804DEE18500E")
    ISpTTSEngine : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Speak( 
            /* [in] */ DWORD dwSpeakFlags,
            /* [in] */ REFGUID rguidFormatId,
            /* [in] */ const WAVEFORMATEX *pWaveFormatEx,
            /* [in] */ const SPVTEXTFRAG *pTextFragList,
            /* [in] */ ISpTTSEngineSite *pOutputSite) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetOutputFormat( 
            /* [in] */ const GUID *pTargetFmtId,
            /* [in] */ const WAVEFORMATEX *pTargetWaveFormatEx,
            /* [out] */ GUID *pOutputFormatId,
            /* [out][annotation] */ 
            _Outptr_  WAVEFORMATEX **ppCoMemOutputWaveFormatEx) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpTTSEngineVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpTTSEngine * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpTTSEngine * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpTTSEngine * This);
        
        HRESULT ( STDMETHODCALLTYPE *Speak )( 
            ISpTTSEngine * This,
            /* [in] */ DWORD dwSpeakFlags,
            /* [in] */ REFGUID rguidFormatId,
            /* [in] */ const WAVEFORMATEX *pWaveFormatEx,
            /* [in] */ const SPVTEXTFRAG *pTextFragList,
            /* [in] */ ISpTTSEngineSite *pOutputSite);
        
        HRESULT ( STDMETHODCALLTYPE *GetOutputFormat )( 
            ISpTTSEngine * This,
            /* [in] */ const GUID *pTargetFmtId,
            /* [in] */ const WAVEFORMATEX *pTargetWaveFormatEx,
            /* [out] */ GUID *pOutputFormatId,
            /* [out][annotation] */ 
            _Outptr_  WAVEFORMATEX **ppCoMemOutputWaveFormatEx);
        
        END_INTERFACE
    } ISpTTSEngineVtbl;

    interface ISpTTSEngine
    {
        CONST_VTBL struct ISpTTSEngineVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpTTSEngine_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpTTSEngine_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpTTSEngine_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpTTSEngine_Speak(This,dwSpeakFlags,rguidFormatId,pWaveFormatEx,pTextFragList,pOutputSite)	\
    ( (This)->lpVtbl -> Speak(This,dwSpeakFlags,rguidFormatId,pWaveFormatEx,pTextFragList,pOutputSite) ) 

#define ISpTTSEngine_GetOutputFormat(This,pTargetFmtId,pTargetWaveFormatEx,pOutputFormatId,ppCoMemOutputWaveFormatEx)	\
    ( (This)->lpVtbl -> GetOutputFormat(This,pTargetFmtId,pTargetWaveFormatEx,pOutputFormatId,ppCoMemOutputWaveFormatEx) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpTTSEngine_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_sapiddk51_0000_0011 */
/* [local] */ 

typedef /* [restricted] */ struct SPWORDENTRY
    {
    SPWORDHANDLE hWord;
    WORD LangID;
    WCHAR *pszDisplayText;
    WCHAR *pszLexicalForm;
    SPPHONEID *aPhoneId;
    void *pvClientContext;
    } 	SPWORDENTRY;

typedef /* [restricted] */ struct SPRULEENTRY
    {
    SPRULEHANDLE hRule;
    SPSTATEHANDLE hInitialState;
    DWORD Attributes;
    void *pvClientRuleContext;
    void *pvClientGrammarContext;
    } 	SPRULEENTRY;

typedef 
enum SPTRANSITIONTYPE
    {
        SPTRANSEPSILON	= 0,
        SPTRANSWORD	= ( SPTRANSEPSILON + 1 ) ,
        SPTRANSRULE	= ( SPTRANSWORD + 1 ) ,
        SPTRANSTEXTBUF	= ( SPTRANSRULE + 1 ) ,
        SPTRANSWILDCARD	= ( SPTRANSTEXTBUF + 1 ) ,
        SPTRANSDICTATION	= ( SPTRANSWILDCARD + 1 ) 
    } 	SPTRANSITIONTYPE;

typedef /* [restricted] */ struct SPTRANSITIONENTRY
    {
    SPTRANSITIONID ID;
    SPSTATEHANDLE hNextState;
    BYTE Type;
    char RequiredConfidence;
    struct 
        {
        DWORD fHasProperty;
        } 	;
    float Weight;
    union 
        {
        struct 
            {
            SPSTATEHANDLE hRuleInitialState;
            SPRULEHANDLE hRule;
            void *pvClientRuleContext;
            } 	;
        struct 
            {
            SPWORDHANDLE hWord;
            void *pvClientWordContext;
            } 	;
        struct 
            {
            void *pvGrammarCookie;
            } 	;
        } 	;
    } 	SPTRANSITIONENTRY;

typedef /* [restricted] */ struct SPTRANSITIONPROPERTY
    {
    LPCWSTR pszName;
    ULONG ulId;
    LPCWSTR pszValue;
    VARIANT vValue;
    } 	SPTRANSITIONPROPERTY;

typedef /* [restricted] */ struct SPSTATEINFO
    {
    ULONG cAllocatedEntries;
    SPTRANSITIONENTRY *pTransitions;
    ULONG cEpsilons;
    ULONG cRules;
    ULONG cWords;
    ULONG cSpecialTransitions;
    } 	SPSTATEINFO;

typedef /* [restricted] */ struct SPPATHENTRY
    {
    SPTRANSITIONID hTransition;
    SPPHRASEELEMENT elem;
    } 	SPPATHENTRY;



extern RPC_IF_HANDLE __MIDL_itf_sapiddk51_0000_0011_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sapiddk51_0000_0011_v0_0_s_ifspec;

#ifndef __ISpCFGInterpreterSite_INTERFACE_DEFINED__
#define __ISpCFGInterpreterSite_INTERFACE_DEFINED__

/* interface ISpCFGInterpreterSite */
/* [restricted][local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpCFGInterpreterSite;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6A6FFAD8-78B6-473D-B844-98152E4FB16B")
    ISpCFGInterpreterSite : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AddTextReplacement( 
            /* [in] */ SPPHRASEREPLACEMENT *pReplace) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddProperty( 
            /* [in] */ const SPPHRASEPROPERTY *pProperty) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetResourceValue( 
            /* [in] */ LPCWSTR pszResourceName,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppCoMemResource) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpCFGInterpreterSiteVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpCFGInterpreterSite * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpCFGInterpreterSite * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpCFGInterpreterSite * This);
        
        HRESULT ( STDMETHODCALLTYPE *AddTextReplacement )( 
            ISpCFGInterpreterSite * This,
            /* [in] */ SPPHRASEREPLACEMENT *pReplace);
        
        HRESULT ( STDMETHODCALLTYPE *AddProperty )( 
            ISpCFGInterpreterSite * This,
            /* [in] */ const SPPHRASEPROPERTY *pProperty);
        
        HRESULT ( STDMETHODCALLTYPE *GetResourceValue )( 
            ISpCFGInterpreterSite * This,
            /* [in] */ LPCWSTR pszResourceName,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppCoMemResource);
        
        END_INTERFACE
    } ISpCFGInterpreterSiteVtbl;

    interface ISpCFGInterpreterSite
    {
        CONST_VTBL struct ISpCFGInterpreterSiteVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpCFGInterpreterSite_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpCFGInterpreterSite_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpCFGInterpreterSite_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpCFGInterpreterSite_AddTextReplacement(This,pReplace)	\
    ( (This)->lpVtbl -> AddTextReplacement(This,pReplace) ) 

#define ISpCFGInterpreterSite_AddProperty(This,pProperty)	\
    ( (This)->lpVtbl -> AddProperty(This,pProperty) ) 

#define ISpCFGInterpreterSite_GetResourceValue(This,pszResourceName,ppCoMemResource)	\
    ( (This)->lpVtbl -> GetResourceValue(This,pszResourceName,ppCoMemResource) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpCFGInterpreterSite_INTERFACE_DEFINED__ */


#ifndef __ISpCFGInterpreter_INTERFACE_DEFINED__
#define __ISpCFGInterpreter_INTERFACE_DEFINED__

/* interface ISpCFGInterpreter */
/* [restricted][local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpCFGInterpreter;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F3D3F926-11FC-11D3-BB97-00C04F8EE6C0")
    ISpCFGInterpreter : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE InitGrammar( 
            /* [in] */ LPCWSTR pszGrammarName,
            /* [in] */ const void **pvGrammarData) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Interpret( 
            /* [in] */ ISpPhraseBuilder *pPhrase,
            /* [in] */ const ULONG ulFirstElement,
            /* [in] */ const ULONG ulCountOfElements,
            /* [in] */ ISpCFGInterpreterSite *pSite) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpCFGInterpreterVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpCFGInterpreter * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpCFGInterpreter * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpCFGInterpreter * This);
        
        HRESULT ( STDMETHODCALLTYPE *InitGrammar )( 
            ISpCFGInterpreter * This,
            /* [in] */ LPCWSTR pszGrammarName,
            /* [in] */ const void **pvGrammarData);
        
        HRESULT ( STDMETHODCALLTYPE *Interpret )( 
            ISpCFGInterpreter * This,
            /* [in] */ ISpPhraseBuilder *pPhrase,
            /* [in] */ const ULONG ulFirstElement,
            /* [in] */ const ULONG ulCountOfElements,
            /* [in] */ ISpCFGInterpreterSite *pSite);
        
        END_INTERFACE
    } ISpCFGInterpreterVtbl;

    interface ISpCFGInterpreter
    {
        CONST_VTBL struct ISpCFGInterpreterVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpCFGInterpreter_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpCFGInterpreter_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpCFGInterpreter_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpCFGInterpreter_InitGrammar(This,pszGrammarName,pvGrammarData)	\
    ( (This)->lpVtbl -> InitGrammar(This,pszGrammarName,pvGrammarData) ) 

#define ISpCFGInterpreter_Interpret(This,pPhrase,ulFirstElement,ulCountOfElements,pSite)	\
    ( (This)->lpVtbl -> Interpret(This,pPhrase,ulFirstElement,ulCountOfElements,pSite) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpCFGInterpreter_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_sapiddk51_0000_0013 */
/* [local] */ 

typedef 
enum SPCFGNOTIFY
    {
        SPCFGN_ADD	= 0,
        SPCFGN_REMOVE	= ( SPCFGN_ADD + 1 ) ,
        SPCFGN_INVALIDATE	= ( SPCFGN_REMOVE + 1 ) ,
        SPCFGN_ACTIVATE	= ( SPCFGN_INVALIDATE + 1 ) ,
        SPCFGN_DEACTIVATE	= ( SPCFGN_ACTIVATE + 1 ) 
    } 	SPCFGNOTIFY;

typedef 
enum SPRESULTTYPE
    {
        SPRT_CFG	= 0,
        SPRT_SLM	= 1,
        SPRT_PROPRIETARY	= 2,
        SPRT_FALSE_RECOGNITION	= ( 1L << 2 ) 
    } 	SPRESULTTYPE;

typedef struct tagSPPHRASEALT
    {
    ISpPhraseBuilder *pPhrase;
    ULONG ulStartElementInParent;
    ULONG cElementsInParent;
    ULONG cElementsInAlternate;
    void *pvAltExtra;
    ULONG cbAltExtra;
    } 	SPPHRASEALT;

typedef struct SPRECORESULTINFO
    {
    ULONG cbSize;
    SPRESULTTYPE eResultType;
    BOOL fHypothesis;
    BOOL fProprietaryAutoPause;
    ULONGLONG ullStreamPosStart;
    ULONGLONG ullStreamPosEnd;
    SPGRAMMARHANDLE hGrammar;
    ULONG ulSizeEngineData;
    void *pvEngineData;
    ISpPhraseBuilder *pPhrase;
    SPPHRASEALT *aPhraseAlts;
    ULONG ulNumAlts;
    } 	SPRECORESULTINFO;

typedef 
enum SPWORDINFOOPT
    {
        SPWIO_NONE	= 0,
        SPWIO_WANT_TEXT	= 1
    } 	SPWORDINFOOPT;

typedef 
enum SPRULEINFOOPT
    {
        SPRIO_NONE	= 0
    } 	SPRULEINFOOPT;

typedef struct SPPARSEINFO
    {
    ULONG cbSize;
    SPRULEHANDLE hRule;
    ULONGLONG ullAudioStreamPosition;
    ULONG ulAudioSize;
    ULONG cTransitions;
    SPPATHENTRY *pPath;
    GUID SREngineID;
    ULONG ulSREnginePrivateDataSize;
    const BYTE *pSREnginePrivateData;
    BOOL fHypothesis;
    } 	SPPARSEINFO;



extern RPC_IF_HANDLE __MIDL_itf_sapiddk51_0000_0013_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sapiddk51_0000_0013_v0_0_s_ifspec;

#ifndef __ISpSREngineSite_INTERFACE_DEFINED__
#define __ISpSREngineSite_INTERFACE_DEFINED__

/* interface ISpSREngineSite */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpSREngineSite;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3B414AEC-720C-4883-B9EF-178CD394FB3A")
    ISpSREngineSite : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Read( 
            /* [in] */ void *pv,
            /* [in] */ ULONG cb,
            /* [out] */ ULONG *pcbRead) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DataAvailable( 
            /* [out] */ ULONG *pcb) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetBufferNotifySize( 
            /* [in] */ ULONG cbSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ParseFromTransitions( 
            /* [in] */ const SPPARSEINFO *pParseInfo,
            /* [out] */ ISpPhraseBuilder **ppNewPhrase) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Recognition( 
            /* [in] */ const SPRECORESULTINFO *pResultInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddEvent( 
            /* [in] */ const SPEVENT *pEvent,
            /* [in] */ SPRECOCONTEXTHANDLE hSAPIRecoContext) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Synchronize( 
            /* [in] */ ULONGLONG ullProcessedThruPos) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetWordInfo( 
            /* [out][in] */ SPWORDENTRY *pWordEntry,
            /* [in] */ SPWORDINFOOPT Options) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetWordClientContext( 
            /* [in] */ SPWORDHANDLE hWord,
            /* [in] */ void *pvClientContext) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRuleInfo( 
            /* [out][in] */ SPRULEENTRY *pRuleEntry,
            /* [in] */ SPRULEINFOOPT Options) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetRuleClientContext( 
            /* [in] */ SPRULEHANDLE hRule,
            /* [in] */ void *pvClientContext) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStateInfo( 
            /* [in] */ SPSTATEHANDLE hState,
            /* [out] */ SPSTATEINFO *pStateInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetResource( 
            /* [in] */ SPRULEHANDLE hRule,
            /* [in] */ LPCWSTR pszResourceName,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppCoMemResource) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTransitionProperty( 
            /* [in] */ SPTRANSITIONID ID,
            /* [out][annotation] */ 
            _Outptr_  SPTRANSITIONPROPERTY **ppCoMemProperty) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsAlternate( 
            /* [in] */ SPRULEHANDLE hRule,
            /* [in] */ SPRULEHANDLE hAltRule) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMaxAlternates( 
            /* [in] */ SPRULEHANDLE hRule,
            /* [out] */ ULONG *pulNumAlts) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetContextMaxAlternates( 
            /* [in] */ SPRECOCONTEXTHANDLE hContext,
            /* [out] */ ULONG *pulNumAlts) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UpdateRecoPos( 
            /* [in] */ ULONGLONG ullCurrentRecoPos) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpSREngineSiteVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpSREngineSite * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpSREngineSite * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpSREngineSite * This);
        
        HRESULT ( STDMETHODCALLTYPE *Read )( 
            ISpSREngineSite * This,
            /* [in] */ void *pv,
            /* [in] */ ULONG cb,
            /* [out] */ ULONG *pcbRead);
        
        HRESULT ( STDMETHODCALLTYPE *DataAvailable )( 
            ISpSREngineSite * This,
            /* [out] */ ULONG *pcb);
        
        HRESULT ( STDMETHODCALLTYPE *SetBufferNotifySize )( 
            ISpSREngineSite * This,
            /* [in] */ ULONG cbSize);
        
        HRESULT ( STDMETHODCALLTYPE *ParseFromTransitions )( 
            ISpSREngineSite * This,
            /* [in] */ const SPPARSEINFO *pParseInfo,
            /* [out] */ ISpPhraseBuilder **ppNewPhrase);
        
        HRESULT ( STDMETHODCALLTYPE *Recognition )( 
            ISpSREngineSite * This,
            /* [in] */ const SPRECORESULTINFO *pResultInfo);
        
        HRESULT ( STDMETHODCALLTYPE *AddEvent )( 
            ISpSREngineSite * This,
            /* [in] */ const SPEVENT *pEvent,
            /* [in] */ SPRECOCONTEXTHANDLE hSAPIRecoContext);
        
        HRESULT ( STDMETHODCALLTYPE *Synchronize )( 
            ISpSREngineSite * This,
            /* [in] */ ULONGLONG ullProcessedThruPos);
        
        HRESULT ( STDMETHODCALLTYPE *GetWordInfo )( 
            ISpSREngineSite * This,
            /* [out][in] */ SPWORDENTRY *pWordEntry,
            /* [in] */ SPWORDINFOOPT Options);
        
        HRESULT ( STDMETHODCALLTYPE *SetWordClientContext )( 
            ISpSREngineSite * This,
            /* [in] */ SPWORDHANDLE hWord,
            /* [in] */ void *pvClientContext);
        
        HRESULT ( STDMETHODCALLTYPE *GetRuleInfo )( 
            ISpSREngineSite * This,
            /* [out][in] */ SPRULEENTRY *pRuleEntry,
            /* [in] */ SPRULEINFOOPT Options);
        
        HRESULT ( STDMETHODCALLTYPE *SetRuleClientContext )( 
            ISpSREngineSite * This,
            /* [in] */ SPRULEHANDLE hRule,
            /* [in] */ void *pvClientContext);
        
        HRESULT ( STDMETHODCALLTYPE *GetStateInfo )( 
            ISpSREngineSite * This,
            /* [in] */ SPSTATEHANDLE hState,
            /* [out] */ SPSTATEINFO *pStateInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetResource )( 
            ISpSREngineSite * This,
            /* [in] */ SPRULEHANDLE hRule,
            /* [in] */ LPCWSTR pszResourceName,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppCoMemResource);
        
        HRESULT ( STDMETHODCALLTYPE *GetTransitionProperty )( 
            ISpSREngineSite * This,
            /* [in] */ SPTRANSITIONID ID,
            /* [out][annotation] */ 
            _Outptr_  SPTRANSITIONPROPERTY **ppCoMemProperty);
        
        HRESULT ( STDMETHODCALLTYPE *IsAlternate )( 
            ISpSREngineSite * This,
            /* [in] */ SPRULEHANDLE hRule,
            /* [in] */ SPRULEHANDLE hAltRule);
        
        HRESULT ( STDMETHODCALLTYPE *GetMaxAlternates )( 
            ISpSREngineSite * This,
            /* [in] */ SPRULEHANDLE hRule,
            /* [out] */ ULONG *pulNumAlts);
        
        HRESULT ( STDMETHODCALLTYPE *GetContextMaxAlternates )( 
            ISpSREngineSite * This,
            /* [in] */ SPRECOCONTEXTHANDLE hContext,
            /* [out] */ ULONG *pulNumAlts);
        
        HRESULT ( STDMETHODCALLTYPE *UpdateRecoPos )( 
            ISpSREngineSite * This,
            /* [in] */ ULONGLONG ullCurrentRecoPos);
        
        END_INTERFACE
    } ISpSREngineSiteVtbl;

    interface ISpSREngineSite
    {
        CONST_VTBL struct ISpSREngineSiteVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpSREngineSite_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpSREngineSite_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpSREngineSite_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpSREngineSite_Read(This,pv,cb,pcbRead)	\
    ( (This)->lpVtbl -> Read(This,pv,cb,pcbRead) ) 

#define ISpSREngineSite_DataAvailable(This,pcb)	\
    ( (This)->lpVtbl -> DataAvailable(This,pcb) ) 

#define ISpSREngineSite_SetBufferNotifySize(This,cbSize)	\
    ( (This)->lpVtbl -> SetBufferNotifySize(This,cbSize) ) 

#define ISpSREngineSite_ParseFromTransitions(This,pParseInfo,ppNewPhrase)	\
    ( (This)->lpVtbl -> ParseFromTransitions(This,pParseInfo,ppNewPhrase) ) 

#define ISpSREngineSite_Recognition(This,pResultInfo)	\
    ( (This)->lpVtbl -> Recognition(This,pResultInfo) ) 

#define ISpSREngineSite_AddEvent(This,pEvent,hSAPIRecoContext)	\
    ( (This)->lpVtbl -> AddEvent(This,pEvent,hSAPIRecoContext) ) 

#define ISpSREngineSite_Synchronize(This,ullProcessedThruPos)	\
    ( (This)->lpVtbl -> Synchronize(This,ullProcessedThruPos) ) 

#define ISpSREngineSite_GetWordInfo(This,pWordEntry,Options)	\
    ( (This)->lpVtbl -> GetWordInfo(This,pWordEntry,Options) ) 

#define ISpSREngineSite_SetWordClientContext(This,hWord,pvClientContext)	\
    ( (This)->lpVtbl -> SetWordClientContext(This,hWord,pvClientContext) ) 

#define ISpSREngineSite_GetRuleInfo(This,pRuleEntry,Options)	\
    ( (This)->lpVtbl -> GetRuleInfo(This,pRuleEntry,Options) ) 

#define ISpSREngineSite_SetRuleClientContext(This,hRule,pvClientContext)	\
    ( (This)->lpVtbl -> SetRuleClientContext(This,hRule,pvClientContext) ) 

#define ISpSREngineSite_GetStateInfo(This,hState,pStateInfo)	\
    ( (This)->lpVtbl -> GetStateInfo(This,hState,pStateInfo) ) 

#define ISpSREngineSite_GetResource(This,hRule,pszResourceName,ppCoMemResource)	\
    ( (This)->lpVtbl -> GetResource(This,hRule,pszResourceName,ppCoMemResource) ) 

#define ISpSREngineSite_GetTransitionProperty(This,ID,ppCoMemProperty)	\
    ( (This)->lpVtbl -> GetTransitionProperty(This,ID,ppCoMemProperty) ) 

#define ISpSREngineSite_IsAlternate(This,hRule,hAltRule)	\
    ( (This)->lpVtbl -> IsAlternate(This,hRule,hAltRule) ) 

#define ISpSREngineSite_GetMaxAlternates(This,hRule,pulNumAlts)	\
    ( (This)->lpVtbl -> GetMaxAlternates(This,hRule,pulNumAlts) ) 

#define ISpSREngineSite_GetContextMaxAlternates(This,hContext,pulNumAlts)	\
    ( (This)->lpVtbl -> GetContextMaxAlternates(This,hContext,pulNumAlts) ) 

#define ISpSREngineSite_UpdateRecoPos(This,ullCurrentRecoPos)	\
    ( (This)->lpVtbl -> UpdateRecoPos(This,ullCurrentRecoPos) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpSREngineSite_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_sapiddk51_0000_0014 */
/* [local] */ 

typedef 
enum SPPROPSRC
    {
        SPPROPSRC_RECO_INST	= 0,
        SPPROPSRC_RECO_CTX	= ( SPPROPSRC_RECO_INST + 1 ) ,
        SPPROPSRC_RECO_GRAMMAR	= ( SPPROPSRC_RECO_CTX + 1 ) 
    } 	SPPROPSRC;



extern RPC_IF_HANDLE __MIDL_itf_sapiddk51_0000_0014_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sapiddk51_0000_0014_v0_0_s_ifspec;

#ifndef __ISpSREngine_INTERFACE_DEFINED__
#define __ISpSREngine_INTERFACE_DEFINED__

/* interface ISpSREngine */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpSREngine;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2F472991-854B-4465-B613-FBAFB3AD8ED8")
    ISpSREngine : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetSite( 
            /* [in] */ ISpSREngineSite *pSite) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetInputAudioFormat( 
            /* [in] */ const GUID *pguidSourceFormatId,
            /* [in] */ const WAVEFORMATEX *pSourceWaveFormatEx,
            /* [out] */ GUID *pguidDesiredFormatId,
            /* [out][annotation] */ 
            _Outptr_  WAVEFORMATEX **ppCoMemDesiredWaveFormatEx) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RecognizeStream( 
            /* [in] */ REFGUID rguidFmtId,
            /* [in] */ const WAVEFORMATEX *pWaveFormatEx,
            /* [in] */ HANDLE hRequestSync,
            /* [in] */ HANDLE hDataAvailable,
            /* [in] */ HANDLE hExit,
            /* [in] */ BOOL fNewAudioStream,
            /* [in] */ BOOL fRealTimeAudio,
            /* [in] */ ISpObjectToken *pAudioObjectToken) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetRecoProfile( 
            /* [in] */ ISpObjectToken *pProfile) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnCreateGrammar( 
            /* [in] */ void *pvEngineRecoContext,
            /* [in] */ SPGRAMMARHANDLE hSAPIGrammar,
            /* [out][annotation] */ 
            _Outptr_  void **ppvEngineGrammarContext) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnDeleteGrammar( 
            /* [in] */ void *pvEngineGrammar) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadProprietaryGrammar( 
            /* [in] */ void *pvEngineGrammar,
            /* [in] */ REFGUID rguidParam,
            /* [string][in] */ LPCWSTR pszStringParam,
            /* [in] */ const void *pvDataParam,
            /* [in] */ ULONG ulDataSize,
            /* [in] */ SPLOADOPTIONS Options) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UnloadProprietaryGrammar( 
            /* [in] */ void *pvEngineGrammar) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetProprietaryRuleState( 
            /* [in] */ void *pvEngineGrammar,
            /* [string][in] */ LPCWSTR pszName,
            /* [in] */ void *pReserved,
            /* [in] */ SPRULESTATE NewState,
            /* [out] */ ULONG *pcRulesChanged) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetProprietaryRuleIdState( 
            /* [in] */ void *pvEngineGrammar,
            /* [in] */ DWORD dwRuleId,
            /* [in] */ SPRULESTATE NewState) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadSLM( 
            /* [in] */ void *pvEngineGrammar,
            /* [string][in] */ LPCWSTR pszTopicName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UnloadSLM( 
            /* [in] */ void *pvEngineGrammar) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetSLMState( 
            /* [in] */ void *pvEngineGrammar,
            /* [in] */ SPRULESTATE NewState) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetWordSequenceData( 
            /* [in] */ void *pvEngineGrammar,
            /* [in][annotation] */ 
            _In_reads_(cchText)  const WCHAR *pText,
            /* [in] */ ULONG cchText,
            /* [in] */ const SPTEXTSELECTIONINFO *pInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetTextSelection( 
            /* [in] */ void *pvEngineGrammar,
            /* [in] */ const SPTEXTSELECTIONINFO *pInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsPronounceable( 
            /* [in] */ void *pvEngineGrammar,
            /* [string][in] */ LPCWSTR pszWord,
            /* [out] */ SPWORDPRONOUNCEABLE *pWordPronounceable) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnCreateRecoContext( 
            /* [in] */ SPRECOCONTEXTHANDLE hSAPIRecoContext,
            /* [out] */ void **ppvEngineContext) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnDeleteRecoContext( 
            /* [in] */ void *pvEngineContext) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PrivateCall( 
            /* [in] */ void *pvEngineContext,
            /* [out][in] */ PVOID pCallFrame,
            /* [in] */ ULONG ulCallFrameSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAdaptationData( 
            /* [in] */ void *pvEngineContext,
            /* [annotation] */ 
            _In_reads_(cch)  const WCHAR *pAdaptationData,
            /* [in] */ const ULONG cch) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPropertyNum( 
            /* [in] */ SPPROPSRC eSrc,
            /* [in] */ void *pvSrcObj,
            /* [in] */ const WCHAR *pName,
            /* [in] */ LONG lValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPropertyNum( 
            /* [in] */ SPPROPSRC eSrc,
            /* [in] */ void *pvSrcObj,
            /* [in] */ const WCHAR *pName,
            /* [out] */ LONG *lValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPropertyString( 
            /* [in] */ SPPROPSRC eSrc,
            /* [in] */ void *pvSrcObj,
            /* [in] */ LPCWSTR pName,
            /* [in] */ LPCWSTR pValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPropertyString( 
            /* [in] */ SPPROPSRC eSrc,
            /* [in] */ void *pvSrcObj,
            /* [in] */ LPCWSTR pName,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppCoMemValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetGrammarState( 
            /* [in] */ void *pvEngineGrammar,
            /* [in] */ SPGRAMMARSTATE eGrammarState) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE WordNotify( 
            /* [in] */ SPCFGNOTIFY Action,
            /* [in] */ ULONG cWords,
            /* [in] */ const SPWORDENTRY *pWords) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RuleNotify( 
            /* [in] */ SPCFGNOTIFY Action,
            /* [in] */ ULONG cRules,
            /* [in] */ const SPRULEENTRY *pRules) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PrivateCallEx( 
            /* [in] */ void *pvEngineContext,
            /* [in] */ const void *pInCallFrame,
            /* [in] */ ULONG ulInCallFrameSize,
            /* [out] */ void **ppvCoMemResponse,
            /* [out] */ ULONG *pulResponseSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetContextState( 
            /* [in] */ void *pvEngineContext,
            /* [in] */ SPCONTEXTSTATE eContextState) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpSREngineVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpSREngine * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpSREngine * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpSREngine * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetSite )( 
            ISpSREngine * This,
            /* [in] */ ISpSREngineSite *pSite);
        
        HRESULT ( STDMETHODCALLTYPE *GetInputAudioFormat )( 
            ISpSREngine * This,
            /* [in] */ const GUID *pguidSourceFormatId,
            /* [in] */ const WAVEFORMATEX *pSourceWaveFormatEx,
            /* [out] */ GUID *pguidDesiredFormatId,
            /* [out][annotation] */ 
            _Outptr_  WAVEFORMATEX **ppCoMemDesiredWaveFormatEx);
        
        HRESULT ( STDMETHODCALLTYPE *RecognizeStream )( 
            ISpSREngine * This,
            /* [in] */ REFGUID rguidFmtId,
            /* [in] */ const WAVEFORMATEX *pWaveFormatEx,
            /* [in] */ HANDLE hRequestSync,
            /* [in] */ HANDLE hDataAvailable,
            /* [in] */ HANDLE hExit,
            /* [in] */ BOOL fNewAudioStream,
            /* [in] */ BOOL fRealTimeAudio,
            /* [in] */ ISpObjectToken *pAudioObjectToken);
        
        HRESULT ( STDMETHODCALLTYPE *SetRecoProfile )( 
            ISpSREngine * This,
            /* [in] */ ISpObjectToken *pProfile);
        
        HRESULT ( STDMETHODCALLTYPE *OnCreateGrammar )( 
            ISpSREngine * This,
            /* [in] */ void *pvEngineRecoContext,
            /* [in] */ SPGRAMMARHANDLE hSAPIGrammar,
            /* [out][annotation] */ 
            _Outptr_  void **ppvEngineGrammarContext);
        
        HRESULT ( STDMETHODCALLTYPE *OnDeleteGrammar )( 
            ISpSREngine * This,
            /* [in] */ void *pvEngineGrammar);
        
        HRESULT ( STDMETHODCALLTYPE *LoadProprietaryGrammar )( 
            ISpSREngine * This,
            /* [in] */ void *pvEngineGrammar,
            /* [in] */ REFGUID rguidParam,
            /* [string][in] */ LPCWSTR pszStringParam,
            /* [in] */ const void *pvDataParam,
            /* [in] */ ULONG ulDataSize,
            /* [in] */ SPLOADOPTIONS Options);
        
        HRESULT ( STDMETHODCALLTYPE *UnloadProprietaryGrammar )( 
            ISpSREngine * This,
            /* [in] */ void *pvEngineGrammar);
        
        HRESULT ( STDMETHODCALLTYPE *SetProprietaryRuleState )( 
            ISpSREngine * This,
            /* [in] */ void *pvEngineGrammar,
            /* [string][in] */ LPCWSTR pszName,
            /* [in] */ void *pReserved,
            /* [in] */ SPRULESTATE NewState,
            /* [out] */ ULONG *pcRulesChanged);
        
        HRESULT ( STDMETHODCALLTYPE *SetProprietaryRuleIdState )( 
            ISpSREngine * This,
            /* [in] */ void *pvEngineGrammar,
            /* [in] */ DWORD dwRuleId,
            /* [in] */ SPRULESTATE NewState);
        
        HRESULT ( STDMETHODCALLTYPE *LoadSLM )( 
            ISpSREngine * This,
            /* [in] */ void *pvEngineGrammar,
            /* [string][in] */ LPCWSTR pszTopicName);
        
        HRESULT ( STDMETHODCALLTYPE *UnloadSLM )( 
            ISpSREngine * This,
            /* [in] */ void *pvEngineGrammar);
        
        HRESULT ( STDMETHODCALLTYPE *SetSLMState )( 
            ISpSREngine * This,
            /* [in] */ void *pvEngineGrammar,
            /* [in] */ SPRULESTATE NewState);
        
        HRESULT ( STDMETHODCALLTYPE *SetWordSequenceData )( 
            ISpSREngine * This,
            /* [in] */ void *pvEngineGrammar,
            /* [in][annotation] */ 
            _In_reads_(cchText)  const WCHAR *pText,
            /* [in] */ ULONG cchText,
            /* [in] */ const SPTEXTSELECTIONINFO *pInfo);
        
        HRESULT ( STDMETHODCALLTYPE *SetTextSelection )( 
            ISpSREngine * This,
            /* [in] */ void *pvEngineGrammar,
            /* [in] */ const SPTEXTSELECTIONINFO *pInfo);
        
        HRESULT ( STDMETHODCALLTYPE *IsPronounceable )( 
            ISpSREngine * This,
            /* [in] */ void *pvEngineGrammar,
            /* [string][in] */ LPCWSTR pszWord,
            /* [out] */ SPWORDPRONOUNCEABLE *pWordPronounceable);
        
        HRESULT ( STDMETHODCALLTYPE *OnCreateRecoContext )( 
            ISpSREngine * This,
            /* [in] */ SPRECOCONTEXTHANDLE hSAPIRecoContext,
            /* [out] */ void **ppvEngineContext);
        
        HRESULT ( STDMETHODCALLTYPE *OnDeleteRecoContext )( 
            ISpSREngine * This,
            /* [in] */ void *pvEngineContext);
        
        HRESULT ( STDMETHODCALLTYPE *PrivateCall )( 
            ISpSREngine * This,
            /* [in] */ void *pvEngineContext,
            /* [out][in] */ PVOID pCallFrame,
            /* [in] */ ULONG ulCallFrameSize);
        
        HRESULT ( STDMETHODCALLTYPE *SetAdaptationData )( 
            ISpSREngine * This,
            /* [in] */ void *pvEngineContext,
            /* [annotation] */ 
            _In_reads_(cch)  const WCHAR *pAdaptationData,
            /* [in] */ const ULONG cch);
        
        HRESULT ( STDMETHODCALLTYPE *SetPropertyNum )( 
            ISpSREngine * This,
            /* [in] */ SPPROPSRC eSrc,
            /* [in] */ void *pvSrcObj,
            /* [in] */ const WCHAR *pName,
            /* [in] */ LONG lValue);
        
        HRESULT ( STDMETHODCALLTYPE *GetPropertyNum )( 
            ISpSREngine * This,
            /* [in] */ SPPROPSRC eSrc,
            /* [in] */ void *pvSrcObj,
            /* [in] */ const WCHAR *pName,
            /* [out] */ LONG *lValue);
        
        HRESULT ( STDMETHODCALLTYPE *SetPropertyString )( 
            ISpSREngine * This,
            /* [in] */ SPPROPSRC eSrc,
            /* [in] */ void *pvSrcObj,
            /* [in] */ LPCWSTR pName,
            /* [in] */ LPCWSTR pValue);
        
        HRESULT ( STDMETHODCALLTYPE *GetPropertyString )( 
            ISpSREngine * This,
            /* [in] */ SPPROPSRC eSrc,
            /* [in] */ void *pvSrcObj,
            /* [in] */ LPCWSTR pName,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppCoMemValue);
        
        HRESULT ( STDMETHODCALLTYPE *SetGrammarState )( 
            ISpSREngine * This,
            /* [in] */ void *pvEngineGrammar,
            /* [in] */ SPGRAMMARSTATE eGrammarState);
        
        HRESULT ( STDMETHODCALLTYPE *WordNotify )( 
            ISpSREngine * This,
            /* [in] */ SPCFGNOTIFY Action,
            /* [in] */ ULONG cWords,
            /* [in] */ const SPWORDENTRY *pWords);
        
        HRESULT ( STDMETHODCALLTYPE *RuleNotify )( 
            ISpSREngine * This,
            /* [in] */ SPCFGNOTIFY Action,
            /* [in] */ ULONG cRules,
            /* [in] */ const SPRULEENTRY *pRules);
        
        HRESULT ( STDMETHODCALLTYPE *PrivateCallEx )( 
            ISpSREngine * This,
            /* [in] */ void *pvEngineContext,
            /* [in] */ const void *pInCallFrame,
            /* [in] */ ULONG ulInCallFrameSize,
            /* [out] */ void **ppvCoMemResponse,
            /* [out] */ ULONG *pulResponseSize);
        
        HRESULT ( STDMETHODCALLTYPE *SetContextState )( 
            ISpSREngine * This,
            /* [in] */ void *pvEngineContext,
            /* [in] */ SPCONTEXTSTATE eContextState);
        
        END_INTERFACE
    } ISpSREngineVtbl;

    interface ISpSREngine
    {
        CONST_VTBL struct ISpSREngineVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpSREngine_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpSREngine_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpSREngine_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpSREngine_SetSite(This,pSite)	\
    ( (This)->lpVtbl -> SetSite(This,pSite) ) 

#define ISpSREngine_GetInputAudioFormat(This,pguidSourceFormatId,pSourceWaveFormatEx,pguidDesiredFormatId,ppCoMemDesiredWaveFormatEx)	\
    ( (This)->lpVtbl -> GetInputAudioFormat(This,pguidSourceFormatId,pSourceWaveFormatEx,pguidDesiredFormatId,ppCoMemDesiredWaveFormatEx) ) 

#define ISpSREngine_RecognizeStream(This,rguidFmtId,pWaveFormatEx,hRequestSync,hDataAvailable,hExit,fNewAudioStream,fRealTimeAudio,pAudioObjectToken)	\
    ( (This)->lpVtbl -> RecognizeStream(This,rguidFmtId,pWaveFormatEx,hRequestSync,hDataAvailable,hExit,fNewAudioStream,fRealTimeAudio,pAudioObjectToken) ) 

#define ISpSREngine_SetRecoProfile(This,pProfile)	\
    ( (This)->lpVtbl -> SetRecoProfile(This,pProfile) ) 

#define ISpSREngine_OnCreateGrammar(This,pvEngineRecoContext,hSAPIGrammar,ppvEngineGrammarContext)	\
    ( (This)->lpVtbl -> OnCreateGrammar(This,pvEngineRecoContext,hSAPIGrammar,ppvEngineGrammarContext) ) 

#define ISpSREngine_OnDeleteGrammar(This,pvEngineGrammar)	\
    ( (This)->lpVtbl -> OnDeleteGrammar(This,pvEngineGrammar) ) 

#define ISpSREngine_LoadProprietaryGrammar(This,pvEngineGrammar,rguidParam,pszStringParam,pvDataParam,ulDataSize,Options)	\
    ( (This)->lpVtbl -> LoadProprietaryGrammar(This,pvEngineGrammar,rguidParam,pszStringParam,pvDataParam,ulDataSize,Options) ) 

#define ISpSREngine_UnloadProprietaryGrammar(This,pvEngineGrammar)	\
    ( (This)->lpVtbl -> UnloadProprietaryGrammar(This,pvEngineGrammar) ) 

#define ISpSREngine_SetProprietaryRuleState(This,pvEngineGrammar,pszName,pReserved,NewState,pcRulesChanged)	\
    ( (This)->lpVtbl -> SetProprietaryRuleState(This,pvEngineGrammar,pszName,pReserved,NewState,pcRulesChanged) ) 

#define ISpSREngine_SetProprietaryRuleIdState(This,pvEngineGrammar,dwRuleId,NewState)	\
    ( (This)->lpVtbl -> SetProprietaryRuleIdState(This,pvEngineGrammar,dwRuleId,NewState) ) 

#define ISpSREngine_LoadSLM(This,pvEngineGrammar,pszTopicName)	\
    ( (This)->lpVtbl -> LoadSLM(This,pvEngineGrammar,pszTopicName) ) 

#define ISpSREngine_UnloadSLM(This,pvEngineGrammar)	\
    ( (This)->lpVtbl -> UnloadSLM(This,pvEngineGrammar) ) 

#define ISpSREngine_SetSLMState(This,pvEngineGrammar,NewState)	\
    ( (This)->lpVtbl -> SetSLMState(This,pvEngineGrammar,NewState) ) 

#define ISpSREngine_SetWordSequenceData(This,pvEngineGrammar,pText,cchText,pInfo)	\
    ( (This)->lpVtbl -> SetWordSequenceData(This,pvEngineGrammar,pText,cchText,pInfo) ) 

#define ISpSREngine_SetTextSelection(This,pvEngineGrammar,pInfo)	\
    ( (This)->lpVtbl -> SetTextSelection(This,pvEngineGrammar,pInfo) ) 

#define ISpSREngine_IsPronounceable(This,pvEngineGrammar,pszWord,pWordPronounceable)	\
    ( (This)->lpVtbl -> IsPronounceable(This,pvEngineGrammar,pszWord,pWordPronounceable) ) 

#define ISpSREngine_OnCreateRecoContext(This,hSAPIRecoContext,ppvEngineContext)	\
    ( (This)->lpVtbl -> OnCreateRecoContext(This,hSAPIRecoContext,ppvEngineContext) ) 

#define ISpSREngine_OnDeleteRecoContext(This,pvEngineContext)	\
    ( (This)->lpVtbl -> OnDeleteRecoContext(This,pvEngineContext) ) 

#define ISpSREngine_PrivateCall(This,pvEngineContext,pCallFrame,ulCallFrameSize)	\
    ( (This)->lpVtbl -> PrivateCall(This,pvEngineContext,pCallFrame,ulCallFrameSize) ) 

#define ISpSREngine_SetAdaptationData(This,pvEngineContext,pAdaptationData,cch)	\
    ( (This)->lpVtbl -> SetAdaptationData(This,pvEngineContext,pAdaptationData,cch) ) 

#define ISpSREngine_SetPropertyNum(This,eSrc,pvSrcObj,pName,lValue)	\
    ( (This)->lpVtbl -> SetPropertyNum(This,eSrc,pvSrcObj,pName,lValue) ) 

#define ISpSREngine_GetPropertyNum(This,eSrc,pvSrcObj,pName,lValue)	\
    ( (This)->lpVtbl -> GetPropertyNum(This,eSrc,pvSrcObj,pName,lValue) ) 

#define ISpSREngine_SetPropertyString(This,eSrc,pvSrcObj,pName,pValue)	\
    ( (This)->lpVtbl -> SetPropertyString(This,eSrc,pvSrcObj,pName,pValue) ) 

#define ISpSREngine_GetPropertyString(This,eSrc,pvSrcObj,pName,ppCoMemValue)	\
    ( (This)->lpVtbl -> GetPropertyString(This,eSrc,pvSrcObj,pName,ppCoMemValue) ) 

#define ISpSREngine_SetGrammarState(This,pvEngineGrammar,eGrammarState)	\
    ( (This)->lpVtbl -> SetGrammarState(This,pvEngineGrammar,eGrammarState) ) 

#define ISpSREngine_WordNotify(This,Action,cWords,pWords)	\
    ( (This)->lpVtbl -> WordNotify(This,Action,cWords,pWords) ) 

#define ISpSREngine_RuleNotify(This,Action,cRules,pRules)	\
    ( (This)->lpVtbl -> RuleNotify(This,Action,cRules,pRules) ) 

#define ISpSREngine_PrivateCallEx(This,pvEngineContext,pInCallFrame,ulInCallFrameSize,ppvCoMemResponse,pulResponseSize)	\
    ( (This)->lpVtbl -> PrivateCallEx(This,pvEngineContext,pInCallFrame,ulInCallFrameSize,ppvCoMemResponse,pulResponseSize) ) 

#define ISpSREngine_SetContextState(This,pvEngineContext,eContextState)	\
    ( (This)->lpVtbl -> SetContextState(This,pvEngineContext,eContextState) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpSREngine_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_sapiddk51_0000_0015 */
/* [local] */ 

typedef struct tagSPPHRASEALTREQUEST
    {
    ULONG ulStartElement;
    ULONG cElements;
    ULONG ulRequestAltCount;
    void *pvResultExtra;
    ULONG cbResultExtra;
    ISpPhrase *pPhrase;
    ISpRecoContext *pRecoContext;
    } 	SPPHRASEALTREQUEST;



extern RPC_IF_HANDLE __MIDL_itf_sapiddk51_0000_0015_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sapiddk51_0000_0015_v0_0_s_ifspec;

#ifndef ___ISpPrivateEngineCall_INTERFACE_DEFINED__
#define ___ISpPrivateEngineCall_INTERFACE_DEFINED__

/* interface _ISpPrivateEngineCall */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID__ISpPrivateEngineCall;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8E7C791E-4467-11D3-9723-00C04F72DB08")
    _ISpPrivateEngineCall : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CallEngine( 
            /* [out][in][annotation] */ 
            _Inout_updates_bytes_(ulCallFrameSize)  void *pCallFrame,
            /* [in] */ ULONG ulCallFrameSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CallEngineEx( 
            /* [in][annotation] */ 
            _In_reads_bytes_(ulInFrameSize)  const void *pInFrame,
            /* [in] */ ULONG ulInFrameSize,
            /* [out][annotation] */ 
            _Outptr_result_buffer_maybenull_(*pulOutFrameSize)  void **ppCoMemOutFrame,
            /* [out][annotation] */ 
            _Out_writes_(1)  ULONG *pulOutFrameSize) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct _ISpPrivateEngineCallVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _ISpPrivateEngineCall * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _ISpPrivateEngineCall * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _ISpPrivateEngineCall * This);
        
        HRESULT ( STDMETHODCALLTYPE *CallEngine )( 
            _ISpPrivateEngineCall * This,
            /* [out][in][annotation] */ 
            _Inout_updates_bytes_(ulCallFrameSize)  void *pCallFrame,
            /* [in] */ ULONG ulCallFrameSize);
        
        HRESULT ( STDMETHODCALLTYPE *CallEngineEx )( 
            _ISpPrivateEngineCall * This,
            /* [in][annotation] */ 
            _In_reads_bytes_(ulInFrameSize)  const void *pInFrame,
            /* [in] */ ULONG ulInFrameSize,
            /* [out][annotation] */ 
            _Outptr_result_buffer_maybenull_(*pulOutFrameSize)  void **ppCoMemOutFrame,
            /* [out][annotation] */ 
            _Out_writes_(1)  ULONG *pulOutFrameSize);
        
        END_INTERFACE
    } _ISpPrivateEngineCallVtbl;

    interface _ISpPrivateEngineCall
    {
        CONST_VTBL struct _ISpPrivateEngineCallVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _ISpPrivateEngineCall_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _ISpPrivateEngineCall_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _ISpPrivateEngineCall_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _ISpPrivateEngineCall_CallEngine(This,pCallFrame,ulCallFrameSize)	\
    ( (This)->lpVtbl -> CallEngine(This,pCallFrame,ulCallFrameSize) ) 

#define _ISpPrivateEngineCall_CallEngineEx(This,pInFrame,ulInFrameSize,ppCoMemOutFrame,pulOutFrameSize)	\
    ( (This)->lpVtbl -> CallEngineEx(This,pInFrame,ulInFrameSize,ppCoMemOutFrame,pulOutFrameSize) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* ___ISpPrivateEngineCall_INTERFACE_DEFINED__ */



#ifndef __SpeechDDKLib_LIBRARY_DEFINED__
#define __SpeechDDKLib_LIBRARY_DEFINED__

/* library SpeechDDKLib */
/* [version][uuid][helpstring] */ 


EXTERN_C const IID LIBID_SpeechDDKLib;

EXTERN_C const CLSID CLSID_SpDataKey;

#ifdef __cplusplus

class DECLSPEC_UUID("D9F6EE60-58C9-458B-88E1-2F908FD7F87C")
SpDataKey;
#endif

EXTERN_C const CLSID CLSID_SpObjectTokenEnum;

#ifdef __cplusplus

class DECLSPEC_UUID("3918D75F-0ACB-41F2-B733-92AA15BCECF6")
SpObjectTokenEnum;
#endif

EXTERN_C const CLSID CLSID_SpPhraseBuilder;

#ifdef __cplusplus

class DECLSPEC_UUID("777B6BBD-2FF2-11D3-88FE-00C04F8EF9B5")
SpPhraseBuilder;
#endif

EXTERN_C const CLSID CLSID_SpITNProcessor;

#ifdef __cplusplus

class DECLSPEC_UUID("12D73610-A1C9-11D3-BC90-00C04F72DF9F")
SpITNProcessor;
#endif

EXTERN_C const CLSID CLSID_SpGrammarCompiler;

#ifdef __cplusplus

class DECLSPEC_UUID("B1E29D59-A675-11D2-8302-00C04F8EE6C0")
SpGrammarCompiler;
#endif

EXTERN_C const CLSID CLSID_SpGramCompBackend;

#ifdef __cplusplus

class DECLSPEC_UUID("DA93E903-C843-11D2-A084-00C04F8EF9B5")
SpGramCompBackend;
#endif
#endif /* __SpeechDDKLib_LIBRARY_DEFINED__ */

/* interface __MIDL_itf_sapiddk51_0000_0017 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_sapiddk51_0000_0017_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sapiddk51_0000_0017_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


