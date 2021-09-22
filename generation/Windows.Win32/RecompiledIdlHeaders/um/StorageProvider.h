

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

#ifndef __storageprovider_h__
#define __storageprovider_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IStorageProviderPropertyHandler_FWD_DEFINED__
#define __IStorageProviderPropertyHandler_FWD_DEFINED__
typedef interface IStorageProviderPropertyHandler IStorageProviderPropertyHandler;

#endif 	/* __IStorageProviderPropertyHandler_FWD_DEFINED__ */


#ifndef __IStorageProviderHandler_FWD_DEFINED__
#define __IStorageProviderHandler_FWD_DEFINED__
typedef interface IStorageProviderHandler IStorageProviderHandler;

#endif 	/* __IStorageProviderHandler_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "propsys.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_storageprovider_0000_0000 */
/* [local] */ 

#include <winapifamily.h>
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)


extern RPC_IF_HANDLE __MIDL_itf_storageprovider_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_storageprovider_0000_0000_v0_0_s_ifspec;

#ifndef __IStorageProviderPropertyHandler_INTERFACE_DEFINED__
#define __IStorageProviderPropertyHandler_INTERFACE_DEFINED__

/* interface IStorageProviderPropertyHandler */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IStorageProviderPropertyHandler;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("301DFBE5-524C-4B0F-8B2D-21C40B3A2988")
    IStorageProviderPropertyHandler : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE RetrieveProperties( 
            /* [annotation][size_is][in] */ 
            _In_reads_(propertiesToRetrieveCount)  const PROPERTYKEY *propertiesToRetrieve,
            /* [annotation][in] */ 
            _In_  ULONG propertiesToRetrieveCount,
            /* [annotation][out] */ 
            _Out_  IPropertyStore **retrievedProperties) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SaveProperties( 
            /* [annotation][in] */ 
            _In_  IPropertyStore *propertiesToSave) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IStorageProviderPropertyHandlerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IStorageProviderPropertyHandler * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IStorageProviderPropertyHandler * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IStorageProviderPropertyHandler * This);
        
        HRESULT ( STDMETHODCALLTYPE *RetrieveProperties )( 
            __RPC__in IStorageProviderPropertyHandler * This,
            /* [annotation][size_is][in] */ 
            _In_reads_(propertiesToRetrieveCount)  const PROPERTYKEY *propertiesToRetrieve,
            /* [annotation][in] */ 
            _In_  ULONG propertiesToRetrieveCount,
            /* [annotation][out] */ 
            _Out_  IPropertyStore **retrievedProperties);
        
        HRESULT ( STDMETHODCALLTYPE *SaveProperties )( 
            __RPC__in IStorageProviderPropertyHandler * This,
            /* [annotation][in] */ 
            _In_  IPropertyStore *propertiesToSave);
        
        END_INTERFACE
    } IStorageProviderPropertyHandlerVtbl;

    interface IStorageProviderPropertyHandler
    {
        CONST_VTBL struct IStorageProviderPropertyHandlerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IStorageProviderPropertyHandler_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IStorageProviderPropertyHandler_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IStorageProviderPropertyHandler_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IStorageProviderPropertyHandler_RetrieveProperties(This,propertiesToRetrieve,propertiesToRetrieveCount,retrievedProperties)	\
    ( (This)->lpVtbl -> RetrieveProperties(This,propertiesToRetrieve,propertiesToRetrieveCount,retrievedProperties) ) 

#define IStorageProviderPropertyHandler_SaveProperties(This,propertiesToSave)	\
    ( (This)->lpVtbl -> SaveProperties(This,propertiesToSave) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IStorageProviderPropertyHandler_INTERFACE_DEFINED__ */


#ifndef __IStorageProviderHandler_INTERFACE_DEFINED__
#define __IStorageProviderHandler_INTERFACE_DEFINED__

/* interface IStorageProviderHandler */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IStorageProviderHandler;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("162C6FB5-44D3-435B-903D-E613FA093FB5")
    IStorageProviderHandler : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetPropertyHandlerFromPath( 
            /* [annotation][in] */ 
            _In_  LPCWSTR path,
            /* [annotation][out] */ 
            _Out_  IStorageProviderPropertyHandler **propertyHandler) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPropertyHandlerFromUri( 
            /* [annotation][in] */ 
            _In_  LPCWSTR uri,
            /* [annotation][out] */ 
            _Out_  IStorageProviderPropertyHandler **propertyHandler) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPropertyHandlerFromFileId( 
            /* [annotation][in] */ 
            _In_  LPCWSTR fileId,
            /* [annotation][out] */ 
            _Out_  IStorageProviderPropertyHandler **propertyHandler) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IStorageProviderHandlerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IStorageProviderHandler * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IStorageProviderHandler * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IStorageProviderHandler * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetPropertyHandlerFromPath )( 
            __RPC__in IStorageProviderHandler * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR path,
            /* [annotation][out] */ 
            _Out_  IStorageProviderPropertyHandler **propertyHandler);
        
        HRESULT ( STDMETHODCALLTYPE *GetPropertyHandlerFromUri )( 
            __RPC__in IStorageProviderHandler * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR uri,
            /* [annotation][out] */ 
            _Out_  IStorageProviderPropertyHandler **propertyHandler);
        
        HRESULT ( STDMETHODCALLTYPE *GetPropertyHandlerFromFileId )( 
            __RPC__in IStorageProviderHandler * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR fileId,
            /* [annotation][out] */ 
            _Out_  IStorageProviderPropertyHandler **propertyHandler);
        
        END_INTERFACE
    } IStorageProviderHandlerVtbl;

    interface IStorageProviderHandler
    {
        CONST_VTBL struct IStorageProviderHandlerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IStorageProviderHandler_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IStorageProviderHandler_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IStorageProviderHandler_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IStorageProviderHandler_GetPropertyHandlerFromPath(This,path,propertyHandler)	\
    ( (This)->lpVtbl -> GetPropertyHandlerFromPath(This,path,propertyHandler) ) 

#define IStorageProviderHandler_GetPropertyHandlerFromUri(This,uri,propertyHandler)	\
    ( (This)->lpVtbl -> GetPropertyHandlerFromUri(This,uri,propertyHandler) ) 

#define IStorageProviderHandler_GetPropertyHandlerFromFileId(This,fileId,propertyHandler)	\
    ( (This)->lpVtbl -> GetPropertyHandlerFromFileId(This,fileId,propertyHandler) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IStorageProviderHandler_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_storageprovider_0000_0002 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_storageprovider_0000_0002_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_storageprovider_0000_0002_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


