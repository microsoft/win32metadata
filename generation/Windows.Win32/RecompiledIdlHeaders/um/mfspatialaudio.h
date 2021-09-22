

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

#ifndef __mfspatialaudio_h__
#define __mfspatialaudio_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IMFSpatialAudioObjectBuffer_FWD_DEFINED__
#define __IMFSpatialAudioObjectBuffer_FWD_DEFINED__
typedef interface IMFSpatialAudioObjectBuffer IMFSpatialAudioObjectBuffer;

#endif 	/* __IMFSpatialAudioObjectBuffer_FWD_DEFINED__ */


#ifndef __IMFSpatialAudioSample_FWD_DEFINED__
#define __IMFSpatialAudioSample_FWD_DEFINED__
typedef interface IMFSpatialAudioSample IMFSpatialAudioSample;

#endif 	/* __IMFSpatialAudioSample_FWD_DEFINED__ */


/* header files for imported files */
#include "mfobjects.h"
#include "SpatialAudioClient.h"
#include "SpatialAudioMetadata.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_mfspatialaudio_0000_0000 */
/* [local] */ 

#pragma region Application Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP)


extern RPC_IF_HANDLE __MIDL_itf_mfspatialaudio_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_mfspatialaudio_0000_0000_v0_0_s_ifspec;

#ifndef __IMFSpatialAudioObjectBuffer_INTERFACE_DEFINED__
#define __IMFSpatialAudioObjectBuffer_INTERFACE_DEFINED__

/* interface IMFSpatialAudioObjectBuffer */
/* [local][uuid][object] */ 


EXTERN_C const IID IID_IMFSpatialAudioObjectBuffer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("d396ec8c-605e-4249-978d-72ad1c312872")
    IMFSpatialAudioObjectBuffer : public IMFMediaBuffer
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetID( 
            /* [annotation][in] */ 
            _In_  UINT32 u32ID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetID( 
            /* [annotation][out] */ 
            _Out_  UINT32 *pu32ID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetType( 
            /* [annotation][in] */ 
            _In_  AudioObjectType type) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetType( 
            /* [annotation][out] */ 
            _Out_  AudioObjectType *pType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMetadataItems( 
            /* [annotation][out] */ 
            _Outptr_result_nullonfailure_  ISpatialAudioMetadataItems **ppMetadataItems) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IMFSpatialAudioObjectBufferVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMFSpatialAudioObjectBuffer * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMFSpatialAudioObjectBuffer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMFSpatialAudioObjectBuffer * This);
        
        HRESULT ( STDMETHODCALLTYPE *Lock )( 
            IMFSpatialAudioObjectBuffer * This,
            /* [annotation][out] */ 
            _Outptr_result_bytebuffer_to_(*pcbMaxLength, *pcbCurrentLength)  BYTE **ppbBuffer,
            /* [annotation][out] */ 
            _Out_opt_  DWORD *pcbMaxLength,
            /* [annotation][out] */ 
            _Out_opt_  DWORD *pcbCurrentLength);
        
        HRESULT ( STDMETHODCALLTYPE *Unlock )( 
            IMFSpatialAudioObjectBuffer * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetCurrentLength )( 
            IMFSpatialAudioObjectBuffer * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pcbCurrentLength);
        
        HRESULT ( STDMETHODCALLTYPE *SetCurrentLength )( 
            IMFSpatialAudioObjectBuffer * This,
            /* [annotation][in] */ 
            _In_  DWORD cbCurrentLength);
        
        HRESULT ( STDMETHODCALLTYPE *GetMaxLength )( 
            IMFSpatialAudioObjectBuffer * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pcbMaxLength);
        
        HRESULT ( STDMETHODCALLTYPE *SetID )( 
            IMFSpatialAudioObjectBuffer * This,
            /* [annotation][in] */ 
            _In_  UINT32 u32ID);
        
        HRESULT ( STDMETHODCALLTYPE *GetID )( 
            IMFSpatialAudioObjectBuffer * This,
            /* [annotation][out] */ 
            _Out_  UINT32 *pu32ID);
        
        HRESULT ( STDMETHODCALLTYPE *SetType )( 
            IMFSpatialAudioObjectBuffer * This,
            /* [annotation][in] */ 
            _In_  AudioObjectType type);
        
        HRESULT ( STDMETHODCALLTYPE *GetType )( 
            IMFSpatialAudioObjectBuffer * This,
            /* [annotation][out] */ 
            _Out_  AudioObjectType *pType);
        
        HRESULT ( STDMETHODCALLTYPE *GetMetadataItems )( 
            IMFSpatialAudioObjectBuffer * This,
            /* [annotation][out] */ 
            _Outptr_result_nullonfailure_  ISpatialAudioMetadataItems **ppMetadataItems);
        
        END_INTERFACE
    } IMFSpatialAudioObjectBufferVtbl;

    interface IMFSpatialAudioObjectBuffer
    {
        CONST_VTBL struct IMFSpatialAudioObjectBufferVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMFSpatialAudioObjectBuffer_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMFSpatialAudioObjectBuffer_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMFSpatialAudioObjectBuffer_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMFSpatialAudioObjectBuffer_Lock(This,ppbBuffer,pcbMaxLength,pcbCurrentLength)	\
    ( (This)->lpVtbl -> Lock(This,ppbBuffer,pcbMaxLength,pcbCurrentLength) ) 

#define IMFSpatialAudioObjectBuffer_Unlock(This)	\
    ( (This)->lpVtbl -> Unlock(This) ) 

#define IMFSpatialAudioObjectBuffer_GetCurrentLength(This,pcbCurrentLength)	\
    ( (This)->lpVtbl -> GetCurrentLength(This,pcbCurrentLength) ) 

#define IMFSpatialAudioObjectBuffer_SetCurrentLength(This,cbCurrentLength)	\
    ( (This)->lpVtbl -> SetCurrentLength(This,cbCurrentLength) ) 

#define IMFSpatialAudioObjectBuffer_GetMaxLength(This,pcbMaxLength)	\
    ( (This)->lpVtbl -> GetMaxLength(This,pcbMaxLength) ) 


#define IMFSpatialAudioObjectBuffer_SetID(This,u32ID)	\
    ( (This)->lpVtbl -> SetID(This,u32ID) ) 

#define IMFSpatialAudioObjectBuffer_GetID(This,pu32ID)	\
    ( (This)->lpVtbl -> GetID(This,pu32ID) ) 

#define IMFSpatialAudioObjectBuffer_SetType(This,type)	\
    ( (This)->lpVtbl -> SetType(This,type) ) 

#define IMFSpatialAudioObjectBuffer_GetType(This,pType)	\
    ( (This)->lpVtbl -> GetType(This,pType) ) 

#define IMFSpatialAudioObjectBuffer_GetMetadataItems(This,ppMetadataItems)	\
    ( (This)->lpVtbl -> GetMetadataItems(This,ppMetadataItems) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMFSpatialAudioObjectBuffer_INTERFACE_DEFINED__ */


#ifndef __IMFSpatialAudioSample_INTERFACE_DEFINED__
#define __IMFSpatialAudioSample_INTERFACE_DEFINED__

/* interface IMFSpatialAudioSample */
/* [local][uuid][object] */ 


EXTERN_C const IID IID_IMFSpatialAudioSample;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("abf28a9B-3393-4290-ba79-5ffc46d986b2")
    IMFSpatialAudioSample : public IMFSample
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetObjectCount( 
            /* [annotation][out] */ 
            _Out_  DWORD *pdwObjectCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddSpatialAudioObject( 
            /* [annotation][in] */ 
            _In_  IMFSpatialAudioObjectBuffer *pAudioObjBuffer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSpatialAudioObjectByIndex( 
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][out] */ 
            _COM_Outptr_  IMFSpatialAudioObjectBuffer **ppAudioObjBuffer) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IMFSpatialAudioSampleVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMFSpatialAudioSample * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMFSpatialAudioSample * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMFSpatialAudioSample * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetItem )( 
            IMFSpatialAudioSample * This,
            REFGUID guidKey,
            /* [full][out][in] */ PROPVARIANT *pValue);
        
        HRESULT ( STDMETHODCALLTYPE *GetItemType )( 
            IMFSpatialAudioSample * This,
            REFGUID guidKey,
            /* [annotation][out] */ 
            _Out_  MF_ATTRIBUTE_TYPE *pType);
        
        HRESULT ( STDMETHODCALLTYPE *CompareItem )( 
            IMFSpatialAudioSample * This,
            REFGUID guidKey,
            REFPROPVARIANT Value,
            /* [annotation][out] */ 
            _Out_  BOOL *pbResult);
        
        HRESULT ( STDMETHODCALLTYPE *Compare )( 
            IMFSpatialAudioSample * This,
            IMFAttributes *pTheirs,
            MF_ATTRIBUTES_MATCH_TYPE MatchType,
            /* [annotation][out] */ 
            _Out_  BOOL *pbResult);
        
        HRESULT ( STDMETHODCALLTYPE *GetUINT32 )( 
            IMFSpatialAudioSample * This,
            REFGUID guidKey,
            /* [annotation][out] */ 
            _Out_  UINT32 *punValue);
        
        HRESULT ( STDMETHODCALLTYPE *GetUINT64 )( 
            IMFSpatialAudioSample * This,
            REFGUID guidKey,
            /* [annotation][out] */ 
            _Out_  UINT64 *punValue);
        
        HRESULT ( STDMETHODCALLTYPE *GetDouble )( 
            IMFSpatialAudioSample * This,
            REFGUID guidKey,
            /* [annotation][out] */ 
            _Out_  double *pfValue);
        
        HRESULT ( STDMETHODCALLTYPE *GetGUID )( 
            IMFSpatialAudioSample * This,
            REFGUID guidKey,
            /* [annotation][out] */ 
            _Out_  GUID *pguidValue);
        
        HRESULT ( STDMETHODCALLTYPE *GetStringLength )( 
            IMFSpatialAudioSample * This,
            REFGUID guidKey,
            /* [annotation][out] */ 
            _Out_  UINT32 *pcchLength);
        
        HRESULT ( STDMETHODCALLTYPE *GetString )( 
            IMFSpatialAudioSample * This,
            REFGUID guidKey,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cchBufSize)  LPWSTR pwszValue,
            UINT32 cchBufSize,
            /* [full][out][in] */ UINT32 *pcchLength);
        
        HRESULT ( STDMETHODCALLTYPE *GetAllocatedString )( 
            IMFSpatialAudioSample * This,
            REFGUID guidKey,
            /* [annotation][size_is][size_is][out] */ 
            _Out_writes_(*pcchLength + 1)  LPWSTR *ppwszValue,
            /* [annotation][out] */ 
            _Out_  UINT32 *pcchLength);
        
        HRESULT ( STDMETHODCALLTYPE *GetBlobSize )( 
            IMFSpatialAudioSample * This,
            REFGUID guidKey,
            /* [annotation][out] */ 
            _Out_  UINT32 *pcbBlobSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetBlob )( 
            IMFSpatialAudioSample * This,
            REFGUID guidKey,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cbBufSize)  UINT8 *pBuf,
            UINT32 cbBufSize,
            /* [full][out][in] */ UINT32 *pcbBlobSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetAllocatedBlob )( 
            IMFSpatialAudioSample * This,
            REFGUID guidKey,
            /* [annotation][size_is][size_is][out] */ 
            _Out_writes_(*pcbSize)  UINT8 **ppBuf,
            /* [annotation][out] */ 
            _Out_  UINT32 *pcbSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetUnknown )( 
            IMFSpatialAudioSample * This,
            REFGUID guidKey,
            REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  LPVOID *ppv);
        
        HRESULT ( STDMETHODCALLTYPE *SetItem )( 
            IMFSpatialAudioSample * This,
            REFGUID guidKey,
            REFPROPVARIANT Value);
        
        HRESULT ( STDMETHODCALLTYPE *DeleteItem )( 
            IMFSpatialAudioSample * This,
            REFGUID guidKey);
        
        HRESULT ( STDMETHODCALLTYPE *DeleteAllItems )( 
            IMFSpatialAudioSample * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetUINT32 )( 
            IMFSpatialAudioSample * This,
            REFGUID guidKey,
            UINT32 unValue);
        
        HRESULT ( STDMETHODCALLTYPE *SetUINT64 )( 
            IMFSpatialAudioSample * This,
            REFGUID guidKey,
            UINT64 unValue);
        
        HRESULT ( STDMETHODCALLTYPE *SetDouble )( 
            IMFSpatialAudioSample * This,
            REFGUID guidKey,
            double fValue);
        
        HRESULT ( STDMETHODCALLTYPE *SetGUID )( 
            IMFSpatialAudioSample * This,
            REFGUID guidKey,
            REFGUID guidValue);
        
        HRESULT ( STDMETHODCALLTYPE *SetString )( 
            IMFSpatialAudioSample * This,
            REFGUID guidKey,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR wszValue);
        
        HRESULT ( STDMETHODCALLTYPE *SetBlob )( 
            IMFSpatialAudioSample * This,
            REFGUID guidKey,
            /* [annotation][size_is][in] */ 
            _In_reads_(cbBufSize)  const UINT8 *pBuf,
            UINT32 cbBufSize);
        
        HRESULT ( STDMETHODCALLTYPE *SetUnknown )( 
            IMFSpatialAudioSample * This,
            REFGUID guidKey,
            /* [annotation][in] */ 
            _In_  IUnknown *pUnknown);
        
        HRESULT ( STDMETHODCALLTYPE *LockStore )( 
            IMFSpatialAudioSample * This);
        
        HRESULT ( STDMETHODCALLTYPE *UnlockStore )( 
            IMFSpatialAudioSample * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetCount )( 
            IMFSpatialAudioSample * This,
            /* [annotation][out] */ 
            _Out_  UINT32 *pcItems);
        
        HRESULT ( STDMETHODCALLTYPE *GetItemByIndex )( 
            IMFSpatialAudioSample * This,
            UINT32 unIndex,
            /* [annotation][out] */ 
            _Out_  GUID *pguidKey,
            /* [full][out][in] */ PROPVARIANT *pValue);
        
        HRESULT ( STDMETHODCALLTYPE *CopyAllItems )( 
            IMFSpatialAudioSample * This,
            /* [annotation][in] */ 
            _In_  IMFAttributes *pDest);
        
        HRESULT ( STDMETHODCALLTYPE *GetSampleFlags )( 
            IMFSpatialAudioSample * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwSampleFlags);
        
        HRESULT ( STDMETHODCALLTYPE *SetSampleFlags )( 
            IMFSpatialAudioSample * This,
            /* [annotation][in] */ 
            _In_  DWORD dwSampleFlags);
        
        HRESULT ( STDMETHODCALLTYPE *GetSampleTime )( 
            IMFSpatialAudioSample * This,
            /* [annotation][out] */ 
            _Out_  LONGLONG *phnsSampleTime);
        
        HRESULT ( STDMETHODCALLTYPE *SetSampleTime )( 
            IMFSpatialAudioSample * This,
            /* [annotation][in] */ 
            _In_  LONGLONG hnsSampleTime);
        
        HRESULT ( STDMETHODCALLTYPE *GetSampleDuration )( 
            IMFSpatialAudioSample * This,
            /* [annotation][out] */ 
            _Out_  LONGLONG *phnsSampleDuration);
        
        HRESULT ( STDMETHODCALLTYPE *SetSampleDuration )( 
            IMFSpatialAudioSample * This,
            /* [annotation][in] */ 
            _In_  LONGLONG hnsSampleDuration);
        
        HRESULT ( STDMETHODCALLTYPE *GetBufferCount )( 
            IMFSpatialAudioSample * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwBufferCount);
        
        HRESULT ( STDMETHODCALLTYPE *GetBufferByIndex )( 
            IMFSpatialAudioSample * This,
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][out] */ 
            _Out_  IMFMediaBuffer **ppBuffer);
        
        HRESULT ( STDMETHODCALLTYPE *ConvertToContiguousBuffer )( 
            IMFSpatialAudioSample * This,
            /* [annotation][out] */ 
            _Out_  IMFMediaBuffer **ppBuffer);
        
        HRESULT ( STDMETHODCALLTYPE *AddBuffer )( 
            IMFSpatialAudioSample * This,
            /* [annotation][in] */ 
            _In_  IMFMediaBuffer *pBuffer);
        
        HRESULT ( STDMETHODCALLTYPE *RemoveBufferByIndex )( 
            IMFSpatialAudioSample * This,
            /* [annotation][in] */ 
            _In_  DWORD dwIndex);
        
        HRESULT ( STDMETHODCALLTYPE *RemoveAllBuffers )( 
            IMFSpatialAudioSample * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTotalLength )( 
            IMFSpatialAudioSample * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pcbTotalLength);
        
        HRESULT ( STDMETHODCALLTYPE *CopyToBuffer )( 
            IMFSpatialAudioSample * This,
            /* [annotation][in] */ 
            _In_  IMFMediaBuffer *pBuffer);
        
        HRESULT ( STDMETHODCALLTYPE *GetObjectCount )( 
            IMFSpatialAudioSample * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwObjectCount);
        
        HRESULT ( STDMETHODCALLTYPE *AddSpatialAudioObject )( 
            IMFSpatialAudioSample * This,
            /* [annotation][in] */ 
            _In_  IMFSpatialAudioObjectBuffer *pAudioObjBuffer);
        
        HRESULT ( STDMETHODCALLTYPE *GetSpatialAudioObjectByIndex )( 
            IMFSpatialAudioSample * This,
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][out] */ 
            _COM_Outptr_  IMFSpatialAudioObjectBuffer **ppAudioObjBuffer);
        
        END_INTERFACE
    } IMFSpatialAudioSampleVtbl;

    interface IMFSpatialAudioSample
    {
        CONST_VTBL struct IMFSpatialAudioSampleVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMFSpatialAudioSample_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMFSpatialAudioSample_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMFSpatialAudioSample_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMFSpatialAudioSample_GetItem(This,guidKey,pValue)	\
    ( (This)->lpVtbl -> GetItem(This,guidKey,pValue) ) 

#define IMFSpatialAudioSample_GetItemType(This,guidKey,pType)	\
    ( (This)->lpVtbl -> GetItemType(This,guidKey,pType) ) 

#define IMFSpatialAudioSample_CompareItem(This,guidKey,Value,pbResult)	\
    ( (This)->lpVtbl -> CompareItem(This,guidKey,Value,pbResult) ) 

#define IMFSpatialAudioSample_Compare(This,pTheirs,MatchType,pbResult)	\
    ( (This)->lpVtbl -> Compare(This,pTheirs,MatchType,pbResult) ) 

#define IMFSpatialAudioSample_GetUINT32(This,guidKey,punValue)	\
    ( (This)->lpVtbl -> GetUINT32(This,guidKey,punValue) ) 

#define IMFSpatialAudioSample_GetUINT64(This,guidKey,punValue)	\
    ( (This)->lpVtbl -> GetUINT64(This,guidKey,punValue) ) 

#define IMFSpatialAudioSample_GetDouble(This,guidKey,pfValue)	\
    ( (This)->lpVtbl -> GetDouble(This,guidKey,pfValue) ) 

#define IMFSpatialAudioSample_GetGUID(This,guidKey,pguidValue)	\
    ( (This)->lpVtbl -> GetGUID(This,guidKey,pguidValue) ) 

#define IMFSpatialAudioSample_GetStringLength(This,guidKey,pcchLength)	\
    ( (This)->lpVtbl -> GetStringLength(This,guidKey,pcchLength) ) 

#define IMFSpatialAudioSample_GetString(This,guidKey,pwszValue,cchBufSize,pcchLength)	\
    ( (This)->lpVtbl -> GetString(This,guidKey,pwszValue,cchBufSize,pcchLength) ) 

#define IMFSpatialAudioSample_GetAllocatedString(This,guidKey,ppwszValue,pcchLength)	\
    ( (This)->lpVtbl -> GetAllocatedString(This,guidKey,ppwszValue,pcchLength) ) 

#define IMFSpatialAudioSample_GetBlobSize(This,guidKey,pcbBlobSize)	\
    ( (This)->lpVtbl -> GetBlobSize(This,guidKey,pcbBlobSize) ) 

#define IMFSpatialAudioSample_GetBlob(This,guidKey,pBuf,cbBufSize,pcbBlobSize)	\
    ( (This)->lpVtbl -> GetBlob(This,guidKey,pBuf,cbBufSize,pcbBlobSize) ) 

#define IMFSpatialAudioSample_GetAllocatedBlob(This,guidKey,ppBuf,pcbSize)	\
    ( (This)->lpVtbl -> GetAllocatedBlob(This,guidKey,ppBuf,pcbSize) ) 

#define IMFSpatialAudioSample_GetUnknown(This,guidKey,riid,ppv)	\
    ( (This)->lpVtbl -> GetUnknown(This,guidKey,riid,ppv) ) 

#define IMFSpatialAudioSample_SetItem(This,guidKey,Value)	\
    ( (This)->lpVtbl -> SetItem(This,guidKey,Value) ) 

#define IMFSpatialAudioSample_DeleteItem(This,guidKey)	\
    ( (This)->lpVtbl -> DeleteItem(This,guidKey) ) 

#define IMFSpatialAudioSample_DeleteAllItems(This)	\
    ( (This)->lpVtbl -> DeleteAllItems(This) ) 

#define IMFSpatialAudioSample_SetUINT32(This,guidKey,unValue)	\
    ( (This)->lpVtbl -> SetUINT32(This,guidKey,unValue) ) 

#define IMFSpatialAudioSample_SetUINT64(This,guidKey,unValue)	\
    ( (This)->lpVtbl -> SetUINT64(This,guidKey,unValue) ) 

#define IMFSpatialAudioSample_SetDouble(This,guidKey,fValue)	\
    ( (This)->lpVtbl -> SetDouble(This,guidKey,fValue) ) 

#define IMFSpatialAudioSample_SetGUID(This,guidKey,guidValue)	\
    ( (This)->lpVtbl -> SetGUID(This,guidKey,guidValue) ) 

#define IMFSpatialAudioSample_SetString(This,guidKey,wszValue)	\
    ( (This)->lpVtbl -> SetString(This,guidKey,wszValue) ) 

#define IMFSpatialAudioSample_SetBlob(This,guidKey,pBuf,cbBufSize)	\
    ( (This)->lpVtbl -> SetBlob(This,guidKey,pBuf,cbBufSize) ) 

#define IMFSpatialAudioSample_SetUnknown(This,guidKey,pUnknown)	\
    ( (This)->lpVtbl -> SetUnknown(This,guidKey,pUnknown) ) 

#define IMFSpatialAudioSample_LockStore(This)	\
    ( (This)->lpVtbl -> LockStore(This) ) 

#define IMFSpatialAudioSample_UnlockStore(This)	\
    ( (This)->lpVtbl -> UnlockStore(This) ) 

#define IMFSpatialAudioSample_GetCount(This,pcItems)	\
    ( (This)->lpVtbl -> GetCount(This,pcItems) ) 

#define IMFSpatialAudioSample_GetItemByIndex(This,unIndex,pguidKey,pValue)	\
    ( (This)->lpVtbl -> GetItemByIndex(This,unIndex,pguidKey,pValue) ) 

#define IMFSpatialAudioSample_CopyAllItems(This,pDest)	\
    ( (This)->lpVtbl -> CopyAllItems(This,pDest) ) 


#define IMFSpatialAudioSample_GetSampleFlags(This,pdwSampleFlags)	\
    ( (This)->lpVtbl -> GetSampleFlags(This,pdwSampleFlags) ) 

#define IMFSpatialAudioSample_SetSampleFlags(This,dwSampleFlags)	\
    ( (This)->lpVtbl -> SetSampleFlags(This,dwSampleFlags) ) 

#define IMFSpatialAudioSample_GetSampleTime(This,phnsSampleTime)	\
    ( (This)->lpVtbl -> GetSampleTime(This,phnsSampleTime) ) 

#define IMFSpatialAudioSample_SetSampleTime(This,hnsSampleTime)	\
    ( (This)->lpVtbl -> SetSampleTime(This,hnsSampleTime) ) 

#define IMFSpatialAudioSample_GetSampleDuration(This,phnsSampleDuration)	\
    ( (This)->lpVtbl -> GetSampleDuration(This,phnsSampleDuration) ) 

#define IMFSpatialAudioSample_SetSampleDuration(This,hnsSampleDuration)	\
    ( (This)->lpVtbl -> SetSampleDuration(This,hnsSampleDuration) ) 

#define IMFSpatialAudioSample_GetBufferCount(This,pdwBufferCount)	\
    ( (This)->lpVtbl -> GetBufferCount(This,pdwBufferCount) ) 

#define IMFSpatialAudioSample_GetBufferByIndex(This,dwIndex,ppBuffer)	\
    ( (This)->lpVtbl -> GetBufferByIndex(This,dwIndex,ppBuffer) ) 

#define IMFSpatialAudioSample_ConvertToContiguousBuffer(This,ppBuffer)	\
    ( (This)->lpVtbl -> ConvertToContiguousBuffer(This,ppBuffer) ) 

#define IMFSpatialAudioSample_AddBuffer(This,pBuffer)	\
    ( (This)->lpVtbl -> AddBuffer(This,pBuffer) ) 

#define IMFSpatialAudioSample_RemoveBufferByIndex(This,dwIndex)	\
    ( (This)->lpVtbl -> RemoveBufferByIndex(This,dwIndex) ) 

#define IMFSpatialAudioSample_RemoveAllBuffers(This)	\
    ( (This)->lpVtbl -> RemoveAllBuffers(This) ) 

#define IMFSpatialAudioSample_GetTotalLength(This,pcbTotalLength)	\
    ( (This)->lpVtbl -> GetTotalLength(This,pcbTotalLength) ) 

#define IMFSpatialAudioSample_CopyToBuffer(This,pBuffer)	\
    ( (This)->lpVtbl -> CopyToBuffer(This,pBuffer) ) 


#define IMFSpatialAudioSample_GetObjectCount(This,pdwObjectCount)	\
    ( (This)->lpVtbl -> GetObjectCount(This,pdwObjectCount) ) 

#define IMFSpatialAudioSample_AddSpatialAudioObject(This,pAudioObjBuffer)	\
    ( (This)->lpVtbl -> AddSpatialAudioObject(This,pAudioObjBuffer) ) 

#define IMFSpatialAudioSample_GetSpatialAudioObjectByIndex(This,dwIndex,ppAudioObjBuffer)	\
    ( (This)->lpVtbl -> GetSpatialAudioObjectByIndex(This,dwIndex,ppAudioObjBuffer) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMFSpatialAudioSample_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_mfspatialaudio_0000_0002 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP) */


extern RPC_IF_HANDLE __MIDL_itf_mfspatialaudio_0000_0002_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_mfspatialaudio_0000_0002_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


