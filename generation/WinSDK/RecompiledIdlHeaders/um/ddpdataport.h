

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

#ifndef __ddpdataport_h__
#define __ddpdataport_h__

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

#ifndef __IDedupDataPort_FWD_DEFINED__
#define __IDedupDataPort_FWD_DEFINED__
typedef interface IDedupDataPort IDedupDataPort;

#endif 	/* __IDedupDataPort_FWD_DEFINED__ */


#ifndef __IDedupDataPortManager_FWD_DEFINED__
#define __IDedupDataPortManager_FWD_DEFINED__
typedef interface IDedupDataPortManager IDedupDataPortManager;

#endif 	/* __IDedupDataPortManager_FWD_DEFINED__ */


#ifndef __IDedupDataPort_FWD_DEFINED__
#define __IDedupDataPort_FWD_DEFINED__
typedef interface IDedupDataPort IDedupDataPort;

#endif 	/* __IDedupDataPort_FWD_DEFINED__ */


#ifndef __IDedupDataPortManager_FWD_DEFINED__
#define __IDedupDataPortManager_FWD_DEFINED__
typedef interface IDedupDataPortManager IDedupDataPortManager;

#endif 	/* __IDedupDataPortManager_FWD_DEFINED__ */


#ifndef __DedupDataPort_FWD_DEFINED__
#define __DedupDataPort_FWD_DEFINED__

#ifdef __cplusplus
typedef class DedupDataPort DedupDataPort;
#else
typedef struct DedupDataPort DedupDataPort;
#endif /* __cplusplus */

#endif 	/* __DedupDataPort_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "ddpcommon.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_ddpdataport_0000_0000 */
/* [local] */ 

#include <winapifamily.h>
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)


extern RPC_IF_HANDLE __MIDL_itf_ddpdataport_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ddpdataport_0000_0000_v0_0_s_ifspec;

#ifndef __IDedupDataPort_INTERFACE_DEFINED__
#define __IDedupDataPort_INTERFACE_DEFINED__

/* interface IDedupDataPort */
/* [version][object][uuid] */ 


EXTERN_C const IID IID_IDedupDataPort;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7963d734-40a9-4ea3-bbf6-5a89d26f7ae8")
    IDedupDataPort : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetStatus( 
            /* [annotation][out] */ 
            _Out_  DedupDataPortVolumeStatus *pStatus,
            /* [optional][out] */ __RPC__out DWORD *pDataHeadroomMb) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LookupChunks( 
            /* [annotation][in] */ 
            _In_  DWORD Count,
            /* [annotation][size_is][in] */ 
            _In_reads_(Count)  DedupHash *pHashes,
            /* [annotation][out] */ 
            _Out_  GUID *pRequestId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InsertChunks( 
            /* [annotation][in] */ 
            _In_  DWORD ChunkCount,
            /* [annotation][size_is][in] */ 
            _In_reads_(ChunkCount)  DedupChunk *pChunkMetadata,
            /* [annotation][in] */ 
            _In_  DWORD DataByteCount,
            /* [annotation][size_is][in] */ 
            _In_reads_(DataByteCount)  BYTE *pChunkData,
            /* [annotation][out] */ 
            _Out_  GUID *pRequestId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InsertChunksWithStream( 
            /* [annotation][in] */ 
            _In_  DWORD ChunkCount,
            /* [annotation][size_is][in] */ 
            _In_reads_(ChunkCount)  DedupChunk *pChunkMetadata,
            /* [annotation][in] */ 
            _In_  DWORD DataByteCount,
            /* [annotation][in] */ 
            _In_  IStream *pChunkDataStream,
            /* [annotation][out] */ 
            _Out_  GUID *pRequestId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CommitStreams( 
            /* [annotation][in] */ 
            _In_  DWORD StreamCount,
            /* [annotation][size_is][in] */ 
            _In_reads_(StreamCount)  DedupStream *pStreams,
            /* [annotation][in] */ 
            _In_  DWORD EntryCount,
            /* [annotation][size_is][in] */ 
            _In_reads_(EntryCount)  DedupStreamEntry *pEntries,
            /* [annotation][out] */ 
            _Out_  GUID *pRequestId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CommitStreamsWithStream( 
            /* [annotation][in] */ 
            _In_  DWORD StreamCount,
            /* [annotation][size_is][in] */ 
            _In_reads_(StreamCount)  DedupStream *pStreams,
            /* [annotation][in] */ 
            _In_  DWORD EntryCount,
            /* [annotation][in] */ 
            _In_  IStream *pEntriesStream,
            /* [annotation][out] */ 
            _Out_  GUID *pRequestId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStreams( 
            /* [annotation][in] */ 
            _In_  DWORD StreamCount,
            /* [annotation][size_is][in] */ 
            _In_reads_(StreamCount)  BSTR *pStreamPaths,
            /* [annotation][out] */ 
            _Out_  GUID *pRequestId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStreamsResults( 
            /* [annotation][in] */ 
            _In_  GUID RequestId,
            /* [annotation][in] */ 
            _In_  DWORD MaxWaitMs,
            /* [annotation][in] */ 
            _In_  DWORD StreamEntryIndex,
            /* [annotation][out] */ 
            _Out_  DWORD *pStreamCount,
            /* [annotation][size_is][size_is][out] */ 
            _Out_writes_(*pStreamCount)  DedupStream **ppStreams,
            /* [annotation][out] */ 
            _Out_  DWORD *pEntryCount,
            /* [annotation][size_is][size_is][out] */ 
            _Out_writes_(*pEntryCount)  DedupStreamEntry **ppEntries,
            /* [annotation][out] */ 
            _Out_  DedupDataPortRequestStatus *pStatus,
            /* [annotation][size_is][size_is][out] */ 
            _Out_writes_(*pStreamCount)  HRESULT **ppItemResults) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetChunks( 
            /* [annotation][in] */ 
            _In_  DWORD Count,
            /* [annotation][size_is][in] */ 
            _In_reads_(Count)  DedupHash *pHashes,
            /* [annotation][out] */ 
            _Out_  GUID *pRequestId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetChunksResults( 
            /* [annotation][in] */ 
            _In_  GUID RequestId,
            /* [annotation][in] */ 
            _In_  DWORD MaxWaitMs,
            /* [annotation][in] */ 
            _In_  DWORD ChunkIndex,
            /* [annotation][out] */ 
            _Out_  DWORD *pChunkCount,
            /* [annotation][size_is][size_is][out] */ 
            _Out_writes_(*pChunkCount)  DedupChunk **ppChunkMetadata,
            /* [annotation][out] */ 
            _Out_  DWORD *pDataByteCount,
            /* [annotation][size_is][size_is][out] */ 
            _Out_writes_(*pDataByteCount)  BYTE **ppChunkData,
            /* [annotation][out] */ 
            _Out_  DedupDataPortRequestStatus *pStatus,
            /* [annotation][size_is][size_is][out] */ 
            _Out_writes_(*pChunkCount)  HRESULT **ppItemResults) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRequestStatus( 
            /* [annotation][in] */ 
            _In_  GUID RequestId,
            /* [annotation][out] */ 
            _Out_  DedupDataPortRequestStatus *pStatus) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRequestResults( 
            /* [annotation][in] */ 
            _In_  GUID RequestId,
            /* [annotation][in] */ 
            _In_  DWORD MaxWaitMs,
            /* [annotation][out] */ 
            _Out_  HRESULT *pBatchResult,
            /* [annotation][out] */ 
            _Out_  DWORD *pBatchCount,
            /* [annotation][out] */ 
            _Out_  DedupDataPortRequestStatus *pStatus,
            /* [annotation][size_is][size_is][out] */ 
            _Out_writes_(*pBatchCount)  HRESULT **ppItemResults) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IDedupDataPortVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IDedupDataPort * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IDedupDataPort * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IDedupDataPort * This);
        
        DECLSPEC_XFGVIRT(IDedupDataPort, GetStatus)
        HRESULT ( STDMETHODCALLTYPE *GetStatus )( 
            __RPC__in IDedupDataPort * This,
            /* [annotation][out] */ 
            _Out_  DedupDataPortVolumeStatus *pStatus,
            /* [optional][out] */ __RPC__out DWORD *pDataHeadroomMb);
        
        DECLSPEC_XFGVIRT(IDedupDataPort, LookupChunks)
        HRESULT ( STDMETHODCALLTYPE *LookupChunks )( 
            __RPC__in IDedupDataPort * This,
            /* [annotation][in] */ 
            _In_  DWORD Count,
            /* [annotation][size_is][in] */ 
            _In_reads_(Count)  DedupHash *pHashes,
            /* [annotation][out] */ 
            _Out_  GUID *pRequestId);
        
        DECLSPEC_XFGVIRT(IDedupDataPort, InsertChunks)
        HRESULT ( STDMETHODCALLTYPE *InsertChunks )( 
            __RPC__in IDedupDataPort * This,
            /* [annotation][in] */ 
            _In_  DWORD ChunkCount,
            /* [annotation][size_is][in] */ 
            _In_reads_(ChunkCount)  DedupChunk *pChunkMetadata,
            /* [annotation][in] */ 
            _In_  DWORD DataByteCount,
            /* [annotation][size_is][in] */ 
            _In_reads_(DataByteCount)  BYTE *pChunkData,
            /* [annotation][out] */ 
            _Out_  GUID *pRequestId);
        
        DECLSPEC_XFGVIRT(IDedupDataPort, InsertChunksWithStream)
        HRESULT ( STDMETHODCALLTYPE *InsertChunksWithStream )( 
            __RPC__in IDedupDataPort * This,
            /* [annotation][in] */ 
            _In_  DWORD ChunkCount,
            /* [annotation][size_is][in] */ 
            _In_reads_(ChunkCount)  DedupChunk *pChunkMetadata,
            /* [annotation][in] */ 
            _In_  DWORD DataByteCount,
            /* [annotation][in] */ 
            _In_  IStream *pChunkDataStream,
            /* [annotation][out] */ 
            _Out_  GUID *pRequestId);
        
        DECLSPEC_XFGVIRT(IDedupDataPort, CommitStreams)
        HRESULT ( STDMETHODCALLTYPE *CommitStreams )( 
            __RPC__in IDedupDataPort * This,
            /* [annotation][in] */ 
            _In_  DWORD StreamCount,
            /* [annotation][size_is][in] */ 
            _In_reads_(StreamCount)  DedupStream *pStreams,
            /* [annotation][in] */ 
            _In_  DWORD EntryCount,
            /* [annotation][size_is][in] */ 
            _In_reads_(EntryCount)  DedupStreamEntry *pEntries,
            /* [annotation][out] */ 
            _Out_  GUID *pRequestId);
        
        DECLSPEC_XFGVIRT(IDedupDataPort, CommitStreamsWithStream)
        HRESULT ( STDMETHODCALLTYPE *CommitStreamsWithStream )( 
            __RPC__in IDedupDataPort * This,
            /* [annotation][in] */ 
            _In_  DWORD StreamCount,
            /* [annotation][size_is][in] */ 
            _In_reads_(StreamCount)  DedupStream *pStreams,
            /* [annotation][in] */ 
            _In_  DWORD EntryCount,
            /* [annotation][in] */ 
            _In_  IStream *pEntriesStream,
            /* [annotation][out] */ 
            _Out_  GUID *pRequestId);
        
        DECLSPEC_XFGVIRT(IDedupDataPort, GetStreams)
        HRESULT ( STDMETHODCALLTYPE *GetStreams )( 
            __RPC__in IDedupDataPort * This,
            /* [annotation][in] */ 
            _In_  DWORD StreamCount,
            /* [annotation][size_is][in] */ 
            _In_reads_(StreamCount)  BSTR *pStreamPaths,
            /* [annotation][out] */ 
            _Out_  GUID *pRequestId);
        
        DECLSPEC_XFGVIRT(IDedupDataPort, GetStreamsResults)
        HRESULT ( STDMETHODCALLTYPE *GetStreamsResults )( 
            __RPC__in IDedupDataPort * This,
            /* [annotation][in] */ 
            _In_  GUID RequestId,
            /* [annotation][in] */ 
            _In_  DWORD MaxWaitMs,
            /* [annotation][in] */ 
            _In_  DWORD StreamEntryIndex,
            /* [annotation][out] */ 
            _Out_  DWORD *pStreamCount,
            /* [annotation][size_is][size_is][out] */ 
            _Out_writes_(*pStreamCount)  DedupStream **ppStreams,
            /* [annotation][out] */ 
            _Out_  DWORD *pEntryCount,
            /* [annotation][size_is][size_is][out] */ 
            _Out_writes_(*pEntryCount)  DedupStreamEntry **ppEntries,
            /* [annotation][out] */ 
            _Out_  DedupDataPortRequestStatus *pStatus,
            /* [annotation][size_is][size_is][out] */ 
            _Out_writes_(*pStreamCount)  HRESULT **ppItemResults);
        
        DECLSPEC_XFGVIRT(IDedupDataPort, GetChunks)
        HRESULT ( STDMETHODCALLTYPE *GetChunks )( 
            __RPC__in IDedupDataPort * This,
            /* [annotation][in] */ 
            _In_  DWORD Count,
            /* [annotation][size_is][in] */ 
            _In_reads_(Count)  DedupHash *pHashes,
            /* [annotation][out] */ 
            _Out_  GUID *pRequestId);
        
        DECLSPEC_XFGVIRT(IDedupDataPort, GetChunksResults)
        HRESULT ( STDMETHODCALLTYPE *GetChunksResults )( 
            __RPC__in IDedupDataPort * This,
            /* [annotation][in] */ 
            _In_  GUID RequestId,
            /* [annotation][in] */ 
            _In_  DWORD MaxWaitMs,
            /* [annotation][in] */ 
            _In_  DWORD ChunkIndex,
            /* [annotation][out] */ 
            _Out_  DWORD *pChunkCount,
            /* [annotation][size_is][size_is][out] */ 
            _Out_writes_(*pChunkCount)  DedupChunk **ppChunkMetadata,
            /* [annotation][out] */ 
            _Out_  DWORD *pDataByteCount,
            /* [annotation][size_is][size_is][out] */ 
            _Out_writes_(*pDataByteCount)  BYTE **ppChunkData,
            /* [annotation][out] */ 
            _Out_  DedupDataPortRequestStatus *pStatus,
            /* [annotation][size_is][size_is][out] */ 
            _Out_writes_(*pChunkCount)  HRESULT **ppItemResults);
        
        DECLSPEC_XFGVIRT(IDedupDataPort, GetRequestStatus)
        HRESULT ( STDMETHODCALLTYPE *GetRequestStatus )( 
            __RPC__in IDedupDataPort * This,
            /* [annotation][in] */ 
            _In_  GUID RequestId,
            /* [annotation][out] */ 
            _Out_  DedupDataPortRequestStatus *pStatus);
        
        DECLSPEC_XFGVIRT(IDedupDataPort, GetRequestResults)
        HRESULT ( STDMETHODCALLTYPE *GetRequestResults )( 
            __RPC__in IDedupDataPort * This,
            /* [annotation][in] */ 
            _In_  GUID RequestId,
            /* [annotation][in] */ 
            _In_  DWORD MaxWaitMs,
            /* [annotation][out] */ 
            _Out_  HRESULT *pBatchResult,
            /* [annotation][out] */ 
            _Out_  DWORD *pBatchCount,
            /* [annotation][out] */ 
            _Out_  DedupDataPortRequestStatus *pStatus,
            /* [annotation][size_is][size_is][out] */ 
            _Out_writes_(*pBatchCount)  HRESULT **ppItemResults);
        
        END_INTERFACE
    } IDedupDataPortVtbl;

    interface IDedupDataPort
    {
        CONST_VTBL struct IDedupDataPortVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDedupDataPort_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDedupDataPort_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDedupDataPort_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDedupDataPort_GetStatus(This,pStatus,pDataHeadroomMb)	\
    ( (This)->lpVtbl -> GetStatus(This,pStatus,pDataHeadroomMb) ) 

#define IDedupDataPort_LookupChunks(This,Count,pHashes,pRequestId)	\
    ( (This)->lpVtbl -> LookupChunks(This,Count,pHashes,pRequestId) ) 

#define IDedupDataPort_InsertChunks(This,ChunkCount,pChunkMetadata,DataByteCount,pChunkData,pRequestId)	\
    ( (This)->lpVtbl -> InsertChunks(This,ChunkCount,pChunkMetadata,DataByteCount,pChunkData,pRequestId) ) 

#define IDedupDataPort_InsertChunksWithStream(This,ChunkCount,pChunkMetadata,DataByteCount,pChunkDataStream,pRequestId)	\
    ( (This)->lpVtbl -> InsertChunksWithStream(This,ChunkCount,pChunkMetadata,DataByteCount,pChunkDataStream,pRequestId) ) 

#define IDedupDataPort_CommitStreams(This,StreamCount,pStreams,EntryCount,pEntries,pRequestId)	\
    ( (This)->lpVtbl -> CommitStreams(This,StreamCount,pStreams,EntryCount,pEntries,pRequestId) ) 

#define IDedupDataPort_CommitStreamsWithStream(This,StreamCount,pStreams,EntryCount,pEntriesStream,pRequestId)	\
    ( (This)->lpVtbl -> CommitStreamsWithStream(This,StreamCount,pStreams,EntryCount,pEntriesStream,pRequestId) ) 

#define IDedupDataPort_GetStreams(This,StreamCount,pStreamPaths,pRequestId)	\
    ( (This)->lpVtbl -> GetStreams(This,StreamCount,pStreamPaths,pRequestId) ) 

#define IDedupDataPort_GetStreamsResults(This,RequestId,MaxWaitMs,StreamEntryIndex,pStreamCount,ppStreams,pEntryCount,ppEntries,pStatus,ppItemResults)	\
    ( (This)->lpVtbl -> GetStreamsResults(This,RequestId,MaxWaitMs,StreamEntryIndex,pStreamCount,ppStreams,pEntryCount,ppEntries,pStatus,ppItemResults) ) 

#define IDedupDataPort_GetChunks(This,Count,pHashes,pRequestId)	\
    ( (This)->lpVtbl -> GetChunks(This,Count,pHashes,pRequestId) ) 

#define IDedupDataPort_GetChunksResults(This,RequestId,MaxWaitMs,ChunkIndex,pChunkCount,ppChunkMetadata,pDataByteCount,ppChunkData,pStatus,ppItemResults)	\
    ( (This)->lpVtbl -> GetChunksResults(This,RequestId,MaxWaitMs,ChunkIndex,pChunkCount,ppChunkMetadata,pDataByteCount,ppChunkData,pStatus,ppItemResults) ) 

#define IDedupDataPort_GetRequestStatus(This,RequestId,pStatus)	\
    ( (This)->lpVtbl -> GetRequestStatus(This,RequestId,pStatus) ) 

#define IDedupDataPort_GetRequestResults(This,RequestId,MaxWaitMs,pBatchResult,pBatchCount,pStatus,ppItemResults)	\
    ( (This)->lpVtbl -> GetRequestResults(This,RequestId,MaxWaitMs,pBatchResult,pBatchCount,pStatus,ppItemResults) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDedupDataPort_INTERFACE_DEFINED__ */


#ifndef __IDedupDataPortManager_INTERFACE_DEFINED__
#define __IDedupDataPortManager_INTERFACE_DEFINED__

/* interface IDedupDataPortManager */
/* [version][object][uuid] */ 


EXTERN_C const IID IID_IDedupDataPortManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("44677452-b90a-445e-8192-cdcfe81511fb")
    IDedupDataPortManager : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetConfiguration( 
            /* [annotation][out] */ 
            _Out_  DWORD *pMinChunkSize,
            /* [annotation][out] */ 
            _Out_  DWORD *pMaxChunkSize,
            /* [annotation][out] */ 
            _Out_  DedupChunkingAlgorithm *pChunkingAlgorithm,
            /* [annotation][out] */ 
            _Out_  DedupHashingAlgorithm *pHashingAlgorithm,
            /* [annotation][out] */ 
            _Out_  DedupCompressionAlgorithm *pCompressionAlgorithm) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetVolumeStatus( 
            /* [annotation][in] */ 
            _In_  DWORD Options,
            /* [annotation][in] */ 
            _In_  BSTR Path,
            /* [annotation][out] */ 
            _Out_  DedupDataPortVolumeStatus *pStatus) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetVolumeDataPort( 
            /* [annotation][in] */ 
            _In_  DWORD Options,
            /* [annotation][in] */ 
            _In_  BSTR Path,
            /* [annotation][out] */ 
            _Out_  IDedupDataPort **ppDataPort) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IDedupDataPortManagerVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IDedupDataPortManager * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IDedupDataPortManager * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IDedupDataPortManager * This);
        
        DECLSPEC_XFGVIRT(IDedupDataPortManager, GetConfiguration)
        HRESULT ( STDMETHODCALLTYPE *GetConfiguration )( 
            __RPC__in IDedupDataPortManager * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pMinChunkSize,
            /* [annotation][out] */ 
            _Out_  DWORD *pMaxChunkSize,
            /* [annotation][out] */ 
            _Out_  DedupChunkingAlgorithm *pChunkingAlgorithm,
            /* [annotation][out] */ 
            _Out_  DedupHashingAlgorithm *pHashingAlgorithm,
            /* [annotation][out] */ 
            _Out_  DedupCompressionAlgorithm *pCompressionAlgorithm);
        
        DECLSPEC_XFGVIRT(IDedupDataPortManager, GetVolumeStatus)
        HRESULT ( STDMETHODCALLTYPE *GetVolumeStatus )( 
            __RPC__in IDedupDataPortManager * This,
            /* [annotation][in] */ 
            _In_  DWORD Options,
            /* [annotation][in] */ 
            _In_  BSTR Path,
            /* [annotation][out] */ 
            _Out_  DedupDataPortVolumeStatus *pStatus);
        
        DECLSPEC_XFGVIRT(IDedupDataPortManager, GetVolumeDataPort)
        HRESULT ( STDMETHODCALLTYPE *GetVolumeDataPort )( 
            __RPC__in IDedupDataPortManager * This,
            /* [annotation][in] */ 
            _In_  DWORD Options,
            /* [annotation][in] */ 
            _In_  BSTR Path,
            /* [annotation][out] */ 
            _Out_  IDedupDataPort **ppDataPort);
        
        END_INTERFACE
    } IDedupDataPortManagerVtbl;

    interface IDedupDataPortManager
    {
        CONST_VTBL struct IDedupDataPortManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDedupDataPortManager_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDedupDataPortManager_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDedupDataPortManager_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDedupDataPortManager_GetConfiguration(This,pMinChunkSize,pMaxChunkSize,pChunkingAlgorithm,pHashingAlgorithm,pCompressionAlgorithm)	\
    ( (This)->lpVtbl -> GetConfiguration(This,pMinChunkSize,pMaxChunkSize,pChunkingAlgorithm,pHashingAlgorithm,pCompressionAlgorithm) ) 

#define IDedupDataPortManager_GetVolumeStatus(This,Options,Path,pStatus)	\
    ( (This)->lpVtbl -> GetVolumeStatus(This,Options,Path,pStatus) ) 

#define IDedupDataPortManager_GetVolumeDataPort(This,Options,Path,ppDataPort)	\
    ( (This)->lpVtbl -> GetVolumeDataPort(This,Options,Path,ppDataPort) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDedupDataPortManager_INTERFACE_DEFINED__ */



#ifndef __DedupDataPort_LIBRARY_DEFINED__
#define __DedupDataPort_LIBRARY_DEFINED__

/* library DedupDataPort */
/* [version][uuid] */ 




EXTERN_C const IID LIBID_DedupDataPort;

EXTERN_C const CLSID CLSID_DedupDataPort;

#ifdef __cplusplus

class DECLSPEC_UUID("8f107207-1829-48b2-a64b-e61f8e0d9acb")
DedupDataPort;
#endif
#endif /* __DedupDataPort_LIBRARY_DEFINED__ */

/* interface __MIDL_itf_ddpdataport_0000_0003 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_ddpdataport_0000_0003_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ddpdataport_0000_0003_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     __RPC__in unsigned long *, unsigned long            , __RPC__in BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     __RPC__in unsigned long *, __RPC__in BSTR * ); 

unsigned long             __RPC_USER  BSTR_UserSize64(     __RPC__in unsigned long *, unsigned long            , __RPC__in BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal64(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal64(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out BSTR * ); 
void                      __RPC_USER  BSTR_UserFree64(     __RPC__in unsigned long *, __RPC__in BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


