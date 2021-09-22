

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


#ifndef __dimm_h__
#define __dimm_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IEnumRegisterWordA_FWD_DEFINED__
#define __IEnumRegisterWordA_FWD_DEFINED__
typedef interface IEnumRegisterWordA IEnumRegisterWordA;

#endif 	/* __IEnumRegisterWordA_FWD_DEFINED__ */


#ifndef __IEnumRegisterWordW_FWD_DEFINED__
#define __IEnumRegisterWordW_FWD_DEFINED__
typedef interface IEnumRegisterWordW IEnumRegisterWordW;

#endif 	/* __IEnumRegisterWordW_FWD_DEFINED__ */


#ifndef __IEnumInputContext_FWD_DEFINED__
#define __IEnumInputContext_FWD_DEFINED__
typedef interface IEnumInputContext IEnumInputContext;

#endif 	/* __IEnumInputContext_FWD_DEFINED__ */


#ifndef __IActiveIMMRegistrar_FWD_DEFINED__
#define __IActiveIMMRegistrar_FWD_DEFINED__
typedef interface IActiveIMMRegistrar IActiveIMMRegistrar;

#endif 	/* __IActiveIMMRegistrar_FWD_DEFINED__ */


#ifndef __IActiveIMMMessagePumpOwner_FWD_DEFINED__
#define __IActiveIMMMessagePumpOwner_FWD_DEFINED__
typedef interface IActiveIMMMessagePumpOwner IActiveIMMMessagePumpOwner;

#endif 	/* __IActiveIMMMessagePumpOwner_FWD_DEFINED__ */


#ifndef __IActiveIMMApp_FWD_DEFINED__
#define __IActiveIMMApp_FWD_DEFINED__
typedef interface IActiveIMMApp IActiveIMMApp;

#endif 	/* __IActiveIMMApp_FWD_DEFINED__ */


#ifndef __IActiveIMMIME_FWD_DEFINED__
#define __IActiveIMMIME_FWD_DEFINED__
typedef interface IActiveIMMIME IActiveIMMIME;

#endif 	/* __IActiveIMMIME_FWD_DEFINED__ */


#ifndef __IActiveIME_FWD_DEFINED__
#define __IActiveIME_FWD_DEFINED__
typedef interface IActiveIME IActiveIME;

#endif 	/* __IActiveIME_FWD_DEFINED__ */


#ifndef __IActiveIME2_FWD_DEFINED__
#define __IActiveIME2_FWD_DEFINED__
typedef interface IActiveIME2 IActiveIME2;

#endif 	/* __IActiveIME2_FWD_DEFINED__ */


#ifndef __CActiveIMM_FWD_DEFINED__
#define __CActiveIMM_FWD_DEFINED__

#ifdef __cplusplus
typedef class CActiveIMM CActiveIMM;
#else
typedef struct CActiveIMM CActiveIMM;
#endif /* __cplusplus */

#endif 	/* __CActiveIMM_FWD_DEFINED__ */


/* header files for imported files */
#include "unknwn.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_dimm_0000_0000 */
/* [local] */ 

//=--------------------------------------------------------------------------=
// dimm.h
//=--------------------------------------------------------------------------=
// (C) Copyright Microsoft Corporation.  All Rights Reserved.
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//=--------------------------------------------------------------------------=

#pragma comment(lib,"uuid.lib")

//--------------------------------------------------------------------------
// IActiveIMM Interfaces.

#include <winapifamily.h>
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)



extern RPC_IF_HANDLE __MIDL_itf_dimm_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_dimm_0000_0000_v0_0_s_ifspec;


#ifndef __ActiveIMM_LIBRARY_DEFINED__
#define __ActiveIMM_LIBRARY_DEFINED__

/* library ActiveIMM */
/* [version][lcid][helpstring][uuid] */ 

#include <imm.h>
#if 0
typedef WORD LANGID;

typedef /* [public][public][public][public] */ struct __MIDL___MIDL_itf_dimm_0000_0000_0001
    {
    LPSTR lpReading;
    LPSTR lpWord;
    } 	REGISTERWORDA;

typedef /* [public][public][public][public][public] */ struct __MIDL___MIDL_itf_dimm_0000_0000_0002
    {
    LPWSTR lpReading;
    LPWSTR lpWord;
    } 	REGISTERWORDW;

typedef /* [public][public][public][public][public][public][public] */ struct __MIDL___MIDL_itf_dimm_0000_0000_0003
    {
    LONG lfHeight;
    LONG lfWidth;
    LONG lfEscapement;
    LONG lfOrientation;
    LONG lfWeight;
    BYTE lfItalic;
    BYTE lfUnderline;
    BYTE lfStrikeOut;
    BYTE lfCharSet;
    BYTE lfOutPrecision;
    BYTE lfClipPrecision;
    BYTE lfQuality;
    BYTE lfPitchAndFamily;
    CHAR lfFaceName[ 32 ];
    } 	LOGFONTA;

typedef /* [public][public][public][public][public][public][public] */ struct __MIDL___MIDL_itf_dimm_0000_0000_0004
    {
    LONG lfHeight;
    LONG lfWidth;
    LONG lfEscapement;
    LONG lfOrientation;
    LONG lfWeight;
    BYTE lfItalic;
    BYTE lfUnderline;
    BYTE lfStrikeOut;
    BYTE lfCharSet;
    BYTE lfOutPrecision;
    BYTE lfClipPrecision;
    BYTE lfQuality;
    BYTE lfPitchAndFamily;
    WCHAR lfFaceName[ 32 ];
    } 	LOGFONTW;

typedef DWORD HIMC;

typedef DWORD HIMCC;

typedef /* [public][public][public][public][public][public][public] */ struct __MIDL___MIDL_itf_dimm_0000_0000_0005
    {
    DWORD dwIndex;
    DWORD dwStyle;
    POINT ptCurrentPos;
    RECT rcArea;
    } 	CANDIDATEFORM;

typedef /* [public][public][public][public][public][public][public] */ struct __MIDL___MIDL_itf_dimm_0000_0000_0006
    {
    DWORD dwStyle;
    POINT ptCurrentPos;
    RECT rcArea;
    } 	COMPOSITIONFORM;

typedef /* [public][public][public][public][public][public][public][public][public][public] */ struct __MIDL___MIDL_itf_dimm_0000_0000_0007
    {
    DWORD dwSize;
    DWORD dwStyle;
    DWORD dwCount;
    DWORD dwSelection;
    DWORD dwPageStart;
    DWORD dwPageSize;
    DWORD dwOffset[ 1 ];
    } 	CANDIDATELIST;

typedef /* [public][public][public] */ struct __MIDL___MIDL_itf_dimm_0000_0000_0008
    {
    DWORD dwStyle;
    CHAR szDescription[ 32 ];
    } 	STYLEBUFA;

typedef /* [public][public][public][public] */ struct __MIDL___MIDL_itf_dimm_0000_0000_0009
    {
    DWORD dwStyle;
    WCHAR szDescription[ 32 ];
    } 	STYLEBUFW;

typedef WORD ATOM;

#endif
#if (WINVER < 0x040A)
typedef /* [public][public][public][public][public] */ struct __MIDL___MIDL_itf_dimm_0000_0000_0010
    {
    UINT cbSize;
    UINT fType;
    UINT fState;
    UINT wID;
    HBITMAP hbmpChecked;
    HBITMAP hbmpUnchecked;
    DWORD dwItemData;
    CHAR szString[ 80 ];
    HBITMAP hbmpItem;
    } 	IMEMENUITEMINFOA;

typedef /* [public][public][public][public][public] */ struct __MIDL___MIDL_itf_dimm_0000_0000_0011
    {
    UINT cbSize;
    UINT fType;
    UINT fState;
    UINT wID;
    HBITMAP hbmpChecked;
    HBITMAP hbmpUnchecked;
    DWORD dwItemData;
    WCHAR szString[ 80 ];
    HBITMAP hbmpItem;
    } 	IMEMENUITEMINFOW;

#endif
#ifndef _DDKIMM_H_
typedef /* [public][public] */ struct __MIDL___MIDL_itf_dimm_0000_0000_0012
    {
    HWND hWnd;
    BOOL fOpen;
    POINT ptStatusWndPos;
    POINT ptSoftKbdPos;
    DWORD fdwConversion;
    DWORD fdwSentence;
    union 
        {
        LOGFONTA A;
        LOGFONTW W;
        } 	lfFont;
    COMPOSITIONFORM cfCompForm;
    CANDIDATEFORM cfCandForm[ 4 ];
    HIMCC hCompStr;
    HIMCC hCandInfo;
    HIMCC hGuideLine;
    HIMCC hPrivate;
    DWORD dwNumMsgBuf;
    HIMCC hMsgBuf;
    DWORD fdwInit;
    DWORD dwReserve[ 3 ];
    } 	INPUTCONTEXT;

typedef /* [public][public] */ struct __MIDL___MIDL_itf_dimm_0000_0000_0014
    {
    DWORD dwPrivateDataSize;
    DWORD fdwProperty;
    DWORD fdwConversionCaps;
    DWORD fdwSentenceCaps;
    DWORD fdwUICaps;
    DWORD fdwSCSCaps;
    DWORD fdwSelectCaps;
    } 	IMEINFO;

#endif

EXTERN_C const IID LIBID_ActiveIMM;

#ifndef __IEnumRegisterWordA_INTERFACE_DEFINED__
#define __IEnumRegisterWordA_INTERFACE_DEFINED__

/* interface IEnumRegisterWordA */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IEnumRegisterWordA;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("08C03412-F96B-11d0-A475-00AA006BCC59")
    IEnumRegisterWordA : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [annotation][out] */ 
            _Out_  IEnumRegisterWordA **ppEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [annotation][in] */ 
            _In_  ULONG ulCount,
            /* [annotation][out] */ 
            _Out_  REGISTERWORDA *rgRegisterWord,
            /* [annotation][out] */ 
            _Out_  ULONG *pcFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [annotation][in] */ 
            _In_  ULONG ulCount) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IEnumRegisterWordAVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IEnumRegisterWordA * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IEnumRegisterWordA * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IEnumRegisterWordA * This);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            __RPC__in IEnumRegisterWordA * This,
            /* [annotation][out] */ 
            _Out_  IEnumRegisterWordA **ppEnum);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            __RPC__in IEnumRegisterWordA * This,
            /* [annotation][in] */ 
            _In_  ULONG ulCount,
            /* [annotation][out] */ 
            _Out_  REGISTERWORDA *rgRegisterWord,
            /* [annotation][out] */ 
            _Out_  ULONG *pcFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            __RPC__in IEnumRegisterWordA * This);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            __RPC__in IEnumRegisterWordA * This,
            /* [annotation][in] */ 
            _In_  ULONG ulCount);
        
        END_INTERFACE
    } IEnumRegisterWordAVtbl;

    interface IEnumRegisterWordA
    {
        CONST_VTBL struct IEnumRegisterWordAVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumRegisterWordA_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEnumRegisterWordA_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEnumRegisterWordA_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IEnumRegisterWordA_Clone(This,ppEnum)	\
    ( (This)->lpVtbl -> Clone(This,ppEnum) ) 

#define IEnumRegisterWordA_Next(This,ulCount,rgRegisterWord,pcFetched)	\
    ( (This)->lpVtbl -> Next(This,ulCount,rgRegisterWord,pcFetched) ) 

#define IEnumRegisterWordA_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define IEnumRegisterWordA_Skip(This,ulCount)	\
    ( (This)->lpVtbl -> Skip(This,ulCount) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IEnumRegisterWordA_INTERFACE_DEFINED__ */


#ifndef __IEnumRegisterWordW_INTERFACE_DEFINED__
#define __IEnumRegisterWordW_INTERFACE_DEFINED__

/* interface IEnumRegisterWordW */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IEnumRegisterWordW;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4955DD31-B159-11d0-8FCF-00AA006BCC59")
    IEnumRegisterWordW : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [annotation][out] */ 
            _Out_  IEnumRegisterWordW **ppEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [annotation][in] */ 
            _In_  ULONG ulCount,
            /* [annotation][out] */ 
            _Out_  REGISTERWORDW *rgRegisterWord,
            /* [annotation][out] */ 
            _Out_  ULONG *pcFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [annotation][in] */ 
            _In_  ULONG ulCount) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IEnumRegisterWordWVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IEnumRegisterWordW * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IEnumRegisterWordW * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IEnumRegisterWordW * This);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            __RPC__in IEnumRegisterWordW * This,
            /* [annotation][out] */ 
            _Out_  IEnumRegisterWordW **ppEnum);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            __RPC__in IEnumRegisterWordW * This,
            /* [annotation][in] */ 
            _In_  ULONG ulCount,
            /* [annotation][out] */ 
            _Out_  REGISTERWORDW *rgRegisterWord,
            /* [annotation][out] */ 
            _Out_  ULONG *pcFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            __RPC__in IEnumRegisterWordW * This);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            __RPC__in IEnumRegisterWordW * This,
            /* [annotation][in] */ 
            _In_  ULONG ulCount);
        
        END_INTERFACE
    } IEnumRegisterWordWVtbl;

    interface IEnumRegisterWordW
    {
        CONST_VTBL struct IEnumRegisterWordWVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumRegisterWordW_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEnumRegisterWordW_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEnumRegisterWordW_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IEnumRegisterWordW_Clone(This,ppEnum)	\
    ( (This)->lpVtbl -> Clone(This,ppEnum) ) 

#define IEnumRegisterWordW_Next(This,ulCount,rgRegisterWord,pcFetched)	\
    ( (This)->lpVtbl -> Next(This,ulCount,rgRegisterWord,pcFetched) ) 

#define IEnumRegisterWordW_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define IEnumRegisterWordW_Skip(This,ulCount)	\
    ( (This)->lpVtbl -> Skip(This,ulCount) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IEnumRegisterWordW_INTERFACE_DEFINED__ */


#ifndef __IEnumInputContext_INTERFACE_DEFINED__
#define __IEnumInputContext_INTERFACE_DEFINED__

/* interface IEnumInputContext */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IEnumInputContext;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("09b5eab0-f997-11d1-93d4-0060b067b86e")
    IEnumInputContext : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [annotation][out] */ 
            _Out_  IEnumInputContext **ppEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [annotation][in] */ 
            _In_  ULONG ulCount,
            /* [annotation][out] */ 
            _Out_  HIMC *rgInputContext,
            /* [annotation][out] */ 
            _Out_  ULONG *pcFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [annotation][in] */ 
            _In_  ULONG ulCount) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IEnumInputContextVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IEnumInputContext * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IEnumInputContext * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IEnumInputContext * This);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            __RPC__in IEnumInputContext * This,
            /* [annotation][out] */ 
            _Out_  IEnumInputContext **ppEnum);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            __RPC__in IEnumInputContext * This,
            /* [annotation][in] */ 
            _In_  ULONG ulCount,
            /* [annotation][out] */ 
            _Out_  HIMC *rgInputContext,
            /* [annotation][out] */ 
            _Out_  ULONG *pcFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            __RPC__in IEnumInputContext * This);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            __RPC__in IEnumInputContext * This,
            /* [annotation][in] */ 
            _In_  ULONG ulCount);
        
        END_INTERFACE
    } IEnumInputContextVtbl;

    interface IEnumInputContext
    {
        CONST_VTBL struct IEnumInputContextVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumInputContext_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEnumInputContext_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEnumInputContext_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IEnumInputContext_Clone(This,ppEnum)	\
    ( (This)->lpVtbl -> Clone(This,ppEnum) ) 

#define IEnumInputContext_Next(This,ulCount,rgInputContext,pcFetched)	\
    ( (This)->lpVtbl -> Next(This,ulCount,rgInputContext,pcFetched) ) 

#define IEnumInputContext_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define IEnumInputContext_Skip(This,ulCount)	\
    ( (This)->lpVtbl -> Skip(This,ulCount) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IEnumInputContext_INTERFACE_DEFINED__ */


#ifndef __IActiveIMMRegistrar_INTERFACE_DEFINED__
#define __IActiveIMMRegistrar_INTERFACE_DEFINED__

/* interface IActiveIMMRegistrar */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IActiveIMMRegistrar;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("b3458082-bd00-11d1-939b-0060b067b86e")
    IActiveIMMRegistrar : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE RegisterIME( 
            /* [annotation][in] */ 
            _In_  REFCLSID rclsid,
            /* [annotation][in] */ 
            _In_  LANGID lgid,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszIconFile,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszDesc) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UnregisterIME( 
            /* [annotation][in] */ 
            _In_  REFCLSID rclsid) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IActiveIMMRegistrarVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IActiveIMMRegistrar * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IActiveIMMRegistrar * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IActiveIMMRegistrar * This);
        
        HRESULT ( STDMETHODCALLTYPE *RegisterIME )( 
            __RPC__in IActiveIMMRegistrar * This,
            /* [annotation][in] */ 
            _In_  REFCLSID rclsid,
            /* [annotation][in] */ 
            _In_  LANGID lgid,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszIconFile,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszDesc);
        
        HRESULT ( STDMETHODCALLTYPE *UnregisterIME )( 
            __RPC__in IActiveIMMRegistrar * This,
            /* [annotation][in] */ 
            _In_  REFCLSID rclsid);
        
        END_INTERFACE
    } IActiveIMMRegistrarVtbl;

    interface IActiveIMMRegistrar
    {
        CONST_VTBL struct IActiveIMMRegistrarVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActiveIMMRegistrar_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IActiveIMMRegistrar_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IActiveIMMRegistrar_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IActiveIMMRegistrar_RegisterIME(This,rclsid,lgid,pszIconFile,pszDesc)	\
    ( (This)->lpVtbl -> RegisterIME(This,rclsid,lgid,pszIconFile,pszDesc) ) 

#define IActiveIMMRegistrar_UnregisterIME(This,rclsid)	\
    ( (This)->lpVtbl -> UnregisterIME(This,rclsid) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IActiveIMMRegistrar_INTERFACE_DEFINED__ */


#ifndef __IActiveIMMMessagePumpOwner_INTERFACE_DEFINED__
#define __IActiveIMMMessagePumpOwner_INTERFACE_DEFINED__

/* interface IActiveIMMMessagePumpOwner */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IActiveIMMMessagePumpOwner;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("b5cf2cfa-8aeb-11d1-9364-0060b067b86e")
    IActiveIMMMessagePumpOwner : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Start( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE End( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnTranslateMessage( 
            /* [annotation][in] */ 
            _In_  const MSG *pMsg) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Pause( 
            /* [annotation][out] */ 
            _Out_  DWORD *pdwCookie) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Resume( 
            /* [annotation][in] */ 
            _In_  DWORD dwCookie) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IActiveIMMMessagePumpOwnerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IActiveIMMMessagePumpOwner * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IActiveIMMMessagePumpOwner * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IActiveIMMMessagePumpOwner * This);
        
        HRESULT ( STDMETHODCALLTYPE *Start )( 
            __RPC__in IActiveIMMMessagePumpOwner * This);
        
        HRESULT ( STDMETHODCALLTYPE *End )( 
            __RPC__in IActiveIMMMessagePumpOwner * This);
        
        HRESULT ( STDMETHODCALLTYPE *OnTranslateMessage )( 
            __RPC__in IActiveIMMMessagePumpOwner * This,
            /* [annotation][in] */ 
            _In_  const MSG *pMsg);
        
        HRESULT ( STDMETHODCALLTYPE *Pause )( 
            __RPC__in IActiveIMMMessagePumpOwner * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwCookie);
        
        HRESULT ( STDMETHODCALLTYPE *Resume )( 
            __RPC__in IActiveIMMMessagePumpOwner * This,
            /* [annotation][in] */ 
            _In_  DWORD dwCookie);
        
        END_INTERFACE
    } IActiveIMMMessagePumpOwnerVtbl;

    interface IActiveIMMMessagePumpOwner
    {
        CONST_VTBL struct IActiveIMMMessagePumpOwnerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActiveIMMMessagePumpOwner_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IActiveIMMMessagePumpOwner_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IActiveIMMMessagePumpOwner_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IActiveIMMMessagePumpOwner_Start(This)	\
    ( (This)->lpVtbl -> Start(This) ) 

#define IActiveIMMMessagePumpOwner_End(This)	\
    ( (This)->lpVtbl -> End(This) ) 

#define IActiveIMMMessagePumpOwner_OnTranslateMessage(This,pMsg)	\
    ( (This)->lpVtbl -> OnTranslateMessage(This,pMsg) ) 

#define IActiveIMMMessagePumpOwner_Pause(This,pdwCookie)	\
    ( (This)->lpVtbl -> Pause(This,pdwCookie) ) 

#define IActiveIMMMessagePumpOwner_Resume(This,dwCookie)	\
    ( (This)->lpVtbl -> Resume(This,dwCookie) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IActiveIMMMessagePumpOwner_INTERFACE_DEFINED__ */


#ifndef __IActiveIMMApp_INTERFACE_DEFINED__
#define __IActiveIMMApp_INTERFACE_DEFINED__

/* interface IActiveIMMApp */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IActiveIMMApp;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("08c0e040-62d1-11d1-9326-0060b067b86e")
    IActiveIMMApp : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AssociateContext( 
            /* [annotation][in] */ 
            _In_  HWND hWnd,
            /* [annotation][in] */ 
            _In_  HIMC hIME,
            /* [annotation][out] */ 
            _Out_  HIMC *phPrev) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ConfigureIMEA( 
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  HWND hWnd,
            /* [annotation][in] */ 
            _In_  DWORD dwMode,
            /* [annotation][in] */ 
            _In_  REGISTERWORDA *pData) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ConfigureIMEW( 
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  HWND hWnd,
            /* [annotation][in] */ 
            _In_  DWORD dwMode,
            /* [annotation][in] */ 
            _In_  REGISTERWORDW *pData) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateContext( 
            /* [annotation][out] */ 
            _Out_  HIMC *phIMC) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DestroyContext( 
            /* [annotation][in] */ 
            _In_  HIMC hIME) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumRegisterWordA( 
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  LPSTR szReading,
            /* [annotation][in] */ 
            _In_  DWORD dwStyle,
            /* [annotation][in] */ 
            _In_  LPSTR szRegister,
            /* [annotation][in] */ 
            _In_  LPVOID pData,
            /* [annotation][out] */ 
            _Out_  IEnumRegisterWordA **pEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumRegisterWordW( 
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  LPWSTR szReading,
            /* [annotation][in] */ 
            _In_  DWORD dwStyle,
            /* [annotation][in] */ 
            _In_  LPWSTR szRegister,
            /* [annotation][in] */ 
            _In_  LPVOID pData,
            /* [annotation][out] */ 
            _Out_  IEnumRegisterWordW **pEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EscapeA( 
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  UINT uEscape,
            /* [annotation][out][in] */ 
            _Inout_  LPVOID pData,
            /* [annotation][out] */ 
            _Out_  LRESULT *plResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EscapeW( 
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  UINT uEscape,
            /* [annotation][out][in] */ 
            _Inout_  LPVOID pData,
            /* [annotation][out] */ 
            _Out_  LRESULT *plResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCandidateListA( 
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][in] */ 
            _In_  UINT uBufLen,
            /* [annotation][out] */ 
            _Out_  CANDIDATELIST *pCandList,
            /* [annotation][out] */ 
            _Out_  UINT *puCopied) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCandidateListW( 
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][in] */ 
            _In_  UINT uBufLen,
            /* [annotation][out] */ 
            _Out_  CANDIDATELIST *pCandList,
            /* [annotation][out] */ 
            _Out_  UINT *puCopied) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCandidateListCountA( 
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwListSize,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwBufLen) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCandidateListCountW( 
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwListSize,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwBufLen) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCandidateWindow( 
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][out] */ 
            _Out_  CANDIDATEFORM *pCandidate) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCompositionFontA( 
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][out] */ 
            _Out_  LOGFONTA *plf) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCompositionFontW( 
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][out] */ 
            _Out_  LOGFONTW *plf) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCompositionStringA( 
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][in] */ 
            _In_  DWORD dwBufLen,
            /* [annotation][out] */ 
            _Out_  LONG *plCopied,
            /* [annotation][out] */ 
            _Out_  LPVOID pBuf) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCompositionStringW( 
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][in] */ 
            _In_  DWORD dwBufLen,
            /* [annotation][out] */ 
            _Out_  LONG *plCopied,
            /* [annotation][out] */ 
            _Out_  LPVOID pBuf) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCompositionWindow( 
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][out] */ 
            _Out_  COMPOSITIONFORM *pCompForm) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetContext( 
            /* [annotation][in] */ 
            _In_  HWND hWnd,
            /* [annotation][out] */ 
            _Out_  HIMC *phIMC) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetConversionListA( 
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  LPSTR pSrc,
            /* [annotation][in] */ 
            _In_  UINT uBufLen,
            /* [annotation][in] */ 
            _In_  UINT uFlag,
            /* [annotation][out] */ 
            _Out_  CANDIDATELIST *pDst,
            /* [annotation][out] */ 
            _Out_  UINT *puCopied) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetConversionListW( 
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  LPWSTR pSrc,
            /* [annotation][in] */ 
            _In_  UINT uBufLen,
            /* [annotation][in] */ 
            _In_  UINT uFlag,
            /* [annotation][out] */ 
            _Out_  CANDIDATELIST *pDst,
            /* [annotation][out] */ 
            _Out_  UINT *puCopied) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetConversionStatus( 
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][out] */ 
            _Out_  DWORD *pfdwConversion,
            /* [annotation][out] */ 
            _Out_  DWORD *pfdwSentence) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDefaultIMEWnd( 
            /* [annotation][in] */ 
            _In_  HWND hWnd,
            /* [annotation][out] */ 
            _Out_  HWND *phDefWnd) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDescriptionA( 
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  UINT uBufLen,
            /* [annotation][out] */ 
            _Out_  LPSTR szDescription,
            /* [annotation][out] */ 
            _Out_  UINT *puCopied) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDescriptionW( 
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  UINT uBufLen,
            /* [annotation][out] */ 
            _Out_  LPWSTR szDescription,
            /* [annotation][out] */ 
            _Out_  UINT *puCopied) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetGuideLineA( 
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][in] */ 
            _In_  DWORD dwBufLen,
            /* [annotation][out] */ 
            _Out_  LPSTR pBuf,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetGuideLineW( 
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][in] */ 
            _In_  DWORD dwBufLen,
            /* [annotation][out] */ 
            _Out_  LPWSTR pBuf,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetIMEFileNameA( 
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  UINT uBufLen,
            /* [annotation][out] */ 
            _Out_  LPSTR szFileName,
            /* [annotation][out] */ 
            _Out_  UINT *puCopied) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetIMEFileNameW( 
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  UINT uBufLen,
            /* [annotation][out] */ 
            _Out_  LPWSTR szFileName,
            /* [annotation][out] */ 
            _Out_  UINT *puCopied) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetOpenStatus( 
            /* [annotation][in] */ 
            _In_  HIMC hIMC) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetProperty( 
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  DWORD fdwIndex,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwProperty) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRegisterWordStyleA( 
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  UINT nItem,
            /* [annotation][out] */ 
            _Out_  STYLEBUFA *pStyleBuf,
            /* [annotation][out] */ 
            _Out_  UINT *puCopied) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRegisterWordStyleW( 
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  UINT nItem,
            /* [annotation][out] */ 
            _Out_  STYLEBUFW *pStyleBuf,
            /* [annotation][out] */ 
            _Out_  UINT *puCopied) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStatusWindowPos( 
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][out] */ 
            _Out_  POINT *pptPos) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetVirtualKey( 
            /* [annotation][in] */ 
            _In_  HWND hWnd,
            /* [annotation][out] */ 
            _Out_  UINT *puVirtualKey) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InstallIMEA( 
            /* [annotation][in] */ 
            _In_  LPSTR szIMEFileName,
            /* [annotation][in] */ 
            _In_  LPSTR szLayoutText,
            /* [annotation][out] */ 
            _Out_  HKL *phKL) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InstallIMEW( 
            /* [annotation][in] */ 
            _In_  LPWSTR szIMEFileName,
            /* [annotation][in] */ 
            _In_  LPWSTR szLayoutText,
            /* [annotation][out] */ 
            _Out_  HKL *phKL) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsIME( 
            /* [annotation][in] */ 
            _In_  HKL hKL) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsUIMessageA( 
            /* [annotation][in] */ 
            _In_  HWND hWndIME,
            /* [annotation][in] */ 
            _In_  UINT msg,
            /* [annotation][in] */ 
            _In_  WPARAM wParam,
            /* [annotation][in] */ 
            _In_  LPARAM lParam) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsUIMessageW( 
            /* [annotation][in] */ 
            _In_  HWND hWndIME,
            /* [annotation][in] */ 
            _In_  UINT msg,
            /* [annotation][in] */ 
            _In_  WPARAM wParam,
            /* [annotation][in] */ 
            _In_  LPARAM lParam) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE NotifyIME( 
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  DWORD dwAction,
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][in] */ 
            _In_  DWORD dwValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RegisterWordA( 
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  LPSTR szReading,
            /* [annotation][in] */ 
            _In_  DWORD dwStyle,
            /* [annotation][in] */ 
            _In_  LPSTR szRegister) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RegisterWordW( 
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  LPWSTR szReading,
            /* [annotation][in] */ 
            _In_  DWORD dwStyle,
            /* [annotation][in] */ 
            _In_  LPWSTR szRegister) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReleaseContext( 
            /* [annotation][in] */ 
            _In_  HWND hWnd,
            /* [annotation][in] */ 
            _In_  HIMC hIMC) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetCandidateWindow( 
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  CANDIDATEFORM *pCandidate) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetCompositionFontA( 
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  LOGFONTA *plf) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetCompositionFontW( 
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  LOGFONTW *plf) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetCompositionStringA( 
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][in] */ 
            _In_  LPVOID pComp,
            /* [annotation][in] */ 
            _In_  DWORD dwCompLen,
            /* [annotation][in] */ 
            _In_  LPVOID pRead,
            /* [annotation][in] */ 
            _In_  DWORD dwReadLen) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetCompositionStringW( 
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][in] */ 
            _In_  LPVOID pComp,
            /* [annotation][in] */ 
            _In_  DWORD dwCompLen,
            /* [annotation][in] */ 
            _In_  LPVOID pRead,
            /* [annotation][in] */ 
            _In_  DWORD dwReadLen) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetCompositionWindow( 
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  COMPOSITIONFORM *pCompForm) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetConversionStatus( 
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  DWORD fdwConversion,
            /* [annotation][in] */ 
            _In_  DWORD fdwSentence) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetOpenStatus( 
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  BOOL fOpen) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetStatusWindowPos( 
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  POINT *pptPos) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SimulateHotKey( 
            /* [annotation][in] */ 
            _In_  HWND hWnd,
            /* [annotation][in] */ 
            _In_  DWORD dwHotKeyID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UnregisterWordA( 
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  LPSTR szReading,
            /* [annotation][in] */ 
            _In_  DWORD dwStyle,
            /* [annotation][in] */ 
            _In_  LPSTR szUnregister) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UnregisterWordW( 
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  LPWSTR szReading,
            /* [annotation][in] */ 
            _In_  DWORD dwStyle,
            /* [annotation][in] */ 
            _In_  LPWSTR szUnregister) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Activate( 
            /* [annotation][in] */ 
            _In_  BOOL fRestoreLayout) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Deactivate( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnDefWindowProc( 
            /* [annotation][in] */ 
            _In_  HWND hWnd,
            /* [annotation][in] */ 
            _In_  UINT Msg,
            /* [annotation][in] */ 
            _In_  WPARAM wParam,
            /* [annotation][in] */ 
            _In_  LPARAM lParam,
            /* [annotation][out] */ 
            _Out_  LRESULT *plResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FilterClientWindows( 
            /* [annotation][in] */ 
            _In_  ATOM *aaClassList,
            /* [annotation][in] */ 
            _In_  UINT uSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCodePageA( 
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][out] */ 
            _Out_  UINT *uCodePage) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLangId( 
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][out] */ 
            _Out_  LANGID *plid) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AssociateContextEx( 
            /* [annotation][in] */ 
            _In_  HWND hWnd,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DisableIME( 
            /* [annotation][in] */ 
            _In_  DWORD idThread) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetImeMenuItemsA( 
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][in] */ 
            _In_  DWORD dwType,
            /* [annotation][in] */ 
            _In_  IMEMENUITEMINFOA *pImeParentMenu,
            /* [annotation][out] */ 
            _Out_  IMEMENUITEMINFOA *pImeMenu,
            /* [annotation][in] */ 
            _In_  DWORD dwSize,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetImeMenuItemsW( 
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][in] */ 
            _In_  DWORD dwType,
            /* [annotation][in] */ 
            _In_  IMEMENUITEMINFOW *pImeParentMenu,
            /* [annotation][out] */ 
            _Out_  IMEMENUITEMINFOW *pImeMenu,
            /* [annotation][in] */ 
            _In_  DWORD dwSize,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumInputContext( 
            /* [annotation][in] */ 
            _In_  DWORD idThread,
            /* [annotation][out] */ 
            _Out_  IEnumInputContext **ppEnum) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IActiveIMMAppVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IActiveIMMApp * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IActiveIMMApp * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IActiveIMMApp * This);
        
        HRESULT ( STDMETHODCALLTYPE *AssociateContext )( 
            __RPC__in IActiveIMMApp * This,
            /* [annotation][in] */ 
            _In_  HWND hWnd,
            /* [annotation][in] */ 
            _In_  HIMC hIME,
            /* [annotation][out] */ 
            _Out_  HIMC *phPrev);
        
        HRESULT ( STDMETHODCALLTYPE *ConfigureIMEA )( 
            __RPC__in IActiveIMMApp * This,
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  HWND hWnd,
            /* [annotation][in] */ 
            _In_  DWORD dwMode,
            /* [annotation][in] */ 
            _In_  REGISTERWORDA *pData);
        
        HRESULT ( STDMETHODCALLTYPE *ConfigureIMEW )( 
            __RPC__in IActiveIMMApp * This,
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  HWND hWnd,
            /* [annotation][in] */ 
            _In_  DWORD dwMode,
            /* [annotation][in] */ 
            _In_  REGISTERWORDW *pData);
        
        HRESULT ( STDMETHODCALLTYPE *CreateContext )( 
            __RPC__in IActiveIMMApp * This,
            /* [annotation][out] */ 
            _Out_  HIMC *phIMC);
        
        HRESULT ( STDMETHODCALLTYPE *DestroyContext )( 
            __RPC__in IActiveIMMApp * This,
            /* [annotation][in] */ 
            _In_  HIMC hIME);
        
        HRESULT ( STDMETHODCALLTYPE *EnumRegisterWordA )( 
            __RPC__in IActiveIMMApp * This,
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  LPSTR szReading,
            /* [annotation][in] */ 
            _In_  DWORD dwStyle,
            /* [annotation][in] */ 
            _In_  LPSTR szRegister,
            /* [annotation][in] */ 
            _In_  LPVOID pData,
            /* [annotation][out] */ 
            _Out_  IEnumRegisterWordA **pEnum);
        
        HRESULT ( STDMETHODCALLTYPE *EnumRegisterWordW )( 
            __RPC__in IActiveIMMApp * This,
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  LPWSTR szReading,
            /* [annotation][in] */ 
            _In_  DWORD dwStyle,
            /* [annotation][in] */ 
            _In_  LPWSTR szRegister,
            /* [annotation][in] */ 
            _In_  LPVOID pData,
            /* [annotation][out] */ 
            _Out_  IEnumRegisterWordW **pEnum);
        
        HRESULT ( STDMETHODCALLTYPE *EscapeA )( 
            __RPC__in IActiveIMMApp * This,
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  UINT uEscape,
            /* [annotation][out][in] */ 
            _Inout_  LPVOID pData,
            /* [annotation][out] */ 
            _Out_  LRESULT *plResult);
        
        HRESULT ( STDMETHODCALLTYPE *EscapeW )( 
            __RPC__in IActiveIMMApp * This,
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  UINT uEscape,
            /* [annotation][out][in] */ 
            _Inout_  LPVOID pData,
            /* [annotation][out] */ 
            _Out_  LRESULT *plResult);
        
        HRESULT ( STDMETHODCALLTYPE *GetCandidateListA )( 
            __RPC__in IActiveIMMApp * This,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][in] */ 
            _In_  UINT uBufLen,
            /* [annotation][out] */ 
            _Out_  CANDIDATELIST *pCandList,
            /* [annotation][out] */ 
            _Out_  UINT *puCopied);
        
        HRESULT ( STDMETHODCALLTYPE *GetCandidateListW )( 
            __RPC__in IActiveIMMApp * This,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][in] */ 
            _In_  UINT uBufLen,
            /* [annotation][out] */ 
            _Out_  CANDIDATELIST *pCandList,
            /* [annotation][out] */ 
            _Out_  UINT *puCopied);
        
        HRESULT ( STDMETHODCALLTYPE *GetCandidateListCountA )( 
            __RPC__in IActiveIMMApp * This,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwListSize,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwBufLen);
        
        HRESULT ( STDMETHODCALLTYPE *GetCandidateListCountW )( 
            __RPC__in IActiveIMMApp * This,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwListSize,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwBufLen);
        
        HRESULT ( STDMETHODCALLTYPE *GetCandidateWindow )( 
            __RPC__in IActiveIMMApp * This,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][out] */ 
            _Out_  CANDIDATEFORM *pCandidate);
        
        HRESULT ( STDMETHODCALLTYPE *GetCompositionFontA )( 
            __RPC__in IActiveIMMApp * This,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][out] */ 
            _Out_  LOGFONTA *plf);
        
        HRESULT ( STDMETHODCALLTYPE *GetCompositionFontW )( 
            __RPC__in IActiveIMMApp * This,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][out] */ 
            _Out_  LOGFONTW *plf);
        
        HRESULT ( STDMETHODCALLTYPE *GetCompositionStringA )( 
            __RPC__in IActiveIMMApp * This,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][in] */ 
            _In_  DWORD dwBufLen,
            /* [annotation][out] */ 
            _Out_  LONG *plCopied,
            /* [annotation][out] */ 
            _Out_  LPVOID pBuf);
        
        HRESULT ( STDMETHODCALLTYPE *GetCompositionStringW )( 
            __RPC__in IActiveIMMApp * This,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][in] */ 
            _In_  DWORD dwBufLen,
            /* [annotation][out] */ 
            _Out_  LONG *plCopied,
            /* [annotation][out] */ 
            _Out_  LPVOID pBuf);
        
        HRESULT ( STDMETHODCALLTYPE *GetCompositionWindow )( 
            __RPC__in IActiveIMMApp * This,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][out] */ 
            _Out_  COMPOSITIONFORM *pCompForm);
        
        HRESULT ( STDMETHODCALLTYPE *GetContext )( 
            __RPC__in IActiveIMMApp * This,
            /* [annotation][in] */ 
            _In_  HWND hWnd,
            /* [annotation][out] */ 
            _Out_  HIMC *phIMC);
        
        HRESULT ( STDMETHODCALLTYPE *GetConversionListA )( 
            __RPC__in IActiveIMMApp * This,
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  LPSTR pSrc,
            /* [annotation][in] */ 
            _In_  UINT uBufLen,
            /* [annotation][in] */ 
            _In_  UINT uFlag,
            /* [annotation][out] */ 
            _Out_  CANDIDATELIST *pDst,
            /* [annotation][out] */ 
            _Out_  UINT *puCopied);
        
        HRESULT ( STDMETHODCALLTYPE *GetConversionListW )( 
            __RPC__in IActiveIMMApp * This,
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  LPWSTR pSrc,
            /* [annotation][in] */ 
            _In_  UINT uBufLen,
            /* [annotation][in] */ 
            _In_  UINT uFlag,
            /* [annotation][out] */ 
            _Out_  CANDIDATELIST *pDst,
            /* [annotation][out] */ 
            _Out_  UINT *puCopied);
        
        HRESULT ( STDMETHODCALLTYPE *GetConversionStatus )( 
            __RPC__in IActiveIMMApp * This,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][out] */ 
            _Out_  DWORD *pfdwConversion,
            /* [annotation][out] */ 
            _Out_  DWORD *pfdwSentence);
        
        HRESULT ( STDMETHODCALLTYPE *GetDefaultIMEWnd )( 
            __RPC__in IActiveIMMApp * This,
            /* [annotation][in] */ 
            _In_  HWND hWnd,
            /* [annotation][out] */ 
            _Out_  HWND *phDefWnd);
        
        HRESULT ( STDMETHODCALLTYPE *GetDescriptionA )( 
            __RPC__in IActiveIMMApp * This,
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  UINT uBufLen,
            /* [annotation][out] */ 
            _Out_  LPSTR szDescription,
            /* [annotation][out] */ 
            _Out_  UINT *puCopied);
        
        HRESULT ( STDMETHODCALLTYPE *GetDescriptionW )( 
            __RPC__in IActiveIMMApp * This,
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  UINT uBufLen,
            /* [annotation][out] */ 
            _Out_  LPWSTR szDescription,
            /* [annotation][out] */ 
            _Out_  UINT *puCopied);
        
        HRESULT ( STDMETHODCALLTYPE *GetGuideLineA )( 
            __RPC__in IActiveIMMApp * This,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][in] */ 
            _In_  DWORD dwBufLen,
            /* [annotation][out] */ 
            _Out_  LPSTR pBuf,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwResult);
        
        HRESULT ( STDMETHODCALLTYPE *GetGuideLineW )( 
            __RPC__in IActiveIMMApp * This,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][in] */ 
            _In_  DWORD dwBufLen,
            /* [annotation][out] */ 
            _Out_  LPWSTR pBuf,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwResult);
        
        HRESULT ( STDMETHODCALLTYPE *GetIMEFileNameA )( 
            __RPC__in IActiveIMMApp * This,
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  UINT uBufLen,
            /* [annotation][out] */ 
            _Out_  LPSTR szFileName,
            /* [annotation][out] */ 
            _Out_  UINT *puCopied);
        
        HRESULT ( STDMETHODCALLTYPE *GetIMEFileNameW )( 
            __RPC__in IActiveIMMApp * This,
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  UINT uBufLen,
            /* [annotation][out] */ 
            _Out_  LPWSTR szFileName,
            /* [annotation][out] */ 
            _Out_  UINT *puCopied);
        
        HRESULT ( STDMETHODCALLTYPE *GetOpenStatus )( 
            __RPC__in IActiveIMMApp * This,
            /* [annotation][in] */ 
            _In_  HIMC hIMC);
        
        HRESULT ( STDMETHODCALLTYPE *GetProperty )( 
            __RPC__in IActiveIMMApp * This,
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  DWORD fdwIndex,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwProperty);
        
        HRESULT ( STDMETHODCALLTYPE *GetRegisterWordStyleA )( 
            __RPC__in IActiveIMMApp * This,
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  UINT nItem,
            /* [annotation][out] */ 
            _Out_  STYLEBUFA *pStyleBuf,
            /* [annotation][out] */ 
            _Out_  UINT *puCopied);
        
        HRESULT ( STDMETHODCALLTYPE *GetRegisterWordStyleW )( 
            __RPC__in IActiveIMMApp * This,
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  UINT nItem,
            /* [annotation][out] */ 
            _Out_  STYLEBUFW *pStyleBuf,
            /* [annotation][out] */ 
            _Out_  UINT *puCopied);
        
        HRESULT ( STDMETHODCALLTYPE *GetStatusWindowPos )( 
            __RPC__in IActiveIMMApp * This,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][out] */ 
            _Out_  POINT *pptPos);
        
        HRESULT ( STDMETHODCALLTYPE *GetVirtualKey )( 
            __RPC__in IActiveIMMApp * This,
            /* [annotation][in] */ 
            _In_  HWND hWnd,
            /* [annotation][out] */ 
            _Out_  UINT *puVirtualKey);
        
        HRESULT ( STDMETHODCALLTYPE *InstallIMEA )( 
            __RPC__in IActiveIMMApp * This,
            /* [annotation][in] */ 
            _In_  LPSTR szIMEFileName,
            /* [annotation][in] */ 
            _In_  LPSTR szLayoutText,
            /* [annotation][out] */ 
            _Out_  HKL *phKL);
        
        HRESULT ( STDMETHODCALLTYPE *InstallIMEW )( 
            __RPC__in IActiveIMMApp * This,
            /* [annotation][in] */ 
            _In_  LPWSTR szIMEFileName,
            /* [annotation][in] */ 
            _In_  LPWSTR szLayoutText,
            /* [annotation][out] */ 
            _Out_  HKL *phKL);
        
        HRESULT ( STDMETHODCALLTYPE *IsIME )( 
            __RPC__in IActiveIMMApp * This,
            /* [annotation][in] */ 
            _In_  HKL hKL);
        
        HRESULT ( STDMETHODCALLTYPE *IsUIMessageA )( 
            __RPC__in IActiveIMMApp * This,
            /* [annotation][in] */ 
            _In_  HWND hWndIME,
            /* [annotation][in] */ 
            _In_  UINT msg,
            /* [annotation][in] */ 
            _In_  WPARAM wParam,
            /* [annotation][in] */ 
            _In_  LPARAM lParam);
        
        HRESULT ( STDMETHODCALLTYPE *IsUIMessageW )( 
            __RPC__in IActiveIMMApp * This,
            /* [annotation][in] */ 
            _In_  HWND hWndIME,
            /* [annotation][in] */ 
            _In_  UINT msg,
            /* [annotation][in] */ 
            _In_  WPARAM wParam,
            /* [annotation][in] */ 
            _In_  LPARAM lParam);
        
        HRESULT ( STDMETHODCALLTYPE *NotifyIME )( 
            __RPC__in IActiveIMMApp * This,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  DWORD dwAction,
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][in] */ 
            _In_  DWORD dwValue);
        
        HRESULT ( STDMETHODCALLTYPE *RegisterWordA )( 
            __RPC__in IActiveIMMApp * This,
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  LPSTR szReading,
            /* [annotation][in] */ 
            _In_  DWORD dwStyle,
            /* [annotation][in] */ 
            _In_  LPSTR szRegister);
        
        HRESULT ( STDMETHODCALLTYPE *RegisterWordW )( 
            __RPC__in IActiveIMMApp * This,
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  LPWSTR szReading,
            /* [annotation][in] */ 
            _In_  DWORD dwStyle,
            /* [annotation][in] */ 
            _In_  LPWSTR szRegister);
        
        HRESULT ( STDMETHODCALLTYPE *ReleaseContext )( 
            __RPC__in IActiveIMMApp * This,
            /* [annotation][in] */ 
            _In_  HWND hWnd,
            /* [annotation][in] */ 
            _In_  HIMC hIMC);
        
        HRESULT ( STDMETHODCALLTYPE *SetCandidateWindow )( 
            __RPC__in IActiveIMMApp * This,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  CANDIDATEFORM *pCandidate);
        
        HRESULT ( STDMETHODCALLTYPE *SetCompositionFontA )( 
            __RPC__in IActiveIMMApp * This,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  LOGFONTA *plf);
        
        HRESULT ( STDMETHODCALLTYPE *SetCompositionFontW )( 
            __RPC__in IActiveIMMApp * This,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  LOGFONTW *plf);
        
        HRESULT ( STDMETHODCALLTYPE *SetCompositionStringA )( 
            __RPC__in IActiveIMMApp * This,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][in] */ 
            _In_  LPVOID pComp,
            /* [annotation][in] */ 
            _In_  DWORD dwCompLen,
            /* [annotation][in] */ 
            _In_  LPVOID pRead,
            /* [annotation][in] */ 
            _In_  DWORD dwReadLen);
        
        HRESULT ( STDMETHODCALLTYPE *SetCompositionStringW )( 
            __RPC__in IActiveIMMApp * This,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][in] */ 
            _In_  LPVOID pComp,
            /* [annotation][in] */ 
            _In_  DWORD dwCompLen,
            /* [annotation][in] */ 
            _In_  LPVOID pRead,
            /* [annotation][in] */ 
            _In_  DWORD dwReadLen);
        
        HRESULT ( STDMETHODCALLTYPE *SetCompositionWindow )( 
            __RPC__in IActiveIMMApp * This,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  COMPOSITIONFORM *pCompForm);
        
        HRESULT ( STDMETHODCALLTYPE *SetConversionStatus )( 
            __RPC__in IActiveIMMApp * This,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  DWORD fdwConversion,
            /* [annotation][in] */ 
            _In_  DWORD fdwSentence);
        
        HRESULT ( STDMETHODCALLTYPE *SetOpenStatus )( 
            __RPC__in IActiveIMMApp * This,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  BOOL fOpen);
        
        HRESULT ( STDMETHODCALLTYPE *SetStatusWindowPos )( 
            __RPC__in IActiveIMMApp * This,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  POINT *pptPos);
        
        HRESULT ( STDMETHODCALLTYPE *SimulateHotKey )( 
            __RPC__in IActiveIMMApp * This,
            /* [annotation][in] */ 
            _In_  HWND hWnd,
            /* [annotation][in] */ 
            _In_  DWORD dwHotKeyID);
        
        HRESULT ( STDMETHODCALLTYPE *UnregisterWordA )( 
            __RPC__in IActiveIMMApp * This,
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  LPSTR szReading,
            /* [annotation][in] */ 
            _In_  DWORD dwStyle,
            /* [annotation][in] */ 
            _In_  LPSTR szUnregister);
        
        HRESULT ( STDMETHODCALLTYPE *UnregisterWordW )( 
            __RPC__in IActiveIMMApp * This,
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  LPWSTR szReading,
            /* [annotation][in] */ 
            _In_  DWORD dwStyle,
            /* [annotation][in] */ 
            _In_  LPWSTR szUnregister);
        
        HRESULT ( STDMETHODCALLTYPE *Activate )( 
            __RPC__in IActiveIMMApp * This,
            /* [annotation][in] */ 
            _In_  BOOL fRestoreLayout);
        
        HRESULT ( STDMETHODCALLTYPE *Deactivate )( 
            __RPC__in IActiveIMMApp * This);
        
        HRESULT ( STDMETHODCALLTYPE *OnDefWindowProc )( 
            __RPC__in IActiveIMMApp * This,
            /* [annotation][in] */ 
            _In_  HWND hWnd,
            /* [annotation][in] */ 
            _In_  UINT Msg,
            /* [annotation][in] */ 
            _In_  WPARAM wParam,
            /* [annotation][in] */ 
            _In_  LPARAM lParam,
            /* [annotation][out] */ 
            _Out_  LRESULT *plResult);
        
        HRESULT ( STDMETHODCALLTYPE *FilterClientWindows )( 
            __RPC__in IActiveIMMApp * This,
            /* [annotation][in] */ 
            _In_  ATOM *aaClassList,
            /* [annotation][in] */ 
            _In_  UINT uSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetCodePageA )( 
            __RPC__in IActiveIMMApp * This,
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][out] */ 
            _Out_  UINT *uCodePage);
        
        HRESULT ( STDMETHODCALLTYPE *GetLangId )( 
            __RPC__in IActiveIMMApp * This,
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][out] */ 
            _Out_  LANGID *plid);
        
        HRESULT ( STDMETHODCALLTYPE *AssociateContextEx )( 
            __RPC__in IActiveIMMApp * This,
            /* [annotation][in] */ 
            _In_  HWND hWnd,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags);
        
        HRESULT ( STDMETHODCALLTYPE *DisableIME )( 
            __RPC__in IActiveIMMApp * This,
            /* [annotation][in] */ 
            _In_  DWORD idThread);
        
        HRESULT ( STDMETHODCALLTYPE *GetImeMenuItemsA )( 
            __RPC__in IActiveIMMApp * This,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][in] */ 
            _In_  DWORD dwType,
            /* [annotation][in] */ 
            _In_  IMEMENUITEMINFOA *pImeParentMenu,
            /* [annotation][out] */ 
            _Out_  IMEMENUITEMINFOA *pImeMenu,
            /* [annotation][in] */ 
            _In_  DWORD dwSize,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwResult);
        
        HRESULT ( STDMETHODCALLTYPE *GetImeMenuItemsW )( 
            __RPC__in IActiveIMMApp * This,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][in] */ 
            _In_  DWORD dwType,
            /* [annotation][in] */ 
            _In_  IMEMENUITEMINFOW *pImeParentMenu,
            /* [annotation][out] */ 
            _Out_  IMEMENUITEMINFOW *pImeMenu,
            /* [annotation][in] */ 
            _In_  DWORD dwSize,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwResult);
        
        HRESULT ( STDMETHODCALLTYPE *EnumInputContext )( 
            __RPC__in IActiveIMMApp * This,
            /* [annotation][in] */ 
            _In_  DWORD idThread,
            /* [annotation][out] */ 
            _Out_  IEnumInputContext **ppEnum);
        
        END_INTERFACE
    } IActiveIMMAppVtbl;

    interface IActiveIMMApp
    {
        CONST_VTBL struct IActiveIMMAppVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActiveIMMApp_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IActiveIMMApp_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IActiveIMMApp_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IActiveIMMApp_AssociateContext(This,hWnd,hIME,phPrev)	\
    ( (This)->lpVtbl -> AssociateContext(This,hWnd,hIME,phPrev) ) 

#define IActiveIMMApp_ConfigureIMEA(This,hKL,hWnd,dwMode,pData)	\
    ( (This)->lpVtbl -> ConfigureIMEA(This,hKL,hWnd,dwMode,pData) ) 

#define IActiveIMMApp_ConfigureIMEW(This,hKL,hWnd,dwMode,pData)	\
    ( (This)->lpVtbl -> ConfigureIMEW(This,hKL,hWnd,dwMode,pData) ) 

#define IActiveIMMApp_CreateContext(This,phIMC)	\
    ( (This)->lpVtbl -> CreateContext(This,phIMC) ) 

#define IActiveIMMApp_DestroyContext(This,hIME)	\
    ( (This)->lpVtbl -> DestroyContext(This,hIME) ) 

#define IActiveIMMApp_EnumRegisterWordA(This,hKL,szReading,dwStyle,szRegister,pData,pEnum)	\
    ( (This)->lpVtbl -> EnumRegisterWordA(This,hKL,szReading,dwStyle,szRegister,pData,pEnum) ) 

#define IActiveIMMApp_EnumRegisterWordW(This,hKL,szReading,dwStyle,szRegister,pData,pEnum)	\
    ( (This)->lpVtbl -> EnumRegisterWordW(This,hKL,szReading,dwStyle,szRegister,pData,pEnum) ) 

#define IActiveIMMApp_EscapeA(This,hKL,hIMC,uEscape,pData,plResult)	\
    ( (This)->lpVtbl -> EscapeA(This,hKL,hIMC,uEscape,pData,plResult) ) 

#define IActiveIMMApp_EscapeW(This,hKL,hIMC,uEscape,pData,plResult)	\
    ( (This)->lpVtbl -> EscapeW(This,hKL,hIMC,uEscape,pData,plResult) ) 

#define IActiveIMMApp_GetCandidateListA(This,hIMC,dwIndex,uBufLen,pCandList,puCopied)	\
    ( (This)->lpVtbl -> GetCandidateListA(This,hIMC,dwIndex,uBufLen,pCandList,puCopied) ) 

#define IActiveIMMApp_GetCandidateListW(This,hIMC,dwIndex,uBufLen,pCandList,puCopied)	\
    ( (This)->lpVtbl -> GetCandidateListW(This,hIMC,dwIndex,uBufLen,pCandList,puCopied) ) 

#define IActiveIMMApp_GetCandidateListCountA(This,hIMC,pdwListSize,pdwBufLen)	\
    ( (This)->lpVtbl -> GetCandidateListCountA(This,hIMC,pdwListSize,pdwBufLen) ) 

#define IActiveIMMApp_GetCandidateListCountW(This,hIMC,pdwListSize,pdwBufLen)	\
    ( (This)->lpVtbl -> GetCandidateListCountW(This,hIMC,pdwListSize,pdwBufLen) ) 

#define IActiveIMMApp_GetCandidateWindow(This,hIMC,dwIndex,pCandidate)	\
    ( (This)->lpVtbl -> GetCandidateWindow(This,hIMC,dwIndex,pCandidate) ) 

#define IActiveIMMApp_GetCompositionFontA(This,hIMC,plf)	\
    ( (This)->lpVtbl -> GetCompositionFontA(This,hIMC,plf) ) 

#define IActiveIMMApp_GetCompositionFontW(This,hIMC,plf)	\
    ( (This)->lpVtbl -> GetCompositionFontW(This,hIMC,plf) ) 

#define IActiveIMMApp_GetCompositionStringA(This,hIMC,dwIndex,dwBufLen,plCopied,pBuf)	\
    ( (This)->lpVtbl -> GetCompositionStringA(This,hIMC,dwIndex,dwBufLen,plCopied,pBuf) ) 

#define IActiveIMMApp_GetCompositionStringW(This,hIMC,dwIndex,dwBufLen,plCopied,pBuf)	\
    ( (This)->lpVtbl -> GetCompositionStringW(This,hIMC,dwIndex,dwBufLen,plCopied,pBuf) ) 

#define IActiveIMMApp_GetCompositionWindow(This,hIMC,pCompForm)	\
    ( (This)->lpVtbl -> GetCompositionWindow(This,hIMC,pCompForm) ) 

#define IActiveIMMApp_GetContext(This,hWnd,phIMC)	\
    ( (This)->lpVtbl -> GetContext(This,hWnd,phIMC) ) 

#define IActiveIMMApp_GetConversionListA(This,hKL,hIMC,pSrc,uBufLen,uFlag,pDst,puCopied)	\
    ( (This)->lpVtbl -> GetConversionListA(This,hKL,hIMC,pSrc,uBufLen,uFlag,pDst,puCopied) ) 

#define IActiveIMMApp_GetConversionListW(This,hKL,hIMC,pSrc,uBufLen,uFlag,pDst,puCopied)	\
    ( (This)->lpVtbl -> GetConversionListW(This,hKL,hIMC,pSrc,uBufLen,uFlag,pDst,puCopied) ) 

#define IActiveIMMApp_GetConversionStatus(This,hIMC,pfdwConversion,pfdwSentence)	\
    ( (This)->lpVtbl -> GetConversionStatus(This,hIMC,pfdwConversion,pfdwSentence) ) 

#define IActiveIMMApp_GetDefaultIMEWnd(This,hWnd,phDefWnd)	\
    ( (This)->lpVtbl -> GetDefaultIMEWnd(This,hWnd,phDefWnd) ) 

#define IActiveIMMApp_GetDescriptionA(This,hKL,uBufLen,szDescription,puCopied)	\
    ( (This)->lpVtbl -> GetDescriptionA(This,hKL,uBufLen,szDescription,puCopied) ) 

#define IActiveIMMApp_GetDescriptionW(This,hKL,uBufLen,szDescription,puCopied)	\
    ( (This)->lpVtbl -> GetDescriptionW(This,hKL,uBufLen,szDescription,puCopied) ) 

#define IActiveIMMApp_GetGuideLineA(This,hIMC,dwIndex,dwBufLen,pBuf,pdwResult)	\
    ( (This)->lpVtbl -> GetGuideLineA(This,hIMC,dwIndex,dwBufLen,pBuf,pdwResult) ) 

#define IActiveIMMApp_GetGuideLineW(This,hIMC,dwIndex,dwBufLen,pBuf,pdwResult)	\
    ( (This)->lpVtbl -> GetGuideLineW(This,hIMC,dwIndex,dwBufLen,pBuf,pdwResult) ) 

#define IActiveIMMApp_GetIMEFileNameA(This,hKL,uBufLen,szFileName,puCopied)	\
    ( (This)->lpVtbl -> GetIMEFileNameA(This,hKL,uBufLen,szFileName,puCopied) ) 

#define IActiveIMMApp_GetIMEFileNameW(This,hKL,uBufLen,szFileName,puCopied)	\
    ( (This)->lpVtbl -> GetIMEFileNameW(This,hKL,uBufLen,szFileName,puCopied) ) 

#define IActiveIMMApp_GetOpenStatus(This,hIMC)	\
    ( (This)->lpVtbl -> GetOpenStatus(This,hIMC) ) 

#define IActiveIMMApp_GetProperty(This,hKL,fdwIndex,pdwProperty)	\
    ( (This)->lpVtbl -> GetProperty(This,hKL,fdwIndex,pdwProperty) ) 

#define IActiveIMMApp_GetRegisterWordStyleA(This,hKL,nItem,pStyleBuf,puCopied)	\
    ( (This)->lpVtbl -> GetRegisterWordStyleA(This,hKL,nItem,pStyleBuf,puCopied) ) 

#define IActiveIMMApp_GetRegisterWordStyleW(This,hKL,nItem,pStyleBuf,puCopied)	\
    ( (This)->lpVtbl -> GetRegisterWordStyleW(This,hKL,nItem,pStyleBuf,puCopied) ) 

#define IActiveIMMApp_GetStatusWindowPos(This,hIMC,pptPos)	\
    ( (This)->lpVtbl -> GetStatusWindowPos(This,hIMC,pptPos) ) 

#define IActiveIMMApp_GetVirtualKey(This,hWnd,puVirtualKey)	\
    ( (This)->lpVtbl -> GetVirtualKey(This,hWnd,puVirtualKey) ) 

#define IActiveIMMApp_InstallIMEA(This,szIMEFileName,szLayoutText,phKL)	\
    ( (This)->lpVtbl -> InstallIMEA(This,szIMEFileName,szLayoutText,phKL) ) 

#define IActiveIMMApp_InstallIMEW(This,szIMEFileName,szLayoutText,phKL)	\
    ( (This)->lpVtbl -> InstallIMEW(This,szIMEFileName,szLayoutText,phKL) ) 

#define IActiveIMMApp_IsIME(This,hKL)	\
    ( (This)->lpVtbl -> IsIME(This,hKL) ) 

#define IActiveIMMApp_IsUIMessageA(This,hWndIME,msg,wParam,lParam)	\
    ( (This)->lpVtbl -> IsUIMessageA(This,hWndIME,msg,wParam,lParam) ) 

#define IActiveIMMApp_IsUIMessageW(This,hWndIME,msg,wParam,lParam)	\
    ( (This)->lpVtbl -> IsUIMessageW(This,hWndIME,msg,wParam,lParam) ) 

#define IActiveIMMApp_NotifyIME(This,hIMC,dwAction,dwIndex,dwValue)	\
    ( (This)->lpVtbl -> NotifyIME(This,hIMC,dwAction,dwIndex,dwValue) ) 

#define IActiveIMMApp_RegisterWordA(This,hKL,szReading,dwStyle,szRegister)	\
    ( (This)->lpVtbl -> RegisterWordA(This,hKL,szReading,dwStyle,szRegister) ) 

#define IActiveIMMApp_RegisterWordW(This,hKL,szReading,dwStyle,szRegister)	\
    ( (This)->lpVtbl -> RegisterWordW(This,hKL,szReading,dwStyle,szRegister) ) 

#define IActiveIMMApp_ReleaseContext(This,hWnd,hIMC)	\
    ( (This)->lpVtbl -> ReleaseContext(This,hWnd,hIMC) ) 

#define IActiveIMMApp_SetCandidateWindow(This,hIMC,pCandidate)	\
    ( (This)->lpVtbl -> SetCandidateWindow(This,hIMC,pCandidate) ) 

#define IActiveIMMApp_SetCompositionFontA(This,hIMC,plf)	\
    ( (This)->lpVtbl -> SetCompositionFontA(This,hIMC,plf) ) 

#define IActiveIMMApp_SetCompositionFontW(This,hIMC,plf)	\
    ( (This)->lpVtbl -> SetCompositionFontW(This,hIMC,plf) ) 

#define IActiveIMMApp_SetCompositionStringA(This,hIMC,dwIndex,pComp,dwCompLen,pRead,dwReadLen)	\
    ( (This)->lpVtbl -> SetCompositionStringA(This,hIMC,dwIndex,pComp,dwCompLen,pRead,dwReadLen) ) 

#define IActiveIMMApp_SetCompositionStringW(This,hIMC,dwIndex,pComp,dwCompLen,pRead,dwReadLen)	\
    ( (This)->lpVtbl -> SetCompositionStringW(This,hIMC,dwIndex,pComp,dwCompLen,pRead,dwReadLen) ) 

#define IActiveIMMApp_SetCompositionWindow(This,hIMC,pCompForm)	\
    ( (This)->lpVtbl -> SetCompositionWindow(This,hIMC,pCompForm) ) 

#define IActiveIMMApp_SetConversionStatus(This,hIMC,fdwConversion,fdwSentence)	\
    ( (This)->lpVtbl -> SetConversionStatus(This,hIMC,fdwConversion,fdwSentence) ) 

#define IActiveIMMApp_SetOpenStatus(This,hIMC,fOpen)	\
    ( (This)->lpVtbl -> SetOpenStatus(This,hIMC,fOpen) ) 

#define IActiveIMMApp_SetStatusWindowPos(This,hIMC,pptPos)	\
    ( (This)->lpVtbl -> SetStatusWindowPos(This,hIMC,pptPos) ) 

#define IActiveIMMApp_SimulateHotKey(This,hWnd,dwHotKeyID)	\
    ( (This)->lpVtbl -> SimulateHotKey(This,hWnd,dwHotKeyID) ) 

#define IActiveIMMApp_UnregisterWordA(This,hKL,szReading,dwStyle,szUnregister)	\
    ( (This)->lpVtbl -> UnregisterWordA(This,hKL,szReading,dwStyle,szUnregister) ) 

#define IActiveIMMApp_UnregisterWordW(This,hKL,szReading,dwStyle,szUnregister)	\
    ( (This)->lpVtbl -> UnregisterWordW(This,hKL,szReading,dwStyle,szUnregister) ) 

#define IActiveIMMApp_Activate(This,fRestoreLayout)	\
    ( (This)->lpVtbl -> Activate(This,fRestoreLayout) ) 

#define IActiveIMMApp_Deactivate(This)	\
    ( (This)->lpVtbl -> Deactivate(This) ) 

#define IActiveIMMApp_OnDefWindowProc(This,hWnd,Msg,wParam,lParam,plResult)	\
    ( (This)->lpVtbl -> OnDefWindowProc(This,hWnd,Msg,wParam,lParam,plResult) ) 

#define IActiveIMMApp_FilterClientWindows(This,aaClassList,uSize)	\
    ( (This)->lpVtbl -> FilterClientWindows(This,aaClassList,uSize) ) 

#define IActiveIMMApp_GetCodePageA(This,hKL,uCodePage)	\
    ( (This)->lpVtbl -> GetCodePageA(This,hKL,uCodePage) ) 

#define IActiveIMMApp_GetLangId(This,hKL,plid)	\
    ( (This)->lpVtbl -> GetLangId(This,hKL,plid) ) 

#define IActiveIMMApp_AssociateContextEx(This,hWnd,hIMC,dwFlags)	\
    ( (This)->lpVtbl -> AssociateContextEx(This,hWnd,hIMC,dwFlags) ) 

#define IActiveIMMApp_DisableIME(This,idThread)	\
    ( (This)->lpVtbl -> DisableIME(This,idThread) ) 

#define IActiveIMMApp_GetImeMenuItemsA(This,hIMC,dwFlags,dwType,pImeParentMenu,pImeMenu,dwSize,pdwResult)	\
    ( (This)->lpVtbl -> GetImeMenuItemsA(This,hIMC,dwFlags,dwType,pImeParentMenu,pImeMenu,dwSize,pdwResult) ) 

#define IActiveIMMApp_GetImeMenuItemsW(This,hIMC,dwFlags,dwType,pImeParentMenu,pImeMenu,dwSize,pdwResult)	\
    ( (This)->lpVtbl -> GetImeMenuItemsW(This,hIMC,dwFlags,dwType,pImeParentMenu,pImeMenu,dwSize,pdwResult) ) 

#define IActiveIMMApp_EnumInputContext(This,idThread,ppEnum)	\
    ( (This)->lpVtbl -> EnumInputContext(This,idThread,ppEnum) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IActiveIMMApp_INTERFACE_DEFINED__ */


#ifndef __IActiveIMMIME_INTERFACE_DEFINED__
#define __IActiveIMMIME_INTERFACE_DEFINED__

/* interface IActiveIMMIME */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IActiveIMMIME;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("08C03411-F96B-11d0-A475-00AA006BCC59")
    IActiveIMMIME : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AssociateContext( 
            /* [annotation][in] */ 
            _In_  HWND hWnd,
            /* [annotation][in] */ 
            _In_  HIMC hIME,
            /* [annotation][out] */ 
            _Out_  HIMC *phPrev) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ConfigureIMEA( 
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  HWND hWnd,
            /* [annotation][in] */ 
            _In_  DWORD dwMode,
            /* [annotation][in] */ 
            _In_  REGISTERWORDA *pData) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ConfigureIMEW( 
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  HWND hWnd,
            /* [annotation][in] */ 
            _In_  DWORD dwMode,
            /* [annotation][in] */ 
            _In_  REGISTERWORDW *pData) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateContext( 
            /* [annotation][out] */ 
            _Out_  HIMC *phIMC) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DestroyContext( 
            /* [annotation][in] */ 
            _In_  HIMC hIME) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumRegisterWordA( 
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  LPSTR szReading,
            /* [annotation][in] */ 
            _In_  DWORD dwStyle,
            /* [annotation][in] */ 
            _In_  LPSTR szRegister,
            /* [annotation][in] */ 
            _In_  LPVOID pData,
            /* [annotation][out] */ 
            _Out_  IEnumRegisterWordA **pEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumRegisterWordW( 
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  LPWSTR szReading,
            /* [annotation][in] */ 
            _In_  DWORD dwStyle,
            /* [annotation][in] */ 
            _In_  LPWSTR szRegister,
            /* [annotation][in] */ 
            _In_  LPVOID pData,
            /* [annotation][out] */ 
            _Out_  IEnumRegisterWordW **pEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EscapeA( 
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  UINT uEscape,
            /* [annotation][out][in] */ 
            _Inout_  LPVOID pData,
            /* [annotation][out] */ 
            _Out_  LRESULT *plResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EscapeW( 
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  UINT uEscape,
            /* [annotation][out][in] */ 
            _Inout_  LPVOID pData,
            /* [annotation][out] */ 
            _Out_  LRESULT *plResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCandidateListA( 
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][in] */ 
            _In_  UINT uBufLen,
            /* [annotation][out] */ 
            _Out_  CANDIDATELIST *pCandList,
            /* [annotation][out] */ 
            _Out_  UINT *puCopied) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCandidateListW( 
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][in] */ 
            _In_  UINT uBufLen,
            /* [annotation][out] */ 
            _Out_  CANDIDATELIST *pCandList,
            /* [annotation][out] */ 
            _Out_  UINT *puCopied) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCandidateListCountA( 
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwListSize,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwBufLen) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCandidateListCountW( 
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwListSize,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwBufLen) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCandidateWindow( 
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][out] */ 
            _Out_  CANDIDATEFORM *pCandidate) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCompositionFontA( 
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][out] */ 
            _Out_  LOGFONTA *plf) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCompositionFontW( 
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][out] */ 
            _Out_  LOGFONTW *plf) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCompositionStringA( 
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][in] */ 
            _In_  DWORD dwBufLen,
            /* [annotation][out] */ 
            _Out_  LONG *plCopied,
            /* [annotation][out] */ 
            _Out_  LPVOID pBuf) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCompositionStringW( 
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][in] */ 
            _In_  DWORD dwBufLen,
            /* [annotation][out] */ 
            _Out_  LONG *plCopied,
            /* [annotation][out] */ 
            _Out_  LPVOID pBuf) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCompositionWindow( 
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][out] */ 
            _Out_  COMPOSITIONFORM *pCompForm) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetContext( 
            /* [annotation][in] */ 
            _In_  HWND hWnd,
            /* [annotation][out] */ 
            _Out_  HIMC *phIMC) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetConversionListA( 
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  LPSTR pSrc,
            /* [annotation][in] */ 
            _In_  UINT uBufLen,
            /* [annotation][in] */ 
            _In_  UINT uFlag,
            /* [annotation][out] */ 
            _Out_  CANDIDATELIST *pDst,
            /* [annotation][out] */ 
            _Out_  UINT *puCopied) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetConversionListW( 
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  LPWSTR pSrc,
            /* [annotation][in] */ 
            _In_  UINT uBufLen,
            /* [annotation][in] */ 
            _In_  UINT uFlag,
            /* [annotation][out] */ 
            _Out_  CANDIDATELIST *pDst,
            /* [annotation][out] */ 
            _Out_  UINT *puCopied) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetConversionStatus( 
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][out] */ 
            _Out_  DWORD *pfdwConversion,
            /* [annotation][out] */ 
            _Out_  DWORD *pfdwSentence) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDefaultIMEWnd( 
            /* [annotation][in] */ 
            _In_  HWND hWnd,
            /* [annotation][out] */ 
            _Out_  HWND *phDefWnd) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDescriptionA( 
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  UINT uBufLen,
            /* [annotation][out] */ 
            _Out_  LPSTR szDescription,
            /* [annotation][out] */ 
            _Out_  UINT *puCopied) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDescriptionW( 
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  UINT uBufLen,
            /* [annotation][out] */ 
            _Out_  LPWSTR szDescription,
            /* [annotation][out] */ 
            _Out_  UINT *puCopied) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetGuideLineA( 
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][in] */ 
            _In_  DWORD dwBufLen,
            /* [annotation][out] */ 
            _Out_  LPSTR pBuf,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetGuideLineW( 
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][in] */ 
            _In_  DWORD dwBufLen,
            /* [annotation][out] */ 
            _Out_  LPWSTR pBuf,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetIMEFileNameA( 
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  UINT uBufLen,
            /* [annotation][out] */ 
            _Out_  LPSTR szFileName,
            /* [annotation][out] */ 
            _Out_  UINT *puCopied) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetIMEFileNameW( 
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  UINT uBufLen,
            /* [annotation][out] */ 
            _Out_  LPWSTR szFileName,
            /* [annotation][out] */ 
            _Out_  UINT *puCopied) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetOpenStatus( 
            /* [annotation][in] */ 
            _In_  HIMC hIMC) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetProperty( 
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  DWORD fdwIndex,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwProperty) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRegisterWordStyleA( 
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  UINT nItem,
            /* [annotation][out] */ 
            _Out_  STYLEBUFA *pStyleBuf,
            /* [annotation][out] */ 
            _Out_  UINT *puCopied) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRegisterWordStyleW( 
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  UINT nItem,
            /* [annotation][out] */ 
            _Out_  STYLEBUFW *pStyleBuf,
            /* [annotation][out] */ 
            _Out_  UINT *puCopied) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStatusWindowPos( 
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][out] */ 
            _Out_  POINT *pptPos) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetVirtualKey( 
            /* [annotation][in] */ 
            _In_  HWND hWnd,
            /* [annotation][out] */ 
            _Out_  UINT *puVirtualKey) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InstallIMEA( 
            /* [annotation][in] */ 
            _In_  LPSTR szIMEFileName,
            /* [annotation][in] */ 
            _In_  LPSTR szLayoutText,
            /* [annotation][out] */ 
            _Out_  HKL *phKL) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InstallIMEW( 
            /* [annotation][in] */ 
            _In_  LPWSTR szIMEFileName,
            /* [annotation][in] */ 
            _In_  LPWSTR szLayoutText,
            /* [annotation][out] */ 
            _Out_  HKL *phKL) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsIME( 
            /* [annotation][in] */ 
            _In_  HKL hKL) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsUIMessageA( 
            /* [annotation][in] */ 
            _In_  HWND hWndIME,
            /* [annotation][in] */ 
            _In_  UINT msg,
            /* [annotation][in] */ 
            _In_  WPARAM wParam,
            /* [annotation][in] */ 
            _In_  LPARAM lParam) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsUIMessageW( 
            /* [annotation][in] */ 
            _In_  HWND hWndIME,
            /* [annotation][in] */ 
            _In_  UINT msg,
            /* [annotation][in] */ 
            _In_  WPARAM wParam,
            /* [annotation][in] */ 
            _In_  LPARAM lParam) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE NotifyIME( 
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  DWORD dwAction,
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][in] */ 
            _In_  DWORD dwValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RegisterWordA( 
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  LPSTR szReading,
            /* [annotation][in] */ 
            _In_  DWORD dwStyle,
            /* [annotation][in] */ 
            _In_  LPSTR szRegister) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RegisterWordW( 
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  LPWSTR szReading,
            /* [annotation][in] */ 
            _In_  DWORD dwStyle,
            /* [annotation][in] */ 
            _In_  LPWSTR szRegister) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReleaseContext( 
            /* [annotation][in] */ 
            _In_  HWND hWnd,
            /* [annotation][in] */ 
            _In_  HIMC hIMC) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetCandidateWindow( 
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  CANDIDATEFORM *pCandidate) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetCompositionFontA( 
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  LOGFONTA *plf) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetCompositionFontW( 
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  LOGFONTW *plf) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetCompositionStringA( 
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][in] */ 
            _In_  LPVOID pComp,
            /* [annotation][in] */ 
            _In_  DWORD dwCompLen,
            /* [annotation][in] */ 
            _In_  LPVOID pRead,
            /* [annotation][in] */ 
            _In_  DWORD dwReadLen) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetCompositionStringW( 
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][in] */ 
            _In_  LPVOID pComp,
            /* [annotation][in] */ 
            _In_  DWORD dwCompLen,
            /* [annotation][in] */ 
            _In_  LPVOID pRead,
            /* [annotation][in] */ 
            _In_  DWORD dwReadLen) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetCompositionWindow( 
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  COMPOSITIONFORM *pCompForm) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetConversionStatus( 
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  DWORD fdwConversion,
            /* [annotation][in] */ 
            _In_  DWORD fdwSentence) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetOpenStatus( 
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  BOOL fOpen) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetStatusWindowPos( 
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  POINT *pptPos) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SimulateHotKey( 
            /* [annotation][in] */ 
            _In_  HWND hWnd,
            /* [annotation][in] */ 
            _In_  DWORD dwHotKeyID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UnregisterWordA( 
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  LPSTR szReading,
            /* [annotation][in] */ 
            _In_  DWORD dwStyle,
            /* [annotation][in] */ 
            _In_  LPSTR szUnregister) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UnregisterWordW( 
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  LPWSTR szReading,
            /* [annotation][in] */ 
            _In_  DWORD dwStyle,
            /* [annotation][in] */ 
            _In_  LPWSTR szUnregister) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GenerateMessage( 
            /* [annotation][in] */ 
            _In_  HIMC hIMC) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LockIMC( 
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][out] */ 
            _Out_  INPUTCONTEXT **ppIMC) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UnlockIMC( 
            /* [annotation][in] */ 
            _In_  HIMC hIMC) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetIMCLockCount( 
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwLockCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateIMCC( 
            /* [annotation][in] */ 
            _In_  DWORD dwSize,
            /* [annotation][out] */ 
            _Out_  HIMCC *phIMCC) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DestroyIMCC( 
            /* [annotation][in] */ 
            _In_  HIMCC hIMCC) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LockIMCC( 
            /* [annotation][in] */ 
            _In_  HIMCC hIMCC,
            /* [annotation][out] */ 
            _Out_  void **ppv) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UnlockIMCC( 
            /* [annotation][in] */ 
            _In_  HIMCC hIMCC) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReSizeIMCC( 
            /* [annotation][in] */ 
            _In_  HIMCC hIMCC,
            /* [annotation][in] */ 
            _In_  DWORD dwSize,
            /* [annotation][out] */ 
            _Out_  HIMCC *phIMCC) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetIMCCSize( 
            /* [annotation][in] */ 
            _In_  HIMCC hIMCC,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetIMCCLockCount( 
            /* [annotation][in] */ 
            _In_  HIMCC hIMCC,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwLockCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetHotKey( 
            /* [annotation][in] */ 
            _In_  DWORD dwHotKeyID,
            /* [annotation][out] */ 
            _Out_  UINT *puModifiers,
            /* [annotation][out] */ 
            _Out_  UINT *puVKey,
            /* [annotation][out] */ 
            _Out_  HKL *phKL) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetHotKey( 
            /* [annotation][in] */ 
            _In_  DWORD dwHotKeyID,
            /* [annotation][in] */ 
            _In_  UINT uModifiers,
            /* [annotation][in] */ 
            _In_  UINT uVKey,
            /* [annotation][in] */ 
            _In_  HKL hKL) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateSoftKeyboard( 
            /* [annotation][in] */ 
            _In_  UINT uType,
            /* [annotation][in] */ 
            _In_  HWND hOwner,
            /* [annotation][in] */ 
            _In_  int x,
            /* [annotation][in] */ 
            _In_  int y,
            /* [annotation][out] */ 
            _Out_  HWND *phSoftKbdWnd) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DestroySoftKeyboard( 
            /* [annotation][in] */ 
            _In_  HWND hSoftKbdWnd) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ShowSoftKeyboard( 
            /* [annotation][in] */ 
            _In_  HWND hSoftKbdWnd,
            /* [annotation][in] */ 
            _In_  int nCmdShow) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCodePageA( 
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][out] */ 
            _Out_  UINT *uCodePage) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLangId( 
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][out] */ 
            _Out_  LANGID *plid) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE KeybdEvent( 
            /* [annotation][in] */ 
            _In_  LANGID lgidIME,
            /* [annotation][in] */ 
            _In_  BYTE bVk,
            /* [annotation][in] */ 
            _In_  BYTE bScan,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][in] */ 
            _In_  DWORD dwExtraInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LockModal( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UnlockModal( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AssociateContextEx( 
            /* [annotation][in] */ 
            _In_  HWND hWnd,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DisableIME( 
            /* [annotation][in] */ 
            _In_  DWORD idThread) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetImeMenuItemsA( 
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][in] */ 
            _In_  DWORD dwType,
            /* [annotation][in] */ 
            _In_  IMEMENUITEMINFOA *pImeParentMenu,
            /* [annotation][out] */ 
            _Out_  IMEMENUITEMINFOA *pImeMenu,
            /* [annotation][in] */ 
            _In_  DWORD dwSize,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetImeMenuItemsW( 
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][in] */ 
            _In_  DWORD dwType,
            /* [annotation][in] */ 
            _In_  IMEMENUITEMINFOW *pImeParentMenu,
            /* [annotation][out] */ 
            _Out_  IMEMENUITEMINFOW *pImeMenu,
            /* [annotation][in] */ 
            _In_  DWORD dwSize,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumInputContext( 
            /* [annotation][in] */ 
            _In_  DWORD idThread,
            /* [annotation][out] */ 
            _Out_  IEnumInputContext **ppEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RequestMessageA( 
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  WPARAM wParam,
            /* [annotation][in] */ 
            _In_  LPARAM lParam,
            /* [annotation][out] */ 
            _Out_  LRESULT *plResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RequestMessageW( 
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  WPARAM wParam,
            /* [annotation][in] */ 
            _In_  LPARAM lParam,
            /* [annotation][out] */ 
            _Out_  LRESULT *plResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SendIMCA( 
            /* [annotation][in] */ 
            _In_  HWND hWnd,
            /* [annotation][in] */ 
            _In_  UINT uMsg,
            /* [annotation][in] */ 
            _In_  WPARAM wParam,
            /* [annotation][in] */ 
            _In_  LPARAM lParam,
            /* [annotation][out] */ 
            _Out_  LRESULT *plResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SendIMCW( 
            /* [annotation][in] */ 
            _In_  HWND hWnd,
            /* [annotation][in] */ 
            _In_  UINT uMsg,
            /* [annotation][in] */ 
            _In_  WPARAM wParam,
            /* [annotation][in] */ 
            _In_  LPARAM lParam,
            /* [annotation][out] */ 
            _Out_  LRESULT *plResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsSleeping( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IActiveIMMIMEVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IActiveIMMIME * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IActiveIMMIME * This);
        
        HRESULT ( STDMETHODCALLTYPE *AssociateContext )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  HWND hWnd,
            /* [annotation][in] */ 
            _In_  HIMC hIME,
            /* [annotation][out] */ 
            _Out_  HIMC *phPrev);
        
        HRESULT ( STDMETHODCALLTYPE *ConfigureIMEA )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  HWND hWnd,
            /* [annotation][in] */ 
            _In_  DWORD dwMode,
            /* [annotation][in] */ 
            _In_  REGISTERWORDA *pData);
        
        HRESULT ( STDMETHODCALLTYPE *ConfigureIMEW )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  HWND hWnd,
            /* [annotation][in] */ 
            _In_  DWORD dwMode,
            /* [annotation][in] */ 
            _In_  REGISTERWORDW *pData);
        
        HRESULT ( STDMETHODCALLTYPE *CreateContext )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][out] */ 
            _Out_  HIMC *phIMC);
        
        HRESULT ( STDMETHODCALLTYPE *DestroyContext )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  HIMC hIME);
        
        HRESULT ( STDMETHODCALLTYPE *EnumRegisterWordA )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  LPSTR szReading,
            /* [annotation][in] */ 
            _In_  DWORD dwStyle,
            /* [annotation][in] */ 
            _In_  LPSTR szRegister,
            /* [annotation][in] */ 
            _In_  LPVOID pData,
            /* [annotation][out] */ 
            _Out_  IEnumRegisterWordA **pEnum);
        
        HRESULT ( STDMETHODCALLTYPE *EnumRegisterWordW )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  LPWSTR szReading,
            /* [annotation][in] */ 
            _In_  DWORD dwStyle,
            /* [annotation][in] */ 
            _In_  LPWSTR szRegister,
            /* [annotation][in] */ 
            _In_  LPVOID pData,
            /* [annotation][out] */ 
            _Out_  IEnumRegisterWordW **pEnum);
        
        HRESULT ( STDMETHODCALLTYPE *EscapeA )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  UINT uEscape,
            /* [annotation][out][in] */ 
            _Inout_  LPVOID pData,
            /* [annotation][out] */ 
            _Out_  LRESULT *plResult);
        
        HRESULT ( STDMETHODCALLTYPE *EscapeW )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  UINT uEscape,
            /* [annotation][out][in] */ 
            _Inout_  LPVOID pData,
            /* [annotation][out] */ 
            _Out_  LRESULT *plResult);
        
        HRESULT ( STDMETHODCALLTYPE *GetCandidateListA )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][in] */ 
            _In_  UINT uBufLen,
            /* [annotation][out] */ 
            _Out_  CANDIDATELIST *pCandList,
            /* [annotation][out] */ 
            _Out_  UINT *puCopied);
        
        HRESULT ( STDMETHODCALLTYPE *GetCandidateListW )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][in] */ 
            _In_  UINT uBufLen,
            /* [annotation][out] */ 
            _Out_  CANDIDATELIST *pCandList,
            /* [annotation][out] */ 
            _Out_  UINT *puCopied);
        
        HRESULT ( STDMETHODCALLTYPE *GetCandidateListCountA )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwListSize,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwBufLen);
        
        HRESULT ( STDMETHODCALLTYPE *GetCandidateListCountW )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwListSize,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwBufLen);
        
        HRESULT ( STDMETHODCALLTYPE *GetCandidateWindow )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][out] */ 
            _Out_  CANDIDATEFORM *pCandidate);
        
        HRESULT ( STDMETHODCALLTYPE *GetCompositionFontA )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][out] */ 
            _Out_  LOGFONTA *plf);
        
        HRESULT ( STDMETHODCALLTYPE *GetCompositionFontW )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][out] */ 
            _Out_  LOGFONTW *plf);
        
        HRESULT ( STDMETHODCALLTYPE *GetCompositionStringA )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][in] */ 
            _In_  DWORD dwBufLen,
            /* [annotation][out] */ 
            _Out_  LONG *plCopied,
            /* [annotation][out] */ 
            _Out_  LPVOID pBuf);
        
        HRESULT ( STDMETHODCALLTYPE *GetCompositionStringW )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][in] */ 
            _In_  DWORD dwBufLen,
            /* [annotation][out] */ 
            _Out_  LONG *plCopied,
            /* [annotation][out] */ 
            _Out_  LPVOID pBuf);
        
        HRESULT ( STDMETHODCALLTYPE *GetCompositionWindow )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][out] */ 
            _Out_  COMPOSITIONFORM *pCompForm);
        
        HRESULT ( STDMETHODCALLTYPE *GetContext )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  HWND hWnd,
            /* [annotation][out] */ 
            _Out_  HIMC *phIMC);
        
        HRESULT ( STDMETHODCALLTYPE *GetConversionListA )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  LPSTR pSrc,
            /* [annotation][in] */ 
            _In_  UINT uBufLen,
            /* [annotation][in] */ 
            _In_  UINT uFlag,
            /* [annotation][out] */ 
            _Out_  CANDIDATELIST *pDst,
            /* [annotation][out] */ 
            _Out_  UINT *puCopied);
        
        HRESULT ( STDMETHODCALLTYPE *GetConversionListW )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  LPWSTR pSrc,
            /* [annotation][in] */ 
            _In_  UINT uBufLen,
            /* [annotation][in] */ 
            _In_  UINT uFlag,
            /* [annotation][out] */ 
            _Out_  CANDIDATELIST *pDst,
            /* [annotation][out] */ 
            _Out_  UINT *puCopied);
        
        HRESULT ( STDMETHODCALLTYPE *GetConversionStatus )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][out] */ 
            _Out_  DWORD *pfdwConversion,
            /* [annotation][out] */ 
            _Out_  DWORD *pfdwSentence);
        
        HRESULT ( STDMETHODCALLTYPE *GetDefaultIMEWnd )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  HWND hWnd,
            /* [annotation][out] */ 
            _Out_  HWND *phDefWnd);
        
        HRESULT ( STDMETHODCALLTYPE *GetDescriptionA )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  UINT uBufLen,
            /* [annotation][out] */ 
            _Out_  LPSTR szDescription,
            /* [annotation][out] */ 
            _Out_  UINT *puCopied);
        
        HRESULT ( STDMETHODCALLTYPE *GetDescriptionW )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  UINT uBufLen,
            /* [annotation][out] */ 
            _Out_  LPWSTR szDescription,
            /* [annotation][out] */ 
            _Out_  UINT *puCopied);
        
        HRESULT ( STDMETHODCALLTYPE *GetGuideLineA )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][in] */ 
            _In_  DWORD dwBufLen,
            /* [annotation][out] */ 
            _Out_  LPSTR pBuf,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwResult);
        
        HRESULT ( STDMETHODCALLTYPE *GetGuideLineW )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][in] */ 
            _In_  DWORD dwBufLen,
            /* [annotation][out] */ 
            _Out_  LPWSTR pBuf,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwResult);
        
        HRESULT ( STDMETHODCALLTYPE *GetIMEFileNameA )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  UINT uBufLen,
            /* [annotation][out] */ 
            _Out_  LPSTR szFileName,
            /* [annotation][out] */ 
            _Out_  UINT *puCopied);
        
        HRESULT ( STDMETHODCALLTYPE *GetIMEFileNameW )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  UINT uBufLen,
            /* [annotation][out] */ 
            _Out_  LPWSTR szFileName,
            /* [annotation][out] */ 
            _Out_  UINT *puCopied);
        
        HRESULT ( STDMETHODCALLTYPE *GetOpenStatus )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  HIMC hIMC);
        
        HRESULT ( STDMETHODCALLTYPE *GetProperty )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  DWORD fdwIndex,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwProperty);
        
        HRESULT ( STDMETHODCALLTYPE *GetRegisterWordStyleA )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  UINT nItem,
            /* [annotation][out] */ 
            _Out_  STYLEBUFA *pStyleBuf,
            /* [annotation][out] */ 
            _Out_  UINT *puCopied);
        
        HRESULT ( STDMETHODCALLTYPE *GetRegisterWordStyleW )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  UINT nItem,
            /* [annotation][out] */ 
            _Out_  STYLEBUFW *pStyleBuf,
            /* [annotation][out] */ 
            _Out_  UINT *puCopied);
        
        HRESULT ( STDMETHODCALLTYPE *GetStatusWindowPos )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][out] */ 
            _Out_  POINT *pptPos);
        
        HRESULT ( STDMETHODCALLTYPE *GetVirtualKey )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  HWND hWnd,
            /* [annotation][out] */ 
            _Out_  UINT *puVirtualKey);
        
        HRESULT ( STDMETHODCALLTYPE *InstallIMEA )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  LPSTR szIMEFileName,
            /* [annotation][in] */ 
            _In_  LPSTR szLayoutText,
            /* [annotation][out] */ 
            _Out_  HKL *phKL);
        
        HRESULT ( STDMETHODCALLTYPE *InstallIMEW )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  LPWSTR szIMEFileName,
            /* [annotation][in] */ 
            _In_  LPWSTR szLayoutText,
            /* [annotation][out] */ 
            _Out_  HKL *phKL);
        
        HRESULT ( STDMETHODCALLTYPE *IsIME )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  HKL hKL);
        
        HRESULT ( STDMETHODCALLTYPE *IsUIMessageA )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  HWND hWndIME,
            /* [annotation][in] */ 
            _In_  UINT msg,
            /* [annotation][in] */ 
            _In_  WPARAM wParam,
            /* [annotation][in] */ 
            _In_  LPARAM lParam);
        
        HRESULT ( STDMETHODCALLTYPE *IsUIMessageW )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  HWND hWndIME,
            /* [annotation][in] */ 
            _In_  UINT msg,
            /* [annotation][in] */ 
            _In_  WPARAM wParam,
            /* [annotation][in] */ 
            _In_  LPARAM lParam);
        
        HRESULT ( STDMETHODCALLTYPE *NotifyIME )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  DWORD dwAction,
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][in] */ 
            _In_  DWORD dwValue);
        
        HRESULT ( STDMETHODCALLTYPE *RegisterWordA )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  LPSTR szReading,
            /* [annotation][in] */ 
            _In_  DWORD dwStyle,
            /* [annotation][in] */ 
            _In_  LPSTR szRegister);
        
        HRESULT ( STDMETHODCALLTYPE *RegisterWordW )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  LPWSTR szReading,
            /* [annotation][in] */ 
            _In_  DWORD dwStyle,
            /* [annotation][in] */ 
            _In_  LPWSTR szRegister);
        
        HRESULT ( STDMETHODCALLTYPE *ReleaseContext )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  HWND hWnd,
            /* [annotation][in] */ 
            _In_  HIMC hIMC);
        
        HRESULT ( STDMETHODCALLTYPE *SetCandidateWindow )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  CANDIDATEFORM *pCandidate);
        
        HRESULT ( STDMETHODCALLTYPE *SetCompositionFontA )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  LOGFONTA *plf);
        
        HRESULT ( STDMETHODCALLTYPE *SetCompositionFontW )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  LOGFONTW *plf);
        
        HRESULT ( STDMETHODCALLTYPE *SetCompositionStringA )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][in] */ 
            _In_  LPVOID pComp,
            /* [annotation][in] */ 
            _In_  DWORD dwCompLen,
            /* [annotation][in] */ 
            _In_  LPVOID pRead,
            /* [annotation][in] */ 
            _In_  DWORD dwReadLen);
        
        HRESULT ( STDMETHODCALLTYPE *SetCompositionStringW )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][in] */ 
            _In_  LPVOID pComp,
            /* [annotation][in] */ 
            _In_  DWORD dwCompLen,
            /* [annotation][in] */ 
            _In_  LPVOID pRead,
            /* [annotation][in] */ 
            _In_  DWORD dwReadLen);
        
        HRESULT ( STDMETHODCALLTYPE *SetCompositionWindow )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  COMPOSITIONFORM *pCompForm);
        
        HRESULT ( STDMETHODCALLTYPE *SetConversionStatus )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  DWORD fdwConversion,
            /* [annotation][in] */ 
            _In_  DWORD fdwSentence);
        
        HRESULT ( STDMETHODCALLTYPE *SetOpenStatus )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  BOOL fOpen);
        
        HRESULT ( STDMETHODCALLTYPE *SetStatusWindowPos )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  POINT *pptPos);
        
        HRESULT ( STDMETHODCALLTYPE *SimulateHotKey )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  HWND hWnd,
            /* [annotation][in] */ 
            _In_  DWORD dwHotKeyID);
        
        HRESULT ( STDMETHODCALLTYPE *UnregisterWordA )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  LPSTR szReading,
            /* [annotation][in] */ 
            _In_  DWORD dwStyle,
            /* [annotation][in] */ 
            _In_  LPSTR szUnregister);
        
        HRESULT ( STDMETHODCALLTYPE *UnregisterWordW )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  LPWSTR szReading,
            /* [annotation][in] */ 
            _In_  DWORD dwStyle,
            /* [annotation][in] */ 
            _In_  LPWSTR szUnregister);
        
        HRESULT ( STDMETHODCALLTYPE *GenerateMessage )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  HIMC hIMC);
        
        HRESULT ( STDMETHODCALLTYPE *LockIMC )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][out] */ 
            _Out_  INPUTCONTEXT **ppIMC);
        
        HRESULT ( STDMETHODCALLTYPE *UnlockIMC )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  HIMC hIMC);
        
        HRESULT ( STDMETHODCALLTYPE *GetIMCLockCount )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwLockCount);
        
        HRESULT ( STDMETHODCALLTYPE *CreateIMCC )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  DWORD dwSize,
            /* [annotation][out] */ 
            _Out_  HIMCC *phIMCC);
        
        HRESULT ( STDMETHODCALLTYPE *DestroyIMCC )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  HIMCC hIMCC);
        
        HRESULT ( STDMETHODCALLTYPE *LockIMCC )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  HIMCC hIMCC,
            /* [annotation][out] */ 
            _Out_  void **ppv);
        
        HRESULT ( STDMETHODCALLTYPE *UnlockIMCC )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  HIMCC hIMCC);
        
        HRESULT ( STDMETHODCALLTYPE *ReSizeIMCC )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  HIMCC hIMCC,
            /* [annotation][in] */ 
            _In_  DWORD dwSize,
            /* [annotation][out] */ 
            _Out_  HIMCC *phIMCC);
        
        HRESULT ( STDMETHODCALLTYPE *GetIMCCSize )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  HIMCC hIMCC,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetIMCCLockCount )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  HIMCC hIMCC,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwLockCount);
        
        HRESULT ( STDMETHODCALLTYPE *GetHotKey )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  DWORD dwHotKeyID,
            /* [annotation][out] */ 
            _Out_  UINT *puModifiers,
            /* [annotation][out] */ 
            _Out_  UINT *puVKey,
            /* [annotation][out] */ 
            _Out_  HKL *phKL);
        
        HRESULT ( STDMETHODCALLTYPE *SetHotKey )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  DWORD dwHotKeyID,
            /* [annotation][in] */ 
            _In_  UINT uModifiers,
            /* [annotation][in] */ 
            _In_  UINT uVKey,
            /* [annotation][in] */ 
            _In_  HKL hKL);
        
        HRESULT ( STDMETHODCALLTYPE *CreateSoftKeyboard )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  UINT uType,
            /* [annotation][in] */ 
            _In_  HWND hOwner,
            /* [annotation][in] */ 
            _In_  int x,
            /* [annotation][in] */ 
            _In_  int y,
            /* [annotation][out] */ 
            _Out_  HWND *phSoftKbdWnd);
        
        HRESULT ( STDMETHODCALLTYPE *DestroySoftKeyboard )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  HWND hSoftKbdWnd);
        
        HRESULT ( STDMETHODCALLTYPE *ShowSoftKeyboard )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  HWND hSoftKbdWnd,
            /* [annotation][in] */ 
            _In_  int nCmdShow);
        
        HRESULT ( STDMETHODCALLTYPE *GetCodePageA )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][out] */ 
            _Out_  UINT *uCodePage);
        
        HRESULT ( STDMETHODCALLTYPE *GetLangId )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][out] */ 
            _Out_  LANGID *plid);
        
        HRESULT ( STDMETHODCALLTYPE *KeybdEvent )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  LANGID lgidIME,
            /* [annotation][in] */ 
            _In_  BYTE bVk,
            /* [annotation][in] */ 
            _In_  BYTE bScan,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][in] */ 
            _In_  DWORD dwExtraInfo);
        
        HRESULT ( STDMETHODCALLTYPE *LockModal )( 
            __RPC__in IActiveIMMIME * This);
        
        HRESULT ( STDMETHODCALLTYPE *UnlockModal )( 
            __RPC__in IActiveIMMIME * This);
        
        HRESULT ( STDMETHODCALLTYPE *AssociateContextEx )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  HWND hWnd,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags);
        
        HRESULT ( STDMETHODCALLTYPE *DisableIME )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  DWORD idThread);
        
        HRESULT ( STDMETHODCALLTYPE *GetImeMenuItemsA )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][in] */ 
            _In_  DWORD dwType,
            /* [annotation][in] */ 
            _In_  IMEMENUITEMINFOA *pImeParentMenu,
            /* [annotation][out] */ 
            _Out_  IMEMENUITEMINFOA *pImeMenu,
            /* [annotation][in] */ 
            _In_  DWORD dwSize,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwResult);
        
        HRESULT ( STDMETHODCALLTYPE *GetImeMenuItemsW )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][in] */ 
            _In_  DWORD dwType,
            /* [annotation][in] */ 
            _In_  IMEMENUITEMINFOW *pImeParentMenu,
            /* [annotation][out] */ 
            _Out_  IMEMENUITEMINFOW *pImeMenu,
            /* [annotation][in] */ 
            _In_  DWORD dwSize,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwResult);
        
        HRESULT ( STDMETHODCALLTYPE *EnumInputContext )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  DWORD idThread,
            /* [annotation][out] */ 
            _Out_  IEnumInputContext **ppEnum);
        
        HRESULT ( STDMETHODCALLTYPE *RequestMessageA )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  WPARAM wParam,
            /* [annotation][in] */ 
            _In_  LPARAM lParam,
            /* [annotation][out] */ 
            _Out_  LRESULT *plResult);
        
        HRESULT ( STDMETHODCALLTYPE *RequestMessageW )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  WPARAM wParam,
            /* [annotation][in] */ 
            _In_  LPARAM lParam,
            /* [annotation][out] */ 
            _Out_  LRESULT *plResult);
        
        HRESULT ( STDMETHODCALLTYPE *SendIMCA )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  HWND hWnd,
            /* [annotation][in] */ 
            _In_  UINT uMsg,
            /* [annotation][in] */ 
            _In_  WPARAM wParam,
            /* [annotation][in] */ 
            _In_  LPARAM lParam,
            /* [annotation][out] */ 
            _Out_  LRESULT *plResult);
        
        HRESULT ( STDMETHODCALLTYPE *SendIMCW )( 
            __RPC__in IActiveIMMIME * This,
            /* [annotation][in] */ 
            _In_  HWND hWnd,
            /* [annotation][in] */ 
            _In_  UINT uMsg,
            /* [annotation][in] */ 
            _In_  WPARAM wParam,
            /* [annotation][in] */ 
            _In_  LPARAM lParam,
            /* [annotation][out] */ 
            _Out_  LRESULT *plResult);
        
        HRESULT ( STDMETHODCALLTYPE *IsSleeping )( 
            __RPC__in IActiveIMMIME * This);
        
        END_INTERFACE
    } IActiveIMMIMEVtbl;

    interface IActiveIMMIME
    {
        CONST_VTBL struct IActiveIMMIMEVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActiveIMMIME_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IActiveIMMIME_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IActiveIMMIME_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IActiveIMMIME_AssociateContext(This,hWnd,hIME,phPrev)	\
    ( (This)->lpVtbl -> AssociateContext(This,hWnd,hIME,phPrev) ) 

#define IActiveIMMIME_ConfigureIMEA(This,hKL,hWnd,dwMode,pData)	\
    ( (This)->lpVtbl -> ConfigureIMEA(This,hKL,hWnd,dwMode,pData) ) 

#define IActiveIMMIME_ConfigureIMEW(This,hKL,hWnd,dwMode,pData)	\
    ( (This)->lpVtbl -> ConfigureIMEW(This,hKL,hWnd,dwMode,pData) ) 

#define IActiveIMMIME_CreateContext(This,phIMC)	\
    ( (This)->lpVtbl -> CreateContext(This,phIMC) ) 

#define IActiveIMMIME_DestroyContext(This,hIME)	\
    ( (This)->lpVtbl -> DestroyContext(This,hIME) ) 

#define IActiveIMMIME_EnumRegisterWordA(This,hKL,szReading,dwStyle,szRegister,pData,pEnum)	\
    ( (This)->lpVtbl -> EnumRegisterWordA(This,hKL,szReading,dwStyle,szRegister,pData,pEnum) ) 

#define IActiveIMMIME_EnumRegisterWordW(This,hKL,szReading,dwStyle,szRegister,pData,pEnum)	\
    ( (This)->lpVtbl -> EnumRegisterWordW(This,hKL,szReading,dwStyle,szRegister,pData,pEnum) ) 

#define IActiveIMMIME_EscapeA(This,hKL,hIMC,uEscape,pData,plResult)	\
    ( (This)->lpVtbl -> EscapeA(This,hKL,hIMC,uEscape,pData,plResult) ) 

#define IActiveIMMIME_EscapeW(This,hKL,hIMC,uEscape,pData,plResult)	\
    ( (This)->lpVtbl -> EscapeW(This,hKL,hIMC,uEscape,pData,plResult) ) 

#define IActiveIMMIME_GetCandidateListA(This,hIMC,dwIndex,uBufLen,pCandList,puCopied)	\
    ( (This)->lpVtbl -> GetCandidateListA(This,hIMC,dwIndex,uBufLen,pCandList,puCopied) ) 

#define IActiveIMMIME_GetCandidateListW(This,hIMC,dwIndex,uBufLen,pCandList,puCopied)	\
    ( (This)->lpVtbl -> GetCandidateListW(This,hIMC,dwIndex,uBufLen,pCandList,puCopied) ) 

#define IActiveIMMIME_GetCandidateListCountA(This,hIMC,pdwListSize,pdwBufLen)	\
    ( (This)->lpVtbl -> GetCandidateListCountA(This,hIMC,pdwListSize,pdwBufLen) ) 

#define IActiveIMMIME_GetCandidateListCountW(This,hIMC,pdwListSize,pdwBufLen)	\
    ( (This)->lpVtbl -> GetCandidateListCountW(This,hIMC,pdwListSize,pdwBufLen) ) 

#define IActiveIMMIME_GetCandidateWindow(This,hIMC,dwIndex,pCandidate)	\
    ( (This)->lpVtbl -> GetCandidateWindow(This,hIMC,dwIndex,pCandidate) ) 

#define IActiveIMMIME_GetCompositionFontA(This,hIMC,plf)	\
    ( (This)->lpVtbl -> GetCompositionFontA(This,hIMC,plf) ) 

#define IActiveIMMIME_GetCompositionFontW(This,hIMC,plf)	\
    ( (This)->lpVtbl -> GetCompositionFontW(This,hIMC,plf) ) 

#define IActiveIMMIME_GetCompositionStringA(This,hIMC,dwIndex,dwBufLen,plCopied,pBuf)	\
    ( (This)->lpVtbl -> GetCompositionStringA(This,hIMC,dwIndex,dwBufLen,plCopied,pBuf) ) 

#define IActiveIMMIME_GetCompositionStringW(This,hIMC,dwIndex,dwBufLen,plCopied,pBuf)	\
    ( (This)->lpVtbl -> GetCompositionStringW(This,hIMC,dwIndex,dwBufLen,plCopied,pBuf) ) 

#define IActiveIMMIME_GetCompositionWindow(This,hIMC,pCompForm)	\
    ( (This)->lpVtbl -> GetCompositionWindow(This,hIMC,pCompForm) ) 

#define IActiveIMMIME_GetContext(This,hWnd,phIMC)	\
    ( (This)->lpVtbl -> GetContext(This,hWnd,phIMC) ) 

#define IActiveIMMIME_GetConversionListA(This,hKL,hIMC,pSrc,uBufLen,uFlag,pDst,puCopied)	\
    ( (This)->lpVtbl -> GetConversionListA(This,hKL,hIMC,pSrc,uBufLen,uFlag,pDst,puCopied) ) 

#define IActiveIMMIME_GetConversionListW(This,hKL,hIMC,pSrc,uBufLen,uFlag,pDst,puCopied)	\
    ( (This)->lpVtbl -> GetConversionListW(This,hKL,hIMC,pSrc,uBufLen,uFlag,pDst,puCopied) ) 

#define IActiveIMMIME_GetConversionStatus(This,hIMC,pfdwConversion,pfdwSentence)	\
    ( (This)->lpVtbl -> GetConversionStatus(This,hIMC,pfdwConversion,pfdwSentence) ) 

#define IActiveIMMIME_GetDefaultIMEWnd(This,hWnd,phDefWnd)	\
    ( (This)->lpVtbl -> GetDefaultIMEWnd(This,hWnd,phDefWnd) ) 

#define IActiveIMMIME_GetDescriptionA(This,hKL,uBufLen,szDescription,puCopied)	\
    ( (This)->lpVtbl -> GetDescriptionA(This,hKL,uBufLen,szDescription,puCopied) ) 

#define IActiveIMMIME_GetDescriptionW(This,hKL,uBufLen,szDescription,puCopied)	\
    ( (This)->lpVtbl -> GetDescriptionW(This,hKL,uBufLen,szDescription,puCopied) ) 

#define IActiveIMMIME_GetGuideLineA(This,hIMC,dwIndex,dwBufLen,pBuf,pdwResult)	\
    ( (This)->lpVtbl -> GetGuideLineA(This,hIMC,dwIndex,dwBufLen,pBuf,pdwResult) ) 

#define IActiveIMMIME_GetGuideLineW(This,hIMC,dwIndex,dwBufLen,pBuf,pdwResult)	\
    ( (This)->lpVtbl -> GetGuideLineW(This,hIMC,dwIndex,dwBufLen,pBuf,pdwResult) ) 

#define IActiveIMMIME_GetIMEFileNameA(This,hKL,uBufLen,szFileName,puCopied)	\
    ( (This)->lpVtbl -> GetIMEFileNameA(This,hKL,uBufLen,szFileName,puCopied) ) 

#define IActiveIMMIME_GetIMEFileNameW(This,hKL,uBufLen,szFileName,puCopied)	\
    ( (This)->lpVtbl -> GetIMEFileNameW(This,hKL,uBufLen,szFileName,puCopied) ) 

#define IActiveIMMIME_GetOpenStatus(This,hIMC)	\
    ( (This)->lpVtbl -> GetOpenStatus(This,hIMC) ) 

#define IActiveIMMIME_GetProperty(This,hKL,fdwIndex,pdwProperty)	\
    ( (This)->lpVtbl -> GetProperty(This,hKL,fdwIndex,pdwProperty) ) 

#define IActiveIMMIME_GetRegisterWordStyleA(This,hKL,nItem,pStyleBuf,puCopied)	\
    ( (This)->lpVtbl -> GetRegisterWordStyleA(This,hKL,nItem,pStyleBuf,puCopied) ) 

#define IActiveIMMIME_GetRegisterWordStyleW(This,hKL,nItem,pStyleBuf,puCopied)	\
    ( (This)->lpVtbl -> GetRegisterWordStyleW(This,hKL,nItem,pStyleBuf,puCopied) ) 

#define IActiveIMMIME_GetStatusWindowPos(This,hIMC,pptPos)	\
    ( (This)->lpVtbl -> GetStatusWindowPos(This,hIMC,pptPos) ) 

#define IActiveIMMIME_GetVirtualKey(This,hWnd,puVirtualKey)	\
    ( (This)->lpVtbl -> GetVirtualKey(This,hWnd,puVirtualKey) ) 

#define IActiveIMMIME_InstallIMEA(This,szIMEFileName,szLayoutText,phKL)	\
    ( (This)->lpVtbl -> InstallIMEA(This,szIMEFileName,szLayoutText,phKL) ) 

#define IActiveIMMIME_InstallIMEW(This,szIMEFileName,szLayoutText,phKL)	\
    ( (This)->lpVtbl -> InstallIMEW(This,szIMEFileName,szLayoutText,phKL) ) 

#define IActiveIMMIME_IsIME(This,hKL)	\
    ( (This)->lpVtbl -> IsIME(This,hKL) ) 

#define IActiveIMMIME_IsUIMessageA(This,hWndIME,msg,wParam,lParam)	\
    ( (This)->lpVtbl -> IsUIMessageA(This,hWndIME,msg,wParam,lParam) ) 

#define IActiveIMMIME_IsUIMessageW(This,hWndIME,msg,wParam,lParam)	\
    ( (This)->lpVtbl -> IsUIMessageW(This,hWndIME,msg,wParam,lParam) ) 

#define IActiveIMMIME_NotifyIME(This,hIMC,dwAction,dwIndex,dwValue)	\
    ( (This)->lpVtbl -> NotifyIME(This,hIMC,dwAction,dwIndex,dwValue) ) 

#define IActiveIMMIME_RegisterWordA(This,hKL,szReading,dwStyle,szRegister)	\
    ( (This)->lpVtbl -> RegisterWordA(This,hKL,szReading,dwStyle,szRegister) ) 

#define IActiveIMMIME_RegisterWordW(This,hKL,szReading,dwStyle,szRegister)	\
    ( (This)->lpVtbl -> RegisterWordW(This,hKL,szReading,dwStyle,szRegister) ) 

#define IActiveIMMIME_ReleaseContext(This,hWnd,hIMC)	\
    ( (This)->lpVtbl -> ReleaseContext(This,hWnd,hIMC) ) 

#define IActiveIMMIME_SetCandidateWindow(This,hIMC,pCandidate)	\
    ( (This)->lpVtbl -> SetCandidateWindow(This,hIMC,pCandidate) ) 

#define IActiveIMMIME_SetCompositionFontA(This,hIMC,plf)	\
    ( (This)->lpVtbl -> SetCompositionFontA(This,hIMC,plf) ) 

#define IActiveIMMIME_SetCompositionFontW(This,hIMC,plf)	\
    ( (This)->lpVtbl -> SetCompositionFontW(This,hIMC,plf) ) 

#define IActiveIMMIME_SetCompositionStringA(This,hIMC,dwIndex,pComp,dwCompLen,pRead,dwReadLen)	\
    ( (This)->lpVtbl -> SetCompositionStringA(This,hIMC,dwIndex,pComp,dwCompLen,pRead,dwReadLen) ) 

#define IActiveIMMIME_SetCompositionStringW(This,hIMC,dwIndex,pComp,dwCompLen,pRead,dwReadLen)	\
    ( (This)->lpVtbl -> SetCompositionStringW(This,hIMC,dwIndex,pComp,dwCompLen,pRead,dwReadLen) ) 

#define IActiveIMMIME_SetCompositionWindow(This,hIMC,pCompForm)	\
    ( (This)->lpVtbl -> SetCompositionWindow(This,hIMC,pCompForm) ) 

#define IActiveIMMIME_SetConversionStatus(This,hIMC,fdwConversion,fdwSentence)	\
    ( (This)->lpVtbl -> SetConversionStatus(This,hIMC,fdwConversion,fdwSentence) ) 

#define IActiveIMMIME_SetOpenStatus(This,hIMC,fOpen)	\
    ( (This)->lpVtbl -> SetOpenStatus(This,hIMC,fOpen) ) 

#define IActiveIMMIME_SetStatusWindowPos(This,hIMC,pptPos)	\
    ( (This)->lpVtbl -> SetStatusWindowPos(This,hIMC,pptPos) ) 

#define IActiveIMMIME_SimulateHotKey(This,hWnd,dwHotKeyID)	\
    ( (This)->lpVtbl -> SimulateHotKey(This,hWnd,dwHotKeyID) ) 

#define IActiveIMMIME_UnregisterWordA(This,hKL,szReading,dwStyle,szUnregister)	\
    ( (This)->lpVtbl -> UnregisterWordA(This,hKL,szReading,dwStyle,szUnregister) ) 

#define IActiveIMMIME_UnregisterWordW(This,hKL,szReading,dwStyle,szUnregister)	\
    ( (This)->lpVtbl -> UnregisterWordW(This,hKL,szReading,dwStyle,szUnregister) ) 

#define IActiveIMMIME_GenerateMessage(This,hIMC)	\
    ( (This)->lpVtbl -> GenerateMessage(This,hIMC) ) 

#define IActiveIMMIME_LockIMC(This,hIMC,ppIMC)	\
    ( (This)->lpVtbl -> LockIMC(This,hIMC,ppIMC) ) 

#define IActiveIMMIME_UnlockIMC(This,hIMC)	\
    ( (This)->lpVtbl -> UnlockIMC(This,hIMC) ) 

#define IActiveIMMIME_GetIMCLockCount(This,hIMC,pdwLockCount)	\
    ( (This)->lpVtbl -> GetIMCLockCount(This,hIMC,pdwLockCount) ) 

#define IActiveIMMIME_CreateIMCC(This,dwSize,phIMCC)	\
    ( (This)->lpVtbl -> CreateIMCC(This,dwSize,phIMCC) ) 

#define IActiveIMMIME_DestroyIMCC(This,hIMCC)	\
    ( (This)->lpVtbl -> DestroyIMCC(This,hIMCC) ) 

#define IActiveIMMIME_LockIMCC(This,hIMCC,ppv)	\
    ( (This)->lpVtbl -> LockIMCC(This,hIMCC,ppv) ) 

#define IActiveIMMIME_UnlockIMCC(This,hIMCC)	\
    ( (This)->lpVtbl -> UnlockIMCC(This,hIMCC) ) 

#define IActiveIMMIME_ReSizeIMCC(This,hIMCC,dwSize,phIMCC)	\
    ( (This)->lpVtbl -> ReSizeIMCC(This,hIMCC,dwSize,phIMCC) ) 

#define IActiveIMMIME_GetIMCCSize(This,hIMCC,pdwSize)	\
    ( (This)->lpVtbl -> GetIMCCSize(This,hIMCC,pdwSize) ) 

#define IActiveIMMIME_GetIMCCLockCount(This,hIMCC,pdwLockCount)	\
    ( (This)->lpVtbl -> GetIMCCLockCount(This,hIMCC,pdwLockCount) ) 

#define IActiveIMMIME_GetHotKey(This,dwHotKeyID,puModifiers,puVKey,phKL)	\
    ( (This)->lpVtbl -> GetHotKey(This,dwHotKeyID,puModifiers,puVKey,phKL) ) 

#define IActiveIMMIME_SetHotKey(This,dwHotKeyID,uModifiers,uVKey,hKL)	\
    ( (This)->lpVtbl -> SetHotKey(This,dwHotKeyID,uModifiers,uVKey,hKL) ) 

#define IActiveIMMIME_CreateSoftKeyboard(This,uType,hOwner,x,y,phSoftKbdWnd)	\
    ( (This)->lpVtbl -> CreateSoftKeyboard(This,uType,hOwner,x,y,phSoftKbdWnd) ) 

#define IActiveIMMIME_DestroySoftKeyboard(This,hSoftKbdWnd)	\
    ( (This)->lpVtbl -> DestroySoftKeyboard(This,hSoftKbdWnd) ) 

#define IActiveIMMIME_ShowSoftKeyboard(This,hSoftKbdWnd,nCmdShow)	\
    ( (This)->lpVtbl -> ShowSoftKeyboard(This,hSoftKbdWnd,nCmdShow) ) 

#define IActiveIMMIME_GetCodePageA(This,hKL,uCodePage)	\
    ( (This)->lpVtbl -> GetCodePageA(This,hKL,uCodePage) ) 

#define IActiveIMMIME_GetLangId(This,hKL,plid)	\
    ( (This)->lpVtbl -> GetLangId(This,hKL,plid) ) 

#define IActiveIMMIME_KeybdEvent(This,lgidIME,bVk,bScan,dwFlags,dwExtraInfo)	\
    ( (This)->lpVtbl -> KeybdEvent(This,lgidIME,bVk,bScan,dwFlags,dwExtraInfo) ) 

#define IActiveIMMIME_LockModal(This)	\
    ( (This)->lpVtbl -> LockModal(This) ) 

#define IActiveIMMIME_UnlockModal(This)	\
    ( (This)->lpVtbl -> UnlockModal(This) ) 

#define IActiveIMMIME_AssociateContextEx(This,hWnd,hIMC,dwFlags)	\
    ( (This)->lpVtbl -> AssociateContextEx(This,hWnd,hIMC,dwFlags) ) 

#define IActiveIMMIME_DisableIME(This,idThread)	\
    ( (This)->lpVtbl -> DisableIME(This,idThread) ) 

#define IActiveIMMIME_GetImeMenuItemsA(This,hIMC,dwFlags,dwType,pImeParentMenu,pImeMenu,dwSize,pdwResult)	\
    ( (This)->lpVtbl -> GetImeMenuItemsA(This,hIMC,dwFlags,dwType,pImeParentMenu,pImeMenu,dwSize,pdwResult) ) 

#define IActiveIMMIME_GetImeMenuItemsW(This,hIMC,dwFlags,dwType,pImeParentMenu,pImeMenu,dwSize,pdwResult)	\
    ( (This)->lpVtbl -> GetImeMenuItemsW(This,hIMC,dwFlags,dwType,pImeParentMenu,pImeMenu,dwSize,pdwResult) ) 

#define IActiveIMMIME_EnumInputContext(This,idThread,ppEnum)	\
    ( (This)->lpVtbl -> EnumInputContext(This,idThread,ppEnum) ) 

#define IActiveIMMIME_RequestMessageA(This,hIMC,wParam,lParam,plResult)	\
    ( (This)->lpVtbl -> RequestMessageA(This,hIMC,wParam,lParam,plResult) ) 

#define IActiveIMMIME_RequestMessageW(This,hIMC,wParam,lParam,plResult)	\
    ( (This)->lpVtbl -> RequestMessageW(This,hIMC,wParam,lParam,plResult) ) 

#define IActiveIMMIME_SendIMCA(This,hWnd,uMsg,wParam,lParam,plResult)	\
    ( (This)->lpVtbl -> SendIMCA(This,hWnd,uMsg,wParam,lParam,plResult) ) 

#define IActiveIMMIME_SendIMCW(This,hWnd,uMsg,wParam,lParam,plResult)	\
    ( (This)->lpVtbl -> SendIMCW(This,hWnd,uMsg,wParam,lParam,plResult) ) 

#define IActiveIMMIME_IsSleeping(This)	\
    ( (This)->lpVtbl -> IsSleeping(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IActiveIMMIME_INTERFACE_DEFINED__ */


#ifndef __IActiveIME_INTERFACE_DEFINED__
#define __IActiveIME_INTERFACE_DEFINED__

/* interface IActiveIME */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IActiveIME;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6FE20962-D077-11d0-8FE7-00AA006BCC59")
    IActiveIME : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Inquire( 
            /* [annotation][in] */ 
            _In_  DWORD dwSystemInfoFlags,
            /* [annotation][out] */ 
            _Out_  IMEINFO *pIMEInfo,
            /* [annotation][out] */ 
            _Out_  LPWSTR szWndClass,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwPrivate) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ConversionList( 
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  LPWSTR szSource,
            /* [annotation][in] */ 
            _In_  UINT uFlag,
            /* [annotation][in] */ 
            _In_  UINT uBufLen,
            /* [annotation][out] */ 
            _Out_  CANDIDATELIST *pDest,
            /* [annotation][out] */ 
            _Out_  UINT *puCopied) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Configure( 
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  HWND hWnd,
            /* [annotation][in] */ 
            _In_  DWORD dwMode,
            /* [annotation][in] */ 
            _In_  REGISTERWORDW *pRegisterWord) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Destroy( 
            /* [annotation][in] */ 
            _In_  UINT uReserved) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Escape( 
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  UINT uEscape,
            /* [annotation][out][in] */ 
            _Inout_  void *pData,
            /* [annotation][out] */ 
            _Out_  LRESULT *plResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetActiveContext( 
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  BOOL fFlag) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ProcessKey( 
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  UINT uVirKey,
            /* [annotation][in] */ 
            _In_  DWORD lParam,
            /* [annotation][in] */ 
            _In_  BYTE *pbKeyState) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Notify( 
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  DWORD dwAction,
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][in] */ 
            _In_  DWORD dwValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Select( 
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  BOOL fSelect) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetCompositionString( 
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][in] */ 
            _In_  void *pComp,
            /* [annotation][in] */ 
            _In_  DWORD dwCompLen,
            /* [annotation][in] */ 
            _In_  void *pRead,
            /* [annotation][in] */ 
            _In_  DWORD dwReadLen) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ToAsciiEx( 
            /* [annotation][in] */ 
            _In_  UINT uVirKey,
            /* [annotation][in] */ 
            _In_  UINT uScanCode,
            /* [annotation][in] */ 
            _In_  BYTE *pbKeyState,
            /* [annotation][in] */ 
            _In_  UINT fuState,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwTransBuf,
            /* [annotation][out] */ 
            _Out_  UINT *puSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RegisterWord( 
            /* [annotation][in] */ 
            _In_  LPWSTR szReading,
            /* [annotation][in] */ 
            _In_  DWORD dwStyle,
            /* [annotation][in] */ 
            _In_  LPWSTR szString) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UnregisterWord( 
            /* [annotation][in] */ 
            _In_  LPWSTR szReading,
            /* [annotation][in] */ 
            _In_  DWORD dwStyle,
            /* [annotation][in] */ 
            _In_  LPWSTR szString) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRegisterWordStyle( 
            /* [annotation][in] */ 
            _In_  UINT nItem,
            /* [annotation][out] */ 
            _Out_  STYLEBUFW *pStyleBuf,
            /* [annotation][out] */ 
            _Out_  UINT *puBufSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumRegisterWord( 
            /* [annotation][in] */ 
            _In_  LPWSTR szReading,
            /* [annotation][in] */ 
            _In_  DWORD dwStyle,
            /* [annotation][in] */ 
            _In_  LPWSTR szRegister,
            /* [annotation][in] */ 
            _In_  LPVOID pData,
            /* [annotation][out] */ 
            _Out_  IEnumRegisterWordW **ppEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCodePageA( 
            /* [annotation][out] */ 
            _Out_  UINT *uCodePage) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLangId( 
            /* [annotation][out] */ 
            _Out_  LANGID *plid) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IActiveIMEVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IActiveIME * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IActiveIME * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IActiveIME * This);
        
        HRESULT ( STDMETHODCALLTYPE *Inquire )( 
            __RPC__in IActiveIME * This,
            /* [annotation][in] */ 
            _In_  DWORD dwSystemInfoFlags,
            /* [annotation][out] */ 
            _Out_  IMEINFO *pIMEInfo,
            /* [annotation][out] */ 
            _Out_  LPWSTR szWndClass,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwPrivate);
        
        HRESULT ( STDMETHODCALLTYPE *ConversionList )( 
            __RPC__in IActiveIME * This,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  LPWSTR szSource,
            /* [annotation][in] */ 
            _In_  UINT uFlag,
            /* [annotation][in] */ 
            _In_  UINT uBufLen,
            /* [annotation][out] */ 
            _Out_  CANDIDATELIST *pDest,
            /* [annotation][out] */ 
            _Out_  UINT *puCopied);
        
        HRESULT ( STDMETHODCALLTYPE *Configure )( 
            __RPC__in IActiveIME * This,
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  HWND hWnd,
            /* [annotation][in] */ 
            _In_  DWORD dwMode,
            /* [annotation][in] */ 
            _In_  REGISTERWORDW *pRegisterWord);
        
        HRESULT ( STDMETHODCALLTYPE *Destroy )( 
            __RPC__in IActiveIME * This,
            /* [annotation][in] */ 
            _In_  UINT uReserved);
        
        HRESULT ( STDMETHODCALLTYPE *Escape )( 
            __RPC__in IActiveIME * This,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  UINT uEscape,
            /* [annotation][out][in] */ 
            _Inout_  void *pData,
            /* [annotation][out] */ 
            _Out_  LRESULT *plResult);
        
        HRESULT ( STDMETHODCALLTYPE *SetActiveContext )( 
            __RPC__in IActiveIME * This,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  BOOL fFlag);
        
        HRESULT ( STDMETHODCALLTYPE *ProcessKey )( 
            __RPC__in IActiveIME * This,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  UINT uVirKey,
            /* [annotation][in] */ 
            _In_  DWORD lParam,
            /* [annotation][in] */ 
            _In_  BYTE *pbKeyState);
        
        HRESULT ( STDMETHODCALLTYPE *Notify )( 
            __RPC__in IActiveIME * This,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  DWORD dwAction,
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][in] */ 
            _In_  DWORD dwValue);
        
        HRESULT ( STDMETHODCALLTYPE *Select )( 
            __RPC__in IActiveIME * This,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  BOOL fSelect);
        
        HRESULT ( STDMETHODCALLTYPE *SetCompositionString )( 
            __RPC__in IActiveIME * This,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][in] */ 
            _In_  void *pComp,
            /* [annotation][in] */ 
            _In_  DWORD dwCompLen,
            /* [annotation][in] */ 
            _In_  void *pRead,
            /* [annotation][in] */ 
            _In_  DWORD dwReadLen);
        
        HRESULT ( STDMETHODCALLTYPE *ToAsciiEx )( 
            __RPC__in IActiveIME * This,
            /* [annotation][in] */ 
            _In_  UINT uVirKey,
            /* [annotation][in] */ 
            _In_  UINT uScanCode,
            /* [annotation][in] */ 
            _In_  BYTE *pbKeyState,
            /* [annotation][in] */ 
            _In_  UINT fuState,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwTransBuf,
            /* [annotation][out] */ 
            _Out_  UINT *puSize);
        
        HRESULT ( STDMETHODCALLTYPE *RegisterWord )( 
            __RPC__in IActiveIME * This,
            /* [annotation][in] */ 
            _In_  LPWSTR szReading,
            /* [annotation][in] */ 
            _In_  DWORD dwStyle,
            /* [annotation][in] */ 
            _In_  LPWSTR szString);
        
        HRESULT ( STDMETHODCALLTYPE *UnregisterWord )( 
            __RPC__in IActiveIME * This,
            /* [annotation][in] */ 
            _In_  LPWSTR szReading,
            /* [annotation][in] */ 
            _In_  DWORD dwStyle,
            /* [annotation][in] */ 
            _In_  LPWSTR szString);
        
        HRESULT ( STDMETHODCALLTYPE *GetRegisterWordStyle )( 
            __RPC__in IActiveIME * This,
            /* [annotation][in] */ 
            _In_  UINT nItem,
            /* [annotation][out] */ 
            _Out_  STYLEBUFW *pStyleBuf,
            /* [annotation][out] */ 
            _Out_  UINT *puBufSize);
        
        HRESULT ( STDMETHODCALLTYPE *EnumRegisterWord )( 
            __RPC__in IActiveIME * This,
            /* [annotation][in] */ 
            _In_  LPWSTR szReading,
            /* [annotation][in] */ 
            _In_  DWORD dwStyle,
            /* [annotation][in] */ 
            _In_  LPWSTR szRegister,
            /* [annotation][in] */ 
            _In_  LPVOID pData,
            /* [annotation][out] */ 
            _Out_  IEnumRegisterWordW **ppEnum);
        
        HRESULT ( STDMETHODCALLTYPE *GetCodePageA )( 
            __RPC__in IActiveIME * This,
            /* [annotation][out] */ 
            _Out_  UINT *uCodePage);
        
        HRESULT ( STDMETHODCALLTYPE *GetLangId )( 
            __RPC__in IActiveIME * This,
            /* [annotation][out] */ 
            _Out_  LANGID *plid);
        
        END_INTERFACE
    } IActiveIMEVtbl;

    interface IActiveIME
    {
        CONST_VTBL struct IActiveIMEVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActiveIME_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IActiveIME_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IActiveIME_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IActiveIME_Inquire(This,dwSystemInfoFlags,pIMEInfo,szWndClass,pdwPrivate)	\
    ( (This)->lpVtbl -> Inquire(This,dwSystemInfoFlags,pIMEInfo,szWndClass,pdwPrivate) ) 

#define IActiveIME_ConversionList(This,hIMC,szSource,uFlag,uBufLen,pDest,puCopied)	\
    ( (This)->lpVtbl -> ConversionList(This,hIMC,szSource,uFlag,uBufLen,pDest,puCopied) ) 

#define IActiveIME_Configure(This,hKL,hWnd,dwMode,pRegisterWord)	\
    ( (This)->lpVtbl -> Configure(This,hKL,hWnd,dwMode,pRegisterWord) ) 

#define IActiveIME_Destroy(This,uReserved)	\
    ( (This)->lpVtbl -> Destroy(This,uReserved) ) 

#define IActiveIME_Escape(This,hIMC,uEscape,pData,plResult)	\
    ( (This)->lpVtbl -> Escape(This,hIMC,uEscape,pData,plResult) ) 

#define IActiveIME_SetActiveContext(This,hIMC,fFlag)	\
    ( (This)->lpVtbl -> SetActiveContext(This,hIMC,fFlag) ) 

#define IActiveIME_ProcessKey(This,hIMC,uVirKey,lParam,pbKeyState)	\
    ( (This)->lpVtbl -> ProcessKey(This,hIMC,uVirKey,lParam,pbKeyState) ) 

#define IActiveIME_Notify(This,hIMC,dwAction,dwIndex,dwValue)	\
    ( (This)->lpVtbl -> Notify(This,hIMC,dwAction,dwIndex,dwValue) ) 

#define IActiveIME_Select(This,hIMC,fSelect)	\
    ( (This)->lpVtbl -> Select(This,hIMC,fSelect) ) 

#define IActiveIME_SetCompositionString(This,hIMC,dwIndex,pComp,dwCompLen,pRead,dwReadLen)	\
    ( (This)->lpVtbl -> SetCompositionString(This,hIMC,dwIndex,pComp,dwCompLen,pRead,dwReadLen) ) 

#define IActiveIME_ToAsciiEx(This,uVirKey,uScanCode,pbKeyState,fuState,hIMC,pdwTransBuf,puSize)	\
    ( (This)->lpVtbl -> ToAsciiEx(This,uVirKey,uScanCode,pbKeyState,fuState,hIMC,pdwTransBuf,puSize) ) 

#define IActiveIME_RegisterWord(This,szReading,dwStyle,szString)	\
    ( (This)->lpVtbl -> RegisterWord(This,szReading,dwStyle,szString) ) 

#define IActiveIME_UnregisterWord(This,szReading,dwStyle,szString)	\
    ( (This)->lpVtbl -> UnregisterWord(This,szReading,dwStyle,szString) ) 

#define IActiveIME_GetRegisterWordStyle(This,nItem,pStyleBuf,puBufSize)	\
    ( (This)->lpVtbl -> GetRegisterWordStyle(This,nItem,pStyleBuf,puBufSize) ) 

#define IActiveIME_EnumRegisterWord(This,szReading,dwStyle,szRegister,pData,ppEnum)	\
    ( (This)->lpVtbl -> EnumRegisterWord(This,szReading,dwStyle,szRegister,pData,ppEnum) ) 

#define IActiveIME_GetCodePageA(This,uCodePage)	\
    ( (This)->lpVtbl -> GetCodePageA(This,uCodePage) ) 

#define IActiveIME_GetLangId(This,plid)	\
    ( (This)->lpVtbl -> GetLangId(This,plid) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IActiveIME_INTERFACE_DEFINED__ */


#ifndef __IActiveIME2_INTERFACE_DEFINED__
#define __IActiveIME2_INTERFACE_DEFINED__

/* interface IActiveIME2 */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IActiveIME2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("e1c4bf0e-2d53-11d2-93e1-0060b067b86e")
    IActiveIME2 : public IActiveIME
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Sleep( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Unsleep( 
            /* [annotation][in] */ 
            _In_  BOOL fDead) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IActiveIME2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IActiveIME2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IActiveIME2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IActiveIME2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *Inquire )( 
            __RPC__in IActiveIME2 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwSystemInfoFlags,
            /* [annotation][out] */ 
            _Out_  IMEINFO *pIMEInfo,
            /* [annotation][out] */ 
            _Out_  LPWSTR szWndClass,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwPrivate);
        
        HRESULT ( STDMETHODCALLTYPE *ConversionList )( 
            __RPC__in IActiveIME2 * This,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  LPWSTR szSource,
            /* [annotation][in] */ 
            _In_  UINT uFlag,
            /* [annotation][in] */ 
            _In_  UINT uBufLen,
            /* [annotation][out] */ 
            _Out_  CANDIDATELIST *pDest,
            /* [annotation][out] */ 
            _Out_  UINT *puCopied);
        
        HRESULT ( STDMETHODCALLTYPE *Configure )( 
            __RPC__in IActiveIME2 * This,
            /* [annotation][in] */ 
            _In_  HKL hKL,
            /* [annotation][in] */ 
            _In_  HWND hWnd,
            /* [annotation][in] */ 
            _In_  DWORD dwMode,
            /* [annotation][in] */ 
            _In_  REGISTERWORDW *pRegisterWord);
        
        HRESULT ( STDMETHODCALLTYPE *Destroy )( 
            __RPC__in IActiveIME2 * This,
            /* [annotation][in] */ 
            _In_  UINT uReserved);
        
        HRESULT ( STDMETHODCALLTYPE *Escape )( 
            __RPC__in IActiveIME2 * This,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  UINT uEscape,
            /* [annotation][out][in] */ 
            _Inout_  void *pData,
            /* [annotation][out] */ 
            _Out_  LRESULT *plResult);
        
        HRESULT ( STDMETHODCALLTYPE *SetActiveContext )( 
            __RPC__in IActiveIME2 * This,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  BOOL fFlag);
        
        HRESULT ( STDMETHODCALLTYPE *ProcessKey )( 
            __RPC__in IActiveIME2 * This,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  UINT uVirKey,
            /* [annotation][in] */ 
            _In_  DWORD lParam,
            /* [annotation][in] */ 
            _In_  BYTE *pbKeyState);
        
        HRESULT ( STDMETHODCALLTYPE *Notify )( 
            __RPC__in IActiveIME2 * This,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  DWORD dwAction,
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][in] */ 
            _In_  DWORD dwValue);
        
        HRESULT ( STDMETHODCALLTYPE *Select )( 
            __RPC__in IActiveIME2 * This,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  BOOL fSelect);
        
        HRESULT ( STDMETHODCALLTYPE *SetCompositionString )( 
            __RPC__in IActiveIME2 * This,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][in] */ 
            _In_  void *pComp,
            /* [annotation][in] */ 
            _In_  DWORD dwCompLen,
            /* [annotation][in] */ 
            _In_  void *pRead,
            /* [annotation][in] */ 
            _In_  DWORD dwReadLen);
        
        HRESULT ( STDMETHODCALLTYPE *ToAsciiEx )( 
            __RPC__in IActiveIME2 * This,
            /* [annotation][in] */ 
            _In_  UINT uVirKey,
            /* [annotation][in] */ 
            _In_  UINT uScanCode,
            /* [annotation][in] */ 
            _In_  BYTE *pbKeyState,
            /* [annotation][in] */ 
            _In_  UINT fuState,
            /* [annotation][in] */ 
            _In_  HIMC hIMC,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwTransBuf,
            /* [annotation][out] */ 
            _Out_  UINT *puSize);
        
        HRESULT ( STDMETHODCALLTYPE *RegisterWord )( 
            __RPC__in IActiveIME2 * This,
            /* [annotation][in] */ 
            _In_  LPWSTR szReading,
            /* [annotation][in] */ 
            _In_  DWORD dwStyle,
            /* [annotation][in] */ 
            _In_  LPWSTR szString);
        
        HRESULT ( STDMETHODCALLTYPE *UnregisterWord )( 
            __RPC__in IActiveIME2 * This,
            /* [annotation][in] */ 
            _In_  LPWSTR szReading,
            /* [annotation][in] */ 
            _In_  DWORD dwStyle,
            /* [annotation][in] */ 
            _In_  LPWSTR szString);
        
        HRESULT ( STDMETHODCALLTYPE *GetRegisterWordStyle )( 
            __RPC__in IActiveIME2 * This,
            /* [annotation][in] */ 
            _In_  UINT nItem,
            /* [annotation][out] */ 
            _Out_  STYLEBUFW *pStyleBuf,
            /* [annotation][out] */ 
            _Out_  UINT *puBufSize);
        
        HRESULT ( STDMETHODCALLTYPE *EnumRegisterWord )( 
            __RPC__in IActiveIME2 * This,
            /* [annotation][in] */ 
            _In_  LPWSTR szReading,
            /* [annotation][in] */ 
            _In_  DWORD dwStyle,
            /* [annotation][in] */ 
            _In_  LPWSTR szRegister,
            /* [annotation][in] */ 
            _In_  LPVOID pData,
            /* [annotation][out] */ 
            _Out_  IEnumRegisterWordW **ppEnum);
        
        HRESULT ( STDMETHODCALLTYPE *GetCodePageA )( 
            __RPC__in IActiveIME2 * This,
            /* [annotation][out] */ 
            _Out_  UINT *uCodePage);
        
        HRESULT ( STDMETHODCALLTYPE *GetLangId )( 
            __RPC__in IActiveIME2 * This,
            /* [annotation][out] */ 
            _Out_  LANGID *plid);
        
        HRESULT ( STDMETHODCALLTYPE *Sleep )( 
            __RPC__in IActiveIME2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *Unsleep )( 
            __RPC__in IActiveIME2 * This,
            /* [annotation][in] */ 
            _In_  BOOL fDead);
        
        END_INTERFACE
    } IActiveIME2Vtbl;

    interface IActiveIME2
    {
        CONST_VTBL struct IActiveIME2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActiveIME2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IActiveIME2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IActiveIME2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IActiveIME2_Inquire(This,dwSystemInfoFlags,pIMEInfo,szWndClass,pdwPrivate)	\
    ( (This)->lpVtbl -> Inquire(This,dwSystemInfoFlags,pIMEInfo,szWndClass,pdwPrivate) ) 

#define IActiveIME2_ConversionList(This,hIMC,szSource,uFlag,uBufLen,pDest,puCopied)	\
    ( (This)->lpVtbl -> ConversionList(This,hIMC,szSource,uFlag,uBufLen,pDest,puCopied) ) 

#define IActiveIME2_Configure(This,hKL,hWnd,dwMode,pRegisterWord)	\
    ( (This)->lpVtbl -> Configure(This,hKL,hWnd,dwMode,pRegisterWord) ) 

#define IActiveIME2_Destroy(This,uReserved)	\
    ( (This)->lpVtbl -> Destroy(This,uReserved) ) 

#define IActiveIME2_Escape(This,hIMC,uEscape,pData,plResult)	\
    ( (This)->lpVtbl -> Escape(This,hIMC,uEscape,pData,plResult) ) 

#define IActiveIME2_SetActiveContext(This,hIMC,fFlag)	\
    ( (This)->lpVtbl -> SetActiveContext(This,hIMC,fFlag) ) 

#define IActiveIME2_ProcessKey(This,hIMC,uVirKey,lParam,pbKeyState)	\
    ( (This)->lpVtbl -> ProcessKey(This,hIMC,uVirKey,lParam,pbKeyState) ) 

#define IActiveIME2_Notify(This,hIMC,dwAction,dwIndex,dwValue)	\
    ( (This)->lpVtbl -> Notify(This,hIMC,dwAction,dwIndex,dwValue) ) 

#define IActiveIME2_Select(This,hIMC,fSelect)	\
    ( (This)->lpVtbl -> Select(This,hIMC,fSelect) ) 

#define IActiveIME2_SetCompositionString(This,hIMC,dwIndex,pComp,dwCompLen,pRead,dwReadLen)	\
    ( (This)->lpVtbl -> SetCompositionString(This,hIMC,dwIndex,pComp,dwCompLen,pRead,dwReadLen) ) 

#define IActiveIME2_ToAsciiEx(This,uVirKey,uScanCode,pbKeyState,fuState,hIMC,pdwTransBuf,puSize)	\
    ( (This)->lpVtbl -> ToAsciiEx(This,uVirKey,uScanCode,pbKeyState,fuState,hIMC,pdwTransBuf,puSize) ) 

#define IActiveIME2_RegisterWord(This,szReading,dwStyle,szString)	\
    ( (This)->lpVtbl -> RegisterWord(This,szReading,dwStyle,szString) ) 

#define IActiveIME2_UnregisterWord(This,szReading,dwStyle,szString)	\
    ( (This)->lpVtbl -> UnregisterWord(This,szReading,dwStyle,szString) ) 

#define IActiveIME2_GetRegisterWordStyle(This,nItem,pStyleBuf,puBufSize)	\
    ( (This)->lpVtbl -> GetRegisterWordStyle(This,nItem,pStyleBuf,puBufSize) ) 

#define IActiveIME2_EnumRegisterWord(This,szReading,dwStyle,szRegister,pData,ppEnum)	\
    ( (This)->lpVtbl -> EnumRegisterWord(This,szReading,dwStyle,szRegister,pData,ppEnum) ) 

#define IActiveIME2_GetCodePageA(This,uCodePage)	\
    ( (This)->lpVtbl -> GetCodePageA(This,uCodePage) ) 

#define IActiveIME2_GetLangId(This,plid)	\
    ( (This)->lpVtbl -> GetLangId(This,plid) ) 


#define IActiveIME2_Sleep(This)	\
    ( (This)->lpVtbl -> Sleep(This) ) 

#define IActiveIME2_Unsleep(This,fDead)	\
    ( (This)->lpVtbl -> Unsleep(This,fDead) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IActiveIME2_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_CActiveIMM;

#ifdef __cplusplus

class DECLSPEC_UUID("4955DD33-B159-11d0-8FCF-00AA006BCC59")
CActiveIMM;
#endif
#endif /* __ActiveIMM_LIBRARY_DEFINED__ */

/* interface __MIDL_itf_dimm_0000_0001 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_dimm_0000_0001_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_dimm_0000_0001_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


