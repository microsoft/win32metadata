
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
#define WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION 0xf0000
#endif // defined(WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION)

#if !defined(WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION)
#define WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION 0x10000
#endif // defined(WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION)

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

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                interface IWindowsUpdate;
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate ABI::Windows::Management::Update::IWindowsUpdate

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionCompletedEventArgs_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionCompletedEventArgs_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                interface IWindowsUpdateActionCompletedEventArgs;
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionCompletedEventArgs ABI::Windows::Management::Update::IWindowsUpdateActionCompletedEventArgs

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionCompletedEventArgs_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionProgress_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionProgress_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                interface IWindowsUpdateActionProgress;
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionProgress ABI::Windows::Management::Update::IWindowsUpdateActionProgress

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionProgress_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionResult_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionResult_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                interface IWindowsUpdateActionResult;
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionResult ABI::Windows::Management::Update::IWindowsUpdateActionResult

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionResult_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministrator_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministrator_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                interface IWindowsUpdateAdministrator;
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministrator ABI::Windows::Management::Update::IWindowsUpdateAdministrator

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministrator_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministratorStatics_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministratorStatics_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                interface IWindowsUpdateAdministratorStatics;
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministratorStatics ABI::Windows::Management::Update::IWindowsUpdateAdministratorStatics

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministratorStatics_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateApprovalData_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateApprovalData_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                interface IWindowsUpdateApprovalData;
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateApprovalData ABI::Windows::Management::Update::IWindowsUpdateApprovalData

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateApprovalData_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAttentionRequiredInfo_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAttentionRequiredInfo_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                interface IWindowsUpdateAttentionRequiredInfo;
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAttentionRequiredInfo ABI::Windows::Management::Update::IWindowsUpdateAttentionRequiredInfo

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAttentionRequiredInfo_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAttentionRequiredReasonChangedEventArgs_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAttentionRequiredReasonChangedEventArgs_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                interface IWindowsUpdateAttentionRequiredReasonChangedEventArgs;
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAttentionRequiredReasonChangedEventArgs ABI::Windows::Management::Update::IWindowsUpdateAttentionRequiredReasonChangedEventArgs

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAttentionRequiredReasonChangedEventArgs_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateGetAdministratorResult_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateGetAdministratorResult_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                interface IWindowsUpdateGetAdministratorResult;
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateGetAdministratorResult ABI::Windows::Management::Update::IWindowsUpdateGetAdministratorResult

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateGetAdministratorResult_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateItem_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateItem_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                interface IWindowsUpdateItem;
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateItem ABI::Windows::Management::Update::IWindowsUpdateItem

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateItem_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManager_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManager_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                interface IWindowsUpdateManager;
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManager ABI::Windows::Management::Update::IWindowsUpdateManager

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManager_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManagerFactory_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManagerFactory_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                interface IWindowsUpdateManagerFactory;
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManagerFactory ABI::Windows::Management::Update::IWindowsUpdateManagerFactory

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManagerFactory_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateProgressChangedEventArgs_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateProgressChangedEventArgs_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                interface IWindowsUpdateProgressChangedEventArgs;
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateProgressChangedEventArgs ABI::Windows::Management::Update::IWindowsUpdateProgressChangedEventArgs

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateProgressChangedEventArgs_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptions_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptions_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                interface IWindowsUpdateRestartRequestOptions;
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptions ABI::Windows::Management::Update::IWindowsUpdateRestartRequestOptions

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptions_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptionsFactory_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptionsFactory_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                interface IWindowsUpdateRestartRequestOptionsFactory;
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptionsFactory ABI::Windows::Management::Update::IWindowsUpdateRestartRequestOptionsFactory

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptionsFactory_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateScanCompletedEventArgs_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateScanCompletedEventArgs_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                interface IWindowsUpdateScanCompletedEventArgs;
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateScanCompletedEventArgs ABI::Windows::Management::Update::IWindowsUpdateScanCompletedEventArgs

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateScanCompletedEventArgs_FWD_DEFINED__

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
        namespace Management {
            namespace Update {
                class WindowsUpdateItem;
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

#ifndef DEF___FIIterator_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_USE
#define DEF___FIIterator_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("0f903002-8142-5dc4-8078-7929a6ebfba0"))
IIterator<ABI::Windows::Management::Update::WindowsUpdateItem*> : IIterator_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Management::Update::WindowsUpdateItem*, ABI::Windows::Management::Update::IWindowsUpdateItem*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IIterator`1<Windows.Management.Update.WindowsUpdateItem>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterator<ABI::Windows::Management::Update::WindowsUpdateItem*> __FIIterator_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_t;
#define __FIIterator_1_Windows__CManagement__CUpdate__CWindowsUpdateItem ABI::Windows::Foundation::Collections::__FIIterator_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterator_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_USE */

#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

#ifndef DEF___FIIterable_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_USE
#define DEF___FIIterable_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("73336bf8-168c-50c4-8cf9-ae7c2d14fd2e"))
IIterable<ABI::Windows::Management::Update::WindowsUpdateItem*> : IIterable_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Management::Update::WindowsUpdateItem*, ABI::Windows::Management::Update::IWindowsUpdateItem*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IIterable`1<Windows.Management.Update.WindowsUpdateItem>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterable<ABI::Windows::Management::Update::WindowsUpdateItem*> __FIIterable_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_t;
#define __FIIterable_1_Windows__CManagement__CUpdate__CWindowsUpdateItem ABI::Windows::Foundation::Collections::__FIIterable_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterable_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_USE */

#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

#ifndef DEF___FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_USE
#define DEF___FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("8faa5cdf-6b97-5d4f-804d-443b4fbbdc53"))
IVectorView<ABI::Windows::Management::Update::WindowsUpdateItem*> : IVectorView_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Management::Update::WindowsUpdateItem*, ABI::Windows::Management::Update::IWindowsUpdateItem*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IVectorView`1<Windows.Management.Update.WindowsUpdateItem>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IVectorView<ABI::Windows::Management::Update::WindowsUpdateItem*> __FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_t;
#define __FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem ABI::Windows::Foundation::Collections::__FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_USE */

#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

#ifndef DEF___FIAsyncOperation_1___FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_USE
#define DEF___FIAsyncOperation_1___FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation {
template <>
struct __declspec(uuid("6fe7014f-431a-5203-9574-5246fc49d6bb"))
IAsyncOperation<__FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem*> : IAsyncOperation_impl<__FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem*>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.IAsyncOperation`1<Windows.Foundation.Collections.IVectorView`1<Windows.Management.Update.WindowsUpdateItem>>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IAsyncOperation<__FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem*> __FIAsyncOperation_1___FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_t;
#define __FIAsyncOperation_1___FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem ABI::Windows::Foundation::__FIAsyncOperation_1___FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_t
/* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIAsyncOperation_1___FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_USE */

#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

#ifndef DEF___FIAsyncOperationCompletedHandler_1___FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_USE
#define DEF___FIAsyncOperationCompletedHandler_1___FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation {
template <>
struct __declspec(uuid("958afbc1-54db-5352-a899-d4fca044a6d4"))
IAsyncOperationCompletedHandler<__FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem*> : IAsyncOperationCompletedHandler_impl<__FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem*>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.AsyncOperationCompletedHandler`1<Windows.Foundation.Collections.IVectorView`1<Windows.Management.Update.WindowsUpdateItem>>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IAsyncOperationCompletedHandler<__FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem*> __FIAsyncOperationCompletedHandler_1___FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_t;
#define __FIAsyncOperationCompletedHandler_1___FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem ABI::Windows::Foundation::__FIAsyncOperationCompletedHandler_1___FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_t
/* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIAsyncOperationCompletedHandler_1___FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_USE */

#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                class WindowsUpdate;
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

#ifndef DEF___FIIterator_1_Windows__CManagement__CUpdate__CWindowsUpdate_USE
#define DEF___FIIterator_1_Windows__CManagement__CUpdate__CWindowsUpdate_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("b3c6c75d-acc8-5450-b138-7d0e4780e1a5"))
IIterator<ABI::Windows::Management::Update::WindowsUpdate*> : IIterator_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Management::Update::WindowsUpdate*, ABI::Windows::Management::Update::IWindowsUpdate*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IIterator`1<Windows.Management.Update.WindowsUpdate>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterator<ABI::Windows::Management::Update::WindowsUpdate*> __FIIterator_1_Windows__CManagement__CUpdate__CWindowsUpdate_t;
#define __FIIterator_1_Windows__CManagement__CUpdate__CWindowsUpdate ABI::Windows::Foundation::Collections::__FIIterator_1_Windows__CManagement__CUpdate__CWindowsUpdate_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterator_1_Windows__CManagement__CUpdate__CWindowsUpdate_USE */

#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

#ifndef DEF___FIIterable_1_Windows__CManagement__CUpdate__CWindowsUpdate_USE
#define DEF___FIIterable_1_Windows__CManagement__CUpdate__CWindowsUpdate_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("7adc510b-32d8-5b1d-908a-27ca443a880c"))
IIterable<ABI::Windows::Management::Update::WindowsUpdate*> : IIterable_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Management::Update::WindowsUpdate*, ABI::Windows::Management::Update::IWindowsUpdate*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IIterable`1<Windows.Management.Update.WindowsUpdate>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterable<ABI::Windows::Management::Update::WindowsUpdate*> __FIIterable_1_Windows__CManagement__CUpdate__CWindowsUpdate_t;
#define __FIIterable_1_Windows__CManagement__CUpdate__CWindowsUpdate ABI::Windows::Foundation::Collections::__FIIterable_1_Windows__CManagement__CUpdate__CWindowsUpdate_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterable_1_Windows__CManagement__CUpdate__CWindowsUpdate_USE */

#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

#ifndef DEF___FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdate_USE
#define DEF___FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdate_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("1eef9339-6038-5751-b5ae-bd89c17a8741"))
IVectorView<ABI::Windows::Management::Update::WindowsUpdate*> : IVectorView_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Management::Update::WindowsUpdate*, ABI::Windows::Management::Update::IWindowsUpdate*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IVectorView`1<Windows.Management.Update.WindowsUpdate>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IVectorView<ABI::Windows::Management::Update::WindowsUpdate*> __FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdate_t;
#define __FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdate ABI::Windows::Foundation::Collections::__FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdate_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdate_USE */

#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000


#ifndef DEF___FIReference_1_boolean_USE
#define DEF___FIReference_1_boolean_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation {
template <>
struct __declspec(uuid("3c00fd60-2950-5939-a21a-2d12c5a01b8a"))
IReference<bool> : IReference_impl<ABI::Windows::Foundation::Internal::AggregateType<bool, boolean>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.IReference`1<Boolean>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IReference<bool> __FIReference_1_boolean_t;
#define __FIReference_1_boolean ABI::Windows::Foundation::__FIReference_1_boolean_t
/* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIReference_1_boolean_USE */



#ifndef DEF___FIReference_1_int_USE
#define DEF___FIReference_1_int_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation {
template <>
struct __declspec(uuid("548cefbd-bc8a-5fa0-8df2-957440fc8bf4"))
IReference<int> : IReference_impl<int>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.IReference`1<Int32>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IReference<int> __FIReference_1_int_t;
#define __FIReference_1_int ABI::Windows::Foundation::__FIReference_1_int_t
/* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIReference_1_int_USE */


namespace ABI {
    namespace Windows {
        namespace Foundation {
            typedef struct DateTime DateTime;
        } /* Foundation */
    } /* Windows */
} /* ABI */

#if WINDOWS_FOUNDATION_FOUNDATIONCONTRACT_VERSION >= 0x10000

#ifndef DEF___FIReference_1_Windows__CFoundation__CDateTime_USE
#define DEF___FIReference_1_Windows__CFoundation__CDateTime_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation {
template <>
struct __declspec(uuid("5541d8a7-497c-5aa4-86fc-7713adbf2a2c"))
IReference<struct ABI::Windows::Foundation::DateTime> : IReference_impl<struct ABI::Windows::Foundation::DateTime>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.IReference`1<Windows.Foundation.DateTime>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IReference<struct ABI::Windows::Foundation::DateTime> __FIReference_1_Windows__CFoundation__CDateTime_t;
#define __FIReference_1_Windows__CFoundation__CDateTime ABI::Windows::Foundation::__FIReference_1_Windows__CFoundation__CDateTime_t
/* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIReference_1_Windows__CFoundation__CDateTime_USE */

#endif // WINDOWS_FOUNDATION_FOUNDATIONCONTRACT_VERSION >= 0x10000

namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                class WindowsUpdateManager;
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

#ifndef DEF___FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_IInspectable_USE
#define DEF___FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_IInspectable_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation {
template <>
struct __declspec(uuid("b95a0a5d-28f1-50f5-914a-b55a1a84dcd8"))
ITypedEventHandler<ABI::Windows::Management::Update::WindowsUpdateManager*, IInspectable*> : ITypedEventHandler_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Management::Update::WindowsUpdateManager*, ABI::Windows::Management::Update::IWindowsUpdateManager*>, IInspectable*>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.TypedEventHandler`2<Windows.Management.Update.WindowsUpdateManager, Object>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef ITypedEventHandler<ABI::Windows::Management::Update::WindowsUpdateManager*, IInspectable*> __FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_IInspectable_t;
#define __FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_IInspectable ABI::Windows::Foundation::__FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_IInspectable_t
/* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_IInspectable_USE */

#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                class WindowsUpdateActionCompletedEventArgs;
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

#ifndef DEF___FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateActionCompletedEventArgs_USE
#define DEF___FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateActionCompletedEventArgs_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation {
template <>
struct __declspec(uuid("a4f8bb0a-4633-5c2c-b4a2-5047e201cf07"))
ITypedEventHandler<ABI::Windows::Management::Update::WindowsUpdateManager*, ABI::Windows::Management::Update::WindowsUpdateActionCompletedEventArgs*> : ITypedEventHandler_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Management::Update::WindowsUpdateManager*, ABI::Windows::Management::Update::IWindowsUpdateManager*>, ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Management::Update::WindowsUpdateActionCompletedEventArgs*, ABI::Windows::Management::Update::IWindowsUpdateActionCompletedEventArgs*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.TypedEventHandler`2<Windows.Management.Update.WindowsUpdateManager, Windows.Management.Update.WindowsUpdateActionCompletedEventArgs>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef ITypedEventHandler<ABI::Windows::Management::Update::WindowsUpdateManager*, ABI::Windows::Management::Update::WindowsUpdateActionCompletedEventArgs*> __FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateActionCompletedEventArgs_t;
#define __FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateActionCompletedEventArgs ABI::Windows::Foundation::__FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateActionCompletedEventArgs_t
/* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateActionCompletedEventArgs_USE */

#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                class WindowsUpdateAttentionRequiredReasonChangedEventArgs;
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

#ifndef DEF___FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateAttentionRequiredReasonChangedEventArgs_USE
#define DEF___FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateAttentionRequiredReasonChangedEventArgs_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation {
template <>
struct __declspec(uuid("1b44e3b5-e822-5c75-85a9-4a3983bebdd8"))
ITypedEventHandler<ABI::Windows::Management::Update::WindowsUpdateManager*, ABI::Windows::Management::Update::WindowsUpdateAttentionRequiredReasonChangedEventArgs*> : ITypedEventHandler_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Management::Update::WindowsUpdateManager*, ABI::Windows::Management::Update::IWindowsUpdateManager*>, ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Management::Update::WindowsUpdateAttentionRequiredReasonChangedEventArgs*, ABI::Windows::Management::Update::IWindowsUpdateAttentionRequiredReasonChangedEventArgs*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.TypedEventHandler`2<Windows.Management.Update.WindowsUpdateManager, Windows.Management.Update.WindowsUpdateAttentionRequiredReasonChangedEventArgs>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef ITypedEventHandler<ABI::Windows::Management::Update::WindowsUpdateManager*, ABI::Windows::Management::Update::WindowsUpdateAttentionRequiredReasonChangedEventArgs*> __FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateAttentionRequiredReasonChangedEventArgs_t;
#define __FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateAttentionRequiredReasonChangedEventArgs ABI::Windows::Foundation::__FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateAttentionRequiredReasonChangedEventArgs_t
/* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateAttentionRequiredReasonChangedEventArgs_USE */

#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                class WindowsUpdateProgressChangedEventArgs;
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

#ifndef DEF___FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateProgressChangedEventArgs_USE
#define DEF___FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateProgressChangedEventArgs_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation {
template <>
struct __declspec(uuid("61f35a11-50a1-5199-ac17-75206872fc4d"))
ITypedEventHandler<ABI::Windows::Management::Update::WindowsUpdateManager*, ABI::Windows::Management::Update::WindowsUpdateProgressChangedEventArgs*> : ITypedEventHandler_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Management::Update::WindowsUpdateManager*, ABI::Windows::Management::Update::IWindowsUpdateManager*>, ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Management::Update::WindowsUpdateProgressChangedEventArgs*, ABI::Windows::Management::Update::IWindowsUpdateProgressChangedEventArgs*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.TypedEventHandler`2<Windows.Management.Update.WindowsUpdateManager, Windows.Management.Update.WindowsUpdateProgressChangedEventArgs>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef ITypedEventHandler<ABI::Windows::Management::Update::WindowsUpdateManager*, ABI::Windows::Management::Update::WindowsUpdateProgressChangedEventArgs*> __FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateProgressChangedEventArgs_t;
#define __FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateProgressChangedEventArgs ABI::Windows::Foundation::__FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateProgressChangedEventArgs_t
/* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateProgressChangedEventArgs_USE */

#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                class WindowsUpdateScanCompletedEventArgs;
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

#ifndef DEF___FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateScanCompletedEventArgs_USE
#define DEF___FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateScanCompletedEventArgs_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation {
template <>
struct __declspec(uuid("74625656-399b-5686-b24d-349f57880690"))
ITypedEventHandler<ABI::Windows::Management::Update::WindowsUpdateManager*, ABI::Windows::Management::Update::WindowsUpdateScanCompletedEventArgs*> : ITypedEventHandler_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Management::Update::WindowsUpdateManager*, ABI::Windows::Management::Update::IWindowsUpdateManager*>, ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Management::Update::WindowsUpdateScanCompletedEventArgs*, ABI::Windows::Management::Update::IWindowsUpdateScanCompletedEventArgs*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.TypedEventHandler`2<Windows.Management.Update.WindowsUpdateManager, Windows.Management.Update.WindowsUpdateScanCompletedEventArgs>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef ITypedEventHandler<ABI::Windows::Management::Update::WindowsUpdateManager*, ABI::Windows::Management::Update::WindowsUpdateScanCompletedEventArgs*> __FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateScanCompletedEventArgs_t;
#define __FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateScanCompletedEventArgs ABI::Windows::Foundation::__FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateScanCompletedEventArgs_t
/* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateScanCompletedEventArgs_USE */

#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

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

#ifndef ____x_ABI_CWindows_CFoundation_CIPropertyValue_FWD_DEFINED__
#define ____x_ABI_CWindows_CFoundation_CIPropertyValue_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Foundation {
            interface IPropertyValue;
        } /* Foundation */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CFoundation_CIPropertyValue ABI::Windows::Foundation::IPropertyValue

#endif // ____x_ABI_CWindows_CFoundation_CIPropertyValue_FWD_DEFINED__

namespace ABI {
    namespace Windows {
        namespace Foundation {
            class Uri;
        } /* Foundation */
    } /* Windows */
} /* ABI */

#ifndef ____x_ABI_CWindows_CFoundation_CIUriRuntimeClass_FWD_DEFINED__
#define ____x_ABI_CWindows_CFoundation_CIUriRuntimeClass_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Foundation {
            interface IUriRuntimeClass;
        } /* Foundation */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CFoundation_CIUriRuntimeClass ABI::Windows::Foundation::IUriRuntimeClass

#endif // ____x_ABI_CWindows_CFoundation_CIUriRuntimeClass_FWD_DEFINED__

namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                typedef enum WindowsUpdateAdministratorOptions : unsigned int WindowsUpdateAdministratorOptions;
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                typedef enum WindowsUpdateAdministratorStatus : int WindowsUpdateAdministratorStatus;
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                typedef enum WindowsUpdateAttentionRequiredReason : int WindowsUpdateAttentionRequiredReason;
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

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

namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                class WindowsUpdateActionProgress;
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                class WindowsUpdateActionResult;
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                class WindowsUpdateAdministrator;
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                class WindowsUpdateApprovalData;
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                class WindowsUpdateAttentionRequiredInfo;
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                class WindowsUpdateGetAdministratorResult;
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                class WindowsUpdateRestartRequestOptions;
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

/*
 *
 * Struct Windows.Management.Update.WindowsUpdateAdministratorOptions
 *
 * Introduced to Windows.Management.Update.WindowsUpdateContract in version 1.0
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                enum WindowsUpdateAdministratorOptions : unsigned int
                {
                    WindowsUpdateAdministratorOptions_None = 0,
                    WindowsUpdateAdministratorOptions_RequireAdministratorApprovalForScans = 0x1,
                    WindowsUpdateAdministratorOptions_RequireAdministratorApprovalForUpdates = 0x2,
                    WindowsUpdateAdministratorOptions_RequireAdministratorApprovalForActions = 0x4,
                };

                DEFINE_ENUM_FLAG_OPERATORS(WindowsUpdateAdministratorOptions)
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

/*
 *
 * Struct Windows.Management.Update.WindowsUpdateAdministratorStatus
 *
 * Introduced to Windows.Management.Update.WindowsUpdateContract in version 1.0
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                enum WindowsUpdateAdministratorStatus : int
                {
                    WindowsUpdateAdministratorStatus_Succeeded = 0,
                    WindowsUpdateAdministratorStatus_NoAdministratorRegistered = 1,
                    WindowsUpdateAdministratorStatus_OtherAdministratorIsRegistered = 2,
                };
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

/*
 *
 * Struct Windows.Management.Update.WindowsUpdateAttentionRequiredReason
 *
 * Introduced to Windows.Management.Update.WindowsUpdateContract in version 1.0
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                enum WindowsUpdateAttentionRequiredReason : int
                {
                    WindowsUpdateAttentionRequiredReason_None = 0,
                    WindowsUpdateAttentionRequiredReason_SeekerUpdate = 1,
                    WindowsUpdateAttentionRequiredReason_ReadyToReboot = 2,
                    WindowsUpdateAttentionRequiredReason_NeedNonMeteredNetwork = 3,
                    WindowsUpdateAttentionRequiredReason_NeedUserAgreementForMeteredNetwork = 4,
                    WindowsUpdateAttentionRequiredReason_NeedNetwork = 5,
                    WindowsUpdateAttentionRequiredReason_NeedMoreSpace = 6,
                    WindowsUpdateAttentionRequiredReason_BatterySaverEnabled = 7,
                    WindowsUpdateAttentionRequiredReason_NeedUserInteraction = 8,
                    WindowsUpdateAttentionRequiredReason_NeedUserAgreementForPolicy = 9,
                    WindowsUpdateAttentionRequiredReason_CompatibilityError = 10,
                    WindowsUpdateAttentionRequiredReason_NeedUserInteractionForEula = 11,
                    WindowsUpdateAttentionRequiredReason_NeedUserInteractionForCta = 12,
                    WindowsUpdateAttentionRequiredReason_Regulated = 13,
                    WindowsUpdateAttentionRequiredReason_ExternalReboot = 14,
                    WindowsUpdateAttentionRequiredReason_OtherUpdate = 15,
                    WindowsUpdateAttentionRequiredReason_BlockedByProvider = 16,
                    WindowsUpdateAttentionRequiredReason_BlockedByPostRebootFailure = 17,
                    WindowsUpdateAttentionRequiredReason_UserEngaged = 18,
                    WindowsUpdateAttentionRequiredReason_BlockedByBattery = 19,
                    WindowsUpdateAttentionRequiredReason_Exclusivity = 20,
                    WindowsUpdateAttentionRequiredReason_BlockedBySerialization = 21,
                    WindowsUpdateAttentionRequiredReason_ConflictClass = 22,
                    WindowsUpdateAttentionRequiredReason_BlockedByAdminApproval = 23,
                    WindowsUpdateAttentionRequiredReason_BlockedByTooManyAttempts = 24,
                    WindowsUpdateAttentionRequiredReason_BlockedByFailure = 25,
                    WindowsUpdateAttentionRequiredReason_Demotion = 26,
                    WindowsUpdateAttentionRequiredReason_BlockedByActiveHours = 27,
                    WindowsUpdateAttentionRequiredReason_ScheduledForMaintenance = 28,
                    WindowsUpdateAttentionRequiredReason_PolicyScheduledInstallTime = 29,
                    WindowsUpdateAttentionRequiredReason_BlockedByOobe = 30,
                    WindowsUpdateAttentionRequiredReason_DeferredDuringOobe = 31,
                    WindowsUpdateAttentionRequiredReason_DeferredForSustainableTime = 32,
                };
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

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
 * Interface Windows.Management.Update.IWindowsUpdate
 *
 * Introduced to Windows.Management.Update.WindowsUpdateContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.WindowsUpdate
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_IWindowsUpdate[] = L"Windows.Management.Update.IWindowsUpdate";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                MIDL_INTERFACE("c3c88dd7-0ef3-52b2-a9ad-66bfc6bd9582")
                IWindowsUpdate : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE get_ProviderId(
                        HSTRING* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_UpdateId(
                        HSTRING* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_Title(
                        HSTRING* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_Description(
                        HSTRING* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_IsFeatureUpdate(
                        boolean* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_IsMinorImpact(
                        boolean* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_IsSecurity(
                        boolean* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_IsCritical(
                        boolean* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_IsForOS(
                        boolean* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_IsDriver(
                        boolean* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_IsMandatory(
                        boolean* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_IsUrgent(
                        boolean* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_IsSeeker(
                        boolean* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_MoreInfoUrl(
                        ABI::Windows::Foundation::IUriRuntimeClass** value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_SupportUrl(
                        ABI::Windows::Foundation::IUriRuntimeClass** value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_IsEulaAccepted(
                        boolean* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_EulaText(
                        HSTRING* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_Deadline(
                        __FIReference_1_Windows__CFoundation__CDateTime** value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_AttentionRequiredInfo(
                        ABI::Windows::Management::Update::IWindowsUpdateAttentionRequiredInfo** value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_ActionResult(
                        ABI::Windows::Management::Update::IWindowsUpdateActionResult** value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_CurrentAction(
                        HSTRING* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_ActionProgress(
                        ABI::Windows::Management::Update::IWindowsUpdateActionProgress** value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE GetPropertyValue(
                        HSTRING propertyName,
                        IInspectable** result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE AcceptEula(void) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IWindowsUpdate = _uuidof(IWindowsUpdate);
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.IWindowsUpdateActionCompletedEventArgs
 *
 * Introduced to Windows.Management.Update.WindowsUpdateContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.WindowsUpdateActionCompletedEventArgs
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionCompletedEventArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionCompletedEventArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_IWindowsUpdateActionCompletedEventArgs[] = L"Windows.Management.Update.IWindowsUpdateActionCompletedEventArgs";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                MIDL_INTERFACE("2c44b950-a655-5321-aec1-aee762922131")
                IWindowsUpdateActionCompletedEventArgs : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE get_Update(
                        ABI::Windows::Management::Update::IWindowsUpdate** value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_Action(
                        HSTRING* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_Succeeded(
                        boolean* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_ExtendedError(
                        HRESULT* value
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IWindowsUpdateActionCompletedEventArgs = _uuidof(IWindowsUpdateActionCompletedEventArgs);
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionCompletedEventArgs;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionCompletedEventArgs_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.IWindowsUpdateActionProgress
 *
 * Introduced to Windows.Management.Update.WindowsUpdateContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.WindowsUpdateActionProgress
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionProgress_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionProgress_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_IWindowsUpdateActionProgress[] = L"Windows.Management.Update.IWindowsUpdateActionProgress";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                MIDL_INTERFACE("83b22d8a-4bb0-549f-ba39-59724882d137")
                IWindowsUpdateActionProgress : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE get_Action(
                        HSTRING* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_Progress(
                        DOUBLE* value
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IWindowsUpdateActionProgress = _uuidof(IWindowsUpdateActionProgress);
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionProgress;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionProgress_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.IWindowsUpdateActionResult
 *
 * Introduced to Windows.Management.Update.WindowsUpdateContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.WindowsUpdateActionResult
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionResult_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionResult_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_IWindowsUpdateActionResult[] = L"Windows.Management.Update.IWindowsUpdateActionResult";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                MIDL_INTERFACE("e6692c62-f697-51b7-ab7f-e73e5e688f12")
                IWindowsUpdateActionResult : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE get_Timestamp(
                        ABI::Windows::Foundation::DateTime* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_Succeeded(
                        boolean* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_ExtendedError(
                        HRESULT* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_Action(
                        HSTRING* value
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IWindowsUpdateActionResult = _uuidof(IWindowsUpdateActionResult);
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionResult;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionResult_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.IWindowsUpdateAdministrator
 *
 * Introduced to Windows.Management.Update.WindowsUpdateContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.WindowsUpdateAdministrator
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministrator_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministrator_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_IWindowsUpdateAdministrator[] = L"Windows.Management.Update.IWindowsUpdateAdministrator";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                MIDL_INTERFACE("7a60181c-ba1e-5cf9-aa65-304120b73d72")
                IWindowsUpdateAdministrator : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE StartAdministratorScan(void) = 0;
                    virtual HRESULT STDMETHODCALLTYPE ApproveWindowsUpdateAction(
                        HSTRING updateId,
                        HSTRING action
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE RevokeWindowsUpdateActionApproval(
                        HSTRING updateId,
                        HSTRING action
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE ApproveWindowsUpdate(
                        HSTRING updateId,
                        ABI::Windows::Management::Update::IWindowsUpdateApprovalData* approvalData
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE RevokeWindowsUpdateApproval(
                        HSTRING updateId
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE GetUpdates(
                        __FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdate** result
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IWindowsUpdateAdministrator = _uuidof(IWindowsUpdateAdministrator);
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministrator;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministrator_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.IWindowsUpdateAdministratorStatics
 *
 * Introduced to Windows.Management.Update.WindowsUpdateContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.WindowsUpdateAdministrator
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministratorStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministratorStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_IWindowsUpdateAdministratorStatics[] = L"Windows.Management.Update.IWindowsUpdateAdministratorStatics";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                MIDL_INTERFACE("013e6d36-ef69-53bc-8db8-c403bca550ed")
                IWindowsUpdateAdministratorStatics : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE GetRegisteredAdministrator(
                        HSTRING organizationName,
                        ABI::Windows::Management::Update::IWindowsUpdateGetAdministratorResult** result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE RegisterForAdministration(
                        HSTRING organizationName,
                        ABI::Windows::Management::Update::WindowsUpdateAdministratorOptions options,
                        ABI::Windows::Management::Update::WindowsUpdateAdministratorStatus* result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE UnregisterForAdministration(
                        HSTRING organizationName,
                        ABI::Windows::Management::Update::WindowsUpdateAdministratorStatus* result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE GetRegisteredAdministratorName(
                        HSTRING* result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE RequestRestart(
                        ABI::Windows::Management::Update::IWindowsUpdateRestartRequestOptions* restartOptions,
                        HSTRING* result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE CancelRestartRequest(
                        HSTRING requestRestartToken
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IWindowsUpdateAdministratorStatics = _uuidof(IWindowsUpdateAdministratorStatics);
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministratorStatics;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministratorStatics_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.IWindowsUpdateApprovalData
 *
 * Introduced to Windows.Management.Update.WindowsUpdateContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.WindowsUpdateApprovalData
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateApprovalData_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateApprovalData_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_IWindowsUpdateApprovalData[] = L"Windows.Management.Update.IWindowsUpdateApprovalData";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                MIDL_INTERFACE("aadf5bfd-84db-59bc-85e2-ad4fc1f62f7c")
                IWindowsUpdateApprovalData : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE get_Seeker(
                        __FIReference_1_boolean** value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_Seeker(
                        __FIReference_1_boolean* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_AllowDownloadOnMetered(
                        __FIReference_1_boolean** value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_AllowDownloadOnMetered(
                        __FIReference_1_boolean* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_ComplianceDeadlineInDays(
                        __FIReference_1_int** value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_ComplianceDeadlineInDays(
                        __FIReference_1_int* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_ComplianceGracePeriodInDays(
                        __FIReference_1_int** value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_ComplianceGracePeriodInDays(
                        __FIReference_1_int* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_OptOutOfAutoReboot(
                        __FIReference_1_boolean** value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_OptOutOfAutoReboot(
                        __FIReference_1_boolean* value
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IWindowsUpdateApprovalData = _uuidof(IWindowsUpdateApprovalData);
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateApprovalData;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateApprovalData_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.IWindowsUpdateAttentionRequiredInfo
 *
 * Introduced to Windows.Management.Update.WindowsUpdateContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.WindowsUpdateAttentionRequiredInfo
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAttentionRequiredInfo_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAttentionRequiredInfo_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_IWindowsUpdateAttentionRequiredInfo[] = L"Windows.Management.Update.IWindowsUpdateAttentionRequiredInfo";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                MIDL_INTERFACE("44df2579-74d3-5ffa-b6ce-09e187e1e0ed")
                IWindowsUpdateAttentionRequiredInfo : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE get_Reason(
                        ABI::Windows::Management::Update::WindowsUpdateAttentionRequiredReason* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_Timestamp(
                        __FIReference_1_Windows__CFoundation__CDateTime** value
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IWindowsUpdateAttentionRequiredInfo = _uuidof(IWindowsUpdateAttentionRequiredInfo);
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAttentionRequiredInfo;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAttentionRequiredInfo_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.IWindowsUpdateAttentionRequiredReasonChangedEventArgs
 *
 * Introduced to Windows.Management.Update.WindowsUpdateContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.WindowsUpdateAttentionRequiredReasonChangedEventArgs
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAttentionRequiredReasonChangedEventArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAttentionRequiredReasonChangedEventArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_IWindowsUpdateAttentionRequiredReasonChangedEventArgs[] = L"Windows.Management.Update.IWindowsUpdateAttentionRequiredReasonChangedEventArgs";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                MIDL_INTERFACE("0627abca-dbb8-524a-b1d2-d9df004eeb31")
                IWindowsUpdateAttentionRequiredReasonChangedEventArgs : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE get_Update(
                        ABI::Windows::Management::Update::IWindowsUpdate** value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_Reason(
                        ABI::Windows::Management::Update::WindowsUpdateAttentionRequiredReason* value
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IWindowsUpdateAttentionRequiredReasonChangedEventArgs = _uuidof(IWindowsUpdateAttentionRequiredReasonChangedEventArgs);
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAttentionRequiredReasonChangedEventArgs;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAttentionRequiredReasonChangedEventArgs_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.IWindowsUpdateGetAdministratorResult
 *
 * Introduced to Windows.Management.Update.WindowsUpdateContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.WindowsUpdateGetAdministratorResult
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateGetAdministratorResult_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateGetAdministratorResult_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_IWindowsUpdateGetAdministratorResult[] = L"Windows.Management.Update.IWindowsUpdateGetAdministratorResult";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                MIDL_INTERFACE("bb39ffc4-2c42-5b1c-8995-343341c92c50")
                IWindowsUpdateGetAdministratorResult : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE get_Administrator(
                        ABI::Windows::Management::Update::IWindowsUpdateAdministrator** value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_Status(
                        ABI::Windows::Management::Update::WindowsUpdateAdministratorStatus* value
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IWindowsUpdateGetAdministratorResult = _uuidof(IWindowsUpdateGetAdministratorResult);
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateGetAdministratorResult;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateGetAdministratorResult_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.IWindowsUpdateItem
 *
 * Introduced to Windows.Management.Update.WindowsUpdateContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.WindowsUpdateItem
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateItem_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateItem_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_IWindowsUpdateItem[] = L"Windows.Management.Update.IWindowsUpdateItem";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                MIDL_INTERFACE("b222e44a-49b6-59bf-a033-ef617cd73a98")
                IWindowsUpdateItem : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE get_ProviderId(
                        HSTRING* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_UpdateId(
                        HSTRING* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_Timestamp(
                        ABI::Windows::Foundation::DateTime* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_Title(
                        HSTRING* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_Description(
                        HSTRING* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_MoreInfoUrl(
                        ABI::Windows::Foundation::IUriRuntimeClass** value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_Category(
                        HSTRING* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_Operation(
                        HSTRING* value
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IWindowsUpdateItem = _uuidof(IWindowsUpdateItem);
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateItem;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateItem_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.IWindowsUpdateManager
 *
 * Introduced to Windows.Management.Update.WindowsUpdateContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.WindowsUpdateManager
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManager_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManager_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_IWindowsUpdateManager[] = L"Windows.Management.Update.IWindowsUpdateManager";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                MIDL_INTERFACE("5dd966c0-a71a-5602-bbd0-09a70e4573fa")
                IWindowsUpdateManager : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE add_ScanningStateChanged(
                        __FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_IInspectable* handler,
                        EventRegistrationToken* token
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE remove_ScanningStateChanged(
                        EventRegistrationToken token
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE add_WorkingStateChanged(
                        __FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_IInspectable* handler,
                        EventRegistrationToken* token
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE remove_WorkingStateChanged(
                        EventRegistrationToken token
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE add_ProgressChanged(
                        __FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateProgressChangedEventArgs* handler,
                        EventRegistrationToken* token
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE remove_ProgressChanged(
                        EventRegistrationToken token
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE add_AttentionRequiredReasonChanged(
                        __FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateAttentionRequiredReasonChangedEventArgs* handler,
                        EventRegistrationToken* token
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE remove_AttentionRequiredReasonChanged(
                        EventRegistrationToken token
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE add_ActionCompleted(
                        __FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateActionCompletedEventArgs* handler,
                        EventRegistrationToken* token
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE remove_ActionCompleted(
                        EventRegistrationToken token
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE add_ScanCompleted(
                        __FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateScanCompletedEventArgs* handler,
                        EventRegistrationToken* token
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE remove_ScanCompleted(
                        EventRegistrationToken token
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_IsScanning(
                        boolean* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_IsWorking(
                        boolean* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_LastSuccessfulScanTimestamp(
                        __FIReference_1_Windows__CFoundation__CDateTime** value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE GetApplicableUpdates(
                        __FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdate** result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE GetMostRecentCompletedUpdates(
                        INT32 count,
                        __FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem** result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE GetMostRecentCompletedUpdatesAsync(
                        INT32 count,
                        __FIAsyncOperation_1___FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem** operation
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE StartScan(
                        boolean userInitiated
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IWindowsUpdateManager = _uuidof(IWindowsUpdateManager);
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManager;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManager_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.IWindowsUpdateManagerFactory
 *
 * Introduced to Windows.Management.Update.WindowsUpdateContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.WindowsUpdateManager
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManagerFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManagerFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_IWindowsUpdateManagerFactory[] = L"Windows.Management.Update.IWindowsUpdateManagerFactory";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                MIDL_INTERFACE("1b394df8-decb-5f44-b47c-6ccf3bcfdb37")
                IWindowsUpdateManagerFactory : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE CreateInstance(
                        HSTRING clientId,
                        ABI::Windows::Management::Update::IWindowsUpdateManager** value
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IWindowsUpdateManagerFactory = _uuidof(IWindowsUpdateManagerFactory);
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManagerFactory;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManagerFactory_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.IWindowsUpdateProgressChangedEventArgs
 *
 * Introduced to Windows.Management.Update.WindowsUpdateContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.WindowsUpdateProgressChangedEventArgs
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateProgressChangedEventArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateProgressChangedEventArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_IWindowsUpdateProgressChangedEventArgs[] = L"Windows.Management.Update.IWindowsUpdateProgressChangedEventArgs";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                MIDL_INTERFACE("bbfbdeeb-94c8-5aa7-b0fb-66c67c233b0a")
                IWindowsUpdateProgressChangedEventArgs : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE get_Update(
                        ABI::Windows::Management::Update::IWindowsUpdate** value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_ActionProgress(
                        ABI::Windows::Management::Update::IWindowsUpdateActionProgress** value
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IWindowsUpdateProgressChangedEventArgs = _uuidof(IWindowsUpdateProgressChangedEventArgs);
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateProgressChangedEventArgs;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateProgressChangedEventArgs_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.IWindowsUpdateRestartRequestOptions
 *
 * Introduced to Windows.Management.Update.WindowsUpdateContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.WindowsUpdateRestartRequestOptions
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptions_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptions_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_IWindowsUpdateRestartRequestOptions[] = L"Windows.Management.Update.IWindowsUpdateRestartRequestOptions";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                MIDL_INTERFACE("38cfb7d3-4188-5222-905c-6c4443c951ee")
                IWindowsUpdateRestartRequestOptions : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE get_Title(
                        HSTRING* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_Title(
                        HSTRING value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_Description(
                        HSTRING* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_Description(
                        HSTRING value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_MoreInfoUrl(
                        ABI::Windows::Foundation::IUriRuntimeClass** value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_MoreInfoUrl(
                        ABI::Windows::Foundation::IUriRuntimeClass* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_ComplianceDeadlineInDays(
                        INT32* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_ComplianceDeadlineInDays(
                        INT32 value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_ComplianceGracePeriodInDays(
                        INT32* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_ComplianceGracePeriodInDays(
                        INT32 value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_OrganizationName(
                        HSTRING* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_OrganizationName(
                        HSTRING value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_OptOutOfAutoReboot(
                        boolean* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_OptOutOfAutoReboot(
                        boolean value
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IWindowsUpdateRestartRequestOptions = _uuidof(IWindowsUpdateRestartRequestOptions);
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptions;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptions_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.IWindowsUpdateRestartRequestOptionsFactory
 *
 * Introduced to Windows.Management.Update.WindowsUpdateContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.WindowsUpdateRestartRequestOptions
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptionsFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptionsFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_IWindowsUpdateRestartRequestOptionsFactory[] = L"Windows.Management.Update.IWindowsUpdateRestartRequestOptionsFactory";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                MIDL_INTERFACE("75f41d04-0e17-50d0-8c15-6b9d0539b3a9")
                IWindowsUpdateRestartRequestOptionsFactory : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE CreateInstance(
                        HSTRING title,
                        HSTRING description,
                        ABI::Windows::Foundation::IUriRuntimeClass* moreInfoUrl,
                        INT32 complianceDeadlineInDays,
                        INT32 complianceGracePeriodInDays,
                        ABI::Windows::Management::Update::IWindowsUpdateRestartRequestOptions** value
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IWindowsUpdateRestartRequestOptionsFactory = _uuidof(IWindowsUpdateRestartRequestOptionsFactory);
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptionsFactory;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptionsFactory_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.IWindowsUpdateScanCompletedEventArgs
 *
 * Introduced to Windows.Management.Update.WindowsUpdateContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.WindowsUpdateScanCompletedEventArgs
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateScanCompletedEventArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateScanCompletedEventArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_IWindowsUpdateScanCompletedEventArgs[] = L"Windows.Management.Update.IWindowsUpdateScanCompletedEventArgs";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                MIDL_INTERFACE("95b6953e-ba5c-5fe8-b115-12de184a6bb0")
                IWindowsUpdateScanCompletedEventArgs : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE get_ProviderId(
                        HSTRING* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_Succeeded(
                        boolean* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_ExtendedError(
                        HRESULT* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_Updates(
                        __FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdate** value
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IWindowsUpdateScanCompletedEventArgs = _uuidof(IWindowsUpdateScanCompletedEventArgs);
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateScanCompletedEventArgs;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateScanCompletedEventArgs_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

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

/*
 *
 * Class Windows.Management.Update.WindowsUpdate
 *
 * Introduced to Windows.Management.Update.WindowsUpdateContract in version 1.0
 *
 * Class implements the following interfaces:
 *    Windows.Management.Update.IWindowsUpdate ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Management_Update_WindowsUpdate_DEFINED
#define RUNTIMECLASS_Windows_Management_Update_WindowsUpdate_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Update_WindowsUpdate[] = L"Windows.Management.Update.WindowsUpdate";
#endif
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Management.Update.WindowsUpdateActionCompletedEventArgs
 *
 * Introduced to Windows.Management.Update.WindowsUpdateContract in version 1.0
 *
 * Class implements the following interfaces:
 *    Windows.Management.Update.IWindowsUpdateActionCompletedEventArgs ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Management_Update_WindowsUpdateActionCompletedEventArgs_DEFINED
#define RUNTIMECLASS_Windows_Management_Update_WindowsUpdateActionCompletedEventArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Update_WindowsUpdateActionCompletedEventArgs[] = L"Windows.Management.Update.WindowsUpdateActionCompletedEventArgs";
#endif
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Management.Update.WindowsUpdateActionProgress
 *
 * Introduced to Windows.Management.Update.WindowsUpdateContract in version 1.0
 *
 * Class implements the following interfaces:
 *    Windows.Management.Update.IWindowsUpdateActionProgress ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Management_Update_WindowsUpdateActionProgress_DEFINED
#define RUNTIMECLASS_Windows_Management_Update_WindowsUpdateActionProgress_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Update_WindowsUpdateActionProgress[] = L"Windows.Management.Update.WindowsUpdateActionProgress";
#endif
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Management.Update.WindowsUpdateActionResult
 *
 * Introduced to Windows.Management.Update.WindowsUpdateContract in version 1.0
 *
 * Class implements the following interfaces:
 *    Windows.Management.Update.IWindowsUpdateActionResult ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Management_Update_WindowsUpdateActionResult_DEFINED
#define RUNTIMECLASS_Windows_Management_Update_WindowsUpdateActionResult_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Update_WindowsUpdateActionResult[] = L"Windows.Management.Update.WindowsUpdateActionResult";
#endif
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Management.Update.WindowsUpdateAdministrator
 *
 * Introduced to Windows.Management.Update.WindowsUpdateContract in version 1.0
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Windows.Management.Update.IWindowsUpdateAdministratorStatics interface starting with version 1.0 of the Windows.Management.Update.WindowsUpdateContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Management.Update.IWindowsUpdateAdministrator ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Management_Update_WindowsUpdateAdministrator_DEFINED
#define RUNTIMECLASS_Windows_Management_Update_WindowsUpdateAdministrator_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Update_WindowsUpdateAdministrator[] = L"Windows.Management.Update.WindowsUpdateAdministrator";
#endif
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Management.Update.WindowsUpdateApprovalData
 *
 * Introduced to Windows.Management.Update.WindowsUpdateContract in version 1.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via RoActivateInstance starting with version 1.0 of the Windows.Management.Update.WindowsUpdateContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Management.Update.IWindowsUpdateApprovalData ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Management_Update_WindowsUpdateApprovalData_DEFINED
#define RUNTIMECLASS_Windows_Management_Update_WindowsUpdateApprovalData_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Update_WindowsUpdateApprovalData[] = L"Windows.Management.Update.WindowsUpdateApprovalData";
#endif
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Management.Update.WindowsUpdateAttentionRequiredInfo
 *
 * Introduced to Windows.Management.Update.WindowsUpdateContract in version 1.0
 *
 * Class implements the following interfaces:
 *    Windows.Management.Update.IWindowsUpdateAttentionRequiredInfo ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Management_Update_WindowsUpdateAttentionRequiredInfo_DEFINED
#define RUNTIMECLASS_Windows_Management_Update_WindowsUpdateAttentionRequiredInfo_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Update_WindowsUpdateAttentionRequiredInfo[] = L"Windows.Management.Update.WindowsUpdateAttentionRequiredInfo";
#endif
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Management.Update.WindowsUpdateAttentionRequiredReasonChangedEventArgs
 *
 * Introduced to Windows.Management.Update.WindowsUpdateContract in version 1.0
 *
 * Class implements the following interfaces:
 *    Windows.Management.Update.IWindowsUpdateAttentionRequiredReasonChangedEventArgs ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Management_Update_WindowsUpdateAttentionRequiredReasonChangedEventArgs_DEFINED
#define RUNTIMECLASS_Windows_Management_Update_WindowsUpdateAttentionRequiredReasonChangedEventArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Update_WindowsUpdateAttentionRequiredReasonChangedEventArgs[] = L"Windows.Management.Update.WindowsUpdateAttentionRequiredReasonChangedEventArgs";
#endif
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Management.Update.WindowsUpdateGetAdministratorResult
 *
 * Introduced to Windows.Management.Update.WindowsUpdateContract in version 1.0
 *
 * Class implements the following interfaces:
 *    Windows.Management.Update.IWindowsUpdateGetAdministratorResult ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Management_Update_WindowsUpdateGetAdministratorResult_DEFINED
#define RUNTIMECLASS_Windows_Management_Update_WindowsUpdateGetAdministratorResult_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Update_WindowsUpdateGetAdministratorResult[] = L"Windows.Management.Update.WindowsUpdateGetAdministratorResult";
#endif
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Management.Update.WindowsUpdateItem
 *
 * Introduced to Windows.Management.Update.WindowsUpdateContract in version 1.0
 *
 * Class implements the following interfaces:
 *    Windows.Management.Update.IWindowsUpdateItem ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Management_Update_WindowsUpdateItem_DEFINED
#define RUNTIMECLASS_Windows_Management_Update_WindowsUpdateItem_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Update_WindowsUpdateItem[] = L"Windows.Management.Update.WindowsUpdateItem";
#endif
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Management.Update.WindowsUpdateManager
 *
 * Introduced to Windows.Management.Update.WindowsUpdateContract in version 1.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via the Windows.Management.Update.IWindowsUpdateManagerFactory interface starting with version 1.0 of the Windows.Management.Update.WindowsUpdateContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Management.Update.IWindowsUpdateManager ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Management_Update_WindowsUpdateManager_DEFINED
#define RUNTIMECLASS_Windows_Management_Update_WindowsUpdateManager_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Update_WindowsUpdateManager[] = L"Windows.Management.Update.WindowsUpdateManager";
#endif
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Management.Update.WindowsUpdateProgressChangedEventArgs
 *
 * Introduced to Windows.Management.Update.WindowsUpdateContract in version 1.0
 *
 * Class implements the following interfaces:
 *    Windows.Management.Update.IWindowsUpdateProgressChangedEventArgs ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Management_Update_WindowsUpdateProgressChangedEventArgs_DEFINED
#define RUNTIMECLASS_Windows_Management_Update_WindowsUpdateProgressChangedEventArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Update_WindowsUpdateProgressChangedEventArgs[] = L"Windows.Management.Update.WindowsUpdateProgressChangedEventArgs";
#endif
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Management.Update.WindowsUpdateRestartRequestOptions
 *
 * Introduced to Windows.Management.Update.WindowsUpdateContract in version 1.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via the Windows.Management.Update.IWindowsUpdateRestartRequestOptionsFactory interface starting with version 1.0 of the Windows.Management.Update.WindowsUpdateContract API contract
 *   Type can be activated via RoActivateInstance starting with version 1.0 of the Windows.Management.Update.WindowsUpdateContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Management.Update.IWindowsUpdateRestartRequestOptions ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Management_Update_WindowsUpdateRestartRequestOptions_DEFINED
#define RUNTIMECLASS_Windows_Management_Update_WindowsUpdateRestartRequestOptions_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Update_WindowsUpdateRestartRequestOptions[] = L"Windows.Management.Update.WindowsUpdateRestartRequestOptions";
#endif
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Management.Update.WindowsUpdateScanCompletedEventArgs
 *
 * Introduced to Windows.Management.Update.WindowsUpdateContract in version 1.0
 *
 * Class implements the following interfaces:
 *    Windows.Management.Update.IWindowsUpdateScanCompletedEventArgs ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Management_Update_WindowsUpdateScanCompletedEventArgs_DEFINED
#define RUNTIMECLASS_Windows_Management_Update_WindowsUpdateScanCompletedEventArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Update_WindowsUpdateScanCompletedEventArgs[] = L"Windows.Management.Update.WindowsUpdateScanCompletedEventArgs";
#endif
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

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

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate;

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionCompletedEventArgs_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionCompletedEventArgs_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionCompletedEventArgs __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionCompletedEventArgs;

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionCompletedEventArgs_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionProgress_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionProgress_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionProgress __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionProgress;

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionProgress_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionResult_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionResult_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionResult __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionResult;

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionResult_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministrator_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministrator_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministrator __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministrator;

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministrator_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministratorStatics_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministratorStatics_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministratorStatics __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministratorStatics;

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministratorStatics_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateApprovalData_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateApprovalData_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateApprovalData __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateApprovalData;

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateApprovalData_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAttentionRequiredInfo_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAttentionRequiredInfo_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAttentionRequiredInfo __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAttentionRequiredInfo;

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAttentionRequiredInfo_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAttentionRequiredReasonChangedEventArgs_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAttentionRequiredReasonChangedEventArgs_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAttentionRequiredReasonChangedEventArgs __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAttentionRequiredReasonChangedEventArgs;

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAttentionRequiredReasonChangedEventArgs_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateGetAdministratorResult_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateGetAdministratorResult_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateGetAdministratorResult __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateGetAdministratorResult;

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateGetAdministratorResult_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateItem_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateItem_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateItem __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateItem;

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateItem_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManager_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManager_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManager __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManager;

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManager_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManagerFactory_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManagerFactory_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManagerFactory __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManagerFactory;

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManagerFactory_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateProgressChangedEventArgs_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateProgressChangedEventArgs_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateProgressChangedEventArgs __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateProgressChangedEventArgs;

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateProgressChangedEventArgs_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptions_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptions_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptions __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptions;

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptions_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptionsFactory_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptionsFactory_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptionsFactory __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptionsFactory;

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptionsFactory_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateScanCompletedEventArgs_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateScanCompletedEventArgs_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateScanCompletedEventArgs __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateScanCompletedEventArgs;

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateScanCompletedEventArgs_FWD_DEFINED__

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

#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#if !defined(____FIIterator_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_INTERFACE_DEFINED__)
#define ____FIIterator_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_INTERFACE_DEFINED__

typedef interface __FIIterator_1_Windows__CManagement__CUpdate__CWindowsUpdateItem __FIIterator_1_Windows__CManagement__CUpdate__CWindowsUpdateItem;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterator_1_Windows__CManagement__CUpdate__CWindowsUpdateItem;

typedef struct __FIIterator_1_Windows__CManagement__CUpdate__CWindowsUpdateItemVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIIterator_1_Windows__CManagement__CUpdate__CWindowsUpdateItem* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIIterator_1_Windows__CManagement__CUpdate__CWindowsUpdateItem* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIIterator_1_Windows__CManagement__CUpdate__CWindowsUpdateItem* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIIterator_1_Windows__CManagement__CUpdate__CWindowsUpdateItem* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIIterator_1_Windows__CManagement__CUpdate__CWindowsUpdateItem* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIIterator_1_Windows__CManagement__CUpdate__CWindowsUpdateItem* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Current)(__FIIterator_1_Windows__CManagement__CUpdate__CWindowsUpdateItem* This,
        __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateItem** result);
    HRESULT (STDMETHODCALLTYPE* get_HasCurrent)(__FIIterator_1_Windows__CManagement__CUpdate__CWindowsUpdateItem* This,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* MoveNext)(__FIIterator_1_Windows__CManagement__CUpdate__CWindowsUpdateItem* This,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* GetMany)(__FIIterator_1_Windows__CManagement__CUpdate__CWindowsUpdateItem* This,
        UINT32 itemsLength,
        __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateItem** items,
        UINT32* result);

    END_INTERFACE
} __FIIterator_1_Windows__CManagement__CUpdate__CWindowsUpdateItemVtbl;

interface __FIIterator_1_Windows__CManagement__CUpdate__CWindowsUpdateItem
{
    CONST_VTBL struct __FIIterator_1_Windows__CManagement__CUpdate__CWindowsUpdateItemVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIIterator_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIIterator_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIIterator_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIIterator_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIIterator_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIIterator_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIIterator_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_get_Current(This, result) \
    ((This)->lpVtbl->get_Current(This, result))

#define __FIIterator_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_get_HasCurrent(This, result) \
    ((This)->lpVtbl->get_HasCurrent(This, result))

#define __FIIterator_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_MoveNext(This, result) \
    ((This)->lpVtbl->MoveNext(This, result))

#define __FIIterator_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_GetMany(This, itemsLength, items, result) \
    ((This)->lpVtbl->GetMany(This, itemsLength, items, result))

#endif /* COBJMACROS */

#endif // ____FIIterator_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_INTERFACE_DEFINED__
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#if !defined(____FIIterable_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_INTERFACE_DEFINED__)
#define ____FIIterable_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_INTERFACE_DEFINED__

typedef interface __FIIterable_1_Windows__CManagement__CUpdate__CWindowsUpdateItem __FIIterable_1_Windows__CManagement__CUpdate__CWindowsUpdateItem;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterable_1_Windows__CManagement__CUpdate__CWindowsUpdateItem;

typedef struct __FIIterable_1_Windows__CManagement__CUpdate__CWindowsUpdateItemVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIIterable_1_Windows__CManagement__CUpdate__CWindowsUpdateItem* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIIterable_1_Windows__CManagement__CUpdate__CWindowsUpdateItem* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIIterable_1_Windows__CManagement__CUpdate__CWindowsUpdateItem* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIIterable_1_Windows__CManagement__CUpdate__CWindowsUpdateItem* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIIterable_1_Windows__CManagement__CUpdate__CWindowsUpdateItem* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIIterable_1_Windows__CManagement__CUpdate__CWindowsUpdateItem* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* First)(__FIIterable_1_Windows__CManagement__CUpdate__CWindowsUpdateItem* This,
        __FIIterator_1_Windows__CManagement__CUpdate__CWindowsUpdateItem** result);

    END_INTERFACE
} __FIIterable_1_Windows__CManagement__CUpdate__CWindowsUpdateItemVtbl;

interface __FIIterable_1_Windows__CManagement__CUpdate__CWindowsUpdateItem
{
    CONST_VTBL struct __FIIterable_1_Windows__CManagement__CUpdate__CWindowsUpdateItemVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIIterable_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIIterable_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIIterable_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIIterable_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIIterable_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIIterable_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIIterable_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_First(This, result) \
    ((This)->lpVtbl->First(This, result))

#endif /* COBJMACROS */

#endif // ____FIIterable_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_INTERFACE_DEFINED__
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#if !defined(____FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_INTERFACE_DEFINED__)
#define ____FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_INTERFACE_DEFINED__

typedef interface __FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem __FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem;

typedef struct __FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItemVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* GetAt)(__FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem* This,
        UINT32 index,
        __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateItem** result);
    HRESULT (STDMETHODCALLTYPE* get_Size)(__FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem* This,
        UINT32* result);
    HRESULT (STDMETHODCALLTYPE* IndexOf)(__FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem* This,
        __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateItem* value,
        UINT32* index,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* GetMany)(__FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem* This,
        UINT32 startIndex,
        UINT32 itemsLength,
        __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateItem** items,
        UINT32* result);

    END_INTERFACE
} __FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItemVtbl;

interface __FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem
{
    CONST_VTBL struct __FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItemVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_GetAt(This, index, result) \
    ((This)->lpVtbl->GetAt(This, index, result))

#define __FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_get_Size(This, result) \
    ((This)->lpVtbl->get_Size(This, result))

#define __FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_IndexOf(This, value, index, result) \
    ((This)->lpVtbl->IndexOf(This, value, index, result))

#define __FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_GetMany(This, startIndex, itemsLength, items, result) \
    ((This)->lpVtbl->GetMany(This, startIndex, itemsLength, items, result))

#endif /* COBJMACROS */

#endif // ____FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_INTERFACE_DEFINED__
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

typedef interface __FIAsyncOperationCompletedHandler_1___FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem __FIAsyncOperationCompletedHandler_1___FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem;

#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#if !defined(____FIAsyncOperation_1___FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_INTERFACE_DEFINED__)
#define ____FIAsyncOperation_1___FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_INTERFACE_DEFINED__

typedef interface __FIAsyncOperation_1___FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem __FIAsyncOperation_1___FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIAsyncOperation_1___FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem;

typedef struct __FIAsyncOperation_1___FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItemVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIAsyncOperation_1___FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIAsyncOperation_1___FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIAsyncOperation_1___FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIAsyncOperation_1___FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIAsyncOperation_1___FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIAsyncOperation_1___FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* put_Completed)(__FIAsyncOperation_1___FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem* This,
        __FIAsyncOperationCompletedHandler_1___FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem* handler);
    HRESULT (STDMETHODCALLTYPE* get_Completed)(__FIAsyncOperation_1___FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem* This,
        __FIAsyncOperationCompletedHandler_1___FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem** result);
    HRESULT (STDMETHODCALLTYPE* GetResults)(__FIAsyncOperation_1___FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem* This,
        __FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem** result);

    END_INTERFACE
} __FIAsyncOperation_1___FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItemVtbl;

interface __FIAsyncOperation_1___FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem
{
    CONST_VTBL struct __FIAsyncOperation_1___FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItemVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIAsyncOperation_1___FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIAsyncOperation_1___FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIAsyncOperation_1___FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIAsyncOperation_1___FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIAsyncOperation_1___FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIAsyncOperation_1___FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIAsyncOperation_1___FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_put_Completed(This, handler) \
    ((This)->lpVtbl->put_Completed(This, handler))

#define __FIAsyncOperation_1___FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_get_Completed(This, result) \
    ((This)->lpVtbl->get_Completed(This, result))

#define __FIAsyncOperation_1___FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_GetResults(This, result) \
    ((This)->lpVtbl->GetResults(This, result))

#endif /* COBJMACROS */

#endif // ____FIAsyncOperation_1___FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_INTERFACE_DEFINED__
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#if !defined(____FIAsyncOperationCompletedHandler_1___FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_INTERFACE_DEFINED__)
#define ____FIAsyncOperationCompletedHandler_1___FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_INTERFACE_DEFINED__

typedef interface __FIAsyncOperationCompletedHandler_1___FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem __FIAsyncOperationCompletedHandler_1___FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIAsyncOperationCompletedHandler_1___FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem;

typedef struct __FIAsyncOperationCompletedHandler_1___FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItemVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIAsyncOperationCompletedHandler_1___FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIAsyncOperationCompletedHandler_1___FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIAsyncOperationCompletedHandler_1___FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem* This);
    HRESULT (STDMETHODCALLTYPE* Invoke)(__FIAsyncOperationCompletedHandler_1___FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem* This,
        __FIAsyncOperation_1___FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem* asyncInfo,
        AsyncStatus asyncStatus);

    END_INTERFACE
} __FIAsyncOperationCompletedHandler_1___FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItemVtbl;

interface __FIAsyncOperationCompletedHandler_1___FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem
{
    CONST_VTBL struct __FIAsyncOperationCompletedHandler_1___FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItemVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIAsyncOperationCompletedHandler_1___FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIAsyncOperationCompletedHandler_1___FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIAsyncOperationCompletedHandler_1___FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIAsyncOperationCompletedHandler_1___FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_Invoke(This, asyncInfo, asyncStatus) \
    ((This)->lpVtbl->Invoke(This, asyncInfo, asyncStatus))

#endif /* COBJMACROS */

#endif // ____FIAsyncOperationCompletedHandler_1___FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem_INTERFACE_DEFINED__
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#if !defined(____FIIterator_1_Windows__CManagement__CUpdate__CWindowsUpdate_INTERFACE_DEFINED__)
#define ____FIIterator_1_Windows__CManagement__CUpdate__CWindowsUpdate_INTERFACE_DEFINED__

typedef interface __FIIterator_1_Windows__CManagement__CUpdate__CWindowsUpdate __FIIterator_1_Windows__CManagement__CUpdate__CWindowsUpdate;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterator_1_Windows__CManagement__CUpdate__CWindowsUpdate;

typedef struct __FIIterator_1_Windows__CManagement__CUpdate__CWindowsUpdateVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIIterator_1_Windows__CManagement__CUpdate__CWindowsUpdate* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIIterator_1_Windows__CManagement__CUpdate__CWindowsUpdate* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIIterator_1_Windows__CManagement__CUpdate__CWindowsUpdate* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIIterator_1_Windows__CManagement__CUpdate__CWindowsUpdate* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIIterator_1_Windows__CManagement__CUpdate__CWindowsUpdate* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIIterator_1_Windows__CManagement__CUpdate__CWindowsUpdate* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Current)(__FIIterator_1_Windows__CManagement__CUpdate__CWindowsUpdate* This,
        __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate** result);
    HRESULT (STDMETHODCALLTYPE* get_HasCurrent)(__FIIterator_1_Windows__CManagement__CUpdate__CWindowsUpdate* This,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* MoveNext)(__FIIterator_1_Windows__CManagement__CUpdate__CWindowsUpdate* This,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* GetMany)(__FIIterator_1_Windows__CManagement__CUpdate__CWindowsUpdate* This,
        UINT32 itemsLength,
        __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate** items,
        UINT32* result);

    END_INTERFACE
} __FIIterator_1_Windows__CManagement__CUpdate__CWindowsUpdateVtbl;

interface __FIIterator_1_Windows__CManagement__CUpdate__CWindowsUpdate
{
    CONST_VTBL struct __FIIterator_1_Windows__CManagement__CUpdate__CWindowsUpdateVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIIterator_1_Windows__CManagement__CUpdate__CWindowsUpdate_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIIterator_1_Windows__CManagement__CUpdate__CWindowsUpdate_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIIterator_1_Windows__CManagement__CUpdate__CWindowsUpdate_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIIterator_1_Windows__CManagement__CUpdate__CWindowsUpdate_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIIterator_1_Windows__CManagement__CUpdate__CWindowsUpdate_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIIterator_1_Windows__CManagement__CUpdate__CWindowsUpdate_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIIterator_1_Windows__CManagement__CUpdate__CWindowsUpdate_get_Current(This, result) \
    ((This)->lpVtbl->get_Current(This, result))

#define __FIIterator_1_Windows__CManagement__CUpdate__CWindowsUpdate_get_HasCurrent(This, result) \
    ((This)->lpVtbl->get_HasCurrent(This, result))

#define __FIIterator_1_Windows__CManagement__CUpdate__CWindowsUpdate_MoveNext(This, result) \
    ((This)->lpVtbl->MoveNext(This, result))

#define __FIIterator_1_Windows__CManagement__CUpdate__CWindowsUpdate_GetMany(This, itemsLength, items, result) \
    ((This)->lpVtbl->GetMany(This, itemsLength, items, result))

#endif /* COBJMACROS */

#endif // ____FIIterator_1_Windows__CManagement__CUpdate__CWindowsUpdate_INTERFACE_DEFINED__
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#if !defined(____FIIterable_1_Windows__CManagement__CUpdate__CWindowsUpdate_INTERFACE_DEFINED__)
#define ____FIIterable_1_Windows__CManagement__CUpdate__CWindowsUpdate_INTERFACE_DEFINED__

typedef interface __FIIterable_1_Windows__CManagement__CUpdate__CWindowsUpdate __FIIterable_1_Windows__CManagement__CUpdate__CWindowsUpdate;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterable_1_Windows__CManagement__CUpdate__CWindowsUpdate;

typedef struct __FIIterable_1_Windows__CManagement__CUpdate__CWindowsUpdateVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIIterable_1_Windows__CManagement__CUpdate__CWindowsUpdate* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIIterable_1_Windows__CManagement__CUpdate__CWindowsUpdate* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIIterable_1_Windows__CManagement__CUpdate__CWindowsUpdate* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIIterable_1_Windows__CManagement__CUpdate__CWindowsUpdate* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIIterable_1_Windows__CManagement__CUpdate__CWindowsUpdate* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIIterable_1_Windows__CManagement__CUpdate__CWindowsUpdate* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* First)(__FIIterable_1_Windows__CManagement__CUpdate__CWindowsUpdate* This,
        __FIIterator_1_Windows__CManagement__CUpdate__CWindowsUpdate** result);

    END_INTERFACE
} __FIIterable_1_Windows__CManagement__CUpdate__CWindowsUpdateVtbl;

interface __FIIterable_1_Windows__CManagement__CUpdate__CWindowsUpdate
{
    CONST_VTBL struct __FIIterable_1_Windows__CManagement__CUpdate__CWindowsUpdateVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIIterable_1_Windows__CManagement__CUpdate__CWindowsUpdate_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIIterable_1_Windows__CManagement__CUpdate__CWindowsUpdate_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIIterable_1_Windows__CManagement__CUpdate__CWindowsUpdate_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIIterable_1_Windows__CManagement__CUpdate__CWindowsUpdate_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIIterable_1_Windows__CManagement__CUpdate__CWindowsUpdate_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIIterable_1_Windows__CManagement__CUpdate__CWindowsUpdate_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIIterable_1_Windows__CManagement__CUpdate__CWindowsUpdate_First(This, result) \
    ((This)->lpVtbl->First(This, result))

#endif /* COBJMACROS */

#endif // ____FIIterable_1_Windows__CManagement__CUpdate__CWindowsUpdate_INTERFACE_DEFINED__
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#if !defined(____FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdate_INTERFACE_DEFINED__)
#define ____FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdate_INTERFACE_DEFINED__

typedef interface __FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdate __FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdate;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdate;

typedef struct __FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdate* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdate* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdate* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdate* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdate* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdate* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* GetAt)(__FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdate* This,
        UINT32 index,
        __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate** result);
    HRESULT (STDMETHODCALLTYPE* get_Size)(__FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdate* This,
        UINT32* result);
    HRESULT (STDMETHODCALLTYPE* IndexOf)(__FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdate* This,
        __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate* value,
        UINT32* index,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* GetMany)(__FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdate* This,
        UINT32 startIndex,
        UINT32 itemsLength,
        __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate** items,
        UINT32* result);

    END_INTERFACE
} __FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateVtbl;

interface __FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdate
{
    CONST_VTBL struct __FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdate_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdate_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdate_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdate_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdate_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdate_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdate_GetAt(This, index, result) \
    ((This)->lpVtbl->GetAt(This, index, result))

#define __FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdate_get_Size(This, result) \
    ((This)->lpVtbl->get_Size(This, result))

#define __FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdate_IndexOf(This, value, index, result) \
    ((This)->lpVtbl->IndexOf(This, value, index, result))

#define __FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdate_GetMany(This, startIndex, itemsLength, items, result) \
    ((This)->lpVtbl->GetMany(This, startIndex, itemsLength, items, result))

#endif /* COBJMACROS */

#endif // ____FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdate_INTERFACE_DEFINED__
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

#if !defined(____FIReference_1_boolean_INTERFACE_DEFINED__)
#define ____FIReference_1_boolean_INTERFACE_DEFINED__

typedef interface __FIReference_1_boolean __FIReference_1_boolean;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIReference_1_boolean;

typedef struct __FIReference_1_booleanVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIReference_1_boolean* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIReference_1_boolean* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIReference_1_boolean* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIReference_1_boolean* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIReference_1_boolean* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIReference_1_boolean* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Value)(__FIReference_1_boolean* This,
        boolean* result);

    END_INTERFACE
} __FIReference_1_booleanVtbl;

interface __FIReference_1_boolean
{
    CONST_VTBL struct __FIReference_1_booleanVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIReference_1_boolean_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIReference_1_boolean_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIReference_1_boolean_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIReference_1_boolean_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIReference_1_boolean_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIReference_1_boolean_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIReference_1_boolean_get_Value(This, result) \
    ((This)->lpVtbl->get_Value(This, result))

#endif /* COBJMACROS */

#endif // ____FIReference_1_boolean_INTERFACE_DEFINED__

#if !defined(____FIReference_1_int_INTERFACE_DEFINED__)
#define ____FIReference_1_int_INTERFACE_DEFINED__

typedef interface __FIReference_1_int __FIReference_1_int;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIReference_1_int;

typedef struct __FIReference_1_intVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIReference_1_int* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIReference_1_int* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIReference_1_int* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIReference_1_int* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIReference_1_int* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIReference_1_int* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Value)(__FIReference_1_int* This,
        INT32* result);

    END_INTERFACE
} __FIReference_1_intVtbl;

interface __FIReference_1_int
{
    CONST_VTBL struct __FIReference_1_intVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIReference_1_int_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIReference_1_int_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIReference_1_int_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIReference_1_int_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIReference_1_int_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIReference_1_int_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIReference_1_int_get_Value(This, result) \
    ((This)->lpVtbl->get_Value(This, result))

#endif /* COBJMACROS */

#endif // ____FIReference_1_int_INTERFACE_DEFINED__

typedef struct __x_ABI_CWindows_CFoundation_CDateTime __x_ABI_CWindows_CFoundation_CDateTime;

#if WINDOWS_FOUNDATION_FOUNDATIONCONTRACT_VERSION >= 0x10000
#if !defined(____FIReference_1_Windows__CFoundation__CDateTime_INTERFACE_DEFINED__)
#define ____FIReference_1_Windows__CFoundation__CDateTime_INTERFACE_DEFINED__

typedef interface __FIReference_1_Windows__CFoundation__CDateTime __FIReference_1_Windows__CFoundation__CDateTime;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIReference_1_Windows__CFoundation__CDateTime;

typedef struct __FIReference_1_Windows__CFoundation__CDateTimeVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIReference_1_Windows__CFoundation__CDateTime* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIReference_1_Windows__CFoundation__CDateTime* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIReference_1_Windows__CFoundation__CDateTime* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIReference_1_Windows__CFoundation__CDateTime* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIReference_1_Windows__CFoundation__CDateTime* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIReference_1_Windows__CFoundation__CDateTime* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Value)(__FIReference_1_Windows__CFoundation__CDateTime* This,
        struct __x_ABI_CWindows_CFoundation_CDateTime* result);

    END_INTERFACE
} __FIReference_1_Windows__CFoundation__CDateTimeVtbl;

interface __FIReference_1_Windows__CFoundation__CDateTime
{
    CONST_VTBL struct __FIReference_1_Windows__CFoundation__CDateTimeVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIReference_1_Windows__CFoundation__CDateTime_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIReference_1_Windows__CFoundation__CDateTime_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIReference_1_Windows__CFoundation__CDateTime_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIReference_1_Windows__CFoundation__CDateTime_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIReference_1_Windows__CFoundation__CDateTime_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIReference_1_Windows__CFoundation__CDateTime_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIReference_1_Windows__CFoundation__CDateTime_get_Value(This, result) \
    ((This)->lpVtbl->get_Value(This, result))

#endif /* COBJMACROS */

#endif // ____FIReference_1_Windows__CFoundation__CDateTime_INTERFACE_DEFINED__
#endif // WINDOWS_FOUNDATION_FOUNDATIONCONTRACT_VERSION >= 0x10000

#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#if !defined(____FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_IInspectable_INTERFACE_DEFINED__)
#define ____FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_IInspectable_INTERFACE_DEFINED__

typedef interface __FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_IInspectable __FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_IInspectable;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_IInspectable;

typedef struct __FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_IInspectableVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_IInspectable* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_IInspectable* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_IInspectable* This);
    HRESULT (STDMETHODCALLTYPE* Invoke)(__FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_IInspectable* This,
        __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManager* sender,
        IInspectable* args);

    END_INTERFACE
} __FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_IInspectableVtbl;

interface __FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_IInspectable
{
    CONST_VTBL struct __FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_IInspectableVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_IInspectable_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_IInspectable_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_IInspectable_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_IInspectable_Invoke(This, sender, args) \
    ((This)->lpVtbl->Invoke(This, sender, args))

#endif /* COBJMACROS */

#endif // ____FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_IInspectable_INTERFACE_DEFINED__
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#if !defined(____FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateActionCompletedEventArgs_INTERFACE_DEFINED__)
#define ____FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateActionCompletedEventArgs_INTERFACE_DEFINED__

typedef interface __FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateActionCompletedEventArgs __FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateActionCompletedEventArgs;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateActionCompletedEventArgs;

typedef struct __FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateActionCompletedEventArgsVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateActionCompletedEventArgs* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateActionCompletedEventArgs* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateActionCompletedEventArgs* This);
    HRESULT (STDMETHODCALLTYPE* Invoke)(__FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateActionCompletedEventArgs* This,
        __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManager* sender,
        __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionCompletedEventArgs* args);

    END_INTERFACE
} __FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateActionCompletedEventArgsVtbl;

interface __FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateActionCompletedEventArgs
{
    CONST_VTBL struct __FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateActionCompletedEventArgsVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateActionCompletedEventArgs_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateActionCompletedEventArgs_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateActionCompletedEventArgs_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateActionCompletedEventArgs_Invoke(This, sender, args) \
    ((This)->lpVtbl->Invoke(This, sender, args))

#endif /* COBJMACROS */

#endif // ____FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateActionCompletedEventArgs_INTERFACE_DEFINED__
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#if !defined(____FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateAttentionRequiredReasonChangedEventArgs_INTERFACE_DEFINED__)
#define ____FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateAttentionRequiredReasonChangedEventArgs_INTERFACE_DEFINED__

typedef interface __FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateAttentionRequiredReasonChangedEventArgs __FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateAttentionRequiredReasonChangedEventArgs;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateAttentionRequiredReasonChangedEventArgs;

typedef struct __FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateAttentionRequiredReasonChangedEventArgsVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateAttentionRequiredReasonChangedEventArgs* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateAttentionRequiredReasonChangedEventArgs* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateAttentionRequiredReasonChangedEventArgs* This);
    HRESULT (STDMETHODCALLTYPE* Invoke)(__FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateAttentionRequiredReasonChangedEventArgs* This,
        __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManager* sender,
        __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAttentionRequiredReasonChangedEventArgs* args);

    END_INTERFACE
} __FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateAttentionRequiredReasonChangedEventArgsVtbl;

interface __FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateAttentionRequiredReasonChangedEventArgs
{
    CONST_VTBL struct __FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateAttentionRequiredReasonChangedEventArgsVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateAttentionRequiredReasonChangedEventArgs_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateAttentionRequiredReasonChangedEventArgs_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateAttentionRequiredReasonChangedEventArgs_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateAttentionRequiredReasonChangedEventArgs_Invoke(This, sender, args) \
    ((This)->lpVtbl->Invoke(This, sender, args))

#endif /* COBJMACROS */

#endif // ____FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateAttentionRequiredReasonChangedEventArgs_INTERFACE_DEFINED__
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#if !defined(____FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateProgressChangedEventArgs_INTERFACE_DEFINED__)
#define ____FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateProgressChangedEventArgs_INTERFACE_DEFINED__

typedef interface __FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateProgressChangedEventArgs __FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateProgressChangedEventArgs;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateProgressChangedEventArgs;

typedef struct __FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateProgressChangedEventArgsVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateProgressChangedEventArgs* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateProgressChangedEventArgs* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateProgressChangedEventArgs* This);
    HRESULT (STDMETHODCALLTYPE* Invoke)(__FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateProgressChangedEventArgs* This,
        __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManager* sender,
        __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateProgressChangedEventArgs* args);

    END_INTERFACE
} __FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateProgressChangedEventArgsVtbl;

interface __FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateProgressChangedEventArgs
{
    CONST_VTBL struct __FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateProgressChangedEventArgsVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateProgressChangedEventArgs_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateProgressChangedEventArgs_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateProgressChangedEventArgs_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateProgressChangedEventArgs_Invoke(This, sender, args) \
    ((This)->lpVtbl->Invoke(This, sender, args))

#endif /* COBJMACROS */

#endif // ____FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateProgressChangedEventArgs_INTERFACE_DEFINED__
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#if !defined(____FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateScanCompletedEventArgs_INTERFACE_DEFINED__)
#define ____FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateScanCompletedEventArgs_INTERFACE_DEFINED__

typedef interface __FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateScanCompletedEventArgs __FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateScanCompletedEventArgs;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateScanCompletedEventArgs;

typedef struct __FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateScanCompletedEventArgsVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateScanCompletedEventArgs* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateScanCompletedEventArgs* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateScanCompletedEventArgs* This);
    HRESULT (STDMETHODCALLTYPE* Invoke)(__FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateScanCompletedEventArgs* This,
        __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManager* sender,
        __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateScanCompletedEventArgs* args);

    END_INTERFACE
} __FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateScanCompletedEventArgsVtbl;

interface __FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateScanCompletedEventArgs
{
    CONST_VTBL struct __FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateScanCompletedEventArgsVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateScanCompletedEventArgs_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateScanCompletedEventArgs_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateScanCompletedEventArgs_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateScanCompletedEventArgs_Invoke(This, sender, args) \
    ((This)->lpVtbl->Invoke(This, sender, args))

#endif /* COBJMACROS */

#endif // ____FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateScanCompletedEventArgs_INTERFACE_DEFINED__
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

#ifndef ____x_ABI_CWindows_CFoundation_CCollections_CIPropertySet_FWD_DEFINED__
#define ____x_ABI_CWindows_CFoundation_CCollections_CIPropertySet_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CFoundation_CCollections_CIPropertySet __x_ABI_CWindows_CFoundation_CCollections_CIPropertySet;

#endif // ____x_ABI_CWindows_CFoundation_CCollections_CIPropertySet_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CFoundation_CIPropertyValue_FWD_DEFINED__
#define ____x_ABI_CWindows_CFoundation_CIPropertyValue_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CFoundation_CIPropertyValue __x_ABI_CWindows_CFoundation_CIPropertyValue;

#endif // ____x_ABI_CWindows_CFoundation_CIPropertyValue_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CFoundation_CIUriRuntimeClass_FWD_DEFINED__
#define ____x_ABI_CWindows_CFoundation_CIUriRuntimeClass_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CFoundation_CIUriRuntimeClass __x_ABI_CWindows_CFoundation_CIUriRuntimeClass;

#endif // ____x_ABI_CWindows_CFoundation_CIUriRuntimeClass_FWD_DEFINED__

typedef enum __x_ABI_CWindows_CManagement_CUpdate_CWindowsUpdateAdministratorOptions __x_ABI_CWindows_CManagement_CUpdate_CWindowsUpdateAdministratorOptions;

typedef enum __x_ABI_CWindows_CManagement_CUpdate_CWindowsUpdateAdministratorStatus __x_ABI_CWindows_CManagement_CUpdate_CWindowsUpdateAdministratorStatus;

typedef enum __x_ABI_CWindows_CManagement_CUpdate_CWindowsUpdateAttentionRequiredReason __x_ABI_CWindows_CManagement_CUpdate_CWindowsUpdateAttentionRequiredReason;

/*
 *
 * Struct Windows.Management.Update.WindowsUpdateAdministratorOptions
 *
 * Introduced to Windows.Management.Update.WindowsUpdateContract in version 1.0
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
enum __x_ABI_CWindows_CManagement_CUpdate_CWindowsUpdateAdministratorOptions
{
    WindowsUpdateAdministratorOptions_None = 0,
    WindowsUpdateAdministratorOptions_RequireAdministratorApprovalForScans = 0x1,
    WindowsUpdateAdministratorOptions_RequireAdministratorApprovalForUpdates = 0x2,
    WindowsUpdateAdministratorOptions_RequireAdministratorApprovalForActions = 0x4,
};
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

/*
 *
 * Struct Windows.Management.Update.WindowsUpdateAdministratorStatus
 *
 * Introduced to Windows.Management.Update.WindowsUpdateContract in version 1.0
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
enum __x_ABI_CWindows_CManagement_CUpdate_CWindowsUpdateAdministratorStatus
{
    WindowsUpdateAdministratorStatus_Succeeded = 0,
    WindowsUpdateAdministratorStatus_NoAdministratorRegistered = 1,
    WindowsUpdateAdministratorStatus_OtherAdministratorIsRegistered = 2,
};
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

/*
 *
 * Struct Windows.Management.Update.WindowsUpdateAttentionRequiredReason
 *
 * Introduced to Windows.Management.Update.WindowsUpdateContract in version 1.0
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
enum __x_ABI_CWindows_CManagement_CUpdate_CWindowsUpdateAttentionRequiredReason
{
    WindowsUpdateAttentionRequiredReason_None = 0,
    WindowsUpdateAttentionRequiredReason_SeekerUpdate = 1,
    WindowsUpdateAttentionRequiredReason_ReadyToReboot = 2,
    WindowsUpdateAttentionRequiredReason_NeedNonMeteredNetwork = 3,
    WindowsUpdateAttentionRequiredReason_NeedUserAgreementForMeteredNetwork = 4,
    WindowsUpdateAttentionRequiredReason_NeedNetwork = 5,
    WindowsUpdateAttentionRequiredReason_NeedMoreSpace = 6,
    WindowsUpdateAttentionRequiredReason_BatterySaverEnabled = 7,
    WindowsUpdateAttentionRequiredReason_NeedUserInteraction = 8,
    WindowsUpdateAttentionRequiredReason_NeedUserAgreementForPolicy = 9,
    WindowsUpdateAttentionRequiredReason_CompatibilityError = 10,
    WindowsUpdateAttentionRequiredReason_NeedUserInteractionForEula = 11,
    WindowsUpdateAttentionRequiredReason_NeedUserInteractionForCta = 12,
    WindowsUpdateAttentionRequiredReason_Regulated = 13,
    WindowsUpdateAttentionRequiredReason_ExternalReboot = 14,
    WindowsUpdateAttentionRequiredReason_OtherUpdate = 15,
    WindowsUpdateAttentionRequiredReason_BlockedByProvider = 16,
    WindowsUpdateAttentionRequiredReason_BlockedByPostRebootFailure = 17,
    WindowsUpdateAttentionRequiredReason_UserEngaged = 18,
    WindowsUpdateAttentionRequiredReason_BlockedByBattery = 19,
    WindowsUpdateAttentionRequiredReason_Exclusivity = 20,
    WindowsUpdateAttentionRequiredReason_BlockedBySerialization = 21,
    WindowsUpdateAttentionRequiredReason_ConflictClass = 22,
    WindowsUpdateAttentionRequiredReason_BlockedByAdminApproval = 23,
    WindowsUpdateAttentionRequiredReason_BlockedByTooManyAttempts = 24,
    WindowsUpdateAttentionRequiredReason_BlockedByFailure = 25,
    WindowsUpdateAttentionRequiredReason_Demotion = 26,
    WindowsUpdateAttentionRequiredReason_BlockedByActiveHours = 27,
    WindowsUpdateAttentionRequiredReason_ScheduledForMaintenance = 28,
    WindowsUpdateAttentionRequiredReason_PolicyScheduledInstallTime = 29,
    WindowsUpdateAttentionRequiredReason_BlockedByOobe = 30,
    WindowsUpdateAttentionRequiredReason_DeferredDuringOobe = 31,
    WindowsUpdateAttentionRequiredReason_DeferredForSustainableTime = 32,
};
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

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
 * Interface Windows.Management.Update.IWindowsUpdate
 *
 * Introduced to Windows.Management.Update.WindowsUpdateContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.WindowsUpdate
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_IWindowsUpdate[] = L"Windows.Management.Update.IWindowsUpdate";
typedef struct __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_ProviderId)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* get_UpdateId)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* get_Title)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* get_Description)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* get_IsFeatureUpdate)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate* This,
        boolean* value);
    HRESULT (STDMETHODCALLTYPE* get_IsMinorImpact)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate* This,
        boolean* value);
    HRESULT (STDMETHODCALLTYPE* get_IsSecurity)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate* This,
        boolean* value);
    HRESULT (STDMETHODCALLTYPE* get_IsCritical)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate* This,
        boolean* value);
    HRESULT (STDMETHODCALLTYPE* get_IsForOS)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate* This,
        boolean* value);
    HRESULT (STDMETHODCALLTYPE* get_IsDriver)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate* This,
        boolean* value);
    HRESULT (STDMETHODCALLTYPE* get_IsMandatory)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate* This,
        boolean* value);
    HRESULT (STDMETHODCALLTYPE* get_IsUrgent)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate* This,
        boolean* value);
    HRESULT (STDMETHODCALLTYPE* get_IsSeeker)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate* This,
        boolean* value);
    HRESULT (STDMETHODCALLTYPE* get_MoreInfoUrl)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate* This,
        __x_ABI_CWindows_CFoundation_CIUriRuntimeClass** value);
    HRESULT (STDMETHODCALLTYPE* get_SupportUrl)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate* This,
        __x_ABI_CWindows_CFoundation_CIUriRuntimeClass** value);
    HRESULT (STDMETHODCALLTYPE* get_IsEulaAccepted)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate* This,
        boolean* value);
    HRESULT (STDMETHODCALLTYPE* get_EulaText)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* get_Deadline)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate* This,
        __FIReference_1_Windows__CFoundation__CDateTime** value);
    HRESULT (STDMETHODCALLTYPE* get_AttentionRequiredInfo)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate* This,
        __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAttentionRequiredInfo** value);
    HRESULT (STDMETHODCALLTYPE* get_ActionResult)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate* This,
        __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionResult** value);
    HRESULT (STDMETHODCALLTYPE* get_CurrentAction)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* get_ActionProgress)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate* This,
        __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionProgress** value);
    HRESULT (STDMETHODCALLTYPE* GetPropertyValue)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate* This,
        HSTRING propertyName,
        IInspectable** result);
    HRESULT (STDMETHODCALLTYPE* AcceptEula)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate* This);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateVtbl;

interface __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate_get_ProviderId(This, value) \
    ((This)->lpVtbl->get_ProviderId(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate_get_UpdateId(This, value) \
    ((This)->lpVtbl->get_UpdateId(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate_get_Title(This, value) \
    ((This)->lpVtbl->get_Title(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate_get_Description(This, value) \
    ((This)->lpVtbl->get_Description(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate_get_IsFeatureUpdate(This, value) \
    ((This)->lpVtbl->get_IsFeatureUpdate(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate_get_IsMinorImpact(This, value) \
    ((This)->lpVtbl->get_IsMinorImpact(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate_get_IsSecurity(This, value) \
    ((This)->lpVtbl->get_IsSecurity(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate_get_IsCritical(This, value) \
    ((This)->lpVtbl->get_IsCritical(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate_get_IsForOS(This, value) \
    ((This)->lpVtbl->get_IsForOS(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate_get_IsDriver(This, value) \
    ((This)->lpVtbl->get_IsDriver(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate_get_IsMandatory(This, value) \
    ((This)->lpVtbl->get_IsMandatory(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate_get_IsUrgent(This, value) \
    ((This)->lpVtbl->get_IsUrgent(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate_get_IsSeeker(This, value) \
    ((This)->lpVtbl->get_IsSeeker(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate_get_MoreInfoUrl(This, value) \
    ((This)->lpVtbl->get_MoreInfoUrl(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate_get_SupportUrl(This, value) \
    ((This)->lpVtbl->get_SupportUrl(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate_get_IsEulaAccepted(This, value) \
    ((This)->lpVtbl->get_IsEulaAccepted(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate_get_EulaText(This, value) \
    ((This)->lpVtbl->get_EulaText(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate_get_Deadline(This, value) \
    ((This)->lpVtbl->get_Deadline(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate_get_AttentionRequiredInfo(This, value) \
    ((This)->lpVtbl->get_AttentionRequiredInfo(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate_get_ActionResult(This, value) \
    ((This)->lpVtbl->get_ActionResult(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate_get_CurrentAction(This, value) \
    ((This)->lpVtbl->get_CurrentAction(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate_get_ActionProgress(This, value) \
    ((This)->lpVtbl->get_ActionProgress(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate_GetPropertyValue(This, propertyName, result) \
    ((This)->lpVtbl->GetPropertyValue(This, propertyName, result))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate_AcceptEula(This) \
    ((This)->lpVtbl->AcceptEula(This))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.IWindowsUpdateActionCompletedEventArgs
 *
 * Introduced to Windows.Management.Update.WindowsUpdateContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.WindowsUpdateActionCompletedEventArgs
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionCompletedEventArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionCompletedEventArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_IWindowsUpdateActionCompletedEventArgs[] = L"Windows.Management.Update.IWindowsUpdateActionCompletedEventArgs";
typedef struct __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionCompletedEventArgsVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionCompletedEventArgs* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionCompletedEventArgs* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionCompletedEventArgs* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionCompletedEventArgs* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionCompletedEventArgs* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionCompletedEventArgs* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Update)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionCompletedEventArgs* This,
        __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate** value);
    HRESULT (STDMETHODCALLTYPE* get_Action)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionCompletedEventArgs* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* get_Succeeded)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionCompletedEventArgs* This,
        boolean* value);
    HRESULT (STDMETHODCALLTYPE* get_ExtendedError)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionCompletedEventArgs* This,
        HRESULT* value);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionCompletedEventArgsVtbl;

interface __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionCompletedEventArgs
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionCompletedEventArgsVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionCompletedEventArgs_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionCompletedEventArgs_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionCompletedEventArgs_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionCompletedEventArgs_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionCompletedEventArgs_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionCompletedEventArgs_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionCompletedEventArgs_get_Update(This, value) \
    ((This)->lpVtbl->get_Update(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionCompletedEventArgs_get_Action(This, value) \
    ((This)->lpVtbl->get_Action(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionCompletedEventArgs_get_Succeeded(This, value) \
    ((This)->lpVtbl->get_Succeeded(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionCompletedEventArgs_get_ExtendedError(This, value) \
    ((This)->lpVtbl->get_ExtendedError(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionCompletedEventArgs;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionCompletedEventArgs_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.IWindowsUpdateActionProgress
 *
 * Introduced to Windows.Management.Update.WindowsUpdateContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.WindowsUpdateActionProgress
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionProgress_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionProgress_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_IWindowsUpdateActionProgress[] = L"Windows.Management.Update.IWindowsUpdateActionProgress";
typedef struct __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionProgressVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionProgress* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionProgress* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionProgress* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionProgress* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionProgress* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionProgress* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Action)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionProgress* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* get_Progress)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionProgress* This,
        DOUBLE* value);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionProgressVtbl;

interface __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionProgress
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionProgressVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionProgress_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionProgress_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionProgress_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionProgress_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionProgress_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionProgress_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionProgress_get_Action(This, value) \
    ((This)->lpVtbl->get_Action(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionProgress_get_Progress(This, value) \
    ((This)->lpVtbl->get_Progress(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionProgress;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionProgress_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.IWindowsUpdateActionResult
 *
 * Introduced to Windows.Management.Update.WindowsUpdateContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.WindowsUpdateActionResult
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionResult_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionResult_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_IWindowsUpdateActionResult[] = L"Windows.Management.Update.IWindowsUpdateActionResult";
typedef struct __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionResultVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionResult* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionResult* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionResult* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionResult* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionResult* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionResult* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Timestamp)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionResult* This,
        struct __x_ABI_CWindows_CFoundation_CDateTime* value);
    HRESULT (STDMETHODCALLTYPE* get_Succeeded)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionResult* This,
        boolean* value);
    HRESULT (STDMETHODCALLTYPE* get_ExtendedError)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionResult* This,
        HRESULT* value);
    HRESULT (STDMETHODCALLTYPE* get_Action)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionResult* This,
        HSTRING* value);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionResultVtbl;

interface __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionResult
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionResultVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionResult_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionResult_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionResult_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionResult_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionResult_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionResult_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionResult_get_Timestamp(This, value) \
    ((This)->lpVtbl->get_Timestamp(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionResult_get_Succeeded(This, value) \
    ((This)->lpVtbl->get_Succeeded(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionResult_get_ExtendedError(This, value) \
    ((This)->lpVtbl->get_ExtendedError(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionResult_get_Action(This, value) \
    ((This)->lpVtbl->get_Action(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionResult;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionResult_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.IWindowsUpdateAdministrator
 *
 * Introduced to Windows.Management.Update.WindowsUpdateContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.WindowsUpdateAdministrator
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministrator_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministrator_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_IWindowsUpdateAdministrator[] = L"Windows.Management.Update.IWindowsUpdateAdministrator";
typedef struct __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministratorVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministrator* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministrator* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministrator* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministrator* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministrator* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministrator* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* StartAdministratorScan)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministrator* This);
    HRESULT (STDMETHODCALLTYPE* ApproveWindowsUpdateAction)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministrator* This,
        HSTRING updateId,
        HSTRING action);
    HRESULT (STDMETHODCALLTYPE* RevokeWindowsUpdateActionApproval)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministrator* This,
        HSTRING updateId,
        HSTRING action);
    HRESULT (STDMETHODCALLTYPE* ApproveWindowsUpdate)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministrator* This,
        HSTRING updateId,
        __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateApprovalData* approvalData);
    HRESULT (STDMETHODCALLTYPE* RevokeWindowsUpdateApproval)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministrator* This,
        HSTRING updateId);
    HRESULT (STDMETHODCALLTYPE* GetUpdates)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministrator* This,
        __FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdate** result);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministratorVtbl;

interface __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministrator
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministratorVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministrator_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministrator_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministrator_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministrator_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministrator_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministrator_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministrator_StartAdministratorScan(This) \
    ((This)->lpVtbl->StartAdministratorScan(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministrator_ApproveWindowsUpdateAction(This, updateId, action) \
    ((This)->lpVtbl->ApproveWindowsUpdateAction(This, updateId, action))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministrator_RevokeWindowsUpdateActionApproval(This, updateId, action) \
    ((This)->lpVtbl->RevokeWindowsUpdateActionApproval(This, updateId, action))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministrator_ApproveWindowsUpdate(This, updateId, approvalData) \
    ((This)->lpVtbl->ApproveWindowsUpdate(This, updateId, approvalData))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministrator_RevokeWindowsUpdateApproval(This, updateId) \
    ((This)->lpVtbl->RevokeWindowsUpdateApproval(This, updateId))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministrator_GetUpdates(This, result) \
    ((This)->lpVtbl->GetUpdates(This, result))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministrator;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministrator_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.IWindowsUpdateAdministratorStatics
 *
 * Introduced to Windows.Management.Update.WindowsUpdateContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.WindowsUpdateAdministrator
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministratorStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministratorStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_IWindowsUpdateAdministratorStatics[] = L"Windows.Management.Update.IWindowsUpdateAdministratorStatics";
typedef struct __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministratorStaticsVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministratorStatics* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministratorStatics* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministratorStatics* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministratorStatics* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministratorStatics* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministratorStatics* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* GetRegisteredAdministrator)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministratorStatics* This,
        HSTRING organizationName,
        __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateGetAdministratorResult** result);
    HRESULT (STDMETHODCALLTYPE* RegisterForAdministration)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministratorStatics* This,
        HSTRING organizationName,
        enum __x_ABI_CWindows_CManagement_CUpdate_CWindowsUpdateAdministratorOptions options,
        enum __x_ABI_CWindows_CManagement_CUpdate_CWindowsUpdateAdministratorStatus* result);
    HRESULT (STDMETHODCALLTYPE* UnregisterForAdministration)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministratorStatics* This,
        HSTRING organizationName,
        enum __x_ABI_CWindows_CManagement_CUpdate_CWindowsUpdateAdministratorStatus* result);
    HRESULT (STDMETHODCALLTYPE* GetRegisteredAdministratorName)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministratorStatics* This,
        HSTRING* result);
    HRESULT (STDMETHODCALLTYPE* RequestRestart)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministratorStatics* This,
        __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptions* restartOptions,
        HSTRING* result);
    HRESULT (STDMETHODCALLTYPE* CancelRestartRequest)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministratorStatics* This,
        HSTRING requestRestartToken);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministratorStaticsVtbl;

interface __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministratorStatics
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministratorStaticsVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministratorStatics_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministratorStatics_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministratorStatics_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministratorStatics_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministratorStatics_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministratorStatics_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministratorStatics_GetRegisteredAdministrator(This, organizationName, result) \
    ((This)->lpVtbl->GetRegisteredAdministrator(This, organizationName, result))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministratorStatics_RegisterForAdministration(This, organizationName, options, result) \
    ((This)->lpVtbl->RegisterForAdministration(This, organizationName, options, result))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministratorStatics_UnregisterForAdministration(This, organizationName, result) \
    ((This)->lpVtbl->UnregisterForAdministration(This, organizationName, result))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministratorStatics_GetRegisteredAdministratorName(This, result) \
    ((This)->lpVtbl->GetRegisteredAdministratorName(This, result))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministratorStatics_RequestRestart(This, restartOptions, result) \
    ((This)->lpVtbl->RequestRestart(This, restartOptions, result))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministratorStatics_CancelRestartRequest(This, requestRestartToken) \
    ((This)->lpVtbl->CancelRestartRequest(This, requestRestartToken))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministratorStatics;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministratorStatics_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.IWindowsUpdateApprovalData
 *
 * Introduced to Windows.Management.Update.WindowsUpdateContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.WindowsUpdateApprovalData
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateApprovalData_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateApprovalData_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_IWindowsUpdateApprovalData[] = L"Windows.Management.Update.IWindowsUpdateApprovalData";
typedef struct __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateApprovalDataVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateApprovalData* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateApprovalData* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateApprovalData* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateApprovalData* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateApprovalData* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateApprovalData* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Seeker)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateApprovalData* This,
        __FIReference_1_boolean** value);
    HRESULT (STDMETHODCALLTYPE* put_Seeker)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateApprovalData* This,
        __FIReference_1_boolean* value);
    HRESULT (STDMETHODCALLTYPE* get_AllowDownloadOnMetered)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateApprovalData* This,
        __FIReference_1_boolean** value);
    HRESULT (STDMETHODCALLTYPE* put_AllowDownloadOnMetered)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateApprovalData* This,
        __FIReference_1_boolean* value);
    HRESULT (STDMETHODCALLTYPE* get_ComplianceDeadlineInDays)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateApprovalData* This,
        __FIReference_1_int** value);
    HRESULT (STDMETHODCALLTYPE* put_ComplianceDeadlineInDays)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateApprovalData* This,
        __FIReference_1_int* value);
    HRESULT (STDMETHODCALLTYPE* get_ComplianceGracePeriodInDays)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateApprovalData* This,
        __FIReference_1_int** value);
    HRESULT (STDMETHODCALLTYPE* put_ComplianceGracePeriodInDays)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateApprovalData* This,
        __FIReference_1_int* value);
    HRESULT (STDMETHODCALLTYPE* get_OptOutOfAutoReboot)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateApprovalData* This,
        __FIReference_1_boolean** value);
    HRESULT (STDMETHODCALLTYPE* put_OptOutOfAutoReboot)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateApprovalData* This,
        __FIReference_1_boolean* value);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateApprovalDataVtbl;

interface __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateApprovalData
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateApprovalDataVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateApprovalData_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateApprovalData_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateApprovalData_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateApprovalData_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateApprovalData_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateApprovalData_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateApprovalData_get_Seeker(This, value) \
    ((This)->lpVtbl->get_Seeker(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateApprovalData_put_Seeker(This, value) \
    ((This)->lpVtbl->put_Seeker(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateApprovalData_get_AllowDownloadOnMetered(This, value) \
    ((This)->lpVtbl->get_AllowDownloadOnMetered(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateApprovalData_put_AllowDownloadOnMetered(This, value) \
    ((This)->lpVtbl->put_AllowDownloadOnMetered(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateApprovalData_get_ComplianceDeadlineInDays(This, value) \
    ((This)->lpVtbl->get_ComplianceDeadlineInDays(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateApprovalData_put_ComplianceDeadlineInDays(This, value) \
    ((This)->lpVtbl->put_ComplianceDeadlineInDays(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateApprovalData_get_ComplianceGracePeriodInDays(This, value) \
    ((This)->lpVtbl->get_ComplianceGracePeriodInDays(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateApprovalData_put_ComplianceGracePeriodInDays(This, value) \
    ((This)->lpVtbl->put_ComplianceGracePeriodInDays(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateApprovalData_get_OptOutOfAutoReboot(This, value) \
    ((This)->lpVtbl->get_OptOutOfAutoReboot(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateApprovalData_put_OptOutOfAutoReboot(This, value) \
    ((This)->lpVtbl->put_OptOutOfAutoReboot(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateApprovalData;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateApprovalData_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.IWindowsUpdateAttentionRequiredInfo
 *
 * Introduced to Windows.Management.Update.WindowsUpdateContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.WindowsUpdateAttentionRequiredInfo
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAttentionRequiredInfo_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAttentionRequiredInfo_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_IWindowsUpdateAttentionRequiredInfo[] = L"Windows.Management.Update.IWindowsUpdateAttentionRequiredInfo";
typedef struct __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAttentionRequiredInfoVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAttentionRequiredInfo* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAttentionRequiredInfo* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAttentionRequiredInfo* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAttentionRequiredInfo* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAttentionRequiredInfo* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAttentionRequiredInfo* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Reason)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAttentionRequiredInfo* This,
        enum __x_ABI_CWindows_CManagement_CUpdate_CWindowsUpdateAttentionRequiredReason* value);
    HRESULT (STDMETHODCALLTYPE* get_Timestamp)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAttentionRequiredInfo* This,
        __FIReference_1_Windows__CFoundation__CDateTime** value);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAttentionRequiredInfoVtbl;

interface __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAttentionRequiredInfo
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAttentionRequiredInfoVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAttentionRequiredInfo_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAttentionRequiredInfo_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAttentionRequiredInfo_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAttentionRequiredInfo_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAttentionRequiredInfo_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAttentionRequiredInfo_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAttentionRequiredInfo_get_Reason(This, value) \
    ((This)->lpVtbl->get_Reason(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAttentionRequiredInfo_get_Timestamp(This, value) \
    ((This)->lpVtbl->get_Timestamp(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAttentionRequiredInfo;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAttentionRequiredInfo_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.IWindowsUpdateAttentionRequiredReasonChangedEventArgs
 *
 * Introduced to Windows.Management.Update.WindowsUpdateContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.WindowsUpdateAttentionRequiredReasonChangedEventArgs
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAttentionRequiredReasonChangedEventArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAttentionRequiredReasonChangedEventArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_IWindowsUpdateAttentionRequiredReasonChangedEventArgs[] = L"Windows.Management.Update.IWindowsUpdateAttentionRequiredReasonChangedEventArgs";
typedef struct __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAttentionRequiredReasonChangedEventArgsVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAttentionRequiredReasonChangedEventArgs* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAttentionRequiredReasonChangedEventArgs* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAttentionRequiredReasonChangedEventArgs* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAttentionRequiredReasonChangedEventArgs* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAttentionRequiredReasonChangedEventArgs* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAttentionRequiredReasonChangedEventArgs* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Update)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAttentionRequiredReasonChangedEventArgs* This,
        __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate** value);
    HRESULT (STDMETHODCALLTYPE* get_Reason)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAttentionRequiredReasonChangedEventArgs* This,
        enum __x_ABI_CWindows_CManagement_CUpdate_CWindowsUpdateAttentionRequiredReason* value);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAttentionRequiredReasonChangedEventArgsVtbl;

interface __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAttentionRequiredReasonChangedEventArgs
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAttentionRequiredReasonChangedEventArgsVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAttentionRequiredReasonChangedEventArgs_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAttentionRequiredReasonChangedEventArgs_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAttentionRequiredReasonChangedEventArgs_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAttentionRequiredReasonChangedEventArgs_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAttentionRequiredReasonChangedEventArgs_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAttentionRequiredReasonChangedEventArgs_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAttentionRequiredReasonChangedEventArgs_get_Update(This, value) \
    ((This)->lpVtbl->get_Update(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAttentionRequiredReasonChangedEventArgs_get_Reason(This, value) \
    ((This)->lpVtbl->get_Reason(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAttentionRequiredReasonChangedEventArgs;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAttentionRequiredReasonChangedEventArgs_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.IWindowsUpdateGetAdministratorResult
 *
 * Introduced to Windows.Management.Update.WindowsUpdateContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.WindowsUpdateGetAdministratorResult
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateGetAdministratorResult_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateGetAdministratorResult_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_IWindowsUpdateGetAdministratorResult[] = L"Windows.Management.Update.IWindowsUpdateGetAdministratorResult";
typedef struct __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateGetAdministratorResultVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateGetAdministratorResult* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateGetAdministratorResult* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateGetAdministratorResult* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateGetAdministratorResult* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateGetAdministratorResult* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateGetAdministratorResult* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Administrator)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateGetAdministratorResult* This,
        __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateAdministrator** value);
    HRESULT (STDMETHODCALLTYPE* get_Status)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateGetAdministratorResult* This,
        enum __x_ABI_CWindows_CManagement_CUpdate_CWindowsUpdateAdministratorStatus* value);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateGetAdministratorResultVtbl;

interface __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateGetAdministratorResult
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateGetAdministratorResultVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateGetAdministratorResult_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateGetAdministratorResult_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateGetAdministratorResult_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateGetAdministratorResult_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateGetAdministratorResult_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateGetAdministratorResult_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateGetAdministratorResult_get_Administrator(This, value) \
    ((This)->lpVtbl->get_Administrator(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateGetAdministratorResult_get_Status(This, value) \
    ((This)->lpVtbl->get_Status(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateGetAdministratorResult;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateGetAdministratorResult_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.IWindowsUpdateItem
 *
 * Introduced to Windows.Management.Update.WindowsUpdateContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.WindowsUpdateItem
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateItem_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateItem_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_IWindowsUpdateItem[] = L"Windows.Management.Update.IWindowsUpdateItem";
typedef struct __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateItemVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateItem* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateItem* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateItem* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateItem* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateItem* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateItem* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_ProviderId)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateItem* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* get_UpdateId)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateItem* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* get_Timestamp)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateItem* This,
        struct __x_ABI_CWindows_CFoundation_CDateTime* value);
    HRESULT (STDMETHODCALLTYPE* get_Title)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateItem* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* get_Description)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateItem* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* get_MoreInfoUrl)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateItem* This,
        __x_ABI_CWindows_CFoundation_CIUriRuntimeClass** value);
    HRESULT (STDMETHODCALLTYPE* get_Category)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateItem* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* get_Operation)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateItem* This,
        HSTRING* value);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateItemVtbl;

interface __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateItem
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateItemVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateItem_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateItem_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateItem_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateItem_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateItem_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateItem_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateItem_get_ProviderId(This, value) \
    ((This)->lpVtbl->get_ProviderId(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateItem_get_UpdateId(This, value) \
    ((This)->lpVtbl->get_UpdateId(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateItem_get_Timestamp(This, value) \
    ((This)->lpVtbl->get_Timestamp(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateItem_get_Title(This, value) \
    ((This)->lpVtbl->get_Title(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateItem_get_Description(This, value) \
    ((This)->lpVtbl->get_Description(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateItem_get_MoreInfoUrl(This, value) \
    ((This)->lpVtbl->get_MoreInfoUrl(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateItem_get_Category(This, value) \
    ((This)->lpVtbl->get_Category(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateItem_get_Operation(This, value) \
    ((This)->lpVtbl->get_Operation(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateItem;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateItem_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.IWindowsUpdateManager
 *
 * Introduced to Windows.Management.Update.WindowsUpdateContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.WindowsUpdateManager
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManager_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManager_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_IWindowsUpdateManager[] = L"Windows.Management.Update.IWindowsUpdateManager";
typedef struct __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManagerVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManager* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManager* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManager* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManager* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManager* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManager* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* add_ScanningStateChanged)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManager* This,
        __FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_IInspectable* handler,
        EventRegistrationToken* token);
    HRESULT (STDMETHODCALLTYPE* remove_ScanningStateChanged)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManager* This,
        EventRegistrationToken token);
    HRESULT (STDMETHODCALLTYPE* add_WorkingStateChanged)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManager* This,
        __FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_IInspectable* handler,
        EventRegistrationToken* token);
    HRESULT (STDMETHODCALLTYPE* remove_WorkingStateChanged)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManager* This,
        EventRegistrationToken token);
    HRESULT (STDMETHODCALLTYPE* add_ProgressChanged)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManager* This,
        __FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateProgressChangedEventArgs* handler,
        EventRegistrationToken* token);
    HRESULT (STDMETHODCALLTYPE* remove_ProgressChanged)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManager* This,
        EventRegistrationToken token);
    HRESULT (STDMETHODCALLTYPE* add_AttentionRequiredReasonChanged)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManager* This,
        __FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateAttentionRequiredReasonChangedEventArgs* handler,
        EventRegistrationToken* token);
    HRESULT (STDMETHODCALLTYPE* remove_AttentionRequiredReasonChanged)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManager* This,
        EventRegistrationToken token);
    HRESULT (STDMETHODCALLTYPE* add_ActionCompleted)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManager* This,
        __FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateActionCompletedEventArgs* handler,
        EventRegistrationToken* token);
    HRESULT (STDMETHODCALLTYPE* remove_ActionCompleted)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManager* This,
        EventRegistrationToken token);
    HRESULT (STDMETHODCALLTYPE* add_ScanCompleted)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManager* This,
        __FITypedEventHandler_2_Windows__CManagement__CUpdate__CWindowsUpdateManager_Windows__CManagement__CUpdate__CWindowsUpdateScanCompletedEventArgs* handler,
        EventRegistrationToken* token);
    HRESULT (STDMETHODCALLTYPE* remove_ScanCompleted)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManager* This,
        EventRegistrationToken token);
    HRESULT (STDMETHODCALLTYPE* get_IsScanning)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManager* This,
        boolean* value);
    HRESULT (STDMETHODCALLTYPE* get_IsWorking)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManager* This,
        boolean* value);
    HRESULT (STDMETHODCALLTYPE* get_LastSuccessfulScanTimestamp)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManager* This,
        __FIReference_1_Windows__CFoundation__CDateTime** value);
    HRESULT (STDMETHODCALLTYPE* GetApplicableUpdates)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManager* This,
        __FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdate** result);
    HRESULT (STDMETHODCALLTYPE* GetMostRecentCompletedUpdates)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManager* This,
        INT32 count,
        __FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem** result);
    HRESULT (STDMETHODCALLTYPE* GetMostRecentCompletedUpdatesAsync)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManager* This,
        INT32 count,
        __FIAsyncOperation_1___FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdateItem** operation);
    HRESULT (STDMETHODCALLTYPE* StartScan)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManager* This,
        boolean userInitiated);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManagerVtbl;

interface __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManager
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManagerVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManager_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManager_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManager_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManager_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManager_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManager_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManager_add_ScanningStateChanged(This, handler, token) \
    ((This)->lpVtbl->add_ScanningStateChanged(This, handler, token))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManager_remove_ScanningStateChanged(This, token) \
    ((This)->lpVtbl->remove_ScanningStateChanged(This, token))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManager_add_WorkingStateChanged(This, handler, token) \
    ((This)->lpVtbl->add_WorkingStateChanged(This, handler, token))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManager_remove_WorkingStateChanged(This, token) \
    ((This)->lpVtbl->remove_WorkingStateChanged(This, token))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManager_add_ProgressChanged(This, handler, token) \
    ((This)->lpVtbl->add_ProgressChanged(This, handler, token))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManager_remove_ProgressChanged(This, token) \
    ((This)->lpVtbl->remove_ProgressChanged(This, token))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManager_add_AttentionRequiredReasonChanged(This, handler, token) \
    ((This)->lpVtbl->add_AttentionRequiredReasonChanged(This, handler, token))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManager_remove_AttentionRequiredReasonChanged(This, token) \
    ((This)->lpVtbl->remove_AttentionRequiredReasonChanged(This, token))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManager_add_ActionCompleted(This, handler, token) \
    ((This)->lpVtbl->add_ActionCompleted(This, handler, token))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManager_remove_ActionCompleted(This, token) \
    ((This)->lpVtbl->remove_ActionCompleted(This, token))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManager_add_ScanCompleted(This, handler, token) \
    ((This)->lpVtbl->add_ScanCompleted(This, handler, token))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManager_remove_ScanCompleted(This, token) \
    ((This)->lpVtbl->remove_ScanCompleted(This, token))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManager_get_IsScanning(This, value) \
    ((This)->lpVtbl->get_IsScanning(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManager_get_IsWorking(This, value) \
    ((This)->lpVtbl->get_IsWorking(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManager_get_LastSuccessfulScanTimestamp(This, value) \
    ((This)->lpVtbl->get_LastSuccessfulScanTimestamp(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManager_GetApplicableUpdates(This, result) \
    ((This)->lpVtbl->GetApplicableUpdates(This, result))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManager_GetMostRecentCompletedUpdates(This, count, result) \
    ((This)->lpVtbl->GetMostRecentCompletedUpdates(This, count, result))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManager_GetMostRecentCompletedUpdatesAsync(This, count, operation) \
    ((This)->lpVtbl->GetMostRecentCompletedUpdatesAsync(This, count, operation))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManager_StartScan(This, userInitiated) \
    ((This)->lpVtbl->StartScan(This, userInitiated))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManager;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManager_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.IWindowsUpdateManagerFactory
 *
 * Introduced to Windows.Management.Update.WindowsUpdateContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.WindowsUpdateManager
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManagerFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManagerFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_IWindowsUpdateManagerFactory[] = L"Windows.Management.Update.IWindowsUpdateManagerFactory";
typedef struct __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManagerFactoryVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManagerFactory* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManagerFactory* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManagerFactory* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManagerFactory* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManagerFactory* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManagerFactory* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* CreateInstance)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManagerFactory* This,
        HSTRING clientId,
        __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManager** value);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManagerFactoryVtbl;

interface __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManagerFactory
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManagerFactoryVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManagerFactory_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManagerFactory_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManagerFactory_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManagerFactory_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManagerFactory_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManagerFactory_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManagerFactory_CreateInstance(This, clientId, value) \
    ((This)->lpVtbl->CreateInstance(This, clientId, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManagerFactory;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateManagerFactory_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.IWindowsUpdateProgressChangedEventArgs
 *
 * Introduced to Windows.Management.Update.WindowsUpdateContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.WindowsUpdateProgressChangedEventArgs
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateProgressChangedEventArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateProgressChangedEventArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_IWindowsUpdateProgressChangedEventArgs[] = L"Windows.Management.Update.IWindowsUpdateProgressChangedEventArgs";
typedef struct __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateProgressChangedEventArgsVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateProgressChangedEventArgs* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateProgressChangedEventArgs* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateProgressChangedEventArgs* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateProgressChangedEventArgs* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateProgressChangedEventArgs* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateProgressChangedEventArgs* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Update)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateProgressChangedEventArgs* This,
        __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdate** value);
    HRESULT (STDMETHODCALLTYPE* get_ActionProgress)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateProgressChangedEventArgs* This,
        __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateActionProgress** value);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateProgressChangedEventArgsVtbl;

interface __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateProgressChangedEventArgs
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateProgressChangedEventArgsVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateProgressChangedEventArgs_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateProgressChangedEventArgs_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateProgressChangedEventArgs_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateProgressChangedEventArgs_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateProgressChangedEventArgs_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateProgressChangedEventArgs_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateProgressChangedEventArgs_get_Update(This, value) \
    ((This)->lpVtbl->get_Update(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateProgressChangedEventArgs_get_ActionProgress(This, value) \
    ((This)->lpVtbl->get_ActionProgress(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateProgressChangedEventArgs;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateProgressChangedEventArgs_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.IWindowsUpdateRestartRequestOptions
 *
 * Introduced to Windows.Management.Update.WindowsUpdateContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.WindowsUpdateRestartRequestOptions
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptions_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptions_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_IWindowsUpdateRestartRequestOptions[] = L"Windows.Management.Update.IWindowsUpdateRestartRequestOptions";
typedef struct __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptionsVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptions* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptions* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptions* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptions* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptions* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptions* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Title)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptions* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* put_Title)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptions* This,
        HSTRING value);
    HRESULT (STDMETHODCALLTYPE* get_Description)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptions* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* put_Description)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptions* This,
        HSTRING value);
    HRESULT (STDMETHODCALLTYPE* get_MoreInfoUrl)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptions* This,
        __x_ABI_CWindows_CFoundation_CIUriRuntimeClass** value);
    HRESULT (STDMETHODCALLTYPE* put_MoreInfoUrl)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptions* This,
        __x_ABI_CWindows_CFoundation_CIUriRuntimeClass* value);
    HRESULT (STDMETHODCALLTYPE* get_ComplianceDeadlineInDays)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptions* This,
        INT32* value);
    HRESULT (STDMETHODCALLTYPE* put_ComplianceDeadlineInDays)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptions* This,
        INT32 value);
    HRESULT (STDMETHODCALLTYPE* get_ComplianceGracePeriodInDays)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptions* This,
        INT32* value);
    HRESULT (STDMETHODCALLTYPE* put_ComplianceGracePeriodInDays)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptions* This,
        INT32 value);
    HRESULT (STDMETHODCALLTYPE* get_OrganizationName)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptions* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* put_OrganizationName)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptions* This,
        HSTRING value);
    HRESULT (STDMETHODCALLTYPE* get_OptOutOfAutoReboot)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptions* This,
        boolean* value);
    HRESULT (STDMETHODCALLTYPE* put_OptOutOfAutoReboot)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptions* This,
        boolean value);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptionsVtbl;

interface __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptions
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptionsVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptions_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptions_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptions_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptions_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptions_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptions_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptions_get_Title(This, value) \
    ((This)->lpVtbl->get_Title(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptions_put_Title(This, value) \
    ((This)->lpVtbl->put_Title(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptions_get_Description(This, value) \
    ((This)->lpVtbl->get_Description(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptions_put_Description(This, value) \
    ((This)->lpVtbl->put_Description(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptions_get_MoreInfoUrl(This, value) \
    ((This)->lpVtbl->get_MoreInfoUrl(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptions_put_MoreInfoUrl(This, value) \
    ((This)->lpVtbl->put_MoreInfoUrl(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptions_get_ComplianceDeadlineInDays(This, value) \
    ((This)->lpVtbl->get_ComplianceDeadlineInDays(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptions_put_ComplianceDeadlineInDays(This, value) \
    ((This)->lpVtbl->put_ComplianceDeadlineInDays(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptions_get_ComplianceGracePeriodInDays(This, value) \
    ((This)->lpVtbl->get_ComplianceGracePeriodInDays(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptions_put_ComplianceGracePeriodInDays(This, value) \
    ((This)->lpVtbl->put_ComplianceGracePeriodInDays(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptions_get_OrganizationName(This, value) \
    ((This)->lpVtbl->get_OrganizationName(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptions_put_OrganizationName(This, value) \
    ((This)->lpVtbl->put_OrganizationName(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptions_get_OptOutOfAutoReboot(This, value) \
    ((This)->lpVtbl->get_OptOutOfAutoReboot(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptions_put_OptOutOfAutoReboot(This, value) \
    ((This)->lpVtbl->put_OptOutOfAutoReboot(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptions;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptions_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.IWindowsUpdateRestartRequestOptionsFactory
 *
 * Introduced to Windows.Management.Update.WindowsUpdateContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.WindowsUpdateRestartRequestOptions
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptionsFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptionsFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_IWindowsUpdateRestartRequestOptionsFactory[] = L"Windows.Management.Update.IWindowsUpdateRestartRequestOptionsFactory";
typedef struct __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptionsFactoryVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptionsFactory* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptionsFactory* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptionsFactory* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptionsFactory* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptionsFactory* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptionsFactory* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* CreateInstance)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptionsFactory* This,
        HSTRING title,
        HSTRING description,
        __x_ABI_CWindows_CFoundation_CIUriRuntimeClass* moreInfoUrl,
        INT32 complianceDeadlineInDays,
        INT32 complianceGracePeriodInDays,
        __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptions** value);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptionsFactoryVtbl;

interface __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptionsFactory
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptionsFactoryVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptionsFactory_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptionsFactory_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptionsFactory_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptionsFactory_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptionsFactory_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptionsFactory_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptionsFactory_CreateInstance(This, title, description, moreInfoUrl, complianceDeadlineInDays, complianceGracePeriodInDays, value) \
    ((This)->lpVtbl->CreateInstance(This, title, description, moreInfoUrl, complianceDeadlineInDays, complianceGracePeriodInDays, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptionsFactory;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateRestartRequestOptionsFactory_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.IWindowsUpdateScanCompletedEventArgs
 *
 * Introduced to Windows.Management.Update.WindowsUpdateContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.WindowsUpdateScanCompletedEventArgs
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateScanCompletedEventArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateScanCompletedEventArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_IWindowsUpdateScanCompletedEventArgs[] = L"Windows.Management.Update.IWindowsUpdateScanCompletedEventArgs";
typedef struct __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateScanCompletedEventArgsVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateScanCompletedEventArgs* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateScanCompletedEventArgs* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateScanCompletedEventArgs* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateScanCompletedEventArgs* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateScanCompletedEventArgs* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateScanCompletedEventArgs* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_ProviderId)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateScanCompletedEventArgs* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* get_Succeeded)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateScanCompletedEventArgs* This,
        boolean* value);
    HRESULT (STDMETHODCALLTYPE* get_ExtendedError)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateScanCompletedEventArgs* This,
        HRESULT* value);
    HRESULT (STDMETHODCALLTYPE* get_Updates)(__x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateScanCompletedEventArgs* This,
        __FIVectorView_1_Windows__CManagement__CUpdate__CWindowsUpdate** value);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateScanCompletedEventArgsVtbl;

interface __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateScanCompletedEventArgs
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateScanCompletedEventArgsVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateScanCompletedEventArgs_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateScanCompletedEventArgs_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateScanCompletedEventArgs_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateScanCompletedEventArgs_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateScanCompletedEventArgs_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateScanCompletedEventArgs_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateScanCompletedEventArgs_get_ProviderId(This, value) \
    ((This)->lpVtbl->get_ProviderId(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateScanCompletedEventArgs_get_Succeeded(This, value) \
    ((This)->lpVtbl->get_Succeeded(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateScanCompletedEventArgs_get_ExtendedError(This, value) \
    ((This)->lpVtbl->get_ExtendedError(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateScanCompletedEventArgs_get_Updates(This, value) \
    ((This)->lpVtbl->get_Updates(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateScanCompletedEventArgs;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CIWindowsUpdateScanCompletedEventArgs_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

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

/*
 *
 * Class Windows.Management.Update.WindowsUpdate
 *
 * Introduced to Windows.Management.Update.WindowsUpdateContract in version 1.0
 *
 * Class implements the following interfaces:
 *    Windows.Management.Update.IWindowsUpdate ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Management_Update_WindowsUpdate_DEFINED
#define RUNTIMECLASS_Windows_Management_Update_WindowsUpdate_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Update_WindowsUpdate[] = L"Windows.Management.Update.WindowsUpdate";
#endif
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Management.Update.WindowsUpdateActionCompletedEventArgs
 *
 * Introduced to Windows.Management.Update.WindowsUpdateContract in version 1.0
 *
 * Class implements the following interfaces:
 *    Windows.Management.Update.IWindowsUpdateActionCompletedEventArgs ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Management_Update_WindowsUpdateActionCompletedEventArgs_DEFINED
#define RUNTIMECLASS_Windows_Management_Update_WindowsUpdateActionCompletedEventArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Update_WindowsUpdateActionCompletedEventArgs[] = L"Windows.Management.Update.WindowsUpdateActionCompletedEventArgs";
#endif
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Management.Update.WindowsUpdateActionProgress
 *
 * Introduced to Windows.Management.Update.WindowsUpdateContract in version 1.0
 *
 * Class implements the following interfaces:
 *    Windows.Management.Update.IWindowsUpdateActionProgress ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Management_Update_WindowsUpdateActionProgress_DEFINED
#define RUNTIMECLASS_Windows_Management_Update_WindowsUpdateActionProgress_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Update_WindowsUpdateActionProgress[] = L"Windows.Management.Update.WindowsUpdateActionProgress";
#endif
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Management.Update.WindowsUpdateActionResult
 *
 * Introduced to Windows.Management.Update.WindowsUpdateContract in version 1.0
 *
 * Class implements the following interfaces:
 *    Windows.Management.Update.IWindowsUpdateActionResult ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Management_Update_WindowsUpdateActionResult_DEFINED
#define RUNTIMECLASS_Windows_Management_Update_WindowsUpdateActionResult_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Update_WindowsUpdateActionResult[] = L"Windows.Management.Update.WindowsUpdateActionResult";
#endif
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Management.Update.WindowsUpdateAdministrator
 *
 * Introduced to Windows.Management.Update.WindowsUpdateContract in version 1.0
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Windows.Management.Update.IWindowsUpdateAdministratorStatics interface starting with version 1.0 of the Windows.Management.Update.WindowsUpdateContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Management.Update.IWindowsUpdateAdministrator ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Management_Update_WindowsUpdateAdministrator_DEFINED
#define RUNTIMECLASS_Windows_Management_Update_WindowsUpdateAdministrator_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Update_WindowsUpdateAdministrator[] = L"Windows.Management.Update.WindowsUpdateAdministrator";
#endif
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Management.Update.WindowsUpdateApprovalData
 *
 * Introduced to Windows.Management.Update.WindowsUpdateContract in version 1.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via RoActivateInstance starting with version 1.0 of the Windows.Management.Update.WindowsUpdateContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Management.Update.IWindowsUpdateApprovalData ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Management_Update_WindowsUpdateApprovalData_DEFINED
#define RUNTIMECLASS_Windows_Management_Update_WindowsUpdateApprovalData_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Update_WindowsUpdateApprovalData[] = L"Windows.Management.Update.WindowsUpdateApprovalData";
#endif
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Management.Update.WindowsUpdateAttentionRequiredInfo
 *
 * Introduced to Windows.Management.Update.WindowsUpdateContract in version 1.0
 *
 * Class implements the following interfaces:
 *    Windows.Management.Update.IWindowsUpdateAttentionRequiredInfo ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Management_Update_WindowsUpdateAttentionRequiredInfo_DEFINED
#define RUNTIMECLASS_Windows_Management_Update_WindowsUpdateAttentionRequiredInfo_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Update_WindowsUpdateAttentionRequiredInfo[] = L"Windows.Management.Update.WindowsUpdateAttentionRequiredInfo";
#endif
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Management.Update.WindowsUpdateAttentionRequiredReasonChangedEventArgs
 *
 * Introduced to Windows.Management.Update.WindowsUpdateContract in version 1.0
 *
 * Class implements the following interfaces:
 *    Windows.Management.Update.IWindowsUpdateAttentionRequiredReasonChangedEventArgs ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Management_Update_WindowsUpdateAttentionRequiredReasonChangedEventArgs_DEFINED
#define RUNTIMECLASS_Windows_Management_Update_WindowsUpdateAttentionRequiredReasonChangedEventArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Update_WindowsUpdateAttentionRequiredReasonChangedEventArgs[] = L"Windows.Management.Update.WindowsUpdateAttentionRequiredReasonChangedEventArgs";
#endif
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Management.Update.WindowsUpdateGetAdministratorResult
 *
 * Introduced to Windows.Management.Update.WindowsUpdateContract in version 1.0
 *
 * Class implements the following interfaces:
 *    Windows.Management.Update.IWindowsUpdateGetAdministratorResult ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Management_Update_WindowsUpdateGetAdministratorResult_DEFINED
#define RUNTIMECLASS_Windows_Management_Update_WindowsUpdateGetAdministratorResult_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Update_WindowsUpdateGetAdministratorResult[] = L"Windows.Management.Update.WindowsUpdateGetAdministratorResult";
#endif
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Management.Update.WindowsUpdateItem
 *
 * Introduced to Windows.Management.Update.WindowsUpdateContract in version 1.0
 *
 * Class implements the following interfaces:
 *    Windows.Management.Update.IWindowsUpdateItem ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Management_Update_WindowsUpdateItem_DEFINED
#define RUNTIMECLASS_Windows_Management_Update_WindowsUpdateItem_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Update_WindowsUpdateItem[] = L"Windows.Management.Update.WindowsUpdateItem";
#endif
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Management.Update.WindowsUpdateManager
 *
 * Introduced to Windows.Management.Update.WindowsUpdateContract in version 1.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via the Windows.Management.Update.IWindowsUpdateManagerFactory interface starting with version 1.0 of the Windows.Management.Update.WindowsUpdateContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Management.Update.IWindowsUpdateManager ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Management_Update_WindowsUpdateManager_DEFINED
#define RUNTIMECLASS_Windows_Management_Update_WindowsUpdateManager_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Update_WindowsUpdateManager[] = L"Windows.Management.Update.WindowsUpdateManager";
#endif
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Management.Update.WindowsUpdateProgressChangedEventArgs
 *
 * Introduced to Windows.Management.Update.WindowsUpdateContract in version 1.0
 *
 * Class implements the following interfaces:
 *    Windows.Management.Update.IWindowsUpdateProgressChangedEventArgs ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Management_Update_WindowsUpdateProgressChangedEventArgs_DEFINED
#define RUNTIMECLASS_Windows_Management_Update_WindowsUpdateProgressChangedEventArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Update_WindowsUpdateProgressChangedEventArgs[] = L"Windows.Management.Update.WindowsUpdateProgressChangedEventArgs";
#endif
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Management.Update.WindowsUpdateRestartRequestOptions
 *
 * Introduced to Windows.Management.Update.WindowsUpdateContract in version 1.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via the Windows.Management.Update.IWindowsUpdateRestartRequestOptionsFactory interface starting with version 1.0 of the Windows.Management.Update.WindowsUpdateContract API contract
 *   Type can be activated via RoActivateInstance starting with version 1.0 of the Windows.Management.Update.WindowsUpdateContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Management.Update.IWindowsUpdateRestartRequestOptions ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Management_Update_WindowsUpdateRestartRequestOptions_DEFINED
#define RUNTIMECLASS_Windows_Management_Update_WindowsUpdateRestartRequestOptions_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Update_WindowsUpdateRestartRequestOptions[] = L"Windows.Management.Update.WindowsUpdateRestartRequestOptions";
#endif
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Management.Update.WindowsUpdateScanCompletedEventArgs
 *
 * Introduced to Windows.Management.Update.WindowsUpdateContract in version 1.0
 *
 * Class implements the following interfaces:
 *    Windows.Management.Update.IWindowsUpdateScanCompletedEventArgs ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Management_Update_WindowsUpdateScanCompletedEventArgs_DEFINED
#define RUNTIMECLASS_Windows_Management_Update_WindowsUpdateScanCompletedEventArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Update_WindowsUpdateScanCompletedEventArgs[] = L"Windows.Management.Update.WindowsUpdateScanCompletedEventArgs";
#endif
#endif // WINDOWS_MANAGEMENT_UPDATE_WINDOWSUPDATECONTRACT_VERSION >= 0x10000

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
