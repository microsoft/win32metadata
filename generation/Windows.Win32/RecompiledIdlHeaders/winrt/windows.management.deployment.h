
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
#ifndef __windows2Emanagement2Edeployment_h__
#define __windows2Emanagement2Edeployment_h__
#ifndef __windows2Emanagement2Edeployment_p_h__
#define __windows2Emanagement2Edeployment_p_h__


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
#if !defined(WINDOWS_APPLICATIONMODEL_FULLTRUSTAPPCONTRACT_VERSION)
#define WINDOWS_APPLICATIONMODEL_FULLTRUSTAPPCONTRACT_VERSION 0x10000
#endif // defined(WINDOWS_APPLICATIONMODEL_FULLTRUSTAPPCONTRACT_VERSION)

#if !defined(WINDOWS_APPLICATIONMODEL_STARTUPTASKCONTRACT_VERSION)
#define WINDOWS_APPLICATIONMODEL_STARTUPTASKCONTRACT_VERSION 0x30000
#endif // defined(WINDOWS_APPLICATIONMODEL_STARTUPTASKCONTRACT_VERSION)

#if !defined(WINDOWS_FOUNDATION_FOUNDATIONCONTRACT_VERSION)
#define WINDOWS_FOUNDATION_FOUNDATIONCONTRACT_VERSION 0x40000
#endif // defined(WINDOWS_FOUNDATION_FOUNDATIONCONTRACT_VERSION)

#if !defined(WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION)
#define WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION 0xa0000
#endif // defined(WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION)

#endif // defined(SPECIFIC_API_CONTRACT_DEFINITIONS)


// Header files for imported files
#include "inspectable.h"
#include "AsyncInfo.h"
#include "EventToken.h"
#include "windowscontracts.h"
#include "Windows.Foundation.h"
#include "Windows.ApplicationModel.h"
// Importing Collections header
#include <windows.foundation.collections.h>

#if defined(__cplusplus) && !defined(CINTERFACE)
/* Forward Declarations */
#ifndef ____x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Deployment {
                interface IAddPackageOptions;
            } /* Deployment */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions ABI::Windows::Management::Deployment::IAddPackageOptions

#endif // ____x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CDeployment_CIDeploymentResult_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CDeployment_CIDeploymentResult_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Deployment {
                interface IDeploymentResult;
            } /* Deployment */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CDeployment_CIDeploymentResult ABI::Windows::Management::Deployment::IDeploymentResult

#endif // ____x_ABI_CWindows_CManagement_CDeployment_CIDeploymentResult_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CDeployment_CIDeploymentResult2_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CDeployment_CIDeploymentResult2_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Deployment {
                interface IDeploymentResult2;
            } /* Deployment */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CDeployment_CIDeploymentResult2 ABI::Windows::Management::Deployment::IDeploymentResult2

#endif // ____x_ABI_CWindows_CManagement_CDeployment_CIDeploymentResult2_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Deployment {
                interface IPackageManager;
            } /* Deployment */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager ABI::Windows::Management::Deployment::IPackageManager

#endif // ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager2_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager2_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Deployment {
                interface IPackageManager2;
            } /* Deployment */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager2 ABI::Windows::Management::Deployment::IPackageManager2

#endif // ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager2_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager3_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager3_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Deployment {
                interface IPackageManager3;
            } /* Deployment */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager3 ABI::Windows::Management::Deployment::IPackageManager3

#endif // ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager3_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager4_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager4_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Deployment {
                interface IPackageManager4;
            } /* Deployment */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager4 ABI::Windows::Management::Deployment::IPackageManager4

#endif // ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager4_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager5_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager5_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Deployment {
                interface IPackageManager5;
            } /* Deployment */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager5 ABI::Windows::Management::Deployment::IPackageManager5

#endif // ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager5_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager6_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager6_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Deployment {
                interface IPackageManager6;
            } /* Deployment */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager6 ABI::Windows::Management::Deployment::IPackageManager6

#endif // ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager6_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager7_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager7_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Deployment {
                interface IPackageManager7;
            } /* Deployment */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager7 ABI::Windows::Management::Deployment::IPackageManager7

#endif // ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager7_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager8_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager8_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Deployment {
                interface IPackageManager8;
            } /* Deployment */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager8 ABI::Windows::Management::Deployment::IPackageManager8

#endif // ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager8_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager9_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager9_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Deployment {
                interface IPackageManager9;
            } /* Deployment */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager9 ABI::Windows::Management::Deployment::IPackageManager9

#endif // ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager9_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManagerDebugSettings_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManagerDebugSettings_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Deployment {
                interface IPackageManagerDebugSettings;
            } /* Deployment */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManagerDebugSettings ABI::Windows::Management::Deployment::IPackageManagerDebugSettings

#endif // ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManagerDebugSettings_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CDeployment_CIPackageUserInformation_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CDeployment_CIPackageUserInformation_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Deployment {
                interface IPackageUserInformation;
            } /* Deployment */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageUserInformation ABI::Windows::Management::Deployment::IPackageUserInformation

#endif // ____x_ABI_CWindows_CManagement_CDeployment_CIPackageUserInformation_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Deployment {
                interface IPackageVolume;
            } /* Deployment */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume ABI::Windows::Management::Deployment::IPackageVolume

#endif // ____x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume2_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume2_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Deployment {
                interface IPackageVolume2;
            } /* Deployment */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume2 ABI::Windows::Management::Deployment::IPackageVolume2

#endif // ____x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume2_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Deployment {
                interface IRegisterPackageOptions;
            } /* Deployment */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptions ABI::Windows::Management::Deployment::IRegisterPackageOptions

#endif // ____x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptions_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptions_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Deployment {
                interface IStagePackageOptions;
            } /* Deployment */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptions ABI::Windows::Management::Deployment::IStagePackageOptions

#endif // ____x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptions_FWD_DEFINED__

// Parameterized interface forward declarations (C++)

// Collection interface definitions

#ifndef DEF___FIAsyncOperation_1_UINT64_USE
#define DEF___FIAsyncOperation_1_UINT64_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation {
template <>
struct __declspec(uuid("2a70d630-0767-5f0a-a1c2-deb08126e26e"))
IAsyncOperation<UINT64> : IAsyncOperation_impl<UINT64>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.IAsyncOperation`1<UInt64>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IAsyncOperation<UINT64> __FIAsyncOperation_1_UINT64_t;
#define __FIAsyncOperation_1_UINT64 ABI::Windows::Foundation::__FIAsyncOperation_1_UINT64_t
/* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIAsyncOperation_1_UINT64_USE */



#ifndef DEF___FIAsyncOperationCompletedHandler_1_UINT64_USE
#define DEF___FIAsyncOperationCompletedHandler_1_UINT64_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation {
template <>
struct __declspec(uuid("ee8aeb02-fb00-51fa-8f57-32583ea241f9"))
IAsyncOperationCompletedHandler<UINT64> : IAsyncOperationCompletedHandler_impl<UINT64>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.AsyncOperationCompletedHandler`1<UInt64>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IAsyncOperationCompletedHandler<UINT64> __FIAsyncOperationCompletedHandler_1_UINT64_t;
#define __FIAsyncOperationCompletedHandler_1_UINT64 ABI::Windows::Foundation::__FIAsyncOperationCompletedHandler_1_UINT64_t
/* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIAsyncOperationCompletedHandler_1_UINT64_USE */


namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Deployment {
                class PackageVolume;
            } /* Deployment */
        } /* Management */
    } /* Windows */
} /* ABI */

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#ifndef DEF___FIIterator_1_Windows__CManagement__CDeployment__CPackageVolume_USE
#define DEF___FIIterator_1_Windows__CManagement__CDeployment__CPackageVolume_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("a8d5b736-4e68-5ef1-9f07-f06837988c73"))
IIterator<ABI::Windows::Management::Deployment::PackageVolume*> : IIterator_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Management::Deployment::PackageVolume*, ABI::Windows::Management::Deployment::IPackageVolume*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IIterator`1<Windows.Management.Deployment.PackageVolume>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterator<ABI::Windows::Management::Deployment::PackageVolume*> __FIIterator_1_Windows__CManagement__CDeployment__CPackageVolume_t;
#define __FIIterator_1_Windows__CManagement__CDeployment__CPackageVolume ABI::Windows::Foundation::Collections::__FIIterator_1_Windows__CManagement__CDeployment__CPackageVolume_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterator_1_Windows__CManagement__CDeployment__CPackageVolume_USE */

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#ifndef DEF___FIIterable_1_Windows__CManagement__CDeployment__CPackageVolume_USE
#define DEF___FIIterable_1_Windows__CManagement__CDeployment__CPackageVolume_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("a6199162-b163-56a1-9980-db0c3f4e9284"))
IIterable<ABI::Windows::Management::Deployment::PackageVolume*> : IIterable_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Management::Deployment::PackageVolume*, ABI::Windows::Management::Deployment::IPackageVolume*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IIterable`1<Windows.Management.Deployment.PackageVolume>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterable<ABI::Windows::Management::Deployment::PackageVolume*> __FIIterable_1_Windows__CManagement__CDeployment__CPackageVolume_t;
#define __FIIterable_1_Windows__CManagement__CDeployment__CPackageVolume ABI::Windows::Foundation::Collections::__FIIterable_1_Windows__CManagement__CDeployment__CPackageVolume_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterable_1_Windows__CManagement__CDeployment__CPackageVolume_USE */

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#ifndef DEF___FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume_USE
#define DEF___FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("50b5715a-f077-53d1-896d-b132c48701f4"))
IVectorView<ABI::Windows::Management::Deployment::PackageVolume*> : IVectorView_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Management::Deployment::PackageVolume*, ABI::Windows::Management::Deployment::IPackageVolume*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IVectorView`1<Windows.Management.Deployment.PackageVolume>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IVectorView<ABI::Windows::Management::Deployment::PackageVolume*> __FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume_t;
#define __FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume ABI::Windows::Foundation::Collections::__FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume_USE */

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#ifndef DEF___FIAsyncOperation_1___FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume_USE
#define DEF___FIAsyncOperation_1___FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation {
template <>
struct __declspec(uuid("1e357e07-d337-5c07-ae06-900c1b9a77c1"))
IAsyncOperation<__FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume*> : IAsyncOperation_impl<__FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume*>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.IAsyncOperation`1<Windows.Foundation.Collections.IVectorView`1<Windows.Management.Deployment.PackageVolume>>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IAsyncOperation<__FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume*> __FIAsyncOperation_1___FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume_t;
#define __FIAsyncOperation_1___FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume ABI::Windows::Foundation::__FIAsyncOperation_1___FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume_t
/* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIAsyncOperation_1___FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume_USE */

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#ifndef DEF___FIAsyncOperationCompletedHandler_1___FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume_USE
#define DEF___FIAsyncOperationCompletedHandler_1___FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation {
template <>
struct __declspec(uuid("721241c2-0b83-594a-9b61-ce7f1492c415"))
IAsyncOperationCompletedHandler<__FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume*> : IAsyncOperationCompletedHandler_impl<__FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume*>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.AsyncOperationCompletedHandler`1<Windows.Foundation.Collections.IVectorView`1<Windows.Management.Deployment.PackageVolume>>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IAsyncOperationCompletedHandler<__FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume*> __FIAsyncOperationCompletedHandler_1___FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume_t;
#define __FIAsyncOperationCompletedHandler_1___FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume ABI::Windows::Foundation::__FIAsyncOperationCompletedHandler_1___FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume_t
/* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIAsyncOperationCompletedHandler_1___FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume_USE */

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#ifndef DEF___FIAsyncOperation_1_Windows__CManagement__CDeployment__CPackageVolume_USE
#define DEF___FIAsyncOperation_1_Windows__CManagement__CDeployment__CPackageVolume_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation {
template <>
struct __declspec(uuid("0315edb6-dc58-51cc-a519-44901ad2cf15"))
IAsyncOperation<ABI::Windows::Management::Deployment::PackageVolume*> : IAsyncOperation_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Management::Deployment::PackageVolume*, ABI::Windows::Management::Deployment::IPackageVolume*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.IAsyncOperation`1<Windows.Management.Deployment.PackageVolume>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IAsyncOperation<ABI::Windows::Management::Deployment::PackageVolume*> __FIAsyncOperation_1_Windows__CManagement__CDeployment__CPackageVolume_t;
#define __FIAsyncOperation_1_Windows__CManagement__CDeployment__CPackageVolume ABI::Windows::Foundation::__FIAsyncOperation_1_Windows__CManagement__CDeployment__CPackageVolume_t
/* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIAsyncOperation_1_Windows__CManagement__CDeployment__CPackageVolume_USE */

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#ifndef DEF___FIAsyncOperationCompletedHandler_1_Windows__CManagement__CDeployment__CPackageVolume_USE
#define DEF___FIAsyncOperationCompletedHandler_1_Windows__CManagement__CDeployment__CPackageVolume_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation {
template <>
struct __declspec(uuid("35fee361-6cea-5e5c-8eda-34b3f22df4e7"))
IAsyncOperationCompletedHandler<ABI::Windows::Management::Deployment::PackageVolume*> : IAsyncOperationCompletedHandler_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Management::Deployment::PackageVolume*, ABI::Windows::Management::Deployment::IPackageVolume*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.AsyncOperationCompletedHandler`1<Windows.Management.Deployment.PackageVolume>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IAsyncOperationCompletedHandler<ABI::Windows::Management::Deployment::PackageVolume*> __FIAsyncOperationCompletedHandler_1_Windows__CManagement__CDeployment__CPackageVolume_t;
#define __FIAsyncOperationCompletedHandler_1_Windows__CManagement__CDeployment__CPackageVolume ABI::Windows::Foundation::__FIAsyncOperationCompletedHandler_1_Windows__CManagement__CDeployment__CPackageVolume_t
/* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIAsyncOperationCompletedHandler_1_Windows__CManagement__CDeployment__CPackageVolume_USE */

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Deployment {
                class DeploymentResult;
            } /* Deployment */
        } /* Management */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Deployment {
                typedef struct DeploymentProgress DeploymentProgress;
            } /* Deployment */
        } /* Management */
    } /* Windows */
} /* ABI */

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#ifndef DEF___FIAsyncOperationWithProgressCompletedHandler_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress_USE
#define DEF___FIAsyncOperationWithProgressCompletedHandler_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation {
template <>
struct __declspec(uuid("6e1c7129-61e0-5d88-9fd4-f3ce65a05719"))
IAsyncOperationWithProgressCompletedHandler<ABI::Windows::Management::Deployment::DeploymentResult*, struct ABI::Windows::Management::Deployment::DeploymentProgress> : IAsyncOperationWithProgressCompletedHandler_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Management::Deployment::DeploymentResult*, ABI::Windows::Management::Deployment::IDeploymentResult*>, struct ABI::Windows::Management::Deployment::DeploymentProgress>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.AsyncOperationWithProgressCompletedHandler`2<Windows.Management.Deployment.DeploymentResult, Windows.Management.Deployment.DeploymentProgress>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IAsyncOperationWithProgressCompletedHandler<ABI::Windows::Management::Deployment::DeploymentResult*, struct ABI::Windows::Management::Deployment::DeploymentProgress> __FIAsyncOperationWithProgressCompletedHandler_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress_t;
#define __FIAsyncOperationWithProgressCompletedHandler_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress ABI::Windows::Foundation::__FIAsyncOperationWithProgressCompletedHandler_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress_t
/* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIAsyncOperationWithProgressCompletedHandler_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress_USE */

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#ifndef DEF___FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress_USE
#define DEF___FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation {
template <>
struct __declspec(uuid("5a97aab7-b6ea-55ac-a5dc-d5b164d94e94"))
IAsyncOperationWithProgress<ABI::Windows::Management::Deployment::DeploymentResult*, struct ABI::Windows::Management::Deployment::DeploymentProgress> : IAsyncOperationWithProgress_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Management::Deployment::DeploymentResult*, ABI::Windows::Management::Deployment::IDeploymentResult*>, struct ABI::Windows::Management::Deployment::DeploymentProgress>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.IAsyncOperationWithProgress`2<Windows.Management.Deployment.DeploymentResult, Windows.Management.Deployment.DeploymentProgress>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IAsyncOperationWithProgress<ABI::Windows::Management::Deployment::DeploymentResult*, struct ABI::Windows::Management::Deployment::DeploymentProgress> __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress_t;
#define __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress ABI::Windows::Foundation::__FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress_t
/* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress_USE */

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#ifndef DEF___FIAsyncOperationProgressHandler_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress_USE
#define DEF___FIAsyncOperationProgressHandler_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation {
template <>
struct __declspec(uuid("f1b926d1-1796-597a-9bea-6c6449d03eef"))
IAsyncOperationProgressHandler<ABI::Windows::Management::Deployment::DeploymentResult*, struct ABI::Windows::Management::Deployment::DeploymentProgress> : IAsyncOperationProgressHandler_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Management::Deployment::DeploymentResult*, ABI::Windows::Management::Deployment::IDeploymentResult*>, struct ABI::Windows::Management::Deployment::DeploymentProgress>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.AsyncOperationProgressHandler`2<Windows.Management.Deployment.DeploymentResult, Windows.Management.Deployment.DeploymentProgress>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IAsyncOperationProgressHandler<ABI::Windows::Management::Deployment::DeploymentResult*, struct ABI::Windows::Management::Deployment::DeploymentProgress> __FIAsyncOperationProgressHandler_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress_t;
#define __FIAsyncOperationProgressHandler_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress ABI::Windows::Foundation::__FIAsyncOperationProgressHandler_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress_t
/* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIAsyncOperationProgressHandler_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress_USE */

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000


#ifndef DEF___FIIterator_1_HSTRING_USE
#define DEF___FIIterator_1_HSTRING_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("8c304ebb-6615-50a4-8829-879ecd443236"))
IIterator<HSTRING> : IIterator_impl<HSTRING>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IIterator`1<String>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterator<HSTRING> __FIIterator_1_HSTRING_t;
#define __FIIterator_1_HSTRING ABI::Windows::Foundation::Collections::__FIIterator_1_HSTRING_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterator_1_HSTRING_USE */



#ifndef DEF___FIIterable_1_HSTRING_USE
#define DEF___FIIterable_1_HSTRING_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("e2fcc7c1-3bfc-5a0b-b2b0-72e769d1cb7e"))
IIterable<HSTRING> : IIterable_impl<HSTRING>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IIterable`1<String>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterable<HSTRING> __FIIterable_1_HSTRING_t;
#define __FIIterable_1_HSTRING ABI::Windows::Foundation::Collections::__FIIterable_1_HSTRING_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterable_1_HSTRING_USE */


namespace ABI {
    namespace Windows {
        namespace ApplicationModel {
            class Package;
        } /* ApplicationModel */
    } /* Windows */
} /* ABI */

#ifndef ____x_ABI_CWindows_CApplicationModel_CIPackage_FWD_DEFINED__
#define ____x_ABI_CWindows_CApplicationModel_CIPackage_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace ApplicationModel {
            interface IPackage;
        } /* ApplicationModel */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CApplicationModel_CIPackage ABI::Windows::ApplicationModel::IPackage

#endif // ____x_ABI_CWindows_CApplicationModel_CIPackage_FWD_DEFINED__

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#ifndef DEF___FIIterator_1_Windows__CApplicationModel__CPackage_USE
#define DEF___FIIterator_1_Windows__CApplicationModel__CPackage_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("0217f069-025c-5ee6-a87f-e782e3b623ae"))
IIterator<ABI::Windows::ApplicationModel::Package*> : IIterator_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::ApplicationModel::Package*, ABI::Windows::ApplicationModel::IPackage*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IIterator`1<Windows.ApplicationModel.Package>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterator<ABI::Windows::ApplicationModel::Package*> __FIIterator_1_Windows__CApplicationModel__CPackage_t;
#define __FIIterator_1_Windows__CApplicationModel__CPackage ABI::Windows::Foundation::Collections::__FIIterator_1_Windows__CApplicationModel__CPackage_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterator_1_Windows__CApplicationModel__CPackage_USE */

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#ifndef DEF___FIIterable_1_Windows__CApplicationModel__CPackage_USE
#define DEF___FIIterable_1_Windows__CApplicationModel__CPackage_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("69ad6aa7-0c49-5f27-a5eb-ef4d59467b6d"))
IIterable<ABI::Windows::ApplicationModel::Package*> : IIterable_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::ApplicationModel::Package*, ABI::Windows::ApplicationModel::IPackage*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IIterable`1<Windows.ApplicationModel.Package>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterable<ABI::Windows::ApplicationModel::Package*> __FIIterable_1_Windows__CApplicationModel__CPackage_t;
#define __FIIterable_1_Windows__CApplicationModel__CPackage ABI::Windows::Foundation::Collections::__FIIterable_1_Windows__CApplicationModel__CPackage_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterable_1_Windows__CApplicationModel__CPackage_USE */

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

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

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#ifndef DEF___FIIterator_1_Windows__CFoundation__CUri_USE
#define DEF___FIIterator_1_Windows__CFoundation__CUri_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("1c157d0f-5efe-5cec-bbd6-0c6ce9af07a5"))
IIterator<ABI::Windows::Foundation::Uri*> : IIterator_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Foundation::Uri*, ABI::Windows::Foundation::IUriRuntimeClass*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IIterator`1<Windows.Foundation.Uri>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterator<ABI::Windows::Foundation::Uri*> __FIIterator_1_Windows__CFoundation__CUri_t;
#define __FIIterator_1_Windows__CFoundation__CUri ABI::Windows::Foundation::Collections::__FIIterator_1_Windows__CFoundation__CUri_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterator_1_Windows__CFoundation__CUri_USE */

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#ifndef DEF___FIIterable_1_Windows__CFoundation__CUri_USE
#define DEF___FIIterable_1_Windows__CFoundation__CUri_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("b0d63b78-78ad-5e31-b6d8-e32a0e16c447"))
IIterable<ABI::Windows::Foundation::Uri*> : IIterable_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Foundation::Uri*, ABI::Windows::Foundation::IUriRuntimeClass*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IIterable`1<Windows.Foundation.Uri>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterable<ABI::Windows::Foundation::Uri*> __FIIterable_1_Windows__CFoundation__CUri_t;
#define __FIIterable_1_Windows__CFoundation__CUri ABI::Windows::Foundation::Collections::__FIIterable_1_Windows__CFoundation__CUri_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterable_1_Windows__CFoundation__CUri_USE */

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Deployment {
                class PackageUserInformation;
            } /* Deployment */
        } /* Management */
    } /* Windows */
} /* ABI */

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#ifndef DEF___FIIterator_1_Windows__CManagement__CDeployment__CPackageUserInformation_USE
#define DEF___FIIterator_1_Windows__CManagement__CDeployment__CPackageUserInformation_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("75660566-ae43-5858-ada6-d57ddae90277"))
IIterator<ABI::Windows::Management::Deployment::PackageUserInformation*> : IIterator_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Management::Deployment::PackageUserInformation*, ABI::Windows::Management::Deployment::IPackageUserInformation*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IIterator`1<Windows.Management.Deployment.PackageUserInformation>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterator<ABI::Windows::Management::Deployment::PackageUserInformation*> __FIIterator_1_Windows__CManagement__CDeployment__CPackageUserInformation_t;
#define __FIIterator_1_Windows__CManagement__CDeployment__CPackageUserInformation ABI::Windows::Foundation::Collections::__FIIterator_1_Windows__CManagement__CDeployment__CPackageUserInformation_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterator_1_Windows__CManagement__CDeployment__CPackageUserInformation_USE */

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#ifndef DEF___FIIterable_1_Windows__CManagement__CDeployment__CPackageUserInformation_USE
#define DEF___FIIterable_1_Windows__CManagement__CDeployment__CPackageUserInformation_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("341348b9-52c8-5b57-9e91-f19f2a05b188"))
IIterable<ABI::Windows::Management::Deployment::PackageUserInformation*> : IIterable_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Management::Deployment::PackageUserInformation*, ABI::Windows::Management::Deployment::IPackageUserInformation*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IIterable`1<Windows.Management.Deployment.PackageUserInformation>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterable<ABI::Windows::Management::Deployment::PackageUserInformation*> __FIIterable_1_Windows__CManagement__CDeployment__CPackageUserInformation_t;
#define __FIIterable_1_Windows__CManagement__CDeployment__CPackageUserInformation ABI::Windows::Foundation::Collections::__FIIterable_1_Windows__CManagement__CDeployment__CPackageUserInformation_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterable_1_Windows__CManagement__CDeployment__CPackageUserInformation_USE */

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000


#ifndef DEF___FIVectorView_1_HSTRING_USE
#define DEF___FIVectorView_1_HSTRING_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("2f13c006-a03a-5f69-b090-75a43e33423e"))
IVectorView<HSTRING> : IVectorView_impl<HSTRING>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IVectorView`1<String>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IVectorView<HSTRING> __FIVectorView_1_HSTRING_t;
#define __FIVectorView_1_HSTRING ABI::Windows::Foundation::Collections::__FIVectorView_1_HSTRING_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIVectorView_1_HSTRING_USE */


#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#ifndef DEF___FIVectorView_1_Windows__CApplicationModel__CPackage_USE
#define DEF___FIVectorView_1_Windows__CApplicationModel__CPackage_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("0263c4d4-195c-5dc5-a7ca-6806ceca420b"))
IVectorView<ABI::Windows::ApplicationModel::Package*> : IVectorView_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::ApplicationModel::Package*, ABI::Windows::ApplicationModel::IPackage*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IVectorView`1<Windows.ApplicationModel.Package>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IVectorView<ABI::Windows::ApplicationModel::Package*> __FIVectorView_1_Windows__CApplicationModel__CPackage_t;
#define __FIVectorView_1_Windows__CApplicationModel__CPackage ABI::Windows::Foundation::Collections::__FIVectorView_1_Windows__CApplicationModel__CPackage_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIVectorView_1_Windows__CApplicationModel__CPackage_USE */

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#ifndef DEF___FIVectorView_1_Windows__CFoundation__CUri_USE
#define DEF___FIVectorView_1_Windows__CFoundation__CUri_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("4b8385bd-a2cd-5ff1-bf74-7ea580423e50"))
IVectorView<ABI::Windows::Foundation::Uri*> : IVectorView_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Foundation::Uri*, ABI::Windows::Foundation::IUriRuntimeClass*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IVectorView`1<Windows.Foundation.Uri>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IVectorView<ABI::Windows::Foundation::Uri*> __FIVectorView_1_Windows__CFoundation__CUri_t;
#define __FIVectorView_1_Windows__CFoundation__CUri ABI::Windows::Foundation::Collections::__FIVectorView_1_Windows__CFoundation__CUri_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIVectorView_1_Windows__CFoundation__CUri_USE */

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000


#ifndef DEF___FIVector_1_HSTRING_USE
#define DEF___FIVector_1_HSTRING_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("98b9acc1-4b56-532e-ac73-03d5291cca90"))
IVector<HSTRING> : IVector_impl<HSTRING>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IVector`1<String>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IVector<HSTRING> __FIVector_1_HSTRING_t;
#define __FIVector_1_HSTRING ABI::Windows::Foundation::Collections::__FIVector_1_HSTRING_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIVector_1_HSTRING_USE */


#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#ifndef DEF___FIVector_1_Windows__CApplicationModel__CPackage_USE
#define DEF___FIVector_1_Windows__CApplicationModel__CPackage_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("d1bb509e-6989-5c69-b1ff-d1702fe8aca3"))
IVector<ABI::Windows::ApplicationModel::Package*> : IVector_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::ApplicationModel::Package*, ABI::Windows::ApplicationModel::IPackage*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IVector`1<Windows.ApplicationModel.Package>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IVector<ABI::Windows::ApplicationModel::Package*> __FIVector_1_Windows__CApplicationModel__CPackage_t;
#define __FIVector_1_Windows__CApplicationModel__CPackage ABI::Windows::Foundation::Collections::__FIVector_1_Windows__CApplicationModel__CPackage_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIVector_1_Windows__CApplicationModel__CPackage_USE */

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#ifndef DEF___FIVector_1_Windows__CFoundation__CUri_USE
#define DEF___FIVector_1_Windows__CFoundation__CUri_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("0d82bd8d-fe62-5d67-a7b9-7886dd75bc4e"))
IVector<ABI::Windows::Foundation::Uri*> : IVector_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Foundation::Uri*, ABI::Windows::Foundation::IUriRuntimeClass*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IVector`1<Windows.Foundation.Uri>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IVector<ABI::Windows::Foundation::Uri*> __FIVector_1_Windows__CFoundation__CUri_t;
#define __FIVector_1_Windows__CFoundation__CUri ABI::Windows::Foundation::Collections::__FIVector_1_Windows__CFoundation__CUri_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIVector_1_Windows__CFoundation__CUri_USE */

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

namespace ABI {
    namespace Windows {
        namespace ApplicationModel {
            typedef enum PackageContentGroupState : int PackageContentGroupState;
        } /* ApplicationModel */
    } /* Windows */
} /* ABI */

#ifndef ____x_ABI_CWindows_CFoundation_CIAsyncAction_FWD_DEFINED__
#define ____x_ABI_CWindows_CFoundation_CIAsyncAction_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Foundation {
            interface IAsyncAction;
        } /* Foundation */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CFoundation_CIAsyncAction ABI::Windows::Foundation::IAsyncAction

#endif // ____x_ABI_CWindows_CFoundation_CIAsyncAction_FWD_DEFINED__

namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Deployment {
                typedef enum AddPackageByAppInstallerOptions : unsigned int AddPackageByAppInstallerOptions;
            } /* Deployment */
        } /* Management */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Deployment {
                typedef enum DeploymentOptions : unsigned int DeploymentOptions;
            } /* Deployment */
        } /* Management */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Deployment {
                typedef enum DeploymentProgressState : int DeploymentProgressState;
            } /* Deployment */
        } /* Management */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Deployment {
                typedef enum PackageInstallState : int PackageInstallState;
            } /* Deployment */
        } /* Management */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Deployment {
                typedef enum PackageState : int PackageState;
            } /* Deployment */
        } /* Management */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Deployment {
                typedef enum PackageStatus : unsigned int PackageStatus;
            } /* Deployment */
        } /* Management */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Deployment {
                typedef enum PackageStubPreference : int PackageStubPreference;
            } /* Deployment */
        } /* Management */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Deployment {
                typedef enum PackageTypes : unsigned int PackageTypes;
            } /* Deployment */
        } /* Management */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Deployment {
                typedef enum RemovalOptions : unsigned int RemovalOptions;
            } /* Deployment */
        } /* Management */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Deployment {
                typedef enum StubPackageOption : int StubPackageOption;
            } /* Deployment */
        } /* Management */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Deployment {
                class AddPackageOptions;
            } /* Deployment */
        } /* Management */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Deployment {
                class PackageManagerDebugSettings;
            } /* Deployment */
        } /* Management */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Deployment {
                class RegisterPackageOptions;
            } /* Deployment */
        } /* Management */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Deployment {
                class StagePackageOptions;
            } /* Deployment */
        } /* Management */
    } /* Windows */
} /* ABI */

/*
 *
 * Struct Windows.Management.Deployment.AddPackageByAppInstallerOptions
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Deployment {
                enum AddPackageByAppInstallerOptions : unsigned int
                {
                    AddPackageByAppInstallerOptions_None = 0,
                    AddPackageByAppInstallerOptions_InstallAllResources = 0x20,
                    AddPackageByAppInstallerOptions_ForceTargetAppShutdown = 0x40,
                    AddPackageByAppInstallerOptions_RequiredContentGroupOnly = 0x100,
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x80000
                    AddPackageByAppInstallerOptions_LimitToExistingPackages = 0x200,
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x80000
                };

                DEFINE_ENUM_FLAG_OPERATORS(AddPackageByAppInstallerOptions)
            } /* Deployment */
        } /* Management */
    } /* Windows */
} /* ABI */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Struct Windows.Management.Deployment.DeploymentOptions
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Deployment {
                enum DeploymentOptions : unsigned int
                {
                    DeploymentOptions_None = 0,
                    DeploymentOptions_ForceApplicationShutdown = 0x1,
                    DeploymentOptions_DevelopmentMode = 0x2,
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
                    DeploymentOptions_InstallAllResources = 0x20,
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
                    DeploymentOptions_ForceTargetApplicationShutdown = 0x40,
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x40000
                    DeploymentOptions_RequiredContentGroupOnly = 0x100,
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x40000
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x70000
                    DeploymentOptions_ForceUpdateFromAnyVersion = 0x40000,
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x70000
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xa0000
                    DeploymentOptions_RetainFilesOnFailure = 0x200000,
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xa0000
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xa0000
                    DeploymentOptions_StageInPlace = 0x400000,
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xa0000
                };

                DEFINE_ENUM_FLAG_OPERATORS(DeploymentOptions)
            } /* Deployment */
        } /* Management */
    } /* Windows */
} /* ABI */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Struct Windows.Management.Deployment.DeploymentProgressState
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Deployment {
                enum DeploymentProgressState : int
                {
                    DeploymentProgressState_Queued = 0,
                    DeploymentProgressState_Processing = 1,
                };
            } /* Deployment */
        } /* Management */
    } /* Windows */
} /* ABI */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Struct Windows.Management.Deployment.PackageInstallState
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Deployment {
                enum PackageInstallState : int
                {
                    PackageInstallState_NotInstalled = 0,
                    PackageInstallState_Staged = 1,
                    PackageInstallState_Installed = 2,
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x20000
                    PackageInstallState_Paused = 6,
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x20000
                };
            } /* Deployment */
        } /* Management */
    } /* Windows */
} /* ABI */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Struct Windows.Management.Deployment.PackageState
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Deployment {
                enum PackageState : int
                {
                    PackageState_Normal = 0,
                    PackageState_LicenseInvalid = 1,
                    PackageState_Modified = 2,
                    PackageState_Tampered = 3,
                };
            } /* Deployment */
        } /* Management */
    } /* Windows */
} /* ABI */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Struct Windows.Management.Deployment.PackageStatus
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Deployment {
                enum PackageStatus : unsigned int
                {
                    PackageStatus_OK = 0,
                    PackageStatus_LicenseIssue = 0x1,
                    PackageStatus_Modified = 0x2,
                    PackageStatus_Tampered = 0x4,
                    PackageStatus_Disabled = 0x8,
                };

                DEFINE_ENUM_FLAG_OPERATORS(PackageStatus)
            } /* Deployment */
        } /* Management */
    } /* Windows */
} /* ABI */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Struct Windows.Management.Deployment.PackageStubPreference
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 10.0
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xa0000
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Deployment {
                enum PackageStubPreference : int
                {
                    PackageStubPreference_Full = 0,
                    PackageStubPreference_Stub = 1,
                };
            } /* Deployment */
        } /* Management */
    } /* Windows */
} /* ABI */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xa0000

/*
 *
 * Struct Windows.Management.Deployment.PackageTypes
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Deployment {
                enum PackageTypes : unsigned int
                {
                    PackageTypes_None = 0,
                    PackageTypes_Main = 0x1,
                    PackageTypes_Framework = 0x2,
                    PackageTypes_Resource = 0x4,
                    PackageTypes_Bundle = 0x8,
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
                    PackageTypes_Xap = 0x10,
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x30000
                    PackageTypes_Optional = 0x20,
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x30000
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xa0000
                    PackageTypes_All = 0xffffffff,
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xa0000
                };

                DEFINE_ENUM_FLAG_OPERATORS(PackageTypes)
            } /* Deployment */
        } /* Management */
    } /* Windows */
} /* ABI */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Struct Windows.Management.Deployment.RemovalOptions
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Deployment {
                enum RemovalOptions : unsigned int
                {
                    RemovalOptions_None = 0,
                    RemovalOptions_PreserveApplicationData = 0x1000,
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xa0000
                    RemovalOptions_PreserveRoamableApplicationData = 0x80,
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xa0000
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x70000
                    RemovalOptions_RemoveForAllUsers = 0x80000,
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x70000
                };

                DEFINE_ENUM_FLAG_OPERATORS(RemovalOptions)
            } /* Deployment */
        } /* Management */
    } /* Windows */
} /* ABI */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Struct Windows.Management.Deployment.StubPackageOption
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 10.0
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xa0000
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Deployment {
                enum StubPackageOption : int
                {
                    StubPackageOption_Default = 0,
                    StubPackageOption_InstallFull = 1,
                    StubPackageOption_InstallStub = 2,
                    StubPackageOption_UsePreference = 3,
                };
            } /* Deployment */
        } /* Management */
    } /* Windows */
} /* ABI */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xa0000

/*
 *
 * Struct Windows.Management.Deployment.DeploymentProgress
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Deployment {
                struct DeploymentProgress
                {
                    ABI::Windows::Management::Deployment::DeploymentProgressState state;
                    UINT32 percentage;
                };
            } /* Deployment */
        } /* Management */
    } /* Windows */
} /* ABI */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Deployment.IAddPackageOptions
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 10.0
 *
 * Interface is a part of the implementation of type Windows.Management.Deployment.AddPackageOptions
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xa0000
#if !defined(____x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Deployment_IAddPackageOptions[] = L"Windows.Management.Deployment.IAddPackageOptions";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Deployment {
                MIDL_INTERFACE("05cee018-f68f-422b-95a4-66679ec77fc0")
                IAddPackageOptions : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE get_DependencyPackageUris(
                        __FIVector_1_Windows__CFoundation__CUri** value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_TargetVolume(
                        ABI::Windows::Management::Deployment::IPackageVolume** value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_TargetVolume(
                        ABI::Windows::Management::Deployment::IPackageVolume* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_OptionalPackageFamilyNames(
                        __FIVector_1_HSTRING** value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_OptionalPackageUris(
                        __FIVector_1_Windows__CFoundation__CUri** value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_RelatedPackageUris(
                        __FIVector_1_Windows__CFoundation__CUri** value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_ExternalLocationUri(
                        ABI::Windows::Foundation::IUriRuntimeClass** value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_ExternalLocationUri(
                        ABI::Windows::Foundation::IUriRuntimeClass* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_StubPackageOption(
                        ABI::Windows::Management::Deployment::StubPackageOption* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_StubPackageOption(
                        ABI::Windows::Management::Deployment::StubPackageOption value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_DeveloperMode(
                        boolean* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_DeveloperMode(
                        boolean value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_ForceAppShutdown(
                        boolean* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_ForceAppShutdown(
                        boolean value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_ForceTargetAppShutdown(
                        boolean* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_ForceTargetAppShutdown(
                        boolean value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_ForceUpdateFromAnyVersion(
                        boolean* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_ForceUpdateFromAnyVersion(
                        boolean value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_InstallAllResources(
                        boolean* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_InstallAllResources(
                        boolean value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_RequiredContentGroupOnly(
                        boolean* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_RequiredContentGroupOnly(
                        boolean value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_RetainFilesOnFailure(
                        boolean* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_RetainFilesOnFailure(
                        boolean value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_StageInPlace(
                        boolean* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_StageInPlace(
                        boolean value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_AllowUnsigned(
                        boolean* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_AllowUnsigned(
                        boolean value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_DeferRegistrationWhenPackagesAreInUse(
                        boolean* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_DeferRegistrationWhenPackagesAreInUse(
                        boolean value
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IAddPackageOptions = _uuidof(IAddPackageOptions);
            } /* Deployment */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions;
#endif /* !defined(____x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xa0000

/*
 *
 * Interface Windows.Management.Deployment.IDeploymentResult
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Deployment.DeploymentResult
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CDeployment_CIDeploymentResult_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CDeployment_CIDeploymentResult_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Deployment_IDeploymentResult[] = L"Windows.Management.Deployment.IDeploymentResult";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Deployment {
                MIDL_INTERFACE("2563b9ae-b77d-4c1f-8a7b-20e6ad515ef3")
                IDeploymentResult : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE get_ErrorText(
                        HSTRING* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_ActivityId(
                        GUID* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_ExtendedErrorCode(
                        HRESULT* value
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IDeploymentResult = _uuidof(IDeploymentResult);
            } /* Deployment */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CDeployment_CIDeploymentResult;
#endif /* !defined(____x_ABI_CWindows_CManagement_CDeployment_CIDeploymentResult_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Deployment.IDeploymentResult2
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 4.0
 *
 * Interface is a part of the implementation of type Windows.Management.Deployment.DeploymentResult
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x40000
#if !defined(____x_ABI_CWindows_CManagement_CDeployment_CIDeploymentResult2_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CDeployment_CIDeploymentResult2_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Deployment_IDeploymentResult2[] = L"Windows.Management.Deployment.IDeploymentResult2";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Deployment {
                MIDL_INTERFACE("fc0e715c-5a01-4bd7-bcf1-381c8c82e04a")
                IDeploymentResult2 : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE get_IsRegistered(
                        boolean* value
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IDeploymentResult2 = _uuidof(IDeploymentResult2);
            } /* Deployment */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CDeployment_CIDeploymentResult2;
#endif /* !defined(____x_ABI_CWindows_CManagement_CDeployment_CIDeploymentResult2_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x40000

/*
 *
 * Interface Windows.Management.Deployment.IPackageManager
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Deployment.PackageManager
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Deployment_IPackageManager[] = L"Windows.Management.Deployment.IPackageManager";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Deployment {
                MIDL_INTERFACE("9a7d4b65-5e8f-4fc7-a2e5-7f6925cb8b53")
                IPackageManager : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE AddPackageAsync(
                        ABI::Windows::Foundation::IUriRuntimeClass* packageUri,
                        __FIIterable_1_Windows__CFoundation__CUri* dependencyPackageUris,
                        ABI::Windows::Management::Deployment::DeploymentOptions deploymentOptions,
                        __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress** deploymentOperation
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE UpdatePackageAsync(
                        ABI::Windows::Foundation::IUriRuntimeClass* packageUri,
                        __FIIterable_1_Windows__CFoundation__CUri* dependencyPackageUris,
                        ABI::Windows::Management::Deployment::DeploymentOptions deploymentOptions,
                        __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress** deploymentOperation
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE RemovePackageAsync(
                        HSTRING packageFullName,
                        __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress** deploymentOperation
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE StagePackageAsync(
                        ABI::Windows::Foundation::IUriRuntimeClass* packageUri,
                        __FIIterable_1_Windows__CFoundation__CUri* dependencyPackageUris,
                        __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress** deploymentOperation
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE RegisterPackageAsync(
                        ABI::Windows::Foundation::IUriRuntimeClass* manifestUri,
                        __FIIterable_1_Windows__CFoundation__CUri* dependencyPackageUris,
                        ABI::Windows::Management::Deployment::DeploymentOptions deploymentOptions,
                        __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress** deploymentOperation
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE FindPackages(
                        __FIIterable_1_Windows__CApplicationModel__CPackage** packageCollection
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE FindPackagesByUserSecurityId(
                        HSTRING userSecurityId,
                        __FIIterable_1_Windows__CApplicationModel__CPackage** packageCollection
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE FindPackagesByNamePublisher(
                        HSTRING packageName,
                        HSTRING packagePublisher,
                        __FIIterable_1_Windows__CApplicationModel__CPackage** packageCollection
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE FindPackagesByUserSecurityIdNamePublisher(
                        HSTRING userSecurityId,
                        HSTRING packageName,
                        HSTRING packagePublisher,
                        __FIIterable_1_Windows__CApplicationModel__CPackage** packageCollection
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE FindUsers(
                        HSTRING packageFullName,
                        __FIIterable_1_Windows__CManagement__CDeployment__CPackageUserInformation** users
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE SetPackageState(
                        HSTRING packageFullName,
                        ABI::Windows::Management::Deployment::PackageState packageState
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE FindPackageByPackageFullName(
                        HSTRING packageFullName,
                        ABI::Windows::ApplicationModel::IPackage** packageInformation
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE CleanupPackageForUserAsync(
                        HSTRING packageName,
                        HSTRING userSecurityId,
                        __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress** deploymentOperation
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE FindPackagesByPackageFamilyName(
                        HSTRING packageFamilyName,
                        __FIIterable_1_Windows__CApplicationModel__CPackage** packageCollection
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE FindPackagesByUserSecurityIdPackageFamilyName(
                        HSTRING userSecurityId,
                        HSTRING packageFamilyName,
                        __FIIterable_1_Windows__CApplicationModel__CPackage** packageCollection
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE FindPackageByUserSecurityIdPackageFullName(
                        HSTRING userSecurityId,
                        HSTRING packageFullName,
                        ABI::Windows::ApplicationModel::IPackage** packageInformation
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IPackageManager = _uuidof(IPackageManager);
            } /* Deployment */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CDeployment_CIPackageManager;
#endif /* !defined(____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Deployment.IPackageManager2
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Deployment.PackageManager
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager2_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager2_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Deployment_IPackageManager2[] = L"Windows.Management.Deployment.IPackageManager2";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Deployment {
                MIDL_INTERFACE("f7aad08d-0840-46f2-b5d8-cad47693a095")
                IPackageManager2 : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE RemovePackageWithOptionsAsync(
                        HSTRING packageFullName,
                        ABI::Windows::Management::Deployment::RemovalOptions removalOptions,
                        __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress** deploymentOperation
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE StagePackageWithOptionsAsync(
                        ABI::Windows::Foundation::IUriRuntimeClass* packageUri,
                        __FIIterable_1_Windows__CFoundation__CUri* dependencyPackageUris,
                        ABI::Windows::Management::Deployment::DeploymentOptions deploymentOptions,
                        __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress** deploymentOperation
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE RegisterPackageByFullNameAsync(
                        HSTRING mainPackageFullName,
                        __FIIterable_1_HSTRING* dependencyPackageFullNames,
                        ABI::Windows::Management::Deployment::DeploymentOptions deploymentOptions,
                        __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress** deploymentOperation
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE FindPackagesWithPackageTypes(
                        ABI::Windows::Management::Deployment::PackageTypes packageTypes,
                        __FIIterable_1_Windows__CApplicationModel__CPackage** packageCollection
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE FindPackagesByUserSecurityIdWithPackageTypes(
                        HSTRING userSecurityId,
                        ABI::Windows::Management::Deployment::PackageTypes packageTypes,
                        __FIIterable_1_Windows__CApplicationModel__CPackage** packageCollection
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE FindPackagesByNamePublisherWithPackageTypes(
                        HSTRING packageName,
                        HSTRING packagePublisher,
                        ABI::Windows::Management::Deployment::PackageTypes packageTypes,
                        __FIIterable_1_Windows__CApplicationModel__CPackage** packageCollection
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE FindPackagesByUserSecurityIdNamePublisherWithPackageTypes(
                        HSTRING userSecurityId,
                        HSTRING packageName,
                        HSTRING packagePublisher,
                        ABI::Windows::Management::Deployment::PackageTypes packageTypes,
                        __FIIterable_1_Windows__CApplicationModel__CPackage** packageCollection
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE FindPackagesByPackageFamilyNameWithPackageTypes(
                        HSTRING packageFamilyName,
                        ABI::Windows::Management::Deployment::PackageTypes packageTypes,
                        __FIIterable_1_Windows__CApplicationModel__CPackage** packageCollection
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE FindPackagesByUserSecurityIdPackageFamilyNameWithPackageTypes(
                        HSTRING userSecurityId,
                        HSTRING packageFamilyName,
                        ABI::Windows::Management::Deployment::PackageTypes packageTypes,
                        __FIIterable_1_Windows__CApplicationModel__CPackage** packageCollection
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE StageUserDataAsync(
                        HSTRING packageFullName,
                        __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress** deploymentOperation
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IPackageManager2 = _uuidof(IPackageManager2);
            } /* Deployment */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CDeployment_CIPackageManager2;
#endif /* !defined(____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager2_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Deployment.IPackageManager3
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Deployment.PackageManager
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager3_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager3_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Deployment_IPackageManager3[] = L"Windows.Management.Deployment.IPackageManager3";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Deployment {
                MIDL_INTERFACE("daad9948-36f1-41a7-9188-bc263e0dcb72")
                IPackageManager3 : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE AddPackageVolumeAsync(
                        HSTRING packageStorePath,
                        __FIAsyncOperation_1_Windows__CManagement__CDeployment__CPackageVolume** packageVolume
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE AddPackageToVolumeAsync(
                        ABI::Windows::Foundation::IUriRuntimeClass* packageUri,
                        __FIIterable_1_Windows__CFoundation__CUri* dependencyPackageUris,
                        ABI::Windows::Management::Deployment::DeploymentOptions deploymentOptions,
                        ABI::Windows::Management::Deployment::IPackageVolume* targetVolume,
                        __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress** deploymentOperation
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE ClearPackageStatus(
                        HSTRING packageFullName,
                        ABI::Windows::Management::Deployment::PackageStatus status
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE RegisterPackageWithAppDataVolumeAsync(
                        ABI::Windows::Foundation::IUriRuntimeClass* manifestUri,
                        __FIIterable_1_Windows__CFoundation__CUri* dependencyPackageUris,
                        ABI::Windows::Management::Deployment::DeploymentOptions deploymentOptions,
                        ABI::Windows::Management::Deployment::IPackageVolume* appDataVolume,
                        __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress** deploymentOperation
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE FindPackageVolumeByName(
                        HSTRING volumeName,
                        ABI::Windows::Management::Deployment::IPackageVolume** volume
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE FindPackageVolumes(
                        __FIIterable_1_Windows__CManagement__CDeployment__CPackageVolume** volumeCollection
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE GetDefaultPackageVolume(
                        ABI::Windows::Management::Deployment::IPackageVolume** volume
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE MovePackageToVolumeAsync(
                        HSTRING packageFullName,
                        ABI::Windows::Management::Deployment::DeploymentOptions deploymentOptions,
                        ABI::Windows::Management::Deployment::IPackageVolume* targetVolume,
                        __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress** deploymentOperation
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE RemovePackageVolumeAsync(
                        ABI::Windows::Management::Deployment::IPackageVolume* volume,
                        __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress** deploymentOperation
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE SetDefaultPackageVolume(
                        ABI::Windows::Management::Deployment::IPackageVolume* volume
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE SetPackageStatus(
                        HSTRING packageFullName,
                        ABI::Windows::Management::Deployment::PackageStatus status
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE SetPackageVolumeOfflineAsync(
                        ABI::Windows::Management::Deployment::IPackageVolume* packageVolume,
                        __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress** deploymentOperation
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE SetPackageVolumeOnlineAsync(
                        ABI::Windows::Management::Deployment::IPackageVolume* packageVolume,
                        __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress** deploymentOperation
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE StagePackageToVolumeAsync(
                        ABI::Windows::Foundation::IUriRuntimeClass* packageUri,
                        __FIIterable_1_Windows__CFoundation__CUri* dependencyPackageUris,
                        ABI::Windows::Management::Deployment::DeploymentOptions deploymentOptions,
                        ABI::Windows::Management::Deployment::IPackageVolume* targetVolume,
                        __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress** deploymentOperation
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE StageUserDataWithOptionsAsync(
                        HSTRING packageFullName,
                        ABI::Windows::Management::Deployment::DeploymentOptions deploymentOptions,
                        __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress** deploymentOperation
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IPackageManager3 = _uuidof(IPackageManager3);
            } /* Deployment */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CDeployment_CIPackageManager3;
#endif /* !defined(____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager3_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Deployment.IPackageManager4
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 3.0
 *
 * Interface is a part of the implementation of type Windows.Management.Deployment.PackageManager
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x30000
#if !defined(____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager4_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager4_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Deployment_IPackageManager4[] = L"Windows.Management.Deployment.IPackageManager4";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Deployment {
                MIDL_INTERFACE("3c719963-bab6-46bf-8ff7-da4719230ae6")
                IPackageManager4 : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE GetPackageVolumesAsync(
                        __FIAsyncOperation_1___FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume** operation
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IPackageManager4 = _uuidof(IPackageManager4);
            } /* Deployment */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CDeployment_CIPackageManager4;
#endif /* !defined(____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager4_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x30000

/*
 *
 * Interface Windows.Management.Deployment.IPackageManager5
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 4.0
 *
 * Interface is a part of the implementation of type Windows.Management.Deployment.PackageManager
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x40000
#if !defined(____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager5_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager5_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Deployment_IPackageManager5[] = L"Windows.Management.Deployment.IPackageManager5";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Deployment {
                MIDL_INTERFACE("711f3117-1afd-4313-978c-9bb6e1b864a7")
                IPackageManager5 : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE AddPackageToVolumeAndOptionalPackagesAsync(
                        ABI::Windows::Foundation::IUriRuntimeClass* packageUri,
                        __FIIterable_1_Windows__CFoundation__CUri* dependencyPackageUris,
                        ABI::Windows::Management::Deployment::DeploymentOptions deploymentOptions,
                        ABI::Windows::Management::Deployment::IPackageVolume* targetVolume,
                        __FIIterable_1_HSTRING* optionalPackageFamilyNames,
                        __FIIterable_1_Windows__CFoundation__CUri* externalPackageUris,
                        __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress** deploymentOperation
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE StagePackageToVolumeAndOptionalPackagesAsync(
                        ABI::Windows::Foundation::IUriRuntimeClass* packageUri,
                        __FIIterable_1_Windows__CFoundation__CUri* dependencyPackageUris,
                        ABI::Windows::Management::Deployment::DeploymentOptions deploymentOptions,
                        ABI::Windows::Management::Deployment::IPackageVolume* targetVolume,
                        __FIIterable_1_HSTRING* optionalPackageFamilyNames,
                        __FIIterable_1_Windows__CFoundation__CUri* externalPackageUris,
                        __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress** deploymentOperation
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE RegisterPackageByFamilyNameAndOptionalPackagesAsync(
                        HSTRING mainPackageFamilyName,
                        __FIIterable_1_HSTRING* dependencyPackageFamilyNames,
                        ABI::Windows::Management::Deployment::DeploymentOptions deploymentOptions,
                        ABI::Windows::Management::Deployment::IPackageVolume* appDataVolume,
                        __FIIterable_1_HSTRING* optionalPackageFamilyNames,
                        __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress** deploymentOperation
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_DebugSettings(
                        ABI::Windows::Management::Deployment::IPackageManagerDebugSettings** value
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IPackageManager5 = _uuidof(IPackageManager5);
            } /* Deployment */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CDeployment_CIPackageManager5;
#endif /* !defined(____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager5_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x40000

/*
 *
 * Interface Windows.Management.Deployment.IPackageManager6
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 * Interface is a part of the implementation of type Windows.Management.Deployment.PackageManager
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager6_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager6_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Deployment_IPackageManager6[] = L"Windows.Management.Deployment.IPackageManager6";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Deployment {
                MIDL_INTERFACE("0847e909-53cd-4e4f-832e-57d180f6e447")
                IPackageManager6 : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE ProvisionPackageForAllUsersAsync(
                        HSTRING packageFamilyName,
                        __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress** operation
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE AddPackageByAppInstallerFileAsync(
                        ABI::Windows::Foundation::IUriRuntimeClass* appInstallerFileUri,
                        ABI::Windows::Management::Deployment::AddPackageByAppInstallerOptions options,
                        ABI::Windows::Management::Deployment::IPackageVolume* targetVolume,
                        __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress** operation
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE RequestAddPackageByAppInstallerFileAsync(
                        ABI::Windows::Foundation::IUriRuntimeClass* appInstallerFileUri,
                        ABI::Windows::Management::Deployment::AddPackageByAppInstallerOptions options,
                        ABI::Windows::Management::Deployment::IPackageVolume* targetVolume,
                        __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress** operation
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE AddPackageToVolumeAndRelatedSetAsync(
                        ABI::Windows::Foundation::IUriRuntimeClass* packageUri,
                        __FIIterable_1_Windows__CFoundation__CUri* dependencyPackageUris,
                        ABI::Windows::Management::Deployment::DeploymentOptions options,
                        ABI::Windows::Management::Deployment::IPackageVolume* targetVolume,
                        __FIIterable_1_HSTRING* optionalPackageFamilyNames,
                        __FIIterable_1_Windows__CFoundation__CUri* packageUrisToInstall,
                        __FIIterable_1_Windows__CFoundation__CUri* relatedPackageUris,
                        __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress** operation
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE StagePackageToVolumeAndRelatedSetAsync(
                        ABI::Windows::Foundation::IUriRuntimeClass* packageUri,
                        __FIIterable_1_Windows__CFoundation__CUri* dependencyPackageUris,
                        ABI::Windows::Management::Deployment::DeploymentOptions options,
                        ABI::Windows::Management::Deployment::IPackageVolume* targetVolume,
                        __FIIterable_1_HSTRING* optionalPackageFamilyNames,
                        __FIIterable_1_Windows__CFoundation__CUri* packageUrisToInstall,
                        __FIIterable_1_Windows__CFoundation__CUri* relatedPackageUris,
                        __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress** operation
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE RequestAddPackageAsync(
                        ABI::Windows::Foundation::IUriRuntimeClass* packageUri,
                        __FIIterable_1_Windows__CFoundation__CUri* dependencyPackageUris,
                        ABI::Windows::Management::Deployment::DeploymentOptions deploymentOptions,
                        ABI::Windows::Management::Deployment::IPackageVolume* targetVolume,
                        __FIIterable_1_HSTRING* optionalPackageFamilyNames,
                        __FIIterable_1_Windows__CFoundation__CUri* relatedPackageUris,
                        __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress** operation
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IPackageManager6 = _uuidof(IPackageManager6);
            } /* Deployment */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CDeployment_CIPackageManager6;
#endif /* !defined(____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager6_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Interface Windows.Management.Deployment.IPackageManager7
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 6.0
 *
 * Interface is a part of the implementation of type Windows.Management.Deployment.PackageManager
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x60000
#if !defined(____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager7_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager7_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Deployment_IPackageManager7[] = L"Windows.Management.Deployment.IPackageManager7";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Deployment {
                MIDL_INTERFACE("f28654f4-2ba7-4b80-88d6-be15f9a23fba")
                IPackageManager7 : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE RequestAddPackageAndRelatedSetAsync(
                        ABI::Windows::Foundation::IUriRuntimeClass* packageUri,
                        __FIIterable_1_Windows__CFoundation__CUri* dependencyPackageUris,
                        ABI::Windows::Management::Deployment::DeploymentOptions deploymentOptions,
                        ABI::Windows::Management::Deployment::IPackageVolume* targetVolume,
                        __FIIterable_1_HSTRING* optionalPackageFamilyNames,
                        __FIIterable_1_Windows__CFoundation__CUri* relatedPackageUris,
                        __FIIterable_1_Windows__CFoundation__CUri* packageUrisToInstall,
                        __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress** operation
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IPackageManager7 = _uuidof(IPackageManager7);
            } /* Deployment */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CDeployment_CIPackageManager7;
#endif /* !defined(____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager7_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x60000

/*
 *
 * Interface Windows.Management.Deployment.IPackageManager8
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 7.0
 *
 * Interface is a part of the implementation of type Windows.Management.Deployment.PackageManager
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x70000
#if !defined(____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager8_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager8_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Deployment_IPackageManager8[] = L"Windows.Management.Deployment.IPackageManager8";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Deployment {
                MIDL_INTERFACE("b8575330-1298-4ee2-80ee-7f659c5d2782")
                IPackageManager8 : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE DeprovisionPackageForAllUsersAsync(
                        HSTRING packageFamilyName,
                        __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress** operation
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IPackageManager8 = _uuidof(IPackageManager8);
            } /* Deployment */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CDeployment_CIPackageManager8;
#endif /* !defined(____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager8_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x70000

/*
 *
 * Interface Windows.Management.Deployment.IPackageManager9
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 10.0
 *
 * Interface is a part of the implementation of type Windows.Management.Deployment.PackageManager
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xa0000
#if !defined(____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager9_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager9_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Deployment_IPackageManager9[] = L"Windows.Management.Deployment.IPackageManager9";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Deployment {
                MIDL_INTERFACE("1aa79035-cc71-4b2e-80a6-c7041d8579a7")
                IPackageManager9 : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE FindProvisionedPackages(
                        __FIVector_1_Windows__CApplicationModel__CPackage** packageCollection
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE AddPackageByUriAsync(
                        ABI::Windows::Foundation::IUriRuntimeClass* packageUri,
                        ABI::Windows::Management::Deployment::IAddPackageOptions* options,
                        __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress** deploymentOperation
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE StagePackageByUriAsync(
                        ABI::Windows::Foundation::IUriRuntimeClass* packageUri,
                        ABI::Windows::Management::Deployment::IStagePackageOptions* options,
                        __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress** deploymentOperation
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE RegisterPackageByUriAsync(
                        ABI::Windows::Foundation::IUriRuntimeClass* manifestUri,
                        ABI::Windows::Management::Deployment::IRegisterPackageOptions* options,
                        __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress** deploymentOperation
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE RegisterPackagesByFullNameAsync(
                        __FIIterable_1_HSTRING* packageFullNames,
                        ABI::Windows::Management::Deployment::IRegisterPackageOptions* options,
                        __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress** deploymentOperation
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE SetPackageStubPreference(
                        HSTRING packageFamilyName,
                        ABI::Windows::Management::Deployment::PackageStubPreference useStub
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE GetPackageStubPreference(
                        HSTRING packageFamilyName,
                        ABI::Windows::Management::Deployment::PackageStubPreference* value
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IPackageManager9 = _uuidof(IPackageManager9);
            } /* Deployment */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CDeployment_CIPackageManager9;
#endif /* !defined(____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager9_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xa0000

/*
 *
 * Interface Windows.Management.Deployment.IPackageManagerDebugSettings
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 4.0
 *
 * Interface is a part of the implementation of type Windows.Management.Deployment.PackageManagerDebugSettings
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x40000
#if !defined(____x_ABI_CWindows_CManagement_CDeployment_CIPackageManagerDebugSettings_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManagerDebugSettings_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Deployment_IPackageManagerDebugSettings[] = L"Windows.Management.Deployment.IPackageManagerDebugSettings";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Deployment {
                MIDL_INTERFACE("1a611683-a988-4fcf-8f0f-ce175898e8eb")
                IPackageManagerDebugSettings : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE SetContentGroupStateAsync(
                        ABI::Windows::ApplicationModel::IPackage* package,
                        HSTRING contentGroupName,
                        ABI::Windows::ApplicationModel::PackageContentGroupState state,
                        ABI::Windows::Foundation::IAsyncAction** action
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE SetContentGroupStateWithPercentageAsync(
                        ABI::Windows::ApplicationModel::IPackage* package,
                        HSTRING contentGroupName,
                        ABI::Windows::ApplicationModel::PackageContentGroupState state,
                        DOUBLE completionPercentage,
                        ABI::Windows::Foundation::IAsyncAction** action
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IPackageManagerDebugSettings = _uuidof(IPackageManagerDebugSettings);
            } /* Deployment */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CDeployment_CIPackageManagerDebugSettings;
#endif /* !defined(____x_ABI_CWindows_CManagement_CDeployment_CIPackageManagerDebugSettings_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x40000

/*
 *
 * Interface Windows.Management.Deployment.IPackageUserInformation
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Deployment.PackageUserInformation
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CDeployment_CIPackageUserInformation_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CDeployment_CIPackageUserInformation_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Deployment_IPackageUserInformation[] = L"Windows.Management.Deployment.IPackageUserInformation";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Deployment {
                MIDL_INTERFACE("f6383423-fa09-4cbc-9055-15ca275e2e7e")
                IPackageUserInformation : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE get_UserSecurityId(
                        HSTRING* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_InstallState(
                        ABI::Windows::Management::Deployment::PackageInstallState* value
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IPackageUserInformation = _uuidof(IPackageUserInformation);
            } /* Deployment */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CDeployment_CIPackageUserInformation;
#endif /* !defined(____x_ABI_CWindows_CManagement_CDeployment_CIPackageUserInformation_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Deployment.IPackageVolume
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Deployment.PackageVolume
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Deployment_IPackageVolume[] = L"Windows.Management.Deployment.IPackageVolume";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Deployment {
                MIDL_INTERFACE("cf2672c3-1a40-4450-9739-2ace2e898853")
                IPackageVolume : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE get_IsOffline(
                        boolean* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_IsSystemVolume(
                        boolean* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_MountPoint(
                        HSTRING* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_Name(
                        HSTRING* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_PackageStorePath(
                        HSTRING* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_SupportsHardLinks(
                        boolean* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE FindPackages(
                        __FIVector_1_Windows__CApplicationModel__CPackage** packageCollection
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE FindPackagesByNamePublisher(
                        HSTRING packageName,
                        HSTRING packagePublisher,
                        __FIVector_1_Windows__CApplicationModel__CPackage** packageCollection
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE FindPackagesByPackageFamilyName(
                        HSTRING packageFamilyName,
                        __FIVector_1_Windows__CApplicationModel__CPackage** packageCollection
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE FindPackagesWithPackageTypes(
                        ABI::Windows::Management::Deployment::PackageTypes packageTypes,
                        __FIVector_1_Windows__CApplicationModel__CPackage** packageCollection
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE FindPackagesByNamePublisherWithPackagesTypes(
                        ABI::Windows::Management::Deployment::PackageTypes packageTypes,
                        HSTRING packageName,
                        HSTRING packagePublisher,
                        __FIVector_1_Windows__CApplicationModel__CPackage** packageCollection
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE FindPackagesByPackageFamilyNameWithPackageTypes(
                        ABI::Windows::Management::Deployment::PackageTypes packageTypes,
                        HSTRING packageFamilyName,
                        __FIVector_1_Windows__CApplicationModel__CPackage** packageCollection
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE FindPackageByPackageFullName(
                        HSTRING packageFullName,
                        __FIVector_1_Windows__CApplicationModel__CPackage** packageCollection
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE FindPackagesByUserSecurityId(
                        HSTRING userSecurityId,
                        __FIVector_1_Windows__CApplicationModel__CPackage** packageCollection
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE FindPackagesByUserSecurityIdNamePublisher(
                        HSTRING userSecurityId,
                        HSTRING packageName,
                        HSTRING packagePublisher,
                        __FIVector_1_Windows__CApplicationModel__CPackage** packageCollection
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE FindPackagesByUserSecurityIdPackageFamilyName(
                        HSTRING userSecurityId,
                        HSTRING packageFamilyName,
                        __FIVector_1_Windows__CApplicationModel__CPackage** packageCollection
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE FindPackagesByUserSecurityIdWithPackageTypes(
                        HSTRING userSecurityId,
                        ABI::Windows::Management::Deployment::PackageTypes packageTypes,
                        __FIVector_1_Windows__CApplicationModel__CPackage** packageCollection
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE FindPackagesByUserSecurityIdNamePublisherWithPackageTypes(
                        HSTRING userSecurityId,
                        ABI::Windows::Management::Deployment::PackageTypes packageTypes,
                        HSTRING packageName,
                        HSTRING packagePublisher,
                        __FIVector_1_Windows__CApplicationModel__CPackage** packageCollection
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE FindPackagesByUserSecurityIdPackageFamilyNameWithPackagesTypes(
                        HSTRING userSecurityId,
                        ABI::Windows::Management::Deployment::PackageTypes packageTypes,
                        HSTRING packageFamilyName,
                        __FIVector_1_Windows__CApplicationModel__CPackage** packageCollection
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE FindPackageByUserSecurityIdPackageFullName(
                        HSTRING userSecurityId,
                        HSTRING packageFullName,
                        __FIVector_1_Windows__CApplicationModel__CPackage** packageCollection
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IPackageVolume = _uuidof(IPackageVolume);
            } /* Deployment */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume;
#endif /* !defined(____x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Deployment.IPackageVolume2
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 3.0
 *
 * Interface is a part of the implementation of type Windows.Management.Deployment.PackageVolume
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x30000
#if !defined(____x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume2_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume2_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Deployment_IPackageVolume2[] = L"Windows.Management.Deployment.IPackageVolume2";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Deployment {
                MIDL_INTERFACE("46abcf2e-9dd4-47a2-ab8c-c6408349bcd8")
                IPackageVolume2 : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE get_IsFullTrustPackageSupported(
                        boolean* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_IsAppxInstallSupported(
                        boolean* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE GetAvailableSpaceAsync(
                        __FIAsyncOperation_1_UINT64** operation
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IPackageVolume2 = _uuidof(IPackageVolume2);
            } /* Deployment */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume2;
#endif /* !defined(____x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume2_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x30000

/*
 *
 * Interface Windows.Management.Deployment.IRegisterPackageOptions
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 10.0
 *
 * Interface is a part of the implementation of type Windows.Management.Deployment.RegisterPackageOptions
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xa0000
#if !defined(____x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Deployment_IRegisterPackageOptions[] = L"Windows.Management.Deployment.IRegisterPackageOptions";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Deployment {
                MIDL_INTERFACE("677112a7-50d4-496c-8415-0602b4c6d3bf")
                IRegisterPackageOptions : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE get_DependencyPackageUris(
                        __FIVector_1_Windows__CFoundation__CUri** value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_AppDataVolume(
                        ABI::Windows::Management::Deployment::IPackageVolume** value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_AppDataVolume(
                        ABI::Windows::Management::Deployment::IPackageVolume* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_OptionalPackageFamilyNames(
                        __FIVector_1_HSTRING** value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_ExternalLocationUri(
                        ABI::Windows::Foundation::IUriRuntimeClass** value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_ExternalLocationUri(
                        ABI::Windows::Foundation::IUriRuntimeClass* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_DeveloperMode(
                        boolean* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_DeveloperMode(
                        boolean value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_ForceAppShutdown(
                        boolean* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_ForceAppShutdown(
                        boolean value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_ForceTargetAppShutdown(
                        boolean* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_ForceTargetAppShutdown(
                        boolean value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_ForceUpdateFromAnyVersion(
                        boolean* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_ForceUpdateFromAnyVersion(
                        boolean value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_InstallAllResources(
                        boolean* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_InstallAllResources(
                        boolean value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_StageInPlace(
                        boolean* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_StageInPlace(
                        boolean value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_AllowUnsigned(
                        boolean* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_AllowUnsigned(
                        boolean value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_DeferRegistrationWhenPackagesAreInUse(
                        boolean* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_DeferRegistrationWhenPackagesAreInUse(
                        boolean value
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IRegisterPackageOptions = _uuidof(IRegisterPackageOptions);
            } /* Deployment */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptions;
#endif /* !defined(____x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xa0000

/*
 *
 * Interface Windows.Management.Deployment.IStagePackageOptions
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 10.0
 *
 * Interface is a part of the implementation of type Windows.Management.Deployment.StagePackageOptions
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xa0000
#if !defined(____x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptions_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptions_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Deployment_IStagePackageOptions[] = L"Windows.Management.Deployment.IStagePackageOptions";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Deployment {
                MIDL_INTERFACE("0b110c9c-b95d-4c56-bd36-6d656800d06b")
                IStagePackageOptions : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE get_DependencyPackageUris(
                        __FIVector_1_Windows__CFoundation__CUri** value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_TargetVolume(
                        ABI::Windows::Management::Deployment::IPackageVolume** value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_TargetVolume(
                        ABI::Windows::Management::Deployment::IPackageVolume* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_OptionalPackageFamilyNames(
                        __FIVector_1_HSTRING** value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_OptionalPackageUris(
                        __FIVector_1_Windows__CFoundation__CUri** value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_RelatedPackageUris(
                        __FIVector_1_Windows__CFoundation__CUri** value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_ExternalLocationUri(
                        ABI::Windows::Foundation::IUriRuntimeClass** value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_ExternalLocationUri(
                        ABI::Windows::Foundation::IUriRuntimeClass* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_StubPackageOption(
                        ABI::Windows::Management::Deployment::StubPackageOption* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_StubPackageOption(
                        ABI::Windows::Management::Deployment::StubPackageOption value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_DeveloperMode(
                        boolean* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_DeveloperMode(
                        boolean value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_ForceUpdateFromAnyVersion(
                        boolean* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_ForceUpdateFromAnyVersion(
                        boolean value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_InstallAllResources(
                        boolean* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_InstallAllResources(
                        boolean value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_RequiredContentGroupOnly(
                        boolean* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_RequiredContentGroupOnly(
                        boolean value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_StageInPlace(
                        boolean* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_StageInPlace(
                        boolean value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_AllowUnsigned(
                        boolean* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_AllowUnsigned(
                        boolean value
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IStagePackageOptions = _uuidof(IStagePackageOptions);
            } /* Deployment */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptions;
#endif /* !defined(____x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptions_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xa0000

/*
 *
 * Class Windows.Management.Deployment.AddPackageOptions
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 10.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via RoActivateInstance starting with version 10.0 of the Windows.Foundation.UniversalApiContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Management.Deployment.IAddPackageOptions ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xa0000
#ifndef RUNTIMECLASS_Windows_Management_Deployment_AddPackageOptions_DEFINED
#define RUNTIMECLASS_Windows_Management_Deployment_AddPackageOptions_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Deployment_AddPackageOptions[] = L"Windows.Management.Deployment.AddPackageOptions";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xa0000

/*
 *
 * Class Windows.Management.Deployment.DeploymentResult
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 * Class implements the following interfaces:
 *    Windows.Management.Deployment.IDeploymentResult ** Default Interface **
 *    Windows.Management.Deployment.IDeploymentResult2
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Management_Deployment_DeploymentResult_DEFINED
#define RUNTIMECLASS_Windows_Management_Deployment_DeploymentResult_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Deployment_DeploymentResult[] = L"Windows.Management.Deployment.DeploymentResult";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Management.Deployment.PackageManager
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via RoActivateInstance starting with version 1.0 of the Windows.Foundation.UniversalApiContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Management.Deployment.IPackageManager ** Default Interface **
 *    Windows.Management.Deployment.IPackageManager2
 *    Windows.Management.Deployment.IPackageManager3
 *    Windows.Management.Deployment.IPackageManager4
 *    Windows.Management.Deployment.IPackageManager5
 *    Windows.Management.Deployment.IPackageManager6
 *    Windows.Management.Deployment.IPackageManager7
 *    Windows.Management.Deployment.IPackageManager8
 *    Windows.Management.Deployment.IPackageManager9
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Management_Deployment_PackageManager_DEFINED
#define RUNTIMECLASS_Windows_Management_Deployment_PackageManager_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Deployment_PackageManager[] = L"Windows.Management.Deployment.PackageManager";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Management.Deployment.PackageManagerDebugSettings
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 4.0
 *
 * Class implements the following interfaces:
 *    Windows.Management.Deployment.IPackageManagerDebugSettings ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x40000
#ifndef RUNTIMECLASS_Windows_Management_Deployment_PackageManagerDebugSettings_DEFINED
#define RUNTIMECLASS_Windows_Management_Deployment_PackageManagerDebugSettings_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Deployment_PackageManagerDebugSettings[] = L"Windows.Management.Deployment.PackageManagerDebugSettings";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x40000

/*
 *
 * Class Windows.Management.Deployment.PackageUserInformation
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 * Class implements the following interfaces:
 *    Windows.Management.Deployment.IPackageUserInformation ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Management_Deployment_PackageUserInformation_DEFINED
#define RUNTIMECLASS_Windows_Management_Deployment_PackageUserInformation_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Deployment_PackageUserInformation[] = L"Windows.Management.Deployment.PackageUserInformation";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Management.Deployment.PackageVolume
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 * Class implements the following interfaces:
 *    Windows.Management.Deployment.IPackageVolume ** Default Interface **
 *    Windows.Management.Deployment.IPackageVolume2
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Management_Deployment_PackageVolume_DEFINED
#define RUNTIMECLASS_Windows_Management_Deployment_PackageVolume_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Deployment_PackageVolume[] = L"Windows.Management.Deployment.PackageVolume";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Management.Deployment.RegisterPackageOptions
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 10.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via RoActivateInstance starting with version 10.0 of the Windows.Foundation.UniversalApiContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Management.Deployment.IRegisterPackageOptions ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xa0000
#ifndef RUNTIMECLASS_Windows_Management_Deployment_RegisterPackageOptions_DEFINED
#define RUNTIMECLASS_Windows_Management_Deployment_RegisterPackageOptions_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Deployment_RegisterPackageOptions[] = L"Windows.Management.Deployment.RegisterPackageOptions";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xa0000

/*
 *
 * Class Windows.Management.Deployment.StagePackageOptions
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 10.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via RoActivateInstance starting with version 10.0 of the Windows.Foundation.UniversalApiContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Management.Deployment.IStagePackageOptions ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xa0000
#ifndef RUNTIMECLASS_Windows_Management_Deployment_StagePackageOptions_DEFINED
#define RUNTIMECLASS_Windows_Management_Deployment_StagePackageOptions_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Deployment_StagePackageOptions[] = L"Windows.Management.Deployment.StagePackageOptions";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xa0000

#else // !defined(__cplusplus)
/* Forward Declarations */
#ifndef ____x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions __x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions;

#endif // ____x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CDeployment_CIDeploymentResult_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CDeployment_CIDeploymentResult_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CDeployment_CIDeploymentResult __x_ABI_CWindows_CManagement_CDeployment_CIDeploymentResult;

#endif // ____x_ABI_CWindows_CManagement_CDeployment_CIDeploymentResult_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CDeployment_CIDeploymentResult2_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CDeployment_CIDeploymentResult2_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CDeployment_CIDeploymentResult2 __x_ABI_CWindows_CManagement_CDeployment_CIDeploymentResult2;

#endif // ____x_ABI_CWindows_CManagement_CDeployment_CIDeploymentResult2_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager;

#endif // ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager2_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager2_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager2 __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager2;

#endif // ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager2_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager3_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager3_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager3 __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager3;

#endif // ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager3_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager4_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager4_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager4 __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager4;

#endif // ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager4_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager5_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager5_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager5 __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager5;

#endif // ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager5_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager6_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager6_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager6 __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager6;

#endif // ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager6_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager7_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager7_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager7 __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager7;

#endif // ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager7_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager8_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager8_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager8 __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager8;

#endif // ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager8_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager9_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager9_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager9 __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager9;

#endif // ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager9_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManagerDebugSettings_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManagerDebugSettings_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CDeployment_CIPackageManagerDebugSettings __x_ABI_CWindows_CManagement_CDeployment_CIPackageManagerDebugSettings;

#endif // ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManagerDebugSettings_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CDeployment_CIPackageUserInformation_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CDeployment_CIPackageUserInformation_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CDeployment_CIPackageUserInformation __x_ABI_CWindows_CManagement_CDeployment_CIPackageUserInformation;

#endif // ____x_ABI_CWindows_CManagement_CDeployment_CIPackageUserInformation_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume;

#endif // ____x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume2_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume2_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume2 __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume2;

#endif // ____x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume2_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptions __x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptions;

#endif // ____x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptions_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptions_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptions __x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptions;

#endif // ____x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptions_FWD_DEFINED__

// Parameterized interface forward declarations (C)

// Collection interface definitions

typedef interface __FIAsyncOperationCompletedHandler_1_UINT64 __FIAsyncOperationCompletedHandler_1_UINT64;

#if !defined(____FIAsyncOperation_1_UINT64_INTERFACE_DEFINED__)
#define ____FIAsyncOperation_1_UINT64_INTERFACE_DEFINED__

typedef interface __FIAsyncOperation_1_UINT64 __FIAsyncOperation_1_UINT64;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIAsyncOperation_1_UINT64;

typedef struct __FIAsyncOperation_1_UINT64Vtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIAsyncOperation_1_UINT64* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIAsyncOperation_1_UINT64* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIAsyncOperation_1_UINT64* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIAsyncOperation_1_UINT64* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIAsyncOperation_1_UINT64* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIAsyncOperation_1_UINT64* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* put_Completed)(__FIAsyncOperation_1_UINT64* This,
        __FIAsyncOperationCompletedHandler_1_UINT64* handler);
    HRESULT (STDMETHODCALLTYPE* get_Completed)(__FIAsyncOperation_1_UINT64* This,
        __FIAsyncOperationCompletedHandler_1_UINT64** result);
    HRESULT (STDMETHODCALLTYPE* GetResults)(__FIAsyncOperation_1_UINT64* This,
        UINT64* result);

    END_INTERFACE
} __FIAsyncOperation_1_UINT64Vtbl;

interface __FIAsyncOperation_1_UINT64
{
    CONST_VTBL struct __FIAsyncOperation_1_UINT64Vtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIAsyncOperation_1_UINT64_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIAsyncOperation_1_UINT64_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIAsyncOperation_1_UINT64_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIAsyncOperation_1_UINT64_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIAsyncOperation_1_UINT64_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIAsyncOperation_1_UINT64_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIAsyncOperation_1_UINT64_put_Completed(This, handler) \
    ((This)->lpVtbl->put_Completed(This, handler))

#define __FIAsyncOperation_1_UINT64_get_Completed(This, result) \
    ((This)->lpVtbl->get_Completed(This, result))

#define __FIAsyncOperation_1_UINT64_GetResults(This, result) \
    ((This)->lpVtbl->GetResults(This, result))

#endif /* COBJMACROS */

#endif // ____FIAsyncOperation_1_UINT64_INTERFACE_DEFINED__

#if !defined(____FIAsyncOperationCompletedHandler_1_UINT64_INTERFACE_DEFINED__)
#define ____FIAsyncOperationCompletedHandler_1_UINT64_INTERFACE_DEFINED__

typedef interface __FIAsyncOperationCompletedHandler_1_UINT64 __FIAsyncOperationCompletedHandler_1_UINT64;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIAsyncOperationCompletedHandler_1_UINT64;

typedef struct __FIAsyncOperationCompletedHandler_1_UINT64Vtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIAsyncOperationCompletedHandler_1_UINT64* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIAsyncOperationCompletedHandler_1_UINT64* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIAsyncOperationCompletedHandler_1_UINT64* This);
    HRESULT (STDMETHODCALLTYPE* Invoke)(__FIAsyncOperationCompletedHandler_1_UINT64* This,
        __FIAsyncOperation_1_UINT64* asyncInfo,
        AsyncStatus asyncStatus);

    END_INTERFACE
} __FIAsyncOperationCompletedHandler_1_UINT64Vtbl;

interface __FIAsyncOperationCompletedHandler_1_UINT64
{
    CONST_VTBL struct __FIAsyncOperationCompletedHandler_1_UINT64Vtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIAsyncOperationCompletedHandler_1_UINT64_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIAsyncOperationCompletedHandler_1_UINT64_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIAsyncOperationCompletedHandler_1_UINT64_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIAsyncOperationCompletedHandler_1_UINT64_Invoke(This, asyncInfo, asyncStatus) \
    ((This)->lpVtbl->Invoke(This, asyncInfo, asyncStatus))

#endif /* COBJMACROS */

#endif // ____FIAsyncOperationCompletedHandler_1_UINT64_INTERFACE_DEFINED__

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if !defined(____FIIterator_1_Windows__CManagement__CDeployment__CPackageVolume_INTERFACE_DEFINED__)
#define ____FIIterator_1_Windows__CManagement__CDeployment__CPackageVolume_INTERFACE_DEFINED__

typedef interface __FIIterator_1_Windows__CManagement__CDeployment__CPackageVolume __FIIterator_1_Windows__CManagement__CDeployment__CPackageVolume;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterator_1_Windows__CManagement__CDeployment__CPackageVolume;

typedef struct __FIIterator_1_Windows__CManagement__CDeployment__CPackageVolumeVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIIterator_1_Windows__CManagement__CDeployment__CPackageVolume* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIIterator_1_Windows__CManagement__CDeployment__CPackageVolume* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIIterator_1_Windows__CManagement__CDeployment__CPackageVolume* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIIterator_1_Windows__CManagement__CDeployment__CPackageVolume* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIIterator_1_Windows__CManagement__CDeployment__CPackageVolume* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIIterator_1_Windows__CManagement__CDeployment__CPackageVolume* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Current)(__FIIterator_1_Windows__CManagement__CDeployment__CPackageVolume* This,
        __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume** result);
    HRESULT (STDMETHODCALLTYPE* get_HasCurrent)(__FIIterator_1_Windows__CManagement__CDeployment__CPackageVolume* This,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* MoveNext)(__FIIterator_1_Windows__CManagement__CDeployment__CPackageVolume* This,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* GetMany)(__FIIterator_1_Windows__CManagement__CDeployment__CPackageVolume* This,
        UINT32 itemsLength,
        __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume** items,
        UINT32* result);

    END_INTERFACE
} __FIIterator_1_Windows__CManagement__CDeployment__CPackageVolumeVtbl;

interface __FIIterator_1_Windows__CManagement__CDeployment__CPackageVolume
{
    CONST_VTBL struct __FIIterator_1_Windows__CManagement__CDeployment__CPackageVolumeVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIIterator_1_Windows__CManagement__CDeployment__CPackageVolume_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIIterator_1_Windows__CManagement__CDeployment__CPackageVolume_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIIterator_1_Windows__CManagement__CDeployment__CPackageVolume_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIIterator_1_Windows__CManagement__CDeployment__CPackageVolume_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIIterator_1_Windows__CManagement__CDeployment__CPackageVolume_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIIterator_1_Windows__CManagement__CDeployment__CPackageVolume_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIIterator_1_Windows__CManagement__CDeployment__CPackageVolume_get_Current(This, result) \
    ((This)->lpVtbl->get_Current(This, result))

#define __FIIterator_1_Windows__CManagement__CDeployment__CPackageVolume_get_HasCurrent(This, result) \
    ((This)->lpVtbl->get_HasCurrent(This, result))

#define __FIIterator_1_Windows__CManagement__CDeployment__CPackageVolume_MoveNext(This, result) \
    ((This)->lpVtbl->MoveNext(This, result))

#define __FIIterator_1_Windows__CManagement__CDeployment__CPackageVolume_GetMany(This, itemsLength, items, result) \
    ((This)->lpVtbl->GetMany(This, itemsLength, items, result))

#endif /* COBJMACROS */

#endif // ____FIIterator_1_Windows__CManagement__CDeployment__CPackageVolume_INTERFACE_DEFINED__
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if !defined(____FIIterable_1_Windows__CManagement__CDeployment__CPackageVolume_INTERFACE_DEFINED__)
#define ____FIIterable_1_Windows__CManagement__CDeployment__CPackageVolume_INTERFACE_DEFINED__

typedef interface __FIIterable_1_Windows__CManagement__CDeployment__CPackageVolume __FIIterable_1_Windows__CManagement__CDeployment__CPackageVolume;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterable_1_Windows__CManagement__CDeployment__CPackageVolume;

typedef struct __FIIterable_1_Windows__CManagement__CDeployment__CPackageVolumeVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIIterable_1_Windows__CManagement__CDeployment__CPackageVolume* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIIterable_1_Windows__CManagement__CDeployment__CPackageVolume* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIIterable_1_Windows__CManagement__CDeployment__CPackageVolume* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIIterable_1_Windows__CManagement__CDeployment__CPackageVolume* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIIterable_1_Windows__CManagement__CDeployment__CPackageVolume* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIIterable_1_Windows__CManagement__CDeployment__CPackageVolume* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* First)(__FIIterable_1_Windows__CManagement__CDeployment__CPackageVolume* This,
        __FIIterator_1_Windows__CManagement__CDeployment__CPackageVolume** result);

    END_INTERFACE
} __FIIterable_1_Windows__CManagement__CDeployment__CPackageVolumeVtbl;

interface __FIIterable_1_Windows__CManagement__CDeployment__CPackageVolume
{
    CONST_VTBL struct __FIIterable_1_Windows__CManagement__CDeployment__CPackageVolumeVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIIterable_1_Windows__CManagement__CDeployment__CPackageVolume_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIIterable_1_Windows__CManagement__CDeployment__CPackageVolume_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIIterable_1_Windows__CManagement__CDeployment__CPackageVolume_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIIterable_1_Windows__CManagement__CDeployment__CPackageVolume_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIIterable_1_Windows__CManagement__CDeployment__CPackageVolume_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIIterable_1_Windows__CManagement__CDeployment__CPackageVolume_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIIterable_1_Windows__CManagement__CDeployment__CPackageVolume_First(This, result) \
    ((This)->lpVtbl->First(This, result))

#endif /* COBJMACROS */

#endif // ____FIIterable_1_Windows__CManagement__CDeployment__CPackageVolume_INTERFACE_DEFINED__
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if !defined(____FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume_INTERFACE_DEFINED__)
#define ____FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume_INTERFACE_DEFINED__

typedef interface __FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume __FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume;

typedef struct __FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolumeVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* GetAt)(__FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume* This,
        UINT32 index,
        __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume** result);
    HRESULT (STDMETHODCALLTYPE* get_Size)(__FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume* This,
        UINT32* result);
    HRESULT (STDMETHODCALLTYPE* IndexOf)(__FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume* This,
        __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume* value,
        UINT32* index,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* GetMany)(__FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume* This,
        UINT32 startIndex,
        UINT32 itemsLength,
        __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume** items,
        UINT32* result);

    END_INTERFACE
} __FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolumeVtbl;

interface __FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume
{
    CONST_VTBL struct __FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolumeVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume_GetAt(This, index, result) \
    ((This)->lpVtbl->GetAt(This, index, result))

#define __FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume_get_Size(This, result) \
    ((This)->lpVtbl->get_Size(This, result))

#define __FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume_IndexOf(This, value, index, result) \
    ((This)->lpVtbl->IndexOf(This, value, index, result))

#define __FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume_GetMany(This, startIndex, itemsLength, items, result) \
    ((This)->lpVtbl->GetMany(This, startIndex, itemsLength, items, result))

#endif /* COBJMACROS */

#endif // ____FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume_INTERFACE_DEFINED__
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

typedef interface __FIAsyncOperationCompletedHandler_1___FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume __FIAsyncOperationCompletedHandler_1___FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume;

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if !defined(____FIAsyncOperation_1___FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume_INTERFACE_DEFINED__)
#define ____FIAsyncOperation_1___FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume_INTERFACE_DEFINED__

typedef interface __FIAsyncOperation_1___FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume __FIAsyncOperation_1___FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIAsyncOperation_1___FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume;

typedef struct __FIAsyncOperation_1___FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolumeVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIAsyncOperation_1___FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIAsyncOperation_1___FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIAsyncOperation_1___FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIAsyncOperation_1___FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIAsyncOperation_1___FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIAsyncOperation_1___FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* put_Completed)(__FIAsyncOperation_1___FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume* This,
        __FIAsyncOperationCompletedHandler_1___FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume* handler);
    HRESULT (STDMETHODCALLTYPE* get_Completed)(__FIAsyncOperation_1___FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume* This,
        __FIAsyncOperationCompletedHandler_1___FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume** result);
    HRESULT (STDMETHODCALLTYPE* GetResults)(__FIAsyncOperation_1___FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume* This,
        __FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume** result);

    END_INTERFACE
} __FIAsyncOperation_1___FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolumeVtbl;

interface __FIAsyncOperation_1___FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume
{
    CONST_VTBL struct __FIAsyncOperation_1___FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolumeVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIAsyncOperation_1___FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIAsyncOperation_1___FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIAsyncOperation_1___FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIAsyncOperation_1___FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIAsyncOperation_1___FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIAsyncOperation_1___FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIAsyncOperation_1___FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume_put_Completed(This, handler) \
    ((This)->lpVtbl->put_Completed(This, handler))

#define __FIAsyncOperation_1___FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume_get_Completed(This, result) \
    ((This)->lpVtbl->get_Completed(This, result))

#define __FIAsyncOperation_1___FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume_GetResults(This, result) \
    ((This)->lpVtbl->GetResults(This, result))

#endif /* COBJMACROS */

#endif // ____FIAsyncOperation_1___FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume_INTERFACE_DEFINED__
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if !defined(____FIAsyncOperationCompletedHandler_1___FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume_INTERFACE_DEFINED__)
#define ____FIAsyncOperationCompletedHandler_1___FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume_INTERFACE_DEFINED__

typedef interface __FIAsyncOperationCompletedHandler_1___FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume __FIAsyncOperationCompletedHandler_1___FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIAsyncOperationCompletedHandler_1___FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume;

typedef struct __FIAsyncOperationCompletedHandler_1___FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolumeVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIAsyncOperationCompletedHandler_1___FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIAsyncOperationCompletedHandler_1___FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIAsyncOperationCompletedHandler_1___FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume* This);
    HRESULT (STDMETHODCALLTYPE* Invoke)(__FIAsyncOperationCompletedHandler_1___FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume* This,
        __FIAsyncOperation_1___FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume* asyncInfo,
        AsyncStatus asyncStatus);

    END_INTERFACE
} __FIAsyncOperationCompletedHandler_1___FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolumeVtbl;

interface __FIAsyncOperationCompletedHandler_1___FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume
{
    CONST_VTBL struct __FIAsyncOperationCompletedHandler_1___FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolumeVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIAsyncOperationCompletedHandler_1___FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIAsyncOperationCompletedHandler_1___FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIAsyncOperationCompletedHandler_1___FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIAsyncOperationCompletedHandler_1___FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume_Invoke(This, asyncInfo, asyncStatus) \
    ((This)->lpVtbl->Invoke(This, asyncInfo, asyncStatus))

#endif /* COBJMACROS */

#endif // ____FIAsyncOperationCompletedHandler_1___FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume_INTERFACE_DEFINED__
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

typedef interface __FIAsyncOperationCompletedHandler_1_Windows__CManagement__CDeployment__CPackageVolume __FIAsyncOperationCompletedHandler_1_Windows__CManagement__CDeployment__CPackageVolume;

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if !defined(____FIAsyncOperation_1_Windows__CManagement__CDeployment__CPackageVolume_INTERFACE_DEFINED__)
#define ____FIAsyncOperation_1_Windows__CManagement__CDeployment__CPackageVolume_INTERFACE_DEFINED__

typedef interface __FIAsyncOperation_1_Windows__CManagement__CDeployment__CPackageVolume __FIAsyncOperation_1_Windows__CManagement__CDeployment__CPackageVolume;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIAsyncOperation_1_Windows__CManagement__CDeployment__CPackageVolume;

typedef struct __FIAsyncOperation_1_Windows__CManagement__CDeployment__CPackageVolumeVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIAsyncOperation_1_Windows__CManagement__CDeployment__CPackageVolume* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIAsyncOperation_1_Windows__CManagement__CDeployment__CPackageVolume* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIAsyncOperation_1_Windows__CManagement__CDeployment__CPackageVolume* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIAsyncOperation_1_Windows__CManagement__CDeployment__CPackageVolume* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIAsyncOperation_1_Windows__CManagement__CDeployment__CPackageVolume* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIAsyncOperation_1_Windows__CManagement__CDeployment__CPackageVolume* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* put_Completed)(__FIAsyncOperation_1_Windows__CManagement__CDeployment__CPackageVolume* This,
        __FIAsyncOperationCompletedHandler_1_Windows__CManagement__CDeployment__CPackageVolume* handler);
    HRESULT (STDMETHODCALLTYPE* get_Completed)(__FIAsyncOperation_1_Windows__CManagement__CDeployment__CPackageVolume* This,
        __FIAsyncOperationCompletedHandler_1_Windows__CManagement__CDeployment__CPackageVolume** result);
    HRESULT (STDMETHODCALLTYPE* GetResults)(__FIAsyncOperation_1_Windows__CManagement__CDeployment__CPackageVolume* This,
        __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume** result);

    END_INTERFACE
} __FIAsyncOperation_1_Windows__CManagement__CDeployment__CPackageVolumeVtbl;

interface __FIAsyncOperation_1_Windows__CManagement__CDeployment__CPackageVolume
{
    CONST_VTBL struct __FIAsyncOperation_1_Windows__CManagement__CDeployment__CPackageVolumeVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIAsyncOperation_1_Windows__CManagement__CDeployment__CPackageVolume_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIAsyncOperation_1_Windows__CManagement__CDeployment__CPackageVolume_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIAsyncOperation_1_Windows__CManagement__CDeployment__CPackageVolume_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIAsyncOperation_1_Windows__CManagement__CDeployment__CPackageVolume_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIAsyncOperation_1_Windows__CManagement__CDeployment__CPackageVolume_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIAsyncOperation_1_Windows__CManagement__CDeployment__CPackageVolume_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIAsyncOperation_1_Windows__CManagement__CDeployment__CPackageVolume_put_Completed(This, handler) \
    ((This)->lpVtbl->put_Completed(This, handler))

#define __FIAsyncOperation_1_Windows__CManagement__CDeployment__CPackageVolume_get_Completed(This, result) \
    ((This)->lpVtbl->get_Completed(This, result))

#define __FIAsyncOperation_1_Windows__CManagement__CDeployment__CPackageVolume_GetResults(This, result) \
    ((This)->lpVtbl->GetResults(This, result))

#endif /* COBJMACROS */

#endif // ____FIAsyncOperation_1_Windows__CManagement__CDeployment__CPackageVolume_INTERFACE_DEFINED__
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if !defined(____FIAsyncOperationCompletedHandler_1_Windows__CManagement__CDeployment__CPackageVolume_INTERFACE_DEFINED__)
#define ____FIAsyncOperationCompletedHandler_1_Windows__CManagement__CDeployment__CPackageVolume_INTERFACE_DEFINED__

typedef interface __FIAsyncOperationCompletedHandler_1_Windows__CManagement__CDeployment__CPackageVolume __FIAsyncOperationCompletedHandler_1_Windows__CManagement__CDeployment__CPackageVolume;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIAsyncOperationCompletedHandler_1_Windows__CManagement__CDeployment__CPackageVolume;

typedef struct __FIAsyncOperationCompletedHandler_1_Windows__CManagement__CDeployment__CPackageVolumeVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIAsyncOperationCompletedHandler_1_Windows__CManagement__CDeployment__CPackageVolume* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIAsyncOperationCompletedHandler_1_Windows__CManagement__CDeployment__CPackageVolume* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIAsyncOperationCompletedHandler_1_Windows__CManagement__CDeployment__CPackageVolume* This);
    HRESULT (STDMETHODCALLTYPE* Invoke)(__FIAsyncOperationCompletedHandler_1_Windows__CManagement__CDeployment__CPackageVolume* This,
        __FIAsyncOperation_1_Windows__CManagement__CDeployment__CPackageVolume* asyncInfo,
        AsyncStatus asyncStatus);

    END_INTERFACE
} __FIAsyncOperationCompletedHandler_1_Windows__CManagement__CDeployment__CPackageVolumeVtbl;

interface __FIAsyncOperationCompletedHandler_1_Windows__CManagement__CDeployment__CPackageVolume
{
    CONST_VTBL struct __FIAsyncOperationCompletedHandler_1_Windows__CManagement__CDeployment__CPackageVolumeVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIAsyncOperationCompletedHandler_1_Windows__CManagement__CDeployment__CPackageVolume_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIAsyncOperationCompletedHandler_1_Windows__CManagement__CDeployment__CPackageVolume_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIAsyncOperationCompletedHandler_1_Windows__CManagement__CDeployment__CPackageVolume_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIAsyncOperationCompletedHandler_1_Windows__CManagement__CDeployment__CPackageVolume_Invoke(This, asyncInfo, asyncStatus) \
    ((This)->lpVtbl->Invoke(This, asyncInfo, asyncStatus))

#endif /* COBJMACROS */

#endif // ____FIAsyncOperationCompletedHandler_1_Windows__CManagement__CDeployment__CPackageVolume_INTERFACE_DEFINED__
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

typedef struct __x_ABI_CWindows_CManagement_CDeployment_CDeploymentProgress __x_ABI_CWindows_CManagement_CDeployment_CDeploymentProgress;

typedef interface __FIAsyncOperationProgressHandler_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress __FIAsyncOperationProgressHandler_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress;

typedef interface __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress;

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if !defined(____FIAsyncOperationWithProgressCompletedHandler_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress_INTERFACE_DEFINED__)
#define ____FIAsyncOperationWithProgressCompletedHandler_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress_INTERFACE_DEFINED__

typedef interface __FIAsyncOperationWithProgressCompletedHandler_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress __FIAsyncOperationWithProgressCompletedHandler_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIAsyncOperationWithProgressCompletedHandler_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress;

typedef struct __FIAsyncOperationWithProgressCompletedHandler_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgressVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIAsyncOperationWithProgressCompletedHandler_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIAsyncOperationWithProgressCompletedHandler_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIAsyncOperationWithProgressCompletedHandler_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress* This);
    HRESULT (STDMETHODCALLTYPE* Invoke)(__FIAsyncOperationWithProgressCompletedHandler_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress* This,
        __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress* asyncInfo,
        AsyncStatus asyncStatus);

    END_INTERFACE
} __FIAsyncOperationWithProgressCompletedHandler_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgressVtbl;

interface __FIAsyncOperationWithProgressCompletedHandler_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress
{
    CONST_VTBL struct __FIAsyncOperationWithProgressCompletedHandler_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgressVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIAsyncOperationWithProgressCompletedHandler_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIAsyncOperationWithProgressCompletedHandler_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIAsyncOperationWithProgressCompletedHandler_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIAsyncOperationWithProgressCompletedHandler_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress_Invoke(This, asyncInfo, asyncStatus) \
    ((This)->lpVtbl->Invoke(This, asyncInfo, asyncStatus))

#endif /* COBJMACROS */

#endif // ____FIAsyncOperationWithProgressCompletedHandler_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress_INTERFACE_DEFINED__
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if !defined(____FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress_INTERFACE_DEFINED__)
#define ____FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress_INTERFACE_DEFINED__

typedef interface __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress;

typedef struct __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgressVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* put_Progress)(__FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress* This,
        __FIAsyncOperationProgressHandler_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress* handler);
    HRESULT (STDMETHODCALLTYPE* get_Progress)(__FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress* This,
        __FIAsyncOperationProgressHandler_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress** result);
    HRESULT (STDMETHODCALLTYPE* put_Completed)(__FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress* This,
        __FIAsyncOperationWithProgressCompletedHandler_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress* handler);
    HRESULT (STDMETHODCALLTYPE* get_Completed)(__FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress* This,
        __FIAsyncOperationWithProgressCompletedHandler_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress** result);
    HRESULT (STDMETHODCALLTYPE* GetResults)(__FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress* This,
        __x_ABI_CWindows_CManagement_CDeployment_CIDeploymentResult** result);

    END_INTERFACE
} __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgressVtbl;

interface __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress
{
    CONST_VTBL struct __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgressVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress_put_Progress(This, handler) \
    ((This)->lpVtbl->put_Progress(This, handler))

#define __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress_get_Progress(This, result) \
    ((This)->lpVtbl->get_Progress(This, result))

#define __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress_put_Completed(This, handler) \
    ((This)->lpVtbl->put_Completed(This, handler))

#define __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress_get_Completed(This, result) \
    ((This)->lpVtbl->get_Completed(This, result))

#define __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress_GetResults(This, result) \
    ((This)->lpVtbl->GetResults(This, result))

#endif /* COBJMACROS */

#endif // ____FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress_INTERFACE_DEFINED__
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if !defined(____FIAsyncOperationProgressHandler_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress_INTERFACE_DEFINED__)
#define ____FIAsyncOperationProgressHandler_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress_INTERFACE_DEFINED__

typedef interface __FIAsyncOperationProgressHandler_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress __FIAsyncOperationProgressHandler_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIAsyncOperationProgressHandler_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress;

typedef struct __FIAsyncOperationProgressHandler_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgressVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIAsyncOperationProgressHandler_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIAsyncOperationProgressHandler_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIAsyncOperationProgressHandler_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress* This);
    HRESULT (STDMETHODCALLTYPE* Invoke)(__FIAsyncOperationProgressHandler_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress* This,
        __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress* asyncInfo,
        struct __x_ABI_CWindows_CManagement_CDeployment_CDeploymentProgress progressInfo);

    END_INTERFACE
} __FIAsyncOperationProgressHandler_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgressVtbl;

interface __FIAsyncOperationProgressHandler_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress
{
    CONST_VTBL struct __FIAsyncOperationProgressHandler_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgressVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIAsyncOperationProgressHandler_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIAsyncOperationProgressHandler_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIAsyncOperationProgressHandler_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIAsyncOperationProgressHandler_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress_Invoke(This, asyncInfo, progressInfo) \
    ((This)->lpVtbl->Invoke(This, asyncInfo, progressInfo))

#endif /* COBJMACROS */

#endif // ____FIAsyncOperationProgressHandler_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress_INTERFACE_DEFINED__
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#if !defined(____FIIterator_1_HSTRING_INTERFACE_DEFINED__)
#define ____FIIterator_1_HSTRING_INTERFACE_DEFINED__

typedef interface __FIIterator_1_HSTRING __FIIterator_1_HSTRING;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterator_1_HSTRING;

typedef struct __FIIterator_1_HSTRINGVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIIterator_1_HSTRING* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIIterator_1_HSTRING* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIIterator_1_HSTRING* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIIterator_1_HSTRING* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIIterator_1_HSTRING* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIIterator_1_HSTRING* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Current)(__FIIterator_1_HSTRING* This,
        HSTRING* result);
    HRESULT (STDMETHODCALLTYPE* get_HasCurrent)(__FIIterator_1_HSTRING* This,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* MoveNext)(__FIIterator_1_HSTRING* This,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* GetMany)(__FIIterator_1_HSTRING* This,
        UINT32 itemsLength,
        HSTRING* items,
        UINT32* result);

    END_INTERFACE
} __FIIterator_1_HSTRINGVtbl;

interface __FIIterator_1_HSTRING
{
    CONST_VTBL struct __FIIterator_1_HSTRINGVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIIterator_1_HSTRING_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIIterator_1_HSTRING_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIIterator_1_HSTRING_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIIterator_1_HSTRING_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIIterator_1_HSTRING_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIIterator_1_HSTRING_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIIterator_1_HSTRING_get_Current(This, result) \
    ((This)->lpVtbl->get_Current(This, result))

#define __FIIterator_1_HSTRING_get_HasCurrent(This, result) \
    ((This)->lpVtbl->get_HasCurrent(This, result))

#define __FIIterator_1_HSTRING_MoveNext(This, result) \
    ((This)->lpVtbl->MoveNext(This, result))

#define __FIIterator_1_HSTRING_GetMany(This, itemsLength, items, result) \
    ((This)->lpVtbl->GetMany(This, itemsLength, items, result))

#endif /* COBJMACROS */

#endif // ____FIIterator_1_HSTRING_INTERFACE_DEFINED__

#if !defined(____FIIterable_1_HSTRING_INTERFACE_DEFINED__)
#define ____FIIterable_1_HSTRING_INTERFACE_DEFINED__

typedef interface __FIIterable_1_HSTRING __FIIterable_1_HSTRING;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterable_1_HSTRING;

typedef struct __FIIterable_1_HSTRINGVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIIterable_1_HSTRING* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIIterable_1_HSTRING* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIIterable_1_HSTRING* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIIterable_1_HSTRING* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIIterable_1_HSTRING* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIIterable_1_HSTRING* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* First)(__FIIterable_1_HSTRING* This,
        __FIIterator_1_HSTRING** result);

    END_INTERFACE
} __FIIterable_1_HSTRINGVtbl;

interface __FIIterable_1_HSTRING
{
    CONST_VTBL struct __FIIterable_1_HSTRINGVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIIterable_1_HSTRING_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIIterable_1_HSTRING_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIIterable_1_HSTRING_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIIterable_1_HSTRING_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIIterable_1_HSTRING_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIIterable_1_HSTRING_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIIterable_1_HSTRING_First(This, result) \
    ((This)->lpVtbl->First(This, result))

#endif /* COBJMACROS */

#endif // ____FIIterable_1_HSTRING_INTERFACE_DEFINED__

#ifndef ____x_ABI_CWindows_CApplicationModel_CIPackage_FWD_DEFINED__
#define ____x_ABI_CWindows_CApplicationModel_CIPackage_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CApplicationModel_CIPackage __x_ABI_CWindows_CApplicationModel_CIPackage;

#endif // ____x_ABI_CWindows_CApplicationModel_CIPackage_FWD_DEFINED__

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if !defined(____FIIterator_1_Windows__CApplicationModel__CPackage_INTERFACE_DEFINED__)
#define ____FIIterator_1_Windows__CApplicationModel__CPackage_INTERFACE_DEFINED__

typedef interface __FIIterator_1_Windows__CApplicationModel__CPackage __FIIterator_1_Windows__CApplicationModel__CPackage;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterator_1_Windows__CApplicationModel__CPackage;

typedef struct __FIIterator_1_Windows__CApplicationModel__CPackageVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIIterator_1_Windows__CApplicationModel__CPackage* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIIterator_1_Windows__CApplicationModel__CPackage* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIIterator_1_Windows__CApplicationModel__CPackage* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIIterator_1_Windows__CApplicationModel__CPackage* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIIterator_1_Windows__CApplicationModel__CPackage* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIIterator_1_Windows__CApplicationModel__CPackage* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Current)(__FIIterator_1_Windows__CApplicationModel__CPackage* This,
        __x_ABI_CWindows_CApplicationModel_CIPackage** result);
    HRESULT (STDMETHODCALLTYPE* get_HasCurrent)(__FIIterator_1_Windows__CApplicationModel__CPackage* This,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* MoveNext)(__FIIterator_1_Windows__CApplicationModel__CPackage* This,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* GetMany)(__FIIterator_1_Windows__CApplicationModel__CPackage* This,
        UINT32 itemsLength,
        __x_ABI_CWindows_CApplicationModel_CIPackage** items,
        UINT32* result);

    END_INTERFACE
} __FIIterator_1_Windows__CApplicationModel__CPackageVtbl;

interface __FIIterator_1_Windows__CApplicationModel__CPackage
{
    CONST_VTBL struct __FIIterator_1_Windows__CApplicationModel__CPackageVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIIterator_1_Windows__CApplicationModel__CPackage_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIIterator_1_Windows__CApplicationModel__CPackage_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIIterator_1_Windows__CApplicationModel__CPackage_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIIterator_1_Windows__CApplicationModel__CPackage_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIIterator_1_Windows__CApplicationModel__CPackage_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIIterator_1_Windows__CApplicationModel__CPackage_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIIterator_1_Windows__CApplicationModel__CPackage_get_Current(This, result) \
    ((This)->lpVtbl->get_Current(This, result))

#define __FIIterator_1_Windows__CApplicationModel__CPackage_get_HasCurrent(This, result) \
    ((This)->lpVtbl->get_HasCurrent(This, result))

#define __FIIterator_1_Windows__CApplicationModel__CPackage_MoveNext(This, result) \
    ((This)->lpVtbl->MoveNext(This, result))

#define __FIIterator_1_Windows__CApplicationModel__CPackage_GetMany(This, itemsLength, items, result) \
    ((This)->lpVtbl->GetMany(This, itemsLength, items, result))

#endif /* COBJMACROS */

#endif // ____FIIterator_1_Windows__CApplicationModel__CPackage_INTERFACE_DEFINED__
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if !defined(____FIIterable_1_Windows__CApplicationModel__CPackage_INTERFACE_DEFINED__)
#define ____FIIterable_1_Windows__CApplicationModel__CPackage_INTERFACE_DEFINED__

typedef interface __FIIterable_1_Windows__CApplicationModel__CPackage __FIIterable_1_Windows__CApplicationModel__CPackage;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterable_1_Windows__CApplicationModel__CPackage;

typedef struct __FIIterable_1_Windows__CApplicationModel__CPackageVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIIterable_1_Windows__CApplicationModel__CPackage* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIIterable_1_Windows__CApplicationModel__CPackage* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIIterable_1_Windows__CApplicationModel__CPackage* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIIterable_1_Windows__CApplicationModel__CPackage* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIIterable_1_Windows__CApplicationModel__CPackage* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIIterable_1_Windows__CApplicationModel__CPackage* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* First)(__FIIterable_1_Windows__CApplicationModel__CPackage* This,
        __FIIterator_1_Windows__CApplicationModel__CPackage** result);

    END_INTERFACE
} __FIIterable_1_Windows__CApplicationModel__CPackageVtbl;

interface __FIIterable_1_Windows__CApplicationModel__CPackage
{
    CONST_VTBL struct __FIIterable_1_Windows__CApplicationModel__CPackageVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIIterable_1_Windows__CApplicationModel__CPackage_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIIterable_1_Windows__CApplicationModel__CPackage_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIIterable_1_Windows__CApplicationModel__CPackage_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIIterable_1_Windows__CApplicationModel__CPackage_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIIterable_1_Windows__CApplicationModel__CPackage_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIIterable_1_Windows__CApplicationModel__CPackage_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIIterable_1_Windows__CApplicationModel__CPackage_First(This, result) \
    ((This)->lpVtbl->First(This, result))

#endif /* COBJMACROS */

#endif // ____FIIterable_1_Windows__CApplicationModel__CPackage_INTERFACE_DEFINED__
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#ifndef ____x_ABI_CWindows_CFoundation_CIUriRuntimeClass_FWD_DEFINED__
#define ____x_ABI_CWindows_CFoundation_CIUriRuntimeClass_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CFoundation_CIUriRuntimeClass __x_ABI_CWindows_CFoundation_CIUriRuntimeClass;

#endif // ____x_ABI_CWindows_CFoundation_CIUriRuntimeClass_FWD_DEFINED__

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if !defined(____FIIterator_1_Windows__CFoundation__CUri_INTERFACE_DEFINED__)
#define ____FIIterator_1_Windows__CFoundation__CUri_INTERFACE_DEFINED__

typedef interface __FIIterator_1_Windows__CFoundation__CUri __FIIterator_1_Windows__CFoundation__CUri;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterator_1_Windows__CFoundation__CUri;

typedef struct __FIIterator_1_Windows__CFoundation__CUriVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIIterator_1_Windows__CFoundation__CUri* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIIterator_1_Windows__CFoundation__CUri* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIIterator_1_Windows__CFoundation__CUri* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIIterator_1_Windows__CFoundation__CUri* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIIterator_1_Windows__CFoundation__CUri* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIIterator_1_Windows__CFoundation__CUri* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Current)(__FIIterator_1_Windows__CFoundation__CUri* This,
        __x_ABI_CWindows_CFoundation_CIUriRuntimeClass** result);
    HRESULT (STDMETHODCALLTYPE* get_HasCurrent)(__FIIterator_1_Windows__CFoundation__CUri* This,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* MoveNext)(__FIIterator_1_Windows__CFoundation__CUri* This,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* GetMany)(__FIIterator_1_Windows__CFoundation__CUri* This,
        UINT32 itemsLength,
        __x_ABI_CWindows_CFoundation_CIUriRuntimeClass** items,
        UINT32* result);

    END_INTERFACE
} __FIIterator_1_Windows__CFoundation__CUriVtbl;

interface __FIIterator_1_Windows__CFoundation__CUri
{
    CONST_VTBL struct __FIIterator_1_Windows__CFoundation__CUriVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIIterator_1_Windows__CFoundation__CUri_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIIterator_1_Windows__CFoundation__CUri_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIIterator_1_Windows__CFoundation__CUri_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIIterator_1_Windows__CFoundation__CUri_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIIterator_1_Windows__CFoundation__CUri_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIIterator_1_Windows__CFoundation__CUri_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIIterator_1_Windows__CFoundation__CUri_get_Current(This, result) \
    ((This)->lpVtbl->get_Current(This, result))

#define __FIIterator_1_Windows__CFoundation__CUri_get_HasCurrent(This, result) \
    ((This)->lpVtbl->get_HasCurrent(This, result))

#define __FIIterator_1_Windows__CFoundation__CUri_MoveNext(This, result) \
    ((This)->lpVtbl->MoveNext(This, result))

#define __FIIterator_1_Windows__CFoundation__CUri_GetMany(This, itemsLength, items, result) \
    ((This)->lpVtbl->GetMany(This, itemsLength, items, result))

#endif /* COBJMACROS */

#endif // ____FIIterator_1_Windows__CFoundation__CUri_INTERFACE_DEFINED__
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if !defined(____FIIterable_1_Windows__CFoundation__CUri_INTERFACE_DEFINED__)
#define ____FIIterable_1_Windows__CFoundation__CUri_INTERFACE_DEFINED__

typedef interface __FIIterable_1_Windows__CFoundation__CUri __FIIterable_1_Windows__CFoundation__CUri;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterable_1_Windows__CFoundation__CUri;

typedef struct __FIIterable_1_Windows__CFoundation__CUriVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIIterable_1_Windows__CFoundation__CUri* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIIterable_1_Windows__CFoundation__CUri* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIIterable_1_Windows__CFoundation__CUri* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIIterable_1_Windows__CFoundation__CUri* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIIterable_1_Windows__CFoundation__CUri* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIIterable_1_Windows__CFoundation__CUri* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* First)(__FIIterable_1_Windows__CFoundation__CUri* This,
        __FIIterator_1_Windows__CFoundation__CUri** result);

    END_INTERFACE
} __FIIterable_1_Windows__CFoundation__CUriVtbl;

interface __FIIterable_1_Windows__CFoundation__CUri
{
    CONST_VTBL struct __FIIterable_1_Windows__CFoundation__CUriVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIIterable_1_Windows__CFoundation__CUri_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIIterable_1_Windows__CFoundation__CUri_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIIterable_1_Windows__CFoundation__CUri_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIIterable_1_Windows__CFoundation__CUri_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIIterable_1_Windows__CFoundation__CUri_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIIterable_1_Windows__CFoundation__CUri_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIIterable_1_Windows__CFoundation__CUri_First(This, result) \
    ((This)->lpVtbl->First(This, result))

#endif /* COBJMACROS */

#endif // ____FIIterable_1_Windows__CFoundation__CUri_INTERFACE_DEFINED__
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if !defined(____FIIterator_1_Windows__CManagement__CDeployment__CPackageUserInformation_INTERFACE_DEFINED__)
#define ____FIIterator_1_Windows__CManagement__CDeployment__CPackageUserInformation_INTERFACE_DEFINED__

typedef interface __FIIterator_1_Windows__CManagement__CDeployment__CPackageUserInformation __FIIterator_1_Windows__CManagement__CDeployment__CPackageUserInformation;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterator_1_Windows__CManagement__CDeployment__CPackageUserInformation;

typedef struct __FIIterator_1_Windows__CManagement__CDeployment__CPackageUserInformationVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIIterator_1_Windows__CManagement__CDeployment__CPackageUserInformation* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIIterator_1_Windows__CManagement__CDeployment__CPackageUserInformation* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIIterator_1_Windows__CManagement__CDeployment__CPackageUserInformation* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIIterator_1_Windows__CManagement__CDeployment__CPackageUserInformation* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIIterator_1_Windows__CManagement__CDeployment__CPackageUserInformation* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIIterator_1_Windows__CManagement__CDeployment__CPackageUserInformation* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Current)(__FIIterator_1_Windows__CManagement__CDeployment__CPackageUserInformation* This,
        __x_ABI_CWindows_CManagement_CDeployment_CIPackageUserInformation** result);
    HRESULT (STDMETHODCALLTYPE* get_HasCurrent)(__FIIterator_1_Windows__CManagement__CDeployment__CPackageUserInformation* This,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* MoveNext)(__FIIterator_1_Windows__CManagement__CDeployment__CPackageUserInformation* This,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* GetMany)(__FIIterator_1_Windows__CManagement__CDeployment__CPackageUserInformation* This,
        UINT32 itemsLength,
        __x_ABI_CWindows_CManagement_CDeployment_CIPackageUserInformation** items,
        UINT32* result);

    END_INTERFACE
} __FIIterator_1_Windows__CManagement__CDeployment__CPackageUserInformationVtbl;

interface __FIIterator_1_Windows__CManagement__CDeployment__CPackageUserInformation
{
    CONST_VTBL struct __FIIterator_1_Windows__CManagement__CDeployment__CPackageUserInformationVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIIterator_1_Windows__CManagement__CDeployment__CPackageUserInformation_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIIterator_1_Windows__CManagement__CDeployment__CPackageUserInformation_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIIterator_1_Windows__CManagement__CDeployment__CPackageUserInformation_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIIterator_1_Windows__CManagement__CDeployment__CPackageUserInformation_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIIterator_1_Windows__CManagement__CDeployment__CPackageUserInformation_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIIterator_1_Windows__CManagement__CDeployment__CPackageUserInformation_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIIterator_1_Windows__CManagement__CDeployment__CPackageUserInformation_get_Current(This, result) \
    ((This)->lpVtbl->get_Current(This, result))

#define __FIIterator_1_Windows__CManagement__CDeployment__CPackageUserInformation_get_HasCurrent(This, result) \
    ((This)->lpVtbl->get_HasCurrent(This, result))

#define __FIIterator_1_Windows__CManagement__CDeployment__CPackageUserInformation_MoveNext(This, result) \
    ((This)->lpVtbl->MoveNext(This, result))

#define __FIIterator_1_Windows__CManagement__CDeployment__CPackageUserInformation_GetMany(This, itemsLength, items, result) \
    ((This)->lpVtbl->GetMany(This, itemsLength, items, result))

#endif /* COBJMACROS */

#endif // ____FIIterator_1_Windows__CManagement__CDeployment__CPackageUserInformation_INTERFACE_DEFINED__
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if !defined(____FIIterable_1_Windows__CManagement__CDeployment__CPackageUserInformation_INTERFACE_DEFINED__)
#define ____FIIterable_1_Windows__CManagement__CDeployment__CPackageUserInformation_INTERFACE_DEFINED__

typedef interface __FIIterable_1_Windows__CManagement__CDeployment__CPackageUserInformation __FIIterable_1_Windows__CManagement__CDeployment__CPackageUserInformation;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterable_1_Windows__CManagement__CDeployment__CPackageUserInformation;

typedef struct __FIIterable_1_Windows__CManagement__CDeployment__CPackageUserInformationVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIIterable_1_Windows__CManagement__CDeployment__CPackageUserInformation* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIIterable_1_Windows__CManagement__CDeployment__CPackageUserInformation* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIIterable_1_Windows__CManagement__CDeployment__CPackageUserInformation* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIIterable_1_Windows__CManagement__CDeployment__CPackageUserInformation* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIIterable_1_Windows__CManagement__CDeployment__CPackageUserInformation* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIIterable_1_Windows__CManagement__CDeployment__CPackageUserInformation* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* First)(__FIIterable_1_Windows__CManagement__CDeployment__CPackageUserInformation* This,
        __FIIterator_1_Windows__CManagement__CDeployment__CPackageUserInformation** result);

    END_INTERFACE
} __FIIterable_1_Windows__CManagement__CDeployment__CPackageUserInformationVtbl;

interface __FIIterable_1_Windows__CManagement__CDeployment__CPackageUserInformation
{
    CONST_VTBL struct __FIIterable_1_Windows__CManagement__CDeployment__CPackageUserInformationVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIIterable_1_Windows__CManagement__CDeployment__CPackageUserInformation_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIIterable_1_Windows__CManagement__CDeployment__CPackageUserInformation_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIIterable_1_Windows__CManagement__CDeployment__CPackageUserInformation_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIIterable_1_Windows__CManagement__CDeployment__CPackageUserInformation_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIIterable_1_Windows__CManagement__CDeployment__CPackageUserInformation_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIIterable_1_Windows__CManagement__CDeployment__CPackageUserInformation_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIIterable_1_Windows__CManagement__CDeployment__CPackageUserInformation_First(This, result) \
    ((This)->lpVtbl->First(This, result))

#endif /* COBJMACROS */

#endif // ____FIIterable_1_Windows__CManagement__CDeployment__CPackageUserInformation_INTERFACE_DEFINED__
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#if !defined(____FIVectorView_1_HSTRING_INTERFACE_DEFINED__)
#define ____FIVectorView_1_HSTRING_INTERFACE_DEFINED__

typedef interface __FIVectorView_1_HSTRING __FIVectorView_1_HSTRING;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIVectorView_1_HSTRING;

typedef struct __FIVectorView_1_HSTRINGVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIVectorView_1_HSTRING* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIVectorView_1_HSTRING* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIVectorView_1_HSTRING* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIVectorView_1_HSTRING* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIVectorView_1_HSTRING* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIVectorView_1_HSTRING* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* GetAt)(__FIVectorView_1_HSTRING* This,
        UINT32 index,
        HSTRING* result);
    HRESULT (STDMETHODCALLTYPE* get_Size)(__FIVectorView_1_HSTRING* This,
        UINT32* result);
    HRESULT (STDMETHODCALLTYPE* IndexOf)(__FIVectorView_1_HSTRING* This,
        HSTRING value,
        UINT32* index,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* GetMany)(__FIVectorView_1_HSTRING* This,
        UINT32 startIndex,
        UINT32 itemsLength,
        HSTRING* items,
        UINT32* result);

    END_INTERFACE
} __FIVectorView_1_HSTRINGVtbl;

interface __FIVectorView_1_HSTRING
{
    CONST_VTBL struct __FIVectorView_1_HSTRINGVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIVectorView_1_HSTRING_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIVectorView_1_HSTRING_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIVectorView_1_HSTRING_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIVectorView_1_HSTRING_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIVectorView_1_HSTRING_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIVectorView_1_HSTRING_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIVectorView_1_HSTRING_GetAt(This, index, result) \
    ((This)->lpVtbl->GetAt(This, index, result))

#define __FIVectorView_1_HSTRING_get_Size(This, result) \
    ((This)->lpVtbl->get_Size(This, result))

#define __FIVectorView_1_HSTRING_IndexOf(This, value, index, result) \
    ((This)->lpVtbl->IndexOf(This, value, index, result))

#define __FIVectorView_1_HSTRING_GetMany(This, startIndex, itemsLength, items, result) \
    ((This)->lpVtbl->GetMany(This, startIndex, itemsLength, items, result))

#endif /* COBJMACROS */

#endif // ____FIVectorView_1_HSTRING_INTERFACE_DEFINED__

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if !defined(____FIVectorView_1_Windows__CApplicationModel__CPackage_INTERFACE_DEFINED__)
#define ____FIVectorView_1_Windows__CApplicationModel__CPackage_INTERFACE_DEFINED__

typedef interface __FIVectorView_1_Windows__CApplicationModel__CPackage __FIVectorView_1_Windows__CApplicationModel__CPackage;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIVectorView_1_Windows__CApplicationModel__CPackage;

typedef struct __FIVectorView_1_Windows__CApplicationModel__CPackageVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIVectorView_1_Windows__CApplicationModel__CPackage* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIVectorView_1_Windows__CApplicationModel__CPackage* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIVectorView_1_Windows__CApplicationModel__CPackage* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIVectorView_1_Windows__CApplicationModel__CPackage* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIVectorView_1_Windows__CApplicationModel__CPackage* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIVectorView_1_Windows__CApplicationModel__CPackage* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* GetAt)(__FIVectorView_1_Windows__CApplicationModel__CPackage* This,
        UINT32 index,
        __x_ABI_CWindows_CApplicationModel_CIPackage** result);
    HRESULT (STDMETHODCALLTYPE* get_Size)(__FIVectorView_1_Windows__CApplicationModel__CPackage* This,
        UINT32* result);
    HRESULT (STDMETHODCALLTYPE* IndexOf)(__FIVectorView_1_Windows__CApplicationModel__CPackage* This,
        __x_ABI_CWindows_CApplicationModel_CIPackage* value,
        UINT32* index,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* GetMany)(__FIVectorView_1_Windows__CApplicationModel__CPackage* This,
        UINT32 startIndex,
        UINT32 itemsLength,
        __x_ABI_CWindows_CApplicationModel_CIPackage** items,
        UINT32* result);

    END_INTERFACE
} __FIVectorView_1_Windows__CApplicationModel__CPackageVtbl;

interface __FIVectorView_1_Windows__CApplicationModel__CPackage
{
    CONST_VTBL struct __FIVectorView_1_Windows__CApplicationModel__CPackageVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIVectorView_1_Windows__CApplicationModel__CPackage_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIVectorView_1_Windows__CApplicationModel__CPackage_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIVectorView_1_Windows__CApplicationModel__CPackage_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIVectorView_1_Windows__CApplicationModel__CPackage_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIVectorView_1_Windows__CApplicationModel__CPackage_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIVectorView_1_Windows__CApplicationModel__CPackage_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIVectorView_1_Windows__CApplicationModel__CPackage_GetAt(This, index, result) \
    ((This)->lpVtbl->GetAt(This, index, result))

#define __FIVectorView_1_Windows__CApplicationModel__CPackage_get_Size(This, result) \
    ((This)->lpVtbl->get_Size(This, result))

#define __FIVectorView_1_Windows__CApplicationModel__CPackage_IndexOf(This, value, index, result) \
    ((This)->lpVtbl->IndexOf(This, value, index, result))

#define __FIVectorView_1_Windows__CApplicationModel__CPackage_GetMany(This, startIndex, itemsLength, items, result) \
    ((This)->lpVtbl->GetMany(This, startIndex, itemsLength, items, result))

#endif /* COBJMACROS */

#endif // ____FIVectorView_1_Windows__CApplicationModel__CPackage_INTERFACE_DEFINED__
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if !defined(____FIVectorView_1_Windows__CFoundation__CUri_INTERFACE_DEFINED__)
#define ____FIVectorView_1_Windows__CFoundation__CUri_INTERFACE_DEFINED__

typedef interface __FIVectorView_1_Windows__CFoundation__CUri __FIVectorView_1_Windows__CFoundation__CUri;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIVectorView_1_Windows__CFoundation__CUri;

typedef struct __FIVectorView_1_Windows__CFoundation__CUriVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIVectorView_1_Windows__CFoundation__CUri* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIVectorView_1_Windows__CFoundation__CUri* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIVectorView_1_Windows__CFoundation__CUri* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIVectorView_1_Windows__CFoundation__CUri* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIVectorView_1_Windows__CFoundation__CUri* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIVectorView_1_Windows__CFoundation__CUri* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* GetAt)(__FIVectorView_1_Windows__CFoundation__CUri* This,
        UINT32 index,
        __x_ABI_CWindows_CFoundation_CIUriRuntimeClass** result);
    HRESULT (STDMETHODCALLTYPE* get_Size)(__FIVectorView_1_Windows__CFoundation__CUri* This,
        UINT32* result);
    HRESULT (STDMETHODCALLTYPE* IndexOf)(__FIVectorView_1_Windows__CFoundation__CUri* This,
        __x_ABI_CWindows_CFoundation_CIUriRuntimeClass* value,
        UINT32* index,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* GetMany)(__FIVectorView_1_Windows__CFoundation__CUri* This,
        UINT32 startIndex,
        UINT32 itemsLength,
        __x_ABI_CWindows_CFoundation_CIUriRuntimeClass** items,
        UINT32* result);

    END_INTERFACE
} __FIVectorView_1_Windows__CFoundation__CUriVtbl;

interface __FIVectorView_1_Windows__CFoundation__CUri
{
    CONST_VTBL struct __FIVectorView_1_Windows__CFoundation__CUriVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIVectorView_1_Windows__CFoundation__CUri_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIVectorView_1_Windows__CFoundation__CUri_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIVectorView_1_Windows__CFoundation__CUri_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIVectorView_1_Windows__CFoundation__CUri_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIVectorView_1_Windows__CFoundation__CUri_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIVectorView_1_Windows__CFoundation__CUri_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIVectorView_1_Windows__CFoundation__CUri_GetAt(This, index, result) \
    ((This)->lpVtbl->GetAt(This, index, result))

#define __FIVectorView_1_Windows__CFoundation__CUri_get_Size(This, result) \
    ((This)->lpVtbl->get_Size(This, result))

#define __FIVectorView_1_Windows__CFoundation__CUri_IndexOf(This, value, index, result) \
    ((This)->lpVtbl->IndexOf(This, value, index, result))

#define __FIVectorView_1_Windows__CFoundation__CUri_GetMany(This, startIndex, itemsLength, items, result) \
    ((This)->lpVtbl->GetMany(This, startIndex, itemsLength, items, result))

#endif /* COBJMACROS */

#endif // ____FIVectorView_1_Windows__CFoundation__CUri_INTERFACE_DEFINED__
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#if !defined(____FIVector_1_HSTRING_INTERFACE_DEFINED__)
#define ____FIVector_1_HSTRING_INTERFACE_DEFINED__

typedef interface __FIVector_1_HSTRING __FIVector_1_HSTRING;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIVector_1_HSTRING;

typedef struct __FIVector_1_HSTRINGVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIVector_1_HSTRING* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIVector_1_HSTRING* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIVector_1_HSTRING* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIVector_1_HSTRING* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIVector_1_HSTRING* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIVector_1_HSTRING* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* GetAt)(__FIVector_1_HSTRING* This,
        UINT32 index,
        HSTRING* result);
    HRESULT (STDMETHODCALLTYPE* get_Size)(__FIVector_1_HSTRING* This,
        UINT32* result);
    HRESULT (STDMETHODCALLTYPE* GetView)(__FIVector_1_HSTRING* This,
        __FIVectorView_1_HSTRING** result);
    HRESULT (STDMETHODCALLTYPE* IndexOf)(__FIVector_1_HSTRING* This,
        HSTRING value,
        UINT32* index,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* SetAt)(__FIVector_1_HSTRING* This,
        UINT32 index,
        HSTRING value);
    HRESULT (STDMETHODCALLTYPE* InsertAt)(__FIVector_1_HSTRING* This,
        UINT32 index,
        HSTRING value);
    HRESULT (STDMETHODCALLTYPE* RemoveAt)(__FIVector_1_HSTRING* This,
        UINT32 index);
    HRESULT (STDMETHODCALLTYPE* Append)(__FIVector_1_HSTRING* This,
        HSTRING value);
    HRESULT (STDMETHODCALLTYPE* RemoveAtEnd)(__FIVector_1_HSTRING* This);
    HRESULT (STDMETHODCALLTYPE* Clear)(__FIVector_1_HSTRING* This);
    HRESULT (STDMETHODCALLTYPE* GetMany)(__FIVector_1_HSTRING* This,
        UINT32 startIndex,
        UINT32 itemsLength,
        HSTRING* items,
        UINT32* result);
    HRESULT (STDMETHODCALLTYPE* ReplaceAll)(__FIVector_1_HSTRING* This,
        UINT32 itemsLength,
        HSTRING* items);

    END_INTERFACE
} __FIVector_1_HSTRINGVtbl;

interface __FIVector_1_HSTRING
{
    CONST_VTBL struct __FIVector_1_HSTRINGVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIVector_1_HSTRING_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIVector_1_HSTRING_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIVector_1_HSTRING_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIVector_1_HSTRING_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIVector_1_HSTRING_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIVector_1_HSTRING_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIVector_1_HSTRING_GetAt(This, index, result) \
    ((This)->lpVtbl->GetAt(This, index, result))

#define __FIVector_1_HSTRING_get_Size(This, result) \
    ((This)->lpVtbl->get_Size(This, result))

#define __FIVector_1_HSTRING_GetView(This, result) \
    ((This)->lpVtbl->GetView(This, result))

#define __FIVector_1_HSTRING_IndexOf(This, value, index, result) \
    ((This)->lpVtbl->IndexOf(This, value, index, result))

#define __FIVector_1_HSTRING_SetAt(This, index, value) \
    ((This)->lpVtbl->SetAt(This, index, value))

#define __FIVector_1_HSTRING_InsertAt(This, index, value) \
    ((This)->lpVtbl->InsertAt(This, index, value))

#define __FIVector_1_HSTRING_RemoveAt(This, index) \
    ((This)->lpVtbl->RemoveAt(This, index))

#define __FIVector_1_HSTRING_Append(This, value) \
    ((This)->lpVtbl->Append(This, value))

#define __FIVector_1_HSTRING_RemoveAtEnd(This) \
    ((This)->lpVtbl->RemoveAtEnd(This))

#define __FIVector_1_HSTRING_Clear(This) \
    ((This)->lpVtbl->Clear(This))

#define __FIVector_1_HSTRING_GetMany(This, startIndex, itemsLength, items, result) \
    ((This)->lpVtbl->GetMany(This, startIndex, itemsLength, items, result))

#define __FIVector_1_HSTRING_ReplaceAll(This, itemsLength, items) \
    ((This)->lpVtbl->ReplaceAll(This, itemsLength, items))

#endif /* COBJMACROS */

#endif // ____FIVector_1_HSTRING_INTERFACE_DEFINED__

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if !defined(____FIVector_1_Windows__CApplicationModel__CPackage_INTERFACE_DEFINED__)
#define ____FIVector_1_Windows__CApplicationModel__CPackage_INTERFACE_DEFINED__

typedef interface __FIVector_1_Windows__CApplicationModel__CPackage __FIVector_1_Windows__CApplicationModel__CPackage;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIVector_1_Windows__CApplicationModel__CPackage;

typedef struct __FIVector_1_Windows__CApplicationModel__CPackageVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIVector_1_Windows__CApplicationModel__CPackage* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIVector_1_Windows__CApplicationModel__CPackage* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIVector_1_Windows__CApplicationModel__CPackage* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIVector_1_Windows__CApplicationModel__CPackage* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIVector_1_Windows__CApplicationModel__CPackage* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIVector_1_Windows__CApplicationModel__CPackage* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* GetAt)(__FIVector_1_Windows__CApplicationModel__CPackage* This,
        UINT32 index,
        __x_ABI_CWindows_CApplicationModel_CIPackage** result);
    HRESULT (STDMETHODCALLTYPE* get_Size)(__FIVector_1_Windows__CApplicationModel__CPackage* This,
        UINT32* result);
    HRESULT (STDMETHODCALLTYPE* GetView)(__FIVector_1_Windows__CApplicationModel__CPackage* This,
        __FIVectorView_1_Windows__CApplicationModel__CPackage** result);
    HRESULT (STDMETHODCALLTYPE* IndexOf)(__FIVector_1_Windows__CApplicationModel__CPackage* This,
        __x_ABI_CWindows_CApplicationModel_CIPackage* value,
        UINT32* index,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* SetAt)(__FIVector_1_Windows__CApplicationModel__CPackage* This,
        UINT32 index,
        __x_ABI_CWindows_CApplicationModel_CIPackage* value);
    HRESULT (STDMETHODCALLTYPE* InsertAt)(__FIVector_1_Windows__CApplicationModel__CPackage* This,
        UINT32 index,
        __x_ABI_CWindows_CApplicationModel_CIPackage* value);
    HRESULT (STDMETHODCALLTYPE* RemoveAt)(__FIVector_1_Windows__CApplicationModel__CPackage* This,
        UINT32 index);
    HRESULT (STDMETHODCALLTYPE* Append)(__FIVector_1_Windows__CApplicationModel__CPackage* This,
        __x_ABI_CWindows_CApplicationModel_CIPackage* value);
    HRESULT (STDMETHODCALLTYPE* RemoveAtEnd)(__FIVector_1_Windows__CApplicationModel__CPackage* This);
    HRESULT (STDMETHODCALLTYPE* Clear)(__FIVector_1_Windows__CApplicationModel__CPackage* This);
    HRESULT (STDMETHODCALLTYPE* GetMany)(__FIVector_1_Windows__CApplicationModel__CPackage* This,
        UINT32 startIndex,
        UINT32 itemsLength,
        __x_ABI_CWindows_CApplicationModel_CIPackage** items,
        UINT32* result);
    HRESULT (STDMETHODCALLTYPE* ReplaceAll)(__FIVector_1_Windows__CApplicationModel__CPackage* This,
        UINT32 itemsLength,
        __x_ABI_CWindows_CApplicationModel_CIPackage** items);

    END_INTERFACE
} __FIVector_1_Windows__CApplicationModel__CPackageVtbl;

interface __FIVector_1_Windows__CApplicationModel__CPackage
{
    CONST_VTBL struct __FIVector_1_Windows__CApplicationModel__CPackageVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIVector_1_Windows__CApplicationModel__CPackage_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIVector_1_Windows__CApplicationModel__CPackage_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIVector_1_Windows__CApplicationModel__CPackage_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIVector_1_Windows__CApplicationModel__CPackage_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIVector_1_Windows__CApplicationModel__CPackage_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIVector_1_Windows__CApplicationModel__CPackage_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIVector_1_Windows__CApplicationModel__CPackage_GetAt(This, index, result) \
    ((This)->lpVtbl->GetAt(This, index, result))

#define __FIVector_1_Windows__CApplicationModel__CPackage_get_Size(This, result) \
    ((This)->lpVtbl->get_Size(This, result))

#define __FIVector_1_Windows__CApplicationModel__CPackage_GetView(This, result) \
    ((This)->lpVtbl->GetView(This, result))

#define __FIVector_1_Windows__CApplicationModel__CPackage_IndexOf(This, value, index, result) \
    ((This)->lpVtbl->IndexOf(This, value, index, result))

#define __FIVector_1_Windows__CApplicationModel__CPackage_SetAt(This, index, value) \
    ((This)->lpVtbl->SetAt(This, index, value))

#define __FIVector_1_Windows__CApplicationModel__CPackage_InsertAt(This, index, value) \
    ((This)->lpVtbl->InsertAt(This, index, value))

#define __FIVector_1_Windows__CApplicationModel__CPackage_RemoveAt(This, index) \
    ((This)->lpVtbl->RemoveAt(This, index))

#define __FIVector_1_Windows__CApplicationModel__CPackage_Append(This, value) \
    ((This)->lpVtbl->Append(This, value))

#define __FIVector_1_Windows__CApplicationModel__CPackage_RemoveAtEnd(This) \
    ((This)->lpVtbl->RemoveAtEnd(This))

#define __FIVector_1_Windows__CApplicationModel__CPackage_Clear(This) \
    ((This)->lpVtbl->Clear(This))

#define __FIVector_1_Windows__CApplicationModel__CPackage_GetMany(This, startIndex, itemsLength, items, result) \
    ((This)->lpVtbl->GetMany(This, startIndex, itemsLength, items, result))

#define __FIVector_1_Windows__CApplicationModel__CPackage_ReplaceAll(This, itemsLength, items) \
    ((This)->lpVtbl->ReplaceAll(This, itemsLength, items))

#endif /* COBJMACROS */

#endif // ____FIVector_1_Windows__CApplicationModel__CPackage_INTERFACE_DEFINED__
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if !defined(____FIVector_1_Windows__CFoundation__CUri_INTERFACE_DEFINED__)
#define ____FIVector_1_Windows__CFoundation__CUri_INTERFACE_DEFINED__

typedef interface __FIVector_1_Windows__CFoundation__CUri __FIVector_1_Windows__CFoundation__CUri;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIVector_1_Windows__CFoundation__CUri;

typedef struct __FIVector_1_Windows__CFoundation__CUriVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIVector_1_Windows__CFoundation__CUri* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIVector_1_Windows__CFoundation__CUri* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIVector_1_Windows__CFoundation__CUri* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIVector_1_Windows__CFoundation__CUri* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIVector_1_Windows__CFoundation__CUri* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIVector_1_Windows__CFoundation__CUri* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* GetAt)(__FIVector_1_Windows__CFoundation__CUri* This,
        UINT32 index,
        __x_ABI_CWindows_CFoundation_CIUriRuntimeClass** result);
    HRESULT (STDMETHODCALLTYPE* get_Size)(__FIVector_1_Windows__CFoundation__CUri* This,
        UINT32* result);
    HRESULT (STDMETHODCALLTYPE* GetView)(__FIVector_1_Windows__CFoundation__CUri* This,
        __FIVectorView_1_Windows__CFoundation__CUri** result);
    HRESULT (STDMETHODCALLTYPE* IndexOf)(__FIVector_1_Windows__CFoundation__CUri* This,
        __x_ABI_CWindows_CFoundation_CIUriRuntimeClass* value,
        UINT32* index,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* SetAt)(__FIVector_1_Windows__CFoundation__CUri* This,
        UINT32 index,
        __x_ABI_CWindows_CFoundation_CIUriRuntimeClass* value);
    HRESULT (STDMETHODCALLTYPE* InsertAt)(__FIVector_1_Windows__CFoundation__CUri* This,
        UINT32 index,
        __x_ABI_CWindows_CFoundation_CIUriRuntimeClass* value);
    HRESULT (STDMETHODCALLTYPE* RemoveAt)(__FIVector_1_Windows__CFoundation__CUri* This,
        UINT32 index);
    HRESULT (STDMETHODCALLTYPE* Append)(__FIVector_1_Windows__CFoundation__CUri* This,
        __x_ABI_CWindows_CFoundation_CIUriRuntimeClass* value);
    HRESULT (STDMETHODCALLTYPE* RemoveAtEnd)(__FIVector_1_Windows__CFoundation__CUri* This);
    HRESULT (STDMETHODCALLTYPE* Clear)(__FIVector_1_Windows__CFoundation__CUri* This);
    HRESULT (STDMETHODCALLTYPE* GetMany)(__FIVector_1_Windows__CFoundation__CUri* This,
        UINT32 startIndex,
        UINT32 itemsLength,
        __x_ABI_CWindows_CFoundation_CIUriRuntimeClass** items,
        UINT32* result);
    HRESULT (STDMETHODCALLTYPE* ReplaceAll)(__FIVector_1_Windows__CFoundation__CUri* This,
        UINT32 itemsLength,
        __x_ABI_CWindows_CFoundation_CIUriRuntimeClass** items);

    END_INTERFACE
} __FIVector_1_Windows__CFoundation__CUriVtbl;

interface __FIVector_1_Windows__CFoundation__CUri
{
    CONST_VTBL struct __FIVector_1_Windows__CFoundation__CUriVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIVector_1_Windows__CFoundation__CUri_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIVector_1_Windows__CFoundation__CUri_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIVector_1_Windows__CFoundation__CUri_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIVector_1_Windows__CFoundation__CUri_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIVector_1_Windows__CFoundation__CUri_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIVector_1_Windows__CFoundation__CUri_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIVector_1_Windows__CFoundation__CUri_GetAt(This, index, result) \
    ((This)->lpVtbl->GetAt(This, index, result))

#define __FIVector_1_Windows__CFoundation__CUri_get_Size(This, result) \
    ((This)->lpVtbl->get_Size(This, result))

#define __FIVector_1_Windows__CFoundation__CUri_GetView(This, result) \
    ((This)->lpVtbl->GetView(This, result))

#define __FIVector_1_Windows__CFoundation__CUri_IndexOf(This, value, index, result) \
    ((This)->lpVtbl->IndexOf(This, value, index, result))

#define __FIVector_1_Windows__CFoundation__CUri_SetAt(This, index, value) \
    ((This)->lpVtbl->SetAt(This, index, value))

#define __FIVector_1_Windows__CFoundation__CUri_InsertAt(This, index, value) \
    ((This)->lpVtbl->InsertAt(This, index, value))

#define __FIVector_1_Windows__CFoundation__CUri_RemoveAt(This, index) \
    ((This)->lpVtbl->RemoveAt(This, index))

#define __FIVector_1_Windows__CFoundation__CUri_Append(This, value) \
    ((This)->lpVtbl->Append(This, value))

#define __FIVector_1_Windows__CFoundation__CUri_RemoveAtEnd(This) \
    ((This)->lpVtbl->RemoveAtEnd(This))

#define __FIVector_1_Windows__CFoundation__CUri_Clear(This) \
    ((This)->lpVtbl->Clear(This))

#define __FIVector_1_Windows__CFoundation__CUri_GetMany(This, startIndex, itemsLength, items, result) \
    ((This)->lpVtbl->GetMany(This, startIndex, itemsLength, items, result))

#define __FIVector_1_Windows__CFoundation__CUri_ReplaceAll(This, itemsLength, items) \
    ((This)->lpVtbl->ReplaceAll(This, itemsLength, items))

#endif /* COBJMACROS */

#endif // ____FIVector_1_Windows__CFoundation__CUri_INTERFACE_DEFINED__
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

typedef enum __x_ABI_CWindows_CApplicationModel_CPackageContentGroupState __x_ABI_CWindows_CApplicationModel_CPackageContentGroupState;

#ifndef ____x_ABI_CWindows_CFoundation_CIAsyncAction_FWD_DEFINED__
#define ____x_ABI_CWindows_CFoundation_CIAsyncAction_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CFoundation_CIAsyncAction __x_ABI_CWindows_CFoundation_CIAsyncAction;

#endif // ____x_ABI_CWindows_CFoundation_CIAsyncAction_FWD_DEFINED__

typedef enum __x_ABI_CWindows_CManagement_CDeployment_CAddPackageByAppInstallerOptions __x_ABI_CWindows_CManagement_CDeployment_CAddPackageByAppInstallerOptions;

typedef enum __x_ABI_CWindows_CManagement_CDeployment_CDeploymentOptions __x_ABI_CWindows_CManagement_CDeployment_CDeploymentOptions;

typedef enum __x_ABI_CWindows_CManagement_CDeployment_CDeploymentProgressState __x_ABI_CWindows_CManagement_CDeployment_CDeploymentProgressState;

typedef enum __x_ABI_CWindows_CManagement_CDeployment_CPackageInstallState __x_ABI_CWindows_CManagement_CDeployment_CPackageInstallState;

typedef enum __x_ABI_CWindows_CManagement_CDeployment_CPackageState __x_ABI_CWindows_CManagement_CDeployment_CPackageState;

typedef enum __x_ABI_CWindows_CManagement_CDeployment_CPackageStatus __x_ABI_CWindows_CManagement_CDeployment_CPackageStatus;

typedef enum __x_ABI_CWindows_CManagement_CDeployment_CPackageStubPreference __x_ABI_CWindows_CManagement_CDeployment_CPackageStubPreference;

typedef enum __x_ABI_CWindows_CManagement_CDeployment_CPackageTypes __x_ABI_CWindows_CManagement_CDeployment_CPackageTypes;

typedef enum __x_ABI_CWindows_CManagement_CDeployment_CRemovalOptions __x_ABI_CWindows_CManagement_CDeployment_CRemovalOptions;

typedef enum __x_ABI_CWindows_CManagement_CDeployment_CStubPackageOption __x_ABI_CWindows_CManagement_CDeployment_CStubPackageOption;

/*
 *
 * Struct Windows.Management.Deployment.AddPackageByAppInstallerOptions
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
enum __x_ABI_CWindows_CManagement_CDeployment_CAddPackageByAppInstallerOptions
{
    AddPackageByAppInstallerOptions_None = 0,
    AddPackageByAppInstallerOptions_InstallAllResources = 0x20,
    AddPackageByAppInstallerOptions_ForceTargetAppShutdown = 0x40,
    AddPackageByAppInstallerOptions_RequiredContentGroupOnly = 0x100,
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x80000
    AddPackageByAppInstallerOptions_LimitToExistingPackages = 0x200,
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x80000
};
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Struct Windows.Management.Deployment.DeploymentOptions
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
enum __x_ABI_CWindows_CManagement_CDeployment_CDeploymentOptions
{
    DeploymentOptions_None = 0,
    DeploymentOptions_ForceApplicationShutdown = 0x1,
    DeploymentOptions_DevelopmentMode = 0x2,
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
    DeploymentOptions_InstallAllResources = 0x20,
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
    DeploymentOptions_ForceTargetApplicationShutdown = 0x40,
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x40000
    DeploymentOptions_RequiredContentGroupOnly = 0x100,
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x40000
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x70000
    DeploymentOptions_ForceUpdateFromAnyVersion = 0x40000,
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x70000
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xa0000
    DeploymentOptions_RetainFilesOnFailure = 0x200000,
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xa0000
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xa0000
    DeploymentOptions_StageInPlace = 0x400000,
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xa0000
};
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Struct Windows.Management.Deployment.DeploymentProgressState
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
enum __x_ABI_CWindows_CManagement_CDeployment_CDeploymentProgressState
{
    DeploymentProgressState_Queued = 0,
    DeploymentProgressState_Processing = 1,
};
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Struct Windows.Management.Deployment.PackageInstallState
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
enum __x_ABI_CWindows_CManagement_CDeployment_CPackageInstallState
{
    PackageInstallState_NotInstalled = 0,
    PackageInstallState_Staged = 1,
    PackageInstallState_Installed = 2,
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x20000
    PackageInstallState_Paused = 6,
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x20000
};
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Struct Windows.Management.Deployment.PackageState
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
enum __x_ABI_CWindows_CManagement_CDeployment_CPackageState
{
    PackageState_Normal = 0,
    PackageState_LicenseInvalid = 1,
    PackageState_Modified = 2,
    PackageState_Tampered = 3,
};
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Struct Windows.Management.Deployment.PackageStatus
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
enum __x_ABI_CWindows_CManagement_CDeployment_CPackageStatus
{
    PackageStatus_OK = 0,
    PackageStatus_LicenseIssue = 0x1,
    PackageStatus_Modified = 0x2,
    PackageStatus_Tampered = 0x4,
    PackageStatus_Disabled = 0x8,
};
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Struct Windows.Management.Deployment.PackageStubPreference
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 10.0
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xa0000
enum __x_ABI_CWindows_CManagement_CDeployment_CPackageStubPreference
{
    PackageStubPreference_Full = 0,
    PackageStubPreference_Stub = 1,
};
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xa0000

/*
 *
 * Struct Windows.Management.Deployment.PackageTypes
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
enum __x_ABI_CWindows_CManagement_CDeployment_CPackageTypes
{
    PackageTypes_None = 0,
    PackageTypes_Main = 0x1,
    PackageTypes_Framework = 0x2,
    PackageTypes_Resource = 0x4,
    PackageTypes_Bundle = 0x8,
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
    PackageTypes_Xap = 0x10,
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x30000
    PackageTypes_Optional = 0x20,
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x30000
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xa0000
    PackageTypes_All = 0xffffffff,
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xa0000
};
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Struct Windows.Management.Deployment.RemovalOptions
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
enum __x_ABI_CWindows_CManagement_CDeployment_CRemovalOptions
{
    RemovalOptions_None = 0,
    RemovalOptions_PreserveApplicationData = 0x1000,
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xa0000
    RemovalOptions_PreserveRoamableApplicationData = 0x80,
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xa0000
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x70000
    RemovalOptions_RemoveForAllUsers = 0x80000,
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x70000
};
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Struct Windows.Management.Deployment.StubPackageOption
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 10.0
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xa0000
enum __x_ABI_CWindows_CManagement_CDeployment_CStubPackageOption
{
    StubPackageOption_Default = 0,
    StubPackageOption_InstallFull = 1,
    StubPackageOption_InstallStub = 2,
    StubPackageOption_UsePreference = 3,
};
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xa0000

/*
 *
 * Struct Windows.Management.Deployment.DeploymentProgress
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
struct __x_ABI_CWindows_CManagement_CDeployment_CDeploymentProgress
{
    enum __x_ABI_CWindows_CManagement_CDeployment_CDeploymentProgressState state;
    UINT32 percentage;
};
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Deployment.IAddPackageOptions
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 10.0
 *
 * Interface is a part of the implementation of type Windows.Management.Deployment.AddPackageOptions
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xa0000
#if !defined(____x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Deployment_IAddPackageOptions[] = L"Windows.Management.Deployment.IAddPackageOptions";
typedef struct __x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptionsVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_DependencyPackageUris)(__x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions* This,
        __FIVector_1_Windows__CFoundation__CUri** value);
    HRESULT (STDMETHODCALLTYPE* get_TargetVolume)(__x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions* This,
        __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume** value);
    HRESULT (STDMETHODCALLTYPE* put_TargetVolume)(__x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions* This,
        __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume* value);
    HRESULT (STDMETHODCALLTYPE* get_OptionalPackageFamilyNames)(__x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions* This,
        __FIVector_1_HSTRING** value);
    HRESULT (STDMETHODCALLTYPE* get_OptionalPackageUris)(__x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions* This,
        __FIVector_1_Windows__CFoundation__CUri** value);
    HRESULT (STDMETHODCALLTYPE* get_RelatedPackageUris)(__x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions* This,
        __FIVector_1_Windows__CFoundation__CUri** value);
    HRESULT (STDMETHODCALLTYPE* get_ExternalLocationUri)(__x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions* This,
        __x_ABI_CWindows_CFoundation_CIUriRuntimeClass** value);
    HRESULT (STDMETHODCALLTYPE* put_ExternalLocationUri)(__x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions* This,
        __x_ABI_CWindows_CFoundation_CIUriRuntimeClass* value);
    HRESULT (STDMETHODCALLTYPE* get_StubPackageOption)(__x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions* This,
        enum __x_ABI_CWindows_CManagement_CDeployment_CStubPackageOption* value);
    HRESULT (STDMETHODCALLTYPE* put_StubPackageOption)(__x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions* This,
        enum __x_ABI_CWindows_CManagement_CDeployment_CStubPackageOption value);
    HRESULT (STDMETHODCALLTYPE* get_DeveloperMode)(__x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions* This,
        boolean* value);
    HRESULT (STDMETHODCALLTYPE* put_DeveloperMode)(__x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions* This,
        boolean value);
    HRESULT (STDMETHODCALLTYPE* get_ForceAppShutdown)(__x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions* This,
        boolean* value);
    HRESULT (STDMETHODCALLTYPE* put_ForceAppShutdown)(__x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions* This,
        boolean value);
    HRESULT (STDMETHODCALLTYPE* get_ForceTargetAppShutdown)(__x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions* This,
        boolean* value);
    HRESULT (STDMETHODCALLTYPE* put_ForceTargetAppShutdown)(__x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions* This,
        boolean value);
    HRESULT (STDMETHODCALLTYPE* get_ForceUpdateFromAnyVersion)(__x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions* This,
        boolean* value);
    HRESULT (STDMETHODCALLTYPE* put_ForceUpdateFromAnyVersion)(__x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions* This,
        boolean value);
    HRESULT (STDMETHODCALLTYPE* get_InstallAllResources)(__x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions* This,
        boolean* value);
    HRESULT (STDMETHODCALLTYPE* put_InstallAllResources)(__x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions* This,
        boolean value);
    HRESULT (STDMETHODCALLTYPE* get_RequiredContentGroupOnly)(__x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions* This,
        boolean* value);
    HRESULT (STDMETHODCALLTYPE* put_RequiredContentGroupOnly)(__x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions* This,
        boolean value);
    HRESULT (STDMETHODCALLTYPE* get_RetainFilesOnFailure)(__x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions* This,
        boolean* value);
    HRESULT (STDMETHODCALLTYPE* put_RetainFilesOnFailure)(__x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions* This,
        boolean value);
    HRESULT (STDMETHODCALLTYPE* get_StageInPlace)(__x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions* This,
        boolean* value);
    HRESULT (STDMETHODCALLTYPE* put_StageInPlace)(__x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions* This,
        boolean value);
    HRESULT (STDMETHODCALLTYPE* get_AllowUnsigned)(__x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions* This,
        boolean* value);
    HRESULT (STDMETHODCALLTYPE* put_AllowUnsigned)(__x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions* This,
        boolean value);
    HRESULT (STDMETHODCALLTYPE* get_DeferRegistrationWhenPackagesAreInUse)(__x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions* This,
        boolean* value);
    HRESULT (STDMETHODCALLTYPE* put_DeferRegistrationWhenPackagesAreInUse)(__x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions* This,
        boolean value);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptionsVtbl;

interface __x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptionsVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions_get_DependencyPackageUris(This, value) \
    ((This)->lpVtbl->get_DependencyPackageUris(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions_get_TargetVolume(This, value) \
    ((This)->lpVtbl->get_TargetVolume(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions_put_TargetVolume(This, value) \
    ((This)->lpVtbl->put_TargetVolume(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions_get_OptionalPackageFamilyNames(This, value) \
    ((This)->lpVtbl->get_OptionalPackageFamilyNames(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions_get_OptionalPackageUris(This, value) \
    ((This)->lpVtbl->get_OptionalPackageUris(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions_get_RelatedPackageUris(This, value) \
    ((This)->lpVtbl->get_RelatedPackageUris(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions_get_ExternalLocationUri(This, value) \
    ((This)->lpVtbl->get_ExternalLocationUri(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions_put_ExternalLocationUri(This, value) \
    ((This)->lpVtbl->put_ExternalLocationUri(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions_get_StubPackageOption(This, value) \
    ((This)->lpVtbl->get_StubPackageOption(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions_put_StubPackageOption(This, value) \
    ((This)->lpVtbl->put_StubPackageOption(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions_get_DeveloperMode(This, value) \
    ((This)->lpVtbl->get_DeveloperMode(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions_put_DeveloperMode(This, value) \
    ((This)->lpVtbl->put_DeveloperMode(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions_get_ForceAppShutdown(This, value) \
    ((This)->lpVtbl->get_ForceAppShutdown(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions_put_ForceAppShutdown(This, value) \
    ((This)->lpVtbl->put_ForceAppShutdown(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions_get_ForceTargetAppShutdown(This, value) \
    ((This)->lpVtbl->get_ForceTargetAppShutdown(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions_put_ForceTargetAppShutdown(This, value) \
    ((This)->lpVtbl->put_ForceTargetAppShutdown(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions_get_ForceUpdateFromAnyVersion(This, value) \
    ((This)->lpVtbl->get_ForceUpdateFromAnyVersion(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions_put_ForceUpdateFromAnyVersion(This, value) \
    ((This)->lpVtbl->put_ForceUpdateFromAnyVersion(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions_get_InstallAllResources(This, value) \
    ((This)->lpVtbl->get_InstallAllResources(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions_put_InstallAllResources(This, value) \
    ((This)->lpVtbl->put_InstallAllResources(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions_get_RequiredContentGroupOnly(This, value) \
    ((This)->lpVtbl->get_RequiredContentGroupOnly(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions_put_RequiredContentGroupOnly(This, value) \
    ((This)->lpVtbl->put_RequiredContentGroupOnly(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions_get_RetainFilesOnFailure(This, value) \
    ((This)->lpVtbl->get_RetainFilesOnFailure(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions_put_RetainFilesOnFailure(This, value) \
    ((This)->lpVtbl->put_RetainFilesOnFailure(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions_get_StageInPlace(This, value) \
    ((This)->lpVtbl->get_StageInPlace(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions_put_StageInPlace(This, value) \
    ((This)->lpVtbl->put_StageInPlace(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions_get_AllowUnsigned(This, value) \
    ((This)->lpVtbl->get_AllowUnsigned(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions_put_AllowUnsigned(This, value) \
    ((This)->lpVtbl->put_AllowUnsigned(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions_get_DeferRegistrationWhenPackagesAreInUse(This, value) \
    ((This)->lpVtbl->get_DeferRegistrationWhenPackagesAreInUse(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions_put_DeferRegistrationWhenPackagesAreInUse(This, value) \
    ((This)->lpVtbl->put_DeferRegistrationWhenPackagesAreInUse(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions;
#endif /* !defined(____x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xa0000

/*
 *
 * Interface Windows.Management.Deployment.IDeploymentResult
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Deployment.DeploymentResult
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CDeployment_CIDeploymentResult_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CDeployment_CIDeploymentResult_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Deployment_IDeploymentResult[] = L"Windows.Management.Deployment.IDeploymentResult";
typedef struct __x_ABI_CWindows_CManagement_CDeployment_CIDeploymentResultVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CDeployment_CIDeploymentResult* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CDeployment_CIDeploymentResult* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CDeployment_CIDeploymentResult* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CDeployment_CIDeploymentResult* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CDeployment_CIDeploymentResult* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CDeployment_CIDeploymentResult* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_ErrorText)(__x_ABI_CWindows_CManagement_CDeployment_CIDeploymentResult* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* get_ActivityId)(__x_ABI_CWindows_CManagement_CDeployment_CIDeploymentResult* This,
        GUID* value);
    HRESULT (STDMETHODCALLTYPE* get_ExtendedErrorCode)(__x_ABI_CWindows_CManagement_CDeployment_CIDeploymentResult* This,
        HRESULT* value);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CDeployment_CIDeploymentResultVtbl;

interface __x_ABI_CWindows_CManagement_CDeployment_CIDeploymentResult
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CDeployment_CIDeploymentResultVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CDeployment_CIDeploymentResult_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CDeployment_CIDeploymentResult_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CDeployment_CIDeploymentResult_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CDeployment_CIDeploymentResult_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CDeployment_CIDeploymentResult_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CDeployment_CIDeploymentResult_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CDeployment_CIDeploymentResult_get_ErrorText(This, value) \
    ((This)->lpVtbl->get_ErrorText(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIDeploymentResult_get_ActivityId(This, value) \
    ((This)->lpVtbl->get_ActivityId(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIDeploymentResult_get_ExtendedErrorCode(This, value) \
    ((This)->lpVtbl->get_ExtendedErrorCode(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CDeployment_CIDeploymentResult;
#endif /* !defined(____x_ABI_CWindows_CManagement_CDeployment_CIDeploymentResult_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Deployment.IDeploymentResult2
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 4.0
 *
 * Interface is a part of the implementation of type Windows.Management.Deployment.DeploymentResult
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x40000
#if !defined(____x_ABI_CWindows_CManagement_CDeployment_CIDeploymentResult2_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CDeployment_CIDeploymentResult2_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Deployment_IDeploymentResult2[] = L"Windows.Management.Deployment.IDeploymentResult2";
typedef struct __x_ABI_CWindows_CManagement_CDeployment_CIDeploymentResult2Vtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CDeployment_CIDeploymentResult2* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CDeployment_CIDeploymentResult2* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CDeployment_CIDeploymentResult2* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CDeployment_CIDeploymentResult2* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CDeployment_CIDeploymentResult2* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CDeployment_CIDeploymentResult2* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_IsRegistered)(__x_ABI_CWindows_CManagement_CDeployment_CIDeploymentResult2* This,
        boolean* value);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CDeployment_CIDeploymentResult2Vtbl;

interface __x_ABI_CWindows_CManagement_CDeployment_CIDeploymentResult2
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CDeployment_CIDeploymentResult2Vtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CDeployment_CIDeploymentResult2_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CDeployment_CIDeploymentResult2_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CDeployment_CIDeploymentResult2_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CDeployment_CIDeploymentResult2_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CDeployment_CIDeploymentResult2_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CDeployment_CIDeploymentResult2_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CDeployment_CIDeploymentResult2_get_IsRegistered(This, value) \
    ((This)->lpVtbl->get_IsRegistered(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CDeployment_CIDeploymentResult2;
#endif /* !defined(____x_ABI_CWindows_CManagement_CDeployment_CIDeploymentResult2_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x40000

/*
 *
 * Interface Windows.Management.Deployment.IPackageManager
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Deployment.PackageManager
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Deployment_IPackageManager[] = L"Windows.Management.Deployment.IPackageManager";
typedef struct __x_ABI_CWindows_CManagement_CDeployment_CIPackageManagerVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* AddPackageAsync)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager* This,
        __x_ABI_CWindows_CFoundation_CIUriRuntimeClass* packageUri,
        __FIIterable_1_Windows__CFoundation__CUri* dependencyPackageUris,
        enum __x_ABI_CWindows_CManagement_CDeployment_CDeploymentOptions deploymentOptions,
        __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress** deploymentOperation);
    HRESULT (STDMETHODCALLTYPE* UpdatePackageAsync)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager* This,
        __x_ABI_CWindows_CFoundation_CIUriRuntimeClass* packageUri,
        __FIIterable_1_Windows__CFoundation__CUri* dependencyPackageUris,
        enum __x_ABI_CWindows_CManagement_CDeployment_CDeploymentOptions deploymentOptions,
        __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress** deploymentOperation);
    HRESULT (STDMETHODCALLTYPE* RemovePackageAsync)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager* This,
        HSTRING packageFullName,
        __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress** deploymentOperation);
    HRESULT (STDMETHODCALLTYPE* StagePackageAsync)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager* This,
        __x_ABI_CWindows_CFoundation_CIUriRuntimeClass* packageUri,
        __FIIterable_1_Windows__CFoundation__CUri* dependencyPackageUris,
        __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress** deploymentOperation);
    HRESULT (STDMETHODCALLTYPE* RegisterPackageAsync)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager* This,
        __x_ABI_CWindows_CFoundation_CIUriRuntimeClass* manifestUri,
        __FIIterable_1_Windows__CFoundation__CUri* dependencyPackageUris,
        enum __x_ABI_CWindows_CManagement_CDeployment_CDeploymentOptions deploymentOptions,
        __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress** deploymentOperation);
    HRESULT (STDMETHODCALLTYPE* FindPackages)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager* This,
        __FIIterable_1_Windows__CApplicationModel__CPackage** packageCollection);
    HRESULT (STDMETHODCALLTYPE* FindPackagesByUserSecurityId)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager* This,
        HSTRING userSecurityId,
        __FIIterable_1_Windows__CApplicationModel__CPackage** packageCollection);
    HRESULT (STDMETHODCALLTYPE* FindPackagesByNamePublisher)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager* This,
        HSTRING packageName,
        HSTRING packagePublisher,
        __FIIterable_1_Windows__CApplicationModel__CPackage** packageCollection);
    HRESULT (STDMETHODCALLTYPE* FindPackagesByUserSecurityIdNamePublisher)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager* This,
        HSTRING userSecurityId,
        HSTRING packageName,
        HSTRING packagePublisher,
        __FIIterable_1_Windows__CApplicationModel__CPackage** packageCollection);
    HRESULT (STDMETHODCALLTYPE* FindUsers)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager* This,
        HSTRING packageFullName,
        __FIIterable_1_Windows__CManagement__CDeployment__CPackageUserInformation** users);
    HRESULT (STDMETHODCALLTYPE* SetPackageState)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager* This,
        HSTRING packageFullName,
        enum __x_ABI_CWindows_CManagement_CDeployment_CPackageState packageState);
    HRESULT (STDMETHODCALLTYPE* FindPackageByPackageFullName)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager* This,
        HSTRING packageFullName,
        __x_ABI_CWindows_CApplicationModel_CIPackage** packageInformation);
    HRESULT (STDMETHODCALLTYPE* CleanupPackageForUserAsync)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager* This,
        HSTRING packageName,
        HSTRING userSecurityId,
        __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress** deploymentOperation);
    HRESULT (STDMETHODCALLTYPE* FindPackagesByPackageFamilyName)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager* This,
        HSTRING packageFamilyName,
        __FIIterable_1_Windows__CApplicationModel__CPackage** packageCollection);
    HRESULT (STDMETHODCALLTYPE* FindPackagesByUserSecurityIdPackageFamilyName)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager* This,
        HSTRING userSecurityId,
        HSTRING packageFamilyName,
        __FIIterable_1_Windows__CApplicationModel__CPackage** packageCollection);
    HRESULT (STDMETHODCALLTYPE* FindPackageByUserSecurityIdPackageFullName)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager* This,
        HSTRING userSecurityId,
        HSTRING packageFullName,
        __x_ABI_CWindows_CApplicationModel_CIPackage** packageInformation);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CDeployment_CIPackageManagerVtbl;

interface __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CDeployment_CIPackageManagerVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager_AddPackageAsync(This, packageUri, dependencyPackageUris, deploymentOptions, deploymentOperation) \
    ((This)->lpVtbl->AddPackageAsync(This, packageUri, dependencyPackageUris, deploymentOptions, deploymentOperation))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager_UpdatePackageAsync(This, packageUri, dependencyPackageUris, deploymentOptions, deploymentOperation) \
    ((This)->lpVtbl->UpdatePackageAsync(This, packageUri, dependencyPackageUris, deploymentOptions, deploymentOperation))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager_RemovePackageAsync(This, packageFullName, deploymentOperation) \
    ((This)->lpVtbl->RemovePackageAsync(This, packageFullName, deploymentOperation))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager_StagePackageAsync(This, packageUri, dependencyPackageUris, deploymentOperation) \
    ((This)->lpVtbl->StagePackageAsync(This, packageUri, dependencyPackageUris, deploymentOperation))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager_RegisterPackageAsync(This, manifestUri, dependencyPackageUris, deploymentOptions, deploymentOperation) \
    ((This)->lpVtbl->RegisterPackageAsync(This, manifestUri, dependencyPackageUris, deploymentOptions, deploymentOperation))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager_FindPackages(This, packageCollection) \
    ((This)->lpVtbl->FindPackages(This, packageCollection))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager_FindPackagesByUserSecurityId(This, userSecurityId, packageCollection) \
    ((This)->lpVtbl->FindPackagesByUserSecurityId(This, userSecurityId, packageCollection))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager_FindPackagesByNamePublisher(This, packageName, packagePublisher, packageCollection) \
    ((This)->lpVtbl->FindPackagesByNamePublisher(This, packageName, packagePublisher, packageCollection))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager_FindPackagesByUserSecurityIdNamePublisher(This, userSecurityId, packageName, packagePublisher, packageCollection) \
    ((This)->lpVtbl->FindPackagesByUserSecurityIdNamePublisher(This, userSecurityId, packageName, packagePublisher, packageCollection))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager_FindUsers(This, packageFullName, users) \
    ((This)->lpVtbl->FindUsers(This, packageFullName, users))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager_SetPackageState(This, packageFullName, packageState) \
    ((This)->lpVtbl->SetPackageState(This, packageFullName, packageState))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager_FindPackageByPackageFullName(This, packageFullName, packageInformation) \
    ((This)->lpVtbl->FindPackageByPackageFullName(This, packageFullName, packageInformation))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager_CleanupPackageForUserAsync(This, packageName, userSecurityId, deploymentOperation) \
    ((This)->lpVtbl->CleanupPackageForUserAsync(This, packageName, userSecurityId, deploymentOperation))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager_FindPackagesByPackageFamilyName(This, packageFamilyName, packageCollection) \
    ((This)->lpVtbl->FindPackagesByPackageFamilyName(This, packageFamilyName, packageCollection))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager_FindPackagesByUserSecurityIdPackageFamilyName(This, userSecurityId, packageFamilyName, packageCollection) \
    ((This)->lpVtbl->FindPackagesByUserSecurityIdPackageFamilyName(This, userSecurityId, packageFamilyName, packageCollection))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager_FindPackageByUserSecurityIdPackageFullName(This, userSecurityId, packageFullName, packageInformation) \
    ((This)->lpVtbl->FindPackageByUserSecurityIdPackageFullName(This, userSecurityId, packageFullName, packageInformation))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CDeployment_CIPackageManager;
#endif /* !defined(____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Deployment.IPackageManager2
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Deployment.PackageManager
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager2_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager2_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Deployment_IPackageManager2[] = L"Windows.Management.Deployment.IPackageManager2";
typedef struct __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager2Vtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager2* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager2* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager2* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager2* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager2* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager2* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* RemovePackageWithOptionsAsync)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager2* This,
        HSTRING packageFullName,
        enum __x_ABI_CWindows_CManagement_CDeployment_CRemovalOptions removalOptions,
        __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress** deploymentOperation);
    HRESULT (STDMETHODCALLTYPE* StagePackageWithOptionsAsync)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager2* This,
        __x_ABI_CWindows_CFoundation_CIUriRuntimeClass* packageUri,
        __FIIterable_1_Windows__CFoundation__CUri* dependencyPackageUris,
        enum __x_ABI_CWindows_CManagement_CDeployment_CDeploymentOptions deploymentOptions,
        __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress** deploymentOperation);
    HRESULT (STDMETHODCALLTYPE* RegisterPackageByFullNameAsync)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager2* This,
        HSTRING mainPackageFullName,
        __FIIterable_1_HSTRING* dependencyPackageFullNames,
        enum __x_ABI_CWindows_CManagement_CDeployment_CDeploymentOptions deploymentOptions,
        __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress** deploymentOperation);
    HRESULT (STDMETHODCALLTYPE* FindPackagesWithPackageTypes)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager2* This,
        enum __x_ABI_CWindows_CManagement_CDeployment_CPackageTypes packageTypes,
        __FIIterable_1_Windows__CApplicationModel__CPackage** packageCollection);
    HRESULT (STDMETHODCALLTYPE* FindPackagesByUserSecurityIdWithPackageTypes)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager2* This,
        HSTRING userSecurityId,
        enum __x_ABI_CWindows_CManagement_CDeployment_CPackageTypes packageTypes,
        __FIIterable_1_Windows__CApplicationModel__CPackage** packageCollection);
    HRESULT (STDMETHODCALLTYPE* FindPackagesByNamePublisherWithPackageTypes)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager2* This,
        HSTRING packageName,
        HSTRING packagePublisher,
        enum __x_ABI_CWindows_CManagement_CDeployment_CPackageTypes packageTypes,
        __FIIterable_1_Windows__CApplicationModel__CPackage** packageCollection);
    HRESULT (STDMETHODCALLTYPE* FindPackagesByUserSecurityIdNamePublisherWithPackageTypes)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager2* This,
        HSTRING userSecurityId,
        HSTRING packageName,
        HSTRING packagePublisher,
        enum __x_ABI_CWindows_CManagement_CDeployment_CPackageTypes packageTypes,
        __FIIterable_1_Windows__CApplicationModel__CPackage** packageCollection);
    HRESULT (STDMETHODCALLTYPE* FindPackagesByPackageFamilyNameWithPackageTypes)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager2* This,
        HSTRING packageFamilyName,
        enum __x_ABI_CWindows_CManagement_CDeployment_CPackageTypes packageTypes,
        __FIIterable_1_Windows__CApplicationModel__CPackage** packageCollection);
    HRESULT (STDMETHODCALLTYPE* FindPackagesByUserSecurityIdPackageFamilyNameWithPackageTypes)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager2* This,
        HSTRING userSecurityId,
        HSTRING packageFamilyName,
        enum __x_ABI_CWindows_CManagement_CDeployment_CPackageTypes packageTypes,
        __FIIterable_1_Windows__CApplicationModel__CPackage** packageCollection);
    HRESULT (STDMETHODCALLTYPE* StageUserDataAsync)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager2* This,
        HSTRING packageFullName,
        __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress** deploymentOperation);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager2Vtbl;

interface __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager2
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager2Vtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager2_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager2_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager2_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager2_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager2_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager2_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager2_RemovePackageWithOptionsAsync(This, packageFullName, removalOptions, deploymentOperation) \
    ((This)->lpVtbl->RemovePackageWithOptionsAsync(This, packageFullName, removalOptions, deploymentOperation))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager2_StagePackageWithOptionsAsync(This, packageUri, dependencyPackageUris, deploymentOptions, deploymentOperation) \
    ((This)->lpVtbl->StagePackageWithOptionsAsync(This, packageUri, dependencyPackageUris, deploymentOptions, deploymentOperation))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager2_RegisterPackageByFullNameAsync(This, mainPackageFullName, dependencyPackageFullNames, deploymentOptions, deploymentOperation) \
    ((This)->lpVtbl->RegisterPackageByFullNameAsync(This, mainPackageFullName, dependencyPackageFullNames, deploymentOptions, deploymentOperation))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager2_FindPackagesWithPackageTypes(This, packageTypes, packageCollection) \
    ((This)->lpVtbl->FindPackagesWithPackageTypes(This, packageTypes, packageCollection))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager2_FindPackagesByUserSecurityIdWithPackageTypes(This, userSecurityId, packageTypes, packageCollection) \
    ((This)->lpVtbl->FindPackagesByUserSecurityIdWithPackageTypes(This, userSecurityId, packageTypes, packageCollection))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager2_FindPackagesByNamePublisherWithPackageTypes(This, packageName, packagePublisher, packageTypes, packageCollection) \
    ((This)->lpVtbl->FindPackagesByNamePublisherWithPackageTypes(This, packageName, packagePublisher, packageTypes, packageCollection))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager2_FindPackagesByUserSecurityIdNamePublisherWithPackageTypes(This, userSecurityId, packageName, packagePublisher, packageTypes, packageCollection) \
    ((This)->lpVtbl->FindPackagesByUserSecurityIdNamePublisherWithPackageTypes(This, userSecurityId, packageName, packagePublisher, packageTypes, packageCollection))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager2_FindPackagesByPackageFamilyNameWithPackageTypes(This, packageFamilyName, packageTypes, packageCollection) \
    ((This)->lpVtbl->FindPackagesByPackageFamilyNameWithPackageTypes(This, packageFamilyName, packageTypes, packageCollection))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager2_FindPackagesByUserSecurityIdPackageFamilyNameWithPackageTypes(This, userSecurityId, packageFamilyName, packageTypes, packageCollection) \
    ((This)->lpVtbl->FindPackagesByUserSecurityIdPackageFamilyNameWithPackageTypes(This, userSecurityId, packageFamilyName, packageTypes, packageCollection))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager2_StageUserDataAsync(This, packageFullName, deploymentOperation) \
    ((This)->lpVtbl->StageUserDataAsync(This, packageFullName, deploymentOperation))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CDeployment_CIPackageManager2;
#endif /* !defined(____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager2_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Deployment.IPackageManager3
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Deployment.PackageManager
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager3_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager3_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Deployment_IPackageManager3[] = L"Windows.Management.Deployment.IPackageManager3";
typedef struct __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager3Vtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager3* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager3* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager3* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager3* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager3* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager3* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* AddPackageVolumeAsync)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager3* This,
        HSTRING packageStorePath,
        __FIAsyncOperation_1_Windows__CManagement__CDeployment__CPackageVolume** packageVolume);
    HRESULT (STDMETHODCALLTYPE* AddPackageToVolumeAsync)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager3* This,
        __x_ABI_CWindows_CFoundation_CIUriRuntimeClass* packageUri,
        __FIIterable_1_Windows__CFoundation__CUri* dependencyPackageUris,
        enum __x_ABI_CWindows_CManagement_CDeployment_CDeploymentOptions deploymentOptions,
        __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume* targetVolume,
        __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress** deploymentOperation);
    HRESULT (STDMETHODCALLTYPE* ClearPackageStatus)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager3* This,
        HSTRING packageFullName,
        enum __x_ABI_CWindows_CManagement_CDeployment_CPackageStatus status);
    HRESULT (STDMETHODCALLTYPE* RegisterPackageWithAppDataVolumeAsync)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager3* This,
        __x_ABI_CWindows_CFoundation_CIUriRuntimeClass* manifestUri,
        __FIIterable_1_Windows__CFoundation__CUri* dependencyPackageUris,
        enum __x_ABI_CWindows_CManagement_CDeployment_CDeploymentOptions deploymentOptions,
        __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume* appDataVolume,
        __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress** deploymentOperation);
    HRESULT (STDMETHODCALLTYPE* FindPackageVolumeByName)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager3* This,
        HSTRING volumeName,
        __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume** volume);
    HRESULT (STDMETHODCALLTYPE* FindPackageVolumes)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager3* This,
        __FIIterable_1_Windows__CManagement__CDeployment__CPackageVolume** volumeCollection);
    HRESULT (STDMETHODCALLTYPE* GetDefaultPackageVolume)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager3* This,
        __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume** volume);
    HRESULT (STDMETHODCALLTYPE* MovePackageToVolumeAsync)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager3* This,
        HSTRING packageFullName,
        enum __x_ABI_CWindows_CManagement_CDeployment_CDeploymentOptions deploymentOptions,
        __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume* targetVolume,
        __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress** deploymentOperation);
    HRESULT (STDMETHODCALLTYPE* RemovePackageVolumeAsync)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager3* This,
        __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume* volume,
        __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress** deploymentOperation);
    HRESULT (STDMETHODCALLTYPE* SetDefaultPackageVolume)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager3* This,
        __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume* volume);
    HRESULT (STDMETHODCALLTYPE* SetPackageStatus)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager3* This,
        HSTRING packageFullName,
        enum __x_ABI_CWindows_CManagement_CDeployment_CPackageStatus status);
    HRESULT (STDMETHODCALLTYPE* SetPackageVolumeOfflineAsync)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager3* This,
        __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume* packageVolume,
        __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress** deploymentOperation);
    HRESULT (STDMETHODCALLTYPE* SetPackageVolumeOnlineAsync)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager3* This,
        __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume* packageVolume,
        __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress** deploymentOperation);
    HRESULT (STDMETHODCALLTYPE* StagePackageToVolumeAsync)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager3* This,
        __x_ABI_CWindows_CFoundation_CIUriRuntimeClass* packageUri,
        __FIIterable_1_Windows__CFoundation__CUri* dependencyPackageUris,
        enum __x_ABI_CWindows_CManagement_CDeployment_CDeploymentOptions deploymentOptions,
        __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume* targetVolume,
        __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress** deploymentOperation);
    HRESULT (STDMETHODCALLTYPE* StageUserDataWithOptionsAsync)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager3* This,
        HSTRING packageFullName,
        enum __x_ABI_CWindows_CManagement_CDeployment_CDeploymentOptions deploymentOptions,
        __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress** deploymentOperation);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager3Vtbl;

interface __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager3
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager3Vtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager3_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager3_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager3_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager3_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager3_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager3_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager3_AddPackageVolumeAsync(This, packageStorePath, packageVolume) \
    ((This)->lpVtbl->AddPackageVolumeAsync(This, packageStorePath, packageVolume))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager3_AddPackageToVolumeAsync(This, packageUri, dependencyPackageUris, deploymentOptions, targetVolume, deploymentOperation) \
    ((This)->lpVtbl->AddPackageToVolumeAsync(This, packageUri, dependencyPackageUris, deploymentOptions, targetVolume, deploymentOperation))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager3_ClearPackageStatus(This, packageFullName, status) \
    ((This)->lpVtbl->ClearPackageStatus(This, packageFullName, status))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager3_RegisterPackageWithAppDataVolumeAsync(This, manifestUri, dependencyPackageUris, deploymentOptions, appDataVolume, deploymentOperation) \
    ((This)->lpVtbl->RegisterPackageWithAppDataVolumeAsync(This, manifestUri, dependencyPackageUris, deploymentOptions, appDataVolume, deploymentOperation))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager3_FindPackageVolumeByName(This, volumeName, volume) \
    ((This)->lpVtbl->FindPackageVolumeByName(This, volumeName, volume))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager3_FindPackageVolumes(This, volumeCollection) \
    ((This)->lpVtbl->FindPackageVolumes(This, volumeCollection))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager3_GetDefaultPackageVolume(This, volume) \
    ((This)->lpVtbl->GetDefaultPackageVolume(This, volume))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager3_MovePackageToVolumeAsync(This, packageFullName, deploymentOptions, targetVolume, deploymentOperation) \
    ((This)->lpVtbl->MovePackageToVolumeAsync(This, packageFullName, deploymentOptions, targetVolume, deploymentOperation))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager3_RemovePackageVolumeAsync(This, volume, deploymentOperation) \
    ((This)->lpVtbl->RemovePackageVolumeAsync(This, volume, deploymentOperation))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager3_SetDefaultPackageVolume(This, volume) \
    ((This)->lpVtbl->SetDefaultPackageVolume(This, volume))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager3_SetPackageStatus(This, packageFullName, status) \
    ((This)->lpVtbl->SetPackageStatus(This, packageFullName, status))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager3_SetPackageVolumeOfflineAsync(This, packageVolume, deploymentOperation) \
    ((This)->lpVtbl->SetPackageVolumeOfflineAsync(This, packageVolume, deploymentOperation))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager3_SetPackageVolumeOnlineAsync(This, packageVolume, deploymentOperation) \
    ((This)->lpVtbl->SetPackageVolumeOnlineAsync(This, packageVolume, deploymentOperation))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager3_StagePackageToVolumeAsync(This, packageUri, dependencyPackageUris, deploymentOptions, targetVolume, deploymentOperation) \
    ((This)->lpVtbl->StagePackageToVolumeAsync(This, packageUri, dependencyPackageUris, deploymentOptions, targetVolume, deploymentOperation))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager3_StageUserDataWithOptionsAsync(This, packageFullName, deploymentOptions, deploymentOperation) \
    ((This)->lpVtbl->StageUserDataWithOptionsAsync(This, packageFullName, deploymentOptions, deploymentOperation))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CDeployment_CIPackageManager3;
#endif /* !defined(____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager3_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Deployment.IPackageManager4
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 3.0
 *
 * Interface is a part of the implementation of type Windows.Management.Deployment.PackageManager
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x30000
#if !defined(____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager4_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager4_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Deployment_IPackageManager4[] = L"Windows.Management.Deployment.IPackageManager4";
typedef struct __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager4Vtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager4* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager4* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager4* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager4* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager4* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager4* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* GetPackageVolumesAsync)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager4* This,
        __FIAsyncOperation_1___FIVectorView_1_Windows__CManagement__CDeployment__CPackageVolume** operation);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager4Vtbl;

interface __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager4
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager4Vtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager4_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager4_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager4_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager4_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager4_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager4_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager4_GetPackageVolumesAsync(This, operation) \
    ((This)->lpVtbl->GetPackageVolumesAsync(This, operation))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CDeployment_CIPackageManager4;
#endif /* !defined(____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager4_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x30000

/*
 *
 * Interface Windows.Management.Deployment.IPackageManager5
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 4.0
 *
 * Interface is a part of the implementation of type Windows.Management.Deployment.PackageManager
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x40000
#if !defined(____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager5_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager5_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Deployment_IPackageManager5[] = L"Windows.Management.Deployment.IPackageManager5";
typedef struct __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager5Vtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager5* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager5* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager5* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager5* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager5* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager5* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* AddPackageToVolumeAndOptionalPackagesAsync)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager5* This,
        __x_ABI_CWindows_CFoundation_CIUriRuntimeClass* packageUri,
        __FIIterable_1_Windows__CFoundation__CUri* dependencyPackageUris,
        enum __x_ABI_CWindows_CManagement_CDeployment_CDeploymentOptions deploymentOptions,
        __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume* targetVolume,
        __FIIterable_1_HSTRING* optionalPackageFamilyNames,
        __FIIterable_1_Windows__CFoundation__CUri* externalPackageUris,
        __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress** deploymentOperation);
    HRESULT (STDMETHODCALLTYPE* StagePackageToVolumeAndOptionalPackagesAsync)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager5* This,
        __x_ABI_CWindows_CFoundation_CIUriRuntimeClass* packageUri,
        __FIIterable_1_Windows__CFoundation__CUri* dependencyPackageUris,
        enum __x_ABI_CWindows_CManagement_CDeployment_CDeploymentOptions deploymentOptions,
        __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume* targetVolume,
        __FIIterable_1_HSTRING* optionalPackageFamilyNames,
        __FIIterable_1_Windows__CFoundation__CUri* externalPackageUris,
        __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress** deploymentOperation);
    HRESULT (STDMETHODCALLTYPE* RegisterPackageByFamilyNameAndOptionalPackagesAsync)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager5* This,
        HSTRING mainPackageFamilyName,
        __FIIterable_1_HSTRING* dependencyPackageFamilyNames,
        enum __x_ABI_CWindows_CManagement_CDeployment_CDeploymentOptions deploymentOptions,
        __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume* appDataVolume,
        __FIIterable_1_HSTRING* optionalPackageFamilyNames,
        __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress** deploymentOperation);
    HRESULT (STDMETHODCALLTYPE* get_DebugSettings)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager5* This,
        __x_ABI_CWindows_CManagement_CDeployment_CIPackageManagerDebugSettings** value);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager5Vtbl;

interface __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager5
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager5Vtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager5_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager5_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager5_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager5_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager5_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager5_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager5_AddPackageToVolumeAndOptionalPackagesAsync(This, packageUri, dependencyPackageUris, deploymentOptions, targetVolume, optionalPackageFamilyNames, externalPackageUris, deploymentOperation) \
    ((This)->lpVtbl->AddPackageToVolumeAndOptionalPackagesAsync(This, packageUri, dependencyPackageUris, deploymentOptions, targetVolume, optionalPackageFamilyNames, externalPackageUris, deploymentOperation))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager5_StagePackageToVolumeAndOptionalPackagesAsync(This, packageUri, dependencyPackageUris, deploymentOptions, targetVolume, optionalPackageFamilyNames, externalPackageUris, deploymentOperation) \
    ((This)->lpVtbl->StagePackageToVolumeAndOptionalPackagesAsync(This, packageUri, dependencyPackageUris, deploymentOptions, targetVolume, optionalPackageFamilyNames, externalPackageUris, deploymentOperation))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager5_RegisterPackageByFamilyNameAndOptionalPackagesAsync(This, mainPackageFamilyName, dependencyPackageFamilyNames, deploymentOptions, appDataVolume, optionalPackageFamilyNames, deploymentOperation) \
    ((This)->lpVtbl->RegisterPackageByFamilyNameAndOptionalPackagesAsync(This, mainPackageFamilyName, dependencyPackageFamilyNames, deploymentOptions, appDataVolume, optionalPackageFamilyNames, deploymentOperation))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager5_get_DebugSettings(This, value) \
    ((This)->lpVtbl->get_DebugSettings(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CDeployment_CIPackageManager5;
#endif /* !defined(____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager5_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x40000

/*
 *
 * Interface Windows.Management.Deployment.IPackageManager6
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 * Interface is a part of the implementation of type Windows.Management.Deployment.PackageManager
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager6_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager6_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Deployment_IPackageManager6[] = L"Windows.Management.Deployment.IPackageManager6";
typedef struct __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager6Vtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager6* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager6* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager6* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager6* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager6* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager6* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* ProvisionPackageForAllUsersAsync)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager6* This,
        HSTRING packageFamilyName,
        __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress** operation);
    HRESULT (STDMETHODCALLTYPE* AddPackageByAppInstallerFileAsync)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager6* This,
        __x_ABI_CWindows_CFoundation_CIUriRuntimeClass* appInstallerFileUri,
        enum __x_ABI_CWindows_CManagement_CDeployment_CAddPackageByAppInstallerOptions options,
        __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume* targetVolume,
        __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress** operation);
    HRESULT (STDMETHODCALLTYPE* RequestAddPackageByAppInstallerFileAsync)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager6* This,
        __x_ABI_CWindows_CFoundation_CIUriRuntimeClass* appInstallerFileUri,
        enum __x_ABI_CWindows_CManagement_CDeployment_CAddPackageByAppInstallerOptions options,
        __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume* targetVolume,
        __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress** operation);
    HRESULT (STDMETHODCALLTYPE* AddPackageToVolumeAndRelatedSetAsync)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager6* This,
        __x_ABI_CWindows_CFoundation_CIUriRuntimeClass* packageUri,
        __FIIterable_1_Windows__CFoundation__CUri* dependencyPackageUris,
        enum __x_ABI_CWindows_CManagement_CDeployment_CDeploymentOptions options,
        __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume* targetVolume,
        __FIIterable_1_HSTRING* optionalPackageFamilyNames,
        __FIIterable_1_Windows__CFoundation__CUri* packageUrisToInstall,
        __FIIterable_1_Windows__CFoundation__CUri* relatedPackageUris,
        __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress** operation);
    HRESULT (STDMETHODCALLTYPE* StagePackageToVolumeAndRelatedSetAsync)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager6* This,
        __x_ABI_CWindows_CFoundation_CIUriRuntimeClass* packageUri,
        __FIIterable_1_Windows__CFoundation__CUri* dependencyPackageUris,
        enum __x_ABI_CWindows_CManagement_CDeployment_CDeploymentOptions options,
        __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume* targetVolume,
        __FIIterable_1_HSTRING* optionalPackageFamilyNames,
        __FIIterable_1_Windows__CFoundation__CUri* packageUrisToInstall,
        __FIIterable_1_Windows__CFoundation__CUri* relatedPackageUris,
        __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress** operation);
    HRESULT (STDMETHODCALLTYPE* RequestAddPackageAsync)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager6* This,
        __x_ABI_CWindows_CFoundation_CIUriRuntimeClass* packageUri,
        __FIIterable_1_Windows__CFoundation__CUri* dependencyPackageUris,
        enum __x_ABI_CWindows_CManagement_CDeployment_CDeploymentOptions deploymentOptions,
        __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume* targetVolume,
        __FIIterable_1_HSTRING* optionalPackageFamilyNames,
        __FIIterable_1_Windows__CFoundation__CUri* relatedPackageUris,
        __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress** operation);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager6Vtbl;

interface __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager6
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager6Vtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager6_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager6_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager6_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager6_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager6_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager6_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager6_ProvisionPackageForAllUsersAsync(This, packageFamilyName, operation) \
    ((This)->lpVtbl->ProvisionPackageForAllUsersAsync(This, packageFamilyName, operation))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager6_AddPackageByAppInstallerFileAsync(This, appInstallerFileUri, options, targetVolume, operation) \
    ((This)->lpVtbl->AddPackageByAppInstallerFileAsync(This, appInstallerFileUri, options, targetVolume, operation))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager6_RequestAddPackageByAppInstallerFileAsync(This, appInstallerFileUri, options, targetVolume, operation) \
    ((This)->lpVtbl->RequestAddPackageByAppInstallerFileAsync(This, appInstallerFileUri, options, targetVolume, operation))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager6_AddPackageToVolumeAndRelatedSetAsync(This, packageUri, dependencyPackageUris, options, targetVolume, optionalPackageFamilyNames, packageUrisToInstall, relatedPackageUris, operation) \
    ((This)->lpVtbl->AddPackageToVolumeAndRelatedSetAsync(This, packageUri, dependencyPackageUris, options, targetVolume, optionalPackageFamilyNames, packageUrisToInstall, relatedPackageUris, operation))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager6_StagePackageToVolumeAndRelatedSetAsync(This, packageUri, dependencyPackageUris, options, targetVolume, optionalPackageFamilyNames, packageUrisToInstall, relatedPackageUris, operation) \
    ((This)->lpVtbl->StagePackageToVolumeAndRelatedSetAsync(This, packageUri, dependencyPackageUris, options, targetVolume, optionalPackageFamilyNames, packageUrisToInstall, relatedPackageUris, operation))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager6_RequestAddPackageAsync(This, packageUri, dependencyPackageUris, deploymentOptions, targetVolume, optionalPackageFamilyNames, relatedPackageUris, operation) \
    ((This)->lpVtbl->RequestAddPackageAsync(This, packageUri, dependencyPackageUris, deploymentOptions, targetVolume, optionalPackageFamilyNames, relatedPackageUris, operation))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CDeployment_CIPackageManager6;
#endif /* !defined(____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager6_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Interface Windows.Management.Deployment.IPackageManager7
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 6.0
 *
 * Interface is a part of the implementation of type Windows.Management.Deployment.PackageManager
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x60000
#if !defined(____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager7_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager7_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Deployment_IPackageManager7[] = L"Windows.Management.Deployment.IPackageManager7";
typedef struct __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager7Vtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager7* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager7* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager7* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager7* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager7* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager7* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* RequestAddPackageAndRelatedSetAsync)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager7* This,
        __x_ABI_CWindows_CFoundation_CIUriRuntimeClass* packageUri,
        __FIIterable_1_Windows__CFoundation__CUri* dependencyPackageUris,
        enum __x_ABI_CWindows_CManagement_CDeployment_CDeploymentOptions deploymentOptions,
        __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume* targetVolume,
        __FIIterable_1_HSTRING* optionalPackageFamilyNames,
        __FIIterable_1_Windows__CFoundation__CUri* relatedPackageUris,
        __FIIterable_1_Windows__CFoundation__CUri* packageUrisToInstall,
        __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress** operation);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager7Vtbl;

interface __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager7
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager7Vtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager7_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager7_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager7_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager7_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager7_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager7_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager7_RequestAddPackageAndRelatedSetAsync(This, packageUri, dependencyPackageUris, deploymentOptions, targetVolume, optionalPackageFamilyNames, relatedPackageUris, packageUrisToInstall, operation) \
    ((This)->lpVtbl->RequestAddPackageAndRelatedSetAsync(This, packageUri, dependencyPackageUris, deploymentOptions, targetVolume, optionalPackageFamilyNames, relatedPackageUris, packageUrisToInstall, operation))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CDeployment_CIPackageManager7;
#endif /* !defined(____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager7_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x60000

/*
 *
 * Interface Windows.Management.Deployment.IPackageManager8
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 7.0
 *
 * Interface is a part of the implementation of type Windows.Management.Deployment.PackageManager
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x70000
#if !defined(____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager8_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager8_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Deployment_IPackageManager8[] = L"Windows.Management.Deployment.IPackageManager8";
typedef struct __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager8Vtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager8* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager8* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager8* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager8* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager8* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager8* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* DeprovisionPackageForAllUsersAsync)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager8* This,
        HSTRING packageFamilyName,
        __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress** operation);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager8Vtbl;

interface __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager8
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager8Vtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager8_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager8_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager8_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager8_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager8_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager8_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager8_DeprovisionPackageForAllUsersAsync(This, packageFamilyName, operation) \
    ((This)->lpVtbl->DeprovisionPackageForAllUsersAsync(This, packageFamilyName, operation))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CDeployment_CIPackageManager8;
#endif /* !defined(____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager8_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x70000

/*
 *
 * Interface Windows.Management.Deployment.IPackageManager9
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 10.0
 *
 * Interface is a part of the implementation of type Windows.Management.Deployment.PackageManager
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xa0000
#if !defined(____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager9_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager9_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Deployment_IPackageManager9[] = L"Windows.Management.Deployment.IPackageManager9";
typedef struct __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager9Vtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager9* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager9* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager9* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager9* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager9* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager9* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* FindProvisionedPackages)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager9* This,
        __FIVector_1_Windows__CApplicationModel__CPackage** packageCollection);
    HRESULT (STDMETHODCALLTYPE* AddPackageByUriAsync)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager9* This,
        __x_ABI_CWindows_CFoundation_CIUriRuntimeClass* packageUri,
        __x_ABI_CWindows_CManagement_CDeployment_CIAddPackageOptions* options,
        __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress** deploymentOperation);
    HRESULT (STDMETHODCALLTYPE* StagePackageByUriAsync)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager9* This,
        __x_ABI_CWindows_CFoundation_CIUriRuntimeClass* packageUri,
        __x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptions* options,
        __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress** deploymentOperation);
    HRESULT (STDMETHODCALLTYPE* RegisterPackageByUriAsync)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager9* This,
        __x_ABI_CWindows_CFoundation_CIUriRuntimeClass* manifestUri,
        __x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptions* options,
        __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress** deploymentOperation);
    HRESULT (STDMETHODCALLTYPE* RegisterPackagesByFullNameAsync)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager9* This,
        __FIIterable_1_HSTRING* packageFullNames,
        __x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptions* options,
        __FIAsyncOperationWithProgress_2_Windows__CManagement__CDeployment__CDeploymentResult_Windows__CManagement__CDeployment__CDeploymentProgress** deploymentOperation);
    HRESULT (STDMETHODCALLTYPE* SetPackageStubPreference)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager9* This,
        HSTRING packageFamilyName,
        enum __x_ABI_CWindows_CManagement_CDeployment_CPackageStubPreference useStub);
    HRESULT (STDMETHODCALLTYPE* GetPackageStubPreference)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManager9* This,
        HSTRING packageFamilyName,
        enum __x_ABI_CWindows_CManagement_CDeployment_CPackageStubPreference* value);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager9Vtbl;

interface __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager9
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager9Vtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager9_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager9_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager9_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager9_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager9_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager9_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager9_FindProvisionedPackages(This, packageCollection) \
    ((This)->lpVtbl->FindProvisionedPackages(This, packageCollection))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager9_AddPackageByUriAsync(This, packageUri, options, deploymentOperation) \
    ((This)->lpVtbl->AddPackageByUriAsync(This, packageUri, options, deploymentOperation))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager9_StagePackageByUriAsync(This, packageUri, options, deploymentOperation) \
    ((This)->lpVtbl->StagePackageByUriAsync(This, packageUri, options, deploymentOperation))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager9_RegisterPackageByUriAsync(This, manifestUri, options, deploymentOperation) \
    ((This)->lpVtbl->RegisterPackageByUriAsync(This, manifestUri, options, deploymentOperation))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager9_RegisterPackagesByFullNameAsync(This, packageFullNames, options, deploymentOperation) \
    ((This)->lpVtbl->RegisterPackagesByFullNameAsync(This, packageFullNames, options, deploymentOperation))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager9_SetPackageStubPreference(This, packageFamilyName, useStub) \
    ((This)->lpVtbl->SetPackageStubPreference(This, packageFamilyName, useStub))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManager9_GetPackageStubPreference(This, packageFamilyName, value) \
    ((This)->lpVtbl->GetPackageStubPreference(This, packageFamilyName, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CDeployment_CIPackageManager9;
#endif /* !defined(____x_ABI_CWindows_CManagement_CDeployment_CIPackageManager9_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xa0000

/*
 *
 * Interface Windows.Management.Deployment.IPackageManagerDebugSettings
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 4.0
 *
 * Interface is a part of the implementation of type Windows.Management.Deployment.PackageManagerDebugSettings
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x40000
#if !defined(____x_ABI_CWindows_CManagement_CDeployment_CIPackageManagerDebugSettings_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CDeployment_CIPackageManagerDebugSettings_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Deployment_IPackageManagerDebugSettings[] = L"Windows.Management.Deployment.IPackageManagerDebugSettings";
typedef struct __x_ABI_CWindows_CManagement_CDeployment_CIPackageManagerDebugSettingsVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManagerDebugSettings* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManagerDebugSettings* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManagerDebugSettings* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManagerDebugSettings* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManagerDebugSettings* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManagerDebugSettings* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* SetContentGroupStateAsync)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManagerDebugSettings* This,
        __x_ABI_CWindows_CApplicationModel_CIPackage* package,
        HSTRING contentGroupName,
        enum __x_ABI_CWindows_CApplicationModel_CPackageContentGroupState state,
        __x_ABI_CWindows_CFoundation_CIAsyncAction** action);
    HRESULT (STDMETHODCALLTYPE* SetContentGroupStateWithPercentageAsync)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageManagerDebugSettings* This,
        __x_ABI_CWindows_CApplicationModel_CIPackage* package,
        HSTRING contentGroupName,
        enum __x_ABI_CWindows_CApplicationModel_CPackageContentGroupState state,
        DOUBLE completionPercentage,
        __x_ABI_CWindows_CFoundation_CIAsyncAction** action);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CDeployment_CIPackageManagerDebugSettingsVtbl;

interface __x_ABI_CWindows_CManagement_CDeployment_CIPackageManagerDebugSettings
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CDeployment_CIPackageManagerDebugSettingsVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManagerDebugSettings_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManagerDebugSettings_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManagerDebugSettings_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManagerDebugSettings_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManagerDebugSettings_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManagerDebugSettings_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManagerDebugSettings_SetContentGroupStateAsync(This, package, contentGroupName, state, action) \
    ((This)->lpVtbl->SetContentGroupStateAsync(This, package, contentGroupName, state, action))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageManagerDebugSettings_SetContentGroupStateWithPercentageAsync(This, package, contentGroupName, state, completionPercentage, action) \
    ((This)->lpVtbl->SetContentGroupStateWithPercentageAsync(This, package, contentGroupName, state, completionPercentage, action))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CDeployment_CIPackageManagerDebugSettings;
#endif /* !defined(____x_ABI_CWindows_CManagement_CDeployment_CIPackageManagerDebugSettings_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x40000

/*
 *
 * Interface Windows.Management.Deployment.IPackageUserInformation
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Deployment.PackageUserInformation
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CDeployment_CIPackageUserInformation_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CDeployment_CIPackageUserInformation_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Deployment_IPackageUserInformation[] = L"Windows.Management.Deployment.IPackageUserInformation";
typedef struct __x_ABI_CWindows_CManagement_CDeployment_CIPackageUserInformationVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageUserInformation* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageUserInformation* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageUserInformation* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageUserInformation* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageUserInformation* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageUserInformation* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_UserSecurityId)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageUserInformation* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* get_InstallState)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageUserInformation* This,
        enum __x_ABI_CWindows_CManagement_CDeployment_CPackageInstallState* value);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CDeployment_CIPackageUserInformationVtbl;

interface __x_ABI_CWindows_CManagement_CDeployment_CIPackageUserInformation
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CDeployment_CIPackageUserInformationVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageUserInformation_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageUserInformation_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageUserInformation_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageUserInformation_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageUserInformation_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageUserInformation_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageUserInformation_get_UserSecurityId(This, value) \
    ((This)->lpVtbl->get_UserSecurityId(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageUserInformation_get_InstallState(This, value) \
    ((This)->lpVtbl->get_InstallState(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CDeployment_CIPackageUserInformation;
#endif /* !defined(____x_ABI_CWindows_CManagement_CDeployment_CIPackageUserInformation_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Deployment.IPackageVolume
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Deployment.PackageVolume
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Deployment_IPackageVolume[] = L"Windows.Management.Deployment.IPackageVolume";
typedef struct __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolumeVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_IsOffline)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume* This,
        boolean* value);
    HRESULT (STDMETHODCALLTYPE* get_IsSystemVolume)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume* This,
        boolean* value);
    HRESULT (STDMETHODCALLTYPE* get_MountPoint)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* get_Name)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* get_PackageStorePath)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* get_SupportsHardLinks)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume* This,
        boolean* value);
    HRESULT (STDMETHODCALLTYPE* FindPackages)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume* This,
        __FIVector_1_Windows__CApplicationModel__CPackage** packageCollection);
    HRESULT (STDMETHODCALLTYPE* FindPackagesByNamePublisher)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume* This,
        HSTRING packageName,
        HSTRING packagePublisher,
        __FIVector_1_Windows__CApplicationModel__CPackage** packageCollection);
    HRESULT (STDMETHODCALLTYPE* FindPackagesByPackageFamilyName)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume* This,
        HSTRING packageFamilyName,
        __FIVector_1_Windows__CApplicationModel__CPackage** packageCollection);
    HRESULT (STDMETHODCALLTYPE* FindPackagesWithPackageTypes)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume* This,
        enum __x_ABI_CWindows_CManagement_CDeployment_CPackageTypes packageTypes,
        __FIVector_1_Windows__CApplicationModel__CPackage** packageCollection);
    HRESULT (STDMETHODCALLTYPE* FindPackagesByNamePublisherWithPackagesTypes)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume* This,
        enum __x_ABI_CWindows_CManagement_CDeployment_CPackageTypes packageTypes,
        HSTRING packageName,
        HSTRING packagePublisher,
        __FIVector_1_Windows__CApplicationModel__CPackage** packageCollection);
    HRESULT (STDMETHODCALLTYPE* FindPackagesByPackageFamilyNameWithPackageTypes)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume* This,
        enum __x_ABI_CWindows_CManagement_CDeployment_CPackageTypes packageTypes,
        HSTRING packageFamilyName,
        __FIVector_1_Windows__CApplicationModel__CPackage** packageCollection);
    HRESULT (STDMETHODCALLTYPE* FindPackageByPackageFullName)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume* This,
        HSTRING packageFullName,
        __FIVector_1_Windows__CApplicationModel__CPackage** packageCollection);
    HRESULT (STDMETHODCALLTYPE* FindPackagesByUserSecurityId)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume* This,
        HSTRING userSecurityId,
        __FIVector_1_Windows__CApplicationModel__CPackage** packageCollection);
    HRESULT (STDMETHODCALLTYPE* FindPackagesByUserSecurityIdNamePublisher)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume* This,
        HSTRING userSecurityId,
        HSTRING packageName,
        HSTRING packagePublisher,
        __FIVector_1_Windows__CApplicationModel__CPackage** packageCollection);
    HRESULT (STDMETHODCALLTYPE* FindPackagesByUserSecurityIdPackageFamilyName)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume* This,
        HSTRING userSecurityId,
        HSTRING packageFamilyName,
        __FIVector_1_Windows__CApplicationModel__CPackage** packageCollection);
    HRESULT (STDMETHODCALLTYPE* FindPackagesByUserSecurityIdWithPackageTypes)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume* This,
        HSTRING userSecurityId,
        enum __x_ABI_CWindows_CManagement_CDeployment_CPackageTypes packageTypes,
        __FIVector_1_Windows__CApplicationModel__CPackage** packageCollection);
    HRESULT (STDMETHODCALLTYPE* FindPackagesByUserSecurityIdNamePublisherWithPackageTypes)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume* This,
        HSTRING userSecurityId,
        enum __x_ABI_CWindows_CManagement_CDeployment_CPackageTypes packageTypes,
        HSTRING packageName,
        HSTRING packagePublisher,
        __FIVector_1_Windows__CApplicationModel__CPackage** packageCollection);
    HRESULT (STDMETHODCALLTYPE* FindPackagesByUserSecurityIdPackageFamilyNameWithPackagesTypes)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume* This,
        HSTRING userSecurityId,
        enum __x_ABI_CWindows_CManagement_CDeployment_CPackageTypes packageTypes,
        HSTRING packageFamilyName,
        __FIVector_1_Windows__CApplicationModel__CPackage** packageCollection);
    HRESULT (STDMETHODCALLTYPE* FindPackageByUserSecurityIdPackageFullName)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume* This,
        HSTRING userSecurityId,
        HSTRING packageFullName,
        __FIVector_1_Windows__CApplicationModel__CPackage** packageCollection);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolumeVtbl;

interface __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolumeVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume_get_IsOffline(This, value) \
    ((This)->lpVtbl->get_IsOffline(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume_get_IsSystemVolume(This, value) \
    ((This)->lpVtbl->get_IsSystemVolume(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume_get_MountPoint(This, value) \
    ((This)->lpVtbl->get_MountPoint(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume_get_Name(This, value) \
    ((This)->lpVtbl->get_Name(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume_get_PackageStorePath(This, value) \
    ((This)->lpVtbl->get_PackageStorePath(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume_get_SupportsHardLinks(This, value) \
    ((This)->lpVtbl->get_SupportsHardLinks(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume_FindPackages(This, packageCollection) \
    ((This)->lpVtbl->FindPackages(This, packageCollection))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume_FindPackagesByNamePublisher(This, packageName, packagePublisher, packageCollection) \
    ((This)->lpVtbl->FindPackagesByNamePublisher(This, packageName, packagePublisher, packageCollection))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume_FindPackagesByPackageFamilyName(This, packageFamilyName, packageCollection) \
    ((This)->lpVtbl->FindPackagesByPackageFamilyName(This, packageFamilyName, packageCollection))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume_FindPackagesWithPackageTypes(This, packageTypes, packageCollection) \
    ((This)->lpVtbl->FindPackagesWithPackageTypes(This, packageTypes, packageCollection))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume_FindPackagesByNamePublisherWithPackagesTypes(This, packageTypes, packageName, packagePublisher, packageCollection) \
    ((This)->lpVtbl->FindPackagesByNamePublisherWithPackagesTypes(This, packageTypes, packageName, packagePublisher, packageCollection))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume_FindPackagesByPackageFamilyNameWithPackageTypes(This, packageTypes, packageFamilyName, packageCollection) \
    ((This)->lpVtbl->FindPackagesByPackageFamilyNameWithPackageTypes(This, packageTypes, packageFamilyName, packageCollection))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume_FindPackageByPackageFullName(This, packageFullName, packageCollection) \
    ((This)->lpVtbl->FindPackageByPackageFullName(This, packageFullName, packageCollection))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume_FindPackagesByUserSecurityId(This, userSecurityId, packageCollection) \
    ((This)->lpVtbl->FindPackagesByUserSecurityId(This, userSecurityId, packageCollection))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume_FindPackagesByUserSecurityIdNamePublisher(This, userSecurityId, packageName, packagePublisher, packageCollection) \
    ((This)->lpVtbl->FindPackagesByUserSecurityIdNamePublisher(This, userSecurityId, packageName, packagePublisher, packageCollection))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume_FindPackagesByUserSecurityIdPackageFamilyName(This, userSecurityId, packageFamilyName, packageCollection) \
    ((This)->lpVtbl->FindPackagesByUserSecurityIdPackageFamilyName(This, userSecurityId, packageFamilyName, packageCollection))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume_FindPackagesByUserSecurityIdWithPackageTypes(This, userSecurityId, packageTypes, packageCollection) \
    ((This)->lpVtbl->FindPackagesByUserSecurityIdWithPackageTypes(This, userSecurityId, packageTypes, packageCollection))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume_FindPackagesByUserSecurityIdNamePublisherWithPackageTypes(This, userSecurityId, packageTypes, packageName, packagePublisher, packageCollection) \
    ((This)->lpVtbl->FindPackagesByUserSecurityIdNamePublisherWithPackageTypes(This, userSecurityId, packageTypes, packageName, packagePublisher, packageCollection))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume_FindPackagesByUserSecurityIdPackageFamilyNameWithPackagesTypes(This, userSecurityId, packageTypes, packageFamilyName, packageCollection) \
    ((This)->lpVtbl->FindPackagesByUserSecurityIdPackageFamilyNameWithPackagesTypes(This, userSecurityId, packageTypes, packageFamilyName, packageCollection))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume_FindPackageByUserSecurityIdPackageFullName(This, userSecurityId, packageFullName, packageCollection) \
    ((This)->lpVtbl->FindPackageByUserSecurityIdPackageFullName(This, userSecurityId, packageFullName, packageCollection))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume;
#endif /* !defined(____x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Deployment.IPackageVolume2
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 3.0
 *
 * Interface is a part of the implementation of type Windows.Management.Deployment.PackageVolume
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x30000
#if !defined(____x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume2_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume2_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Deployment_IPackageVolume2[] = L"Windows.Management.Deployment.IPackageVolume2";
typedef struct __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume2Vtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume2* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume2* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume2* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume2* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume2* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume2* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_IsFullTrustPackageSupported)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume2* This,
        boolean* value);
    HRESULT (STDMETHODCALLTYPE* get_IsAppxInstallSupported)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume2* This,
        boolean* value);
    HRESULT (STDMETHODCALLTYPE* GetAvailableSpaceAsync)(__x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume2* This,
        __FIAsyncOperation_1_UINT64** operation);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume2Vtbl;

interface __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume2
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume2Vtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume2_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume2_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume2_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume2_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume2_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume2_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume2_get_IsFullTrustPackageSupported(This, value) \
    ((This)->lpVtbl->get_IsFullTrustPackageSupported(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume2_get_IsAppxInstallSupported(This, value) \
    ((This)->lpVtbl->get_IsAppxInstallSupported(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume2_GetAvailableSpaceAsync(This, operation) \
    ((This)->lpVtbl->GetAvailableSpaceAsync(This, operation))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume2;
#endif /* !defined(____x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume2_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x30000

/*
 *
 * Interface Windows.Management.Deployment.IRegisterPackageOptions
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 10.0
 *
 * Interface is a part of the implementation of type Windows.Management.Deployment.RegisterPackageOptions
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xa0000
#if !defined(____x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Deployment_IRegisterPackageOptions[] = L"Windows.Management.Deployment.IRegisterPackageOptions";
typedef struct __x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptionsVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptions* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptions* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptions* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptions* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptions* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptions* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_DependencyPackageUris)(__x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptions* This,
        __FIVector_1_Windows__CFoundation__CUri** value);
    HRESULT (STDMETHODCALLTYPE* get_AppDataVolume)(__x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptions* This,
        __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume** value);
    HRESULT (STDMETHODCALLTYPE* put_AppDataVolume)(__x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptions* This,
        __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume* value);
    HRESULT (STDMETHODCALLTYPE* get_OptionalPackageFamilyNames)(__x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptions* This,
        __FIVector_1_HSTRING** value);
    HRESULT (STDMETHODCALLTYPE* get_ExternalLocationUri)(__x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptions* This,
        __x_ABI_CWindows_CFoundation_CIUriRuntimeClass** value);
    HRESULT (STDMETHODCALLTYPE* put_ExternalLocationUri)(__x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptions* This,
        __x_ABI_CWindows_CFoundation_CIUriRuntimeClass* value);
    HRESULT (STDMETHODCALLTYPE* get_DeveloperMode)(__x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptions* This,
        boolean* value);
    HRESULT (STDMETHODCALLTYPE* put_DeveloperMode)(__x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptions* This,
        boolean value);
    HRESULT (STDMETHODCALLTYPE* get_ForceAppShutdown)(__x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptions* This,
        boolean* value);
    HRESULT (STDMETHODCALLTYPE* put_ForceAppShutdown)(__x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptions* This,
        boolean value);
    HRESULT (STDMETHODCALLTYPE* get_ForceTargetAppShutdown)(__x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptions* This,
        boolean* value);
    HRESULT (STDMETHODCALLTYPE* put_ForceTargetAppShutdown)(__x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptions* This,
        boolean value);
    HRESULT (STDMETHODCALLTYPE* get_ForceUpdateFromAnyVersion)(__x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptions* This,
        boolean* value);
    HRESULT (STDMETHODCALLTYPE* put_ForceUpdateFromAnyVersion)(__x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptions* This,
        boolean value);
    HRESULT (STDMETHODCALLTYPE* get_InstallAllResources)(__x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptions* This,
        boolean* value);
    HRESULT (STDMETHODCALLTYPE* put_InstallAllResources)(__x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptions* This,
        boolean value);
    HRESULT (STDMETHODCALLTYPE* get_StageInPlace)(__x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptions* This,
        boolean* value);
    HRESULT (STDMETHODCALLTYPE* put_StageInPlace)(__x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptions* This,
        boolean value);
    HRESULT (STDMETHODCALLTYPE* get_AllowUnsigned)(__x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptions* This,
        boolean* value);
    HRESULT (STDMETHODCALLTYPE* put_AllowUnsigned)(__x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptions* This,
        boolean value);
    HRESULT (STDMETHODCALLTYPE* get_DeferRegistrationWhenPackagesAreInUse)(__x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptions* This,
        boolean* value);
    HRESULT (STDMETHODCALLTYPE* put_DeferRegistrationWhenPackagesAreInUse)(__x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptions* This,
        boolean value);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptionsVtbl;

interface __x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptions
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptionsVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_get_DependencyPackageUris(This, value) \
    ((This)->lpVtbl->get_DependencyPackageUris(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_get_AppDataVolume(This, value) \
    ((This)->lpVtbl->get_AppDataVolume(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_put_AppDataVolume(This, value) \
    ((This)->lpVtbl->put_AppDataVolume(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_get_OptionalPackageFamilyNames(This, value) \
    ((This)->lpVtbl->get_OptionalPackageFamilyNames(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_get_ExternalLocationUri(This, value) \
    ((This)->lpVtbl->get_ExternalLocationUri(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_put_ExternalLocationUri(This, value) \
    ((This)->lpVtbl->put_ExternalLocationUri(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_get_DeveloperMode(This, value) \
    ((This)->lpVtbl->get_DeveloperMode(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_put_DeveloperMode(This, value) \
    ((This)->lpVtbl->put_DeveloperMode(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_get_ForceAppShutdown(This, value) \
    ((This)->lpVtbl->get_ForceAppShutdown(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_put_ForceAppShutdown(This, value) \
    ((This)->lpVtbl->put_ForceAppShutdown(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_get_ForceTargetAppShutdown(This, value) \
    ((This)->lpVtbl->get_ForceTargetAppShutdown(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_put_ForceTargetAppShutdown(This, value) \
    ((This)->lpVtbl->put_ForceTargetAppShutdown(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_get_ForceUpdateFromAnyVersion(This, value) \
    ((This)->lpVtbl->get_ForceUpdateFromAnyVersion(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_put_ForceUpdateFromAnyVersion(This, value) \
    ((This)->lpVtbl->put_ForceUpdateFromAnyVersion(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_get_InstallAllResources(This, value) \
    ((This)->lpVtbl->get_InstallAllResources(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_put_InstallAllResources(This, value) \
    ((This)->lpVtbl->put_InstallAllResources(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_get_StageInPlace(This, value) \
    ((This)->lpVtbl->get_StageInPlace(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_put_StageInPlace(This, value) \
    ((This)->lpVtbl->put_StageInPlace(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_get_AllowUnsigned(This, value) \
    ((This)->lpVtbl->get_AllowUnsigned(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_put_AllowUnsigned(This, value) \
    ((This)->lpVtbl->put_AllowUnsigned(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_get_DeferRegistrationWhenPackagesAreInUse(This, value) \
    ((This)->lpVtbl->get_DeferRegistrationWhenPackagesAreInUse(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_put_DeferRegistrationWhenPackagesAreInUse(This, value) \
    ((This)->lpVtbl->put_DeferRegistrationWhenPackagesAreInUse(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptions;
#endif /* !defined(____x_ABI_CWindows_CManagement_CDeployment_CIRegisterPackageOptions_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xa0000

/*
 *
 * Interface Windows.Management.Deployment.IStagePackageOptions
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 10.0
 *
 * Interface is a part of the implementation of type Windows.Management.Deployment.StagePackageOptions
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xa0000
#if !defined(____x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptions_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptions_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Deployment_IStagePackageOptions[] = L"Windows.Management.Deployment.IStagePackageOptions";
typedef struct __x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptionsVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptions* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptions* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptions* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptions* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptions* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptions* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_DependencyPackageUris)(__x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptions* This,
        __FIVector_1_Windows__CFoundation__CUri** value);
    HRESULT (STDMETHODCALLTYPE* get_TargetVolume)(__x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptions* This,
        __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume** value);
    HRESULT (STDMETHODCALLTYPE* put_TargetVolume)(__x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptions* This,
        __x_ABI_CWindows_CManagement_CDeployment_CIPackageVolume* value);
    HRESULT (STDMETHODCALLTYPE* get_OptionalPackageFamilyNames)(__x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptions* This,
        __FIVector_1_HSTRING** value);
    HRESULT (STDMETHODCALLTYPE* get_OptionalPackageUris)(__x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptions* This,
        __FIVector_1_Windows__CFoundation__CUri** value);
    HRESULT (STDMETHODCALLTYPE* get_RelatedPackageUris)(__x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptions* This,
        __FIVector_1_Windows__CFoundation__CUri** value);
    HRESULT (STDMETHODCALLTYPE* get_ExternalLocationUri)(__x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptions* This,
        __x_ABI_CWindows_CFoundation_CIUriRuntimeClass** value);
    HRESULT (STDMETHODCALLTYPE* put_ExternalLocationUri)(__x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptions* This,
        __x_ABI_CWindows_CFoundation_CIUriRuntimeClass* value);
    HRESULT (STDMETHODCALLTYPE* get_StubPackageOption)(__x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptions* This,
        enum __x_ABI_CWindows_CManagement_CDeployment_CStubPackageOption* value);
    HRESULT (STDMETHODCALLTYPE* put_StubPackageOption)(__x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptions* This,
        enum __x_ABI_CWindows_CManagement_CDeployment_CStubPackageOption value);
    HRESULT (STDMETHODCALLTYPE* get_DeveloperMode)(__x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptions* This,
        boolean* value);
    HRESULT (STDMETHODCALLTYPE* put_DeveloperMode)(__x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptions* This,
        boolean value);
    HRESULT (STDMETHODCALLTYPE* get_ForceUpdateFromAnyVersion)(__x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptions* This,
        boolean* value);
    HRESULT (STDMETHODCALLTYPE* put_ForceUpdateFromAnyVersion)(__x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptions* This,
        boolean value);
    HRESULT (STDMETHODCALLTYPE* get_InstallAllResources)(__x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptions* This,
        boolean* value);
    HRESULT (STDMETHODCALLTYPE* put_InstallAllResources)(__x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptions* This,
        boolean value);
    HRESULT (STDMETHODCALLTYPE* get_RequiredContentGroupOnly)(__x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptions* This,
        boolean* value);
    HRESULT (STDMETHODCALLTYPE* put_RequiredContentGroupOnly)(__x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptions* This,
        boolean value);
    HRESULT (STDMETHODCALLTYPE* get_StageInPlace)(__x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptions* This,
        boolean* value);
    HRESULT (STDMETHODCALLTYPE* put_StageInPlace)(__x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptions* This,
        boolean value);
    HRESULT (STDMETHODCALLTYPE* get_AllowUnsigned)(__x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptions* This,
        boolean* value);
    HRESULT (STDMETHODCALLTYPE* put_AllowUnsigned)(__x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptions* This,
        boolean value);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptionsVtbl;

interface __x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptions
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptionsVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptions_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptions_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptions_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptions_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptions_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptions_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptions_get_DependencyPackageUris(This, value) \
    ((This)->lpVtbl->get_DependencyPackageUris(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptions_get_TargetVolume(This, value) \
    ((This)->lpVtbl->get_TargetVolume(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptions_put_TargetVolume(This, value) \
    ((This)->lpVtbl->put_TargetVolume(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptions_get_OptionalPackageFamilyNames(This, value) \
    ((This)->lpVtbl->get_OptionalPackageFamilyNames(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptions_get_OptionalPackageUris(This, value) \
    ((This)->lpVtbl->get_OptionalPackageUris(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptions_get_RelatedPackageUris(This, value) \
    ((This)->lpVtbl->get_RelatedPackageUris(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptions_get_ExternalLocationUri(This, value) \
    ((This)->lpVtbl->get_ExternalLocationUri(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptions_put_ExternalLocationUri(This, value) \
    ((This)->lpVtbl->put_ExternalLocationUri(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptions_get_StubPackageOption(This, value) \
    ((This)->lpVtbl->get_StubPackageOption(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptions_put_StubPackageOption(This, value) \
    ((This)->lpVtbl->put_StubPackageOption(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptions_get_DeveloperMode(This, value) \
    ((This)->lpVtbl->get_DeveloperMode(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptions_put_DeveloperMode(This, value) \
    ((This)->lpVtbl->put_DeveloperMode(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptions_get_ForceUpdateFromAnyVersion(This, value) \
    ((This)->lpVtbl->get_ForceUpdateFromAnyVersion(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptions_put_ForceUpdateFromAnyVersion(This, value) \
    ((This)->lpVtbl->put_ForceUpdateFromAnyVersion(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptions_get_InstallAllResources(This, value) \
    ((This)->lpVtbl->get_InstallAllResources(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptions_put_InstallAllResources(This, value) \
    ((This)->lpVtbl->put_InstallAllResources(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptions_get_RequiredContentGroupOnly(This, value) \
    ((This)->lpVtbl->get_RequiredContentGroupOnly(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptions_put_RequiredContentGroupOnly(This, value) \
    ((This)->lpVtbl->put_RequiredContentGroupOnly(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptions_get_StageInPlace(This, value) \
    ((This)->lpVtbl->get_StageInPlace(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptions_put_StageInPlace(This, value) \
    ((This)->lpVtbl->put_StageInPlace(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptions_get_AllowUnsigned(This, value) \
    ((This)->lpVtbl->get_AllowUnsigned(This, value))

#define __x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptions_put_AllowUnsigned(This, value) \
    ((This)->lpVtbl->put_AllowUnsigned(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptions;
#endif /* !defined(____x_ABI_CWindows_CManagement_CDeployment_CIStagePackageOptions_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xa0000

/*
 *
 * Class Windows.Management.Deployment.AddPackageOptions
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 10.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via RoActivateInstance starting with version 10.0 of the Windows.Foundation.UniversalApiContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Management.Deployment.IAddPackageOptions ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xa0000
#ifndef RUNTIMECLASS_Windows_Management_Deployment_AddPackageOptions_DEFINED
#define RUNTIMECLASS_Windows_Management_Deployment_AddPackageOptions_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Deployment_AddPackageOptions[] = L"Windows.Management.Deployment.AddPackageOptions";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xa0000

/*
 *
 * Class Windows.Management.Deployment.DeploymentResult
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 * Class implements the following interfaces:
 *    Windows.Management.Deployment.IDeploymentResult ** Default Interface **
 *    Windows.Management.Deployment.IDeploymentResult2
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Management_Deployment_DeploymentResult_DEFINED
#define RUNTIMECLASS_Windows_Management_Deployment_DeploymentResult_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Deployment_DeploymentResult[] = L"Windows.Management.Deployment.DeploymentResult";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Management.Deployment.PackageManager
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via RoActivateInstance starting with version 1.0 of the Windows.Foundation.UniversalApiContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Management.Deployment.IPackageManager ** Default Interface **
 *    Windows.Management.Deployment.IPackageManager2
 *    Windows.Management.Deployment.IPackageManager3
 *    Windows.Management.Deployment.IPackageManager4
 *    Windows.Management.Deployment.IPackageManager5
 *    Windows.Management.Deployment.IPackageManager6
 *    Windows.Management.Deployment.IPackageManager7
 *    Windows.Management.Deployment.IPackageManager8
 *    Windows.Management.Deployment.IPackageManager9
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Management_Deployment_PackageManager_DEFINED
#define RUNTIMECLASS_Windows_Management_Deployment_PackageManager_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Deployment_PackageManager[] = L"Windows.Management.Deployment.PackageManager";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Management.Deployment.PackageManagerDebugSettings
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 4.0
 *
 * Class implements the following interfaces:
 *    Windows.Management.Deployment.IPackageManagerDebugSettings ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x40000
#ifndef RUNTIMECLASS_Windows_Management_Deployment_PackageManagerDebugSettings_DEFINED
#define RUNTIMECLASS_Windows_Management_Deployment_PackageManagerDebugSettings_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Deployment_PackageManagerDebugSettings[] = L"Windows.Management.Deployment.PackageManagerDebugSettings";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x40000

/*
 *
 * Class Windows.Management.Deployment.PackageUserInformation
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 * Class implements the following interfaces:
 *    Windows.Management.Deployment.IPackageUserInformation ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Management_Deployment_PackageUserInformation_DEFINED
#define RUNTIMECLASS_Windows_Management_Deployment_PackageUserInformation_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Deployment_PackageUserInformation[] = L"Windows.Management.Deployment.PackageUserInformation";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Management.Deployment.PackageVolume
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 * Class implements the following interfaces:
 *    Windows.Management.Deployment.IPackageVolume ** Default Interface **
 *    Windows.Management.Deployment.IPackageVolume2
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Management_Deployment_PackageVolume_DEFINED
#define RUNTIMECLASS_Windows_Management_Deployment_PackageVolume_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Deployment_PackageVolume[] = L"Windows.Management.Deployment.PackageVolume";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Management.Deployment.RegisterPackageOptions
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 10.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via RoActivateInstance starting with version 10.0 of the Windows.Foundation.UniversalApiContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Management.Deployment.IRegisterPackageOptions ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xa0000
#ifndef RUNTIMECLASS_Windows_Management_Deployment_RegisterPackageOptions_DEFINED
#define RUNTIMECLASS_Windows_Management_Deployment_RegisterPackageOptions_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Deployment_RegisterPackageOptions[] = L"Windows.Management.Deployment.RegisterPackageOptions";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xa0000

/*
 *
 * Class Windows.Management.Deployment.StagePackageOptions
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 10.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via RoActivateInstance starting with version 10.0 of the Windows.Foundation.UniversalApiContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Management.Deployment.IStagePackageOptions ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xa0000
#ifndef RUNTIMECLASS_Windows_Management_Deployment_StagePackageOptions_DEFINED
#define RUNTIMECLASS_Windows_Management_Deployment_StagePackageOptions_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Deployment_StagePackageOptions[] = L"Windows.Management.Deployment.StagePackageOptions";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xa0000

#endif // defined(__cplusplus)
#pragma pop_macro("MIDL_CONST_ID")
// Restore the original value of the 'DEPRECATED' macro
#pragma pop_macro("DEPRECATED")

#ifdef __clang__
#pragma clang diagnostic pop // deprecated-declarations
#else
#pragma warning(pop)
#endif
#endif // __windows2Emanagement2Edeployment_p_h__

#endif // __windows2Emanagement2Edeployment_h__
