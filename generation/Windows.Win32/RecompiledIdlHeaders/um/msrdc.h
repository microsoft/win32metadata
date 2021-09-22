

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

#ifndef __msrdc_h__
#define __msrdc_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IRdcGeneratorParameters_FWD_DEFINED__
#define __IRdcGeneratorParameters_FWD_DEFINED__
typedef interface IRdcGeneratorParameters IRdcGeneratorParameters;

#endif 	/* __IRdcGeneratorParameters_FWD_DEFINED__ */


#ifndef __IRdcGeneratorFilterMaxParameters_FWD_DEFINED__
#define __IRdcGeneratorFilterMaxParameters_FWD_DEFINED__
typedef interface IRdcGeneratorFilterMaxParameters IRdcGeneratorFilterMaxParameters;

#endif 	/* __IRdcGeneratorFilterMaxParameters_FWD_DEFINED__ */


#ifndef __IRdcGenerator_FWD_DEFINED__
#define __IRdcGenerator_FWD_DEFINED__
typedef interface IRdcGenerator IRdcGenerator;

#endif 	/* __IRdcGenerator_FWD_DEFINED__ */


#ifndef __IRdcFileReader_FWD_DEFINED__
#define __IRdcFileReader_FWD_DEFINED__
typedef interface IRdcFileReader IRdcFileReader;

#endif 	/* __IRdcFileReader_FWD_DEFINED__ */


#ifndef __IRdcFileWriter_FWD_DEFINED__
#define __IRdcFileWriter_FWD_DEFINED__
typedef interface IRdcFileWriter IRdcFileWriter;

#endif 	/* __IRdcFileWriter_FWD_DEFINED__ */


#ifndef __IRdcSignatureReader_FWD_DEFINED__
#define __IRdcSignatureReader_FWD_DEFINED__
typedef interface IRdcSignatureReader IRdcSignatureReader;

#endif 	/* __IRdcSignatureReader_FWD_DEFINED__ */


#ifndef __IRdcComparator_FWD_DEFINED__
#define __IRdcComparator_FWD_DEFINED__
typedef interface IRdcComparator IRdcComparator;

#endif 	/* __IRdcComparator_FWD_DEFINED__ */


#ifndef __IRdcLibrary_FWD_DEFINED__
#define __IRdcLibrary_FWD_DEFINED__
typedef interface IRdcLibrary IRdcLibrary;

#endif 	/* __IRdcLibrary_FWD_DEFINED__ */


#ifndef __ISimilarityReportProgress_FWD_DEFINED__
#define __ISimilarityReportProgress_FWD_DEFINED__
typedef interface ISimilarityReportProgress ISimilarityReportProgress;

#endif 	/* __ISimilarityReportProgress_FWD_DEFINED__ */


#ifndef __ISimilarityTableDumpState_FWD_DEFINED__
#define __ISimilarityTableDumpState_FWD_DEFINED__
typedef interface ISimilarityTableDumpState ISimilarityTableDumpState;

#endif 	/* __ISimilarityTableDumpState_FWD_DEFINED__ */


#ifndef __ISimilarityTraitsMappedView_FWD_DEFINED__
#define __ISimilarityTraitsMappedView_FWD_DEFINED__
typedef interface ISimilarityTraitsMappedView ISimilarityTraitsMappedView;

#endif 	/* __ISimilarityTraitsMappedView_FWD_DEFINED__ */


#ifndef __ISimilarityTraitsMapping_FWD_DEFINED__
#define __ISimilarityTraitsMapping_FWD_DEFINED__
typedef interface ISimilarityTraitsMapping ISimilarityTraitsMapping;

#endif 	/* __ISimilarityTraitsMapping_FWD_DEFINED__ */


#ifndef __ISimilarityTraitsTable_FWD_DEFINED__
#define __ISimilarityTraitsTable_FWD_DEFINED__
typedef interface ISimilarityTraitsTable ISimilarityTraitsTable;

#endif 	/* __ISimilarityTraitsTable_FWD_DEFINED__ */


#ifndef __ISimilarityFileIdTable_FWD_DEFINED__
#define __ISimilarityFileIdTable_FWD_DEFINED__
typedef interface ISimilarityFileIdTable ISimilarityFileIdTable;

#endif 	/* __ISimilarityFileIdTable_FWD_DEFINED__ */


#ifndef __IRdcSimilarityGenerator_FWD_DEFINED__
#define __IRdcSimilarityGenerator_FWD_DEFINED__
typedef interface IRdcSimilarityGenerator IRdcSimilarityGenerator;

#endif 	/* __IRdcSimilarityGenerator_FWD_DEFINED__ */


#ifndef __IFindSimilarResults_FWD_DEFINED__
#define __IFindSimilarResults_FWD_DEFINED__
typedef interface IFindSimilarResults IFindSimilarResults;

#endif 	/* __IFindSimilarResults_FWD_DEFINED__ */


#ifndef __ISimilarity_FWD_DEFINED__
#define __ISimilarity_FWD_DEFINED__
typedef interface ISimilarity ISimilarity;

#endif 	/* __ISimilarity_FWD_DEFINED__ */


#ifndef __RdcLibrary_FWD_DEFINED__
#define __RdcLibrary_FWD_DEFINED__

#ifdef __cplusplus
typedef class RdcLibrary RdcLibrary;
#else
typedef struct RdcLibrary RdcLibrary;
#endif /* __cplusplus */

#endif 	/* __RdcLibrary_FWD_DEFINED__ */


#ifndef __RdcGeneratorParameters_FWD_DEFINED__
#define __RdcGeneratorParameters_FWD_DEFINED__

#ifdef __cplusplus
typedef class RdcGeneratorParameters RdcGeneratorParameters;
#else
typedef struct RdcGeneratorParameters RdcGeneratorParameters;
#endif /* __cplusplus */

#endif 	/* __RdcGeneratorParameters_FWD_DEFINED__ */


#ifndef __RdcGeneratorFilterMaxParameters_FWD_DEFINED__
#define __RdcGeneratorFilterMaxParameters_FWD_DEFINED__

#ifdef __cplusplus
typedef class RdcGeneratorFilterMaxParameters RdcGeneratorFilterMaxParameters;
#else
typedef struct RdcGeneratorFilterMaxParameters RdcGeneratorFilterMaxParameters;
#endif /* __cplusplus */

#endif 	/* __RdcGeneratorFilterMaxParameters_FWD_DEFINED__ */


#ifndef __RdcGenerator_FWD_DEFINED__
#define __RdcGenerator_FWD_DEFINED__

#ifdef __cplusplus
typedef class RdcGenerator RdcGenerator;
#else
typedef struct RdcGenerator RdcGenerator;
#endif /* __cplusplus */

#endif 	/* __RdcGenerator_FWD_DEFINED__ */


#ifndef __RdcFileReader_FWD_DEFINED__
#define __RdcFileReader_FWD_DEFINED__

#ifdef __cplusplus
typedef class RdcFileReader RdcFileReader;
#else
typedef struct RdcFileReader RdcFileReader;
#endif /* __cplusplus */

#endif 	/* __RdcFileReader_FWD_DEFINED__ */


#ifndef __RdcSignatureReader_FWD_DEFINED__
#define __RdcSignatureReader_FWD_DEFINED__

#ifdef __cplusplus
typedef class RdcSignatureReader RdcSignatureReader;
#else
typedef struct RdcSignatureReader RdcSignatureReader;
#endif /* __cplusplus */

#endif 	/* __RdcSignatureReader_FWD_DEFINED__ */


#ifndef __RdcComparator_FWD_DEFINED__
#define __RdcComparator_FWD_DEFINED__

#ifdef __cplusplus
typedef class RdcComparator RdcComparator;
#else
typedef struct RdcComparator RdcComparator;
#endif /* __cplusplus */

#endif 	/* __RdcComparator_FWD_DEFINED__ */


#ifndef __SimilarityReportProgress_FWD_DEFINED__
#define __SimilarityReportProgress_FWD_DEFINED__

#ifdef __cplusplus
typedef class SimilarityReportProgress SimilarityReportProgress;
#else
typedef struct SimilarityReportProgress SimilarityReportProgress;
#endif /* __cplusplus */

#endif 	/* __SimilarityReportProgress_FWD_DEFINED__ */


#ifndef __SimilarityTableDumpState_FWD_DEFINED__
#define __SimilarityTableDumpState_FWD_DEFINED__

#ifdef __cplusplus
typedef class SimilarityTableDumpState SimilarityTableDumpState;
#else
typedef struct SimilarityTableDumpState SimilarityTableDumpState;
#endif /* __cplusplus */

#endif 	/* __SimilarityTableDumpState_FWD_DEFINED__ */


#ifndef __SimilarityTraitsTable_FWD_DEFINED__
#define __SimilarityTraitsTable_FWD_DEFINED__

#ifdef __cplusplus
typedef class SimilarityTraitsTable SimilarityTraitsTable;
#else
typedef struct SimilarityTraitsTable SimilarityTraitsTable;
#endif /* __cplusplus */

#endif 	/* __SimilarityTraitsTable_FWD_DEFINED__ */


#ifndef __SimilarityFileIdTable_FWD_DEFINED__
#define __SimilarityFileIdTable_FWD_DEFINED__

#ifdef __cplusplus
typedef class SimilarityFileIdTable SimilarityFileIdTable;
#else
typedef struct SimilarityFileIdTable SimilarityFileIdTable;
#endif /* __cplusplus */

#endif 	/* __SimilarityFileIdTable_FWD_DEFINED__ */


#ifndef __Similarity_FWD_DEFINED__
#define __Similarity_FWD_DEFINED__

#ifdef __cplusplus
typedef class Similarity Similarity;
#else
typedef struct Similarity Similarity;
#endif /* __cplusplus */

#endif 	/* __Similarity_FWD_DEFINED__ */


#ifndef __RdcSimilarityGenerator_FWD_DEFINED__
#define __RdcSimilarityGenerator_FWD_DEFINED__

#ifdef __cplusplus
typedef class RdcSimilarityGenerator RdcSimilarityGenerator;
#else
typedef struct RdcSimilarityGenerator RdcSimilarityGenerator;
#endif /* __cplusplus */

#endif 	/* __RdcSimilarityGenerator_FWD_DEFINED__ */


#ifndef __FindSimilarResults_FWD_DEFINED__
#define __FindSimilarResults_FWD_DEFINED__

#ifdef __cplusplus
typedef class FindSimilarResults FindSimilarResults;
#else
typedef struct FindSimilarResults FindSimilarResults;
#endif /* __cplusplus */

#endif 	/* __FindSimilarResults_FWD_DEFINED__ */


#ifndef __SimilarityTraitsMapping_FWD_DEFINED__
#define __SimilarityTraitsMapping_FWD_DEFINED__

#ifdef __cplusplus
typedef class SimilarityTraitsMapping SimilarityTraitsMapping;
#else
typedef struct SimilarityTraitsMapping SimilarityTraitsMapping;
#endif /* __cplusplus */

#endif 	/* __SimilarityTraitsMapping_FWD_DEFINED__ */


#ifndef __SimilarityTraitsMappedView_FWD_DEFINED__
#define __SimilarityTraitsMappedView_FWD_DEFINED__

#ifdef __cplusplus
typedef class SimilarityTraitsMappedView SimilarityTraitsMappedView;
#else
typedef struct SimilarityTraitsMappedView SimilarityTraitsMappedView;
#endif /* __cplusplus */

#endif 	/* __SimilarityTraitsMappedView_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_msrdc_0000_0000 */
/* [local] */ 

#include <winapifamily.h>
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
#define	RDCE_TABLE_FULL	( 0x80040001 )

#define	RDCE_TABLE_CORRUPT	( 0x80040002 )

#pragma warning( disable: 4100 )
#pragma warning( disable: 4152 )
const ULONG MSRDC_VERSION = 0x010000;
const ULONG MSRDC_MINIMUM_COMPATIBLE_APP_VERSION = 0x010000;
const ULONG MSRDC_MINIMUM_DEPTH = 1;
const ULONG MSRDC_MAXIMUM_DEPTH = 8;
const ULONG MSRDC_MINIMUM_COMPAREBUFFER = 100000;
const ULONG MSRDC_MAXIMUM_COMPAREBUFFER = (1<<30);
const ULONG MSRDC_DEFAULT_COMPAREBUFFER = 3200000;
const ULONG MSRDC_MINIMUM_INPUTBUFFERSIZE = 1024;
#define	MSRDC_SIGNATURE_HASHSIZE	( 16 )

const ULONG MSRDC_MINIMUM_HORIZONSIZE = 128;
const ULONG MSRDC_MAXIMUM_HORIZONSIZE = 1024 * 16;
const ULONG MSRDC_MINIMUM_HASHWINDOWSIZE = 2;
const ULONG MSRDC_MAXIMUM_HASHWINDOWSIZE = 96;
const ULONG MSRDC_DEFAULT_HASHWINDOWSIZE_1 = 48;
const ULONG MSRDC_DEFAULT_HORIZONSIZE_1    = 1024;
const ULONG MSRDC_DEFAULT_HASHWINDOWSIZE_N = 2;
const ULONG MSRDC_DEFAULT_HORIZONSIZE_N    = 128;
const ULONG MSRDC_MAXIMUM_TRAITVALUE = 63;
const ULONG MSRDC_MINIMUM_MATCHESREQUIRED = 1;
const ULONG MSRDC_MAXIMUM_MATCHESREQUIRED = 16;
typedef /* [public][public][public][public] */ 
enum __MIDL___MIDL_itf_msrdc_0000_0000_0001
    {
        RDC_NoError	= 0,
        RDC_HeaderVersionNewer	= ( RDC_NoError + 1 ) ,
        RDC_HeaderVersionOlder	= ( RDC_HeaderVersionNewer + 1 ) ,
        RDC_HeaderMissingOrCorrupt	= ( RDC_HeaderVersionOlder + 1 ) ,
        RDC_HeaderWrongType	= ( RDC_HeaderMissingOrCorrupt + 1 ) ,
        RDC_DataMissingOrCorrupt	= ( RDC_HeaderWrongType + 1 ) ,
        RDC_DataTooManyRecords	= ( RDC_DataMissingOrCorrupt + 1 ) ,
        RDC_FileChecksumMismatch	= ( RDC_DataTooManyRecords + 1 ) ,
        RDC_ApplicationError	= ( RDC_FileChecksumMismatch + 1 ) ,
        RDC_Aborted	= ( RDC_ApplicationError + 1 ) ,
        RDC_Win32Error	= ( RDC_Aborted + 1 ) 
    } 	RDC_ErrorCode;

typedef /* [public][public][public] */ 
enum __MIDL___MIDL_itf_msrdc_0000_0000_0002
    {
        RDCGENTYPE_Unused	= 0,
        RDCGENTYPE_FilterMax	= ( RDCGENTYPE_Unused + 1 ) 
    } 	GeneratorParametersType;

typedef /* [public][public][public][public] */ 
enum __MIDL___MIDL_itf_msrdc_0000_0000_0003
    {
        RDCNEED_SOURCE	= 0,
        RDCNEED_TARGET	= 1,
        RDCNEED_SEED	= 2,
        RDCNEED_SEED_MAX	= 255
    } 	RdcNeedType;

typedef /* [public][public][public] */ struct __MIDL___MIDL_itf_msrdc_0000_0000_0004
    {
    RdcNeedType m_BlockType;
    unsigned __int64 m_FileOffset;
    unsigned __int64 m_BlockLength;
    } 	RdcNeed;

typedef /* [public][public][public][public] */ struct __MIDL___MIDL_itf_msrdc_0000_0000_0005
    {
    ULONG m_Size;
    ULONG m_Used;
    BYTE *m_Data;
    } 	RdcBufferPointer;

typedef /* [public][public] */ struct __MIDL___MIDL_itf_msrdc_0000_0000_0006
    {
    ULONG m_Size;
    ULONG m_Used;
    RdcNeed *m_Data;
    } 	RdcNeedPointer;

typedef /* [public][public][public] */ struct __MIDL___MIDL_itf_msrdc_0000_0000_0007
    {
    BYTE m_Signature[ 16 ];
    USHORT m_BlockLength;
    } 	RdcSignature;

typedef /* [public][public] */ struct __MIDL___MIDL_itf_msrdc_0000_0000_0008
    {
    ULONG m_Size;
    ULONG m_Used;
    RdcSignature *m_Data;
    } 	RdcSignaturePointer;

typedef unsigned int SimilarityFileIndexT;

typedef /* [public][public][public][public][public][public][public] */ 
enum __MIDL___MIDL_itf_msrdc_0000_0000_0009
    {
        RDCTABLE_InvalidOrUnknown	= 0,
        RDCTABLE_Existing	= ( RDCTABLE_InvalidOrUnknown + 1 ) ,
        RDCTABLE_New	= ( RDCTABLE_Existing + 1 ) 
    } 	RdcCreatedTables;

typedef /* [public][public][public][public] */ 
enum __MIDL___MIDL_itf_msrdc_0000_0000_0010
    {
        RDCMAPPING_Undefined	= 0,
        RDCMAPPING_ReadOnly	= ( RDCMAPPING_Undefined + 1 ) ,
        RDCMAPPING_ReadWrite	= ( RDCMAPPING_ReadOnly + 1 ) 
    } 	RdcMappingAccessMode;

typedef /* [public][public] */ struct __MIDL___MIDL_itf_msrdc_0000_0000_0011
    {
    unsigned char *m_Data;
    DWORD m_Length;
    } 	SimilarityMappedViewInfo;

typedef /* [public][public][public][public][public][public][public][public] */ struct __MIDL___MIDL_itf_msrdc_0000_0000_0012
    {
    unsigned char m_Data[ 16 ];
    } 	SimilarityData;

typedef /* [public][public] */ struct __MIDL___MIDL_itf_msrdc_0000_0000_0013
    {
    SimilarityFileIndexT m_FileIndex;
    unsigned int m_MatchCount;
    } 	FindSimilarFileIndexResults;

typedef /* [public][public] */ struct __MIDL___MIDL_itf_msrdc_0000_0000_0014
    {
    SimilarityFileIndexT m_FileIndex;
    SimilarityData m_Data;
    } 	SimilarityDumpData;

#define	SimilarityFileIdMinSize	( 4 )

#define	SimilarityFileIdMaxSize	( 32 )

typedef /* [public][public][public][public][public] */ struct __MIDL___MIDL_itf_msrdc_0000_0000_0015
    {
    byte m_FileId[ 32 ];
    } 	SimilarityFileId;



extern RPC_IF_HANDLE __MIDL_itf_msrdc_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_msrdc_0000_0000_v0_0_s_ifspec;

#ifndef __IRdcGeneratorParameters_INTERFACE_DEFINED__
#define __IRdcGeneratorParameters_INTERFACE_DEFINED__

/* interface IRdcGeneratorParameters */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRdcGeneratorParameters;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("96236A71-9DBC-11DA-9E3F-0011114AE311")
    IRdcGeneratorParameters : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetGeneratorParametersType( 
            /* [annotation][out] */ 
            _Out_  GeneratorParametersType *parametersType) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetParametersVersion( 
            /* [annotation][out] */ 
            _Out_  ULONG *currentVersion,
            /* [annotation][out] */ 
            _Out_  ULONG *minimumCompatibleAppVersion) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetSerializeSize( 
            /* [annotation][out] */ 
            _Out_  ULONG *size) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Serialize( 
            /* [annotation][in] */ 
            _In_  ULONG size,
            /* [annotation][out] */ 
            _Out_  BYTE *parametersBlob,
            /* [annotation][out] */ 
            _Out_  ULONG *bytesWritten) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRdcGeneratorParametersVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IRdcGeneratorParameters * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IRdcGeneratorParameters * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IRdcGeneratorParameters * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetGeneratorParametersType )( 
            __RPC__in IRdcGeneratorParameters * This,
            /* [annotation][out] */ 
            _Out_  GeneratorParametersType *parametersType);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetParametersVersion )( 
            __RPC__in IRdcGeneratorParameters * This,
            /* [annotation][out] */ 
            _Out_  ULONG *currentVersion,
            /* [annotation][out] */ 
            _Out_  ULONG *minimumCompatibleAppVersion);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetSerializeSize )( 
            __RPC__in IRdcGeneratorParameters * This,
            /* [annotation][out] */ 
            _Out_  ULONG *size);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Serialize )( 
            __RPC__in IRdcGeneratorParameters * This,
            /* [annotation][in] */ 
            _In_  ULONG size,
            /* [annotation][out] */ 
            _Out_  BYTE *parametersBlob,
            /* [annotation][out] */ 
            _Out_  ULONG *bytesWritten);
        
        END_INTERFACE
    } IRdcGeneratorParametersVtbl;

    interface IRdcGeneratorParameters
    {
        CONST_VTBL struct IRdcGeneratorParametersVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRdcGeneratorParameters_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRdcGeneratorParameters_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRdcGeneratorParameters_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRdcGeneratorParameters_GetGeneratorParametersType(This,parametersType)	\
    ( (This)->lpVtbl -> GetGeneratorParametersType(This,parametersType) ) 

#define IRdcGeneratorParameters_GetParametersVersion(This,currentVersion,minimumCompatibleAppVersion)	\
    ( (This)->lpVtbl -> GetParametersVersion(This,currentVersion,minimumCompatibleAppVersion) ) 

#define IRdcGeneratorParameters_GetSerializeSize(This,size)	\
    ( (This)->lpVtbl -> GetSerializeSize(This,size) ) 

#define IRdcGeneratorParameters_Serialize(This,size,parametersBlob,bytesWritten)	\
    ( (This)->lpVtbl -> Serialize(This,size,parametersBlob,bytesWritten) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRdcGeneratorParameters_INTERFACE_DEFINED__ */


#ifndef __IRdcGeneratorFilterMaxParameters_INTERFACE_DEFINED__
#define __IRdcGeneratorFilterMaxParameters_INTERFACE_DEFINED__

/* interface IRdcGeneratorFilterMaxParameters */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_IRdcGeneratorFilterMaxParameters;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("96236A72-9DBC-11DA-9E3F-0011114AE311")
    IRdcGeneratorFilterMaxParameters : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetHorizonSize( 
            /* [annotation][out] */ 
            _Out_  ULONG *horizonSize) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetHorizonSize( 
            /* [annotation][in] */ 
            _In_  ULONG horizonSize) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetHashWindowSize( 
            /* [annotation][out] */ 
            _Out_  ULONG *hashWindowSize) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetHashWindowSize( 
            /* [annotation][in] */ 
            _In_  ULONG hashWindowSize) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRdcGeneratorFilterMaxParametersVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRdcGeneratorFilterMaxParameters * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRdcGeneratorFilterMaxParameters * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRdcGeneratorFilterMaxParameters * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetHorizonSize )( 
            IRdcGeneratorFilterMaxParameters * This,
            /* [annotation][out] */ 
            _Out_  ULONG *horizonSize);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetHorizonSize )( 
            IRdcGeneratorFilterMaxParameters * This,
            /* [annotation][in] */ 
            _In_  ULONG horizonSize);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetHashWindowSize )( 
            IRdcGeneratorFilterMaxParameters * This,
            /* [annotation][out] */ 
            _Out_  ULONG *hashWindowSize);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetHashWindowSize )( 
            IRdcGeneratorFilterMaxParameters * This,
            /* [annotation][in] */ 
            _In_  ULONG hashWindowSize);
        
        END_INTERFACE
    } IRdcGeneratorFilterMaxParametersVtbl;

    interface IRdcGeneratorFilterMaxParameters
    {
        CONST_VTBL struct IRdcGeneratorFilterMaxParametersVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRdcGeneratorFilterMaxParameters_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRdcGeneratorFilterMaxParameters_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRdcGeneratorFilterMaxParameters_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRdcGeneratorFilterMaxParameters_GetHorizonSize(This,horizonSize)	\
    ( (This)->lpVtbl -> GetHorizonSize(This,horizonSize) ) 

#define IRdcGeneratorFilterMaxParameters_SetHorizonSize(This,horizonSize)	\
    ( (This)->lpVtbl -> SetHorizonSize(This,horizonSize) ) 

#define IRdcGeneratorFilterMaxParameters_GetHashWindowSize(This,hashWindowSize)	\
    ( (This)->lpVtbl -> GetHashWindowSize(This,hashWindowSize) ) 

#define IRdcGeneratorFilterMaxParameters_SetHashWindowSize(This,hashWindowSize)	\
    ( (This)->lpVtbl -> SetHashWindowSize(This,hashWindowSize) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRdcGeneratorFilterMaxParameters_INTERFACE_DEFINED__ */


#ifndef __IRdcGenerator_INTERFACE_DEFINED__
#define __IRdcGenerator_INTERFACE_DEFINED__

/* interface IRdcGenerator */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_IRdcGenerator;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("96236A73-9DBC-11DA-9E3F-0011114AE311")
    IRdcGenerator : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetGeneratorParameters( 
            /* [annotation][in] */ 
            _In_  ULONG level,
            /* [annotation][out] */ 
            _Out_  IRdcGeneratorParameters **iGeneratorParameters) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Process( 
            /* [annotation][in] */ 
            _In_  BOOL endOfInput,
            /* [annotation][out] */ 
            _Out_  BOOL *endOfOutput,
            /* [annotation][out][in] */ 
            _Inout_  RdcBufferPointer *inputBuffer,
            /* [annotation][in] */ 
            _In_  ULONG depth,
            /* [annotation][size_is][out] */ 
            _Out_writes_(depth)  RdcBufferPointer *outputBuffers[  ],
            /* [annotation][out] */ 
            _Out_  RDC_ErrorCode *rdc_ErrorCode) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRdcGeneratorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRdcGenerator * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRdcGenerator * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRdcGenerator * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetGeneratorParameters )( 
            IRdcGenerator * This,
            /* [annotation][in] */ 
            _In_  ULONG level,
            /* [annotation][out] */ 
            _Out_  IRdcGeneratorParameters **iGeneratorParameters);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Process )( 
            IRdcGenerator * This,
            /* [annotation][in] */ 
            _In_  BOOL endOfInput,
            /* [annotation][out] */ 
            _Out_  BOOL *endOfOutput,
            /* [annotation][out][in] */ 
            _Inout_  RdcBufferPointer *inputBuffer,
            /* [annotation][in] */ 
            _In_  ULONG depth,
            /* [annotation][size_is][out] */ 
            _Out_writes_(depth)  RdcBufferPointer *outputBuffers[  ],
            /* [annotation][out] */ 
            _Out_  RDC_ErrorCode *rdc_ErrorCode);
        
        END_INTERFACE
    } IRdcGeneratorVtbl;

    interface IRdcGenerator
    {
        CONST_VTBL struct IRdcGeneratorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRdcGenerator_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRdcGenerator_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRdcGenerator_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRdcGenerator_GetGeneratorParameters(This,level,iGeneratorParameters)	\
    ( (This)->lpVtbl -> GetGeneratorParameters(This,level,iGeneratorParameters) ) 

#define IRdcGenerator_Process(This,endOfInput,endOfOutput,inputBuffer,depth,outputBuffers,rdc_ErrorCode)	\
    ( (This)->lpVtbl -> Process(This,endOfInput,endOfOutput,inputBuffer,depth,outputBuffers,rdc_ErrorCode) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRdcGenerator_INTERFACE_DEFINED__ */


#ifndef __IRdcFileReader_INTERFACE_DEFINED__
#define __IRdcFileReader_INTERFACE_DEFINED__

/* interface IRdcFileReader */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_IRdcFileReader;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("96236A74-9DBC-11DA-9E3F-0011114AE311")
    IRdcFileReader : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetFileSize( 
            /* [annotation][out] */ 
            _Out_  ULONGLONG *fileSize) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Read( 
            /* [annotation][in] */ 
            _In_  ULONGLONG offsetFileStart,
            /* [annotation][in] */ 
            _In_  ULONG bytesToRead,
            /* [annotation][out] */ 
            _Out_  ULONG *bytesActuallyRead,
            /* [annotation][out] */ 
            _Out_  BYTE *buffer,
            /* [annotation][out] */ 
            _Out_  BOOL *eof) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetFilePosition( 
            /* [annotation][out] */ 
            _Out_  ULONGLONG *offsetFromStart) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRdcFileReaderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRdcFileReader * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRdcFileReader * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRdcFileReader * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetFileSize )( 
            IRdcFileReader * This,
            /* [annotation][out] */ 
            _Out_  ULONGLONG *fileSize);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Read )( 
            IRdcFileReader * This,
            /* [annotation][in] */ 
            _In_  ULONGLONG offsetFileStart,
            /* [annotation][in] */ 
            _In_  ULONG bytesToRead,
            /* [annotation][out] */ 
            _Out_  ULONG *bytesActuallyRead,
            /* [annotation][out] */ 
            _Out_  BYTE *buffer,
            /* [annotation][out] */ 
            _Out_  BOOL *eof);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetFilePosition )( 
            IRdcFileReader * This,
            /* [annotation][out] */ 
            _Out_  ULONGLONG *offsetFromStart);
        
        END_INTERFACE
    } IRdcFileReaderVtbl;

    interface IRdcFileReader
    {
        CONST_VTBL struct IRdcFileReaderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRdcFileReader_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRdcFileReader_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRdcFileReader_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRdcFileReader_GetFileSize(This,fileSize)	\
    ( (This)->lpVtbl -> GetFileSize(This,fileSize) ) 

#define IRdcFileReader_Read(This,offsetFileStart,bytesToRead,bytesActuallyRead,buffer,eof)	\
    ( (This)->lpVtbl -> Read(This,offsetFileStart,bytesToRead,bytesActuallyRead,buffer,eof) ) 

#define IRdcFileReader_GetFilePosition(This,offsetFromStart)	\
    ( (This)->lpVtbl -> GetFilePosition(This,offsetFromStart) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRdcFileReader_INTERFACE_DEFINED__ */


#ifndef __IRdcFileWriter_INTERFACE_DEFINED__
#define __IRdcFileWriter_INTERFACE_DEFINED__

/* interface IRdcFileWriter */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_IRdcFileWriter;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("96236A75-9DBC-11DA-9E3F-0011114AE311")
    IRdcFileWriter : public IRdcFileReader
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Write( 
            /* [annotation][in] */ 
            _In_  ULONGLONG offsetFileStart,
            /* [annotation][in] */ 
            _In_  ULONG bytesToWrite,
            /* [annotation][out] */ 
            _Out_  BYTE *buffer) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Truncate( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE DeleteOnClose( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRdcFileWriterVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRdcFileWriter * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRdcFileWriter * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRdcFileWriter * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetFileSize )( 
            IRdcFileWriter * This,
            /* [annotation][out] */ 
            _Out_  ULONGLONG *fileSize);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Read )( 
            IRdcFileWriter * This,
            /* [annotation][in] */ 
            _In_  ULONGLONG offsetFileStart,
            /* [annotation][in] */ 
            _In_  ULONG bytesToRead,
            /* [annotation][out] */ 
            _Out_  ULONG *bytesActuallyRead,
            /* [annotation][out] */ 
            _Out_  BYTE *buffer,
            /* [annotation][out] */ 
            _Out_  BOOL *eof);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetFilePosition )( 
            IRdcFileWriter * This,
            /* [annotation][out] */ 
            _Out_  ULONGLONG *offsetFromStart);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Write )( 
            IRdcFileWriter * This,
            /* [annotation][in] */ 
            _In_  ULONGLONG offsetFileStart,
            /* [annotation][in] */ 
            _In_  ULONG bytesToWrite,
            /* [annotation][out] */ 
            _Out_  BYTE *buffer);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Truncate )( 
            IRdcFileWriter * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *DeleteOnClose )( 
            IRdcFileWriter * This);
        
        END_INTERFACE
    } IRdcFileWriterVtbl;

    interface IRdcFileWriter
    {
        CONST_VTBL struct IRdcFileWriterVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRdcFileWriter_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRdcFileWriter_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRdcFileWriter_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRdcFileWriter_GetFileSize(This,fileSize)	\
    ( (This)->lpVtbl -> GetFileSize(This,fileSize) ) 

#define IRdcFileWriter_Read(This,offsetFileStart,bytesToRead,bytesActuallyRead,buffer,eof)	\
    ( (This)->lpVtbl -> Read(This,offsetFileStart,bytesToRead,bytesActuallyRead,buffer,eof) ) 

#define IRdcFileWriter_GetFilePosition(This,offsetFromStart)	\
    ( (This)->lpVtbl -> GetFilePosition(This,offsetFromStart) ) 


#define IRdcFileWriter_Write(This,offsetFileStart,bytesToWrite,buffer)	\
    ( (This)->lpVtbl -> Write(This,offsetFileStart,bytesToWrite,buffer) ) 

#define IRdcFileWriter_Truncate(This)	\
    ( (This)->lpVtbl -> Truncate(This) ) 

#define IRdcFileWriter_DeleteOnClose(This)	\
    ( (This)->lpVtbl -> DeleteOnClose(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRdcFileWriter_INTERFACE_DEFINED__ */


#ifndef __IRdcSignatureReader_INTERFACE_DEFINED__
#define __IRdcSignatureReader_INTERFACE_DEFINED__

/* interface IRdcSignatureReader */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_IRdcSignatureReader;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("96236A76-9DBC-11DA-9E3F-0011114AE311")
    IRdcSignatureReader : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ReadHeader( 
            /* [annotation][out] */ 
            _Out_  RDC_ErrorCode *rdc_ErrorCode) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ReadSignatures( 
            /* [annotation][out][in] */ 
            _Inout_  RdcSignaturePointer *rdcSignaturePointer,
            /* [annotation][out] */ 
            _Out_  BOOL *endOfOutput) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRdcSignatureReaderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRdcSignatureReader * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRdcSignatureReader * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRdcSignatureReader * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ReadHeader )( 
            IRdcSignatureReader * This,
            /* [annotation][out] */ 
            _Out_  RDC_ErrorCode *rdc_ErrorCode);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ReadSignatures )( 
            IRdcSignatureReader * This,
            /* [annotation][out][in] */ 
            _Inout_  RdcSignaturePointer *rdcSignaturePointer,
            /* [annotation][out] */ 
            _Out_  BOOL *endOfOutput);
        
        END_INTERFACE
    } IRdcSignatureReaderVtbl;

    interface IRdcSignatureReader
    {
        CONST_VTBL struct IRdcSignatureReaderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRdcSignatureReader_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRdcSignatureReader_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRdcSignatureReader_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRdcSignatureReader_ReadHeader(This,rdc_ErrorCode)	\
    ( (This)->lpVtbl -> ReadHeader(This,rdc_ErrorCode) ) 

#define IRdcSignatureReader_ReadSignatures(This,rdcSignaturePointer,endOfOutput)	\
    ( (This)->lpVtbl -> ReadSignatures(This,rdcSignaturePointer,endOfOutput) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRdcSignatureReader_INTERFACE_DEFINED__ */


#ifndef __IRdcComparator_INTERFACE_DEFINED__
#define __IRdcComparator_INTERFACE_DEFINED__

/* interface IRdcComparator */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_IRdcComparator;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("96236A77-9DBC-11DA-9E3F-0011114AE311")
    IRdcComparator : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Process( 
            /* [annotation][in] */ 
            _In_  BOOL endOfInput,
            /* [annotation][out] */ 
            _Out_  BOOL *endOfOutput,
            /* [annotation][out][in] */ 
            _Inout_  RdcBufferPointer *inputBuffer,
            /* [annotation][out][in] */ 
            _Inout_  RdcNeedPointer *outputBuffer,
            /* [annotation][out] */ 
            _Out_  RDC_ErrorCode *rdc_ErrorCode) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRdcComparatorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRdcComparator * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRdcComparator * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRdcComparator * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Process )( 
            IRdcComparator * This,
            /* [annotation][in] */ 
            _In_  BOOL endOfInput,
            /* [annotation][out] */ 
            _Out_  BOOL *endOfOutput,
            /* [annotation][out][in] */ 
            _Inout_  RdcBufferPointer *inputBuffer,
            /* [annotation][out][in] */ 
            _Inout_  RdcNeedPointer *outputBuffer,
            /* [annotation][out] */ 
            _Out_  RDC_ErrorCode *rdc_ErrorCode);
        
        END_INTERFACE
    } IRdcComparatorVtbl;

    interface IRdcComparator
    {
        CONST_VTBL struct IRdcComparatorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRdcComparator_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRdcComparator_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRdcComparator_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRdcComparator_Process(This,endOfInput,endOfOutput,inputBuffer,outputBuffer,rdc_ErrorCode)	\
    ( (This)->lpVtbl -> Process(This,endOfInput,endOfOutput,inputBuffer,outputBuffer,rdc_ErrorCode) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRdcComparator_INTERFACE_DEFINED__ */


#ifndef __IRdcLibrary_INTERFACE_DEFINED__
#define __IRdcLibrary_INTERFACE_DEFINED__

/* interface IRdcLibrary */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_IRdcLibrary;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("96236A78-9DBC-11DA-9E3F-0011114AE311")
    IRdcLibrary : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ComputeDefaultRecursionDepth( 
            /* [annotation][in] */ 
            _In_  ULONGLONG fileSize,
            /* [annotation][out] */ 
            _Out_  ULONG *depth) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CreateGeneratorParameters( 
            /* [annotation][in] */ 
            _In_  GeneratorParametersType parametersType,
            /* [annotation][in] */ 
            _In_  ULONG level,
            /* [annotation][out] */ 
            _Out_  IRdcGeneratorParameters **iGeneratorParameters) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OpenGeneratorParameters( 
            /* [annotation][in] */ 
            _In_  ULONG size,
            /* [annotation][in] */ 
            _In_  const BYTE *parametersBlob,
            /* [annotation][out] */ 
            _Out_  IRdcGeneratorParameters **iGeneratorParameters) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CreateGenerator( 
            /* [annotation][in] */ 
            _In_  ULONG depth,
            /* [annotation][size_is][in] */ 
            _In_reads_(depth)  IRdcGeneratorParameters *iGeneratorParametersArray[  ],
            /* [annotation][out] */ 
            _Out_  IRdcGenerator **iGenerator) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CreateComparator( 
            /* [annotation][in] */ 
            _In_  IRdcFileReader *iSeedSignaturesFile,
            /* [annotation][in] */ 
            _In_  ULONG comparatorBufferSize,
            /* [annotation][out] */ 
            _Out_  IRdcComparator **iComparator) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CreateSignatureReader( 
            /* [annotation][in] */ 
            _In_  IRdcFileReader *iFileReader,
            /* [annotation][out] */ 
            _Out_  IRdcSignatureReader **iSignatureReader) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetRDCVersion( 
            /* [annotation][out] */ 
            _Out_  ULONG *currentVersion,
            /* [annotation][out] */ 
            _Out_  ULONG *minimumCompatibleAppVersion) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRdcLibraryVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRdcLibrary * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRdcLibrary * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRdcLibrary * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ComputeDefaultRecursionDepth )( 
            IRdcLibrary * This,
            /* [annotation][in] */ 
            _In_  ULONGLONG fileSize,
            /* [annotation][out] */ 
            _Out_  ULONG *depth);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CreateGeneratorParameters )( 
            IRdcLibrary * This,
            /* [annotation][in] */ 
            _In_  GeneratorParametersType parametersType,
            /* [annotation][in] */ 
            _In_  ULONG level,
            /* [annotation][out] */ 
            _Out_  IRdcGeneratorParameters **iGeneratorParameters);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *OpenGeneratorParameters )( 
            IRdcLibrary * This,
            /* [annotation][in] */ 
            _In_  ULONG size,
            /* [annotation][in] */ 
            _In_  const BYTE *parametersBlob,
            /* [annotation][out] */ 
            _Out_  IRdcGeneratorParameters **iGeneratorParameters);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CreateGenerator )( 
            IRdcLibrary * This,
            /* [annotation][in] */ 
            _In_  ULONG depth,
            /* [annotation][size_is][in] */ 
            _In_reads_(depth)  IRdcGeneratorParameters *iGeneratorParametersArray[  ],
            /* [annotation][out] */ 
            _Out_  IRdcGenerator **iGenerator);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CreateComparator )( 
            IRdcLibrary * This,
            /* [annotation][in] */ 
            _In_  IRdcFileReader *iSeedSignaturesFile,
            /* [annotation][in] */ 
            _In_  ULONG comparatorBufferSize,
            /* [annotation][out] */ 
            _Out_  IRdcComparator **iComparator);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CreateSignatureReader )( 
            IRdcLibrary * This,
            /* [annotation][in] */ 
            _In_  IRdcFileReader *iFileReader,
            /* [annotation][out] */ 
            _Out_  IRdcSignatureReader **iSignatureReader);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetRDCVersion )( 
            IRdcLibrary * This,
            /* [annotation][out] */ 
            _Out_  ULONG *currentVersion,
            /* [annotation][out] */ 
            _Out_  ULONG *minimumCompatibleAppVersion);
        
        END_INTERFACE
    } IRdcLibraryVtbl;

    interface IRdcLibrary
    {
        CONST_VTBL struct IRdcLibraryVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRdcLibrary_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRdcLibrary_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRdcLibrary_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRdcLibrary_ComputeDefaultRecursionDepth(This,fileSize,depth)	\
    ( (This)->lpVtbl -> ComputeDefaultRecursionDepth(This,fileSize,depth) ) 

#define IRdcLibrary_CreateGeneratorParameters(This,parametersType,level,iGeneratorParameters)	\
    ( (This)->lpVtbl -> CreateGeneratorParameters(This,parametersType,level,iGeneratorParameters) ) 

#define IRdcLibrary_OpenGeneratorParameters(This,size,parametersBlob,iGeneratorParameters)	\
    ( (This)->lpVtbl -> OpenGeneratorParameters(This,size,parametersBlob,iGeneratorParameters) ) 

#define IRdcLibrary_CreateGenerator(This,depth,iGeneratorParametersArray,iGenerator)	\
    ( (This)->lpVtbl -> CreateGenerator(This,depth,iGeneratorParametersArray,iGenerator) ) 

#define IRdcLibrary_CreateComparator(This,iSeedSignaturesFile,comparatorBufferSize,iComparator)	\
    ( (This)->lpVtbl -> CreateComparator(This,iSeedSignaturesFile,comparatorBufferSize,iComparator) ) 

#define IRdcLibrary_CreateSignatureReader(This,iFileReader,iSignatureReader)	\
    ( (This)->lpVtbl -> CreateSignatureReader(This,iFileReader,iSignatureReader) ) 

#define IRdcLibrary_GetRDCVersion(This,currentVersion,minimumCompatibleAppVersion)	\
    ( (This)->lpVtbl -> GetRDCVersion(This,currentVersion,minimumCompatibleAppVersion) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRdcLibrary_INTERFACE_DEFINED__ */


#ifndef __ISimilarityReportProgress_INTERFACE_DEFINED__
#define __ISimilarityReportProgress_INTERFACE_DEFINED__

/* interface ISimilarityReportProgress */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_ISimilarityReportProgress;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("96236A7A-9DBC-11DA-9E3F-0011114AE311")
    ISimilarityReportProgress : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ReportProgress( 
            /* [annotation][in] */ 
            _In_  DWORD percentCompleted) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISimilarityReportProgressVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISimilarityReportProgress * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISimilarityReportProgress * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISimilarityReportProgress * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ReportProgress )( 
            ISimilarityReportProgress * This,
            /* [annotation][in] */ 
            _In_  DWORD percentCompleted);
        
        END_INTERFACE
    } ISimilarityReportProgressVtbl;

    interface ISimilarityReportProgress
    {
        CONST_VTBL struct ISimilarityReportProgressVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISimilarityReportProgress_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISimilarityReportProgress_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISimilarityReportProgress_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISimilarityReportProgress_ReportProgress(This,percentCompleted)	\
    ( (This)->lpVtbl -> ReportProgress(This,percentCompleted) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISimilarityReportProgress_INTERFACE_DEFINED__ */


#ifndef __ISimilarityTableDumpState_INTERFACE_DEFINED__
#define __ISimilarityTableDumpState_INTERFACE_DEFINED__

/* interface ISimilarityTableDumpState */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_ISimilarityTableDumpState;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("96236A7B-9DBC-11DA-9E3F-0011114AE311")
    ISimilarityTableDumpState : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetNextData( 
            /* [annotation][in] */ 
            _In_  DWORD resultsSize,
            /* [annotation][out] */ 
            _Out_  DWORD *resultsUsed,
            /* [annotation][out] */ 
            _Out_  BOOL *eof,
            /* [annotation][out][in] */ 
            _Inout_  SimilarityDumpData *results) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISimilarityTableDumpStateVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISimilarityTableDumpState * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISimilarityTableDumpState * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISimilarityTableDumpState * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetNextData )( 
            ISimilarityTableDumpState * This,
            /* [annotation][in] */ 
            _In_  DWORD resultsSize,
            /* [annotation][out] */ 
            _Out_  DWORD *resultsUsed,
            /* [annotation][out] */ 
            _Out_  BOOL *eof,
            /* [annotation][out][in] */ 
            _Inout_  SimilarityDumpData *results);
        
        END_INTERFACE
    } ISimilarityTableDumpStateVtbl;

    interface ISimilarityTableDumpState
    {
        CONST_VTBL struct ISimilarityTableDumpStateVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISimilarityTableDumpState_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISimilarityTableDumpState_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISimilarityTableDumpState_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISimilarityTableDumpState_GetNextData(This,resultsSize,resultsUsed,eof,results)	\
    ( (This)->lpVtbl -> GetNextData(This,resultsSize,resultsUsed,eof,results) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISimilarityTableDumpState_INTERFACE_DEFINED__ */


#ifndef __ISimilarityTraitsMappedView_INTERFACE_DEFINED__
#define __ISimilarityTraitsMappedView_INTERFACE_DEFINED__

/* interface ISimilarityTraitsMappedView */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_ISimilarityTraitsMappedView;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("96236A7C-9DBC-11DA-9E3F-0011114AE311")
    ISimilarityTraitsMappedView : public IUnknown
    {
    public:
        virtual /* [local][helpstring] */ HRESULT STDMETHODCALLTYPE Flush( void) = 0;
        
        virtual /* [local][helpstring] */ HRESULT STDMETHODCALLTYPE Unmap( void) = 0;
        
        virtual /* [local][helpstring] */ HRESULT STDMETHODCALLTYPE Get( 
            /* [annotation][in] */ 
            _In_  unsigned __int64 index,
            /* [annotation][in] */ 
            _In_  BOOL dirty,
            /* [annotation][in] */ 
            _In_  DWORD numElements,
            /* [annotation][out] */ 
            _Out_  SimilarityMappedViewInfo *viewInfo) = 0;
        
        virtual /* [local][helpstring] */ void STDMETHODCALLTYPE GetView( 
            /* [annotation][out] */ 
            _Out_  const unsigned char **mappedPageBegin,
            /* [annotation][out] */ 
            _Out_  const unsigned char **mappedPageEnd) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISimilarityTraitsMappedViewVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISimilarityTraitsMappedView * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISimilarityTraitsMappedView * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISimilarityTraitsMappedView * This);
        
        /* [local][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Flush )( 
            ISimilarityTraitsMappedView * This);
        
        /* [local][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Unmap )( 
            ISimilarityTraitsMappedView * This);
        
        /* [local][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Get )( 
            ISimilarityTraitsMappedView * This,
            /* [annotation][in] */ 
            _In_  unsigned __int64 index,
            /* [annotation][in] */ 
            _In_  BOOL dirty,
            /* [annotation][in] */ 
            _In_  DWORD numElements,
            /* [annotation][out] */ 
            _Out_  SimilarityMappedViewInfo *viewInfo);
        
        /* [local][helpstring] */ void ( STDMETHODCALLTYPE *GetView )( 
            ISimilarityTraitsMappedView * This,
            /* [annotation][out] */ 
            _Out_  const unsigned char **mappedPageBegin,
            /* [annotation][out] */ 
            _Out_  const unsigned char **mappedPageEnd);
        
        END_INTERFACE
    } ISimilarityTraitsMappedViewVtbl;

    interface ISimilarityTraitsMappedView
    {
        CONST_VTBL struct ISimilarityTraitsMappedViewVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISimilarityTraitsMappedView_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISimilarityTraitsMappedView_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISimilarityTraitsMappedView_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISimilarityTraitsMappedView_Flush(This)	\
    ( (This)->lpVtbl -> Flush(This) ) 

#define ISimilarityTraitsMappedView_Unmap(This)	\
    ( (This)->lpVtbl -> Unmap(This) ) 

#define ISimilarityTraitsMappedView_Get(This,index,dirty,numElements,viewInfo)	\
    ( (This)->lpVtbl -> Get(This,index,dirty,numElements,viewInfo) ) 

#define ISimilarityTraitsMappedView_GetView(This,mappedPageBegin,mappedPageEnd)	\
    ( (This)->lpVtbl -> GetView(This,mappedPageBegin,mappedPageEnd) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISimilarityTraitsMappedView_INTERFACE_DEFINED__ */


#ifndef __ISimilarityTraitsMapping_INTERFACE_DEFINED__
#define __ISimilarityTraitsMapping_INTERFACE_DEFINED__

/* interface ISimilarityTraitsMapping */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_ISimilarityTraitsMapping;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("96236A7D-9DBC-11DA-9E3F-0011114AE311")
    ISimilarityTraitsMapping : public IUnknown
    {
    public:
        virtual /* [local][helpstring] */ void STDMETHODCALLTYPE CloseMapping( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetFileSize( 
            /* [annotation][in] */ 
            _In_  unsigned __int64 fileSize) = 0;
        
        virtual /* [local][helpstring] */ HRESULT STDMETHODCALLTYPE GetFileSize( 
            /* [annotation][out] */ 
            _Out_  unsigned __int64 *fileSize) = 0;
        
        virtual /* [local][helpstring] */ HRESULT STDMETHODCALLTYPE OpenMapping( 
            /* [annotation][in] */ 
            _In_  RdcMappingAccessMode accessMode,
            /* [annotation][in] */ 
            _In_  unsigned __int64 begin,
            /* [annotation][in] */ 
            _In_  unsigned __int64 end,
            /* [annotation][out] */ 
            _Out_  unsigned __int64 *actualEnd) = 0;
        
        virtual /* [local][helpstring] */ HRESULT STDMETHODCALLTYPE ResizeMapping( 
            /* [annotation][in] */ 
            _In_  RdcMappingAccessMode accessMode,
            /* [annotation][in] */ 
            _In_  unsigned __int64 begin,
            /* [annotation][in] */ 
            _In_  unsigned __int64 end,
            /* [annotation][out] */ 
            _Out_  unsigned __int64 *actualEnd) = 0;
        
        virtual /* [local][helpstring] */ void STDMETHODCALLTYPE GetPageSize( 
            /* [annotation][out] */ 
            _Out_  DWORD *pageSize) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CreateView( 
            /* [annotation][in] */ 
            _In_  DWORD minimumMappedPages,
            /* [annotation][in] */ 
            _In_  RdcMappingAccessMode accessMode,
            /* [annotation][out] */ 
            _Out_  ISimilarityTraitsMappedView **mappedView) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISimilarityTraitsMappingVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISimilarityTraitsMapping * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISimilarityTraitsMapping * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISimilarityTraitsMapping * This);
        
        /* [local][helpstring] */ void ( STDMETHODCALLTYPE *CloseMapping )( 
            ISimilarityTraitsMapping * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetFileSize )( 
            ISimilarityTraitsMapping * This,
            /* [annotation][in] */ 
            _In_  unsigned __int64 fileSize);
        
        /* [local][helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetFileSize )( 
            ISimilarityTraitsMapping * This,
            /* [annotation][out] */ 
            _Out_  unsigned __int64 *fileSize);
        
        /* [local][helpstring] */ HRESULT ( STDMETHODCALLTYPE *OpenMapping )( 
            ISimilarityTraitsMapping * This,
            /* [annotation][in] */ 
            _In_  RdcMappingAccessMode accessMode,
            /* [annotation][in] */ 
            _In_  unsigned __int64 begin,
            /* [annotation][in] */ 
            _In_  unsigned __int64 end,
            /* [annotation][out] */ 
            _Out_  unsigned __int64 *actualEnd);
        
        /* [local][helpstring] */ HRESULT ( STDMETHODCALLTYPE *ResizeMapping )( 
            ISimilarityTraitsMapping * This,
            /* [annotation][in] */ 
            _In_  RdcMappingAccessMode accessMode,
            /* [annotation][in] */ 
            _In_  unsigned __int64 begin,
            /* [annotation][in] */ 
            _In_  unsigned __int64 end,
            /* [annotation][out] */ 
            _Out_  unsigned __int64 *actualEnd);
        
        /* [local][helpstring] */ void ( STDMETHODCALLTYPE *GetPageSize )( 
            ISimilarityTraitsMapping * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pageSize);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CreateView )( 
            ISimilarityTraitsMapping * This,
            /* [annotation][in] */ 
            _In_  DWORD minimumMappedPages,
            /* [annotation][in] */ 
            _In_  RdcMappingAccessMode accessMode,
            /* [annotation][out] */ 
            _Out_  ISimilarityTraitsMappedView **mappedView);
        
        END_INTERFACE
    } ISimilarityTraitsMappingVtbl;

    interface ISimilarityTraitsMapping
    {
        CONST_VTBL struct ISimilarityTraitsMappingVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISimilarityTraitsMapping_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISimilarityTraitsMapping_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISimilarityTraitsMapping_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISimilarityTraitsMapping_CloseMapping(This)	\
    ( (This)->lpVtbl -> CloseMapping(This) ) 

#define ISimilarityTraitsMapping_SetFileSize(This,fileSize)	\
    ( (This)->lpVtbl -> SetFileSize(This,fileSize) ) 

#define ISimilarityTraitsMapping_GetFileSize(This,fileSize)	\
    ( (This)->lpVtbl -> GetFileSize(This,fileSize) ) 

#define ISimilarityTraitsMapping_OpenMapping(This,accessMode,begin,end,actualEnd)	\
    ( (This)->lpVtbl -> OpenMapping(This,accessMode,begin,end,actualEnd) ) 

#define ISimilarityTraitsMapping_ResizeMapping(This,accessMode,begin,end,actualEnd)	\
    ( (This)->lpVtbl -> ResizeMapping(This,accessMode,begin,end,actualEnd) ) 

#define ISimilarityTraitsMapping_GetPageSize(This,pageSize)	\
    ( (This)->lpVtbl -> GetPageSize(This,pageSize) ) 

#define ISimilarityTraitsMapping_CreateView(This,minimumMappedPages,accessMode,mappedView)	\
    ( (This)->lpVtbl -> CreateView(This,minimumMappedPages,accessMode,mappedView) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISimilarityTraitsMapping_INTERFACE_DEFINED__ */


#ifndef __ISimilarityTraitsTable_INTERFACE_DEFINED__
#define __ISimilarityTraitsTable_INTERFACE_DEFINED__

/* interface ISimilarityTraitsTable */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_ISimilarityTraitsTable;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("96236A7E-9DBC-11DA-9E3F-0011114AE311")
    ISimilarityTraitsTable : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CreateTable( 
            /* [annotation][in] */ 
            _In_  wchar_t *path,
            /* [annotation][in] */ 
            _In_  BOOL truncate,
            /* [annotation][in] */ 
            _In_  BYTE *securityDescriptor,
            /* [annotation][out] */ 
            _Out_  RdcCreatedTables *isNew) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CreateTableIndirect( 
            /* [annotation][in] */ 
            _In_  ISimilarityTraitsMapping *mapping,
            /* [annotation][in] */ 
            _In_  BOOL truncate,
            /* [annotation][out] */ 
            _Out_  RdcCreatedTables *isNew) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CloseTable( 
            BOOL isValid) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Append( 
            /* [annotation][in] */ 
            _In_  SimilarityData *data,
            /* [annotation][in] */ 
            _In_  SimilarityFileIndexT fileIndex) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE FindSimilarFileIndex( 
            /* [annotation][in] */ 
            _In_  SimilarityData *similarityData,
            /* [annotation][in] */ 
            _In_  USHORT numberOfMatchesRequired,
            /* [annotation][out] */ 
            _Out_  FindSimilarFileIndexResults *findSimilarFileIndexResults,
            /* [annotation][in] */ 
            _In_  DWORD resultsSize,
            /* [annotation][out] */ 
            _Out_  DWORD *resultsUsed) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE BeginDump( 
            /* [annotation][out] */ 
            _Out_  ISimilarityTableDumpState **similarityTableDumpState) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetLastIndex( 
            /* [annotation][out] */ 
            _Out_  SimilarityFileIndexT *fileIndex) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISimilarityTraitsTableVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISimilarityTraitsTable * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISimilarityTraitsTable * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISimilarityTraitsTable * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CreateTable )( 
            ISimilarityTraitsTable * This,
            /* [annotation][in] */ 
            _In_  wchar_t *path,
            /* [annotation][in] */ 
            _In_  BOOL truncate,
            /* [annotation][in] */ 
            _In_  BYTE *securityDescriptor,
            /* [annotation][out] */ 
            _Out_  RdcCreatedTables *isNew);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CreateTableIndirect )( 
            ISimilarityTraitsTable * This,
            /* [annotation][in] */ 
            _In_  ISimilarityTraitsMapping *mapping,
            /* [annotation][in] */ 
            _In_  BOOL truncate,
            /* [annotation][out] */ 
            _Out_  RdcCreatedTables *isNew);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CloseTable )( 
            ISimilarityTraitsTable * This,
            BOOL isValid);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Append )( 
            ISimilarityTraitsTable * This,
            /* [annotation][in] */ 
            _In_  SimilarityData *data,
            /* [annotation][in] */ 
            _In_  SimilarityFileIndexT fileIndex);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *FindSimilarFileIndex )( 
            ISimilarityTraitsTable * This,
            /* [annotation][in] */ 
            _In_  SimilarityData *similarityData,
            /* [annotation][in] */ 
            _In_  USHORT numberOfMatchesRequired,
            /* [annotation][out] */ 
            _Out_  FindSimilarFileIndexResults *findSimilarFileIndexResults,
            /* [annotation][in] */ 
            _In_  DWORD resultsSize,
            /* [annotation][out] */ 
            _Out_  DWORD *resultsUsed);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *BeginDump )( 
            ISimilarityTraitsTable * This,
            /* [annotation][out] */ 
            _Out_  ISimilarityTableDumpState **similarityTableDumpState);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetLastIndex )( 
            ISimilarityTraitsTable * This,
            /* [annotation][out] */ 
            _Out_  SimilarityFileIndexT *fileIndex);
        
        END_INTERFACE
    } ISimilarityTraitsTableVtbl;

    interface ISimilarityTraitsTable
    {
        CONST_VTBL struct ISimilarityTraitsTableVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISimilarityTraitsTable_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISimilarityTraitsTable_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISimilarityTraitsTable_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISimilarityTraitsTable_CreateTable(This,path,truncate,securityDescriptor,isNew)	\
    ( (This)->lpVtbl -> CreateTable(This,path,truncate,securityDescriptor,isNew) ) 

#define ISimilarityTraitsTable_CreateTableIndirect(This,mapping,truncate,isNew)	\
    ( (This)->lpVtbl -> CreateTableIndirect(This,mapping,truncate,isNew) ) 

#define ISimilarityTraitsTable_CloseTable(This,isValid)	\
    ( (This)->lpVtbl -> CloseTable(This,isValid) ) 

#define ISimilarityTraitsTable_Append(This,data,fileIndex)	\
    ( (This)->lpVtbl -> Append(This,data,fileIndex) ) 

#define ISimilarityTraitsTable_FindSimilarFileIndex(This,similarityData,numberOfMatchesRequired,findSimilarFileIndexResults,resultsSize,resultsUsed)	\
    ( (This)->lpVtbl -> FindSimilarFileIndex(This,similarityData,numberOfMatchesRequired,findSimilarFileIndexResults,resultsSize,resultsUsed) ) 

#define ISimilarityTraitsTable_BeginDump(This,similarityTableDumpState)	\
    ( (This)->lpVtbl -> BeginDump(This,similarityTableDumpState) ) 

#define ISimilarityTraitsTable_GetLastIndex(This,fileIndex)	\
    ( (This)->lpVtbl -> GetLastIndex(This,fileIndex) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISimilarityTraitsTable_INTERFACE_DEFINED__ */


#ifndef __ISimilarityFileIdTable_INTERFACE_DEFINED__
#define __ISimilarityFileIdTable_INTERFACE_DEFINED__

/* interface ISimilarityFileIdTable */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_ISimilarityFileIdTable;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("96236A7F-9DBC-11DA-9E3F-0011114AE311")
    ISimilarityFileIdTable : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CreateTable( 
            /* [annotation][in] */ 
            _In_  wchar_t *path,
            /* [annotation][in] */ 
            _In_  BOOL truncate,
            /* [annotation][in] */ 
            _In_  BYTE *securityDescriptor,
            /* [annotation][in] */ 
            _In_  DWORD recordSize,
            /* [annotation][out] */ 
            _Out_  RdcCreatedTables *isNew) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CreateTableIndirect( 
            /* [annotation][in] */ 
            _In_  IRdcFileWriter *fileIdFile,
            /* [annotation][in] */ 
            _In_  BOOL truncate,
            /* [annotation][in] */ 
            _In_  DWORD recordSize,
            /* [annotation][out] */ 
            _Out_  RdcCreatedTables *isNew) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CloseTable( 
            BOOL isValid) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Append( 
            /* [annotation][in] */ 
            _In_  SimilarityFileId *similarityFileId,
            /* [annotation][out] */ 
            _Out_  SimilarityFileIndexT *similarityFileIndex) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Lookup( 
            /* [annotation][in] */ 
            _In_  SimilarityFileIndexT similarityFileIndex,
            /* [annotation][out] */ 
            _Out_  SimilarityFileId *similarityFileId) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Invalidate( 
            /* [annotation][in] */ 
            _In_  SimilarityFileIndexT similarityFileIndex) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetRecordCount( 
            /* [annotation][out] */ 
            _Out_  DWORD *recordCount) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISimilarityFileIdTableVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISimilarityFileIdTable * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISimilarityFileIdTable * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISimilarityFileIdTable * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CreateTable )( 
            ISimilarityFileIdTable * This,
            /* [annotation][in] */ 
            _In_  wchar_t *path,
            /* [annotation][in] */ 
            _In_  BOOL truncate,
            /* [annotation][in] */ 
            _In_  BYTE *securityDescriptor,
            /* [annotation][in] */ 
            _In_  DWORD recordSize,
            /* [annotation][out] */ 
            _Out_  RdcCreatedTables *isNew);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CreateTableIndirect )( 
            ISimilarityFileIdTable * This,
            /* [annotation][in] */ 
            _In_  IRdcFileWriter *fileIdFile,
            /* [annotation][in] */ 
            _In_  BOOL truncate,
            /* [annotation][in] */ 
            _In_  DWORD recordSize,
            /* [annotation][out] */ 
            _Out_  RdcCreatedTables *isNew);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CloseTable )( 
            ISimilarityFileIdTable * This,
            BOOL isValid);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Append )( 
            ISimilarityFileIdTable * This,
            /* [annotation][in] */ 
            _In_  SimilarityFileId *similarityFileId,
            /* [annotation][out] */ 
            _Out_  SimilarityFileIndexT *similarityFileIndex);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Lookup )( 
            ISimilarityFileIdTable * This,
            /* [annotation][in] */ 
            _In_  SimilarityFileIndexT similarityFileIndex,
            /* [annotation][out] */ 
            _Out_  SimilarityFileId *similarityFileId);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Invalidate )( 
            ISimilarityFileIdTable * This,
            /* [annotation][in] */ 
            _In_  SimilarityFileIndexT similarityFileIndex);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetRecordCount )( 
            ISimilarityFileIdTable * This,
            /* [annotation][out] */ 
            _Out_  DWORD *recordCount);
        
        END_INTERFACE
    } ISimilarityFileIdTableVtbl;

    interface ISimilarityFileIdTable
    {
        CONST_VTBL struct ISimilarityFileIdTableVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISimilarityFileIdTable_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISimilarityFileIdTable_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISimilarityFileIdTable_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISimilarityFileIdTable_CreateTable(This,path,truncate,securityDescriptor,recordSize,isNew)	\
    ( (This)->lpVtbl -> CreateTable(This,path,truncate,securityDescriptor,recordSize,isNew) ) 

#define ISimilarityFileIdTable_CreateTableIndirect(This,fileIdFile,truncate,recordSize,isNew)	\
    ( (This)->lpVtbl -> CreateTableIndirect(This,fileIdFile,truncate,recordSize,isNew) ) 

#define ISimilarityFileIdTable_CloseTable(This,isValid)	\
    ( (This)->lpVtbl -> CloseTable(This,isValid) ) 

#define ISimilarityFileIdTable_Append(This,similarityFileId,similarityFileIndex)	\
    ( (This)->lpVtbl -> Append(This,similarityFileId,similarityFileIndex) ) 

#define ISimilarityFileIdTable_Lookup(This,similarityFileIndex,similarityFileId)	\
    ( (This)->lpVtbl -> Lookup(This,similarityFileIndex,similarityFileId) ) 

#define ISimilarityFileIdTable_Invalidate(This,similarityFileIndex)	\
    ( (This)->lpVtbl -> Invalidate(This,similarityFileIndex) ) 

#define ISimilarityFileIdTable_GetRecordCount(This,recordCount)	\
    ( (This)->lpVtbl -> GetRecordCount(This,recordCount) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISimilarityFileIdTable_INTERFACE_DEFINED__ */


#ifndef __IRdcSimilarityGenerator_INTERFACE_DEFINED__
#define __IRdcSimilarityGenerator_INTERFACE_DEFINED__

/* interface IRdcSimilarityGenerator */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_IRdcSimilarityGenerator;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("96236A80-9DBC-11DA-9E3F-0011114AE311")
    IRdcSimilarityGenerator : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE EnableSimilarity( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Results( 
            /* [annotation][out] */ 
            _Out_  SimilarityData *similarityData) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRdcSimilarityGeneratorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRdcSimilarityGenerator * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRdcSimilarityGenerator * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRdcSimilarityGenerator * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *EnableSimilarity )( 
            IRdcSimilarityGenerator * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Results )( 
            IRdcSimilarityGenerator * This,
            /* [annotation][out] */ 
            _Out_  SimilarityData *similarityData);
        
        END_INTERFACE
    } IRdcSimilarityGeneratorVtbl;

    interface IRdcSimilarityGenerator
    {
        CONST_VTBL struct IRdcSimilarityGeneratorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRdcSimilarityGenerator_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRdcSimilarityGenerator_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRdcSimilarityGenerator_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRdcSimilarityGenerator_EnableSimilarity(This)	\
    ( (This)->lpVtbl -> EnableSimilarity(This) ) 

#define IRdcSimilarityGenerator_Results(This,similarityData)	\
    ( (This)->lpVtbl -> Results(This,similarityData) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRdcSimilarityGenerator_INTERFACE_DEFINED__ */


#ifndef __IFindSimilarResults_INTERFACE_DEFINED__
#define __IFindSimilarResults_INTERFACE_DEFINED__

/* interface IFindSimilarResults */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_IFindSimilarResults;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("96236A81-9DBC-11DA-9E3F-0011114AE311")
    IFindSimilarResults : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetSize( 
            /* [annotation][out] */ 
            _Out_  DWORD *size) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetNextFileId( 
            /* [annotation][out] */ 
            _Out_  DWORD *numTraitsMatched,
            /* [annotation][out] */ 
            _Out_  SimilarityFileId *similarityFileId) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IFindSimilarResultsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFindSimilarResults * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFindSimilarResults * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFindSimilarResults * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetSize )( 
            IFindSimilarResults * This,
            /* [annotation][out] */ 
            _Out_  DWORD *size);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetNextFileId )( 
            IFindSimilarResults * This,
            /* [annotation][out] */ 
            _Out_  DWORD *numTraitsMatched,
            /* [annotation][out] */ 
            _Out_  SimilarityFileId *similarityFileId);
        
        END_INTERFACE
    } IFindSimilarResultsVtbl;

    interface IFindSimilarResults
    {
        CONST_VTBL struct IFindSimilarResultsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFindSimilarResults_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFindSimilarResults_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFindSimilarResults_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFindSimilarResults_GetSize(This,size)	\
    ( (This)->lpVtbl -> GetSize(This,size) ) 

#define IFindSimilarResults_GetNextFileId(This,numTraitsMatched,similarityFileId)	\
    ( (This)->lpVtbl -> GetNextFileId(This,numTraitsMatched,similarityFileId) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFindSimilarResults_INTERFACE_DEFINED__ */


#ifndef __ISimilarity_INTERFACE_DEFINED__
#define __ISimilarity_INTERFACE_DEFINED__

/* interface ISimilarity */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_ISimilarity;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("96236A83-9DBC-11DA-9E3F-0011114AE311")
    ISimilarity : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CreateTable( 
            /* [annotation][in] */ 
            _In_  wchar_t *path,
            /* [annotation][in] */ 
            _In_  BOOL truncate,
            /* [annotation][in] */ 
            _In_  BYTE *securityDescriptor,
            /* [annotation][in] */ 
            _In_  DWORD recordSize,
            /* [annotation][out] */ 
            _Out_  RdcCreatedTables *isNew) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CreateTableIndirect( 
            /* [annotation][in] */ 
            _In_  ISimilarityTraitsMapping *mapping,
            /* [annotation][in] */ 
            _In_  IRdcFileWriter *fileIdFile,
            /* [annotation][in] */ 
            _In_  BOOL truncate,
            /* [annotation][in] */ 
            _In_  DWORD recordSize,
            /* [annotation][out] */ 
            _Out_  RdcCreatedTables *isNew) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CloseTable( 
            /* [annotation][in] */ 
            _In_  BOOL isValid) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Append( 
            /* [annotation][in] */ 
            _In_  SimilarityFileId *similarityFileId,
            /* [annotation][in] */ 
            _In_  SimilarityData *similarityData) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE FindSimilarFileId( 
            /* [annotation][in] */ 
            _In_  SimilarityData *similarityData,
            /* [annotation][in] */ 
            _In_  USHORT numberOfMatchesRequired,
            /* [annotation][in] */ 
            _In_  DWORD resultsSize,
            /* [annotation][out] */ 
            _Out_  IFindSimilarResults **findSimilarResults) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CopyAndSwap( 
            /* [annotation][in] */ 
            _In_  ISimilarity *newSimilarityTables,
            /* [annotation][in] */ 
            _In_  ISimilarityReportProgress *reportProgress) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetRecordCount( 
            /* [annotation][out] */ 
            _Out_  DWORD *recordCount) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISimilarityVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISimilarity * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISimilarity * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISimilarity * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CreateTable )( 
            ISimilarity * This,
            /* [annotation][in] */ 
            _In_  wchar_t *path,
            /* [annotation][in] */ 
            _In_  BOOL truncate,
            /* [annotation][in] */ 
            _In_  BYTE *securityDescriptor,
            /* [annotation][in] */ 
            _In_  DWORD recordSize,
            /* [annotation][out] */ 
            _Out_  RdcCreatedTables *isNew);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CreateTableIndirect )( 
            ISimilarity * This,
            /* [annotation][in] */ 
            _In_  ISimilarityTraitsMapping *mapping,
            /* [annotation][in] */ 
            _In_  IRdcFileWriter *fileIdFile,
            /* [annotation][in] */ 
            _In_  BOOL truncate,
            /* [annotation][in] */ 
            _In_  DWORD recordSize,
            /* [annotation][out] */ 
            _Out_  RdcCreatedTables *isNew);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CloseTable )( 
            ISimilarity * This,
            /* [annotation][in] */ 
            _In_  BOOL isValid);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Append )( 
            ISimilarity * This,
            /* [annotation][in] */ 
            _In_  SimilarityFileId *similarityFileId,
            /* [annotation][in] */ 
            _In_  SimilarityData *similarityData);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *FindSimilarFileId )( 
            ISimilarity * This,
            /* [annotation][in] */ 
            _In_  SimilarityData *similarityData,
            /* [annotation][in] */ 
            _In_  USHORT numberOfMatchesRequired,
            /* [annotation][in] */ 
            _In_  DWORD resultsSize,
            /* [annotation][out] */ 
            _Out_  IFindSimilarResults **findSimilarResults);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CopyAndSwap )( 
            ISimilarity * This,
            /* [annotation][in] */ 
            _In_  ISimilarity *newSimilarityTables,
            /* [annotation][in] */ 
            _In_  ISimilarityReportProgress *reportProgress);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetRecordCount )( 
            ISimilarity * This,
            /* [annotation][out] */ 
            _Out_  DWORD *recordCount);
        
        END_INTERFACE
    } ISimilarityVtbl;

    interface ISimilarity
    {
        CONST_VTBL struct ISimilarityVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISimilarity_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISimilarity_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISimilarity_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISimilarity_CreateTable(This,path,truncate,securityDescriptor,recordSize,isNew)	\
    ( (This)->lpVtbl -> CreateTable(This,path,truncate,securityDescriptor,recordSize,isNew) ) 

#define ISimilarity_CreateTableIndirect(This,mapping,fileIdFile,truncate,recordSize,isNew)	\
    ( (This)->lpVtbl -> CreateTableIndirect(This,mapping,fileIdFile,truncate,recordSize,isNew) ) 

#define ISimilarity_CloseTable(This,isValid)	\
    ( (This)->lpVtbl -> CloseTable(This,isValid) ) 

#define ISimilarity_Append(This,similarityFileId,similarityData)	\
    ( (This)->lpVtbl -> Append(This,similarityFileId,similarityData) ) 

#define ISimilarity_FindSimilarFileId(This,similarityData,numberOfMatchesRequired,resultsSize,findSimilarResults)	\
    ( (This)->lpVtbl -> FindSimilarFileId(This,similarityData,numberOfMatchesRequired,resultsSize,findSimilarResults) ) 

#define ISimilarity_CopyAndSwap(This,newSimilarityTables,reportProgress)	\
    ( (This)->lpVtbl -> CopyAndSwap(This,newSimilarityTables,reportProgress) ) 

#define ISimilarity_GetRecordCount(This,recordCount)	\
    ( (This)->lpVtbl -> GetRecordCount(This,recordCount) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISimilarity_INTERFACE_DEFINED__ */



#ifndef __MSRDCLib_LIBRARY_DEFINED__
#define __MSRDCLib_LIBRARY_DEFINED__

/* library MSRDCLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_MSRDCLib;

EXTERN_C const CLSID CLSID_RdcLibrary;

#ifdef __cplusplus

class DECLSPEC_UUID("96236A85-9DBC-11DA-9E3F-0011114AE311")
RdcLibrary;
#endif

EXTERN_C const CLSID CLSID_RdcGeneratorParameters;

#ifdef __cplusplus

class DECLSPEC_UUID("96236A86-9DBC-11DA-9E3F-0011114AE311")
RdcGeneratorParameters;
#endif

EXTERN_C const CLSID CLSID_RdcGeneratorFilterMaxParameters;

#ifdef __cplusplus

class DECLSPEC_UUID("96236A87-9DBC-11DA-9E3F-0011114AE311")
RdcGeneratorFilterMaxParameters;
#endif

EXTERN_C const CLSID CLSID_RdcGenerator;

#ifdef __cplusplus

class DECLSPEC_UUID("96236A88-9DBC-11DA-9E3F-0011114AE311")
RdcGenerator;
#endif

EXTERN_C const CLSID CLSID_RdcFileReader;

#ifdef __cplusplus

class DECLSPEC_UUID("96236A89-9DBC-11DA-9E3F-0011114AE311")
RdcFileReader;
#endif

EXTERN_C const CLSID CLSID_RdcSignatureReader;

#ifdef __cplusplus

class DECLSPEC_UUID("96236A8A-9DBC-11DA-9E3F-0011114AE311")
RdcSignatureReader;
#endif

EXTERN_C const CLSID CLSID_RdcComparator;

#ifdef __cplusplus

class DECLSPEC_UUID("96236A8B-9DBC-11DA-9E3F-0011114AE311")
RdcComparator;
#endif

EXTERN_C const CLSID CLSID_SimilarityReportProgress;

#ifdef __cplusplus

class DECLSPEC_UUID("96236A8D-9DBC-11DA-9E3F-0011114AE311")
SimilarityReportProgress;
#endif

EXTERN_C const CLSID CLSID_SimilarityTableDumpState;

#ifdef __cplusplus

class DECLSPEC_UUID("96236A8E-9DBC-11DA-9E3F-0011114AE311")
SimilarityTableDumpState;
#endif

EXTERN_C const CLSID CLSID_SimilarityTraitsTable;

#ifdef __cplusplus

class DECLSPEC_UUID("96236A8F-9DBC-11DA-9E3F-0011114AE311")
SimilarityTraitsTable;
#endif

EXTERN_C const CLSID CLSID_SimilarityFileIdTable;

#ifdef __cplusplus

class DECLSPEC_UUID("96236A90-9DBC-11DA-9E3F-0011114AE311")
SimilarityFileIdTable;
#endif

EXTERN_C const CLSID CLSID_Similarity;

#ifdef __cplusplus

class DECLSPEC_UUID("96236A91-9DBC-11DA-9E3F-0011114AE311")
Similarity;
#endif

EXTERN_C const CLSID CLSID_RdcSimilarityGenerator;

#ifdef __cplusplus

class DECLSPEC_UUID("96236A92-9DBC-11DA-9E3F-0011114AE311")
RdcSimilarityGenerator;
#endif

EXTERN_C const CLSID CLSID_FindSimilarResults;

#ifdef __cplusplus

class DECLSPEC_UUID("96236A93-9DBC-11DA-9E3F-0011114AE311")
FindSimilarResults;
#endif

EXTERN_C const CLSID CLSID_SimilarityTraitsMapping;

#ifdef __cplusplus

class DECLSPEC_UUID("96236A94-9DBC-11DA-9E3F-0011114AE311")
SimilarityTraitsMapping;
#endif

EXTERN_C const CLSID CLSID_SimilarityTraitsMappedView;

#ifdef __cplusplus

class DECLSPEC_UUID("96236A95-9DBC-11DA-9E3F-0011114AE311")
SimilarityTraitsMappedView;
#endif
#endif /* __MSRDCLib_LIBRARY_DEFINED__ */

/* interface __MIDL_itf_msrdc_0000_0018 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_msrdc_0000_0018_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_msrdc_0000_0018_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


