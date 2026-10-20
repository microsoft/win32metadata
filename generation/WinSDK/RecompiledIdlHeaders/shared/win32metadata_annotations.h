#ifndef WIN32METADATA_ANNOTATIONS_H
#define WIN32METADATA_ANNOTATIONS_H

#if defined(WIN32METADATA) && defined(__clang__)
#ifndef _WIN32META_ANNOTATION_
#define _WIN32META_ANNOTATION_(...) \
    __attribute__((annotate("Win32Metadata." __VA_ARGS__)))
#endif
#define _WIN32META_STRINGIFY_(...) #__VA_ARGS__
#define _WIN32META_EXPAND_STRINGIFY_(...) _WIN32META_STRINGIFY_(__VA_ARGS__)
#define _Win32_RAIIFree_(cleanup, ...) \
    _WIN32META_ANNOTATION_("RAIIFree", "Win32Metadata.FunctionDecl:" _WIN32META_EXPAND_STRINGIFY_(cleanup), ##__VA_ARGS__)
#define _Win32_ImportLibrary_(...) _WIN32META_ANNOTATION_("ImportLibrary", __VA_ARGS__)
#define _Win32_AssociatedEnum_(name) _WIN32META_ANNOTATION_("AssociatedEnum", (name)0)
#define _Win32_Enum_(name, storage, ...) \
    typedef _WIN32META_ANNOTATION_("Enum(" #__VA_ARGS__ ")", __VA_ARGS__) storage name
#define _Win32_FlagsEnum_(name, storage, ...) \
    typedef _WIN32META_ANNOTATION_("FlagsEnum(" #__VA_ARGS__ ")", __VA_ARGS__) storage name
#if defined(__cplusplus) && !defined(CINTERFACE)
#define _WIN32META_JOIN_RAW_(left, right) left##right
#define _WIN32META_JOIN_(left, right) _WIN32META_JOIN_RAW_(left, right)
#define _WIN32META_ANNOTATE_METHOD_(method, annotation) \
    _WIN32META_ANNOTATION_("Method", sizeof(&method)) annotation \
    static const unsigned char _WIN32META_JOIN_(_WIN32META_METHOD_, __COUNTER__) = 0
#define _WIN32META_ANNOTATE_PARAMETER_(method, parameter, annotation) \
    _WIN32META_ANNOTATION_("Parameter", sizeof(&method), #parameter) annotation \
    static const unsigned char _WIN32META_JOIN_(_WIN32META_PARAMETER_, __COUNTER__) = 0
#else
#define _WIN32META_ANNOTATE_METHOD_(method, annotation)
#define _WIN32META_ANNOTATE_PARAMETER_(method, parameter, annotation)
#endif
#else
#define _WIN32META_ANNOTATION_(...)
#define _Win32_RAIIFree_(...)
#define _Win32_ImportLibrary_(...)
#define _Win32_AssociatedEnum_(name)
#define _Win32_Enum_(name, storage, ...)
#define _Win32_FlagsEnum_(name, storage, ...)
#define _WIN32META_ANNOTATE_METHOD_(method, annotation)
#define _WIN32META_ANNOTATE_PARAMETER_(method, parameter, annotation)
#endif

#define _Win32_RAIIFree_Handle_(cleanup) _Win32_RAIIFree_(cleanup, -1, 0)
#define _Win32_SetLastError_ _WIN32META_ANNOTATION_("SetLastError")
#define _Win32_PreserveResult_ _WIN32META_ANNOTATION_("PreserveResult")
#define _Win32_Retained_ _WIN32META_ANNOTATION_("Retained")
#define _Win32_ContainsInteriorPointers_ _WIN32META_ANNOTATION_("ContainsInteriorPointers")
#define _Win32_Retval_ _WIN32META_ANNOTATION_("RetVal")
#define _Win32_Reserved_ _WIN32META_ANNOTATION_("Reserved")
#define _Win32_Optional_(value) _WIN32META_ANNOTATION_("Optional(" #value ")")
#define _Win32_ComOutPtr_(value) _WIN32META_ANNOTATION_("ComOutPtr(" #value ")")
#define _Win32_AlsoUsableFor_(name) _WIN32META_ANNOTATION_("AlsoUsableFor(" #name ")")
#define _Win32_AssociatedConstant_(name) _WIN32META_ANNOTATION_("AssociatedConstant(" #name ")")

#if defined(MIDL_PASS)
#define _Win32_AnnotateInterface_(name, annotation) \
    cpp_quote("#if defined(WIN32METADATA) && defined(__clang__) && defined(__cplusplus)") \
    cpp_quote("typedef " #annotation " struct " #name " " #name ";") \
    cpp_quote("#endif")
#define _Win32_AnnotateMethod_(method, annotation) \
    cpp_quote("_WIN32META_ANNOTATE_METHOD_(" #method ", " #annotation ");")
#define _Win32_AnnotateParameter_(method, parameter, annotation) \
    cpp_quote("_WIN32META_ANNOTATE_PARAMETER_(" #method ", " #parameter ", " #annotation ");")
#endif

#define _WIN32META_OS_VERSION_Windows2000 "SupportedOSPlatform(\"windows5.0\")"
#define _WIN32META_OS_VERSION_WindowsXP "SupportedOSPlatform(\"windows5.1.2600\")"
#define _WIN32META_OS_VERSION_WindowsVista "SupportedOSPlatform(\"windows6.0.6000\")"
#define _WIN32META_OS_VERSION_Windows7 "SupportedOSPlatform(\"windows6.1\")"
#define _WIN32META_OS_VERSION_Windows8 "SupportedOSPlatform(\"windows8.0\")"
#define _WIN32META_OS_VERSION_Windows81 "SupportedOSPlatform(\"windows8.1\")"
#define _WIN32META_OS_VERSION_10240 "SupportedOSPlatform(\"windows10.0.10240\")"
#define _WIN32META_OS_VERSION_10586 "SupportedOSPlatform(\"windows10.0.10586\")"
#define _WIN32META_OS_VERSION_14393 "SupportedOSPlatform(\"windows10.0.14393\")"
#define _WIN32META_OS_VERSION_15063 "SupportedOSPlatform(\"windows10.0.15063\")"
#define _WIN32META_OS_VERSION_16299 "SupportedOSPlatform(\"windows10.0.16299\")"
#define _WIN32META_OS_VERSION_17134 "SupportedOSPlatform(\"windows10.0.17134\")"
#define _WIN32META_OS_VERSION_17763 "SupportedOSPlatform(\"windows10.0.17763\")"
#define _WIN32META_OS_VERSION_18362 "SupportedOSPlatform(\"windows10.0.18362\")"
#define _WIN32META_OS_VERSION_19041 "SupportedOSPlatform(\"windows10.0.19041\")"
#define _WIN32META_OS_VERSION_Server2000 "SupportedOSPlatform(\"windowsserver2000\")"
#define _WIN32META_OS_VERSION_Server2003 "SupportedOSPlatform(\"windowsserver2003\")"
#define _WIN32META_OS_VERSION_Server2008 "SupportedOSPlatform(\"windowsserver2008\")"
#define _WIN32META_OS_VERSION_Server2012 "SupportedOSPlatform(\"windowsserver2012\")"
#define _WIN32META_OS_VERSION_Server2016 "SupportedOSPlatform(\"windowsserver2016\")"
#define _WIN32META_OS_VERSION_RAW(os) _WIN32META_OS_VERSION_##os
#define _WIN32META_OS_VERSION(os) _WIN32META_OS_VERSION_RAW(os)

#define _Win32_SupportedOS_Windows2000_ _WIN32META_ANNOTATION_(_WIN32META_OS_VERSION(Windows2000))
#define _Win32_SupportedOS_WindowsXP_ _WIN32META_ANNOTATION_(_WIN32META_OS_VERSION(WindowsXP))
#define _Win32_SupportedOS_WindowsVista_ _WIN32META_ANNOTATION_(_WIN32META_OS_VERSION(WindowsVista))
#define _Win32_SupportedOS_Windows7_ _WIN32META_ANNOTATION_(_WIN32META_OS_VERSION(Windows7))
#define _Win32_SupportedOS_Windows8_ _WIN32META_ANNOTATION_(_WIN32META_OS_VERSION(Windows8))
#define _Win32_SupportedOS_Windows81_ _WIN32META_ANNOTATION_(_WIN32META_OS_VERSION(Windows81))
#define _Win32_SupportedOS_10240_ _WIN32META_ANNOTATION_(_WIN32META_OS_VERSION(10240))
#define _Win32_SupportedOS_10586_ _WIN32META_ANNOTATION_(_WIN32META_OS_VERSION(10586))
#define _Win32_SupportedOS_14393_ _WIN32META_ANNOTATION_(_WIN32META_OS_VERSION(14393))
#define _Win32_SupportedOS_15063_ _WIN32META_ANNOTATION_(_WIN32META_OS_VERSION(15063))
#define _Win32_SupportedOS_16299_ _WIN32META_ANNOTATION_(_WIN32META_OS_VERSION(16299))
#define _Win32_SupportedOS_17134_ _WIN32META_ANNOTATION_(_WIN32META_OS_VERSION(17134))
#define _Win32_SupportedOS_17763_ _WIN32META_ANNOTATION_(_WIN32META_OS_VERSION(17763))
#define _Win32_SupportedOS_18362_ _WIN32META_ANNOTATION_(_WIN32META_OS_VERSION(18362))
#define _Win32_SupportedOS_19041_ _WIN32META_ANNOTATION_(_WIN32META_OS_VERSION(19041))
#define _Win32_SupportedOS_Server2000_ _WIN32META_ANNOTATION_(_WIN32META_OS_VERSION(Server2000))
#define _Win32_SupportedOS_Server2003_ _WIN32META_ANNOTATION_(_WIN32META_OS_VERSION(Server2003))
#define _Win32_SupportedOS_Server2008_ _WIN32META_ANNOTATION_(_WIN32META_OS_VERSION(Server2008))
#define _Win32_SupportedOS_Server2012_ _WIN32META_ANNOTATION_(_WIN32META_OS_VERSION(Server2012))
#define _Win32_SupportedOS_Server2016_ _WIN32META_ANNOTATION_(_WIN32META_OS_VERSION(Server2016))

// Clang owns lexical scope, including includes. Attributes accumulate, not override.
#if defined(WIN32METADATA) && defined(__clang__)
#define _WIN32META_OS_PRAGMA(...) _Pragma(_WIN32META_EXPAND_STRINGIFY_(__VA_ARGS__))
#define _Win32_SupportedOS_BEGIN_(os) \
    _WIN32META_OS_PRAGMA(clang attribute win32_os.push( \
        __attribute__((annotate("Win32Metadata." _WIN32META_OS_VERSION(os)))), \
        apply_to = any(function, record, enum, type_alias)))
#define _Win32_SupportedOS_END_() _WIN32META_OS_PRAGMA(clang attribute win32_os.pop)
#else
#define _Win32_SupportedOS_BEGIN_(os)
#define _Win32_SupportedOS_END_()
#endif

#endif
