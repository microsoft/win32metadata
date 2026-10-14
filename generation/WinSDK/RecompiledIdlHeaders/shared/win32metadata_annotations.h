#pragma once

#if defined(WIN32METADATA) && defined(__clang__)
#define _WIN32META_ANNOTATION_(text) __attribute__((annotate(text)))
#define _WIN32META_STRINGIFY_(...) #__VA_ARGS__
#define _WIN32META_EXPAND_STRINGIFY_(...) _WIN32META_STRINGIFY_(__VA_ARGS__)
#if defined(WIN32METADATA_CSHARP)
// Private C# transport preserves the declaration-time expansion of invalid values.
#define _Win32_RAIIFree_(...) \
    _WIN32META_ANNOTATION_("RAIIFree(" #__VA_ARGS__ ")") \
    _WIN32META_ANNOTATION_("__win32metadata_RAIIFree_expanded(" _WIN32META_EXPAND_STRINGIFY_(__VA_ARGS__) ")")
#else
#define _Win32_RAIIFree_(...) _WIN32META_ANNOTATION_("RAIIFree(" #__VA_ARGS__ ")")
#endif
#else
#define _WIN32META_ANNOTATION_(text)
#define _Win32_RAIIFree_(...)
#endif

#define _Win32_SetLastError_ _WIN32META_ANNOTATION_("SetLastError")
#define _Win32_ImportLibrary_(name) _WIN32META_ANNOTATION_("ImportLibrary(" name ")")
#define _Win32_PreserveResult_ _WIN32META_ANNOTATION_("PreserveResult")
#define _Win32_Retained_ _WIN32META_ANNOTATION_("Retained")
#define _Win32_ContainsInteriorPointers_ _WIN32META_ANNOTATION_("ContainsInteriorPointers")
#define _Win32_Retval_ _WIN32META_ANNOTATION_("RetVal")
#define _Win32_AlsoUsableFor_(name) _WIN32META_ANNOTATION_("AlsoUsableFor(" #name ")")
#define _Win32_AssociatedEnum_(name) _WIN32META_ANNOTATION_("AssociatedEnum(" #name ")")
#define _Win32_AssociatedConstant_(name) _WIN32META_ANNOTATION_("AssociatedConstant(" #name ")")

#define _Windows_SupportedOS_Windows2000_ _WIN32META_ANNOTATION_("SupportedOSPlatform(\"windows5.0\")")
#define _Windows_SupportedOS_WindowsXP_ _WIN32META_ANNOTATION_("SupportedOSPlatform(\"windows5.1.2600\")")
#define _Windows_SupportedOS_WindowsVista_ _WIN32META_ANNOTATION_("SupportedOSPlatform(\"windows6.0.6000\")")
#define _Windows_SupportedOS_Windows7_ _WIN32META_ANNOTATION_("SupportedOSPlatform(\"windows6.1\")")
#define _Windows_SupportedOS_Windows8_ _WIN32META_ANNOTATION_("SupportedOSPlatform(\"windows8.0\")")
#define _Windows_SupportedOS_Windows81_ _WIN32META_ANNOTATION_("SupportedOSPlatform(\"windows8.1\")")
#define _Windows_SupportedOS_10240_ _WIN32META_ANNOTATION_("SupportedOSPlatform(\"windows10.0.10240\")")
#define _Windows_SupportedOS_10586_ _WIN32META_ANNOTATION_("SupportedOSPlatform(\"windows10.0.10586\")")
#define _Windows_SupportedOS_14393_ _WIN32META_ANNOTATION_("SupportedOSPlatform(\"windows10.0.14393\")")
#define _Windows_SupportedOS_15063_ _WIN32META_ANNOTATION_("SupportedOSPlatform(\"windows10.0.15063\")")
#define _Windows_SupportedOS_16299_ _WIN32META_ANNOTATION_("SupportedOSPlatform(\"windows10.0.16299\")")
#define _Windows_SupportedOS_17134_ _WIN32META_ANNOTATION_("SupportedOSPlatform(\"windows10.0.17134\")")
#define _Windows_SupportedOS_17763_ _WIN32META_ANNOTATION_("SupportedOSPlatform(\"windows10.0.17763\")")
#define _Windows_SupportedOS_18362_ _WIN32META_ANNOTATION_("SupportedOSPlatform(\"windows10.0.18362\")")
#define _Windows_SupportedOS_19041_ _WIN32META_ANNOTATION_("SupportedOSPlatform(\"windows10.0.19041\")")
#define _Windows_SupportedOS_Server2000_ _WIN32META_ANNOTATION_("SupportedOSPlatform(\"windowsserver2000\")")
#define _Windows_SupportedOS_Server2003_ _WIN32META_ANNOTATION_("SupportedOSPlatform(\"windowsserver2003\")")
#define _Windows_SupportedOS_Server2008_ _WIN32META_ANNOTATION_("SupportedOSPlatform(\"windowsserver2008\")")
#define _Windows_SupportedOS_Server2012_ _WIN32META_ANNOTATION_("SupportedOSPlatform(\"windowsserver2012\")")
#define _Windows_SupportedOS_Server2016_ _WIN32META_ANNOTATION_("SupportedOSPlatform(\"windowsserver2016\")")
