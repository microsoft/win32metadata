using System;
using Windows.Win32.Foundation;
using Windows.Win32.Interop;
using Windows.Win32.System.PropertiesSystem; // For PROPERTYKEY
using Windows.Win32.System.SystemServices;
using static Windows.Win32.Foundation.Apis; // Various constants
using static Windows.Win32.System.Diagnostics.Debug.WIN32_ERROR;
using static Windows.Win32.System.SystemServices.Apis; // Various constants
using static Windows.Win32.Media.Multimedia.Apis; // Various constants
using static Windows.Win32.Media.Audio.CoreAudio.Apis; // Various constants
using static Windows.Win32.Graphics.DirectShow.Apis; // Various constants
using static Windows.Win32.UI.WindowsAndMessaging.Apis; // For WM_USER
using static Windows.Win32.Storage.FileSystem.FILE_ACCESS_FLAGS; // For FILE_* constants
using static Windows.Win32.System.Diagnostics.Debug.FACILITY_CODE; // For MAKE_HRESULT constants


namespace Windows.Win32.System.Wmi
{
    public static partial class Apis
    {
        public const uint MI_FLAG_CLASS = 1u<< 0;

        public const uint MI_FLAG_METHOD = 1u<< 1;

        public const uint MI_FLAG_PROPERTY = 1u<< 2;

        public const uint MI_FLAG_PARAMETER = 1u<< 3;

        public const uint MI_FLAG_ASSOCIATION = 1u<< 4;

        public const uint MI_FLAG_INDICATION = 1u<< 5;

        public const uint MI_FLAG_REFERENCE = 1u<< 6;

        public const uint MI_FLAG_ENABLEOVERRIDE = 1u<< 7;

        public const uint MI_FLAG_DISABLEOVERRIDE = 1u<< 8;

        public const uint MI_FLAG_RESTRICTED = 1u<< 9;

        public const uint MI_FLAG_TOSUBCLASS = 1u<< 10;

        public const uint MI_FLAG_TRANSLATABLE = 1u<< 11;

        public const uint MI_FLAG_KEY = 1u<< 12;

        public const uint MI_FLAG_IN = 1u<< 13;

        public const uint MI_FLAG_OUT = 1u<< 14;

        public const uint MI_FLAG_REQUIRED = 1u<< 15;

        public const uint MI_FLAG_STATIC = 1u<< 16;

        public const uint MI_FLAG_ABSTRACT = 1u<< 17;

        public const uint MI_FLAG_TERMINAL = 1u<< 18;

        public const uint MI_FLAG_EXPENSIVE = 1u<< 19;

        public const uint MI_FLAG_STREAM = 1u<< 20;

        public const uint MI_FLAG_READONLY = 1u<< 21;

        public const uint MI_FLAG_EXTENDED = 1u<< 12;

        public const uint MI_FLAG_NOT_MODIFIED = 1u<< 25;

        public const uint MI_FLAG_NULL = 1u<< 29;

        public const uint MI_FLAG_BORROW = 1u<< 30;

        public const uint MI_MODULE_FLAG_STANDARD_QUALIFIERS = 1u<< 0;

        public const uint MI_MODULE_FLAG_DESCRIPTIONS = 1u<< 1;

        public const uint MI_MODULE_FLAG_VALUES = 1u<< 2;

        public const uint MI_MODULE_FLAG_MAPPING_STRINGS = 1u<< 3;

        public const uint MI_MODULE_FLAG_BOOLEANS = 1u<< 4;

        public const uint MI_MODULE_FLAG_CPLUSPLUS = 1u<< 5;

        public const uint MI_MODULE_FLAG_LOCALIZED = 1u<< 6;

        public const uint MI_MODULE_FLAG_FILTER_SUPPORT = 1u<< 7;

        public const uint MI_MAX_LOCALE_SIZE = 128;

        public const uint MI_WRITEMESSAGE_CHANNEL_WARNING = 0;

        public const uint MI_WRITEMESSAGE_CHANNEL_VERBOSE = 1;

        public const uint MI_WRITEMESSAGE_CHANNEL_DEBUG = 2;

        public const uint MI_CALL_VERSION = 1;

        public const uint MI_OPERATIONFLAGS_MANUAL_ACK_RESULTS = 0x0001;

        public const uint MI_OPERATIONFLAGS_NO_RTTI = 0x0400;

        public const uint MI_OPERATIONFLAGS_BASIC_RTTI = 0x0002;

        public const uint MI_OPERATIONFLAGS_STANDARD_RTTI = 0x0800;

        public const uint MI_OPERATIONFLAGS_FULL_RTTI = 0x0004;

        public const uint MI_OPERATIONFLAGS_DEFAULT_RTTI = 0;

        public const uint MI_OPERATIONFLAGS_LOCALIZED_QUALIFIERS = 0x0008;

        public const uint MI_OPERATIONFLAGS_EXPENSIVE_PROPERTIES = 0x0040;

        public const uint MI_OPERATIONFLAGS_POLYMORPHISM_SHALLOW = 0x0080;

        public const uint MI_OPERATIONFLAGS_POLYMORPHISM_DEEP_BASE_PROPS_ONLY = 0x0180;

        public const uint MI_OPERATIONFLAGS_REPORT_OPERATION_STARTED = 0x0200;

        public const uint MI_SERIALIZER_FLAGS_CLASS_DEEP = 1;

        public const uint MI_SERIALIZER_FLAGS_INSTANCE_WITH_CLASS = 1;

        public const uint WBEMS_DISPID_DERIVATION = 23;

        public const uint WBEMS_DISPID_OBJECT_READY = 1;

        public const uint WBEMS_DISPID_COMPLETED = 2;

        public const uint WBEMS_DISPID_PROGRESS = 3;

        public const uint WBEMS_DISPID_OBJECT_PUT = 4;

        public const uint WBEMS_DISPID_CONNECTION_READY = 5;

    }
}
