

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

#ifndef __iaccess_h__
#define __iaccess_h__

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

#ifndef __IAccessControl_FWD_DEFINED__
#define __IAccessControl_FWD_DEFINED__
typedef interface IAccessControl IAccessControl;

#endif 	/* __IAccessControl_FWD_DEFINED__ */


#ifndef __IAuditControl_FWD_DEFINED__
#define __IAuditControl_FWD_DEFINED__
typedef interface IAuditControl IAuditControl;

#endif 	/* __IAuditControl_FWD_DEFINED__ */


/* header files for imported files */
#include "unknwn.h"
#include "accctrl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_iaccess_0000_0000 */
/* [local] */ 

//+-------------------------------------------------------------------------
//
//  Microsoft Windows
//  Copyright (c) Microsoft Corporation. All rights reserved.
//
//--------------------------------------------------------------------------
#if ( _MSC_VER >= 1020 )
#pragma once
#endif
#include <winapifamily.h>
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
typedef PACTRL_ACCESSW PACTRL_ACCESSW_ALLOCATE_ALL_NODES;

typedef PACTRL_AUDITW PACTRL_AUDITW_ALLOCATE_ALL_NODES;




extern RPC_IF_HANDLE __MIDL_itf_iaccess_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_iaccess_0000_0000_v0_0_s_ifspec;

#ifndef __IAccessControl_INTERFACE_DEFINED__
#define __IAccessControl_INTERFACE_DEFINED__

/* interface IAccessControl */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IAccessControl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("EEDD23E0-8410-11CE-A1C3-08002B2B8D8F")
    IAccessControl : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GrantAccessRights( 
            /* [annotation][in] */ 
            _In_  PACTRL_ACCESSW pAccessList) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAccessRights( 
            /* [annotation][in] */ 
            _In_  PACTRL_ACCESSW pAccessList) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetOwner( 
            /* [annotation][in] */ 
            _In_  PTRUSTEEW pOwner,
            /* [annotation][in] */ 
            _In_  PTRUSTEEW pGroup) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RevokeAccessRights( 
            /* [annotation][in] */ 
            _In_  LPWSTR lpProperty,
            /* [annotation][in] */ 
            _In_  ULONG cTrustees,
            /* [annotation][size_is][in] */ 
            _In_reads_(cTrustees)  TRUSTEEW prgTrustees[  ]) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAllAccessRights( 
            /* [annotation][in] */ 
            _In_  LPWSTR lpProperty,
            /* [annotation][out] */ 
            _Out_  PACTRL_ACCESSW_ALLOCATE_ALL_NODES *ppAccessList,
            /* [annotation][out] */ 
            _Out_  PTRUSTEEW *ppOwner,
            /* [annotation][out] */ 
            _Out_  PTRUSTEEW *ppGroup) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsAccessAllowed( 
            /* [annotation][in] */ 
            _In_  PTRUSTEEW pTrustee,
            /* [annotation][in] */ 
            _In_  LPWSTR lpProperty,
            /* [annotation][in] */ 
            _In_  ACCESS_RIGHTS AccessRights,
            /* [annotation][out] */ 
            _Out_  BOOL *pfAccessAllowed) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAccessControlVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IAccessControl * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IAccessControl * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IAccessControl * This);
        
        DECLSPEC_XFGVIRT(IAccessControl, GrantAccessRights)
        HRESULT ( STDMETHODCALLTYPE *GrantAccessRights )( 
            __RPC__in IAccessControl * This,
            /* [annotation][in] */ 
            _In_  PACTRL_ACCESSW pAccessList);
        
        DECLSPEC_XFGVIRT(IAccessControl, SetAccessRights)
        HRESULT ( STDMETHODCALLTYPE *SetAccessRights )( 
            __RPC__in IAccessControl * This,
            /* [annotation][in] */ 
            _In_  PACTRL_ACCESSW pAccessList);
        
        DECLSPEC_XFGVIRT(IAccessControl, SetOwner)
        HRESULT ( STDMETHODCALLTYPE *SetOwner )( 
            __RPC__in IAccessControl * This,
            /* [annotation][in] */ 
            _In_  PTRUSTEEW pOwner,
            /* [annotation][in] */ 
            _In_  PTRUSTEEW pGroup);
        
        DECLSPEC_XFGVIRT(IAccessControl, RevokeAccessRights)
        HRESULT ( STDMETHODCALLTYPE *RevokeAccessRights )( 
            __RPC__in IAccessControl * This,
            /* [annotation][in] */ 
            _In_  LPWSTR lpProperty,
            /* [annotation][in] */ 
            _In_  ULONG cTrustees,
            /* [annotation][size_is][in] */ 
            _In_reads_(cTrustees)  TRUSTEEW prgTrustees[  ]);
        
        DECLSPEC_XFGVIRT(IAccessControl, GetAllAccessRights)
        HRESULT ( STDMETHODCALLTYPE *GetAllAccessRights )( 
            __RPC__in IAccessControl * This,
            /* [annotation][in] */ 
            _In_  LPWSTR lpProperty,
            /* [annotation][out] */ 
            _Out_  PACTRL_ACCESSW_ALLOCATE_ALL_NODES *ppAccessList,
            /* [annotation][out] */ 
            _Out_  PTRUSTEEW *ppOwner,
            /* [annotation][out] */ 
            _Out_  PTRUSTEEW *ppGroup);
        
        DECLSPEC_XFGVIRT(IAccessControl, IsAccessAllowed)
        HRESULT ( STDMETHODCALLTYPE *IsAccessAllowed )( 
            __RPC__in IAccessControl * This,
            /* [annotation][in] */ 
            _In_  PTRUSTEEW pTrustee,
            /* [annotation][in] */ 
            _In_  LPWSTR lpProperty,
            /* [annotation][in] */ 
            _In_  ACCESS_RIGHTS AccessRights,
            /* [annotation][out] */ 
            _Out_  BOOL *pfAccessAllowed);
        
        END_INTERFACE
    } IAccessControlVtbl;

    interface IAccessControl
    {
        CONST_VTBL struct IAccessControlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAccessControl_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAccessControl_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAccessControl_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAccessControl_GrantAccessRights(This,pAccessList)	\
    ( (This)->lpVtbl -> GrantAccessRights(This,pAccessList) ) 

#define IAccessControl_SetAccessRights(This,pAccessList)	\
    ( (This)->lpVtbl -> SetAccessRights(This,pAccessList) ) 

#define IAccessControl_SetOwner(This,pOwner,pGroup)	\
    ( (This)->lpVtbl -> SetOwner(This,pOwner,pGroup) ) 

#define IAccessControl_RevokeAccessRights(This,lpProperty,cTrustees,prgTrustees)	\
    ( (This)->lpVtbl -> RevokeAccessRights(This,lpProperty,cTrustees,prgTrustees) ) 

#define IAccessControl_GetAllAccessRights(This,lpProperty,ppAccessList,ppOwner,ppGroup)	\
    ( (This)->lpVtbl -> GetAllAccessRights(This,lpProperty,ppAccessList,ppOwner,ppGroup) ) 

#define IAccessControl_IsAccessAllowed(This,pTrustee,lpProperty,AccessRights,pfAccessAllowed)	\
    ( (This)->lpVtbl -> IsAccessAllowed(This,pTrustee,lpProperty,AccessRights,pfAccessAllowed) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAccessControl_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_iaccess_0000_0001 */
/* [local] */ 




extern RPC_IF_HANDLE __MIDL_itf_iaccess_0000_0001_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_iaccess_0000_0001_v0_0_s_ifspec;

#ifndef __IAuditControl_INTERFACE_DEFINED__
#define __IAuditControl_INTERFACE_DEFINED__

/* interface IAuditControl */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IAuditControl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1da6292f-bc66-11ce-aae3-00aa004c2737")
    IAuditControl : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GrantAuditRights( 
            /* [annotation][in] */ 
            _In_  PACTRL_AUDITW pAuditList) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAuditRights( 
            /* [annotation][in] */ 
            _In_  PACTRL_AUDITW pAuditList) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RevokeAuditRights( 
            /* [annotation][in] */ 
            _In_  LPWSTR lpProperty,
            /* [annotation][in] */ 
            _In_  ULONG cTrustees,
            /* [annotation][size_is][in] */ 
            _In_reads_(cTrustees)  TRUSTEEW prgTrustees[  ]) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAllAuditRights( 
            /* [annotation][in] */ 
            _In_  LPWSTR lpProperty,
            /* [annotation][out] */ 
            _Out_  PACTRL_AUDITW *ppAuditList) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsAccessAudited( 
            /* [annotation][in] */ 
            _In_  PTRUSTEEW pTrustee,
            /* [annotation][in] */ 
            _In_  ACCESS_RIGHTS AuditRights,
            /* [annotation][out] */ 
            _Out_  BOOL *pfAccessAudited) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAuditControlVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IAuditControl * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IAuditControl * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IAuditControl * This);
        
        DECLSPEC_XFGVIRT(IAuditControl, GrantAuditRights)
        HRESULT ( STDMETHODCALLTYPE *GrantAuditRights )( 
            __RPC__in IAuditControl * This,
            /* [annotation][in] */ 
            _In_  PACTRL_AUDITW pAuditList);
        
        DECLSPEC_XFGVIRT(IAuditControl, SetAuditRights)
        HRESULT ( STDMETHODCALLTYPE *SetAuditRights )( 
            __RPC__in IAuditControl * This,
            /* [annotation][in] */ 
            _In_  PACTRL_AUDITW pAuditList);
        
        DECLSPEC_XFGVIRT(IAuditControl, RevokeAuditRights)
        HRESULT ( STDMETHODCALLTYPE *RevokeAuditRights )( 
            __RPC__in IAuditControl * This,
            /* [annotation][in] */ 
            _In_  LPWSTR lpProperty,
            /* [annotation][in] */ 
            _In_  ULONG cTrustees,
            /* [annotation][size_is][in] */ 
            _In_reads_(cTrustees)  TRUSTEEW prgTrustees[  ]);
        
        DECLSPEC_XFGVIRT(IAuditControl, GetAllAuditRights)
        HRESULT ( STDMETHODCALLTYPE *GetAllAuditRights )( 
            __RPC__in IAuditControl * This,
            /* [annotation][in] */ 
            _In_  LPWSTR lpProperty,
            /* [annotation][out] */ 
            _Out_  PACTRL_AUDITW *ppAuditList);
        
        DECLSPEC_XFGVIRT(IAuditControl, IsAccessAudited)
        HRESULT ( STDMETHODCALLTYPE *IsAccessAudited )( 
            __RPC__in IAuditControl * This,
            /* [annotation][in] */ 
            _In_  PTRUSTEEW pTrustee,
            /* [annotation][in] */ 
            _In_  ACCESS_RIGHTS AuditRights,
            /* [annotation][out] */ 
            _Out_  BOOL *pfAccessAudited);
        
        END_INTERFACE
    } IAuditControlVtbl;

    interface IAuditControl
    {
        CONST_VTBL struct IAuditControlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAuditControl_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAuditControl_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAuditControl_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAuditControl_GrantAuditRights(This,pAuditList)	\
    ( (This)->lpVtbl -> GrantAuditRights(This,pAuditList) ) 

#define IAuditControl_SetAuditRights(This,pAuditList)	\
    ( (This)->lpVtbl -> SetAuditRights(This,pAuditList) ) 

#define IAuditControl_RevokeAuditRights(This,lpProperty,cTrustees,prgTrustees)	\
    ( (This)->lpVtbl -> RevokeAuditRights(This,lpProperty,cTrustees,prgTrustees) ) 

#define IAuditControl_GetAllAuditRights(This,lpProperty,ppAuditList)	\
    ( (This)->lpVtbl -> GetAllAuditRights(This,lpProperty,ppAuditList) ) 

#define IAuditControl_IsAccessAudited(This,pTrustee,AuditRights,pfAccessAudited)	\
    ( (This)->lpVtbl -> IsAccessAudited(This,pTrustee,AuditRights,pfAccessAudited) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAuditControl_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_iaccess_0000_0002 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_iaccess_0000_0002_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_iaccess_0000_0002_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


