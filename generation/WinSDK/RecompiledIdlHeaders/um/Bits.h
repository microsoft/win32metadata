

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0626 */
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

#ifndef __bits_h__
#define __bits_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef DECLSPEC_XFGVIRT
#if _CONTROL_FLOW_GUARD_XFG
#define DECLSPEC_XFGVIRT(base, func) __declspec(xfg_virtual(base, func))
#else
#define DECLSPEC_XFGVIRT(base, func)
#endif
#endif

/* Forward Declarations */ 

#ifndef __IBackgroundCopyFile_FWD_DEFINED__
#define __IBackgroundCopyFile_FWD_DEFINED__
typedef interface IBackgroundCopyFile IBackgroundCopyFile;

#endif 	/* __IBackgroundCopyFile_FWD_DEFINED__ */


#ifndef __IEnumBackgroundCopyFiles_FWD_DEFINED__
#define __IEnumBackgroundCopyFiles_FWD_DEFINED__
typedef interface IEnumBackgroundCopyFiles IEnumBackgroundCopyFiles;

#endif 	/* __IEnumBackgroundCopyFiles_FWD_DEFINED__ */


#ifndef __IBackgroundCopyError_FWD_DEFINED__
#define __IBackgroundCopyError_FWD_DEFINED__
typedef interface IBackgroundCopyError IBackgroundCopyError;

#endif 	/* __IBackgroundCopyError_FWD_DEFINED__ */


#ifndef __IBackgroundCopyJob_FWD_DEFINED__
#define __IBackgroundCopyJob_FWD_DEFINED__
typedef interface IBackgroundCopyJob IBackgroundCopyJob;

#endif 	/* __IBackgroundCopyJob_FWD_DEFINED__ */


#ifndef __IEnumBackgroundCopyJobs_FWD_DEFINED__
#define __IEnumBackgroundCopyJobs_FWD_DEFINED__
typedef interface IEnumBackgroundCopyJobs IEnumBackgroundCopyJobs;

#endif 	/* __IEnumBackgroundCopyJobs_FWD_DEFINED__ */


#ifndef __IBackgroundCopyCallback_FWD_DEFINED__
#define __IBackgroundCopyCallback_FWD_DEFINED__
typedef interface IBackgroundCopyCallback IBackgroundCopyCallback;

#endif 	/* __IBackgroundCopyCallback_FWD_DEFINED__ */


#ifndef __AsyncIBackgroundCopyCallback_FWD_DEFINED__
#define __AsyncIBackgroundCopyCallback_FWD_DEFINED__
typedef interface AsyncIBackgroundCopyCallback AsyncIBackgroundCopyCallback;

#endif 	/* __AsyncIBackgroundCopyCallback_FWD_DEFINED__ */


#ifndef __IBackgroundCopyManager_FWD_DEFINED__
#define __IBackgroundCopyManager_FWD_DEFINED__
typedef interface IBackgroundCopyManager IBackgroundCopyManager;

#endif 	/* __IBackgroundCopyManager_FWD_DEFINED__ */


#ifndef __BackgroundCopyManager_FWD_DEFINED__
#define __BackgroundCopyManager_FWD_DEFINED__

#ifdef __cplusplus
typedef class BackgroundCopyManager BackgroundCopyManager;
#else
typedef struct BackgroundCopyManager BackgroundCopyManager;
#endif /* __cplusplus */

#endif 	/* __BackgroundCopyManager_FWD_DEFINED__ */


#ifndef __IBackgroundCopyCallback_FWD_DEFINED__
#define __IBackgroundCopyCallback_FWD_DEFINED__
typedef interface IBackgroundCopyCallback IBackgroundCopyCallback;

#endif 	/* __IBackgroundCopyCallback_FWD_DEFINED__ */


/* header files for imported files */
#include "unknwn.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_bits_0000_0000 */
/* [local] */ 

#include <winapifamily.h>
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
#include "bitsmsg.h"
#define BG_SIZE_UNKNOWN     (UINT64)(-1)


extern RPC_IF_HANDLE __MIDL_itf_bits_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_bits_0000_0000_v0_0_s_ifspec;

#ifndef __IBackgroundCopyFile_INTERFACE_DEFINED__
#define __IBackgroundCopyFile_INTERFACE_DEFINED__

/* interface IBackgroundCopyFile */
/* [object][uuid] */ 

typedef struct _BG_FILE_PROGRESS
    {
    UINT64 BytesTotal;
    UINT64 BytesTransferred;
    BOOL Completed;
    } 	BG_FILE_PROGRESS;


EXTERN_C const IID IID_IBackgroundCopyFile;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("01b7bd23-fb88-4a77-8490-5891d3e4653a")
    IBackgroundCopyFile : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetRemoteName( 
            /* [annotation][out] */ 
            _Out_  LPWSTR *pVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLocalName( 
            /* [annotation][out] */ 
            _Out_  LPWSTR *pVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetProgress( 
            /* [annotation][out] */ 
            _Out_  BG_FILE_PROGRESS *pVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IBackgroundCopyFileVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IBackgroundCopyFile * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IBackgroundCopyFile * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IBackgroundCopyFile * This);
        
        DECLSPEC_XFGVIRT(IBackgroundCopyFile, GetRemoteName)
        HRESULT ( STDMETHODCALLTYPE *GetRemoteName )( 
            __RPC__in IBackgroundCopyFile * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *pVal);
        
        DECLSPEC_XFGVIRT(IBackgroundCopyFile, GetLocalName)
        HRESULT ( STDMETHODCALLTYPE *GetLocalName )( 
            __RPC__in IBackgroundCopyFile * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *pVal);
        
        DECLSPEC_XFGVIRT(IBackgroundCopyFile, GetProgress)
        HRESULT ( STDMETHODCALLTYPE *GetProgress )( 
            __RPC__in IBackgroundCopyFile * This,
            /* [annotation][out] */ 
            _Out_  BG_FILE_PROGRESS *pVal);
        
        END_INTERFACE
    } IBackgroundCopyFileVtbl;

    interface IBackgroundCopyFile
    {
        CONST_VTBL struct IBackgroundCopyFileVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBackgroundCopyFile_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IBackgroundCopyFile_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IBackgroundCopyFile_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IBackgroundCopyFile_GetRemoteName(This,pVal)	\
    ( (This)->lpVtbl -> GetRemoteName(This,pVal) ) 

#define IBackgroundCopyFile_GetLocalName(This,pVal)	\
    ( (This)->lpVtbl -> GetLocalName(This,pVal) ) 

#define IBackgroundCopyFile_GetProgress(This,pVal)	\
    ( (This)->lpVtbl -> GetProgress(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IBackgroundCopyFile_INTERFACE_DEFINED__ */


#ifndef __IEnumBackgroundCopyFiles_INTERFACE_DEFINED__
#define __IEnumBackgroundCopyFiles_INTERFACE_DEFINED__

/* interface IEnumBackgroundCopyFiles */
/* [object][helpstring][uuid] */ 


EXTERN_C const IID IID_IEnumBackgroundCopyFiles;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("ca51e165-c365-424c-8d41-24aaa4ff3c40")
    IEnumBackgroundCopyFiles : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [annotation][in] */ 
            _In_  ULONG celt,
            /* [length_is][size_is][out] */ __RPC__out_ecount_part(celt, pceltFetched ? *pceltFetched : celt) IBackgroundCopyFile **rgelt,
            /* [annotation][unique][out][in] */ 
            _Inout_  ULONG *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [annotation][in] */ 
            _In_  ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [annotation][out] */ 
            _Out_  IEnumBackgroundCopyFiles **ppenum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCount( 
            /* [annotation][out] */ 
            _Out_  ULONG *puCount) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IEnumBackgroundCopyFilesVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IEnumBackgroundCopyFiles * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IEnumBackgroundCopyFiles * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IEnumBackgroundCopyFiles * This);
        
        DECLSPEC_XFGVIRT(IEnumBackgroundCopyFiles, Next)
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            __RPC__in IEnumBackgroundCopyFiles * This,
            /* [annotation][in] */ 
            _In_  ULONG celt,
            /* [length_is][size_is][out] */ __RPC__out_ecount_part(celt, pceltFetched ? *pceltFetched : celt) IBackgroundCopyFile **rgelt,
            /* [annotation][unique][out][in] */ 
            _Inout_  ULONG *pceltFetched);
        
        DECLSPEC_XFGVIRT(IEnumBackgroundCopyFiles, Skip)
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            __RPC__in IEnumBackgroundCopyFiles * This,
            /* [annotation][in] */ 
            _In_  ULONG celt);
        
        DECLSPEC_XFGVIRT(IEnumBackgroundCopyFiles, Reset)
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            __RPC__in IEnumBackgroundCopyFiles * This);
        
        DECLSPEC_XFGVIRT(IEnumBackgroundCopyFiles, Clone)
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            __RPC__in IEnumBackgroundCopyFiles * This,
            /* [annotation][out] */ 
            _Out_  IEnumBackgroundCopyFiles **ppenum);
        
        DECLSPEC_XFGVIRT(IEnumBackgroundCopyFiles, GetCount)
        HRESULT ( STDMETHODCALLTYPE *GetCount )( 
            __RPC__in IEnumBackgroundCopyFiles * This,
            /* [annotation][out] */ 
            _Out_  ULONG *puCount);
        
        END_INTERFACE
    } IEnumBackgroundCopyFilesVtbl;

    interface IEnumBackgroundCopyFiles
    {
        CONST_VTBL struct IEnumBackgroundCopyFilesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumBackgroundCopyFiles_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEnumBackgroundCopyFiles_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEnumBackgroundCopyFiles_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IEnumBackgroundCopyFiles_Next(This,celt,rgelt,pceltFetched)	\
    ( (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched) ) 

#define IEnumBackgroundCopyFiles_Skip(This,celt)	\
    ( (This)->lpVtbl -> Skip(This,celt) ) 

#define IEnumBackgroundCopyFiles_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define IEnumBackgroundCopyFiles_Clone(This,ppenum)	\
    ( (This)->lpVtbl -> Clone(This,ppenum) ) 

#define IEnumBackgroundCopyFiles_GetCount(This,puCount)	\
    ( (This)->lpVtbl -> GetCount(This,puCount) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IEnumBackgroundCopyFiles_INTERFACE_DEFINED__ */


#ifndef __IBackgroundCopyError_INTERFACE_DEFINED__
#define __IBackgroundCopyError_INTERFACE_DEFINED__

/* interface IBackgroundCopyError */
/* [object][helpstring][uuid] */ 

typedef 
enum BG_ERROR_CONTEXT
    {
        BG_ERROR_CONTEXT_NONE	= 0,
        BG_ERROR_CONTEXT_UNKNOWN	= 1,
        BG_ERROR_CONTEXT_GENERAL_QUEUE_MANAGER	= 2,
        BG_ERROR_CONTEXT_QUEUE_MANAGER_NOTIFICATION	= 3,
        BG_ERROR_CONTEXT_LOCAL_FILE	= 4,
        BG_ERROR_CONTEXT_REMOTE_FILE	= 5,
        BG_ERROR_CONTEXT_GENERAL_TRANSPORT	= 6,
        BG_ERROR_CONTEXT_REMOTE_APPLICATION	= 7,
        BG_ERROR_CONTEXT_SERVER_CERTIFICATE_CALLBACK	= 8
    } 	BG_ERROR_CONTEXT;


EXTERN_C const IID IID_IBackgroundCopyError;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("19c613a0-fcb8-4f28-81ae-897c3d078f81")
    IBackgroundCopyError : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetError( 
            /* [ref][out] */ __RPC__out BG_ERROR_CONTEXT *pContext,
            /* [ref][out] */ __RPC__out HRESULT *pCode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFile( 
            /* [annotation][out] */ 
            _Out_  IBackgroundCopyFile **pVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetErrorDescription( 
            /* [annotation][in] */ 
            _In_  DWORD LanguageId,
            /* [ref][out] */ __RPC__deref_out_opt LPWSTR *pErrorDescription) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetErrorContextDescription( 
            /* [annotation][in] */ 
            _In_  DWORD LanguageId,
            /* [ref][out] */ __RPC__deref_out_opt LPWSTR *pContextDescription) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetProtocol( 
            /* [ref][out] */ __RPC__deref_out_opt LPWSTR *pProtocol) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IBackgroundCopyErrorVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IBackgroundCopyError * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IBackgroundCopyError * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IBackgroundCopyError * This);
        
        DECLSPEC_XFGVIRT(IBackgroundCopyError, GetError)
        HRESULT ( STDMETHODCALLTYPE *GetError )( 
            __RPC__in IBackgroundCopyError * This,
            /* [ref][out] */ __RPC__out BG_ERROR_CONTEXT *pContext,
            /* [ref][out] */ __RPC__out HRESULT *pCode);
        
        DECLSPEC_XFGVIRT(IBackgroundCopyError, GetFile)
        HRESULT ( STDMETHODCALLTYPE *GetFile )( 
            __RPC__in IBackgroundCopyError * This,
            /* [annotation][out] */ 
            _Out_  IBackgroundCopyFile **pVal);
        
        DECLSPEC_XFGVIRT(IBackgroundCopyError, GetErrorDescription)
        HRESULT ( STDMETHODCALLTYPE *GetErrorDescription )( 
            __RPC__in IBackgroundCopyError * This,
            /* [annotation][in] */ 
            _In_  DWORD LanguageId,
            /* [ref][out] */ __RPC__deref_out_opt LPWSTR *pErrorDescription);
        
        DECLSPEC_XFGVIRT(IBackgroundCopyError, GetErrorContextDescription)
        HRESULT ( STDMETHODCALLTYPE *GetErrorContextDescription )( 
            __RPC__in IBackgroundCopyError * This,
            /* [annotation][in] */ 
            _In_  DWORD LanguageId,
            /* [ref][out] */ __RPC__deref_out_opt LPWSTR *pContextDescription);
        
        DECLSPEC_XFGVIRT(IBackgroundCopyError, GetProtocol)
        HRESULT ( STDMETHODCALLTYPE *GetProtocol )( 
            __RPC__in IBackgroundCopyError * This,
            /* [ref][out] */ __RPC__deref_out_opt LPWSTR *pProtocol);
        
        END_INTERFACE
    } IBackgroundCopyErrorVtbl;

    interface IBackgroundCopyError
    {
        CONST_VTBL struct IBackgroundCopyErrorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBackgroundCopyError_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IBackgroundCopyError_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IBackgroundCopyError_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IBackgroundCopyError_GetError(This,pContext,pCode)	\
    ( (This)->lpVtbl -> GetError(This,pContext,pCode) ) 

#define IBackgroundCopyError_GetFile(This,pVal)	\
    ( (This)->lpVtbl -> GetFile(This,pVal) ) 

#define IBackgroundCopyError_GetErrorDescription(This,LanguageId,pErrorDescription)	\
    ( (This)->lpVtbl -> GetErrorDescription(This,LanguageId,pErrorDescription) ) 

#define IBackgroundCopyError_GetErrorContextDescription(This,LanguageId,pContextDescription)	\
    ( (This)->lpVtbl -> GetErrorContextDescription(This,LanguageId,pContextDescription) ) 

#define IBackgroundCopyError_GetProtocol(This,pProtocol)	\
    ( (This)->lpVtbl -> GetProtocol(This,pProtocol) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IBackgroundCopyError_INTERFACE_DEFINED__ */


#ifndef __IBackgroundCopyJob_INTERFACE_DEFINED__
#define __IBackgroundCopyJob_INTERFACE_DEFINED__

/* interface IBackgroundCopyJob */
/* [object][helpstring][uuid] */ 

typedef struct _BG_FILE_INFO
    {
    LPWSTR RemoteName;
    LPWSTR LocalName;
    } 	BG_FILE_INFO;

typedef struct _BG_JOB_PROGRESS
    {
    UINT64 BytesTotal;
    UINT64 BytesTransferred;
    ULONG FilesTotal;
    ULONG FilesTransferred;
    } 	BG_JOB_PROGRESS;

typedef struct _BG_JOB_TIMES
    {
    FILETIME CreationTime;
    FILETIME ModificationTime;
    FILETIME TransferCompletionTime;
    } 	BG_JOB_TIMES;

typedef 
enum BG_JOB_PRIORITY
    {
        BG_JOB_PRIORITY_FOREGROUND	= 0,
        BG_JOB_PRIORITY_HIGH	= ( BG_JOB_PRIORITY_FOREGROUND + 1 ) ,
        BG_JOB_PRIORITY_NORMAL	= ( BG_JOB_PRIORITY_HIGH + 1 ) ,
        BG_JOB_PRIORITY_LOW	= ( BG_JOB_PRIORITY_NORMAL + 1 ) 
    } 	BG_JOB_PRIORITY;

typedef 
enum BG_JOB_STATE
    {
        BG_JOB_STATE_QUEUED	= 0,
        BG_JOB_STATE_CONNECTING	= ( BG_JOB_STATE_QUEUED + 1 ) ,
        BG_JOB_STATE_TRANSFERRING	= ( BG_JOB_STATE_CONNECTING + 1 ) ,
        BG_JOB_STATE_SUSPENDED	= ( BG_JOB_STATE_TRANSFERRING + 1 ) ,
        BG_JOB_STATE_ERROR	= ( BG_JOB_STATE_SUSPENDED + 1 ) ,
        BG_JOB_STATE_TRANSIENT_ERROR	= ( BG_JOB_STATE_ERROR + 1 ) ,
        BG_JOB_STATE_TRANSFERRED	= ( BG_JOB_STATE_TRANSIENT_ERROR + 1 ) ,
        BG_JOB_STATE_ACKNOWLEDGED	= ( BG_JOB_STATE_TRANSFERRED + 1 ) ,
        BG_JOB_STATE_CANCELLED	= ( BG_JOB_STATE_ACKNOWLEDGED + 1 ) 
    } 	BG_JOB_STATE;

typedef 
enum BG_JOB_TYPE
    {
        BG_JOB_TYPE_DOWNLOAD	= 0,
        BG_JOB_TYPE_UPLOAD	= ( BG_JOB_TYPE_DOWNLOAD + 1 ) ,
        BG_JOB_TYPE_UPLOAD_REPLY	= ( BG_JOB_TYPE_UPLOAD + 1 ) 
    } 	BG_JOB_TYPE;

typedef 
enum BG_JOB_PROXY_USAGE
    {
        BG_JOB_PROXY_USAGE_PRECONFIG	= 0,
        BG_JOB_PROXY_USAGE_NO_PROXY	= ( BG_JOB_PROXY_USAGE_PRECONFIG + 1 ) ,
        BG_JOB_PROXY_USAGE_OVERRIDE	= ( BG_JOB_PROXY_USAGE_NO_PROXY + 1 ) ,
        BG_JOB_PROXY_USAGE_AUTODETECT	= ( BG_JOB_PROXY_USAGE_OVERRIDE + 1 ) 
    } 	BG_JOB_PROXY_USAGE;


EXTERN_C const IID IID_IBackgroundCopyJob;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("37668d37-507e-4160-9316-26306d150b12")
    IBackgroundCopyJob : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AddFileSet( 
            /* [annotation][in] */ 
            _In_  ULONG cFileCount,
            /* [annotation][size_is][in] */ 
            _In_reads_(cFileCount)  BG_FILE_INFO *pFileSet) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddFile( 
            /* [annotation][in] */ 
            _In_  LPCWSTR RemoteUrl,
            /* [annotation][in] */ 
            _In_  LPCWSTR LocalName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumFiles( 
            /* [annotation][out] */ 
            _Out_  IEnumBackgroundCopyFiles **pEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Suspend( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Resume( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Cancel( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Complete( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetId( 
            /* [annotation][out] */ 
            _Out_  GUID *pVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetType( 
            /* [annotation][out] */ 
            _Out_  BG_JOB_TYPE *pVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetProgress( 
            /* [annotation][out] */ 
            _Out_  BG_JOB_PROGRESS *pVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTimes( 
            /* [annotation][out] */ 
            _Out_  BG_JOB_TIMES *pVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetState( 
            /* [annotation][out] */ 
            _Out_  BG_JOB_STATE *pVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetError( 
            /* [annotation][out] */ 
            _Out_  IBackgroundCopyError **ppError) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetOwner( 
            /* [annotation][out] */ 
            _Out_  LPWSTR *pVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDisplayName( 
            /* [annotation][in] */ 
            _In_  LPCWSTR Val) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDisplayName( 
            /* [annotation][out] */ 
            _Out_  LPWSTR *pVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDescription( 
            /* [annotation][in] */ 
            _In_  LPCWSTR Val) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDescription( 
            /* [annotation][out] */ 
            _Out_  LPWSTR *pVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPriority( 
            /* [annotation][in] */ 
            _In_  BG_JOB_PRIORITY Val) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPriority( 
            /* [annotation][out] */ 
            _Out_  BG_JOB_PRIORITY *pVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetNotifyFlags( 
            /* [annotation][in] */ 
            _In_  ULONG Val) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNotifyFlags( 
            /* [annotation][out] */ 
            _Out_  ULONG *pVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetNotifyInterface( 
            /* [annotation][in] */ 
            _In_  IUnknown *Val) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNotifyInterface( 
            /* [annotation][out] */ 
            _Out_  IUnknown **pVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMinimumRetryDelay( 
            /* [annotation][in] */ 
            _In_  ULONG Seconds) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMinimumRetryDelay( 
            /* [annotation][out] */ 
            _Out_  ULONG *Seconds) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetNoProgressTimeout( 
            /* [annotation][in] */ 
            _In_  ULONG Seconds) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNoProgressTimeout( 
            /* [annotation][out] */ 
            _Out_  ULONG *Seconds) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetErrorCount( 
            /* [annotation][out] */ 
            _Out_  ULONG *Errors) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetProxySettings( 
            /* [annotation][in] */ 
            _In_  BG_JOB_PROXY_USAGE ProxyUsage,
            /* [annotation][unique][string][in] */ 
            _In_  const WCHAR *ProxyList,
            /* [annotation][unique][string][in] */ 
            _In_  const WCHAR *ProxyBypassList) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetProxySettings( 
            /* [annotation][out] */ 
            _Out_  BG_JOB_PROXY_USAGE *pProxyUsage,
            /* [annotation][out] */ 
            _Out_  LPWSTR *pProxyList,
            /* [annotation][out] */ 
            _Out_  LPWSTR *pProxyBypassList) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE TakeOwnership( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IBackgroundCopyJobVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IBackgroundCopyJob * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IBackgroundCopyJob * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IBackgroundCopyJob * This);
        
        DECLSPEC_XFGVIRT(IBackgroundCopyJob, AddFileSet)
        HRESULT ( STDMETHODCALLTYPE *AddFileSet )( 
            __RPC__in IBackgroundCopyJob * This,
            /* [annotation][in] */ 
            _In_  ULONG cFileCount,
            /* [annotation][size_is][in] */ 
            _In_reads_(cFileCount)  BG_FILE_INFO *pFileSet);
        
        DECLSPEC_XFGVIRT(IBackgroundCopyJob, AddFile)
        HRESULT ( STDMETHODCALLTYPE *AddFile )( 
            __RPC__in IBackgroundCopyJob * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR RemoteUrl,
            /* [annotation][in] */ 
            _In_  LPCWSTR LocalName);
        
        DECLSPEC_XFGVIRT(IBackgroundCopyJob, EnumFiles)
        HRESULT ( STDMETHODCALLTYPE *EnumFiles )( 
            __RPC__in IBackgroundCopyJob * This,
            /* [annotation][out] */ 
            _Out_  IEnumBackgroundCopyFiles **pEnum);
        
        DECLSPEC_XFGVIRT(IBackgroundCopyJob, Suspend)
        HRESULT ( STDMETHODCALLTYPE *Suspend )( 
            __RPC__in IBackgroundCopyJob * This);
        
        DECLSPEC_XFGVIRT(IBackgroundCopyJob, Resume)
        HRESULT ( STDMETHODCALLTYPE *Resume )( 
            __RPC__in IBackgroundCopyJob * This);
        
        DECLSPEC_XFGVIRT(IBackgroundCopyJob, Cancel)
        HRESULT ( STDMETHODCALLTYPE *Cancel )( 
            __RPC__in IBackgroundCopyJob * This);
        
        DECLSPEC_XFGVIRT(IBackgroundCopyJob, Complete)
        HRESULT ( STDMETHODCALLTYPE *Complete )( 
            __RPC__in IBackgroundCopyJob * This);
        
        DECLSPEC_XFGVIRT(IBackgroundCopyJob, GetId)
        HRESULT ( STDMETHODCALLTYPE *GetId )( 
            __RPC__in IBackgroundCopyJob * This,
            /* [annotation][out] */ 
            _Out_  GUID *pVal);
        
        DECLSPEC_XFGVIRT(IBackgroundCopyJob, GetType)
        HRESULT ( STDMETHODCALLTYPE *GetType )( 
            __RPC__in IBackgroundCopyJob * This,
            /* [annotation][out] */ 
            _Out_  BG_JOB_TYPE *pVal);
        
        DECLSPEC_XFGVIRT(IBackgroundCopyJob, GetProgress)
        HRESULT ( STDMETHODCALLTYPE *GetProgress )( 
            __RPC__in IBackgroundCopyJob * This,
            /* [annotation][out] */ 
            _Out_  BG_JOB_PROGRESS *pVal);
        
        DECLSPEC_XFGVIRT(IBackgroundCopyJob, GetTimes)
        HRESULT ( STDMETHODCALLTYPE *GetTimes )( 
            __RPC__in IBackgroundCopyJob * This,
            /* [annotation][out] */ 
            _Out_  BG_JOB_TIMES *pVal);
        
        DECLSPEC_XFGVIRT(IBackgroundCopyJob, GetState)
        HRESULT ( STDMETHODCALLTYPE *GetState )( 
            __RPC__in IBackgroundCopyJob * This,
            /* [annotation][out] */ 
            _Out_  BG_JOB_STATE *pVal);
        
        DECLSPEC_XFGVIRT(IBackgroundCopyJob, GetError)
        HRESULT ( STDMETHODCALLTYPE *GetError )( 
            __RPC__in IBackgroundCopyJob * This,
            /* [annotation][out] */ 
            _Out_  IBackgroundCopyError **ppError);
        
        DECLSPEC_XFGVIRT(IBackgroundCopyJob, GetOwner)
        HRESULT ( STDMETHODCALLTYPE *GetOwner )( 
            __RPC__in IBackgroundCopyJob * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *pVal);
        
        DECLSPEC_XFGVIRT(IBackgroundCopyJob, SetDisplayName)
        HRESULT ( STDMETHODCALLTYPE *SetDisplayName )( 
            __RPC__in IBackgroundCopyJob * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR Val);
        
        DECLSPEC_XFGVIRT(IBackgroundCopyJob, GetDisplayName)
        HRESULT ( STDMETHODCALLTYPE *GetDisplayName )( 
            __RPC__in IBackgroundCopyJob * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *pVal);
        
        DECLSPEC_XFGVIRT(IBackgroundCopyJob, SetDescription)
        HRESULT ( STDMETHODCALLTYPE *SetDescription )( 
            __RPC__in IBackgroundCopyJob * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR Val);
        
        DECLSPEC_XFGVIRT(IBackgroundCopyJob, GetDescription)
        HRESULT ( STDMETHODCALLTYPE *GetDescription )( 
            __RPC__in IBackgroundCopyJob * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *pVal);
        
        DECLSPEC_XFGVIRT(IBackgroundCopyJob, SetPriority)
        HRESULT ( STDMETHODCALLTYPE *SetPriority )( 
            __RPC__in IBackgroundCopyJob * This,
            /* [annotation][in] */ 
            _In_  BG_JOB_PRIORITY Val);
        
        DECLSPEC_XFGVIRT(IBackgroundCopyJob, GetPriority)
        HRESULT ( STDMETHODCALLTYPE *GetPriority )( 
            __RPC__in IBackgroundCopyJob * This,
            /* [annotation][out] */ 
            _Out_  BG_JOB_PRIORITY *pVal);
        
        DECLSPEC_XFGVIRT(IBackgroundCopyJob, SetNotifyFlags)
        HRESULT ( STDMETHODCALLTYPE *SetNotifyFlags )( 
            __RPC__in IBackgroundCopyJob * This,
            /* [annotation][in] */ 
            _In_  ULONG Val);
        
        DECLSPEC_XFGVIRT(IBackgroundCopyJob, GetNotifyFlags)
        HRESULT ( STDMETHODCALLTYPE *GetNotifyFlags )( 
            __RPC__in IBackgroundCopyJob * This,
            /* [annotation][out] */ 
            _Out_  ULONG *pVal);
        
        DECLSPEC_XFGVIRT(IBackgroundCopyJob, SetNotifyInterface)
        HRESULT ( STDMETHODCALLTYPE *SetNotifyInterface )( 
            __RPC__in IBackgroundCopyJob * This,
            /* [annotation][in] */ 
            _In_  IUnknown *Val);
        
        DECLSPEC_XFGVIRT(IBackgroundCopyJob, GetNotifyInterface)
        HRESULT ( STDMETHODCALLTYPE *GetNotifyInterface )( 
            __RPC__in IBackgroundCopyJob * This,
            /* [annotation][out] */ 
            _Out_  IUnknown **pVal);
        
        DECLSPEC_XFGVIRT(IBackgroundCopyJob, SetMinimumRetryDelay)
        HRESULT ( STDMETHODCALLTYPE *SetMinimumRetryDelay )( 
            __RPC__in IBackgroundCopyJob * This,
            /* [annotation][in] */ 
            _In_  ULONG Seconds);
        
        DECLSPEC_XFGVIRT(IBackgroundCopyJob, GetMinimumRetryDelay)
        HRESULT ( STDMETHODCALLTYPE *GetMinimumRetryDelay )( 
            __RPC__in IBackgroundCopyJob * This,
            /* [annotation][out] */ 
            _Out_  ULONG *Seconds);
        
        DECLSPEC_XFGVIRT(IBackgroundCopyJob, SetNoProgressTimeout)
        HRESULT ( STDMETHODCALLTYPE *SetNoProgressTimeout )( 
            __RPC__in IBackgroundCopyJob * This,
            /* [annotation][in] */ 
            _In_  ULONG Seconds);
        
        DECLSPEC_XFGVIRT(IBackgroundCopyJob, GetNoProgressTimeout)
        HRESULT ( STDMETHODCALLTYPE *GetNoProgressTimeout )( 
            __RPC__in IBackgroundCopyJob * This,
            /* [annotation][out] */ 
            _Out_  ULONG *Seconds);
        
        DECLSPEC_XFGVIRT(IBackgroundCopyJob, GetErrorCount)
        HRESULT ( STDMETHODCALLTYPE *GetErrorCount )( 
            __RPC__in IBackgroundCopyJob * This,
            /* [annotation][out] */ 
            _Out_  ULONG *Errors);
        
        DECLSPEC_XFGVIRT(IBackgroundCopyJob, SetProxySettings)
        HRESULT ( STDMETHODCALLTYPE *SetProxySettings )( 
            __RPC__in IBackgroundCopyJob * This,
            /* [annotation][in] */ 
            _In_  BG_JOB_PROXY_USAGE ProxyUsage,
            /* [annotation][unique][string][in] */ 
            _In_  const WCHAR *ProxyList,
            /* [annotation][unique][string][in] */ 
            _In_  const WCHAR *ProxyBypassList);
        
        DECLSPEC_XFGVIRT(IBackgroundCopyJob, GetProxySettings)
        HRESULT ( STDMETHODCALLTYPE *GetProxySettings )( 
            __RPC__in IBackgroundCopyJob * This,
            /* [annotation][out] */ 
            _Out_  BG_JOB_PROXY_USAGE *pProxyUsage,
            /* [annotation][out] */ 
            _Out_  LPWSTR *pProxyList,
            /* [annotation][out] */ 
            _Out_  LPWSTR *pProxyBypassList);
        
        DECLSPEC_XFGVIRT(IBackgroundCopyJob, TakeOwnership)
        HRESULT ( STDMETHODCALLTYPE *TakeOwnership )( 
            __RPC__in IBackgroundCopyJob * This);
        
        END_INTERFACE
    } IBackgroundCopyJobVtbl;

    interface IBackgroundCopyJob
    {
        CONST_VTBL struct IBackgroundCopyJobVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBackgroundCopyJob_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IBackgroundCopyJob_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IBackgroundCopyJob_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IBackgroundCopyJob_AddFileSet(This,cFileCount,pFileSet)	\
    ( (This)->lpVtbl -> AddFileSet(This,cFileCount,pFileSet) ) 

#define IBackgroundCopyJob_AddFile(This,RemoteUrl,LocalName)	\
    ( (This)->lpVtbl -> AddFile(This,RemoteUrl,LocalName) ) 

#define IBackgroundCopyJob_EnumFiles(This,pEnum)	\
    ( (This)->lpVtbl -> EnumFiles(This,pEnum) ) 

#define IBackgroundCopyJob_Suspend(This)	\
    ( (This)->lpVtbl -> Suspend(This) ) 

#define IBackgroundCopyJob_Resume(This)	\
    ( (This)->lpVtbl -> Resume(This) ) 

#define IBackgroundCopyJob_Cancel(This)	\
    ( (This)->lpVtbl -> Cancel(This) ) 

#define IBackgroundCopyJob_Complete(This)	\
    ( (This)->lpVtbl -> Complete(This) ) 

#define IBackgroundCopyJob_GetId(This,pVal)	\
    ( (This)->lpVtbl -> GetId(This,pVal) ) 

#define IBackgroundCopyJob_GetType(This,pVal)	\
    ( (This)->lpVtbl -> GetType(This,pVal) ) 

#define IBackgroundCopyJob_GetProgress(This,pVal)	\
    ( (This)->lpVtbl -> GetProgress(This,pVal) ) 

#define IBackgroundCopyJob_GetTimes(This,pVal)	\
    ( (This)->lpVtbl -> GetTimes(This,pVal) ) 

#define IBackgroundCopyJob_GetState(This,pVal)	\
    ( (This)->lpVtbl -> GetState(This,pVal) ) 

#define IBackgroundCopyJob_GetError(This,ppError)	\
    ( (This)->lpVtbl -> GetError(This,ppError) ) 

#define IBackgroundCopyJob_GetOwner(This,pVal)	\
    ( (This)->lpVtbl -> GetOwner(This,pVal) ) 

#define IBackgroundCopyJob_SetDisplayName(This,Val)	\
    ( (This)->lpVtbl -> SetDisplayName(This,Val) ) 

#define IBackgroundCopyJob_GetDisplayName(This,pVal)	\
    ( (This)->lpVtbl -> GetDisplayName(This,pVal) ) 

#define IBackgroundCopyJob_SetDescription(This,Val)	\
    ( (This)->lpVtbl -> SetDescription(This,Val) ) 

#define IBackgroundCopyJob_GetDescription(This,pVal)	\
    ( (This)->lpVtbl -> GetDescription(This,pVal) ) 

#define IBackgroundCopyJob_SetPriority(This,Val)	\
    ( (This)->lpVtbl -> SetPriority(This,Val) ) 

#define IBackgroundCopyJob_GetPriority(This,pVal)	\
    ( (This)->lpVtbl -> GetPriority(This,pVal) ) 

#define IBackgroundCopyJob_SetNotifyFlags(This,Val)	\
    ( (This)->lpVtbl -> SetNotifyFlags(This,Val) ) 

#define IBackgroundCopyJob_GetNotifyFlags(This,pVal)	\
    ( (This)->lpVtbl -> GetNotifyFlags(This,pVal) ) 

#define IBackgroundCopyJob_SetNotifyInterface(This,Val)	\
    ( (This)->lpVtbl -> SetNotifyInterface(This,Val) ) 

#define IBackgroundCopyJob_GetNotifyInterface(This,pVal)	\
    ( (This)->lpVtbl -> GetNotifyInterface(This,pVal) ) 

#define IBackgroundCopyJob_SetMinimumRetryDelay(This,Seconds)	\
    ( (This)->lpVtbl -> SetMinimumRetryDelay(This,Seconds) ) 

#define IBackgroundCopyJob_GetMinimumRetryDelay(This,Seconds)	\
    ( (This)->lpVtbl -> GetMinimumRetryDelay(This,Seconds) ) 

#define IBackgroundCopyJob_SetNoProgressTimeout(This,Seconds)	\
    ( (This)->lpVtbl -> SetNoProgressTimeout(This,Seconds) ) 

#define IBackgroundCopyJob_GetNoProgressTimeout(This,Seconds)	\
    ( (This)->lpVtbl -> GetNoProgressTimeout(This,Seconds) ) 

#define IBackgroundCopyJob_GetErrorCount(This,Errors)	\
    ( (This)->lpVtbl -> GetErrorCount(This,Errors) ) 

#define IBackgroundCopyJob_SetProxySettings(This,ProxyUsage,ProxyList,ProxyBypassList)	\
    ( (This)->lpVtbl -> SetProxySettings(This,ProxyUsage,ProxyList,ProxyBypassList) ) 

#define IBackgroundCopyJob_GetProxySettings(This,pProxyUsage,pProxyList,pProxyBypassList)	\
    ( (This)->lpVtbl -> GetProxySettings(This,pProxyUsage,pProxyList,pProxyBypassList) ) 

#define IBackgroundCopyJob_TakeOwnership(This)	\
    ( (This)->lpVtbl -> TakeOwnership(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IBackgroundCopyJob_INTERFACE_DEFINED__ */


#ifndef __IEnumBackgroundCopyJobs_INTERFACE_DEFINED__
#define __IEnumBackgroundCopyJobs_INTERFACE_DEFINED__

/* interface IEnumBackgroundCopyJobs */
/* [object][helpstring][uuid] */ 


EXTERN_C const IID IID_IEnumBackgroundCopyJobs;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1af4f612-3b71-466f-8f58-7b6f73ac57ad")
    IEnumBackgroundCopyJobs : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [annotation][in] */ 
            _In_  ULONG celt,
            /* [length_is][size_is][out] */ __RPC__out_ecount_part(celt, pceltFetched ? *pceltFetched : celt) IBackgroundCopyJob **rgelt,
            /* [annotation][unique][out][in] */ 
            _Inout_  ULONG *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [annotation][in] */ 
            _In_  ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [annotation][out] */ 
            _Out_  IEnumBackgroundCopyJobs **ppenum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCount( 
            /* [annotation][out] */ 
            _Out_  ULONG *puCount) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IEnumBackgroundCopyJobsVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IEnumBackgroundCopyJobs * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IEnumBackgroundCopyJobs * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IEnumBackgroundCopyJobs * This);
        
        DECLSPEC_XFGVIRT(IEnumBackgroundCopyJobs, Next)
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            __RPC__in IEnumBackgroundCopyJobs * This,
            /* [annotation][in] */ 
            _In_  ULONG celt,
            /* [length_is][size_is][out] */ __RPC__out_ecount_part(celt, pceltFetched ? *pceltFetched : celt) IBackgroundCopyJob **rgelt,
            /* [annotation][unique][out][in] */ 
            _Inout_  ULONG *pceltFetched);
        
        DECLSPEC_XFGVIRT(IEnumBackgroundCopyJobs, Skip)
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            __RPC__in IEnumBackgroundCopyJobs * This,
            /* [annotation][in] */ 
            _In_  ULONG celt);
        
        DECLSPEC_XFGVIRT(IEnumBackgroundCopyJobs, Reset)
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            __RPC__in IEnumBackgroundCopyJobs * This);
        
        DECLSPEC_XFGVIRT(IEnumBackgroundCopyJobs, Clone)
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            __RPC__in IEnumBackgroundCopyJobs * This,
            /* [annotation][out] */ 
            _Out_  IEnumBackgroundCopyJobs **ppenum);
        
        DECLSPEC_XFGVIRT(IEnumBackgroundCopyJobs, GetCount)
        HRESULT ( STDMETHODCALLTYPE *GetCount )( 
            __RPC__in IEnumBackgroundCopyJobs * This,
            /* [annotation][out] */ 
            _Out_  ULONG *puCount);
        
        END_INTERFACE
    } IEnumBackgroundCopyJobsVtbl;

    interface IEnumBackgroundCopyJobs
    {
        CONST_VTBL struct IEnumBackgroundCopyJobsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumBackgroundCopyJobs_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEnumBackgroundCopyJobs_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEnumBackgroundCopyJobs_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IEnumBackgroundCopyJobs_Next(This,celt,rgelt,pceltFetched)	\
    ( (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched) ) 

#define IEnumBackgroundCopyJobs_Skip(This,celt)	\
    ( (This)->lpVtbl -> Skip(This,celt) ) 

#define IEnumBackgroundCopyJobs_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define IEnumBackgroundCopyJobs_Clone(This,ppenum)	\
    ( (This)->lpVtbl -> Clone(This,ppenum) ) 

#define IEnumBackgroundCopyJobs_GetCount(This,puCount)	\
    ( (This)->lpVtbl -> GetCount(This,puCount) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IEnumBackgroundCopyJobs_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_bits_0000_0005 */
/* [local] */ 

#define   BG_NOTIFY_JOB_TRANSFERRED         0x0001
#define   BG_NOTIFY_JOB_ERROR               0x0002
#define   BG_NOTIFY_DISABLE                 0x0004
#define   BG_NOTIFY_JOB_MODIFICATION        0x0008
#define   BG_NOTIFY_FILE_TRANSFERRED        0x0010
#define   BG_NOTIFY_FILE_RANGES_TRANSFERRED 0x0020


extern RPC_IF_HANDLE __MIDL_itf_bits_0000_0005_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_bits_0000_0005_v0_0_s_ifspec;

#ifndef __IBackgroundCopyCallback_INTERFACE_DEFINED__
#define __IBackgroundCopyCallback_INTERFACE_DEFINED__

/* interface IBackgroundCopyCallback */
/* [object][helpstring][async_uuid][uuid] */ 


EXTERN_C const IID IID_IBackgroundCopyCallback;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("97ea99c7-0186-4ad4-8df9-c5b4e0ed6b22")
    IBackgroundCopyCallback : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE JobTransferred( 
            /* [annotation][in] */ 
            _In_  IBackgroundCopyJob *pJob) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE JobError( 
            /* [annotation][in] */ 
            _In_  IBackgroundCopyJob *pJob,
            /* [annotation][in] */ 
            _In_  IBackgroundCopyError *pError) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE JobModification( 
            /* [annotation][in] */ 
            _In_  IBackgroundCopyJob *pJob,
            /* [annotation][in] */ 
            _In_  DWORD dwReserved) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IBackgroundCopyCallbackVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IBackgroundCopyCallback * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IBackgroundCopyCallback * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IBackgroundCopyCallback * This);
        
        DECLSPEC_XFGVIRT(IBackgroundCopyCallback, JobTransferred)
        HRESULT ( STDMETHODCALLTYPE *JobTransferred )( 
            __RPC__in IBackgroundCopyCallback * This,
            /* [annotation][in] */ 
            _In_  IBackgroundCopyJob *pJob);
        
        DECLSPEC_XFGVIRT(IBackgroundCopyCallback, JobError)
        HRESULT ( STDMETHODCALLTYPE *JobError )( 
            __RPC__in IBackgroundCopyCallback * This,
            /* [annotation][in] */ 
            _In_  IBackgroundCopyJob *pJob,
            /* [annotation][in] */ 
            _In_  IBackgroundCopyError *pError);
        
        DECLSPEC_XFGVIRT(IBackgroundCopyCallback, JobModification)
        HRESULT ( STDMETHODCALLTYPE *JobModification )( 
            __RPC__in IBackgroundCopyCallback * This,
            /* [annotation][in] */ 
            _In_  IBackgroundCopyJob *pJob,
            /* [annotation][in] */ 
            _In_  DWORD dwReserved);
        
        END_INTERFACE
    } IBackgroundCopyCallbackVtbl;

    interface IBackgroundCopyCallback
    {
        CONST_VTBL struct IBackgroundCopyCallbackVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBackgroundCopyCallback_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IBackgroundCopyCallback_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IBackgroundCopyCallback_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IBackgroundCopyCallback_JobTransferred(This,pJob)	\
    ( (This)->lpVtbl -> JobTransferred(This,pJob) ) 

#define IBackgroundCopyCallback_JobError(This,pJob,pError)	\
    ( (This)->lpVtbl -> JobError(This,pJob,pError) ) 

#define IBackgroundCopyCallback_JobModification(This,pJob,dwReserved)	\
    ( (This)->lpVtbl -> JobModification(This,pJob,dwReserved) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IBackgroundCopyCallback_INTERFACE_DEFINED__ */


#ifndef __AsyncIBackgroundCopyCallback_INTERFACE_DEFINED__
#define __AsyncIBackgroundCopyCallback_INTERFACE_DEFINED__

/* interface AsyncIBackgroundCopyCallback */
/* [uuid][object][helpstring] */ 


EXTERN_C const IID IID_AsyncIBackgroundCopyCallback;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("ca29d251-b4bb-4679-a3d9-ae8006119d54")
    AsyncIBackgroundCopyCallback : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Begin_JobTransferred( 
            /* [annotation][in] */ 
            _In_  IBackgroundCopyJob *pJob) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_JobTransferred( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_JobError( 
            /* [annotation][in] */ 
            _In_  IBackgroundCopyJob *pJob,
            /* [annotation][in] */ 
            _In_  IBackgroundCopyError *pError) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_JobError( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Begin_JobModification( 
            /* [annotation][in] */ 
            _In_  IBackgroundCopyJob *pJob,
            /* [annotation][in] */ 
            _In_  DWORD dwReserved) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish_JobModification( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct AsyncIBackgroundCopyCallbackVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in AsyncIBackgroundCopyCallback * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in AsyncIBackgroundCopyCallback * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in AsyncIBackgroundCopyCallback * This);
        
        DECLSPEC_XFGVIRT(AsyncIBackgroundCopyCallback, Begin_JobTransferred)
        HRESULT ( STDMETHODCALLTYPE *Begin_JobTransferred )( 
            __RPC__in AsyncIBackgroundCopyCallback * This,
            /* [annotation][in] */ 
            _In_  IBackgroundCopyJob *pJob);
        
        DECLSPEC_XFGVIRT(AsyncIBackgroundCopyCallback, Finish_JobTransferred)
        HRESULT ( STDMETHODCALLTYPE *Finish_JobTransferred )( 
            __RPC__in AsyncIBackgroundCopyCallback * This);
        
        DECLSPEC_XFGVIRT(AsyncIBackgroundCopyCallback, Begin_JobError)
        HRESULT ( STDMETHODCALLTYPE *Begin_JobError )( 
            __RPC__in AsyncIBackgroundCopyCallback * This,
            /* [annotation][in] */ 
            _In_  IBackgroundCopyJob *pJob,
            /* [annotation][in] */ 
            _In_  IBackgroundCopyError *pError);
        
        DECLSPEC_XFGVIRT(AsyncIBackgroundCopyCallback, Finish_JobError)
        HRESULT ( STDMETHODCALLTYPE *Finish_JobError )( 
            __RPC__in AsyncIBackgroundCopyCallback * This);
        
        DECLSPEC_XFGVIRT(AsyncIBackgroundCopyCallback, Begin_JobModification)
        HRESULT ( STDMETHODCALLTYPE *Begin_JobModification )( 
            __RPC__in AsyncIBackgroundCopyCallback * This,
            /* [annotation][in] */ 
            _In_  IBackgroundCopyJob *pJob,
            /* [annotation][in] */ 
            _In_  DWORD dwReserved);
        
        DECLSPEC_XFGVIRT(AsyncIBackgroundCopyCallback, Finish_JobModification)
        HRESULT ( STDMETHODCALLTYPE *Finish_JobModification )( 
            __RPC__in AsyncIBackgroundCopyCallback * This);
        
        END_INTERFACE
    } AsyncIBackgroundCopyCallbackVtbl;

    interface AsyncIBackgroundCopyCallback
    {
        CONST_VTBL struct AsyncIBackgroundCopyCallbackVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define AsyncIBackgroundCopyCallback_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define AsyncIBackgroundCopyCallback_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define AsyncIBackgroundCopyCallback_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define AsyncIBackgroundCopyCallback_Begin_JobTransferred(This,pJob)	\
    ( (This)->lpVtbl -> Begin_JobTransferred(This,pJob) ) 

#define AsyncIBackgroundCopyCallback_Finish_JobTransferred(This)	\
    ( (This)->lpVtbl -> Finish_JobTransferred(This) ) 

#define AsyncIBackgroundCopyCallback_Begin_JobError(This,pJob,pError)	\
    ( (This)->lpVtbl -> Begin_JobError(This,pJob,pError) ) 

#define AsyncIBackgroundCopyCallback_Finish_JobError(This)	\
    ( (This)->lpVtbl -> Finish_JobError(This) ) 

#define AsyncIBackgroundCopyCallback_Begin_JobModification(This,pJob,dwReserved)	\
    ( (This)->lpVtbl -> Begin_JobModification(This,pJob,dwReserved) ) 

#define AsyncIBackgroundCopyCallback_Finish_JobModification(This)	\
    ( (This)->lpVtbl -> Finish_JobModification(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __AsyncIBackgroundCopyCallback_INTERFACE_DEFINED__ */


#ifndef __IBackgroundCopyManager_INTERFACE_DEFINED__
#define __IBackgroundCopyManager_INTERFACE_DEFINED__

/* interface IBackgroundCopyManager */
/* [object][helpstring][uuid] */ 

#define    BG_JOB_ENUM_ALL_USERS  0x0001

EXTERN_C const IID IID_IBackgroundCopyManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5ce34c0d-0dc9-4c1f-897c-daa1b78cee7c")
    IBackgroundCopyManager : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CreateJob( 
            /* [annotation][in] */ 
            _In_  LPCWSTR DisplayName,
            /* [annotation][in] */ 
            _In_  BG_JOB_TYPE Type,
            /* [annotation][out] */ 
            _Out_  GUID *pJobId,
            /* [annotation][out] */ 
            _Out_  IBackgroundCopyJob **ppJob) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetJob( 
            /* [annotation][in] */ 
            _In_  REFGUID jobID,
            /* [annotation][out] */ 
            _Out_  IBackgroundCopyJob **ppJob) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumJobs( 
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][out] */ 
            _Out_  IEnumBackgroundCopyJobs **ppEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetErrorDescription( 
            /* [annotation][in] */ 
            _In_  HRESULT hResult,
            /* [annotation][in] */ 
            _In_  DWORD LanguageId,
            /* [annotation][out] */ 
            _Out_  LPWSTR *pErrorDescription) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IBackgroundCopyManagerVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IBackgroundCopyManager * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IBackgroundCopyManager * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IBackgroundCopyManager * This);
        
        DECLSPEC_XFGVIRT(IBackgroundCopyManager, CreateJob)
        HRESULT ( STDMETHODCALLTYPE *CreateJob )( 
            __RPC__in IBackgroundCopyManager * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR DisplayName,
            /* [annotation][in] */ 
            _In_  BG_JOB_TYPE Type,
            /* [annotation][out] */ 
            _Out_  GUID *pJobId,
            /* [annotation][out] */ 
            _Out_  IBackgroundCopyJob **ppJob);
        
        DECLSPEC_XFGVIRT(IBackgroundCopyManager, GetJob)
        HRESULT ( STDMETHODCALLTYPE *GetJob )( 
            __RPC__in IBackgroundCopyManager * This,
            /* [annotation][in] */ 
            _In_  REFGUID jobID,
            /* [annotation][out] */ 
            _Out_  IBackgroundCopyJob **ppJob);
        
        DECLSPEC_XFGVIRT(IBackgroundCopyManager, EnumJobs)
        HRESULT ( STDMETHODCALLTYPE *EnumJobs )( 
            __RPC__in IBackgroundCopyManager * This,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][out] */ 
            _Out_  IEnumBackgroundCopyJobs **ppEnum);
        
        DECLSPEC_XFGVIRT(IBackgroundCopyManager, GetErrorDescription)
        HRESULT ( STDMETHODCALLTYPE *GetErrorDescription )( 
            __RPC__in IBackgroundCopyManager * This,
            /* [annotation][in] */ 
            _In_  HRESULT hResult,
            /* [annotation][in] */ 
            _In_  DWORD LanguageId,
            /* [annotation][out] */ 
            _Out_  LPWSTR *pErrorDescription);
        
        END_INTERFACE
    } IBackgroundCopyManagerVtbl;

    interface IBackgroundCopyManager
    {
        CONST_VTBL struct IBackgroundCopyManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBackgroundCopyManager_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IBackgroundCopyManager_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IBackgroundCopyManager_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IBackgroundCopyManager_CreateJob(This,DisplayName,Type,pJobId,ppJob)	\
    ( (This)->lpVtbl -> CreateJob(This,DisplayName,Type,pJobId,ppJob) ) 

#define IBackgroundCopyManager_GetJob(This,jobID,ppJob)	\
    ( (This)->lpVtbl -> GetJob(This,jobID,ppJob) ) 

#define IBackgroundCopyManager_EnumJobs(This,dwFlags,ppEnum)	\
    ( (This)->lpVtbl -> EnumJobs(This,dwFlags,ppEnum) ) 

#define IBackgroundCopyManager_GetErrorDescription(This,hResult,LanguageId,pErrorDescription)	\
    ( (This)->lpVtbl -> GetErrorDescription(This,hResult,LanguageId,pErrorDescription) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IBackgroundCopyManager_INTERFACE_DEFINED__ */



#ifndef __BackgroundCopyManager_LIBRARY_DEFINED__
#define __BackgroundCopyManager_LIBRARY_DEFINED__

/* library BackgroundCopyManager */
/* [version][lcid][helpstring][uuid] */ 



EXTERN_C const IID LIBID_BackgroundCopyManager;

EXTERN_C const CLSID CLSID_BackgroundCopyManager;

#ifdef __cplusplus

class DECLSPEC_UUID("4991d34b-80a1-4291-83b6-3328366b9097")
BackgroundCopyManager;
#endif
#endif /* __BackgroundCopyManager_LIBRARY_DEFINED__ */

/* interface __MIDL_itf_bits_0000_0008 */
/* [local] */ 

#include "bits1_5.h"
#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_bits_0000_0008_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_bits_0000_0008_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


