
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
#ifndef __windows2Estorage2Eprovider_h__
#define __windows2Estorage2Eprovider_h__
#ifndef __windows2Estorage2Eprovider_p_h__
#define __windows2Estorage2Eprovider_p_h__


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

#if !defined(WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION)
#define WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION 0x60000
#endif // defined(WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION)

#endif // defined(SPECIFIC_API_CONTRACT_DEFINITIONS)


// Header files for imported files
#include "inspectable.h"
#include "AsyncInfo.h"
#include "EventToken.h"
#include "windowscontracts.h"
#include "Windows.Foundation.h"
#include "Windows.Storage.h"
#include "Windows.Storage.Streams.h"
// Importing Collections header
#include <windows.foundation.collections.h>

#if defined(__cplusplus) && !defined(CINTERFACE)
/* Forward Declarations */
#ifndef ____x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterStatics_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterStatics_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                interface ICachedFileUpdaterStatics;
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterStatics ABI::Windows::Storage::Provider::ICachedFileUpdaterStatics

#endif // ____x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterStatics_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                interface ICachedFileUpdaterUI;
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI ABI::Windows::Storage::Provider::ICachedFileUpdaterUI

#endif // ____x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI2_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI2_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                interface ICachedFileUpdaterUI2;
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI2 ABI::Windows::Storage::Provider::ICachedFileUpdaterUI2

#endif // ____x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI2_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                interface IFileUpdateRequest;
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest ABI::Windows::Storage::Provider::IFileUpdateRequest

#endif // ____x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest2_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest2_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                interface IFileUpdateRequest2;
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest2 ABI::Windows::Storage::Provider::IFileUpdateRequest2

#endif // ____x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest2_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequestDeferral_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequestDeferral_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                interface IFileUpdateRequestDeferral;
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequestDeferral ABI::Windows::Storage::Provider::IFileUpdateRequestDeferral

#endif // ____x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequestDeferral_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequestedEventArgs_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequestedEventArgs_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                interface IFileUpdateRequestedEventArgs;
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequestedEventArgs ABI::Windows::Storage::Provider::IFileUpdateRequestedEventArgs

#endif // ____x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequestedEventArgs_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderError_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderError_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                interface IStorageProviderError;
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderError ABI::Windows::Storage::Provider::IStorageProviderError

#endif // ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderError_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommand_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommand_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                interface IStorageProviderErrorCommand;
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommand ABI::Windows::Storage::Provider::IStorageProviderErrorCommand

#endif // ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommand_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommandFactory_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommandFactory_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                interface IStorageProviderErrorCommandFactory;
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommandFactory ABI::Windows::Storage::Provider::IStorageProviderErrorCommandFactory

#endif // ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommandFactory_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorFactory_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorFactory_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                interface IStorageProviderErrorFactory;
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorFactory ABI::Windows::Storage::Provider::IStorageProviderErrorFactory

#endif // ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorFactory_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfo_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfo_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                interface IStorageProviderFileTypeInfo;
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfo ABI::Windows::Storage::Provider::IStorageProviderFileTypeInfo

#endif // ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfo_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfoFactory_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfoFactory_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                interface IStorageProviderFileTypeInfoFactory;
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfoFactory ABI::Windows::Storage::Provider::IStorageProviderFileTypeInfoFactory

#endif // ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfoFactory_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetContentInfoForPathResult_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetContentInfoForPathResult_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                interface IStorageProviderGetContentInfoForPathResult;
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetContentInfoForPathResult ABI::Windows::Storage::Provider::IStorageProviderGetContentInfoForPathResult

#endif // ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetContentInfoForPathResult_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetPathForContentUriResult_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetPathForContentUriResult_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                interface IStorageProviderGetPathForContentUriResult;
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetPathForContentUriResult ABI::Windows::Storage::Provider::IStorageProviderGetPathForContentUriResult

#endif // ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetPathForContentUriResult_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderHandlerFactory_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderHandlerFactory_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                interface IStorageProviderHandlerFactory;
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderHandlerFactory ABI::Windows::Storage::Provider::IStorageProviderHandlerFactory

#endif // ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderHandlerFactory_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertiesStatics_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertiesStatics_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                interface IStorageProviderItemPropertiesStatics;
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertiesStatics ABI::Windows::Storage::Provider::IStorageProviderItemPropertiesStatics

#endif // ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertiesStatics_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemProperty_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemProperty_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                interface IStorageProviderItemProperty;
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemProperty ABI::Windows::Storage::Provider::IStorageProviderItemProperty

#endif // ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemProperty_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertyDefinition_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertyDefinition_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                interface IStorageProviderItemPropertyDefinition;
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertyDefinition ABI::Windows::Storage::Provider::IStorageProviderItemPropertyDefinition

#endif // ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertyDefinition_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertySource_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertySource_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                interface IStorageProviderItemPropertySource;
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertySource ABI::Windows::Storage::Provider::IStorageProviderItemPropertySource

#endif // ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertySource_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderPropertyCapabilities_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderPropertyCapabilities_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                interface IStorageProviderPropertyCapabilities;
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderPropertyCapabilities ABI::Windows::Storage::Provider::IStorageProviderPropertyCapabilities

#endif // ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderPropertyCapabilities_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatus_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatus_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                interface IStorageProviderStatus;
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatus ABI::Windows::Storage::Provider::IStorageProviderStatus

#endif // ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatus_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusFactory_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusFactory_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                interface IStorageProviderStatusFactory;
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusFactory ABI::Windows::Storage::Provider::IStorageProviderStatusFactory

#endif // ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusFactory_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusSource_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusSource_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                interface IStorageProviderStatusSource;
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusSource ABI::Windows::Storage::Provider::IStorageProviderStatusSource

#endif // ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusSource_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                interface IStorageProviderSyncRootInfo;
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo ABI::Windows::Storage::Provider::IStorageProviderSyncRootInfo

#endif // ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo2_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo2_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                interface IStorageProviderSyncRootInfo2;
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo2 ABI::Windows::Storage::Provider::IStorageProviderSyncRootInfo2

#endif // ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo2_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo3_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo3_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                interface IStorageProviderSyncRootInfo3;
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo3 ABI::Windows::Storage::Provider::IStorageProviderSyncRootInfo3

#endif // ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo3_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStatics_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStatics_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                interface IStorageProviderSyncRootManagerStatics;
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStatics ABI::Windows::Storage::Provider::IStorageProviderSyncRootManagerStatics

#endif // ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStatics_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStatics2_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStatics2_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                interface IStorageProviderSyncRootManagerStatics2;
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStatics2 ABI::Windows::Storage::Provider::IStorageProviderSyncRootManagerStatics2

#endif // ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStatics2_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderUriSource_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderUriSource_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                interface IStorageProviderUriSource;
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderUriSource ABI::Windows::Storage::Provider::IStorageProviderUriSource

#endif // ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderUriSource_FWD_DEFINED__

// Parameterized interface forward declarations (C++)

// Collection interface definitions
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                class StorageProviderError;
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */

#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x50000

#ifndef DEF___FIIterator_1_Windows__CStorage__CProvider__CStorageProviderError_USE
#define DEF___FIIterator_1_Windows__CStorage__CProvider__CStorageProviderError_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("638cc599-72fe-54b2-be50-53f446d8a538"))
IIterator<ABI::Windows::Storage::Provider::StorageProviderError*> : IIterator_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Storage::Provider::StorageProviderError*, ABI::Windows::Storage::Provider::IStorageProviderError*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IIterator`1<Windows.Storage.Provider.StorageProviderError>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterator<ABI::Windows::Storage::Provider::StorageProviderError*> __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderError_t;
#define __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderError ABI::Windows::Foundation::Collections::__FIIterator_1_Windows__CStorage__CProvider__CStorageProviderError_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterator_1_Windows__CStorage__CProvider__CStorageProviderError_USE */

#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x50000

#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x50000

#ifndef DEF___FIIterable_1_Windows__CStorage__CProvider__CStorageProviderError_USE
#define DEF___FIIterable_1_Windows__CStorage__CProvider__CStorageProviderError_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("2b2a9a00-9929-5154-a897-1e6cfd7cf21a"))
IIterable<ABI::Windows::Storage::Provider::StorageProviderError*> : IIterable_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Storage::Provider::StorageProviderError*, ABI::Windows::Storage::Provider::IStorageProviderError*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IIterable`1<Windows.Storage.Provider.StorageProviderError>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterable<ABI::Windows::Storage::Provider::StorageProviderError*> __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderError_t;
#define __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderError ABI::Windows::Foundation::Collections::__FIIterable_1_Windows__CStorage__CProvider__CStorageProviderError_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterable_1_Windows__CStorage__CProvider__CStorageProviderError_USE */

#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x50000

namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                class StorageProviderFileTypeInfo;
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */

#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x40000

#ifndef DEF___FIIterator_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo_USE
#define DEF___FIIterator_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("7d5b1532-3ca2-5930-a3c8-7c488f6ac2fb"))
IIterator<ABI::Windows::Storage::Provider::StorageProviderFileTypeInfo*> : IIterator_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Storage::Provider::StorageProviderFileTypeInfo*, ABI::Windows::Storage::Provider::IStorageProviderFileTypeInfo*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IIterator`1<Windows.Storage.Provider.StorageProviderFileTypeInfo>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterator<ABI::Windows::Storage::Provider::StorageProviderFileTypeInfo*> __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo_t;
#define __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo ABI::Windows::Foundation::Collections::__FIIterator_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterator_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo_USE */

#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x40000

#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x40000

#ifndef DEF___FIIterable_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo_USE
#define DEF___FIIterable_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("b21025bc-4365-5728-b52e-51475166f141"))
IIterable<ABI::Windows::Storage::Provider::StorageProviderFileTypeInfo*> : IIterable_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Storage::Provider::StorageProviderFileTypeInfo*, ABI::Windows::Storage::Provider::IStorageProviderFileTypeInfo*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IIterable`1<Windows.Storage.Provider.StorageProviderFileTypeInfo>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterable<ABI::Windows::Storage::Provider::StorageProviderFileTypeInfo*> __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo_t;
#define __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo ABI::Windows::Foundation::Collections::__FIIterable_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterable_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo_USE */

#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x40000

namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                class StorageProviderItemProperty;
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */

#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000

#ifndef DEF___FIIterator_1_Windows__CStorage__CProvider__CStorageProviderItemProperty_USE
#define DEF___FIIterator_1_Windows__CStorage__CProvider__CStorageProviderItemProperty_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("0c6dddde-1aa3-54f5-b139-e4a237dc1c5f"))
IIterator<ABI::Windows::Storage::Provider::StorageProviderItemProperty*> : IIterator_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Storage::Provider::StorageProviderItemProperty*, ABI::Windows::Storage::Provider::IStorageProviderItemProperty*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IIterator`1<Windows.Storage.Provider.StorageProviderItemProperty>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterator<ABI::Windows::Storage::Provider::StorageProviderItemProperty*> __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderItemProperty_t;
#define __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderItemProperty ABI::Windows::Foundation::Collections::__FIIterator_1_Windows__CStorage__CProvider__CStorageProviderItemProperty_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterator_1_Windows__CStorage__CProvider__CStorageProviderItemProperty_USE */

#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000

#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000

#ifndef DEF___FIIterable_1_Windows__CStorage__CProvider__CStorageProviderItemProperty_USE
#define DEF___FIIterable_1_Windows__CStorage__CProvider__CStorageProviderItemProperty_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("4584cb69-ee26-59e0-b05d-c9a7851a7317"))
IIterable<ABI::Windows::Storage::Provider::StorageProviderItemProperty*> : IIterable_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Storage::Provider::StorageProviderItemProperty*, ABI::Windows::Storage::Provider::IStorageProviderItemProperty*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IIterable`1<Windows.Storage.Provider.StorageProviderItemProperty>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterable<ABI::Windows::Storage::Provider::StorageProviderItemProperty*> __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderItemProperty_t;
#define __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderItemProperty ABI::Windows::Foundation::Collections::__FIIterable_1_Windows__CStorage__CProvider__CStorageProviderItemProperty_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterable_1_Windows__CStorage__CProvider__CStorageProviderItemProperty_USE */

#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000

namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                class StorageProviderItemPropertyDefinition;
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */

#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000

#ifndef DEF___FIIterator_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition_USE
#define DEF___FIIterator_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("55e5719d-2bda-521f-8c60-6921d90b0bb1"))
IIterator<ABI::Windows::Storage::Provider::StorageProviderItemPropertyDefinition*> : IIterator_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Storage::Provider::StorageProviderItemPropertyDefinition*, ABI::Windows::Storage::Provider::IStorageProviderItemPropertyDefinition*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IIterator`1<Windows.Storage.Provider.StorageProviderItemPropertyDefinition>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterator<ABI::Windows::Storage::Provider::StorageProviderItemPropertyDefinition*> __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition_t;
#define __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition ABI::Windows::Foundation::Collections::__FIIterator_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterator_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition_USE */

#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000

#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000

#ifndef DEF___FIIterable_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition_USE
#define DEF___FIIterable_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("41e78b90-1a7f-5dab-a123-7d5f5011dfeb"))
IIterable<ABI::Windows::Storage::Provider::StorageProviderItemPropertyDefinition*> : IIterable_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Storage::Provider::StorageProviderItemPropertyDefinition*, ABI::Windows::Storage::Provider::IStorageProviderItemPropertyDefinition*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IIterable`1<Windows.Storage.Provider.StorageProviderItemPropertyDefinition>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterable<ABI::Windows::Storage::Provider::StorageProviderItemPropertyDefinition*> __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition_t;
#define __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition ABI::Windows::Foundation::Collections::__FIIterable_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterable_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition_USE */

#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000

namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                class StorageProviderSyncRootInfo;
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */

#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000

#ifndef DEF___FIIterator_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo_USE
#define DEF___FIIterator_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("f73f72c9-6bf9-5f24-95af-7264e5516423"))
IIterator<ABI::Windows::Storage::Provider::StorageProviderSyncRootInfo*> : IIterator_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Storage::Provider::StorageProviderSyncRootInfo*, ABI::Windows::Storage::Provider::IStorageProviderSyncRootInfo*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IIterator`1<Windows.Storage.Provider.StorageProviderSyncRootInfo>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterator<ABI::Windows::Storage::Provider::StorageProviderSyncRootInfo*> __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo_t;
#define __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo ABI::Windows::Foundation::Collections::__FIIterator_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterator_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo_USE */

#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000

#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000

#ifndef DEF___FIIterable_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo_USE
#define DEF___FIIterable_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("62ba69a0-f65c-502c-9782-b4bc25194d11"))
IIterable<ABI::Windows::Storage::Provider::StorageProviderSyncRootInfo*> : IIterable_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Storage::Provider::StorageProviderSyncRootInfo*, ABI::Windows::Storage::Provider::IStorageProviderSyncRootInfo*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IIterable`1<Windows.Storage.Provider.StorageProviderSyncRootInfo>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterable<ABI::Windows::Storage::Provider::StorageProviderSyncRootInfo*> __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo_t;
#define __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo ABI::Windows::Foundation::Collections::__FIIterable_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterable_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo_USE */

#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000

#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x50000

#ifndef DEF___FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderError_USE
#define DEF___FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderError_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("88932307-2b4b-5235-ab32-6d324a523763"))
IVectorView<ABI::Windows::Storage::Provider::StorageProviderError*> : IVectorView_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Storage::Provider::StorageProviderError*, ABI::Windows::Storage::Provider::IStorageProviderError*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IVectorView`1<Windows.Storage.Provider.StorageProviderError>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IVectorView<ABI::Windows::Storage::Provider::StorageProviderError*> __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderError_t;
#define __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderError ABI::Windows::Foundation::Collections::__FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderError_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderError_USE */

#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x50000

#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x40000

#ifndef DEF___FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo_USE
#define DEF___FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("8ac5508f-9fc5-5ab4-9927-9d7a25c1d0d2"))
IVectorView<ABI::Windows::Storage::Provider::StorageProviderFileTypeInfo*> : IVectorView_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Storage::Provider::StorageProviderFileTypeInfo*, ABI::Windows::Storage::Provider::IStorageProviderFileTypeInfo*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IVectorView`1<Windows.Storage.Provider.StorageProviderFileTypeInfo>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IVectorView<ABI::Windows::Storage::Provider::StorageProviderFileTypeInfo*> __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo_t;
#define __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo ABI::Windows::Foundation::Collections::__FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo_USE */

#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x40000

#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000

#ifndef DEF___FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition_USE
#define DEF___FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("327544ca-45dc-5c83-b054-0a91e5fa0a29"))
IVectorView<ABI::Windows::Storage::Provider::StorageProviderItemPropertyDefinition*> : IVectorView_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Storage::Provider::StorageProviderItemPropertyDefinition*, ABI::Windows::Storage::Provider::IStorageProviderItemPropertyDefinition*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IVectorView`1<Windows.Storage.Provider.StorageProviderItemPropertyDefinition>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IVectorView<ABI::Windows::Storage::Provider::StorageProviderItemPropertyDefinition*> __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition_t;
#define __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition ABI::Windows::Foundation::Collections::__FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition_USE */

#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000

#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000

#ifndef DEF___FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo_USE
#define DEF___FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("211521e5-217c-5ff3-bf9e-8dc4d675177f"))
IVectorView<ABI::Windows::Storage::Provider::StorageProviderSyncRootInfo*> : IVectorView_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Storage::Provider::StorageProviderSyncRootInfo*, ABI::Windows::Storage::Provider::IStorageProviderSyncRootInfo*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IVectorView`1<Windows.Storage.Provider.StorageProviderSyncRootInfo>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IVectorView<ABI::Windows::Storage::Provider::StorageProviderSyncRootInfo*> __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo_t;
#define __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo ABI::Windows::Foundation::Collections::__FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo_USE */

#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000

#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x40000

#ifndef DEF___FIVector_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo_USE
#define DEF___FIVector_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("9172e4ab-a9ca-5cc4-9311-363f9f097da5"))
IVector<ABI::Windows::Storage::Provider::StorageProviderFileTypeInfo*> : IVector_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Storage::Provider::StorageProviderFileTypeInfo*, ABI::Windows::Storage::Provider::IStorageProviderFileTypeInfo*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IVector`1<Windows.Storage.Provider.StorageProviderFileTypeInfo>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IVector<ABI::Windows::Storage::Provider::StorageProviderFileTypeInfo*> __FIVector_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo_t;
#define __FIVector_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo ABI::Windows::Foundation::Collections::__FIVector_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIVector_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo_USE */

#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x40000

#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000

#ifndef DEF___FIVector_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition_USE
#define DEF___FIVector_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("f839fcff-87df-53a7-94d4-b507101e7e63"))
IVector<ABI::Windows::Storage::Provider::StorageProviderItemPropertyDefinition*> : IVector_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Storage::Provider::StorageProviderItemPropertyDefinition*, ABI::Windows::Storage::Provider::IStorageProviderItemPropertyDefinition*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IVector`1<Windows.Storage.Provider.StorageProviderItemPropertyDefinition>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IVector<ABI::Windows::Storage::Provider::StorageProviderItemPropertyDefinition*> __FIVector_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition_t;
#define __FIVector_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition ABI::Windows::Foundation::Collections::__FIVector_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIVector_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition_USE */

#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000

namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                class CachedFileUpdaterUI;
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#ifndef DEF___FITypedEventHandler_2_Windows__CStorage__CProvider__CCachedFileUpdaterUI_IInspectable_USE
#define DEF___FITypedEventHandler_2_Windows__CStorage__CProvider__CCachedFileUpdaterUI_IInspectable_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation {
template <>
struct __declspec(uuid("45fdd443-c0b9-57b0-a84f-7d876edc3149"))
ITypedEventHandler<ABI::Windows::Storage::Provider::CachedFileUpdaterUI*, IInspectable*> : ITypedEventHandler_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Storage::Provider::CachedFileUpdaterUI*, ABI::Windows::Storage::Provider::ICachedFileUpdaterUI*>, IInspectable*>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.TypedEventHandler`2<Windows.Storage.Provider.CachedFileUpdaterUI, Object>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef ITypedEventHandler<ABI::Windows::Storage::Provider::CachedFileUpdaterUI*, IInspectable*> __FITypedEventHandler_2_Windows__CStorage__CProvider__CCachedFileUpdaterUI_IInspectable_t;
#define __FITypedEventHandler_2_Windows__CStorage__CProvider__CCachedFileUpdaterUI_IInspectable ABI::Windows::Foundation::__FITypedEventHandler_2_Windows__CStorage__CProvider__CCachedFileUpdaterUI_IInspectable_t
/* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FITypedEventHandler_2_Windows__CStorage__CProvider__CCachedFileUpdaterUI_IInspectable_USE */

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                class FileUpdateRequestedEventArgs;
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#ifndef DEF___FITypedEventHandler_2_Windows__CStorage__CProvider__CCachedFileUpdaterUI_Windows__CStorage__CProvider__CFileUpdateRequestedEventArgs_USE
#define DEF___FITypedEventHandler_2_Windows__CStorage__CProvider__CCachedFileUpdaterUI_Windows__CStorage__CProvider__CFileUpdateRequestedEventArgs_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation {
template <>
struct __declspec(uuid("ed56ab72-ebd3-52c8-b0ac-987d30090351"))
ITypedEventHandler<ABI::Windows::Storage::Provider::CachedFileUpdaterUI*, ABI::Windows::Storage::Provider::FileUpdateRequestedEventArgs*> : ITypedEventHandler_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Storage::Provider::CachedFileUpdaterUI*, ABI::Windows::Storage::Provider::ICachedFileUpdaterUI*>, ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Storage::Provider::FileUpdateRequestedEventArgs*, ABI::Windows::Storage::Provider::IFileUpdateRequestedEventArgs*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.TypedEventHandler`2<Windows.Storage.Provider.CachedFileUpdaterUI, Windows.Storage.Provider.FileUpdateRequestedEventArgs>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef ITypedEventHandler<ABI::Windows::Storage::Provider::CachedFileUpdaterUI*, ABI::Windows::Storage::Provider::FileUpdateRequestedEventArgs*> __FITypedEventHandler_2_Windows__CStorage__CProvider__CCachedFileUpdaterUI_Windows__CStorage__CProvider__CFileUpdateRequestedEventArgs_t;
#define __FITypedEventHandler_2_Windows__CStorage__CProvider__CCachedFileUpdaterUI_Windows__CStorage__CProvider__CFileUpdateRequestedEventArgs ABI::Windows::Foundation::__FITypedEventHandler_2_Windows__CStorage__CProvider__CCachedFileUpdaterUI_Windows__CStorage__CProvider__CFileUpdateRequestedEventArgs_t
/* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FITypedEventHandler_2_Windows__CStorage__CProvider__CCachedFileUpdaterUI_Windows__CStorage__CProvider__CFileUpdateRequestedEventArgs_USE */

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x50000

#ifndef DEF___FITypedEventHandler_2_Windows__CStorage__CProvider__CIStorageProviderStatusSource_IInspectable_USE
#define DEF___FITypedEventHandler_2_Windows__CStorage__CProvider__CIStorageProviderStatusSource_IInspectable_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation {
template <>
struct __declspec(uuid("c829a1b2-e1b7-51cf-ab19-21b427e642a8"))
ITypedEventHandler<ABI::Windows::Storage::Provider::IStorageProviderStatusSource*, IInspectable*> : ITypedEventHandler_impl<ABI::Windows::Storage::Provider::IStorageProviderStatusSource*, IInspectable*>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.TypedEventHandler`2<Windows.Storage.Provider.IStorageProviderStatusSource, Object>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef ITypedEventHandler<ABI::Windows::Storage::Provider::IStorageProviderStatusSource*, IInspectable*> __FITypedEventHandler_2_Windows__CStorage__CProvider__CIStorageProviderStatusSource_IInspectable_t;
#define __FITypedEventHandler_2_Windows__CStorage__CProvider__CIStorageProviderStatusSource_IInspectable ABI::Windows::Foundation::__FITypedEventHandler_2_Windows__CStorage__CProvider__CIStorageProviderStatusSource_IInspectable_t
/* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FITypedEventHandler_2_Windows__CStorage__CProvider__CIStorageProviderStatusSource_IInspectable_USE */

#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x50000

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

#ifndef ____x_ABI_CWindows_CStorage_CIStorageFile_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CIStorageFile_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Storage {
            interface IStorageFile;
        } /* Storage */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CStorage_CIStorageFile ABI::Windows::Storage::IStorageFile

#endif // ____x_ABI_CWindows_CStorage_CIStorageFile_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CStorage_CIStorageFolder_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CIStorageFolder_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Storage {
            interface IStorageFolder;
        } /* Storage */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CStorage_CIStorageFolder ABI::Windows::Storage::IStorageFolder

#endif // ____x_ABI_CWindows_CStorage_CIStorageFolder_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CStorage_CIStorageItem_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CIStorageItem_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Storage {
            interface IStorageItem;
        } /* Storage */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CStorage_CIStorageItem ABI::Windows::Storage::IStorageItem

#endif // ____x_ABI_CWindows_CStorage_CIStorageItem_FWD_DEFINED__

namespace ABI {
    namespace Windows {
        namespace Storage {
            class StorageFile;
        } /* Storage */
    } /* Windows */
} /* ABI */

#ifndef ____x_ABI_CWindows_CStorage_CStreams_CIBuffer_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CStreams_CIBuffer_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Streams {
                interface IBuffer;
            } /* Streams */
        } /* Storage */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CStorage_CStreams_CIBuffer ABI::Windows::Storage::Streams::IBuffer

#endif // ____x_ABI_CWindows_CStorage_CStreams_CIBuffer_FWD_DEFINED__

namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                typedef enum CachedFileOptions : unsigned int CachedFileOptions;
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                typedef enum CachedFileTarget : int CachedFileTarget;
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                typedef enum FileUpdateStatus : int FileUpdateStatus;
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                typedef enum ReadActivationMode : int ReadActivationMode;
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                typedef enum StorageProviderHardlinkPolicy : unsigned int StorageProviderHardlinkPolicy;
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                typedef enum StorageProviderHydrationPolicy : int StorageProviderHydrationPolicy;
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                typedef enum StorageProviderHydrationPolicyModifier : unsigned int StorageProviderHydrationPolicyModifier;
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                typedef enum StorageProviderInSyncPolicy : unsigned int StorageProviderInSyncPolicy;
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                typedef enum StorageProviderPopulationPolicy : int StorageProviderPopulationPolicy;
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                typedef enum StorageProviderProtectionMode : int StorageProviderProtectionMode;
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                typedef enum StorageProviderState : int StorageProviderState;
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                typedef enum StorageProviderUriSourceStatus : int StorageProviderUriSourceStatus;
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                typedef enum UIStatus : int UIStatus;
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                typedef enum WriteActivationMode : int WriteActivationMode;
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                class FileUpdateRequest;
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                class FileUpdateRequestDeferral;
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                class StorageProviderErrorCommand;
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                class StorageProviderGetContentInfoForPathResult;
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                class StorageProviderGetPathForContentUriResult;
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                class StorageProviderStatus;
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */

/*
 *
 * Struct Windows.Storage.Provider.CachedFileOptions
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                enum CachedFileOptions : unsigned int
                {
                    CachedFileOptions_None = 0,
                    CachedFileOptions_RequireUpdateOnAccess = 0x1,
                    CachedFileOptions_UseCachedFileWhenOffline = 0x2,
                    CachedFileOptions_DenyAccessWhenOffline = 0x4,
                };

                DEFINE_ENUM_FLAG_OPERATORS(CachedFileOptions)
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Struct Windows.Storage.Provider.CachedFileTarget
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                enum CachedFileTarget : int
                {
                    CachedFileTarget_Local = 0,
                    CachedFileTarget_Remote = 1,
                };
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Struct Windows.Storage.Provider.FileUpdateStatus
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                enum FileUpdateStatus : int
                {
                    FileUpdateStatus_Incomplete = 0,
                    FileUpdateStatus_Complete = 1,
                    FileUpdateStatus_UserInputNeeded = 2,
                    FileUpdateStatus_CurrentlyUnavailable = 3,
                    FileUpdateStatus_Failed = 4,
                    FileUpdateStatus_CompleteAndRenamed = 5,
                };
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Struct Windows.Storage.Provider.ReadActivationMode
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                enum ReadActivationMode : int
                {
                    ReadActivationMode_NotNeeded = 0,
                    ReadActivationMode_BeforeAccess = 1,
                };
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Struct Windows.Storage.Provider.StorageProviderHardlinkPolicy
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 1.0
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                enum StorageProviderHardlinkPolicy : unsigned int
                {
                    StorageProviderHardlinkPolicy_None = 0,
                    StorageProviderHardlinkPolicy_Allowed = 0x1,
                };

                DEFINE_ENUM_FLAG_OPERATORS(StorageProviderHardlinkPolicy)
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000

/*
 *
 * Struct Windows.Storage.Provider.StorageProviderHydrationPolicy
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 1.0
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                enum StorageProviderHydrationPolicy : int
                {
                    StorageProviderHydrationPolicy_Partial = 0,
                    StorageProviderHydrationPolicy_Progressive = 1,
                    StorageProviderHydrationPolicy_Full = 2,
                    StorageProviderHydrationPolicy_AlwaysFull = 3,
                };
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000

/*
 *
 * Struct Windows.Storage.Provider.StorageProviderHydrationPolicyModifier
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 1.0
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                enum StorageProviderHydrationPolicyModifier : unsigned int
                {
                    StorageProviderHydrationPolicyModifier_None = 0,
                    StorageProviderHydrationPolicyModifier_ValidationRequired = 0x1,
                    StorageProviderHydrationPolicyModifier_StreamingAllowed = 0x2,
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x30000
                    StorageProviderHydrationPolicyModifier_AutoDehydrationAllowed = 0x4,
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x30000
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x60000
                    StorageProviderHydrationPolicyModifier_AllowFullRestartHydration = 0x8,
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x60000
                };

                DEFINE_ENUM_FLAG_OPERATORS(StorageProviderHydrationPolicyModifier)
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000

/*
 *
 * Struct Windows.Storage.Provider.StorageProviderInSyncPolicy
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 1.0
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                enum StorageProviderInSyncPolicy : unsigned int
                {
                    StorageProviderInSyncPolicy_Default = 0,
                    StorageProviderInSyncPolicy_FileCreationTime = 0x1,
                    StorageProviderInSyncPolicy_FileReadOnlyAttribute = 0x2,
                    StorageProviderInSyncPolicy_FileHiddenAttribute = 0x4,
                    StorageProviderInSyncPolicy_FileSystemAttribute = 0x8,
                    StorageProviderInSyncPolicy_DirectoryCreationTime = 0x10,
                    StorageProviderInSyncPolicy_DirectoryReadOnlyAttribute = 0x20,
                    StorageProviderInSyncPolicy_DirectoryHiddenAttribute = 0x40,
                    StorageProviderInSyncPolicy_DirectorySystemAttribute = 0x80,
                    StorageProviderInSyncPolicy_FileLastWriteTime = 0x100,
                    StorageProviderInSyncPolicy_DirectoryLastWriteTime = 0x200,
                    StorageProviderInSyncPolicy_PreserveInsyncForSyncEngine = 0x80000000,
                };

                DEFINE_ENUM_FLAG_OPERATORS(StorageProviderInSyncPolicy)
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000

/*
 *
 * Struct Windows.Storage.Provider.StorageProviderPopulationPolicy
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 1.0
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                enum StorageProviderPopulationPolicy : int
                {
                    StorageProviderPopulationPolicy_Full = 1,
                    StorageProviderPopulationPolicy_AlwaysFull = 2,
                };
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000

/*
 *
 * Struct Windows.Storage.Provider.StorageProviderProtectionMode
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 1.0
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                enum StorageProviderProtectionMode : int
                {
                    StorageProviderProtectionMode_Unknown = 0,
                    StorageProviderProtectionMode_Personal = 1,
                };
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000

/*
 *
 * Struct Windows.Storage.Provider.StorageProviderState
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 5.0
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x50000
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                enum StorageProviderState : int
                {
                    StorageProviderState_InSync = 0,
                    StorageProviderState_Syncing = 1,
                    StorageProviderState_Paused = 2,
                    StorageProviderState_Error = 3,
                    StorageProviderState_Warning = 4,
                    StorageProviderState_Offline = 5,
                };
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x50000

/*
 *
 * Struct Windows.Storage.Provider.StorageProviderUriSourceStatus
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 2.0
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x20000
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                enum StorageProviderUriSourceStatus : int
                {
                    StorageProviderUriSourceStatus_Success = 0,
                    StorageProviderUriSourceStatus_NoSyncRoot = 1,
                    StorageProviderUriSourceStatus_FileNotFound = 2,
                };
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x20000

/*
 *
 * Struct Windows.Storage.Provider.UIStatus
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                enum UIStatus : int
                {
                    UIStatus_Unavailable = 0,
                    UIStatus_Hidden = 1,
                    UIStatus_Visible = 2,
                    UIStatus_Complete = 3,
                };
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Struct Windows.Storage.Provider.WriteActivationMode
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                enum WriteActivationMode : int
                {
                    WriteActivationMode_ReadOnly = 0,
                    WriteActivationMode_NotNeeded = 1,
                    WriteActivationMode_AfterWrite = 2,
                };
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Storage.Provider.ICachedFileUpdaterStatics
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Storage.Provider.CachedFileUpdater
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Storage_Provider_ICachedFileUpdaterStatics[] = L"Windows.Storage.Provider.ICachedFileUpdaterStatics";
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                MIDL_INTERFACE("9fc90920-7bcf-4888-a81e-102d7034d7ce")
                ICachedFileUpdaterStatics : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE SetUpdateInformation(
                        ABI::Windows::Storage::IStorageFile* file,
                        HSTRING contentId,
                        ABI::Windows::Storage::Provider::ReadActivationMode readMode,
                        ABI::Windows::Storage::Provider::WriteActivationMode writeMode,
                        ABI::Windows::Storage::Provider::CachedFileOptions options
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_ICachedFileUpdaterStatics = _uuidof(ICachedFileUpdaterStatics);
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterStatics;
#endif /* !defined(____x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterStatics_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Storage.Provider.ICachedFileUpdaterUI
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Storage.Provider.CachedFileUpdaterUI
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Storage_Provider_ICachedFileUpdaterUI[] = L"Windows.Storage.Provider.ICachedFileUpdaterUI";
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                MIDL_INTERFACE("9e6f41e6-baf2-4a97-b600-9333f5df80fd")
                ICachedFileUpdaterUI : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE get_Title(
                        HSTRING* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_Title(
                        HSTRING value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_UpdateTarget(
                        ABI::Windows::Storage::Provider::CachedFileTarget* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE add_FileUpdateRequested(
                        __FITypedEventHandler_2_Windows__CStorage__CProvider__CCachedFileUpdaterUI_Windows__CStorage__CProvider__CFileUpdateRequestedEventArgs* handler,
                        EventRegistrationToken* token
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE remove_FileUpdateRequested(
                        EventRegistrationToken token
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE add_UIRequested(
                        __FITypedEventHandler_2_Windows__CStorage__CProvider__CCachedFileUpdaterUI_IInspectable* handler,
                        EventRegistrationToken* token
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE remove_UIRequested(
                        EventRegistrationToken token
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_UIStatus(
                        ABI::Windows::Storage::Provider::UIStatus* value
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_ICachedFileUpdaterUI = _uuidof(ICachedFileUpdaterUI);
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI;
#endif /* !defined(____x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Storage.Provider.ICachedFileUpdaterUI2
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Storage.Provider.CachedFileUpdaterUI
 *
 * Any object which implements this interface must also implement the following interfaces:
 *     Windows.Storage.Provider.ICachedFileUpdaterUI
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI2_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI2_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Storage_Provider_ICachedFileUpdaterUI2[] = L"Windows.Storage.Provider.ICachedFileUpdaterUI2";
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                MIDL_INTERFACE("8856a21c-8699-4340-9f49-f7cad7fe8991")
                ICachedFileUpdaterUI2 : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE get_UpdateRequest(
                        ABI::Windows::Storage::Provider::IFileUpdateRequest** value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE GetDeferral(
                        ABI::Windows::Storage::Provider::IFileUpdateRequestDeferral** value
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_ICachedFileUpdaterUI2 = _uuidof(ICachedFileUpdaterUI2);
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI2;
#endif /* !defined(____x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI2_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Storage.Provider.IFileUpdateRequest
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Storage.Provider.FileUpdateRequest
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Storage_Provider_IFileUpdateRequest[] = L"Windows.Storage.Provider.IFileUpdateRequest";
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                MIDL_INTERFACE("40c82536-c1fe-4d93-a792-1e736bc70837")
                IFileUpdateRequest : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE get_ContentId(
                        HSTRING* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_File(
                        ABI::Windows::Storage::IStorageFile** value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_Status(
                        ABI::Windows::Storage::Provider::FileUpdateStatus* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_Status(
                        ABI::Windows::Storage::Provider::FileUpdateStatus value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE GetDeferral(
                        ABI::Windows::Storage::Provider::IFileUpdateRequestDeferral** value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE UpdateLocalFile(
                        ABI::Windows::Storage::IStorageFile* value
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IFileUpdateRequest = _uuidof(IFileUpdateRequest);
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest;
#endif /* !defined(____x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Storage.Provider.IFileUpdateRequest2
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Storage.Provider.FileUpdateRequest
 *
 * Any object which implements this interface must also implement the following interfaces:
 *     Windows.Storage.Provider.IFileUpdateRequest
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest2_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest2_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Storage_Provider_IFileUpdateRequest2[] = L"Windows.Storage.Provider.IFileUpdateRequest2";
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                MIDL_INTERFACE("82484648-bdbe-447b-a2ee-7afe6a032a94")
                IFileUpdateRequest2 : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE get_UserInputNeededMessage(
                        HSTRING* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_UserInputNeededMessage(
                        HSTRING value
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IFileUpdateRequest2 = _uuidof(IFileUpdateRequest2);
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest2;
#endif /* !defined(____x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest2_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Storage.Provider.IFileUpdateRequestDeferral
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Storage.Provider.FileUpdateRequestDeferral
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequestDeferral_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequestDeferral_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Storage_Provider_IFileUpdateRequestDeferral[] = L"Windows.Storage.Provider.IFileUpdateRequestDeferral";
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                MIDL_INTERFACE("ffcedb2b-8ade-44a5-bb00-164c4e72f13a")
                IFileUpdateRequestDeferral : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE Complete(void) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IFileUpdateRequestDeferral = _uuidof(IFileUpdateRequestDeferral);
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequestDeferral;
#endif /* !defined(____x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequestDeferral_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Storage.Provider.IFileUpdateRequestedEventArgs
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Storage.Provider.FileUpdateRequestedEventArgs
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequestedEventArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequestedEventArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Storage_Provider_IFileUpdateRequestedEventArgs[] = L"Windows.Storage.Provider.IFileUpdateRequestedEventArgs";
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                MIDL_INTERFACE("7b0a9342-3905-438d-aaef-78ae265f8dd2")
                IFileUpdateRequestedEventArgs : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE get_Request(
                        ABI::Windows::Storage::Provider::IFileUpdateRequest** value
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IFileUpdateRequestedEventArgs = _uuidof(IFileUpdateRequestedEventArgs);
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequestedEventArgs;
#endif /* !defined(____x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequestedEventArgs_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Storage.Provider.IStorageProviderError
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 5.0
 *
 * Interface is a part of the implementation of type Windows.Storage.Provider.StorageProviderError
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderError_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderError_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Storage_Provider_IStorageProviderError[] = L"Windows.Storage.Provider.IStorageProviderError";
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                MIDL_INTERFACE("47f2780b-ef7f-5910-bf83-331d89256615")
                IStorageProviderError : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE get_Id(
                        HSTRING* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_Title(
                        HSTRING* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_Message(
                        HSTRING* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_FilePath(
                        HSTRING* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_FilePath(
                        HSTRING value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_PrimaryAction(
                        ABI::Windows::Storage::Provider::IStorageProviderErrorCommand** value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_PrimaryAction(
                        ABI::Windows::Storage::Provider::IStorageProviderErrorCommand* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_SecondaryAction(
                        ABI::Windows::Storage::Provider::IStorageProviderErrorCommand** value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_SecondaryAction(
                        ABI::Windows::Storage::Provider::IStorageProviderErrorCommand* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_InformationalLink(
                        ABI::Windows::Storage::Provider::IStorageProviderErrorCommand** value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_InformationalLink(
                        ABI::Windows::Storage::Provider::IStorageProviderErrorCommand* value
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IStorageProviderError = _uuidof(IStorageProviderError);
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CStorage_CProvider_CIStorageProviderError;
#endif /* !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderError_INTERFACE_DEFINED__) */
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x50000

/*
 *
 * Interface Windows.Storage.Provider.IStorageProviderErrorCommand
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 5.0
 *
 * Interface is a part of the implementation of type Windows.Storage.Provider.StorageProviderErrorCommand
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommand_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommand_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Storage_Provider_IStorageProviderErrorCommand[] = L"Windows.Storage.Provider.IStorageProviderErrorCommand";
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                MIDL_INTERFACE("b6b18aed-bb65-5f26-86e4-1d3e34d54477")
                IStorageProviderErrorCommand : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE get_Label(
                        HSTRING* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_ActionUri(
                        ABI::Windows::Foundation::IUriRuntimeClass** value
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IStorageProviderErrorCommand = _uuidof(IStorageProviderErrorCommand);
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommand;
#endif /* !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommand_INTERFACE_DEFINED__) */
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x50000

/*
 *
 * Interface Windows.Storage.Provider.IStorageProviderErrorCommandFactory
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 5.0
 *
 * Interface is a part of the implementation of type Windows.Storage.Provider.StorageProviderErrorCommand
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommandFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommandFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Storage_Provider_IStorageProviderErrorCommandFactory[] = L"Windows.Storage.Provider.IStorageProviderErrorCommandFactory";
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                MIDL_INTERFACE("ecc1f555-3ab4-556f-8bb2-7e5515eed8dc")
                IStorageProviderErrorCommandFactory : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE CreateInstance(
                        HSTRING label,
                        ABI::Windows::Foundation::IUriRuntimeClass* actionUri,
                        ABI::Windows::Storage::Provider::IStorageProviderErrorCommand** value
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IStorageProviderErrorCommandFactory = _uuidof(IStorageProviderErrorCommandFactory);
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommandFactory;
#endif /* !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommandFactory_INTERFACE_DEFINED__) */
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x50000

/*
 *
 * Interface Windows.Storage.Provider.IStorageProviderErrorFactory
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 5.0
 *
 * Interface is a part of the implementation of type Windows.Storage.Provider.StorageProviderError
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Storage_Provider_IStorageProviderErrorFactory[] = L"Windows.Storage.Provider.IStorageProviderErrorFactory";
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                MIDL_INTERFACE("97d6f240-61ab-51dc-9921-18bd0dbef79e")
                IStorageProviderErrorFactory : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE CreateInstance(
                        HSTRING id,
                        HSTRING title,
                        HSTRING message,
                        ABI::Windows::Storage::Provider::IStorageProviderError** value
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IStorageProviderErrorFactory = _uuidof(IStorageProviderErrorFactory);
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorFactory;
#endif /* !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorFactory_INTERFACE_DEFINED__) */
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x50000

/*
 *
 * Interface Windows.Storage.Provider.IStorageProviderFileTypeInfo
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 4.0
 *
 * Interface is a part of the implementation of type Windows.Storage.Provider.StorageProviderFileTypeInfo
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x40000
#if !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfo_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfo_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Storage_Provider_IStorageProviderFileTypeInfo[] = L"Windows.Storage.Provider.IStorageProviderFileTypeInfo";
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                MIDL_INTERFACE("1955b9c1-0184-5a88-87df-4544f464365d")
                IStorageProviderFileTypeInfo : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE get_FileExtension(
                        HSTRING* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_IconResource(
                        HSTRING* value
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IStorageProviderFileTypeInfo = _uuidof(IStorageProviderFileTypeInfo);
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfo;
#endif /* !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfo_INTERFACE_DEFINED__) */
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x40000

/*
 *
 * Interface Windows.Storage.Provider.IStorageProviderFileTypeInfoFactory
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 4.0
 *
 * Interface is a part of the implementation of type Windows.Storage.Provider.StorageProviderFileTypeInfo
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x40000
#if !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfoFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfoFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Storage_Provider_IStorageProviderFileTypeInfoFactory[] = L"Windows.Storage.Provider.IStorageProviderFileTypeInfoFactory";
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                MIDL_INTERFACE("3fa12c6f-cce6-5d5d-80b1-389e7cf92dbf")
                IStorageProviderFileTypeInfoFactory : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE CreateInstance(
                        HSTRING fileExtension,
                        HSTRING iconResource,
                        ABI::Windows::Storage::Provider::IStorageProviderFileTypeInfo** value
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IStorageProviderFileTypeInfoFactory = _uuidof(IStorageProviderFileTypeInfoFactory);
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfoFactory;
#endif /* !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfoFactory_INTERFACE_DEFINED__) */
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x40000

/*
 *
 * Interface Windows.Storage.Provider.IStorageProviderGetContentInfoForPathResult
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 2.0
 *
 * Interface is a part of the implementation of type Windows.Storage.Provider.StorageProviderGetContentInfoForPathResult
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x20000
#if !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetContentInfoForPathResult_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetContentInfoForPathResult_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Storage_Provider_IStorageProviderGetContentInfoForPathResult[] = L"Windows.Storage.Provider.IStorageProviderGetContentInfoForPathResult";
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                MIDL_INTERFACE("2564711d-aa89-4d12-82e3-f72a92e33966")
                IStorageProviderGetContentInfoForPathResult : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE get_Status(
                        ABI::Windows::Storage::Provider::StorageProviderUriSourceStatus* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_Status(
                        ABI::Windows::Storage::Provider::StorageProviderUriSourceStatus value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_ContentUri(
                        HSTRING* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_ContentUri(
                        HSTRING value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_ContentId(
                        HSTRING* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_ContentId(
                        HSTRING value
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IStorageProviderGetContentInfoForPathResult = _uuidof(IStorageProviderGetContentInfoForPathResult);
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetContentInfoForPathResult;
#endif /* !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetContentInfoForPathResult_INTERFACE_DEFINED__) */
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x20000

/*
 *
 * Interface Windows.Storage.Provider.IStorageProviderGetPathForContentUriResult
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 2.0
 *
 * Interface is a part of the implementation of type Windows.Storage.Provider.StorageProviderGetPathForContentUriResult
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x20000
#if !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetPathForContentUriResult_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetPathForContentUriResult_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Storage_Provider_IStorageProviderGetPathForContentUriResult[] = L"Windows.Storage.Provider.IStorageProviderGetPathForContentUriResult";
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                MIDL_INTERFACE("63711a9d-4118-45a6-acb6-22c49d019f40")
                IStorageProviderGetPathForContentUriResult : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE get_Status(
                        ABI::Windows::Storage::Provider::StorageProviderUriSourceStatus* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_Status(
                        ABI::Windows::Storage::Provider::StorageProviderUriSourceStatus value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_Path(
                        HSTRING* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_Path(
                        HSTRING value
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IStorageProviderGetPathForContentUriResult = _uuidof(IStorageProviderGetPathForContentUriResult);
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetPathForContentUriResult;
#endif /* !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetPathForContentUriResult_INTERFACE_DEFINED__) */
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x20000

/*
 *
 * Interface Windows.Storage.Provider.IStorageProviderHandlerFactory
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 5.0
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderHandlerFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderHandlerFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Storage_Provider_IStorageProviderHandlerFactory[] = L"Windows.Storage.Provider.IStorageProviderHandlerFactory";
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                MIDL_INTERFACE("6154dc3a-fc1d-5aae-9e23-e8659a22c5f6")
                IStorageProviderHandlerFactory : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE GetStatusSource(
                        HSTRING syncRootId,
                        ABI::Windows::Storage::Provider::IStorageProviderStatusSource** result
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IStorageProviderHandlerFactory = _uuidof(IStorageProviderHandlerFactory);
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CStorage_CProvider_CIStorageProviderHandlerFactory;
#endif /* !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderHandlerFactory_INTERFACE_DEFINED__) */
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x50000

/*
 *
 * Interface Windows.Storage.Provider.IStorageProviderItemPropertiesStatics
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Storage.Provider.StorageProviderItemProperties
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertiesStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertiesStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Storage_Provider_IStorageProviderItemPropertiesStatics[] = L"Windows.Storage.Provider.IStorageProviderItemPropertiesStatics";
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                MIDL_INTERFACE("2d2c1c97-2704-4729-8fa9-7e6b8e158c2f")
                IStorageProviderItemPropertiesStatics : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE SetAsync(
                        ABI::Windows::Storage::IStorageItem* item,
                        __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderItemProperty* itemProperties,
                        ABI::Windows::Foundation::IAsyncAction** operation
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IStorageProviderItemPropertiesStatics = _uuidof(IStorageProviderItemPropertiesStatics);
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertiesStatics;
#endif /* !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertiesStatics_INTERFACE_DEFINED__) */
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Storage.Provider.IStorageProviderItemProperty
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Storage.Provider.StorageProviderItemProperty
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemProperty_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemProperty_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Storage_Provider_IStorageProviderItemProperty[] = L"Windows.Storage.Provider.IStorageProviderItemProperty";
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                MIDL_INTERFACE("476cb558-730b-4188-b7b5-63b716ed476d")
                IStorageProviderItemProperty : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE put_Id(
                        INT32 value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_Id(
                        INT32* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_Value(
                        HSTRING value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_Value(
                        HSTRING* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_IconResource(
                        HSTRING value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_IconResource(
                        HSTRING* value
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IStorageProviderItemProperty = _uuidof(IStorageProviderItemProperty);
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemProperty;
#endif /* !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemProperty_INTERFACE_DEFINED__) */
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Storage.Provider.IStorageProviderItemPropertyDefinition
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Storage.Provider.StorageProviderItemPropertyDefinition
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertyDefinition_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertyDefinition_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Storage_Provider_IStorageProviderItemPropertyDefinition[] = L"Windows.Storage.Provider.IStorageProviderItemPropertyDefinition";
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                MIDL_INTERFACE("c5b383bb-ff1f-4298-831e-ff1c08089690")
                IStorageProviderItemPropertyDefinition : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE get_Id(
                        INT32* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_Id(
                        INT32 value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_DisplayNameResource(
                        HSTRING* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_DisplayNameResource(
                        HSTRING value
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IStorageProviderItemPropertyDefinition = _uuidof(IStorageProviderItemPropertyDefinition);
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertyDefinition;
#endif /* !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertyDefinition_INTERFACE_DEFINED__) */
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Storage.Provider.IStorageProviderItemPropertySource
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 1.0
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertySource_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertySource_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Storage_Provider_IStorageProviderItemPropertySource[] = L"Windows.Storage.Provider.IStorageProviderItemPropertySource";
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                MIDL_INTERFACE("8f6f9c3e-f632-4a9b-8d99-d2d7a11df56a")
                IStorageProviderItemPropertySource : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE GetItemProperties(
                        HSTRING itemPath,
                        __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderItemProperty** result
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IStorageProviderItemPropertySource = _uuidof(IStorageProviderItemPropertySource);
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertySource;
#endif /* !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertySource_INTERFACE_DEFINED__) */
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Storage.Provider.IStorageProviderPropertyCapabilities
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 1.0
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderPropertyCapabilities_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderPropertyCapabilities_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Storage_Provider_IStorageProviderPropertyCapabilities[] = L"Windows.Storage.Provider.IStorageProviderPropertyCapabilities";
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                MIDL_INTERFACE("658d2f0e-63b7-4567-acf9-51abe301dda5")
                IStorageProviderPropertyCapabilities : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE IsPropertySupported(
                        HSTRING propertyCanonicalName,
                        boolean* isSupported
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IStorageProviderPropertyCapabilities = _uuidof(IStorageProviderPropertyCapabilities);
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CStorage_CProvider_CIStorageProviderPropertyCapabilities;
#endif /* !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderPropertyCapabilities_INTERFACE_DEFINED__) */
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Storage.Provider.IStorageProviderStatus
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 5.0
 *
 * Interface is a part of the implementation of type Windows.Storage.Provider.StorageProviderStatus
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatus_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatus_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Storage_Provider_IStorageProviderStatus[] = L"Windows.Storage.Provider.IStorageProviderStatus";
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                MIDL_INTERFACE("ff6e761d-fb8b-56c3-9e7a-05309d191fb4")
                IStorageProviderStatus : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE get_Message(
                        HSTRING* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_State(
                        ABI::Windows::Storage::Provider::StorageProviderState* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_ErrorMessages(
                        __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderError** value
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IStorageProviderStatus = _uuidof(IStorageProviderStatus);
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatus;
#endif /* !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatus_INTERFACE_DEFINED__) */
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x50000

/*
 *
 * Interface Windows.Storage.Provider.IStorageProviderStatusFactory
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 5.0
 *
 * Interface is a part of the implementation of type Windows.Storage.Provider.StorageProviderStatus
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Storage_Provider_IStorageProviderStatusFactory[] = L"Windows.Storage.Provider.IStorageProviderStatusFactory";
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                MIDL_INTERFACE("d64828c5-9b7a-5fa4-b126-90bd18936c7f")
                IStorageProviderStatusFactory : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE CreateInstance(
                        ABI::Windows::Storage::Provider::StorageProviderState state,
                        HSTRING message,
                        ABI::Windows::Storage::Provider::IStorageProviderStatus** value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE CreateInstance2(
                        ABI::Windows::Storage::Provider::StorageProviderState state,
                        HSTRING message,
                        __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderError* errorMessages,
                        ABI::Windows::Storage::Provider::IStorageProviderStatus** value
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IStorageProviderStatusFactory = _uuidof(IStorageProviderStatusFactory);
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusFactory;
#endif /* !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusFactory_INTERFACE_DEFINED__) */
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x50000

/*
 *
 * Interface Windows.Storage.Provider.IStorageProviderStatusSource
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 5.0
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusSource_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusSource_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Storage_Provider_IStorageProviderStatusSource[] = L"Windows.Storage.Provider.IStorageProviderStatusSource";
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                MIDL_INTERFACE("2e316bb2-fd43-5335-b3c4-a962ee31d17e")
                IStorageProviderStatusSource : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE GetStatus(
                        ABI::Windows::Storage::Provider::IStorageProviderStatus** result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE add_Changed(
                        __FITypedEventHandler_2_Windows__CStorage__CProvider__CIStorageProviderStatusSource_IInspectable* handler,
                        EventRegistrationToken* token
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE remove_Changed(
                        EventRegistrationToken token
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IStorageProviderStatusSource = _uuidof(IStorageProviderStatusSource);
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusSource;
#endif /* !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusSource_INTERFACE_DEFINED__) */
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x50000

/*
 *
 * Interface Windows.Storage.Provider.IStorageProviderSyncRootInfo
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Storage.Provider.StorageProviderSyncRootInfo
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Storage_Provider_IStorageProviderSyncRootInfo[] = L"Windows.Storage.Provider.IStorageProviderSyncRootInfo";
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                MIDL_INTERFACE("7c1305c4-99f9-41ac-8904-ab055d654926")
                IStorageProviderSyncRootInfo : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE get_Id(
                        HSTRING* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_Id(
                        HSTRING value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_Context(
                        ABI::Windows::Storage::Streams::IBuffer** value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_Context(
                        ABI::Windows::Storage::Streams::IBuffer* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_Path(
                        ABI::Windows::Storage::IStorageFolder** value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_Path(
                        ABI::Windows::Storage::IStorageFolder* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_DisplayNameResource(
                        HSTRING* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_DisplayNameResource(
                        HSTRING value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_IconResource(
                        HSTRING* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_IconResource(
                        HSTRING value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_HydrationPolicy(
                        ABI::Windows::Storage::Provider::StorageProviderHydrationPolicy* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_HydrationPolicy(
                        ABI::Windows::Storage::Provider::StorageProviderHydrationPolicy value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_HydrationPolicyModifier(
                        ABI::Windows::Storage::Provider::StorageProviderHydrationPolicyModifier* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_HydrationPolicyModifier(
                        ABI::Windows::Storage::Provider::StorageProviderHydrationPolicyModifier value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_PopulationPolicy(
                        ABI::Windows::Storage::Provider::StorageProviderPopulationPolicy* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_PopulationPolicy(
                        ABI::Windows::Storage::Provider::StorageProviderPopulationPolicy value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_InSyncPolicy(
                        ABI::Windows::Storage::Provider::StorageProviderInSyncPolicy* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_InSyncPolicy(
                        ABI::Windows::Storage::Provider::StorageProviderInSyncPolicy value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_HardlinkPolicy(
                        ABI::Windows::Storage::Provider::StorageProviderHardlinkPolicy* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_HardlinkPolicy(
                        ABI::Windows::Storage::Provider::StorageProviderHardlinkPolicy value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_ShowSiblingsAsGroup(
                        boolean* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_ShowSiblingsAsGroup(
                        boolean value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_Version(
                        HSTRING* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_Version(
                        HSTRING value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_ProtectionMode(
                        ABI::Windows::Storage::Provider::StorageProviderProtectionMode* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_ProtectionMode(
                        ABI::Windows::Storage::Provider::StorageProviderProtectionMode value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_AllowPinning(
                        boolean* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_AllowPinning(
                        boolean value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_StorageProviderItemPropertyDefinitions(
                        __FIVector_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition** value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_RecycleBinUri(
                        ABI::Windows::Foundation::IUriRuntimeClass** value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_RecycleBinUri(
                        ABI::Windows::Foundation::IUriRuntimeClass* value
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IStorageProviderSyncRootInfo = _uuidof(IStorageProviderSyncRootInfo);
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo;
#endif /* !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo_INTERFACE_DEFINED__) */
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Storage.Provider.IStorageProviderSyncRootInfo2
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 3.0
 *
 * Interface is a part of the implementation of type Windows.Storage.Provider.StorageProviderSyncRootInfo
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x30000
#if !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo2_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo2_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Storage_Provider_IStorageProviderSyncRootInfo2[] = L"Windows.Storage.Provider.IStorageProviderSyncRootInfo2";
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                MIDL_INTERFACE("cf51b023-7cf1-5166-bdba-efd95f529e31")
                IStorageProviderSyncRootInfo2 : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE get_ProviderId(
                        GUID* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_ProviderId(
                        GUID value
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IStorageProviderSyncRootInfo2 = _uuidof(IStorageProviderSyncRootInfo2);
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo2;
#endif /* !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo2_INTERFACE_DEFINED__) */
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x30000

/*
 *
 * Interface Windows.Storage.Provider.IStorageProviderSyncRootInfo3
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 4.0
 *
 * Interface is a part of the implementation of type Windows.Storage.Provider.StorageProviderSyncRootInfo
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x40000
#if !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo3_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo3_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Storage_Provider_IStorageProviderSyncRootInfo3[] = L"Windows.Storage.Provider.IStorageProviderSyncRootInfo3";
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                MIDL_INTERFACE("507a6617-bef6-56fd-855e-75ace2e45cf5")
                IStorageProviderSyncRootInfo3 : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE get_FallbackFileTypeInfo(
                        __FIVector_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo** value
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IStorageProviderSyncRootInfo3 = _uuidof(IStorageProviderSyncRootInfo3);
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo3;
#endif /* !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo3_INTERFACE_DEFINED__) */
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x40000

/*
 *
 * Interface Windows.Storage.Provider.IStorageProviderSyncRootManagerStatics
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Storage.Provider.StorageProviderSyncRootManager
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Storage_Provider_IStorageProviderSyncRootManagerStatics[] = L"Windows.Storage.Provider.IStorageProviderSyncRootManagerStatics";
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                MIDL_INTERFACE("3e99fbbf-8fe3-4b40-abc7-f6fc3d74c98e")
                IStorageProviderSyncRootManagerStatics : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE Register(
                        ABI::Windows::Storage::Provider::IStorageProviderSyncRootInfo* syncRootInformation
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE Unregister(
                        HSTRING id
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE GetSyncRootInformationForFolder(
                        ABI::Windows::Storage::IStorageFolder* folder,
                        ABI::Windows::Storage::Provider::IStorageProviderSyncRootInfo** result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE GetSyncRootInformationForId(
                        HSTRING id,
                        ABI::Windows::Storage::Provider::IStorageProviderSyncRootInfo** result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE GetCurrentSyncRoots(
                        __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo** result
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IStorageProviderSyncRootManagerStatics = _uuidof(IStorageProviderSyncRootManagerStatics);
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStatics;
#endif /* !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStatics_INTERFACE_DEFINED__) */
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Storage.Provider.IStorageProviderSyncRootManagerStatics2
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 4.0
 *
 * Interface is a part of the implementation of type Windows.Storage.Provider.StorageProviderSyncRootManager
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x40000
#if !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStatics2_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStatics2_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Storage_Provider_IStorageProviderSyncRootManagerStatics2[] = L"Windows.Storage.Provider.IStorageProviderSyncRootManagerStatics2";
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                MIDL_INTERFACE("efb6cfee-1374-544e-9df1-5598d2e9cfdd")
                IStorageProviderSyncRootManagerStatics2 : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE IsSupported(
                        boolean* result
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IStorageProviderSyncRootManagerStatics2 = _uuidof(IStorageProviderSyncRootManagerStatics2);
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStatics2;
#endif /* !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStatics2_INTERFACE_DEFINED__) */
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x40000

/*
 *
 * Interface Windows.Storage.Provider.IStorageProviderUriSource
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 2.0
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x20000
#if !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderUriSource_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderUriSource_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Storage_Provider_IStorageProviderUriSource[] = L"Windows.Storage.Provider.IStorageProviderUriSource";
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Provider {
                MIDL_INTERFACE("b29806d1-8be0-4962-8bb6-0d4c2e14d47a")
                IStorageProviderUriSource : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE GetPathForContentUri(
                        HSTRING contentUri,
                        ABI::Windows::Storage::Provider::IStorageProviderGetPathForContentUriResult* result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE GetContentInfoForPath(
                        HSTRING path,
                        ABI::Windows::Storage::Provider::IStorageProviderGetContentInfoForPathResult* result
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IStorageProviderUriSource = _uuidof(IStorageProviderUriSource);
            } /* Provider */
        } /* Storage */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CStorage_CProvider_CIStorageProviderUriSource;
#endif /* !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderUriSource_INTERFACE_DEFINED__) */
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x20000

/*
 *
 * Class Windows.Storage.Provider.CachedFileUpdater
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Windows.Storage.Provider.ICachedFileUpdaterStatics interface starting with version 1.0 of the Windows.Foundation.UniversalApiContract API contract
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Storage_Provider_CachedFileUpdater_DEFINED
#define RUNTIMECLASS_Windows_Storage_Provider_CachedFileUpdater_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Storage_Provider_CachedFileUpdater[] = L"Windows.Storage.Provider.CachedFileUpdater";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Storage.Provider.CachedFileUpdaterUI
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 * Class implements the following interfaces:
 *    Windows.Storage.Provider.ICachedFileUpdaterUI ** Default Interface **
 *    Windows.Storage.Provider.ICachedFileUpdaterUI2
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Storage_Provider_CachedFileUpdaterUI_DEFINED
#define RUNTIMECLASS_Windows_Storage_Provider_CachedFileUpdaterUI_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Storage_Provider_CachedFileUpdaterUI[] = L"Windows.Storage.Provider.CachedFileUpdaterUI";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Storage.Provider.FileUpdateRequest
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 * Class implements the following interfaces:
 *    Windows.Storage.Provider.IFileUpdateRequest ** Default Interface **
 *    Windows.Storage.Provider.IFileUpdateRequest2
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Storage_Provider_FileUpdateRequest_DEFINED
#define RUNTIMECLASS_Windows_Storage_Provider_FileUpdateRequest_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Storage_Provider_FileUpdateRequest[] = L"Windows.Storage.Provider.FileUpdateRequest";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Storage.Provider.FileUpdateRequestDeferral
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 * Class implements the following interfaces:
 *    Windows.Storage.Provider.IFileUpdateRequestDeferral ** Default Interface **
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Storage_Provider_FileUpdateRequestDeferral_DEFINED
#define RUNTIMECLASS_Windows_Storage_Provider_FileUpdateRequestDeferral_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Storage_Provider_FileUpdateRequestDeferral[] = L"Windows.Storage.Provider.FileUpdateRequestDeferral";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Storage.Provider.FileUpdateRequestedEventArgs
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 * Class implements the following interfaces:
 *    Windows.Storage.Provider.IFileUpdateRequestedEventArgs ** Default Interface **
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Storage_Provider_FileUpdateRequestedEventArgs_DEFINED
#define RUNTIMECLASS_Windows_Storage_Provider_FileUpdateRequestedEventArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Storage_Provider_FileUpdateRequestedEventArgs[] = L"Windows.Storage.Provider.FileUpdateRequestedEventArgs";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Storage.Provider.StorageProviderError
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 5.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via the Windows.Storage.Provider.IStorageProviderErrorFactory interface starting with version 5.0 of the Windows.Storage.Provider.CloudFilesContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Storage.Provider.IStorageProviderError ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x50000
#ifndef RUNTIMECLASS_Windows_Storage_Provider_StorageProviderError_DEFINED
#define RUNTIMECLASS_Windows_Storage_Provider_StorageProviderError_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Storage_Provider_StorageProviderError[] = L"Windows.Storage.Provider.StorageProviderError";
#endif
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x50000

/*
 *
 * Class Windows.Storage.Provider.StorageProviderErrorCommand
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 5.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via the Windows.Storage.Provider.IStorageProviderErrorCommandFactory interface starting with version 5.0 of the Windows.Storage.Provider.CloudFilesContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Storage.Provider.IStorageProviderErrorCommand ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x50000
#ifndef RUNTIMECLASS_Windows_Storage_Provider_StorageProviderErrorCommand_DEFINED
#define RUNTIMECLASS_Windows_Storage_Provider_StorageProviderErrorCommand_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Storage_Provider_StorageProviderErrorCommand[] = L"Windows.Storage.Provider.StorageProviderErrorCommand";
#endif
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x50000

/*
 *
 * Class Windows.Storage.Provider.StorageProviderFileTypeInfo
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 4.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via the Windows.Storage.Provider.IStorageProviderFileTypeInfoFactory interface starting with version 4.0 of the Windows.Storage.Provider.CloudFilesContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Storage.Provider.IStorageProviderFileTypeInfo ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x40000
#ifndef RUNTIMECLASS_Windows_Storage_Provider_StorageProviderFileTypeInfo_DEFINED
#define RUNTIMECLASS_Windows_Storage_Provider_StorageProviderFileTypeInfo_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Storage_Provider_StorageProviderFileTypeInfo[] = L"Windows.Storage.Provider.StorageProviderFileTypeInfo";
#endif
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x40000

/*
 *
 * Class Windows.Storage.Provider.StorageProviderGetContentInfoForPathResult
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 2.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via RoActivateInstance starting with version 2.0 of the Windows.Storage.Provider.CloudFilesContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Storage.Provider.IStorageProviderGetContentInfoForPathResult ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x20000
#ifndef RUNTIMECLASS_Windows_Storage_Provider_StorageProviderGetContentInfoForPathResult_DEFINED
#define RUNTIMECLASS_Windows_Storage_Provider_StorageProviderGetContentInfoForPathResult_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Storage_Provider_StorageProviderGetContentInfoForPathResult[] = L"Windows.Storage.Provider.StorageProviderGetContentInfoForPathResult";
#endif
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x20000

/*
 *
 * Class Windows.Storage.Provider.StorageProviderGetPathForContentUriResult
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 2.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via RoActivateInstance starting with version 2.0 of the Windows.Storage.Provider.CloudFilesContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Storage.Provider.IStorageProviderGetPathForContentUriResult ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x20000
#ifndef RUNTIMECLASS_Windows_Storage_Provider_StorageProviderGetPathForContentUriResult_DEFINED
#define RUNTIMECLASS_Windows_Storage_Provider_StorageProviderGetPathForContentUriResult_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Storage_Provider_StorageProviderGetPathForContentUriResult[] = L"Windows.Storage.Provider.StorageProviderGetPathForContentUriResult";
#endif
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x20000

/*
 *
 * Class Windows.Storage.Provider.StorageProviderItemProperties
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 1.0
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Windows.Storage.Provider.IStorageProviderItemPropertiesStatics interface starting with version 1.0 of the Windows.Storage.Provider.CloudFilesContract API contract
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Storage_Provider_StorageProviderItemProperties_DEFINED
#define RUNTIMECLASS_Windows_Storage_Provider_StorageProviderItemProperties_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Storage_Provider_StorageProviderItemProperties[] = L"Windows.Storage.Provider.StorageProviderItemProperties";
#endif
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Storage.Provider.StorageProviderItemProperty
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 1.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via RoActivateInstance starting with version 1.0 of the Windows.Storage.Provider.CloudFilesContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Storage.Provider.IStorageProviderItemProperty ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Storage_Provider_StorageProviderItemProperty_DEFINED
#define RUNTIMECLASS_Windows_Storage_Provider_StorageProviderItemProperty_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Storage_Provider_StorageProviderItemProperty[] = L"Windows.Storage.Provider.StorageProviderItemProperty";
#endif
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Storage.Provider.StorageProviderItemPropertyDefinition
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 1.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via RoActivateInstance starting with version 1.0 of the Windows.Storage.Provider.CloudFilesContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Storage.Provider.IStorageProviderItemPropertyDefinition ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Storage_Provider_StorageProviderItemPropertyDefinition_DEFINED
#define RUNTIMECLASS_Windows_Storage_Provider_StorageProviderItemPropertyDefinition_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Storage_Provider_StorageProviderItemPropertyDefinition[] = L"Windows.Storage.Provider.StorageProviderItemPropertyDefinition";
#endif
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Storage.Provider.StorageProviderStatus
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 5.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via the Windows.Storage.Provider.IStorageProviderStatusFactory interface starting with version 5.0 of the Windows.Storage.Provider.CloudFilesContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Storage.Provider.IStorageProviderStatus ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x50000
#ifndef RUNTIMECLASS_Windows_Storage_Provider_StorageProviderStatus_DEFINED
#define RUNTIMECLASS_Windows_Storage_Provider_StorageProviderStatus_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Storage_Provider_StorageProviderStatus[] = L"Windows.Storage.Provider.StorageProviderStatus";
#endif
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x50000

/*
 *
 * Class Windows.Storage.Provider.StorageProviderSyncRootInfo
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 1.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via RoActivateInstance starting with version 1.0 of the Windows.Storage.Provider.CloudFilesContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Storage.Provider.IStorageProviderSyncRootInfo ** Default Interface **
 *    Windows.Storage.Provider.IStorageProviderSyncRootInfo2
 *    Windows.Storage.Provider.IStorageProviderSyncRootInfo3
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Storage_Provider_StorageProviderSyncRootInfo_DEFINED
#define RUNTIMECLASS_Windows_Storage_Provider_StorageProviderSyncRootInfo_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Storage_Provider_StorageProviderSyncRootInfo[] = L"Windows.Storage.Provider.StorageProviderSyncRootInfo";
#endif
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Storage.Provider.StorageProviderSyncRootManager
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 1.0
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Windows.Storage.Provider.IStorageProviderSyncRootManagerStatics2 interface starting with version 4.0 of the Windows.Storage.Provider.CloudFilesContract API contract
 *   Static Methods exist on the Windows.Storage.Provider.IStorageProviderSyncRootManagerStatics interface starting with version 1.0 of the Windows.Storage.Provider.CloudFilesContract API contract
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Storage_Provider_StorageProviderSyncRootManager_DEFINED
#define RUNTIMECLASS_Windows_Storage_Provider_StorageProviderSyncRootManager_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Storage_Provider_StorageProviderSyncRootManager[] = L"Windows.Storage.Provider.StorageProviderSyncRootManager";
#endif
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000

#else // !defined(__cplusplus)
/* Forward Declarations */
#ifndef ____x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterStatics_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterStatics_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterStatics __x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterStatics;

#endif // ____x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterStatics_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI __x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI;

#endif // ____x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI2_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI2_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI2 __x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI2;

#endif // ____x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI2_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest __x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest;

#endif // ____x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest2_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest2_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest2 __x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest2;

#endif // ____x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest2_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequestDeferral_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequestDeferral_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequestDeferral __x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequestDeferral;

#endif // ____x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequestDeferral_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequestedEventArgs_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequestedEventArgs_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequestedEventArgs __x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequestedEventArgs;

#endif // ____x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequestedEventArgs_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderError_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderError_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderError __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderError;

#endif // ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderError_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommand_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommand_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommand __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommand;

#endif // ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommand_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommandFactory_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommandFactory_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommandFactory __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommandFactory;

#endif // ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommandFactory_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorFactory_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorFactory_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorFactory __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorFactory;

#endif // ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorFactory_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfo_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfo_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfo __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfo;

#endif // ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfo_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfoFactory_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfoFactory_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfoFactory __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfoFactory;

#endif // ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfoFactory_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetContentInfoForPathResult_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetContentInfoForPathResult_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetContentInfoForPathResult __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetContentInfoForPathResult;

#endif // ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetContentInfoForPathResult_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetPathForContentUriResult_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetPathForContentUriResult_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetPathForContentUriResult __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetPathForContentUriResult;

#endif // ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetPathForContentUriResult_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderHandlerFactory_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderHandlerFactory_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderHandlerFactory __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderHandlerFactory;

#endif // ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderHandlerFactory_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertiesStatics_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertiesStatics_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertiesStatics __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertiesStatics;

#endif // ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertiesStatics_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemProperty_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemProperty_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemProperty __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemProperty;

#endif // ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemProperty_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertyDefinition_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertyDefinition_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertyDefinition __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertyDefinition;

#endif // ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertyDefinition_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertySource_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertySource_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertySource __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertySource;

#endif // ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertySource_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderPropertyCapabilities_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderPropertyCapabilities_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderPropertyCapabilities __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderPropertyCapabilities;

#endif // ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderPropertyCapabilities_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatus_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatus_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatus __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatus;

#endif // ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatus_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusFactory_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusFactory_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusFactory __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusFactory;

#endif // ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusFactory_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusSource_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusSource_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusSource __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusSource;

#endif // ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusSource_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo;

#endif // ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo2_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo2_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo2 __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo2;

#endif // ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo2_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo3_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo3_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo3 __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo3;

#endif // ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo3_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStatics_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStatics_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStatics __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStatics;

#endif // ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStatics_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStatics2_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStatics2_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStatics2 __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStatics2;

#endif // ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStatics2_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderUriSource_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderUriSource_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderUriSource __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderUriSource;

#endif // ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderUriSource_FWD_DEFINED__

// Parameterized interface forward declarations (C)

// Collection interface definitions

#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x50000
#if !defined(____FIIterator_1_Windows__CStorage__CProvider__CStorageProviderError_INTERFACE_DEFINED__)
#define ____FIIterator_1_Windows__CStorage__CProvider__CStorageProviderError_INTERFACE_DEFINED__

typedef interface __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderError __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderError;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterator_1_Windows__CStorage__CProvider__CStorageProviderError;

typedef struct __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderErrorVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIIterator_1_Windows__CStorage__CProvider__CStorageProviderError* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIIterator_1_Windows__CStorage__CProvider__CStorageProviderError* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIIterator_1_Windows__CStorage__CProvider__CStorageProviderError* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIIterator_1_Windows__CStorage__CProvider__CStorageProviderError* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIIterator_1_Windows__CStorage__CProvider__CStorageProviderError* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIIterator_1_Windows__CStorage__CProvider__CStorageProviderError* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Current)(__FIIterator_1_Windows__CStorage__CProvider__CStorageProviderError* This,
        __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderError** result);
    HRESULT (STDMETHODCALLTYPE* get_HasCurrent)(__FIIterator_1_Windows__CStorage__CProvider__CStorageProviderError* This,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* MoveNext)(__FIIterator_1_Windows__CStorage__CProvider__CStorageProviderError* This,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* GetMany)(__FIIterator_1_Windows__CStorage__CProvider__CStorageProviderError* This,
        UINT32 itemsLength,
        __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderError** items,
        UINT32* result);

    END_INTERFACE
} __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderErrorVtbl;

interface __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderError
{
    CONST_VTBL struct __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderErrorVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderError_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderError_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderError_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderError_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderError_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderError_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderError_get_Current(This, result) \
    ((This)->lpVtbl->get_Current(This, result))

#define __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderError_get_HasCurrent(This, result) \
    ((This)->lpVtbl->get_HasCurrent(This, result))

#define __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderError_MoveNext(This, result) \
    ((This)->lpVtbl->MoveNext(This, result))

#define __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderError_GetMany(This, itemsLength, items, result) \
    ((This)->lpVtbl->GetMany(This, itemsLength, items, result))

#endif /* COBJMACROS */

#endif // ____FIIterator_1_Windows__CStorage__CProvider__CStorageProviderError_INTERFACE_DEFINED__
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x50000

#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x50000
#if !defined(____FIIterable_1_Windows__CStorage__CProvider__CStorageProviderError_INTERFACE_DEFINED__)
#define ____FIIterable_1_Windows__CStorage__CProvider__CStorageProviderError_INTERFACE_DEFINED__

typedef interface __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderError __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderError;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterable_1_Windows__CStorage__CProvider__CStorageProviderError;

typedef struct __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderErrorVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIIterable_1_Windows__CStorage__CProvider__CStorageProviderError* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIIterable_1_Windows__CStorage__CProvider__CStorageProviderError* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIIterable_1_Windows__CStorage__CProvider__CStorageProviderError* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIIterable_1_Windows__CStorage__CProvider__CStorageProviderError* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIIterable_1_Windows__CStorage__CProvider__CStorageProviderError* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIIterable_1_Windows__CStorage__CProvider__CStorageProviderError* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* First)(__FIIterable_1_Windows__CStorage__CProvider__CStorageProviderError* This,
        __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderError** result);

    END_INTERFACE
} __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderErrorVtbl;

interface __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderError
{
    CONST_VTBL struct __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderErrorVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderError_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderError_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderError_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderError_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderError_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderError_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderError_First(This, result) \
    ((This)->lpVtbl->First(This, result))

#endif /* COBJMACROS */

#endif // ____FIIterable_1_Windows__CStorage__CProvider__CStorageProviderError_INTERFACE_DEFINED__
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x50000

#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x40000
#if !defined(____FIIterator_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo_INTERFACE_DEFINED__)
#define ____FIIterator_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo_INTERFACE_DEFINED__

typedef interface __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterator_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo;

typedef struct __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfoVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIIterator_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIIterator_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIIterator_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIIterator_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIIterator_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIIterator_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Current)(__FIIterator_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo* This,
        __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfo** result);
    HRESULT (STDMETHODCALLTYPE* get_HasCurrent)(__FIIterator_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo* This,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* MoveNext)(__FIIterator_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo* This,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* GetMany)(__FIIterator_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo* This,
        UINT32 itemsLength,
        __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfo** items,
        UINT32* result);

    END_INTERFACE
} __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfoVtbl;

interface __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo
{
    CONST_VTBL struct __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfoVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo_get_Current(This, result) \
    ((This)->lpVtbl->get_Current(This, result))

#define __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo_get_HasCurrent(This, result) \
    ((This)->lpVtbl->get_HasCurrent(This, result))

#define __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo_MoveNext(This, result) \
    ((This)->lpVtbl->MoveNext(This, result))

#define __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo_GetMany(This, itemsLength, items, result) \
    ((This)->lpVtbl->GetMany(This, itemsLength, items, result))

#endif /* COBJMACROS */

#endif // ____FIIterator_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo_INTERFACE_DEFINED__
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x40000

#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x40000
#if !defined(____FIIterable_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo_INTERFACE_DEFINED__)
#define ____FIIterable_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo_INTERFACE_DEFINED__

typedef interface __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterable_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo;

typedef struct __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfoVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIIterable_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIIterable_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIIterable_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIIterable_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIIterable_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIIterable_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* First)(__FIIterable_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo* This,
        __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo** result);

    END_INTERFACE
} __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfoVtbl;

interface __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo
{
    CONST_VTBL struct __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfoVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo_First(This, result) \
    ((This)->lpVtbl->First(This, result))

#endif /* COBJMACROS */

#endif // ____FIIterable_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo_INTERFACE_DEFINED__
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x40000

#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000
#if !defined(____FIIterator_1_Windows__CStorage__CProvider__CStorageProviderItemProperty_INTERFACE_DEFINED__)
#define ____FIIterator_1_Windows__CStorage__CProvider__CStorageProviderItemProperty_INTERFACE_DEFINED__

typedef interface __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderItemProperty __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderItemProperty;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterator_1_Windows__CStorage__CProvider__CStorageProviderItemProperty;

typedef struct __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIIterator_1_Windows__CStorage__CProvider__CStorageProviderItemProperty* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIIterator_1_Windows__CStorage__CProvider__CStorageProviderItemProperty* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIIterator_1_Windows__CStorage__CProvider__CStorageProviderItemProperty* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIIterator_1_Windows__CStorage__CProvider__CStorageProviderItemProperty* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIIterator_1_Windows__CStorage__CProvider__CStorageProviderItemProperty* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIIterator_1_Windows__CStorage__CProvider__CStorageProviderItemProperty* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Current)(__FIIterator_1_Windows__CStorage__CProvider__CStorageProviderItemProperty* This,
        __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemProperty** result);
    HRESULT (STDMETHODCALLTYPE* get_HasCurrent)(__FIIterator_1_Windows__CStorage__CProvider__CStorageProviderItemProperty* This,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* MoveNext)(__FIIterator_1_Windows__CStorage__CProvider__CStorageProviderItemProperty* This,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* GetMany)(__FIIterator_1_Windows__CStorage__CProvider__CStorageProviderItemProperty* This,
        UINT32 itemsLength,
        __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemProperty** items,
        UINT32* result);

    END_INTERFACE
} __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyVtbl;

interface __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderItemProperty
{
    CONST_VTBL struct __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderItemProperty_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderItemProperty_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderItemProperty_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderItemProperty_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderItemProperty_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderItemProperty_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderItemProperty_get_Current(This, result) \
    ((This)->lpVtbl->get_Current(This, result))

#define __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderItemProperty_get_HasCurrent(This, result) \
    ((This)->lpVtbl->get_HasCurrent(This, result))

#define __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderItemProperty_MoveNext(This, result) \
    ((This)->lpVtbl->MoveNext(This, result))

#define __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderItemProperty_GetMany(This, itemsLength, items, result) \
    ((This)->lpVtbl->GetMany(This, itemsLength, items, result))

#endif /* COBJMACROS */

#endif // ____FIIterator_1_Windows__CStorage__CProvider__CStorageProviderItemProperty_INTERFACE_DEFINED__
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000

#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000
#if !defined(____FIIterable_1_Windows__CStorage__CProvider__CStorageProviderItemProperty_INTERFACE_DEFINED__)
#define ____FIIterable_1_Windows__CStorage__CProvider__CStorageProviderItemProperty_INTERFACE_DEFINED__

typedef interface __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderItemProperty __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderItemProperty;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterable_1_Windows__CStorage__CProvider__CStorageProviderItemProperty;

typedef struct __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIIterable_1_Windows__CStorage__CProvider__CStorageProviderItemProperty* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIIterable_1_Windows__CStorage__CProvider__CStorageProviderItemProperty* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIIterable_1_Windows__CStorage__CProvider__CStorageProviderItemProperty* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIIterable_1_Windows__CStorage__CProvider__CStorageProviderItemProperty* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIIterable_1_Windows__CStorage__CProvider__CStorageProviderItemProperty* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIIterable_1_Windows__CStorage__CProvider__CStorageProviderItemProperty* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* First)(__FIIterable_1_Windows__CStorage__CProvider__CStorageProviderItemProperty* This,
        __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderItemProperty** result);

    END_INTERFACE
} __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyVtbl;

interface __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderItemProperty
{
    CONST_VTBL struct __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderItemProperty_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderItemProperty_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderItemProperty_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderItemProperty_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderItemProperty_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderItemProperty_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderItemProperty_First(This, result) \
    ((This)->lpVtbl->First(This, result))

#endif /* COBJMACROS */

#endif // ____FIIterable_1_Windows__CStorage__CProvider__CStorageProviderItemProperty_INTERFACE_DEFINED__
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000

#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000
#if !defined(____FIIterator_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition_INTERFACE_DEFINED__)
#define ____FIIterator_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition_INTERFACE_DEFINED__

typedef interface __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterator_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition;

typedef struct __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinitionVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIIterator_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIIterator_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIIterator_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIIterator_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIIterator_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIIterator_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Current)(__FIIterator_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition* This,
        __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertyDefinition** result);
    HRESULT (STDMETHODCALLTYPE* get_HasCurrent)(__FIIterator_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition* This,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* MoveNext)(__FIIterator_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition* This,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* GetMany)(__FIIterator_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition* This,
        UINT32 itemsLength,
        __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertyDefinition** items,
        UINT32* result);

    END_INTERFACE
} __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinitionVtbl;

interface __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition
{
    CONST_VTBL struct __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinitionVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition_get_Current(This, result) \
    ((This)->lpVtbl->get_Current(This, result))

#define __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition_get_HasCurrent(This, result) \
    ((This)->lpVtbl->get_HasCurrent(This, result))

#define __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition_MoveNext(This, result) \
    ((This)->lpVtbl->MoveNext(This, result))

#define __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition_GetMany(This, itemsLength, items, result) \
    ((This)->lpVtbl->GetMany(This, itemsLength, items, result))

#endif /* COBJMACROS */

#endif // ____FIIterator_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition_INTERFACE_DEFINED__
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000

#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000
#if !defined(____FIIterable_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition_INTERFACE_DEFINED__)
#define ____FIIterable_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition_INTERFACE_DEFINED__

typedef interface __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterable_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition;

typedef struct __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinitionVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIIterable_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIIterable_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIIterable_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIIterable_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIIterable_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIIterable_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* First)(__FIIterable_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition* This,
        __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition** result);

    END_INTERFACE
} __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinitionVtbl;

interface __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition
{
    CONST_VTBL struct __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinitionVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition_First(This, result) \
    ((This)->lpVtbl->First(This, result))

#endif /* COBJMACROS */

#endif // ____FIIterable_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition_INTERFACE_DEFINED__
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000

#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000
#if !defined(____FIIterator_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo_INTERFACE_DEFINED__)
#define ____FIIterator_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo_INTERFACE_DEFINED__

typedef interface __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterator_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo;

typedef struct __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfoVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIIterator_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIIterator_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIIterator_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIIterator_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIIterator_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIIterator_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Current)(__FIIterator_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo* This,
        __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo** result);
    HRESULT (STDMETHODCALLTYPE* get_HasCurrent)(__FIIterator_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo* This,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* MoveNext)(__FIIterator_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo* This,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* GetMany)(__FIIterator_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo* This,
        UINT32 itemsLength,
        __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo** items,
        UINT32* result);

    END_INTERFACE
} __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfoVtbl;

interface __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo
{
    CONST_VTBL struct __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfoVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo_get_Current(This, result) \
    ((This)->lpVtbl->get_Current(This, result))

#define __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo_get_HasCurrent(This, result) \
    ((This)->lpVtbl->get_HasCurrent(This, result))

#define __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo_MoveNext(This, result) \
    ((This)->lpVtbl->MoveNext(This, result))

#define __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo_GetMany(This, itemsLength, items, result) \
    ((This)->lpVtbl->GetMany(This, itemsLength, items, result))

#endif /* COBJMACROS */

#endif // ____FIIterator_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo_INTERFACE_DEFINED__
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000

#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000
#if !defined(____FIIterable_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo_INTERFACE_DEFINED__)
#define ____FIIterable_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo_INTERFACE_DEFINED__

typedef interface __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterable_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo;

typedef struct __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfoVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIIterable_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIIterable_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIIterable_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIIterable_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIIterable_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIIterable_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* First)(__FIIterable_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo* This,
        __FIIterator_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo** result);

    END_INTERFACE
} __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfoVtbl;

interface __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo
{
    CONST_VTBL struct __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfoVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo_First(This, result) \
    ((This)->lpVtbl->First(This, result))

#endif /* COBJMACROS */

#endif // ____FIIterable_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo_INTERFACE_DEFINED__
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000

#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x50000
#if !defined(____FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderError_INTERFACE_DEFINED__)
#define ____FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderError_INTERFACE_DEFINED__

typedef interface __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderError __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderError;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderError;

typedef struct __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderErrorVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderError* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderError* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderError* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderError* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderError* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderError* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* GetAt)(__FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderError* This,
        UINT32 index,
        __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderError** result);
    HRESULT (STDMETHODCALLTYPE* get_Size)(__FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderError* This,
        UINT32* result);
    HRESULT (STDMETHODCALLTYPE* IndexOf)(__FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderError* This,
        __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderError* value,
        UINT32* index,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* GetMany)(__FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderError* This,
        UINT32 startIndex,
        UINT32 itemsLength,
        __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderError** items,
        UINT32* result);

    END_INTERFACE
} __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderErrorVtbl;

interface __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderError
{
    CONST_VTBL struct __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderErrorVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderError_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderError_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderError_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderError_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderError_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderError_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderError_GetAt(This, index, result) \
    ((This)->lpVtbl->GetAt(This, index, result))

#define __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderError_get_Size(This, result) \
    ((This)->lpVtbl->get_Size(This, result))

#define __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderError_IndexOf(This, value, index, result) \
    ((This)->lpVtbl->IndexOf(This, value, index, result))

#define __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderError_GetMany(This, startIndex, itemsLength, items, result) \
    ((This)->lpVtbl->GetMany(This, startIndex, itemsLength, items, result))

#endif /* COBJMACROS */

#endif // ____FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderError_INTERFACE_DEFINED__
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x50000

#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x40000
#if !defined(____FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo_INTERFACE_DEFINED__)
#define ____FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo_INTERFACE_DEFINED__

typedef interface __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo;

typedef struct __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfoVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* GetAt)(__FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo* This,
        UINT32 index,
        __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfo** result);
    HRESULT (STDMETHODCALLTYPE* get_Size)(__FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo* This,
        UINT32* result);
    HRESULT (STDMETHODCALLTYPE* IndexOf)(__FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo* This,
        __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfo* value,
        UINT32* index,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* GetMany)(__FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo* This,
        UINT32 startIndex,
        UINT32 itemsLength,
        __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfo** items,
        UINT32* result);

    END_INTERFACE
} __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfoVtbl;

interface __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo
{
    CONST_VTBL struct __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfoVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo_GetAt(This, index, result) \
    ((This)->lpVtbl->GetAt(This, index, result))

#define __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo_get_Size(This, result) \
    ((This)->lpVtbl->get_Size(This, result))

#define __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo_IndexOf(This, value, index, result) \
    ((This)->lpVtbl->IndexOf(This, value, index, result))

#define __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo_GetMany(This, startIndex, itemsLength, items, result) \
    ((This)->lpVtbl->GetMany(This, startIndex, itemsLength, items, result))

#endif /* COBJMACROS */

#endif // ____FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo_INTERFACE_DEFINED__
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x40000

#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000
#if !defined(____FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition_INTERFACE_DEFINED__)
#define ____FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition_INTERFACE_DEFINED__

typedef interface __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition;

typedef struct __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinitionVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* GetAt)(__FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition* This,
        UINT32 index,
        __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertyDefinition** result);
    HRESULT (STDMETHODCALLTYPE* get_Size)(__FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition* This,
        UINT32* result);
    HRESULT (STDMETHODCALLTYPE* IndexOf)(__FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition* This,
        __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertyDefinition* value,
        UINT32* index,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* GetMany)(__FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition* This,
        UINT32 startIndex,
        UINT32 itemsLength,
        __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertyDefinition** items,
        UINT32* result);

    END_INTERFACE
} __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinitionVtbl;

interface __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition
{
    CONST_VTBL struct __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinitionVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition_GetAt(This, index, result) \
    ((This)->lpVtbl->GetAt(This, index, result))

#define __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition_get_Size(This, result) \
    ((This)->lpVtbl->get_Size(This, result))

#define __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition_IndexOf(This, value, index, result) \
    ((This)->lpVtbl->IndexOf(This, value, index, result))

#define __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition_GetMany(This, startIndex, itemsLength, items, result) \
    ((This)->lpVtbl->GetMany(This, startIndex, itemsLength, items, result))

#endif /* COBJMACROS */

#endif // ____FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition_INTERFACE_DEFINED__
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000

#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000
#if !defined(____FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo_INTERFACE_DEFINED__)
#define ____FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo_INTERFACE_DEFINED__

typedef interface __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo;

typedef struct __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfoVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* GetAt)(__FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo* This,
        UINT32 index,
        __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo** result);
    HRESULT (STDMETHODCALLTYPE* get_Size)(__FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo* This,
        UINT32* result);
    HRESULT (STDMETHODCALLTYPE* IndexOf)(__FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo* This,
        __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo* value,
        UINT32* index,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* GetMany)(__FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo* This,
        UINT32 startIndex,
        UINT32 itemsLength,
        __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo** items,
        UINT32* result);

    END_INTERFACE
} __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfoVtbl;

interface __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo
{
    CONST_VTBL struct __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfoVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo_GetAt(This, index, result) \
    ((This)->lpVtbl->GetAt(This, index, result))

#define __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo_get_Size(This, result) \
    ((This)->lpVtbl->get_Size(This, result))

#define __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo_IndexOf(This, value, index, result) \
    ((This)->lpVtbl->IndexOf(This, value, index, result))

#define __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo_GetMany(This, startIndex, itemsLength, items, result) \
    ((This)->lpVtbl->GetMany(This, startIndex, itemsLength, items, result))

#endif /* COBJMACROS */

#endif // ____FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo_INTERFACE_DEFINED__
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000

#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x40000
#if !defined(____FIVector_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo_INTERFACE_DEFINED__)
#define ____FIVector_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo_INTERFACE_DEFINED__

typedef interface __FIVector_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo __FIVector_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIVector_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo;

typedef struct __FIVector_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfoVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIVector_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIVector_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIVector_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIVector_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIVector_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIVector_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* GetAt)(__FIVector_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo* This,
        UINT32 index,
        __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfo** result);
    HRESULT (STDMETHODCALLTYPE* get_Size)(__FIVector_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo* This,
        UINT32* result);
    HRESULT (STDMETHODCALLTYPE* GetView)(__FIVector_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo* This,
        __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo** result);
    HRESULT (STDMETHODCALLTYPE* IndexOf)(__FIVector_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo* This,
        __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfo* value,
        UINT32* index,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* SetAt)(__FIVector_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo* This,
        UINT32 index,
        __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfo* value);
    HRESULT (STDMETHODCALLTYPE* InsertAt)(__FIVector_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo* This,
        UINT32 index,
        __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfo* value);
    HRESULT (STDMETHODCALLTYPE* RemoveAt)(__FIVector_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo* This,
        UINT32 index);
    HRESULT (STDMETHODCALLTYPE* Append)(__FIVector_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo* This,
        __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfo* value);
    HRESULT (STDMETHODCALLTYPE* RemoveAtEnd)(__FIVector_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo* This);
    HRESULT (STDMETHODCALLTYPE* Clear)(__FIVector_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo* This);
    HRESULT (STDMETHODCALLTYPE* GetMany)(__FIVector_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo* This,
        UINT32 startIndex,
        UINT32 itemsLength,
        __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfo** items,
        UINT32* result);
    HRESULT (STDMETHODCALLTYPE* ReplaceAll)(__FIVector_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo* This,
        UINT32 itemsLength,
        __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfo** items);

    END_INTERFACE
} __FIVector_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfoVtbl;

interface __FIVector_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo
{
    CONST_VTBL struct __FIVector_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfoVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIVector_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIVector_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIVector_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIVector_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIVector_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIVector_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIVector_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo_GetAt(This, index, result) \
    ((This)->lpVtbl->GetAt(This, index, result))

#define __FIVector_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo_get_Size(This, result) \
    ((This)->lpVtbl->get_Size(This, result))

#define __FIVector_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo_GetView(This, result) \
    ((This)->lpVtbl->GetView(This, result))

#define __FIVector_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo_IndexOf(This, value, index, result) \
    ((This)->lpVtbl->IndexOf(This, value, index, result))

#define __FIVector_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo_SetAt(This, index, value) \
    ((This)->lpVtbl->SetAt(This, index, value))

#define __FIVector_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo_InsertAt(This, index, value) \
    ((This)->lpVtbl->InsertAt(This, index, value))

#define __FIVector_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo_RemoveAt(This, index) \
    ((This)->lpVtbl->RemoveAt(This, index))

#define __FIVector_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo_Append(This, value) \
    ((This)->lpVtbl->Append(This, value))

#define __FIVector_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo_RemoveAtEnd(This) \
    ((This)->lpVtbl->RemoveAtEnd(This))

#define __FIVector_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo_Clear(This) \
    ((This)->lpVtbl->Clear(This))

#define __FIVector_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo_GetMany(This, startIndex, itemsLength, items, result) \
    ((This)->lpVtbl->GetMany(This, startIndex, itemsLength, items, result))

#define __FIVector_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo_ReplaceAll(This, itemsLength, items) \
    ((This)->lpVtbl->ReplaceAll(This, itemsLength, items))

#endif /* COBJMACROS */

#endif // ____FIVector_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo_INTERFACE_DEFINED__
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x40000

#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000
#if !defined(____FIVector_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition_INTERFACE_DEFINED__)
#define ____FIVector_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition_INTERFACE_DEFINED__

typedef interface __FIVector_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition __FIVector_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIVector_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition;

typedef struct __FIVector_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinitionVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIVector_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIVector_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIVector_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIVector_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIVector_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIVector_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* GetAt)(__FIVector_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition* This,
        UINT32 index,
        __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertyDefinition** result);
    HRESULT (STDMETHODCALLTYPE* get_Size)(__FIVector_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition* This,
        UINT32* result);
    HRESULT (STDMETHODCALLTYPE* GetView)(__FIVector_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition* This,
        __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition** result);
    HRESULT (STDMETHODCALLTYPE* IndexOf)(__FIVector_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition* This,
        __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertyDefinition* value,
        UINT32* index,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* SetAt)(__FIVector_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition* This,
        UINT32 index,
        __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertyDefinition* value);
    HRESULT (STDMETHODCALLTYPE* InsertAt)(__FIVector_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition* This,
        UINT32 index,
        __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertyDefinition* value);
    HRESULT (STDMETHODCALLTYPE* RemoveAt)(__FIVector_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition* This,
        UINT32 index);
    HRESULT (STDMETHODCALLTYPE* Append)(__FIVector_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition* This,
        __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertyDefinition* value);
    HRESULT (STDMETHODCALLTYPE* RemoveAtEnd)(__FIVector_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition* This);
    HRESULT (STDMETHODCALLTYPE* Clear)(__FIVector_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition* This);
    HRESULT (STDMETHODCALLTYPE* GetMany)(__FIVector_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition* This,
        UINT32 startIndex,
        UINT32 itemsLength,
        __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertyDefinition** items,
        UINT32* result);
    HRESULT (STDMETHODCALLTYPE* ReplaceAll)(__FIVector_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition* This,
        UINT32 itemsLength,
        __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertyDefinition** items);

    END_INTERFACE
} __FIVector_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinitionVtbl;

interface __FIVector_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition
{
    CONST_VTBL struct __FIVector_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinitionVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIVector_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIVector_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIVector_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIVector_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIVector_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIVector_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIVector_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition_GetAt(This, index, result) \
    ((This)->lpVtbl->GetAt(This, index, result))

#define __FIVector_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition_get_Size(This, result) \
    ((This)->lpVtbl->get_Size(This, result))

#define __FIVector_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition_GetView(This, result) \
    ((This)->lpVtbl->GetView(This, result))

#define __FIVector_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition_IndexOf(This, value, index, result) \
    ((This)->lpVtbl->IndexOf(This, value, index, result))

#define __FIVector_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition_SetAt(This, index, value) \
    ((This)->lpVtbl->SetAt(This, index, value))

#define __FIVector_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition_InsertAt(This, index, value) \
    ((This)->lpVtbl->InsertAt(This, index, value))

#define __FIVector_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition_RemoveAt(This, index) \
    ((This)->lpVtbl->RemoveAt(This, index))

#define __FIVector_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition_Append(This, value) \
    ((This)->lpVtbl->Append(This, value))

#define __FIVector_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition_RemoveAtEnd(This) \
    ((This)->lpVtbl->RemoveAtEnd(This))

#define __FIVector_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition_Clear(This) \
    ((This)->lpVtbl->Clear(This))

#define __FIVector_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition_GetMany(This, startIndex, itemsLength, items, result) \
    ((This)->lpVtbl->GetMany(This, startIndex, itemsLength, items, result))

#define __FIVector_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition_ReplaceAll(This, itemsLength, items) \
    ((This)->lpVtbl->ReplaceAll(This, itemsLength, items))

#endif /* COBJMACROS */

#endif // ____FIVector_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition_INTERFACE_DEFINED__
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if !defined(____FITypedEventHandler_2_Windows__CStorage__CProvider__CCachedFileUpdaterUI_IInspectable_INTERFACE_DEFINED__)
#define ____FITypedEventHandler_2_Windows__CStorage__CProvider__CCachedFileUpdaterUI_IInspectable_INTERFACE_DEFINED__

typedef interface __FITypedEventHandler_2_Windows__CStorage__CProvider__CCachedFileUpdaterUI_IInspectable __FITypedEventHandler_2_Windows__CStorage__CProvider__CCachedFileUpdaterUI_IInspectable;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FITypedEventHandler_2_Windows__CStorage__CProvider__CCachedFileUpdaterUI_IInspectable;

typedef struct __FITypedEventHandler_2_Windows__CStorage__CProvider__CCachedFileUpdaterUI_IInspectableVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FITypedEventHandler_2_Windows__CStorage__CProvider__CCachedFileUpdaterUI_IInspectable* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FITypedEventHandler_2_Windows__CStorage__CProvider__CCachedFileUpdaterUI_IInspectable* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FITypedEventHandler_2_Windows__CStorage__CProvider__CCachedFileUpdaterUI_IInspectable* This);
    HRESULT (STDMETHODCALLTYPE* Invoke)(__FITypedEventHandler_2_Windows__CStorage__CProvider__CCachedFileUpdaterUI_IInspectable* This,
        __x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI* sender,
        IInspectable* args);

    END_INTERFACE
} __FITypedEventHandler_2_Windows__CStorage__CProvider__CCachedFileUpdaterUI_IInspectableVtbl;

interface __FITypedEventHandler_2_Windows__CStorage__CProvider__CCachedFileUpdaterUI_IInspectable
{
    CONST_VTBL struct __FITypedEventHandler_2_Windows__CStorage__CProvider__CCachedFileUpdaterUI_IInspectableVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FITypedEventHandler_2_Windows__CStorage__CProvider__CCachedFileUpdaterUI_IInspectable_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FITypedEventHandler_2_Windows__CStorage__CProvider__CCachedFileUpdaterUI_IInspectable_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FITypedEventHandler_2_Windows__CStorage__CProvider__CCachedFileUpdaterUI_IInspectable_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FITypedEventHandler_2_Windows__CStorage__CProvider__CCachedFileUpdaterUI_IInspectable_Invoke(This, sender, args) \
    ((This)->lpVtbl->Invoke(This, sender, args))

#endif /* COBJMACROS */

#endif // ____FITypedEventHandler_2_Windows__CStorage__CProvider__CCachedFileUpdaterUI_IInspectable_INTERFACE_DEFINED__
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if !defined(____FITypedEventHandler_2_Windows__CStorage__CProvider__CCachedFileUpdaterUI_Windows__CStorage__CProvider__CFileUpdateRequestedEventArgs_INTERFACE_DEFINED__)
#define ____FITypedEventHandler_2_Windows__CStorage__CProvider__CCachedFileUpdaterUI_Windows__CStorage__CProvider__CFileUpdateRequestedEventArgs_INTERFACE_DEFINED__

typedef interface __FITypedEventHandler_2_Windows__CStorage__CProvider__CCachedFileUpdaterUI_Windows__CStorage__CProvider__CFileUpdateRequestedEventArgs __FITypedEventHandler_2_Windows__CStorage__CProvider__CCachedFileUpdaterUI_Windows__CStorage__CProvider__CFileUpdateRequestedEventArgs;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FITypedEventHandler_2_Windows__CStorage__CProvider__CCachedFileUpdaterUI_Windows__CStorage__CProvider__CFileUpdateRequestedEventArgs;

typedef struct __FITypedEventHandler_2_Windows__CStorage__CProvider__CCachedFileUpdaterUI_Windows__CStorage__CProvider__CFileUpdateRequestedEventArgsVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FITypedEventHandler_2_Windows__CStorage__CProvider__CCachedFileUpdaterUI_Windows__CStorage__CProvider__CFileUpdateRequestedEventArgs* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FITypedEventHandler_2_Windows__CStorage__CProvider__CCachedFileUpdaterUI_Windows__CStorage__CProvider__CFileUpdateRequestedEventArgs* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FITypedEventHandler_2_Windows__CStorage__CProvider__CCachedFileUpdaterUI_Windows__CStorage__CProvider__CFileUpdateRequestedEventArgs* This);
    HRESULT (STDMETHODCALLTYPE* Invoke)(__FITypedEventHandler_2_Windows__CStorage__CProvider__CCachedFileUpdaterUI_Windows__CStorage__CProvider__CFileUpdateRequestedEventArgs* This,
        __x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI* sender,
        __x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequestedEventArgs* args);

    END_INTERFACE
} __FITypedEventHandler_2_Windows__CStorage__CProvider__CCachedFileUpdaterUI_Windows__CStorage__CProvider__CFileUpdateRequestedEventArgsVtbl;

interface __FITypedEventHandler_2_Windows__CStorage__CProvider__CCachedFileUpdaterUI_Windows__CStorage__CProvider__CFileUpdateRequestedEventArgs
{
    CONST_VTBL struct __FITypedEventHandler_2_Windows__CStorage__CProvider__CCachedFileUpdaterUI_Windows__CStorage__CProvider__CFileUpdateRequestedEventArgsVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FITypedEventHandler_2_Windows__CStorage__CProvider__CCachedFileUpdaterUI_Windows__CStorage__CProvider__CFileUpdateRequestedEventArgs_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FITypedEventHandler_2_Windows__CStorage__CProvider__CCachedFileUpdaterUI_Windows__CStorage__CProvider__CFileUpdateRequestedEventArgs_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FITypedEventHandler_2_Windows__CStorage__CProvider__CCachedFileUpdaterUI_Windows__CStorage__CProvider__CFileUpdateRequestedEventArgs_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FITypedEventHandler_2_Windows__CStorage__CProvider__CCachedFileUpdaterUI_Windows__CStorage__CProvider__CFileUpdateRequestedEventArgs_Invoke(This, sender, args) \
    ((This)->lpVtbl->Invoke(This, sender, args))

#endif /* COBJMACROS */

#endif // ____FITypedEventHandler_2_Windows__CStorage__CProvider__CCachedFileUpdaterUI_Windows__CStorage__CProvider__CFileUpdateRequestedEventArgs_INTERFACE_DEFINED__
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x50000
#if !defined(____FITypedEventHandler_2_Windows__CStorage__CProvider__CIStorageProviderStatusSource_IInspectable_INTERFACE_DEFINED__)
#define ____FITypedEventHandler_2_Windows__CStorage__CProvider__CIStorageProviderStatusSource_IInspectable_INTERFACE_DEFINED__

typedef interface __FITypedEventHandler_2_Windows__CStorage__CProvider__CIStorageProviderStatusSource_IInspectable __FITypedEventHandler_2_Windows__CStorage__CProvider__CIStorageProviderStatusSource_IInspectable;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FITypedEventHandler_2_Windows__CStorage__CProvider__CIStorageProviderStatusSource_IInspectable;

typedef struct __FITypedEventHandler_2_Windows__CStorage__CProvider__CIStorageProviderStatusSource_IInspectableVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FITypedEventHandler_2_Windows__CStorage__CProvider__CIStorageProviderStatusSource_IInspectable* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FITypedEventHandler_2_Windows__CStorage__CProvider__CIStorageProviderStatusSource_IInspectable* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FITypedEventHandler_2_Windows__CStorage__CProvider__CIStorageProviderStatusSource_IInspectable* This);
    HRESULT (STDMETHODCALLTYPE* Invoke)(__FITypedEventHandler_2_Windows__CStorage__CProvider__CIStorageProviderStatusSource_IInspectable* This,
        __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusSource* sender,
        IInspectable* args);

    END_INTERFACE
} __FITypedEventHandler_2_Windows__CStorage__CProvider__CIStorageProviderStatusSource_IInspectableVtbl;

interface __FITypedEventHandler_2_Windows__CStorage__CProvider__CIStorageProviderStatusSource_IInspectable
{
    CONST_VTBL struct __FITypedEventHandler_2_Windows__CStorage__CProvider__CIStorageProviderStatusSource_IInspectableVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FITypedEventHandler_2_Windows__CStorage__CProvider__CIStorageProviderStatusSource_IInspectable_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FITypedEventHandler_2_Windows__CStorage__CProvider__CIStorageProviderStatusSource_IInspectable_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FITypedEventHandler_2_Windows__CStorage__CProvider__CIStorageProviderStatusSource_IInspectable_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FITypedEventHandler_2_Windows__CStorage__CProvider__CIStorageProviderStatusSource_IInspectable_Invoke(This, sender, args) \
    ((This)->lpVtbl->Invoke(This, sender, args))

#endif /* COBJMACROS */

#endif // ____FITypedEventHandler_2_Windows__CStorage__CProvider__CIStorageProviderStatusSource_IInspectable_INTERFACE_DEFINED__
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x50000

#ifndef ____x_ABI_CWindows_CFoundation_CIAsyncAction_FWD_DEFINED__
#define ____x_ABI_CWindows_CFoundation_CIAsyncAction_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CFoundation_CIAsyncAction __x_ABI_CWindows_CFoundation_CIAsyncAction;

#endif // ____x_ABI_CWindows_CFoundation_CIAsyncAction_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CFoundation_CIUriRuntimeClass_FWD_DEFINED__
#define ____x_ABI_CWindows_CFoundation_CIUriRuntimeClass_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CFoundation_CIUriRuntimeClass __x_ABI_CWindows_CFoundation_CIUriRuntimeClass;

#endif // ____x_ABI_CWindows_CFoundation_CIUriRuntimeClass_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CStorage_CIStorageFile_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CIStorageFile_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CStorage_CIStorageFile __x_ABI_CWindows_CStorage_CIStorageFile;

#endif // ____x_ABI_CWindows_CStorage_CIStorageFile_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CStorage_CIStorageFolder_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CIStorageFolder_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CStorage_CIStorageFolder __x_ABI_CWindows_CStorage_CIStorageFolder;

#endif // ____x_ABI_CWindows_CStorage_CIStorageFolder_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CStorage_CIStorageItem_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CIStorageItem_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CStorage_CIStorageItem __x_ABI_CWindows_CStorage_CIStorageItem;

#endif // ____x_ABI_CWindows_CStorage_CIStorageItem_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CStorage_CStreams_CIBuffer_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CStreams_CIBuffer_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CStorage_CStreams_CIBuffer __x_ABI_CWindows_CStorage_CStreams_CIBuffer;

#endif // ____x_ABI_CWindows_CStorage_CStreams_CIBuffer_FWD_DEFINED__

typedef enum __x_ABI_CWindows_CStorage_CProvider_CCachedFileOptions __x_ABI_CWindows_CStorage_CProvider_CCachedFileOptions;

typedef enum __x_ABI_CWindows_CStorage_CProvider_CCachedFileTarget __x_ABI_CWindows_CStorage_CProvider_CCachedFileTarget;

typedef enum __x_ABI_CWindows_CStorage_CProvider_CFileUpdateStatus __x_ABI_CWindows_CStorage_CProvider_CFileUpdateStatus;

typedef enum __x_ABI_CWindows_CStorage_CProvider_CReadActivationMode __x_ABI_CWindows_CStorage_CProvider_CReadActivationMode;

typedef enum __x_ABI_CWindows_CStorage_CProvider_CStorageProviderHardlinkPolicy __x_ABI_CWindows_CStorage_CProvider_CStorageProviderHardlinkPolicy;

typedef enum __x_ABI_CWindows_CStorage_CProvider_CStorageProviderHydrationPolicy __x_ABI_CWindows_CStorage_CProvider_CStorageProviderHydrationPolicy;

typedef enum __x_ABI_CWindows_CStorage_CProvider_CStorageProviderHydrationPolicyModifier __x_ABI_CWindows_CStorage_CProvider_CStorageProviderHydrationPolicyModifier;

typedef enum __x_ABI_CWindows_CStorage_CProvider_CStorageProviderInSyncPolicy __x_ABI_CWindows_CStorage_CProvider_CStorageProviderInSyncPolicy;

typedef enum __x_ABI_CWindows_CStorage_CProvider_CStorageProviderPopulationPolicy __x_ABI_CWindows_CStorage_CProvider_CStorageProviderPopulationPolicy;

typedef enum __x_ABI_CWindows_CStorage_CProvider_CStorageProviderProtectionMode __x_ABI_CWindows_CStorage_CProvider_CStorageProviderProtectionMode;

typedef enum __x_ABI_CWindows_CStorage_CProvider_CStorageProviderState __x_ABI_CWindows_CStorage_CProvider_CStorageProviderState;

typedef enum __x_ABI_CWindows_CStorage_CProvider_CStorageProviderUriSourceStatus __x_ABI_CWindows_CStorage_CProvider_CStorageProviderUriSourceStatus;

typedef enum __x_ABI_CWindows_CStorage_CProvider_CUIStatus __x_ABI_CWindows_CStorage_CProvider_CUIStatus;

typedef enum __x_ABI_CWindows_CStorage_CProvider_CWriteActivationMode __x_ABI_CWindows_CStorage_CProvider_CWriteActivationMode;

/*
 *
 * Struct Windows.Storage.Provider.CachedFileOptions
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
enum __x_ABI_CWindows_CStorage_CProvider_CCachedFileOptions
{
    CachedFileOptions_None = 0,
    CachedFileOptions_RequireUpdateOnAccess = 0x1,
    CachedFileOptions_UseCachedFileWhenOffline = 0x2,
    CachedFileOptions_DenyAccessWhenOffline = 0x4,
};
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Struct Windows.Storage.Provider.CachedFileTarget
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
enum __x_ABI_CWindows_CStorage_CProvider_CCachedFileTarget
{
    CachedFileTarget_Local = 0,
    CachedFileTarget_Remote = 1,
};
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Struct Windows.Storage.Provider.FileUpdateStatus
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
enum __x_ABI_CWindows_CStorage_CProvider_CFileUpdateStatus
{
    FileUpdateStatus_Incomplete = 0,
    FileUpdateStatus_Complete = 1,
    FileUpdateStatus_UserInputNeeded = 2,
    FileUpdateStatus_CurrentlyUnavailable = 3,
    FileUpdateStatus_Failed = 4,
    FileUpdateStatus_CompleteAndRenamed = 5,
};
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Struct Windows.Storage.Provider.ReadActivationMode
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
enum __x_ABI_CWindows_CStorage_CProvider_CReadActivationMode
{
    ReadActivationMode_NotNeeded = 0,
    ReadActivationMode_BeforeAccess = 1,
};
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Struct Windows.Storage.Provider.StorageProviderHardlinkPolicy
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 1.0
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000
enum __x_ABI_CWindows_CStorage_CProvider_CStorageProviderHardlinkPolicy
{
    StorageProviderHardlinkPolicy_None = 0,
    StorageProviderHardlinkPolicy_Allowed = 0x1,
};
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000

/*
 *
 * Struct Windows.Storage.Provider.StorageProviderHydrationPolicy
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 1.0
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000
enum __x_ABI_CWindows_CStorage_CProvider_CStorageProviderHydrationPolicy
{
    StorageProviderHydrationPolicy_Partial = 0,
    StorageProviderHydrationPolicy_Progressive = 1,
    StorageProviderHydrationPolicy_Full = 2,
    StorageProviderHydrationPolicy_AlwaysFull = 3,
};
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000

/*
 *
 * Struct Windows.Storage.Provider.StorageProviderHydrationPolicyModifier
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 1.0
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000
enum __x_ABI_CWindows_CStorage_CProvider_CStorageProviderHydrationPolicyModifier
{
    StorageProviderHydrationPolicyModifier_None = 0,
    StorageProviderHydrationPolicyModifier_ValidationRequired = 0x1,
    StorageProviderHydrationPolicyModifier_StreamingAllowed = 0x2,
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x30000
    StorageProviderHydrationPolicyModifier_AutoDehydrationAllowed = 0x4,
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x30000
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x60000
    StorageProviderHydrationPolicyModifier_AllowFullRestartHydration = 0x8,
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x60000
};
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000

/*
 *
 * Struct Windows.Storage.Provider.StorageProviderInSyncPolicy
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 1.0
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000
enum __x_ABI_CWindows_CStorage_CProvider_CStorageProviderInSyncPolicy
{
    StorageProviderInSyncPolicy_Default = 0,
    StorageProviderInSyncPolicy_FileCreationTime = 0x1,
    StorageProviderInSyncPolicy_FileReadOnlyAttribute = 0x2,
    StorageProviderInSyncPolicy_FileHiddenAttribute = 0x4,
    StorageProviderInSyncPolicy_FileSystemAttribute = 0x8,
    StorageProviderInSyncPolicy_DirectoryCreationTime = 0x10,
    StorageProviderInSyncPolicy_DirectoryReadOnlyAttribute = 0x20,
    StorageProviderInSyncPolicy_DirectoryHiddenAttribute = 0x40,
    StorageProviderInSyncPolicy_DirectorySystemAttribute = 0x80,
    StorageProviderInSyncPolicy_FileLastWriteTime = 0x100,
    StorageProviderInSyncPolicy_DirectoryLastWriteTime = 0x200,
    StorageProviderInSyncPolicy_PreserveInsyncForSyncEngine = 0x80000000,
};
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000

/*
 *
 * Struct Windows.Storage.Provider.StorageProviderPopulationPolicy
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 1.0
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000
enum __x_ABI_CWindows_CStorage_CProvider_CStorageProviderPopulationPolicy
{
    StorageProviderPopulationPolicy_Full = 1,
    StorageProviderPopulationPolicy_AlwaysFull = 2,
};
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000

/*
 *
 * Struct Windows.Storage.Provider.StorageProviderProtectionMode
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 1.0
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000
enum __x_ABI_CWindows_CStorage_CProvider_CStorageProviderProtectionMode
{
    StorageProviderProtectionMode_Unknown = 0,
    StorageProviderProtectionMode_Personal = 1,
};
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000

/*
 *
 * Struct Windows.Storage.Provider.StorageProviderState
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 5.0
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x50000
enum __x_ABI_CWindows_CStorage_CProvider_CStorageProviderState
{
    StorageProviderState_InSync = 0,
    StorageProviderState_Syncing = 1,
    StorageProviderState_Paused = 2,
    StorageProviderState_Error = 3,
    StorageProviderState_Warning = 4,
    StorageProviderState_Offline = 5,
};
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x50000

/*
 *
 * Struct Windows.Storage.Provider.StorageProviderUriSourceStatus
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 2.0
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x20000
enum __x_ABI_CWindows_CStorage_CProvider_CStorageProviderUriSourceStatus
{
    StorageProviderUriSourceStatus_Success = 0,
    StorageProviderUriSourceStatus_NoSyncRoot = 1,
    StorageProviderUriSourceStatus_FileNotFound = 2,
};
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x20000

/*
 *
 * Struct Windows.Storage.Provider.UIStatus
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
enum __x_ABI_CWindows_CStorage_CProvider_CUIStatus
{
    UIStatus_Unavailable = 0,
    UIStatus_Hidden = 1,
    UIStatus_Visible = 2,
    UIStatus_Complete = 3,
};
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Struct Windows.Storage.Provider.WriteActivationMode
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
enum __x_ABI_CWindows_CStorage_CProvider_CWriteActivationMode
{
    WriteActivationMode_ReadOnly = 0,
    WriteActivationMode_NotNeeded = 1,
    WriteActivationMode_AfterWrite = 2,
};
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Storage.Provider.ICachedFileUpdaterStatics
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Storage.Provider.CachedFileUpdater
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Storage_Provider_ICachedFileUpdaterStatics[] = L"Windows.Storage.Provider.ICachedFileUpdaterStatics";
typedef struct __x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterStaticsVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterStatics* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterStatics* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterStatics* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterStatics* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterStatics* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterStatics* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* SetUpdateInformation)(__x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterStatics* This,
        __x_ABI_CWindows_CStorage_CIStorageFile* file,
        HSTRING contentId,
        enum __x_ABI_CWindows_CStorage_CProvider_CReadActivationMode readMode,
        enum __x_ABI_CWindows_CStorage_CProvider_CWriteActivationMode writeMode,
        enum __x_ABI_CWindows_CStorage_CProvider_CCachedFileOptions options);

    END_INTERFACE
} __x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterStaticsVtbl;

interface __x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterStatics
{
    CONST_VTBL struct __x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterStaticsVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterStatics_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterStatics_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterStatics_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterStatics_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterStatics_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterStatics_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterStatics_SetUpdateInformation(This, file, contentId, readMode, writeMode, options) \
    ((This)->lpVtbl->SetUpdateInformation(This, file, contentId, readMode, writeMode, options))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterStatics;
#endif /* !defined(____x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterStatics_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Storage.Provider.ICachedFileUpdaterUI
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Storage.Provider.CachedFileUpdaterUI
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Storage_Provider_ICachedFileUpdaterUI[] = L"Windows.Storage.Provider.ICachedFileUpdaterUI";
typedef struct __x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUIVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Title)(__x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* put_Title)(__x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI* This,
        HSTRING value);
    HRESULT (STDMETHODCALLTYPE* get_UpdateTarget)(__x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI* This,
        enum __x_ABI_CWindows_CStorage_CProvider_CCachedFileTarget* value);
    HRESULT (STDMETHODCALLTYPE* add_FileUpdateRequested)(__x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI* This,
        __FITypedEventHandler_2_Windows__CStorage__CProvider__CCachedFileUpdaterUI_Windows__CStorage__CProvider__CFileUpdateRequestedEventArgs* handler,
        EventRegistrationToken* token);
    HRESULT (STDMETHODCALLTYPE* remove_FileUpdateRequested)(__x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI* This,
        EventRegistrationToken token);
    HRESULT (STDMETHODCALLTYPE* add_UIRequested)(__x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI* This,
        __FITypedEventHandler_2_Windows__CStorage__CProvider__CCachedFileUpdaterUI_IInspectable* handler,
        EventRegistrationToken* token);
    HRESULT (STDMETHODCALLTYPE* remove_UIRequested)(__x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI* This,
        EventRegistrationToken token);
    HRESULT (STDMETHODCALLTYPE* get_UIStatus)(__x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI* This,
        enum __x_ABI_CWindows_CStorage_CProvider_CUIStatus* value);

    END_INTERFACE
} __x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUIVtbl;

interface __x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI
{
    CONST_VTBL struct __x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUIVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI_get_Title(This, value) \
    ((This)->lpVtbl->get_Title(This, value))

#define __x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI_put_Title(This, value) \
    ((This)->lpVtbl->put_Title(This, value))

#define __x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI_get_UpdateTarget(This, value) \
    ((This)->lpVtbl->get_UpdateTarget(This, value))

#define __x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI_add_FileUpdateRequested(This, handler, token) \
    ((This)->lpVtbl->add_FileUpdateRequested(This, handler, token))

#define __x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI_remove_FileUpdateRequested(This, token) \
    ((This)->lpVtbl->remove_FileUpdateRequested(This, token))

#define __x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI_add_UIRequested(This, handler, token) \
    ((This)->lpVtbl->add_UIRequested(This, handler, token))

#define __x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI_remove_UIRequested(This, token) \
    ((This)->lpVtbl->remove_UIRequested(This, token))

#define __x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI_get_UIStatus(This, value) \
    ((This)->lpVtbl->get_UIStatus(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI;
#endif /* !defined(____x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Storage.Provider.ICachedFileUpdaterUI2
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Storage.Provider.CachedFileUpdaterUI
 *
 * Any object which implements this interface must also implement the following interfaces:
 *     Windows.Storage.Provider.ICachedFileUpdaterUI
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI2_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI2_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Storage_Provider_ICachedFileUpdaterUI2[] = L"Windows.Storage.Provider.ICachedFileUpdaterUI2";
typedef struct __x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI2Vtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI2* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI2* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI2* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI2* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI2* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI2* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_UpdateRequest)(__x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI2* This,
        __x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest** value);
    HRESULT (STDMETHODCALLTYPE* GetDeferral)(__x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI2* This,
        __x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequestDeferral** value);

    END_INTERFACE
} __x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI2Vtbl;

interface __x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI2
{
    CONST_VTBL struct __x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI2Vtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI2_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI2_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI2_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI2_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI2_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI2_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI2_get_UpdateRequest(This, value) \
    ((This)->lpVtbl->get_UpdateRequest(This, value))

#define __x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI2_GetDeferral(This, value) \
    ((This)->lpVtbl->GetDeferral(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI2;
#endif /* !defined(____x_ABI_CWindows_CStorage_CProvider_CICachedFileUpdaterUI2_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Storage.Provider.IFileUpdateRequest
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Storage.Provider.FileUpdateRequest
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Storage_Provider_IFileUpdateRequest[] = L"Windows.Storage.Provider.IFileUpdateRequest";
typedef struct __x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequestVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_ContentId)(__x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* get_File)(__x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest* This,
        __x_ABI_CWindows_CStorage_CIStorageFile** value);
    HRESULT (STDMETHODCALLTYPE* get_Status)(__x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest* This,
        enum __x_ABI_CWindows_CStorage_CProvider_CFileUpdateStatus* value);
    HRESULT (STDMETHODCALLTYPE* put_Status)(__x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest* This,
        enum __x_ABI_CWindows_CStorage_CProvider_CFileUpdateStatus value);
    HRESULT (STDMETHODCALLTYPE* GetDeferral)(__x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest* This,
        __x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequestDeferral** value);
    HRESULT (STDMETHODCALLTYPE* UpdateLocalFile)(__x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest* This,
        __x_ABI_CWindows_CStorage_CIStorageFile* value);

    END_INTERFACE
} __x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequestVtbl;

interface __x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest
{
    CONST_VTBL struct __x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequestVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest_get_ContentId(This, value) \
    ((This)->lpVtbl->get_ContentId(This, value))

#define __x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest_get_File(This, value) \
    ((This)->lpVtbl->get_File(This, value))

#define __x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest_get_Status(This, value) \
    ((This)->lpVtbl->get_Status(This, value))

#define __x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest_put_Status(This, value) \
    ((This)->lpVtbl->put_Status(This, value))

#define __x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest_GetDeferral(This, value) \
    ((This)->lpVtbl->GetDeferral(This, value))

#define __x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest_UpdateLocalFile(This, value) \
    ((This)->lpVtbl->UpdateLocalFile(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest;
#endif /* !defined(____x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Storage.Provider.IFileUpdateRequest2
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Storage.Provider.FileUpdateRequest
 *
 * Any object which implements this interface must also implement the following interfaces:
 *     Windows.Storage.Provider.IFileUpdateRequest
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest2_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest2_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Storage_Provider_IFileUpdateRequest2[] = L"Windows.Storage.Provider.IFileUpdateRequest2";
typedef struct __x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest2Vtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest2* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest2* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest2* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest2* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest2* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest2* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_UserInputNeededMessage)(__x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest2* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* put_UserInputNeededMessage)(__x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest2* This,
        HSTRING value);

    END_INTERFACE
} __x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest2Vtbl;

interface __x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest2
{
    CONST_VTBL struct __x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest2Vtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest2_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest2_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest2_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest2_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest2_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest2_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest2_get_UserInputNeededMessage(This, value) \
    ((This)->lpVtbl->get_UserInputNeededMessage(This, value))

#define __x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest2_put_UserInputNeededMessage(This, value) \
    ((This)->lpVtbl->put_UserInputNeededMessage(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest2;
#endif /* !defined(____x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest2_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Storage.Provider.IFileUpdateRequestDeferral
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Storage.Provider.FileUpdateRequestDeferral
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequestDeferral_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequestDeferral_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Storage_Provider_IFileUpdateRequestDeferral[] = L"Windows.Storage.Provider.IFileUpdateRequestDeferral";
typedef struct __x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequestDeferralVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequestDeferral* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequestDeferral* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequestDeferral* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequestDeferral* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequestDeferral* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequestDeferral* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* Complete)(__x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequestDeferral* This);

    END_INTERFACE
} __x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequestDeferralVtbl;

interface __x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequestDeferral
{
    CONST_VTBL struct __x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequestDeferralVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequestDeferral_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequestDeferral_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequestDeferral_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequestDeferral_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequestDeferral_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequestDeferral_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequestDeferral_Complete(This) \
    ((This)->lpVtbl->Complete(This))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequestDeferral;
#endif /* !defined(____x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequestDeferral_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Storage.Provider.IFileUpdateRequestedEventArgs
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Storage.Provider.FileUpdateRequestedEventArgs
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequestedEventArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequestedEventArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Storage_Provider_IFileUpdateRequestedEventArgs[] = L"Windows.Storage.Provider.IFileUpdateRequestedEventArgs";
typedef struct __x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequestedEventArgsVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequestedEventArgs* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequestedEventArgs* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequestedEventArgs* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequestedEventArgs* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequestedEventArgs* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequestedEventArgs* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Request)(__x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequestedEventArgs* This,
        __x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequest** value);

    END_INTERFACE
} __x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequestedEventArgsVtbl;

interface __x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequestedEventArgs
{
    CONST_VTBL struct __x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequestedEventArgsVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequestedEventArgs_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequestedEventArgs_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequestedEventArgs_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequestedEventArgs_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequestedEventArgs_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequestedEventArgs_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequestedEventArgs_get_Request(This, value) \
    ((This)->lpVtbl->get_Request(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequestedEventArgs;
#endif /* !defined(____x_ABI_CWindows_CStorage_CProvider_CIFileUpdateRequestedEventArgs_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Storage.Provider.IStorageProviderError
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 5.0
 *
 * Interface is a part of the implementation of type Windows.Storage.Provider.StorageProviderError
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderError_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderError_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Storage_Provider_IStorageProviderError[] = L"Windows.Storage.Provider.IStorageProviderError";
typedef struct __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderError* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderError* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderError* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderError* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderError* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderError* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Id)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderError* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* get_Title)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderError* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* get_Message)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderError* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* get_FilePath)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderError* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* put_FilePath)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderError* This,
        HSTRING value);
    HRESULT (STDMETHODCALLTYPE* get_PrimaryAction)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderError* This,
        __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommand** value);
    HRESULT (STDMETHODCALLTYPE* put_PrimaryAction)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderError* This,
        __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommand* value);
    HRESULT (STDMETHODCALLTYPE* get_SecondaryAction)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderError* This,
        __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommand** value);
    HRESULT (STDMETHODCALLTYPE* put_SecondaryAction)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderError* This,
        __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommand* value);
    HRESULT (STDMETHODCALLTYPE* get_InformationalLink)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderError* This,
        __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommand** value);
    HRESULT (STDMETHODCALLTYPE* put_InformationalLink)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderError* This,
        __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommand* value);

    END_INTERFACE
} __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorVtbl;

interface __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderError
{
    CONST_VTBL struct __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderError_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderError_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderError_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderError_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderError_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderError_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderError_get_Id(This, value) \
    ((This)->lpVtbl->get_Id(This, value))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderError_get_Title(This, value) \
    ((This)->lpVtbl->get_Title(This, value))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderError_get_Message(This, value) \
    ((This)->lpVtbl->get_Message(This, value))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderError_get_FilePath(This, value) \
    ((This)->lpVtbl->get_FilePath(This, value))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderError_put_FilePath(This, value) \
    ((This)->lpVtbl->put_FilePath(This, value))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderError_get_PrimaryAction(This, value) \
    ((This)->lpVtbl->get_PrimaryAction(This, value))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderError_put_PrimaryAction(This, value) \
    ((This)->lpVtbl->put_PrimaryAction(This, value))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderError_get_SecondaryAction(This, value) \
    ((This)->lpVtbl->get_SecondaryAction(This, value))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderError_put_SecondaryAction(This, value) \
    ((This)->lpVtbl->put_SecondaryAction(This, value))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderError_get_InformationalLink(This, value) \
    ((This)->lpVtbl->get_InformationalLink(This, value))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderError_put_InformationalLink(This, value) \
    ((This)->lpVtbl->put_InformationalLink(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CStorage_CProvider_CIStorageProviderError;
#endif /* !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderError_INTERFACE_DEFINED__) */
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x50000

/*
 *
 * Interface Windows.Storage.Provider.IStorageProviderErrorCommand
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 5.0
 *
 * Interface is a part of the implementation of type Windows.Storage.Provider.StorageProviderErrorCommand
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommand_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommand_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Storage_Provider_IStorageProviderErrorCommand[] = L"Windows.Storage.Provider.IStorageProviderErrorCommand";
typedef struct __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommandVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommand* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommand* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommand* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommand* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommand* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommand* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Label)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommand* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* get_ActionUri)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommand* This,
        __x_ABI_CWindows_CFoundation_CIUriRuntimeClass** value);

    END_INTERFACE
} __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommandVtbl;

interface __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommand
{
    CONST_VTBL struct __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommandVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommand_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommand_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommand_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommand_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommand_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommand_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommand_get_Label(This, value) \
    ((This)->lpVtbl->get_Label(This, value))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommand_get_ActionUri(This, value) \
    ((This)->lpVtbl->get_ActionUri(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommand;
#endif /* !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommand_INTERFACE_DEFINED__) */
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x50000

/*
 *
 * Interface Windows.Storage.Provider.IStorageProviderErrorCommandFactory
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 5.0
 *
 * Interface is a part of the implementation of type Windows.Storage.Provider.StorageProviderErrorCommand
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommandFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommandFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Storage_Provider_IStorageProviderErrorCommandFactory[] = L"Windows.Storage.Provider.IStorageProviderErrorCommandFactory";
typedef struct __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommandFactoryVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommandFactory* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommandFactory* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommandFactory* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommandFactory* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommandFactory* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommandFactory* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* CreateInstance)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommandFactory* This,
        HSTRING label,
        __x_ABI_CWindows_CFoundation_CIUriRuntimeClass* actionUri,
        __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommand** value);

    END_INTERFACE
} __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommandFactoryVtbl;

interface __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommandFactory
{
    CONST_VTBL struct __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommandFactoryVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommandFactory_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommandFactory_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommandFactory_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommandFactory_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommandFactory_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommandFactory_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommandFactory_CreateInstance(This, label, actionUri, value) \
    ((This)->lpVtbl->CreateInstance(This, label, actionUri, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommandFactory;
#endif /* !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorCommandFactory_INTERFACE_DEFINED__) */
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x50000

/*
 *
 * Interface Windows.Storage.Provider.IStorageProviderErrorFactory
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 5.0
 *
 * Interface is a part of the implementation of type Windows.Storage.Provider.StorageProviderError
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Storage_Provider_IStorageProviderErrorFactory[] = L"Windows.Storage.Provider.IStorageProviderErrorFactory";
typedef struct __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorFactoryVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorFactory* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorFactory* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorFactory* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorFactory* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorFactory* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorFactory* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* CreateInstance)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorFactory* This,
        HSTRING id,
        HSTRING title,
        HSTRING message,
        __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderError** value);

    END_INTERFACE
} __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorFactoryVtbl;

interface __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorFactory
{
    CONST_VTBL struct __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorFactoryVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorFactory_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorFactory_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorFactory_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorFactory_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorFactory_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorFactory_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorFactory_CreateInstance(This, id, title, message, value) \
    ((This)->lpVtbl->CreateInstance(This, id, title, message, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorFactory;
#endif /* !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderErrorFactory_INTERFACE_DEFINED__) */
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x50000

/*
 *
 * Interface Windows.Storage.Provider.IStorageProviderFileTypeInfo
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 4.0
 *
 * Interface is a part of the implementation of type Windows.Storage.Provider.StorageProviderFileTypeInfo
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x40000
#if !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfo_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfo_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Storage_Provider_IStorageProviderFileTypeInfo[] = L"Windows.Storage.Provider.IStorageProviderFileTypeInfo";
typedef struct __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfoVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfo* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfo* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfo* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfo* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfo* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfo* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_FileExtension)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfo* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* get_IconResource)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfo* This,
        HSTRING* value);

    END_INTERFACE
} __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfoVtbl;

interface __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfo
{
    CONST_VTBL struct __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfoVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfo_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfo_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfo_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfo_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfo_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfo_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfo_get_FileExtension(This, value) \
    ((This)->lpVtbl->get_FileExtension(This, value))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfo_get_IconResource(This, value) \
    ((This)->lpVtbl->get_IconResource(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfo;
#endif /* !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfo_INTERFACE_DEFINED__) */
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x40000

/*
 *
 * Interface Windows.Storage.Provider.IStorageProviderFileTypeInfoFactory
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 4.0
 *
 * Interface is a part of the implementation of type Windows.Storage.Provider.StorageProviderFileTypeInfo
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x40000
#if !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfoFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfoFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Storage_Provider_IStorageProviderFileTypeInfoFactory[] = L"Windows.Storage.Provider.IStorageProviderFileTypeInfoFactory";
typedef struct __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfoFactoryVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfoFactory* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfoFactory* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfoFactory* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfoFactory* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfoFactory* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfoFactory* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* CreateInstance)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfoFactory* This,
        HSTRING fileExtension,
        HSTRING iconResource,
        __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfo** value);

    END_INTERFACE
} __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfoFactoryVtbl;

interface __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfoFactory
{
    CONST_VTBL struct __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfoFactoryVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfoFactory_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfoFactory_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfoFactory_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfoFactory_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfoFactory_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfoFactory_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfoFactory_CreateInstance(This, fileExtension, iconResource, value) \
    ((This)->lpVtbl->CreateInstance(This, fileExtension, iconResource, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfoFactory;
#endif /* !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderFileTypeInfoFactory_INTERFACE_DEFINED__) */
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x40000

/*
 *
 * Interface Windows.Storage.Provider.IStorageProviderGetContentInfoForPathResult
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 2.0
 *
 * Interface is a part of the implementation of type Windows.Storage.Provider.StorageProviderGetContentInfoForPathResult
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x20000
#if !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetContentInfoForPathResult_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetContentInfoForPathResult_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Storage_Provider_IStorageProviderGetContentInfoForPathResult[] = L"Windows.Storage.Provider.IStorageProviderGetContentInfoForPathResult";
typedef struct __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetContentInfoForPathResultVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetContentInfoForPathResult* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetContentInfoForPathResult* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetContentInfoForPathResult* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetContentInfoForPathResult* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetContentInfoForPathResult* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetContentInfoForPathResult* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Status)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetContentInfoForPathResult* This,
        enum __x_ABI_CWindows_CStorage_CProvider_CStorageProviderUriSourceStatus* value);
    HRESULT (STDMETHODCALLTYPE* put_Status)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetContentInfoForPathResult* This,
        enum __x_ABI_CWindows_CStorage_CProvider_CStorageProviderUriSourceStatus value);
    HRESULT (STDMETHODCALLTYPE* get_ContentUri)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetContentInfoForPathResult* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* put_ContentUri)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetContentInfoForPathResult* This,
        HSTRING value);
    HRESULT (STDMETHODCALLTYPE* get_ContentId)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetContentInfoForPathResult* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* put_ContentId)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetContentInfoForPathResult* This,
        HSTRING value);

    END_INTERFACE
} __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetContentInfoForPathResultVtbl;

interface __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetContentInfoForPathResult
{
    CONST_VTBL struct __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetContentInfoForPathResultVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetContentInfoForPathResult_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetContentInfoForPathResult_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetContentInfoForPathResult_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetContentInfoForPathResult_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetContentInfoForPathResult_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetContentInfoForPathResult_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetContentInfoForPathResult_get_Status(This, value) \
    ((This)->lpVtbl->get_Status(This, value))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetContentInfoForPathResult_put_Status(This, value) \
    ((This)->lpVtbl->put_Status(This, value))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetContentInfoForPathResult_get_ContentUri(This, value) \
    ((This)->lpVtbl->get_ContentUri(This, value))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetContentInfoForPathResult_put_ContentUri(This, value) \
    ((This)->lpVtbl->put_ContentUri(This, value))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetContentInfoForPathResult_get_ContentId(This, value) \
    ((This)->lpVtbl->get_ContentId(This, value))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetContentInfoForPathResult_put_ContentId(This, value) \
    ((This)->lpVtbl->put_ContentId(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetContentInfoForPathResult;
#endif /* !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetContentInfoForPathResult_INTERFACE_DEFINED__) */
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x20000

/*
 *
 * Interface Windows.Storage.Provider.IStorageProviderGetPathForContentUriResult
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 2.0
 *
 * Interface is a part of the implementation of type Windows.Storage.Provider.StorageProviderGetPathForContentUriResult
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x20000
#if !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetPathForContentUriResult_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetPathForContentUriResult_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Storage_Provider_IStorageProviderGetPathForContentUriResult[] = L"Windows.Storage.Provider.IStorageProviderGetPathForContentUriResult";
typedef struct __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetPathForContentUriResultVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetPathForContentUriResult* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetPathForContentUriResult* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetPathForContentUriResult* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetPathForContentUriResult* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetPathForContentUriResult* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetPathForContentUriResult* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Status)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetPathForContentUriResult* This,
        enum __x_ABI_CWindows_CStorage_CProvider_CStorageProviderUriSourceStatus* value);
    HRESULT (STDMETHODCALLTYPE* put_Status)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetPathForContentUriResult* This,
        enum __x_ABI_CWindows_CStorage_CProvider_CStorageProviderUriSourceStatus value);
    HRESULT (STDMETHODCALLTYPE* get_Path)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetPathForContentUriResult* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* put_Path)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetPathForContentUriResult* This,
        HSTRING value);

    END_INTERFACE
} __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetPathForContentUriResultVtbl;

interface __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetPathForContentUriResult
{
    CONST_VTBL struct __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetPathForContentUriResultVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetPathForContentUriResult_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetPathForContentUriResult_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetPathForContentUriResult_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetPathForContentUriResult_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetPathForContentUriResult_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetPathForContentUriResult_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetPathForContentUriResult_get_Status(This, value) \
    ((This)->lpVtbl->get_Status(This, value))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetPathForContentUriResult_put_Status(This, value) \
    ((This)->lpVtbl->put_Status(This, value))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetPathForContentUriResult_get_Path(This, value) \
    ((This)->lpVtbl->get_Path(This, value))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetPathForContentUriResult_put_Path(This, value) \
    ((This)->lpVtbl->put_Path(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetPathForContentUriResult;
#endif /* !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetPathForContentUriResult_INTERFACE_DEFINED__) */
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x20000

/*
 *
 * Interface Windows.Storage.Provider.IStorageProviderHandlerFactory
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 5.0
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderHandlerFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderHandlerFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Storage_Provider_IStorageProviderHandlerFactory[] = L"Windows.Storage.Provider.IStorageProviderHandlerFactory";
typedef struct __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderHandlerFactoryVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderHandlerFactory* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderHandlerFactory* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderHandlerFactory* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderHandlerFactory* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderHandlerFactory* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderHandlerFactory* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* GetStatusSource)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderHandlerFactory* This,
        HSTRING syncRootId,
        __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusSource** result);

    END_INTERFACE
} __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderHandlerFactoryVtbl;

interface __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderHandlerFactory
{
    CONST_VTBL struct __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderHandlerFactoryVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderHandlerFactory_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderHandlerFactory_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderHandlerFactory_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderHandlerFactory_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderHandlerFactory_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderHandlerFactory_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderHandlerFactory_GetStatusSource(This, syncRootId, result) \
    ((This)->lpVtbl->GetStatusSource(This, syncRootId, result))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CStorage_CProvider_CIStorageProviderHandlerFactory;
#endif /* !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderHandlerFactory_INTERFACE_DEFINED__) */
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x50000

/*
 *
 * Interface Windows.Storage.Provider.IStorageProviderItemPropertiesStatics
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Storage.Provider.StorageProviderItemProperties
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertiesStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertiesStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Storage_Provider_IStorageProviderItemPropertiesStatics[] = L"Windows.Storage.Provider.IStorageProviderItemPropertiesStatics";
typedef struct __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertiesStaticsVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertiesStatics* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertiesStatics* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertiesStatics* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertiesStatics* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertiesStatics* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertiesStatics* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* SetAsync)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertiesStatics* This,
        __x_ABI_CWindows_CStorage_CIStorageItem* item,
        __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderItemProperty* itemProperties,
        __x_ABI_CWindows_CFoundation_CIAsyncAction** operation);

    END_INTERFACE
} __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertiesStaticsVtbl;

interface __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertiesStatics
{
    CONST_VTBL struct __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertiesStaticsVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertiesStatics_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertiesStatics_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertiesStatics_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertiesStatics_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertiesStatics_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertiesStatics_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertiesStatics_SetAsync(This, item, itemProperties, operation) \
    ((This)->lpVtbl->SetAsync(This, item, itemProperties, operation))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertiesStatics;
#endif /* !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertiesStatics_INTERFACE_DEFINED__) */
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Storage.Provider.IStorageProviderItemProperty
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Storage.Provider.StorageProviderItemProperty
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemProperty_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemProperty_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Storage_Provider_IStorageProviderItemProperty[] = L"Windows.Storage.Provider.IStorageProviderItemProperty";
typedef struct __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertyVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemProperty* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemProperty* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemProperty* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemProperty* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemProperty* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemProperty* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* put_Id)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemProperty* This,
        INT32 value);
    HRESULT (STDMETHODCALLTYPE* get_Id)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemProperty* This,
        INT32* value);
    HRESULT (STDMETHODCALLTYPE* put_Value)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemProperty* This,
        HSTRING value);
    HRESULT (STDMETHODCALLTYPE* get_Value)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemProperty* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* put_IconResource)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemProperty* This,
        HSTRING value);
    HRESULT (STDMETHODCALLTYPE* get_IconResource)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemProperty* This,
        HSTRING* value);

    END_INTERFACE
} __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertyVtbl;

interface __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemProperty
{
    CONST_VTBL struct __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertyVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemProperty_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemProperty_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemProperty_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemProperty_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemProperty_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemProperty_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemProperty_put_Id(This, value) \
    ((This)->lpVtbl->put_Id(This, value))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemProperty_get_Id(This, value) \
    ((This)->lpVtbl->get_Id(This, value))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemProperty_put_Value(This, value) \
    ((This)->lpVtbl->put_Value(This, value))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemProperty_get_Value(This, value) \
    ((This)->lpVtbl->get_Value(This, value))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemProperty_put_IconResource(This, value) \
    ((This)->lpVtbl->put_IconResource(This, value))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemProperty_get_IconResource(This, value) \
    ((This)->lpVtbl->get_IconResource(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemProperty;
#endif /* !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemProperty_INTERFACE_DEFINED__) */
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Storage.Provider.IStorageProviderItemPropertyDefinition
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Storage.Provider.StorageProviderItemPropertyDefinition
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertyDefinition_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertyDefinition_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Storage_Provider_IStorageProviderItemPropertyDefinition[] = L"Windows.Storage.Provider.IStorageProviderItemPropertyDefinition";
typedef struct __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertyDefinitionVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertyDefinition* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertyDefinition* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertyDefinition* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertyDefinition* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertyDefinition* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertyDefinition* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Id)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertyDefinition* This,
        INT32* value);
    HRESULT (STDMETHODCALLTYPE* put_Id)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertyDefinition* This,
        INT32 value);
    HRESULT (STDMETHODCALLTYPE* get_DisplayNameResource)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertyDefinition* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* put_DisplayNameResource)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertyDefinition* This,
        HSTRING value);

    END_INTERFACE
} __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertyDefinitionVtbl;

interface __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertyDefinition
{
    CONST_VTBL struct __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertyDefinitionVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertyDefinition_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertyDefinition_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertyDefinition_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertyDefinition_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertyDefinition_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertyDefinition_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertyDefinition_get_Id(This, value) \
    ((This)->lpVtbl->get_Id(This, value))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertyDefinition_put_Id(This, value) \
    ((This)->lpVtbl->put_Id(This, value))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertyDefinition_get_DisplayNameResource(This, value) \
    ((This)->lpVtbl->get_DisplayNameResource(This, value))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertyDefinition_put_DisplayNameResource(This, value) \
    ((This)->lpVtbl->put_DisplayNameResource(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertyDefinition;
#endif /* !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertyDefinition_INTERFACE_DEFINED__) */
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Storage.Provider.IStorageProviderItemPropertySource
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 1.0
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertySource_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertySource_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Storage_Provider_IStorageProviderItemPropertySource[] = L"Windows.Storage.Provider.IStorageProviderItemPropertySource";
typedef struct __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertySourceVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertySource* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertySource* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertySource* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertySource* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertySource* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertySource* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* GetItemProperties)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertySource* This,
        HSTRING itemPath,
        __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderItemProperty** result);

    END_INTERFACE
} __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertySourceVtbl;

interface __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertySource
{
    CONST_VTBL struct __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertySourceVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertySource_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertySource_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertySource_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertySource_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertySource_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertySource_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertySource_GetItemProperties(This, itemPath, result) \
    ((This)->lpVtbl->GetItemProperties(This, itemPath, result))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertySource;
#endif /* !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderItemPropertySource_INTERFACE_DEFINED__) */
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Storage.Provider.IStorageProviderPropertyCapabilities
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 1.0
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderPropertyCapabilities_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderPropertyCapabilities_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Storage_Provider_IStorageProviderPropertyCapabilities[] = L"Windows.Storage.Provider.IStorageProviderPropertyCapabilities";
typedef struct __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderPropertyCapabilitiesVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderPropertyCapabilities* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderPropertyCapabilities* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderPropertyCapabilities* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderPropertyCapabilities* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderPropertyCapabilities* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderPropertyCapabilities* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* IsPropertySupported)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderPropertyCapabilities* This,
        HSTRING propertyCanonicalName,
        boolean* isSupported);

    END_INTERFACE
} __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderPropertyCapabilitiesVtbl;

interface __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderPropertyCapabilities
{
    CONST_VTBL struct __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderPropertyCapabilitiesVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderPropertyCapabilities_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderPropertyCapabilities_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderPropertyCapabilities_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderPropertyCapabilities_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderPropertyCapabilities_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderPropertyCapabilities_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderPropertyCapabilities_IsPropertySupported(This, propertyCanonicalName, isSupported) \
    ((This)->lpVtbl->IsPropertySupported(This, propertyCanonicalName, isSupported))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CStorage_CProvider_CIStorageProviderPropertyCapabilities;
#endif /* !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderPropertyCapabilities_INTERFACE_DEFINED__) */
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Storage.Provider.IStorageProviderStatus
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 5.0
 *
 * Interface is a part of the implementation of type Windows.Storage.Provider.StorageProviderStatus
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatus_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatus_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Storage_Provider_IStorageProviderStatus[] = L"Windows.Storage.Provider.IStorageProviderStatus";
typedef struct __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatus* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatus* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatus* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatus* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatus* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatus* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Message)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatus* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* get_State)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatus* This,
        enum __x_ABI_CWindows_CStorage_CProvider_CStorageProviderState* value);
    HRESULT (STDMETHODCALLTYPE* get_ErrorMessages)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatus* This,
        __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderError** value);

    END_INTERFACE
} __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusVtbl;

interface __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatus
{
    CONST_VTBL struct __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatus_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatus_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatus_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatus_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatus_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatus_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatus_get_Message(This, value) \
    ((This)->lpVtbl->get_Message(This, value))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatus_get_State(This, value) \
    ((This)->lpVtbl->get_State(This, value))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatus_get_ErrorMessages(This, value) \
    ((This)->lpVtbl->get_ErrorMessages(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatus;
#endif /* !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatus_INTERFACE_DEFINED__) */
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x50000

/*
 *
 * Interface Windows.Storage.Provider.IStorageProviderStatusFactory
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 5.0
 *
 * Interface is a part of the implementation of type Windows.Storage.Provider.StorageProviderStatus
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Storage_Provider_IStorageProviderStatusFactory[] = L"Windows.Storage.Provider.IStorageProviderStatusFactory";
typedef struct __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusFactoryVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusFactory* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusFactory* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusFactory* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusFactory* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusFactory* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusFactory* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* CreateInstance)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusFactory* This,
        enum __x_ABI_CWindows_CStorage_CProvider_CStorageProviderState state,
        HSTRING message,
        __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatus** value);
    HRESULT (STDMETHODCALLTYPE* CreateInstance2)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusFactory* This,
        enum __x_ABI_CWindows_CStorage_CProvider_CStorageProviderState state,
        HSTRING message,
        __FIIterable_1_Windows__CStorage__CProvider__CStorageProviderError* errorMessages,
        __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatus** value);

    END_INTERFACE
} __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusFactoryVtbl;

interface __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusFactory
{
    CONST_VTBL struct __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusFactoryVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusFactory_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusFactory_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusFactory_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusFactory_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusFactory_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusFactory_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusFactory_CreateInstance(This, state, message, value) \
    ((This)->lpVtbl->CreateInstance(This, state, message, value))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusFactory_CreateInstance2(This, state, message, errorMessages, value) \
    ((This)->lpVtbl->CreateInstance2(This, state, message, errorMessages, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusFactory;
#endif /* !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusFactory_INTERFACE_DEFINED__) */
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x50000

/*
 *
 * Interface Windows.Storage.Provider.IStorageProviderStatusSource
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 5.0
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusSource_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusSource_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Storage_Provider_IStorageProviderStatusSource[] = L"Windows.Storage.Provider.IStorageProviderStatusSource";
typedef struct __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusSourceVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusSource* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusSource* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusSource* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusSource* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusSource* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusSource* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* GetStatus)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusSource* This,
        __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatus** result);
    HRESULT (STDMETHODCALLTYPE* add_Changed)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusSource* This,
        __FITypedEventHandler_2_Windows__CStorage__CProvider__CIStorageProviderStatusSource_IInspectable* handler,
        EventRegistrationToken* token);
    HRESULT (STDMETHODCALLTYPE* remove_Changed)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusSource* This,
        EventRegistrationToken token);

    END_INTERFACE
} __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusSourceVtbl;

interface __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusSource
{
    CONST_VTBL struct __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusSourceVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusSource_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusSource_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusSource_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusSource_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusSource_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusSource_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusSource_GetStatus(This, result) \
    ((This)->lpVtbl->GetStatus(This, result))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusSource_add_Changed(This, handler, token) \
    ((This)->lpVtbl->add_Changed(This, handler, token))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusSource_remove_Changed(This, token) \
    ((This)->lpVtbl->remove_Changed(This, token))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusSource;
#endif /* !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderStatusSource_INTERFACE_DEFINED__) */
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x50000

/*
 *
 * Interface Windows.Storage.Provider.IStorageProviderSyncRootInfo
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Storage.Provider.StorageProviderSyncRootInfo
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Storage_Provider_IStorageProviderSyncRootInfo[] = L"Windows.Storage.Provider.IStorageProviderSyncRootInfo";
typedef struct __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfoVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Id)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* put_Id)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo* This,
        HSTRING value);
    HRESULT (STDMETHODCALLTYPE* get_Context)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo* This,
        __x_ABI_CWindows_CStorage_CStreams_CIBuffer** value);
    HRESULT (STDMETHODCALLTYPE* put_Context)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo* This,
        __x_ABI_CWindows_CStorage_CStreams_CIBuffer* value);
    HRESULT (STDMETHODCALLTYPE* get_Path)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo* This,
        __x_ABI_CWindows_CStorage_CIStorageFolder** value);
    HRESULT (STDMETHODCALLTYPE* put_Path)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo* This,
        __x_ABI_CWindows_CStorage_CIStorageFolder* value);
    HRESULT (STDMETHODCALLTYPE* get_DisplayNameResource)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* put_DisplayNameResource)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo* This,
        HSTRING value);
    HRESULT (STDMETHODCALLTYPE* get_IconResource)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* put_IconResource)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo* This,
        HSTRING value);
    HRESULT (STDMETHODCALLTYPE* get_HydrationPolicy)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo* This,
        enum __x_ABI_CWindows_CStorage_CProvider_CStorageProviderHydrationPolicy* value);
    HRESULT (STDMETHODCALLTYPE* put_HydrationPolicy)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo* This,
        enum __x_ABI_CWindows_CStorage_CProvider_CStorageProviderHydrationPolicy value);
    HRESULT (STDMETHODCALLTYPE* get_HydrationPolicyModifier)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo* This,
        enum __x_ABI_CWindows_CStorage_CProvider_CStorageProviderHydrationPolicyModifier* value);
    HRESULT (STDMETHODCALLTYPE* put_HydrationPolicyModifier)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo* This,
        enum __x_ABI_CWindows_CStorage_CProvider_CStorageProviderHydrationPolicyModifier value);
    HRESULT (STDMETHODCALLTYPE* get_PopulationPolicy)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo* This,
        enum __x_ABI_CWindows_CStorage_CProvider_CStorageProviderPopulationPolicy* value);
    HRESULT (STDMETHODCALLTYPE* put_PopulationPolicy)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo* This,
        enum __x_ABI_CWindows_CStorage_CProvider_CStorageProviderPopulationPolicy value);
    HRESULT (STDMETHODCALLTYPE* get_InSyncPolicy)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo* This,
        enum __x_ABI_CWindows_CStorage_CProvider_CStorageProviderInSyncPolicy* value);
    HRESULT (STDMETHODCALLTYPE* put_InSyncPolicy)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo* This,
        enum __x_ABI_CWindows_CStorage_CProvider_CStorageProviderInSyncPolicy value);
    HRESULT (STDMETHODCALLTYPE* get_HardlinkPolicy)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo* This,
        enum __x_ABI_CWindows_CStorage_CProvider_CStorageProviderHardlinkPolicy* value);
    HRESULT (STDMETHODCALLTYPE* put_HardlinkPolicy)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo* This,
        enum __x_ABI_CWindows_CStorage_CProvider_CStorageProviderHardlinkPolicy value);
    HRESULT (STDMETHODCALLTYPE* get_ShowSiblingsAsGroup)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo* This,
        boolean* value);
    HRESULT (STDMETHODCALLTYPE* put_ShowSiblingsAsGroup)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo* This,
        boolean value);
    HRESULT (STDMETHODCALLTYPE* get_Version)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* put_Version)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo* This,
        HSTRING value);
    HRESULT (STDMETHODCALLTYPE* get_ProtectionMode)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo* This,
        enum __x_ABI_CWindows_CStorage_CProvider_CStorageProviderProtectionMode* value);
    HRESULT (STDMETHODCALLTYPE* put_ProtectionMode)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo* This,
        enum __x_ABI_CWindows_CStorage_CProvider_CStorageProviderProtectionMode value);
    HRESULT (STDMETHODCALLTYPE* get_AllowPinning)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo* This,
        boolean* value);
    HRESULT (STDMETHODCALLTYPE* put_AllowPinning)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo* This,
        boolean value);
    HRESULT (STDMETHODCALLTYPE* get_StorageProviderItemPropertyDefinitions)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo* This,
        __FIVector_1_Windows__CStorage__CProvider__CStorageProviderItemPropertyDefinition** value);
    HRESULT (STDMETHODCALLTYPE* get_RecycleBinUri)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo* This,
        __x_ABI_CWindows_CFoundation_CIUriRuntimeClass** value);
    HRESULT (STDMETHODCALLTYPE* put_RecycleBinUri)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo* This,
        __x_ABI_CWindows_CFoundation_CIUriRuntimeClass* value);

    END_INTERFACE
} __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfoVtbl;

interface __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo
{
    CONST_VTBL struct __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfoVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo_get_Id(This, value) \
    ((This)->lpVtbl->get_Id(This, value))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo_put_Id(This, value) \
    ((This)->lpVtbl->put_Id(This, value))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo_get_Context(This, value) \
    ((This)->lpVtbl->get_Context(This, value))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo_put_Context(This, value) \
    ((This)->lpVtbl->put_Context(This, value))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo_get_Path(This, value) \
    ((This)->lpVtbl->get_Path(This, value))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo_put_Path(This, value) \
    ((This)->lpVtbl->put_Path(This, value))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo_get_DisplayNameResource(This, value) \
    ((This)->lpVtbl->get_DisplayNameResource(This, value))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo_put_DisplayNameResource(This, value) \
    ((This)->lpVtbl->put_DisplayNameResource(This, value))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo_get_IconResource(This, value) \
    ((This)->lpVtbl->get_IconResource(This, value))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo_put_IconResource(This, value) \
    ((This)->lpVtbl->put_IconResource(This, value))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo_get_HydrationPolicy(This, value) \
    ((This)->lpVtbl->get_HydrationPolicy(This, value))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo_put_HydrationPolicy(This, value) \
    ((This)->lpVtbl->put_HydrationPolicy(This, value))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo_get_HydrationPolicyModifier(This, value) \
    ((This)->lpVtbl->get_HydrationPolicyModifier(This, value))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo_put_HydrationPolicyModifier(This, value) \
    ((This)->lpVtbl->put_HydrationPolicyModifier(This, value))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo_get_PopulationPolicy(This, value) \
    ((This)->lpVtbl->get_PopulationPolicy(This, value))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo_put_PopulationPolicy(This, value) \
    ((This)->lpVtbl->put_PopulationPolicy(This, value))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo_get_InSyncPolicy(This, value) \
    ((This)->lpVtbl->get_InSyncPolicy(This, value))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo_put_InSyncPolicy(This, value) \
    ((This)->lpVtbl->put_InSyncPolicy(This, value))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo_get_HardlinkPolicy(This, value) \
    ((This)->lpVtbl->get_HardlinkPolicy(This, value))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo_put_HardlinkPolicy(This, value) \
    ((This)->lpVtbl->put_HardlinkPolicy(This, value))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo_get_ShowSiblingsAsGroup(This, value) \
    ((This)->lpVtbl->get_ShowSiblingsAsGroup(This, value))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo_put_ShowSiblingsAsGroup(This, value) \
    ((This)->lpVtbl->put_ShowSiblingsAsGroup(This, value))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo_get_Version(This, value) \
    ((This)->lpVtbl->get_Version(This, value))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo_put_Version(This, value) \
    ((This)->lpVtbl->put_Version(This, value))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo_get_ProtectionMode(This, value) \
    ((This)->lpVtbl->get_ProtectionMode(This, value))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo_put_ProtectionMode(This, value) \
    ((This)->lpVtbl->put_ProtectionMode(This, value))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo_get_AllowPinning(This, value) \
    ((This)->lpVtbl->get_AllowPinning(This, value))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo_put_AllowPinning(This, value) \
    ((This)->lpVtbl->put_AllowPinning(This, value))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo_get_StorageProviderItemPropertyDefinitions(This, value) \
    ((This)->lpVtbl->get_StorageProviderItemPropertyDefinitions(This, value))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo_get_RecycleBinUri(This, value) \
    ((This)->lpVtbl->get_RecycleBinUri(This, value))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo_put_RecycleBinUri(This, value) \
    ((This)->lpVtbl->put_RecycleBinUri(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo;
#endif /* !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo_INTERFACE_DEFINED__) */
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Storage.Provider.IStorageProviderSyncRootInfo2
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 3.0
 *
 * Interface is a part of the implementation of type Windows.Storage.Provider.StorageProviderSyncRootInfo
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x30000
#if !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo2_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo2_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Storage_Provider_IStorageProviderSyncRootInfo2[] = L"Windows.Storage.Provider.IStorageProviderSyncRootInfo2";
typedef struct __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo2Vtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo2* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo2* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo2* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo2* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo2* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo2* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_ProviderId)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo2* This,
        GUID* value);
    HRESULT (STDMETHODCALLTYPE* put_ProviderId)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo2* This,
        GUID value);

    END_INTERFACE
} __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo2Vtbl;

interface __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo2
{
    CONST_VTBL struct __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo2Vtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo2_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo2_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo2_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo2_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo2_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo2_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo2_get_ProviderId(This, value) \
    ((This)->lpVtbl->get_ProviderId(This, value))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo2_put_ProviderId(This, value) \
    ((This)->lpVtbl->put_ProviderId(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo2;
#endif /* !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo2_INTERFACE_DEFINED__) */
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x30000

/*
 *
 * Interface Windows.Storage.Provider.IStorageProviderSyncRootInfo3
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 4.0
 *
 * Interface is a part of the implementation of type Windows.Storage.Provider.StorageProviderSyncRootInfo
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x40000
#if !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo3_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo3_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Storage_Provider_IStorageProviderSyncRootInfo3[] = L"Windows.Storage.Provider.IStorageProviderSyncRootInfo3";
typedef struct __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo3Vtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo3* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo3* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo3* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo3* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo3* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo3* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_FallbackFileTypeInfo)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo3* This,
        __FIVector_1_Windows__CStorage__CProvider__CStorageProviderFileTypeInfo** value);

    END_INTERFACE
} __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo3Vtbl;

interface __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo3
{
    CONST_VTBL struct __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo3Vtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo3_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo3_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo3_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo3_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo3_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo3_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo3_get_FallbackFileTypeInfo(This, value) \
    ((This)->lpVtbl->get_FallbackFileTypeInfo(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo3;
#endif /* !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo3_INTERFACE_DEFINED__) */
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x40000

/*
 *
 * Interface Windows.Storage.Provider.IStorageProviderSyncRootManagerStatics
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Storage.Provider.StorageProviderSyncRootManager
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Storage_Provider_IStorageProviderSyncRootManagerStatics[] = L"Windows.Storage.Provider.IStorageProviderSyncRootManagerStatics";
typedef struct __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStaticsVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStatics* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStatics* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStatics* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStatics* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStatics* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStatics* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* Register)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStatics* This,
        __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo* syncRootInformation);
    HRESULT (STDMETHODCALLTYPE* Unregister)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStatics* This,
        HSTRING id);
    HRESULT (STDMETHODCALLTYPE* GetSyncRootInformationForFolder)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStatics* This,
        __x_ABI_CWindows_CStorage_CIStorageFolder* folder,
        __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo** result);
    HRESULT (STDMETHODCALLTYPE* GetSyncRootInformationForId)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStatics* This,
        HSTRING id,
        __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootInfo** result);
    HRESULT (STDMETHODCALLTYPE* GetCurrentSyncRoots)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStatics* This,
        __FIVectorView_1_Windows__CStorage__CProvider__CStorageProviderSyncRootInfo** result);

    END_INTERFACE
} __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStaticsVtbl;

interface __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStatics
{
    CONST_VTBL struct __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStaticsVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStatics_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStatics_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStatics_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStatics_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStatics_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStatics_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStatics_Register(This, syncRootInformation) \
    ((This)->lpVtbl->Register(This, syncRootInformation))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStatics_Unregister(This, id) \
    ((This)->lpVtbl->Unregister(This, id))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStatics_GetSyncRootInformationForFolder(This, folder, result) \
    ((This)->lpVtbl->GetSyncRootInformationForFolder(This, folder, result))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStatics_GetSyncRootInformationForId(This, id, result) \
    ((This)->lpVtbl->GetSyncRootInformationForId(This, id, result))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStatics_GetCurrentSyncRoots(This, result) \
    ((This)->lpVtbl->GetCurrentSyncRoots(This, result))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStatics;
#endif /* !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStatics_INTERFACE_DEFINED__) */
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Storage.Provider.IStorageProviderSyncRootManagerStatics2
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 4.0
 *
 * Interface is a part of the implementation of type Windows.Storage.Provider.StorageProviderSyncRootManager
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x40000
#if !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStatics2_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStatics2_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Storage_Provider_IStorageProviderSyncRootManagerStatics2[] = L"Windows.Storage.Provider.IStorageProviderSyncRootManagerStatics2";
typedef struct __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStatics2Vtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStatics2* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStatics2* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStatics2* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStatics2* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStatics2* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStatics2* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* IsSupported)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStatics2* This,
        boolean* result);

    END_INTERFACE
} __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStatics2Vtbl;

interface __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStatics2
{
    CONST_VTBL struct __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStatics2Vtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStatics2_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStatics2_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStatics2_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStatics2_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStatics2_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStatics2_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStatics2_IsSupported(This, result) \
    ((This)->lpVtbl->IsSupported(This, result))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStatics2;
#endif /* !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderSyncRootManagerStatics2_INTERFACE_DEFINED__) */
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x40000

/*
 *
 * Interface Windows.Storage.Provider.IStorageProviderUriSource
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 2.0
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x20000
#if !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderUriSource_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderUriSource_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Storage_Provider_IStorageProviderUriSource[] = L"Windows.Storage.Provider.IStorageProviderUriSource";
typedef struct __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderUriSourceVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderUriSource* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderUriSource* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderUriSource* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderUriSource* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderUriSource* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderUriSource* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* GetPathForContentUri)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderUriSource* This,
        HSTRING contentUri,
        __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetPathForContentUriResult* result);
    HRESULT (STDMETHODCALLTYPE* GetContentInfoForPath)(__x_ABI_CWindows_CStorage_CProvider_CIStorageProviderUriSource* This,
        HSTRING path,
        __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderGetContentInfoForPathResult* result);

    END_INTERFACE
} __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderUriSourceVtbl;

interface __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderUriSource
{
    CONST_VTBL struct __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderUriSourceVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderUriSource_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderUriSource_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderUriSource_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderUriSource_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderUriSource_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderUriSource_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderUriSource_GetPathForContentUri(This, contentUri, result) \
    ((This)->lpVtbl->GetPathForContentUri(This, contentUri, result))

#define __x_ABI_CWindows_CStorage_CProvider_CIStorageProviderUriSource_GetContentInfoForPath(This, path, result) \
    ((This)->lpVtbl->GetContentInfoForPath(This, path, result))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CStorage_CProvider_CIStorageProviderUriSource;
#endif /* !defined(____x_ABI_CWindows_CStorage_CProvider_CIStorageProviderUriSource_INTERFACE_DEFINED__) */
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x20000

/*
 *
 * Class Windows.Storage.Provider.CachedFileUpdater
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Windows.Storage.Provider.ICachedFileUpdaterStatics interface starting with version 1.0 of the Windows.Foundation.UniversalApiContract API contract
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Storage_Provider_CachedFileUpdater_DEFINED
#define RUNTIMECLASS_Windows_Storage_Provider_CachedFileUpdater_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Storage_Provider_CachedFileUpdater[] = L"Windows.Storage.Provider.CachedFileUpdater";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Storage.Provider.CachedFileUpdaterUI
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 * Class implements the following interfaces:
 *    Windows.Storage.Provider.ICachedFileUpdaterUI ** Default Interface **
 *    Windows.Storage.Provider.ICachedFileUpdaterUI2
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Storage_Provider_CachedFileUpdaterUI_DEFINED
#define RUNTIMECLASS_Windows_Storage_Provider_CachedFileUpdaterUI_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Storage_Provider_CachedFileUpdaterUI[] = L"Windows.Storage.Provider.CachedFileUpdaterUI";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Storage.Provider.FileUpdateRequest
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 * Class implements the following interfaces:
 *    Windows.Storage.Provider.IFileUpdateRequest ** Default Interface **
 *    Windows.Storage.Provider.IFileUpdateRequest2
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Storage_Provider_FileUpdateRequest_DEFINED
#define RUNTIMECLASS_Windows_Storage_Provider_FileUpdateRequest_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Storage_Provider_FileUpdateRequest[] = L"Windows.Storage.Provider.FileUpdateRequest";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Storage.Provider.FileUpdateRequestDeferral
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 * Class implements the following interfaces:
 *    Windows.Storage.Provider.IFileUpdateRequestDeferral ** Default Interface **
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Storage_Provider_FileUpdateRequestDeferral_DEFINED
#define RUNTIMECLASS_Windows_Storage_Provider_FileUpdateRequestDeferral_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Storage_Provider_FileUpdateRequestDeferral[] = L"Windows.Storage.Provider.FileUpdateRequestDeferral";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Storage.Provider.FileUpdateRequestedEventArgs
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 * Class implements the following interfaces:
 *    Windows.Storage.Provider.IFileUpdateRequestedEventArgs ** Default Interface **
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Storage_Provider_FileUpdateRequestedEventArgs_DEFINED
#define RUNTIMECLASS_Windows_Storage_Provider_FileUpdateRequestedEventArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Storage_Provider_FileUpdateRequestedEventArgs[] = L"Windows.Storage.Provider.FileUpdateRequestedEventArgs";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Storage.Provider.StorageProviderError
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 5.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via the Windows.Storage.Provider.IStorageProviderErrorFactory interface starting with version 5.0 of the Windows.Storage.Provider.CloudFilesContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Storage.Provider.IStorageProviderError ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x50000
#ifndef RUNTIMECLASS_Windows_Storage_Provider_StorageProviderError_DEFINED
#define RUNTIMECLASS_Windows_Storage_Provider_StorageProviderError_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Storage_Provider_StorageProviderError[] = L"Windows.Storage.Provider.StorageProviderError";
#endif
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x50000

/*
 *
 * Class Windows.Storage.Provider.StorageProviderErrorCommand
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 5.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via the Windows.Storage.Provider.IStorageProviderErrorCommandFactory interface starting with version 5.0 of the Windows.Storage.Provider.CloudFilesContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Storage.Provider.IStorageProviderErrorCommand ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x50000
#ifndef RUNTIMECLASS_Windows_Storage_Provider_StorageProviderErrorCommand_DEFINED
#define RUNTIMECLASS_Windows_Storage_Provider_StorageProviderErrorCommand_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Storage_Provider_StorageProviderErrorCommand[] = L"Windows.Storage.Provider.StorageProviderErrorCommand";
#endif
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x50000

/*
 *
 * Class Windows.Storage.Provider.StorageProviderFileTypeInfo
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 4.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via the Windows.Storage.Provider.IStorageProviderFileTypeInfoFactory interface starting with version 4.0 of the Windows.Storage.Provider.CloudFilesContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Storage.Provider.IStorageProviderFileTypeInfo ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x40000
#ifndef RUNTIMECLASS_Windows_Storage_Provider_StorageProviderFileTypeInfo_DEFINED
#define RUNTIMECLASS_Windows_Storage_Provider_StorageProviderFileTypeInfo_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Storage_Provider_StorageProviderFileTypeInfo[] = L"Windows.Storage.Provider.StorageProviderFileTypeInfo";
#endif
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x40000

/*
 *
 * Class Windows.Storage.Provider.StorageProviderGetContentInfoForPathResult
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 2.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via RoActivateInstance starting with version 2.0 of the Windows.Storage.Provider.CloudFilesContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Storage.Provider.IStorageProviderGetContentInfoForPathResult ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x20000
#ifndef RUNTIMECLASS_Windows_Storage_Provider_StorageProviderGetContentInfoForPathResult_DEFINED
#define RUNTIMECLASS_Windows_Storage_Provider_StorageProviderGetContentInfoForPathResult_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Storage_Provider_StorageProviderGetContentInfoForPathResult[] = L"Windows.Storage.Provider.StorageProviderGetContentInfoForPathResult";
#endif
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x20000

/*
 *
 * Class Windows.Storage.Provider.StorageProviderGetPathForContentUriResult
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 2.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via RoActivateInstance starting with version 2.0 of the Windows.Storage.Provider.CloudFilesContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Storage.Provider.IStorageProviderGetPathForContentUriResult ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x20000
#ifndef RUNTIMECLASS_Windows_Storage_Provider_StorageProviderGetPathForContentUriResult_DEFINED
#define RUNTIMECLASS_Windows_Storage_Provider_StorageProviderGetPathForContentUriResult_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Storage_Provider_StorageProviderGetPathForContentUriResult[] = L"Windows.Storage.Provider.StorageProviderGetPathForContentUriResult";
#endif
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x20000

/*
 *
 * Class Windows.Storage.Provider.StorageProviderItemProperties
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 1.0
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Windows.Storage.Provider.IStorageProviderItemPropertiesStatics interface starting with version 1.0 of the Windows.Storage.Provider.CloudFilesContract API contract
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Storage_Provider_StorageProviderItemProperties_DEFINED
#define RUNTIMECLASS_Windows_Storage_Provider_StorageProviderItemProperties_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Storage_Provider_StorageProviderItemProperties[] = L"Windows.Storage.Provider.StorageProviderItemProperties";
#endif
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Storage.Provider.StorageProviderItemProperty
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 1.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via RoActivateInstance starting with version 1.0 of the Windows.Storage.Provider.CloudFilesContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Storage.Provider.IStorageProviderItemProperty ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Storage_Provider_StorageProviderItemProperty_DEFINED
#define RUNTIMECLASS_Windows_Storage_Provider_StorageProviderItemProperty_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Storage_Provider_StorageProviderItemProperty[] = L"Windows.Storage.Provider.StorageProviderItemProperty";
#endif
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Storage.Provider.StorageProviderItemPropertyDefinition
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 1.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via RoActivateInstance starting with version 1.0 of the Windows.Storage.Provider.CloudFilesContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Storage.Provider.IStorageProviderItemPropertyDefinition ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Storage_Provider_StorageProviderItemPropertyDefinition_DEFINED
#define RUNTIMECLASS_Windows_Storage_Provider_StorageProviderItemPropertyDefinition_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Storage_Provider_StorageProviderItemPropertyDefinition[] = L"Windows.Storage.Provider.StorageProviderItemPropertyDefinition";
#endif
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Storage.Provider.StorageProviderStatus
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 5.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via the Windows.Storage.Provider.IStorageProviderStatusFactory interface starting with version 5.0 of the Windows.Storage.Provider.CloudFilesContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Storage.Provider.IStorageProviderStatus ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x50000
#ifndef RUNTIMECLASS_Windows_Storage_Provider_StorageProviderStatus_DEFINED
#define RUNTIMECLASS_Windows_Storage_Provider_StorageProviderStatus_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Storage_Provider_StorageProviderStatus[] = L"Windows.Storage.Provider.StorageProviderStatus";
#endif
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x50000

/*
 *
 * Class Windows.Storage.Provider.StorageProviderSyncRootInfo
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 1.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via RoActivateInstance starting with version 1.0 of the Windows.Storage.Provider.CloudFilesContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Storage.Provider.IStorageProviderSyncRootInfo ** Default Interface **
 *    Windows.Storage.Provider.IStorageProviderSyncRootInfo2
 *    Windows.Storage.Provider.IStorageProviderSyncRootInfo3
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Storage_Provider_StorageProviderSyncRootInfo_DEFINED
#define RUNTIMECLASS_Windows_Storage_Provider_StorageProviderSyncRootInfo_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Storage_Provider_StorageProviderSyncRootInfo[] = L"Windows.Storage.Provider.StorageProviderSyncRootInfo";
#endif
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Storage.Provider.StorageProviderSyncRootManager
 *
 * Introduced to Windows.Storage.Provider.CloudFilesContract in version 1.0
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Windows.Storage.Provider.IStorageProviderSyncRootManagerStatics2 interface starting with version 4.0 of the Windows.Storage.Provider.CloudFilesContract API contract
 *   Static Methods exist on the Windows.Storage.Provider.IStorageProviderSyncRootManagerStatics interface starting with version 1.0 of the Windows.Storage.Provider.CloudFilesContract API contract
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Storage_Provider_StorageProviderSyncRootManager_DEFINED
#define RUNTIMECLASS_Windows_Storage_Provider_StorageProviderSyncRootManager_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Storage_Provider_StorageProviderSyncRootManager[] = L"Windows.Storage.Provider.StorageProviderSyncRootManager";
#endif
#endif // WINDOWS_STORAGE_PROVIDER_CLOUDFILESCONTRACT_VERSION >= 0x10000

#endif // defined(__cplusplus)
#pragma pop_macro("MIDL_CONST_ID")
// Restore the original value of the 'DEPRECATED' macro
#pragma pop_macro("DEPRECATED")

#ifdef __clang__
#pragma clang diagnostic pop // deprecated-declarations
#else
#pragma warning(pop)
#endif
#endif // __windows2Estorage2Eprovider_p_h__

#endif // __windows2Estorage2Eprovider_h__
