
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
#ifndef __windows2Emedia2Eclosedcaptioning_h__
#define __windows2Emedia2Eclosedcaptioning_h__
#ifndef __windows2Emedia2Eclosedcaptioning_p_h__
#define __windows2Emedia2Eclosedcaptioning_p_h__


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

#endif // defined(SPECIFIC_API_CONTRACT_DEFINITIONS)


// Header files for imported files
#include "inspectable.h"
#include "AsyncInfo.h"
#include "EventToken.h"
#include "windowscontracts.h"
#include "Windows.Foundation.h"
#include "Windows.UI.h"

#if defined(__cplusplus) && !defined(CINTERFACE)
/* Forward Declarations */
#ifndef ____x_ABI_CWindows_CMedia_CClosedCaptioning_CIClosedCaptionPropertiesStatics_FWD_DEFINED__
#define ____x_ABI_CWindows_CMedia_CClosedCaptioning_CIClosedCaptionPropertiesStatics_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Media {
            namespace ClosedCaptioning {
                interface IClosedCaptionPropertiesStatics;
            } /* ClosedCaptioning */
        } /* Media */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CMedia_CClosedCaptioning_CIClosedCaptionPropertiesStatics ABI::Windows::Media::ClosedCaptioning::IClosedCaptionPropertiesStatics

#endif // ____x_ABI_CWindows_CMedia_CClosedCaptioning_CIClosedCaptionPropertiesStatics_FWD_DEFINED__

// Parameterized interface forward declarations (C++)

// Collection interface definitions
namespace ABI {
    namespace Windows {
        namespace UI {
            typedef struct Color Color;
        } /* UI */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Media {
            namespace ClosedCaptioning {
                typedef enum ClosedCaptionColor : int ClosedCaptionColor;
            } /* ClosedCaptioning */
        } /* Media */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Media {
            namespace ClosedCaptioning {
                typedef enum ClosedCaptionEdgeEffect : int ClosedCaptionEdgeEffect;
            } /* ClosedCaptioning */
        } /* Media */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Media {
            namespace ClosedCaptioning {
                typedef enum ClosedCaptionOpacity : int ClosedCaptionOpacity;
            } /* ClosedCaptioning */
        } /* Media */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Media {
            namespace ClosedCaptioning {
                typedef enum ClosedCaptionSize : int ClosedCaptionSize;
            } /* ClosedCaptioning */
        } /* Media */
    } /* Windows */
} /* ABI */

namespace ABI {
    namespace Windows {
        namespace Media {
            namespace ClosedCaptioning {
                typedef enum ClosedCaptionStyle : int ClosedCaptionStyle;
            } /* ClosedCaptioning */
        } /* Media */
    } /* Windows */
} /* ABI */

/*
 *
 * Struct Windows.Media.ClosedCaptioning.ClosedCaptionColor
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
namespace ABI {
    namespace Windows {
        namespace Media {
            namespace ClosedCaptioning {
                enum ClosedCaptionColor : int
                {
                    ClosedCaptionColor_Default = 0,
                    ClosedCaptionColor_White = 1,
                    ClosedCaptionColor_Black = 2,
                    ClosedCaptionColor_Red = 3,
                    ClosedCaptionColor_Green = 4,
                    ClosedCaptionColor_Blue = 5,
                    ClosedCaptionColor_Yellow = 6,
                    ClosedCaptionColor_Magenta = 7,
                    ClosedCaptionColor_Cyan = 8,
                };
            } /* ClosedCaptioning */
        } /* Media */
    } /* Windows */
} /* ABI */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Struct Windows.Media.ClosedCaptioning.ClosedCaptionEdgeEffect
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
namespace ABI {
    namespace Windows {
        namespace Media {
            namespace ClosedCaptioning {
                enum ClosedCaptionEdgeEffect : int
                {
                    ClosedCaptionEdgeEffect_Default = 0,
                    ClosedCaptionEdgeEffect_None = 1,
                    ClosedCaptionEdgeEffect_Raised = 2,
                    ClosedCaptionEdgeEffect_Depressed = 3,
                    ClosedCaptionEdgeEffect_Uniform = 4,
                    ClosedCaptionEdgeEffect_DropShadow = 5,
                };
            } /* ClosedCaptioning */
        } /* Media */
    } /* Windows */
} /* ABI */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Struct Windows.Media.ClosedCaptioning.ClosedCaptionOpacity
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
namespace ABI {
    namespace Windows {
        namespace Media {
            namespace ClosedCaptioning {
                enum ClosedCaptionOpacity : int
                {
                    ClosedCaptionOpacity_Default = 0,
                    ClosedCaptionOpacity_OneHundredPercent = 1,
                    ClosedCaptionOpacity_SeventyFivePercent = 2,
                    ClosedCaptionOpacity_TwentyFivePercent = 3,
                    ClosedCaptionOpacity_ZeroPercent = 4,
                };
            } /* ClosedCaptioning */
        } /* Media */
    } /* Windows */
} /* ABI */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Struct Windows.Media.ClosedCaptioning.ClosedCaptionSize
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
namespace ABI {
    namespace Windows {
        namespace Media {
            namespace ClosedCaptioning {
                enum ClosedCaptionSize : int
                {
                    ClosedCaptionSize_Default = 0,
                    ClosedCaptionSize_FiftyPercent = 1,
                    ClosedCaptionSize_OneHundredPercent = 2,
                    ClosedCaptionSize_OneHundredFiftyPercent = 3,
                    ClosedCaptionSize_TwoHundredPercent = 4,
                };
            } /* ClosedCaptioning */
        } /* Media */
    } /* Windows */
} /* ABI */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Struct Windows.Media.ClosedCaptioning.ClosedCaptionStyle
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
namespace ABI {
    namespace Windows {
        namespace Media {
            namespace ClosedCaptioning {
                enum ClosedCaptionStyle : int
                {
                    ClosedCaptionStyle_Default = 0,
                    ClosedCaptionStyle_MonospacedWithSerifs = 1,
                    ClosedCaptionStyle_ProportionalWithSerifs = 2,
                    ClosedCaptionStyle_MonospacedWithoutSerifs = 3,
                    ClosedCaptionStyle_ProportionalWithoutSerifs = 4,
                    ClosedCaptionStyle_Casual = 5,
                    ClosedCaptionStyle_Cursive = 6,
                    ClosedCaptionStyle_SmallCapitals = 7,
                };
            } /* ClosedCaptioning */
        } /* Media */
    } /* Windows */
} /* ABI */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Media.ClosedCaptioning.IClosedCaptionPropertiesStatics
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Media.ClosedCaptioning.ClosedCaptionProperties
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CMedia_CClosedCaptioning_CIClosedCaptionPropertiesStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CMedia_CClosedCaptioning_CIClosedCaptionPropertiesStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Media_ClosedCaptioning_IClosedCaptionPropertiesStatics[] = L"Windows.Media.ClosedCaptioning.IClosedCaptionPropertiesStatics";
namespace ABI {
    namespace Windows {
        namespace Media {
            namespace ClosedCaptioning {
                MIDL_INTERFACE("10aa1f84-cc30-4141-b503-5272289e0c20")
                IClosedCaptionPropertiesStatics : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE get_FontColor(
                        ABI::Windows::Media::ClosedCaptioning::ClosedCaptionColor* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_ComputedFontColor(
                        ABI::Windows::UI::Color* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_FontOpacity(
                        ABI::Windows::Media::ClosedCaptioning::ClosedCaptionOpacity* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_FontSize(
                        ABI::Windows::Media::ClosedCaptioning::ClosedCaptionSize* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_FontStyle(
                        ABI::Windows::Media::ClosedCaptioning::ClosedCaptionStyle* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_FontEffect(
                        ABI::Windows::Media::ClosedCaptioning::ClosedCaptionEdgeEffect* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_BackgroundColor(
                        ABI::Windows::Media::ClosedCaptioning::ClosedCaptionColor* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_ComputedBackgroundColor(
                        ABI::Windows::UI::Color* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_BackgroundOpacity(
                        ABI::Windows::Media::ClosedCaptioning::ClosedCaptionOpacity* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_RegionColor(
                        ABI::Windows::Media::ClosedCaptioning::ClosedCaptionColor* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_ComputedRegionColor(
                        ABI::Windows::UI::Color* value
                        ) = 0;
                    virtual HRESULT STDMETHODCALLTYPE get_RegionOpacity(
                        ABI::Windows::Media::ClosedCaptioning::ClosedCaptionOpacity* value
                        ) = 0;
                };

                extern MIDL_CONST_ID IID& IID_IClosedCaptionPropertiesStatics = _uuidof(IClosedCaptionPropertiesStatics);
            } /* ClosedCaptioning */
        } /* Media */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CMedia_CClosedCaptioning_CIClosedCaptionPropertiesStatics;
#endif /* !defined(____x_ABI_CWindows_CMedia_CClosedCaptioning_CIClosedCaptionPropertiesStatics_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Media.ClosedCaptioning.ClosedCaptionProperties
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Windows.Media.ClosedCaptioning.IClosedCaptionPropertiesStatics interface starting with version 1.0 of the Windows.Foundation.UniversalApiContract API contract
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Media_ClosedCaptioning_ClosedCaptionProperties_DEFINED
#define RUNTIMECLASS_Windows_Media_ClosedCaptioning_ClosedCaptionProperties_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Media_ClosedCaptioning_ClosedCaptionProperties[] = L"Windows.Media.ClosedCaptioning.ClosedCaptionProperties";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#else // !defined(__cplusplus)
/* Forward Declarations */
#ifndef ____x_ABI_CWindows_CMedia_CClosedCaptioning_CIClosedCaptionPropertiesStatics_FWD_DEFINED__
#define ____x_ABI_CWindows_CMedia_CClosedCaptioning_CIClosedCaptionPropertiesStatics_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CMedia_CClosedCaptioning_CIClosedCaptionPropertiesStatics __x_ABI_CWindows_CMedia_CClosedCaptioning_CIClosedCaptionPropertiesStatics;

#endif // ____x_ABI_CWindows_CMedia_CClosedCaptioning_CIClosedCaptionPropertiesStatics_FWD_DEFINED__

// Parameterized interface forward declarations (C)

// Collection interface definitions

typedef struct __x_ABI_CWindows_CUI_CColor __x_ABI_CWindows_CUI_CColor;

typedef enum __x_ABI_CWindows_CMedia_CClosedCaptioning_CClosedCaptionColor __x_ABI_CWindows_CMedia_CClosedCaptioning_CClosedCaptionColor;

typedef enum __x_ABI_CWindows_CMedia_CClosedCaptioning_CClosedCaptionEdgeEffect __x_ABI_CWindows_CMedia_CClosedCaptioning_CClosedCaptionEdgeEffect;

typedef enum __x_ABI_CWindows_CMedia_CClosedCaptioning_CClosedCaptionOpacity __x_ABI_CWindows_CMedia_CClosedCaptioning_CClosedCaptionOpacity;

typedef enum __x_ABI_CWindows_CMedia_CClosedCaptioning_CClosedCaptionSize __x_ABI_CWindows_CMedia_CClosedCaptioning_CClosedCaptionSize;

typedef enum __x_ABI_CWindows_CMedia_CClosedCaptioning_CClosedCaptionStyle __x_ABI_CWindows_CMedia_CClosedCaptioning_CClosedCaptionStyle;

/*
 *
 * Struct Windows.Media.ClosedCaptioning.ClosedCaptionColor
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
enum __x_ABI_CWindows_CMedia_CClosedCaptioning_CClosedCaptionColor
{
    ClosedCaptionColor_Default = 0,
    ClosedCaptionColor_White = 1,
    ClosedCaptionColor_Black = 2,
    ClosedCaptionColor_Red = 3,
    ClosedCaptionColor_Green = 4,
    ClosedCaptionColor_Blue = 5,
    ClosedCaptionColor_Yellow = 6,
    ClosedCaptionColor_Magenta = 7,
    ClosedCaptionColor_Cyan = 8,
};
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Struct Windows.Media.ClosedCaptioning.ClosedCaptionEdgeEffect
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
enum __x_ABI_CWindows_CMedia_CClosedCaptioning_CClosedCaptionEdgeEffect
{
    ClosedCaptionEdgeEffect_Default = 0,
    ClosedCaptionEdgeEffect_None = 1,
    ClosedCaptionEdgeEffect_Raised = 2,
    ClosedCaptionEdgeEffect_Depressed = 3,
    ClosedCaptionEdgeEffect_Uniform = 4,
    ClosedCaptionEdgeEffect_DropShadow = 5,
};
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Struct Windows.Media.ClosedCaptioning.ClosedCaptionOpacity
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
enum __x_ABI_CWindows_CMedia_CClosedCaptioning_CClosedCaptionOpacity
{
    ClosedCaptionOpacity_Default = 0,
    ClosedCaptionOpacity_OneHundredPercent = 1,
    ClosedCaptionOpacity_SeventyFivePercent = 2,
    ClosedCaptionOpacity_TwentyFivePercent = 3,
    ClosedCaptionOpacity_ZeroPercent = 4,
};
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Struct Windows.Media.ClosedCaptioning.ClosedCaptionSize
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
enum __x_ABI_CWindows_CMedia_CClosedCaptioning_CClosedCaptionSize
{
    ClosedCaptionSize_Default = 0,
    ClosedCaptionSize_FiftyPercent = 1,
    ClosedCaptionSize_OneHundredPercent = 2,
    ClosedCaptionSize_OneHundredFiftyPercent = 3,
    ClosedCaptionSize_TwoHundredPercent = 4,
};
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Struct Windows.Media.ClosedCaptioning.ClosedCaptionStyle
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
enum __x_ABI_CWindows_CMedia_CClosedCaptioning_CClosedCaptionStyle
{
    ClosedCaptionStyle_Default = 0,
    ClosedCaptionStyle_MonospacedWithSerifs = 1,
    ClosedCaptionStyle_ProportionalWithSerifs = 2,
    ClosedCaptionStyle_MonospacedWithoutSerifs = 3,
    ClosedCaptionStyle_ProportionalWithoutSerifs = 4,
    ClosedCaptionStyle_Casual = 5,
    ClosedCaptionStyle_Cursive = 6,
    ClosedCaptionStyle_SmallCapitals = 7,
};
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Media.ClosedCaptioning.IClosedCaptionPropertiesStatics
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Media.ClosedCaptioning.ClosedCaptionProperties
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CMedia_CClosedCaptioning_CIClosedCaptionPropertiesStatics_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CMedia_CClosedCaptioning_CIClosedCaptionPropertiesStatics_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Media_ClosedCaptioning_IClosedCaptionPropertiesStatics[] = L"Windows.Media.ClosedCaptioning.IClosedCaptionPropertiesStatics";
typedef struct __x_ABI_CWindows_CMedia_CClosedCaptioning_CIClosedCaptionPropertiesStaticsVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CMedia_CClosedCaptioning_CIClosedCaptionPropertiesStatics* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CMedia_CClosedCaptioning_CIClosedCaptionPropertiesStatics* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CMedia_CClosedCaptioning_CIClosedCaptionPropertiesStatics* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CMedia_CClosedCaptioning_CIClosedCaptionPropertiesStatics* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CMedia_CClosedCaptioning_CIClosedCaptionPropertiesStatics* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CMedia_CClosedCaptioning_CIClosedCaptionPropertiesStatics* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* get_FontColor)(__x_ABI_CWindows_CMedia_CClosedCaptioning_CIClosedCaptionPropertiesStatics* This,
        enum __x_ABI_CWindows_CMedia_CClosedCaptioning_CClosedCaptionColor* value);
    HRESULT (STDMETHODCALLTYPE* get_ComputedFontColor)(__x_ABI_CWindows_CMedia_CClosedCaptioning_CIClosedCaptionPropertiesStatics* This,
        struct __x_ABI_CWindows_CUI_CColor* value);
    HRESULT (STDMETHODCALLTYPE* get_FontOpacity)(__x_ABI_CWindows_CMedia_CClosedCaptioning_CIClosedCaptionPropertiesStatics* This,
        enum __x_ABI_CWindows_CMedia_CClosedCaptioning_CClosedCaptionOpacity* value);
    HRESULT (STDMETHODCALLTYPE* get_FontSize)(__x_ABI_CWindows_CMedia_CClosedCaptioning_CIClosedCaptionPropertiesStatics* This,
        enum __x_ABI_CWindows_CMedia_CClosedCaptioning_CClosedCaptionSize* value);
    HRESULT (STDMETHODCALLTYPE* get_FontStyle)(__x_ABI_CWindows_CMedia_CClosedCaptioning_CIClosedCaptionPropertiesStatics* This,
        enum __x_ABI_CWindows_CMedia_CClosedCaptioning_CClosedCaptionStyle* value);
    HRESULT (STDMETHODCALLTYPE* get_FontEffect)(__x_ABI_CWindows_CMedia_CClosedCaptioning_CIClosedCaptionPropertiesStatics* This,
        enum __x_ABI_CWindows_CMedia_CClosedCaptioning_CClosedCaptionEdgeEffect* value);
    HRESULT (STDMETHODCALLTYPE* get_BackgroundColor)(__x_ABI_CWindows_CMedia_CClosedCaptioning_CIClosedCaptionPropertiesStatics* This,
        enum __x_ABI_CWindows_CMedia_CClosedCaptioning_CClosedCaptionColor* value);
    HRESULT (STDMETHODCALLTYPE* get_ComputedBackgroundColor)(__x_ABI_CWindows_CMedia_CClosedCaptioning_CIClosedCaptionPropertiesStatics* This,
        struct __x_ABI_CWindows_CUI_CColor* value);
    HRESULT (STDMETHODCALLTYPE* get_BackgroundOpacity)(__x_ABI_CWindows_CMedia_CClosedCaptioning_CIClosedCaptionPropertiesStatics* This,
        enum __x_ABI_CWindows_CMedia_CClosedCaptioning_CClosedCaptionOpacity* value);
    HRESULT (STDMETHODCALLTYPE* get_RegionColor)(__x_ABI_CWindows_CMedia_CClosedCaptioning_CIClosedCaptionPropertiesStatics* This,
        enum __x_ABI_CWindows_CMedia_CClosedCaptioning_CClosedCaptionColor* value);
    HRESULT (STDMETHODCALLTYPE* get_ComputedRegionColor)(__x_ABI_CWindows_CMedia_CClosedCaptioning_CIClosedCaptionPropertiesStatics* This,
        struct __x_ABI_CWindows_CUI_CColor* value);
    HRESULT (STDMETHODCALLTYPE* get_RegionOpacity)(__x_ABI_CWindows_CMedia_CClosedCaptioning_CIClosedCaptionPropertiesStatics* This,
        enum __x_ABI_CWindows_CMedia_CClosedCaptioning_CClosedCaptionOpacity* value);

    END_INTERFACE
} __x_ABI_CWindows_CMedia_CClosedCaptioning_CIClosedCaptionPropertiesStaticsVtbl;

interface __x_ABI_CWindows_CMedia_CClosedCaptioning_CIClosedCaptionPropertiesStatics
{
    CONST_VTBL struct __x_ABI_CWindows_CMedia_CClosedCaptioning_CIClosedCaptionPropertiesStaticsVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CMedia_CClosedCaptioning_CIClosedCaptionPropertiesStatics_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CMedia_CClosedCaptioning_CIClosedCaptionPropertiesStatics_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CMedia_CClosedCaptioning_CIClosedCaptionPropertiesStatics_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CMedia_CClosedCaptioning_CIClosedCaptionPropertiesStatics_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CMedia_CClosedCaptioning_CIClosedCaptionPropertiesStatics_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CMedia_CClosedCaptioning_CIClosedCaptionPropertiesStatics_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CMedia_CClosedCaptioning_CIClosedCaptionPropertiesStatics_get_FontColor(This, value) \
    ((This)->lpVtbl->get_FontColor(This, value))

#define __x_ABI_CWindows_CMedia_CClosedCaptioning_CIClosedCaptionPropertiesStatics_get_ComputedFontColor(This, value) \
    ((This)->lpVtbl->get_ComputedFontColor(This, value))

#define __x_ABI_CWindows_CMedia_CClosedCaptioning_CIClosedCaptionPropertiesStatics_get_FontOpacity(This, value) \
    ((This)->lpVtbl->get_FontOpacity(This, value))

#define __x_ABI_CWindows_CMedia_CClosedCaptioning_CIClosedCaptionPropertiesStatics_get_FontSize(This, value) \
    ((This)->lpVtbl->get_FontSize(This, value))

#define __x_ABI_CWindows_CMedia_CClosedCaptioning_CIClosedCaptionPropertiesStatics_get_FontStyle(This, value) \
    ((This)->lpVtbl->get_FontStyle(This, value))

#define __x_ABI_CWindows_CMedia_CClosedCaptioning_CIClosedCaptionPropertiesStatics_get_FontEffect(This, value) \
    ((This)->lpVtbl->get_FontEffect(This, value))

#define __x_ABI_CWindows_CMedia_CClosedCaptioning_CIClosedCaptionPropertiesStatics_get_BackgroundColor(This, value) \
    ((This)->lpVtbl->get_BackgroundColor(This, value))

#define __x_ABI_CWindows_CMedia_CClosedCaptioning_CIClosedCaptionPropertiesStatics_get_ComputedBackgroundColor(This, value) \
    ((This)->lpVtbl->get_ComputedBackgroundColor(This, value))

#define __x_ABI_CWindows_CMedia_CClosedCaptioning_CIClosedCaptionPropertiesStatics_get_BackgroundOpacity(This, value) \
    ((This)->lpVtbl->get_BackgroundOpacity(This, value))

#define __x_ABI_CWindows_CMedia_CClosedCaptioning_CIClosedCaptionPropertiesStatics_get_RegionColor(This, value) \
    ((This)->lpVtbl->get_RegionColor(This, value))

#define __x_ABI_CWindows_CMedia_CClosedCaptioning_CIClosedCaptionPropertiesStatics_get_ComputedRegionColor(This, value) \
    ((This)->lpVtbl->get_ComputedRegionColor(This, value))

#define __x_ABI_CWindows_CMedia_CClosedCaptioning_CIClosedCaptionPropertiesStatics_get_RegionOpacity(This, value) \
    ((This)->lpVtbl->get_RegionOpacity(This, value))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CMedia_CClosedCaptioning_CIClosedCaptionPropertiesStatics;
#endif /* !defined(____x_ABI_CWindows_CMedia_CClosedCaptioning_CIClosedCaptionPropertiesStatics_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Media.ClosedCaptioning.ClosedCaptionProperties
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 * RuntimeClass contains static methods.
 *   Static Methods exist on the Windows.Media.ClosedCaptioning.IClosedCaptionPropertiesStatics interface starting with version 1.0 of the Windows.Foundation.UniversalApiContract API contract
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Media_ClosedCaptioning_ClosedCaptionProperties_DEFINED
#define RUNTIMECLASS_Windows_Media_ClosedCaptioning_ClosedCaptionProperties_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Media_ClosedCaptioning_ClosedCaptionProperties[] = L"Windows.Media.ClosedCaptioning.ClosedCaptionProperties";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#endif // defined(__cplusplus)
#pragma pop_macro("MIDL_CONST_ID")
// Restore the original value of the 'DEPRECATED' macro
#pragma pop_macro("DEPRECATED")

#ifdef __clang__
#pragma clang diagnostic pop // deprecated-declarations
#else
#pragma warning(pop)
#endif
#endif // __windows2Emedia2Eclosedcaptioning_p_h__

#endif // __windows2Emedia2Eclosedcaptioning_h__
