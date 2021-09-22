

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

#ifndef __msimeapi_h__
#define __msimeapi_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IImePlugInDictDictionaryList_FWD_DEFINED__
#define __IImePlugInDictDictionaryList_FWD_DEFINED__
typedef interface IImePlugInDictDictionaryList IImePlugInDictDictionaryList;

#endif 	/* __IImePlugInDictDictionaryList_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_msimeapi_0000_0000 */
/* [local] */ 

#include <winapifamily.h>
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
#if (NTDDI_VERSION >= NTDDI_WIN8)


extern RPC_IF_HANDLE __MIDL_itf_msimeapi_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_msimeapi_0000_0000_v0_0_s_ifspec;

#ifndef __IImePlugInDictDictionaryList_INTERFACE_DEFINED__
#define __IImePlugInDictDictionaryList_INTERFACE_DEFINED__

/* interface IImePlugInDictDictionaryList */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IImePlugInDictDictionaryList;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("98752974-b0a6-489b-8f6f-bff3769c8eeb")
    IImePlugInDictDictionaryList : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetDictionariesInUse( 
            /* [annotation][out] */ 
            _Out_  SAFEARRAY * *prgDictionaryGUID,
            /* [annotation][out][in] */ 
            _Inout_  SAFEARRAY * *prgDateCreated,
            /* [annotation][out][in] */ 
            _Inout_  SAFEARRAY * *prgfEncrypted) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DeleteDictionary( 
            /* [annotation][in] */ 
            _In_  BSTR bstrDictionaryGUID) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IImePlugInDictDictionaryListVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IImePlugInDictDictionaryList * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IImePlugInDictDictionaryList * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IImePlugInDictDictionaryList * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetDictionariesInUse )( 
            __RPC__in IImePlugInDictDictionaryList * This,
            /* [annotation][out] */ 
            _Out_  SAFEARRAY * *prgDictionaryGUID,
            /* [annotation][out][in] */ 
            _Inout_  SAFEARRAY * *prgDateCreated,
            /* [annotation][out][in] */ 
            _Inout_  SAFEARRAY * *prgfEncrypted);
        
        HRESULT ( STDMETHODCALLTYPE *DeleteDictionary )( 
            __RPC__in IImePlugInDictDictionaryList * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrDictionaryGUID);
        
        END_INTERFACE
    } IImePlugInDictDictionaryListVtbl;

    interface IImePlugInDictDictionaryList
    {
        CONST_VTBL struct IImePlugInDictDictionaryListVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IImePlugInDictDictionaryList_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IImePlugInDictDictionaryList_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IImePlugInDictDictionaryList_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IImePlugInDictDictionaryList_GetDictionariesInUse(This,prgDictionaryGUID,prgDateCreated,prgfEncrypted)	\
    ( (This)->lpVtbl -> GetDictionariesInUse(This,prgDictionaryGUID,prgDateCreated,prgfEncrypted) ) 

#define IImePlugInDictDictionaryList_DeleteDictionary(This,bstrDictionaryGUID)	\
    ( (This)->lpVtbl -> DeleteDictionary(This,bstrDictionaryGUID) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IImePlugInDictDictionaryList_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_msimeapi_0000_0001 */
/* [local] */ 

// {7BF0129B-5BEF-4DE4-9B0B-5EDB66AC2FA6}
DEFINE_GUID(CLSID_ImePlugInDictDictionaryList_CHS,
0x7bf0129b, 0x5bef, 0x4de4, 0x9b, 0x0b, 0x5e, 0xdb, 0x66, 0xac, 0x2f, 0xa6);
#define VIPROGID_ImePlugInDictDictionaryList_CHS OLESTR("ImePlugInDictDictionaryList2052")
#define VDPROGID_ImePlugInDictDictionaryList_CHS OLESTR("ImePlugInDictDictionaryList2052.15")
// {4FE2776B-B0F9-4396-B5FC-E9D4CF1EC195}
DEFINE_GUID(CLSID_ImePlugInDictDictionaryList_JPN,
0x4fe2776b, 0xb0f9, 0x4396, 0xb5, 0xfc, 0xe9, 0xd4, 0xcf, 0x1e, 0xc1, 0x95);
#define VIPROGID_ImePlugInDictDictionaryList_JPN OLESTR("ImePlugInDictDictionaryList1041")
#define VDPROGID_ImePlugInDictDictionaryList_JPN OLESTR("ImePlugInDictDictionaryList1041.15")
#endif // (NTDDI >= NTDDI_WIN8)
#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_msimeapi_0000_0001_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_msimeapi_0000_0001_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     __RPC__in unsigned long *, unsigned long            , __RPC__in BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     __RPC__in unsigned long *, __RPC__in BSTR * ); 

unsigned long             __RPC_USER  LPSAFEARRAY_UserSize(     __RPC__in unsigned long *, unsigned long            , __RPC__in LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserMarshal(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserUnmarshal(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out LPSAFEARRAY * ); 
void                      __RPC_USER  LPSAFEARRAY_UserFree(     __RPC__in unsigned long *, __RPC__in LPSAFEARRAY * ); 

unsigned long             __RPC_USER  BSTR_UserSize64(     __RPC__in unsigned long *, unsigned long            , __RPC__in BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal64(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal64(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out BSTR * ); 
void                      __RPC_USER  BSTR_UserFree64(     __RPC__in unsigned long *, __RPC__in BSTR * ); 

unsigned long             __RPC_USER  LPSAFEARRAY_UserSize64(     __RPC__in unsigned long *, unsigned long            , __RPC__in LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserMarshal64(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserUnmarshal64(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out LPSAFEARRAY * ); 
void                      __RPC_USER  LPSAFEARRAY_UserFree64(     __RPC__in unsigned long *, __RPC__in LPSAFEARRAY * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


