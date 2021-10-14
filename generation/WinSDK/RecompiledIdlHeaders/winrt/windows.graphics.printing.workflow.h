
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
#include "Windows.ApplicationModel.Activation.h"
#include "Windows.Devices.Printers.h"
#include "Windows.Graphics.Printing.PrintTicket.h"
#include "Windows.Storage.h"
#include "Windows.Storage.Streams.h"
// Importing Collections header
#include <windows.foundation.collections.h>

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

#ifndef ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration2_FWD_DEFINED__
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration2_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    interface IPrintWorkflowConfiguration2;
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration2 ABI::Windows::Graphics::Printing::Workflow::IPrintWorkflowConfiguration2

#endif // ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration2_FWD_DEFINED__

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

#ifndef ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobActivatedEventArgs_FWD_DEFINED__
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobActivatedEventArgs_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    interface IPrintWorkflowJobActivatedEventArgs;
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobActivatedEventArgs ABI::Windows::Graphics::Printing::Workflow::IPrintWorkflowJobActivatedEventArgs

#endif // ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobActivatedEventArgs_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobBackgroundSession_FWD_DEFINED__
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobBackgroundSession_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    interface IPrintWorkflowJobBackgroundSession;
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobBackgroundSession ABI::Windows::Graphics::Printing::Workflow::IPrintWorkflowJobBackgroundSession

#endif // ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobBackgroundSession_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobNotificationEventArgs_FWD_DEFINED__
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobNotificationEventArgs_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    interface IPrintWorkflowJobNotificationEventArgs;
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobNotificationEventArgs ABI::Windows::Graphics::Printing::Workflow::IPrintWorkflowJobNotificationEventArgs

#endif // ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobNotificationEventArgs_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobStartingEventArgs_FWD_DEFINED__
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobStartingEventArgs_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    interface IPrintWorkflowJobStartingEventArgs;
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobStartingEventArgs ABI::Windows::Graphics::Printing::Workflow::IPrintWorkflowJobStartingEventArgs

#endif // ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobStartingEventArgs_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobTriggerDetails_FWD_DEFINED__
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobTriggerDetails_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    interface IPrintWorkflowJobTriggerDetails;
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobTriggerDetails ABI::Windows::Graphics::Printing::Workflow::IPrintWorkflowJobTriggerDetails

#endif // ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobTriggerDetails_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobUISession_FWD_DEFINED__
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobUISession_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    interface IPrintWorkflowJobUISession;
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobUISession ABI::Windows::Graphics::Printing::Workflow::IPrintWorkflowJobUISession

#endif // ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobUISession_FWD_DEFINED__

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

#ifndef ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelSourceFileContentFactory_FWD_DEFINED__
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelSourceFileContentFactory_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    interface IPrintWorkflowObjectModelSourceFileContentFactory;
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelSourceFileContentFactory ABI::Windows::Graphics::Printing::Workflow::IPrintWorkflowObjectModelSourceFileContentFactory

#endif // ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelSourceFileContentFactory_FWD_DEFINED__

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

#ifndef ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlConverter_FWD_DEFINED__
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlConverter_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    interface IPrintWorkflowPdlConverter;
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlConverter ABI::Windows::Graphics::Printing::Workflow::IPrintWorkflowPdlConverter

#endif // ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlConverter_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlDataAvailableEventArgs_FWD_DEFINED__
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlDataAvailableEventArgs_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    interface IPrintWorkflowPdlDataAvailableEventArgs;
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlDataAvailableEventArgs ABI::Windows::Graphics::Printing::Workflow::IPrintWorkflowPdlDataAvailableEventArgs

#endif // ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlDataAvailableEventArgs_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlModificationRequestedEventArgs_FWD_DEFINED__
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlModificationRequestedEventArgs_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    interface IPrintWorkflowPdlModificationRequestedEventArgs;
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlModificationRequestedEventArgs ABI::Windows::Graphics::Printing::Workflow::IPrintWorkflowPdlModificationRequestedEventArgs

#endif // ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlModificationRequestedEventArgs_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlSourceContent_FWD_DEFINED__
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlSourceContent_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    interface IPrintWorkflowPdlSourceContent;
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlSourceContent ABI::Windows::Graphics::Printing::Workflow::IPrintWorkflowPdlSourceContent

#endif // ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlSourceContent_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlTargetStream_FWD_DEFINED__
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlTargetStream_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    interface IPrintWorkflowPdlTargetStream;
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlTargetStream ABI::Windows::Graphics::Printing::Workflow::IPrintWorkflowPdlTargetStream

#endif // ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlTargetStream_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPrinterJob_FWD_DEFINED__
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPrinterJob_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    interface IPrintWorkflowPrinterJob;
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPrinterJob ABI::Windows::Graphics::Printing::Workflow::IPrintWorkflowPrinterJob

#endif // ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPrinterJob_FWD_DEFINED__

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

#ifndef ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowUILauncher_FWD_DEFINED__
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowUILauncher_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    interface IPrintWorkflowUILauncher;
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowUILauncher ABI::Windows::Graphics::Printing::Workflow::IPrintWorkflowUILauncher

#endif // ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowUILauncher_FWD_DEFINED__

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
                    typedef enum PrintWorkflowUICompletionStatus : int PrintWorkflowUICompletionStatus;
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#ifndef DEF___FIAsyncOperation_1_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowUICompletionStatus_USE
#define DEF___FIAsyncOperation_1_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowUICompletionStatus_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation {
template <>
struct __declspec(uuid("e4312e4b-c35d-5ccb-b290-72d0c4a808a6"))
IAsyncOperation<enum ABI::Windows::Graphics::Printing::Workflow::PrintWorkflowUICompletionStatus> : IAsyncOperation_impl<enum ABI::Windows::Graphics::Printing::Workflow::PrintWorkflowUICompletionStatus>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.IAsyncOperation`1<Windows.Graphics.Printing.Workflow.PrintWorkflowUICompletionStatus>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IAsyncOperation<enum ABI::Windows::Graphics::Printing::Workflow::PrintWorkflowUICompletionStatus> __FIAsyncOperation_1_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowUICompletionStatus_t;
#define __FIAsyncOperation_1_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowUICompletionStatus ABI::Windows::Foundation::__FIAsyncOperation_1_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowUICompletionStatus_t
/* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIAsyncOperation_1_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowUICompletionStatus_USE */

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#ifndef DEF___FIAsyncOperationCompletedHandler_1_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowUICompletionStatus_USE
#define DEF___FIAsyncOperationCompletedHandler_1_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowUICompletionStatus_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation {
template <>
struct __declspec(uuid("2cf68098-e07d-5362-a2ad-356551327df2"))
IAsyncOperationCompletedHandler<enum ABI::Windows::Graphics::Printing::Workflow::PrintWorkflowUICompletionStatus> : IAsyncOperationCompletedHandler_impl<enum ABI::Windows::Graphics::Printing::Workflow::PrintWorkflowUICompletionStatus>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.AsyncOperationCompletedHandler`1<Windows.Graphics.Printing.Workflow.PrintWorkflowUICompletionStatus>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IAsyncOperationCompletedHandler<enum ABI::Windows::Graphics::Printing::Workflow::PrintWorkflowUICompletionStatus> __FIAsyncOperationCompletedHandler_1_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowUICompletionStatus_t;
#define __FIAsyncOperationCompletedHandler_1_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowUICompletionStatus ABI::Windows::Foundation::__FIAsyncOperationCompletedHandler_1_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowUICompletionStatus_t
/* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIAsyncOperationCompletedHandler_1_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowUICompletionStatus_USE */

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

namespace ABI {
    namespace Windows {
        namespace Storage {
            class StorageFile;
        } /* Storage */
    } /* Windows */
} /* ABI */

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

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#ifndef DEF___FIAsyncOperation_1_Windows__CStorage__CStorageFile_USE
#define DEF___FIAsyncOperation_1_Windows__CStorage__CStorageFile_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation {
template <>
struct __declspec(uuid("5e52f8ce-aced-5a42-95b4-f674dd84885e"))
IAsyncOperation<ABI::Windows::Storage::StorageFile*> : IAsyncOperation_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Storage::StorageFile*, ABI::Windows::Storage::IStorageFile*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.IAsyncOperation`1<Windows.Storage.StorageFile>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IAsyncOperation<ABI::Windows::Storage::StorageFile*> __FIAsyncOperation_1_Windows__CStorage__CStorageFile_t;
#define __FIAsyncOperation_1_Windows__CStorage__CStorageFile ABI::Windows::Foundation::__FIAsyncOperation_1_Windows__CStorage__CStorageFile_t
/* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIAsyncOperation_1_Windows__CStorage__CStorageFile_USE */

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#ifndef DEF___FIAsyncOperationCompletedHandler_1_Windows__CStorage__CStorageFile_USE
#define DEF___FIAsyncOperationCompletedHandler_1_Windows__CStorage__CStorageFile_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation {
template <>
struct __declspec(uuid("e521c894-2c26-5946-9e61-2b5e188d01ed"))
IAsyncOperationCompletedHandler<ABI::Windows::Storage::StorageFile*> : IAsyncOperationCompletedHandler_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Storage::StorageFile*, ABI::Windows::Storage::IStorageFile*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.AsyncOperationCompletedHandler`1<Windows.Storage.StorageFile>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IAsyncOperationCompletedHandler<ABI::Windows::Storage::StorageFile*> __FIAsyncOperationCompletedHandler_1_Windows__CStorage__CStorageFile_t;
#define __FIAsyncOperationCompletedHandler_1_Windows__CStorage__CStorageFile ABI::Windows::Foundation::__FIAsyncOperationCompletedHandler_1_Windows__CStorage__CStorageFile_t
/* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIAsyncOperationCompletedHandler_1_Windows__CStorage__CStorageFile_USE */

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
        namespace Devices {
            namespace Printers {
                class IppAttributeValue;
            } /* Printers */
        } /* Devices */
    } /* Windows */
} /* ABI */

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

namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    class PrintWorkflowJobBackgroundSession;
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
                    class PrintWorkflowJobStartingEventArgs;
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#ifndef DEF___FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobStartingEventArgs_USE
#define DEF___FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobStartingEventArgs_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation {
template <>
struct __declspec(uuid("03d7ca7e-089d-5ff2-bae1-46d664f818af"))
ITypedEventHandler<ABI::Windows::Graphics::Printing::Workflow::PrintWorkflowJobBackgroundSession*, ABI::Windows::Graphics::Printing::Workflow::PrintWorkflowJobStartingEventArgs*> : ITypedEventHandler_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Graphics::Printing::Workflow::PrintWorkflowJobBackgroundSession*, ABI::Windows::Graphics::Printing::Workflow::IPrintWorkflowJobBackgroundSession*>, ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Graphics::Printing::Workflow::PrintWorkflowJobStartingEventArgs*, ABI::Windows::Graphics::Printing::Workflow::IPrintWorkflowJobStartingEventArgs*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.TypedEventHandler`2<Windows.Graphics.Printing.Workflow.PrintWorkflowJobBackgroundSession, Windows.Graphics.Printing.Workflow.PrintWorkflowJobStartingEventArgs>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef ITypedEventHandler<ABI::Windows::Graphics::Printing::Workflow::PrintWorkflowJobBackgroundSession*, ABI::Windows::Graphics::Printing::Workflow::PrintWorkflowJobStartingEventArgs*> __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobStartingEventArgs_t;
#define __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobStartingEventArgs ABI::Windows::Foundation::__FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobStartingEventArgs_t
/* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobStartingEventArgs_USE */

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    class PrintWorkflowPdlModificationRequestedEventArgs;
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#ifndef DEF___FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowPdlModificationRequestedEventArgs_USE
#define DEF___FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowPdlModificationRequestedEventArgs_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation {
template <>
struct __declspec(uuid("c9a3b256-9f44-5cd5-a02e-7d5f52e8bd5d"))
ITypedEventHandler<ABI::Windows::Graphics::Printing::Workflow::PrintWorkflowJobBackgroundSession*, ABI::Windows::Graphics::Printing::Workflow::PrintWorkflowPdlModificationRequestedEventArgs*> : ITypedEventHandler_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Graphics::Printing::Workflow::PrintWorkflowJobBackgroundSession*, ABI::Windows::Graphics::Printing::Workflow::IPrintWorkflowJobBackgroundSession*>, ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Graphics::Printing::Workflow::PrintWorkflowPdlModificationRequestedEventArgs*, ABI::Windows::Graphics::Printing::Workflow::IPrintWorkflowPdlModificationRequestedEventArgs*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.TypedEventHandler`2<Windows.Graphics.Printing.Workflow.PrintWorkflowJobBackgroundSession, Windows.Graphics.Printing.Workflow.PrintWorkflowPdlModificationRequestedEventArgs>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef ITypedEventHandler<ABI::Windows::Graphics::Printing::Workflow::PrintWorkflowJobBackgroundSession*, ABI::Windows::Graphics::Printing::Workflow::PrintWorkflowPdlModificationRequestedEventArgs*> __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowPdlModificationRequestedEventArgs_t;
#define __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowPdlModificationRequestedEventArgs ABI::Windows::Foundation::__FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowPdlModificationRequestedEventArgs_t
/* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowPdlModificationRequestedEventArgs_USE */

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    class PrintWorkflowJobUISession;
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
                    class PrintWorkflowJobNotificationEventArgs;
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#ifndef DEF___FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobUISession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobNotificationEventArgs_USE
#define DEF___FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobUISession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobNotificationEventArgs_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation {
template <>
struct __declspec(uuid("91a4746d-7840-5f88-97d6-ee39c5afb6e0"))
ITypedEventHandler<ABI::Windows::Graphics::Printing::Workflow::PrintWorkflowJobUISession*, ABI::Windows::Graphics::Printing::Workflow::PrintWorkflowJobNotificationEventArgs*> : ITypedEventHandler_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Graphics::Printing::Workflow::PrintWorkflowJobUISession*, ABI::Windows::Graphics::Printing::Workflow::IPrintWorkflowJobUISession*>, ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Graphics::Printing::Workflow::PrintWorkflowJobNotificationEventArgs*, ABI::Windows::Graphics::Printing::Workflow::IPrintWorkflowJobNotificationEventArgs*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.TypedEventHandler`2<Windows.Graphics.Printing.Workflow.PrintWorkflowJobUISession, Windows.Graphics.Printing.Workflow.PrintWorkflowJobNotificationEventArgs>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef ITypedEventHandler<ABI::Windows::Graphics::Printing::Workflow::PrintWorkflowJobUISession*, ABI::Windows::Graphics::Printing::Workflow::PrintWorkflowJobNotificationEventArgs*> __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobUISession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobNotificationEventArgs_t;
#define __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobUISession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobNotificationEventArgs ABI::Windows::Foundation::__FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobUISession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobNotificationEventArgs_t
/* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobUISession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobNotificationEventArgs_USE */

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    class PrintWorkflowPdlDataAvailableEventArgs;
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#ifndef DEF___FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobUISession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowPdlDataAvailableEventArgs_USE
#define DEF___FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobUISession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowPdlDataAvailableEventArgs_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation {
template <>
struct __declspec(uuid("5a185747-96bc-50ea-8d97-5a7d9e1c93ef"))
ITypedEventHandler<ABI::Windows::Graphics::Printing::Workflow::PrintWorkflowJobUISession*, ABI::Windows::Graphics::Printing::Workflow::PrintWorkflowPdlDataAvailableEventArgs*> : ITypedEventHandler_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Graphics::Printing::Workflow::PrintWorkflowJobUISession*, ABI::Windows::Graphics::Printing::Workflow::IPrintWorkflowJobUISession*>, ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Graphics::Printing::Workflow::PrintWorkflowPdlDataAvailableEventArgs*, ABI::Windows::Graphics::Printing::Workflow::IPrintWorkflowPdlDataAvailableEventArgs*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.TypedEventHandler`2<Windows.Graphics.Printing.Workflow.PrintWorkflowJobUISession, Windows.Graphics.Printing.Workflow.PrintWorkflowPdlDataAvailableEventArgs>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef ITypedEventHandler<ABI::Windows::Graphics::Printing::Workflow::PrintWorkflowJobUISession*, ABI::Windows::Graphics::Printing::Workflow::PrintWorkflowPdlDataAvailableEventArgs*> __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobUISession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowPdlDataAvailableEventArgs_t;
#define __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobUISession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowPdlDataAvailableEventArgs ABI::Windows::Foundation::__FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobUISession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowPdlDataAvailableEventArgs_t
/* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobUISession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowPdlDataAvailableEventArgs_USE */

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

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
        namespace Devices {
            namespace Printers {
                class IppPrintDevice;
            } /* Printers */
        } /* Devices */
    } /* Windows */
} /* ABI */

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

namespace ABI {
    namespace Windows {
        namespace Devices {
            namespace Printers {
                class IppSetAttributesResult;
            } /* Printers */
        } /* Devices */
    } /* Windows */
} /* ABI */

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
                    typedef enum PrintWorkflowJobAbortReason : int PrintWorkflowJobAbortReason;
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
                    typedef enum PrintWorkflowPdlConversionType : int PrintWorkflowPdlConversionType;
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
                    typedef enum PrintWorkflowPrinterJobStatus : int PrintWorkflowPrinterJobStatus;
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
                    class PrintWorkflowPdlConverter;
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
                    class PrintWorkflowPdlSourceContent;
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
                    class PrintWorkflowPdlTargetStream;
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
                    class PrintWorkflowPrinterJob;
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

namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    class PrintWorkflowUILauncher;
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */

/*
 *
 * Struct Windows.Graphics.Printing.Workflow.PrintWorkflowJobAbortReason
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    enum PrintWorkflowJobAbortReason : int
                    {
                        PrintWorkflowJobAbortReason_JobFailed = 0,
                        PrintWorkflowJobAbortReason_UserCanceled = 1,
                    };
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Struct Windows.Graphics.Printing.Workflow.PrintWorkflowPdlConversionType
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    enum PrintWorkflowPdlConversionType : int
                    {
                        PrintWorkflowPdlConversionType_XpsToPdf = 0,
                        PrintWorkflowPdlConversionType_XpsToPwgr = 1,
                        PrintWorkflowPdlConversionType_XpsToPclm = 2,
                    };
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Struct Windows.Graphics.Printing.Workflow.PrintWorkflowPrinterJobStatus
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    enum PrintWorkflowPrinterJobStatus : int
                    {
                        PrintWorkflowPrinterJobStatus_Error = 0,
                        PrintWorkflowPrinterJobStatus_Aborted = 1,
                        PrintWorkflowPrinterJobStatus_InProgress = 2,
                        PrintWorkflowPrinterJobStatus_Completed = 3,
                    };
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

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
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
                        PrintWorkflowSessionStatus_PdlDataAvailableForModification = 4,
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
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
 * Struct Windows.Graphics.Printing.Workflow.PrintWorkflowUICompletionStatus
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    enum PrintWorkflowUICompletionStatus : int
                    {
                        PrintWorkflowUICompletionStatus_Completed = 0,
                        PrintWorkflowUICompletionStatus_LaunchFailed = 1,
                        PrintWorkflowUICompletionStatus_JobFailed = 2,
                        PrintWorkflowUICompletionStatus_UserCanceled = 3,
                    };
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

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
 * Interface Windows.Graphics.Printing.Workflow.IPrintWorkflowConfiguration2
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Interface is a part of the implementation of type Windows.Graphics.Printing.Workflow.PrintWorkflowConfiguration
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration2_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration2_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Graphics_Printing_Workflow_IPrintWorkflowConfiguration2[] = L"Windows.Graphics.Printing.Workflow.IPrintWorkflowConfiguration2";
namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    MIDL_INTERFACE("de350a50-a6d4-5be2-8b9a-09d3d39ea780")
                    IPrintWorkflowConfiguration2 : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE AbortPrintFlow(
                            ABI::Windows::Graphics::Printing::Workflow::PrintWorkflowJobAbortReason reason
                            ) = 0;
                    };

                    extern MIDL_CONST_ID IID& IID_IPrintWorkflowConfiguration2 = _uuidof(IPrintWorkflowConfiguration2);
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration2;
#endif /* !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration2_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

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
 * Interface Windows.Graphics.Printing.Workflow.IPrintWorkflowJobActivatedEventArgs
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Interface is a part of the implementation of type Windows.Graphics.Printing.Workflow.PrintWorkflowJobActivatedEventArgs
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobActivatedEventArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobActivatedEventArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Graphics_Printing_Workflow_IPrintWorkflowJobActivatedEventArgs[] = L"Windows.Graphics.Printing.Workflow.IPrintWorkflowJobActivatedEventArgs";
namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    MIDL_INTERFACE("d4bd5e6d-034e-5e00-a616-f961a033dcc8")
                    IPrintWorkflowJobActivatedEventArgs : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE get_Session(
                            ABI::Windows::Graphics::Printing::Workflow::IPrintWorkflowJobUISession** value
                            ) = 0;
                    };

                    extern MIDL_CONST_ID IID& IID_IPrintWorkflowJobActivatedEventArgs = _uuidof(IPrintWorkflowJobActivatedEventArgs);
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobActivatedEventArgs;
#endif /* !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobActivatedEventArgs_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Interface Windows.Graphics.Printing.Workflow.IPrintWorkflowJobBackgroundSession
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Interface is a part of the implementation of type Windows.Graphics.Printing.Workflow.PrintWorkflowJobBackgroundSession
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobBackgroundSession_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobBackgroundSession_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Graphics_Printing_Workflow_IPrintWorkflowJobBackgroundSession[] = L"Windows.Graphics.Printing.Workflow.IPrintWorkflowJobBackgroundSession";
namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    MIDL_INTERFACE("c5ec6ad8-20c9-5d51-8507-2734b46f96c5")
                    IPrintWorkflowJobBackgroundSession : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE get_Status(
                            ABI::Windows::Graphics::Printing::Workflow::PrintWorkflowSessionStatus* value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE add_JobStarting(
                            __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobStartingEventArgs* handler,
                            EventRegistrationToken* token
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE remove_JobStarting(
                            EventRegistrationToken token
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE add_PdlModificationRequested(
                            __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowPdlModificationRequestedEventArgs* handler,
                            EventRegistrationToken* token
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE remove_PdlModificationRequested(
                            EventRegistrationToken token
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE Start(void) = 0;
                    };

                    extern MIDL_CONST_ID IID& IID_IPrintWorkflowJobBackgroundSession = _uuidof(IPrintWorkflowJobBackgroundSession);
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobBackgroundSession;
#endif /* !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobBackgroundSession_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Interface Windows.Graphics.Printing.Workflow.IPrintWorkflowJobNotificationEventArgs
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Interface is a part of the implementation of type Windows.Graphics.Printing.Workflow.PrintWorkflowJobNotificationEventArgs
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobNotificationEventArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobNotificationEventArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Graphics_Printing_Workflow_IPrintWorkflowJobNotificationEventArgs[] = L"Windows.Graphics.Printing.Workflow.IPrintWorkflowJobNotificationEventArgs";
namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    MIDL_INTERFACE("0ae16fba-5398-5eba-b472-978650186a9a")
                    IPrintWorkflowJobNotificationEventArgs : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE get_Configuration(
                            ABI::Windows::Graphics::Printing::Workflow::IPrintWorkflowConfiguration** value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_PrinterJob(
                            ABI::Windows::Graphics::Printing::Workflow::IPrintWorkflowPrinterJob** value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE GetDeferral(
                            ABI::Windows::Foundation::IDeferral** result
                            ) = 0;
                    };

                    extern MIDL_CONST_ID IID& IID_IPrintWorkflowJobNotificationEventArgs = _uuidof(IPrintWorkflowJobNotificationEventArgs);
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobNotificationEventArgs;
#endif /* !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobNotificationEventArgs_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Interface Windows.Graphics.Printing.Workflow.IPrintWorkflowJobStartingEventArgs
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Interface is a part of the implementation of type Windows.Graphics.Printing.Workflow.PrintWorkflowJobStartingEventArgs
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobStartingEventArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobStartingEventArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Graphics_Printing_Workflow_IPrintWorkflowJobStartingEventArgs[] = L"Windows.Graphics.Printing.Workflow.IPrintWorkflowJobStartingEventArgs";
namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    MIDL_INTERFACE("e3d99ba8-31ad-5e09-b0d7-601b97f161ad")
                    IPrintWorkflowJobStartingEventArgs : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE get_Configuration(
                            ABI::Windows::Graphics::Printing::Workflow::IPrintWorkflowConfiguration** value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_Printer(
                            ABI::Windows::Devices::Printers::IIppPrintDevice** value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE SetSkipSystemRendering(void) = 0;
                        virtual HRESULT STDMETHODCALLTYPE GetDeferral(
                            ABI::Windows::Foundation::IDeferral** result
                            ) = 0;
                    };

                    extern MIDL_CONST_ID IID& IID_IPrintWorkflowJobStartingEventArgs = _uuidof(IPrintWorkflowJobStartingEventArgs);
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobStartingEventArgs;
#endif /* !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobStartingEventArgs_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Interface Windows.Graphics.Printing.Workflow.IPrintWorkflowJobTriggerDetails
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Interface is a part of the implementation of type Windows.Graphics.Printing.Workflow.PrintWorkflowJobTriggerDetails
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobTriggerDetails_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobTriggerDetails_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Graphics_Printing_Workflow_IPrintWorkflowJobTriggerDetails[] = L"Windows.Graphics.Printing.Workflow.IPrintWorkflowJobTriggerDetails";
namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    MIDL_INTERFACE("ff296129-60e2-51db-ba8c-e2ccddb516b9")
                    IPrintWorkflowJobTriggerDetails : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE get_PrintWorkflowJobSession(
                            ABI::Windows::Graphics::Printing::Workflow::IPrintWorkflowJobBackgroundSession** value
                            ) = 0;
                    };

                    extern MIDL_CONST_ID IID& IID_IPrintWorkflowJobTriggerDetails = _uuidof(IPrintWorkflowJobTriggerDetails);
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobTriggerDetails;
#endif /* !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobTriggerDetails_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Interface Windows.Graphics.Printing.Workflow.IPrintWorkflowJobUISession
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Interface is a part of the implementation of type Windows.Graphics.Printing.Workflow.PrintWorkflowJobUISession
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobUISession_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobUISession_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Graphics_Printing_Workflow_IPrintWorkflowJobUISession[] = L"Windows.Graphics.Printing.Workflow.IPrintWorkflowJobUISession";
namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    MIDL_INTERFACE("00c8736b-7637-5687-a302-0f664d2aac65")
                    IPrintWorkflowJobUISession : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE get_Status(
                            ABI::Windows::Graphics::Printing::Workflow::PrintWorkflowSessionStatus* value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE add_PdlDataAvailable(
                            __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobUISession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowPdlDataAvailableEventArgs* handler,
                            EventRegistrationToken* token
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE remove_PdlDataAvailable(
                            EventRegistrationToken token
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE add_JobNotification(
                            __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobUISession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobNotificationEventArgs* handler,
                            EventRegistrationToken* token
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE remove_JobNotification(
                            EventRegistrationToken token
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE Start(void) = 0;
                    };

                    extern MIDL_CONST_ID IID& IID_IPrintWorkflowJobUISession = _uuidof(IPrintWorkflowJobUISession);
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobUISession;
#endif /* !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobUISession_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

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
 * Interface Windows.Graphics.Printing.Workflow.IPrintWorkflowObjectModelSourceFileContentFactory
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Interface is a part of the implementation of type Windows.Graphics.Printing.Workflow.PrintWorkflowObjectModelSourceFileContent
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelSourceFileContentFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelSourceFileContentFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Graphics_Printing_Workflow_IPrintWorkflowObjectModelSourceFileContentFactory[] = L"Windows.Graphics.Printing.Workflow.IPrintWorkflowObjectModelSourceFileContentFactory";
namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    MIDL_INTERFACE("93b1b903-f013-56d6-b708-99ac2ccb12ee")
                    IPrintWorkflowObjectModelSourceFileContentFactory : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE CreateInstance(
                            ABI::Windows::Storage::Streams::IInputStream* xpsStream,
                            ABI::Windows::Graphics::Printing::Workflow::IPrintWorkflowObjectModelSourceFileContent** value
                            ) = 0;
                    };

                    extern MIDL_CONST_ID IID& IID_IPrintWorkflowObjectModelSourceFileContentFactory = _uuidof(IPrintWorkflowObjectModelSourceFileContentFactory);
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelSourceFileContentFactory;
#endif /* !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelSourceFileContentFactory_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

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
 * Interface Windows.Graphics.Printing.Workflow.IPrintWorkflowPdlConverter
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Interface is a part of the implementation of type Windows.Graphics.Printing.Workflow.PrintWorkflowPdlConverter
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlConverter_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlConverter_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Graphics_Printing_Workflow_IPrintWorkflowPdlConverter[] = L"Windows.Graphics.Printing.Workflow.IPrintWorkflowPdlConverter";
namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    MIDL_INTERFACE("40604b62-0ae4-51f1-818f-731dc0b005ab")
                    IPrintWorkflowPdlConverter : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE ConvertPdlAsync(
                            ABI::Windows::Graphics::Printing::PrintTicket::IWorkflowPrintTicket* printTicket,
                            ABI::Windows::Storage::Streams::IInputStream* inputStream,
                            ABI::Windows::Storage::Streams::IOutputStream* outputStream,
                            ABI::Windows::Foundation::IAsyncAction** operation
                            ) = 0;
                    };

                    extern MIDL_CONST_ID IID& IID_IPrintWorkflowPdlConverter = _uuidof(IPrintWorkflowPdlConverter);
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlConverter;
#endif /* !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlConverter_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Interface Windows.Graphics.Printing.Workflow.IPrintWorkflowPdlDataAvailableEventArgs
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Interface is a part of the implementation of type Windows.Graphics.Printing.Workflow.PrintWorkflowPdlDataAvailableEventArgs
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlDataAvailableEventArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlDataAvailableEventArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Graphics_Printing_Workflow_IPrintWorkflowPdlDataAvailableEventArgs[] = L"Windows.Graphics.Printing.Workflow.IPrintWorkflowPdlDataAvailableEventArgs";
namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    MIDL_INTERFACE("d4ad6b50-1547-5991-a0ef-e2ee20211518")
                    IPrintWorkflowPdlDataAvailableEventArgs : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE get_Configuration(
                            ABI::Windows::Graphics::Printing::Workflow::IPrintWorkflowConfiguration** value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_PrinterJob(
                            ABI::Windows::Graphics::Printing::Workflow::IPrintWorkflowPrinterJob** value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_SourceContent(
                            ABI::Windows::Graphics::Printing::Workflow::IPrintWorkflowPdlSourceContent** value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE GetDeferral(
                            ABI::Windows::Foundation::IDeferral** result
                            ) = 0;
                    };

                    extern MIDL_CONST_ID IID& IID_IPrintWorkflowPdlDataAvailableEventArgs = _uuidof(IPrintWorkflowPdlDataAvailableEventArgs);
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlDataAvailableEventArgs;
#endif /* !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlDataAvailableEventArgs_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Interface Windows.Graphics.Printing.Workflow.IPrintWorkflowPdlModificationRequestedEventArgs
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Interface is a part of the implementation of type Windows.Graphics.Printing.Workflow.PrintWorkflowPdlModificationRequestedEventArgs
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlModificationRequestedEventArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlModificationRequestedEventArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Graphics_Printing_Workflow_IPrintWorkflowPdlModificationRequestedEventArgs[] = L"Windows.Graphics.Printing.Workflow.IPrintWorkflowPdlModificationRequestedEventArgs";
namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    MIDL_INTERFACE("1a339a61-2e13-5edd-a707-ceec61d7333b")
                    IPrintWorkflowPdlModificationRequestedEventArgs : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE get_Configuration(
                            ABI::Windows::Graphics::Printing::Workflow::IPrintWorkflowConfiguration** value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_PrinterJob(
                            ABI::Windows::Graphics::Printing::Workflow::IPrintWorkflowPrinterJob** value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_SourceContent(
                            ABI::Windows::Graphics::Printing::Workflow::IPrintWorkflowPdlSourceContent** value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_UILauncher(
                            ABI::Windows::Graphics::Printing::Workflow::IPrintWorkflowUILauncher** value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE CreateJobOnPrinter(
                            HSTRING targetContentType,
                            ABI::Windows::Graphics::Printing::Workflow::IPrintWorkflowPdlTargetStream** result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE CreateJobOnPrinterWithAttributes(
                            __FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* jobAttributes,
                            HSTRING targetContentType,
                            ABI::Windows::Graphics::Printing::Workflow::IPrintWorkflowPdlTargetStream** result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE CreateJobOnPrinterWithAttributesBuffer(
                            ABI::Windows::Storage::Streams::IBuffer* jobAttributesBuffer,
                            HSTRING targetContentType,
                            ABI::Windows::Graphics::Printing::Workflow::IPrintWorkflowPdlTargetStream** result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE GetPdlConverter(
                            ABI::Windows::Graphics::Printing::Workflow::PrintWorkflowPdlConversionType conversionType,
                            ABI::Windows::Graphics::Printing::Workflow::IPrintWorkflowPdlConverter** result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE GetDeferral(
                            ABI::Windows::Foundation::IDeferral** result
                            ) = 0;
                    };

                    extern MIDL_CONST_ID IID& IID_IPrintWorkflowPdlModificationRequestedEventArgs = _uuidof(IPrintWorkflowPdlModificationRequestedEventArgs);
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlModificationRequestedEventArgs;
#endif /* !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlModificationRequestedEventArgs_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Interface Windows.Graphics.Printing.Workflow.IPrintWorkflowPdlSourceContent
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Interface is a part of the implementation of type Windows.Graphics.Printing.Workflow.PrintWorkflowPdlSourceContent
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlSourceContent_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlSourceContent_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Graphics_Printing_Workflow_IPrintWorkflowPdlSourceContent[] = L"Windows.Graphics.Printing.Workflow.IPrintWorkflowPdlSourceContent";
namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    MIDL_INTERFACE("92f7fc41-32b8-56ab-845e-b1e68b3aedd5")
                    IPrintWorkflowPdlSourceContent : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE get_ContentType(
                            HSTRING* value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE GetInputStream(
                            ABI::Windows::Storage::Streams::IInputStream** result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE GetContentFileAsync(
                            __FIAsyncOperation_1_Windows__CStorage__CStorageFile** operation
                            ) = 0;
                    };

                    extern MIDL_CONST_ID IID& IID_IPrintWorkflowPdlSourceContent = _uuidof(IPrintWorkflowPdlSourceContent);
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlSourceContent;
#endif /* !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlSourceContent_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Interface Windows.Graphics.Printing.Workflow.IPrintWorkflowPdlTargetStream
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Interface is a part of the implementation of type Windows.Graphics.Printing.Workflow.PrintWorkflowPdlTargetStream
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlTargetStream_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlTargetStream_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Graphics_Printing_Workflow_IPrintWorkflowPdlTargetStream[] = L"Windows.Graphics.Printing.Workflow.IPrintWorkflowPdlTargetStream";
namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    MIDL_INTERFACE("a742dfe5-1ee3-52a9-9f9f-2e2043180fd1")
                    IPrintWorkflowPdlTargetStream : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE GetOutputStream(
                            ABI::Windows::Storage::Streams::IOutputStream** result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE CompleteStreamSubmission(
                            ABI::Windows::Graphics::Printing::Workflow::PrintWorkflowSubmittedStatus status
                            ) = 0;
                    };

                    extern MIDL_CONST_ID IID& IID_IPrintWorkflowPdlTargetStream = _uuidof(IPrintWorkflowPdlTargetStream);
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlTargetStream;
#endif /* !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlTargetStream_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Interface Windows.Graphics.Printing.Workflow.IPrintWorkflowPrinterJob
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Interface is a part of the implementation of type Windows.Graphics.Printing.Workflow.PrintWorkflowPrinterJob
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPrinterJob_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPrinterJob_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Graphics_Printing_Workflow_IPrintWorkflowPrinterJob[] = L"Windows.Graphics.Printing.Workflow.IPrintWorkflowPrinterJob";
namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    MIDL_INTERFACE("12009f94-0d14-5443-bc09-250311ce570b")
                    IPrintWorkflowPrinterJob : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE get_JobId(
                            INT32* value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_Printer(
                            ABI::Windows::Devices::Printers::IIppPrintDevice** value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE GetJobStatus(
                            ABI::Windows::Graphics::Printing::Workflow::PrintWorkflowPrinterJobStatus* result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE GetJobPrintTicket(
                            ABI::Windows::Graphics::Printing::PrintTicket::IWorkflowPrintTicket** result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE GetJobAttributesAsBuffer(
                            __FIIterable_1_HSTRING* attributeNames,
                            ABI::Windows::Storage::Streams::IBuffer** result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE GetJobAttributes(
                            __FIIterable_1_HSTRING* attributeNames,
                            __FIMap_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue** result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE SetJobAttributesFromBuffer(
                            ABI::Windows::Storage::Streams::IBuffer* jobAttributesBuffer,
                            ABI::Windows::Devices::Printers::IIppSetAttributesResult** result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE SetJobAttributes(
                            __FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* jobAttributes,
                            ABI::Windows::Devices::Printers::IIppSetAttributesResult** result
                            ) = 0;
                    };

                    extern MIDL_CONST_ID IID& IID_IPrintWorkflowPrinterJob = _uuidof(IPrintWorkflowPrinterJob);
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPrinterJob;
#endif /* !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPrinterJob_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

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
 * Interface Windows.Graphics.Printing.Workflow.IPrintWorkflowUILauncher
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Interface is a part of the implementation of type Windows.Graphics.Printing.Workflow.PrintWorkflowUILauncher
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowUILauncher_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowUILauncher_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Graphics_Printing_Workflow_IPrintWorkflowUILauncher[] = L"Windows.Graphics.Printing.Workflow.IPrintWorkflowUILauncher";
namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Printing {
                namespace Workflow {
                    MIDL_INTERFACE("64e9e22f-14cc-5828-96fb-39163fb6c378")
                    IPrintWorkflowUILauncher : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE IsUILaunchEnabled(
                            boolean* result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE LaunchAndCompleteUIAsync(
                            __FIAsyncOperation_1_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowUICompletionStatus** operation
                            ) = 0;
                    };

                    extern MIDL_CONST_ID IID& IID_IPrintWorkflowUILauncher = _uuidof(IPrintWorkflowUILauncher);
                } /* Workflow */
            } /* Printing */
        } /* Graphics */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowUILauncher;
#endif /* !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowUILauncher_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

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
 *    Windows.Graphics.Printing.Workflow.IPrintWorkflowConfiguration2
 *    Windows.Graphics.Printing.Workflow.IPrintWorkflowConfiguration ** Default Interface **
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
 * Class Windows.Graphics.Printing.Workflow.PrintWorkflowJobActivatedEventArgs
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Class implements the following interfaces:
 *    Windows.Graphics.Printing.Workflow.IPrintWorkflowJobActivatedEventArgs ** Default Interface **
 *    Windows.ApplicationModel.Activation.IActivatedEventArgs
 *    Windows.ApplicationModel.Activation.IActivatedEventArgsWithUser
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#ifndef RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowJobActivatedEventArgs_DEFINED
#define RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowJobActivatedEventArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Graphics_Printing_Workflow_PrintWorkflowJobActivatedEventArgs[] = L"Windows.Graphics.Printing.Workflow.PrintWorkflowJobActivatedEventArgs";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Class Windows.Graphics.Printing.Workflow.PrintWorkflowJobBackgroundSession
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Class implements the following interfaces:
 *    Windows.Graphics.Printing.Workflow.IPrintWorkflowJobBackgroundSession ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#ifndef RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowJobBackgroundSession_DEFINED
#define RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowJobBackgroundSession_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Graphics_Printing_Workflow_PrintWorkflowJobBackgroundSession[] = L"Windows.Graphics.Printing.Workflow.PrintWorkflowJobBackgroundSession";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Class Windows.Graphics.Printing.Workflow.PrintWorkflowJobNotificationEventArgs
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Class implements the following interfaces:
 *    Windows.Graphics.Printing.Workflow.IPrintWorkflowJobNotificationEventArgs ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#ifndef RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowJobNotificationEventArgs_DEFINED
#define RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowJobNotificationEventArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Graphics_Printing_Workflow_PrintWorkflowJobNotificationEventArgs[] = L"Windows.Graphics.Printing.Workflow.PrintWorkflowJobNotificationEventArgs";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Class Windows.Graphics.Printing.Workflow.PrintWorkflowJobStartingEventArgs
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Class implements the following interfaces:
 *    Windows.Graphics.Printing.Workflow.IPrintWorkflowJobStartingEventArgs ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#ifndef RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowJobStartingEventArgs_DEFINED
#define RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowJobStartingEventArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Graphics_Printing_Workflow_PrintWorkflowJobStartingEventArgs[] = L"Windows.Graphics.Printing.Workflow.PrintWorkflowJobStartingEventArgs";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Class Windows.Graphics.Printing.Workflow.PrintWorkflowJobTriggerDetails
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Class implements the following interfaces:
 *    Windows.Graphics.Printing.Workflow.IPrintWorkflowJobTriggerDetails ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#ifndef RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowJobTriggerDetails_DEFINED
#define RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowJobTriggerDetails_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Graphics_Printing_Workflow_PrintWorkflowJobTriggerDetails[] = L"Windows.Graphics.Printing.Workflow.PrintWorkflowJobTriggerDetails";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Class Windows.Graphics.Printing.Workflow.PrintWorkflowJobUISession
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Class implements the following interfaces:
 *    Windows.Graphics.Printing.Workflow.IPrintWorkflowJobUISession ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#ifndef RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowJobUISession_DEFINED
#define RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowJobUISession_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Graphics_Printing_Workflow_PrintWorkflowJobUISession[] = L"Windows.Graphics.Printing.Workflow.PrintWorkflowJobUISession";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Class Windows.Graphics.Printing.Workflow.PrintWorkflowObjectModelSourceFileContent
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via the Windows.Graphics.Printing.Workflow.IPrintWorkflowObjectModelSourceFileContentFactory interface starting with version 13.0 of the Windows.Foundation.UniversalApiContract API contract
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
 * Class Windows.Graphics.Printing.Workflow.PrintWorkflowPdlConverter
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Class implements the following interfaces:
 *    Windows.Graphics.Printing.Workflow.IPrintWorkflowPdlConverter ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#ifndef RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowPdlConverter_DEFINED
#define RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowPdlConverter_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Graphics_Printing_Workflow_PrintWorkflowPdlConverter[] = L"Windows.Graphics.Printing.Workflow.PrintWorkflowPdlConverter";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Class Windows.Graphics.Printing.Workflow.PrintWorkflowPdlDataAvailableEventArgs
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Class implements the following interfaces:
 *    Windows.Graphics.Printing.Workflow.IPrintWorkflowPdlDataAvailableEventArgs ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#ifndef RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowPdlDataAvailableEventArgs_DEFINED
#define RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowPdlDataAvailableEventArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Graphics_Printing_Workflow_PrintWorkflowPdlDataAvailableEventArgs[] = L"Windows.Graphics.Printing.Workflow.PrintWorkflowPdlDataAvailableEventArgs";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Class Windows.Graphics.Printing.Workflow.PrintWorkflowPdlModificationRequestedEventArgs
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Class implements the following interfaces:
 *    Windows.Graphics.Printing.Workflow.IPrintWorkflowPdlModificationRequestedEventArgs ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#ifndef RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowPdlModificationRequestedEventArgs_DEFINED
#define RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowPdlModificationRequestedEventArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Graphics_Printing_Workflow_PrintWorkflowPdlModificationRequestedEventArgs[] = L"Windows.Graphics.Printing.Workflow.PrintWorkflowPdlModificationRequestedEventArgs";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Class Windows.Graphics.Printing.Workflow.PrintWorkflowPdlSourceContent
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Class implements the following interfaces:
 *    Windows.Graphics.Printing.Workflow.IPrintWorkflowPdlSourceContent ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#ifndef RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowPdlSourceContent_DEFINED
#define RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowPdlSourceContent_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Graphics_Printing_Workflow_PrintWorkflowPdlSourceContent[] = L"Windows.Graphics.Printing.Workflow.PrintWorkflowPdlSourceContent";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Class Windows.Graphics.Printing.Workflow.PrintWorkflowPdlTargetStream
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Class implements the following interfaces:
 *    Windows.Graphics.Printing.Workflow.IPrintWorkflowPdlTargetStream ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#ifndef RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowPdlTargetStream_DEFINED
#define RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowPdlTargetStream_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Graphics_Printing_Workflow_PrintWorkflowPdlTargetStream[] = L"Windows.Graphics.Printing.Workflow.PrintWorkflowPdlTargetStream";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Class Windows.Graphics.Printing.Workflow.PrintWorkflowPrinterJob
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Class implements the following interfaces:
 *    Windows.Graphics.Printing.Workflow.IPrintWorkflowPrinterJob ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#ifndef RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowPrinterJob_DEFINED
#define RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowPrinterJob_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Graphics_Printing_Workflow_PrintWorkflowPrinterJob[] = L"Windows.Graphics.Printing.Workflow.PrintWorkflowPrinterJob";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

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
 * Class Windows.Graphics.Printing.Workflow.PrintWorkflowUILauncher
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Class implements the following interfaces:
 *    Windows.Graphics.Printing.Workflow.IPrintWorkflowUILauncher ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#ifndef RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowUILauncher_DEFINED
#define RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowUILauncher_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Graphics_Printing_Workflow_PrintWorkflowUILauncher[] = L"Windows.Graphics.Printing.Workflow.PrintWorkflowUILauncher";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

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

#ifndef ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration2_FWD_DEFINED__
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration2_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration2 __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration2;

#endif // ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration2_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSession_FWD_DEFINED__
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSession_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSession __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSession;

#endif // ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSession_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSetupRequestedEventArgs_FWD_DEFINED__
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSetupRequestedEventArgs_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSetupRequestedEventArgs __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSetupRequestedEventArgs;

#endif // ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowForegroundSetupRequestedEventArgs_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobActivatedEventArgs_FWD_DEFINED__
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobActivatedEventArgs_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobActivatedEventArgs __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobActivatedEventArgs;

#endif // ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobActivatedEventArgs_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobBackgroundSession_FWD_DEFINED__
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobBackgroundSession_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobBackgroundSession __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobBackgroundSession;

#endif // ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobBackgroundSession_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobNotificationEventArgs_FWD_DEFINED__
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobNotificationEventArgs_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobNotificationEventArgs __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobNotificationEventArgs;

#endif // ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobNotificationEventArgs_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobStartingEventArgs_FWD_DEFINED__
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobStartingEventArgs_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobStartingEventArgs __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobStartingEventArgs;

#endif // ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobStartingEventArgs_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobTriggerDetails_FWD_DEFINED__
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobTriggerDetails_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobTriggerDetails __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobTriggerDetails;

#endif // ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobTriggerDetails_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobUISession_FWD_DEFINED__
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobUISession_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobUISession __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobUISession;

#endif // ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobUISession_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelSourceFileContent_FWD_DEFINED__
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelSourceFileContent_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelSourceFileContent __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelSourceFileContent;

#endif // ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelSourceFileContent_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelSourceFileContentFactory_FWD_DEFINED__
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelSourceFileContentFactory_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelSourceFileContentFactory __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelSourceFileContentFactory;

#endif // ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelSourceFileContentFactory_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelTargetPackage_FWD_DEFINED__
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelTargetPackage_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelTargetPackage __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelTargetPackage;

#endif // ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelTargetPackage_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlConverter_FWD_DEFINED__
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlConverter_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlConverter __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlConverter;

#endif // ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlConverter_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlDataAvailableEventArgs_FWD_DEFINED__
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlDataAvailableEventArgs_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlDataAvailableEventArgs __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlDataAvailableEventArgs;

#endif // ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlDataAvailableEventArgs_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlModificationRequestedEventArgs_FWD_DEFINED__
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlModificationRequestedEventArgs_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlModificationRequestedEventArgs __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlModificationRequestedEventArgs;

#endif // ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlModificationRequestedEventArgs_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlSourceContent_FWD_DEFINED__
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlSourceContent_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlSourceContent __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlSourceContent;

#endif // ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlSourceContent_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlTargetStream_FWD_DEFINED__
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlTargetStream_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlTargetStream __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlTargetStream;

#endif // ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlTargetStream_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPrinterJob_FWD_DEFINED__
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPrinterJob_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPrinterJob __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPrinterJob;

#endif // ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPrinterJob_FWD_DEFINED__

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

#ifndef ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowUILauncher_FWD_DEFINED__
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowUILauncher_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowUILauncher __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowUILauncher;

#endif // ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowUILauncher_FWD_DEFINED__

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

typedef enum __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CPrintWorkflowUICompletionStatus __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CPrintWorkflowUICompletionStatus;

typedef interface __FIAsyncOperationCompletedHandler_1_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowUICompletionStatus __FIAsyncOperationCompletedHandler_1_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowUICompletionStatus;

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____FIAsyncOperation_1_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowUICompletionStatus_INTERFACE_DEFINED__)
#define ____FIAsyncOperation_1_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowUICompletionStatus_INTERFACE_DEFINED__

typedef interface __FIAsyncOperation_1_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowUICompletionStatus __FIAsyncOperation_1_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowUICompletionStatus;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIAsyncOperation_1_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowUICompletionStatus;

typedef struct __FIAsyncOperation_1_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowUICompletionStatusVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIAsyncOperation_1_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowUICompletionStatus* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIAsyncOperation_1_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowUICompletionStatus* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIAsyncOperation_1_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowUICompletionStatus* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIAsyncOperation_1_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowUICompletionStatus* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIAsyncOperation_1_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowUICompletionStatus* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIAsyncOperation_1_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowUICompletionStatus* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* put_Completed)(__FIAsyncOperation_1_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowUICompletionStatus* This,
        __FIAsyncOperationCompletedHandler_1_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowUICompletionStatus* handler);
    HRESULT (STDMETHODCALLTYPE* get_Completed)(__FIAsyncOperation_1_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowUICompletionStatus* This,
        __FIAsyncOperationCompletedHandler_1_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowUICompletionStatus** result);
    HRESULT (STDMETHODCALLTYPE* GetResults)(__FIAsyncOperation_1_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowUICompletionStatus* This,
        enum __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CPrintWorkflowUICompletionStatus* result);

    END_INTERFACE
} __FIAsyncOperation_1_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowUICompletionStatusVtbl;

interface __FIAsyncOperation_1_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowUICompletionStatus
{
    CONST_VTBL struct __FIAsyncOperation_1_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowUICompletionStatusVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIAsyncOperation_1_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowUICompletionStatus_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIAsyncOperation_1_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowUICompletionStatus_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIAsyncOperation_1_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowUICompletionStatus_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIAsyncOperation_1_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowUICompletionStatus_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIAsyncOperation_1_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowUICompletionStatus_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIAsyncOperation_1_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowUICompletionStatus_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIAsyncOperation_1_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowUICompletionStatus_put_Completed(This, handler) \
    ((This)->lpVtbl->put_Completed(This, handler))

#define __FIAsyncOperation_1_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowUICompletionStatus_get_Completed(This, result) \
    ((This)->lpVtbl->get_Completed(This, result))

#define __FIAsyncOperation_1_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowUICompletionStatus_GetResults(This, result) \
    ((This)->lpVtbl->GetResults(This, result))

#endif /* COBJMACROS */

#endif // ____FIAsyncOperation_1_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowUICompletionStatus_INTERFACE_DEFINED__
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____FIAsyncOperationCompletedHandler_1_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowUICompletionStatus_INTERFACE_DEFINED__)
#define ____FIAsyncOperationCompletedHandler_1_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowUICompletionStatus_INTERFACE_DEFINED__

typedef interface __FIAsyncOperationCompletedHandler_1_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowUICompletionStatus __FIAsyncOperationCompletedHandler_1_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowUICompletionStatus;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIAsyncOperationCompletedHandler_1_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowUICompletionStatus;

typedef struct __FIAsyncOperationCompletedHandler_1_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowUICompletionStatusVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIAsyncOperationCompletedHandler_1_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowUICompletionStatus* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIAsyncOperationCompletedHandler_1_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowUICompletionStatus* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIAsyncOperationCompletedHandler_1_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowUICompletionStatus* This);
    HRESULT (STDMETHODCALLTYPE* Invoke)(__FIAsyncOperationCompletedHandler_1_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowUICompletionStatus* This,
        __FIAsyncOperation_1_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowUICompletionStatus* asyncInfo,
        AsyncStatus asyncStatus);

    END_INTERFACE
} __FIAsyncOperationCompletedHandler_1_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowUICompletionStatusVtbl;

interface __FIAsyncOperationCompletedHandler_1_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowUICompletionStatus
{
    CONST_VTBL struct __FIAsyncOperationCompletedHandler_1_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowUICompletionStatusVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIAsyncOperationCompletedHandler_1_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowUICompletionStatus_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIAsyncOperationCompletedHandler_1_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowUICompletionStatus_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIAsyncOperationCompletedHandler_1_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowUICompletionStatus_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIAsyncOperationCompletedHandler_1_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowUICompletionStatus_Invoke(This, asyncInfo, asyncStatus) \
    ((This)->lpVtbl->Invoke(This, asyncInfo, asyncStatus))

#endif /* COBJMACROS */

#endif // ____FIAsyncOperationCompletedHandler_1_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowUICompletionStatus_INTERFACE_DEFINED__
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#ifndef ____x_ABI_CWindows_CStorage_CIStorageFile_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CIStorageFile_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CStorage_CIStorageFile __x_ABI_CWindows_CStorage_CIStorageFile;

#endif // ____x_ABI_CWindows_CStorage_CIStorageFile_FWD_DEFINED__

typedef interface __FIAsyncOperationCompletedHandler_1_Windows__CStorage__CStorageFile __FIAsyncOperationCompletedHandler_1_Windows__CStorage__CStorageFile;

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if !defined(____FIAsyncOperation_1_Windows__CStorage__CStorageFile_INTERFACE_DEFINED__)
#define ____FIAsyncOperation_1_Windows__CStorage__CStorageFile_INTERFACE_DEFINED__

typedef interface __FIAsyncOperation_1_Windows__CStorage__CStorageFile __FIAsyncOperation_1_Windows__CStorage__CStorageFile;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIAsyncOperation_1_Windows__CStorage__CStorageFile;

typedef struct __FIAsyncOperation_1_Windows__CStorage__CStorageFileVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIAsyncOperation_1_Windows__CStorage__CStorageFile* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIAsyncOperation_1_Windows__CStorage__CStorageFile* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIAsyncOperation_1_Windows__CStorage__CStorageFile* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIAsyncOperation_1_Windows__CStorage__CStorageFile* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIAsyncOperation_1_Windows__CStorage__CStorageFile* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIAsyncOperation_1_Windows__CStorage__CStorageFile* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* put_Completed)(__FIAsyncOperation_1_Windows__CStorage__CStorageFile* This,
        __FIAsyncOperationCompletedHandler_1_Windows__CStorage__CStorageFile* handler);
    HRESULT (STDMETHODCALLTYPE* get_Completed)(__FIAsyncOperation_1_Windows__CStorage__CStorageFile* This,
        __FIAsyncOperationCompletedHandler_1_Windows__CStorage__CStorageFile** result);
    HRESULT (STDMETHODCALLTYPE* GetResults)(__FIAsyncOperation_1_Windows__CStorage__CStorageFile* This,
        __x_ABI_CWindows_CStorage_CIStorageFile** result);

    END_INTERFACE
} __FIAsyncOperation_1_Windows__CStorage__CStorageFileVtbl;

interface __FIAsyncOperation_1_Windows__CStorage__CStorageFile
{
    CONST_VTBL struct __FIAsyncOperation_1_Windows__CStorage__CStorageFileVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIAsyncOperation_1_Windows__CStorage__CStorageFile_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIAsyncOperation_1_Windows__CStorage__CStorageFile_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIAsyncOperation_1_Windows__CStorage__CStorageFile_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIAsyncOperation_1_Windows__CStorage__CStorageFile_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIAsyncOperation_1_Windows__CStorage__CStorageFile_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIAsyncOperation_1_Windows__CStorage__CStorageFile_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIAsyncOperation_1_Windows__CStorage__CStorageFile_put_Completed(This, handler) \
    ((This)->lpVtbl->put_Completed(This, handler))

#define __FIAsyncOperation_1_Windows__CStorage__CStorageFile_get_Completed(This, result) \
    ((This)->lpVtbl->get_Completed(This, result))

#define __FIAsyncOperation_1_Windows__CStorage__CStorageFile_GetResults(This, result) \
    ((This)->lpVtbl->GetResults(This, result))

#endif /* COBJMACROS */

#endif // ____FIAsyncOperation_1_Windows__CStorage__CStorageFile_INTERFACE_DEFINED__
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if !defined(____FIAsyncOperationCompletedHandler_1_Windows__CStorage__CStorageFile_INTERFACE_DEFINED__)
#define ____FIAsyncOperationCompletedHandler_1_Windows__CStorage__CStorageFile_INTERFACE_DEFINED__

typedef interface __FIAsyncOperationCompletedHandler_1_Windows__CStorage__CStorageFile __FIAsyncOperationCompletedHandler_1_Windows__CStorage__CStorageFile;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIAsyncOperationCompletedHandler_1_Windows__CStorage__CStorageFile;

typedef struct __FIAsyncOperationCompletedHandler_1_Windows__CStorage__CStorageFileVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIAsyncOperationCompletedHandler_1_Windows__CStorage__CStorageFile* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIAsyncOperationCompletedHandler_1_Windows__CStorage__CStorageFile* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIAsyncOperationCompletedHandler_1_Windows__CStorage__CStorageFile* This);
    HRESULT (STDMETHODCALLTYPE* Invoke)(__FIAsyncOperationCompletedHandler_1_Windows__CStorage__CStorageFile* This,
        __FIAsyncOperation_1_Windows__CStorage__CStorageFile* asyncInfo,
        AsyncStatus asyncStatus);

    END_INTERFACE
} __FIAsyncOperationCompletedHandler_1_Windows__CStorage__CStorageFileVtbl;

interface __FIAsyncOperationCompletedHandler_1_Windows__CStorage__CStorageFile
{
    CONST_VTBL struct __FIAsyncOperationCompletedHandler_1_Windows__CStorage__CStorageFileVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIAsyncOperationCompletedHandler_1_Windows__CStorage__CStorageFile_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIAsyncOperationCompletedHandler_1_Windows__CStorage__CStorageFile_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIAsyncOperationCompletedHandler_1_Windows__CStorage__CStorageFile_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIAsyncOperationCompletedHandler_1_Windows__CStorage__CStorageFile_Invoke(This, asyncInfo, asyncStatus) \
    ((This)->lpVtbl->Invoke(This, asyncInfo, asyncStatus))

#endif /* COBJMACROS */

#endif // ____FIAsyncOperationCompletedHandler_1_Windows__CStorage__CStorageFile_INTERFACE_DEFINED__
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

#ifndef ____x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue_FWD_DEFINED__
#define ____x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue __x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue;

#endif // ____x_ABI_CWindows_CDevices_CPrinters_CIIppAttributeValue_FWD_DEFINED__

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

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobStartingEventArgs_INTERFACE_DEFINED__)
#define ____FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobStartingEventArgs_INTERFACE_DEFINED__

typedef interface __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobStartingEventArgs __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobStartingEventArgs;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobStartingEventArgs;

typedef struct __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobStartingEventArgsVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobStartingEventArgs* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobStartingEventArgs* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobStartingEventArgs* This);
    HRESULT (STDMETHODCALLTYPE* Invoke)(__FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobStartingEventArgs* This,
        __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobBackgroundSession* sender,
        __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobStartingEventArgs* args);

    END_INTERFACE
} __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobStartingEventArgsVtbl;

interface __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobStartingEventArgs
{
    CONST_VTBL struct __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobStartingEventArgsVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobStartingEventArgs_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobStartingEventArgs_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobStartingEventArgs_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobStartingEventArgs_Invoke(This, sender, args) \
    ((This)->lpVtbl->Invoke(This, sender, args))

#endif /* COBJMACROS */

#endif // ____FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobStartingEventArgs_INTERFACE_DEFINED__
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowPdlModificationRequestedEventArgs_INTERFACE_DEFINED__)
#define ____FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowPdlModificationRequestedEventArgs_INTERFACE_DEFINED__

typedef interface __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowPdlModificationRequestedEventArgs __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowPdlModificationRequestedEventArgs;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowPdlModificationRequestedEventArgs;

typedef struct __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowPdlModificationRequestedEventArgsVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowPdlModificationRequestedEventArgs* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowPdlModificationRequestedEventArgs* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowPdlModificationRequestedEventArgs* This);
    HRESULT (STDMETHODCALLTYPE* Invoke)(__FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowPdlModificationRequestedEventArgs* This,
        __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobBackgroundSession* sender,
        __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlModificationRequestedEventArgs* args);

    END_INTERFACE
} __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowPdlModificationRequestedEventArgsVtbl;

interface __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowPdlModificationRequestedEventArgs
{
    CONST_VTBL struct __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowPdlModificationRequestedEventArgsVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowPdlModificationRequestedEventArgs_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowPdlModificationRequestedEventArgs_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowPdlModificationRequestedEventArgs_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowPdlModificationRequestedEventArgs_Invoke(This, sender, args) \
    ((This)->lpVtbl->Invoke(This, sender, args))

#endif /* COBJMACROS */

#endif // ____FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowPdlModificationRequestedEventArgs_INTERFACE_DEFINED__
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobUISession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobNotificationEventArgs_INTERFACE_DEFINED__)
#define ____FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobUISession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobNotificationEventArgs_INTERFACE_DEFINED__

typedef interface __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobUISession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobNotificationEventArgs __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobUISession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobNotificationEventArgs;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobUISession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobNotificationEventArgs;

typedef struct __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobUISession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobNotificationEventArgsVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobUISession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobNotificationEventArgs* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobUISession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobNotificationEventArgs* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobUISession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobNotificationEventArgs* This);
    HRESULT (STDMETHODCALLTYPE* Invoke)(__FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobUISession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobNotificationEventArgs* This,
        __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobUISession* sender,
        __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobNotificationEventArgs* args);

    END_INTERFACE
} __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobUISession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobNotificationEventArgsVtbl;

interface __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobUISession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobNotificationEventArgs
{
    CONST_VTBL struct __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobUISession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobNotificationEventArgsVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobUISession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobNotificationEventArgs_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobUISession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobNotificationEventArgs_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobUISession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobNotificationEventArgs_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobUISession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobNotificationEventArgs_Invoke(This, sender, args) \
    ((This)->lpVtbl->Invoke(This, sender, args))

#endif /* COBJMACROS */

#endif // ____FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobUISession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobNotificationEventArgs_INTERFACE_DEFINED__
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobUISession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowPdlDataAvailableEventArgs_INTERFACE_DEFINED__)
#define ____FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobUISession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowPdlDataAvailableEventArgs_INTERFACE_DEFINED__

typedef interface __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobUISession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowPdlDataAvailableEventArgs __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobUISession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowPdlDataAvailableEventArgs;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobUISession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowPdlDataAvailableEventArgs;

typedef struct __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobUISession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowPdlDataAvailableEventArgsVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobUISession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowPdlDataAvailableEventArgs* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobUISession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowPdlDataAvailableEventArgs* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobUISession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowPdlDataAvailableEventArgs* This);
    HRESULT (STDMETHODCALLTYPE* Invoke)(__FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobUISession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowPdlDataAvailableEventArgs* This,
        __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobUISession* sender,
        __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlDataAvailableEventArgs* args);

    END_INTERFACE
} __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobUISession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowPdlDataAvailableEventArgsVtbl;

interface __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobUISession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowPdlDataAvailableEventArgs
{
    CONST_VTBL struct __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobUISession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowPdlDataAvailableEventArgsVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobUISession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowPdlDataAvailableEventArgs_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobUISession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowPdlDataAvailableEventArgs_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobUISession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowPdlDataAvailableEventArgs_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobUISession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowPdlDataAvailableEventArgs_Invoke(This, sender, args) \
    ((This)->lpVtbl->Invoke(This, sender, args))

#endif /* COBJMACROS */

#endif // ____FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobUISession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowPdlDataAvailableEventArgs_INTERFACE_DEFINED__
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#ifndef ____x_ABI_CWindows_CApplicationModel_CActivation_CIActivatedEventArgs_FWD_DEFINED__
#define ____x_ABI_CWindows_CApplicationModel_CActivation_CIActivatedEventArgs_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CApplicationModel_CActivation_CIActivatedEventArgs __x_ABI_CWindows_CApplicationModel_CActivation_CIActivatedEventArgs;

#endif // ____x_ABI_CWindows_CApplicationModel_CActivation_CIActivatedEventArgs_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CApplicationModel_CActivation_CIActivatedEventArgsWithUser_FWD_DEFINED__
#define ____x_ABI_CWindows_CApplicationModel_CActivation_CIActivatedEventArgsWithUser_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CApplicationModel_CActivation_CIActivatedEventArgsWithUser __x_ABI_CWindows_CApplicationModel_CActivation_CIActivatedEventArgsWithUser;

#endif // ____x_ABI_CWindows_CApplicationModel_CActivation_CIActivatedEventArgsWithUser_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CDevices_CPrinters_CIIppPrintDevice_FWD_DEFINED__
#define ____x_ABI_CWindows_CDevices_CPrinters_CIIppPrintDevice_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CDevices_CPrinters_CIIppPrintDevice __x_ABI_CWindows_CDevices_CPrinters_CIIppPrintDevice;

#endif // ____x_ABI_CWindows_CDevices_CPrinters_CIIppPrintDevice_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CDevices_CPrinters_CIIppSetAttributesResult_FWD_DEFINED__
#define ____x_ABI_CWindows_CDevices_CPrinters_CIIppSetAttributesResult_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CDevices_CPrinters_CIIppSetAttributesResult __x_ABI_CWindows_CDevices_CPrinters_CIIppSetAttributesResult;

#endif // ____x_ABI_CWindows_CDevices_CPrinters_CIIppSetAttributesResult_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CFoundation_CIDeferral_FWD_DEFINED__
#define ____x_ABI_CWindows_CFoundation_CIDeferral_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CFoundation_CIDeferral __x_ABI_CWindows_CFoundation_CIDeferral;

#endif // ____x_ABI_CWindows_CFoundation_CIDeferral_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CFoundation_CIAsyncAction_FWD_DEFINED__
#define ____x_ABI_CWindows_CFoundation_CIAsyncAction_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CFoundation_CIAsyncAction __x_ABI_CWindows_CFoundation_CIAsyncAction;

#endif // ____x_ABI_CWindows_CFoundation_CIAsyncAction_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CStorage_CStreams_CIBuffer_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CStreams_CIBuffer_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CStorage_CStreams_CIBuffer __x_ABI_CWindows_CStorage_CStreams_CIBuffer;

#endif // ____x_ABI_CWindows_CStorage_CStreams_CIBuffer_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CStorage_CStreams_CIInputStream_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CStreams_CIInputStream_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CStorage_CStreams_CIInputStream __x_ABI_CWindows_CStorage_CStreams_CIInputStream;

#endif // ____x_ABI_CWindows_CStorage_CStreams_CIInputStream_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CStorage_CStreams_CIOutputStream_FWD_DEFINED__
#define ____x_ABI_CWindows_CStorage_CStreams_CIOutputStream_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CStorage_CStreams_CIOutputStream __x_ABI_CWindows_CStorage_CStreams_CIOutputStream;

#endif // ____x_ABI_CWindows_CStorage_CStreams_CIOutputStream_FWD_DEFINED__

typedef enum __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CPrintWorkflowJobAbortReason __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CPrintWorkflowJobAbortReason;

typedef enum __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CPrintWorkflowPdlConversionType __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CPrintWorkflowPdlConversionType;

typedef enum __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CPrintWorkflowPrinterJobStatus __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CPrintWorkflowPrinterJobStatus;

typedef enum __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CPrintWorkflowSessionStatus __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CPrintWorkflowSessionStatus;

typedef enum __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CPrintWorkflowSubmittedStatus __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CPrintWorkflowSubmittedStatus;

/*
 *
 * Struct Windows.Graphics.Printing.Workflow.PrintWorkflowJobAbortReason
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
enum __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CPrintWorkflowJobAbortReason
{
    PrintWorkflowJobAbortReason_JobFailed = 0,
    PrintWorkflowJobAbortReason_UserCanceled = 1,
};
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Struct Windows.Graphics.Printing.Workflow.PrintWorkflowPdlConversionType
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
enum __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CPrintWorkflowPdlConversionType
{
    PrintWorkflowPdlConversionType_XpsToPdf = 0,
    PrintWorkflowPdlConversionType_XpsToPwgr = 1,
    PrintWorkflowPdlConversionType_XpsToPclm = 2,
};
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Struct Windows.Graphics.Printing.Workflow.PrintWorkflowPrinterJobStatus
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
enum __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CPrintWorkflowPrinterJobStatus
{
    PrintWorkflowPrinterJobStatus_Error = 0,
    PrintWorkflowPrinterJobStatus_Aborted = 1,
    PrintWorkflowPrinterJobStatus_InProgress = 2,
    PrintWorkflowPrinterJobStatus_Completed = 3,
};
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

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
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
    PrintWorkflowSessionStatus_PdlDataAvailableForModification = 4,
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
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
 * Struct Windows.Graphics.Printing.Workflow.PrintWorkflowUICompletionStatus
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
enum __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CPrintWorkflowUICompletionStatus
{
    PrintWorkflowUICompletionStatus_Completed = 0,
    PrintWorkflowUICompletionStatus_LaunchFailed = 1,
    PrintWorkflowUICompletionStatus_JobFailed = 2,
    PrintWorkflowUICompletionStatus_UserCanceled = 3,
};
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

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
 * Interface Windows.Graphics.Printing.Workflow.IPrintWorkflowConfiguration2
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Interface is a part of the implementation of type Windows.Graphics.Printing.Workflow.PrintWorkflowConfiguration
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration2_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration2_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Graphics_Printing_Workflow_IPrintWorkflowConfiguration2[] = L"Windows.Graphics.Printing.Workflow.IPrintWorkflowConfiguration2";
typedef struct __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration2Vtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration2* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration2* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration2* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration2* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration2* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration2* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* AbortPrintFlow)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration2* This,
        enum __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CPrintWorkflowJobAbortReason reason);

    END_INTERFACE
} __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration2Vtbl;

interface __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration2
{
    CONST_VTBL struct __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration2Vtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration2_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration2_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration2_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration2_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration2_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration2_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration2_AbortPrintFlow(This, reason) \
    ((This)->lpVtbl->AbortPrintFlow(This, reason))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration2;
#endif /* !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration2_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

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
 * Interface Windows.Graphics.Printing.Workflow.IPrintWorkflowJobActivatedEventArgs
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Interface is a part of the implementation of type Windows.Graphics.Printing.Workflow.PrintWorkflowJobActivatedEventArgs
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobActivatedEventArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobActivatedEventArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Graphics_Printing_Workflow_IPrintWorkflowJobActivatedEventArgs[] = L"Windows.Graphics.Printing.Workflow.IPrintWorkflowJobActivatedEventArgs";
typedef struct __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobActivatedEventArgsVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobActivatedEventArgs* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobActivatedEventArgs* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobActivatedEventArgs* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobActivatedEventArgs* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobActivatedEventArgs* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobActivatedEventArgs* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Session)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobActivatedEventArgs* This,
        __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobUISession** value);

    END_INTERFACE
} __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobActivatedEventArgsVtbl;

interface __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobActivatedEventArgs
{
    CONST_VTBL struct __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobActivatedEventArgsVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobActivatedEventArgs_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobActivatedEventArgs_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobActivatedEventArgs_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobActivatedEventArgs_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobActivatedEventArgs_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobActivatedEventArgs_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobActivatedEventArgs_get_Session(This, value) \
    ((This)->lpVtbl->get_Session(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobActivatedEventArgs;
#endif /* !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobActivatedEventArgs_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Interface Windows.Graphics.Printing.Workflow.IPrintWorkflowJobBackgroundSession
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Interface is a part of the implementation of type Windows.Graphics.Printing.Workflow.PrintWorkflowJobBackgroundSession
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobBackgroundSession_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobBackgroundSession_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Graphics_Printing_Workflow_IPrintWorkflowJobBackgroundSession[] = L"Windows.Graphics.Printing.Workflow.IPrintWorkflowJobBackgroundSession";
typedef struct __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobBackgroundSessionVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobBackgroundSession* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobBackgroundSession* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobBackgroundSession* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobBackgroundSession* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobBackgroundSession* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobBackgroundSession* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Status)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobBackgroundSession* This,
        enum __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CPrintWorkflowSessionStatus* value);
    HRESULT (STDMETHODCALLTYPE* add_JobStarting)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobBackgroundSession* This,
        __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobStartingEventArgs* handler,
        EventRegistrationToken* token);
    HRESULT (STDMETHODCALLTYPE* remove_JobStarting)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobBackgroundSession* This,
        EventRegistrationToken token);
    HRESULT (STDMETHODCALLTYPE* add_PdlModificationRequested)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobBackgroundSession* This,
        __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobBackgroundSession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowPdlModificationRequestedEventArgs* handler,
        EventRegistrationToken* token);
    HRESULT (STDMETHODCALLTYPE* remove_PdlModificationRequested)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobBackgroundSession* This,
        EventRegistrationToken token);
    HRESULT (STDMETHODCALLTYPE* Start)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobBackgroundSession* This);

    END_INTERFACE
} __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobBackgroundSessionVtbl;

interface __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobBackgroundSession
{
    CONST_VTBL struct __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobBackgroundSessionVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobBackgroundSession_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobBackgroundSession_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobBackgroundSession_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobBackgroundSession_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobBackgroundSession_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobBackgroundSession_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobBackgroundSession_get_Status(This, value) \
    ((This)->lpVtbl->get_Status(This, value))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobBackgroundSession_add_JobStarting(This, handler, token) \
    ((This)->lpVtbl->add_JobStarting(This, handler, token))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobBackgroundSession_remove_JobStarting(This, token) \
    ((This)->lpVtbl->remove_JobStarting(This, token))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobBackgroundSession_add_PdlModificationRequested(This, handler, token) \
    ((This)->lpVtbl->add_PdlModificationRequested(This, handler, token))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobBackgroundSession_remove_PdlModificationRequested(This, token) \
    ((This)->lpVtbl->remove_PdlModificationRequested(This, token))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobBackgroundSession_Start(This) \
    ((This)->lpVtbl->Start(This))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobBackgroundSession;
#endif /* !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobBackgroundSession_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Interface Windows.Graphics.Printing.Workflow.IPrintWorkflowJobNotificationEventArgs
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Interface is a part of the implementation of type Windows.Graphics.Printing.Workflow.PrintWorkflowJobNotificationEventArgs
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobNotificationEventArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobNotificationEventArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Graphics_Printing_Workflow_IPrintWorkflowJobNotificationEventArgs[] = L"Windows.Graphics.Printing.Workflow.IPrintWorkflowJobNotificationEventArgs";
typedef struct __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobNotificationEventArgsVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobNotificationEventArgs* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobNotificationEventArgs* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobNotificationEventArgs* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobNotificationEventArgs* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobNotificationEventArgs* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobNotificationEventArgs* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Configuration)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobNotificationEventArgs* This,
        __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration** value);
    HRESULT (STDMETHODCALLTYPE* get_PrinterJob)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobNotificationEventArgs* This,
        __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPrinterJob** value);
    HRESULT (STDMETHODCALLTYPE* GetDeferral)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobNotificationEventArgs* This,
        __x_ABI_CWindows_CFoundation_CIDeferral** result);

    END_INTERFACE
} __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobNotificationEventArgsVtbl;

interface __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobNotificationEventArgs
{
    CONST_VTBL struct __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobNotificationEventArgsVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobNotificationEventArgs_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobNotificationEventArgs_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobNotificationEventArgs_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobNotificationEventArgs_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobNotificationEventArgs_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobNotificationEventArgs_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobNotificationEventArgs_get_Configuration(This, value) \
    ((This)->lpVtbl->get_Configuration(This, value))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobNotificationEventArgs_get_PrinterJob(This, value) \
    ((This)->lpVtbl->get_PrinterJob(This, value))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobNotificationEventArgs_GetDeferral(This, result) \
    ((This)->lpVtbl->GetDeferral(This, result))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobNotificationEventArgs;
#endif /* !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobNotificationEventArgs_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Interface Windows.Graphics.Printing.Workflow.IPrintWorkflowJobStartingEventArgs
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Interface is a part of the implementation of type Windows.Graphics.Printing.Workflow.PrintWorkflowJobStartingEventArgs
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobStartingEventArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobStartingEventArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Graphics_Printing_Workflow_IPrintWorkflowJobStartingEventArgs[] = L"Windows.Graphics.Printing.Workflow.IPrintWorkflowJobStartingEventArgs";
typedef struct __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobStartingEventArgsVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobStartingEventArgs* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobStartingEventArgs* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobStartingEventArgs* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobStartingEventArgs* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobStartingEventArgs* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobStartingEventArgs* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Configuration)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobStartingEventArgs* This,
        __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration** value);
    HRESULT (STDMETHODCALLTYPE* get_Printer)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobStartingEventArgs* This,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppPrintDevice** value);
    HRESULT (STDMETHODCALLTYPE* SetSkipSystemRendering)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobStartingEventArgs* This);
    HRESULT (STDMETHODCALLTYPE* GetDeferral)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobStartingEventArgs* This,
        __x_ABI_CWindows_CFoundation_CIDeferral** result);

    END_INTERFACE
} __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobStartingEventArgsVtbl;

interface __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobStartingEventArgs
{
    CONST_VTBL struct __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobStartingEventArgsVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobStartingEventArgs_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobStartingEventArgs_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobStartingEventArgs_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobStartingEventArgs_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobStartingEventArgs_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobStartingEventArgs_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobStartingEventArgs_get_Configuration(This, value) \
    ((This)->lpVtbl->get_Configuration(This, value))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobStartingEventArgs_get_Printer(This, value) \
    ((This)->lpVtbl->get_Printer(This, value))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobStartingEventArgs_SetSkipSystemRendering(This) \
    ((This)->lpVtbl->SetSkipSystemRendering(This))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobStartingEventArgs_GetDeferral(This, result) \
    ((This)->lpVtbl->GetDeferral(This, result))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobStartingEventArgs;
#endif /* !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobStartingEventArgs_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Interface Windows.Graphics.Printing.Workflow.IPrintWorkflowJobTriggerDetails
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Interface is a part of the implementation of type Windows.Graphics.Printing.Workflow.PrintWorkflowJobTriggerDetails
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobTriggerDetails_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobTriggerDetails_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Graphics_Printing_Workflow_IPrintWorkflowJobTriggerDetails[] = L"Windows.Graphics.Printing.Workflow.IPrintWorkflowJobTriggerDetails";
typedef struct __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobTriggerDetailsVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobTriggerDetails* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobTriggerDetails* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobTriggerDetails* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobTriggerDetails* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobTriggerDetails* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobTriggerDetails* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_PrintWorkflowJobSession)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobTriggerDetails* This,
        __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobBackgroundSession** value);

    END_INTERFACE
} __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobTriggerDetailsVtbl;

interface __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobTriggerDetails
{
    CONST_VTBL struct __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobTriggerDetailsVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobTriggerDetails_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobTriggerDetails_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobTriggerDetails_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobTriggerDetails_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobTriggerDetails_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobTriggerDetails_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobTriggerDetails_get_PrintWorkflowJobSession(This, value) \
    ((This)->lpVtbl->get_PrintWorkflowJobSession(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobTriggerDetails;
#endif /* !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobTriggerDetails_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Interface Windows.Graphics.Printing.Workflow.IPrintWorkflowJobUISession
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Interface is a part of the implementation of type Windows.Graphics.Printing.Workflow.PrintWorkflowJobUISession
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobUISession_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobUISession_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Graphics_Printing_Workflow_IPrintWorkflowJobUISession[] = L"Windows.Graphics.Printing.Workflow.IPrintWorkflowJobUISession";
typedef struct __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobUISessionVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobUISession* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobUISession* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobUISession* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobUISession* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobUISession* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobUISession* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Status)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobUISession* This,
        enum __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CPrintWorkflowSessionStatus* value);
    HRESULT (STDMETHODCALLTYPE* add_PdlDataAvailable)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobUISession* This,
        __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobUISession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowPdlDataAvailableEventArgs* handler,
        EventRegistrationToken* token);
    HRESULT (STDMETHODCALLTYPE* remove_PdlDataAvailable)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobUISession* This,
        EventRegistrationToken token);
    HRESULT (STDMETHODCALLTYPE* add_JobNotification)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobUISession* This,
        __FITypedEventHandler_2_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobUISession_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowJobNotificationEventArgs* handler,
        EventRegistrationToken* token);
    HRESULT (STDMETHODCALLTYPE* remove_JobNotification)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobUISession* This,
        EventRegistrationToken token);
    HRESULT (STDMETHODCALLTYPE* Start)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobUISession* This);

    END_INTERFACE
} __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobUISessionVtbl;

interface __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobUISession
{
    CONST_VTBL struct __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobUISessionVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobUISession_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobUISession_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobUISession_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobUISession_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobUISession_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobUISession_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobUISession_get_Status(This, value) \
    ((This)->lpVtbl->get_Status(This, value))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobUISession_add_PdlDataAvailable(This, handler, token) \
    ((This)->lpVtbl->add_PdlDataAvailable(This, handler, token))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobUISession_remove_PdlDataAvailable(This, token) \
    ((This)->lpVtbl->remove_PdlDataAvailable(This, token))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobUISession_add_JobNotification(This, handler, token) \
    ((This)->lpVtbl->add_JobNotification(This, handler, token))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobUISession_remove_JobNotification(This, token) \
    ((This)->lpVtbl->remove_JobNotification(This, token))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobUISession_Start(This) \
    ((This)->lpVtbl->Start(This))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobUISession;
#endif /* !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowJobUISession_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

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
 * Interface Windows.Graphics.Printing.Workflow.IPrintWorkflowObjectModelSourceFileContentFactory
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Interface is a part of the implementation of type Windows.Graphics.Printing.Workflow.PrintWorkflowObjectModelSourceFileContent
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelSourceFileContentFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelSourceFileContentFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Graphics_Printing_Workflow_IPrintWorkflowObjectModelSourceFileContentFactory[] = L"Windows.Graphics.Printing.Workflow.IPrintWorkflowObjectModelSourceFileContentFactory";
typedef struct __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelSourceFileContentFactoryVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelSourceFileContentFactory* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelSourceFileContentFactory* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelSourceFileContentFactory* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelSourceFileContentFactory* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelSourceFileContentFactory* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelSourceFileContentFactory* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* CreateInstance)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelSourceFileContentFactory* This,
        __x_ABI_CWindows_CStorage_CStreams_CIInputStream* xpsStream,
        __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelSourceFileContent** value);

    END_INTERFACE
} __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelSourceFileContentFactoryVtbl;

interface __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelSourceFileContentFactory
{
    CONST_VTBL struct __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelSourceFileContentFactoryVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelSourceFileContentFactory_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelSourceFileContentFactory_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelSourceFileContentFactory_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelSourceFileContentFactory_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelSourceFileContentFactory_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelSourceFileContentFactory_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelSourceFileContentFactory_CreateInstance(This, xpsStream, value) \
    ((This)->lpVtbl->CreateInstance(This, xpsStream, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelSourceFileContentFactory;
#endif /* !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowObjectModelSourceFileContentFactory_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

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
 * Interface Windows.Graphics.Printing.Workflow.IPrintWorkflowPdlConverter
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Interface is a part of the implementation of type Windows.Graphics.Printing.Workflow.PrintWorkflowPdlConverter
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlConverter_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlConverter_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Graphics_Printing_Workflow_IPrintWorkflowPdlConverter[] = L"Windows.Graphics.Printing.Workflow.IPrintWorkflowPdlConverter";
typedef struct __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlConverterVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlConverter* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlConverter* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlConverter* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlConverter* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlConverter* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlConverter* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* ConvertPdlAsync)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlConverter* This,
        __x_ABI_CWindows_CGraphics_CPrinting_CPrintTicket_CIWorkflowPrintTicket* printTicket,
        __x_ABI_CWindows_CStorage_CStreams_CIInputStream* inputStream,
        __x_ABI_CWindows_CStorage_CStreams_CIOutputStream* outputStream,
        __x_ABI_CWindows_CFoundation_CIAsyncAction** operation);

    END_INTERFACE
} __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlConverterVtbl;

interface __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlConverter
{
    CONST_VTBL struct __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlConverterVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlConverter_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlConverter_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlConverter_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlConverter_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlConverter_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlConverter_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlConverter_ConvertPdlAsync(This, printTicket, inputStream, outputStream, operation) \
    ((This)->lpVtbl->ConvertPdlAsync(This, printTicket, inputStream, outputStream, operation))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlConverter;
#endif /* !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlConverter_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Interface Windows.Graphics.Printing.Workflow.IPrintWorkflowPdlDataAvailableEventArgs
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Interface is a part of the implementation of type Windows.Graphics.Printing.Workflow.PrintWorkflowPdlDataAvailableEventArgs
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlDataAvailableEventArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlDataAvailableEventArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Graphics_Printing_Workflow_IPrintWorkflowPdlDataAvailableEventArgs[] = L"Windows.Graphics.Printing.Workflow.IPrintWorkflowPdlDataAvailableEventArgs";
typedef struct __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlDataAvailableEventArgsVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlDataAvailableEventArgs* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlDataAvailableEventArgs* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlDataAvailableEventArgs* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlDataAvailableEventArgs* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlDataAvailableEventArgs* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlDataAvailableEventArgs* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Configuration)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlDataAvailableEventArgs* This,
        __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration** value);
    HRESULT (STDMETHODCALLTYPE* get_PrinterJob)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlDataAvailableEventArgs* This,
        __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPrinterJob** value);
    HRESULT (STDMETHODCALLTYPE* get_SourceContent)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlDataAvailableEventArgs* This,
        __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlSourceContent** value);
    HRESULT (STDMETHODCALLTYPE* GetDeferral)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlDataAvailableEventArgs* This,
        __x_ABI_CWindows_CFoundation_CIDeferral** result);

    END_INTERFACE
} __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlDataAvailableEventArgsVtbl;

interface __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlDataAvailableEventArgs
{
    CONST_VTBL struct __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlDataAvailableEventArgsVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlDataAvailableEventArgs_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlDataAvailableEventArgs_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlDataAvailableEventArgs_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlDataAvailableEventArgs_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlDataAvailableEventArgs_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlDataAvailableEventArgs_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlDataAvailableEventArgs_get_Configuration(This, value) \
    ((This)->lpVtbl->get_Configuration(This, value))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlDataAvailableEventArgs_get_PrinterJob(This, value) \
    ((This)->lpVtbl->get_PrinterJob(This, value))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlDataAvailableEventArgs_get_SourceContent(This, value) \
    ((This)->lpVtbl->get_SourceContent(This, value))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlDataAvailableEventArgs_GetDeferral(This, result) \
    ((This)->lpVtbl->GetDeferral(This, result))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlDataAvailableEventArgs;
#endif /* !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlDataAvailableEventArgs_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Interface Windows.Graphics.Printing.Workflow.IPrintWorkflowPdlModificationRequestedEventArgs
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Interface is a part of the implementation of type Windows.Graphics.Printing.Workflow.PrintWorkflowPdlModificationRequestedEventArgs
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlModificationRequestedEventArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlModificationRequestedEventArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Graphics_Printing_Workflow_IPrintWorkflowPdlModificationRequestedEventArgs[] = L"Windows.Graphics.Printing.Workflow.IPrintWorkflowPdlModificationRequestedEventArgs";
typedef struct __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlModificationRequestedEventArgsVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlModificationRequestedEventArgs* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlModificationRequestedEventArgs* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlModificationRequestedEventArgs* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlModificationRequestedEventArgs* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlModificationRequestedEventArgs* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlModificationRequestedEventArgs* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Configuration)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlModificationRequestedEventArgs* This,
        __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowConfiguration** value);
    HRESULT (STDMETHODCALLTYPE* get_PrinterJob)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlModificationRequestedEventArgs* This,
        __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPrinterJob** value);
    HRESULT (STDMETHODCALLTYPE* get_SourceContent)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlModificationRequestedEventArgs* This,
        __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlSourceContent** value);
    HRESULT (STDMETHODCALLTYPE* get_UILauncher)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlModificationRequestedEventArgs* This,
        __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowUILauncher** value);
    HRESULT (STDMETHODCALLTYPE* CreateJobOnPrinter)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlModificationRequestedEventArgs* This,
        HSTRING targetContentType,
        __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlTargetStream** result);
    HRESULT (STDMETHODCALLTYPE* CreateJobOnPrinterWithAttributes)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlModificationRequestedEventArgs* This,
        __FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* jobAttributes,
        HSTRING targetContentType,
        __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlTargetStream** result);
    HRESULT (STDMETHODCALLTYPE* CreateJobOnPrinterWithAttributesBuffer)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlModificationRequestedEventArgs* This,
        __x_ABI_CWindows_CStorage_CStreams_CIBuffer* jobAttributesBuffer,
        HSTRING targetContentType,
        __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlTargetStream** result);
    HRESULT (STDMETHODCALLTYPE* GetPdlConverter)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlModificationRequestedEventArgs* This,
        enum __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CPrintWorkflowPdlConversionType conversionType,
        __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlConverter** result);
    HRESULT (STDMETHODCALLTYPE* GetDeferral)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlModificationRequestedEventArgs* This,
        __x_ABI_CWindows_CFoundation_CIDeferral** result);

    END_INTERFACE
} __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlModificationRequestedEventArgsVtbl;

interface __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlModificationRequestedEventArgs
{
    CONST_VTBL struct __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlModificationRequestedEventArgsVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlModificationRequestedEventArgs_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlModificationRequestedEventArgs_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlModificationRequestedEventArgs_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlModificationRequestedEventArgs_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlModificationRequestedEventArgs_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlModificationRequestedEventArgs_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlModificationRequestedEventArgs_get_Configuration(This, value) \
    ((This)->lpVtbl->get_Configuration(This, value))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlModificationRequestedEventArgs_get_PrinterJob(This, value) \
    ((This)->lpVtbl->get_PrinterJob(This, value))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlModificationRequestedEventArgs_get_SourceContent(This, value) \
    ((This)->lpVtbl->get_SourceContent(This, value))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlModificationRequestedEventArgs_get_UILauncher(This, value) \
    ((This)->lpVtbl->get_UILauncher(This, value))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlModificationRequestedEventArgs_CreateJobOnPrinter(This, targetContentType, result) \
    ((This)->lpVtbl->CreateJobOnPrinter(This, targetContentType, result))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlModificationRequestedEventArgs_CreateJobOnPrinterWithAttributes(This, jobAttributes, targetContentType, result) \
    ((This)->lpVtbl->CreateJobOnPrinterWithAttributes(This, jobAttributes, targetContentType, result))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlModificationRequestedEventArgs_CreateJobOnPrinterWithAttributesBuffer(This, jobAttributesBuffer, targetContentType, result) \
    ((This)->lpVtbl->CreateJobOnPrinterWithAttributesBuffer(This, jobAttributesBuffer, targetContentType, result))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlModificationRequestedEventArgs_GetPdlConverter(This, conversionType, result) \
    ((This)->lpVtbl->GetPdlConverter(This, conversionType, result))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlModificationRequestedEventArgs_GetDeferral(This, result) \
    ((This)->lpVtbl->GetDeferral(This, result))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlModificationRequestedEventArgs;
#endif /* !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlModificationRequestedEventArgs_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Interface Windows.Graphics.Printing.Workflow.IPrintWorkflowPdlSourceContent
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Interface is a part of the implementation of type Windows.Graphics.Printing.Workflow.PrintWorkflowPdlSourceContent
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlSourceContent_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlSourceContent_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Graphics_Printing_Workflow_IPrintWorkflowPdlSourceContent[] = L"Windows.Graphics.Printing.Workflow.IPrintWorkflowPdlSourceContent";
typedef struct __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlSourceContentVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlSourceContent* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlSourceContent* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlSourceContent* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlSourceContent* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlSourceContent* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlSourceContent* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_ContentType)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlSourceContent* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* GetInputStream)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlSourceContent* This,
        __x_ABI_CWindows_CStorage_CStreams_CIInputStream** result);
    HRESULT (STDMETHODCALLTYPE* GetContentFileAsync)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlSourceContent* This,
        __FIAsyncOperation_1_Windows__CStorage__CStorageFile** operation);

    END_INTERFACE
} __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlSourceContentVtbl;

interface __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlSourceContent
{
    CONST_VTBL struct __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlSourceContentVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlSourceContent_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlSourceContent_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlSourceContent_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlSourceContent_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlSourceContent_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlSourceContent_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlSourceContent_get_ContentType(This, value) \
    ((This)->lpVtbl->get_ContentType(This, value))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlSourceContent_GetInputStream(This, result) \
    ((This)->lpVtbl->GetInputStream(This, result))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlSourceContent_GetContentFileAsync(This, operation) \
    ((This)->lpVtbl->GetContentFileAsync(This, operation))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlSourceContent;
#endif /* !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlSourceContent_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Interface Windows.Graphics.Printing.Workflow.IPrintWorkflowPdlTargetStream
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Interface is a part of the implementation of type Windows.Graphics.Printing.Workflow.PrintWorkflowPdlTargetStream
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlTargetStream_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlTargetStream_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Graphics_Printing_Workflow_IPrintWorkflowPdlTargetStream[] = L"Windows.Graphics.Printing.Workflow.IPrintWorkflowPdlTargetStream";
typedef struct __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlTargetStreamVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlTargetStream* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlTargetStream* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlTargetStream* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlTargetStream* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlTargetStream* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlTargetStream* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* GetOutputStream)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlTargetStream* This,
        __x_ABI_CWindows_CStorage_CStreams_CIOutputStream** result);
    HRESULT (STDMETHODCALLTYPE* CompleteStreamSubmission)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlTargetStream* This,
        enum __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CPrintWorkflowSubmittedStatus status);

    END_INTERFACE
} __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlTargetStreamVtbl;

interface __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlTargetStream
{
    CONST_VTBL struct __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlTargetStreamVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlTargetStream_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlTargetStream_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlTargetStream_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlTargetStream_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlTargetStream_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlTargetStream_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlTargetStream_GetOutputStream(This, result) \
    ((This)->lpVtbl->GetOutputStream(This, result))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlTargetStream_CompleteStreamSubmission(This, status) \
    ((This)->lpVtbl->CompleteStreamSubmission(This, status))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlTargetStream;
#endif /* !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPdlTargetStream_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Interface Windows.Graphics.Printing.Workflow.IPrintWorkflowPrinterJob
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Interface is a part of the implementation of type Windows.Graphics.Printing.Workflow.PrintWorkflowPrinterJob
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPrinterJob_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPrinterJob_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Graphics_Printing_Workflow_IPrintWorkflowPrinterJob[] = L"Windows.Graphics.Printing.Workflow.IPrintWorkflowPrinterJob";
typedef struct __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPrinterJobVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPrinterJob* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPrinterJob* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPrinterJob* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPrinterJob* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPrinterJob* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPrinterJob* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_JobId)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPrinterJob* This,
        INT32* value);
    HRESULT (STDMETHODCALLTYPE* get_Printer)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPrinterJob* This,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppPrintDevice** value);
    HRESULT (STDMETHODCALLTYPE* GetJobStatus)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPrinterJob* This,
        enum __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CPrintWorkflowPrinterJobStatus* result);
    HRESULT (STDMETHODCALLTYPE* GetJobPrintTicket)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPrinterJob* This,
        __x_ABI_CWindows_CGraphics_CPrinting_CPrintTicket_CIWorkflowPrintTicket** result);
    HRESULT (STDMETHODCALLTYPE* GetJobAttributesAsBuffer)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPrinterJob* This,
        __FIIterable_1_HSTRING* attributeNames,
        __x_ABI_CWindows_CStorage_CStreams_CIBuffer** result);
    HRESULT (STDMETHODCALLTYPE* GetJobAttributes)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPrinterJob* This,
        __FIIterable_1_HSTRING* attributeNames,
        __FIMap_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue** result);
    HRESULT (STDMETHODCALLTYPE* SetJobAttributesFromBuffer)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPrinterJob* This,
        __x_ABI_CWindows_CStorage_CStreams_CIBuffer* jobAttributesBuffer,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppSetAttributesResult** result);
    HRESULT (STDMETHODCALLTYPE* SetJobAttributes)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPrinterJob* This,
        __FIIterable_1___FIKeyValuePair_2_HSTRING_Windows__CDevices__CPrinters__CIppAttributeValue* jobAttributes,
        __x_ABI_CWindows_CDevices_CPrinters_CIIppSetAttributesResult** result);

    END_INTERFACE
} __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPrinterJobVtbl;

interface __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPrinterJob
{
    CONST_VTBL struct __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPrinterJobVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPrinterJob_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPrinterJob_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPrinterJob_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPrinterJob_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPrinterJob_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPrinterJob_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPrinterJob_get_JobId(This, value) \
    ((This)->lpVtbl->get_JobId(This, value))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPrinterJob_get_Printer(This, value) \
    ((This)->lpVtbl->get_Printer(This, value))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPrinterJob_GetJobStatus(This, result) \
    ((This)->lpVtbl->GetJobStatus(This, result))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPrinterJob_GetJobPrintTicket(This, result) \
    ((This)->lpVtbl->GetJobPrintTicket(This, result))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPrinterJob_GetJobAttributesAsBuffer(This, attributeNames, result) \
    ((This)->lpVtbl->GetJobAttributesAsBuffer(This, attributeNames, result))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPrinterJob_GetJobAttributes(This, attributeNames, result) \
    ((This)->lpVtbl->GetJobAttributes(This, attributeNames, result))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPrinterJob_SetJobAttributesFromBuffer(This, jobAttributesBuffer, result) \
    ((This)->lpVtbl->SetJobAttributesFromBuffer(This, jobAttributesBuffer, result))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPrinterJob_SetJobAttributes(This, jobAttributes, result) \
    ((This)->lpVtbl->SetJobAttributes(This, jobAttributes, result))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPrinterJob;
#endif /* !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowPrinterJob_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

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
 * Interface Windows.Graphics.Printing.Workflow.IPrintWorkflowUILauncher
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Interface is a part of the implementation of type Windows.Graphics.Printing.Workflow.PrintWorkflowUILauncher
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowUILauncher_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowUILauncher_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Graphics_Printing_Workflow_IPrintWorkflowUILauncher[] = L"Windows.Graphics.Printing.Workflow.IPrintWorkflowUILauncher";
typedef struct __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowUILauncherVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowUILauncher* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowUILauncher* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowUILauncher* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowUILauncher* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowUILauncher* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowUILauncher* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* IsUILaunchEnabled)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowUILauncher* This,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* LaunchAndCompleteUIAsync)(__x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowUILauncher* This,
        __FIAsyncOperation_1_Windows__CGraphics__CPrinting__CWorkflow__CPrintWorkflowUICompletionStatus** operation);

    END_INTERFACE
} __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowUILauncherVtbl;

interface __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowUILauncher
{
    CONST_VTBL struct __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowUILauncherVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowUILauncher_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowUILauncher_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowUILauncher_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowUILauncher_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowUILauncher_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowUILauncher_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowUILauncher_IsUILaunchEnabled(This, result) \
    ((This)->lpVtbl->IsUILaunchEnabled(This, result))

#define __x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowUILauncher_LaunchAndCompleteUIAsync(This, operation) \
    ((This)->lpVtbl->LaunchAndCompleteUIAsync(This, operation))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowUILauncher;
#endif /* !defined(____x_ABI_CWindows_CGraphics_CPrinting_CWorkflow_CIPrintWorkflowUILauncher_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

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
 *    Windows.Graphics.Printing.Workflow.IPrintWorkflowConfiguration2
 *    Windows.Graphics.Printing.Workflow.IPrintWorkflowConfiguration ** Default Interface **
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
 * Class Windows.Graphics.Printing.Workflow.PrintWorkflowJobActivatedEventArgs
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Class implements the following interfaces:
 *    Windows.Graphics.Printing.Workflow.IPrintWorkflowJobActivatedEventArgs ** Default Interface **
 *    Windows.ApplicationModel.Activation.IActivatedEventArgs
 *    Windows.ApplicationModel.Activation.IActivatedEventArgsWithUser
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#ifndef RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowJobActivatedEventArgs_DEFINED
#define RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowJobActivatedEventArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Graphics_Printing_Workflow_PrintWorkflowJobActivatedEventArgs[] = L"Windows.Graphics.Printing.Workflow.PrintWorkflowJobActivatedEventArgs";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Class Windows.Graphics.Printing.Workflow.PrintWorkflowJobBackgroundSession
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Class implements the following interfaces:
 *    Windows.Graphics.Printing.Workflow.IPrintWorkflowJobBackgroundSession ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#ifndef RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowJobBackgroundSession_DEFINED
#define RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowJobBackgroundSession_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Graphics_Printing_Workflow_PrintWorkflowJobBackgroundSession[] = L"Windows.Graphics.Printing.Workflow.PrintWorkflowJobBackgroundSession";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Class Windows.Graphics.Printing.Workflow.PrintWorkflowJobNotificationEventArgs
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Class implements the following interfaces:
 *    Windows.Graphics.Printing.Workflow.IPrintWorkflowJobNotificationEventArgs ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#ifndef RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowJobNotificationEventArgs_DEFINED
#define RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowJobNotificationEventArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Graphics_Printing_Workflow_PrintWorkflowJobNotificationEventArgs[] = L"Windows.Graphics.Printing.Workflow.PrintWorkflowJobNotificationEventArgs";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Class Windows.Graphics.Printing.Workflow.PrintWorkflowJobStartingEventArgs
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Class implements the following interfaces:
 *    Windows.Graphics.Printing.Workflow.IPrintWorkflowJobStartingEventArgs ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#ifndef RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowJobStartingEventArgs_DEFINED
#define RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowJobStartingEventArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Graphics_Printing_Workflow_PrintWorkflowJobStartingEventArgs[] = L"Windows.Graphics.Printing.Workflow.PrintWorkflowJobStartingEventArgs";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Class Windows.Graphics.Printing.Workflow.PrintWorkflowJobTriggerDetails
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Class implements the following interfaces:
 *    Windows.Graphics.Printing.Workflow.IPrintWorkflowJobTriggerDetails ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#ifndef RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowJobTriggerDetails_DEFINED
#define RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowJobTriggerDetails_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Graphics_Printing_Workflow_PrintWorkflowJobTriggerDetails[] = L"Windows.Graphics.Printing.Workflow.PrintWorkflowJobTriggerDetails";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Class Windows.Graphics.Printing.Workflow.PrintWorkflowJobUISession
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Class implements the following interfaces:
 *    Windows.Graphics.Printing.Workflow.IPrintWorkflowJobUISession ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#ifndef RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowJobUISession_DEFINED
#define RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowJobUISession_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Graphics_Printing_Workflow_PrintWorkflowJobUISession[] = L"Windows.Graphics.Printing.Workflow.PrintWorkflowJobUISession";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Class Windows.Graphics.Printing.Workflow.PrintWorkflowObjectModelSourceFileContent
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via the Windows.Graphics.Printing.Workflow.IPrintWorkflowObjectModelSourceFileContentFactory interface starting with version 13.0 of the Windows.Foundation.UniversalApiContract API contract
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
 * Class Windows.Graphics.Printing.Workflow.PrintWorkflowPdlConverter
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Class implements the following interfaces:
 *    Windows.Graphics.Printing.Workflow.IPrintWorkflowPdlConverter ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#ifndef RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowPdlConverter_DEFINED
#define RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowPdlConverter_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Graphics_Printing_Workflow_PrintWorkflowPdlConverter[] = L"Windows.Graphics.Printing.Workflow.PrintWorkflowPdlConverter";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Class Windows.Graphics.Printing.Workflow.PrintWorkflowPdlDataAvailableEventArgs
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Class implements the following interfaces:
 *    Windows.Graphics.Printing.Workflow.IPrintWorkflowPdlDataAvailableEventArgs ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#ifndef RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowPdlDataAvailableEventArgs_DEFINED
#define RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowPdlDataAvailableEventArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Graphics_Printing_Workflow_PrintWorkflowPdlDataAvailableEventArgs[] = L"Windows.Graphics.Printing.Workflow.PrintWorkflowPdlDataAvailableEventArgs";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Class Windows.Graphics.Printing.Workflow.PrintWorkflowPdlModificationRequestedEventArgs
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Class implements the following interfaces:
 *    Windows.Graphics.Printing.Workflow.IPrintWorkflowPdlModificationRequestedEventArgs ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#ifndef RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowPdlModificationRequestedEventArgs_DEFINED
#define RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowPdlModificationRequestedEventArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Graphics_Printing_Workflow_PrintWorkflowPdlModificationRequestedEventArgs[] = L"Windows.Graphics.Printing.Workflow.PrintWorkflowPdlModificationRequestedEventArgs";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Class Windows.Graphics.Printing.Workflow.PrintWorkflowPdlSourceContent
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Class implements the following interfaces:
 *    Windows.Graphics.Printing.Workflow.IPrintWorkflowPdlSourceContent ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#ifndef RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowPdlSourceContent_DEFINED
#define RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowPdlSourceContent_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Graphics_Printing_Workflow_PrintWorkflowPdlSourceContent[] = L"Windows.Graphics.Printing.Workflow.PrintWorkflowPdlSourceContent";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Class Windows.Graphics.Printing.Workflow.PrintWorkflowPdlTargetStream
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Class implements the following interfaces:
 *    Windows.Graphics.Printing.Workflow.IPrintWorkflowPdlTargetStream ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#ifndef RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowPdlTargetStream_DEFINED
#define RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowPdlTargetStream_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Graphics_Printing_Workflow_PrintWorkflowPdlTargetStream[] = L"Windows.Graphics.Printing.Workflow.PrintWorkflowPdlTargetStream";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Class Windows.Graphics.Printing.Workflow.PrintWorkflowPrinterJob
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Class implements the following interfaces:
 *    Windows.Graphics.Printing.Workflow.IPrintWorkflowPrinterJob ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#ifndef RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowPrinterJob_DEFINED
#define RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowPrinterJob_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Graphics_Printing_Workflow_PrintWorkflowPrinterJob[] = L"Windows.Graphics.Printing.Workflow.PrintWorkflowPrinterJob";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

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
 * Class Windows.Graphics.Printing.Workflow.PrintWorkflowUILauncher
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Class implements the following interfaces:
 *    Windows.Graphics.Printing.Workflow.IPrintWorkflowUILauncher ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#ifndef RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowUILauncher_DEFINED
#define RUNTIMECLASS_Windows_Graphics_Printing_Workflow_PrintWorkflowUILauncher_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Graphics_Printing_Workflow_PrintWorkflowUILauncher[] = L"Windows.Graphics.Printing.Workflow.PrintWorkflowUILauncher";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

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
