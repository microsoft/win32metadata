

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

#ifndef __mobsync_h__
#define __mobsync_h__

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

#ifndef __ISyncMgrSynchronizeCallback_FWD_DEFINED__
#define __ISyncMgrSynchronizeCallback_FWD_DEFINED__
typedef interface ISyncMgrSynchronizeCallback ISyncMgrSynchronizeCallback;

#endif 	/* __ISyncMgrSynchronizeCallback_FWD_DEFINED__ */


#ifndef __ISyncMgrEnumItems_FWD_DEFINED__
#define __ISyncMgrEnumItems_FWD_DEFINED__
typedef interface ISyncMgrEnumItems ISyncMgrEnumItems;

#endif 	/* __ISyncMgrEnumItems_FWD_DEFINED__ */


#ifndef __ISyncMgrSynchronize_FWD_DEFINED__
#define __ISyncMgrSynchronize_FWD_DEFINED__
typedef interface ISyncMgrSynchronize ISyncMgrSynchronize;

#endif 	/* __ISyncMgrSynchronize_FWD_DEFINED__ */


#ifndef __ISyncMgrSynchronizeInvoke_FWD_DEFINED__
#define __ISyncMgrSynchronizeInvoke_FWD_DEFINED__
typedef interface ISyncMgrSynchronizeInvoke ISyncMgrSynchronizeInvoke;

#endif 	/* __ISyncMgrSynchronizeInvoke_FWD_DEFINED__ */


#ifndef __ISyncMgrRegister_FWD_DEFINED__
#define __ISyncMgrRegister_FWD_DEFINED__
typedef interface ISyncMgrRegister ISyncMgrRegister;

#endif 	/* __ISyncMgrRegister_FWD_DEFINED__ */


#ifndef __SyncMgr_FWD_DEFINED__
#define __SyncMgr_FWD_DEFINED__

#ifdef __cplusplus
typedef class SyncMgr SyncMgr;
#else
typedef struct SyncMgr SyncMgr;
#endif /* __cplusplus */

#endif 	/* __SyncMgr_FWD_DEFINED__ */


/* header files for imported files */
#include "objidl.h"
#include "oleidl.h"
#include "shobjidl_core.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_mobsync_0000_0000 */
/* [local] */ 

#include <winapifamily.h>
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
#define SYNCMGRITEMID        GUID
#define REFSYNCMGRITEMID     REFGUID
#define SYNCMGRERRORID       GUID
#define REFSYNCMGRERRORID    REFGUID

#define S_SYNCMGR_MISSINGITEMS       MAKE_SCODE(SEVERITY_SUCCESS,FACILITY_ITF,0x0201)
#define S_SYNCMGR_RETRYSYNC          MAKE_SCODE(SEVERITY_SUCCESS,FACILITY_ITF,0x0202)
#define S_SYNCMGR_CANCELITEM         MAKE_SCODE(SEVERITY_SUCCESS,FACILITY_ITF,0x0203)
#define S_SYNCMGR_CANCELALL          MAKE_SCODE(SEVERITY_SUCCESS,FACILITY_ITF,0x0204)
#define S_SYNCMGR_ITEMDELETED        MAKE_SCODE(SEVERITY_SUCCESS,FACILITY_ITF,0x0210)
#define S_SYNCMGR_ENUMITEMS          MAKE_SCODE(SEVERITY_SUCCESS,FACILITY_ITF,0x0211)


extern RPC_IF_HANDLE __MIDL_itf_mobsync_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_mobsync_0000_0000_v0_0_s_ifspec;

#ifndef __ISyncMgrSynchronizeCallback_INTERFACE_DEFINED__
#define __ISyncMgrSynchronizeCallback_INTERFACE_DEFINED__

/* interface ISyncMgrSynchronizeCallback */
/* [uuid][object] */ 

typedef /* [unique] */  __RPC_unique_pointer ISyncMgrSynchronizeCallback *LPSYNCMGRSYNCHRONIZECALLBACK;

#define   SYNCMGRPROGRESSITEM_STATUSTEXT         0x0001
#define   SYNCMGRPROGRESSITEM_STATUSTYPE         0x0002
#define   SYNCMGRPROGRESSITEM_PROGVALUE          0x0004
#define   SYNCMGRPROGRESSITEM_MAXVALUE           0x0008
typedef /* [v1_enum] */ 
enum _tagSYNCMGRSTATUS
    {
        SYNCMGRSTATUS_STOPPED	= 0,
        SYNCMGRSTATUS_SKIPPED	= 0x1,
        SYNCMGRSTATUS_PENDING	= 0x2,
        SYNCMGRSTATUS_UPDATING	= 0x3,
        SYNCMGRSTATUS_SUCCEEDED	= 0x4,
        SYNCMGRSTATUS_FAILED	= 0x5,
        SYNCMGRSTATUS_PAUSED	= 0x6,
        SYNCMGRSTATUS_RESUMING	= 0x7,
        SYNCMGRSTATUS_UPDATING_INDETERMINATE	= 0x8,
        SYNCMGRSTATUS_DELETED	= 0x100
    } 	SYNCMGRSTATUS;

typedef struct _tagSYNCMGRPROGRESSITEM
    {
    DWORD cbSize;
    UINT mask;
    LPCWSTR lpcStatusText;
    DWORD dwStatusType;
    int iProgValue;
    int iMaxValue;
    } 	SYNCMGRPROGRESSITEM;

typedef struct _tagSYNCMGRPROGRESSITEM *LPSYNCMGRPROGRESSITEM;

typedef /* [v1_enum] */ 
enum _tagSYNCMGRLOGLEVEL
    {
        SYNCMGRLOGLEVEL_INFORMATION	= 0x1,
        SYNCMGRLOGLEVEL_WARNING	= 0x2,
        SYNCMGRLOGLEVEL_ERROR	= 0x3,
        SYNCMGRLOGLEVEL_LOGLEVELMAX	= 0x3
    } 	SYNCMGRLOGLEVEL;

#define   SYNCMGRLOGERROR_ERRORFLAGS                     0x0001
#define   SYNCMGRLOGERROR_ERRORID                        0x0002
#define   SYNCMGRLOGERROR_ITEMID                         0x0004
typedef /* [v1_enum] */ 
enum _tagSYNCMGRERRORFLAGS
    {
        SYNCMGRERRORFLAG_ENABLEJUMPTEXT	= 0x1
    } 	SYNCMGRERRORFLAGS;

typedef struct _tagSYNCMGRLOGERRORINFO
    {
    DWORD cbSize;
    DWORD mask;
    DWORD dwSyncMgrErrorFlags;
    GUID ErrorID;
    GUID ItemID;
    } 	SYNCMGRLOGERRORINFO;

typedef struct _tagSYNCMGRLOGERRORINFO *LPSYNCMGRLOGERRORINFO;


EXTERN_C const IID IID_ISyncMgrSynchronizeCallback;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6295DF41-35EE-11d1-8707-00C04FD93327")
    ISyncMgrSynchronizeCallback : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ShowPropertiesCompleted( 
            /* [annotation][in] */ 
            _In_  HRESULT hr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PrepareForSyncCompleted( 
            /* [annotation][in] */ 
            _In_  HRESULT hr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SynchronizeCompleted( 
            /* [annotation][in] */ 
            _In_  HRESULT hr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ShowErrorCompleted( 
            /* [annotation][in] */ 
            _In_  HRESULT hr,
            /* [annotation][in] */ 
            _In_  ULONG cItems,
            /* [annotation][size_is][unique][in] */ 
            _In_reads_(cItems)  const GUID *pItemIDs) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnableModeless( 
            /* [annotation][in] */ 
            _In_  BOOL fEnable) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Progress( 
            /* [annotation][in] */ 
            _In_  REFGUID ItemID,
            /* [annotation][unique][in] */ 
            _In_  const SYNCMGRPROGRESSITEM *pSyncProgressItem) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LogError( 
            /* [annotation][in] */ 
            _In_  DWORD dwErrorLevel,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszErrorText,
            /* [annotation][unique][in] */ 
            _In_  const SYNCMGRLOGERRORINFO *pSyncLogError) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DeleteLogError( 
            /* [annotation][in] */ 
            _In_  REFGUID ErrorID,
            /* [annotation][in] */ 
            _In_  DWORD dwReserved) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EstablishConnection( 
            /* [annotation][unique][in] */ 
            _In_  LPCWSTR pwszConnection,
            /* [annotation][in] */ 
            _In_  DWORD dwReserved) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISyncMgrSynchronizeCallbackVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISyncMgrSynchronizeCallback * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISyncMgrSynchronizeCallback * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISyncMgrSynchronizeCallback * This);
        
        DECLSPEC_XFGVIRT(ISyncMgrSynchronizeCallback, ShowPropertiesCompleted)
        HRESULT ( STDMETHODCALLTYPE *ShowPropertiesCompleted )( 
            __RPC__in ISyncMgrSynchronizeCallback * This,
            /* [annotation][in] */ 
            _In_  HRESULT hr);
        
        DECLSPEC_XFGVIRT(ISyncMgrSynchronizeCallback, PrepareForSyncCompleted)
        HRESULT ( STDMETHODCALLTYPE *PrepareForSyncCompleted )( 
            __RPC__in ISyncMgrSynchronizeCallback * This,
            /* [annotation][in] */ 
            _In_  HRESULT hr);
        
        DECLSPEC_XFGVIRT(ISyncMgrSynchronizeCallback, SynchronizeCompleted)
        HRESULT ( STDMETHODCALLTYPE *SynchronizeCompleted )( 
            __RPC__in ISyncMgrSynchronizeCallback * This,
            /* [annotation][in] */ 
            _In_  HRESULT hr);
        
        DECLSPEC_XFGVIRT(ISyncMgrSynchronizeCallback, ShowErrorCompleted)
        HRESULT ( STDMETHODCALLTYPE *ShowErrorCompleted )( 
            __RPC__in ISyncMgrSynchronizeCallback * This,
            /* [annotation][in] */ 
            _In_  HRESULT hr,
            /* [annotation][in] */ 
            _In_  ULONG cItems,
            /* [annotation][size_is][unique][in] */ 
            _In_reads_(cItems)  const GUID *pItemIDs);
        
        DECLSPEC_XFGVIRT(ISyncMgrSynchronizeCallback, EnableModeless)
        HRESULT ( STDMETHODCALLTYPE *EnableModeless )( 
            __RPC__in ISyncMgrSynchronizeCallback * This,
            /* [annotation][in] */ 
            _In_  BOOL fEnable);
        
        DECLSPEC_XFGVIRT(ISyncMgrSynchronizeCallback, Progress)
        HRESULT ( STDMETHODCALLTYPE *Progress )( 
            __RPC__in ISyncMgrSynchronizeCallback * This,
            /* [annotation][in] */ 
            _In_  REFGUID ItemID,
            /* [annotation][unique][in] */ 
            _In_  const SYNCMGRPROGRESSITEM *pSyncProgressItem);
        
        DECLSPEC_XFGVIRT(ISyncMgrSynchronizeCallback, LogError)
        HRESULT ( STDMETHODCALLTYPE *LogError )( 
            __RPC__in ISyncMgrSynchronizeCallback * This,
            /* [annotation][in] */ 
            _In_  DWORD dwErrorLevel,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszErrorText,
            /* [annotation][unique][in] */ 
            _In_  const SYNCMGRLOGERRORINFO *pSyncLogError);
        
        DECLSPEC_XFGVIRT(ISyncMgrSynchronizeCallback, DeleteLogError)
        HRESULT ( STDMETHODCALLTYPE *DeleteLogError )( 
            __RPC__in ISyncMgrSynchronizeCallback * This,
            /* [annotation][in] */ 
            _In_  REFGUID ErrorID,
            /* [annotation][in] */ 
            _In_  DWORD dwReserved);
        
        DECLSPEC_XFGVIRT(ISyncMgrSynchronizeCallback, EstablishConnection)
        HRESULT ( STDMETHODCALLTYPE *EstablishConnection )( 
            __RPC__in ISyncMgrSynchronizeCallback * This,
            /* [annotation][unique][in] */ 
            _In_  LPCWSTR pwszConnection,
            /* [annotation][in] */ 
            _In_  DWORD dwReserved);
        
        END_INTERFACE
    } ISyncMgrSynchronizeCallbackVtbl;

    interface ISyncMgrSynchronizeCallback
    {
        CONST_VTBL struct ISyncMgrSynchronizeCallbackVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISyncMgrSynchronizeCallback_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISyncMgrSynchronizeCallback_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISyncMgrSynchronizeCallback_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISyncMgrSynchronizeCallback_ShowPropertiesCompleted(This,hr)	\
    ( (This)->lpVtbl -> ShowPropertiesCompleted(This,hr) ) 

#define ISyncMgrSynchronizeCallback_PrepareForSyncCompleted(This,hr)	\
    ( (This)->lpVtbl -> PrepareForSyncCompleted(This,hr) ) 

#define ISyncMgrSynchronizeCallback_SynchronizeCompleted(This,hr)	\
    ( (This)->lpVtbl -> SynchronizeCompleted(This,hr) ) 

#define ISyncMgrSynchronizeCallback_ShowErrorCompleted(This,hr,cItems,pItemIDs)	\
    ( (This)->lpVtbl -> ShowErrorCompleted(This,hr,cItems,pItemIDs) ) 

#define ISyncMgrSynchronizeCallback_EnableModeless(This,fEnable)	\
    ( (This)->lpVtbl -> EnableModeless(This,fEnable) ) 

#define ISyncMgrSynchronizeCallback_Progress(This,ItemID,pSyncProgressItem)	\
    ( (This)->lpVtbl -> Progress(This,ItemID,pSyncProgressItem) ) 

#define ISyncMgrSynchronizeCallback_LogError(This,dwErrorLevel,pszErrorText,pSyncLogError)	\
    ( (This)->lpVtbl -> LogError(This,dwErrorLevel,pszErrorText,pSyncLogError) ) 

#define ISyncMgrSynchronizeCallback_DeleteLogError(This,ErrorID,dwReserved)	\
    ( (This)->lpVtbl -> DeleteLogError(This,ErrorID,dwReserved) ) 

#define ISyncMgrSynchronizeCallback_EstablishConnection(This,pwszConnection,dwReserved)	\
    ( (This)->lpVtbl -> EstablishConnection(This,pwszConnection,dwReserved) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISyncMgrSynchronizeCallback_INTERFACE_DEFINED__ */


#ifndef __ISyncMgrEnumItems_INTERFACE_DEFINED__
#define __ISyncMgrEnumItems_INTERFACE_DEFINED__

/* interface ISyncMgrEnumItems */
/* [unique][uuid][object] */ 

typedef /* [unique] */  __RPC_unique_pointer ISyncMgrEnumItems *LPSYNCMGRENUMITEMS;

typedef /* [v1_enum] */ 
enum _tagSYNCMGRITEMFLAGS
    {
        SYNCMGRITEM_HASPROPERTIES	= 0x1,
        SYNCMGRITEM_TEMPORARY	= 0x2,
        SYNCMGRITEM_ROAMINGUSER	= 0x4,
        SYNCMGRITEM_LASTUPDATETIME	= 0x8,
        SYNCMGRITEM_MAYDELETEITEM	= 0x10,
        SYNCMGRITEM_HIDDEN	= 0x20
    } 	SYNCMGRITEMFLAGS;

#define SYNCMGRITEM_ITEMFLAGMASK  0x007F
#define	MAX_SYNCMGRITEMNAME	( 128 )

typedef struct _tagSYNCMGRITEM
    {
    DWORD cbSize;
    DWORD dwFlags;
    GUID ItemID;
    DWORD dwItemState;
    HICON hIcon;
    WCHAR wszItemName[ 128 ];
    FILETIME ftLastUpdate;
    } 	SYNCMGRITEM;

typedef struct _tagSYNCMGRITEM *LPSYNCMGRITEM;


EXTERN_C const IID IID_ISyncMgrEnumItems;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6295DF2A-35EE-11d1-8707-00C04FD93327")
    ISyncMgrEnumItems : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [annotation][in] */ 
            _In_  ULONG celt,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(celt,*pceltFetched)  SYNCMGRITEM *rgelt,
            /* [annotation][out] */ 
            _Out_  ULONG *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [annotation][in] */ 
            _In_  ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [annotation][out] */ 
            _Out_  ISyncMgrEnumItems **ppenum) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISyncMgrEnumItemsVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISyncMgrEnumItems * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISyncMgrEnumItems * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISyncMgrEnumItems * This);
        
        DECLSPEC_XFGVIRT(ISyncMgrEnumItems, Next)
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            __RPC__in ISyncMgrEnumItems * This,
            /* [annotation][in] */ 
            _In_  ULONG celt,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(celt,*pceltFetched)  SYNCMGRITEM *rgelt,
            /* [annotation][out] */ 
            _Out_  ULONG *pceltFetched);
        
        DECLSPEC_XFGVIRT(ISyncMgrEnumItems, Skip)
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            __RPC__in ISyncMgrEnumItems * This,
            /* [annotation][in] */ 
            _In_  ULONG celt);
        
        DECLSPEC_XFGVIRT(ISyncMgrEnumItems, Reset)
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            __RPC__in ISyncMgrEnumItems * This);
        
        DECLSPEC_XFGVIRT(ISyncMgrEnumItems, Clone)
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            __RPC__in ISyncMgrEnumItems * This,
            /* [annotation][out] */ 
            _Out_  ISyncMgrEnumItems **ppenum);
        
        END_INTERFACE
    } ISyncMgrEnumItemsVtbl;

    interface ISyncMgrEnumItems
    {
        CONST_VTBL struct ISyncMgrEnumItemsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISyncMgrEnumItems_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISyncMgrEnumItems_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISyncMgrEnumItems_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISyncMgrEnumItems_Next(This,celt,rgelt,pceltFetched)	\
    ( (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched) ) 

#define ISyncMgrEnumItems_Skip(This,celt)	\
    ( (This)->lpVtbl -> Skip(This,celt) ) 

#define ISyncMgrEnumItems_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define ISyncMgrEnumItems_Clone(This,ppenum)	\
    ( (This)->lpVtbl -> Clone(This,ppenum) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISyncMgrEnumItems_INTERFACE_DEFINED__ */


#ifndef __ISyncMgrSynchronize_INTERFACE_DEFINED__
#define __ISyncMgrSynchronize_INTERFACE_DEFINED__

/* interface ISyncMgrSynchronize */
/* [uuid][object] */ 

typedef /* [unique] */  __RPC_unique_pointer ISyncMgrSynchronize *LPSYNCMGROnSynchronize;

typedef /* [v1_enum] */ 
enum _tagSYNCMGRFLAG
    {
        SYNCMGRFLAG_CONNECT	= 0x1,
        SYNCMGRFLAG_PENDINGDISCONNECT	= 0x2,
        SYNCMGRFLAG_MANUAL	= 0x3,
        SYNCMGRFLAG_IDLE	= 0x4,
        SYNCMGRFLAG_INVOKE	= 0x5,
        SYNCMGRFLAG_SCHEDULED	= 0x6,
        SYNCMGRFLAG_EVENTMASK	= 0xff,
        SYNCMGRFLAG_SETTINGS	= 0x100,
        SYNCMGRFLAG_MAYBOTHERUSER	= 0x200
    } 	SYNCMGRFLAG;

typedef /* [v1_enum] */ 
enum _tagSYNCMGRHANDLERFLAGS
    {
        SYNCMGRHANDLER_HASPROPERTIES	= 0x1,
        SYNCMGRHANDLER_MAYESTABLISHCONNECTION	= 0x2,
        SYNCMGRHANDLER_ALWAYSLISTHANDLER	= 0x4,
        SYNCMGRHANDLER_HIDDEN	= 0x8
    } 	SYNCMGRHANDLERFLAGS;

#define SYNCMGRHANDLERFLAG_MASK 0x000f
#define	MAX_SYNCMGRHANDLERNAME	( 32 )

typedef struct _tagSYNCMGRHANDLERINFO
    {
    DWORD cbSize;
    HICON hIcon;
    DWORD SyncMgrHandlerFlags;
    WCHAR wszHandlerName[ 32 ];
    } 	SYNCMGRHANDLERINFO;

typedef struct _tagSYNCMGRHANDLERINFO *LPSYNCMGRHANDLERINFO;

typedef /* [v1_enum] */ 
enum _tagSYNCMGRITEMSTATE
    {
        SYNCMGRITEMSTATE_UNCHECKED	= 0,
        SYNCMGRITEMSTATE_CHECKED	= 0x1
    } 	SYNCMGRITEMSTATE;


EXTERN_C const IID IID_ISyncMgrSynchronize;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6295DF40-35EE-11d1-8707-00C04FD93327")
    ISyncMgrSynchronize : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Initialize( 
            /* [annotation][in] */ 
            _In_  DWORD dwReserved,
            /* [annotation][in] */ 
            _In_  DWORD dwSyncMgrFlags,
            /* [annotation][in] */ 
            _In_  DWORD cbCookie,
            /* [annotation][size_is][unique][in] */ 
            _In_reads_(cbCookie)  const BYTE *lpCookie) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetHandlerInfo( 
            /* [annotation][out] */ 
            _Out_  SYNCMGRHANDLERINFO **ppSyncMgrHandlerInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumSyncMgrItems( 
            /* [annotation][out] */ 
            _Out_  ISyncMgrEnumItems **ppSyncMgrEnumItems) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetItemObject( 
            /* [annotation][in] */ 
            _In_  REFGUID ItemID,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppv) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ShowProperties( 
            /* [annotation][in] */ 
            _In_  HWND hWndParent,
            /* [annotation][in] */ 
            _In_  REFGUID ItemID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetProgressCallback( 
            /* [annotation][unique][in] */ 
            _In_  ISyncMgrSynchronizeCallback *lpCallBack) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PrepareForSync( 
            /* [annotation][in] */ 
            _In_  ULONG cbNumItems,
            /* [annotation][size_is][in] */ 
            _In_reads_(cbNumItems)  GUID *pItemIDs,
            /* [annotation][in] */ 
            _In_  HWND hWndParent,
            /* [annotation][in] */ 
            _In_  DWORD dwReserved) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Synchronize( 
            /* [annotation][in] */ 
            _In_  HWND hWndParent) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetItemStatus( 
            /* [annotation][in] */ 
            _In_  REFGUID pItemID,
            /* [annotation][in] */ 
            _In_  DWORD dwSyncMgrStatus) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ShowError( 
            /* [annotation][in] */ 
            _In_  HWND hWndParent,
            /* [annotation][in] */ 
            _In_  REFGUID ErrorID) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISyncMgrSynchronizeVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISyncMgrSynchronize * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISyncMgrSynchronize * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISyncMgrSynchronize * This);
        
        DECLSPEC_XFGVIRT(ISyncMgrSynchronize, Initialize)
        HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            __RPC__in ISyncMgrSynchronize * This,
            /* [annotation][in] */ 
            _In_  DWORD dwReserved,
            /* [annotation][in] */ 
            _In_  DWORD dwSyncMgrFlags,
            /* [annotation][in] */ 
            _In_  DWORD cbCookie,
            /* [annotation][size_is][unique][in] */ 
            _In_reads_(cbCookie)  const BYTE *lpCookie);
        
        DECLSPEC_XFGVIRT(ISyncMgrSynchronize, GetHandlerInfo)
        HRESULT ( STDMETHODCALLTYPE *GetHandlerInfo )( 
            __RPC__in ISyncMgrSynchronize * This,
            /* [annotation][out] */ 
            _Out_  SYNCMGRHANDLERINFO **ppSyncMgrHandlerInfo);
        
        DECLSPEC_XFGVIRT(ISyncMgrSynchronize, EnumSyncMgrItems)
        HRESULT ( STDMETHODCALLTYPE *EnumSyncMgrItems )( 
            __RPC__in ISyncMgrSynchronize * This,
            /* [annotation][out] */ 
            _Out_  ISyncMgrEnumItems **ppSyncMgrEnumItems);
        
        DECLSPEC_XFGVIRT(ISyncMgrSynchronize, GetItemObject)
        HRESULT ( STDMETHODCALLTYPE *GetItemObject )( 
            __RPC__in ISyncMgrSynchronize * This,
            /* [annotation][in] */ 
            _In_  REFGUID ItemID,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppv);
        
        DECLSPEC_XFGVIRT(ISyncMgrSynchronize, ShowProperties)
        HRESULT ( STDMETHODCALLTYPE *ShowProperties )( 
            __RPC__in ISyncMgrSynchronize * This,
            /* [annotation][in] */ 
            _In_  HWND hWndParent,
            /* [annotation][in] */ 
            _In_  REFGUID ItemID);
        
        DECLSPEC_XFGVIRT(ISyncMgrSynchronize, SetProgressCallback)
        HRESULT ( STDMETHODCALLTYPE *SetProgressCallback )( 
            __RPC__in ISyncMgrSynchronize * This,
            /* [annotation][unique][in] */ 
            _In_  ISyncMgrSynchronizeCallback *lpCallBack);
        
        DECLSPEC_XFGVIRT(ISyncMgrSynchronize, PrepareForSync)
        HRESULT ( STDMETHODCALLTYPE *PrepareForSync )( 
            __RPC__in ISyncMgrSynchronize * This,
            /* [annotation][in] */ 
            _In_  ULONG cbNumItems,
            /* [annotation][size_is][in] */ 
            _In_reads_(cbNumItems)  GUID *pItemIDs,
            /* [annotation][in] */ 
            _In_  HWND hWndParent,
            /* [annotation][in] */ 
            _In_  DWORD dwReserved);
        
        DECLSPEC_XFGVIRT(ISyncMgrSynchronize, Synchronize)
        HRESULT ( STDMETHODCALLTYPE *Synchronize )( 
            __RPC__in ISyncMgrSynchronize * This,
            /* [annotation][in] */ 
            _In_  HWND hWndParent);
        
        DECLSPEC_XFGVIRT(ISyncMgrSynchronize, SetItemStatus)
        HRESULT ( STDMETHODCALLTYPE *SetItemStatus )( 
            __RPC__in ISyncMgrSynchronize * This,
            /* [annotation][in] */ 
            _In_  REFGUID pItemID,
            /* [annotation][in] */ 
            _In_  DWORD dwSyncMgrStatus);
        
        DECLSPEC_XFGVIRT(ISyncMgrSynchronize, ShowError)
        HRESULT ( STDMETHODCALLTYPE *ShowError )( 
            __RPC__in ISyncMgrSynchronize * This,
            /* [annotation][in] */ 
            _In_  HWND hWndParent,
            /* [annotation][in] */ 
            _In_  REFGUID ErrorID);
        
        END_INTERFACE
    } ISyncMgrSynchronizeVtbl;

    interface ISyncMgrSynchronize
    {
        CONST_VTBL struct ISyncMgrSynchronizeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISyncMgrSynchronize_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISyncMgrSynchronize_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISyncMgrSynchronize_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISyncMgrSynchronize_Initialize(This,dwReserved,dwSyncMgrFlags,cbCookie,lpCookie)	\
    ( (This)->lpVtbl -> Initialize(This,dwReserved,dwSyncMgrFlags,cbCookie,lpCookie) ) 

#define ISyncMgrSynchronize_GetHandlerInfo(This,ppSyncMgrHandlerInfo)	\
    ( (This)->lpVtbl -> GetHandlerInfo(This,ppSyncMgrHandlerInfo) ) 

#define ISyncMgrSynchronize_EnumSyncMgrItems(This,ppSyncMgrEnumItems)	\
    ( (This)->lpVtbl -> EnumSyncMgrItems(This,ppSyncMgrEnumItems) ) 

#define ISyncMgrSynchronize_GetItemObject(This,ItemID,riid,ppv)	\
    ( (This)->lpVtbl -> GetItemObject(This,ItemID,riid,ppv) ) 

#define ISyncMgrSynchronize_ShowProperties(This,hWndParent,ItemID)	\
    ( (This)->lpVtbl -> ShowProperties(This,hWndParent,ItemID) ) 

#define ISyncMgrSynchronize_SetProgressCallback(This,lpCallBack)	\
    ( (This)->lpVtbl -> SetProgressCallback(This,lpCallBack) ) 

#define ISyncMgrSynchronize_PrepareForSync(This,cbNumItems,pItemIDs,hWndParent,dwReserved)	\
    ( (This)->lpVtbl -> PrepareForSync(This,cbNumItems,pItemIDs,hWndParent,dwReserved) ) 

#define ISyncMgrSynchronize_Synchronize(This,hWndParent)	\
    ( (This)->lpVtbl -> Synchronize(This,hWndParent) ) 

#define ISyncMgrSynchronize_SetItemStatus(This,pItemID,dwSyncMgrStatus)	\
    ( (This)->lpVtbl -> SetItemStatus(This,pItemID,dwSyncMgrStatus) ) 

#define ISyncMgrSynchronize_ShowError(This,hWndParent,ErrorID)	\
    ( (This)->lpVtbl -> ShowError(This,hWndParent,ErrorID) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISyncMgrSynchronize_INTERFACE_DEFINED__ */


#ifndef __ISyncMgrSynchronizeInvoke_INTERFACE_DEFINED__
#define __ISyncMgrSynchronizeInvoke_INTERFACE_DEFINED__

/* interface ISyncMgrSynchronizeInvoke */
/* [unique][uuid][object] */ 

typedef /* [unique] */  __RPC_unique_pointer ISyncMgrSynchronizeInvoke *LPSYNCMGRSYNCHRONIZEINVOKE;

typedef /* [v1_enum] */ 
enum _tagSYNCMGRINVOKEFLAGS
    {
        SYNCMGRINVOKE_STARTSYNC	= 0x2,
        SYNCMGRINVOKE_MINIMIZED	= 0x4
    } 	SYNCMGRINVOKEFLAGS;


EXTERN_C const IID IID_ISyncMgrSynchronizeInvoke;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6295DF2C-35EE-11d1-8707-00C04FD93327")
    ISyncMgrSynchronizeInvoke : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE UpdateItems( 
            /* [annotation][in] */ 
            _In_  DWORD dwInvokeFlags,
            /* [annotation][in] */ 
            _In_  REFCLSID clsid,
            /* [annotation][in] */ 
            _In_  DWORD cbCookie,
            /* [annotation][size_is][unique][in] */ 
            _In_reads_(cbCookie)  const BYTE *pCookie) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UpdateAll( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISyncMgrSynchronizeInvokeVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISyncMgrSynchronizeInvoke * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISyncMgrSynchronizeInvoke * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISyncMgrSynchronizeInvoke * This);
        
        DECLSPEC_XFGVIRT(ISyncMgrSynchronizeInvoke, UpdateItems)
        HRESULT ( STDMETHODCALLTYPE *UpdateItems )( 
            __RPC__in ISyncMgrSynchronizeInvoke * This,
            /* [annotation][in] */ 
            _In_  DWORD dwInvokeFlags,
            /* [annotation][in] */ 
            _In_  REFCLSID clsid,
            /* [annotation][in] */ 
            _In_  DWORD cbCookie,
            /* [annotation][size_is][unique][in] */ 
            _In_reads_(cbCookie)  const BYTE *pCookie);
        
        DECLSPEC_XFGVIRT(ISyncMgrSynchronizeInvoke, UpdateAll)
        HRESULT ( STDMETHODCALLTYPE *UpdateAll )( 
            __RPC__in ISyncMgrSynchronizeInvoke * This);
        
        END_INTERFACE
    } ISyncMgrSynchronizeInvokeVtbl;

    interface ISyncMgrSynchronizeInvoke
    {
        CONST_VTBL struct ISyncMgrSynchronizeInvokeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISyncMgrSynchronizeInvoke_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISyncMgrSynchronizeInvoke_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISyncMgrSynchronizeInvoke_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISyncMgrSynchronizeInvoke_UpdateItems(This,dwInvokeFlags,clsid,cbCookie,pCookie)	\
    ( (This)->lpVtbl -> UpdateItems(This,dwInvokeFlags,clsid,cbCookie,pCookie) ) 

#define ISyncMgrSynchronizeInvoke_UpdateAll(This)	\
    ( (This)->lpVtbl -> UpdateAll(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISyncMgrSynchronizeInvoke_INTERFACE_DEFINED__ */


#ifndef __ISyncMgrRegister_INTERFACE_DEFINED__
#define __ISyncMgrRegister_INTERFACE_DEFINED__

/* interface ISyncMgrRegister */
/* [unique][uuid][object] */ 

typedef /* [unique] */  __RPC_unique_pointer ISyncMgrRegister *LPSYNCMGRREGISTER;

typedef /* [v1_enum] */ 
enum _tagSYNCMGRREGISTERFLAGS
    {
        SYNCMGRREGISTERFLAG_CONNECT	= 0x1,
        SYNCMGRREGISTERFLAG_PENDINGDISCONNECT	= 0x2,
        SYNCMGRREGISTERFLAG_IDLE	= 0x4
    } 	SYNCMGRREGISTERFLAGS;

#define SYNCMGRREGISTERFLAGS_MASK  0x07

EXTERN_C const IID IID_ISyncMgrRegister;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6295DF42-35EE-11d1-8707-00C04FD93327")
    ISyncMgrRegister : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE RegisterSyncMgrHandler( 
            /* [annotation][in] */ 
            _In_  REFCLSID clsidHandler,
            /* [annotation][unique][in] */ 
            _In_  LPCWSTR pwszDescription,
            /* [annotation][in] */ 
            _In_  DWORD dwSyncMgrRegisterFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UnregisterSyncMgrHandler( 
            /* [annotation][in] */ 
            _In_  REFCLSID clsidHandler,
            /* [annotation][in] */ 
            _In_  DWORD dwReserved) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetHandlerRegistrationInfo( 
            /* [annotation][in] */ 
            _In_  REFCLSID clsidHandler,
            /* [annotation][out][in] */ 
            _Inout_  LPDWORD pdwSyncMgrRegisterFlags) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISyncMgrRegisterVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISyncMgrRegister * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISyncMgrRegister * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISyncMgrRegister * This);
        
        DECLSPEC_XFGVIRT(ISyncMgrRegister, RegisterSyncMgrHandler)
        HRESULT ( STDMETHODCALLTYPE *RegisterSyncMgrHandler )( 
            __RPC__in ISyncMgrRegister * This,
            /* [annotation][in] */ 
            _In_  REFCLSID clsidHandler,
            /* [annotation][unique][in] */ 
            _In_  LPCWSTR pwszDescription,
            /* [annotation][in] */ 
            _In_  DWORD dwSyncMgrRegisterFlags);
        
        DECLSPEC_XFGVIRT(ISyncMgrRegister, UnregisterSyncMgrHandler)
        HRESULT ( STDMETHODCALLTYPE *UnregisterSyncMgrHandler )( 
            __RPC__in ISyncMgrRegister * This,
            /* [annotation][in] */ 
            _In_  REFCLSID clsidHandler,
            /* [annotation][in] */ 
            _In_  DWORD dwReserved);
        
        DECLSPEC_XFGVIRT(ISyncMgrRegister, GetHandlerRegistrationInfo)
        HRESULT ( STDMETHODCALLTYPE *GetHandlerRegistrationInfo )( 
            __RPC__in ISyncMgrRegister * This,
            /* [annotation][in] */ 
            _In_  REFCLSID clsidHandler,
            /* [annotation][out][in] */ 
            _Inout_  LPDWORD pdwSyncMgrRegisterFlags);
        
        END_INTERFACE
    } ISyncMgrRegisterVtbl;

    interface ISyncMgrRegister
    {
        CONST_VTBL struct ISyncMgrRegisterVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISyncMgrRegister_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISyncMgrRegister_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISyncMgrRegister_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISyncMgrRegister_RegisterSyncMgrHandler(This,clsidHandler,pwszDescription,dwSyncMgrRegisterFlags)	\
    ( (This)->lpVtbl -> RegisterSyncMgrHandler(This,clsidHandler,pwszDescription,dwSyncMgrRegisterFlags) ) 

#define ISyncMgrRegister_UnregisterSyncMgrHandler(This,clsidHandler,dwReserved)	\
    ( (This)->lpVtbl -> UnregisterSyncMgrHandler(This,clsidHandler,dwReserved) ) 

#define ISyncMgrRegister_GetHandlerRegistrationInfo(This,clsidHandler,pdwSyncMgrRegisterFlags)	\
    ( (This)->lpVtbl -> GetHandlerRegistrationInfo(This,clsidHandler,pdwSyncMgrRegisterFlags) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISyncMgrRegister_INTERFACE_DEFINED__ */



#ifndef __SyncObjects_LIBRARY_DEFINED__
#define __SyncObjects_LIBRARY_DEFINED__

/* library SyncObjects */
/* [version][lcid][helpstring][uuid] */ 


EXTERN_C const IID LIBID_SyncObjects;

EXTERN_C const CLSID CLSID_SyncMgr;

#ifdef __cplusplus

class DECLSPEC_UUID("6295DF27-35EE-11d1-8707-00C04FD93327")
SyncMgr;
#endif
#endif /* __SyncObjects_LIBRARY_DEFINED__ */

/* interface __MIDL_itf_mobsync_0000_0006 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_mobsync_0000_0006_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_mobsync_0000_0006_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  HICON_UserSize(     __RPC__in unsigned long *, unsigned long            , __RPC__in HICON * ); 
unsigned char * __RPC_USER  HICON_UserMarshal(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in HICON * ); 
unsigned char * __RPC_USER  HICON_UserUnmarshal(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out HICON * ); 
void                      __RPC_USER  HICON_UserFree(     __RPC__in unsigned long *, __RPC__in HICON * ); 

unsigned long             __RPC_USER  HWND_UserSize(     __RPC__in unsigned long *, unsigned long            , __RPC__in HWND * ); 
unsigned char * __RPC_USER  HWND_UserMarshal(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in HWND * ); 
unsigned char * __RPC_USER  HWND_UserUnmarshal(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out HWND * ); 
void                      __RPC_USER  HWND_UserFree(     __RPC__in unsigned long *, __RPC__in HWND * ); 

unsigned long             __RPC_USER  HICON_UserSize64(     __RPC__in unsigned long *, unsigned long            , __RPC__in HICON * ); 
unsigned char * __RPC_USER  HICON_UserMarshal64(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in HICON * ); 
unsigned char * __RPC_USER  HICON_UserUnmarshal64(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out HICON * ); 
void                      __RPC_USER  HICON_UserFree64(     __RPC__in unsigned long *, __RPC__in HICON * ); 

unsigned long             __RPC_USER  HWND_UserSize64(     __RPC__in unsigned long *, unsigned long            , __RPC__in HWND * ); 
unsigned char * __RPC_USER  HWND_UserMarshal64(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in HWND * ); 
unsigned char * __RPC_USER  HWND_UserUnmarshal64(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out HWND * ); 
void                      __RPC_USER  HWND_UserFree64(     __RPC__in unsigned long *, __RPC__in HWND * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


