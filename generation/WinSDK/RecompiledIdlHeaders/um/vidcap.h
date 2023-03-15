

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

#ifndef __vidcap_h__
#define __vidcap_h__

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

#ifndef __IKsTopologyInfo_FWD_DEFINED__
#define __IKsTopologyInfo_FWD_DEFINED__
typedef interface IKsTopologyInfo IKsTopologyInfo;

#endif 	/* __IKsTopologyInfo_FWD_DEFINED__ */


#ifndef __ISelector_FWD_DEFINED__
#define __ISelector_FWD_DEFINED__
typedef interface ISelector ISelector;

#endif 	/* __ISelector_FWD_DEFINED__ */


#ifndef __ICameraControl_FWD_DEFINED__
#define __ICameraControl_FWD_DEFINED__
typedef interface ICameraControl ICameraControl;

#endif 	/* __ICameraControl_FWD_DEFINED__ */


#ifndef __IVideoProcAmp_FWD_DEFINED__
#define __IVideoProcAmp_FWD_DEFINED__
typedef interface IVideoProcAmp IVideoProcAmp;

#endif 	/* __IVideoProcAmp_FWD_DEFINED__ */


#ifndef __IKsNodeControl_FWD_DEFINED__
#define __IKsNodeControl_FWD_DEFINED__
typedef interface IKsNodeControl IKsNodeControl;

#endif 	/* __IKsNodeControl_FWD_DEFINED__ */


/* header files for imported files */
#include "unknwn.h"
#include "strmif.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_vidcap_0000_0000 */
/* [local] */ 

#include <winapifamily.h>
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
#include "ks.h"
#ifndef _KS_
typedef /* [public][public] */ struct __MIDL___MIDL_itf_vidcap_0000_0000_0001
    {
    ULONG FromNode;
    ULONG FromNodePin;
    ULONG ToNode;
    ULONG ToNodePin;
    } 	KSTOPOLOGY_CONNECTION;

typedef struct __MIDL___MIDL_itf_vidcap_0000_0000_0001 *PKSTOPOLOGY_CONNECTION;

#endif


extern RPC_IF_HANDLE __MIDL_itf_vidcap_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vidcap_0000_0000_v0_0_s_ifspec;

#ifndef __IKsTopologyInfo_INTERFACE_DEFINED__
#define __IKsTopologyInfo_INTERFACE_DEFINED__

/* interface IKsTopologyInfo */
/* [unique][uuid][local][object] */ 


EXTERN_C const IID IID_IKsTopologyInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("720D4AC0-7533-11D0-A5D6-28DB04C10000")
    IKsTopologyInfo : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE get_NumCategories( 
            /* [annotation][out] */ 
            _Out_  DWORD *pdwNumCategories) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_Category( 
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][out] */ 
            _Out_  GUID *pCategory) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_NumConnections( 
            /* [annotation][out] */ 
            _Out_  DWORD *pdwNumConnections) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_ConnectionInfo( 
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][out] */ 
            _Out_  KSTOPOLOGY_CONNECTION *pConnectionInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_NodeName( 
            /* [in] */ DWORD dwNodeId,
            /* [annotation][out] */ 
            _Out_writes_bytes_opt_(dwBufSize)  WCHAR *pwchNodeName,
            /* [in] */ DWORD dwBufSize,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwNameLen) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_NumNodes( 
            /* [annotation][out] */ 
            _Out_  DWORD *pdwNumNodes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_NodeType( 
            /* [annotation][in] */ 
            _In_  DWORD dwNodeId,
            /* [annotation][out] */ 
            _Out_  GUID *pNodeType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateNodeInstance( 
            /* [annotation][in] */ 
            _In_  DWORD dwNodeId,
            /* [annotation][in] */ 
            _In_  REFIID iid,
            /* [annotation][out] */ 
            _Out_  void **ppvObject) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IKsTopologyInfoVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IKsTopologyInfo * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IKsTopologyInfo * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IKsTopologyInfo * This);
        
        DECLSPEC_XFGVIRT(IKsTopologyInfo, get_NumCategories)
        HRESULT ( STDMETHODCALLTYPE *get_NumCategories )( 
            IKsTopologyInfo * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwNumCategories);
        
        DECLSPEC_XFGVIRT(IKsTopologyInfo, get_Category)
        HRESULT ( STDMETHODCALLTYPE *get_Category )( 
            IKsTopologyInfo * This,
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][out] */ 
            _Out_  GUID *pCategory);
        
        DECLSPEC_XFGVIRT(IKsTopologyInfo, get_NumConnections)
        HRESULT ( STDMETHODCALLTYPE *get_NumConnections )( 
            IKsTopologyInfo * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwNumConnections);
        
        DECLSPEC_XFGVIRT(IKsTopologyInfo, get_ConnectionInfo)
        HRESULT ( STDMETHODCALLTYPE *get_ConnectionInfo )( 
            IKsTopologyInfo * This,
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][out] */ 
            _Out_  KSTOPOLOGY_CONNECTION *pConnectionInfo);
        
        DECLSPEC_XFGVIRT(IKsTopologyInfo, get_NodeName)
        HRESULT ( STDMETHODCALLTYPE *get_NodeName )( 
            IKsTopologyInfo * This,
            /* [in] */ DWORD dwNodeId,
            /* [annotation][out] */ 
            _Out_writes_bytes_opt_(dwBufSize)  WCHAR *pwchNodeName,
            /* [in] */ DWORD dwBufSize,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwNameLen);
        
        DECLSPEC_XFGVIRT(IKsTopologyInfo, get_NumNodes)
        HRESULT ( STDMETHODCALLTYPE *get_NumNodes )( 
            IKsTopologyInfo * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwNumNodes);
        
        DECLSPEC_XFGVIRT(IKsTopologyInfo, get_NodeType)
        HRESULT ( STDMETHODCALLTYPE *get_NodeType )( 
            IKsTopologyInfo * This,
            /* [annotation][in] */ 
            _In_  DWORD dwNodeId,
            /* [annotation][out] */ 
            _Out_  GUID *pNodeType);
        
        DECLSPEC_XFGVIRT(IKsTopologyInfo, CreateNodeInstance)
        HRESULT ( STDMETHODCALLTYPE *CreateNodeInstance )( 
            IKsTopologyInfo * This,
            /* [annotation][in] */ 
            _In_  DWORD dwNodeId,
            /* [annotation][in] */ 
            _In_  REFIID iid,
            /* [annotation][out] */ 
            _Out_  void **ppvObject);
        
        END_INTERFACE
    } IKsTopologyInfoVtbl;

    interface IKsTopologyInfo
    {
        CONST_VTBL struct IKsTopologyInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IKsTopologyInfo_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IKsTopologyInfo_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IKsTopologyInfo_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IKsTopologyInfo_get_NumCategories(This,pdwNumCategories)	\
    ( (This)->lpVtbl -> get_NumCategories(This,pdwNumCategories) ) 

#define IKsTopologyInfo_get_Category(This,dwIndex,pCategory)	\
    ( (This)->lpVtbl -> get_Category(This,dwIndex,pCategory) ) 

#define IKsTopologyInfo_get_NumConnections(This,pdwNumConnections)	\
    ( (This)->lpVtbl -> get_NumConnections(This,pdwNumConnections) ) 

#define IKsTopologyInfo_get_ConnectionInfo(This,dwIndex,pConnectionInfo)	\
    ( (This)->lpVtbl -> get_ConnectionInfo(This,dwIndex,pConnectionInfo) ) 

#define IKsTopologyInfo_get_NodeName(This,dwNodeId,pwchNodeName,dwBufSize,pdwNameLen)	\
    ( (This)->lpVtbl -> get_NodeName(This,dwNodeId,pwchNodeName,dwBufSize,pdwNameLen) ) 

#define IKsTopologyInfo_get_NumNodes(This,pdwNumNodes)	\
    ( (This)->lpVtbl -> get_NumNodes(This,pdwNumNodes) ) 

#define IKsTopologyInfo_get_NodeType(This,dwNodeId,pNodeType)	\
    ( (This)->lpVtbl -> get_NodeType(This,dwNodeId,pNodeType) ) 

#define IKsTopologyInfo_CreateNodeInstance(This,dwNodeId,iid,ppvObject)	\
    ( (This)->lpVtbl -> CreateNodeInstance(This,dwNodeId,iid,ppvObject) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IKsTopologyInfo_INTERFACE_DEFINED__ */


#ifndef __ISelector_INTERFACE_DEFINED__
#define __ISelector_INTERFACE_DEFINED__

/* interface ISelector */
/* [unique][uuid][local][object] */ 


EXTERN_C const IID IID_ISelector;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1ABDAECA-68B6-4F83-9371-B413907C7B9F")
    ISelector : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE get_NumSources( 
            /* [annotation][out] */ 
            _Out_  DWORD *pdwNumSources) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_SourceNodeId( 
            /* [annotation][out] */ 
            _Out_  DWORD *pdwPinId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_SourceNodeId( 
            /* [annotation][in] */ 
            _In_  DWORD dwPinId) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISelectorVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISelector * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISelector * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISelector * This);
        
        DECLSPEC_XFGVIRT(ISelector, get_NumSources)
        HRESULT ( STDMETHODCALLTYPE *get_NumSources )( 
            ISelector * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwNumSources);
        
        DECLSPEC_XFGVIRT(ISelector, get_SourceNodeId)
        HRESULT ( STDMETHODCALLTYPE *get_SourceNodeId )( 
            ISelector * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwPinId);
        
        DECLSPEC_XFGVIRT(ISelector, put_SourceNodeId)
        HRESULT ( STDMETHODCALLTYPE *put_SourceNodeId )( 
            ISelector * This,
            /* [annotation][in] */ 
            _In_  DWORD dwPinId);
        
        END_INTERFACE
    } ISelectorVtbl;

    interface ISelector
    {
        CONST_VTBL struct ISelectorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISelector_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISelector_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISelector_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISelector_get_NumSources(This,pdwNumSources)	\
    ( (This)->lpVtbl -> get_NumSources(This,pdwNumSources) ) 

#define ISelector_get_SourceNodeId(This,pdwPinId)	\
    ( (This)->lpVtbl -> get_SourceNodeId(This,pdwPinId) ) 

#define ISelector_put_SourceNodeId(This,dwPinId)	\
    ( (This)->lpVtbl -> put_SourceNodeId(This,dwPinId) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISelector_INTERFACE_DEFINED__ */


#ifndef __ICameraControl_INTERFACE_DEFINED__
#define __ICameraControl_INTERFACE_DEFINED__

/* interface ICameraControl */
/* [unique][uuid][local][object] */ 


EXTERN_C const IID IID_ICameraControl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2BA1785D-4D1B-44EF-85E8-C7F1D3F20184")
    ICameraControl : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE get_Exposure( 
            /* [annotation][out] */ 
            _Out_  long *pValue,
            /* [annotation][out] */ 
            _Out_  long *pFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_Exposure( 
            /* [annotation][in] */ 
            _In_  long Value,
            /* [annotation][in] */ 
            _In_  long Flags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getRange_Exposure( 
            /* [annotation][out] */ 
            _Out_  long *pMin,
            /* [annotation][out] */ 
            _Out_  long *pMax,
            /* [annotation][out] */ 
            _Out_  long *pSteppingDelta,
            /* [annotation][out] */ 
            _Out_  long *pDefault,
            /* [annotation][out] */ 
            _Out_  long *pCapsFlag) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_Focus( 
            /* [annotation][out] */ 
            _Out_  long *pValue,
            /* [annotation][out] */ 
            _Out_  long *pFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_Focus( 
            /* [annotation][in] */ 
            _In_  long Value,
            /* [annotation][in] */ 
            _In_  long Flags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getRange_Focus( 
            /* [annotation][out] */ 
            _Out_  long *pMin,
            /* [annotation][out] */ 
            _Out_  long *pMax,
            /* [annotation][out] */ 
            _Out_  long *pSteppingDelta,
            /* [annotation][out] */ 
            _Out_  long *pDefault,
            /* [annotation][out] */ 
            _Out_  long *pCapsFlag) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_Iris( 
            /* [annotation][out] */ 
            _Out_  long *pValue,
            /* [annotation][out] */ 
            _Out_  long *pFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_Iris( 
            /* [annotation][in] */ 
            _In_  long Value,
            /* [annotation][in] */ 
            _In_  long Flags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getRange_Iris( 
            /* [annotation][out] */ 
            _Out_  long *pMin,
            /* [annotation][out] */ 
            _Out_  long *pMax,
            /* [annotation][out] */ 
            _Out_  long *pSteppingDelta,
            /* [annotation][out] */ 
            _Out_  long *pDefault,
            /* [annotation][out] */ 
            _Out_  long *pCapsFlag) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_Zoom( 
            /* [annotation][out] */ 
            _Out_  long *pValue,
            /* [annotation][out] */ 
            _Out_  long *pFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_Zoom( 
            /* [annotation][in] */ 
            _In_  long Value,
            /* [annotation][in] */ 
            _In_  long Flags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getRange_Zoom( 
            /* [annotation][out] */ 
            _Out_  long *pMin,
            /* [annotation][out] */ 
            _Out_  long *pMax,
            /* [annotation][out] */ 
            _Out_  long *pSteppingDelta,
            /* [annotation][out] */ 
            _Out_  long *pDefault,
            /* [annotation][out] */ 
            _Out_  long *pCapsFlag) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_FocalLengths( 
            /* [annotation][out] */ 
            _Out_  long *plOcularFocalLength,
            /* [annotation][out] */ 
            _Out_  long *plObjectiveFocalLengthMin,
            /* [annotation][out] */ 
            _Out_  long *plObjectiveFocalLengthMax) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_Pan( 
            /* [annotation][out] */ 
            _Out_  long *pValue,
            /* [annotation][out] */ 
            _Out_  long *pFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_Pan( 
            /* [annotation][in] */ 
            _In_  long Value,
            /* [annotation][in] */ 
            _In_  long Flags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getRange_Pan( 
            /* [annotation][out] */ 
            _Out_  long *pMin,
            /* [annotation][out] */ 
            _Out_  long *pMax,
            /* [annotation][out] */ 
            _Out_  long *pSteppingDelta,
            /* [annotation][out] */ 
            _Out_  long *pDefault,
            /* [annotation][out] */ 
            _Out_  long *pCapsFlag) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_Tilt( 
            /* [annotation][out] */ 
            _Out_  long *pValue,
            /* [annotation][out] */ 
            _Out_  long *pFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_Tilt( 
            /* [annotation][in] */ 
            _In_  long Value,
            /* [annotation][in] */ 
            _In_  long Flags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getRange_Tilt( 
            /* [annotation][out] */ 
            _Out_  long *pMin,
            /* [annotation][out] */ 
            _Out_  long *pMax,
            /* [annotation][out] */ 
            _Out_  long *pSteppingDelta,
            /* [annotation][out] */ 
            _Out_  long *pDefault,
            /* [annotation][out] */ 
            _Out_  long *pCapsFlag) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_PanTilt( 
            /* [annotation][out] */ 
            _Out_  long *pPanValue,
            /* [annotation][out] */ 
            _Out_  long *pTiltValue,
            /* [annotation][out] */ 
            _Out_  long *pFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_PanTilt( 
            /* [annotation][in] */ 
            _In_  long PanValue,
            /* [annotation][in] */ 
            _In_  long TiltValue,
            /* [annotation][in] */ 
            _In_  long Flags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_Roll( 
            /* [annotation][out] */ 
            _Out_  long *pValue,
            /* [annotation][out] */ 
            _Out_  long *pFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_Roll( 
            /* [annotation][in] */ 
            _In_  long Value,
            /* [annotation][in] */ 
            _In_  long Flags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getRange_Roll( 
            /* [annotation][out] */ 
            _Out_  long *pMin,
            /* [annotation][out] */ 
            _Out_  long *pMax,
            /* [annotation][out] */ 
            _Out_  long *pSteppingDelta,
            /* [annotation][out] */ 
            _Out_  long *pDefault,
            /* [annotation][out] */ 
            _Out_  long *pCapsFlag) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_ExposureRelative( 
            /* [annotation][out] */ 
            _Out_  long *pValue,
            /* [annotation][out] */ 
            _Out_  long *pFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_ExposureRelative( 
            /* [annotation][in] */ 
            _In_  long Value,
            /* [annotation][in] */ 
            _In_  long Flags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getRange_ExposureRelative( 
            /* [annotation][out] */ 
            _Out_  long *pMin,
            /* [annotation][out] */ 
            _Out_  long *pMax,
            /* [annotation][out] */ 
            _Out_  long *pSteppingDelta,
            /* [annotation][out] */ 
            _Out_  long *pDefault,
            /* [annotation][out] */ 
            _Out_  long *pCapsFlag) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_FocusRelative( 
            /* [annotation][out] */ 
            _Out_  long *pValue,
            /* [annotation][out] */ 
            _Out_  long *pFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_FocusRelative( 
            /* [annotation][in] */ 
            _In_  long Value,
            /* [annotation][in] */ 
            _In_  long Flags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getRange_FocusRelative( 
            /* [annotation][out] */ 
            _Out_  long *pMin,
            /* [annotation][out] */ 
            _Out_  long *pMax,
            /* [annotation][out] */ 
            _Out_  long *pSteppingDelta,
            /* [annotation][out] */ 
            _Out_  long *pDefault,
            /* [annotation][out] */ 
            _Out_  long *pCapsFlag) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_IrisRelative( 
            /* [annotation][out] */ 
            _Out_  long *pValue,
            /* [annotation][out] */ 
            _Out_  long *pFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_IrisRelative( 
            /* [annotation][in] */ 
            _In_  long Value,
            /* [annotation][in] */ 
            _In_  long Flags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getRange_IrisRelative( 
            /* [annotation][out] */ 
            _Out_  long *pMin,
            /* [annotation][out] */ 
            _Out_  long *pMax,
            /* [annotation][out] */ 
            _Out_  long *pSteppingDelta,
            /* [annotation][out] */ 
            _Out_  long *pDefault,
            /* [annotation][out] */ 
            _Out_  long *pCapsFlag) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_ZoomRelative( 
            /* [annotation][out] */ 
            _Out_  long *pValue,
            /* [annotation][out] */ 
            _Out_  long *pFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_ZoomRelative( 
            /* [annotation][in] */ 
            _In_  long Value,
            /* [annotation][in] */ 
            _In_  long Flags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getRange_ZoomRelative( 
            /* [annotation][out] */ 
            _Out_  long *pMin,
            /* [annotation][out] */ 
            _Out_  long *pMax,
            /* [annotation][out] */ 
            _Out_  long *pSteppingDelta,
            /* [annotation][out] */ 
            _Out_  long *pDefault,
            /* [annotation][out] */ 
            _Out_  long *pCapsFlag) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_PanRelative( 
            /* [annotation][out] */ 
            _Out_  long *pValue,
            /* [annotation][out] */ 
            _Out_  long *pFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_PanRelative( 
            /* [annotation][in] */ 
            _In_  long Value,
            /* [annotation][in] */ 
            _In_  long Flags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_TiltRelative( 
            /* [annotation][out] */ 
            _Out_  long *pValue,
            /* [annotation][out] */ 
            _Out_  long *pFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_TiltRelative( 
            /* [annotation][in] */ 
            _In_  long Value,
            /* [annotation][in] */ 
            _In_  long Flags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getRange_TiltRelative( 
            /* [annotation][out] */ 
            _Out_  long *pMin,
            /* [annotation][out] */ 
            _Out_  long *pMax,
            /* [annotation][out] */ 
            _Out_  long *pSteppingDelta,
            /* [annotation][out] */ 
            _Out_  long *pDefault,
            /* [annotation][out] */ 
            _Out_  long *pCapsFlag) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_PanTiltRelative( 
            /* [annotation][out] */ 
            _Out_  long *pPanValue,
            /* [annotation][out] */ 
            _Out_  long *pTiltValue,
            /* [annotation][out] */ 
            _Out_  long *pFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_PanTiltRelative( 
            /* [annotation][in] */ 
            _In_  long PanValue,
            /* [annotation][in] */ 
            _In_  long TiltValue,
            /* [annotation][in] */ 
            _In_  long Flags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getRange_PanRelative( 
            /* [annotation][out] */ 
            _Out_  long *pMin,
            /* [annotation][out] */ 
            _Out_  long *pMax,
            /* [annotation][out] */ 
            _Out_  long *pSteppingDelta,
            /* [annotation][out] */ 
            _Out_  long *pDefault,
            /* [annotation][out] */ 
            _Out_  long *pCapsFlag) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_RollRelative( 
            /* [annotation][out] */ 
            _Out_  long *pValue,
            /* [annotation][out] */ 
            _Out_  long *pFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_RollRelative( 
            /* [annotation][in] */ 
            _In_  long Value,
            /* [annotation][in] */ 
            _In_  long Flags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getRange_RollRelative( 
            /* [annotation][out] */ 
            _Out_  long *pMin,
            /* [annotation][out] */ 
            _Out_  long *pMax,
            /* [annotation][out] */ 
            _Out_  long *pSteppingDelta,
            /* [annotation][out] */ 
            _Out_  long *pDefault,
            /* [annotation][out] */ 
            _Out_  long *pCapsFlag) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_ScanMode( 
            /* [annotation][out] */ 
            _Out_  long *pValue,
            /* [annotation][out] */ 
            _Out_  long *pFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_ScanMode( 
            /* [annotation][in] */ 
            _In_  long Value,
            /* [annotation][in] */ 
            _In_  long Flags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_PrivacyMode( 
            /* [annotation][out] */ 
            _Out_  long *pValue,
            /* [annotation][out] */ 
            _Out_  long *pFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_PrivacyMode( 
            /* [annotation][in] */ 
            _In_  long Value,
            /* [annotation][in] */ 
            _In_  long Flags) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICameraControlVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICameraControl * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICameraControl * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICameraControl * This);
        
        DECLSPEC_XFGVIRT(ICameraControl, get_Exposure)
        HRESULT ( STDMETHODCALLTYPE *get_Exposure )( 
            ICameraControl * This,
            /* [annotation][out] */ 
            _Out_  long *pValue,
            /* [annotation][out] */ 
            _Out_  long *pFlags);
        
        DECLSPEC_XFGVIRT(ICameraControl, put_Exposure)
        HRESULT ( STDMETHODCALLTYPE *put_Exposure )( 
            ICameraControl * This,
            /* [annotation][in] */ 
            _In_  long Value,
            /* [annotation][in] */ 
            _In_  long Flags);
        
        DECLSPEC_XFGVIRT(ICameraControl, getRange_Exposure)
        HRESULT ( STDMETHODCALLTYPE *getRange_Exposure )( 
            ICameraControl * This,
            /* [annotation][out] */ 
            _Out_  long *pMin,
            /* [annotation][out] */ 
            _Out_  long *pMax,
            /* [annotation][out] */ 
            _Out_  long *pSteppingDelta,
            /* [annotation][out] */ 
            _Out_  long *pDefault,
            /* [annotation][out] */ 
            _Out_  long *pCapsFlag);
        
        DECLSPEC_XFGVIRT(ICameraControl, get_Focus)
        HRESULT ( STDMETHODCALLTYPE *get_Focus )( 
            ICameraControl * This,
            /* [annotation][out] */ 
            _Out_  long *pValue,
            /* [annotation][out] */ 
            _Out_  long *pFlags);
        
        DECLSPEC_XFGVIRT(ICameraControl, put_Focus)
        HRESULT ( STDMETHODCALLTYPE *put_Focus )( 
            ICameraControl * This,
            /* [annotation][in] */ 
            _In_  long Value,
            /* [annotation][in] */ 
            _In_  long Flags);
        
        DECLSPEC_XFGVIRT(ICameraControl, getRange_Focus)
        HRESULT ( STDMETHODCALLTYPE *getRange_Focus )( 
            ICameraControl * This,
            /* [annotation][out] */ 
            _Out_  long *pMin,
            /* [annotation][out] */ 
            _Out_  long *pMax,
            /* [annotation][out] */ 
            _Out_  long *pSteppingDelta,
            /* [annotation][out] */ 
            _Out_  long *pDefault,
            /* [annotation][out] */ 
            _Out_  long *pCapsFlag);
        
        DECLSPEC_XFGVIRT(ICameraControl, get_Iris)
        HRESULT ( STDMETHODCALLTYPE *get_Iris )( 
            ICameraControl * This,
            /* [annotation][out] */ 
            _Out_  long *pValue,
            /* [annotation][out] */ 
            _Out_  long *pFlags);
        
        DECLSPEC_XFGVIRT(ICameraControl, put_Iris)
        HRESULT ( STDMETHODCALLTYPE *put_Iris )( 
            ICameraControl * This,
            /* [annotation][in] */ 
            _In_  long Value,
            /* [annotation][in] */ 
            _In_  long Flags);
        
        DECLSPEC_XFGVIRT(ICameraControl, getRange_Iris)
        HRESULT ( STDMETHODCALLTYPE *getRange_Iris )( 
            ICameraControl * This,
            /* [annotation][out] */ 
            _Out_  long *pMin,
            /* [annotation][out] */ 
            _Out_  long *pMax,
            /* [annotation][out] */ 
            _Out_  long *pSteppingDelta,
            /* [annotation][out] */ 
            _Out_  long *pDefault,
            /* [annotation][out] */ 
            _Out_  long *pCapsFlag);
        
        DECLSPEC_XFGVIRT(ICameraControl, get_Zoom)
        HRESULT ( STDMETHODCALLTYPE *get_Zoom )( 
            ICameraControl * This,
            /* [annotation][out] */ 
            _Out_  long *pValue,
            /* [annotation][out] */ 
            _Out_  long *pFlags);
        
        DECLSPEC_XFGVIRT(ICameraControl, put_Zoom)
        HRESULT ( STDMETHODCALLTYPE *put_Zoom )( 
            ICameraControl * This,
            /* [annotation][in] */ 
            _In_  long Value,
            /* [annotation][in] */ 
            _In_  long Flags);
        
        DECLSPEC_XFGVIRT(ICameraControl, getRange_Zoom)
        HRESULT ( STDMETHODCALLTYPE *getRange_Zoom )( 
            ICameraControl * This,
            /* [annotation][out] */ 
            _Out_  long *pMin,
            /* [annotation][out] */ 
            _Out_  long *pMax,
            /* [annotation][out] */ 
            _Out_  long *pSteppingDelta,
            /* [annotation][out] */ 
            _Out_  long *pDefault,
            /* [annotation][out] */ 
            _Out_  long *pCapsFlag);
        
        DECLSPEC_XFGVIRT(ICameraControl, get_FocalLengths)
        HRESULT ( STDMETHODCALLTYPE *get_FocalLengths )( 
            ICameraControl * This,
            /* [annotation][out] */ 
            _Out_  long *plOcularFocalLength,
            /* [annotation][out] */ 
            _Out_  long *plObjectiveFocalLengthMin,
            /* [annotation][out] */ 
            _Out_  long *plObjectiveFocalLengthMax);
        
        DECLSPEC_XFGVIRT(ICameraControl, get_Pan)
        HRESULT ( STDMETHODCALLTYPE *get_Pan )( 
            ICameraControl * This,
            /* [annotation][out] */ 
            _Out_  long *pValue,
            /* [annotation][out] */ 
            _Out_  long *pFlags);
        
        DECLSPEC_XFGVIRT(ICameraControl, put_Pan)
        HRESULT ( STDMETHODCALLTYPE *put_Pan )( 
            ICameraControl * This,
            /* [annotation][in] */ 
            _In_  long Value,
            /* [annotation][in] */ 
            _In_  long Flags);
        
        DECLSPEC_XFGVIRT(ICameraControl, getRange_Pan)
        HRESULT ( STDMETHODCALLTYPE *getRange_Pan )( 
            ICameraControl * This,
            /* [annotation][out] */ 
            _Out_  long *pMin,
            /* [annotation][out] */ 
            _Out_  long *pMax,
            /* [annotation][out] */ 
            _Out_  long *pSteppingDelta,
            /* [annotation][out] */ 
            _Out_  long *pDefault,
            /* [annotation][out] */ 
            _Out_  long *pCapsFlag);
        
        DECLSPEC_XFGVIRT(ICameraControl, get_Tilt)
        HRESULT ( STDMETHODCALLTYPE *get_Tilt )( 
            ICameraControl * This,
            /* [annotation][out] */ 
            _Out_  long *pValue,
            /* [annotation][out] */ 
            _Out_  long *pFlags);
        
        DECLSPEC_XFGVIRT(ICameraControl, put_Tilt)
        HRESULT ( STDMETHODCALLTYPE *put_Tilt )( 
            ICameraControl * This,
            /* [annotation][in] */ 
            _In_  long Value,
            /* [annotation][in] */ 
            _In_  long Flags);
        
        DECLSPEC_XFGVIRT(ICameraControl, getRange_Tilt)
        HRESULT ( STDMETHODCALLTYPE *getRange_Tilt )( 
            ICameraControl * This,
            /* [annotation][out] */ 
            _Out_  long *pMin,
            /* [annotation][out] */ 
            _Out_  long *pMax,
            /* [annotation][out] */ 
            _Out_  long *pSteppingDelta,
            /* [annotation][out] */ 
            _Out_  long *pDefault,
            /* [annotation][out] */ 
            _Out_  long *pCapsFlag);
        
        DECLSPEC_XFGVIRT(ICameraControl, get_PanTilt)
        HRESULT ( STDMETHODCALLTYPE *get_PanTilt )( 
            ICameraControl * This,
            /* [annotation][out] */ 
            _Out_  long *pPanValue,
            /* [annotation][out] */ 
            _Out_  long *pTiltValue,
            /* [annotation][out] */ 
            _Out_  long *pFlags);
        
        DECLSPEC_XFGVIRT(ICameraControl, put_PanTilt)
        HRESULT ( STDMETHODCALLTYPE *put_PanTilt )( 
            ICameraControl * This,
            /* [annotation][in] */ 
            _In_  long PanValue,
            /* [annotation][in] */ 
            _In_  long TiltValue,
            /* [annotation][in] */ 
            _In_  long Flags);
        
        DECLSPEC_XFGVIRT(ICameraControl, get_Roll)
        HRESULT ( STDMETHODCALLTYPE *get_Roll )( 
            ICameraControl * This,
            /* [annotation][out] */ 
            _Out_  long *pValue,
            /* [annotation][out] */ 
            _Out_  long *pFlags);
        
        DECLSPEC_XFGVIRT(ICameraControl, put_Roll)
        HRESULT ( STDMETHODCALLTYPE *put_Roll )( 
            ICameraControl * This,
            /* [annotation][in] */ 
            _In_  long Value,
            /* [annotation][in] */ 
            _In_  long Flags);
        
        DECLSPEC_XFGVIRT(ICameraControl, getRange_Roll)
        HRESULT ( STDMETHODCALLTYPE *getRange_Roll )( 
            ICameraControl * This,
            /* [annotation][out] */ 
            _Out_  long *pMin,
            /* [annotation][out] */ 
            _Out_  long *pMax,
            /* [annotation][out] */ 
            _Out_  long *pSteppingDelta,
            /* [annotation][out] */ 
            _Out_  long *pDefault,
            /* [annotation][out] */ 
            _Out_  long *pCapsFlag);
        
        DECLSPEC_XFGVIRT(ICameraControl, get_ExposureRelative)
        HRESULT ( STDMETHODCALLTYPE *get_ExposureRelative )( 
            ICameraControl * This,
            /* [annotation][out] */ 
            _Out_  long *pValue,
            /* [annotation][out] */ 
            _Out_  long *pFlags);
        
        DECLSPEC_XFGVIRT(ICameraControl, put_ExposureRelative)
        HRESULT ( STDMETHODCALLTYPE *put_ExposureRelative )( 
            ICameraControl * This,
            /* [annotation][in] */ 
            _In_  long Value,
            /* [annotation][in] */ 
            _In_  long Flags);
        
        DECLSPEC_XFGVIRT(ICameraControl, getRange_ExposureRelative)
        HRESULT ( STDMETHODCALLTYPE *getRange_ExposureRelative )( 
            ICameraControl * This,
            /* [annotation][out] */ 
            _Out_  long *pMin,
            /* [annotation][out] */ 
            _Out_  long *pMax,
            /* [annotation][out] */ 
            _Out_  long *pSteppingDelta,
            /* [annotation][out] */ 
            _Out_  long *pDefault,
            /* [annotation][out] */ 
            _Out_  long *pCapsFlag);
        
        DECLSPEC_XFGVIRT(ICameraControl, get_FocusRelative)
        HRESULT ( STDMETHODCALLTYPE *get_FocusRelative )( 
            ICameraControl * This,
            /* [annotation][out] */ 
            _Out_  long *pValue,
            /* [annotation][out] */ 
            _Out_  long *pFlags);
        
        DECLSPEC_XFGVIRT(ICameraControl, put_FocusRelative)
        HRESULT ( STDMETHODCALLTYPE *put_FocusRelative )( 
            ICameraControl * This,
            /* [annotation][in] */ 
            _In_  long Value,
            /* [annotation][in] */ 
            _In_  long Flags);
        
        DECLSPEC_XFGVIRT(ICameraControl, getRange_FocusRelative)
        HRESULT ( STDMETHODCALLTYPE *getRange_FocusRelative )( 
            ICameraControl * This,
            /* [annotation][out] */ 
            _Out_  long *pMin,
            /* [annotation][out] */ 
            _Out_  long *pMax,
            /* [annotation][out] */ 
            _Out_  long *pSteppingDelta,
            /* [annotation][out] */ 
            _Out_  long *pDefault,
            /* [annotation][out] */ 
            _Out_  long *pCapsFlag);
        
        DECLSPEC_XFGVIRT(ICameraControl, get_IrisRelative)
        HRESULT ( STDMETHODCALLTYPE *get_IrisRelative )( 
            ICameraControl * This,
            /* [annotation][out] */ 
            _Out_  long *pValue,
            /* [annotation][out] */ 
            _Out_  long *pFlags);
        
        DECLSPEC_XFGVIRT(ICameraControl, put_IrisRelative)
        HRESULT ( STDMETHODCALLTYPE *put_IrisRelative )( 
            ICameraControl * This,
            /* [annotation][in] */ 
            _In_  long Value,
            /* [annotation][in] */ 
            _In_  long Flags);
        
        DECLSPEC_XFGVIRT(ICameraControl, getRange_IrisRelative)
        HRESULT ( STDMETHODCALLTYPE *getRange_IrisRelative )( 
            ICameraControl * This,
            /* [annotation][out] */ 
            _Out_  long *pMin,
            /* [annotation][out] */ 
            _Out_  long *pMax,
            /* [annotation][out] */ 
            _Out_  long *pSteppingDelta,
            /* [annotation][out] */ 
            _Out_  long *pDefault,
            /* [annotation][out] */ 
            _Out_  long *pCapsFlag);
        
        DECLSPEC_XFGVIRT(ICameraControl, get_ZoomRelative)
        HRESULT ( STDMETHODCALLTYPE *get_ZoomRelative )( 
            ICameraControl * This,
            /* [annotation][out] */ 
            _Out_  long *pValue,
            /* [annotation][out] */ 
            _Out_  long *pFlags);
        
        DECLSPEC_XFGVIRT(ICameraControl, put_ZoomRelative)
        HRESULT ( STDMETHODCALLTYPE *put_ZoomRelative )( 
            ICameraControl * This,
            /* [annotation][in] */ 
            _In_  long Value,
            /* [annotation][in] */ 
            _In_  long Flags);
        
        DECLSPEC_XFGVIRT(ICameraControl, getRange_ZoomRelative)
        HRESULT ( STDMETHODCALLTYPE *getRange_ZoomRelative )( 
            ICameraControl * This,
            /* [annotation][out] */ 
            _Out_  long *pMin,
            /* [annotation][out] */ 
            _Out_  long *pMax,
            /* [annotation][out] */ 
            _Out_  long *pSteppingDelta,
            /* [annotation][out] */ 
            _Out_  long *pDefault,
            /* [annotation][out] */ 
            _Out_  long *pCapsFlag);
        
        DECLSPEC_XFGVIRT(ICameraControl, get_PanRelative)
        HRESULT ( STDMETHODCALLTYPE *get_PanRelative )( 
            ICameraControl * This,
            /* [annotation][out] */ 
            _Out_  long *pValue,
            /* [annotation][out] */ 
            _Out_  long *pFlags);
        
        DECLSPEC_XFGVIRT(ICameraControl, put_PanRelative)
        HRESULT ( STDMETHODCALLTYPE *put_PanRelative )( 
            ICameraControl * This,
            /* [annotation][in] */ 
            _In_  long Value,
            /* [annotation][in] */ 
            _In_  long Flags);
        
        DECLSPEC_XFGVIRT(ICameraControl, get_TiltRelative)
        HRESULT ( STDMETHODCALLTYPE *get_TiltRelative )( 
            ICameraControl * This,
            /* [annotation][out] */ 
            _Out_  long *pValue,
            /* [annotation][out] */ 
            _Out_  long *pFlags);
        
        DECLSPEC_XFGVIRT(ICameraControl, put_TiltRelative)
        HRESULT ( STDMETHODCALLTYPE *put_TiltRelative )( 
            ICameraControl * This,
            /* [annotation][in] */ 
            _In_  long Value,
            /* [annotation][in] */ 
            _In_  long Flags);
        
        DECLSPEC_XFGVIRT(ICameraControl, getRange_TiltRelative)
        HRESULT ( STDMETHODCALLTYPE *getRange_TiltRelative )( 
            ICameraControl * This,
            /* [annotation][out] */ 
            _Out_  long *pMin,
            /* [annotation][out] */ 
            _Out_  long *pMax,
            /* [annotation][out] */ 
            _Out_  long *pSteppingDelta,
            /* [annotation][out] */ 
            _Out_  long *pDefault,
            /* [annotation][out] */ 
            _Out_  long *pCapsFlag);
        
        DECLSPEC_XFGVIRT(ICameraControl, get_PanTiltRelative)
        HRESULT ( STDMETHODCALLTYPE *get_PanTiltRelative )( 
            ICameraControl * This,
            /* [annotation][out] */ 
            _Out_  long *pPanValue,
            /* [annotation][out] */ 
            _Out_  long *pTiltValue,
            /* [annotation][out] */ 
            _Out_  long *pFlags);
        
        DECLSPEC_XFGVIRT(ICameraControl, put_PanTiltRelative)
        HRESULT ( STDMETHODCALLTYPE *put_PanTiltRelative )( 
            ICameraControl * This,
            /* [annotation][in] */ 
            _In_  long PanValue,
            /* [annotation][in] */ 
            _In_  long TiltValue,
            /* [annotation][in] */ 
            _In_  long Flags);
        
        DECLSPEC_XFGVIRT(ICameraControl, getRange_PanRelative)
        HRESULT ( STDMETHODCALLTYPE *getRange_PanRelative )( 
            ICameraControl * This,
            /* [annotation][out] */ 
            _Out_  long *pMin,
            /* [annotation][out] */ 
            _Out_  long *pMax,
            /* [annotation][out] */ 
            _Out_  long *pSteppingDelta,
            /* [annotation][out] */ 
            _Out_  long *pDefault,
            /* [annotation][out] */ 
            _Out_  long *pCapsFlag);
        
        DECLSPEC_XFGVIRT(ICameraControl, get_RollRelative)
        HRESULT ( STDMETHODCALLTYPE *get_RollRelative )( 
            ICameraControl * This,
            /* [annotation][out] */ 
            _Out_  long *pValue,
            /* [annotation][out] */ 
            _Out_  long *pFlags);
        
        DECLSPEC_XFGVIRT(ICameraControl, put_RollRelative)
        HRESULT ( STDMETHODCALLTYPE *put_RollRelative )( 
            ICameraControl * This,
            /* [annotation][in] */ 
            _In_  long Value,
            /* [annotation][in] */ 
            _In_  long Flags);
        
        DECLSPEC_XFGVIRT(ICameraControl, getRange_RollRelative)
        HRESULT ( STDMETHODCALLTYPE *getRange_RollRelative )( 
            ICameraControl * This,
            /* [annotation][out] */ 
            _Out_  long *pMin,
            /* [annotation][out] */ 
            _Out_  long *pMax,
            /* [annotation][out] */ 
            _Out_  long *pSteppingDelta,
            /* [annotation][out] */ 
            _Out_  long *pDefault,
            /* [annotation][out] */ 
            _Out_  long *pCapsFlag);
        
        DECLSPEC_XFGVIRT(ICameraControl, get_ScanMode)
        HRESULT ( STDMETHODCALLTYPE *get_ScanMode )( 
            ICameraControl * This,
            /* [annotation][out] */ 
            _Out_  long *pValue,
            /* [annotation][out] */ 
            _Out_  long *pFlags);
        
        DECLSPEC_XFGVIRT(ICameraControl, put_ScanMode)
        HRESULT ( STDMETHODCALLTYPE *put_ScanMode )( 
            ICameraControl * This,
            /* [annotation][in] */ 
            _In_  long Value,
            /* [annotation][in] */ 
            _In_  long Flags);
        
        DECLSPEC_XFGVIRT(ICameraControl, get_PrivacyMode)
        HRESULT ( STDMETHODCALLTYPE *get_PrivacyMode )( 
            ICameraControl * This,
            /* [annotation][out] */ 
            _Out_  long *pValue,
            /* [annotation][out] */ 
            _Out_  long *pFlags);
        
        DECLSPEC_XFGVIRT(ICameraControl, put_PrivacyMode)
        HRESULT ( STDMETHODCALLTYPE *put_PrivacyMode )( 
            ICameraControl * This,
            /* [annotation][in] */ 
            _In_  long Value,
            /* [annotation][in] */ 
            _In_  long Flags);
        
        END_INTERFACE
    } ICameraControlVtbl;

    interface ICameraControl
    {
        CONST_VTBL struct ICameraControlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICameraControl_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICameraControl_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICameraControl_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICameraControl_get_Exposure(This,pValue,pFlags)	\
    ( (This)->lpVtbl -> get_Exposure(This,pValue,pFlags) ) 

#define ICameraControl_put_Exposure(This,Value,Flags)	\
    ( (This)->lpVtbl -> put_Exposure(This,Value,Flags) ) 

#define ICameraControl_getRange_Exposure(This,pMin,pMax,pSteppingDelta,pDefault,pCapsFlag)	\
    ( (This)->lpVtbl -> getRange_Exposure(This,pMin,pMax,pSteppingDelta,pDefault,pCapsFlag) ) 

#define ICameraControl_get_Focus(This,pValue,pFlags)	\
    ( (This)->lpVtbl -> get_Focus(This,pValue,pFlags) ) 

#define ICameraControl_put_Focus(This,Value,Flags)	\
    ( (This)->lpVtbl -> put_Focus(This,Value,Flags) ) 

#define ICameraControl_getRange_Focus(This,pMin,pMax,pSteppingDelta,pDefault,pCapsFlag)	\
    ( (This)->lpVtbl -> getRange_Focus(This,pMin,pMax,pSteppingDelta,pDefault,pCapsFlag) ) 

#define ICameraControl_get_Iris(This,pValue,pFlags)	\
    ( (This)->lpVtbl -> get_Iris(This,pValue,pFlags) ) 

#define ICameraControl_put_Iris(This,Value,Flags)	\
    ( (This)->lpVtbl -> put_Iris(This,Value,Flags) ) 

#define ICameraControl_getRange_Iris(This,pMin,pMax,pSteppingDelta,pDefault,pCapsFlag)	\
    ( (This)->lpVtbl -> getRange_Iris(This,pMin,pMax,pSteppingDelta,pDefault,pCapsFlag) ) 

#define ICameraControl_get_Zoom(This,pValue,pFlags)	\
    ( (This)->lpVtbl -> get_Zoom(This,pValue,pFlags) ) 

#define ICameraControl_put_Zoom(This,Value,Flags)	\
    ( (This)->lpVtbl -> put_Zoom(This,Value,Flags) ) 

#define ICameraControl_getRange_Zoom(This,pMin,pMax,pSteppingDelta,pDefault,pCapsFlag)	\
    ( (This)->lpVtbl -> getRange_Zoom(This,pMin,pMax,pSteppingDelta,pDefault,pCapsFlag) ) 

#define ICameraControl_get_FocalLengths(This,plOcularFocalLength,plObjectiveFocalLengthMin,plObjectiveFocalLengthMax)	\
    ( (This)->lpVtbl -> get_FocalLengths(This,plOcularFocalLength,plObjectiveFocalLengthMin,plObjectiveFocalLengthMax) ) 

#define ICameraControl_get_Pan(This,pValue,pFlags)	\
    ( (This)->lpVtbl -> get_Pan(This,pValue,pFlags) ) 

#define ICameraControl_put_Pan(This,Value,Flags)	\
    ( (This)->lpVtbl -> put_Pan(This,Value,Flags) ) 

#define ICameraControl_getRange_Pan(This,pMin,pMax,pSteppingDelta,pDefault,pCapsFlag)	\
    ( (This)->lpVtbl -> getRange_Pan(This,pMin,pMax,pSteppingDelta,pDefault,pCapsFlag) ) 

#define ICameraControl_get_Tilt(This,pValue,pFlags)	\
    ( (This)->lpVtbl -> get_Tilt(This,pValue,pFlags) ) 

#define ICameraControl_put_Tilt(This,Value,Flags)	\
    ( (This)->lpVtbl -> put_Tilt(This,Value,Flags) ) 

#define ICameraControl_getRange_Tilt(This,pMin,pMax,pSteppingDelta,pDefault,pCapsFlag)	\
    ( (This)->lpVtbl -> getRange_Tilt(This,pMin,pMax,pSteppingDelta,pDefault,pCapsFlag) ) 

#define ICameraControl_get_PanTilt(This,pPanValue,pTiltValue,pFlags)	\
    ( (This)->lpVtbl -> get_PanTilt(This,pPanValue,pTiltValue,pFlags) ) 

#define ICameraControl_put_PanTilt(This,PanValue,TiltValue,Flags)	\
    ( (This)->lpVtbl -> put_PanTilt(This,PanValue,TiltValue,Flags) ) 

#define ICameraControl_get_Roll(This,pValue,pFlags)	\
    ( (This)->lpVtbl -> get_Roll(This,pValue,pFlags) ) 

#define ICameraControl_put_Roll(This,Value,Flags)	\
    ( (This)->lpVtbl -> put_Roll(This,Value,Flags) ) 

#define ICameraControl_getRange_Roll(This,pMin,pMax,pSteppingDelta,pDefault,pCapsFlag)	\
    ( (This)->lpVtbl -> getRange_Roll(This,pMin,pMax,pSteppingDelta,pDefault,pCapsFlag) ) 

#define ICameraControl_get_ExposureRelative(This,pValue,pFlags)	\
    ( (This)->lpVtbl -> get_ExposureRelative(This,pValue,pFlags) ) 

#define ICameraControl_put_ExposureRelative(This,Value,Flags)	\
    ( (This)->lpVtbl -> put_ExposureRelative(This,Value,Flags) ) 

#define ICameraControl_getRange_ExposureRelative(This,pMin,pMax,pSteppingDelta,pDefault,pCapsFlag)	\
    ( (This)->lpVtbl -> getRange_ExposureRelative(This,pMin,pMax,pSteppingDelta,pDefault,pCapsFlag) ) 

#define ICameraControl_get_FocusRelative(This,pValue,pFlags)	\
    ( (This)->lpVtbl -> get_FocusRelative(This,pValue,pFlags) ) 

#define ICameraControl_put_FocusRelative(This,Value,Flags)	\
    ( (This)->lpVtbl -> put_FocusRelative(This,Value,Flags) ) 

#define ICameraControl_getRange_FocusRelative(This,pMin,pMax,pSteppingDelta,pDefault,pCapsFlag)	\
    ( (This)->lpVtbl -> getRange_FocusRelative(This,pMin,pMax,pSteppingDelta,pDefault,pCapsFlag) ) 

#define ICameraControl_get_IrisRelative(This,pValue,pFlags)	\
    ( (This)->lpVtbl -> get_IrisRelative(This,pValue,pFlags) ) 

#define ICameraControl_put_IrisRelative(This,Value,Flags)	\
    ( (This)->lpVtbl -> put_IrisRelative(This,Value,Flags) ) 

#define ICameraControl_getRange_IrisRelative(This,pMin,pMax,pSteppingDelta,pDefault,pCapsFlag)	\
    ( (This)->lpVtbl -> getRange_IrisRelative(This,pMin,pMax,pSteppingDelta,pDefault,pCapsFlag) ) 

#define ICameraControl_get_ZoomRelative(This,pValue,pFlags)	\
    ( (This)->lpVtbl -> get_ZoomRelative(This,pValue,pFlags) ) 

#define ICameraControl_put_ZoomRelative(This,Value,Flags)	\
    ( (This)->lpVtbl -> put_ZoomRelative(This,Value,Flags) ) 

#define ICameraControl_getRange_ZoomRelative(This,pMin,pMax,pSteppingDelta,pDefault,pCapsFlag)	\
    ( (This)->lpVtbl -> getRange_ZoomRelative(This,pMin,pMax,pSteppingDelta,pDefault,pCapsFlag) ) 

#define ICameraControl_get_PanRelative(This,pValue,pFlags)	\
    ( (This)->lpVtbl -> get_PanRelative(This,pValue,pFlags) ) 

#define ICameraControl_put_PanRelative(This,Value,Flags)	\
    ( (This)->lpVtbl -> put_PanRelative(This,Value,Flags) ) 

#define ICameraControl_get_TiltRelative(This,pValue,pFlags)	\
    ( (This)->lpVtbl -> get_TiltRelative(This,pValue,pFlags) ) 

#define ICameraControl_put_TiltRelative(This,Value,Flags)	\
    ( (This)->lpVtbl -> put_TiltRelative(This,Value,Flags) ) 

#define ICameraControl_getRange_TiltRelative(This,pMin,pMax,pSteppingDelta,pDefault,pCapsFlag)	\
    ( (This)->lpVtbl -> getRange_TiltRelative(This,pMin,pMax,pSteppingDelta,pDefault,pCapsFlag) ) 

#define ICameraControl_get_PanTiltRelative(This,pPanValue,pTiltValue,pFlags)	\
    ( (This)->lpVtbl -> get_PanTiltRelative(This,pPanValue,pTiltValue,pFlags) ) 

#define ICameraControl_put_PanTiltRelative(This,PanValue,TiltValue,Flags)	\
    ( (This)->lpVtbl -> put_PanTiltRelative(This,PanValue,TiltValue,Flags) ) 

#define ICameraControl_getRange_PanRelative(This,pMin,pMax,pSteppingDelta,pDefault,pCapsFlag)	\
    ( (This)->lpVtbl -> getRange_PanRelative(This,pMin,pMax,pSteppingDelta,pDefault,pCapsFlag) ) 

#define ICameraControl_get_RollRelative(This,pValue,pFlags)	\
    ( (This)->lpVtbl -> get_RollRelative(This,pValue,pFlags) ) 

#define ICameraControl_put_RollRelative(This,Value,Flags)	\
    ( (This)->lpVtbl -> put_RollRelative(This,Value,Flags) ) 

#define ICameraControl_getRange_RollRelative(This,pMin,pMax,pSteppingDelta,pDefault,pCapsFlag)	\
    ( (This)->lpVtbl -> getRange_RollRelative(This,pMin,pMax,pSteppingDelta,pDefault,pCapsFlag) ) 

#define ICameraControl_get_ScanMode(This,pValue,pFlags)	\
    ( (This)->lpVtbl -> get_ScanMode(This,pValue,pFlags) ) 

#define ICameraControl_put_ScanMode(This,Value,Flags)	\
    ( (This)->lpVtbl -> put_ScanMode(This,Value,Flags) ) 

#define ICameraControl_get_PrivacyMode(This,pValue,pFlags)	\
    ( (This)->lpVtbl -> get_PrivacyMode(This,pValue,pFlags) ) 

#define ICameraControl_put_PrivacyMode(This,Value,Flags)	\
    ( (This)->lpVtbl -> put_PrivacyMode(This,Value,Flags) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICameraControl_INTERFACE_DEFINED__ */


#ifndef __IVideoProcAmp_INTERFACE_DEFINED__
#define __IVideoProcAmp_INTERFACE_DEFINED__

/* interface IVideoProcAmp */
/* [unique][uuid][local][object] */ 


EXTERN_C const IID IID_IVideoProcAmp;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4050560E-42A7-413a-85C2-09269A2D0F44")
    IVideoProcAmp : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE get_BacklightCompensation( 
            /* [annotation][out] */ 
            _Out_  long *pValue,
            /* [annotation][out] */ 
            _Out_  long *pFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_BacklightCompensation( 
            /* [annotation][in] */ 
            _In_  long Value,
            /* [annotation][in] */ 
            _In_  long Flags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getRange_BacklightCompensation( 
            /* [annotation][out] */ 
            _Out_  long *pMin,
            /* [annotation][out] */ 
            _Out_  long *pMax,
            /* [annotation][out] */ 
            _Out_  long *pSteppingDelta,
            /* [annotation][out] */ 
            _Out_  long *pDefault,
            /* [annotation][out] */ 
            _Out_  long *pCapsFlag) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_Brightness( 
            /* [annotation][out] */ 
            _Out_  long *pValue,
            /* [annotation][out] */ 
            _Out_  long *pFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_Brightness( 
            /* [annotation][in] */ 
            _In_  long Value,
            /* [annotation][in] */ 
            _In_  long Flags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getRange_Brightness( 
            /* [annotation][out] */ 
            _Out_  long *pMin,
            /* [annotation][out] */ 
            _Out_  long *pMax,
            /* [annotation][out] */ 
            _Out_  long *pSteppingDelta,
            /* [annotation][out] */ 
            _Out_  long *pDefault,
            /* [annotation][out] */ 
            _Out_  long *pCapsFlag) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_ColorEnable( 
            /* [annotation][out] */ 
            _Out_  long *pValue,
            /* [annotation][out] */ 
            _Out_  long *pFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_ColorEnable( 
            /* [annotation][in] */ 
            _In_  long Value,
            /* [annotation][in] */ 
            _In_  long Flags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getRange_ColorEnable( 
            /* [annotation][out] */ 
            _Out_  long *pMin,
            /* [annotation][out] */ 
            _Out_  long *pMax,
            /* [annotation][out] */ 
            _Out_  long *pSteppingDelta,
            /* [annotation][out] */ 
            _Out_  long *pDefault,
            /* [annotation][out] */ 
            _Out_  long *pCapsFlag) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_Contrast( 
            /* [annotation][out] */ 
            _Out_  long *pValue,
            /* [annotation][out] */ 
            _Out_  long *pFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_Contrast( 
            /* [annotation][in] */ 
            _In_  long Value,
            /* [annotation][in] */ 
            _In_  long Flags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getRange_Contrast( 
            /* [annotation][out] */ 
            _Out_  long *pMin,
            /* [annotation][out] */ 
            _Out_  long *pMax,
            /* [annotation][out] */ 
            _Out_  long *pSteppingDelta,
            /* [annotation][out] */ 
            _Out_  long *pDefault,
            /* [annotation][out] */ 
            _Out_  long *pCapsFlag) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_Gamma( 
            /* [annotation][out] */ 
            _Out_  long *pValue,
            /* [annotation][out] */ 
            _Out_  long *pFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_Gamma( 
            /* [annotation][in] */ 
            _In_  long Value,
            /* [annotation][in] */ 
            _In_  long Flags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getRange_Gamma( 
            /* [annotation][out] */ 
            _Out_  long *pMin,
            /* [annotation][out] */ 
            _Out_  long *pMax,
            /* [annotation][out] */ 
            _Out_  long *pSteppingDelta,
            /* [annotation][out] */ 
            _Out_  long *pDefault,
            /* [annotation][out] */ 
            _Out_  long *pCapsFlag) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_Saturation( 
            /* [annotation][out] */ 
            _Out_  long *pValue,
            /* [annotation][out] */ 
            _Out_  long *pFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_Saturation( 
            /* [annotation][in] */ 
            _In_  long Value,
            /* [annotation][in] */ 
            _In_  long Flags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getRange_Saturation( 
            /* [annotation][out] */ 
            _Out_  long *pMin,
            /* [annotation][out] */ 
            _Out_  long *pMax,
            /* [annotation][out] */ 
            _Out_  long *pSteppingDelta,
            /* [annotation][out] */ 
            _Out_  long *pDefault,
            /* [annotation][out] */ 
            _Out_  long *pCapsFlag) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_Sharpness( 
            /* [annotation][out] */ 
            _Out_  long *pValue,
            /* [annotation][out] */ 
            _Out_  long *pFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_Sharpness( 
            /* [annotation][in] */ 
            _In_  long Value,
            /* [annotation][in] */ 
            _In_  long Flags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getRange_Sharpness( 
            /* [annotation][out] */ 
            _Out_  long *pMin,
            /* [annotation][out] */ 
            _Out_  long *pMax,
            /* [annotation][out] */ 
            _Out_  long *pSteppingDelta,
            /* [annotation][out] */ 
            _Out_  long *pDefault,
            /* [annotation][out] */ 
            _Out_  long *pCapsFlag) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_WhiteBalance( 
            /* [annotation][out] */ 
            _Out_  long *pValue,
            /* [annotation][out] */ 
            _Out_  long *pFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_WhiteBalance( 
            /* [annotation][in] */ 
            _In_  long Value,
            /* [annotation][in] */ 
            _In_  long Flags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getRange_WhiteBalance( 
            /* [annotation][out] */ 
            _Out_  long *pMin,
            /* [annotation][out] */ 
            _Out_  long *pMax,
            /* [annotation][out] */ 
            _Out_  long *pSteppingDelta,
            /* [annotation][out] */ 
            _Out_  long *pDefault,
            /* [annotation][out] */ 
            _Out_  long *pCapsFlag) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_Gain( 
            /* [annotation][out] */ 
            _Out_  long *pValue,
            /* [annotation][out] */ 
            _Out_  long *pFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_Gain( 
            /* [annotation][in] */ 
            _In_  long Value,
            /* [annotation][in] */ 
            _In_  long Flags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getRange_Gain( 
            /* [annotation][out] */ 
            _Out_  long *pMin,
            /* [annotation][out] */ 
            _Out_  long *pMax,
            /* [annotation][out] */ 
            _Out_  long *pSteppingDelta,
            /* [annotation][out] */ 
            _Out_  long *pDefault,
            /* [annotation][out] */ 
            _Out_  long *pCapsFlag) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_Hue( 
            /* [annotation][out] */ 
            _Out_  long *pValue,
            /* [annotation][out] */ 
            _Out_  long *pFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_Hue( 
            /* [annotation][in] */ 
            _In_  long Value,
            /* [annotation][in] */ 
            _In_  long Flags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getRange_Hue( 
            /* [annotation][out] */ 
            _Out_  long *pMin,
            /* [annotation][out] */ 
            _Out_  long *pMax,
            /* [annotation][out] */ 
            _Out_  long *pSteppingDelta,
            /* [annotation][out] */ 
            _Out_  long *pDefault,
            /* [annotation][out] */ 
            _Out_  long *pCapsFlag) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_DigitalMultiplier( 
            /* [annotation][out] */ 
            _Out_  long *pValue,
            /* [annotation][out] */ 
            _Out_  long *pFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_DigitalMultiplier( 
            /* [annotation][in] */ 
            _In_  long Value,
            /* [annotation][in] */ 
            _In_  long Flags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getRange_DigitalMultiplier( 
            /* [annotation][out] */ 
            _Out_  long *pMin,
            /* [annotation][out] */ 
            _Out_  long *pMax,
            /* [annotation][out] */ 
            _Out_  long *pSteppingDelta,
            /* [annotation][out] */ 
            _Out_  long *pDefault,
            /* [annotation][out] */ 
            _Out_  long *pCapsFlag) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_PowerlineFrequency( 
            /* [annotation][out] */ 
            _Out_  long *pValue,
            /* [annotation][out] */ 
            _Out_  long *pFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_PowerlineFrequency( 
            /* [annotation][in] */ 
            _In_  long Value,
            /* [annotation][in] */ 
            _In_  long Flags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getRange_PowerlineFrequency( 
            /* [annotation][out] */ 
            _Out_  long *pMin,
            /* [annotation][out] */ 
            _Out_  long *pMax,
            /* [annotation][out] */ 
            _Out_  long *pSteppingDelta,
            /* [annotation][out] */ 
            _Out_  long *pDefault,
            /* [annotation][out] */ 
            _Out_  long *pCapsFlag) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_WhiteBalanceComponent( 
            /* [annotation][out] */ 
            _Out_  long *pValue1,
            /* [annotation][out] */ 
            _Out_  long *pValue2,
            /* [annotation][out][in] */ 
            _Inout_  long *pFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_WhiteBalanceComponent( 
            /* [annotation][in] */ 
            _In_  long Value1,
            /* [annotation][in] */ 
            _In_  long Value2,
            /* [annotation][in] */ 
            _In_  long Flags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getRange_WhiteBalanceComponent( 
            /* [annotation][out] */ 
            _Out_  long *pMin,
            /* [annotation][out] */ 
            _Out_  long *pMax,
            /* [annotation][out] */ 
            _Out_  long *pSteppingDelta,
            /* [annotation][out] */ 
            _Out_  long *pDefault,
            /* [annotation][out][in] */ 
            _Inout_  long *pCapsFlag) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IVideoProcAmpVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVideoProcAmp * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVideoProcAmp * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVideoProcAmp * This);
        
        DECLSPEC_XFGVIRT(IVideoProcAmp, get_BacklightCompensation)
        HRESULT ( STDMETHODCALLTYPE *get_BacklightCompensation )( 
            IVideoProcAmp * This,
            /* [annotation][out] */ 
            _Out_  long *pValue,
            /* [annotation][out] */ 
            _Out_  long *pFlags);
        
        DECLSPEC_XFGVIRT(IVideoProcAmp, put_BacklightCompensation)
        HRESULT ( STDMETHODCALLTYPE *put_BacklightCompensation )( 
            IVideoProcAmp * This,
            /* [annotation][in] */ 
            _In_  long Value,
            /* [annotation][in] */ 
            _In_  long Flags);
        
        DECLSPEC_XFGVIRT(IVideoProcAmp, getRange_BacklightCompensation)
        HRESULT ( STDMETHODCALLTYPE *getRange_BacklightCompensation )( 
            IVideoProcAmp * This,
            /* [annotation][out] */ 
            _Out_  long *pMin,
            /* [annotation][out] */ 
            _Out_  long *pMax,
            /* [annotation][out] */ 
            _Out_  long *pSteppingDelta,
            /* [annotation][out] */ 
            _Out_  long *pDefault,
            /* [annotation][out] */ 
            _Out_  long *pCapsFlag);
        
        DECLSPEC_XFGVIRT(IVideoProcAmp, get_Brightness)
        HRESULT ( STDMETHODCALLTYPE *get_Brightness )( 
            IVideoProcAmp * This,
            /* [annotation][out] */ 
            _Out_  long *pValue,
            /* [annotation][out] */ 
            _Out_  long *pFlags);
        
        DECLSPEC_XFGVIRT(IVideoProcAmp, put_Brightness)
        HRESULT ( STDMETHODCALLTYPE *put_Brightness )( 
            IVideoProcAmp * This,
            /* [annotation][in] */ 
            _In_  long Value,
            /* [annotation][in] */ 
            _In_  long Flags);
        
        DECLSPEC_XFGVIRT(IVideoProcAmp, getRange_Brightness)
        HRESULT ( STDMETHODCALLTYPE *getRange_Brightness )( 
            IVideoProcAmp * This,
            /* [annotation][out] */ 
            _Out_  long *pMin,
            /* [annotation][out] */ 
            _Out_  long *pMax,
            /* [annotation][out] */ 
            _Out_  long *pSteppingDelta,
            /* [annotation][out] */ 
            _Out_  long *pDefault,
            /* [annotation][out] */ 
            _Out_  long *pCapsFlag);
        
        DECLSPEC_XFGVIRT(IVideoProcAmp, get_ColorEnable)
        HRESULT ( STDMETHODCALLTYPE *get_ColorEnable )( 
            IVideoProcAmp * This,
            /* [annotation][out] */ 
            _Out_  long *pValue,
            /* [annotation][out] */ 
            _Out_  long *pFlags);
        
        DECLSPEC_XFGVIRT(IVideoProcAmp, put_ColorEnable)
        HRESULT ( STDMETHODCALLTYPE *put_ColorEnable )( 
            IVideoProcAmp * This,
            /* [annotation][in] */ 
            _In_  long Value,
            /* [annotation][in] */ 
            _In_  long Flags);
        
        DECLSPEC_XFGVIRT(IVideoProcAmp, getRange_ColorEnable)
        HRESULT ( STDMETHODCALLTYPE *getRange_ColorEnable )( 
            IVideoProcAmp * This,
            /* [annotation][out] */ 
            _Out_  long *pMin,
            /* [annotation][out] */ 
            _Out_  long *pMax,
            /* [annotation][out] */ 
            _Out_  long *pSteppingDelta,
            /* [annotation][out] */ 
            _Out_  long *pDefault,
            /* [annotation][out] */ 
            _Out_  long *pCapsFlag);
        
        DECLSPEC_XFGVIRT(IVideoProcAmp, get_Contrast)
        HRESULT ( STDMETHODCALLTYPE *get_Contrast )( 
            IVideoProcAmp * This,
            /* [annotation][out] */ 
            _Out_  long *pValue,
            /* [annotation][out] */ 
            _Out_  long *pFlags);
        
        DECLSPEC_XFGVIRT(IVideoProcAmp, put_Contrast)
        HRESULT ( STDMETHODCALLTYPE *put_Contrast )( 
            IVideoProcAmp * This,
            /* [annotation][in] */ 
            _In_  long Value,
            /* [annotation][in] */ 
            _In_  long Flags);
        
        DECLSPEC_XFGVIRT(IVideoProcAmp, getRange_Contrast)
        HRESULT ( STDMETHODCALLTYPE *getRange_Contrast )( 
            IVideoProcAmp * This,
            /* [annotation][out] */ 
            _Out_  long *pMin,
            /* [annotation][out] */ 
            _Out_  long *pMax,
            /* [annotation][out] */ 
            _Out_  long *pSteppingDelta,
            /* [annotation][out] */ 
            _Out_  long *pDefault,
            /* [annotation][out] */ 
            _Out_  long *pCapsFlag);
        
        DECLSPEC_XFGVIRT(IVideoProcAmp, get_Gamma)
        HRESULT ( STDMETHODCALLTYPE *get_Gamma )( 
            IVideoProcAmp * This,
            /* [annotation][out] */ 
            _Out_  long *pValue,
            /* [annotation][out] */ 
            _Out_  long *pFlags);
        
        DECLSPEC_XFGVIRT(IVideoProcAmp, put_Gamma)
        HRESULT ( STDMETHODCALLTYPE *put_Gamma )( 
            IVideoProcAmp * This,
            /* [annotation][in] */ 
            _In_  long Value,
            /* [annotation][in] */ 
            _In_  long Flags);
        
        DECLSPEC_XFGVIRT(IVideoProcAmp, getRange_Gamma)
        HRESULT ( STDMETHODCALLTYPE *getRange_Gamma )( 
            IVideoProcAmp * This,
            /* [annotation][out] */ 
            _Out_  long *pMin,
            /* [annotation][out] */ 
            _Out_  long *pMax,
            /* [annotation][out] */ 
            _Out_  long *pSteppingDelta,
            /* [annotation][out] */ 
            _Out_  long *pDefault,
            /* [annotation][out] */ 
            _Out_  long *pCapsFlag);
        
        DECLSPEC_XFGVIRT(IVideoProcAmp, get_Saturation)
        HRESULT ( STDMETHODCALLTYPE *get_Saturation )( 
            IVideoProcAmp * This,
            /* [annotation][out] */ 
            _Out_  long *pValue,
            /* [annotation][out] */ 
            _Out_  long *pFlags);
        
        DECLSPEC_XFGVIRT(IVideoProcAmp, put_Saturation)
        HRESULT ( STDMETHODCALLTYPE *put_Saturation )( 
            IVideoProcAmp * This,
            /* [annotation][in] */ 
            _In_  long Value,
            /* [annotation][in] */ 
            _In_  long Flags);
        
        DECLSPEC_XFGVIRT(IVideoProcAmp, getRange_Saturation)
        HRESULT ( STDMETHODCALLTYPE *getRange_Saturation )( 
            IVideoProcAmp * This,
            /* [annotation][out] */ 
            _Out_  long *pMin,
            /* [annotation][out] */ 
            _Out_  long *pMax,
            /* [annotation][out] */ 
            _Out_  long *pSteppingDelta,
            /* [annotation][out] */ 
            _Out_  long *pDefault,
            /* [annotation][out] */ 
            _Out_  long *pCapsFlag);
        
        DECLSPEC_XFGVIRT(IVideoProcAmp, get_Sharpness)
        HRESULT ( STDMETHODCALLTYPE *get_Sharpness )( 
            IVideoProcAmp * This,
            /* [annotation][out] */ 
            _Out_  long *pValue,
            /* [annotation][out] */ 
            _Out_  long *pFlags);
        
        DECLSPEC_XFGVIRT(IVideoProcAmp, put_Sharpness)
        HRESULT ( STDMETHODCALLTYPE *put_Sharpness )( 
            IVideoProcAmp * This,
            /* [annotation][in] */ 
            _In_  long Value,
            /* [annotation][in] */ 
            _In_  long Flags);
        
        DECLSPEC_XFGVIRT(IVideoProcAmp, getRange_Sharpness)
        HRESULT ( STDMETHODCALLTYPE *getRange_Sharpness )( 
            IVideoProcAmp * This,
            /* [annotation][out] */ 
            _Out_  long *pMin,
            /* [annotation][out] */ 
            _Out_  long *pMax,
            /* [annotation][out] */ 
            _Out_  long *pSteppingDelta,
            /* [annotation][out] */ 
            _Out_  long *pDefault,
            /* [annotation][out] */ 
            _Out_  long *pCapsFlag);
        
        DECLSPEC_XFGVIRT(IVideoProcAmp, get_WhiteBalance)
        HRESULT ( STDMETHODCALLTYPE *get_WhiteBalance )( 
            IVideoProcAmp * This,
            /* [annotation][out] */ 
            _Out_  long *pValue,
            /* [annotation][out] */ 
            _Out_  long *pFlags);
        
        DECLSPEC_XFGVIRT(IVideoProcAmp, put_WhiteBalance)
        HRESULT ( STDMETHODCALLTYPE *put_WhiteBalance )( 
            IVideoProcAmp * This,
            /* [annotation][in] */ 
            _In_  long Value,
            /* [annotation][in] */ 
            _In_  long Flags);
        
        DECLSPEC_XFGVIRT(IVideoProcAmp, getRange_WhiteBalance)
        HRESULT ( STDMETHODCALLTYPE *getRange_WhiteBalance )( 
            IVideoProcAmp * This,
            /* [annotation][out] */ 
            _Out_  long *pMin,
            /* [annotation][out] */ 
            _Out_  long *pMax,
            /* [annotation][out] */ 
            _Out_  long *pSteppingDelta,
            /* [annotation][out] */ 
            _Out_  long *pDefault,
            /* [annotation][out] */ 
            _Out_  long *pCapsFlag);
        
        DECLSPEC_XFGVIRT(IVideoProcAmp, get_Gain)
        HRESULT ( STDMETHODCALLTYPE *get_Gain )( 
            IVideoProcAmp * This,
            /* [annotation][out] */ 
            _Out_  long *pValue,
            /* [annotation][out] */ 
            _Out_  long *pFlags);
        
        DECLSPEC_XFGVIRT(IVideoProcAmp, put_Gain)
        HRESULT ( STDMETHODCALLTYPE *put_Gain )( 
            IVideoProcAmp * This,
            /* [annotation][in] */ 
            _In_  long Value,
            /* [annotation][in] */ 
            _In_  long Flags);
        
        DECLSPEC_XFGVIRT(IVideoProcAmp, getRange_Gain)
        HRESULT ( STDMETHODCALLTYPE *getRange_Gain )( 
            IVideoProcAmp * This,
            /* [annotation][out] */ 
            _Out_  long *pMin,
            /* [annotation][out] */ 
            _Out_  long *pMax,
            /* [annotation][out] */ 
            _Out_  long *pSteppingDelta,
            /* [annotation][out] */ 
            _Out_  long *pDefault,
            /* [annotation][out] */ 
            _Out_  long *pCapsFlag);
        
        DECLSPEC_XFGVIRT(IVideoProcAmp, get_Hue)
        HRESULT ( STDMETHODCALLTYPE *get_Hue )( 
            IVideoProcAmp * This,
            /* [annotation][out] */ 
            _Out_  long *pValue,
            /* [annotation][out] */ 
            _Out_  long *pFlags);
        
        DECLSPEC_XFGVIRT(IVideoProcAmp, put_Hue)
        HRESULT ( STDMETHODCALLTYPE *put_Hue )( 
            IVideoProcAmp * This,
            /* [annotation][in] */ 
            _In_  long Value,
            /* [annotation][in] */ 
            _In_  long Flags);
        
        DECLSPEC_XFGVIRT(IVideoProcAmp, getRange_Hue)
        HRESULT ( STDMETHODCALLTYPE *getRange_Hue )( 
            IVideoProcAmp * This,
            /* [annotation][out] */ 
            _Out_  long *pMin,
            /* [annotation][out] */ 
            _Out_  long *pMax,
            /* [annotation][out] */ 
            _Out_  long *pSteppingDelta,
            /* [annotation][out] */ 
            _Out_  long *pDefault,
            /* [annotation][out] */ 
            _Out_  long *pCapsFlag);
        
        DECLSPEC_XFGVIRT(IVideoProcAmp, get_DigitalMultiplier)
        HRESULT ( STDMETHODCALLTYPE *get_DigitalMultiplier )( 
            IVideoProcAmp * This,
            /* [annotation][out] */ 
            _Out_  long *pValue,
            /* [annotation][out] */ 
            _Out_  long *pFlags);
        
        DECLSPEC_XFGVIRT(IVideoProcAmp, put_DigitalMultiplier)
        HRESULT ( STDMETHODCALLTYPE *put_DigitalMultiplier )( 
            IVideoProcAmp * This,
            /* [annotation][in] */ 
            _In_  long Value,
            /* [annotation][in] */ 
            _In_  long Flags);
        
        DECLSPEC_XFGVIRT(IVideoProcAmp, getRange_DigitalMultiplier)
        HRESULT ( STDMETHODCALLTYPE *getRange_DigitalMultiplier )( 
            IVideoProcAmp * This,
            /* [annotation][out] */ 
            _Out_  long *pMin,
            /* [annotation][out] */ 
            _Out_  long *pMax,
            /* [annotation][out] */ 
            _Out_  long *pSteppingDelta,
            /* [annotation][out] */ 
            _Out_  long *pDefault,
            /* [annotation][out] */ 
            _Out_  long *pCapsFlag);
        
        DECLSPEC_XFGVIRT(IVideoProcAmp, get_PowerlineFrequency)
        HRESULT ( STDMETHODCALLTYPE *get_PowerlineFrequency )( 
            IVideoProcAmp * This,
            /* [annotation][out] */ 
            _Out_  long *pValue,
            /* [annotation][out] */ 
            _Out_  long *pFlags);
        
        DECLSPEC_XFGVIRT(IVideoProcAmp, put_PowerlineFrequency)
        HRESULT ( STDMETHODCALLTYPE *put_PowerlineFrequency )( 
            IVideoProcAmp * This,
            /* [annotation][in] */ 
            _In_  long Value,
            /* [annotation][in] */ 
            _In_  long Flags);
        
        DECLSPEC_XFGVIRT(IVideoProcAmp, getRange_PowerlineFrequency)
        HRESULT ( STDMETHODCALLTYPE *getRange_PowerlineFrequency )( 
            IVideoProcAmp * This,
            /* [annotation][out] */ 
            _Out_  long *pMin,
            /* [annotation][out] */ 
            _Out_  long *pMax,
            /* [annotation][out] */ 
            _Out_  long *pSteppingDelta,
            /* [annotation][out] */ 
            _Out_  long *pDefault,
            /* [annotation][out] */ 
            _Out_  long *pCapsFlag);
        
        DECLSPEC_XFGVIRT(IVideoProcAmp, get_WhiteBalanceComponent)
        HRESULT ( STDMETHODCALLTYPE *get_WhiteBalanceComponent )( 
            IVideoProcAmp * This,
            /* [annotation][out] */ 
            _Out_  long *pValue1,
            /* [annotation][out] */ 
            _Out_  long *pValue2,
            /* [annotation][out][in] */ 
            _Inout_  long *pFlags);
        
        DECLSPEC_XFGVIRT(IVideoProcAmp, put_WhiteBalanceComponent)
        HRESULT ( STDMETHODCALLTYPE *put_WhiteBalanceComponent )( 
            IVideoProcAmp * This,
            /* [annotation][in] */ 
            _In_  long Value1,
            /* [annotation][in] */ 
            _In_  long Value2,
            /* [annotation][in] */ 
            _In_  long Flags);
        
        DECLSPEC_XFGVIRT(IVideoProcAmp, getRange_WhiteBalanceComponent)
        HRESULT ( STDMETHODCALLTYPE *getRange_WhiteBalanceComponent )( 
            IVideoProcAmp * This,
            /* [annotation][out] */ 
            _Out_  long *pMin,
            /* [annotation][out] */ 
            _Out_  long *pMax,
            /* [annotation][out] */ 
            _Out_  long *pSteppingDelta,
            /* [annotation][out] */ 
            _Out_  long *pDefault,
            /* [annotation][out][in] */ 
            _Inout_  long *pCapsFlag);
        
        END_INTERFACE
    } IVideoProcAmpVtbl;

    interface IVideoProcAmp
    {
        CONST_VTBL struct IVideoProcAmpVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVideoProcAmp_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IVideoProcAmp_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IVideoProcAmp_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IVideoProcAmp_get_BacklightCompensation(This,pValue,pFlags)	\
    ( (This)->lpVtbl -> get_BacklightCompensation(This,pValue,pFlags) ) 

#define IVideoProcAmp_put_BacklightCompensation(This,Value,Flags)	\
    ( (This)->lpVtbl -> put_BacklightCompensation(This,Value,Flags) ) 

#define IVideoProcAmp_getRange_BacklightCompensation(This,pMin,pMax,pSteppingDelta,pDefault,pCapsFlag)	\
    ( (This)->lpVtbl -> getRange_BacklightCompensation(This,pMin,pMax,pSteppingDelta,pDefault,pCapsFlag) ) 

#define IVideoProcAmp_get_Brightness(This,pValue,pFlags)	\
    ( (This)->lpVtbl -> get_Brightness(This,pValue,pFlags) ) 

#define IVideoProcAmp_put_Brightness(This,Value,Flags)	\
    ( (This)->lpVtbl -> put_Brightness(This,Value,Flags) ) 

#define IVideoProcAmp_getRange_Brightness(This,pMin,pMax,pSteppingDelta,pDefault,pCapsFlag)	\
    ( (This)->lpVtbl -> getRange_Brightness(This,pMin,pMax,pSteppingDelta,pDefault,pCapsFlag) ) 

#define IVideoProcAmp_get_ColorEnable(This,pValue,pFlags)	\
    ( (This)->lpVtbl -> get_ColorEnable(This,pValue,pFlags) ) 

#define IVideoProcAmp_put_ColorEnable(This,Value,Flags)	\
    ( (This)->lpVtbl -> put_ColorEnable(This,Value,Flags) ) 

#define IVideoProcAmp_getRange_ColorEnable(This,pMin,pMax,pSteppingDelta,pDefault,pCapsFlag)	\
    ( (This)->lpVtbl -> getRange_ColorEnable(This,pMin,pMax,pSteppingDelta,pDefault,pCapsFlag) ) 

#define IVideoProcAmp_get_Contrast(This,pValue,pFlags)	\
    ( (This)->lpVtbl -> get_Contrast(This,pValue,pFlags) ) 

#define IVideoProcAmp_put_Contrast(This,Value,Flags)	\
    ( (This)->lpVtbl -> put_Contrast(This,Value,Flags) ) 

#define IVideoProcAmp_getRange_Contrast(This,pMin,pMax,pSteppingDelta,pDefault,pCapsFlag)	\
    ( (This)->lpVtbl -> getRange_Contrast(This,pMin,pMax,pSteppingDelta,pDefault,pCapsFlag) ) 

#define IVideoProcAmp_get_Gamma(This,pValue,pFlags)	\
    ( (This)->lpVtbl -> get_Gamma(This,pValue,pFlags) ) 

#define IVideoProcAmp_put_Gamma(This,Value,Flags)	\
    ( (This)->lpVtbl -> put_Gamma(This,Value,Flags) ) 

#define IVideoProcAmp_getRange_Gamma(This,pMin,pMax,pSteppingDelta,pDefault,pCapsFlag)	\
    ( (This)->lpVtbl -> getRange_Gamma(This,pMin,pMax,pSteppingDelta,pDefault,pCapsFlag) ) 

#define IVideoProcAmp_get_Saturation(This,pValue,pFlags)	\
    ( (This)->lpVtbl -> get_Saturation(This,pValue,pFlags) ) 

#define IVideoProcAmp_put_Saturation(This,Value,Flags)	\
    ( (This)->lpVtbl -> put_Saturation(This,Value,Flags) ) 

#define IVideoProcAmp_getRange_Saturation(This,pMin,pMax,pSteppingDelta,pDefault,pCapsFlag)	\
    ( (This)->lpVtbl -> getRange_Saturation(This,pMin,pMax,pSteppingDelta,pDefault,pCapsFlag) ) 

#define IVideoProcAmp_get_Sharpness(This,pValue,pFlags)	\
    ( (This)->lpVtbl -> get_Sharpness(This,pValue,pFlags) ) 

#define IVideoProcAmp_put_Sharpness(This,Value,Flags)	\
    ( (This)->lpVtbl -> put_Sharpness(This,Value,Flags) ) 

#define IVideoProcAmp_getRange_Sharpness(This,pMin,pMax,pSteppingDelta,pDefault,pCapsFlag)	\
    ( (This)->lpVtbl -> getRange_Sharpness(This,pMin,pMax,pSteppingDelta,pDefault,pCapsFlag) ) 

#define IVideoProcAmp_get_WhiteBalance(This,pValue,pFlags)	\
    ( (This)->lpVtbl -> get_WhiteBalance(This,pValue,pFlags) ) 

#define IVideoProcAmp_put_WhiteBalance(This,Value,Flags)	\
    ( (This)->lpVtbl -> put_WhiteBalance(This,Value,Flags) ) 

#define IVideoProcAmp_getRange_WhiteBalance(This,pMin,pMax,pSteppingDelta,pDefault,pCapsFlag)	\
    ( (This)->lpVtbl -> getRange_WhiteBalance(This,pMin,pMax,pSteppingDelta,pDefault,pCapsFlag) ) 

#define IVideoProcAmp_get_Gain(This,pValue,pFlags)	\
    ( (This)->lpVtbl -> get_Gain(This,pValue,pFlags) ) 

#define IVideoProcAmp_put_Gain(This,Value,Flags)	\
    ( (This)->lpVtbl -> put_Gain(This,Value,Flags) ) 

#define IVideoProcAmp_getRange_Gain(This,pMin,pMax,pSteppingDelta,pDefault,pCapsFlag)	\
    ( (This)->lpVtbl -> getRange_Gain(This,pMin,pMax,pSteppingDelta,pDefault,pCapsFlag) ) 

#define IVideoProcAmp_get_Hue(This,pValue,pFlags)	\
    ( (This)->lpVtbl -> get_Hue(This,pValue,pFlags) ) 

#define IVideoProcAmp_put_Hue(This,Value,Flags)	\
    ( (This)->lpVtbl -> put_Hue(This,Value,Flags) ) 

#define IVideoProcAmp_getRange_Hue(This,pMin,pMax,pSteppingDelta,pDefault,pCapsFlag)	\
    ( (This)->lpVtbl -> getRange_Hue(This,pMin,pMax,pSteppingDelta,pDefault,pCapsFlag) ) 

#define IVideoProcAmp_get_DigitalMultiplier(This,pValue,pFlags)	\
    ( (This)->lpVtbl -> get_DigitalMultiplier(This,pValue,pFlags) ) 

#define IVideoProcAmp_put_DigitalMultiplier(This,Value,Flags)	\
    ( (This)->lpVtbl -> put_DigitalMultiplier(This,Value,Flags) ) 

#define IVideoProcAmp_getRange_DigitalMultiplier(This,pMin,pMax,pSteppingDelta,pDefault,pCapsFlag)	\
    ( (This)->lpVtbl -> getRange_DigitalMultiplier(This,pMin,pMax,pSteppingDelta,pDefault,pCapsFlag) ) 

#define IVideoProcAmp_get_PowerlineFrequency(This,pValue,pFlags)	\
    ( (This)->lpVtbl -> get_PowerlineFrequency(This,pValue,pFlags) ) 

#define IVideoProcAmp_put_PowerlineFrequency(This,Value,Flags)	\
    ( (This)->lpVtbl -> put_PowerlineFrequency(This,Value,Flags) ) 

#define IVideoProcAmp_getRange_PowerlineFrequency(This,pMin,pMax,pSteppingDelta,pDefault,pCapsFlag)	\
    ( (This)->lpVtbl -> getRange_PowerlineFrequency(This,pMin,pMax,pSteppingDelta,pDefault,pCapsFlag) ) 

#define IVideoProcAmp_get_WhiteBalanceComponent(This,pValue1,pValue2,pFlags)	\
    ( (This)->lpVtbl -> get_WhiteBalanceComponent(This,pValue1,pValue2,pFlags) ) 

#define IVideoProcAmp_put_WhiteBalanceComponent(This,Value1,Value2,Flags)	\
    ( (This)->lpVtbl -> put_WhiteBalanceComponent(This,Value1,Value2,Flags) ) 

#define IVideoProcAmp_getRange_WhiteBalanceComponent(This,pMin,pMax,pSteppingDelta,pDefault,pCapsFlag)	\
    ( (This)->lpVtbl -> getRange_WhiteBalanceComponent(This,pMin,pMax,pSteppingDelta,pDefault,pCapsFlag) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IVideoProcAmp_INTERFACE_DEFINED__ */


#ifndef __IKsNodeControl_INTERFACE_DEFINED__
#define __IKsNodeControl_INTERFACE_DEFINED__

/* interface IKsNodeControl */
/* [unique][uuid][local][object] */ 


EXTERN_C const IID IID_IKsNodeControl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("11737C14-24A7-4bb5-81A0-0D003813B0C4")
    IKsNodeControl : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE put_NodeId( 
            /* [annotation][in] */ 
            _In_  DWORD dwNodeId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_KsControl( 
            /* [annotation][in] */ 
            _In_  PVOID pKsControl) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IKsNodeControlVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IKsNodeControl * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IKsNodeControl * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IKsNodeControl * This);
        
        DECLSPEC_XFGVIRT(IKsNodeControl, put_NodeId)
        HRESULT ( STDMETHODCALLTYPE *put_NodeId )( 
            IKsNodeControl * This,
            /* [annotation][in] */ 
            _In_  DWORD dwNodeId);
        
        DECLSPEC_XFGVIRT(IKsNodeControl, put_KsControl)
        HRESULT ( STDMETHODCALLTYPE *put_KsControl )( 
            IKsNodeControl * This,
            /* [annotation][in] */ 
            _In_  PVOID pKsControl);
        
        END_INTERFACE
    } IKsNodeControlVtbl;

    interface IKsNodeControl
    {
        CONST_VTBL struct IKsNodeControlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IKsNodeControl_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IKsNodeControl_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IKsNodeControl_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IKsNodeControl_put_NodeId(This,dwNodeId)	\
    ( (This)->lpVtbl -> put_NodeId(This,dwNodeId) ) 

#define IKsNodeControl_put_KsControl(This,pKsControl)	\
    ( (This)->lpVtbl -> put_KsControl(This,pKsControl) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IKsNodeControl_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vidcap_0000_0005 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_vidcap_0000_0005_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vidcap_0000_0005_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


