
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
#ifndef __windows2Eai2Eagents2Emcp_h__
#define __windows2Eai2Eagents2Emcp_h__
#ifndef __windows2Eai2Eagents2Emcp_p_h__
#define __windows2Eai2Eagents2Emcp_p_h__


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
#if !defined(WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION)
#define WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION 0x20000
#endif // defined(WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION)

#if !defined(WINDOWS_APPLICATIONMODEL_FULLTRUSTAPPCONTRACT_VERSION)
#define WINDOWS_APPLICATIONMODEL_FULLTRUSTAPPCONTRACT_VERSION 0x20000
#endif // defined(WINDOWS_APPLICATIONMODEL_FULLTRUSTAPPCONTRACT_VERSION)

#if !defined(WINDOWS_APPLICATIONMODEL_STARTUPTASKCONTRACT_VERSION)
#define WINDOWS_APPLICATIONMODEL_STARTUPTASKCONTRACT_VERSION 0x30000
#endif // defined(WINDOWS_APPLICATIONMODEL_STARTUPTASKCONTRACT_VERSION)

#if !defined(WINDOWS_FOUNDATION_FOUNDATIONCONTRACT_VERSION)
#define WINDOWS_FOUNDATION_FOUNDATIONCONTRACT_VERSION 0x40000
#endif // defined(WINDOWS_FOUNDATION_FOUNDATIONCONTRACT_VERSION)

#if !defined(WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION)
#define WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION 0x130000
#endif // defined(WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION)

#endif // defined(SPECIFIC_API_CONTRACT_DEFINITIONS)


// Header files for imported files
#include "inspectable.h"
#include "AsyncInfo.h"
#include "EventToken.h"
#include "windowscontracts.h"
#include "Windows.Foundation.h"
#include "Windows.AI.Agents.h"
#include "Windows.ApplicationModel.h"
#include "Windows.UI.h"
// Importing Collections header
#include <windows.foundation.collections.h>

#if defined(__cplusplus) && !defined(CINTERFACE)
/* Forward Declarations */
#ifndef ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpHttpConnectionResult_FWD_DEFINED__
#define ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpHttpConnectionResult_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Agents {
                namespace Mcp {
                    interface IMcpHttpConnectionResult;
                } /* Mcp */
            } /* Agents */
        } /* AI */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpHttpConnectionResult ABI::Windows::AI::Agents::Mcp::IMcpHttpConnectionResult

#endif // ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpHttpConnectionResult_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpMessageFilter_FWD_DEFINED__
#define ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpMessageFilter_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Agents {
                namespace Mcp {
                    interface IMcpMessageFilter;
                } /* Mcp */
            } /* Agents */
        } /* AI */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpMessageFilter ABI::Windows::AI::Agents::Mcp::IMcpMessageFilter

#endif // ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpMessageFilter_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpMessageFilterResponse_FWD_DEFINED__
#define ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpMessageFilterResponse_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Agents {
                namespace Mcp {
                    interface IMcpMessageFilterResponse;
                } /* Mcp */
            } /* Agents */
        } /* AI */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpMessageFilterResponse ABI::Windows::AI::Agents::Mcp::IMcpMessageFilterResponse

#endif // ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpMessageFilterResponse_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpNamedPipeConnectionResult_FWD_DEFINED__
#define ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpNamedPipeConnectionResult_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Agents {
                namespace Mcp {
                    interface IMcpNamedPipeConnectionResult;
                } /* Mcp */
            } /* Agents */
        } /* AI */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpNamedPipeConnectionResult ABI::Windows::AI::Agents::Mcp::IMcpNamedPipeConnectionResult

#endif // ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpNamedPipeConnectionResult_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpNamedPipeConnectionServer_FWD_DEFINED__
#define ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpNamedPipeConnectionServer_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Agents {
                namespace Mcp {
                    interface IMcpNamedPipeConnectionServer;
                } /* Mcp */
            } /* Agents */
        } /* AI */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpNamedPipeConnectionServer ABI::Windows::AI::Agents::Mcp::IMcpNamedPipeConnectionServer

#endif // ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpNamedPipeConnectionServer_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpResourcesStatics_FWD_DEFINED__
#define ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpResourcesStatics_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Agents {
                namespace Mcp {
                    interface IMcpResourcesStatics;
                } /* Mcp */
            } /* Agents */
        } /* AI */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpResourcesStatics ABI::Windows::AI::Agents::Mcp::IMcpResourcesStatics

#endif // ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpResourcesStatics_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerContext_FWD_DEFINED__
#define ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerContext_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Agents {
                namespace Mcp {
                    interface IMcpServerContext;
                } /* Mcp */
            } /* Agents */
        } /* AI */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerContext ABI::Windows::AI::Agents::Mcp::IMcpServerContext

#endif // ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerContext_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerContextStatics_FWD_DEFINED__
#define ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerContextStatics_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Agents {
                namespace Mcp {
                    interface IMcpServerContextStatics;
                } /* Mcp */
            } /* Agents */
        } /* AI */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerContextStatics ABI::Windows::AI::Agents::Mcp::IMcpServerContextStatics

#endif // ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerContextStatics_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerInfo_FWD_DEFINED__
#define ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerInfo_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Agents {
                namespace Mcp {
                    interface IMcpServerInfo;
                } /* Mcp */
            } /* Agents */
        } /* AI */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerInfo ABI::Windows::AI::Agents::Mcp::IMcpServerInfo

#endif // ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerInfo_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerRegistry_FWD_DEFINED__
#define ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerRegistry_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Agents {
                namespace Mcp {
                    interface IMcpServerRegistry;
                } /* Mcp */
            } /* Agents */
        } /* AI */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerRegistry ABI::Windows::AI::Agents::Mcp::IMcpServerRegistry

#endif // ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerRegistry_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerRegistryStatics_FWD_DEFINED__
#define ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerRegistryStatics_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Agents {
                namespace Mcp {
                    interface IMcpServerRegistryStatics;
                } /* Mcp */
            } /* Agents */
        } /* AI */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerRegistryStatics ABI::Windows::AI::Agents::Mcp::IMcpServerRegistryStatics

#endif // ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerRegistryStatics_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpSseConnectionServer_FWD_DEFINED__
#define ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpSseConnectionServer_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Agents {
                namespace Mcp {
                    interface IMcpSseConnectionServer;
                } /* Mcp */
            } /* Agents */
        } /* AI */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpSseConnectionServer ABI::Windows::AI::Agents::Mcp::IMcpSseConnectionServer

#endif // ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpSseConnectionServer_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpStdioConnectionInfo_FWD_DEFINED__
#define ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpStdioConnectionInfo_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Agents {
                namespace Mcp {
                    interface IMcpStdioConnectionInfo;
                } /* Mcp */
            } /* Agents */
        } /* AI */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpStdioConnectionInfo ABI::Windows::AI::Agents::Mcp::IMcpStdioConnectionInfo

#endif // ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpStdioConnectionInfo_FWD_DEFINED__

// Parameterized interface forward declarations (C++)

// Collection interface definitions
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

#ifndef ____x_ABI_CWindows_CFoundation_CIClosable_FWD_DEFINED__
#define ____x_ABI_CWindows_CFoundation_CIClosable_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Foundation {
            interface IClosable;
        } /* Foundation */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CFoundation_CIClosable ABI::Windows::Foundation::IClosable

#endif // ____x_ABI_CWindows_CFoundation_CIClosable_FWD_DEFINED__

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
        namespace UI {
            typedef struct WindowId WindowId;
        } /* UI */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Agents {
                namespace Mcp {
                    typedef enum McpAuthorizationResponse : int McpAuthorizationResponse;
                } /* Mcp */
            } /* Agents */
        } /* AI */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Agents {
                namespace Mcp {
                    typedef enum McpMessageAction : int McpMessageAction;
                } /* Mcp */
            } /* Agents */
        } /* AI */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Agents {
                namespace Mcp {
                    typedef enum McpMessageDirection : int McpMessageDirection;
                } /* Mcp */
            } /* Agents */
        } /* AI */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Agents {
                namespace Mcp {
                    class McpHttpConnectionResult;
                } /* Mcp */
            } /* Agents */
        } /* AI */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Agents {
                namespace Mcp {
                    class McpMessageFilterResponse;
                } /* Mcp */
            } /* Agents */
        } /* AI */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Agents {
                namespace Mcp {
                    class McpNamedPipeConnectionResult;
                } /* Mcp */
            } /* Agents */
        } /* AI */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Agents {
                namespace Mcp {
                    class McpServerContext;
                } /* Mcp */
            } /* Agents */
        } /* AI */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Agents {
                namespace Mcp {
                    class McpServerInfo;
                } /* Mcp */
            } /* Agents */
        } /* AI */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Agents {
                namespace Mcp {
                    class McpServerRegistry;
                } /* Mcp */
            } /* Agents */
        } /* AI */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Agents {
                namespace Mcp {
                    class McpStdioConnectionInfo;
                } /* Mcp */
            } /* Agents */
        } /* AI */
    } /* Windows */
} /* ABI */

/*
 *
 * Struct Windows.AI.Agents.Mcp.McpAuthorizationResponse
 *
 * Introduced to Windows.AI.Agents.AgentsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x10000
namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Agents {
                namespace Mcp {
                    enum McpAuthorizationResponse : int
                    {
                        McpAuthorizationResponse_Denied = 0,
                        McpAuthorizationResponse_Approved = 1,
                    };
                } /* Mcp */
            } /* Agents */
        } /* AI */
    } /* Windows */
} /* ABI */
#endif // WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Struct Windows.AI.Agents.Mcp.McpMessageAction
 *
 * Introduced to Windows.AI.Agents.AgentsContract in version 2.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x20000
namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Agents {
                namespace Mcp {
                    enum McpMessageAction : int
                    {
                        McpMessageAction_Allow = 0,
                        McpMessageAction_Block = 1,
                    };
                } /* Mcp */
            } /* Agents */
        } /* AI */
    } /* Windows */
} /* ABI */
#endif // WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x20000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Struct Windows.AI.Agents.Mcp.McpMessageDirection
 *
 * Introduced to Windows.AI.Agents.AgentsContract in version 2.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x20000
namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Agents {
                namespace Mcp {
                    enum McpMessageDirection : int
                    {
                        McpMessageDirection_Request = 0,
                        McpMessageDirection_Response = 1,
                    };
                } /* Mcp */
            } /* Agents */
        } /* AI */
    } /* Windows */
} /* ABI */
#endif // WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x20000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Interface Windows.AI.Agents.Mcp.IMcpHttpConnectionResult
 *
 * Introduced to Windows.AI.Agents.AgentsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Interface is a part of the implementation of type Windows.AI.Agents.Mcp.McpHttpConnectionResult
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpHttpConnectionResult_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpHttpConnectionResult_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_AI_Agents_Mcp_IMcpHttpConnectionResult[] = L"Windows.AI.Agents.Mcp.IMcpHttpConnectionResult";
namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Agents {
                namespace Mcp {
                    MIDL_INTERFACE("d2c3755f-6d3c-5e90-84dd-3e0973049606")
                    IMcpHttpConnectionResult : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE get_Uri(
                            ABI::Windows::Foundation::IUriRuntimeClass** value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE put_Uri(
                            ABI::Windows::Foundation::IUriRuntimeClass* value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_Headers(
                            ABI::Windows::Foundation::Collections::IPropertySet** value
                            ) = 0;
                    };

                    MIDL_CONST_ID IID& IID_IMcpHttpConnectionResult = __uuidof(IMcpHttpConnectionResult);
                } /* Mcp */
            } /* Agents */
        } /* AI */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpHttpConnectionResult;
#endif /* !defined(____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpHttpConnectionResult_INTERFACE_DEFINED__) */
#endif // WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Interface Windows.AI.Agents.Mcp.IMcpMessageFilter
 *
 * Introduced to Windows.AI.Agents.AgentsContract in version 2.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x20000
#if !defined(____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpMessageFilter_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpMessageFilter_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_AI_Agents_Mcp_IMcpMessageFilter[] = L"Windows.AI.Agents.Mcp.IMcpMessageFilter";
namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Agents {
                namespace Mcp {
                    MIDL_INTERFACE("8ee681f8-f858-56f7-a0c7-45f928845f9b")
                    IMcpMessageFilter : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE Initialize(
                            HSTRING clientAppUserModelId,
                            HSTRING serverPackageFamilyName,
                            HSTRING serverId
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE OnMessage(
                            HSTRING message,
                            ABI::Windows::AI::Agents::Mcp::McpMessageDirection direction,
                            ABI::Windows::AI::Agents::Mcp::IMcpMessageFilterResponse* filterResponse
                            ) = 0;
                    };

                    MIDL_CONST_ID IID& IID_IMcpMessageFilter = __uuidof(IMcpMessageFilter);
                } /* Mcp */
            } /* Agents */
        } /* AI */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpMessageFilter;
#endif /* !defined(____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpMessageFilter_INTERFACE_DEFINED__) */
#endif // WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x20000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Interface Windows.AI.Agents.Mcp.IMcpMessageFilterResponse
 *
 * Introduced to Windows.AI.Agents.AgentsContract in version 2.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Interface is a part of the implementation of type Windows.AI.Agents.Mcp.McpMessageFilterResponse
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x20000
#if !defined(____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpMessageFilterResponse_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpMessageFilterResponse_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_AI_Agents_Mcp_IMcpMessageFilterResponse[] = L"Windows.AI.Agents.Mcp.IMcpMessageFilterResponse";
namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Agents {
                namespace Mcp {
                    MIDL_INTERFACE("bcfc9710-e1d8-5ed4-9dab-03269635d83b")
                    IMcpMessageFilterResponse : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE get_MessageAction(
                            ABI::Windows::AI::Agents::Mcp::McpMessageAction* value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE put_MessageAction(
                            ABI::Windows::AI::Agents::Mcp::McpMessageAction value
                            ) = 0;
                    };

                    MIDL_CONST_ID IID& IID_IMcpMessageFilterResponse = __uuidof(IMcpMessageFilterResponse);
                } /* Mcp */
            } /* Agents */
        } /* AI */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpMessageFilterResponse;
#endif /* !defined(____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpMessageFilterResponse_INTERFACE_DEFINED__) */
#endif // WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x20000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Interface Windows.AI.Agents.Mcp.IMcpNamedPipeConnectionResult
 *
 * Introduced to Windows.AI.Agents.AgentsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Interface is a part of the implementation of type Windows.AI.Agents.Mcp.McpNamedPipeConnectionResult
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpNamedPipeConnectionResult_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpNamedPipeConnectionResult_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_AI_Agents_Mcp_IMcpNamedPipeConnectionResult[] = L"Windows.AI.Agents.Mcp.IMcpNamedPipeConnectionResult";
namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Agents {
                namespace Mcp {
                    MIDL_INTERFACE("8a2aef6f-b4dc-5180-a3e1-47b63dbbb70a")
                    IMcpNamedPipeConnectionResult : public IInspectable
                    {
                    public:
                    };

                    MIDL_CONST_ID IID& IID_IMcpNamedPipeConnectionResult = __uuidof(IMcpNamedPipeConnectionResult);
                } /* Mcp */
            } /* Agents */
        } /* AI */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpNamedPipeConnectionResult;
#endif /* !defined(____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpNamedPipeConnectionResult_INTERFACE_DEFINED__) */
#endif // WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Interface Windows.AI.Agents.Mcp.IMcpNamedPipeConnectionServer
 *
 * Introduced to Windows.AI.Agents.AgentsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpNamedPipeConnectionServer_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpNamedPipeConnectionServer_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_AI_Agents_Mcp_IMcpNamedPipeConnectionServer[] = L"Windows.AI.Agents.Mcp.IMcpNamedPipeConnectionServer";
namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Agents {
                namespace Mcp {
                    MIDL_INTERFACE("52bbbdea-3858-5e4c-91d2-86deebf8ecd0")
                    IMcpNamedPipeConnectionServer : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE Connect(
                            ABI::Windows::AI::Agents::Mcp::IMcpServerContext* hostContext,
                            HSTRING pipeName,
                            ABI::Windows::AI::Agents::Mcp::IMcpNamedPipeConnectionResult* connectionResult
                            ) = 0;
                    };

                    MIDL_CONST_ID IID& IID_IMcpNamedPipeConnectionServer = __uuidof(IMcpNamedPipeConnectionServer);
                } /* Mcp */
            } /* Agents */
        } /* AI */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpNamedPipeConnectionServer;
#endif /* !defined(____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpNamedPipeConnectionServer_INTERFACE_DEFINED__) */
#endif // WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Interface Windows.AI.Agents.Mcp.IMcpResourcesStatics
 *
 * Introduced to Windows.AI.Agents.AgentsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Interface is a part of the implementation of type Windows.AI.Agents.Mcp.McpResources
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpResourcesStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpResourcesStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_AI_Agents_Mcp_IMcpResourcesStatics[] = L"Windows.AI.Agents.Mcp.IMcpResourcesStatics";
namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Agents {
                namespace Mcp {
                    MIDL_INTERFACE("9b9f451c-73f8-59c0-bbea-5ceb60b5f26c")
                    IMcpResourcesStatics : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE get_FileSystemRead(
                            HSTRING* value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_FileSystemWrite(
                            HSTRING* value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_FileSystemDelete(
                            HSTRING* value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_FileSystemCreate(
                            HSTRING* value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_HttpGet(
                            HSTRING* value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_HttpPost(
                            HSTRING* value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_HttpPut(
                            HSTRING* value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_HttpDelete(
                            HSTRING* value
                            ) = 0;
                    };

                    MIDL_CONST_ID IID& IID_IMcpResourcesStatics = __uuidof(IMcpResourcesStatics);
                } /* Mcp */
            } /* Agents */
        } /* AI */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpResourcesStatics;
#endif /* !defined(____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpResourcesStatics_INTERFACE_DEFINED__) */
#endif // WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Interface Windows.AI.Agents.Mcp.IMcpServerContext
 *
 * Introduced to Windows.AI.Agents.AgentsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Interface is a part of the implementation of type Windows.AI.Agents.Mcp.McpServerContext
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerContext_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerContext_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_AI_Agents_Mcp_IMcpServerContext[] = L"Windows.AI.Agents.Mcp.IMcpServerContext";
namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Agents {
                namespace Mcp {
                    MIDL_INTERFACE("d92a55b5-5c54-5505-960a-8a1a15180e8b")
                    IMcpServerContext : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE get_AppId(
                            HSTRING* value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE RequestResourceAccess(
                            ABI::Windows::Foundation::IUriRuntimeClass* resource,
                            HSTRING description,
                            HSTRING reasonForAsking,
                            ABI::Windows::AI::Agents::Mcp::McpAuthorizationResponse* result
                            ) = 0;
                    };

                    MIDL_CONST_ID IID& IID_IMcpServerContext = __uuidof(IMcpServerContext);
                } /* Mcp */
            } /* Agents */
        } /* AI */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerContext;
#endif /* !defined(____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerContext_INTERFACE_DEFINED__) */
#endif // WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Interface Windows.AI.Agents.Mcp.IMcpServerContextStatics
 *
 * Introduced to Windows.AI.Agents.AgentsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Interface is a part of the implementation of type Windows.AI.Agents.Mcp.McpServerContext
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerContextStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerContextStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_AI_Agents_Mcp_IMcpServerContextStatics[] = L"Windows.AI.Agents.Mcp.IMcpServerContextStatics";
namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Agents {
                namespace Mcp {
                    MIDL_INTERFACE("1f84b814-9fe8-521d-bf3c-b2f12861b29b")
                    IMcpServerContextStatics : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE GetContextForCaller(
                            ABI::Windows::AI::Agents::Mcp::IMcpServerContext** result
                            ) = 0;
                    };

                    MIDL_CONST_ID IID& IID_IMcpServerContextStatics = __uuidof(IMcpServerContextStatics);
                } /* Mcp */
            } /* Agents */
        } /* AI */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerContextStatics;
#endif /* !defined(____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerContextStatics_INTERFACE_DEFINED__) */
#endif // WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Interface Windows.AI.Agents.Mcp.IMcpServerInfo
 *
 * Introduced to Windows.AI.Agents.AgentsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Interface is a part of the implementation of type Windows.AI.Agents.Mcp.McpServerInfo
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerInfo_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerInfo_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_AI_Agents_Mcp_IMcpServerInfo[] = L"Windows.AI.Agents.Mcp.IMcpServerInfo";
namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Agents {
                namespace Mcp {
                    MIDL_INTERFACE("96622943-0771-4960-8851-7e3ee690ea7e")
                    IMcpServerInfo : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE get_Id(
                            GUID* value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_Name(
                            HSTRING* value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_Description(
                            HSTRING* value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_Package(
                            ABI::Windows::ApplicationModel::IPackage** value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_DisplayName(
                            HSTRING* value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_AppUserModelId(
                            HSTRING* value
                            ) = 0;
                    };

                    MIDL_CONST_ID IID& IID_IMcpServerInfo = __uuidof(IMcpServerInfo);
                } /* Mcp */
            } /* Agents */
        } /* AI */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerInfo;
#endif /* !defined(____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerInfo_INTERFACE_DEFINED__) */
#endif // WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Interface Windows.AI.Agents.Mcp.IMcpServerRegistry
 *
 * Introduced to Windows.AI.Agents.AgentsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Interface is a part of the implementation of type Windows.AI.Agents.Mcp.McpServerRegistry
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerRegistry_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerRegistry_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_AI_Agents_Mcp_IMcpServerRegistry[] = L"Windows.AI.Agents.Mcp.IMcpServerRegistry";
namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Agents {
                namespace Mcp {
                    MIDL_INTERFACE("fece06c6-0aa5-4bd1-8e64-fbc5f328f5dc")
                    IMcpServerRegistry : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE GetMcpServerInfos(
                            UINT32* resultLength,
                            ABI::Windows::AI::Agents::Mcp::IMcpServerInfo*** result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE GetMcpConnectionInfo(
                            GUID mcpServerId,
                            ABI::Windows::UI::WindowId ownerWindowId,
                            ABI::Windows::AI::Agents::Mcp::IMcpStdioConnectionInfo** result
                            ) = 0;
                    };

                    MIDL_CONST_ID IID& IID_IMcpServerRegistry = __uuidof(IMcpServerRegistry);
                } /* Mcp */
            } /* Agents */
        } /* AI */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerRegistry;
#endif /* !defined(____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerRegistry_INTERFACE_DEFINED__) */
#endif // WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Interface Windows.AI.Agents.Mcp.IMcpServerRegistryStatics
 *
 * Introduced to Windows.AI.Agents.AgentsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Interface is a part of the implementation of type Windows.AI.Agents.Mcp.McpServerRegistry
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerRegistryStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerRegistryStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_AI_Agents_Mcp_IMcpServerRegistryStatics[] = L"Windows.AI.Agents.Mcp.IMcpServerRegistryStatics";
namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Agents {
                namespace Mcp {
                    MIDL_INTERFACE("4acf7fed-d300-55bc-9dde-9f433cdc903d")
                    IMcpServerRegistryStatics : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE GetDefault(
                            ABI::Windows::AI::Agents::Mcp::IMcpServerRegistry** result
                            ) = 0;
                    };

                    MIDL_CONST_ID IID& IID_IMcpServerRegistryStatics = __uuidof(IMcpServerRegistryStatics);
                } /* Mcp */
            } /* Agents */
        } /* AI */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerRegistryStatics;
#endif /* !defined(____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerRegistryStatics_INTERFACE_DEFINED__) */
#endif // WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Interface Windows.AI.Agents.Mcp.IMcpSseConnectionServer
 *
 * Introduced to Windows.AI.Agents.AgentsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpSseConnectionServer_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpSseConnectionServer_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_AI_Agents_Mcp_IMcpSseConnectionServer[] = L"Windows.AI.Agents.Mcp.IMcpSseConnectionServer";
namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Agents {
                namespace Mcp {
                    MIDL_INTERFACE("c460edda-9200-5ecb-91b3-157ee1d2fdf5")
                    IMcpSseConnectionServer : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE Connect(
                            ABI::Windows::AI::Agents::Mcp::IMcpServerContext* hostContext,
                            ABI::Windows::AI::Agents::Mcp::IMcpHttpConnectionResult* connectionResult
                            ) = 0;
                    };

                    MIDL_CONST_ID IID& IID_IMcpSseConnectionServer = __uuidof(IMcpSseConnectionServer);
                } /* Mcp */
            } /* Agents */
        } /* AI */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpSseConnectionServer;
#endif /* !defined(____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpSseConnectionServer_INTERFACE_DEFINED__) */
#endif // WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Interface Windows.AI.Agents.Mcp.IMcpStdioConnectionInfo
 *
 * Introduced to Windows.AI.Agents.AgentsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Interface is a part of the implementation of type Windows.AI.Agents.Mcp.McpStdioConnectionInfo
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpStdioConnectionInfo_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpStdioConnectionInfo_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_AI_Agents_Mcp_IMcpStdioConnectionInfo[] = L"Windows.AI.Agents.Mcp.IMcpStdioConnectionInfo";
namespace ABI {
    namespace Windows {
        namespace AI {
            namespace Agents {
                namespace Mcp {
                    MIDL_INTERFACE("fbc54aac-590b-526c-a545-b7c731b18c39")
                    IMcpStdioConnectionInfo : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE get_Command(
                            HSTRING* value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE GetCommandArguments(
                            UINT32* resultLength,
                            HSTRING** result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_Info(
                            ABI::Windows::AI::Agents::Mcp::IMcpServerInfo** value
                            ) = 0;
                    };

                    MIDL_CONST_ID IID& IID_IMcpStdioConnectionInfo = __uuidof(IMcpStdioConnectionInfo);
                } /* Mcp */
            } /* Agents */
        } /* AI */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpStdioConnectionInfo;
#endif /* !defined(____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpStdioConnectionInfo_INTERFACE_DEFINED__) */
#endif // WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Class Windows.AI.Agents.Mcp.McpHttpConnectionResult
 *
 * Introduced to Windows.AI.Agents.AgentsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Class implements the following interfaces:
 *    Windows.AI.Agents.Mcp.IMcpHttpConnectionResult ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_AI_Agents_Mcp_McpHttpConnectionResult_DEFINED
#define RUNTIMECLASS_Windows_AI_Agents_Mcp_McpHttpConnectionResult_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_AI_Agents_Mcp_McpHttpConnectionResult[] = L"Windows.AI.Agents.Mcp.McpHttpConnectionResult";
#endif
#endif // WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Class Windows.AI.Agents.Mcp.McpMessageFilterResponse
 *
 * Introduced to Windows.AI.Agents.AgentsContract in version 2.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Class implements the following interfaces:
 *    Windows.AI.Agents.Mcp.IMcpMessageFilterResponse ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x20000
#ifndef RUNTIMECLASS_Windows_AI_Agents_Mcp_McpMessageFilterResponse_DEFINED
#define RUNTIMECLASS_Windows_AI_Agents_Mcp_McpMessageFilterResponse_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_AI_Agents_Mcp_McpMessageFilterResponse[] = L"Windows.AI.Agents.Mcp.McpMessageFilterResponse";
#endif
#endif // WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x20000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Class Windows.AI.Agents.Mcp.McpNamedPipeConnectionResult
 *
 * Introduced to Windows.AI.Agents.AgentsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Class implements the following interfaces:
 *    Windows.AI.Agents.Mcp.IMcpNamedPipeConnectionResult ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_AI_Agents_Mcp_McpNamedPipeConnectionResult_DEFINED
#define RUNTIMECLASS_Windows_AI_Agents_Mcp_McpNamedPipeConnectionResult_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_AI_Agents_Mcp_McpNamedPipeConnectionResult[] = L"Windows.AI.Agents.Mcp.McpNamedPipeConnectionResult";
#endif
#endif // WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Class Windows.AI.Agents.Mcp.McpResources
 *
 * Introduced to Windows.AI.Agents.AgentsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Windows.AI.Agents.Mcp.IMcpResourcesStatics interface starting with version 1.0 of the Windows.AI.Agents.AgentsContract API contract
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_AI_Agents_Mcp_McpResources_DEFINED
#define RUNTIMECLASS_Windows_AI_Agents_Mcp_McpResources_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_AI_Agents_Mcp_McpResources[] = L"Windows.AI.Agents.Mcp.McpResources";
#endif
#endif // WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Class Windows.AI.Agents.Mcp.McpServerContext
 *
 * Introduced to Windows.AI.Agents.AgentsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Windows.AI.Agents.Mcp.IMcpServerContextStatics interface starting with version 1.0 of the Windows.AI.Agents.AgentsContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.AI.Agents.Mcp.IMcpServerContext ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_AI_Agents_Mcp_McpServerContext_DEFINED
#define RUNTIMECLASS_Windows_AI_Agents_Mcp_McpServerContext_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_AI_Agents_Mcp_McpServerContext[] = L"Windows.AI.Agents.Mcp.McpServerContext";
#endif
#endif // WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Class Windows.AI.Agents.Mcp.McpServerInfo
 *
 * Introduced to Windows.AI.Agents.AgentsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Class implements the following interfaces:
 *    Windows.AI.Agents.Mcp.IMcpServerInfo ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_AI_Agents_Mcp_McpServerInfo_DEFINED
#define RUNTIMECLASS_Windows_AI_Agents_Mcp_McpServerInfo_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_AI_Agents_Mcp_McpServerInfo[] = L"Windows.AI.Agents.Mcp.McpServerInfo";
#endif
#endif // WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Class Windows.AI.Agents.Mcp.McpServerRegistry
 *
 * Introduced to Windows.AI.Agents.AgentsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Windows.AI.Agents.Mcp.IMcpServerRegistryStatics interface starting with version 1.0 of the Windows.AI.Agents.AgentsContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.AI.Agents.Mcp.IMcpServerRegistry ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_AI_Agents_Mcp_McpServerRegistry_DEFINED
#define RUNTIMECLASS_Windows_AI_Agents_Mcp_McpServerRegistry_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_AI_Agents_Mcp_McpServerRegistry[] = L"Windows.AI.Agents.Mcp.McpServerRegistry";
#endif
#endif // WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Class Windows.AI.Agents.Mcp.McpStdioConnectionInfo
 *
 * Introduced to Windows.AI.Agents.AgentsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Class implements the following interfaces:
 *    Windows.AI.Agents.Mcp.IMcpStdioConnectionInfo ** Default Interface **
 *    Windows.Foundation.IClosable
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_AI_Agents_Mcp_McpStdioConnectionInfo_DEFINED
#define RUNTIMECLASS_Windows_AI_Agents_Mcp_McpStdioConnectionInfo_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_AI_Agents_Mcp_McpStdioConnectionInfo[] = L"Windows.AI.Agents.Mcp.McpStdioConnectionInfo";
#endif
#endif // WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

#else // !defined(__cplusplus)
/* Forward Declarations */
#ifndef ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpHttpConnectionResult_FWD_DEFINED__
#define ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpHttpConnectionResult_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpHttpConnectionResult __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpHttpConnectionResult;

#endif // ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpHttpConnectionResult_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpMessageFilter_FWD_DEFINED__
#define ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpMessageFilter_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpMessageFilter __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpMessageFilter;

#endif // ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpMessageFilter_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpMessageFilterResponse_FWD_DEFINED__
#define ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpMessageFilterResponse_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpMessageFilterResponse __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpMessageFilterResponse;

#endif // ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpMessageFilterResponse_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpNamedPipeConnectionResult_FWD_DEFINED__
#define ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpNamedPipeConnectionResult_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpNamedPipeConnectionResult __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpNamedPipeConnectionResult;

#endif // ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpNamedPipeConnectionResult_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpNamedPipeConnectionServer_FWD_DEFINED__
#define ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpNamedPipeConnectionServer_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpNamedPipeConnectionServer __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpNamedPipeConnectionServer;

#endif // ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpNamedPipeConnectionServer_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpResourcesStatics_FWD_DEFINED__
#define ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpResourcesStatics_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpResourcesStatics __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpResourcesStatics;

#endif // ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpResourcesStatics_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerContext_FWD_DEFINED__
#define ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerContext_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerContext __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerContext;

#endif // ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerContext_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerContextStatics_FWD_DEFINED__
#define ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerContextStatics_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerContextStatics __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerContextStatics;

#endif // ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerContextStatics_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerInfo_FWD_DEFINED__
#define ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerInfo_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerInfo __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerInfo;

#endif // ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerInfo_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerRegistry_FWD_DEFINED__
#define ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerRegistry_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerRegistry __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerRegistry;

#endif // ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerRegistry_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerRegistryStatics_FWD_DEFINED__
#define ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerRegistryStatics_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerRegistryStatics __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerRegistryStatics;

#endif // ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerRegistryStatics_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpSseConnectionServer_FWD_DEFINED__
#define ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpSseConnectionServer_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpSseConnectionServer __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpSseConnectionServer;

#endif // ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpSseConnectionServer_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpStdioConnectionInfo_FWD_DEFINED__
#define ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpStdioConnectionInfo_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpStdioConnectionInfo __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpStdioConnectionInfo;

#endif // ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpStdioConnectionInfo_FWD_DEFINED__

// Parameterized interface forward declarations (C)

// Collection interface definitions

#ifndef ____x_ABI_CWindows_CApplicationModel_CIPackage_FWD_DEFINED__
#define ____x_ABI_CWindows_CApplicationModel_CIPackage_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CApplicationModel_CIPackage __x_ABI_CWindows_CApplicationModel_CIPackage;

#endif // ____x_ABI_CWindows_CApplicationModel_CIPackage_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CFoundation_CCollections_CIPropertySet_FWD_DEFINED__
#define ____x_ABI_CWindows_CFoundation_CCollections_CIPropertySet_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CFoundation_CCollections_CIPropertySet __x_ABI_CWindows_CFoundation_CCollections_CIPropertySet;

#endif // ____x_ABI_CWindows_CFoundation_CCollections_CIPropertySet_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CFoundation_CIClosable_FWD_DEFINED__
#define ____x_ABI_CWindows_CFoundation_CIClosable_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CFoundation_CIClosable __x_ABI_CWindows_CFoundation_CIClosable;

#endif // ____x_ABI_CWindows_CFoundation_CIClosable_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CFoundation_CIUriRuntimeClass_FWD_DEFINED__
#define ____x_ABI_CWindows_CFoundation_CIUriRuntimeClass_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CFoundation_CIUriRuntimeClass __x_ABI_CWindows_CFoundation_CIUriRuntimeClass;

#endif // ____x_ABI_CWindows_CFoundation_CIUriRuntimeClass_FWD_DEFINED__

typedef struct __x_ABI_CWindows_CUI_CWindowId __x_ABI_CWindows_CUI_CWindowId;

typedef enum __x_ABI_CWindows_CAI_CAgents_CMcp_CMcpAuthorizationResponse __x_ABI_CWindows_CAI_CAgents_CMcp_CMcpAuthorizationResponse;

typedef enum __x_ABI_CWindows_CAI_CAgents_CMcp_CMcpMessageAction __x_ABI_CWindows_CAI_CAgents_CMcp_CMcpMessageAction;

typedef enum __x_ABI_CWindows_CAI_CAgents_CMcp_CMcpMessageDirection __x_ABI_CWindows_CAI_CAgents_CMcp_CMcpMessageDirection;

/*
 *
 * Struct Windows.AI.Agents.Mcp.McpAuthorizationResponse
 *
 * Introduced to Windows.AI.Agents.AgentsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x10000
enum __x_ABI_CWindows_CAI_CAgents_CMcp_CMcpAuthorizationResponse
{
    McpAuthorizationResponse_Denied = 0,
    McpAuthorizationResponse_Approved = 1,
};
#endif // WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Struct Windows.AI.Agents.Mcp.McpMessageAction
 *
 * Introduced to Windows.AI.Agents.AgentsContract in version 2.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x20000
enum __x_ABI_CWindows_CAI_CAgents_CMcp_CMcpMessageAction
{
    McpMessageAction_Allow = 0,
    McpMessageAction_Block = 1,
};
#endif // WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x20000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Struct Windows.AI.Agents.Mcp.McpMessageDirection
 *
 * Introduced to Windows.AI.Agents.AgentsContract in version 2.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x20000
enum __x_ABI_CWindows_CAI_CAgents_CMcp_CMcpMessageDirection
{
    McpMessageDirection_Request = 0,
    McpMessageDirection_Response = 1,
};
#endif // WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x20000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Interface Windows.AI.Agents.Mcp.IMcpHttpConnectionResult
 *
 * Introduced to Windows.AI.Agents.AgentsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Interface is a part of the implementation of type Windows.AI.Agents.Mcp.McpHttpConnectionResult
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpHttpConnectionResult_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpHttpConnectionResult_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_AI_Agents_Mcp_IMcpHttpConnectionResult[] = L"Windows.AI.Agents.Mcp.IMcpHttpConnectionResult";
typedef struct __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpHttpConnectionResultVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpHttpConnectionResult* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpHttpConnectionResult* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpHttpConnectionResult* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpHttpConnectionResult* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpHttpConnectionResult* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpHttpConnectionResult* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Uri)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpHttpConnectionResult* This,
        __x_ABI_CWindows_CFoundation_CIUriRuntimeClass** value);
    HRESULT (STDMETHODCALLTYPE* put_Uri)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpHttpConnectionResult* This,
        __x_ABI_CWindows_CFoundation_CIUriRuntimeClass* value);
    HRESULT (STDMETHODCALLTYPE* get_Headers)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpHttpConnectionResult* This,
        __x_ABI_CWindows_CFoundation_CCollections_CIPropertySet** value);

    END_INTERFACE
} __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpHttpConnectionResultVtbl;

interface __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpHttpConnectionResult
{
    CONST_VTBL struct __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpHttpConnectionResultVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpHttpConnectionResult_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpHttpConnectionResult_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpHttpConnectionResult_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpHttpConnectionResult_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpHttpConnectionResult_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpHttpConnectionResult_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpHttpConnectionResult_get_Uri(This, value) \
    ((This)->lpVtbl->get_Uri(This, value))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpHttpConnectionResult_put_Uri(This, value) \
    ((This)->lpVtbl->put_Uri(This, value))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpHttpConnectionResult_get_Headers(This, value) \
    ((This)->lpVtbl->get_Headers(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpHttpConnectionResult;
#endif /* !defined(____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpHttpConnectionResult_INTERFACE_DEFINED__) */
#endif // WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Interface Windows.AI.Agents.Mcp.IMcpMessageFilter
 *
 * Introduced to Windows.AI.Agents.AgentsContract in version 2.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x20000
#if !defined(____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpMessageFilter_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpMessageFilter_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_AI_Agents_Mcp_IMcpMessageFilter[] = L"Windows.AI.Agents.Mcp.IMcpMessageFilter";
typedef struct __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpMessageFilterVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpMessageFilter* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpMessageFilter* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpMessageFilter* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpMessageFilter* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpMessageFilter* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpMessageFilter* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* Initialize)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpMessageFilter* This,
        HSTRING clientAppUserModelId,
        HSTRING serverPackageFamilyName,
        HSTRING serverId);
    HRESULT (STDMETHODCALLTYPE* OnMessage)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpMessageFilter* This,
        HSTRING message,
        enum __x_ABI_CWindows_CAI_CAgents_CMcp_CMcpMessageDirection direction,
        __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpMessageFilterResponse* filterResponse);

    END_INTERFACE
} __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpMessageFilterVtbl;

interface __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpMessageFilter
{
    CONST_VTBL struct __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpMessageFilterVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpMessageFilter_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpMessageFilter_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpMessageFilter_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpMessageFilter_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpMessageFilter_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpMessageFilter_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpMessageFilter_Initialize(This, clientAppUserModelId, serverPackageFamilyName, serverId) \
    ((This)->lpVtbl->Initialize(This, clientAppUserModelId, serverPackageFamilyName, serverId))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpMessageFilter_OnMessage(This, message, direction, filterResponse) \
    ((This)->lpVtbl->OnMessage(This, message, direction, filterResponse))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpMessageFilter;
#endif /* !defined(____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpMessageFilter_INTERFACE_DEFINED__) */
#endif // WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x20000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Interface Windows.AI.Agents.Mcp.IMcpMessageFilterResponse
 *
 * Introduced to Windows.AI.Agents.AgentsContract in version 2.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Interface is a part of the implementation of type Windows.AI.Agents.Mcp.McpMessageFilterResponse
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x20000
#if !defined(____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpMessageFilterResponse_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpMessageFilterResponse_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_AI_Agents_Mcp_IMcpMessageFilterResponse[] = L"Windows.AI.Agents.Mcp.IMcpMessageFilterResponse";
typedef struct __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpMessageFilterResponseVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpMessageFilterResponse* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpMessageFilterResponse* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpMessageFilterResponse* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpMessageFilterResponse* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpMessageFilterResponse* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpMessageFilterResponse* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_MessageAction)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpMessageFilterResponse* This,
        enum __x_ABI_CWindows_CAI_CAgents_CMcp_CMcpMessageAction* value);
    HRESULT (STDMETHODCALLTYPE* put_MessageAction)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpMessageFilterResponse* This,
        enum __x_ABI_CWindows_CAI_CAgents_CMcp_CMcpMessageAction value);

    END_INTERFACE
} __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpMessageFilterResponseVtbl;

interface __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpMessageFilterResponse
{
    CONST_VTBL struct __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpMessageFilterResponseVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpMessageFilterResponse_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpMessageFilterResponse_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpMessageFilterResponse_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpMessageFilterResponse_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpMessageFilterResponse_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpMessageFilterResponse_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpMessageFilterResponse_get_MessageAction(This, value) \
    ((This)->lpVtbl->get_MessageAction(This, value))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpMessageFilterResponse_put_MessageAction(This, value) \
    ((This)->lpVtbl->put_MessageAction(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpMessageFilterResponse;
#endif /* !defined(____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpMessageFilterResponse_INTERFACE_DEFINED__) */
#endif // WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x20000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Interface Windows.AI.Agents.Mcp.IMcpNamedPipeConnectionResult
 *
 * Introduced to Windows.AI.Agents.AgentsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Interface is a part of the implementation of type Windows.AI.Agents.Mcp.McpNamedPipeConnectionResult
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpNamedPipeConnectionResult_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpNamedPipeConnectionResult_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_AI_Agents_Mcp_IMcpNamedPipeConnectionResult[] = L"Windows.AI.Agents.Mcp.IMcpNamedPipeConnectionResult";
typedef struct __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpNamedPipeConnectionResultVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpNamedPipeConnectionResult* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpNamedPipeConnectionResult* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpNamedPipeConnectionResult* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpNamedPipeConnectionResult* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpNamedPipeConnectionResult* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpNamedPipeConnectionResult* This,
        TrustLevel* trustLevel);

    END_INTERFACE
} __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpNamedPipeConnectionResultVtbl;

interface __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpNamedPipeConnectionResult
{
    CONST_VTBL struct __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpNamedPipeConnectionResultVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpNamedPipeConnectionResult_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpNamedPipeConnectionResult_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpNamedPipeConnectionResult_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpNamedPipeConnectionResult_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpNamedPipeConnectionResult_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpNamedPipeConnectionResult_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpNamedPipeConnectionResult;
#endif /* !defined(____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpNamedPipeConnectionResult_INTERFACE_DEFINED__) */
#endif // WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Interface Windows.AI.Agents.Mcp.IMcpNamedPipeConnectionServer
 *
 * Introduced to Windows.AI.Agents.AgentsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpNamedPipeConnectionServer_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpNamedPipeConnectionServer_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_AI_Agents_Mcp_IMcpNamedPipeConnectionServer[] = L"Windows.AI.Agents.Mcp.IMcpNamedPipeConnectionServer";
typedef struct __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpNamedPipeConnectionServerVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpNamedPipeConnectionServer* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpNamedPipeConnectionServer* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpNamedPipeConnectionServer* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpNamedPipeConnectionServer* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpNamedPipeConnectionServer* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpNamedPipeConnectionServer* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* Connect)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpNamedPipeConnectionServer* This,
        __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerContext* hostContext,
        HSTRING pipeName,
        __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpNamedPipeConnectionResult* connectionResult);

    END_INTERFACE
} __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpNamedPipeConnectionServerVtbl;

interface __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpNamedPipeConnectionServer
{
    CONST_VTBL struct __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpNamedPipeConnectionServerVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpNamedPipeConnectionServer_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpNamedPipeConnectionServer_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpNamedPipeConnectionServer_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpNamedPipeConnectionServer_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpNamedPipeConnectionServer_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpNamedPipeConnectionServer_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpNamedPipeConnectionServer_Connect(This, hostContext, pipeName, connectionResult) \
    ((This)->lpVtbl->Connect(This, hostContext, pipeName, connectionResult))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpNamedPipeConnectionServer;
#endif /* !defined(____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpNamedPipeConnectionServer_INTERFACE_DEFINED__) */
#endif // WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Interface Windows.AI.Agents.Mcp.IMcpResourcesStatics
 *
 * Introduced to Windows.AI.Agents.AgentsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Interface is a part of the implementation of type Windows.AI.Agents.Mcp.McpResources
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpResourcesStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpResourcesStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_AI_Agents_Mcp_IMcpResourcesStatics[] = L"Windows.AI.Agents.Mcp.IMcpResourcesStatics";
typedef struct __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpResourcesStaticsVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpResourcesStatics* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpResourcesStatics* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpResourcesStatics* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpResourcesStatics* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpResourcesStatics* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpResourcesStatics* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_FileSystemRead)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpResourcesStatics* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* get_FileSystemWrite)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpResourcesStatics* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* get_FileSystemDelete)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpResourcesStatics* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* get_FileSystemCreate)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpResourcesStatics* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* get_HttpGet)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpResourcesStatics* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* get_HttpPost)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpResourcesStatics* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* get_HttpPut)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpResourcesStatics* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* get_HttpDelete)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpResourcesStatics* This,
        HSTRING* value);

    END_INTERFACE
} __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpResourcesStaticsVtbl;

interface __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpResourcesStatics
{
    CONST_VTBL struct __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpResourcesStaticsVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpResourcesStatics_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpResourcesStatics_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpResourcesStatics_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpResourcesStatics_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpResourcesStatics_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpResourcesStatics_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpResourcesStatics_get_FileSystemRead(This, value) \
    ((This)->lpVtbl->get_FileSystemRead(This, value))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpResourcesStatics_get_FileSystemWrite(This, value) \
    ((This)->lpVtbl->get_FileSystemWrite(This, value))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpResourcesStatics_get_FileSystemDelete(This, value) \
    ((This)->lpVtbl->get_FileSystemDelete(This, value))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpResourcesStatics_get_FileSystemCreate(This, value) \
    ((This)->lpVtbl->get_FileSystemCreate(This, value))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpResourcesStatics_get_HttpGet(This, value) \
    ((This)->lpVtbl->get_HttpGet(This, value))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpResourcesStatics_get_HttpPost(This, value) \
    ((This)->lpVtbl->get_HttpPost(This, value))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpResourcesStatics_get_HttpPut(This, value) \
    ((This)->lpVtbl->get_HttpPut(This, value))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpResourcesStatics_get_HttpDelete(This, value) \
    ((This)->lpVtbl->get_HttpDelete(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpResourcesStatics;
#endif /* !defined(____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpResourcesStatics_INTERFACE_DEFINED__) */
#endif // WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Interface Windows.AI.Agents.Mcp.IMcpServerContext
 *
 * Introduced to Windows.AI.Agents.AgentsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Interface is a part of the implementation of type Windows.AI.Agents.Mcp.McpServerContext
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerContext_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerContext_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_AI_Agents_Mcp_IMcpServerContext[] = L"Windows.AI.Agents.Mcp.IMcpServerContext";
typedef struct __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerContextVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerContext* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerContext* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerContext* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerContext* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerContext* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerContext* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_AppId)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerContext* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* RequestResourceAccess)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerContext* This,
        __x_ABI_CWindows_CFoundation_CIUriRuntimeClass* resource,
        HSTRING description,
        HSTRING reasonForAsking,
        enum __x_ABI_CWindows_CAI_CAgents_CMcp_CMcpAuthorizationResponse* result);

    END_INTERFACE
} __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerContextVtbl;

interface __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerContext
{
    CONST_VTBL struct __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerContextVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerContext_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerContext_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerContext_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerContext_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerContext_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerContext_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerContext_get_AppId(This, value) \
    ((This)->lpVtbl->get_AppId(This, value))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerContext_RequestResourceAccess(This, resource, description, reasonForAsking, result) \
    ((This)->lpVtbl->RequestResourceAccess(This, resource, description, reasonForAsking, result))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerContext;
#endif /* !defined(____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerContext_INTERFACE_DEFINED__) */
#endif // WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Interface Windows.AI.Agents.Mcp.IMcpServerContextStatics
 *
 * Introduced to Windows.AI.Agents.AgentsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Interface is a part of the implementation of type Windows.AI.Agents.Mcp.McpServerContext
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerContextStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerContextStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_AI_Agents_Mcp_IMcpServerContextStatics[] = L"Windows.AI.Agents.Mcp.IMcpServerContextStatics";
typedef struct __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerContextStaticsVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerContextStatics* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerContextStatics* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerContextStatics* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerContextStatics* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerContextStatics* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerContextStatics* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* GetContextForCaller)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerContextStatics* This,
        __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerContext** result);

    END_INTERFACE
} __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerContextStaticsVtbl;

interface __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerContextStatics
{
    CONST_VTBL struct __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerContextStaticsVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerContextStatics_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerContextStatics_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerContextStatics_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerContextStatics_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerContextStatics_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerContextStatics_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerContextStatics_GetContextForCaller(This, result) \
    ((This)->lpVtbl->GetContextForCaller(This, result))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerContextStatics;
#endif /* !defined(____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerContextStatics_INTERFACE_DEFINED__) */
#endif // WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Interface Windows.AI.Agents.Mcp.IMcpServerInfo
 *
 * Introduced to Windows.AI.Agents.AgentsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Interface is a part of the implementation of type Windows.AI.Agents.Mcp.McpServerInfo
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerInfo_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerInfo_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_AI_Agents_Mcp_IMcpServerInfo[] = L"Windows.AI.Agents.Mcp.IMcpServerInfo";
typedef struct __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerInfoVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerInfo* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerInfo* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerInfo* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerInfo* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerInfo* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerInfo* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Id)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerInfo* This,
        GUID* value);
    HRESULT (STDMETHODCALLTYPE* get_Name)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerInfo* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* get_Description)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerInfo* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* get_Package)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerInfo* This,
        __x_ABI_CWindows_CApplicationModel_CIPackage** value);
    HRESULT (STDMETHODCALLTYPE* get_DisplayName)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerInfo* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* get_AppUserModelId)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerInfo* This,
        HSTRING* value);

    END_INTERFACE
} __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerInfoVtbl;

interface __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerInfo
{
    CONST_VTBL struct __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerInfoVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerInfo_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerInfo_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerInfo_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerInfo_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerInfo_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerInfo_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerInfo_get_Id(This, value) \
    ((This)->lpVtbl->get_Id(This, value))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerInfo_get_Name(This, value) \
    ((This)->lpVtbl->get_Name(This, value))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerInfo_get_Description(This, value) \
    ((This)->lpVtbl->get_Description(This, value))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerInfo_get_Package(This, value) \
    ((This)->lpVtbl->get_Package(This, value))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerInfo_get_DisplayName(This, value) \
    ((This)->lpVtbl->get_DisplayName(This, value))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerInfo_get_AppUserModelId(This, value) \
    ((This)->lpVtbl->get_AppUserModelId(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerInfo;
#endif /* !defined(____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerInfo_INTERFACE_DEFINED__) */
#endif // WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Interface Windows.AI.Agents.Mcp.IMcpServerRegistry
 *
 * Introduced to Windows.AI.Agents.AgentsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Interface is a part of the implementation of type Windows.AI.Agents.Mcp.McpServerRegistry
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerRegistry_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerRegistry_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_AI_Agents_Mcp_IMcpServerRegistry[] = L"Windows.AI.Agents.Mcp.IMcpServerRegistry";
typedef struct __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerRegistryVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerRegistry* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerRegistry* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerRegistry* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerRegistry* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerRegistry* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerRegistry* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* GetMcpServerInfos)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerRegistry* This,
        UINT32* resultLength,
        __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerInfo*** result);
    HRESULT (STDMETHODCALLTYPE* GetMcpConnectionInfo)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerRegistry* This,
        GUID mcpServerId,
        struct __x_ABI_CWindows_CUI_CWindowId ownerWindowId,
        __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpStdioConnectionInfo** result);

    END_INTERFACE
} __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerRegistryVtbl;

interface __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerRegistry
{
    CONST_VTBL struct __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerRegistryVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerRegistry_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerRegistry_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerRegistry_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerRegistry_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerRegistry_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerRegistry_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerRegistry_GetMcpServerInfos(This, resultLength, result) \
    ((This)->lpVtbl->GetMcpServerInfos(This, resultLength, result))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerRegistry_GetMcpConnectionInfo(This, mcpServerId, ownerWindowId, result) \
    ((This)->lpVtbl->GetMcpConnectionInfo(This, mcpServerId, ownerWindowId, result))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerRegistry;
#endif /* !defined(____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerRegistry_INTERFACE_DEFINED__) */
#endif // WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Interface Windows.AI.Agents.Mcp.IMcpServerRegistryStatics
 *
 * Introduced to Windows.AI.Agents.AgentsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Interface is a part of the implementation of type Windows.AI.Agents.Mcp.McpServerRegistry
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerRegistryStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerRegistryStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_AI_Agents_Mcp_IMcpServerRegistryStatics[] = L"Windows.AI.Agents.Mcp.IMcpServerRegistryStatics";
typedef struct __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerRegistryStaticsVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerRegistryStatics* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerRegistryStatics* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerRegistryStatics* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerRegistryStatics* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerRegistryStatics* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerRegistryStatics* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* GetDefault)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerRegistryStatics* This,
        __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerRegistry** result);

    END_INTERFACE
} __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerRegistryStaticsVtbl;

interface __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerRegistryStatics
{
    CONST_VTBL struct __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerRegistryStaticsVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerRegistryStatics_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerRegistryStatics_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerRegistryStatics_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerRegistryStatics_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerRegistryStatics_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerRegistryStatics_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerRegistryStatics_GetDefault(This, result) \
    ((This)->lpVtbl->GetDefault(This, result))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerRegistryStatics;
#endif /* !defined(____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerRegistryStatics_INTERFACE_DEFINED__) */
#endif // WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Interface Windows.AI.Agents.Mcp.IMcpSseConnectionServer
 *
 * Introduced to Windows.AI.Agents.AgentsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpSseConnectionServer_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpSseConnectionServer_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_AI_Agents_Mcp_IMcpSseConnectionServer[] = L"Windows.AI.Agents.Mcp.IMcpSseConnectionServer";
typedef struct __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpSseConnectionServerVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpSseConnectionServer* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpSseConnectionServer* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpSseConnectionServer* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpSseConnectionServer* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpSseConnectionServer* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpSseConnectionServer* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* Connect)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpSseConnectionServer* This,
        __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerContext* hostContext,
        __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpHttpConnectionResult* connectionResult);

    END_INTERFACE
} __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpSseConnectionServerVtbl;

interface __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpSseConnectionServer
{
    CONST_VTBL struct __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpSseConnectionServerVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpSseConnectionServer_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpSseConnectionServer_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpSseConnectionServer_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpSseConnectionServer_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpSseConnectionServer_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpSseConnectionServer_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpSseConnectionServer_Connect(This, hostContext, connectionResult) \
    ((This)->lpVtbl->Connect(This, hostContext, connectionResult))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpSseConnectionServer;
#endif /* !defined(____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpSseConnectionServer_INTERFACE_DEFINED__) */
#endif // WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Interface Windows.AI.Agents.Mcp.IMcpStdioConnectionInfo
 *
 * Introduced to Windows.AI.Agents.AgentsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Interface is a part of the implementation of type Windows.AI.Agents.Mcp.McpStdioConnectionInfo
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpStdioConnectionInfo_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpStdioConnectionInfo_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_AI_Agents_Mcp_IMcpStdioConnectionInfo[] = L"Windows.AI.Agents.Mcp.IMcpStdioConnectionInfo";
typedef struct __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpStdioConnectionInfoVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpStdioConnectionInfo* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpStdioConnectionInfo* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpStdioConnectionInfo* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpStdioConnectionInfo* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpStdioConnectionInfo* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpStdioConnectionInfo* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Command)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpStdioConnectionInfo* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* GetCommandArguments)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpStdioConnectionInfo* This,
        UINT32* resultLength,
        HSTRING** result);
    HRESULT (STDMETHODCALLTYPE* get_Info)(__x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpStdioConnectionInfo* This,
        __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpServerInfo** value);

    END_INTERFACE
} __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpStdioConnectionInfoVtbl;

interface __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpStdioConnectionInfo
{
    CONST_VTBL struct __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpStdioConnectionInfoVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpStdioConnectionInfo_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpStdioConnectionInfo_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpStdioConnectionInfo_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpStdioConnectionInfo_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpStdioConnectionInfo_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpStdioConnectionInfo_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpStdioConnectionInfo_get_Command(This, value) \
    ((This)->lpVtbl->get_Command(This, value))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpStdioConnectionInfo_GetCommandArguments(This, resultLength, result) \
    ((This)->lpVtbl->GetCommandArguments(This, resultLength, result))

#define __x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpStdioConnectionInfo_get_Info(This, value) \
    ((This)->lpVtbl->get_Info(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpStdioConnectionInfo;
#endif /* !defined(____x_ABI_CWindows_CAI_CAgents_CMcp_CIMcpStdioConnectionInfo_INTERFACE_DEFINED__) */
#endif // WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Class Windows.AI.Agents.Mcp.McpHttpConnectionResult
 *
 * Introduced to Windows.AI.Agents.AgentsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Class implements the following interfaces:
 *    Windows.AI.Agents.Mcp.IMcpHttpConnectionResult ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_AI_Agents_Mcp_McpHttpConnectionResult_DEFINED
#define RUNTIMECLASS_Windows_AI_Agents_Mcp_McpHttpConnectionResult_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_AI_Agents_Mcp_McpHttpConnectionResult[] = L"Windows.AI.Agents.Mcp.McpHttpConnectionResult";
#endif
#endif // WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Class Windows.AI.Agents.Mcp.McpMessageFilterResponse
 *
 * Introduced to Windows.AI.Agents.AgentsContract in version 2.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Class implements the following interfaces:
 *    Windows.AI.Agents.Mcp.IMcpMessageFilterResponse ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x20000
#ifndef RUNTIMECLASS_Windows_AI_Agents_Mcp_McpMessageFilterResponse_DEFINED
#define RUNTIMECLASS_Windows_AI_Agents_Mcp_McpMessageFilterResponse_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_AI_Agents_Mcp_McpMessageFilterResponse[] = L"Windows.AI.Agents.Mcp.McpMessageFilterResponse";
#endif
#endif // WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x20000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Class Windows.AI.Agents.Mcp.McpNamedPipeConnectionResult
 *
 * Introduced to Windows.AI.Agents.AgentsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Class implements the following interfaces:
 *    Windows.AI.Agents.Mcp.IMcpNamedPipeConnectionResult ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_AI_Agents_Mcp_McpNamedPipeConnectionResult_DEFINED
#define RUNTIMECLASS_Windows_AI_Agents_Mcp_McpNamedPipeConnectionResult_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_AI_Agents_Mcp_McpNamedPipeConnectionResult[] = L"Windows.AI.Agents.Mcp.McpNamedPipeConnectionResult";
#endif
#endif // WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Class Windows.AI.Agents.Mcp.McpResources
 *
 * Introduced to Windows.AI.Agents.AgentsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Windows.AI.Agents.Mcp.IMcpResourcesStatics interface starting with version 1.0 of the Windows.AI.Agents.AgentsContract API contract
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_AI_Agents_Mcp_McpResources_DEFINED
#define RUNTIMECLASS_Windows_AI_Agents_Mcp_McpResources_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_AI_Agents_Mcp_McpResources[] = L"Windows.AI.Agents.Mcp.McpResources";
#endif
#endif // WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Class Windows.AI.Agents.Mcp.McpServerContext
 *
 * Introduced to Windows.AI.Agents.AgentsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Windows.AI.Agents.Mcp.IMcpServerContextStatics interface starting with version 1.0 of the Windows.AI.Agents.AgentsContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.AI.Agents.Mcp.IMcpServerContext ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_AI_Agents_Mcp_McpServerContext_DEFINED
#define RUNTIMECLASS_Windows_AI_Agents_Mcp_McpServerContext_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_AI_Agents_Mcp_McpServerContext[] = L"Windows.AI.Agents.Mcp.McpServerContext";
#endif
#endif // WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Class Windows.AI.Agents.Mcp.McpServerInfo
 *
 * Introduced to Windows.AI.Agents.AgentsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Class implements the following interfaces:
 *    Windows.AI.Agents.Mcp.IMcpServerInfo ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_AI_Agents_Mcp_McpServerInfo_DEFINED
#define RUNTIMECLASS_Windows_AI_Agents_Mcp_McpServerInfo_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_AI_Agents_Mcp_McpServerInfo[] = L"Windows.AI.Agents.Mcp.McpServerInfo";
#endif
#endif // WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Class Windows.AI.Agents.Mcp.McpServerRegistry
 *
 * Introduced to Windows.AI.Agents.AgentsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Windows.AI.Agents.Mcp.IMcpServerRegistryStatics interface starting with version 1.0 of the Windows.AI.Agents.AgentsContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.AI.Agents.Mcp.IMcpServerRegistry ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_AI_Agents_Mcp_McpServerRegistry_DEFINED
#define RUNTIMECLASS_Windows_AI_Agents_Mcp_McpServerRegistry_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_AI_Agents_Mcp_McpServerRegistry[] = L"Windows.AI.Agents.Mcp.McpServerRegistry";
#endif
#endif // WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

/*
 *
 * Class Windows.AI.Agents.Mcp.McpStdioConnectionInfo
 *
 * Introduced to Windows.AI.Agents.AgentsContract in version 1.0
 *
 * Type is for evaluation purposes and is subject to change or removal in future updates.
 *
 * Class implements the following interfaces:
 *    Windows.AI.Agents.Mcp.IMcpStdioConnectionInfo ** Default Interface **
 *    Windows.Foundation.IClosable
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)
#if WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_AI_Agents_Mcp_McpStdioConnectionInfo_DEFINED
#define RUNTIMECLASS_Windows_AI_Agents_Mcp_McpStdioConnectionInfo_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_AI_Agents_Mcp_McpStdioConnectionInfo[] = L"Windows.AI.Agents.Mcp.McpStdioConnectionInfo";
#endif
#endif // WINDOWS_AI_AGENTS_AGENTSCONTRACT_VERSION >= 0x10000
#endif // defined(ENABLE_WINRT_EXPERIMENTAL_TYPES)

#endif // defined(__cplusplus)
#pragma pop_macro("MIDL_CONST_ID")
// Restore the original value of the 'DEPRECATED' macro
#pragma pop_macro("DEPRECATED")

#ifdef __clang__
#pragma clang diagnostic pop // deprecated-declarations
#else
#pragma warning(pop)
#endif
#endif // __windows2Eai2Eagents2Emcp_p_h__

#endif // __windows2Eai2Eagents2Emcp_h__
