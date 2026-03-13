
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
#ifndef __windows2Emanagement2Eupdate2Ecluster_h__
#define __windows2Emanagement2Eupdate2Ecluster_h__
#ifndef __windows2Emanagement2Eupdate2Ecluster_p_h__
#define __windows2Emanagement2Eupdate2Ecluster_p_h__


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
#define WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION 0x140000
#endif // defined(WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION)

#if !defined(WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION)
#define WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION 0x10000
#endif // defined(WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION)

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
#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAcquireEnvironmentInfoResult_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAcquireEnvironmentInfoResult_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    interface IAcquireEnvironmentInfoResult;
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAcquireEnvironmentInfoResult ABI::Windows::Management::Update::Cluster::IAcquireEnvironmentInfoResult

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAcquireEnvironmentInfoResult_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAcquireEnvironmentInfoResultFactory_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAcquireEnvironmentInfoResultFactory_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    interface IAcquireEnvironmentInfoResultFactory;
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAcquireEnvironmentInfoResultFactory ABI::Windows::Management::Update::Cluster::IAcquireEnvironmentInfoResultFactory

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAcquireEnvironmentInfoResultFactory_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAreRebootsPendingResult_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAreRebootsPendingResult_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    interface IAreRebootsPendingResult;
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAreRebootsPendingResult ABI::Windows::Management::Update::Cluster::IAreRebootsPendingResult

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAreRebootsPendingResult_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAreRebootsPendingResultFactory_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAreRebootsPendingResultFactory_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    interface IAreRebootsPendingResultFactory;
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAreRebootsPendingResultFactory ABI::Windows::Management::Update::Cluster::IAreRebootsPendingResultFactory

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAreRebootsPendingResultFactory_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperations_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperations_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    interface IClusterNativeEnvironmentOperations;
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperations ABI::Windows::Management::Update::Cluster::IClusterNativeEnvironmentOperations

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperations_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperationsPlugin_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperationsPlugin_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    interface IClusterNativeEnvironmentOperationsPlugin;
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperationsPlugin ABI::Windows::Management::Update::Cluster::IClusterNativeEnvironmentOperationsPlugin

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperationsPlugin_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperations_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperations_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    interface IClusterNativeNodeOperations;
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperations ABI::Windows::Management::Update::Cluster::IClusterNativeNodeOperations

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperations_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperationsPlugin_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperationsPlugin_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    interface IClusterNativeNodeOperationsPlugin;
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperationsPlugin ABI::Windows::Management::Update::Cluster::IClusterNativeNodeOperationsPlugin

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperationsPlugin_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterUpdateServices_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterUpdateServices_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    interface IClusterUpdateServices;
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterUpdateServices ABI::Windows::Management::Update::Cluster::IClusterUpdateServices

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterUpdateServices_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIInstallUpdateTaskResult_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIInstallUpdateTaskResult_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    interface IInstallUpdateTaskResult;
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIInstallUpdateTaskResult ABI::Windows::Management::Update::Cluster::IInstallUpdateTaskResult

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIInstallUpdateTaskResult_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIInstallUpdateTaskResultFactory_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIInstallUpdateTaskResultFactory_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    interface IInstallUpdateTaskResultFactory;
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIInstallUpdateTaskResultFactory ABI::Windows::Management::Update::Cluster::IInstallUpdateTaskResultFactory

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIInstallUpdateTaskResultFactory_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIRollbackUpdateTaskResult_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIRollbackUpdateTaskResult_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    interface IRollbackUpdateTaskResult;
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIRollbackUpdateTaskResult ABI::Windows::Management::Update::Cluster::IRollbackUpdateTaskResult

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIRollbackUpdateTaskResult_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIRollbackUpdateTaskResultFactory_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIRollbackUpdateTaskResultFactory_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    interface IRollbackUpdateTaskResultFactory;
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIRollbackUpdateTaskResultFactory ABI::Windows::Management::Update::Cluster::IRollbackUpdateTaskResultFactory

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIRollbackUpdateTaskResultFactory_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIScanUpdateTaskResult_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIScanUpdateTaskResult_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    interface IScanUpdateTaskResult;
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIScanUpdateTaskResult ABI::Windows::Management::Update::Cluster::IScanUpdateTaskResult

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIScanUpdateTaskResult_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIScanUpdateTaskResultFactory_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIScanUpdateTaskResultFactory_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    interface IScanUpdateTaskResultFactory;
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIScanUpdateTaskResultFactory ABI::Windows::Management::Update::Cluster::IScanUpdateTaskResultFactory

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIScanUpdateTaskResultFactory_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIStageUpdateTaskResult_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIStageUpdateTaskResult_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    interface IStageUpdateTaskResult;
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIStageUpdateTaskResult ABI::Windows::Management::Update::Cluster::IStageUpdateTaskResult

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIStageUpdateTaskResult_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIStageUpdateTaskResultFactory_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIStageUpdateTaskResultFactory_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    interface IStageUpdateTaskResultFactory;
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIStageUpdateTaskResultFactory ABI::Windows::Management::Update::Cluster::IStageUpdateTaskResultFactory

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIStageUpdateTaskResultFactory_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateCredential_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateCredential_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    interface IUpdateCredential;
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateCredential ABI::Windows::Management::Update::Cluster::IUpdateCredential

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateCredential_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateCredentialFactory_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateCredentialFactory_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    interface IUpdateCredentialFactory;
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateCredentialFactory ABI::Windows::Management::Update::Cluster::IUpdateCredentialFactory

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateCredentialFactory_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecord_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecord_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    interface IUpdateInstallRecord;
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecord ABI::Windows::Management::Update::Cluster::IUpdateInstallRecord

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecord_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecordFactory_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecordFactory_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    interface IUpdateInstallRecordFactory;
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecordFactory ABI::Windows::Management::Update::Cluster::IUpdateInstallRecordFactory

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecordFactory_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstaller_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstaller_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    interface IUpdateInstaller;
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstaller ABI::Windows::Management::Update::Cluster::IUpdateInstaller

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstaller_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallerPlugin_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallerPlugin_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    interface IUpdateInstallerPlugin;
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallerPlugin ABI::Windows::Management::Update::Cluster::IUpdateInstallerPlugin

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallerPlugin_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResult_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResult_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    interface IUpdateOperationResult;
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResult ABI::Windows::Management::Update::Cluster::IUpdateOperationResult

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResult_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResultFactory_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResultFactory_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    interface IUpdateOperationResultFactory;
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResultFactory ABI::Windows::Management::Update::Cluster::IUpdateOperationResultFactory

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResultFactory_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResult_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResult_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    interface IUpdatePendingOperationResult;
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResult ABI::Windows::Management::Update::Cluster::IUpdatePendingOperationResult

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResult_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResultFactory_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResultFactory_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    interface IUpdatePendingOperationResultFactory;
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResultFactory ABI::Windows::Management::Update::Cluster::IUpdatePendingOperationResultFactory

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResultFactory_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfo_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfo_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    interface IUpdatePluginVersionInfo;
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfo ABI::Windows::Management::Update::Cluster::IUpdatePluginVersionInfo

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfo_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfoFactory_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfoFactory_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    interface IUpdatePluginVersionInfoFactory;
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfoFactory ABI::Windows::Management::Update::Cluster::IUpdatePluginVersionInfoFactory

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfoFactory_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecord_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecord_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    interface IUpdateRecipeNodeValidationInfoRecord;
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecord ABI::Windows::Management::Update::Cluster::IUpdateRecipeNodeValidationInfoRecord

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecord_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecordFactory_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecordFactory_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    interface IUpdateRecipeNodeValidationInfoRecordFactory;
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecordFactory ABI::Windows::Management::Update::Cluster::IUpdateRecipeNodeValidationInfoRecordFactory

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecordFactory_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecord_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecord_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    interface IUpdateScanRecord;
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecord ABI::Windows::Management::Update::Cluster::IUpdateScanRecord

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecord_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecordFactory_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecordFactory_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    interface IUpdateScanRecordFactory;
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecordFactory ABI::Windows::Management::Update::Cluster::IUpdateScanRecordFactory

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecordFactory_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecord_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecord_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    interface IUpdateStageRecord;
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecord ABI::Windows::Management::Update::Cluster::IUpdateStageRecord

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecord_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecordFactory_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecordFactory_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    interface IUpdateStageRecordFactory;
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecordFactory ABI::Windows::Management::Update::Cluster::IUpdateStageRecordFactory

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecordFactory_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResult_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResult_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    interface IUpdateTaskResult;
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResult ABI::Windows::Management::Update::Cluster::IUpdateTaskResult

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResult_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResultFactory_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResultFactory_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    interface IUpdateTaskResultFactory;
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResultFactory ABI::Windows::Management::Update::Cluster::IUpdateTaskResultFactory

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResultFactory_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessage_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessage_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    interface IUpdateValidationLogMessage;
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessage ABI::Windows::Management::Update::Cluster::IUpdateValidationLogMessage

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessage_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessageFactory_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessageFactory_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    interface IUpdateValidationLogMessageFactory;
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessageFactory ABI::Windows::Management::Update::Cluster::IUpdateValidationLogMessageFactory

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessageFactory_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateAllNodesUpdateRecipeResult_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateAllNodesUpdateRecipeResult_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    interface IValidateAllNodesUpdateRecipeResult;
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateAllNodesUpdateRecipeResult ABI::Windows::Management::Update::Cluster::IValidateAllNodesUpdateRecipeResult

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateAllNodesUpdateRecipeResult_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateAllNodesUpdateRecipeResultFactory_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateAllNodesUpdateRecipeResultFactory_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    interface IValidateAllNodesUpdateRecipeResultFactory;
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateAllNodesUpdateRecipeResultFactory ABI::Windows::Management::Update::Cluster::IValidateAllNodesUpdateRecipeResultFactory

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateAllNodesUpdateRecipeResultFactory_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateClusterEnvironmentResult_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateClusterEnvironmentResult_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    interface IValidateClusterEnvironmentResult;
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateClusterEnvironmentResult ABI::Windows::Management::Update::Cluster::IValidateClusterEnvironmentResult

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateClusterEnvironmentResult_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateClusterEnvironmentResultFactory_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateClusterEnvironmentResultFactory_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    interface IValidateClusterEnvironmentResultFactory;
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateClusterEnvironmentResultFactory ABI::Windows::Management::Update::Cluster::IValidateClusterEnvironmentResultFactory

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateClusterEnvironmentResultFactory_FWD_DEFINED__

// Parameterized interface forward declarations (C++)

// Collection interface definitions

#ifndef DEF___FIKeyValuePair_2_HSTRING_HSTRING_USE
#define DEF___FIKeyValuePair_2_HSTRING_HSTRING_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("60310303-49c5-52e6-abc6-a9b36eccc716"))
IKeyValuePair<HSTRING, HSTRING> : IKeyValuePair_impl<HSTRING, HSTRING>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IKeyValuePair`2<String, String>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IKeyValuePair<HSTRING, HSTRING> __FIKeyValuePair_2_HSTRING_HSTRING_t;
#define __FIKeyValuePair_2_HSTRING_HSTRING ABI::Windows::Foundation::Collections::__FIKeyValuePair_2_HSTRING_HSTRING_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIKeyValuePair_2_HSTRING_HSTRING_USE */



#ifndef DEF___FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRING_USE
#define DEF___FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRING_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("05eb86f1-7140-5517-b88d-cbaebe57e6b1"))
IIterator<__FIKeyValuePair_2_HSTRING_HSTRING*> : IIterator_impl<__FIKeyValuePair_2_HSTRING_HSTRING*>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IIterator`1<Windows.Foundation.Collections.IKeyValuePair`2<String, String>>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterator<__FIKeyValuePair_2_HSTRING_HSTRING*> __FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRING_t;
#define __FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRING ABI::Windows::Foundation::Collections::__FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRING_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRING_USE */



#ifndef DEF___FIIterable_1___FIKeyValuePair_2_HSTRING_HSTRING_USE
#define DEF___FIIterable_1___FIKeyValuePair_2_HSTRING_HSTRING_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("e9bdaaf0-cbf6-5c72-be90-29cbf3a1319b"))
IIterable<__FIKeyValuePair_2_HSTRING_HSTRING*> : IIterable_impl<__FIKeyValuePair_2_HSTRING_HSTRING*>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IIterable`1<Windows.Foundation.Collections.IKeyValuePair`2<String, String>>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterable<__FIKeyValuePair_2_HSTRING_HSTRING*> __FIIterable_1___FIKeyValuePair_2_HSTRING_HSTRING_t;
#define __FIIterable_1___FIKeyValuePair_2_HSTRING_HSTRING ABI::Windows::Foundation::Collections::__FIIterable_1___FIKeyValuePair_2_HSTRING_HSTRING_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterable_1___FIKeyValuePair_2_HSTRING_HSTRING_USE */


namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    class UpdateInstallRecord;
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

#ifndef DEF___FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord_USE
#define DEF___FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("13af2fd6-d049-5d0c-9173-450c4e92691c"))
IIterator<ABI::Windows::Management::Update::Cluster::UpdateInstallRecord*> : IIterator_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Management::Update::Cluster::UpdateInstallRecord*, ABI::Windows::Management::Update::Cluster::IUpdateInstallRecord*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IIterator`1<Windows.Management.Update.Cluster.UpdateInstallRecord>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterator<ABI::Windows::Management::Update::Cluster::UpdateInstallRecord*> __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord_t;
#define __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord ABI::Windows::Foundation::Collections::__FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord_USE */

#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

#ifndef DEF___FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord_USE
#define DEF___FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("368bf35a-8ac1-56c1-94b5-a080d8f20e4e"))
IIterable<ABI::Windows::Management::Update::Cluster::UpdateInstallRecord*> : IIterable_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Management::Update::Cluster::UpdateInstallRecord*, ABI::Windows::Management::Update::Cluster::IUpdateInstallRecord*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IIterable`1<Windows.Management.Update.Cluster.UpdateInstallRecord>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterable<ABI::Windows::Management::Update::Cluster::UpdateInstallRecord*> __FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord_t;
#define __FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord ABI::Windows::Foundation::Collections::__FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord_USE */

#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    class UpdateRecipeNodeValidationInfoRecord;
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

#ifndef DEF___FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord_USE
#define DEF___FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("d9b6eb8a-dfc7-50fa-8dea-538e3fb79570"))
IIterator<ABI::Windows::Management::Update::Cluster::UpdateRecipeNodeValidationInfoRecord*> : IIterator_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Management::Update::Cluster::UpdateRecipeNodeValidationInfoRecord*, ABI::Windows::Management::Update::Cluster::IUpdateRecipeNodeValidationInfoRecord*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IIterator`1<Windows.Management.Update.Cluster.UpdateRecipeNodeValidationInfoRecord>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterator<ABI::Windows::Management::Update::Cluster::UpdateRecipeNodeValidationInfoRecord*> __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord_t;
#define __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord ABI::Windows::Foundation::Collections::__FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord_USE */

#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

#ifndef DEF___FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord_USE
#define DEF___FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("e69c7183-ddb2-5113-af49-8b4df0c96af4"))
IIterable<ABI::Windows::Management::Update::Cluster::UpdateRecipeNodeValidationInfoRecord*> : IIterable_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Management::Update::Cluster::UpdateRecipeNodeValidationInfoRecord*, ABI::Windows::Management::Update::Cluster::IUpdateRecipeNodeValidationInfoRecord*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IIterable`1<Windows.Management.Update.Cluster.UpdateRecipeNodeValidationInfoRecord>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterable<ABI::Windows::Management::Update::Cluster::UpdateRecipeNodeValidationInfoRecord*> __FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord_t;
#define __FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord ABI::Windows::Foundation::Collections::__FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord_USE */

#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    class UpdateScanRecord;
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

#ifndef DEF___FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord_USE
#define DEF___FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("7c5cfe06-c971-533b-bba5-834657b9002a"))
IIterator<ABI::Windows::Management::Update::Cluster::UpdateScanRecord*> : IIterator_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Management::Update::Cluster::UpdateScanRecord*, ABI::Windows::Management::Update::Cluster::IUpdateScanRecord*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IIterator`1<Windows.Management.Update.Cluster.UpdateScanRecord>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterator<ABI::Windows::Management::Update::Cluster::UpdateScanRecord*> __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord_t;
#define __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord ABI::Windows::Foundation::Collections::__FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord_USE */

#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

#ifndef DEF___FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord_USE
#define DEF___FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("a470910d-3e8d-5d27-9291-581b24fc1a64"))
IIterable<ABI::Windows::Management::Update::Cluster::UpdateScanRecord*> : IIterable_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Management::Update::Cluster::UpdateScanRecord*, ABI::Windows::Management::Update::Cluster::IUpdateScanRecord*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IIterable`1<Windows.Management.Update.Cluster.UpdateScanRecord>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterable<ABI::Windows::Management::Update::Cluster::UpdateScanRecord*> __FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord_t;
#define __FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord ABI::Windows::Foundation::Collections::__FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord_USE */

#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    class UpdateStageRecord;
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

#ifndef DEF___FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord_USE
#define DEF___FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("314e74c1-f580-5706-bcd2-7bd4fdfb822f"))
IIterator<ABI::Windows::Management::Update::Cluster::UpdateStageRecord*> : IIterator_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Management::Update::Cluster::UpdateStageRecord*, ABI::Windows::Management::Update::Cluster::IUpdateStageRecord*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IIterator`1<Windows.Management.Update.Cluster.UpdateStageRecord>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterator<ABI::Windows::Management::Update::Cluster::UpdateStageRecord*> __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord_t;
#define __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord ABI::Windows::Foundation::Collections::__FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord_USE */

#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

#ifndef DEF___FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord_USE
#define DEF___FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("958a6876-bf10-5872-a23d-93cc7b9a4bc9"))
IIterable<ABI::Windows::Management::Update::Cluster::UpdateStageRecord*> : IIterable_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Management::Update::Cluster::UpdateStageRecord*, ABI::Windows::Management::Update::Cluster::IUpdateStageRecord*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IIterable`1<Windows.Management.Update.Cluster.UpdateStageRecord>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterable<ABI::Windows::Management::Update::Cluster::UpdateStageRecord*> __FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord_t;
#define __FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord ABI::Windows::Foundation::Collections::__FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord_USE */

#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    class UpdateValidationLogMessage;
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

#ifndef DEF___FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage_USE
#define DEF___FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("fd406572-3830-596a-9f70-1fc00749c328"))
IIterator<ABI::Windows::Management::Update::Cluster::UpdateValidationLogMessage*> : IIterator_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Management::Update::Cluster::UpdateValidationLogMessage*, ABI::Windows::Management::Update::Cluster::IUpdateValidationLogMessage*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IIterator`1<Windows.Management.Update.Cluster.UpdateValidationLogMessage>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterator<ABI::Windows::Management::Update::Cluster::UpdateValidationLogMessage*> __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage_t;
#define __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage ABI::Windows::Foundation::Collections::__FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage_USE */

#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

#ifndef DEF___FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage_USE
#define DEF___FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("1c02198c-aba3-57a3-a381-16830da1aa89"))
IIterable<ABI::Windows::Management::Update::Cluster::UpdateValidationLogMessage*> : IIterable_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Management::Update::Cluster::UpdateValidationLogMessage*, ABI::Windows::Management::Update::Cluster::IUpdateValidationLogMessage*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IIterable`1<Windows.Management.Update.Cluster.UpdateValidationLogMessage>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IIterable<ABI::Windows::Management::Update::Cluster::UpdateValidationLogMessage*> __FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage_t;
#define __FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage ABI::Windows::Foundation::Collections::__FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage_USE */

#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000


#ifndef DEF___FIMapView_2_HSTRING_HSTRING_USE
#define DEF___FIMapView_2_HSTRING_HSTRING_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("ac7f26f2-feb7-5b2a-8ac4-345bc62caede"))
IMapView<HSTRING, HSTRING> : IMapView_impl<HSTRING, HSTRING>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IMapView`2<String, String>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IMapView<HSTRING, HSTRING> __FIMapView_2_HSTRING_HSTRING_t;
#define __FIMapView_2_HSTRING_HSTRING ABI::Windows::Foundation::Collections::__FIMapView_2_HSTRING_HSTRING_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIMapView_2_HSTRING_HSTRING_USE */



#ifndef DEF___FIMap_2_HSTRING_HSTRING_USE
#define DEF___FIMap_2_HSTRING_HSTRING_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("f6d1f700-49c2-52ae-8154-826f9908773c"))
IMap<HSTRING, HSTRING> : IMap_impl<HSTRING, HSTRING>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IMap`2<String, String>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IMap<HSTRING, HSTRING> __FIMap_2_HSTRING_HSTRING_t;
#define __FIMap_2_HSTRING_HSTRING ABI::Windows::Foundation::Collections::__FIMap_2_HSTRING_HSTRING_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIMap_2_HSTRING_HSTRING_USE */


#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

#ifndef DEF___FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord_USE
#define DEF___FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("f7d373c8-d6d9-5753-9abc-4028149c5ba6"))
IVectorView<ABI::Windows::Management::Update::Cluster::UpdateInstallRecord*> : IVectorView_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Management::Update::Cluster::UpdateInstallRecord*, ABI::Windows::Management::Update::Cluster::IUpdateInstallRecord*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IVectorView`1<Windows.Management.Update.Cluster.UpdateInstallRecord>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IVectorView<ABI::Windows::Management::Update::Cluster::UpdateInstallRecord*> __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord_t;
#define __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord ABI::Windows::Foundation::Collections::__FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord_USE */

#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

#ifndef DEF___FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord_USE
#define DEF___FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("a2fa4879-3e6b-5c2b-9c26-5d445930ad92"))
IVectorView<ABI::Windows::Management::Update::Cluster::UpdateRecipeNodeValidationInfoRecord*> : IVectorView_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Management::Update::Cluster::UpdateRecipeNodeValidationInfoRecord*, ABI::Windows::Management::Update::Cluster::IUpdateRecipeNodeValidationInfoRecord*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IVectorView`1<Windows.Management.Update.Cluster.UpdateRecipeNodeValidationInfoRecord>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IVectorView<ABI::Windows::Management::Update::Cluster::UpdateRecipeNodeValidationInfoRecord*> __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord_t;
#define __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord ABI::Windows::Foundation::Collections::__FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord_USE */

#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

#ifndef DEF___FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord_USE
#define DEF___FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("40677104-06fe-5bf5-bb2c-d69aa0fee0e4"))
IVectorView<ABI::Windows::Management::Update::Cluster::UpdateScanRecord*> : IVectorView_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Management::Update::Cluster::UpdateScanRecord*, ABI::Windows::Management::Update::Cluster::IUpdateScanRecord*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IVectorView`1<Windows.Management.Update.Cluster.UpdateScanRecord>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IVectorView<ABI::Windows::Management::Update::Cluster::UpdateScanRecord*> __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord_t;
#define __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord ABI::Windows::Foundation::Collections::__FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord_USE */

#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

#ifndef DEF___FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord_USE
#define DEF___FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("98f1e843-11fe-5752-8a02-5e564258fa60"))
IVectorView<ABI::Windows::Management::Update::Cluster::UpdateStageRecord*> : IVectorView_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Management::Update::Cluster::UpdateStageRecord*, ABI::Windows::Management::Update::Cluster::IUpdateStageRecord*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IVectorView`1<Windows.Management.Update.Cluster.UpdateStageRecord>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IVectorView<ABI::Windows::Management::Update::Cluster::UpdateStageRecord*> __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord_t;
#define __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord ABI::Windows::Foundation::Collections::__FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord_USE */

#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

#ifndef DEF___FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage_USE
#define DEF___FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("4f374506-49c2-5718-876c-3d1df2990311"))
IVectorView<ABI::Windows::Management::Update::Cluster::UpdateValidationLogMessage*> : IVectorView_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Management::Update::Cluster::UpdateValidationLogMessage*, ABI::Windows::Management::Update::Cluster::IUpdateValidationLogMessage*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.Collections.IVectorView`1<Windows.Management.Update.Cluster.UpdateValidationLogMessage>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef IVectorView<ABI::Windows::Management::Update::Cluster::UpdateValidationLogMessage*> __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage_t;
#define __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage ABI::Windows::Foundation::Collections::__FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage_t
/* Collections */ } /* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage_USE */

#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

namespace ABI {
    namespace Windows {
        namespace Foundation {
            typedef struct TimeSpan TimeSpan;
        } /* Foundation */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    typedef enum ClusterNativeUpdateCompletionStatus : int ClusterNativeUpdateCompletionStatus;
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    typedef enum ClusterNativeUpdateCredentialStatus : int ClusterNativeUpdateCredentialStatus;
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    typedef enum ClusterNativeUpdateEnvironmentValidationStatus : int ClusterNativeUpdateEnvironmentValidationStatus;
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    typedef enum ClusterNativeUpdateLogLevel : int ClusterNativeUpdateLogLevel;
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    typedef enum ClusterNativeUpdateOperationStatus : int ClusterNativeUpdateOperationStatus;
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    class AcquireEnvironmentInfoResult;
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    class AreRebootsPendingResult;
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    class ClusterUpdateServices;
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    class InstallUpdateTaskResult;
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    class RollbackUpdateTaskResult;
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    class ScanUpdateTaskResult;
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    class StageUpdateTaskResult;
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    class UpdateCredential;
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    class UpdateOperationResult;
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    class UpdatePendingOperationResult;
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    class UpdatePluginVersionInfo;
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    class UpdateTaskResult;
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    class ValidateAllNodesUpdateRecipeResult;
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    class ValidateClusterEnvironmentResult;
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

/*
 *
 * Struct Windows.Management.Update.Cluster.ClusterNativeUpdateCompletionStatus
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    enum ClusterNativeUpdateCompletionStatus : int
                    {
                        ClusterNativeUpdateCompletionStatus_Completed = 0,
                        ClusterNativeUpdateCompletionStatus_Failed = 1,
                        ClusterNativeUpdateCompletionStatus_Canceled = 2,
                    };
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Struct Windows.Management.Update.Cluster.ClusterNativeUpdateCredentialStatus
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    enum ClusterNativeUpdateCredentialStatus : int
                    {
                        ClusterNativeUpdateCredentialStatus_Success = 0,
                        ClusterNativeUpdateCredentialStatus_NoSuchCredential = 1,
                        ClusterNativeUpdateCredentialStatus_ErrorRetrievingCredential = 2,
                    };
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Struct Windows.Management.Update.Cluster.ClusterNativeUpdateEnvironmentValidationStatus
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    enum ClusterNativeUpdateEnvironmentValidationStatus : int
                    {
                        ClusterNativeUpdateEnvironmentValidationStatus_Approved = 0,
                        ClusterNativeUpdateEnvironmentValidationStatus_ApprovedWithWarnings = 1,
                        ClusterNativeUpdateEnvironmentValidationStatus_Rejected = 2,
                    };
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Struct Windows.Management.Update.Cluster.ClusterNativeUpdateLogLevel
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    enum ClusterNativeUpdateLogLevel : int
                    {
                        ClusterNativeUpdateLogLevel_Debug = 0,
                        ClusterNativeUpdateLogLevel_Verbose = 1,
                        ClusterNativeUpdateLogLevel_Info = 2,
                        ClusterNativeUpdateLogLevel_Warning = 3,
                        ClusterNativeUpdateLogLevel_Error = 4,
                    };
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Struct Windows.Management.Update.Cluster.ClusterNativeUpdateOperationStatus
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    enum ClusterNativeUpdateOperationStatus : int
                    {
                        ClusterNativeUpdateOperationStatus_Success = 0,
                        ClusterNativeUpdateOperationStatus_Failed = 1,
                        ClusterNativeUpdateOperationStatus_Pending = 2,
                        ClusterNativeUpdateOperationStatus_Canceled = 3,
                    };
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IAcquireEnvironmentInfoResult
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.Cluster.AcquireEnvironmentInfoResult
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAcquireEnvironmentInfoResult_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAcquireEnvironmentInfoResult_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IAcquireEnvironmentInfoResult[] = L"Windows.Management.Update.Cluster.IAcquireEnvironmentInfoResult";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    MIDL_INTERFACE("b720e3a4-9a34-51c1-a1fa-0c6673bef689")
                    IAcquireEnvironmentInfoResult : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE get_Result(
                            ABI::Windows::Management::Update::Cluster::IUpdateTaskResult** value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_EnvironmentInfo(
                            HSTRING* value
                            ) = 0;
                    };

                    MIDL_CONST_ID IID& IID_IAcquireEnvironmentInfoResult = __uuidof(IAcquireEnvironmentInfoResult);
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAcquireEnvironmentInfoResult;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAcquireEnvironmentInfoResult_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IAcquireEnvironmentInfoResultFactory
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.Cluster.AcquireEnvironmentInfoResult
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAcquireEnvironmentInfoResultFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAcquireEnvironmentInfoResultFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IAcquireEnvironmentInfoResultFactory[] = L"Windows.Management.Update.Cluster.IAcquireEnvironmentInfoResultFactory";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    MIDL_INTERFACE("bbe87f45-0125-5b6d-b9de-05effc98becb")
                    IAcquireEnvironmentInfoResultFactory : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE CreateInstance(
                            ABI::Windows::Management::Update::Cluster::IUpdateTaskResult* result,
                            HSTRING environmentInfo,
                            ABI::Windows::Management::Update::Cluster::IAcquireEnvironmentInfoResult** value
                            ) = 0;
                    };

                    MIDL_CONST_ID IID& IID_IAcquireEnvironmentInfoResultFactory = __uuidof(IAcquireEnvironmentInfoResultFactory);
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAcquireEnvironmentInfoResultFactory;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAcquireEnvironmentInfoResultFactory_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IAreRebootsPendingResult
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.Cluster.AreRebootsPendingResult
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAreRebootsPendingResult_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAreRebootsPendingResult_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IAreRebootsPendingResult[] = L"Windows.Management.Update.Cluster.IAreRebootsPendingResult";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    MIDL_INTERFACE("a0c93ffd-8409-5fe1-876b-d59d5d9951b5")
                    IAreRebootsPendingResult : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE get_Result(
                            ABI::Windows::Management::Update::Cluster::IUpdateOperationResult** value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_IsRebootPending(
                            boolean* value
                            ) = 0;
                    };

                    MIDL_CONST_ID IID& IID_IAreRebootsPendingResult = __uuidof(IAreRebootsPendingResult);
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAreRebootsPendingResult;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAreRebootsPendingResult_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IAreRebootsPendingResultFactory
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.Cluster.AreRebootsPendingResult
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAreRebootsPendingResultFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAreRebootsPendingResultFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IAreRebootsPendingResultFactory[] = L"Windows.Management.Update.Cluster.IAreRebootsPendingResultFactory";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    MIDL_INTERFACE("801c7304-1fdf-59b4-9ef6-adbd0544d98f")
                    IAreRebootsPendingResultFactory : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE CreateInstance(
                            ABI::Windows::Management::Update::Cluster::IUpdateOperationResult* result,
                            boolean isRebootPending,
                            ABI::Windows::Management::Update::Cluster::IAreRebootsPendingResult** value
                            ) = 0;
                    };

                    MIDL_CONST_ID IID& IID_IAreRebootsPendingResultFactory = __uuidof(IAreRebootsPendingResultFactory);
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAreRebootsPendingResultFactory;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAreRebootsPendingResultFactory_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IClusterNativeEnvironmentOperations
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperations_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperations_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IClusterNativeEnvironmentOperations[] = L"Windows.Management.Update.Cluster.IClusterNativeEnvironmentOperations";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    MIDL_INTERFACE("a6d3d05e-1cfe-5363-b745-c6981d0e6b25")
                    IClusterNativeEnvironmentOperations : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE AcquireNodeEnvironmentInfo(
                            ABI::Windows::Management::Update::Cluster::IAcquireEnvironmentInfoResult** result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE ValidateClusterEnvironment(
                            __FIMapView_2_HSTRING_HSTRING* nodeEnvironmentInfo,
                            ABI::Windows::Management::Update::Cluster::IValidateClusterEnvironmentResult** result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE StartPreUpdateRunOperation(
                            ABI::Windows::Management::Update::Cluster::IUpdateOperationResult** result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE IsPreUpdateRunOperationComplete(
                            ABI::Windows::Management::Update::Cluster::IUpdatePendingOperationResult** result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE StartPostUpdateRunOperation(
                            ABI::Windows::Management::Update::Cluster::IUpdateOperationResult** result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE IsPostUpdateRunOperationComplete(
                            ABI::Windows::Management::Update::Cluster::IUpdatePendingOperationResult** result
                            ) = 0;
                    };

                    MIDL_CONST_ID IID& IID_IClusterNativeEnvironmentOperations = __uuidof(IClusterNativeEnvironmentOperations);
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperations;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperations_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IClusterNativeEnvironmentOperationsPlugin
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperationsPlugin_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperationsPlugin_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IClusterNativeEnvironmentOperationsPlugin[] = L"Windows.Management.Update.Cluster.IClusterNativeEnvironmentOperationsPlugin";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    MIDL_INTERFACE("534b9984-3201-5a90-a42b-42d9c98c961a")
                    IClusterNativeEnvironmentOperationsPlugin : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE get_Name(
                            HSTRING* value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_FriendlyName(
                            HSTRING* value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_Description(
                            HSTRING* value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_Version(
                            ABI::Windows::Management::Update::Cluster::IUpdatePluginVersionInfo** value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_DefaultOptions(
                            __FIMapView_2_HSTRING_HSTRING** value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE CreateEnvironmentOperations(
                            HSTRING clusterName,
                            HSTRING runId,
                            __FIMap_2_HSTRING_HSTRING* options,
                            ABI::Windows::Management::Update::Cluster::IClusterUpdateServices* updateServices,
                            ABI::Windows::Management::Update::Cluster::IClusterNativeEnvironmentOperations** result
                            ) = 0;
                    };

                    MIDL_CONST_ID IID& IID_IClusterNativeEnvironmentOperationsPlugin = __uuidof(IClusterNativeEnvironmentOperationsPlugin);
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperationsPlugin;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperationsPlugin_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IClusterNativeNodeOperations
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperations_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperations_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IClusterNativeNodeOperations[] = L"Windows.Management.Update.Cluster.IClusterNativeNodeOperations";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    MIDL_INTERFACE("ce23db69-b72b-5204-9d1c-c53d0b2d803d")
                    IClusterNativeNodeOperations : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE AreAdditionalRebootsPending(
                            ABI::Windows::Management::Update::Cluster::IAreRebootsPendingResult** result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE StartPreRebootOperation(
                            ABI::Windows::Management::Update::Cluster::IUpdateOperationResult** result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE IsPreRebootOperationComplete(
                            ABI::Windows::Management::Update::Cluster::IUpdatePendingOperationResult** result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE StartPostRebootOperation(
                            ABI::Windows::Management::Update::Cluster::IUpdateOperationResult** result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE IsPostRebootOperationComplete(
                            ABI::Windows::Management::Update::Cluster::IUpdatePendingOperationResult** result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE StartPreDrainOperation(
                            ABI::Windows::Management::Update::Cluster::IUpdateOperationResult** result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE IsPreDrainOperationComplete(
                            ABI::Windows::Management::Update::Cluster::IUpdatePendingOperationResult** result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE StartPostResumeOperation(
                            ABI::Windows::Management::Update::Cluster::IUpdateOperationResult** result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE IsPostResumeOperationComplete(
                            ABI::Windows::Management::Update::Cluster::IUpdatePendingOperationResult** result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE StartPreUpdateRunOperation(
                            ABI::Windows::Management::Update::Cluster::IUpdateOperationResult** result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE IsPreUpdateRunOperationComplete(
                            ABI::Windows::Management::Update::Cluster::IUpdatePendingOperationResult** result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE StartPostUpdateRunOperation(
                            ABI::Windows::Management::Update::Cluster::IUpdateOperationResult** result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE IsPostUpdateRunOperationComplete(
                            ABI::Windows::Management::Update::Cluster::IUpdatePendingOperationResult** result
                            ) = 0;
                    };

                    MIDL_CONST_ID IID& IID_IClusterNativeNodeOperations = __uuidof(IClusterNativeNodeOperations);
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperations;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperations_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IClusterNativeNodeOperationsPlugin
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperationsPlugin_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperationsPlugin_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IClusterNativeNodeOperationsPlugin[] = L"Windows.Management.Update.Cluster.IClusterNativeNodeOperationsPlugin";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    MIDL_INTERFACE("5f7a457c-e9d3-5cec-a967-0da9d95fd6f4")
                    IClusterNativeNodeOperationsPlugin : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE get_Name(
                            HSTRING* value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_FriendlyName(
                            HSTRING* value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_Description(
                            HSTRING* value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_Version(
                            ABI::Windows::Management::Update::Cluster::IUpdatePluginVersionInfo** value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_DefaultOptions(
                            __FIMapView_2_HSTRING_HSTRING** value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE CreateNodeOperations(
                            HSTRING clusterName,
                            HSTRING runId,
                            __FIMap_2_HSTRING_HSTRING* options,
                            ABI::Windows::Management::Update::Cluster::IClusterUpdateServices* updateServices,
                            ABI::Windows::Management::Update::Cluster::IClusterNativeNodeOperations** result
                            ) = 0;
                    };

                    MIDL_CONST_ID IID& IID_IClusterNativeNodeOperationsPlugin = __uuidof(IClusterNativeNodeOperationsPlugin);
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperationsPlugin;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperationsPlugin_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IClusterUpdateServices
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.Cluster.ClusterUpdateServices
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterUpdateServices_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterUpdateServices_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IClusterUpdateServices[] = L"Windows.Management.Update.Cluster.IClusterUpdateServices";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    MIDL_INTERFACE("38461e68-1445-53e3-b914-ce19e3b730c4")
                    IClusterUpdateServices : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE WriteLogEntry(
                            ABI::Windows::Management::Update::Cluster::ClusterNativeUpdateLogLevel level,
                            HSTRING message
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE ReportProgress(
                            INT32 currentStep,
                            INT32 maxSteps,
                            HSTRING message
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE GetPluginCredential(
                            HSTRING credentialId,
                            ABI::Windows::Management::Update::Cluster::IUpdateCredential** result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE IsOperationMarkedAsCanceled(
                            boolean* result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE SaveRunStateInformation(
                            HSTRING persistentInformation
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE GetRunStateInformation(
                            HSTRING* result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE SaveRunIndependentInformation(
                            HSTRING persistentInformation
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE GetRunIndependentInformation(
                            HSTRING* result
                            ) = 0;
                    };

                    MIDL_CONST_ID IID& IID_IClusterUpdateServices = __uuidof(IClusterUpdateServices);
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterUpdateServices;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterUpdateServices_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IInstallUpdateTaskResult
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.Cluster.InstallUpdateTaskResult
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIInstallUpdateTaskResult_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIInstallUpdateTaskResult_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IInstallUpdateTaskResult[] = L"Windows.Management.Update.Cluster.IInstallUpdateTaskResult";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    MIDL_INTERFACE("d519090a-4e93-5916-92bb-9356da52344b")
                    IInstallUpdateTaskResult : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE get_Result(
                            ABI::Windows::Management::Update::Cluster::IUpdateTaskResult** value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_InstallRecords(
                            __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord** value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_ShouldRollback(
                            boolean* value
                            ) = 0;
                    };

                    MIDL_CONST_ID IID& IID_IInstallUpdateTaskResult = __uuidof(IInstallUpdateTaskResult);
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIInstallUpdateTaskResult;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIInstallUpdateTaskResult_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IInstallUpdateTaskResultFactory
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.Cluster.InstallUpdateTaskResult
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIInstallUpdateTaskResultFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIInstallUpdateTaskResultFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IInstallUpdateTaskResultFactory[] = L"Windows.Management.Update.Cluster.IInstallUpdateTaskResultFactory";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    MIDL_INTERFACE("07473356-1a87-554d-9c14-489c0d69b258")
                    IInstallUpdateTaskResultFactory : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE CreateInstance(
                            ABI::Windows::Management::Update::Cluster::IUpdateTaskResult* result,
                            __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord* installRecords,
                            boolean shouldRollback,
                            ABI::Windows::Management::Update::Cluster::IInstallUpdateTaskResult** value
                            ) = 0;
                    };

                    MIDL_CONST_ID IID& IID_IInstallUpdateTaskResultFactory = __uuidof(IInstallUpdateTaskResultFactory);
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIInstallUpdateTaskResultFactory;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIInstallUpdateTaskResultFactory_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IRollbackUpdateTaskResult
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.Cluster.RollbackUpdateTaskResult
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIRollbackUpdateTaskResult_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIRollbackUpdateTaskResult_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IRollbackUpdateTaskResult[] = L"Windows.Management.Update.Cluster.IRollbackUpdateTaskResult";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    MIDL_INTERFACE("477e2a95-bcb6-5044-ad3d-e4180efcf1be")
                    IRollbackUpdateTaskResult : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE get_Result(
                            ABI::Windows::Management::Update::Cluster::IUpdateTaskResult** value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_InstallRecords(
                            __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord** value
                            ) = 0;
                    };

                    MIDL_CONST_ID IID& IID_IRollbackUpdateTaskResult = __uuidof(IRollbackUpdateTaskResult);
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIRollbackUpdateTaskResult;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIRollbackUpdateTaskResult_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IRollbackUpdateTaskResultFactory
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.Cluster.RollbackUpdateTaskResult
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIRollbackUpdateTaskResultFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIRollbackUpdateTaskResultFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IRollbackUpdateTaskResultFactory[] = L"Windows.Management.Update.Cluster.IRollbackUpdateTaskResultFactory";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    MIDL_INTERFACE("2dbd5bc3-efdf-5046-8954-78981796f016")
                    IRollbackUpdateTaskResultFactory : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE CreateInstance(
                            ABI::Windows::Management::Update::Cluster::IUpdateTaskResult* result,
                            __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord* installRecords,
                            ABI::Windows::Management::Update::Cluster::IRollbackUpdateTaskResult** value
                            ) = 0;
                    };

                    MIDL_CONST_ID IID& IID_IRollbackUpdateTaskResultFactory = __uuidof(IRollbackUpdateTaskResultFactory);
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIRollbackUpdateTaskResultFactory;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIRollbackUpdateTaskResultFactory_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IScanUpdateTaskResult
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.Cluster.ScanUpdateTaskResult
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIScanUpdateTaskResult_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIScanUpdateTaskResult_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IScanUpdateTaskResult[] = L"Windows.Management.Update.Cluster.IScanUpdateTaskResult";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    MIDL_INTERFACE("24e9f302-a976-5148-b109-5100ac1a50ed")
                    IScanUpdateTaskResult : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE get_Result(
                            ABI::Windows::Management::Update::Cluster::IUpdateTaskResult** value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_ScanRecords(
                            __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord** value
                            ) = 0;
                    };

                    MIDL_CONST_ID IID& IID_IScanUpdateTaskResult = __uuidof(IScanUpdateTaskResult);
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIScanUpdateTaskResult;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIScanUpdateTaskResult_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IScanUpdateTaskResultFactory
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.Cluster.ScanUpdateTaskResult
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIScanUpdateTaskResultFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIScanUpdateTaskResultFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IScanUpdateTaskResultFactory[] = L"Windows.Management.Update.Cluster.IScanUpdateTaskResultFactory";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    MIDL_INTERFACE("12594ad2-5312-5f8a-8fa2-2da4a34e3319")
                    IScanUpdateTaskResultFactory : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE CreateInstance(
                            ABI::Windows::Management::Update::Cluster::IUpdateTaskResult* result,
                            __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord* scanRecords,
                            ABI::Windows::Management::Update::Cluster::IScanUpdateTaskResult** value
                            ) = 0;
                    };

                    MIDL_CONST_ID IID& IID_IScanUpdateTaskResultFactory = __uuidof(IScanUpdateTaskResultFactory);
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIScanUpdateTaskResultFactory;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIScanUpdateTaskResultFactory_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IStageUpdateTaskResult
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.Cluster.StageUpdateTaskResult
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIStageUpdateTaskResult_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIStageUpdateTaskResult_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IStageUpdateTaskResult[] = L"Windows.Management.Update.Cluster.IStageUpdateTaskResult";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    MIDL_INTERFACE("c926add1-335c-57f7-8dac-1ce2fce65060")
                    IStageUpdateTaskResult : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE get_Result(
                            ABI::Windows::Management::Update::Cluster::IUpdateTaskResult** value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_StageRecords(
                            __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord** value
                            ) = 0;
                    };

                    MIDL_CONST_ID IID& IID_IStageUpdateTaskResult = __uuidof(IStageUpdateTaskResult);
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIStageUpdateTaskResult;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIStageUpdateTaskResult_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IStageUpdateTaskResultFactory
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.Cluster.StageUpdateTaskResult
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIStageUpdateTaskResultFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIStageUpdateTaskResultFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IStageUpdateTaskResultFactory[] = L"Windows.Management.Update.Cluster.IStageUpdateTaskResultFactory";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    MIDL_INTERFACE("2256548a-f175-5143-888a-f49f27a34ed3")
                    IStageUpdateTaskResultFactory : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE CreateInstance(
                            ABI::Windows::Management::Update::Cluster::IUpdateTaskResult* result,
                            __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord* stageRecords,
                            ABI::Windows::Management::Update::Cluster::IStageUpdateTaskResult** value
                            ) = 0;
                    };

                    MIDL_CONST_ID IID& IID_IStageUpdateTaskResultFactory = __uuidof(IStageUpdateTaskResultFactory);
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIStageUpdateTaskResultFactory;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIStageUpdateTaskResultFactory_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IUpdateCredential
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.Cluster.UpdateCredential
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateCredential_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateCredential_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IUpdateCredential[] = L"Windows.Management.Update.Cluster.IUpdateCredential";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    MIDL_INTERFACE("de6d09b1-bcdb-5d6d-9d46-7250b853fffe")
                    IUpdateCredential : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE get_Status(
                            ABI::Windows::Management::Update::Cluster::ClusterNativeUpdateCredentialStatus* value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_UserName(
                            HSTRING* value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_Password(
                            HSTRING* value
                            ) = 0;
                    };

                    MIDL_CONST_ID IID& IID_IUpdateCredential = __uuidof(IUpdateCredential);
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateCredential;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateCredential_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IUpdateCredentialFactory
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.Cluster.UpdateCredential
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateCredentialFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateCredentialFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IUpdateCredentialFactory[] = L"Windows.Management.Update.Cluster.IUpdateCredentialFactory";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    MIDL_INTERFACE("e251a298-44b1-5455-8b44-5971bd516f09")
                    IUpdateCredentialFactory : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE CreateInstance(
                            ABI::Windows::Management::Update::Cluster::ClusterNativeUpdateCredentialStatus status,
                            HSTRING userName,
                            HSTRING password,
                            ABI::Windows::Management::Update::Cluster::IUpdateCredential** value
                            ) = 0;
                    };

                    MIDL_CONST_ID IID& IID_IUpdateCredentialFactory = __uuidof(IUpdateCredentialFactory);
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateCredentialFactory;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateCredentialFactory_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IUpdateInstallRecord
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.Cluster.UpdateInstallRecord
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecord_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecord_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IUpdateInstallRecord[] = L"Windows.Management.Update.Cluster.IUpdateInstallRecord";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    MIDL_INTERFACE("38118797-dc5d-5727-89ff-5b8a44b3f53b")
                    IUpdateInstallRecord : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE get_UpdateId(
                            HSTRING* value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_IsRebootRequired(
                            boolean* value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_Status(
                            ABI::Windows::Management::Update::Cluster::ClusterNativeUpdateCompletionStatus* value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_FailureMessage(
                            HSTRING* value
                            ) = 0;
                    };

                    MIDL_CONST_ID IID& IID_IUpdateInstallRecord = __uuidof(IUpdateInstallRecord);
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecord;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecord_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IUpdateInstallRecordFactory
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.Cluster.UpdateInstallRecord
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecordFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecordFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IUpdateInstallRecordFactory[] = L"Windows.Management.Update.Cluster.IUpdateInstallRecordFactory";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    MIDL_INTERFACE("9b6c54b5-d229-5147-9d6e-16e47f2317db")
                    IUpdateInstallRecordFactory : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE CreateInstance(
                            HSTRING updateId,
                            boolean isRebootRequired,
                            ABI::Windows::Management::Update::Cluster::ClusterNativeUpdateCompletionStatus status,
                            HSTRING failureMessage,
                            ABI::Windows::Management::Update::Cluster::IUpdateInstallRecord** value
                            ) = 0;
                    };

                    MIDL_CONST_ID IID& IID_IUpdateInstallRecordFactory = __uuidof(IUpdateInstallRecordFactory);
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecordFactory;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecordFactory_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IUpdateInstaller
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstaller_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstaller_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IUpdateInstaller[] = L"Windows.Management.Update.Cluster.IUpdateInstaller";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    MIDL_INTERFACE("c8cfe973-daaf-57d3-8d3b-59eec0b082ea")
                    IUpdateInstaller : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE Scan(
                            ABI::Windows::Management::Update::Cluster::IScanUpdateTaskResult** result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE Stage(
                            __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord* updatesToStage,
                            ABI::Windows::Management::Update::Cluster::IStageUpdateTaskResult** result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE Install(
                            __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord* updatesToInstall,
                            ABI::Windows::Management::Update::Cluster::IInstallUpdateTaskResult** result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE Rollback(
                            __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord* updatesToRollback,
                            ABI::Windows::Management::Update::Cluster::IRollbackUpdateTaskResult** result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE ShouldUsePluginSpecificReboot(
                            boolean* usePluginReboot,
                            ABI::Windows::Management::Update::Cluster::IUpdateTaskResult** result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE RebootNode(
                            ABI::Windows::Management::Update::Cluster::IUpdateTaskResult** result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE AcquireUpdateListValidationInfo(
                            HSTRING* recipeValidationInfo,
                            ABI::Windows::Management::Update::Cluster::IUpdateTaskResult** result
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE ValidateAllNodesUpdateRecipe(
                            __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord* allNodesRecipeValidationInfo,
                            ABI::Windows::Management::Update::Cluster::IValidateAllNodesUpdateRecipeResult** result
                            ) = 0;
                    };

                    MIDL_CONST_ID IID& IID_IUpdateInstaller = __uuidof(IUpdateInstaller);
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstaller;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstaller_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IUpdateInstallerPlugin
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallerPlugin_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallerPlugin_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IUpdateInstallerPlugin[] = L"Windows.Management.Update.Cluster.IUpdateInstallerPlugin";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    MIDL_INTERFACE("61122faa-0cd8-5a98-8938-5c1f88c632c6")
                    IUpdateInstallerPlugin : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE get_Name(
                            HSTRING* value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_FriendlyName(
                            HSTRING* value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_Description(
                            HSTRING* value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_Version(
                            ABI::Windows::Management::Update::Cluster::IUpdatePluginVersionInfo** value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_IsUpdateRollbackSupported(
                            boolean* value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_DefaultOptions(
                            __FIMapView_2_HSTRING_HSTRING** value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE CreateUpdateInstaller(
                            HSTRING clusterName,
                            HSTRING runId,
                            __FIMap_2_HSTRING_HSTRING* options,
                            ABI::Windows::Management::Update::Cluster::IClusterUpdateServices* updateServices,
                            ABI::Windows::Management::Update::Cluster::IUpdateInstaller** result
                            ) = 0;
                    };

                    MIDL_CONST_ID IID& IID_IUpdateInstallerPlugin = __uuidof(IUpdateInstallerPlugin);
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallerPlugin;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallerPlugin_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IUpdateOperationResult
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.Cluster.UpdateOperationResult
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResult_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResult_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IUpdateOperationResult[] = L"Windows.Management.Update.Cluster.IUpdateOperationResult";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    MIDL_INTERFACE("9fc35275-3eb7-5785-bb32-0e37bb52cf41")
                    IUpdateOperationResult : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE get_StatusCode(
                            ABI::Windows::Management::Update::Cluster::ClusterNativeUpdateOperationStatus* value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_Reason(
                            HSTRING* value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_ErrorCode(
                            INT32* value
                            ) = 0;
                    };

                    MIDL_CONST_ID IID& IID_IUpdateOperationResult = __uuidof(IUpdateOperationResult);
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResult;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResult_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IUpdateOperationResultFactory
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.Cluster.UpdateOperationResult
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResultFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResultFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IUpdateOperationResultFactory[] = L"Windows.Management.Update.Cluster.IUpdateOperationResultFactory";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    MIDL_INTERFACE("ff53c580-e92c-50a9-8811-a057d5a2a523")
                    IUpdateOperationResultFactory : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE CreateInstance(
                            ABI::Windows::Management::Update::Cluster::ClusterNativeUpdateOperationStatus status,
                            HSTRING reason,
                            ABI::Windows::Management::Update::Cluster::IUpdateOperationResult** value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE CreateInstance2(
                            ABI::Windows::Management::Update::Cluster::ClusterNativeUpdateOperationStatus status,
                            HSTRING reason,
                            INT32 errorCode,
                            ABI::Windows::Management::Update::Cluster::IUpdateOperationResult** value
                            ) = 0;
                    };

                    MIDL_CONST_ID IID& IID_IUpdateOperationResultFactory = __uuidof(IUpdateOperationResultFactory);
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResultFactory;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResultFactory_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IUpdatePendingOperationResult
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.Cluster.UpdatePendingOperationResult
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResult_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResult_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IUpdatePendingOperationResult[] = L"Windows.Management.Update.Cluster.IUpdatePendingOperationResult";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    MIDL_INTERFACE("0f83b557-e96a-5f19-9492-99fc8bd83c5d")
                    IUpdatePendingOperationResult : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE get_Result(
                            ABI::Windows::Management::Update::Cluster::IUpdateOperationResult** value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_SuggestedRecheckInterval(
                            ABI::Windows::Foundation::TimeSpan* value
                            ) = 0;
                    };

                    MIDL_CONST_ID IID& IID_IUpdatePendingOperationResult = __uuidof(IUpdatePendingOperationResult);
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResult;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResult_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IUpdatePendingOperationResultFactory
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.Cluster.UpdatePendingOperationResult
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResultFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResultFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IUpdatePendingOperationResultFactory[] = L"Windows.Management.Update.Cluster.IUpdatePendingOperationResultFactory";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    MIDL_INTERFACE("45a3b731-d513-5baf-bb44-68b97a938308")
                    IUpdatePendingOperationResultFactory : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE CreateInstance(
                            ABI::Windows::Management::Update::Cluster::IUpdateOperationResult* result,
                            ABI::Windows::Foundation::TimeSpan suggestedRecheckInterval,
                            ABI::Windows::Management::Update::Cluster::IUpdatePendingOperationResult** value
                            ) = 0;
                    };

                    MIDL_CONST_ID IID& IID_IUpdatePendingOperationResultFactory = __uuidof(IUpdatePendingOperationResultFactory);
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResultFactory;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResultFactory_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IUpdatePluginVersionInfo
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.Cluster.UpdatePluginVersionInfo
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfo_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfo_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IUpdatePluginVersionInfo[] = L"Windows.Management.Update.Cluster.IUpdatePluginVersionInfo";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    MIDL_INTERFACE("0901af2e-b340-5e7e-9898-516fc96add89")
                    IUpdatePluginVersionInfo : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE get_MajorVersion(
                            UINT32* value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_MinorVersion(
                            UINT32* value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_PatchLevel(
                            UINT32* value
                            ) = 0;
                    };

                    MIDL_CONST_ID IID& IID_IUpdatePluginVersionInfo = __uuidof(IUpdatePluginVersionInfo);
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfo;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfo_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IUpdatePluginVersionInfoFactory
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.Cluster.UpdatePluginVersionInfo
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfoFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfoFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IUpdatePluginVersionInfoFactory[] = L"Windows.Management.Update.Cluster.IUpdatePluginVersionInfoFactory";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    MIDL_INTERFACE("56bb98ce-543c-59f2-810d-4d2cf84ee40e")
                    IUpdatePluginVersionInfoFactory : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE CreateInstance(
                            UINT32 majorVersion,
                            UINT32 minorVersion,
                            UINT32 patchLevel,
                            ABI::Windows::Management::Update::Cluster::IUpdatePluginVersionInfo** value
                            ) = 0;
                    };

                    MIDL_CONST_ID IID& IID_IUpdatePluginVersionInfoFactory = __uuidof(IUpdatePluginVersionInfoFactory);
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfoFactory;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfoFactory_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IUpdateRecipeNodeValidationInfoRecord
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.Cluster.UpdateRecipeNodeValidationInfoRecord
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecord_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecord_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IUpdateRecipeNodeValidationInfoRecord[] = L"Windows.Management.Update.Cluster.IUpdateRecipeNodeValidationInfoRecord";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    MIDL_INTERFACE("55dfff15-5556-51c4-80c2-af03f385d429")
                    IUpdateRecipeNodeValidationInfoRecord : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE get_NodeName(
                            HSTRING* value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_RecipeValidationInfo(
                            HSTRING* value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_ScanResults(
                            __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord** value
                            ) = 0;
                    };

                    MIDL_CONST_ID IID& IID_IUpdateRecipeNodeValidationInfoRecord = __uuidof(IUpdateRecipeNodeValidationInfoRecord);
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecord;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecord_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IUpdateRecipeNodeValidationInfoRecordFactory
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.Cluster.UpdateRecipeNodeValidationInfoRecord
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecordFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecordFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IUpdateRecipeNodeValidationInfoRecordFactory[] = L"Windows.Management.Update.Cluster.IUpdateRecipeNodeValidationInfoRecordFactory";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    MIDL_INTERFACE("e0fa2776-dd6c-5139-a93e-23e2188921af")
                    IUpdateRecipeNodeValidationInfoRecordFactory : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE CreateInstance(
                            HSTRING nodeName,
                            HSTRING recipeValidationInfo,
                            __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord* scanResults,
                            ABI::Windows::Management::Update::Cluster::IUpdateRecipeNodeValidationInfoRecord** value
                            ) = 0;
                    };

                    MIDL_CONST_ID IID& IID_IUpdateRecipeNodeValidationInfoRecordFactory = __uuidof(IUpdateRecipeNodeValidationInfoRecordFactory);
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecordFactory;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecordFactory_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IUpdateScanRecord
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.Cluster.UpdateScanRecord
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecord_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecord_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IUpdateScanRecord[] = L"Windows.Management.Update.Cluster.IUpdateScanRecord";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    MIDL_INTERFACE("c54af4fb-d316-5480-954f-d1eb51961de5")
                    IUpdateScanRecord : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE get_UpdateId(
                            HSTRING* value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_UpdateTitle(
                            HSTRING* value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_UpdateDescription(
                            HSTRING* value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_IsRebootRequired(
                            boolean* value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_PluginSpecificData(
                            HSTRING* value
                            ) = 0;
                    };

                    MIDL_CONST_ID IID& IID_IUpdateScanRecord = __uuidof(IUpdateScanRecord);
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecord;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecord_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IUpdateScanRecordFactory
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.Cluster.UpdateScanRecord
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecordFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecordFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IUpdateScanRecordFactory[] = L"Windows.Management.Update.Cluster.IUpdateScanRecordFactory";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    MIDL_INTERFACE("d9a3860e-a05a-58c3-b368-07bb350072d0")
                    IUpdateScanRecordFactory : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE CreateInstance(
                            HSTRING updateId,
                            HSTRING updateTitle,
                            HSTRING updateDescription,
                            boolean isRebootRequired,
                            HSTRING pluginSpecificData,
                            ABI::Windows::Management::Update::Cluster::IUpdateScanRecord** value
                            ) = 0;
                    };

                    MIDL_CONST_ID IID& IID_IUpdateScanRecordFactory = __uuidof(IUpdateScanRecordFactory);
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecordFactory;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecordFactory_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IUpdateStageRecord
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.Cluster.UpdateStageRecord
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecord_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecord_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IUpdateStageRecord[] = L"Windows.Management.Update.Cluster.IUpdateStageRecord";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    MIDL_INTERFACE("60d8edf9-eb18-59d1-badb-5d862f9352e9")
                    IUpdateStageRecord : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE get_UpdateId(
                            HSTRING* value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_Status(
                            ABI::Windows::Management::Update::Cluster::ClusterNativeUpdateCompletionStatus* value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_FailureMessage(
                            HSTRING* value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_UpdatedPluginSpecificData(
                            HSTRING* value
                            ) = 0;
                    };

                    MIDL_CONST_ID IID& IID_IUpdateStageRecord = __uuidof(IUpdateStageRecord);
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecord;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecord_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IUpdateStageRecordFactory
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.Cluster.UpdateStageRecord
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecordFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecordFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IUpdateStageRecordFactory[] = L"Windows.Management.Update.Cluster.IUpdateStageRecordFactory";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    MIDL_INTERFACE("b5c12a84-ebf5-505b-872f-4de71fdda7e8")
                    IUpdateStageRecordFactory : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE CreateInstance(
                            HSTRING updateId,
                            ABI::Windows::Management::Update::Cluster::ClusterNativeUpdateCompletionStatus status,
                            HSTRING failureMessage,
                            ABI::Windows::Management::Update::Cluster::IUpdateStageRecord** value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE CreateInstance2(
                            HSTRING updateId,
                            ABI::Windows::Management::Update::Cluster::ClusterNativeUpdateCompletionStatus status,
                            HSTRING failureMessage,
                            HSTRING updatedPluginSpecificData,
                            ABI::Windows::Management::Update::Cluster::IUpdateStageRecord** value
                            ) = 0;
                    };

                    MIDL_CONST_ID IID& IID_IUpdateStageRecordFactory = __uuidof(IUpdateStageRecordFactory);
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecordFactory;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecordFactory_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IUpdateTaskResult
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.Cluster.UpdateTaskResult
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResult_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResult_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IUpdateTaskResult[] = L"Windows.Management.Update.Cluster.IUpdateTaskResult";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    MIDL_INTERFACE("3fdd9274-7686-5cb9-89e4-6d618ed3a47a")
                    IUpdateTaskResult : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE get_Succeeded(
                            boolean* value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_Reason(
                            HSTRING* value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_ErrorCode(
                            INT32* value
                            ) = 0;
                    };

                    MIDL_CONST_ID IID& IID_IUpdateTaskResult = __uuidof(IUpdateTaskResult);
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResult;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResult_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IUpdateTaskResultFactory
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.Cluster.UpdateTaskResult
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResultFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResultFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IUpdateTaskResultFactory[] = L"Windows.Management.Update.Cluster.IUpdateTaskResultFactory";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    MIDL_INTERFACE("c5ae4ce3-7d1e-50bf-a64a-95f34783fc8c")
                    IUpdateTaskResultFactory : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE CreateInstance(
                            boolean succeeded,
                            HSTRING reason,
                            ABI::Windows::Management::Update::Cluster::IUpdateTaskResult** value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE CreateInstance2(
                            boolean succeeded,
                            HSTRING reason,
                            INT32 errorCode,
                            ABI::Windows::Management::Update::Cluster::IUpdateTaskResult** value
                            ) = 0;
                    };

                    MIDL_CONST_ID IID& IID_IUpdateTaskResultFactory = __uuidof(IUpdateTaskResultFactory);
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResultFactory;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResultFactory_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IUpdateValidationLogMessage
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.Cluster.UpdateValidationLogMessage
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessage_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessage_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IUpdateValidationLogMessage[] = L"Windows.Management.Update.Cluster.IUpdateValidationLogMessage";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    MIDL_INTERFACE("1e55bbd5-648f-584c-904d-ae6a053e80c8")
                    IUpdateValidationLogMessage : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE get_Severity(
                            ABI::Windows::Management::Update::Cluster::ClusterNativeUpdateLogLevel* value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_Message(
                            HSTRING* value
                            ) = 0;
                    };

                    MIDL_CONST_ID IID& IID_IUpdateValidationLogMessage = __uuidof(IUpdateValidationLogMessage);
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessage;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessage_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IUpdateValidationLogMessageFactory
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.Cluster.UpdateValidationLogMessage
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessageFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessageFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IUpdateValidationLogMessageFactory[] = L"Windows.Management.Update.Cluster.IUpdateValidationLogMessageFactory";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    MIDL_INTERFACE("9005a873-4c0b-5c78-a433-be5095b0226e")
                    IUpdateValidationLogMessageFactory : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE CreateInstance(
                            ABI::Windows::Management::Update::Cluster::ClusterNativeUpdateLogLevel severity,
                            HSTRING message,
                            ABI::Windows::Management::Update::Cluster::IUpdateValidationLogMessage** value
                            ) = 0;
                    };

                    MIDL_CONST_ID IID& IID_IUpdateValidationLogMessageFactory = __uuidof(IUpdateValidationLogMessageFactory);
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessageFactory;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessageFactory_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IValidateAllNodesUpdateRecipeResult
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.Cluster.ValidateAllNodesUpdateRecipeResult
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateAllNodesUpdateRecipeResult_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateAllNodesUpdateRecipeResult_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IValidateAllNodesUpdateRecipeResult[] = L"Windows.Management.Update.Cluster.IValidateAllNodesUpdateRecipeResult";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    MIDL_INTERFACE("4a6adcd4-b621-5ca6-b82e-6ce96d2a3b93")
                    IValidateAllNodesUpdateRecipeResult : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE get_Result(
                            ABI::Windows::Management::Update::Cluster::IUpdateTaskResult** value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_AreUpdatesApproved(
                            boolean* value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_ValidationMessages(
                            __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage** value
                            ) = 0;
                    };

                    MIDL_CONST_ID IID& IID_IValidateAllNodesUpdateRecipeResult = __uuidof(IValidateAllNodesUpdateRecipeResult);
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateAllNodesUpdateRecipeResult;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateAllNodesUpdateRecipeResult_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IValidateAllNodesUpdateRecipeResultFactory
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.Cluster.ValidateAllNodesUpdateRecipeResult
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateAllNodesUpdateRecipeResultFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateAllNodesUpdateRecipeResultFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IValidateAllNodesUpdateRecipeResultFactory[] = L"Windows.Management.Update.Cluster.IValidateAllNodesUpdateRecipeResultFactory";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    MIDL_INTERFACE("00a73e76-0643-5793-ba1c-6e7aa89fdba6")
                    IValidateAllNodesUpdateRecipeResultFactory : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE CreateInstance(
                            ABI::Windows::Management::Update::Cluster::IUpdateTaskResult* result,
                            boolean areUpdatesApproved,
                            __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage* validationMessages,
                            ABI::Windows::Management::Update::Cluster::IValidateAllNodesUpdateRecipeResult** value
                            ) = 0;
                    };

                    MIDL_CONST_ID IID& IID_IValidateAllNodesUpdateRecipeResultFactory = __uuidof(IValidateAllNodesUpdateRecipeResultFactory);
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateAllNodesUpdateRecipeResultFactory;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateAllNodesUpdateRecipeResultFactory_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IValidateClusterEnvironmentResult
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.Cluster.ValidateClusterEnvironmentResult
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateClusterEnvironmentResult_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateClusterEnvironmentResult_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IValidateClusterEnvironmentResult[] = L"Windows.Management.Update.Cluster.IValidateClusterEnvironmentResult";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    MIDL_INTERFACE("4df22928-9fde-5c16-961c-aab26f4a7780")
                    IValidateClusterEnvironmentResult : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE get_Result(
                            ABI::Windows::Management::Update::Cluster::IUpdateTaskResult** value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_ApprovalStatus(
                            ABI::Windows::Management::Update::Cluster::ClusterNativeUpdateEnvironmentValidationStatus* value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE get_ValidationMessages(
                            __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage** value
                            ) = 0;
                    };

                    MIDL_CONST_ID IID& IID_IValidateClusterEnvironmentResult = __uuidof(IValidateClusterEnvironmentResult);
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateClusterEnvironmentResult;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateClusterEnvironmentResult_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IValidateClusterEnvironmentResultFactory
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.Cluster.ValidateClusterEnvironmentResult
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateClusterEnvironmentResultFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateClusterEnvironmentResultFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IValidateClusterEnvironmentResultFactory[] = L"Windows.Management.Update.Cluster.IValidateClusterEnvironmentResultFactory";
namespace ABI {
    namespace Windows {
        namespace Management {
            namespace Update {
                namespace Cluster {
                    MIDL_INTERFACE("9222e2a5-7106-5dc4-860e-6634e47299fc")
                    IValidateClusterEnvironmentResultFactory : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE CreateInstance(
                            ABI::Windows::Management::Update::Cluster::IUpdateTaskResult* result,
                            ABI::Windows::Management::Update::Cluster::ClusterNativeUpdateEnvironmentValidationStatus approvalStatus,
                            __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage* validationMessages,
                            ABI::Windows::Management::Update::Cluster::IValidateClusterEnvironmentResult** value
                            ) = 0;
                    };

                    MIDL_CONST_ID IID& IID_IValidateClusterEnvironmentResultFactory = __uuidof(IValidateClusterEnvironmentResultFactory);
                } /* Cluster */
            } /* Update */
        } /* Management */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateClusterEnvironmentResultFactory;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateClusterEnvironmentResultFactory_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Management.Update.Cluster.AcquireEnvironmentInfoResult
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via the Windows.Management.Update.Cluster.IAcquireEnvironmentInfoResultFactory interface starting with version 1.0 of the Windows.Management.Update.Cluster.ClusterNativeUpdatingContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Management.Update.Cluster.IAcquireEnvironmentInfoResult ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Management_Update_Cluster_AcquireEnvironmentInfoResult_DEFINED
#define RUNTIMECLASS_Windows_Management_Update_Cluster_AcquireEnvironmentInfoResult_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Update_Cluster_AcquireEnvironmentInfoResult[] = L"Windows.Management.Update.Cluster.AcquireEnvironmentInfoResult";
#endif
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Management.Update.Cluster.AreRebootsPendingResult
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via the Windows.Management.Update.Cluster.IAreRebootsPendingResultFactory interface starting with version 1.0 of the Windows.Management.Update.Cluster.ClusterNativeUpdatingContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Management.Update.Cluster.IAreRebootsPendingResult ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Management_Update_Cluster_AreRebootsPendingResult_DEFINED
#define RUNTIMECLASS_Windows_Management_Update_Cluster_AreRebootsPendingResult_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Update_Cluster_AreRebootsPendingResult[] = L"Windows.Management.Update.Cluster.AreRebootsPendingResult";
#endif
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Management.Update.Cluster.ClusterUpdateServices
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * Class implements the following interfaces:
 *    Windows.Management.Update.Cluster.IClusterUpdateServices ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Management_Update_Cluster_ClusterUpdateServices_DEFINED
#define RUNTIMECLASS_Windows_Management_Update_Cluster_ClusterUpdateServices_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Update_Cluster_ClusterUpdateServices[] = L"Windows.Management.Update.Cluster.ClusterUpdateServices";
#endif
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Management.Update.Cluster.InstallUpdateTaskResult
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via the Windows.Management.Update.Cluster.IInstallUpdateTaskResultFactory interface starting with version 1.0 of the Windows.Management.Update.Cluster.ClusterNativeUpdatingContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Management.Update.Cluster.IInstallUpdateTaskResult ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Management_Update_Cluster_InstallUpdateTaskResult_DEFINED
#define RUNTIMECLASS_Windows_Management_Update_Cluster_InstallUpdateTaskResult_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Update_Cluster_InstallUpdateTaskResult[] = L"Windows.Management.Update.Cluster.InstallUpdateTaskResult";
#endif
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Management.Update.Cluster.RollbackUpdateTaskResult
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via the Windows.Management.Update.Cluster.IRollbackUpdateTaskResultFactory interface starting with version 1.0 of the Windows.Management.Update.Cluster.ClusterNativeUpdatingContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Management.Update.Cluster.IRollbackUpdateTaskResult ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Management_Update_Cluster_RollbackUpdateTaskResult_DEFINED
#define RUNTIMECLASS_Windows_Management_Update_Cluster_RollbackUpdateTaskResult_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Update_Cluster_RollbackUpdateTaskResult[] = L"Windows.Management.Update.Cluster.RollbackUpdateTaskResult";
#endif
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Management.Update.Cluster.ScanUpdateTaskResult
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via the Windows.Management.Update.Cluster.IScanUpdateTaskResultFactory interface starting with version 1.0 of the Windows.Management.Update.Cluster.ClusterNativeUpdatingContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Management.Update.Cluster.IScanUpdateTaskResult ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Management_Update_Cluster_ScanUpdateTaskResult_DEFINED
#define RUNTIMECLASS_Windows_Management_Update_Cluster_ScanUpdateTaskResult_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Update_Cluster_ScanUpdateTaskResult[] = L"Windows.Management.Update.Cluster.ScanUpdateTaskResult";
#endif
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Management.Update.Cluster.StageUpdateTaskResult
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via the Windows.Management.Update.Cluster.IStageUpdateTaskResultFactory interface starting with version 1.0 of the Windows.Management.Update.Cluster.ClusterNativeUpdatingContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Management.Update.Cluster.IStageUpdateTaskResult ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Management_Update_Cluster_StageUpdateTaskResult_DEFINED
#define RUNTIMECLASS_Windows_Management_Update_Cluster_StageUpdateTaskResult_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Update_Cluster_StageUpdateTaskResult[] = L"Windows.Management.Update.Cluster.StageUpdateTaskResult";
#endif
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Management.Update.Cluster.UpdateCredential
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via the Windows.Management.Update.Cluster.IUpdateCredentialFactory interface starting with version 1.0 of the Windows.Management.Update.Cluster.ClusterNativeUpdatingContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Management.Update.Cluster.IUpdateCredential ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Management_Update_Cluster_UpdateCredential_DEFINED
#define RUNTIMECLASS_Windows_Management_Update_Cluster_UpdateCredential_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Update_Cluster_UpdateCredential[] = L"Windows.Management.Update.Cluster.UpdateCredential";
#endif
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Management.Update.Cluster.UpdateInstallRecord
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via the Windows.Management.Update.Cluster.IUpdateInstallRecordFactory interface starting with version 1.0 of the Windows.Management.Update.Cluster.ClusterNativeUpdatingContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Management.Update.Cluster.IUpdateInstallRecord ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Management_Update_Cluster_UpdateInstallRecord_DEFINED
#define RUNTIMECLASS_Windows_Management_Update_Cluster_UpdateInstallRecord_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Update_Cluster_UpdateInstallRecord[] = L"Windows.Management.Update.Cluster.UpdateInstallRecord";
#endif
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Management.Update.Cluster.UpdateOperationResult
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via the Windows.Management.Update.Cluster.IUpdateOperationResultFactory interface starting with version 1.0 of the Windows.Management.Update.Cluster.ClusterNativeUpdatingContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Management.Update.Cluster.IUpdateOperationResult ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Management_Update_Cluster_UpdateOperationResult_DEFINED
#define RUNTIMECLASS_Windows_Management_Update_Cluster_UpdateOperationResult_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Update_Cluster_UpdateOperationResult[] = L"Windows.Management.Update.Cluster.UpdateOperationResult";
#endif
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Management.Update.Cluster.UpdatePendingOperationResult
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via the Windows.Management.Update.Cluster.IUpdatePendingOperationResultFactory interface starting with version 1.0 of the Windows.Management.Update.Cluster.ClusterNativeUpdatingContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Management.Update.Cluster.IUpdatePendingOperationResult ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Management_Update_Cluster_UpdatePendingOperationResult_DEFINED
#define RUNTIMECLASS_Windows_Management_Update_Cluster_UpdatePendingOperationResult_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Update_Cluster_UpdatePendingOperationResult[] = L"Windows.Management.Update.Cluster.UpdatePendingOperationResult";
#endif
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Management.Update.Cluster.UpdatePluginVersionInfo
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via the Windows.Management.Update.Cluster.IUpdatePluginVersionInfoFactory interface starting with version 1.0 of the Windows.Management.Update.Cluster.ClusterNativeUpdatingContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Management.Update.Cluster.IUpdatePluginVersionInfo ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Management_Update_Cluster_UpdatePluginVersionInfo_DEFINED
#define RUNTIMECLASS_Windows_Management_Update_Cluster_UpdatePluginVersionInfo_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Update_Cluster_UpdatePluginVersionInfo[] = L"Windows.Management.Update.Cluster.UpdatePluginVersionInfo";
#endif
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Management.Update.Cluster.UpdateRecipeNodeValidationInfoRecord
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via the Windows.Management.Update.Cluster.IUpdateRecipeNodeValidationInfoRecordFactory interface starting with version 1.0 of the Windows.Management.Update.Cluster.ClusterNativeUpdatingContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Management.Update.Cluster.IUpdateRecipeNodeValidationInfoRecord ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Management_Update_Cluster_UpdateRecipeNodeValidationInfoRecord_DEFINED
#define RUNTIMECLASS_Windows_Management_Update_Cluster_UpdateRecipeNodeValidationInfoRecord_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Update_Cluster_UpdateRecipeNodeValidationInfoRecord[] = L"Windows.Management.Update.Cluster.UpdateRecipeNodeValidationInfoRecord";
#endif
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Management.Update.Cluster.UpdateScanRecord
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via the Windows.Management.Update.Cluster.IUpdateScanRecordFactory interface starting with version 1.0 of the Windows.Management.Update.Cluster.ClusterNativeUpdatingContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Management.Update.Cluster.IUpdateScanRecord ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Management_Update_Cluster_UpdateScanRecord_DEFINED
#define RUNTIMECLASS_Windows_Management_Update_Cluster_UpdateScanRecord_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Update_Cluster_UpdateScanRecord[] = L"Windows.Management.Update.Cluster.UpdateScanRecord";
#endif
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Management.Update.Cluster.UpdateStageRecord
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via the Windows.Management.Update.Cluster.IUpdateStageRecordFactory interface starting with version 1.0 of the Windows.Management.Update.Cluster.ClusterNativeUpdatingContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Management.Update.Cluster.IUpdateStageRecord ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Management_Update_Cluster_UpdateStageRecord_DEFINED
#define RUNTIMECLASS_Windows_Management_Update_Cluster_UpdateStageRecord_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Update_Cluster_UpdateStageRecord[] = L"Windows.Management.Update.Cluster.UpdateStageRecord";
#endif
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Management.Update.Cluster.UpdateTaskResult
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via the Windows.Management.Update.Cluster.IUpdateTaskResultFactory interface starting with version 1.0 of the Windows.Management.Update.Cluster.ClusterNativeUpdatingContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Management.Update.Cluster.IUpdateTaskResult ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Management_Update_Cluster_UpdateTaskResult_DEFINED
#define RUNTIMECLASS_Windows_Management_Update_Cluster_UpdateTaskResult_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Update_Cluster_UpdateTaskResult[] = L"Windows.Management.Update.Cluster.UpdateTaskResult";
#endif
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Management.Update.Cluster.UpdateValidationLogMessage
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via the Windows.Management.Update.Cluster.IUpdateValidationLogMessageFactory interface starting with version 1.0 of the Windows.Management.Update.Cluster.ClusterNativeUpdatingContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Management.Update.Cluster.IUpdateValidationLogMessage ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Management_Update_Cluster_UpdateValidationLogMessage_DEFINED
#define RUNTIMECLASS_Windows_Management_Update_Cluster_UpdateValidationLogMessage_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Update_Cluster_UpdateValidationLogMessage[] = L"Windows.Management.Update.Cluster.UpdateValidationLogMessage";
#endif
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Management.Update.Cluster.ValidateAllNodesUpdateRecipeResult
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via the Windows.Management.Update.Cluster.IValidateAllNodesUpdateRecipeResultFactory interface starting with version 1.0 of the Windows.Management.Update.Cluster.ClusterNativeUpdatingContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Management.Update.Cluster.IValidateAllNodesUpdateRecipeResult ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Management_Update_Cluster_ValidateAllNodesUpdateRecipeResult_DEFINED
#define RUNTIMECLASS_Windows_Management_Update_Cluster_ValidateAllNodesUpdateRecipeResult_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Update_Cluster_ValidateAllNodesUpdateRecipeResult[] = L"Windows.Management.Update.Cluster.ValidateAllNodesUpdateRecipeResult";
#endif
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Management.Update.Cluster.ValidateClusterEnvironmentResult
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via the Windows.Management.Update.Cluster.IValidateClusterEnvironmentResultFactory interface starting with version 1.0 of the Windows.Management.Update.Cluster.ClusterNativeUpdatingContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Management.Update.Cluster.IValidateClusterEnvironmentResult ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Management_Update_Cluster_ValidateClusterEnvironmentResult_DEFINED
#define RUNTIMECLASS_Windows_Management_Update_Cluster_ValidateClusterEnvironmentResult_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Update_Cluster_ValidateClusterEnvironmentResult[] = L"Windows.Management.Update.Cluster.ValidateClusterEnvironmentResult";
#endif
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

#else // !defined(__cplusplus)
/* Forward Declarations */
#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAcquireEnvironmentInfoResult_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAcquireEnvironmentInfoResult_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAcquireEnvironmentInfoResult __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAcquireEnvironmentInfoResult;

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAcquireEnvironmentInfoResult_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAcquireEnvironmentInfoResultFactory_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAcquireEnvironmentInfoResultFactory_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAcquireEnvironmentInfoResultFactory __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAcquireEnvironmentInfoResultFactory;

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAcquireEnvironmentInfoResultFactory_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAreRebootsPendingResult_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAreRebootsPendingResult_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAreRebootsPendingResult __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAreRebootsPendingResult;

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAreRebootsPendingResult_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAreRebootsPendingResultFactory_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAreRebootsPendingResultFactory_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAreRebootsPendingResultFactory __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAreRebootsPendingResultFactory;

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAreRebootsPendingResultFactory_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperations_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperations_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperations __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperations;

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperations_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperationsPlugin_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperationsPlugin_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperationsPlugin __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperationsPlugin;

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperationsPlugin_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperations_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperations_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperations __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperations;

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperations_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperationsPlugin_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperationsPlugin_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperationsPlugin __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperationsPlugin;

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperationsPlugin_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterUpdateServices_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterUpdateServices_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterUpdateServices __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterUpdateServices;

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterUpdateServices_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIInstallUpdateTaskResult_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIInstallUpdateTaskResult_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIInstallUpdateTaskResult __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIInstallUpdateTaskResult;

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIInstallUpdateTaskResult_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIInstallUpdateTaskResultFactory_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIInstallUpdateTaskResultFactory_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIInstallUpdateTaskResultFactory __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIInstallUpdateTaskResultFactory;

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIInstallUpdateTaskResultFactory_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIRollbackUpdateTaskResult_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIRollbackUpdateTaskResult_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIRollbackUpdateTaskResult __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIRollbackUpdateTaskResult;

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIRollbackUpdateTaskResult_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIRollbackUpdateTaskResultFactory_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIRollbackUpdateTaskResultFactory_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIRollbackUpdateTaskResultFactory __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIRollbackUpdateTaskResultFactory;

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIRollbackUpdateTaskResultFactory_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIScanUpdateTaskResult_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIScanUpdateTaskResult_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIScanUpdateTaskResult __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIScanUpdateTaskResult;

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIScanUpdateTaskResult_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIScanUpdateTaskResultFactory_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIScanUpdateTaskResultFactory_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIScanUpdateTaskResultFactory __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIScanUpdateTaskResultFactory;

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIScanUpdateTaskResultFactory_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIStageUpdateTaskResult_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIStageUpdateTaskResult_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIStageUpdateTaskResult __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIStageUpdateTaskResult;

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIStageUpdateTaskResult_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIStageUpdateTaskResultFactory_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIStageUpdateTaskResultFactory_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIStageUpdateTaskResultFactory __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIStageUpdateTaskResultFactory;

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIStageUpdateTaskResultFactory_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateCredential_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateCredential_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateCredential __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateCredential;

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateCredential_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateCredentialFactory_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateCredentialFactory_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateCredentialFactory __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateCredentialFactory;

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateCredentialFactory_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecord_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecord_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecord __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecord;

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecord_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecordFactory_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecordFactory_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecordFactory __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecordFactory;

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecordFactory_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstaller_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstaller_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstaller __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstaller;

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstaller_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallerPlugin_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallerPlugin_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallerPlugin __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallerPlugin;

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallerPlugin_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResult_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResult_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResult __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResult;

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResult_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResultFactory_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResultFactory_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResultFactory __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResultFactory;

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResultFactory_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResult_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResult_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResult __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResult;

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResult_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResultFactory_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResultFactory_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResultFactory __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResultFactory;

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResultFactory_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfo_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfo_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfo __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfo;

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfo_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfoFactory_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfoFactory_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfoFactory __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfoFactory;

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfoFactory_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecord_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecord_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecord __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecord;

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecord_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecordFactory_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecordFactory_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecordFactory __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecordFactory;

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecordFactory_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecord_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecord_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecord __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecord;

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecord_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecordFactory_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecordFactory_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecordFactory __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecordFactory;

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecordFactory_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecord_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecord_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecord __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecord;

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecord_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecordFactory_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecordFactory_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecordFactory __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecordFactory;

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecordFactory_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResult_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResult_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResult __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResult;

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResult_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResultFactory_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResultFactory_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResultFactory __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResultFactory;

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResultFactory_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessage_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessage_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessage __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessage;

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessage_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessageFactory_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessageFactory_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessageFactory __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessageFactory;

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessageFactory_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateAllNodesUpdateRecipeResult_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateAllNodesUpdateRecipeResult_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateAllNodesUpdateRecipeResult __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateAllNodesUpdateRecipeResult;

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateAllNodesUpdateRecipeResult_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateAllNodesUpdateRecipeResultFactory_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateAllNodesUpdateRecipeResultFactory_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateAllNodesUpdateRecipeResultFactory __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateAllNodesUpdateRecipeResultFactory;

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateAllNodesUpdateRecipeResultFactory_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateClusterEnvironmentResult_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateClusterEnvironmentResult_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateClusterEnvironmentResult __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateClusterEnvironmentResult;

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateClusterEnvironmentResult_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateClusterEnvironmentResultFactory_FWD_DEFINED__
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateClusterEnvironmentResultFactory_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateClusterEnvironmentResultFactory __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateClusterEnvironmentResultFactory;

#endif // ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateClusterEnvironmentResultFactory_FWD_DEFINED__

// Parameterized interface forward declarations (C)

// Collection interface definitions

#if !defined(____FIKeyValuePair_2_HSTRING_HSTRING_INTERFACE_DEFINED__)
#define ____FIKeyValuePair_2_HSTRING_HSTRING_INTERFACE_DEFINED__

typedef interface __FIKeyValuePair_2_HSTRING_HSTRING __FIKeyValuePair_2_HSTRING_HSTRING;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIKeyValuePair_2_HSTRING_HSTRING;

typedef struct __FIKeyValuePair_2_HSTRING_HSTRINGVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIKeyValuePair_2_HSTRING_HSTRING* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIKeyValuePair_2_HSTRING_HSTRING* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIKeyValuePair_2_HSTRING_HSTRING* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIKeyValuePair_2_HSTRING_HSTRING* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIKeyValuePair_2_HSTRING_HSTRING* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIKeyValuePair_2_HSTRING_HSTRING* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Key)(__FIKeyValuePair_2_HSTRING_HSTRING* This,
        HSTRING* result);
    HRESULT (STDMETHODCALLTYPE* get_Value)(__FIKeyValuePair_2_HSTRING_HSTRING* This,
        HSTRING* result);

    END_INTERFACE
} __FIKeyValuePair_2_HSTRING_HSTRINGVtbl;

interface __FIKeyValuePair_2_HSTRING_HSTRING
{
    CONST_VTBL struct __FIKeyValuePair_2_HSTRING_HSTRINGVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIKeyValuePair_2_HSTRING_HSTRING_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIKeyValuePair_2_HSTRING_HSTRING_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIKeyValuePair_2_HSTRING_HSTRING_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIKeyValuePair_2_HSTRING_HSTRING_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIKeyValuePair_2_HSTRING_HSTRING_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIKeyValuePair_2_HSTRING_HSTRING_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIKeyValuePair_2_HSTRING_HSTRING_get_Key(This, result) \
    ((This)->lpVtbl->get_Key(This, result))

#define __FIKeyValuePair_2_HSTRING_HSTRING_get_Value(This, result) \
    ((This)->lpVtbl->get_Value(This, result))

#endif /* COBJMACROS */

#endif // ____FIKeyValuePair_2_HSTRING_HSTRING_INTERFACE_DEFINED__

#if !defined(____FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRING_INTERFACE_DEFINED__)
#define ____FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRING_INTERFACE_DEFINED__

typedef interface __FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRING __FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRING;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRING;

typedef struct __FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRINGVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRING* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRING* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRING* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRING* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRING* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRING* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Current)(__FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRING* This,
        __FIKeyValuePair_2_HSTRING_HSTRING** result);
    HRESULT (STDMETHODCALLTYPE* get_HasCurrent)(__FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRING* This,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* MoveNext)(__FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRING* This,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* GetMany)(__FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRING* This,
        UINT32 itemsLength,
        __FIKeyValuePair_2_HSTRING_HSTRING** items,
        UINT32* result);

    END_INTERFACE
} __FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRINGVtbl;

interface __FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRING
{
    CONST_VTBL struct __FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRINGVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRING_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRING_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRING_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRING_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRING_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRING_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRING_get_Current(This, result) \
    ((This)->lpVtbl->get_Current(This, result))

#define __FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRING_get_HasCurrent(This, result) \
    ((This)->lpVtbl->get_HasCurrent(This, result))

#define __FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRING_MoveNext(This, result) \
    ((This)->lpVtbl->MoveNext(This, result))

#define __FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRING_GetMany(This, itemsLength, items, result) \
    ((This)->lpVtbl->GetMany(This, itemsLength, items, result))

#endif /* COBJMACROS */

#endif // ____FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRING_INTERFACE_DEFINED__

#if !defined(____FIIterable_1___FIKeyValuePair_2_HSTRING_HSTRING_INTERFACE_DEFINED__)
#define ____FIIterable_1___FIKeyValuePair_2_HSTRING_HSTRING_INTERFACE_DEFINED__

typedef interface __FIIterable_1___FIKeyValuePair_2_HSTRING_HSTRING __FIIterable_1___FIKeyValuePair_2_HSTRING_HSTRING;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterable_1___FIKeyValuePair_2_HSTRING_HSTRING;

typedef struct __FIIterable_1___FIKeyValuePair_2_HSTRING_HSTRINGVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIIterable_1___FIKeyValuePair_2_HSTRING_HSTRING* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIIterable_1___FIKeyValuePair_2_HSTRING_HSTRING* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIIterable_1___FIKeyValuePair_2_HSTRING_HSTRING* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIIterable_1___FIKeyValuePair_2_HSTRING_HSTRING* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIIterable_1___FIKeyValuePair_2_HSTRING_HSTRING* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIIterable_1___FIKeyValuePair_2_HSTRING_HSTRING* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* First)(__FIIterable_1___FIKeyValuePair_2_HSTRING_HSTRING* This,
        __FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRING** result);

    END_INTERFACE
} __FIIterable_1___FIKeyValuePair_2_HSTRING_HSTRINGVtbl;

interface __FIIterable_1___FIKeyValuePair_2_HSTRING_HSTRING
{
    CONST_VTBL struct __FIIterable_1___FIKeyValuePair_2_HSTRING_HSTRINGVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIIterable_1___FIKeyValuePair_2_HSTRING_HSTRING_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIIterable_1___FIKeyValuePair_2_HSTRING_HSTRING_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIIterable_1___FIKeyValuePair_2_HSTRING_HSTRING_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIIterable_1___FIKeyValuePair_2_HSTRING_HSTRING_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIIterable_1___FIKeyValuePair_2_HSTRING_HSTRING_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIIterable_1___FIKeyValuePair_2_HSTRING_HSTRING_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIIterable_1___FIKeyValuePair_2_HSTRING_HSTRING_First(This, result) \
    ((This)->lpVtbl->First(This, result))

#endif /* COBJMACROS */

#endif // ____FIIterable_1___FIKeyValuePair_2_HSTRING_HSTRING_INTERFACE_DEFINED__

#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord_INTERFACE_DEFINED__)
#define ____FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord_INTERFACE_DEFINED__

typedef interface __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord;

typedef struct __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecordVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Current)(__FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord* This,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecord** result);
    HRESULT (STDMETHODCALLTYPE* get_HasCurrent)(__FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord* This,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* MoveNext)(__FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord* This,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* GetMany)(__FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord* This,
        UINT32 itemsLength,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecord** items,
        UINT32* result);

    END_INTERFACE
} __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecordVtbl;

interface __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord
{
    CONST_VTBL struct __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecordVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord_get_Current(This, result) \
    ((This)->lpVtbl->get_Current(This, result))

#define __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord_get_HasCurrent(This, result) \
    ((This)->lpVtbl->get_HasCurrent(This, result))

#define __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord_MoveNext(This, result) \
    ((This)->lpVtbl->MoveNext(This, result))

#define __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord_GetMany(This, itemsLength, items, result) \
    ((This)->lpVtbl->GetMany(This, itemsLength, items, result))

#endif /* COBJMACROS */

#endif // ____FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord_INTERFACE_DEFINED__
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord_INTERFACE_DEFINED__)
#define ____FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord_INTERFACE_DEFINED__

typedef interface __FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord __FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord;

typedef struct __FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecordVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* First)(__FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord* This,
        __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord** result);

    END_INTERFACE
} __FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecordVtbl;

interface __FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord
{
    CONST_VTBL struct __FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecordVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord_First(This, result) \
    ((This)->lpVtbl->First(This, result))

#endif /* COBJMACROS */

#endif // ____FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord_INTERFACE_DEFINED__
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord_INTERFACE_DEFINED__)
#define ____FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord_INTERFACE_DEFINED__

typedef interface __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord;

typedef struct __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecordVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Current)(__FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord* This,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecord** result);
    HRESULT (STDMETHODCALLTYPE* get_HasCurrent)(__FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord* This,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* MoveNext)(__FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord* This,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* GetMany)(__FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord* This,
        UINT32 itemsLength,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecord** items,
        UINT32* result);

    END_INTERFACE
} __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecordVtbl;

interface __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord
{
    CONST_VTBL struct __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecordVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord_get_Current(This, result) \
    ((This)->lpVtbl->get_Current(This, result))

#define __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord_get_HasCurrent(This, result) \
    ((This)->lpVtbl->get_HasCurrent(This, result))

#define __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord_MoveNext(This, result) \
    ((This)->lpVtbl->MoveNext(This, result))

#define __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord_GetMany(This, itemsLength, items, result) \
    ((This)->lpVtbl->GetMany(This, itemsLength, items, result))

#endif /* COBJMACROS */

#endif // ____FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord_INTERFACE_DEFINED__
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord_INTERFACE_DEFINED__)
#define ____FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord_INTERFACE_DEFINED__

typedef interface __FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord __FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord;

typedef struct __FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecordVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* First)(__FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord* This,
        __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord** result);

    END_INTERFACE
} __FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecordVtbl;

interface __FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord
{
    CONST_VTBL struct __FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecordVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord_First(This, result) \
    ((This)->lpVtbl->First(This, result))

#endif /* COBJMACROS */

#endif // ____FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord_INTERFACE_DEFINED__
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord_INTERFACE_DEFINED__)
#define ____FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord_INTERFACE_DEFINED__

typedef interface __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord;

typedef struct __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecordVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Current)(__FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord* This,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecord** result);
    HRESULT (STDMETHODCALLTYPE* get_HasCurrent)(__FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord* This,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* MoveNext)(__FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord* This,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* GetMany)(__FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord* This,
        UINT32 itemsLength,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecord** items,
        UINT32* result);

    END_INTERFACE
} __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecordVtbl;

interface __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord
{
    CONST_VTBL struct __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecordVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord_get_Current(This, result) \
    ((This)->lpVtbl->get_Current(This, result))

#define __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord_get_HasCurrent(This, result) \
    ((This)->lpVtbl->get_HasCurrent(This, result))

#define __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord_MoveNext(This, result) \
    ((This)->lpVtbl->MoveNext(This, result))

#define __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord_GetMany(This, itemsLength, items, result) \
    ((This)->lpVtbl->GetMany(This, itemsLength, items, result))

#endif /* COBJMACROS */

#endif // ____FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord_INTERFACE_DEFINED__
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord_INTERFACE_DEFINED__)
#define ____FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord_INTERFACE_DEFINED__

typedef interface __FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord __FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord;

typedef struct __FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecordVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* First)(__FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord* This,
        __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord** result);

    END_INTERFACE
} __FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecordVtbl;

interface __FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord
{
    CONST_VTBL struct __FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecordVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord_First(This, result) \
    ((This)->lpVtbl->First(This, result))

#endif /* COBJMACROS */

#endif // ____FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord_INTERFACE_DEFINED__
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord_INTERFACE_DEFINED__)
#define ____FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord_INTERFACE_DEFINED__

typedef interface __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord;

typedef struct __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecordVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Current)(__FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord* This,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecord** result);
    HRESULT (STDMETHODCALLTYPE* get_HasCurrent)(__FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord* This,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* MoveNext)(__FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord* This,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* GetMany)(__FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord* This,
        UINT32 itemsLength,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecord** items,
        UINT32* result);

    END_INTERFACE
} __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecordVtbl;

interface __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord
{
    CONST_VTBL struct __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecordVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord_get_Current(This, result) \
    ((This)->lpVtbl->get_Current(This, result))

#define __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord_get_HasCurrent(This, result) \
    ((This)->lpVtbl->get_HasCurrent(This, result))

#define __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord_MoveNext(This, result) \
    ((This)->lpVtbl->MoveNext(This, result))

#define __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord_GetMany(This, itemsLength, items, result) \
    ((This)->lpVtbl->GetMany(This, itemsLength, items, result))

#endif /* COBJMACROS */

#endif // ____FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord_INTERFACE_DEFINED__
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord_INTERFACE_DEFINED__)
#define ____FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord_INTERFACE_DEFINED__

typedef interface __FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord __FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord;

typedef struct __FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecordVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* First)(__FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord* This,
        __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord** result);

    END_INTERFACE
} __FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecordVtbl;

interface __FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord
{
    CONST_VTBL struct __FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecordVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord_First(This, result) \
    ((This)->lpVtbl->First(This, result))

#endif /* COBJMACROS */

#endif // ____FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord_INTERFACE_DEFINED__
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage_INTERFACE_DEFINED__)
#define ____FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage_INTERFACE_DEFINED__

typedef interface __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage;

typedef struct __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessageVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Current)(__FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage* This,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessage** result);
    HRESULT (STDMETHODCALLTYPE* get_HasCurrent)(__FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage* This,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* MoveNext)(__FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage* This,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* GetMany)(__FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage* This,
        UINT32 itemsLength,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessage** items,
        UINT32* result);

    END_INTERFACE
} __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessageVtbl;

interface __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage
{
    CONST_VTBL struct __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessageVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage_get_Current(This, result) \
    ((This)->lpVtbl->get_Current(This, result))

#define __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage_get_HasCurrent(This, result) \
    ((This)->lpVtbl->get_HasCurrent(This, result))

#define __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage_MoveNext(This, result) \
    ((This)->lpVtbl->MoveNext(This, result))

#define __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage_GetMany(This, itemsLength, items, result) \
    ((This)->lpVtbl->GetMany(This, itemsLength, items, result))

#endif /* COBJMACROS */

#endif // ____FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage_INTERFACE_DEFINED__
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage_INTERFACE_DEFINED__)
#define ____FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage_INTERFACE_DEFINED__

typedef interface __FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage __FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage;

typedef struct __FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessageVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* First)(__FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage* This,
        __FIIterator_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage** result);

    END_INTERFACE
} __FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessageVtbl;

interface __FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage
{
    CONST_VTBL struct __FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessageVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage_First(This, result) \
    ((This)->lpVtbl->First(This, result))

#endif /* COBJMACROS */

#endif // ____FIIterable_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage_INTERFACE_DEFINED__
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

typedef interface __FIMapView_2_HSTRING_HSTRING __FIMapView_2_HSTRING_HSTRING;

#if !defined(____FIMapView_2_HSTRING_HSTRING_INTERFACE_DEFINED__)
#define ____FIMapView_2_HSTRING_HSTRING_INTERFACE_DEFINED__

typedef interface __FIMapView_2_HSTRING_HSTRING __FIMapView_2_HSTRING_HSTRING;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIMapView_2_HSTRING_HSTRING;

typedef struct __FIMapView_2_HSTRING_HSTRINGVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIMapView_2_HSTRING_HSTRING* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIMapView_2_HSTRING_HSTRING* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIMapView_2_HSTRING_HSTRING* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIMapView_2_HSTRING_HSTRING* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIMapView_2_HSTRING_HSTRING* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIMapView_2_HSTRING_HSTRING* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* Lookup)(__FIMapView_2_HSTRING_HSTRING* This,
        HSTRING key,
        HSTRING* result);
    HRESULT (STDMETHODCALLTYPE* get_Size)(__FIMapView_2_HSTRING_HSTRING* This,
        UINT32* result);
    HRESULT (STDMETHODCALLTYPE* HasKey)(__FIMapView_2_HSTRING_HSTRING* This,
        HSTRING key,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* Split)(__FIMapView_2_HSTRING_HSTRING* This,
        __FIMapView_2_HSTRING_HSTRING** first,
        __FIMapView_2_HSTRING_HSTRING** second);

    END_INTERFACE
} __FIMapView_2_HSTRING_HSTRINGVtbl;

interface __FIMapView_2_HSTRING_HSTRING
{
    CONST_VTBL struct __FIMapView_2_HSTRING_HSTRINGVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIMapView_2_HSTRING_HSTRING_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIMapView_2_HSTRING_HSTRING_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIMapView_2_HSTRING_HSTRING_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIMapView_2_HSTRING_HSTRING_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIMapView_2_HSTRING_HSTRING_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIMapView_2_HSTRING_HSTRING_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIMapView_2_HSTRING_HSTRING_Lookup(This, key, result) \
    ((This)->lpVtbl->Lookup(This, key, result))

#define __FIMapView_2_HSTRING_HSTRING_get_Size(This, result) \
    ((This)->lpVtbl->get_Size(This, result))

#define __FIMapView_2_HSTRING_HSTRING_HasKey(This, key, result) \
    ((This)->lpVtbl->HasKey(This, key, result))

#define __FIMapView_2_HSTRING_HSTRING_Split(This, first, second) \
    ((This)->lpVtbl->Split(This, first, second))

#endif /* COBJMACROS */

#endif // ____FIMapView_2_HSTRING_HSTRING_INTERFACE_DEFINED__

#if !defined(____FIMap_2_HSTRING_HSTRING_INTERFACE_DEFINED__)
#define ____FIMap_2_HSTRING_HSTRING_INTERFACE_DEFINED__

typedef interface __FIMap_2_HSTRING_HSTRING __FIMap_2_HSTRING_HSTRING;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIMap_2_HSTRING_HSTRING;

typedef struct __FIMap_2_HSTRING_HSTRINGVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIMap_2_HSTRING_HSTRING* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIMap_2_HSTRING_HSTRING* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIMap_2_HSTRING_HSTRING* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIMap_2_HSTRING_HSTRING* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIMap_2_HSTRING_HSTRING* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIMap_2_HSTRING_HSTRING* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* Lookup)(__FIMap_2_HSTRING_HSTRING* This,
        HSTRING key,
        HSTRING* result);
    HRESULT (STDMETHODCALLTYPE* get_Size)(__FIMap_2_HSTRING_HSTRING* This,
        UINT32* result);
    HRESULT (STDMETHODCALLTYPE* HasKey)(__FIMap_2_HSTRING_HSTRING* This,
        HSTRING key,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* GetView)(__FIMap_2_HSTRING_HSTRING* This,
        __FIMapView_2_HSTRING_HSTRING** result);
    HRESULT (STDMETHODCALLTYPE* Insert)(__FIMap_2_HSTRING_HSTRING* This,
        HSTRING key,
        HSTRING value,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* Remove)(__FIMap_2_HSTRING_HSTRING* This,
        HSTRING key);
    HRESULT (STDMETHODCALLTYPE* Clear)(__FIMap_2_HSTRING_HSTRING* This);

    END_INTERFACE
} __FIMap_2_HSTRING_HSTRINGVtbl;

interface __FIMap_2_HSTRING_HSTRING
{
    CONST_VTBL struct __FIMap_2_HSTRING_HSTRINGVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIMap_2_HSTRING_HSTRING_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIMap_2_HSTRING_HSTRING_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIMap_2_HSTRING_HSTRING_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIMap_2_HSTRING_HSTRING_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIMap_2_HSTRING_HSTRING_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIMap_2_HSTRING_HSTRING_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIMap_2_HSTRING_HSTRING_Lookup(This, key, result) \
    ((This)->lpVtbl->Lookup(This, key, result))

#define __FIMap_2_HSTRING_HSTRING_get_Size(This, result) \
    ((This)->lpVtbl->get_Size(This, result))

#define __FIMap_2_HSTRING_HSTRING_HasKey(This, key, result) \
    ((This)->lpVtbl->HasKey(This, key, result))

#define __FIMap_2_HSTRING_HSTRING_GetView(This, result) \
    ((This)->lpVtbl->GetView(This, result))

#define __FIMap_2_HSTRING_HSTRING_Insert(This, key, value, result) \
    ((This)->lpVtbl->Insert(This, key, value, result))

#define __FIMap_2_HSTRING_HSTRING_Remove(This, key) \
    ((This)->lpVtbl->Remove(This, key))

#define __FIMap_2_HSTRING_HSTRING_Clear(This) \
    ((This)->lpVtbl->Clear(This))

#endif /* COBJMACROS */

#endif // ____FIMap_2_HSTRING_HSTRING_INTERFACE_DEFINED__

#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord_INTERFACE_DEFINED__)
#define ____FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord_INTERFACE_DEFINED__

typedef interface __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord;

typedef struct __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecordVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* GetAt)(__FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord* This,
        UINT32 index,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecord** result);
    HRESULT (STDMETHODCALLTYPE* get_Size)(__FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord* This,
        UINT32* result);
    HRESULT (STDMETHODCALLTYPE* IndexOf)(__FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord* This,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecord* value,
        UINT32* index,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* GetMany)(__FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord* This,
        UINT32 startIndex,
        UINT32 itemsLength,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecord** items,
        UINT32* result);

    END_INTERFACE
} __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecordVtbl;

interface __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord
{
    CONST_VTBL struct __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecordVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord_GetAt(This, index, result) \
    ((This)->lpVtbl->GetAt(This, index, result))

#define __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord_get_Size(This, result) \
    ((This)->lpVtbl->get_Size(This, result))

#define __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord_IndexOf(This, value, index, result) \
    ((This)->lpVtbl->IndexOf(This, value, index, result))

#define __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord_GetMany(This, startIndex, itemsLength, items, result) \
    ((This)->lpVtbl->GetMany(This, startIndex, itemsLength, items, result))

#endif /* COBJMACROS */

#endif // ____FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord_INTERFACE_DEFINED__
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord_INTERFACE_DEFINED__)
#define ____FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord_INTERFACE_DEFINED__

typedef interface __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord;

typedef struct __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecordVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* GetAt)(__FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord* This,
        UINT32 index,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecord** result);
    HRESULT (STDMETHODCALLTYPE* get_Size)(__FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord* This,
        UINT32* result);
    HRESULT (STDMETHODCALLTYPE* IndexOf)(__FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord* This,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecord* value,
        UINT32* index,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* GetMany)(__FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord* This,
        UINT32 startIndex,
        UINT32 itemsLength,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecord** items,
        UINT32* result);

    END_INTERFACE
} __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecordVtbl;

interface __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord
{
    CONST_VTBL struct __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecordVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord_GetAt(This, index, result) \
    ((This)->lpVtbl->GetAt(This, index, result))

#define __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord_get_Size(This, result) \
    ((This)->lpVtbl->get_Size(This, result))

#define __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord_IndexOf(This, value, index, result) \
    ((This)->lpVtbl->IndexOf(This, value, index, result))

#define __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord_GetMany(This, startIndex, itemsLength, items, result) \
    ((This)->lpVtbl->GetMany(This, startIndex, itemsLength, items, result))

#endif /* COBJMACROS */

#endif // ____FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord_INTERFACE_DEFINED__
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord_INTERFACE_DEFINED__)
#define ____FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord_INTERFACE_DEFINED__

typedef interface __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord;

typedef struct __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecordVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* GetAt)(__FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord* This,
        UINT32 index,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecord** result);
    HRESULT (STDMETHODCALLTYPE* get_Size)(__FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord* This,
        UINT32* result);
    HRESULT (STDMETHODCALLTYPE* IndexOf)(__FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord* This,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecord* value,
        UINT32* index,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* GetMany)(__FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord* This,
        UINT32 startIndex,
        UINT32 itemsLength,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecord** items,
        UINT32* result);

    END_INTERFACE
} __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecordVtbl;

interface __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord
{
    CONST_VTBL struct __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecordVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord_GetAt(This, index, result) \
    ((This)->lpVtbl->GetAt(This, index, result))

#define __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord_get_Size(This, result) \
    ((This)->lpVtbl->get_Size(This, result))

#define __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord_IndexOf(This, value, index, result) \
    ((This)->lpVtbl->IndexOf(This, value, index, result))

#define __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord_GetMany(This, startIndex, itemsLength, items, result) \
    ((This)->lpVtbl->GetMany(This, startIndex, itemsLength, items, result))

#endif /* COBJMACROS */

#endif // ____FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord_INTERFACE_DEFINED__
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord_INTERFACE_DEFINED__)
#define ____FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord_INTERFACE_DEFINED__

typedef interface __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord;

typedef struct __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecordVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* GetAt)(__FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord* This,
        UINT32 index,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecord** result);
    HRESULT (STDMETHODCALLTYPE* get_Size)(__FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord* This,
        UINT32* result);
    HRESULT (STDMETHODCALLTYPE* IndexOf)(__FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord* This,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecord* value,
        UINT32* index,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* GetMany)(__FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord* This,
        UINT32 startIndex,
        UINT32 itemsLength,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecord** items,
        UINT32* result);

    END_INTERFACE
} __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecordVtbl;

interface __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord
{
    CONST_VTBL struct __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecordVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord_GetAt(This, index, result) \
    ((This)->lpVtbl->GetAt(This, index, result))

#define __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord_get_Size(This, result) \
    ((This)->lpVtbl->get_Size(This, result))

#define __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord_IndexOf(This, value, index, result) \
    ((This)->lpVtbl->IndexOf(This, value, index, result))

#define __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord_GetMany(This, startIndex, itemsLength, items, result) \
    ((This)->lpVtbl->GetMany(This, startIndex, itemsLength, items, result))

#endif /* COBJMACROS */

#endif // ____FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord_INTERFACE_DEFINED__
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage_INTERFACE_DEFINED__)
#define ____FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage_INTERFACE_DEFINED__

typedef interface __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage;

typedef struct __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessageVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* GetAt)(__FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage* This,
        UINT32 index,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessage** result);
    HRESULT (STDMETHODCALLTYPE* get_Size)(__FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage* This,
        UINT32* result);
    HRESULT (STDMETHODCALLTYPE* IndexOf)(__FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage* This,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessage* value,
        UINT32* index,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* GetMany)(__FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage* This,
        UINT32 startIndex,
        UINT32 itemsLength,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessage** items,
        UINT32* result);

    END_INTERFACE
} __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessageVtbl;

interface __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage
{
    CONST_VTBL struct __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessageVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage_GetAt(This, index, result) \
    ((This)->lpVtbl->GetAt(This, index, result))

#define __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage_get_Size(This, result) \
    ((This)->lpVtbl->get_Size(This, result))

#define __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage_IndexOf(This, value, index, result) \
    ((This)->lpVtbl->IndexOf(This, value, index, result))

#define __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage_GetMany(This, startIndex, itemsLength, items, result) \
    ((This)->lpVtbl->GetMany(This, startIndex, itemsLength, items, result))

#endif /* COBJMACROS */

#endif // ____FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage_INTERFACE_DEFINED__
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

typedef struct __x_ABI_CWindows_CFoundation_CTimeSpan __x_ABI_CWindows_CFoundation_CTimeSpan;

typedef enum __x_ABI_CWindows_CManagement_CUpdate_CCluster_CClusterNativeUpdateCompletionStatus __x_ABI_CWindows_CManagement_CUpdate_CCluster_CClusterNativeUpdateCompletionStatus;

typedef enum __x_ABI_CWindows_CManagement_CUpdate_CCluster_CClusterNativeUpdateCredentialStatus __x_ABI_CWindows_CManagement_CUpdate_CCluster_CClusterNativeUpdateCredentialStatus;

typedef enum __x_ABI_CWindows_CManagement_CUpdate_CCluster_CClusterNativeUpdateEnvironmentValidationStatus __x_ABI_CWindows_CManagement_CUpdate_CCluster_CClusterNativeUpdateEnvironmentValidationStatus;

typedef enum __x_ABI_CWindows_CManagement_CUpdate_CCluster_CClusterNativeUpdateLogLevel __x_ABI_CWindows_CManagement_CUpdate_CCluster_CClusterNativeUpdateLogLevel;

typedef enum __x_ABI_CWindows_CManagement_CUpdate_CCluster_CClusterNativeUpdateOperationStatus __x_ABI_CWindows_CManagement_CUpdate_CCluster_CClusterNativeUpdateOperationStatus;

/*
 *
 * Struct Windows.Management.Update.Cluster.ClusterNativeUpdateCompletionStatus
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
enum __x_ABI_CWindows_CManagement_CUpdate_CCluster_CClusterNativeUpdateCompletionStatus
{
    ClusterNativeUpdateCompletionStatus_Completed = 0,
    ClusterNativeUpdateCompletionStatus_Failed = 1,
    ClusterNativeUpdateCompletionStatus_Canceled = 2,
};
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Struct Windows.Management.Update.Cluster.ClusterNativeUpdateCredentialStatus
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
enum __x_ABI_CWindows_CManagement_CUpdate_CCluster_CClusterNativeUpdateCredentialStatus
{
    ClusterNativeUpdateCredentialStatus_Success = 0,
    ClusterNativeUpdateCredentialStatus_NoSuchCredential = 1,
    ClusterNativeUpdateCredentialStatus_ErrorRetrievingCredential = 2,
};
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Struct Windows.Management.Update.Cluster.ClusterNativeUpdateEnvironmentValidationStatus
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
enum __x_ABI_CWindows_CManagement_CUpdate_CCluster_CClusterNativeUpdateEnvironmentValidationStatus
{
    ClusterNativeUpdateEnvironmentValidationStatus_Approved = 0,
    ClusterNativeUpdateEnvironmentValidationStatus_ApprovedWithWarnings = 1,
    ClusterNativeUpdateEnvironmentValidationStatus_Rejected = 2,
};
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Struct Windows.Management.Update.Cluster.ClusterNativeUpdateLogLevel
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
enum __x_ABI_CWindows_CManagement_CUpdate_CCluster_CClusterNativeUpdateLogLevel
{
    ClusterNativeUpdateLogLevel_Debug = 0,
    ClusterNativeUpdateLogLevel_Verbose = 1,
    ClusterNativeUpdateLogLevel_Info = 2,
    ClusterNativeUpdateLogLevel_Warning = 3,
    ClusterNativeUpdateLogLevel_Error = 4,
};
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Struct Windows.Management.Update.Cluster.ClusterNativeUpdateOperationStatus
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
enum __x_ABI_CWindows_CManagement_CUpdate_CCluster_CClusterNativeUpdateOperationStatus
{
    ClusterNativeUpdateOperationStatus_Success = 0,
    ClusterNativeUpdateOperationStatus_Failed = 1,
    ClusterNativeUpdateOperationStatus_Pending = 2,
    ClusterNativeUpdateOperationStatus_Canceled = 3,
};
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IAcquireEnvironmentInfoResult
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.Cluster.AcquireEnvironmentInfoResult
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAcquireEnvironmentInfoResult_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAcquireEnvironmentInfoResult_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IAcquireEnvironmentInfoResult[] = L"Windows.Management.Update.Cluster.IAcquireEnvironmentInfoResult";
typedef struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAcquireEnvironmentInfoResultVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAcquireEnvironmentInfoResult* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAcquireEnvironmentInfoResult* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAcquireEnvironmentInfoResult* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAcquireEnvironmentInfoResult* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAcquireEnvironmentInfoResult* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAcquireEnvironmentInfoResult* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Result)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAcquireEnvironmentInfoResult* This,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResult** value);
    HRESULT (STDMETHODCALLTYPE* get_EnvironmentInfo)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAcquireEnvironmentInfoResult* This,
        HSTRING* value);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAcquireEnvironmentInfoResultVtbl;

interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAcquireEnvironmentInfoResult
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAcquireEnvironmentInfoResultVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAcquireEnvironmentInfoResult_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAcquireEnvironmentInfoResult_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAcquireEnvironmentInfoResult_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAcquireEnvironmentInfoResult_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAcquireEnvironmentInfoResult_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAcquireEnvironmentInfoResult_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAcquireEnvironmentInfoResult_get_Result(This, value) \
    ((This)->lpVtbl->get_Result(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAcquireEnvironmentInfoResult_get_EnvironmentInfo(This, value) \
    ((This)->lpVtbl->get_EnvironmentInfo(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAcquireEnvironmentInfoResult;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAcquireEnvironmentInfoResult_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IAcquireEnvironmentInfoResultFactory
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.Cluster.AcquireEnvironmentInfoResult
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAcquireEnvironmentInfoResultFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAcquireEnvironmentInfoResultFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IAcquireEnvironmentInfoResultFactory[] = L"Windows.Management.Update.Cluster.IAcquireEnvironmentInfoResultFactory";
typedef struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAcquireEnvironmentInfoResultFactoryVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAcquireEnvironmentInfoResultFactory* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAcquireEnvironmentInfoResultFactory* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAcquireEnvironmentInfoResultFactory* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAcquireEnvironmentInfoResultFactory* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAcquireEnvironmentInfoResultFactory* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAcquireEnvironmentInfoResultFactory* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* CreateInstance)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAcquireEnvironmentInfoResultFactory* This,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResult* result,
        HSTRING environmentInfo,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAcquireEnvironmentInfoResult** value);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAcquireEnvironmentInfoResultFactoryVtbl;

interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAcquireEnvironmentInfoResultFactory
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAcquireEnvironmentInfoResultFactoryVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAcquireEnvironmentInfoResultFactory_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAcquireEnvironmentInfoResultFactory_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAcquireEnvironmentInfoResultFactory_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAcquireEnvironmentInfoResultFactory_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAcquireEnvironmentInfoResultFactory_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAcquireEnvironmentInfoResultFactory_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAcquireEnvironmentInfoResultFactory_CreateInstance(This, result, environmentInfo, value) \
    ((This)->lpVtbl->CreateInstance(This, result, environmentInfo, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAcquireEnvironmentInfoResultFactory;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAcquireEnvironmentInfoResultFactory_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IAreRebootsPendingResult
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.Cluster.AreRebootsPendingResult
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAreRebootsPendingResult_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAreRebootsPendingResult_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IAreRebootsPendingResult[] = L"Windows.Management.Update.Cluster.IAreRebootsPendingResult";
typedef struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAreRebootsPendingResultVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAreRebootsPendingResult* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAreRebootsPendingResult* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAreRebootsPendingResult* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAreRebootsPendingResult* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAreRebootsPendingResult* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAreRebootsPendingResult* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Result)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAreRebootsPendingResult* This,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResult** value);
    HRESULT (STDMETHODCALLTYPE* get_IsRebootPending)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAreRebootsPendingResult* This,
        boolean* value);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAreRebootsPendingResultVtbl;

interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAreRebootsPendingResult
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAreRebootsPendingResultVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAreRebootsPendingResult_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAreRebootsPendingResult_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAreRebootsPendingResult_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAreRebootsPendingResult_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAreRebootsPendingResult_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAreRebootsPendingResult_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAreRebootsPendingResult_get_Result(This, value) \
    ((This)->lpVtbl->get_Result(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAreRebootsPendingResult_get_IsRebootPending(This, value) \
    ((This)->lpVtbl->get_IsRebootPending(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAreRebootsPendingResult;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAreRebootsPendingResult_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IAreRebootsPendingResultFactory
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.Cluster.AreRebootsPendingResult
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAreRebootsPendingResultFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAreRebootsPendingResultFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IAreRebootsPendingResultFactory[] = L"Windows.Management.Update.Cluster.IAreRebootsPendingResultFactory";
typedef struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAreRebootsPendingResultFactoryVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAreRebootsPendingResultFactory* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAreRebootsPendingResultFactory* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAreRebootsPendingResultFactory* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAreRebootsPendingResultFactory* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAreRebootsPendingResultFactory* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAreRebootsPendingResultFactory* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* CreateInstance)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAreRebootsPendingResultFactory* This,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResult* result,
        boolean isRebootPending,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAreRebootsPendingResult** value);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAreRebootsPendingResultFactoryVtbl;

interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAreRebootsPendingResultFactory
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAreRebootsPendingResultFactoryVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAreRebootsPendingResultFactory_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAreRebootsPendingResultFactory_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAreRebootsPendingResultFactory_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAreRebootsPendingResultFactory_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAreRebootsPendingResultFactory_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAreRebootsPendingResultFactory_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAreRebootsPendingResultFactory_CreateInstance(This, result, isRebootPending, value) \
    ((This)->lpVtbl->CreateInstance(This, result, isRebootPending, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAreRebootsPendingResultFactory;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAreRebootsPendingResultFactory_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IClusterNativeEnvironmentOperations
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperations_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperations_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IClusterNativeEnvironmentOperations[] = L"Windows.Management.Update.Cluster.IClusterNativeEnvironmentOperations";
typedef struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperationsVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperations* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperations* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperations* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperations* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperations* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperations* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* AcquireNodeEnvironmentInfo)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperations* This,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAcquireEnvironmentInfoResult** result);
    HRESULT (STDMETHODCALLTYPE* ValidateClusterEnvironment)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperations* This,
        __FIMapView_2_HSTRING_HSTRING* nodeEnvironmentInfo,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateClusterEnvironmentResult** result);
    HRESULT (STDMETHODCALLTYPE* StartPreUpdateRunOperation)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperations* This,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResult** result);
    HRESULT (STDMETHODCALLTYPE* IsPreUpdateRunOperationComplete)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperations* This,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResult** result);
    HRESULT (STDMETHODCALLTYPE* StartPostUpdateRunOperation)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperations* This,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResult** result);
    HRESULT (STDMETHODCALLTYPE* IsPostUpdateRunOperationComplete)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperations* This,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResult** result);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperationsVtbl;

interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperations
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperationsVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperations_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperations_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperations_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperations_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperations_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperations_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperations_AcquireNodeEnvironmentInfo(This, result) \
    ((This)->lpVtbl->AcquireNodeEnvironmentInfo(This, result))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperations_ValidateClusterEnvironment(This, nodeEnvironmentInfo, result) \
    ((This)->lpVtbl->ValidateClusterEnvironment(This, nodeEnvironmentInfo, result))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperations_StartPreUpdateRunOperation(This, result) \
    ((This)->lpVtbl->StartPreUpdateRunOperation(This, result))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperations_IsPreUpdateRunOperationComplete(This, result) \
    ((This)->lpVtbl->IsPreUpdateRunOperationComplete(This, result))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperations_StartPostUpdateRunOperation(This, result) \
    ((This)->lpVtbl->StartPostUpdateRunOperation(This, result))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperations_IsPostUpdateRunOperationComplete(This, result) \
    ((This)->lpVtbl->IsPostUpdateRunOperationComplete(This, result))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperations;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperations_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IClusterNativeEnvironmentOperationsPlugin
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperationsPlugin_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperationsPlugin_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IClusterNativeEnvironmentOperationsPlugin[] = L"Windows.Management.Update.Cluster.IClusterNativeEnvironmentOperationsPlugin";
typedef struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperationsPluginVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperationsPlugin* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperationsPlugin* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperationsPlugin* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperationsPlugin* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperationsPlugin* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperationsPlugin* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Name)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperationsPlugin* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* get_FriendlyName)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperationsPlugin* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* get_Description)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperationsPlugin* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* get_Version)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperationsPlugin* This,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfo** value);
    HRESULT (STDMETHODCALLTYPE* get_DefaultOptions)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperationsPlugin* This,
        __FIMapView_2_HSTRING_HSTRING** value);
    HRESULT (STDMETHODCALLTYPE* CreateEnvironmentOperations)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperationsPlugin* This,
        HSTRING clusterName,
        HSTRING runId,
        __FIMap_2_HSTRING_HSTRING* options,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterUpdateServices* updateServices,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperations** result);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperationsPluginVtbl;

interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperationsPlugin
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperationsPluginVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperationsPlugin_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperationsPlugin_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperationsPlugin_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperationsPlugin_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperationsPlugin_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperationsPlugin_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperationsPlugin_get_Name(This, value) \
    ((This)->lpVtbl->get_Name(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperationsPlugin_get_FriendlyName(This, value) \
    ((This)->lpVtbl->get_FriendlyName(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperationsPlugin_get_Description(This, value) \
    ((This)->lpVtbl->get_Description(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperationsPlugin_get_Version(This, value) \
    ((This)->lpVtbl->get_Version(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperationsPlugin_get_DefaultOptions(This, value) \
    ((This)->lpVtbl->get_DefaultOptions(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperationsPlugin_CreateEnvironmentOperations(This, clusterName, runId, options, updateServices, result) \
    ((This)->lpVtbl->CreateEnvironmentOperations(This, clusterName, runId, options, updateServices, result))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperationsPlugin;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeEnvironmentOperationsPlugin_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IClusterNativeNodeOperations
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperations_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperations_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IClusterNativeNodeOperations[] = L"Windows.Management.Update.Cluster.IClusterNativeNodeOperations";
typedef struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperationsVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperations* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperations* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperations* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperations* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperations* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperations* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* AreAdditionalRebootsPending)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperations* This,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIAreRebootsPendingResult** result);
    HRESULT (STDMETHODCALLTYPE* StartPreRebootOperation)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperations* This,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResult** result);
    HRESULT (STDMETHODCALLTYPE* IsPreRebootOperationComplete)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperations* This,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResult** result);
    HRESULT (STDMETHODCALLTYPE* StartPostRebootOperation)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperations* This,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResult** result);
    HRESULT (STDMETHODCALLTYPE* IsPostRebootOperationComplete)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperations* This,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResult** result);
    HRESULT (STDMETHODCALLTYPE* StartPreDrainOperation)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperations* This,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResult** result);
    HRESULT (STDMETHODCALLTYPE* IsPreDrainOperationComplete)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperations* This,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResult** result);
    HRESULT (STDMETHODCALLTYPE* StartPostResumeOperation)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperations* This,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResult** result);
    HRESULT (STDMETHODCALLTYPE* IsPostResumeOperationComplete)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperations* This,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResult** result);
    HRESULT (STDMETHODCALLTYPE* StartPreUpdateRunOperation)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperations* This,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResult** result);
    HRESULT (STDMETHODCALLTYPE* IsPreUpdateRunOperationComplete)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperations* This,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResult** result);
    HRESULT (STDMETHODCALLTYPE* StartPostUpdateRunOperation)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperations* This,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResult** result);
    HRESULT (STDMETHODCALLTYPE* IsPostUpdateRunOperationComplete)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperations* This,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResult** result);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperationsVtbl;

interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperations
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperationsVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperations_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperations_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperations_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperations_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperations_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperations_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperations_AreAdditionalRebootsPending(This, result) \
    ((This)->lpVtbl->AreAdditionalRebootsPending(This, result))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperations_StartPreRebootOperation(This, result) \
    ((This)->lpVtbl->StartPreRebootOperation(This, result))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperations_IsPreRebootOperationComplete(This, result) \
    ((This)->lpVtbl->IsPreRebootOperationComplete(This, result))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperations_StartPostRebootOperation(This, result) \
    ((This)->lpVtbl->StartPostRebootOperation(This, result))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperations_IsPostRebootOperationComplete(This, result) \
    ((This)->lpVtbl->IsPostRebootOperationComplete(This, result))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperations_StartPreDrainOperation(This, result) \
    ((This)->lpVtbl->StartPreDrainOperation(This, result))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperations_IsPreDrainOperationComplete(This, result) \
    ((This)->lpVtbl->IsPreDrainOperationComplete(This, result))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperations_StartPostResumeOperation(This, result) \
    ((This)->lpVtbl->StartPostResumeOperation(This, result))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperations_IsPostResumeOperationComplete(This, result) \
    ((This)->lpVtbl->IsPostResumeOperationComplete(This, result))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperations_StartPreUpdateRunOperation(This, result) \
    ((This)->lpVtbl->StartPreUpdateRunOperation(This, result))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperations_IsPreUpdateRunOperationComplete(This, result) \
    ((This)->lpVtbl->IsPreUpdateRunOperationComplete(This, result))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperations_StartPostUpdateRunOperation(This, result) \
    ((This)->lpVtbl->StartPostUpdateRunOperation(This, result))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperations_IsPostUpdateRunOperationComplete(This, result) \
    ((This)->lpVtbl->IsPostUpdateRunOperationComplete(This, result))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperations;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperations_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IClusterNativeNodeOperationsPlugin
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperationsPlugin_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperationsPlugin_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IClusterNativeNodeOperationsPlugin[] = L"Windows.Management.Update.Cluster.IClusterNativeNodeOperationsPlugin";
typedef struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperationsPluginVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperationsPlugin* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperationsPlugin* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperationsPlugin* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperationsPlugin* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperationsPlugin* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperationsPlugin* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Name)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperationsPlugin* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* get_FriendlyName)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperationsPlugin* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* get_Description)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperationsPlugin* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* get_Version)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperationsPlugin* This,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfo** value);
    HRESULT (STDMETHODCALLTYPE* get_DefaultOptions)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperationsPlugin* This,
        __FIMapView_2_HSTRING_HSTRING** value);
    HRESULT (STDMETHODCALLTYPE* CreateNodeOperations)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperationsPlugin* This,
        HSTRING clusterName,
        HSTRING runId,
        __FIMap_2_HSTRING_HSTRING* options,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterUpdateServices* updateServices,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperations** result);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperationsPluginVtbl;

interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperationsPlugin
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperationsPluginVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperationsPlugin_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperationsPlugin_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperationsPlugin_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperationsPlugin_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperationsPlugin_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperationsPlugin_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperationsPlugin_get_Name(This, value) \
    ((This)->lpVtbl->get_Name(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperationsPlugin_get_FriendlyName(This, value) \
    ((This)->lpVtbl->get_FriendlyName(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperationsPlugin_get_Description(This, value) \
    ((This)->lpVtbl->get_Description(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperationsPlugin_get_Version(This, value) \
    ((This)->lpVtbl->get_Version(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperationsPlugin_get_DefaultOptions(This, value) \
    ((This)->lpVtbl->get_DefaultOptions(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperationsPlugin_CreateNodeOperations(This, clusterName, runId, options, updateServices, result) \
    ((This)->lpVtbl->CreateNodeOperations(This, clusterName, runId, options, updateServices, result))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperationsPlugin;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterNativeNodeOperationsPlugin_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IClusterUpdateServices
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.Cluster.ClusterUpdateServices
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterUpdateServices_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterUpdateServices_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IClusterUpdateServices[] = L"Windows.Management.Update.Cluster.IClusterUpdateServices";
typedef struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterUpdateServicesVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterUpdateServices* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterUpdateServices* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterUpdateServices* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterUpdateServices* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterUpdateServices* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterUpdateServices* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* WriteLogEntry)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterUpdateServices* This,
        enum __x_ABI_CWindows_CManagement_CUpdate_CCluster_CClusterNativeUpdateLogLevel level,
        HSTRING message);
    HRESULT (STDMETHODCALLTYPE* ReportProgress)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterUpdateServices* This,
        INT32 currentStep,
        INT32 maxSteps,
        HSTRING message);
    HRESULT (STDMETHODCALLTYPE* GetPluginCredential)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterUpdateServices* This,
        HSTRING credentialId,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateCredential** result);
    HRESULT (STDMETHODCALLTYPE* IsOperationMarkedAsCanceled)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterUpdateServices* This,
        boolean* result);
    HRESULT (STDMETHODCALLTYPE* SaveRunStateInformation)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterUpdateServices* This,
        HSTRING persistentInformation);
    HRESULT (STDMETHODCALLTYPE* GetRunStateInformation)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterUpdateServices* This,
        HSTRING* result);
    HRESULT (STDMETHODCALLTYPE* SaveRunIndependentInformation)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterUpdateServices* This,
        HSTRING persistentInformation);
    HRESULT (STDMETHODCALLTYPE* GetRunIndependentInformation)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterUpdateServices* This,
        HSTRING* result);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterUpdateServicesVtbl;

interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterUpdateServices
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterUpdateServicesVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterUpdateServices_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterUpdateServices_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterUpdateServices_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterUpdateServices_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterUpdateServices_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterUpdateServices_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterUpdateServices_WriteLogEntry(This, level, message) \
    ((This)->lpVtbl->WriteLogEntry(This, level, message))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterUpdateServices_ReportProgress(This, currentStep, maxSteps, message) \
    ((This)->lpVtbl->ReportProgress(This, currentStep, maxSteps, message))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterUpdateServices_GetPluginCredential(This, credentialId, result) \
    ((This)->lpVtbl->GetPluginCredential(This, credentialId, result))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterUpdateServices_IsOperationMarkedAsCanceled(This, result) \
    ((This)->lpVtbl->IsOperationMarkedAsCanceled(This, result))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterUpdateServices_SaveRunStateInformation(This, persistentInformation) \
    ((This)->lpVtbl->SaveRunStateInformation(This, persistentInformation))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterUpdateServices_GetRunStateInformation(This, result) \
    ((This)->lpVtbl->GetRunStateInformation(This, result))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterUpdateServices_SaveRunIndependentInformation(This, persistentInformation) \
    ((This)->lpVtbl->SaveRunIndependentInformation(This, persistentInformation))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterUpdateServices_GetRunIndependentInformation(This, result) \
    ((This)->lpVtbl->GetRunIndependentInformation(This, result))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterUpdateServices;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterUpdateServices_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IInstallUpdateTaskResult
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.Cluster.InstallUpdateTaskResult
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIInstallUpdateTaskResult_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIInstallUpdateTaskResult_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IInstallUpdateTaskResult[] = L"Windows.Management.Update.Cluster.IInstallUpdateTaskResult";
typedef struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIInstallUpdateTaskResultVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIInstallUpdateTaskResult* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIInstallUpdateTaskResult* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIInstallUpdateTaskResult* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIInstallUpdateTaskResult* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIInstallUpdateTaskResult* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIInstallUpdateTaskResult* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Result)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIInstallUpdateTaskResult* This,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResult** value);
    HRESULT (STDMETHODCALLTYPE* get_InstallRecords)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIInstallUpdateTaskResult* This,
        __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord** value);
    HRESULT (STDMETHODCALLTYPE* get_ShouldRollback)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIInstallUpdateTaskResult* This,
        boolean* value);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIInstallUpdateTaskResultVtbl;

interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIInstallUpdateTaskResult
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIInstallUpdateTaskResultVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIInstallUpdateTaskResult_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIInstallUpdateTaskResult_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIInstallUpdateTaskResult_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIInstallUpdateTaskResult_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIInstallUpdateTaskResult_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIInstallUpdateTaskResult_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIInstallUpdateTaskResult_get_Result(This, value) \
    ((This)->lpVtbl->get_Result(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIInstallUpdateTaskResult_get_InstallRecords(This, value) \
    ((This)->lpVtbl->get_InstallRecords(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIInstallUpdateTaskResult_get_ShouldRollback(This, value) \
    ((This)->lpVtbl->get_ShouldRollback(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIInstallUpdateTaskResult;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIInstallUpdateTaskResult_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IInstallUpdateTaskResultFactory
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.Cluster.InstallUpdateTaskResult
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIInstallUpdateTaskResultFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIInstallUpdateTaskResultFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IInstallUpdateTaskResultFactory[] = L"Windows.Management.Update.Cluster.IInstallUpdateTaskResultFactory";
typedef struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIInstallUpdateTaskResultFactoryVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIInstallUpdateTaskResultFactory* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIInstallUpdateTaskResultFactory* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIInstallUpdateTaskResultFactory* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIInstallUpdateTaskResultFactory* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIInstallUpdateTaskResultFactory* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIInstallUpdateTaskResultFactory* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* CreateInstance)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIInstallUpdateTaskResultFactory* This,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResult* result,
        __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord* installRecords,
        boolean shouldRollback,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIInstallUpdateTaskResult** value);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIInstallUpdateTaskResultFactoryVtbl;

interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIInstallUpdateTaskResultFactory
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIInstallUpdateTaskResultFactoryVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIInstallUpdateTaskResultFactory_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIInstallUpdateTaskResultFactory_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIInstallUpdateTaskResultFactory_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIInstallUpdateTaskResultFactory_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIInstallUpdateTaskResultFactory_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIInstallUpdateTaskResultFactory_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIInstallUpdateTaskResultFactory_CreateInstance(This, result, installRecords, shouldRollback, value) \
    ((This)->lpVtbl->CreateInstance(This, result, installRecords, shouldRollback, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIInstallUpdateTaskResultFactory;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIInstallUpdateTaskResultFactory_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IRollbackUpdateTaskResult
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.Cluster.RollbackUpdateTaskResult
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIRollbackUpdateTaskResult_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIRollbackUpdateTaskResult_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IRollbackUpdateTaskResult[] = L"Windows.Management.Update.Cluster.IRollbackUpdateTaskResult";
typedef struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIRollbackUpdateTaskResultVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIRollbackUpdateTaskResult* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIRollbackUpdateTaskResult* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIRollbackUpdateTaskResult* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIRollbackUpdateTaskResult* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIRollbackUpdateTaskResult* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIRollbackUpdateTaskResult* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Result)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIRollbackUpdateTaskResult* This,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResult** value);
    HRESULT (STDMETHODCALLTYPE* get_InstallRecords)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIRollbackUpdateTaskResult* This,
        __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord** value);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIRollbackUpdateTaskResultVtbl;

interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIRollbackUpdateTaskResult
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIRollbackUpdateTaskResultVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIRollbackUpdateTaskResult_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIRollbackUpdateTaskResult_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIRollbackUpdateTaskResult_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIRollbackUpdateTaskResult_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIRollbackUpdateTaskResult_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIRollbackUpdateTaskResult_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIRollbackUpdateTaskResult_get_Result(This, value) \
    ((This)->lpVtbl->get_Result(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIRollbackUpdateTaskResult_get_InstallRecords(This, value) \
    ((This)->lpVtbl->get_InstallRecords(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIRollbackUpdateTaskResult;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIRollbackUpdateTaskResult_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IRollbackUpdateTaskResultFactory
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.Cluster.RollbackUpdateTaskResult
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIRollbackUpdateTaskResultFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIRollbackUpdateTaskResultFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IRollbackUpdateTaskResultFactory[] = L"Windows.Management.Update.Cluster.IRollbackUpdateTaskResultFactory";
typedef struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIRollbackUpdateTaskResultFactoryVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIRollbackUpdateTaskResultFactory* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIRollbackUpdateTaskResultFactory* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIRollbackUpdateTaskResultFactory* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIRollbackUpdateTaskResultFactory* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIRollbackUpdateTaskResultFactory* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIRollbackUpdateTaskResultFactory* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* CreateInstance)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIRollbackUpdateTaskResultFactory* This,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResult* result,
        __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateInstallRecord* installRecords,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIRollbackUpdateTaskResult** value);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIRollbackUpdateTaskResultFactoryVtbl;

interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIRollbackUpdateTaskResultFactory
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIRollbackUpdateTaskResultFactoryVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIRollbackUpdateTaskResultFactory_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIRollbackUpdateTaskResultFactory_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIRollbackUpdateTaskResultFactory_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIRollbackUpdateTaskResultFactory_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIRollbackUpdateTaskResultFactory_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIRollbackUpdateTaskResultFactory_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIRollbackUpdateTaskResultFactory_CreateInstance(This, result, installRecords, value) \
    ((This)->lpVtbl->CreateInstance(This, result, installRecords, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIRollbackUpdateTaskResultFactory;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIRollbackUpdateTaskResultFactory_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IScanUpdateTaskResult
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.Cluster.ScanUpdateTaskResult
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIScanUpdateTaskResult_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIScanUpdateTaskResult_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IScanUpdateTaskResult[] = L"Windows.Management.Update.Cluster.IScanUpdateTaskResult";
typedef struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIScanUpdateTaskResultVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIScanUpdateTaskResult* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIScanUpdateTaskResult* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIScanUpdateTaskResult* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIScanUpdateTaskResult* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIScanUpdateTaskResult* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIScanUpdateTaskResult* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Result)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIScanUpdateTaskResult* This,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResult** value);
    HRESULT (STDMETHODCALLTYPE* get_ScanRecords)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIScanUpdateTaskResult* This,
        __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord** value);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIScanUpdateTaskResultVtbl;

interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIScanUpdateTaskResult
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIScanUpdateTaskResultVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIScanUpdateTaskResult_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIScanUpdateTaskResult_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIScanUpdateTaskResult_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIScanUpdateTaskResult_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIScanUpdateTaskResult_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIScanUpdateTaskResult_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIScanUpdateTaskResult_get_Result(This, value) \
    ((This)->lpVtbl->get_Result(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIScanUpdateTaskResult_get_ScanRecords(This, value) \
    ((This)->lpVtbl->get_ScanRecords(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIScanUpdateTaskResult;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIScanUpdateTaskResult_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IScanUpdateTaskResultFactory
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.Cluster.ScanUpdateTaskResult
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIScanUpdateTaskResultFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIScanUpdateTaskResultFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IScanUpdateTaskResultFactory[] = L"Windows.Management.Update.Cluster.IScanUpdateTaskResultFactory";
typedef struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIScanUpdateTaskResultFactoryVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIScanUpdateTaskResultFactory* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIScanUpdateTaskResultFactory* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIScanUpdateTaskResultFactory* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIScanUpdateTaskResultFactory* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIScanUpdateTaskResultFactory* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIScanUpdateTaskResultFactory* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* CreateInstance)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIScanUpdateTaskResultFactory* This,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResult* result,
        __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord* scanRecords,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIScanUpdateTaskResult** value);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIScanUpdateTaskResultFactoryVtbl;

interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIScanUpdateTaskResultFactory
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIScanUpdateTaskResultFactoryVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIScanUpdateTaskResultFactory_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIScanUpdateTaskResultFactory_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIScanUpdateTaskResultFactory_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIScanUpdateTaskResultFactory_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIScanUpdateTaskResultFactory_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIScanUpdateTaskResultFactory_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIScanUpdateTaskResultFactory_CreateInstance(This, result, scanRecords, value) \
    ((This)->lpVtbl->CreateInstance(This, result, scanRecords, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIScanUpdateTaskResultFactory;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIScanUpdateTaskResultFactory_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IStageUpdateTaskResult
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.Cluster.StageUpdateTaskResult
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIStageUpdateTaskResult_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIStageUpdateTaskResult_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IStageUpdateTaskResult[] = L"Windows.Management.Update.Cluster.IStageUpdateTaskResult";
typedef struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIStageUpdateTaskResultVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIStageUpdateTaskResult* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIStageUpdateTaskResult* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIStageUpdateTaskResult* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIStageUpdateTaskResult* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIStageUpdateTaskResult* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIStageUpdateTaskResult* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Result)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIStageUpdateTaskResult* This,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResult** value);
    HRESULT (STDMETHODCALLTYPE* get_StageRecords)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIStageUpdateTaskResult* This,
        __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord** value);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIStageUpdateTaskResultVtbl;

interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIStageUpdateTaskResult
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIStageUpdateTaskResultVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIStageUpdateTaskResult_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIStageUpdateTaskResult_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIStageUpdateTaskResult_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIStageUpdateTaskResult_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIStageUpdateTaskResult_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIStageUpdateTaskResult_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIStageUpdateTaskResult_get_Result(This, value) \
    ((This)->lpVtbl->get_Result(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIStageUpdateTaskResult_get_StageRecords(This, value) \
    ((This)->lpVtbl->get_StageRecords(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIStageUpdateTaskResult;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIStageUpdateTaskResult_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IStageUpdateTaskResultFactory
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.Cluster.StageUpdateTaskResult
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIStageUpdateTaskResultFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIStageUpdateTaskResultFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IStageUpdateTaskResultFactory[] = L"Windows.Management.Update.Cluster.IStageUpdateTaskResultFactory";
typedef struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIStageUpdateTaskResultFactoryVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIStageUpdateTaskResultFactory* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIStageUpdateTaskResultFactory* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIStageUpdateTaskResultFactory* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIStageUpdateTaskResultFactory* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIStageUpdateTaskResultFactory* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIStageUpdateTaskResultFactory* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* CreateInstance)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIStageUpdateTaskResultFactory* This,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResult* result,
        __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateStageRecord* stageRecords,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIStageUpdateTaskResult** value);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIStageUpdateTaskResultFactoryVtbl;

interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIStageUpdateTaskResultFactory
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIStageUpdateTaskResultFactoryVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIStageUpdateTaskResultFactory_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIStageUpdateTaskResultFactory_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIStageUpdateTaskResultFactory_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIStageUpdateTaskResultFactory_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIStageUpdateTaskResultFactory_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIStageUpdateTaskResultFactory_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIStageUpdateTaskResultFactory_CreateInstance(This, result, stageRecords, value) \
    ((This)->lpVtbl->CreateInstance(This, result, stageRecords, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIStageUpdateTaskResultFactory;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIStageUpdateTaskResultFactory_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IUpdateCredential
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.Cluster.UpdateCredential
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateCredential_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateCredential_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IUpdateCredential[] = L"Windows.Management.Update.Cluster.IUpdateCredential";
typedef struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateCredentialVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateCredential* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateCredential* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateCredential* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateCredential* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateCredential* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateCredential* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Status)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateCredential* This,
        enum __x_ABI_CWindows_CManagement_CUpdate_CCluster_CClusterNativeUpdateCredentialStatus* value);
    HRESULT (STDMETHODCALLTYPE* get_UserName)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateCredential* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* get_Password)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateCredential* This,
        HSTRING* value);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateCredentialVtbl;

interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateCredential
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateCredentialVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateCredential_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateCredential_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateCredential_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateCredential_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateCredential_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateCredential_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateCredential_get_Status(This, value) \
    ((This)->lpVtbl->get_Status(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateCredential_get_UserName(This, value) \
    ((This)->lpVtbl->get_UserName(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateCredential_get_Password(This, value) \
    ((This)->lpVtbl->get_Password(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateCredential;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateCredential_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IUpdateCredentialFactory
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.Cluster.UpdateCredential
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateCredentialFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateCredentialFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IUpdateCredentialFactory[] = L"Windows.Management.Update.Cluster.IUpdateCredentialFactory";
typedef struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateCredentialFactoryVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateCredentialFactory* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateCredentialFactory* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateCredentialFactory* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateCredentialFactory* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateCredentialFactory* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateCredentialFactory* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* CreateInstance)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateCredentialFactory* This,
        enum __x_ABI_CWindows_CManagement_CUpdate_CCluster_CClusterNativeUpdateCredentialStatus status,
        HSTRING userName,
        HSTRING password,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateCredential** value);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateCredentialFactoryVtbl;

interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateCredentialFactory
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateCredentialFactoryVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateCredentialFactory_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateCredentialFactory_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateCredentialFactory_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateCredentialFactory_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateCredentialFactory_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateCredentialFactory_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateCredentialFactory_CreateInstance(This, status, userName, password, value) \
    ((This)->lpVtbl->CreateInstance(This, status, userName, password, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateCredentialFactory;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateCredentialFactory_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IUpdateInstallRecord
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.Cluster.UpdateInstallRecord
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecord_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecord_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IUpdateInstallRecord[] = L"Windows.Management.Update.Cluster.IUpdateInstallRecord";
typedef struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecordVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecord* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecord* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecord* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecord* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecord* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecord* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_UpdateId)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecord* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* get_IsRebootRequired)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecord* This,
        boolean* value);
    HRESULT (STDMETHODCALLTYPE* get_Status)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecord* This,
        enum __x_ABI_CWindows_CManagement_CUpdate_CCluster_CClusterNativeUpdateCompletionStatus* value);
    HRESULT (STDMETHODCALLTYPE* get_FailureMessage)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecord* This,
        HSTRING* value);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecordVtbl;

interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecord
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecordVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecord_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecord_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecord_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecord_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecord_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecord_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecord_get_UpdateId(This, value) \
    ((This)->lpVtbl->get_UpdateId(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecord_get_IsRebootRequired(This, value) \
    ((This)->lpVtbl->get_IsRebootRequired(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecord_get_Status(This, value) \
    ((This)->lpVtbl->get_Status(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecord_get_FailureMessage(This, value) \
    ((This)->lpVtbl->get_FailureMessage(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecord;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecord_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IUpdateInstallRecordFactory
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.Cluster.UpdateInstallRecord
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecordFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecordFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IUpdateInstallRecordFactory[] = L"Windows.Management.Update.Cluster.IUpdateInstallRecordFactory";
typedef struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecordFactoryVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecordFactory* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecordFactory* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecordFactory* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecordFactory* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecordFactory* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecordFactory* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* CreateInstance)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecordFactory* This,
        HSTRING updateId,
        boolean isRebootRequired,
        enum __x_ABI_CWindows_CManagement_CUpdate_CCluster_CClusterNativeUpdateCompletionStatus status,
        HSTRING failureMessage,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecord** value);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecordFactoryVtbl;

interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecordFactory
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecordFactoryVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecordFactory_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecordFactory_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecordFactory_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecordFactory_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecordFactory_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecordFactory_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecordFactory_CreateInstance(This, updateId, isRebootRequired, status, failureMessage, value) \
    ((This)->lpVtbl->CreateInstance(This, updateId, isRebootRequired, status, failureMessage, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecordFactory;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallRecordFactory_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IUpdateInstaller
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstaller_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstaller_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IUpdateInstaller[] = L"Windows.Management.Update.Cluster.IUpdateInstaller";
typedef struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallerVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstaller* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstaller* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstaller* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstaller* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstaller* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstaller* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* Scan)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstaller* This,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIScanUpdateTaskResult** result);
    HRESULT (STDMETHODCALLTYPE* Stage)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstaller* This,
        __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord* updatesToStage,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIStageUpdateTaskResult** result);
    HRESULT (STDMETHODCALLTYPE* Install)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstaller* This,
        __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord* updatesToInstall,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIInstallUpdateTaskResult** result);
    HRESULT (STDMETHODCALLTYPE* Rollback)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstaller* This,
        __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord* updatesToRollback,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIRollbackUpdateTaskResult** result);
    HRESULT (STDMETHODCALLTYPE* ShouldUsePluginSpecificReboot)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstaller* This,
        boolean* usePluginReboot,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResult** result);
    HRESULT (STDMETHODCALLTYPE* RebootNode)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstaller* This,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResult** result);
    HRESULT (STDMETHODCALLTYPE* AcquireUpdateListValidationInfo)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstaller* This,
        HSTRING* recipeValidationInfo,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResult** result);
    HRESULT (STDMETHODCALLTYPE* ValidateAllNodesUpdateRecipe)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstaller* This,
        __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateRecipeNodeValidationInfoRecord* allNodesRecipeValidationInfo,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateAllNodesUpdateRecipeResult** result);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallerVtbl;

interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstaller
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallerVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstaller_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstaller_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstaller_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstaller_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstaller_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstaller_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstaller_Scan(This, result) \
    ((This)->lpVtbl->Scan(This, result))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstaller_Stage(This, updatesToStage, result) \
    ((This)->lpVtbl->Stage(This, updatesToStage, result))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstaller_Install(This, updatesToInstall, result) \
    ((This)->lpVtbl->Install(This, updatesToInstall, result))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstaller_Rollback(This, updatesToRollback, result) \
    ((This)->lpVtbl->Rollback(This, updatesToRollback, result))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstaller_ShouldUsePluginSpecificReboot(This, usePluginReboot, result) \
    ((This)->lpVtbl->ShouldUsePluginSpecificReboot(This, usePluginReboot, result))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstaller_RebootNode(This, result) \
    ((This)->lpVtbl->RebootNode(This, result))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstaller_AcquireUpdateListValidationInfo(This, recipeValidationInfo, result) \
    ((This)->lpVtbl->AcquireUpdateListValidationInfo(This, recipeValidationInfo, result))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstaller_ValidateAllNodesUpdateRecipe(This, allNodesRecipeValidationInfo, result) \
    ((This)->lpVtbl->ValidateAllNodesUpdateRecipe(This, allNodesRecipeValidationInfo, result))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstaller;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstaller_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IUpdateInstallerPlugin
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallerPlugin_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallerPlugin_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IUpdateInstallerPlugin[] = L"Windows.Management.Update.Cluster.IUpdateInstallerPlugin";
typedef struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallerPluginVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallerPlugin* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallerPlugin* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallerPlugin* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallerPlugin* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallerPlugin* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallerPlugin* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Name)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallerPlugin* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* get_FriendlyName)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallerPlugin* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* get_Description)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallerPlugin* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* get_Version)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallerPlugin* This,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfo** value);
    HRESULT (STDMETHODCALLTYPE* get_IsUpdateRollbackSupported)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallerPlugin* This,
        boolean* value);
    HRESULT (STDMETHODCALLTYPE* get_DefaultOptions)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallerPlugin* This,
        __FIMapView_2_HSTRING_HSTRING** value);
    HRESULT (STDMETHODCALLTYPE* CreateUpdateInstaller)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallerPlugin* This,
        HSTRING clusterName,
        HSTRING runId,
        __FIMap_2_HSTRING_HSTRING* options,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIClusterUpdateServices* updateServices,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstaller** result);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallerPluginVtbl;

interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallerPlugin
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallerPluginVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallerPlugin_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallerPlugin_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallerPlugin_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallerPlugin_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallerPlugin_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallerPlugin_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallerPlugin_get_Name(This, value) \
    ((This)->lpVtbl->get_Name(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallerPlugin_get_FriendlyName(This, value) \
    ((This)->lpVtbl->get_FriendlyName(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallerPlugin_get_Description(This, value) \
    ((This)->lpVtbl->get_Description(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallerPlugin_get_Version(This, value) \
    ((This)->lpVtbl->get_Version(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallerPlugin_get_IsUpdateRollbackSupported(This, value) \
    ((This)->lpVtbl->get_IsUpdateRollbackSupported(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallerPlugin_get_DefaultOptions(This, value) \
    ((This)->lpVtbl->get_DefaultOptions(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallerPlugin_CreateUpdateInstaller(This, clusterName, runId, options, updateServices, result) \
    ((This)->lpVtbl->CreateUpdateInstaller(This, clusterName, runId, options, updateServices, result))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallerPlugin;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateInstallerPlugin_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IUpdateOperationResult
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.Cluster.UpdateOperationResult
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResult_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResult_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IUpdateOperationResult[] = L"Windows.Management.Update.Cluster.IUpdateOperationResult";
typedef struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResultVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResult* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResult* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResult* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResult* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResult* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResult* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_StatusCode)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResult* This,
        enum __x_ABI_CWindows_CManagement_CUpdate_CCluster_CClusterNativeUpdateOperationStatus* value);
    HRESULT (STDMETHODCALLTYPE* get_Reason)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResult* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* get_ErrorCode)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResult* This,
        INT32* value);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResultVtbl;

interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResult
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResultVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResult_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResult_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResult_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResult_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResult_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResult_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResult_get_StatusCode(This, value) \
    ((This)->lpVtbl->get_StatusCode(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResult_get_Reason(This, value) \
    ((This)->lpVtbl->get_Reason(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResult_get_ErrorCode(This, value) \
    ((This)->lpVtbl->get_ErrorCode(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResult;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResult_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IUpdateOperationResultFactory
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.Cluster.UpdateOperationResult
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResultFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResultFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IUpdateOperationResultFactory[] = L"Windows.Management.Update.Cluster.IUpdateOperationResultFactory";
typedef struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResultFactoryVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResultFactory* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResultFactory* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResultFactory* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResultFactory* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResultFactory* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResultFactory* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* CreateInstance)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResultFactory* This,
        enum __x_ABI_CWindows_CManagement_CUpdate_CCluster_CClusterNativeUpdateOperationStatus status,
        HSTRING reason,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResult** value);
    HRESULT (STDMETHODCALLTYPE* CreateInstance2)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResultFactory* This,
        enum __x_ABI_CWindows_CManagement_CUpdate_CCluster_CClusterNativeUpdateOperationStatus status,
        HSTRING reason,
        INT32 errorCode,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResult** value);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResultFactoryVtbl;

interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResultFactory
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResultFactoryVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResultFactory_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResultFactory_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResultFactory_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResultFactory_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResultFactory_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResultFactory_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResultFactory_CreateInstance(This, status, reason, value) \
    ((This)->lpVtbl->CreateInstance(This, status, reason, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResultFactory_CreateInstance2(This, status, reason, errorCode, value) \
    ((This)->lpVtbl->CreateInstance2(This, status, reason, errorCode, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResultFactory;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResultFactory_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IUpdatePendingOperationResult
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.Cluster.UpdatePendingOperationResult
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResult_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResult_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IUpdatePendingOperationResult[] = L"Windows.Management.Update.Cluster.IUpdatePendingOperationResult";
typedef struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResultVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResult* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResult* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResult* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResult* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResult* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResult* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Result)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResult* This,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResult** value);
    HRESULT (STDMETHODCALLTYPE* get_SuggestedRecheckInterval)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResult* This,
        struct __x_ABI_CWindows_CFoundation_CTimeSpan* value);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResultVtbl;

interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResult
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResultVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResult_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResult_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResult_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResult_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResult_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResult_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResult_get_Result(This, value) \
    ((This)->lpVtbl->get_Result(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResult_get_SuggestedRecheckInterval(This, value) \
    ((This)->lpVtbl->get_SuggestedRecheckInterval(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResult;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResult_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IUpdatePendingOperationResultFactory
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.Cluster.UpdatePendingOperationResult
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResultFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResultFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IUpdatePendingOperationResultFactory[] = L"Windows.Management.Update.Cluster.IUpdatePendingOperationResultFactory";
typedef struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResultFactoryVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResultFactory* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResultFactory* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResultFactory* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResultFactory* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResultFactory* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResultFactory* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* CreateInstance)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResultFactory* This,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateOperationResult* result,
        struct __x_ABI_CWindows_CFoundation_CTimeSpan suggestedRecheckInterval,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResult** value);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResultFactoryVtbl;

interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResultFactory
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResultFactoryVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResultFactory_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResultFactory_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResultFactory_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResultFactory_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResultFactory_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResultFactory_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResultFactory_CreateInstance(This, result, suggestedRecheckInterval, value) \
    ((This)->lpVtbl->CreateInstance(This, result, suggestedRecheckInterval, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResultFactory;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePendingOperationResultFactory_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IUpdatePluginVersionInfo
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.Cluster.UpdatePluginVersionInfo
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfo_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfo_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IUpdatePluginVersionInfo[] = L"Windows.Management.Update.Cluster.IUpdatePluginVersionInfo";
typedef struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfoVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfo* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfo* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfo* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfo* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfo* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfo* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_MajorVersion)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfo* This,
        UINT32* value);
    HRESULT (STDMETHODCALLTYPE* get_MinorVersion)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfo* This,
        UINT32* value);
    HRESULT (STDMETHODCALLTYPE* get_PatchLevel)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfo* This,
        UINT32* value);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfoVtbl;

interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfo
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfoVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfo_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfo_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfo_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfo_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfo_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfo_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfo_get_MajorVersion(This, value) \
    ((This)->lpVtbl->get_MajorVersion(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfo_get_MinorVersion(This, value) \
    ((This)->lpVtbl->get_MinorVersion(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfo_get_PatchLevel(This, value) \
    ((This)->lpVtbl->get_PatchLevel(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfo;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfo_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IUpdatePluginVersionInfoFactory
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.Cluster.UpdatePluginVersionInfo
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfoFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfoFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IUpdatePluginVersionInfoFactory[] = L"Windows.Management.Update.Cluster.IUpdatePluginVersionInfoFactory";
typedef struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfoFactoryVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfoFactory* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfoFactory* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfoFactory* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfoFactory* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfoFactory* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfoFactory* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* CreateInstance)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfoFactory* This,
        UINT32 majorVersion,
        UINT32 minorVersion,
        UINT32 patchLevel,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfo** value);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfoFactoryVtbl;

interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfoFactory
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfoFactoryVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfoFactory_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfoFactory_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfoFactory_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfoFactory_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfoFactory_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfoFactory_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfoFactory_CreateInstance(This, majorVersion, minorVersion, patchLevel, value) \
    ((This)->lpVtbl->CreateInstance(This, majorVersion, minorVersion, patchLevel, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfoFactory;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdatePluginVersionInfoFactory_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IUpdateRecipeNodeValidationInfoRecord
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.Cluster.UpdateRecipeNodeValidationInfoRecord
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecord_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecord_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IUpdateRecipeNodeValidationInfoRecord[] = L"Windows.Management.Update.Cluster.IUpdateRecipeNodeValidationInfoRecord";
typedef struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecordVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecord* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecord* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecord* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecord* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecord* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecord* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_NodeName)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecord* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* get_RecipeValidationInfo)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecord* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* get_ScanResults)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecord* This,
        __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord** value);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecordVtbl;

interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecord
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecordVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecord_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecord_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecord_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecord_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecord_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecord_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecord_get_NodeName(This, value) \
    ((This)->lpVtbl->get_NodeName(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecord_get_RecipeValidationInfo(This, value) \
    ((This)->lpVtbl->get_RecipeValidationInfo(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecord_get_ScanResults(This, value) \
    ((This)->lpVtbl->get_ScanResults(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecord;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecord_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IUpdateRecipeNodeValidationInfoRecordFactory
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.Cluster.UpdateRecipeNodeValidationInfoRecord
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecordFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecordFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IUpdateRecipeNodeValidationInfoRecordFactory[] = L"Windows.Management.Update.Cluster.IUpdateRecipeNodeValidationInfoRecordFactory";
typedef struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecordFactoryVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecordFactory* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecordFactory* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecordFactory* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecordFactory* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecordFactory* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecordFactory* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* CreateInstance)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecordFactory* This,
        HSTRING nodeName,
        HSTRING recipeValidationInfo,
        __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateScanRecord* scanResults,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecord** value);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecordFactoryVtbl;

interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecordFactory
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecordFactoryVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecordFactory_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecordFactory_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecordFactory_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecordFactory_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecordFactory_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecordFactory_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecordFactory_CreateInstance(This, nodeName, recipeValidationInfo, scanResults, value) \
    ((This)->lpVtbl->CreateInstance(This, nodeName, recipeValidationInfo, scanResults, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecordFactory;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateRecipeNodeValidationInfoRecordFactory_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IUpdateScanRecord
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.Cluster.UpdateScanRecord
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecord_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecord_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IUpdateScanRecord[] = L"Windows.Management.Update.Cluster.IUpdateScanRecord";
typedef struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecordVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecord* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecord* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecord* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecord* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecord* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecord* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_UpdateId)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecord* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* get_UpdateTitle)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecord* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* get_UpdateDescription)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecord* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* get_IsRebootRequired)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecord* This,
        boolean* value);
    HRESULT (STDMETHODCALLTYPE* get_PluginSpecificData)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecord* This,
        HSTRING* value);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecordVtbl;

interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecord
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecordVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecord_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecord_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecord_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecord_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecord_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecord_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecord_get_UpdateId(This, value) \
    ((This)->lpVtbl->get_UpdateId(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecord_get_UpdateTitle(This, value) \
    ((This)->lpVtbl->get_UpdateTitle(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecord_get_UpdateDescription(This, value) \
    ((This)->lpVtbl->get_UpdateDescription(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecord_get_IsRebootRequired(This, value) \
    ((This)->lpVtbl->get_IsRebootRequired(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecord_get_PluginSpecificData(This, value) \
    ((This)->lpVtbl->get_PluginSpecificData(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecord;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecord_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IUpdateScanRecordFactory
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.Cluster.UpdateScanRecord
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecordFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecordFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IUpdateScanRecordFactory[] = L"Windows.Management.Update.Cluster.IUpdateScanRecordFactory";
typedef struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecordFactoryVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecordFactory* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecordFactory* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecordFactory* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecordFactory* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecordFactory* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecordFactory* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* CreateInstance)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecordFactory* This,
        HSTRING updateId,
        HSTRING updateTitle,
        HSTRING updateDescription,
        boolean isRebootRequired,
        HSTRING pluginSpecificData,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecord** value);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecordFactoryVtbl;

interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecordFactory
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecordFactoryVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecordFactory_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecordFactory_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecordFactory_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecordFactory_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecordFactory_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecordFactory_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecordFactory_CreateInstance(This, updateId, updateTitle, updateDescription, isRebootRequired, pluginSpecificData, value) \
    ((This)->lpVtbl->CreateInstance(This, updateId, updateTitle, updateDescription, isRebootRequired, pluginSpecificData, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecordFactory;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateScanRecordFactory_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IUpdateStageRecord
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.Cluster.UpdateStageRecord
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecord_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecord_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IUpdateStageRecord[] = L"Windows.Management.Update.Cluster.IUpdateStageRecord";
typedef struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecordVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecord* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecord* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecord* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecord* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecord* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecord* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_UpdateId)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecord* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* get_Status)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecord* This,
        enum __x_ABI_CWindows_CManagement_CUpdate_CCluster_CClusterNativeUpdateCompletionStatus* value);
    HRESULT (STDMETHODCALLTYPE* get_FailureMessage)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecord* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* get_UpdatedPluginSpecificData)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecord* This,
        HSTRING* value);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecordVtbl;

interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecord
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecordVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecord_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecord_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecord_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecord_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecord_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecord_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecord_get_UpdateId(This, value) \
    ((This)->lpVtbl->get_UpdateId(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecord_get_Status(This, value) \
    ((This)->lpVtbl->get_Status(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecord_get_FailureMessage(This, value) \
    ((This)->lpVtbl->get_FailureMessage(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecord_get_UpdatedPluginSpecificData(This, value) \
    ((This)->lpVtbl->get_UpdatedPluginSpecificData(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecord;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecord_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IUpdateStageRecordFactory
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.Cluster.UpdateStageRecord
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecordFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecordFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IUpdateStageRecordFactory[] = L"Windows.Management.Update.Cluster.IUpdateStageRecordFactory";
typedef struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecordFactoryVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecordFactory* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecordFactory* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecordFactory* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecordFactory* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecordFactory* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecordFactory* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* CreateInstance)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecordFactory* This,
        HSTRING updateId,
        enum __x_ABI_CWindows_CManagement_CUpdate_CCluster_CClusterNativeUpdateCompletionStatus status,
        HSTRING failureMessage,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecord** value);
    HRESULT (STDMETHODCALLTYPE* CreateInstance2)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecordFactory* This,
        HSTRING updateId,
        enum __x_ABI_CWindows_CManagement_CUpdate_CCluster_CClusterNativeUpdateCompletionStatus status,
        HSTRING failureMessage,
        HSTRING updatedPluginSpecificData,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecord** value);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecordFactoryVtbl;

interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecordFactory
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecordFactoryVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecordFactory_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecordFactory_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecordFactory_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecordFactory_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecordFactory_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecordFactory_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecordFactory_CreateInstance(This, updateId, status, failureMessage, value) \
    ((This)->lpVtbl->CreateInstance(This, updateId, status, failureMessage, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecordFactory_CreateInstance2(This, updateId, status, failureMessage, updatedPluginSpecificData, value) \
    ((This)->lpVtbl->CreateInstance2(This, updateId, status, failureMessage, updatedPluginSpecificData, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecordFactory;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateStageRecordFactory_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IUpdateTaskResult
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.Cluster.UpdateTaskResult
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResult_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResult_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IUpdateTaskResult[] = L"Windows.Management.Update.Cluster.IUpdateTaskResult";
typedef struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResultVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResult* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResult* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResult* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResult* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResult* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResult* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Succeeded)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResult* This,
        boolean* value);
    HRESULT (STDMETHODCALLTYPE* get_Reason)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResult* This,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* get_ErrorCode)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResult* This,
        INT32* value);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResultVtbl;

interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResult
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResultVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResult_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResult_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResult_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResult_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResult_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResult_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResult_get_Succeeded(This, value) \
    ((This)->lpVtbl->get_Succeeded(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResult_get_Reason(This, value) \
    ((This)->lpVtbl->get_Reason(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResult_get_ErrorCode(This, value) \
    ((This)->lpVtbl->get_ErrorCode(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResult;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResult_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IUpdateTaskResultFactory
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.Cluster.UpdateTaskResult
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResultFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResultFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IUpdateTaskResultFactory[] = L"Windows.Management.Update.Cluster.IUpdateTaskResultFactory";
typedef struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResultFactoryVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResultFactory* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResultFactory* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResultFactory* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResultFactory* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResultFactory* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResultFactory* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* CreateInstance)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResultFactory* This,
        boolean succeeded,
        HSTRING reason,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResult** value);
    HRESULT (STDMETHODCALLTYPE* CreateInstance2)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResultFactory* This,
        boolean succeeded,
        HSTRING reason,
        INT32 errorCode,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResult** value);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResultFactoryVtbl;

interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResultFactory
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResultFactoryVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResultFactory_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResultFactory_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResultFactory_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResultFactory_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResultFactory_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResultFactory_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResultFactory_CreateInstance(This, succeeded, reason, value) \
    ((This)->lpVtbl->CreateInstance(This, succeeded, reason, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResultFactory_CreateInstance2(This, succeeded, reason, errorCode, value) \
    ((This)->lpVtbl->CreateInstance2(This, succeeded, reason, errorCode, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResultFactory;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResultFactory_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IUpdateValidationLogMessage
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.Cluster.UpdateValidationLogMessage
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessage_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessage_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IUpdateValidationLogMessage[] = L"Windows.Management.Update.Cluster.IUpdateValidationLogMessage";
typedef struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessageVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessage* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessage* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessage* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessage* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessage* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessage* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Severity)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessage* This,
        enum __x_ABI_CWindows_CManagement_CUpdate_CCluster_CClusterNativeUpdateLogLevel* value);
    HRESULT (STDMETHODCALLTYPE* get_Message)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessage* This,
        HSTRING* value);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessageVtbl;

interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessage
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessageVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessage_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessage_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessage_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessage_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessage_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessage_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessage_get_Severity(This, value) \
    ((This)->lpVtbl->get_Severity(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessage_get_Message(This, value) \
    ((This)->lpVtbl->get_Message(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessage;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessage_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IUpdateValidationLogMessageFactory
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.Cluster.UpdateValidationLogMessage
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessageFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessageFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IUpdateValidationLogMessageFactory[] = L"Windows.Management.Update.Cluster.IUpdateValidationLogMessageFactory";
typedef struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessageFactoryVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessageFactory* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessageFactory* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessageFactory* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessageFactory* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessageFactory* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessageFactory* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* CreateInstance)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessageFactory* This,
        enum __x_ABI_CWindows_CManagement_CUpdate_CCluster_CClusterNativeUpdateLogLevel severity,
        HSTRING message,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessage** value);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessageFactoryVtbl;

interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessageFactory
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessageFactoryVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessageFactory_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessageFactory_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessageFactory_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessageFactory_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessageFactory_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessageFactory_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessageFactory_CreateInstance(This, severity, message, value) \
    ((This)->lpVtbl->CreateInstance(This, severity, message, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessageFactory;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateValidationLogMessageFactory_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IValidateAllNodesUpdateRecipeResult
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.Cluster.ValidateAllNodesUpdateRecipeResult
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateAllNodesUpdateRecipeResult_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateAllNodesUpdateRecipeResult_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IValidateAllNodesUpdateRecipeResult[] = L"Windows.Management.Update.Cluster.IValidateAllNodesUpdateRecipeResult";
typedef struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateAllNodesUpdateRecipeResultVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateAllNodesUpdateRecipeResult* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateAllNodesUpdateRecipeResult* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateAllNodesUpdateRecipeResult* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateAllNodesUpdateRecipeResult* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateAllNodesUpdateRecipeResult* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateAllNodesUpdateRecipeResult* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Result)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateAllNodesUpdateRecipeResult* This,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResult** value);
    HRESULT (STDMETHODCALLTYPE* get_AreUpdatesApproved)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateAllNodesUpdateRecipeResult* This,
        boolean* value);
    HRESULT (STDMETHODCALLTYPE* get_ValidationMessages)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateAllNodesUpdateRecipeResult* This,
        __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage** value);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateAllNodesUpdateRecipeResultVtbl;

interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateAllNodesUpdateRecipeResult
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateAllNodesUpdateRecipeResultVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateAllNodesUpdateRecipeResult_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateAllNodesUpdateRecipeResult_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateAllNodesUpdateRecipeResult_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateAllNodesUpdateRecipeResult_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateAllNodesUpdateRecipeResult_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateAllNodesUpdateRecipeResult_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateAllNodesUpdateRecipeResult_get_Result(This, value) \
    ((This)->lpVtbl->get_Result(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateAllNodesUpdateRecipeResult_get_AreUpdatesApproved(This, value) \
    ((This)->lpVtbl->get_AreUpdatesApproved(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateAllNodesUpdateRecipeResult_get_ValidationMessages(This, value) \
    ((This)->lpVtbl->get_ValidationMessages(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateAllNodesUpdateRecipeResult;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateAllNodesUpdateRecipeResult_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IValidateAllNodesUpdateRecipeResultFactory
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.Cluster.ValidateAllNodesUpdateRecipeResult
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateAllNodesUpdateRecipeResultFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateAllNodesUpdateRecipeResultFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IValidateAllNodesUpdateRecipeResultFactory[] = L"Windows.Management.Update.Cluster.IValidateAllNodesUpdateRecipeResultFactory";
typedef struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateAllNodesUpdateRecipeResultFactoryVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateAllNodesUpdateRecipeResultFactory* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateAllNodesUpdateRecipeResultFactory* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateAllNodesUpdateRecipeResultFactory* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateAllNodesUpdateRecipeResultFactory* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateAllNodesUpdateRecipeResultFactory* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateAllNodesUpdateRecipeResultFactory* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* CreateInstance)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateAllNodesUpdateRecipeResultFactory* This,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResult* result,
        boolean areUpdatesApproved,
        __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage* validationMessages,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateAllNodesUpdateRecipeResult** value);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateAllNodesUpdateRecipeResultFactoryVtbl;

interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateAllNodesUpdateRecipeResultFactory
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateAllNodesUpdateRecipeResultFactoryVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateAllNodesUpdateRecipeResultFactory_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateAllNodesUpdateRecipeResultFactory_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateAllNodesUpdateRecipeResultFactory_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateAllNodesUpdateRecipeResultFactory_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateAllNodesUpdateRecipeResultFactory_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateAllNodesUpdateRecipeResultFactory_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateAllNodesUpdateRecipeResultFactory_CreateInstance(This, result, areUpdatesApproved, validationMessages, value) \
    ((This)->lpVtbl->CreateInstance(This, result, areUpdatesApproved, validationMessages, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateAllNodesUpdateRecipeResultFactory;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateAllNodesUpdateRecipeResultFactory_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IValidateClusterEnvironmentResult
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.Cluster.ValidateClusterEnvironmentResult
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateClusterEnvironmentResult_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateClusterEnvironmentResult_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IValidateClusterEnvironmentResult[] = L"Windows.Management.Update.Cluster.IValidateClusterEnvironmentResult";
typedef struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateClusterEnvironmentResultVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateClusterEnvironmentResult* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateClusterEnvironmentResult* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateClusterEnvironmentResult* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateClusterEnvironmentResult* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateClusterEnvironmentResult* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateClusterEnvironmentResult* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_Result)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateClusterEnvironmentResult* This,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResult** value);
    HRESULT (STDMETHODCALLTYPE* get_ApprovalStatus)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateClusterEnvironmentResult* This,
        enum __x_ABI_CWindows_CManagement_CUpdate_CCluster_CClusterNativeUpdateEnvironmentValidationStatus* value);
    HRESULT (STDMETHODCALLTYPE* get_ValidationMessages)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateClusterEnvironmentResult* This,
        __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage** value);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateClusterEnvironmentResultVtbl;

interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateClusterEnvironmentResult
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateClusterEnvironmentResultVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateClusterEnvironmentResult_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateClusterEnvironmentResult_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateClusterEnvironmentResult_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateClusterEnvironmentResult_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateClusterEnvironmentResult_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateClusterEnvironmentResult_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateClusterEnvironmentResult_get_Result(This, value) \
    ((This)->lpVtbl->get_Result(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateClusterEnvironmentResult_get_ApprovalStatus(This, value) \
    ((This)->lpVtbl->get_ApprovalStatus(This, value))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateClusterEnvironmentResult_get_ValidationMessages(This, value) \
    ((This)->lpVtbl->get_ValidationMessages(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateClusterEnvironmentResult;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateClusterEnvironmentResult_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Management.Update.Cluster.IValidateClusterEnvironmentResultFactory
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Management.Update.Cluster.ValidateClusterEnvironmentResult
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateClusterEnvironmentResultFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateClusterEnvironmentResultFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Management_Update_Cluster_IValidateClusterEnvironmentResultFactory[] = L"Windows.Management.Update.Cluster.IValidateClusterEnvironmentResultFactory";
typedef struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateClusterEnvironmentResultFactoryVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateClusterEnvironmentResultFactory* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateClusterEnvironmentResultFactory* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateClusterEnvironmentResultFactory* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateClusterEnvironmentResultFactory* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateClusterEnvironmentResultFactory* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateClusterEnvironmentResultFactory* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* CreateInstance)(__x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateClusterEnvironmentResultFactory* This,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIUpdateTaskResult* result,
        enum __x_ABI_CWindows_CManagement_CUpdate_CCluster_CClusterNativeUpdateEnvironmentValidationStatus approvalStatus,
        __FIVectorView_1_Windows__CManagement__CUpdate__CCluster__CUpdateValidationLogMessage* validationMessages,
        __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateClusterEnvironmentResult** value);

    END_INTERFACE
} __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateClusterEnvironmentResultFactoryVtbl;

interface __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateClusterEnvironmentResultFactory
{
    CONST_VTBL struct __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateClusterEnvironmentResultFactoryVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateClusterEnvironmentResultFactory_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateClusterEnvironmentResultFactory_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateClusterEnvironmentResultFactory_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateClusterEnvironmentResultFactory_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateClusterEnvironmentResultFactory_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateClusterEnvironmentResultFactory_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateClusterEnvironmentResultFactory_CreateInstance(This, result, approvalStatus, validationMessages, value) \
    ((This)->lpVtbl->CreateInstance(This, result, approvalStatus, validationMessages, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateClusterEnvironmentResultFactory;
#endif /* !defined(____x_ABI_CWindows_CManagement_CUpdate_CCluster_CIValidateClusterEnvironmentResultFactory_INTERFACE_DEFINED__) */
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Management.Update.Cluster.AcquireEnvironmentInfoResult
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via the Windows.Management.Update.Cluster.IAcquireEnvironmentInfoResultFactory interface starting with version 1.0 of the Windows.Management.Update.Cluster.ClusterNativeUpdatingContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Management.Update.Cluster.IAcquireEnvironmentInfoResult ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Management_Update_Cluster_AcquireEnvironmentInfoResult_DEFINED
#define RUNTIMECLASS_Windows_Management_Update_Cluster_AcquireEnvironmentInfoResult_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Update_Cluster_AcquireEnvironmentInfoResult[] = L"Windows.Management.Update.Cluster.AcquireEnvironmentInfoResult";
#endif
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Management.Update.Cluster.AreRebootsPendingResult
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via the Windows.Management.Update.Cluster.IAreRebootsPendingResultFactory interface starting with version 1.0 of the Windows.Management.Update.Cluster.ClusterNativeUpdatingContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Management.Update.Cluster.IAreRebootsPendingResult ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Management_Update_Cluster_AreRebootsPendingResult_DEFINED
#define RUNTIMECLASS_Windows_Management_Update_Cluster_AreRebootsPendingResult_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Update_Cluster_AreRebootsPendingResult[] = L"Windows.Management.Update.Cluster.AreRebootsPendingResult";
#endif
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Management.Update.Cluster.ClusterUpdateServices
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * Class implements the following interfaces:
 *    Windows.Management.Update.Cluster.IClusterUpdateServices ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Management_Update_Cluster_ClusterUpdateServices_DEFINED
#define RUNTIMECLASS_Windows_Management_Update_Cluster_ClusterUpdateServices_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Update_Cluster_ClusterUpdateServices[] = L"Windows.Management.Update.Cluster.ClusterUpdateServices";
#endif
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Management.Update.Cluster.InstallUpdateTaskResult
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via the Windows.Management.Update.Cluster.IInstallUpdateTaskResultFactory interface starting with version 1.0 of the Windows.Management.Update.Cluster.ClusterNativeUpdatingContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Management.Update.Cluster.IInstallUpdateTaskResult ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Management_Update_Cluster_InstallUpdateTaskResult_DEFINED
#define RUNTIMECLASS_Windows_Management_Update_Cluster_InstallUpdateTaskResult_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Update_Cluster_InstallUpdateTaskResult[] = L"Windows.Management.Update.Cluster.InstallUpdateTaskResult";
#endif
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Management.Update.Cluster.RollbackUpdateTaskResult
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via the Windows.Management.Update.Cluster.IRollbackUpdateTaskResultFactory interface starting with version 1.0 of the Windows.Management.Update.Cluster.ClusterNativeUpdatingContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Management.Update.Cluster.IRollbackUpdateTaskResult ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Management_Update_Cluster_RollbackUpdateTaskResult_DEFINED
#define RUNTIMECLASS_Windows_Management_Update_Cluster_RollbackUpdateTaskResult_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Update_Cluster_RollbackUpdateTaskResult[] = L"Windows.Management.Update.Cluster.RollbackUpdateTaskResult";
#endif
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Management.Update.Cluster.ScanUpdateTaskResult
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via the Windows.Management.Update.Cluster.IScanUpdateTaskResultFactory interface starting with version 1.0 of the Windows.Management.Update.Cluster.ClusterNativeUpdatingContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Management.Update.Cluster.IScanUpdateTaskResult ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Management_Update_Cluster_ScanUpdateTaskResult_DEFINED
#define RUNTIMECLASS_Windows_Management_Update_Cluster_ScanUpdateTaskResult_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Update_Cluster_ScanUpdateTaskResult[] = L"Windows.Management.Update.Cluster.ScanUpdateTaskResult";
#endif
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Management.Update.Cluster.StageUpdateTaskResult
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via the Windows.Management.Update.Cluster.IStageUpdateTaskResultFactory interface starting with version 1.0 of the Windows.Management.Update.Cluster.ClusterNativeUpdatingContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Management.Update.Cluster.IStageUpdateTaskResult ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Management_Update_Cluster_StageUpdateTaskResult_DEFINED
#define RUNTIMECLASS_Windows_Management_Update_Cluster_StageUpdateTaskResult_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Update_Cluster_StageUpdateTaskResult[] = L"Windows.Management.Update.Cluster.StageUpdateTaskResult";
#endif
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Management.Update.Cluster.UpdateCredential
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via the Windows.Management.Update.Cluster.IUpdateCredentialFactory interface starting with version 1.0 of the Windows.Management.Update.Cluster.ClusterNativeUpdatingContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Management.Update.Cluster.IUpdateCredential ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Management_Update_Cluster_UpdateCredential_DEFINED
#define RUNTIMECLASS_Windows_Management_Update_Cluster_UpdateCredential_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Update_Cluster_UpdateCredential[] = L"Windows.Management.Update.Cluster.UpdateCredential";
#endif
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Management.Update.Cluster.UpdateInstallRecord
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via the Windows.Management.Update.Cluster.IUpdateInstallRecordFactory interface starting with version 1.0 of the Windows.Management.Update.Cluster.ClusterNativeUpdatingContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Management.Update.Cluster.IUpdateInstallRecord ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Management_Update_Cluster_UpdateInstallRecord_DEFINED
#define RUNTIMECLASS_Windows_Management_Update_Cluster_UpdateInstallRecord_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Update_Cluster_UpdateInstallRecord[] = L"Windows.Management.Update.Cluster.UpdateInstallRecord";
#endif
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Management.Update.Cluster.UpdateOperationResult
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via the Windows.Management.Update.Cluster.IUpdateOperationResultFactory interface starting with version 1.0 of the Windows.Management.Update.Cluster.ClusterNativeUpdatingContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Management.Update.Cluster.IUpdateOperationResult ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Management_Update_Cluster_UpdateOperationResult_DEFINED
#define RUNTIMECLASS_Windows_Management_Update_Cluster_UpdateOperationResult_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Update_Cluster_UpdateOperationResult[] = L"Windows.Management.Update.Cluster.UpdateOperationResult";
#endif
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Management.Update.Cluster.UpdatePendingOperationResult
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via the Windows.Management.Update.Cluster.IUpdatePendingOperationResultFactory interface starting with version 1.0 of the Windows.Management.Update.Cluster.ClusterNativeUpdatingContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Management.Update.Cluster.IUpdatePendingOperationResult ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Management_Update_Cluster_UpdatePendingOperationResult_DEFINED
#define RUNTIMECLASS_Windows_Management_Update_Cluster_UpdatePendingOperationResult_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Update_Cluster_UpdatePendingOperationResult[] = L"Windows.Management.Update.Cluster.UpdatePendingOperationResult";
#endif
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Management.Update.Cluster.UpdatePluginVersionInfo
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via the Windows.Management.Update.Cluster.IUpdatePluginVersionInfoFactory interface starting with version 1.0 of the Windows.Management.Update.Cluster.ClusterNativeUpdatingContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Management.Update.Cluster.IUpdatePluginVersionInfo ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Management_Update_Cluster_UpdatePluginVersionInfo_DEFINED
#define RUNTIMECLASS_Windows_Management_Update_Cluster_UpdatePluginVersionInfo_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Update_Cluster_UpdatePluginVersionInfo[] = L"Windows.Management.Update.Cluster.UpdatePluginVersionInfo";
#endif
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Management.Update.Cluster.UpdateRecipeNodeValidationInfoRecord
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via the Windows.Management.Update.Cluster.IUpdateRecipeNodeValidationInfoRecordFactory interface starting with version 1.0 of the Windows.Management.Update.Cluster.ClusterNativeUpdatingContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Management.Update.Cluster.IUpdateRecipeNodeValidationInfoRecord ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Management_Update_Cluster_UpdateRecipeNodeValidationInfoRecord_DEFINED
#define RUNTIMECLASS_Windows_Management_Update_Cluster_UpdateRecipeNodeValidationInfoRecord_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Update_Cluster_UpdateRecipeNodeValidationInfoRecord[] = L"Windows.Management.Update.Cluster.UpdateRecipeNodeValidationInfoRecord";
#endif
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Management.Update.Cluster.UpdateScanRecord
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via the Windows.Management.Update.Cluster.IUpdateScanRecordFactory interface starting with version 1.0 of the Windows.Management.Update.Cluster.ClusterNativeUpdatingContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Management.Update.Cluster.IUpdateScanRecord ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Management_Update_Cluster_UpdateScanRecord_DEFINED
#define RUNTIMECLASS_Windows_Management_Update_Cluster_UpdateScanRecord_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Update_Cluster_UpdateScanRecord[] = L"Windows.Management.Update.Cluster.UpdateScanRecord";
#endif
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Management.Update.Cluster.UpdateStageRecord
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via the Windows.Management.Update.Cluster.IUpdateStageRecordFactory interface starting with version 1.0 of the Windows.Management.Update.Cluster.ClusterNativeUpdatingContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Management.Update.Cluster.IUpdateStageRecord ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Management_Update_Cluster_UpdateStageRecord_DEFINED
#define RUNTIMECLASS_Windows_Management_Update_Cluster_UpdateStageRecord_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Update_Cluster_UpdateStageRecord[] = L"Windows.Management.Update.Cluster.UpdateStageRecord";
#endif
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Management.Update.Cluster.UpdateTaskResult
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via the Windows.Management.Update.Cluster.IUpdateTaskResultFactory interface starting with version 1.0 of the Windows.Management.Update.Cluster.ClusterNativeUpdatingContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Management.Update.Cluster.IUpdateTaskResult ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Management_Update_Cluster_UpdateTaskResult_DEFINED
#define RUNTIMECLASS_Windows_Management_Update_Cluster_UpdateTaskResult_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Update_Cluster_UpdateTaskResult[] = L"Windows.Management.Update.Cluster.UpdateTaskResult";
#endif
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Management.Update.Cluster.UpdateValidationLogMessage
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via the Windows.Management.Update.Cluster.IUpdateValidationLogMessageFactory interface starting with version 1.0 of the Windows.Management.Update.Cluster.ClusterNativeUpdatingContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Management.Update.Cluster.IUpdateValidationLogMessage ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Management_Update_Cluster_UpdateValidationLogMessage_DEFINED
#define RUNTIMECLASS_Windows_Management_Update_Cluster_UpdateValidationLogMessage_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Update_Cluster_UpdateValidationLogMessage[] = L"Windows.Management.Update.Cluster.UpdateValidationLogMessage";
#endif
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Management.Update.Cluster.ValidateAllNodesUpdateRecipeResult
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via the Windows.Management.Update.Cluster.IValidateAllNodesUpdateRecipeResultFactory interface starting with version 1.0 of the Windows.Management.Update.Cluster.ClusterNativeUpdatingContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Management.Update.Cluster.IValidateAllNodesUpdateRecipeResult ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Management_Update_Cluster_ValidateAllNodesUpdateRecipeResult_DEFINED
#define RUNTIMECLASS_Windows_Management_Update_Cluster_ValidateAllNodesUpdateRecipeResult_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Update_Cluster_ValidateAllNodesUpdateRecipeResult[] = L"Windows.Management.Update.Cluster.ValidateAllNodesUpdateRecipeResult";
#endif
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Management.Update.Cluster.ValidateClusterEnvironmentResult
 *
 * Introduced to Windows.Management.Update.Cluster.ClusterNativeUpdatingContract in version 1.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via the Windows.Management.Update.Cluster.IValidateClusterEnvironmentResultFactory interface starting with version 1.0 of the Windows.Management.Update.Cluster.ClusterNativeUpdatingContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Management.Update.Cluster.IValidateClusterEnvironmentResult ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Management_Update_Cluster_ValidateClusterEnvironmentResult_DEFINED
#define RUNTIMECLASS_Windows_Management_Update_Cluster_ValidateClusterEnvironmentResult_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Management_Update_Cluster_ValidateClusterEnvironmentResult[] = L"Windows.Management.Update.Cluster.ValidateClusterEnvironmentResult";
#endif
#endif // WINDOWS_MANAGEMENT_UPDATE_CLUSTER_CLUSTERNATIVEUPDATINGCONTRACT_VERSION >= 0x10000

#endif // defined(__cplusplus)
#pragma pop_macro("MIDL_CONST_ID")
// Restore the original value of the 'DEPRECATED' macro
#pragma pop_macro("DEPRECATED")

#ifdef __clang__
#pragma clang diagnostic pop // deprecated-declarations
#else
#pragma warning(pop)
#endif
#endif // __windows2Emanagement2Eupdate2Ecluster_p_h__

#endif // __windows2Emanagement2Eupdate2Ecluster_h__
