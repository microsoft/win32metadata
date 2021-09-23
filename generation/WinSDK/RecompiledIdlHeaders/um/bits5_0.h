

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

#ifndef __bits5_0_h__
#define __bits5_0_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IBackgroundCopyJob5_FWD_DEFINED__
#define __IBackgroundCopyJob5_FWD_DEFINED__
typedef interface IBackgroundCopyJob5 IBackgroundCopyJob5;

#endif 	/* __IBackgroundCopyJob5_FWD_DEFINED__ */


#ifndef __IBackgroundCopyFile5_FWD_DEFINED__
#define __IBackgroundCopyFile5_FWD_DEFINED__
typedef interface IBackgroundCopyFile5 IBackgroundCopyFile5;

#endif 	/* __IBackgroundCopyFile5_FWD_DEFINED__ */


#ifndef __BackgroundCopyManager5_0_FWD_DEFINED__
#define __BackgroundCopyManager5_0_FWD_DEFINED__

#ifdef __cplusplus
typedef class BackgroundCopyManager5_0 BackgroundCopyManager5_0;
#else
typedef struct BackgroundCopyManager5_0 BackgroundCopyManager5_0;
#endif /* __cplusplus */

#endif 	/* __BackgroundCopyManager5_0_FWD_DEFINED__ */


#ifndef __IBackgroundCopyFile5_FWD_DEFINED__
#define __IBackgroundCopyFile5_FWD_DEFINED__
typedef interface IBackgroundCopyFile5 IBackgroundCopyFile5;

#endif 	/* __IBackgroundCopyFile5_FWD_DEFINED__ */


#ifndef __IBackgroundCopyJob5_FWD_DEFINED__
#define __IBackgroundCopyJob5_FWD_DEFINED__
typedef interface IBackgroundCopyJob5 IBackgroundCopyJob5;

#endif 	/* __IBackgroundCopyJob5_FWD_DEFINED__ */


/* header files for imported files */
#include "bits.h"
#include "bits1_5.h"
#include "bits2_0.h"
#include "bits2_5.h"
#include "bits3_0.h"
#include "bits4_0.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_bits5_0_0000_0000 */
/* [local] */ 

#include <winapifamily.h>
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
#define BITS_COST_STATE_UNRESTRICTED          0x1
#define BITS_COST_STATE_CAPPED_USAGE_UNKNOWN  0x2
#define BITS_COST_STATE_BELOW_CAP             0x4
#define BITS_COST_STATE_NEAR_CAP              0x8
#define BITS_COST_STATE_OVERCAP_CHARGED       0x10
#define BITS_COST_STATE_OVERCAP_THROTTLED     0x20
#define BITS_COST_STATE_USAGE_BASED           0x40
#define BITS_COST_STATE_ROAMING               0x80
#define BITS_COST_OPTION_IGNORE_CONGESTION    0x80000000
#define BITS_COST_STATE_RESERVED              0x40000000
#define BITS_COST_STATE_TRANSFER_NOT_ROAMING  (BITS_COST_OPTION_IGNORE_CONGESTION|BITS_COST_STATE_USAGE_BASED|BITS_COST_STATE_OVERCAP_THROTTLED|BITS_COST_STATE_OVERCAP_CHARGED|BITS_COST_STATE_NEAR_CAP|BITS_COST_STATE_BELOW_CAP|BITS_COST_STATE_CAPPED_USAGE_UNKNOWN|BITS_COST_STATE_UNRESTRICTED)
#define BITS_COST_STATE_TRANSFER_NO_SURCHARGE (BITS_COST_OPTION_IGNORE_CONGESTION|BITS_COST_STATE_USAGE_BASED|BITS_COST_STATE_OVERCAP_THROTTLED|BITS_COST_STATE_NEAR_CAP|BITS_COST_STATE_BELOW_CAP|BITS_COST_STATE_CAPPED_USAGE_UNKNOWN|BITS_COST_STATE_UNRESTRICTED)
#define BITS_COST_STATE_TRANSFER_STANDARD     (BITS_COST_OPTION_IGNORE_CONGESTION|BITS_COST_STATE_USAGE_BASED|BITS_COST_STATE_OVERCAP_THROTTLED|BITS_COST_STATE_BELOW_CAP|BITS_COST_STATE_CAPPED_USAGE_UNKNOWN|BITS_COST_STATE_UNRESTRICTED)
#define BITS_COST_STATE_TRANSFER_UNRESTRICTED (BITS_COST_OPTION_IGNORE_CONGESTION|BITS_COST_STATE_OVERCAP_THROTTLED|BITS_COST_STATE_UNRESTRICTED)
#define BITS_COST_STATE_TRANSFER_ALWAYS       (BITS_COST_OPTION_IGNORE_CONGESTION|BITS_COST_STATE_ROAMING|BITS_COST_STATE_USAGE_BASED|BITS_COST_STATE_OVERCAP_THROTTLED|BITS_COST_STATE_OVERCAP_CHARGED|BITS_COST_STATE_NEAR_CAP|BITS_COST_STATE_BELOW_CAP|BITS_COST_STATE_CAPPED_USAGE_UNKNOWN|BITS_COST_STATE_UNRESTRICTED)
typedef 
enum BITS_JOB_TRANSFER_POLICY
    {
        BITS_JOB_TRANSFER_POLICY_ALWAYS	= 0x800000ff,
        BITS_JOB_TRANSFER_POLICY_NOT_ROAMING	= 0x8000007f,
        BITS_JOB_TRANSFER_POLICY_NO_SURCHARGE	= 0x8000006f,
        BITS_JOB_TRANSFER_POLICY_STANDARD	= 0x80000067,
        BITS_JOB_TRANSFER_POLICY_UNRESTRICTED	= 0x80000021
    } 	BITS_JOB_TRANSFER_POLICY;

typedef 
enum BITS_JOB_PROPERTY_ID
    {
        BITS_JOB_PROPERTY_ID_COST_FLAGS	= 1,
        BITS_JOB_PROPERTY_NOTIFICATION_CLSID	= 2,
        BITS_JOB_PROPERTY_DYNAMIC_CONTENT	= 3,
        BITS_JOB_PROPERTY_HIGH_PERFORMANCE	= 4,
        BITS_JOB_PROPERTY_MAX_DOWNLOAD_SIZE	= 5,
        BITS_JOB_PROPERTY_USE_STORED_CREDENTIALS	= 7,
        BITS_JOB_PROPERTY_MINIMUM_NOTIFICATION_INTERVAL_MS	= 9,
        BITS_JOB_PROPERTY_ON_DEMAND_MODE	= 10
    } 	BITS_JOB_PROPERTY_ID;

typedef /* [public][public][public][switch_type] */ union __MIDL___MIDL_itf_bits5_0_0000_0000_0001
    {
    /* [case()] */ DWORD Dword;
    /* [case()] */ GUID ClsID;
    /* [case()] */ BOOL Enable;
    /* [case()] */ UINT64 Uint64;
    /* [case()] */ BG_AUTH_TARGET Target;
    } 	BITS_JOB_PROPERTY_VALUE;

typedef 
enum BITS_FILE_PROPERTY_ID
    {
        BITS_FILE_PROPERTY_ID_HTTP_RESPONSE_HEADERS	= 1
    } 	BITS_FILE_PROPERTY_ID;

typedef /* [public][public][public][switch_type] */ union __MIDL___MIDL_itf_bits5_0_0000_0000_0002
    {
    /* [case()] */ LPWSTR String;
    } 	BITS_FILE_PROPERTY_VALUE;



extern RPC_IF_HANDLE __MIDL_itf_bits5_0_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_bits5_0_0000_0000_v0_0_s_ifspec;

#ifndef __IBackgroundCopyJob5_INTERFACE_DEFINED__
#define __IBackgroundCopyJob5_INTERFACE_DEFINED__

/* interface IBackgroundCopyJob5 */
/* [object][helpstring][uuid] */ 


EXTERN_C const IID IID_IBackgroundCopyJob5;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E847030C-BBBA-4657-AF6D-484AA42BF1FE")
    IBackgroundCopyJob5 : public IBackgroundCopyJob4
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetProperty( 
            /* [annotation][in] */ 
            _In_  BITS_JOB_PROPERTY_ID PropertyId,
            /* [switch_is][in] */ BITS_JOB_PROPERTY_VALUE PropertyValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetProperty( 
            /* [annotation][in] */ 
            _In_  BITS_JOB_PROPERTY_ID PropertyId,
            /* [switch_is][out] */ __RPC__out BITS_JOB_PROPERTY_VALUE *PropertyValue) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IBackgroundCopyJob5Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IBackgroundCopyJob5 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IBackgroundCopyJob5 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IBackgroundCopyJob5 * This);
        
        HRESULT ( STDMETHODCALLTYPE *AddFileSet )( 
            __RPC__in IBackgroundCopyJob5 * This,
            /* [annotation][in] */ 
            _In_  ULONG cFileCount,
            /* [annotation][size_is][in] */ 
            _In_reads_(cFileCount)  BG_FILE_INFO *pFileSet);
        
        HRESULT ( STDMETHODCALLTYPE *AddFile )( 
            __RPC__in IBackgroundCopyJob5 * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR RemoteUrl,
            /* [annotation][in] */ 
            _In_  LPCWSTR LocalName);
        
        HRESULT ( STDMETHODCALLTYPE *EnumFiles )( 
            __RPC__in IBackgroundCopyJob5 * This,
            /* [annotation][out] */ 
            _Out_  IEnumBackgroundCopyFiles **pEnum);
        
        HRESULT ( STDMETHODCALLTYPE *Suspend )( 
            __RPC__in IBackgroundCopyJob5 * This);
        
        HRESULT ( STDMETHODCALLTYPE *Resume )( 
            __RPC__in IBackgroundCopyJob5 * This);
        
        HRESULT ( STDMETHODCALLTYPE *Cancel )( 
            __RPC__in IBackgroundCopyJob5 * This);
        
        HRESULT ( STDMETHODCALLTYPE *Complete )( 
            __RPC__in IBackgroundCopyJob5 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetId )( 
            __RPC__in IBackgroundCopyJob5 * This,
            /* [annotation][out] */ 
            _Out_  GUID *pVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetType )( 
            __RPC__in IBackgroundCopyJob5 * This,
            /* [annotation][out] */ 
            _Out_  BG_JOB_TYPE *pVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetProgress )( 
            __RPC__in IBackgroundCopyJob5 * This,
            /* [annotation][out] */ 
            _Out_  BG_JOB_PROGRESS *pVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetTimes )( 
            __RPC__in IBackgroundCopyJob5 * This,
            /* [annotation][out] */ 
            _Out_  BG_JOB_TIMES *pVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetState )( 
            __RPC__in IBackgroundCopyJob5 * This,
            /* [annotation][out] */ 
            _Out_  BG_JOB_STATE *pVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetError )( 
            __RPC__in IBackgroundCopyJob5 * This,
            /* [annotation][out] */ 
            _Out_  IBackgroundCopyError **ppError);
        
        HRESULT ( STDMETHODCALLTYPE *GetOwner )( 
            __RPC__in IBackgroundCopyJob5 * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *pVal);
        
        HRESULT ( STDMETHODCALLTYPE *SetDisplayName )( 
            __RPC__in IBackgroundCopyJob5 * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR Val);
        
        HRESULT ( STDMETHODCALLTYPE *GetDisplayName )( 
            __RPC__in IBackgroundCopyJob5 * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *pVal);
        
        HRESULT ( STDMETHODCALLTYPE *SetDescription )( 
            __RPC__in IBackgroundCopyJob5 * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR Val);
        
        HRESULT ( STDMETHODCALLTYPE *GetDescription )( 
            __RPC__in IBackgroundCopyJob5 * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *pVal);
        
        HRESULT ( STDMETHODCALLTYPE *SetPriority )( 
            __RPC__in IBackgroundCopyJob5 * This,
            /* [annotation][in] */ 
            _In_  BG_JOB_PRIORITY Val);
        
        HRESULT ( STDMETHODCALLTYPE *GetPriority )( 
            __RPC__in IBackgroundCopyJob5 * This,
            /* [annotation][out] */ 
            _Out_  BG_JOB_PRIORITY *pVal);
        
        HRESULT ( STDMETHODCALLTYPE *SetNotifyFlags )( 
            __RPC__in IBackgroundCopyJob5 * This,
            /* [annotation][in] */ 
            _In_  ULONG Val);
        
        HRESULT ( STDMETHODCALLTYPE *GetNotifyFlags )( 
            __RPC__in IBackgroundCopyJob5 * This,
            /* [annotation][out] */ 
            _Out_  ULONG *pVal);
        
        HRESULT ( STDMETHODCALLTYPE *SetNotifyInterface )( 
            __RPC__in IBackgroundCopyJob5 * This,
            /* [annotation][in] */ 
            _In_  IUnknown *Val);
        
        HRESULT ( STDMETHODCALLTYPE *GetNotifyInterface )( 
            __RPC__in IBackgroundCopyJob5 * This,
            /* [annotation][out] */ 
            _Out_  IUnknown **pVal);
        
        HRESULT ( STDMETHODCALLTYPE *SetMinimumRetryDelay )( 
            __RPC__in IBackgroundCopyJob5 * This,
            /* [annotation][in] */ 
            _In_  ULONG Seconds);
        
        HRESULT ( STDMETHODCALLTYPE *GetMinimumRetryDelay )( 
            __RPC__in IBackgroundCopyJob5 * This,
            /* [annotation][out] */ 
            _Out_  ULONG *Seconds);
        
        HRESULT ( STDMETHODCALLTYPE *SetNoProgressTimeout )( 
            __RPC__in IBackgroundCopyJob5 * This,
            /* [annotation][in] */ 
            _In_  ULONG Seconds);
        
        HRESULT ( STDMETHODCALLTYPE *GetNoProgressTimeout )( 
            __RPC__in IBackgroundCopyJob5 * This,
            /* [annotation][out] */ 
            _Out_  ULONG *Seconds);
        
        HRESULT ( STDMETHODCALLTYPE *GetErrorCount )( 
            __RPC__in IBackgroundCopyJob5 * This,
            /* [annotation][out] */ 
            _Out_  ULONG *Errors);
        
        HRESULT ( STDMETHODCALLTYPE *SetProxySettings )( 
            __RPC__in IBackgroundCopyJob5 * This,
            /* [annotation][in] */ 
            _In_  BG_JOB_PROXY_USAGE ProxyUsage,
            /* [annotation][unique][string][in] */ 
            _In_  const WCHAR *ProxyList,
            /* [annotation][unique][string][in] */ 
            _In_  const WCHAR *ProxyBypassList);
        
        HRESULT ( STDMETHODCALLTYPE *GetProxySettings )( 
            __RPC__in IBackgroundCopyJob5 * This,
            /* [annotation][out] */ 
            _Out_  BG_JOB_PROXY_USAGE *pProxyUsage,
            /* [annotation][out] */ 
            _Out_  LPWSTR *pProxyList,
            /* [annotation][out] */ 
            _Out_  LPWSTR *pProxyBypassList);
        
        HRESULT ( STDMETHODCALLTYPE *TakeOwnership )( 
            __RPC__in IBackgroundCopyJob5 * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetNotifyCmdLine )( 
            __RPC__in IBackgroundCopyJob5 * This,
            /* [annotation][unique][in] */ 
            _In_  LPCWSTR Program,
            /* [annotation][unique][in] */ 
            _In_  LPCWSTR Parameters);
        
        HRESULT ( STDMETHODCALLTYPE *GetNotifyCmdLine )( 
            __RPC__in IBackgroundCopyJob5 * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *pProgram,
            /* [annotation][out] */ 
            _Out_  LPWSTR *pParameters);
        
        HRESULT ( STDMETHODCALLTYPE *GetReplyProgress )( 
            __RPC__in IBackgroundCopyJob5 * This,
            /* [annotation][out][in] */ 
            _Inout_  BG_JOB_REPLY_PROGRESS *pProgress);
        
        HRESULT ( STDMETHODCALLTYPE *GetReplyData )( 
            __RPC__in IBackgroundCopyJob5 * This,
            /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(( unsigned long  )*pLength) byte **ppBuffer,
            /* [annotation][unique][out][in] */ 
            _Inout_  UINT64 *pLength);
        
        HRESULT ( STDMETHODCALLTYPE *SetReplyFileName )( 
            __RPC__in IBackgroundCopyJob5 * This,
            /* [annotation][unique][in] */ 
            _In_  LPCWSTR ReplyFileName);
        
        HRESULT ( STDMETHODCALLTYPE *GetReplyFileName )( 
            __RPC__in IBackgroundCopyJob5 * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *pReplyFileName);
        
        HRESULT ( STDMETHODCALLTYPE *SetCredentials )( 
            __RPC__in IBackgroundCopyJob5 * This,
            __RPC__in BG_AUTH_CREDENTIALS *credentials);
        
        HRESULT ( STDMETHODCALLTYPE *RemoveCredentials )( 
            __RPC__in IBackgroundCopyJob5 * This,
            BG_AUTH_TARGET Target,
            BG_AUTH_SCHEME Scheme);
        
        HRESULT ( STDMETHODCALLTYPE *ReplaceRemotePrefix )( 
            __RPC__in IBackgroundCopyJob5 * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR OldPrefix,
            /* [annotation][in] */ 
            _In_  LPCWSTR NewPrefix);
        
        HRESULT ( STDMETHODCALLTYPE *AddFileWithRanges )( 
            __RPC__in IBackgroundCopyJob5 * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR RemoteUrl,
            /* [annotation][in] */ 
            _In_  LPCWSTR LocalName,
            /* [annotation][in] */ 
            _In_  DWORD RangeCount,
            /* [annotation][size_is][in] */ 
            _In_reads_(RangeCount)  BG_FILE_RANGE Ranges[  ]);
        
        HRESULT ( STDMETHODCALLTYPE *SetFileACLFlags )( 
            __RPC__in IBackgroundCopyJob5 * This,
            /* [annotation][in] */ 
            _In_  DWORD Flags);
        
        HRESULT ( STDMETHODCALLTYPE *GetFileACLFlags )( 
            __RPC__in IBackgroundCopyJob5 * This,
            /* [ref][out] */ __RPC__out DWORD *Flags);
        
        HRESULT ( STDMETHODCALLTYPE *SetPeerCachingFlags )( 
            __RPC__in IBackgroundCopyJob5 * This,
            DWORD Flags);
        
        HRESULT ( STDMETHODCALLTYPE *GetPeerCachingFlags )( 
            __RPC__in IBackgroundCopyJob5 * This,
            /* [ref][out] */ __RPC__out DWORD *pFlags);
        
        HRESULT ( STDMETHODCALLTYPE *GetOwnerIntegrityLevel )( 
            __RPC__in IBackgroundCopyJob5 * This,
            /* [ref][out] */ __RPC__out ULONG *pLevel);
        
        HRESULT ( STDMETHODCALLTYPE *GetOwnerElevationState )( 
            __RPC__in IBackgroundCopyJob5 * This,
            /* [ref][out] */ __RPC__out BOOL *pElevated);
        
        HRESULT ( STDMETHODCALLTYPE *SetMaximumDownloadTime )( 
            __RPC__in IBackgroundCopyJob5 * This,
            ULONG Timeout);
        
        HRESULT ( STDMETHODCALLTYPE *GetMaximumDownloadTime )( 
            __RPC__in IBackgroundCopyJob5 * This,
            /* [ref][out] */ __RPC__out ULONG *pTimeout);
        
        HRESULT ( STDMETHODCALLTYPE *SetProperty )( 
            __RPC__in IBackgroundCopyJob5 * This,
            /* [annotation][in] */ 
            _In_  BITS_JOB_PROPERTY_ID PropertyId,
            /* [switch_is][in] */ BITS_JOB_PROPERTY_VALUE PropertyValue);
        
        HRESULT ( STDMETHODCALLTYPE *GetProperty )( 
            __RPC__in IBackgroundCopyJob5 * This,
            /* [annotation][in] */ 
            _In_  BITS_JOB_PROPERTY_ID PropertyId,
            /* [switch_is][out] */ __RPC__out BITS_JOB_PROPERTY_VALUE *PropertyValue);
        
        END_INTERFACE
    } IBackgroundCopyJob5Vtbl;

    interface IBackgroundCopyJob5
    {
        CONST_VTBL struct IBackgroundCopyJob5Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBackgroundCopyJob5_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IBackgroundCopyJob5_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IBackgroundCopyJob5_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IBackgroundCopyJob5_AddFileSet(This,cFileCount,pFileSet)	\
    ( (This)->lpVtbl -> AddFileSet(This,cFileCount,pFileSet) ) 

#define IBackgroundCopyJob5_AddFile(This,RemoteUrl,LocalName)	\
    ( (This)->lpVtbl -> AddFile(This,RemoteUrl,LocalName) ) 

#define IBackgroundCopyJob5_EnumFiles(This,pEnum)	\
    ( (This)->lpVtbl -> EnumFiles(This,pEnum) ) 

#define IBackgroundCopyJob5_Suspend(This)	\
    ( (This)->lpVtbl -> Suspend(This) ) 

#define IBackgroundCopyJob5_Resume(This)	\
    ( (This)->lpVtbl -> Resume(This) ) 

#define IBackgroundCopyJob5_Cancel(This)	\
    ( (This)->lpVtbl -> Cancel(This) ) 

#define IBackgroundCopyJob5_Complete(This)	\
    ( (This)->lpVtbl -> Complete(This) ) 

#define IBackgroundCopyJob5_GetId(This,pVal)	\
    ( (This)->lpVtbl -> GetId(This,pVal) ) 

#define IBackgroundCopyJob5_GetType(This,pVal)	\
    ( (This)->lpVtbl -> GetType(This,pVal) ) 

#define IBackgroundCopyJob5_GetProgress(This,pVal)	\
    ( (This)->lpVtbl -> GetProgress(This,pVal) ) 

#define IBackgroundCopyJob5_GetTimes(This,pVal)	\
    ( (This)->lpVtbl -> GetTimes(This,pVal) ) 

#define IBackgroundCopyJob5_GetState(This,pVal)	\
    ( (This)->lpVtbl -> GetState(This,pVal) ) 

#define IBackgroundCopyJob5_GetError(This,ppError)	\
    ( (This)->lpVtbl -> GetError(This,ppError) ) 

#define IBackgroundCopyJob5_GetOwner(This,pVal)	\
    ( (This)->lpVtbl -> GetOwner(This,pVal) ) 

#define IBackgroundCopyJob5_SetDisplayName(This,Val)	\
    ( (This)->lpVtbl -> SetDisplayName(This,Val) ) 

#define IBackgroundCopyJob5_GetDisplayName(This,pVal)	\
    ( (This)->lpVtbl -> GetDisplayName(This,pVal) ) 

#define IBackgroundCopyJob5_SetDescription(This,Val)	\
    ( (This)->lpVtbl -> SetDescription(This,Val) ) 

#define IBackgroundCopyJob5_GetDescription(This,pVal)	\
    ( (This)->lpVtbl -> GetDescription(This,pVal) ) 

#define IBackgroundCopyJob5_SetPriority(This,Val)	\
    ( (This)->lpVtbl -> SetPriority(This,Val) ) 

#define IBackgroundCopyJob5_GetPriority(This,pVal)	\
    ( (This)->lpVtbl -> GetPriority(This,pVal) ) 

#define IBackgroundCopyJob5_SetNotifyFlags(This,Val)	\
    ( (This)->lpVtbl -> SetNotifyFlags(This,Val) ) 

#define IBackgroundCopyJob5_GetNotifyFlags(This,pVal)	\
    ( (This)->lpVtbl -> GetNotifyFlags(This,pVal) ) 

#define IBackgroundCopyJob5_SetNotifyInterface(This,Val)	\
    ( (This)->lpVtbl -> SetNotifyInterface(This,Val) ) 

#define IBackgroundCopyJob5_GetNotifyInterface(This,pVal)	\
    ( (This)->lpVtbl -> GetNotifyInterface(This,pVal) ) 

#define IBackgroundCopyJob5_SetMinimumRetryDelay(This,Seconds)	\
    ( (This)->lpVtbl -> SetMinimumRetryDelay(This,Seconds) ) 

#define IBackgroundCopyJob5_GetMinimumRetryDelay(This,Seconds)	\
    ( (This)->lpVtbl -> GetMinimumRetryDelay(This,Seconds) ) 

#define IBackgroundCopyJob5_SetNoProgressTimeout(This,Seconds)	\
    ( (This)->lpVtbl -> SetNoProgressTimeout(This,Seconds) ) 

#define IBackgroundCopyJob5_GetNoProgressTimeout(This,Seconds)	\
    ( (This)->lpVtbl -> GetNoProgressTimeout(This,Seconds) ) 

#define IBackgroundCopyJob5_GetErrorCount(This,Errors)	\
    ( (This)->lpVtbl -> GetErrorCount(This,Errors) ) 

#define IBackgroundCopyJob5_SetProxySettings(This,ProxyUsage,ProxyList,ProxyBypassList)	\
    ( (This)->lpVtbl -> SetProxySettings(This,ProxyUsage,ProxyList,ProxyBypassList) ) 

#define IBackgroundCopyJob5_GetProxySettings(This,pProxyUsage,pProxyList,pProxyBypassList)	\
    ( (This)->lpVtbl -> GetProxySettings(This,pProxyUsage,pProxyList,pProxyBypassList) ) 

#define IBackgroundCopyJob5_TakeOwnership(This)	\
    ( (This)->lpVtbl -> TakeOwnership(This) ) 


#define IBackgroundCopyJob5_SetNotifyCmdLine(This,Program,Parameters)	\
    ( (This)->lpVtbl -> SetNotifyCmdLine(This,Program,Parameters) ) 

#define IBackgroundCopyJob5_GetNotifyCmdLine(This,pProgram,pParameters)	\
    ( (This)->lpVtbl -> GetNotifyCmdLine(This,pProgram,pParameters) ) 

#define IBackgroundCopyJob5_GetReplyProgress(This,pProgress)	\
    ( (This)->lpVtbl -> GetReplyProgress(This,pProgress) ) 

#define IBackgroundCopyJob5_GetReplyData(This,ppBuffer,pLength)	\
    ( (This)->lpVtbl -> GetReplyData(This,ppBuffer,pLength) ) 

#define IBackgroundCopyJob5_SetReplyFileName(This,ReplyFileName)	\
    ( (This)->lpVtbl -> SetReplyFileName(This,ReplyFileName) ) 

#define IBackgroundCopyJob5_GetReplyFileName(This,pReplyFileName)	\
    ( (This)->lpVtbl -> GetReplyFileName(This,pReplyFileName) ) 

#define IBackgroundCopyJob5_SetCredentials(This,credentials)	\
    ( (This)->lpVtbl -> SetCredentials(This,credentials) ) 

#define IBackgroundCopyJob5_RemoveCredentials(This,Target,Scheme)	\
    ( (This)->lpVtbl -> RemoveCredentials(This,Target,Scheme) ) 


#define IBackgroundCopyJob5_ReplaceRemotePrefix(This,OldPrefix,NewPrefix)	\
    ( (This)->lpVtbl -> ReplaceRemotePrefix(This,OldPrefix,NewPrefix) ) 

#define IBackgroundCopyJob5_AddFileWithRanges(This,RemoteUrl,LocalName,RangeCount,Ranges)	\
    ( (This)->lpVtbl -> AddFileWithRanges(This,RemoteUrl,LocalName,RangeCount,Ranges) ) 

#define IBackgroundCopyJob5_SetFileACLFlags(This,Flags)	\
    ( (This)->lpVtbl -> SetFileACLFlags(This,Flags) ) 

#define IBackgroundCopyJob5_GetFileACLFlags(This,Flags)	\
    ( (This)->lpVtbl -> GetFileACLFlags(This,Flags) ) 


#define IBackgroundCopyJob5_SetPeerCachingFlags(This,Flags)	\
    ( (This)->lpVtbl -> SetPeerCachingFlags(This,Flags) ) 

#define IBackgroundCopyJob5_GetPeerCachingFlags(This,pFlags)	\
    ( (This)->lpVtbl -> GetPeerCachingFlags(This,pFlags) ) 

#define IBackgroundCopyJob5_GetOwnerIntegrityLevel(This,pLevel)	\
    ( (This)->lpVtbl -> GetOwnerIntegrityLevel(This,pLevel) ) 

#define IBackgroundCopyJob5_GetOwnerElevationState(This,pElevated)	\
    ( (This)->lpVtbl -> GetOwnerElevationState(This,pElevated) ) 

#define IBackgroundCopyJob5_SetMaximumDownloadTime(This,Timeout)	\
    ( (This)->lpVtbl -> SetMaximumDownloadTime(This,Timeout) ) 

#define IBackgroundCopyJob5_GetMaximumDownloadTime(This,pTimeout)	\
    ( (This)->lpVtbl -> GetMaximumDownloadTime(This,pTimeout) ) 


#define IBackgroundCopyJob5_SetProperty(This,PropertyId,PropertyValue)	\
    ( (This)->lpVtbl -> SetProperty(This,PropertyId,PropertyValue) ) 

#define IBackgroundCopyJob5_GetProperty(This,PropertyId,PropertyValue)	\
    ( (This)->lpVtbl -> GetProperty(This,PropertyId,PropertyValue) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IBackgroundCopyJob5_INTERFACE_DEFINED__ */


#ifndef __IBackgroundCopyFile5_INTERFACE_DEFINED__
#define __IBackgroundCopyFile5_INTERFACE_DEFINED__

/* interface IBackgroundCopyFile5 */
/* [object][helpstring][uuid] */ 


EXTERN_C const IID IID_IBackgroundCopyFile5;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("85C1657F-DAFC-40E8-8834-DF18EA25717E")
    IBackgroundCopyFile5 : public IBackgroundCopyFile4
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetProperty( 
            /* [annotation][in] */ 
            _In_  BITS_FILE_PROPERTY_ID PropertyId,
            /* [switch_is][in] */ BITS_FILE_PROPERTY_VALUE PropertyValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetProperty( 
            /* [annotation][in] */ 
            _In_  BITS_FILE_PROPERTY_ID PropertyId,
            /* [switch_is][out] */ __RPC__out BITS_FILE_PROPERTY_VALUE *PropertyValue) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IBackgroundCopyFile5Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IBackgroundCopyFile5 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IBackgroundCopyFile5 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IBackgroundCopyFile5 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetRemoteName )( 
            __RPC__in IBackgroundCopyFile5 * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *pVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetLocalName )( 
            __RPC__in IBackgroundCopyFile5 * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *pVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetProgress )( 
            __RPC__in IBackgroundCopyFile5 * This,
            /* [annotation][out] */ 
            _Out_  BG_FILE_PROGRESS *pVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetFileRanges )( 
            __RPC__in IBackgroundCopyFile5 * This,
            /* [annotation][unique][out][in] */ 
            _Inout_  DWORD *RangeCount,
            /* [annotation][size_is][size_is][out] */ 
            _Out_writes_(*RangeCount)  BG_FILE_RANGE **Ranges);
        
        HRESULT ( STDMETHODCALLTYPE *SetRemoteName )( 
            __RPC__in IBackgroundCopyFile5 * This,
            __RPC__in LPCWSTR Val);
        
        HRESULT ( STDMETHODCALLTYPE *GetTemporaryName )( 
            __RPC__in IBackgroundCopyFile5 * This,
            /* [annotation][out] */ 
            _Out_  LPWSTR *pFilename);
        
        HRESULT ( STDMETHODCALLTYPE *SetValidationState )( 
            __RPC__in IBackgroundCopyFile5 * This,
            /* [annotation][in] */ 
            _In_  BOOL state);
        
        HRESULT ( STDMETHODCALLTYPE *GetValidationState )( 
            __RPC__in IBackgroundCopyFile5 * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pState);
        
        HRESULT ( STDMETHODCALLTYPE *IsDownloadedFromPeer )( 
            __RPC__in IBackgroundCopyFile5 * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetPeerDownloadStats )( 
            __RPC__in IBackgroundCopyFile5 * This,
            /* [annotation][out] */ 
            _Out_  PUINT64 pFromOrigin,
            /* [annotation][out] */ 
            _Out_  PUINT64 pFromPeers);
        
        HRESULT ( STDMETHODCALLTYPE *SetProperty )( 
            __RPC__in IBackgroundCopyFile5 * This,
            /* [annotation][in] */ 
            _In_  BITS_FILE_PROPERTY_ID PropertyId,
            /* [switch_is][in] */ BITS_FILE_PROPERTY_VALUE PropertyValue);
        
        HRESULT ( STDMETHODCALLTYPE *GetProperty )( 
            __RPC__in IBackgroundCopyFile5 * This,
            /* [annotation][in] */ 
            _In_  BITS_FILE_PROPERTY_ID PropertyId,
            /* [switch_is][out] */ __RPC__out BITS_FILE_PROPERTY_VALUE *PropertyValue);
        
        END_INTERFACE
    } IBackgroundCopyFile5Vtbl;

    interface IBackgroundCopyFile5
    {
        CONST_VTBL struct IBackgroundCopyFile5Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBackgroundCopyFile5_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IBackgroundCopyFile5_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IBackgroundCopyFile5_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IBackgroundCopyFile5_GetRemoteName(This,pVal)	\
    ( (This)->lpVtbl -> GetRemoteName(This,pVal) ) 

#define IBackgroundCopyFile5_GetLocalName(This,pVal)	\
    ( (This)->lpVtbl -> GetLocalName(This,pVal) ) 

#define IBackgroundCopyFile5_GetProgress(This,pVal)	\
    ( (This)->lpVtbl -> GetProgress(This,pVal) ) 


#define IBackgroundCopyFile5_GetFileRanges(This,RangeCount,Ranges)	\
    ( (This)->lpVtbl -> GetFileRanges(This,RangeCount,Ranges) ) 

#define IBackgroundCopyFile5_SetRemoteName(This,Val)	\
    ( (This)->lpVtbl -> SetRemoteName(This,Val) ) 


#define IBackgroundCopyFile5_GetTemporaryName(This,pFilename)	\
    ( (This)->lpVtbl -> GetTemporaryName(This,pFilename) ) 

#define IBackgroundCopyFile5_SetValidationState(This,state)	\
    ( (This)->lpVtbl -> SetValidationState(This,state) ) 

#define IBackgroundCopyFile5_GetValidationState(This,pState)	\
    ( (This)->lpVtbl -> GetValidationState(This,pState) ) 

#define IBackgroundCopyFile5_IsDownloadedFromPeer(This,pVal)	\
    ( (This)->lpVtbl -> IsDownloadedFromPeer(This,pVal) ) 


#define IBackgroundCopyFile5_GetPeerDownloadStats(This,pFromOrigin,pFromPeers)	\
    ( (This)->lpVtbl -> GetPeerDownloadStats(This,pFromOrigin,pFromPeers) ) 


#define IBackgroundCopyFile5_SetProperty(This,PropertyId,PropertyValue)	\
    ( (This)->lpVtbl -> SetProperty(This,PropertyId,PropertyValue) ) 

#define IBackgroundCopyFile5_GetProperty(This,PropertyId,PropertyValue)	\
    ( (This)->lpVtbl -> GetProperty(This,PropertyId,PropertyValue) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IBackgroundCopyFile5_INTERFACE_DEFINED__ */



#ifndef __BackgroundCopyManager5_0_LIBRARY_DEFINED__
#define __BackgroundCopyManager5_0_LIBRARY_DEFINED__

/* library BackgroundCopyManager5_0 */
/* [version][lcid][helpstring][uuid] */ 












EXTERN_C const IID LIBID_BackgroundCopyManager5_0;

EXTERN_C const CLSID CLSID_BackgroundCopyManager5_0;

#ifdef __cplusplus

class DECLSPEC_UUID("1ECCA34C-E88A-44E3-8D6A-8921BDE9E452")
BackgroundCopyManager5_0;
#endif
#endif /* __BackgroundCopyManager5_0_LIBRARY_DEFINED__ */

/* interface __MIDL_itf_bits5_0_0000_0003 */
/* [local] */ 

#include "bits10_1.h"
#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_bits5_0_0000_0003_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_bits5_0_0000_0003_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


