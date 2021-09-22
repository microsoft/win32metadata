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


using static Windows.Win32.Foundation.Apis;

namespace Windows.Win32.Foundation
{
    public enum NTSTATUS_FACILITY_CODE : uint
    {
        FACILITY_DEBUGGER = 0x1,
        FACILITY_RPC_RUNTIME = 0x2,
        FACILITY_RPC_STUBS = 0x3,
        FACILITY_IO_ERROR_CODE = 0x4,
        FACILITY_CODCLASS_ERROR_CODE = 0x6,
        FACILITY_NTWIN32 = 0x7,
        FACILITY_NTCERT = 0x8,
        FACILITY_NTSSPI = 0x9,
        FACILITY_TERMINAL_SERVER = 0xA,
        FACILITY_USB_ERROR_CODE = 0x10,
        FACILITY_HID_ERROR_CODE = 0x11,
        FACILITY_FIREWIRE_ERROR_CODE = 0x12,
        FACILITY_CLUSTER_ERROR_CODE = 0x13,
        FACILITY_ACPI_ERROR_CODE = 0x14,
        FACILITY_SXS_ERROR_CODE = 0x15,
        FACILITY_TRANSACTION = 0x19,
        FACILITY_COMMONLOG = 0x1A,
        FACILITY_VIDEO = 0x1B,
        FACILITY_FILTER_MANAGER = 0x1C,
        FACILITY_MONITOR = 0x1D,
        FACILITY_GRAPHICS_KERNEL = 0x1E,
        FACILITY_DRIVER_FRAMEWORK = 0x20,
        FACILITY_FVE_ERROR_CODE = 0x21,
        FACILITY_FWP_ERROR_CODE = 0x22,
        FACILITY_NDIS_ERROR_CODE = 0x23,
        FACILITY_QUIC_ERROR_CODE = 0x24,
        FACILITY_TPM = 0x29,
        FACILITY_RTPM = 0x2A,
        FACILITY_HYPERVISOR = 0x35,
        FACILITY_IPSEC = 0x36,
        FACILITY_VIRTUALIZATION = 0x37,
        FACILITY_VOLMGR = 0x38,
        FACILITY_BCD_ERROR_CODE = 0x39,
        FACILITY_WIN32K_NTUSER = 0x3E,
        FACILITY_WIN32K_NTGDI = 0x3F,
        FACILITY_RESUME_KEY_FILTER = 0x40,
        FACILITY_RDBSS = 0x41,
        FACILITY_BTH_ATT = 0x42,
        FACILITY_SECUREBOOT = 0x43,
        FACILITY_AUDIO_KERNEL = 0x44,
        FACILITY_VSM = 0x45,
        FACILITY_VOLSNAP = 0x50,
        FACILITY_SDBUS = 0x51,
        FACILITY_SHARED_VHDX = 0x5C,
        FACILITY_SMB = 0x5D,
        FACILITY_XVS = 0x5E,
        FACILITY_INTERIX = 0x99,
        FACILITY_SPACES = 0xE7,
        FACILITY_SECURITY_CORE = 0xE8,
        FACILITY_SYSTEM_INTEGRITY = 0xE9,
        FACILITY_LICENSING = 0xEA,
        FACILITY_PLATFORM_MANIFEST = 0xEB,
        FACILITY_APP_EXEC = 0xEC,
        FACILITY_MAXIMUM_VALUE = 0xED,
    }

    [Flags]
    public enum DUPLICATE_HANDLE_OPTIONS : uint
    {
        DUPLICATE_CLOSE_SOURCE = 0x00000001,
        DUPLICATE_SAME_ACCESS = 0x00000002,
    }

    [Flags]
    public enum HANDLE_FLAGS : uint
    {
        HANDLE_FLAG_INHERIT = 0x00000001,
        HANDLE_FLAG_PROTECT_FROM_CLOSE = 0x00000002,
    }

}
