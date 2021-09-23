
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
#define WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION 0xa0000
#endif // defined(WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION)

#endif // defined(SPECIFIC_API_CONTRACT_DEFINITIONS)


// Header files for imported files
#include "inspectable.h"
#include "AsyncInfo.h"
#include "EventToken.h"
#include "windowscontracts.h"
#include "Windows.Foundation.h"
#include "Windows.Storage.Streams.h"

#if defined(__cplusplus) && !defined(CINTERFACE)
/* Forward Declarations */
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
