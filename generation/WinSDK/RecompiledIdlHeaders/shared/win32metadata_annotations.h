#pragma once

#if defined(WIN32METADATA) && defined(__clang__)
#define _WIN32META_ANNOTATION_(text) __attribute__((annotate(text)))
#else
#define _WIN32META_ANNOTATION_(text)
#endif

#ifndef _Out_retval_
#define _Out_retval_ _Out_ _Win32_Retval_
#endif

#ifndef _COM_Outptr_retval_
#define _COM_Outptr_retval_ _COM_Outptr_ _Win32_Retval_
#endif

#define _Win32_SetLastError_ \
    _WIN32META_ANNOTATION_("win32metadata:set_last_error")
#define _Win32_ImportLibrary_(value) \
    _WIN32META_ANNOTATION_("win32metadata:import_library=" value)
#define _Win32_PreserveResult_ \
    _WIN32META_ANNOTATION_("win32metadata:preserve_result")
#define _Win32_RAIIFree_(function) \
    _WIN32META_ANNOTATION_("win32metadata:raii_free=" #function)
#define _Win32_Retained_ \
    _WIN32META_ANNOTATION_("win32metadata:retained")
#define _Win32_AlsoUsableFor_(type) \
    _WIN32META_ANNOTATION_("win32metadata:also_usable_for=" #type)
#define _Win32_AssociatedEnum_(type) \
    _WIN32META_ANNOTATION_("win32metadata:associated_enum=" #type)
#define _Win32_AssociatedConstant_(name) \
    _WIN32META_ANNOTATION_("win32metadata:associated_constant=" #name)
#define _Win32_Retval_ \
    _WIN32META_ANNOTATION_("win32metadata:retval")

#define _Windows_SupportedOS_Windows2000_ \
    _WIN32META_ANNOTATION_("win32metadata:supported_os=windows5.0")
#define _Windows_SupportedOS_WindowsXP_ \
    _WIN32META_ANNOTATION_("win32metadata:supported_os=windows5.1.2600")
#define _Windows_SupportedOS_WindowsVista_ \
    _WIN32META_ANNOTATION_("win32metadata:supported_os=windows6.0.6000")
#define _Windows_SupportedOS_Windows7_ \
    _WIN32META_ANNOTATION_("win32metadata:supported_os=windows6.1")
#define _Windows_SupportedOS_Windows8_ \
    _WIN32META_ANNOTATION_("win32metadata:supported_os=windows6.2")
#define _Windows_SupportedOS_Windows81_ \
    _WIN32META_ANNOTATION_("win32metadata:supported_os=windows6.3")
#define _Windows_SupportedOS_10240_ \
    _WIN32META_ANNOTATION_("win32metadata:supported_os=windows10.0.10240")
#define _Windows_SupportedOS_10586_ \
    _WIN32META_ANNOTATION_("win32metadata:supported_os=windows10.0.10586")
#define _Windows_SupportedOS_14393_ \
    _WIN32META_ANNOTATION_("win32metadata:supported_os=windows10.0.14393")
#define _Windows_SupportedOS_15063_ \
    _WIN32META_ANNOTATION_("win32metadata:supported_os=windows10.0.15063")
#define _Windows_SupportedOS_16299_ \
    _WIN32META_ANNOTATION_("win32metadata:supported_os=windows10.0.16299")
#define _Windows_SupportedOS_17134_ \
    _WIN32META_ANNOTATION_("win32metadata:supported_os=windows10.0.17134")
#define _Windows_SupportedOS_17763_ \
    _WIN32META_ANNOTATION_("win32metadata:supported_os=windows10.0.17763")
#define _Windows_SupportedOS_18362_ \
    _WIN32META_ANNOTATION_("win32metadata:supported_os=windows10.0.18362")
#define _Windows_SupportedOS_19041_ \
    _WIN32META_ANNOTATION_("win32metadata:supported_os=windows10.0.19041")
#define _Windows_SupportedOS_Server2000_ \
    _WIN32META_ANNOTATION_("win32metadata:supported_os=windowsserver2000")
#define _Windows_SupportedOS_Server2003_ \
    _WIN32META_ANNOTATION_("win32metadata:supported_os=windowsserver2003")
#define _Windows_SupportedOS_Server2008_ \
    _WIN32META_ANNOTATION_("win32metadata:supported_os=windowsserver2008")
#define _Windows_SupportedOS_Server2012_ \
    _WIN32META_ANNOTATION_("win32metadata:supported_os=windowsserver2012")
#define _Windows_SupportedOS_Server2016_ \
    _WIN32META_ANNOTATION_("win32metadata:supported_os=windowsserver2016")
