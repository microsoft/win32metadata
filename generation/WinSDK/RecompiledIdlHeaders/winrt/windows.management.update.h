
#pragma warning( disable: 4049 )  /* more than 64k source lines */

/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

/* verify that the <rpcsal.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCSAL_H_VERSION__
#define __REQUIRED_RPCSAL_H_VERSION__ 100
#endif

#include <rpc.h>
#include <rpcndr.h>

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include <windows.h>
#include <ole2.h>
#endif /*COM_NO_WINDOWS_H*/
#ifndef __windows2Emanagement2Eupdate_h__
#define __windows2Emanagement2Eupdate_h__
#ifndef __windows2Emanagement2Eupdate_p_h__
#define __windows2Emanagement2Eupdate_p_h__


#pragma once

//
// Deprecated attribute support
//

#pragma push_macro("DEPRECATED")
#undef DEPRECATED

#if !defined(DISABLE_WINRT_DEPRECATION)
#if defined(__cplusplus)
#if __cplusplus >= 201402
#define DEPRECATED(x) [[deprecated(x)]]
#define DEPRECATEDENUMERATOR(x) [[deprecated(x)]]
#elif defined(_MSC_VER)
#if _MSC_VER >= 1900
#define DEPRECATED(x) [[deprecated(x)]]
#define DEPRECATEDENUMERATOR(x) [[deprecated(x)]]
#else
#define DEPRECATED(x) __declspec(deprecated(x))
#define DEPRECATEDENUMERATOR(x)
#endif // _MSC_VER >= 1900
#else // Not Standard C++ or MSVC, ignore the construct.
#define DEPRECATED(x)
#define DEPRECATEDENUMERATOR(x)
#endif  // C++ deprecation
#else // C - disable deprecation
#define DEPRECATED(x)
#define DEPRECATEDENUMERATOR(x)
#endif
#else // Deprecation is disabled
#define DEPRECATED(x)
#define DEPRECATEDENUMERATOR(x)
#endif  /* DEPRECATED */

// Disable Deprecation for this header, MIDL verifies that cross-type access is acceptable
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#else
#pragma warning(push)
#pragma warning(disable: 4996)
#endif

// Ensure that the setting of the /ns_prefix command line switch is consistent for all headers.
// If you get an error from the compiler indicating "warning C4005: 'CHECK_NS_PREFIX_STATE': macro redefinition", this
// indicates that you have included two different headers with different settings for the /ns_prefix MIDL command line switch
#if !defined(DISABLE_NS_PREFIX_CHECKS)
#define CHECK_NS_PREFIX_STATE "always"
#endif // !defined(DISABLE_NS_PREFIX_CHECKS)


#pragma push_macro("MIDL_CONST_ID")
#undef MIDL_CONST_ID
#define MIDL_CONST_ID const __declspec(selectany)


//  API Contract Inclusion Definitions
#if !defined(SPECIFIC_API_CONTRACT_DEFINITIONS)
#if !defined(WINDOWS_FOUNDATION_FOUNDATIONCONTRACT_VERSION)
#define WINDOWS_FOUNDATION_FOUNDATIONCONTRACT_VERSION 0x40000
#endif // defined(WINDOWS_FOUNDATION_FOUNDATIONCONTRACT_VERSION)

#if !defined(WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION)
#define WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION 0xe0000
#endif // defined(WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION)

#endif // defined(SPECIFIC_API_CONTRACT_DEFINITIONS)


// Header files for imported files
#include "inspectable.h"
#include "AsyncInfo.h"
#include "EventToken.h"
#include "windowscontracts.h"
#include "Windows.Foundation.h"
// Importing Collections header
#include <windows.foundation.collections.h>

#if defined(__cplusplus) && !defined(CINTERFACE)
/* Forward Declarations */
#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManager_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManager_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                interface IPreviewBuildsManager;
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManager ABI::Windows::Management::Update::IPreviewBuildsManager

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManager_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManagerStatics_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManagerStatics_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                interface IPreviewBuildsManagerStatics;
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManagerStatics ABI::Windows::Management::Update::IPreviewBuildsManagerStatics

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManagerStatics_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsState_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsState_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                interface IPreviewBuildsState;
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsState ABI::Windows::Management::Update::IPreviewBuildsState

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsState_FWD_DEFINED__

// Parameterized interface forward declarations (C++)

// Collection interface definitions

#ifndef DEF___FIAsyncOperation_1_boolean_USE
#define DEF___FIAsyncOperation_1_boolean_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation {
template <>
struct __declspec(uuid("cdb5efb3-5788-509d-9be1-71ccb8a3362a"))
IAsyncOperation<bool> : IAsyncOperation_impl<ABI::Windows::Foundation::Internal::AggregateType<bool, boolean>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.IAsyncOperation`1<Boolean>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IAsyncOperation<bool> __FIAsyncOperation_1_boolean_t;
#define __FIAsyncOperation_1_boolean ABI::Windows::Foundation::__FIAsyncOperation_1_boolean_t
/* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIAsyncOperation_1_boolean_USE */



#ifndef DEF___FIAsyncOperationCompletedHandler_1_boolean_USE
#define DEF___FIAsyncOperationCompletedHandler_1_boolean_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation {
template <>
struct __declspec(uuid("c1d3d1a2-ae17-5a5f-b5a2-bdcc8844889a"))
IAsyncOperationCompletedHandler<bool> : IAsyncOperationCompletedHandler_impl<ABI::Windows::Foundation::Internal::AggregateType<bool, boolean>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.AsyncOperationCompletedHandler`1<Boolean>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IAsyncOperationCompletedHandler<bool> __FIAsyncOperationCompletedHandler_1_boolean_t;
#define __FIAsyncOperationCompletedHandler_1_boolean ABI::Windows::Foundation::__FIAsyncOperationCompletedHandler_1_boolean_t
/* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIAsyncOperationCompletedHandler_1_boolean_USE */


namespace ABI {
    namespace Windows {
        namespace Foundation {
            namespace Collections {
                class ValueSet;
            } /* Collections */
        } /* Foundation */
    } /* Windows */
} /* ABI */

#ifndef ____x_ABI_CWindows_CFoundation_CCollections_CIPropertySet_FWD_DEFINED__
#define ____x_ABI_CWindows_CFoundation_CCollections_CIPropertySet_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Foundation {
            namespace Collections {
                interface IPropertySet;
            } /* Collections */
        } /* Foundation */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CFoundation_CCollections_CIPropertySet ABI::Windows::Foundation::Collections::IPropertySet

#endif // ____x_ABI_CWindows_CFoundation_CCollections_CIPropertySet_FWD_DEFINED__

namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                class PreviewBuildsManager;
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                class PreviewBuildsState;
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

/*
 *
 * Interface Windows.Management.Update.IPreviewBuildsManager
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 6.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.PreviewBuildsManager
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x60000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManager_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManager_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_IPreviewBuildsManager[] = L"Windows.Management.Update.IPreviewBuildsManager";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                MIDL_INTERFACE("fa07dd61-7e4f-59f7-7c9f-def9051c5f62")
                IPreviewBuildsManager : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE get_ArePreviewBuildsAllowed(
                        boolean* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_ArePreviewBuildsAllowed(
                        boolean value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE GetCurrentState(
                        ABI::Windows::Management::Update::IPreviewBuildsState** result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE SyncAsync(
                        __FIAsyncOperation_1_boolean** result
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IPreviewBuildsManager = _uuidof(IPreviewBuildsManager);
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManager;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManager_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x60000

/*
 *
 * Interface Windows.Management.Update.IPreviewBuildsManagerStatics
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 6.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.PreviewBuildsManager
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x60000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManagerStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManagerStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_IPreviewBuildsManagerStatics[] = L"Windows.Management.Update.IPreviewBuildsManagerStatics";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                MIDL_INTERFACE("3e422887-b112-5a70-7da1-97d78d32aa29")
                IPreviewBuildsManagerStatics : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE GetDefault(
                        ABI::Windows::Management::Update::IPreviewBuildsManager** value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE IsSupported(
                        boolean* result
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IPreviewBuildsManagerStatics = _uuidof(IPreviewBuildsManagerStatics);
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManagerStatics;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManagerStatics_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x60000

/*
 *
 * Interface Windows.Management.Update.IPreviewBuildsState
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 6.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.PreviewBuildsState
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x60000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsState_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsState_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_IPreviewBuildsState[] = L"Windows.Management.Update.IPreviewBuildsState";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                MIDL_INTERFACE("a2f2903e-b223-5f63-7546-3e8eac070a2e")
                IPreviewBuildsState : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE get_Properties(
                        ABI::Windows::Foundation::Collections::IPropertySet** value
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IPreviewBuildsState = _uuidof(IPreviewBuildsState);
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsState;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsState_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x60000

/*
 *
 * Class Windows.Management.Update.PreviewBuildsManager
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 6.0
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Windows.Management.Update.IPreviewBuildsManagerStatics interface starting with version 6.0 of the Windows.Foundation.UniversalApiContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Management.Update.IPreviewBuildsManager ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x60000
#ifndef RUNTIMECLASS_Windows_Management_Update_PreviewBuildsManager_DEFINED
#define RUNTIMECLASS_Windows_Management_Update_PreviewBuildsManager_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Update_PreviewBuildsManager[] = L"Windows.Management.Update.PreviewBuildsManager";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x60000

/*
 *
 * Class Windows.Management.Update.PreviewBuildsState
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 6.0
 *
 * Class implements the following interfaces:
 *    Windows.Management.Update.IPreviewBuildsState ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x60000
#ifndef RUNTIMECLASS_Windows_Management_Update_PreviewBuildsState_DEFINED
#define RUNTIMECLASS_Windows_Management_Update_PreviewBuildsState_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Update_PreviewBuildsState[] = L"Windows.Management.Update.PreviewBuildsState";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x60000

#else // !defined(__cplusplus)
/* Forward Declarations */
#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManager_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManager_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManager __x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManager;

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManager_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManagerStatics_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManagerStatics_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManagerStatics __x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManagerStatics;

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManagerStatics_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsState_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsState_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsState __x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsState;

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsState_FWD_DEFINED__

// Parameterized interface forward declarations (C)

// Collection interface definitions

typedef interface __FIAsyncOperationCompletedHandler_1_boolean __FIAsyncOperationCompletedHandler_1_boolean;

#if !defined(____FIAsyncOperation_1_boolean_INTERFACE_DEFINED__)
#define ____FIAsyncOperation_1_boolean_INTERFACE_DEFINED__

typedef interface __FIAsyncOperation_1_boolean __FIAsyncOperation_1_boolean;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIAsyncOperation_1_boolean;

typedef struct __FIAsyncOperation_1_booleanVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIAsyncOperation_1_boolean* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIAsyncOperation_1_boolean* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIAsyncOperation_1_boolean* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIAsyncOperation_1_boolean* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIAsyncOperation_1_boolean* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIAsyncOperation_1_boolean* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* put_Completed)(__FIAsyncOperation_1_boolean* This,
        __FIAsyncOperationCompletedHandler_1_boolean* handler);
    HRESULT (STDMETHODCALLTYPE* get_Completed)(__FIAsyncOperation_1_boolean* This,
        __FIAsyncOperationCompletedHandler_1_boolean** result);
    HRESULT (STDMETHODCALLTYPE* GetResults)(__FIAsyncOperation_1_boolean* This,
        boolean* result);

    END_INTERFACE
} __FIAsyncOperation_1_booleanVtbl;

interface __FIAsyncOperation_1_boolean
{
    CONST_VTBL struct __FIAsyncOperation_1_booleanVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIAsyncOperation_1_boolean_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIAsyncOperation_1_boolean_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIAsyncOperation_1_boolean_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIAsyncOperation_1_boolean_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIAsyncOperation_1_boolean_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIAsyncOperation_1_boolean_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIAsyncOperation_1_boolean_put_Completed(This, handler) \
    ((This)->lpVtbl->put_Completed(This, handler))

#define __FIAsyncOperation_1_boolean_get_Completed(This, result) \
    ((This)->lpVtbl->get_Completed(This, result))

#define __FIAsyncOperation_1_boolean_GetResults(This, result) \
    ((This)->lpVtbl->GetResults(This, result))

#endif /* COBJMACROS */

#endif // ____FIAsyncOperation_1_boolean_INTERFACE_DEFINED__

#if !defined(____FIAsyncOperationCompletedHandler_1_boolean_INTERFACE_DEFINED__)
#define ____FIAsyncOperationCompletedHandler_1_boolean_INTERFACE_DEFINED__

typedef interface __FIAsyncOperationCompletedHandler_1_boolean __FIAsyncOperationCompletedHandler_1_boolean;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIAsyncOperationCompletedHandler_1_boolean;

typedef struct __FIAsyncOperationCompletedHandler_1_booleanVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIAsyncOperationCompletedHandler_1_boolean* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIAsyncOperationCompletedHandler_1_boolean* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIAsyncOperationCompletedHandler_1_boolean* This);
    HRESULT (STDMETHODCALLTYPE* Invoke)(__FIAsyncOperationCompletedHandler_1_boolean* This,
        __FIAsyncOperation_1_boolean* asyncInfo,
        AsyncStatus asyncStatus);

    END_INTERFACE
} __FIAsyncOperationCompletedHandler_1_booleanVtbl;

interface __FIAsyncOperationCompletedHandler_1_boolean
{
    CONST_VTBL struct __FIAsyncOperationCompletedHandler_1_booleanVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIAsyncOperationCompletedHandler_1_boolean_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIAsyncOperationCompletedHandler_1_boolean_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIAsyncOperationCompletedHandler_1_boolean_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIAsyncOperationCompletedHandler_1_boolean_Invoke(This, asyncInfo, asyncStatus) \
    ((This)->lpVtbl->Invoke(This, asyncInfo, asyncStatus))

#endif /* COBJMACROS */

#endif // ____FIAsyncOperationCompletedHandler_1_boolean_INTERFACE_DEFINED__

#ifndef ____x_ABI_CWindows_CFoundation_CCollections_CIPropertySet_FWD_DEFINED__
#define ____x_ABI_CWindows_CFoundation_CCollections_CIPropertySet_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CFoundation_CCollections_CIPropertySet __x_ABI_CWindows_CFoundation_CCollections_CIPropertySet;

#endif // ____x_ABI_CWindows_CFoundation_CCollections_CIPropertySet_FWD_DEFINED__

/*
 *
 * Interface Windows.Management.Update.IPreviewBuildsManager
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 6.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.PreviewBuildsManager
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x60000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManager_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManager_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_IPreviewBuildsManager[] = L"Windows.Management.Update.IPreviewBuildsManager";
typedef struct __x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManagerVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManager* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManager* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManager* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManager* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManager* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManager* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_ArePreviewBuildsAllowed)(__x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManager* This,
        boolean* value);
    HRESULT (STDMETHODCALLTYPE* put_ArePreviewBuildsAllowed)(__x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManager* This,
        boolean value);
    HRESULT (STDMETHODCALLTYPE* GetCurrentState)(__x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManager* This,
        __x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsState** result);
    HRESULT (STDMETHODCALLTYPE* SyncAsync)(__x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManager* This,
        __FIAsyncOperation_1_boolean** result);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManagerVtbl;

interface __x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManager
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManagerVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManager_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManager_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManager_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManager_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManager_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManager_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManager_get_ArePreviewBuildsAllowed(This, value) \
    ((This)->lpVtbl->get_ArePreviewBuildsAllowed(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManager_put_ArePreviewBuildsAllowed(This, value) \
    ((This)->lpVtbl->put_ArePreviewBuildsAllowed(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManager_GetCurrentState(This, result) \
    ((This)->lpVtbl->GetCurrentState(This, result))

#define __x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManager_SyncAsync(This, result) \
    ((This)->lpVtbl->SyncAsync(This, result))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManager;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManager_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x60000

/*
 *
 * Interface Windows.Management.Update.IPreviewBuildsManagerStatics
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 6.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.PreviewBuildsManager
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x60000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManagerStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManagerStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_IPreviewBuildsManagerStatics[] = L"Windows.Management.Update.IPreviewBuildsManagerStatics";
typedef struct __x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManagerStaticsVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManagerStatics* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManagerStatics* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManagerStatics* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManagerStatics* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManagerStatics* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManagerStatics* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* GetDefault)(__x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManagerStatics* This,
        __x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManager** value);
    HRESULT (STDMETHODCALLTYPE* IsSupported)(__x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManagerStatics* This,
        boolean* result);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManagerStaticsVtbl;

interface __x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManagerStatics
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManagerStaticsVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManagerStatics_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManagerStatics_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManagerStatics_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManagerStatics_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManagerStatics_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManagerStatics_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManagerStatics_GetDefault(This, value) \
    ((This)->lpVtbl->GetDefault(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManagerStatics_IsSupported(This, result) \
    ((This)->lpVtbl->IsSupported(This, result))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManagerStatics;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsManagerStatics_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x60000

/*
 *
 * Interface Windows.Management.Update.IPreviewBuildsState
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 6.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.PreviewBuildsState
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x60000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsState_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsState_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_IPreviewBuildsState[] = L"Windows.Management.Update.IPreviewBuildsState";
typedef struct __x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsStateVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsState* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsState* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsState* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsState* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsState* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsState* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Properties)(__x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsState* This,
        __x_ABI_CWindows_CFoundation_CCollections_CIPropertySet** value);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsStateVtbl;

interface __x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsState
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsStateVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsState_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsState_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsState_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsState_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsState_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsState_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsState_get_Properties(This, value) \
    ((This)->lpVtbl->get_Properties(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsState;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CIPreviewBuildsState_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x60000

/*
 *
 * Class Windows.Management.Update.PreviewBuildsManager
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 6.0
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Windows.Management.Update.IPreviewBuildsManagerStatics interface starting with version 6.0 of the Windows.Foundation.UniversalApiContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Management.Update.IPreviewBuildsManager ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x60000
#ifndef RUNTIMECLASS_Windows_Management_Update_PreviewBuildsManager_DEFINED
#define RUNTIMECLASS_Windows_Management_Update_PreviewBuildsManager_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Update_PreviewBuildsManager[] = L"Windows.Management.Update.PreviewBuildsManager";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x60000

/*
 *
 * Class Windows.Management.Update.PreviewBuildsState
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 6.0
 *
 * Class implements the following interfaces:
 *    Windows.Management.Update.IPreviewBuildsState ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x60000
#ifndef RUNTIMECLASS_Windows_Management_Update_PreviewBuildsState_DEFINED
#define RUNTIMECLASS_Windows_Management_Update_PreviewBuildsState_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Update_PreviewBuildsState[] = L"Windows.Management.Update.PreviewBuildsState";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x60000

#endif // defined(__cplusplus)
#pragma pop_macro("MIDL_CONST_ID")
// Restore the original value of the 'DEPRECATED' macro
#pragma pop_macro("DEPRECATED")

#ifdef __clang__
#pragma clang diagnostic pop // deprecated-declarations
#else
#pragma warning(pop)
#endif
#endif // __windows2Emanagement2Eupdate_p_h__

#endif // __windows2Emanagement2Eupdate_h__
