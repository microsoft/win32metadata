
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
#ifndef __windows2Egaming2Einput2Epreview_h__
#define __windows2Egaming2Einput2Epreview_h__
#ifndef __windows2Egaming2Einput2Epreview_p_h__
#define __windows2Egaming2Einput2Epreview_p_h__


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
#if !defined(WINDOWS_GAMING_INPUT_GAMINGINPUTPREVIEWCONTRACT_VERSION)
#define WINDOWS_GAMING_INPUT_GAMINGINPUTPREVIEWCONTRACT_VERSION 0x10000
#endif // defined(WINDOWS_GAMING_INPUT_GAMINGINPUTPREVIEWCONTRACT_VERSION)

#endif // defined(SPECIFIC_API_CONTRACT_DEFINITIONS)


// Header files for imported files
#include "inspectable.h"
#include "AsyncInfo.h"
#include "EventToken.h"
#include "windowscontracts.h"
#include "Windows.Foundation.h"
#include "Windows.Gaming.Input.h"
#include "Windows.Gaming.Input.Custom.h"

#if defined(__cplusplus) && !defined(CINTERFACE)
/* Forward Declarations */
#ifndef ____x_ABI_CWindows_CGaming_CInput_CPreview_CIGameControllerProviderInfoStatics_FWD_DEFINED__
#define ____x_ABI_CWindows_CGaming_CInput_CPreview_CIGameControllerProviderInfoStatics_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Gaming {
            namespace Input {
                namespace Preview {
                    interface IGameControllerProviderInfoStatics;
                } /* Preview */
            } /* Input */
        } /* Gaming */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CGaming_CInput_CPreview_CIGameControllerProviderInfoStatics ABI::Windows::Gaming::Input::Preview::IGameControllerProviderInfoStatics

#endif // ____x_ABI_CWindows_CGaming_CInput_CPreview_CIGameControllerProviderInfoStatics_FWD_DEFINED__

// Parameterized interface forward declarations (C++)

// Collection interface definitions
#ifndef ____x_ABI_CWindows_CGaming_CInput_CCustom_CIGameControllerProvider_FWD_DEFINED__
#define ____x_ABI_CWindows_CGaming_CInput_CCustom_CIGameControllerProvider_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Gaming {
            namespace Input {
                namespace Custom {
                    interface IGameControllerProvider;
                } /* Custom */
            } /* Input */
        } /* Gaming */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CGaming_CInput_CCustom_CIGameControllerProvider ABI::Windows::Gaming::Input::Custom::IGameControllerProvider

#endif // ____x_ABI_CWindows_CGaming_CInput_CCustom_CIGameControllerProvider_FWD_DEFINED__

/*
 *
 * Interface Windows.Gaming.Input.Preview.IGameControllerProviderInfoStatics
 *
 * Introduced to Windows.Gaming.Input.GamingInputPreviewContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Gaming.Input.Preview.GameControllerProviderInfo
 *
 */
#if WINDOWS_GAMING_INPUT_GAMINGINPUTPREVIEWCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CGaming_CInput_CPreview_CIGameControllerProviderInfoStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CGaming_CInput_CPreview_CIGameControllerProviderInfoStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Gaming_Input_Preview_IGameControllerProviderInfoStatics[] = L"Windows.Gaming.Input.Preview.IGameControllerProviderInfoStatics";
namespace ABI {
    namespace Windows {
        namespace Gaming {
            namespace Input {
                namespace Preview {
                    MIDL_INTERFACE("0be1e6c5-d9bd-44ee-8362-488b2e464bfb")
                    IGameControllerProviderInfoStatics : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE GetParentProviderId(
                            ABI::Windows::Gaming::Input::Custom::IGameControllerProvider* provider,
                            HSTRING* value
                            ) = 0;
                        virtual HRESULT STDMETHODCALLTYPE GetProviderId(
                            ABI::Windows::Gaming::Input::Custom::IGameControllerProvider* provider,
                            HSTRING* value
                            ) = 0;
                    };

                    extern MIDL_CONST_ID IID& IID_IGameControllerProviderInfoStatics = _uuidof(IGameControllerProviderInfoStatics);
                } /* Preview */
            } /* Input */
        } /* Gaming */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CGaming_CInput_CPreview_CIGameControllerProviderInfoStatics;
#endif /* !defined(____x_ABI_CWindows_CGaming_CInput_CPreview_CIGameControllerProviderInfoStatics_INTERFACE_DEFINED__) */
#endif // WINDOWS_GAMING_INPUT_GAMINGINPUTPREVIEWCONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Gaming.Input.Preview.GameControllerProviderInfo
 *
 * Introduced to Windows.Gaming.Input.GamingInputPreviewContract in version 1.0
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Windows.Gaming.Input.Preview.IGameControllerProviderInfoStatics interface starting with version 1.0 of the Windows.Gaming.Input.GamingInputPreviewContract API contract
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_GAMING_INPUT_GAMINGINPUTPREVIEWCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Gaming_Input_Preview_GameControllerProviderInfo_DEFINED
#define RUNTIMECLASS_Windows_Gaming_Input_Preview_GameControllerProviderInfo_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Gaming_Input_Preview_GameControllerProviderInfo[] = L"Windows.Gaming.Input.Preview.GameControllerProviderInfo";
#endif
#endif // WINDOWS_GAMING_INPUT_GAMINGINPUTPREVIEWCONTRACT_VERSION >= 0x10000

#else // !defined(__cplusplus)
/* Forward Declarations */
#ifndef ____x_ABI_CWindows_CGaming_CInput_CPreview_CIGameControllerProviderInfoStatics_FWD_DEFINED__
#define ____x_ABI_CWindows_CGaming_CInput_CPreview_CIGameControllerProviderInfoStatics_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CGaming_CInput_CPreview_CIGameControllerProviderInfoStatics __x_ABI_CWindows_CGaming_CInput_CPreview_CIGameControllerProviderInfoStatics;

#endif // ____x_ABI_CWindows_CGaming_CInput_CPreview_CIGameControllerProviderInfoStatics_FWD_DEFINED__

// Parameterized interface forward declarations (C)

// Collection interface definitions

#ifndef ____x_ABI_CWindows_CGaming_CInput_CCustom_CIGameControllerProvider_FWD_DEFINED__
#define ____x_ABI_CWindows_CGaming_CInput_CCustom_CIGameControllerProvider_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CGaming_CInput_CCustom_CIGameControllerProvider __x_ABI_CWindows_CGaming_CInput_CCustom_CIGameControllerProvider;

#endif // ____x_ABI_CWindows_CGaming_CInput_CCustom_CIGameControllerProvider_FWD_DEFINED__

/*
 *
 * Interface Windows.Gaming.Input.Preview.IGameControllerProviderInfoStatics
 *
 * Introduced to Windows.Gaming.Input.GamingInputPreviewContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Gaming.Input.Preview.GameControllerProviderInfo
 *
 */
#if WINDOWS_GAMING_INPUT_GAMINGINPUTPREVIEWCONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CGaming_CInput_CPreview_CIGameControllerProviderInfoStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CGaming_CInput_CPreview_CIGameControllerProviderInfoStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Gaming_Input_Preview_IGameControllerProviderInfoStatics[] = L"Windows.Gaming.Input.Preview.IGameControllerProviderInfoStatics";
typedef struct __x_ABI_CWindows_CGaming_CInput_CPreview_CIGameControllerProviderInfoStaticsVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CGaming_CInput_CPreview_CIGameControllerProviderInfoStatics* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CGaming_CInput_CPreview_CIGameControllerProviderInfoStatics* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CGaming_CInput_CPreview_CIGameControllerProviderInfoStatics* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CGaming_CInput_CPreview_CIGameControllerProviderInfoStatics* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CGaming_CInput_CPreview_CIGameControllerProviderInfoStatics* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CGaming_CInput_CPreview_CIGameControllerProviderInfoStatics* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* GetParentProviderId)(__x_ABI_CWindows_CGaming_CInput_CPreview_CIGameControllerProviderInfoStatics* This,
        __x_ABI_CWindows_CGaming_CInput_CCustom_CIGameControllerProvider* provider,
        HSTRING* value);
    HRESULT (STDMETHODCALLTYPE* GetProviderId)(__x_ABI_CWindows_CGaming_CInput_CPreview_CIGameControllerProviderInfoStatics* This,
        __x_ABI_CWindows_CGaming_CInput_CCustom_CIGameControllerProvider* provider,
        HSTRING* value);

    END_INTERFACE
} __x_ABI_CWindows_CGaming_CInput_CPreview_CIGameControllerProviderInfoStaticsVtbl;

interface __x_ABI_CWindows_CGaming_CInput_CPreview_CIGameControllerProviderInfoStatics
{
    CONST_VTBL struct __x_ABI_CWindows_CGaming_CInput_CPreview_CIGameControllerProviderInfoStaticsVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CGaming_CInput_CPreview_CIGameControllerProviderInfoStatics_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CGaming_CInput_CPreview_CIGameControllerProviderInfoStatics_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CGaming_CInput_CPreview_CIGameControllerProviderInfoStatics_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CGaming_CInput_CPreview_CIGameControllerProviderInfoStatics_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CGaming_CInput_CPreview_CIGameControllerProviderInfoStatics_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CGaming_CInput_CPreview_CIGameControllerProviderInfoStatics_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CGaming_CInput_CPreview_CIGameControllerProviderInfoStatics_GetParentProviderId(This, provider, value) \
    ((This)->lpVtbl->GetParentProviderId(This, provider, value))

#define __x_ABI_CWindows_CGaming_CInput_CPreview_CIGameControllerProviderInfoStatics_GetProviderId(This, provider, value) \
    ((This)->lpVtbl->GetProviderId(This, provider, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CGaming_CInput_CPreview_CIGameControllerProviderInfoStatics;
#endif /* !defined(____x_ABI_CWindows_CGaming_CInput_CPreview_CIGameControllerProviderInfoStatics_INTERFACE_DEFINED__) */
#endif // WINDOWS_GAMING_INPUT_GAMINGINPUTPREVIEWCONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Gaming.Input.Preview.GameControllerProviderInfo
 *
 * Introduced to Windows.Gaming.Input.GamingInputPreviewContract in version 1.0
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Windows.Gaming.Input.Preview.IGameControllerProviderInfoStatics interface starting with version 1.0 of the Windows.Gaming.Input.GamingInputPreviewContract API contract
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_GAMING_INPUT_GAMINGINPUTPREVIEWCONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Gaming_Input_Preview_GameControllerProviderInfo_DEFINED
#define RUNTIMECLASS_Windows_Gaming_Input_Preview_GameControllerProviderInfo_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Gaming_Input_Preview_GameControllerProviderInfo[] = L"Windows.Gaming.Input.Preview.GameControllerProviderInfo";
#endif
#endif // WINDOWS_GAMING_INPUT_GAMINGINPUTPREVIEWCONTRACT_VERSION >= 0x10000

#endif // defined(__cplusplus)
#pragma pop_macro("MIDL_CONST_ID")
// Restore the original value of the 'DEPRECATED' macro
#pragma pop_macro("DEPRECATED")

#ifdef __clang__
#pragma clang diagnostic pop // deprecated-declarations
#else
#pragma warning(pop)
#endif
#endif // __windows2Egaming2Einput2Epreview_p_h__

#endif // __windows2Egaming2Einput2Epreview_h__
