
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
#ifndef __windows2Eui2Einput2Epreview_h__
#define __windows2Eui2Einput2Epreview_h__
#ifndef __windows2Eui2Einput2Epreview_p_h__
#define __windows2Eui2Einput2Epreview_p_h__


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
#define WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION 0xa0000
#endif // defined(WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION)

#endif // defined(SPECIFIC_API_CONTRACT_DEFINITIONS)


// Header files for imported files
#include "inspectable.h"
#include "AsyncInfo.h"
#include "EventToken.h"
#include "windowscontracts.h"
#include "Windows.Foundation.h"
#include "Windows.UI.Input.h"
#include "Windows.UI.WindowManagement.h"

#if defined(__cplusplus) && !defined(CINTERFACE)
/* Forward Declarations */
#ifndef ____x_ABI_CWindows_CUI_CInput_CPreview_CIInputActivationListenerPreviewStatics_FWD_DEFINED__
#define ____x_ABI_CWindows_CUI_CInput_CPreview_CIInputActivationListenerPreviewStatics_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace UI {
            namespace Input {
                namespace Preview {
                    interface IInputActivationListenerPreviewStatics;
                } /* Preview */
            } /* Input */
        } /* UI */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CUI_CInput_CPreview_CIInputActivationListenerPreviewStatics ABI::Windows::UI::Input::Preview::IInputActivationListenerPreviewStatics

#endif // ____x_ABI_CWindows_CUI_CInput_CPreview_CIInputActivationListenerPreviewStatics_FWD_DEFINED__

// Parameterized interface forward declarations (C++)

// Collection interface definitions
namespace ABI {
    namespace Windows {
        namespace UI {
            namespace Input {
                class InputActivationListener;
            } /* Input */
        } /* UI */
    } /* Windows */
} /* ABI */

#ifndef ____x_ABI_CWindows_CUI_CInput_CIInputActivationListener_FWD_DEFINED__
#define ____x_ABI_CWindows_CUI_CInput_CIInputActivationListener_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace UI {
            namespace Input {
                interface IInputActivationListener;
            } /* Input */
        } /* UI */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CUI_CInput_CIInputActivationListener ABI::Windows::UI::Input::IInputActivationListener

#endif // ____x_ABI_CWindows_CUI_CInput_CIInputActivationListener_FWD_DEFINED__

namespace ABI {
    namespace Windows {
        namespace UI {
            namespace WindowManagement {
                class AppWindow;
            } /* WindowManagement */
        } /* UI */
    } /* Windows */
} /* ABI */

#ifndef ____x_ABI_CWindows_CUI_CWindowManagement_CIAppWindow_FWD_DEFINED__
#define ____x_ABI_CWindows_CUI_CWindowManagement_CIAppWindow_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace UI {
            namespace WindowManagement {
                interface IAppWindow;
            } /* WindowManagement */
        } /* UI */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CUI_CWindowManagement_CIAppWindow ABI::Windows::UI::WindowManagement::IAppWindow

#endif // ____x_ABI_CWindows_CUI_CWindowManagement_CIAppWindow_FWD_DEFINED__

/*
 *
 * Interface Windows.UI.Input.Preview.IInputActivationListenerPreviewStatics
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 8.0
 *
 * Interface is a part of the implementation of type Windows.UI.Input.Preview.InputActivationListenerPreview
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x80000
#if !defined(____x_ABI_CWindows_CUI_CInput_CPreview_CIInputActivationListenerPreviewStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CUI_CInput_CPreview_CIInputActivationListenerPreviewStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_UI_Input_Preview_IInputActivationListenerPreviewStatics[] = L"Windows.UI.Input.Preview.IInputActivationListenerPreviewStatics";
namespace ABI {
    namespace Windows {
        namespace UI {
            namespace Input {
                namespace Preview {
                    MIDL_INTERFACE("f0551ce5-0de6-5be0-a589-f737201a4582")
                    IInputActivationListenerPreviewStatics : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE CreateForApplicationWindow(
                            ABI::Windows::UI::WindowManagement::IAppWindow* window,
                            ABI::Windows::UI::Input::IInputActivationListener** result
                            ) = 0;
                    };

                    extern MIDL_CONST_ID IID& IID_IInputActivationListenerPreviewStatics = _uuidof(IInputActivationListenerPreviewStatics);
                } /* Preview */
            } /* Input */
        } /* UI */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CUI_CInput_CPreview_CIInputActivationListenerPreviewStatics;
#endif /* !defined(____x_ABI_CWindows_CUI_CInput_CPreview_CIInputActivationListenerPreviewStatics_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x80000

/*
 *
 * Class Windows.UI.Input.Preview.InputActivationListenerPreview
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 8.0
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Windows.UI.Input.Preview.IInputActivationListenerPreviewStatics interface starting with version 8.0 of the Windows.Foundation.UniversalApiContract API contract
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x80000
#ifndef RUNTIMECLASS_Windows_UI_Input_Preview_InputActivationListenerPreview_DEFINED
#define RUNTIMECLASS_Windows_UI_Input_Preview_InputActivationListenerPreview_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_UI_Input_Preview_InputActivationListenerPreview[] = L"Windows.UI.Input.Preview.InputActivationListenerPreview";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x80000

#else // !defined(__cplusplus)
/* Forward Declarations */
#ifndef ____x_ABI_CWindows_CUI_CInput_CPreview_CIInputActivationListenerPreviewStatics_FWD_DEFINED__
#define ____x_ABI_CWindows_CUI_CInput_CPreview_CIInputActivationListenerPreviewStatics_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CUI_CInput_CPreview_CIInputActivationListenerPreviewStatics __x_ABI_CWindows_CUI_CInput_CPreview_CIInputActivationListenerPreviewStatics;

#endif // ____x_ABI_CWindows_CUI_CInput_CPreview_CIInputActivationListenerPreviewStatics_FWD_DEFINED__

// Parameterized interface forward declarations (C)

// Collection interface definitions

#ifndef ____x_ABI_CWindows_CUI_CInput_CIInputActivationListener_FWD_DEFINED__
#define ____x_ABI_CWindows_CUI_CInput_CIInputActivationListener_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CUI_CInput_CIInputActivationListener __x_ABI_CWindows_CUI_CInput_CIInputActivationListener;

#endif // ____x_ABI_CWindows_CUI_CInput_CIInputActivationListener_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CUI_CWindowManagement_CIAppWindow_FWD_DEFINED__
#define ____x_ABI_CWindows_CUI_CWindowManagement_CIAppWindow_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CUI_CWindowManagement_CIAppWindow __x_ABI_CWindows_CUI_CWindowManagement_CIAppWindow;

#endif // ____x_ABI_CWindows_CUI_CWindowManagement_CIAppWindow_FWD_DEFINED__

/*
 *
 * Interface Windows.UI.Input.Preview.IInputActivationListenerPreviewStatics
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 8.0
 *
 * Interface is a part of the implementation of type Windows.UI.Input.Preview.InputActivationListenerPreview
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x80000
#if !defined(____x_ABI_CWindows_CUI_CInput_CPreview_CIInputActivationListenerPreviewStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CUI_CInput_CPreview_CIInputActivationListenerPreviewStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_UI_Input_Preview_IInputActivationListenerPreviewStatics[] = L"Windows.UI.Input.Preview.IInputActivationListenerPreviewStatics";
typedef struct __x_ABI_CWindows_CUI_CInput_CPreview_CIInputActivationListenerPreviewStaticsVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CUI_CInput_CPreview_CIInputActivationListenerPreviewStatics* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CUI_CInput_CPreview_CIInputActivationListenerPreviewStatics* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CUI_CInput_CPreview_CIInputActivationListenerPreviewStatics* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CUI_CInput_CPreview_CIInputActivationListenerPreviewStatics* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CUI_CInput_CPreview_CIInputActivationListenerPreviewStatics* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CUI_CInput_CPreview_CIInputActivationListenerPreviewStatics* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* CreateForApplicationWindow)(__x_ABI_CWindows_CUI_CInput_CPreview_CIInputActivationListenerPreviewStatics* This,
        __x_ABI_CWindows_CUI_CWindowManagement_CIAppWindow* window,
        __x_ABI_CWindows_CUI_CInput_CIInputActivationListener** result);

    END_INTERFACE
} __x_ABI_CWindows_CUI_CInput_CPreview_CIInputActivationListenerPreviewStaticsVtbl;

interface __x_ABI_CWindows_CUI_CInput_CPreview_CIInputActivationListenerPreviewStatics
{
    CONST_VTBL struct __x_ABI_CWindows_CUI_CInput_CPreview_CIInputActivationListenerPreviewStaticsVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CUI_CInput_CPreview_CIInputActivationListenerPreviewStatics_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CUI_CInput_CPreview_CIInputActivationListenerPreviewStatics_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CUI_CInput_CPreview_CIInputActivationListenerPreviewStatics_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CUI_CInput_CPreview_CIInputActivationListenerPreviewStatics_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CUI_CInput_CPreview_CIInputActivationListenerPreviewStatics_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CUI_CInput_CPreview_CIInputActivationListenerPreviewStatics_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CUI_CInput_CPreview_CIInputActivationListenerPreviewStatics_CreateForApplicationWindow(This, window, result) \
    ((This)->lpVtbl->CreateForApplicationWindow(This, window, result))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CUI_CInput_CPreview_CIInputActivationListenerPreviewStatics;
#endif /* !defined(____x_ABI_CWindows_CUI_CInput_CPreview_CIInputActivationListenerPreviewStatics_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x80000

/*
 *
 * Class Windows.UI.Input.Preview.InputActivationListenerPreview
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 8.0
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Windows.UI.Input.Preview.IInputActivationListenerPreviewStatics interface starting with version 8.0 of the Windows.Foundation.UniversalApiContract API contract
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x80000
#ifndef RUNTIMECLASS_Windows_UI_Input_Preview_InputActivationListenerPreview_DEFINED
#define RUNTIMECLASS_Windows_UI_Input_Preview_InputActivationListenerPreview_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_UI_Input_Preview_InputActivationListenerPreview[] = L"Windows.UI.Input.Preview.InputActivationListenerPreview";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x80000

#endif // defined(__cplusplus)
#pragma pop_macro("MIDL_CONST_ID")
// Restore the original value of the 'DEPRECATED' macro
#pragma pop_macro("DEPRECATED")

#ifdef __clang__
#pragma clang diagnostic pop // deprecated-declarations
#else
#pragma warning(pop)
#endif
#endif // __windows2Eui2Einput2Epreview_p_h__

#endif // __windows2Eui2Einput2Epreview_h__
