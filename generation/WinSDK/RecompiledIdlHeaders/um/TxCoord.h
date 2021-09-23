

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

#ifndef __txcoord_h__
#define __txcoord_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ITransactionResourceAsync_FWD_DEFINED__
#define __ITransactionResourceAsync_FWD_DEFINED__
typedef interface ITransactionResourceAsync ITransactionResourceAsync;

#endif 	/* __ITransactionResourceAsync_FWD_DEFINED__ */


#ifndef __ITransactionLastResourceAsync_FWD_DEFINED__
#define __ITransactionLastResourceAsync_FWD_DEFINED__
typedef interface ITransactionLastResourceAsync ITransactionLastResourceAsync;

#endif 	/* __ITransactionLastResourceAsync_FWD_DEFINED__ */


#ifndef __ITransactionResource_FWD_DEFINED__
#define __ITransactionResource_FWD_DEFINED__
typedef interface ITransactionResource ITransactionResource;

#endif 	/* __ITransactionResource_FWD_DEFINED__ */


#ifndef __ITransactionEnlistmentAsync_FWD_DEFINED__
#define __ITransactionEnlistmentAsync_FWD_DEFINED__
typedef interface ITransactionEnlistmentAsync ITransactionEnlistmentAsync;

#endif 	/* __ITransactionEnlistmentAsync_FWD_DEFINED__ */


#ifndef __ITransactionLastEnlistmentAsync_FWD_DEFINED__
#define __ITransactionLastEnlistmentAsync_FWD_DEFINED__
typedef interface ITransactionLastEnlistmentAsync ITransactionLastEnlistmentAsync;

#endif 	/* __ITransactionLastEnlistmentAsync_FWD_DEFINED__ */


#ifndef __ITransactionExportFactory_FWD_DEFINED__
#define __ITransactionExportFactory_FWD_DEFINED__
typedef interface ITransactionExportFactory ITransactionExportFactory;

#endif 	/* __ITransactionExportFactory_FWD_DEFINED__ */


#ifndef __ITransactionImportWhereabouts_FWD_DEFINED__
#define __ITransactionImportWhereabouts_FWD_DEFINED__
typedef interface ITransactionImportWhereabouts ITransactionImportWhereabouts;

#endif 	/* __ITransactionImportWhereabouts_FWD_DEFINED__ */


#ifndef __ITransactionExport_FWD_DEFINED__
#define __ITransactionExport_FWD_DEFINED__
typedef interface ITransactionExport ITransactionExport;

#endif 	/* __ITransactionExport_FWD_DEFINED__ */


#ifndef __ITransactionImport_FWD_DEFINED__
#define __ITransactionImport_FWD_DEFINED__
typedef interface ITransactionImport ITransactionImport;

#endif 	/* __ITransactionImport_FWD_DEFINED__ */


#ifndef __ITipTransaction_FWD_DEFINED__
#define __ITipTransaction_FWD_DEFINED__
typedef interface ITipTransaction ITipTransaction;

#endif 	/* __ITipTransaction_FWD_DEFINED__ */


#ifndef __ITipHelper_FWD_DEFINED__
#define __ITipHelper_FWD_DEFINED__
typedef interface ITipHelper ITipHelper;

#endif 	/* __ITipHelper_FWD_DEFINED__ */


#ifndef __ITipPullSink_FWD_DEFINED__
#define __ITipPullSink_FWD_DEFINED__
typedef interface ITipPullSink ITipPullSink;

#endif 	/* __ITipPullSink_FWD_DEFINED__ */


#ifndef __IDtcNetworkAccessConfig_FWD_DEFINED__
#define __IDtcNetworkAccessConfig_FWD_DEFINED__
typedef interface IDtcNetworkAccessConfig IDtcNetworkAccessConfig;

#endif 	/* __IDtcNetworkAccessConfig_FWD_DEFINED__ */


#ifndef __IDtcNetworkAccessConfig2_FWD_DEFINED__
#define __IDtcNetworkAccessConfig2_FWD_DEFINED__
typedef interface IDtcNetworkAccessConfig2 IDtcNetworkAccessConfig2;

#endif 	/* __IDtcNetworkAccessConfig2_FWD_DEFINED__ */


#ifndef __IDtcNetworkAccessConfig3_FWD_DEFINED__
#define __IDtcNetworkAccessConfig3_FWD_DEFINED__
typedef interface IDtcNetworkAccessConfig3 IDtcNetworkAccessConfig3;

#endif 	/* __IDtcNetworkAccessConfig3_FWD_DEFINED__ */


/* header files for imported files */
#include "transact.h"
#include "objidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_txcoord_0000_0000 */
/* [local] */ 

#include <winapifamily.h>
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)















extern RPC_IF_HANDLE __MIDL_itf_txcoord_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_txcoord_0000_0000_v0_0_s_ifspec;

#ifndef __ITransactionResourceAsync_INTERFACE_DEFINED__
#define __ITransactionResourceAsync_INTERFACE_DEFINED__

/* interface ITransactionResourceAsync */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_ITransactionResourceAsync;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("69E971F0-23CE-11cf-AD60-00AA00A74CCD")
    ITransactionResourceAsync : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE PrepareRequest( 
            /* [annotation][in] */ 
            _In_  BOOL fRetaining,
            /* [annotation][in] */ 
            _In_  DWORD grfRM,
            /* [annotation][in] */ 
            _In_  BOOL fWantMoniker,
            /* [annotation][in] */ 
            _In_  BOOL fSinglePhase) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CommitRequest( 
            /* [annotation][in] */ 
            _In_  DWORD grfRM,
            /* [annotation][unique][in] */ 
            _In_  XACTUOW *pNewUOW) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AbortRequest( 
            /* [annotation][unique][in] */ 
            _In_  BOID *pboidReason,
            /* [annotation][in] */ 
            _In_  BOOL fRetaining,
            /* [annotation][unique][in] */ 
            _In_  XACTUOW *pNewUOW) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE TMDown( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITransactionResourceAsyncVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ITransactionResourceAsync * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ITransactionResourceAsync * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ITransactionResourceAsync * This);
        
        HRESULT ( STDMETHODCALLTYPE *PrepareRequest )( 
            __RPC__in ITransactionResourceAsync * This,
            /* [annotation][in] */ 
            _In_  BOOL fRetaining,
            /* [annotation][in] */ 
            _In_  DWORD grfRM,
            /* [annotation][in] */ 
            _In_  BOOL fWantMoniker,
            /* [annotation][in] */ 
            _In_  BOOL fSinglePhase);
        
        HRESULT ( STDMETHODCALLTYPE *CommitRequest )( 
            __RPC__in ITransactionResourceAsync * This,
            /* [annotation][in] */ 
            _In_  DWORD grfRM,
            /* [annotation][unique][in] */ 
            _In_  XACTUOW *pNewUOW);
        
        HRESULT ( STDMETHODCALLTYPE *AbortRequest )( 
            __RPC__in ITransactionResourceAsync * This,
            /* [annotation][unique][in] */ 
            _In_  BOID *pboidReason,
            /* [annotation][in] */ 
            _In_  BOOL fRetaining,
            /* [annotation][unique][in] */ 
            _In_  XACTUOW *pNewUOW);
        
        HRESULT ( STDMETHODCALLTYPE *TMDown )( 
            __RPC__in ITransactionResourceAsync * This);
        
        END_INTERFACE
    } ITransactionResourceAsyncVtbl;

    interface ITransactionResourceAsync
    {
        CONST_VTBL struct ITransactionResourceAsyncVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITransactionResourceAsync_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITransactionResourceAsync_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITransactionResourceAsync_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITransactionResourceAsync_PrepareRequest(This,fRetaining,grfRM,fWantMoniker,fSinglePhase)	\
    ( (This)->lpVtbl -> PrepareRequest(This,fRetaining,grfRM,fWantMoniker,fSinglePhase) ) 

#define ITransactionResourceAsync_CommitRequest(This,grfRM,pNewUOW)	\
    ( (This)->lpVtbl -> CommitRequest(This,grfRM,pNewUOW) ) 

#define ITransactionResourceAsync_AbortRequest(This,pboidReason,fRetaining,pNewUOW)	\
    ( (This)->lpVtbl -> AbortRequest(This,pboidReason,fRetaining,pNewUOW) ) 

#define ITransactionResourceAsync_TMDown(This)	\
    ( (This)->lpVtbl -> TMDown(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITransactionResourceAsync_INTERFACE_DEFINED__ */


#ifndef __ITransactionLastResourceAsync_INTERFACE_DEFINED__
#define __ITransactionLastResourceAsync_INTERFACE_DEFINED__

/* interface ITransactionLastResourceAsync */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_ITransactionLastResourceAsync;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C82BD532-5B30-11d3-8A91-00C04F79EB6D")
    ITransactionLastResourceAsync : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE DelegateCommit( 
            /* [annotation][in] */ 
            _In_  DWORD grfRM) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ForgetRequest( 
            /* [annotation][in] */ 
            _In_  XACTUOW *pNewUOW) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITransactionLastResourceAsyncVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ITransactionLastResourceAsync * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ITransactionLastResourceAsync * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ITransactionLastResourceAsync * This);
        
        HRESULT ( STDMETHODCALLTYPE *DelegateCommit )( 
            __RPC__in ITransactionLastResourceAsync * This,
            /* [annotation][in] */ 
            _In_  DWORD grfRM);
        
        HRESULT ( STDMETHODCALLTYPE *ForgetRequest )( 
            __RPC__in ITransactionLastResourceAsync * This,
            /* [annotation][in] */ 
            _In_  XACTUOW *pNewUOW);
        
        END_INTERFACE
    } ITransactionLastResourceAsyncVtbl;

    interface ITransactionLastResourceAsync
    {
        CONST_VTBL struct ITransactionLastResourceAsyncVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITransactionLastResourceAsync_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITransactionLastResourceAsync_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITransactionLastResourceAsync_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITransactionLastResourceAsync_DelegateCommit(This,grfRM)	\
    ( (This)->lpVtbl -> DelegateCommit(This,grfRM) ) 

#define ITransactionLastResourceAsync_ForgetRequest(This,pNewUOW)	\
    ( (This)->lpVtbl -> ForgetRequest(This,pNewUOW) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITransactionLastResourceAsync_INTERFACE_DEFINED__ */


#ifndef __ITransactionResource_INTERFACE_DEFINED__
#define __ITransactionResource_INTERFACE_DEFINED__

/* interface ITransactionResource */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_ITransactionResource;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("EE5FF7B3-4572-11d0-9452-00A0C905416E")
    ITransactionResource : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE PrepareRequest( 
            /* [annotation][in] */ 
            _In_  BOOL fRetaining,
            /* [annotation][in] */ 
            _In_  DWORD grfRM,
            /* [annotation][in] */ 
            _In_  BOOL fWantMoniker,
            /* [annotation][in] */ 
            _In_  BOOL fSinglePhase) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CommitRequest( 
            /* [annotation][in] */ 
            _In_  DWORD grfRM,
            /* [annotation][unique][in] */ 
            _In_  XACTUOW *pNewUOW) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AbortRequest( 
            /* [annotation][unique][in] */ 
            _In_  BOID *pboidReason,
            /* [annotation][in] */ 
            _In_  BOOL fRetaining,
            /* [annotation][unique][in] */ 
            _In_  XACTUOW *pNewUOW) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE TMDown( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITransactionResourceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ITransactionResource * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ITransactionResource * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ITransactionResource * This);
        
        HRESULT ( STDMETHODCALLTYPE *PrepareRequest )( 
            __RPC__in ITransactionResource * This,
            /* [annotation][in] */ 
            _In_  BOOL fRetaining,
            /* [annotation][in] */ 
            _In_  DWORD grfRM,
            /* [annotation][in] */ 
            _In_  BOOL fWantMoniker,
            /* [annotation][in] */ 
            _In_  BOOL fSinglePhase);
        
        HRESULT ( STDMETHODCALLTYPE *CommitRequest )( 
            __RPC__in ITransactionResource * This,
            /* [annotation][in] */ 
            _In_  DWORD grfRM,
            /* [annotation][unique][in] */ 
            _In_  XACTUOW *pNewUOW);
        
        HRESULT ( STDMETHODCALLTYPE *AbortRequest )( 
            __RPC__in ITransactionResource * This,
            /* [annotation][unique][in] */ 
            _In_  BOID *pboidReason,
            /* [annotation][in] */ 
            _In_  BOOL fRetaining,
            /* [annotation][unique][in] */ 
            _In_  XACTUOW *pNewUOW);
        
        HRESULT ( STDMETHODCALLTYPE *TMDown )( 
            __RPC__in ITransactionResource * This);
        
        END_INTERFACE
    } ITransactionResourceVtbl;

    interface ITransactionResource
    {
        CONST_VTBL struct ITransactionResourceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITransactionResource_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITransactionResource_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITransactionResource_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITransactionResource_PrepareRequest(This,fRetaining,grfRM,fWantMoniker,fSinglePhase)	\
    ( (This)->lpVtbl -> PrepareRequest(This,fRetaining,grfRM,fWantMoniker,fSinglePhase) ) 

#define ITransactionResource_CommitRequest(This,grfRM,pNewUOW)	\
    ( (This)->lpVtbl -> CommitRequest(This,grfRM,pNewUOW) ) 

#define ITransactionResource_AbortRequest(This,pboidReason,fRetaining,pNewUOW)	\
    ( (This)->lpVtbl -> AbortRequest(This,pboidReason,fRetaining,pNewUOW) ) 

#define ITransactionResource_TMDown(This)	\
    ( (This)->lpVtbl -> TMDown(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITransactionResource_INTERFACE_DEFINED__ */


#ifndef __ITransactionEnlistmentAsync_INTERFACE_DEFINED__
#define __ITransactionEnlistmentAsync_INTERFACE_DEFINED__

/* interface ITransactionEnlistmentAsync */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_ITransactionEnlistmentAsync;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0fb15081-af41-11ce-bd2b-204c4f4f5020")
    ITransactionEnlistmentAsync : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE PrepareRequestDone( 
            /* [annotation][in] */ 
            _In_  HRESULT hr,
            /* [annotation][unique][in] */ 
            _In_  IMoniker *pmk,
            /* [annotation][unique][in] */ 
            _In_  BOID *pboidReason) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CommitRequestDone( 
            /* [annotation][in] */ 
            _In_  HRESULT hr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AbortRequestDone( 
            /* [annotation][in] */ 
            _In_  HRESULT hr) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITransactionEnlistmentAsyncVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ITransactionEnlistmentAsync * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ITransactionEnlistmentAsync * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ITransactionEnlistmentAsync * This);
        
        HRESULT ( STDMETHODCALLTYPE *PrepareRequestDone )( 
            __RPC__in ITransactionEnlistmentAsync * This,
            /* [annotation][in] */ 
            _In_  HRESULT hr,
            /* [annotation][unique][in] */ 
            _In_  IMoniker *pmk,
            /* [annotation][unique][in] */ 
            _In_  BOID *pboidReason);
        
        HRESULT ( STDMETHODCALLTYPE *CommitRequestDone )( 
            __RPC__in ITransactionEnlistmentAsync * This,
            /* [annotation][in] */ 
            _In_  HRESULT hr);
        
        HRESULT ( STDMETHODCALLTYPE *AbortRequestDone )( 
            __RPC__in ITransactionEnlistmentAsync * This,
            /* [annotation][in] */ 
            _In_  HRESULT hr);
        
        END_INTERFACE
    } ITransactionEnlistmentAsyncVtbl;

    interface ITransactionEnlistmentAsync
    {
        CONST_VTBL struct ITransactionEnlistmentAsyncVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITransactionEnlistmentAsync_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITransactionEnlistmentAsync_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITransactionEnlistmentAsync_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITransactionEnlistmentAsync_PrepareRequestDone(This,hr,pmk,pboidReason)	\
    ( (This)->lpVtbl -> PrepareRequestDone(This,hr,pmk,pboidReason) ) 

#define ITransactionEnlistmentAsync_CommitRequestDone(This,hr)	\
    ( (This)->lpVtbl -> CommitRequestDone(This,hr) ) 

#define ITransactionEnlistmentAsync_AbortRequestDone(This,hr)	\
    ( (This)->lpVtbl -> AbortRequestDone(This,hr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITransactionEnlistmentAsync_INTERFACE_DEFINED__ */


#ifndef __ITransactionLastEnlistmentAsync_INTERFACE_DEFINED__
#define __ITransactionLastEnlistmentAsync_INTERFACE_DEFINED__

/* interface ITransactionLastEnlistmentAsync */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_ITransactionLastEnlistmentAsync;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C82BD533-5B30-11d3-8A91-00C04F79EB6D")
    ITransactionLastEnlistmentAsync : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE TransactionOutcome( 
            /* [annotation][in] */ 
            _In_  XACTSTAT XactStat,
            /* [annotation][unique][in] */ 
            _In_  BOID *pboidReason) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITransactionLastEnlistmentAsyncVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ITransactionLastEnlistmentAsync * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ITransactionLastEnlistmentAsync * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ITransactionLastEnlistmentAsync * This);
        
        HRESULT ( STDMETHODCALLTYPE *TransactionOutcome )( 
            __RPC__in ITransactionLastEnlistmentAsync * This,
            /* [annotation][in] */ 
            _In_  XACTSTAT XactStat,
            /* [annotation][unique][in] */ 
            _In_  BOID *pboidReason);
        
        END_INTERFACE
    } ITransactionLastEnlistmentAsyncVtbl;

    interface ITransactionLastEnlistmentAsync
    {
        CONST_VTBL struct ITransactionLastEnlistmentAsyncVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITransactionLastEnlistmentAsync_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITransactionLastEnlistmentAsync_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITransactionLastEnlistmentAsync_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITransactionLastEnlistmentAsync_TransactionOutcome(This,XactStat,pboidReason)	\
    ( (This)->lpVtbl -> TransactionOutcome(This,XactStat,pboidReason) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITransactionLastEnlistmentAsync_INTERFACE_DEFINED__ */


#ifndef __ITransactionExportFactory_INTERFACE_DEFINED__
#define __ITransactionExportFactory_INTERFACE_DEFINED__

/* interface ITransactionExportFactory */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_ITransactionExportFactory;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E1CF9B53-8745-11ce-A9BA-00AA006C3706")
    ITransactionExportFactory : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetRemoteClassId( 
            /* [annotation][out] */ 
            _Out_  CLSID *pclsid) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Create( 
            /* [annotation][in] */ 
            _In_  ULONG cbWhereabouts,
            /* [annotation][size_is][in] */ 
            _In_reads_(cbWhereabouts)  byte *rgbWhereabouts,
            /* [annotation][out] */ 
            _Out_  ITransactionExport **ppExport) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITransactionExportFactoryVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ITransactionExportFactory * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ITransactionExportFactory * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ITransactionExportFactory * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetRemoteClassId )( 
            __RPC__in ITransactionExportFactory * This,
            /* [annotation][out] */ 
            _Out_  CLSID *pclsid);
        
        HRESULT ( STDMETHODCALLTYPE *Create )( 
            __RPC__in ITransactionExportFactory * This,
            /* [annotation][in] */ 
            _In_  ULONG cbWhereabouts,
            /* [annotation][size_is][in] */ 
            _In_reads_(cbWhereabouts)  byte *rgbWhereabouts,
            /* [annotation][out] */ 
            _Out_  ITransactionExport **ppExport);
        
        END_INTERFACE
    } ITransactionExportFactoryVtbl;

    interface ITransactionExportFactory
    {
        CONST_VTBL struct ITransactionExportFactoryVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITransactionExportFactory_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITransactionExportFactory_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITransactionExportFactory_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITransactionExportFactory_GetRemoteClassId(This,pclsid)	\
    ( (This)->lpVtbl -> GetRemoteClassId(This,pclsid) ) 

#define ITransactionExportFactory_Create(This,cbWhereabouts,rgbWhereabouts,ppExport)	\
    ( (This)->lpVtbl -> Create(This,cbWhereabouts,rgbWhereabouts,ppExport) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITransactionExportFactory_INTERFACE_DEFINED__ */


#ifndef __ITransactionImportWhereabouts_INTERFACE_DEFINED__
#define __ITransactionImportWhereabouts_INTERFACE_DEFINED__

/* interface ITransactionImportWhereabouts */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_ITransactionImportWhereabouts;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0141fda4-8fc0-11ce-bd18-204c4f4f5020")
    ITransactionImportWhereabouts : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetWhereaboutsSize( 
            /* [annotation][out] */ 
            _Out_  ULONG *pcbWhereabouts) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE GetWhereabouts( 
            /* [annotation][in] */ 
            _In_  ULONG cbWhereabouts,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cbWhereabouts)  byte *rgbWhereabouts,
            /* [annotation][out] */ 
            _Out_  ULONG *pcbUsed) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITransactionImportWhereaboutsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ITransactionImportWhereabouts * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ITransactionImportWhereabouts * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ITransactionImportWhereabouts * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetWhereaboutsSize )( 
            __RPC__in ITransactionImportWhereabouts * This,
            /* [annotation][out] */ 
            _Out_  ULONG *pcbWhereabouts);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *GetWhereabouts )( 
            ITransactionImportWhereabouts * This,
            /* [annotation][in] */ 
            _In_  ULONG cbWhereabouts,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cbWhereabouts)  byte *rgbWhereabouts,
            /* [annotation][out] */ 
            _Out_  ULONG *pcbUsed);
        
        END_INTERFACE
    } ITransactionImportWhereaboutsVtbl;

    interface ITransactionImportWhereabouts
    {
        CONST_VTBL struct ITransactionImportWhereaboutsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITransactionImportWhereabouts_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITransactionImportWhereabouts_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITransactionImportWhereabouts_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITransactionImportWhereabouts_GetWhereaboutsSize(This,pcbWhereabouts)	\
    ( (This)->lpVtbl -> GetWhereaboutsSize(This,pcbWhereabouts) ) 

#define ITransactionImportWhereabouts_GetWhereabouts(This,cbWhereabouts,rgbWhereabouts,pcbUsed)	\
    ( (This)->lpVtbl -> GetWhereabouts(This,cbWhereabouts,rgbWhereabouts,pcbUsed) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT STDMETHODCALLTYPE ITransactionImportWhereabouts_RemoteGetWhereabouts_Proxy( 
    __RPC__in ITransactionImportWhereabouts * This,
    /* [annotation][out] */ 
    _Out_  ULONG *pcbUsed,
    /* [annotation][in] */ 
    _In_  ULONG cbWhereabouts,
    /* [annotation][length_is][size_is][out] */ 
    _Out_writes_to_(cbWhereabouts,*pcbUsed)  byte *rgbWhereabouts);


void __RPC_STUB ITransactionImportWhereabouts_RemoteGetWhereabouts_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITransactionImportWhereabouts_INTERFACE_DEFINED__ */


#ifndef __ITransactionExport_INTERFACE_DEFINED__
#define __ITransactionExport_INTERFACE_DEFINED__

/* interface ITransactionExport */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_ITransactionExport;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0141fda5-8fc0-11ce-bd18-204c4f4f5020")
    ITransactionExport : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Export( 
            /* [annotation][in] */ 
            _In_  IUnknown *punkTransaction,
            /* [annotation][out] */ 
            _Out_  ULONG *pcbTransactionCookie) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE GetTransactionCookie( 
            /* [annotation][in] */ 
            _In_  IUnknown *punkTransaction,
            /* [annotation][in] */ 
            _In_  ULONG cbTransactionCookie,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cbTransactionCookie)  byte *rgbTransactionCookie,
            /* [annotation][out] */ 
            _Out_  ULONG *pcbUsed) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITransactionExportVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ITransactionExport * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ITransactionExport * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ITransactionExport * This);
        
        HRESULT ( STDMETHODCALLTYPE *Export )( 
            __RPC__in ITransactionExport * This,
            /* [annotation][in] */ 
            _In_  IUnknown *punkTransaction,
            /* [annotation][out] */ 
            _Out_  ULONG *pcbTransactionCookie);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *GetTransactionCookie )( 
            ITransactionExport * This,
            /* [annotation][in] */ 
            _In_  IUnknown *punkTransaction,
            /* [annotation][in] */ 
            _In_  ULONG cbTransactionCookie,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cbTransactionCookie)  byte *rgbTransactionCookie,
            /* [annotation][out] */ 
            _Out_  ULONG *pcbUsed);
        
        END_INTERFACE
    } ITransactionExportVtbl;

    interface ITransactionExport
    {
        CONST_VTBL struct ITransactionExportVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITransactionExport_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITransactionExport_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITransactionExport_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITransactionExport_Export(This,punkTransaction,pcbTransactionCookie)	\
    ( (This)->lpVtbl -> Export(This,punkTransaction,pcbTransactionCookie) ) 

#define ITransactionExport_GetTransactionCookie(This,punkTransaction,cbTransactionCookie,rgbTransactionCookie,pcbUsed)	\
    ( (This)->lpVtbl -> GetTransactionCookie(This,punkTransaction,cbTransactionCookie,rgbTransactionCookie,pcbUsed) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT STDMETHODCALLTYPE ITransactionExport_RemoteGetTransactionCookie_Proxy( 
    __RPC__in ITransactionExport * This,
    /* [annotation][in] */ 
    _In_  IUnknown *punkTransaction,
    /* [annotation][out] */ 
    _Out_  ULONG *pcbUsed,
    /* [annotation][in] */ 
    _In_  ULONG cbTransactionCookie,
    /* [annotation][length_is][size_is][out] */ 
    _Out_writes_to_(cbTransactionCookie,*pcbUsed)  byte *rgbTransactionCookie);


void __RPC_STUB ITransactionExport_RemoteGetTransactionCookie_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITransactionExport_INTERFACE_DEFINED__ */


#ifndef __ITransactionImport_INTERFACE_DEFINED__
#define __ITransactionImport_INTERFACE_DEFINED__

/* interface ITransactionImport */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_ITransactionImport;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E1CF9B5A-8745-11ce-A9BA-00AA006C3706")
    ITransactionImport : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Import( 
            /* [annotation][in] */ 
            _In_  ULONG cbTransactionCookie,
            /* [annotation][size_is][in] */ 
            _In_reads_(cbTransactionCookie)  byte *rgbTransactionCookie,
            /* [annotation][in] */ 
            _In_  IID *piid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvTransaction) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITransactionImportVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ITransactionImport * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ITransactionImport * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ITransactionImport * This);
        
        HRESULT ( STDMETHODCALLTYPE *Import )( 
            __RPC__in ITransactionImport * This,
            /* [annotation][in] */ 
            _In_  ULONG cbTransactionCookie,
            /* [annotation][size_is][in] */ 
            _In_reads_(cbTransactionCookie)  byte *rgbTransactionCookie,
            /* [annotation][in] */ 
            _In_  IID *piid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvTransaction);
        
        END_INTERFACE
    } ITransactionImportVtbl;

    interface ITransactionImport
    {
        CONST_VTBL struct ITransactionImportVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITransactionImport_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITransactionImport_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITransactionImport_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITransactionImport_Import(This,cbTransactionCookie,rgbTransactionCookie,piid,ppvTransaction)	\
    ( (This)->lpVtbl -> Import(This,cbTransactionCookie,rgbTransactionCookie,piid,ppvTransaction) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITransactionImport_INTERFACE_DEFINED__ */


#ifndef __ITipTransaction_INTERFACE_DEFINED__
#define __ITipTransaction_INTERFACE_DEFINED__

/* interface ITipTransaction */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_ITipTransaction;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("17CF72D0-BAC5-11d1-B1BF-00C04FC2F3EF")
    ITipTransaction : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Push( 
            /* [annotation][in] */ 
            _In_  unsigned char *i_pszRemoteTmUrl,
            /* [annotation][out] */ 
            _Out_  LPSTR *o_ppszRemoteTxUrl) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTransactionUrl( 
            /* [annotation][out] */ 
            _Out_  LPSTR *o_ppszLocalTxUrl) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITipTransactionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ITipTransaction * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ITipTransaction * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ITipTransaction * This);
        
        HRESULT ( STDMETHODCALLTYPE *Push )( 
            __RPC__in ITipTransaction * This,
            /* [annotation][in] */ 
            _In_  unsigned char *i_pszRemoteTmUrl,
            /* [annotation][out] */ 
            _Out_  LPSTR *o_ppszRemoteTxUrl);
        
        HRESULT ( STDMETHODCALLTYPE *GetTransactionUrl )( 
            __RPC__in ITipTransaction * This,
            /* [annotation][out] */ 
            _Out_  LPSTR *o_ppszLocalTxUrl);
        
        END_INTERFACE
    } ITipTransactionVtbl;

    interface ITipTransaction
    {
        CONST_VTBL struct ITipTransactionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITipTransaction_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITipTransaction_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITipTransaction_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITipTransaction_Push(This,i_pszRemoteTmUrl,o_ppszRemoteTxUrl)	\
    ( (This)->lpVtbl -> Push(This,i_pszRemoteTmUrl,o_ppszRemoteTxUrl) ) 

#define ITipTransaction_GetTransactionUrl(This,o_ppszLocalTxUrl)	\
    ( (This)->lpVtbl -> GetTransactionUrl(This,o_ppszLocalTxUrl) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITipTransaction_INTERFACE_DEFINED__ */


#ifndef __ITipHelper_INTERFACE_DEFINED__
#define __ITipHelper_INTERFACE_DEFINED__

/* interface ITipHelper */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_ITipHelper;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("17CF72D1-BAC5-11d1-B1BF-00C04FC2F3EF")
    ITipHelper : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Pull( 
            /* [annotation][in] */ 
            _In_  unsigned char *i_pszTxUrl,
            /* [annotation][out] */ 
            _Out_  ITransaction **o_ppITransaction) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PullAsync( 
            /* [annotation][in] */ 
            _In_  unsigned char *i_pszTxUrl,
            /* [annotation][in] */ 
            _In_  ITipPullSink *i_pTipPullSink,
            /* [annotation][out] */ 
            _Out_  ITransaction **o_ppITransaction) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLocalTmUrl( 
            /* [annotation][out] */ 
            _Out_  unsigned char **o_ppszLocalTmUrl) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITipHelperVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ITipHelper * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ITipHelper * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ITipHelper * This);
        
        HRESULT ( STDMETHODCALLTYPE *Pull )( 
            __RPC__in ITipHelper * This,
            /* [annotation][in] */ 
            _In_  unsigned char *i_pszTxUrl,
            /* [annotation][out] */ 
            _Out_  ITransaction **o_ppITransaction);
        
        HRESULT ( STDMETHODCALLTYPE *PullAsync )( 
            __RPC__in ITipHelper * This,
            /* [annotation][in] */ 
            _In_  unsigned char *i_pszTxUrl,
            /* [annotation][in] */ 
            _In_  ITipPullSink *i_pTipPullSink,
            /* [annotation][out] */ 
            _Out_  ITransaction **o_ppITransaction);
        
        HRESULT ( STDMETHODCALLTYPE *GetLocalTmUrl )( 
            __RPC__in ITipHelper * This,
            /* [annotation][out] */ 
            _Out_  unsigned char **o_ppszLocalTmUrl);
        
        END_INTERFACE
    } ITipHelperVtbl;

    interface ITipHelper
    {
        CONST_VTBL struct ITipHelperVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITipHelper_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITipHelper_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITipHelper_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITipHelper_Pull(This,i_pszTxUrl,o_ppITransaction)	\
    ( (This)->lpVtbl -> Pull(This,i_pszTxUrl,o_ppITransaction) ) 

#define ITipHelper_PullAsync(This,i_pszTxUrl,i_pTipPullSink,o_ppITransaction)	\
    ( (This)->lpVtbl -> PullAsync(This,i_pszTxUrl,i_pTipPullSink,o_ppITransaction) ) 

#define ITipHelper_GetLocalTmUrl(This,o_ppszLocalTmUrl)	\
    ( (This)->lpVtbl -> GetLocalTmUrl(This,o_ppszLocalTmUrl) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITipHelper_INTERFACE_DEFINED__ */


#ifndef __ITipPullSink_INTERFACE_DEFINED__
#define __ITipPullSink_INTERFACE_DEFINED__

/* interface ITipPullSink */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_ITipPullSink;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("17CF72D2-BAC5-11d1-B1BF-00C04FC2F3EF")
    ITipPullSink : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE PullComplete( 
            /* [annotation][in] */ 
            _In_  HRESULT i_hrPull) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITipPullSinkVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ITipPullSink * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ITipPullSink * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ITipPullSink * This);
        
        HRESULT ( STDMETHODCALLTYPE *PullComplete )( 
            __RPC__in ITipPullSink * This,
            /* [annotation][in] */ 
            _In_  HRESULT i_hrPull);
        
        END_INTERFACE
    } ITipPullSinkVtbl;

    interface ITipPullSink
    {
        CONST_VTBL struct ITipPullSinkVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITipPullSink_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITipPullSink_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITipPullSink_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITipPullSink_PullComplete(This,i_hrPull)	\
    ( (This)->lpVtbl -> PullComplete(This,i_hrPull) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITipPullSink_INTERFACE_DEFINED__ */


#ifndef __IDtcNetworkAccessConfig_INTERFACE_DEFINED__
#define __IDtcNetworkAccessConfig_INTERFACE_DEFINED__

/* interface IDtcNetworkAccessConfig */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IDtcNetworkAccessConfig;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9797C15D-A428-4291-87B6-0995031A678D")
    IDtcNetworkAccessConfig : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetAnyNetworkAccess( 
            /* [annotation][out] */ 
            _Out_  BOOL *pbAnyNetworkAccess) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAnyNetworkAccess( 
            /* [annotation][in] */ 
            _In_  BOOL bAnyNetworkAccess) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNetworkAdministrationAccess( 
            /* [annotation][out] */ 
            _Out_  BOOL *pbNetworkAdministrationAccess) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetNetworkAdministrationAccess( 
            /* [annotation][in] */ 
            _In_  BOOL bNetworkAdministrationAccess) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNetworkTransactionAccess( 
            /* [annotation][out] */ 
            _Out_  BOOL *pbNetworkTransactionAccess) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetNetworkTransactionAccess( 
            /* [annotation][in] */ 
            _In_  BOOL bNetworkTransactionAccess) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNetworkClientAccess( 
            /* [annotation][out] */ 
            _Out_  BOOL *pbNetworkClientAccess) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetNetworkClientAccess( 
            /* [annotation][in] */ 
            _In_  BOOL bNetworkClientAccess) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNetworkTIPAccess( 
            /* [annotation][out] */ 
            _Out_  BOOL *pbNetworkTIPAccess) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetNetworkTIPAccess( 
            /* [annotation][in] */ 
            _In_  BOOL bNetworkTIPAccess) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetXAAccess( 
            /* [annotation][out] */ 
            _Out_  BOOL *pbXAAccess) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetXAAccess( 
            /* [annotation][in] */ 
            _In_  BOOL bXAAccess) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RestartDtcService( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IDtcNetworkAccessConfigVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IDtcNetworkAccessConfig * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IDtcNetworkAccessConfig * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IDtcNetworkAccessConfig * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetAnyNetworkAccess )( 
            __RPC__in IDtcNetworkAccessConfig * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pbAnyNetworkAccess);
        
        HRESULT ( STDMETHODCALLTYPE *SetAnyNetworkAccess )( 
            __RPC__in IDtcNetworkAccessConfig * This,
            /* [annotation][in] */ 
            _In_  BOOL bAnyNetworkAccess);
        
        HRESULT ( STDMETHODCALLTYPE *GetNetworkAdministrationAccess )( 
            __RPC__in IDtcNetworkAccessConfig * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pbNetworkAdministrationAccess);
        
        HRESULT ( STDMETHODCALLTYPE *SetNetworkAdministrationAccess )( 
            __RPC__in IDtcNetworkAccessConfig * This,
            /* [annotation][in] */ 
            _In_  BOOL bNetworkAdministrationAccess);
        
        HRESULT ( STDMETHODCALLTYPE *GetNetworkTransactionAccess )( 
            __RPC__in IDtcNetworkAccessConfig * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pbNetworkTransactionAccess);
        
        HRESULT ( STDMETHODCALLTYPE *SetNetworkTransactionAccess )( 
            __RPC__in IDtcNetworkAccessConfig * This,
            /* [annotation][in] */ 
            _In_  BOOL bNetworkTransactionAccess);
        
        HRESULT ( STDMETHODCALLTYPE *GetNetworkClientAccess )( 
            __RPC__in IDtcNetworkAccessConfig * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pbNetworkClientAccess);
        
        HRESULT ( STDMETHODCALLTYPE *SetNetworkClientAccess )( 
            __RPC__in IDtcNetworkAccessConfig * This,
            /* [annotation][in] */ 
            _In_  BOOL bNetworkClientAccess);
        
        HRESULT ( STDMETHODCALLTYPE *GetNetworkTIPAccess )( 
            __RPC__in IDtcNetworkAccessConfig * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pbNetworkTIPAccess);
        
        HRESULT ( STDMETHODCALLTYPE *SetNetworkTIPAccess )( 
            __RPC__in IDtcNetworkAccessConfig * This,
            /* [annotation][in] */ 
            _In_  BOOL bNetworkTIPAccess);
        
        HRESULT ( STDMETHODCALLTYPE *GetXAAccess )( 
            __RPC__in IDtcNetworkAccessConfig * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pbXAAccess);
        
        HRESULT ( STDMETHODCALLTYPE *SetXAAccess )( 
            __RPC__in IDtcNetworkAccessConfig * This,
            /* [annotation][in] */ 
            _In_  BOOL bXAAccess);
        
        HRESULT ( STDMETHODCALLTYPE *RestartDtcService )( 
            __RPC__in IDtcNetworkAccessConfig * This);
        
        END_INTERFACE
    } IDtcNetworkAccessConfigVtbl;

    interface IDtcNetworkAccessConfig
    {
        CONST_VTBL struct IDtcNetworkAccessConfigVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDtcNetworkAccessConfig_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDtcNetworkAccessConfig_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDtcNetworkAccessConfig_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDtcNetworkAccessConfig_GetAnyNetworkAccess(This,pbAnyNetworkAccess)	\
    ( (This)->lpVtbl -> GetAnyNetworkAccess(This,pbAnyNetworkAccess) ) 

#define IDtcNetworkAccessConfig_SetAnyNetworkAccess(This,bAnyNetworkAccess)	\
    ( (This)->lpVtbl -> SetAnyNetworkAccess(This,bAnyNetworkAccess) ) 

#define IDtcNetworkAccessConfig_GetNetworkAdministrationAccess(This,pbNetworkAdministrationAccess)	\
    ( (This)->lpVtbl -> GetNetworkAdministrationAccess(This,pbNetworkAdministrationAccess) ) 

#define IDtcNetworkAccessConfig_SetNetworkAdministrationAccess(This,bNetworkAdministrationAccess)	\
    ( (This)->lpVtbl -> SetNetworkAdministrationAccess(This,bNetworkAdministrationAccess) ) 

#define IDtcNetworkAccessConfig_GetNetworkTransactionAccess(This,pbNetworkTransactionAccess)	\
    ( (This)->lpVtbl -> GetNetworkTransactionAccess(This,pbNetworkTransactionAccess) ) 

#define IDtcNetworkAccessConfig_SetNetworkTransactionAccess(This,bNetworkTransactionAccess)	\
    ( (This)->lpVtbl -> SetNetworkTransactionAccess(This,bNetworkTransactionAccess) ) 

#define IDtcNetworkAccessConfig_GetNetworkClientAccess(This,pbNetworkClientAccess)	\
    ( (This)->lpVtbl -> GetNetworkClientAccess(This,pbNetworkClientAccess) ) 

#define IDtcNetworkAccessConfig_SetNetworkClientAccess(This,bNetworkClientAccess)	\
    ( (This)->lpVtbl -> SetNetworkClientAccess(This,bNetworkClientAccess) ) 

#define IDtcNetworkAccessConfig_GetNetworkTIPAccess(This,pbNetworkTIPAccess)	\
    ( (This)->lpVtbl -> GetNetworkTIPAccess(This,pbNetworkTIPAccess) ) 

#define IDtcNetworkAccessConfig_SetNetworkTIPAccess(This,bNetworkTIPAccess)	\
    ( (This)->lpVtbl -> SetNetworkTIPAccess(This,bNetworkTIPAccess) ) 

#define IDtcNetworkAccessConfig_GetXAAccess(This,pbXAAccess)	\
    ( (This)->lpVtbl -> GetXAAccess(This,pbXAAccess) ) 

#define IDtcNetworkAccessConfig_SetXAAccess(This,bXAAccess)	\
    ( (This)->lpVtbl -> SetXAAccess(This,bXAAccess) ) 

#define IDtcNetworkAccessConfig_RestartDtcService(This)	\
    ( (This)->lpVtbl -> RestartDtcService(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDtcNetworkAccessConfig_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_txcoord_0000_0013 */
/* [local] */ 

typedef 
enum AUTHENTICATION_LEVEL
    {
        NO_AUTHENTICATION_REQUIRED	= 0,
        INCOMING_AUTHENTICATION_REQUIRED	= 1,
        MUTUAL_AUTHENTICATION_REQUIRED	= 2
    } 	AUTHENTICATION_LEVEL;



extern RPC_IF_HANDLE __MIDL_itf_txcoord_0000_0013_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_txcoord_0000_0013_v0_0_s_ifspec;

#ifndef __IDtcNetworkAccessConfig2_INTERFACE_DEFINED__
#define __IDtcNetworkAccessConfig2_INTERFACE_DEFINED__

/* interface IDtcNetworkAccessConfig2 */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IDtcNetworkAccessConfig2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A7AA013B-EB7D-4f42-B41C-B2DEC09AE034")
    IDtcNetworkAccessConfig2 : public IDtcNetworkAccessConfig
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetNetworkInboundAccess( 
            /* [annotation][out] */ 
            _Out_  BOOL *pbInbound) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNetworkOutboundAccess( 
            /* [annotation][out] */ 
            _Out_  BOOL *pbOutbound) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetNetworkInboundAccess( 
            /* [annotation][in] */ 
            _In_  BOOL bInbound) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetNetworkOutboundAccess( 
            /* [annotation][in] */ 
            _In_  BOOL bOutbound) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAuthenticationLevel( 
            /* [annotation][out] */ 
            _Out_  AUTHENTICATION_LEVEL *pAuthLevel) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAuthenticationLevel( 
            /* [annotation][in] */ 
            _In_  AUTHENTICATION_LEVEL AuthLevel) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IDtcNetworkAccessConfig2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IDtcNetworkAccessConfig2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IDtcNetworkAccessConfig2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IDtcNetworkAccessConfig2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetAnyNetworkAccess )( 
            __RPC__in IDtcNetworkAccessConfig2 * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pbAnyNetworkAccess);
        
        HRESULT ( STDMETHODCALLTYPE *SetAnyNetworkAccess )( 
            __RPC__in IDtcNetworkAccessConfig2 * This,
            /* [annotation][in] */ 
            _In_  BOOL bAnyNetworkAccess);
        
        HRESULT ( STDMETHODCALLTYPE *GetNetworkAdministrationAccess )( 
            __RPC__in IDtcNetworkAccessConfig2 * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pbNetworkAdministrationAccess);
        
        HRESULT ( STDMETHODCALLTYPE *SetNetworkAdministrationAccess )( 
            __RPC__in IDtcNetworkAccessConfig2 * This,
            /* [annotation][in] */ 
            _In_  BOOL bNetworkAdministrationAccess);
        
        HRESULT ( STDMETHODCALLTYPE *GetNetworkTransactionAccess )( 
            __RPC__in IDtcNetworkAccessConfig2 * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pbNetworkTransactionAccess);
        
        HRESULT ( STDMETHODCALLTYPE *SetNetworkTransactionAccess )( 
            __RPC__in IDtcNetworkAccessConfig2 * This,
            /* [annotation][in] */ 
            _In_  BOOL bNetworkTransactionAccess);
        
        HRESULT ( STDMETHODCALLTYPE *GetNetworkClientAccess )( 
            __RPC__in IDtcNetworkAccessConfig2 * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pbNetworkClientAccess);
        
        HRESULT ( STDMETHODCALLTYPE *SetNetworkClientAccess )( 
            __RPC__in IDtcNetworkAccessConfig2 * This,
            /* [annotation][in] */ 
            _In_  BOOL bNetworkClientAccess);
        
        HRESULT ( STDMETHODCALLTYPE *GetNetworkTIPAccess )( 
            __RPC__in IDtcNetworkAccessConfig2 * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pbNetworkTIPAccess);
        
        HRESULT ( STDMETHODCALLTYPE *SetNetworkTIPAccess )( 
            __RPC__in IDtcNetworkAccessConfig2 * This,
            /* [annotation][in] */ 
            _In_  BOOL bNetworkTIPAccess);
        
        HRESULT ( STDMETHODCALLTYPE *GetXAAccess )( 
            __RPC__in IDtcNetworkAccessConfig2 * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pbXAAccess);
        
        HRESULT ( STDMETHODCALLTYPE *SetXAAccess )( 
            __RPC__in IDtcNetworkAccessConfig2 * This,
            /* [annotation][in] */ 
            _In_  BOOL bXAAccess);
        
        HRESULT ( STDMETHODCALLTYPE *RestartDtcService )( 
            __RPC__in IDtcNetworkAccessConfig2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetNetworkInboundAccess )( 
            __RPC__in IDtcNetworkAccessConfig2 * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pbInbound);
        
        HRESULT ( STDMETHODCALLTYPE *GetNetworkOutboundAccess )( 
            __RPC__in IDtcNetworkAccessConfig2 * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pbOutbound);
        
        HRESULT ( STDMETHODCALLTYPE *SetNetworkInboundAccess )( 
            __RPC__in IDtcNetworkAccessConfig2 * This,
            /* [annotation][in] */ 
            _In_  BOOL bInbound);
        
        HRESULT ( STDMETHODCALLTYPE *SetNetworkOutboundAccess )( 
            __RPC__in IDtcNetworkAccessConfig2 * This,
            /* [annotation][in] */ 
            _In_  BOOL bOutbound);
        
        HRESULT ( STDMETHODCALLTYPE *GetAuthenticationLevel )( 
            __RPC__in IDtcNetworkAccessConfig2 * This,
            /* [annotation][out] */ 
            _Out_  AUTHENTICATION_LEVEL *pAuthLevel);
        
        HRESULT ( STDMETHODCALLTYPE *SetAuthenticationLevel )( 
            __RPC__in IDtcNetworkAccessConfig2 * This,
            /* [annotation][in] */ 
            _In_  AUTHENTICATION_LEVEL AuthLevel);
        
        END_INTERFACE
    } IDtcNetworkAccessConfig2Vtbl;

    interface IDtcNetworkAccessConfig2
    {
        CONST_VTBL struct IDtcNetworkAccessConfig2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDtcNetworkAccessConfig2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDtcNetworkAccessConfig2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDtcNetworkAccessConfig2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDtcNetworkAccessConfig2_GetAnyNetworkAccess(This,pbAnyNetworkAccess)	\
    ( (This)->lpVtbl -> GetAnyNetworkAccess(This,pbAnyNetworkAccess) ) 

#define IDtcNetworkAccessConfig2_SetAnyNetworkAccess(This,bAnyNetworkAccess)	\
    ( (This)->lpVtbl -> SetAnyNetworkAccess(This,bAnyNetworkAccess) ) 

#define IDtcNetworkAccessConfig2_GetNetworkAdministrationAccess(This,pbNetworkAdministrationAccess)	\
    ( (This)->lpVtbl -> GetNetworkAdministrationAccess(This,pbNetworkAdministrationAccess) ) 

#define IDtcNetworkAccessConfig2_SetNetworkAdministrationAccess(This,bNetworkAdministrationAccess)	\
    ( (This)->lpVtbl -> SetNetworkAdministrationAccess(This,bNetworkAdministrationAccess) ) 

#define IDtcNetworkAccessConfig2_GetNetworkTransactionAccess(This,pbNetworkTransactionAccess)	\
    ( (This)->lpVtbl -> GetNetworkTransactionAccess(This,pbNetworkTransactionAccess) ) 

#define IDtcNetworkAccessConfig2_SetNetworkTransactionAccess(This,bNetworkTransactionAccess)	\
    ( (This)->lpVtbl -> SetNetworkTransactionAccess(This,bNetworkTransactionAccess) ) 

#define IDtcNetworkAccessConfig2_GetNetworkClientAccess(This,pbNetworkClientAccess)	\
    ( (This)->lpVtbl -> GetNetworkClientAccess(This,pbNetworkClientAccess) ) 

#define IDtcNetworkAccessConfig2_SetNetworkClientAccess(This,bNetworkClientAccess)	\
    ( (This)->lpVtbl -> SetNetworkClientAccess(This,bNetworkClientAccess) ) 

#define IDtcNetworkAccessConfig2_GetNetworkTIPAccess(This,pbNetworkTIPAccess)	\
    ( (This)->lpVtbl -> GetNetworkTIPAccess(This,pbNetworkTIPAccess) ) 

#define IDtcNetworkAccessConfig2_SetNetworkTIPAccess(This,bNetworkTIPAccess)	\
    ( (This)->lpVtbl -> SetNetworkTIPAccess(This,bNetworkTIPAccess) ) 

#define IDtcNetworkAccessConfig2_GetXAAccess(This,pbXAAccess)	\
    ( (This)->lpVtbl -> GetXAAccess(This,pbXAAccess) ) 

#define IDtcNetworkAccessConfig2_SetXAAccess(This,bXAAccess)	\
    ( (This)->lpVtbl -> SetXAAccess(This,bXAAccess) ) 

#define IDtcNetworkAccessConfig2_RestartDtcService(This)	\
    ( (This)->lpVtbl -> RestartDtcService(This) ) 


#define IDtcNetworkAccessConfig2_GetNetworkInboundAccess(This,pbInbound)	\
    ( (This)->lpVtbl -> GetNetworkInboundAccess(This,pbInbound) ) 

#define IDtcNetworkAccessConfig2_GetNetworkOutboundAccess(This,pbOutbound)	\
    ( (This)->lpVtbl -> GetNetworkOutboundAccess(This,pbOutbound) ) 

#define IDtcNetworkAccessConfig2_SetNetworkInboundAccess(This,bInbound)	\
    ( (This)->lpVtbl -> SetNetworkInboundAccess(This,bInbound) ) 

#define IDtcNetworkAccessConfig2_SetNetworkOutboundAccess(This,bOutbound)	\
    ( (This)->lpVtbl -> SetNetworkOutboundAccess(This,bOutbound) ) 

#define IDtcNetworkAccessConfig2_GetAuthenticationLevel(This,pAuthLevel)	\
    ( (This)->lpVtbl -> GetAuthenticationLevel(This,pAuthLevel) ) 

#define IDtcNetworkAccessConfig2_SetAuthenticationLevel(This,AuthLevel)	\
    ( (This)->lpVtbl -> SetAuthenticationLevel(This,AuthLevel) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDtcNetworkAccessConfig2_INTERFACE_DEFINED__ */


#ifndef __IDtcNetworkAccessConfig3_INTERFACE_DEFINED__
#define __IDtcNetworkAccessConfig3_INTERFACE_DEFINED__

/* interface IDtcNetworkAccessConfig3 */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IDtcNetworkAccessConfig3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("76E4B4F3-2CA5-466b-89D5-FD218EE75B49")
    IDtcNetworkAccessConfig3 : public IDtcNetworkAccessConfig2
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetLUAccess( 
            /* [annotation][out] */ 
            _Out_  BOOL *pbLUAccess) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetLUAccess( 
            /* [annotation][in] */ 
            _In_  BOOL bLUAccess) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IDtcNetworkAccessConfig3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IDtcNetworkAccessConfig3 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IDtcNetworkAccessConfig3 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IDtcNetworkAccessConfig3 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetAnyNetworkAccess )( 
            __RPC__in IDtcNetworkAccessConfig3 * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pbAnyNetworkAccess);
        
        HRESULT ( STDMETHODCALLTYPE *SetAnyNetworkAccess )( 
            __RPC__in IDtcNetworkAccessConfig3 * This,
            /* [annotation][in] */ 
            _In_  BOOL bAnyNetworkAccess);
        
        HRESULT ( STDMETHODCALLTYPE *GetNetworkAdministrationAccess )( 
            __RPC__in IDtcNetworkAccessConfig3 * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pbNetworkAdministrationAccess);
        
        HRESULT ( STDMETHODCALLTYPE *SetNetworkAdministrationAccess )( 
            __RPC__in IDtcNetworkAccessConfig3 * This,
            /* [annotation][in] */ 
            _In_  BOOL bNetworkAdministrationAccess);
        
        HRESULT ( STDMETHODCALLTYPE *GetNetworkTransactionAccess )( 
            __RPC__in IDtcNetworkAccessConfig3 * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pbNetworkTransactionAccess);
        
        HRESULT ( STDMETHODCALLTYPE *SetNetworkTransactionAccess )( 
            __RPC__in IDtcNetworkAccessConfig3 * This,
            /* [annotation][in] */ 
            _In_  BOOL bNetworkTransactionAccess);
        
        HRESULT ( STDMETHODCALLTYPE *GetNetworkClientAccess )( 
            __RPC__in IDtcNetworkAccessConfig3 * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pbNetworkClientAccess);
        
        HRESULT ( STDMETHODCALLTYPE *SetNetworkClientAccess )( 
            __RPC__in IDtcNetworkAccessConfig3 * This,
            /* [annotation][in] */ 
            _In_  BOOL bNetworkClientAccess);
        
        HRESULT ( STDMETHODCALLTYPE *GetNetworkTIPAccess )( 
            __RPC__in IDtcNetworkAccessConfig3 * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pbNetworkTIPAccess);
        
        HRESULT ( STDMETHODCALLTYPE *SetNetworkTIPAccess )( 
            __RPC__in IDtcNetworkAccessConfig3 * This,
            /* [annotation][in] */ 
            _In_  BOOL bNetworkTIPAccess);
        
        HRESULT ( STDMETHODCALLTYPE *GetXAAccess )( 
            __RPC__in IDtcNetworkAccessConfig3 * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pbXAAccess);
        
        HRESULT ( STDMETHODCALLTYPE *SetXAAccess )( 
            __RPC__in IDtcNetworkAccessConfig3 * This,
            /* [annotation][in] */ 
            _In_  BOOL bXAAccess);
        
        HRESULT ( STDMETHODCALLTYPE *RestartDtcService )( 
            __RPC__in IDtcNetworkAccessConfig3 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetNetworkInboundAccess )( 
            __RPC__in IDtcNetworkAccessConfig3 * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pbInbound);
        
        HRESULT ( STDMETHODCALLTYPE *GetNetworkOutboundAccess )( 
            __RPC__in IDtcNetworkAccessConfig3 * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pbOutbound);
        
        HRESULT ( STDMETHODCALLTYPE *SetNetworkInboundAccess )( 
            __RPC__in IDtcNetworkAccessConfig3 * This,
            /* [annotation][in] */ 
            _In_  BOOL bInbound);
        
        HRESULT ( STDMETHODCALLTYPE *SetNetworkOutboundAccess )( 
            __RPC__in IDtcNetworkAccessConfig3 * This,
            /* [annotation][in] */ 
            _In_  BOOL bOutbound);
        
        HRESULT ( STDMETHODCALLTYPE *GetAuthenticationLevel )( 
            __RPC__in IDtcNetworkAccessConfig3 * This,
            /* [annotation][out] */ 
            _Out_  AUTHENTICATION_LEVEL *pAuthLevel);
        
        HRESULT ( STDMETHODCALLTYPE *SetAuthenticationLevel )( 
            __RPC__in IDtcNetworkAccessConfig3 * This,
            /* [annotation][in] */ 
            _In_  AUTHENTICATION_LEVEL AuthLevel);
        
        HRESULT ( STDMETHODCALLTYPE *GetLUAccess )( 
            __RPC__in IDtcNetworkAccessConfig3 * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pbLUAccess);
        
        HRESULT ( STDMETHODCALLTYPE *SetLUAccess )( 
            __RPC__in IDtcNetworkAccessConfig3 * This,
            /* [annotation][in] */ 
            _In_  BOOL bLUAccess);
        
        END_INTERFACE
    } IDtcNetworkAccessConfig3Vtbl;

    interface IDtcNetworkAccessConfig3
    {
        CONST_VTBL struct IDtcNetworkAccessConfig3Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDtcNetworkAccessConfig3_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDtcNetworkAccessConfig3_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDtcNetworkAccessConfig3_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDtcNetworkAccessConfig3_GetAnyNetworkAccess(This,pbAnyNetworkAccess)	\
    ( (This)->lpVtbl -> GetAnyNetworkAccess(This,pbAnyNetworkAccess) ) 

#define IDtcNetworkAccessConfig3_SetAnyNetworkAccess(This,bAnyNetworkAccess)	\
    ( (This)->lpVtbl -> SetAnyNetworkAccess(This,bAnyNetworkAccess) ) 

#define IDtcNetworkAccessConfig3_GetNetworkAdministrationAccess(This,pbNetworkAdministrationAccess)	\
    ( (This)->lpVtbl -> GetNetworkAdministrationAccess(This,pbNetworkAdministrationAccess) ) 

#define IDtcNetworkAccessConfig3_SetNetworkAdministrationAccess(This,bNetworkAdministrationAccess)	\
    ( (This)->lpVtbl -> SetNetworkAdministrationAccess(This,bNetworkAdministrationAccess) ) 

#define IDtcNetworkAccessConfig3_GetNetworkTransactionAccess(This,pbNetworkTransactionAccess)	\
    ( (This)->lpVtbl -> GetNetworkTransactionAccess(This,pbNetworkTransactionAccess) ) 

#define IDtcNetworkAccessConfig3_SetNetworkTransactionAccess(This,bNetworkTransactionAccess)	\
    ( (This)->lpVtbl -> SetNetworkTransactionAccess(This,bNetworkTransactionAccess) ) 

#define IDtcNetworkAccessConfig3_GetNetworkClientAccess(This,pbNetworkClientAccess)	\
    ( (This)->lpVtbl -> GetNetworkClientAccess(This,pbNetworkClientAccess) ) 

#define IDtcNetworkAccessConfig3_SetNetworkClientAccess(This,bNetworkClientAccess)	\
    ( (This)->lpVtbl -> SetNetworkClientAccess(This,bNetworkClientAccess) ) 

#define IDtcNetworkAccessConfig3_GetNetworkTIPAccess(This,pbNetworkTIPAccess)	\
    ( (This)->lpVtbl -> GetNetworkTIPAccess(This,pbNetworkTIPAccess) ) 

#define IDtcNetworkAccessConfig3_SetNetworkTIPAccess(This,bNetworkTIPAccess)	\
    ( (This)->lpVtbl -> SetNetworkTIPAccess(This,bNetworkTIPAccess) ) 

#define IDtcNetworkAccessConfig3_GetXAAccess(This,pbXAAccess)	\
    ( (This)->lpVtbl -> GetXAAccess(This,pbXAAccess) ) 

#define IDtcNetworkAccessConfig3_SetXAAccess(This,bXAAccess)	\
    ( (This)->lpVtbl -> SetXAAccess(This,bXAAccess) ) 

#define IDtcNetworkAccessConfig3_RestartDtcService(This)	\
    ( (This)->lpVtbl -> RestartDtcService(This) ) 


#define IDtcNetworkAccessConfig3_GetNetworkInboundAccess(This,pbInbound)	\
    ( (This)->lpVtbl -> GetNetworkInboundAccess(This,pbInbound) ) 

#define IDtcNetworkAccessConfig3_GetNetworkOutboundAccess(This,pbOutbound)	\
    ( (This)->lpVtbl -> GetNetworkOutboundAccess(This,pbOutbound) ) 

#define IDtcNetworkAccessConfig3_SetNetworkInboundAccess(This,bInbound)	\
    ( (This)->lpVtbl -> SetNetworkInboundAccess(This,bInbound) ) 

#define IDtcNetworkAccessConfig3_SetNetworkOutboundAccess(This,bOutbound)	\
    ( (This)->lpVtbl -> SetNetworkOutboundAccess(This,bOutbound) ) 

#define IDtcNetworkAccessConfig3_GetAuthenticationLevel(This,pAuthLevel)	\
    ( (This)->lpVtbl -> GetAuthenticationLevel(This,pAuthLevel) ) 

#define IDtcNetworkAccessConfig3_SetAuthenticationLevel(This,AuthLevel)	\
    ( (This)->lpVtbl -> SetAuthenticationLevel(This,AuthLevel) ) 


#define IDtcNetworkAccessConfig3_GetLUAccess(This,pbLUAccess)	\
    ( (This)->lpVtbl -> GetLUAccess(This,pbLUAccess) ) 

#define IDtcNetworkAccessConfig3_SetLUAccess(This,bLUAccess)	\
    ( (This)->lpVtbl -> SetLUAccess(This,bLUAccess) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDtcNetworkAccessConfig3_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_txcoord_0000_0015 */
/* [local] */ 



#if _MSC_VER < 1100 || !defined(__cplusplus)

DEFINE_GUID(IID_ITransactionResourceAsync,       0x69E971F0, 0x23CE, 0x11cf, 0xAD, 0x60, 0x00, 0xAA, 0x00, 0xA7, 0x4C, 0xCD);
DEFINE_GUID(IID_ITransactionLastResourceAsync,   0xC82BD532, 0x5B30, 0x11D3, 0x8A, 0x91, 0x00, 0xC0, 0x4F, 0x79, 0xEB, 0x6D);
DEFINE_GUID(IID_ITransactionResource,            0xEE5FF7B3, 0x4572, 0x11d0, 0x94, 0x52, 0x00, 0xA0, 0xC9, 0x05, 0x41, 0x6E);
DEFINE_GUID(IID_ITransactionEnlistmentAsync,     0x0fb15081, 0xaf41, 0x11ce, 0xbd, 0x2b, 0x20, 0x4c, 0x4f, 0x4f, 0x50, 0x20);
DEFINE_GUID(IID_ITransactionLastEnlistmentAsync, 0xC82BD533, 0x5B30, 0x11D3, 0x8A, 0x91, 0x00, 0xC0, 0x4F, 0x79, 0xEB, 0x6D);
DEFINE_GUID(IID_ITransactionExportFactory,       0xE1CF9B53, 0x8745, 0x11ce, 0xA9, 0xBA, 0x00, 0xAA, 0x00, 0x6C, 0x37, 0x06);
DEFINE_GUID(IID_ITransactionImportWhereabouts,   0x0141fda4, 0x8fc0, 0x11ce, 0xbd, 0x18, 0x20, 0x4c, 0x4f, 0x4f, 0x50, 0x20);
DEFINE_GUID(IID_ITransactionExport,              0x0141fda5, 0x8fc0, 0x11ce, 0xbd, 0x18, 0x20, 0x4c, 0x4f, 0x4f, 0x50, 0x20);
DEFINE_GUID(IID_ITransactionImport,              0xE1CF9B5A, 0x8745, 0x11ce, 0xA9, 0xBA, 0x00, 0xAA, 0x00, 0x6C, 0x37, 0x06);
DEFINE_GUID(IID_ITipTransaction,                 0x17cf72d0, 0xbac5, 0x11d1, 0xb1, 0xbf, 0x0, 0xc0, 0x4f, 0xc2, 0xf3, 0xef);
DEFINE_GUID(IID_ITipHelper,                      0x17cf72d1, 0xbac5, 0x11d1, 0xb1, 0xbf, 0x0, 0xc0, 0x4f, 0xc2, 0xf3, 0xef);
DEFINE_GUID(IID_ITipPullSink,                    0x17cf72d2, 0xbac5, 0x11d1, 0xb1, 0xbf, 0x0, 0xc0, 0x4f, 0xc2, 0xf3, 0xef);
DEFINE_GUID(IID_IDtcNetworkAccessConfig,         0x9797c15d, 0xa428, 0x4291, 0x87, 0xb6, 0x9, 0x95, 0x3, 0x1a, 0x67, 0x8d);
DEFINE_GUID(IID_IDtcNetworkAccessConfig2,        0xa7aa013b, 0xeb7d, 0x4f42, 0xb4, 0x1c, 0xb2, 0xde, 0xc0, 0x9a, 0xe0, 0x34);

#else

#define  IID_ITransactionResourceAsync               __uuidof(ITransactionResourceAsync)
#define  IID_ITransactionLastResourceAsync           __uuidof(ITransactionLastResourceAsync)
#define  IID_ITransactionResource                    __uuidof(ITransactionResource)
#define  IID_ITransactionEnlistmentAsync             __uuidof(ITransactionEnlistmentAsync)
#define  IID_ITransactionLastEnlistmentAsync         __uuidof(ITransactionLastEnlistmentAsync)
#define  IID_ITransactionExportFactory               __uuidof(ITransactionExportFactory)
#define  IID_ITransactionImportWhereabouts           __uuidof(ITransactionImportWhereabouts)
#define  IID_ITransactionExport                      __uuidof(ITransactionExport)
#define  IID_ITransactionImport                      __uuidof(ITransactionImport)
#define  IID_ITipTransaction                         __uuidof(ITipTransaction)
#define  IID_ITipHelper                              __uuidof(ITipHelper)
#define  IID_ITipPullSink                            __uuidof(ITipPullSink)
#define  IID_IDtcNetworkAccessConfig                 __uuidof(IDtcNetworkAccessConfig)
#define  IID_IDtcNetworkAccessConfig2                __uuidof(IDtcNetworkAccessConfig2)
#define  IID_IDtcNetworkAccessConfig3                __uuidof(IDtcNetworkAccessConfig3)

#endif
#pragma deprecated (ITipTransaction)
#pragma deprecated (ITipHelper)
#pragma deprecated (ITipPullSink)
#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_txcoord_0000_0015_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_txcoord_0000_0015_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* [local] */ HRESULT STDMETHODCALLTYPE ITransactionImportWhereabouts_GetWhereabouts_Proxy( 
    ITransactionImportWhereabouts * This,
    /* [annotation][in] */ 
    _In_  ULONG cbWhereabouts,
    /* [annotation][size_is][out] */ 
    _Out_writes_(cbWhereabouts)  byte *rgbWhereabouts,
    /* [annotation][out] */ 
    _Out_  ULONG *pcbUsed);


/* [call_as] */ HRESULT STDMETHODCALLTYPE ITransactionImportWhereabouts_GetWhereabouts_Stub( 
    __RPC__in ITransactionImportWhereabouts * This,
    /* [annotation][out] */ 
    _Out_  ULONG *pcbUsed,
    /* [annotation][in] */ 
    _In_  ULONG cbWhereabouts,
    /* [annotation][length_is][size_is][out] */ 
    _Out_writes_to_(cbWhereabouts,*pcbUsed)  byte *rgbWhereabouts);

/* [local] */ HRESULT STDMETHODCALLTYPE ITransactionExport_GetTransactionCookie_Proxy( 
    ITransactionExport * This,
    /* [annotation][in] */ 
    _In_  IUnknown *punkTransaction,
    /* [annotation][in] */ 
    _In_  ULONG cbTransactionCookie,
    /* [annotation][size_is][out] */ 
    _Out_writes_(cbTransactionCookie)  byte *rgbTransactionCookie,
    /* [annotation][out] */ 
    _Out_  ULONG *pcbUsed);


/* [call_as] */ HRESULT STDMETHODCALLTYPE ITransactionExport_GetTransactionCookie_Stub( 
    __RPC__in ITransactionExport * This,
    /* [annotation][in] */ 
    _In_  IUnknown *punkTransaction,
    /* [annotation][out] */ 
    _Out_  ULONG *pcbUsed,
    /* [annotation][in] */ 
    _In_  ULONG cbTransactionCookie,
    /* [annotation][length_is][size_is][out] */ 
    _Out_writes_to_(cbTransactionCookie,*pcbUsed)  byte *rgbTransactionCookie);



/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


