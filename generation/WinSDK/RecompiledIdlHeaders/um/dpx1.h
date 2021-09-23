

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

#ifndef __dpx1_h__
#define __dpx1_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IDpxJob_FWD_DEFINED__
#define __IDpxJob_FWD_DEFINED__
typedef interface IDpxJob IDpxJob;

#endif 	/* __IDpxJob_FWD_DEFINED__ */


#ifndef __IFileHashProviderCallback_FWD_DEFINED__
#define __IFileHashProviderCallback_FWD_DEFINED__
typedef interface IFileHashProviderCallback IFileHashProviderCallback;

#endif 	/* __IFileHashProviderCallback_FWD_DEFINED__ */


#ifndef __IDpxJob2_FWD_DEFINED__
#define __IDpxJob2_FWD_DEFINED__
typedef interface IDpxJob2 IDpxJob2;

#endif 	/* __IDpxJob2_FWD_DEFINED__ */


#ifndef __IDpxContainer_FWD_DEFINED__
#define __IDpxContainer_FWD_DEFINED__
typedef interface IDpxContainer IDpxContainer;

#endif 	/* __IDpxContainer_FWD_DEFINED__ */


#ifndef __IDpxFile_FWD_DEFINED__
#define __IDpxFile_FWD_DEFINED__
typedef interface IDpxFile IDpxFile;

#endif 	/* __IDpxFile_FWD_DEFINED__ */


#ifndef __IDpxFile2_FWD_DEFINED__
#define __IDpxFile2_FWD_DEFINED__
typedef interface IDpxFile2 IDpxFile2;

#endif 	/* __IDpxFile2_FWD_DEFINED__ */


#ifndef __IDpxContainerDirectoryEntry_FWD_DEFINED__
#define __IDpxContainerDirectoryEntry_FWD_DEFINED__
typedef interface IDpxContainerDirectoryEntry IDpxContainerDirectoryEntry;

#endif 	/* __IDpxContainerDirectoryEntry_FWD_DEFINED__ */


#ifndef __IDpxDownloadProvider_FWD_DEFINED__
#define __IDpxDownloadProvider_FWD_DEFINED__
typedef interface IDpxDownloadProvider IDpxDownloadProvider;

#endif 	/* __IDpxDownloadProvider_FWD_DEFINED__ */


#ifndef __IDpxDownloadCallback_FWD_DEFINED__
#define __IDpxDownloadCallback_FWD_DEFINED__
typedef interface IDpxDownloadCallback IDpxDownloadCallback;

#endif 	/* __IDpxDownloadCallback_FWD_DEFINED__ */


#ifndef __IEnumDpxContainers_FWD_DEFINED__
#define __IEnumDpxContainers_FWD_DEFINED__
typedef interface IEnumDpxContainers IEnumDpxContainers;

#endif 	/* __IEnumDpxContainers_FWD_DEFINED__ */


#ifndef __IEnumDpxFiles_FWD_DEFINED__
#define __IEnumDpxFiles_FWD_DEFINED__
typedef interface IEnumDpxFiles IEnumDpxFiles;

#endif 	/* __IEnumDpxFiles_FWD_DEFINED__ */


#ifndef __IEnumDpxContainerDirectoryEntries_FWD_DEFINED__
#define __IEnumDpxContainerDirectoryEntries_FWD_DEFINED__
typedef interface IEnumDpxContainerDirectoryEntries IEnumDpxContainerDirectoryEntries;

#endif 	/* __IEnumDpxContainerDirectoryEntries_FWD_DEFINED__ */


#ifndef __IDpxEncryptedContainer_FWD_DEFINED__
#define __IDpxEncryptedContainer_FWD_DEFINED__
typedef interface IDpxEncryptedContainer IDpxEncryptedContainer;

#endif 	/* __IDpxEncryptedContainer_FWD_DEFINED__ */


#ifndef __IDpxContainer2_FWD_DEFINED__
#define __IDpxContainer2_FWD_DEFINED__
typedef interface IDpxContainer2 IDpxContainer2;

#endif 	/* __IDpxContainer2_FWD_DEFINED__ */


#ifndef __IDpxContainer3_FWD_DEFINED__
#define __IDpxContainer3_FWD_DEFINED__
typedef interface IDpxContainer3 IDpxContainer3;

#endif 	/* __IDpxContainer3_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_dpx1_0000_0000 */
/* [local] */ 

// Copyright (c) Microsoft Corporation.  All rights reserved.

#include <winapifamily.h>
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
#include <SpecStrings.h>
typedef unsigned int ALG_ID;










typedef unsigned int LOCATIONTYPE;

#define	LOCATIONTYPE_UNKNOWN	( 0 )

#define	LOCATIONTYPE_NONE	( 0x1000000 )

#define	LOCATIONTYPE_LOCAL	( 0x2000000 )

#define	LOCATIONTYPE_CAB	( 0x3000000 )

#define	LOCATIONTYPE_CMI	( 0x4000000 )

#define	LOCATIONTYPE__MASK_FLAGS	( 0xffff )

#define	LOCATIONTYPE_RECURSIVE	( 0x1 )

#define	LOCATIONTYPE_ABSOLUTE	( 0x2 )

#define	LOCATIONTYPE_COMPRESSED	( 0x4 )

#define	LOCATIONTYPE_IGNORE	( 0x8 )

#define	LOCATIONTYPE_DUPLICATE	( 0x10 )

#define	LOCATIONTYPE_INTERMEDIATE	( 0x20 )

#define	LOCATIONTYPE__MASK_TYPE	( 0xffff0000 )

typedef /* [public][public] */ 
enum __MIDL___MIDL_itf_dpx1_0000_0000_0001
    {
        DPX_RESUME_AND_DOWNLOAD	= 0,
        DPX_RESUME_UNTIL_DOWNLOAD	= 0x1,
        DPX_RESUME_AND_DOWNLOAD_FALLBACK	= 0x2,
        DPX_RESUME_UNTIL_DOWNLOAD_NO_CLONE	= 0x3
    } 	DPX_RESUME_TYPE;

#define DPX_MAX_HASH_SIZE 64
typedef /* [public][public][public][public][public][public][public] */ struct __MIDL___MIDL_itf_dpx1_0000_0000_0002
    {
    ALG_ID AlgorithmId;
    UINT HashSize;
    /* [length_is] */ BYTE HashData[ 64 ];
    } 	DPX_HASH;

typedef /* [public][public][public][public][public] */ struct __MIDL___MIDL_itf_dpx1_0000_0000_0003
    {
    UINT64 Offset;
    UINT64 Length;
    } 	DPX_BYTE_RANGE;

typedef /* [public][public][public] */ 
enum __MIDL___MIDL_itf_dpx1_0000_0000_0004
    {
        DPX_PHASE_JOB_IDLE	= 0,
        DPX_PHASE_DOWNLOAD_INDEX	= 0x10,
        DPX_PHASE_INVENTORY	= 0x20,
        DPX_PHASE_DOWNLOAD_FILES	= 0x30,
        DPX_PHASE_EXPAND_FILES	= 0x40,
        DPX_PHASE_JOB_INPROGRESS	= 0x50,
        DPX_PHASE_JOB_COMPLETE	= 0x7f00,
        DPX_PHASE_JOB_CANCELLED	= 0xfffe,
        DPX_PHASE_JOB_FAILURE	= 0xffff
    } 	DPX_PROGRESS_PHASE;

typedef /* [public][public][public][public][public][public][public][public][public][public][public][public] */ struct __MIDL___MIDL_itf_dpx1_0000_0000_0005
    {
    UINT64 Completed;
    UINT64 Remaining;
    } 	DPX_PROGRESS_REMAIN;

typedef /* [public][public] */ struct __MIDL___MIDL_itf_dpx1_0000_0000_0006
    {
    DPX_PROGRESS_REMAIN Inventory;
    DPX_PROGRESS_REMAIN Download;
    DPX_PROGRESS_REMAIN Expansion;
    DPX_PROGRESS_REMAIN Files;
    DPX_PROGRESS_REMAIN Overall;
    DPX_PROGRESS_PHASE ePhase;
    } 	DPX_PROGRESS;

#define DPX_OPTION_DELTA_BASIS_ROOT L"delta_basis_root"
#define DPX_COMPRESSION_ALGORITHM_OPTION_NAME L"postprocess_compression_algorithm"
#define DPX_CLEANUP_OPTION_NAME L"postprocess_source_cleanup"
#define DPX_COMPRESSION_ALGORITHM_XPRESS_HUFF L"xpress_huff"
#define DPX_COMPRESSION_ALGORITHM_WOF_PROVIDER_FILE L"wof_provider_file"
#define DPX_COMPRESSED_FILE_HEADER_LENGTH 4
#define DPX_COMPRESSED_FILE_HEADER_XPRESS_HUFF {'D', 'C', 'X', '\x01'}
#define DPX_XPRESS_HUFF_BLOCK_SIZE (1024 * 1024)
#define DPX_OPTION_TELEMETRY_CORRELATION_VECTOR L"Telemetry_correlation_vector"
#define DPX_OPTION_HASH_TYPE L"cix_hash_type"
#define DPX_OPTION_HARDLINK_ASSETS L"hardlink_assets"
#define DPX_OPTION_COMPLETE_SELF_COPIES L"complete_self_copies"


extern RPC_IF_HANDLE __MIDL_itf_dpx1_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_dpx1_0000_0000_v0_0_s_ifspec;

#ifndef __IDpxJob_INTERFACE_DEFINED__
#define __IDpxJob_INTERFACE_DEFINED__

/* interface IDpxJob */
/* [unique][object][uuid] */ 


EXTERN_C const IID IID_IDpxJob;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("ddc1b711-0e55-452f-838e-d1505b866e2b")
    IDpxJob : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetTargetPath( 
            /* [annotation][out] */ 
            _Out_  LPWSTR *TargetPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddContainer( 
            /* [annotation][in] */ 
            _In_  LPCWSTR ContainerPath,
            /* [annotation][out] */ 
            _Out_  IDpxContainer **ppContainer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumContainers( 
            /* [annotation][out] */ 
            _Out_  IEnumDpxContainers **ppEnumContainers) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDownloadProvider( 
            /* [annotation][unique][in] */ 
            _In_  IDpxDownloadProvider *pDownloadProvider) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDownloadProvider( 
            /* [annotation][out] */ 
            _Out_  IDpxDownloadProvider **ppDownloadProvider) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Resume( 
            DPX_RESUME_TYPE eResumeType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Suspend( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Cancel( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetProgress( 
            /* [annotation][out] */ 
            _Out_  DPX_PROGRESS *pProgress) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SaveJobState( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetUserValue( 
            /* [annotation][in] */ 
            _In_  UINT64 UserValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetUserValue( 
            /* [annotation][out] */ 
            _Out_  UINT64 *pUserValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetOptionValue( 
            /* [annotation][in] */ 
            _In_  LPCWSTR OptionName,
            /* [annotation][unique][in] */ 
            _In_  LPCWSTR OptionValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetOptionValue( 
            /* [annotation][in] */ 
            _In_  LPCWSTR OptionName,
            /* [annotation][out] */ 
            _Out_  LPWSTR *pOptionValue) = 0;
        
        virtual /* [local] */ void STDMETHODCALLTYPE FreeMemory( 
            /* [annotation][in] */ 
            _In_  void *Allocation) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IDpxJobVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IDpxJob * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IDpxJob * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IDpxJob * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTargetPath )( 
            __RPC__in IDpxJob * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *TargetPath);
        
        HRESULT ( STDMETHODCALLTYPE *AddContainer )( 
            __RPC__in IDpxJob * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR ContainerPath,
            /* [annotation][out] */ 
            _Out_  IDpxContainer **ppContainer);
        
        HRESULT ( STDMETHODCALLTYPE *EnumContainers )( 
            __RPC__in IDpxJob * This,
            /* [annotation][out] */ 
            _Out_  IEnumDpxContainers **ppEnumContainers);
        
        HRESULT ( STDMETHODCALLTYPE *SetDownloadProvider )( 
            __RPC__in IDpxJob * This,
            /* [annotation][unique][in] */ 
            _In_  IDpxDownloadProvider *pDownloadProvider);
        
        HRESULT ( STDMETHODCALLTYPE *GetDownloadProvider )( 
            __RPC__in IDpxJob * This,
            /* [annotation][out] */ 
            _Out_  IDpxDownloadProvider **ppDownloadProvider);
        
        HRESULT ( STDMETHODCALLTYPE *Resume )( 
            __RPC__in IDpxJob * This,
            DPX_RESUME_TYPE eResumeType);
        
        HRESULT ( STDMETHODCALLTYPE *Suspend )( 
            __RPC__in IDpxJob * This);
        
        HRESULT ( STDMETHODCALLTYPE *Cancel )( 
            __RPC__in IDpxJob * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetProgress )( 
            __RPC__in IDpxJob * This,
            /* [annotation][out] */ 
            _Out_  DPX_PROGRESS *pProgress);
        
        HRESULT ( STDMETHODCALLTYPE *SaveJobState )( 
            __RPC__in IDpxJob * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetUserValue )( 
            __RPC__in IDpxJob * This,
            /* [annotation][in] */ 
            _In_  UINT64 UserValue);
        
        HRESULT ( STDMETHODCALLTYPE *GetUserValue )( 
            __RPC__in IDpxJob * This,
            /* [annotation][out] */ 
            _Out_  UINT64 *pUserValue);
        
        HRESULT ( STDMETHODCALLTYPE *SetOptionValue )( 
            __RPC__in IDpxJob * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR OptionName,
            /* [annotation][unique][in] */ 
            _In_  LPCWSTR OptionValue);
        
        HRESULT ( STDMETHODCALLTYPE *GetOptionValue )( 
            __RPC__in IDpxJob * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR OptionName,
            /* [annotation][out] */ 
            _Out_  LPWSTR *pOptionValue);
        
        /* [local] */ void ( STDMETHODCALLTYPE *FreeMemory )( 
            IDpxJob * This,
            /* [annotation][in] */ 
            _In_  void *Allocation);
        
        END_INTERFACE
    } IDpxJobVtbl;

    interface IDpxJob
    {
        CONST_VTBL struct IDpxJobVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDpxJob_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDpxJob_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDpxJob_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDpxJob_GetTargetPath(This,TargetPath)	\
    ( (This)->lpVtbl -> GetTargetPath(This,TargetPath) ) 

#define IDpxJob_AddContainer(This,ContainerPath,ppContainer)	\
    ( (This)->lpVtbl -> AddContainer(This,ContainerPath,ppContainer) ) 

#define IDpxJob_EnumContainers(This,ppEnumContainers)	\
    ( (This)->lpVtbl -> EnumContainers(This,ppEnumContainers) ) 

#define IDpxJob_SetDownloadProvider(This,pDownloadProvider)	\
    ( (This)->lpVtbl -> SetDownloadProvider(This,pDownloadProvider) ) 

#define IDpxJob_GetDownloadProvider(This,ppDownloadProvider)	\
    ( (This)->lpVtbl -> GetDownloadProvider(This,ppDownloadProvider) ) 

#define IDpxJob_Resume(This,eResumeType)	\
    ( (This)->lpVtbl -> Resume(This,eResumeType) ) 

#define IDpxJob_Suspend(This)	\
    ( (This)->lpVtbl -> Suspend(This) ) 

#define IDpxJob_Cancel(This)	\
    ( (This)->lpVtbl -> Cancel(This) ) 

#define IDpxJob_GetProgress(This,pProgress)	\
    ( (This)->lpVtbl -> GetProgress(This,pProgress) ) 

#define IDpxJob_SaveJobState(This)	\
    ( (This)->lpVtbl -> SaveJobState(This) ) 

#define IDpxJob_SetUserValue(This,UserValue)	\
    ( (This)->lpVtbl -> SetUserValue(This,UserValue) ) 

#define IDpxJob_GetUserValue(This,pUserValue)	\
    ( (This)->lpVtbl -> GetUserValue(This,pUserValue) ) 

#define IDpxJob_SetOptionValue(This,OptionName,OptionValue)	\
    ( (This)->lpVtbl -> SetOptionValue(This,OptionName,OptionValue) ) 

#define IDpxJob_GetOptionValue(This,OptionName,pOptionValue)	\
    ( (This)->lpVtbl -> GetOptionValue(This,OptionName,pOptionValue) ) 

#define IDpxJob_FreeMemory(This,Allocation)	\
    ( (This)->lpVtbl -> FreeMemory(This,Allocation) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDpxJob_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_dpx1_0000_0001 */
/* [local] */ 

#ifdef __cplusplus
enum class DPX_FILE_PROVIDER_QUERY_DISPOSITION
{
    Invalid = 0,
    Success = 1,
    Compressed = 2
};
#else
typedef 
enum tagDPX_FILE_PROVIDER_QUERY_DISPOSITION
    {
        DPX_FILE_PROVIDER_QUERY_DISPOSITION_INVALID	= 0,
        DPX_FILE_PROVIDER_QUERY_DISPOSITION_SUCCESS	= 1,
        DPX_FILE_PROVIDER_QUERY_DISPOSITION_COMPRESSED	= 2
    } 	DPX_FILE_PROVIDER_QUERY_DISPOSITION;

#endif


extern RPC_IF_HANDLE __MIDL_itf_dpx1_0000_0001_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_dpx1_0000_0001_v0_0_s_ifspec;

#ifndef __IFileHashProviderCallback_INTERFACE_DEFINED__
#define __IFileHashProviderCallback_INTERFACE_DEFINED__

/* interface IFileHashProviderCallback */
/* [unique][object][uuid] */ 


EXTERN_C const IID IID_IFileHashProviderCallback;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("e9a288f7-bcfb-4466-95c6-5a388263d8fb")
    IFileHashProviderCallback : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetFileHash( 
            /* [annotation][in] */ 
            _In_  LPCWSTR FilePath,
            /* [annotation][in] */ 
            _In_  ALG_ID algId,
            /* [annotation][out] */ 
            _Out_  DPX_FILE_PROVIDER_QUERY_DISPOSITION *pDisposition,
            /* [annotation][in] */ 
            _In_  UINT cbHashData,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cbHashData)  BYTE pbHashData[  ]) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IFileHashProviderCallbackVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IFileHashProviderCallback * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IFileHashProviderCallback * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IFileHashProviderCallback * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetFileHash )( 
            __RPC__in IFileHashProviderCallback * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR FilePath,
            /* [annotation][in] */ 
            _In_  ALG_ID algId,
            /* [annotation][out] */ 
            _Out_  DPX_FILE_PROVIDER_QUERY_DISPOSITION *pDisposition,
            /* [annotation][in] */ 
            _In_  UINT cbHashData,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cbHashData)  BYTE pbHashData[  ]);
        
        END_INTERFACE
    } IFileHashProviderCallbackVtbl;

    interface IFileHashProviderCallback
    {
        CONST_VTBL struct IFileHashProviderCallbackVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFileHashProviderCallback_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFileHashProviderCallback_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFileHashProviderCallback_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFileHashProviderCallback_GetFileHash(This,FilePath,algId,pDisposition,cbHashData,pbHashData)	\
    ( (This)->lpVtbl -> GetFileHash(This,FilePath,algId,pDisposition,cbHashData,pbHashData) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFileHashProviderCallback_INTERFACE_DEFINED__ */


#ifndef __IDpxJob2_INTERFACE_DEFINED__
#define __IDpxJob2_INTERFACE_DEFINED__

/* interface IDpxJob2 */
/* [unique][object][uuid] */ 


EXTERN_C const IID IID_IDpxJob2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("e1c292c8-919a-4f1b-b85a-9c542932fc8d")
    IDpxJob2 : public IDpxJob
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetInventoryProvider( 
            /* [annotation][in] */ 
            _In_  LOCATIONTYPE locationType,
            /* [annotation][in] */ 
            _In_  IFileHashProviderCallback *pProvider) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IDpxJob2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IDpxJob2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IDpxJob2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IDpxJob2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTargetPath )( 
            __RPC__in IDpxJob2 * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *TargetPath);
        
        HRESULT ( STDMETHODCALLTYPE *AddContainer )( 
            __RPC__in IDpxJob2 * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR ContainerPath,
            /* [annotation][out] */ 
            _Out_  IDpxContainer **ppContainer);
        
        HRESULT ( STDMETHODCALLTYPE *EnumContainers )( 
            __RPC__in IDpxJob2 * This,
            /* [annotation][out] */ 
            _Out_  IEnumDpxContainers **ppEnumContainers);
        
        HRESULT ( STDMETHODCALLTYPE *SetDownloadProvider )( 
            __RPC__in IDpxJob2 * This,
            /* [annotation][unique][in] */ 
            _In_  IDpxDownloadProvider *pDownloadProvider);
        
        HRESULT ( STDMETHODCALLTYPE *GetDownloadProvider )( 
            __RPC__in IDpxJob2 * This,
            /* [annotation][out] */ 
            _Out_  IDpxDownloadProvider **ppDownloadProvider);
        
        HRESULT ( STDMETHODCALLTYPE *Resume )( 
            __RPC__in IDpxJob2 * This,
            DPX_RESUME_TYPE eResumeType);
        
        HRESULT ( STDMETHODCALLTYPE *Suspend )( 
            __RPC__in IDpxJob2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *Cancel )( 
            __RPC__in IDpxJob2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetProgress )( 
            __RPC__in IDpxJob2 * This,
            /* [annotation][out] */ 
            _Out_  DPX_PROGRESS *pProgress);
        
        HRESULT ( STDMETHODCALLTYPE *SaveJobState )( 
            __RPC__in IDpxJob2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetUserValue )( 
            __RPC__in IDpxJob2 * This,
            /* [annotation][in] */ 
            _In_  UINT64 UserValue);
        
        HRESULT ( STDMETHODCALLTYPE *GetUserValue )( 
            __RPC__in IDpxJob2 * This,
            /* [annotation][out] */ 
            _Out_  UINT64 *pUserValue);
        
        HRESULT ( STDMETHODCALLTYPE *SetOptionValue )( 
            __RPC__in IDpxJob2 * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR OptionName,
            /* [annotation][unique][in] */ 
            _In_  LPCWSTR OptionValue);
        
        HRESULT ( STDMETHODCALLTYPE *GetOptionValue )( 
            __RPC__in IDpxJob2 * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR OptionName,
            /* [annotation][out] */ 
            _Out_  LPWSTR *pOptionValue);
        
        /* [local] */ void ( STDMETHODCALLTYPE *FreeMemory )( 
            IDpxJob2 * This,
            /* [annotation][in] */ 
            _In_  void *Allocation);
        
        HRESULT ( STDMETHODCALLTYPE *SetInventoryProvider )( 
            __RPC__in IDpxJob2 * This,
            /* [annotation][in] */ 
            _In_  LOCATIONTYPE locationType,
            /* [annotation][in] */ 
            _In_  IFileHashProviderCallback *pProvider);
        
        END_INTERFACE
    } IDpxJob2Vtbl;

    interface IDpxJob2
    {
        CONST_VTBL struct IDpxJob2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDpxJob2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDpxJob2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDpxJob2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDpxJob2_GetTargetPath(This,TargetPath)	\
    ( (This)->lpVtbl -> GetTargetPath(This,TargetPath) ) 

#define IDpxJob2_AddContainer(This,ContainerPath,ppContainer)	\
    ( (This)->lpVtbl -> AddContainer(This,ContainerPath,ppContainer) ) 

#define IDpxJob2_EnumContainers(This,ppEnumContainers)	\
    ( (This)->lpVtbl -> EnumContainers(This,ppEnumContainers) ) 

#define IDpxJob2_SetDownloadProvider(This,pDownloadProvider)	\
    ( (This)->lpVtbl -> SetDownloadProvider(This,pDownloadProvider) ) 

#define IDpxJob2_GetDownloadProvider(This,ppDownloadProvider)	\
    ( (This)->lpVtbl -> GetDownloadProvider(This,ppDownloadProvider) ) 

#define IDpxJob2_Resume(This,eResumeType)	\
    ( (This)->lpVtbl -> Resume(This,eResumeType) ) 

#define IDpxJob2_Suspend(This)	\
    ( (This)->lpVtbl -> Suspend(This) ) 

#define IDpxJob2_Cancel(This)	\
    ( (This)->lpVtbl -> Cancel(This) ) 

#define IDpxJob2_GetProgress(This,pProgress)	\
    ( (This)->lpVtbl -> GetProgress(This,pProgress) ) 

#define IDpxJob2_SaveJobState(This)	\
    ( (This)->lpVtbl -> SaveJobState(This) ) 

#define IDpxJob2_SetUserValue(This,UserValue)	\
    ( (This)->lpVtbl -> SetUserValue(This,UserValue) ) 

#define IDpxJob2_GetUserValue(This,pUserValue)	\
    ( (This)->lpVtbl -> GetUserValue(This,pUserValue) ) 

#define IDpxJob2_SetOptionValue(This,OptionName,OptionValue)	\
    ( (This)->lpVtbl -> SetOptionValue(This,OptionName,OptionValue) ) 

#define IDpxJob2_GetOptionValue(This,OptionName,pOptionValue)	\
    ( (This)->lpVtbl -> GetOptionValue(This,OptionName,pOptionValue) ) 

#define IDpxJob2_FreeMemory(This,Allocation)	\
    ( (This)->lpVtbl -> FreeMemory(This,Allocation) ) 


#define IDpxJob2_SetInventoryProvider(This,locationType,pProvider)	\
    ( (This)->lpVtbl -> SetInventoryProvider(This,locationType,pProvider) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDpxJob2_INTERFACE_DEFINED__ */


#ifndef __IDpxContainer_INTERFACE_DEFINED__
#define __IDpxContainer_INTERFACE_DEFINED__

/* interface IDpxContainer */
/* [unique][object][uuid] */ 


EXTERN_C const IID IID_IDpxContainer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("ddc1b712-0e55-452f-838e-d1505b866e2b")
    IDpxContainer : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetContainerPath( 
            /* [annotation][in] */ 
            _In_  LPCWSTR ContainerPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetContainerPath( 
            /* [annotation][out] */ 
            _Out_  LPWSTR *pContainerPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddFileToExtract( 
            /* [annotation][in] */ 
            _In_  LPCWSTR SourceFileName,
            /* [annotation][unique][in] */ 
            _In_  LPCWSTR TargetFileName,
            /* [annotation][unique][in] */ 
            _In_  DPX_HASH *TargetFileHash) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddFileToExtract2( 
            /* [annotation][in] */ 
            _In_  LPCWSTR SourceFileName,
            /* [annotation][unique][in] */ 
            _In_  LPCWSTR TargetFileName,
            /* [annotation][out] */ 
            _Out_  IDpxFile **ppFile) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ExtractAllFiles( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumFilesToExtract( 
            /* [annotation][out] */ 
            _Out_  IEnumDpxFiles **ppEnumFiles) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetExpectedContainerIndexHash( 
            /* [annotation][in] */ 
            _In_  DPX_HASH *pExpectedHash) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetExpectedContainerIndexHash( 
            /* [annotation][out] */ 
            _Out_  DPX_HASH **ppExpectedHash) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ProvideContainerIndex( 
            /* [annotation][in] */ 
            _In_  UINT IndexSize,
            /* [annotation][size_is][in] */ 
            _In_reads_(IndexSize)  BYTE IndexData[  ]) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ProvideContainerIndexByFile( 
            /* [annotation][in] */ 
            _In_  LPCWSTR IndexFileName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumDirectoryEntries( 
            /* [annotation][out] */ 
            _Out_  IEnumDpxContainerDirectoryEntries **ppEnumEntries) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Remove( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetUserValue( 
            /* [annotation][in] */ 
            _In_  UINT64 UserValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetUserValue( 
            /* [annotation][out] */ 
            _Out_  UINT64 *pUserValue) = 0;
        
        virtual /* [local] */ void STDMETHODCALLTYPE FreeMemory( 
            /* [annotation][in] */ 
            _In_  void *Allocation) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IDpxContainerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IDpxContainer * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IDpxContainer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IDpxContainer * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetContainerPath )( 
            __RPC__in IDpxContainer * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR ContainerPath);
        
        HRESULT ( STDMETHODCALLTYPE *GetContainerPath )( 
            __RPC__in IDpxContainer * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *pContainerPath);
        
        HRESULT ( STDMETHODCALLTYPE *AddFileToExtract )( 
            __RPC__in IDpxContainer * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR SourceFileName,
            /* [annotation][unique][in] */ 
            _In_  LPCWSTR TargetFileName,
            /* [annotation][unique][in] */ 
            _In_  DPX_HASH *TargetFileHash);
        
        HRESULT ( STDMETHODCALLTYPE *AddFileToExtract2 )( 
            __RPC__in IDpxContainer * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR SourceFileName,
            /* [annotation][unique][in] */ 
            _In_  LPCWSTR TargetFileName,
            /* [annotation][out] */ 
            _Out_  IDpxFile **ppFile);
        
        HRESULT ( STDMETHODCALLTYPE *ExtractAllFiles )( 
            __RPC__in IDpxContainer * This);
        
        HRESULT ( STDMETHODCALLTYPE *EnumFilesToExtract )( 
            __RPC__in IDpxContainer * This,
            /* [annotation][out] */ 
            _Out_  IEnumDpxFiles **ppEnumFiles);
        
        HRESULT ( STDMETHODCALLTYPE *SetExpectedContainerIndexHash )( 
            __RPC__in IDpxContainer * This,
            /* [annotation][in] */ 
            _In_  DPX_HASH *pExpectedHash);
        
        HRESULT ( STDMETHODCALLTYPE *GetExpectedContainerIndexHash )( 
            __RPC__in IDpxContainer * This,
            /* [annotation][out] */ 
            _Out_  DPX_HASH **ppExpectedHash);
        
        HRESULT ( STDMETHODCALLTYPE *ProvideContainerIndex )( 
            __RPC__in IDpxContainer * This,
            /* [annotation][in] */ 
            _In_  UINT IndexSize,
            /* [annotation][size_is][in] */ 
            _In_reads_(IndexSize)  BYTE IndexData[  ]);
        
        HRESULT ( STDMETHODCALLTYPE *ProvideContainerIndexByFile )( 
            __RPC__in IDpxContainer * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR IndexFileName);
        
        HRESULT ( STDMETHODCALLTYPE *EnumDirectoryEntries )( 
            __RPC__in IDpxContainer * This,
            /* [annotation][out] */ 
            _Out_  IEnumDpxContainerDirectoryEntries **ppEnumEntries);
        
        HRESULT ( STDMETHODCALLTYPE *Remove )( 
            __RPC__in IDpxContainer * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetUserValue )( 
            __RPC__in IDpxContainer * This,
            /* [annotation][in] */ 
            _In_  UINT64 UserValue);
        
        HRESULT ( STDMETHODCALLTYPE *GetUserValue )( 
            __RPC__in IDpxContainer * This,
            /* [annotation][out] */ 
            _Out_  UINT64 *pUserValue);
        
        /* [local] */ void ( STDMETHODCALLTYPE *FreeMemory )( 
            IDpxContainer * This,
            /* [annotation][in] */ 
            _In_  void *Allocation);
        
        END_INTERFACE
    } IDpxContainerVtbl;

    interface IDpxContainer
    {
        CONST_VTBL struct IDpxContainerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDpxContainer_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDpxContainer_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDpxContainer_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDpxContainer_SetContainerPath(This,ContainerPath)	\
    ( (This)->lpVtbl -> SetContainerPath(This,ContainerPath) ) 

#define IDpxContainer_GetContainerPath(This,pContainerPath)	\
    ( (This)->lpVtbl -> GetContainerPath(This,pContainerPath) ) 

#define IDpxContainer_AddFileToExtract(This,SourceFileName,TargetFileName,TargetFileHash)	\
    ( (This)->lpVtbl -> AddFileToExtract(This,SourceFileName,TargetFileName,TargetFileHash) ) 

#define IDpxContainer_AddFileToExtract2(This,SourceFileName,TargetFileName,ppFile)	\
    ( (This)->lpVtbl -> AddFileToExtract2(This,SourceFileName,TargetFileName,ppFile) ) 

#define IDpxContainer_ExtractAllFiles(This)	\
    ( (This)->lpVtbl -> ExtractAllFiles(This) ) 

#define IDpxContainer_EnumFilesToExtract(This,ppEnumFiles)	\
    ( (This)->lpVtbl -> EnumFilesToExtract(This,ppEnumFiles) ) 

#define IDpxContainer_SetExpectedContainerIndexHash(This,pExpectedHash)	\
    ( (This)->lpVtbl -> SetExpectedContainerIndexHash(This,pExpectedHash) ) 

#define IDpxContainer_GetExpectedContainerIndexHash(This,ppExpectedHash)	\
    ( (This)->lpVtbl -> GetExpectedContainerIndexHash(This,ppExpectedHash) ) 

#define IDpxContainer_ProvideContainerIndex(This,IndexSize,IndexData)	\
    ( (This)->lpVtbl -> ProvideContainerIndex(This,IndexSize,IndexData) ) 

#define IDpxContainer_ProvideContainerIndexByFile(This,IndexFileName)	\
    ( (This)->lpVtbl -> ProvideContainerIndexByFile(This,IndexFileName) ) 

#define IDpxContainer_EnumDirectoryEntries(This,ppEnumEntries)	\
    ( (This)->lpVtbl -> EnumDirectoryEntries(This,ppEnumEntries) ) 

#define IDpxContainer_Remove(This)	\
    ( (This)->lpVtbl -> Remove(This) ) 

#define IDpxContainer_SetUserValue(This,UserValue)	\
    ( (This)->lpVtbl -> SetUserValue(This,UserValue) ) 

#define IDpxContainer_GetUserValue(This,pUserValue)	\
    ( (This)->lpVtbl -> GetUserValue(This,pUserValue) ) 

#define IDpxContainer_FreeMemory(This,Allocation)	\
    ( (This)->lpVtbl -> FreeMemory(This,Allocation) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDpxContainer_INTERFACE_DEFINED__ */


#ifndef __IDpxFile_INTERFACE_DEFINED__
#define __IDpxFile_INTERFACE_DEFINED__

/* interface IDpxFile */
/* [unique][object][uuid] */ 


EXTERN_C const IID IID_IDpxFile;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("ddc1b713-0e55-452f-838e-d1505b866e2b")
    IDpxFile : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetSourceFileName( 
            /* [annotation][out] */ 
            _Out_  LPWSTR *pSourceFileName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTargetFileName( 
            /* [annotation][out] */ 
            _Out_  LPWSTR *pTargetFileName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetExpectedHash( 
            /* [annotation][in] */ 
            _In_  DPX_HASH *pExpectedHash) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetExpectedHash( 
            /* [annotation][out] */ 
            _Out_  DPX_HASH **ppExpectedHash) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Remove( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetUserValue( 
            /* [annotation][in] */ 
            _In_  UINT64 UserValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetUserValue( 
            /* [annotation][out] */ 
            _Out_  UINT64 *pUserValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStatus( 
            /* [annotation][out] */ 
            _Out_  HRESULT *pStatus) = 0;
        
        virtual /* [local] */ void STDMETHODCALLTYPE FreeMemory( 
            /* [annotation][in] */ 
            _In_  void *Allocation) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IDpxFileVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IDpxFile * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IDpxFile * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IDpxFile * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetSourceFileName )( 
            __RPC__in IDpxFile * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *pSourceFileName);
        
        HRESULT ( STDMETHODCALLTYPE *GetTargetFileName )( 
            __RPC__in IDpxFile * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *pTargetFileName);
        
        HRESULT ( STDMETHODCALLTYPE *SetExpectedHash )( 
            __RPC__in IDpxFile * This,
            /* [annotation][in] */ 
            _In_  DPX_HASH *pExpectedHash);
        
        HRESULT ( STDMETHODCALLTYPE *GetExpectedHash )( 
            __RPC__in IDpxFile * This,
            /* [annotation][out] */ 
            _Out_  DPX_HASH **ppExpectedHash);
        
        HRESULT ( STDMETHODCALLTYPE *Remove )( 
            __RPC__in IDpxFile * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetUserValue )( 
            __RPC__in IDpxFile * This,
            /* [annotation][in] */ 
            _In_  UINT64 UserValue);
        
        HRESULT ( STDMETHODCALLTYPE *GetUserValue )( 
            __RPC__in IDpxFile * This,
            /* [annotation][out] */ 
            _Out_  UINT64 *pUserValue);
        
        HRESULT ( STDMETHODCALLTYPE *GetStatus )( 
            __RPC__in IDpxFile * This,
            /* [annotation][out] */ 
            _Out_  HRESULT *pStatus);
        
        /* [local] */ void ( STDMETHODCALLTYPE *FreeMemory )( 
            IDpxFile * This,
            /* [annotation][in] */ 
            _In_  void *Allocation);
        
        END_INTERFACE
    } IDpxFileVtbl;

    interface IDpxFile
    {
        CONST_VTBL struct IDpxFileVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDpxFile_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDpxFile_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDpxFile_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDpxFile_GetSourceFileName(This,pSourceFileName)	\
    ( (This)->lpVtbl -> GetSourceFileName(This,pSourceFileName) ) 

#define IDpxFile_GetTargetFileName(This,pTargetFileName)	\
    ( (This)->lpVtbl -> GetTargetFileName(This,pTargetFileName) ) 

#define IDpxFile_SetExpectedHash(This,pExpectedHash)	\
    ( (This)->lpVtbl -> SetExpectedHash(This,pExpectedHash) ) 

#define IDpxFile_GetExpectedHash(This,ppExpectedHash)	\
    ( (This)->lpVtbl -> GetExpectedHash(This,ppExpectedHash) ) 

#define IDpxFile_Remove(This)	\
    ( (This)->lpVtbl -> Remove(This) ) 

#define IDpxFile_SetUserValue(This,UserValue)	\
    ( (This)->lpVtbl -> SetUserValue(This,UserValue) ) 

#define IDpxFile_GetUserValue(This,pUserValue)	\
    ( (This)->lpVtbl -> GetUserValue(This,pUserValue) ) 

#define IDpxFile_GetStatus(This,pStatus)	\
    ( (This)->lpVtbl -> GetStatus(This,pStatus) ) 

#define IDpxFile_FreeMemory(This,Allocation)	\
    ( (This)->lpVtbl -> FreeMemory(This,Allocation) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDpxFile_INTERFACE_DEFINED__ */


#ifndef __IDpxFile2_INTERFACE_DEFINED__
#define __IDpxFile2_INTERFACE_DEFINED__

/* interface IDpxFile2 */
/* [unique][object][uuid] */ 


EXTERN_C const IID IID_IDpxFile2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("c249cc11-c1f5-428e-acbf-e1b78b30b971")
    IDpxFile2 : public IDpxFile
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetSize( 
            /* [annotation][out] */ 
            _Out_  UINT64 *pSize) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IDpxFile2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IDpxFile2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IDpxFile2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IDpxFile2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetSourceFileName )( 
            __RPC__in IDpxFile2 * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *pSourceFileName);
        
        HRESULT ( STDMETHODCALLTYPE *GetTargetFileName )( 
            __RPC__in IDpxFile2 * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *pTargetFileName);
        
        HRESULT ( STDMETHODCALLTYPE *SetExpectedHash )( 
            __RPC__in IDpxFile2 * This,
            /* [annotation][in] */ 
            _In_  DPX_HASH *pExpectedHash);
        
        HRESULT ( STDMETHODCALLTYPE *GetExpectedHash )( 
            __RPC__in IDpxFile2 * This,
            /* [annotation][out] */ 
            _Out_  DPX_HASH **ppExpectedHash);
        
        HRESULT ( STDMETHODCALLTYPE *Remove )( 
            __RPC__in IDpxFile2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetUserValue )( 
            __RPC__in IDpxFile2 * This,
            /* [annotation][in] */ 
            _In_  UINT64 UserValue);
        
        HRESULT ( STDMETHODCALLTYPE *GetUserValue )( 
            __RPC__in IDpxFile2 * This,
            /* [annotation][out] */ 
            _Out_  UINT64 *pUserValue);
        
        HRESULT ( STDMETHODCALLTYPE *GetStatus )( 
            __RPC__in IDpxFile2 * This,
            /* [annotation][out] */ 
            _Out_  HRESULT *pStatus);
        
        /* [local] */ void ( STDMETHODCALLTYPE *FreeMemory )( 
            IDpxFile2 * This,
            /* [annotation][in] */ 
            _In_  void *Allocation);
        
        HRESULT ( STDMETHODCALLTYPE *GetSize )( 
            __RPC__in IDpxFile2 * This,
            /* [annotation][out] */ 
            _Out_  UINT64 *pSize);
        
        END_INTERFACE
    } IDpxFile2Vtbl;

    interface IDpxFile2
    {
        CONST_VTBL struct IDpxFile2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDpxFile2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDpxFile2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDpxFile2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDpxFile2_GetSourceFileName(This,pSourceFileName)	\
    ( (This)->lpVtbl -> GetSourceFileName(This,pSourceFileName) ) 

#define IDpxFile2_GetTargetFileName(This,pTargetFileName)	\
    ( (This)->lpVtbl -> GetTargetFileName(This,pTargetFileName) ) 

#define IDpxFile2_SetExpectedHash(This,pExpectedHash)	\
    ( (This)->lpVtbl -> SetExpectedHash(This,pExpectedHash) ) 

#define IDpxFile2_GetExpectedHash(This,ppExpectedHash)	\
    ( (This)->lpVtbl -> GetExpectedHash(This,ppExpectedHash) ) 

#define IDpxFile2_Remove(This)	\
    ( (This)->lpVtbl -> Remove(This) ) 

#define IDpxFile2_SetUserValue(This,UserValue)	\
    ( (This)->lpVtbl -> SetUserValue(This,UserValue) ) 

#define IDpxFile2_GetUserValue(This,pUserValue)	\
    ( (This)->lpVtbl -> GetUserValue(This,pUserValue) ) 

#define IDpxFile2_GetStatus(This,pStatus)	\
    ( (This)->lpVtbl -> GetStatus(This,pStatus) ) 

#define IDpxFile2_FreeMemory(This,Allocation)	\
    ( (This)->lpVtbl -> FreeMemory(This,Allocation) ) 


#define IDpxFile2_GetSize(This,pSize)	\
    ( (This)->lpVtbl -> GetSize(This,pSize) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDpxFile2_INTERFACE_DEFINED__ */


#ifndef __IDpxContainerDirectoryEntry_INTERFACE_DEFINED__
#define __IDpxContainerDirectoryEntry_INTERFACE_DEFINED__

/* interface IDpxContainerDirectoryEntry */
/* [unique][object][uuid] */ 


EXTERN_C const IID IID_IDpxContainerDirectoryEntry;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("ddc1b715-0e55-452f-838e-d1505b866e2b")
    IDpxContainerDirectoryEntry : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetName( 
            /* [annotation][out] */ 
            _Out_  LPWSTR *pDirEntryName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetHash( 
            /* [annotation][out] */ 
            _Out_  DPX_HASH **pDirEntryHash) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSize( 
            /* [annotation][out] */ 
            _Out_  UINT64 *pDirEntrySize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTime( 
            /* [annotation][out] */ 
            _Out_  FILETIME *pDirEntryTime) = 0;
        
        virtual /* [local] */ void STDMETHODCALLTYPE FreeMemory( 
            /* [annotation][in] */ 
            _In_  void *Allocation) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IDpxContainerDirectoryEntryVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IDpxContainerDirectoryEntry * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IDpxContainerDirectoryEntry * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IDpxContainerDirectoryEntry * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetName )( 
            __RPC__in IDpxContainerDirectoryEntry * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *pDirEntryName);
        
        HRESULT ( STDMETHODCALLTYPE *GetHash )( 
            __RPC__in IDpxContainerDirectoryEntry * This,
            /* [annotation][out] */ 
            _Out_  DPX_HASH **pDirEntryHash);
        
        HRESULT ( STDMETHODCALLTYPE *GetSize )( 
            __RPC__in IDpxContainerDirectoryEntry * This,
            /* [annotation][out] */ 
            _Out_  UINT64 *pDirEntrySize);
        
        HRESULT ( STDMETHODCALLTYPE *GetTime )( 
            __RPC__in IDpxContainerDirectoryEntry * This,
            /* [annotation][out] */ 
            _Out_  FILETIME *pDirEntryTime);
        
        /* [local] */ void ( STDMETHODCALLTYPE *FreeMemory )( 
            IDpxContainerDirectoryEntry * This,
            /* [annotation][in] */ 
            _In_  void *Allocation);
        
        END_INTERFACE
    } IDpxContainerDirectoryEntryVtbl;

    interface IDpxContainerDirectoryEntry
    {
        CONST_VTBL struct IDpxContainerDirectoryEntryVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDpxContainerDirectoryEntry_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDpxContainerDirectoryEntry_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDpxContainerDirectoryEntry_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDpxContainerDirectoryEntry_GetName(This,pDirEntryName)	\
    ( (This)->lpVtbl -> GetName(This,pDirEntryName) ) 

#define IDpxContainerDirectoryEntry_GetHash(This,pDirEntryHash)	\
    ( (This)->lpVtbl -> GetHash(This,pDirEntryHash) ) 

#define IDpxContainerDirectoryEntry_GetSize(This,pDirEntrySize)	\
    ( (This)->lpVtbl -> GetSize(This,pDirEntrySize) ) 

#define IDpxContainerDirectoryEntry_GetTime(This,pDirEntryTime)	\
    ( (This)->lpVtbl -> GetTime(This,pDirEntryTime) ) 

#define IDpxContainerDirectoryEntry_FreeMemory(This,Allocation)	\
    ( (This)->lpVtbl -> FreeMemory(This,Allocation) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDpxContainerDirectoryEntry_INTERFACE_DEFINED__ */


#ifndef __IDpxDownloadProvider_INTERFACE_DEFINED__
#define __IDpxDownloadProvider_INTERFACE_DEFINED__

/* interface IDpxDownloadProvider */
/* [unique][object][uuid] */ 


EXTERN_C const IID IID_IDpxDownloadProvider;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("ddc1b716-0e55-452f-838e-d1505b866e2b")
    IDpxDownloadProvider : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetProvideDataCallback( 
            /* [annotation][in] */ 
            _In_  IDpxDownloadCallback *pProvideData) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetProvideDataCallback( 
            /* [annotation][out] */ 
            _Out_  IDpxDownloadCallback **ppProvideData) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddContainer( 
            /* [annotation][in] */ 
            _In_  LPCWSTR ContainerFilePath,
            /* [annotation][in] */ 
            _In_  UINT64 ContainerId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddRanges( 
            /* [annotation][in] */ 
            _In_  UINT64 ContainerId,
            /* [annotation][in] */ 
            _In_  UINT RangeCount,
            /* [annotation][size_is][in] */ 
            _In_reads_(RangeCount)  DPX_BYTE_RANGE RangeList[  ]) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetContainers( 
            /* [annotation][out] */ 
            _Out_  UINT *ContainerCount,
            /* [annotation][size_is][size_is][out] */ 
            _Out_writes_(*ContainerCount)  UINT64 **ppContainerIdArray) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetContainerPath( 
            /* [annotation][in] */ 
            _In_  UINT64 ContainerId,
            /* [annotation][out] */ 
            _Out_  LPWSTR *ContainerPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRanges( 
            /* [annotation][in] */ 
            _In_  UINT64 ContainerId,
            /* [annotation][in] */ 
            _In_  BOOL IncludeCompletedRanges,
            /* [annotation][out] */ 
            _Out_  UINT *RangeCount,
            /* [annotation][size_is][size_is][out] */ 
            _Out_writes_(*RangeCount)  DPX_BYTE_RANGE **ppRangeArray) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Resume( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Suspend( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Cancel( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE WaitForCompletion( 
            /* [annotation][in] */ 
            _In_  DWORD TimeoutMilliseconds) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetProgress( 
            /* [annotation][out] */ 
            _Out_  DPX_PROGRESS_REMAIN *pDownloadProgress) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ClearRequest( void) = 0;
        
        virtual /* [local] */ void STDMETHODCALLTYPE FreeMemory( 
            /* [annotation][in] */ 
            _In_  void *Allocation) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IDpxDownloadProviderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IDpxDownloadProvider * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IDpxDownloadProvider * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IDpxDownloadProvider * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetProvideDataCallback )( 
            __RPC__in IDpxDownloadProvider * This,
            /* [annotation][in] */ 
            _In_  IDpxDownloadCallback *pProvideData);
        
        HRESULT ( STDMETHODCALLTYPE *GetProvideDataCallback )( 
            __RPC__in IDpxDownloadProvider * This,
            /* [annotation][out] */ 
            _Out_  IDpxDownloadCallback **ppProvideData);
        
        HRESULT ( STDMETHODCALLTYPE *AddContainer )( 
            __RPC__in IDpxDownloadProvider * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR ContainerFilePath,
            /* [annotation][in] */ 
            _In_  UINT64 ContainerId);
        
        HRESULT ( STDMETHODCALLTYPE *AddRanges )( 
            __RPC__in IDpxDownloadProvider * This,
            /* [annotation][in] */ 
            _In_  UINT64 ContainerId,
            /* [annotation][in] */ 
            _In_  UINT RangeCount,
            /* [annotation][size_is][in] */ 
            _In_reads_(RangeCount)  DPX_BYTE_RANGE RangeList[  ]);
        
        HRESULT ( STDMETHODCALLTYPE *GetContainers )( 
            __RPC__in IDpxDownloadProvider * This,
            /* [annotation][out] */ 
            _Out_  UINT *ContainerCount,
            /* [annotation][size_is][size_is][out] */ 
            _Out_writes_(*ContainerCount)  UINT64 **ppContainerIdArray);
        
        HRESULT ( STDMETHODCALLTYPE *GetContainerPath )( 
            __RPC__in IDpxDownloadProvider * This,
            /* [annotation][in] */ 
            _In_  UINT64 ContainerId,
            /* [annotation][out] */ 
            _Out_  LPWSTR *ContainerPath);
        
        HRESULT ( STDMETHODCALLTYPE *GetRanges )( 
            __RPC__in IDpxDownloadProvider * This,
            /* [annotation][in] */ 
            _In_  UINT64 ContainerId,
            /* [annotation][in] */ 
            _In_  BOOL IncludeCompletedRanges,
            /* [annotation][out] */ 
            _Out_  UINT *RangeCount,
            /* [annotation][size_is][size_is][out] */ 
            _Out_writes_(*RangeCount)  DPX_BYTE_RANGE **ppRangeArray);
        
        HRESULT ( STDMETHODCALLTYPE *Resume )( 
            __RPC__in IDpxDownloadProvider * This);
        
        HRESULT ( STDMETHODCALLTYPE *Suspend )( 
            __RPC__in IDpxDownloadProvider * This);
        
        HRESULT ( STDMETHODCALLTYPE *Cancel )( 
            __RPC__in IDpxDownloadProvider * This);
        
        HRESULT ( STDMETHODCALLTYPE *WaitForCompletion )( 
            __RPC__in IDpxDownloadProvider * This,
            /* [annotation][in] */ 
            _In_  DWORD TimeoutMilliseconds);
        
        HRESULT ( STDMETHODCALLTYPE *GetProgress )( 
            __RPC__in IDpxDownloadProvider * This,
            /* [annotation][out] */ 
            _Out_  DPX_PROGRESS_REMAIN *pDownloadProgress);
        
        HRESULT ( STDMETHODCALLTYPE *ClearRequest )( 
            __RPC__in IDpxDownloadProvider * This);
        
        /* [local] */ void ( STDMETHODCALLTYPE *FreeMemory )( 
            IDpxDownloadProvider * This,
            /* [annotation][in] */ 
            _In_  void *Allocation);
        
        END_INTERFACE
    } IDpxDownloadProviderVtbl;

    interface IDpxDownloadProvider
    {
        CONST_VTBL struct IDpxDownloadProviderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDpxDownloadProvider_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDpxDownloadProvider_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDpxDownloadProvider_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDpxDownloadProvider_SetProvideDataCallback(This,pProvideData)	\
    ( (This)->lpVtbl -> SetProvideDataCallback(This,pProvideData) ) 

#define IDpxDownloadProvider_GetProvideDataCallback(This,ppProvideData)	\
    ( (This)->lpVtbl -> GetProvideDataCallback(This,ppProvideData) ) 

#define IDpxDownloadProvider_AddContainer(This,ContainerFilePath,ContainerId)	\
    ( (This)->lpVtbl -> AddContainer(This,ContainerFilePath,ContainerId) ) 

#define IDpxDownloadProvider_AddRanges(This,ContainerId,RangeCount,RangeList)	\
    ( (This)->lpVtbl -> AddRanges(This,ContainerId,RangeCount,RangeList) ) 

#define IDpxDownloadProvider_GetContainers(This,ContainerCount,ppContainerIdArray)	\
    ( (This)->lpVtbl -> GetContainers(This,ContainerCount,ppContainerIdArray) ) 

#define IDpxDownloadProvider_GetContainerPath(This,ContainerId,ContainerPath)	\
    ( (This)->lpVtbl -> GetContainerPath(This,ContainerId,ContainerPath) ) 

#define IDpxDownloadProvider_GetRanges(This,ContainerId,IncludeCompletedRanges,RangeCount,ppRangeArray)	\
    ( (This)->lpVtbl -> GetRanges(This,ContainerId,IncludeCompletedRanges,RangeCount,ppRangeArray) ) 

#define IDpxDownloadProvider_Resume(This)	\
    ( (This)->lpVtbl -> Resume(This) ) 

#define IDpxDownloadProvider_Suspend(This)	\
    ( (This)->lpVtbl -> Suspend(This) ) 

#define IDpxDownloadProvider_Cancel(This)	\
    ( (This)->lpVtbl -> Cancel(This) ) 

#define IDpxDownloadProvider_WaitForCompletion(This,TimeoutMilliseconds)	\
    ( (This)->lpVtbl -> WaitForCompletion(This,TimeoutMilliseconds) ) 

#define IDpxDownloadProvider_GetProgress(This,pDownloadProgress)	\
    ( (This)->lpVtbl -> GetProgress(This,pDownloadProgress) ) 

#define IDpxDownloadProvider_ClearRequest(This)	\
    ( (This)->lpVtbl -> ClearRequest(This) ) 

#define IDpxDownloadProvider_FreeMemory(This,Allocation)	\
    ( (This)->lpVtbl -> FreeMemory(This,Allocation) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDpxDownloadProvider_INTERFACE_DEFINED__ */


#ifndef __IDpxDownloadCallback_INTERFACE_DEFINED__
#define __IDpxDownloadCallback_INTERFACE_DEFINED__

/* interface IDpxDownloadCallback */
/* [unique][object][uuid] */ 


EXTERN_C const IID IID_IDpxDownloadCallback;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("ddc1b717-0e55-452f-838e-d1505b866e2b")
    IDpxDownloadCallback : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ProvideRequestedData( 
            /* [annotation][in] */ 
            _In_  UINT64 ContainerId,
            /* [annotation][in] */ 
            _In_  UINT RangeCount,
            /* [annotation][size_is][in] */ 
            _In_reads_(RangeCount)  DPX_BYTE_RANGE RangeList[  ],
            /* [annotation][size_is][in] */ 
            _In_reads_(RangeCount)  const BYTE *RangeData[  ]) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ProvideRequestedDataByFile( 
            /* [annotation][in] */ 
            _In_  UINT64 ContainerId,
            /* [annotation][in] */ 
            _In_  LPCWSTR ResponseFilePath,
            /* [annotation][in] */ 
            _In_  UINT RangeCount,
            /* [annotation][size_is][in] */ 
            _In_reads_(RangeCount)  DPX_BYTE_RANGE RangeArray[  ],
            /* [annotation][size_is][in] */ 
            _In_reads_(RangeCount)  UINT64 OffsetInResponseFile[  ]) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ProvideRequestedDataByPackedRangeFile( 
            /* [annotation][in] */ 
            _In_  UINT64 ContainerId,
            /* [annotation][in] */ 
            _In_  LPCWSTR ResponseFilePath) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IDpxDownloadCallbackVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IDpxDownloadCallback * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IDpxDownloadCallback * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IDpxDownloadCallback * This);
        
        HRESULT ( STDMETHODCALLTYPE *ProvideRequestedData )( 
            __RPC__in IDpxDownloadCallback * This,
            /* [annotation][in] */ 
            _In_  UINT64 ContainerId,
            /* [annotation][in] */ 
            _In_  UINT RangeCount,
            /* [annotation][size_is][in] */ 
            _In_reads_(RangeCount)  DPX_BYTE_RANGE RangeList[  ],
            /* [annotation][size_is][in] */ 
            _In_reads_(RangeCount)  const BYTE *RangeData[  ]);
        
        HRESULT ( STDMETHODCALLTYPE *ProvideRequestedDataByFile )( 
            __RPC__in IDpxDownloadCallback * This,
            /* [annotation][in] */ 
            _In_  UINT64 ContainerId,
            /* [annotation][in] */ 
            _In_  LPCWSTR ResponseFilePath,
            /* [annotation][in] */ 
            _In_  UINT RangeCount,
            /* [annotation][size_is][in] */ 
            _In_reads_(RangeCount)  DPX_BYTE_RANGE RangeArray[  ],
            /* [annotation][size_is][in] */ 
            _In_reads_(RangeCount)  UINT64 OffsetInResponseFile[  ]);
        
        HRESULT ( STDMETHODCALLTYPE *ProvideRequestedDataByPackedRangeFile )( 
            __RPC__in IDpxDownloadCallback * This,
            /* [annotation][in] */ 
            _In_  UINT64 ContainerId,
            /* [annotation][in] */ 
            _In_  LPCWSTR ResponseFilePath);
        
        END_INTERFACE
    } IDpxDownloadCallbackVtbl;

    interface IDpxDownloadCallback
    {
        CONST_VTBL struct IDpxDownloadCallbackVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDpxDownloadCallback_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDpxDownloadCallback_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDpxDownloadCallback_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDpxDownloadCallback_ProvideRequestedData(This,ContainerId,RangeCount,RangeList,RangeData)	\
    ( (This)->lpVtbl -> ProvideRequestedData(This,ContainerId,RangeCount,RangeList,RangeData) ) 

#define IDpxDownloadCallback_ProvideRequestedDataByFile(This,ContainerId,ResponseFilePath,RangeCount,RangeArray,OffsetInResponseFile)	\
    ( (This)->lpVtbl -> ProvideRequestedDataByFile(This,ContainerId,ResponseFilePath,RangeCount,RangeArray,OffsetInResponseFile) ) 

#define IDpxDownloadCallback_ProvideRequestedDataByPackedRangeFile(This,ContainerId,ResponseFilePath)	\
    ( (This)->lpVtbl -> ProvideRequestedDataByPackedRangeFile(This,ContainerId,ResponseFilePath) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDpxDownloadCallback_INTERFACE_DEFINED__ */


#ifndef __IEnumDpxContainers_INTERFACE_DEFINED__
#define __IEnumDpxContainers_INTERFACE_DEFINED__

/* interface IEnumDpxContainers */
/* [unique][object][uuid] */ 


EXTERN_C const IID IID_IEnumDpxContainers;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("ddc1b722-0e55-452f-838e-d1505b866e2b")
    IEnumDpxContainers : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [annotation][in] */ 
            _In_  UINT ItemCount,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(ItemCount,*pFetchedCount)  IDpxContainer **ppContainers,
            /* [annotation][out] */ 
            _Out_  UINT *pFetchedCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [annotation][in] */ 
            _In_  UINT ItemCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [annotation][out] */ 
            _Out_  IEnumDpxContainers **ppEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCount( 
            /* [annotation][out] */ 
            _Out_  UINT *pItemCount) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IEnumDpxContainersVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IEnumDpxContainers * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IEnumDpxContainers * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IEnumDpxContainers * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            __RPC__in IEnumDpxContainers * This,
            /* [annotation][in] */ 
            _In_  UINT ItemCount,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(ItemCount,*pFetchedCount)  IDpxContainer **ppContainers,
            /* [annotation][out] */ 
            _Out_  UINT *pFetchedCount);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            __RPC__in IEnumDpxContainers * This,
            /* [annotation][in] */ 
            _In_  UINT ItemCount);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            __RPC__in IEnumDpxContainers * This);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            __RPC__in IEnumDpxContainers * This,
            /* [annotation][out] */ 
            _Out_  IEnumDpxContainers **ppEnum);
        
        HRESULT ( STDMETHODCALLTYPE *GetCount )( 
            __RPC__in IEnumDpxContainers * This,
            /* [annotation][out] */ 
            _Out_  UINT *pItemCount);
        
        END_INTERFACE
    } IEnumDpxContainersVtbl;

    interface IEnumDpxContainers
    {
        CONST_VTBL struct IEnumDpxContainersVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumDpxContainers_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEnumDpxContainers_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEnumDpxContainers_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IEnumDpxContainers_Next(This,ItemCount,ppContainers,pFetchedCount)	\
    ( (This)->lpVtbl -> Next(This,ItemCount,ppContainers,pFetchedCount) ) 

#define IEnumDpxContainers_Skip(This,ItemCount)	\
    ( (This)->lpVtbl -> Skip(This,ItemCount) ) 

#define IEnumDpxContainers_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define IEnumDpxContainers_Clone(This,ppEnum)	\
    ( (This)->lpVtbl -> Clone(This,ppEnum) ) 

#define IEnumDpxContainers_GetCount(This,pItemCount)	\
    ( (This)->lpVtbl -> GetCount(This,pItemCount) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IEnumDpxContainers_INTERFACE_DEFINED__ */


#ifndef __IEnumDpxFiles_INTERFACE_DEFINED__
#define __IEnumDpxFiles_INTERFACE_DEFINED__

/* interface IEnumDpxFiles */
/* [unique][object][uuid] */ 


EXTERN_C const IID IID_IEnumDpxFiles;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("ddc1b723-0e55-452f-838e-d1505b866e2b")
    IEnumDpxFiles : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [annotation][in] */ 
            _In_  UINT ItemCount,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(ItemCount,*pFetchedCount)  IDpxFile **ppFiles,
            /* [annotation][out] */ 
            _Out_  UINT *pFetchedCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [annotation][in] */ 
            _In_  UINT ItemCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [annotation][out] */ 
            _Out_  IEnumDpxFiles **ppEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCount( 
            /* [annotation][out] */ 
            _Out_  UINT *pItemCount) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IEnumDpxFilesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IEnumDpxFiles * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IEnumDpxFiles * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IEnumDpxFiles * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            __RPC__in IEnumDpxFiles * This,
            /* [annotation][in] */ 
            _In_  UINT ItemCount,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(ItemCount,*pFetchedCount)  IDpxFile **ppFiles,
            /* [annotation][out] */ 
            _Out_  UINT *pFetchedCount);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            __RPC__in IEnumDpxFiles * This,
            /* [annotation][in] */ 
            _In_  UINT ItemCount);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            __RPC__in IEnumDpxFiles * This);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            __RPC__in IEnumDpxFiles * This,
            /* [annotation][out] */ 
            _Out_  IEnumDpxFiles **ppEnum);
        
        HRESULT ( STDMETHODCALLTYPE *GetCount )( 
            __RPC__in IEnumDpxFiles * This,
            /* [annotation][out] */ 
            _Out_  UINT *pItemCount);
        
        END_INTERFACE
    } IEnumDpxFilesVtbl;

    interface IEnumDpxFiles
    {
        CONST_VTBL struct IEnumDpxFilesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumDpxFiles_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEnumDpxFiles_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEnumDpxFiles_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IEnumDpxFiles_Next(This,ItemCount,ppFiles,pFetchedCount)	\
    ( (This)->lpVtbl -> Next(This,ItemCount,ppFiles,pFetchedCount) ) 

#define IEnumDpxFiles_Skip(This,ItemCount)	\
    ( (This)->lpVtbl -> Skip(This,ItemCount) ) 

#define IEnumDpxFiles_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define IEnumDpxFiles_Clone(This,ppEnum)	\
    ( (This)->lpVtbl -> Clone(This,ppEnum) ) 

#define IEnumDpxFiles_GetCount(This,pItemCount)	\
    ( (This)->lpVtbl -> GetCount(This,pItemCount) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IEnumDpxFiles_INTERFACE_DEFINED__ */


#ifndef __IEnumDpxContainerDirectoryEntries_INTERFACE_DEFINED__
#define __IEnumDpxContainerDirectoryEntries_INTERFACE_DEFINED__

/* interface IEnumDpxContainerDirectoryEntries */
/* [unique][object][uuid] */ 


EXTERN_C const IID IID_IEnumDpxContainerDirectoryEntries;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("ddc1b725-0e55-452f-838e-d1505b866e2b")
    IEnumDpxContainerDirectoryEntries : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [annotation][in] */ 
            _In_  UINT ItemCount,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(ItemCount,*pFetchedCount)  IDpxContainerDirectoryEntry **ppDirectoryEntries,
            /* [annotation][out] */ 
            _Out_  UINT *pFetchedCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [annotation][in] */ 
            _In_  UINT ItemCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [annotation][out] */ 
            _Out_  IEnumDpxContainerDirectoryEntries **ppEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCount( 
            /* [annotation][out] */ 
            _Out_  UINT *pItemCount) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IEnumDpxContainerDirectoryEntriesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IEnumDpxContainerDirectoryEntries * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IEnumDpxContainerDirectoryEntries * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IEnumDpxContainerDirectoryEntries * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            __RPC__in IEnumDpxContainerDirectoryEntries * This,
            /* [annotation][in] */ 
            _In_  UINT ItemCount,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(ItemCount,*pFetchedCount)  IDpxContainerDirectoryEntry **ppDirectoryEntries,
            /* [annotation][out] */ 
            _Out_  UINT *pFetchedCount);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            __RPC__in IEnumDpxContainerDirectoryEntries * This,
            /* [annotation][in] */ 
            _In_  UINT ItemCount);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            __RPC__in IEnumDpxContainerDirectoryEntries * This);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            __RPC__in IEnumDpxContainerDirectoryEntries * This,
            /* [annotation][out] */ 
            _Out_  IEnumDpxContainerDirectoryEntries **ppEnum);
        
        HRESULT ( STDMETHODCALLTYPE *GetCount )( 
            __RPC__in IEnumDpxContainerDirectoryEntries * This,
            /* [annotation][out] */ 
            _Out_  UINT *pItemCount);
        
        END_INTERFACE
    } IEnumDpxContainerDirectoryEntriesVtbl;

    interface IEnumDpxContainerDirectoryEntries
    {
        CONST_VTBL struct IEnumDpxContainerDirectoryEntriesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumDpxContainerDirectoryEntries_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEnumDpxContainerDirectoryEntries_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEnumDpxContainerDirectoryEntries_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IEnumDpxContainerDirectoryEntries_Next(This,ItemCount,ppDirectoryEntries,pFetchedCount)	\
    ( (This)->lpVtbl -> Next(This,ItemCount,ppDirectoryEntries,pFetchedCount) ) 

#define IEnumDpxContainerDirectoryEntries_Skip(This,ItemCount)	\
    ( (This)->lpVtbl -> Skip(This,ItemCount) ) 

#define IEnumDpxContainerDirectoryEntries_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define IEnumDpxContainerDirectoryEntries_Clone(This,ppEnum)	\
    ( (This)->lpVtbl -> Clone(This,ppEnum) ) 

#define IEnumDpxContainerDirectoryEntries_GetCount(This,pItemCount)	\
    ( (This)->lpVtbl -> GetCount(This,pItemCount) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IEnumDpxContainerDirectoryEntries_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_dpx1_0000_0012 */
/* [local] */ 

typedef struct tagDpxContainerDecryptionData
    {
    ULONG cbDecryptionData;
    /* [size_is] */ BYTE *pDecryptionData;
    } 	DpxContainerDecryptionData;

typedef 
enum tagDPX_CONTAINER_ENCRYPTION_ENUM
    {
        DPX_CONTAINER_ENCRYPTION_NONE	= 0,
        DPX_CONTAINER_ENCRYPTION_ITERATIVE	= 1,
        DPX_CONTAINER_ENCRYPTION_MAX_ENUM	= DPX_CONTAINER_ENCRYPTION_ITERATIVE
    } 	DPX_CONTAINER_ENCRYPTION_ENUM;



extern RPC_IF_HANDLE __MIDL_itf_dpx1_0000_0012_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_dpx1_0000_0012_v0_0_s_ifspec;

#ifndef __IDpxEncryptedContainer_INTERFACE_DEFINED__
#define __IDpxEncryptedContainer_INTERFACE_DEFINED__

/* interface IDpxEncryptedContainer */
/* [unique][object][uuid] */ 


EXTERN_C const IID IID_IDpxEncryptedContainer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("ddc1b726-0e55-452f-838e-d1505b866e2b")
    IDpxEncryptedContainer : public IDpxContainer
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetContainerDecryption( 
            /* [annotation][in] */ 
            _In_  UINT DecryptionDataCount,
            /* [annotation][size_is][in] */ 
            _In_reads_(DecryptionDataCount)  DpxContainerDecryptionData DecryptionData[  ],
            /* [annotation][in] */ 
            _In_  DPX_CONTAINER_ENCRYPTION_ENUM EncryptionType) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IDpxEncryptedContainerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IDpxEncryptedContainer * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IDpxEncryptedContainer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IDpxEncryptedContainer * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetContainerPath )( 
            __RPC__in IDpxEncryptedContainer * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR ContainerPath);
        
        HRESULT ( STDMETHODCALLTYPE *GetContainerPath )( 
            __RPC__in IDpxEncryptedContainer * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *pContainerPath);
        
        HRESULT ( STDMETHODCALLTYPE *AddFileToExtract )( 
            __RPC__in IDpxEncryptedContainer * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR SourceFileName,
            /* [annotation][unique][in] */ 
            _In_  LPCWSTR TargetFileName,
            /* [annotation][unique][in] */ 
            _In_  DPX_HASH *TargetFileHash);
        
        HRESULT ( STDMETHODCALLTYPE *AddFileToExtract2 )( 
            __RPC__in IDpxEncryptedContainer * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR SourceFileName,
            /* [annotation][unique][in] */ 
            _In_  LPCWSTR TargetFileName,
            /* [annotation][out] */ 
            _Out_  IDpxFile **ppFile);
        
        HRESULT ( STDMETHODCALLTYPE *ExtractAllFiles )( 
            __RPC__in IDpxEncryptedContainer * This);
        
        HRESULT ( STDMETHODCALLTYPE *EnumFilesToExtract )( 
            __RPC__in IDpxEncryptedContainer * This,
            /* [annotation][out] */ 
            _Out_  IEnumDpxFiles **ppEnumFiles);
        
        HRESULT ( STDMETHODCALLTYPE *SetExpectedContainerIndexHash )( 
            __RPC__in IDpxEncryptedContainer * This,
            /* [annotation][in] */ 
            _In_  DPX_HASH *pExpectedHash);
        
        HRESULT ( STDMETHODCALLTYPE *GetExpectedContainerIndexHash )( 
            __RPC__in IDpxEncryptedContainer * This,
            /* [annotation][out] */ 
            _Out_  DPX_HASH **ppExpectedHash);
        
        HRESULT ( STDMETHODCALLTYPE *ProvideContainerIndex )( 
            __RPC__in IDpxEncryptedContainer * This,
            /* [annotation][in] */ 
            _In_  UINT IndexSize,
            /* [annotation][size_is][in] */ 
            _In_reads_(IndexSize)  BYTE IndexData[  ]);
        
        HRESULT ( STDMETHODCALLTYPE *ProvideContainerIndexByFile )( 
            __RPC__in IDpxEncryptedContainer * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR IndexFileName);
        
        HRESULT ( STDMETHODCALLTYPE *EnumDirectoryEntries )( 
            __RPC__in IDpxEncryptedContainer * This,
            /* [annotation][out] */ 
            _Out_  IEnumDpxContainerDirectoryEntries **ppEnumEntries);
        
        HRESULT ( STDMETHODCALLTYPE *Remove )( 
            __RPC__in IDpxEncryptedContainer * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetUserValue )( 
            __RPC__in IDpxEncryptedContainer * This,
            /* [annotation][in] */ 
            _In_  UINT64 UserValue);
        
        HRESULT ( STDMETHODCALLTYPE *GetUserValue )( 
            __RPC__in IDpxEncryptedContainer * This,
            /* [annotation][out] */ 
            _Out_  UINT64 *pUserValue);
        
        /* [local] */ void ( STDMETHODCALLTYPE *FreeMemory )( 
            IDpxEncryptedContainer * This,
            /* [annotation][in] */ 
            _In_  void *Allocation);
        
        HRESULT ( STDMETHODCALLTYPE *SetContainerDecryption )( 
            __RPC__in IDpxEncryptedContainer * This,
            /* [annotation][in] */ 
            _In_  UINT DecryptionDataCount,
            /* [annotation][size_is][in] */ 
            _In_reads_(DecryptionDataCount)  DpxContainerDecryptionData DecryptionData[  ],
            /* [annotation][in] */ 
            _In_  DPX_CONTAINER_ENCRYPTION_ENUM EncryptionType);
        
        END_INTERFACE
    } IDpxEncryptedContainerVtbl;

    interface IDpxEncryptedContainer
    {
        CONST_VTBL struct IDpxEncryptedContainerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDpxEncryptedContainer_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDpxEncryptedContainer_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDpxEncryptedContainer_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDpxEncryptedContainer_SetContainerPath(This,ContainerPath)	\
    ( (This)->lpVtbl -> SetContainerPath(This,ContainerPath) ) 

#define IDpxEncryptedContainer_GetContainerPath(This,pContainerPath)	\
    ( (This)->lpVtbl -> GetContainerPath(This,pContainerPath) ) 

#define IDpxEncryptedContainer_AddFileToExtract(This,SourceFileName,TargetFileName,TargetFileHash)	\
    ( (This)->lpVtbl -> AddFileToExtract(This,SourceFileName,TargetFileName,TargetFileHash) ) 

#define IDpxEncryptedContainer_AddFileToExtract2(This,SourceFileName,TargetFileName,ppFile)	\
    ( (This)->lpVtbl -> AddFileToExtract2(This,SourceFileName,TargetFileName,ppFile) ) 

#define IDpxEncryptedContainer_ExtractAllFiles(This)	\
    ( (This)->lpVtbl -> ExtractAllFiles(This) ) 

#define IDpxEncryptedContainer_EnumFilesToExtract(This,ppEnumFiles)	\
    ( (This)->lpVtbl -> EnumFilesToExtract(This,ppEnumFiles) ) 

#define IDpxEncryptedContainer_SetExpectedContainerIndexHash(This,pExpectedHash)	\
    ( (This)->lpVtbl -> SetExpectedContainerIndexHash(This,pExpectedHash) ) 

#define IDpxEncryptedContainer_GetExpectedContainerIndexHash(This,ppExpectedHash)	\
    ( (This)->lpVtbl -> GetExpectedContainerIndexHash(This,ppExpectedHash) ) 

#define IDpxEncryptedContainer_ProvideContainerIndex(This,IndexSize,IndexData)	\
    ( (This)->lpVtbl -> ProvideContainerIndex(This,IndexSize,IndexData) ) 

#define IDpxEncryptedContainer_ProvideContainerIndexByFile(This,IndexFileName)	\
    ( (This)->lpVtbl -> ProvideContainerIndexByFile(This,IndexFileName) ) 

#define IDpxEncryptedContainer_EnumDirectoryEntries(This,ppEnumEntries)	\
    ( (This)->lpVtbl -> EnumDirectoryEntries(This,ppEnumEntries) ) 

#define IDpxEncryptedContainer_Remove(This)	\
    ( (This)->lpVtbl -> Remove(This) ) 

#define IDpxEncryptedContainer_SetUserValue(This,UserValue)	\
    ( (This)->lpVtbl -> SetUserValue(This,UserValue) ) 

#define IDpxEncryptedContainer_GetUserValue(This,pUserValue)	\
    ( (This)->lpVtbl -> GetUserValue(This,pUserValue) ) 

#define IDpxEncryptedContainer_FreeMemory(This,Allocation)	\
    ( (This)->lpVtbl -> FreeMemory(This,Allocation) ) 


#define IDpxEncryptedContainer_SetContainerDecryption(This,DecryptionDataCount,DecryptionData,EncryptionType)	\
    ( (This)->lpVtbl -> SetContainerDecryption(This,DecryptionDataCount,DecryptionData,EncryptionType) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDpxEncryptedContainer_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_dpx1_0000_0013 */
/* [local] */ 

typedef struct tagDpxPredecessorFilePathInfo
    {
    LPCWSTR PredecessorInstallPath;
    LPCWSTR PredecessorCabPath;
    LPCWSTR CabPath;
    } 	PredecessorFilePathInfo;



extern RPC_IF_HANDLE __MIDL_itf_dpx1_0000_0013_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_dpx1_0000_0013_v0_0_s_ifspec;

#ifndef __IDpxContainer2_INTERFACE_DEFINED__
#define __IDpxContainer2_INTERFACE_DEFINED__

/* interface IDpxContainer2 */
/* [unique][object][uuid] */ 


EXTERN_C const IID IID_IDpxContainer2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("c8e1e004-3a8d-45c7-a6aa-8c8f2f2ed1e1")
    IDpxContainer2 : public IDpxEncryptedContainer
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AddPredecessorContainer( 
            /* [annotation][in] */ 
            _In_  LPCWSTR ContainerPath,
            /* [annotation][in] */ 
            _In_  UINT PredecessorFilePathsCount,
            /* [annotation][size_is][in] */ 
            _In_reads_(PredecessorFilePathsCount)  PredecessorFilePathInfo PredecessorFilePaths[  ],
            /* [annotation][out] */ 
            _Out_  IDpxContainer2 **ppContainer) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IDpxContainer2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IDpxContainer2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IDpxContainer2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IDpxContainer2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetContainerPath )( 
            __RPC__in IDpxContainer2 * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR ContainerPath);
        
        HRESULT ( STDMETHODCALLTYPE *GetContainerPath )( 
            __RPC__in IDpxContainer2 * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *pContainerPath);
        
        HRESULT ( STDMETHODCALLTYPE *AddFileToExtract )( 
            __RPC__in IDpxContainer2 * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR SourceFileName,
            /* [annotation][unique][in] */ 
            _In_  LPCWSTR TargetFileName,
            /* [annotation][unique][in] */ 
            _In_  DPX_HASH *TargetFileHash);
        
        HRESULT ( STDMETHODCALLTYPE *AddFileToExtract2 )( 
            __RPC__in IDpxContainer2 * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR SourceFileName,
            /* [annotation][unique][in] */ 
            _In_  LPCWSTR TargetFileName,
            /* [annotation][out] */ 
            _Out_  IDpxFile **ppFile);
        
        HRESULT ( STDMETHODCALLTYPE *ExtractAllFiles )( 
            __RPC__in IDpxContainer2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *EnumFilesToExtract )( 
            __RPC__in IDpxContainer2 * This,
            /* [annotation][out] */ 
            _Out_  IEnumDpxFiles **ppEnumFiles);
        
        HRESULT ( STDMETHODCALLTYPE *SetExpectedContainerIndexHash )( 
            __RPC__in IDpxContainer2 * This,
            /* [annotation][in] */ 
            _In_  DPX_HASH *pExpectedHash);
        
        HRESULT ( STDMETHODCALLTYPE *GetExpectedContainerIndexHash )( 
            __RPC__in IDpxContainer2 * This,
            /* [annotation][out] */ 
            _Out_  DPX_HASH **ppExpectedHash);
        
        HRESULT ( STDMETHODCALLTYPE *ProvideContainerIndex )( 
            __RPC__in IDpxContainer2 * This,
            /* [annotation][in] */ 
            _In_  UINT IndexSize,
            /* [annotation][size_is][in] */ 
            _In_reads_(IndexSize)  BYTE IndexData[  ]);
        
        HRESULT ( STDMETHODCALLTYPE *ProvideContainerIndexByFile )( 
            __RPC__in IDpxContainer2 * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR IndexFileName);
        
        HRESULT ( STDMETHODCALLTYPE *EnumDirectoryEntries )( 
            __RPC__in IDpxContainer2 * This,
            /* [annotation][out] */ 
            _Out_  IEnumDpxContainerDirectoryEntries **ppEnumEntries);
        
        HRESULT ( STDMETHODCALLTYPE *Remove )( 
            __RPC__in IDpxContainer2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetUserValue )( 
            __RPC__in IDpxContainer2 * This,
            /* [annotation][in] */ 
            _In_  UINT64 UserValue);
        
        HRESULT ( STDMETHODCALLTYPE *GetUserValue )( 
            __RPC__in IDpxContainer2 * This,
            /* [annotation][out] */ 
            _Out_  UINT64 *pUserValue);
        
        /* [local] */ void ( STDMETHODCALLTYPE *FreeMemory )( 
            IDpxContainer2 * This,
            /* [annotation][in] */ 
            _In_  void *Allocation);
        
        HRESULT ( STDMETHODCALLTYPE *SetContainerDecryption )( 
            __RPC__in IDpxContainer2 * This,
            /* [annotation][in] */ 
            _In_  UINT DecryptionDataCount,
            /* [annotation][size_is][in] */ 
            _In_reads_(DecryptionDataCount)  DpxContainerDecryptionData DecryptionData[  ],
            /* [annotation][in] */ 
            _In_  DPX_CONTAINER_ENCRYPTION_ENUM EncryptionType);
        
        HRESULT ( STDMETHODCALLTYPE *AddPredecessorContainer )( 
            __RPC__in IDpxContainer2 * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR ContainerPath,
            /* [annotation][in] */ 
            _In_  UINT PredecessorFilePathsCount,
            /* [annotation][size_is][in] */ 
            _In_reads_(PredecessorFilePathsCount)  PredecessorFilePathInfo PredecessorFilePaths[  ],
            /* [annotation][out] */ 
            _Out_  IDpxContainer2 **ppContainer);
        
        END_INTERFACE
    } IDpxContainer2Vtbl;

    interface IDpxContainer2
    {
        CONST_VTBL struct IDpxContainer2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDpxContainer2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDpxContainer2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDpxContainer2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDpxContainer2_SetContainerPath(This,ContainerPath)	\
    ( (This)->lpVtbl -> SetContainerPath(This,ContainerPath) ) 

#define IDpxContainer2_GetContainerPath(This,pContainerPath)	\
    ( (This)->lpVtbl -> GetContainerPath(This,pContainerPath) ) 

#define IDpxContainer2_AddFileToExtract(This,SourceFileName,TargetFileName,TargetFileHash)	\
    ( (This)->lpVtbl -> AddFileToExtract(This,SourceFileName,TargetFileName,TargetFileHash) ) 

#define IDpxContainer2_AddFileToExtract2(This,SourceFileName,TargetFileName,ppFile)	\
    ( (This)->lpVtbl -> AddFileToExtract2(This,SourceFileName,TargetFileName,ppFile) ) 

#define IDpxContainer2_ExtractAllFiles(This)	\
    ( (This)->lpVtbl -> ExtractAllFiles(This) ) 

#define IDpxContainer2_EnumFilesToExtract(This,ppEnumFiles)	\
    ( (This)->lpVtbl -> EnumFilesToExtract(This,ppEnumFiles) ) 

#define IDpxContainer2_SetExpectedContainerIndexHash(This,pExpectedHash)	\
    ( (This)->lpVtbl -> SetExpectedContainerIndexHash(This,pExpectedHash) ) 

#define IDpxContainer2_GetExpectedContainerIndexHash(This,ppExpectedHash)	\
    ( (This)->lpVtbl -> GetExpectedContainerIndexHash(This,ppExpectedHash) ) 

#define IDpxContainer2_ProvideContainerIndex(This,IndexSize,IndexData)	\
    ( (This)->lpVtbl -> ProvideContainerIndex(This,IndexSize,IndexData) ) 

#define IDpxContainer2_ProvideContainerIndexByFile(This,IndexFileName)	\
    ( (This)->lpVtbl -> ProvideContainerIndexByFile(This,IndexFileName) ) 

#define IDpxContainer2_EnumDirectoryEntries(This,ppEnumEntries)	\
    ( (This)->lpVtbl -> EnumDirectoryEntries(This,ppEnumEntries) ) 

#define IDpxContainer2_Remove(This)	\
    ( (This)->lpVtbl -> Remove(This) ) 

#define IDpxContainer2_SetUserValue(This,UserValue)	\
    ( (This)->lpVtbl -> SetUserValue(This,UserValue) ) 

#define IDpxContainer2_GetUserValue(This,pUserValue)	\
    ( (This)->lpVtbl -> GetUserValue(This,pUserValue) ) 

#define IDpxContainer2_FreeMemory(This,Allocation)	\
    ( (This)->lpVtbl -> FreeMemory(This,Allocation) ) 


#define IDpxContainer2_SetContainerDecryption(This,DecryptionDataCount,DecryptionData,EncryptionType)	\
    ( (This)->lpVtbl -> SetContainerDecryption(This,DecryptionDataCount,DecryptionData,EncryptionType) ) 


#define IDpxContainer2_AddPredecessorContainer(This,ContainerPath,PredecessorFilePathsCount,PredecessorFilePaths,ppContainer)	\
    ( (This)->lpVtbl -> AddPredecessorContainer(This,ContainerPath,PredecessorFilePathsCount,PredecessorFilePaths,ppContainer) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDpxContainer2_INTERFACE_DEFINED__ */


#ifndef __IDpxContainer3_INTERFACE_DEFINED__
#define __IDpxContainer3_INTERFACE_DEFINED__

/* interface IDpxContainer3 */
/* [unique][object][uuid] */ 


EXTERN_C const IID IID_IDpxContainer3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("582f768c-fe7d-4bf5-b0b8-3ab01d53b0d0")
    IDpxContainer3 : public IDpxContainer2
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AddPeerContainer( 
            /* [annotation][in] */ 
            _In_  LPCWSTR ContainerPath,
            /* [annotation][out] */ 
            _Out_  IDpxContainer3 **ppContainer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsPeer( 
            /* [annotation][in] */ 
            _In_  IDpxContainer3 *ppOtherContainer,
            /* [annotation][out] */ 
            _Out_  BOOL *pIsPeer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPeerGroupId( 
            /* [annotation][out] */ 
            _Out_  UINT64 *pnPeerGroupId) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IDpxContainer3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IDpxContainer3 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IDpxContainer3 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IDpxContainer3 * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetContainerPath )( 
            __RPC__in IDpxContainer3 * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR ContainerPath);
        
        HRESULT ( STDMETHODCALLTYPE *GetContainerPath )( 
            __RPC__in IDpxContainer3 * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *pContainerPath);
        
        HRESULT ( STDMETHODCALLTYPE *AddFileToExtract )( 
            __RPC__in IDpxContainer3 * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR SourceFileName,
            /* [annotation][unique][in] */ 
            _In_  LPCWSTR TargetFileName,
            /* [annotation][unique][in] */ 
            _In_  DPX_HASH *TargetFileHash);
        
        HRESULT ( STDMETHODCALLTYPE *AddFileToExtract2 )( 
            __RPC__in IDpxContainer3 * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR SourceFileName,
            /* [annotation][unique][in] */ 
            _In_  LPCWSTR TargetFileName,
            /* [annotation][out] */ 
            _Out_  IDpxFile **ppFile);
        
        HRESULT ( STDMETHODCALLTYPE *ExtractAllFiles )( 
            __RPC__in IDpxContainer3 * This);
        
        HRESULT ( STDMETHODCALLTYPE *EnumFilesToExtract )( 
            __RPC__in IDpxContainer3 * This,
            /* [annotation][out] */ 
            _Out_  IEnumDpxFiles **ppEnumFiles);
        
        HRESULT ( STDMETHODCALLTYPE *SetExpectedContainerIndexHash )( 
            __RPC__in IDpxContainer3 * This,
            /* [annotation][in] */ 
            _In_  DPX_HASH *pExpectedHash);
        
        HRESULT ( STDMETHODCALLTYPE *GetExpectedContainerIndexHash )( 
            __RPC__in IDpxContainer3 * This,
            /* [annotation][out] */ 
            _Out_  DPX_HASH **ppExpectedHash);
        
        HRESULT ( STDMETHODCALLTYPE *ProvideContainerIndex )( 
            __RPC__in IDpxContainer3 * This,
            /* [annotation][in] */ 
            _In_  UINT IndexSize,
            /* [annotation][size_is][in] */ 
            _In_reads_(IndexSize)  BYTE IndexData[  ]);
        
        HRESULT ( STDMETHODCALLTYPE *ProvideContainerIndexByFile )( 
            __RPC__in IDpxContainer3 * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR IndexFileName);
        
        HRESULT ( STDMETHODCALLTYPE *EnumDirectoryEntries )( 
            __RPC__in IDpxContainer3 * This,
            /* [annotation][out] */ 
            _Out_  IEnumDpxContainerDirectoryEntries **ppEnumEntries);
        
        HRESULT ( STDMETHODCALLTYPE *Remove )( 
            __RPC__in IDpxContainer3 * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetUserValue )( 
            __RPC__in IDpxContainer3 * This,
            /* [annotation][in] */ 
            _In_  UINT64 UserValue);
        
        HRESULT ( STDMETHODCALLTYPE *GetUserValue )( 
            __RPC__in IDpxContainer3 * This,
            /* [annotation][out] */ 
            _Out_  UINT64 *pUserValue);
        
        /* [local] */ void ( STDMETHODCALLTYPE *FreeMemory )( 
            IDpxContainer3 * This,
            /* [annotation][in] */ 
            _In_  void *Allocation);
        
        HRESULT ( STDMETHODCALLTYPE *SetContainerDecryption )( 
            __RPC__in IDpxContainer3 * This,
            /* [annotation][in] */ 
            _In_  UINT DecryptionDataCount,
            /* [annotation][size_is][in] */ 
            _In_reads_(DecryptionDataCount)  DpxContainerDecryptionData DecryptionData[  ],
            /* [annotation][in] */ 
            _In_  DPX_CONTAINER_ENCRYPTION_ENUM EncryptionType);
        
        HRESULT ( STDMETHODCALLTYPE *AddPredecessorContainer )( 
            __RPC__in IDpxContainer3 * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR ContainerPath,
            /* [annotation][in] */ 
            _In_  UINT PredecessorFilePathsCount,
            /* [annotation][size_is][in] */ 
            _In_reads_(PredecessorFilePathsCount)  PredecessorFilePathInfo PredecessorFilePaths[  ],
            /* [annotation][out] */ 
            _Out_  IDpxContainer2 **ppContainer);
        
        HRESULT ( STDMETHODCALLTYPE *AddPeerContainer )( 
            __RPC__in IDpxContainer3 * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR ContainerPath,
            /* [annotation][out] */ 
            _Out_  IDpxContainer3 **ppContainer);
        
        HRESULT ( STDMETHODCALLTYPE *IsPeer )( 
            __RPC__in IDpxContainer3 * This,
            /* [annotation][in] */ 
            _In_  IDpxContainer3 *ppOtherContainer,
            /* [annotation][out] */ 
            _Out_  BOOL *pIsPeer);
        
        HRESULT ( STDMETHODCALLTYPE *GetPeerGroupId )( 
            __RPC__in IDpxContainer3 * This,
            /* [annotation][out] */ 
            _Out_  UINT64 *pnPeerGroupId);
        
        END_INTERFACE
    } IDpxContainer3Vtbl;

    interface IDpxContainer3
    {
        CONST_VTBL struct IDpxContainer3Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDpxContainer3_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDpxContainer3_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDpxContainer3_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDpxContainer3_SetContainerPath(This,ContainerPath)	\
    ( (This)->lpVtbl -> SetContainerPath(This,ContainerPath) ) 

#define IDpxContainer3_GetContainerPath(This,pContainerPath)	\
    ( (This)->lpVtbl -> GetContainerPath(This,pContainerPath) ) 

#define IDpxContainer3_AddFileToExtract(This,SourceFileName,TargetFileName,TargetFileHash)	\
    ( (This)->lpVtbl -> AddFileToExtract(This,SourceFileName,TargetFileName,TargetFileHash) ) 

#define IDpxContainer3_AddFileToExtract2(This,SourceFileName,TargetFileName,ppFile)	\
    ( (This)->lpVtbl -> AddFileToExtract2(This,SourceFileName,TargetFileName,ppFile) ) 

#define IDpxContainer3_ExtractAllFiles(This)	\
    ( (This)->lpVtbl -> ExtractAllFiles(This) ) 

#define IDpxContainer3_EnumFilesToExtract(This,ppEnumFiles)	\
    ( (This)->lpVtbl -> EnumFilesToExtract(This,ppEnumFiles) ) 

#define IDpxContainer3_SetExpectedContainerIndexHash(This,pExpectedHash)	\
    ( (This)->lpVtbl -> SetExpectedContainerIndexHash(This,pExpectedHash) ) 

#define IDpxContainer3_GetExpectedContainerIndexHash(This,ppExpectedHash)	\
    ( (This)->lpVtbl -> GetExpectedContainerIndexHash(This,ppExpectedHash) ) 

#define IDpxContainer3_ProvideContainerIndex(This,IndexSize,IndexData)	\
    ( (This)->lpVtbl -> ProvideContainerIndex(This,IndexSize,IndexData) ) 

#define IDpxContainer3_ProvideContainerIndexByFile(This,IndexFileName)	\
    ( (This)->lpVtbl -> ProvideContainerIndexByFile(This,IndexFileName) ) 

#define IDpxContainer3_EnumDirectoryEntries(This,ppEnumEntries)	\
    ( (This)->lpVtbl -> EnumDirectoryEntries(This,ppEnumEntries) ) 

#define IDpxContainer3_Remove(This)	\
    ( (This)->lpVtbl -> Remove(This) ) 

#define IDpxContainer3_SetUserValue(This,UserValue)	\
    ( (This)->lpVtbl -> SetUserValue(This,UserValue) ) 

#define IDpxContainer3_GetUserValue(This,pUserValue)	\
    ( (This)->lpVtbl -> GetUserValue(This,pUserValue) ) 

#define IDpxContainer3_FreeMemory(This,Allocation)	\
    ( (This)->lpVtbl -> FreeMemory(This,Allocation) ) 


#define IDpxContainer3_SetContainerDecryption(This,DecryptionDataCount,DecryptionData,EncryptionType)	\
    ( (This)->lpVtbl -> SetContainerDecryption(This,DecryptionDataCount,DecryptionData,EncryptionType) ) 


#define IDpxContainer3_AddPredecessorContainer(This,ContainerPath,PredecessorFilePathsCount,PredecessorFilePaths,ppContainer)	\
    ( (This)->lpVtbl -> AddPredecessorContainer(This,ContainerPath,PredecessorFilePathsCount,PredecessorFilePaths,ppContainer) ) 


#define IDpxContainer3_AddPeerContainer(This,ContainerPath,ppContainer)	\
    ( (This)->lpVtbl -> AddPeerContainer(This,ContainerPath,ppContainer) ) 

#define IDpxContainer3_IsPeer(This,ppOtherContainer,pIsPeer)	\
    ( (This)->lpVtbl -> IsPeer(This,ppOtherContainer,pIsPeer) ) 

#define IDpxContainer3_GetPeerGroupId(This,pnPeerGroupId)	\
    ( (This)->lpVtbl -> GetPeerGroupId(This,pnPeerGroupId) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDpxContainer3_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_dpx1_0000_0015 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_dpx1_0000_0015_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_dpx1_0000_0015_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


