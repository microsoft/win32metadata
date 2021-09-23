

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

#ifndef __ctfutb_h__
#define __ctfutb_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ITfLangBarMgr_FWD_DEFINED__
#define __ITfLangBarMgr_FWD_DEFINED__
typedef interface ITfLangBarMgr ITfLangBarMgr;

#endif 	/* __ITfLangBarMgr_FWD_DEFINED__ */


#ifndef __ITfLangBarEventSink_FWD_DEFINED__
#define __ITfLangBarEventSink_FWD_DEFINED__
typedef interface ITfLangBarEventSink ITfLangBarEventSink;

#endif 	/* __ITfLangBarEventSink_FWD_DEFINED__ */


#ifndef __ITfLangBarItemSink_FWD_DEFINED__
#define __ITfLangBarItemSink_FWD_DEFINED__
typedef interface ITfLangBarItemSink ITfLangBarItemSink;

#endif 	/* __ITfLangBarItemSink_FWD_DEFINED__ */


#ifndef __IEnumTfLangBarItems_FWD_DEFINED__
#define __IEnumTfLangBarItems_FWD_DEFINED__
typedef interface IEnumTfLangBarItems IEnumTfLangBarItems;

#endif 	/* __IEnumTfLangBarItems_FWD_DEFINED__ */


#ifndef __ITfLangBarItemMgr_FWD_DEFINED__
#define __ITfLangBarItemMgr_FWD_DEFINED__
typedef interface ITfLangBarItemMgr ITfLangBarItemMgr;

#endif 	/* __ITfLangBarItemMgr_FWD_DEFINED__ */


#ifndef __ITfLangBarItem_FWD_DEFINED__
#define __ITfLangBarItem_FWD_DEFINED__
typedef interface ITfLangBarItem ITfLangBarItem;

#endif 	/* __ITfLangBarItem_FWD_DEFINED__ */


#ifndef __ITfSystemLangBarItemSink_FWD_DEFINED__
#define __ITfSystemLangBarItemSink_FWD_DEFINED__
typedef interface ITfSystemLangBarItemSink ITfSystemLangBarItemSink;

#endif 	/* __ITfSystemLangBarItemSink_FWD_DEFINED__ */


#ifndef __ITfSystemLangBarItem_FWD_DEFINED__
#define __ITfSystemLangBarItem_FWD_DEFINED__
typedef interface ITfSystemLangBarItem ITfSystemLangBarItem;

#endif 	/* __ITfSystemLangBarItem_FWD_DEFINED__ */


#ifndef __ITfSystemLangBarItemText_FWD_DEFINED__
#define __ITfSystemLangBarItemText_FWD_DEFINED__
typedef interface ITfSystemLangBarItemText ITfSystemLangBarItemText;

#endif 	/* __ITfSystemLangBarItemText_FWD_DEFINED__ */


#ifndef __ITfSystemDeviceTypeLangBarItem_FWD_DEFINED__
#define __ITfSystemDeviceTypeLangBarItem_FWD_DEFINED__
typedef interface ITfSystemDeviceTypeLangBarItem ITfSystemDeviceTypeLangBarItem;

#endif 	/* __ITfSystemDeviceTypeLangBarItem_FWD_DEFINED__ */


#ifndef __ITfLangBarItemButton_FWD_DEFINED__
#define __ITfLangBarItemButton_FWD_DEFINED__
typedef interface ITfLangBarItemButton ITfLangBarItemButton;

#endif 	/* __ITfLangBarItemButton_FWD_DEFINED__ */


#ifndef __ITfLangBarItemBitmapButton_FWD_DEFINED__
#define __ITfLangBarItemBitmapButton_FWD_DEFINED__
typedef interface ITfLangBarItemBitmapButton ITfLangBarItemBitmapButton;

#endif 	/* __ITfLangBarItemBitmapButton_FWD_DEFINED__ */


#ifndef __ITfLangBarItemBitmap_FWD_DEFINED__
#define __ITfLangBarItemBitmap_FWD_DEFINED__
typedef interface ITfLangBarItemBitmap ITfLangBarItemBitmap;

#endif 	/* __ITfLangBarItemBitmap_FWD_DEFINED__ */


#ifndef __ITfLangBarItemBalloon_FWD_DEFINED__
#define __ITfLangBarItemBalloon_FWD_DEFINED__
typedef interface ITfLangBarItemBalloon ITfLangBarItemBalloon;

#endif 	/* __ITfLangBarItemBalloon_FWD_DEFINED__ */


#ifndef __ITfMenu_FWD_DEFINED__
#define __ITfMenu_FWD_DEFINED__
typedef interface ITfMenu ITfMenu;

#endif 	/* __ITfMenu_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "msctf.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_ctfutb_0000_0000 */
/* [local] */ 

#include <winapifamily.h>
//=--------------------------------------------------------------------------=
// ctfutb.h


// Text Framework declarations.

//=--------------------------------------------------------------------------=
// (C) Copyright 1995-2001 Microsoft Corporation.  All Rights Reserved.
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR TFPLIED, INCLUDING BUT NOT LIMITED TO
// THE TFPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//=--------------------------------------------------------------------------=

#ifndef CTFUTB_DEFINED
#define CTFUTB_DEFINED

#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#pragma region Application Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP)
#define TF_FLOATINGLANGBAR_WNDTITLEW L"TF_FloatingLangBar_WndTitle"
#define TF_FLOATINGLANGBAR_WNDTITLEA "TF_FloatingLangBar_WndTitle"
#ifdef UNICODE
#define TF_FLOATINGLANGBAR_WNDTITLE TF_FLOATINGLANGBAR_WNDTITLEW
#else
#define TF_FLOATINGLANGBAR_WNDTITLE TF_FLOATINGLANGBAR_WNDTITLEA
#endif
#define TF_LBI_ICON                0x00000001
#define TF_LBI_TEXT                0x00000002
#define TF_LBI_TOOLTIP             0x00000004
#define TF_LBI_BITMAP              0x00000008
#define TF_LBI_BALLOON             0x00000010
#define TF_LBI_CUSTOMUI            0x00000020
#define TF_LBI_BTNALL              (TF_LBI_ICON | TF_LBI_TEXT | TF_LBI_TOOLTIP)
#define TF_LBI_BMPBTNALL           (TF_LBI_BITMAP | TF_LBI_TEXT | TF_LBI_TOOLTIP)
#define TF_LBI_BMPALL              (TF_LBI_BITMAP | TF_LBI_TOOLTIP)
#define TF_LBI_STATUS              0x00010000
#define TF_LBI_STYLE_HIDDENSTATUSCONTROL  0x00000001
#define TF_LBI_STYLE_SHOWNINTRAY        0x00000002
#define TF_LBI_STYLE_HIDEONNOOTHERITEMS 0x00000004
#define TF_LBI_STYLE_SHOWNINTRAYONLY    0x00000008
#define TF_LBI_STYLE_HIDDENBYDEFAULT    0x00000010
#define TF_LBI_STYLE_TEXTCOLORICON      0x00000020
#define TF_LBI_STYLE_BTN_BUTTON         0x00010000
#define TF_LBI_STYLE_BTN_MENU           0x00020000
#define TF_LBI_STYLE_BTN_TOGGLE         0x00040000
#define TF_LBI_STATUS_HIDDEN           0x00000001
#define TF_LBI_STATUS_DISABLED         0x00000002
#define TF_LBI_STATUS_BTN_TOGGLED      0x00010000
#define TF_LBI_BMPF_VERTICAL           0x00000001
#define TF_SFT_SHOWNORMAL               0x00000001
#define TF_SFT_DOCK                     0x00000002
#define TF_SFT_MINIMIZED                0x00000004
#define TF_SFT_HIDDEN                   0x00000008
#define TF_SFT_NOTRANSPARENCY           0x00000010
#define TF_SFT_LOWTRANSPARENCY          0x00000020
#define TF_SFT_HIGHTRANSPARENCY         0x00000040
#define TF_SFT_LABELS                   0x00000080
#define TF_SFT_NOLABELS                 0x00000100
#define TF_SFT_EXTRAICONSONMINIMIZED    0x00000200
#define TF_SFT_NOEXTRAICONSONMINIMIZED  0x00000400
#define TF_SFT_DESKBAND                 0x00000800
#define TF_INVALIDMENUITEM            (UINT)(-1)
#define TF_DTLBI_USEPROFILEICON         0x00000001
#ifdef __cplusplus
}
#endif  /* __cplusplus */
#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP) */
#pragma endregion
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)







extern RPC_IF_HANDLE __MIDL_itf_ctfutb_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ctfutb_0000_0000_v0_0_s_ifspec;

#ifndef __ITfLangBarMgr_INTERFACE_DEFINED__
#define __ITfLangBarMgr_INTERFACE_DEFINED__

/* interface ITfLangBarMgr */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_ITfLangBarMgr;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("87955690-e627-11d2-8ddb-00105a2799b5")
    ITfLangBarMgr : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AdviseEventSink( 
            /* [annotation][in] */ 
            _In_  ITfLangBarEventSink *pSink,
            /* [annotation][in] */ 
            _In_  HWND hwnd,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][in] */ 
            _In_  DWORD *pdwCookie) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UnadviseEventSink( 
            /* [annotation][in] */ 
            _In_  DWORD dwCookie) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetThreadMarshalInterface( 
            /* [annotation][in] */ 
            _In_  DWORD dwThreadId,
            /* [annotation][in] */ 
            _In_  DWORD dwType,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  IUnknown **ppunk) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetThreadLangBarItemMgr( 
            /* [annotation][in] */ 
            _In_  DWORD dwThreadId,
            /* [annotation][out] */ 
            _Out_  ITfLangBarItemMgr **pplbi,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwThreadid) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetInputProcessorProfiles( 
            /* [annotation][in] */ 
            _In_  DWORD dwThreadId,
            /* [annotation][out] */ 
            _Out_  ITfInputProcessorProfiles **ppaip,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwThreadid) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RestoreLastFocus( 
            /* [annotation][out] */ 
            _Out_  DWORD *pdwThreadId,
            /* [annotation][in] */ 
            _In_  BOOL fPrev) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetModalInput( 
            /* [annotation][in] */ 
            _In_  ITfLangBarEventSink *pSink,
            /* [annotation][in] */ 
            _In_  DWORD dwThreadId,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ShowFloating( 
            /* [annotation][in] */ 
            _In_  DWORD dwFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetShowFloatingStatus( 
            /* [annotation][out] */ 
            _Out_  DWORD *pdwFlags) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITfLangBarMgrVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ITfLangBarMgr * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ITfLangBarMgr * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ITfLangBarMgr * This);
        
        HRESULT ( STDMETHODCALLTYPE *AdviseEventSink )( 
            __RPC__in ITfLangBarMgr * This,
            /* [annotation][in] */ 
            _In_  ITfLangBarEventSink *pSink,
            /* [annotation][in] */ 
            _In_  HWND hwnd,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][in] */ 
            _In_  DWORD *pdwCookie);
        
        HRESULT ( STDMETHODCALLTYPE *UnadviseEventSink )( 
            __RPC__in ITfLangBarMgr * This,
            /* [annotation][in] */ 
            _In_  DWORD dwCookie);
        
        HRESULT ( STDMETHODCALLTYPE *GetThreadMarshalInterface )( 
            __RPC__in ITfLangBarMgr * This,
            /* [annotation][in] */ 
            _In_  DWORD dwThreadId,
            /* [annotation][in] */ 
            _In_  DWORD dwType,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  IUnknown **ppunk);
        
        HRESULT ( STDMETHODCALLTYPE *GetThreadLangBarItemMgr )( 
            __RPC__in ITfLangBarMgr * This,
            /* [annotation][in] */ 
            _In_  DWORD dwThreadId,
            /* [annotation][out] */ 
            _Out_  ITfLangBarItemMgr **pplbi,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwThreadid);
        
        HRESULT ( STDMETHODCALLTYPE *GetInputProcessorProfiles )( 
            __RPC__in ITfLangBarMgr * This,
            /* [annotation][in] */ 
            _In_  DWORD dwThreadId,
            /* [annotation][out] */ 
            _Out_  ITfInputProcessorProfiles **ppaip,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwThreadid);
        
        HRESULT ( STDMETHODCALLTYPE *RestoreLastFocus )( 
            __RPC__in ITfLangBarMgr * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwThreadId,
            /* [annotation][in] */ 
            _In_  BOOL fPrev);
        
        HRESULT ( STDMETHODCALLTYPE *SetModalInput )( 
            __RPC__in ITfLangBarMgr * This,
            /* [annotation][in] */ 
            _In_  ITfLangBarEventSink *pSink,
            /* [annotation][in] */ 
            _In_  DWORD dwThreadId,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags);
        
        HRESULT ( STDMETHODCALLTYPE *ShowFloating )( 
            __RPC__in ITfLangBarMgr * This,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags);
        
        HRESULT ( STDMETHODCALLTYPE *GetShowFloatingStatus )( 
            __RPC__in ITfLangBarMgr * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwFlags);
        
        END_INTERFACE
    } ITfLangBarMgrVtbl;

    interface ITfLangBarMgr
    {
        CONST_VTBL struct ITfLangBarMgrVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITfLangBarMgr_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITfLangBarMgr_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITfLangBarMgr_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITfLangBarMgr_AdviseEventSink(This,pSink,hwnd,dwFlags,pdwCookie)	\
    ( (This)->lpVtbl -> AdviseEventSink(This,pSink,hwnd,dwFlags,pdwCookie) ) 

#define ITfLangBarMgr_UnadviseEventSink(This,dwCookie)	\
    ( (This)->lpVtbl -> UnadviseEventSink(This,dwCookie) ) 

#define ITfLangBarMgr_GetThreadMarshalInterface(This,dwThreadId,dwType,riid,ppunk)	\
    ( (This)->lpVtbl -> GetThreadMarshalInterface(This,dwThreadId,dwType,riid,ppunk) ) 

#define ITfLangBarMgr_GetThreadLangBarItemMgr(This,dwThreadId,pplbi,pdwThreadid)	\
    ( (This)->lpVtbl -> GetThreadLangBarItemMgr(This,dwThreadId,pplbi,pdwThreadid) ) 

#define ITfLangBarMgr_GetInputProcessorProfiles(This,dwThreadId,ppaip,pdwThreadid)	\
    ( (This)->lpVtbl -> GetInputProcessorProfiles(This,dwThreadId,ppaip,pdwThreadid) ) 

#define ITfLangBarMgr_RestoreLastFocus(This,pdwThreadId,fPrev)	\
    ( (This)->lpVtbl -> RestoreLastFocus(This,pdwThreadId,fPrev) ) 

#define ITfLangBarMgr_SetModalInput(This,pSink,dwThreadId,dwFlags)	\
    ( (This)->lpVtbl -> SetModalInput(This,pSink,dwThreadId,dwFlags) ) 

#define ITfLangBarMgr_ShowFloating(This,dwFlags)	\
    ( (This)->lpVtbl -> ShowFloating(This,dwFlags) ) 

#define ITfLangBarMgr_GetShowFloatingStatus(This,pdwFlags)	\
    ( (This)->lpVtbl -> GetShowFloatingStatus(This,pdwFlags) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITfLangBarMgr_INTERFACE_DEFINED__ */


#ifndef __ITfLangBarEventSink_INTERFACE_DEFINED__
#define __ITfLangBarEventSink_INTERFACE_DEFINED__

/* interface ITfLangBarEventSink */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_ITfLangBarEventSink;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("18a4e900-e0ae-11d2-afdd-00105a2799b5")
    ITfLangBarEventSink : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnSetFocus( 
            /* [annotation][in] */ 
            _In_  DWORD dwThreadId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnThreadTerminate( 
            /* [annotation][in] */ 
            _In_  DWORD dwThreadId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnThreadItemChange( 
            /* [annotation][in] */ 
            _In_  DWORD dwThreadId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnModalInput( 
            /* [annotation][in] */ 
            _In_  DWORD dwThreadId,
            /* [annotation][in] */ 
            _In_  UINT uMsg,
            /* [annotation][in] */ 
            _In_  WPARAM wParam,
            /* [annotation][in] */ 
            _In_  LPARAM lParam) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ShowFloating( 
            /* [annotation][in] */ 
            _In_  DWORD dwFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetItemFloatingRect( 
            /* [annotation][in] */ 
            _In_  DWORD dwThreadId,
            /* [annotation][in] */ 
            _In_  REFGUID rguid,
            /* [annotation][out] */ 
            _Out_  RECT *prc) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITfLangBarEventSinkVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ITfLangBarEventSink * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ITfLangBarEventSink * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ITfLangBarEventSink * This);
        
        HRESULT ( STDMETHODCALLTYPE *OnSetFocus )( 
            __RPC__in ITfLangBarEventSink * This,
            /* [annotation][in] */ 
            _In_  DWORD dwThreadId);
        
        HRESULT ( STDMETHODCALLTYPE *OnThreadTerminate )( 
            __RPC__in ITfLangBarEventSink * This,
            /* [annotation][in] */ 
            _In_  DWORD dwThreadId);
        
        HRESULT ( STDMETHODCALLTYPE *OnThreadItemChange )( 
            __RPC__in ITfLangBarEventSink * This,
            /* [annotation][in] */ 
            _In_  DWORD dwThreadId);
        
        HRESULT ( STDMETHODCALLTYPE *OnModalInput )( 
            __RPC__in ITfLangBarEventSink * This,
            /* [annotation][in] */ 
            _In_  DWORD dwThreadId,
            /* [annotation][in] */ 
            _In_  UINT uMsg,
            /* [annotation][in] */ 
            _In_  WPARAM wParam,
            /* [annotation][in] */ 
            _In_  LPARAM lParam);
        
        HRESULT ( STDMETHODCALLTYPE *ShowFloating )( 
            __RPC__in ITfLangBarEventSink * This,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags);
        
        HRESULT ( STDMETHODCALLTYPE *GetItemFloatingRect )( 
            __RPC__in ITfLangBarEventSink * This,
            /* [annotation][in] */ 
            _In_  DWORD dwThreadId,
            /* [annotation][in] */ 
            _In_  REFGUID rguid,
            /* [annotation][out] */ 
            _Out_  RECT *prc);
        
        END_INTERFACE
    } ITfLangBarEventSinkVtbl;

    interface ITfLangBarEventSink
    {
        CONST_VTBL struct ITfLangBarEventSinkVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITfLangBarEventSink_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITfLangBarEventSink_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITfLangBarEventSink_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITfLangBarEventSink_OnSetFocus(This,dwThreadId)	\
    ( (This)->lpVtbl -> OnSetFocus(This,dwThreadId) ) 

#define ITfLangBarEventSink_OnThreadTerminate(This,dwThreadId)	\
    ( (This)->lpVtbl -> OnThreadTerminate(This,dwThreadId) ) 

#define ITfLangBarEventSink_OnThreadItemChange(This,dwThreadId)	\
    ( (This)->lpVtbl -> OnThreadItemChange(This,dwThreadId) ) 

#define ITfLangBarEventSink_OnModalInput(This,dwThreadId,uMsg,wParam,lParam)	\
    ( (This)->lpVtbl -> OnModalInput(This,dwThreadId,uMsg,wParam,lParam) ) 

#define ITfLangBarEventSink_ShowFloating(This,dwFlags)	\
    ( (This)->lpVtbl -> ShowFloating(This,dwFlags) ) 

#define ITfLangBarEventSink_GetItemFloatingRect(This,dwThreadId,rguid,prc)	\
    ( (This)->lpVtbl -> GetItemFloatingRect(This,dwThreadId,rguid,prc) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITfLangBarEventSink_INTERFACE_DEFINED__ */


#ifndef __ITfLangBarItemSink_INTERFACE_DEFINED__
#define __ITfLangBarItemSink_INTERFACE_DEFINED__

/* interface ITfLangBarItemSink */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_ITfLangBarItemSink;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("57dbe1a0-de25-11d2-afdd-00105a2799b5")
    ITfLangBarItemSink : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnUpdate( 
            /* [annotation][in] */ 
            _In_  DWORD dwFlags) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITfLangBarItemSinkVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ITfLangBarItemSink * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ITfLangBarItemSink * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ITfLangBarItemSink * This);
        
        HRESULT ( STDMETHODCALLTYPE *OnUpdate )( 
            __RPC__in ITfLangBarItemSink * This,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags);
        
        END_INTERFACE
    } ITfLangBarItemSinkVtbl;

    interface ITfLangBarItemSink
    {
        CONST_VTBL struct ITfLangBarItemSinkVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITfLangBarItemSink_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITfLangBarItemSink_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITfLangBarItemSink_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITfLangBarItemSink_OnUpdate(This,dwFlags)	\
    ( (This)->lpVtbl -> OnUpdate(This,dwFlags) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITfLangBarItemSink_INTERFACE_DEFINED__ */


#ifndef __IEnumTfLangBarItems_INTERFACE_DEFINED__
#define __IEnumTfLangBarItems_INTERFACE_DEFINED__

/* interface IEnumTfLangBarItems */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IEnumTfLangBarItems;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("583f34d0-de25-11d2-afdd-00105a2799b5")
    IEnumTfLangBarItems : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [annotation][out] */ 
            _Out_  IEnumTfLangBarItems **ppEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [annotation][in] */ 
            _In_  ULONG ulCount,
            /* [annotation][size_is][out] */ 
            _Out_writes_(ulCount)  ITfLangBarItem **ppItem,
            /* [annotation][unique][out][in] */ 
            _Inout_  ULONG *pcFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [annotation][in] */ 
            _In_  ULONG ulCount) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IEnumTfLangBarItemsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IEnumTfLangBarItems * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IEnumTfLangBarItems * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IEnumTfLangBarItems * This);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            __RPC__in IEnumTfLangBarItems * This,
            /* [annotation][out] */ 
            _Out_  IEnumTfLangBarItems **ppEnum);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            __RPC__in IEnumTfLangBarItems * This,
            /* [annotation][in] */ 
            _In_  ULONG ulCount,
            /* [annotation][size_is][out] */ 
            _Out_writes_(ulCount)  ITfLangBarItem **ppItem,
            /* [annotation][unique][out][in] */ 
            _Inout_  ULONG *pcFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            __RPC__in IEnumTfLangBarItems * This);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            __RPC__in IEnumTfLangBarItems * This,
            /* [annotation][in] */ 
            _In_  ULONG ulCount);
        
        END_INTERFACE
    } IEnumTfLangBarItemsVtbl;

    interface IEnumTfLangBarItems
    {
        CONST_VTBL struct IEnumTfLangBarItemsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumTfLangBarItems_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEnumTfLangBarItems_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEnumTfLangBarItems_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IEnumTfLangBarItems_Clone(This,ppEnum)	\
    ( (This)->lpVtbl -> Clone(This,ppEnum) ) 

#define IEnumTfLangBarItems_Next(This,ulCount,ppItem,pcFetched)	\
    ( (This)->lpVtbl -> Next(This,ulCount,ppItem,pcFetched) ) 

#define IEnumTfLangBarItems_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define IEnumTfLangBarItems_Skip(This,ulCount)	\
    ( (This)->lpVtbl -> Skip(This,ulCount) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IEnumTfLangBarItems_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_ctfutb_0000_0004 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion
#pragma region Application Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP)
#define	TF_LBI_DESC_MAXLEN	( 32 )

typedef /* [uuid] */  DECLSPEC_UUID("12a1d29f-a065-440c-9746-eb2002c8bd19") struct TF_LANGBARITEMINFO
    {
    CLSID clsidService;
    GUID guidItem;
    DWORD dwStyle;
    ULONG ulSort;
    WCHAR szDescription[ 32 ];
    } 	TF_LANGBARITEMINFO;

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP) */
#pragma endregion
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)


extern RPC_IF_HANDLE __MIDL_itf_ctfutb_0000_0004_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ctfutb_0000_0004_v0_0_s_ifspec;

#ifndef __ITfLangBarItemMgr_INTERFACE_DEFINED__
#define __ITfLangBarItemMgr_INTERFACE_DEFINED__

/* interface ITfLangBarItemMgr */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_ITfLangBarItemMgr;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("ba468c55-9956-4fb1-a59d-52a7dd7cc6aa")
    ITfLangBarItemMgr : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE EnumItems( 
            /* [annotation][out] */ 
            _Out_  IEnumTfLangBarItems **ppEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetItem( 
            /* [annotation][in] */ 
            _In_  REFGUID rguid,
            /* [annotation][out] */ 
            _Out_  ITfLangBarItem **ppItem) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddItem( 
            /* [annotation][in] */ 
            _In_  ITfLangBarItem *punk) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveItem( 
            /* [annotation][in] */ 
            _In_  ITfLangBarItem *punk) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AdviseItemSink( 
            /* [annotation][in] */ 
            _In_  ITfLangBarItemSink *punk,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwCookie,
            /* [annotation][in] */ 
            _In_  REFGUID rguidItem) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UnadviseItemSink( 
            /* [annotation][in] */ 
            _In_  DWORD dwCookie) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetItemFloatingRect( 
            /* [annotation][in] */ 
            _In_  DWORD dwThreadId,
            /* [annotation][in] */ 
            _In_  REFGUID rguid,
            /* [annotation][out] */ 
            _Out_  RECT *prc) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetItemsStatus( 
            /* [annotation][in] */ 
            _In_  ULONG ulCount,
            /* [annotation][size_is][in] */ 
            _In_reads_(ulCount)  const GUID *prgguid,
            /* [annotation][size_is][out] */ 
            _Out_writes_(ulCount)  DWORD *pdwStatus) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetItemNum( 
            /* [annotation][out] */ 
            _Out_  ULONG *pulCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetItems( 
            /* [annotation][in] */ 
            _In_  ULONG ulCount,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(ulCount,*pcFetched)  ITfLangBarItem **ppItem,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(ulCount,*pcFetched)  TF_LANGBARITEMINFO *pInfo,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(ulCount,*pcFetched)  DWORD *pdwStatus,
            /* [annotation][unique][out][in] */ 
            _Inout_  ULONG *pcFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AdviseItemsSink( 
            /* [annotation][in] */ 
            _In_  ULONG ulCount,
            /* [annotation][size_is][in] */ 
            _In_reads_(ulCount)  ITfLangBarItemSink **ppunk,
            /* [annotation][size_is][in] */ 
            _In_reads_(ulCount)  const GUID *pguidItem,
            /* [annotation][size_is][out] */ 
            _Out_writes_(ulCount)  DWORD *pdwCookie) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UnadviseItemsSink( 
            /* [annotation][in] */ 
            _In_  ULONG ulCount,
            /* [annotation][size_is][in] */ 
            _In_reads_(ulCount)  DWORD *pdwCookie) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITfLangBarItemMgrVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ITfLangBarItemMgr * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ITfLangBarItemMgr * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ITfLangBarItemMgr * This);
        
        HRESULT ( STDMETHODCALLTYPE *EnumItems )( 
            __RPC__in ITfLangBarItemMgr * This,
            /* [annotation][out] */ 
            _Out_  IEnumTfLangBarItems **ppEnum);
        
        HRESULT ( STDMETHODCALLTYPE *GetItem )( 
            __RPC__in ITfLangBarItemMgr * This,
            /* [annotation][in] */ 
            _In_  REFGUID rguid,
            /* [annotation][out] */ 
            _Out_  ITfLangBarItem **ppItem);
        
        HRESULT ( STDMETHODCALLTYPE *AddItem )( 
            __RPC__in ITfLangBarItemMgr * This,
            /* [annotation][in] */ 
            _In_  ITfLangBarItem *punk);
        
        HRESULT ( STDMETHODCALLTYPE *RemoveItem )( 
            __RPC__in ITfLangBarItemMgr * This,
            /* [annotation][in] */ 
            _In_  ITfLangBarItem *punk);
        
        HRESULT ( STDMETHODCALLTYPE *AdviseItemSink )( 
            __RPC__in ITfLangBarItemMgr * This,
            /* [annotation][in] */ 
            _In_  ITfLangBarItemSink *punk,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwCookie,
            /* [annotation][in] */ 
            _In_  REFGUID rguidItem);
        
        HRESULT ( STDMETHODCALLTYPE *UnadviseItemSink )( 
            __RPC__in ITfLangBarItemMgr * This,
            /* [annotation][in] */ 
            _In_  DWORD dwCookie);
        
        HRESULT ( STDMETHODCALLTYPE *GetItemFloatingRect )( 
            __RPC__in ITfLangBarItemMgr * This,
            /* [annotation][in] */ 
            _In_  DWORD dwThreadId,
            /* [annotation][in] */ 
            _In_  REFGUID rguid,
            /* [annotation][out] */ 
            _Out_  RECT *prc);
        
        HRESULT ( STDMETHODCALLTYPE *GetItemsStatus )( 
            __RPC__in ITfLangBarItemMgr * This,
            /* [annotation][in] */ 
            _In_  ULONG ulCount,
            /* [annotation][size_is][in] */ 
            _In_reads_(ulCount)  const GUID *prgguid,
            /* [annotation][size_is][out] */ 
            _Out_writes_(ulCount)  DWORD *pdwStatus);
        
        HRESULT ( STDMETHODCALLTYPE *GetItemNum )( 
            __RPC__in ITfLangBarItemMgr * This,
            /* [annotation][out] */ 
            _Out_  ULONG *pulCount);
        
        HRESULT ( STDMETHODCALLTYPE *GetItems )( 
            __RPC__in ITfLangBarItemMgr * This,
            /* [annotation][in] */ 
            _In_  ULONG ulCount,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(ulCount,*pcFetched)  ITfLangBarItem **ppItem,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(ulCount,*pcFetched)  TF_LANGBARITEMINFO *pInfo,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(ulCount,*pcFetched)  DWORD *pdwStatus,
            /* [annotation][unique][out][in] */ 
            _Inout_  ULONG *pcFetched);
        
        HRESULT ( STDMETHODCALLTYPE *AdviseItemsSink )( 
            __RPC__in ITfLangBarItemMgr * This,
            /* [annotation][in] */ 
            _In_  ULONG ulCount,
            /* [annotation][size_is][in] */ 
            _In_reads_(ulCount)  ITfLangBarItemSink **ppunk,
            /* [annotation][size_is][in] */ 
            _In_reads_(ulCount)  const GUID *pguidItem,
            /* [annotation][size_is][out] */ 
            _Out_writes_(ulCount)  DWORD *pdwCookie);
        
        HRESULT ( STDMETHODCALLTYPE *UnadviseItemsSink )( 
            __RPC__in ITfLangBarItemMgr * This,
            /* [annotation][in] */ 
            _In_  ULONG ulCount,
            /* [annotation][size_is][in] */ 
            _In_reads_(ulCount)  DWORD *pdwCookie);
        
        END_INTERFACE
    } ITfLangBarItemMgrVtbl;

    interface ITfLangBarItemMgr
    {
        CONST_VTBL struct ITfLangBarItemMgrVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITfLangBarItemMgr_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITfLangBarItemMgr_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITfLangBarItemMgr_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITfLangBarItemMgr_EnumItems(This,ppEnum)	\
    ( (This)->lpVtbl -> EnumItems(This,ppEnum) ) 

#define ITfLangBarItemMgr_GetItem(This,rguid,ppItem)	\
    ( (This)->lpVtbl -> GetItem(This,rguid,ppItem) ) 

#define ITfLangBarItemMgr_AddItem(This,punk)	\
    ( (This)->lpVtbl -> AddItem(This,punk) ) 

#define ITfLangBarItemMgr_RemoveItem(This,punk)	\
    ( (This)->lpVtbl -> RemoveItem(This,punk) ) 

#define ITfLangBarItemMgr_AdviseItemSink(This,punk,pdwCookie,rguidItem)	\
    ( (This)->lpVtbl -> AdviseItemSink(This,punk,pdwCookie,rguidItem) ) 

#define ITfLangBarItemMgr_UnadviseItemSink(This,dwCookie)	\
    ( (This)->lpVtbl -> UnadviseItemSink(This,dwCookie) ) 

#define ITfLangBarItemMgr_GetItemFloatingRect(This,dwThreadId,rguid,prc)	\
    ( (This)->lpVtbl -> GetItemFloatingRect(This,dwThreadId,rguid,prc) ) 

#define ITfLangBarItemMgr_GetItemsStatus(This,ulCount,prgguid,pdwStatus)	\
    ( (This)->lpVtbl -> GetItemsStatus(This,ulCount,prgguid,pdwStatus) ) 

#define ITfLangBarItemMgr_GetItemNum(This,pulCount)	\
    ( (This)->lpVtbl -> GetItemNum(This,pulCount) ) 

#define ITfLangBarItemMgr_GetItems(This,ulCount,ppItem,pInfo,pdwStatus,pcFetched)	\
    ( (This)->lpVtbl -> GetItems(This,ulCount,ppItem,pInfo,pdwStatus,pcFetched) ) 

#define ITfLangBarItemMgr_AdviseItemsSink(This,ulCount,ppunk,pguidItem,pdwCookie)	\
    ( (This)->lpVtbl -> AdviseItemsSink(This,ulCount,ppunk,pguidItem,pdwCookie) ) 

#define ITfLangBarItemMgr_UnadviseItemsSink(This,ulCount,pdwCookie)	\
    ( (This)->lpVtbl -> UnadviseItemsSink(This,ulCount,pdwCookie) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITfLangBarItemMgr_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_ctfutb_0000_0005 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion
#pragma region Application Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP)


extern RPC_IF_HANDLE __MIDL_itf_ctfutb_0000_0005_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ctfutb_0000_0005_v0_0_s_ifspec;

#ifndef __ITfLangBarItem_INTERFACE_DEFINED__
#define __ITfLangBarItem_INTERFACE_DEFINED__

/* interface ITfLangBarItem */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_ITfLangBarItem;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("73540d69-edeb-4ee9-96c9-23aa30b25916")
    ITfLangBarItem : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetInfo( 
            /* [annotation][out] */ 
            _Out_  TF_LANGBARITEMINFO *pInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStatus( 
            /* [annotation][out] */ 
            _Out_  DWORD *pdwStatus) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Show( 
            /* [annotation][in] */ 
            _In_  BOOL fShow) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTooltipString( 
            /* [annotation][out] */ 
            _Out_  BSTR *pbstrToolTip) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITfLangBarItemVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ITfLangBarItem * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ITfLangBarItem * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ITfLangBarItem * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetInfo )( 
            __RPC__in ITfLangBarItem * This,
            /* [annotation][out] */ 
            _Out_  TF_LANGBARITEMINFO *pInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetStatus )( 
            __RPC__in ITfLangBarItem * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwStatus);
        
        HRESULT ( STDMETHODCALLTYPE *Show )( 
            __RPC__in ITfLangBarItem * This,
            /* [annotation][in] */ 
            _In_  BOOL fShow);
        
        HRESULT ( STDMETHODCALLTYPE *GetTooltipString )( 
            __RPC__in ITfLangBarItem * This,
            /* [annotation][out] */ 
            _Out_  BSTR *pbstrToolTip);
        
        END_INTERFACE
    } ITfLangBarItemVtbl;

    interface ITfLangBarItem
    {
        CONST_VTBL struct ITfLangBarItemVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITfLangBarItem_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITfLangBarItem_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITfLangBarItem_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITfLangBarItem_GetInfo(This,pInfo)	\
    ( (This)->lpVtbl -> GetInfo(This,pInfo) ) 

#define ITfLangBarItem_GetStatus(This,pdwStatus)	\
    ( (This)->lpVtbl -> GetStatus(This,pdwStatus) ) 

#define ITfLangBarItem_Show(This,fShow)	\
    ( (This)->lpVtbl -> Show(This,fShow) ) 

#define ITfLangBarItem_GetTooltipString(This,pbstrToolTip)	\
    ( (This)->lpVtbl -> GetTooltipString(This,pbstrToolTip) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITfLangBarItem_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_ctfutb_0000_0006 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP) */
#pragma endregion
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)


extern RPC_IF_HANDLE __MIDL_itf_ctfutb_0000_0006_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ctfutb_0000_0006_v0_0_s_ifspec;

#ifndef __ITfSystemLangBarItemSink_INTERFACE_DEFINED__
#define __ITfSystemLangBarItemSink_INTERFACE_DEFINED__

/* interface ITfSystemLangBarItemSink */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_ITfSystemLangBarItemSink;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1449d9ab-13cf-4687-aa3e-8d8b18574396")
    ITfSystemLangBarItemSink : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE InitMenu( 
            /* [annotation][in] */ 
            _In_  ITfMenu *pMenu) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnMenuSelect( 
            /* [annotation][in] */ 
            _In_  UINT wID) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITfSystemLangBarItemSinkVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ITfSystemLangBarItemSink * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ITfSystemLangBarItemSink * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ITfSystemLangBarItemSink * This);
        
        HRESULT ( STDMETHODCALLTYPE *InitMenu )( 
            __RPC__in ITfSystemLangBarItemSink * This,
            /* [annotation][in] */ 
            _In_  ITfMenu *pMenu);
        
        HRESULT ( STDMETHODCALLTYPE *OnMenuSelect )( 
            __RPC__in ITfSystemLangBarItemSink * This,
            /* [annotation][in] */ 
            _In_  UINT wID);
        
        END_INTERFACE
    } ITfSystemLangBarItemSinkVtbl;

    interface ITfSystemLangBarItemSink
    {
        CONST_VTBL struct ITfSystemLangBarItemSinkVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITfSystemLangBarItemSink_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITfSystemLangBarItemSink_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITfSystemLangBarItemSink_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITfSystemLangBarItemSink_InitMenu(This,pMenu)	\
    ( (This)->lpVtbl -> InitMenu(This,pMenu) ) 

#define ITfSystemLangBarItemSink_OnMenuSelect(This,wID)	\
    ( (This)->lpVtbl -> OnMenuSelect(This,wID) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITfSystemLangBarItemSink_INTERFACE_DEFINED__ */


#ifndef __ITfSystemLangBarItem_INTERFACE_DEFINED__
#define __ITfSystemLangBarItem_INTERFACE_DEFINED__

/* interface ITfSystemLangBarItem */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_ITfSystemLangBarItem;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1e13e9ec-6b33-4d4a-b5eb-8a92f029f356")
    ITfSystemLangBarItem : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetIcon( 
            /* [annotation][in] */ 
            _In_  HICON hIcon) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetTooltipString( 
            /* [annotation][size_is][in] */ 
            _In_reads_(cch)  WCHAR *pchToolTip,
            /* [annotation][in] */ 
            _In_  ULONG cch) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITfSystemLangBarItemVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ITfSystemLangBarItem * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ITfSystemLangBarItem * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ITfSystemLangBarItem * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetIcon )( 
            __RPC__in ITfSystemLangBarItem * This,
            /* [annotation][in] */ 
            _In_  HICON hIcon);
        
        HRESULT ( STDMETHODCALLTYPE *SetTooltipString )( 
            __RPC__in ITfSystemLangBarItem * This,
            /* [annotation][size_is][in] */ 
            _In_reads_(cch)  WCHAR *pchToolTip,
            /* [annotation][in] */ 
            _In_  ULONG cch);
        
        END_INTERFACE
    } ITfSystemLangBarItemVtbl;

    interface ITfSystemLangBarItem
    {
        CONST_VTBL struct ITfSystemLangBarItemVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITfSystemLangBarItem_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITfSystemLangBarItem_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITfSystemLangBarItem_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITfSystemLangBarItem_SetIcon(This,hIcon)	\
    ( (This)->lpVtbl -> SetIcon(This,hIcon) ) 

#define ITfSystemLangBarItem_SetTooltipString(This,pchToolTip,cch)	\
    ( (This)->lpVtbl -> SetTooltipString(This,pchToolTip,cch) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITfSystemLangBarItem_INTERFACE_DEFINED__ */


#ifndef __ITfSystemLangBarItemText_INTERFACE_DEFINED__
#define __ITfSystemLangBarItemText_INTERFACE_DEFINED__

/* interface ITfSystemLangBarItemText */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_ITfSystemLangBarItemText;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5c4ce0e5-ba49-4b52-ac6b-3b397b4f701f")
    ITfSystemLangBarItemText : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetItemText( 
            /* [annotation][size_is][in] */ 
            _In_reads_(cch)  const WCHAR *pch,
            /* [annotation][in] */ 
            _In_  ULONG cch) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetItemText( 
            /* [annotation][out] */ 
            _Out_  BSTR *pbstrText) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITfSystemLangBarItemTextVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ITfSystemLangBarItemText * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ITfSystemLangBarItemText * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ITfSystemLangBarItemText * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetItemText )( 
            __RPC__in ITfSystemLangBarItemText * This,
            /* [annotation][size_is][in] */ 
            _In_reads_(cch)  const WCHAR *pch,
            /* [annotation][in] */ 
            _In_  ULONG cch);
        
        HRESULT ( STDMETHODCALLTYPE *GetItemText )( 
            __RPC__in ITfSystemLangBarItemText * This,
            /* [annotation][out] */ 
            _Out_  BSTR *pbstrText);
        
        END_INTERFACE
    } ITfSystemLangBarItemTextVtbl;

    interface ITfSystemLangBarItemText
    {
        CONST_VTBL struct ITfSystemLangBarItemTextVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITfSystemLangBarItemText_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITfSystemLangBarItemText_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITfSystemLangBarItemText_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITfSystemLangBarItemText_SetItemText(This,pch,cch)	\
    ( (This)->lpVtbl -> SetItemText(This,pch,cch) ) 

#define ITfSystemLangBarItemText_GetItemText(This,pbstrText)	\
    ( (This)->lpVtbl -> GetItemText(This,pbstrText) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITfSystemLangBarItemText_INTERFACE_DEFINED__ */


#ifndef __ITfSystemDeviceTypeLangBarItem_INTERFACE_DEFINED__
#define __ITfSystemDeviceTypeLangBarItem_INTERFACE_DEFINED__

/* interface ITfSystemDeviceTypeLangBarItem */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_ITfSystemDeviceTypeLangBarItem;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("45672eb9-9059-46a2-838d-4530355f6a77")
    ITfSystemDeviceTypeLangBarItem : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetIconMode( 
            /* [annotation][in] */ 
            _In_  DWORD dwFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetIconMode( 
            /* [annotation][out] */ 
            _Out_  DWORD *pdwFlags) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITfSystemDeviceTypeLangBarItemVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ITfSystemDeviceTypeLangBarItem * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ITfSystemDeviceTypeLangBarItem * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ITfSystemDeviceTypeLangBarItem * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetIconMode )( 
            __RPC__in ITfSystemDeviceTypeLangBarItem * This,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags);
        
        HRESULT ( STDMETHODCALLTYPE *GetIconMode )( 
            __RPC__in ITfSystemDeviceTypeLangBarItem * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwFlags);
        
        END_INTERFACE
    } ITfSystemDeviceTypeLangBarItemVtbl;

    interface ITfSystemDeviceTypeLangBarItem
    {
        CONST_VTBL struct ITfSystemDeviceTypeLangBarItemVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITfSystemDeviceTypeLangBarItem_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITfSystemDeviceTypeLangBarItem_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITfSystemDeviceTypeLangBarItem_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITfSystemDeviceTypeLangBarItem_SetIconMode(This,dwFlags)	\
    ( (This)->lpVtbl -> SetIconMode(This,dwFlags) ) 

#define ITfSystemDeviceTypeLangBarItem_GetIconMode(This,pdwFlags)	\
    ( (This)->lpVtbl -> GetIconMode(This,pdwFlags) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITfSystemDeviceTypeLangBarItem_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_ctfutb_0000_0010 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion
#pragma region Application Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP)
typedef /* [public][public][public][public][public][uuid] */  DECLSPEC_UUID("8fb5f0ce-dfdd-4f0a-85b9-8988d8dd8ff2") 
enum __MIDL___MIDL_itf_ctfutb_0000_0010_0001
    {
        TF_LBI_CLK_RIGHT	= 1,
        TF_LBI_CLK_LEFT	= 2
    } 	TfLBIClick;

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP) */
#pragma endregion
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)


extern RPC_IF_HANDLE __MIDL_itf_ctfutb_0000_0010_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ctfutb_0000_0010_v0_0_s_ifspec;

#ifndef __ITfLangBarItemButton_INTERFACE_DEFINED__
#define __ITfLangBarItemButton_INTERFACE_DEFINED__

/* interface ITfLangBarItemButton */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_ITfLangBarItemButton;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("28c7f1d0-de25-11d2-afdd-00105a2799b5")
    ITfLangBarItemButton : public ITfLangBarItem
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnClick( 
            /* [annotation][in] */ 
            _In_  TfLBIClick click,
            /* [annotation][in] */ 
            _In_  POINT pt,
            /* [annotation][in] */ 
            _In_  const RECT *prcArea) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InitMenu( 
            /* [annotation][in] */ 
            _In_  ITfMenu *pMenu) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnMenuSelect( 
            /* [annotation][in] */ 
            _In_  UINT wID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetIcon( 
            /* [annotation][out] */ 
            _Out_  HICON *phIcon) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetText( 
            /* [annotation][out] */ 
            _Out_  BSTR *pbstrText) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITfLangBarItemButtonVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ITfLangBarItemButton * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ITfLangBarItemButton * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ITfLangBarItemButton * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetInfo )( 
            __RPC__in ITfLangBarItemButton * This,
            /* [annotation][out] */ 
            _Out_  TF_LANGBARITEMINFO *pInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetStatus )( 
            __RPC__in ITfLangBarItemButton * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwStatus);
        
        HRESULT ( STDMETHODCALLTYPE *Show )( 
            __RPC__in ITfLangBarItemButton * This,
            /* [annotation][in] */ 
            _In_  BOOL fShow);
        
        HRESULT ( STDMETHODCALLTYPE *GetTooltipString )( 
            __RPC__in ITfLangBarItemButton * This,
            /* [annotation][out] */ 
            _Out_  BSTR *pbstrToolTip);
        
        HRESULT ( STDMETHODCALLTYPE *OnClick )( 
            __RPC__in ITfLangBarItemButton * This,
            /* [annotation][in] */ 
            _In_  TfLBIClick click,
            /* [annotation][in] */ 
            _In_  POINT pt,
            /* [annotation][in] */ 
            _In_  const RECT *prcArea);
        
        HRESULT ( STDMETHODCALLTYPE *InitMenu )( 
            __RPC__in ITfLangBarItemButton * This,
            /* [annotation][in] */ 
            _In_  ITfMenu *pMenu);
        
        HRESULT ( STDMETHODCALLTYPE *OnMenuSelect )( 
            __RPC__in ITfLangBarItemButton * This,
            /* [annotation][in] */ 
            _In_  UINT wID);
        
        HRESULT ( STDMETHODCALLTYPE *GetIcon )( 
            __RPC__in ITfLangBarItemButton * This,
            /* [annotation][out] */ 
            _Out_  HICON *phIcon);
        
        HRESULT ( STDMETHODCALLTYPE *GetText )( 
            __RPC__in ITfLangBarItemButton * This,
            /* [annotation][out] */ 
            _Out_  BSTR *pbstrText);
        
        END_INTERFACE
    } ITfLangBarItemButtonVtbl;

    interface ITfLangBarItemButton
    {
        CONST_VTBL struct ITfLangBarItemButtonVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITfLangBarItemButton_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITfLangBarItemButton_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITfLangBarItemButton_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITfLangBarItemButton_GetInfo(This,pInfo)	\
    ( (This)->lpVtbl -> GetInfo(This,pInfo) ) 

#define ITfLangBarItemButton_GetStatus(This,pdwStatus)	\
    ( (This)->lpVtbl -> GetStatus(This,pdwStatus) ) 

#define ITfLangBarItemButton_Show(This,fShow)	\
    ( (This)->lpVtbl -> Show(This,fShow) ) 

#define ITfLangBarItemButton_GetTooltipString(This,pbstrToolTip)	\
    ( (This)->lpVtbl -> GetTooltipString(This,pbstrToolTip) ) 


#define ITfLangBarItemButton_OnClick(This,click,pt,prcArea)	\
    ( (This)->lpVtbl -> OnClick(This,click,pt,prcArea) ) 

#define ITfLangBarItemButton_InitMenu(This,pMenu)	\
    ( (This)->lpVtbl -> InitMenu(This,pMenu) ) 

#define ITfLangBarItemButton_OnMenuSelect(This,wID)	\
    ( (This)->lpVtbl -> OnMenuSelect(This,wID) ) 

#define ITfLangBarItemButton_GetIcon(This,phIcon)	\
    ( (This)->lpVtbl -> GetIcon(This,phIcon) ) 

#define ITfLangBarItemButton_GetText(This,pbstrText)	\
    ( (This)->lpVtbl -> GetText(This,pbstrText) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITfLangBarItemButton_INTERFACE_DEFINED__ */


#ifndef __ITfLangBarItemBitmapButton_INTERFACE_DEFINED__
#define __ITfLangBarItemBitmapButton_INTERFACE_DEFINED__

/* interface ITfLangBarItemBitmapButton */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_ITfLangBarItemBitmapButton;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("a26a0525-3fae-4fa0-89ee-88a964f9f1b5")
    ITfLangBarItemBitmapButton : public ITfLangBarItem
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnClick( 
            /* [annotation][in] */ 
            _In_  TfLBIClick click,
            /* [annotation][in] */ 
            _In_  POINT pt,
            /* [annotation][in] */ 
            _In_  const RECT *prcArea) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InitMenu( 
            /* [annotation][in] */ 
            _In_  ITfMenu *pMenu) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnMenuSelect( 
            /* [annotation][in] */ 
            _In_  UINT wID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPreferredSize( 
            /* [annotation][in] */ 
            _In_  const SIZE *pszDefault,
            /* [annotation][out] */ 
            _Out_  SIZE *psz) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DrawBitmap( 
            /* [annotation][in] */ 
            _In_  LONG bmWidth,
            /* [annotation][in] */ 
            _In_  LONG bmHeight,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][out] */ 
            _Out_  HBITMAP *phbmp,
            /* [annotation][out] */ 
            _Out_  HBITMAP *phbmpMask) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetText( 
            /* [annotation][out] */ 
            _Out_  BSTR *pbstrText) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITfLangBarItemBitmapButtonVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ITfLangBarItemBitmapButton * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ITfLangBarItemBitmapButton * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ITfLangBarItemBitmapButton * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetInfo )( 
            __RPC__in ITfLangBarItemBitmapButton * This,
            /* [annotation][out] */ 
            _Out_  TF_LANGBARITEMINFO *pInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetStatus )( 
            __RPC__in ITfLangBarItemBitmapButton * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwStatus);
        
        HRESULT ( STDMETHODCALLTYPE *Show )( 
            __RPC__in ITfLangBarItemBitmapButton * This,
            /* [annotation][in] */ 
            _In_  BOOL fShow);
        
        HRESULT ( STDMETHODCALLTYPE *GetTooltipString )( 
            __RPC__in ITfLangBarItemBitmapButton * This,
            /* [annotation][out] */ 
            _Out_  BSTR *pbstrToolTip);
        
        HRESULT ( STDMETHODCALLTYPE *OnClick )( 
            __RPC__in ITfLangBarItemBitmapButton * This,
            /* [annotation][in] */ 
            _In_  TfLBIClick click,
            /* [annotation][in] */ 
            _In_  POINT pt,
            /* [annotation][in] */ 
            _In_  const RECT *prcArea);
        
        HRESULT ( STDMETHODCALLTYPE *InitMenu )( 
            __RPC__in ITfLangBarItemBitmapButton * This,
            /* [annotation][in] */ 
            _In_  ITfMenu *pMenu);
        
        HRESULT ( STDMETHODCALLTYPE *OnMenuSelect )( 
            __RPC__in ITfLangBarItemBitmapButton * This,
            /* [annotation][in] */ 
            _In_  UINT wID);
        
        HRESULT ( STDMETHODCALLTYPE *GetPreferredSize )( 
            __RPC__in ITfLangBarItemBitmapButton * This,
            /* [annotation][in] */ 
            _In_  const SIZE *pszDefault,
            /* [annotation][out] */ 
            _Out_  SIZE *psz);
        
        HRESULT ( STDMETHODCALLTYPE *DrawBitmap )( 
            __RPC__in ITfLangBarItemBitmapButton * This,
            /* [annotation][in] */ 
            _In_  LONG bmWidth,
            /* [annotation][in] */ 
            _In_  LONG bmHeight,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][out] */ 
            _Out_  HBITMAP *phbmp,
            /* [annotation][out] */ 
            _Out_  HBITMAP *phbmpMask);
        
        HRESULT ( STDMETHODCALLTYPE *GetText )( 
            __RPC__in ITfLangBarItemBitmapButton * This,
            /* [annotation][out] */ 
            _Out_  BSTR *pbstrText);
        
        END_INTERFACE
    } ITfLangBarItemBitmapButtonVtbl;

    interface ITfLangBarItemBitmapButton
    {
        CONST_VTBL struct ITfLangBarItemBitmapButtonVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITfLangBarItemBitmapButton_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITfLangBarItemBitmapButton_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITfLangBarItemBitmapButton_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITfLangBarItemBitmapButton_GetInfo(This,pInfo)	\
    ( (This)->lpVtbl -> GetInfo(This,pInfo) ) 

#define ITfLangBarItemBitmapButton_GetStatus(This,pdwStatus)	\
    ( (This)->lpVtbl -> GetStatus(This,pdwStatus) ) 

#define ITfLangBarItemBitmapButton_Show(This,fShow)	\
    ( (This)->lpVtbl -> Show(This,fShow) ) 

#define ITfLangBarItemBitmapButton_GetTooltipString(This,pbstrToolTip)	\
    ( (This)->lpVtbl -> GetTooltipString(This,pbstrToolTip) ) 


#define ITfLangBarItemBitmapButton_OnClick(This,click,pt,prcArea)	\
    ( (This)->lpVtbl -> OnClick(This,click,pt,prcArea) ) 

#define ITfLangBarItemBitmapButton_InitMenu(This,pMenu)	\
    ( (This)->lpVtbl -> InitMenu(This,pMenu) ) 

#define ITfLangBarItemBitmapButton_OnMenuSelect(This,wID)	\
    ( (This)->lpVtbl -> OnMenuSelect(This,wID) ) 

#define ITfLangBarItemBitmapButton_GetPreferredSize(This,pszDefault,psz)	\
    ( (This)->lpVtbl -> GetPreferredSize(This,pszDefault,psz) ) 

#define ITfLangBarItemBitmapButton_DrawBitmap(This,bmWidth,bmHeight,dwFlags,phbmp,phbmpMask)	\
    ( (This)->lpVtbl -> DrawBitmap(This,bmWidth,bmHeight,dwFlags,phbmp,phbmpMask) ) 

#define ITfLangBarItemBitmapButton_GetText(This,pbstrText)	\
    ( (This)->lpVtbl -> GetText(This,pbstrText) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITfLangBarItemBitmapButton_INTERFACE_DEFINED__ */


#ifndef __ITfLangBarItemBitmap_INTERFACE_DEFINED__
#define __ITfLangBarItemBitmap_INTERFACE_DEFINED__

/* interface ITfLangBarItemBitmap */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_ITfLangBarItemBitmap;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("73830352-d722-4179-ada5-f045c98df355")
    ITfLangBarItemBitmap : public ITfLangBarItem
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnClick( 
            /* [annotation][in] */ 
            _In_  TfLBIClick click,
            /* [annotation][in] */ 
            _In_  POINT pt,
            /* [annotation][in] */ 
            _In_  const RECT *prcArea) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPreferredSize( 
            /* [annotation][in] */ 
            _In_  const SIZE *pszDefault,
            /* [annotation][out] */ 
            _Out_  SIZE *psz) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DrawBitmap( 
            /* [annotation][in] */ 
            _In_  LONG bmWidth,
            /* [annotation][in] */ 
            _In_  LONG bmHeight,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][out] */ 
            _Out_  HBITMAP *phbmp,
            /* [annotation][out] */ 
            _Out_  HBITMAP *phbmpMask) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITfLangBarItemBitmapVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ITfLangBarItemBitmap * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ITfLangBarItemBitmap * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ITfLangBarItemBitmap * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetInfo )( 
            __RPC__in ITfLangBarItemBitmap * This,
            /* [annotation][out] */ 
            _Out_  TF_LANGBARITEMINFO *pInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetStatus )( 
            __RPC__in ITfLangBarItemBitmap * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwStatus);
        
        HRESULT ( STDMETHODCALLTYPE *Show )( 
            __RPC__in ITfLangBarItemBitmap * This,
            /* [annotation][in] */ 
            _In_  BOOL fShow);
        
        HRESULT ( STDMETHODCALLTYPE *GetTooltipString )( 
            __RPC__in ITfLangBarItemBitmap * This,
            /* [annotation][out] */ 
            _Out_  BSTR *pbstrToolTip);
        
        HRESULT ( STDMETHODCALLTYPE *OnClick )( 
            __RPC__in ITfLangBarItemBitmap * This,
            /* [annotation][in] */ 
            _In_  TfLBIClick click,
            /* [annotation][in] */ 
            _In_  POINT pt,
            /* [annotation][in] */ 
            _In_  const RECT *prcArea);
        
        HRESULT ( STDMETHODCALLTYPE *GetPreferredSize )( 
            __RPC__in ITfLangBarItemBitmap * This,
            /* [annotation][in] */ 
            _In_  const SIZE *pszDefault,
            /* [annotation][out] */ 
            _Out_  SIZE *psz);
        
        HRESULT ( STDMETHODCALLTYPE *DrawBitmap )( 
            __RPC__in ITfLangBarItemBitmap * This,
            /* [annotation][in] */ 
            _In_  LONG bmWidth,
            /* [annotation][in] */ 
            _In_  LONG bmHeight,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][out] */ 
            _Out_  HBITMAP *phbmp,
            /* [annotation][out] */ 
            _Out_  HBITMAP *phbmpMask);
        
        END_INTERFACE
    } ITfLangBarItemBitmapVtbl;

    interface ITfLangBarItemBitmap
    {
        CONST_VTBL struct ITfLangBarItemBitmapVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITfLangBarItemBitmap_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITfLangBarItemBitmap_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITfLangBarItemBitmap_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITfLangBarItemBitmap_GetInfo(This,pInfo)	\
    ( (This)->lpVtbl -> GetInfo(This,pInfo) ) 

#define ITfLangBarItemBitmap_GetStatus(This,pdwStatus)	\
    ( (This)->lpVtbl -> GetStatus(This,pdwStatus) ) 

#define ITfLangBarItemBitmap_Show(This,fShow)	\
    ( (This)->lpVtbl -> Show(This,fShow) ) 

#define ITfLangBarItemBitmap_GetTooltipString(This,pbstrToolTip)	\
    ( (This)->lpVtbl -> GetTooltipString(This,pbstrToolTip) ) 


#define ITfLangBarItemBitmap_OnClick(This,click,pt,prcArea)	\
    ( (This)->lpVtbl -> OnClick(This,click,pt,prcArea) ) 

#define ITfLangBarItemBitmap_GetPreferredSize(This,pszDefault,psz)	\
    ( (This)->lpVtbl -> GetPreferredSize(This,pszDefault,psz) ) 

#define ITfLangBarItemBitmap_DrawBitmap(This,bmWidth,bmHeight,dwFlags,phbmp,phbmpMask)	\
    ( (This)->lpVtbl -> DrawBitmap(This,bmWidth,bmHeight,dwFlags,phbmp,phbmpMask) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITfLangBarItemBitmap_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_ctfutb_0000_0013 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion
#pragma region Application Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP)


extern RPC_IF_HANDLE __MIDL_itf_ctfutb_0000_0013_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ctfutb_0000_0013_v0_0_s_ifspec;

#ifndef __ITfLangBarItemBalloon_INTERFACE_DEFINED__
#define __ITfLangBarItemBalloon_INTERFACE_DEFINED__

/* interface ITfLangBarItemBalloon */
/* [unique][uuid][object] */ 

typedef /* [public][public][public][uuid] */  DECLSPEC_UUID("f399a969-9e97-4ddd-b974-2bfb934cfbc9") 
enum __MIDL_ITfLangBarItemBalloon_0001
    {
        TF_LB_BALLOON_RECO	= 0,
        TF_LB_BALLOON_SHOW	= 1,
        TF_LB_BALLOON_MISS	= 2
    } 	TfLBBalloonStyle;

typedef /* [uuid] */  DECLSPEC_UUID("37574483-5c50-4092-a55c-922e3a67e5b8") struct TF_LBBALLOONINFO
    {
    TfLBBalloonStyle style;
    BSTR bstrText;
    } 	TF_LBBALLOONINFO;


EXTERN_C const IID IID_ITfLangBarItemBalloon;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("01C2D285-D3C7-4B7B-B5B5-D97411D0C283")
    ITfLangBarItemBalloon : public ITfLangBarItem
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnClick( 
            /* [annotation][in] */ 
            _In_  TfLBIClick click,
            /* [annotation][in] */ 
            _In_  POINT pt,
            /* [annotation][in] */ 
            _In_  const RECT *prcArea) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPreferredSize( 
            /* [annotation][in] */ 
            _In_  const SIZE *pszDefault,
            /* [annotation][out] */ 
            _Out_  SIZE *psz) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBalloonInfo( 
            /* [annotation][out] */ 
            _Out_  TF_LBBALLOONINFO *pInfo) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITfLangBarItemBalloonVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ITfLangBarItemBalloon * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ITfLangBarItemBalloon * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ITfLangBarItemBalloon * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetInfo )( 
            __RPC__in ITfLangBarItemBalloon * This,
            /* [annotation][out] */ 
            _Out_  TF_LANGBARITEMINFO *pInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetStatus )( 
            __RPC__in ITfLangBarItemBalloon * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwStatus);
        
        HRESULT ( STDMETHODCALLTYPE *Show )( 
            __RPC__in ITfLangBarItemBalloon * This,
            /* [annotation][in] */ 
            _In_  BOOL fShow);
        
        HRESULT ( STDMETHODCALLTYPE *GetTooltipString )( 
            __RPC__in ITfLangBarItemBalloon * This,
            /* [annotation][out] */ 
            _Out_  BSTR *pbstrToolTip);
        
        HRESULT ( STDMETHODCALLTYPE *OnClick )( 
            __RPC__in ITfLangBarItemBalloon * This,
            /* [annotation][in] */ 
            _In_  TfLBIClick click,
            /* [annotation][in] */ 
            _In_  POINT pt,
            /* [annotation][in] */ 
            _In_  const RECT *prcArea);
        
        HRESULT ( STDMETHODCALLTYPE *GetPreferredSize )( 
            __RPC__in ITfLangBarItemBalloon * This,
            /* [annotation][in] */ 
            _In_  const SIZE *pszDefault,
            /* [annotation][out] */ 
            _Out_  SIZE *psz);
        
        HRESULT ( STDMETHODCALLTYPE *GetBalloonInfo )( 
            __RPC__in ITfLangBarItemBalloon * This,
            /* [annotation][out] */ 
            _Out_  TF_LBBALLOONINFO *pInfo);
        
        END_INTERFACE
    } ITfLangBarItemBalloonVtbl;

    interface ITfLangBarItemBalloon
    {
        CONST_VTBL struct ITfLangBarItemBalloonVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITfLangBarItemBalloon_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITfLangBarItemBalloon_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITfLangBarItemBalloon_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITfLangBarItemBalloon_GetInfo(This,pInfo)	\
    ( (This)->lpVtbl -> GetInfo(This,pInfo) ) 

#define ITfLangBarItemBalloon_GetStatus(This,pdwStatus)	\
    ( (This)->lpVtbl -> GetStatus(This,pdwStatus) ) 

#define ITfLangBarItemBalloon_Show(This,fShow)	\
    ( (This)->lpVtbl -> Show(This,fShow) ) 

#define ITfLangBarItemBalloon_GetTooltipString(This,pbstrToolTip)	\
    ( (This)->lpVtbl -> GetTooltipString(This,pbstrToolTip) ) 


#define ITfLangBarItemBalloon_OnClick(This,click,pt,prcArea)	\
    ( (This)->lpVtbl -> OnClick(This,click,pt,prcArea) ) 

#define ITfLangBarItemBalloon_GetPreferredSize(This,pszDefault,psz)	\
    ( (This)->lpVtbl -> GetPreferredSize(This,pszDefault,psz) ) 

#define ITfLangBarItemBalloon_GetBalloonInfo(This,pInfo)	\
    ( (This)->lpVtbl -> GetBalloonInfo(This,pInfo) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITfLangBarItemBalloon_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_ctfutb_0000_0014 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP) */
#pragma endregion
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)


extern RPC_IF_HANDLE __MIDL_itf_ctfutb_0000_0014_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ctfutb_0000_0014_v0_0_s_ifspec;

#ifndef __ITfMenu_INTERFACE_DEFINED__
#define __ITfMenu_INTERFACE_DEFINED__

/* interface ITfMenu */
/* [unique][uuid][object] */ 

#define	TF_LBMENUF_CHECKED	( 0x1 )

#define	TF_LBMENUF_SUBMENU	( 0x2 )

#define	TF_LBMENUF_SEPARATOR	( 0x4 )

#define	TF_LBMENUF_RADIOCHECKED	( 0x8 )

#define	TF_LBMENUF_GRAYED	( 0x10 )


EXTERN_C const IID IID_ITfMenu;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6F8A98E4-AAA0-4F15-8C5B-07E0DF0A3DD8")
    ITfMenu : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AddMenuItem( 
            /* [annotation][in] */ 
            _In_  UINT uId,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][in] */ 
            _In_  HBITMAP hbmp,
            /* [annotation][in] */ 
            _In_  HBITMAP hbmpMask,
            /* [annotation][size_is][unique][in] */ 
            _In_reads_(cch)  const WCHAR *pch,
            /* [annotation][in] */ 
            _In_  ULONG cch,
            /* [annotation][unique][out][in] */ 
            _Inout_  ITfMenu **ppMenu) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITfMenuVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ITfMenu * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ITfMenu * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ITfMenu * This);
        
        HRESULT ( STDMETHODCALLTYPE *AddMenuItem )( 
            __RPC__in ITfMenu * This,
            /* [annotation][in] */ 
            _In_  UINT uId,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][in] */ 
            _In_  HBITMAP hbmp,
            /* [annotation][in] */ 
            _In_  HBITMAP hbmpMask,
            /* [annotation][size_is][unique][in] */ 
            _In_reads_(cch)  const WCHAR *pch,
            /* [annotation][in] */ 
            _In_  ULONG cch,
            /* [annotation][unique][out][in] */ 
            _Inout_  ITfMenu **ppMenu);
        
        END_INTERFACE
    } ITfMenuVtbl;

    interface ITfMenu
    {
        CONST_VTBL struct ITfMenuVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITfMenu_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITfMenu_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITfMenu_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITfMenu_AddMenuItem(This,uId,dwFlags,hbmp,hbmpMask,pch,cch,ppMenu)	\
    ( (This)->lpVtbl -> AddMenuItem(This,uId,dwFlags,hbmp,hbmpMask,pch,cch,ppMenu) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITfMenu_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_ctfutb_0000_0015 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion
#endif // CTFUTB_DEFINED


extern RPC_IF_HANDLE __MIDL_itf_ctfutb_0000_0015_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ctfutb_0000_0015_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     __RPC__in unsigned long *, unsigned long            , __RPC__in BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     __RPC__in unsigned long *, __RPC__in BSTR * ); 

unsigned long             __RPC_USER  HBITMAP_UserSize(     __RPC__in unsigned long *, unsigned long            , __RPC__in HBITMAP * ); 
unsigned char * __RPC_USER  HBITMAP_UserMarshal(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in HBITMAP * ); 
unsigned char * __RPC_USER  HBITMAP_UserUnmarshal(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out HBITMAP * ); 
void                      __RPC_USER  HBITMAP_UserFree(     __RPC__in unsigned long *, __RPC__in HBITMAP * ); 

unsigned long             __RPC_USER  HICON_UserSize(     __RPC__in unsigned long *, unsigned long            , __RPC__in HICON * ); 
unsigned char * __RPC_USER  HICON_UserMarshal(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in HICON * ); 
unsigned char * __RPC_USER  HICON_UserUnmarshal(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out HICON * ); 
void                      __RPC_USER  HICON_UserFree(     __RPC__in unsigned long *, __RPC__in HICON * ); 

unsigned long             __RPC_USER  HWND_UserSize(     __RPC__in unsigned long *, unsigned long            , __RPC__in HWND * ); 
unsigned char * __RPC_USER  HWND_UserMarshal(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in HWND * ); 
unsigned char * __RPC_USER  HWND_UserUnmarshal(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out HWND * ); 
void                      __RPC_USER  HWND_UserFree(     __RPC__in unsigned long *, __RPC__in HWND * ); 

unsigned long             __RPC_USER  BSTR_UserSize64(     __RPC__in unsigned long *, unsigned long            , __RPC__in BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal64(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal64(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out BSTR * ); 
void                      __RPC_USER  BSTR_UserFree64(     __RPC__in unsigned long *, __RPC__in BSTR * ); 

unsigned long             __RPC_USER  HBITMAP_UserSize64(     __RPC__in unsigned long *, unsigned long            , __RPC__in HBITMAP * ); 
unsigned char * __RPC_USER  HBITMAP_UserMarshal64(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in HBITMAP * ); 
unsigned char * __RPC_USER  HBITMAP_UserUnmarshal64(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out HBITMAP * ); 
void                      __RPC_USER  HBITMAP_UserFree64(     __RPC__in unsigned long *, __RPC__in HBITMAP * ); 

unsigned long             __RPC_USER  HICON_UserSize64(     __RPC__in unsigned long *, unsigned long            , __RPC__in HICON * ); 
unsigned char * __RPC_USER  HICON_UserMarshal64(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in HICON * ); 
unsigned char * __RPC_USER  HICON_UserUnmarshal64(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out HICON * ); 
void                      __RPC_USER  HICON_UserFree64(     __RPC__in unsigned long *, __RPC__in HICON * ); 

unsigned long             __RPC_USER  HWND_UserSize64(     __RPC__in unsigned long *, unsigned long            , __RPC__in HWND * ); 
unsigned char * __RPC_USER  HWND_UserMarshal64(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in HWND * ); 
unsigned char * __RPC_USER  HWND_UserUnmarshal64(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out HWND * ); 
void                      __RPC_USER  HWND_UserFree64(     __RPC__in unsigned long *, __RPC__in HWND * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


