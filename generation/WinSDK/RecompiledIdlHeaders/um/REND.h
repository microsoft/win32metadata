

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

#ifndef __rend_h__
#define __rend_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ITDirectoryObjectConference_FWD_DEFINED__
#define __ITDirectoryObjectConference_FWD_DEFINED__
typedef interface ITDirectoryObjectConference ITDirectoryObjectConference;

#endif 	/* __ITDirectoryObjectConference_FWD_DEFINED__ */


#ifndef __ITDirectoryObjectUser_FWD_DEFINED__
#define __ITDirectoryObjectUser_FWD_DEFINED__
typedef interface ITDirectoryObjectUser ITDirectoryObjectUser;

#endif 	/* __ITDirectoryObjectUser_FWD_DEFINED__ */


#ifndef __IEnumDialableAddrs_FWD_DEFINED__
#define __IEnumDialableAddrs_FWD_DEFINED__
typedef interface IEnumDialableAddrs IEnumDialableAddrs;

#endif 	/* __IEnumDialableAddrs_FWD_DEFINED__ */


#ifndef __ITDirectoryObject_FWD_DEFINED__
#define __ITDirectoryObject_FWD_DEFINED__
typedef interface ITDirectoryObject ITDirectoryObject;

#endif 	/* __ITDirectoryObject_FWD_DEFINED__ */


#ifndef __IEnumDirectoryObject_FWD_DEFINED__
#define __IEnumDirectoryObject_FWD_DEFINED__
typedef interface IEnumDirectoryObject IEnumDirectoryObject;

#endif 	/* __IEnumDirectoryObject_FWD_DEFINED__ */


#ifndef __ITILSConfig_FWD_DEFINED__
#define __ITILSConfig_FWD_DEFINED__
typedef interface ITILSConfig ITILSConfig;

#endif 	/* __ITILSConfig_FWD_DEFINED__ */


#ifndef __ITDirectory_FWD_DEFINED__
#define __ITDirectory_FWD_DEFINED__
typedef interface ITDirectory ITDirectory;

#endif 	/* __ITDirectory_FWD_DEFINED__ */


#ifndef __IEnumDirectory_FWD_DEFINED__
#define __IEnumDirectory_FWD_DEFINED__
typedef interface IEnumDirectory IEnumDirectory;

#endif 	/* __IEnumDirectory_FWD_DEFINED__ */


#ifndef __ITRendezvous_FWD_DEFINED__
#define __ITRendezvous_FWD_DEFINED__
typedef interface ITRendezvous ITRendezvous;

#endif 	/* __ITRendezvous_FWD_DEFINED__ */


#ifndef __ITRendezvous_FWD_DEFINED__
#define __ITRendezvous_FWD_DEFINED__
typedef interface ITRendezvous ITRendezvous;

#endif 	/* __ITRendezvous_FWD_DEFINED__ */


#ifndef __ITDirectoryObjectConference_FWD_DEFINED__
#define __ITDirectoryObjectConference_FWD_DEFINED__
typedef interface ITDirectoryObjectConference ITDirectoryObjectConference;

#endif 	/* __ITDirectoryObjectConference_FWD_DEFINED__ */


#ifndef __ITDirectoryObjectUser_FWD_DEFINED__
#define __ITDirectoryObjectUser_FWD_DEFINED__
typedef interface ITDirectoryObjectUser ITDirectoryObjectUser;

#endif 	/* __ITDirectoryObjectUser_FWD_DEFINED__ */


#ifndef __ITDirectoryObject_FWD_DEFINED__
#define __ITDirectoryObject_FWD_DEFINED__
typedef interface ITDirectoryObject ITDirectoryObject;

#endif 	/* __ITDirectoryObject_FWD_DEFINED__ */


#ifndef __ITILSConfig_FWD_DEFINED__
#define __ITILSConfig_FWD_DEFINED__
typedef interface ITILSConfig ITILSConfig;

#endif 	/* __ITILSConfig_FWD_DEFINED__ */


#ifndef __ITDirectory_FWD_DEFINED__
#define __ITDirectory_FWD_DEFINED__
typedef interface ITDirectory ITDirectory;

#endif 	/* __ITDirectory_FWD_DEFINED__ */


#ifndef __Rendezvous_FWD_DEFINED__
#define __Rendezvous_FWD_DEFINED__

#ifdef __cplusplus
typedef class Rendezvous Rendezvous;
#else
typedef struct Rendezvous Rendezvous;
#endif /* __cplusplus */

#endif 	/* __Rendezvous_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "tapi3if.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_rend_0000_0000 */
/* [local] */ 

/* Copyright (c) Microsoft Corporation. All rights reserved. */
#include <winapifamily.h>
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
#define	IDISPDIROBJECT	( 0x10000 )

#define	IDISPDIROBJCONFERENCE	( 0x20000 )

#define	IDISPDIROBJUSER	( 0x30000 )

#define	IDISPDIRECTORY	( 0x10000 )

#define	IDISPILSCONFIG	( 0x20000 )

typedef 
enum DIRECTORY_TYPE
    {
        DT_NTDS	= 1,
        DT_ILS	= 2
    } 	DIRECTORY_TYPE;

typedef 
enum DIRECTORY_OBJECT_TYPE
    {
        OT_CONFERENCE	= 1,
        OT_USER	= 2
    } 	DIRECTORY_OBJECT_TYPE;

typedef 
enum RND_ADVERTISING_SCOPE
    {
        RAS_LOCAL	= 1,
        RAS_SITE	= 2,
        RAS_REGION	= 3,
        RAS_WORLD	= 4
    } 	RND_ADVERTISING_SCOPE;



extern RPC_IF_HANDLE __MIDL_itf_rend_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_rend_0000_0000_v0_0_s_ifspec;

#ifndef __ITDirectoryObjectConference_INTERFACE_DEFINED__
#define __ITDirectoryObjectConference_INTERFACE_DEFINED__

/* interface ITDirectoryObjectConference */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ITDirectoryObjectConference;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F1029E5D-CB5B-11D0-8D59-00C04FD91AC0")
    ITDirectoryObjectConference : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Protocol( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *ppProtocol) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Originator( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *ppOriginator) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Originator( 
            /* [annotation][in] */ 
            _In_  BSTR pOriginator) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AdvertisingScope( 
            /* [annotation][retval][out] */ 
            _Out_retval_  RND_ADVERTISING_SCOPE *pAdvertisingScope) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AdvertisingScope( 
            /* [annotation][in] */ 
            _In_  RND_ADVERTISING_SCOPE AdvertisingScope) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Url( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *ppUrl) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Url( 
            /* [annotation][in] */ 
            _In_  BSTR pUrl) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Description( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *ppDescription) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Description( 
            /* [annotation][in] */ 
            _In_  BSTR pDescription) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IsEncrypted( 
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pfEncrypted) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_IsEncrypted( 
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL fEncrypted) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StartTime( 
            /* [annotation][retval][out] */ 
            _Out_retval_  DATE *pDate) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_StartTime( 
            /* [annotation][in] */ 
            _In_  DATE Date) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StopTime( 
            /* [annotation][retval][out] */ 
            _Out_retval_  DATE *pDate) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_StopTime( 
            /* [annotation][in] */ 
            _In_  DATE Date) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITDirectoryObjectConferenceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ITDirectoryObjectConference * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ITDirectoryObjectConference * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ITDirectoryObjectConference * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in ITDirectoryObjectConference * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in ITDirectoryObjectConference * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in ITDirectoryObjectConference * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][size_is][in] */ 
            _In_reads_(cNames)  LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cNames)  DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITDirectoryObjectConference * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Protocol )( 
            __RPC__in ITDirectoryObjectConference * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *ppProtocol);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Originator )( 
            __RPC__in ITDirectoryObjectConference * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *ppOriginator);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Originator )( 
            __RPC__in ITDirectoryObjectConference * This,
            /* [annotation][in] */ 
            _In_  BSTR pOriginator);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AdvertisingScope )( 
            __RPC__in ITDirectoryObjectConference * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  RND_ADVERTISING_SCOPE *pAdvertisingScope);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AdvertisingScope )( 
            __RPC__in ITDirectoryObjectConference * This,
            /* [annotation][in] */ 
            _In_  RND_ADVERTISING_SCOPE AdvertisingScope);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Url )( 
            __RPC__in ITDirectoryObjectConference * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *ppUrl);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Url )( 
            __RPC__in ITDirectoryObjectConference * This,
            /* [annotation][in] */ 
            _In_  BSTR pUrl);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Description )( 
            __RPC__in ITDirectoryObjectConference * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *ppDescription);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Description )( 
            __RPC__in ITDirectoryObjectConference * This,
            /* [annotation][in] */ 
            _In_  BSTR pDescription);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsEncrypted )( 
            __RPC__in ITDirectoryObjectConference * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pfEncrypted);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_IsEncrypted )( 
            __RPC__in ITDirectoryObjectConference * This,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL fEncrypted);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StartTime )( 
            __RPC__in ITDirectoryObjectConference * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  DATE *pDate);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_StartTime )( 
            __RPC__in ITDirectoryObjectConference * This,
            /* [annotation][in] */ 
            _In_  DATE Date);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StopTime )( 
            __RPC__in ITDirectoryObjectConference * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  DATE *pDate);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_StopTime )( 
            __RPC__in ITDirectoryObjectConference * This,
            /* [annotation][in] */ 
            _In_  DATE Date);
        
        END_INTERFACE
    } ITDirectoryObjectConferenceVtbl;

    interface ITDirectoryObjectConference
    {
        CONST_VTBL struct ITDirectoryObjectConferenceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITDirectoryObjectConference_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITDirectoryObjectConference_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITDirectoryObjectConference_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITDirectoryObjectConference_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ITDirectoryObjectConference_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ITDirectoryObjectConference_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ITDirectoryObjectConference_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ITDirectoryObjectConference_get_Protocol(This,ppProtocol)	\
    ( (This)->lpVtbl -> get_Protocol(This,ppProtocol) ) 

#define ITDirectoryObjectConference_get_Originator(This,ppOriginator)	\
    ( (This)->lpVtbl -> get_Originator(This,ppOriginator) ) 

#define ITDirectoryObjectConference_put_Originator(This,pOriginator)	\
    ( (This)->lpVtbl -> put_Originator(This,pOriginator) ) 

#define ITDirectoryObjectConference_get_AdvertisingScope(This,pAdvertisingScope)	\
    ( (This)->lpVtbl -> get_AdvertisingScope(This,pAdvertisingScope) ) 

#define ITDirectoryObjectConference_put_AdvertisingScope(This,AdvertisingScope)	\
    ( (This)->lpVtbl -> put_AdvertisingScope(This,AdvertisingScope) ) 

#define ITDirectoryObjectConference_get_Url(This,ppUrl)	\
    ( (This)->lpVtbl -> get_Url(This,ppUrl) ) 

#define ITDirectoryObjectConference_put_Url(This,pUrl)	\
    ( (This)->lpVtbl -> put_Url(This,pUrl) ) 

#define ITDirectoryObjectConference_get_Description(This,ppDescription)	\
    ( (This)->lpVtbl -> get_Description(This,ppDescription) ) 

#define ITDirectoryObjectConference_put_Description(This,pDescription)	\
    ( (This)->lpVtbl -> put_Description(This,pDescription) ) 

#define ITDirectoryObjectConference_get_IsEncrypted(This,pfEncrypted)	\
    ( (This)->lpVtbl -> get_IsEncrypted(This,pfEncrypted) ) 

#define ITDirectoryObjectConference_put_IsEncrypted(This,fEncrypted)	\
    ( (This)->lpVtbl -> put_IsEncrypted(This,fEncrypted) ) 

#define ITDirectoryObjectConference_get_StartTime(This,pDate)	\
    ( (This)->lpVtbl -> get_StartTime(This,pDate) ) 

#define ITDirectoryObjectConference_put_StartTime(This,Date)	\
    ( (This)->lpVtbl -> put_StartTime(This,Date) ) 

#define ITDirectoryObjectConference_get_StopTime(This,pDate)	\
    ( (This)->lpVtbl -> get_StopTime(This,pDate) ) 

#define ITDirectoryObjectConference_put_StopTime(This,Date)	\
    ( (This)->lpVtbl -> put_StopTime(This,Date) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITDirectoryObjectConference_INTERFACE_DEFINED__ */


#ifndef __ITDirectoryObjectUser_INTERFACE_DEFINED__
#define __ITDirectoryObjectUser_INTERFACE_DEFINED__

/* interface ITDirectoryObjectUser */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ITDirectoryObjectUser;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("34621D6F-6CFF-11d1-AFF7-00C04FC31FEE")
    ITDirectoryObjectUser : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IPPhonePrimary( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *ppName) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_IPPhonePrimary( 
            /* [annotation][in] */ 
            _In_  BSTR pName) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITDirectoryObjectUserVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ITDirectoryObjectUser * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ITDirectoryObjectUser * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ITDirectoryObjectUser * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in ITDirectoryObjectUser * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in ITDirectoryObjectUser * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in ITDirectoryObjectUser * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][size_is][in] */ 
            _In_reads_(cNames)  LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cNames)  DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITDirectoryObjectUser * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IPPhonePrimary )( 
            __RPC__in ITDirectoryObjectUser * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *ppName);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_IPPhonePrimary )( 
            __RPC__in ITDirectoryObjectUser * This,
            /* [annotation][in] */ 
            _In_  BSTR pName);
        
        END_INTERFACE
    } ITDirectoryObjectUserVtbl;

    interface ITDirectoryObjectUser
    {
        CONST_VTBL struct ITDirectoryObjectUserVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITDirectoryObjectUser_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITDirectoryObjectUser_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITDirectoryObjectUser_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITDirectoryObjectUser_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ITDirectoryObjectUser_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ITDirectoryObjectUser_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ITDirectoryObjectUser_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ITDirectoryObjectUser_get_IPPhonePrimary(This,ppName)	\
    ( (This)->lpVtbl -> get_IPPhonePrimary(This,ppName) ) 

#define ITDirectoryObjectUser_put_IPPhonePrimary(This,pName)	\
    ( (This)->lpVtbl -> put_IPPhonePrimary(This,pName) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITDirectoryObjectUser_INTERFACE_DEFINED__ */


#ifndef __IEnumDialableAddrs_INTERFACE_DEFINED__
#define __IEnumDialableAddrs_INTERFACE_DEFINED__

/* interface IEnumDialableAddrs */
/* [object][unique][restricted][hidden][helpstring][uuid] */ 


EXTERN_C const IID IID_IEnumDialableAddrs;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("34621D70-6CFF-11d1-AFF7-00C04FC31FEE")
    IEnumDialableAddrs : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [annotation][in] */ 
            _In_  ULONG celt,
            /* [annotation][size_is][out] */ 
            _Out_writes_(celt)  BSTR *ppElements,
            /* [full][out][in] */ __RPC__inout_opt ULONG *pcFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [annotation][in] */ 
            _In_  ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IEnumDialableAddrs **ppEnum) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IEnumDialableAddrsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IEnumDialableAddrs * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IEnumDialableAddrs * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IEnumDialableAddrs * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            __RPC__in IEnumDialableAddrs * This,
            /* [annotation][in] */ 
            _In_  ULONG celt,
            /* [annotation][size_is][out] */ 
            _Out_writes_(celt)  BSTR *ppElements,
            /* [full][out][in] */ __RPC__inout_opt ULONG *pcFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            __RPC__in IEnumDialableAddrs * This);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            __RPC__in IEnumDialableAddrs * This,
            /* [annotation][in] */ 
            _In_  ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            __RPC__in IEnumDialableAddrs * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IEnumDialableAddrs **ppEnum);
        
        END_INTERFACE
    } IEnumDialableAddrsVtbl;

    interface IEnumDialableAddrs
    {
        CONST_VTBL struct IEnumDialableAddrsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumDialableAddrs_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEnumDialableAddrs_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEnumDialableAddrs_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IEnumDialableAddrs_Next(This,celt,ppElements,pcFetched)	\
    ( (This)->lpVtbl -> Next(This,celt,ppElements,pcFetched) ) 

#define IEnumDialableAddrs_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define IEnumDialableAddrs_Skip(This,celt)	\
    ( (This)->lpVtbl -> Skip(This,celt) ) 

#define IEnumDialableAddrs_Clone(This,ppEnum)	\
    ( (This)->lpVtbl -> Clone(This,ppEnum) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IEnumDialableAddrs_INTERFACE_DEFINED__ */


#ifndef __ITDirectoryObject_INTERFACE_DEFINED__
#define __ITDirectoryObject_INTERFACE_DEFINED__

/* interface ITDirectoryObject */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ITDirectoryObject;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("34621D6E-6CFF-11d1-AFF7-00C04FC31FEE")
    ITDirectoryObject : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ObjectType( 
            /* [annotation][retval][out] */ 
            _Out_retval_  DIRECTORY_OBJECT_TYPE *pObjectType) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *ppName) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [annotation][in] */ 
            _In_  BSTR pName) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DialableAddrs( 
            /* [annotation][in] */ 
            _In_  long dwAddressType,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT *pVariant) = 0;
        
        virtual /* [helpstring][restricted][hidden][id] */ HRESULT STDMETHODCALLTYPE EnumerateDialableAddrs( 
            /* [annotation][in] */ 
            _In_  DWORD dwAddressType,
            /* [annotation][out] */ 
            _Out_  IEnumDialableAddrs **ppEnumDialableAddrs) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SecurityDescriptor( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IDispatch **ppSecDes) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SecurityDescriptor( 
            /* [annotation][in] */ 
            _In_  IDispatch *pSecDes) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITDirectoryObjectVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ITDirectoryObject * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ITDirectoryObject * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ITDirectoryObject * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in ITDirectoryObject * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in ITDirectoryObject * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in ITDirectoryObject * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][size_is][in] */ 
            _In_reads_(cNames)  LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cNames)  DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITDirectoryObject * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ObjectType )( 
            __RPC__in ITDirectoryObject * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  DIRECTORY_OBJECT_TYPE *pObjectType);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            __RPC__in ITDirectoryObject * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *ppName);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            __RPC__in ITDirectoryObject * This,
            /* [annotation][in] */ 
            _In_  BSTR pName);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DialableAddrs )( 
            __RPC__in ITDirectoryObject * This,
            /* [annotation][in] */ 
            _In_  long dwAddressType,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT *pVariant);
        
        /* [helpstring][restricted][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *EnumerateDialableAddrs )( 
            __RPC__in ITDirectoryObject * This,
            /* [annotation][in] */ 
            _In_  DWORD dwAddressType,
            /* [annotation][out] */ 
            _Out_  IEnumDialableAddrs **ppEnumDialableAddrs);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SecurityDescriptor )( 
            __RPC__in ITDirectoryObject * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IDispatch **ppSecDes);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SecurityDescriptor )( 
            __RPC__in ITDirectoryObject * This,
            /* [annotation][in] */ 
            _In_  IDispatch *pSecDes);
        
        END_INTERFACE
    } ITDirectoryObjectVtbl;

    interface ITDirectoryObject
    {
        CONST_VTBL struct ITDirectoryObjectVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITDirectoryObject_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITDirectoryObject_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITDirectoryObject_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITDirectoryObject_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ITDirectoryObject_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ITDirectoryObject_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ITDirectoryObject_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ITDirectoryObject_get_ObjectType(This,pObjectType)	\
    ( (This)->lpVtbl -> get_ObjectType(This,pObjectType) ) 

#define ITDirectoryObject_get_Name(This,ppName)	\
    ( (This)->lpVtbl -> get_Name(This,ppName) ) 

#define ITDirectoryObject_put_Name(This,pName)	\
    ( (This)->lpVtbl -> put_Name(This,pName) ) 

#define ITDirectoryObject_get_DialableAddrs(This,dwAddressType,pVariant)	\
    ( (This)->lpVtbl -> get_DialableAddrs(This,dwAddressType,pVariant) ) 

#define ITDirectoryObject_EnumerateDialableAddrs(This,dwAddressType,ppEnumDialableAddrs)	\
    ( (This)->lpVtbl -> EnumerateDialableAddrs(This,dwAddressType,ppEnumDialableAddrs) ) 

#define ITDirectoryObject_get_SecurityDescriptor(This,ppSecDes)	\
    ( (This)->lpVtbl -> get_SecurityDescriptor(This,ppSecDes) ) 

#define ITDirectoryObject_put_SecurityDescriptor(This,pSecDes)	\
    ( (This)->lpVtbl -> put_SecurityDescriptor(This,pSecDes) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITDirectoryObject_INTERFACE_DEFINED__ */


#ifndef __IEnumDirectoryObject_INTERFACE_DEFINED__
#define __IEnumDirectoryObject_INTERFACE_DEFINED__

/* interface IEnumDirectoryObject */
/* [unique][restricted][hidden][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IEnumDirectoryObject;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("06C9B64A-306D-11D1-9774-00C04FD91AC0")
    IEnumDirectoryObject : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [annotation][in] */ 
            _In_  ULONG celt,
            /* [annotation][size_is][out] */ 
            _Out_writes_(celt)  ITDirectoryObject **pVal,
            /* [full][out][in] */ __RPC__inout_opt ULONG *pcFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [annotation][in] */ 
            _In_  ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IEnumDirectoryObject **ppEnum) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IEnumDirectoryObjectVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IEnumDirectoryObject * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IEnumDirectoryObject * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IEnumDirectoryObject * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            __RPC__in IEnumDirectoryObject * This,
            /* [annotation][in] */ 
            _In_  ULONG celt,
            /* [annotation][size_is][out] */ 
            _Out_writes_(celt)  ITDirectoryObject **pVal,
            /* [full][out][in] */ __RPC__inout_opt ULONG *pcFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            __RPC__in IEnumDirectoryObject * This);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            __RPC__in IEnumDirectoryObject * This,
            /* [annotation][in] */ 
            _In_  ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            __RPC__in IEnumDirectoryObject * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IEnumDirectoryObject **ppEnum);
        
        END_INTERFACE
    } IEnumDirectoryObjectVtbl;

    interface IEnumDirectoryObject
    {
        CONST_VTBL struct IEnumDirectoryObjectVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumDirectoryObject_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEnumDirectoryObject_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEnumDirectoryObject_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IEnumDirectoryObject_Next(This,celt,pVal,pcFetched)	\
    ( (This)->lpVtbl -> Next(This,celt,pVal,pcFetched) ) 

#define IEnumDirectoryObject_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define IEnumDirectoryObject_Skip(This,celt)	\
    ( (This)->lpVtbl -> Skip(This,celt) ) 

#define IEnumDirectoryObject_Clone(This,ppEnum)	\
    ( (This)->lpVtbl -> Clone(This,ppEnum) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IEnumDirectoryObject_INTERFACE_DEFINED__ */


#ifndef __ITILSConfig_INTERFACE_DEFINED__
#define __ITILSConfig_INTERFACE_DEFINED__

/* interface ITILSConfig */
/* [helpstring][dual][uuid][public][object] */ 


EXTERN_C const IID IID_ITILSConfig;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("34621D72-6CFF-11d1-AFF7-00C04FC31FEE")
    ITILSConfig : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Port( 
            /* [annotation][retval][out] */ 
            _Out_retval_  long *pPort) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Port( 
            /* [annotation][in] */ 
            _In_  long Port) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITILSConfigVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ITILSConfig * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ITILSConfig * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ITILSConfig * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in ITILSConfig * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in ITILSConfig * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in ITILSConfig * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][size_is][in] */ 
            _In_reads_(cNames)  LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cNames)  DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITILSConfig * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Port )( 
            __RPC__in ITILSConfig * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *pPort);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Port )( 
            __RPC__in ITILSConfig * This,
            /* [annotation][in] */ 
            _In_  long Port);
        
        END_INTERFACE
    } ITILSConfigVtbl;

    interface ITILSConfig
    {
        CONST_VTBL struct ITILSConfigVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITILSConfig_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITILSConfig_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITILSConfig_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITILSConfig_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ITILSConfig_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ITILSConfig_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ITILSConfig_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ITILSConfig_get_Port(This,pPort)	\
    ( (This)->lpVtbl -> get_Port(This,pPort) ) 

#define ITILSConfig_put_Port(This,Port)	\
    ( (This)->lpVtbl -> put_Port(This,Port) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITILSConfig_INTERFACE_DEFINED__ */


#ifndef __ITDirectory_INTERFACE_DEFINED__
#define __ITDirectory_INTERFACE_DEFINED__

/* interface ITDirectory */
/* [helpstring][dual][uuid][public][object] */ 


EXTERN_C const IID IID_ITDirectory;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("34621D6C-6CFF-11d1-AFF7-00C04FC31FEE")
    ITDirectory : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DirectoryType( 
            /* [annotation][retval][out] */ 
            _Out_retval_  DIRECTORY_TYPE *pDirectoryType) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DisplayName( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pName) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IsDynamic( 
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pfDynamic) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DefaultObjectTTL( 
            /* [annotation][retval][out] */ 
            _Out_retval_  long *pTTL) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DefaultObjectTTL( 
            /* [annotation][in] */ 
            _In_  long TTL) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EnableAutoRefresh( 
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL fEnable) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Connect( 
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL fSecure) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Bind( 
            /* [annotation][in] */ 
            _In_  BSTR pDomainName,
            /* [annotation][in] */ 
            _In_  BSTR pUserName,
            /* [annotation][in] */ 
            _In_  BSTR pPassword,
            /* [annotation][in] */ 
            _In_  long lFlags) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddDirectoryObject( 
            /* [annotation][in] */ 
            _In_  ITDirectoryObject *pDirectoryObject) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ModifyDirectoryObject( 
            /* [annotation][in] */ 
            _In_  ITDirectoryObject *pDirectoryObject) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RefreshDirectoryObject( 
            /* [annotation][in] */ 
            _In_  ITDirectoryObject *pDirectoryObject) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteDirectoryObject( 
            /* [annotation][in] */ 
            _In_  ITDirectoryObject *pDirectoryObject) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DirectoryObjects( 
            /* [annotation][in] */ 
            _In_  DIRECTORY_OBJECT_TYPE DirectoryObjectType,
            /* [annotation][in] */ 
            _In_  BSTR pName,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT *pVariant) = 0;
        
        virtual /* [helpstring][restricted][hidden][id] */ HRESULT STDMETHODCALLTYPE EnumerateDirectoryObjects( 
            /* [annotation][in] */ 
            _In_  DIRECTORY_OBJECT_TYPE DirectoryObjectType,
            /* [annotation][in] */ 
            _In_  BSTR pName,
            /* [annotation][out] */ 
            _Out_  IEnumDirectoryObject **ppEnumObject) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITDirectoryVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ITDirectory * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ITDirectory * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ITDirectory * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in ITDirectory * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in ITDirectory * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in ITDirectory * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][size_is][in] */ 
            _In_reads_(cNames)  LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cNames)  DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITDirectory * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DirectoryType )( 
            __RPC__in ITDirectory * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  DIRECTORY_TYPE *pDirectoryType);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DisplayName )( 
            __RPC__in ITDirectory * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pName);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsDynamic )( 
            __RPC__in ITDirectory * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pfDynamic);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultObjectTTL )( 
            __RPC__in ITDirectory * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *pTTL);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultObjectTTL )( 
            __RPC__in ITDirectory * This,
            /* [annotation][in] */ 
            _In_  long TTL);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EnableAutoRefresh )( 
            __RPC__in ITDirectory * This,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL fEnable);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Connect )( 
            __RPC__in ITDirectory * This,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL fSecure);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Bind )( 
            __RPC__in ITDirectory * This,
            /* [annotation][in] */ 
            _In_  BSTR pDomainName,
            /* [annotation][in] */ 
            _In_  BSTR pUserName,
            /* [annotation][in] */ 
            _In_  BSTR pPassword,
            /* [annotation][in] */ 
            _In_  long lFlags);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddDirectoryObject )( 
            __RPC__in ITDirectory * This,
            /* [annotation][in] */ 
            _In_  ITDirectoryObject *pDirectoryObject);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ModifyDirectoryObject )( 
            __RPC__in ITDirectory * This,
            /* [annotation][in] */ 
            _In_  ITDirectoryObject *pDirectoryObject);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RefreshDirectoryObject )( 
            __RPC__in ITDirectory * This,
            /* [annotation][in] */ 
            _In_  ITDirectoryObject *pDirectoryObject);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeleteDirectoryObject )( 
            __RPC__in ITDirectory * This,
            /* [annotation][in] */ 
            _In_  ITDirectoryObject *pDirectoryObject);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DirectoryObjects )( 
            __RPC__in ITDirectory * This,
            /* [annotation][in] */ 
            _In_  DIRECTORY_OBJECT_TYPE DirectoryObjectType,
            /* [annotation][in] */ 
            _In_  BSTR pName,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT *pVariant);
        
        /* [helpstring][restricted][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *EnumerateDirectoryObjects )( 
            __RPC__in ITDirectory * This,
            /* [annotation][in] */ 
            _In_  DIRECTORY_OBJECT_TYPE DirectoryObjectType,
            /* [annotation][in] */ 
            _In_  BSTR pName,
            /* [annotation][out] */ 
            _Out_  IEnumDirectoryObject **ppEnumObject);
        
        END_INTERFACE
    } ITDirectoryVtbl;

    interface ITDirectory
    {
        CONST_VTBL struct ITDirectoryVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITDirectory_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITDirectory_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITDirectory_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITDirectory_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ITDirectory_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ITDirectory_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ITDirectory_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ITDirectory_get_DirectoryType(This,pDirectoryType)	\
    ( (This)->lpVtbl -> get_DirectoryType(This,pDirectoryType) ) 

#define ITDirectory_get_DisplayName(This,pName)	\
    ( (This)->lpVtbl -> get_DisplayName(This,pName) ) 

#define ITDirectory_get_IsDynamic(This,pfDynamic)	\
    ( (This)->lpVtbl -> get_IsDynamic(This,pfDynamic) ) 

#define ITDirectory_get_DefaultObjectTTL(This,pTTL)	\
    ( (This)->lpVtbl -> get_DefaultObjectTTL(This,pTTL) ) 

#define ITDirectory_put_DefaultObjectTTL(This,TTL)	\
    ( (This)->lpVtbl -> put_DefaultObjectTTL(This,TTL) ) 

#define ITDirectory_EnableAutoRefresh(This,fEnable)	\
    ( (This)->lpVtbl -> EnableAutoRefresh(This,fEnable) ) 

#define ITDirectory_Connect(This,fSecure)	\
    ( (This)->lpVtbl -> Connect(This,fSecure) ) 

#define ITDirectory_Bind(This,pDomainName,pUserName,pPassword,lFlags)	\
    ( (This)->lpVtbl -> Bind(This,pDomainName,pUserName,pPassword,lFlags) ) 

#define ITDirectory_AddDirectoryObject(This,pDirectoryObject)	\
    ( (This)->lpVtbl -> AddDirectoryObject(This,pDirectoryObject) ) 

#define ITDirectory_ModifyDirectoryObject(This,pDirectoryObject)	\
    ( (This)->lpVtbl -> ModifyDirectoryObject(This,pDirectoryObject) ) 

#define ITDirectory_RefreshDirectoryObject(This,pDirectoryObject)	\
    ( (This)->lpVtbl -> RefreshDirectoryObject(This,pDirectoryObject) ) 

#define ITDirectory_DeleteDirectoryObject(This,pDirectoryObject)	\
    ( (This)->lpVtbl -> DeleteDirectoryObject(This,pDirectoryObject) ) 

#define ITDirectory_get_DirectoryObjects(This,DirectoryObjectType,pName,pVariant)	\
    ( (This)->lpVtbl -> get_DirectoryObjects(This,DirectoryObjectType,pName,pVariant) ) 

#define ITDirectory_EnumerateDirectoryObjects(This,DirectoryObjectType,pName,ppEnumObject)	\
    ( (This)->lpVtbl -> EnumerateDirectoryObjects(This,DirectoryObjectType,pName,ppEnumObject) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITDirectory_INTERFACE_DEFINED__ */


#ifndef __IEnumDirectory_INTERFACE_DEFINED__
#define __IEnumDirectory_INTERFACE_DEFINED__

/* interface IEnumDirectory */
/* [object][unique][restricted][hidden][helpstring][uuid] */ 


EXTERN_C const IID IID_IEnumDirectory;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("34621D6D-6CFF-11d1-AFF7-00C04FC31FEE")
    IEnumDirectory : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [annotation][in] */ 
            _In_  ULONG celt,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(celt,*pcFetched)  ITDirectory **ppElements,
            /* [full][out][in] */ __RPC__inout_opt ULONG *pcFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [annotation][in] */ 
            _In_  ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IEnumDirectory **ppEnum) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IEnumDirectoryVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IEnumDirectory * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IEnumDirectory * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IEnumDirectory * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            __RPC__in IEnumDirectory * This,
            /* [annotation][in] */ 
            _In_  ULONG celt,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(celt,*pcFetched)  ITDirectory **ppElements,
            /* [full][out][in] */ __RPC__inout_opt ULONG *pcFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            __RPC__in IEnumDirectory * This);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            __RPC__in IEnumDirectory * This,
            /* [annotation][in] */ 
            _In_  ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            __RPC__in IEnumDirectory * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IEnumDirectory **ppEnum);
        
        END_INTERFACE
    } IEnumDirectoryVtbl;

    interface IEnumDirectory
    {
        CONST_VTBL struct IEnumDirectoryVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumDirectory_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEnumDirectory_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEnumDirectory_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IEnumDirectory_Next(This,celt,ppElements,pcFetched)	\
    ( (This)->lpVtbl -> Next(This,celt,ppElements,pcFetched) ) 

#define IEnumDirectory_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define IEnumDirectory_Skip(This,celt)	\
    ( (This)->lpVtbl -> Skip(This,celt) ) 

#define IEnumDirectory_Clone(This,ppEnum)	\
    ( (This)->lpVtbl -> Clone(This,ppEnum) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IEnumDirectory_INTERFACE_DEFINED__ */


#ifndef __ITRendezvous_INTERFACE_DEFINED__
#define __ITRendezvous_INTERFACE_DEFINED__

/* interface ITRendezvous */
/* [helpstring][dual][uuid][public][object] */ 


EXTERN_C const IID IID_ITRendezvous;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("34621D6B-6CFF-11d1-AFF7-00C04FC31FEE")
    ITRendezvous : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DefaultDirectories( 
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT *pVariant) = 0;
        
        virtual /* [helpstring][restricted][hidden][id] */ HRESULT STDMETHODCALLTYPE EnumerateDefaultDirectories( 
            /* [annotation][out] */ 
            _Out_  IEnumDirectory **ppEnumDirectory) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateDirectory( 
            /* [annotation][in] */ 
            _In_  DIRECTORY_TYPE DirectoryType,
            /* [annotation][in] */ 
            _In_  BSTR pName,
            /* [annotation][retval][out] */ 
            _Out_retval_  ITDirectory **ppDir) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateDirectoryObject( 
            /* [annotation][in] */ 
            _In_  DIRECTORY_OBJECT_TYPE DirectoryObjectType,
            /* [annotation][in] */ 
            _In_  BSTR pName,
            /* [annotation][retval][out] */ 
            _Out_retval_  ITDirectoryObject **ppDirectoryObject) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITRendezvousVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ITRendezvous * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ITRendezvous * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ITRendezvous * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in ITRendezvous * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in ITRendezvous * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in ITRendezvous * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][size_is][in] */ 
            _In_reads_(cNames)  LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cNames)  DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITRendezvous * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultDirectories )( 
            __RPC__in ITRendezvous * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT *pVariant);
        
        /* [helpstring][restricted][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *EnumerateDefaultDirectories )( 
            __RPC__in ITRendezvous * This,
            /* [annotation][out] */ 
            _Out_  IEnumDirectory **ppEnumDirectory);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateDirectory )( 
            __RPC__in ITRendezvous * This,
            /* [annotation][in] */ 
            _In_  DIRECTORY_TYPE DirectoryType,
            /* [annotation][in] */ 
            _In_  BSTR pName,
            /* [annotation][retval][out] */ 
            _Out_retval_  ITDirectory **ppDir);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateDirectoryObject )( 
            __RPC__in ITRendezvous * This,
            /* [annotation][in] */ 
            _In_  DIRECTORY_OBJECT_TYPE DirectoryObjectType,
            /* [annotation][in] */ 
            _In_  BSTR pName,
            /* [annotation][retval][out] */ 
            _Out_retval_  ITDirectoryObject **ppDirectoryObject);
        
        END_INTERFACE
    } ITRendezvousVtbl;

    interface ITRendezvous
    {
        CONST_VTBL struct ITRendezvousVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITRendezvous_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITRendezvous_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITRendezvous_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITRendezvous_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ITRendezvous_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ITRendezvous_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ITRendezvous_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ITRendezvous_get_DefaultDirectories(This,pVariant)	\
    ( (This)->lpVtbl -> get_DefaultDirectories(This,pVariant) ) 

#define ITRendezvous_EnumerateDefaultDirectories(This,ppEnumDirectory)	\
    ( (This)->lpVtbl -> EnumerateDefaultDirectories(This,ppEnumDirectory) ) 

#define ITRendezvous_CreateDirectory(This,DirectoryType,pName,ppDir)	\
    ( (This)->lpVtbl -> CreateDirectory(This,DirectoryType,pName,ppDir) ) 

#define ITRendezvous_CreateDirectoryObject(This,DirectoryObjectType,pName,ppDirectoryObject)	\
    ( (This)->lpVtbl -> CreateDirectoryObject(This,DirectoryObjectType,pName,ppDirectoryObject) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITRendezvous_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_rend_0000_0009 */
/* [local] */ 



/***************************************************************/
/* Rend constants -- defined here for C apps                   */
/* The subsequent definitions that MIDL generates from the     */
/* module declaration are not used. The module declaration is  */
/* retained, however, so that the constants show up in the     */
/* type library.                                               */
/***************************************************************/

#define RENDBIND_AUTHENTICATE       0x00000001
#define RENDBIND_DEFAULTDOMAINNAME  0x00000002
#define RENDBIND_DEFAULTUSERNAME    0x00000004
#define RENDBIND_DEFAULTPASSWORD    0x00000008
/* this is just the previous three |'ed together for convenience. */
#define RENDBIND_DEFAULTCREDENTIALS 0x0000000e

#define __RendConstants_MODULE_DEFINED__

/***************************************************************/
/* end of rend constants section                               */
/***************************************************************/




extern RPC_IF_HANDLE __MIDL_itf_rend_0000_0009_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_rend_0000_0009_v0_0_s_ifspec;


#ifndef __RENDLib_LIBRARY_DEFINED__
#define __RENDLib_LIBRARY_DEFINED__

/* library RENDLib */
/* [helpstring][version][uuid] */ 








EXTERN_C const IID LIBID_RENDLib;

EXTERN_C const CLSID CLSID_Rendezvous;

#ifdef __cplusplus

class DECLSPEC_UUID("F1029E5B-CB5B-11D0-8D59-00C04FD91AC0")
Rendezvous;
#endif


#ifndef __RendConstants_MODULE_DEFINED__
#define __RendConstants_MODULE_DEFINED__


/* module RendConstants */
/* [helpstring][dllname][uuid] */ 

const long RENDBIND_AUTHENTICATE	=	0x1;

const long RENDBIND_DEFAULTDOMAINNAME	=	0x2;

const long RENDBIND_DEFAULTUSERNAME	=	0x4;

const long RENDBIND_DEFAULTPASSWORD	=	0x8;

const long RENDBIND_DEFAULTCREDENTIALS	=	0xe;

#endif /* __RendConstants_MODULE_DEFINED__ */
#endif /* __RENDLib_LIBRARY_DEFINED__ */

/* interface __MIDL_itf_rend_0000_0010 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_rend_0000_0010_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_rend_0000_0010_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     __RPC__in unsigned long *, unsigned long            , __RPC__in BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     __RPC__in unsigned long *, __RPC__in BSTR * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     __RPC__in unsigned long *, unsigned long            , __RPC__in VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree(     __RPC__in unsigned long *, __RPC__in VARIANT * ); 

unsigned long             __RPC_USER  BSTR_UserSize64(     __RPC__in unsigned long *, unsigned long            , __RPC__in BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal64(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal64(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out BSTR * ); 
void                      __RPC_USER  BSTR_UserFree64(     __RPC__in unsigned long *, __RPC__in BSTR * ); 

unsigned long             __RPC_USER  VARIANT_UserSize64(     __RPC__in unsigned long *, unsigned long            , __RPC__in VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal64(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal64(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree64(     __RPC__in unsigned long *, __RPC__in VARIANT * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


