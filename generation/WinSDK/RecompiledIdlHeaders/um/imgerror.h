

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

#ifndef __imgerror_h__
#define __imgerror_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IImgErrorInfo_FWD_DEFINED__
#define __IImgErrorInfo_FWD_DEFINED__
typedef interface IImgErrorInfo IImgErrorInfo;

#endif 	/* __IImgErrorInfo_FWD_DEFINED__ */


#ifndef __IImgCreateErrorInfo_FWD_DEFINED__
#define __IImgCreateErrorInfo_FWD_DEFINED__
typedef interface IImgCreateErrorInfo IImgCreateErrorInfo;

#endif 	/* __IImgCreateErrorInfo_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_imgerror_0000_0000 */
/* [local] */ 

//+-------------------------------------------------------------------------
//
//  Microsoft Windows
//  Copyright (c) Microsoft Corporation. All rights reserved.
//
//--------------------------------------------------------------------------
#include <winapifamily.h>
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)


typedef /* [public][public][public] */ struct __MIDL___MIDL_itf_imgerror_0000_0000_0001
    {
    BSTR description;
    GUID guid;
    DWORD helpContext;
    BSTR helpFile;
    BSTR source;
    BSTR devDescription;
    GUID errorID;
    ULONG cUserParameters;
    /* [size_is] */ BSTR *aUserParameters;
    BSTR userFallback;
    DWORD exceptionID;
    } 	ImgErrorInfo;



extern RPC_IF_HANDLE __MIDL_itf_imgerror_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_imgerror_0000_0000_v0_0_s_ifspec;

#ifndef __IImgErrorInfo_INTERFACE_DEFINED__
#define __IImgErrorInfo_INTERFACE_DEFINED__

/* interface IImgErrorInfo */
/* [ref][helpstring][local][uuid][object] */ 


EXTERN_C const IID IID_IImgErrorInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2bce4ece-d30e-445a-9423-6829be945ad8")
    IImgErrorInfo : public IErrorInfo
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetDeveloperDescription( 
            /* [annotation][out] */ 
            _Out_  BSTR *pbstrDevDescription) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetUserErrorId( 
            /* [annotation][out] */ 
            _Out_  GUID *pErrorId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetUserParameterCount( 
            /* [annotation][out] */ 
            _Out_  ULONG *pcUserParams) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetUserParameter( 
            /* [annotation][in] */ 
            _In_  ULONG cParam,
            /* [annotation][out] */ 
            _Out_  BSTR *pbstrParam) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetUserFallback( 
            /* [annotation][out] */ 
            _Out_  BSTR *pbstrFallback) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetExceptionId( 
            /* [annotation][out] */ 
            _Out_  DWORD *pExceptionId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DetachErrorInfo( 
            /* [annotation][out] */ 
            _Out_  ImgErrorInfo *pErrorInfo) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IImgErrorInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IImgErrorInfo * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IImgErrorInfo * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IImgErrorInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetGUID )( 
            IImgErrorInfo * This,
            /* [annotation][out] */ 
            _Out_  GUID *pGUID);
        
        HRESULT ( STDMETHODCALLTYPE *GetSource )( 
            IImgErrorInfo * This,
            /* [annotation][out] */ 
            _Out_  BSTR *pBstrSource);
        
        HRESULT ( STDMETHODCALLTYPE *GetDescription )( 
            IImgErrorInfo * This,
            /* [annotation][out] */ 
            _Out_  BSTR *pBstrDescription);
        
        HRESULT ( STDMETHODCALLTYPE *GetHelpFile )( 
            IImgErrorInfo * This,
            /* [annotation][out] */ 
            _Out_  BSTR *pBstrHelpFile);
        
        HRESULT ( STDMETHODCALLTYPE *GetHelpContext )( 
            IImgErrorInfo * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwHelpContext);
        
        HRESULT ( STDMETHODCALLTYPE *GetDeveloperDescription )( 
            IImgErrorInfo * This,
            /* [annotation][out] */ 
            _Out_  BSTR *pbstrDevDescription);
        
        HRESULT ( STDMETHODCALLTYPE *GetUserErrorId )( 
            IImgErrorInfo * This,
            /* [annotation][out] */ 
            _Out_  GUID *pErrorId);
        
        HRESULT ( STDMETHODCALLTYPE *GetUserParameterCount )( 
            IImgErrorInfo * This,
            /* [annotation][out] */ 
            _Out_  ULONG *pcUserParams);
        
        HRESULT ( STDMETHODCALLTYPE *GetUserParameter )( 
            IImgErrorInfo * This,
            /* [annotation][in] */ 
            _In_  ULONG cParam,
            /* [annotation][out] */ 
            _Out_  BSTR *pbstrParam);
        
        HRESULT ( STDMETHODCALLTYPE *GetUserFallback )( 
            IImgErrorInfo * This,
            /* [annotation][out] */ 
            _Out_  BSTR *pbstrFallback);
        
        HRESULT ( STDMETHODCALLTYPE *GetExceptionId )( 
            IImgErrorInfo * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pExceptionId);
        
        HRESULT ( STDMETHODCALLTYPE *DetachErrorInfo )( 
            IImgErrorInfo * This,
            /* [annotation][out] */ 
            _Out_  ImgErrorInfo *pErrorInfo);
        
        END_INTERFACE
    } IImgErrorInfoVtbl;

    interface IImgErrorInfo
    {
        CONST_VTBL struct IImgErrorInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IImgErrorInfo_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IImgErrorInfo_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IImgErrorInfo_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IImgErrorInfo_GetGUID(This,pGUID)	\
    ( (This)->lpVtbl -> GetGUID(This,pGUID) ) 

#define IImgErrorInfo_GetSource(This,pBstrSource)	\
    ( (This)->lpVtbl -> GetSource(This,pBstrSource) ) 

#define IImgErrorInfo_GetDescription(This,pBstrDescription)	\
    ( (This)->lpVtbl -> GetDescription(This,pBstrDescription) ) 

#define IImgErrorInfo_GetHelpFile(This,pBstrHelpFile)	\
    ( (This)->lpVtbl -> GetHelpFile(This,pBstrHelpFile) ) 

#define IImgErrorInfo_GetHelpContext(This,pdwHelpContext)	\
    ( (This)->lpVtbl -> GetHelpContext(This,pdwHelpContext) ) 


#define IImgErrorInfo_GetDeveloperDescription(This,pbstrDevDescription)	\
    ( (This)->lpVtbl -> GetDeveloperDescription(This,pbstrDevDescription) ) 

#define IImgErrorInfo_GetUserErrorId(This,pErrorId)	\
    ( (This)->lpVtbl -> GetUserErrorId(This,pErrorId) ) 

#define IImgErrorInfo_GetUserParameterCount(This,pcUserParams)	\
    ( (This)->lpVtbl -> GetUserParameterCount(This,pcUserParams) ) 

#define IImgErrorInfo_GetUserParameter(This,cParam,pbstrParam)	\
    ( (This)->lpVtbl -> GetUserParameter(This,cParam,pbstrParam) ) 

#define IImgErrorInfo_GetUserFallback(This,pbstrFallback)	\
    ( (This)->lpVtbl -> GetUserFallback(This,pbstrFallback) ) 

#define IImgErrorInfo_GetExceptionId(This,pExceptionId)	\
    ( (This)->lpVtbl -> GetExceptionId(This,pExceptionId) ) 

#define IImgErrorInfo_DetachErrorInfo(This,pErrorInfo)	\
    ( (This)->lpVtbl -> DetachErrorInfo(This,pErrorInfo) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IImgErrorInfo_INTERFACE_DEFINED__ */


#ifndef __IImgCreateErrorInfo_INTERFACE_DEFINED__
#define __IImgCreateErrorInfo_INTERFACE_DEFINED__

/* interface IImgCreateErrorInfo */
/* [ref][helpstring][local][uuid][object] */ 


EXTERN_C const IID IID_IImgCreateErrorInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1c55a64c-07cd-4fb5-90f7-b753d91f0c9e")
    IImgCreateErrorInfo : public ICreateErrorInfo
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AttachToErrorInfo( 
            /* [annotation][out][in] */ 
            _Inout_  ImgErrorInfo *pErrorInfo) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IImgCreateErrorInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IImgCreateErrorInfo * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IImgCreateErrorInfo * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IImgCreateErrorInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetGUID )( 
            IImgCreateErrorInfo * This,
            /* [annotation][in] */ 
            _In_  REFGUID rguid);
        
        HRESULT ( STDMETHODCALLTYPE *SetSource )( 
            IImgCreateErrorInfo * This,
            /* [annotation][in] */ 
            _In_  LPOLESTR szSource);
        
        HRESULT ( STDMETHODCALLTYPE *SetDescription )( 
            IImgCreateErrorInfo * This,
            /* [annotation][in] */ 
            _In_  LPOLESTR szDescription);
        
        HRESULT ( STDMETHODCALLTYPE *SetHelpFile )( 
            IImgCreateErrorInfo * This,
            /* [annotation][in] */ 
            _In_  LPOLESTR szHelpFile);
        
        HRESULT ( STDMETHODCALLTYPE *SetHelpContext )( 
            IImgCreateErrorInfo * This,
            /* [annotation][in] */ 
            _In_  DWORD dwHelpContext);
        
        HRESULT ( STDMETHODCALLTYPE *AttachToErrorInfo )( 
            IImgCreateErrorInfo * This,
            /* [annotation][out][in] */ 
            _Inout_  ImgErrorInfo *pErrorInfo);
        
        END_INTERFACE
    } IImgCreateErrorInfoVtbl;

    interface IImgCreateErrorInfo
    {
        CONST_VTBL struct IImgCreateErrorInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IImgCreateErrorInfo_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IImgCreateErrorInfo_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IImgCreateErrorInfo_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IImgCreateErrorInfo_SetGUID(This,rguid)	\
    ( (This)->lpVtbl -> SetGUID(This,rguid) ) 

#define IImgCreateErrorInfo_SetSource(This,szSource)	\
    ( (This)->lpVtbl -> SetSource(This,szSource) ) 

#define IImgCreateErrorInfo_SetDescription(This,szDescription)	\
    ( (This)->lpVtbl -> SetDescription(This,szDescription) ) 

#define IImgCreateErrorInfo_SetHelpFile(This,szHelpFile)	\
    ( (This)->lpVtbl -> SetHelpFile(This,szHelpFile) ) 

#define IImgCreateErrorInfo_SetHelpContext(This,dwHelpContext)	\
    ( (This)->lpVtbl -> SetHelpContext(This,dwHelpContext) ) 


#define IImgCreateErrorInfo_AttachToErrorInfo(This,pErrorInfo)	\
    ( (This)->lpVtbl -> AttachToErrorInfo(This,pErrorInfo) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IImgCreateErrorInfo_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_imgerror_0000_0002 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_imgerror_0000_0002_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_imgerror_0000_0002_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


