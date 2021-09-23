
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
#ifndef __windows2Edata2Exml2Exsl_h__
#define __windows2Edata2Exml2Exsl_h__
#ifndef __windows2Edata2Exml2Exsl_p_h__
#define __windows2Edata2Exml2Exsl_p_h__


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
#include "Windows.Data.Xml.Dom.h"

#if defined(__cplusplus) && !defined(CINTERFACE)
/* Forward Declarations */
#ifndef ____x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessor_FWD_DEFINED__
#define ____x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessor_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Data {
            namespace Xml {
                namespace Xsl {
                    interface IXsltProcessor;
                } /* Xsl */
            } /* Xml */
        } /* Data */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessor ABI::Windows::Data::Xml::Xsl::IXsltProcessor

#endif // ____x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessor_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessor2_FWD_DEFINED__
#define ____x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessor2_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Data {
            namespace Xml {
                namespace Xsl {
                    interface IXsltProcessor2;
                } /* Xsl */
            } /* Xml */
        } /* Data */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessor2 ABI::Windows::Data::Xml::Xsl::IXsltProcessor2

#endif // ____x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessor2_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessorFactory_FWD_DEFINED__
#define ____x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessorFactory_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Data {
            namespace Xml {
                namespace Xsl {
                    interface IXsltProcessorFactory;
                } /* Xsl */
            } /* Xml */
        } /* Data */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessorFactory ABI::Windows::Data::Xml::Xsl::IXsltProcessorFactory

#endif // ____x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessorFactory_FWD_DEFINED__

// Parameterized interface forward declarations (C++)

// Collection interface definitions
#ifndef ____x_ABI_CWindows_CData_CXml_CDom_CIXmlNode_FWD_DEFINED__
#define ____x_ABI_CWindows_CData_CXml_CDom_CIXmlNode_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Data {
            namespace Xml {
                namespace Dom {
                    interface IXmlNode;
                } /* Dom */
            } /* Xml */
        } /* Data */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CData_CXml_CDom_CIXmlNode ABI::Windows::Data::Xml::Dom::IXmlNode

#endif // ____x_ABI_CWindows_CData_CXml_CDom_CIXmlNode_FWD_DEFINED__

namespace ABI {
    namespace Windows {
        namespace Data {
            namespace Xml {
                namespace Dom {
                    class XmlDocument;
                } /* Dom */
            } /* Xml */
        } /* Data */
    } /* Windows */
} /* ABI */

#ifndef ____x_ABI_CWindows_CData_CXml_CDom_CIXmlDocument_FWD_DEFINED__
#define ____x_ABI_CWindows_CData_CXml_CDom_CIXmlDocument_FWD_DEFINED__
namespace ABI {
    namespace Windows {
        namespace Data {
            namespace Xml {
                namespace Dom {
                    interface IXmlDocument;
                } /* Dom */
            } /* Xml */
        } /* Data */
    } /* Windows */
} /* ABI */
#define __x_ABI_CWindows_CData_CXml_CDom_CIXmlDocument ABI::Windows::Data::Xml::Dom::IXmlDocument

#endif // ____x_ABI_CWindows_CData_CXml_CDom_CIXmlDocument_FWD_DEFINED__

namespace ABI {
    namespace Windows {
        namespace Data {
            namespace Xml {
                namespace Xsl {
                    class XsltProcessor;
                } /* Xsl */
            } /* Xml */
        } /* Data */
    } /* Windows */
} /* ABI */

/*
 *
 * Interface Windows.Data.Xml.Xsl.IXsltProcessor
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Data.Xml.Xsl.XsltProcessor
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessor_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessor_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Data_Xml_Xsl_IXsltProcessor[] = L"Windows.Data.Xml.Xsl.IXsltProcessor";
namespace ABI {
    namespace Windows {
        namespace Data {
            namespace Xml {
                namespace Xsl {
                    MIDL_INTERFACE("7b64703f-550c-48c6-a90f-93a5b964518f")
                    IXsltProcessor : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE TransformToString(
                            ABI::Windows::Data::Xml::Dom::IXmlNode* inputNode,
                            HSTRING* output
                            ) = 0;
                    };

                    extern MIDL_CONST_ID IID& IID_IXsltProcessor = _uuidof(IXsltProcessor);
                } /* Xsl */
            } /* Xml */
        } /* Data */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessor;
#endif /* !defined(____x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessor_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Data.Xml.Xsl.IXsltProcessor2
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Data.Xml.Xsl.XsltProcessor
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessor2_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessor2_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Data_Xml_Xsl_IXsltProcessor2[] = L"Windows.Data.Xml.Xsl.IXsltProcessor2";
namespace ABI {
    namespace Windows {
        namespace Data {
            namespace Xml {
                namespace Xsl {
                    MIDL_INTERFACE("8da45c56-97a5-44cb-a8be-27d86280c70a")
                    IXsltProcessor2 : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE TransformToDocument(
                            ABI::Windows::Data::Xml::Dom::IXmlNode* inputNode,
                            ABI::Windows::Data::Xml::Dom::IXmlDocument** output
                            ) = 0;
                    };

                    extern MIDL_CONST_ID IID& IID_IXsltProcessor2 = _uuidof(IXsltProcessor2);
                } /* Xsl */
            } /* Xml */
        } /* Data */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessor2;
#endif /* !defined(____x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessor2_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Data.Xml.Xsl.IXsltProcessorFactory
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Data.Xml.Xsl.XsltProcessor
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessorFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessorFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Data_Xml_Xsl_IXsltProcessorFactory[] = L"Windows.Data.Xml.Xsl.IXsltProcessorFactory";
namespace ABI {
    namespace Windows {
        namespace Data {
            namespace Xml {
                namespace Xsl {
                    MIDL_INTERFACE("274146c0-9a51-4663-bf30-0ef742146f20")
                    IXsltProcessorFactory : public IInspectable
                    {
                    public:
                        virtual HRESULT STDMETHODCALLTYPE CreateInstance(
                            ABI::Windows::Data::Xml::Dom::IXmlDocument* document,
                            ABI::Windows::Data::Xml::Xsl::IXsltProcessor** xsltProcessor
                            ) = 0;
                    };

                    extern MIDL_CONST_ID IID& IID_IXsltProcessorFactory = _uuidof(IXsltProcessorFactory);
                } /* Xsl */
            } /* Xml */
        } /* Data */
    } /* Windows */
} /* ABI */

EXTERN_C const IID IID___x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessorFactory;
#endif /* !defined(____x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessorFactory_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Data.Xml.Xsl.XsltProcessor
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via the Windows.Data.Xml.Xsl.IXsltProcessorFactory interface starting with version 1.0 of the Windows.Foundation.UniversalApiContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Data.Xml.Xsl.IXsltProcessor ** Default Interface **
 *    Windows.Data.Xml.Xsl.IXsltProcessor2
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Data_Xml_Xsl_XsltProcessor_DEFINED
#define RUNTIMECLASS_Windows_Data_Xml_Xsl_XsltProcessor_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Data_Xml_Xsl_XsltProcessor[] = L"Windows.Data.Xml.Xsl.XsltProcessor";
#endif
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

#else // !defined(__cplusplus)
/* Forward Declarations */
#ifndef ____x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessor_FWD_DEFINED__
#define ____x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessor_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessor __x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessor;

#endif // ____x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessor_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessor2_FWD_DEFINED__
#define ____x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessor2_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessor2 __x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessor2;

#endif // ____x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessor2_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessorFactory_FWD_DEFINED__
#define ____x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessorFactory_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessorFactory __x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessorFactory;

#endif // ____x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessorFactory_FWD_DEFINED__

// Parameterized interface forward declarations (C)

// Collection interface definitions

#ifndef ____x_ABI_CWindows_CData_CXml_CDom_CIXmlNode_FWD_DEFINED__
#define ____x_ABI_CWindows_CData_CXml_CDom_CIXmlNode_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CData_CXml_CDom_CIXmlNode __x_ABI_CWindows_CData_CXml_CDom_CIXmlNode;

#endif // ____x_ABI_CWindows_CData_CXml_CDom_CIXmlNode_FWD_DEFINED__

#ifndef ____x_ABI_CWindows_CData_CXml_CDom_CIXmlDocument_FWD_DEFINED__
#define ____x_ABI_CWindows_CData_CXml_CDom_CIXmlDocument_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CData_CXml_CDom_CIXmlDocument __x_ABI_CWindows_CData_CXml_CDom_CIXmlDocument;

#endif // ____x_ABI_CWindows_CData_CXml_CDom_CIXmlDocument_FWD_DEFINED__

/*
 *
 * Interface Windows.Data.Xml.Xsl.IXsltProcessor
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Data.Xml.Xsl.XsltProcessor
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessor_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessor_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Data_Xml_Xsl_IXsltProcessor[] = L"Windows.Data.Xml.Xsl.IXsltProcessor";
typedef struct __x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessorVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessor* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessor* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessor* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessor* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessor* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessor* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* TransformToString)(__x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessor* This,
        __x_ABI_CWindows_CData_CXml_CDom_CIXmlNode* inputNode,
        HSTRING* output);

    END_INTERFACE
} __x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessorVtbl;

interface __x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessor
{
    CONST_VTBL struct __x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessorVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessor_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessor_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessor_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessor_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessor_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessor_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessor_TransformToString(This, inputNode, output) \
    ((This)->lpVtbl->TransformToString(This, inputNode, output))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessor;
#endif /* !defined(____x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessor_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Data.Xml.Xsl.IXsltProcessor2
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Data.Xml.Xsl.XsltProcessor
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessor2_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessor2_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Data_Xml_Xsl_IXsltProcessor2[] = L"Windows.Data.Xml.Xsl.IXsltProcessor2";
typedef struct __x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessor2Vtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessor2* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessor2* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessor2* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessor2* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessor2* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessor2* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* TransformToDocument)(__x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessor2* This,
        __x_ABI_CWindows_CData_CXml_CDom_CIXmlNode* inputNode,
        __x_ABI_CWindows_CData_CXml_CDom_CIXmlDocument** output);

    END_INTERFACE
} __x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessor2Vtbl;

interface __x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessor2
{
    CONST_VTBL struct __x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessor2Vtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessor2_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessor2_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessor2_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessor2_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessor2_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessor2_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessor2_TransformToDocument(This, inputNode, output) \
    ((This)->lpVtbl->TransformToDocument(This, inputNode, output))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessor2;
#endif /* !defined(____x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessor2_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Interface Windows.Data.Xml.Xsl.IXsltProcessorFactory
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 * Interface is a part of the implementation of type Windows.Data.Xml.Xsl.XsltProcessor
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#if !defined(____x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessorFactory_INTERFACE_DEFINED__)
#define ____x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessorFactory_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Windows_Data_Xml_Xsl_IXsltProcessorFactory[] = L"Windows.Data.Xml.Xsl.IXsltProcessorFactory";
typedef struct __x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessorFactoryVtbl
{
    BEGIN_INTERFACE

    HRESULT (STDMETHODCALLTYPE* QueryInterface)(__x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessorFactory* This,
        REFIID riid,
        void** ppvObject);
    ULONG (STDMETHODCALLTYPE* AddRef)(__x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessorFactory* This);
    ULONG (STDMETHODCALLTYPE* Release)(__x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessorFactory* This);
    HRESULT (STDMETHODCALLTYPE* GetIids)(__x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessorFactory* This,
        ULONG* iidCount,
        IID** iids);
    HRESULT (STDMETHODCALLTYPE* GetRuntimeClassName)(__x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessorFactory* This,
        HSTRING* className);
    HRESULT (STDMETHODCALLTYPE* GetTrustLevel)(__x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessorFactory* This,
        TrustLevel* trustLevel);
    HRESULT (STDMETHODCALLTYPE* CreateInstance)(__x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessorFactory* This,
        __x_ABI_CWindows_CData_CXml_CDom_CIXmlDocument* document,
        __x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessor** xsltProcessor);

    END_INTERFACE
} __x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessorFactoryVtbl;

interface __x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessorFactory
{
    CONST_VTBL struct __x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessorFactoryVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define __x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessorFactory_QueryInterface(This, riid, ppvObject) \
    ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define __x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessorFactory_AddRef(This) \
    ((This)->lpVtbl->AddRef(This))

#define __x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessorFactory_Release(This) \
    ((This)->lpVtbl->Release(This))

#define __x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessorFactory_GetIids(This, iidCount, iids) \
    ((This)->lpVtbl->GetIids(This, iidCount, iids))

#define __x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessorFactory_GetRuntimeClassName(This, className) \
    ((This)->lpVtbl->GetRuntimeClassName(This, className))

#define __x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessorFactory_GetTrustLevel(This, trustLevel) \
    ((This)->lpVtbl->GetTrustLevel(This, trustLevel))

#define __x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessorFactory_CreateInstance(This, document, xsltProcessor) \
    ((This)->lpVtbl->CreateInstance(This, document, xsltProcessor))

#endif /* COBJMACROS */

EXTERN_C const IID IID___x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessorFactory;
#endif /* !defined(____x_ABI_CWindows_CData_CXml_CXsl_CIXsltProcessorFactory_INTERFACE_DEFINED__) */
#endif // WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000

/*
 *
 * Class Windows.Data.Xml.Xsl.XsltProcessor
 *
 * Introduced to Windows.Foundation.UniversalApiContract in version 1.0
 *
 * RuntimeClass can be activated.
 *   Type can be activated via the Windows.Data.Xml.Xsl.IXsltProcessorFactory interface starting with version 1.0 of the Windows.Foundation.UniversalApiContract API contract
 *
 * Class implements the following interfaces:
 *    Windows.Data.Xml.Xsl.IXsltProcessor ** Default Interface **
 *    Windows.Data.Xml.Xsl.IXsltProcessor2
 *
 * Class Threading Model:  Both Single and Multi Threaded Apartment
 *
 * Class Marshaling Behavior:  Agile - Class is agile
 *
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#ifndef RUNTIMECLASS_Windows_Data_Xml_Xsl_XsltProcessor_DEFINED
#define RUNTIMECLASS_Windows_Data_Xml_Xsl_XsltProcessor_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_Windows_Data_Xml_Xsl_XsltProcessor[] = L"Windows.Data.Xml.Xsl.XsltProcessor";
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
#endif // __windows2Edata2Exml2Exsl_p_h__

#endif // __windows2Edata2Exml2Exsl_h__
