

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

#ifndef __ocidl_h__
#define __ocidl_h__

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

#ifndef __IEnumConnections_FWD_DEFINED__
#define __IEnumConnections_FWD_DEFINED__
typedef interface IEnumConnections IEnumConnections;

#endif 	/* __IEnumConnections_FWD_DEFINED__ */


#ifndef __IConnectionPoint_FWD_DEFINED__
#define __IConnectionPoint_FWD_DEFINED__
typedef interface IConnectionPoint IConnectionPoint;

#endif 	/* __IConnectionPoint_FWD_DEFINED__ */


#ifndef __IEnumConnectionPoints_FWD_DEFINED__
#define __IEnumConnectionPoints_FWD_DEFINED__
typedef interface IEnumConnectionPoints IEnumConnectionPoints;

#endif 	/* __IEnumConnectionPoints_FWD_DEFINED__ */


#ifndef __IConnectionPointContainer_FWD_DEFINED__
#define __IConnectionPointContainer_FWD_DEFINED__
typedef interface IConnectionPointContainer IConnectionPointContainer;

#endif 	/* __IConnectionPointContainer_FWD_DEFINED__ */


#ifndef __IClassFactory2_FWD_DEFINED__
#define __IClassFactory2_FWD_DEFINED__
typedef interface IClassFactory2 IClassFactory2;

#endif 	/* __IClassFactory2_FWD_DEFINED__ */


#ifndef __IProvideClassInfo_FWD_DEFINED__
#define __IProvideClassInfo_FWD_DEFINED__
typedef interface IProvideClassInfo IProvideClassInfo;

#endif 	/* __IProvideClassInfo_FWD_DEFINED__ */


#ifndef __IProvideClassInfo2_FWD_DEFINED__
#define __IProvideClassInfo2_FWD_DEFINED__
typedef interface IProvideClassInfo2 IProvideClassInfo2;

#endif 	/* __IProvideClassInfo2_FWD_DEFINED__ */


#ifndef __IProvideMultipleClassInfo_FWD_DEFINED__
#define __IProvideMultipleClassInfo_FWD_DEFINED__
typedef interface IProvideMultipleClassInfo IProvideMultipleClassInfo;

#endif 	/* __IProvideMultipleClassInfo_FWD_DEFINED__ */


#ifndef __IOleControl_FWD_DEFINED__
#define __IOleControl_FWD_DEFINED__
typedef interface IOleControl IOleControl;

#endif 	/* __IOleControl_FWD_DEFINED__ */


#ifndef __IOleControlSite_FWD_DEFINED__
#define __IOleControlSite_FWD_DEFINED__
typedef interface IOleControlSite IOleControlSite;

#endif 	/* __IOleControlSite_FWD_DEFINED__ */


#ifndef __IPropertyPage_FWD_DEFINED__
#define __IPropertyPage_FWD_DEFINED__
typedef interface IPropertyPage IPropertyPage;

#endif 	/* __IPropertyPage_FWD_DEFINED__ */


#ifndef __IPropertyPage2_FWD_DEFINED__
#define __IPropertyPage2_FWD_DEFINED__
typedef interface IPropertyPage2 IPropertyPage2;

#endif 	/* __IPropertyPage2_FWD_DEFINED__ */


#ifndef __IPropertyPageSite_FWD_DEFINED__
#define __IPropertyPageSite_FWD_DEFINED__
typedef interface IPropertyPageSite IPropertyPageSite;

#endif 	/* __IPropertyPageSite_FWD_DEFINED__ */


#ifndef __IPropertyNotifySink_FWD_DEFINED__
#define __IPropertyNotifySink_FWD_DEFINED__
typedef interface IPropertyNotifySink IPropertyNotifySink;

#endif 	/* __IPropertyNotifySink_FWD_DEFINED__ */


#ifndef __ISpecifyPropertyPages_FWD_DEFINED__
#define __ISpecifyPropertyPages_FWD_DEFINED__
typedef interface ISpecifyPropertyPages ISpecifyPropertyPages;

#endif 	/* __ISpecifyPropertyPages_FWD_DEFINED__ */


#ifndef __IPersistMemory_FWD_DEFINED__
#define __IPersistMemory_FWD_DEFINED__
typedef interface IPersistMemory IPersistMemory;

#endif 	/* __IPersistMemory_FWD_DEFINED__ */


#ifndef __IPersistStreamInit_FWD_DEFINED__
#define __IPersistStreamInit_FWD_DEFINED__
typedef interface IPersistStreamInit IPersistStreamInit;

#endif 	/* __IPersistStreamInit_FWD_DEFINED__ */


#ifndef __IPersistPropertyBag_FWD_DEFINED__
#define __IPersistPropertyBag_FWD_DEFINED__
typedef interface IPersistPropertyBag IPersistPropertyBag;

#endif 	/* __IPersistPropertyBag_FWD_DEFINED__ */


#ifndef __ISimpleFrameSite_FWD_DEFINED__
#define __ISimpleFrameSite_FWD_DEFINED__
typedef interface ISimpleFrameSite ISimpleFrameSite;

#endif 	/* __ISimpleFrameSite_FWD_DEFINED__ */


#ifndef __IFont_FWD_DEFINED__
#define __IFont_FWD_DEFINED__
typedef interface IFont IFont;

#endif 	/* __IFont_FWD_DEFINED__ */


#ifndef __IPicture_FWD_DEFINED__
#define __IPicture_FWD_DEFINED__
typedef interface IPicture IPicture;

#endif 	/* __IPicture_FWD_DEFINED__ */


#ifndef __IPicture2_FWD_DEFINED__
#define __IPicture2_FWD_DEFINED__
typedef interface IPicture2 IPicture2;

#endif 	/* __IPicture2_FWD_DEFINED__ */


#ifndef __IFontEventsDisp_FWD_DEFINED__
#define __IFontEventsDisp_FWD_DEFINED__
typedef interface IFontEventsDisp IFontEventsDisp;

#endif 	/* __IFontEventsDisp_FWD_DEFINED__ */


#ifndef __IFontDisp_FWD_DEFINED__
#define __IFontDisp_FWD_DEFINED__
typedef interface IFontDisp IFontDisp;

#endif 	/* __IFontDisp_FWD_DEFINED__ */


#ifndef __IPictureDisp_FWD_DEFINED__
#define __IPictureDisp_FWD_DEFINED__
typedef interface IPictureDisp IPictureDisp;

#endif 	/* __IPictureDisp_FWD_DEFINED__ */


#ifndef __IOleInPlaceObjectWindowless_FWD_DEFINED__
#define __IOleInPlaceObjectWindowless_FWD_DEFINED__
typedef interface IOleInPlaceObjectWindowless IOleInPlaceObjectWindowless;

#endif 	/* __IOleInPlaceObjectWindowless_FWD_DEFINED__ */


#ifndef __IOleInPlaceSiteEx_FWD_DEFINED__
#define __IOleInPlaceSiteEx_FWD_DEFINED__
typedef interface IOleInPlaceSiteEx IOleInPlaceSiteEx;

#endif 	/* __IOleInPlaceSiteEx_FWD_DEFINED__ */


#ifndef __IOleInPlaceSiteWindowless_FWD_DEFINED__
#define __IOleInPlaceSiteWindowless_FWD_DEFINED__
typedef interface IOleInPlaceSiteWindowless IOleInPlaceSiteWindowless;

#endif 	/* __IOleInPlaceSiteWindowless_FWD_DEFINED__ */


#ifndef __IViewObjectEx_FWD_DEFINED__
#define __IViewObjectEx_FWD_DEFINED__
typedef interface IViewObjectEx IViewObjectEx;

#endif 	/* __IViewObjectEx_FWD_DEFINED__ */


#ifndef __IOleUndoUnit_FWD_DEFINED__
#define __IOleUndoUnit_FWD_DEFINED__
typedef interface IOleUndoUnit IOleUndoUnit;

#endif 	/* __IOleUndoUnit_FWD_DEFINED__ */


#ifndef __IOleParentUndoUnit_FWD_DEFINED__
#define __IOleParentUndoUnit_FWD_DEFINED__
typedef interface IOleParentUndoUnit IOleParentUndoUnit;

#endif 	/* __IOleParentUndoUnit_FWD_DEFINED__ */


#ifndef __IEnumOleUndoUnits_FWD_DEFINED__
#define __IEnumOleUndoUnits_FWD_DEFINED__
typedef interface IEnumOleUndoUnits IEnumOleUndoUnits;

#endif 	/* __IEnumOleUndoUnits_FWD_DEFINED__ */


#ifndef __IOleUndoManager_FWD_DEFINED__
#define __IOleUndoManager_FWD_DEFINED__
typedef interface IOleUndoManager IOleUndoManager;

#endif 	/* __IOleUndoManager_FWD_DEFINED__ */


#ifndef __IPointerInactive_FWD_DEFINED__
#define __IPointerInactive_FWD_DEFINED__
typedef interface IPointerInactive IPointerInactive;

#endif 	/* __IPointerInactive_FWD_DEFINED__ */


#ifndef __IObjectWithSite_FWD_DEFINED__
#define __IObjectWithSite_FWD_DEFINED__
typedef interface IObjectWithSite IObjectWithSite;

#endif 	/* __IObjectWithSite_FWD_DEFINED__ */


#ifndef __IPerPropertyBrowsing_FWD_DEFINED__
#define __IPerPropertyBrowsing_FWD_DEFINED__
typedef interface IPerPropertyBrowsing IPerPropertyBrowsing;

#endif 	/* __IPerPropertyBrowsing_FWD_DEFINED__ */


#ifndef __IPropertyBag2_FWD_DEFINED__
#define __IPropertyBag2_FWD_DEFINED__
typedef interface IPropertyBag2 IPropertyBag2;

#endif 	/* __IPropertyBag2_FWD_DEFINED__ */


#ifndef __IPersistPropertyBag2_FWD_DEFINED__
#define __IPersistPropertyBag2_FWD_DEFINED__
typedef interface IPersistPropertyBag2 IPersistPropertyBag2;

#endif 	/* __IPersistPropertyBag2_FWD_DEFINED__ */


#ifndef __IAdviseSinkEx_FWD_DEFINED__
#define __IAdviseSinkEx_FWD_DEFINED__
typedef interface IAdviseSinkEx IAdviseSinkEx;

#endif 	/* __IAdviseSinkEx_FWD_DEFINED__ */


#ifndef __IQuickActivate_FWD_DEFINED__
#define __IQuickActivate_FWD_DEFINED__
typedef interface IQuickActivate IQuickActivate;

#endif 	/* __IQuickActivate_FWD_DEFINED__ */


/* header files for imported files */
#include "oleidl.h"
#include "oaidl.h"
#include "servprov.h"
#include "urlmon.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_ocidl_0000_0000 */
/* [local] */ 

#include <winapifamily.h>
//+-------------------------------------------------------------------------
//
//  Microsoft Windows
//  Copyright (c) Microsoft Corporation. All rights reserved.
//
//--------------------------------------------------------------------------
#if ( _MSC_VER >= 1020 )
#pragma once
#endif
#if _MSC_VER >= 1200
#pragma warning(push)
#pragma warning(disable:4820) /* padding added after data member */
#pragma warning(disable:4917) /* a GUID can only be associated with a class, interface or namespace */
#endif
#pragma region Application Family or OneCore Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM)




#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM) */
#pragma endregion
#pragma region Desktop Family or OneCore Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)





































#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) */
#pragma endregion
#pragma region Desktop Family or OneCore Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)


extern RPC_IF_HANDLE __MIDL_itf_ocidl_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ocidl_0000_0000_v0_0_s_ifspec;

#ifndef __IOleControlTypes_INTERFACE_DEFINED__
#define __IOleControlTypes_INTERFACE_DEFINED__

/* interface IOleControlTypes */
/* [unique][version] */ 

typedef /* [v1_enum] */ 
enum tagUASFLAGS
    {
        UAS_NORMAL	= 0,
        UAS_BLOCKED	= 0x1,
        UAS_NOPARENTENABLE	= 0x2,
        UAS_MASK	= 0x3
    } 	UASFLAGS;

/* State values for the DISPID_READYSTATE property */
typedef /* [v1_enum] */ 
enum tagREADYSTATE
    {
        READYSTATE_UNINITIALIZED	= 0,
        READYSTATE_LOADING	= 1,
        READYSTATE_LOADED	= 2,
        READYSTATE_INTERACTIVE	= 3,
        READYSTATE_COMPLETE	= 4
    } 	READYSTATE;



extern RPC_IF_HANDLE IOleControlTypes_v1_0_c_ifspec;
extern RPC_IF_HANDLE IOleControlTypes_v1_0_s_ifspec;
#endif /* __IOleControlTypes_INTERFACE_DEFINED__ */

/* interface __MIDL_itf_ocidl_0000_0001 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) */
#pragma endregion
#pragma region Application Family or OneCore Family or Games Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)


extern RPC_IF_HANDLE __MIDL_itf_ocidl_0000_0001_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ocidl_0000_0001_v0_0_s_ifspec;

#ifndef __IEnumConnections_INTERFACE_DEFINED__
#define __IEnumConnections_INTERFACE_DEFINED__

/* interface IEnumConnections */
/* [unique][uuid][object] */ 

typedef IEnumConnections *PENUMCONNECTIONS;

typedef IEnumConnections *LPENUMCONNECTIONS;

typedef struct tagCONNECTDATA
    {
    IUnknown *pUnk;
    DWORD dwCookie;
    } 	CONNECTDATA;

typedef struct tagCONNECTDATA *PCONNECTDATA;

typedef struct tagCONNECTDATA *LPCONNECTDATA;


EXTERN_C const IID IID_IEnumConnections;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B196B287-BAB4-101A-B69C-00AA00341D07")
    IEnumConnections : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE Next( 
            /* [annotation][in] */ 
            _In_  ULONG cConnections,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(cConnections,*pcFetched)  LPCONNECTDATA rgcd,
            /* [annotation][out] */ 
            _Out_  ULONG *pcFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [annotation][in] */ 
            _In_  ULONG cConnections) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [annotation][out] */ 
            _Out_  IEnumConnections **ppEnum) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IEnumConnectionsVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IEnumConnections * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IEnumConnections * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IEnumConnections * This);
        
        DECLSPEC_XFGVIRT(IEnumConnections, Next)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Next )( 
            IEnumConnections * This,
            /* [annotation][in] */ 
            _In_  ULONG cConnections,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(cConnections,*pcFetched)  LPCONNECTDATA rgcd,
            /* [annotation][out] */ 
            _Out_  ULONG *pcFetched);
        
        DECLSPEC_XFGVIRT(IEnumConnections, Skip)
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            __RPC__in IEnumConnections * This,
            /* [annotation][in] */ 
            _In_  ULONG cConnections);
        
        DECLSPEC_XFGVIRT(IEnumConnections, Reset)
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            __RPC__in IEnumConnections * This);
        
        DECLSPEC_XFGVIRT(IEnumConnections, Clone)
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            __RPC__in IEnumConnections * This,
            /* [annotation][out] */ 
            _Out_  IEnumConnections **ppEnum);
        
        END_INTERFACE
    } IEnumConnectionsVtbl;

    interface IEnumConnections
    {
        CONST_VTBL struct IEnumConnectionsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumConnections_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEnumConnections_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEnumConnections_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IEnumConnections_Next(This,cConnections,rgcd,pcFetched)	\
    ( (This)->lpVtbl -> Next(This,cConnections,rgcd,pcFetched) ) 

#define IEnumConnections_Skip(This,cConnections)	\
    ( (This)->lpVtbl -> Skip(This,cConnections) ) 

#define IEnumConnections_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define IEnumConnections_Clone(This,ppEnum)	\
    ( (This)->lpVtbl -> Clone(This,ppEnum) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT STDMETHODCALLTYPE IEnumConnections_RemoteNext_Proxy( 
    __RPC__in IEnumConnections * This,
    /* [annotation][in] */ 
    _In_  ULONG cConnections,
    /* [annotation][length_is][size_is][out] */ 
    _Out_writes_to_(cConnections,*pcFetched)  LPCONNECTDATA rgcd,
    /* [annotation][out] */ 
    _Out_  ULONG *pcFetched);


void __RPC_STUB IEnumConnections_RemoteNext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEnumConnections_INTERFACE_DEFINED__ */


#ifndef __IConnectionPoint_INTERFACE_DEFINED__
#define __IConnectionPoint_INTERFACE_DEFINED__

/* interface IConnectionPoint */
/* [unique][uuid][object] */ 

typedef IConnectionPoint *PCONNECTIONPOINT;

typedef IConnectionPoint *LPCONNECTIONPOINT;


EXTERN_C const IID IID_IConnectionPoint;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B196B286-BAB4-101A-B69C-00AA00341D07")
    IConnectionPoint : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetConnectionInterface( 
            /* [annotation][out] */ 
            _Out_  IID *pIID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetConnectionPointContainer( 
            /* [annotation][out] */ 
            _Out_  IConnectionPointContainer **ppCPC) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Advise( 
            /* [annotation][in] */ 
            _In_  IUnknown *pUnkSink,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwCookie) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Unadvise( 
            /* [annotation][in] */ 
            _In_  DWORD dwCookie) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumConnections( 
            /* [annotation][out] */ 
            _Out_  IEnumConnections **ppEnum) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IConnectionPointVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IConnectionPoint * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IConnectionPoint * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IConnectionPoint * This);
        
        DECLSPEC_XFGVIRT(IConnectionPoint, GetConnectionInterface)
        HRESULT ( STDMETHODCALLTYPE *GetConnectionInterface )( 
            __RPC__in IConnectionPoint * This,
            /* [annotation][out] */ 
            _Out_  IID *pIID);
        
        DECLSPEC_XFGVIRT(IConnectionPoint, GetConnectionPointContainer)
        HRESULT ( STDMETHODCALLTYPE *GetConnectionPointContainer )( 
            __RPC__in IConnectionPoint * This,
            /* [annotation][out] */ 
            _Out_  IConnectionPointContainer **ppCPC);
        
        DECLSPEC_XFGVIRT(IConnectionPoint, Advise)
        HRESULT ( STDMETHODCALLTYPE *Advise )( 
            __RPC__in IConnectionPoint * This,
            /* [annotation][in] */ 
            _In_  IUnknown *pUnkSink,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwCookie);
        
        DECLSPEC_XFGVIRT(IConnectionPoint, Unadvise)
        HRESULT ( STDMETHODCALLTYPE *Unadvise )( 
            __RPC__in IConnectionPoint * This,
            /* [annotation][in] */ 
            _In_  DWORD dwCookie);
        
        DECLSPEC_XFGVIRT(IConnectionPoint, EnumConnections)
        HRESULT ( STDMETHODCALLTYPE *EnumConnections )( 
            __RPC__in IConnectionPoint * This,
            /* [annotation][out] */ 
            _Out_  IEnumConnections **ppEnum);
        
        END_INTERFACE
    } IConnectionPointVtbl;

    interface IConnectionPoint
    {
        CONST_VTBL struct IConnectionPointVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IConnectionPoint_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IConnectionPoint_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IConnectionPoint_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IConnectionPoint_GetConnectionInterface(This,pIID)	\
    ( (This)->lpVtbl -> GetConnectionInterface(This,pIID) ) 

#define IConnectionPoint_GetConnectionPointContainer(This,ppCPC)	\
    ( (This)->lpVtbl -> GetConnectionPointContainer(This,ppCPC) ) 

#define IConnectionPoint_Advise(This,pUnkSink,pdwCookie)	\
    ( (This)->lpVtbl -> Advise(This,pUnkSink,pdwCookie) ) 

#define IConnectionPoint_Unadvise(This,dwCookie)	\
    ( (This)->lpVtbl -> Unadvise(This,dwCookie) ) 

#define IConnectionPoint_EnumConnections(This,ppEnum)	\
    ( (This)->lpVtbl -> EnumConnections(This,ppEnum) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IConnectionPoint_INTERFACE_DEFINED__ */


#ifndef __IEnumConnectionPoints_INTERFACE_DEFINED__
#define __IEnumConnectionPoints_INTERFACE_DEFINED__

/* interface IEnumConnectionPoints */
/* [unique][uuid][object] */ 

typedef IEnumConnectionPoints *PENUMCONNECTIONPOINTS;

typedef IEnumConnectionPoints *LPENUMCONNECTIONPOINTS;


EXTERN_C const IID IID_IEnumConnectionPoints;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B196B285-BAB4-101A-B69C-00AA00341D07")
    IEnumConnectionPoints : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE Next( 
            /* [annotation][in] */ 
            _In_  ULONG cConnections,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(cConnections,*pcFetched)  LPCONNECTIONPOINT *ppCP,
            /* [annotation][out] */ 
            _Out_  ULONG *pcFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [annotation][in] */ 
            _In_  ULONG cConnections) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [annotation][out] */ 
            _Out_  IEnumConnectionPoints **ppEnum) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IEnumConnectionPointsVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IEnumConnectionPoints * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IEnumConnectionPoints * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IEnumConnectionPoints * This);
        
        DECLSPEC_XFGVIRT(IEnumConnectionPoints, Next)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Next )( 
            IEnumConnectionPoints * This,
            /* [annotation][in] */ 
            _In_  ULONG cConnections,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(cConnections,*pcFetched)  LPCONNECTIONPOINT *ppCP,
            /* [annotation][out] */ 
            _Out_  ULONG *pcFetched);
        
        DECLSPEC_XFGVIRT(IEnumConnectionPoints, Skip)
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            __RPC__in IEnumConnectionPoints * This,
            /* [annotation][in] */ 
            _In_  ULONG cConnections);
        
        DECLSPEC_XFGVIRT(IEnumConnectionPoints, Reset)
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            __RPC__in IEnumConnectionPoints * This);
        
        DECLSPEC_XFGVIRT(IEnumConnectionPoints, Clone)
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            __RPC__in IEnumConnectionPoints * This,
            /* [annotation][out] */ 
            _Out_  IEnumConnectionPoints **ppEnum);
        
        END_INTERFACE
    } IEnumConnectionPointsVtbl;

    interface IEnumConnectionPoints
    {
        CONST_VTBL struct IEnumConnectionPointsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumConnectionPoints_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEnumConnectionPoints_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEnumConnectionPoints_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IEnumConnectionPoints_Next(This,cConnections,ppCP,pcFetched)	\
    ( (This)->lpVtbl -> Next(This,cConnections,ppCP,pcFetched) ) 

#define IEnumConnectionPoints_Skip(This,cConnections)	\
    ( (This)->lpVtbl -> Skip(This,cConnections) ) 

#define IEnumConnectionPoints_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define IEnumConnectionPoints_Clone(This,ppEnum)	\
    ( (This)->lpVtbl -> Clone(This,ppEnum) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT STDMETHODCALLTYPE IEnumConnectionPoints_RemoteNext_Proxy( 
    __RPC__in IEnumConnectionPoints * This,
    /* [annotation][in] */ 
    _In_  ULONG cConnections,
    /* [annotation][length_is][size_is][out] */ 
    _Out_writes_to_(cConnections,*pcFetched)  LPCONNECTIONPOINT *ppCP,
    /* [annotation][out] */ 
    _Out_  ULONG *pcFetched);


void __RPC_STUB IEnumConnectionPoints_RemoteNext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEnumConnectionPoints_INTERFACE_DEFINED__ */


#ifndef __IConnectionPointContainer_INTERFACE_DEFINED__
#define __IConnectionPointContainer_INTERFACE_DEFINED__

/* interface IConnectionPointContainer */
/* [unique][uuid][object] */ 

typedef IConnectionPointContainer *PCONNECTIONPOINTCONTAINER;

typedef IConnectionPointContainer *LPCONNECTIONPOINTCONTAINER;


EXTERN_C const IID IID_IConnectionPointContainer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B196B284-BAB4-101A-B69C-00AA00341D07")
    IConnectionPointContainer : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE EnumConnectionPoints( 
            /* [annotation][out] */ 
            _Out_  IEnumConnectionPoints **ppEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FindConnectionPoint( 
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][out] */ 
            _Out_  IConnectionPoint **ppCP) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IConnectionPointContainerVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IConnectionPointContainer * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IConnectionPointContainer * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IConnectionPointContainer * This);
        
        DECLSPEC_XFGVIRT(IConnectionPointContainer, EnumConnectionPoints)
        HRESULT ( STDMETHODCALLTYPE *EnumConnectionPoints )( 
            __RPC__in IConnectionPointContainer * This,
            /* [annotation][out] */ 
            _Out_  IEnumConnectionPoints **ppEnum);
        
        DECLSPEC_XFGVIRT(IConnectionPointContainer, FindConnectionPoint)
        HRESULT ( STDMETHODCALLTYPE *FindConnectionPoint )( 
            __RPC__in IConnectionPointContainer * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][out] */ 
            _Out_  IConnectionPoint **ppCP);
        
        END_INTERFACE
    } IConnectionPointContainerVtbl;

    interface IConnectionPointContainer
    {
        CONST_VTBL struct IConnectionPointContainerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IConnectionPointContainer_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IConnectionPointContainer_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IConnectionPointContainer_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IConnectionPointContainer_EnumConnectionPoints(This,ppEnum)	\
    ( (This)->lpVtbl -> EnumConnectionPoints(This,ppEnum) ) 

#define IConnectionPointContainer_FindConnectionPoint(This,riid,ppCP)	\
    ( (This)->lpVtbl -> FindConnectionPoint(This,riid,ppCP) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IConnectionPointContainer_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_ocidl_0000_0005 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */
#pragma endregion
#pragma region Desktop Family or OneCore Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)


extern RPC_IF_HANDLE __MIDL_itf_ocidl_0000_0005_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ocidl_0000_0005_v0_0_s_ifspec;

#ifndef __IClassFactory2_INTERFACE_DEFINED__
#define __IClassFactory2_INTERFACE_DEFINED__

/* interface IClassFactory2 */
/* [unique][uuid][object] */ 

typedef IClassFactory2 *LPCLASSFACTORY2;

typedef struct tagLICINFO
    {
    LONG cbLicInfo;
    BOOL fRuntimeKeyAvail;
    BOOL fLicVerified;
    } 	LICINFO;

typedef struct tagLICINFO *LPLICINFO;


EXTERN_C const IID IID_IClassFactory2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B196B28F-BAB4-101A-B69C-00AA00341D07")
    IClassFactory2 : public IClassFactory
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetLicInfo( 
            /* [annotation][out][in] */ 
            _Inout_  LICINFO *pLicInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RequestLicKey( 
            /* [annotation][in] */ 
            _In_  DWORD dwReserved,
            /* [annotation][out] */ 
            _Out_  BSTR *pBstrKey) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE CreateInstanceLic( 
            /* [annotation][in] */ 
            _In_opt_  IUnknown *pUnkOuter,
            /* [annotation][in] */ 
            _Reserved_  IUnknown *pUnkReserved,
            /* [annotation][in] */ 
            __RPC__in  REFIID riid,
            /* [annotation][in] */ 
            __RPC__in  BSTR bstrKey,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out_opt  PVOID *ppvObj) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IClassFactory2Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IClassFactory2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IClassFactory2 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IClassFactory2 * This);
        
        DECLSPEC_XFGVIRT(IClassFactory, CreateInstance)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *CreateInstance )( 
            IClassFactory2 * This,
            /* [annotation][unique][in] */ 
            _In_opt_  IUnknown *pUnkOuter,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IClassFactory, LockServer)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *LockServer )( 
            IClassFactory2 * This,
            /* [annotation][in] */ 
            _In_  BOOL fLock);
        
        DECLSPEC_XFGVIRT(IClassFactory2, GetLicInfo)
        HRESULT ( STDMETHODCALLTYPE *GetLicInfo )( 
            __RPC__in IClassFactory2 * This,
            /* [annotation][out][in] */ 
            _Inout_  LICINFO *pLicInfo);
        
        DECLSPEC_XFGVIRT(IClassFactory2, RequestLicKey)
        HRESULT ( STDMETHODCALLTYPE *RequestLicKey )( 
            __RPC__in IClassFactory2 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwReserved,
            /* [annotation][out] */ 
            _Out_  BSTR *pBstrKey);
        
        DECLSPEC_XFGVIRT(IClassFactory2, CreateInstanceLic)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *CreateInstanceLic )( 
            IClassFactory2 * This,
            /* [annotation][in] */ 
            _In_opt_  IUnknown *pUnkOuter,
            /* [annotation][in] */ 
            _Reserved_  IUnknown *pUnkReserved,
            /* [annotation][in] */ 
            __RPC__in  REFIID riid,
            /* [annotation][in] */ 
            __RPC__in  BSTR bstrKey,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out_opt  PVOID *ppvObj);
        
        END_INTERFACE
    } IClassFactory2Vtbl;

    interface IClassFactory2
    {
        CONST_VTBL struct IClassFactory2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IClassFactory2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IClassFactory2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IClassFactory2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IClassFactory2_CreateInstance(This,pUnkOuter,riid,ppvObject)	\
    ( (This)->lpVtbl -> CreateInstance(This,pUnkOuter,riid,ppvObject) ) 

#define IClassFactory2_LockServer(This,fLock)	\
    ( (This)->lpVtbl -> LockServer(This,fLock) ) 


#define IClassFactory2_GetLicInfo(This,pLicInfo)	\
    ( (This)->lpVtbl -> GetLicInfo(This,pLicInfo) ) 

#define IClassFactory2_RequestLicKey(This,dwReserved,pBstrKey)	\
    ( (This)->lpVtbl -> RequestLicKey(This,dwReserved,pBstrKey) ) 

#define IClassFactory2_CreateInstanceLic(This,pUnkOuter,pUnkReserved,riid,bstrKey,ppvObj)	\
    ( (This)->lpVtbl -> CreateInstanceLic(This,pUnkOuter,pUnkReserved,riid,bstrKey,ppvObj) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT STDMETHODCALLTYPE IClassFactory2_RemoteCreateInstanceLic_Proxy( 
    __RPC__in IClassFactory2 * This,
    /* [annotation][in] */ 
    _In_  REFIID riid,
    /* [annotation][in] */ 
    _In_  BSTR bstrKey,
    /* [annotation][iid_is][out] */ 
    _COM_Outptr_  IUnknown **ppvObj);


void __RPC_STUB IClassFactory2_RemoteCreateInstanceLic_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IClassFactory2_INTERFACE_DEFINED__ */


#ifndef __IProvideClassInfo_INTERFACE_DEFINED__
#define __IProvideClassInfo_INTERFACE_DEFINED__

/* interface IProvideClassInfo */
/* [unique][uuid][object] */ 

typedef IProvideClassInfo *LPPROVIDECLASSINFO;


EXTERN_C const IID IID_IProvideClassInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B196B283-BAB4-101A-B69C-00AA00341D07")
    IProvideClassInfo : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetClassInfo( 
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTI) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IProvideClassInfoVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IProvideClassInfo * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IProvideClassInfo * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IProvideClassInfo * This);
        
        DECLSPEC_XFGVIRT(IProvideClassInfo, GetClassInfo)
        HRESULT ( STDMETHODCALLTYPE *GetClassInfo )( 
            __RPC__in IProvideClassInfo * This,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTI);
        
        END_INTERFACE
    } IProvideClassInfoVtbl;

    interface IProvideClassInfo
    {
        CONST_VTBL struct IProvideClassInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IProvideClassInfo_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IProvideClassInfo_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IProvideClassInfo_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IProvideClassInfo_GetClassInfo(This,ppTI)	\
    ( (This)->lpVtbl -> GetClassInfo(This,ppTI) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IProvideClassInfo_INTERFACE_DEFINED__ */


#ifndef __IProvideClassInfo2_INTERFACE_DEFINED__
#define __IProvideClassInfo2_INTERFACE_DEFINED__

/* interface IProvideClassInfo2 */
/* [unique][uuid][object] */ 

typedef IProvideClassInfo2 *LPPROVIDECLASSINFO2;

typedef 
enum tagGUIDKIND
    {
        GUIDKIND_DEFAULT_SOURCE_DISP_IID	= 1
    } 	GUIDKIND;


EXTERN_C const IID IID_IProvideClassInfo2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A6BC3AC0-DBAA-11CE-9DE3-00AA004BB851")
    IProvideClassInfo2 : public IProvideClassInfo
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetGUID( 
            /* [annotation][in] */ 
            _In_  DWORD dwGuidKind,
            /* [annotation][out] */ 
            _Out_  GUID *pGUID) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IProvideClassInfo2Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IProvideClassInfo2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IProvideClassInfo2 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IProvideClassInfo2 * This);
        
        DECLSPEC_XFGVIRT(IProvideClassInfo, GetClassInfo)
        HRESULT ( STDMETHODCALLTYPE *GetClassInfo )( 
            __RPC__in IProvideClassInfo2 * This,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTI);
        
        DECLSPEC_XFGVIRT(IProvideClassInfo2, GetGUID)
        HRESULT ( STDMETHODCALLTYPE *GetGUID )( 
            __RPC__in IProvideClassInfo2 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwGuidKind,
            /* [annotation][out] */ 
            _Out_  GUID *pGUID);
        
        END_INTERFACE
    } IProvideClassInfo2Vtbl;

    interface IProvideClassInfo2
    {
        CONST_VTBL struct IProvideClassInfo2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IProvideClassInfo2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IProvideClassInfo2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IProvideClassInfo2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IProvideClassInfo2_GetClassInfo(This,ppTI)	\
    ( (This)->lpVtbl -> GetClassInfo(This,ppTI) ) 


#define IProvideClassInfo2_GetGUID(This,dwGuidKind,pGUID)	\
    ( (This)->lpVtbl -> GetGUID(This,dwGuidKind,pGUID) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IProvideClassInfo2_INTERFACE_DEFINED__ */


#ifndef __IProvideMultipleClassInfo_INTERFACE_DEFINED__
#define __IProvideMultipleClassInfo_INTERFACE_DEFINED__

/* interface IProvideMultipleClassInfo */
/* [unique][uuid][object] */ 

#define MULTICLASSINFO_GETTYPEINFO           0x00000001
#define MULTICLASSINFO_GETNUMRESERVEDDISPIDS 0x00000002
#define MULTICLASSINFO_GETIIDPRIMARY         0x00000004
#define MULTICLASSINFO_GETIIDSOURCE          0x00000008
#define TIFLAGS_EXTENDDISPATCHONLY           0x00000001
typedef IProvideMultipleClassInfo *LPPROVIDEMULTIPLECLASSINFO;


EXTERN_C const IID IID_IProvideMultipleClassInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A7ABA9C1-8983-11cf-8F20-00805F2CD064")
    IProvideMultipleClassInfo : public IProvideClassInfo2
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetMultiTypeInfoCount( 
            /* [annotation][out] */ 
            _Out_  ULONG *pcti) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetInfoOfIndex( 
            /* [annotation][in] */ 
            _In_  ULONG iti,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **pptiCoClass,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwTIFlags,
            /* [annotation][out] */ 
            _Out_  ULONG *pcdispidReserved,
            /* [annotation][out] */ 
            _Out_  IID *piidPrimary,
            /* [annotation][out] */ 
            _Out_  IID *piidSource) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IProvideMultipleClassInfoVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IProvideMultipleClassInfo * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IProvideMultipleClassInfo * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IProvideMultipleClassInfo * This);
        
        DECLSPEC_XFGVIRT(IProvideClassInfo, GetClassInfo)
        HRESULT ( STDMETHODCALLTYPE *GetClassInfo )( 
            __RPC__in IProvideMultipleClassInfo * This,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTI);
        
        DECLSPEC_XFGVIRT(IProvideClassInfo2, GetGUID)
        HRESULT ( STDMETHODCALLTYPE *GetGUID )( 
            __RPC__in IProvideMultipleClassInfo * This,
            /* [annotation][in] */ 
            _In_  DWORD dwGuidKind,
            /* [annotation][out] */ 
            _Out_  GUID *pGUID);
        
        DECLSPEC_XFGVIRT(IProvideMultipleClassInfo, GetMultiTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetMultiTypeInfoCount )( 
            __RPC__in IProvideMultipleClassInfo * This,
            /* [annotation][out] */ 
            _Out_  ULONG *pcti);
        
        DECLSPEC_XFGVIRT(IProvideMultipleClassInfo, GetInfoOfIndex)
        HRESULT ( STDMETHODCALLTYPE *GetInfoOfIndex )( 
            __RPC__in IProvideMultipleClassInfo * This,
            /* [annotation][in] */ 
            _In_  ULONG iti,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **pptiCoClass,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwTIFlags,
            /* [annotation][out] */ 
            _Out_  ULONG *pcdispidReserved,
            /* [annotation][out] */ 
            _Out_  IID *piidPrimary,
            /* [annotation][out] */ 
            _Out_  IID *piidSource);
        
        END_INTERFACE
    } IProvideMultipleClassInfoVtbl;

    interface IProvideMultipleClassInfo
    {
        CONST_VTBL struct IProvideMultipleClassInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IProvideMultipleClassInfo_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IProvideMultipleClassInfo_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IProvideMultipleClassInfo_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IProvideMultipleClassInfo_GetClassInfo(This,ppTI)	\
    ( (This)->lpVtbl -> GetClassInfo(This,ppTI) ) 


#define IProvideMultipleClassInfo_GetGUID(This,dwGuidKind,pGUID)	\
    ( (This)->lpVtbl -> GetGUID(This,dwGuidKind,pGUID) ) 


#define IProvideMultipleClassInfo_GetMultiTypeInfoCount(This,pcti)	\
    ( (This)->lpVtbl -> GetMultiTypeInfoCount(This,pcti) ) 

#define IProvideMultipleClassInfo_GetInfoOfIndex(This,iti,dwFlags,pptiCoClass,pdwTIFlags,pcdispidReserved,piidPrimary,piidSource)	\
    ( (This)->lpVtbl -> GetInfoOfIndex(This,iti,dwFlags,pptiCoClass,pdwTIFlags,pcdispidReserved,piidPrimary,piidSource) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IProvideMultipleClassInfo_INTERFACE_DEFINED__ */


#ifndef __IOleControl_INTERFACE_DEFINED__
#define __IOleControl_INTERFACE_DEFINED__

/* interface IOleControl */
/* [unique][uuid][object] */ 

typedef IOleControl *LPOLECONTROL;

typedef struct tagCONTROLINFO
    {
    ULONG cb;
    HACCEL hAccel;
    USHORT cAccel;
    DWORD dwFlags;
    } 	CONTROLINFO;

typedef struct tagCONTROLINFO *LPCONTROLINFO;

typedef 
enum tagCTRLINFO
    {
        CTRLINFO_EATS_RETURN	= 1,
        CTRLINFO_EATS_ESCAPE	= 2
    } 	CTRLINFO;


EXTERN_C const IID IID_IOleControl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B196B288-BAB4-101A-B69C-00AA00341D07")
    IOleControl : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetControlInfo( 
            /* [annotation][out][in] */ 
            _Inout_  CONTROLINFO *pCI) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnMnemonic( 
            /* [annotation][in] */ 
            _In_  MSG *pMsg) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnAmbientPropertyChange( 
            /* [annotation][in] */ 
            _In_  DISPID dispID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FreezeEvents( 
            /* [annotation][in] */ 
            _In_  BOOL bFreeze) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IOleControlVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IOleControl * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IOleControl * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IOleControl * This);
        
        DECLSPEC_XFGVIRT(IOleControl, GetControlInfo)
        HRESULT ( STDMETHODCALLTYPE *GetControlInfo )( 
            __RPC__in IOleControl * This,
            /* [annotation][out][in] */ 
            _Inout_  CONTROLINFO *pCI);
        
        DECLSPEC_XFGVIRT(IOleControl, OnMnemonic)
        HRESULT ( STDMETHODCALLTYPE *OnMnemonic )( 
            __RPC__in IOleControl * This,
            /* [annotation][in] */ 
            _In_  MSG *pMsg);
        
        DECLSPEC_XFGVIRT(IOleControl, OnAmbientPropertyChange)
        HRESULT ( STDMETHODCALLTYPE *OnAmbientPropertyChange )( 
            __RPC__in IOleControl * This,
            /* [annotation][in] */ 
            _In_  DISPID dispID);
        
        DECLSPEC_XFGVIRT(IOleControl, FreezeEvents)
        HRESULT ( STDMETHODCALLTYPE *FreezeEvents )( 
            __RPC__in IOleControl * This,
            /* [annotation][in] */ 
            _In_  BOOL bFreeze);
        
        END_INTERFACE
    } IOleControlVtbl;

    interface IOleControl
    {
        CONST_VTBL struct IOleControlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOleControl_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOleControl_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOleControl_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOleControl_GetControlInfo(This,pCI)	\
    ( (This)->lpVtbl -> GetControlInfo(This,pCI) ) 

#define IOleControl_OnMnemonic(This,pMsg)	\
    ( (This)->lpVtbl -> OnMnemonic(This,pMsg) ) 

#define IOleControl_OnAmbientPropertyChange(This,dispID)	\
    ( (This)->lpVtbl -> OnAmbientPropertyChange(This,dispID) ) 

#define IOleControl_FreezeEvents(This,bFreeze)	\
    ( (This)->lpVtbl -> FreezeEvents(This,bFreeze) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOleControl_INTERFACE_DEFINED__ */


#ifndef __IOleControlSite_INTERFACE_DEFINED__
#define __IOleControlSite_INTERFACE_DEFINED__

/* interface IOleControlSite */
/* [unique][uuid][object] */ 

typedef IOleControlSite *LPOLECONTROLSITE;

typedef struct tagPOINTF
    {
    FLOAT x;
    FLOAT y;
    } 	POINTF;

typedef struct tagPOINTF *LPPOINTF;

typedef 
enum tagXFORMCOORDS
    {
        XFORMCOORDS_POSITION	= 0x1,
        XFORMCOORDS_SIZE	= 0x2,
        XFORMCOORDS_HIMETRICTOCONTAINER	= 0x4,
        XFORMCOORDS_CONTAINERTOHIMETRIC	= 0x8,
        XFORMCOORDS_EVENTCOMPAT	= 0x10
    } 	XFORMCOORDS;


EXTERN_C const IID IID_IOleControlSite;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B196B289-BAB4-101A-B69C-00AA00341D07")
    IOleControlSite : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnControlInfoChanged( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LockInPlaceActive( 
            /* [annotation][in] */ 
            _In_  BOOL fLock) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetExtendedControl( 
            /* [annotation][out] */ 
            _Out_  IDispatch **ppDisp) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE TransformCoords( 
            /* [annotation][out][in] */ 
            _Inout_  POINTL *pPtlHimetric,
            /* [annotation][out][in] */ 
            _Inout_  POINTF *pPtfContainer,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE TranslateAccelerator( 
            /* [annotation][in] */ 
            _In_  MSG *pMsg,
            /* [annotation][in] */ 
            _In_  DWORD grfModifiers) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnFocus( 
            /* [annotation][in] */ 
            _In_  BOOL fGotFocus) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ShowPropertyFrame( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IOleControlSiteVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IOleControlSite * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IOleControlSite * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IOleControlSite * This);
        
        DECLSPEC_XFGVIRT(IOleControlSite, OnControlInfoChanged)
        HRESULT ( STDMETHODCALLTYPE *OnControlInfoChanged )( 
            __RPC__in IOleControlSite * This);
        
        DECLSPEC_XFGVIRT(IOleControlSite, LockInPlaceActive)
        HRESULT ( STDMETHODCALLTYPE *LockInPlaceActive )( 
            __RPC__in IOleControlSite * This,
            /* [annotation][in] */ 
            _In_  BOOL fLock);
        
        DECLSPEC_XFGVIRT(IOleControlSite, GetExtendedControl)
        HRESULT ( STDMETHODCALLTYPE *GetExtendedControl )( 
            __RPC__in IOleControlSite * This,
            /* [annotation][out] */ 
            _Out_  IDispatch **ppDisp);
        
        DECLSPEC_XFGVIRT(IOleControlSite, TransformCoords)
        HRESULT ( STDMETHODCALLTYPE *TransformCoords )( 
            __RPC__in IOleControlSite * This,
            /* [annotation][out][in] */ 
            _Inout_  POINTL *pPtlHimetric,
            /* [annotation][out][in] */ 
            _Inout_  POINTF *pPtfContainer,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags);
        
        DECLSPEC_XFGVIRT(IOleControlSite, TranslateAccelerator)
        HRESULT ( STDMETHODCALLTYPE *TranslateAccelerator )( 
            __RPC__in IOleControlSite * This,
            /* [annotation][in] */ 
            _In_  MSG *pMsg,
            /* [annotation][in] */ 
            _In_  DWORD grfModifiers);
        
        DECLSPEC_XFGVIRT(IOleControlSite, OnFocus)
        HRESULT ( STDMETHODCALLTYPE *OnFocus )( 
            __RPC__in IOleControlSite * This,
            /* [annotation][in] */ 
            _In_  BOOL fGotFocus);
        
        DECLSPEC_XFGVIRT(IOleControlSite, ShowPropertyFrame)
        HRESULT ( STDMETHODCALLTYPE *ShowPropertyFrame )( 
            __RPC__in IOleControlSite * This);
        
        END_INTERFACE
    } IOleControlSiteVtbl;

    interface IOleControlSite
    {
        CONST_VTBL struct IOleControlSiteVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOleControlSite_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOleControlSite_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOleControlSite_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOleControlSite_OnControlInfoChanged(This)	\
    ( (This)->lpVtbl -> OnControlInfoChanged(This) ) 

#define IOleControlSite_LockInPlaceActive(This,fLock)	\
    ( (This)->lpVtbl -> LockInPlaceActive(This,fLock) ) 

#define IOleControlSite_GetExtendedControl(This,ppDisp)	\
    ( (This)->lpVtbl -> GetExtendedControl(This,ppDisp) ) 

#define IOleControlSite_TransformCoords(This,pPtlHimetric,pPtfContainer,dwFlags)	\
    ( (This)->lpVtbl -> TransformCoords(This,pPtlHimetric,pPtfContainer,dwFlags) ) 

#define IOleControlSite_TranslateAccelerator(This,pMsg,grfModifiers)	\
    ( (This)->lpVtbl -> TranslateAccelerator(This,pMsg,grfModifiers) ) 

#define IOleControlSite_OnFocus(This,fGotFocus)	\
    ( (This)->lpVtbl -> OnFocus(This,fGotFocus) ) 

#define IOleControlSite_ShowPropertyFrame(This)	\
    ( (This)->lpVtbl -> ShowPropertyFrame(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOleControlSite_INTERFACE_DEFINED__ */


#ifndef __IPropertyPage_INTERFACE_DEFINED__
#define __IPropertyPage_INTERFACE_DEFINED__

/* interface IPropertyPage */
/* [unique][uuid][object] */ 

typedef IPropertyPage *LPPROPERTYPAGE;

typedef struct tagPROPPAGEINFO
    {
    ULONG cb;
    LPOLESTR pszTitle;
    SIZE size;
    LPOLESTR pszDocString;
    LPOLESTR pszHelpFile;
    DWORD dwHelpContext;
    } 	PROPPAGEINFO;

typedef struct tagPROPPAGEINFO *LPPROPPAGEINFO;


EXTERN_C const IID IID_IPropertyPage;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B196B28D-BAB4-101A-B69C-00AA00341D07")
    IPropertyPage : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetPageSite( 
            /* [annotation][in] */ 
            _In_  IPropertyPageSite *pPageSite) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Activate( 
            /* [annotation][in] */ 
            _In_  HWND hWndParent,
            /* [annotation][in] */ 
            _In_  LPCRECT pRect,
            /* [annotation][in] */ 
            _In_  BOOL bModal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Deactivate( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPageInfo( 
            /* [annotation][out] */ 
            _Out_  PROPPAGEINFO *pPageInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetObjects( 
            /* [annotation][in] */ 
            _In_  ULONG cObjects,
            /* [annotation][size_is][in] */ 
            _In_reads_(cObjects)  IUnknown **ppUnk) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Show( 
            /* [annotation][in] */ 
            _In_  UINT nCmdShow) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Move( 
            /* [annotation][in] */ 
            _In_  LPCRECT pRect) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsPageDirty( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Apply( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Help( 
            /* [annotation][in] */ 
            _In_  LPCOLESTR pszHelpDir) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE TranslateAccelerator( 
            /* [annotation][in] */ 
            _In_  MSG *pMsg) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IPropertyPageVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IPropertyPage * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IPropertyPage * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IPropertyPage * This);
        
        DECLSPEC_XFGVIRT(IPropertyPage, SetPageSite)
        HRESULT ( STDMETHODCALLTYPE *SetPageSite )( 
            __RPC__in IPropertyPage * This,
            /* [annotation][in] */ 
            _In_  IPropertyPageSite *pPageSite);
        
        DECLSPEC_XFGVIRT(IPropertyPage, Activate)
        HRESULT ( STDMETHODCALLTYPE *Activate )( 
            __RPC__in IPropertyPage * This,
            /* [annotation][in] */ 
            _In_  HWND hWndParent,
            /* [annotation][in] */ 
            _In_  LPCRECT pRect,
            /* [annotation][in] */ 
            _In_  BOOL bModal);
        
        DECLSPEC_XFGVIRT(IPropertyPage, Deactivate)
        HRESULT ( STDMETHODCALLTYPE *Deactivate )( 
            __RPC__in IPropertyPage * This);
        
        DECLSPEC_XFGVIRT(IPropertyPage, GetPageInfo)
        HRESULT ( STDMETHODCALLTYPE *GetPageInfo )( 
            __RPC__in IPropertyPage * This,
            /* [annotation][out] */ 
            _Out_  PROPPAGEINFO *pPageInfo);
        
        DECLSPEC_XFGVIRT(IPropertyPage, SetObjects)
        HRESULT ( STDMETHODCALLTYPE *SetObjects )( 
            __RPC__in IPropertyPage * This,
            /* [annotation][in] */ 
            _In_  ULONG cObjects,
            /* [annotation][size_is][in] */ 
            _In_reads_(cObjects)  IUnknown **ppUnk);
        
        DECLSPEC_XFGVIRT(IPropertyPage, Show)
        HRESULT ( STDMETHODCALLTYPE *Show )( 
            __RPC__in IPropertyPage * This,
            /* [annotation][in] */ 
            _In_  UINT nCmdShow);
        
        DECLSPEC_XFGVIRT(IPropertyPage, Move)
        HRESULT ( STDMETHODCALLTYPE *Move )( 
            __RPC__in IPropertyPage * This,
            /* [annotation][in] */ 
            _In_  LPCRECT pRect);
        
        DECLSPEC_XFGVIRT(IPropertyPage, IsPageDirty)
        HRESULT ( STDMETHODCALLTYPE *IsPageDirty )( 
            __RPC__in IPropertyPage * This);
        
        DECLSPEC_XFGVIRT(IPropertyPage, Apply)
        HRESULT ( STDMETHODCALLTYPE *Apply )( 
            __RPC__in IPropertyPage * This);
        
        DECLSPEC_XFGVIRT(IPropertyPage, Help)
        HRESULT ( STDMETHODCALLTYPE *Help )( 
            __RPC__in IPropertyPage * This,
            /* [annotation][in] */ 
            _In_  LPCOLESTR pszHelpDir);
        
        DECLSPEC_XFGVIRT(IPropertyPage, TranslateAccelerator)
        HRESULT ( STDMETHODCALLTYPE *TranslateAccelerator )( 
            __RPC__in IPropertyPage * This,
            /* [annotation][in] */ 
            _In_  MSG *pMsg);
        
        END_INTERFACE
    } IPropertyPageVtbl;

    interface IPropertyPage
    {
        CONST_VTBL struct IPropertyPageVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPropertyPage_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPropertyPage_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPropertyPage_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPropertyPage_SetPageSite(This,pPageSite)	\
    ( (This)->lpVtbl -> SetPageSite(This,pPageSite) ) 

#define IPropertyPage_Activate(This,hWndParent,pRect,bModal)	\
    ( (This)->lpVtbl -> Activate(This,hWndParent,pRect,bModal) ) 

#define IPropertyPage_Deactivate(This)	\
    ( (This)->lpVtbl -> Deactivate(This) ) 

#define IPropertyPage_GetPageInfo(This,pPageInfo)	\
    ( (This)->lpVtbl -> GetPageInfo(This,pPageInfo) ) 

#define IPropertyPage_SetObjects(This,cObjects,ppUnk)	\
    ( (This)->lpVtbl -> SetObjects(This,cObjects,ppUnk) ) 

#define IPropertyPage_Show(This,nCmdShow)	\
    ( (This)->lpVtbl -> Show(This,nCmdShow) ) 

#define IPropertyPage_Move(This,pRect)	\
    ( (This)->lpVtbl -> Move(This,pRect) ) 

#define IPropertyPage_IsPageDirty(This)	\
    ( (This)->lpVtbl -> IsPageDirty(This) ) 

#define IPropertyPage_Apply(This)	\
    ( (This)->lpVtbl -> Apply(This) ) 

#define IPropertyPage_Help(This,pszHelpDir)	\
    ( (This)->lpVtbl -> Help(This,pszHelpDir) ) 

#define IPropertyPage_TranslateAccelerator(This,pMsg)	\
    ( (This)->lpVtbl -> TranslateAccelerator(This,pMsg) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPropertyPage_INTERFACE_DEFINED__ */


#ifndef __IPropertyPage2_INTERFACE_DEFINED__
#define __IPropertyPage2_INTERFACE_DEFINED__

/* interface IPropertyPage2 */
/* [unique][uuid][object] */ 

typedef IPropertyPage2 *LPPROPERTYPAGE2;


EXTERN_C const IID IID_IPropertyPage2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("01E44665-24AC-101B-84ED-08002B2EC713")
    IPropertyPage2 : public IPropertyPage
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE EditProperty( 
            /* [annotation][in] */ 
            _In_  DISPID dispID) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IPropertyPage2Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IPropertyPage2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IPropertyPage2 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IPropertyPage2 * This);
        
        DECLSPEC_XFGVIRT(IPropertyPage, SetPageSite)
        HRESULT ( STDMETHODCALLTYPE *SetPageSite )( 
            __RPC__in IPropertyPage2 * This,
            /* [annotation][in] */ 
            _In_  IPropertyPageSite *pPageSite);
        
        DECLSPEC_XFGVIRT(IPropertyPage, Activate)
        HRESULT ( STDMETHODCALLTYPE *Activate )( 
            __RPC__in IPropertyPage2 * This,
            /* [annotation][in] */ 
            _In_  HWND hWndParent,
            /* [annotation][in] */ 
            _In_  LPCRECT pRect,
            /* [annotation][in] */ 
            _In_  BOOL bModal);
        
        DECLSPEC_XFGVIRT(IPropertyPage, Deactivate)
        HRESULT ( STDMETHODCALLTYPE *Deactivate )( 
            __RPC__in IPropertyPage2 * This);
        
        DECLSPEC_XFGVIRT(IPropertyPage, GetPageInfo)
        HRESULT ( STDMETHODCALLTYPE *GetPageInfo )( 
            __RPC__in IPropertyPage2 * This,
            /* [annotation][out] */ 
            _Out_  PROPPAGEINFO *pPageInfo);
        
        DECLSPEC_XFGVIRT(IPropertyPage, SetObjects)
        HRESULT ( STDMETHODCALLTYPE *SetObjects )( 
            __RPC__in IPropertyPage2 * This,
            /* [annotation][in] */ 
            _In_  ULONG cObjects,
            /* [annotation][size_is][in] */ 
            _In_reads_(cObjects)  IUnknown **ppUnk);
        
        DECLSPEC_XFGVIRT(IPropertyPage, Show)
        HRESULT ( STDMETHODCALLTYPE *Show )( 
            __RPC__in IPropertyPage2 * This,
            /* [annotation][in] */ 
            _In_  UINT nCmdShow);
        
        DECLSPEC_XFGVIRT(IPropertyPage, Move)
        HRESULT ( STDMETHODCALLTYPE *Move )( 
            __RPC__in IPropertyPage2 * This,
            /* [annotation][in] */ 
            _In_  LPCRECT pRect);
        
        DECLSPEC_XFGVIRT(IPropertyPage, IsPageDirty)
        HRESULT ( STDMETHODCALLTYPE *IsPageDirty )( 
            __RPC__in IPropertyPage2 * This);
        
        DECLSPEC_XFGVIRT(IPropertyPage, Apply)
        HRESULT ( STDMETHODCALLTYPE *Apply )( 
            __RPC__in IPropertyPage2 * This);
        
        DECLSPEC_XFGVIRT(IPropertyPage, Help)
        HRESULT ( STDMETHODCALLTYPE *Help )( 
            __RPC__in IPropertyPage2 * This,
            /* [annotation][in] */ 
            _In_  LPCOLESTR pszHelpDir);
        
        DECLSPEC_XFGVIRT(IPropertyPage, TranslateAccelerator)
        HRESULT ( STDMETHODCALLTYPE *TranslateAccelerator )( 
            __RPC__in IPropertyPage2 * This,
            /* [annotation][in] */ 
            _In_  MSG *pMsg);
        
        DECLSPEC_XFGVIRT(IPropertyPage2, EditProperty)
        HRESULT ( STDMETHODCALLTYPE *EditProperty )( 
            __RPC__in IPropertyPage2 * This,
            /* [annotation][in] */ 
            _In_  DISPID dispID);
        
        END_INTERFACE
    } IPropertyPage2Vtbl;

    interface IPropertyPage2
    {
        CONST_VTBL struct IPropertyPage2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPropertyPage2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPropertyPage2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPropertyPage2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPropertyPage2_SetPageSite(This,pPageSite)	\
    ( (This)->lpVtbl -> SetPageSite(This,pPageSite) ) 

#define IPropertyPage2_Activate(This,hWndParent,pRect,bModal)	\
    ( (This)->lpVtbl -> Activate(This,hWndParent,pRect,bModal) ) 

#define IPropertyPage2_Deactivate(This)	\
    ( (This)->lpVtbl -> Deactivate(This) ) 

#define IPropertyPage2_GetPageInfo(This,pPageInfo)	\
    ( (This)->lpVtbl -> GetPageInfo(This,pPageInfo) ) 

#define IPropertyPage2_SetObjects(This,cObjects,ppUnk)	\
    ( (This)->lpVtbl -> SetObjects(This,cObjects,ppUnk) ) 

#define IPropertyPage2_Show(This,nCmdShow)	\
    ( (This)->lpVtbl -> Show(This,nCmdShow) ) 

#define IPropertyPage2_Move(This,pRect)	\
    ( (This)->lpVtbl -> Move(This,pRect) ) 

#define IPropertyPage2_IsPageDirty(This)	\
    ( (This)->lpVtbl -> IsPageDirty(This) ) 

#define IPropertyPage2_Apply(This)	\
    ( (This)->lpVtbl -> Apply(This) ) 

#define IPropertyPage2_Help(This,pszHelpDir)	\
    ( (This)->lpVtbl -> Help(This,pszHelpDir) ) 

#define IPropertyPage2_TranslateAccelerator(This,pMsg)	\
    ( (This)->lpVtbl -> TranslateAccelerator(This,pMsg) ) 


#define IPropertyPage2_EditProperty(This,dispID)	\
    ( (This)->lpVtbl -> EditProperty(This,dispID) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPropertyPage2_INTERFACE_DEFINED__ */


#ifndef __IPropertyPageSite_INTERFACE_DEFINED__
#define __IPropertyPageSite_INTERFACE_DEFINED__

/* interface IPropertyPageSite */
/* [unique][uuid][object] */ 

typedef IPropertyPageSite *LPPROPERTYPAGESITE;

typedef 
enum tagPROPPAGESTATUS
    {
        PROPPAGESTATUS_DIRTY	= 0x1,
        PROPPAGESTATUS_VALIDATE	= 0x2,
        PROPPAGESTATUS_CLEAN	= 0x4
    } 	PROPPAGESTATUS;


EXTERN_C const IID IID_IPropertyPageSite;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B196B28C-BAB4-101A-B69C-00AA00341D07")
    IPropertyPageSite : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnStatusChange( 
            /* [annotation][in] */ 
            _In_  DWORD dwFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLocaleID( 
            /* [annotation][out] */ 
            _Out_  LCID *pLocaleID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPageContainer( 
            /* [annotation][out] */ 
            _Out_  IUnknown **ppUnk) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE TranslateAccelerator( 
            /* [annotation][in] */ 
            _In_  MSG *pMsg) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IPropertyPageSiteVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IPropertyPageSite * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IPropertyPageSite * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IPropertyPageSite * This);
        
        DECLSPEC_XFGVIRT(IPropertyPageSite, OnStatusChange)
        HRESULT ( STDMETHODCALLTYPE *OnStatusChange )( 
            __RPC__in IPropertyPageSite * This,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags);
        
        DECLSPEC_XFGVIRT(IPropertyPageSite, GetLocaleID)
        HRESULT ( STDMETHODCALLTYPE *GetLocaleID )( 
            __RPC__in IPropertyPageSite * This,
            /* [annotation][out] */ 
            _Out_  LCID *pLocaleID);
        
        DECLSPEC_XFGVIRT(IPropertyPageSite, GetPageContainer)
        HRESULT ( STDMETHODCALLTYPE *GetPageContainer )( 
            __RPC__in IPropertyPageSite * This,
            /* [annotation][out] */ 
            _Out_  IUnknown **ppUnk);
        
        DECLSPEC_XFGVIRT(IPropertyPageSite, TranslateAccelerator)
        HRESULT ( STDMETHODCALLTYPE *TranslateAccelerator )( 
            __RPC__in IPropertyPageSite * This,
            /* [annotation][in] */ 
            _In_  MSG *pMsg);
        
        END_INTERFACE
    } IPropertyPageSiteVtbl;

    interface IPropertyPageSite
    {
        CONST_VTBL struct IPropertyPageSiteVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPropertyPageSite_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPropertyPageSite_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPropertyPageSite_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPropertyPageSite_OnStatusChange(This,dwFlags)	\
    ( (This)->lpVtbl -> OnStatusChange(This,dwFlags) ) 

#define IPropertyPageSite_GetLocaleID(This,pLocaleID)	\
    ( (This)->lpVtbl -> GetLocaleID(This,pLocaleID) ) 

#define IPropertyPageSite_GetPageContainer(This,ppUnk)	\
    ( (This)->lpVtbl -> GetPageContainer(This,ppUnk) ) 

#define IPropertyPageSite_TranslateAccelerator(This,pMsg)	\
    ( (This)->lpVtbl -> TranslateAccelerator(This,pMsg) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPropertyPageSite_INTERFACE_DEFINED__ */


#ifndef __IPropertyNotifySink_INTERFACE_DEFINED__
#define __IPropertyNotifySink_INTERFACE_DEFINED__

/* interface IPropertyNotifySink */
/* [unique][uuid][object] */ 

typedef IPropertyNotifySink *LPPROPERTYNOTIFYSINK;


EXTERN_C const IID IID_IPropertyNotifySink;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9BFBBC02-EFF1-101A-84ED-00AA00341D07")
    IPropertyNotifySink : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnChanged( 
            /* [annotation][in] */ 
            _In_  DISPID dispID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnRequestEdit( 
            /* [annotation][in] */ 
            _In_  DISPID dispID) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IPropertyNotifySinkVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IPropertyNotifySink * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IPropertyNotifySink * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IPropertyNotifySink * This);
        
        DECLSPEC_XFGVIRT(IPropertyNotifySink, OnChanged)
        HRESULT ( STDMETHODCALLTYPE *OnChanged )( 
            __RPC__in IPropertyNotifySink * This,
            /* [annotation][in] */ 
            _In_  DISPID dispID);
        
        DECLSPEC_XFGVIRT(IPropertyNotifySink, OnRequestEdit)
        HRESULT ( STDMETHODCALLTYPE *OnRequestEdit )( 
            __RPC__in IPropertyNotifySink * This,
            /* [annotation][in] */ 
            _In_  DISPID dispID);
        
        END_INTERFACE
    } IPropertyNotifySinkVtbl;

    interface IPropertyNotifySink
    {
        CONST_VTBL struct IPropertyNotifySinkVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPropertyNotifySink_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPropertyNotifySink_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPropertyNotifySink_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPropertyNotifySink_OnChanged(This,dispID)	\
    ( (This)->lpVtbl -> OnChanged(This,dispID) ) 

#define IPropertyNotifySink_OnRequestEdit(This,dispID)	\
    ( (This)->lpVtbl -> OnRequestEdit(This,dispID) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPropertyNotifySink_INTERFACE_DEFINED__ */


#ifndef __ISpecifyPropertyPages_INTERFACE_DEFINED__
#define __ISpecifyPropertyPages_INTERFACE_DEFINED__

/* interface ISpecifyPropertyPages */
/* [unique][uuid][object] */ 

typedef ISpecifyPropertyPages *LPSPECIFYPROPERTYPAGES;

typedef struct tagCAUUID
    {
    ULONG cElems;
    /* [size_is] */ GUID *pElems;
    } 	CAUUID;

typedef struct tagCAUUID *LPCAUUID;


EXTERN_C const IID IID_ISpecifyPropertyPages;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B196B28B-BAB4-101A-B69C-00AA00341D07")
    ISpecifyPropertyPages : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetPages( 
            /* [annotation][out] */ 
            _Out_  CAUUID *pPages) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpecifyPropertyPagesVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpecifyPropertyPages * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpecifyPropertyPages * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpecifyPropertyPages * This);
        
        DECLSPEC_XFGVIRT(ISpecifyPropertyPages, GetPages)
        HRESULT ( STDMETHODCALLTYPE *GetPages )( 
            __RPC__in ISpecifyPropertyPages * This,
            /* [annotation][out] */ 
            _Out_  CAUUID *pPages);
        
        END_INTERFACE
    } ISpecifyPropertyPagesVtbl;

    interface ISpecifyPropertyPages
    {
        CONST_VTBL struct ISpecifyPropertyPagesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpecifyPropertyPages_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpecifyPropertyPages_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpecifyPropertyPages_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpecifyPropertyPages_GetPages(This,pPages)	\
    ( (This)->lpVtbl -> GetPages(This,pPages) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpecifyPropertyPages_INTERFACE_DEFINED__ */


#ifndef __IPersistMemory_INTERFACE_DEFINED__
#define __IPersistMemory_INTERFACE_DEFINED__

/* interface IPersistMemory */
/* [unique][uuid][object] */ 

typedef IPersistMemory *LPPERSISTMEMORY;


EXTERN_C const IID IID_IPersistMemory;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BD1AE5E0-A6AE-11CE-BD37-504200C10000")
    IPersistMemory : public IPersist
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE IsDirty( void) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE Load( 
            /* [annotation][size_is][in] */ 
            _In_reads_(cbSize)  LPVOID pMem,
            /* [annotation][in] */ 
            _In_  ULONG cbSize) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE Save( 
            /* [annotation][size_is][out] */ 
            _Out_writes_(cbSize)  LPVOID pMem,
            /* [annotation][in] */ 
            _In_  BOOL fClearDirty,
            /* [annotation][in] */ 
            _In_  ULONG cbSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSizeMax( 
            /* [annotation][out] */ 
            _Out_  ULONG *pCbSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InitNew( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IPersistMemoryVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IPersistMemory * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IPersistMemory * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IPersistMemory * This);
        
        DECLSPEC_XFGVIRT(IPersist, GetClassID)
        HRESULT ( STDMETHODCALLTYPE *GetClassID )( 
            __RPC__in IPersistMemory * This,
            /* [annotation][out] */ 
            _Out_  CLSID *pClassID);
        
        DECLSPEC_XFGVIRT(IPersistMemory, IsDirty)
        HRESULT ( STDMETHODCALLTYPE *IsDirty )( 
            __RPC__in IPersistMemory * This);
        
        DECLSPEC_XFGVIRT(IPersistMemory, Load)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Load )( 
            IPersistMemory * This,
            /* [annotation][size_is][in] */ 
            _In_reads_(cbSize)  LPVOID pMem,
            /* [annotation][in] */ 
            _In_  ULONG cbSize);
        
        DECLSPEC_XFGVIRT(IPersistMemory, Save)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Save )( 
            IPersistMemory * This,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cbSize)  LPVOID pMem,
            /* [annotation][in] */ 
            _In_  BOOL fClearDirty,
            /* [annotation][in] */ 
            _In_  ULONG cbSize);
        
        DECLSPEC_XFGVIRT(IPersistMemory, GetSizeMax)
        HRESULT ( STDMETHODCALLTYPE *GetSizeMax )( 
            __RPC__in IPersistMemory * This,
            /* [annotation][out] */ 
            _Out_  ULONG *pCbSize);
        
        DECLSPEC_XFGVIRT(IPersistMemory, InitNew)
        HRESULT ( STDMETHODCALLTYPE *InitNew )( 
            __RPC__in IPersistMemory * This);
        
        END_INTERFACE
    } IPersistMemoryVtbl;

    interface IPersistMemory
    {
        CONST_VTBL struct IPersistMemoryVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPersistMemory_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPersistMemory_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPersistMemory_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPersistMemory_GetClassID(This,pClassID)	\
    ( (This)->lpVtbl -> GetClassID(This,pClassID) ) 


#define IPersistMemory_IsDirty(This)	\
    ( (This)->lpVtbl -> IsDirty(This) ) 

#define IPersistMemory_Load(This,pMem,cbSize)	\
    ( (This)->lpVtbl -> Load(This,pMem,cbSize) ) 

#define IPersistMemory_Save(This,pMem,fClearDirty,cbSize)	\
    ( (This)->lpVtbl -> Save(This,pMem,fClearDirty,cbSize) ) 

#define IPersistMemory_GetSizeMax(This,pCbSize)	\
    ( (This)->lpVtbl -> GetSizeMax(This,pCbSize) ) 

#define IPersistMemory_InitNew(This)	\
    ( (This)->lpVtbl -> InitNew(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT STDMETHODCALLTYPE IPersistMemory_RemoteLoad_Proxy( 
    __RPC__in IPersistMemory * This,
    /* [annotation][size_is][in] */ 
    _In_reads_(cbSize)  BYTE *pMem,
    /* [annotation][in] */ 
    _In_  ULONG cbSize);


void __RPC_STUB IPersistMemory_RemoteLoad_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IPersistMemory_RemoteSave_Proxy( 
    __RPC__in IPersistMemory * This,
    /* [annotation][size_is][out] */ 
    _Out_writes_(cbSize)  BYTE *pMem,
    /* [annotation][in] */ 
    _In_  BOOL fClearDirty,
    /* [annotation][in] */ 
    _In_  ULONG cbSize);


void __RPC_STUB IPersistMemory_RemoteSave_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPersistMemory_INTERFACE_DEFINED__ */


#ifndef __IPersistStreamInit_INTERFACE_DEFINED__
#define __IPersistStreamInit_INTERFACE_DEFINED__

/* interface IPersistStreamInit */
/* [unique][uuid][object] */ 

typedef IPersistStreamInit *LPPERSISTSTREAMINIT;


EXTERN_C const IID IID_IPersistStreamInit;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7FD52380-4E07-101B-AE2D-08002B2EC713")
    IPersistStreamInit : public IPersist
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE IsDirty( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Load( 
            /* [annotation][in] */ 
            _In_  LPSTREAM pStm) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Save( 
            /* [annotation][in] */ 
            _In_  LPSTREAM pStm,
            /* [annotation][in] */ 
            _In_  BOOL fClearDirty) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSizeMax( 
            /* [annotation][out] */ 
            _Out_  ULARGE_INTEGER *pCbSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InitNew( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IPersistStreamInitVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IPersistStreamInit * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IPersistStreamInit * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IPersistStreamInit * This);
        
        DECLSPEC_XFGVIRT(IPersist, GetClassID)
        HRESULT ( STDMETHODCALLTYPE *GetClassID )( 
            __RPC__in IPersistStreamInit * This,
            /* [annotation][out] */ 
            _Out_  CLSID *pClassID);
        
        DECLSPEC_XFGVIRT(IPersistStreamInit, IsDirty)
        HRESULT ( STDMETHODCALLTYPE *IsDirty )( 
            __RPC__in IPersistStreamInit * This);
        
        DECLSPEC_XFGVIRT(IPersistStreamInit, Load)
        HRESULT ( STDMETHODCALLTYPE *Load )( 
            __RPC__in IPersistStreamInit * This,
            /* [annotation][in] */ 
            _In_  LPSTREAM pStm);
        
        DECLSPEC_XFGVIRT(IPersistStreamInit, Save)
        HRESULT ( STDMETHODCALLTYPE *Save )( 
            __RPC__in IPersistStreamInit * This,
            /* [annotation][in] */ 
            _In_  LPSTREAM pStm,
            /* [annotation][in] */ 
            _In_  BOOL fClearDirty);
        
        DECLSPEC_XFGVIRT(IPersistStreamInit, GetSizeMax)
        HRESULT ( STDMETHODCALLTYPE *GetSizeMax )( 
            __RPC__in IPersistStreamInit * This,
            /* [annotation][out] */ 
            _Out_  ULARGE_INTEGER *pCbSize);
        
        DECLSPEC_XFGVIRT(IPersistStreamInit, InitNew)
        HRESULT ( STDMETHODCALLTYPE *InitNew )( 
            __RPC__in IPersistStreamInit * This);
        
        END_INTERFACE
    } IPersistStreamInitVtbl;

    interface IPersistStreamInit
    {
        CONST_VTBL struct IPersistStreamInitVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPersistStreamInit_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPersistStreamInit_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPersistStreamInit_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPersistStreamInit_GetClassID(This,pClassID)	\
    ( (This)->lpVtbl -> GetClassID(This,pClassID) ) 


#define IPersistStreamInit_IsDirty(This)	\
    ( (This)->lpVtbl -> IsDirty(This) ) 

#define IPersistStreamInit_Load(This,pStm)	\
    ( (This)->lpVtbl -> Load(This,pStm) ) 

#define IPersistStreamInit_Save(This,pStm,fClearDirty)	\
    ( (This)->lpVtbl -> Save(This,pStm,fClearDirty) ) 

#define IPersistStreamInit_GetSizeMax(This,pCbSize)	\
    ( (This)->lpVtbl -> GetSizeMax(This,pCbSize) ) 

#define IPersistStreamInit_InitNew(This)	\
    ( (This)->lpVtbl -> InitNew(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPersistStreamInit_INTERFACE_DEFINED__ */


#ifndef __IPersistPropertyBag_INTERFACE_DEFINED__
#define __IPersistPropertyBag_INTERFACE_DEFINED__

/* interface IPersistPropertyBag */
/* [unique][uuid][object] */ 

typedef IPersistPropertyBag *LPPERSISTPROPERTYBAG;


EXTERN_C const IID IID_IPersistPropertyBag;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("37D84F60-42CB-11CE-8135-00AA004BB851")
    IPersistPropertyBag : public IPersist
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE InitNew( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Load( 
            /* [annotation][in] */ 
            _In_  IPropertyBag *pPropBag,
            /* [annotation][unique][in] */ 
            _In_  IErrorLog *pErrorLog) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Save( 
            /* [annotation][in] */ 
            _In_  IPropertyBag *pPropBag,
            /* [annotation][in] */ 
            _In_  BOOL fClearDirty,
            /* [annotation][in] */ 
            _In_  BOOL fSaveAllProperties) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IPersistPropertyBagVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IPersistPropertyBag * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IPersistPropertyBag * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IPersistPropertyBag * This);
        
        DECLSPEC_XFGVIRT(IPersist, GetClassID)
        HRESULT ( STDMETHODCALLTYPE *GetClassID )( 
            __RPC__in IPersistPropertyBag * This,
            /* [annotation][out] */ 
            _Out_  CLSID *pClassID);
        
        DECLSPEC_XFGVIRT(IPersistPropertyBag, InitNew)
        HRESULT ( STDMETHODCALLTYPE *InitNew )( 
            __RPC__in IPersistPropertyBag * This);
        
        DECLSPEC_XFGVIRT(IPersistPropertyBag, Load)
        HRESULT ( STDMETHODCALLTYPE *Load )( 
            __RPC__in IPersistPropertyBag * This,
            /* [annotation][in] */ 
            _In_  IPropertyBag *pPropBag,
            /* [annotation][unique][in] */ 
            _In_  IErrorLog *pErrorLog);
        
        DECLSPEC_XFGVIRT(IPersistPropertyBag, Save)
        HRESULT ( STDMETHODCALLTYPE *Save )( 
            __RPC__in IPersistPropertyBag * This,
            /* [annotation][in] */ 
            _In_  IPropertyBag *pPropBag,
            /* [annotation][in] */ 
            _In_  BOOL fClearDirty,
            /* [annotation][in] */ 
            _In_  BOOL fSaveAllProperties);
        
        END_INTERFACE
    } IPersistPropertyBagVtbl;

    interface IPersistPropertyBag
    {
        CONST_VTBL struct IPersistPropertyBagVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPersistPropertyBag_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPersistPropertyBag_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPersistPropertyBag_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPersistPropertyBag_GetClassID(This,pClassID)	\
    ( (This)->lpVtbl -> GetClassID(This,pClassID) ) 


#define IPersistPropertyBag_InitNew(This)	\
    ( (This)->lpVtbl -> InitNew(This) ) 

#define IPersistPropertyBag_Load(This,pPropBag,pErrorLog)	\
    ( (This)->lpVtbl -> Load(This,pPropBag,pErrorLog) ) 

#define IPersistPropertyBag_Save(This,pPropBag,fClearDirty,fSaveAllProperties)	\
    ( (This)->lpVtbl -> Save(This,pPropBag,fClearDirty,fSaveAllProperties) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPersistPropertyBag_INTERFACE_DEFINED__ */


#ifndef __ISimpleFrameSite_INTERFACE_DEFINED__
#define __ISimpleFrameSite_INTERFACE_DEFINED__

/* interface ISimpleFrameSite */
/* [unique][uuid][object] */ 

typedef ISimpleFrameSite *LPSIMPLEFRAMESITE;


EXTERN_C const IID IID_ISimpleFrameSite;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("742B0E01-14E6-101B-914E-00AA00300CAB")
    ISimpleFrameSite : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE PreMessageFilter( 
            /* [annotation][in] */ 
            _In_  HWND hWnd,
            /* [annotation][in] */ 
            _In_  UINT msg,
            /* [annotation][in] */ 
            _In_  WPARAM wp,
            /* [annotation][in] */ 
            _In_  LPARAM lp,
            /* [annotation][out] */ 
            _Out_  LRESULT *plResult,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwCookie) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PostMessageFilter( 
            /* [annotation][in] */ 
            _In_  HWND hWnd,
            /* [annotation][in] */ 
            _In_  UINT msg,
            /* [annotation][in] */ 
            _In_  WPARAM wp,
            /* [annotation][in] */ 
            _In_  LPARAM lp,
            /* [annotation][out] */ 
            _Out_  LRESULT *plResult,
            /* [annotation][in] */ 
            _In_  DWORD dwCookie) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISimpleFrameSiteVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISimpleFrameSite * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISimpleFrameSite * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISimpleFrameSite * This);
        
        DECLSPEC_XFGVIRT(ISimpleFrameSite, PreMessageFilter)
        HRESULT ( STDMETHODCALLTYPE *PreMessageFilter )( 
            __RPC__in ISimpleFrameSite * This,
            /* [annotation][in] */ 
            _In_  HWND hWnd,
            /* [annotation][in] */ 
            _In_  UINT msg,
            /* [annotation][in] */ 
            _In_  WPARAM wp,
            /* [annotation][in] */ 
            _In_  LPARAM lp,
            /* [annotation][out] */ 
            _Out_  LRESULT *plResult,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwCookie);
        
        DECLSPEC_XFGVIRT(ISimpleFrameSite, PostMessageFilter)
        HRESULT ( STDMETHODCALLTYPE *PostMessageFilter )( 
            __RPC__in ISimpleFrameSite * This,
            /* [annotation][in] */ 
            _In_  HWND hWnd,
            /* [annotation][in] */ 
            _In_  UINT msg,
            /* [annotation][in] */ 
            _In_  WPARAM wp,
            /* [annotation][in] */ 
            _In_  LPARAM lp,
            /* [annotation][out] */ 
            _Out_  LRESULT *plResult,
            /* [annotation][in] */ 
            _In_  DWORD dwCookie);
        
        END_INTERFACE
    } ISimpleFrameSiteVtbl;

    interface ISimpleFrameSite
    {
        CONST_VTBL struct ISimpleFrameSiteVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISimpleFrameSite_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISimpleFrameSite_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISimpleFrameSite_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISimpleFrameSite_PreMessageFilter(This,hWnd,msg,wp,lp,plResult,pdwCookie)	\
    ( (This)->lpVtbl -> PreMessageFilter(This,hWnd,msg,wp,lp,plResult,pdwCookie) ) 

#define ISimpleFrameSite_PostMessageFilter(This,hWnd,msg,wp,lp,plResult,dwCookie)	\
    ( (This)->lpVtbl -> PostMessageFilter(This,hWnd,msg,wp,lp,plResult,dwCookie) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISimpleFrameSite_INTERFACE_DEFINED__ */


#ifndef __IFont_INTERFACE_DEFINED__
#define __IFont_INTERFACE_DEFINED__

/* interface IFont */
/* [unique][uuid][object] */ 

typedef IFont *LPFONT;

#if (defined(_WIN32) || defined (_WIN64)) && !defined(OLE2ANSI)
typedef TEXTMETRICW TEXTMETRICOLE;

#else
typedef TEXTMETRIC TEXTMETRICOLE;
#endif
typedef TEXTMETRICOLE *LPTEXTMETRICOLE;


EXTERN_C const IID IID_IFont;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BEF6E002-A874-101A-8BBA-00AA00300CAB")
    IFont : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE get_Name( 
            /* [annotation][out] */ 
            _Out_  BSTR *pName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_Name( 
            /* [annotation][in] */ 
            _In_  BSTR name) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_Size( 
            /* [annotation][out] */ 
            _Out_  CY *pSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_Size( 
            /* [annotation][in] */ 
            _In_  CY size) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_Bold( 
            /* [annotation][out] */ 
            _Out_  BOOL *pBold) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_Bold( 
            /* [annotation][in] */ 
            _In_  BOOL bold) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_Italic( 
            /* [annotation][out] */ 
            _Out_  BOOL *pItalic) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_Italic( 
            /* [annotation][in] */ 
            _In_  BOOL italic) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_Underline( 
            /* [annotation][out] */ 
            _Out_  BOOL *pUnderline) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_Underline( 
            /* [annotation][in] */ 
            _In_  BOOL underline) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_Strikethrough( 
            /* [annotation][out] */ 
            _Out_  BOOL *pStrikethrough) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_Strikethrough( 
            /* [annotation][in] */ 
            _In_  BOOL strikethrough) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_Weight( 
            /* [annotation][out] */ 
            _Out_  SHORT *pWeight) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_Weight( 
            /* [annotation][in] */ 
            _In_  SHORT weight) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_Charset( 
            /* [annotation][out] */ 
            _Out_  SHORT *pCharset) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_Charset( 
            /* [annotation][in] */ 
            _In_  SHORT charset) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_hFont( 
            /* [annotation][out] */ 
            _Out_  HFONT *phFont) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [annotation][out] */ 
            _Out_  IFont **ppFont) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsEqual( 
            /* [annotation][in] */ 
            _In_  IFont *pFontOther) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetRatio( 
            /* [annotation][in] */ 
            _In_  LONG cyLogical,
            /* [annotation][in] */ 
            _In_  LONG cyHimetric) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryTextMetrics( 
            /* [annotation][out] */ 
            _Out_  TEXTMETRICOLE *pTM) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddRefHfont( 
            /* [annotation][in] */ 
            _In_  HFONT hFont) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReleaseHfont( 
            /* [annotation][in] */ 
            _In_  HFONT hFont) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetHdc( 
            /* [annotation][in] */ 
            _In_  HDC hDC) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IFontVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IFont * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IFont * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IFont * This);
        
        DECLSPEC_XFGVIRT(IFont, get_Name)
        HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            __RPC__in IFont * This,
            /* [annotation][out] */ 
            _Out_  BSTR *pName);
        
        DECLSPEC_XFGVIRT(IFont, put_Name)
        HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            __RPC__in IFont * This,
            /* [annotation][in] */ 
            _In_  BSTR name);
        
        DECLSPEC_XFGVIRT(IFont, get_Size)
        HRESULT ( STDMETHODCALLTYPE *get_Size )( 
            __RPC__in IFont * This,
            /* [annotation][out] */ 
            _Out_  CY *pSize);
        
        DECLSPEC_XFGVIRT(IFont, put_Size)
        HRESULT ( STDMETHODCALLTYPE *put_Size )( 
            __RPC__in IFont * This,
            /* [annotation][in] */ 
            _In_  CY size);
        
        DECLSPEC_XFGVIRT(IFont, get_Bold)
        HRESULT ( STDMETHODCALLTYPE *get_Bold )( 
            __RPC__in IFont * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pBold);
        
        DECLSPEC_XFGVIRT(IFont, put_Bold)
        HRESULT ( STDMETHODCALLTYPE *put_Bold )( 
            __RPC__in IFont * This,
            /* [annotation][in] */ 
            _In_  BOOL bold);
        
        DECLSPEC_XFGVIRT(IFont, get_Italic)
        HRESULT ( STDMETHODCALLTYPE *get_Italic )( 
            __RPC__in IFont * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pItalic);
        
        DECLSPEC_XFGVIRT(IFont, put_Italic)
        HRESULT ( STDMETHODCALLTYPE *put_Italic )( 
            __RPC__in IFont * This,
            /* [annotation][in] */ 
            _In_  BOOL italic);
        
        DECLSPEC_XFGVIRT(IFont, get_Underline)
        HRESULT ( STDMETHODCALLTYPE *get_Underline )( 
            __RPC__in IFont * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pUnderline);
        
        DECLSPEC_XFGVIRT(IFont, put_Underline)
        HRESULT ( STDMETHODCALLTYPE *put_Underline )( 
            __RPC__in IFont * This,
            /* [annotation][in] */ 
            _In_  BOOL underline);
        
        DECLSPEC_XFGVIRT(IFont, get_Strikethrough)
        HRESULT ( STDMETHODCALLTYPE *get_Strikethrough )( 
            __RPC__in IFont * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pStrikethrough);
        
        DECLSPEC_XFGVIRT(IFont, put_Strikethrough)
        HRESULT ( STDMETHODCALLTYPE *put_Strikethrough )( 
            __RPC__in IFont * This,
            /* [annotation][in] */ 
            _In_  BOOL strikethrough);
        
        DECLSPEC_XFGVIRT(IFont, get_Weight)
        HRESULT ( STDMETHODCALLTYPE *get_Weight )( 
            __RPC__in IFont * This,
            /* [annotation][out] */ 
            _Out_  SHORT *pWeight);
        
        DECLSPEC_XFGVIRT(IFont, put_Weight)
        HRESULT ( STDMETHODCALLTYPE *put_Weight )( 
            __RPC__in IFont * This,
            /* [annotation][in] */ 
            _In_  SHORT weight);
        
        DECLSPEC_XFGVIRT(IFont, get_Charset)
        HRESULT ( STDMETHODCALLTYPE *get_Charset )( 
            __RPC__in IFont * This,
            /* [annotation][out] */ 
            _Out_  SHORT *pCharset);
        
        DECLSPEC_XFGVIRT(IFont, put_Charset)
        HRESULT ( STDMETHODCALLTYPE *put_Charset )( 
            __RPC__in IFont * This,
            /* [annotation][in] */ 
            _In_  SHORT charset);
        
        DECLSPEC_XFGVIRT(IFont, get_hFont)
        HRESULT ( STDMETHODCALLTYPE *get_hFont )( 
            __RPC__in IFont * This,
            /* [annotation][out] */ 
            _Out_  HFONT *phFont);
        
        DECLSPEC_XFGVIRT(IFont, Clone)
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            __RPC__in IFont * This,
            /* [annotation][out] */ 
            _Out_  IFont **ppFont);
        
        DECLSPEC_XFGVIRT(IFont, IsEqual)
        HRESULT ( STDMETHODCALLTYPE *IsEqual )( 
            __RPC__in IFont * This,
            /* [annotation][in] */ 
            _In_  IFont *pFontOther);
        
        DECLSPEC_XFGVIRT(IFont, SetRatio)
        HRESULT ( STDMETHODCALLTYPE *SetRatio )( 
            __RPC__in IFont * This,
            /* [annotation][in] */ 
            _In_  LONG cyLogical,
            /* [annotation][in] */ 
            _In_  LONG cyHimetric);
        
        DECLSPEC_XFGVIRT(IFont, QueryTextMetrics)
        HRESULT ( STDMETHODCALLTYPE *QueryTextMetrics )( 
            __RPC__in IFont * This,
            /* [annotation][out] */ 
            _Out_  TEXTMETRICOLE *pTM);
        
        DECLSPEC_XFGVIRT(IFont, AddRefHfont)
        HRESULT ( STDMETHODCALLTYPE *AddRefHfont )( 
            __RPC__in IFont * This,
            /* [annotation][in] */ 
            _In_  HFONT hFont);
        
        DECLSPEC_XFGVIRT(IFont, ReleaseHfont)
        HRESULT ( STDMETHODCALLTYPE *ReleaseHfont )( 
            __RPC__in IFont * This,
            /* [annotation][in] */ 
            _In_  HFONT hFont);
        
        DECLSPEC_XFGVIRT(IFont, SetHdc)
        HRESULT ( STDMETHODCALLTYPE *SetHdc )( 
            __RPC__in IFont * This,
            /* [annotation][in] */ 
            _In_  HDC hDC);
        
        END_INTERFACE
    } IFontVtbl;

    interface IFont
    {
        CONST_VTBL struct IFontVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFont_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFont_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFont_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFont_get_Name(This,pName)	\
    ( (This)->lpVtbl -> get_Name(This,pName) ) 

#define IFont_put_Name(This,name)	\
    ( (This)->lpVtbl -> put_Name(This,name) ) 

#define IFont_get_Size(This,pSize)	\
    ( (This)->lpVtbl -> get_Size(This,pSize) ) 

#define IFont_put_Size(This,size)	\
    ( (This)->lpVtbl -> put_Size(This,size) ) 

#define IFont_get_Bold(This,pBold)	\
    ( (This)->lpVtbl -> get_Bold(This,pBold) ) 

#define IFont_put_Bold(This,bold)	\
    ( (This)->lpVtbl -> put_Bold(This,bold) ) 

#define IFont_get_Italic(This,pItalic)	\
    ( (This)->lpVtbl -> get_Italic(This,pItalic) ) 

#define IFont_put_Italic(This,italic)	\
    ( (This)->lpVtbl -> put_Italic(This,italic) ) 

#define IFont_get_Underline(This,pUnderline)	\
    ( (This)->lpVtbl -> get_Underline(This,pUnderline) ) 

#define IFont_put_Underline(This,underline)	\
    ( (This)->lpVtbl -> put_Underline(This,underline) ) 

#define IFont_get_Strikethrough(This,pStrikethrough)	\
    ( (This)->lpVtbl -> get_Strikethrough(This,pStrikethrough) ) 

#define IFont_put_Strikethrough(This,strikethrough)	\
    ( (This)->lpVtbl -> put_Strikethrough(This,strikethrough) ) 

#define IFont_get_Weight(This,pWeight)	\
    ( (This)->lpVtbl -> get_Weight(This,pWeight) ) 

#define IFont_put_Weight(This,weight)	\
    ( (This)->lpVtbl -> put_Weight(This,weight) ) 

#define IFont_get_Charset(This,pCharset)	\
    ( (This)->lpVtbl -> get_Charset(This,pCharset) ) 

#define IFont_put_Charset(This,charset)	\
    ( (This)->lpVtbl -> put_Charset(This,charset) ) 

#define IFont_get_hFont(This,phFont)	\
    ( (This)->lpVtbl -> get_hFont(This,phFont) ) 

#define IFont_Clone(This,ppFont)	\
    ( (This)->lpVtbl -> Clone(This,ppFont) ) 

#define IFont_IsEqual(This,pFontOther)	\
    ( (This)->lpVtbl -> IsEqual(This,pFontOther) ) 

#define IFont_SetRatio(This,cyLogical,cyHimetric)	\
    ( (This)->lpVtbl -> SetRatio(This,cyLogical,cyHimetric) ) 

#define IFont_QueryTextMetrics(This,pTM)	\
    ( (This)->lpVtbl -> QueryTextMetrics(This,pTM) ) 

#define IFont_AddRefHfont(This,hFont)	\
    ( (This)->lpVtbl -> AddRefHfont(This,hFont) ) 

#define IFont_ReleaseHfont(This,hFont)	\
    ( (This)->lpVtbl -> ReleaseHfont(This,hFont) ) 

#define IFont_SetHdc(This,hDC)	\
    ( (This)->lpVtbl -> SetHdc(This,hDC) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFont_INTERFACE_DEFINED__ */


#ifndef __IPicture_INTERFACE_DEFINED__
#define __IPicture_INTERFACE_DEFINED__

/* interface IPicture */
/* [unique][uuid][object] */ 

typedef IPicture *LPPICTURE;

typedef 
enum tagPictureAttributes
    {
        PICTURE_SCALABLE	= 0x1,
        PICTURE_TRANSPARENT	= 0x2
    } 	PICTUREATTRIBUTES;

typedef /* [public][uuid] */  DECLSPEC_UUID("66504313-BE0F-101A-8BBB-00AA00300CAB") UINT OLE_HANDLE;

typedef /* [hidden][uuid] */  DECLSPEC_UUID("66504306-BE0F-101A-8BBB-00AA00300CAB") LONG OLE_XPOS_HIMETRIC;

typedef /* [hidden][uuid] */  DECLSPEC_UUID("66504307-BE0F-101A-8BBB-00AA00300CAB") LONG OLE_YPOS_HIMETRIC;

typedef /* [hidden][uuid] */  DECLSPEC_UUID("66504308-BE0F-101A-8BBB-00AA00300CAB") LONG OLE_XSIZE_HIMETRIC;

typedef /* [hidden][uuid] */  DECLSPEC_UUID("66504309-BE0F-101A-8BBB-00AA00300CAB") LONG OLE_YSIZE_HIMETRIC;


EXTERN_C const IID IID_IPicture;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7BF80980-BF32-101A-8BBB-00AA00300CAB")
    IPicture : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE get_Handle( 
            /* [annotation][out] */ 
            _Out_  OLE_HANDLE *pHandle) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_hPal( 
            /* [annotation][out] */ 
            _Out_  OLE_HANDLE *phPal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_Type( 
            /* [annotation][out] */ 
            _Out_  SHORT *pType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_Width( 
            /* [annotation][out] */ 
            _Out_  OLE_XSIZE_HIMETRIC *pWidth) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_Height( 
            /* [annotation][out] */ 
            _Out_  OLE_YSIZE_HIMETRIC *pHeight) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Render( 
            /* [annotation][in] */ 
            _In_  HDC hDC,
            /* [annotation][in] */ 
            _In_  LONG x,
            /* [annotation][in] */ 
            _In_  LONG y,
            /* [annotation][in] */ 
            _In_  LONG cx,
            /* [annotation][in] */ 
            _In_  LONG cy,
            /* [annotation][in] */ 
            _In_  OLE_XPOS_HIMETRIC xSrc,
            /* [annotation][in] */ 
            _In_  OLE_YPOS_HIMETRIC ySrc,
            /* [annotation][in] */ 
            _In_  OLE_XSIZE_HIMETRIC cxSrc,
            /* [annotation][in] */ 
            _In_  OLE_YSIZE_HIMETRIC cySrc,
            /* [annotation][in] */ 
            _In_  LPCRECT pRcWBounds) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE set_hPal( 
            /* [annotation][in] */ 
            _In_  OLE_HANDLE hPal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_CurDC( 
            /* [annotation][out] */ 
            _Out_  HDC *phDC) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SelectPicture( 
            /* [annotation][in] */ 
            _In_  HDC hDCIn,
            /* [annotation][out] */ 
            _Out_  HDC *phDCOut,
            /* [annotation][out] */ 
            _Out_  OLE_HANDLE *phBmpOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_KeepOriginalFormat( 
            /* [annotation][out] */ 
            _Out_  BOOL *pKeep) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_KeepOriginalFormat( 
            /* [annotation][in] */ 
            _In_  BOOL keep) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PictureChanged( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SaveAsFile( 
            /* [annotation][in] */ 
            _In_  LPSTREAM pStream,
            /* [annotation][in] */ 
            _In_  BOOL fSaveMemCopy,
            /* [annotation][out] */ 
            _Out_  LONG *pCbSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_Attributes( 
            /* [annotation][out] */ 
            _Out_  DWORD *pDwAttr) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IPictureVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IPicture * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IPicture * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IPicture * This);
        
        DECLSPEC_XFGVIRT(IPicture, get_Handle)
        HRESULT ( STDMETHODCALLTYPE *get_Handle )( 
            __RPC__in IPicture * This,
            /* [annotation][out] */ 
            _Out_  OLE_HANDLE *pHandle);
        
        DECLSPEC_XFGVIRT(IPicture, get_hPal)
        HRESULT ( STDMETHODCALLTYPE *get_hPal )( 
            __RPC__in IPicture * This,
            /* [annotation][out] */ 
            _Out_  OLE_HANDLE *phPal);
        
        DECLSPEC_XFGVIRT(IPicture, get_Type)
        HRESULT ( STDMETHODCALLTYPE *get_Type )( 
            __RPC__in IPicture * This,
            /* [annotation][out] */ 
            _Out_  SHORT *pType);
        
        DECLSPEC_XFGVIRT(IPicture, get_Width)
        HRESULT ( STDMETHODCALLTYPE *get_Width )( 
            __RPC__in IPicture * This,
            /* [annotation][out] */ 
            _Out_  OLE_XSIZE_HIMETRIC *pWidth);
        
        DECLSPEC_XFGVIRT(IPicture, get_Height)
        HRESULT ( STDMETHODCALLTYPE *get_Height )( 
            __RPC__in IPicture * This,
            /* [annotation][out] */ 
            _Out_  OLE_YSIZE_HIMETRIC *pHeight);
        
        DECLSPEC_XFGVIRT(IPicture, Render)
        HRESULT ( STDMETHODCALLTYPE *Render )( 
            __RPC__in IPicture * This,
            /* [annotation][in] */ 
            _In_  HDC hDC,
            /* [annotation][in] */ 
            _In_  LONG x,
            /* [annotation][in] */ 
            _In_  LONG y,
            /* [annotation][in] */ 
            _In_  LONG cx,
            /* [annotation][in] */ 
            _In_  LONG cy,
            /* [annotation][in] */ 
            _In_  OLE_XPOS_HIMETRIC xSrc,
            /* [annotation][in] */ 
            _In_  OLE_YPOS_HIMETRIC ySrc,
            /* [annotation][in] */ 
            _In_  OLE_XSIZE_HIMETRIC cxSrc,
            /* [annotation][in] */ 
            _In_  OLE_YSIZE_HIMETRIC cySrc,
            /* [annotation][in] */ 
            _In_  LPCRECT pRcWBounds);
        
        DECLSPEC_XFGVIRT(IPicture, set_hPal)
        HRESULT ( STDMETHODCALLTYPE *set_hPal )( 
            __RPC__in IPicture * This,
            /* [annotation][in] */ 
            _In_  OLE_HANDLE hPal);
        
        DECLSPEC_XFGVIRT(IPicture, get_CurDC)
        HRESULT ( STDMETHODCALLTYPE *get_CurDC )( 
            __RPC__in IPicture * This,
            /* [annotation][out] */ 
            _Out_  HDC *phDC);
        
        DECLSPEC_XFGVIRT(IPicture, SelectPicture)
        HRESULT ( STDMETHODCALLTYPE *SelectPicture )( 
            __RPC__in IPicture * This,
            /* [annotation][in] */ 
            _In_  HDC hDCIn,
            /* [annotation][out] */ 
            _Out_  HDC *phDCOut,
            /* [annotation][out] */ 
            _Out_  OLE_HANDLE *phBmpOut);
        
        DECLSPEC_XFGVIRT(IPicture, get_KeepOriginalFormat)
        HRESULT ( STDMETHODCALLTYPE *get_KeepOriginalFormat )( 
            __RPC__in IPicture * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pKeep);
        
        DECLSPEC_XFGVIRT(IPicture, put_KeepOriginalFormat)
        HRESULT ( STDMETHODCALLTYPE *put_KeepOriginalFormat )( 
            __RPC__in IPicture * This,
            /* [annotation][in] */ 
            _In_  BOOL keep);
        
        DECLSPEC_XFGVIRT(IPicture, PictureChanged)
        HRESULT ( STDMETHODCALLTYPE *PictureChanged )( 
            __RPC__in IPicture * This);
        
        DECLSPEC_XFGVIRT(IPicture, SaveAsFile)
        HRESULT ( STDMETHODCALLTYPE *SaveAsFile )( 
            __RPC__in IPicture * This,
            /* [annotation][in] */ 
            _In_  LPSTREAM pStream,
            /* [annotation][in] */ 
            _In_  BOOL fSaveMemCopy,
            /* [annotation][out] */ 
            _Out_  LONG *pCbSize);
        
        DECLSPEC_XFGVIRT(IPicture, get_Attributes)
        HRESULT ( STDMETHODCALLTYPE *get_Attributes )( 
            __RPC__in IPicture * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pDwAttr);
        
        END_INTERFACE
    } IPictureVtbl;

    interface IPicture
    {
        CONST_VTBL struct IPictureVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPicture_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPicture_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPicture_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPicture_get_Handle(This,pHandle)	\
    ( (This)->lpVtbl -> get_Handle(This,pHandle) ) 

#define IPicture_get_hPal(This,phPal)	\
    ( (This)->lpVtbl -> get_hPal(This,phPal) ) 

#define IPicture_get_Type(This,pType)	\
    ( (This)->lpVtbl -> get_Type(This,pType) ) 

#define IPicture_get_Width(This,pWidth)	\
    ( (This)->lpVtbl -> get_Width(This,pWidth) ) 

#define IPicture_get_Height(This,pHeight)	\
    ( (This)->lpVtbl -> get_Height(This,pHeight) ) 

#define IPicture_Render(This,hDC,x,y,cx,cy,xSrc,ySrc,cxSrc,cySrc,pRcWBounds)	\
    ( (This)->lpVtbl -> Render(This,hDC,x,y,cx,cy,xSrc,ySrc,cxSrc,cySrc,pRcWBounds) ) 

#define IPicture_set_hPal(This,hPal)	\
    ( (This)->lpVtbl -> set_hPal(This,hPal) ) 

#define IPicture_get_CurDC(This,phDC)	\
    ( (This)->lpVtbl -> get_CurDC(This,phDC) ) 

#define IPicture_SelectPicture(This,hDCIn,phDCOut,phBmpOut)	\
    ( (This)->lpVtbl -> SelectPicture(This,hDCIn,phDCOut,phBmpOut) ) 

#define IPicture_get_KeepOriginalFormat(This,pKeep)	\
    ( (This)->lpVtbl -> get_KeepOriginalFormat(This,pKeep) ) 

#define IPicture_put_KeepOriginalFormat(This,keep)	\
    ( (This)->lpVtbl -> put_KeepOriginalFormat(This,keep) ) 

#define IPicture_PictureChanged(This)	\
    ( (This)->lpVtbl -> PictureChanged(This) ) 

#define IPicture_SaveAsFile(This,pStream,fSaveMemCopy,pCbSize)	\
    ( (This)->lpVtbl -> SaveAsFile(This,pStream,fSaveMemCopy,pCbSize) ) 

#define IPicture_get_Attributes(This,pDwAttr)	\
    ( (This)->lpVtbl -> get_Attributes(This,pDwAttr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPicture_INTERFACE_DEFINED__ */


#ifndef __IPicture2_INTERFACE_DEFINED__
#define __IPicture2_INTERFACE_DEFINED__

/* interface IPicture2 */
/* [unique][uuid][object] */ 

typedef IPicture2 *LPPICTURE2;

typedef UINT_PTR HHANDLE;


EXTERN_C const IID IID_IPicture2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F5185DD8-2012-4b0b-AAD9-F052C6BD482B")
    IPicture2 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE get_Handle( 
            /* [annotation][out] */ 
            _Out_  HHANDLE *pHandle) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_hPal( 
            /* [annotation][out] */ 
            _Out_  HHANDLE *phPal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_Type( 
            /* [annotation][out] */ 
            _Out_  SHORT *pType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_Width( 
            /* [annotation][out] */ 
            _Out_  OLE_XSIZE_HIMETRIC *pWidth) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_Height( 
            /* [annotation][out] */ 
            _Out_  OLE_YSIZE_HIMETRIC *pHeight) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Render( 
            /* [annotation][in] */ 
            _In_  HDC hDC,
            /* [annotation][in] */ 
            _In_  LONG x,
            /* [annotation][in] */ 
            _In_  LONG y,
            /* [annotation][in] */ 
            _In_  LONG cx,
            /* [annotation][in] */ 
            _In_  LONG cy,
            /* [annotation][in] */ 
            _In_  OLE_XPOS_HIMETRIC xSrc,
            /* [annotation][in] */ 
            _In_  OLE_YPOS_HIMETRIC ySrc,
            /* [annotation][in] */ 
            _In_  OLE_XSIZE_HIMETRIC cxSrc,
            /* [annotation][in] */ 
            _In_  OLE_YSIZE_HIMETRIC cySrc,
            /* [annotation][in] */ 
            _In_  LPCRECT pRcWBounds) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE set_hPal( 
            /* [annotation][in] */ 
            _In_  HHANDLE hPal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_CurDC( 
            /* [annotation][out] */ 
            _Out_  HDC *phDC) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SelectPicture( 
            /* [annotation][in] */ 
            _In_  HDC hDCIn,
            /* [annotation][out] */ 
            _Out_  HDC *phDCOut,
            /* [annotation][out] */ 
            _Out_  HHANDLE *phBmpOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_KeepOriginalFormat( 
            /* [annotation][out] */ 
            _Out_  BOOL *pKeep) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_KeepOriginalFormat( 
            /* [annotation][in] */ 
            _In_  BOOL keep) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PictureChanged( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SaveAsFile( 
            /* [annotation][in] */ 
            _In_  LPSTREAM pStream,
            /* [annotation][in] */ 
            _In_  BOOL fSaveMemCopy,
            /* [annotation][out] */ 
            _Out_  LONG *pCbSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_Attributes( 
            /* [annotation][out] */ 
            _Out_  DWORD *pDwAttr) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IPicture2Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IPicture2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IPicture2 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IPicture2 * This);
        
        DECLSPEC_XFGVIRT(IPicture2, get_Handle)
        HRESULT ( STDMETHODCALLTYPE *get_Handle )( 
            __RPC__in IPicture2 * This,
            /* [annotation][out] */ 
            _Out_  HHANDLE *pHandle);
        
        DECLSPEC_XFGVIRT(IPicture2, get_hPal)
        HRESULT ( STDMETHODCALLTYPE *get_hPal )( 
            __RPC__in IPicture2 * This,
            /* [annotation][out] */ 
            _Out_  HHANDLE *phPal);
        
        DECLSPEC_XFGVIRT(IPicture2, get_Type)
        HRESULT ( STDMETHODCALLTYPE *get_Type )( 
            __RPC__in IPicture2 * This,
            /* [annotation][out] */ 
            _Out_  SHORT *pType);
        
        DECLSPEC_XFGVIRT(IPicture2, get_Width)
        HRESULT ( STDMETHODCALLTYPE *get_Width )( 
            __RPC__in IPicture2 * This,
            /* [annotation][out] */ 
            _Out_  OLE_XSIZE_HIMETRIC *pWidth);
        
        DECLSPEC_XFGVIRT(IPicture2, get_Height)
        HRESULT ( STDMETHODCALLTYPE *get_Height )( 
            __RPC__in IPicture2 * This,
            /* [annotation][out] */ 
            _Out_  OLE_YSIZE_HIMETRIC *pHeight);
        
        DECLSPEC_XFGVIRT(IPicture2, Render)
        HRESULT ( STDMETHODCALLTYPE *Render )( 
            __RPC__in IPicture2 * This,
            /* [annotation][in] */ 
            _In_  HDC hDC,
            /* [annotation][in] */ 
            _In_  LONG x,
            /* [annotation][in] */ 
            _In_  LONG y,
            /* [annotation][in] */ 
            _In_  LONG cx,
            /* [annotation][in] */ 
            _In_  LONG cy,
            /* [annotation][in] */ 
            _In_  OLE_XPOS_HIMETRIC xSrc,
            /* [annotation][in] */ 
            _In_  OLE_YPOS_HIMETRIC ySrc,
            /* [annotation][in] */ 
            _In_  OLE_XSIZE_HIMETRIC cxSrc,
            /* [annotation][in] */ 
            _In_  OLE_YSIZE_HIMETRIC cySrc,
            /* [annotation][in] */ 
            _In_  LPCRECT pRcWBounds);
        
        DECLSPEC_XFGVIRT(IPicture2, set_hPal)
        HRESULT ( STDMETHODCALLTYPE *set_hPal )( 
            __RPC__in IPicture2 * This,
            /* [annotation][in] */ 
            _In_  HHANDLE hPal);
        
        DECLSPEC_XFGVIRT(IPicture2, get_CurDC)
        HRESULT ( STDMETHODCALLTYPE *get_CurDC )( 
            __RPC__in IPicture2 * This,
            /* [annotation][out] */ 
            _Out_  HDC *phDC);
        
        DECLSPEC_XFGVIRT(IPicture2, SelectPicture)
        HRESULT ( STDMETHODCALLTYPE *SelectPicture )( 
            __RPC__in IPicture2 * This,
            /* [annotation][in] */ 
            _In_  HDC hDCIn,
            /* [annotation][out] */ 
            _Out_  HDC *phDCOut,
            /* [annotation][out] */ 
            _Out_  HHANDLE *phBmpOut);
        
        DECLSPEC_XFGVIRT(IPicture2, get_KeepOriginalFormat)
        HRESULT ( STDMETHODCALLTYPE *get_KeepOriginalFormat )( 
            __RPC__in IPicture2 * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pKeep);
        
        DECLSPEC_XFGVIRT(IPicture2, put_KeepOriginalFormat)
        HRESULT ( STDMETHODCALLTYPE *put_KeepOriginalFormat )( 
            __RPC__in IPicture2 * This,
            /* [annotation][in] */ 
            _In_  BOOL keep);
        
        DECLSPEC_XFGVIRT(IPicture2, PictureChanged)
        HRESULT ( STDMETHODCALLTYPE *PictureChanged )( 
            __RPC__in IPicture2 * This);
        
        DECLSPEC_XFGVIRT(IPicture2, SaveAsFile)
        HRESULT ( STDMETHODCALLTYPE *SaveAsFile )( 
            __RPC__in IPicture2 * This,
            /* [annotation][in] */ 
            _In_  LPSTREAM pStream,
            /* [annotation][in] */ 
            _In_  BOOL fSaveMemCopy,
            /* [annotation][out] */ 
            _Out_  LONG *pCbSize);
        
        DECLSPEC_XFGVIRT(IPicture2, get_Attributes)
        HRESULT ( STDMETHODCALLTYPE *get_Attributes )( 
            __RPC__in IPicture2 * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pDwAttr);
        
        END_INTERFACE
    } IPicture2Vtbl;

    interface IPicture2
    {
        CONST_VTBL struct IPicture2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPicture2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPicture2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPicture2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPicture2_get_Handle(This,pHandle)	\
    ( (This)->lpVtbl -> get_Handle(This,pHandle) ) 

#define IPicture2_get_hPal(This,phPal)	\
    ( (This)->lpVtbl -> get_hPal(This,phPal) ) 

#define IPicture2_get_Type(This,pType)	\
    ( (This)->lpVtbl -> get_Type(This,pType) ) 

#define IPicture2_get_Width(This,pWidth)	\
    ( (This)->lpVtbl -> get_Width(This,pWidth) ) 

#define IPicture2_get_Height(This,pHeight)	\
    ( (This)->lpVtbl -> get_Height(This,pHeight) ) 

#define IPicture2_Render(This,hDC,x,y,cx,cy,xSrc,ySrc,cxSrc,cySrc,pRcWBounds)	\
    ( (This)->lpVtbl -> Render(This,hDC,x,y,cx,cy,xSrc,ySrc,cxSrc,cySrc,pRcWBounds) ) 

#define IPicture2_set_hPal(This,hPal)	\
    ( (This)->lpVtbl -> set_hPal(This,hPal) ) 

#define IPicture2_get_CurDC(This,phDC)	\
    ( (This)->lpVtbl -> get_CurDC(This,phDC) ) 

#define IPicture2_SelectPicture(This,hDCIn,phDCOut,phBmpOut)	\
    ( (This)->lpVtbl -> SelectPicture(This,hDCIn,phDCOut,phBmpOut) ) 

#define IPicture2_get_KeepOriginalFormat(This,pKeep)	\
    ( (This)->lpVtbl -> get_KeepOriginalFormat(This,pKeep) ) 

#define IPicture2_put_KeepOriginalFormat(This,keep)	\
    ( (This)->lpVtbl -> put_KeepOriginalFormat(This,keep) ) 

#define IPicture2_PictureChanged(This)	\
    ( (This)->lpVtbl -> PictureChanged(This) ) 

#define IPicture2_SaveAsFile(This,pStream,fSaveMemCopy,pCbSize)	\
    ( (This)->lpVtbl -> SaveAsFile(This,pStream,fSaveMemCopy,pCbSize) ) 

#define IPicture2_get_Attributes(This,pDwAttr)	\
    ( (This)->lpVtbl -> get_Attributes(This,pDwAttr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPicture2_INTERFACE_DEFINED__ */


#ifndef __IFontEventsDisp_INTERFACE_DEFINED__
#define __IFontEventsDisp_INTERFACE_DEFINED__

/* interface IFontEventsDisp */
/* [unique][uuid][object] */ 

typedef IFontEventsDisp *LPFONTEVENTS;


EXTERN_C const IID IID_IFontEventsDisp;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4EF6100A-AF88-11D0-9846-00C04FC29993")
    IFontEventsDisp : public IDispatch
    {
    public:
    };
    
    
#else 	/* C style interface */

    typedef struct IFontEventsDispVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IFontEventsDisp * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IFontEventsDisp * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IFontEventsDisp * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IFontEventsDisp * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IFontEventsDisp * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IFontEventsDisp * This,
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
            IFontEventsDisp * This,
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
        
        END_INTERFACE
    } IFontEventsDispVtbl;

    interface IFontEventsDisp
    {
        CONST_VTBL struct IFontEventsDispVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFontEventsDisp_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFontEventsDisp_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFontEventsDisp_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFontEventsDisp_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFontEventsDisp_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFontEventsDisp_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFontEventsDisp_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFontEventsDisp_INTERFACE_DEFINED__ */


#ifndef __IFontDisp_INTERFACE_DEFINED__
#define __IFontDisp_INTERFACE_DEFINED__

/* interface IFontDisp */
/* [unique][uuid][object] */ 

typedef IFontDisp *LPFONTDISP;


EXTERN_C const IID IID_IFontDisp;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BEF6E003-A874-101A-8BBA-00AA00300CAB")
    IFontDisp : public IDispatch
    {
    public:
    };
    
    
#else 	/* C style interface */

    typedef struct IFontDispVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IFontDisp * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IFontDisp * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IFontDisp * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IFontDisp * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IFontDisp * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IFontDisp * This,
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
            IFontDisp * This,
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
        
        END_INTERFACE
    } IFontDispVtbl;

    interface IFontDisp
    {
        CONST_VTBL struct IFontDispVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFontDisp_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFontDisp_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFontDisp_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFontDisp_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFontDisp_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFontDisp_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFontDisp_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFontDisp_INTERFACE_DEFINED__ */


#ifndef __IPictureDisp_INTERFACE_DEFINED__
#define __IPictureDisp_INTERFACE_DEFINED__

/* interface IPictureDisp */
/* [unique][uuid][object] */ 

typedef IPictureDisp *LPPICTUREDISP;


EXTERN_C const IID IID_IPictureDisp;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7BF80981-BF32-101A-8BBB-00AA00300CAB")
    IPictureDisp : public IDispatch
    {
    public:
    };
    
    
#else 	/* C style interface */

    typedef struct IPictureDispVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IPictureDisp * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IPictureDisp * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IPictureDisp * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IPictureDisp * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IPictureDisp * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IPictureDisp * This,
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
            IPictureDisp * This,
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
        
        END_INTERFACE
    } IPictureDispVtbl;

    interface IPictureDisp
    {
        CONST_VTBL struct IPictureDispVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPictureDisp_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPictureDisp_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPictureDisp_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPictureDisp_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IPictureDisp_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IPictureDisp_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IPictureDisp_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPictureDisp_INTERFACE_DEFINED__ */


#ifndef __IOleInPlaceObjectWindowless_INTERFACE_DEFINED__
#define __IOleInPlaceObjectWindowless_INTERFACE_DEFINED__

/* interface IOleInPlaceObjectWindowless */
/* [uuid][unique][object] */ 

typedef IOleInPlaceObjectWindowless *LPOLEINPLACEOBJECTWINDOWLESS;


EXTERN_C const IID IID_IOleInPlaceObjectWindowless;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1C2056CC-5EF4-101B-8BC8-00AA003E3B29")
    IOleInPlaceObjectWindowless : public IOleInPlaceObject
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnWindowMessage( 
            /* [annotation][in] */ 
            _In_  UINT msg,
            /* [annotation][in] */ 
            _In_  WPARAM wParam,
            /* [annotation][in] */ 
            _In_  LPARAM lParam,
            /* [annotation][out] */ 
            _Out_  LRESULT *plResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDropTarget( 
            /* [annotation][out] */ 
            _Out_  IDropTarget **ppDropTarget) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IOleInPlaceObjectWindowlessVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IOleInPlaceObjectWindowless * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IOleInPlaceObjectWindowless * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IOleInPlaceObjectWindowless * This);
        
        DECLSPEC_XFGVIRT(IOleWindow, GetWindow)
        /* [input_sync] */ HRESULT ( STDMETHODCALLTYPE *GetWindow )( 
            __RPC__in IOleInPlaceObjectWindowless * This,
            /* [annotation][out] */ 
            _Out_  HWND *phwnd);
        
        DECLSPEC_XFGVIRT(IOleWindow, ContextSensitiveHelp)
        HRESULT ( STDMETHODCALLTYPE *ContextSensitiveHelp )( 
            __RPC__in IOleInPlaceObjectWindowless * This,
            /* [annotation][in] */ 
            _In_  BOOL fEnterMode);
        
        DECLSPEC_XFGVIRT(IOleInPlaceObject, InPlaceDeactivate)
        HRESULT ( STDMETHODCALLTYPE *InPlaceDeactivate )( 
            __RPC__in IOleInPlaceObjectWindowless * This);
        
        DECLSPEC_XFGVIRT(IOleInPlaceObject, UIDeactivate)
        HRESULT ( STDMETHODCALLTYPE *UIDeactivate )( 
            __RPC__in IOleInPlaceObjectWindowless * This);
        
        DECLSPEC_XFGVIRT(IOleInPlaceObject, SetObjectRects)
        /* [input_sync] */ HRESULT ( STDMETHODCALLTYPE *SetObjectRects )( 
            __RPC__in IOleInPlaceObjectWindowless * This,
            /* [annotation][in] */ 
            _In_  LPCRECT lprcPosRect,
            /* [annotation][in] */ 
            _In_  LPCRECT lprcClipRect);
        
        DECLSPEC_XFGVIRT(IOleInPlaceObject, ReactivateAndUndo)
        HRESULT ( STDMETHODCALLTYPE *ReactivateAndUndo )( 
            __RPC__in IOleInPlaceObjectWindowless * This);
        
        DECLSPEC_XFGVIRT(IOleInPlaceObjectWindowless, OnWindowMessage)
        HRESULT ( STDMETHODCALLTYPE *OnWindowMessage )( 
            __RPC__in IOleInPlaceObjectWindowless * This,
            /* [annotation][in] */ 
            _In_  UINT msg,
            /* [annotation][in] */ 
            _In_  WPARAM wParam,
            /* [annotation][in] */ 
            _In_  LPARAM lParam,
            /* [annotation][out] */ 
            _Out_  LRESULT *plResult);
        
        DECLSPEC_XFGVIRT(IOleInPlaceObjectWindowless, GetDropTarget)
        HRESULT ( STDMETHODCALLTYPE *GetDropTarget )( 
            __RPC__in IOleInPlaceObjectWindowless * This,
            /* [annotation][out] */ 
            _Out_  IDropTarget **ppDropTarget);
        
        END_INTERFACE
    } IOleInPlaceObjectWindowlessVtbl;

    interface IOleInPlaceObjectWindowless
    {
        CONST_VTBL struct IOleInPlaceObjectWindowlessVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOleInPlaceObjectWindowless_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOleInPlaceObjectWindowless_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOleInPlaceObjectWindowless_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOleInPlaceObjectWindowless_GetWindow(This,phwnd)	\
    ( (This)->lpVtbl -> GetWindow(This,phwnd) ) 

#define IOleInPlaceObjectWindowless_ContextSensitiveHelp(This,fEnterMode)	\
    ( (This)->lpVtbl -> ContextSensitiveHelp(This,fEnterMode) ) 


#define IOleInPlaceObjectWindowless_InPlaceDeactivate(This)	\
    ( (This)->lpVtbl -> InPlaceDeactivate(This) ) 

#define IOleInPlaceObjectWindowless_UIDeactivate(This)	\
    ( (This)->lpVtbl -> UIDeactivate(This) ) 

#define IOleInPlaceObjectWindowless_SetObjectRects(This,lprcPosRect,lprcClipRect)	\
    ( (This)->lpVtbl -> SetObjectRects(This,lprcPosRect,lprcClipRect) ) 

#define IOleInPlaceObjectWindowless_ReactivateAndUndo(This)	\
    ( (This)->lpVtbl -> ReactivateAndUndo(This) ) 


#define IOleInPlaceObjectWindowless_OnWindowMessage(This,msg,wParam,lParam,plResult)	\
    ( (This)->lpVtbl -> OnWindowMessage(This,msg,wParam,lParam,plResult) ) 

#define IOleInPlaceObjectWindowless_GetDropTarget(This,ppDropTarget)	\
    ( (This)->lpVtbl -> GetDropTarget(This,ppDropTarget) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOleInPlaceObjectWindowless_INTERFACE_DEFINED__ */


#ifndef __IOleInPlaceSiteEx_INTERFACE_DEFINED__
#define __IOleInPlaceSiteEx_INTERFACE_DEFINED__

/* interface IOleInPlaceSiteEx */
/* [uuid][unique][object] */ 

typedef IOleInPlaceSiteEx *LPOLEINPLACESITEEX;

typedef /* [v1_enum] */ 
enum tagACTIVATEFLAGS
    {
        ACTIVATE_WINDOWLESS	= 1
    } 	ACTIVATEFLAGS;


EXTERN_C const IID IID_IOleInPlaceSiteEx;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9C2CAD80-3424-11CF-B670-00AA004CD6D8")
    IOleInPlaceSiteEx : public IOleInPlaceSite
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnInPlaceActivateEx( 
            /* [annotation][out] */ 
            _Out_  BOOL *pfNoRedraw,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnInPlaceDeactivateEx( 
            /* [annotation][in] */ 
            _In_  BOOL fNoRedraw) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RequestUIActivate( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IOleInPlaceSiteExVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IOleInPlaceSiteEx * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IOleInPlaceSiteEx * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IOleInPlaceSiteEx * This);
        
        DECLSPEC_XFGVIRT(IOleWindow, GetWindow)
        /* [input_sync] */ HRESULT ( STDMETHODCALLTYPE *GetWindow )( 
            __RPC__in IOleInPlaceSiteEx * This,
            /* [annotation][out] */ 
            _Out_  HWND *phwnd);
        
        DECLSPEC_XFGVIRT(IOleWindow, ContextSensitiveHelp)
        HRESULT ( STDMETHODCALLTYPE *ContextSensitiveHelp )( 
            __RPC__in IOleInPlaceSiteEx * This,
            /* [annotation][in] */ 
            _In_  BOOL fEnterMode);
        
        DECLSPEC_XFGVIRT(IOleInPlaceSite, CanInPlaceActivate)
        HRESULT ( STDMETHODCALLTYPE *CanInPlaceActivate )( 
            __RPC__in IOleInPlaceSiteEx * This);
        
        DECLSPEC_XFGVIRT(IOleInPlaceSite, OnInPlaceActivate)
        HRESULT ( STDMETHODCALLTYPE *OnInPlaceActivate )( 
            __RPC__in IOleInPlaceSiteEx * This);
        
        DECLSPEC_XFGVIRT(IOleInPlaceSite, OnUIActivate)
        HRESULT ( STDMETHODCALLTYPE *OnUIActivate )( 
            __RPC__in IOleInPlaceSiteEx * This);
        
        DECLSPEC_XFGVIRT(IOleInPlaceSite, GetWindowContext)
        HRESULT ( STDMETHODCALLTYPE *GetWindowContext )( 
            __RPC__in IOleInPlaceSiteEx * This,
            /* [annotation][out] */ 
            _Out_  IOleInPlaceFrame **ppFrame,
            /* [annotation][out] */ 
            _Out_  IOleInPlaceUIWindow **ppDoc,
            /* [annotation][out] */ 
            _Out_  LPRECT lprcPosRect,
            /* [annotation][out] */ 
            _Out_  LPRECT lprcClipRect,
            /* [annotation][out][in] */ 
            _Inout_  LPOLEINPLACEFRAMEINFO lpFrameInfo);
        
        DECLSPEC_XFGVIRT(IOleInPlaceSite, Scroll)
        HRESULT ( STDMETHODCALLTYPE *Scroll )( 
            __RPC__in IOleInPlaceSiteEx * This,
            /* [annotation][in] */ 
            _In_  SIZE scrollExtant);
        
        DECLSPEC_XFGVIRT(IOleInPlaceSite, OnUIDeactivate)
        HRESULT ( STDMETHODCALLTYPE *OnUIDeactivate )( 
            __RPC__in IOleInPlaceSiteEx * This,
            /* [annotation][in] */ 
            _In_  BOOL fUndoable);
        
        DECLSPEC_XFGVIRT(IOleInPlaceSite, OnInPlaceDeactivate)
        HRESULT ( STDMETHODCALLTYPE *OnInPlaceDeactivate )( 
            __RPC__in IOleInPlaceSiteEx * This);
        
        DECLSPEC_XFGVIRT(IOleInPlaceSite, DiscardUndoState)
        HRESULT ( STDMETHODCALLTYPE *DiscardUndoState )( 
            __RPC__in IOleInPlaceSiteEx * This);
        
        DECLSPEC_XFGVIRT(IOleInPlaceSite, DeactivateAndUndo)
        HRESULT ( STDMETHODCALLTYPE *DeactivateAndUndo )( 
            __RPC__in IOleInPlaceSiteEx * This);
        
        DECLSPEC_XFGVIRT(IOleInPlaceSite, OnPosRectChange)
        HRESULT ( STDMETHODCALLTYPE *OnPosRectChange )( 
            __RPC__in IOleInPlaceSiteEx * This,
            /* [annotation][in] */ 
            _In_  LPCRECT lprcPosRect);
        
        DECLSPEC_XFGVIRT(IOleInPlaceSiteEx, OnInPlaceActivateEx)
        HRESULT ( STDMETHODCALLTYPE *OnInPlaceActivateEx )( 
            __RPC__in IOleInPlaceSiteEx * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pfNoRedraw,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags);
        
        DECLSPEC_XFGVIRT(IOleInPlaceSiteEx, OnInPlaceDeactivateEx)
        HRESULT ( STDMETHODCALLTYPE *OnInPlaceDeactivateEx )( 
            __RPC__in IOleInPlaceSiteEx * This,
            /* [annotation][in] */ 
            _In_  BOOL fNoRedraw);
        
        DECLSPEC_XFGVIRT(IOleInPlaceSiteEx, RequestUIActivate)
        HRESULT ( STDMETHODCALLTYPE *RequestUIActivate )( 
            __RPC__in IOleInPlaceSiteEx * This);
        
        END_INTERFACE
    } IOleInPlaceSiteExVtbl;

    interface IOleInPlaceSiteEx
    {
        CONST_VTBL struct IOleInPlaceSiteExVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOleInPlaceSiteEx_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOleInPlaceSiteEx_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOleInPlaceSiteEx_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOleInPlaceSiteEx_GetWindow(This,phwnd)	\
    ( (This)->lpVtbl -> GetWindow(This,phwnd) ) 

#define IOleInPlaceSiteEx_ContextSensitiveHelp(This,fEnterMode)	\
    ( (This)->lpVtbl -> ContextSensitiveHelp(This,fEnterMode) ) 


#define IOleInPlaceSiteEx_CanInPlaceActivate(This)	\
    ( (This)->lpVtbl -> CanInPlaceActivate(This) ) 

#define IOleInPlaceSiteEx_OnInPlaceActivate(This)	\
    ( (This)->lpVtbl -> OnInPlaceActivate(This) ) 

#define IOleInPlaceSiteEx_OnUIActivate(This)	\
    ( (This)->lpVtbl -> OnUIActivate(This) ) 

#define IOleInPlaceSiteEx_GetWindowContext(This,ppFrame,ppDoc,lprcPosRect,lprcClipRect,lpFrameInfo)	\
    ( (This)->lpVtbl -> GetWindowContext(This,ppFrame,ppDoc,lprcPosRect,lprcClipRect,lpFrameInfo) ) 

#define IOleInPlaceSiteEx_Scroll(This,scrollExtant)	\
    ( (This)->lpVtbl -> Scroll(This,scrollExtant) ) 

#define IOleInPlaceSiteEx_OnUIDeactivate(This,fUndoable)	\
    ( (This)->lpVtbl -> OnUIDeactivate(This,fUndoable) ) 

#define IOleInPlaceSiteEx_OnInPlaceDeactivate(This)	\
    ( (This)->lpVtbl -> OnInPlaceDeactivate(This) ) 

#define IOleInPlaceSiteEx_DiscardUndoState(This)	\
    ( (This)->lpVtbl -> DiscardUndoState(This) ) 

#define IOleInPlaceSiteEx_DeactivateAndUndo(This)	\
    ( (This)->lpVtbl -> DeactivateAndUndo(This) ) 

#define IOleInPlaceSiteEx_OnPosRectChange(This,lprcPosRect)	\
    ( (This)->lpVtbl -> OnPosRectChange(This,lprcPosRect) ) 


#define IOleInPlaceSiteEx_OnInPlaceActivateEx(This,pfNoRedraw,dwFlags)	\
    ( (This)->lpVtbl -> OnInPlaceActivateEx(This,pfNoRedraw,dwFlags) ) 

#define IOleInPlaceSiteEx_OnInPlaceDeactivateEx(This,fNoRedraw)	\
    ( (This)->lpVtbl -> OnInPlaceDeactivateEx(This,fNoRedraw) ) 

#define IOleInPlaceSiteEx_RequestUIActivate(This)	\
    ( (This)->lpVtbl -> RequestUIActivate(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOleInPlaceSiteEx_INTERFACE_DEFINED__ */


#ifndef __IOleInPlaceSiteWindowless_INTERFACE_DEFINED__
#define __IOleInPlaceSiteWindowless_INTERFACE_DEFINED__

/* interface IOleInPlaceSiteWindowless */
/* [uuid][unique][object] */ 

typedef IOleInPlaceSiteWindowless *LPOLEINPLACESITEWINDOWLESS;

typedef /* [v1_enum] */ 
enum tagOLEDCFLAGS
    {
        OLEDC_NODRAW	= 0x1,
        OLEDC_PAINTBKGND	= 0x2,
        OLEDC_OFFSCREEN	= 0x4
    } 	OLEDCFLAGS;




EXTERN_C const IID IID_IOleInPlaceSiteWindowless;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("922EADA0-3424-11CF-B670-00AA004CD6D8")
    IOleInPlaceSiteWindowless : public IOleInPlaceSiteEx
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CanWindowlessActivate( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCapture( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetCapture( 
            /* [annotation][in] */ 
            _In_  BOOL fCapture) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFocus( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetFocus( 
            /* [annotation][in] */ 
            _In_  BOOL fFocus) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDC( 
            /* [annotation][unique][in] */ 
            _In_  LPCRECT pRect,
            /* [annotation][in] */ 
            _In_  DWORD grfFlags,
            /* [annotation][out] */ 
            _Out_  HDC *phDC) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReleaseDC( 
            /* [annotation][in] */ 
            _In_  HDC hDC) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InvalidateRect( 
            /* [annotation][unique][in] */ 
            _In_  LPCRECT pRect,
            /* [annotation][in] */ 
            _In_  BOOL fErase) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InvalidateRgn( 
            /* [annotation][in] */ 
            _In_  HRGN hRGN,
            /* [annotation][in] */ 
            _In_  BOOL fErase) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ScrollRect( 
            /* [annotation][in] */ 
            _In_  INT dx,
            /* [annotation][in] */ 
            _In_  INT dy,
            /* [annotation][in] */ 
            _In_  LPCRECT pRectScroll,
            /* [annotation][in] */ 
            _In_  LPCRECT pRectClip) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AdjustRect( 
            /* [annotation][out][in] */ 
            _Inout_  LPRECT prc) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnDefWindowMessage( 
            /* [annotation][in] */ 
            _In_  UINT msg,
            /* [annotation][in] */ 
            _In_  WPARAM wParam,
            /* [annotation][in] */ 
            _In_  LPARAM lParam,
            /* [annotation][out] */ 
            _Out_  LRESULT *plResult) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IOleInPlaceSiteWindowlessVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IOleInPlaceSiteWindowless * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IOleInPlaceSiteWindowless * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IOleInPlaceSiteWindowless * This);
        
        DECLSPEC_XFGVIRT(IOleWindow, GetWindow)
        /* [input_sync] */ HRESULT ( STDMETHODCALLTYPE *GetWindow )( 
            __RPC__in IOleInPlaceSiteWindowless * This,
            /* [annotation][out] */ 
            _Out_  HWND *phwnd);
        
        DECLSPEC_XFGVIRT(IOleWindow, ContextSensitiveHelp)
        HRESULT ( STDMETHODCALLTYPE *ContextSensitiveHelp )( 
            __RPC__in IOleInPlaceSiteWindowless * This,
            /* [annotation][in] */ 
            _In_  BOOL fEnterMode);
        
        DECLSPEC_XFGVIRT(IOleInPlaceSite, CanInPlaceActivate)
        HRESULT ( STDMETHODCALLTYPE *CanInPlaceActivate )( 
            __RPC__in IOleInPlaceSiteWindowless * This);
        
        DECLSPEC_XFGVIRT(IOleInPlaceSite, OnInPlaceActivate)
        HRESULT ( STDMETHODCALLTYPE *OnInPlaceActivate )( 
            __RPC__in IOleInPlaceSiteWindowless * This);
        
        DECLSPEC_XFGVIRT(IOleInPlaceSite, OnUIActivate)
        HRESULT ( STDMETHODCALLTYPE *OnUIActivate )( 
            __RPC__in IOleInPlaceSiteWindowless * This);
        
        DECLSPEC_XFGVIRT(IOleInPlaceSite, GetWindowContext)
        HRESULT ( STDMETHODCALLTYPE *GetWindowContext )( 
            __RPC__in IOleInPlaceSiteWindowless * This,
            /* [annotation][out] */ 
            _Out_  IOleInPlaceFrame **ppFrame,
            /* [annotation][out] */ 
            _Out_  IOleInPlaceUIWindow **ppDoc,
            /* [annotation][out] */ 
            _Out_  LPRECT lprcPosRect,
            /* [annotation][out] */ 
            _Out_  LPRECT lprcClipRect,
            /* [annotation][out][in] */ 
            _Inout_  LPOLEINPLACEFRAMEINFO lpFrameInfo);
        
        DECLSPEC_XFGVIRT(IOleInPlaceSite, Scroll)
        HRESULT ( STDMETHODCALLTYPE *Scroll )( 
            __RPC__in IOleInPlaceSiteWindowless * This,
            /* [annotation][in] */ 
            _In_  SIZE scrollExtant);
        
        DECLSPEC_XFGVIRT(IOleInPlaceSite, OnUIDeactivate)
        HRESULT ( STDMETHODCALLTYPE *OnUIDeactivate )( 
            __RPC__in IOleInPlaceSiteWindowless * This,
            /* [annotation][in] */ 
            _In_  BOOL fUndoable);
        
        DECLSPEC_XFGVIRT(IOleInPlaceSite, OnInPlaceDeactivate)
        HRESULT ( STDMETHODCALLTYPE *OnInPlaceDeactivate )( 
            __RPC__in IOleInPlaceSiteWindowless * This);
        
        DECLSPEC_XFGVIRT(IOleInPlaceSite, DiscardUndoState)
        HRESULT ( STDMETHODCALLTYPE *DiscardUndoState )( 
            __RPC__in IOleInPlaceSiteWindowless * This);
        
        DECLSPEC_XFGVIRT(IOleInPlaceSite, DeactivateAndUndo)
        HRESULT ( STDMETHODCALLTYPE *DeactivateAndUndo )( 
            __RPC__in IOleInPlaceSiteWindowless * This);
        
        DECLSPEC_XFGVIRT(IOleInPlaceSite, OnPosRectChange)
        HRESULT ( STDMETHODCALLTYPE *OnPosRectChange )( 
            __RPC__in IOleInPlaceSiteWindowless * This,
            /* [annotation][in] */ 
            _In_  LPCRECT lprcPosRect);
        
        DECLSPEC_XFGVIRT(IOleInPlaceSiteEx, OnInPlaceActivateEx)
        HRESULT ( STDMETHODCALLTYPE *OnInPlaceActivateEx )( 
            __RPC__in IOleInPlaceSiteWindowless * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pfNoRedraw,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags);
        
        DECLSPEC_XFGVIRT(IOleInPlaceSiteEx, OnInPlaceDeactivateEx)
        HRESULT ( STDMETHODCALLTYPE *OnInPlaceDeactivateEx )( 
            __RPC__in IOleInPlaceSiteWindowless * This,
            /* [annotation][in] */ 
            _In_  BOOL fNoRedraw);
        
        DECLSPEC_XFGVIRT(IOleInPlaceSiteEx, RequestUIActivate)
        HRESULT ( STDMETHODCALLTYPE *RequestUIActivate )( 
            __RPC__in IOleInPlaceSiteWindowless * This);
        
        DECLSPEC_XFGVIRT(IOleInPlaceSiteWindowless, CanWindowlessActivate)
        HRESULT ( STDMETHODCALLTYPE *CanWindowlessActivate )( 
            __RPC__in IOleInPlaceSiteWindowless * This);
        
        DECLSPEC_XFGVIRT(IOleInPlaceSiteWindowless, GetCapture)
        HRESULT ( STDMETHODCALLTYPE *GetCapture )( 
            __RPC__in IOleInPlaceSiteWindowless * This);
        
        DECLSPEC_XFGVIRT(IOleInPlaceSiteWindowless, SetCapture)
        HRESULT ( STDMETHODCALLTYPE *SetCapture )( 
            __RPC__in IOleInPlaceSiteWindowless * This,
            /* [annotation][in] */ 
            _In_  BOOL fCapture);
        
        DECLSPEC_XFGVIRT(IOleInPlaceSiteWindowless, GetFocus)
        HRESULT ( STDMETHODCALLTYPE *GetFocus )( 
            __RPC__in IOleInPlaceSiteWindowless * This);
        
        DECLSPEC_XFGVIRT(IOleInPlaceSiteWindowless, SetFocus)
        HRESULT ( STDMETHODCALLTYPE *SetFocus )( 
            __RPC__in IOleInPlaceSiteWindowless * This,
            /* [annotation][in] */ 
            _In_  BOOL fFocus);
        
        DECLSPEC_XFGVIRT(IOleInPlaceSiteWindowless, GetDC)
        HRESULT ( STDMETHODCALLTYPE *GetDC )( 
            __RPC__in IOleInPlaceSiteWindowless * This,
            /* [annotation][unique][in] */ 
            _In_  LPCRECT pRect,
            /* [annotation][in] */ 
            _In_  DWORD grfFlags,
            /* [annotation][out] */ 
            _Out_  HDC *phDC);
        
        DECLSPEC_XFGVIRT(IOleInPlaceSiteWindowless, ReleaseDC)
        HRESULT ( STDMETHODCALLTYPE *ReleaseDC )( 
            __RPC__in IOleInPlaceSiteWindowless * This,
            /* [annotation][in] */ 
            _In_  HDC hDC);
        
        DECLSPEC_XFGVIRT(IOleInPlaceSiteWindowless, InvalidateRect)
        HRESULT ( STDMETHODCALLTYPE *InvalidateRect )( 
            __RPC__in IOleInPlaceSiteWindowless * This,
            /* [annotation][unique][in] */ 
            _In_  LPCRECT pRect,
            /* [annotation][in] */ 
            _In_  BOOL fErase);
        
        DECLSPEC_XFGVIRT(IOleInPlaceSiteWindowless, InvalidateRgn)
        HRESULT ( STDMETHODCALLTYPE *InvalidateRgn )( 
            __RPC__in IOleInPlaceSiteWindowless * This,
            /* [annotation][in] */ 
            _In_  HRGN hRGN,
            /* [annotation][in] */ 
            _In_  BOOL fErase);
        
        DECLSPEC_XFGVIRT(IOleInPlaceSiteWindowless, ScrollRect)
        HRESULT ( STDMETHODCALLTYPE *ScrollRect )( 
            __RPC__in IOleInPlaceSiteWindowless * This,
            /* [annotation][in] */ 
            _In_  INT dx,
            /* [annotation][in] */ 
            _In_  INT dy,
            /* [annotation][in] */ 
            _In_  LPCRECT pRectScroll,
            /* [annotation][in] */ 
            _In_  LPCRECT pRectClip);
        
        DECLSPEC_XFGVIRT(IOleInPlaceSiteWindowless, AdjustRect)
        HRESULT ( STDMETHODCALLTYPE *AdjustRect )( 
            __RPC__in IOleInPlaceSiteWindowless * This,
            /* [annotation][out][in] */ 
            _Inout_  LPRECT prc);
        
        DECLSPEC_XFGVIRT(IOleInPlaceSiteWindowless, OnDefWindowMessage)
        HRESULT ( STDMETHODCALLTYPE *OnDefWindowMessage )( 
            __RPC__in IOleInPlaceSiteWindowless * This,
            /* [annotation][in] */ 
            _In_  UINT msg,
            /* [annotation][in] */ 
            _In_  WPARAM wParam,
            /* [annotation][in] */ 
            _In_  LPARAM lParam,
            /* [annotation][out] */ 
            _Out_  LRESULT *plResult);
        
        END_INTERFACE
    } IOleInPlaceSiteWindowlessVtbl;

    interface IOleInPlaceSiteWindowless
    {
        CONST_VTBL struct IOleInPlaceSiteWindowlessVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOleInPlaceSiteWindowless_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOleInPlaceSiteWindowless_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOleInPlaceSiteWindowless_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOleInPlaceSiteWindowless_GetWindow(This,phwnd)	\
    ( (This)->lpVtbl -> GetWindow(This,phwnd) ) 

#define IOleInPlaceSiteWindowless_ContextSensitiveHelp(This,fEnterMode)	\
    ( (This)->lpVtbl -> ContextSensitiveHelp(This,fEnterMode) ) 


#define IOleInPlaceSiteWindowless_CanInPlaceActivate(This)	\
    ( (This)->lpVtbl -> CanInPlaceActivate(This) ) 

#define IOleInPlaceSiteWindowless_OnInPlaceActivate(This)	\
    ( (This)->lpVtbl -> OnInPlaceActivate(This) ) 

#define IOleInPlaceSiteWindowless_OnUIActivate(This)	\
    ( (This)->lpVtbl -> OnUIActivate(This) ) 

#define IOleInPlaceSiteWindowless_GetWindowContext(This,ppFrame,ppDoc,lprcPosRect,lprcClipRect,lpFrameInfo)	\
    ( (This)->lpVtbl -> GetWindowContext(This,ppFrame,ppDoc,lprcPosRect,lprcClipRect,lpFrameInfo) ) 

#define IOleInPlaceSiteWindowless_Scroll(This,scrollExtant)	\
    ( (This)->lpVtbl -> Scroll(This,scrollExtant) ) 

#define IOleInPlaceSiteWindowless_OnUIDeactivate(This,fUndoable)	\
    ( (This)->lpVtbl -> OnUIDeactivate(This,fUndoable) ) 

#define IOleInPlaceSiteWindowless_OnInPlaceDeactivate(This)	\
    ( (This)->lpVtbl -> OnInPlaceDeactivate(This) ) 

#define IOleInPlaceSiteWindowless_DiscardUndoState(This)	\
    ( (This)->lpVtbl -> DiscardUndoState(This) ) 

#define IOleInPlaceSiteWindowless_DeactivateAndUndo(This)	\
    ( (This)->lpVtbl -> DeactivateAndUndo(This) ) 

#define IOleInPlaceSiteWindowless_OnPosRectChange(This,lprcPosRect)	\
    ( (This)->lpVtbl -> OnPosRectChange(This,lprcPosRect) ) 


#define IOleInPlaceSiteWindowless_OnInPlaceActivateEx(This,pfNoRedraw,dwFlags)	\
    ( (This)->lpVtbl -> OnInPlaceActivateEx(This,pfNoRedraw,dwFlags) ) 

#define IOleInPlaceSiteWindowless_OnInPlaceDeactivateEx(This,fNoRedraw)	\
    ( (This)->lpVtbl -> OnInPlaceDeactivateEx(This,fNoRedraw) ) 

#define IOleInPlaceSiteWindowless_RequestUIActivate(This)	\
    ( (This)->lpVtbl -> RequestUIActivate(This) ) 


#define IOleInPlaceSiteWindowless_CanWindowlessActivate(This)	\
    ( (This)->lpVtbl -> CanWindowlessActivate(This) ) 

#define IOleInPlaceSiteWindowless_GetCapture(This)	\
    ( (This)->lpVtbl -> GetCapture(This) ) 

#define IOleInPlaceSiteWindowless_SetCapture(This,fCapture)	\
    ( (This)->lpVtbl -> SetCapture(This,fCapture) ) 

#define IOleInPlaceSiteWindowless_GetFocus(This)	\
    ( (This)->lpVtbl -> GetFocus(This) ) 

#define IOleInPlaceSiteWindowless_SetFocus(This,fFocus)	\
    ( (This)->lpVtbl -> SetFocus(This,fFocus) ) 

#define IOleInPlaceSiteWindowless_GetDC(This,pRect,grfFlags,phDC)	\
    ( (This)->lpVtbl -> GetDC(This,pRect,grfFlags,phDC) ) 

#define IOleInPlaceSiteWindowless_ReleaseDC(This,hDC)	\
    ( (This)->lpVtbl -> ReleaseDC(This,hDC) ) 

#define IOleInPlaceSiteWindowless_InvalidateRect(This,pRect,fErase)	\
    ( (This)->lpVtbl -> InvalidateRect(This,pRect,fErase) ) 

#define IOleInPlaceSiteWindowless_InvalidateRgn(This,hRGN,fErase)	\
    ( (This)->lpVtbl -> InvalidateRgn(This,hRGN,fErase) ) 

#define IOleInPlaceSiteWindowless_ScrollRect(This,dx,dy,pRectScroll,pRectClip)	\
    ( (This)->lpVtbl -> ScrollRect(This,dx,dy,pRectScroll,pRectClip) ) 

#define IOleInPlaceSiteWindowless_AdjustRect(This,prc)	\
    ( (This)->lpVtbl -> AdjustRect(This,prc) ) 

#define IOleInPlaceSiteWindowless_OnDefWindowMessage(This,msg,wParam,lParam,plResult)	\
    ( (This)->lpVtbl -> OnDefWindowMessage(This,msg,wParam,lParam,plResult) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOleInPlaceSiteWindowless_INTERFACE_DEFINED__ */


#ifndef __IViewObjectEx_INTERFACE_DEFINED__
#define __IViewObjectEx_INTERFACE_DEFINED__

/* interface IViewObjectEx */
/* [uuid][unique][object] */ 

typedef IViewObjectEx *LPVIEWOBJECTEX;

typedef /* [v1_enum] */ 
enum tagVIEWSTATUS
    {
        VIEWSTATUS_OPAQUE	= 1,
        VIEWSTATUS_SOLIDBKGND	= 2,
        VIEWSTATUS_DVASPECTOPAQUE	= 4,
        VIEWSTATUS_DVASPECTTRANSPARENT	= 8,
        VIEWSTATUS_SURFACE	= 16,
        VIEWSTATUS_3DSURFACE	= 32
    } 	VIEWSTATUS;

typedef /* [v1_enum] */ 
enum tagHITRESULT
    {
        HITRESULT_OUTSIDE	= 0,
        HITRESULT_TRANSPARENT	= 1,
        HITRESULT_CLOSE	= 2,
        HITRESULT_HIT	= 3
    } 	HITRESULT;

typedef /* [v1_enum] */ 
enum tagDVASPECT2
    {
        DVASPECT_OPAQUE	= 16,
        DVASPECT_TRANSPARENT	= 32
    } 	DVASPECT2;

typedef struct tagExtentInfo
    {
    ULONG cb;
    DWORD dwExtentMode;
    SIZEL sizelProposed;
    } 	DVEXTENTINFO;

typedef /* [v1_enum] */ 
enum tagExtentMode
    {
        DVEXTENT_CONTENT	= 0,
        DVEXTENT_INTEGRAL	= ( DVEXTENT_CONTENT + 1 ) 
    } 	DVEXTENTMODE;

typedef /* [v1_enum] */ 
enum tagAspectInfoFlag
    {
        DVASPECTINFOFLAG_CANOPTIMIZE	= 1
    } 	DVASPECTINFOFLAG;

typedef struct tagAspectInfo
    {
    ULONG cb;
    DWORD dwFlags;
    } 	DVASPECTINFO;


EXTERN_C const IID IID_IViewObjectEx;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3AF24292-0C96-11CE-A0CF-00AA00600AB8")
    IViewObjectEx : public IViewObject2
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetRect( 
            /* [annotation][in] */ 
            _In_  DWORD dwAspect,
            /* [annotation][out] */ 
            _Out_  LPRECTL pRect) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetViewStatus( 
            /* [annotation][out] */ 
            _Out_  DWORD *pdwStatus) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryHitPoint( 
            /* [annotation][in] */ 
            _In_  DWORD dwAspect,
            /* [annotation][in] */ 
            _In_  LPCRECT pRectBounds,
            /* [annotation][in] */ 
            _In_  POINT ptlLoc,
            /* [annotation][in] */ 
            _In_  LONG lCloseHint,
            /* [annotation][out] */ 
            _Out_  DWORD *pHitResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryHitRect( 
            /* [annotation][in] */ 
            _In_  DWORD dwAspect,
            /* [annotation][in] */ 
            _In_  LPCRECT pRectBounds,
            /* [annotation][in] */ 
            _In_  LPCRECT pRectLoc,
            /* [annotation][in] */ 
            _In_  LONG lCloseHint,
            /* [annotation][out] */ 
            _Out_  DWORD *pHitResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNaturalExtent( 
            /* [annotation][in] */ 
            _In_  DWORD dwAspect,
            /* [annotation][in] */ 
            _In_  LONG lindex,
            /* [annotation][in] */ 
            _In_  DVTARGETDEVICE *ptd,
            /* [annotation][in] */ 
            _In_  HDC hicTargetDev,
            /* [annotation][in] */ 
            _In_  DVEXTENTINFO *pExtentInfo,
            /* [annotation][out] */ 
            _Out_  LPSIZEL pSizel) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IViewObjectExVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IViewObjectEx * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IViewObjectEx * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IViewObjectEx * This);
        
        DECLSPEC_XFGVIRT(IViewObject, Draw)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Draw )( 
            IViewObjectEx * This,
            /* [annotation][in] */ 
            _In_  DWORD dwDrawAspect,
            /* [annotation][in] */ 
            _In_  LONG lindex,
            /* [annotation][unique][in] */ 
            _Null_  void *pvAspect,
            /* [annotation][unique][in] */ 
            _In_opt_  DVTARGETDEVICE *ptd,
            /* [annotation][in] */ 
            _In_opt_  HDC hdcTargetDev,
            /* [annotation][in] */ 
            _In_  HDC hdcDraw,
            /* [annotation][in] */ 
            _In_opt_  LPCRECTL lprcBounds,
            /* [annotation][unique][in] */ 
            _In_opt_  LPCRECTL lprcWBounds,
            /* [annotation][in] */ 
            _In_opt_  BOOL ( STDMETHODCALLTYPE *pfnContinue )( 
                ULONG_PTR dwContinue),
            /* [annotation][in] */ 
            _In_  ULONG_PTR dwContinue);
        
        DECLSPEC_XFGVIRT(IViewObject, GetColorSet)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *GetColorSet )( 
            IViewObjectEx * This,
            /* [annotation][in] */ 
            _In_  DWORD dwDrawAspect,
            /* [annotation][in] */ 
            _In_  LONG lindex,
            /* [annotation][unique][in] */ 
            _Null_  void *pvAspect,
            /* [annotation][unique][in] */ 
            _In_opt_  DVTARGETDEVICE *ptd,
            /* [annotation][in] */ 
            _In_opt_  HDC hicTargetDev,
            /* [annotation][out] */ 
            _Outptr_  LOGPALETTE **ppColorSet);
        
        DECLSPEC_XFGVIRT(IViewObject, Freeze)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Freeze )( 
            IViewObjectEx * This,
            /* [annotation][in] */ 
            _In_  DWORD dwDrawAspect,
            /* [annotation][in] */ 
            _In_  LONG lindex,
            /* [annotation][unique][in] */ 
            _Null_  void *pvAspect,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwFreeze);
        
        DECLSPEC_XFGVIRT(IViewObject, Unfreeze)
        HRESULT ( STDMETHODCALLTYPE *Unfreeze )( 
            __RPC__in IViewObjectEx * This,
            /* [annotation][in] */ 
            _In_  DWORD dwFreeze);
        
        DECLSPEC_XFGVIRT(IViewObject, SetAdvise)
        HRESULT ( STDMETHODCALLTYPE *SetAdvise )( 
            __RPC__in IViewObjectEx * This,
            /* [annotation][in] */ 
            _In_  DWORD aspects,
            /* [annotation][in] */ 
            _In_  DWORD advf,
            /* [annotation][unique][in] */ 
            _In_  IAdviseSink *pAdvSink);
        
        DECLSPEC_XFGVIRT(IViewObject, GetAdvise)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *GetAdvise )( 
            IViewObjectEx * This,
            /* [annotation][unique][out] */ 
            _Out_opt_  DWORD *pAspects,
            /* [annotation][unique][out] */ 
            _Out_opt_  DWORD *pAdvf,
            /* [annotation][out] */ 
            _Outptr_  IAdviseSink **ppAdvSink);
        
        DECLSPEC_XFGVIRT(IViewObject2, GetExtent)
        HRESULT ( STDMETHODCALLTYPE *GetExtent )( 
            __RPC__in IViewObjectEx * This,
            /* [annotation][in] */ 
            _In_  DWORD dwDrawAspect,
            /* [annotation][in] */ 
            _In_  LONG lindex,
            /* [annotation][unique][in] */ 
            _In_  DVTARGETDEVICE *ptd,
            /* [annotation][out] */ 
            _Out_  LPSIZEL lpsizel);
        
        DECLSPEC_XFGVIRT(IViewObjectEx, GetRect)
        HRESULT ( STDMETHODCALLTYPE *GetRect )( 
            __RPC__in IViewObjectEx * This,
            /* [annotation][in] */ 
            _In_  DWORD dwAspect,
            /* [annotation][out] */ 
            _Out_  LPRECTL pRect);
        
        DECLSPEC_XFGVIRT(IViewObjectEx, GetViewStatus)
        HRESULT ( STDMETHODCALLTYPE *GetViewStatus )( 
            __RPC__in IViewObjectEx * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwStatus);
        
        DECLSPEC_XFGVIRT(IViewObjectEx, QueryHitPoint)
        HRESULT ( STDMETHODCALLTYPE *QueryHitPoint )( 
            __RPC__in IViewObjectEx * This,
            /* [annotation][in] */ 
            _In_  DWORD dwAspect,
            /* [annotation][in] */ 
            _In_  LPCRECT pRectBounds,
            /* [annotation][in] */ 
            _In_  POINT ptlLoc,
            /* [annotation][in] */ 
            _In_  LONG lCloseHint,
            /* [annotation][out] */ 
            _Out_  DWORD *pHitResult);
        
        DECLSPEC_XFGVIRT(IViewObjectEx, QueryHitRect)
        HRESULT ( STDMETHODCALLTYPE *QueryHitRect )( 
            __RPC__in IViewObjectEx * This,
            /* [annotation][in] */ 
            _In_  DWORD dwAspect,
            /* [annotation][in] */ 
            _In_  LPCRECT pRectBounds,
            /* [annotation][in] */ 
            _In_  LPCRECT pRectLoc,
            /* [annotation][in] */ 
            _In_  LONG lCloseHint,
            /* [annotation][out] */ 
            _Out_  DWORD *pHitResult);
        
        DECLSPEC_XFGVIRT(IViewObjectEx, GetNaturalExtent)
        HRESULT ( STDMETHODCALLTYPE *GetNaturalExtent )( 
            __RPC__in IViewObjectEx * This,
            /* [annotation][in] */ 
            _In_  DWORD dwAspect,
            /* [annotation][in] */ 
            _In_  LONG lindex,
            /* [annotation][in] */ 
            _In_  DVTARGETDEVICE *ptd,
            /* [annotation][in] */ 
            _In_  HDC hicTargetDev,
            /* [annotation][in] */ 
            _In_  DVEXTENTINFO *pExtentInfo,
            /* [annotation][out] */ 
            _Out_  LPSIZEL pSizel);
        
        END_INTERFACE
    } IViewObjectExVtbl;

    interface IViewObjectEx
    {
        CONST_VTBL struct IViewObjectExVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IViewObjectEx_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IViewObjectEx_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IViewObjectEx_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IViewObjectEx_Draw(This,dwDrawAspect,lindex,pvAspect,ptd,hdcTargetDev,hdcDraw,lprcBounds,lprcWBounds,pfnContinue,dwContinue)	\
    ( (This)->lpVtbl -> Draw(This,dwDrawAspect,lindex,pvAspect,ptd,hdcTargetDev,hdcDraw,lprcBounds,lprcWBounds,pfnContinue,dwContinue) ) 

#define IViewObjectEx_GetColorSet(This,dwDrawAspect,lindex,pvAspect,ptd,hicTargetDev,ppColorSet)	\
    ( (This)->lpVtbl -> GetColorSet(This,dwDrawAspect,lindex,pvAspect,ptd,hicTargetDev,ppColorSet) ) 

#define IViewObjectEx_Freeze(This,dwDrawAspect,lindex,pvAspect,pdwFreeze)	\
    ( (This)->lpVtbl -> Freeze(This,dwDrawAspect,lindex,pvAspect,pdwFreeze) ) 

#define IViewObjectEx_Unfreeze(This,dwFreeze)	\
    ( (This)->lpVtbl -> Unfreeze(This,dwFreeze) ) 

#define IViewObjectEx_SetAdvise(This,aspects,advf,pAdvSink)	\
    ( (This)->lpVtbl -> SetAdvise(This,aspects,advf,pAdvSink) ) 

#define IViewObjectEx_GetAdvise(This,pAspects,pAdvf,ppAdvSink)	\
    ( (This)->lpVtbl -> GetAdvise(This,pAspects,pAdvf,ppAdvSink) ) 


#define IViewObjectEx_GetExtent(This,dwDrawAspect,lindex,ptd,lpsizel)	\
    ( (This)->lpVtbl -> GetExtent(This,dwDrawAspect,lindex,ptd,lpsizel) ) 


#define IViewObjectEx_GetRect(This,dwAspect,pRect)	\
    ( (This)->lpVtbl -> GetRect(This,dwAspect,pRect) ) 

#define IViewObjectEx_GetViewStatus(This,pdwStatus)	\
    ( (This)->lpVtbl -> GetViewStatus(This,pdwStatus) ) 

#define IViewObjectEx_QueryHitPoint(This,dwAspect,pRectBounds,ptlLoc,lCloseHint,pHitResult)	\
    ( (This)->lpVtbl -> QueryHitPoint(This,dwAspect,pRectBounds,ptlLoc,lCloseHint,pHitResult) ) 

#define IViewObjectEx_QueryHitRect(This,dwAspect,pRectBounds,pRectLoc,lCloseHint,pHitResult)	\
    ( (This)->lpVtbl -> QueryHitRect(This,dwAspect,pRectBounds,pRectLoc,lCloseHint,pHitResult) ) 

#define IViewObjectEx_GetNaturalExtent(This,dwAspect,lindex,ptd,hicTargetDev,pExtentInfo,pSizel)	\
    ( (This)->lpVtbl -> GetNaturalExtent(This,dwAspect,lindex,ptd,hicTargetDev,pExtentInfo,pSizel) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IViewObjectEx_INTERFACE_DEFINED__ */


#ifndef __IOleUndoUnit_INTERFACE_DEFINED__
#define __IOleUndoUnit_INTERFACE_DEFINED__

/* interface IOleUndoUnit */
/* [uuid][unique][object] */ 

typedef IOleUndoUnit *LPOLEUNDOUNIT;


EXTERN_C const IID IID_IOleUndoUnit;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("894AD3B0-EF97-11CE-9BC9-00AA00608E01")
    IOleUndoUnit : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Do( 
            /* [annotation][in] */ 
            _In_  IOleUndoManager *pUndoManager) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDescription( 
            /* [annotation][out] */ 
            _Out_  BSTR *pBstr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetUnitType( 
            /* [annotation][out] */ 
            _Out_  CLSID *pClsid,
            /* [annotation][out] */ 
            _Out_  LONG *plID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnNextAdd( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IOleUndoUnitVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IOleUndoUnit * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IOleUndoUnit * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IOleUndoUnit * This);
        
        DECLSPEC_XFGVIRT(IOleUndoUnit, Do)
        HRESULT ( STDMETHODCALLTYPE *Do )( 
            __RPC__in IOleUndoUnit * This,
            /* [annotation][in] */ 
            _In_  IOleUndoManager *pUndoManager);
        
        DECLSPEC_XFGVIRT(IOleUndoUnit, GetDescription)
        HRESULT ( STDMETHODCALLTYPE *GetDescription )( 
            __RPC__in IOleUndoUnit * This,
            /* [annotation][out] */ 
            _Out_  BSTR *pBstr);
        
        DECLSPEC_XFGVIRT(IOleUndoUnit, GetUnitType)
        HRESULT ( STDMETHODCALLTYPE *GetUnitType )( 
            __RPC__in IOleUndoUnit * This,
            /* [annotation][out] */ 
            _Out_  CLSID *pClsid,
            /* [annotation][out] */ 
            _Out_  LONG *plID);
        
        DECLSPEC_XFGVIRT(IOleUndoUnit, OnNextAdd)
        HRESULT ( STDMETHODCALLTYPE *OnNextAdd )( 
            __RPC__in IOleUndoUnit * This);
        
        END_INTERFACE
    } IOleUndoUnitVtbl;

    interface IOleUndoUnit
    {
        CONST_VTBL struct IOleUndoUnitVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOleUndoUnit_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOleUndoUnit_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOleUndoUnit_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOleUndoUnit_Do(This,pUndoManager)	\
    ( (This)->lpVtbl -> Do(This,pUndoManager) ) 

#define IOleUndoUnit_GetDescription(This,pBstr)	\
    ( (This)->lpVtbl -> GetDescription(This,pBstr) ) 

#define IOleUndoUnit_GetUnitType(This,pClsid,plID)	\
    ( (This)->lpVtbl -> GetUnitType(This,pClsid,plID) ) 

#define IOleUndoUnit_OnNextAdd(This)	\
    ( (This)->lpVtbl -> OnNextAdd(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOleUndoUnit_INTERFACE_DEFINED__ */


#ifndef __IOleParentUndoUnit_INTERFACE_DEFINED__
#define __IOleParentUndoUnit_INTERFACE_DEFINED__

/* interface IOleParentUndoUnit */
/* [uuid][unique][object] */ 

typedef IOleParentUndoUnit *LPOLEPARENTUNDOUNIT;


EXTERN_C const IID IID_IOleParentUndoUnit;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A1FAF330-EF97-11CE-9BC9-00AA00608E01")
    IOleParentUndoUnit : public IOleUndoUnit
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Open( 
            /* [annotation][in] */ 
            _In_  IOleParentUndoUnit *pPUU) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Close( 
            /* [annotation][in] */ 
            _In_  IOleParentUndoUnit *pPUU,
            /* [annotation][in] */ 
            _In_  BOOL fCommit) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Add( 
            /* [annotation][in] */ 
            _In_  IOleUndoUnit *pUU) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FindUnit( 
            /* [annotation][in] */ 
            _In_  IOleUndoUnit *pUU) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetParentState( 
            /* [annotation][out] */ 
            _Out_  DWORD *pdwState) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IOleParentUndoUnitVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IOleParentUndoUnit * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IOleParentUndoUnit * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IOleParentUndoUnit * This);
        
        DECLSPEC_XFGVIRT(IOleUndoUnit, Do)
        HRESULT ( STDMETHODCALLTYPE *Do )( 
            __RPC__in IOleParentUndoUnit * This,
            /* [annotation][in] */ 
            _In_  IOleUndoManager *pUndoManager);
        
        DECLSPEC_XFGVIRT(IOleUndoUnit, GetDescription)
        HRESULT ( STDMETHODCALLTYPE *GetDescription )( 
            __RPC__in IOleParentUndoUnit * This,
            /* [annotation][out] */ 
            _Out_  BSTR *pBstr);
        
        DECLSPEC_XFGVIRT(IOleUndoUnit, GetUnitType)
        HRESULT ( STDMETHODCALLTYPE *GetUnitType )( 
            __RPC__in IOleParentUndoUnit * This,
            /* [annotation][out] */ 
            _Out_  CLSID *pClsid,
            /* [annotation][out] */ 
            _Out_  LONG *plID);
        
        DECLSPEC_XFGVIRT(IOleUndoUnit, OnNextAdd)
        HRESULT ( STDMETHODCALLTYPE *OnNextAdd )( 
            __RPC__in IOleParentUndoUnit * This);
        
        DECLSPEC_XFGVIRT(IOleParentUndoUnit, Open)
        HRESULT ( STDMETHODCALLTYPE *Open )( 
            __RPC__in IOleParentUndoUnit * This,
            /* [annotation][in] */ 
            _In_  IOleParentUndoUnit *pPUU);
        
        DECLSPEC_XFGVIRT(IOleParentUndoUnit, Close)
        HRESULT ( STDMETHODCALLTYPE *Close )( 
            __RPC__in IOleParentUndoUnit * This,
            /* [annotation][in] */ 
            _In_  IOleParentUndoUnit *pPUU,
            /* [annotation][in] */ 
            _In_  BOOL fCommit);
        
        DECLSPEC_XFGVIRT(IOleParentUndoUnit, Add)
        HRESULT ( STDMETHODCALLTYPE *Add )( 
            __RPC__in IOleParentUndoUnit * This,
            /* [annotation][in] */ 
            _In_  IOleUndoUnit *pUU);
        
        DECLSPEC_XFGVIRT(IOleParentUndoUnit, FindUnit)
        HRESULT ( STDMETHODCALLTYPE *FindUnit )( 
            __RPC__in IOleParentUndoUnit * This,
            /* [annotation][in] */ 
            _In_  IOleUndoUnit *pUU);
        
        DECLSPEC_XFGVIRT(IOleParentUndoUnit, GetParentState)
        HRESULT ( STDMETHODCALLTYPE *GetParentState )( 
            __RPC__in IOleParentUndoUnit * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwState);
        
        END_INTERFACE
    } IOleParentUndoUnitVtbl;

    interface IOleParentUndoUnit
    {
        CONST_VTBL struct IOleParentUndoUnitVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOleParentUndoUnit_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOleParentUndoUnit_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOleParentUndoUnit_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOleParentUndoUnit_Do(This,pUndoManager)	\
    ( (This)->lpVtbl -> Do(This,pUndoManager) ) 

#define IOleParentUndoUnit_GetDescription(This,pBstr)	\
    ( (This)->lpVtbl -> GetDescription(This,pBstr) ) 

#define IOleParentUndoUnit_GetUnitType(This,pClsid,plID)	\
    ( (This)->lpVtbl -> GetUnitType(This,pClsid,plID) ) 

#define IOleParentUndoUnit_OnNextAdd(This)	\
    ( (This)->lpVtbl -> OnNextAdd(This) ) 


#define IOleParentUndoUnit_Open(This,pPUU)	\
    ( (This)->lpVtbl -> Open(This,pPUU) ) 

#define IOleParentUndoUnit_Close(This,pPUU,fCommit)	\
    ( (This)->lpVtbl -> Close(This,pPUU,fCommit) ) 

#define IOleParentUndoUnit_Add(This,pUU)	\
    ( (This)->lpVtbl -> Add(This,pUU) ) 

#define IOleParentUndoUnit_FindUnit(This,pUU)	\
    ( (This)->lpVtbl -> FindUnit(This,pUU) ) 

#define IOleParentUndoUnit_GetParentState(This,pdwState)	\
    ( (This)->lpVtbl -> GetParentState(This,pdwState) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOleParentUndoUnit_INTERFACE_DEFINED__ */


#ifndef __IEnumOleUndoUnits_INTERFACE_DEFINED__
#define __IEnumOleUndoUnits_INTERFACE_DEFINED__

/* interface IEnumOleUndoUnits */
/* [uuid][unique][object] */ 

typedef IEnumOleUndoUnits *LPENUMOLEUNDOUNITS;


EXTERN_C const IID IID_IEnumOleUndoUnits;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B3E7C340-EF97-11CE-9BC9-00AA00608E01")
    IEnumOleUndoUnits : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE Next( 
            /* [annotation][in] */ 
            _In_  ULONG cElt,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(cElt,*pcEltFetched)  IOleUndoUnit **rgElt,
            /* [annotation][out] */ 
            _Out_  ULONG *pcEltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [annotation][in] */ 
            _In_  ULONG cElt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [annotation][out] */ 
            _Out_  IEnumOleUndoUnits **ppEnum) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IEnumOleUndoUnitsVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IEnumOleUndoUnits * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IEnumOleUndoUnits * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IEnumOleUndoUnits * This);
        
        DECLSPEC_XFGVIRT(IEnumOleUndoUnits, Next)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Next )( 
            IEnumOleUndoUnits * This,
            /* [annotation][in] */ 
            _In_  ULONG cElt,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(cElt,*pcEltFetched)  IOleUndoUnit **rgElt,
            /* [annotation][out] */ 
            _Out_  ULONG *pcEltFetched);
        
        DECLSPEC_XFGVIRT(IEnumOleUndoUnits, Skip)
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            __RPC__in IEnumOleUndoUnits * This,
            /* [annotation][in] */ 
            _In_  ULONG cElt);
        
        DECLSPEC_XFGVIRT(IEnumOleUndoUnits, Reset)
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            __RPC__in IEnumOleUndoUnits * This);
        
        DECLSPEC_XFGVIRT(IEnumOleUndoUnits, Clone)
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            __RPC__in IEnumOleUndoUnits * This,
            /* [annotation][out] */ 
            _Out_  IEnumOleUndoUnits **ppEnum);
        
        END_INTERFACE
    } IEnumOleUndoUnitsVtbl;

    interface IEnumOleUndoUnits
    {
        CONST_VTBL struct IEnumOleUndoUnitsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumOleUndoUnits_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEnumOleUndoUnits_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEnumOleUndoUnits_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IEnumOleUndoUnits_Next(This,cElt,rgElt,pcEltFetched)	\
    ( (This)->lpVtbl -> Next(This,cElt,rgElt,pcEltFetched) ) 

#define IEnumOleUndoUnits_Skip(This,cElt)	\
    ( (This)->lpVtbl -> Skip(This,cElt) ) 

#define IEnumOleUndoUnits_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define IEnumOleUndoUnits_Clone(This,ppEnum)	\
    ( (This)->lpVtbl -> Clone(This,ppEnum) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT STDMETHODCALLTYPE IEnumOleUndoUnits_RemoteNext_Proxy( 
    __RPC__in IEnumOleUndoUnits * This,
    /* [annotation][in] */ 
    _In_  ULONG cElt,
    /* [annotation][length_is][size_is][out] */ 
    _Out_writes_to_(cElt,*pcEltFetched)  IOleUndoUnit **rgElt,
    /* [annotation][out] */ 
    _Out_  ULONG *pcEltFetched);


void __RPC_STUB IEnumOleUndoUnits_RemoteNext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEnumOleUndoUnits_INTERFACE_DEFINED__ */


#ifndef __IOleUndoManager_INTERFACE_DEFINED__
#define __IOleUndoManager_INTERFACE_DEFINED__

/* interface IOleUndoManager */
/* [uuid][unique][object] */ 

#define SID_SOleUndoManager IID_IOleUndoManager
typedef IOleUndoManager *LPOLEUNDOMANAGER;


EXTERN_C const IID IID_IOleUndoManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D001F200-EF97-11CE-9BC9-00AA00608E01")
    IOleUndoManager : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Open( 
            /* [annotation][in] */ 
            _In_  IOleParentUndoUnit *pPUU) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Close( 
            /* [annotation][in] */ 
            _In_  IOleParentUndoUnit *pPUU,
            /* [annotation][in] */ 
            _In_  BOOL fCommit) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Add( 
            /* [annotation][in] */ 
            _In_  IOleUndoUnit *pUU) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetOpenParentState( 
            /* [annotation][out] */ 
            _Out_  DWORD *pdwState) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DiscardFrom( 
            /* [annotation][in] */ 
            _In_  IOleUndoUnit *pUU) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UndoTo( 
            /* [annotation][in] */ 
            _In_  IOleUndoUnit *pUU) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RedoTo( 
            /* [annotation][in] */ 
            _In_  IOleUndoUnit *pUU) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumUndoable( 
            /* [annotation][out] */ 
            _Out_  IEnumOleUndoUnits **ppEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumRedoable( 
            /* [annotation][out] */ 
            _Out_  IEnumOleUndoUnits **ppEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLastUndoDescription( 
            /* [annotation][out] */ 
            _Out_  BSTR *pBstr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLastRedoDescription( 
            /* [annotation][out] */ 
            _Out_  BSTR *pBstr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Enable( 
            /* [annotation][in] */ 
            _In_  BOOL fEnable) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IOleUndoManagerVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IOleUndoManager * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IOleUndoManager * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IOleUndoManager * This);
        
        DECLSPEC_XFGVIRT(IOleUndoManager, Open)
        HRESULT ( STDMETHODCALLTYPE *Open )( 
            __RPC__in IOleUndoManager * This,
            /* [annotation][in] */ 
            _In_  IOleParentUndoUnit *pPUU);
        
        DECLSPEC_XFGVIRT(IOleUndoManager, Close)
        HRESULT ( STDMETHODCALLTYPE *Close )( 
            __RPC__in IOleUndoManager * This,
            /* [annotation][in] */ 
            _In_  IOleParentUndoUnit *pPUU,
            /* [annotation][in] */ 
            _In_  BOOL fCommit);
        
        DECLSPEC_XFGVIRT(IOleUndoManager, Add)
        HRESULT ( STDMETHODCALLTYPE *Add )( 
            __RPC__in IOleUndoManager * This,
            /* [annotation][in] */ 
            _In_  IOleUndoUnit *pUU);
        
        DECLSPEC_XFGVIRT(IOleUndoManager, GetOpenParentState)
        HRESULT ( STDMETHODCALLTYPE *GetOpenParentState )( 
            __RPC__in IOleUndoManager * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwState);
        
        DECLSPEC_XFGVIRT(IOleUndoManager, DiscardFrom)
        HRESULT ( STDMETHODCALLTYPE *DiscardFrom )( 
            __RPC__in IOleUndoManager * This,
            /* [annotation][in] */ 
            _In_  IOleUndoUnit *pUU);
        
        DECLSPEC_XFGVIRT(IOleUndoManager, UndoTo)
        HRESULT ( STDMETHODCALLTYPE *UndoTo )( 
            __RPC__in IOleUndoManager * This,
            /* [annotation][in] */ 
            _In_  IOleUndoUnit *pUU);
        
        DECLSPEC_XFGVIRT(IOleUndoManager, RedoTo)
        HRESULT ( STDMETHODCALLTYPE *RedoTo )( 
            __RPC__in IOleUndoManager * This,
            /* [annotation][in] */ 
            _In_  IOleUndoUnit *pUU);
        
        DECLSPEC_XFGVIRT(IOleUndoManager, EnumUndoable)
        HRESULT ( STDMETHODCALLTYPE *EnumUndoable )( 
            __RPC__in IOleUndoManager * This,
            /* [annotation][out] */ 
            _Out_  IEnumOleUndoUnits **ppEnum);
        
        DECLSPEC_XFGVIRT(IOleUndoManager, EnumRedoable)
        HRESULT ( STDMETHODCALLTYPE *EnumRedoable )( 
            __RPC__in IOleUndoManager * This,
            /* [annotation][out] */ 
            _Out_  IEnumOleUndoUnits **ppEnum);
        
        DECLSPEC_XFGVIRT(IOleUndoManager, GetLastUndoDescription)
        HRESULT ( STDMETHODCALLTYPE *GetLastUndoDescription )( 
            __RPC__in IOleUndoManager * This,
            /* [annotation][out] */ 
            _Out_  BSTR *pBstr);
        
        DECLSPEC_XFGVIRT(IOleUndoManager, GetLastRedoDescription)
        HRESULT ( STDMETHODCALLTYPE *GetLastRedoDescription )( 
            __RPC__in IOleUndoManager * This,
            /* [annotation][out] */ 
            _Out_  BSTR *pBstr);
        
        DECLSPEC_XFGVIRT(IOleUndoManager, Enable)
        HRESULT ( STDMETHODCALLTYPE *Enable )( 
            __RPC__in IOleUndoManager * This,
            /* [annotation][in] */ 
            _In_  BOOL fEnable);
        
        END_INTERFACE
    } IOleUndoManagerVtbl;

    interface IOleUndoManager
    {
        CONST_VTBL struct IOleUndoManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOleUndoManager_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOleUndoManager_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOleUndoManager_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOleUndoManager_Open(This,pPUU)	\
    ( (This)->lpVtbl -> Open(This,pPUU) ) 

#define IOleUndoManager_Close(This,pPUU,fCommit)	\
    ( (This)->lpVtbl -> Close(This,pPUU,fCommit) ) 

#define IOleUndoManager_Add(This,pUU)	\
    ( (This)->lpVtbl -> Add(This,pUU) ) 

#define IOleUndoManager_GetOpenParentState(This,pdwState)	\
    ( (This)->lpVtbl -> GetOpenParentState(This,pdwState) ) 

#define IOleUndoManager_DiscardFrom(This,pUU)	\
    ( (This)->lpVtbl -> DiscardFrom(This,pUU) ) 

#define IOleUndoManager_UndoTo(This,pUU)	\
    ( (This)->lpVtbl -> UndoTo(This,pUU) ) 

#define IOleUndoManager_RedoTo(This,pUU)	\
    ( (This)->lpVtbl -> RedoTo(This,pUU) ) 

#define IOleUndoManager_EnumUndoable(This,ppEnum)	\
    ( (This)->lpVtbl -> EnumUndoable(This,ppEnum) ) 

#define IOleUndoManager_EnumRedoable(This,ppEnum)	\
    ( (This)->lpVtbl -> EnumRedoable(This,ppEnum) ) 

#define IOleUndoManager_GetLastUndoDescription(This,pBstr)	\
    ( (This)->lpVtbl -> GetLastUndoDescription(This,pBstr) ) 

#define IOleUndoManager_GetLastRedoDescription(This,pBstr)	\
    ( (This)->lpVtbl -> GetLastRedoDescription(This,pBstr) ) 

#define IOleUndoManager_Enable(This,fEnable)	\
    ( (This)->lpVtbl -> Enable(This,fEnable) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOleUndoManager_INTERFACE_DEFINED__ */


#ifndef __IPointerInactive_INTERFACE_DEFINED__
#define __IPointerInactive_INTERFACE_DEFINED__

/* interface IPointerInactive */
/* [uuid][unique][object] */ 

typedef IPointerInactive *LPPOINTERINACTIVE;

typedef /* [v1_enum] */ 
enum tagPOINTERINACTIVE
    {
        POINTERINACTIVE_ACTIVATEONENTRY	= 1,
        POINTERINACTIVE_DEACTIVATEONLEAVE	= 2,
        POINTERINACTIVE_ACTIVATEONDRAG	= 4
    } 	POINTERINACTIVE;


EXTERN_C const IID IID_IPointerInactive;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("55980BA0-35AA-11CF-B671-00AA004CD6D8")
    IPointerInactive : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetActivationPolicy( 
            /* [annotation][out] */ 
            _Out_  DWORD *pdwPolicy) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnInactiveMouseMove( 
            /* [annotation][in] */ 
            _In_  LPCRECT pRectBounds,
            /* [annotation][in] */ 
            _In_  LONG x,
            /* [annotation][in] */ 
            _In_  LONG y,
            /* [annotation][in] */ 
            _In_  DWORD grfKeyState) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnInactiveSetCursor( 
            /* [annotation][in] */ 
            _In_  LPCRECT pRectBounds,
            /* [annotation][in] */ 
            _In_  LONG x,
            /* [annotation][in] */ 
            _In_  LONG y,
            /* [annotation][in] */ 
            _In_  DWORD dwMouseMsg,
            /* [annotation][in] */ 
            _In_  BOOL fSetAlways) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IPointerInactiveVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IPointerInactive * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IPointerInactive * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IPointerInactive * This);
        
        DECLSPEC_XFGVIRT(IPointerInactive, GetActivationPolicy)
        HRESULT ( STDMETHODCALLTYPE *GetActivationPolicy )( 
            __RPC__in IPointerInactive * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwPolicy);
        
        DECLSPEC_XFGVIRT(IPointerInactive, OnInactiveMouseMove)
        HRESULT ( STDMETHODCALLTYPE *OnInactiveMouseMove )( 
            __RPC__in IPointerInactive * This,
            /* [annotation][in] */ 
            _In_  LPCRECT pRectBounds,
            /* [annotation][in] */ 
            _In_  LONG x,
            /* [annotation][in] */ 
            _In_  LONG y,
            /* [annotation][in] */ 
            _In_  DWORD grfKeyState);
        
        DECLSPEC_XFGVIRT(IPointerInactive, OnInactiveSetCursor)
        HRESULT ( STDMETHODCALLTYPE *OnInactiveSetCursor )( 
            __RPC__in IPointerInactive * This,
            /* [annotation][in] */ 
            _In_  LPCRECT pRectBounds,
            /* [annotation][in] */ 
            _In_  LONG x,
            /* [annotation][in] */ 
            _In_  LONG y,
            /* [annotation][in] */ 
            _In_  DWORD dwMouseMsg,
            /* [annotation][in] */ 
            _In_  BOOL fSetAlways);
        
        END_INTERFACE
    } IPointerInactiveVtbl;

    interface IPointerInactive
    {
        CONST_VTBL struct IPointerInactiveVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPointerInactive_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPointerInactive_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPointerInactive_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPointerInactive_GetActivationPolicy(This,pdwPolicy)	\
    ( (This)->lpVtbl -> GetActivationPolicy(This,pdwPolicy) ) 

#define IPointerInactive_OnInactiveMouseMove(This,pRectBounds,x,y,grfKeyState)	\
    ( (This)->lpVtbl -> OnInactiveMouseMove(This,pRectBounds,x,y,grfKeyState) ) 

#define IPointerInactive_OnInactiveSetCursor(This,pRectBounds,x,y,dwMouseMsg,fSetAlways)	\
    ( (This)->lpVtbl -> OnInactiveSetCursor(This,pRectBounds,x,y,dwMouseMsg,fSetAlways) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPointerInactive_INTERFACE_DEFINED__ */


#ifndef __IObjectWithSite_INTERFACE_DEFINED__
#define __IObjectWithSite_INTERFACE_DEFINED__

/* interface IObjectWithSite */
/* [unique][uuid][object] */ 

typedef IObjectWithSite *LPOBJECTWITHSITE;


EXTERN_C const IID IID_IObjectWithSite;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("FC4801A3-2BA9-11CF-A229-00AA003D7352")
    IObjectWithSite : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetSite( 
            /* [annotation][in] */ 
            _In_  IUnknown *pUnkSite) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSite( 
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvSite) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IObjectWithSiteVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IObjectWithSite * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IObjectWithSite * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IObjectWithSite * This);
        
        DECLSPEC_XFGVIRT(IObjectWithSite, SetSite)
        HRESULT ( STDMETHODCALLTYPE *SetSite )( 
            __RPC__in IObjectWithSite * This,
            /* [annotation][in] */ 
            _In_  IUnknown *pUnkSite);
        
        DECLSPEC_XFGVIRT(IObjectWithSite, GetSite)
        HRESULT ( STDMETHODCALLTYPE *GetSite )( 
            __RPC__in IObjectWithSite * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvSite);
        
        END_INTERFACE
    } IObjectWithSiteVtbl;

    interface IObjectWithSite
    {
        CONST_VTBL struct IObjectWithSiteVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IObjectWithSite_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IObjectWithSite_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IObjectWithSite_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IObjectWithSite_SetSite(This,pUnkSite)	\
    ( (This)->lpVtbl -> SetSite(This,pUnkSite) ) 

#define IObjectWithSite_GetSite(This,riid,ppvSite)	\
    ( (This)->lpVtbl -> GetSite(This,riid,ppvSite) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IObjectWithSite_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_ocidl_0000_0036 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) */
#pragma endregion
#pragma region Desktop Family or OneCore Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)


extern RPC_IF_HANDLE __MIDL_itf_ocidl_0000_0036_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ocidl_0000_0036_v0_0_s_ifspec;

#ifndef __IPerPropertyBrowsing_INTERFACE_DEFINED__
#define __IPerPropertyBrowsing_INTERFACE_DEFINED__

/* interface IPerPropertyBrowsing */
/* [unique][uuid][object] */ 

typedef IPerPropertyBrowsing *LPPERPROPERTYBROWSING;

typedef struct tagCALPOLESTR
    {
    ULONG cElems;
    /* [size_is] */ LPOLESTR *pElems;
    } 	CALPOLESTR;

typedef struct tagCALPOLESTR *LPCALPOLESTR;

typedef struct tagCADWORD
    {
    ULONG cElems;
    /* [size_is] */ DWORD *pElems;
    } 	CADWORD;

typedef struct tagCADWORD *LPCADWORD;


EXTERN_C const IID IID_IPerPropertyBrowsing;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("376BD3AA-3845-101B-84ED-08002B2EC713")
    IPerPropertyBrowsing : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetDisplayString( 
            /* [annotation][in] */ 
            _In_  DISPID dispID,
            /* [annotation][out] */ 
            _Out_  BSTR *pBstr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE MapPropertyToPage( 
            /* [annotation][in] */ 
            _In_  DISPID dispID,
            /* [annotation][out] */ 
            _Out_  CLSID *pClsid) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPredefinedStrings( 
            /* [annotation][in] */ 
            _In_  DISPID dispID,
            /* [annotation][out] */ 
            _Out_  CALPOLESTR *pCaStringsOut,
            /* [annotation][out] */ 
            _Out_  CADWORD *pCaCookiesOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPredefinedValue( 
            /* [annotation][in] */ 
            _In_  DISPID dispID,
            /* [annotation][in] */ 
            _In_  DWORD dwCookie,
            /* [annotation][out] */ 
            _Out_  VARIANT *pVarOut) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IPerPropertyBrowsingVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IPerPropertyBrowsing * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IPerPropertyBrowsing * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IPerPropertyBrowsing * This);
        
        DECLSPEC_XFGVIRT(IPerPropertyBrowsing, GetDisplayString)
        HRESULT ( STDMETHODCALLTYPE *GetDisplayString )( 
            __RPC__in IPerPropertyBrowsing * This,
            /* [annotation][in] */ 
            _In_  DISPID dispID,
            /* [annotation][out] */ 
            _Out_  BSTR *pBstr);
        
        DECLSPEC_XFGVIRT(IPerPropertyBrowsing, MapPropertyToPage)
        HRESULT ( STDMETHODCALLTYPE *MapPropertyToPage )( 
            __RPC__in IPerPropertyBrowsing * This,
            /* [annotation][in] */ 
            _In_  DISPID dispID,
            /* [annotation][out] */ 
            _Out_  CLSID *pClsid);
        
        DECLSPEC_XFGVIRT(IPerPropertyBrowsing, GetPredefinedStrings)
        HRESULT ( STDMETHODCALLTYPE *GetPredefinedStrings )( 
            __RPC__in IPerPropertyBrowsing * This,
            /* [annotation][in] */ 
            _In_  DISPID dispID,
            /* [annotation][out] */ 
            _Out_  CALPOLESTR *pCaStringsOut,
            /* [annotation][out] */ 
            _Out_  CADWORD *pCaCookiesOut);
        
        DECLSPEC_XFGVIRT(IPerPropertyBrowsing, GetPredefinedValue)
        HRESULT ( STDMETHODCALLTYPE *GetPredefinedValue )( 
            __RPC__in IPerPropertyBrowsing * This,
            /* [annotation][in] */ 
            _In_  DISPID dispID,
            /* [annotation][in] */ 
            _In_  DWORD dwCookie,
            /* [annotation][out] */ 
            _Out_  VARIANT *pVarOut);
        
        END_INTERFACE
    } IPerPropertyBrowsingVtbl;

    interface IPerPropertyBrowsing
    {
        CONST_VTBL struct IPerPropertyBrowsingVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPerPropertyBrowsing_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPerPropertyBrowsing_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPerPropertyBrowsing_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPerPropertyBrowsing_GetDisplayString(This,dispID,pBstr)	\
    ( (This)->lpVtbl -> GetDisplayString(This,dispID,pBstr) ) 

#define IPerPropertyBrowsing_MapPropertyToPage(This,dispID,pClsid)	\
    ( (This)->lpVtbl -> MapPropertyToPage(This,dispID,pClsid) ) 

#define IPerPropertyBrowsing_GetPredefinedStrings(This,dispID,pCaStringsOut,pCaCookiesOut)	\
    ( (This)->lpVtbl -> GetPredefinedStrings(This,dispID,pCaStringsOut,pCaCookiesOut) ) 

#define IPerPropertyBrowsing_GetPredefinedValue(This,dispID,dwCookie,pVarOut)	\
    ( (This)->lpVtbl -> GetPredefinedValue(This,dispID,dwCookie,pVarOut) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPerPropertyBrowsing_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_ocidl_0000_0037 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) */
#pragma endregion
#pragma region Application Family or OneCore Family or Games Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)


extern RPC_IF_HANDLE __MIDL_itf_ocidl_0000_0037_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ocidl_0000_0037_v0_0_s_ifspec;

#ifndef __IPropertyBag2_INTERFACE_DEFINED__
#define __IPropertyBag2_INTERFACE_DEFINED__

/* interface IPropertyBag2 */
/* [unique][uuid][object] */ 

typedef IPropertyBag2 *LPPROPERTYBAG2;

typedef /* [v1_enum] */ 
enum tagPROPBAG2_TYPE
    {
        PROPBAG2_TYPE_UNDEFINED	= 0,
        PROPBAG2_TYPE_DATA	= 1,
        PROPBAG2_TYPE_URL	= 2,
        PROPBAG2_TYPE_OBJECT	= 3,
        PROPBAG2_TYPE_STREAM	= 4,
        PROPBAG2_TYPE_STORAGE	= 5,
        PROPBAG2_TYPE_MONIKER	= 6
    } 	PROPBAG2_TYPE;

typedef struct tagPROPBAG2
    {
    DWORD dwType;
    VARTYPE vt;
    CLIPFORMAT cfType;
    DWORD dwHint;
    LPOLESTR pstrName;
    CLSID clsid;
    } 	PROPBAG2;


EXTERN_C const IID IID_IPropertyBag2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("22F55882-280B-11d0-A8A9-00A0C90C2004")
    IPropertyBag2 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Read( 
            /* [annotation][in] */ 
            _In_  ULONG cProperties,
            /* [annotation][size_is][in] */ 
            _In_reads_(cProperties)  PROPBAG2 *pPropBag,
            /* [annotation][unique][in] */ 
            _In_  IErrorLog *pErrLog,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cProperties)  VARIANT *pvarValue,
            /* [annotation][size_is][unique][out][in] */ 
            _Inout_updates_(cProperties)  HRESULT *phrError) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Write( 
            /* [annotation][in] */ 
            _In_  ULONG cProperties,
            /* [annotation][size_is][in] */ 
            _In_reads_(cProperties)  PROPBAG2 *pPropBag,
            /* [annotation][size_is][in] */ 
            _In_reads_(cProperties)  VARIANT *pvarValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CountProperties( 
            /* [annotation][out] */ 
            _Out_  ULONG *pcProperties) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPropertyInfo( 
            /* [annotation][in] */ 
            _In_  ULONG iProperty,
            /* [annotation][in] */ 
            _In_  ULONG cProperties,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cProperties)  PROPBAG2 *pPropBag,
            /* [annotation][out] */ 
            _Out_  ULONG *pcProperties) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadObject( 
            /* [annotation][in] */ 
            _In_  LPCOLESTR pstrName,
            /* [annotation][in] */ 
            _In_  DWORD dwHint,
            /* [annotation][in] */ 
            _In_  IUnknown *pUnkObject,
            /* [annotation][unique][in] */ 
            _In_  IErrorLog *pErrLog) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IPropertyBag2Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IPropertyBag2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IPropertyBag2 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IPropertyBag2 * This);
        
        DECLSPEC_XFGVIRT(IPropertyBag2, Read)
        HRESULT ( STDMETHODCALLTYPE *Read )( 
            __RPC__in IPropertyBag2 * This,
            /* [annotation][in] */ 
            _In_  ULONG cProperties,
            /* [annotation][size_is][in] */ 
            _In_reads_(cProperties)  PROPBAG2 *pPropBag,
            /* [annotation][unique][in] */ 
            _In_  IErrorLog *pErrLog,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cProperties)  VARIANT *pvarValue,
            /* [annotation][size_is][unique][out][in] */ 
            _Inout_updates_(cProperties)  HRESULT *phrError);
        
        DECLSPEC_XFGVIRT(IPropertyBag2, Write)
        HRESULT ( STDMETHODCALLTYPE *Write )( 
            __RPC__in IPropertyBag2 * This,
            /* [annotation][in] */ 
            _In_  ULONG cProperties,
            /* [annotation][size_is][in] */ 
            _In_reads_(cProperties)  PROPBAG2 *pPropBag,
            /* [annotation][size_is][in] */ 
            _In_reads_(cProperties)  VARIANT *pvarValue);
        
        DECLSPEC_XFGVIRT(IPropertyBag2, CountProperties)
        HRESULT ( STDMETHODCALLTYPE *CountProperties )( 
            __RPC__in IPropertyBag2 * This,
            /* [annotation][out] */ 
            _Out_  ULONG *pcProperties);
        
        DECLSPEC_XFGVIRT(IPropertyBag2, GetPropertyInfo)
        HRESULT ( STDMETHODCALLTYPE *GetPropertyInfo )( 
            __RPC__in IPropertyBag2 * This,
            /* [annotation][in] */ 
            _In_  ULONG iProperty,
            /* [annotation][in] */ 
            _In_  ULONG cProperties,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cProperties)  PROPBAG2 *pPropBag,
            /* [annotation][out] */ 
            _Out_  ULONG *pcProperties);
        
        DECLSPEC_XFGVIRT(IPropertyBag2, LoadObject)
        HRESULT ( STDMETHODCALLTYPE *LoadObject )( 
            __RPC__in IPropertyBag2 * This,
            /* [annotation][in] */ 
            _In_  LPCOLESTR pstrName,
            /* [annotation][in] */ 
            _In_  DWORD dwHint,
            /* [annotation][in] */ 
            _In_  IUnknown *pUnkObject,
            /* [annotation][unique][in] */ 
            _In_  IErrorLog *pErrLog);
        
        END_INTERFACE
    } IPropertyBag2Vtbl;

    interface IPropertyBag2
    {
        CONST_VTBL struct IPropertyBag2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPropertyBag2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPropertyBag2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPropertyBag2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPropertyBag2_Read(This,cProperties,pPropBag,pErrLog,pvarValue,phrError)	\
    ( (This)->lpVtbl -> Read(This,cProperties,pPropBag,pErrLog,pvarValue,phrError) ) 

#define IPropertyBag2_Write(This,cProperties,pPropBag,pvarValue)	\
    ( (This)->lpVtbl -> Write(This,cProperties,pPropBag,pvarValue) ) 

#define IPropertyBag2_CountProperties(This,pcProperties)	\
    ( (This)->lpVtbl -> CountProperties(This,pcProperties) ) 

#define IPropertyBag2_GetPropertyInfo(This,iProperty,cProperties,pPropBag,pcProperties)	\
    ( (This)->lpVtbl -> GetPropertyInfo(This,iProperty,cProperties,pPropBag,pcProperties) ) 

#define IPropertyBag2_LoadObject(This,pstrName,dwHint,pUnkObject,pErrLog)	\
    ( (This)->lpVtbl -> LoadObject(This,pstrName,dwHint,pUnkObject,pErrLog) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPropertyBag2_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_ocidl_0000_0038 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */
#pragma endregion
#pragma region Desktop Family or OneCore Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)


extern RPC_IF_HANDLE __MIDL_itf_ocidl_0000_0038_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ocidl_0000_0038_v0_0_s_ifspec;

#ifndef __IPersistPropertyBag2_INTERFACE_DEFINED__
#define __IPersistPropertyBag2_INTERFACE_DEFINED__

/* interface IPersistPropertyBag2 */
/* [unique][uuid][object] */ 

typedef IPersistPropertyBag2 *LPPERSISTPROPERTYBAG2;


EXTERN_C const IID IID_IPersistPropertyBag2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("22F55881-280B-11d0-A8A9-00A0C90C2004")
    IPersistPropertyBag2 : public IPersist
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE InitNew( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Load( 
            /* [annotation][in] */ 
            _In_  IPropertyBag2 *pPropBag,
            /* [annotation][unique][in] */ 
            _In_  IErrorLog *pErrLog) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Save( 
            /* [annotation][in] */ 
            _In_  IPropertyBag2 *pPropBag,
            /* [annotation][in] */ 
            _In_  BOOL fClearDirty,
            /* [annotation][in] */ 
            _In_  BOOL fSaveAllProperties) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsDirty( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IPersistPropertyBag2Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IPersistPropertyBag2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IPersistPropertyBag2 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IPersistPropertyBag2 * This);
        
        DECLSPEC_XFGVIRT(IPersist, GetClassID)
        HRESULT ( STDMETHODCALLTYPE *GetClassID )( 
            __RPC__in IPersistPropertyBag2 * This,
            /* [annotation][out] */ 
            _Out_  CLSID *pClassID);
        
        DECLSPEC_XFGVIRT(IPersistPropertyBag2, InitNew)
        HRESULT ( STDMETHODCALLTYPE *InitNew )( 
            __RPC__in IPersistPropertyBag2 * This);
        
        DECLSPEC_XFGVIRT(IPersistPropertyBag2, Load)
        HRESULT ( STDMETHODCALLTYPE *Load )( 
            __RPC__in IPersistPropertyBag2 * This,
            /* [annotation][in] */ 
            _In_  IPropertyBag2 *pPropBag,
            /* [annotation][unique][in] */ 
            _In_  IErrorLog *pErrLog);
        
        DECLSPEC_XFGVIRT(IPersistPropertyBag2, Save)
        HRESULT ( STDMETHODCALLTYPE *Save )( 
            __RPC__in IPersistPropertyBag2 * This,
            /* [annotation][in] */ 
            _In_  IPropertyBag2 *pPropBag,
            /* [annotation][in] */ 
            _In_  BOOL fClearDirty,
            /* [annotation][in] */ 
            _In_  BOOL fSaveAllProperties);
        
        DECLSPEC_XFGVIRT(IPersistPropertyBag2, IsDirty)
        HRESULT ( STDMETHODCALLTYPE *IsDirty )( 
            __RPC__in IPersistPropertyBag2 * This);
        
        END_INTERFACE
    } IPersistPropertyBag2Vtbl;

    interface IPersistPropertyBag2
    {
        CONST_VTBL struct IPersistPropertyBag2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPersistPropertyBag2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPersistPropertyBag2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPersistPropertyBag2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPersistPropertyBag2_GetClassID(This,pClassID)	\
    ( (This)->lpVtbl -> GetClassID(This,pClassID) ) 


#define IPersistPropertyBag2_InitNew(This)	\
    ( (This)->lpVtbl -> InitNew(This) ) 

#define IPersistPropertyBag2_Load(This,pPropBag,pErrLog)	\
    ( (This)->lpVtbl -> Load(This,pPropBag,pErrLog) ) 

#define IPersistPropertyBag2_Save(This,pPropBag,fClearDirty,fSaveAllProperties)	\
    ( (This)->lpVtbl -> Save(This,pPropBag,fClearDirty,fSaveAllProperties) ) 

#define IPersistPropertyBag2_IsDirty(This)	\
    ( (This)->lpVtbl -> IsDirty(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPersistPropertyBag2_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_ocidl_0000_0039 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) */
#pragma endregion
#pragma region Desktop Family or OneCore Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)


extern RPC_IF_HANDLE __MIDL_itf_ocidl_0000_0039_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ocidl_0000_0039_v0_0_s_ifspec;

#ifndef __IAdviseSinkEx_INTERFACE_DEFINED__
#define __IAdviseSinkEx_INTERFACE_DEFINED__

/* interface IAdviseSinkEx */
/* [uuid][unique][object] */ 

typedef IAdviseSinkEx *LPADVISESINKEX;


EXTERN_C const IID IID_IAdviseSinkEx;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3AF24290-0C96-11CE-A0CF-00AA00600AB8")
    IAdviseSinkEx : public IAdviseSink
    {
    public:
        virtual /* [local] */ void STDMETHODCALLTYPE OnViewStatusChange( 
            /* [annotation][in] */ 
            _In_  DWORD dwViewStatus) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAdviseSinkExVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IAdviseSinkEx * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IAdviseSinkEx * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IAdviseSinkEx * This);
        
        DECLSPEC_XFGVIRT(IAdviseSink, OnDataChange)
        /* [local] */ void ( STDMETHODCALLTYPE *OnDataChange )( 
            IAdviseSinkEx * This,
            /* [annotation][unique][in] */ 
            _In_  FORMATETC *pFormatetc,
            /* [annotation][unique][in] */ 
            _In_  STGMEDIUM *pStgmed);
        
        DECLSPEC_XFGVIRT(IAdviseSink, OnViewChange)
        /* [local] */ void ( STDMETHODCALLTYPE *OnViewChange )( 
            IAdviseSinkEx * This,
            /* [annotation][in] */ 
            _In_  DWORD dwAspect,
            /* [annotation][in] */ 
            _In_  LONG lindex);
        
        DECLSPEC_XFGVIRT(IAdviseSink, OnRename)
        /* [local] */ void ( STDMETHODCALLTYPE *OnRename )( 
            IAdviseSinkEx * This,
            /* [annotation][in] */ 
            _In_  IMoniker *pmk);
        
        DECLSPEC_XFGVIRT(IAdviseSink, OnSave)
        /* [local] */ void ( STDMETHODCALLTYPE *OnSave )( 
            IAdviseSinkEx * This);
        
        DECLSPEC_XFGVIRT(IAdviseSink, OnClose)
        /* [local] */ void ( STDMETHODCALLTYPE *OnClose )( 
            IAdviseSinkEx * This);
        
        DECLSPEC_XFGVIRT(IAdviseSinkEx, OnViewStatusChange)
        /* [local] */ void ( STDMETHODCALLTYPE *OnViewStatusChange )( 
            IAdviseSinkEx * This,
            /* [annotation][in] */ 
            _In_  DWORD dwViewStatus);
        
        END_INTERFACE
    } IAdviseSinkExVtbl;

    interface IAdviseSinkEx
    {
        CONST_VTBL struct IAdviseSinkExVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAdviseSinkEx_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAdviseSinkEx_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAdviseSinkEx_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAdviseSinkEx_OnDataChange(This,pFormatetc,pStgmed)	\
    ( (This)->lpVtbl -> OnDataChange(This,pFormatetc,pStgmed) ) 

#define IAdviseSinkEx_OnViewChange(This,dwAspect,lindex)	\
    ( (This)->lpVtbl -> OnViewChange(This,dwAspect,lindex) ) 

#define IAdviseSinkEx_OnRename(This,pmk)	\
    ( (This)->lpVtbl -> OnRename(This,pmk) ) 

#define IAdviseSinkEx_OnSave(This)	\
    ( (This)->lpVtbl -> OnSave(This) ) 

#define IAdviseSinkEx_OnClose(This)	\
    ( (This)->lpVtbl -> OnClose(This) ) 


#define IAdviseSinkEx_OnViewStatusChange(This,dwViewStatus)	\
    ( (This)->lpVtbl -> OnViewStatusChange(This,dwViewStatus) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT STDMETHODCALLTYPE IAdviseSinkEx_RemoteOnViewStatusChange_Proxy( 
    __RPC__in IAdviseSinkEx * This,
    /* [annotation][in] */ 
    _In_  DWORD dwViewStatus);


void __RPC_STUB IAdviseSinkEx_RemoteOnViewStatusChange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAdviseSinkEx_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_ocidl_0000_0040 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) */
#pragma endregion
#pragma region Application Family or OneCore Family or Games Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)


extern RPC_IF_HANDLE __MIDL_itf_ocidl_0000_0040_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ocidl_0000_0040_v0_0_s_ifspec;

#ifndef __IQuickActivate_INTERFACE_DEFINED__
#define __IQuickActivate_INTERFACE_DEFINED__

/* interface IQuickActivate */
/* [uuid][unique][object] */ 

typedef IQuickActivate *LPQUICKACTIVATE;

typedef /* [v1_enum] */ 
enum tagQACONTAINERFLAGS
    {
        QACONTAINER_SHOWHATCHING	= 0x1,
        QACONTAINER_SHOWGRABHANDLES	= 0x2,
        QACONTAINER_USERMODE	= 0x4,
        QACONTAINER_DISPLAYASDEFAULT	= 0x8,
        QACONTAINER_UIDEAD	= 0x10,
        QACONTAINER_AUTOCLIP	= 0x20,
        QACONTAINER_MESSAGEREFLECT	= 0x40,
        QACONTAINER_SUPPORTSMNEMONICS	= 0x80
    } 	QACONTAINERFLAGS;

typedef /* [public][uuid] */  DECLSPEC_UUID("66504301-BE0F-101A-8BBB-00AA00300CAB") DWORD OLE_COLOR;

typedef struct tagQACONTAINER
    {
    ULONG cbSize;
    IOleClientSite *pClientSite;
    IAdviseSinkEx *pAdviseSink;
    IPropertyNotifySink *pPropertyNotifySink;
    IUnknown *pUnkEventSink;
    DWORD dwAmbientFlags;
    OLE_COLOR colorFore;
    OLE_COLOR colorBack;
    IFont *pFont;
    IOleUndoManager *pUndoMgr;
    DWORD dwAppearance;
    LONG lcid;
    HPALETTE hpal;
    IBindHost *pBindHost;
    IOleControlSite *pOleControlSite;
    IServiceProvider *pServiceProvider;
    } 	QACONTAINER;

typedef struct tagQACONTROL
    {
    ULONG cbSize;
    DWORD dwMiscStatus;
    DWORD dwViewStatus;
    DWORD dwEventCookie;
    DWORD dwPropNotifyCookie;
    DWORD dwPointerActivationPolicy;
    } 	QACONTROL;


EXTERN_C const IID IID_IQuickActivate;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CF51ED10-62FE-11CF-BF86-00A0C9034836")
    IQuickActivate : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE QuickActivate( 
            /* [annotation][in] */ 
            _In_  QACONTAINER *pQaContainer,
            /* [annotation][out][in] */ 
            _Inout_  QACONTROL *pQaControl) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetContentExtent( 
            /* [annotation][in] */ 
            _In_  LPSIZEL pSizel) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetContentExtent( 
            /* [annotation][out] */ 
            _Out_  LPSIZEL pSizel) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IQuickActivateVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IQuickActivate * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IQuickActivate * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IQuickActivate * This);
        
        DECLSPEC_XFGVIRT(IQuickActivate, QuickActivate)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *QuickActivate )( 
            IQuickActivate * This,
            /* [annotation][in] */ 
            _In_  QACONTAINER *pQaContainer,
            /* [annotation][out][in] */ 
            _Inout_  QACONTROL *pQaControl);
        
        DECLSPEC_XFGVIRT(IQuickActivate, SetContentExtent)
        HRESULT ( STDMETHODCALLTYPE *SetContentExtent )( 
            __RPC__in IQuickActivate * This,
            /* [annotation][in] */ 
            _In_  LPSIZEL pSizel);
        
        DECLSPEC_XFGVIRT(IQuickActivate, GetContentExtent)
        HRESULT ( STDMETHODCALLTYPE *GetContentExtent )( 
            __RPC__in IQuickActivate * This,
            /* [annotation][out] */ 
            _Out_  LPSIZEL pSizel);
        
        END_INTERFACE
    } IQuickActivateVtbl;

    interface IQuickActivate
    {
        CONST_VTBL struct IQuickActivateVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IQuickActivate_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IQuickActivate_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IQuickActivate_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IQuickActivate_QuickActivate(This,pQaContainer,pQaControl)	\
    ( (This)->lpVtbl -> QuickActivate(This,pQaContainer,pQaControl) ) 

#define IQuickActivate_SetContentExtent(This,pSizel)	\
    ( (This)->lpVtbl -> SetContentExtent(This,pSizel) ) 

#define IQuickActivate_GetContentExtent(This,pSizel)	\
    ( (This)->lpVtbl -> GetContentExtent(This,pSizel) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT STDMETHODCALLTYPE IQuickActivate_RemoteQuickActivate_Proxy( 
    __RPC__in IQuickActivate * This,
    /* [annotation][in] */ 
    _In_  QACONTAINER *pQaContainer,
    /* [annotation][out] */ 
    _Out_  QACONTROL *pQaControl);


void __RPC_STUB IQuickActivate_RemoteQuickActivate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IQuickActivate_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_ocidl_0000_0041 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */
#pragma endregion
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


extern RPC_IF_HANDLE __MIDL_itf_ocidl_0000_0041_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ocidl_0000_0041_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     __RPC__in unsigned long *, unsigned long            , __RPC__in BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     __RPC__in unsigned long *, __RPC__in BSTR * ); 

unsigned long             __RPC_USER  CLIPFORMAT_UserSize(     __RPC__in unsigned long *, unsigned long            , __RPC__in CLIPFORMAT * ); 
unsigned char * __RPC_USER  CLIPFORMAT_UserMarshal(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in CLIPFORMAT * ); 
unsigned char * __RPC_USER  CLIPFORMAT_UserUnmarshal(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out CLIPFORMAT * ); 
void                      __RPC_USER  CLIPFORMAT_UserFree(     __RPC__in unsigned long *, __RPC__in CLIPFORMAT * ); 

unsigned long             __RPC_USER  HACCEL_UserSize(     __RPC__in unsigned long *, unsigned long            , __RPC__in HACCEL * ); 
unsigned char * __RPC_USER  HACCEL_UserMarshal(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in HACCEL * ); 
unsigned char * __RPC_USER  HACCEL_UserUnmarshal(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out HACCEL * ); 
void                      __RPC_USER  HACCEL_UserFree(     __RPC__in unsigned long *, __RPC__in HACCEL * ); 

unsigned long             __RPC_USER  HDC_UserSize(     __RPC__in unsigned long *, unsigned long            , __RPC__in HDC * ); 
unsigned char * __RPC_USER  HDC_UserMarshal(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in HDC * ); 
unsigned char * __RPC_USER  HDC_UserUnmarshal(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out HDC * ); 
void                      __RPC_USER  HDC_UserFree(     __RPC__in unsigned long *, __RPC__in HDC * ); 

unsigned long             __RPC_USER  HFONT_UserSize(     __RPC__in unsigned long *, unsigned long            , __RPC__in HFONT * ); 
unsigned char * __RPC_USER  HFONT_UserMarshal(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in HFONT * ); 
unsigned char * __RPC_USER  HFONT_UserUnmarshal(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out HFONT * ); 
void                      __RPC_USER  HFONT_UserFree(     __RPC__in unsigned long *, __RPC__in HFONT * ); 

unsigned long             __RPC_USER  HPALETTE_UserSize(     __RPC__in unsigned long *, unsigned long            , __RPC__in HPALETTE * ); 
unsigned char * __RPC_USER  HPALETTE_UserMarshal(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in HPALETTE * ); 
unsigned char * __RPC_USER  HPALETTE_UserUnmarshal(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out HPALETTE * ); 
void                      __RPC_USER  HPALETTE_UserFree(     __RPC__in unsigned long *, __RPC__in HPALETTE * ); 

unsigned long             __RPC_USER  HRGN_UserSize(     __RPC__in unsigned long *, unsigned long            , __RPC__in HRGN * ); 
unsigned char * __RPC_USER  HRGN_UserMarshal(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in HRGN * ); 
unsigned char * __RPC_USER  HRGN_UserUnmarshal(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out HRGN * ); 
void                      __RPC_USER  HRGN_UserFree(     __RPC__in unsigned long *, __RPC__in HRGN * ); 

unsigned long             __RPC_USER  HWND_UserSize(     __RPC__in unsigned long *, unsigned long            , __RPC__in HWND * ); 
unsigned char * __RPC_USER  HWND_UserMarshal(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in HWND * ); 
unsigned char * __RPC_USER  HWND_UserUnmarshal(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out HWND * ); 
void                      __RPC_USER  HWND_UserFree(     __RPC__in unsigned long *, __RPC__in HWND * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     __RPC__in unsigned long *, unsigned long            , __RPC__in VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree(     __RPC__in unsigned long *, __RPC__in VARIANT * ); 

unsigned long             __RPC_USER  BSTR_UserSize64(     __RPC__in unsigned long *, unsigned long            , __RPC__in BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal64(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal64(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out BSTR * ); 
void                      __RPC_USER  BSTR_UserFree64(     __RPC__in unsigned long *, __RPC__in BSTR * ); 

unsigned long             __RPC_USER  CLIPFORMAT_UserSize64(     __RPC__in unsigned long *, unsigned long            , __RPC__in CLIPFORMAT * ); 
unsigned char * __RPC_USER  CLIPFORMAT_UserMarshal64(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in CLIPFORMAT * ); 
unsigned char * __RPC_USER  CLIPFORMAT_UserUnmarshal64(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out CLIPFORMAT * ); 
void                      __RPC_USER  CLIPFORMAT_UserFree64(     __RPC__in unsigned long *, __RPC__in CLIPFORMAT * ); 

unsigned long             __RPC_USER  HACCEL_UserSize64(     __RPC__in unsigned long *, unsigned long            , __RPC__in HACCEL * ); 
unsigned char * __RPC_USER  HACCEL_UserMarshal64(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in HACCEL * ); 
unsigned char * __RPC_USER  HACCEL_UserUnmarshal64(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out HACCEL * ); 
void                      __RPC_USER  HACCEL_UserFree64(     __RPC__in unsigned long *, __RPC__in HACCEL * ); 

unsigned long             __RPC_USER  HDC_UserSize64(     __RPC__in unsigned long *, unsigned long            , __RPC__in HDC * ); 
unsigned char * __RPC_USER  HDC_UserMarshal64(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in HDC * ); 
unsigned char * __RPC_USER  HDC_UserUnmarshal64(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out HDC * ); 
void                      __RPC_USER  HDC_UserFree64(     __RPC__in unsigned long *, __RPC__in HDC * ); 

unsigned long             __RPC_USER  HFONT_UserSize64(     __RPC__in unsigned long *, unsigned long            , __RPC__in HFONT * ); 
unsigned char * __RPC_USER  HFONT_UserMarshal64(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in HFONT * ); 
unsigned char * __RPC_USER  HFONT_UserUnmarshal64(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out HFONT * ); 
void                      __RPC_USER  HFONT_UserFree64(     __RPC__in unsigned long *, __RPC__in HFONT * ); 

unsigned long             __RPC_USER  HPALETTE_UserSize64(     __RPC__in unsigned long *, unsigned long            , __RPC__in HPALETTE * ); 
unsigned char * __RPC_USER  HPALETTE_UserMarshal64(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in HPALETTE * ); 
unsigned char * __RPC_USER  HPALETTE_UserUnmarshal64(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out HPALETTE * ); 
void                      __RPC_USER  HPALETTE_UserFree64(     __RPC__in unsigned long *, __RPC__in HPALETTE * ); 

unsigned long             __RPC_USER  HRGN_UserSize64(     __RPC__in unsigned long *, unsigned long            , __RPC__in HRGN * ); 
unsigned char * __RPC_USER  HRGN_UserMarshal64(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in HRGN * ); 
unsigned char * __RPC_USER  HRGN_UserUnmarshal64(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out HRGN * ); 
void                      __RPC_USER  HRGN_UserFree64(     __RPC__in unsigned long *, __RPC__in HRGN * ); 

unsigned long             __RPC_USER  HWND_UserSize64(     __RPC__in unsigned long *, unsigned long            , __RPC__in HWND * ); 
unsigned char * __RPC_USER  HWND_UserMarshal64(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in HWND * ); 
unsigned char * __RPC_USER  HWND_UserUnmarshal64(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out HWND * ); 
void                      __RPC_USER  HWND_UserFree64(     __RPC__in unsigned long *, __RPC__in HWND * ); 

unsigned long             __RPC_USER  VARIANT_UserSize64(     __RPC__in unsigned long *, unsigned long            , __RPC__in VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal64(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal64(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree64(     __RPC__in unsigned long *, __RPC__in VARIANT * ); 

/* [local] */ HRESULT STDMETHODCALLTYPE IEnumConnections_Next_Proxy( 
    IEnumConnections * This,
    /* [annotation][in] */ 
    _In_  ULONG cConnections,
    /* [annotation][length_is][size_is][out] */ 
    _Out_writes_to_(cConnections,*pcFetched)  LPCONNECTDATA rgcd,
    /* [annotation][out] */ 
    _Out_  ULONG *pcFetched);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IEnumConnections_Next_Stub( 
    __RPC__in IEnumConnections * This,
    /* [annotation][in] */ 
    _In_  ULONG cConnections,
    /* [annotation][length_is][size_is][out] */ 
    _Out_writes_to_(cConnections,*pcFetched)  LPCONNECTDATA rgcd,
    /* [annotation][out] */ 
    _Out_  ULONG *pcFetched);

/* [local] */ HRESULT STDMETHODCALLTYPE IEnumConnectionPoints_Next_Proxy( 
    IEnumConnectionPoints * This,
    /* [annotation][in] */ 
    _In_  ULONG cConnections,
    /* [annotation][length_is][size_is][out] */ 
    _Out_writes_to_(cConnections,*pcFetched)  LPCONNECTIONPOINT *ppCP,
    /* [annotation][out] */ 
    _Out_  ULONG *pcFetched);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IEnumConnectionPoints_Next_Stub( 
    __RPC__in IEnumConnectionPoints * This,
    /* [annotation][in] */ 
    _In_  ULONG cConnections,
    /* [annotation][length_is][size_is][out] */ 
    _Out_writes_to_(cConnections,*pcFetched)  LPCONNECTIONPOINT *ppCP,
    /* [annotation][out] */ 
    _Out_  ULONG *pcFetched);

/* [local] */ HRESULT STDMETHODCALLTYPE IClassFactory2_CreateInstanceLic_Proxy( 
    IClassFactory2 * This,
    /* [annotation][in] */ 
    _In_opt_  IUnknown *pUnkOuter,
    /* [annotation][in] */ 
    _Reserved_  IUnknown *pUnkReserved,
    /* [annotation][in] */ 
    __RPC__in  REFIID riid,
    /* [annotation][in] */ 
    __RPC__in  BSTR bstrKey,
    /* [annotation][iid_is][out] */ 
    __RPC__deref_out_opt  PVOID *ppvObj);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IClassFactory2_CreateInstanceLic_Stub( 
    __RPC__in IClassFactory2 * This,
    /* [annotation][in] */ 
    _In_  REFIID riid,
    /* [annotation][in] */ 
    _In_  BSTR bstrKey,
    /* [annotation][iid_is][out] */ 
    _COM_Outptr_  IUnknown **ppvObj);

/* [local] */ HRESULT STDMETHODCALLTYPE IPersistMemory_Load_Proxy( 
    IPersistMemory * This,
    /* [annotation][size_is][in] */ 
    _In_reads_(cbSize)  LPVOID pMem,
    /* [annotation][in] */ 
    _In_  ULONG cbSize);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IPersistMemory_Load_Stub( 
    __RPC__in IPersistMemory * This,
    /* [annotation][size_is][in] */ 
    _In_reads_(cbSize)  BYTE *pMem,
    /* [annotation][in] */ 
    _In_  ULONG cbSize);

/* [local] */ HRESULT STDMETHODCALLTYPE IPersistMemory_Save_Proxy( 
    IPersistMemory * This,
    /* [annotation][size_is][out] */ 
    _Out_writes_(cbSize)  LPVOID pMem,
    /* [annotation][in] */ 
    _In_  BOOL fClearDirty,
    /* [annotation][in] */ 
    _In_  ULONG cbSize);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IPersistMemory_Save_Stub( 
    __RPC__in IPersistMemory * This,
    /* [annotation][size_is][out] */ 
    _Out_writes_(cbSize)  BYTE *pMem,
    /* [annotation][in] */ 
    _In_  BOOL fClearDirty,
    /* [annotation][in] */ 
    _In_  ULONG cbSize);

/* [local] */ HRESULT STDMETHODCALLTYPE IEnumOleUndoUnits_Next_Proxy( 
    IEnumOleUndoUnits * This,
    /* [annotation][in] */ 
    _In_  ULONG cElt,
    /* [annotation][length_is][size_is][out] */ 
    _Out_writes_to_(cElt,*pcEltFetched)  IOleUndoUnit **rgElt,
    /* [annotation][out] */ 
    _Out_  ULONG *pcEltFetched);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IEnumOleUndoUnits_Next_Stub( 
    __RPC__in IEnumOleUndoUnits * This,
    /* [annotation][in] */ 
    _In_  ULONG cElt,
    /* [annotation][length_is][size_is][out] */ 
    _Out_writes_to_(cElt,*pcEltFetched)  IOleUndoUnit **rgElt,
    /* [annotation][out] */ 
    _Out_  ULONG *pcEltFetched);

/* [local] */ void STDMETHODCALLTYPE IAdviseSinkEx_OnViewStatusChange_Proxy( 
    IAdviseSinkEx * This,
    /* [annotation][in] */ 
    _In_  DWORD dwViewStatus);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IAdviseSinkEx_OnViewStatusChange_Stub( 
    __RPC__in IAdviseSinkEx * This,
    /* [annotation][in] */ 
    _In_  DWORD dwViewStatus);

/* [local] */ HRESULT STDMETHODCALLTYPE IQuickActivate_QuickActivate_Proxy( 
    IQuickActivate * This,
    /* [annotation][in] */ 
    _In_  QACONTAINER *pQaContainer,
    /* [annotation][out][in] */ 
    _Inout_  QACONTROL *pQaControl);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IQuickActivate_QuickActivate_Stub( 
    __RPC__in IQuickActivate * This,
    /* [annotation][in] */ 
    _In_  QACONTAINER *pQaContainer,
    /* [annotation][out] */ 
    _Out_  QACONTROL *pQaControl);



/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


