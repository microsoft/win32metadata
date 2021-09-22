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


namespace Windows.Win32.System.Kernel
{
    public static partial class Apis
    {
        public const int OBJ_HANDLE_TAGBITS = 0x00000003;

        public const uint RTL_BALANCED_NODE_RESERVED_PARENT_MASK = 3;

        public const int OBJ_INHERIT = 0x00000002;

        public const int OBJ_PERMANENT = 0x00000010;

        public const int OBJ_EXCLUSIVE = 0x00000020;

        public const int OBJ_CASE_INSENSITIVE = 0x00000040;

        public const int OBJ_OPENIF = 0x00000080;

        public const int OBJ_OPENLINK = 0x00000100;

        public const int OBJ_KERNEL_HANDLE = 0x00000200;

        public const int OBJ_FORCE_ACCESS_CHECK = 0x00000400;

        public const int OBJ_IGNORE_IMPERSONATED_DEVICEMAP = 0x00000800;

        public const int OBJ_DONT_REPARSE = 0x00001000;

        public const int OBJ_VALID_ATTRIBUTES = 0x00001FF2;

        public const uint NULL64 = 0;

        public const uint MAXUCHAR = 0xff;

        public const uint MAXUSHORT = 0xffff;

        public const uint MAXULONG = 0xffffffff;

    }
}
