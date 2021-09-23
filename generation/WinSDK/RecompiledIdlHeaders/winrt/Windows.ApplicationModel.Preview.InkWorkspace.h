
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
#ifndef __windows2Eapplicationmodel2Epreview2Einkworkspace_h__
#define __windows2Eapplicationmodel2Epreview2Einkworkspace_h__
#ifndef __windows2Eapplicationmodel2Epreview2Einkworkspace_p_h__
#define __windows2Eapplicationmodel2Epreview2Einkworkspace_p_h__


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
#if !defined(WINDOWS_APPLICATIONMODEL_PREVIEW_INKWORKSPACE_PREVIEWINKWORKSPACECONTRACT_VERSION)
#define WINDOWS_APPLICATIONMODEL_PREVIEW_INKWORKSPACE_PREVIEWINKWORKSPACECONTRACT_VERSION 0x10000
#endif // defined(WINDOWS_APPLICATIONMODEL_PREVIEW_INKWORKSPACE_PREVIEWINKWORKSPACECONTRACT_VERSION)

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
#include "Windows.Graphics.Imaging.h"

#if defined(__cplusplus) && !defined(CINTERFACE)
/* Forward Declarations */
#ifndef ____x_ABI_CWindows_CApplicationModel_CPreview_CInkWorkspace_CIInkWorkspaceHostedAppManager_FWD_DEFINED__
#define ____x_ABI_CWindows_CApplicationModel_CPreview_CInkWorkspace_CIInkWorkspaceHostedAppManager_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace ApplicationModel {
            namespace Preview {
                namespace InkWorkspace {
                    interface IInkWorkspaceHostedAppManager;
                } /* InkWorkspace */
            } /* Preview */
        } /* ApplicationModel */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CApplicationModel_CPreview_CInkWorkspace_CIInkWorkspaceHostedAppManager ABI::Windows::ApplicationModel::Preview::InkWorkspace::IInkWorkspaceHostedAppManager

#endif // ____x_ABI_CWindows_CApplicationModel_CPreview_CInkWorkspace_CIInkWorkspaceHostedAppManager_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CApplicationModel_CPreview_CInkWorkspace_CIInkWorkspaceHostedAppManagerStatics_FWD_DEFINED__
#define ____x_ABI_CWindows_CApplicationModel_CPreview_CInkWorkspace_CIInkWorkspaceHostedAppManagerStatics_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace ApplicationModel {
            namespace Preview {
                namespace InkWorkspace {
                    interface IInkWorkspaceHostedAppManagerStatics;
                } /* InkWorkspace */
            } /* Preview */
        } /* ApplicationModel */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CApplicationModel_CPreview_CInkWorkspace_CIInkWorkspaceHostedAppManagerStatics ABI::Windows::ApplicationModel::Preview::InkWorkspace::IInkWorkspaceHostedAppManagerStatics

#endif // ____x_ABI_CWindows_CApplicationModel_CPreview_CInkWorkspace_CIInkWorkspaceHostedAppManagerStatics_FWD_DEFINED__

// Parameterized interface forward declarations (C++)

// Collection interface definitions
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
        namespace Graphics {
            namespace Imaging {
                class SoftwareBitmap;
            } /* Imaging */
        } /* Graphics */
    } /* Windows */
} /* ABI */

#ifndef ____x_ABI_CWindows_CGraphics_CImaging_CISoftwareBitmap_FWD_DEFINED__
#define ____x_ABI_CWindows_CGraphics_CImaging_CISoftwareBitmap_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Graphics {
            namespace Imaging {
                interface ISoftwareBitmap;
            } /* Imaging */
        } /* Graphics */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CGraphics_CImaging_CISoftwareBitmap ABI::Windows::Graphics::Imaging::ISoftwareBitmap

#endif // ____x_ABI_CWindows_CGraphics_CImaging_CISoftwareBitmap_FWD_DEFINED__

namespace ABI {
    namespace Windows {
        namespace ApplicationModel {
            namespace Preview {
                namespace InkWorkspace {
                    class InkWorkspaceHostedAppManager;
                } /* InkWorkspace */
            } /* Preview */
        } /* ApplicationModel */
    } /* Windows */
} /* ABI */

/*
 *
 * Interface Windows.ApplicationModel.Preview.InkWorkspace.IInkWorkspaceHostedAppManager
 *
 * Introduced to Windows.ApplicationModel.Preview.InkWorkspace.PreviewInkWorkspaceContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.ApplicationModel.Preview.InkWorkspace.InkWorkspaceHostedAppManager
 *
 */
#if WINDOWS_APPLICATIONMODEL_PREVIEW_INKWORKSPACE_PREVIEWINKWORKSPACECONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CApplicationModel_CPreview_CInkWorkspace_CIInkWorkspaceHostedAppManager_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CApplicationModel_CPreview_CInkWorkspace_CIInkWorkspaceHostedAppManager_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_ApplicationModel_Preview_InkWorkspace_IInkWorkspaceHostedAppManager[] = L"Windows.ApplicationModel.Preview.InkWorkspace.IInkWorkspaceHostedAppManager";
namespace ABI {
    namespace Windows {
        namespace ApplicationModel {
            namespace Preview {
                namespace InkWorkspace {
                    MIDL_INTERFACE("fe0a7990-5e59-4bb7-8a63-7d218cd96300")
                    IInkWorkspaceHostedAppManager : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE SetThumbnailAsync(
                            ABI::Windows::Graphics::Imaging::ISoftwareBitmap* bitmap,
                            ABI::Windows::Foundation::IAsyncAction** action
                            ) = 0;
                    };

                    extern MIDL_CONST_ID IID& IID_IInkWorkspaceHostedAppManager = _uuidof(IInkWorkspaceHostedAppManager);
                } /* InkWorkspace */
            } /* Preview */
        } /* ApplicationModel */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CApplicationModel_CPreview_CInkWorkspace_CIInkWorkspaceHostedAppManager;
#endif /* !defined(____x_ABI_CWindows_CApplicationModel_CPreview_CInkWorkspace_CIInkWorkspaceHostedAppManager_INTERFACE_DEFINED__) */
#endif // WINDOWS_APPLICATIONMODEL_PREVIEW_INKWORKSPACE_PREVIEWINKWORKSPACECONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.ApplicationModel.Preview.InkWorkspace.IInkWorkspaceHostedAppManagerStatics
 *
 * Introduced to Windows.ApplicationModel.Preview.InkWorkspace.PreviewInkWorkspaceContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.ApplicationModel.Preview.InkWorkspace.InkWorkspaceHostedAppManager
 *
 */
#if WINDOWS_APPLICATIONMODEL_PREVIEW_INKWORKSPACE_PREVIEWINKWORKSPACECONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CApplicationModel_CPreview_CInkWorkspace_CIInkWorkspaceHostedAppManagerStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CApplicationModel_CPreview_CInkWorkspace_CIInkWorkspaceHostedAppManagerStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_ApplicationModel_Preview_InkWorkspace_IInkWorkspaceHostedAppManagerStatics[] = L"Windows.ApplicationModel.Preview.InkWorkspace.IInkWorkspaceHostedAppManagerStatics";
namespace ABI {
    namespace Windows {
        namespace ApplicationModel {
            namespace Preview {
                namespace InkWorkspace {
                    MIDL_INTERFACE("cbfd8cc5-a162-4bc4-84ee-e8716d5233c5")
                    IInkWorkspaceHostedAppManagerStatics : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE GetForCurrentApp(
                            ABI::Windows::ApplicationModel::Preview::InkWorkspace::IInkWorkspaceHostedAppManager** current
                            ) = 0;
                    };

                    extern MIDL_CONST_ID IID& IID_IInkWorkspaceHostedAppManagerStatics = _uuidof(IInkWorkspaceHostedAppManagerStatics);
                } /* InkWorkspace */
            } /* Preview */
        } /* ApplicationModel */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CApplicationModel_CPreview_CInkWorkspace_CIInkWorkspaceHostedAppManagerStatics;
#endif /* !defined(____x_ABI_CWindows_CApplicationModel_CPreview_CInkWorkspace_CIInkWorkspaceHostedAppManagerStatics_INTERFACE_DEFINED__) */
#endif // WINDOWS_APPLICATIONMODEL_PREVIEW_INKWORKSPACE_PREVIEWINKWORKSPACECONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.ApplicationModel.Preview.InkWorkspace.InkWorkspaceHostedAppManager
 *
 * Introduced to Windows.ApplicationModel.Preview.InkWorkspace.PreviewInkWorkspaceContract in version 1.0
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Windows.ApplicationModel.Preview.InkWorkspace.IInkWorkspaceHostedAppManagerStatics interface starting with version 1.0 of the Windows.ApplicationModel.Preview.InkWorkspace.PreviewInkWorkspaceContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.ApplicationModel.Preview.InkWorkspace.IInkWorkspaceHostedAppManager ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_APPLICATIONMODEL_PREVIEW_INKWORKSPACE_PREVIEWINKWORKSPACECONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_ApplicationModel_Preview_InkWorkspace_InkWorkspaceHostedAppManager_DEFINED
#define RUNTIMECLASS_Windows_ApplicationModel_Preview_InkWorkspace_InkWorkspaceHostedAppManager_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_ApplicationModel_Preview_InkWorkspace_InkWorkspaceHostedAppManager[] = L"Windows.ApplicationModel.Preview.InkWorkspace.InkWorkspaceHostedAppManager";
#endif
#endif // WINDOWS_APPLICATIONMODEL_PREVIEW_INKWORKSPACE_PREVIEWINKWORKSPACECONTRACT_VERSION >= 0x10000

#else // !defined(__cplusplus)
/* Forward Declarations */
#ifndef ____x_ABI_CWindows_CApplicationModel_CPreview_CInkWorkspace_CIInkWorkspaceHostedAppManager_FWD_DEFINED__
#define ____x_ABI_CWindows_CApplicationModel_CPreview_CInkWorkspace_CIInkWorkspaceHostedAppManager_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CApplicationModel_CPreview_CInkWorkspace_CIInkWorkspaceHostedAppManager __x_ABI_CWindows_CApplicationModel_CPreview_CInkWorkspace_CIInkWorkspaceHostedAppManager;

#endif // ____x_ABI_CWindows_CApplicationModel_CPreview_CInkWorkspace_CIInkWorkspaceHostedAppManager_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CApplicationModel_CPreview_CInkWorkspace_CIInkWorkspaceHostedAppManagerStatics_FWD_DEFINED__
#define ____x_ABI_CWindows_CApplicationModel_CPreview_CInkWorkspace_CIInkWorkspaceHostedAppManagerStatics_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CApplicationModel_CPreview_CInkWorkspace_CIInkWorkspaceHostedAppManagerStatics __x_ABI_CWindows_CApplicationModel_CPreview_CInkWorkspace_CIInkWorkspaceHostedAppManagerStatics;

#endif // ____x_ABI_CWindows_CApplicationModel_CPreview_CInkWorkspace_CIInkWorkspaceHostedAppManagerStatics_FWD_DEFINED__

// Parameterized interface forward declarations (C)

// Collection interface definitions

#ifndef ____x_ABI_CWindows_CFoundation_CIAsyncAction_FWD_DEFINED__
#define ____x_ABI_CWindows_CFoundation_CIAsyncAction_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CFoundation_CIAsyncAction __x_ABI_CWindows_CFoundation_CIAsyncAction;

#endif // ____x_ABI_CWindows_CFoundation_CIAsyncAction_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CGraphics_CImaging_CISoftwareBitmap_FWD_DEFINED__
#define ____x_ABI_CWindows_CGraphics_CImaging_CISoftwareBitmap_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CGraphics_CImaging_CISoftwareBitmap __x_ABI_CWindows_CGraphics_CImaging_CISoftwareBitmap;

#endif // ____x_ABI_CWindows_CGraphics_CImaging_CISoftwareBitmap_FWD_DEFINED__

/*
 *
 * Interface Windows.ApplicationModel.Preview.InkWorkspace.IInkWorkspaceHostedAppManager
 *
 * Introduced to Windows.ApplicationModel.Preview.InkWorkspace.PreviewInkWorkspaceContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.ApplicationModel.Preview.InkWorkspace.InkWorkspaceHostedAppManager
 *
 */
#if WINDOWS_APPLICATIONMODEL_PREVIEW_INKWORKSPACE_PREVIEWINKWORKSPACECONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CApplicationModel_CPreview_CInkWorkspace_CIInkWorkspaceHostedAppManager_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CApplicationModel_CPreview_CInkWorkspace_CIInkWorkspaceHostedAppManager_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_ApplicationModel_Preview_InkWorkspace_IInkWorkspaceHostedAppManager[] = L"Windows.ApplicationModel.Preview.InkWorkspace.IInkWorkspaceHostedAppManager";
typedef struct __x_ABI_CWindows_CApplicationModel_CPreview_CInkWorkspace_CIInkWorkspaceHostedAppManagerVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CApplicationModel_CPreview_CInkWorkspace_CIInkWorkspaceHostedAppManager* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CApplicationModel_CPreview_CInkWorkspace_CIInkWorkspaceHostedAppManager* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CApplicationModel_CPreview_CInkWorkspace_CIInkWorkspaceHostedAppManager* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CApplicationModel_CPreview_CInkWorkspace_CIInkWorkspaceHostedAppManager* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CApplicationModel_CPreview_CInkWorkspace_CIInkWorkspaceHostedAppManager* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CApplicationModel_CPreview_CInkWorkspace_CIInkWorkspaceHostedAppManager* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* SetThumbnailAsync)(__x_ABI_CWindows_CApplicationModel_CPreview_CInkWorkspace_CIInkWorkspaceHostedAppManager* This,
        __x_ABI_CWindows_CGraphics_CImaging_CISoftwareBitmap* bitmap,
        __x_ABI_CWindows_CFoundation_CIAsyncAction** action);

    END_INTERFACE
} __x_ABI_CWindows_CApplicationModel_CPreview_CInkWorkspace_CIInkWorkspaceHostedAppManagerVtbl;

interface __x_ABI_CWindows_CApplicationModel_CPreview_CInkWorkspace_CIInkWorkspaceHostedAppManager
{
    CONST_VTBL struct __x_ABI_CWindows_CApplicationModel_CPreview_CInkWorkspace_CIInkWorkspaceHostedAppManagerVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CApplicationModel_CPreview_CInkWorkspace_CIInkWorkspaceHostedAppManager_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CApplicationModel_CPreview_CInkWorkspace_CIInkWorkspaceHostedAppManager_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CApplicationModel_CPreview_CInkWorkspace_CIInkWorkspaceHostedAppManager_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CApplicationModel_CPreview_CInkWorkspace_CIInkWorkspaceHostedAppManager_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CApplicationModel_CPreview_CInkWorkspace_CIInkWorkspaceHostedAppManager_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CApplicationModel_CPreview_CInkWorkspace_CIInkWorkspaceHostedAppManager_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CApplicationModel_CPreview_CInkWorkspace_CIInkWorkspaceHostedAppManager_SetThumbnailAsync(This, bitmap, action) \
    ((This)->lpVtbl->SetThumbnailAsync(This, bitmap, action))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CApplicationModel_CPreview_CInkWorkspace_CIInkWorkspaceHostedAppManager;
#endif /* !defined(____x_ABI_CWindows_CApplicationModel_CPreview_CInkWorkspace_CIInkWorkspaceHostedAppManager_INTERFACE_DEFINED__) */
#endif // WINDOWS_APPLICATIONMODEL_PREVIEW_INKWORKSPACE_PREVIEWINKWORKSPACECONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.ApplicationModel.Preview.InkWorkspace.IInkWorkspaceHostedAppManagerStatics
 *
 * Introduced to Windows.ApplicationModel.Preview.InkWorkspace.PreviewInkWorkspaceContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.ApplicationModel.Preview.InkWorkspace.InkWorkspaceHostedAppManager
 *
 */
#if WINDOWS_APPLICATIONMODEL_PREVIEW_INKWORKSPACE_PREVIEWINKWORKSPACECONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CApplicationModel_CPreview_CInkWorkspace_CIInkWorkspaceHostedAppManagerStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CApplicationModel_CPreview_CInkWorkspace_CIInkWorkspaceHostedAppManagerStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_ApplicationModel_Preview_InkWorkspace_IInkWorkspaceHostedAppManagerStatics[] = L"Windows.ApplicationModel.Preview.InkWorkspace.IInkWorkspaceHostedAppManagerStatics";
typedef struct __x_ABI_CWindows_CApplicationModel_CPreview_CInkWorkspace_CIInkWorkspaceHostedAppManagerStaticsVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CApplicationModel_CPreview_CInkWorkspace_CIInkWorkspaceHostedAppManagerStatics* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CApplicationModel_CPreview_CInkWorkspace_CIInkWorkspaceHostedAppManagerStatics* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CApplicationModel_CPreview_CInkWorkspace_CIInkWorkspaceHostedAppManagerStatics* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CApplicationModel_CPreview_CInkWorkspace_CIInkWorkspaceHostedAppManagerStatics* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CApplicationModel_CPreview_CInkWorkspace_CIInkWorkspaceHostedAppManagerStatics* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CApplicationModel_CPreview_CInkWorkspace_CIInkWorkspaceHostedAppManagerStatics* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* GetForCurrentApp)(__x_ABI_CWindows_CApplicationModel_CPreview_CInkWorkspace_CIInkWorkspaceHostedAppManagerStatics* This,
        __x_ABI_CWindows_CApplicationModel_CPreview_CInkWorkspace_CIInkWorkspaceHostedAppManager** current);

    END_INTERFACE
} __x_ABI_CWindows_CApplicationModel_CPreview_CInkWorkspace_CIInkWorkspaceHostedAppManagerStaticsVtbl;

interface __x_ABI_CWindows_CApplicationModel_CPreview_CInkWorkspace_CIInkWorkspaceHostedAppManagerStatics
{
    CONST_VTBL struct __x_ABI_CWindows_CApplicationModel_CPreview_CInkWorkspace_CIInkWorkspaceHostedAppManagerStaticsVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CApplicationModel_CPreview_CInkWorkspace_CIInkWorkspaceHostedAppManagerStatics_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CApplicationModel_CPreview_CInkWorkspace_CIInkWorkspaceHostedAppManagerStatics_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CApplicationModel_CPreview_CInkWorkspace_CIInkWorkspaceHostedAppManagerStatics_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CApplicationModel_CPreview_CInkWorkspace_CIInkWorkspaceHostedAppManagerStatics_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CApplicationModel_CPreview_CInkWorkspace_CIInkWorkspaceHostedAppManagerStatics_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CApplicationModel_CPreview_CInkWorkspace_CIInkWorkspaceHostedAppManagerStatics_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CApplicationModel_CPreview_CInkWorkspace_CIInkWorkspaceHostedAppManagerStatics_GetForCurrentApp(This, current) \
    ((This)->lpVtbl->GetForCurrentApp(This, current))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CApplicationModel_CPreview_CInkWorkspace_CIInkWorkspaceHostedAppManagerStatics;
#endif /* !defined(____x_ABI_CWindows_CApplicationModel_CPreview_CInkWorkspace_CIInkWorkspaceHostedAppManagerStatics_INTERFACE_DEFINED__) */
#endif // WINDOWS_APPLICATIONMODEL_PREVIEW_INKWORKSPACE_PREVIEWINKWORKSPACECONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.ApplicationModel.Preview.InkWorkspace.InkWorkspaceHostedAppManager
 *
 * Introduced to Windows.ApplicationModel.Preview.InkWorkspace.PreviewInkWorkspaceContract in version 1.0
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Windows.ApplicationModel.Preview.InkWorkspace.IInkWorkspaceHostedAppManagerStatics interface starting with version 1.0 of the Windows.ApplicationModel.Preview.InkWorkspace.PreviewInkWorkspaceContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.ApplicationModel.Preview.InkWorkspace.IInkWorkspaceHostedAppManager ** Default Interface **
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_APPLICATIONMODEL_PREVIEW_INKWORKSPACE_PREVIEWINKWORKSPACECONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_ApplicationModel_Preview_InkWorkspace_InkWorkspaceHostedAppManager_DEFINED
#define RUNTIMECLASS_Windows_ApplicationModel_Preview_InkWorkspace_InkWorkspaceHostedAppManager_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_ApplicationModel_Preview_InkWorkspace_InkWorkspaceHostedAppManager[] = L"Windows.ApplicationModel.Preview.InkWorkspace.InkWorkspaceHostedAppManager";
#endif
#endif // WINDOWS_APPLICATIONMODEL_PREVIEW_INKWORKSPACE_PREVIEWINKWORKSPACECONTRACT_VERSION >= 0x10000

#endif // defined(__cplusplus)
#pragma pop_macro("MIDL_CONST_ID")
// Restore the original value of the 'DEPRECATED' macro
#pragma pop_macro("DEPRECATED")

#ifdef __clang__
#pragma clang diagnostic pop // deprecated-declarations
#else
#pragma warning(pop)
#endif
#endif // __windows2Eapplicationmodel2Epreview2Einkworkspace_p_h__

#endif // __windows2Eapplicationmodel2Epreview2Einkworkspace_h__
