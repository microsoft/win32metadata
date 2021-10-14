
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
#ifndef __windows2Edevices2Eprinters_h__
#define __windows2Edevices2Eprinters_h__
#ifndef __windows2Edevices2Eprinters_p_h__
#define __windows2Edevices2Eprinters_p_h__


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
#if !defined(WINDOWS_DEVICES_PRINTERS_PRINTERSCONTRACT_VERSION)
#define WINDOWS_DEVICES_PRINTERS_PRINTERSCONTRACT_VERSION 0x10000
#endif // defined(WINDOWS_DEVICES_PRINTERS_PRINTERSCONTRACT_VERSION)

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
#include "Windows.Storage.Streams.h"
// Importing Collections header
#include <windows.foundation.collections.h>

#if defined(__cplusplus) && !defined(CINTERFACE)
/* Forward Declarations */
#ifndef ____x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeError_FWD_DEFINED__
#define ____x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeError_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Devices {
            namespace Printers {
                interface IIppAttributeError;
            } /* Printers */
        } /* Devices */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeError ABI::Windows::Devices::Printers::IIppAttributeError

#endif // ____x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeError_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue_FWD_DEFINED__
#define ____x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Devices {
            namespace Printers {
                interface IIppAttributeValue;
            } /* Printers */
        } /* Devices */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue ABI::Windows::Devices::Printers::IIppAttributeValue

#endif // ____x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics_FWD_DEFINED__
#define ____x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Devices {
            namespace Printers {
                interface IIppAttributeValueStatics;
            } /* Printers */
        } /* Devices */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics ABI::Windows::Devices::Printers::IIppAttributeValueStatics

#endif // ____x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRange_FWD_DEFINED__
#define ____x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRange_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Devices {
            namespace Printers {
                interface IIppIntegerRange;
            } /* Printers */
        } /* Devices */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRange ABI::Windows::Devices::Printers::IIppIntegerRange

#endif // ____x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRange_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRangeFactory_FWD_DEFINED__
#define ____x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRangeFactory_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Devices {
            namespace Printers {
                interface IIppIntegerRangeFactory;
            } /* Printers */
        } /* Devices */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRangeFactory ABI::Windows::Devices::Printers::IIppIntegerRangeFactory

#endif // ____x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRangeFactory_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CDevices_CPrinters_CIIppPrintDevice_FWD_DEFINED__
#define ____x_ABI_CWindows_CDevices_CPrinters_CIIppPrintDevice_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Devices {
            namespace Printers {
                interface IIppPrintDevice;
            } /* Printers */
        } /* Devices */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CDevices_CPrinters_CIIppPrintDevice ABI::Windows::Devices::Printers::IIppPrintDevice

#endif // ____x_ABI_CWindows_CDevices_CPrinters_CIIppPrintDevice_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CDevices_CPrinters_CIIppResolution_FWD_DEFINED__
#define ____x_ABI_CWindows_CDevices_CPrinters_CIIppResolution_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Devices {
            namespace Printers {
                interface IIppResolution;
            } /* Printers */
        } /* Devices */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CDevices_CPrinters_CIIppResolution ABI::Windows::Devices::Printers::IIppResolution

#endif // ____x_ABI_CWindows_CDevices_CPrinters_CIIppResolution_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CDevices_CPrinters_CIIppResolutionFactory_FWD_DEFINED__
#define ____x_ABI_CWindows_CDevices_CPrinters_CIIppResolutionFactory_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Devices {
            namespace Printers {
                interface IIppResolutionFactory;
            } /* Printers */
        } /* Devices */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CDevices_CPrinters_CIIppResolutionFactory ABI::Windows::Devices::Printers::IIppResolutionFactory

#endif // ____x_ABI_CWindows_CDevices_CPrinters_CIIppResolutionFactory_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CDevices_CPrinters_CIIppSetAttributesResult_FWD_DEFINED__
#define ____x_ABI_CWindows_CDevices_CPrinters_CIIppSetAttributesResult_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Devices {
            namespace Printers {
                interface IIppSetAttributesResult;
            } /* Printers */
        } /* Devices */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CDevices_CPrinters_CIIppSetAttributesResult ABI::Windows::Devices::Printers::IIppSetAttributesResult

#endif // ____x_ABI_CWindows_CDevices_CPrinters_CIIppSetAttributesResult_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguage_FWD_DEFINED__
#define ____x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguage_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Devices {
            namespace Printers {
                interface IIppTextWithLanguage;
            } /* Printers */
        } /* Devices */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguage ABI::Windows::Devices::Printers::IIppTextWithLanguage

#endif // ____x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguage_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguageFactory_FWD_DEFINED__
#define ____x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguageFactory_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Devices {
            namespace Printers {
                interface IIppTextWithLanguageFactory;
            } /* Printers */
        } /* Devices */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguageFactory ABI::Windows::Devices::Printers::IIppTextWithLanguageFactory

#endif // ____x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguageFactory_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CDevices_CPrinters_CIPrint3DDevice_FWD_DEFINED__
#define ____x_ABI_CWindows_CDevices_CPrinters_CIPrint3DDevice_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Devices {
            namespace Printers {
                interface IPrint3DDevice;
            } /* Printers */
        } /* Devices */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CDevices_CPrinters_CIPrint3DDevice ABI::Windows::Devices::Printers::IPrint3DDevice

#endif // ____x_ABI_CWindows_CDevices_CPrinters_CIPrint3DDevice_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CDevices_CPrinters_CIPrint3DDeviceStatics_FWD_DEFINED__
#define ____x_ABI_CWindows_CDevices_CPrinters_CIPrint3DDeviceStatics_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Devices {
            namespace Printers {
                interface IPrint3DDeviceStatics;
            } /* Printers */
        } /* Devices */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CDevices_CPrinters_CIPrint3DDeviceStatics ABI::Windows::Devices::Printers::IPrint3DDeviceStatics

#endif // ____x_ABI_CWindows_CDevices_CPrinters_CIPrint3DDeviceStatics_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CDevices_CPrinters_CIPrintSchema_FWD_DEFINED__
#define ____x_ABI_CWindows_CDevices_CPrinters_CIPrintSchema_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Devices {
            namespace Printers {
                interface IPrintSchema;
            } /* Printers */
        } /* Devices */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CDevices_CPrinters_CIPrintSchema ABI::Windows::Devices::Printers::IPrintSchema

#endif // ____x_ABI_CWindows_CDevices_CPrinters_CIPrintSchema_FWD_DEFINED__

// Parameterized interface forward declarations (C++)

// Collection interface definitions
namespace ABI {
    namespace Windows {
        namespace Devices {
            namespace Printers {
                class Print3DDevice;
            } /* Printers */
        } /* Devices */
    } /* Windows */
} /* ABI */

#if WINDOWS_DEVICES_PRINTERS_PRINTERSCONTRACT_VERSION >= 0x10000

#ifndef DEF___FIAsyncOperation_1_Windows__CDevices__CPrinters__CPrint3DDevice_USE
#define DEF___FIAsyncOperation_1_Windows__CDevices__CPrinters__CPrint3DDevice_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation {
template <>
struct __declspec(uuid("7cfc4a8f-5eb7-5af7-bc9f-78a7e407cd2e"))
IAsyncOperation<ABI::Windows::Devices::Printers::Print3DDevice*> : IAsyncOperation_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Devices::Printers::Print3DDevice*, ABI::Windows::Devices::Printers::IPrint3DDevice*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.IAsyncOperation`1<Windows.Devices.Printers.Print3DDevice>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IAsyncOperation<ABI::Windows::Devices::Printers::Print3DDevice*> __FIAsyncOperation_1_Windows__CDevices__CPrinters__CPrint3DDevice_t;
#define __FIAsyncOperation_1_Windows__CDevices__CPrinters__CPrint3DDevice ABI::Windows::Foundation::__FIAsyncOperation_1_Windows__CDevices__CPrinters__CPrint3DDevice_t
/* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIAsyncOperation_1_Windows__CDevices__CPrinters__CPrint3DDevice_USE */

#endif // WINDOWS_DEVICES_PRINTERS_PRINTERSCONTRACT_VERSION >= 0x10000

#if WINDOWS_DEVICES_PRINTERS_PRINTERSCONTRACT_VERSION >= 0x10000

#ifndef DEF___FIAsyncOperationCompletedHandler_1_Windows__CDevices__CPrinters__CPrint3DDevice_USE
#define DEF___FIAsyncOperationCompletedHandler_1_Windows__CDevices__CPrinters__CPrint3DDevice_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation {
template <>
struct __declspec(uuid("8d4b123f-4343-5195-bbc9-b99e956e057f"))
IAsyncOperationCompletedHandler<ABI::Windows::Devices::Printers::Print3DDevice*> : IAsyncOperationCompletedHandler_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Devices::Printers::Print3DDevice*, ABI::Windows::Devices::Printers::IPrint3DDevice*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.AsyncOperationCompletedHandler`1<Windows.Devices.Printers.Print3DDevice>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IAsyncOperationCompletedHandler<ABI::Windows::Devices::Printers::Print3DDevice*> __FIAsyncOperationCompletedHandler_1_Windows__CDevices__CPrinters__CPrint3DDevice_t;
#define __FIAsyncOperationCompletedHandler_1_Windows__CDevices__CPrinters__CPrint3DDevice ABI::Windows::Foundation::__FIAsyncOperationCompletedHandler_1_Windows__CDevices__CPrinters__CPrint3DDevice_t
/* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIAsyncOperationCompletedHandler_1_Windows__CDevices__CPrinters__CPrint3DDevice_USE */

#endif // WINDOWS_DEVICES_PRINTERS_PRINTERSCONTRACT_VERSION >= 0x10000

#ifndef ____x_ABI_CWindows_CStorage_CStreams_CIRandomAccessStreamWithContentType_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CStreams_CIRandomAccessStreamWithContentType_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Streams {
                interface IRandomAccessStreamWithContentType;
            } /* Streams */
        } /* Storage */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CStorage_CStreams_CIRandomAccessStreamWithContentType ABI::Windows::Storage::Streams::IRandomAccessStreamWithContentType

#endif // ____x_ABI_CWindows_CStorage_CStreams_CIRandomAccessStreamWithContentType_FWD_DEFINED__

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#ifndef DEF___FIAsyncOperation_1_Windows__CStorage__CStreams__CIRandomAccessStreamWithContentType_USE
#define DEF___FIAsyncOperation_1_Windows__CStorage__CStreams__CIRandomAccessStreamWithContentType_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation {
template <>
struct __declspec(uuid("c4a57c5e-32b0-55b3-ad13-ce1c23041ed6"))
IAsyncOperation<ABI::Windows::Storage::Streams::IRandomAccessStreamWithContentType*> : IAsyncOperation_impl<ABI::Windows::Storage::Streams::IRandomAccessStreamWithContentType*>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.IAsyncOperation`1<Windows.Storage.Streams.IRandomAccessStreamWithContentType>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IAsyncOperation<ABI::Windows::Storage::Streams::IRandomAccessStreamWithContentType*> __FIAsyncOperation_1_Windows__CStorage__CStreams__CIRandomAccessStreamWithContentType_t;
#define __FIAsyncOperation_1_Windows__CStorage__CStreams__CIRandomAccessStreamWithContentType ABI::Windows::Foundation::__FIAsyncOperation_1_Windows__CStorage__CStreams__CIRandomAccessStreamWithContentType_t
/* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIAsyncOperation_1_Windows__CStorage__CStreams__CIRandomAccessStreamWithContentType_USE */

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#ifndef DEF___FIAsyncOperationCompletedHandler_1_Windows__CStorage__CStreams__CIRandomAccessStreamWithContentType_USE
#define DEF___FIAsyncOperationCompletedHandler_1_Windows__CStorage__CStreams__CIRandomAccessStreamWithContentType_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation {
template <>
struct __declspec(uuid("3dddecf4-1d39-58e8-83b1-dbed541c7f35"))
IAsyncOperationCompletedHandler<ABI::Windows::Storage::Streams::IRandomAccessStreamWithContentType*> : IAsyncOperationCompletedHandler_impl<ABI::Windows::Storage::Streams::IRandomAccessStreamWithContentType*>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.AsyncOperationCompletedHandler`1<Windows.Storage.Streams.IRandomAccessStreamWithContentType>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IAsyncOperationCompletedHandler<ABI::Windows::Storage::Streams::IRandomAccessStreamWithContentType*> __FIAsyncOperationCompletedHandler_1_Windows__CStorage__CStreams__CIRandomAccessStreamWithContentType_t;
#define __FIAsyncOperationCompletedHandler_1_Windows__CStorage__CStreams__CIRandomAccessStreamWithContentType ABI::Windows::Foundation::__FIAsyncOperationCompletedHandler_1_Windows__CStorage__CStreams__CIRandomAccessStreamWithContentType_t
/* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIAsyncOperationCompletedHandler_1_Windows__CStorage__CStreams__CIRandomAccessStreamWithContentType_USE */

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000


#ifndef DEF___FIIterator_1_boolean_USE
#define DEF___FIIterator_1_boolean_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("740a0296-a535-572a-bf0b-17c18ff71fe6"))
IIterator<bool> : IIterator_impl<ABI::Windows::Foundation::Internal::AggregateType<bool, boolean>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IIterator`1<Boolean>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterator<bool> __FIIterator_1_boolean_t;
#define __FIIterator_1_boolean ABI::Windows::Foundation::Collections::__FIIterator_1_boolean_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterator_1_boolean_USE */



#ifndef DEF___FIIterable_1_boolean_USE
#define DEF___FIIterable_1_boolean_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("30160817-1d7d-54e9-99db-d7636266a476"))
IIterable<bool> : IIterable_impl<ABI::Windows::Foundation::Internal::AggregateType<bool, boolean>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IIterable`1<Boolean>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterable<bool> __FIIterable_1_boolean_t;
#define __FIIterable_1_boolean ABI::Windows::Foundation::Collections::__FIIterable_1_boolean_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterable_1_boolean_USE */



#ifndef DEF___FIIterator_1_int_USE
#define DEF___FIIterator_1_int_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("bfea7f78-50c2-5f1d-a6ea-9e978d2699ff"))
IIterator<int> : IIterator_impl<int>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IIterator`1<Int32>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterator<int> __FIIterator_1_int_t;
#define __FIIterator_1_int ABI::Windows::Foundation::Collections::__FIIterator_1_int_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterator_1_int_USE */



#ifndef DEF___FIIterable_1_int_USE
#define DEF___FIIterable_1_int_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("81a643fb-f51c-5565-83c4-f96425777b66"))
IIterable<int> : IIterable_impl<int>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IIterable`1<Int32>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterable<int> __FIIterable_1_int_t;
#define __FIIterable_1_int ABI::Windows::Foundation::Collections::__FIIterable_1_int_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterable_1_int_USE */



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
        namespace Devices {
            namespace Printers {
                class IppAttributeValue;
            } /* Printers */
        } /* Devices */
    } /* Windows */
} /* ABI */

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#ifndef DEF___FIIterator_1_Windows__CDevices__CPrinters__CIppAttributeValue_USE
#define DEF___FIIterator_1_Windows__CDevices__CPrinters__CIppAttributeValue_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("a1f417ab-5251-5e30-81f6-c62b3eb8e259"))
IIterator<ABI::Windows::Devices::Printers::IppAttributeValue*> : IIterator_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Devices::Printers::IppAttributeValue*, ABI::Windows::Devices::Printers::IIppAttributeValue*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IIterator`1<Windows.Devices.Printers.IppAttributeValue>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterator<ABI::Windows::Devices::Printers::IppAttributeValue*> __FIIterator_1_Windows__CDevices__CPrinters__CIppAttributeValue_t;
#define __FIIterator_1_Windows__CDevices__CPrinters__CIppAttributeValue ABI::Windows::Foundation::Collections::__FIIterator_1_Windows__CDevices__CPrinters__CIppAttributeValue_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterator_1_Windows__CDevices__CPrinters__CIppAttributeValue_USE */

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#ifndef DEF___FIIterable_1_Windows__CDevices__CPrinters__CIppAttributeValue_USE
#define DEF___FIIterable_1_Windows__CDevices__CPrinters__CIppAttributeValue_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("2bd5bedc-2312-564d-b685-68684f631e92"))
IIterable<ABI::Windows::Devices::Printers::IppAttributeValue*> : IIterable_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Devices::Printers::IppAttributeValue*, ABI::Windows::Devices::Printers::IIppAttributeValue*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IIterable`1<Windows.Devices.Printers.IppAttributeValue>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterable<ABI::Windows::Devices::Printers::IppAttributeValue*> __FIIterable_1_Windows__CDevices__CPrinters__CIppAttributeValue_t;
#define __FIIterable_1_Windows__CDevices__CPrinters__CIppAttributeValue ABI::Windows::Foundation::Collections::__FIIterable_1_Windows__CDevices__CPrinters__CIppAttributeValue_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterable_1_Windows__CDevices__CPrinters__CIppAttributeValue_USE */

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

namespace ABI {
    namespace Windows {
        namespace Devices {
            namespace Printers {
                class IppIntegerRange;
            } /* Printers */
        } /* Devices */
    } /* Windows */
} /* ABI */

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#ifndef DEF___FIIterator_1_Windows__CDevices__CPrinters__CIppIntegerRange_USE
#define DEF___FIIterator_1_Windows__CDevices__CPrinters__CIppIntegerRange_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("55f88707-ee5c-5616-941d-089b69f0b48e"))
IIterator<ABI::Windows::Devices::Printers::IppIntegerRange*> : IIterator_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Devices::Printers::IppIntegerRange*, ABI::Windows::Devices::Printers::IIppIntegerRange*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IIterator`1<Windows.Devices.Printers.IppIntegerRange>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterator<ABI::Windows::Devices::Printers::IppIntegerRange*> __FIIterator_1_Windows__CDevices__CPrinters__CIppIntegerRange_t;
#define __FIIterator_1_Windows__CDevices__CPrinters__CIppIntegerRange ABI::Windows::Foundation::Collections::__FIIterator_1_Windows__CDevices__CPrinters__CIppIntegerRange_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterator_1_Windows__CDevices__CPrinters__CIppIntegerRange_USE */

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#ifndef DEF___FIIterable_1_Windows__CDevices__CPrinters__CIppIntegerRange_USE
#define DEF___FIIterable_1_Windows__CDevices__CPrinters__CIppIntegerRange_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("c1ab4df0-4e73-5bdd-80d1-e32e0264ce41"))
IIterable<ABI::Windows::Devices::Printers::IppIntegerRange*> : IIterable_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Devices::Printers::IppIntegerRange*, ABI::Windows::Devices::Printers::IIppIntegerRange*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IIterable`1<Windows.Devices.Printers.IppIntegerRange>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterable<ABI::Windows::Devices::Printers::IppIntegerRange*> __FIIterable_1_Windows__CDevices__CPrinters__CIppIntegerRange_t;
#define __FIIterable_1_Windows__CDevices__CPrinters__CIppIntegerRange ABI::Windows::Foundation::Collections::__FIIterable_1_Windows__CDevices__CPrinters__CIppIntegerRange_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterable_1_Windows__CDevices__CPrinters__CIppIntegerRange_USE */

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

namespace ABI {
    namespace Windows {
        namespace Devices {
            namespace Printers {
                class IppResolution;
            } /* Printers */
        } /* Devices */
    } /* Windows */
} /* ABI */

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#ifndef DEF___FIIterator_1_Windows__CDevices__CPrinters__CIppResolution_USE
#define DEF___FIIterator_1_Windows__CDevices__CPrinters__CIppResolution_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("704428e7-3e54-5a3c-9ce0-272b1e4a83c8"))
IIterator<ABI::Windows::Devices::Printers::IppResolution*> : IIterator_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Devices::Printers::IppResolution*, ABI::Windows::Devices::Printers::IIppResolution*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IIterator`1<Windows.Devices.Printers.IppResolution>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterator<ABI::Windows::Devices::Printers::IppResolution*> __FIIterator_1_Windows__CDevices__CPrinters__CIppResolution_t;
#define __FIIterator_1_Windows__CDevices__CPrinters__CIppResolution ABI::Windows::Foundation::Collections::__FIIterator_1_Windows__CDevices__CPrinters__CIppResolution_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterator_1_Windows__CDevices__CPrinters__CIppResolution_USE */

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#ifndef DEF___FIIterable_1_Windows__CDevices__CPrinters__CIppResolution_USE
#define DEF___FIIterable_1_Windows__CDevices__CPrinters__CIppResolution_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("60cf8d08-474e-54fe-af66-6893e8f92575"))
IIterable<ABI::Windows::Devices::Printers::IppResolution*> : IIterable_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Devices::Printers::IppResolution*, ABI::Windows::Devices::Printers::IIppResolution*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IIterable`1<Windows.Devices.Printers.IppResolution>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterable<ABI::Windows::Devices::Printers::IppResolution*> __FIIterable_1_Windows__CDevices__CPrinters__CIppResolution_t;
#define __FIIterable_1_Windows__CDevices__CPrinters__CIppResolution ABI::Windows::Foundation::Collections::__FIIterable_1_Windows__CDevices__CPrinters__CIppResolution_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterable_1_Windows__CDevices__CPrinters__CIppResolution_USE */

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

namespace ABI {
    namespace Windows {
        namespace Devices {
            namespace Printers {
                class IppTextWithLanguage;
            } /* Printers */
        } /* Devices */
    } /* Windows */
} /* ABI */

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#ifndef DEF___FIIterator_1_Windows__CDevices__CPrinters__CIppTextWithLanguage_USE
#define DEF___FIIterator_1_Windows__CDevices__CPrinters__CIppTextWithLanguage_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("b5a11414-5b14-5ec3-af62-944f74056613"))
IIterator<ABI::Windows::Devices::Printers::IppTextWithLanguage*> : IIterator_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Devices::Printers::IppTextWithLanguage*, ABI::Windows::Devices::Printers::IIppTextWithLanguage*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IIterator`1<Windows.Devices.Printers.IppTextWithLanguage>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterator<ABI::Windows::Devices::Printers::IppTextWithLanguage*> __FIIterator_1_Windows__CDevices__CPrinters__CIppTextWithLanguage_t;
#define __FIIterator_1_Windows__CDevices__CPrinters__CIppTextWithLanguage ABI::Windows::Foundation::Collections::__FIIterator_1_Windows__CDevices__CPrinters__CIppTextWithLanguage_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterator_1_Windows__CDevices__CPrinters__CIppTextWithLanguage_USE */

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#ifndef DEF___FIIterable_1_Windows__CDevices__CPrinters__CIppTextWithLanguage_USE
#define DEF___FIIterable_1_Windows__CDevices__CPrinters__CIppTextWithLanguage_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("da3d8cb6-082a-5993-8640-ac246fd71244"))
IIterable<ABI::Windows::Devices::Printers::IppTextWithLanguage*> : IIterable_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Devices::Printers::IppTextWithLanguage*, ABI::Windows::Devices::Printers::IIppTextWithLanguage*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IIterable`1<Windows.Devices.Printers.IppTextWithLanguage>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterable<ABI::Windows::Devices::Printers::IppTextWithLanguage*> __FIIterable_1_Windows__CDevices__CPrinters__CIppTextWithLanguage_t;
#define __FIIterable_1_Windows__CDevices__CPrinters__CIppTextWithLanguage ABI::Windows::Foundation::Collections::__FIIterable_1_Windows__CDevices__CPrinters__CIppTextWithLanguage_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterable_1_Windows__CDevices__CPrinters__CIppTextWithLanguage_USE */

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#ifndef DEF___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_USE
#define DEF___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("ec09ead6-6117-5ae5-80e3-2d6bc7f9a955"))
IKeyValuePair<HSTRING, ABI::Windows::Devices::Printers::IppAttributeValue*> : IKeyValuePair_impl<HSTRING, ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Devices::Printers::IppAttributeValue*, ABI::Windows::Devices::Printers::IIppAttributeValue*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IKeyValuePair`2<String, Windows.Devices.Printers.IppAttributeValue>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IKeyValuePair<HSTRING, ABI::Windows::Devices::Printers::IppAttributeValue*> __FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_t;
#define __FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue ABI::Windows::Foundation::Collections::__FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_USE */

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#ifndef DEF___FIIterator_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_USE
#define DEF___FIIterator_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("8a501320-0647-58a4-8af8-8d63936ce48a"))
IIterator<__FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue*> : IIterator_impl<__FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue*>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IIterator`1<Windows.Foundation.Collections.IKeyValuePair`2<String, Windows.Devices.Printers.IppAttributeValue>>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterator<__FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue*> __FIIterator_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_t;
#define __FIIterator_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue ABI::Windows::Foundation::Collections::__FIIterator_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterator_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_USE */

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#ifndef DEF___FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_USE
#define DEF___FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("5dcf9ab4-ed4e-5648-8bfb-f626d5d7c505"))
IIterable<__FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue*> : IIterable_impl<__FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue*>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IIterable`1<Windows.Foundation.Collections.IKeyValuePair`2<String, Windows.Devices.Printers.IppAttributeValue>>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterable<__FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue*> __FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_t;
#define __FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue ABI::Windows::Foundation::Collections::__FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_USE */

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#ifndef DEF___FIIterator_1___FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_USE
#define DEF___FIIterator_1___FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("81a06ad8-f097-5782-9d7d-0d3d00afaa82"))
IIterator<__FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue*> : IIterator_impl<__FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue*>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IIterator`1<Windows.Foundation.Collections.IIterable`1<Windows.Foundation.Collections.IKeyValuePair`2<String, Windows.Devices.Printers.IppAttributeValue>>>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterator<__FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue*> __FIIterator_1___FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_t;
#define __FIIterator_1___FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue ABI::Windows::Foundation::Collections::__FIIterator_1___FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterator_1___FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_USE */

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#ifndef DEF___FIIterable_1___FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_USE
#define DEF___FIIterable_1___FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("e4a5d51b-0047-5c20-8a42-d265732e8117"))
IIterable<__FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue*> : IIterable_impl<__FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue*>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IIterable`1<Windows.Foundation.Collections.IIterable`1<Windows.Foundation.Collections.IKeyValuePair`2<String, Windows.Devices.Printers.IppAttributeValue>>>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterable<__FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue*> __FIIterable_1___FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_t;
#define __FIIterable_1___FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue ABI::Windows::Foundation::Collections::__FIIterable_1___FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterable_1___FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_USE */

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

namespace ABI {
    namespace Windows {
        namespace Devices {
            namespace Printers {
                class IppAttributeError;
            } /* Printers */
        } /* Devices */
    } /* Windows */
} /* ABI */

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#ifndef DEF___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError_USE
#define DEF___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("22992703-b6a5-57a6-b211-5bf6b8d8f7b1"))
IKeyValuePair<HSTRING, ABI::Windows::Devices::Printers::IppAttributeError*> : IKeyValuePair_impl<HSTRING, ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Devices::Printers::IppAttributeError*, ABI::Windows::Devices::Printers::IIppAttributeError*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IKeyValuePair`2<String, Windows.Devices.Printers.IppAttributeError>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IKeyValuePair<HSTRING, ABI::Windows::Devices::Printers::IppAttributeError*> __FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError_t;
#define __FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError ABI::Windows::Foundation::Collections::__FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError_USE */

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#ifndef DEF___FIIterator_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError_USE
#define DEF___FIIterator_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("5f234542-d5b2-5a78-8f40-ced5a3ebb28b"))
IIterator<__FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError*> : IIterator_impl<__FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError*>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IIterator`1<Windows.Foundation.Collections.IKeyValuePair`2<String, Windows.Devices.Printers.IppAttributeError>>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterator<__FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError*> __FIIterator_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError_t;
#define __FIIterator_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError ABI::Windows::Foundation::Collections::__FIIterator_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterator_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError_USE */

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#ifndef DEF___FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError_USE
#define DEF___FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("17f42ebf-08e9-5e26-96ed-513171d2aff2"))
IIterable<__FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError*> : IIterable_impl<__FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError*>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IIterable`1<Windows.Foundation.Collections.IKeyValuePair`2<String, Windows.Devices.Printers.IppAttributeError>>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterable<__FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError*> __FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError_t;
#define __FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError ABI::Windows::Foundation::Collections::__FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError_USE */

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#ifndef DEF___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_USE
#define DEF___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("a2379f3e-0733-5491-98b8-08b3134ab23d"))
IMapView<HSTRING, ABI::Windows::Devices::Printers::IppAttributeValue*> : IMapView_impl<HSTRING, ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Devices::Printers::IppAttributeValue*, ABI::Windows::Devices::Printers::IIppAttributeValue*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IMapView`2<String, Windows.Devices.Printers.IppAttributeValue>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IMapView<HSTRING, ABI::Windows::Devices::Printers::IppAttributeValue*> __FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_t;
#define __FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue ABI::Windows::Foundation::Collections::__FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_USE */

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#ifndef DEF___FIIterator_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_USE
#define DEF___FIIterator_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("d5f0c12f-599d-5e06-87e8-d9a83e3822cc"))
IIterator<__FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue*> : IIterator_impl<__FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue*>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IIterator`1<Windows.Foundation.Collections.IMapView`2<String, Windows.Devices.Printers.IppAttributeValue>>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterator<__FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue*> __FIIterator_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_t;
#define __FIIterator_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue ABI::Windows::Foundation::Collections::__FIIterator_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterator_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_USE */

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#ifndef DEF___FIIterable_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_USE
#define DEF___FIIterable_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("47558612-ba48-5da9-9d10-6ed53b0ca405"))
IIterable<__FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue*> : IIterable_impl<__FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue*>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IIterable`1<Windows.Foundation.Collections.IMapView`2<String, Windows.Devices.Printers.IppAttributeValue>>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterable<__FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue*> __FIIterable_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_t;
#define __FIIterable_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue ABI::Windows::Foundation::Collections::__FIIterable_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterable_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_USE */

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

namespace ABI {
    namespace Windows {
        namespace Foundation {
            typedef struct DateTime DateTime;
        } /* Foundation */
    } /* Windows */
} /* ABI */

#if WINDOWS_FOUNDATION_FOUNDATIONCONTRACT_VERSION >= 0x10000

#ifndef DEF___FIIterator_1_Windows__CFoundation__CDateTime_USE
#define DEF___FIIterator_1_Windows__CFoundation__CDateTime_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("f56158df-8947-5480-96ed-36c1057877ea"))
IIterator<struct ABI::Windows::Foundation::DateTime> : IIterator_impl<struct ABI::Windows::Foundation::DateTime>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IIterator`1<Windows.Foundation.DateTime>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterator<struct ABI::Windows::Foundation::DateTime> __FIIterator_1_Windows__CFoundation__CDateTime_t;
#define __FIIterator_1_Windows__CFoundation__CDateTime ABI::Windows::Foundation::Collections::__FIIterator_1_Windows__CFoundation__CDateTime_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterator_1_Windows__CFoundation__CDateTime_USE */

#endif // WINDOWS_FOUNDATION_FOUNDATIONCONTRACT_VERSION >= 0x10000

#if WINDOWS_FOUNDATION_FOUNDATIONCONTRACT_VERSION >= 0x10000

#ifndef DEF___FIIterable_1_Windows__CFoundation__CDateTime_USE
#define DEF___FIIterable_1_Windows__CFoundation__CDateTime_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("576a207d-977c-5b36-b54d-624ec86c53a3"))
IIterable<struct ABI::Windows::Foundation::DateTime> : IIterable_impl<struct ABI::Windows::Foundation::DateTime>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IIterable`1<Windows.Foundation.DateTime>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterable<struct ABI::Windows::Foundation::DateTime> __FIIterable_1_Windows__CFoundation__CDateTime_t;
#define __FIIterable_1_Windows__CFoundation__CDateTime ABI::Windows::Foundation::Collections::__FIIterable_1_Windows__CFoundation__CDateTime_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterable_1_Windows__CFoundation__CDateTime_USE */

#endif // WINDOWS_FOUNDATION_FOUNDATIONCONTRACT_VERSION >= 0x10000

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

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#ifndef DEF___FIIterator_1_Windows__CStorage__CStreams__CIBuffer_USE
#define DEF___FIIterator_1_Windows__CStorage__CStreams__CIBuffer_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("afee38e0-f882-5f10-9655-1fc98cc8cce5"))
IIterator<ABI::Windows::Storage::Streams::IBuffer*> : IIterator_impl<ABI::Windows::Storage::Streams::IBuffer*>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IIterator`1<Windows.Storage.Streams.IBuffer>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterator<ABI::Windows::Storage::Streams::IBuffer*> __FIIterator_1_Windows__CStorage__CStreams__CIBuffer_t;
#define __FIIterator_1_Windows__CStorage__CStreams__CIBuffer ABI::Windows::Foundation::Collections::__FIIterator_1_Windows__CStorage__CStreams__CIBuffer_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterator_1_Windows__CStorage__CStreams__CIBuffer_USE */

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#ifndef DEF___FIIterable_1_Windows__CStorage__CStreams__CIBuffer_USE
#define DEF___FIIterable_1_Windows__CStorage__CStreams__CIBuffer_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("902972bf-a984-5443-b1c5-2f04a99e1fca"))
IIterable<ABI::Windows::Storage::Streams::IBuffer*> : IIterable_impl<ABI::Windows::Storage::Streams::IBuffer*>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IIterable`1<Windows.Storage.Streams.IBuffer>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterable<ABI::Windows::Storage::Streams::IBuffer*> __FIIterable_1_Windows__CStorage__CStreams__CIBuffer_t;
#define __FIIterable_1_Windows__CStorage__CStreams__CIBuffer ABI::Windows::Foundation::Collections::__FIIterable_1_Windows__CStorage__CStreams__CIBuffer_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterable_1_Windows__CStorage__CStreams__CIBuffer_USE */

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#ifndef DEF___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError_USE
#define DEF___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("5f0d875e-7488-554f-9f68-0dc4952230f2"))
IMapView<HSTRING, ABI::Windows::Devices::Printers::IppAttributeError*> : IMapView_impl<HSTRING, ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Devices::Printers::IppAttributeError*, ABI::Windows::Devices::Printers::IIppAttributeError*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IMapView`2<String, Windows.Devices.Printers.IppAttributeError>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IMapView<HSTRING, ABI::Windows::Devices::Printers::IppAttributeError*> __FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError_t;
#define __FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError ABI::Windows::Foundation::Collections::__FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError_USE */

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#ifndef DEF___FIMap_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_USE
#define DEF___FIMap_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("e7f72ba5-e881-550d-939b-f54cb31962e8"))
IMap<HSTRING, ABI::Windows::Devices::Printers::IppAttributeValue*> : IMap_impl<HSTRING, ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Devices::Printers::IppAttributeValue*, ABI::Windows::Devices::Printers::IIppAttributeValue*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IMap`2<String, Windows.Devices.Printers.IppAttributeValue>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IMap<HSTRING, ABI::Windows::Devices::Printers::IppAttributeValue*> __FIMap_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_t;
#define __FIMap_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue ABI::Windows::Foundation::Collections::__FIMap_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIMap_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_USE */

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000


#ifndef DEF___FIVectorView_1_boolean_USE
#define DEF___FIVectorView_1_boolean_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("243a09cb-6f40-56af-a442-fe81431fbef5"))
IVectorView<bool> : IVectorView_impl<ABI::Windows::Foundation::Internal::AggregateType<bool, boolean>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IVectorView`1<Boolean>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IVectorView<bool> __FIVectorView_1_boolean_t;
#define __FIVectorView_1_boolean ABI::Windows::Foundation::Collections::__FIVectorView_1_boolean_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIVectorView_1_boolean_USE */



#ifndef DEF___FIVectorView_1_int_USE
#define DEF___FIVectorView_1_int_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("8d720cdf-3934-5d3f-9a55-40e8063b086a"))
IVectorView<int> : IVectorView_impl<int>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IVectorView`1<Int32>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IVectorView<int> __FIVectorView_1_int_t;
#define __FIVectorView_1_int ABI::Windows::Foundation::Collections::__FIVectorView_1_int_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIVectorView_1_int_USE */



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


#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#ifndef DEF___FIVectorView_1_Windows__CDevices__CPrinters__CIppAttributeValue_USE
#define DEF___FIVectorView_1_Windows__CDevices__CPrinters__CIppAttributeValue_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("b47b6f27-ef3b-55c4-825f-a8766d13c725"))
IVectorView<ABI::Windows::Devices::Printers::IppAttributeValue*> : IVectorView_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Devices::Printers::IppAttributeValue*, ABI::Windows::Devices::Printers::IIppAttributeValue*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IVectorView`1<Windows.Devices.Printers.IppAttributeValue>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IVectorView<ABI::Windows::Devices::Printers::IppAttributeValue*> __FIVectorView_1_Windows__CDevices__CPrinters__CIppAttributeValue_t;
#define __FIVectorView_1_Windows__CDevices__CPrinters__CIppAttributeValue ABI::Windows::Foundation::Collections::__FIVectorView_1_Windows__CDevices__CPrinters__CIppAttributeValue_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIVectorView_1_Windows__CDevices__CPrinters__CIppAttributeValue_USE */

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#ifndef DEF___FIVectorView_1_Windows__CDevices__CPrinters__CIppIntegerRange_USE
#define DEF___FIVectorView_1_Windows__CDevices__CPrinters__CIppIntegerRange_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("31e6c2e8-93b2-51d3-9fa2-56f181602b08"))
IVectorView<ABI::Windows::Devices::Printers::IppIntegerRange*> : IVectorView_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Devices::Printers::IppIntegerRange*, ABI::Windows::Devices::Printers::IIppIntegerRange*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IVectorView`1<Windows.Devices.Printers.IppIntegerRange>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IVectorView<ABI::Windows::Devices::Printers::IppIntegerRange*> __FIVectorView_1_Windows__CDevices__CPrinters__CIppIntegerRange_t;
#define __FIVectorView_1_Windows__CDevices__CPrinters__CIppIntegerRange ABI::Windows::Foundation::Collections::__FIVectorView_1_Windows__CDevices__CPrinters__CIppIntegerRange_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIVectorView_1_Windows__CDevices__CPrinters__CIppIntegerRange_USE */

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#ifndef DEF___FIVectorView_1_Windows__CDevices__CPrinters__CIppResolution_USE
#define DEF___FIVectorView_1_Windows__CDevices__CPrinters__CIppResolution_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("76871ada-42f4-57d9-94a2-ea406598e705"))
IVectorView<ABI::Windows::Devices::Printers::IppResolution*> : IVectorView_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Devices::Printers::IppResolution*, ABI::Windows::Devices::Printers::IIppResolution*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IVectorView`1<Windows.Devices.Printers.IppResolution>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IVectorView<ABI::Windows::Devices::Printers::IppResolution*> __FIVectorView_1_Windows__CDevices__CPrinters__CIppResolution_t;
#define __FIVectorView_1_Windows__CDevices__CPrinters__CIppResolution ABI::Windows::Foundation::Collections::__FIVectorView_1_Windows__CDevices__CPrinters__CIppResolution_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIVectorView_1_Windows__CDevices__CPrinters__CIppResolution_USE */

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#ifndef DEF___FIVectorView_1_Windows__CDevices__CPrinters__CIppTextWithLanguage_USE
#define DEF___FIVectorView_1_Windows__CDevices__CPrinters__CIppTextWithLanguage_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("84c1fb51-ca7a-5a23-8193-0c4a05b13653"))
IVectorView<ABI::Windows::Devices::Printers::IppTextWithLanguage*> : IVectorView_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Devices::Printers::IppTextWithLanguage*, ABI::Windows::Devices::Printers::IIppTextWithLanguage*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IVectorView`1<Windows.Devices.Printers.IppTextWithLanguage>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IVectorView<ABI::Windows::Devices::Printers::IppTextWithLanguage*> __FIVectorView_1_Windows__CDevices__CPrinters__CIppTextWithLanguage_t;
#define __FIVectorView_1_Windows__CDevices__CPrinters__CIppTextWithLanguage ABI::Windows::Foundation::Collections::__FIVectorView_1_Windows__CDevices__CPrinters__CIppTextWithLanguage_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIVectorView_1_Windows__CDevices__CPrinters__CIppTextWithLanguage_USE */

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#ifndef DEF___FIVectorView_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_USE
#define DEF___FIVectorView_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("166c0d36-4165-5a33-9d6d-6f42c5d73188"))
IVectorView<__FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue*> : IVectorView_impl<__FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue*>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IVectorView`1<Windows.Foundation.Collections.IMapView`2<String, Windows.Devices.Printers.IppAttributeValue>>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IVectorView<__FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue*> __FIVectorView_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_t;
#define __FIVectorView_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue ABI::Windows::Foundation::Collections::__FIVectorView_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIVectorView_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_USE */

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#if WINDOWS_FOUNDATION_FOUNDATIONCONTRACT_VERSION >= 0x10000

#ifndef DEF___FIVectorView_1_Windows__CFoundation__CDateTime_USE
#define DEF___FIVectorView_1_Windows__CFoundation__CDateTime_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("135a5f72-a818-54a8-b955-dff2593a3bf5"))
IVectorView<struct ABI::Windows::Foundation::DateTime> : IVectorView_impl<struct ABI::Windows::Foundation::DateTime>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IVectorView`1<Windows.Foundation.DateTime>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IVectorView<struct ABI::Windows::Foundation::DateTime> __FIVectorView_1_Windows__CFoundation__CDateTime_t;
#define __FIVectorView_1_Windows__CFoundation__CDateTime ABI::Windows::Foundation::Collections::__FIVectorView_1_Windows__CFoundation__CDateTime_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIVectorView_1_Windows__CFoundation__CDateTime_USE */

#endif // WINDOWS_FOUNDATION_FOUNDATIONCONTRACT_VERSION >= 0x10000

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

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#ifndef DEF___FIVectorView_1_Windows__CStorage__CStreams__CIBuffer_USE
#define DEF___FIVectorView_1_Windows__CStorage__CStreams__CIBuffer_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("fd944562-11d6-5eab-bd72-701993b68fac"))
IVectorView<ABI::Windows::Storage::Streams::IBuffer*> : IVectorView_impl<ABI::Windows::Storage::Streams::IBuffer*>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IVectorView`1<Windows.Storage.Streams.IBuffer>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IVectorView<ABI::Windows::Storage::Streams::IBuffer*> __FIVectorView_1_Windows__CStorage__CStreams__CIBuffer_t;
#define __FIVectorView_1_Windows__CStorage__CStreams__CIBuffer ABI::Windows::Foundation::Collections::__FIVectorView_1_Windows__CStorage__CStreams__CIBuffer_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIVectorView_1_Windows__CStorage__CStreams__CIBuffer_USE */

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000


#ifndef DEF___FIVector_1_boolean_USE
#define DEF___FIVector_1_boolean_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("6180171d-2ed8-5e24-8a55-01ecb1009eb2"))
IVector<bool> : IVector_impl<ABI::Windows::Foundation::Internal::AggregateType<bool, boolean>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IVector`1<Boolean>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IVector<bool> __FIVector_1_boolean_t;
#define __FIVector_1_boolean ABI::Windows::Foundation::Collections::__FIVector_1_boolean_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIVector_1_boolean_USE */



#ifndef DEF___FIVector_1_int_USE
#define DEF___FIVector_1_int_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("b939af5b-b45d-5489-9149-61442c1905fe"))
IVector<int> : IVector_impl<int>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IVector`1<Int32>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IVector<int> __FIVector_1_int_t;
#define __FIVector_1_int ABI::Windows::Foundation::Collections::__FIVector_1_int_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIVector_1_int_USE */



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


#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#ifndef DEF___FIVector_1_Windows__CDevices__CPrinters__CIppIntegerRange_USE
#define DEF___FIVector_1_Windows__CDevices__CPrinters__CIppIntegerRange_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("c9cacf28-ef27-5753-8382-7d7df136294d"))
IVector<ABI::Windows::Devices::Printers::IppIntegerRange*> : IVector_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Devices::Printers::IppIntegerRange*, ABI::Windows::Devices::Printers::IIppIntegerRange*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IVector`1<Windows.Devices.Printers.IppIntegerRange>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IVector<ABI::Windows::Devices::Printers::IppIntegerRange*> __FIVector_1_Windows__CDevices__CPrinters__CIppIntegerRange_t;
#define __FIVector_1_Windows__CDevices__CPrinters__CIppIntegerRange ABI::Windows::Foundation::Collections::__FIVector_1_Windows__CDevices__CPrinters__CIppIntegerRange_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIVector_1_Windows__CDevices__CPrinters__CIppIntegerRange_USE */

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#ifndef DEF___FIVector_1_Windows__CDevices__CPrinters__CIppResolution_USE
#define DEF___FIVector_1_Windows__CDevices__CPrinters__CIppResolution_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("992f8ca5-0e6c-5873-af3d-b0927f275a69"))
IVector<ABI::Windows::Devices::Printers::IppResolution*> : IVector_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Devices::Printers::IppResolution*, ABI::Windows::Devices::Printers::IIppResolution*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IVector`1<Windows.Devices.Printers.IppResolution>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IVector<ABI::Windows::Devices::Printers::IppResolution*> __FIVector_1_Windows__CDevices__CPrinters__CIppResolution_t;
#define __FIVector_1_Windows__CDevices__CPrinters__CIppResolution ABI::Windows::Foundation::Collections::__FIVector_1_Windows__CDevices__CPrinters__CIppResolution_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIVector_1_Windows__CDevices__CPrinters__CIppResolution_USE */

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#ifndef DEF___FIVector_1_Windows__CDevices__CPrinters__CIppTextWithLanguage_USE
#define DEF___FIVector_1_Windows__CDevices__CPrinters__CIppTextWithLanguage_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("a2e47775-c458-53fd-a85b-0fc65f021ea6"))
IVector<ABI::Windows::Devices::Printers::IppTextWithLanguage*> : IVector_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Devices::Printers::IppTextWithLanguage*, ABI::Windows::Devices::Printers::IIppTextWithLanguage*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IVector`1<Windows.Devices.Printers.IppTextWithLanguage>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IVector<ABI::Windows::Devices::Printers::IppTextWithLanguage*> __FIVector_1_Windows__CDevices__CPrinters__CIppTextWithLanguage_t;
#define __FIVector_1_Windows__CDevices__CPrinters__CIppTextWithLanguage ABI::Windows::Foundation::Collections::__FIVector_1_Windows__CDevices__CPrinters__CIppTextWithLanguage_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIVector_1_Windows__CDevices__CPrinters__CIppTextWithLanguage_USE */

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#ifndef DEF___FIVector_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_USE
#define DEF___FIVector_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("1ee3a40e-00e5-52ed-b2aa-fb70f99813b7"))
IVector<__FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue*> : IVector_impl<__FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue*>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IVector`1<Windows.Foundation.Collections.IMapView`2<String, Windows.Devices.Printers.IppAttributeValue>>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IVector<__FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue*> __FIVector_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_t;
#define __FIVector_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue ABI::Windows::Foundation::Collections::__FIVector_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIVector_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_USE */

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#if WINDOWS_FOUNDATION_FOUNDATIONCONTRACT_VERSION >= 0x10000

#ifndef DEF___FIVector_1_Windows__CFoundation__CDateTime_USE
#define DEF___FIVector_1_Windows__CFoundation__CDateTime_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("94390dc5-e442-5870-88b6-007e232f902c"))
IVector<struct ABI::Windows::Foundation::DateTime> : IVector_impl<struct ABI::Windows::Foundation::DateTime>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IVector`1<Windows.Foundation.DateTime>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IVector<struct ABI::Windows::Foundation::DateTime> __FIVector_1_Windows__CFoundation__CDateTime_t;
#define __FIVector_1_Windows__CFoundation__CDateTime ABI::Windows::Foundation::Collections::__FIVector_1_Windows__CFoundation__CDateTime_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIVector_1_Windows__CFoundation__CDateTime_USE */

#endif // WINDOWS_FOUNDATION_FOUNDATIONCONTRACT_VERSION >= 0x10000

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

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#ifndef DEF___FIVector_1_Windows__CStorage__CStreams__CIBuffer_USE
#define DEF___FIVector_1_Windows__CStorage__CStreams__CIBuffer_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("308fe894-cc06-5007-bc85-cbe94ac1a70c"))
IVector<ABI::Windows::Storage::Streams::IBuffer*> : IVector_impl<ABI::Windows::Storage::Streams::IBuffer*>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IVector`1<Windows.Storage.Streams.IBuffer>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IVector<ABI::Windows::Storage::Streams::IBuffer*> __FIVector_1_Windows__CStorage__CStreams__CIBuffer_t;
#define __FIVector_1_Windows__CStorage__CStreams__CIBuffer ABI::Windows::Foundation::Collections::__FIVector_1_Windows__CStorage__CStreams__CIBuffer_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIVector_1_Windows__CStorage__CStreams__CIBuffer_USE */

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

namespace ABI {
    namespace Windows {
        namespace Devices {
            namespace Printers {
                typedef enum IppAttributeErrorReason : int IppAttributeErrorReason;
            } /* Printers */
        } /* Devices */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Devices {
            namespace Printers {
                typedef enum IppAttributeValueKind : int IppAttributeValueKind;
            } /* Printers */
        } /* Devices */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Devices {
            namespace Printers {
                typedef enum IppResolutionUnit : int IppResolutionUnit;
            } /* Printers */
        } /* Devices */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Devices {
            namespace Printers {
                class IppSetAttributesResult;
            } /* Printers */
        } /* Devices */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Devices {
            namespace Printers {
                class PrintSchema;
            } /* Printers */
        } /* Devices */
    } /* Windows */
} /* ABI */

/*
 *
 * Struct Windows.Devices.Printers.IppAttributeErrorReason
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
namespace ABI {
    namespace Windows {
        namespace Devices {
            namespace Printers {
                enum IppAttributeErrorReason : int
                {
                    IppAttributeErrorReason_RequestEntityTooLarge = 0,
                    IppAttributeErrorReason_AttributeNotSupported = 1,
                    IppAttributeErrorReason_AttributeValuesNotSupported = 2,
                    IppAttributeErrorReason_AttributeNotSettable = 3,
                    IppAttributeErrorReason_ConflictingAttributes = 4,
                };
            } /* Printers */
        } /* Devices */
    } /* Windows */
} /* ABI */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Struct Windows.Devices.Printers.IppAttributeValueKind
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
namespace ABI {
    namespace Windows {
        namespace Devices {
            namespace Printers {
                enum IppAttributeValueKind : int
                {
                    IppAttributeValueKind_Unsupported = 0,
                    IppAttributeValueKind_Unknown = 1,
                    IppAttributeValueKind_NoValue = 2,
                    IppAttributeValueKind_Integer = 3,
                    IppAttributeValueKind_Boolean = 4,
                    IppAttributeValueKind_Enum = 5,
                    IppAttributeValueKind_OctetString = 6,
                    IppAttributeValueKind_DateTime = 7,
                    IppAttributeValueKind_Resolution = 8,
                    IppAttributeValueKind_RangeOfInteger = 9,
                    IppAttributeValueKind_Collection = 10,
                    IppAttributeValueKind_TextWithLanguage = 11,
                    IppAttributeValueKind_NameWithLanguage = 12,
                    IppAttributeValueKind_TextWithoutLanguage = 13,
                    IppAttributeValueKind_NameWithoutLanguage = 14,
                    IppAttributeValueKind_Keyword = 15,
                    IppAttributeValueKind_Uri = 16,
                    IppAttributeValueKind_UriSchema = 17,
                    IppAttributeValueKind_Charset = 18,
                    IppAttributeValueKind_NaturalLanguage = 19,
                    IppAttributeValueKind_MimeMediaType = 20,
                };
            } /* Printers */
        } /* Devices */
    } /* Windows */
} /* ABI */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Struct Windows.Devices.Printers.IppResolutionUnit
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
namespace ABI {
    namespace Windows {
        namespace Devices {
            namespace Printers {
                enum IppResolutionUnit : int
                {
                    IppResolutionUnit_DotsPerInch = 0,
                    IppResolutionUnit_DotsPerCentimeter = 1,
                };
            } /* Printers */
        } /* Devices */
    } /* Windows */
} /* ABI */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Interface Windows.Devices.Printers.IIppAttributeError
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Interface is a part of the implementation of type Windows.Devices.Printers.IppAttributeError
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeError_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeError_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Devices_Printers_IIppAttributeError[] = L"Windows.Devices.Printers.IIppAttributeError";
namespace ABI {
    namespace Windows {
        namespace Devices {
            namespace Printers {
                MIDL_INTERFACE("750feda1-9eef-5c39-93e4-46149bbcef27")
                IIppAttributeError : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE get_Reason(
                        ABI::Windows::Devices::Printers::IppAttributeErrorReason* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_ExtendedError(
                        HRESULT* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE GetUnsupportedValues(
                        __FIVectorView_1_Windows__CDevices__CPrinters__CIppAttributeValue** result
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IIppAttributeError = _uuidof(IIppAttributeError);
            } /* Printers */
        } /* Devices */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeError;
#endif /* !defined(____x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeError_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Interface Windows.Devices.Printers.IIppAttributeValue
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Interface is a part of the implementation of type Windows.Devices.Printers.IppAttributeValue
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Devices_Printers_IIppAttributeValue[] = L"Windows.Devices.Printers.IIppAttributeValue";
namespace ABI {
    namespace Windows {
        namespace Devices {
            namespace Printers {
                MIDL_INTERFACE("99407fed-e2bb-59a3-988b-28a974052a26")
                IIppAttributeValue : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE get_Kind(
                        ABI::Windows::Devices::Printers::IppAttributeValueKind* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE GetIntegerArray(
                        __FIVector_1_int** result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE GetBooleanArray(
                        __FIVector_1_boolean** result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE GetEnumArray(
                        __FIVector_1_int** result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE GetOctetStringArray(
                        __FIVector_1_Windows__CStorage__CStreams__CIBuffer** result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE GetDateTimeArray(
                        __FIVector_1_Windows__CFoundation__CDateTime** result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE GetResolutionArray(
                        __FIVector_1_Windows__CDevices__CPrinters__CIppResolution** result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE GetRangeOfIntegerArray(
                        __FIVector_1_Windows__CDevices__CPrinters__CIppIntegerRange** result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE GetCollectionArray(
                        __FIVector_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue** result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE GetTextWithLanguageArray(
                        __FIVector_1_Windows__CDevices__CPrinters__CIppTextWithLanguage** result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE GetNameWithLanguageArray(
                        __FIVector_1_Windows__CDevices__CPrinters__CIppTextWithLanguage** result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE GetTextWithoutLanguageArray(
                        __FIVector_1_HSTRING** result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE GetNameWithoutLanguageArray(
                        __FIVector_1_HSTRING** result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE GetKeywordArray(
                        __FIVector_1_HSTRING** result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE GetUriArray(
                        __FIVector_1_Windows__CFoundation__CUri** result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE GetUriSchemaArray(
                        __FIVector_1_HSTRING** result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE GetCharsetArray(
                        __FIVector_1_HSTRING** result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE GetNaturalLanguageArray(
                        __FIVector_1_HSTRING** result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE GetMimeMediaTypeArray(
                        __FIVector_1_HSTRING** result
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IIppAttributeValue = _uuidof(IIppAttributeValue);
            } /* Printers */
        } /* Devices */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue;
#endif /* !defined(____x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Interface Windows.Devices.Printers.IIppAttributeValueStatics
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Interface is a part of the implementation of type Windows.Devices.Printers.IppAttributeValue
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Devices_Printers_IIppAttributeValueStatics[] = L"Windows.Devices.Printers.IIppAttributeValueStatics";
namespace ABI {
    namespace Windows {
        namespace Devices {
            namespace Printers {
                MIDL_INTERFACE("10d43942-dd94-5998-b235-afafb6fa7935")
                IIppAttributeValueStatics : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE CreateUnsupported(
                        ABI::Windows::Devices::Printers::IIppAttributeValue** result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE CreateUnknown(
                        ABI::Windows::Devices::Printers::IIppAttributeValue** result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE CreateNoValue(
                        ABI::Windows::Devices::Printers::IIppAttributeValue** result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE CreateInteger(
                        INT32 value,
                        ABI::Windows::Devices::Printers::IIppAttributeValue** result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE CreateIntegerArray(
                        __FIIterable_1_int* values,
                        ABI::Windows::Devices::Printers::IIppAttributeValue** result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE CreateBoolean(
                        boolean value,
                        ABI::Windows::Devices::Printers::IIppAttributeValue** result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE CreateBooleanArray(
                        __FIIterable_1_boolean* values,
                        ABI::Windows::Devices::Printers::IIppAttributeValue** result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE CreateEnum(
                        INT32 value,
                        ABI::Windows::Devices::Printers::IIppAttributeValue** result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE CreateEnumArray(
                        __FIIterable_1_int* values,
                        ABI::Windows::Devices::Printers::IIppAttributeValue** result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE CreateOctetString(
                        ABI::Windows::Storage::Streams::IBuffer* value,
                        ABI::Windows::Devices::Printers::IIppAttributeValue** result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE CreateOctetStringArray(
                        __FIIterable_1_Windows__CStorage__CStreams__CIBuffer* values,
                        ABI::Windows::Devices::Printers::IIppAttributeValue** result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE CreateDateTime(
                        ABI::Windows::Foundation::DateTime value,
                        ABI::Windows::Devices::Printers::IIppAttributeValue** result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE CreateDateTimeArray(
                        __FIIterable_1_Windows__CFoundation__CDateTime* values,
                        ABI::Windows::Devices::Printers::IIppAttributeValue** result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE CreateResolution(
                        ABI::Windows::Devices::Printers::IIppResolution* value,
                        ABI::Windows::Devices::Printers::IIppAttributeValue** result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE CreateResolutionArray(
                        __FIIterable_1_Windows__CDevices__CPrinters__CIppResolution* values,
                        ABI::Windows::Devices::Printers::IIppAttributeValue** result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE CreateRangeOfInteger(
                        ABI::Windows::Devices::Printers::IIppIntegerRange* value,
                        ABI::Windows::Devices::Printers::IIppAttributeValue** result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE CreateRangeOfIntegerArray(
                        __FIIterable_1_Windows__CDevices__CPrinters__CIppIntegerRange* values,
                        ABI::Windows::Devices::Printers::IIppAttributeValue** result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE CreateCollection(
                        __FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* memberAttributes,
                        ABI::Windows::Devices::Printers::IIppAttributeValue** result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE CreateCollectionArray(
                        __FIIterable_1___FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* memberAttributesArray,
                        ABI::Windows::Devices::Printers::IIppAttributeValue** result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE CreateTextWithLanguage(
                        ABI::Windows::Devices::Printers::IIppTextWithLanguage* value,
                        ABI::Windows::Devices::Printers::IIppAttributeValue** result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE CreateTextWithLanguageArray(
                        __FIIterable_1_Windows__CDevices__CPrinters__CIppTextWithLanguage* values,
                        ABI::Windows::Devices::Printers::IIppAttributeValue** result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE CreateNameWithLanguage(
                        ABI::Windows::Devices::Printers::IIppTextWithLanguage* value,
                        ABI::Windows::Devices::Printers::IIppAttributeValue** result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE CreateNameWithLanguageArray(
                        __FIIterable_1_Windows__CDevices__CPrinters__CIppTextWithLanguage* values,
                        ABI::Windows::Devices::Printers::IIppAttributeValue** result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE CreateTextWithoutLanguage(
                        HSTRING value,
                        ABI::Windows::Devices::Printers::IIppAttributeValue** result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE CreateTextWithoutLanguageArray(
                        __FIIterable_1_HSTRING* values,
                        ABI::Windows::Devices::Printers::IIppAttributeValue** result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE CreateNameWithoutLanguage(
                        HSTRING value,
                        ABI::Windows::Devices::Printers::IIppAttributeValue** result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE CreateNameWithoutLanguageArray(
                        __FIIterable_1_HSTRING* values,
                        ABI::Windows::Devices::Printers::IIppAttributeValue** result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE CreateKeyword(
                        HSTRING value,
                        ABI::Windows::Devices::Printers::IIppAttributeValue** result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE CreateKeywordArray(
                        __FIIterable_1_HSTRING* values,
                        ABI::Windows::Devices::Printers::IIppAttributeValue** result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE CreateUri(
                        ABI::Windows::Foundation::IUriRuntimeClass* value,
                        ABI::Windows::Devices::Printers::IIppAttributeValue** result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE CreateUriArray(
                        __FIIterable_1_Windows__CFoundation__CUri* values,
                        ABI::Windows::Devices::Printers::IIppAttributeValue** result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE CreateUriSchema(
                        HSTRING value,
                        ABI::Windows::Devices::Printers::IIppAttributeValue** result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE CreateUriSchemaArray(
                        __FIIterable_1_HSTRING* values,
                        ABI::Windows::Devices::Printers::IIppAttributeValue** result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE CreateCharset(
                        HSTRING value,
                        ABI::Windows::Devices::Printers::IIppAttributeValue** result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE CreateCharsetArray(
                        __FIIterable_1_HSTRING* values,
                        ABI::Windows::Devices::Printers::IIppAttributeValue** result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE CreateNaturalLanguage(
                        HSTRING value,
                        ABI::Windows::Devices::Printers::IIppAttributeValue** result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE CreateNaturalLanguageArray(
                        __FIIterable_1_HSTRING* values,
                        ABI::Windows::Devices::Printers::IIppAttributeValue** result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE CreateMimeMedia(
                        HSTRING value,
                        ABI::Windows::Devices::Printers::IIppAttributeValue** result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE CreateMimeMediaArray(
                        __FIIterable_1_HSTRING* values,
                        ABI::Windows::Devices::Printers::IIppAttributeValue** result
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IIppAttributeValueStatics = _uuidof(IIppAttributeValueStatics);
            } /* Printers */
        } /* Devices */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics;
#endif /* !defined(____x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Interface Windows.Devices.Printers.IIppIntegerRange
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Interface is a part of the implementation of type Windows.Devices.Printers.IppIntegerRange
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRange_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRange_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Devices_Printers_IIppIntegerRange[] = L"Windows.Devices.Printers.IIppIntegerRange";
namespace ABI {
    namespace Windows {
        namespace Devices {
            namespace Printers {
                MIDL_INTERFACE("92907346-c3ea-5ed6-bdb1-3752c62c6f7f")
                IIppIntegerRange : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE get_Start(
                        INT32* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_End(
                        INT32* value
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IIppIntegerRange = _uuidof(IIppIntegerRange);
            } /* Printers */
        } /* Devices */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRange;
#endif /* !defined(____x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRange_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Interface Windows.Devices.Printers.IIppIntegerRangeFactory
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Interface is a part of the implementation of type Windows.Devices.Printers.IppIntegerRange
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRangeFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRangeFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Devices_Printers_IIppIntegerRangeFactory[] = L"Windows.Devices.Printers.IIppIntegerRangeFactory";
namespace ABI {
    namespace Windows {
        namespace Devices {
            namespace Printers {
                MIDL_INTERFACE("75d4ecae-f87e-54ad-b5d0-465204db7553")
                IIppIntegerRangeFactory : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE CreateInstance(
                        INT32 start,
                        INT32 end,
                        ABI::Windows::Devices::Printers::IIppIntegerRange** value
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IIppIntegerRangeFactory = _uuidof(IIppIntegerRangeFactory);
            } /* Printers */
        } /* Devices */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRangeFactory;
#endif /* !defined(____x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRangeFactory_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Interface Windows.Devices.Printers.IIppPrintDevice
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Interface is a part of the implementation of type Windows.Devices.Printers.IppPrintDevice
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____x_ABI_CWindows_CDevices_CPrinters_CIIppPrintDevice_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CDevices_CPrinters_CIIppPrintDevice_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Devices_Printers_IIppPrintDevice[] = L"Windows.Devices.Printers.IIppPrintDevice";
namespace ABI {
    namespace Windows {
        namespace Devices {
            namespace Printers {
                MIDL_INTERFACE("d748ac56-76f3-5dc6-afd4-c2a8686b9359")
                IIppPrintDevice : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE get_PrinterName(
                        HSTRING* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_PrinterUri(
                        ABI::Windows::Foundation::IUriRuntimeClass** value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE GetPrinterAttributesAsBuffer(
                        __FIIterable_1_HSTRING* attributeNames,
                        ABI::Windows::Storage::Streams::IBuffer** result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE GetPrinterAttributes(
                        __FIIterable_1_HSTRING* attributeNames,
                        __FIMap_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue** result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE SetPrinterAttributesFromBuffer(
                        ABI::Windows::Storage::Streams::IBuffer* printerAttributesBuffer,
                        ABI::Windows::Devices::Printers::IIppSetAttributesResult** result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE SetPrinterAttributes(
                        __FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* printerAttributes,
                        ABI::Windows::Devices::Printers::IIppSetAttributesResult** result
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IIppPrintDevice = _uuidof(IIppPrintDevice);
            } /* Printers */
        } /* Devices */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CDevices_CPrinters_CIIppPrintDevice;
#endif /* !defined(____x_ABI_CWindows_CDevices_CPrinters_CIIppPrintDevice_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Interface Windows.Devices.Printers.IIppResolution
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Interface is a part of the implementation of type Windows.Devices.Printers.IppResolution
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____x_ABI_CWindows_CDevices_CPrinters_CIIppResolution_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CDevices_CPrinters_CIIppResolution_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Devices_Printers_IIppResolution[] = L"Windows.Devices.Printers.IIppResolution";
namespace ABI {
    namespace Windows {
        namespace Devices {
            namespace Printers {
                MIDL_INTERFACE("cb493f86-6bf3-56f5-86ce-263d08aead63")
                IIppResolution : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE get_Width(
                        INT32* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_Height(
                        INT32* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_Unit(
                        ABI::Windows::Devices::Printers::IppResolutionUnit* value
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IIppResolution = _uuidof(IIppResolution);
            } /* Printers */
        } /* Devices */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CDevices_CPrinters_CIIppResolution;
#endif /* !defined(____x_ABI_CWindows_CDevices_CPrinters_CIIppResolution_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Interface Windows.Devices.Printers.IIppResolutionFactory
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Interface is a part of the implementation of type Windows.Devices.Printers.IppResolution
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____x_ABI_CWindows_CDevices_CPrinters_CIIppResolutionFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CDevices_CPrinters_CIIppResolutionFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Devices_Printers_IIppResolutionFactory[] = L"Windows.Devices.Printers.IIppResolutionFactory";
namespace ABI {
    namespace Windows {
        namespace Devices {
            namespace Printers {
                MIDL_INTERFACE("e481c2ae-251a-5326-b173-95543ed99a35")
                IIppResolutionFactory : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE CreateInstance(
                        INT32 width,
                        INT32 height,
                        ABI::Windows::Devices::Printers::IppResolutionUnit unit,
                        ABI::Windows::Devices::Printers::IIppResolution** value
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IIppResolutionFactory = _uuidof(IIppResolutionFactory);
            } /* Printers */
        } /* Devices */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CDevices_CPrinters_CIIppResolutionFactory;
#endif /* !defined(____x_ABI_CWindows_CDevices_CPrinters_CIIppResolutionFactory_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Interface Windows.Devices.Printers.IIppSetAttributesResult
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Interface is a part of the implementation of type Windows.Devices.Printers.IppSetAttributesResult
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____x_ABI_CWindows_CDevices_CPrinters_CIIppSetAttributesResult_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CDevices_CPrinters_CIIppSetAttributesResult_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Devices_Printers_IIppSetAttributesResult[] = L"Windows.Devices.Printers.IIppSetAttributesResult";
namespace ABI {
    namespace Windows {
        namespace Devices {
            namespace Printers {
                MIDL_INTERFACE("7d1c7f55-aa9d-58a3-90e9-17bdc5281f07")
                IIppSetAttributesResult : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE get_Succeeded(
                        boolean* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_AttributeErrors(
                        __FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError** value
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IIppSetAttributesResult = _uuidof(IIppSetAttributesResult);
            } /* Printers */
        } /* Devices */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CDevices_CPrinters_CIIppSetAttributesResult;
#endif /* !defined(____x_ABI_CWindows_CDevices_CPrinters_CIIppSetAttributesResult_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Interface Windows.Devices.Printers.IIppTextWithLanguage
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Interface is a part of the implementation of type Windows.Devices.Printers.IppTextWithLanguage
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguage_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguage_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Devices_Printers_IIppTextWithLanguage[] = L"Windows.Devices.Printers.IIppTextWithLanguage";
namespace ABI {
    namespace Windows {
        namespace Devices {
            namespace Printers {
                MIDL_INTERFACE("326447a6-5149-5936-90e8-0c736036bf77")
                IIppTextWithLanguage : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE get_Language(
                        HSTRING* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_Value(
                        HSTRING* value
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IIppTextWithLanguage = _uuidof(IIppTextWithLanguage);
            } /* Printers */
        } /* Devices */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguage;
#endif /* !defined(____x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguage_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Interface Windows.Devices.Printers.IIppTextWithLanguageFactory
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Interface is a part of the implementation of type Windows.Devices.Printers.IppTextWithLanguage
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguageFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguageFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Devices_Printers_IIppTextWithLanguageFactory[] = L"Windows.Devices.Printers.IIppTextWithLanguageFactory";
namespace ABI {
    namespace Windows {
        namespace Devices {
            namespace Printers {
                MIDL_INTERFACE("ca4a1e8d-2968-5775-997c-8a46f1a574ed")
                IIppTextWithLanguageFactory : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE CreateInstance(
                        HSTRING language,
                        HSTRING text,
                        ABI::Windows::Devices::Printers::IIppTextWithLanguage** value
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IIppTextWithLanguageFactory = _uuidof(IIppTextWithLanguageFactory);
            } /* Printers */
        } /* Devices */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguageFactory;
#endif /* !defined(____x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguageFactory_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Interface Windows.Devices.Printers.IPrint3DDevice
 *
 * Introduced to Windows.Devices.Printers.PrintersContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Devices.Printers.Print3DDevice
 *
 */
#if WINDOWS_DEVICES_PRINTERS_PRINTERSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CDevices_CPrinters_CIPrint3DDevice_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CDevices_CPrinters_CIPrint3DDevice_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Devices_Printers_IPrint3DDevice[] = L"Windows.Devices.Printers.IPrint3DDevice";
namespace ABI {
    namespace Windows {
        namespace Devices {
            namespace Printers {
                MIDL_INTERFACE("041c3d19-9713-42a2-9813-7dc3337428d3")
                IPrint3DDevice : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE get_PrintSchema(
                        ABI::Windows::Devices::Printers::IPrintSchema** value
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IPrint3DDevice = _uuidof(IPrint3DDevice);
            } /* Printers */
        } /* Devices */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CDevices_CPrinters_CIPrint3DDevice;
#endif /* !defined(____x_ABI_CWindows_CDevices_CPrinters_CIPrint3DDevice_INTERFACE_DEFINED__) */
#endif // WINDOWS_DEVICES_PRINTERS_PRINTERSCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Devices.Printers.IPrint3DDeviceStatics
 *
 * Introduced to Windows.Devices.Printers.PrintersContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Devices.Printers.Print3DDevice
 *
 */
#if WINDOWS_DEVICES_PRINTERS_PRINTERSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CDevices_CPrinters_CIPrint3DDeviceStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CDevices_CPrinters_CIPrint3DDeviceStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Devices_Printers_IPrint3DDeviceStatics[] = L"Windows.Devices.Printers.IPrint3DDeviceStatics";
namespace ABI {
    namespace Windows {
        namespace Devices {
            namespace Printers {
                MIDL_INTERFACE("fde3620a-67cd-41b7-a344-5150a1fd75b5")
                IPrint3DDeviceStatics : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE FromIdAsync(
                        HSTRING deviceId,
                        __FIAsyncOperation_1_Windows__CDevices__CPrinters__CPrint3DDevice** operation
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE GetDeviceSelector(
                        HSTRING* result
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IPrint3DDeviceStatics = _uuidof(IPrint3DDeviceStatics);
            } /* Printers */
        } /* Devices */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CDevices_CPrinters_CIPrint3DDeviceStatics;
#endif /* !defined(____x_ABI_CWindows_CDevices_CPrinters_CIPrint3DDeviceStatics_INTERFACE_DEFINED__) */
#endif // WINDOWS_DEVICES_PRINTERS_PRINTERSCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Devices.Printers.IPrintSchema
 *
 * Introduced to Windows.Devices.Printers.PrintersContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Devices.Printers.PrintSchema
 *
 */
#if WINDOWS_DEVICES_PRINTERS_PRINTERSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CDevices_CPrinters_CIPrintSchema_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CDevices_CPrinters_CIPrintSchema_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Devices_Printers_IPrintSchema[] = L"Windows.Devices.Printers.IPrintSchema";
namespace ABI {
    namespace Windows {
        namespace Devices {
            namespace Printers {
                MIDL_INTERFACE("c2b98316-26b8-4bfb-8138-9f962c22a35b")
                IPrintSchema : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE GetDefaultPrintTicketAsync(
                        __FIAsyncOperation_1_Windows__CStorage__CStreams__CIRandomAccessStreamWithContentType** operation
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE GetCapabilitiesAsync(
                        ABI::Windows::Storage::Streams::IRandomAccessStreamWithContentType* constrainTicket,
                        __FIAsyncOperation_1_Windows__CStorage__CStreams__CIRandomAccessStreamWithContentType** operation
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE MergeAndValidateWithDefaultPrintTicketAsync(
                        ABI::Windows::Storage::Streams::IRandomAccessStreamWithContentType* deltaTicket,
                        __FIAsyncOperation_1_Windows__CStorage__CStreams__CIRandomAccessStreamWithContentType** operation
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IPrintSchema = _uuidof(IPrintSchema);
            } /* Printers */
        } /* Devices */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CDevices_CPrinters_CIPrintSchema;
#endif /* !defined(____x_ABI_CWindows_CDevices_CPrinters_CIPrintSchema_INTERFACE_DEFINED__) */
#endif // WINDOWS_DEVICES_PRINTERS_PRINTERSCONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Devices.Printers.IppAttributeError
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Class implements the following interfaces:
 *    Windows.Devices.Printers.IIppAttributeError ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#ifndef RUNTIMECLASS_Windows_Devices_Printers_IppAttributeError_DEFINED
#define RUNTIMECLASS_Windows_Devices_Printers_IppAttributeError_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Devices_Printers_IppAttributeError[] = L"Windows.Devices.Printers.IppAttributeError";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Class Windows.Devices.Printers.IppAttributeValue
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Windows.Devices.Printers.IIppAttributeValueStatics interface starting with version 13.0 of the Windows.Foundation.UniversalApiContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Devices.Printers.IIppAttributeValue ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#ifndef RUNTIMECLASS_Windows_Devices_Printers_IppAttributeValue_DEFINED
#define RUNTIMECLASS_Windows_Devices_Printers_IppAttributeValue_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Devices_Printers_IppAttributeValue[] = L"Windows.Devices.Printers.IppAttributeValue";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Class Windows.Devices.Printers.IppIntegerRange
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via the Windows.Devices.Printers.IIppIntegerRangeFactory interface starting with version 13.0 of the Windows.Foundation.UniversalApiContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Devices.Printers.IIppIntegerRange ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#ifndef RUNTIMECLASS_Windows_Devices_Printers_IppIntegerRange_DEFINED
#define RUNTIMECLASS_Windows_Devices_Printers_IppIntegerRange_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Devices_Printers_IppIntegerRange[] = L"Windows.Devices.Printers.IppIntegerRange";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Class Windows.Devices.Printers.IppPrintDevice
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Class implements the following interfaces:
 *    Windows.Devices.Printers.IIppPrintDevice ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#ifndef RUNTIMECLASS_Windows_Devices_Printers_IppPrintDevice_DEFINED
#define RUNTIMECLASS_Windows_Devices_Printers_IppPrintDevice_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Devices_Printers_IppPrintDevice[] = L"Windows.Devices.Printers.IppPrintDevice";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Class Windows.Devices.Printers.IppResolution
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via the Windows.Devices.Printers.IIppResolutionFactory interface starting with version 13.0 of the Windows.Foundation.UniversalApiContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Devices.Printers.IIppResolution ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#ifndef RUNTIMECLASS_Windows_Devices_Printers_IppResolution_DEFINED
#define RUNTIMECLASS_Windows_Devices_Printers_IppResolution_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Devices_Printers_IppResolution[] = L"Windows.Devices.Printers.IppResolution";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Class Windows.Devices.Printers.IppSetAttributesResult
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Class implements the following interfaces:
 *    Windows.Devices.Printers.IIppSetAttributesResult ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#ifndef RUNTIMECLASS_Windows_Devices_Printers_IppSetAttributesResult_DEFINED
#define RUNTIMECLASS_Windows_Devices_Printers_IppSetAttributesResult_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Devices_Printers_IppSetAttributesResult[] = L"Windows.Devices.Printers.IppSetAttributesResult";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Class Windows.Devices.Printers.IppTextWithLanguage
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via the Windows.Devices.Printers.IIppTextWithLanguageFactory interface starting with version 13.0 of the Windows.Foundation.UniversalApiContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Devices.Printers.IIppTextWithLanguage ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#ifndef RUNTIMECLASS_Windows_Devices_Printers_IppTextWithLanguage_DEFINED
#define RUNTIMECLASS_Windows_Devices_Printers_IppTextWithLanguage_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Devices_Printers_IppTextWithLanguage[] = L"Windows.Devices.Printers.IppTextWithLanguage";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Class Windows.Devices.Printers.Print3DDevice
 *
 * Introduced to Windows.Devices.Printers.PrintersContract in version 1.0
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Windows.Devices.Printers.IPrint3DDeviceStatics interface starting with version 1.0 of the Windows.Devices.Printers.PrintersContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Devices.Printers.IPrint3DDevice ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_DEVICES_PRINTERS_PRINTERSCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Devices_Printers_Print3DDevice_DEFINED
#define RUNTIMECLASS_Windows_Devices_Printers_Print3DDevice_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Devices_Printers_Print3DDevice[] = L"Windows.Devices.Printers.Print3DDevice";
#endif
#endif // WINDOWS_DEVICES_PRINTERS_PRINTERSCONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Devices.Printers.PrintSchema
 *
 * Introduced to Windows.Devices.Printers.PrintersContract in version 1.0
 *
 * Class implements the following interfaces:
 *    Windows.Devices.Printers.IPrintSchema ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_DEVICES_PRINTERS_PRINTERSCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Devices_Printers_PrintSchema_DEFINED
#define RUNTIMECLASS_Windows_Devices_Printers_PrintSchema_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Devices_Printers_PrintSchema[] = L"Windows.Devices.Printers.PrintSchema";
#endif
#endif // WINDOWS_DEVICES_PRINTERS_PRINTERSCONTRACT_VERSION >= 0x10000

#else // !defined(__cplusplus)
/* Forward Declarations */
#ifndef ____x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeError_FWD_DEFINED__
#define ____x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeError_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeError __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeError;

#endif // ____x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeError_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue_FWD_DEFINED__
#define ____x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue;

#endif // ____x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics_FWD_DEFINED__
#define ____x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics;

#endif // ____x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRange_FWD_DEFINED__
#define ____x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRange_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRange __x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRange;

#endif // ____x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRange_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRangeFactory_FWD_DEFINED__
#define ____x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRangeFactory_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRangeFactory __x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRangeFactory;

#endif // ____x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRangeFactory_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CDevices_CPrinters_CIIppPrintDevice_FWD_DEFINED__
#define ____x_ABI_CWindows_CDevices_CPrinters_CIIppPrintDevice_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CDevices_CPrinters_CIIppPrintDevice __x_ABI_CWindows_CDevices_CPrinters_CIIppPrintDevice;

#endif // ____x_ABI_CWindows_CDevices_CPrinters_CIIppPrintDevice_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CDevices_CPrinters_CIIppResolution_FWD_DEFINED__
#define ____x_ABI_CWindows_CDevices_CPrinters_CIIppResolution_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CDevices_CPrinters_CIIppResolution __x_ABI_CWindows_CDevices_CPrinters_CIIppResolution;

#endif // ____x_ABI_CWindows_CDevices_CPrinters_CIIppResolution_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CDevices_CPrinters_CIIppResolutionFactory_FWD_DEFINED__
#define ____x_ABI_CWindows_CDevices_CPrinters_CIIppResolutionFactory_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CDevices_CPrinters_CIIppResolutionFactory __x_ABI_CWindows_CDevices_CPrinters_CIIppResolutionFactory;

#endif // ____x_ABI_CWindows_CDevices_CPrinters_CIIppResolutionFactory_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CDevices_CPrinters_CIIppSetAttributesResult_FWD_DEFINED__
#define ____x_ABI_CWindows_CDevices_CPrinters_CIIppSetAttributesResult_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CDevices_CPrinters_CIIppSetAttributesResult __x_ABI_CWindows_CDevices_CPrinters_CIIppSetAttributesResult;

#endif // ____x_ABI_CWindows_CDevices_CPrinters_CIIppSetAttributesResult_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguage_FWD_DEFINED__
#define ____x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguage_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguage __x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguage;

#endif // ____x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguage_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguageFactory_FWD_DEFINED__
#define ____x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguageFactory_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguageFactory __x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguageFactory;

#endif // ____x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguageFactory_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CDevices_CPrinters_CIPrint3DDevice_FWD_DEFINED__
#define ____x_ABI_CWindows_CDevices_CPrinters_CIPrint3DDevice_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CDevices_CPrinters_CIPrint3DDevice __x_ABI_CWindows_CDevices_CPrinters_CIPrint3DDevice;

#endif // ____x_ABI_CWindows_CDevices_CPrinters_CIPrint3DDevice_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CDevices_CPrinters_CIPrint3DDeviceStatics_FWD_DEFINED__
#define ____x_ABI_CWindows_CDevices_CPrinters_CIPrint3DDeviceStatics_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CDevices_CPrinters_CIPrint3DDeviceStatics __x_ABI_CWindows_CDevices_CPrinters_CIPrint3DDeviceStatics;

#endif // ____x_ABI_CWindows_CDevices_CPrinters_CIPrint3DDeviceStatics_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CDevices_CPrinters_CIPrintSchema_FWD_DEFINED__
#define ____x_ABI_CWindows_CDevices_CPrinters_CIPrintSchema_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CDevices_CPrinters_CIPrintSchema __x_ABI_CWindows_CDevices_CPrinters_CIPrintSchema;

#endif // ____x_ABI_CWindows_CDevices_CPrinters_CIPrintSchema_FWD_DEFINED__

// Parameterized interface forward declarations (C)

// Collection interface definitions

typedef interface __FIAsyncOperationCompletedHandler_1_Windows__CDevices__CPrinters__CPrint3DDevice __FIAsyncOperationCompletedHandler_1_Windows__CDevices__CPrinters__CPrint3DDevice;

#if WINDOWS_DEVICES_PRINTERS_PRINTERSCONTRACT_VERSION >= 0x10000
#if !defined(____FIAsyncOperation_1_Windows__CDevices__CPrinters__CPrint3DDevice_INTERFACE_DEFINED__)
#define ____FIAsyncOperation_1_Windows__CDevices__CPrinters__CPrint3DDevice_INTERFACE_DEFINED__

typedef interface __FIAsyncOperation_1_Windows__CDevices__CPrinters__CPrint3DDevice __FIAsyncOperation_1_Windows__CDevices__CPrinters__CPrint3DDevice;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIAsyncOperation_1_Windows__CDevices__CPrinters__CPrint3DDevice;

typedef struct __FIAsyncOperation_1_Windows__CDevices__CPrinters__CPrint3DDeviceVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIAsyncOperation_1_Windows__CDevices__CPrinters__CPrint3DDevice* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIAsyncOperation_1_Windows__CDevices__CPrinters__CPrint3DDevice* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIAsyncOperation_1_Windows__CDevices__CPrinters__CPrint3DDevice* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIAsyncOperation_1_Windows__CDevices__CPrinters__CPrint3DDevice* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIAsyncOperation_1_Windows__CDevices__CPrinters__CPrint3DDevice* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIAsyncOperation_1_Windows__CDevices__CPrinters__CPrint3DDevice* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* put_Completed)(__FIAsyncOperation_1_Windows__CDevices__CPrinters__CPrint3DDevice* This,
        __FIAsyncOperationCompletedHandler_1_Windows__CDevices__CPrinters__CPrint3DDevice* handler);
    HRESULT (STDMETHODCALLTYPE* get_Completed)(__FIAsyncOperation_1_Windows__CDevices__CPrinters__CPrint3DDevice* This,
        __FIAsyncOperationCompletedHandler_1_Windows__CDevices__CPrinters__CPrint3DDevice** result);
    HRESULT (STDMETHODCALLTYPE* GetResults)(__FIAsyncOperation_1_Windows__CDevices__CPrinters__CPrint3DDevice* This,
        __x_ABI_CWindows_CDevices_CPrinters_CIPrint3DDevice** result);

    END_INTERFACE
} __FIAsyncOperation_1_Windows__CDevices__CPrinters__CPrint3DDeviceVtbl;

interface __FIAsyncOperation_1_Windows__CDevices__CPrinters__CPrint3DDevice
{
    CONST_VTBL struct __FIAsyncOperation_1_Windows__CDevices__CPrinters__CPrint3DDeviceVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIAsyncOperation_1_Windows__CDevices__CPrinters__CPrint3DDevice_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIAsyncOperation_1_Windows__CDevices__CPrinters__CPrint3DDevice_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIAsyncOperation_1_Windows__CDevices__CPrinters__CPrint3DDevice_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIAsyncOperation_1_Windows__CDevices__CPrinters__CPrint3DDevice_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIAsyncOperation_1_Windows__CDevices__CPrinters__CPrint3DDevice_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIAsyncOperation_1_Windows__CDevices__CPrinters__CPrint3DDevice_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIAsyncOperation_1_Windows__CDevices__CPrinters__CPrint3DDevice_put_Completed(This, handler) \
    ((This)->lpVtbl->put_Completed(This, handler))

#define __FIAsyncOperation_1_Windows__CDevices__CPrinters__CPrint3DDevice_get_Completed(This, result) \
    ((This)->lpVtbl->get_Completed(This, result))

#define __FIAsyncOperation_1_Windows__CDevices__CPrinters__CPrint3DDevice_GetResults(This, result) \
    ((This)->lpVtbl->GetResults(This, result))

#endif /* COBJMACROS */

#endif // ____FIAsyncOperation_1_Windows__CDevices__CPrinters__CPrint3DDevice_INTERFACE_DEFINED__
#endif // WINDOWS_DEVICES_PRINTERS_PRINTERSCONTRACT_VERSION >= 0x10000

#if WINDOWS_DEVICES_PRINTERS_PRINTERSCONTRACT_VERSION >= 0x10000
#if !defined(____FIAsyncOperationCompletedHandler_1_Windows__CDevices__CPrinters__CPrint3DDevice_INTERFACE_DEFINED__)
#define ____FIAsyncOperationCompletedHandler_1_Windows__CDevices__CPrinters__CPrint3DDevice_INTERFACE_DEFINED__

typedef interface __FIAsyncOperationCompletedHandler_1_Windows__CDevices__CPrinters__CPrint3DDevice __FIAsyncOperationCompletedHandler_1_Windows__CDevices__CPrinters__CPrint3DDevice;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIAsyncOperationCompletedHandler_1_Windows__CDevices__CPrinters__CPrint3DDevice;

typedef struct __FIAsyncOperationCompletedHandler_1_Windows__CDevices__CPrinters__CPrint3DDeviceVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIAsyncOperationCompletedHandler_1_Windows__CDevices__CPrinters__CPrint3DDevice* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIAsyncOperationCompletedHandler_1_Windows__CDevices__CPrinters__CPrint3DDevice* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIAsyncOperationCompletedHandler_1_Windows__CDevices__CPrinters__CPrint3DDevice* This);
    HRESULT (STDMETHODCALLTYPE* Invoke)(__FIAsyncOperationCompletedHandler_1_Windows__CDevices__CPrinters__CPrint3DDevice* This,
        __FIAsyncOperation_1_Windows__CDevices__CPrinters__CPrint3DDevice* asyncInfo,
        AsyncStatus asyncStatus);

    END_INTERFACE
} __FIAsyncOperationCompletedHandler_1_Windows__CDevices__CPrinters__CPrint3DDeviceVtbl;

interface __FIAsyncOperationCompletedHandler_1_Windows__CDevices__CPrinters__CPrint3DDevice
{
    CONST_VTBL struct __FIAsyncOperationCompletedHandler_1_Windows__CDevices__CPrinters__CPrint3DDeviceVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIAsyncOperationCompletedHandler_1_Windows__CDevices__CPrinters__CPrint3DDevice_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIAsyncOperationCompletedHandler_1_Windows__CDevices__CPrinters__CPrint3DDevice_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIAsyncOperationCompletedHandler_1_Windows__CDevices__CPrinters__CPrint3DDevice_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIAsyncOperationCompletedHandler_1_Windows__CDevices__CPrinters__CPrint3DDevice_Invoke(This, asyncInfo, asyncStatus) \
    ((This)->lpVtbl->Invoke(This, asyncInfo, asyncStatus))

#endif /* COBJMACROS */

#endif // ____FIAsyncOperationCompletedHandler_1_Windows__CDevices__CPrinters__CPrint3DDevice_INTERFACE_DEFINED__
#endif // WINDOWS_DEVICES_PRINTERS_PRINTERSCONTRACT_VERSION >= 0x10000

#ifndef ____x_ABI_CWindows_CStorage_CStreams_CIRandomAccessStreamWithContentType_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CStreams_CIRandomAccessStreamWithContentType_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CStorage_CStreams_CIRandomAccessStreamWithContentType __x_ABI_CWindows_CStorage_CStreams_CIRandomAccessStreamWithContentType;

#endif // ____x_ABI_CWindows_CStorage_CStreams_CIRandomAccessStreamWithContentType_FWD_DEFINED__

typedef interface __FIAsyncOperationCompletedHandler_1_Windows__CStorage__CStreams__CIRandomAccessStreamWithContentType __FIAsyncOperationCompletedHandler_1_Windows__CStorage__CStreams__CIRandomAccessStreamWithContentType;

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if !defined(____FIAsyncOperation_1_Windows__CStorage__CStreams__CIRandomAccessStreamWithContentType_INTERFACE_DEFINED__)
#define ____FIAsyncOperation_1_Windows__CStorage__CStreams__CIRandomAccessStreamWithContentType_INTERFACE_DEFINED__

typedef interface __FIAsyncOperation_1_Windows__CStorage__CStreams__CIRandomAccessStreamWithContentType __FIAsyncOperation_1_Windows__CStorage__CStreams__CIRandomAccessStreamWithContentType;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIAsyncOperation_1_Windows__CStorage__CStreams__CIRandomAccessStreamWithContentType;

typedef struct __FIAsyncOperation_1_Windows__CStorage__CStreams__CIRandomAccessStreamWithContentTypeVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIAsyncOperation_1_Windows__CStorage__CStreams__CIRandomAccessStreamWithContentType* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIAsyncOperation_1_Windows__CStorage__CStreams__CIRandomAccessStreamWithContentType* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIAsyncOperation_1_Windows__CStorage__CStreams__CIRandomAccessStreamWithContentType* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIAsyncOperation_1_Windows__CStorage__CStreams__CIRandomAccessStreamWithContentType* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIAsyncOperation_1_Windows__CStorage__CStreams__CIRandomAccessStreamWithContentType* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIAsyncOperation_1_Windows__CStorage__CStreams__CIRandomAccessStreamWithContentType* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* put_Completed)(__FIAsyncOperation_1_Windows__CStorage__CStreams__CIRandomAccessStreamWithContentType* This,
        __FIAsyncOperationCompletedHandler_1_Windows__CStorage__CStreams__CIRandomAccessStreamWithContentType* handler);
    HRESULT (STDMETHODCALLTYPE* get_Completed)(__FIAsyncOperation_1_Windows__CStorage__CStreams__CIRandomAccessStreamWithContentType* This,
        __FIAsyncOperationCompletedHandler_1_Windows__CStorage__CStreams__CIRandomAccessStreamWithContentType** result);
    HRESULT (STDMETHODCALLTYPE* GetResults)(__FIAsyncOperation_1_Windows__CStorage__CStreams__CIRandomAccessStreamWithContentType* This,
        __x_ABI_CWindows_CStorage_CStreams_CIRandomAccessStreamWithContentType** result);

    END_INTERFACE
} __FIAsyncOperation_1_Windows__CStorage__CStreams__CIRandomAccessStreamWithContentTypeVtbl;

interface __FIAsyncOperation_1_Windows__CStorage__CStreams__CIRandomAccessStreamWithContentType
{
    CONST_VTBL struct __FIAsyncOperation_1_Windows__CStorage__CStreams__CIRandomAccessStreamWithContentTypeVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIAsyncOperation_1_Windows__CStorage__CStreams__CIRandomAccessStreamWithContentType_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIAsyncOperation_1_Windows__CStorage__CStreams__CIRandomAccessStreamWithContentType_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIAsyncOperation_1_Windows__CStorage__CStreams__CIRandomAccessStreamWithContentType_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIAsyncOperation_1_Windows__CStorage__CStreams__CIRandomAccessStreamWithContentType_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIAsyncOperation_1_Windows__CStorage__CStreams__CIRandomAccessStreamWithContentType_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIAsyncOperation_1_Windows__CStorage__CStreams__CIRandomAccessStreamWithContentType_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIAsyncOperation_1_Windows__CStorage__CStreams__CIRandomAccessStreamWithContentType_put_Completed(This, handler) \
    ((This)->lpVtbl->put_Completed(This, handler))

#define __FIAsyncOperation_1_Windows__CStorage__CStreams__CIRandomAccessStreamWithContentType_get_Completed(This, result) \
    ((This)->lpVtbl->get_Completed(This, result))

#define __FIAsyncOperation_1_Windows__CStorage__CStreams__CIRandomAccessStreamWithContentType_GetResults(This, result) \
    ((This)->lpVtbl->GetResults(This, result))

#endif /* COBJMACROS */

#endif // ____FIAsyncOperation_1_Windows__CStorage__CStreams__CIRandomAccessStreamWithContentType_INTERFACE_DEFINED__
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if !defined(____FIAsyncOperationCompletedHandler_1_Windows__CStorage__CStreams__CIRandomAccessStreamWithContentType_INTERFACE_DEFINED__)
#define ____FIAsyncOperationCompletedHandler_1_Windows__CStorage__CStreams__CIRandomAccessStreamWithContentType_INTERFACE_DEFINED__

typedef interface __FIAsyncOperationCompletedHandler_1_Windows__CStorage__CStreams__CIRandomAccessStreamWithContentType __FIAsyncOperationCompletedHandler_1_Windows__CStorage__CStreams__CIRandomAccessStreamWithContentType;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIAsyncOperationCompletedHandler_1_Windows__CStorage__CStreams__CIRandomAccessStreamWithContentType;

typedef struct __FIAsyncOperationCompletedHandler_1_Windows__CStorage__CStreams__CIRandomAccessStreamWithContentTypeVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIAsyncOperationCompletedHandler_1_Windows__CStorage__CStreams__CIRandomAccessStreamWithContentType* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIAsyncOperationCompletedHandler_1_Windows__CStorage__CStreams__CIRandomAccessStreamWithContentType* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIAsyncOperationCompletedHandler_1_Windows__CStorage__CStreams__CIRandomAccessStreamWithContentType* This);
    HRESULT (STDMETHODCALLTYPE* Invoke)(__FIAsyncOperationCompletedHandler_1_Windows__CStorage__CStreams__CIRandomAccessStreamWithContentType* This,
        __FIAsyncOperation_1_Windows__CStorage__CStreams__CIRandomAccessStreamWithContentType* asyncInfo,
        AsyncStatus asyncStatus);

    END_INTERFACE
} __FIAsyncOperationCompletedHandler_1_Windows__CStorage__CStreams__CIRandomAccessStreamWithContentTypeVtbl;

interface __FIAsyncOperationCompletedHandler_1_Windows__CStorage__CStreams__CIRandomAccessStreamWithContentType
{
    CONST_VTBL struct __FIAsyncOperationCompletedHandler_1_Windows__CStorage__CStreams__CIRandomAccessStreamWithContentTypeVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIAsyncOperationCompletedHandler_1_Windows__CStorage__CStreams__CIRandomAccessStreamWithContentType_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIAsyncOperationCompletedHandler_1_Windows__CStorage__CStreams__CIRandomAccessStreamWithContentType_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIAsyncOperationCompletedHandler_1_Windows__CStorage__CStreams__CIRandomAccessStreamWithContentType_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIAsyncOperationCompletedHandler_1_Windows__CStorage__CStreams__CIRandomAccessStreamWithContentType_Invoke(This, asyncInfo, asyncStatus) \
    ((This)->lpVtbl->Invoke(This, asyncInfo, asyncStatus))

#endif /* COBJMACROS */

#endif // ____FIAsyncOperationCompletedHandler_1_Windows__CStorage__CStreams__CIRandomAccessStreamWithContentType_INTERFACE_DEFINED__
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#if !defined(____FIIterator_1_boolean_INTERFACE_DEFINED__)
#define ____FIIterator_1_boolean_INTERFACE_DEFINED__

typedef interface __FIIterator_1_boolean __FIIterator_1_boolean;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterator_1_boolean;

typedef struct __FIIterator_1_booleanVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIIterator_1_boolean* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIIterator_1_boolean* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIIterator_1_boolean* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIIterator_1_boolean* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIIterator_1_boolean* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIIterator_1_boolean* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Current)(__FIIterator_1_boolean* This,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* get_HasCurrent)(__FIIterator_1_boolean* This,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* MoveNext)(__FIIterator_1_boolean* This,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* GetMany)(__FIIterator_1_boolean* This,
        UINT32 itemsLength,
        boolean* items,
        UINT32* result);

    END_INTERFACE
} __FIIterator_1_booleanVtbl;

interface __FIIterator_1_boolean
{
    CONST_VTBL struct __FIIterator_1_booleanVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIIterator_1_boolean_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIIterator_1_boolean_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIIterator_1_boolean_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIIterator_1_boolean_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIIterator_1_boolean_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIIterator_1_boolean_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIIterator_1_boolean_get_Current(This, result) \
    ((This)->lpVtbl->get_Current(This, result))

#define __FIIterator_1_boolean_get_HasCurrent(This, result) \
    ((This)->lpVtbl->get_HasCurrent(This, result))

#define __FIIterator_1_boolean_MoveNext(This, result) \
    ((This)->lpVtbl->MoveNext(This, result))

#define __FIIterator_1_boolean_GetMany(This, itemsLength, items, result) \
    ((This)->lpVtbl->GetMany(This, itemsLength, items, result))

#endif /* COBJMACROS */

#endif // ____FIIterator_1_boolean_INTERFACE_DEFINED__

#if !defined(____FIIterable_1_boolean_INTERFACE_DEFINED__)
#define ____FIIterable_1_boolean_INTERFACE_DEFINED__

typedef interface __FIIterable_1_boolean __FIIterable_1_boolean;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterable_1_boolean;

typedef struct __FIIterable_1_booleanVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIIterable_1_boolean* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIIterable_1_boolean* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIIterable_1_boolean* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIIterable_1_boolean* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIIterable_1_boolean* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIIterable_1_boolean* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* First)(__FIIterable_1_boolean* This,
        __FIIterator_1_boolean** result);

    END_INTERFACE
} __FIIterable_1_booleanVtbl;

interface __FIIterable_1_boolean
{
    CONST_VTBL struct __FIIterable_1_booleanVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIIterable_1_boolean_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIIterable_1_boolean_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIIterable_1_boolean_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIIterable_1_boolean_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIIterable_1_boolean_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIIterable_1_boolean_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIIterable_1_boolean_First(This, result) \
    ((This)->lpVtbl->First(This, result))

#endif /* COBJMACROS */

#endif // ____FIIterable_1_boolean_INTERFACE_DEFINED__

#if !defined(____FIIterator_1_int_INTERFACE_DEFINED__)
#define ____FIIterator_1_int_INTERFACE_DEFINED__

typedef interface __FIIterator_1_int __FIIterator_1_int;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterator_1_int;

typedef struct __FIIterator_1_intVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIIterator_1_int* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIIterator_1_int* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIIterator_1_int* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIIterator_1_int* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIIterator_1_int* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIIterator_1_int* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Current)(__FIIterator_1_int* This,
        INT32* result);
    HRESULT (STDMETHODCALLTYPE* get_HasCurrent)(__FIIterator_1_int* This,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* MoveNext)(__FIIterator_1_int* This,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* GetMany)(__FIIterator_1_int* This,
        UINT32 itemsLength,
        INT32* items,
        UINT32* result);

    END_INTERFACE
} __FIIterator_1_intVtbl;

interface __FIIterator_1_int
{
    CONST_VTBL struct __FIIterator_1_intVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIIterator_1_int_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIIterator_1_int_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIIterator_1_int_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIIterator_1_int_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIIterator_1_int_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIIterator_1_int_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIIterator_1_int_get_Current(This, result) \
    ((This)->lpVtbl->get_Current(This, result))

#define __FIIterator_1_int_get_HasCurrent(This, result) \
    ((This)->lpVtbl->get_HasCurrent(This, result))

#define __FIIterator_1_int_MoveNext(This, result) \
    ((This)->lpVtbl->MoveNext(This, result))

#define __FIIterator_1_int_GetMany(This, itemsLength, items, result) \
    ((This)->lpVtbl->GetMany(This, itemsLength, items, result))

#endif /* COBJMACROS */

#endif // ____FIIterator_1_int_INTERFACE_DEFINED__

#if !defined(____FIIterable_1_int_INTERFACE_DEFINED__)
#define ____FIIterable_1_int_INTERFACE_DEFINED__

typedef interface __FIIterable_1_int __FIIterable_1_int;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterable_1_int;

typedef struct __FIIterable_1_intVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIIterable_1_int* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIIterable_1_int* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIIterable_1_int* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIIterable_1_int* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIIterable_1_int* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIIterable_1_int* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* First)(__FIIterable_1_int* This,
        __FIIterator_1_int** result);

    END_INTERFACE
} __FIIterable_1_intVtbl;

interface __FIIterable_1_int
{
    CONST_VTBL struct __FIIterable_1_intVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIIterable_1_int_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIIterable_1_int_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIIterable_1_int_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIIterable_1_int_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIIterable_1_int_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIIterable_1_int_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIIterable_1_int_First(This, result) \
    ((This)->lpVtbl->First(This, result))

#endif /* COBJMACROS */

#endif // ____FIIterable_1_int_INTERFACE_DEFINED__

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

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____FIIterator_1_Windows__CDevices__CPrinters__CIppAttributeValue_INTERFACE_DEFINED__)
#define ____FIIterator_1_Windows__CDevices__CPrinters__CIppAttributeValue_INTERFACE_DEFINED__

typedef interface __FIIterator_1_Windows__CDevices__CPrinters__CIppAttributeValue __FIIterator_1_Windows__CDevices__CPrinters__CIppAttributeValue;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterator_1_Windows__CDevices__CPrinters__CIppAttributeValue;

typedef struct __FIIterator_1_Windows__CDevices__CPrinters__CIppAttributeValueVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIIterator_1_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIIterator_1_Windows__CDevices__CPrinters__CIppAttributeValue* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIIterator_1_Windows__CDevices__CPrinters__CIppAttributeValue* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIIterator_1_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIIterator_1_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIIterator_1_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Current)(__FIIterator_1_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue** result);
    HRESULT (STDMETHODCALLTYPE* get_HasCurrent)(__FIIterator_1_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* MoveNext)(__FIIterator_1_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* GetMany)(__FIIterator_1_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        UINT32 itemsLength,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue** items,
        UINT32* result);

    END_INTERFACE
} __FIIterator_1_Windows__CDevices__CPrinters__CIppAttributeValueVtbl;

interface __FIIterator_1_Windows__CDevices__CPrinters__CIppAttributeValue
{
    CONST_VTBL struct __FIIterator_1_Windows__CDevices__CPrinters__CIppAttributeValueVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIIterator_1_Windows__CDevices__CPrinters__CIppAttributeValue_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIIterator_1_Windows__CDevices__CPrinters__CIppAttributeValue_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIIterator_1_Windows__CDevices__CPrinters__CIppAttributeValue_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIIterator_1_Windows__CDevices__CPrinters__CIppAttributeValue_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIIterator_1_Windows__CDevices__CPrinters__CIppAttributeValue_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIIterator_1_Windows__CDevices__CPrinters__CIppAttributeValue_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIIterator_1_Windows__CDevices__CPrinters__CIppAttributeValue_get_Current(This, result) \
    ((This)->lpVtbl->get_Current(This, result))

#define __FIIterator_1_Windows__CDevices__CPrinters__CIppAttributeValue_get_HasCurrent(This, result) \
    ((This)->lpVtbl->get_HasCurrent(This, result))

#define __FIIterator_1_Windows__CDevices__CPrinters__CIppAttributeValue_MoveNext(This, result) \
    ((This)->lpVtbl->MoveNext(This, result))

#define __FIIterator_1_Windows__CDevices__CPrinters__CIppAttributeValue_GetMany(This, itemsLength, items, result) \
    ((This)->lpVtbl->GetMany(This, itemsLength, items, result))

#endif /* COBJMACROS */

#endif // ____FIIterator_1_Windows__CDevices__CPrinters__CIppAttributeValue_INTERFACE_DEFINED__
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____FIIterable_1_Windows__CDevices__CPrinters__CIppAttributeValue_INTERFACE_DEFINED__)
#define ____FIIterable_1_Windows__CDevices__CPrinters__CIppAttributeValue_INTERFACE_DEFINED__

typedef interface __FIIterable_1_Windows__CDevices__CPrinters__CIppAttributeValue __FIIterable_1_Windows__CDevices__CPrinters__CIppAttributeValue;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterable_1_Windows__CDevices__CPrinters__CIppAttributeValue;

typedef struct __FIIterable_1_Windows__CDevices__CPrinters__CIppAttributeValueVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIIterable_1_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIIterable_1_Windows__CDevices__CPrinters__CIppAttributeValue* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIIterable_1_Windows__CDevices__CPrinters__CIppAttributeValue* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIIterable_1_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIIterable_1_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIIterable_1_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* First)(__FIIterable_1_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        __FIIterator_1_Windows__CDevices__CPrinters__CIppAttributeValue** result);

    END_INTERFACE
} __FIIterable_1_Windows__CDevices__CPrinters__CIppAttributeValueVtbl;

interface __FIIterable_1_Windows__CDevices__CPrinters__CIppAttributeValue
{
    CONST_VTBL struct __FIIterable_1_Windows__CDevices__CPrinters__CIppAttributeValueVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIIterable_1_Windows__CDevices__CPrinters__CIppAttributeValue_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIIterable_1_Windows__CDevices__CPrinters__CIppAttributeValue_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIIterable_1_Windows__CDevices__CPrinters__CIppAttributeValue_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIIterable_1_Windows__CDevices__CPrinters__CIppAttributeValue_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIIterable_1_Windows__CDevices__CPrinters__CIppAttributeValue_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIIterable_1_Windows__CDevices__CPrinters__CIppAttributeValue_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIIterable_1_Windows__CDevices__CPrinters__CIppAttributeValue_First(This, result) \
    ((This)->lpVtbl->First(This, result))

#endif /* COBJMACROS */

#endif // ____FIIterable_1_Windows__CDevices__CPrinters__CIppAttributeValue_INTERFACE_DEFINED__
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____FIIterator_1_Windows__CDevices__CPrinters__CIppIntegerRange_INTERFACE_DEFINED__)
#define ____FIIterator_1_Windows__CDevices__CPrinters__CIppIntegerRange_INTERFACE_DEFINED__

typedef interface __FIIterator_1_Windows__CDevices__CPrinters__CIppIntegerRange __FIIterator_1_Windows__CDevices__CPrinters__CIppIntegerRange;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterator_1_Windows__CDevices__CPrinters__CIppIntegerRange;

typedef struct __FIIterator_1_Windows__CDevices__CPrinters__CIppIntegerRangeVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIIterator_1_Windows__CDevices__CPrinters__CIppIntegerRange* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIIterator_1_Windows__CDevices__CPrinters__CIppIntegerRange* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIIterator_1_Windows__CDevices__CPrinters__CIppIntegerRange* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIIterator_1_Windows__CDevices__CPrinters__CIppIntegerRange* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIIterator_1_Windows__CDevices__CPrinters__CIppIntegerRange* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIIterator_1_Windows__CDevices__CPrinters__CIppIntegerRange* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Current)(__FIIterator_1_Windows__CDevices__CPrinters__CIppIntegerRange* This,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRange** result);
    HRESULT (STDMETHODCALLTYPE* get_HasCurrent)(__FIIterator_1_Windows__CDevices__CPrinters__CIppIntegerRange* This,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* MoveNext)(__FIIterator_1_Windows__CDevices__CPrinters__CIppIntegerRange* This,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* GetMany)(__FIIterator_1_Windows__CDevices__CPrinters__CIppIntegerRange* This,
        UINT32 itemsLength,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRange** items,
        UINT32* result);

    END_INTERFACE
} __FIIterator_1_Windows__CDevices__CPrinters__CIppIntegerRangeVtbl;

interface __FIIterator_1_Windows__CDevices__CPrinters__CIppIntegerRange
{
    CONST_VTBL struct __FIIterator_1_Windows__CDevices__CPrinters__CIppIntegerRangeVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIIterator_1_Windows__CDevices__CPrinters__CIppIntegerRange_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIIterator_1_Windows__CDevices__CPrinters__CIppIntegerRange_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIIterator_1_Windows__CDevices__CPrinters__CIppIntegerRange_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIIterator_1_Windows__CDevices__CPrinters__CIppIntegerRange_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIIterator_1_Windows__CDevices__CPrinters__CIppIntegerRange_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIIterator_1_Windows__CDevices__CPrinters__CIppIntegerRange_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIIterator_1_Windows__CDevices__CPrinters__CIppIntegerRange_get_Current(This, result) \
    ((This)->lpVtbl->get_Current(This, result))

#define __FIIterator_1_Windows__CDevices__CPrinters__CIppIntegerRange_get_HasCurrent(This, result) \
    ((This)->lpVtbl->get_HasCurrent(This, result))

#define __FIIterator_1_Windows__CDevices__CPrinters__CIppIntegerRange_MoveNext(This, result) \
    ((This)->lpVtbl->MoveNext(This, result))

#define __FIIterator_1_Windows__CDevices__CPrinters__CIppIntegerRange_GetMany(This, itemsLength, items, result) \
    ((This)->lpVtbl->GetMany(This, itemsLength, items, result))

#endif /* COBJMACROS */

#endif // ____FIIterator_1_Windows__CDevices__CPrinters__CIppIntegerRange_INTERFACE_DEFINED__
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____FIIterable_1_Windows__CDevices__CPrinters__CIppIntegerRange_INTERFACE_DEFINED__)
#define ____FIIterable_1_Windows__CDevices__CPrinters__CIppIntegerRange_INTERFACE_DEFINED__

typedef interface __FIIterable_1_Windows__CDevices__CPrinters__CIppIntegerRange __FIIterable_1_Windows__CDevices__CPrinters__CIppIntegerRange;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterable_1_Windows__CDevices__CPrinters__CIppIntegerRange;

typedef struct __FIIterable_1_Windows__CDevices__CPrinters__CIppIntegerRangeVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIIterable_1_Windows__CDevices__CPrinters__CIppIntegerRange* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIIterable_1_Windows__CDevices__CPrinters__CIppIntegerRange* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIIterable_1_Windows__CDevices__CPrinters__CIppIntegerRange* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIIterable_1_Windows__CDevices__CPrinters__CIppIntegerRange* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIIterable_1_Windows__CDevices__CPrinters__CIppIntegerRange* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIIterable_1_Windows__CDevices__CPrinters__CIppIntegerRange* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* First)(__FIIterable_1_Windows__CDevices__CPrinters__CIppIntegerRange* This,
        __FIIterator_1_Windows__CDevices__CPrinters__CIppIntegerRange** result);

    END_INTERFACE
} __FIIterable_1_Windows__CDevices__CPrinters__CIppIntegerRangeVtbl;

interface __FIIterable_1_Windows__CDevices__CPrinters__CIppIntegerRange
{
    CONST_VTBL struct __FIIterable_1_Windows__CDevices__CPrinters__CIppIntegerRangeVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIIterable_1_Windows__CDevices__CPrinters__CIppIntegerRange_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIIterable_1_Windows__CDevices__CPrinters__CIppIntegerRange_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIIterable_1_Windows__CDevices__CPrinters__CIppIntegerRange_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIIterable_1_Windows__CDevices__CPrinters__CIppIntegerRange_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIIterable_1_Windows__CDevices__CPrinters__CIppIntegerRange_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIIterable_1_Windows__CDevices__CPrinters__CIppIntegerRange_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIIterable_1_Windows__CDevices__CPrinters__CIppIntegerRange_First(This, result) \
    ((This)->lpVtbl->First(This, result))

#endif /* COBJMACROS */

#endif // ____FIIterable_1_Windows__CDevices__CPrinters__CIppIntegerRange_INTERFACE_DEFINED__
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____FIIterator_1_Windows__CDevices__CPrinters__CIppResolution_INTERFACE_DEFINED__)
#define ____FIIterator_1_Windows__CDevices__CPrinters__CIppResolution_INTERFACE_DEFINED__

typedef interface __FIIterator_1_Windows__CDevices__CPrinters__CIppResolution __FIIterator_1_Windows__CDevices__CPrinters__CIppResolution;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterator_1_Windows__CDevices__CPrinters__CIppResolution;

typedef struct __FIIterator_1_Windows__CDevices__CPrinters__CIppResolutionVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIIterator_1_Windows__CDevices__CPrinters__CIppResolution* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIIterator_1_Windows__CDevices__CPrinters__CIppResolution* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIIterator_1_Windows__CDevices__CPrinters__CIppResolution* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIIterator_1_Windows__CDevices__CPrinters__CIppResolution* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIIterator_1_Windows__CDevices__CPrinters__CIppResolution* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIIterator_1_Windows__CDevices__CPrinters__CIppResolution* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Current)(__FIIterator_1_Windows__CDevices__CPrinters__CIppResolution* This,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppResolution** result);
    HRESULT (STDMETHODCALLTYPE* get_HasCurrent)(__FIIterator_1_Windows__CDevices__CPrinters__CIppResolution* This,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* MoveNext)(__FIIterator_1_Windows__CDevices__CPrinters__CIppResolution* This,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* GetMany)(__FIIterator_1_Windows__CDevices__CPrinters__CIppResolution* This,
        UINT32 itemsLength,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppResolution** items,
        UINT32* result);

    END_INTERFACE
} __FIIterator_1_Windows__CDevices__CPrinters__CIppResolutionVtbl;

interface __FIIterator_1_Windows__CDevices__CPrinters__CIppResolution
{
    CONST_VTBL struct __FIIterator_1_Windows__CDevices__CPrinters__CIppResolutionVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIIterator_1_Windows__CDevices__CPrinters__CIppResolution_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIIterator_1_Windows__CDevices__CPrinters__CIppResolution_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIIterator_1_Windows__CDevices__CPrinters__CIppResolution_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIIterator_1_Windows__CDevices__CPrinters__CIppResolution_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIIterator_1_Windows__CDevices__CPrinters__CIppResolution_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIIterator_1_Windows__CDevices__CPrinters__CIppResolution_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIIterator_1_Windows__CDevices__CPrinters__CIppResolution_get_Current(This, result) \
    ((This)->lpVtbl->get_Current(This, result))

#define __FIIterator_1_Windows__CDevices__CPrinters__CIppResolution_get_HasCurrent(This, result) \
    ((This)->lpVtbl->get_HasCurrent(This, result))

#define __FIIterator_1_Windows__CDevices__CPrinters__CIppResolution_MoveNext(This, result) \
    ((This)->lpVtbl->MoveNext(This, result))

#define __FIIterator_1_Windows__CDevices__CPrinters__CIppResolution_GetMany(This, itemsLength, items, result) \
    ((This)->lpVtbl->GetMany(This, itemsLength, items, result))

#endif /* COBJMACROS */

#endif // ____FIIterator_1_Windows__CDevices__CPrinters__CIppResolution_INTERFACE_DEFINED__
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____FIIterable_1_Windows__CDevices__CPrinters__CIppResolution_INTERFACE_DEFINED__)
#define ____FIIterable_1_Windows__CDevices__CPrinters__CIppResolution_INTERFACE_DEFINED__

typedef interface __FIIterable_1_Windows__CDevices__CPrinters__CIppResolution __FIIterable_1_Windows__CDevices__CPrinters__CIppResolution;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterable_1_Windows__CDevices__CPrinters__CIppResolution;

typedef struct __FIIterable_1_Windows__CDevices__CPrinters__CIppResolutionVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIIterable_1_Windows__CDevices__CPrinters__CIppResolution* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIIterable_1_Windows__CDevices__CPrinters__CIppResolution* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIIterable_1_Windows__CDevices__CPrinters__CIppResolution* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIIterable_1_Windows__CDevices__CPrinters__CIppResolution* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIIterable_1_Windows__CDevices__CPrinters__CIppResolution* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIIterable_1_Windows__CDevices__CPrinters__CIppResolution* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* First)(__FIIterable_1_Windows__CDevices__CPrinters__CIppResolution* This,
        __FIIterator_1_Windows__CDevices__CPrinters__CIppResolution** result);

    END_INTERFACE
} __FIIterable_1_Windows__CDevices__CPrinters__CIppResolutionVtbl;

interface __FIIterable_1_Windows__CDevices__CPrinters__CIppResolution
{
    CONST_VTBL struct __FIIterable_1_Windows__CDevices__CPrinters__CIppResolutionVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIIterable_1_Windows__CDevices__CPrinters__CIppResolution_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIIterable_1_Windows__CDevices__CPrinters__CIppResolution_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIIterable_1_Windows__CDevices__CPrinters__CIppResolution_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIIterable_1_Windows__CDevices__CPrinters__CIppResolution_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIIterable_1_Windows__CDevices__CPrinters__CIppResolution_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIIterable_1_Windows__CDevices__CPrinters__CIppResolution_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIIterable_1_Windows__CDevices__CPrinters__CIppResolution_First(This, result) \
    ((This)->lpVtbl->First(This, result))

#endif /* COBJMACROS */

#endif // ____FIIterable_1_Windows__CDevices__CPrinters__CIppResolution_INTERFACE_DEFINED__
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____FIIterator_1_Windows__CDevices__CPrinters__CIppTextWithLanguage_INTERFACE_DEFINED__)
#define ____FIIterator_1_Windows__CDevices__CPrinters__CIppTextWithLanguage_INTERFACE_DEFINED__

typedef interface __FIIterator_1_Windows__CDevices__CPrinters__CIppTextWithLanguage __FIIterator_1_Windows__CDevices__CPrinters__CIppTextWithLanguage;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterator_1_Windows__CDevices__CPrinters__CIppTextWithLanguage;

typedef struct __FIIterator_1_Windows__CDevices__CPrinters__CIppTextWithLanguageVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIIterator_1_Windows__CDevices__CPrinters__CIppTextWithLanguage* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIIterator_1_Windows__CDevices__CPrinters__CIppTextWithLanguage* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIIterator_1_Windows__CDevices__CPrinters__CIppTextWithLanguage* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIIterator_1_Windows__CDevices__CPrinters__CIppTextWithLanguage* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIIterator_1_Windows__CDevices__CPrinters__CIppTextWithLanguage* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIIterator_1_Windows__CDevices__CPrinters__CIppTextWithLanguage* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Current)(__FIIterator_1_Windows__CDevices__CPrinters__CIppTextWithLanguage* This,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguage** result);
    HRESULT (STDMETHODCALLTYPE* get_HasCurrent)(__FIIterator_1_Windows__CDevices__CPrinters__CIppTextWithLanguage* This,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* MoveNext)(__FIIterator_1_Windows__CDevices__CPrinters__CIppTextWithLanguage* This,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* GetMany)(__FIIterator_1_Windows__CDevices__CPrinters__CIppTextWithLanguage* This,
        UINT32 itemsLength,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguage** items,
        UINT32* result);

    END_INTERFACE
} __FIIterator_1_Windows__CDevices__CPrinters__CIppTextWithLanguageVtbl;

interface __FIIterator_1_Windows__CDevices__CPrinters__CIppTextWithLanguage
{
    CONST_VTBL struct __FIIterator_1_Windows__CDevices__CPrinters__CIppTextWithLanguageVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIIterator_1_Windows__CDevices__CPrinters__CIppTextWithLanguage_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIIterator_1_Windows__CDevices__CPrinters__CIppTextWithLanguage_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIIterator_1_Windows__CDevices__CPrinters__CIppTextWithLanguage_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIIterator_1_Windows__CDevices__CPrinters__CIppTextWithLanguage_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIIterator_1_Windows__CDevices__CPrinters__CIppTextWithLanguage_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIIterator_1_Windows__CDevices__CPrinters__CIppTextWithLanguage_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIIterator_1_Windows__CDevices__CPrinters__CIppTextWithLanguage_get_Current(This, result) \
    ((This)->lpVtbl->get_Current(This, result))

#define __FIIterator_1_Windows__CDevices__CPrinters__CIppTextWithLanguage_get_HasCurrent(This, result) \
    ((This)->lpVtbl->get_HasCurrent(This, result))

#define __FIIterator_1_Windows__CDevices__CPrinters__CIppTextWithLanguage_MoveNext(This, result) \
    ((This)->lpVtbl->MoveNext(This, result))

#define __FIIterator_1_Windows__CDevices__CPrinters__CIppTextWithLanguage_GetMany(This, itemsLength, items, result) \
    ((This)->lpVtbl->GetMany(This, itemsLength, items, result))

#endif /* COBJMACROS */

#endif // ____FIIterator_1_Windows__CDevices__CPrinters__CIppTextWithLanguage_INTERFACE_DEFINED__
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____FIIterable_1_Windows__CDevices__CPrinters__CIppTextWithLanguage_INTERFACE_DEFINED__)
#define ____FIIterable_1_Windows__CDevices__CPrinters__CIppTextWithLanguage_INTERFACE_DEFINED__

typedef interface __FIIterable_1_Windows__CDevices__CPrinters__CIppTextWithLanguage __FIIterable_1_Windows__CDevices__CPrinters__CIppTextWithLanguage;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterable_1_Windows__CDevices__CPrinters__CIppTextWithLanguage;

typedef struct __FIIterable_1_Windows__CDevices__CPrinters__CIppTextWithLanguageVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIIterable_1_Windows__CDevices__CPrinters__CIppTextWithLanguage* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIIterable_1_Windows__CDevices__CPrinters__CIppTextWithLanguage* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIIterable_1_Windows__CDevices__CPrinters__CIppTextWithLanguage* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIIterable_1_Windows__CDevices__CPrinters__CIppTextWithLanguage* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIIterable_1_Windows__CDevices__CPrinters__CIppTextWithLanguage* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIIterable_1_Windows__CDevices__CPrinters__CIppTextWithLanguage* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* First)(__FIIterable_1_Windows__CDevices__CPrinters__CIppTextWithLanguage* This,
        __FIIterator_1_Windows__CDevices__CPrinters__CIppTextWithLanguage** result);

    END_INTERFACE
} __FIIterable_1_Windows__CDevices__CPrinters__CIppTextWithLanguageVtbl;

interface __FIIterable_1_Windows__CDevices__CPrinters__CIppTextWithLanguage
{
    CONST_VTBL struct __FIIterable_1_Windows__CDevices__CPrinters__CIppTextWithLanguageVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIIterable_1_Windows__CDevices__CPrinters__CIppTextWithLanguage_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIIterable_1_Windows__CDevices__CPrinters__CIppTextWithLanguage_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIIterable_1_Windows__CDevices__CPrinters__CIppTextWithLanguage_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIIterable_1_Windows__CDevices__CPrinters__CIppTextWithLanguage_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIIterable_1_Windows__CDevices__CPrinters__CIppTextWithLanguage_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIIterable_1_Windows__CDevices__CPrinters__CIppTextWithLanguage_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIIterable_1_Windows__CDevices__CPrinters__CIppTextWithLanguage_First(This, result) \
    ((This)->lpVtbl->First(This, result))

#endif /* COBJMACROS */

#endif // ____FIIterable_1_Windows__CDevices__CPrinters__CIppTextWithLanguage_INTERFACE_DEFINED__
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_INTERFACE_DEFINED__)
#define ____FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_INTERFACE_DEFINED__

typedef interface __FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue __FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue;

typedef struct __FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValueVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Key)(__FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        HSTRING* result);
    HRESULT (STDMETHODCALLTYPE* get_Value)(__FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue** result);

    END_INTERFACE
} __FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValueVtbl;

interface __FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue
{
    CONST_VTBL struct __FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValueVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_get_Key(This, result) \
    ((This)->lpVtbl->get_Key(This, result))

#define __FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_get_Value(This, result) \
    ((This)->lpVtbl->get_Value(This, result))

#endif /* COBJMACROS */

#endif // ____FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_INTERFACE_DEFINED__
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____FIIterator_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_INTERFACE_DEFINED__)
#define ____FIIterator_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_INTERFACE_DEFINED__

typedef interface __FIIterator_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue __FIIterator_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterator_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue;

typedef struct __FIIterator_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValueVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIIterator_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIIterator_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIIterator_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIIterator_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIIterator_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIIterator_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Current)(__FIIterator_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        __FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue** result);
    HRESULT (STDMETHODCALLTYPE* get_HasCurrent)(__FIIterator_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* MoveNext)(__FIIterator_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* GetMany)(__FIIterator_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        UINT32 itemsLength,
        __FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue** items,
        UINT32* result);

    END_INTERFACE
} __FIIterator_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValueVtbl;

interface __FIIterator_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue
{
    CONST_VTBL struct __FIIterator_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValueVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIIterator_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIIterator_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIIterator_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIIterator_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIIterator_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIIterator_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIIterator_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_get_Current(This, result) \
    ((This)->lpVtbl->get_Current(This, result))

#define __FIIterator_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_get_HasCurrent(This, result) \
    ((This)->lpVtbl->get_HasCurrent(This, result))

#define __FIIterator_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_MoveNext(This, result) \
    ((This)->lpVtbl->MoveNext(This, result))

#define __FIIterator_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_GetMany(This, itemsLength, items, result) \
    ((This)->lpVtbl->GetMany(This, itemsLength, items, result))

#endif /* COBJMACROS */

#endif // ____FIIterator_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_INTERFACE_DEFINED__
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_INTERFACE_DEFINED__)
#define ____FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_INTERFACE_DEFINED__

typedef interface __FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue __FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue;

typedef struct __FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValueVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* First)(__FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        __FIIterator_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue** result);

    END_INTERFACE
} __FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValueVtbl;

interface __FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue
{
    CONST_VTBL struct __FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValueVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_First(This, result) \
    ((This)->lpVtbl->First(This, result))

#endif /* COBJMACROS */

#endif // ____FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_INTERFACE_DEFINED__
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____FIIterator_1___FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_INTERFACE_DEFINED__)
#define ____FIIterator_1___FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_INTERFACE_DEFINED__

typedef interface __FIIterator_1___FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue __FIIterator_1___FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterator_1___FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue;

typedef struct __FIIterator_1___FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValueVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIIterator_1___FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIIterator_1___FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIIterator_1___FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIIterator_1___FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIIterator_1___FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIIterator_1___FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Current)(__FIIterator_1___FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        __FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue** result);
    HRESULT (STDMETHODCALLTYPE* get_HasCurrent)(__FIIterator_1___FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* MoveNext)(__FIIterator_1___FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* GetMany)(__FIIterator_1___FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        UINT32 itemsLength,
        __FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue** items,
        UINT32* result);

    END_INTERFACE
} __FIIterator_1___FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValueVtbl;

interface __FIIterator_1___FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue
{
    CONST_VTBL struct __FIIterator_1___FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValueVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIIterator_1___FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIIterator_1___FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIIterator_1___FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIIterator_1___FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIIterator_1___FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIIterator_1___FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIIterator_1___FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_get_Current(This, result) \
    ((This)->lpVtbl->get_Current(This, result))

#define __FIIterator_1___FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_get_HasCurrent(This, result) \
    ((This)->lpVtbl->get_HasCurrent(This, result))

#define __FIIterator_1___FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_MoveNext(This, result) \
    ((This)->lpVtbl->MoveNext(This, result))

#define __FIIterator_1___FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_GetMany(This, itemsLength, items, result) \
    ((This)->lpVtbl->GetMany(This, itemsLength, items, result))

#endif /* COBJMACROS */

#endif // ____FIIterator_1___FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_INTERFACE_DEFINED__
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____FIIterable_1___FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_INTERFACE_DEFINED__)
#define ____FIIterable_1___FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_INTERFACE_DEFINED__

typedef interface __FIIterable_1___FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue __FIIterable_1___FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterable_1___FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue;

typedef struct __FIIterable_1___FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValueVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIIterable_1___FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIIterable_1___FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIIterable_1___FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIIterable_1___FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIIterable_1___FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIIterable_1___FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* First)(__FIIterable_1___FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        __FIIterator_1___FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue** result);

    END_INTERFACE
} __FIIterable_1___FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValueVtbl;

interface __FIIterable_1___FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue
{
    CONST_VTBL struct __FIIterable_1___FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValueVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIIterable_1___FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIIterable_1___FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIIterable_1___FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIIterable_1___FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIIterable_1___FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIIterable_1___FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIIterable_1___FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_First(This, result) \
    ((This)->lpVtbl->First(This, result))

#endif /* COBJMACROS */

#endif // ____FIIterable_1___FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_INTERFACE_DEFINED__
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError_INTERFACE_DEFINED__)
#define ____FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError_INTERFACE_DEFINED__

typedef interface __FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError __FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError;

typedef struct __FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeErrorVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Key)(__FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError* This,
        HSTRING* result);
    HRESULT (STDMETHODCALLTYPE* get_Value)(__FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError* This,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeError** result);

    END_INTERFACE
} __FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeErrorVtbl;

interface __FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError
{
    CONST_VTBL struct __FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeErrorVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError_get_Key(This, result) \
    ((This)->lpVtbl->get_Key(This, result))

#define __FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError_get_Value(This, result) \
    ((This)->lpVtbl->get_Value(This, result))

#endif /* COBJMACROS */

#endif // ____FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError_INTERFACE_DEFINED__
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____FIIterator_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError_INTERFACE_DEFINED__)
#define ____FIIterator_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError_INTERFACE_DEFINED__

typedef interface __FIIterator_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError __FIIterator_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterator_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError;

typedef struct __FIIterator_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeErrorVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIIterator_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIIterator_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIIterator_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIIterator_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIIterator_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIIterator_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Current)(__FIIterator_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError* This,
        __FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError** result);
    HRESULT (STDMETHODCALLTYPE* get_HasCurrent)(__FIIterator_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError* This,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* MoveNext)(__FIIterator_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError* This,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* GetMany)(__FIIterator_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError* This,
        UINT32 itemsLength,
        __FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError** items,
        UINT32* result);

    END_INTERFACE
} __FIIterator_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeErrorVtbl;

interface __FIIterator_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError
{
    CONST_VTBL struct __FIIterator_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeErrorVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIIterator_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIIterator_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIIterator_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIIterator_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIIterator_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIIterator_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIIterator_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError_get_Current(This, result) \
    ((This)->lpVtbl->get_Current(This, result))

#define __FIIterator_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError_get_HasCurrent(This, result) \
    ((This)->lpVtbl->get_HasCurrent(This, result))

#define __FIIterator_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError_MoveNext(This, result) \
    ((This)->lpVtbl->MoveNext(This, result))

#define __FIIterator_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError_GetMany(This, itemsLength, items, result) \
    ((This)->lpVtbl->GetMany(This, itemsLength, items, result))

#endif /* COBJMACROS */

#endif // ____FIIterator_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError_INTERFACE_DEFINED__
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError_INTERFACE_DEFINED__)
#define ____FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError_INTERFACE_DEFINED__

typedef interface __FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError __FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError;

typedef struct __FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeErrorVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* First)(__FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError* This,
        __FIIterator_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError** result);

    END_INTERFACE
} __FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeErrorVtbl;

interface __FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError
{
    CONST_VTBL struct __FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeErrorVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError_First(This, result) \
    ((This)->lpVtbl->First(This, result))

#endif /* COBJMACROS */

#endif // ____FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError_INTERFACE_DEFINED__
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

typedef interface __FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue __FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue;

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_INTERFACE_DEFINED__)
#define ____FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_INTERFACE_DEFINED__

typedef interface __FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue __FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue;

typedef struct __FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValueVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* Lookup)(__FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        HSTRING key,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue** result);
    HRESULT (STDMETHODCALLTYPE* get_Size)(__FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        UINT32* result);
    HRESULT (STDMETHODCALLTYPE* HasKey)(__FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        HSTRING key,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* Split)(__FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        __FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue** first,
        __FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue** second);

    END_INTERFACE
} __FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValueVtbl;

interface __FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue
{
    CONST_VTBL struct __FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValueVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_Lookup(This, key, result) \
    ((This)->lpVtbl->Lookup(This, key, result))

#define __FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_get_Size(This, result) \
    ((This)->lpVtbl->get_Size(This, result))

#define __FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_HasKey(This, key, result) \
    ((This)->lpVtbl->HasKey(This, key, result))

#define __FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_Split(This, first, second) \
    ((This)->lpVtbl->Split(This, first, second))

#endif /* COBJMACROS */

#endif // ____FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_INTERFACE_DEFINED__
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____FIIterator_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_INTERFACE_DEFINED__)
#define ____FIIterator_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_INTERFACE_DEFINED__

typedef interface __FIIterator_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue __FIIterator_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterator_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue;

typedef struct __FIIterator_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValueVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIIterator_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIIterator_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIIterator_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIIterator_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIIterator_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIIterator_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Current)(__FIIterator_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        __FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue** result);
    HRESULT (STDMETHODCALLTYPE* get_HasCurrent)(__FIIterator_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* MoveNext)(__FIIterator_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* GetMany)(__FIIterator_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        UINT32 itemsLength,
        __FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue** items,
        UINT32* result);

    END_INTERFACE
} __FIIterator_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValueVtbl;

interface __FIIterator_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue
{
    CONST_VTBL struct __FIIterator_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValueVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIIterator_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIIterator_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIIterator_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIIterator_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIIterator_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIIterator_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIIterator_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_get_Current(This, result) \
    ((This)->lpVtbl->get_Current(This, result))

#define __FIIterator_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_get_HasCurrent(This, result) \
    ((This)->lpVtbl->get_HasCurrent(This, result))

#define __FIIterator_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_MoveNext(This, result) \
    ((This)->lpVtbl->MoveNext(This, result))

#define __FIIterator_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_GetMany(This, itemsLength, items, result) \
    ((This)->lpVtbl->GetMany(This, itemsLength, items, result))

#endif /* COBJMACROS */

#endif // ____FIIterator_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_INTERFACE_DEFINED__
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____FIIterable_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_INTERFACE_DEFINED__)
#define ____FIIterable_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_INTERFACE_DEFINED__

typedef interface __FIIterable_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue __FIIterable_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterable_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue;

typedef struct __FIIterable_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValueVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIIterable_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIIterable_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIIterable_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIIterable_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIIterable_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIIterable_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* First)(__FIIterable_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        __FIIterator_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue** result);

    END_INTERFACE
} __FIIterable_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValueVtbl;

interface __FIIterable_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue
{
    CONST_VTBL struct __FIIterable_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValueVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIIterable_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIIterable_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIIterable_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIIterable_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIIterable_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIIterable_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIIterable_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_First(This, result) \
    ((This)->lpVtbl->First(This, result))

#endif /* COBJMACROS */

#endif // ____FIIterable_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_INTERFACE_DEFINED__
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

typedef struct __x_ABI_CWindows_CFoundation_CDateTime __x_ABI_CWindows_CFoundation_CDateTime;

#if WINDOWS_FOUNDATION_FOUNDATIONCONTRACT_VERSION >= 0x10000
#if !defined(____FIIterator_1_Windows__CFoundation__CDateTime_INTERFACE_DEFINED__)
#define ____FIIterator_1_Windows__CFoundation__CDateTime_INTERFACE_DEFINED__

typedef interface __FIIterator_1_Windows__CFoundation__CDateTime __FIIterator_1_Windows__CFoundation__CDateTime;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterator_1_Windows__CFoundation__CDateTime;

typedef struct __FIIterator_1_Windows__CFoundation__CDateTimeVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIIterator_1_Windows__CFoundation__CDateTime* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIIterator_1_Windows__CFoundation__CDateTime* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIIterator_1_Windows__CFoundation__CDateTime* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIIterator_1_Windows__CFoundation__CDateTime* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIIterator_1_Windows__CFoundation__CDateTime* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIIterator_1_Windows__CFoundation__CDateTime* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Current)(__FIIterator_1_Windows__CFoundation__CDateTime* This,
        struct __x_ABI_CWindows_CFoundation_CDateTime* result);
    HRESULT (STDMETHODCALLTYPE* get_HasCurrent)(__FIIterator_1_Windows__CFoundation__CDateTime* This,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* MoveNext)(__FIIterator_1_Windows__CFoundation__CDateTime* This,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* GetMany)(__FIIterator_1_Windows__CFoundation__CDateTime* This,
        UINT32 itemsLength,
        struct __x_ABI_CWindows_CFoundation_CDateTime* items,
        UINT32* result);

    END_INTERFACE
} __FIIterator_1_Windows__CFoundation__CDateTimeVtbl;

interface __FIIterator_1_Windows__CFoundation__CDateTime
{
    CONST_VTBL struct __FIIterator_1_Windows__CFoundation__CDateTimeVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIIterator_1_Windows__CFoundation__CDateTime_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIIterator_1_Windows__CFoundation__CDateTime_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIIterator_1_Windows__CFoundation__CDateTime_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIIterator_1_Windows__CFoundation__CDateTime_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIIterator_1_Windows__CFoundation__CDateTime_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIIterator_1_Windows__CFoundation__CDateTime_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIIterator_1_Windows__CFoundation__CDateTime_get_Current(This, result) \
    ((This)->lpVtbl->get_Current(This, result))

#define __FIIterator_1_Windows__CFoundation__CDateTime_get_HasCurrent(This, result) \
    ((This)->lpVtbl->get_HasCurrent(This, result))

#define __FIIterator_1_Windows__CFoundation__CDateTime_MoveNext(This, result) \
    ((This)->lpVtbl->MoveNext(This, result))

#define __FIIterator_1_Windows__CFoundation__CDateTime_GetMany(This, itemsLength, items, result) \
    ((This)->lpVtbl->GetMany(This, itemsLength, items, result))

#endif /* COBJMACROS */

#endif // ____FIIterator_1_Windows__CFoundation__CDateTime_INTERFACE_DEFINED__
#endif // WINDOWS_FOUNDATION_FOUNDATIONCONTRACT_VERSION >= 0x10000

#if WINDOWS_FOUNDATION_FOUNDATIONCONTRACT_VERSION >= 0x10000
#if !defined(____FIIterable_1_Windows__CFoundation__CDateTime_INTERFACE_DEFINED__)
#define ____FIIterable_1_Windows__CFoundation__CDateTime_INTERFACE_DEFINED__

typedef interface __FIIterable_1_Windows__CFoundation__CDateTime __FIIterable_1_Windows__CFoundation__CDateTime;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterable_1_Windows__CFoundation__CDateTime;

typedef struct __FIIterable_1_Windows__CFoundation__CDateTimeVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIIterable_1_Windows__CFoundation__CDateTime* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIIterable_1_Windows__CFoundation__CDateTime* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIIterable_1_Windows__CFoundation__CDateTime* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIIterable_1_Windows__CFoundation__CDateTime* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIIterable_1_Windows__CFoundation__CDateTime* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIIterable_1_Windows__CFoundation__CDateTime* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* First)(__FIIterable_1_Windows__CFoundation__CDateTime* This,
        __FIIterator_1_Windows__CFoundation__CDateTime** result);

    END_INTERFACE
} __FIIterable_1_Windows__CFoundation__CDateTimeVtbl;

interface __FIIterable_1_Windows__CFoundation__CDateTime
{
    CONST_VTBL struct __FIIterable_1_Windows__CFoundation__CDateTimeVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIIterable_1_Windows__CFoundation__CDateTime_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIIterable_1_Windows__CFoundation__CDateTime_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIIterable_1_Windows__CFoundation__CDateTime_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIIterable_1_Windows__CFoundation__CDateTime_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIIterable_1_Windows__CFoundation__CDateTime_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIIterable_1_Windows__CFoundation__CDateTime_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIIterable_1_Windows__CFoundation__CDateTime_First(This, result) \
    ((This)->lpVtbl->First(This, result))

#endif /* COBJMACROS */

#endif // ____FIIterable_1_Windows__CFoundation__CDateTime_INTERFACE_DEFINED__
#endif // WINDOWS_FOUNDATION_FOUNDATIONCONTRACT_VERSION >= 0x10000

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

#ifndef ____x_ABI_CWindows_CStorage_CStreams_CIBuffer_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CStreams_CIBuffer_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CStorage_CStreams_CIBuffer __x_ABI_CWindows_CStorage_CStreams_CIBuffer;

#endif // ____x_ABI_CWindows_CStorage_CStreams_CIBuffer_FWD_DEFINED__

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if !defined(____FIIterator_1_Windows__CStorage__CStreams__CIBuffer_INTERFACE_DEFINED__)
#define ____FIIterator_1_Windows__CStorage__CStreams__CIBuffer_INTERFACE_DEFINED__

typedef interface __FIIterator_1_Windows__CStorage__CStreams__CIBuffer __FIIterator_1_Windows__CStorage__CStreams__CIBuffer;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterator_1_Windows__CStorage__CStreams__CIBuffer;

typedef struct __FIIterator_1_Windows__CStorage__CStreams__CIBufferVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIIterator_1_Windows__CStorage__CStreams__CIBuffer* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIIterator_1_Windows__CStorage__CStreams__CIBuffer* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIIterator_1_Windows__CStorage__CStreams__CIBuffer* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIIterator_1_Windows__CStorage__CStreams__CIBuffer* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIIterator_1_Windows__CStorage__CStreams__CIBuffer* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIIterator_1_Windows__CStorage__CStreams__CIBuffer* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Current)(__FIIterator_1_Windows__CStorage__CStreams__CIBuffer* This,
        __x_ABI_CWindows_CStorage_CStreams_CIBuffer** result);
    HRESULT (STDMETHODCALLTYPE* get_HasCurrent)(__FIIterator_1_Windows__CStorage__CStreams__CIBuffer* This,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* MoveNext)(__FIIterator_1_Windows__CStorage__CStreams__CIBuffer* This,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* GetMany)(__FIIterator_1_Windows__CStorage__CStreams__CIBuffer* This,
        UINT32 itemsLength,
        __x_ABI_CWindows_CStorage_CStreams_CIBuffer** items,
        UINT32* result);

    END_INTERFACE
} __FIIterator_1_Windows__CStorage__CStreams__CIBufferVtbl;

interface __FIIterator_1_Windows__CStorage__CStreams__CIBuffer
{
    CONST_VTBL struct __FIIterator_1_Windows__CStorage__CStreams__CIBufferVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIIterator_1_Windows__CStorage__CStreams__CIBuffer_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIIterator_1_Windows__CStorage__CStreams__CIBuffer_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIIterator_1_Windows__CStorage__CStreams__CIBuffer_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIIterator_1_Windows__CStorage__CStreams__CIBuffer_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIIterator_1_Windows__CStorage__CStreams__CIBuffer_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIIterator_1_Windows__CStorage__CStreams__CIBuffer_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIIterator_1_Windows__CStorage__CStreams__CIBuffer_get_Current(This, result) \
    ((This)->lpVtbl->get_Current(This, result))

#define __FIIterator_1_Windows__CStorage__CStreams__CIBuffer_get_HasCurrent(This, result) \
    ((This)->lpVtbl->get_HasCurrent(This, result))

#define __FIIterator_1_Windows__CStorage__CStreams__CIBuffer_MoveNext(This, result) \
    ((This)->lpVtbl->MoveNext(This, result))

#define __FIIterator_1_Windows__CStorage__CStreams__CIBuffer_GetMany(This, itemsLength, items, result) \
    ((This)->lpVtbl->GetMany(This, itemsLength, items, result))

#endif /* COBJMACROS */

#endif // ____FIIterator_1_Windows__CStorage__CStreams__CIBuffer_INTERFACE_DEFINED__
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if !defined(____FIIterable_1_Windows__CStorage__CStreams__CIBuffer_INTERFACE_DEFINED__)
#define ____FIIterable_1_Windows__CStorage__CStreams__CIBuffer_INTERFACE_DEFINED__

typedef interface __FIIterable_1_Windows__CStorage__CStreams__CIBuffer __FIIterable_1_Windows__CStorage__CStreams__CIBuffer;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterable_1_Windows__CStorage__CStreams__CIBuffer;

typedef struct __FIIterable_1_Windows__CStorage__CStreams__CIBufferVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIIterable_1_Windows__CStorage__CStreams__CIBuffer* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIIterable_1_Windows__CStorage__CStreams__CIBuffer* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIIterable_1_Windows__CStorage__CStreams__CIBuffer* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIIterable_1_Windows__CStorage__CStreams__CIBuffer* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIIterable_1_Windows__CStorage__CStreams__CIBuffer* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIIterable_1_Windows__CStorage__CStreams__CIBuffer* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* First)(__FIIterable_1_Windows__CStorage__CStreams__CIBuffer* This,
        __FIIterator_1_Windows__CStorage__CStreams__CIBuffer** result);

    END_INTERFACE
} __FIIterable_1_Windows__CStorage__CStreams__CIBufferVtbl;

interface __FIIterable_1_Windows__CStorage__CStreams__CIBuffer
{
    CONST_VTBL struct __FIIterable_1_Windows__CStorage__CStreams__CIBufferVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIIterable_1_Windows__CStorage__CStreams__CIBuffer_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIIterable_1_Windows__CStorage__CStreams__CIBuffer_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIIterable_1_Windows__CStorage__CStreams__CIBuffer_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIIterable_1_Windows__CStorage__CStreams__CIBuffer_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIIterable_1_Windows__CStorage__CStreams__CIBuffer_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIIterable_1_Windows__CStorage__CStreams__CIBuffer_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIIterable_1_Windows__CStorage__CStreams__CIBuffer_First(This, result) \
    ((This)->lpVtbl->First(This, result))

#endif /* COBJMACROS */

#endif // ____FIIterable_1_Windows__CStorage__CStreams__CIBuffer_INTERFACE_DEFINED__
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

typedef interface __FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError __FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError;

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError_INTERFACE_DEFINED__)
#define ____FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError_INTERFACE_DEFINED__

typedef interface __FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError __FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError;

typedef struct __FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeErrorVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* Lookup)(__FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError* This,
        HSTRING key,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeError** result);
    HRESULT (STDMETHODCALLTYPE* get_Size)(__FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError* This,
        UINT32* result);
    HRESULT (STDMETHODCALLTYPE* HasKey)(__FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError* This,
        HSTRING key,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* Split)(__FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError* This,
        __FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError** first,
        __FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError** second);

    END_INTERFACE
} __FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeErrorVtbl;

interface __FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError
{
    CONST_VTBL struct __FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeErrorVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError_Lookup(This, key, result) \
    ((This)->lpVtbl->Lookup(This, key, result))

#define __FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError_get_Size(This, result) \
    ((This)->lpVtbl->get_Size(This, result))

#define __FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError_HasKey(This, key, result) \
    ((This)->lpVtbl->HasKey(This, key, result))

#define __FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError_Split(This, first, second) \
    ((This)->lpVtbl->Split(This, first, second))

#endif /* COBJMACROS */

#endif // ____FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError_INTERFACE_DEFINED__
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____FIMap_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_INTERFACE_DEFINED__)
#define ____FIMap_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_INTERFACE_DEFINED__

typedef interface __FIMap_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue __FIMap_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIMap_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue;

typedef struct __FIMap_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValueVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIMap_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIMap_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIMap_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIMap_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIMap_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIMap_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* Lookup)(__FIMap_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        HSTRING key,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue** result);
    HRESULT (STDMETHODCALLTYPE* get_Size)(__FIMap_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        UINT32* result);
    HRESULT (STDMETHODCALLTYPE* HasKey)(__FIMap_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        HSTRING key,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* GetView)(__FIMap_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        __FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue** result);
    HRESULT (STDMETHODCALLTYPE* Insert)(__FIMap_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        HSTRING key,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue* value,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* Remove)(__FIMap_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        HSTRING key);
    HRESULT (STDMETHODCALLTYPE* Clear)(__FIMap_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This);

    END_INTERFACE
} __FIMap_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValueVtbl;

interface __FIMap_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue
{
    CONST_VTBL struct __FIMap_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValueVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIMap_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIMap_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIMap_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIMap_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIMap_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIMap_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIMap_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_Lookup(This, key, result) \
    ((This)->lpVtbl->Lookup(This, key, result))

#define __FIMap_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_get_Size(This, result) \
    ((This)->lpVtbl->get_Size(This, result))

#define __FIMap_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_HasKey(This, key, result) \
    ((This)->lpVtbl->HasKey(This, key, result))

#define __FIMap_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_GetView(This, result) \
    ((This)->lpVtbl->GetView(This, result))

#define __FIMap_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_Insert(This, key, value, result) \
    ((This)->lpVtbl->Insert(This, key, value, result))

#define __FIMap_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_Remove(This, key) \
    ((This)->lpVtbl->Remove(This, key))

#define __FIMap_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_Clear(This) \
    ((This)->lpVtbl->Clear(This))

#endif /* COBJMACROS */

#endif // ____FIMap_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_INTERFACE_DEFINED__
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#if !defined(____FIVectorView_1_boolean_INTERFACE_DEFINED__)
#define ____FIVectorView_1_boolean_INTERFACE_DEFINED__

typedef interface __FIVectorView_1_boolean __FIVectorView_1_boolean;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIVectorView_1_boolean;

typedef struct __FIVectorView_1_booleanVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIVectorView_1_boolean* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIVectorView_1_boolean* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIVectorView_1_boolean* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIVectorView_1_boolean* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIVectorView_1_boolean* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIVectorView_1_boolean* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* GetAt)(__FIVectorView_1_boolean* This,
        UINT32 index,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* get_Size)(__FIVectorView_1_boolean* This,
        UINT32* result);
    HRESULT (STDMETHODCALLTYPE* IndexOf)(__FIVectorView_1_boolean* This,
        boolean value,
        UINT32* index,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* GetMany)(__FIVectorView_1_boolean* This,
        UINT32 startIndex,
        UINT32 itemsLength,
        boolean* items,
        UINT32* result);

    END_INTERFACE
} __FIVectorView_1_booleanVtbl;

interface __FIVectorView_1_boolean
{
    CONST_VTBL struct __FIVectorView_1_booleanVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIVectorView_1_boolean_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIVectorView_1_boolean_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIVectorView_1_boolean_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIVectorView_1_boolean_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIVectorView_1_boolean_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIVectorView_1_boolean_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIVectorView_1_boolean_GetAt(This, index, result) \
    ((This)->lpVtbl->GetAt(This, index, result))

#define __FIVectorView_1_boolean_get_Size(This, result) \
    ((This)->lpVtbl->get_Size(This, result))

#define __FIVectorView_1_boolean_IndexOf(This, value, index, result) \
    ((This)->lpVtbl->IndexOf(This, value, index, result))

#define __FIVectorView_1_boolean_GetMany(This, startIndex, itemsLength, items, result) \
    ((This)->lpVtbl->GetMany(This, startIndex, itemsLength, items, result))

#endif /* COBJMACROS */

#endif // ____FIVectorView_1_boolean_INTERFACE_DEFINED__

#if !defined(____FIVectorView_1_int_INTERFACE_DEFINED__)
#define ____FIVectorView_1_int_INTERFACE_DEFINED__

typedef interface __FIVectorView_1_int __FIVectorView_1_int;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIVectorView_1_int;

typedef struct __FIVectorView_1_intVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIVectorView_1_int* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIVectorView_1_int* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIVectorView_1_int* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIVectorView_1_int* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIVectorView_1_int* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIVectorView_1_int* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* GetAt)(__FIVectorView_1_int* This,
        UINT32 index,
        INT32* result);
    HRESULT (STDMETHODCALLTYPE* get_Size)(__FIVectorView_1_int* This,
        UINT32* result);
    HRESULT (STDMETHODCALLTYPE* IndexOf)(__FIVectorView_1_int* This,
        INT32 value,
        UINT32* index,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* GetMany)(__FIVectorView_1_int* This,
        UINT32 startIndex,
        UINT32 itemsLength,
        INT32* items,
        UINT32* result);

    END_INTERFACE
} __FIVectorView_1_intVtbl;

interface __FIVectorView_1_int
{
    CONST_VTBL struct __FIVectorView_1_intVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIVectorView_1_int_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIVectorView_1_int_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIVectorView_1_int_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIVectorView_1_int_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIVectorView_1_int_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIVectorView_1_int_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIVectorView_1_int_GetAt(This, index, result) \
    ((This)->lpVtbl->GetAt(This, index, result))

#define __FIVectorView_1_int_get_Size(This, result) \
    ((This)->lpVtbl->get_Size(This, result))

#define __FIVectorView_1_int_IndexOf(This, value, index, result) \
    ((This)->lpVtbl->IndexOf(This, value, index, result))

#define __FIVectorView_1_int_GetMany(This, startIndex, itemsLength, items, result) \
    ((This)->lpVtbl->GetMany(This, startIndex, itemsLength, items, result))

#endif /* COBJMACROS */

#endif // ____FIVectorView_1_int_INTERFACE_DEFINED__

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

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____FIVectorView_1_Windows__CDevices__CPrinters__CIppAttributeValue_INTERFACE_DEFINED__)
#define ____FIVectorView_1_Windows__CDevices__CPrinters__CIppAttributeValue_INTERFACE_DEFINED__

typedef interface __FIVectorView_1_Windows__CDevices__CPrinters__CIppAttributeValue __FIVectorView_1_Windows__CDevices__CPrinters__CIppAttributeValue;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIVectorView_1_Windows__CDevices__CPrinters__CIppAttributeValue;

typedef struct __FIVectorView_1_Windows__CDevices__CPrinters__CIppAttributeValueVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIVectorView_1_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIVectorView_1_Windows__CDevices__CPrinters__CIppAttributeValue* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIVectorView_1_Windows__CDevices__CPrinters__CIppAttributeValue* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIVectorView_1_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIVectorView_1_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIVectorView_1_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* GetAt)(__FIVectorView_1_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        UINT32 index,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue** result);
    HRESULT (STDMETHODCALLTYPE* get_Size)(__FIVectorView_1_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        UINT32* result);
    HRESULT (STDMETHODCALLTYPE* IndexOf)(__FIVectorView_1_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue* value,
        UINT32* index,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* GetMany)(__FIVectorView_1_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        UINT32 startIndex,
        UINT32 itemsLength,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue** items,
        UINT32* result);

    END_INTERFACE
} __FIVectorView_1_Windows__CDevices__CPrinters__CIppAttributeValueVtbl;

interface __FIVectorView_1_Windows__CDevices__CPrinters__CIppAttributeValue
{
    CONST_VTBL struct __FIVectorView_1_Windows__CDevices__CPrinters__CIppAttributeValueVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIVectorView_1_Windows__CDevices__CPrinters__CIppAttributeValue_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIVectorView_1_Windows__CDevices__CPrinters__CIppAttributeValue_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIVectorView_1_Windows__CDevices__CPrinters__CIppAttributeValue_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIVectorView_1_Windows__CDevices__CPrinters__CIppAttributeValue_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIVectorView_1_Windows__CDevices__CPrinters__CIppAttributeValue_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIVectorView_1_Windows__CDevices__CPrinters__CIppAttributeValue_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIVectorView_1_Windows__CDevices__CPrinters__CIppAttributeValue_GetAt(This, index, result) \
    ((This)->lpVtbl->GetAt(This, index, result))

#define __FIVectorView_1_Windows__CDevices__CPrinters__CIppAttributeValue_get_Size(This, result) \
    ((This)->lpVtbl->get_Size(This, result))

#define __FIVectorView_1_Windows__CDevices__CPrinters__CIppAttributeValue_IndexOf(This, value, index, result) \
    ((This)->lpVtbl->IndexOf(This, value, index, result))

#define __FIVectorView_1_Windows__CDevices__CPrinters__CIppAttributeValue_GetMany(This, startIndex, itemsLength, items, result) \
    ((This)->lpVtbl->GetMany(This, startIndex, itemsLength, items, result))

#endif /* COBJMACROS */

#endif // ____FIVectorView_1_Windows__CDevices__CPrinters__CIppAttributeValue_INTERFACE_DEFINED__
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____FIVectorView_1_Windows__CDevices__CPrinters__CIppIntegerRange_INTERFACE_DEFINED__)
#define ____FIVectorView_1_Windows__CDevices__CPrinters__CIppIntegerRange_INTERFACE_DEFINED__

typedef interface __FIVectorView_1_Windows__CDevices__CPrinters__CIppIntegerRange __FIVectorView_1_Windows__CDevices__CPrinters__CIppIntegerRange;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIVectorView_1_Windows__CDevices__CPrinters__CIppIntegerRange;

typedef struct __FIVectorView_1_Windows__CDevices__CPrinters__CIppIntegerRangeVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIVectorView_1_Windows__CDevices__CPrinters__CIppIntegerRange* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIVectorView_1_Windows__CDevices__CPrinters__CIppIntegerRange* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIVectorView_1_Windows__CDevices__CPrinters__CIppIntegerRange* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIVectorView_1_Windows__CDevices__CPrinters__CIppIntegerRange* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIVectorView_1_Windows__CDevices__CPrinters__CIppIntegerRange* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIVectorView_1_Windows__CDevices__CPrinters__CIppIntegerRange* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* GetAt)(__FIVectorView_1_Windows__CDevices__CPrinters__CIppIntegerRange* This,
        UINT32 index,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRange** result);
    HRESULT (STDMETHODCALLTYPE* get_Size)(__FIVectorView_1_Windows__CDevices__CPrinters__CIppIntegerRange* This,
        UINT32* result);
    HRESULT (STDMETHODCALLTYPE* IndexOf)(__FIVectorView_1_Windows__CDevices__CPrinters__CIppIntegerRange* This,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRange* value,
        UINT32* index,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* GetMany)(__FIVectorView_1_Windows__CDevices__CPrinters__CIppIntegerRange* This,
        UINT32 startIndex,
        UINT32 itemsLength,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRange** items,
        UINT32* result);

    END_INTERFACE
} __FIVectorView_1_Windows__CDevices__CPrinters__CIppIntegerRangeVtbl;

interface __FIVectorView_1_Windows__CDevices__CPrinters__CIppIntegerRange
{
    CONST_VTBL struct __FIVectorView_1_Windows__CDevices__CPrinters__CIppIntegerRangeVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIVectorView_1_Windows__CDevices__CPrinters__CIppIntegerRange_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIVectorView_1_Windows__CDevices__CPrinters__CIppIntegerRange_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIVectorView_1_Windows__CDevices__CPrinters__CIppIntegerRange_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIVectorView_1_Windows__CDevices__CPrinters__CIppIntegerRange_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIVectorView_1_Windows__CDevices__CPrinters__CIppIntegerRange_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIVectorView_1_Windows__CDevices__CPrinters__CIppIntegerRange_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIVectorView_1_Windows__CDevices__CPrinters__CIppIntegerRange_GetAt(This, index, result) \
    ((This)->lpVtbl->GetAt(This, index, result))

#define __FIVectorView_1_Windows__CDevices__CPrinters__CIppIntegerRange_get_Size(This, result) \
    ((This)->lpVtbl->get_Size(This, result))

#define __FIVectorView_1_Windows__CDevices__CPrinters__CIppIntegerRange_IndexOf(This, value, index, result) \
    ((This)->lpVtbl->IndexOf(This, value, index, result))

#define __FIVectorView_1_Windows__CDevices__CPrinters__CIppIntegerRange_GetMany(This, startIndex, itemsLength, items, result) \
    ((This)->lpVtbl->GetMany(This, startIndex, itemsLength, items, result))

#endif /* COBJMACROS */

#endif // ____FIVectorView_1_Windows__CDevices__CPrinters__CIppIntegerRange_INTERFACE_DEFINED__
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____FIVectorView_1_Windows__CDevices__CPrinters__CIppResolution_INTERFACE_DEFINED__)
#define ____FIVectorView_1_Windows__CDevices__CPrinters__CIppResolution_INTERFACE_DEFINED__

typedef interface __FIVectorView_1_Windows__CDevices__CPrinters__CIppResolution __FIVectorView_1_Windows__CDevices__CPrinters__CIppResolution;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIVectorView_1_Windows__CDevices__CPrinters__CIppResolution;

typedef struct __FIVectorView_1_Windows__CDevices__CPrinters__CIppResolutionVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIVectorView_1_Windows__CDevices__CPrinters__CIppResolution* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIVectorView_1_Windows__CDevices__CPrinters__CIppResolution* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIVectorView_1_Windows__CDevices__CPrinters__CIppResolution* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIVectorView_1_Windows__CDevices__CPrinters__CIppResolution* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIVectorView_1_Windows__CDevices__CPrinters__CIppResolution* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIVectorView_1_Windows__CDevices__CPrinters__CIppResolution* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* GetAt)(__FIVectorView_1_Windows__CDevices__CPrinters__CIppResolution* This,
        UINT32 index,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppResolution** result);
    HRESULT (STDMETHODCALLTYPE* get_Size)(__FIVectorView_1_Windows__CDevices__CPrinters__CIppResolution* This,
        UINT32* result);
    HRESULT (STDMETHODCALLTYPE* IndexOf)(__FIVectorView_1_Windows__CDevices__CPrinters__CIppResolution* This,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppResolution* value,
        UINT32* index,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* GetMany)(__FIVectorView_1_Windows__CDevices__CPrinters__CIppResolution* This,
        UINT32 startIndex,
        UINT32 itemsLength,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppResolution** items,
        UINT32* result);

    END_INTERFACE
} __FIVectorView_1_Windows__CDevices__CPrinters__CIppResolutionVtbl;

interface __FIVectorView_1_Windows__CDevices__CPrinters__CIppResolution
{
    CONST_VTBL struct __FIVectorView_1_Windows__CDevices__CPrinters__CIppResolutionVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIVectorView_1_Windows__CDevices__CPrinters__CIppResolution_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIVectorView_1_Windows__CDevices__CPrinters__CIppResolution_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIVectorView_1_Windows__CDevices__CPrinters__CIppResolution_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIVectorView_1_Windows__CDevices__CPrinters__CIppResolution_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIVectorView_1_Windows__CDevices__CPrinters__CIppResolution_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIVectorView_1_Windows__CDevices__CPrinters__CIppResolution_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIVectorView_1_Windows__CDevices__CPrinters__CIppResolution_GetAt(This, index, result) \
    ((This)->lpVtbl->GetAt(This, index, result))

#define __FIVectorView_1_Windows__CDevices__CPrinters__CIppResolution_get_Size(This, result) \
    ((This)->lpVtbl->get_Size(This, result))

#define __FIVectorView_1_Windows__CDevices__CPrinters__CIppResolution_IndexOf(This, value, index, result) \
    ((This)->lpVtbl->IndexOf(This, value, index, result))

#define __FIVectorView_1_Windows__CDevices__CPrinters__CIppResolution_GetMany(This, startIndex, itemsLength, items, result) \
    ((This)->lpVtbl->GetMany(This, startIndex, itemsLength, items, result))

#endif /* COBJMACROS */

#endif // ____FIVectorView_1_Windows__CDevices__CPrinters__CIppResolution_INTERFACE_DEFINED__
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____FIVectorView_1_Windows__CDevices__CPrinters__CIppTextWithLanguage_INTERFACE_DEFINED__)
#define ____FIVectorView_1_Windows__CDevices__CPrinters__CIppTextWithLanguage_INTERFACE_DEFINED__

typedef interface __FIVectorView_1_Windows__CDevices__CPrinters__CIppTextWithLanguage __FIVectorView_1_Windows__CDevices__CPrinters__CIppTextWithLanguage;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIVectorView_1_Windows__CDevices__CPrinters__CIppTextWithLanguage;

typedef struct __FIVectorView_1_Windows__CDevices__CPrinters__CIppTextWithLanguageVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIVectorView_1_Windows__CDevices__CPrinters__CIppTextWithLanguage* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIVectorView_1_Windows__CDevices__CPrinters__CIppTextWithLanguage* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIVectorView_1_Windows__CDevices__CPrinters__CIppTextWithLanguage* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIVectorView_1_Windows__CDevices__CPrinters__CIppTextWithLanguage* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIVectorView_1_Windows__CDevices__CPrinters__CIppTextWithLanguage* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIVectorView_1_Windows__CDevices__CPrinters__CIppTextWithLanguage* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* GetAt)(__FIVectorView_1_Windows__CDevices__CPrinters__CIppTextWithLanguage* This,
        UINT32 index,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguage** result);
    HRESULT (STDMETHODCALLTYPE* get_Size)(__FIVectorView_1_Windows__CDevices__CPrinters__CIppTextWithLanguage* This,
        UINT32* result);
    HRESULT (STDMETHODCALLTYPE* IndexOf)(__FIVectorView_1_Windows__CDevices__CPrinters__CIppTextWithLanguage* This,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguage* value,
        UINT32* index,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* GetMany)(__FIVectorView_1_Windows__CDevices__CPrinters__CIppTextWithLanguage* This,
        UINT32 startIndex,
        UINT32 itemsLength,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguage** items,
        UINT32* result);

    END_INTERFACE
} __FIVectorView_1_Windows__CDevices__CPrinters__CIppTextWithLanguageVtbl;

interface __FIVectorView_1_Windows__CDevices__CPrinters__CIppTextWithLanguage
{
    CONST_VTBL struct __FIVectorView_1_Windows__CDevices__CPrinters__CIppTextWithLanguageVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIVectorView_1_Windows__CDevices__CPrinters__CIppTextWithLanguage_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIVectorView_1_Windows__CDevices__CPrinters__CIppTextWithLanguage_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIVectorView_1_Windows__CDevices__CPrinters__CIppTextWithLanguage_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIVectorView_1_Windows__CDevices__CPrinters__CIppTextWithLanguage_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIVectorView_1_Windows__CDevices__CPrinters__CIppTextWithLanguage_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIVectorView_1_Windows__CDevices__CPrinters__CIppTextWithLanguage_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIVectorView_1_Windows__CDevices__CPrinters__CIppTextWithLanguage_GetAt(This, index, result) \
    ((This)->lpVtbl->GetAt(This, index, result))

#define __FIVectorView_1_Windows__CDevices__CPrinters__CIppTextWithLanguage_get_Size(This, result) \
    ((This)->lpVtbl->get_Size(This, result))

#define __FIVectorView_1_Windows__CDevices__CPrinters__CIppTextWithLanguage_IndexOf(This, value, index, result) \
    ((This)->lpVtbl->IndexOf(This, value, index, result))

#define __FIVectorView_1_Windows__CDevices__CPrinters__CIppTextWithLanguage_GetMany(This, startIndex, itemsLength, items, result) \
    ((This)->lpVtbl->GetMany(This, startIndex, itemsLength, items, result))

#endif /* COBJMACROS */

#endif // ____FIVectorView_1_Windows__CDevices__CPrinters__CIppTextWithLanguage_INTERFACE_DEFINED__
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____FIVectorView_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_INTERFACE_DEFINED__)
#define ____FIVectorView_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_INTERFACE_DEFINED__

typedef interface __FIVectorView_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue __FIVectorView_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIVectorView_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue;

typedef struct __FIVectorView_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValueVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIVectorView_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIVectorView_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIVectorView_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIVectorView_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIVectorView_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIVectorView_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* GetAt)(__FIVectorView_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        UINT32 index,
        __FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue** result);
    HRESULT (STDMETHODCALLTYPE* get_Size)(__FIVectorView_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        UINT32* result);
    HRESULT (STDMETHODCALLTYPE* IndexOf)(__FIVectorView_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        __FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* value,
        UINT32* index,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* GetMany)(__FIVectorView_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        UINT32 startIndex,
        UINT32 itemsLength,
        __FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue** items,
        UINT32* result);

    END_INTERFACE
} __FIVectorView_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValueVtbl;

interface __FIVectorView_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue
{
    CONST_VTBL struct __FIVectorView_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValueVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIVectorView_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIVectorView_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIVectorView_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIVectorView_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIVectorView_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIVectorView_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIVectorView_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_GetAt(This, index, result) \
    ((This)->lpVtbl->GetAt(This, index, result))

#define __FIVectorView_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_get_Size(This, result) \
    ((This)->lpVtbl->get_Size(This, result))

#define __FIVectorView_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_IndexOf(This, value, index, result) \
    ((This)->lpVtbl->IndexOf(This, value, index, result))

#define __FIVectorView_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_GetMany(This, startIndex, itemsLength, items, result) \
    ((This)->lpVtbl->GetMany(This, startIndex, itemsLength, items, result))

#endif /* COBJMACROS */

#endif // ____FIVectorView_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_INTERFACE_DEFINED__
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#if WINDOWS_FOUNDATION_FOUNDATIONCONTRACT_VERSION >= 0x10000
#if !defined(____FIVectorView_1_Windows__CFoundation__CDateTime_INTERFACE_DEFINED__)
#define ____FIVectorView_1_Windows__CFoundation__CDateTime_INTERFACE_DEFINED__

typedef interface __FIVectorView_1_Windows__CFoundation__CDateTime __FIVectorView_1_Windows__CFoundation__CDateTime;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIVectorView_1_Windows__CFoundation__CDateTime;

typedef struct __FIVectorView_1_Windows__CFoundation__CDateTimeVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIVectorView_1_Windows__CFoundation__CDateTime* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIVectorView_1_Windows__CFoundation__CDateTime* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIVectorView_1_Windows__CFoundation__CDateTime* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIVectorView_1_Windows__CFoundation__CDateTime* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIVectorView_1_Windows__CFoundation__CDateTime* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIVectorView_1_Windows__CFoundation__CDateTime* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* GetAt)(__FIVectorView_1_Windows__CFoundation__CDateTime* This,
        UINT32 index,
        struct __x_ABI_CWindows_CFoundation_CDateTime* result);
    HRESULT (STDMETHODCALLTYPE* get_Size)(__FIVectorView_1_Windows__CFoundation__CDateTime* This,
        UINT32* result);
    HRESULT (STDMETHODCALLTYPE* IndexOf)(__FIVectorView_1_Windows__CFoundation__CDateTime* This,
        struct __x_ABI_CWindows_CFoundation_CDateTime value,
        UINT32* index,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* GetMany)(__FIVectorView_1_Windows__CFoundation__CDateTime* This,
        UINT32 startIndex,
        UINT32 itemsLength,
        struct __x_ABI_CWindows_CFoundation_CDateTime* items,
        UINT32* result);

    END_INTERFACE
} __FIVectorView_1_Windows__CFoundation__CDateTimeVtbl;

interface __FIVectorView_1_Windows__CFoundation__CDateTime
{
    CONST_VTBL struct __FIVectorView_1_Windows__CFoundation__CDateTimeVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIVectorView_1_Windows__CFoundation__CDateTime_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIVectorView_1_Windows__CFoundation__CDateTime_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIVectorView_1_Windows__CFoundation__CDateTime_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIVectorView_1_Windows__CFoundation__CDateTime_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIVectorView_1_Windows__CFoundation__CDateTime_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIVectorView_1_Windows__CFoundation__CDateTime_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIVectorView_1_Windows__CFoundation__CDateTime_GetAt(This, index, result) \
    ((This)->lpVtbl->GetAt(This, index, result))

#define __FIVectorView_1_Windows__CFoundation__CDateTime_get_Size(This, result) \
    ((This)->lpVtbl->get_Size(This, result))

#define __FIVectorView_1_Windows__CFoundation__CDateTime_IndexOf(This, value, index, result) \
    ((This)->lpVtbl->IndexOf(This, value, index, result))

#define __FIVectorView_1_Windows__CFoundation__CDateTime_GetMany(This, startIndex, itemsLength, items, result) \
    ((This)->lpVtbl->GetMany(This, startIndex, itemsLength, items, result))

#endif /* COBJMACROS */

#endif // ____FIVectorView_1_Windows__CFoundation__CDateTime_INTERFACE_DEFINED__
#endif // WINDOWS_FOUNDATION_FOUNDATIONCONTRACT_VERSION >= 0x10000

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

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if !defined(____FIVectorView_1_Windows__CStorage__CStreams__CIBuffer_INTERFACE_DEFINED__)
#define ____FIVectorView_1_Windows__CStorage__CStreams__CIBuffer_INTERFACE_DEFINED__

typedef interface __FIVectorView_1_Windows__CStorage__CStreams__CIBuffer __FIVectorView_1_Windows__CStorage__CStreams__CIBuffer;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIVectorView_1_Windows__CStorage__CStreams__CIBuffer;

typedef struct __FIVectorView_1_Windows__CStorage__CStreams__CIBufferVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIVectorView_1_Windows__CStorage__CStreams__CIBuffer* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIVectorView_1_Windows__CStorage__CStreams__CIBuffer* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIVectorView_1_Windows__CStorage__CStreams__CIBuffer* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIVectorView_1_Windows__CStorage__CStreams__CIBuffer* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIVectorView_1_Windows__CStorage__CStreams__CIBuffer* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIVectorView_1_Windows__CStorage__CStreams__CIBuffer* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* GetAt)(__FIVectorView_1_Windows__CStorage__CStreams__CIBuffer* This,
        UINT32 index,
        __x_ABI_CWindows_CStorage_CStreams_CIBuffer** result);
    HRESULT (STDMETHODCALLTYPE* get_Size)(__FIVectorView_1_Windows__CStorage__CStreams__CIBuffer* This,
        UINT32* result);
    HRESULT (STDMETHODCALLTYPE* IndexOf)(__FIVectorView_1_Windows__CStorage__CStreams__CIBuffer* This,
        __x_ABI_CWindows_CStorage_CStreams_CIBuffer* value,
        UINT32* index,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* GetMany)(__FIVectorView_1_Windows__CStorage__CStreams__CIBuffer* This,
        UINT32 startIndex,
        UINT32 itemsLength,
        __x_ABI_CWindows_CStorage_CStreams_CIBuffer** items,
        UINT32* result);

    END_INTERFACE
} __FIVectorView_1_Windows__CStorage__CStreams__CIBufferVtbl;

interface __FIVectorView_1_Windows__CStorage__CStreams__CIBuffer
{
    CONST_VTBL struct __FIVectorView_1_Windows__CStorage__CStreams__CIBufferVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIVectorView_1_Windows__CStorage__CStreams__CIBuffer_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIVectorView_1_Windows__CStorage__CStreams__CIBuffer_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIVectorView_1_Windows__CStorage__CStreams__CIBuffer_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIVectorView_1_Windows__CStorage__CStreams__CIBuffer_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIVectorView_1_Windows__CStorage__CStreams__CIBuffer_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIVectorView_1_Windows__CStorage__CStreams__CIBuffer_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIVectorView_1_Windows__CStorage__CStreams__CIBuffer_GetAt(This, index, result) \
    ((This)->lpVtbl->GetAt(This, index, result))

#define __FIVectorView_1_Windows__CStorage__CStreams__CIBuffer_get_Size(This, result) \
    ((This)->lpVtbl->get_Size(This, result))

#define __FIVectorView_1_Windows__CStorage__CStreams__CIBuffer_IndexOf(This, value, index, result) \
    ((This)->lpVtbl->IndexOf(This, value, index, result))

#define __FIVectorView_1_Windows__CStorage__CStreams__CIBuffer_GetMany(This, startIndex, itemsLength, items, result) \
    ((This)->lpVtbl->GetMany(This, startIndex, itemsLength, items, result))

#endif /* COBJMACROS */

#endif // ____FIVectorView_1_Windows__CStorage__CStreams__CIBuffer_INTERFACE_DEFINED__
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#if !defined(____FIVector_1_boolean_INTERFACE_DEFINED__)
#define ____FIVector_1_boolean_INTERFACE_DEFINED__

typedef interface __FIVector_1_boolean __FIVector_1_boolean;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIVector_1_boolean;

typedef struct __FIVector_1_booleanVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIVector_1_boolean* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIVector_1_boolean* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIVector_1_boolean* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIVector_1_boolean* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIVector_1_boolean* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIVector_1_boolean* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* GetAt)(__FIVector_1_boolean* This,
        UINT32 index,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* get_Size)(__FIVector_1_boolean* This,
        UINT32* result);
    HRESULT (STDMETHODCALLTYPE* GetView)(__FIVector_1_boolean* This,
        __FIVectorView_1_boolean** result);
    HRESULT (STDMETHODCALLTYPE* IndexOf)(__FIVector_1_boolean* This,
        boolean value,
        UINT32* index,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* SetAt)(__FIVector_1_boolean* This,
        UINT32 index,
        boolean value);
    HRESULT (STDMETHODCALLTYPE* InsertAt)(__FIVector_1_boolean* This,
        UINT32 index,
        boolean value);
    HRESULT (STDMETHODCALLTYPE* RemoveAt)(__FIVector_1_boolean* This,
        UINT32 index);
    HRESULT (STDMETHODCALLTYPE* Append)(__FIVector_1_boolean* This,
        boolean value);
    HRESULT (STDMETHODCALLTYPE* RemoveAtEnd)(__FIVector_1_boolean* This);
    HRESULT (STDMETHODCALLTYPE* Clear)(__FIVector_1_boolean* This);
    HRESULT (STDMETHODCALLTYPE* GetMany)(__FIVector_1_boolean* This,
        UINT32 startIndex,
        UINT32 itemsLength,
        boolean* items,
        UINT32* result);
    HRESULT (STDMETHODCALLTYPE* ReplaceAll)(__FIVector_1_boolean* This,
        UINT32 itemsLength,
        boolean* items);

    END_INTERFACE
} __FIVector_1_booleanVtbl;

interface __FIVector_1_boolean
{
    CONST_VTBL struct __FIVector_1_booleanVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIVector_1_boolean_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIVector_1_boolean_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIVector_1_boolean_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIVector_1_boolean_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIVector_1_boolean_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIVector_1_boolean_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIVector_1_boolean_GetAt(This, index, result) \
    ((This)->lpVtbl->GetAt(This, index, result))

#define __FIVector_1_boolean_get_Size(This, result) \
    ((This)->lpVtbl->get_Size(This, result))

#define __FIVector_1_boolean_GetView(This, result) \
    ((This)->lpVtbl->GetView(This, result))

#define __FIVector_1_boolean_IndexOf(This, value, index, result) \
    ((This)->lpVtbl->IndexOf(This, value, index, result))

#define __FIVector_1_boolean_SetAt(This, index, value) \
    ((This)->lpVtbl->SetAt(This, index, value))

#define __FIVector_1_boolean_InsertAt(This, index, value) \
    ((This)->lpVtbl->InsertAt(This, index, value))

#define __FIVector_1_boolean_RemoveAt(This, index) \
    ((This)->lpVtbl->RemoveAt(This, index))

#define __FIVector_1_boolean_Append(This, value) \
    ((This)->lpVtbl->Append(This, value))

#define __FIVector_1_boolean_RemoveAtEnd(This) \
    ((This)->lpVtbl->RemoveAtEnd(This))

#define __FIVector_1_boolean_Clear(This) \
    ((This)->lpVtbl->Clear(This))

#define __FIVector_1_boolean_GetMany(This, startIndex, itemsLength, items, result) \
    ((This)->lpVtbl->GetMany(This, startIndex, itemsLength, items, result))

#define __FIVector_1_boolean_ReplaceAll(This, itemsLength, items) \
    ((This)->lpVtbl->ReplaceAll(This, itemsLength, items))

#endif /* COBJMACROS */

#endif // ____FIVector_1_boolean_INTERFACE_DEFINED__

#if !defined(____FIVector_1_int_INTERFACE_DEFINED__)
#define ____FIVector_1_int_INTERFACE_DEFINED__

typedef interface __FIVector_1_int __FIVector_1_int;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIVector_1_int;

typedef struct __FIVector_1_intVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIVector_1_int* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIVector_1_int* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIVector_1_int* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIVector_1_int* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIVector_1_int* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIVector_1_int* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* GetAt)(__FIVector_1_int* This,
        UINT32 index,
        INT32* result);
    HRESULT (STDMETHODCALLTYPE* get_Size)(__FIVector_1_int* This,
        UINT32* result);
    HRESULT (STDMETHODCALLTYPE* GetView)(__FIVector_1_int* This,
        __FIVectorView_1_int** result);
    HRESULT (STDMETHODCALLTYPE* IndexOf)(__FIVector_1_int* This,
        INT32 value,
        UINT32* index,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* SetAt)(__FIVector_1_int* This,
        UINT32 index,
        INT32 value);
    HRESULT (STDMETHODCALLTYPE* InsertAt)(__FIVector_1_int* This,
        UINT32 index,
        INT32 value);
    HRESULT (STDMETHODCALLTYPE* RemoveAt)(__FIVector_1_int* This,
        UINT32 index);
    HRESULT (STDMETHODCALLTYPE* Append)(__FIVector_1_int* This,
        INT32 value);
    HRESULT (STDMETHODCALLTYPE* RemoveAtEnd)(__FIVector_1_int* This);
    HRESULT (STDMETHODCALLTYPE* Clear)(__FIVector_1_int* This);
    HRESULT (STDMETHODCALLTYPE* GetMany)(__FIVector_1_int* This,
        UINT32 startIndex,
        UINT32 itemsLength,
        INT32* items,
        UINT32* result);
    HRESULT (STDMETHODCALLTYPE* ReplaceAll)(__FIVector_1_int* This,
        UINT32 itemsLength,
        INT32* items);

    END_INTERFACE
} __FIVector_1_intVtbl;

interface __FIVector_1_int
{
    CONST_VTBL struct __FIVector_1_intVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIVector_1_int_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIVector_1_int_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIVector_1_int_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIVector_1_int_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIVector_1_int_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIVector_1_int_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIVector_1_int_GetAt(This, index, result) \
    ((This)->lpVtbl->GetAt(This, index, result))

#define __FIVector_1_int_get_Size(This, result) \
    ((This)->lpVtbl->get_Size(This, result))

#define __FIVector_1_int_GetView(This, result) \
    ((This)->lpVtbl->GetView(This, result))

#define __FIVector_1_int_IndexOf(This, value, index, result) \
    ((This)->lpVtbl->IndexOf(This, value, index, result))

#define __FIVector_1_int_SetAt(This, index, value) \
    ((This)->lpVtbl->SetAt(This, index, value))

#define __FIVector_1_int_InsertAt(This, index, value) \
    ((This)->lpVtbl->InsertAt(This, index, value))

#define __FIVector_1_int_RemoveAt(This, index) \
    ((This)->lpVtbl->RemoveAt(This, index))

#define __FIVector_1_int_Append(This, value) \
    ((This)->lpVtbl->Append(This, value))

#define __FIVector_1_int_RemoveAtEnd(This) \
    ((This)->lpVtbl->RemoveAtEnd(This))

#define __FIVector_1_int_Clear(This) \
    ((This)->lpVtbl->Clear(This))

#define __FIVector_1_int_GetMany(This, startIndex, itemsLength, items, result) \
    ((This)->lpVtbl->GetMany(This, startIndex, itemsLength, items, result))

#define __FIVector_1_int_ReplaceAll(This, itemsLength, items) \
    ((This)->lpVtbl->ReplaceAll(This, itemsLength, items))

#endif /* COBJMACROS */

#endif // ____FIVector_1_int_INTERFACE_DEFINED__

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

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____FIVector_1_Windows__CDevices__CPrinters__CIppIntegerRange_INTERFACE_DEFINED__)
#define ____FIVector_1_Windows__CDevices__CPrinters__CIppIntegerRange_INTERFACE_DEFINED__

typedef interface __FIVector_1_Windows__CDevices__CPrinters__CIppIntegerRange __FIVector_1_Windows__CDevices__CPrinters__CIppIntegerRange;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIVector_1_Windows__CDevices__CPrinters__CIppIntegerRange;

typedef struct __FIVector_1_Windows__CDevices__CPrinters__CIppIntegerRangeVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIVector_1_Windows__CDevices__CPrinters__CIppIntegerRange* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIVector_1_Windows__CDevices__CPrinters__CIppIntegerRange* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIVector_1_Windows__CDevices__CPrinters__CIppIntegerRange* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIVector_1_Windows__CDevices__CPrinters__CIppIntegerRange* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIVector_1_Windows__CDevices__CPrinters__CIppIntegerRange* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIVector_1_Windows__CDevices__CPrinters__CIppIntegerRange* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* GetAt)(__FIVector_1_Windows__CDevices__CPrinters__CIppIntegerRange* This,
        UINT32 index,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRange** result);
    HRESULT (STDMETHODCALLTYPE* get_Size)(__FIVector_1_Windows__CDevices__CPrinters__CIppIntegerRange* This,
        UINT32* result);
    HRESULT (STDMETHODCALLTYPE* GetView)(__FIVector_1_Windows__CDevices__CPrinters__CIppIntegerRange* This,
        __FIVectorView_1_Windows__CDevices__CPrinters__CIppIntegerRange** result);
    HRESULT (STDMETHODCALLTYPE* IndexOf)(__FIVector_1_Windows__CDevices__CPrinters__CIppIntegerRange* This,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRange* value,
        UINT32* index,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* SetAt)(__FIVector_1_Windows__CDevices__CPrinters__CIppIntegerRange* This,
        UINT32 index,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRange* value);
    HRESULT (STDMETHODCALLTYPE* InsertAt)(__FIVector_1_Windows__CDevices__CPrinters__CIppIntegerRange* This,
        UINT32 index,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRange* value);
    HRESULT (STDMETHODCALLTYPE* RemoveAt)(__FIVector_1_Windows__CDevices__CPrinters__CIppIntegerRange* This,
        UINT32 index);
    HRESULT (STDMETHODCALLTYPE* Append)(__FIVector_1_Windows__CDevices__CPrinters__CIppIntegerRange* This,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRange* value);
    HRESULT (STDMETHODCALLTYPE* RemoveAtEnd)(__FIVector_1_Windows__CDevices__CPrinters__CIppIntegerRange* This);
    HRESULT (STDMETHODCALLTYPE* Clear)(__FIVector_1_Windows__CDevices__CPrinters__CIppIntegerRange* This);
    HRESULT (STDMETHODCALLTYPE* GetMany)(__FIVector_1_Windows__CDevices__CPrinters__CIppIntegerRange* This,
        UINT32 startIndex,
        UINT32 itemsLength,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRange** items,
        UINT32* result);
    HRESULT (STDMETHODCALLTYPE* ReplaceAll)(__FIVector_1_Windows__CDevices__CPrinters__CIppIntegerRange* This,
        UINT32 itemsLength,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRange** items);

    END_INTERFACE
} __FIVector_1_Windows__CDevices__CPrinters__CIppIntegerRangeVtbl;

interface __FIVector_1_Windows__CDevices__CPrinters__CIppIntegerRange
{
    CONST_VTBL struct __FIVector_1_Windows__CDevices__CPrinters__CIppIntegerRangeVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIVector_1_Windows__CDevices__CPrinters__CIppIntegerRange_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIVector_1_Windows__CDevices__CPrinters__CIppIntegerRange_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIVector_1_Windows__CDevices__CPrinters__CIppIntegerRange_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIVector_1_Windows__CDevices__CPrinters__CIppIntegerRange_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIVector_1_Windows__CDevices__CPrinters__CIppIntegerRange_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIVector_1_Windows__CDevices__CPrinters__CIppIntegerRange_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIVector_1_Windows__CDevices__CPrinters__CIppIntegerRange_GetAt(This, index, result) \
    ((This)->lpVtbl->GetAt(This, index, result))

#define __FIVector_1_Windows__CDevices__CPrinters__CIppIntegerRange_get_Size(This, result) \
    ((This)->lpVtbl->get_Size(This, result))

#define __FIVector_1_Windows__CDevices__CPrinters__CIppIntegerRange_GetView(This, result) \
    ((This)->lpVtbl->GetView(This, result))

#define __FIVector_1_Windows__CDevices__CPrinters__CIppIntegerRange_IndexOf(This, value, index, result) \
    ((This)->lpVtbl->IndexOf(This, value, index, result))

#define __FIVector_1_Windows__CDevices__CPrinters__CIppIntegerRange_SetAt(This, index, value) \
    ((This)->lpVtbl->SetAt(This, index, value))

#define __FIVector_1_Windows__CDevices__CPrinters__CIppIntegerRange_InsertAt(This, index, value) \
    ((This)->lpVtbl->InsertAt(This, index, value))

#define __FIVector_1_Windows__CDevices__CPrinters__CIppIntegerRange_RemoveAt(This, index) \
    ((This)->lpVtbl->RemoveAt(This, index))

#define __FIVector_1_Windows__CDevices__CPrinters__CIppIntegerRange_Append(This, value) \
    ((This)->lpVtbl->Append(This, value))

#define __FIVector_1_Windows__CDevices__CPrinters__CIppIntegerRange_RemoveAtEnd(This) \
    ((This)->lpVtbl->RemoveAtEnd(This))

#define __FIVector_1_Windows__CDevices__CPrinters__CIppIntegerRange_Clear(This) \
    ((This)->lpVtbl->Clear(This))

#define __FIVector_1_Windows__CDevices__CPrinters__CIppIntegerRange_GetMany(This, startIndex, itemsLength, items, result) \
    ((This)->lpVtbl->GetMany(This, startIndex, itemsLength, items, result))

#define __FIVector_1_Windows__CDevices__CPrinters__CIppIntegerRange_ReplaceAll(This, itemsLength, items) \
    ((This)->lpVtbl->ReplaceAll(This, itemsLength, items))

#endif /* COBJMACROS */

#endif // ____FIVector_1_Windows__CDevices__CPrinters__CIppIntegerRange_INTERFACE_DEFINED__
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____FIVector_1_Windows__CDevices__CPrinters__CIppResolution_INTERFACE_DEFINED__)
#define ____FIVector_1_Windows__CDevices__CPrinters__CIppResolution_INTERFACE_DEFINED__

typedef interface __FIVector_1_Windows__CDevices__CPrinters__CIppResolution __FIVector_1_Windows__CDevices__CPrinters__CIppResolution;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIVector_1_Windows__CDevices__CPrinters__CIppResolution;

typedef struct __FIVector_1_Windows__CDevices__CPrinters__CIppResolutionVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIVector_1_Windows__CDevices__CPrinters__CIppResolution* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIVector_1_Windows__CDevices__CPrinters__CIppResolution* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIVector_1_Windows__CDevices__CPrinters__CIppResolution* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIVector_1_Windows__CDevices__CPrinters__CIppResolution* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIVector_1_Windows__CDevices__CPrinters__CIppResolution* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIVector_1_Windows__CDevices__CPrinters__CIppResolution* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* GetAt)(__FIVector_1_Windows__CDevices__CPrinters__CIppResolution* This,
        UINT32 index,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppResolution** result);
    HRESULT (STDMETHODCALLTYPE* get_Size)(__FIVector_1_Windows__CDevices__CPrinters__CIppResolution* This,
        UINT32* result);
    HRESULT (STDMETHODCALLTYPE* GetView)(__FIVector_1_Windows__CDevices__CPrinters__CIppResolution* This,
        __FIVectorView_1_Windows__CDevices__CPrinters__CIppResolution** result);
    HRESULT (STDMETHODCALLTYPE* IndexOf)(__FIVector_1_Windows__CDevices__CPrinters__CIppResolution* This,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppResolution* value,
        UINT32* index,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* SetAt)(__FIVector_1_Windows__CDevices__CPrinters__CIppResolution* This,
        UINT32 index,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppResolution* value);
    HRESULT (STDMETHODCALLTYPE* InsertAt)(__FIVector_1_Windows__CDevices__CPrinters__CIppResolution* This,
        UINT32 index,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppResolution* value);
    HRESULT (STDMETHODCALLTYPE* RemoveAt)(__FIVector_1_Windows__CDevices__CPrinters__CIppResolution* This,
        UINT32 index);
    HRESULT (STDMETHODCALLTYPE* Append)(__FIVector_1_Windows__CDevices__CPrinters__CIppResolution* This,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppResolution* value);
    HRESULT (STDMETHODCALLTYPE* RemoveAtEnd)(__FIVector_1_Windows__CDevices__CPrinters__CIppResolution* This);
    HRESULT (STDMETHODCALLTYPE* Clear)(__FIVector_1_Windows__CDevices__CPrinters__CIppResolution* This);
    HRESULT (STDMETHODCALLTYPE* GetMany)(__FIVector_1_Windows__CDevices__CPrinters__CIppResolution* This,
        UINT32 startIndex,
        UINT32 itemsLength,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppResolution** items,
        UINT32* result);
    HRESULT (STDMETHODCALLTYPE* ReplaceAll)(__FIVector_1_Windows__CDevices__CPrinters__CIppResolution* This,
        UINT32 itemsLength,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppResolution** items);

    END_INTERFACE
} __FIVector_1_Windows__CDevices__CPrinters__CIppResolutionVtbl;

interface __FIVector_1_Windows__CDevices__CPrinters__CIppResolution
{
    CONST_VTBL struct __FIVector_1_Windows__CDevices__CPrinters__CIppResolutionVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIVector_1_Windows__CDevices__CPrinters__CIppResolution_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIVector_1_Windows__CDevices__CPrinters__CIppResolution_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIVector_1_Windows__CDevices__CPrinters__CIppResolution_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIVector_1_Windows__CDevices__CPrinters__CIppResolution_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIVector_1_Windows__CDevices__CPrinters__CIppResolution_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIVector_1_Windows__CDevices__CPrinters__CIppResolution_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIVector_1_Windows__CDevices__CPrinters__CIppResolution_GetAt(This, index, result) \
    ((This)->lpVtbl->GetAt(This, index, result))

#define __FIVector_1_Windows__CDevices__CPrinters__CIppResolution_get_Size(This, result) \
    ((This)->lpVtbl->get_Size(This, result))

#define __FIVector_1_Windows__CDevices__CPrinters__CIppResolution_GetView(This, result) \
    ((This)->lpVtbl->GetView(This, result))

#define __FIVector_1_Windows__CDevices__CPrinters__CIppResolution_IndexOf(This, value, index, result) \
    ((This)->lpVtbl->IndexOf(This, value, index, result))

#define __FIVector_1_Windows__CDevices__CPrinters__CIppResolution_SetAt(This, index, value) \
    ((This)->lpVtbl->SetAt(This, index, value))

#define __FIVector_1_Windows__CDevices__CPrinters__CIppResolution_InsertAt(This, index, value) \
    ((This)->lpVtbl->InsertAt(This, index, value))

#define __FIVector_1_Windows__CDevices__CPrinters__CIppResolution_RemoveAt(This, index) \
    ((This)->lpVtbl->RemoveAt(This, index))

#define __FIVector_1_Windows__CDevices__CPrinters__CIppResolution_Append(This, value) \
    ((This)->lpVtbl->Append(This, value))

#define __FIVector_1_Windows__CDevices__CPrinters__CIppResolution_RemoveAtEnd(This) \
    ((This)->lpVtbl->RemoveAtEnd(This))

#define __FIVector_1_Windows__CDevices__CPrinters__CIppResolution_Clear(This) \
    ((This)->lpVtbl->Clear(This))

#define __FIVector_1_Windows__CDevices__CPrinters__CIppResolution_GetMany(This, startIndex, itemsLength, items, result) \
    ((This)->lpVtbl->GetMany(This, startIndex, itemsLength, items, result))

#define __FIVector_1_Windows__CDevices__CPrinters__CIppResolution_ReplaceAll(This, itemsLength, items) \
    ((This)->lpVtbl->ReplaceAll(This, itemsLength, items))

#endif /* COBJMACROS */

#endif // ____FIVector_1_Windows__CDevices__CPrinters__CIppResolution_INTERFACE_DEFINED__
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____FIVector_1_Windows__CDevices__CPrinters__CIppTextWithLanguage_INTERFACE_DEFINED__)
#define ____FIVector_1_Windows__CDevices__CPrinters__CIppTextWithLanguage_INTERFACE_DEFINED__

typedef interface __FIVector_1_Windows__CDevices__CPrinters__CIppTextWithLanguage __FIVector_1_Windows__CDevices__CPrinters__CIppTextWithLanguage;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIVector_1_Windows__CDevices__CPrinters__CIppTextWithLanguage;

typedef struct __FIVector_1_Windows__CDevices__CPrinters__CIppTextWithLanguageVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIVector_1_Windows__CDevices__CPrinters__CIppTextWithLanguage* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIVector_1_Windows__CDevices__CPrinters__CIppTextWithLanguage* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIVector_1_Windows__CDevices__CPrinters__CIppTextWithLanguage* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIVector_1_Windows__CDevices__CPrinters__CIppTextWithLanguage* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIVector_1_Windows__CDevices__CPrinters__CIppTextWithLanguage* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIVector_1_Windows__CDevices__CPrinters__CIppTextWithLanguage* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* GetAt)(__FIVector_1_Windows__CDevices__CPrinters__CIppTextWithLanguage* This,
        UINT32 index,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguage** result);
    HRESULT (STDMETHODCALLTYPE* get_Size)(__FIVector_1_Windows__CDevices__CPrinters__CIppTextWithLanguage* This,
        UINT32* result);
    HRESULT (STDMETHODCALLTYPE* GetView)(__FIVector_1_Windows__CDevices__CPrinters__CIppTextWithLanguage* This,
        __FIVectorView_1_Windows__CDevices__CPrinters__CIppTextWithLanguage** result);
    HRESULT (STDMETHODCALLTYPE* IndexOf)(__FIVector_1_Windows__CDevices__CPrinters__CIppTextWithLanguage* This,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguage* value,
        UINT32* index,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* SetAt)(__FIVector_1_Windows__CDevices__CPrinters__CIppTextWithLanguage* This,
        UINT32 index,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguage* value);
    HRESULT (STDMETHODCALLTYPE* InsertAt)(__FIVector_1_Windows__CDevices__CPrinters__CIppTextWithLanguage* This,
        UINT32 index,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguage* value);
    HRESULT (STDMETHODCALLTYPE* RemoveAt)(__FIVector_1_Windows__CDevices__CPrinters__CIppTextWithLanguage* This,
        UINT32 index);
    HRESULT (STDMETHODCALLTYPE* Append)(__FIVector_1_Windows__CDevices__CPrinters__CIppTextWithLanguage* This,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguage* value);
    HRESULT (STDMETHODCALLTYPE* RemoveAtEnd)(__FIVector_1_Windows__CDevices__CPrinters__CIppTextWithLanguage* This);
    HRESULT (STDMETHODCALLTYPE* Clear)(__FIVector_1_Windows__CDevices__CPrinters__CIppTextWithLanguage* This);
    HRESULT (STDMETHODCALLTYPE* GetMany)(__FIVector_1_Windows__CDevices__CPrinters__CIppTextWithLanguage* This,
        UINT32 startIndex,
        UINT32 itemsLength,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguage** items,
        UINT32* result);
    HRESULT (STDMETHODCALLTYPE* ReplaceAll)(__FIVector_1_Windows__CDevices__CPrinters__CIppTextWithLanguage* This,
        UINT32 itemsLength,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguage** items);

    END_INTERFACE
} __FIVector_1_Windows__CDevices__CPrinters__CIppTextWithLanguageVtbl;

interface __FIVector_1_Windows__CDevices__CPrinters__CIppTextWithLanguage
{
    CONST_VTBL struct __FIVector_1_Windows__CDevices__CPrinters__CIppTextWithLanguageVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIVector_1_Windows__CDevices__CPrinters__CIppTextWithLanguage_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIVector_1_Windows__CDevices__CPrinters__CIppTextWithLanguage_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIVector_1_Windows__CDevices__CPrinters__CIppTextWithLanguage_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIVector_1_Windows__CDevices__CPrinters__CIppTextWithLanguage_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIVector_1_Windows__CDevices__CPrinters__CIppTextWithLanguage_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIVector_1_Windows__CDevices__CPrinters__CIppTextWithLanguage_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIVector_1_Windows__CDevices__CPrinters__CIppTextWithLanguage_GetAt(This, index, result) \
    ((This)->lpVtbl->GetAt(This, index, result))

#define __FIVector_1_Windows__CDevices__CPrinters__CIppTextWithLanguage_get_Size(This, result) \
    ((This)->lpVtbl->get_Size(This, result))

#define __FIVector_1_Windows__CDevices__CPrinters__CIppTextWithLanguage_GetView(This, result) \
    ((This)->lpVtbl->GetView(This, result))

#define __FIVector_1_Windows__CDevices__CPrinters__CIppTextWithLanguage_IndexOf(This, value, index, result) \
    ((This)->lpVtbl->IndexOf(This, value, index, result))

#define __FIVector_1_Windows__CDevices__CPrinters__CIppTextWithLanguage_SetAt(This, index, value) \
    ((This)->lpVtbl->SetAt(This, index, value))

#define __FIVector_1_Windows__CDevices__CPrinters__CIppTextWithLanguage_InsertAt(This, index, value) \
    ((This)->lpVtbl->InsertAt(This, index, value))

#define __FIVector_1_Windows__CDevices__CPrinters__CIppTextWithLanguage_RemoveAt(This, index) \
    ((This)->lpVtbl->RemoveAt(This, index))

#define __FIVector_1_Windows__CDevices__CPrinters__CIppTextWithLanguage_Append(This, value) \
    ((This)->lpVtbl->Append(This, value))

#define __FIVector_1_Windows__CDevices__CPrinters__CIppTextWithLanguage_RemoveAtEnd(This) \
    ((This)->lpVtbl->RemoveAtEnd(This))

#define __FIVector_1_Windows__CDevices__CPrinters__CIppTextWithLanguage_Clear(This) \
    ((This)->lpVtbl->Clear(This))

#define __FIVector_1_Windows__CDevices__CPrinters__CIppTextWithLanguage_GetMany(This, startIndex, itemsLength, items, result) \
    ((This)->lpVtbl->GetMany(This, startIndex, itemsLength, items, result))

#define __FIVector_1_Windows__CDevices__CPrinters__CIppTextWithLanguage_ReplaceAll(This, itemsLength, items) \
    ((This)->lpVtbl->ReplaceAll(This, itemsLength, items))

#endif /* COBJMACROS */

#endif // ____FIVector_1_Windows__CDevices__CPrinters__CIppTextWithLanguage_INTERFACE_DEFINED__
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____FIVector_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_INTERFACE_DEFINED__)
#define ____FIVector_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_INTERFACE_DEFINED__

typedef interface __FIVector_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue __FIVector_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIVector_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue;

typedef struct __FIVector_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValueVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIVector_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIVector_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIVector_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIVector_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIVector_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIVector_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* GetAt)(__FIVector_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        UINT32 index,
        __FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue** result);
    HRESULT (STDMETHODCALLTYPE* get_Size)(__FIVector_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        UINT32* result);
    HRESULT (STDMETHODCALLTYPE* GetView)(__FIVector_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        __FIVectorView_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue** result);
    HRESULT (STDMETHODCALLTYPE* IndexOf)(__FIVector_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        __FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* value,
        UINT32* index,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* SetAt)(__FIVector_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        UINT32 index,
        __FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* value);
    HRESULT (STDMETHODCALLTYPE* InsertAt)(__FIVector_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        UINT32 index,
        __FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* value);
    HRESULT (STDMETHODCALLTYPE* RemoveAt)(__FIVector_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        UINT32 index);
    HRESULT (STDMETHODCALLTYPE* Append)(__FIVector_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        __FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* value);
    HRESULT (STDMETHODCALLTYPE* RemoveAtEnd)(__FIVector_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This);
    HRESULT (STDMETHODCALLTYPE* Clear)(__FIVector_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This);
    HRESULT (STDMETHODCALLTYPE* GetMany)(__FIVector_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        UINT32 startIndex,
        UINT32 itemsLength,
        __FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue** items,
        UINT32* result);
    HRESULT (STDMETHODCALLTYPE* ReplaceAll)(__FIVector_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* This,
        UINT32 itemsLength,
        __FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue** items);

    END_INTERFACE
} __FIVector_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValueVtbl;

interface __FIVector_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue
{
    CONST_VTBL struct __FIVector_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValueVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIVector_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIVector_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIVector_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIVector_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIVector_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIVector_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIVector_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_GetAt(This, index, result) \
    ((This)->lpVtbl->GetAt(This, index, result))

#define __FIVector_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_get_Size(This, result) \
    ((This)->lpVtbl->get_Size(This, result))

#define __FIVector_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_GetView(This, result) \
    ((This)->lpVtbl->GetView(This, result))

#define __FIVector_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_IndexOf(This, value, index, result) \
    ((This)->lpVtbl->IndexOf(This, value, index, result))

#define __FIVector_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_SetAt(This, index, value) \
    ((This)->lpVtbl->SetAt(This, index, value))

#define __FIVector_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_InsertAt(This, index, value) \
    ((This)->lpVtbl->InsertAt(This, index, value))

#define __FIVector_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_RemoveAt(This, index) \
    ((This)->lpVtbl->RemoveAt(This, index))

#define __FIVector_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_Append(This, value) \
    ((This)->lpVtbl->Append(This, value))

#define __FIVector_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_RemoveAtEnd(This) \
    ((This)->lpVtbl->RemoveAtEnd(This))

#define __FIVector_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_Clear(This) \
    ((This)->lpVtbl->Clear(This))

#define __FIVector_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_GetMany(This, startIndex, itemsLength, items, result) \
    ((This)->lpVtbl->GetMany(This, startIndex, itemsLength, items, result))

#define __FIVector_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_ReplaceAll(This, itemsLength, items) \
    ((This)->lpVtbl->ReplaceAll(This, itemsLength, items))

#endif /* COBJMACROS */

#endif // ____FIVector_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue_INTERFACE_DEFINED__
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#if WINDOWS_FOUNDATION_FOUNDATIONCONTRACT_VERSION >= 0x10000
#if !defined(____FIVector_1_Windows__CFoundation__CDateTime_INTERFACE_DEFINED__)
#define ____FIVector_1_Windows__CFoundation__CDateTime_INTERFACE_DEFINED__

typedef interface __FIVector_1_Windows__CFoundation__CDateTime __FIVector_1_Windows__CFoundation__CDateTime;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIVector_1_Windows__CFoundation__CDateTime;

typedef struct __FIVector_1_Windows__CFoundation__CDateTimeVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIVector_1_Windows__CFoundation__CDateTime* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIVector_1_Windows__CFoundation__CDateTime* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIVector_1_Windows__CFoundation__CDateTime* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIVector_1_Windows__CFoundation__CDateTime* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIVector_1_Windows__CFoundation__CDateTime* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIVector_1_Windows__CFoundation__CDateTime* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* GetAt)(__FIVector_1_Windows__CFoundation__CDateTime* This,
        UINT32 index,
        struct __x_ABI_CWindows_CFoundation_CDateTime* result);
    HRESULT (STDMETHODCALLTYPE* get_Size)(__FIVector_1_Windows__CFoundation__CDateTime* This,
        UINT32* result);
    HRESULT (STDMETHODCALLTYPE* GetView)(__FIVector_1_Windows__CFoundation__CDateTime* This,
        __FIVectorView_1_Windows__CFoundation__CDateTime** result);
    HRESULT (STDMETHODCALLTYPE* IndexOf)(__FIVector_1_Windows__CFoundation__CDateTime* This,
        struct __x_ABI_CWindows_CFoundation_CDateTime value,
        UINT32* index,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* SetAt)(__FIVector_1_Windows__CFoundation__CDateTime* This,
        UINT32 index,
        struct __x_ABI_CWindows_CFoundation_CDateTime value);
    HRESULT (STDMETHODCALLTYPE* InsertAt)(__FIVector_1_Windows__CFoundation__CDateTime* This,
        UINT32 index,
        struct __x_ABI_CWindows_CFoundation_CDateTime value);
    HRESULT (STDMETHODCALLTYPE* RemoveAt)(__FIVector_1_Windows__CFoundation__CDateTime* This,
        UINT32 index);
    HRESULT (STDMETHODCALLTYPE* Append)(__FIVector_1_Windows__CFoundation__CDateTime* This,
        struct __x_ABI_CWindows_CFoundation_CDateTime value);
    HRESULT (STDMETHODCALLTYPE* RemoveAtEnd)(__FIVector_1_Windows__CFoundation__CDateTime* This);
    HRESULT (STDMETHODCALLTYPE* Clear)(__FIVector_1_Windows__CFoundation__CDateTime* This);
    HRESULT (STDMETHODCALLTYPE* GetMany)(__FIVector_1_Windows__CFoundation__CDateTime* This,
        UINT32 startIndex,
        UINT32 itemsLength,
        struct __x_ABI_CWindows_CFoundation_CDateTime* items,
        UINT32* result);
    HRESULT (STDMETHODCALLTYPE* ReplaceAll)(__FIVector_1_Windows__CFoundation__CDateTime* This,
        UINT32 itemsLength,
        struct __x_ABI_CWindows_CFoundation_CDateTime* items);

    END_INTERFACE
} __FIVector_1_Windows__CFoundation__CDateTimeVtbl;

interface __FIVector_1_Windows__CFoundation__CDateTime
{
    CONST_VTBL struct __FIVector_1_Windows__CFoundation__CDateTimeVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIVector_1_Windows__CFoundation__CDateTime_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIVector_1_Windows__CFoundation__CDateTime_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIVector_1_Windows__CFoundation__CDateTime_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIVector_1_Windows__CFoundation__CDateTime_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIVector_1_Windows__CFoundation__CDateTime_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIVector_1_Windows__CFoundation__CDateTime_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIVector_1_Windows__CFoundation__CDateTime_GetAt(This, index, result) \
    ((This)->lpVtbl->GetAt(This, index, result))

#define __FIVector_1_Windows__CFoundation__CDateTime_get_Size(This, result) \
    ((This)->lpVtbl->get_Size(This, result))

#define __FIVector_1_Windows__CFoundation__CDateTime_GetView(This, result) \
    ((This)->lpVtbl->GetView(This, result))

#define __FIVector_1_Windows__CFoundation__CDateTime_IndexOf(This, value, index, result) \
    ((This)->lpVtbl->IndexOf(This, value, index, result))

#define __FIVector_1_Windows__CFoundation__CDateTime_SetAt(This, index, value) \
    ((This)->lpVtbl->SetAt(This, index, value))

#define __FIVector_1_Windows__CFoundation__CDateTime_InsertAt(This, index, value) \
    ((This)->lpVtbl->InsertAt(This, index, value))

#define __FIVector_1_Windows__CFoundation__CDateTime_RemoveAt(This, index) \
    ((This)->lpVtbl->RemoveAt(This, index))

#define __FIVector_1_Windows__CFoundation__CDateTime_Append(This, value) \
    ((This)->lpVtbl->Append(This, value))

#define __FIVector_1_Windows__CFoundation__CDateTime_RemoveAtEnd(This) \
    ((This)->lpVtbl->RemoveAtEnd(This))

#define __FIVector_1_Windows__CFoundation__CDateTime_Clear(This) \
    ((This)->lpVtbl->Clear(This))

#define __FIVector_1_Windows__CFoundation__CDateTime_GetMany(This, startIndex, itemsLength, items, result) \
    ((This)->lpVtbl->GetMany(This, startIndex, itemsLength, items, result))

#define __FIVector_1_Windows__CFoundation__CDateTime_ReplaceAll(This, itemsLength, items) \
    ((This)->lpVtbl->ReplaceAll(This, itemsLength, items))

#endif /* COBJMACROS */

#endif // ____FIVector_1_Windows__CFoundation__CDateTime_INTERFACE_DEFINED__
#endif // WINDOWS_FOUNDATION_FOUNDATIONCONTRACT_VERSION >= 0x10000

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

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if !defined(____FIVector_1_Windows__CStorage__CStreams__CIBuffer_INTERFACE_DEFINED__)
#define ____FIVector_1_Windows__CStorage__CStreams__CIBuffer_INTERFACE_DEFINED__

typedef interface __FIVector_1_Windows__CStorage__CStreams__CIBuffer __FIVector_1_Windows__CStorage__CStreams__CIBuffer;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIVector_1_Windows__CStorage__CStreams__CIBuffer;

typedef struct __FIVector_1_Windows__CStorage__CStreams__CIBufferVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIVector_1_Windows__CStorage__CStreams__CIBuffer* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIVector_1_Windows__CStorage__CStreams__CIBuffer* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIVector_1_Windows__CStorage__CStreams__CIBuffer* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIVector_1_Windows__CStorage__CStreams__CIBuffer* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIVector_1_Windows__CStorage__CStreams__CIBuffer* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIVector_1_Windows__CStorage__CStreams__CIBuffer* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* GetAt)(__FIVector_1_Windows__CStorage__CStreams__CIBuffer* This,
        UINT32 index,
        __x_ABI_CWindows_CStorage_CStreams_CIBuffer** result);
    HRESULT (STDMETHODCALLTYPE* get_Size)(__FIVector_1_Windows__CStorage__CStreams__CIBuffer* This,
        UINT32* result);
    HRESULT (STDMETHODCALLTYPE* GetView)(__FIVector_1_Windows__CStorage__CStreams__CIBuffer* This,
        __FIVectorView_1_Windows__CStorage__CStreams__CIBuffer** result);
    HRESULT (STDMETHODCALLTYPE* IndexOf)(__FIVector_1_Windows__CStorage__CStreams__CIBuffer* This,
        __x_ABI_CWindows_CStorage_CStreams_CIBuffer* value,
        UINT32* index,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* SetAt)(__FIVector_1_Windows__CStorage__CStreams__CIBuffer* This,
        UINT32 index,
        __x_ABI_CWindows_CStorage_CStreams_CIBuffer* value);
    HRESULT (STDMETHODCALLTYPE* InsertAt)(__FIVector_1_Windows__CStorage__CStreams__CIBuffer* This,
        UINT32 index,
        __x_ABI_CWindows_CStorage_CStreams_CIBuffer* value);
    HRESULT (STDMETHODCALLTYPE* RemoveAt)(__FIVector_1_Windows__CStorage__CStreams__CIBuffer* This,
        UINT32 index);
    HRESULT (STDMETHODCALLTYPE* Append)(__FIVector_1_Windows__CStorage__CStreams__CIBuffer* This,
        __x_ABI_CWindows_CStorage_CStreams_CIBuffer* value);
    HRESULT (STDMETHODCALLTYPE* RemoveAtEnd)(__FIVector_1_Windows__CStorage__CStreams__CIBuffer* This);
    HRESULT (STDMETHODCALLTYPE* Clear)(__FIVector_1_Windows__CStorage__CStreams__CIBuffer* This);
    HRESULT (STDMETHODCALLTYPE* GetMany)(__FIVector_1_Windows__CStorage__CStreams__CIBuffer* This,
        UINT32 startIndex,
        UINT32 itemsLength,
        __x_ABI_CWindows_CStorage_CStreams_CIBuffer** items,
        UINT32* result);
    HRESULT (STDMETHODCALLTYPE* ReplaceAll)(__FIVector_1_Windows__CStorage__CStreams__CIBuffer* This,
        UINT32 itemsLength,
        __x_ABI_CWindows_CStorage_CStreams_CIBuffer** items);

    END_INTERFACE
} __FIVector_1_Windows__CStorage__CStreams__CIBufferVtbl;

interface __FIVector_1_Windows__CStorage__CStreams__CIBuffer
{
    CONST_VTBL struct __FIVector_1_Windows__CStorage__CStreams__CIBufferVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIVector_1_Windows__CStorage__CStreams__CIBuffer_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIVector_1_Windows__CStorage__CStreams__CIBuffer_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIVector_1_Windows__CStorage__CStreams__CIBuffer_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIVector_1_Windows__CStorage__CStreams__CIBuffer_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIVector_1_Windows__CStorage__CStreams__CIBuffer_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIVector_1_Windows__CStorage__CStreams__CIBuffer_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIVector_1_Windows__CStorage__CStreams__CIBuffer_GetAt(This, index, result) \
    ((This)->lpVtbl->GetAt(This, index, result))

#define __FIVector_1_Windows__CStorage__CStreams__CIBuffer_get_Size(This, result) \
    ((This)->lpVtbl->get_Size(This, result))

#define __FIVector_1_Windows__CStorage__CStreams__CIBuffer_GetView(This, result) \
    ((This)->lpVtbl->GetView(This, result))

#define __FIVector_1_Windows__CStorage__CStreams__CIBuffer_IndexOf(This, value, index, result) \
    ((This)->lpVtbl->IndexOf(This, value, index, result))

#define __FIVector_1_Windows__CStorage__CStreams__CIBuffer_SetAt(This, index, value) \
    ((This)->lpVtbl->SetAt(This, index, value))

#define __FIVector_1_Windows__CStorage__CStreams__CIBuffer_InsertAt(This, index, value) \
    ((This)->lpVtbl->InsertAt(This, index, value))

#define __FIVector_1_Windows__CStorage__CStreams__CIBuffer_RemoveAt(This, index) \
    ((This)->lpVtbl->RemoveAt(This, index))

#define __FIVector_1_Windows__CStorage__CStreams__CIBuffer_Append(This, value) \
    ((This)->lpVtbl->Append(This, value))

#define __FIVector_1_Windows__CStorage__CStreams__CIBuffer_RemoveAtEnd(This) \
    ((This)->lpVtbl->RemoveAtEnd(This))

#define __FIVector_1_Windows__CStorage__CStreams__CIBuffer_Clear(This) \
    ((This)->lpVtbl->Clear(This))

#define __FIVector_1_Windows__CStorage__CStreams__CIBuffer_GetMany(This, startIndex, itemsLength, items, result) \
    ((This)->lpVtbl->GetMany(This, startIndex, itemsLength, items, result))

#define __FIVector_1_Windows__CStorage__CStreams__CIBuffer_ReplaceAll(This, itemsLength, items) \
    ((This)->lpVtbl->ReplaceAll(This, itemsLength, items))

#endif /* COBJMACROS */

#endif // ____FIVector_1_Windows__CStorage__CStreams__CIBuffer_INTERFACE_DEFINED__
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

typedef enum __x_ABI_CWindows_CDevices_CPrinters_CIppAttributeErrorReason __x_ABI_CWindows_CDevices_CPrinters_CIppAttributeErrorReason;

typedef enum __x_ABI_CWindows_CDevices_CPrinters_CIppAttributeValueKind __x_ABI_CWindows_CDevices_CPrinters_CIppAttributeValueKind;

typedef enum __x_ABI_CWindows_CDevices_CPrinters_CIppResolutionUnit __x_ABI_CWindows_CDevices_CPrinters_CIppResolutionUnit;

/*
 *
 * Struct Windows.Devices.Printers.IppAttributeErrorReason
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
enum __x_ABI_CWindows_CDevices_CPrinters_CIppAttributeErrorReason
{
    IppAttributeErrorReason_RequestEntityTooLarge = 0,
    IppAttributeErrorReason_AttributeNotSupported = 1,
    IppAttributeErrorReason_AttributeValuesNotSupported = 2,
    IppAttributeErrorReason_AttributeNotSettable = 3,
    IppAttributeErrorReason_ConflictingAttributes = 4,
};
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Struct Windows.Devices.Printers.IppAttributeValueKind
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
enum __x_ABI_CWindows_CDevices_CPrinters_CIppAttributeValueKind
{
    IppAttributeValueKind_Unsupported = 0,
    IppAttributeValueKind_Unknown = 1,
    IppAttributeValueKind_NoValue = 2,
    IppAttributeValueKind_Integer = 3,
    IppAttributeValueKind_Boolean = 4,
    IppAttributeValueKind_Enum = 5,
    IppAttributeValueKind_OctetString = 6,
    IppAttributeValueKind_DateTime = 7,
    IppAttributeValueKind_Resolution = 8,
    IppAttributeValueKind_RangeOfInteger = 9,
    IppAttributeValueKind_Collection = 10,
    IppAttributeValueKind_TextWithLanguage = 11,
    IppAttributeValueKind_NameWithLanguage = 12,
    IppAttributeValueKind_TextWithoutLanguage = 13,
    IppAttributeValueKind_NameWithoutLanguage = 14,
    IppAttributeValueKind_Keyword = 15,
    IppAttributeValueKind_Uri = 16,
    IppAttributeValueKind_UriSchema = 17,
    IppAttributeValueKind_Charset = 18,
    IppAttributeValueKind_NaturalLanguage = 19,
    IppAttributeValueKind_MimeMediaType = 20,
};
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Struct Windows.Devices.Printers.IppResolutionUnit
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
enum __x_ABI_CWindows_CDevices_CPrinters_CIppResolutionUnit
{
    IppResolutionUnit_DotsPerInch = 0,
    IppResolutionUnit_DotsPerCentimeter = 1,
};
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Interface Windows.Devices.Printers.IIppAttributeError
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Interface is a part of the implementation of type Windows.Devices.Printers.IppAttributeError
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeError_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeError_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Devices_Printers_IIppAttributeError[] = L"Windows.Devices.Printers.IIppAttributeError";
typedef struct __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeErrorVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeError* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeError* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeError* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeError* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeError* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeError* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Reason)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeError* This,
        enum __x_ABI_CWindows_CDevices_CPrinters_CIppAttributeErrorReason* value);
    HRESULT (STDMETHODCALLTYPE* get_ExtendedError)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeError* This,
        HRESULT* value);
    HRESULT (STDMETHODCALLTYPE* GetUnsupportedValues)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeError* This,
        __FIVectorView_1_Windows__CDevices__CPrinters__CIppAttributeValue** result);

    END_INTERFACE
} __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeErrorVtbl;

interface __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeError
{
    CONST_VTBL struct __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeErrorVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeError_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeError_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeError_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeError_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeError_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeError_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeError_get_Reason(This, value) \
    ((This)->lpVtbl->get_Reason(This, value))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeError_get_ExtendedError(This, value) \
    ((This)->lpVtbl->get_ExtendedError(This, value))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeError_GetUnsupportedValues(This, result) \
    ((This)->lpVtbl->GetUnsupportedValues(This, result))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeError;
#endif /* !defined(____x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeError_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Interface Windows.Devices.Printers.IIppAttributeValue
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Interface is a part of the implementation of type Windows.Devices.Printers.IppAttributeValue
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Devices_Printers_IIppAttributeValue[] = L"Windows.Devices.Printers.IIppAttributeValue";
typedef struct __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Kind)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue* This,
        enum __x_ABI_CWindows_CDevices_CPrinters_CIppAttributeValueKind* value);
    HRESULT (STDMETHODCALLTYPE* GetIntegerArray)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue* This,
        __FIVector_1_int** result);
    HRESULT (STDMETHODCALLTYPE* GetBooleanArray)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue* This,
        __FIVector_1_boolean** result);
    HRESULT (STDMETHODCALLTYPE* GetEnumArray)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue* This,
        __FIVector_1_int** result);
    HRESULT (STDMETHODCALLTYPE* GetOctetStringArray)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue* This,
        __FIVector_1_Windows__CStorage__CStreams__CIBuffer** result);
    HRESULT (STDMETHODCALLTYPE* GetDateTimeArray)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue* This,
        __FIVector_1_Windows__CFoundation__CDateTime** result);
    HRESULT (STDMETHODCALLTYPE* GetResolutionArray)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue* This,
        __FIVector_1_Windows__CDevices__CPrinters__CIppResolution** result);
    HRESULT (STDMETHODCALLTYPE* GetRangeOfIntegerArray)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue* This,
        __FIVector_1_Windows__CDevices__CPrinters__CIppIntegerRange** result);
    HRESULT (STDMETHODCALLTYPE* GetCollectionArray)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue* This,
        __FIVector_1___FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue** result);
    HRESULT (STDMETHODCALLTYPE* GetTextWithLanguageArray)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue* This,
        __FIVector_1_Windows__CDevices__CPrinters__CIppTextWithLanguage** result);
    HRESULT (STDMETHODCALLTYPE* GetNameWithLanguageArray)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue* This,
        __FIVector_1_Windows__CDevices__CPrinters__CIppTextWithLanguage** result);
    HRESULT (STDMETHODCALLTYPE* GetTextWithoutLanguageArray)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue* This,
        __FIVector_1_HSTRING** result);
    HRESULT (STDMETHODCALLTYPE* GetNameWithoutLanguageArray)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue* This,
        __FIVector_1_HSTRING** result);
    HRESULT (STDMETHODCALLTYPE* GetKeywordArray)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue* This,
        __FIVector_1_HSTRING** result);
    HRESULT (STDMETHODCALLTYPE* GetUriArray)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue* This,
        __FIVector_1_Windows__CFoundation__CUri** result);
    HRESULT (STDMETHODCALLTYPE* GetUriSchemaArray)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue* This,
        __FIVector_1_HSTRING** result);
    HRESULT (STDMETHODCALLTYPE* GetCharsetArray)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue* This,
        __FIVector_1_HSTRING** result);
    HRESULT (STDMETHODCALLTYPE* GetNaturalLanguageArray)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue* This,
        __FIVector_1_HSTRING** result);
    HRESULT (STDMETHODCALLTYPE* GetMimeMediaTypeArray)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue* This,
        __FIVector_1_HSTRING** result);

    END_INTERFACE
} __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueVtbl;

interface __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue
{
    CONST_VTBL struct __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue_get_Kind(This, value) \
    ((This)->lpVtbl->get_Kind(This, value))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue_GetIntegerArray(This, result) \
    ((This)->lpVtbl->GetIntegerArray(This, result))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue_GetBooleanArray(This, result) \
    ((This)->lpVtbl->GetBooleanArray(This, result))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue_GetEnumArray(This, result) \
    ((This)->lpVtbl->GetEnumArray(This, result))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue_GetOctetStringArray(This, result) \
    ((This)->lpVtbl->GetOctetStringArray(This, result))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue_GetDateTimeArray(This, result) \
    ((This)->lpVtbl->GetDateTimeArray(This, result))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue_GetResolutionArray(This, result) \
    ((This)->lpVtbl->GetResolutionArray(This, result))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue_GetRangeOfIntegerArray(This, result) \
    ((This)->lpVtbl->GetRangeOfIntegerArray(This, result))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue_GetCollectionArray(This, result) \
    ((This)->lpVtbl->GetCollectionArray(This, result))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue_GetTextWithLanguageArray(This, result) \
    ((This)->lpVtbl->GetTextWithLanguageArray(This, result))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue_GetNameWithLanguageArray(This, result) \
    ((This)->lpVtbl->GetNameWithLanguageArray(This, result))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue_GetTextWithoutLanguageArray(This, result) \
    ((This)->lpVtbl->GetTextWithoutLanguageArray(This, result))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue_GetNameWithoutLanguageArray(This, result) \
    ((This)->lpVtbl->GetNameWithoutLanguageArray(This, result))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue_GetKeywordArray(This, result) \
    ((This)->lpVtbl->GetKeywordArray(This, result))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue_GetUriArray(This, result) \
    ((This)->lpVtbl->GetUriArray(This, result))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue_GetUriSchemaArray(This, result) \
    ((This)->lpVtbl->GetUriSchemaArray(This, result))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue_GetCharsetArray(This, result) \
    ((This)->lpVtbl->GetCharsetArray(This, result))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue_GetNaturalLanguageArray(This, result) \
    ((This)->lpVtbl->GetNaturalLanguageArray(This, result))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue_GetMimeMediaTypeArray(This, result) \
    ((This)->lpVtbl->GetMimeMediaTypeArray(This, result))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue;
#endif /* !defined(____x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Interface Windows.Devices.Printers.IIppAttributeValueStatics
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Interface is a part of the implementation of type Windows.Devices.Printers.IppAttributeValue
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Devices_Printers_IIppAttributeValueStatics[] = L"Windows.Devices.Printers.IIppAttributeValueStatics";
typedef struct __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStaticsVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* CreateUnsupported)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics* This,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue** result);
    HRESULT (STDMETHODCALLTYPE* CreateUnknown)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics* This,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue** result);
    HRESULT (STDMETHODCALLTYPE* CreateNoValue)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics* This,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue** result);
    HRESULT (STDMETHODCALLTYPE* CreateInteger)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics* This,
        INT32 value,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue** result);
    HRESULT (STDMETHODCALLTYPE* CreateIntegerArray)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics* This,
        __FIIterable_1_int* values,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue** result);
    HRESULT (STDMETHODCALLTYPE* CreateBoolean)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics* This,
        boolean value,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue** result);
    HRESULT (STDMETHODCALLTYPE* CreateBooleanArray)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics* This,
        __FIIterable_1_boolean* values,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue** result);
    HRESULT (STDMETHODCALLTYPE* CreateEnum)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics* This,
        INT32 value,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue** result);
    HRESULT (STDMETHODCALLTYPE* CreateEnumArray)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics* This,
        __FIIterable_1_int* values,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue** result);
    HRESULT (STDMETHODCALLTYPE* CreateOctetString)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics* This,
        __x_ABI_CWindows_CStorage_CStreams_CIBuffer* value,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue** result);
    HRESULT (STDMETHODCALLTYPE* CreateOctetStringArray)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics* This,
        __FIIterable_1_Windows__CStorage__CStreams__CIBuffer* values,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue** result);
    HRESULT (STDMETHODCALLTYPE* CreateDateTime)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics* This,
        struct __x_ABI_CWindows_CFoundation_CDateTime value,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue** result);
    HRESULT (STDMETHODCALLTYPE* CreateDateTimeArray)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics* This,
        __FIIterable_1_Windows__CFoundation__CDateTime* values,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue** result);
    HRESULT (STDMETHODCALLTYPE* CreateResolution)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics* This,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppResolution* value,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue** result);
    HRESULT (STDMETHODCALLTYPE* CreateResolutionArray)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics* This,
        __FIIterable_1_Windows__CDevices__CPrinters__CIppResolution* values,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue** result);
    HRESULT (STDMETHODCALLTYPE* CreateRangeOfInteger)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics* This,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRange* value,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue** result);
    HRESULT (STDMETHODCALLTYPE* CreateRangeOfIntegerArray)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics* This,
        __FIIterable_1_Windows__CDevices__CPrinters__CIppIntegerRange* values,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue** result);
    HRESULT (STDMETHODCALLTYPE* CreateCollection)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics* This,
        __FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* memberAttributes,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue** result);
    HRESULT (STDMETHODCALLTYPE* CreateCollectionArray)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics* This,
        __FIIterable_1___FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* memberAttributesArray,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue** result);
    HRESULT (STDMETHODCALLTYPE* CreateTextWithLanguage)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics* This,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguage* value,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue** result);
    HRESULT (STDMETHODCALLTYPE* CreateTextWithLanguageArray)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics* This,
        __FIIterable_1_Windows__CDevices__CPrinters__CIppTextWithLanguage* values,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue** result);
    HRESULT (STDMETHODCALLTYPE* CreateNameWithLanguage)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics* This,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguage* value,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue** result);
    HRESULT (STDMETHODCALLTYPE* CreateNameWithLanguageArray)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics* This,
        __FIIterable_1_Windows__CDevices__CPrinters__CIppTextWithLanguage* values,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue** result);
    HRESULT (STDMETHODCALLTYPE* CreateTextWithoutLanguage)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics* This,
        HSTRING value,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue** result);
    HRESULT (STDMETHODCALLTYPE* CreateTextWithoutLanguageArray)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics* This,
        __FIIterable_1_HSTRING* values,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue** result);
    HRESULT (STDMETHODCALLTYPE* CreateNameWithoutLanguage)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics* This,
        HSTRING value,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue** result);
    HRESULT (STDMETHODCALLTYPE* CreateNameWithoutLanguageArray)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics* This,
        __FIIterable_1_HSTRING* values,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue** result);
    HRESULT (STDMETHODCALLTYPE* CreateKeyword)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics* This,
        HSTRING value,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue** result);
    HRESULT (STDMETHODCALLTYPE* CreateKeywordArray)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics* This,
        __FIIterable_1_HSTRING* values,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue** result);
    HRESULT (STDMETHODCALLTYPE* CreateUri)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics* This,
        __x_ABI_CWindows_CFoundation_CIUriRuntimeClass* value,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue** result);
    HRESULT (STDMETHODCALLTYPE* CreateUriArray)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics* This,
        __FIIterable_1_Windows__CFoundation__CUri* values,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue** result);
    HRESULT (STDMETHODCALLTYPE* CreateUriSchema)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics* This,
        HSTRING value,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue** result);
    HRESULT (STDMETHODCALLTYPE* CreateUriSchemaArray)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics* This,
        __FIIterable_1_HSTRING* values,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue** result);
    HRESULT (STDMETHODCALLTYPE* CreateCharset)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics* This,
        HSTRING value,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue** result);
    HRESULT (STDMETHODCALLTYPE* CreateCharsetArray)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics* This,
        __FIIterable_1_HSTRING* values,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue** result);
    HRESULT (STDMETHODCALLTYPE* CreateNaturalLanguage)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics* This,
        HSTRING value,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue** result);
    HRESULT (STDMETHODCALLTYPE* CreateNaturalLanguageArray)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics* This,
        __FIIterable_1_HSTRING* values,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue** result);
    HRESULT (STDMETHODCALLTYPE* CreateMimeMedia)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics* This,
        HSTRING value,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue** result);
    HRESULT (STDMETHODCALLTYPE* CreateMimeMediaArray)(__x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics* This,
        __FIIterable_1_HSTRING* values,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue** result);

    END_INTERFACE
} __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStaticsVtbl;

interface __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics
{
    CONST_VTBL struct __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStaticsVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics_CreateUnsupported(This, result) \
    ((This)->lpVtbl->CreateUnsupported(This, result))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics_CreateUnknown(This, result) \
    ((This)->lpVtbl->CreateUnknown(This, result))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics_CreateNoValue(This, result) \
    ((This)->lpVtbl->CreateNoValue(This, result))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics_CreateInteger(This, value, result) \
    ((This)->lpVtbl->CreateInteger(This, value, result))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics_CreateIntegerArray(This, values, result) \
    ((This)->lpVtbl->CreateIntegerArray(This, values, result))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics_CreateBoolean(This, value, result) \
    ((This)->lpVtbl->CreateBoolean(This, value, result))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics_CreateBooleanArray(This, values, result) \
    ((This)->lpVtbl->CreateBooleanArray(This, values, result))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics_CreateEnum(This, value, result) \
    ((This)->lpVtbl->CreateEnum(This, value, result))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics_CreateEnumArray(This, values, result) \
    ((This)->lpVtbl->CreateEnumArray(This, values, result))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics_CreateOctetString(This, value, result) \
    ((This)->lpVtbl->CreateOctetString(This, value, result))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics_CreateOctetStringArray(This, values, result) \
    ((This)->lpVtbl->CreateOctetStringArray(This, values, result))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics_CreateDateTime(This, value, result) \
    ((This)->lpVtbl->CreateDateTime(This, value, result))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics_CreateDateTimeArray(This, values, result) \
    ((This)->lpVtbl->CreateDateTimeArray(This, values, result))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics_CreateResolution(This, value, result) \
    ((This)->lpVtbl->CreateResolution(This, value, result))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics_CreateResolutionArray(This, values, result) \
    ((This)->lpVtbl->CreateResolutionArray(This, values, result))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics_CreateRangeOfInteger(This, value, result) \
    ((This)->lpVtbl->CreateRangeOfInteger(This, value, result))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics_CreateRangeOfIntegerArray(This, values, result) \
    ((This)->lpVtbl->CreateRangeOfIntegerArray(This, values, result))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics_CreateCollection(This, memberAttributes, result) \
    ((This)->lpVtbl->CreateCollection(This, memberAttributes, result))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics_CreateCollectionArray(This, memberAttributesArray, result) \
    ((This)->lpVtbl->CreateCollectionArray(This, memberAttributesArray, result))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics_CreateTextWithLanguage(This, value, result) \
    ((This)->lpVtbl->CreateTextWithLanguage(This, value, result))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics_CreateTextWithLanguageArray(This, values, result) \
    ((This)->lpVtbl->CreateTextWithLanguageArray(This, values, result))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics_CreateNameWithLanguage(This, value, result) \
    ((This)->lpVtbl->CreateNameWithLanguage(This, value, result))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics_CreateNameWithLanguageArray(This, values, result) \
    ((This)->lpVtbl->CreateNameWithLanguageArray(This, values, result))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics_CreateTextWithoutLanguage(This, value, result) \
    ((This)->lpVtbl->CreateTextWithoutLanguage(This, value, result))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics_CreateTextWithoutLanguageArray(This, values, result) \
    ((This)->lpVtbl->CreateTextWithoutLanguageArray(This, values, result))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics_CreateNameWithoutLanguage(This, value, result) \
    ((This)->lpVtbl->CreateNameWithoutLanguage(This, value, result))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics_CreateNameWithoutLanguageArray(This, values, result) \
    ((This)->lpVtbl->CreateNameWithoutLanguageArray(This, values, result))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics_CreateKeyword(This, value, result) \
    ((This)->lpVtbl->CreateKeyword(This, value, result))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics_CreateKeywordArray(This, values, result) \
    ((This)->lpVtbl->CreateKeywordArray(This, values, result))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics_CreateUri(This, value, result) \
    ((This)->lpVtbl->CreateUri(This, value, result))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics_CreateUriArray(This, values, result) \
    ((This)->lpVtbl->CreateUriArray(This, values, result))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics_CreateUriSchema(This, value, result) \
    ((This)->lpVtbl->CreateUriSchema(This, value, result))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics_CreateUriSchemaArray(This, values, result) \
    ((This)->lpVtbl->CreateUriSchemaArray(This, values, result))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics_CreateCharset(This, value, result) \
    ((This)->lpVtbl->CreateCharset(This, value, result))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics_CreateCharsetArray(This, values, result) \
    ((This)->lpVtbl->CreateCharsetArray(This, values, result))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics_CreateNaturalLanguage(This, value, result) \
    ((This)->lpVtbl->CreateNaturalLanguage(This, value, result))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics_CreateNaturalLanguageArray(This, values, result) \
    ((This)->lpVtbl->CreateNaturalLanguageArray(This, values, result))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics_CreateMimeMedia(This, value, result) \
    ((This)->lpVtbl->CreateMimeMedia(This, value, result))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics_CreateMimeMediaArray(This, values, result) \
    ((This)->lpVtbl->CreateMimeMediaArray(This, values, result))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics;
#endif /* !defined(____x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValueStatics_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Interface Windows.Devices.Printers.IIppIntegerRange
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Interface is a part of the implementation of type Windows.Devices.Printers.IppIntegerRange
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRange_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRange_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Devices_Printers_IIppIntegerRange[] = L"Windows.Devices.Printers.IIppIntegerRange";
typedef struct __x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRangeVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRange* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRange* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRange* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRange* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRange* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRange* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Start)(__x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRange* This,
        INT32* value);
    HRESULT (STDMETHODCALLTYPE* get_End)(__x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRange* This,
        INT32* value);

    END_INTERFACE
} __x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRangeVtbl;

interface __x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRange
{
    CONST_VTBL struct __x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRangeVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRange_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRange_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRange_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRange_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRange_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRange_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRange_get_Start(This, value) \
    ((This)->lpVtbl->get_Start(This, value))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRange_get_End(This, value) \
    ((This)->lpVtbl->get_End(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRange;
#endif /* !defined(____x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRange_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Interface Windows.Devices.Printers.IIppIntegerRangeFactory
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Interface is a part of the implementation of type Windows.Devices.Printers.IppIntegerRange
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRangeFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRangeFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Devices_Printers_IIppIntegerRangeFactory[] = L"Windows.Devices.Printers.IIppIntegerRangeFactory";
typedef struct __x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRangeFactoryVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRangeFactory* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRangeFactory* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRangeFactory* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRangeFactory* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRangeFactory* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRangeFactory* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* CreateInstance)(__x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRangeFactory* This,
        INT32 start,
        INT32 end,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRange** value);

    END_INTERFACE
} __x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRangeFactoryVtbl;

interface __x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRangeFactory
{
    CONST_VTBL struct __x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRangeFactoryVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRangeFactory_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRangeFactory_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRangeFactory_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRangeFactory_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRangeFactory_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRangeFactory_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRangeFactory_CreateInstance(This, start, end, value) \
    ((This)->lpVtbl->CreateInstance(This, start, end, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRangeFactory;
#endif /* !defined(____x_ABI_CWindows_CDevices_CPrinters_CIIppIntegerRangeFactory_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Interface Windows.Devices.Printers.IIppPrintDevice
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Interface is a part of the implementation of type Windows.Devices.Printers.IppPrintDevice
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____x_ABI_CWindows_CDevices_CPrinters_CIIppPrintDevice_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CDevices_CPrinters_CIIppPrintDevice_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Devices_Printers_IIppPrintDevice[] = L"Windows.Devices.Printers.IIppPrintDevice";
typedef struct __x_ABI_CWindows_CDevices_CPrinters_CIIppPrintDeviceVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CDevices_CPrinters_CIIppPrintDevice* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CDevices_CPrinters_CIIppPrintDevice* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CDevices_CPrinters_CIIppPrintDevice* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CDevices_CPrinters_CIIppPrintDevice* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CDevices_CPrinters_CIIppPrintDevice* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CDevices_CPrinters_CIIppPrintDevice* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_PrinterName)(__x_ABI_CWindows_CDevices_CPrinters_CIIppPrintDevice* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* get_PrinterUri)(__x_ABI_CWindows_CDevices_CPrinters_CIIppPrintDevice* This,
        __x_ABI_CWindows_CFoundation_CIUriRuntimeClass** value);
    HRESULT (STDMETHODCALLTYPE* GetPrinterAttributesAsBuffer)(__x_ABI_CWindows_CDevices_CPrinters_CIIppPrintDevice* This,
        __FIIterable_1_HSTRING* attributeNames,
        __x_ABI_CWindows_CStorage_CStreams_CIBuffer** result);
    HRESULT (STDMETHODCALLTYPE* GetPrinterAttributes)(__x_ABI_CWindows_CDevices_CPrinters_CIIppPrintDevice* This,
        __FIIterable_1_HSTRING* attributeNames,
        __FIMap_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue** result);
    HRESULT (STDMETHODCALLTYPE* SetPrinterAttributesFromBuffer)(__x_ABI_CWindows_CDevices_CPrinters_CIIppPrintDevice* This,
        __x_ABI_CWindows_CStorage_CStreams_CIBuffer* printerAttributesBuffer,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppSetAttributesResult** result);
    HRESULT (STDMETHODCALLTYPE* SetPrinterAttributes)(__x_ABI_CWindows_CDevices_CPrinters_CIIppPrintDevice* This,
        __FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* printerAttributes,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppSetAttributesResult** result);

    END_INTERFACE
} __x_ABI_CWindows_CDevices_CPrinters_CIIppPrintDeviceVtbl;

interface __x_ABI_CWindows_CDevices_CPrinters_CIIppPrintDevice
{
    CONST_VTBL struct __x_ABI_CWindows_CDevices_CPrinters_CIIppPrintDeviceVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppPrintDevice_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppPrintDevice_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppPrintDevice_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppPrintDevice_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppPrintDevice_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppPrintDevice_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppPrintDevice_get_PrinterName(This, value) \
    ((This)->lpVtbl->get_PrinterName(This, value))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppPrintDevice_get_PrinterUri(This, value) \
    ((This)->lpVtbl->get_PrinterUri(This, value))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppPrintDevice_GetPrinterAttributesAsBuffer(This, attributeNames, result) \
    ((This)->lpVtbl->GetPrinterAttributesAsBuffer(This, attributeNames, result))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppPrintDevice_GetPrinterAttributes(This, attributeNames, result) \
    ((This)->lpVtbl->GetPrinterAttributes(This, attributeNames, result))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppPrintDevice_SetPrinterAttributesFromBuffer(This, printerAttributesBuffer, result) \
    ((This)->lpVtbl->SetPrinterAttributesFromBuffer(This, printerAttributesBuffer, result))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppPrintDevice_SetPrinterAttributes(This, printerAttributes, result) \
    ((This)->lpVtbl->SetPrinterAttributes(This, printerAttributes, result))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CDevices_CPrinters_CIIppPrintDevice;
#endif /* !defined(____x_ABI_CWindows_CDevices_CPrinters_CIIppPrintDevice_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Interface Windows.Devices.Printers.IIppResolution
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Interface is a part of the implementation of type Windows.Devices.Printers.IppResolution
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____x_ABI_CWindows_CDevices_CPrinters_CIIppResolution_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CDevices_CPrinters_CIIppResolution_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Devices_Printers_IIppResolution[] = L"Windows.Devices.Printers.IIppResolution";
typedef struct __x_ABI_CWindows_CDevices_CPrinters_CIIppResolutionVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CDevices_CPrinters_CIIppResolution* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CDevices_CPrinters_CIIppResolution* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CDevices_CPrinters_CIIppResolution* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CDevices_CPrinters_CIIppResolution* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CDevices_CPrinters_CIIppResolution* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CDevices_CPrinters_CIIppResolution* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Width)(__x_ABI_CWindows_CDevices_CPrinters_CIIppResolution* This,
        INT32* value);
    HRESULT (STDMETHODCALLTYPE* get_Height)(__x_ABI_CWindows_CDevices_CPrinters_CIIppResolution* This,
        INT32* value);
    HRESULT (STDMETHODCALLTYPE* get_Unit)(__x_ABI_CWindows_CDevices_CPrinters_CIIppResolution* This,
        enum __x_ABI_CWindows_CDevices_CPrinters_CIppResolutionUnit* value);

    END_INTERFACE
} __x_ABI_CWindows_CDevices_CPrinters_CIIppResolutionVtbl;

interface __x_ABI_CWindows_CDevices_CPrinters_CIIppResolution
{
    CONST_VTBL struct __x_ABI_CWindows_CDevices_CPrinters_CIIppResolutionVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppResolution_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppResolution_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppResolution_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppResolution_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppResolution_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppResolution_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppResolution_get_Width(This, value) \
    ((This)->lpVtbl->get_Width(This, value))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppResolution_get_Height(This, value) \
    ((This)->lpVtbl->get_Height(This, value))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppResolution_get_Unit(This, value) \
    ((This)->lpVtbl->get_Unit(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CDevices_CPrinters_CIIppResolution;
#endif /* !defined(____x_ABI_CWindows_CDevices_CPrinters_CIIppResolution_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Interface Windows.Devices.Printers.IIppResolutionFactory
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Interface is a part of the implementation of type Windows.Devices.Printers.IppResolution
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____x_ABI_CWindows_CDevices_CPrinters_CIIppResolutionFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CDevices_CPrinters_CIIppResolutionFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Devices_Printers_IIppResolutionFactory[] = L"Windows.Devices.Printers.IIppResolutionFactory";
typedef struct __x_ABI_CWindows_CDevices_CPrinters_CIIppResolutionFactoryVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CDevices_CPrinters_CIIppResolutionFactory* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CDevices_CPrinters_CIIppResolutionFactory* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CDevices_CPrinters_CIIppResolutionFactory* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CDevices_CPrinters_CIIppResolutionFactory* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CDevices_CPrinters_CIIppResolutionFactory* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CDevices_CPrinters_CIIppResolutionFactory* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* CreateInstance)(__x_ABI_CWindows_CDevices_CPrinters_CIIppResolutionFactory* This,
        INT32 width,
        INT32 height,
        enum __x_ABI_CWindows_CDevices_CPrinters_CIppResolutionUnit unit,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppResolution** value);

    END_INTERFACE
} __x_ABI_CWindows_CDevices_CPrinters_CIIppResolutionFactoryVtbl;

interface __x_ABI_CWindows_CDevices_CPrinters_CIIppResolutionFactory
{
    CONST_VTBL struct __x_ABI_CWindows_CDevices_CPrinters_CIIppResolutionFactoryVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppResolutionFactory_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppResolutionFactory_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppResolutionFactory_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppResolutionFactory_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppResolutionFactory_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppResolutionFactory_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppResolutionFactory_CreateInstance(This, width, height, unit, value) \
    ((This)->lpVtbl->CreateInstance(This, width, height, unit, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CDevices_CPrinters_CIIppResolutionFactory;
#endif /* !defined(____x_ABI_CWindows_CDevices_CPrinters_CIIppResolutionFactory_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Interface Windows.Devices.Printers.IIppSetAttributesResult
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Interface is a part of the implementation of type Windows.Devices.Printers.IppSetAttributesResult
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____x_ABI_CWindows_CDevices_CPrinters_CIIppSetAttributesResult_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CDevices_CPrinters_CIIppSetAttributesResult_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Devices_Printers_IIppSetAttributesResult[] = L"Windows.Devices.Printers.IIppSetAttributesResult";
typedef struct __x_ABI_CWindows_CDevices_CPrinters_CIIppSetAttributesResultVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CDevices_CPrinters_CIIppSetAttributesResult* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CDevices_CPrinters_CIIppSetAttributesResult* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CDevices_CPrinters_CIIppSetAttributesResult* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CDevices_CPrinters_CIIppSetAttributesResult* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CDevices_CPrinters_CIIppSetAttributesResult* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CDevices_CPrinters_CIIppSetAttributesResult* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Succeeded)(__x_ABI_CWindows_CDevices_CPrinters_CIIppSetAttributesResult* This,
        boolean* value);
    HRESULT (STDMETHODCALLTYPE* get_AttributeErrors)(__x_ABI_CWindows_CDevices_CPrinters_CIIppSetAttributesResult* This,
        __FIMapView_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeError** value);

    END_INTERFACE
} __x_ABI_CWindows_CDevices_CPrinters_CIIppSetAttributesResultVtbl;

interface __x_ABI_CWindows_CDevices_CPrinters_CIIppSetAttributesResult
{
    CONST_VTBL struct __x_ABI_CWindows_CDevices_CPrinters_CIIppSetAttributesResultVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppSetAttributesResult_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppSetAttributesResult_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppSetAttributesResult_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppSetAttributesResult_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppSetAttributesResult_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppSetAttributesResult_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppSetAttributesResult_get_Succeeded(This, value) \
    ((This)->lpVtbl->get_Succeeded(This, value))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppSetAttributesResult_get_AttributeErrors(This, value) \
    ((This)->lpVtbl->get_AttributeErrors(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CDevices_CPrinters_CIIppSetAttributesResult;
#endif /* !defined(____x_ABI_CWindows_CDevices_CPrinters_CIIppSetAttributesResult_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Interface Windows.Devices.Printers.IIppTextWithLanguage
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Interface is a part of the implementation of type Windows.Devices.Printers.IppTextWithLanguage
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguage_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguage_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Devices_Printers_IIppTextWithLanguage[] = L"Windows.Devices.Printers.IIppTextWithLanguage";
typedef struct __x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguageVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguage* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguage* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguage* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguage* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguage* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguage* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Language)(__x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguage* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* get_Value)(__x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguage* This,
        HSTRING* value);

    END_INTERFACE
} __x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguageVtbl;

interface __x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguage
{
    CONST_VTBL struct __x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguageVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguage_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguage_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguage_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguage_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguage_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguage_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguage_get_Language(This, value) \
    ((This)->lpVtbl->get_Language(This, value))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguage_get_Value(This, value) \
    ((This)->lpVtbl->get_Value(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguage;
#endif /* !defined(____x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguage_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Interface Windows.Devices.Printers.IIppTextWithLanguageFactory
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Interface is a part of the implementation of type Windows.Devices.Printers.IppTextWithLanguage
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguageFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguageFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Devices_Printers_IIppTextWithLanguageFactory[] = L"Windows.Devices.Printers.IIppTextWithLanguageFactory";
typedef struct __x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguageFactoryVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguageFactory* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguageFactory* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguageFactory* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguageFactory* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguageFactory* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguageFactory* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* CreateInstance)(__x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguageFactory* This,
        HSTRING language,
        HSTRING text,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguage** value);

    END_INTERFACE
} __x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguageFactoryVtbl;

interface __x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguageFactory
{
    CONST_VTBL struct __x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguageFactoryVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguageFactory_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguageFactory_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguageFactory_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguageFactory_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguageFactory_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguageFactory_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguageFactory_CreateInstance(This, language, text, value) \
    ((This)->lpVtbl->CreateInstance(This, language, text, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguageFactory;
#endif /* !defined(____x_ABI_CWindows_CDevices_CPrinters_CIIppTextWithLanguageFactory_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Interface Windows.Devices.Printers.IPrint3DDevice
 *
 * Introduced to Windows.Devices.Printers.PrintersContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Devices.Printers.Print3DDevice
 *
 */
#if WINDOWS_DEVICES_PRINTERS_PRINTERSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CDevices_CPrinters_CIPrint3DDevice_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CDevices_CPrinters_CIPrint3DDevice_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Devices_Printers_IPrint3DDevice[] = L"Windows.Devices.Printers.IPrint3DDevice";
typedef struct __x_ABI_CWindows_CDevices_CPrinters_CIPrint3DDeviceVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CDevices_CPrinters_CIPrint3DDevice* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CDevices_CPrinters_CIPrint3DDevice* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CDevices_CPrinters_CIPrint3DDevice* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CDevices_CPrinters_CIPrint3DDevice* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CDevices_CPrinters_CIPrint3DDevice* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CDevices_CPrinters_CIPrint3DDevice* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_PrintSchema)(__x_ABI_CWindows_CDevices_CPrinters_CIPrint3DDevice* This,
        __x_ABI_CWindows_CDevices_CPrinters_CIPrintSchema** value);

    END_INTERFACE
} __x_ABI_CWindows_CDevices_CPrinters_CIPrint3DDeviceVtbl;

interface __x_ABI_CWindows_CDevices_CPrinters_CIPrint3DDevice
{
    CONST_VTBL struct __x_ABI_CWindows_CDevices_CPrinters_CIPrint3DDeviceVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CDevices_CPrinters_CIPrint3DDevice_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CDevices_CPrinters_CIPrint3DDevice_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CDevices_CPrinters_CIPrint3DDevice_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CDevices_CPrinters_CIPrint3DDevice_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CDevices_CPrinters_CIPrint3DDevice_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CDevices_CPrinters_CIPrint3DDevice_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CDevices_CPrinters_CIPrint3DDevice_get_PrintSchema(This, value) \
    ((This)->lpVtbl->get_PrintSchema(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CDevices_CPrinters_CIPrint3DDevice;
#endif /* !defined(____x_ABI_CWindows_CDevices_CPrinters_CIPrint3DDevice_INTERFACE_DEFINED__) */
#endif // WINDOWS_DEVICES_PRINTERS_PRINTERSCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Devices.Printers.IPrint3DDeviceStatics
 *
 * Introduced to Windows.Devices.Printers.PrintersContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Devices.Printers.Print3DDevice
 *
 */
#if WINDOWS_DEVICES_PRINTERS_PRINTERSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CDevices_CPrinters_CIPrint3DDeviceStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CDevices_CPrinters_CIPrint3DDeviceStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Devices_Printers_IPrint3DDeviceStatics[] = L"Windows.Devices.Printers.IPrint3DDeviceStatics";
typedef struct __x_ABI_CWindows_CDevices_CPrinters_CIPrint3DDeviceStaticsVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CDevices_CPrinters_CIPrint3DDeviceStatics* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CDevices_CPrinters_CIPrint3DDeviceStatics* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CDevices_CPrinters_CIPrint3DDeviceStatics* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CDevices_CPrinters_CIPrint3DDeviceStatics* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CDevices_CPrinters_CIPrint3DDeviceStatics* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CDevices_CPrinters_CIPrint3DDeviceStatics* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* FromIdAsync)(__x_ABI_CWindows_CDevices_CPrinters_CIPrint3DDeviceStatics* This,
        HSTRING deviceId,
        __FIAsyncOperation_1_Windows__CDevices__CPrinters__CPrint3DDevice** operation);
    HRESULT (STDMETHODCALLTYPE* GetDeviceSelector)(__x_ABI_CWindows_CDevices_CPrinters_CIPrint3DDeviceStatics* This,
        HSTRING* result);

    END_INTERFACE
} __x_ABI_CWindows_CDevices_CPrinters_CIPrint3DDeviceStaticsVtbl;

interface __x_ABI_CWindows_CDevices_CPrinters_CIPrint3DDeviceStatics
{
    CONST_VTBL struct __x_ABI_CWindows_CDevices_CPrinters_CIPrint3DDeviceStaticsVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CDevices_CPrinters_CIPrint3DDeviceStatics_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CDevices_CPrinters_CIPrint3DDeviceStatics_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CDevices_CPrinters_CIPrint3DDeviceStatics_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CDevices_CPrinters_CIPrint3DDeviceStatics_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CDevices_CPrinters_CIPrint3DDeviceStatics_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CDevices_CPrinters_CIPrint3DDeviceStatics_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CDevices_CPrinters_CIPrint3DDeviceStatics_FromIdAsync(This, deviceId, operation) \
    ((This)->lpVtbl->FromIdAsync(This, deviceId, operation))

#define __x_ABI_CWindows_CDevices_CPrinters_CIPrint3DDeviceStatics_GetDeviceSelector(This, result) \
    ((This)->lpVtbl->GetDeviceSelector(This, result))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CDevices_CPrinters_CIPrint3DDeviceStatics;
#endif /* !defined(____x_ABI_CWindows_CDevices_CPrinters_CIPrint3DDeviceStatics_INTERFACE_DEFINED__) */
#endif // WINDOWS_DEVICES_PRINTERS_PRINTERSCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Devices.Printers.IPrintSchema
 *
 * Introduced to Windows.Devices.Printers.PrintersContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Devices.Printers.PrintSchema
 *
 */
#if WINDOWS_DEVICES_PRINTERS_PRINTERSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CDevices_CPrinters_CIPrintSchema_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CDevices_CPrinters_CIPrintSchema_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Devices_Printers_IPrintSchema[] = L"Windows.Devices.Printers.IPrintSchema";
typedef struct __x_ABI_CWindows_CDevices_CPrinters_CIPrintSchemaVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CDevices_CPrinters_CIPrintSchema* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CDevices_CPrinters_CIPrintSchema* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CDevices_CPrinters_CIPrintSchema* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CDevices_CPrinters_CIPrintSchema* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CDevices_CPrinters_CIPrintSchema* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CDevices_CPrinters_CIPrintSchema* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* GetDefaultPrintTicketAsync)(__x_ABI_CWindows_CDevices_CPrinters_CIPrintSchema* This,
        __FIAsyncOperation_1_Windows__CStorage__CStreams__CIRandomAccessStreamWithContentType** operation);
    HRESULT (STDMETHODCALLTYPE* GetCapabilitiesAsync)(__x_ABI_CWindows_CDevices_CPrinters_CIPrintSchema* This,
        __x_ABI_CWindows_CStorage_CStreams_CIRandomAccessStreamWithContentType* constrainTicket,
        __FIAsyncOperation_1_Windows__CStorage__CStreams__CIRandomAccessStreamWithContentType** operation);
    HRESULT (STDMETHODCALLTYPE* MergeAndValidateWithDefaultPrintTicketAsync)(__x_ABI_CWindows_CDevices_CPrinters_CIPrintSchema* This,
        __x_ABI_CWindows_CStorage_CStreams_CIRandomAccessStreamWithContentType* deltaTicket,
        __FIAsyncOperation_1_Windows__CStorage__CStreams__CIRandomAccessStreamWithContentType** operation);

    END_INTERFACE
} __x_ABI_CWindows_CDevices_CPrinters_CIPrintSchemaVtbl;

interface __x_ABI_CWindows_CDevices_CPrinters_CIPrintSchema
{
    CONST_VTBL struct __x_ABI_CWindows_CDevices_CPrinters_CIPrintSchemaVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CDevices_CPrinters_CIPrintSchema_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CDevices_CPrinters_CIPrintSchema_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CDevices_CPrinters_CIPrintSchema_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CDevices_CPrinters_CIPrintSchema_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CDevices_CPrinters_CIPrintSchema_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CDevices_CPrinters_CIPrintSchema_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CDevices_CPrinters_CIPrintSchema_GetDefaultPrintTicketAsync(This, operation) \
    ((This)->lpVtbl->GetDefaultPrintTicketAsync(This, operation))

#define __x_ABI_CWindows_CDevices_CPrinters_CIPrintSchema_GetCapabilitiesAsync(This, constrainTicket, operation) \
    ((This)->lpVtbl->GetCapabilitiesAsync(This, constrainTicket, operation))

#define __x_ABI_CWindows_CDevices_CPrinters_CIPrintSchema_MergeAndValidateWithDefaultPrintTicketAsync(This, deltaTicket, operation) \
    ((This)->lpVtbl->MergeAndValidateWithDefaultPrintTicketAsync(This, deltaTicket, operation))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CDevices_CPrinters_CIPrintSchema;
#endif /* !defined(____x_ABI_CWindows_CDevices_CPrinters_CIPrintSchema_INTERFACE_DEFINED__) */
#endif // WINDOWS_DEVICES_PRINTERS_PRINTERSCONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Devices.Printers.IppAttributeError
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Class implements the following interfaces:
 *    Windows.Devices.Printers.IIppAttributeError ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#ifndef RUNTIMECLASS_Windows_Devices_Printers_IppAttributeError_DEFINED
#define RUNTIMECLASS_Windows_Devices_Printers_IppAttributeError_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Devices_Printers_IppAttributeError[] = L"Windows.Devices.Printers.IppAttributeError";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Class Windows.Devices.Printers.IppAttributeValue
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Windows.Devices.Printers.IIppAttributeValueStatics interface starting with version 13.0 of the Windows.Foundation.UniversalApiContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Devices.Printers.IIppAttributeValue ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#ifndef RUNTIMECLASS_Windows_Devices_Printers_IppAttributeValue_DEFINED
#define RUNTIMECLASS_Windows_Devices_Printers_IppAttributeValue_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Devices_Printers_IppAttributeValue[] = L"Windows.Devices.Printers.IppAttributeValue";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Class Windows.Devices.Printers.IppIntegerRange
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via the Windows.Devices.Printers.IIppIntegerRangeFactory interface starting with version 13.0 of the Windows.Foundation.UniversalApiContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Devices.Printers.IIppIntegerRange ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#ifndef RUNTIMECLASS_Windows_Devices_Printers_IppIntegerRange_DEFINED
#define RUNTIMECLASS_Windows_Devices_Printers_IppIntegerRange_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Devices_Printers_IppIntegerRange[] = L"Windows.Devices.Printers.IppIntegerRange";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Class Windows.Devices.Printers.IppPrintDevice
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Class implements the following interfaces:
 *    Windows.Devices.Printers.IIppPrintDevice ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#ifndef RUNTIMECLASS_Windows_Devices_Printers_IppPrintDevice_DEFINED
#define RUNTIMECLASS_Windows_Devices_Printers_IppPrintDevice_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Devices_Printers_IppPrintDevice[] = L"Windows.Devices.Printers.IppPrintDevice";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Class Windows.Devices.Printers.IppResolution
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via the Windows.Devices.Printers.IIppResolutionFactory interface starting with version 13.0 of the Windows.Foundation.UniversalApiContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Devices.Printers.IIppResolution ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#ifndef RUNTIMECLASS_Windows_Devices_Printers_IppResolution_DEFINED
#define RUNTIMECLASS_Windows_Devices_Printers_IppResolution_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Devices_Printers_IppResolution[] = L"Windows.Devices.Printers.IppResolution";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Class Windows.Devices.Printers.IppSetAttributesResult
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Class implements the following interfaces:
 *    Windows.Devices.Printers.IIppSetAttributesResult ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#ifndef RUNTIMECLASS_Windows_Devices_Printers_IppSetAttributesResult_DEFINED
#define RUNTIMECLASS_Windows_Devices_Printers_IppSetAttributesResult_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Devices_Printers_IppSetAttributesResult[] = L"Windows.Devices.Printers.IppSetAttributesResult";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Class Windows.Devices.Printers.IppTextWithLanguage
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via the Windows.Devices.Printers.IIppTextWithLanguageFactory interface starting with version 13.0 of the Windows.Foundation.UniversalApiContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Devices.Printers.IIppTextWithLanguage ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#ifndef RUNTIMECLASS_Windows_Devices_Printers_IppTextWithLanguage_DEFINED
#define RUNTIMECLASS_Windows_Devices_Printers_IppTextWithLanguage_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Devices_Printers_IppTextWithLanguage[] = L"Windows.Devices.Printers.IppTextWithLanguage";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Class Windows.Devices.Printers.Print3DDevice
 *
 * Introduced to Windows.Devices.Printers.PrintersContract in version 1.0
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Windows.Devices.Printers.IPrint3DDeviceStatics interface starting with version 1.0 of the Windows.Devices.Printers.PrintersContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Devices.Printers.IPrint3DDevice ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_DEVICES_PRINTERS_PRINTERSCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Devices_Printers_Print3DDevice_DEFINED
#define RUNTIMECLASS_Windows_Devices_Printers_Print3DDevice_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Devices_Printers_Print3DDevice[] = L"Windows.Devices.Printers.Print3DDevice";
#endif
#endif // WINDOWS_DEVICES_PRINTERS_PRINTERSCONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Devices.Printers.PrintSchema
 *
 * Introduced to Windows.Devices.Printers.PrintersContract in version 1.0
 *
 * Class implements the following interfaces:
 *    Windows.Devices.Printers.IPrintSchema ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_DEVICES_PRINTERS_PRINTERSCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Devices_Printers_PrintSchema_DEFINED
#define RUNTIMECLASS_Windows_Devices_Printers_PrintSchema_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Devices_Printers_PrintSchema[] = L"Windows.Devices.Printers.PrintSchema";
#endif
#endif // WINDOWS_DEVICES_PRINTERS_PRINTERSCONTRACT_VERSION >= 0x10000

#endif // defined(__cplusplus)
#pragma pop_macro("MIDL_CONST_ID")
// Restore the original value of the 'DEPRECATED' macro
#pragma pop_macro("DEPRECATED")

#ifdef __clang__
#pragma clang diagnostic pop // deprecated-declarations
#else
#pragma warning(pop)
#endif
#endif // __windows2Edevices2Eprinters_p_h__

#endif // __windows2Edevices2Eprinters_h__
