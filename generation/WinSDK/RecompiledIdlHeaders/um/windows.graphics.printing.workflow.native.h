

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

#ifndef __windows2Egraphics2Eprinting2Eworkflow2Enative_h__
#define __windows2Egraphics2Eprinting2Eworkflow2Enative_h__

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

#ifndef __IPrintWorkflowXpsReceiver_FWD_DEFINED__
#define __IPrintWorkflowXpsReceiver_FWD_DEFINED__
typedef interface IPrintWorkflowXpsReceiver IPrintWorkflowXpsReceiver;

#endif 	/* __IPrintWorkflowXpsReceiver_FWD_DEFINED__ */


#ifndef __IPrintWorkflowXpsReceiver2_FWD_DEFINED__
#define __IPrintWorkflowXpsReceiver2_FWD_DEFINED__
typedef interface IPrintWorkflowXpsReceiver2 IPrintWorkflowXpsReceiver2;

#endif 	/* __IPrintWorkflowXpsReceiver2_FWD_DEFINED__ */


#ifndef __IPrintWorkflowObjectModelSourceFileContentNative_FWD_DEFINED__
#define __IPrintWorkflowObjectModelSourceFileContentNative_FWD_DEFINED__
typedef interface IPrintWorkflowObjectModelSourceFileContentNative IPrintWorkflowObjectModelSourceFileContentNative;

#endif 	/* __IPrintWorkflowObjectModelSourceFileContentNative_FWD_DEFINED__ */


#ifndef __IPrintWorkflowXpsObjectModelTargetPackageNative_FWD_DEFINED__
#define __IPrintWorkflowXpsObjectModelTargetPackageNative_FWD_DEFINED__
typedef interface IPrintWorkflowXpsObjectModelTargetPackageNative IPrintWorkflowXpsObjectModelTargetPackageNative;

#endif 	/* __IPrintWorkflowXpsObjectModelTargetPackageNative_FWD_DEFINED__ */


#ifndef __IPrintWorkflowConfigurationNative_FWD_DEFINED__
#define __IPrintWorkflowConfigurationNative_FWD_DEFINED__
typedef interface IPrintWorkflowConfigurationNative IPrintWorkflowConfigurationNative;

#endif 	/* __IPrintWorkflowConfigurationNative_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "PrinterExtension.h"
#include "xpsobjectmodel_1.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_windows2Egraphics2Eprinting2Eworkflow2Enative_0000_0000 */
/* [local] */ 

//+-------------------------------------------------------------------------
//
//  Microsoft Windows
//  Copyright (c) Microsoft Corporation. All rights reserved.
//
//--------------------------------------------------------------------------
#pragma warning(push)
#pragma warning(disable:4668) 
#pragma warning(disable:4001) 
#pragma once
#pragma warning(pop)


extern RPC_IF_HANDLE __MIDL_itf_windows2Egraphics2Eprinting2Eworkflow2Enative_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_windows2Egraphics2Eprinting2Eworkflow2Enative_0000_0000_v0_0_s_ifspec;

#ifndef __IPrintWorkflowXpsReceiver_INTERFACE_DEFINED__
#define __IPrintWorkflowXpsReceiver_INTERFACE_DEFINED__

/* interface IPrintWorkflowXpsReceiver */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IPrintWorkflowXpsReceiver;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("04097374-77B8-47F6-8167-AAE29D4CF84B")
    IPrintWorkflowXpsReceiver : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetDocumentSequencePrintTicket( 
            /* [annotation][in] */ 
            _In_  IStream *documentSequencePrintTicket) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDocumentSequenceUri( 
            /* [annotation][in] */ 
            _In_  PCWSTR documentSequenceUri) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddDocumentData( 
            /* [annotation][in] */ 
            _In_  UINT32 documentId,
            /* [annotation][in] */ 
            _In_  IStream *documentPrintTicket,
            /* [annotation][in] */ 
            _In_  PCWSTR documentUri) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddPage( 
            /* [annotation][in] */ 
            _In_  UINT32 documentId,
            /* [annotation][in] */ 
            _In_  UINT32 pageId,
            /* [annotation][in] */ 
            _In_  IXpsOMPageReference *pageReference,
            /* [annotation][in] */ 
            _In_  PCWSTR pageUri) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Close( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IPrintWorkflowXpsReceiverVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IPrintWorkflowXpsReceiver * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IPrintWorkflowXpsReceiver * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IPrintWorkflowXpsReceiver * This);
        
        DECLSPEC_XFGVIRT(IPrintWorkflowXpsReceiver, SetDocumentSequencePrintTicket)
        HRESULT ( STDMETHODCALLTYPE *SetDocumentSequencePrintTicket )( 
            __RPC__in IPrintWorkflowXpsReceiver * This,
            /* [annotation][in] */ 
            _In_  IStream *documentSequencePrintTicket);
        
        DECLSPEC_XFGVIRT(IPrintWorkflowXpsReceiver, SetDocumentSequenceUri)
        HRESULT ( STDMETHODCALLTYPE *SetDocumentSequenceUri )( 
            __RPC__in IPrintWorkflowXpsReceiver * This,
            /* [annotation][in] */ 
            _In_  PCWSTR documentSequenceUri);
        
        DECLSPEC_XFGVIRT(IPrintWorkflowXpsReceiver, AddDocumentData)
        HRESULT ( STDMETHODCALLTYPE *AddDocumentData )( 
            __RPC__in IPrintWorkflowXpsReceiver * This,
            /* [annotation][in] */ 
            _In_  UINT32 documentId,
            /* [annotation][in] */ 
            _In_  IStream *documentPrintTicket,
            /* [annotation][in] */ 
            _In_  PCWSTR documentUri);
        
        DECLSPEC_XFGVIRT(IPrintWorkflowXpsReceiver, AddPage)
        HRESULT ( STDMETHODCALLTYPE *AddPage )( 
            __RPC__in IPrintWorkflowXpsReceiver * This,
            /* [annotation][in] */ 
            _In_  UINT32 documentId,
            /* [annotation][in] */ 
            _In_  UINT32 pageId,
            /* [annotation][in] */ 
            _In_  IXpsOMPageReference *pageReference,
            /* [annotation][in] */ 
            _In_  PCWSTR pageUri);
        
        DECLSPEC_XFGVIRT(IPrintWorkflowXpsReceiver, Close)
        HRESULT ( STDMETHODCALLTYPE *Close )( 
            __RPC__in IPrintWorkflowXpsReceiver * This);
        
        END_INTERFACE
    } IPrintWorkflowXpsReceiverVtbl;

    interface IPrintWorkflowXpsReceiver
    {
        CONST_VTBL struct IPrintWorkflowXpsReceiverVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPrintWorkflowXpsReceiver_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPrintWorkflowXpsReceiver_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPrintWorkflowXpsReceiver_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPrintWorkflowXpsReceiver_SetDocumentSequencePrintTicket(This,documentSequencePrintTicket)	\
    ( (This)->lpVtbl -> SetDocumentSequencePrintTicket(This,documentSequencePrintTicket) ) 

#define IPrintWorkflowXpsReceiver_SetDocumentSequenceUri(This,documentSequenceUri)	\
    ( (This)->lpVtbl -> SetDocumentSequenceUri(This,documentSequenceUri) ) 

#define IPrintWorkflowXpsReceiver_AddDocumentData(This,documentId,documentPrintTicket,documentUri)	\
    ( (This)->lpVtbl -> AddDocumentData(This,documentId,documentPrintTicket,documentUri) ) 

#define IPrintWorkflowXpsReceiver_AddPage(This,documentId,pageId,pageReference,pageUri)	\
    ( (This)->lpVtbl -> AddPage(This,documentId,pageId,pageReference,pageUri) ) 

#define IPrintWorkflowXpsReceiver_Close(This)	\
    ( (This)->lpVtbl -> Close(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPrintWorkflowXpsReceiver_INTERFACE_DEFINED__ */


#ifndef __IPrintWorkflowXpsReceiver2_INTERFACE_DEFINED__
#define __IPrintWorkflowXpsReceiver2_INTERFACE_DEFINED__

/* interface IPrintWorkflowXpsReceiver2 */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IPrintWorkflowXpsReceiver2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("023BCC0C-DFAB-4A61-B074-490C6995580D")
    IPrintWorkflowXpsReceiver2 : public IPrintWorkflowXpsReceiver
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Failed( 
            /* [annotation][in] */ 
            _In_  HRESULT XpsError) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IPrintWorkflowXpsReceiver2Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IPrintWorkflowXpsReceiver2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IPrintWorkflowXpsReceiver2 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IPrintWorkflowXpsReceiver2 * This);
        
        DECLSPEC_XFGVIRT(IPrintWorkflowXpsReceiver, SetDocumentSequencePrintTicket)
        HRESULT ( STDMETHODCALLTYPE *SetDocumentSequencePrintTicket )( 
            __RPC__in IPrintWorkflowXpsReceiver2 * This,
            /* [annotation][in] */ 
            _In_  IStream *documentSequencePrintTicket);
        
        DECLSPEC_XFGVIRT(IPrintWorkflowXpsReceiver, SetDocumentSequenceUri)
        HRESULT ( STDMETHODCALLTYPE *SetDocumentSequenceUri )( 
            __RPC__in IPrintWorkflowXpsReceiver2 * This,
            /* [annotation][in] */ 
            _In_  PCWSTR documentSequenceUri);
        
        DECLSPEC_XFGVIRT(IPrintWorkflowXpsReceiver, AddDocumentData)
        HRESULT ( STDMETHODCALLTYPE *AddDocumentData )( 
            __RPC__in IPrintWorkflowXpsReceiver2 * This,
            /* [annotation][in] */ 
            _In_  UINT32 documentId,
            /* [annotation][in] */ 
            _In_  IStream *documentPrintTicket,
            /* [annotation][in] */ 
            _In_  PCWSTR documentUri);
        
        DECLSPEC_XFGVIRT(IPrintWorkflowXpsReceiver, AddPage)
        HRESULT ( STDMETHODCALLTYPE *AddPage )( 
            __RPC__in IPrintWorkflowXpsReceiver2 * This,
            /* [annotation][in] */ 
            _In_  UINT32 documentId,
            /* [annotation][in] */ 
            _In_  UINT32 pageId,
            /* [annotation][in] */ 
            _In_  IXpsOMPageReference *pageReference,
            /* [annotation][in] */ 
            _In_  PCWSTR pageUri);
        
        DECLSPEC_XFGVIRT(IPrintWorkflowXpsReceiver, Close)
        HRESULT ( STDMETHODCALLTYPE *Close )( 
            __RPC__in IPrintWorkflowXpsReceiver2 * This);
        
        DECLSPEC_XFGVIRT(IPrintWorkflowXpsReceiver2, Failed)
        HRESULT ( STDMETHODCALLTYPE *Failed )( 
            __RPC__in IPrintWorkflowXpsReceiver2 * This,
            /* [annotation][in] */ 
            _In_  HRESULT XpsError);
        
        END_INTERFACE
    } IPrintWorkflowXpsReceiver2Vtbl;

    interface IPrintWorkflowXpsReceiver2
    {
        CONST_VTBL struct IPrintWorkflowXpsReceiver2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPrintWorkflowXpsReceiver2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPrintWorkflowXpsReceiver2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPrintWorkflowXpsReceiver2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPrintWorkflowXpsReceiver2_SetDocumentSequencePrintTicket(This,documentSequencePrintTicket)	\
    ( (This)->lpVtbl -> SetDocumentSequencePrintTicket(This,documentSequencePrintTicket) ) 

#define IPrintWorkflowXpsReceiver2_SetDocumentSequenceUri(This,documentSequenceUri)	\
    ( (This)->lpVtbl -> SetDocumentSequenceUri(This,documentSequenceUri) ) 

#define IPrintWorkflowXpsReceiver2_AddDocumentData(This,documentId,documentPrintTicket,documentUri)	\
    ( (This)->lpVtbl -> AddDocumentData(This,documentId,documentPrintTicket,documentUri) ) 

#define IPrintWorkflowXpsReceiver2_AddPage(This,documentId,pageId,pageReference,pageUri)	\
    ( (This)->lpVtbl -> AddPage(This,documentId,pageId,pageReference,pageUri) ) 

#define IPrintWorkflowXpsReceiver2_Close(This)	\
    ( (This)->lpVtbl -> Close(This) ) 


#define IPrintWorkflowXpsReceiver2_Failed(This,XpsError)	\
    ( (This)->lpVtbl -> Failed(This,XpsError) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPrintWorkflowXpsReceiver2_INTERFACE_DEFINED__ */


#ifndef __IPrintWorkflowObjectModelSourceFileContentNative_INTERFACE_DEFINED__
#define __IPrintWorkflowObjectModelSourceFileContentNative_INTERFACE_DEFINED__

/* interface IPrintWorkflowObjectModelSourceFileContentNative */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IPrintWorkflowObjectModelSourceFileContentNative;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("68C9E477-993E-4052-8AC6-454EFF58DB9D")
    IPrintWorkflowObjectModelSourceFileContentNative : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE StartXpsOMGeneration( 
            /* [annotation][in] */ 
            _In_  IPrintWorkflowXpsReceiver *receiver) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_ObjectFactory( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IXpsOMObjectFactory1 **value) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IPrintWorkflowObjectModelSourceFileContentNativeVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IPrintWorkflowObjectModelSourceFileContentNative * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IPrintWorkflowObjectModelSourceFileContentNative * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IPrintWorkflowObjectModelSourceFileContentNative * This);
        
        DECLSPEC_XFGVIRT(IPrintWorkflowObjectModelSourceFileContentNative, StartXpsOMGeneration)
        HRESULT ( STDMETHODCALLTYPE *StartXpsOMGeneration )( 
            __RPC__in IPrintWorkflowObjectModelSourceFileContentNative * This,
            /* [annotation][in] */ 
            _In_  IPrintWorkflowXpsReceiver *receiver);
        
        DECLSPEC_XFGVIRT(IPrintWorkflowObjectModelSourceFileContentNative, get_ObjectFactory)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_ObjectFactory )( 
            __RPC__in IPrintWorkflowObjectModelSourceFileContentNative * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IXpsOMObjectFactory1 **value);
        
        END_INTERFACE
    } IPrintWorkflowObjectModelSourceFileContentNativeVtbl;

    interface IPrintWorkflowObjectModelSourceFileContentNative
    {
        CONST_VTBL struct IPrintWorkflowObjectModelSourceFileContentNativeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPrintWorkflowObjectModelSourceFileContentNative_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPrintWorkflowObjectModelSourceFileContentNative_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPrintWorkflowObjectModelSourceFileContentNative_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPrintWorkflowObjectModelSourceFileContentNative_StartXpsOMGeneration(This,receiver)	\
    ( (This)->lpVtbl -> StartXpsOMGeneration(This,receiver) ) 

#define IPrintWorkflowObjectModelSourceFileContentNative_get_ObjectFactory(This,value)	\
    ( (This)->lpVtbl -> get_ObjectFactory(This,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPrintWorkflowObjectModelSourceFileContentNative_INTERFACE_DEFINED__ */


#ifndef __IPrintWorkflowXpsObjectModelTargetPackageNative_INTERFACE_DEFINED__
#define __IPrintWorkflowXpsObjectModelTargetPackageNative_INTERFACE_DEFINED__

/* interface IPrintWorkflowXpsObjectModelTargetPackageNative */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IPrintWorkflowXpsObjectModelTargetPackageNative;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7D96BC74-9B54-4CA1-AD3A-979C3D44DDAC")
    IPrintWorkflowXpsObjectModelTargetPackageNative : public IUnknown
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_DocumentPackageTarget( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IXpsDocumentPackageTarget **value) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IPrintWorkflowXpsObjectModelTargetPackageNativeVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IPrintWorkflowXpsObjectModelTargetPackageNative * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IPrintWorkflowXpsObjectModelTargetPackageNative * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IPrintWorkflowXpsObjectModelTargetPackageNative * This);
        
        DECLSPEC_XFGVIRT(IPrintWorkflowXpsObjectModelTargetPackageNative, get_DocumentPackageTarget)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_DocumentPackageTarget )( 
            __RPC__in IPrintWorkflowXpsObjectModelTargetPackageNative * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IXpsDocumentPackageTarget **value);
        
        END_INTERFACE
    } IPrintWorkflowXpsObjectModelTargetPackageNativeVtbl;

    interface IPrintWorkflowXpsObjectModelTargetPackageNative
    {
        CONST_VTBL struct IPrintWorkflowXpsObjectModelTargetPackageNativeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPrintWorkflowXpsObjectModelTargetPackageNative_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPrintWorkflowXpsObjectModelTargetPackageNative_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPrintWorkflowXpsObjectModelTargetPackageNative_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPrintWorkflowXpsObjectModelTargetPackageNative_get_DocumentPackageTarget(This,value)	\
    ( (This)->lpVtbl -> get_DocumentPackageTarget(This,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPrintWorkflowXpsObjectModelTargetPackageNative_INTERFACE_DEFINED__ */


#ifndef __IPrintWorkflowConfigurationNative_INTERFACE_DEFINED__
#define __IPrintWorkflowConfigurationNative_INTERFACE_DEFINED__

/* interface IPrintWorkflowConfigurationNative */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IPrintWorkflowConfigurationNative;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C056BE0A-9EE2-450A-9823-964F0006F2BB")
    IPrintWorkflowConfigurationNative : public IUnknown
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_PrinterQueue( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IPrinterQueue **value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_DriverProperties( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IPrinterPropertyBag **value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_UserProperties( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IPrinterPropertyBag **value) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IPrintWorkflowConfigurationNativeVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IPrintWorkflowConfigurationNative * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IPrintWorkflowConfigurationNative * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IPrintWorkflowConfigurationNative * This);
        
        DECLSPEC_XFGVIRT(IPrintWorkflowConfigurationNative, get_PrinterQueue)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_PrinterQueue )( 
            __RPC__in IPrintWorkflowConfigurationNative * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IPrinterQueue **value);
        
        DECLSPEC_XFGVIRT(IPrintWorkflowConfigurationNative, get_DriverProperties)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_DriverProperties )( 
            __RPC__in IPrintWorkflowConfigurationNative * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IPrinterPropertyBag **value);
        
        DECLSPEC_XFGVIRT(IPrintWorkflowConfigurationNative, get_UserProperties)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_UserProperties )( 
            __RPC__in IPrintWorkflowConfigurationNative * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IPrinterPropertyBag **value);
        
        END_INTERFACE
    } IPrintWorkflowConfigurationNativeVtbl;

    interface IPrintWorkflowConfigurationNative
    {
        CONST_VTBL struct IPrintWorkflowConfigurationNativeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPrintWorkflowConfigurationNative_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPrintWorkflowConfigurationNative_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPrintWorkflowConfigurationNative_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPrintWorkflowConfigurationNative_get_PrinterQueue(This,value)	\
    ( (This)->lpVtbl -> get_PrinterQueue(This,value) ) 

#define IPrintWorkflowConfigurationNative_get_DriverProperties(This,value)	\
    ( (This)->lpVtbl -> get_DriverProperties(This,value) ) 

#define IPrintWorkflowConfigurationNative_get_UserProperties(This,value)	\
    ( (This)->lpVtbl -> get_UserProperties(This,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPrintWorkflowConfigurationNative_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


