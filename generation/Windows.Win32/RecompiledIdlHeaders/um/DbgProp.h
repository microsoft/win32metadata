

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

#ifndef __dbgprop_h__
#define __dbgprop_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IDebugProperty_FWD_DEFINED__
#define __IDebugProperty_FWD_DEFINED__
typedef interface IDebugProperty IDebugProperty;

#endif 	/* __IDebugProperty_FWD_DEFINED__ */


#ifndef __IEnumDebugPropertyInfo_FWD_DEFINED__
#define __IEnumDebugPropertyInfo_FWD_DEFINED__
typedef interface IEnumDebugPropertyInfo IEnumDebugPropertyInfo;

#endif 	/* __IEnumDebugPropertyInfo_FWD_DEFINED__ */


#ifndef __IDebugExtendedProperty_FWD_DEFINED__
#define __IDebugExtendedProperty_FWD_DEFINED__
typedef interface IDebugExtendedProperty IDebugExtendedProperty;

#endif 	/* __IDebugExtendedProperty_FWD_DEFINED__ */


#ifndef __IEnumDebugExtendedPropertyInfo_FWD_DEFINED__
#define __IEnumDebugExtendedPropertyInfo_FWD_DEFINED__
typedef interface IEnumDebugExtendedPropertyInfo IEnumDebugExtendedPropertyInfo;

#endif 	/* __IEnumDebugExtendedPropertyInfo_FWD_DEFINED__ */


#ifndef __IPerPropertyBrowsing2_FWD_DEFINED__
#define __IPerPropertyBrowsing2_FWD_DEFINED__
typedef interface IPerPropertyBrowsing2 IPerPropertyBrowsing2;

#endif 	/* __IPerPropertyBrowsing2_FWD_DEFINED__ */


#ifndef __IDebugPropertyEnumType_All_FWD_DEFINED__
#define __IDebugPropertyEnumType_All_FWD_DEFINED__
typedef interface IDebugPropertyEnumType_All IDebugPropertyEnumType_All;

#endif 	/* __IDebugPropertyEnumType_All_FWD_DEFINED__ */


#ifndef __IDebugPropertyEnumType_Locals_FWD_DEFINED__
#define __IDebugPropertyEnumType_Locals_FWD_DEFINED__
typedef interface IDebugPropertyEnumType_Locals IDebugPropertyEnumType_Locals;

#endif 	/* __IDebugPropertyEnumType_Locals_FWD_DEFINED__ */


#ifndef __IDebugPropertyEnumType_Arguments_FWD_DEFINED__
#define __IDebugPropertyEnumType_Arguments_FWD_DEFINED__
typedef interface IDebugPropertyEnumType_Arguments IDebugPropertyEnumType_Arguments;

#endif 	/* __IDebugPropertyEnumType_Arguments_FWD_DEFINED__ */


#ifndef __IDebugPropertyEnumType_LocalsPlusArgs_FWD_DEFINED__
#define __IDebugPropertyEnumType_LocalsPlusArgs_FWD_DEFINED__
typedef interface IDebugPropertyEnumType_LocalsPlusArgs IDebugPropertyEnumType_LocalsPlusArgs;

#endif 	/* __IDebugPropertyEnumType_LocalsPlusArgs_FWD_DEFINED__ */


#ifndef __IDebugPropertyEnumType_Registers_FWD_DEFINED__
#define __IDebugPropertyEnumType_Registers_FWD_DEFINED__
typedef interface IDebugPropertyEnumType_Registers IDebugPropertyEnumType_Registers;

#endif 	/* __IDebugPropertyEnumType_Registers_FWD_DEFINED__ */


/* header files for imported files */
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_dbgprop_0000_0000 */
/* [local] */ 

#include <winapifamily.h>
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)





// GUIDs for IDebugProperty::GetExtendedInfo
extern GUID guidDocument;
extern GUID guidCodeContext;

enum __MIDL___MIDL_itf_dbgprop_0000_0000_0001
    {
        DBGPROP_ATTRIB_NO_ATTRIB	= 0,
        DBGPROP_ATTRIB_VALUE_IS_INVALID	= 0x8,
        DBGPROP_ATTRIB_VALUE_IS_EXPANDABLE	= 0x10,
        DBGPROP_ATTRIB_VALUE_IS_FAKE	= 0x20,
        DBGPROP_ATTRIB_VALUE_IS_METHOD	= 0x100,
        DBGPROP_ATTRIB_VALUE_IS_EVENT	= 0x200,
        DBGPROP_ATTRIB_VALUE_IS_RAW_STRING	= 0x400,
        DBGPROP_ATTRIB_VALUE_READONLY	= 0x800,
        DBGPROP_ATTRIB_ACCESS_PUBLIC	= 0x1000,
        DBGPROP_ATTRIB_ACCESS_PRIVATE	= 0x2000,
        DBGPROP_ATTRIB_ACCESS_PROTECTED	= 0x4000,
        DBGPROP_ATTRIB_ACCESS_FINAL	= 0x8000,
        DBGPROP_ATTRIB_STORAGE_GLOBAL	= 0x10000,
        DBGPROP_ATTRIB_STORAGE_STATIC	= 0x20000,
        DBGPROP_ATTRIB_STORAGE_FIELD	= 0x40000,
        DBGPROP_ATTRIB_STORAGE_VIRTUAL	= 0x80000,
        DBGPROP_ATTRIB_TYPE_IS_CONSTANT	= 0x100000,
        DBGPROP_ATTRIB_TYPE_IS_SYNCHRONIZED	= 0x200000,
        DBGPROP_ATTRIB_TYPE_IS_VOLATILE	= 0x400000,
        DBGPROP_ATTRIB_HAS_EXTENDED_ATTRIBS	= 0x800000,
        DBGPROP_ATTRIB_FRAME_INTRYBLOCK	= 0x1000000,
        DBGPROP_ATTRIB_FRAME_INCATCHBLOCK	= 0x2000000,
        DBGPROP_ATTRIB_FRAME_INFINALLYBLOCK	= 0x4000000,
        DBGPROP_ATTRIB_VALUE_IS_RETURN_VALUE	= 0x8000000,
        DBGPROP_ATTRIB_VALUE_PENDING_MUTATION	= 0x10000000
    } ;
typedef DWORD DBGPROP_ATTRIB_FLAGS;


enum __MIDL___MIDL_itf_dbgprop_0000_0000_0002
    {
        DBGPROP_INFO_NAME	= 0x1,
        DBGPROP_INFO_TYPE	= 0x2,
        DBGPROP_INFO_VALUE	= 0x4,
        DBGPROP_INFO_FULLNAME	= 0x20,
        DBGPROP_INFO_ATTRIBUTES	= 0x8,
        DBGPROP_INFO_DEBUGPROP	= 0x10,
        DBGPROP_INFO_BEAUTIFY	= 0x2000000,
        DBGPROP_INFO_CALLTOSTRING	= 0x4000000,
        DBGPROP_INFO_AUTOEXPAND	= 0x8000000
    } ;
typedef DWORD DBGPROP_INFO_FLAGS;

#define	DBGPROP_INFO_STANDARD	( ( ( ( DBGPROP_INFO_NAME | DBGPROP_INFO_TYPE )  | DBGPROP_INFO_VALUE )  | DBGPROP_INFO_ATTRIBUTES )  )

#define	DBGPROP_INFO_ALL	( ( ( ( ( ( DBGPROP_INFO_NAME | DBGPROP_INFO_TYPE )  | DBGPROP_INFO_VALUE )  | DBGPROP_INFO_FULLNAME )  | DBGPROP_INFO_ATTRIBUTES )  | DBGPROP_INFO_DEBUGPROP )  )

// DO NOT USE OBJECT_ATTRIB_FLAGS or PROP_INFO_FLAGS, USE DBGPROP_ATTRIB_FLAGS and DBGPROP_INFO_FLAGS instead
typedef 
enum tagOBJECT_ATTRIB_FLAG
    {
        OBJECT_ATTRIB_NO_ATTRIB	= 0,
        OBJECT_ATTRIB_NO_NAME	= 0x1,
        OBJECT_ATTRIB_NO_TYPE	= 0x2,
        OBJECT_ATTRIB_NO_VALUE	= 0x4,
        OBJECT_ATTRIB_VALUE_IS_INVALID	= 0x8,
        OBJECT_ATTRIB_VALUE_IS_OBJECT	= 0x10,
        OBJECT_ATTRIB_VALUE_IS_ENUM	= 0x20,
        OBJECT_ATTRIB_VALUE_IS_CUSTOM	= 0x40,
        OBJECT_ATTRIB_OBJECT_IS_EXPANDABLE	= 0x70,
        OBJECT_ATTRIB_VALUE_HAS_CODE	= 0x80,
        OBJECT_ATTRIB_TYPE_IS_OBJECT	= 0x100,
        OBJECT_ATTRIB_TYPE_HAS_CODE	= 0x200,
        OBJECT_ATTRIB_TYPE_IS_EXPANDABLE	= 0x100,
        OBJECT_ATTRIB_SLOT_IS_CATEGORY	= 0x400,
        OBJECT_ATTRIB_VALUE_READONLY	= 0x800,
        OBJECT_ATTRIB_ACCESS_PUBLIC	= 0x1000,
        OBJECT_ATTRIB_ACCESS_PRIVATE	= 0x2000,
        OBJECT_ATTRIB_ACCESS_PROTECTED	= 0x4000,
        OBJECT_ATTRIB_ACCESS_FINAL	= 0x8000,
        OBJECT_ATTRIB_STORAGE_GLOBAL	= 0x10000,
        OBJECT_ATTRIB_STORAGE_STATIC	= 0x20000,
        OBJECT_ATTRIB_STORAGE_FIELD	= 0x40000,
        OBJECT_ATTRIB_STORAGE_VIRTUAL	= 0x80000,
        OBJECT_ATTRIB_TYPE_IS_CONSTANT	= 0x100000,
        OBJECT_ATTRIB_TYPE_IS_SYNCHRONIZED	= 0x200000,
        OBJECT_ATTRIB_TYPE_IS_VOLATILE	= 0x400000,
        OBJECT_ATTRIB_HAS_EXTENDED_ATTRIBS	= 0x800000,
        OBJECT_ATTRIB_IS_CLASS	= 0x1000000,
        OBJECT_ATTRIB_IS_FUNCTION	= 0x2000000,
        OBJECT_ATTRIB_IS_VARIABLE	= 0x4000000,
        OBJECT_ATTRIB_IS_PROPERTY	= 0x8000000,
        OBJECT_ATTRIB_IS_MACRO	= 0x10000000,
        OBJECT_ATTRIB_IS_TYPE	= 0x20000000,
        OBJECT_ATTRIB_IS_INHERITED	= 0x40000000,
        OBJECT_ATTRIB_IS_INTERFACE	= 0x80000000
    } 	OBJECT_ATTRIB_FLAGS;

typedef 
enum tagPROP_INFO_FLAGS
    {
        PROP_INFO_NAME	= 0x1,
        PROP_INFO_TYPE	= 0x2,
        PROP_INFO_VALUE	= 0x4,
        PROP_INFO_FULLNAME	= 0x20,
        PROP_INFO_ATTRIBUTES	= 0x8,
        PROP_INFO_DEBUGPROP	= 0x10,
        PROP_INFO_AUTOEXPAND	= 0x8000000
    } 	PROP_INFO_FLAGS;

#define	PROP_INFO_STANDARD	( ( ( ( PROP_INFO_NAME | PROP_INFO_TYPE )  | PROP_INFO_VALUE )  | PROP_INFO_ATTRIBUTES )  )

#define	PROP_INFO_ALL	( ( ( ( ( ( PROP_INFO_NAME | PROP_INFO_TYPE )  | PROP_INFO_VALUE )  | PROP_INFO_FULLNAME )  | PROP_INFO_ATTRIBUTES )  | PROP_INFO_DEBUGPROP )  )

typedef struct tagDebugPropertyInfo
    {
    DWORD m_dwValidFields;
    BSTR m_bstrName;
    BSTR m_bstrType;
    BSTR m_bstrValue;
    BSTR m_bstrFullName;
    DWORD m_dwAttrib;
    IDebugProperty *m_pDebugProp;
    } 	DebugPropertyInfo;

typedef 
enum tagEX_PROP_INFO_FLAGS
    {
        EX_PROP_INFO_ID	= 0x100,
        EX_PROP_INFO_NTYPE	= 0x200,
        EX_PROP_INFO_NVALUE	= 0x400,
        EX_PROP_INFO_LOCKBYTES	= 0x800,
        EX_PROP_INFO_DEBUGEXTPROP	= 0x1000
    } 	EX_PROP_INFO_FLAGS;

typedef struct tagExtendedDebugPropertyInfo
    {
    DWORD dwValidFields;
    LPOLESTR pszName;
    LPOLESTR pszType;
    LPOLESTR pszValue;
    LPOLESTR pszFullName;
    DWORD dwAttrib;
    IDebugProperty *pDebugProp;
    DWORD nDISPID;
    DWORD nType;
    VARIANT varValue;
    ILockBytes *plbValue;
    IDebugExtendedProperty *pDebugExtProp;
    } 	ExtendedDebugPropertyInfo;



extern RPC_IF_HANDLE __MIDL_itf_dbgprop_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_dbgprop_0000_0000_v0_0_s_ifspec;

#ifndef __IDebugProperty_INTERFACE_DEFINED__
#define __IDebugProperty_INTERFACE_DEFINED__

/* interface IDebugProperty */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IDebugProperty;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("51973C50-CB0C-11d0-B5C9-00A0244A0E7A")
    IDebugProperty : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE GetPropertyInfo( 
            /* [annotation][in] */ 
            _In_  DWORD dwFieldSpec,
            /* [annotation][in] */ 
            _In_  UINT nRadix,
            /* [annotation][out] */ 
            _Out_  DebugPropertyInfo *pPropertyInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetExtendedInfo( 
            /* [annotation][in] */ 
            _In_  ULONG cInfos,
            /* [annotation][size_is][in] */ 
            _In_reads_(cInfos)  GUID *rgguidExtendedInfo,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cInfos)  VARIANT *rgvar) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetValueAsString( 
            /* [annotation][in] */ 
            _In_  LPCOLESTR pszValue,
            /* [annotation][in] */ 
            _In_  UINT nRadix) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumMembers( 
            /* [annotation][in] */ 
            _In_  DWORD dwFieldSpec,
            /* [annotation][in] */ 
            _In_  UINT nRadix,
            /* [annotation][in] */ 
            _In_  REFIID refiid,
            /* [annotation][out] */ 
            _Out_  IEnumDebugPropertyInfo **ppepi) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetParent( 
            /* [annotation][out] */ 
            _Out_  IDebugProperty **ppDebugProp) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IDebugPropertyVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IDebugProperty * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IDebugProperty * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IDebugProperty * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *GetPropertyInfo )( 
            IDebugProperty * This,
            /* [annotation][in] */ 
            _In_  DWORD dwFieldSpec,
            /* [annotation][in] */ 
            _In_  UINT nRadix,
            /* [annotation][out] */ 
            _Out_  DebugPropertyInfo *pPropertyInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetExtendedInfo )( 
            __RPC__in IDebugProperty * This,
            /* [annotation][in] */ 
            _In_  ULONG cInfos,
            /* [annotation][size_is][in] */ 
            _In_reads_(cInfos)  GUID *rgguidExtendedInfo,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cInfos)  VARIANT *rgvar);
        
        HRESULT ( STDMETHODCALLTYPE *SetValueAsString )( 
            __RPC__in IDebugProperty * This,
            /* [annotation][in] */ 
            _In_  LPCOLESTR pszValue,
            /* [annotation][in] */ 
            _In_  UINT nRadix);
        
        HRESULT ( STDMETHODCALLTYPE *EnumMembers )( 
            __RPC__in IDebugProperty * This,
            /* [annotation][in] */ 
            _In_  DWORD dwFieldSpec,
            /* [annotation][in] */ 
            _In_  UINT nRadix,
            /* [annotation][in] */ 
            _In_  REFIID refiid,
            /* [annotation][out] */ 
            _Out_  IEnumDebugPropertyInfo **ppepi);
        
        HRESULT ( STDMETHODCALLTYPE *GetParent )( 
            __RPC__in IDebugProperty * This,
            /* [annotation][out] */ 
            _Out_  IDebugProperty **ppDebugProp);
        
        END_INTERFACE
    } IDebugPropertyVtbl;

    interface IDebugProperty
    {
        CONST_VTBL struct IDebugPropertyVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDebugProperty_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDebugProperty_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDebugProperty_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDebugProperty_GetPropertyInfo(This,dwFieldSpec,nRadix,pPropertyInfo)	\
    ( (This)->lpVtbl -> GetPropertyInfo(This,dwFieldSpec,nRadix,pPropertyInfo) ) 

#define IDebugProperty_GetExtendedInfo(This,cInfos,rgguidExtendedInfo,rgvar)	\
    ( (This)->lpVtbl -> GetExtendedInfo(This,cInfos,rgguidExtendedInfo,rgvar) ) 

#define IDebugProperty_SetValueAsString(This,pszValue,nRadix)	\
    ( (This)->lpVtbl -> SetValueAsString(This,pszValue,nRadix) ) 

#define IDebugProperty_EnumMembers(This,dwFieldSpec,nRadix,refiid,ppepi)	\
    ( (This)->lpVtbl -> EnumMembers(This,dwFieldSpec,nRadix,refiid,ppepi) ) 

#define IDebugProperty_GetParent(This,ppDebugProp)	\
    ( (This)->lpVtbl -> GetParent(This,ppDebugProp) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT STDMETHODCALLTYPE IDebugProperty_RemoteGetPropertyInfo_Proxy( 
    __RPC__in IDebugProperty * This,
    /* [annotation][in] */ 
    _In_  DWORD dwFieldSpec,
    /* [annotation][in] */ 
    _In_  UINT nRadix,
    /* [annotation][out] */ 
    _Out_  DWORD *dwValidFields,
    /* [annotation][out] */ 
    _Out_  BSTR *pbstrName,
    /* [annotation][out] */ 
    _Out_  BSTR *pbstrType,
    /* [annotation][out] */ 
    _Out_  BSTR *pbstrValue,
    /* [annotation][out] */ 
    _Out_  BSTR *pbstrFullName,
    /* [annotation][out] */ 
    _Out_  DWORD *pdwAttrib,
    /* [annotation][unique][out][in] */ 
    _Inout_  IDebugProperty **ppDebugProperty);


void __RPC_STUB IDebugProperty_RemoteGetPropertyInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDebugProperty_INTERFACE_DEFINED__ */


#ifndef __IEnumDebugPropertyInfo_INTERFACE_DEFINED__
#define __IEnumDebugPropertyInfo_INTERFACE_DEFINED__

/* interface IEnumDebugPropertyInfo */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IEnumDebugPropertyInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("51973C51-CB0C-11d0-B5C9-00A0244A0E7A")
    IEnumDebugPropertyInfo : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE Next( 
            /* [annotation][in] */ 
            _In_  ULONG celt,
            /* [annotation][out] */ 
            _Out_  DebugPropertyInfo *pi,
            /* [annotation][out] */ 
            _Out_  ULONG *pcEltsfetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [annotation][in] */ 
            _In_  ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [annotation][out] */ 
            _Out_  IEnumDebugPropertyInfo **ppepi) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCount( 
            /* [annotation][out] */ 
            _Out_  ULONG *pcelt) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IEnumDebugPropertyInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IEnumDebugPropertyInfo * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IEnumDebugPropertyInfo * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IEnumDebugPropertyInfo * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Next )( 
            IEnumDebugPropertyInfo * This,
            /* [annotation][in] */ 
            _In_  ULONG celt,
            /* [annotation][out] */ 
            _Out_  DebugPropertyInfo *pi,
            /* [annotation][out] */ 
            _Out_  ULONG *pcEltsfetched);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            __RPC__in IEnumDebugPropertyInfo * This,
            /* [annotation][in] */ 
            _In_  ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            __RPC__in IEnumDebugPropertyInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            __RPC__in IEnumDebugPropertyInfo * This,
            /* [annotation][out] */ 
            _Out_  IEnumDebugPropertyInfo **ppepi);
        
        HRESULT ( STDMETHODCALLTYPE *GetCount )( 
            __RPC__in IEnumDebugPropertyInfo * This,
            /* [annotation][out] */ 
            _Out_  ULONG *pcelt);
        
        END_INTERFACE
    } IEnumDebugPropertyInfoVtbl;

    interface IEnumDebugPropertyInfo
    {
        CONST_VTBL struct IEnumDebugPropertyInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumDebugPropertyInfo_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEnumDebugPropertyInfo_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEnumDebugPropertyInfo_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IEnumDebugPropertyInfo_Next(This,celt,pi,pcEltsfetched)	\
    ( (This)->lpVtbl -> Next(This,celt,pi,pcEltsfetched) ) 

#define IEnumDebugPropertyInfo_Skip(This,celt)	\
    ( (This)->lpVtbl -> Skip(This,celt) ) 

#define IEnumDebugPropertyInfo_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define IEnumDebugPropertyInfo_Clone(This,ppepi)	\
    ( (This)->lpVtbl -> Clone(This,ppepi) ) 

#define IEnumDebugPropertyInfo_GetCount(This,pcelt)	\
    ( (This)->lpVtbl -> GetCount(This,pcelt) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT __stdcall IEnumDebugPropertyInfo_RemoteNext_Proxy( 
    __RPC__in IEnumDebugPropertyInfo * This,
    /* [annotation][in] */ 
    _In_  ULONG celt,
    /* [annotation][length_is][size_is][unique][out][in] */ 
    _Inout_updates_to_(celt,*pcEltsfetched)  DebugPropertyInfo *pinfo,
    /* [annotation][out] */ 
    _Out_  ULONG *pcEltsfetched);


void __RPC_STUB IEnumDebugPropertyInfo_RemoteNext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEnumDebugPropertyInfo_INTERFACE_DEFINED__ */


#ifndef __IDebugExtendedProperty_INTERFACE_DEFINED__
#define __IDebugExtendedProperty_INTERFACE_DEFINED__

/* interface IDebugExtendedProperty */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IDebugExtendedProperty;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("51973C52-CB0C-11d0-B5C9-00A0244A0E7A")
    IDebugExtendedProperty : public IDebugProperty
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetExtendedPropertyInfo( 
            /* [annotation][in] */ 
            _In_  DWORD dwFieldSpec,
            /* [annotation][in] */ 
            _In_  UINT nRadix,
            /* [annotation][out] */ 
            _Out_  ExtendedDebugPropertyInfo *pExtendedPropertyInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumExtendedMembers( 
            /* [annotation][in] */ 
            _In_  DWORD dwFieldSpec,
            /* [annotation][in] */ 
            _In_  UINT nRadix,
            /* [annotation][out] */ 
            _Out_  IEnumDebugExtendedPropertyInfo **ppeepi) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IDebugExtendedPropertyVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IDebugExtendedProperty * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IDebugExtendedProperty * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IDebugExtendedProperty * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *GetPropertyInfo )( 
            IDebugExtendedProperty * This,
            /* [annotation][in] */ 
            _In_  DWORD dwFieldSpec,
            /* [annotation][in] */ 
            _In_  UINT nRadix,
            /* [annotation][out] */ 
            _Out_  DebugPropertyInfo *pPropertyInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetExtendedInfo )( 
            __RPC__in IDebugExtendedProperty * This,
            /* [annotation][in] */ 
            _In_  ULONG cInfos,
            /* [annotation][size_is][in] */ 
            _In_reads_(cInfos)  GUID *rgguidExtendedInfo,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cInfos)  VARIANT *rgvar);
        
        HRESULT ( STDMETHODCALLTYPE *SetValueAsString )( 
            __RPC__in IDebugExtendedProperty * This,
            /* [annotation][in] */ 
            _In_  LPCOLESTR pszValue,
            /* [annotation][in] */ 
            _In_  UINT nRadix);
        
        HRESULT ( STDMETHODCALLTYPE *EnumMembers )( 
            __RPC__in IDebugExtendedProperty * This,
            /* [annotation][in] */ 
            _In_  DWORD dwFieldSpec,
            /* [annotation][in] */ 
            _In_  UINT nRadix,
            /* [annotation][in] */ 
            _In_  REFIID refiid,
            /* [annotation][out] */ 
            _Out_  IEnumDebugPropertyInfo **ppepi);
        
        HRESULT ( STDMETHODCALLTYPE *GetParent )( 
            __RPC__in IDebugExtendedProperty * This,
            /* [annotation][out] */ 
            _Out_  IDebugProperty **ppDebugProp);
        
        HRESULT ( STDMETHODCALLTYPE *GetExtendedPropertyInfo )( 
            __RPC__in IDebugExtendedProperty * This,
            /* [annotation][in] */ 
            _In_  DWORD dwFieldSpec,
            /* [annotation][in] */ 
            _In_  UINT nRadix,
            /* [annotation][out] */ 
            _Out_  ExtendedDebugPropertyInfo *pExtendedPropertyInfo);
        
        HRESULT ( STDMETHODCALLTYPE *EnumExtendedMembers )( 
            __RPC__in IDebugExtendedProperty * This,
            /* [annotation][in] */ 
            _In_  DWORD dwFieldSpec,
            /* [annotation][in] */ 
            _In_  UINT nRadix,
            /* [annotation][out] */ 
            _Out_  IEnumDebugExtendedPropertyInfo **ppeepi);
        
        END_INTERFACE
    } IDebugExtendedPropertyVtbl;

    interface IDebugExtendedProperty
    {
        CONST_VTBL struct IDebugExtendedPropertyVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDebugExtendedProperty_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDebugExtendedProperty_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDebugExtendedProperty_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDebugExtendedProperty_GetPropertyInfo(This,dwFieldSpec,nRadix,pPropertyInfo)	\
    ( (This)->lpVtbl -> GetPropertyInfo(This,dwFieldSpec,nRadix,pPropertyInfo) ) 

#define IDebugExtendedProperty_GetExtendedInfo(This,cInfos,rgguidExtendedInfo,rgvar)	\
    ( (This)->lpVtbl -> GetExtendedInfo(This,cInfos,rgguidExtendedInfo,rgvar) ) 

#define IDebugExtendedProperty_SetValueAsString(This,pszValue,nRadix)	\
    ( (This)->lpVtbl -> SetValueAsString(This,pszValue,nRadix) ) 

#define IDebugExtendedProperty_EnumMembers(This,dwFieldSpec,nRadix,refiid,ppepi)	\
    ( (This)->lpVtbl -> EnumMembers(This,dwFieldSpec,nRadix,refiid,ppepi) ) 

#define IDebugExtendedProperty_GetParent(This,ppDebugProp)	\
    ( (This)->lpVtbl -> GetParent(This,ppDebugProp) ) 


#define IDebugExtendedProperty_GetExtendedPropertyInfo(This,dwFieldSpec,nRadix,pExtendedPropertyInfo)	\
    ( (This)->lpVtbl -> GetExtendedPropertyInfo(This,dwFieldSpec,nRadix,pExtendedPropertyInfo) ) 

#define IDebugExtendedProperty_EnumExtendedMembers(This,dwFieldSpec,nRadix,ppeepi)	\
    ( (This)->lpVtbl -> EnumExtendedMembers(This,dwFieldSpec,nRadix,ppeepi) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDebugExtendedProperty_INTERFACE_DEFINED__ */


#ifndef __IEnumDebugExtendedPropertyInfo_INTERFACE_DEFINED__
#define __IEnumDebugExtendedPropertyInfo_INTERFACE_DEFINED__

/* interface IEnumDebugExtendedPropertyInfo */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IEnumDebugExtendedPropertyInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("51973C53-CB0C-11d0-B5C9-00A0244A0E7A")
    IEnumDebugExtendedPropertyInfo : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [annotation][in] */ 
            _In_  ULONG celt,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(celt,*pceltFetched)  ExtendedDebugPropertyInfo *rgExtendedPropertyInfo,
            /* [annotation][out] */ 
            _Out_  ULONG *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [annotation][in] */ 
            _In_  ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [annotation][out] */ 
            _Out_  IEnumDebugExtendedPropertyInfo **pedpe) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCount( 
            /* [annotation][out] */ 
            _Out_  ULONG *pcelt) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IEnumDebugExtendedPropertyInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IEnumDebugExtendedPropertyInfo * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IEnumDebugExtendedPropertyInfo * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IEnumDebugExtendedPropertyInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            __RPC__in IEnumDebugExtendedPropertyInfo * This,
            /* [annotation][in] */ 
            _In_  ULONG celt,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(celt,*pceltFetched)  ExtendedDebugPropertyInfo *rgExtendedPropertyInfo,
            /* [annotation][out] */ 
            _Out_  ULONG *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            __RPC__in IEnumDebugExtendedPropertyInfo * This,
            /* [annotation][in] */ 
            _In_  ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            __RPC__in IEnumDebugExtendedPropertyInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            __RPC__in IEnumDebugExtendedPropertyInfo * This,
            /* [annotation][out] */ 
            _Out_  IEnumDebugExtendedPropertyInfo **pedpe);
        
        HRESULT ( STDMETHODCALLTYPE *GetCount )( 
            __RPC__in IEnumDebugExtendedPropertyInfo * This,
            /* [annotation][out] */ 
            _Out_  ULONG *pcelt);
        
        END_INTERFACE
    } IEnumDebugExtendedPropertyInfoVtbl;

    interface IEnumDebugExtendedPropertyInfo
    {
        CONST_VTBL struct IEnumDebugExtendedPropertyInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumDebugExtendedPropertyInfo_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEnumDebugExtendedPropertyInfo_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEnumDebugExtendedPropertyInfo_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IEnumDebugExtendedPropertyInfo_Next(This,celt,rgExtendedPropertyInfo,pceltFetched)	\
    ( (This)->lpVtbl -> Next(This,celt,rgExtendedPropertyInfo,pceltFetched) ) 

#define IEnumDebugExtendedPropertyInfo_Skip(This,celt)	\
    ( (This)->lpVtbl -> Skip(This,celt) ) 

#define IEnumDebugExtendedPropertyInfo_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define IEnumDebugExtendedPropertyInfo_Clone(This,pedpe)	\
    ( (This)->lpVtbl -> Clone(This,pedpe) ) 

#define IEnumDebugExtendedPropertyInfo_GetCount(This,pcelt)	\
    ( (This)->lpVtbl -> GetCount(This,pcelt) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IEnumDebugExtendedPropertyInfo_INTERFACE_DEFINED__ */


#ifndef __IPerPropertyBrowsing2_INTERFACE_DEFINED__
#define __IPerPropertyBrowsing2_INTERFACE_DEFINED__

/* interface IPerPropertyBrowsing2 */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IPerPropertyBrowsing2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("51973C54-CB0C-11d0-B5C9-00A0244A0E7A")
    IPerPropertyBrowsing2 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetDisplayString( 
            /* [annotation][in] */ 
            _In_  DISPID dispid,
            /* [annotation][out] */ 
            _Out_  BSTR *pBstr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE MapPropertyToPage( 
            /* [annotation][in] */ 
            _In_  DISPID dispid,
            /* [annotation][out] */ 
            _Out_  CLSID *pClsidPropPage) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPredefinedStrings( 
            /* [annotation][in] */ 
            _In_  DISPID dispid,
            /* [annotation][out] */ 
            _Out_  CALPOLESTR *pCaStrings,
            /* [annotation][out] */ 
            _Out_  CADWORD *pCaCookies) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPredefinedValue( 
            /* [annotation][in] */ 
            _In_  DISPID dispid,
            /* [annotation][in] */ 
            _In_  DWORD dwCookie) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IPerPropertyBrowsing2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IPerPropertyBrowsing2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IPerPropertyBrowsing2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IPerPropertyBrowsing2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetDisplayString )( 
            __RPC__in IPerPropertyBrowsing2 * This,
            /* [annotation][in] */ 
            _In_  DISPID dispid,
            /* [annotation][out] */ 
            _Out_  BSTR *pBstr);
        
        HRESULT ( STDMETHODCALLTYPE *MapPropertyToPage )( 
            __RPC__in IPerPropertyBrowsing2 * This,
            /* [annotation][in] */ 
            _In_  DISPID dispid,
            /* [annotation][out] */ 
            _Out_  CLSID *pClsidPropPage);
        
        HRESULT ( STDMETHODCALLTYPE *GetPredefinedStrings )( 
            __RPC__in IPerPropertyBrowsing2 * This,
            /* [annotation][in] */ 
            _In_  DISPID dispid,
            /* [annotation][out] */ 
            _Out_  CALPOLESTR *pCaStrings,
            /* [annotation][out] */ 
            _Out_  CADWORD *pCaCookies);
        
        HRESULT ( STDMETHODCALLTYPE *SetPredefinedValue )( 
            __RPC__in IPerPropertyBrowsing2 * This,
            /* [annotation][in] */ 
            _In_  DISPID dispid,
            /* [annotation][in] */ 
            _In_  DWORD dwCookie);
        
        END_INTERFACE
    } IPerPropertyBrowsing2Vtbl;

    interface IPerPropertyBrowsing2
    {
        CONST_VTBL struct IPerPropertyBrowsing2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPerPropertyBrowsing2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPerPropertyBrowsing2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPerPropertyBrowsing2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPerPropertyBrowsing2_GetDisplayString(This,dispid,pBstr)	\
    ( (This)->lpVtbl -> GetDisplayString(This,dispid,pBstr) ) 

#define IPerPropertyBrowsing2_MapPropertyToPage(This,dispid,pClsidPropPage)	\
    ( (This)->lpVtbl -> MapPropertyToPage(This,dispid,pClsidPropPage) ) 

#define IPerPropertyBrowsing2_GetPredefinedStrings(This,dispid,pCaStrings,pCaCookies)	\
    ( (This)->lpVtbl -> GetPredefinedStrings(This,dispid,pCaStrings,pCaCookies) ) 

#define IPerPropertyBrowsing2_SetPredefinedValue(This,dispid,dwCookie)	\
    ( (This)->lpVtbl -> SetPredefinedValue(This,dispid,dwCookie) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPerPropertyBrowsing2_INTERFACE_DEFINED__ */


#ifndef __IDebugPropertyEnumType_All_INTERFACE_DEFINED__
#define __IDebugPropertyEnumType_All_INTERFACE_DEFINED__

/* interface IDebugPropertyEnumType_All */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IDebugPropertyEnumType_All;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("51973C55-CB0C-11d0-B5C9-00A0244A0E7A")
    IDebugPropertyEnumType_All : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetName( 
            /* [annotation][out] */ 
            _Out_  BSTR *__MIDL__IDebugPropertyEnumType_All0000) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IDebugPropertyEnumType_AllVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IDebugPropertyEnumType_All * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IDebugPropertyEnumType_All * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IDebugPropertyEnumType_All * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetName )( 
            __RPC__in IDebugPropertyEnumType_All * This,
            /* [annotation][out] */ 
            _Out_  BSTR *__MIDL__IDebugPropertyEnumType_All0000);
        
        END_INTERFACE
    } IDebugPropertyEnumType_AllVtbl;

    interface IDebugPropertyEnumType_All
    {
        CONST_VTBL struct IDebugPropertyEnumType_AllVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDebugPropertyEnumType_All_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDebugPropertyEnumType_All_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDebugPropertyEnumType_All_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDebugPropertyEnumType_All_GetName(This,__MIDL__IDebugPropertyEnumType_All0000)	\
    ( (This)->lpVtbl -> GetName(This,__MIDL__IDebugPropertyEnumType_All0000) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDebugPropertyEnumType_All_INTERFACE_DEFINED__ */


#ifndef __IDebugPropertyEnumType_Locals_INTERFACE_DEFINED__
#define __IDebugPropertyEnumType_Locals_INTERFACE_DEFINED__

/* interface IDebugPropertyEnumType_Locals */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IDebugPropertyEnumType_Locals;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("51973C56-CB0C-11d0-B5C9-00A0244A0E7A")
    IDebugPropertyEnumType_Locals : public IDebugPropertyEnumType_All
    {
    public:
    };
    
    
#else 	/* C style interface */

    typedef struct IDebugPropertyEnumType_LocalsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IDebugPropertyEnumType_Locals * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IDebugPropertyEnumType_Locals * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IDebugPropertyEnumType_Locals * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetName )( 
            __RPC__in IDebugPropertyEnumType_Locals * This,
            /* [annotation][out] */ 
            _Out_  BSTR *__MIDL__IDebugPropertyEnumType_All0000);
        
        END_INTERFACE
    } IDebugPropertyEnumType_LocalsVtbl;

    interface IDebugPropertyEnumType_Locals
    {
        CONST_VTBL struct IDebugPropertyEnumType_LocalsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDebugPropertyEnumType_Locals_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDebugPropertyEnumType_Locals_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDebugPropertyEnumType_Locals_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDebugPropertyEnumType_Locals_GetName(This,__MIDL__IDebugPropertyEnumType_All0000)	\
    ( (This)->lpVtbl -> GetName(This,__MIDL__IDebugPropertyEnumType_All0000) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDebugPropertyEnumType_Locals_INTERFACE_DEFINED__ */


#ifndef __IDebugPropertyEnumType_Arguments_INTERFACE_DEFINED__
#define __IDebugPropertyEnumType_Arguments_INTERFACE_DEFINED__

/* interface IDebugPropertyEnumType_Arguments */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IDebugPropertyEnumType_Arguments;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("51973C57-CB0C-11d0-B5C9-00A0244A0E7A")
    IDebugPropertyEnumType_Arguments : public IDebugPropertyEnumType_All
    {
    public:
    };
    
    
#else 	/* C style interface */

    typedef struct IDebugPropertyEnumType_ArgumentsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IDebugPropertyEnumType_Arguments * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IDebugPropertyEnumType_Arguments * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IDebugPropertyEnumType_Arguments * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetName )( 
            __RPC__in IDebugPropertyEnumType_Arguments * This,
            /* [annotation][out] */ 
            _Out_  BSTR *__MIDL__IDebugPropertyEnumType_All0000);
        
        END_INTERFACE
    } IDebugPropertyEnumType_ArgumentsVtbl;

    interface IDebugPropertyEnumType_Arguments
    {
        CONST_VTBL struct IDebugPropertyEnumType_ArgumentsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDebugPropertyEnumType_Arguments_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDebugPropertyEnumType_Arguments_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDebugPropertyEnumType_Arguments_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDebugPropertyEnumType_Arguments_GetName(This,__MIDL__IDebugPropertyEnumType_All0000)	\
    ( (This)->lpVtbl -> GetName(This,__MIDL__IDebugPropertyEnumType_All0000) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDebugPropertyEnumType_Arguments_INTERFACE_DEFINED__ */


#ifndef __IDebugPropertyEnumType_LocalsPlusArgs_INTERFACE_DEFINED__
#define __IDebugPropertyEnumType_LocalsPlusArgs_INTERFACE_DEFINED__

/* interface IDebugPropertyEnumType_LocalsPlusArgs */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IDebugPropertyEnumType_LocalsPlusArgs;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("51973C58-CB0C-11d0-B5C9-00A0244A0E7A")
    IDebugPropertyEnumType_LocalsPlusArgs : public IDebugPropertyEnumType_All
    {
    public:
    };
    
    
#else 	/* C style interface */

    typedef struct IDebugPropertyEnumType_LocalsPlusArgsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IDebugPropertyEnumType_LocalsPlusArgs * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IDebugPropertyEnumType_LocalsPlusArgs * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IDebugPropertyEnumType_LocalsPlusArgs * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetName )( 
            __RPC__in IDebugPropertyEnumType_LocalsPlusArgs * This,
            /* [annotation][out] */ 
            _Out_  BSTR *__MIDL__IDebugPropertyEnumType_All0000);
        
        END_INTERFACE
    } IDebugPropertyEnumType_LocalsPlusArgsVtbl;

    interface IDebugPropertyEnumType_LocalsPlusArgs
    {
        CONST_VTBL struct IDebugPropertyEnumType_LocalsPlusArgsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDebugPropertyEnumType_LocalsPlusArgs_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDebugPropertyEnumType_LocalsPlusArgs_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDebugPropertyEnumType_LocalsPlusArgs_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDebugPropertyEnumType_LocalsPlusArgs_GetName(This,__MIDL__IDebugPropertyEnumType_All0000)	\
    ( (This)->lpVtbl -> GetName(This,__MIDL__IDebugPropertyEnumType_All0000) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDebugPropertyEnumType_LocalsPlusArgs_INTERFACE_DEFINED__ */


#ifndef __IDebugPropertyEnumType_Registers_INTERFACE_DEFINED__
#define __IDebugPropertyEnumType_Registers_INTERFACE_DEFINED__

/* interface IDebugPropertyEnumType_Registers */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IDebugPropertyEnumType_Registers;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("51973C59-CB0C-11d0-B5C9-00A0244A0E7A")
    IDebugPropertyEnumType_Registers : public IDebugPropertyEnumType_All
    {
    public:
    };
    
    
#else 	/* C style interface */

    typedef struct IDebugPropertyEnumType_RegistersVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IDebugPropertyEnumType_Registers * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IDebugPropertyEnumType_Registers * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IDebugPropertyEnumType_Registers * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetName )( 
            __RPC__in IDebugPropertyEnumType_Registers * This,
            /* [annotation][out] */ 
            _Out_  BSTR *__MIDL__IDebugPropertyEnumType_All0000);
        
        END_INTERFACE
    } IDebugPropertyEnumType_RegistersVtbl;

    interface IDebugPropertyEnumType_Registers
    {
        CONST_VTBL struct IDebugPropertyEnumType_RegistersVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDebugPropertyEnumType_Registers_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDebugPropertyEnumType_Registers_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDebugPropertyEnumType_Registers_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDebugPropertyEnumType_Registers_GetName(This,__MIDL__IDebugPropertyEnumType_All0000)	\
    ( (This)->lpVtbl -> GetName(This,__MIDL__IDebugPropertyEnumType_All0000) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDebugPropertyEnumType_Registers_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_dbgprop_0000_0010 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_dbgprop_0000_0010_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_dbgprop_0000_0010_v0_0_s_ifspec;

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

/* [local] */ HRESULT STDMETHODCALLTYPE IDebugProperty_GetPropertyInfo_Proxy( 
    IDebugProperty * This,
    /* [annotation][in] */ 
    _In_  DWORD dwFieldSpec,
    /* [annotation][in] */ 
    _In_  UINT nRadix,
    /* [annotation][out] */ 
    _Out_  DebugPropertyInfo *pPropertyInfo);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IDebugProperty_GetPropertyInfo_Stub( 
    __RPC__in IDebugProperty * This,
    /* [annotation][in] */ 
    _In_  DWORD dwFieldSpec,
    /* [annotation][in] */ 
    _In_  UINT nRadix,
    /* [annotation][out] */ 
    _Out_  DWORD *dwValidFields,
    /* [annotation][out] */ 
    _Out_  BSTR *pbstrName,
    /* [annotation][out] */ 
    _Out_  BSTR *pbstrType,
    /* [annotation][out] */ 
    _Out_  BSTR *pbstrValue,
    /* [annotation][out] */ 
    _Out_  BSTR *pbstrFullName,
    /* [annotation][out] */ 
    _Out_  DWORD *pdwAttrib,
    /* [annotation][unique][out][in] */ 
    _Inout_  IDebugProperty **ppDebugProperty);

/* [local] */ HRESULT STDMETHODCALLTYPE IEnumDebugPropertyInfo_Next_Proxy( 
    IEnumDebugPropertyInfo * This,
    /* [annotation][in] */ 
    _In_  ULONG celt,
    /* [annotation][out] */ 
    _Out_  DebugPropertyInfo *pi,
    /* [annotation][out] */ 
    _Out_  ULONG *pcEltsfetched);


/* [call_as] */ HRESULT __stdcall IEnumDebugPropertyInfo_Next_Stub( 
    __RPC__in IEnumDebugPropertyInfo * This,
    /* [annotation][in] */ 
    _In_  ULONG celt,
    /* [annotation][length_is][size_is][unique][out][in] */ 
    _Inout_updates_to_(celt,*pcEltsfetched)  DebugPropertyInfo *pinfo,
    /* [annotation][out] */ 
    _Out_  ULONG *pcEltsfetched);



/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


