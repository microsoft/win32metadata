
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
#ifndef __windows2Egraphics2Eprinting2Eworkflow_h__
#define __windows2Egraphics2Eprinting2Eworkflow_h__
#ifndef __windows2Egraphics2Eprinting2Eworkflow_p_h__
#define __windows2Egraphics2Eprinting2Eworkflow_p_h__


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
#if !defined(WINDOWS_APPLICATIONMODEL_ACTIVATION_ACTIVATEDEVENTSCONTRACT_VERSION)
#define WINDOWS_APPLICATIONMODEL_ACTIVATION_ACTIVATEDEVENTSCONTRACT_VERSION 0x10000
#endif // defined(WINDOWS_APPLICATIONMODEL_ACTIVATION_ACTIVATEDEVENTSCONTRACT_VERSION)

#if !defined(WINDOWS_APPLICATIONMODEL_ACTIVATION_ACTIVATIONCAMERASETTINGSCONTRACT_VERSION)
#define WINDOWS_APPLICATIONMODEL_ACTIVATION_ACTIVATIONCAMERASETTINGSCONTRACT_VERSION 0x10000
#endif // defined(WINDOWS_APPLICATIONMODEL_ACTIVATION_ACTIVATIONCAMERASETTINGSCONTRACT_VERSION)

#if !defined(WINDOWS_APPLICATIONMODEL_ACTIVATION_CONTACTACTIVATEDEVENTSCONTRACT_VERSION)
#define WINDOWS_APPLICATIONMODEL_ACTIVATION_CONTACTACTIVATEDEVENTSCONTRACT_VERSION 0x10000
#endif // defined(WINDOWS_APPLICATIONMODEL_ACTIVATION_CONTACTACTIVATEDEVENTSCONTRACT_VERSION)

#if !defined(WINDOWS_APPLICATIONMODEL_ACTIVATION_WEBUISEARCHACTIVATEDEVENTSCONTRACT_VERSION)
#define WINDOWS_APPLICATIONMODEL_ACTIVATION_WEBUISEARCHACTIVATEDEVENTSCONTRACT_VERSION 0x10000
#endif // defined(WINDOWS_APPLICATIONMODEL_ACTIVATION_WEBUISEARCHACTIVATEDEVENTSCONTRACT_VERSION)

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
#include "Windows.ApplicationModel.Activation.h"
#include "Windows.Graphics.Printing.PrintTicket.h"
#include "Windows.Storage.Streams.h"

#if defined(__cplusplus) && !defined(CINTERFACE)
/* Forward Declarations */
#ifndef ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSession_FWD_DEFINED__
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSession_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    interface IPrintWorkflowBackgroundSession;
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSession ABI::Windows::Graphics::Printing::Workflow::IPrintWorkflowBackgroundSession

#endif // ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSession_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSetupRequestedEventArgs_FWD_DEFINED__
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSetupRequestedEventArgs_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    interface IPrintWorkflowBackgroundSetupRequestedEventArgs;
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSetupRequestedEventArgs ABI::Windows::Graphics::Printing::Workflow::IPrintWorkflowBackgroundSetupRequestedEventArgs

#endif // ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSetupRequestedEventArgs_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration_FWD_DEFINED__
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    interface IPrintWorkflowConfiguration;
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration ABI::Windows::Graphics::Printing::Workflow::IPrintWorkflowConfiguration

#endif // ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSession_FWD_DEFINED__
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSession_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    interface IPrintWorkflowForegroundSession;
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSession ABI::Windows::Graphics::Printing::Workflow::IPrintWorkflowForegroundSession

#endif // ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSession_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSetupRequestedEventArgs_FWD_DEFINED__
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSetupRequestedEventArgs_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    interface IPrintWorkflowForegroundSetupRequestedEventArgs;
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSetupRequestedEventArgs ABI::Windows::Graphics::Printing::Workflow::IPrintWorkflowForegroundSetupRequestedEventArgs

#endif // ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSetupRequestedEventArgs_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelSourceFileContent_FWD_DEFINED__
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelSourceFileContent_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    interface IPrintWorkflowObjectModelSourceFileContent;
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelSourceFileContent ABI::Windows::Graphics::Printing::Workflow::IPrintWorkflowObjectModelSourceFileContent

#endif // ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelSourceFileContent_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelTargetPackage_FWD_DEFINED__
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelTargetPackage_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    interface IPrintWorkflowObjectModelTargetPackage;
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelTargetPackage ABI::Windows::Graphics::Printing::Workflow::IPrintWorkflowObjectModelTargetPackage

#endif // ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelTargetPackage_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSourceContent_FWD_DEFINED__
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSourceContent_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    interface IPrintWorkflowSourceContent;
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSourceContent ABI::Windows::Graphics::Printing::Workflow::IPrintWorkflowSourceContent

#endif // ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSourceContent_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSpoolStreamContent_FWD_DEFINED__
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSpoolStreamContent_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    interface IPrintWorkflowSpoolStreamContent;
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSpoolStreamContent ABI::Windows::Graphics::Printing::Workflow::IPrintWorkflowSpoolStreamContent

#endif // ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSpoolStreamContent_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowStreamTarget_FWD_DEFINED__
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowStreamTarget_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    interface IPrintWorkflowStreamTarget;
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowStreamTarget ABI::Windows::Graphics::Printing::Workflow::IPrintWorkflowStreamTarget

#endif // ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowStreamTarget_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedEventArgs_FWD_DEFINED__
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedEventArgs_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    interface IPrintWorkflowSubmittedEventArgs;
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedEventArgs ABI::Windows::Graphics::Printing::Workflow::IPrintWorkflowSubmittedEventArgs

#endif // ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedEventArgs_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedOperation_FWD_DEFINED__
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedOperation_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    interface IPrintWorkflowSubmittedOperation;
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedOperation ABI::Windows::Graphics::Printing::Workflow::IPrintWorkflowSubmittedOperation

#endif // ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedOperation_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowTarget_FWD_DEFINED__
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowTarget_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    interface IPrintWorkflowTarget;
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowTarget ABI::Windows::Graphics::Printing::Workflow::IPrintWorkflowTarget

#endif // ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowTarget_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowTriggerDetails_FWD_DEFINED__
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowTriggerDetails_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    interface IPrintWorkflowTriggerDetails;
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowTriggerDetails ABI::Windows::Graphics::Printing::Workflow::IPrintWorkflowTriggerDetails

#endif // ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowTriggerDetails_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowUIActivatedEventArgs_FWD_DEFINED__
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowUIActivatedEventArgs_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    interface IPrintWorkflowUIActivatedEventArgs;
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowUIActivatedEventArgs ABI::Windows::Graphics::Printing::Workflow::IPrintWorkflowUIActivatedEventArgs

#endif // ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowUIActivatedEventArgs_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowXpsDataAvailableEventArgs_FWD_DEFINED__
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowXpsDataAvailableEventArgs_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    interface IPrintWorkflowXpsDataAvailableEventArgs;
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowXpsDataAvailableEventArgs ABI::Windows::Graphics::Printing::Workflow::IPrintWorkflowXpsDataAvailableEventArgs

#endif // ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowXpsDataAvailableEventArgs_FWD_DEFINED__

// Parameterized interface forward declarations (C++)

// Collection interface definitions
namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace PrintTicket {
                    class WorkflowPrintTicket;
                } /* PrintTicket */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */

#ifndef ____x_ABI_CWindows_CGraphics_CPrinting_CPrintTicket_CIWorkflowPrintTicket_FWD_DEFINED__
#define ____x_ABI_CWindows_CGraphics_CPrinting_CPrintTicket_CIWorkflowPrintTicket_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace PrintTicket {
                    interface IWorkflowPrintTicket;
                } /* PrintTicket */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CGraphics_CPrinting_CPrintTicket_CIWorkflowPrintTicket ABI::Windows::Graphics::Printing::PrintTicket::IWorkflowPrintTicket

#endif // ____x_ABI_CWindows_CGraphics_CPrinting_CPrintTicket_CIWorkflowPrintTicket_FWD_DEFINED__

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

#ifndef DEF___FIAsyncOperation_1_Windows__CGraphics__CPrinting__CPrintTicket__CWorkflowPrintTicket_USE
#define DEF___FIAsyncOperation_1_Windows__CGraphics__CPrinting__CPrintTicket__CWorkflowPrintTicket_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation {
template <>
struct __declspec(uuid("26aedf79-0659-5a5d-9acf-b4423eefdebb"))
IAsyncOperation<ABI::Windows::Graphics::Printing::PrintTicket::WorkflowPrintTicket*> : IAsyncOperation_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Graphics::Printing::PrintTicket::WorkflowPrintTicket*, ABI::Windows::Graphics::Printing::PrintTicket::IWorkflowPrintTicket*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.IAsyncOperation`1<Windows.Graphics.Printing.PrintTicket.WorkflowPrintTicket>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IAsyncOperation<ABI::Windows::Graphics::Printing::PrintTicket::WorkflowPrintTicket*> __FIAsyncOperation_1_Windows__CGraphics__CPrinting__CPrintTicket__CWorkflowPrintTicket_t;
#define __FIAsyncOperation_1_Windows__CGraphics__CPrinting__CPrintTicket__CWorkflowPrintTicket ABI::Windows::Foundation::__FIAsyncOperation_1_Windows__CGraphics__CPrinting__CPrintTicket__CWorkflowPrintTicket_t
/* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIAsyncOperation_1_Windows__CGraphics__CPrinting__CPrintTicket__CWorkflowPrintTicket_USE */

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

#ifndef DEF___FIAsyncOperationCompletedHandler_1_Windows__CGraphics__CPrinting__CPrintTicket__CWorkflowPrintTicket_USE
#define DEF___FIAsyncOperationCompletedHandler_1_Windows__CGraphics__CPrinting__CPrintTicket__CWorkflowPrintTicket_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation {
template <>
struct __declspec(uuid("d486c08d-8e7c-5f8d-87ab-0df7ba06c5e3"))
IAsyncOperationCompletedHandler<ABI::Windows::Graphics::Printing::PrintTicket::WorkflowPrintTicket*> : IAsyncOperationCompletedHandler_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Graphics::Printing::PrintTicket::WorkflowPrintTicket*, ABI::Windows::Graphics::Printing::PrintTicket::IWorkflowPrintTicket*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.AsyncOperationCompletedHandler`1<Windows.Graphics.Printing.PrintTicket.WorkflowPrintTicket>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IAsyncOperationCompletedHandler<ABI::Windows::Graphics::Printing::PrintTicket::WorkflowPrintTicket*> __FIAsyncOperationCompletedHandler_1_Windows__CGraphics__CPrinting__CPrintTicket__CWorkflowPrintTicket_t;
#define __FIAsyncOperationCompletedHandler_1_Windows__CGraphics__CPrinting__CPrintTicket__CWorkflowPrintTicket ABI::Windows::Foundation::__FIAsyncOperationCompletedHandler_1_Windows__CGraphics__CPrinting__CPrintTicket__CWorkflowPrintTicket_t
/* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIAsyncOperationCompletedHandler_1_Windows__CGraphics__CPrinting__CPrintTicket__CWorkflowPrintTicket_USE */

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    class PrintWorkflowBackgroundSession;
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    class PrintWorkflowBackgroundSetupRequestedEventArgs;
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

#ifndef DEF___FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSetupRequestedEventArgs_USE
#define DEF___FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSetupRequestedEventArgs_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation {
template <>
struct __declspec(uuid("bb5c0591-4b11-511c-8ef3-1822cb71427c"))
ITypedEventHandler<ABI::Windows::Graphics::Printing::Workflow::PrintWorkflowBackgroundSession*, ABI::Windows::Graphics::Printing::Workflow::PrintWorkflowBackgroundSetupRequestedEventArgs*> : ITypedEventHandler_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Graphics::Printing::Workflow::PrintWorkflowBackgroundSession*, ABI::Windows::Graphics::Printing::Workflow::IPrintWorkflowBackgroundSession*>, ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Graphics::Printing::Workflow::PrintWorkflowBackgroundSetupRequestedEventArgs*, ABI::Windows::Graphics::Printing::Workflow::IPrintWorkflowBackgroundSetupRequestedEventArgs*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.TypedEventHandler`2<Windows.Graphics.Printing.Workflow.PrintWorkflowBackgroundSession, Windows.Graphics.Printing.Workflow.PrintWorkflowBackgroundSetupRequestedEventArgs>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef ITypedEventHandler<ABI::Windows::Graphics::Printing::Workflow::PrintWorkflowBackgroundSession*, ABI::Windows::Graphics::Printing::Workflow::PrintWorkflowBackgroundSetupRequestedEventArgs*> __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSetupRequestedEventArgs_t;
#define __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSetupRequestedEventArgs ABI::Windows::Foundation::__FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSetupRequestedEventArgs_t
/* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSetupRequestedEventArgs_USE */

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    class PrintWorkflowSubmittedEventArgs;
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

#ifndef DEF___FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowSubmittedEventArgs_USE
#define DEF___FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowSubmittedEventArgs_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation {
template <>
struct __declspec(uuid("9ec7b563-5044-5df3-98b5-3a5643fc59fe"))
ITypedEventHandler<ABI::Windows::Graphics::Printing::Workflow::PrintWorkflowBackgroundSession*, ABI::Windows::Graphics::Printing::Workflow::PrintWorkflowSubmittedEventArgs*> : ITypedEventHandler_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Graphics::Printing::Workflow::PrintWorkflowBackgroundSession*, ABI::Windows::Graphics::Printing::Workflow::IPrintWorkflowBackgroundSession*>, ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Graphics::Printing::Workflow::PrintWorkflowSubmittedEventArgs*, ABI::Windows::Graphics::Printing::Workflow::IPrintWorkflowSubmittedEventArgs*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.TypedEventHandler`2<Windows.Graphics.Printing.Workflow.PrintWorkflowBackgroundSession, Windows.Graphics.Printing.Workflow.PrintWorkflowSubmittedEventArgs>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef ITypedEventHandler<ABI::Windows::Graphics::Printing::Workflow::PrintWorkflowBackgroundSession*, ABI::Windows::Graphics::Printing::Workflow::PrintWorkflowSubmittedEventArgs*> __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowSubmittedEventArgs_t;
#define __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowSubmittedEventArgs ABI::Windows::Foundation::__FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowSubmittedEventArgs_t
/* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowSubmittedEventArgs_USE */

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    class PrintWorkflowForegroundSession;
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    class PrintWorkflowForegroundSetupRequestedEventArgs;
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

#ifndef DEF___FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSetupRequestedEventArgs_USE
#define DEF___FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSetupRequestedEventArgs_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation {
template <>
struct __declspec(uuid("d85b48f0-960b-5f65-98b1-5f9b09feb2f6"))
ITypedEventHandler<ABI::Windows::Graphics::Printing::Workflow::PrintWorkflowForegroundSession*, ABI::Windows::Graphics::Printing::Workflow::PrintWorkflowForegroundSetupRequestedEventArgs*> : ITypedEventHandler_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Graphics::Printing::Workflow::PrintWorkflowForegroundSession*, ABI::Windows::Graphics::Printing::Workflow::IPrintWorkflowForegroundSession*>, ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Graphics::Printing::Workflow::PrintWorkflowForegroundSetupRequestedEventArgs*, ABI::Windows::Graphics::Printing::Workflow::IPrintWorkflowForegroundSetupRequestedEventArgs*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.TypedEventHandler`2<Windows.Graphics.Printing.Workflow.PrintWorkflowForegroundSession, Windows.Graphics.Printing.Workflow.PrintWorkflowForegroundSetupRequestedEventArgs>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef ITypedEventHandler<ABI::Windows::Graphics::Printing::Workflow::PrintWorkflowForegroundSession*, ABI::Windows::Graphics::Printing::Workflow::PrintWorkflowForegroundSetupRequestedEventArgs*> __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSetupRequestedEventArgs_t;
#define __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSetupRequestedEventArgs ABI::Windows::Foundation::__FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSetupRequestedEventArgs_t
/* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSetupRequestedEventArgs_USE */

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    class PrintWorkflowXpsDataAvailableEventArgs;
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

#ifndef DEF___FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowXpsDataAvailableEventArgs_USE
#define DEF___FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowXpsDataAvailableEventArgs_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation {
template <>
struct __declspec(uuid("6d38ab29-2bb3-5849-80cd-ece13a589d13"))
ITypedEventHandler<ABI::Windows::Graphics::Printing::Workflow::PrintWorkflowForegroundSession*, ABI::Windows::Graphics::Printing::Workflow::PrintWorkflowXpsDataAvailableEventArgs*> : ITypedEventHandler_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Graphics::Printing::Workflow::PrintWorkflowForegroundSession*, ABI::Windows::Graphics::Printing::Workflow::IPrintWorkflowForegroundSession*>, ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Graphics::Printing::Workflow::PrintWorkflowXpsDataAvailableEventArgs*, ABI::Windows::Graphics::Printing::Workflow::IPrintWorkflowXpsDataAvailableEventArgs*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.TypedEventHandler`2<Windows.Graphics.Printing.Workflow.PrintWorkflowForegroundSession, Windows.Graphics.Printing.Workflow.PrintWorkflowXpsDataAvailableEventArgs>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef ITypedEventHandler<ABI::Windows::Graphics::Printing::Workflow::PrintWorkflowForegroundSession*, ABI::Windows::Graphics::Printing::Workflow::PrintWorkflowXpsDataAvailableEventArgs*> __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowXpsDataAvailableEventArgs_t;
#define __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowXpsDataAvailableEventArgs ABI::Windows::Foundation::__FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowXpsDataAvailableEventArgs_t
/* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowXpsDataAvailableEventArgs_USE */

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

#ifndef ____x_ABI_CWindows_CApplicationModel_CActivation_CIActivatedEventArgs_FWD_DEFINED__
#define ____x_ABI_CWindows_CApplicationModel_CActivation_CIActivatedEventArgs_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace ApplicationModel {
            namespace Activation {
                interface IActivatedEventArgs;
            } /* Activation */
        } /* ApplicationModel */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CApplicationModel_CActivation_CIActivatedEventArgs ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs

#endif // ____x_ABI_CWindows_CApplicationModel_CActivation_CIActivatedEventArgs_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CApplicationModel_CActivation_CIActivatedEventArgsWithUser_FWD_DEFINED__
#define ____x_ABI_CWindows_CApplicationModel_CActivation_CIActivatedEventArgsWithUser_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace ApplicationModel {
            namespace Activation {
                interface IActivatedEventArgsWithUser;
            } /* Activation */
        } /* ApplicationModel */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CApplicationModel_CActivation_CIActivatedEventArgsWithUser ABI::Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser

#endif // ____x_ABI_CWindows_CApplicationModel_CActivation_CIActivatedEventArgsWithUser_FWD_DEFINED__

namespace ABI {
    namespace Windows {
        namespace Foundation {
            class Deferral;
        } /* Foundation */
    } /* Windows */
} /* ABI */

#ifndef ____x_ABI_CWindows_CFoundation_CIDeferral_FWD_DEFINED__
#define ____x_ABI_CWindows_CFoundation_CIDeferral_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Foundation {
            interface IDeferral;
        } /* Foundation */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CFoundation_CIDeferral ABI::Windows::Foundation::IDeferral

#endif // ____x_ABI_CWindows_CFoundation_CIDeferral_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CStorage_CStreams_CIInputStream_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CStreams_CIInputStream_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Streams {
                interface IInputStream;
            } /* Streams */
        } /* Storage */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CStorage_CStreams_CIInputStream ABI::Windows::Storage::Streams::IInputStream

#endif // ____x_ABI_CWindows_CStorage_CStreams_CIInputStream_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CStorage_CStreams_CIOutputStream_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CStreams_CIOutputStream_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Storage {
            namespace Streams {
                interface IOutputStream;
            } /* Streams */
        } /* Storage */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CStorage_CStreams_CIOutputStream ABI::Windows::Storage::Streams::IOutputStream

#endif // ____x_ABI_CWindows_CStorage_CStreams_CIOutputStream_FWD_DEFINED__

namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    typedef enum PrintWorkflowSessionStatus : int PrintWorkflowSessionStatus;
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    typedef enum PrintWorkflowSubmittedStatus : int PrintWorkflowSubmittedStatus;
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    class PrintWorkflowConfiguration;
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    class PrintWorkflowObjectModelSourceFileContent;
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    class PrintWorkflowObjectModelTargetPackage;
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    class PrintWorkflowSourceContent;
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    class PrintWorkflowSpoolStreamContent;
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    class PrintWorkflowStreamTarget;
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    class PrintWorkflowSubmittedOperation;
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    class PrintWorkflowTarget;
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */

/*
 *
 * Struct Windows.Graphics.Printing.Workflow.PrintWorkflowSessionStatus
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    enum PrintWorkflowSessionStatus : int
                    {
                        PrintWorkflowSessionStatus_Started = 0,
                        PrintWorkflowSessionStatus_Completed = 1,
                        PrintWorkflowSessionStatus_Aborted = 2,
                        PrintWorkflowSessionStatus_Closed = 3,
                    };
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Struct Windows.Graphics.Printing.Workflow.PrintWorkflowSubmittedStatus
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    enum PrintWorkflowSubmittedStatus : int
                    {
                        PrintWorkflowSubmittedStatus_Succeeded = 0,
                        PrintWorkflowSubmittedStatus_Canceled = 1,
                        PrintWorkflowSubmittedStatus_Failed = 2,
                    };
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Interface Windows.Graphics.Printing.Workflow.IPrintWorkflowBackgroundSession
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 * Interface is a part of the implementation of type Windows.Graphics.Printing.Workflow.PrintWorkflowBackgroundSession
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSession_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSession_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Graphics_Printing_Workflow_IPrintWorkflowBackgroundSession[] = L"Windows.Graphics.Printing.Workflow.IPrintWorkflowBackgroundSession";
namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    MIDL_INTERFACE("5b7913ba-0c5e-528a-7458-86a46cbddc45")
                    IPrintWorkflowBackgroundSession : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE add_SetupRequested(
                            __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSetupRequestedEventArgs* setupEventHandler,
                            EventRegistrationToken* token
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE remove_SetupRequested(
                            EventRegistrationToken token
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE add_Submitted(
                            __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowSubmittedEventArgs* submittedEventHandler,
                            EventRegistrationToken* token
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE remove_Submitted(
                            EventRegistrationToken token
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_Status(
                            ABI::Windows::Graphics::Printing::Workflow::PrintWorkflowSessionStatus* value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE Start(void) = 0;
                    };

                    extern MIDL_CONST_ID IID& IID_IPrintWorkflowBackgroundSession = _uuidof(IPrintWorkflowBackgroundSession);
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSession;
#endif /* !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSession_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Interface Windows.Graphics.Printing.Workflow.IPrintWorkflowBackgroundSetupRequestedEventArgs
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 * Interface is a part of the implementation of type Windows.Graphics.Printing.Workflow.PrintWorkflowBackgroundSetupRequestedEventArgs
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSetupRequestedEventArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSetupRequestedEventArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Graphics_Printing_Workflow_IPrintWorkflowBackgroundSetupRequestedEventArgs[] = L"Windows.Graphics.Printing.Workflow.IPrintWorkflowBackgroundSetupRequestedEventArgs";
namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    MIDL_INTERFACE("43e97342-1750-59c9-61fb-383748a20362")
                    IPrintWorkflowBackgroundSetupRequestedEventArgs : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE GetUserPrintTicketAsync(
                            __FIAsyncOperation_1_Windows__CGraphics__CPrinting__CPrintTicket__CWorkflowPrintTicket** operation
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_Configuration(
                            ABI::Windows::Graphics::Printing::Workflow::IPrintWorkflowConfiguration** configuration
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE SetRequiresUI(void) = 0;
                        virtual HRESULT STDMETHODCALLTYPE GetDeferral(
                            ABI::Windows::Foundation::IDeferral** result
                            ) = 0;
                    };

                    extern MIDL_CONST_ID IID& IID_IPrintWorkflowBackgroundSetupRequestedEventArgs = _uuidof(IPrintWorkflowBackgroundSetupRequestedEventArgs);
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSetupRequestedEventArgs;
#endif /* !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSetupRequestedEventArgs_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Interface Windows.Graphics.Printing.Workflow.IPrintWorkflowConfiguration
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 * Interface is a part of the implementation of type Windows.Graphics.Printing.Workflow.PrintWorkflowConfiguration
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Graphics_Printing_Workflow_IPrintWorkflowConfiguration[] = L"Windows.Graphics.Printing.Workflow.IPrintWorkflowConfiguration";
namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    MIDL_INTERFACE("d0aac4ed-fd4b-5df5-4bb6-8d0d159ebe3f")
                    IPrintWorkflowConfiguration : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE get_SourceAppDisplayName(
                            HSTRING* value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_JobTitle(
                            HSTRING* value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_SessionId(
                            HSTRING* value
                            ) = 0;
                    };

                    extern MIDL_CONST_ID IID& IID_IPrintWorkflowConfiguration = _uuidof(IPrintWorkflowConfiguration);
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration;
#endif /* !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Interface Windows.Graphics.Printing.Workflow.IPrintWorkflowForegroundSession
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 * Interface is a part of the implementation of type Windows.Graphics.Printing.Workflow.PrintWorkflowForegroundSession
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSession_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSession_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Graphics_Printing_Workflow_IPrintWorkflowForegroundSession[] = L"Windows.Graphics.Printing.Workflow.IPrintWorkflowForegroundSession";
namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    MIDL_INTERFACE("c79b63d0-f8ec-4ceb-953a-c8876157dd33")
                    IPrintWorkflowForegroundSession : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE add_SetupRequested(
                            __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSetupRequestedEventArgs* setupEventHandler,
                            EventRegistrationToken* token
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE remove_SetupRequested(
                            EventRegistrationToken token
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE add_XpsDataAvailable(
                            __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowXpsDataAvailableEventArgs* xpsDataAvailableEventHandler,
                            EventRegistrationToken* token
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE remove_XpsDataAvailable(
                            EventRegistrationToken token
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_Status(
                            ABI::Windows::Graphics::Printing::Workflow::PrintWorkflowSessionStatus* value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE Start(void) = 0;
                    };

                    extern MIDL_CONST_ID IID& IID_IPrintWorkflowForegroundSession = _uuidof(IPrintWorkflowForegroundSession);
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSession;
#endif /* !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSession_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Interface Windows.Graphics.Printing.Workflow.IPrintWorkflowForegroundSetupRequestedEventArgs
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 * Interface is a part of the implementation of type Windows.Graphics.Printing.Workflow.PrintWorkflowForegroundSetupRequestedEventArgs
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSetupRequestedEventArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSetupRequestedEventArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Graphics_Printing_Workflow_IPrintWorkflowForegroundSetupRequestedEventArgs[] = L"Windows.Graphics.Printing.Workflow.IPrintWorkflowForegroundSetupRequestedEventArgs";
namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    MIDL_INTERFACE("bbe38247-9c1b-4dd3-9b2b-c80468d941b3")
                    IPrintWorkflowForegroundSetupRequestedEventArgs : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE GetUserPrintTicketAsync(
                            __FIAsyncOperation_1_Windows__CGraphics__CPrinting__CPrintTicket__CWorkflowPrintTicket** operation
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_Configuration(
                            ABI::Windows::Graphics::Printing::Workflow::IPrintWorkflowConfiguration** value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE GetDeferral(
                            ABI::Windows::Foundation::IDeferral** result
                            ) = 0;
                    };

                    extern MIDL_CONST_ID IID& IID_IPrintWorkflowForegroundSetupRequestedEventArgs = _uuidof(IPrintWorkflowForegroundSetupRequestedEventArgs);
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSetupRequestedEventArgs;
#endif /* !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSetupRequestedEventArgs_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Interface Windows.Graphics.Printing.Workflow.IPrintWorkflowObjectModelSourceFileContent
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 * Interface is a part of the implementation of type Windows.Graphics.Printing.Workflow.PrintWorkflowObjectModelSourceFileContent
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelSourceFileContent_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelSourceFileContent_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Graphics_Printing_Workflow_IPrintWorkflowObjectModelSourceFileContent[] = L"Windows.Graphics.Printing.Workflow.IPrintWorkflowObjectModelSourceFileContent";
namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    MIDL_INTERFACE("c36c8a6a-8a2a-419a-b3c3-2090e6bfab2f")
                    IPrintWorkflowObjectModelSourceFileContent : public IInspectable
                    {
                    public:
                    };

                    extern MIDL_CONST_ID IID& IID_IPrintWorkflowObjectModelSourceFileContent = _uuidof(IPrintWorkflowObjectModelSourceFileContent);
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelSourceFileContent;
#endif /* !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelSourceFileContent_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Interface Windows.Graphics.Printing.Workflow.IPrintWorkflowObjectModelTargetPackage
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 * Interface is a part of the implementation of type Windows.Graphics.Printing.Workflow.PrintWorkflowObjectModelTargetPackage
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelTargetPackage_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelTargetPackage_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Graphics_Printing_Workflow_IPrintWorkflowObjectModelTargetPackage[] = L"Windows.Graphics.Printing.Workflow.IPrintWorkflowObjectModelTargetPackage";
namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    MIDL_INTERFACE("7d96bc74-9b54-4ca1-ad3a-979c3d44ddac")
                    IPrintWorkflowObjectModelTargetPackage : public IInspectable
                    {
                    public:
                    };

                    extern MIDL_CONST_ID IID& IID_IPrintWorkflowObjectModelTargetPackage = _uuidof(IPrintWorkflowObjectModelTargetPackage);
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelTargetPackage;
#endif /* !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelTargetPackage_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Interface Windows.Graphics.Printing.Workflow.IPrintWorkflowSourceContent
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 * Interface is a part of the implementation of type Windows.Graphics.Printing.Workflow.PrintWorkflowSourceContent
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSourceContent_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSourceContent_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Graphics_Printing_Workflow_IPrintWorkflowSourceContent[] = L"Windows.Graphics.Printing.Workflow.IPrintWorkflowSourceContent";
namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    MIDL_INTERFACE("1a28c641-ceb1-4533-bb73-fbe63eefdb18")
                    IPrintWorkflowSourceContent : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE GetJobPrintTicketAsync(
                            __FIAsyncOperation_1_Windows__CGraphics__CPrinting__CPrintTicket__CWorkflowPrintTicket** operation
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE GetSourceSpoolDataAsStreamContent(
                            ABI::Windows::Graphics::Printing::Workflow::IPrintWorkflowSpoolStreamContent** result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE GetSourceSpoolDataAsXpsObjectModel(
                            ABI::Windows::Graphics::Printing::Workflow::IPrintWorkflowObjectModelSourceFileContent** result
                            ) = 0;
                    };

                    extern MIDL_CONST_ID IID& IID_IPrintWorkflowSourceContent = _uuidof(IPrintWorkflowSourceContent);
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSourceContent;
#endif /* !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSourceContent_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Interface Windows.Graphics.Printing.Workflow.IPrintWorkflowSpoolStreamContent
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 * Interface is a part of the implementation of type Windows.Graphics.Printing.Workflow.PrintWorkflowSpoolStreamContent
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSpoolStreamContent_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSpoolStreamContent_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Graphics_Printing_Workflow_IPrintWorkflowSpoolStreamContent[] = L"Windows.Graphics.Printing.Workflow.IPrintWorkflowSpoolStreamContent";
namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    MIDL_INTERFACE("72e55ece-e406-4b74-84e1-3ff3fdcdaf70")
                    IPrintWorkflowSpoolStreamContent : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE GetInputStream(
                            ABI::Windows::Storage::Streams::IInputStream** result
                            ) = 0;
                    };

                    extern MIDL_CONST_ID IID& IID_IPrintWorkflowSpoolStreamContent = _uuidof(IPrintWorkflowSpoolStreamContent);
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSpoolStreamContent;
#endif /* !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSpoolStreamContent_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Interface Windows.Graphics.Printing.Workflow.IPrintWorkflowStreamTarget
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 * Interface is a part of the implementation of type Windows.Graphics.Printing.Workflow.PrintWorkflowStreamTarget
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowStreamTarget_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowStreamTarget_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Graphics_Printing_Workflow_IPrintWorkflowStreamTarget[] = L"Windows.Graphics.Printing.Workflow.IPrintWorkflowStreamTarget";
namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    MIDL_INTERFACE("b23bba84-8565-488b-9839-1c9e7c7aa916")
                    IPrintWorkflowStreamTarget : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE GetOutputStream(
                            ABI::Windows::Storage::Streams::IOutputStream** result
                            ) = 0;
                    };

                    extern MIDL_CONST_ID IID& IID_IPrintWorkflowStreamTarget = _uuidof(IPrintWorkflowStreamTarget);
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowStreamTarget;
#endif /* !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowStreamTarget_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Interface Windows.Graphics.Printing.Workflow.IPrintWorkflowSubmittedEventArgs
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 * Interface is a part of the implementation of type Windows.Graphics.Printing.Workflow.PrintWorkflowSubmittedEventArgs
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedEventArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedEventArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Graphics_Printing_Workflow_IPrintWorkflowSubmittedEventArgs[] = L"Windows.Graphics.Printing.Workflow.IPrintWorkflowSubmittedEventArgs";
namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    MIDL_INTERFACE("3add0a41-3794-5569-5c87-40e8ff720f83")
                    IPrintWorkflowSubmittedEventArgs : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE get_Operation(
                            ABI::Windows::Graphics::Printing::Workflow::IPrintWorkflowSubmittedOperation** value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE GetTarget(
                            ABI::Windows::Graphics::Printing::PrintTicket::IWorkflowPrintTicket* jobPrintTicket,
                            ABI::Windows::Graphics::Printing::Workflow::IPrintWorkflowTarget** result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE GetDeferral(
                            ABI::Windows::Foundation::IDeferral** result
                            ) = 0;
                    };

                    extern MIDL_CONST_ID IID& IID_IPrintWorkflowSubmittedEventArgs = _uuidof(IPrintWorkflowSubmittedEventArgs);
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedEventArgs;
#endif /* !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedEventArgs_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Interface Windows.Graphics.Printing.Workflow.IPrintWorkflowSubmittedOperation
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 * Interface is a part of the implementation of type Windows.Graphics.Printing.Workflow.PrintWorkflowSubmittedOperation
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedOperation_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedOperation_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Graphics_Printing_Workflow_IPrintWorkflowSubmittedOperation[] = L"Windows.Graphics.Printing.Workflow.IPrintWorkflowSubmittedOperation";
namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    MIDL_INTERFACE("2e4e6216-3be1-5f0f-5c81-a5a2bd4eab0e")
                    IPrintWorkflowSubmittedOperation : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE Complete(
                            ABI::Windows::Graphics::Printing::Workflow::PrintWorkflowSubmittedStatus status
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_Configuration(
                            ABI::Windows::Graphics::Printing::Workflow::IPrintWorkflowConfiguration** value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_XpsContent(
                            ABI::Windows::Graphics::Printing::Workflow::IPrintWorkflowSourceContent** value
                            ) = 0;
                    };

                    extern MIDL_CONST_ID IID& IID_IPrintWorkflowSubmittedOperation = _uuidof(IPrintWorkflowSubmittedOperation);
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedOperation;
#endif /* !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedOperation_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Interface Windows.Graphics.Printing.Workflow.IPrintWorkflowTarget
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 * Interface is a part of the implementation of type Windows.Graphics.Printing.Workflow.PrintWorkflowTarget
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowTarget_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowTarget_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Graphics_Printing_Workflow_IPrintWorkflowTarget[] = L"Windows.Graphics.Printing.Workflow.IPrintWorkflowTarget";
namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    MIDL_INTERFACE("29da276c-0a73-5aed-4f3d-970d3251f057")
                    IPrintWorkflowTarget : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE get_TargetAsStream(
                            ABI::Windows::Graphics::Printing::Workflow::IPrintWorkflowStreamTarget** value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_TargetAsXpsObjectModelPackage(
                            ABI::Windows::Graphics::Printing::Workflow::IPrintWorkflowObjectModelTargetPackage** value
                            ) = 0;
                    };

                    extern MIDL_CONST_ID IID& IID_IPrintWorkflowTarget = _uuidof(IPrintWorkflowTarget);
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowTarget;
#endif /* !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowTarget_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Interface Windows.Graphics.Printing.Workflow.IPrintWorkflowTriggerDetails
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 * Interface is a part of the implementation of type Windows.Graphics.Printing.Workflow.PrintWorkflowTriggerDetails
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowTriggerDetails_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowTriggerDetails_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Graphics_Printing_Workflow_IPrintWorkflowTriggerDetails[] = L"Windows.Graphics.Printing.Workflow.IPrintWorkflowTriggerDetails";
namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    MIDL_INTERFACE("5739d868-9d86-4052-b0cb-f310becd59bb")
                    IPrintWorkflowTriggerDetails : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE get_PrintWorkflowSession(
                            ABI::Windows::Graphics::Printing::Workflow::IPrintWorkflowBackgroundSession** value
                            ) = 0;
                    };

                    extern MIDL_CONST_ID IID& IID_IPrintWorkflowTriggerDetails = _uuidof(IPrintWorkflowTriggerDetails);
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowTriggerDetails;
#endif /* !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowTriggerDetails_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Interface Windows.Graphics.Printing.Workflow.IPrintWorkflowUIActivatedEventArgs
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 * Interface is a part of the implementation of type Windows.Graphics.Printing.Workflow.PrintWorkflowUIActivatedEventArgs
 *
 * Any object which implements this interface must also implement the following interfaces:
 *     Windows.ApplicationModel.Activation.IActivatedEventArgs
 *     Windows.ApplicationModel.Activation.IActivatedEventArgsWithUser
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowUIActivatedEventArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowUIActivatedEventArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Graphics_Printing_Workflow_IPrintWorkflowUIActivatedEventArgs[] = L"Windows.Graphics.Printing.Workflow.IPrintWorkflowUIActivatedEventArgs";
namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    MIDL_INTERFACE("bc8a844d-09eb-5746-72a6-8dc8b5edbe9b")
                    IPrintWorkflowUIActivatedEventArgs : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE get_PrintWorkflowSession(
                            ABI::Windows::Graphics::Printing::Workflow::IPrintWorkflowForegroundSession** value
                            ) = 0;
                    };

                    extern MIDL_CONST_ID IID& IID_IPrintWorkflowUIActivatedEventArgs = _uuidof(IPrintWorkflowUIActivatedEventArgs);
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowUIActivatedEventArgs;
#endif /* !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowUIActivatedEventArgs_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Interface Windows.Graphics.Printing.Workflow.IPrintWorkflowXpsDataAvailableEventArgs
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 * Interface is a part of the implementation of type Windows.Graphics.Printing.Workflow.PrintWorkflowXpsDataAvailableEventArgs
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowXpsDataAvailableEventArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowXpsDataAvailableEventArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Graphics_Printing_Workflow_IPrintWorkflowXpsDataAvailableEventArgs[] = L"Windows.Graphics.Printing.Workflow.IPrintWorkflowXpsDataAvailableEventArgs";
namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    MIDL_INTERFACE("4d11c331-54d1-434e-be0e-82c5fa58e5b2")
                    IPrintWorkflowXpsDataAvailableEventArgs : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE get_Operation(
                            ABI::Windows::Graphics::Printing::Workflow::IPrintWorkflowSubmittedOperation** value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE GetDeferral(
                            ABI::Windows::Foundation::IDeferral** result
                            ) = 0;
                    };

                    extern MIDL_CONST_ID IID& IID_IPrintWorkflowXpsDataAvailableEventArgs = _uuidof(IPrintWorkflowXpsDataAvailableEventArgs);
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowXpsDataAvailableEventArgs;
#endif /* !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowXpsDataAvailableEventArgs_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Class Windows.Graphics.Printing.Workflow.PrintWorkflowBackgroundSession
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 * Class implements the following interfaces:
 *    Windows.Graphics.Printing.Workflow.IPrintWorkflowBackgroundSession ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#ifndef RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowBackgroundSession_DEFINED
#define RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowBackgroundSession_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Graphics_Printing_Workflow_PrintWorkflowBackgroundSession[] = L"Windows.Graphics.Printing.Workflow.PrintWorkflowBackgroundSession";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Class Windows.Graphics.Printing.Workflow.PrintWorkflowBackgroundSetupRequestedEventArgs
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 * Class implements the following interfaces:
 *    Windows.Graphics.Printing.Workflow.IPrintWorkflowBackgroundSetupRequestedEventArgs ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#ifndef RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowBackgroundSetupRequestedEventArgs_DEFINED
#define RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowBackgroundSetupRequestedEventArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Graphics_Printing_Workflow_PrintWorkflowBackgroundSetupRequestedEventArgs[] = L"Windows.Graphics.Printing.Workflow.PrintWorkflowBackgroundSetupRequestedEventArgs";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Class Windows.Graphics.Printing.Workflow.PrintWorkflowConfiguration
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 * Class implements the following interfaces:
 *    Windows.Graphics.Printing.Workflow.IPrintWorkflowConfiguration ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#ifndef RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowConfiguration_DEFINED
#define RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowConfiguration_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Graphics_Printing_Workflow_PrintWorkflowConfiguration[] = L"Windows.Graphics.Printing.Workflow.PrintWorkflowConfiguration";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Class Windows.Graphics.Printing.Workflow.PrintWorkflowForegroundSession
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 * Class implements the following interfaces:
 *    Windows.Graphics.Printing.Workflow.IPrintWorkflowForegroundSession ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#ifndef RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowForegroundSession_DEFINED
#define RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowForegroundSession_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Graphics_Printing_Workflow_PrintWorkflowForegroundSession[] = L"Windows.Graphics.Printing.Workflow.PrintWorkflowForegroundSession";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Class Windows.Graphics.Printing.Workflow.PrintWorkflowForegroundSetupRequestedEventArgs
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 * Class implements the following interfaces:
 *    Windows.Graphics.Printing.Workflow.IPrintWorkflowForegroundSetupRequestedEventArgs ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#ifndef RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowForegroundSetupRequestedEventArgs_DEFINED
#define RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowForegroundSetupRequestedEventArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Graphics_Printing_Workflow_PrintWorkflowForegroundSetupRequestedEventArgs[] = L"Windows.Graphics.Printing.Workflow.PrintWorkflowForegroundSetupRequestedEventArgs";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Class Windows.Graphics.Printing.Workflow.PrintWorkflowObjectModelSourceFileContent
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 * Class implements the following interfaces:
 *    Windows.Graphics.Printing.Workflow.IPrintWorkflowObjectModelSourceFileContent ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#ifndef RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowObjectModelSourceFileContent_DEFINED
#define RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowObjectModelSourceFileContent_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Graphics_Printing_Workflow_PrintWorkflowObjectModelSourceFileContent[] = L"Windows.Graphics.Printing.Workflow.PrintWorkflowObjectModelSourceFileContent";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Class Windows.Graphics.Printing.Workflow.PrintWorkflowObjectModelTargetPackage
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 * Class implements the following interfaces:
 *    Windows.Graphics.Printing.Workflow.IPrintWorkflowObjectModelTargetPackage ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#ifndef RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowObjectModelTargetPackage_DEFINED
#define RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowObjectModelTargetPackage_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Graphics_Printing_Workflow_PrintWorkflowObjectModelTargetPackage[] = L"Windows.Graphics.Printing.Workflow.PrintWorkflowObjectModelTargetPackage";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Class Windows.Graphics.Printing.Workflow.PrintWorkflowSourceContent
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 * Class implements the following interfaces:
 *    Windows.Graphics.Printing.Workflow.IPrintWorkflowSourceContent ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#ifndef RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowSourceContent_DEFINED
#define RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowSourceContent_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Graphics_Printing_Workflow_PrintWorkflowSourceContent[] = L"Windows.Graphics.Printing.Workflow.PrintWorkflowSourceContent";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Class Windows.Graphics.Printing.Workflow.PrintWorkflowSpoolStreamContent
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 * Class implements the following interfaces:
 *    Windows.Graphics.Printing.Workflow.IPrintWorkflowSpoolStreamContent ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#ifndef RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowSpoolStreamContent_DEFINED
#define RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowSpoolStreamContent_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Graphics_Printing_Workflow_PrintWorkflowSpoolStreamContent[] = L"Windows.Graphics.Printing.Workflow.PrintWorkflowSpoolStreamContent";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Class Windows.Graphics.Printing.Workflow.PrintWorkflowStreamTarget
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 * Class implements the following interfaces:
 *    Windows.Graphics.Printing.Workflow.IPrintWorkflowStreamTarget ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#ifndef RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowStreamTarget_DEFINED
#define RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowStreamTarget_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Graphics_Printing_Workflow_PrintWorkflowStreamTarget[] = L"Windows.Graphics.Printing.Workflow.PrintWorkflowStreamTarget";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Class Windows.Graphics.Printing.Workflow.PrintWorkflowSubmittedEventArgs
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 * Class implements the following interfaces:
 *    Windows.Graphics.Printing.Workflow.IPrintWorkflowSubmittedEventArgs ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#ifndef RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowSubmittedEventArgs_DEFINED
#define RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowSubmittedEventArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Graphics_Printing_Workflow_PrintWorkflowSubmittedEventArgs[] = L"Windows.Graphics.Printing.Workflow.PrintWorkflowSubmittedEventArgs";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Class Windows.Graphics.Printing.Workflow.PrintWorkflowSubmittedOperation
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 * Class implements the following interfaces:
 *    Windows.Graphics.Printing.Workflow.IPrintWorkflowSubmittedOperation ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#ifndef RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowSubmittedOperation_DEFINED
#define RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowSubmittedOperation_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Graphics_Printing_Workflow_PrintWorkflowSubmittedOperation[] = L"Windows.Graphics.Printing.Workflow.PrintWorkflowSubmittedOperation";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Class Windows.Graphics.Printing.Workflow.PrintWorkflowTarget
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 * Class implements the following interfaces:
 *    Windows.Graphics.Printing.Workflow.IPrintWorkflowTarget ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#ifndef RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowTarget_DEFINED
#define RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowTarget_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Graphics_Printing_Workflow_PrintWorkflowTarget[] = L"Windows.Graphics.Printing.Workflow.PrintWorkflowTarget";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Class Windows.Graphics.Printing.Workflow.PrintWorkflowTriggerDetails
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 * Class implements the following interfaces:
 *    Windows.Graphics.Printing.Workflow.IPrintWorkflowTriggerDetails ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#ifndef RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowTriggerDetails_DEFINED
#define RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowTriggerDetails_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Graphics_Printing_Workflow_PrintWorkflowTriggerDetails[] = L"Windows.Graphics.Printing.Workflow.PrintWorkflowTriggerDetails";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Class Windows.Graphics.Printing.Workflow.PrintWorkflowUIActivatedEventArgs
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 * Class implements the following interfaces:
 *    Windows.Graphics.Printing.Workflow.IPrintWorkflowUIActivatedEventArgs ** Default Interface **
 *    Windows.ApplicationModel.Activation.IActivatedEventArgsWithUser
 *    Windows.ApplicationModel.Activation.IActivatedEventArgs
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#ifndef RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowUIActivatedEventArgs_DEFINED
#define RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowUIActivatedEventArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Graphics_Printing_Workflow_PrintWorkflowUIActivatedEventArgs[] = L"Windows.Graphics.Printing.Workflow.PrintWorkflowUIActivatedEventArgs";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Class Windows.Graphics.Printing.Workflow.PrintWorkflowXpsDataAvailableEventArgs
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 * Class implements the following interfaces:
 *    Windows.Graphics.Printing.Workflow.IPrintWorkflowXpsDataAvailableEventArgs ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#ifndef RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowXpsDataAvailableEventArgs_DEFINED
#define RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowXpsDataAvailableEventArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Graphics_Printing_Workflow_PrintWorkflowXpsDataAvailableEventArgs[] = L"Windows.Graphics.Printing.Workflow.PrintWorkflowXpsDataAvailableEventArgs";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

#else // !defined(__cplusplus)
/* Forward Declarations */
#ifndef ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSession_FWD_DEFINED__
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSession_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSession __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSession;

#endif // ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSession_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSetupRequestedEventArgs_FWD_DEFINED__
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSetupRequestedEventArgs_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSetupRequestedEventArgs __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSetupRequestedEventArgs;

#endif // ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSetupRequestedEventArgs_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration_FWD_DEFINED__
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration;

#endif // ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSession_FWD_DEFINED__
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSession_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSession __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSession;

#endif // ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSession_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSetupRequestedEventArgs_FWD_DEFINED__
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSetupRequestedEventArgs_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSetupRequestedEventArgs __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSetupRequestedEventArgs;

#endif // ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSetupRequestedEventArgs_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelSourceFileContent_FWD_DEFINED__
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelSourceFileContent_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelSourceFileContent __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelSourceFileContent;

#endif // ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelSourceFileContent_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelTargetPackage_FWD_DEFINED__
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelTargetPackage_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelTargetPackage __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelTargetPackage;

#endif // ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelTargetPackage_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSourceContent_FWD_DEFINED__
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSourceContent_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSourceContent __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSourceContent;

#endif // ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSourceContent_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSpoolStreamContent_FWD_DEFINED__
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSpoolStreamContent_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSpoolStreamContent __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSpoolStreamContent;

#endif // ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSpoolStreamContent_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowStreamTarget_FWD_DEFINED__
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowStreamTarget_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowStreamTarget __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowStreamTarget;

#endif // ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowStreamTarget_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedEventArgs_FWD_DEFINED__
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedEventArgs_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedEventArgs __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedEventArgs;

#endif // ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedEventArgs_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedOperation_FWD_DEFINED__
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedOperation_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedOperation __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedOperation;

#endif // ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedOperation_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowTarget_FWD_DEFINED__
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowTarget_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowTarget __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowTarget;

#endif // ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowTarget_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowTriggerDetails_FWD_DEFINED__
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowTriggerDetails_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowTriggerDetails __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowTriggerDetails;

#endif // ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowTriggerDetails_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowUIActivatedEventArgs_FWD_DEFINED__
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowUIActivatedEventArgs_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowUIActivatedEventArgs __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowUIActivatedEventArgs;

#endif // ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowUIActivatedEventArgs_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowXpsDataAvailableEventArgs_FWD_DEFINED__
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowXpsDataAvailableEventArgs_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowXpsDataAvailableEventArgs __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowXpsDataAvailableEventArgs;

#endif // ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowXpsDataAvailableEventArgs_FWD_DEFINED__

// Parameterized interface forward declarations (C)

// Collection interface definitions

#ifndef ____x_ABI_CWindows_CGraphics_CPrinting_CPrintTicket_CIWorkflowPrintTicket_FWD_DEFINED__
#define ____x_ABI_CWindows_CGraphics_CPrinting_CPrintTicket_CIWorkflowPrintTicket_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CGraphics_CPrinting_CPrintTicket_CIWorkflowPrintTicket __x_ABI_CWindows_CGraphics_CPrinting_CPrintTicket_CIWorkflowPrintTicket;

#endif // ____x_ABI_CWindows_CGraphics_CPrinting_CPrintTicket_CIWorkflowPrintTicket_FWD_DEFINED__

typedef interface __FIAsyncOperationCompletedHandler_1_Windows__CGraphics__CPrinting__CPrintTicket__CWorkflowPrintTicket __FIAsyncOperationCompletedHandler_1_Windows__CGraphics__CPrinting__CPrintTicket__CWorkflowPrintTicket;

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#if !defined(____FIAsyncOperation_1_Windows__CGraphics__CPrinting__CPrintTicket__CWorkflowPrintTicket_INTERFACE_DEFINED__)
#define ____FIAsyncOperation_1_Windows__CGraphics__CPrinting__CPrintTicket__CWorkflowPrintTicket_INTERFACE_DEFINED__

typedef interface __FIAsyncOperation_1_Windows__CGraphics__CPrinting__CPrintTicket__CWorkflowPrintTicket __FIAsyncOperation_1_Windows__CGraphics__CPrinting__CPrintTicket__CWorkflowPrintTicket;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIAsyncOperation_1_Windows__CGraphics__CPrinting__CPrintTicket__CWorkflowPrintTicket;

typedef struct __FIAsyncOperation_1_Windows__CGraphics__CPrinting__CPrintTicket__CWorkflowPrintTicketVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIAsyncOperation_1_Windows__CGraphics__CPrinting__CPrintTicket__CWorkflowPrintTicket* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIAsyncOperation_1_Windows__CGraphics__CPrinting__CPrintTicket__CWorkflowPrintTicket* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIAsyncOperation_1_Windows__CGraphics__CPrinting__CPrintTicket__CWorkflowPrintTicket* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIAsyncOperation_1_Windows__CGraphics__CPrinting__CPrintTicket__CWorkflowPrintTicket* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIAsyncOperation_1_Windows__CGraphics__CPrinting__CPrintTicket__CWorkflowPrintTicket* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIAsyncOperation_1_Windows__CGraphics__CPrinting__CPrintTicket__CWorkflowPrintTicket* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* put_Completed)(__FIAsyncOperation_1_Windows__CGraphics__CPrinting__CPrintTicket__CWorkflowPrintTicket* This,
        __FIAsyncOperationCompletedHandler_1_Windows__CGraphics__CPrinting__CPrintTicket__CWorkflowPrintTicket* handler);
    HRESULT (STDMETHODCALLTYPE* get_Completed)(__FIAsyncOperation_1_Windows__CGraphics__CPrinting__CPrintTicket__CWorkflowPrintTicket* This,
        __FIAsyncOperationCompletedHandler_1_Windows__CGraphics__CPrinting__CPrintTicket__CWorkflowPrintTicket** result);
    HRESULT (STDMETHODCALLTYPE* GetResults)(__FIAsyncOperation_1_Windows__CGraphics__CPrinting__CPrintTicket__CWorkflowPrintTicket* This,
        __x_ABI_CWindows_CGraphics_CPrinting_CPrintTicket_CIWorkflowPrintTicket** result);

    END_INTERFACE
} __FIAsyncOperation_1_Windows__CGraphics__CPrinting__CPrintTicket__CWorkflowPrintTicketVtbl;

interface __FIAsyncOperation_1_Windows__CGraphics__CPrinting__CPrintTicket__CWorkflowPrintTicket
{
    CONST_VTBL struct __FIAsyncOperation_1_Windows__CGraphics__CPrinting__CPrintTicket__CWorkflowPrintTicketVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIAsyncOperation_1_Windows__CGraphics__CPrinting__CPrintTicket__CWorkflowPrintTicket_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIAsyncOperation_1_Windows__CGraphics__CPrinting__CPrintTicket__CWorkflowPrintTicket_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIAsyncOperation_1_Windows__CGraphics__CPrinting__CPrintTicket__CWorkflowPrintTicket_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIAsyncOperation_1_Windows__CGraphics__CPrinting__CPrintTicket__CWorkflowPrintTicket_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIAsyncOperation_1_Windows__CGraphics__CPrinting__CPrintTicket__CWorkflowPrintTicket_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIAsyncOperation_1_Windows__CGraphics__CPrinting__CPrintTicket__CWorkflowPrintTicket_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIAsyncOperation_1_Windows__CGraphics__CPrinting__CPrintTicket__CWorkflowPrintTicket_put_Completed(This, handler) \
    ((This)->lpVtbl->put_Completed(This, handler))

#define __FIAsyncOperation_1_Windows__CGraphics__CPrinting__CPrintTicket__CWorkflowPrintTicket_get_Completed(This, result) \
    ((This)->lpVtbl->get_Completed(This, result))

#define __FIAsyncOperation_1_Windows__CGraphics__CPrinting__CPrintTicket__CWorkflowPrintTicket_GetResults(This, result) \
    ((This)->lpVtbl->GetResults(This, result))

#endif /* COBJMACROS */

#endif // ____FIAsyncOperation_1_Windows__CGraphics__CPrinting__CPrintTicket__CWorkflowPrintTicket_INTERFACE_DEFINED__
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#if !defined(____FIAsyncOperationCompletedHandler_1_Windows__CGraphics__CPrinting__CPrintTicket__CWorkflowPrintTicket_INTERFACE_DEFINED__)
#define ____FIAsyncOperationCompletedHandler_1_Windows__CGraphics__CPrinting__CPrintTicket__CWorkflowPrintTicket_INTERFACE_DEFINED__

typedef interface __FIAsyncOperationCompletedHandler_1_Windows__CGraphics__CPrinting__CPrintTicket__CWorkflowPrintTicket __FIAsyncOperationCompletedHandler_1_Windows__CGraphics__CPrinting__CPrintTicket__CWorkflowPrintTicket;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIAsyncOperationCompletedHandler_1_Windows__CGraphics__CPrinting__CPrintTicket__CWorkflowPrintTicket;

typedef struct __FIAsyncOperationCompletedHandler_1_Windows__CGraphics__CPrinting__CPrintTicket__CWorkflowPrintTicketVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIAsyncOperationCompletedHandler_1_Windows__CGraphics__CPrinting__CPrintTicket__CWorkflowPrintTicket* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIAsyncOperationCompletedHandler_1_Windows__CGraphics__CPrinting__CPrintTicket__CWorkflowPrintTicket* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIAsyncOperationCompletedHandler_1_Windows__CGraphics__CPrinting__CPrintTicket__CWorkflowPrintTicket* This);
    HRESULT (STDMETHODCALLTYPE* Invoke)(__FIAsyncOperationCompletedHandler_1_Windows__CGraphics__CPrinting__CPrintTicket__CWorkflowPrintTicket* This,
        __FIAsyncOperation_1_Windows__CGraphics__CPrinting__CPrintTicket__CWorkflowPrintTicket* asyncInfo,
        AsyncStatus asyncStatus);

    END_INTERFACE
} __FIAsyncOperationCompletedHandler_1_Windows__CGraphics__CPrinting__CPrintTicket__CWorkflowPrintTicketVtbl;

interface __FIAsyncOperationCompletedHandler_1_Windows__CGraphics__CPrinting__CPrintTicket__CWorkflowPrintTicket
{
    CONST_VTBL struct __FIAsyncOperationCompletedHandler_1_Windows__CGraphics__CPrinting__CPrintTicket__CWorkflowPrintTicketVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIAsyncOperationCompletedHandler_1_Windows__CGraphics__CPrinting__CPrintTicket__CWorkflowPrintTicket_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIAsyncOperationCompletedHandler_1_Windows__CGraphics__CPrinting__CPrintTicket__CWorkflowPrintTicket_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIAsyncOperationCompletedHandler_1_Windows__CGraphics__CPrinting__CPrintTicket__CWorkflowPrintTicket_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIAsyncOperationCompletedHandler_1_Windows__CGraphics__CPrinting__CPrintTicket__CWorkflowPrintTicket_Invoke(This, asyncInfo, asyncStatus) \
    ((This)->lpVtbl->Invoke(This, asyncInfo, asyncStatus))

#endif /* COBJMACROS */

#endif // ____FIAsyncOperationCompletedHandler_1_Windows__CGraphics__CPrinting__CPrintTicket__CWorkflowPrintTicket_INTERFACE_DEFINED__
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#if !defined(____FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSetupRequestedEventArgs_INTERFACE_DEFINED__)
#define ____FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSetupRequestedEventArgs_INTERFACE_DEFINED__

typedef interface __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSetupRequestedEventArgs __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSetupRequestedEventArgs;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSetupRequestedEventArgs;

typedef struct __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSetupRequestedEventArgsVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSetupRequestedEventArgs* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSetupRequestedEventArgs* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSetupRequestedEventArgs* This);
    HRESULT (STDMETHODCALLTYPE* Invoke)(__FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSetupRequestedEventArgs* This,
        __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSession* sender,
        __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSetupRequestedEventArgs* args);

    END_INTERFACE
} __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSetupRequestedEventArgsVtbl;

interface __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSetupRequestedEventArgs
{
    CONST_VTBL struct __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSetupRequestedEventArgsVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSetupRequestedEventArgs_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSetupRequestedEventArgs_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSetupRequestedEventArgs_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSetupRequestedEventArgs_Invoke(This, sender, args) \
    ((This)->lpVtbl->Invoke(This, sender, args))

#endif /* COBJMACROS */

#endif // ____FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSetupRequestedEventArgs_INTERFACE_DEFINED__
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#if !defined(____FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowSubmittedEventArgs_INTERFACE_DEFINED__)
#define ____FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowSubmittedEventArgs_INTERFACE_DEFINED__

typedef interface __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowSubmittedEventArgs __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowSubmittedEventArgs;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowSubmittedEventArgs;

typedef struct __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowSubmittedEventArgsVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowSubmittedEventArgs* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowSubmittedEventArgs* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowSubmittedEventArgs* This);
    HRESULT (STDMETHODCALLTYPE* Invoke)(__FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowSubmittedEventArgs* This,
        __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSession* sender,
        __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedEventArgs* args);

    END_INTERFACE
} __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowSubmittedEventArgsVtbl;

interface __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowSubmittedEventArgs
{
    CONST_VTBL struct __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowSubmittedEventArgsVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowSubmittedEventArgs_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowSubmittedEventArgs_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowSubmittedEventArgs_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowSubmittedEventArgs_Invoke(This, sender, args) \
    ((This)->lpVtbl->Invoke(This, sender, args))

#endif /* COBJMACROS */

#endif // ____FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowSubmittedEventArgs_INTERFACE_DEFINED__
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#if !defined(____FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSetupRequestedEventArgs_INTERFACE_DEFINED__)
#define ____FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSetupRequestedEventArgs_INTERFACE_DEFINED__

typedef interface __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSetupRequestedEventArgs __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSetupRequestedEventArgs;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSetupRequestedEventArgs;

typedef struct __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSetupRequestedEventArgsVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSetupRequestedEventArgs* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSetupRequestedEventArgs* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSetupRequestedEventArgs* This);
    HRESULT (STDMETHODCALLTYPE* Invoke)(__FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSetupRequestedEventArgs* This,
        __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSession* sender,
        __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSetupRequestedEventArgs* args);

    END_INTERFACE
} __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSetupRequestedEventArgsVtbl;

interface __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSetupRequestedEventArgs
{
    CONST_VTBL struct __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSetupRequestedEventArgsVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSetupRequestedEventArgs_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSetupRequestedEventArgs_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSetupRequestedEventArgs_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSetupRequestedEventArgs_Invoke(This, sender, args) \
    ((This)->lpVtbl->Invoke(This, sender, args))

#endif /* COBJMACROS */

#endif // ____FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSetupRequestedEventArgs_INTERFACE_DEFINED__
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#if !defined(____FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowXpsDataAvailableEventArgs_INTERFACE_DEFINED__)
#define ____FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowXpsDataAvailableEventArgs_INTERFACE_DEFINED__

typedef interface __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowXpsDataAvailableEventArgs __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowXpsDataAvailableEventArgs;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowXpsDataAvailableEventArgs;

typedef struct __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowXpsDataAvailableEventArgsVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowXpsDataAvailableEventArgs* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowXpsDataAvailableEventArgs* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowXpsDataAvailableEventArgs* This);
    HRESULT (STDMETHODCALLTYPE* Invoke)(__FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowXpsDataAvailableEventArgs* This,
        __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSession* sender,
        __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowXpsDataAvailableEventArgs* args);

    END_INTERFACE
} __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowXpsDataAvailableEventArgsVtbl;

interface __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowXpsDataAvailableEventArgs
{
    CONST_VTBL struct __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowXpsDataAvailableEventArgsVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowXpsDataAvailableEventArgs_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowXpsDataAvailableEventArgs_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowXpsDataAvailableEventArgs_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowXpsDataAvailableEventArgs_Invoke(This, sender, args) \
    ((This)->lpVtbl->Invoke(This, sender, args))

#endif /* COBJMACROS */

#endif // ____FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowXpsDataAvailableEventArgs_INTERFACE_DEFINED__
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

#ifndef ____x_ABI_CWindows_CApplicationModel_CActivation_CIActivatedEventArgs_FWD_DEFINED__
#define ____x_ABI_CWindows_CApplicationModel_CActivation_CIActivatedEventArgs_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CApplicationModel_CActivation_CIActivatedEventArgs __x_ABI_CWindows_CApplicationModel_CActivation_CIActivatedEventArgs;

#endif // ____x_ABI_CWindows_CApplicationModel_CActivation_CIActivatedEventArgs_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CApplicationModel_CActivation_CIActivatedEventArgsWithUser_FWD_DEFINED__
#define ____x_ABI_CWindows_CApplicationModel_CActivation_CIActivatedEventArgsWithUser_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CApplicationModel_CActivation_CIActivatedEventArgsWithUser __x_ABI_CWindows_CApplicationModel_CActivation_CIActivatedEventArgsWithUser;

#endif // ____x_ABI_CWindows_CApplicationModel_CActivation_CIActivatedEventArgsWithUser_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CFoundation_CIDeferral_FWD_DEFINED__
#define ____x_ABI_CWindows_CFoundation_CIDeferral_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CFoundation_CIDeferral __x_ABI_CWindows_CFoundation_CIDeferral;

#endif // ____x_ABI_CWindows_CFoundation_CIDeferral_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CStorage_CStreams_CIInputStream_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CStreams_CIInputStream_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CStorage_CStreams_CIInputStream __x_ABI_CWindows_CStorage_CStreams_CIInputStream;

#endif // ____x_ABI_CWindows_CStorage_CStreams_CIInputStream_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CStorage_CStreams_CIOutputStream_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CStreams_CIOutputStream_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CStorage_CStreams_CIOutputStream __x_ABI_CWindows_CStorage_CStreams_CIOutputStream;

#endif // ____x_ABI_CWindows_CStorage_CStreams_CIOutputStream_FWD_DEFINED__

typedef enum __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CPrintWorkflowSessionStatus __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CPrintWorkflowSessionStatus;

typedef enum __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CPrintWorkflowSubmittedStatus __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CPrintWorkflowSubmittedStatus;

/*
 *
 * Struct Windows.Graphics.Printing.Workflow.PrintWorkflowSessionStatus
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
enum __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CPrintWorkflowSessionStatus
{
    PrintWorkflowSessionStatus_Started = 0,
    PrintWorkflowSessionStatus_Completed = 1,
    PrintWorkflowSessionStatus_Aborted = 2,
    PrintWorkflowSessionStatus_Closed = 3,
};
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Struct Windows.Graphics.Printing.Workflow.PrintWorkflowSubmittedStatus
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
enum __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CPrintWorkflowSubmittedStatus
{
    PrintWorkflowSubmittedStatus_Succeeded = 0,
    PrintWorkflowSubmittedStatus_Canceled = 1,
    PrintWorkflowSubmittedStatus_Failed = 2,
};
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Interface Windows.Graphics.Printing.Workflow.IPrintWorkflowBackgroundSession
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 * Interface is a part of the implementation of type Windows.Graphics.Printing.Workflow.PrintWorkflowBackgroundSession
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSession_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSession_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Graphics_Printing_Workflow_IPrintWorkflowBackgroundSession[] = L"Windows.Graphics.Printing.Workflow.IPrintWorkflowBackgroundSession";
typedef struct __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSessionVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSession* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSession* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSession* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSession* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSession* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSession* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* add_SetupRequested)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSession* This,
        __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSetupRequestedEventArgs* setupEventHandler,
        EventRegistrationToken* token);
    HRESULT (STDMETHODCALLTYPE* remove_SetupRequested)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSession* This,
        EventRegistrationToken token);
    HRESULT (STDMETHODCALLTYPE* add_Submitted)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSession* This,
        __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowSubmittedEventArgs* submittedEventHandler,
        EventRegistrationToken* token);
    HRESULT (STDMETHODCALLTYPE* remove_Submitted)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSession* This,
        EventRegistrationToken token);
    HRESULT (STDMETHODCALLTYPE* get_Status)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSession* This,
        enum __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CPrintWorkflowSessionStatus* value);
    HRESULT (STDMETHODCALLTYPE* Start)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSession* This);

    END_INTERFACE
} __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSessionVtbl;

interface __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSession
{
    CONST_VTBL struct __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSessionVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSession_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSession_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSession_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSession_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSession_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSession_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSession_add_SetupRequested(This, setupEventHandler, token) \
    ((This)->lpVtbl->add_SetupRequested(This, setupEventHandler, token))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSession_remove_SetupRequested(This, token) \
    ((This)->lpVtbl->remove_SetupRequested(This, token))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSession_add_Submitted(This, submittedEventHandler, token) \
    ((This)->lpVtbl->add_Submitted(This, submittedEventHandler, token))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSession_remove_Submitted(This, token) \
    ((This)->lpVtbl->remove_Submitted(This, token))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSession_get_Status(This, value) \
    ((This)->lpVtbl->get_Status(This, value))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSession_Start(This) \
    ((This)->lpVtbl->Start(This))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSession;
#endif /* !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSession_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Interface Windows.Graphics.Printing.Workflow.IPrintWorkflowBackgroundSetupRequestedEventArgs
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 * Interface is a part of the implementation of type Windows.Graphics.Printing.Workflow.PrintWorkflowBackgroundSetupRequestedEventArgs
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSetupRequestedEventArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSetupRequestedEventArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Graphics_Printing_Workflow_IPrintWorkflowBackgroundSetupRequestedEventArgs[] = L"Windows.Graphics.Printing.Workflow.IPrintWorkflowBackgroundSetupRequestedEventArgs";
typedef struct __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSetupRequestedEventArgsVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSetupRequestedEventArgs* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSetupRequestedEventArgs* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSetupRequestedEventArgs* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSetupRequestedEventArgs* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSetupRequestedEventArgs* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSetupRequestedEventArgs* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* GetUserPrintTicketAsync)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSetupRequestedEventArgs* This,
        __FIAsyncOperation_1_Windows__CGraphics__CPrinting__CPrintTicket__CWorkflowPrintTicket** operation);
    HRESULT (STDMETHODCALLTYPE* get_Configuration)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSetupRequestedEventArgs* This,
        __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration** configuration);
    HRESULT (STDMETHODCALLTYPE* SetRequiresUI)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSetupRequestedEventArgs* This);
    HRESULT (STDMETHODCALLTYPE* GetDeferral)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSetupRequestedEventArgs* This,
        __x_ABI_CWindows_CFoundation_CIDeferral** result);

    END_INTERFACE
} __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSetupRequestedEventArgsVtbl;

interface __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSetupRequestedEventArgs
{
    CONST_VTBL struct __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSetupRequestedEventArgsVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSetupRequestedEventArgs_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSetupRequestedEventArgs_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSetupRequestedEventArgs_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSetupRequestedEventArgs_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSetupRequestedEventArgs_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSetupRequestedEventArgs_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSetupRequestedEventArgs_GetUserPrintTicketAsync(This, operation) \
    ((This)->lpVtbl->GetUserPrintTicketAsync(This, operation))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSetupRequestedEventArgs_get_Configuration(This, configuration) \
    ((This)->lpVtbl->get_Configuration(This, configuration))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSetupRequestedEventArgs_SetRequiresUI(This) \
    ((This)->lpVtbl->SetRequiresUI(This))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSetupRequestedEventArgs_GetDeferral(This, result) \
    ((This)->lpVtbl->GetDeferral(This, result))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSetupRequestedEventArgs;
#endif /* !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSetupRequestedEventArgs_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Interface Windows.Graphics.Printing.Workflow.IPrintWorkflowConfiguration
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 * Interface is a part of the implementation of type Windows.Graphics.Printing.Workflow.PrintWorkflowConfiguration
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Graphics_Printing_Workflow_IPrintWorkflowConfiguration[] = L"Windows.Graphics.Printing.Workflow.IPrintWorkflowConfiguration";
typedef struct __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfigurationVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_SourceAppDisplayName)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* get_JobTitle)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* get_SessionId)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration* This,
        HSTRING* value);

    END_INTERFACE
} __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfigurationVtbl;

interface __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration
{
    CONST_VTBL struct __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfigurationVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration_get_SourceAppDisplayName(This, value) \
    ((This)->lpVtbl->get_SourceAppDisplayName(This, value))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration_get_JobTitle(This, value) \
    ((This)->lpVtbl->get_JobTitle(This, value))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration_get_SessionId(This, value) \
    ((This)->lpVtbl->get_SessionId(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration;
#endif /* !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Interface Windows.Graphics.Printing.Workflow.IPrintWorkflowForegroundSession
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 * Interface is a part of the implementation of type Windows.Graphics.Printing.Workflow.PrintWorkflowForegroundSession
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSession_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSession_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Graphics_Printing_Workflow_IPrintWorkflowForegroundSession[] = L"Windows.Graphics.Printing.Workflow.IPrintWorkflowForegroundSession";
typedef struct __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSessionVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSession* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSession* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSession* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSession* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSession* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSession* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* add_SetupRequested)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSession* This,
        __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSetupRequestedEventArgs* setupEventHandler,
        EventRegistrationToken* token);
    HRESULT (STDMETHODCALLTYPE* remove_SetupRequested)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSession* This,
        EventRegistrationToken token);
    HRESULT (STDMETHODCALLTYPE* add_XpsDataAvailable)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSession* This,
        __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowForegroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowXpsDataAvailableEventArgs* xpsDataAvailableEventHandler,
        EventRegistrationToken* token);
    HRESULT (STDMETHODCALLTYPE* remove_XpsDataAvailable)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSession* This,
        EventRegistrationToken token);
    HRESULT (STDMETHODCALLTYPE* get_Status)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSession* This,
        enum __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CPrintWorkflowSessionStatus* value);
    HRESULT (STDMETHODCALLTYPE* Start)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSession* This);

    END_INTERFACE
} __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSessionVtbl;

interface __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSession
{
    CONST_VTBL struct __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSessionVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSession_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSession_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSession_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSession_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSession_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSession_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSession_add_SetupRequested(This, setupEventHandler, token) \
    ((This)->lpVtbl->add_SetupRequested(This, setupEventHandler, token))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSession_remove_SetupRequested(This, token) \
    ((This)->lpVtbl->remove_SetupRequested(This, token))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSession_add_XpsDataAvailable(This, xpsDataAvailableEventHandler, token) \
    ((This)->lpVtbl->add_XpsDataAvailable(This, xpsDataAvailableEventHandler, token))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSession_remove_XpsDataAvailable(This, token) \
    ((This)->lpVtbl->remove_XpsDataAvailable(This, token))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSession_get_Status(This, value) \
    ((This)->lpVtbl->get_Status(This, value))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSession_Start(This) \
    ((This)->lpVtbl->Start(This))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSession;
#endif /* !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSession_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Interface Windows.Graphics.Printing.Workflow.IPrintWorkflowForegroundSetupRequestedEventArgs
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 * Interface is a part of the implementation of type Windows.Graphics.Printing.Workflow.PrintWorkflowForegroundSetupRequestedEventArgs
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSetupRequestedEventArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSetupRequestedEventArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Graphics_Printing_Workflow_IPrintWorkflowForegroundSetupRequestedEventArgs[] = L"Windows.Graphics.Printing.Workflow.IPrintWorkflowForegroundSetupRequestedEventArgs";
typedef struct __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSetupRequestedEventArgsVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSetupRequestedEventArgs* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSetupRequestedEventArgs* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSetupRequestedEventArgs* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSetupRequestedEventArgs* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSetupRequestedEventArgs* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSetupRequestedEventArgs* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* GetUserPrintTicketAsync)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSetupRequestedEventArgs* This,
        __FIAsyncOperation_1_Windows__CGraphics__CPrinting__CPrintTicket__CWorkflowPrintTicket** operation);
    HRESULT (STDMETHODCALLTYPE* get_Configuration)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSetupRequestedEventArgs* This,
        __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration** value);
    HRESULT (STDMETHODCALLTYPE* GetDeferral)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSetupRequestedEventArgs* This,
        __x_ABI_CWindows_CFoundation_CIDeferral** result);

    END_INTERFACE
} __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSetupRequestedEventArgsVtbl;

interface __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSetupRequestedEventArgs
{
    CONST_VTBL struct __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSetupRequestedEventArgsVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSetupRequestedEventArgs_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSetupRequestedEventArgs_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSetupRequestedEventArgs_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSetupRequestedEventArgs_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSetupRequestedEventArgs_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSetupRequestedEventArgs_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSetupRequestedEventArgs_GetUserPrintTicketAsync(This, operation) \
    ((This)->lpVtbl->GetUserPrintTicketAsync(This, operation))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSetupRequestedEventArgs_get_Configuration(This, value) \
    ((This)->lpVtbl->get_Configuration(This, value))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSetupRequestedEventArgs_GetDeferral(This, result) \
    ((This)->lpVtbl->GetDeferral(This, result))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSetupRequestedEventArgs;
#endif /* !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSetupRequestedEventArgs_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Interface Windows.Graphics.Printing.Workflow.IPrintWorkflowObjectModelSourceFileContent
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 * Interface is a part of the implementation of type Windows.Graphics.Printing.Workflow.PrintWorkflowObjectModelSourceFileContent
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelSourceFileContent_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelSourceFileContent_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Graphics_Printing_Workflow_IPrintWorkflowObjectModelSourceFileContent[] = L"Windows.Graphics.Printing.Workflow.IPrintWorkflowObjectModelSourceFileContent";
typedef struct __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelSourceFileContentVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelSourceFileContent* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelSourceFileContent* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelSourceFileContent* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelSourceFileContent* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelSourceFileContent* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelSourceFileContent* This,
        TrustLevel* trustLevel);

    END_INTERFACE
} __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelSourceFileContentVtbl;

interface __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelSourceFileContent
{
    CONST_VTBL struct __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelSourceFileContentVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelSourceFileContent_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelSourceFileContent_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelSourceFileContent_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelSourceFileContent_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelSourceFileContent_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelSourceFileContent_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelSourceFileContent;
#endif /* !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelSourceFileContent_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Interface Windows.Graphics.Printing.Workflow.IPrintWorkflowObjectModelTargetPackage
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 * Interface is a part of the implementation of type Windows.Graphics.Printing.Workflow.PrintWorkflowObjectModelTargetPackage
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelTargetPackage_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelTargetPackage_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Graphics_Printing_Workflow_IPrintWorkflowObjectModelTargetPackage[] = L"Windows.Graphics.Printing.Workflow.IPrintWorkflowObjectModelTargetPackage";
typedef struct __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelTargetPackageVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelTargetPackage* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelTargetPackage* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelTargetPackage* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelTargetPackage* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelTargetPackage* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelTargetPackage* This,
        TrustLevel* trustLevel);

    END_INTERFACE
} __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelTargetPackageVtbl;

interface __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelTargetPackage
{
    CONST_VTBL struct __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelTargetPackageVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelTargetPackage_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelTargetPackage_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelTargetPackage_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelTargetPackage_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelTargetPackage_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelTargetPackage_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelTargetPackage;
#endif /* !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelTargetPackage_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Interface Windows.Graphics.Printing.Workflow.IPrintWorkflowSourceContent
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 * Interface is a part of the implementation of type Windows.Graphics.Printing.Workflow.PrintWorkflowSourceContent
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSourceContent_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSourceContent_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Graphics_Printing_Workflow_IPrintWorkflowSourceContent[] = L"Windows.Graphics.Printing.Workflow.IPrintWorkflowSourceContent";
typedef struct __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSourceContentVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSourceContent* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSourceContent* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSourceContent* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSourceContent* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSourceContent* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSourceContent* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* GetJobPrintTicketAsync)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSourceContent* This,
        __FIAsyncOperation_1_Windows__CGraphics__CPrinting__CPrintTicket__CWorkflowPrintTicket** operation);
    HRESULT (STDMETHODCALLTYPE* GetSourceSpoolDataAsStreamContent)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSourceContent* This,
        __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSpoolStreamContent** result);
    HRESULT (STDMETHODCALLTYPE* GetSourceSpoolDataAsXpsObjectModel)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSourceContent* This,
        __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelSourceFileContent** result);

    END_INTERFACE
} __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSourceContentVtbl;

interface __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSourceContent
{
    CONST_VTBL struct __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSourceContentVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSourceContent_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSourceContent_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSourceContent_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSourceContent_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSourceContent_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSourceContent_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSourceContent_GetJobPrintTicketAsync(This, operation) \
    ((This)->lpVtbl->GetJobPrintTicketAsync(This, operation))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSourceContent_GetSourceSpoolDataAsStreamContent(This, result) \
    ((This)->lpVtbl->GetSourceSpoolDataAsStreamContent(This, result))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSourceContent_GetSourceSpoolDataAsXpsObjectModel(This, result) \
    ((This)->lpVtbl->GetSourceSpoolDataAsXpsObjectModel(This, result))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSourceContent;
#endif /* !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSourceContent_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Interface Windows.Graphics.Printing.Workflow.IPrintWorkflowSpoolStreamContent
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 * Interface is a part of the implementation of type Windows.Graphics.Printing.Workflow.PrintWorkflowSpoolStreamContent
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSpoolStreamContent_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSpoolStreamContent_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Graphics_Printing_Workflow_IPrintWorkflowSpoolStreamContent[] = L"Windows.Graphics.Printing.Workflow.IPrintWorkflowSpoolStreamContent";
typedef struct __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSpoolStreamContentVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSpoolStreamContent* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSpoolStreamContent* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSpoolStreamContent* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSpoolStreamContent* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSpoolStreamContent* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSpoolStreamContent* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* GetInputStream)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSpoolStreamContent* This,
        __x_ABI_CWindows_CStorage_CStreams_CIInputStream** result);

    END_INTERFACE
} __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSpoolStreamContentVtbl;

interface __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSpoolStreamContent
{
    CONST_VTBL struct __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSpoolStreamContentVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSpoolStreamContent_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSpoolStreamContent_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSpoolStreamContent_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSpoolStreamContent_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSpoolStreamContent_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSpoolStreamContent_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSpoolStreamContent_GetInputStream(This, result) \
    ((This)->lpVtbl->GetInputStream(This, result))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSpoolStreamContent;
#endif /* !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSpoolStreamContent_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Interface Windows.Graphics.Printing.Workflow.IPrintWorkflowStreamTarget
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 * Interface is a part of the implementation of type Windows.Graphics.Printing.Workflow.PrintWorkflowStreamTarget
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowStreamTarget_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowStreamTarget_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Graphics_Printing_Workflow_IPrintWorkflowStreamTarget[] = L"Windows.Graphics.Printing.Workflow.IPrintWorkflowStreamTarget";
typedef struct __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowStreamTargetVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowStreamTarget* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowStreamTarget* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowStreamTarget* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowStreamTarget* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowStreamTarget* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowStreamTarget* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* GetOutputStream)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowStreamTarget* This,
        __x_ABI_CWindows_CStorage_CStreams_CIOutputStream** result);

    END_INTERFACE
} __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowStreamTargetVtbl;

interface __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowStreamTarget
{
    CONST_VTBL struct __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowStreamTargetVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowStreamTarget_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowStreamTarget_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowStreamTarget_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowStreamTarget_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowStreamTarget_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowStreamTarget_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowStreamTarget_GetOutputStream(This, result) \
    ((This)->lpVtbl->GetOutputStream(This, result))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowStreamTarget;
#endif /* !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowStreamTarget_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Interface Windows.Graphics.Printing.Workflow.IPrintWorkflowSubmittedEventArgs
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 * Interface is a part of the implementation of type Windows.Graphics.Printing.Workflow.PrintWorkflowSubmittedEventArgs
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedEventArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedEventArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Graphics_Printing_Workflow_IPrintWorkflowSubmittedEventArgs[] = L"Windows.Graphics.Printing.Workflow.IPrintWorkflowSubmittedEventArgs";
typedef struct __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedEventArgsVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedEventArgs* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedEventArgs* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedEventArgs* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedEventArgs* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedEventArgs* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedEventArgs* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Operation)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedEventArgs* This,
        __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedOperation** value);
    HRESULT (STDMETHODCALLTYPE* GetTarget)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedEventArgs* This,
        __x_ABI_CWindows_CGraphics_CPrinting_CPrintTicket_CIWorkflowPrintTicket* jobPrintTicket,
        __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowTarget** result);
    HRESULT (STDMETHODCALLTYPE* GetDeferral)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedEventArgs* This,
        __x_ABI_CWindows_CFoundation_CIDeferral** result);

    END_INTERFACE
} __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedEventArgsVtbl;

interface __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedEventArgs
{
    CONST_VTBL struct __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedEventArgsVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedEventArgs_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedEventArgs_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedEventArgs_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedEventArgs_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedEventArgs_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedEventArgs_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedEventArgs_get_Operation(This, value) \
    ((This)->lpVtbl->get_Operation(This, value))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedEventArgs_GetTarget(This, jobPrintTicket, result) \
    ((This)->lpVtbl->GetTarget(This, jobPrintTicket, result))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedEventArgs_GetDeferral(This, result) \
    ((This)->lpVtbl->GetDeferral(This, result))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedEventArgs;
#endif /* !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedEventArgs_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Interface Windows.Graphics.Printing.Workflow.IPrintWorkflowSubmittedOperation
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 * Interface is a part of the implementation of type Windows.Graphics.Printing.Workflow.PrintWorkflowSubmittedOperation
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedOperation_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedOperation_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Graphics_Printing_Workflow_IPrintWorkflowSubmittedOperation[] = L"Windows.Graphics.Printing.Workflow.IPrintWorkflowSubmittedOperation";
typedef struct __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedOperationVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedOperation* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedOperation* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedOperation* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedOperation* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedOperation* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedOperation* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* Complete)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedOperation* This,
        enum __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CPrintWorkflowSubmittedStatus status);
    HRESULT (STDMETHODCALLTYPE* get_Configuration)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedOperation* This,
        __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration** value);
    HRESULT (STDMETHODCALLTYPE* get_XpsContent)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedOperation* This,
        __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSourceContent** value);

    END_INTERFACE
} __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedOperationVtbl;

interface __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedOperation
{
    CONST_VTBL struct __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedOperationVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedOperation_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedOperation_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedOperation_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedOperation_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedOperation_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedOperation_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedOperation_Complete(This, status) \
    ((This)->lpVtbl->Complete(This, status))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedOperation_get_Configuration(This, value) \
    ((This)->lpVtbl->get_Configuration(This, value))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedOperation_get_XpsContent(This, value) \
    ((This)->lpVtbl->get_XpsContent(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedOperation;
#endif /* !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedOperation_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Interface Windows.Graphics.Printing.Workflow.IPrintWorkflowTarget
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 * Interface is a part of the implementation of type Windows.Graphics.Printing.Workflow.PrintWorkflowTarget
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowTarget_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowTarget_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Graphics_Printing_Workflow_IPrintWorkflowTarget[] = L"Windows.Graphics.Printing.Workflow.IPrintWorkflowTarget";
typedef struct __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowTargetVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowTarget* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowTarget* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowTarget* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowTarget* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowTarget* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowTarget* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_TargetAsStream)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowTarget* This,
        __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowStreamTarget** value);
    HRESULT (STDMETHODCALLTYPE* get_TargetAsXpsObjectModelPackage)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowTarget* This,
        __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelTargetPackage** value);

    END_INTERFACE
} __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowTargetVtbl;

interface __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowTarget
{
    CONST_VTBL struct __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowTargetVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowTarget_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowTarget_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowTarget_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowTarget_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowTarget_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowTarget_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowTarget_get_TargetAsStream(This, value) \
    ((This)->lpVtbl->get_TargetAsStream(This, value))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowTarget_get_TargetAsXpsObjectModelPackage(This, value) \
    ((This)->lpVtbl->get_TargetAsXpsObjectModelPackage(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowTarget;
#endif /* !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowTarget_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Interface Windows.Graphics.Printing.Workflow.IPrintWorkflowTriggerDetails
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 * Interface is a part of the implementation of type Windows.Graphics.Printing.Workflow.PrintWorkflowTriggerDetails
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowTriggerDetails_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowTriggerDetails_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Graphics_Printing_Workflow_IPrintWorkflowTriggerDetails[] = L"Windows.Graphics.Printing.Workflow.IPrintWorkflowTriggerDetails";
typedef struct __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowTriggerDetailsVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowTriggerDetails* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowTriggerDetails* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowTriggerDetails* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowTriggerDetails* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowTriggerDetails* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowTriggerDetails* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_PrintWorkflowSession)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowTriggerDetails* This,
        __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowBackgroundSession** value);

    END_INTERFACE
} __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowTriggerDetailsVtbl;

interface __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowTriggerDetails
{
    CONST_VTBL struct __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowTriggerDetailsVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowTriggerDetails_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowTriggerDetails_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowTriggerDetails_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowTriggerDetails_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowTriggerDetails_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowTriggerDetails_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowTriggerDetails_get_PrintWorkflowSession(This, value) \
    ((This)->lpVtbl->get_PrintWorkflowSession(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowTriggerDetails;
#endif /* !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowTriggerDetails_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Interface Windows.Graphics.Printing.Workflow.IPrintWorkflowUIActivatedEventArgs
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 * Interface is a part of the implementation of type Windows.Graphics.Printing.Workflow.PrintWorkflowUIActivatedEventArgs
 *
 * Any object which implements this interface must also implement the following interfaces:
 *     Windows.ApplicationModel.Activation.IActivatedEventArgs
 *     Windows.ApplicationModel.Activation.IActivatedEventArgsWithUser
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowUIActivatedEventArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowUIActivatedEventArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Graphics_Printing_Workflow_IPrintWorkflowUIActivatedEventArgs[] = L"Windows.Graphics.Printing.Workflow.IPrintWorkflowUIActivatedEventArgs";
typedef struct __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowUIActivatedEventArgsVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowUIActivatedEventArgs* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowUIActivatedEventArgs* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowUIActivatedEventArgs* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowUIActivatedEventArgs* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowUIActivatedEventArgs* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowUIActivatedEventArgs* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_PrintWorkflowSession)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowUIActivatedEventArgs* This,
        __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSession** value);

    END_INTERFACE
} __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowUIActivatedEventArgsVtbl;

interface __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowUIActivatedEventArgs
{
    CONST_VTBL struct __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowUIActivatedEventArgsVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowUIActivatedEventArgs_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowUIActivatedEventArgs_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowUIActivatedEventArgs_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowUIActivatedEventArgs_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowUIActivatedEventArgs_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowUIActivatedEventArgs_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowUIActivatedEventArgs_get_PrintWorkflowSession(This, value) \
    ((This)->lpVtbl->get_PrintWorkflowSession(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowUIActivatedEventArgs;
#endif /* !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowUIActivatedEventArgs_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Interface Windows.Graphics.Printing.Workflow.IPrintWorkflowXpsDataAvailableEventArgs
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 * Interface is a part of the implementation of type Windows.Graphics.Printing.Workflow.PrintWorkflowXpsDataAvailableEventArgs
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowXpsDataAvailableEventArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowXpsDataAvailableEventArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Graphics_Printing_Workflow_IPrintWorkflowXpsDataAvailableEventArgs[] = L"Windows.Graphics.Printing.Workflow.IPrintWorkflowXpsDataAvailableEventArgs";
typedef struct __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowXpsDataAvailableEventArgsVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowXpsDataAvailableEventArgs* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowXpsDataAvailableEventArgs* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowXpsDataAvailableEventArgs* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowXpsDataAvailableEventArgs* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowXpsDataAvailableEventArgs* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowXpsDataAvailableEventArgs* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Operation)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowXpsDataAvailableEventArgs* This,
        __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowSubmittedOperation** value);
    HRESULT (STDMETHODCALLTYPE* GetDeferral)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowXpsDataAvailableEventArgs* This,
        __x_ABI_CWindows_CFoundation_CIDeferral** result);

    END_INTERFACE
} __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowXpsDataAvailableEventArgsVtbl;

interface __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowXpsDataAvailableEventArgs
{
    CONST_VTBL struct __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowXpsDataAvailableEventArgsVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowXpsDataAvailableEventArgs_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowXpsDataAvailableEventArgs_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowXpsDataAvailableEventArgs_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowXpsDataAvailableEventArgs_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowXpsDataAvailableEventArgs_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowXpsDataAvailableEventArgs_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowXpsDataAvailableEventArgs_get_Operation(This, value) \
    ((This)->lpVtbl->get_Operation(This, value))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowXpsDataAvailableEventArgs_GetDeferral(This, result) \
    ((This)->lpVtbl->GetDeferral(This, result))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowXpsDataAvailableEventArgs;
#endif /* !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowXpsDataAvailableEventArgs_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Class Windows.Graphics.Printing.Workflow.PrintWorkflowBackgroundSession
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 * Class implements the following interfaces:
 *    Windows.Graphics.Printing.Workflow.IPrintWorkflowBackgroundSession ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#ifndef RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowBackgroundSession_DEFINED
#define RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowBackgroundSession_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Graphics_Printing_Workflow_PrintWorkflowBackgroundSession[] = L"Windows.Graphics.Printing.Workflow.PrintWorkflowBackgroundSession";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Class Windows.Graphics.Printing.Workflow.PrintWorkflowBackgroundSetupRequestedEventArgs
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 * Class implements the following interfaces:
 *    Windows.Graphics.Printing.Workflow.IPrintWorkflowBackgroundSetupRequestedEventArgs ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#ifndef RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowBackgroundSetupRequestedEventArgs_DEFINED
#define RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowBackgroundSetupRequestedEventArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Graphics_Printing_Workflow_PrintWorkflowBackgroundSetupRequestedEventArgs[] = L"Windows.Graphics.Printing.Workflow.PrintWorkflowBackgroundSetupRequestedEventArgs";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Class Windows.Graphics.Printing.Workflow.PrintWorkflowConfiguration
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 * Class implements the following interfaces:
 *    Windows.Graphics.Printing.Workflow.IPrintWorkflowConfiguration ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#ifndef RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowConfiguration_DEFINED
#define RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowConfiguration_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Graphics_Printing_Workflow_PrintWorkflowConfiguration[] = L"Windows.Graphics.Printing.Workflow.PrintWorkflowConfiguration";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Class Windows.Graphics.Printing.Workflow.PrintWorkflowForegroundSession
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 * Class implements the following interfaces:
 *    Windows.Graphics.Printing.Workflow.IPrintWorkflowForegroundSession ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#ifndef RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowForegroundSession_DEFINED
#define RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowForegroundSession_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Graphics_Printing_Workflow_PrintWorkflowForegroundSession[] = L"Windows.Graphics.Printing.Workflow.PrintWorkflowForegroundSession";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Class Windows.Graphics.Printing.Workflow.PrintWorkflowForegroundSetupRequestedEventArgs
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 * Class implements the following interfaces:
 *    Windows.Graphics.Printing.Workflow.IPrintWorkflowForegroundSetupRequestedEventArgs ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#ifndef RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowForegroundSetupRequestedEventArgs_DEFINED
#define RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowForegroundSetupRequestedEventArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Graphics_Printing_Workflow_PrintWorkflowForegroundSetupRequestedEventArgs[] = L"Windows.Graphics.Printing.Workflow.PrintWorkflowForegroundSetupRequestedEventArgs";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Class Windows.Graphics.Printing.Workflow.PrintWorkflowObjectModelSourceFileContent
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 * Class implements the following interfaces:
 *    Windows.Graphics.Printing.Workflow.IPrintWorkflowObjectModelSourceFileContent ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#ifndef RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowObjectModelSourceFileContent_DEFINED
#define RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowObjectModelSourceFileContent_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Graphics_Printing_Workflow_PrintWorkflowObjectModelSourceFileContent[] = L"Windows.Graphics.Printing.Workflow.PrintWorkflowObjectModelSourceFileContent";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Class Windows.Graphics.Printing.Workflow.PrintWorkflowObjectModelTargetPackage
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 * Class implements the following interfaces:
 *    Windows.Graphics.Printing.Workflow.IPrintWorkflowObjectModelTargetPackage ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#ifndef RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowObjectModelTargetPackage_DEFINED
#define RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowObjectModelTargetPackage_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Graphics_Printing_Workflow_PrintWorkflowObjectModelTargetPackage[] = L"Windows.Graphics.Printing.Workflow.PrintWorkflowObjectModelTargetPackage";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Class Windows.Graphics.Printing.Workflow.PrintWorkflowSourceContent
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 * Class implements the following interfaces:
 *    Windows.Graphics.Printing.Workflow.IPrintWorkflowSourceContent ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#ifndef RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowSourceContent_DEFINED
#define RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowSourceContent_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Graphics_Printing_Workflow_PrintWorkflowSourceContent[] = L"Windows.Graphics.Printing.Workflow.PrintWorkflowSourceContent";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Class Windows.Graphics.Printing.Workflow.PrintWorkflowSpoolStreamContent
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 * Class implements the following interfaces:
 *    Windows.Graphics.Printing.Workflow.IPrintWorkflowSpoolStreamContent ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#ifndef RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowSpoolStreamContent_DEFINED
#define RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowSpoolStreamContent_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Graphics_Printing_Workflow_PrintWorkflowSpoolStreamContent[] = L"Windows.Graphics.Printing.Workflow.PrintWorkflowSpoolStreamContent";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Class Windows.Graphics.Printing.Workflow.PrintWorkflowStreamTarget
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 * Class implements the following interfaces:
 *    Windows.Graphics.Printing.Workflow.IPrintWorkflowStreamTarget ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#ifndef RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowStreamTarget_DEFINED
#define RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowStreamTarget_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Graphics_Printing_Workflow_PrintWorkflowStreamTarget[] = L"Windows.Graphics.Printing.Workflow.PrintWorkflowStreamTarget";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Class Windows.Graphics.Printing.Workflow.PrintWorkflowSubmittedEventArgs
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 * Class implements the following interfaces:
 *    Windows.Graphics.Printing.Workflow.IPrintWorkflowSubmittedEventArgs ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#ifndef RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowSubmittedEventArgs_DEFINED
#define RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowSubmittedEventArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Graphics_Printing_Workflow_PrintWorkflowSubmittedEventArgs[] = L"Windows.Graphics.Printing.Workflow.PrintWorkflowSubmittedEventArgs";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Class Windows.Graphics.Printing.Workflow.PrintWorkflowSubmittedOperation
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 * Class implements the following interfaces:
 *    Windows.Graphics.Printing.Workflow.IPrintWorkflowSubmittedOperation ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#ifndef RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowSubmittedOperation_DEFINED
#define RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowSubmittedOperation_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Graphics_Printing_Workflow_PrintWorkflowSubmittedOperation[] = L"Windows.Graphics.Printing.Workflow.PrintWorkflowSubmittedOperation";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Class Windows.Graphics.Printing.Workflow.PrintWorkflowTarget
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 * Class implements the following interfaces:
 *    Windows.Graphics.Printing.Workflow.IPrintWorkflowTarget ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#ifndef RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowTarget_DEFINED
#define RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowTarget_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Graphics_Printing_Workflow_PrintWorkflowTarget[] = L"Windows.Graphics.Printing.Workflow.PrintWorkflowTarget";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Class Windows.Graphics.Printing.Workflow.PrintWorkflowTriggerDetails
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 * Class implements the following interfaces:
 *    Windows.Graphics.Printing.Workflow.IPrintWorkflowTriggerDetails ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#ifndef RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowTriggerDetails_DEFINED
#define RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowTriggerDetails_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Graphics_Printing_Workflow_PrintWorkflowTriggerDetails[] = L"Windows.Graphics.Printing.Workflow.PrintWorkflowTriggerDetails";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Class Windows.Graphics.Printing.Workflow.PrintWorkflowUIActivatedEventArgs
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 * Class implements the following interfaces:
 *    Windows.Graphics.Printing.Workflow.IPrintWorkflowUIActivatedEventArgs ** Default Interface **
 *    Windows.ApplicationModel.Activation.IActivatedEventArgsWithUser
 *    Windows.ApplicationModel.Activation.IActivatedEventArgs
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#ifndef RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowUIActivatedEventArgs_DEFINED
#define RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowUIActivatedEventArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Graphics_Printing_Workflow_PrintWorkflowUIActivatedEventArgs[] = L"Windows.Graphics.Printing.Workflow.PrintWorkflowUIActivatedEventArgs";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Class Windows.Graphics.Printing.Workflow.PrintWorkflowXpsDataAvailableEventArgs
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 * Class implements the following interfaces:
 *    Windows.Graphics.Printing.Workflow.IPrintWorkflowXpsDataAvailableEventArgs ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#ifndef RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowXpsDataAvailableEventArgs_DEFINED
#define RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowXpsDataAvailableEventArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Graphics_Printing_Workflow_PrintWorkflowXpsDataAvailableEventArgs[] = L"Windows.Graphics.Printing.Workflow.PrintWorkflowXpsDataAvailableEventArgs";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

#endif // defined(__cplusplus)
#pragma pop_macro("MIDL_CONST_ID")
// Restore the original value of the 'DEPRECATED' macro
#pragma pop_macro("DEPRECATED")

#ifdef __clang__
#pragma clang diagnostic pop // deprecated-declarations
#else
#pragma warning(pop)
#endif
#endif // __windows2Egraphics2Eprinting2Eworkflow_p_h__

#endif // __windows2Egraphics2Eprinting2Eworkflow_h__
