

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

#ifndef __sapiddk_h__
#define __sapiddk_h__

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


#ifndef __ISpSREngineSite2_FWD_DEFINED__
#define __ISpSREngineSite2_FWD_DEFINED__
typedef interface ISpSREngineSite2 ISpSREngineSite2;

#endif 	/* __ISpSREngineSite2_FWD_DEFINED__ */


#ifndef __ISpSREngine_FWD_DEFINED__
#define __ISpSREngine_FWD_DEFINED__
typedef interface ISpSREngine ISpSREngine;

#endif 	/* __ISpSREngine_FWD_DEFINED__ */


#ifndef __ISpSREngine2_FWD_DEFINED__
#define __ISpSREngine2_FWD_DEFINED__
typedef interface ISpSREngine2 ISpSREngine2;

#endif 	/* __ISpSREngine2_FWD_DEFINED__ */


#ifndef __ISpSRAlternates_FWD_DEFINED__
#define __ISpSRAlternates_FWD_DEFINED__
typedef interface ISpSRAlternates ISpSRAlternates;

#endif 	/* __ISpSRAlternates_FWD_DEFINED__ */


#ifndef __ISpSRAlternates2_FWD_DEFINED__
#define __ISpSRAlternates2_FWD_DEFINED__
typedef interface ISpSRAlternates2 ISpSRAlternates2;

#endif 	/* __ISpSRAlternates2_FWD_DEFINED__ */


#ifndef ___ISpPrivateEngineCall_FWD_DEFINED__
#define ___ISpPrivateEngineCall_FWD_DEFINED__
typedef interface _ISpPrivateEngineCall _ISpPrivateEngineCall;

#endif 	/* ___ISpPrivateEngineCall_FWD_DEFINED__ */


#ifndef __ISpPrivateEngineCallEx_FWD_DEFINED__
#define __ISpPrivateEngineCallEx_FWD_DEFINED__
typedef interface ISpPrivateEngineCallEx ISpPrivateEngineCallEx;

#endif 	/* __ISpPrivateEngineCallEx_FWD_DEFINED__ */


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


#ifndef __SpW3CGrammarCompiler_FWD_DEFINED__
#define __SpW3CGrammarCompiler_FWD_DEFINED__

#ifdef __cplusplus
typedef class SpW3CGrammarCompiler SpW3CGrammarCompiler;
#else
typedef struct SpW3CGrammarCompiler SpW3CGrammarCompiler;
#endif /* __cplusplus */

#endif 	/* __SpW3CGrammarCompiler_FWD_DEFINED__ */


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


/* interface __MIDL_itf_sapiddk_0000_0000 */
/* [local] */ 

#include <winapifamily.h>
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
#ifndef _SAPI_VER
// Use SAPI 5.4 by default if target Windows 7
#if _WIN32_WINNT >= 0x0601
#define _SAPI_VER 0x054
#elif _WIN32_WINNT >= 0x0600
#define _SAPI_VER 0x053
#else // _WIN32_WINNT < 0x0600
#define _SAPI_VER 0x051
#endif // _WIN32_WINNT >= 0x0601
#endif // _SAPI_VER
// The following definitions are for SAPI 5.3 and newer
#if  _SAPI_VER >= 0x053





#define SPRECOEXTENSION   L"RecoExtension"
#define SPALTERNATESCLSID L"AlternatesCLSID"
#define SR_LOCALIZED_DESCRIPTION L"Description"


extern RPC_IF_HANDLE __MIDL_itf_sapiddk_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sapiddk_0000_0000_v0_0_s_ifspec;

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
            /* [annotation][in] */ 
            _In_  LPCWSTR pszTypeOfUI,
            /* [annotation][in] */ 
            _In_  void *pvExtraData,
            /* [annotation][in] */ 
            _In_  ULONG cbExtraData,
            /* [annotation][in] */ 
            _In_  IUnknown *punkObject,
            /* [annotation][out] */ 
            _Out_  BOOL *pfSupported) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE DisplayUI( 
            /* [annotation][in] */ 
            _In_  HWND hwndParent,
            /* [in][annotation] */ 
            _In_opt_  LPCWSTR pszTitle,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszTypeOfUI,
            /* [annotation][in] */ 
            _In_  void *pvExtraData,
            /* [annotation][in] */ 
            _In_  ULONG cbExtraData,
            /* [annotation][in] */ 
            _In_  ISpObjectToken *pToken,
            /* [annotation][in] */ 
            _In_  IUnknown *punkObject) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpTokenUIVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpTokenUI * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpTokenUI * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpTokenUI * This);
        
        DECLSPEC_XFGVIRT(ISpTokenUI, IsUISupported)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *IsUISupported )( 
            ISpTokenUI * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszTypeOfUI,
            /* [annotation][in] */ 
            _In_  void *pvExtraData,
            /* [annotation][in] */ 
            _In_  ULONG cbExtraData,
            /* [annotation][in] */ 
            _In_  IUnknown *punkObject,
            /* [annotation][out] */ 
            _Out_  BOOL *pfSupported);
        
        DECLSPEC_XFGVIRT(ISpTokenUI, DisplayUI)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *DisplayUI )( 
            ISpTokenUI * This,
            /* [annotation][in] */ 
            _In_  HWND hwndParent,
            /* [in][annotation] */ 
            _In_opt_  LPCWSTR pszTitle,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszTypeOfUI,
            /* [annotation][in] */ 
            _In_  void *pvExtraData,
            /* [annotation][in] */ 
            _In_  ULONG cbExtraData,
            /* [annotation][in] */ 
            _In_  ISpObjectToken *pToken,
            /* [annotation][in] */ 
            _In_  IUnknown *punkObject);
        
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
            /* [annotation][in] */ 
            _In_  ULONG cTokens,
            /* [annotation][in] */ 
            _In_  ISpObjectToken **pToken) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddTokensFromDataKey( 
            /* [annotation][in] */ 
            _In_  ISpDataKey *pDataKey,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszSubKey,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszCategoryId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddTokensFromTokenEnum( 
            /* [annotation][in] */ 
            _In_  IEnumSpObjectTokens *pTokenEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Sort( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszTokenIdToListFirst) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpObjectTokenEnumBuilderVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpObjectTokenEnumBuilder * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpObjectTokenEnumBuilder * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpObjectTokenEnumBuilder * This);
        
        DECLSPEC_XFGVIRT(IEnumSpObjectTokens, Next)
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            ISpObjectTokenEnumBuilder * This,
            /* [annotation][in] */ 
            _In_  ULONG celt,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(celt,*pceltFetched)  ISpObjectToken **pelt,
            /* [out][annotation] */ 
            _Out_opt_  ULONG *pceltFetched);
        
        DECLSPEC_XFGVIRT(IEnumSpObjectTokens, Skip)
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            ISpObjectTokenEnumBuilder * This,
            /* [annotation][in] */ 
            _In_  ULONG celt);
        
        DECLSPEC_XFGVIRT(IEnumSpObjectTokens, Reset)
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            ISpObjectTokenEnumBuilder * This);
        
        DECLSPEC_XFGVIRT(IEnumSpObjectTokens, Clone)
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            ISpObjectTokenEnumBuilder * This,
            /* [annotation][out] */ 
            _Out_  IEnumSpObjectTokens **ppEnum);
        
        DECLSPEC_XFGVIRT(IEnumSpObjectTokens, Item)
        HRESULT ( STDMETHODCALLTYPE *Item )( 
            ISpObjectTokenEnumBuilder * This,
            /* [annotation][in] */ 
            _In_  ULONG Index,
            /* [annotation][out] */ 
            _Out_  ISpObjectToken **ppToken);
        
        DECLSPEC_XFGVIRT(IEnumSpObjectTokens, GetCount)
        HRESULT ( STDMETHODCALLTYPE *GetCount )( 
            ISpObjectTokenEnumBuilder * This,
            /* [annotation][out] */ 
            _Out_  ULONG *pCount);
        
        DECLSPEC_XFGVIRT(ISpObjectTokenEnumBuilder, SetAttribs)
        HRESULT ( STDMETHODCALLTYPE *SetAttribs )( 
            ISpObjectTokenEnumBuilder * This,
            /* [in][annotation] */ 
            _In_opt_  LPCWSTR pszReqAttribs,
            /* [in][annotation] */ 
            _In_opt_  LPCWSTR pszOptAttribs);
        
        DECLSPEC_XFGVIRT(ISpObjectTokenEnumBuilder, AddTokens)
        HRESULT ( STDMETHODCALLTYPE *AddTokens )( 
            ISpObjectTokenEnumBuilder * This,
            /* [annotation][in] */ 
            _In_  ULONG cTokens,
            /* [annotation][in] */ 
            _In_  ISpObjectToken **pToken);
        
        DECLSPEC_XFGVIRT(ISpObjectTokenEnumBuilder, AddTokensFromDataKey)
        HRESULT ( STDMETHODCALLTYPE *AddTokensFromDataKey )( 
            ISpObjectTokenEnumBuilder * This,
            /* [annotation][in] */ 
            _In_  ISpDataKey *pDataKey,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszSubKey,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszCategoryId);
        
        DECLSPEC_XFGVIRT(ISpObjectTokenEnumBuilder, AddTokensFromTokenEnum)
        HRESULT ( STDMETHODCALLTYPE *AddTokensFromTokenEnum )( 
            ISpObjectTokenEnumBuilder * This,
            /* [annotation][in] */ 
            _In_  IEnumSpObjectTokens *pTokenEnum);
        
        DECLSPEC_XFGVIRT(ISpObjectTokenEnumBuilder, Sort)
        HRESULT ( STDMETHODCALLTYPE *Sort )( 
            ISpObjectTokenEnumBuilder * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszTokenIdToListFirst);
        
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


/* interface __MIDL_itf_sapiddk_0000_0002 */
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


extern RPC_IF_HANDLE __MIDL_itf_sapiddk_0000_0002_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sapiddk_0000_0002_v0_0_s_ifspec;

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
            /* [annotation][in] */ 
            _In_  const long lLineNumber,
            /* [annotation][in] */ 
            _In_  HRESULT hr,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszDescription,
            /* [in][annotation] */ 
            _In_opt_  LPCWSTR pszHelpFile,
            /* [annotation][in] */ 
            _In_  DWORD dwHelpContext) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpErrorLogVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpErrorLog * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpErrorLog * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpErrorLog * This);
        
        DECLSPEC_XFGVIRT(ISpErrorLog, AddError)
        HRESULT ( STDMETHODCALLTYPE *AddError )( 
            ISpErrorLog * This,
            /* [annotation][in] */ 
            _In_  const long lLineNumber,
            /* [annotation][in] */ 
            _In_  HRESULT hr,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszDescription,
            /* [in][annotation] */ 
            _In_opt_  LPCWSTR pszHelpFile,
            /* [annotation][in] */ 
            _In_  DWORD dwHelpContext);
        
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
            /* [annotation][in] */ 
            _In_  IStream *pSource,
            /* [annotation][out] */ 
            _Out_  IStream *pDest,
            /* [in][annotation] */ 
            _In_opt_  IStream *pHeader,
            /* [in][annotation] */ 
            _In_opt_  IUnknown *pReserved,
            /* [in][annotation] */ 
            _In_opt_  ISpErrorLog *pErrorLog,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpGrammarCompilerVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpGrammarCompiler * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpGrammarCompiler * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpGrammarCompiler * This);
        
        DECLSPEC_XFGVIRT(ISpGrammarCompiler, CompileStream)
        HRESULT ( STDMETHODCALLTYPE *CompileStream )( 
            ISpGrammarCompiler * This,
            /* [annotation][in] */ 
            _In_  IStream *pSource,
            /* [annotation][out] */ 
            _Out_  IStream *pDest,
            /* [in][annotation] */ 
            _In_opt_  IStream *pHeader,
            /* [in][annotation] */ 
            _In_opt_  IUnknown *pReserved,
            /* [in][annotation] */ 
            _In_opt_  ISpErrorLog *pErrorLog,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags);
        
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
            /* [annotation][in] */ 
            _In_  IStream *pStream,
            /* [annotation][in] */ 
            _In_  ISpErrorLog *pErrorLog) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InitFromBinaryGrammar( 
            /* [annotation][in] */ 
            _In_  const SPBINARYGRAMMAR *pBinaryData) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpGramCompBackendVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpGramCompBackend * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpGramCompBackend * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpGramCompBackend * This);
        
        DECLSPEC_XFGVIRT(ISpGrammarBuilder, ResetGrammar)
        HRESULT ( STDMETHODCALLTYPE *ResetGrammar )( 
            __RPC__in ISpGramCompBackend * This,
            /* [annotation][in] */ 
            _In_  WORD NewLanguage);
        
        DECLSPEC_XFGVIRT(ISpGrammarBuilder, GetRule)
        HRESULT ( STDMETHODCALLTYPE *GetRule )( 
            __RPC__in ISpGramCompBackend * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszRuleName,
            /* [annotation][in] */ 
            _In_  DWORD dwRuleId,
            /* [annotation][in] */ 
            _In_  DWORD dwAttributes,
            /* [annotation][in] */ 
            _In_  BOOL fCreateIfNotExist,
            /* [annotation][out] */ 
            _Out_  SPSTATEHANDLE *phInitialState);
        
        DECLSPEC_XFGVIRT(ISpGrammarBuilder, ClearRule)
        HRESULT ( STDMETHODCALLTYPE *ClearRule )( 
            __RPC__in ISpGramCompBackend * This,
            /* [annotation][in] */ 
            _In_  SPSTATEHANDLE hState);
        
        DECLSPEC_XFGVIRT(ISpGrammarBuilder, CreateNewState)
        HRESULT ( STDMETHODCALLTYPE *CreateNewState )( 
            __RPC__in ISpGramCompBackend * This,
            /* [annotation][in] */ 
            _In_  SPSTATEHANDLE hState,
            /* [annotation][out] */ 
            _Out_  SPSTATEHANDLE *phState);
        
        DECLSPEC_XFGVIRT(ISpGrammarBuilder, AddWordTransition)
        HRESULT ( STDMETHODCALLTYPE *AddWordTransition )( 
            __RPC__in ISpGramCompBackend * This,
            /* [annotation][in] */ 
            _In_  SPSTATEHANDLE hFromState,
            /* [annotation][in] */ 
            _In_  SPSTATEHANDLE hToState,
            /* [in][annotation] */ 
            _In_opt_  LPCWSTR psz,
            /* [in][annotation] */ 
            _In_opt_  LPCWSTR pszSeparators,
            /* [annotation][in] */ 
            _In_  SPGRAMMARWORDTYPE eWordType,
            /* [annotation][in] */ 
            _In_  float Weight,
            /* [annotation][in] */ 
            _In_  const SPPROPERTYINFO *pPropInfo);
        
        DECLSPEC_XFGVIRT(ISpGrammarBuilder, AddRuleTransition)
        HRESULT ( STDMETHODCALLTYPE *AddRuleTransition )( 
            __RPC__in ISpGramCompBackend * This,
            /* [annotation][in] */ 
            _In_  SPSTATEHANDLE hFromState,
            /* [annotation][in] */ 
            _In_  SPSTATEHANDLE hToState,
            /* [annotation][in] */ 
            _In_  SPSTATEHANDLE hRule,
            /* [annotation][in] */ 
            _In_  float Weight,
            /* [annotation][in] */ 
            _In_  const SPPROPERTYINFO *pPropInfo);
        
        DECLSPEC_XFGVIRT(ISpGrammarBuilder, AddResource)
        HRESULT ( STDMETHODCALLTYPE *AddResource )( 
            __RPC__in ISpGramCompBackend * This,
            /* [annotation][in] */ 
            _In_  SPSTATEHANDLE hRuleState,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszResourceName,
            /* [in][annotation] */ 
            _In_opt_  LPCWSTR pszResourceValue);
        
        DECLSPEC_XFGVIRT(ISpGrammarBuilder, Commit)
        HRESULT ( STDMETHODCALLTYPE *Commit )( 
            __RPC__in ISpGramCompBackend * This,
            /* [annotation][in] */ 
            _In_  DWORD dwReserved);
        
        DECLSPEC_XFGVIRT(ISpGramCompBackend, SetSaveObjects)
        HRESULT ( STDMETHODCALLTYPE *SetSaveObjects )( 
            __RPC__in ISpGramCompBackend * This,
            /* [annotation][in] */ 
            _In_  IStream *pStream,
            /* [annotation][in] */ 
            _In_  ISpErrorLog *pErrorLog);
        
        DECLSPEC_XFGVIRT(ISpGramCompBackend, InitFromBinaryGrammar)
        HRESULT ( STDMETHODCALLTYPE *InitFromBinaryGrammar )( 
            __RPC__in ISpGramCompBackend * This,
            /* [annotation][in] */ 
            _In_  const SPBINARYGRAMMAR *pBinaryData);
        
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
            /* [annotation][in] */ 
            _In_  ISpPhraseBuilder *pPhrase) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpITNProcessorVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpITNProcessor * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpITNProcessor * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpITNProcessor * This);
        
        DECLSPEC_XFGVIRT(ISpITNProcessor, LoadITNGrammar)
        HRESULT ( STDMETHODCALLTYPE *LoadITNGrammar )( 
            ISpITNProcessor * This,
            /* [in][annotation] */ 
            _In_  LPWSTR pszCLSID);
        
        DECLSPEC_XFGVIRT(ISpITNProcessor, ITNPhrase)
        HRESULT ( STDMETHODCALLTYPE *ITNPhrase )( 
            ISpITNProcessor * This,
            /* [annotation][in] */ 
            _In_  ISpPhraseBuilder *pPhrase);
        
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
            /* [annotation][in] */ 
            _In_  const SPPHRASE *pPhrase) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InitFromSerializedPhrase( 
            /* [annotation][in] */ 
            _In_  const SPSERIALIZEDPHRASE *pPhrase) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddElements( 
            /* [annotation][in] */ 
            _In_  ULONG cElements,
            /* [annotation][in] */ 
            _In_  const SPPHRASEELEMENT *pElement) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddRules( 
            /* [annotation][in] */ 
            _In_  const SPPHRASERULEHANDLE hParent,
            /* [annotation][in] */ 
            _In_  const SPPHRASERULE *pRule,
            /* [annotation][out] */ 
            _Out_  SPPHRASERULEHANDLE *phNewRule) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddProperties( 
            /* [annotation][in] */ 
            _In_  const SPPHRASEPROPERTYHANDLE hParent,
            /* [annotation][in] */ 
            _In_  const SPPHRASEPROPERTY *pProperty,
            /* [annotation][out] */ 
            _Out_  SPPHRASEPROPERTYHANDLE *phNewProperty) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddReplacements( 
            /* [annotation][in] */ 
            _In_  ULONG cReplacements,
            /* [annotation][in] */ 
            _In_  const SPPHRASEREPLACEMENT *pReplacements) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpPhraseBuilderVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpPhraseBuilder * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpPhraseBuilder * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpPhraseBuilder * This);
        
        DECLSPEC_XFGVIRT(ISpPhrase, GetPhrase)
        HRESULT ( STDMETHODCALLTYPE *GetPhrase )( 
            ISpPhraseBuilder * This,
            /* [out][annotation] */ 
            _Outptr_  SPPHRASE **ppCoMemPhrase);
        
        DECLSPEC_XFGVIRT(ISpPhrase, GetSerializedPhrase)
        HRESULT ( STDMETHODCALLTYPE *GetSerializedPhrase )( 
            ISpPhraseBuilder * This,
            /* [out][annotation] */ 
            _Outptr_  SPSERIALIZEDPHRASE **ppCoMemPhrase);
        
        DECLSPEC_XFGVIRT(ISpPhrase, GetText)
        HRESULT ( STDMETHODCALLTYPE *GetText )( 
            ISpPhraseBuilder * This,
            /* [annotation][in] */ 
            _In_  ULONG ulStart,
            /* [annotation][in] */ 
            _In_  ULONG ulCount,
            /* [annotation][in] */ 
            _In_  BOOL fUseTextReplacements,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppszCoMemText,
            /* [optional][out][annotation] */ 
            _Out_writes_opt_(1)  BYTE *pbDisplayAttributes);
        
        DECLSPEC_XFGVIRT(ISpPhrase, Discard)
        HRESULT ( STDMETHODCALLTYPE *Discard )( 
            ISpPhraseBuilder * This,
            /* [annotation][in] */ 
            _In_  DWORD dwValueTypes);
        
        DECLSPEC_XFGVIRT(ISpPhraseBuilder, InitFromPhrase)
        HRESULT ( STDMETHODCALLTYPE *InitFromPhrase )( 
            ISpPhraseBuilder * This,
            /* [annotation][in] */ 
            _In_  const SPPHRASE *pPhrase);
        
        DECLSPEC_XFGVIRT(ISpPhraseBuilder, InitFromSerializedPhrase)
        HRESULT ( STDMETHODCALLTYPE *InitFromSerializedPhrase )( 
            ISpPhraseBuilder * This,
            /* [annotation][in] */ 
            _In_  const SPSERIALIZEDPHRASE *pPhrase);
        
        DECLSPEC_XFGVIRT(ISpPhraseBuilder, AddElements)
        HRESULT ( STDMETHODCALLTYPE *AddElements )( 
            ISpPhraseBuilder * This,
            /* [annotation][in] */ 
            _In_  ULONG cElements,
            /* [annotation][in] */ 
            _In_  const SPPHRASEELEMENT *pElement);
        
        DECLSPEC_XFGVIRT(ISpPhraseBuilder, AddRules)
        HRESULT ( STDMETHODCALLTYPE *AddRules )( 
            ISpPhraseBuilder * This,
            /* [annotation][in] */ 
            _In_  const SPPHRASERULEHANDLE hParent,
            /* [annotation][in] */ 
            _In_  const SPPHRASERULE *pRule,
            /* [annotation][out] */ 
            _Out_  SPPHRASERULEHANDLE *phNewRule);
        
        DECLSPEC_XFGVIRT(ISpPhraseBuilder, AddProperties)
        HRESULT ( STDMETHODCALLTYPE *AddProperties )( 
            ISpPhraseBuilder * This,
            /* [annotation][in] */ 
            _In_  const SPPHRASEPROPERTYHANDLE hParent,
            /* [annotation][in] */ 
            _In_  const SPPHRASEPROPERTY *pProperty,
            /* [annotation][out] */ 
            _Out_  SPPHRASEPROPERTYHANDLE *phNewProperty);
        
        DECLSPEC_XFGVIRT(ISpPhraseBuilder, AddReplacements)
        HRESULT ( STDMETHODCALLTYPE *AddReplacements )( 
            ISpPhraseBuilder * This,
            /* [annotation][in] */ 
            _In_  ULONG cReplacements,
            /* [annotation][in] */ 
            _In_  const SPPHRASEREPLACEMENT *pReplacements);
        
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


/* interface __MIDL_itf_sapiddk_0000_0007 */
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


extern RPC_IF_HANDLE __MIDL_itf_sapiddk_0000_0007_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sapiddk_0000_0007_v0_0_s_ifspec;

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
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][out] */ 
            _Out_  HWND *phwnd) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE WaitForThreadDone( 
            /* [annotation][in] */ 
            _In_  BOOL fForceStop,
            /* [annotation][out] */ 
            _Out_  HRESULT *phrThreadResult,
            /* [annotation][in] */ 
            _In_  ULONG msTimeOut) = 0;
        
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
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpThreadControl * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpThreadControl * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpThreadControl * This);
        
        DECLSPEC_XFGVIRT(ISpNotifySink, Notify)
        HRESULT ( STDMETHODCALLTYPE *Notify )( 
            ISpThreadControl * This);
        
        DECLSPEC_XFGVIRT(ISpThreadControl, StartThread)
        HRESULT ( STDMETHODCALLTYPE *StartThread )( 
            ISpThreadControl * This,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][out] */ 
            _Out_  HWND *phwnd);
        
        DECLSPEC_XFGVIRT(ISpThreadControl, WaitForThreadDone)
        HRESULT ( STDMETHODCALLTYPE *WaitForThreadDone )( 
            ISpThreadControl * This,
            /* [annotation][in] */ 
            _In_  BOOL fForceStop,
            /* [annotation][out] */ 
            _Out_  HRESULT *phrThreadResult,
            /* [annotation][in] */ 
            _In_  ULONG msTimeOut);
        
        DECLSPEC_XFGVIRT(ISpThreadControl, TerminateThread)
        HRESULT ( STDMETHODCALLTYPE *TerminateThread )( 
            ISpThreadControl * This);
        
        DECLSPEC_XFGVIRT(ISpThreadControl, ThreadHandle)
        HANDLE ( STDMETHODCALLTYPE *ThreadHandle )( 
            ISpThreadControl * This);
        
        DECLSPEC_XFGVIRT(ISpThreadControl, ThreadId)
        DWORD ( STDMETHODCALLTYPE *ThreadId )( 
            ISpThreadControl * This);
        
        DECLSPEC_XFGVIRT(ISpThreadControl, NotifyEvent)
        HANDLE ( STDMETHODCALLTYPE *NotifyEvent )( 
            ISpThreadControl * This);
        
        DECLSPEC_XFGVIRT(ISpThreadControl, WindowHandle)
        HWND ( STDMETHODCALLTYPE *WindowHandle )( 
            ISpThreadControl * This);
        
        DECLSPEC_XFGVIRT(ISpThreadControl, ThreadCompleteEvent)
        HANDLE ( STDMETHODCALLTYPE *ThreadCompleteEvent )( 
            ISpThreadControl * This);
        
        DECLSPEC_XFGVIRT(ISpThreadControl, ExitThreadEvent)
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


/* interface __MIDL_itf_sapiddk_0000_0008 */
/* [local] */ 

typedef /* [restricted] */ struct SPTMTHREADINFO
    {
    long lPoolSize;
    long lPriority;
    ULONG ulConcurrencyLimit;
    ULONG ulMaxQuickAllocThreads;
    } 	SPTMTHREADINFO;



extern RPC_IF_HANDLE __MIDL_itf_sapiddk_0000_0008_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sapiddk_0000_0008_v0_0_s_ifspec;

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
            /* [annotation][in] */ 
            _In_  const SPTMTHREADINFO *pPoolInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetThreadPoolInfo( 
            /* [annotation][out] */ 
            _Out_  SPTMTHREADINFO *pPoolInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueueTask( 
            /* [annotation][in] */ 
            _In_  ISpTask *pTask,
            /* [annotation][in] */ 
            _In_  void *pvTaskData,
            /* [annotation][in] */ 
            _In_  HANDLE hCompEvent,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pdwGroupId,
            /* [annotation][out] */ 
            _Out_  DWORD *pTaskID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateReoccurringTask( 
            /* [annotation][in] */ 
            _In_  ISpTask *pTask,
            /* [annotation][in] */ 
            _In_  void *pvTaskData,
            /* [annotation][in] */ 
            _In_  HANDLE hCompEvent,
            /* [annotation][out] */ 
            _Out_  ISpNotifySink **ppTaskCtrl) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateThreadControl( 
            /* [annotation][in] */ 
            _In_  ISpThreadTask *pTask,
            /* [annotation][in] */ 
            _In_  void *pvTaskData,
            /* [annotation][in] */ 
            _In_  long nPriority,
            /* [out][annotation] */ 
            _Outptr_  ISpThreadControl **ppTaskCtrl) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE TerminateTask( 
            /* [annotation][in] */ 
            _In_  DWORD dwTaskId,
            /* [annotation][in] */ 
            _In_  ULONG ulWaitPeriod) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE TerminateTaskGroup( 
            /* [annotation][in] */ 
            _In_  DWORD dwGroupId,
            /* [annotation][in] */ 
            _In_  ULONG ulWaitPeriod) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpTaskManagerVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpTaskManager * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpTaskManager * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpTaskManager * This);
        
        DECLSPEC_XFGVIRT(ISpTaskManager, SetThreadPoolInfo)
        HRESULT ( STDMETHODCALLTYPE *SetThreadPoolInfo )( 
            ISpTaskManager * This,
            /* [annotation][in] */ 
            _In_  const SPTMTHREADINFO *pPoolInfo);
        
        DECLSPEC_XFGVIRT(ISpTaskManager, GetThreadPoolInfo)
        HRESULT ( STDMETHODCALLTYPE *GetThreadPoolInfo )( 
            ISpTaskManager * This,
            /* [annotation][out] */ 
            _Out_  SPTMTHREADINFO *pPoolInfo);
        
        DECLSPEC_XFGVIRT(ISpTaskManager, QueueTask)
        HRESULT ( STDMETHODCALLTYPE *QueueTask )( 
            ISpTaskManager * This,
            /* [annotation][in] */ 
            _In_  ISpTask *pTask,
            /* [annotation][in] */ 
            _In_  void *pvTaskData,
            /* [annotation][in] */ 
            _In_  HANDLE hCompEvent,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pdwGroupId,
            /* [annotation][out] */ 
            _Out_  DWORD *pTaskID);
        
        DECLSPEC_XFGVIRT(ISpTaskManager, CreateReoccurringTask)
        HRESULT ( STDMETHODCALLTYPE *CreateReoccurringTask )( 
            ISpTaskManager * This,
            /* [annotation][in] */ 
            _In_  ISpTask *pTask,
            /* [annotation][in] */ 
            _In_  void *pvTaskData,
            /* [annotation][in] */ 
            _In_  HANDLE hCompEvent,
            /* [annotation][out] */ 
            _Out_  ISpNotifySink **ppTaskCtrl);
        
        DECLSPEC_XFGVIRT(ISpTaskManager, CreateThreadControl)
        HRESULT ( STDMETHODCALLTYPE *CreateThreadControl )( 
            ISpTaskManager * This,
            /* [annotation][in] */ 
            _In_  ISpThreadTask *pTask,
            /* [annotation][in] */ 
            _In_  void *pvTaskData,
            /* [annotation][in] */ 
            _In_  long nPriority,
            /* [out][annotation] */ 
            _Outptr_  ISpThreadControl **ppTaskCtrl);
        
        DECLSPEC_XFGVIRT(ISpTaskManager, TerminateTask)
        HRESULT ( STDMETHODCALLTYPE *TerminateTask )( 
            ISpTaskManager * This,
            /* [annotation][in] */ 
            _In_  DWORD dwTaskId,
            /* [annotation][in] */ 
            _In_  ULONG ulWaitPeriod);
        
        DECLSPEC_XFGVIRT(ISpTaskManager, TerminateTaskGroup)
        HRESULT ( STDMETHODCALLTYPE *TerminateTaskGroup )( 
            ISpTaskManager * This,
            /* [annotation][in] */ 
            _In_  DWORD dwGroupId,
            /* [annotation][in] */ 
            _In_  ULONG ulWaitPeriod);
        
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


/* interface __MIDL_itf_sapiddk_0000_0009 */
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



extern RPC_IF_HANDLE __MIDL_itf_sapiddk_0000_0009_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sapiddk_0000_0009_v0_0_s_ifspec;

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
            /* [annotation][in] */ 
            _In_  const void *pBuff,
            /* [annotation][in] */ 
            _In_  ULONG cb,
            /* [annotation][out] */ 
            _Out_  ULONG *pcbWritten) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRate( 
            /* [annotation][out] */ 
            _Out_  long *pRateAdjust) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetVolume( 
            /* [annotation][out] */ 
            _Out_  USHORT *pusVolume) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSkipInfo( 
            /* [annotation][out] */ 
            _Out_  SPVSKIPTYPE *peType,
            /* [annotation][out] */ 
            _Out_  long *plNumItems) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CompleteSkip( 
            /* [annotation][in] */ 
            _In_  long ulNumSkipped) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpTTSEngineSiteVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpTTSEngineSite * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpTTSEngineSite * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpTTSEngineSite * This);
        
        DECLSPEC_XFGVIRT(ISpEventSink, AddEvents)
        HRESULT ( STDMETHODCALLTYPE *AddEvents )( 
            ISpTTSEngineSite * This,
            /* [annotation][in] */ 
            _In_  const SPEVENT *pEventArray,
            /* [annotation][in] */ 
            _In_  ULONG ulCount);
        
        DECLSPEC_XFGVIRT(ISpEventSink, GetEventInterest)
        HRESULT ( STDMETHODCALLTYPE *GetEventInterest )( 
            ISpTTSEngineSite * This,
            /* [annotation][out] */ 
            _Out_  ULONGLONG *pullEventInterest);
        
        DECLSPEC_XFGVIRT(ISpTTSEngineSite, GetActions)
        DWORD ( STDMETHODCALLTYPE *GetActions )( 
            ISpTTSEngineSite * This);
        
        DECLSPEC_XFGVIRT(ISpTTSEngineSite, Write)
        HRESULT ( STDMETHODCALLTYPE *Write )( 
            ISpTTSEngineSite * This,
            /* [annotation][in] */ 
            _In_  const void *pBuff,
            /* [annotation][in] */ 
            _In_  ULONG cb,
            /* [annotation][out] */ 
            _Out_  ULONG *pcbWritten);
        
        DECLSPEC_XFGVIRT(ISpTTSEngineSite, GetRate)
        HRESULT ( STDMETHODCALLTYPE *GetRate )( 
            ISpTTSEngineSite * This,
            /* [annotation][out] */ 
            _Out_  long *pRateAdjust);
        
        DECLSPEC_XFGVIRT(ISpTTSEngineSite, GetVolume)
        HRESULT ( STDMETHODCALLTYPE *GetVolume )( 
            ISpTTSEngineSite * This,
            /* [annotation][out] */ 
            _Out_  USHORT *pusVolume);
        
        DECLSPEC_XFGVIRT(ISpTTSEngineSite, GetSkipInfo)
        HRESULT ( STDMETHODCALLTYPE *GetSkipInfo )( 
            ISpTTSEngineSite * This,
            /* [annotation][out] */ 
            _Out_  SPVSKIPTYPE *peType,
            /* [annotation][out] */ 
            _Out_  long *plNumItems);
        
        DECLSPEC_XFGVIRT(ISpTTSEngineSite, CompleteSkip)
        HRESULT ( STDMETHODCALLTYPE *CompleteSkip )( 
            ISpTTSEngineSite * This,
            /* [annotation][in] */ 
            _In_  long ulNumSkipped);
        
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


/* interface __MIDL_itf_sapiddk_0000_0010 */
/* [local] */ 

typedef struct SPVTEXTFRAG
    {
    struct SPVTEXTFRAG *pNext;
    SPVSTATE State;
    LPCWSTR pTextStart;
    ULONG ulTextLen;
    ULONG ulTextSrcOffset;
    } 	SPVTEXTFRAG;



extern RPC_IF_HANDLE __MIDL_itf_sapiddk_0000_0010_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sapiddk_0000_0010_v0_0_s_ifspec;

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
            /* [annotation][in] */ 
            _In_  DWORD dwSpeakFlags,
            /* [annotation][in] */ 
            _In_  REFGUID rguidFormatId,
            /* [annotation][in] */ 
            _In_  const WAVEFORMATEX *pWaveFormatEx,
            /* [annotation][in] */ 
            _In_  const SPVTEXTFRAG *pTextFragList,
            /* [annotation][in] */ 
            _In_  ISpTTSEngineSite *pOutputSite) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetOutputFormat( 
            /* [annotation][in] */ 
            _In_  const GUID *pTargetFmtId,
            /* [annotation][in] */ 
            _In_  const WAVEFORMATEX *pTargetWaveFormatEx,
            /* [annotation][out] */ 
            _Out_  GUID *pOutputFormatId,
            /* [out][annotation] */ 
            _Outptr_  WAVEFORMATEX **ppCoMemOutputWaveFormatEx) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpTTSEngineVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpTTSEngine * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpTTSEngine * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpTTSEngine * This);
        
        DECLSPEC_XFGVIRT(ISpTTSEngine, Speak)
        HRESULT ( STDMETHODCALLTYPE *Speak )( 
            ISpTTSEngine * This,
            /* [annotation][in] */ 
            _In_  DWORD dwSpeakFlags,
            /* [annotation][in] */ 
            _In_  REFGUID rguidFormatId,
            /* [annotation][in] */ 
            _In_  const WAVEFORMATEX *pWaveFormatEx,
            /* [annotation][in] */ 
            _In_  const SPVTEXTFRAG *pTextFragList,
            /* [annotation][in] */ 
            _In_  ISpTTSEngineSite *pOutputSite);
        
        DECLSPEC_XFGVIRT(ISpTTSEngine, GetOutputFormat)
        HRESULT ( STDMETHODCALLTYPE *GetOutputFormat )( 
            ISpTTSEngine * This,
            /* [annotation][in] */ 
            _In_  const GUID *pTargetFmtId,
            /* [annotation][in] */ 
            _In_  const WAVEFORMATEX *pTargetWaveFormatEx,
            /* [annotation][out] */ 
            _Out_  GUID *pOutputFormatId,
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


/* interface __MIDL_itf_sapiddk_0000_0011 */
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
    unsigned char RequiredConfidence;
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



extern RPC_IF_HANDLE __MIDL_itf_sapiddk_0000_0011_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sapiddk_0000_0011_v0_0_s_ifspec;

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
            /* [annotation][in] */ 
            _In_  SPPHRASEREPLACEMENT *pReplace) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddProperty( 
            /* [annotation][in] */ 
            _In_  const SPPHRASEPROPERTY *pProperty) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetResourceValue( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszResourceName,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppCoMemResource) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpCFGInterpreterSiteVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpCFGInterpreterSite * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpCFGInterpreterSite * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpCFGInterpreterSite * This);
        
        DECLSPEC_XFGVIRT(ISpCFGInterpreterSite, AddTextReplacement)
        HRESULT ( STDMETHODCALLTYPE *AddTextReplacement )( 
            ISpCFGInterpreterSite * This,
            /* [annotation][in] */ 
            _In_  SPPHRASEREPLACEMENT *pReplace);
        
        DECLSPEC_XFGVIRT(ISpCFGInterpreterSite, AddProperty)
        HRESULT ( STDMETHODCALLTYPE *AddProperty )( 
            ISpCFGInterpreterSite * This,
            /* [annotation][in] */ 
            _In_  const SPPHRASEPROPERTY *pProperty);
        
        DECLSPEC_XFGVIRT(ISpCFGInterpreterSite, GetResourceValue)
        HRESULT ( STDMETHODCALLTYPE *GetResourceValue )( 
            ISpCFGInterpreterSite * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszResourceName,
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
            /* [annotation][in] */ 
            _In_  LPCWSTR pszGrammarName,
            /* [annotation][in] */ 
            _In_  const void **pvGrammarData) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Interpret( 
            /* [annotation][in] */ 
            _In_  ISpPhraseBuilder *pPhrase,
            /* [annotation][in] */ 
            _In_  const ULONG ulFirstElement,
            /* [annotation][in] */ 
            _In_  const ULONG ulCountOfElements,
            /* [annotation][in] */ 
            _In_  ISpCFGInterpreterSite *pSite) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpCFGInterpreterVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpCFGInterpreter * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpCFGInterpreter * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpCFGInterpreter * This);
        
        DECLSPEC_XFGVIRT(ISpCFGInterpreter, InitGrammar)
        HRESULT ( STDMETHODCALLTYPE *InitGrammar )( 
            ISpCFGInterpreter * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszGrammarName,
            /* [annotation][in] */ 
            _In_  const void **pvGrammarData);
        
        DECLSPEC_XFGVIRT(ISpCFGInterpreter, Interpret)
        HRESULT ( STDMETHODCALLTYPE *Interpret )( 
            ISpCFGInterpreter * This,
            /* [annotation][in] */ 
            _In_  ISpPhraseBuilder *pPhrase,
            /* [annotation][in] */ 
            _In_  const ULONG ulFirstElement,
            /* [annotation][in] */ 
            _In_  const ULONG ulCountOfElements,
            /* [annotation][in] */ 
            _In_  ISpCFGInterpreterSite *pSite);
        
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


/* interface __MIDL_itf_sapiddk_0000_0013 */
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
        SPRT_FALSE_RECOGNITION	= ( 1L << 2 ) ,
        SPRT_TYPE_MASK	= 3,
        SPRT_EMULATED	= ( 1L << 3 ) ,
        SPRT_EXTENDABLE_PARSE	= ( 1L << 4 ) 
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

#if 0
typedef struct SPRECORESULTINFOEX
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
    ULONGLONG ullStreamTimeStart;
    ULONGLONG ullStreamTimeEnd;
    } 	SPRECORESULTINFOEX;

#else
typedef struct SPRECORESULTINFOEX : public SPRECORESULTINFO
{
    ULONGLONG         ullStreamTimeStart;
    ULONGLONG         ullStreamTimeEnd;
} SPRECORESULTINFOEX;
#endif
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



extern RPC_IF_HANDLE __MIDL_itf_sapiddk_0000_0013_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sapiddk_0000_0013_v0_0_s_ifspec;

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
            /* [annotation][in] */ 
            _In_  void *pv,
            /* [annotation][in] */ 
            _In_  ULONG cb,
            /* [annotation][out] */ 
            _Out_  ULONG *pcbRead) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DataAvailable( 
            /* [annotation][out] */ 
            _Out_  ULONG *pcb) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetBufferNotifySize( 
            /* [annotation][in] */ 
            _In_  ULONG cbSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ParseFromTransitions( 
            /* [annotation][in] */ 
            _In_  const SPPARSEINFO *pParseInfo,
            /* [annotation][out] */ 
            _Out_  ISpPhraseBuilder **ppNewPhrase) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Recognition( 
            /* [annotation][in] */ 
            _In_  const SPRECORESULTINFO *pResultInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddEvent( 
            /* [annotation][in] */ 
            _In_  const SPEVENT *pEvent,
            /* [annotation][in] */ 
            _In_  SPRECOCONTEXTHANDLE hSAPIRecoContext) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Synchronize( 
            /* [annotation][in] */ 
            _In_  ULONGLONG ullProcessedThruPos) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetWordInfo( 
            /* [annotation][out][in] */ 
            _Inout_  SPWORDENTRY *pWordEntry,
            /* [annotation][in] */ 
            _In_  SPWORDINFOOPT Options) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetWordClientContext( 
            /* [annotation][in] */ 
            _In_  SPWORDHANDLE hWord,
            /* [annotation][in] */ 
            _In_  void *pvClientContext) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRuleInfo( 
            /* [annotation][out][in] */ 
            _Inout_  SPRULEENTRY *pRuleEntry,
            /* [annotation][in] */ 
            _In_  SPRULEINFOOPT Options) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetRuleClientContext( 
            /* [annotation][in] */ 
            _In_  SPRULEHANDLE hRule,
            /* [annotation][in] */ 
            _In_  void *pvClientContext) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStateInfo( 
            /* [annotation][in] */ 
            _In_  SPSTATEHANDLE hState,
            /* [annotation][out] */ 
            _Out_  SPSTATEINFO *pStateInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetResource( 
            /* [annotation][in] */ 
            _In_  SPRULEHANDLE hRule,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszResourceName,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppCoMemResource) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTransitionProperty( 
            /* [annotation][in] */ 
            _In_  SPTRANSITIONID ID,
            /* [out][annotation] */ 
            _Outptr_  SPTRANSITIONPROPERTY **ppCoMemProperty) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsAlternate( 
            /* [annotation][in] */ 
            _In_  SPRULEHANDLE hRule,
            /* [annotation][in] */ 
            _In_  SPRULEHANDLE hAltRule) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMaxAlternates( 
            /* [annotation][in] */ 
            _In_  SPRULEHANDLE hRule,
            /* [annotation][out] */ 
            _Out_  ULONG *pulNumAlts) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetContextMaxAlternates( 
            /* [annotation][in] */ 
            _In_  SPRECOCONTEXTHANDLE hContext,
            /* [annotation][out] */ 
            _Out_  ULONG *pulNumAlts) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UpdateRecoPos( 
            /* [annotation][in] */ 
            _In_  ULONGLONG ullCurrentRecoPos) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpSREngineSiteVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpSREngineSite * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpSREngineSite * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpSREngineSite * This);
        
        DECLSPEC_XFGVIRT(ISpSREngineSite, Read)
        HRESULT ( STDMETHODCALLTYPE *Read )( 
            ISpSREngineSite * This,
            /* [annotation][in] */ 
            _In_  void *pv,
            /* [annotation][in] */ 
            _In_  ULONG cb,
            /* [annotation][out] */ 
            _Out_  ULONG *pcbRead);
        
        DECLSPEC_XFGVIRT(ISpSREngineSite, DataAvailable)
        HRESULT ( STDMETHODCALLTYPE *DataAvailable )( 
            ISpSREngineSite * This,
            /* [annotation][out] */ 
            _Out_  ULONG *pcb);
        
        DECLSPEC_XFGVIRT(ISpSREngineSite, SetBufferNotifySize)
        HRESULT ( STDMETHODCALLTYPE *SetBufferNotifySize )( 
            ISpSREngineSite * This,
            /* [annotation][in] */ 
            _In_  ULONG cbSize);
        
        DECLSPEC_XFGVIRT(ISpSREngineSite, ParseFromTransitions)
        HRESULT ( STDMETHODCALLTYPE *ParseFromTransitions )( 
            ISpSREngineSite * This,
            /* [annotation][in] */ 
            _In_  const SPPARSEINFO *pParseInfo,
            /* [annotation][out] */ 
            _Out_  ISpPhraseBuilder **ppNewPhrase);
        
        DECLSPEC_XFGVIRT(ISpSREngineSite, Recognition)
        HRESULT ( STDMETHODCALLTYPE *Recognition )( 
            ISpSREngineSite * This,
            /* [annotation][in] */ 
            _In_  const SPRECORESULTINFO *pResultInfo);
        
        DECLSPEC_XFGVIRT(ISpSREngineSite, AddEvent)
        HRESULT ( STDMETHODCALLTYPE *AddEvent )( 
            ISpSREngineSite * This,
            /* [annotation][in] */ 
            _In_  const SPEVENT *pEvent,
            /* [annotation][in] */ 
            _In_  SPRECOCONTEXTHANDLE hSAPIRecoContext);
        
        DECLSPEC_XFGVIRT(ISpSREngineSite, Synchronize)
        HRESULT ( STDMETHODCALLTYPE *Synchronize )( 
            ISpSREngineSite * This,
            /* [annotation][in] */ 
            _In_  ULONGLONG ullProcessedThruPos);
        
        DECLSPEC_XFGVIRT(ISpSREngineSite, GetWordInfo)
        HRESULT ( STDMETHODCALLTYPE *GetWordInfo )( 
            ISpSREngineSite * This,
            /* [annotation][out][in] */ 
            _Inout_  SPWORDENTRY *pWordEntry,
            /* [annotation][in] */ 
            _In_  SPWORDINFOOPT Options);
        
        DECLSPEC_XFGVIRT(ISpSREngineSite, SetWordClientContext)
        HRESULT ( STDMETHODCALLTYPE *SetWordClientContext )( 
            ISpSREngineSite * This,
            /* [annotation][in] */ 
            _In_  SPWORDHANDLE hWord,
            /* [annotation][in] */ 
            _In_  void *pvClientContext);
        
        DECLSPEC_XFGVIRT(ISpSREngineSite, GetRuleInfo)
        HRESULT ( STDMETHODCALLTYPE *GetRuleInfo )( 
            ISpSREngineSite * This,
            /* [annotation][out][in] */ 
            _Inout_  SPRULEENTRY *pRuleEntry,
            /* [annotation][in] */ 
            _In_  SPRULEINFOOPT Options);
        
        DECLSPEC_XFGVIRT(ISpSREngineSite, SetRuleClientContext)
        HRESULT ( STDMETHODCALLTYPE *SetRuleClientContext )( 
            ISpSREngineSite * This,
            /* [annotation][in] */ 
            _In_  SPRULEHANDLE hRule,
            /* [annotation][in] */ 
            _In_  void *pvClientContext);
        
        DECLSPEC_XFGVIRT(ISpSREngineSite, GetStateInfo)
        HRESULT ( STDMETHODCALLTYPE *GetStateInfo )( 
            ISpSREngineSite * This,
            /* [annotation][in] */ 
            _In_  SPSTATEHANDLE hState,
            /* [annotation][out] */ 
            _Out_  SPSTATEINFO *pStateInfo);
        
        DECLSPEC_XFGVIRT(ISpSREngineSite, GetResource)
        HRESULT ( STDMETHODCALLTYPE *GetResource )( 
            ISpSREngineSite * This,
            /* [annotation][in] */ 
            _In_  SPRULEHANDLE hRule,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszResourceName,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppCoMemResource);
        
        DECLSPEC_XFGVIRT(ISpSREngineSite, GetTransitionProperty)
        HRESULT ( STDMETHODCALLTYPE *GetTransitionProperty )( 
            ISpSREngineSite * This,
            /* [annotation][in] */ 
            _In_  SPTRANSITIONID ID,
            /* [out][annotation] */ 
            _Outptr_  SPTRANSITIONPROPERTY **ppCoMemProperty);
        
        DECLSPEC_XFGVIRT(ISpSREngineSite, IsAlternate)
        HRESULT ( STDMETHODCALLTYPE *IsAlternate )( 
            ISpSREngineSite * This,
            /* [annotation][in] */ 
            _In_  SPRULEHANDLE hRule,
            /* [annotation][in] */ 
            _In_  SPRULEHANDLE hAltRule);
        
        DECLSPEC_XFGVIRT(ISpSREngineSite, GetMaxAlternates)
        HRESULT ( STDMETHODCALLTYPE *GetMaxAlternates )( 
            ISpSREngineSite * This,
            /* [annotation][in] */ 
            _In_  SPRULEHANDLE hRule,
            /* [annotation][out] */ 
            _Out_  ULONG *pulNumAlts);
        
        DECLSPEC_XFGVIRT(ISpSREngineSite, GetContextMaxAlternates)
        HRESULT ( STDMETHODCALLTYPE *GetContextMaxAlternates )( 
            ISpSREngineSite * This,
            /* [annotation][in] */ 
            _In_  SPRECOCONTEXTHANDLE hContext,
            /* [annotation][out] */ 
            _Out_  ULONG *pulNumAlts);
        
        DECLSPEC_XFGVIRT(ISpSREngineSite, UpdateRecoPos)
        HRESULT ( STDMETHODCALLTYPE *UpdateRecoPos )( 
            ISpSREngineSite * This,
            /* [annotation][in] */ 
            _In_  ULONGLONG ullCurrentRecoPos);
        
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


#ifndef __ISpSREngineSite2_INTERFACE_DEFINED__
#define __ISpSREngineSite2_INTERFACE_DEFINED__

/* interface ISpSREngineSite2 */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpSREngineSite2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7BC6E012-684A-493E-BDD4-2BF5FBF48CFE")
    ISpSREngineSite2 : public ISpSREngineSite
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AddEventEx( 
            /* [annotation][in] */ 
            _In_  const SPEVENTEX *pEvent,
            /* [annotation][in] */ 
            _In_  SPRECOCONTEXTHANDLE hSAPIRecoContext) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UpdateRecoPosEx( 
            /* [annotation][in] */ 
            _In_  ULONGLONG ullCurrentRecoPos,
            /* [annotation][in] */ 
            _In_  ULONGLONG ullCurrentRecoTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRuleTransition( 
            /* [annotation][in] */ 
            _In_  ULONG ulGrammarID,
            /* [annotation][in] */ 
            _In_  ULONG RuleIndex,
            /* [annotation][out] */ 
            _Out_  SPTRANSITIONENTRY *pTrans) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RecognitionEx( 
            /* [annotation][in] */ 
            _In_  const SPRECORESULTINFOEX *pResultInfo) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpSREngineSite2Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpSREngineSite2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpSREngineSite2 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpSREngineSite2 * This);
        
        DECLSPEC_XFGVIRT(ISpSREngineSite, Read)
        HRESULT ( STDMETHODCALLTYPE *Read )( 
            ISpSREngineSite2 * This,
            /* [annotation][in] */ 
            _In_  void *pv,
            /* [annotation][in] */ 
            _In_  ULONG cb,
            /* [annotation][out] */ 
            _Out_  ULONG *pcbRead);
        
        DECLSPEC_XFGVIRT(ISpSREngineSite, DataAvailable)
        HRESULT ( STDMETHODCALLTYPE *DataAvailable )( 
            ISpSREngineSite2 * This,
            /* [annotation][out] */ 
            _Out_  ULONG *pcb);
        
        DECLSPEC_XFGVIRT(ISpSREngineSite, SetBufferNotifySize)
        HRESULT ( STDMETHODCALLTYPE *SetBufferNotifySize )( 
            ISpSREngineSite2 * This,
            /* [annotation][in] */ 
            _In_  ULONG cbSize);
        
        DECLSPEC_XFGVIRT(ISpSREngineSite, ParseFromTransitions)
        HRESULT ( STDMETHODCALLTYPE *ParseFromTransitions )( 
            ISpSREngineSite2 * This,
            /* [annotation][in] */ 
            _In_  const SPPARSEINFO *pParseInfo,
            /* [annotation][out] */ 
            _Out_  ISpPhraseBuilder **ppNewPhrase);
        
        DECLSPEC_XFGVIRT(ISpSREngineSite, Recognition)
        HRESULT ( STDMETHODCALLTYPE *Recognition )( 
            ISpSREngineSite2 * This,
            /* [annotation][in] */ 
            _In_  const SPRECORESULTINFO *pResultInfo);
        
        DECLSPEC_XFGVIRT(ISpSREngineSite, AddEvent)
        HRESULT ( STDMETHODCALLTYPE *AddEvent )( 
            ISpSREngineSite2 * This,
            /* [annotation][in] */ 
            _In_  const SPEVENT *pEvent,
            /* [annotation][in] */ 
            _In_  SPRECOCONTEXTHANDLE hSAPIRecoContext);
        
        DECLSPEC_XFGVIRT(ISpSREngineSite, Synchronize)
        HRESULT ( STDMETHODCALLTYPE *Synchronize )( 
            ISpSREngineSite2 * This,
            /* [annotation][in] */ 
            _In_  ULONGLONG ullProcessedThruPos);
        
        DECLSPEC_XFGVIRT(ISpSREngineSite, GetWordInfo)
        HRESULT ( STDMETHODCALLTYPE *GetWordInfo )( 
            ISpSREngineSite2 * This,
            /* [annotation][out][in] */ 
            _Inout_  SPWORDENTRY *pWordEntry,
            /* [annotation][in] */ 
            _In_  SPWORDINFOOPT Options);
        
        DECLSPEC_XFGVIRT(ISpSREngineSite, SetWordClientContext)
        HRESULT ( STDMETHODCALLTYPE *SetWordClientContext )( 
            ISpSREngineSite2 * This,
            /* [annotation][in] */ 
            _In_  SPWORDHANDLE hWord,
            /* [annotation][in] */ 
            _In_  void *pvClientContext);
        
        DECLSPEC_XFGVIRT(ISpSREngineSite, GetRuleInfo)
        HRESULT ( STDMETHODCALLTYPE *GetRuleInfo )( 
            ISpSREngineSite2 * This,
            /* [annotation][out][in] */ 
            _Inout_  SPRULEENTRY *pRuleEntry,
            /* [annotation][in] */ 
            _In_  SPRULEINFOOPT Options);
        
        DECLSPEC_XFGVIRT(ISpSREngineSite, SetRuleClientContext)
        HRESULT ( STDMETHODCALLTYPE *SetRuleClientContext )( 
            ISpSREngineSite2 * This,
            /* [annotation][in] */ 
            _In_  SPRULEHANDLE hRule,
            /* [annotation][in] */ 
            _In_  void *pvClientContext);
        
        DECLSPEC_XFGVIRT(ISpSREngineSite, GetStateInfo)
        HRESULT ( STDMETHODCALLTYPE *GetStateInfo )( 
            ISpSREngineSite2 * This,
            /* [annotation][in] */ 
            _In_  SPSTATEHANDLE hState,
            /* [annotation][out] */ 
            _Out_  SPSTATEINFO *pStateInfo);
        
        DECLSPEC_XFGVIRT(ISpSREngineSite, GetResource)
        HRESULT ( STDMETHODCALLTYPE *GetResource )( 
            ISpSREngineSite2 * This,
            /* [annotation][in] */ 
            _In_  SPRULEHANDLE hRule,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszResourceName,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppCoMemResource);
        
        DECLSPEC_XFGVIRT(ISpSREngineSite, GetTransitionProperty)
        HRESULT ( STDMETHODCALLTYPE *GetTransitionProperty )( 
            ISpSREngineSite2 * This,
            /* [annotation][in] */ 
            _In_  SPTRANSITIONID ID,
            /* [out][annotation] */ 
            _Outptr_  SPTRANSITIONPROPERTY **ppCoMemProperty);
        
        DECLSPEC_XFGVIRT(ISpSREngineSite, IsAlternate)
        HRESULT ( STDMETHODCALLTYPE *IsAlternate )( 
            ISpSREngineSite2 * This,
            /* [annotation][in] */ 
            _In_  SPRULEHANDLE hRule,
            /* [annotation][in] */ 
            _In_  SPRULEHANDLE hAltRule);
        
        DECLSPEC_XFGVIRT(ISpSREngineSite, GetMaxAlternates)
        HRESULT ( STDMETHODCALLTYPE *GetMaxAlternates )( 
            ISpSREngineSite2 * This,
            /* [annotation][in] */ 
            _In_  SPRULEHANDLE hRule,
            /* [annotation][out] */ 
            _Out_  ULONG *pulNumAlts);
        
        DECLSPEC_XFGVIRT(ISpSREngineSite, GetContextMaxAlternates)
        HRESULT ( STDMETHODCALLTYPE *GetContextMaxAlternates )( 
            ISpSREngineSite2 * This,
            /* [annotation][in] */ 
            _In_  SPRECOCONTEXTHANDLE hContext,
            /* [annotation][out] */ 
            _Out_  ULONG *pulNumAlts);
        
        DECLSPEC_XFGVIRT(ISpSREngineSite, UpdateRecoPos)
        HRESULT ( STDMETHODCALLTYPE *UpdateRecoPos )( 
            ISpSREngineSite2 * This,
            /* [annotation][in] */ 
            _In_  ULONGLONG ullCurrentRecoPos);
        
        DECLSPEC_XFGVIRT(ISpSREngineSite2, AddEventEx)
        HRESULT ( STDMETHODCALLTYPE *AddEventEx )( 
            ISpSREngineSite2 * This,
            /* [annotation][in] */ 
            _In_  const SPEVENTEX *pEvent,
            /* [annotation][in] */ 
            _In_  SPRECOCONTEXTHANDLE hSAPIRecoContext);
        
        DECLSPEC_XFGVIRT(ISpSREngineSite2, UpdateRecoPosEx)
        HRESULT ( STDMETHODCALLTYPE *UpdateRecoPosEx )( 
            ISpSREngineSite2 * This,
            /* [annotation][in] */ 
            _In_  ULONGLONG ullCurrentRecoPos,
            /* [annotation][in] */ 
            _In_  ULONGLONG ullCurrentRecoTime);
        
        DECLSPEC_XFGVIRT(ISpSREngineSite2, GetRuleTransition)
        HRESULT ( STDMETHODCALLTYPE *GetRuleTransition )( 
            ISpSREngineSite2 * This,
            /* [annotation][in] */ 
            _In_  ULONG ulGrammarID,
            /* [annotation][in] */ 
            _In_  ULONG RuleIndex,
            /* [annotation][out] */ 
            _Out_  SPTRANSITIONENTRY *pTrans);
        
        DECLSPEC_XFGVIRT(ISpSREngineSite2, RecognitionEx)
        HRESULT ( STDMETHODCALLTYPE *RecognitionEx )( 
            ISpSREngineSite2 * This,
            /* [annotation][in] */ 
            _In_  const SPRECORESULTINFOEX *pResultInfo);
        
        END_INTERFACE
    } ISpSREngineSite2Vtbl;

    interface ISpSREngineSite2
    {
        CONST_VTBL struct ISpSREngineSite2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpSREngineSite2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpSREngineSite2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpSREngineSite2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpSREngineSite2_Read(This,pv,cb,pcbRead)	\
    ( (This)->lpVtbl -> Read(This,pv,cb,pcbRead) ) 

#define ISpSREngineSite2_DataAvailable(This,pcb)	\
    ( (This)->lpVtbl -> DataAvailable(This,pcb) ) 

#define ISpSREngineSite2_SetBufferNotifySize(This,cbSize)	\
    ( (This)->lpVtbl -> SetBufferNotifySize(This,cbSize) ) 

#define ISpSREngineSite2_ParseFromTransitions(This,pParseInfo,ppNewPhrase)	\
    ( (This)->lpVtbl -> ParseFromTransitions(This,pParseInfo,ppNewPhrase) ) 

#define ISpSREngineSite2_Recognition(This,pResultInfo)	\
    ( (This)->lpVtbl -> Recognition(This,pResultInfo) ) 

#define ISpSREngineSite2_AddEvent(This,pEvent,hSAPIRecoContext)	\
    ( (This)->lpVtbl -> AddEvent(This,pEvent,hSAPIRecoContext) ) 

#define ISpSREngineSite2_Synchronize(This,ullProcessedThruPos)	\
    ( (This)->lpVtbl -> Synchronize(This,ullProcessedThruPos) ) 

#define ISpSREngineSite2_GetWordInfo(This,pWordEntry,Options)	\
    ( (This)->lpVtbl -> GetWordInfo(This,pWordEntry,Options) ) 

#define ISpSREngineSite2_SetWordClientContext(This,hWord,pvClientContext)	\
    ( (This)->lpVtbl -> SetWordClientContext(This,hWord,pvClientContext) ) 

#define ISpSREngineSite2_GetRuleInfo(This,pRuleEntry,Options)	\
    ( (This)->lpVtbl -> GetRuleInfo(This,pRuleEntry,Options) ) 

#define ISpSREngineSite2_SetRuleClientContext(This,hRule,pvClientContext)	\
    ( (This)->lpVtbl -> SetRuleClientContext(This,hRule,pvClientContext) ) 

#define ISpSREngineSite2_GetStateInfo(This,hState,pStateInfo)	\
    ( (This)->lpVtbl -> GetStateInfo(This,hState,pStateInfo) ) 

#define ISpSREngineSite2_GetResource(This,hRule,pszResourceName,ppCoMemResource)	\
    ( (This)->lpVtbl -> GetResource(This,hRule,pszResourceName,ppCoMemResource) ) 

#define ISpSREngineSite2_GetTransitionProperty(This,ID,ppCoMemProperty)	\
    ( (This)->lpVtbl -> GetTransitionProperty(This,ID,ppCoMemProperty) ) 

#define ISpSREngineSite2_IsAlternate(This,hRule,hAltRule)	\
    ( (This)->lpVtbl -> IsAlternate(This,hRule,hAltRule) ) 

#define ISpSREngineSite2_GetMaxAlternates(This,hRule,pulNumAlts)	\
    ( (This)->lpVtbl -> GetMaxAlternates(This,hRule,pulNumAlts) ) 

#define ISpSREngineSite2_GetContextMaxAlternates(This,hContext,pulNumAlts)	\
    ( (This)->lpVtbl -> GetContextMaxAlternates(This,hContext,pulNumAlts) ) 

#define ISpSREngineSite2_UpdateRecoPos(This,ullCurrentRecoPos)	\
    ( (This)->lpVtbl -> UpdateRecoPos(This,ullCurrentRecoPos) ) 


#define ISpSREngineSite2_AddEventEx(This,pEvent,hSAPIRecoContext)	\
    ( (This)->lpVtbl -> AddEventEx(This,pEvent,hSAPIRecoContext) ) 

#define ISpSREngineSite2_UpdateRecoPosEx(This,ullCurrentRecoPos,ullCurrentRecoTime)	\
    ( (This)->lpVtbl -> UpdateRecoPosEx(This,ullCurrentRecoPos,ullCurrentRecoTime) ) 

#define ISpSREngineSite2_GetRuleTransition(This,ulGrammarID,RuleIndex,pTrans)	\
    ( (This)->lpVtbl -> GetRuleTransition(This,ulGrammarID,RuleIndex,pTrans) ) 

#define ISpSREngineSite2_RecognitionEx(This,pResultInfo)	\
    ( (This)->lpVtbl -> RecognitionEx(This,pResultInfo) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpSREngineSite2_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_sapiddk_0000_0015 */
/* [local] */ 

typedef 
enum SPPROPSRC
    {
        SPPROPSRC_RECO_INST	= 0,
        SPPROPSRC_RECO_CTX	= ( SPPROPSRC_RECO_INST + 1 ) ,
        SPPROPSRC_RECO_GRAMMAR	= ( SPPROPSRC_RECO_CTX + 1 ) 
    } 	SPPROPSRC;



extern RPC_IF_HANDLE __MIDL_itf_sapiddk_0000_0015_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sapiddk_0000_0015_v0_0_s_ifspec;

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
            /* [annotation][in] */ 
            _In_  ISpSREngineSite *pSite) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetInputAudioFormat( 
            /* [annotation][in] */ 
            _In_  const GUID *pguidSourceFormatId,
            /* [annotation][in] */ 
            _In_  const WAVEFORMATEX *pSourceWaveFormatEx,
            /* [annotation][out] */ 
            _Out_  GUID *pguidDesiredFormatId,
            /* [out][annotation] */ 
            _Outptr_  WAVEFORMATEX **ppCoMemDesiredWaveFormatEx) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RecognizeStream( 
            /* [annotation][in] */ 
            _In_  REFGUID rguidFmtId,
            /* [annotation][in] */ 
            _In_  const WAVEFORMATEX *pWaveFormatEx,
            /* [annotation][in] */ 
            _In_  HANDLE hRequestSync,
            /* [annotation][in] */ 
            _In_  HANDLE hDataAvailable,
            /* [annotation][in] */ 
            _In_  HANDLE hExit,
            /* [annotation][in] */ 
            _In_  BOOL fNewAudioStream,
            /* [annotation][in] */ 
            _In_  BOOL fRealTimeAudio,
            /* [annotation][in] */ 
            _In_  ISpObjectToken *pAudioObjectToken) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetRecoProfile( 
            /* [annotation][in] */ 
            _In_  ISpObjectToken *pProfile) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnCreateGrammar( 
            /* [annotation][in] */ 
            _In_  void *pvEngineRecoContext,
            /* [annotation][in] */ 
            _In_  SPGRAMMARHANDLE hSAPIGrammar,
            /* [out][annotation] */ 
            _Outptr_  void **ppvEngineGrammarContext) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnDeleteGrammar( 
            /* [annotation][in] */ 
            _In_  void *pvEngineGrammar) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadProprietaryGrammar( 
            /* [annotation][in] */ 
            _In_  void *pvEngineGrammar,
            /* [annotation][in] */ 
            _In_  REFGUID rguidParam,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszStringParam,
            /* [annotation][in] */ 
            _In_  const void *pvDataParam,
            /* [annotation][in] */ 
            _In_  ULONG ulDataSize,
            /* [annotation][in] */ 
            _In_  SPLOADOPTIONS Options) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UnloadProprietaryGrammar( 
            /* [annotation][in] */ 
            _In_  void *pvEngineGrammar) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetProprietaryRuleState( 
            /* [annotation][in] */ 
            _In_  void *pvEngineGrammar,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][in] */ 
            _In_  void *pReserved,
            /* [annotation][in] */ 
            _In_  SPRULESTATE NewState,
            /* [annotation][out] */ 
            _Out_  ULONG *pcRulesChanged) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetProprietaryRuleIdState( 
            /* [annotation][in] */ 
            _In_  void *pvEngineGrammar,
            /* [annotation][in] */ 
            _In_  DWORD dwRuleId,
            /* [annotation][in] */ 
            _In_  SPRULESTATE NewState) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadSLM( 
            /* [annotation][in] */ 
            _In_  void *pvEngineGrammar,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszTopicName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UnloadSLM( 
            /* [annotation][in] */ 
            _In_  void *pvEngineGrammar) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetSLMState( 
            /* [annotation][in] */ 
            _In_  void *pvEngineGrammar,
            /* [annotation][in] */ 
            _In_  SPRULESTATE NewState) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetWordSequenceData( 
            /* [annotation][in] */ 
            _In_  void *pvEngineGrammar,
            /* [in][annotation] */ 
            _In_reads_(cchText)  const WCHAR *pText,
            /* [annotation][in] */ 
            _In_  ULONG cchText,
            /* [annotation][in] */ 
            _In_  const SPTEXTSELECTIONINFO *pInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetTextSelection( 
            /* [annotation][in] */ 
            _In_  void *pvEngineGrammar,
            /* [annotation][in] */ 
            _In_  const SPTEXTSELECTIONINFO *pInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsPronounceable( 
            /* [annotation][in] */ 
            _In_  void *pvEngineGrammar,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszWord,
            /* [annotation][out] */ 
            _Out_  SPWORDPRONOUNCEABLE *pWordPronounceable) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnCreateRecoContext( 
            /* [annotation][in] */ 
            _In_  SPRECOCONTEXTHANDLE hSAPIRecoContext,
            /* [annotation][out] */ 
            _Out_  void **ppvEngineContext) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnDeleteRecoContext( 
            /* [annotation][in] */ 
            _In_  void *pvEngineContext) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PrivateCall( 
            /* [annotation][in] */ 
            _In_  void *pvEngineContext,
            /* [annotation][out][in] */ 
            _Inout_  PVOID pCallFrame,
            /* [annotation][in] */ 
            _In_  ULONG ulCallFrameSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAdaptationData( 
            /* [annotation][in] */ 
            _In_  void *pvEngineContext,
            /* [annotation] */ 
            _In_reads_(cch)  const WCHAR *pAdaptationData,
            /* [annotation][in] */ 
            _In_  const ULONG cch) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPropertyNum( 
            /* [annotation][in] */ 
            _In_  SPPROPSRC eSrc,
            /* [annotation][in] */ 
            _In_  void *pvSrcObj,
            /* [annotation][in] */ 
            _In_  const WCHAR *pName,
            /* [annotation][in] */ 
            _In_  LONG lValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPropertyNum( 
            /* [annotation][in] */ 
            _In_  SPPROPSRC eSrc,
            /* [annotation][in] */ 
            _In_  void *pvSrcObj,
            /* [annotation][in] */ 
            _In_  const WCHAR *pName,
            /* [annotation][out] */ 
            _Out_  LONG *lValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPropertyString( 
            /* [annotation][in] */ 
            _In_  SPPROPSRC eSrc,
            /* [annotation][in] */ 
            _In_  void *pvSrcObj,
            /* [annotation][in] */ 
            _In_  LPCWSTR pName,
            /* [annotation][in] */ 
            _In_  LPCWSTR pValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPropertyString( 
            /* [annotation][in] */ 
            _In_  SPPROPSRC eSrc,
            /* [annotation][in] */ 
            _In_  void *pvSrcObj,
            /* [annotation][in] */ 
            _In_  LPCWSTR pName,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppCoMemValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetGrammarState( 
            /* [annotation][in] */ 
            _In_  void *pvEngineGrammar,
            /* [annotation][in] */ 
            _In_  SPGRAMMARSTATE eGrammarState) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE WordNotify( 
            /* [annotation][in] */ 
            _In_  SPCFGNOTIFY Action,
            /* [annotation][in] */ 
            _In_  ULONG cWords,
            /* [annotation][in] */ 
            _In_  const SPWORDENTRY *pWords) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RuleNotify( 
            /* [annotation][in] */ 
            _In_  SPCFGNOTIFY Action,
            /* [annotation][in] */ 
            _In_  ULONG cRules,
            /* [annotation][in] */ 
            _In_  const SPRULEENTRY *pRules) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PrivateCallEx( 
            /* [annotation][in] */ 
            _In_  void *pvEngineContext,
            /* [annotation][in] */ 
            _In_  const void *pInCallFrame,
            /* [annotation][in] */ 
            _In_  ULONG ulInCallFrameSize,
            /* [annotation][out] */ 
            _Out_  void **ppvCoMemResponse,
            /* [annotation][out] */ 
            _Out_  ULONG *pulResponseSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetContextState( 
            /* [annotation][in] */ 
            _In_  void *pvEngineContext,
            /* [annotation][in] */ 
            _In_  SPCONTEXTSTATE eContextState) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpSREngineVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpSREngine * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpSREngine * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpSREngine * This);
        
        DECLSPEC_XFGVIRT(ISpSREngine, SetSite)
        HRESULT ( STDMETHODCALLTYPE *SetSite )( 
            ISpSREngine * This,
            /* [annotation][in] */ 
            _In_  ISpSREngineSite *pSite);
        
        DECLSPEC_XFGVIRT(ISpSREngine, GetInputAudioFormat)
        HRESULT ( STDMETHODCALLTYPE *GetInputAudioFormat )( 
            ISpSREngine * This,
            /* [annotation][in] */ 
            _In_  const GUID *pguidSourceFormatId,
            /* [annotation][in] */ 
            _In_  const WAVEFORMATEX *pSourceWaveFormatEx,
            /* [annotation][out] */ 
            _Out_  GUID *pguidDesiredFormatId,
            /* [out][annotation] */ 
            _Outptr_  WAVEFORMATEX **ppCoMemDesiredWaveFormatEx);
        
        DECLSPEC_XFGVIRT(ISpSREngine, RecognizeStream)
        HRESULT ( STDMETHODCALLTYPE *RecognizeStream )( 
            ISpSREngine * This,
            /* [annotation][in] */ 
            _In_  REFGUID rguidFmtId,
            /* [annotation][in] */ 
            _In_  const WAVEFORMATEX *pWaveFormatEx,
            /* [annotation][in] */ 
            _In_  HANDLE hRequestSync,
            /* [annotation][in] */ 
            _In_  HANDLE hDataAvailable,
            /* [annotation][in] */ 
            _In_  HANDLE hExit,
            /* [annotation][in] */ 
            _In_  BOOL fNewAudioStream,
            /* [annotation][in] */ 
            _In_  BOOL fRealTimeAudio,
            /* [annotation][in] */ 
            _In_  ISpObjectToken *pAudioObjectToken);
        
        DECLSPEC_XFGVIRT(ISpSREngine, SetRecoProfile)
        HRESULT ( STDMETHODCALLTYPE *SetRecoProfile )( 
            ISpSREngine * This,
            /* [annotation][in] */ 
            _In_  ISpObjectToken *pProfile);
        
        DECLSPEC_XFGVIRT(ISpSREngine, OnCreateGrammar)
        HRESULT ( STDMETHODCALLTYPE *OnCreateGrammar )( 
            ISpSREngine * This,
            /* [annotation][in] */ 
            _In_  void *pvEngineRecoContext,
            /* [annotation][in] */ 
            _In_  SPGRAMMARHANDLE hSAPIGrammar,
            /* [out][annotation] */ 
            _Outptr_  void **ppvEngineGrammarContext);
        
        DECLSPEC_XFGVIRT(ISpSREngine, OnDeleteGrammar)
        HRESULT ( STDMETHODCALLTYPE *OnDeleteGrammar )( 
            ISpSREngine * This,
            /* [annotation][in] */ 
            _In_  void *pvEngineGrammar);
        
        DECLSPEC_XFGVIRT(ISpSREngine, LoadProprietaryGrammar)
        HRESULT ( STDMETHODCALLTYPE *LoadProprietaryGrammar )( 
            ISpSREngine * This,
            /* [annotation][in] */ 
            _In_  void *pvEngineGrammar,
            /* [annotation][in] */ 
            _In_  REFGUID rguidParam,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszStringParam,
            /* [annotation][in] */ 
            _In_  const void *pvDataParam,
            /* [annotation][in] */ 
            _In_  ULONG ulDataSize,
            /* [annotation][in] */ 
            _In_  SPLOADOPTIONS Options);
        
        DECLSPEC_XFGVIRT(ISpSREngine, UnloadProprietaryGrammar)
        HRESULT ( STDMETHODCALLTYPE *UnloadProprietaryGrammar )( 
            ISpSREngine * This,
            /* [annotation][in] */ 
            _In_  void *pvEngineGrammar);
        
        DECLSPEC_XFGVIRT(ISpSREngine, SetProprietaryRuleState)
        HRESULT ( STDMETHODCALLTYPE *SetProprietaryRuleState )( 
            ISpSREngine * This,
            /* [annotation][in] */ 
            _In_  void *pvEngineGrammar,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][in] */ 
            _In_  void *pReserved,
            /* [annotation][in] */ 
            _In_  SPRULESTATE NewState,
            /* [annotation][out] */ 
            _Out_  ULONG *pcRulesChanged);
        
        DECLSPEC_XFGVIRT(ISpSREngine, SetProprietaryRuleIdState)
        HRESULT ( STDMETHODCALLTYPE *SetProprietaryRuleIdState )( 
            ISpSREngine * This,
            /* [annotation][in] */ 
            _In_  void *pvEngineGrammar,
            /* [annotation][in] */ 
            _In_  DWORD dwRuleId,
            /* [annotation][in] */ 
            _In_  SPRULESTATE NewState);
        
        DECLSPEC_XFGVIRT(ISpSREngine, LoadSLM)
        HRESULT ( STDMETHODCALLTYPE *LoadSLM )( 
            ISpSREngine * This,
            /* [annotation][in] */ 
            _In_  void *pvEngineGrammar,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszTopicName);
        
        DECLSPEC_XFGVIRT(ISpSREngine, UnloadSLM)
        HRESULT ( STDMETHODCALLTYPE *UnloadSLM )( 
            ISpSREngine * This,
            /* [annotation][in] */ 
            _In_  void *pvEngineGrammar);
        
        DECLSPEC_XFGVIRT(ISpSREngine, SetSLMState)
        HRESULT ( STDMETHODCALLTYPE *SetSLMState )( 
            ISpSREngine * This,
            /* [annotation][in] */ 
            _In_  void *pvEngineGrammar,
            /* [annotation][in] */ 
            _In_  SPRULESTATE NewState);
        
        DECLSPEC_XFGVIRT(ISpSREngine, SetWordSequenceData)
        HRESULT ( STDMETHODCALLTYPE *SetWordSequenceData )( 
            ISpSREngine * This,
            /* [annotation][in] */ 
            _In_  void *pvEngineGrammar,
            /* [in][annotation] */ 
            _In_reads_(cchText)  const WCHAR *pText,
            /* [annotation][in] */ 
            _In_  ULONG cchText,
            /* [annotation][in] */ 
            _In_  const SPTEXTSELECTIONINFO *pInfo);
        
        DECLSPEC_XFGVIRT(ISpSREngine, SetTextSelection)
        HRESULT ( STDMETHODCALLTYPE *SetTextSelection )( 
            ISpSREngine * This,
            /* [annotation][in] */ 
            _In_  void *pvEngineGrammar,
            /* [annotation][in] */ 
            _In_  const SPTEXTSELECTIONINFO *pInfo);
        
        DECLSPEC_XFGVIRT(ISpSREngine, IsPronounceable)
        HRESULT ( STDMETHODCALLTYPE *IsPronounceable )( 
            ISpSREngine * This,
            /* [annotation][in] */ 
            _In_  void *pvEngineGrammar,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszWord,
            /* [annotation][out] */ 
            _Out_  SPWORDPRONOUNCEABLE *pWordPronounceable);
        
        DECLSPEC_XFGVIRT(ISpSREngine, OnCreateRecoContext)
        HRESULT ( STDMETHODCALLTYPE *OnCreateRecoContext )( 
            ISpSREngine * This,
            /* [annotation][in] */ 
            _In_  SPRECOCONTEXTHANDLE hSAPIRecoContext,
            /* [annotation][out] */ 
            _Out_  void **ppvEngineContext);
        
        DECLSPEC_XFGVIRT(ISpSREngine, OnDeleteRecoContext)
        HRESULT ( STDMETHODCALLTYPE *OnDeleteRecoContext )( 
            ISpSREngine * This,
            /* [annotation][in] */ 
            _In_  void *pvEngineContext);
        
        DECLSPEC_XFGVIRT(ISpSREngine, PrivateCall)
        HRESULT ( STDMETHODCALLTYPE *PrivateCall )( 
            ISpSREngine * This,
            /* [annotation][in] */ 
            _In_  void *pvEngineContext,
            /* [annotation][out][in] */ 
            _Inout_  PVOID pCallFrame,
            /* [annotation][in] */ 
            _In_  ULONG ulCallFrameSize);
        
        DECLSPEC_XFGVIRT(ISpSREngine, SetAdaptationData)
        HRESULT ( STDMETHODCALLTYPE *SetAdaptationData )( 
            ISpSREngine * This,
            /* [annotation][in] */ 
            _In_  void *pvEngineContext,
            /* [annotation] */ 
            _In_reads_(cch)  const WCHAR *pAdaptationData,
            /* [annotation][in] */ 
            _In_  const ULONG cch);
        
        DECLSPEC_XFGVIRT(ISpSREngine, SetPropertyNum)
        HRESULT ( STDMETHODCALLTYPE *SetPropertyNum )( 
            ISpSREngine * This,
            /* [annotation][in] */ 
            _In_  SPPROPSRC eSrc,
            /* [annotation][in] */ 
            _In_  void *pvSrcObj,
            /* [annotation][in] */ 
            _In_  const WCHAR *pName,
            /* [annotation][in] */ 
            _In_  LONG lValue);
        
        DECLSPEC_XFGVIRT(ISpSREngine, GetPropertyNum)
        HRESULT ( STDMETHODCALLTYPE *GetPropertyNum )( 
            ISpSREngine * This,
            /* [annotation][in] */ 
            _In_  SPPROPSRC eSrc,
            /* [annotation][in] */ 
            _In_  void *pvSrcObj,
            /* [annotation][in] */ 
            _In_  const WCHAR *pName,
            /* [annotation][out] */ 
            _Out_  LONG *lValue);
        
        DECLSPEC_XFGVIRT(ISpSREngine, SetPropertyString)
        HRESULT ( STDMETHODCALLTYPE *SetPropertyString )( 
            ISpSREngine * This,
            /* [annotation][in] */ 
            _In_  SPPROPSRC eSrc,
            /* [annotation][in] */ 
            _In_  void *pvSrcObj,
            /* [annotation][in] */ 
            _In_  LPCWSTR pName,
            /* [annotation][in] */ 
            _In_  LPCWSTR pValue);
        
        DECLSPEC_XFGVIRT(ISpSREngine, GetPropertyString)
        HRESULT ( STDMETHODCALLTYPE *GetPropertyString )( 
            ISpSREngine * This,
            /* [annotation][in] */ 
            _In_  SPPROPSRC eSrc,
            /* [annotation][in] */ 
            _In_  void *pvSrcObj,
            /* [annotation][in] */ 
            _In_  LPCWSTR pName,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppCoMemValue);
        
        DECLSPEC_XFGVIRT(ISpSREngine, SetGrammarState)
        HRESULT ( STDMETHODCALLTYPE *SetGrammarState )( 
            ISpSREngine * This,
            /* [annotation][in] */ 
            _In_  void *pvEngineGrammar,
            /* [annotation][in] */ 
            _In_  SPGRAMMARSTATE eGrammarState);
        
        DECLSPEC_XFGVIRT(ISpSREngine, WordNotify)
        HRESULT ( STDMETHODCALLTYPE *WordNotify )( 
            ISpSREngine * This,
            /* [annotation][in] */ 
            _In_  SPCFGNOTIFY Action,
            /* [annotation][in] */ 
            _In_  ULONG cWords,
            /* [annotation][in] */ 
            _In_  const SPWORDENTRY *pWords);
        
        DECLSPEC_XFGVIRT(ISpSREngine, RuleNotify)
        HRESULT ( STDMETHODCALLTYPE *RuleNotify )( 
            ISpSREngine * This,
            /* [annotation][in] */ 
            _In_  SPCFGNOTIFY Action,
            /* [annotation][in] */ 
            _In_  ULONG cRules,
            /* [annotation][in] */ 
            _In_  const SPRULEENTRY *pRules);
        
        DECLSPEC_XFGVIRT(ISpSREngine, PrivateCallEx)
        HRESULT ( STDMETHODCALLTYPE *PrivateCallEx )( 
            ISpSREngine * This,
            /* [annotation][in] */ 
            _In_  void *pvEngineContext,
            /* [annotation][in] */ 
            _In_  const void *pInCallFrame,
            /* [annotation][in] */ 
            _In_  ULONG ulInCallFrameSize,
            /* [annotation][out] */ 
            _Out_  void **ppvCoMemResponse,
            /* [annotation][out] */ 
            _Out_  ULONG *pulResponseSize);
        
        DECLSPEC_XFGVIRT(ISpSREngine, SetContextState)
        HRESULT ( STDMETHODCALLTYPE *SetContextState )( 
            ISpSREngine * This,
            /* [annotation][in] */ 
            _In_  void *pvEngineContext,
            /* [annotation][in] */ 
            _In_  SPCONTEXTSTATE eContextState);
        
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


#ifndef __ISpSREngine2_INTERFACE_DEFINED__
#define __ISpSREngine2_INTERFACE_DEFINED__

/* interface ISpSREngine2 */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpSREngine2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7BA627D8-33F9-4375-90C5-9985AEE5EDE5")
    ISpSREngine2 : public ISpSREngine
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE PrivateCallImmediate( 
            /* [annotation][in] */ 
            _In_  void *pvEngineContext,
            /* [annotation][in] */ 
            _In_  const void *pInCallFrame,
            /* [annotation][in] */ 
            _In_  ULONG ulInCallFrameSize,
            /* [out][annotation] */ 
            _Outptr_  void **ppvCoMemResponse,
            /* [annotation][out] */ 
            _Out_  ULONG *pulResponseSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAdaptationData2( 
            /* [annotation][in] */ 
            _In_  void *pvEngineContext,
            /* [in][annotation] */ 
            _In_reads_(cch)  const WCHAR *pAdaptationData,
            /* [annotation][in] */ 
            _In_  const ULONG cch,
            /* [annotation][in] */ 
            _In_  LPCWSTR pTopicName,
            /* [annotation][in] */ 
            _In_  SPADAPTATIONSETTINGS eSettings,
            /* [annotation][in] */ 
            _In_  SPADAPTATIONRELEVANCE eRelevance) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetGrammarPrefix( 
            /* [annotation][in] */ 
            _In_  void *pvEngineGrammar,
            /* [string][in][annotation] */ 
            _In_opt_  LPCWSTR pszPrefix,
            /* [annotation][in] */ 
            _In_  BOOL fIsPrefixRequired) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetRulePriority( 
            /* [annotation][in] */ 
            _In_  SPRULEHANDLE hRule,
            /* [annotation][in] */ 
            _In_  void *pvClientRuleContext,
            /* [annotation][in] */ 
            _In_  int nRulePriority) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EmulateRecognition( 
            /* [annotation][in] */ 
            _In_  ISpPhrase *pPhrase,
            /* [annotation][in] */ 
            _In_  DWORD dwCompareFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetSLMWeight( 
            /* [annotation][in] */ 
            _In_  void *pvEngineGrammar,
            /* [annotation][in] */ 
            _In_  float flWeight) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetRuleWeight( 
            /* [annotation][in] */ 
            _In_  SPRULEHANDLE hRule,
            /* [annotation][in] */ 
            _In_  void *pvClientRuleContext,
            /* [annotation][in] */ 
            _In_  float flWeight) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetTrainingState( 
            /* [annotation][in] */ 
            _In_  BOOL fDoingTraining,
            /* [annotation][in] */ 
            _In_  BOOL fAdaptFromTrainingData) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ResetAcousticModelAdaptation( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnLoadCFG( 
            /* [annotation][in] */ 
            _In_  void *pvEngineGrammar,
            /* [annotation][in] */ 
            _In_  const SPBINARYGRAMMAR *pGrammarData,
            /* [annotation][in] */ 
            _In_  ULONG ulGrammarID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnUnloadCFG( 
            /* [annotation][in] */ 
            _In_  void *pvEngineGrammar,
            /* [annotation][in] */ 
            _In_  ULONG ulGrammarID) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpSREngine2Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpSREngine2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpSREngine2 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpSREngine2 * This);
        
        DECLSPEC_XFGVIRT(ISpSREngine, SetSite)
        HRESULT ( STDMETHODCALLTYPE *SetSite )( 
            ISpSREngine2 * This,
            /* [annotation][in] */ 
            _In_  ISpSREngineSite *pSite);
        
        DECLSPEC_XFGVIRT(ISpSREngine, GetInputAudioFormat)
        HRESULT ( STDMETHODCALLTYPE *GetInputAudioFormat )( 
            ISpSREngine2 * This,
            /* [annotation][in] */ 
            _In_  const GUID *pguidSourceFormatId,
            /* [annotation][in] */ 
            _In_  const WAVEFORMATEX *pSourceWaveFormatEx,
            /* [annotation][out] */ 
            _Out_  GUID *pguidDesiredFormatId,
            /* [out][annotation] */ 
            _Outptr_  WAVEFORMATEX **ppCoMemDesiredWaveFormatEx);
        
        DECLSPEC_XFGVIRT(ISpSREngine, RecognizeStream)
        HRESULT ( STDMETHODCALLTYPE *RecognizeStream )( 
            ISpSREngine2 * This,
            /* [annotation][in] */ 
            _In_  REFGUID rguidFmtId,
            /* [annotation][in] */ 
            _In_  const WAVEFORMATEX *pWaveFormatEx,
            /* [annotation][in] */ 
            _In_  HANDLE hRequestSync,
            /* [annotation][in] */ 
            _In_  HANDLE hDataAvailable,
            /* [annotation][in] */ 
            _In_  HANDLE hExit,
            /* [annotation][in] */ 
            _In_  BOOL fNewAudioStream,
            /* [annotation][in] */ 
            _In_  BOOL fRealTimeAudio,
            /* [annotation][in] */ 
            _In_  ISpObjectToken *pAudioObjectToken);
        
        DECLSPEC_XFGVIRT(ISpSREngine, SetRecoProfile)
        HRESULT ( STDMETHODCALLTYPE *SetRecoProfile )( 
            ISpSREngine2 * This,
            /* [annotation][in] */ 
            _In_  ISpObjectToken *pProfile);
        
        DECLSPEC_XFGVIRT(ISpSREngine, OnCreateGrammar)
        HRESULT ( STDMETHODCALLTYPE *OnCreateGrammar )( 
            ISpSREngine2 * This,
            /* [annotation][in] */ 
            _In_  void *pvEngineRecoContext,
            /* [annotation][in] */ 
            _In_  SPGRAMMARHANDLE hSAPIGrammar,
            /* [out][annotation] */ 
            _Outptr_  void **ppvEngineGrammarContext);
        
        DECLSPEC_XFGVIRT(ISpSREngine, OnDeleteGrammar)
        HRESULT ( STDMETHODCALLTYPE *OnDeleteGrammar )( 
            ISpSREngine2 * This,
            /* [annotation][in] */ 
            _In_  void *pvEngineGrammar);
        
        DECLSPEC_XFGVIRT(ISpSREngine, LoadProprietaryGrammar)
        HRESULT ( STDMETHODCALLTYPE *LoadProprietaryGrammar )( 
            ISpSREngine2 * This,
            /* [annotation][in] */ 
            _In_  void *pvEngineGrammar,
            /* [annotation][in] */ 
            _In_  REFGUID rguidParam,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszStringParam,
            /* [annotation][in] */ 
            _In_  const void *pvDataParam,
            /* [annotation][in] */ 
            _In_  ULONG ulDataSize,
            /* [annotation][in] */ 
            _In_  SPLOADOPTIONS Options);
        
        DECLSPEC_XFGVIRT(ISpSREngine, UnloadProprietaryGrammar)
        HRESULT ( STDMETHODCALLTYPE *UnloadProprietaryGrammar )( 
            ISpSREngine2 * This,
            /* [annotation][in] */ 
            _In_  void *pvEngineGrammar);
        
        DECLSPEC_XFGVIRT(ISpSREngine, SetProprietaryRuleState)
        HRESULT ( STDMETHODCALLTYPE *SetProprietaryRuleState )( 
            ISpSREngine2 * This,
            /* [annotation][in] */ 
            _In_  void *pvEngineGrammar,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][in] */ 
            _In_  void *pReserved,
            /* [annotation][in] */ 
            _In_  SPRULESTATE NewState,
            /* [annotation][out] */ 
            _Out_  ULONG *pcRulesChanged);
        
        DECLSPEC_XFGVIRT(ISpSREngine, SetProprietaryRuleIdState)
        HRESULT ( STDMETHODCALLTYPE *SetProprietaryRuleIdState )( 
            ISpSREngine2 * This,
            /* [annotation][in] */ 
            _In_  void *pvEngineGrammar,
            /* [annotation][in] */ 
            _In_  DWORD dwRuleId,
            /* [annotation][in] */ 
            _In_  SPRULESTATE NewState);
        
        DECLSPEC_XFGVIRT(ISpSREngine, LoadSLM)
        HRESULT ( STDMETHODCALLTYPE *LoadSLM )( 
            ISpSREngine2 * This,
            /* [annotation][in] */ 
            _In_  void *pvEngineGrammar,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszTopicName);
        
        DECLSPEC_XFGVIRT(ISpSREngine, UnloadSLM)
        HRESULT ( STDMETHODCALLTYPE *UnloadSLM )( 
            ISpSREngine2 * This,
            /* [annotation][in] */ 
            _In_  void *pvEngineGrammar);
        
        DECLSPEC_XFGVIRT(ISpSREngine, SetSLMState)
        HRESULT ( STDMETHODCALLTYPE *SetSLMState )( 
            ISpSREngine2 * This,
            /* [annotation][in] */ 
            _In_  void *pvEngineGrammar,
            /* [annotation][in] */ 
            _In_  SPRULESTATE NewState);
        
        DECLSPEC_XFGVIRT(ISpSREngine, SetWordSequenceData)
        HRESULT ( STDMETHODCALLTYPE *SetWordSequenceData )( 
            ISpSREngine2 * This,
            /* [annotation][in] */ 
            _In_  void *pvEngineGrammar,
            /* [in][annotation] */ 
            _In_reads_(cchText)  const WCHAR *pText,
            /* [annotation][in] */ 
            _In_  ULONG cchText,
            /* [annotation][in] */ 
            _In_  const SPTEXTSELECTIONINFO *pInfo);
        
        DECLSPEC_XFGVIRT(ISpSREngine, SetTextSelection)
        HRESULT ( STDMETHODCALLTYPE *SetTextSelection )( 
            ISpSREngine2 * This,
            /* [annotation][in] */ 
            _In_  void *pvEngineGrammar,
            /* [annotation][in] */ 
            _In_  const SPTEXTSELECTIONINFO *pInfo);
        
        DECLSPEC_XFGVIRT(ISpSREngine, IsPronounceable)
        HRESULT ( STDMETHODCALLTYPE *IsPronounceable )( 
            ISpSREngine2 * This,
            /* [annotation][in] */ 
            _In_  void *pvEngineGrammar,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszWord,
            /* [annotation][out] */ 
            _Out_  SPWORDPRONOUNCEABLE *pWordPronounceable);
        
        DECLSPEC_XFGVIRT(ISpSREngine, OnCreateRecoContext)
        HRESULT ( STDMETHODCALLTYPE *OnCreateRecoContext )( 
            ISpSREngine2 * This,
            /* [annotation][in] */ 
            _In_  SPRECOCONTEXTHANDLE hSAPIRecoContext,
            /* [annotation][out] */ 
            _Out_  void **ppvEngineContext);
        
        DECLSPEC_XFGVIRT(ISpSREngine, OnDeleteRecoContext)
        HRESULT ( STDMETHODCALLTYPE *OnDeleteRecoContext )( 
            ISpSREngine2 * This,
            /* [annotation][in] */ 
            _In_  void *pvEngineContext);
        
        DECLSPEC_XFGVIRT(ISpSREngine, PrivateCall)
        HRESULT ( STDMETHODCALLTYPE *PrivateCall )( 
            ISpSREngine2 * This,
            /* [annotation][in] */ 
            _In_  void *pvEngineContext,
            /* [annotation][out][in] */ 
            _Inout_  PVOID pCallFrame,
            /* [annotation][in] */ 
            _In_  ULONG ulCallFrameSize);
        
        DECLSPEC_XFGVIRT(ISpSREngine, SetAdaptationData)
        HRESULT ( STDMETHODCALLTYPE *SetAdaptationData )( 
            ISpSREngine2 * This,
            /* [annotation][in] */ 
            _In_  void *pvEngineContext,
            /* [annotation] */ 
            _In_reads_(cch)  const WCHAR *pAdaptationData,
            /* [annotation][in] */ 
            _In_  const ULONG cch);
        
        DECLSPEC_XFGVIRT(ISpSREngine, SetPropertyNum)
        HRESULT ( STDMETHODCALLTYPE *SetPropertyNum )( 
            ISpSREngine2 * This,
            /* [annotation][in] */ 
            _In_  SPPROPSRC eSrc,
            /* [annotation][in] */ 
            _In_  void *pvSrcObj,
            /* [annotation][in] */ 
            _In_  const WCHAR *pName,
            /* [annotation][in] */ 
            _In_  LONG lValue);
        
        DECLSPEC_XFGVIRT(ISpSREngine, GetPropertyNum)
        HRESULT ( STDMETHODCALLTYPE *GetPropertyNum )( 
            ISpSREngine2 * This,
            /* [annotation][in] */ 
            _In_  SPPROPSRC eSrc,
            /* [annotation][in] */ 
            _In_  void *pvSrcObj,
            /* [annotation][in] */ 
            _In_  const WCHAR *pName,
            /* [annotation][out] */ 
            _Out_  LONG *lValue);
        
        DECLSPEC_XFGVIRT(ISpSREngine, SetPropertyString)
        HRESULT ( STDMETHODCALLTYPE *SetPropertyString )( 
            ISpSREngine2 * This,
            /* [annotation][in] */ 
            _In_  SPPROPSRC eSrc,
            /* [annotation][in] */ 
            _In_  void *pvSrcObj,
            /* [annotation][in] */ 
            _In_  LPCWSTR pName,
            /* [annotation][in] */ 
            _In_  LPCWSTR pValue);
        
        DECLSPEC_XFGVIRT(ISpSREngine, GetPropertyString)
        HRESULT ( STDMETHODCALLTYPE *GetPropertyString )( 
            ISpSREngine2 * This,
            /* [annotation][in] */ 
            _In_  SPPROPSRC eSrc,
            /* [annotation][in] */ 
            _In_  void *pvSrcObj,
            /* [annotation][in] */ 
            _In_  LPCWSTR pName,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppCoMemValue);
        
        DECLSPEC_XFGVIRT(ISpSREngine, SetGrammarState)
        HRESULT ( STDMETHODCALLTYPE *SetGrammarState )( 
            ISpSREngine2 * This,
            /* [annotation][in] */ 
            _In_  void *pvEngineGrammar,
            /* [annotation][in] */ 
            _In_  SPGRAMMARSTATE eGrammarState);
        
        DECLSPEC_XFGVIRT(ISpSREngine, WordNotify)
        HRESULT ( STDMETHODCALLTYPE *WordNotify )( 
            ISpSREngine2 * This,
            /* [annotation][in] */ 
            _In_  SPCFGNOTIFY Action,
            /* [annotation][in] */ 
            _In_  ULONG cWords,
            /* [annotation][in] */ 
            _In_  const SPWORDENTRY *pWords);
        
        DECLSPEC_XFGVIRT(ISpSREngine, RuleNotify)
        HRESULT ( STDMETHODCALLTYPE *RuleNotify )( 
            ISpSREngine2 * This,
            /* [annotation][in] */ 
            _In_  SPCFGNOTIFY Action,
            /* [annotation][in] */ 
            _In_  ULONG cRules,
            /* [annotation][in] */ 
            _In_  const SPRULEENTRY *pRules);
        
        DECLSPEC_XFGVIRT(ISpSREngine, PrivateCallEx)
        HRESULT ( STDMETHODCALLTYPE *PrivateCallEx )( 
            ISpSREngine2 * This,
            /* [annotation][in] */ 
            _In_  void *pvEngineContext,
            /* [annotation][in] */ 
            _In_  const void *pInCallFrame,
            /* [annotation][in] */ 
            _In_  ULONG ulInCallFrameSize,
            /* [annotation][out] */ 
            _Out_  void **ppvCoMemResponse,
            /* [annotation][out] */ 
            _Out_  ULONG *pulResponseSize);
        
        DECLSPEC_XFGVIRT(ISpSREngine, SetContextState)
        HRESULT ( STDMETHODCALLTYPE *SetContextState )( 
            ISpSREngine2 * This,
            /* [annotation][in] */ 
            _In_  void *pvEngineContext,
            /* [annotation][in] */ 
            _In_  SPCONTEXTSTATE eContextState);
        
        DECLSPEC_XFGVIRT(ISpSREngine2, PrivateCallImmediate)
        HRESULT ( STDMETHODCALLTYPE *PrivateCallImmediate )( 
            ISpSREngine2 * This,
            /* [annotation][in] */ 
            _In_  void *pvEngineContext,
            /* [annotation][in] */ 
            _In_  const void *pInCallFrame,
            /* [annotation][in] */ 
            _In_  ULONG ulInCallFrameSize,
            /* [out][annotation] */ 
            _Outptr_  void **ppvCoMemResponse,
            /* [annotation][out] */ 
            _Out_  ULONG *pulResponseSize);
        
        DECLSPEC_XFGVIRT(ISpSREngine2, SetAdaptationData2)
        HRESULT ( STDMETHODCALLTYPE *SetAdaptationData2 )( 
            ISpSREngine2 * This,
            /* [annotation][in] */ 
            _In_  void *pvEngineContext,
            /* [in][annotation] */ 
            _In_reads_(cch)  const WCHAR *pAdaptationData,
            /* [annotation][in] */ 
            _In_  const ULONG cch,
            /* [annotation][in] */ 
            _In_  LPCWSTR pTopicName,
            /* [annotation][in] */ 
            _In_  SPADAPTATIONSETTINGS eSettings,
            /* [annotation][in] */ 
            _In_  SPADAPTATIONRELEVANCE eRelevance);
        
        DECLSPEC_XFGVIRT(ISpSREngine2, SetGrammarPrefix)
        HRESULT ( STDMETHODCALLTYPE *SetGrammarPrefix )( 
            ISpSREngine2 * This,
            /* [annotation][in] */ 
            _In_  void *pvEngineGrammar,
            /* [string][in][annotation] */ 
            _In_opt_  LPCWSTR pszPrefix,
            /* [annotation][in] */ 
            _In_  BOOL fIsPrefixRequired);
        
        DECLSPEC_XFGVIRT(ISpSREngine2, SetRulePriority)
        HRESULT ( STDMETHODCALLTYPE *SetRulePriority )( 
            ISpSREngine2 * This,
            /* [annotation][in] */ 
            _In_  SPRULEHANDLE hRule,
            /* [annotation][in] */ 
            _In_  void *pvClientRuleContext,
            /* [annotation][in] */ 
            _In_  int nRulePriority);
        
        DECLSPEC_XFGVIRT(ISpSREngine2, EmulateRecognition)
        HRESULT ( STDMETHODCALLTYPE *EmulateRecognition )( 
            ISpSREngine2 * This,
            /* [annotation][in] */ 
            _In_  ISpPhrase *pPhrase,
            /* [annotation][in] */ 
            _In_  DWORD dwCompareFlags);
        
        DECLSPEC_XFGVIRT(ISpSREngine2, SetSLMWeight)
        HRESULT ( STDMETHODCALLTYPE *SetSLMWeight )( 
            ISpSREngine2 * This,
            /* [annotation][in] */ 
            _In_  void *pvEngineGrammar,
            /* [annotation][in] */ 
            _In_  float flWeight);
        
        DECLSPEC_XFGVIRT(ISpSREngine2, SetRuleWeight)
        HRESULT ( STDMETHODCALLTYPE *SetRuleWeight )( 
            ISpSREngine2 * This,
            /* [annotation][in] */ 
            _In_  SPRULEHANDLE hRule,
            /* [annotation][in] */ 
            _In_  void *pvClientRuleContext,
            /* [annotation][in] */ 
            _In_  float flWeight);
        
        DECLSPEC_XFGVIRT(ISpSREngine2, SetTrainingState)
        HRESULT ( STDMETHODCALLTYPE *SetTrainingState )( 
            ISpSREngine2 * This,
            /* [annotation][in] */ 
            _In_  BOOL fDoingTraining,
            /* [annotation][in] */ 
            _In_  BOOL fAdaptFromTrainingData);
        
        DECLSPEC_XFGVIRT(ISpSREngine2, ResetAcousticModelAdaptation)
        HRESULT ( STDMETHODCALLTYPE *ResetAcousticModelAdaptation )( 
            ISpSREngine2 * This);
        
        DECLSPEC_XFGVIRT(ISpSREngine2, OnLoadCFG)
        HRESULT ( STDMETHODCALLTYPE *OnLoadCFG )( 
            ISpSREngine2 * This,
            /* [annotation][in] */ 
            _In_  void *pvEngineGrammar,
            /* [annotation][in] */ 
            _In_  const SPBINARYGRAMMAR *pGrammarData,
            /* [annotation][in] */ 
            _In_  ULONG ulGrammarID);
        
        DECLSPEC_XFGVIRT(ISpSREngine2, OnUnloadCFG)
        HRESULT ( STDMETHODCALLTYPE *OnUnloadCFG )( 
            ISpSREngine2 * This,
            /* [annotation][in] */ 
            _In_  void *pvEngineGrammar,
            /* [annotation][in] */ 
            _In_  ULONG ulGrammarID);
        
        END_INTERFACE
    } ISpSREngine2Vtbl;

    interface ISpSREngine2
    {
        CONST_VTBL struct ISpSREngine2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpSREngine2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpSREngine2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpSREngine2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpSREngine2_SetSite(This,pSite)	\
    ( (This)->lpVtbl -> SetSite(This,pSite) ) 

#define ISpSREngine2_GetInputAudioFormat(This,pguidSourceFormatId,pSourceWaveFormatEx,pguidDesiredFormatId,ppCoMemDesiredWaveFormatEx)	\
    ( (This)->lpVtbl -> GetInputAudioFormat(This,pguidSourceFormatId,pSourceWaveFormatEx,pguidDesiredFormatId,ppCoMemDesiredWaveFormatEx) ) 

#define ISpSREngine2_RecognizeStream(This,rguidFmtId,pWaveFormatEx,hRequestSync,hDataAvailable,hExit,fNewAudioStream,fRealTimeAudio,pAudioObjectToken)	\
    ( (This)->lpVtbl -> RecognizeStream(This,rguidFmtId,pWaveFormatEx,hRequestSync,hDataAvailable,hExit,fNewAudioStream,fRealTimeAudio,pAudioObjectToken) ) 

#define ISpSREngine2_SetRecoProfile(This,pProfile)	\
    ( (This)->lpVtbl -> SetRecoProfile(This,pProfile) ) 

#define ISpSREngine2_OnCreateGrammar(This,pvEngineRecoContext,hSAPIGrammar,ppvEngineGrammarContext)	\
    ( (This)->lpVtbl -> OnCreateGrammar(This,pvEngineRecoContext,hSAPIGrammar,ppvEngineGrammarContext) ) 

#define ISpSREngine2_OnDeleteGrammar(This,pvEngineGrammar)	\
    ( (This)->lpVtbl -> OnDeleteGrammar(This,pvEngineGrammar) ) 

#define ISpSREngine2_LoadProprietaryGrammar(This,pvEngineGrammar,rguidParam,pszStringParam,pvDataParam,ulDataSize,Options)	\
    ( (This)->lpVtbl -> LoadProprietaryGrammar(This,pvEngineGrammar,rguidParam,pszStringParam,pvDataParam,ulDataSize,Options) ) 

#define ISpSREngine2_UnloadProprietaryGrammar(This,pvEngineGrammar)	\
    ( (This)->lpVtbl -> UnloadProprietaryGrammar(This,pvEngineGrammar) ) 

#define ISpSREngine2_SetProprietaryRuleState(This,pvEngineGrammar,pszName,pReserved,NewState,pcRulesChanged)	\
    ( (This)->lpVtbl -> SetProprietaryRuleState(This,pvEngineGrammar,pszName,pReserved,NewState,pcRulesChanged) ) 

#define ISpSREngine2_SetProprietaryRuleIdState(This,pvEngineGrammar,dwRuleId,NewState)	\
    ( (This)->lpVtbl -> SetProprietaryRuleIdState(This,pvEngineGrammar,dwRuleId,NewState) ) 

#define ISpSREngine2_LoadSLM(This,pvEngineGrammar,pszTopicName)	\
    ( (This)->lpVtbl -> LoadSLM(This,pvEngineGrammar,pszTopicName) ) 

#define ISpSREngine2_UnloadSLM(This,pvEngineGrammar)	\
    ( (This)->lpVtbl -> UnloadSLM(This,pvEngineGrammar) ) 

#define ISpSREngine2_SetSLMState(This,pvEngineGrammar,NewState)	\
    ( (This)->lpVtbl -> SetSLMState(This,pvEngineGrammar,NewState) ) 

#define ISpSREngine2_SetWordSequenceData(This,pvEngineGrammar,pText,cchText,pInfo)	\
    ( (This)->lpVtbl -> SetWordSequenceData(This,pvEngineGrammar,pText,cchText,pInfo) ) 

#define ISpSREngine2_SetTextSelection(This,pvEngineGrammar,pInfo)	\
    ( (This)->lpVtbl -> SetTextSelection(This,pvEngineGrammar,pInfo) ) 

#define ISpSREngine2_IsPronounceable(This,pvEngineGrammar,pszWord,pWordPronounceable)	\
    ( (This)->lpVtbl -> IsPronounceable(This,pvEngineGrammar,pszWord,pWordPronounceable) ) 

#define ISpSREngine2_OnCreateRecoContext(This,hSAPIRecoContext,ppvEngineContext)	\
    ( (This)->lpVtbl -> OnCreateRecoContext(This,hSAPIRecoContext,ppvEngineContext) ) 

#define ISpSREngine2_OnDeleteRecoContext(This,pvEngineContext)	\
    ( (This)->lpVtbl -> OnDeleteRecoContext(This,pvEngineContext) ) 

#define ISpSREngine2_PrivateCall(This,pvEngineContext,pCallFrame,ulCallFrameSize)	\
    ( (This)->lpVtbl -> PrivateCall(This,pvEngineContext,pCallFrame,ulCallFrameSize) ) 

#define ISpSREngine2_SetAdaptationData(This,pvEngineContext,pAdaptationData,cch)	\
    ( (This)->lpVtbl -> SetAdaptationData(This,pvEngineContext,pAdaptationData,cch) ) 

#define ISpSREngine2_SetPropertyNum(This,eSrc,pvSrcObj,pName,lValue)	\
    ( (This)->lpVtbl -> SetPropertyNum(This,eSrc,pvSrcObj,pName,lValue) ) 

#define ISpSREngine2_GetPropertyNum(This,eSrc,pvSrcObj,pName,lValue)	\
    ( (This)->lpVtbl -> GetPropertyNum(This,eSrc,pvSrcObj,pName,lValue) ) 

#define ISpSREngine2_SetPropertyString(This,eSrc,pvSrcObj,pName,pValue)	\
    ( (This)->lpVtbl -> SetPropertyString(This,eSrc,pvSrcObj,pName,pValue) ) 

#define ISpSREngine2_GetPropertyString(This,eSrc,pvSrcObj,pName,ppCoMemValue)	\
    ( (This)->lpVtbl -> GetPropertyString(This,eSrc,pvSrcObj,pName,ppCoMemValue) ) 

#define ISpSREngine2_SetGrammarState(This,pvEngineGrammar,eGrammarState)	\
    ( (This)->lpVtbl -> SetGrammarState(This,pvEngineGrammar,eGrammarState) ) 

#define ISpSREngine2_WordNotify(This,Action,cWords,pWords)	\
    ( (This)->lpVtbl -> WordNotify(This,Action,cWords,pWords) ) 

#define ISpSREngine2_RuleNotify(This,Action,cRules,pRules)	\
    ( (This)->lpVtbl -> RuleNotify(This,Action,cRules,pRules) ) 

#define ISpSREngine2_PrivateCallEx(This,pvEngineContext,pInCallFrame,ulInCallFrameSize,ppvCoMemResponse,pulResponseSize)	\
    ( (This)->lpVtbl -> PrivateCallEx(This,pvEngineContext,pInCallFrame,ulInCallFrameSize,ppvCoMemResponse,pulResponseSize) ) 

#define ISpSREngine2_SetContextState(This,pvEngineContext,eContextState)	\
    ( (This)->lpVtbl -> SetContextState(This,pvEngineContext,eContextState) ) 


#define ISpSREngine2_PrivateCallImmediate(This,pvEngineContext,pInCallFrame,ulInCallFrameSize,ppvCoMemResponse,pulResponseSize)	\
    ( (This)->lpVtbl -> PrivateCallImmediate(This,pvEngineContext,pInCallFrame,ulInCallFrameSize,ppvCoMemResponse,pulResponseSize) ) 

#define ISpSREngine2_SetAdaptationData2(This,pvEngineContext,pAdaptationData,cch,pTopicName,eSettings,eRelevance)	\
    ( (This)->lpVtbl -> SetAdaptationData2(This,pvEngineContext,pAdaptationData,cch,pTopicName,eSettings,eRelevance) ) 

#define ISpSREngine2_SetGrammarPrefix(This,pvEngineGrammar,pszPrefix,fIsPrefixRequired)	\
    ( (This)->lpVtbl -> SetGrammarPrefix(This,pvEngineGrammar,pszPrefix,fIsPrefixRequired) ) 

#define ISpSREngine2_SetRulePriority(This,hRule,pvClientRuleContext,nRulePriority)	\
    ( (This)->lpVtbl -> SetRulePriority(This,hRule,pvClientRuleContext,nRulePriority) ) 

#define ISpSREngine2_EmulateRecognition(This,pPhrase,dwCompareFlags)	\
    ( (This)->lpVtbl -> EmulateRecognition(This,pPhrase,dwCompareFlags) ) 

#define ISpSREngine2_SetSLMWeight(This,pvEngineGrammar,flWeight)	\
    ( (This)->lpVtbl -> SetSLMWeight(This,pvEngineGrammar,flWeight) ) 

#define ISpSREngine2_SetRuleWeight(This,hRule,pvClientRuleContext,flWeight)	\
    ( (This)->lpVtbl -> SetRuleWeight(This,hRule,pvClientRuleContext,flWeight) ) 

#define ISpSREngine2_SetTrainingState(This,fDoingTraining,fAdaptFromTrainingData)	\
    ( (This)->lpVtbl -> SetTrainingState(This,fDoingTraining,fAdaptFromTrainingData) ) 

#define ISpSREngine2_ResetAcousticModelAdaptation(This)	\
    ( (This)->lpVtbl -> ResetAcousticModelAdaptation(This) ) 

#define ISpSREngine2_OnLoadCFG(This,pvEngineGrammar,pGrammarData,ulGrammarID)	\
    ( (This)->lpVtbl -> OnLoadCFG(This,pvEngineGrammar,pGrammarData,ulGrammarID) ) 

#define ISpSREngine2_OnUnloadCFG(This,pvEngineGrammar,ulGrammarID)	\
    ( (This)->lpVtbl -> OnUnloadCFG(This,pvEngineGrammar,ulGrammarID) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpSREngine2_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_sapiddk_0000_0017 */
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



extern RPC_IF_HANDLE __MIDL_itf_sapiddk_0000_0017_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sapiddk_0000_0017_v0_0_s_ifspec;

#ifndef __ISpSRAlternates_INTERFACE_DEFINED__
#define __ISpSRAlternates_INTERFACE_DEFINED__

/* interface ISpSRAlternates */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpSRAlternates;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("FECE8294-2BE1-408F-8E68-2DE377092F0E")
    ISpSRAlternates : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetAlternates( 
            /* [annotation][in] */ 
            _In_  SPPHRASEALTREQUEST *pAltRequest,
            /* [annotation][out] */ 
            _Out_  SPPHRASEALT **ppAlts,
            /* [annotation][out] */ 
            _Out_  ULONG *pcAlts) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Commit( 
            /* [annotation][in] */ 
            _In_  SPPHRASEALTREQUEST *pAltRequest,
            /* [annotation][in] */ 
            _In_  SPPHRASEALT *pAlt,
            /* [annotation][out] */ 
            _Out_  void **ppvResultExtra,
            /* [annotation][out] */ 
            _Out_  ULONG *pcbResultExtra) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpSRAlternatesVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpSRAlternates * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpSRAlternates * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpSRAlternates * This);
        
        DECLSPEC_XFGVIRT(ISpSRAlternates, GetAlternates)
        HRESULT ( STDMETHODCALLTYPE *GetAlternates )( 
            ISpSRAlternates * This,
            /* [annotation][in] */ 
            _In_  SPPHRASEALTREQUEST *pAltRequest,
            /* [annotation][out] */ 
            _Out_  SPPHRASEALT **ppAlts,
            /* [annotation][out] */ 
            _Out_  ULONG *pcAlts);
        
        DECLSPEC_XFGVIRT(ISpSRAlternates, Commit)
        HRESULT ( STDMETHODCALLTYPE *Commit )( 
            ISpSRAlternates * This,
            /* [annotation][in] */ 
            _In_  SPPHRASEALTREQUEST *pAltRequest,
            /* [annotation][in] */ 
            _In_  SPPHRASEALT *pAlt,
            /* [annotation][out] */ 
            _Out_  void **ppvResultExtra,
            /* [annotation][out] */ 
            _Out_  ULONG *pcbResultExtra);
        
        END_INTERFACE
    } ISpSRAlternatesVtbl;

    interface ISpSRAlternates
    {
        CONST_VTBL struct ISpSRAlternatesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpSRAlternates_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpSRAlternates_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpSRAlternates_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpSRAlternates_GetAlternates(This,pAltRequest,ppAlts,pcAlts)	\
    ( (This)->lpVtbl -> GetAlternates(This,pAltRequest,ppAlts,pcAlts) ) 

#define ISpSRAlternates_Commit(This,pAltRequest,pAlt,ppvResultExtra,pcbResultExtra)	\
    ( (This)->lpVtbl -> Commit(This,pAltRequest,pAlt,ppvResultExtra,pcbResultExtra) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpSRAlternates_INTERFACE_DEFINED__ */


#ifndef __ISpSRAlternates2_INTERFACE_DEFINED__
#define __ISpSRAlternates2_INTERFACE_DEFINED__

/* interface ISpSRAlternates2 */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpSRAlternates2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F338F437-CB33-4020-9CAB-C71FF9CE12D3")
    ISpSRAlternates2 : public ISpSRAlternates
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CommitText( 
            /* [annotation][in] */ 
            _In_  SPPHRASEALTREQUEST *pAltRequest,
            /* [annotation] */ 
            _In_opt_  LPCWSTR pcszNewText,
            /* [annotation][in] */ 
            _In_  SPCOMMITFLAGS commitFlags) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpSRAlternates2Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpSRAlternates2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpSRAlternates2 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpSRAlternates2 * This);
        
        DECLSPEC_XFGVIRT(ISpSRAlternates, GetAlternates)
        HRESULT ( STDMETHODCALLTYPE *GetAlternates )( 
            ISpSRAlternates2 * This,
            /* [annotation][in] */ 
            _In_  SPPHRASEALTREQUEST *pAltRequest,
            /* [annotation][out] */ 
            _Out_  SPPHRASEALT **ppAlts,
            /* [annotation][out] */ 
            _Out_  ULONG *pcAlts);
        
        DECLSPEC_XFGVIRT(ISpSRAlternates, Commit)
        HRESULT ( STDMETHODCALLTYPE *Commit )( 
            ISpSRAlternates2 * This,
            /* [annotation][in] */ 
            _In_  SPPHRASEALTREQUEST *pAltRequest,
            /* [annotation][in] */ 
            _In_  SPPHRASEALT *pAlt,
            /* [annotation][out] */ 
            _Out_  void **ppvResultExtra,
            /* [annotation][out] */ 
            _Out_  ULONG *pcbResultExtra);
        
        DECLSPEC_XFGVIRT(ISpSRAlternates2, CommitText)
        HRESULT ( STDMETHODCALLTYPE *CommitText )( 
            ISpSRAlternates2 * This,
            /* [annotation][in] */ 
            _In_  SPPHRASEALTREQUEST *pAltRequest,
            /* [annotation] */ 
            _In_opt_  LPCWSTR pcszNewText,
            /* [annotation][in] */ 
            _In_  SPCOMMITFLAGS commitFlags);
        
        END_INTERFACE
    } ISpSRAlternates2Vtbl;

    interface ISpSRAlternates2
    {
        CONST_VTBL struct ISpSRAlternates2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpSRAlternates2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpSRAlternates2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpSRAlternates2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpSRAlternates2_GetAlternates(This,pAltRequest,ppAlts,pcAlts)	\
    ( (This)->lpVtbl -> GetAlternates(This,pAltRequest,ppAlts,pcAlts) ) 

#define ISpSRAlternates2_Commit(This,pAltRequest,pAlt,ppvResultExtra,pcbResultExtra)	\
    ( (This)->lpVtbl -> Commit(This,pAltRequest,pAlt,ppvResultExtra,pcbResultExtra) ) 


#define ISpSRAlternates2_CommitText(This,pAltRequest,pcszNewText,commitFlags)	\
    ( (This)->lpVtbl -> CommitText(This,pAltRequest,pcszNewText,commitFlags) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpSRAlternates2_INTERFACE_DEFINED__ */


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
            /* [annotation][in] */ 
            _In_  ULONG ulCallFrameSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CallEngineEx( 
            /* [in][annotation] */ 
            _In_reads_bytes_(ulInFrameSize)  const void *pInFrame,
            /* [annotation][in] */ 
            _In_  ULONG ulInFrameSize,
            /* [out][annotation] */ 
            _Outptr_result_buffer_maybenull_(*pulOutFrameSize)  void **ppCoMemOutFrame,
            /* [out][annotation] */ 
            _Out_writes_(1)  ULONG *pulOutFrameSize) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct _ISpPrivateEngineCallVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _ISpPrivateEngineCall * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _ISpPrivateEngineCall * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _ISpPrivateEngineCall * This);
        
        DECLSPEC_XFGVIRT(_ISpPrivateEngineCall, CallEngine)
        HRESULT ( STDMETHODCALLTYPE *CallEngine )( 
            _ISpPrivateEngineCall * This,
            /* [out][in][annotation] */ 
            _Inout_updates_bytes_(ulCallFrameSize)  void *pCallFrame,
            /* [annotation][in] */ 
            _In_  ULONG ulCallFrameSize);
        
        DECLSPEC_XFGVIRT(_ISpPrivateEngineCall, CallEngineEx)
        HRESULT ( STDMETHODCALLTYPE *CallEngineEx )( 
            _ISpPrivateEngineCall * This,
            /* [in][annotation] */ 
            _In_reads_bytes_(ulInFrameSize)  const void *pInFrame,
            /* [annotation][in] */ 
            _In_  ULONG ulInFrameSize,
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


#ifndef __ISpPrivateEngineCallEx_INTERFACE_DEFINED__
#define __ISpPrivateEngineCallEx_INTERFACE_DEFINED__

/* interface ISpPrivateEngineCallEx */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpPrivateEngineCallEx;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DEFD682A-FE0A-42B9-BFA1-56D3D6CECFAF")
    ISpPrivateEngineCallEx : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CallEngineSynchronize( 
            /* [in][annotation] */ 
            _In_reads_bytes_(ulInFrameSize)  const void *pInFrame,
            /* [annotation][in] */ 
            _In_  ULONG ulInFrameSize,
            /* [out][annotation] */ 
            _Outptr_result_bytebuffer_(*pulOutFrameSize)  void **ppCoMemOutFrame,
            /* [out][annotation] */ 
            _Out_writes_(1)  ULONG *pulOutFrameSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CallEngineImmediate( 
            /* [in][annotation] */ 
            _In_reads_bytes_(ulInFrameSize)  const void *pInFrame,
            /* [annotation][in] */ 
            _In_  ULONG ulInFrameSize,
            /* [out][annotation] */ 
            _Outptr_result_bytebuffer_(*pulOutFrameSize)  void **ppCoMemOutFrame,
            /* [out][annotation] */ 
            _Out_writes_(1)  ULONG *pulOutFrameSize) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpPrivateEngineCallExVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpPrivateEngineCallEx * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpPrivateEngineCallEx * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpPrivateEngineCallEx * This);
        
        DECLSPEC_XFGVIRT(ISpPrivateEngineCallEx, CallEngineSynchronize)
        HRESULT ( STDMETHODCALLTYPE *CallEngineSynchronize )( 
            ISpPrivateEngineCallEx * This,
            /* [in][annotation] */ 
            _In_reads_bytes_(ulInFrameSize)  const void *pInFrame,
            /* [annotation][in] */ 
            _In_  ULONG ulInFrameSize,
            /* [out][annotation] */ 
            _Outptr_result_bytebuffer_(*pulOutFrameSize)  void **ppCoMemOutFrame,
            /* [out][annotation] */ 
            _Out_writes_(1)  ULONG *pulOutFrameSize);
        
        DECLSPEC_XFGVIRT(ISpPrivateEngineCallEx, CallEngineImmediate)
        HRESULT ( STDMETHODCALLTYPE *CallEngineImmediate )( 
            ISpPrivateEngineCallEx * This,
            /* [in][annotation] */ 
            _In_reads_bytes_(ulInFrameSize)  const void *pInFrame,
            /* [annotation][in] */ 
            _In_  ULONG ulInFrameSize,
            /* [out][annotation] */ 
            _Outptr_result_bytebuffer_(*pulOutFrameSize)  void **ppCoMemOutFrame,
            /* [out][annotation] */ 
            _Out_writes_(1)  ULONG *pulOutFrameSize);
        
        END_INTERFACE
    } ISpPrivateEngineCallExVtbl;

    interface ISpPrivateEngineCallEx
    {
        CONST_VTBL struct ISpPrivateEngineCallExVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpPrivateEngineCallEx_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpPrivateEngineCallEx_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpPrivateEngineCallEx_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpPrivateEngineCallEx_CallEngineSynchronize(This,pInFrame,ulInFrameSize,ppCoMemOutFrame,pulOutFrameSize)	\
    ( (This)->lpVtbl -> CallEngineSynchronize(This,pInFrame,ulInFrameSize,ppCoMemOutFrame,pulOutFrameSize) ) 

#define ISpPrivateEngineCallEx_CallEngineImmediate(This,pInFrame,ulInFrameSize,ppCoMemOutFrame,pulOutFrameSize)	\
    ( (This)->lpVtbl -> CallEngineImmediate(This,pInFrame,ulInFrameSize,ppCoMemOutFrame,pulOutFrameSize) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpPrivateEngineCallEx_INTERFACE_DEFINED__ */



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

EXTERN_C const CLSID CLSID_SpW3CGrammarCompiler;

#ifdef __cplusplus

class DECLSPEC_UUID("D2C13906-51EF-454E-BC67-A52475FF074C")
SpW3CGrammarCompiler;
#endif

EXTERN_C const CLSID CLSID_SpGramCompBackend;

#ifdef __cplusplus

class DECLSPEC_UUID("DA93E903-C843-11D2-A084-00C04F8EF9B5")
SpGramCompBackend;
#endif
#endif /* __SpeechDDKLib_LIBRARY_DEFINED__ */

/* interface __MIDL_itf_sapiddk_0000_0022 */
/* [local] */ 

#else
#include "sapiddk51.h"
#endif  // _SAPI_VER >= 0x053
#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_sapiddk_0000_0022_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sapiddk_0000_0022_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


