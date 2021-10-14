
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
#ifndef __windows2Eui2Eshell_h__
#define __windows2Eui2Eshell_h__
#ifndef __windows2Eui2Eshell_p_h__
#define __windows2Eui2Eshell_p_h__


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

#if !defined(WINDOWS_UI_SHELL_SECURITYAPPMANAGERCONTRACT_VERSION)
#define WINDOWS_UI_SHELL_SECURITYAPPMANAGERCONTRACT_VERSION 0x10000
#endif // defined(WINDOWS_UI_SHELL_SECURITYAPPMANAGERCONTRACT_VERSION)

#endif // defined(SPECIFIC_API_CONTRACT_DEFINITIONS)


// Header files for imported files
#include "inspectable.h"
#include "AsyncInfo.h"
#include "EventToken.h"
#include "windowscontracts.h"
#include "Windows.Foundation.h"
#include "Windows.ApplicationModel.Core.h"
#include "Windows.UI.h"
#include "Windows.UI.StartScreen.h"

#if defined(__cplusplus) && !defined(CINTERFACE)
/* Forward Declarations */
#ifndef ____x_ABI_CWindows_CUI_CShell_CIAdaptiveCard_FWD_DEFINED__
#define ____x_ABI_CWindows_CUI_CShell_CIAdaptiveCard_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace UI {
            namespace Shell {
                interface IAdaptiveCard;
            } /* Shell */
        } /* UI */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CUI_CShell_CIAdaptiveCard ABI::Windows::UI::Shell::IAdaptiveCard

#endif // ____x_ABI_CWindows_CUI_CShell_CIAdaptiveCard_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CUI_CShell_CIAdaptiveCardBuilderStatics_FWD_DEFINED__
#define ____x_ABI_CWindows_CUI_CShell_CIAdaptiveCardBuilderStatics_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace UI {
            namespace Shell {
                interface IAdaptiveCardBuilderStatics;
            } /* Shell */
        } /* UI */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CUI_CShell_CIAdaptiveCardBuilderStatics ABI::Windows::UI::Shell::IAdaptiveCardBuilderStatics

#endif // ____x_ABI_CWindows_CUI_CShell_CIAdaptiveCardBuilderStatics_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CUI_CShell_CISecurityAppManager_FWD_DEFINED__
#define ____x_ABI_CWindows_CUI_CShell_CISecurityAppManager_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace UI {
            namespace Shell {
                interface ISecurityAppManager;
            } /* Shell */
        } /* UI */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CUI_CShell_CISecurityAppManager ABI::Windows::UI::Shell::ISecurityAppManager

#endif // ____x_ABI_CWindows_CUI_CShell_CISecurityAppManager_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CUI_CShell_CIShareWindowCommandEventArgs_FWD_DEFINED__
#define ____x_ABI_CWindows_CUI_CShell_CIShareWindowCommandEventArgs_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace UI {
            namespace Shell {
                interface IShareWindowCommandEventArgs;
            } /* Shell */
        } /* UI */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CUI_CShell_CIShareWindowCommandEventArgs ABI::Windows::UI::Shell::IShareWindowCommandEventArgs

#endif // ____x_ABI_CWindows_CUI_CShell_CIShareWindowCommandEventArgs_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSource_FWD_DEFINED__
#define ____x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSource_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace UI {
            namespace Shell {
                interface IShareWindowCommandSource;
            } /* Shell */
        } /* UI */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSource ABI::Windows::UI::Shell::IShareWindowCommandSource

#endif // ____x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSource_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSourceStatics_FWD_DEFINED__
#define ____x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSourceStatics_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace UI {
            namespace Shell {
                interface IShareWindowCommandSourceStatics;
            } /* Shell */
        } /* UI */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSourceStatics ABI::Windows::UI::Shell::IShareWindowCommandSourceStatics

#endif // ____x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSourceStatics_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CUI_CShell_CITaskbarManager_FWD_DEFINED__
#define ____x_ABI_CWindows_CUI_CShell_CITaskbarManager_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace UI {
            namespace Shell {
                interface ITaskbarManager;
            } /* Shell */
        } /* UI */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CUI_CShell_CITaskbarManager ABI::Windows::UI::Shell::ITaskbarManager

#endif // ____x_ABI_CWindows_CUI_CShell_CITaskbarManager_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CUI_CShell_CITaskbarManager2_FWD_DEFINED__
#define ____x_ABI_CWindows_CUI_CShell_CITaskbarManager2_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace UI {
            namespace Shell {
                interface ITaskbarManager2;
            } /* Shell */
        } /* UI */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CUI_CShell_CITaskbarManager2 ABI::Windows::UI::Shell::ITaskbarManager2

#endif // ____x_ABI_CWindows_CUI_CShell_CITaskbarManager2_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CUI_CShell_CITaskbarManagerStatics_FWD_DEFINED__
#define ____x_ABI_CWindows_CUI_CShell_CITaskbarManagerStatics_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace UI {
            namespace Shell {
                interface ITaskbarManagerStatics;
            } /* Shell */
        } /* UI */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CUI_CShell_CITaskbarManagerStatics ABI::Windows::UI::Shell::ITaskbarManagerStatics

#endif // ____x_ABI_CWindows_CUI_CShell_CITaskbarManagerStatics_FWD_DEFINED__

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
        namespace UI {
            namespace Shell {
                class ShareWindowCommandSource;
            } /* Shell */
        } /* UI */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace UI {
            namespace Shell {
                class ShareWindowCommandEventArgs;
            } /* Shell */
        } /* UI */
    } /* Windows */
} /* ABI */

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#ifndef DEF___FITypedEventHandler_2_Windows__CUI__CShell__CShareWindowCommandSource_Windows__CUI__CShell__CShareWindowCommandEventArgs_USE
#define DEF___FITypedEventHandler_2_Windows__CUI__CShell__CShareWindowCommandSource_Windows__CUI__CShell__CShareWindowCommandEventArgs_USE
#if !defined(RO_NO_TEMPLATE_NAME)
namespace ABI { namespace Windows { namespace Foundation {
template <>
struct __declspec(uuid("e42513f4-d11b-511d-aedc-9f44ee28df04"))
ITypedEventHandler<ABI::Windows::UI::Shell::ShareWindowCommandSource*, ABI::Windows::UI::Shell::ShareWindowCommandEventArgs*> : ITypedEventHandler_impl<ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::UI::Shell::ShareWindowCommandSource*, ABI::Windows::UI::Shell::IShareWindowCommandSource*>, ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::UI::Shell::ShareWindowCommandEventArgs*, ABI::Windows::UI::Shell::IShareWindowCommandEventArgs*>>
{
    static const wchar_t* z_get_rc_name_impl()
    {
        return L"Windows.Foundation.TypedEventHandler`2<Windows.UI.Shell.ShareWindowCommandSource, Windows.UI.Shell.ShareWindowCommandEventArgs>";
    }
};
// Define a typedef for the parameterized interface specialization's mangled name.
// This allows code which uses the mangled name for the parameterized interface to access the
// correct parameterized interface specialization.
typedef ITypedEventHandler<ABI::Windows::UI::Shell::ShareWindowCommandSource*, ABI::Windows::UI::Shell::ShareWindowCommandEventArgs*> __FITypedEventHandler_2_Windows__CUI__CShell__CShareWindowCommandSource_Windows__CUI__CShell__CShareWindowCommandEventArgs_t;
#define __FITypedEventHandler_2_Windows__CUI__CShell__CShareWindowCommandSource_Windows__CUI__CShell__CShareWindowCommandEventArgs ABI::Windows::Foundation::__FITypedEventHandler_2_Windows__CUI__CShell__CShareWindowCommandSource_Windows__CUI__CShell__CShareWindowCommandEventArgs_t
/* Foundation */ } /* Windows */ } /* ABI */ }

#endif // !defined(RO_NO_TEMPLATE_NAME)
#endif /* DEF___FITypedEventHandler_2_Windows__CUI__CShell__CShareWindowCommandSource_Windows__CUI__CShell__CShareWindowCommandEventArgs_USE */

#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

namespace ABI {
    namespace Windows {
        namespace ApplicationModel {
            namespace Core {
                class AppListEntry;
            } /* Core */
        } /* ApplicationModel */
    } /* Windows */
} /* ABI */

#ifndef ____x_ABI_CWindows_CApplicationModel_CCore_CIAppListEntry_FWD_DEFINED__
#define ____x_ABI_CWindows_CApplicationModel_CCore_CIAppListEntry_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace ApplicationModel {
            namespace Core {
                interface IAppListEntry;
            } /* Core */
        } /* ApplicationModel */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CApplicationModel_CCore_CIAppListEntry ABI::Windows::ApplicationModel::Core::IAppListEntry

#endif // ____x_ABI_CWindows_CApplicationModel_CCore_CIAppListEntry_FWD_DEFINED__

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
            namespace StartScreen {
                class SecondaryTile;
            } /* StartScreen */
        } /* UI */
    } /* Windows */
} /* ABI */

#ifndef ____x_ABI_CWindows_CUI_CStartScreen_CISecondaryTile_FWD_DEFINED__
#define ____x_ABI_CWindows_CUI_CStartScreen_CISecondaryTile_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace UI {
            namespace StartScreen {
                interface ISecondaryTile;
            } /* StartScreen */
        } /* UI */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CUI_CStartScreen_CISecondaryTile ABI::Windows::UI::StartScreen::ISecondaryTile

#endif // ____x_ABI_CWindows_CUI_CStartScreen_CISecondaryTile_FWD_DEFINED__

namespace ABI {
    namespace Windows {
        namespace UI {
            typedef struct WindowId WindowId;
        } /* UI */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace UI {
            namespace Shell {
                typedef enum SecurityAppKind : int SecurityAppKind;
            } /* Shell */
        } /* UI */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace UI {
            namespace Shell {
                typedef enum SecurityAppState : int SecurityAppState;
            } /* Shell */
        } /* UI */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace UI {
            namespace Shell {
                typedef enum SecurityAppSubstatus : int SecurityAppSubstatus;
            } /* Shell */
        } /* UI */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace UI {
            namespace Shell {
                typedef enum ShareWindowCommand : int ShareWindowCommand;
            } /* Shell */
        } /* UI */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace UI {
            namespace Shell {
                class TaskbarManager;
            } /* Shell */
        } /* UI */
    } /* Windows */
} /* ABI */

/*
 *
 * Struct Windows.UI.Shell.SecurityAppKind
 *
 * Introduced to Windows.UI.Shell.SecurityAppManagerContract in version 1.0
 *
 */
#if WINDOWS_UI_SHELL_SECURITYAPPMANAGERCONTRACT_VERSION >= 0x10000
namespace ABI {
    namespace Windows {
        namespace UI {
            namespace Shell {
                enum SecurityAppKind : int
                {
                    SecurityAppKind_WebProtection = 0,
                };
            } /* Shell */
        } /* UI */
    } /* Windows */
} /* ABI */
#endif // WINDOWS_UI_SHELL_SECURITYAPPMANAGERCONTRACT_VERSION >= 0x10000

/*
 *
 * Struct Windows.UI.Shell.SecurityAppState
 *
 * Introduced to Windows.UI.Shell.SecurityAppManagerContract in version 1.0
 *
 */
#if WINDOWS_UI_SHELL_SECURITYAPPMANAGERCONTRACT_VERSION >= 0x10000
namespace ABI {
    namespace Windows {
        namespace UI {
            namespace Shell {
                enum SecurityAppState : int
                {
                    SecurityAppState_Disabled = 0,
                    SecurityAppState_Enabled = 1,
                };
            } /* Shell */
        } /* UI */
    } /* Windows */
} /* ABI */
#endif // WINDOWS_UI_SHELL_SECURITYAPPMANAGERCONTRACT_VERSION >= 0x10000

/*
 *
 * Struct Windows.UI.Shell.SecurityAppSubstatus
 *
 * Introduced to Windows.UI.Shell.SecurityAppManagerContract in version 1.0
 *
 */
#if WINDOWS_UI_SHELL_SECURITYAPPMANAGERCONTRACT_VERSION >= 0x10000
namespace ABI {
    namespace Windows {
        namespace UI {
            namespace Shell {
                enum SecurityAppSubstatus : int
                {
                    SecurityAppSubstatus_Undetermined = 0,
                    SecurityAppSubstatus_NoActionNeeded = 1,
                    SecurityAppSubstatus_ActionRecommended = 2,
                    SecurityAppSubstatus_ActionNeeded = 3,
                };
            } /* Shell */
        } /* UI */
    } /* Windows */
} /* ABI */
#endif // WINDOWS_UI_SHELL_SECURITYAPPMANAGERCONTRACT_VERSION >= 0x10000

/*
 *
 * Struct Windows.UI.Shell.ShareWindowCommand
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
namespace ABI {
    namespace Windows {
        namespace UI {
            namespace Shell {
                enum ShareWindowCommand : int
                {
                    ShareWindowCommand_None = 0,
                    ShareWindowCommand_StartSharing = 1,
                    ShareWindowCommand_StopSharing = 2,
                };
            } /* Shell */
        } /* UI */
    } /* Windows */
} /* ABI */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Interface Windows.UI.Shell.IAdaptiveCard
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CWindows_CUI_CShell_CIAdaptiveCard_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CUI_CShell_CIAdaptiveCard_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_UI_Shell_IAdaptiveCard[] = L"Windows.UI.Shell.IAdaptiveCard";
namespace ABI {
    namespace Windows {
        namespace UI {
            namespace Shell {
                MIDL_INTERFACE("72d0568c-a274-41cd-82a8-989d40b9b05e")
                IAdaptiveCard : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE ToJson(
                        HSTRING* result
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IAdaptiveCard = _uuidof(IAdaptiveCard);
            } /* Shell */
        } /* UI */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CUI_CShell_CIAdaptiveCard;
#endif /* !defined(____x_ABI_CWindows_CUI_CShell_CIAdaptiveCard_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Interface Windows.UI.Shell.IAdaptiveCardBuilderStatics
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CWindows_CUI_CShell_CIAdaptiveCardBuilderStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CUI_CShell_CIAdaptiveCardBuilderStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_UI_Shell_IAdaptiveCardBuilderStatics[] = L"Windows.UI.Shell.IAdaptiveCardBuilderStatics";
namespace ABI {
    namespace Windows {
        namespace UI {
            namespace Shell {
                MIDL_INTERFACE("766d8f08-d3fe-4347-a0bc-b9ea9a6dc28e")
                IAdaptiveCardBuilderStatics : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE CreateAdaptiveCardFromJson(
                        HSTRING value,
                        ABI::Windows::UI::Shell::IAdaptiveCard** result
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IAdaptiveCardBuilderStatics = _uuidof(IAdaptiveCardBuilderStatics);
            } /* Shell */
        } /* UI */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CUI_CShell_CIAdaptiveCardBuilderStatics;
#endif /* !defined(____x_ABI_CWindows_CUI_CShell_CIAdaptiveCardBuilderStatics_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Interface Windows.UI.Shell.ISecurityAppManager
 *
 * Introduced to Windows.UI.Shell.SecurityAppManagerContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.UI.Shell.SecurityAppManager
 *
 */
#if WINDOWS_UI_SHELL_SECURITYAPPMANAGERCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CUI_CShell_CISecurityAppManager_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CUI_CShell_CISecurityAppManager_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_UI_Shell_ISecurityAppManager[] = L"Windows.UI.Shell.ISecurityAppManager";
namespace ABI {
    namespace Windows {
        namespace UI {
            namespace Shell {
                MIDL_INTERFACE("96ac500c-aed4-561d-bde8-953520343a2d")
                ISecurityAppManager : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE Register(
                        ABI::Windows::UI::Shell::SecurityAppKind kind,
                        HSTRING displayName,
                        ABI::Windows::Foundation::IUriRuntimeClass* detailsUri,
                        boolean registerPerUser,
                        GUID* result
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE Unregister(
                        ABI::Windows::UI::Shell::SecurityAppKind kind,
                        GUID guidRegistration
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE UpdateState(
                        ABI::Windows::UI::Shell::SecurityAppKind kind,
                        GUID guidRegistration,
                        ABI::Windows::UI::Shell::SecurityAppState state,
                        ABI::Windows::UI::Shell::SecurityAppSubstatus substatus,
                        ABI::Windows::Foundation::IUriRuntimeClass* detailsUri
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_ISecurityAppManager = _uuidof(ISecurityAppManager);
            } /* Shell */
        } /* UI */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CUI_CShell_CISecurityAppManager;
#endif /* !defined(____x_ABI_CWindows_CUI_CShell_CISecurityAppManager_INTERFACE_DEFINED__) */
#endif // WINDOWS_UI_SHELL_SECURITYAPPMANAGERCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.UI.Shell.IShareWindowCommandEventArgs
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Interface is a part of the implementation of type Windows.UI.Shell.ShareWindowCommandEventArgs
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____x_ABI_CWindows_CUI_CShell_CIShareWindowCommandEventArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CUI_CShell_CIShareWindowCommandEventArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_UI_Shell_IShareWindowCommandEventArgs[] = L"Windows.UI.Shell.IShareWindowCommandEventArgs";
namespace ABI {
    namespace Windows {
        namespace UI {
            namespace Shell {
                MIDL_INTERFACE("4578dc09-a523-5756-a995-e4feb991fff0")
                IShareWindowCommandEventArgs : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE get_WindowId(
                        ABI::Windows::UI::WindowId* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_Command(
                        ABI::Windows::UI::Shell::ShareWindowCommand* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE put_Command(
                        ABI::Windows::UI::Shell::ShareWindowCommand value
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IShareWindowCommandEventArgs = _uuidof(IShareWindowCommandEventArgs);
            } /* Shell */
        } /* UI */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CUI_CShell_CIShareWindowCommandEventArgs;
#endif /* !defined(____x_ABI_CWindows_CUI_CShell_CIShareWindowCommandEventArgs_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Interface Windows.UI.Shell.IShareWindowCommandSource
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Interface is a part of the implementation of type Windows.UI.Shell.ShareWindowCommandSource
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSource_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSource_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_UI_Shell_IShareWindowCommandSource[] = L"Windows.UI.Shell.IShareWindowCommandSource";
namespace ABI {
    namespace Windows {
        namespace UI {
            namespace Shell {
                MIDL_INTERFACE("cb3b7ae3-6b9c-561e-bccc-61e68e0abfef")
                IShareWindowCommandSource : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE Start(void) = 0;
                    virtual HRESULT STDMETHODCALLTYPE Stop(void) = 0;
                    virtual HRESULT STDMETHODCALLTYPE ReportCommandChanged(void) = 0;
                    virtual HRESULT STDMETHODCALLTYPE add_CommandRequested(
                        __FITypedEventHandler_2_Windows__CUI__CShell__CShareWindowCommandSource_Windows__CUI__CShell__CShareWindowCommandEventArgs* handler,
                        EventRegistrationToken* token
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE remove_CommandRequested(
                        EventRegistrationToken token
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE add_CommandInvoked(
                        __FITypedEventHandler_2_Windows__CUI__CShell__CShareWindowCommandSource_Windows__CUI__CShell__CShareWindowCommandEventArgs* handler,
                        EventRegistrationToken* token
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE remove_CommandInvoked(
                        EventRegistrationToken token
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IShareWindowCommandSource = _uuidof(IShareWindowCommandSource);
            } /* Shell */
        } /* UI */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSource;
#endif /* !defined(____x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSource_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Interface Windows.UI.Shell.IShareWindowCommandSourceStatics
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Interface is a part of the implementation of type Windows.UI.Shell.ShareWindowCommandSource
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSourceStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSourceStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_UI_Shell_IShareWindowCommandSourceStatics[] = L"Windows.UI.Shell.IShareWindowCommandSourceStatics";
namespace ABI {
    namespace Windows {
        namespace UI {
            namespace Shell {
                MIDL_INTERFACE("b0eb6656-9cac-517c-b6c7-8ef715084295")
                IShareWindowCommandSourceStatics : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE GetForCurrentView(
                        ABI::Windows::UI::Shell::IShareWindowCommandSource** result
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IShareWindowCommandSourceStatics = _uuidof(IShareWindowCommandSourceStatics);
            } /* Shell */
        } /* UI */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSourceStatics;
#endif /* !defined(____x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSourceStatics_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Interface Windows.UI.Shell.ITaskbarManager
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 * Interface is a part of the implementation of type Windows.UI.Shell.TaskbarManager
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CWindows_CUI_CShell_CITaskbarManager_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CUI_CShell_CITaskbarManager_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_UI_Shell_ITaskbarManager[] = L"Windows.UI.Shell.ITaskbarManager";
namespace ABI {
    namespace Windows {
        namespace UI {
            namespace Shell {
                MIDL_INTERFACE("87490a19-1ad9-49f4-b2e8-86738dc5ac40")
                ITaskbarManager : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE get_IsSupported(
                        boolean* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_IsPinningAllowed(
                        boolean* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE IsCurrentAppPinnedAsync(
                        __FIAsyncOperation_1_boolean** operation
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE IsAppListEntryPinnedAsync(
                        ABI::Windows::ApplicationModel::Core::IAppListEntry* appListEntry,
                        __FIAsyncOperation_1_boolean** operation
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE RequestPinCurrentAppAsync(
                        __FIAsyncOperation_1_boolean** operation
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE RequestPinAppListEntryAsync(
                        ABI::Windows::ApplicationModel::Core::IAppListEntry* appListEntry,
                        __FIAsyncOperation_1_boolean** operation
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_ITaskbarManager = _uuidof(ITaskbarManager);
            } /* Shell */
        } /* UI */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CUI_CShell_CITaskbarManager;
#endif /* !defined(____x_ABI_CWindows_CUI_CShell_CITaskbarManager_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Interface Windows.UI.Shell.ITaskbarManager2
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 7.0
 *
 * Interface is a part of the implementation of type Windows.UI.Shell.TaskbarManager
 *
 * Any object which implements this interface must also implement the following interfaces:
 *     Windows.UI.Shell.ITaskbarManager
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x70000
#if !defined(____x_ABI_CWindows_CUI_CShell_CITaskbarManager2_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CUI_CShell_CITaskbarManager2_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_UI_Shell_ITaskbarManager2[] = L"Windows.UI.Shell.ITaskbarManager2";
namespace ABI {
    namespace Windows {
        namespace UI {
            namespace Shell {
                MIDL_INTERFACE("79f0a06e-7b02-4911-918c-dee0bbd20ba4")
                ITaskbarManager2 : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE IsSecondaryTilePinnedAsync(
                        HSTRING tileId,
                        __FIAsyncOperation_1_boolean** operation
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE RequestPinSecondaryTileAsync(
                        ABI::Windows::UI::StartScreen::ISecondaryTile* secondaryTile,
                        __FIAsyncOperation_1_boolean** operation
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE TryUnpinSecondaryTileAsync(
                        HSTRING tileId,
                        __FIAsyncOperation_1_boolean** operation
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_ITaskbarManager2 = _uuidof(ITaskbarManager2);
            } /* Shell */
        } /* UI */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CUI_CShell_CITaskbarManager2;
#endif /* !defined(____x_ABI_CWindows_CUI_CShell_CITaskbarManager2_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x70000

/*
 *
 * Interface Windows.UI.Shell.ITaskbarManagerStatics
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 * Interface is a part of the implementation of type Windows.UI.Shell.TaskbarManager
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CWindows_CUI_CShell_CITaskbarManagerStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CUI_CShell_CITaskbarManagerStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_UI_Shell_ITaskbarManagerStatics[] = L"Windows.UI.Shell.ITaskbarManagerStatics";
namespace ABI {
    namespace Windows {
        namespace UI {
            namespace Shell {
                MIDL_INTERFACE("db32ab74-de52-4fe6-b7b6-95ff9f8395df")
                ITaskbarManagerStatics : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE GetDefault(
                        ABI::Windows::UI::Shell::ITaskbarManager** result
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_ITaskbarManagerStatics = _uuidof(ITaskbarManagerStatics);
            } /* Shell */
        } /* UI */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CUI_CShell_CITaskbarManagerStatics;
#endif /* !defined(____x_ABI_CWindows_CUI_CShell_CITaskbarManagerStatics_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Class Windows.UI.Shell.AdaptiveCardBuilder
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Windows.UI.Shell.IAdaptiveCardBuilderStatics interface starting with version 5.0 of the Windows.Foundation.UniversalApiContract API contract
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#ifndef RUNTIMECLASS_Windows_UI_Shell_AdaptiveCardBuilder_DEFINED
#define RUNTIMECLASS_Windows_UI_Shell_AdaptiveCardBuilder_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_UI_Shell_AdaptiveCardBuilder[] = L"Windows.UI.Shell.AdaptiveCardBuilder";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Class Windows.UI.Shell.SecurityAppManager
 *
 * Introduced to Windows.UI.Shell.SecurityAppManagerContract in version 1.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via RoActivateInstance starting with version 1.0 of the Windows.UI.Shell.SecurityAppManagerContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.UI.Shell.ISecurityAppManager ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_UI_SHELL_SECURITYAPPMANAGERCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_UI_Shell_SecurityAppManager_DEFINED
#define RUNTIMECLASS_Windows_UI_Shell_SecurityAppManager_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_UI_Shell_SecurityAppManager[] = L"Windows.UI.Shell.SecurityAppManager";
#endif
#endif // WINDOWS_UI_SHELL_SECURITYAPPMANAGERCONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.UI.Shell.ShareWindowCommandEventArgs
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Class implements the following interfaces:
 *    Windows.UI.Shell.IShareWindowCommandEventArgs ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#ifndef RUNTIMECLASS_Windows_UI_Shell_ShareWindowCommandEventArgs_DEFINED
#define RUNTIMECLASS_Windows_UI_Shell_ShareWindowCommandEventArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_UI_Shell_ShareWindowCommandEventArgs[] = L"Windows.UI.Shell.ShareWindowCommandEventArgs";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Class Windows.UI.Shell.ShareWindowCommandSource
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Windows.UI.Shell.IShareWindowCommandSourceStatics interface starting with version 13.0 of the Windows.Foundation.UniversalApiContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.UI.Shell.IShareWindowCommandSource ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#ifndef RUNTIMECLASS_Windows_UI_Shell_ShareWindowCommandSource_DEFINED
#define RUNTIMECLASS_Windows_UI_Shell_ShareWindowCommandSource_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_UI_Shell_ShareWindowCommandSource[] = L"Windows.UI.Shell.ShareWindowCommandSource";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Class Windows.UI.Shell.TaskbarManager
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Windows.UI.Shell.ITaskbarManagerStatics interface starting with version 5.0 of the Windows.Foundation.UniversalApiContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.UI.Shell.ITaskbarManager ** Default Interface **
 *    Windows.UI.Shell.ITaskbarManager2
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#ifndef RUNTIMECLASS_Windows_UI_Shell_TaskbarManager_DEFINED
#define RUNTIMECLASS_Windows_UI_Shell_TaskbarManager_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_UI_Shell_TaskbarManager[] = L"Windows.UI.Shell.TaskbarManager";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

#else // !defined(__cplusplus)
/* Forward Declarations */
#ifndef ____x_ABI_CWindows_CUI_CShell_CIAdaptiveCard_FWD_DEFINED__
#define ____x_ABI_CWindows_CUI_CShell_CIAdaptiveCard_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CUI_CShell_CIAdaptiveCard __x_ABI_CWindows_CUI_CShell_CIAdaptiveCard;

#endif // ____x_ABI_CWindows_CUI_CShell_CIAdaptiveCard_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CUI_CShell_CIAdaptiveCardBuilderStatics_FWD_DEFINED__
#define ____x_ABI_CWindows_CUI_CShell_CIAdaptiveCardBuilderStatics_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CUI_CShell_CIAdaptiveCardBuilderStatics __x_ABI_CWindows_CUI_CShell_CIAdaptiveCardBuilderStatics;

#endif // ____x_ABI_CWindows_CUI_CShell_CIAdaptiveCardBuilderStatics_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CUI_CShell_CISecurityAppManager_FWD_DEFINED__
#define ____x_ABI_CWindows_CUI_CShell_CISecurityAppManager_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CUI_CShell_CISecurityAppManager __x_ABI_CWindows_CUI_CShell_CISecurityAppManager;

#endif // ____x_ABI_CWindows_CUI_CShell_CISecurityAppManager_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CUI_CShell_CIShareWindowCommandEventArgs_FWD_DEFINED__
#define ____x_ABI_CWindows_CUI_CShell_CIShareWindowCommandEventArgs_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CUI_CShell_CIShareWindowCommandEventArgs __x_ABI_CWindows_CUI_CShell_CIShareWindowCommandEventArgs;

#endif // ____x_ABI_CWindows_CUI_CShell_CIShareWindowCommandEventArgs_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSource_FWD_DEFINED__
#define ____x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSource_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSource __x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSource;

#endif // ____x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSource_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSourceStatics_FWD_DEFINED__
#define ____x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSourceStatics_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSourceStatics __x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSourceStatics;

#endif // ____x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSourceStatics_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CUI_CShell_CITaskbarManager_FWD_DEFINED__
#define ____x_ABI_CWindows_CUI_CShell_CITaskbarManager_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CUI_CShell_CITaskbarManager __x_ABI_CWindows_CUI_CShell_CITaskbarManager;

#endif // ____x_ABI_CWindows_CUI_CShell_CITaskbarManager_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CUI_CShell_CITaskbarManager2_FWD_DEFINED__
#define ____x_ABI_CWindows_CUI_CShell_CITaskbarManager2_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CUI_CShell_CITaskbarManager2 __x_ABI_CWindows_CUI_CShell_CITaskbarManager2;

#endif // ____x_ABI_CWindows_CUI_CShell_CITaskbarManager2_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CUI_CShell_CITaskbarManagerStatics_FWD_DEFINED__
#define ____x_ABI_CWindows_CUI_CShell_CITaskbarManagerStatics_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CUI_CShell_CITaskbarManagerStatics __x_ABI_CWindows_CUI_CShell_CITaskbarManagerStatics;

#endif // ____x_ABI_CWindows_CUI_CShell_CITaskbarManagerStatics_FWD_DEFINED__

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

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____FITypedEventHandler_2_Windows__CUI__CShell__CShareWindowCommandSource_Windows__CUI__CShell__CShareWindowCommandEventArgs_INTERFACE_DEFINED__)
#define ____FITypedEventHandler_2_Windows__CUI__CShell__CShareWindowCommandSource_Windows__CUI__CShell__CShareWindowCommandEventArgs_INTERFACE_DEFINED__

typedef interface __FITypedEventHandler_2_Windows__CUI__CShell__CShareWindowCommandSource_Windows__CUI__CShell__CShareWindowCommandEventArgs __FITypedEventHandler_2_Windows__CUI__CShell__CShareWindowCommandSource_Windows__CUI__CShell__CShareWindowCommandEventArgs;

//  Declare the parameterized interface IID.
EXTERN_C const IID IID___FITypedEventHandler_2_Windows__CUI__CShell__CShareWindowCommandSource_Windows__CUI__CShell__CShareWindowCommandEventArgs;

typedef struct __FITypedEventHandler_2_Windows__CUI__CShell__CShareWindowCommandSource_Windows__CUI__CShell__CShareWindowCommandEventArgsVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__FITypedEventHandler_2_Windows__CUI__CShell__CShareWindowCommandSource_Windows__CUI__CShell__CShareWindowCommandEventArgs* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__FITypedEventHandler_2_Windows__CUI__CShell__CShareWindowCommandSource_Windows__CUI__CShell__CShareWindowCommandEventArgs* This);
    ULONG (STDMETHODCALLTYPE* Release)(__FITypedEventHandler_2_Windows__CUI__CShell__CShareWindowCommandSource_Windows__CUI__CShell__CShareWindowCommandEventArgs* This);
    HRESULT (STDMETHODCALLTYPE* Invoke)(__FITypedEventHandler_2_Windows__CUI__CShell__CShareWindowCommandSource_Windows__CUI__CShell__CShareWindowCommandEventArgs* This,
        __x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSource* sender,
        __x_ABI_CWindows_CUI_CShell_CIShareWindowCommandEventArgs* args);

    END_INTERFACE
} __FITypedEventHandler_2_Windows__CUI__CShell__CShareWindowCommandSource_Windows__CUI__CShell__CShareWindowCommandEventArgsVtbl;

interface __FITypedEventHandler_2_Windows__CUI__CShell__CShareWindowCommandSource_Windows__CUI__CShell__CShareWindowCommandEventArgs
{
    CONST_VTBL struct __FITypedEventHandler_2_Windows__CUI__CShell__CShareWindowCommandSource_Windows__CUI__CShell__CShareWindowCommandEventArgsVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __FITypedEventHandler_2_Windows__CUI__CShell__CShareWindowCommandSource_Windows__CUI__CShell__CShareWindowCommandEventArgs_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __FITypedEventHandler_2_Windows__CUI__CShell__CShareWindowCommandSource_Windows__CUI__CShell__CShareWindowCommandEventArgs_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __FITypedEventHandler_2_Windows__CUI__CShell__CShareWindowCommandSource_Windows__CUI__CShell__CShareWindowCommandEventArgs_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __FITypedEventHandler_2_Windows__CUI__CShell__CShareWindowCommandSource_Windows__CUI__CShell__CShareWindowCommandEventArgs_Invoke(This, sender, args) \
    ((This)->lpVtbl->Invoke(This, sender, args))

#endif /* COBJMACROS */

#endif // ____FITypedEventHandler_2_Windows__CUI__CShell__CShareWindowCommandSource_Windows__CUI__CShell__CShareWindowCommandEventArgs_INTERFACE_DEFINED__
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

#ifndef ____x_ABI_CWindows_CApplicationModel_CCore_CIAppListEntry_FWD_DEFINED__
#define ____x_ABI_CWindows_CApplicationModel_CCore_CIAppListEntry_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CApplicationModel_CCore_CIAppListEntry __x_ABI_CWindows_CApplicationModel_CCore_CIAppListEntry;

#endif // ____x_ABI_CWindows_CApplicationModel_CCore_CIAppListEntry_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CFoundation_CIUriRuntimeClass_FWD_DEFINED__
#define ____x_ABI_CWindows_CFoundation_CIUriRuntimeClass_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CFoundation_CIUriRuntimeClass __x_ABI_CWindows_CFoundation_CIUriRuntimeClass;

#endif // ____x_ABI_CWindows_CFoundation_CIUriRuntimeClass_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CUI_CStartScreen_CISecondaryTile_FWD_DEFINED__
#define ____x_ABI_CWindows_CUI_CStartScreen_CISecondaryTile_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CUI_CStartScreen_CISecondaryTile __x_ABI_CWindows_CUI_CStartScreen_CISecondaryTile;

#endif // ____x_ABI_CWindows_CUI_CStartScreen_CISecondaryTile_FWD_DEFINED__

typedef struct __x_ABI_CWindows_CUI_CWindowId __x_ABI_CWindows_CUI_CWindowId;

typedef enum __x_ABI_CWindows_CUI_CShell_CSecurityAppKind __x_ABI_CWindows_CUI_CShell_CSecurityAppKind;

typedef enum __x_ABI_CWindows_CUI_CShell_CSecurityAppState __x_ABI_CWindows_CUI_CShell_CSecurityAppState;

typedef enum __x_ABI_CWindows_CUI_CShell_CSecurityAppSubstatus __x_ABI_CWindows_CUI_CShell_CSecurityAppSubstatus;

typedef enum __x_ABI_CWindows_CUI_CShell_CShareWindowCommand __x_ABI_CWindows_CUI_CShell_CShareWindowCommand;

/*
 *
 * Struct Windows.UI.Shell.SecurityAppKind
 *
 * Introduced to Windows.UI.Shell.SecurityAppManagerContract in version 1.0
 *
 */
#if WINDOWS_UI_SHELL_SECURITYAPPMANAGERCONTRACT_VERSION >= 0x10000
enum __x_ABI_CWindows_CUI_CShell_CSecurityAppKind
{
    SecurityAppKind_WebProtection = 0,
};
#endif // WINDOWS_UI_SHELL_SECURITYAPPMANAGERCONTRACT_VERSION >= 0x10000

/*
 *
 * Struct Windows.UI.Shell.SecurityAppState
 *
 * Introduced to Windows.UI.Shell.SecurityAppManagerContract in version 1.0
 *
 */
#if WINDOWS_UI_SHELL_SECURITYAPPMANAGERCONTRACT_VERSION >= 0x10000
enum __x_ABI_CWindows_CUI_CShell_CSecurityAppState
{
    SecurityAppState_Disabled = 0,
    SecurityAppState_Enabled = 1,
};
#endif // WINDOWS_UI_SHELL_SECURITYAPPMANAGERCONTRACT_VERSION >= 0x10000

/*
 *
 * Struct Windows.UI.Shell.SecurityAppSubstatus
 *
 * Introduced to Windows.UI.Shell.SecurityAppManagerContract in version 1.0
 *
 */
#if WINDOWS_UI_SHELL_SECURITYAPPMANAGERCONTRACT_VERSION >= 0x10000
enum __x_ABI_CWindows_CUI_CShell_CSecurityAppSubstatus
{
    SecurityAppSubstatus_Undetermined = 0,
    SecurityAppSubstatus_NoActionNeeded = 1,
    SecurityAppSubstatus_ActionRecommended = 2,
    SecurityAppSubstatus_ActionNeeded = 3,
};
#endif // WINDOWS_UI_SHELL_SECURITYAPPMANAGERCONTRACT_VERSION >= 0x10000

/*
 *
 * Struct Windows.UI.Shell.ShareWindowCommand
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
enum __x_ABI_CWindows_CUI_CShell_CShareWindowCommand
{
    ShareWindowCommand_None = 0,
    ShareWindowCommand_StartSharing = 1,
    ShareWindowCommand_StopSharing = 2,
};
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Interface Windows.UI.Shell.IAdaptiveCard
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CWindows_CUI_CShell_CIAdaptiveCard_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CUI_CShell_CIAdaptiveCard_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_UI_Shell_IAdaptiveCard[] = L"Windows.UI.Shell.IAdaptiveCard";
typedef struct __x_ABI_CWindows_CUI_CShell_CIAdaptiveCardVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CUI_CShell_CIAdaptiveCard* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CUI_CShell_CIAdaptiveCard* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CUI_CShell_CIAdaptiveCard* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CUI_CShell_CIAdaptiveCard* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CUI_CShell_CIAdaptiveCard* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CUI_CShell_CIAdaptiveCard* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* ToJson)(__x_ABI_CWindows_CUI_CShell_CIAdaptiveCard* This,
        HSTRING* result);

    END_INTERFACE
} __x_ABI_CWindows_CUI_CShell_CIAdaptiveCardVtbl;

interface __x_ABI_CWindows_CUI_CShell_CIAdaptiveCard
{
    CONST_VTBL struct __x_ABI_CWindows_CUI_CShell_CIAdaptiveCardVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CUI_CShell_CIAdaptiveCard_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CUI_CShell_CIAdaptiveCard_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CUI_CShell_CIAdaptiveCard_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CUI_CShell_CIAdaptiveCard_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CUI_CShell_CIAdaptiveCard_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CUI_CShell_CIAdaptiveCard_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CUI_CShell_CIAdaptiveCard_ToJson(This, result) \
    ((This)->lpVtbl->ToJson(This, result))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CUI_CShell_CIAdaptiveCard;
#endif /* !defined(____x_ABI_CWindows_CUI_CShell_CIAdaptiveCard_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Interface Windows.UI.Shell.IAdaptiveCardBuilderStatics
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CWindows_CUI_CShell_CIAdaptiveCardBuilderStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CUI_CShell_CIAdaptiveCardBuilderStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_UI_Shell_IAdaptiveCardBuilderStatics[] = L"Windows.UI.Shell.IAdaptiveCardBuilderStatics";
typedef struct __x_ABI_CWindows_CUI_CShell_CIAdaptiveCardBuilderStaticsVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CUI_CShell_CIAdaptiveCardBuilderStatics* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CUI_CShell_CIAdaptiveCardBuilderStatics* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CUI_CShell_CIAdaptiveCardBuilderStatics* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CUI_CShell_CIAdaptiveCardBuilderStatics* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CUI_CShell_CIAdaptiveCardBuilderStatics* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CUI_CShell_CIAdaptiveCardBuilderStatics* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* CreateAdaptiveCardFromJson)(__x_ABI_CWindows_CUI_CShell_CIAdaptiveCardBuilderStatics* This,
        HSTRING value,
        __x_ABI_CWindows_CUI_CShell_CIAdaptiveCard** result);

    END_INTERFACE
} __x_ABI_CWindows_CUI_CShell_CIAdaptiveCardBuilderStaticsVtbl;

interface __x_ABI_CWindows_CUI_CShell_CIAdaptiveCardBuilderStatics
{
    CONST_VTBL struct __x_ABI_CWindows_CUI_CShell_CIAdaptiveCardBuilderStaticsVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CUI_CShell_CIAdaptiveCardBuilderStatics_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CUI_CShell_CIAdaptiveCardBuilderStatics_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CUI_CShell_CIAdaptiveCardBuilderStatics_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CUI_CShell_CIAdaptiveCardBuilderStatics_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CUI_CShell_CIAdaptiveCardBuilderStatics_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CUI_CShell_CIAdaptiveCardBuilderStatics_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CUI_CShell_CIAdaptiveCardBuilderStatics_CreateAdaptiveCardFromJson(This, value, result) \
    ((This)->lpVtbl->CreateAdaptiveCardFromJson(This, value, result))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CUI_CShell_CIAdaptiveCardBuilderStatics;
#endif /* !defined(____x_ABI_CWindows_CUI_CShell_CIAdaptiveCardBuilderStatics_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Interface Windows.UI.Shell.ISecurityAppManager
 *
 * Introduced to Windows.UI.Shell.SecurityAppManagerContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.UI.Shell.SecurityAppManager
 *
 */
#if WINDOWS_UI_SHELL_SECURITYAPPMANAGERCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CUI_CShell_CISecurityAppManager_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CUI_CShell_CISecurityAppManager_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_UI_Shell_ISecurityAppManager[] = L"Windows.UI.Shell.ISecurityAppManager";
typedef struct __x_ABI_CWindows_CUI_CShell_CISecurityAppManagerVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CUI_CShell_CISecurityAppManager* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CUI_CShell_CISecurityAppManager* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CUI_CShell_CISecurityAppManager* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CUI_CShell_CISecurityAppManager* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CUI_CShell_CISecurityAppManager* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CUI_CShell_CISecurityAppManager* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* Register)(__x_ABI_CWindows_CUI_CShell_CISecurityAppManager* This,
        enum __x_ABI_CWindows_CUI_CShell_CSecurityAppKind kind,
        HSTRING displayName,
        __x_ABI_CWindows_CFoundation_CIUriRuntimeClass* detailsUri,
        boolean registerPerUser,
        GUID* result);
    HRESULT (STDMETHODCALLTYPE* Unregister)(__x_ABI_CWindows_CUI_CShell_CISecurityAppManager* This,
        enum __x_ABI_CWindows_CUI_CShell_CSecurityAppKind kind,
        GUID guidRegistration);
    HRESULT (STDMETHODCALLTYPE* UpdateState)(__x_ABI_CWindows_CUI_CShell_CISecurityAppManager* This,
        enum __x_ABI_CWindows_CUI_CShell_CSecurityAppKind kind,
        GUID guidRegistration,
        enum __x_ABI_CWindows_CUI_CShell_CSecurityAppState state,
        enum __x_ABI_CWindows_CUI_CShell_CSecurityAppSubstatus substatus,
        __x_ABI_CWindows_CFoundation_CIUriRuntimeClass* detailsUri);

    END_INTERFACE
} __x_ABI_CWindows_CUI_CShell_CISecurityAppManagerVtbl;

interface __x_ABI_CWindows_CUI_CShell_CISecurityAppManager
{
    CONST_VTBL struct __x_ABI_CWindows_CUI_CShell_CISecurityAppManagerVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CUI_CShell_CISecurityAppManager_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CUI_CShell_CISecurityAppManager_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CUI_CShell_CISecurityAppManager_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CUI_CShell_CISecurityAppManager_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CUI_CShell_CISecurityAppManager_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CUI_CShell_CISecurityAppManager_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CUI_CShell_CISecurityAppManager_Register(This, kind, displayName, detailsUri, registerPerUser, result) \
    ((This)->lpVtbl->Register(This, kind, displayName, detailsUri, registerPerUser, result))

#define __x_ABI_CWindows_CUI_CShell_CISecurityAppManager_Unregister(This, kind, guidRegistration) \
    ((This)->lpVtbl->Unregister(This, kind, guidRegistration))

#define __x_ABI_CWindows_CUI_CShell_CISecurityAppManager_UpdateState(This, kind, guidRegistration, state, substatus, detailsUri) \
    ((This)->lpVtbl->UpdateState(This, kind, guidRegistration, state, substatus, detailsUri))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CUI_CShell_CISecurityAppManager;
#endif /* !defined(____x_ABI_CWindows_CUI_CShell_CISecurityAppManager_INTERFACE_DEFINED__) */
#endif // WINDOWS_UI_SHELL_SECURITYAPPMANAGERCONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.UI.Shell.IShareWindowCommandEventArgs
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Interface is a part of the implementation of type Windows.UI.Shell.ShareWindowCommandEventArgs
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____x_ABI_CWindows_CUI_CShell_CIShareWindowCommandEventArgs_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CUI_CShell_CIShareWindowCommandEventArgs_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_UI_Shell_IShareWindowCommandEventArgs[] = L"Windows.UI.Shell.IShareWindowCommandEventArgs";
typedef struct __x_ABI_CWindows_CUI_CShell_CIShareWindowCommandEventArgsVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CUI_CShell_CIShareWindowCommandEventArgs* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CUI_CShell_CIShareWindowCommandEventArgs* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CUI_CShell_CIShareWindowCommandEventArgs* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CUI_CShell_CIShareWindowCommandEventArgs* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CUI_CShell_CIShareWindowCommandEventArgs* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CUI_CShell_CIShareWindowCommandEventArgs* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_WindowId)(__x_ABI_CWindows_CUI_CShell_CIShareWindowCommandEventArgs* This,
        struct __x_ABI_CWindows_CUI_CWindowId* value);
    HRESULT (STDMETHODCALLTYPE* get_Command)(__x_ABI_CWindows_CUI_CShell_CIShareWindowCommandEventArgs* This,
        enum __x_ABI_CWindows_CUI_CShell_CShareWindowCommand* value);
    HRESULT (STDMETHODCALLTYPE* put_Command)(__x_ABI_CWindows_CUI_CShell_CIShareWindowCommandEventArgs* This,
        enum __x_ABI_CWindows_CUI_CShell_CShareWindowCommand value);

    END_INTERFACE
} __x_ABI_CWindows_CUI_CShell_CIShareWindowCommandEventArgsVtbl;

interface __x_ABI_CWindows_CUI_CShell_CIShareWindowCommandEventArgs
{
    CONST_VTBL struct __x_ABI_CWindows_CUI_CShell_CIShareWindowCommandEventArgsVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CUI_CShell_CIShareWindowCommandEventArgs_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CUI_CShell_CIShareWindowCommandEventArgs_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CUI_CShell_CIShareWindowCommandEventArgs_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CUI_CShell_CIShareWindowCommandEventArgs_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CUI_CShell_CIShareWindowCommandEventArgs_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CUI_CShell_CIShareWindowCommandEventArgs_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CUI_CShell_CIShareWindowCommandEventArgs_get_WindowId(This, value) \
    ((This)->lpVtbl->get_WindowId(This, value))

#define __x_ABI_CWindows_CUI_CShell_CIShareWindowCommandEventArgs_get_Command(This, value) \
    ((This)->lpVtbl->get_Command(This, value))

#define __x_ABI_CWindows_CUI_CShell_CIShareWindowCommandEventArgs_put_Command(This, value) \
    ((This)->lpVtbl->put_Command(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CUI_CShell_CIShareWindowCommandEventArgs;
#endif /* !defined(____x_ABI_CWindows_CUI_CShell_CIShareWindowCommandEventArgs_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Interface Windows.UI.Shell.IShareWindowCommandSource
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Interface is a part of the implementation of type Windows.UI.Shell.ShareWindowCommandSource
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSource_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSource_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_UI_Shell_IShareWindowCommandSource[] = L"Windows.UI.Shell.IShareWindowCommandSource";
typedef struct __x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSourceVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSource* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSource* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSource* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSource* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSource* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSource* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* Start)(__x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSource* This);
    HRESULT (STDMETHODCALLTYPE* Stop)(__x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSource* This);
    HRESULT (STDMETHODCALLTYPE* ReportCommandChanged)(__x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSource* This);
    HRESULT (STDMETHODCALLTYPE* add_CommandRequested)(__x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSource* This,
        __FITypedEventHandler_2_Windows__CUI__CShell__CShareWindowCommandSource_Windows__CUI__CShell__CShareWindowCommandEventArgs* handler,
        EventRegistrationToken* token);
    HRESULT (STDMETHODCALLTYPE* remove_CommandRequested)(__x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSource* This,
        EventRegistrationToken token);
    HRESULT (STDMETHODCALLTYPE* add_CommandInvoked)(__x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSource* This,
        __FITypedEventHandler_2_Windows__CUI__CShell__CShareWindowCommandSource_Windows__CUI__CShell__CShareWindowCommandEventArgs* handler,
        EventRegistrationToken* token);
    HRESULT (STDMETHODCALLTYPE* remove_CommandInvoked)(__x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSource* This,
        EventRegistrationToken token);

    END_INTERFACE
} __x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSourceVtbl;

interface __x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSource
{
    CONST_VTBL struct __x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSourceVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSource_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSource_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSource_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSource_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSource_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSource_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSource_Start(This) \
    ((This)->lpVtbl->Start(This))

#define __x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSource_Stop(This) \
    ((This)->lpVtbl->Stop(This))

#define __x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSource_ReportCommandChanged(This) \
    ((This)->lpVtbl->ReportCommandChanged(This))

#define __x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSource_add_CommandRequested(This, handler, token) \
    ((This)->lpVtbl->add_CommandRequested(This, handler, token))

#define __x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSource_remove_CommandRequested(This, token) \
    ((This)->lpVtbl->remove_CommandRequested(This, token))

#define __x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSource_add_CommandInvoked(This, handler, token) \
    ((This)->lpVtbl->add_CommandInvoked(This, handler, token))

#define __x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSource_remove_CommandInvoked(This, token) \
    ((This)->lpVtbl->remove_CommandInvoked(This, token))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSource;
#endif /* !defined(____x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSource_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Interface Windows.UI.Shell.IShareWindowCommandSourceStatics
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Interface is a part of the implementation of type Windows.UI.Shell.ShareWindowCommandSource
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#if !defined(____x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSourceStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSourceStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_UI_Shell_IShareWindowCommandSourceStatics[] = L"Windows.UI.Shell.IShareWindowCommandSourceStatics";
typedef struct __x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSourceStaticsVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSourceStatics* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSourceStatics* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSourceStatics* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSourceStatics* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSourceStatics* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSourceStatics* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* GetForCurrentView)(__x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSourceStatics* This,
        __x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSource** result);

    END_INTERFACE
} __x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSourceStaticsVtbl;

interface __x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSourceStatics
{
    CONST_VTBL struct __x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSourceStaticsVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSourceStatics_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSourceStatics_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSourceStatics_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSourceStatics_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSourceStatics_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSourceStatics_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSourceStatics_GetForCurrentView(This, result) \
    ((This)->lpVtbl->GetForCurrentView(This, result))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSourceStatics;
#endif /* !defined(____x_ABI_CWindows_CUI_CShell_CIShareWindowCommandSourceStatics_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Interface Windows.UI.Shell.ITaskbarManager
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 * Interface is a part of the implementation of type Windows.UI.Shell.TaskbarManager
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CWindows_CUI_CShell_CITaskbarManager_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CUI_CShell_CITaskbarManager_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_UI_Shell_ITaskbarManager[] = L"Windows.UI.Shell.ITaskbarManager";
typedef struct __x_ABI_CWindows_CUI_CShell_CITaskbarManagerVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CUI_CShell_CITaskbarManager* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CUI_CShell_CITaskbarManager* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CUI_CShell_CITaskbarManager* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CUI_CShell_CITaskbarManager* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CUI_CShell_CITaskbarManager* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CUI_CShell_CITaskbarManager* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_IsSupported)(__x_ABI_CWindows_CUI_CShell_CITaskbarManager* This,
        boolean* value);
    HRESULT (STDMETHODCALLTYPE* get_IsPinningAllowed)(__x_ABI_CWindows_CUI_CShell_CITaskbarManager* This,
        boolean* value);
    HRESULT (STDMETHODCALLTYPE* IsCurrentAppPinnedAsync)(__x_ABI_CWindows_CUI_CShell_CITaskbarManager* This,
        __FIAsyncOperation_1_boolean** operation);
    HRESULT (STDMETHODCALLTYPE* IsAppListEntryPinnedAsync)(__x_ABI_CWindows_CUI_CShell_CITaskbarManager* This,
        __x_ABI_CWindows_CApplicationModel_CCore_CIAppListEntry* appListEntry,
        __FIAsyncOperation_1_boolean** operation);
    HRESULT (STDMETHODCALLTYPE* RequestPinCurrentAppAsync)(__x_ABI_CWindows_CUI_CShell_CITaskbarManager* This,
        __FIAsyncOperation_1_boolean** operation);
    HRESULT (STDMETHODCALLTYPE* RequestPinAppListEntryAsync)(__x_ABI_CWindows_CUI_CShell_CITaskbarManager* This,
        __x_ABI_CWindows_CApplicationModel_CCore_CIAppListEntry* appListEntry,
        __FIAsyncOperation_1_boolean** operation);

    END_INTERFACE
} __x_ABI_CWindows_CUI_CShell_CITaskbarManagerVtbl;

interface __x_ABI_CWindows_CUI_CShell_CITaskbarManager
{
    CONST_VTBL struct __x_ABI_CWindows_CUI_CShell_CITaskbarManagerVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CUI_CShell_CITaskbarManager_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CUI_CShell_CITaskbarManager_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CUI_CShell_CITaskbarManager_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CUI_CShell_CITaskbarManager_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CUI_CShell_CITaskbarManager_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CUI_CShell_CITaskbarManager_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CUI_CShell_CITaskbarManager_get_IsSupported(This, value) \
    ((This)->lpVtbl->get_IsSupported(This, value))

#define __x_ABI_CWindows_CUI_CShell_CITaskbarManager_get_IsPinningAllowed(This, value) \
    ((This)->lpVtbl->get_IsPinningAllowed(This, value))

#define __x_ABI_CWindows_CUI_CShell_CITaskbarManager_IsCurrentAppPinnedAsync(This, operation) \
    ((This)->lpVtbl->IsCurrentAppPinnedAsync(This, operation))

#define __x_ABI_CWindows_CUI_CShell_CITaskbarManager_IsAppListEntryPinnedAsync(This, appListEntry, operation) \
    ((This)->lpVtbl->IsAppListEntryPinnedAsync(This, appListEntry, operation))

#define __x_ABI_CWindows_CUI_CShell_CITaskbarManager_RequestPinCurrentAppAsync(This, operation) \
    ((This)->lpVtbl->RequestPinCurrentAppAsync(This, operation))

#define __x_ABI_CWindows_CUI_CShell_CITaskbarManager_RequestPinAppListEntryAsync(This, appListEntry, operation) \
    ((This)->lpVtbl->RequestPinAppListEntryAsync(This, appListEntry, operation))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CUI_CShell_CITaskbarManager;
#endif /* !defined(____x_ABI_CWindows_CUI_CShell_CITaskbarManager_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Interface Windows.UI.Shell.ITaskbarManager2
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 7.0
 *
 * Interface is a part of the implementation of type Windows.UI.Shell.TaskbarManager
 *
 * Any object which implements this interface must also implement the following interfaces:
 *     Windows.UI.Shell.ITaskbarManager
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x70000
#if !defined(____x_ABI_CWindows_CUI_CShell_CITaskbarManager2_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CUI_CShell_CITaskbarManager2_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_UI_Shell_ITaskbarManager2[] = L"Windows.UI.Shell.ITaskbarManager2";
typedef struct __x_ABI_CWindows_CUI_CShell_CITaskbarManager2Vtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CUI_CShell_CITaskbarManager2* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CUI_CShell_CITaskbarManager2* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CUI_CShell_CITaskbarManager2* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CUI_CShell_CITaskbarManager2* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CUI_CShell_CITaskbarManager2* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CUI_CShell_CITaskbarManager2* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* IsSecondaryTilePinnedAsync)(__x_ABI_CWindows_CUI_CShell_CITaskbarManager2* This,
        HSTRING tileId,
        __FIAsyncOperation_1_boolean** operation);
    HRESULT (STDMETHODCALLTYPE* RequestPinSecondaryTileAsync)(__x_ABI_CWindows_CUI_CShell_CITaskbarManager2* This,
        __x_ABI_CWindows_CUI_CStartScreen_CISecondaryTile* secondaryTile,
        __FIAsyncOperation_1_boolean** operation);
    HRESULT (STDMETHODCALLTYPE* TryUnpinSecondaryTileAsync)(__x_ABI_CWindows_CUI_CShell_CITaskbarManager2* This,
        HSTRING tileId,
        __FIAsyncOperation_1_boolean** operation);

    END_INTERFACE
} __x_ABI_CWindows_CUI_CShell_CITaskbarManager2Vtbl;

interface __x_ABI_CWindows_CUI_CShell_CITaskbarManager2
{
    CONST_VTBL struct __x_ABI_CWindows_CUI_CShell_CITaskbarManager2Vtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CUI_CShell_CITaskbarManager2_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CUI_CShell_CITaskbarManager2_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CUI_CShell_CITaskbarManager2_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CUI_CShell_CITaskbarManager2_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CUI_CShell_CITaskbarManager2_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CUI_CShell_CITaskbarManager2_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CUI_CShell_CITaskbarManager2_IsSecondaryTilePinnedAsync(This, tileId, operation) \
    ((This)->lpVtbl->IsSecondaryTilePinnedAsync(This, tileId, operation))

#define __x_ABI_CWindows_CUI_CShell_CITaskbarManager2_RequestPinSecondaryTileAsync(This, secondaryTile, operation) \
    ((This)->lpVtbl->RequestPinSecondaryTileAsync(This, secondaryTile, operation))

#define __x_ABI_CWindows_CUI_CShell_CITaskbarManager2_TryUnpinSecondaryTileAsync(This, tileId, operation) \
    ((This)->lpVtbl->TryUnpinSecondaryTileAsync(This, tileId, operation))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CUI_CShell_CITaskbarManager2;
#endif /* !defined(____x_ABI_CWindows_CUI_CShell_CITaskbarManager2_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x70000

/*
 *
 * Interface Windows.UI.Shell.ITaskbarManagerStatics
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 * Interface is a part of the implementation of type Windows.UI.Shell.TaskbarManager
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#if !defined(____x_ABI_CWindows_CUI_CShell_CITaskbarManagerStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CUI_CShell_CITaskbarManagerStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_UI_Shell_ITaskbarManagerStatics[] = L"Windows.UI.Shell.ITaskbarManagerStatics";
typedef struct __x_ABI_CWindows_CUI_CShell_CITaskbarManagerStaticsVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CUI_CShell_CITaskbarManagerStatics* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CUI_CShell_CITaskbarManagerStatics* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CUI_CShell_CITaskbarManagerStatics* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CUI_CShell_CITaskbarManagerStatics* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CUI_CShell_CITaskbarManagerStatics* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CUI_CShell_CITaskbarManagerStatics* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* GetDefault)(__x_ABI_CWindows_CUI_CShell_CITaskbarManagerStatics* This,
        __x_ABI_CWindows_CUI_CShell_CITaskbarManager** result);

    END_INTERFACE
} __x_ABI_CWindows_CUI_CShell_CITaskbarManagerStaticsVtbl;

interface __x_ABI_CWindows_CUI_CShell_CITaskbarManagerStatics
{
    CONST_VTBL struct __x_ABI_CWindows_CUI_CShell_CITaskbarManagerStaticsVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CUI_CShell_CITaskbarManagerStatics_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CUI_CShell_CITaskbarManagerStatics_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CUI_CShell_CITaskbarManagerStatics_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CUI_CShell_CITaskbarManagerStatics_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CUI_CShell_CITaskbarManagerStatics_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CUI_CShell_CITaskbarManagerStatics_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CUI_CShell_CITaskbarManagerStatics_GetDefault(This, result) \
    ((This)->lpVtbl->GetDefault(This, result))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CUI_CShell_CITaskbarManagerStatics;
#endif /* !defined(____x_ABI_CWindows_CUI_CShell_CITaskbarManagerStatics_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Class Windows.UI.Shell.AdaptiveCardBuilder
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Windows.UI.Shell.IAdaptiveCardBuilderStatics interface starting with version 5.0 of the Windows.Foundation.UniversalApiContract API contract
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#ifndef RUNTIMECLASS_Windows_UI_Shell_AdaptiveCardBuilder_DEFINED
#define RUNTIMECLASS_Windows_UI_Shell_AdaptiveCardBuilder_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_UI_Shell_AdaptiveCardBuilder[] = L"Windows.UI.Shell.AdaptiveCardBuilder";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000

/*
 *
 * Class Windows.UI.Shell.SecurityAppManager
 *
 * Introduced to Windows.UI.Shell.SecurityAppManagerContract in version 1.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via RoActivateInstance starting with version 1.0 of the Windows.UI.Shell.SecurityAppManagerContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.UI.Shell.ISecurityAppManager ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_UI_SHELL_SECURITYAPPMANAGERCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_UI_Shell_SecurityAppManager_DEFINED
#define RUNTIMECLASS_Windows_UI_Shell_SecurityAppManager_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_UI_Shell_SecurityAppManager[] = L"Windows.UI.Shell.SecurityAppManager";
#endif
#endif // WINDOWS_UI_SHELL_SECURITYAPPMANAGERCONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.UI.Shell.ShareWindowCommandEventArgs
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * Class implements the following interfaces:
 *    Windows.UI.Shell.IShareWindowCommandEventArgs ** Default Interface **
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#ifndef RUNTIMECLASS_Windows_UI_Shell_ShareWindowCommandEventArgs_DEFINED
#define RUNTIMECLASS_Windows_UI_Shell_ShareWindowCommandEventArgs_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_UI_Shell_ShareWindowCommandEventArgs[] = L"Windows.UI.Shell.ShareWindowCommandEventArgs";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Class Windows.UI.Shell.ShareWindowCommandSource
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 13.0
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Windows.UI.Shell.IShareWindowCommandSourceStatics interface starting with version 13.0 of the Windows.Foundation.UniversalApiContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.UI.Shell.IShareWindowCommandSource ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000
#ifndef RUNTIMECLASS_Windows_UI_Shell_ShareWindowCommandSource_DEFINED
#define RUNTIMECLASS_Windows_UI_Shell_ShareWindowCommandSource_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_UI_Shell_ShareWindowCommandSource[] = L"Windows.UI.Shell.ShareWindowCommandSource";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0xd0000

/*
 *
 * Class Windows.UI.Shell.TaskbarManager
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 5.0
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Windows.UI.Shell.ITaskbarManagerStatics interface starting with version 5.0 of the Windows.Foundation.UniversalApiContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.UI.Shell.ITaskbarManager ** Default Interface **
 *    Windows.UI.Shell.ITaskbarManager2
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x50000
#ifndef RUNTIMECLASS_Windows_UI_Shell_TaskbarManager_DEFINED
#define RUNTIMECLASS_Windows_UI_Shell_TaskbarManager_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_UI_Shell_TaskbarManager[] = L"Windows.UI.Shell.TaskbarManager";
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
#endif // __windows2Eui2Eshell_p_h__

#endif // __windows2Eui2Eshell_h__
