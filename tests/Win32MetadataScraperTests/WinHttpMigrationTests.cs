using System;
using System.Collections.Generic;
using System.Collections.Immutable;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Reflection.Metadata;
using System.Reflection.Metadata.Ecma335;
using System.Reflection.PortableExecutable;
using System.Security.Cryptography;
using System.Text.Json;
using System.Text.RegularExpressions;
using Xunit;
using Xunit.Abstractions;
using Xunit.Sdk;

namespace Win32MetadataScraperTests
{
    public class WinHttpMigrationTests
    {
        internal const string WinHttpNamespace = "Windows.Win32.Networking.WinHttp";
        private const string PropertyStorageNamespace = "Windows.Win32.System.Com.StructuredStorage";
        private const string MetadataNamespace = "Windows.Win32.Foundation.Metadata";
        private const string WNetNamespace = "Windows.Win32.NetworkManagement.WNet";
        private const string DhcpNamespace = "Windows.Win32.NetworkManagement.Dhcp";
        private const string RestartManagerNamespace = "Windows.Win32.System.RestartManager";
        private const string BluetoothNamespace = "Windows.Win32.Devices.Bluetooth";
        private const string HidNamespace = "Windows.Win32.Devices.HumanInterfaceDevice";
        private const string WerNamespace = "Windows.Win32.System.ErrorReporting";
        private const string DwmNamespace = "Windows.Win32.Graphics.Dwm";
        private const string PowerNamespace = "Windows.Win32.System.Power";
        private const string CabinetsNamespace = "Windows.Win32.Storage.Cabinets";
        private const string WebSocketNamespace = "Windows.Win32.Networking.WebSocket";
        private const string FileHistoryNamespace = "Windows.Win32.Storage.FileHistory";
        private const string ProcessSnapshotNamespace = "Windows.Win32.System.Diagnostics.ProcessSnapshotting";
        private const string HidConstant = "HIDP_STATUS_I8242_TRANS_UNKNOWN";
        private const string WerAlias = "WER_SUBMIT_DISCARD_IF_QUEUED";
        private const string HeldDhcpArrayRow = "DHCP_IP_ARRAY::Elements=[NativeArrayInfo(CountParamIndex=0)]";
        private const string WerAliasField = "F|" + WerAlias +
            "|Public, Static, Literal, HasDefault|UInt32|-1|UInt32:80000000||";
        private readonly ITestOutputHelper output;
        private static readonly SignatureNames Signatures = new SignatureNames();
        private static readonly (string Name, uint Bits)[] DwmContactMembers =
        {
            ("DWMSC_DOWN", 1),
            ("DWMSC_UP", 2),
            ("DWMSC_DRAG", 4),
            ("DWMSC_HOLD", 8),
            ("DWMSC_PENBARREL", 16),
            ("DWMSC_NONE", 0),
            ("DWMSC_ALL", uint.MaxValue),
        };
        private static readonly (string Target, string OS)[] SourceBlockedAvailability =
        {
            ("IAssociatedIdentityProvider", "windows6.1"),
            ("IConnectedIdentityProvider", "windows8.0"),
            ("IIdentityAdvise", "windows6.1"),
            ("IIdentityProvider", "windows6.1"),
            ("IIdentityStore", "windows6.1"),
            ("IWscProduct", "windows8.0"),
            ("IWSCProductList", "windows8.0"),
            ("ICivicAddressReport", "windows6.1"),
            ("IDefaultLocation", "windows6.1"),
            ("ILatLongReport", "windows6.1"),
            ("ILocation", "windows6.1"),
            ("ILocationEvents", "windows6.1"),
            ("ILocationPower", "windows8.0"),
            ("ILocationReport", "windows6.1"),
            ("DRendezvousSessionEvents", "windows6.0.6000"),
            ("IRendezvousApplication", "windows6.0.6000"),
            ("IRendezvousSession", "windows6.0.6000"),
            ("IWCNConnectNotify", "windows6.1"),
            ("IWCNDevice", "windows6.1"),
            ("IInitiateWinSATAssessment", "windows6.0.6000"),
            ("IProvideWinSATAssessmentInfo", "windows6.0.6000"),
            ("IProvideWinSATResultsInfo", "windows6.0.6000"),
            ("IProvideWinSATVisuals", "windows6.0.6000"),
            ("IQueryAllWinSATAssessments", "windows6.0.6000"),
            ("IQueryRecentWinSATAssessment", "windows6.0.6000"),
            ("IWinSATInitiateEvents", "windows6.0.6000"),
        };
        private static readonly string[] SourceBlockedAssociations =
        {
            "IIdentityAdvise::IdentityUpdated::dwIdentityUpdateEvents=[AssociatedEnum(\"IdentityUpdateEvent\")]",
            "IIdentityProvider::Advise::dwIdentityUpdateEvents=[AssociatedEnum(\"IdentityUpdateEvent\")]",
            "IWSCProductList::Initialize::provider=[AssociatedEnum(\"WSC_SECURITY_PROVIDER\")]",
        };
        private static readonly (string Owner, string Member, string Enum, string Native)[] Associations =
        {
            ("WinHttpOpenRequest", "dwFlags", "WINHTTP_OPEN_REQUEST_FLAGS", "UInt32"),
            ("WinHttpOpen", "dwAccessType", "WINHTTP_ACCESS_TYPE", "UInt32"),
            ("WinHttpCreateUrl", "dwFlags", "WIN_HTTP_CREATE_URL_FLAGS", "UInt32"),
            ("WINHTTP_PROXY_INFO", "dwAccessType", "WINHTTP_ACCESS_TYPE", "UInt32"),
            ("WINHTTP_CREDS", "dwAuthScheme", "WINHTTP_CREDS_AUTHSCHEME", "UInt32"),
            ("WINHTTP_CREDS_EX", "dwAuthScheme", "WINHTTP_CREDS_AUTHSCHEME", "UInt32"),
            ("URL_COMPONENTS", "nScheme", "WINHTTP_INTERNET_SCHEME", "Int32"),
            ("WINHTTP_PROXY_RESULT_ENTRY", "ProxyScheme", "WINHTTP_INTERNET_SCHEME", "Int32"),
        };
        private static readonly string[] RestartManagerFunctions =
        {
            "RmStartSession", "RmJoinSession", "RmEndSession", "RmRegisterResources", "RmGetList",
            "RmShutdown", "RmRestart", "RmCancelCurrentTask", "RmAddFilter", "RmRemoveFilter", "RmGetFilterList",
        };
        private static readonly string[] PowerErrorFunctions =
        {
            "PowerRegisterSuspendResumeNotification", "PowerUnregisterSuspendResumeNotification", "PowerGetActiveScheme",
            "PowerReadACValue", "PowerReadDCValue", "PowerSetActiveScheme", "PowerSettingRegisterNotification",
            "PowerSettingUnregisterNotification", "PowerCanRestoreIndividualDefaultPowerScheme", "PowerCreatePossibleSetting",
            "PowerCreateSetting", "PowerDeleteScheme", "PowerDuplicateScheme", "PowerEnumerate", "PowerImportPowerScheme",
            "PowerReadACValueIndex", "PowerReadDescription", "PowerReadFriendlyName", "PowerReadIconResourceSpecifier",
            "PowerReadPossibleDescription", "PowerReadPossibleFriendlyName", "PowerReadPossibleValue", "PowerReadValueIncrement",
            "PowerReadValueMax", "PowerReadValueMin", "PowerReadValueUnitsSpecifier", "PowerRemovePowerSetting",
            "PowerReportThermalEvent", "PowerRestoreDefaultPowerSchemes", "PowerRestoreIndividualDefaultPowerScheme",
            "PowerSettingAccessCheck", "PowerSettingAccessCheckEx", "PowerWriteACValueIndex", "PowerWriteDescription",
            "PowerWriteFriendlyName", "PowerWriteIconResourceSpecifier", "PowerWritePossibleDescription",
            "PowerWritePossibleFriendlyName", "PowerWritePossibleValue", "PowerWriteSettingAttributes",
            "PowerWriteValueIncrement", "PowerWriteValueMax", "PowerWriteValueMin", "PowerWriteValueUnitsSpecifier",
        };
        private static readonly EnumUse[] ReviewedEnumUses = Associations
            .Select(value => new EnumUse(WinHttpNamespace, value.Owner, value.Member, value.Enum, value.Native))
            .Concat(new[]
            {
                new EnumUse("Windows.Win32.System.ApplicationVerifier", "VerifierEnumerateResource", "Flags", "VERIFIER_ENUM_RESOURCE_FLAGS", "UInt32"),
                new EnumUse("Windows.Win32.System.ProcessStatus", "EnumProcessModulesEx", "dwFilterFlag", "ENUM_PROCESS_MODULES_EX_FLAGS", "UInt32"),
                new EnumUse("Windows.Win32.UI.Magnification", "MagSetWindowFilterList", "dwFilterMode", "MW_FILTERMODE", "UInt32"),
                new EnumUse("Windows.Win32.UI.Magnification", "MagGetWindowFilterList", "pdwFilterMode", "MW_FILTERMODE", "UInt32*"),
                new EnumUse("Windows.Win32.System.Diagnostics.ToolHelp", "CreateToolhelp32Snapshot", "dwFlags", "CREATE_TOOLHELP_SNAPSHOT_FLAGS", "UInt32"),
                new EnumUse("Windows.Win32.System.Diagnostics.ToolHelp", "HEAPENTRY32", "dwFlags", "HEAPENTRY32_FLAGS", "UInt32"),
                new EnumUse("Windows.Win32.UI.Input.XboxController", "XInputGetBatteryInformation", "devType", "BATTERY_DEVTYPE", "Byte"),
                new EnumUse("Windows.Win32.UI.Input.XboxController", "XInputGetCapabilities", "dwFlags", "XINPUT_FLAG", "UInt32"),
                new EnumUse("Windows.Win32.UI.Input.XboxController", "XINPUT_BATTERY_INFORMATION", "BatteryType", "BATTERY_TYPE", "Byte"),
                new EnumUse("Windows.Win32.UI.Input.XboxController", "XINPUT_BATTERY_INFORMATION", "BatteryLevel", "BATTERY_LEVEL", "Byte"),
                new EnumUse("Windows.Win32.UI.Input.XboxController", "XINPUT_CAPABILITIES", "Type", "XINPUT_DEVTYPE", "Byte"),
                new EnumUse("Windows.Win32.UI.Input.XboxController", "XINPUT_CAPABILITIES", "SubType", "XINPUT_DEVSUBTYPE", "Byte"),
                new EnumUse("Windows.Win32.UI.Input.XboxController", "XINPUT_CAPABILITIES", "Flags", "XINPUT_CAPABILITIES_FLAGS", "UInt16"),
                new EnumUse("Windows.Win32.UI.Input.XboxController", "XINPUT_GAMEPAD", "wButtons", "XINPUT_GAMEPAD_BUTTON_FLAGS", "UInt16"),
                new EnumUse("Windows.Win32.UI.Input.XboxController", "XINPUT_KEYSTROKE", "VirtualKey", "XINPUT_VIRTUAL_KEY", "UInt16"),
                new EnumUse("Windows.Win32.UI.Input.XboxController", "XINPUT_KEYSTROKE", "Flags", "XINPUT_KEYSTROKE_FLAGS", "UInt16"),
                new EnumUse(WNetNamespace, "CONNECTDLGSTRUCTA", "dwFlags", "CONNECTDLGSTRUCT_FLAGS", "UInt32"),
                new EnumUse(WNetNamespace, "CONNECTDLGSTRUCTW", "dwFlags", "CONNECTDLGSTRUCT_FLAGS", "UInt32"),
                new EnumUse(WNetNamespace, "DISCDLGSTRUCTA", "dwFlags", "DISCDLGSTRUCT_FLAGS", "UInt32"),
                new EnumUse(WNetNamespace, "DISCDLGSTRUCTW", "dwFlags", "DISCDLGSTRUCT_FLAGS", "UInt32"),
                new EnumUse(WNetNamespace, "NETINFOSTRUCT", "dwCharacteristics", "NETINFOSTRUCT_CHARACTERISTICS", "UInt32"),
                new EnumUse(WNetNamespace, "NETINFOSTRUCT", "dwStatus", "WIN32_ERROR", "UInt32", "Windows.Win32.Foundation"),
                new EnumUse(WNetNamespace, "NETRESOURCEA", "dwScope", "NET_RESOURCE_SCOPE", "UInt32"),
                new EnumUse(WNetNamespace, "NETRESOURCEA", "dwType", "NET_RESOURCE_TYPE", "UInt32"),
                new EnumUse(WNetNamespace, "NETRESOURCEW", "dwScope", "NET_RESOURCE_SCOPE", "UInt32"),
                new EnumUse(WNetNamespace, "NETRESOURCEW", "dwType", "NET_RESOURCE_TYPE", "UInt32"),
                new EnumUse(WNetNamespace, "NOTIFYADD", "dwAddFlags", "NET_CONNECT_FLAGS", "UInt32"),
                new EnumUse(WNetNamespace, "NPAddConnection3", "dwFlags", "NET_CONNECT_FLAGS", "UInt32"),
                new EnumUse(WNetNamespace, "NPFormatNetworkName", "dwFlags", "NETWORK_NAME_FORMAT_FLAGS", "UInt32"),
                new EnumUse(WNetNamespace, "NPGetUniversalName", "dwInfoLevel", "UNC_INFO_LEVEL", "UInt32"),
                new EnumUse(WNetNamespace, "WNetAddConnection2A", "dwFlags", "NET_CONNECT_FLAGS", "UInt32"),
                new EnumUse(WNetNamespace, "WNetAddConnection2A", "return", "WIN32_ERROR", "UInt32", "Windows.Win32.Foundation"),
                new EnumUse(WNetNamespace, "WNetAddConnection2W", "dwFlags", "NET_CONNECT_FLAGS", "UInt32"),
                new EnumUse(WNetNamespace, "WNetAddConnection2W", "return", "WIN32_ERROR", "UInt32", "Windows.Win32.Foundation"),
                new EnumUse(WNetNamespace, "WNetAddConnection3A", "dwFlags", "NET_CONNECT_FLAGS", "UInt32"),
                new EnumUse(WNetNamespace, "WNetAddConnection3A", "return", "WIN32_ERROR", "UInt32", "Windows.Win32.Foundation"),
                new EnumUse(WNetNamespace, "WNetAddConnection3W", "dwFlags", "NET_CONNECT_FLAGS", "UInt32"),
                new EnumUse(WNetNamespace, "WNetAddConnection3W", "return", "WIN32_ERROR", "UInt32", "Windows.Win32.Foundation"),
                new EnumUse(WNetNamespace, "WNetAddConnection4A", "dwFlags", "NET_CONNECT_FLAGS", "UInt32"),
                new EnumUse(WNetNamespace, "WNetAddConnection4A", "return", "WIN32_ERROR", "UInt32", "Windows.Win32.Foundation"),
                new EnumUse(WNetNamespace, "WNetAddConnection4W", "dwFlags", "NET_CONNECT_FLAGS", "UInt32"),
                new EnumUse(WNetNamespace, "WNetAddConnection4W", "return", "WIN32_ERROR", "UInt32", "Windows.Win32.Foundation"),
                new EnumUse(WNetNamespace, "WNetAddConnectionA", "return", "WIN32_ERROR", "UInt32", "Windows.Win32.Foundation"),
                new EnumUse(WNetNamespace, "WNetAddConnectionW", "return", "WIN32_ERROR", "UInt32", "Windows.Win32.Foundation"),
                new EnumUse(WNetNamespace, "WNetCancelConnection2A", "dwFlags", "NET_CONNECT_FLAGS", "UInt32"),
                new EnumUse(WNetNamespace, "WNetCancelConnection2A", "return", "WIN32_ERROR", "UInt32", "Windows.Win32.Foundation"),
                new EnumUse(WNetNamespace, "WNetCancelConnection2W", "dwFlags", "NET_CONNECT_FLAGS", "UInt32"),
                new EnumUse(WNetNamespace, "WNetCancelConnection2W", "return", "WIN32_ERROR", "UInt32", "Windows.Win32.Foundation"),
                new EnumUse(WNetNamespace, "WNetCancelConnectionA", "return", "WIN32_ERROR", "UInt32", "Windows.Win32.Foundation"),
                new EnumUse(WNetNamespace, "WNetCancelConnectionW", "return", "WIN32_ERROR", "UInt32", "Windows.Win32.Foundation"),
                new EnumUse(WNetNamespace, "WNetCloseEnum", "return", "WIN32_ERROR", "UInt32", "Windows.Win32.Foundation"),
                new EnumUse(WNetNamespace, "WNetConnectionDialog", "return", "WIN32_ERROR", "UInt32", "Windows.Win32.Foundation"),
                new EnumUse(WNetNamespace, "WNetConnectionDialog1A", "return", "WIN32_ERROR", "UInt32", "Windows.Win32.Foundation"),
                new EnumUse(WNetNamespace, "WNetConnectionDialog1W", "return", "WIN32_ERROR", "UInt32", "Windows.Win32.Foundation"),
                new EnumUse(WNetNamespace, "WNetDisconnectDialog", "return", "WIN32_ERROR", "UInt32", "Windows.Win32.Foundation"),
                new EnumUse(WNetNamespace, "WNetDisconnectDialog1A", "return", "WIN32_ERROR", "UInt32", "Windows.Win32.Foundation"),
                new EnumUse(WNetNamespace, "WNetDisconnectDialog1W", "return", "WIN32_ERROR", "UInt32", "Windows.Win32.Foundation"),
                new EnumUse(WNetNamespace, "WNetEnumResourceA", "return", "WIN32_ERROR", "UInt32", "Windows.Win32.Foundation"),
                new EnumUse(WNetNamespace, "WNetEnumResourceW", "return", "WIN32_ERROR", "UInt32", "Windows.Win32.Foundation"),
                new EnumUse(WNetNamespace, "WNetGetConnectionA", "return", "WIN32_ERROR", "UInt32", "Windows.Win32.Foundation"),
                new EnumUse(WNetNamespace, "WNetGetConnectionW", "return", "WIN32_ERROR", "UInt32", "Windows.Win32.Foundation"),
                new EnumUse(WNetNamespace, "WNetGetLastErrorA", "return", "WIN32_ERROR", "UInt32", "Windows.Win32.Foundation"),
                new EnumUse(WNetNamespace, "WNetGetLastErrorW", "return", "WIN32_ERROR", "UInt32", "Windows.Win32.Foundation"),
                new EnumUse(WNetNamespace, "WNetGetNetworkInformationA", "return", "WIN32_ERROR", "UInt32", "Windows.Win32.Foundation"),
                new EnumUse(WNetNamespace, "WNetGetNetworkInformationW", "return", "WIN32_ERROR", "UInt32", "Windows.Win32.Foundation"),
                new EnumUse(WNetNamespace, "WNetGetProviderNameA", "return", "WIN32_ERROR", "UInt32", "Windows.Win32.Foundation"),
                new EnumUse(WNetNamespace, "WNetGetProviderNameW", "return", "WIN32_ERROR", "UInt32", "Windows.Win32.Foundation"),
                new EnumUse(WNetNamespace, "WNetGetResourceInformationA", "return", "WIN32_ERROR", "UInt32", "Windows.Win32.Foundation"),
                new EnumUse(WNetNamespace, "WNetGetResourceInformationW", "return", "WIN32_ERROR", "UInt32", "Windows.Win32.Foundation"),
                new EnumUse(WNetNamespace, "WNetGetResourceParentA", "return", "WIN32_ERROR", "UInt32", "Windows.Win32.Foundation"),
                new EnumUse(WNetNamespace, "WNetGetResourceParentW", "return", "WIN32_ERROR", "UInt32", "Windows.Win32.Foundation"),
                new EnumUse(WNetNamespace, "WNetGetUniversalNameA", "dwInfoLevel", "UNC_INFO_LEVEL", "UInt32"),
                new EnumUse(WNetNamespace, "WNetGetUniversalNameA", "return", "WIN32_ERROR", "UInt32", "Windows.Win32.Foundation"),
                new EnumUse(WNetNamespace, "WNetGetUniversalNameW", "dwInfoLevel", "UNC_INFO_LEVEL", "UInt32"),
                new EnumUse(WNetNamespace, "WNetGetUniversalNameW", "return", "WIN32_ERROR", "UInt32", "Windows.Win32.Foundation"),
                new EnumUse(WNetNamespace, "WNetGetUserA", "return", "WIN32_ERROR", "UInt32", "Windows.Win32.Foundation"),
                new EnumUse(WNetNamespace, "WNetGetUserW", "return", "WIN32_ERROR", "UInt32", "Windows.Win32.Foundation"),
                new EnumUse(WNetNamespace, "WNetOpenEnumA", "dwScope", "NET_RESOURCE_SCOPE", "UInt32"),
                new EnumUse(WNetNamespace, "WNetOpenEnumA", "dwType", "NET_RESOURCE_TYPE", "UInt32"),
                new EnumUse(WNetNamespace, "WNetOpenEnumA", "dwUsage", "WNET_OPEN_ENUM_USAGE", "UInt32"),
                new EnumUse(WNetNamespace, "WNetOpenEnumA", "return", "WIN32_ERROR", "UInt32", "Windows.Win32.Foundation"),
                new EnumUse(WNetNamespace, "WNetOpenEnumW", "dwScope", "NET_RESOURCE_SCOPE", "UInt32"),
                new EnumUse(WNetNamespace, "WNetOpenEnumW", "dwType", "NET_RESOURCE_TYPE", "UInt32"),
                new EnumUse(WNetNamespace, "WNetOpenEnumW", "dwUsage", "WNET_OPEN_ENUM_USAGE", "UInt32"),
                new EnumUse(WNetNamespace, "WNetOpenEnumW", "return", "WIN32_ERROR", "UInt32", "Windows.Win32.Foundation"),
                new EnumUse(WNetNamespace, "WNetUseConnection4A", "return", "WIN32_ERROR", "UInt32", "Windows.Win32.Foundation"),
                new EnumUse(WNetNamespace, "WNetUseConnection4W", "return", "WIN32_ERROR", "UInt32", "Windows.Win32.Foundation"),
                new EnumUse(WNetNamespace, "WNetUseConnectionA", "dwFlags", "NET_CONNECT_FLAGS", "UInt32"),
                new EnumUse(WNetNamespace, "WNetUseConnectionA", "return", "WIN32_ERROR", "UInt32", "Windows.Win32.Foundation"),
                new EnumUse(WNetNamespace, "WNetUseConnectionW", "dwFlags", "NET_CONNECT_FLAGS", "UInt32"),
                new EnumUse(WNetNamespace, "WNetUseConnectionW", "return", "WIN32_ERROR", "UInt32", "Windows.Win32.Foundation"),
            })
            .Concat(RestartManagerFunctions.Select(name => new EnumUse(RestartManagerNamespace, name,
                "return", "WIN32_ERROR", "UInt32", "Windows.Win32.Foundation")))
            .Concat(PowerErrorFunctions.Select(name => new EnumUse(PowerNamespace, name,
                "return", "WIN32_ERROR", "UInt32", "Windows.Win32.Foundation")))
            .Concat(new[]
            {
                new EnumUse(WerNamespace, "WerRegisterFile", "dwFlags", "WER_FILE", "UInt32"),
                new EnumUse(WerNamespace, "WerReportAddFile", "dwFileFlags", "WER_FILE", "UInt32"),
                new EnumUse(WerNamespace, "WerReportSubmit", "dwFlags", "WER_SUBMIT_FLAGS", "UInt32"),
                new EnumUse(WerNamespace, "WerGetFlags", "pdwFlags", "WER_FAULT_REPORTING", "UInt32*"),
                new EnumUse(WerNamespace, "WerSetFlags", "dwFlags", "WER_FAULT_REPORTING", "UInt32"),
                new EnumUse(PowerNamespace, "PowerDeterminePlatformRoleEx", "Version", "POWER_PLATFORM_ROLE_VERSION", "UInt32"),
                new EnumUse(PowerNamespace, "PowerRegisterSuspendResumeNotification", "Flags", "REGISTER_NOTIFICATION_FLAGS",
                    "UInt32", "Windows.Win32.UI.WindowsAndMessaging"),
                new EnumUse(PowerNamespace, "PowerSettingRegisterNotification", "Flags", "REGISTER_NOTIFICATION_FLAGS",
                    "UInt32", "Windows.Win32.UI.WindowsAndMessaging"),
                new EnumUse(PowerNamespace, "PowerSettingAccessCheckEx", "AccessType", "REG_SAM_FLAGS",
                    "UInt32", "Windows.Win32.System.Registry"),
                new EnumUse(CabinetsNamespace, "FDICreate", "cpuType", "FDICREATE_CPU_TYPE", "Int32"),
            }).ToArray();
        private static readonly HandleUse[] ReviewedHandleUses =
        {
            new HandleUse(BluetoothNamespace, "BluetoothFindDeviceClose", "hFind", "HBLUETOOTH_DEVICE_FIND", "IntPtr"),
            new HandleUse(BluetoothNamespace, "BluetoothFindFirstDevice", "return", "HBLUETOOTH_DEVICE_FIND", "IntPtr"),
            new HandleUse(BluetoothNamespace, "BluetoothFindFirstRadio", "return", "HBLUETOOTH_RADIO_FIND", "IntPtr"),
            new HandleUse(BluetoothNamespace, "BluetoothFindNextDevice", "hFind", "HBLUETOOTH_DEVICE_FIND", "IntPtr"),
            new HandleUse(BluetoothNamespace, "BluetoothFindNextRadio", "hFind", "HBLUETOOTH_RADIO_FIND", "IntPtr"),
            new HandleUse(BluetoothNamespace, "BluetoothFindRadioClose", "hFind", "HBLUETOOTH_RADIO_FIND", "IntPtr"),
            new HandleUse(WerNamespace, "WerReportAddDump", "hReportHandle", "HREPORT", "IntPtr"),
            new HandleUse(WerNamespace, "WerReportAddFile", "hReportHandle", "HREPORT", "IntPtr"),
            new HandleUse(WerNamespace, "WerReportCloseHandle", "hReportHandle", "HREPORT", "IntPtr"),
            new HandleUse(WerNamespace, "WerReportCreate", "phReportHandle", "HREPORT*", "IntPtr*"),
            new HandleUse(WerNamespace, "WerReportSetParameter", "hReportHandle", "HREPORT", "IntPtr"),
            new HandleUse(WerNamespace, "WerReportSetUIOption", "hReportHandle", "HREPORT", "IntPtr"),
            new HandleUse(WerNamespace, "WerReportSubmit", "hReportHandle", "HREPORT", "IntPtr"),
            new HandleUse(WerNamespace, "WerStoreClose", "hReportStore", "HREPORTSTORE", "Void*"),
            new HandleUse(WerNamespace, "WerStoreGetFirstReportKey", "hReportStore", "HREPORTSTORE", "Void*"),
            new HandleUse(WerNamespace, "WerStoreGetNextReportKey", "hReportStore", "HREPORTSTORE", "Void*"),
            new HandleUse(WerNamespace, "WerStoreGetReportCount", "hReportStore", "HREPORTSTORE", "Void*"),
            new HandleUse(WerNamespace, "WerStoreGetSizeOnDisk", "hReportStore", "HREPORTSTORE", "Void*"),
            new HandleUse(WerNamespace, "WerStoreOpen", "phReportStore", "HREPORTSTORE*", "Void**"),
            new HandleUse(WerNamespace, "WerStoreQueryReportMetadataV1", "hReportStore", "HREPORTSTORE", "Void*"),
            new HandleUse(WerNamespace, "WerStoreQueryReportMetadataV2", "hReportStore", "HREPORTSTORE", "Void*"),
            new HandleUse(WerNamespace, "WerStoreQueryReportMetadataV3", "hReportStore", "HREPORTSTORE", "Void*"),
            new HandleUse(WerNamespace, "WerStoreUploadReport", "hReportStore", "HREPORTSTORE", "Void*"),
        };
        private static readonly LifecycleTransfer[] ReviewedLifecycleTransfers =
        {
            new LifecycleTransfer(BluetoothNamespace, "HBLUETOOTH_DEVICE_FIND", "BluetoothFindFirstDevice", "return", "BluetoothFindDeviceClose", true),
            new LifecycleTransfer(BluetoothNamespace, "HBLUETOOTH_RADIO_FIND", "BluetoothFindFirstRadio", "return", "BluetoothFindRadioClose", true),
            new LifecycleTransfer(WerNamespace, "HREPORT", "WerReportCreate", "phReportHandle", "WerReportCloseHandle", true),
            new LifecycleTransfer(WerNamespace, "HREPORTSTORE", "WerStoreOpen", "phReportStore", "WerStoreClose", true),
            new LifecycleTransfer(WebSocketNamespace, "WEB_SOCKET_HANDLE", "WebSocketCreateClientHandle", "phWebSocket", "WebSocketDeleteHandle"),
            new LifecycleTransfer(WebSocketNamespace, "WEB_SOCKET_HANDLE", "WebSocketCreateServerHandle", "phWebSocket", "WebSocketDeleteHandle"),
            new LifecycleTransfer(FileHistoryNamespace, "FH_SERVICE_PIPE_HANDLE", "FhServiceOpenPipe", "Pipe", "FhServiceClosePipe"),
            new LifecycleTransfer(ProcessSnapshotNamespace, "HPSSWALK", "PssWalkMarkerCreate", "WalkMarkerHandle", "PssWalkMarkerFree"),
        };
        private static readonly string[] ReviewedNativeConstantSites =
        {
            BluetoothNamespace + ".Apis.AF_BTH",
            HidNamespace + ".Apis." + HidConstant,
            WerNamespace + ".Apis." + WerAlias,
        };
        private static readonly (string Namespace, string Owner, string Method, string Parameter)[] NativeRetvalUses =
        {
            ("Windows.Win32.Devices.Geolocation", "ICivicAddressReport", "GetAddressLine1", "pbstrAddress1"),
            ("Windows.Win32.Devices.Geolocation", "ICivicAddressReport", "GetAddressLine2", "pbstrAddress2"),
            ("Windows.Win32.Devices.Geolocation", "ICivicAddressReport", "GetCity", "pbstrCity"),
            ("Windows.Win32.Devices.Geolocation", "ICivicAddressReport", "GetCountryRegion", "pbstrCountryRegion"),
            ("Windows.Win32.Devices.Geolocation", "ICivicAddressReport", "GetDetailLevel", "pDetailLevel"),
            ("Windows.Win32.Devices.Geolocation", "ICivicAddressReport", "GetPostalCode", "pbstrPostalCode"),
            ("Windows.Win32.Devices.Geolocation", "ICivicAddressReport", "GetStateProvince", "pbstrStateProvince"),
            ("Windows.Win32.Devices.Geolocation", "ICivicAddressReportFactory", "get_CivicAddressReport", "pVal"),
            ("Windows.Win32.Devices.Geolocation", "IDefaultLocation", "GetReport", "ppLocationReport"),
            ("Windows.Win32.Devices.Geolocation", "IDispCivicAddressReport", "get_AddressLine1", "pAddress1"),
            ("Windows.Win32.Devices.Geolocation", "IDispCivicAddressReport", "get_AddressLine2", "pAddress2"),
            ("Windows.Win32.Devices.Geolocation", "IDispCivicAddressReport", "get_City", "pCity"),
            ("Windows.Win32.Devices.Geolocation", "IDispCivicAddressReport", "get_CountryRegion", "pCountryRegion"),
            ("Windows.Win32.Devices.Geolocation", "IDispCivicAddressReport", "get_DetailLevel", "pDetailLevel"),
            ("Windows.Win32.Devices.Geolocation", "IDispCivicAddressReport", "get_PostalCode", "pPostalCode"),
            ("Windows.Win32.Devices.Geolocation", "IDispCivicAddressReport", "get_StateProvince", "pStateProvince"),
            ("Windows.Win32.Devices.Geolocation", "IDispCivicAddressReport", "get_Timestamp", "pVal"),
            ("Windows.Win32.Devices.Geolocation", "IDispLatLongReport", "get_Altitude", "pVal"),
            ("Windows.Win32.Devices.Geolocation", "IDispLatLongReport", "get_AltitudeError", "pVal"),
            ("Windows.Win32.Devices.Geolocation", "IDispLatLongReport", "get_ErrorRadius", "pVal"),
            ("Windows.Win32.Devices.Geolocation", "IDispLatLongReport", "get_Latitude", "pVal"),
            ("Windows.Win32.Devices.Geolocation", "IDispLatLongReport", "get_Longitude", "pVal"),
            ("Windows.Win32.Devices.Geolocation", "IDispLatLongReport", "get_Timestamp", "pVal"),
            ("Windows.Win32.Devices.Geolocation", "ILatLongReport", "GetAltitude", "pAltitude"),
            ("Windows.Win32.Devices.Geolocation", "ILatLongReport", "GetAltitudeError", "pAltitudeError"),
            ("Windows.Win32.Devices.Geolocation", "ILatLongReport", "GetErrorRadius", "pErrorRadius"),
            ("Windows.Win32.Devices.Geolocation", "ILatLongReport", "GetLatitude", "pLatitude"),
            ("Windows.Win32.Devices.Geolocation", "ILatLongReport", "GetLongitude", "pLongitude"),
            ("Windows.Win32.Devices.Geolocation", "ILatLongReportFactory", "get_LatLongReport", "pVal"),
            ("Windows.Win32.Devices.Geolocation", "ILocation", "GetDesiredAccuracy", "pDesiredAccuracy"),
            ("Windows.Win32.Devices.Geolocation", "ILocation", "GetReport", "ppLocationReport"),
            ("Windows.Win32.Devices.Geolocation", "ILocation", "GetReportInterval", "pMilliseconds"),
            ("Windows.Win32.Devices.Geolocation", "ILocation", "GetReportStatus", "pStatus"),
            ("Windows.Win32.Devices.Geolocation", "ILocationReport", "GetSensorID", "pSensorID"),
            ("Windows.Win32.Devices.Geolocation", "ILocationReport", "GetTimestamp", "pCreationTime"),
            ("Windows.Win32.Devices.Geolocation", "ILocationReport", "GetValue", "pValue"),
            ("Windows.Win32.Devices.Geolocation", "ILocationReportFactory", "get_DesiredAccuracy", "pDesiredAccuracy"),
            ("Windows.Win32.Devices.Geolocation", "ILocationReportFactory", "get_ReportInterval", "pMilliseconds"),
            ("Windows.Win32.Devices.Geolocation", "ILocationReportFactory", "get_Status", "pVal"),
            ("Windows.Win32.Networking.NetworkListManager", "INetworkConnection2", "IsDomainAuthenticatedBy", "pValue"),
            ("Windows.Win32.System.RemoteAssistance", "IRendezvousSession", "get_State", "pSessionState"),
            ("Windows.Win32.System.RemoteAssistance", "IRendezvousSession", "get_RemoteUser", "bstrUserName"),
            ("Windows.Win32.System.RemoteAssistance", "IRendezvousSession", "get_Flags", "pFlags"),
            ("Windows.Win32.System.AssessmentTool", "IProvideWinSATAssessmentInfo", "get_Description", "description"),
            ("Windows.Win32.System.AssessmentTool", "IProvideWinSATAssessmentInfo", "get_Score", "score"),
            ("Windows.Win32.System.AssessmentTool", "IProvideWinSATAssessmentInfo", "get_Title", "title"),
            ("Windows.Win32.System.AssessmentTool", "IProvideWinSATResultsInfo", "get_AssessmentDateTime", "fileTime"),
            ("Windows.Win32.System.AssessmentTool", "IProvideWinSATResultsInfo", "get_AssessmentState", "state"),
            ("Windows.Win32.System.AssessmentTool", "IProvideWinSATResultsInfo", "get_RatingStateDesc", "description"),
            ("Windows.Win32.System.AssessmentTool", "IProvideWinSATResultsInfo", "get_SystemRating", "level"),
            ("Windows.Win32.System.AssessmentTool", "IProvideWinSATResultsInfo", "GetAssessmentInfo", "ppinfo"),
            ("Windows.Win32.System.AssessmentTool", "IQueryAllWinSATAssessments", "get_AllXML", "ppDomNodeList"),
            ("Windows.Win32.System.AssessmentTool", "IQueryOEMWinSATCustomization", "GetOEMPrePopulationInfo", "state"),
            ("Windows.Win32.System.AssessmentTool", "IQueryRecentWinSATAssessment", "get_Info", "ppWinSATAssessmentInfo"),
            ("Windows.Win32.System.AssessmentTool", "IQueryRecentWinSATAssessment", "get_XML", "ppDomNodeList"),
            ("Windows.Win32.System.SecurityCenter", "IWscProduct", "get_ProductGuid", "pVal"),
            ("Windows.Win32.System.SecurityCenter", "IWscProduct", "get_ProductIsDefault", "pVal"),
            ("Windows.Win32.System.SecurityCenter", "IWscProduct", "get_ProductName", "pVal"),
            ("Windows.Win32.System.SecurityCenter", "IWscProduct", "get_ProductState", "pVal"),
            ("Windows.Win32.System.SecurityCenter", "IWscProduct", "get_ProductStateTimestamp", "pVal"),
            ("Windows.Win32.System.SecurityCenter", "IWscProduct", "get_RemediationPath", "pVal"),
            ("Windows.Win32.System.SecurityCenter", "IWscProduct", "get_SignatureStatus", "pVal"),
            ("Windows.Win32.System.SecurityCenter", "IWscProduct2", "get_AntivirusProtectionUpdateSubstatus", "peStatus"),
            ("Windows.Win32.System.SecurityCenter", "IWscProduct2", "get_AntivirusScanSubstatus", "peStatus"),
            ("Windows.Win32.System.SecurityCenter", "IWscProduct2", "get_AntivirusSettingsSubstatus", "peStatus"),
            ("Windows.Win32.System.SecurityCenter", "IWscProduct2", "get_FirewallDomainProfileSubstatus", "peStatus"),
            ("Windows.Win32.System.SecurityCenter", "IWscProduct2", "get_FirewallPrivateProfileSubstatus", "peStatus"),
            ("Windows.Win32.System.SecurityCenter", "IWscProduct2", "get_FirewallPublicProfileSubstatus", "peStatus"),
            ("Windows.Win32.System.SecurityCenter", "IWscProduct3", "get_AntivirusDaysUntilExpired", "pdwDays"),
            ("Windows.Win32.System.SecurityCenter", "IWSCProductList", "get_Count", "pVal"),
            ("Windows.Win32.System.SecurityCenter", "IWSCProductList", "get_Item", "pVal"),
        };
        private static readonly (string Namespace, string Owner, string Method) ReviewedPreservedResult =
            ("Windows.Win32.System.Com.Events", "IEnumEventObject", "Reset");
        private static readonly (string Namespace, string Owner, string Method, string Parameter,
            ParameterAttributes Before, ParameterAttributes After)[] NativeDirectionUses =
        {
            (DhcpNamespace, "Apis", "DhcpEnumSubnets", "EnumInfo",
                ParameterAttributes.Out, ParameterAttributes.In | ParameterAttributes.Out),
        };
        private static readonly EnumUse[] PropertyStorageEnumUses =
        {
            new EnumUse(PropertyStorageNamespace, "PROPSPEC", "ulKind", "PROPSPEC_KIND", "UInt32"),
            new EnumUse(PropertyStorageNamespace, "STATPROPSTG", "vt", "VARENUM", "UInt16", "Windows.Win32.System.Variant"),
            new EnumUse(PropertyStorageNamespace, "PROPVARIANT+_Anonymous_e__Union+_Anonymous_e__Struct", "vt",
                "VARENUM", "UInt16", "Windows.Win32.System.Variant"),
        };
        private static readonly string[] PilotAdditionalOwnedMethods =
        {
            "CeipIsOptedIn",
            "VerifierEnumerateResource",
            "MagGetColorEffect", "MagGetFullscreenColorEffect", "MagGetFullscreenTransform",
            "MagGetImageScalingCallback", "MagGetInputTransform", "MagGetWindowFilterList",
            "MagGetWindowSource", "MagGetWindowTransform", "MagInitialize", "MagSetColorEffect",
            "MagSetFullscreenColorEffect", "MagSetFullscreenTransform", "MagSetImageScalingCallback",
            "MagSetInputTransform", "MagSetWindowFilterList", "MagSetWindowSource", "MagSetWindowTransform",
            "MagShowSystemCursor", "MagUninitialize",
            "EmptyWorkingSet", "EnumDeviceDrivers", "EnumPageFilesA", "EnumPageFilesW", "EnumProcesses",
            "EnumProcessModules", "EnumProcessModulesEx", "GetDeviceDriverBaseNameA", "GetDeviceDriverBaseNameW",
            "GetDeviceDriverFileNameA", "GetDeviceDriverFileNameW", "GetMappedFileNameA", "GetMappedFileNameW",
            "GetModuleBaseNameA", "GetModuleBaseNameW", "GetModuleFileNameExA", "GetModuleFileNameExW",
            "GetModuleInformation", "GetPerformanceInfo", "GetProcessImageFileNameA", "GetProcessImageFileNameW",
            "GetProcessMemoryInfo", "GetWsChanges", "GetWsChangesEx", "InitializeProcessForWsWatch",
            "QueryWorkingSet", "QueryWorkingSetEx",
            "EnumDynamicTimeZoneInformation", "FileTimeToSystemTime", "GetDynamicTimeZoneInformation",
            "GetDynamicTimeZoneInformationEffectiveYears", "GetTimeZoneInformation", "GetTimeZoneInformationForYear",
            "LocalFileTimeToLocalSystemTime", "LocalSystemTimeToLocalFileTime", "SetDynamicTimeZoneInformation",
            "SetTimeZoneInformation", "SystemTimeToFileTime", "SystemTimeToTzSpecificLocalTime",
            "SystemTimeToTzSpecificLocalTimeEx", "TzSpecificLocalTimeToSystemTime", "TzSpecificLocalTimeToSystemTimeEx",
            "UalStart", "UalStop", "UalInstrument", "UalRegisterProduct",
            "CreateToolhelp32Snapshot", "Heap32First", "Heap32ListFirst", "Heap32ListNext", "Heap32Next",
            "Module32First", "Module32FirstW", "Module32Next", "Module32NextW", "Process32First", "Process32FirstW",
            "Process32Next", "Process32NextW", "Thread32First", "Thread32Next", "Toolhelp32ReadProcessMemory",
            "WslIsDistributionRegistered", "WslRegisterDistribution", "WslUnregisterDistribution",
            "WslConfigureDistribution", "WslGetDistributionConfiguration", "WslLaunchInteractive", "WslLaunch",
            "XInputGetState", "XInputSetState", "XInputGetCapabilities", "XInputEnable",
            "XInputGetAudioDeviceIds", "XInputGetBatteryInformation", "XInputGetKeystroke",
        };
        private static readonly string[] AdditionalOwnedMethods = PilotAdditionalOwnedMethods.Concat(new[]
        {
            "WscRegisterForChanges", "WscUnRegisterChanges", "WscRegisterForUserNotifications",
            "WscGetSecurityProviderHealth", "WscQueryAntiMalwareUri", "WscGetAntiMalwareUri",
            "WcmQueryProperty", "WcmSetProperty", "WcmGetProfileList", "WcmSetProfileList", "WcmFreeMemory",
            "CoGetInterceptor",
            "DhcpAddFilterV4", "DhcpAddSecurityGroup", "DhcpAddServer", "DhcpAddSubnetElement",
            "DhcpAddSubnetElementV4", "DhcpAddSubnetElementV5", "DhcpAddSubnetElementV6", "DhcpAuditLogGetParams",
            "DhcpAuditLogSetParams", "DhcpCApiCleanup", "DhcpCApiInitialize", "DhcpCreateClass",
            "DhcpCreateClassV6", "DhcpCreateClientInfo", "DhcpCreateClientInfoV4", "DhcpCreateClientInfoVQ",
            "DhcpCreateOption", "DhcpCreateOptionV5", "DhcpCreateOptionV6", "DhcpCreateSubnet",
            "DhcpCreateSubnetV6", "DhcpCreateSubnetVQ", "DhcpDeRegisterParamChange", "DhcpDeleteClass",
            "DhcpDeleteClassV6", "DhcpDeleteClientInfo", "DhcpDeleteClientInfoV6", "DhcpDeleteFilterV4",
            "DhcpDeleteServer", "DhcpDeleteSubnet", "DhcpDeleteSubnetV6", "DhcpDeleteSuperScopeV4",
            "DhcpDsCleanup", "DhcpDsInit", "DhcpEnumClasses", "DhcpEnumClassesV6",
            "DhcpEnumFilterV4", "DhcpEnumOptionValues", "DhcpEnumOptionValuesV5", "DhcpEnumOptionValuesV6",
            "DhcpEnumOptions", "DhcpEnumOptionsV5", "DhcpEnumOptionsV6", "DhcpEnumServers",
            "DhcpEnumSubnetClients", "DhcpEnumSubnetClientsFilterStatusInfo", "DhcpEnumSubnetClientsV4", "DhcpEnumSubnetClientsV5",
            "DhcpEnumSubnetClientsV6", "DhcpEnumSubnetClientsVQ", "DhcpEnumSubnetElements", "DhcpEnumSubnetElementsV4",
            "DhcpEnumSubnetElementsV5", "DhcpEnumSubnetElementsV6", "DhcpEnumSubnets", "DhcpEnumSubnetsV6",
            "DhcpGetAllOptionValues", "DhcpGetAllOptionValuesV6", "DhcpGetAllOptions", "DhcpGetAllOptionsV6",
            "DhcpGetClassInfo", "DhcpGetClientInfo", "DhcpGetClientInfoV4", "DhcpGetClientInfoV6",
            "DhcpGetClientInfoVQ", "DhcpGetClientOptions", "DhcpGetFilterV4", "DhcpGetMibInfo",
            "DhcpGetMibInfoV5", "DhcpGetMibInfoV6", "DhcpGetOptionInfo", "DhcpGetOptionInfoV5",
            "DhcpGetOptionInfoV6", "DhcpGetOptionValue", "DhcpGetOptionValueV5", "DhcpGetOptionValueV6",
            "DhcpGetOriginalSubnetMask", "DhcpGetServerBindingInfo", "DhcpGetServerBindingInfoV6", "DhcpGetServerSpecificStrings",
            "DhcpGetSubnetDelayOffer", "DhcpGetSubnetInfo", "DhcpGetSubnetInfoV6", "DhcpGetSubnetInfoVQ",
            "DhcpGetSuperScopeInfoV4", "DhcpGetThreadOptions", "DhcpGetVersion", "DhcpHlprAddV4PolicyCondition",
            "DhcpHlprAddV4PolicyExpr", "DhcpHlprAddV4PolicyRange", "DhcpHlprCreateV4Policy", "DhcpHlprCreateV4PolicyEx",
            "DhcpHlprFindV4DhcpProperty", "DhcpHlprFreeV4DhcpProperty", "DhcpHlprFreeV4DhcpPropertyArray", "DhcpHlprFreeV4Policy",
            "DhcpHlprFreeV4PolicyArray", "DhcpHlprFreeV4PolicyEx", "DhcpHlprFreeV4PolicyExArray", "DhcpHlprIsV4PolicySingleUC",
            "DhcpHlprIsV4PolicyValid", "DhcpHlprIsV4PolicyWellFormed", "DhcpHlprModifyV4PolicyExpr", "DhcpHlprResetV4PolicyExpr",
            "DhcpModifyClass", "DhcpModifyClassV6", "DhcpRegisterParamChange", "DhcpRemoveDNSRegistrations",
            "DhcpRemoveOption", "DhcpRemoveOptionV5", "DhcpRemoveOptionV6", "DhcpRemoveOptionValue",
            "DhcpRemoveOptionValueV5", "DhcpRemoveOptionValueV6", "DhcpRemoveSubnetElement", "DhcpRemoveSubnetElementV4",
            "DhcpRemoveSubnetElementV5", "DhcpRemoveSubnetElementV6", "DhcpRequestParams", "DhcpRpcFreeMemory",
            "DhcpScanDatabase", "DhcpServerAuditlogParamsFree", "DhcpServerBackupDatabase", "DhcpServerGetConfig",
            "DhcpServerGetConfigV4", "DhcpServerGetConfigV6", "DhcpServerGetConfigVQ", "DhcpServerQueryAttribute",
            "DhcpServerQueryAttributes", "DhcpServerQueryDnsRegCredentials", "DhcpServerRedoAuthorization", "DhcpServerRestoreDatabase",
            "DhcpServerSetConfig", "DhcpServerSetConfigV4", "DhcpServerSetConfigV6", "DhcpServerSetConfigVQ",
            "DhcpServerSetDnsRegCredentials", "DhcpServerSetDnsRegCredentialsV5", "DhcpSetClientInfo", "DhcpSetClientInfoV4",
            "DhcpSetClientInfoV6", "DhcpSetClientInfoVQ", "DhcpSetFilterV4", "DhcpSetOptionInfo",
            "DhcpSetOptionInfoV5", "DhcpSetOptionInfoV6", "DhcpSetOptionValue", "DhcpSetOptionValueV5",
            "DhcpSetOptionValueV6", "DhcpSetOptionValues", "DhcpSetOptionValuesV5", "DhcpSetServerBindingInfo",
            "DhcpSetServerBindingInfoV6", "DhcpSetSubnetDelayOffer", "DhcpSetSubnetInfo", "DhcpSetSubnetInfoV6",
            "DhcpSetSubnetInfoVQ", "DhcpSetSuperScopeV4", "DhcpSetThreadOptions", "DhcpUndoRequestParams",
            "DhcpV4AddPolicyRange", "DhcpV4CreateClientInfo", "DhcpV4CreateClientInfoEx", "DhcpV4CreatePolicy",
            "DhcpV4CreatePolicyEx", "DhcpV4DeletePolicy", "DhcpV4EnumPolicies", "DhcpV4EnumPoliciesEx",
            "DhcpV4EnumSubnetClients", "DhcpV4EnumSubnetClientsEx", "DhcpV4EnumSubnetReservations", "DhcpV4FailoverAddScopeToRelationship",
            "DhcpV4FailoverCreateRelationship", "DhcpV4FailoverDeleteRelationship", "DhcpV4FailoverDeleteScopeFromRelationship", "DhcpV4FailoverEnumRelationship",
            "DhcpV4FailoverGetAddressStatus", "DhcpV4FailoverGetClientInfo", "DhcpV4FailoverGetRelationship", "DhcpV4FailoverGetScopeRelationship",
            "DhcpV4FailoverGetScopeStatistics", "DhcpV4FailoverGetSystemTime", "DhcpV4FailoverSetRelationship", "DhcpV4FailoverTriggerAddrAllocation",
            "DhcpV4GetAllOptionValues", "DhcpV4GetClientInfo", "DhcpV4GetClientInfoEx", "DhcpV4GetFreeIPAddress",
            "DhcpV4GetOptionValue", "DhcpV4GetPolicy", "DhcpV4GetPolicyEx", "DhcpV4QueryPolicyEnforcement",
            "DhcpV4RemoveOptionValue", "DhcpV4RemovePolicyRange", "DhcpV4SetOptionValue", "DhcpV4SetOptionValues",
            "DhcpV4SetPolicy", "DhcpV4SetPolicyEnforcement", "DhcpV4SetPolicyEx", "DhcpV6CreateClientInfo",
            "DhcpV6GetFreeIPAddress", "DhcpV6GetStatelessStatistics", "DhcpV6GetStatelessStoreParams", "DhcpV6SetStatelessStoreParams",
            "Dhcpv6CApiCleanup", "Dhcpv6CApiInitialize", "Dhcpv6ReleasePrefix", "Dhcpv6RenewPrefix",
            "Dhcpv6RequestParams", "Dhcpv6RequestPrefix", "MatchEnumTag", "MatchToken",
            "MultinetGetConnectionPerformanceA", "MultinetGetConnectionPerformanceW", "NPAddConnection", "NPAddConnection3",
            "NPAddConnection4", "NPCancelConnection", "NPCancelConnection2", "NPCloseEnum",
            "NPEnumResource", "NPFormatNetworkName", "NPGetCaps", "NPGetConnection",
            "NPGetConnection3", "NPGetConnectionPerformance", "NPGetPersistentUseOptionsForConnection", "NPGetResourceInformation",
            "NPGetResourceParent", "NPGetUniversalName", "NPGetUser", "NPOpenEnum",
            "Netbios", "PreprocessCommand", "PrintError", "PrintMessage",
            "PrintMessageFromModule", "RegisterContext", "RegisterHelper", "WNetAddConnection2A",
            "WNetAddConnection2W", "WNetAddConnection3A", "WNetAddConnection3W", "WNetAddConnection4A",
            "WNetAddConnection4W", "WNetAddConnectionA", "WNetAddConnectionW", "WNetCancelConnection2A",
            "WNetCancelConnection2W", "WNetCancelConnectionA", "WNetCancelConnectionW", "WNetCloseEnum",
            "WNetConnectionDialog", "WNetConnectionDialog1A", "WNetConnectionDialog1W", "WNetDisconnectDialog",
            "WNetDisconnectDialog1A", "WNetDisconnectDialog1W", "WNetEnumResourceA", "WNetEnumResourceW",
            "WNetGetConnectionA", "WNetGetConnectionW", "WNetGetLastErrorA", "WNetGetLastErrorW",
            "WNetGetNetworkInformationA", "WNetGetNetworkInformationW", "WNetGetProviderNameA", "WNetGetProviderNameW",
            "WNetGetResourceInformationA", "WNetGetResourceInformationW", "WNetGetResourceParentA", "WNetGetResourceParentW",
            "WNetGetUniversalNameA", "WNetGetUniversalNameW", "WNetGetUserA", "WNetGetUserW",
            "WNetOpenEnumA", "WNetOpenEnumW", "WNetSetLastErrorA", "WNetSetLastErrorW",
            "WNetUseConnection4A", "WNetUseConnection4W", "WNetUseConnectionA", "WNetUseConnectionW",
        }).ToArray();
        private static readonly string[] AdditionalOwnedTypes =
        {
            "HEAPENTRY32", "IWaaSAssessor",
            "WSL_DISTRIBUTION_FLAGS", "XINPUT_BATTERY_INFORMATION", "XINPUT_CAPABILITIES",
            "XINPUT_GAMEPAD", "XINPUT_KEYSTROKE",
            "IWscProduct", "IWscProduct2", "IWscProduct3", "IWSCProductList",
            "IInitiateWinSATAssessment", "IProvideWinSATAssessmentInfo", "IProvideWinSATResultsInfo",
            "IProvideWinSATVisuals", "IQueryAllWinSATAssessments", "IQueryRecentWinSATAssessment",
            "IWinSATInitiateEvents", "IQueryOEMWinSATCustomization",
            "IRadialControllerInterop", "IRadialControllerConfigurationInterop",
            "IContact", "IContactManager", "IContactCollection", "IContactProperties", "IContactPropertyCollection",
            "ILocationReport", "ILatLongReport", "ICivicAddressReport", "ILocation",
            "ILocationPower", "IDefaultLocation", "ILocationEvents",
            "IDispLatLongReport", "IDispCivicAddressReport", "ILocationReportFactory",
            "ILatLongReportFactory", "ICivicAddressReportFactory",
            "IRdcGeneratorParameters", "IRdcGeneratorFilterMaxParameters", "IRdcGenerator",
            "IRdcFileReader", "IRdcFileWriter", "IRdcSignatureReader", "IRdcComparator", "IRdcLibrary",
            "ISimilarityReportProgress", "ISimilarityTableDumpState", "ISimilarityTraitsMappedView",
            "ISimilarityTraitsMapping", "ISimilarityTraitsTable", "ISimilarityFileIdTable",
            "IRdcSimilarityGenerator", "IFindSimilarResults", "ISimilarity",
            "INetworkListManager", "INetworkListManagerEvents", "INetwork", "IEnumNetworks", "INetworkEvents",
            "INetworkConnection", "INetworkConnection2", "IEnumNetworkConnections", "INetworkConnectionEvents",
            "INetworkCostManager", "INetworkCostManagerEvents", "INetworkConnectionCost", "INetworkConnectionCostEvents",
            "ICallFrame", "ICallIndirect", "ICallInterceptor", "ICallFrameEvents", "ICallUnmarshal", "ICallFrameWalker",
            "IEventSystem", "IEventPublisher", "IEventClass", "IEventClass2", "IEventSubscription", "IFiringControl",
            "IPublisherFilter", "IMultiInterfacePublisherFilter", "IEventObjectChange", "IEventObjectChange2",
            "IEnumEventObject", "IEventObjectCollection", "IEventProperty", "IEventControl", "IMultiInterfaceEventControl",
            "CONNECTDLGSTRUCTA", "CONNECTDLGSTRUCTW", "CONNECTDLGSTRUCT_FLAGS", "DHCP_IP_ARRAY",
            "DISCDLGSTRUCTA", "DISCDLGSTRUCTW", "DISCDLGSTRUCT_FLAGS", "NETINFOSTRUCT",
            "NETINFOSTRUCT_CHARACTERISTICS", "NETRESOURCEA", "NETRESOURCEW", "NETWORK_NAME_FORMAT_FLAGS",
            "NET_CONNECT_FLAGS", "NET_RESOURCE_SCOPE", "NET_RESOURCE_TYPE", "NOTIFYADD",
            "NPDIRECTORY_NOTIFY_OPERATION", "NP_PROPERTY_DIALOG_SELECTION", "UNC_INFO_LEVEL", "WNET_OPEN_ENUM_USAGE",
            "WNPERM_DLG",
        };
        private static readonly string[] NetworkLogicalEnums =
        {
            "UNC_INFO_LEVEL", "WNPERM_DLG", "WNET_OPEN_ENUM_USAGE", "NET_CONNECT_FLAGS",
            "NP_PROPERTY_DIALOG_SELECTION", "NPDIRECTORY_NOTIFY_OPERATION", "NET_RESOURCE_TYPE", "NETWORK_NAME_FORMAT_FLAGS",
            "NET_RESOURCE_SCOPE", "NETINFOSTRUCT_CHARACTERISTICS", "CONNECTDLGSTRUCT_FLAGS", "DISCDLGSTRUCT_FLAGS",
        };
        private static readonly string[] AdditionalLogicalEnums = new[]
        {
            "VERIFIER_ENUM_RESOURCE_FLAGS", "ENUM_PROCESS_MODULES_EX_FLAGS", "MW_FILTERMODE",
            "CREATE_TOOLHELP_SNAPSHOT_FLAGS", "HEAPENTRY32_FLAGS",
            "XINPUT_VIRTUAL_KEY", "BATTERY_TYPE", "BATTERY_LEVEL", "BATTERY_DEVTYPE",
            "XINPUT_DEVTYPE", "XINPUT_DEVSUBTYPE", "XINPUT_CAPABILITIES_FLAGS",
            "XINPUT_GAMEPAD_BUTTON_FLAGS", "XINPUT_KEYSTROKE_FLAGS", "XINPUT_FLAG",
        }.Concat(NetworkLogicalEnums).ToArray();

        public WinHttpMigrationTests(ITestOutputHelper output) => this.output = output;

        [Fact]
        public void HeaderPatchAvailabilityUsesCanonicalPublicMacros()
        {
            string root = Path.Combine(RepositoryRoot, "generation", "WinSDK", "patches");
            using var recipe = JsonDocument.Parse(File.ReadAllText(Path.Combine(root, "SdkHeaders.json")));
            var patches = recipe.RootElement.GetProperty("patches").EnumerateArray().Select(value => value.GetString()).ToArray();
            Assert.Equal(new[] { @"um\winhttp.h.patch" },
                patches.Where(path => Path.GetFileName(path).StartsWith("winhttp.", StringComparison.Ordinal)));
            Assert.DoesNotContain("_Win32_ImportLibrary_", File.ReadAllText(Path.Combine(root, @"um\winhttp.h.patch")));
            string[] pilotPatches =
            {
                @"shared\sal.h.patch", @"um\waasapi.idl.patch", @"um\propidlbase.idl.patch",
                @"um\winhttp.h.patch", @"um\windowsceip.h.patch", @"um\avrfsdk.h.patch",
                @"um\magnification.h.patch", @"um\Psapi.h.patch", @"um\timezoneapi.h.patch",
                @"um\ual.h.patch", @"um\TlHelp32.h.patch", @"um\wslapi.h.patch", @"um\Xinput.h.patch",
            };
            Assert.All(pilotPatches, patch => Assert.Contains(patch, patches));
            string[] patchTexts = pilotPatches.Select(path => File.ReadAllText(Path.Combine(root, path)).Replace("\r\n", "\n")).ToArray();
            Assert.Equal(new[] { @"shared\sal.h.patch" }, patches.Where(path =>
                File.ReadAllText(Path.Combine(root, path)).Contains("win32metadata_annotations.h", StringComparison.Ordinal)));
            Assert.Contains("+#include <win32metadata_annotations.h>",
                File.ReadAllText(Path.Combine(root, @"shared\sal.h.patch")));
            foreach (string idl in new[] { "waasapi", "propidlbase" })
            {
                string text = File.ReadAllText(Path.Combine(root, @"um\" + idl + ".idl.patch"));
                Assert.Contains("+#include <sal.h>", text);
                Assert.DoesNotContain("win32metadata_annotations.h", text);
            }
            foreach (string input in new[] { @"shared\sal.h", @"shared\concurrencysal.h" })
                Assert.Single(recipe.RootElement.GetProperty("midl").GetProperty("inputs").EnumerateArray()
                    .Where(value => value.GetProperty("path").GetString() == input));
            Assert.Equal(18, patchTexts.Sum(text => Regex.Matches(text, @"(?m)^\+_Win32_(?:FlagsEnum|Enum)_\(").Count));
            Assert.Single(patchTexts.Where(text => text.Contains(
                "+cpp_quote(\"_Win32_Enum_(PROPSPEC_KIND, ULONG, PRSPEC_LPWSTR, PRSPEC_PROPID);\")", StringComparison.Ordinal)));
            Assert.Equal(2, patchTexts.Sum(text => Regex.Matches(text, @"(?m)^\+typedef _WIN32META_ANNOTATION_\(""(?:FlagsEnum|Enum)\(").Count));
            foreach (string group in new[] { "WINHTTP_ACCESS_TYPE", "WINHTTP_CREDS_AUTHSCHEME",
                "CREATE_TOOLHELP_SNAPSHOT_FLAGS", "HEAPENTRY32_FLAGS" })
                Assert.Contains(patchTexts, text => text.Contains("+#ifdef WIN32METADATA\n+typedef DWORD " + group + ";\n+#endif\n",
                    StringComparison.Ordinal));
            foreach (string patch in patches)
            {
                Assert.DoesNotContain("_Windows_SupportedOS_", File.ReadAllText(Path.Combine(root, patch)));
                Assert.DoesNotContain("WIN32METADATA_CSHARP", File.ReadAllText(Path.Combine(root, patch)));
            }
        }

        [MigrationFact]
        public void RegeneratedAssessorKeepsItsSingleTypeFloorWithoutMethodInheritance()
        {
            using var current = Open("WINHTTP_MIGRATION_NEW");
            var reader = current.Reader;
            var types = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Where(type => reader.GetString(type.Namespace) == "Windows.Win32.System.UpdateAssessment" &&
                    reader.GetString(type.Name) == "IWaaSAssessor").ToArray();
            Assert.NotEmpty(types);
            foreach (var type in types)
            {
                Assert.Equal(new[] { "windows10.0.15063" },
                    AttributeValues(reader, type.GetCustomAttributes(), "SupportedOSPlatformAttribute"));
                Assert.All(type.GetMethods().Select(reader.GetMethodDefinition),
                    method => Assert.Empty(AttributeValues(reader, method.GetCustomAttributes(), "SupportedOSPlatformAttribute")));
            }
        }

        [Fact]
        public void PropertyStorageIdlFactsHaveOneOriginalArtifactAndNoSemanticFallback()
        {
            string project = Path.Combine(RepositoryRoot, "generation", "WinSDK");
            using var recipe = JsonDocument.Parse(File.ReadAllText(Path.Combine(project, "patches", "SdkHeaders.json")));
            var patches = recipe.RootElement.GetProperty("patches").EnumerateArray().Select(value => value.GetString()).ToArray();
            Assert.Equal(new[] { @"um\propidlbase.idl.patch" },
                patches.Where(path => Path.GetFileName(path).StartsWith("propidl", StringComparison.OrdinalIgnoreCase)));
            foreach (var pair in new[] { ("propidlbase.idl", "PropIdlBase.h"), ("propidl.idl", "PropIdl.h") })
            {
                var output = recipe.RootElement.GetProperty("midl").GetProperty("outputs").EnumerateArray()
                    .Single(value => value.GetProperty("source").GetString() == @"um\" + pair.Item1);
                Assert.Equal(@"um\" + pair.Item2, output.GetProperty("path").GetString());
            }
            string emitter = File.ReadAllText(Path.Combine(project, "emitter.settings.rsp"));
            string os = File.ReadAllText(Path.Combine(project, "supportedOS.rsp"));
            foreach (string name in new[] { "IPropertyStorage", "IPropertySetStorage", "IEnumSTATPROPSTG", "IEnumSTATPROPSETSTG" })
                Assert.DoesNotContain(name + "=", os);
            foreach (string name in new[] { "IEnumSTATPROPSTG", "IEnumSTATPROPSETSTG" })
                foreach (string method in new[] { "Next", "Skip" })
                    Assert.DoesNotContain(name + "::" + method + "=", emitter);
            Assert.DoesNotContain("PROPVARIANT::_Anonymous_e__Union::_Anonymous_e__Struct::vt=", emitter);
            Assert.DoesNotContain("STATPROPSTG::vt=", emitter);
            using var enums = JsonDocument.Parse(File.ReadAllText(Path.Combine(project, "enums.json")));
            Assert.DoesNotContain(enums.RootElement.GetProperty("items").EnumerateArray(),
                item => item.TryGetProperty("name", out var name) && name.GetString() == "PROPSPEC_KIND");
            Assert.Contains("parse-win32-annotations",
                File.ReadAllText(Path.Combine(project, "Partitions", "Com.StructuredStorage", "settings.rsp")));

            string patch = File.ReadAllText(Path.Combine(project, "patches", @"um\propidlbase.idl.patch"));
            Assert.Contains("+cpp_quote(\"_Win32_Enum_(PROPSPEC_KIND, ULONG, PRSPEC_LPWSTR, PRSPEC_PROPID);\")", patch);
            Assert.Equal(2, Regex.Matches(patch, Regex.Escape("[annotation(\"_Win32_AssociatedEnum_(enum VARENUM)\")]")).Count);
            Assert.DoesNotContain("_Win32_AssociatedEnum_(VARENUM)", patch);
            Assert.Equal(4, Regex.Matches(patch, @"(?m)^\+_Win32_AnnotateInterface_\(").Count);
            Assert.Equal(4, Regex.Matches(patch, @"(?m)^\+_Win32_AnnotateMethod_\(").Count);
            Assert.DoesNotContain("+    [local", patch);
            Assert.DoesNotContain("_Win32_SupportedOS_BEGIN_", patch);
            Assert.DoesNotContain("PRSPEC_INVALID);", patch);
            Assert.Contains("VARIANT::_Anonymous_e__Union::_Anonymous_e__Struct::vt=VARENUM", emitter);
            Assert.Contains("IEnumString::Next=[CanReturnMultipleSuccessValues]", emitter);
            Assert.Contains("PropVariantInit=SupportedOSPlatform(\"windows5.0\")", os);
        }

        [MigrationTheory]
        [InlineData(1)]
        [InlineData(2)]
        [InlineData(4)]
        public void SourceIdlPropertyStorageFactsReachOnlyTheirExistingPhysicalTargets(int architecture)
        {
            using var old = Open("WINHTTP_MIGRATION_OLD");
            using var current = Open("WINHTTP_MIGRATION_NEW");
            foreach (string name in new[] { "IPropertyStorage", "IPropertySetStorage", "IEnumSTATPROPSTG", "IEnumSTATPROPSETSTG" })
            {
                var before = Find(old.Reader, PropertyStorageNamespace + "." + name);
                var after = Find(current.Reader, PropertyStorageNamespace + "." + name);
                Assert.Equal(SnapshotType(old.Reader, before, canonicalizeLegacyResults: true), SnapshotType(current.Reader, after));
                Assert.Equal(new[] { "windows5.0" },
                    AttributeValues(current.Reader, after.GetCustomAttributes(), "SupportedOSPlatformAttribute"));
                foreach (var method in after.GetMethods().Select(current.Reader.GetMethodDefinition))
                {
                    string methodName = current.Reader.GetString(method.Name);
                    Assert.Empty(AttributeValues(current.Reader, method.GetCustomAttributes(), "SupportedOSPlatformAttribute"));
                    bool preserve = name.StartsWith("IEnum", StringComparison.Ordinal) && (methodName == "Next" || methodName == "Skip");
                    Assert.Equal(preserve, method.ImplAttributes.HasFlag(MethodImplAttributes.PreserveSig));
                    Assert.DoesNotContain(method.GetCustomAttributes(), handle => IsLegacyResultAttribute(current.Reader, handle));
                }
            }
            var group = Find(current.Reader, PropertyStorageNamespace + ".PROPSPEC_KIND");
            Assert.Equal(SnapshotType(old.Reader, Find(old.Reader, PropertyStorageNamespace + ".PROPSPEC_KIND")),
                SnapshotType(current.Reader, group));
            var values = group.GetFields().Select(current.Reader.GetFieldDefinition).Where(field => !field.GetDefaultValue().IsNil)
                .Select(field => current.Reader.GetString(field.Name) + "=" +
                    current.Reader.GetBlobReader(current.Reader.GetConstant(field.GetDefaultValue()).Value).ReadUInt32());
            Assert.Equal(new[] { "PRSPEC_LPWSTR=0", "PRSPEC_PROPID=1" }, values);
            foreach (var use in PropertyStorageEnumUses)
            {
                var beforeType = Find(old.Reader, use.Namespace + "." + use.Owner);
                var afterType = Find(current.Reader, use.Namespace + "." + use.Owner);
                var before = beforeType.GetFields().Select(old.Reader.GetFieldDefinition)
                    .Single(field => old.Reader.GetString(field.Name) == use.Member);
                var after = afterType.GetFields().Select(current.Reader.GetFieldDefinition)
                    .Single(field => current.Reader.GetString(field.Name) == use.Member);
                Assert.Equal(use.OldType, before.DecodeSignature(Signatures, null));
                Assert.Equal(use.Native, after.DecodeSignature(Signatures, null));
                Assert.Empty(AttributeValues(old.Reader, before.GetCustomAttributes(), "AssociatedEnumAttribute"));
                Assert.Equal(new[] { use.Enum }, AttributeValues(current.Reader, after.GetCustomAttributes(), "AssociatedEnumAttribute"));
                Assert.Equal(before.Attributes, after.Attributes);
                Assert.Equal(before.GetOffset(), after.GetOffset());
                Assert.Equal(beforeType.Attributes, afterType.Attributes);
                Assert.Equal(beforeType.GetLayout().PackingSize, afterType.GetLayout().PackingSize);
                Assert.Equal(beforeType.GetLayout().Size, afterType.GetLayout().Size);
                Assert.Equal(FieldAttributes(old.Reader, before), FieldAttributes(current.Reader, after));
            }
            foreach (string name in new[] { "STATPROPSETSTG", "VERSIONEDSTREAM" })
                Assert.Equal(SnapshotType(old.Reader, Find(old.Reader, PropertyStorageNamespace + "." + name)),
                    SnapshotType(current.Reader, Find(current.Reader, PropertyStorageNamespace + "." + name)));
            this.output.WriteLine($"Architecture {architecture}: four unchanged type-only floors, canonical PreserveSig on four Next/Skip methods, " +
                "one unchanged two-member enum, and exactly three native-storage/AssociatedEnum field uses.");

            TypeDefinition Find(MetadataReader reader, string name) => reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Single(type => (type.GetDeclaringType().IsNil ? reader.GetString(type.Namespace) + "." + reader.GetString(type.Name) :
                    FullName(reader, type.GetDeclaringType()) + "+" + reader.GetString(type.Name)) == name && Applies(reader, type));

            bool Applies(MetadataReader reader, TypeDefinition type)
            {
                while (true)
                {
                    if (!Supports(reader, type.GetCustomAttributes(), architecture)) return false;
                    if (type.GetDeclaringType().IsNil) return true;
                    type = reader.GetTypeDefinition(type.GetDeclaringType());
                }
            }

            string[] FieldAttributes(MetadataReader reader, FieldDefinition field) => field.GetCustomAttributes()
                .Where(handle => AttributeName(reader, handle) != "AssociatedEnumAttribute")
                .Select(handle => AttributeTypeName(reader, handle) + ":" +
                    Convert.ToHexString(reader.GetBlobBytes(reader.GetCustomAttribute(handle).Value)))
                .OrderBy(value => value, StringComparer.Ordinal).ToArray();
        }

        [MigrationTheory]
        [InlineData(1)]
        [InlineData(2)]
        [InlineData(4)]
        public void All119EffectivePilotFloorsMatchOldOnEveryArchitecture(int architecture)
        {
            using var old = Open("WINHTTP_MIGRATION_OLD");
            using var current = Open("WINHTTP_MIGRATION_NEW");
            string[] before = Floors(old.Reader);
            string[] after = Floors(current.Reader);
            Assert.Equal(119, before.Length);
            Assert.Equal(before, after);
            this.output.WriteLine($"Architecture {architecture}: all 119 exact effective pilot OS floors unchanged.");

            string[] Floors(MetadataReader reader)
            {
                var result = new List<string>();
                foreach (var type in reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                    .Where(type => Supports(reader, type.GetCustomAttributes(), architecture)))
                {
                    string ns = reader.GetString(type.Namespace), name = reader.GetString(type.Name);
                    if (ns == "Windows.Win32.System.UpdateAssessment" && name == "IWaaSAssessor")
                        result.AddRange(AttributeValues(reader, type.GetCustomAttributes(), "SupportedOSPlatformAttribute")
                            .Select(floor => ns + "." + name + "=" + floor));
                    if (name != "Apis") continue;
                    foreach (var method in type.GetMethods().Select(reader.GetMethodDefinition)
                        .Where(method => Supports(reader, method.GetCustomAttributes(), architecture)))
                    {
                        string methodName = reader.GetString(method.Name);
                        if (ns == WinHttpNamespace || PilotAdditionalOwnedMethods.Contains(methodName, StringComparer.Ordinal))
                            result.AddRange(AttributeValues(reader, method.GetCustomAttributes(), "SupportedOSPlatformAttribute")
                                .Select(floor => ns + "." + methodName + "=" + floor));
                    }
                }
                return result.OrderBy(value => value, StringComparer.Ordinal).ToArray();
            }
        }

        [MigrationFact]
        public void OriginalWcmBatchPreservesEveryPhysicalType()
        {
            using var control = Open("WINHTTP_MIGRATION_TOOLING_CONTROL");
            using var current = Open("WINHTTP_MIGRATION_NEW");
            this.AssertEveryPhysicalTypeUnchanged(control.Reader, current.Reader, "qualified pilot Wcm control");
        }

        [MigrationTheory]
        [InlineData(1)]
        [InlineData(2)]
        [InlineData(4)]
        public void OriginalWcmBatchPreservesItsFiveExactAvailabilityTargets(int architecture)
        {
            const string ns = "Windows.Win32.NetworkManagement.WindowsConnectionManager";
            using var control = Open("WINHTTP_MIGRATION_TOOLING_CONTROL");
            using var current = Open("WINHTTP_MIGRATION_NEW");
            var before = Methods(control.Reader, ns, "Apis", architecture);
            var after = Methods(current.Reader, ns, "Apis", architecture);
            foreach (string name in new[]
            {
                "WcmFreeMemory", "WcmGetProfileList", "WcmQueryProperty", "WcmSetProfileList", "WcmSetProperty",
            })
            {
                Assert.Contains(name, before.Keys);
                Assert.Contains(name, after.Keys);
                Assert.Equal(new[] { "windows8.0" },
                    AttributeValues(control.Reader, before[name].GetCustomAttributes(), "SupportedOSPlatformAttribute"));
                Assert.Equal(new[] { "windows8.0" },
                    AttributeValues(current.Reader, after[name].GetCustomAttributes(), "SupportedOSPlatformAttribute"));
            }
            this.output.WriteLine($"Architecture {architecture}: exactly the five existing Wcm availability targets remain windows8.0.");
        }

        [MigrationFact]
        public void OriginalIdlBatchPreservesEveryPhysicalType()
        {
            using var control = Open("WINHTTP_MIGRATION_TOOLING_CONTROL");
            using var current = Open("WINHTTP_MIGRATION_NEW");
            this.AssertEveryPhysicalTypeUnchanged(control.Reader, current.Reader, "first four original-IDL control");
        }

        [MigrationTheory]
        [InlineData(1)]
        [InlineData(2)]
        [InlineData(4)]
        public void OriginalIdlBatchPreservesItsEightExactAvailabilityTargets(int architecture)
        {
            using var control = Open("WINHTTP_MIGRATION_TOOLING_CONTROL");
            using var current = Open("WINHTTP_MIGRATION_NEW");
            foreach (var fact in new[]
            {
                ("Windows.Win32.UI.Input.Radial", "IRadialControllerConfigurationInterop", "windows10.0.14393"),
                ("Windows.Win32.UI.Input.Radial", "IRadialControllerInterop", "windows10.0.14393"),
                ("Windows.Win32.Storage.DataDeduplication", "IDedupBackupSupport", "windowsserver2012"),
                ("Windows.Win32.Storage.DataDeduplication", "IDedupReadFileCallback", "windowsserver2012"),
                ("Windows.Win32.UI.Notifications", "INotificationActivationCallback", "windows10.0.10240"),
                ("Windows.Win32.System.ServerBackup", "IWsbApplicationAsync", "windowsserver2008"),
                ("Windows.Win32.System.ServerBackup", "IWsbApplicationBackupSupport", "windowsserver2008"),
                ("Windows.Win32.System.ServerBackup", "IWsbApplicationRestoreSupport", "windowsserver2008"),
            })
            {
                var before = Type(control.Reader, fact.Item2, architecture, fact.Item1);
                var after = Type(current.Reader, fact.Item2, architecture, fact.Item1);
                Assert.Equal(new[] { fact.Item3 },
                    AttributeValues(control.Reader, before.GetCustomAttributes(), "SupportedOSPlatformAttribute"));
                Assert.Equal(new[] { fact.Item3 },
                    AttributeValues(current.Reader, after.GetCustomAttributes(), "SupportedOSPlatformAttribute"));
            }
            this.output.WriteLine($"Architecture {architecture}: all eight original-IDL interface availability targets retain their exact floors.");
        }

        [MigrationTheory]
        [InlineData(1)]
        [InlineData(2)]
        [InlineData(4)]
        public void AuthoredAvailabilityBatchPreservesItsTwelveExactTargets(int architecture)
        {
            const string ns = "Windows.Win32.Management.MobileDeviceManagementRegistration";
            using var control = Open("WINHTTP_MIGRATION_TOOLING_CONTROL");
            using var current = Open("WINHTTP_MIGRATION_NEW");
            var before = Methods(control.Reader, ns, "Apis", architecture);
            var after = Methods(current.Reader, ns, "Apis", architecture);
            foreach (string name in new[]
            {
                "DiscoverManagementService", "DiscoverManagementServiceEx", "GetDeviceRegistrationInfo",
                "GetManagementAppHyperlink", "IsDeviceRegisteredWithManagement", "IsManagementRegistrationAllowed",
                "RegisterDeviceWithManagement", "RegisterDeviceWithManagementUsingAADCredentials",
                "RegisterDeviceWithManagementUsingAADDeviceCredentials", "SetManagedExternally", "UnregisterDeviceWithManagement",
            })
            {
                Assert.Contains(name, before.Keys);
                Assert.Contains(name, after.Keys);
                Assert.Equal(new[] { "windows8.1" },
                    AttributeValues(control.Reader, before[name].GetCustomAttributes(), "SupportedOSPlatformAttribute"));
                Assert.Equal(new[] { "windows8.1" },
                    AttributeValues(current.Reader, after[name].GetCustomAttributes(), "SupportedOSPlatformAttribute"));
            }
            const string xml = "Windows.Win32.Media.DirectShow.Xml";
            var originalGraph = Type(control.Reader, "IXMLGraphBuilder", architecture, xml);
            var currentGraph = Type(current.Reader, "IXMLGraphBuilder", architecture, xml);
            Assert.Equal(new[] { "windows5.0" },
                AttributeValues(control.Reader, originalGraph.GetCustomAttributes(), "SupportedOSPlatformAttribute"));
            Assert.Equal(new[] { "windows5.0" },
                AttributeValues(current.Reader, currentGraph.GetCustomAttributes(), "SupportedOSPlatformAttribute"));
            this.output.WriteLine($"Architecture {architecture}: all eleven MdmReg function floors and the XML graph interface floor remain exact.");
        }

        [Fact]
        public void NativeDwmContactStorageHasNoAuthoredUnderlyingTypeOverride()
        {
            Assert.DoesNotContain(File.ReadAllLines(Path.Combine(RepositoryRoot, "generation", "WinSDK", "scraper.settings.rsp")),
                line => line.TrimStart().StartsWith("DWM_SHOWCONTACT=", StringComparison.Ordinal));
        }

        [Fact]
        public void SourceBlockedGeneratedArtifactsRetainTheirExactLegacyFacts()
        {
            string project = Path.Combine(RepositoryRoot, "generation", "WinSDK");
            string[] osRows = File.ReadAllLines(Path.Combine(project, "supportedOS.rsp"));
            foreach (var fact in SourceBlockedAvailability)
                Assert.Equal(fact.Target + "=SupportedOSPlatform(\"" + fact.OS + "\")",
                    Assert.Single(osRows.Where(row => row.StartsWith(fact.Target + "=", StringComparison.Ordinal))));
            string[] emitter = File.ReadAllLines(Path.Combine(project, "emitter.settings.rsp"));
            foreach (string row in SourceBlockedAssociations.Append("IdentityUpdateEvent"))
                Assert.Single(emitter.Where(value => value == row));
            using var recipe = JsonDocument.Parse(File.ReadAllText(Path.Combine(project, "patches", "SdkHeaders.json")));
            string[] patches = recipe.RootElement.GetProperty("patches").EnumerateArray().Select(value => value.GetString()).ToArray();
            foreach (string file in new[] { "iwscapi.h", "winsatcominterfacei.h", "locationapi.h", "WcnDevice.h",
                "IdentityProvider.h", "IdentityStore.h", "rendezvoussession.h" })
            {
                string source = File.ReadAllText(Path.Combine(project, "RecompiledIdlHeaders", "um", file));
                Assert.Contains("File created by MIDL compiler", source);
                Assert.DoesNotContain(patches, path => File.ReadAllText(Path.Combine(project, "patches", path))
                    .Split('\n').Any(line => line.StartsWith("+++ ", StringComparison.Ordinal) &&
                        line.TrimEnd('\r').EndsWith("/" + file, StringComparison.OrdinalIgnoreCase)));
            }
        }

        [MigrationTheory]
        [InlineData(1)]
        [InlineData(2)]
        [InlineData(4)]
        public void SourceBlockedArtifactsRetainEveryLegacyPhysicalFact(int architecture)
        {
            using var old = Open("WINHTTP_MIGRATION_OLD");
            using var current = Open("WINHTTP_MIGRATION_NEW");
            var originalTypes = old.Reader.TypeDefinitions.Select(old.Reader.GetTypeDefinition)
                .Where(type => Supports(old.Reader, type.GetCustomAttributes(), architecture))
                .ToLookup(type => old.Reader.GetString(type.Name), StringComparer.Ordinal);

            foreach (var fact in SourceBlockedAvailability)
            {
                var (before, after) = RequiredType(fact.Target);
                Assert.Equal(new[] { fact.OS }, AttributeValues(old.Reader, before.GetCustomAttributes(), "SupportedOSPlatformAttribute"));
                Assert.Equal(new[] { fact.OS }, AttributeValues(current.Reader, after.GetCustomAttributes(), "SupportedOSPlatformAttribute"));
            }

            foreach (string row in SourceBlockedAssociations)
            {
                string[] target = row.Substring(0, row.IndexOf('=')).Split(new[] { "::" }, StringSplitOptions.None);
                int quote = row.IndexOf('"');
                string enumName = row.Substring(quote + 1, row.LastIndexOf('"') - quote - 1);
                var (beforeType, _) = RequiredType(target[0]);
                string ns = old.Reader.GetString(beforeType.Namespace);
                var before = Methods(old.Reader, ns, target[0], architecture)[target[1]];
                var after = Methods(current.Reader, ns, target[0], architecture)[target[1]];
                Assert.Equal(Signature(before.DecodeSignature(Signatures, null)), Signature(after.DecodeSignature(Signatures, null)));
                var original = Assert.Single(before.GetParameters().Select(old.Reader.GetParameter)
                    .Where(parameter => old.Reader.GetString(parameter.Name) == target[2]));
                var parameter = Assert.Single(after.GetParameters().Select(current.Reader.GetParameter)
                    .Where(value => current.Reader.GetString(value.Name) == target[2]));
                Assert.Equal(original.SequenceNumber, parameter.SequenceNumber);
                Assert.Equal(original.Attributes, parameter.Attributes);
                Assert.Equal(new[] { enumName }, AttributeValues(old.Reader, original.GetCustomAttributes(), "AssociatedEnumAttribute"));
                Assert.Equal(new[] { enumName }, AttributeValues(current.Reader, parameter.GetCustomAttributes(), "AssociatedEnumAttribute"));
            }

            var (oldFlags, newFlags) = RequiredType("IdentityUpdateEvent");
            Assert.Equal(SnapshotType(old.Reader, oldFlags), SnapshotType(current.Reader, newFlags));
            foreach (var pair in new[] { (old.Reader, oldFlags), (current.Reader, newFlags) })
            {
                var attribute = Assert.Single(pair.Item2.GetCustomAttributes()
                    .Where(handle => AttributeTypeName(pair.Item1, handle) == "System.FlagsAttribute"));
                Assert.Equal(new byte[] { 1, 0, 0, 0 }, pair.Item1.GetBlobBytes(pair.Item1.GetCustomAttribute(attribute).Value));
            }
            this.output.WriteLine($"Architecture {architecture}: all 26 source-blocked floors, three legacy associations/signatures " +
                "and the complete IdentityUpdateEvent flags enum preserved without metadata normalization.");

            (TypeDefinition Before, TypeDefinition After) RequiredType(string name)
            {
                var before = Assert.Single(originalTypes[name]);
                return (before, Type(current.Reader, name, architecture, old.Reader.GetString(before.Namespace)));
            }
        }

        [MigrationFact]
        public void CompleteNewImageClosesConstructorsAndFrozenOldDefectIsExplicit()
        {
            using var old = Open("WINHTTP_MIGRATION_OLD");
            using var current = Open("WINHTTP_MIGRATION_NEW");
            Assert.Equal(37314, old.Reader.TypeDefinitions.Count);
            AssertReviewedTypeSet(old.Reader, current.Reader);
            Assert.Equal(old.Reader.MethodDefinitions.Count, current.Reader.MethodDefinitions.Count);
            Assert.Equal(old.Reader.FieldDefinitions.Count - 4 + 1, current.Reader.FieldDefinitions.Count);
            string[] beforeEnums = EnumIdentities(old.Reader);
            Assert.Equal(beforeEnums, EnumIdentities(current.Reader));
            this.output.WriteLine($"Complete enum identity set unchanged: {beforeEnums.Length}; added 0, removed 0.");
            var defect = Assert.ThrowsAny<XunitException>(() => AssertClosure(old.Reader));
            Assert.Contains("Unresolved local attribute constructor: " + MetadataNamespace + ".SupportedOSPlatformAttribute", defect.Message);
            Assert.Contains("definitions: 0|0|1|Void|String", defect.Message);
            AssertClosure(current.Reader);

            static string[] EnumIdentities(MetadataReader reader) => Types(reader)
                .Where(entry => !entry.Value.BaseType.IsNil && FullName(reader, entry.Value.BaseType) == "System.Enum")
                .Select(entry => entry.Key).OrderBy(value => value, StringComparer.Ordinal).ToArray();
        }

        [MigrationFact]
        public void FrozenInputToolingControlChangesOnlyConstructorBitsAndCanonicalResultEncoding()
        {
            using var old = Open("WINHTTP_MIGRATION_OLD");
            using var control = Open("WINHTTP_MIGRATION_TOOLING_CONTROL");
            Assert.Equal(old.Reader.TypeDefinitions.Count, control.Reader.TypeDefinitions.Count);
            AssertClosure(control.Reader);
            var before = Types(old.Reader);
            var after = Types(control.Reader);
            Assert.Equal(before.Keys.OrderBy(value => value), after.Keys.OrderBy(value => value));
            int corrected = 0, constructors = 0, resultSites = 0, resultAttributes = 0;
            foreach (var entry in before)
            {
                var original = SnapshotType(old.Reader, entry.Value);
                var constructorControl = SnapshotType(old.Reader, entry.Value, correctConstructorInstanceBits: true);
                var expected = SnapshotType(old.Reader, entry.Value, correctConstructorInstanceBits: true, canonicalizeLegacyResults: true);
                Assert.Equal(expected, SnapshotType(control.Reader, after[entry.Key]));
                corrected += original == constructorControl ? 0 : 1;
                var methods = entry.Value.GetMethods().Select(old.Reader.GetMethodDefinition).ToArray();
                constructors += methods.Count(method =>
                    old.Reader.GetString(method.Name) == ".ctor" && !method.Attributes.HasFlag(MethodAttributes.Static) &&
                    !method.DecodeSignature(Signatures, null).Header.IsInstance);
                resultSites += methods.Count(method => method.GetCustomAttributes().Any(handle => IsLegacyResultAttribute(old.Reader, handle)));
                resultAttributes += methods.Sum(method => method.GetCustomAttributes().Count(handle => IsLegacyResultAttribute(old.Reader, handle)));
            }
            Assert.Equal(39, constructors);
            Assert.Equal(39, corrected);
            Assert.Equal(149, resultSites);
            Assert.Equal(resultSites, resultAttributes);
            Assert.DoesNotContain(control.Reader.CustomAttributes, handle => IsLegacyResultAttribute(control.Reader, handle));
            this.output.WriteLine($"Frozen-input tooling control: {constructors} constructor rows in {corrected} types gain HASTHIS; " +
                $"all {resultSites} legacy success-marker sites use PreserveSig, with no other physical changes.");
        }

        [MigrationFact("WINHTTP_MIGRATION_QUALIFIED_ROOT")]
        public void HistoricalFrozenOldConstructorDefectsAreAlreadyFixedInQualifiedRoot()
        {
            Assert.Equal("1361407C2888102CB5161D83503235C09C36F917837C7107CA0A80E5CF4FAC43",
                Convert.ToHexString(SHA256.HashData(File.ReadAllBytes(Environment.GetEnvironmentVariable("WINHTTP_MIGRATION_OLD")))));
            Assert.Equal("D2C9C2BD1ECECB9371773FB3888FB88BD3F56E301F146FC7F6FE029B13140A67",
                Convert.ToHexString(SHA256.HashData(File.ReadAllBytes(Environment.GetEnvironmentVariable("WINHTTP_MIGRATION_QUALIFIED_ROOT")))));
            using var old = Open("WINHTTP_MIGRATION_OLD");
            using var root = Open("WINHTTP_MIGRATION_QUALIFIED_ROOT");
            var before = Types(old.Reader);
            var after = Types(root.Reader);
            Assert.Equal(before.Keys.OrderBy(value => value), after.Keys.OrderBy(value => value));
            var sites = new List<string>();
            foreach (var entry in before)
            {
                Assert.Equal(SnapshotType(old.Reader, entry.Value, correctConstructorInstanceBits: true),
                    SnapshotType(root.Reader, after[entry.Key]));
                foreach (var method in entry.Value.GetMethods().Select(old.Reader.GetMethodDefinition))
                {
                    var signature = method.DecodeSignature(Signatures, null);
                    if (old.Reader.GetString(method.Name) == ".ctor" &&
                        !method.Attributes.HasFlag(MethodAttributes.Static) && !signature.Header.IsInstance)
                        sites.Add(entry.Key + "::.ctor|" + Signature(signature) + "|OLD header=0x00; qualified8d6 header=0x20");
                }
            }
            Assert.Equal(39, sites.Count);
            this.output.WriteLine("All39 defects belong only to the historical b5b7 frozen OLD image; actual qualified8d6 already fixes them:");
            foreach (string site in sites.OrderBy(value => value, StringComparer.Ordinal))
                this.output.WriteLine(site);
        }

        [MigrationFact("WINHTTP_MIGRATION_CANONICAL_ROOT")]
        public void ActualCanonicalRootMatchesTheCompleteToolingControlWithoutAdditionalConstructorChanges()
        {
            Assert.Equal("41A9406EE85E90FBD68BEC29C03405CC3B1A8436FB78344FC3D480F6DAC437B1",
                Convert.ToHexString(SHA256.HashData(File.ReadAllBytes(Environment.GetEnvironmentVariable("WINHTTP_MIGRATION_CANONICAL_ROOT")))));
            using var root = Open("WINHTTP_MIGRATION_CANONICAL_ROOT");
            using var control = Open("WINHTTP_MIGRATION_TOOLING_CONTROL");
            var before = Types(root.Reader);
            var after = Types(control.Reader);
            Assert.Equal(before.Keys.OrderBy(value => value), after.Keys.OrderBy(value => value));
            foreach (var entry in before)
                Assert.Equal(SnapshotType(root.Reader, entry.Value), SnapshotType(control.Reader, after[entry.Key]));
            AssertClosure(root.Reader);
            this.output.WriteLine($"All {before.Count} physical types match the actual canonical3dc root image exactly; " +
                "zero additional constructor, method-flag, signature or attribute changes.");
        }

        [MigrationFact]
        public void EveryPhysicalTypeHasOnlyReviewedHeaderChanges()
        {
            using var control = Open("WINHTTP_MIGRATION_TOOLING_CONTROL");
            using var current = Open("WINHTTP_MIGRATION_NEW");
            var before = Types(control.Reader);
            var after = Types(current.Reader);
            AssertReviewedTypeSet(control.Reader, current.Reader);
            var removed = ReviewedLifecycleTransfers.Where(value => value.Synthetic)
                .Select(value => value.TypeSite + "#124").ToHashSet(StringComparer.Ordinal);
            var used = new HashSet<string>(StringComparer.Ordinal);
            var usedRetvals = new HashSet<string>(StringComparer.Ordinal);
            var usedPreservedResults = new HashSet<string>(StringComparer.Ordinal);
            var usedNativeDirections = new HashSet<string>(StringComparer.Ordinal);
            var usedHandles = new HashSet<string>(StringComparer.Ordinal);
            var usedLifecycles = new HashSet<string>(StringComparer.Ordinal);
            var usedConstants = new HashSet<string>(StringComparer.Ordinal);
            var usedEnumStorage = new HashSet<string>(StringComparer.Ordinal);
            int unchanged = 0;
            foreach (var entry in before.Where(value => !removed.Contains(value.Key)))
            {
                string expected = SnapshotType(control.Reader, entry.Value, normalizeReviewedChanges: true,
                    usedEnumSites: used, usedRetvalSites: usedRetvals, usedPreservedResultSites: usedPreservedResults,
                    usedNativeDirectionSites: usedNativeDirections, usedHandleSites: usedHandles,
                    usedLifecycleSites: usedLifecycles, usedNativeConstantSites: usedConstants,
                    usedEnumStorageSites: usedEnumStorage, normalizePropertyStorageEnumUses: true);
                string actual = SnapshotType(current.Reader, after[entry.Key]);
                Assert.True(expected == actual, $"Unexpected physical metadata change in {entry.Key}.\nExpected:\n{expected}\nActual:\n{actual}");
                unchanged += SnapshotType(control.Reader, entry.Value) == actual ? 1 : 0;
            }
            Assert.Equal(ReviewedEnumUses.Concat(PropertyStorageEnumUses).Select(value => value.Site).OrderBy(value => value),
                used.OrderBy(value => value));
            Assert.Equal(NativeRetvalUses.Select(value => $"{value.Namespace}.{value.Owner}.{value.Method}.{value.Parameter}")
                .OrderBy(value => value), usedRetvals.OrderBy(value => value));
            Assert.Equal(new[] { $"{ReviewedPreservedResult.Namespace}.{ReviewedPreservedResult.Owner}.{ReviewedPreservedResult.Method}" },
                usedPreservedResults.OrderBy(value => value));
            Assert.Equal(NativeDirectionUses.Select(value => $"{value.Namespace}.{value.Owner}.{value.Method}.{value.Parameter}")
                .OrderBy(value => value), usedNativeDirections.OrderBy(value => value));
            Assert.Equal(ReviewedHandleUses.Select(value => value.Site).OrderBy(value => value), usedHandles.OrderBy(value => value));
            Assert.Equal(ReviewedLifecycleTransfers.Select(value => value.Site)
                .Concat(ReviewedLifecycleTransfers.Where(value => !value.Synthetic).Select(value => value.TypeSite)).Distinct()
                .OrderBy(value => value), usedLifecycles.OrderBy(value => value));
            Assert.Equal(ReviewedNativeConstantSites.OrderBy(value => value), usedConstants.OrderBy(value => value));
            Assert.Equal(new[] { DwmNamespace + ".DWM_SHOWCONTACT" }, usedEnumStorage);
            this.output.WriteLine($"All {after.Count} surviving physical types graded; exactly {removed.Count} verified synthetic handles removed, 0 types added; " +
                $"{unchanged} surviving types unchanged; " +
                $"{used.Count} exact native-type/AssociatedEnum sites, {usedRetvals.Count} native MIDL retval sites " +
                $"{usedPreservedResults.Count} reviewed preserved-result site, {usedNativeDirections.Count} exact native SAL direction site, " +
                $"{usedHandles.Count} native handle signature sites, {usedLifecycles.Count} lifecycle targets, " +
                $"{usedConstants.Count} exact native constant sites and {usedEnumStorage.Count} approved native enum storage correction normalized.");
        }

        [MigrationTheory]
        [InlineData(1)]
        [InlineData(2)]
        [InlineData(4)]
        public void ApprovedDwmContactStorageUsesIntAndPreservesEveryNativeBit(int architecture)
        {
            using var old = Open("WINHTTP_MIGRATION_OLD");
            using var current = Open("WINHTTP_MIGRATION_NEW");
            var before = Type(old.Reader, "DWM_SHOWCONTACT", architecture, DwmNamespace);
            var after = Type(current.Reader, "DWM_SHOWCONTACT", architecture, DwmNamespace);
            AssertDwmContactStorage(old.Reader, before, signed: false);
            AssertDwmContactStorage(current.Reader, after, signed: true);
            var used = new HashSet<string>(StringComparer.Ordinal);
            Assert.Equal(SnapshotType(old.Reader, before, normalizeReviewedChanges: true, usedEnumStorageSites: used),
                SnapshotType(current.Reader, after));
            Assert.Equal(new[] { DwmNamespace + ".DWM_SHOWCONTACT" }, used);
            var all = after.GetFields().Select(current.Reader.GetFieldDefinition)
                .Single(field => current.Reader.GetString(field.Name) == "DWMSC_ALL");
            Assert.Equal(-1, current.Reader.GetBlobReader(current.Reader.GetConstant(all.GetDefaultValue()).Value).ReadInt32());
            var originalMethod = Methods(old.Reader, DwmNamespace, "Apis", architecture)["DwmShowContact"];
            var method = Methods(current.Reader, DwmNamespace, "Apis", architecture)["DwmShowContact"];
            var signature = method.DecodeSignature(Signatures, null);
            Assert.Equal(Signature(originalMethod.DecodeSignature(Signatures, null)), Signature(signature));
            Assert.Equal(DwmNamespace + ".DWM_SHOWCONTACT", signature.ParameterTypes[1]);
            Assert.Equal(Import(old.Reader, originalMethod), Import(current.Reader, method));
            this.output.WriteLine($"DWM_SHOWCONTACT/{architecture}: Int32 storage, seven ordered members and unchanged flags/attributes; " +
                "DWMSC_ALL=-1 retains FFFFFFFF; native DwmShowContact signature/import unchanged.");
        }

        [MigrationTheory]
        [InlineData(1)]
        [InlineData(2)]
        [InlineData(4)]
        public void NativeHandleContractsReachOnlyTheExactProducerTargets(int architecture)
        {
            using var old = Open("WINHTTP_MIGRATION_OLD");
            using var current = Open("WINHTTP_MIGRATION_NEW");
            foreach (var transfer in ReviewedLifecycleTransfers)
            {
                var original = Type(old.Reader, transfer.Type, architecture, transfer.Namespace);
                string[] originalOwnership = Ownership(old.Reader, original.GetCustomAttributes());
                Assert.Equal(LifecycleAttributes(transfer.Cleanup), originalOwnership);
                var method = Methods(current.Reader, transfer.Namespace, "Apis", architecture)[transfer.Method];
                var parameter = method.GetParameters().Select(current.Reader.GetParameter).Single(value =>
                    transfer.Member == "return" ? value.SequenceNumber == 0 : current.Reader.GetString(value.Name) == transfer.Member);
                Assert.Equal(transfer.Member == "return" ? ParameterAttributes.None : ParameterAttributes.Out, parameter.Attributes);
                Assert.Equal(originalOwnership, Ownership(current.Reader, parameter.GetCustomAttributes()));
                var signature = method.DecodeSignature(Signatures, null);
                string producedType = transfer.Member == "return" ? signature.ReturnType : signature.ParameterTypes[parameter.SequenceNumber - 1];
                if (transfer.Member != "return")
                {
                    Assert.EndsWith("*", producedType);
                    producedType = producedType.Substring(0, producedType.Length - 1);
                }
                var cleanup = Methods(current.Reader, transfer.Namespace, "Apis", architecture)[transfer.Cleanup].DecodeSignature(Signatures, null);
                Assert.Equal(producedType, Assert.Single(cleanup.ParameterTypes));
                foreach (var other in method.GetParameters().Select(current.Reader.GetParameter)
                    .Where(value => value.SequenceNumber != parameter.SequenceNumber))
                    Assert.Empty(Ownership(current.Reader, other.GetCustomAttributes()));
                if (!transfer.Synthetic)
                    Assert.Empty(Ownership(current.Reader, Type(current.Reader, transfer.Type, architecture, transfer.Namespace).GetCustomAttributes()));
            }
            var snapshot = Type(current.Reader, "HPSS", architecture, ProcessSnapshotNamespace);
            Assert.Empty(AttributeValues(current.Reader, snapshot.GetCustomAttributes(), "RAIIFreeAttribute"));
            Assert.Equal(new[]
            {
                MetadataNamespace + ".InvalidHandleValueAttribute:010000000000000000000000",
                MetadataNamespace + ".InvalidHandleValueAttribute:0100FFFFFFFFFFFFFFFF0000",
            }, Ownership(current.Reader, snapshot.GetCustomAttributes()));

            static string[] Ownership(MetadataReader reader, CustomAttributeHandleCollection attributes)
                => attributes.Where(handle => AttributeName(reader, handle) is "RAIIFreeAttribute" or "InvalidHandleValueAttribute")
                    .Select(handle => AttributeTypeName(reader, handle) + ":" +
                        Convert.ToHexString(reader.GetBlobBytes(reader.GetCustomAttribute(handle).Value)))
                    .OrderBy(value => value, StringComparer.Ordinal).ToArray();
        }

        [MigrationTheory]
        [InlineData(1)]
        [InlineData(2)]
        [InlineData(4)]
        public void NativeConstantTransportPreservesExactTypesValuesAndLogicalMembers(int architecture)
        {
            using var old = Open("WINHTTP_MIGRATION_OLD");
            using var current = Open("WINHTTP_MIGRATION_NEW");
            var original = Type(old.Reader, "Apis", architecture, WerNamespace);
            var after = Type(current.Reader, "Apis", architecture, WerNamespace);
            Assert.DoesNotContain(original.GetFields(), handle => old.Reader.GetString(old.Reader.GetFieldDefinition(handle).Name) == WerAlias);
            var alias = after.GetFields().Select(current.Reader.GetFieldDefinition).Single(value => current.Reader.GetString(value.Name) == WerAlias);
            Assert.Equal(FieldAttributes.Public | FieldAttributes.Static | FieldAttributes.Literal | FieldAttributes.HasDefault, alias.Attributes);
            Assert.Equal("UInt32", alias.DecodeSignature(Signatures, null));
            Assert.Equal(-1, alias.GetOffset());
            Assert.True(alias.GetMarshallingDescriptor().IsNil);
            Assert.Empty(alias.GetCustomAttributes());
            var constant = current.Reader.GetConstant(alias.GetDefaultValue());
            Assert.Equal(ConstantTypeCode.UInt32, constant.TypeCode);
            Assert.Equal(new byte[] { 128, 0, 0, 0 }, current.Reader.GetBlobBytes(constant.Value));
            var flags = Type(current.Reader, "WER_SUBMIT_FLAGS", architecture, WerNamespace);
            Assert.Equal(14, flags.GetFields().Select(current.Reader.GetFieldDefinition)
                .Count(value => value.Attributes.HasFlag(FieldAttributes.Literal)));
            Assert.Equal(SnapshotType(old.Reader, Type(old.Reader, "WER_SUBMIT_FLAGS", architecture, WerNamespace)),
                SnapshotType(current.Reader, flags));
            foreach (var image in new[] { old, current })
            {
                var apis = Type(image.Reader, "Apis", architecture, HidNamespace);
                AssertHidConstant(image.Reader, apis.GetFields().Select(image.Reader.GetFieldDefinition)
                    .Single(value => image.Reader.GetString(value.Name) == HidConstant));
                apis = Type(image.Reader, "Apis", architecture, BluetoothNamespace);
                AssertNativeLiteral(image.Reader, apis.GetFields().Select(image.Reader.GetFieldDefinition)
                    .Single(value => image.Reader.GetString(value.Name) == "AF_BTH"),
                    "UInt16", ConstantTypeCode.UInt16, new byte[] { 32, 0 });
            }
            Assert.Equal(SnapshotType(old.Reader, Type(old.Reader, "POWER_PLATFORM_ROLE_VERSION", architecture, PowerNamespace)),
                SnapshotType(current.Reader, Type(current.Reader, "POWER_PLATFORM_ROLE_VERSION", architecture, PowerNamespace)));
        }

        [MigrationTheory]
        [InlineData(1)]
        [InlineData(2)]
        [InlineData(4)]
        public void RestartManagerAssociationsPreserveNativeContracts(int architecture)
        {
            using var old = Open("WINHTTP_MIGRATION_OLD");
            using var current = Open("WINHTTP_MIGRATION_NEW");
            var before = Methods(old.Reader, RestartManagerNamespace, "Apis", architecture);
            var after = Methods(current.Reader, RestartManagerNamespace, "Apis", architecture);
            Assert.Equal(RestartManagerFunctions.OrderBy(value => value), before.Keys.OrderBy(value => value));
            Assert.Equal(before.Keys.OrderBy(value => value), after.Keys.OrderBy(value => value));
            foreach (string name in RestartManagerFunctions)
            {
                var original = before[name];
                var method = after[name];
                var oldSignature = original.DecodeSignature(Signatures, null);
                var newSignature = method.DecodeSignature(Signatures, null);
                Assert.Equal("Windows.Win32.Foundation.WIN32_ERROR", oldSignature.ReturnType);
                Assert.Equal("UInt32", newSignature.ReturnType);
                Assert.Equal(Signature(oldSignature, returnType: "UInt32"), Signature(newSignature));
                Assert.Equal(original.Attributes, method.Attributes);
                Assert.Equal(original.ImplAttributes, method.ImplAttributes);
                Assert.Equal(Import(old.Reader, original), Import(current.Reader, method));
                Assert.Equal(new[] { "windows6.0.6000" },
                    AttributeValues(current.Reader, method.GetCustomAttributes(), "SupportedOSPlatformAttribute"));
                Assert.Equal(AttributeValues(old.Reader, original.GetCustomAttributes(), "SupportedOSPlatformAttribute"),
                    AttributeValues(current.Reader, method.GetCustomAttributes(), "SupportedOSPlatformAttribute"));
                var oldParameters = original.GetParameters().Select(old.Reader.GetParameter).ToArray();
                var parameters = method.GetParameters().Select(current.Reader.GetParameter).ToArray();
                Assert.Equal(oldParameters.Select(value => value.SequenceNumber), parameters.Select(value => value.SequenceNumber));
                Assert.Equal(oldParameters.Select(value => value.Attributes), parameters.Select(value => value.Attributes));
                var result = parameters.Single(value => value.SequenceNumber == 0);
                Assert.Single(result.GetCustomAttributes());
                Assert.Equal(new[] { "WIN32_ERROR" },
                    AttributeValues(current.Reader, result.GetCustomAttributes(), "AssociatedEnumAttribute"));
            }
            foreach (string name in new[] { "RM_PROCESS_INFO", "RM_APP_STATUS", "WIN32_ERROR" })
            {
                string ns = name == "WIN32_ERROR" ? "Windows.Win32.Foundation" : RestartManagerNamespace;
                Assert.Equal(SnapshotType(old.Reader, Type(old.Reader, name, architecture, ns)),
                    SnapshotType(current.Reader, Type(current.Reader, name, architecture, ns)));
            }
        }

        [Fact]
        public void RestartManagerHeaderFactsHaveNoAuthoredFallback()
        {
            string project = Path.Combine(RepositoryRoot, "generation", "WinSDK");
            string[] rows = File.ReadAllLines(Path.Combine(project, "emitter.settings.rsp"));
            string[] osRows = File.ReadAllLines(Path.Combine(project, "supportedOS.rsp"));
            Assert.DoesNotContain(rows, row => row.StartsWith("RM_PROCESS_INFO::AppStatus=", StringComparison.Ordinal));
            foreach (string name in RestartManagerFunctions)
            {
                Assert.DoesNotContain(rows, row => row.StartsWith(name + "::return=", StringComparison.Ordinal));
                Assert.DoesNotContain(osRows, row => row.StartsWith(name + "=", StringComparison.Ordinal));
            }
            Assert.Contains("parse-win32-annotations",
                File.ReadAllText(Path.Combine(project, "Partitions", "RstMgr", "settings.rsp")));
            string patch = File.ReadAllText(Path.Combine(project, "patches", "um", "RestartManager.h.patch"));
            Assert.Single(patch.Split('\n').Where(line => line.TrimEnd('\r') == "+_Win32_SupportedOS_BEGIN_(WindowsVista)"));
            Assert.Single(patch.Split('\n').Where(line => line.TrimEnd('\r') == "+_Win32_SupportedOS_END_()"));
            Assert.DoesNotContain("_Win32_DllImport_", patch);
            Assert.DoesNotContain("_Win32_ImportLibrary_", patch);
        }

        [Fact]
        public void IntegratedEnumAndLifecycleFactsHaveNoSemanticSidecarFallback()
        {
            string project = Path.Combine(RepositoryRoot, "generation", "WinSDK");
            string[] emitter = File.ReadAllLines(Path.Combine(project, "emitter.settings.rsp"));
            foreach (var use in ReviewedEnumUses)
                Assert.DoesNotContain(emitter, row => row.StartsWith(use.Owner + "::" + use.Member + "=", StringComparison.Ordinal));
            using var enums = JsonDocument.Parse(File.ReadAllText(Path.Combine(project, "enums.json")));
            string[] relocated = { "WER_FILE", "WER_SUBMIT_FLAGS", "WER_FAULT_REPORTING",
                "DEVICE_POWER_CAPABILITIES", "FDICREATE_CPU_TYPE", "RM_APP_STATUS" };
            foreach (var item in enums.RootElement.GetProperty("items").EnumerateArray())
            {
                if (item.TryGetProperty("name", out var name))
                    Assert.DoesNotContain(name.GetString(), relocated);
                if (!item.TryGetProperty("uses", out var uses))
                    continue;
                foreach (var use in uses.EnumerateArray())
                {
                    string owner = use.TryGetProperty("method", out var method) ? method.GetString()
                        : use.TryGetProperty("struct", out var record) ? record.GetString() : null;
                    string member = use.TryGetProperty("parameter", out var parameter) ? parameter.GetString()
                        : use.TryGetProperty("field", out var field) ? field.GetString() : null;
                    Assert.DoesNotContain(ReviewedEnumUses, expected => expected.Owner == owner && expected.Member == member);
                }
            }
            using var types = JsonDocument.Parse(File.ReadAllText(Path.Combine(project, "autoTypes.json")));
            foreach (var transfer in ReviewedLifecycleTransfers)
            {
                var matches = types.RootElement.EnumerateArray()
                    .Where(value => value.GetProperty("Name").GetString() == transfer.Type).ToArray();
                if (transfer.Synthetic)
                    Assert.Empty(matches);
                else
                {
                    var type = Assert.Single(matches);
                    Assert.Equal("DECLARE_HANDLE", type.GetProperty("ValueType").GetString());
                    Assert.True(type.GetProperty("NativeTypedef").GetBoolean());
                    Assert.False(type.TryGetProperty("CloseApi", out _));
                    Assert.False(type.TryGetProperty("InvalidHandleValues", out _));
                }
            }
            var snapshot = types.RootElement.EnumerateArray().Single(value => value.GetProperty("Name").GetString() == "HPSS");
            Assert.False(snapshot.TryGetProperty("CloseApi", out _));
            Assert.Equal(new[] { -1, 0 }, snapshot.GetProperty("InvalidHandleValues").EnumerateArray().Select(value => value.GetInt32()));
            Assert.Contains("POWER_PLATFORM_ROLE_VERSION=" + PowerNamespace,
                File.ReadAllLines(Path.Combine(project, "requiredNamespacesForNames.rsp")));
        }

        [MigrationTheory]
        [InlineData(1)]
        [InlineData(2)]
        [InlineData(4)]
        public void NativeMidlRetvalsReachEveryPhysicalArchitectureWithoutChangingCliFlags(int architecture)
        {
            using var old = Open("WINHTTP_MIGRATION_OLD");
            using var current = Open("WINHTTP_MIGRATION_NEW");
            foreach (var use in NativeRetvalUses)
            {
                var before = Methods(old.Reader, use.Namespace, use.Owner, architecture)[use.Method];
                var after = Methods(current.Reader, use.Namespace, use.Owner, architecture)[use.Method];
                Assert.Equal(Signature(before.DecodeSignature(Signatures, null)), Signature(after.DecodeSignature(Signatures, null)));
                var original = before.GetParameters().Select(old.Reader.GetParameter)
                    .Single(value => old.Reader.GetString(value.Name) == use.Parameter);
                var parameter = after.GetParameters().Select(current.Reader.GetParameter)
                    .Single(value => current.Reader.GetString(value.Name) == use.Parameter);
                Assert.Equal(original.Attributes, parameter.Attributes);
                Assert.True(parameter.Attributes.HasFlag(ParameterAttributes.Out));
                Assert.False(parameter.Attributes.HasFlag(ParameterAttributes.Retval));
                Assert.DoesNotContain(original.GetCustomAttributes(), handle => AttributeName(old.Reader, handle) == "RetValAttribute");
                var attribute = Assert.Single(parameter.GetCustomAttributes().Where(handle => AttributeName(current.Reader, handle) == "RetValAttribute"));
                Assert.Equal(new byte[] { 1, 0, 0, 0 }, current.Reader.GetBlobBytes(current.Reader.GetCustomAttribute(attribute).Value));
            }
            this.output.WriteLine($"{NativeRetvalUses.Length} exact native MIDL RetValAttribute additions on architecture {architecture}; CLI parameter flags and signatures unchanged.");
        }

        [MigrationTheory]
        [InlineData(1)]
        [InlineData(2)]
        [InlineData(4)]
        public void ReviewedPreservedResultReplacesOnlyTheLegacySuccessAttribute(int architecture)
        {
            using var old = Open("WINHTTP_MIGRATION_OLD");
            using var current = Open("WINHTTP_MIGRATION_NEW");
            var use = ReviewedPreservedResult;
            var before = Methods(old.Reader, use.Namespace, use.Owner, architecture)[use.Method];
            var after = Methods(current.Reader, use.Namespace, use.Owner, architecture)[use.Method];
            Assert.Equal(Signature(before.DecodeSignature(Signatures, null)), Signature(after.DecodeSignature(Signatures, null)));
            Assert.Equal(before.Attributes, after.Attributes);
            Assert.False(before.ImplAttributes.HasFlag(MethodImplAttributes.PreserveSig));
            Assert.Equal(before.ImplAttributes | MethodImplAttributes.PreserveSig, after.ImplAttributes);
            var attribute = Assert.Single(before.GetCustomAttributes()
                .Where(handle => AttributeName(old.Reader, handle) == "CanReturnMultipleSuccessValuesAttribute"));
            Assert.Equal(new byte[] { 1, 0, 0, 0 }, old.Reader.GetBlobBytes(old.Reader.GetCustomAttribute(attribute).Value));
            Assert.DoesNotContain(after.GetCustomAttributes(), handle => AttributeName(current.Reader, handle)
                is "CanReturnMultipleSuccessValuesAttribute" or "CanReturnErrorsAsSuccessAttribute" or "PreserveSigAttribute");
            this.output.WriteLine($"IEnumEventObject.Reset/{architecture}: reviewed legacy custom attribute removed; " +
                "CLI PreserveSig set; signature and method flags unchanged.");
        }

        [MigrationFact("WINHTTP_MIGRATION_PRIOR_CHECKPOINT")]
        public void QualifiedToolingSynchronizationPreservesTheAcceptedOwningCheckpoint()
        {
            string path = Environment.GetEnvironmentVariable("WINHTTP_MIGRATION_PRIOR_CHECKPOINT");
            Assert.Equal("A8017542A473F502837A488628431B6D11B325C6CABAAA1F674A3C9176711199",
                Convert.ToHexString(SHA256.HashData(File.ReadAllBytes(path))));
            using var accepted = Open("WINHTTP_MIGRATION_PRIOR_CHECKPOINT");
            using var current = Open("WINHTTP_MIGRATION_NEW");
            AssertEveryPhysicalTypeUnchanged(accepted.Reader, current.Reader, "accepted owning checkpoint");
        }

        [MigrationFact("WINHTTP_MIGRATION_ACCEPTED")]
        public void ExpandedPilotPreservesAcceptedScopeFactsApartFromReviewedFieldsAndCanonicalResults()
        {
            string path = Environment.GetEnvironmentVariable("WINHTTP_MIGRATION_ACCEPTED");
            Assert.Equal("A0C321735141D55C98BCD7D048F822AAA0DA1D9434309ABA1782F79C220773BB",
                Convert.ToHexString(SHA256.HashData(File.ReadAllBytes(path))));
            using var accepted = Open("WINHTTP_MIGRATION_ACCEPTED");
            using var current = Open("WINHTTP_MIGRATION_NEW");
            AssertOnlyPropertyStorageFieldsAndCanonicalResults(accepted.Reader, current.Reader, "accepted B9");
        }

        [MigrationFact("WINHTTP_MIGRATION_DIRECT_CONTROL")]
        public void ExpandedPilotPreservesMatchedDirectScopeFactsApartFromReviewedFieldsAndCanonicalResults()
        {
            string path = Environment.GetEnvironmentVariable("WINHTTP_MIGRATION_DIRECT_CONTROL");
            Assert.Equal("AA7B0D71E535787D2A5B623F8B144AEDCF66A464F1E769C7ADC56CF83EA2EE43",
                Convert.ToHexString(SHA256.HashData(File.ReadAllBytes(path))));
            using var direct = Open("WINHTTP_MIGRATION_DIRECT_CONTROL");
            using var current = Open("WINHTTP_MIGRATION_NEW");
            AssertOnlyPropertyStorageFieldsAndCanonicalResults(direct.Reader, current.Reader, "matched canonical-direct control");
        }

        [MigrationTheory]
        [InlineData(1)]
        [InlineData(2)]
        [InlineData(4)]
        public void HeaderFactsReachEveryPhysicalArchitecture(int architecture)
        {
            using var old = Open("WINHTTP_MIGRATION_OLD");
            using var current = Open("WINHTTP_MIGRATION_NEW");
            var oldApis = Methods(old.Reader, WinHttpNamespace, "Apis", architecture);
            var newApis = Methods(current.Reader, WinHttpNamespace, "Apis", architecture);
            Assert.Equal(59, oldApis.Count);
            Assert.Equal(oldApis.Keys.OrderBy(name => name), newApis.Keys.OrderBy(name => name));
            int imports = 0, os = 0, lastError = 0;
            foreach (var entry in oldApis)
            {
                var before = entry.Value;
                var after = newApis[entry.Key];
                Assert.Equal(before.Attributes, after.Attributes);
                Assert.Equal(before.ImplAttributes, after.ImplAttributes);
                Assert.Equal(Import(old.Reader, before), Import(current.Reader, after));
                var import = after.GetImport();
                string module = import.Module.IsNil ? "" : current.Reader.GetString(current.Reader.GetModuleReference(import.Module).Name);
                imports += module == "WINHTTP.dll" ? 1 : 0;
                lastError += import.Attributes.HasFlag(MethodImportAttributes.SetLastError) ? 1 : 0;
                Assert.Equal(AttributeValues(old.Reader, before.GetCustomAttributes(), "SupportedOSPlatformAttribute"),
                    AttributeValues(current.Reader, after.GetCustomAttributes(), "SupportedOSPlatformAttribute"));
                os += AttributeValues(current.Reader, after.GetCustomAttributes(), "SupportedOSPlatformAttribute").Length;
                Assert.Equal(before.DecodeSignature(Signatures, null).ReturnType, after.DecodeSignature(Signatures, null).ReturnType);
                var oldParameters = before.GetParameters().Select(old.Reader.GetParameter).ToDictionary(parameter => parameter.SequenceNumber);
                var newParameters = after.GetParameters().Select(current.Reader.GetParameter).ToDictionary(parameter => parameter.SequenceNumber);
                Assert.Equal(oldParameters.Keys.OrderBy(value => value), newParameters.Keys.OrderBy(value => value));
                foreach (var parameter in oldParameters)
                {
                    Assert.Equal(old.Reader.GetString(parameter.Value.Name), current.Reader.GetString(newParameters[parameter.Key].Name));
                    Assert.Equal(parameter.Value.Attributes, newParameters[parameter.Key].Attributes);
                }
            }

            Assert.Equal(59, imports);
            Assert.Equal(38, os);
            Assert.Equal(28, lastError);
            foreach (var association in Associations)
            {
                if (newApis.TryGetValue(association.Owner, out var method))
                {
                    var parameter = method.GetParameters().Select(current.Reader.GetParameter)
                        .Single(value => current.Reader.GetString(value.Name) == association.Member);
                    Assert.Equal(new[] { association.Enum }, AttributeValues(current.Reader, parameter.GetCustomAttributes(), "AssociatedEnumAttribute"));
                    Assert.Equal(association.Native, method.DecodeSignature(Signatures, null).ParameterTypes[parameter.SequenceNumber - 1]);
                }
                else
                {
                    var record = Type(current.Reader, association.Owner, architecture);
                    var field = record.GetFields().Select(current.Reader.GetFieldDefinition)
                        .Single(value => current.Reader.GetString(value.Name) == association.Member);
                    Assert.Equal(new[] { association.Enum }, AttributeValues(current.Reader, field.GetCustomAttributes(), "AssociatedEnumAttribute"));
                    Assert.Equal(association.Native, field.DecodeSignature(Signatures, null));
                    var oldRecord = Type(old.Reader, association.Owner, architecture);
                    Assert.Equal(oldRecord.GetLayout().Size, record.GetLayout().Size);
                    Assert.Equal(oldRecord.GetLayout().PackingSize, record.GetLayout().PackingSize);
                    Assert.Equal(oldRecord.Attributes, record.Attributes);
                    Assert.Equal(oldRecord.GetFields().Select(old.Reader.GetFieldDefinition).Select(value => old.Reader.GetString(value.Name)),
                        record.GetFields().Select(current.Reader.GetFieldDefinition).Select(value => current.Reader.GetString(value.Name)));
                }
            }

            var buffer = newApis["WinHttpQueryHeadersEx"].GetParameters().Select(current.Reader.GetParameter)
                .Single(parameter => current.Reader.GetString(parameter.Name) == "pBuffer");
            Assert.Single(buffer.GetCustomAttributes().Where(handle => AttributeName(current.Reader, handle) == "ContainsInteriorPointersAttribute"));
            Assert.Contains(buffer.GetCustomAttributes(), handle => AttributeName(current.Reader, handle) == "MemorySizeAttribute");
            Assert.True(buffer.Attributes.HasFlag(ParameterAttributes.Out));
            Assert.True(buffer.Attributes.HasFlag(ParameterAttributes.Optional));
            Assert.Equal("Void*", newApis["WinHttpOpen"].DecodeSignature(Signatures, null).ReturnType);
            Assert.DoesNotContain(current.Reader.TypeDefinitions, handle => FullName(current.Reader, handle) == WinHttpNamespace + ".HINTERNET");
            Assert.DoesNotContain(current.Reader.TypeDefinitions, handle => FullName(current.Reader, handle) == WinHttpNamespace + ".LPWINHTTP_STATUS_CALLBACK");
            Assert.Equal(SnapshotType(old.Reader, Type(old.Reader, "WINHTTP_STATUS_CALLBACK", architecture)),
                SnapshotType(current.Reader, Type(current.Reader, "WINHTTP_STATUS_CALLBACK", architecture)));
        }

        [MigrationTheory]
        [InlineData(1)]
        [InlineData(2)]
        [InlineData(4)]
        public void NetworkHeaderFactsPreserveBindingsFloorsAndOwnedRepresentations(int architecture)
        {
            using var old = Open("WINHTTP_MIGRATION_OLD");
            using var current = Open("WINHTTP_MIGRATION_NEW");
            int imports = 0, floors = 0, lastError = 0;
            foreach (var (suffix, methodCount, floorCount) in new[]
            {
                ("NetBios", 1, 1), ("WNet", 65, 57), ("Dhcp", 210, 191), ("NetShell", 8, 8),
            })
            {
                string ns = "Windows.Win32.NetworkManagement." + suffix;
                var before = Methods(old.Reader, ns, "Apis", architecture);
                var after = Methods(current.Reader, ns, "Apis", architecture);
                Assert.Equal(methodCount, before.Count);
                Assert.Equal(before.Keys.OrderBy(value => value), after.Keys.OrderBy(value => value));
                int ownedFloors = 0;
                foreach (var entry in before)
                {
                    var original = entry.Value;
                    var method = after[entry.Key];
                    Assert.Equal(original.Attributes, method.Attributes);
                    Assert.Equal(original.ImplAttributes, method.ImplAttributes);
                    Assert.Equal(Import(old.Reader, original), Import(current.Reader, method));
                    Assert.Equal(AttributeValues(old.Reader, original.GetCustomAttributes(), "SupportedOSPlatformAttribute"),
                        AttributeValues(current.Reader, method.GetCustomAttributes(), "SupportedOSPlatformAttribute"));
                    ownedFloors += AttributeValues(current.Reader, method.GetCustomAttributes(), "SupportedOSPlatformAttribute").Length;
                    imports++;
                    lastError += method.GetImport().Attributes.HasFlag(MethodImportAttributes.SetLastError) ? 1 : 0;
                    var originalParameters = original.GetParameters().Select(old.Reader.GetParameter)
                        .ToDictionary(value => value.SequenceNumber);
                    var parameters = method.GetParameters().Select(current.Reader.GetParameter)
                        .ToDictionary(value => value.SequenceNumber);
                    Assert.Equal(originalParameters.Keys.OrderBy(value => value), parameters.Keys.OrderBy(value => value));
                    foreach (var parameter in originalParameters)
                    {
                        string name = old.Reader.GetString(parameter.Value.Name);
                        Assert.Equal(name, current.Reader.GetString(parameters[parameter.Key].Name));
                        var direction = NativeDirectionUses.SingleOrDefault(value =>
                            (value.Namespace, value.Owner, value.Method, value.Parameter) == (ns, "Apis", entry.Key, name));
                        if (direction.Parameter == null)
                            Assert.Equal(parameter.Value.Attributes, parameters[parameter.Key].Attributes);
                        else
                        {
                            Assert.Equal(direction.Before, parameter.Value.Attributes);
                            Assert.Equal(direction.After, parameters[parameter.Key].Attributes);
                        }
                    }
                }
                Assert.Equal(floorCount, ownedFloors);
                floors += ownedFloors;
            }
            Assert.Equal(284, imports);
            Assert.Equal(257, floors);
            Assert.Equal(2, lastError);

            var oldApis = Methods(old.Reader, WNetNamespace, "Apis", architecture);
            var apis = Methods(current.Reader, WNetNamespace, "Apis", architecture);
            var uses = ReviewedEnumUses.Where(value => value.Namespace == WNetNamespace).ToArray();
            Assert.Equal(75, uses.Length);
            foreach (var use in uses)
            {
                if (apis.TryGetValue(use.Owner, out var method))
                {
                    var original = oldApis[use.Owner];
                    var beforeSignature = original.DecodeSignature(Signatures, null);
                    var signature = method.DecodeSignature(Signatures, null);
                    var parameter = use.Member == "return"
                        ? method.GetParameters().Select(current.Reader.GetParameter).Single(value => value.SequenceNumber == 0)
                        : method.GetParameters().Select(current.Reader.GetParameter)
                            .Single(value => current.Reader.GetString(value.Name) == use.Member);
                    Assert.Equal(new[] { use.Enum }, AttributeValues(current.Reader, parameter.GetCustomAttributes(), "AssociatedEnumAttribute"));
                    if (use.Member == "return")
                    {
                        Assert.Equal(use.OldType, beforeSignature.ReturnType);
                        Assert.Equal(use.Native, signature.ReturnType);
                        Assert.DoesNotContain(method.GetCustomAttributes(), handle => AttributeName(current.Reader, handle) == "AssociatedEnumAttribute");
                    }
                    else
                    {
                        Assert.Equal(use.OldType, beforeSignature.ParameterTypes[parameter.SequenceNumber - 1]);
                        Assert.Equal(use.Native, signature.ParameterTypes[parameter.SequenceNumber - 1]);
                    }
                }
                else
                {
                    var before = Type(old.Reader, use.Owner, architecture, WNetNamespace);
                    var after = Type(current.Reader, use.Owner, architecture, WNetNamespace);
                    var original = before.GetFields().Select(old.Reader.GetFieldDefinition)
                        .Single(value => old.Reader.GetString(value.Name) == use.Member);
                    var field = after.GetFields().Select(current.Reader.GetFieldDefinition)
                        .Single(value => current.Reader.GetString(value.Name) == use.Member);
                    Assert.Equal(use.OldType, original.DecodeSignature(Signatures, null));
                    Assert.Equal(use.Native, field.DecodeSignature(Signatures, null));
                    Assert.Equal(new[] { use.Enum }, AttributeValues(current.Reader, field.GetCustomAttributes(), "AssociatedEnumAttribute"));
                }
            }

            int members = 0;
            foreach (string name in NetworkLogicalEnums)
            {
                var before = Type(old.Reader, name, architecture, WNetNamespace);
                var after = Type(current.Reader, name, architecture, WNetNamespace);
                Assert.Equal(SnapshotType(old.Reader, before), SnapshotType(current.Reader, after));
                Assert.Equal("System.Enum", FullName(current.Reader, after.BaseType));
                Assert.DoesNotContain(after.GetCustomAttributes(), handle => AttributeName(current.Reader, handle) == "ScopedEnumAttribute");
                var fields = after.GetFields().Select(current.Reader.GetFieldDefinition).ToArray();
                Assert.Equal("UInt32", fields.Single(value => current.Reader.GetString(value.Name) == "value__").DecodeSignature(Signatures, null));
                members += fields.Count(value => !value.GetDefaultValue().IsNil);
            }
            Assert.Equal(12, NetworkLogicalEnums.Length);
            Assert.Equal(55, members);
            this.output.WriteLine($"Network/{architecture}: {imports} exact DLL bindings, {floors} unchanged OS floors, " +
                $"{lastError} last-error imports, {uses.Length} exact associations, and 12 unchanged logical enums/{members} members.");
        }

        [MigrationTheory]
        [InlineData(1)]
        [InlineData(2)]
        [InlineData(4)]
        public void HeaderEnumsPreserveLogicalNamesNativeValuesAndUnderlyingTypes(int architecture)
        {
            using var old = Open("WINHTTP_MIGRATION_OLD");
            using var image = Open("WINHTTP_MIGRATION_NEW");
            var reader = image.Reader;
            Check("WINHTTP_OPEN_REQUEST_FLAGS", "UInt32", true, new Dictionary<string, long>
            {
                ["WINHTTP_FLAG_BYPASS_PROXY_CACHE"] = 0x100,
                ["WINHTTP_FLAG_ESCAPE_DISABLE"] = 0x40,
                ["WINHTTP_FLAG_ESCAPE_DISABLE_QUERY"] = 0x80,
                ["WINHTTP_FLAG_ESCAPE_PERCENT"] = 4,
                ["WINHTTP_FLAG_NULL_CODEPAGE"] = 8,
                ["WINHTTP_FLAG_REFRESH"] = 0x100,
                ["WINHTTP_FLAG_SECURE"] = 0x800000,
            });
            Check("WIN_HTTP_CREATE_URL_FLAGS", "UInt32", false, new Dictionary<string, long>
            {
                ["ICU_ESCAPE"] = 0x80000000,
                ["ICU_REJECT_USERPWD"] = 0x4000,
                ["ICU_DECODE"] = 0x10000000,
            });
            Check("WINHTTP_ACCESS_TYPE", "UInt32", false, new Dictionary<string, long>
            {
                ["WINHTTP_ACCESS_TYPE_NO_PROXY"] = 1,
                ["WINHTTP_ACCESS_TYPE_DEFAULT_PROXY"] = 0,
                ["WINHTTP_ACCESS_TYPE_NAMED_PROXY"] = 3,
                ["WINHTTP_ACCESS_TYPE_AUTOMATIC_PROXY"] = 4,
            });
            Check("WINHTTP_CREDS_AUTHSCHEME", "UInt32", false, new Dictionary<string, long>
            {
                ["WINHTTP_AUTH_SCHEME_BASIC"] = 1,
                ["WINHTTP_AUTH_SCHEME_NTLM"] = 2,
                ["WINHTTP_AUTH_SCHEME_NEGOTIATE"] = 16,
            });
            Check("WINHTTP_INTERNET_SCHEME", "Int32", false, new Dictionary<string, long>
            {
                ["WINHTTP_INTERNET_SCHEME_HTTP"] = 1,
                ["WINHTTP_INTERNET_SCHEME_HTTPS"] = 2,
                ["WINHTTP_INTERNET_SCHEME_FTP"] = 3,
                ["WINHTTP_INTERNET_SCHEME_SOCKS"] = 4,
            });
            var apis = Type(reader, "Apis", architecture);
            foreach (string name in new[] { "INTERNET_SCHEME_HTTP", "INTERNET_SCHEME_HTTPS", "INTERNET_SCHEME_FTP", "INTERNET_SCHEME_SOCKS" })
            {
                Assert.DoesNotContain(apis.GetFields().Select(reader.GetFieldDefinition), value => reader.GetString(value.Name) == name);
                var owners = reader.TypeDefinitions.Where(handle => reader.GetTypeDefinition(handle).GetFields()
                        .Select(reader.GetFieldDefinition).Any(value => reader.GetString(value.Name) == name))
                    .Select(handle => FullName(reader, handle)).Distinct().OrderBy(value => value, StringComparer.Ordinal);
                Assert.Equal(new[] { "Windows.Win32.Networking.WinInet.INTERNET_SCHEME" }, owners);
            }
            foreach (var port in new[] { ("INTERNET_DEFAULT_PORT", 0), ("INTERNET_DEFAULT_HTTP_PORT", 80), ("INTERNET_DEFAULT_HTTPS_PORT", 443) })
            {
                var field = apis.GetFields().Select(reader.GetFieldDefinition).Single(value => reader.GetString(value.Name) == port.Item1);
                Assert.Equal("UInt16", field.DecodeSignature(Signatures, null));
                Assert.Equal(port.Item2, reader.GetBlobReader(reader.GetConstant(field.GetDefaultValue()).Value).ReadUInt16());
            }

            void Check(string name, string underlying, bool flags, Dictionary<string, long> expected)
            {
                var type = Type(reader, name, architecture);
                Assert.Equal(SnapshotType(old.Reader, Type(old.Reader, name, architecture)), SnapshotType(reader, type));
                Assert.Equal("System.Enum", FullName(reader, type.BaseType));
                Assert.Equal(flags, type.GetCustomAttributes().Any(handle => AttributeName(reader, handle) == "FlagsAttribute"));
                Assert.DoesNotContain(type.GetCustomAttributes(), handle => AttributeName(reader, handle) == "ScopedEnumAttribute");
                var fields = type.GetFields().Select(reader.GetFieldDefinition).ToArray();
                Assert.Equal(underlying, fields.Single(field => reader.GetString(field.Name) == "value__").DecodeSignature(Signatures, null));
                var values = fields.Where(field => !field.GetDefaultValue().IsNil).ToDictionary(field => reader.GetString(field.Name), field =>
                {
                    var constant = reader.GetConstant(field.GetDefaultValue());
                    var blob = reader.GetBlobReader(constant.Value);
                    return constant.TypeCode == ConstantTypeCode.UInt32 ? (long)blob.ReadUInt32() : blob.ReadInt32();
                });
                Assert.Equal(expected.OrderBy(value => value.Key), values.OrderBy(value => value.Key));
            }
        }

        [MigrationFact]
        public void SharedHeaderAndUnmigratedWinInetMetadataStayUnchanged()
        {
            using var old = Open("WINHTTP_MIGRATION_OLD");
            using var current = Open("WINHTTP_MIGRATION_NEW");
            foreach (string ns in new[] { "Windows.Win32.Networking.HttpServer", "Windows.Win32.Networking.WinInet" })
            {
                var before = SnapshotNamespace(old.Reader, ns);
                var after = SnapshotNamespace(current.Reader, ns);
                Assert.NotEmpty(before);
                Assert.Equal(before, after);
            }
        }

        [MigrationFact]
        public void EmittedWinHttpScopeUsesSdkBindingsWithoutAuthoredSemanticFallback()
        {
            using var old = Open("WINHTTP_MIGRATION_OLD");
            string root = RepositoryRoot;
            var names = Methods(old.Reader, WinHttpNamespace, "Apis", 2).Keys.ToHashSet(StringComparer.Ordinal);
            var bindings = File.ReadLines(Path.Combine(root, "generation", "WinSDK", "libMappings.rsp"))
                .Where(line => line.Contains('=')).Select(line => line.Split('='))
                .ToDictionary(parts => parts[0], parts => parts[1], StringComparer.Ordinal);
            Assert.Equal(59, names.Count);
            foreach (string name in names)
                Assert.Equal("WINHTTP.dll", bindings[name]);
            foreach (string file in new[] { "libMappingsManual.rsp", "supportedOS.rsp", "WithSetLastError.rsp", "emitter.settings.rsp" })
            {
                foreach (string line in File.ReadLines(Path.Combine(root, "generation", "WinSDK", file)))
                {
                    string target = line.Split('=')[0].Split(new[] { "::" }, StringSplitOptions.None)[0];
                    Assert.DoesNotContain(target, names);
                }
            }

            using var enums = JsonDocument.Parse(File.ReadAllText(Path.Combine(root, "generation", "WinSDK", "enums.json")));
            var definitions = Associations.Select(value => value.Enum).ToHashSet(StringComparer.Ordinal);
            foreach (var item in enums.RootElement.GetProperty("items").EnumerateArray())
            {
                if (item.TryGetProperty("name", out var name))
                    Assert.DoesNotContain(name.GetString(), definitions);
                if (item.TryGetProperty("uses", out var uses))
                {
                    foreach (var use in uses.EnumerateArray())
                    {
                        if (use.TryGetProperty("method", out var method))
                            Assert.DoesNotContain(method.GetString(), names);
                        if (use.TryGetProperty("struct", out var record))
                            Assert.DoesNotContain(record.GetString(), Associations.Select(value => value.Owner));
                    }
                }
            }

            string constants = File.ReadAllText(Path.Combine(root, "generation", "WinSDK", "ConstantsScraper.settings.rsp"));
            foreach (string name in new[] { "INTERNET_DEFAULT_PORT", "INTERNET_DEFAULT_HTTP_PORT", "INTERNET_DEFAULT_HTTPS_PORT",
                "INTERNET_SCHEME_HTTP", "INTERNET_SCHEME_HTTPS", "INTERNET_SCHEME_FTP", "INTERNET_SCHEME_SOCKS" })
                Assert.DoesNotContain(name, constants);
            Assert.DoesNotContain("LPWINHTTP_STATUS_CALLBACK",
                File.ReadAllText(Path.Combine(root, "generation", "WinSDK", "Partitions", "WinHttp", "settings.rsp")));
        }

        [MigrationFact]
        public void AdditionalEmittedOwnersHaveOnlyTheExplicitUnmigratedResiduals()
        {
            using var old = Open("WINHTTP_MIGRATION_OLD");
            var emitted = old.Reader.MethodDefinitions.Select(old.Reader.GetMethodDefinition)
                .Select(method => old.Reader.GetString(method.Name)).ToHashSet(StringComparer.Ordinal);
            Assert.All(AdditionalOwnedMethods, name => Assert.Contains(name, emitted));
            var emittedTypes = old.Reader.TypeDefinitions.Select(old.Reader.GetTypeDefinition)
                .Select(type => old.Reader.GetString(type.Name)).ToHashSet(StringComparer.Ordinal);
            Assert.All(AdditionalOwnedTypes, name => Assert.Contains(name, emittedTypes));
            Assert.DoesNotContain("VerifierIsPerUserSettingsEnabled", emitted);
            string project = Path.Combine(RepositoryRoot, "generation", "WinSDK");
            foreach (string file in new[] { "libMappingsManual.rsp", "scraper.settings.rsp", "supportedOS.rsp",
                "WithSetLastError.rsp", "emitter.settings.rsp", "ConstantsScraper.settings.rsp" })
            {
                foreach (string line in File.ReadLines(Path.Combine(project, file)))
                {
                    if (file == "emitter.settings.rsp" && line == HeldDhcpArrayRow)
                        continue;
                    if (file == "supportedOS.rsp" && SourceBlockedAvailability.Any(fact =>
                        line == fact.Target + "=SupportedOSPlatform(\"" + fact.OS + "\")"))
                        continue;
                    if (file == "emitter.settings.rsp" && SourceBlockedAssociations.Contains(line, StringComparer.Ordinal))
                        continue;
                    string target = line.Split('=')[0].Split(new[] { "::" }, StringSplitOptions.None)[0];
                    Assert.DoesNotContain(target, AdditionalOwnedMethods);
                    Assert.DoesNotContain(target, AdditionalLogicalEnums);
                    Assert.DoesNotContain(target, AdditionalOwnedTypes);
                }
            }
            Assert.Single(File.ReadLines(Path.Combine(project, "emitter.settings.rsp")).Where(line => line == HeldDhcpArrayRow));
            using var enums = JsonDocument.Parse(File.ReadAllText(Path.Combine(project, "enums.json")));
            foreach (var item in enums.RootElement.GetProperty("items").EnumerateArray())
            {
                if (item.TryGetProperty("name", out var name))
                    Assert.DoesNotContain(name.GetString(), AdditionalLogicalEnums);
                if (item.TryGetProperty("uses", out var uses))
                {
                    foreach (var use in uses.EnumerateArray())
                    {
                        if (use.TryGetProperty("method", out var method))
                        {
                            string owner = method.GetString().Split(new[] { "::" }, StringSplitOptions.None)[0];
                            Assert.DoesNotContain(owner, AdditionalOwnedMethods);
                            Assert.DoesNotContain(owner, AdditionalOwnedTypes);
                        }
                        if (use.TryGetProperty("struct", out var record))
                            Assert.DoesNotContain(record.GetString(), AdditionalOwnedTypes);
                    }
                }
            }
            string bindings = File.ReadAllText(Path.Combine(project, "libMappings.rsp"));
            Assert.Contains("CeipIsOptedIn=KERNEL32.dll", bindings);
            Assert.DoesNotContain("VerifierEnumerateResource=", bindings);
            Assert.Contains("VerifierIsPerUserSettingsEnabled=SupportedOSPlatform(\"windows6.0.6000\")",
                File.ReadAllText(Path.Combine(project, "supportedOS.rsp")));
            foreach (string name in new[] { "TimeProvOpen", "TimeProvCommand", "TimeProvClose" })
            {
                Assert.DoesNotContain(name, emitted);
                Assert.Contains(name + "=SupportedOSPlatform(\"windows5.1.2600\")",
                    File.ReadAllText(Path.Combine(project, "supportedOS.rsp")));
            }
            foreach (string partition in new[] { "CEIP", "ApplicationVerifier", "MagApi", "PsApi1", "Time", "Ual",
                "ToolHelp", "UpdateAssessment", "Wsl", "Xinput", "SecurityCenter", "WinSat",
                "Wcm", "InputRadial", "WinContacts", "WinLocation", "Rdc", "Nla", "Com.CallObj", "Com.Events",
                "NetBios", "Wnet", "Dhcp", "NetShell" })
                Assert.Contains("parse-win32-annotations", File.ReadAllText(Path.Combine(project, "Partitions", partition, "settings.rsp")));
            Assert.DoesNotContain("--with-librarypath", File.ReadAllText(Path.Combine(project, "Partitions", "Wsl", "settings.rsp")));
            foreach (string partition in new[] { "Base", "PsApi2", "HttpServer",
                "ComOle", "WindowsConnectionManager", "TransactionServer", "Enstor" })
                Assert.DoesNotContain("parse-win32-annotations", File.ReadAllText(Path.Combine(project, "Partitions", partition, "settings.rsp")));
        }

        [Theory]
        [InlineData("valid")]
        [InlineData("wrong-value")]
        [InlineData("wrong-type")]
        [InlineData("wrong-flags")]
        [InlineData("wrong-other-field-order")]
        [InlineData("wrong-other-field-type")]
        [InlineData("wrong-namespace")]
        [InlineData("incomplete-old")]
        [InlineData("instance-old")]
        public void NativeConstantOrderNormalizationMovesOnlyTheExactStaticLiteral(string mutation)
        {
            using var old = Fixture(false, mutation);
            using var current = Fixture(true, mutation);
            var before = old.GetMetadataReader();
            var after = current.GetMetadataReader();
            var original = before.GetTypeDefinition(MetadataTokens.TypeDefinitionHandle(2));
            if (mutation is "incomplete-old" or "instance-old")
            {
                Assert.ThrowsAny<XunitException>(() => SnapshotType(before, original, normalizeReviewedChanges: true));
                return;
            }
            var used = new HashSet<string>(StringComparer.Ordinal);
            string expected = SnapshotType(before, original, normalizeReviewedChanges: true, usedNativeConstantSites: used);
            string actual = SnapshotType(after, after.GetTypeDefinition(MetadataTokens.TypeDefinitionHandle(2)));
            if (mutation == "valid")
            {
                Assert.Equal(expected, actual);
                Assert.Equal(new[] { BluetoothNamespace + ".Apis.AF_BTH" }, used);
            }
            else
                Assert.NotEqual(expected, actual);
            if (mutation == "wrong-namespace")
                Assert.Empty(used);

            static MetadataReaderProvider Fixture(bool native, string mutation)
            {
                var metadata = new MetadataBuilder();
                metadata.AddModule(0, metadata.GetOrAddString("Constants.winmd"), metadata.GetOrAddGuid(Guid.NewGuid()), default, default);
                metadata.AddTypeDefinition(TypeAttributes.NotPublic, default, metadata.GetOrAddString("<Module>"), default,
                    MetadataTokens.FieldDefinitionHandle(1), MetadataTokens.MethodDefinitionHandle(1));
                metadata.AddTypeDefinition(TypeAttributes.Public | TypeAttributes.Abstract | TypeAttributes.Sealed,
                    metadata.GetOrAddString(mutation == "wrong-namespace" ? BluetoothNamespace + ".Other" : BluetoothNamespace),
                    metadata.GetOrAddString("Apis"), default, MetadataTokens.FieldDefinitionHandle(1), MetadataTokens.MethodDefinitionHandle(1));
                string[] names = native
                    ? mutation == "wrong-other-field-order" ? new[] { "One", "Three", "Two", "AF_BTH" } : new[] { "One", "Two", "Three", "AF_BTH" }
                    : new[] { "One", "AF_BTH", "Two", "Three" };
                foreach (string name in names)
                {
                    var signature = new BlobBuilder();
                    var encoder = new BlobEncoder(signature).FieldSignature();
                    var attributes = FieldAttributes.Public | FieldAttributes.Static;
                    bool wide = native && mutation == "wrong-type";
                    if (name == "AF_BTH")
                    {
                        if (wide) encoder.UInt32(); else encoder.UInt16();
                        attributes |= FieldAttributes.Literal | FieldAttributes.HasDefault;
                        if (native && mutation == "wrong-flags")
                            attributes &= ~FieldAttributes.Literal;
                        if (!native && mutation == "instance-old")
                            attributes &= ~FieldAttributes.Static;
                    }
                    else if (native && mutation == "wrong-other-field-type" && name == "Two")
                        encoder.Int64();
                    else
                        encoder.Int32();
                    var field = metadata.AddFieldDefinition(attributes, metadata.GetOrAddString(name), metadata.GetOrAddBlob(signature));
                    if (name == "AF_BTH")
                    {
                        if (wide)
                            metadata.AddConstant(field, 32U);
                        else
                            metadata.AddConstant(field, (ushort)((native && mutation == "wrong-value") || (!native && mutation == "incomplete-old") ? 33 : 32));
                    }
                }
                var image = new BlobBuilder();
                new MetadataRootBuilder(metadata).Serialize(image, 0, 0);
                return MetadataReaderProvider.FromMetadataImage(image.ToImmutableArray());
            }
        }

        [Theory]
        [InlineData("valid")]
        [InlineData("missing-zero")]
        [InlineData("missing-minus-one")]
        [InlineData("duplicate-invalid")]
        [InlineData("wrong-free")]
        [InlineData("wrong-target")]
        [InlineData("borrowed-input")]
        [InlineData("missing-out")]
        [InlineData("retained-type-ownership")]
        [InlineData("wrong-native-type")]
        [InlineData("incomplete-old")]
        public void LifecycleNormalizationRequiresCompleteContractsAndExactTargets(string mutation)
        {
            using var old = Fixture(false, mutation);
            using var current = Fixture(true, mutation);
            var before = old.GetMetadataReader();
            var after = current.GetMetadataReader();
            var original = before.GetTypeDefinition(MetadataTokens.TypeDefinitionHandle(2));
            if (mutation == "incomplete-old")
            {
                Assert.ThrowsAny<XunitException>(() => SnapshotType(before, original, normalizeReviewedChanges: true));
                return;
            }
            var expected = new[] { 2, 3 }.Select(row => SnapshotType(before,
                before.GetTypeDefinition(MetadataTokens.TypeDefinitionHandle(row)), normalizeReviewedChanges: true)).ToArray();
            var actual = new[] { 2, 3 }.Select(row => SnapshotType(after,
                after.GetTypeDefinition(MetadataTokens.TypeDefinitionHandle(row)))).ToArray();
            if (mutation == "valid")
                Assert.Equal(expected, actual);
            else
                Assert.NotEqual(expected, actual);

            static MetadataReaderProvider Fixture(bool native, string mutation)
            {
                var metadata = new MetadataBuilder();
                metadata.AddModule(0, metadata.GetOrAddString("Ownership.winmd"), metadata.GetOrAddGuid(Guid.NewGuid()), default, default);
                var runtime = metadata.AddAssemblyReference(metadata.GetOrAddString("System.Runtime"),
                    new Version(10, 0), default, default, 0, default);
                var valueType = metadata.AddTypeReference(runtime, metadata.GetOrAddString("System"), metadata.GetOrAddString("ValueType"));
                metadata.AddTypeDefinition(TypeAttributes.NotPublic, default, metadata.GetOrAddString("<Module>"), default,
                    MetadataTokens.FieldDefinitionHandle(1), MetadataTokens.MethodDefinitionHandle(1));
                var handle = metadata.AddTypeDefinition(TypeAttributes.Public | TypeAttributes.SequentialLayout | TypeAttributes.Sealed,
                    metadata.GetOrAddString(WebSocketNamespace), metadata.GetOrAddString("WEB_SOCKET_HANDLE"), valueType,
                    MetadataTokens.FieldDefinitionHandle(1), MetadataTokens.MethodDefinitionHandle(1));
                var field = new BlobBuilder();
                new BlobEncoder(field).FieldSignature().IntPtr();
                metadata.AddFieldDefinition(FieldAttributes.Public, metadata.GetOrAddString("Value"), metadata.GetOrAddBlob(field));
                if (!native || mutation == "retained-type-ownership")
                    AddOwnership(handle, "WebSocketDeleteHandle", includeZero: mutation != "incomplete-old");
                metadata.AddTypeDefinition(TypeAttributes.Public | TypeAttributes.Abstract | TypeAttributes.Sealed,
                    metadata.GetOrAddString(WebSocketNamespace), metadata.GetOrAddString("Apis"), default,
                    MetadataTokens.FieldDefinitionHandle(2), MetadataTokens.MethodDefinitionHandle(1));
                var signature = new BlobBuilder();
                new BlobEncoder(signature).MethodSignature().Parameters(3, result => result.Type().Int32(), parameters =>
                {
                    parameters.AddParameter().Type().IntPtr();
                    parameters.AddParameter().Type().UInt32();
                    var output = parameters.AddParameter().Type();
                    if (native && mutation == "wrong-native-type")
                        output.IntPtr();
                    else
                        output.Pointer().Type(handle, isValueType: true);
                });
                metadata.AddMethodDefinition(MethodAttributes.Public | MethodAttributes.Static, MethodImplAttributes.IL,
                    metadata.GetOrAddString("WebSocketCreateClientHandle"), metadata.GetOrAddBlob(signature), -1,
                    MetadataTokens.ParameterHandle(1));
                metadata.AddParameter(ParameterAttributes.None, default, 0);
                var input = metadata.AddParameter(ParameterAttributes.In, metadata.GetOrAddString("pProperties"), 1);
                metadata.AddParameter(ParameterAttributes.In, metadata.GetOrAddString("ulPropertyCount"), 2);
                var result = metadata.AddParameter(native && mutation == "missing-out" ? ParameterAttributes.None : ParameterAttributes.Out,
                    metadata.GetOrAddString("phWebSocket"), 3);
                if (native)
                {
                    var target = mutation == "wrong-target" ? input : result;
                    AddOwnership(target, mutation == "wrong-free" ? "OtherFree" : "WebSocketDeleteHandle",
                        includeZero: mutation != "missing-zero", includeMinusOne: mutation != "missing-minus-one");
                    if (mutation == "borrowed-input")
                        AddOwnership(input, "WebSocketDeleteHandle");
                    if (mutation == "duplicate-invalid")
                        AddAttribute(result, "InvalidHandleValueAttribute", 0L);
                }
                var image = new BlobBuilder();
                new MetadataRootBuilder(metadata).Serialize(image, 0, 0);
                return MetadataReaderProvider.FromMetadataImage(image.ToImmutableArray());

                void AddOwnership(EntityHandle target, string cleanup, bool includeZero = true, bool includeMinusOne = true)
                {
                    AddAttribute(target, "RAIIFreeAttribute", cleanup);
                    if (includeMinusOne)
                        AddAttribute(target, "InvalidHandleValueAttribute", -1L);
                    if (includeZero)
                        AddAttribute(target, "InvalidHandleValueAttribute", 0L);
                }

                void AddAttribute(EntityHandle target, string name, object value)
                {
                    var attribute = metadata.AddTypeReference(MetadataTokens.EntityHandle(1),
                        metadata.GetOrAddString(MetadataNamespace), metadata.GetOrAddString(name));
                    var signature = new BlobBuilder();
                    new BlobEncoder(signature).MethodSignature(isInstanceMethod: true).Parameters(1, result => result.Void(), parameters =>
                    {
                        var type = parameters.AddParameter().Type();
                        if (value is string) type.String(); else type.Int64();
                    });
                    var constructor = metadata.AddMemberReference(attribute, metadata.GetOrAddString(".ctor"), metadata.GetOrAddBlob(signature));
                    var bytes = new BlobBuilder();
                    bytes.WriteUInt16(1);
                    if (value is string text) bytes.WriteSerializedString(text); else bytes.WriteInt64((long)value);
                    bytes.WriteUInt16(0);
                    metadata.AddCustomAttribute(target, constructor, metadata.GetOrAddBlob(bytes));
                }
            }
        }

        [Theory]
        [InlineData("valid")]
        [InlineData("wrong-enum")]
        [InlineData("wrong-target")]
        [InlineData("wrong-native-type")]
        [InlineData("wrong-old-enum-namespace")]
        [InlineData("missing-return-parameter")]
        [InlineData("changed-import")]
        public void ReturnAssociationNormalizationRequiresExactMetadata(string mutation)
        {
            using var old = Fixture(native: false, mutation);
            using var current = Fixture(native: true, mutation);
            var before = old.GetMetadataReader();
            var after = current.GetMetadataReader();
            var used = new HashSet<string>(StringComparer.Ordinal);
            var original = before.GetTypeDefinition(MetadataTokens.TypeDefinitionHandle(3));
            if (mutation == "wrong-old-enum-namespace")
            {
                Assert.ThrowsAny<XunitException>(() => SnapshotType(before, original,
                    normalizeReviewedChanges: true, usedEnumSites: used));
                Assert.Empty(used);
                return;
            }
            string expected = SnapshotType(before, original, normalizeReviewedChanges: true, usedEnumSites: used);
            string actual = SnapshotType(after, after.GetTypeDefinition(MetadataTokens.TypeDefinitionHandle(3)));
            Assert.Equal(new[] { WNetNamespace + ".WNetAddConnectionA::return" }, used);
            if (mutation == "valid")
                Assert.Equal(expected, actual);
            else
                Assert.NotEqual(expected, actual);

            static MetadataReaderProvider Fixture(bool native, string mutation)
            {
                var metadata = new MetadataBuilder();
                metadata.AddModule(0, metadata.GetOrAddString("Return.winmd"), metadata.GetOrAddGuid(Guid.NewGuid()), default, default);
                var runtime = metadata.AddAssemblyReference(metadata.GetOrAddString("System.Runtime"),
                    new Version(10, 0), default, default, 0, default);
                var enumBase = metadata.AddTypeReference(runtime, metadata.GetOrAddString("System"), metadata.GetOrAddString("Enum"));
                metadata.AddTypeDefinition(TypeAttributes.NotPublic, default, metadata.GetOrAddString("<Module>"), default,
                    MetadataTokens.FieldDefinitionHandle(1), MetadataTokens.MethodDefinitionHandle(1));
                var enumeration = metadata.AddTypeDefinition(TypeAttributes.Public,
                    metadata.GetOrAddString(!native && mutation == "wrong-old-enum-namespace" ? WNetNamespace : "Windows.Win32.Foundation"),
                    metadata.GetOrAddString("WIN32_ERROR"), enumBase,
                    MetadataTokens.FieldDefinitionHandle(1), MetadataTokens.MethodDefinitionHandle(1));
                var fieldSignature = new BlobBuilder();
                new BlobEncoder(fieldSignature).FieldSignature().UInt32();
                metadata.AddFieldDefinition(FieldAttributes.Public | FieldAttributes.SpecialName | FieldAttributes.RTSpecialName,
                    metadata.GetOrAddString("value__"), metadata.GetOrAddBlob(fieldSignature));
                metadata.AddTypeDefinition(TypeAttributes.Public | TypeAttributes.Abstract | TypeAttributes.Sealed,
                    metadata.GetOrAddString(WNetNamespace), metadata.GetOrAddString("Apis"), default,
                    MetadataTokens.FieldDefinitionHandle(2), MetadataTokens.MethodDefinitionHandle(1));
                var signature = new BlobBuilder();
                new BlobEncoder(signature).MethodSignature().Parameters(0, result =>
                {
                    var type = result.Type();
                    if (!native)
                        type.Type(enumeration, isValueType: true);
                    else if (mutation == "wrong-native-type")
                        type.Int32();
                    else
                        type.UInt32();
                }, parameters => { });
                var method = metadata.AddMethodDefinition(MethodAttributes.Public | MethodAttributes.Static | MethodAttributes.PinvokeImpl,
                    MethodImplAttributes.PreserveSig, metadata.GetOrAddString("WNetAddConnectionA"), metadata.GetOrAddBlob(signature), -1,
                    MetadataTokens.ParameterHandle(1));
                var module = metadata.AddModuleReference(metadata.GetOrAddString(native && mutation == "changed-import" ? "other.dll" : "MPR.dll"));
                metadata.AddMethodImport(method, MethodImportAttributes.CallingConventionWinApi, metadata.GetOrAddString("WNetAddConnectionA"), module);
                if (!native || mutation != "missing-return-parameter")
                {
                    var parameter = metadata.AddParameter(0, metadata.GetOrAddString(""), 0);
                    if (native)
                    {
                        var attribute = metadata.AddTypeReference(MetadataTokens.EntityHandle(1),
                            metadata.GetOrAddString(MetadataNamespace), metadata.GetOrAddString("AssociatedEnumAttribute"));
                        var constructorSignature = new BlobBuilder();
                        new BlobEncoder(constructorSignature).MethodSignature(isInstanceMethod: true).Parameters(1,
                            result => result.Void(), parameters => parameters.AddParameter().Type().String());
                        var constructor = metadata.AddMemberReference(attribute, metadata.GetOrAddString(".ctor"),
                            metadata.GetOrAddBlob(constructorSignature));
                        var value = new BlobBuilder();
                        value.WriteUInt16(1);
                        value.WriteSerializedString(mutation == "wrong-enum" ? "NET_CONNECT_FLAGS" : "WIN32_ERROR");
                        value.WriteUInt16(0);
                        metadata.AddCustomAttribute(mutation == "wrong-target" ? (EntityHandle)method : parameter,
                            constructor, metadata.GetOrAddBlob(value));
                    }
                }
                var image = new BlobBuilder();
                new MetadataRootBuilder(metadata).Serialize(image, 0, 0);
                return MetadataReaderProvider.FromMetadataImage(image.ToImmutableArray());
            }
        }

        [Theory]
        [InlineData("valid")]
        [InlineData("old-signed-storage")]
        [InlineData("old-wrong-all")]
        [InlineData("old-reordered-members")]
        [InlineData("old-missing-flags")]
        [InlineData("new-unsigned-storage")]
        [InlineData("new-unsigned-constants")]
        [InlineData("new-wrong-all")]
        [InlineData("new-reordered-members")]
        [InlineData("new-missing-member")]
        [InlineData("new-missing-flags")]
        [InlineData("unrelated-enum")]
        public void ApprovedDwmStorageNormalizationRequiresTheExactOldEnumAndNewBits(string mutation)
        {
            using var old = Fixture(native: false);
            using var current = Fixture(native: true);
            var before = old.GetMetadataReader();
            var after = current.GetMetadataReader();
            var used = new HashSet<string>(StringComparer.Ordinal);
            var original = before.GetTypeDefinition(MetadataTokens.TypeDefinitionHandle(2));
            if (mutation.StartsWith("old-", StringComparison.Ordinal))
            {
                Assert.ThrowsAny<XunitException>(() => SnapshotType(before, original,
                    normalizeReviewedChanges: true, usedEnumStorageSites: used));
                Assert.Empty(used);
                return;
            }
            string expected = SnapshotType(before, original, normalizeReviewedChanges: true, usedEnumStorageSites: used);
            string actual = SnapshotType(after, after.GetTypeDefinition(MetadataTokens.TypeDefinitionHandle(2)));
            Assert.Equal(mutation == "valid", expected == actual);
            if (mutation == "unrelated-enum")
                Assert.Empty(used);
            else
                Assert.Equal(new[] { DwmNamespace + ".DWM_SHOWCONTACT" }, used);

            MetadataReaderProvider Fixture(bool native)
            {
                var metadata = new MetadataBuilder();
                metadata.AddModule(0, metadata.GetOrAddString("DwmContact.winmd"), metadata.GetOrAddGuid(Guid.NewGuid()), default, default);
                var runtime = metadata.AddAssemblyReference(metadata.GetOrAddString("System.Runtime"),
                    new Version(10, 0), default, default, 0, default);
                var enumType = metadata.AddTypeReference(runtime, metadata.GetOrAddString("System"), metadata.GetOrAddString("Enum"));
                metadata.AddTypeDefinition(TypeAttributes.NotPublic, default, metadata.GetOrAddString("<Module>"), default,
                    MetadataTokens.FieldDefinitionHandle(1), MetadataTokens.MethodDefinitionHandle(1));
                var type = metadata.AddTypeDefinition(TypeAttributes.Public | TypeAttributes.Sealed,
                    metadata.GetOrAddString(DwmNamespace),
                    metadata.GetOrAddString(mutation == "unrelated-enum" ? "OTHER_DWM_SHOWCONTACT" : "DWM_SHOWCONTACT"), enumType,
                    MetadataTokens.FieldDefinitionHandle(1), MetadataTokens.MethodDefinitionHandle(1));
                if (mutation != (native ? "new-missing-flags" : "old-missing-flags"))
                {
                    var flags = metadata.AddTypeReference(runtime, metadata.GetOrAddString("System"), metadata.GetOrAddString("FlagsAttribute"));
                    var signature = new BlobBuilder();
                    new BlobEncoder(signature).MethodSignature(isInstanceMethod: true).Parameters(0, result => result.Void(), _ => { });
                    var constructor = metadata.AddMemberReference(flags, metadata.GetOrAddString(".ctor"), metadata.GetOrAddBlob(signature));
                    metadata.AddCustomAttribute(type, constructor, metadata.GetOrAddBlob(new byte[] { 1, 0, 0, 0 }));
                }
                var storage = new BlobBuilder();
                var storageType = new BlobEncoder(storage).FieldSignature();
                if (native && mutation != "new-unsigned-storage" || !native && mutation == "old-signed-storage")
                    storageType.Int32();
                else
                    storageType.UInt32();
                metadata.AddFieldDefinition(FieldAttributes.Public | FieldAttributes.SpecialName | FieldAttributes.RTSpecialName,
                    metadata.GetOrAddString("value__"), metadata.GetOrAddBlob(storage));
                var members = DwmContactMembers.ToArray();
                if (mutation == (native ? "new-reordered-members" : "old-reordered-members"))
                    (members[0], members[1]) = (members[1], members[0]);
                foreach (var member in members)
                {
                    if (native && mutation == "new-missing-member" && member.Name == "DWMSC_NONE")
                        continue;
                    uint bits = member.Name == "DWMSC_ALL" && mutation == (native ? "new-wrong-all" : "old-wrong-all")
                        ? uint.MaxValue - 1 : member.Bits;
                    var signature = new BlobBuilder();
                    new BlobEncoder(signature).FieldSignature().Type(type, isValueType: true);
                    var field = metadata.AddFieldDefinition(FieldAttributes.Public | FieldAttributes.Static | FieldAttributes.Literal | FieldAttributes.HasDefault,
                        metadata.GetOrAddString(member.Name), metadata.GetOrAddBlob(signature));
                    metadata.AddConstant(field, native && mutation != "new-unsigned-constants" ? unchecked((int)bits) : (object)bits);
                }
                var image = new BlobBuilder();
                new MetadataRootBuilder(metadata).Serialize(image, 0, 0);
                return MetadataReaderProvider.FromMetadataImage(image.ToImmutableArray());
            }
        }

        [Theory]
        [InlineData(3, true)]
        [InlineData(2, false)]
        [InlineData(1, false)]
        [InlineData(19, false)]
        [InlineData(11, false)]
        public void NativeDirectionNormalizationChangesOnlyTheExactSdkFlags(int flags, bool equal)
        {
            using var old = Fixture(ParameterAttributes.Out);
            using var current = Fixture((ParameterAttributes)flags);
            var before = old.GetMetadataReader();
            var after = current.GetMetadataReader();
            var used = new HashSet<string>(StringComparer.Ordinal);
            string expected = SnapshotType(before, before.GetTypeDefinition(MetadataTokens.TypeDefinitionHandle(2)),
                normalizeReviewedChanges: true, usedNativeDirectionSites: used);
            string actual = SnapshotType(after, after.GetTypeDefinition(MetadataTokens.TypeDefinitionHandle(2)));
            Assert.Equal(new[] { DhcpNamespace + ".Apis.DhcpEnumSubnets.EnumInfo" }, used);
            Assert.Equal(equal, expected == actual);

            static MetadataReaderProvider Fixture(ParameterAttributes direction)
            {
                var metadata = new MetadataBuilder();
                metadata.AddModule(0, metadata.GetOrAddString("Direction.winmd"), metadata.GetOrAddGuid(Guid.NewGuid()), default, default);
                metadata.AddTypeDefinition(TypeAttributes.NotPublic, default, metadata.GetOrAddString("<Module>"), default,
                    MetadataTokens.FieldDefinitionHandle(1), MetadataTokens.MethodDefinitionHandle(1));
                metadata.AddTypeDefinition(TypeAttributes.Public | TypeAttributes.Abstract | TypeAttributes.Sealed,
                    metadata.GetOrAddString(DhcpNamespace), metadata.GetOrAddString("Apis"), default,
                    MetadataTokens.FieldDefinitionHandle(1), MetadataTokens.MethodDefinitionHandle(1));
                var signature = new BlobBuilder();
                new BlobEncoder(signature).MethodSignature().Parameters(6, result => result.Type().UInt32(), parameters =>
                {
                    for (int index = 0; index < 6; index++)
                        parameters.AddParameter().Type().UInt32();
                });
                var method = metadata.AddMethodDefinition(MethodAttributes.Public | MethodAttributes.Static | MethodAttributes.PinvokeImpl,
                    MethodImplAttributes.PreserveSig, metadata.GetOrAddString("DhcpEnumSubnets"), metadata.GetOrAddBlob(signature), -1,
                    MetadataTokens.ParameterHandle(1));
                var module = metadata.AddModuleReference(metadata.GetOrAddString("dhcpsapi.dll"));
                metadata.AddMethodImport(method, MethodImportAttributes.CallingConventionWinApi, metadata.GetOrAddString("DhcpEnumSubnets"), module);
                var names = new[] { "ServerIpAddress", "ResumeHandle", "PreferredMaximum", "EnumInfo", "ElementsRead", "ElementsTotal" };
                for (int index = 0; index < names.Length; index++)
                    metadata.AddParameter(index == 3 ? direction : ParameterAttributes.In, metadata.GetOrAddString(names[index]), index + 1);
                var image = new BlobBuilder();
                new MetadataRootBuilder(metadata).Serialize(image, 0, 0);
                return MetadataReaderProvider.FromMetadataImage(image.ToImmutableArray());
            }
        }

        [Theory]
        [InlineData("valid")]
        [InlineData("missing-type")]
        [InlineData("missing-constructor")]
        [InlineData("missing-instance-bit")]
        [InlineData("external-local-type")]
        [InlineData("self-assembly-reference")]
        public void LocalAttributeClosureMutationControls(string mutation)
        {
            using var metadata = CreateClosureFixture(mutation);
            if (mutation == "valid")
                AssertClosure(metadata.GetMetadataReader());
            else
                Assert.ThrowsAny<XunitException>(() => AssertClosure(metadata.GetMetadataReader()));
        }

        [Theory]
        [InlineData("order")]
        [InlineData("value")]
        [InlineData("type")]
        [InlineData("name")]
        [InlineData("owner")]
        public void ApiLiteralComparisonIgnoresOnlyRowOrder(string mutation)
        {
            using var baseline = Fixture("");
            using var changed = Fixture(mutation);
            var before = baseline.GetMetadataReader();
            var after = changed.GetMetadataReader();
            string expected = SnapshotType(before, before.GetTypeDefinition(MetadataTokens.TypeDefinitionHandle(2)));
            string actual = SnapshotType(after, after.GetTypeDefinition(MetadataTokens.TypeDefinitionHandle(2)));
            if (mutation == "order")
                Assert.Equal(expected, actual);
            else
                Assert.NotEqual(expected, actual);

            static MetadataReaderProvider Fixture(string mutation)
            {
                var metadata = new MetadataBuilder();
                metadata.AddModule(0, metadata.GetOrAddString("Constants.winmd"), metadata.GetOrAddGuid(Guid.NewGuid()), default, default);
                metadata.AddTypeDefinition(TypeAttributes.NotPublic, default, metadata.GetOrAddString("<Module>"), default,
                    MetadataTokens.FieldDefinitionHandle(1), MetadataTokens.MethodDefinitionHandle(1));
                metadata.AddTypeDefinition(TypeAttributes.Public | TypeAttributes.Abstract | TypeAttributes.Sealed,
                    metadata.GetOrAddString("Pilot"), metadata.GetOrAddString("Apis"), default,
                    MetadataTokens.FieldDefinitionHandle(1), MetadataTokens.MethodDefinitionHandle(1));
                metadata.AddTypeDefinition(TypeAttributes.Public, metadata.GetOrAddString("Pilot"),
                    metadata.GetOrAddString("Other"), default, MetadataTokens.FieldDefinitionHandle(mutation == "owner" ? 2 : 3),
                    MetadataTokens.MethodDefinitionHandle(1));
                foreach (string name in mutation == "order" ? new[] { "Second", "First" } : new[] { "First", "Second" })
                {
                    var signature = new BlobBuilder();
                    var fieldType = new BlobEncoder(signature).FieldSignature();
                    bool signed = mutation == "type" && name == "Second";
                    if (signed) fieldType.Int32();
                    else fieldType.UInt32();
                    var field = metadata.AddFieldDefinition(FieldAttributes.Public | FieldAttributes.Static | FieldAttributes.Literal | FieldAttributes.HasDefault,
                        metadata.GetOrAddString(mutation == "name" && name == "Second" ? "Different" : name), metadata.GetOrAddBlob(signature));
                    uint value = name == "First" ? 1u : mutation == "value" ? 3u : 2u;
                    metadata.AddConstant(field, signed ? (object)(int)value : value);
                }
                var image = new BlobBuilder();
                new MetadataRootBuilder(metadata).Serialize(image, 0, 0);
                return MetadataReaderProvider.FromMetadataImage(image.ToImmutableArray());
            }
        }

        internal static string RepositoryRoot
        {
            get
            {
                var directory = new DirectoryInfo(AppContext.BaseDirectory);
                while (directory != null && !File.Exists(Path.Combine(directory.FullName, "generation", "WinSDK", "Windows.Win32.proj")))
                    directory = directory.Parent;
                return directory?.FullName ?? throw new DirectoryNotFoundException("The SDK project was not found.");
            }
        }

        internal static void AssertClosure(MetadataReader reader)
        {
            var definitions = reader.TypeDefinitions.GroupBy(handle => FullName(reader, handle))
                .ToDictionary(group => group.Key, group => group.ToArray(), StringComparer.Ordinal);
            foreach (var handle in reader.TypeReferences)
            {
                var type = reader.GetTypeReference(handle);
                Assert.False(type.ResolutionScope.IsNil, FullName(reader, handle));
                if (IsLocal(reader, handle))
                    Assert.Contains(FullName(reader, handle), definitions.Keys);
            }
            if (reader.IsAssembly)
                Assert.DoesNotContain(reader.AssemblyReferences,
                    handle => reader.GetString(reader.GetAssemblyReference(handle).Name) == reader.GetString(reader.GetAssemblyDefinition().Name));

            foreach (var handle in reader.CustomAttributes)
            {
                var attribute = reader.GetCustomAttribute(handle);
                Assert.DoesNotContain(AttributeName(reader, handle),
                    new[] { "NativeAnnotationAttribute", "SourceLocationAttribute", "CppAttributeList" });
                if (attribute.Constructor.Kind == HandleKind.MethodDefinition)
                {
                    Assert.Equal(".ctor", reader.GetString(reader.GetMethodDefinition((MethodDefinitionHandle)attribute.Constructor).Name));
                    continue;
                }
                Assert.Equal(HandleKind.MemberReference, attribute.Constructor.Kind);
                var constructor = reader.GetMemberReference((MemberReferenceHandle)attribute.Constructor);
                Assert.Equal(".ctor", reader.GetString(constructor.Name));
                string typeName = FullName(reader, constructor.Parent);
                bool local = constructor.Parent.Kind == HandleKind.TypeDefinition ||
                    (constructor.Parent.Kind == HandleKind.TypeReference && IsLocal(reader, (TypeReferenceHandle)constructor.Parent));
                if (typeName.StartsWith(MetadataNamespace + ".", StringComparison.Ordinal))
                    Assert.True(local, "A local metadata attribute was scoped outside this image: " + typeName);
                if (local)
                {
                    Assert.True(definitions.TryGetValue(typeName, out var candidates), "Missing attribute type: " + typeName);
                    string signature = Signature(constructor.DecodeMethodSignature(Signatures, null));
                    var constructors = candidates.Select(reader.GetTypeDefinition).SelectMany(type => type.GetMethods()).Select(reader.GetMethodDefinition)
                        .Where(method => reader.GetString(method.Name) == ".ctor")
                        .Select(method => Signature(method.DecodeSignature(Signatures, null))).ToArray();
                    Assert.True(constructors.Contains(signature), $"Unresolved local attribute constructor: {typeName} {signature}; definitions: " +
                        string.Join("; ", constructors));
                }
            }
        }

        internal static string[] SnapshotNamespace(MetadataReader reader, string ns)
            => reader.TypeDefinitions.Where(handle => FullName(reader, handle).StartsWith(ns + ".", StringComparison.Ordinal))
                .Select(reader.GetTypeDefinition)
                .Select(type => SnapshotType(reader, type)).OrderBy(value => value, StringComparer.Ordinal).ToArray();

        private void AssertEveryPhysicalTypeUnchanged(MetadataReader expectedReader, MetadataReader actualReader, string baseline)
        {
            var before = Types(expectedReader);
            var after = Types(actualReader);
            Assert.Equal(37314, before.Count);
            Assert.Equal(before.Keys.OrderBy(value => value), after.Keys.OrderBy(value => value));
            foreach (var entry in before)
            {
                string expected = SnapshotType(expectedReader, entry.Value);
                string actual = SnapshotType(actualReader, after[entry.Key]);
                Assert.True(expected == actual,
                    $"Unexpected physical change against {baseline} in {entry.Key}.\nExpected:\n{expected}\nActual:\n{actual}");
            }
            this.output.WriteLine($"All {before.Count} {baseline} physical types unchanged; no scope-adoption normalization or allowances.");
        }

        private void AssertOnlyPropertyStorageFieldsAndCanonicalResults(MetadataReader expectedReader, MetadataReader actualReader, string baseline)
        {
            var before = Types(expectedReader);
            var after = Types(actualReader);
            var used = new HashSet<string>(StringComparer.Ordinal);
            Assert.Equal(37314, before.Count);
            Assert.Equal(before.Keys.OrderBy(value => value), after.Keys.OrderBy(value => value));
            foreach (var entry in before)
            {
                string expected = SnapshotType(expectedReader, entry.Value,
                    usedEnumSites: used, normalizePropertyStorageEnumUses: true, canonicalizeLegacyResults: true);
                string actual = SnapshotType(actualReader, after[entry.Key]);
                Assert.True(expected == actual,
                    $"Unexpected expanded-pilot change against {baseline} in {entry.Key}.\nExpected:\n{expected}\nActual:\n{actual}");
            }
            Assert.Equal(PropertyStorageEnumUses.Select(value => value.Site).OrderBy(value => value), used.OrderBy(value => value));
            this.output.WriteLine($"All {before.Count} {baseline} physical types graded: zero scope-adoption changes, " +
                "only canonical result encoding and the three separately asserted source-IDL native-storage/AssociatedEnum field transitions.");
        }

        private static void AssertReviewedTypeSet(MetadataReader expectedReader, MetadataReader actualReader)
        {
            var before = Types(expectedReader);
            var after = Types(actualReader);
            var removed = ReviewedLifecycleTransfers.Where(value => value.Synthetic).ToArray();
            Assert.Equal(4, removed.Length);
            foreach (var transfer in removed)
            {
                string key = transfer.TypeSite + "#124";
                Assert.True(before.ContainsKey(key), "Missing original synthetic handle: " + key);
                Assert.DoesNotContain(key, after.Keys);
                var attributes = LifecycleAttributes(transfer.Cleanup)
                    .Append(MetadataNamespace + ".NativeTypedefAttribute:01000000").OrderBy(value => value, StringComparer.Ordinal);
                string expected = transfer.TypeSite + "\nPublic, SequentialLayout, Sealed, BeforeFieldInit|System.ValueType|0|0|" +
                    string.Join(",", attributes) + "\nF|Value|Public|Void*|-1|||";
                Assert.Equal(expected, SnapshotType(expectedReader, before[key]));
            }
            Assert.Equal(before.Keys.Except(removed.Select(value => value.TypeSite + "#124")).OrderBy(value => value),
                after.Keys.OrderBy(value => value));
        }

        internal static string SnapshotType(MetadataReader reader, TypeDefinition type, bool correctConstructorInstanceBits = false,
            bool normalizeReviewedChanges = false, ISet<string> usedEnumSites = null, ISet<string> usedRetvalSites = null,
            ISet<string> usedPreservedResultSites = null, ISet<string> usedNativeDirectionSites = null,
            ISet<string> usedHandleSites = null, ISet<string> usedLifecycleSites = null, ISet<string> usedNativeConstantSites = null,
            ISet<string> usedEnumStorageSites = null, bool normalizeReviewedEnumUses = false,
            bool normalizePropertyStorageEnumUses = false, bool canonicalizeLegacyResults = false)
        {
            string Attributes(CustomAttributeHandleCollection values, string associatedEnum = null, bool nativeRetval = false,
                bool preservedResult = false, string cleanup = null, bool removeLifecycle = false, bool omitLegacyResults = false)
            {
                var attributes = values.Where(handle => !omitLegacyResults || !IsLegacyResultAttribute(reader, handle))
                    .Select(handle => AttributeTypeName(reader, handle) + ":" +
                    Convert.ToHexString(reader.GetBlobBytes(reader.GetCustomAttribute(handle).Value))).ToList();
                if (associatedEnum != null)
                {
                    Assert.DoesNotContain(values, handle => AttributeName(reader, handle) == "AssociatedEnumAttribute");
                    var value = new BlobBuilder();
                    value.WriteUInt16(1);
                    value.WriteSerializedString(associatedEnum);
                    value.WriteUInt16(0);
                    attributes.Add(MetadataNamespace + ".AssociatedEnumAttribute:" + Convert.ToHexString(value.ToArray()));
                }
                if (nativeRetval)
                {
                    Assert.DoesNotContain(values, handle => AttributeName(reader, handle) == "RetValAttribute");
                    attributes.Add(MetadataNamespace + ".RetValAttribute:01000000");
                }
                if (preservedResult)
                {
                    var attribute = Assert.Single(values.Where(handle => AttributeName(reader, handle) == "CanReturnMultipleSuccessValuesAttribute"));
                    Assert.Equal(new byte[] { 1, 0, 0, 0 }, reader.GetBlobBytes(reader.GetCustomAttribute(attribute).Value));
                    Assert.True(attributes.Remove(MetadataNamespace + ".CanReturnMultipleSuccessValuesAttribute:01000000"));
                }
                if (cleanup != null)
                {
                    string[] ownership = values.Where(handle => AttributeName(reader, handle) is "RAIIFreeAttribute" or "InvalidHandleValueAttribute")
                        .Select(handle => AttributeTypeName(reader, handle) + ":" +
                            Convert.ToHexString(reader.GetBlobBytes(reader.GetCustomAttribute(handle).Value)))
                        .OrderBy(value => value, StringComparer.Ordinal).ToArray();
                    string[] expected = LifecycleAttributes(cleanup);
                    if (removeLifecycle)
                    {
                        Assert.Equal(expected, ownership);
                        foreach (string value in expected)
                            Assert.True(attributes.Remove(value));
                    }
                    else
                    {
                        Assert.Empty(ownership);
                        attributes.AddRange(expected);
                    }
                }
                return string.Join(",", attributes.OrderBy(value => value, StringComparer.Ordinal));
            }
            string Blob(BlobHandle blob) => blob.IsNil ? "" : Convert.ToHexString(reader.GetBlobBytes(blob));
            string ns = reader.GetString(type.Namespace);
            string typeName = reader.GetString(type.Name);
            string fullTypeName = type.GetDeclaringType().IsNil ? ns + "." + typeName :
                FullName(reader, type.GetDeclaringType()) + "+" + typeName;
            bool signedDwmContact = normalizeReviewedChanges && ns == DwmNamespace && typeName == "DWM_SHOWCONTACT";
            if (signedDwmContact)
            {
                AssertDwmContactStorage(reader, type, signed: false);
                usedEnumStorageSites?.Add(DwmNamespace + ".DWM_SHOWCONTACT");
            }
            var uses = (normalizeReviewedChanges || normalizeReviewedEnumUses
                ? ReviewedEnumUses.Where(value => value.Namespace == ns) : Array.Empty<EnumUse>())
                .Concat(normalizePropertyStorageEnumUses ? PropertyStorageEnumUses : Array.Empty<EnumUse>()).ToArray();
            var handleUses = normalizeReviewedChanges
                ? ReviewedHandleUses.Where(value => value.Namespace == ns).ToArray() : Array.Empty<HandleUse>();
            var transfers = normalizeReviewedChanges
                ? ReviewedLifecycleTransfers.Where(value => value.Namespace == ns).ToArray() : Array.Empty<LifecycleTransfer>();
            var typeTransfer = transfers.FirstOrDefault(value => value.Type == typeName);
            if (typeTransfer != null)
                usedLifecycleSites?.Add(typeTransfer.TypeSite);
            var rows = new List<string>
            {
                reader.GetString(type.Namespace) + "." + reader.GetString(type.Name),
                $"{type.Attributes}|{FullName(reader, type.BaseType)}|{type.GetLayout().PackingSize}|{type.GetLayout().Size}|" +
                    Attributes(type.GetCustomAttributes(), cleanup: typeTransfer?.Cleanup, removeLifecycle: true),
            };
            IEnumerable<FieldDefinitionHandle> fields = type.GetFields();
            bool sortedLiteralFields = typeName == "Apis" && fields.All(handle =>
                reader.GetFieldDefinition(handle).Attributes.HasFlag(FieldAttributes.Static | FieldAttributes.Literal));
            if (sortedLiteralFields)
            {
                fields = fields.OrderBy(handle => reader.GetString(reader.GetFieldDefinition(handle).Name), StringComparer.Ordinal);
            }
            if (normalizeReviewedChanges && ns == HidNamespace && typeName == "Apis")
            {
                var field = fields.Select(reader.GetFieldDefinition).Single(value => reader.GetString(value.Name) == HidConstant);
                AssertHidConstant(reader, field);
                fields = fields.OrderBy(handle => reader.GetString(reader.GetFieldDefinition(handle).Name) == HidConstant);
                usedNativeConstantSites?.Add(HidNamespace + ".Apis." + HidConstant);
            }
            if (normalizeReviewedChanges && ns == BluetoothNamespace && typeName == "Apis")
            {
                var field = fields.Select(reader.GetFieldDefinition).Single(value => reader.GetString(value.Name) == "AF_BTH");
                AssertNativeLiteral(reader, field, "UInt16", ConstantTypeCode.UInt16, new byte[] { 32, 0 });
                fields = fields.OrderBy(handle => reader.GetString(reader.GetFieldDefinition(handle).Name) == "AF_BTH");
                usedNativeConstantSites?.Add(BluetoothNamespace + ".Apis.AF_BTH");
            }
            var fieldRows = new List<string>();
            foreach (var handle in fields)
            {
                var field = reader.GetFieldDefinition(handle);
                string name = reader.GetString(field.Name);
                string fieldType = field.DecodeSignature(Signatures, null);
                if (signedDwmContact && name == "value__")
                    fieldType = "Int32";
                var use = uses.SingleOrDefault(value => value.Namespace + "." + value.Owner == fullTypeName && value.Member == name);
                if (use != null)
                {
                    Assert.Equal(use.OldType, fieldType);
                    fieldType = use.Native;
                    usedEnumSites?.Add(use.Site);
                }
                string constant = field.GetDefaultValue().IsNil ? "" :
                    reader.GetConstant(field.GetDefaultValue()).TypeCode + ":" + Blob(reader.GetConstant(field.GetDefaultValue()).Value);
                if (signedDwmContact && !field.GetDefaultValue().IsNil)
                    constant = ConstantTypeCode.Int32 + ":" + Blob(reader.GetConstant(field.GetDefaultValue()).Value);
                fieldRows.Add($"F|{name}|{field.Attributes}|{fieldType}|{field.GetOffset()}|" +
                    $"{constant}|{Blob(field.GetMarshallingDescriptor())}|{Attributes(field.GetCustomAttributes(), use?.Enum)}");
            }
            if (normalizeReviewedChanges && ns == WerNamespace && typeName == "Apis")
            {
                Assert.True(sortedLiteralFields);
                Assert.DoesNotContain(fields, handle => reader.GetString(reader.GetFieldDefinition(handle).Name) == WerAlias);
                fieldRows.Add(WerAliasField);
                usedNativeConstantSites?.Add(WerNamespace + ".Apis." + WerAlias);
            }
            rows.AddRange(sortedLiteralFields
                ? fieldRows.OrderBy(value => value.Split('|')[1], StringComparer.Ordinal)
                : fieldRows);
            foreach (var handle in type.GetMethods())
            {
                var method = reader.GetMethodDefinition(handle);
                var signature = method.DecodeSignature(Signatures, null);
                string methodName = reader.GetString(method.Name);
                var parameters = method.GetParameters().Select(reader.GetParameter).ToArray();
                var parameterTypes = signature.ParameterTypes.ToArray();
                string returnType = signature.ReturnType;
                var parameterEnums = new Dictionary<int, string>();
                foreach (var use in uses.Where(value => typeName == "Apis" && value.Namespace == ns && value.Owner == methodName))
                {
                    var parameter = use.Member == "return"
                        ? parameters.Single(value => value.SequenceNumber == 0)
                        : parameters.Single(value => reader.GetString(value.Name) == use.Member);
                    if (use.Member == "return")
                    {
                        Assert.Equal("", reader.GetString(parameter.Name));
                        Assert.Equal(use.OldType, returnType);
                        returnType = use.Native;
                        parameterEnums.Add(0, use.Enum);
                        usedEnumSites?.Add(use.Site);
                        continue;
                    }
                    Assert.True(parameter.SequenceNumber > 0);
                    Assert.Equal(use.OldType, parameterTypes[parameter.SequenceNumber - 1]);
                    parameterTypes[parameter.SequenceNumber - 1] = use.Native;
                    parameterEnums.Add(parameter.SequenceNumber, use.Enum);
                    usedEnumSites?.Add(use.Site);
                }
                foreach (var use in handleUses.Where(value => typeName == "Apis" && value.Method == methodName))
                {
                    var parameter = use.Member == "return"
                        ? parameters.Single(value => value.SequenceNumber == 0)
                        : parameters.Single(value => reader.GetString(value.Name) == use.Member);
                    if (use.Member == "return")
                    {
                        Assert.Equal("", reader.GetString(parameter.Name));
                        Assert.Equal(use.OldType, returnType);
                        returnType = use.Native;
                    }
                    else
                    {
                        Assert.True(parameter.SequenceNumber > 0);
                        Assert.Equal(use.OldType, parameterTypes[parameter.SequenceNumber - 1]);
                        parameterTypes[parameter.SequenceNumber - 1] = use.Native;
                    }
                    usedHandleSites?.Add(use.Site);
                }
                int header = signature.Header.RawValue;
                if (correctConstructorInstanceBits && reader.GetString(method.Name) == ".ctor" &&
                    !method.Attributes.HasFlag(MethodAttributes.Static) && !signature.Header.IsInstance)
                {
                    Assert.Equal(0, header);
                    header |= 0x20;
                }
                bool preservedResult = normalizeReviewedChanges && (ns, typeName, methodName) == ReviewedPreservedResult;
                var implementation = method.ImplAttributes;
                if (preservedResult)
                {
                    Assert.False(implementation.HasFlag(MethodImplAttributes.PreserveSig));
                    implementation |= MethodImplAttributes.PreserveSig;
                    usedPreservedResultSites?.Add($"{ns}.{typeName}.{methodName}");
                }
                bool canonicalResult = canonicalizeLegacyResults &&
                    method.GetCustomAttributes().Any(handle => IsLegacyResultAttribute(reader, handle));
                if (canonicalResult)
                    implementation |= MethodImplAttributes.PreserveSig;
                rows.Add($"M|{methodName}|{method.Attributes}|{implementation}|{Signature(signature, header, parameterTypes, returnType)}|" +
                    $"{Import(reader, method)}|{Attributes(method.GetCustomAttributes(), preservedResult: preservedResult && !canonicalResult, omitLegacyResults: canonicalResult)}");
                foreach (var parameter in parameters)
                {
                    string parameterName = reader.GetString(parameter.Name);
                    bool nativeRetval = normalizeReviewedChanges && NativeRetvalUses.Contains((ns, typeName, methodName, parameterName));
                    if (nativeRetval)
                        usedRetvalSites?.Add($"{ns}.{typeName}.{methodName}.{parameterName}");
                    var direction = normalizeReviewedChanges
                        ? NativeDirectionUses.SingleOrDefault(value =>
                            (value.Namespace, value.Owner, value.Method, value.Parameter) == (ns, typeName, methodName, parameterName))
                        : default;
                    var parameterAttributes = parameter.Attributes;
                    if (direction.Parameter != null)
                    {
                        Assert.Equal(direction.Before, parameterAttributes);
                        parameterAttributes = direction.After;
                        usedNativeDirectionSites?.Add($"{ns}.{typeName}.{methodName}.{parameterName}");
                    }
                    var transfer = transfers.SingleOrDefault(value => typeName == "Apis" && value.Method == methodName &&
                        (value.Member == "return" ? parameter.SequenceNumber == 0 : value.Member == parameterName));
                    if (transfer != null)
                    {
                        Assert.Equal(transfer.Member == "return" ? ParameterAttributes.None : ParameterAttributes.Out, parameter.Attributes);
                        usedLifecycleSites?.Add(transfer.Site);
                    }
                    string attributes = Attributes(parameter.GetCustomAttributes(), parameterEnums.GetValueOrDefault(parameter.SequenceNumber),
                        nativeRetval, cleanup: transfer?.Cleanup);
                    rows.Add($"P|{parameter.SequenceNumber}|{reader.GetString(parameter.Name)}|{parameterAttributes}|" +
                        $"{Blob(parameter.GetMarshallingDescriptor())}|{attributes}");
                }
            }
            return string.Join("\n", rows);
        }

        private static string[] LifecycleAttributes(string cleanup)
        {
            var value = new BlobBuilder();
            value.WriteUInt16(1);
            value.WriteSerializedString(cleanup);
            value.WriteUInt16(0);
            return new[]
            {
                MetadataNamespace + ".InvalidHandleValueAttribute:010000000000000000000000",
                MetadataNamespace + ".InvalidHandleValueAttribute:0100FFFFFFFFFFFFFFFF0000",
                MetadataNamespace + ".RAIIFreeAttribute:" + Convert.ToHexString(value.ToArray()),
            };
        }

        private static void AssertHidConstant(MetadataReader reader, FieldDefinition field)
            => AssertNativeLiteral(reader, field, "Windows.Win32.Foundation.NTSTATUS", ConstantTypeCode.Int32, new byte[] { 9, 0, 0x11, 0xc0 });

        private static void AssertDwmContactStorage(MetadataReader reader, TypeDefinition type, bool signed)
        {
            Assert.Equal(DwmNamespace, reader.GetString(type.Namespace));
            Assert.Equal("DWM_SHOWCONTACT", reader.GetString(type.Name));
            Assert.Equal("System.Enum", FullName(reader, type.BaseType));
            Assert.Equal(TypeAttributes.Public | TypeAttributes.Sealed, type.Attributes);
            Assert.Equal(0, type.GetLayout().PackingSize);
            Assert.Equal(0, type.GetLayout().Size);
            Assert.Empty(type.GetMethods());
            var flags = Assert.Single(type.GetCustomAttributes().Where(handle => AttributeName(reader, handle) == "FlagsAttribute"));
            Assert.Equal(new byte[] { 1, 0, 0, 0 }, reader.GetBlobBytes(reader.GetCustomAttribute(flags).Value));
            var fields = type.GetFields().Select(reader.GetFieldDefinition).ToArray();
            Assert.Equal(new[] { "value__" }.Concat(DwmContactMembers.Select(value => value.Name)),
                fields.Select(field => reader.GetString(field.Name)));
            Assert.Equal(FieldAttributes.Public | FieldAttributes.SpecialName | FieldAttributes.RTSpecialName, fields[0].Attributes);
            Assert.Equal(signed ? "Int32" : "UInt32", fields[0].DecodeSignature(Signatures, null));
            Assert.Equal(-1, fields[0].GetOffset());
            Assert.True(fields[0].GetDefaultValue().IsNil);
            Assert.True(fields[0].GetMarshallingDescriptor().IsNil);
            Assert.Empty(fields[0].GetCustomAttributes());
            for (int index = 0; index < DwmContactMembers.Length; index++)
                AssertNativeLiteral(reader, fields[index + 1], DwmNamespace + ".DWM_SHOWCONTACT",
                    signed ? ConstantTypeCode.Int32 : ConstantTypeCode.UInt32, BitConverter.GetBytes(DwmContactMembers[index].Bits));
        }

        private static void AssertNativeLiteral(MetadataReader reader, FieldDefinition field, string signature, ConstantTypeCode typeCode, byte[] bytes)
        {
            Assert.Equal(FieldAttributes.Public | FieldAttributes.Static | FieldAttributes.Literal | FieldAttributes.HasDefault, field.Attributes);
            Assert.Equal(signature, field.DecodeSignature(Signatures, null));
            Assert.Equal(-1, field.GetOffset());
            Assert.True(field.GetMarshallingDescriptor().IsNil);
            Assert.Empty(field.GetCustomAttributes());
            var constant = reader.GetConstant(field.GetDefaultValue());
            Assert.Equal(typeCode, constant.TypeCode);
            Assert.Equal(bytes, reader.GetBlobBytes(constant.Value));
        }

        private static string Import(MetadataReader reader, MethodDefinition method)
        {
            var import = method.GetImport();
            return import.Module.IsNil ? "" :
                reader.GetString(reader.GetModuleReference(import.Module).Name) + "|" + reader.GetString(import.Name) + "|" + import.Attributes;
        }

        private static Dictionary<string, MethodDefinition> Methods(MetadataReader reader, string ns, string typeName, int architecture)
            => reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Where(type => reader.GetString(type.Namespace) == ns && reader.GetString(type.Name) == typeName && Supports(reader, type.GetCustomAttributes(), architecture))
                .SelectMany(type => type.GetMethods()).Select(reader.GetMethodDefinition)
                .Where(method => Supports(reader, method.GetCustomAttributes(), architecture))
                .ToDictionary(method => reader.GetString(method.Name), StringComparer.Ordinal);

        private static Dictionary<string, TypeDefinition> Types(MetadataReader reader)
            => reader.TypeDefinitions.ToDictionary(handle =>
            {
                var type = reader.GetTypeDefinition(handle);
                string key = FullName(reader, handle);
                while (true)
                {
                    key += "#" + string.Join("", new[] { 1, 2, 4 }.Select(architecture =>
                        Supports(reader, type.GetCustomAttributes(), architecture) ? architecture : 0));
                    if (type.GetDeclaringType().IsNil) return key;
                    type = reader.GetTypeDefinition(type.GetDeclaringType());
                }
            }, reader.GetTypeDefinition, StringComparer.Ordinal);

        private static TypeDefinition Type(MetadataReader reader, string name, int architecture, string ns = WinHttpNamespace)
            => reader.TypeDefinitions.Select(reader.GetTypeDefinition).Single(type => reader.GetString(type.Namespace) == ns &&
                reader.GetString(type.Name) == name && Supports(reader, type.GetCustomAttributes(), architecture));

        private static bool Supports(MetadataReader reader, CustomAttributeHandleCollection attributes, int architecture)
        {
            var matches = attributes.Where(handle => AttributeName(reader, handle) == "SupportedArchitectureAttribute").ToArray();
            if (!matches.Any()) return true;
            Assert.Single(matches);
            var value = reader.GetBlobReader(reader.GetCustomAttribute(matches[0]).Value);
            Assert.Equal(1, value.ReadUInt16());
            int mask = value.ReadInt32();
            Assert.Equal(0, value.ReadUInt16());
            Assert.Equal(0, value.RemainingBytes);
            return (mask & architecture) != 0;
        }

        private static string[] AttributeValues(MetadataReader reader, CustomAttributeHandleCollection attributes, string name)
            => attributes.Where(handle => AttributeName(reader, handle) == name).Select(handle =>
            {
                var value = reader.GetBlobReader(reader.GetCustomAttribute(handle).Value);
                Assert.Equal(1, value.ReadUInt16());
                string result = value.ReadSerializedString();
                Assert.Equal(0, value.ReadUInt16());
                Assert.Equal(0, value.RemainingBytes);
                return result;
            }).ToArray();

        private static string AttributeName(MetadataReader reader, CustomAttributeHandle handle)
            => AttributeTypeName(reader, handle).Split('.').Last();

        private static bool IsLegacyResultAttribute(MetadataReader reader, CustomAttributeHandle handle)
        {
            string name = AttributeTypeName(reader, handle);
            return name == MetadataNamespace + ".CanReturnErrorsAsSuccessAttribute" ||
                name == MetadataNamespace + ".CanReturnMultipleSuccessValuesAttribute";
        }

        private static string AttributeTypeName(MetadataReader reader, CustomAttributeHandle handle)
        {
            var constructor = reader.GetCustomAttribute(handle).Constructor;
            return FullName(reader, constructor.Kind == HandleKind.MethodDefinition ?
                reader.GetMethodDefinition((MethodDefinitionHandle)constructor).GetDeclaringType() :
                reader.GetMemberReference((MemberReferenceHandle)constructor).Parent);
        }

        private static bool IsLocal(MetadataReader reader, TypeReferenceHandle handle)
        {
            var scope = reader.GetTypeReference(handle).ResolutionScope;
            return scope.Kind == HandleKind.ModuleDefinition ||
                (scope.Kind == HandleKind.TypeReference && IsLocal(reader, (TypeReferenceHandle)scope));
        }

        private static string FullName(MetadataReader reader, EntityHandle handle)
        {
            if (handle.IsNil) return "";
            if (handle.Kind == HandleKind.TypeDefinition)
            {
                var type = reader.GetTypeDefinition((TypeDefinitionHandle)handle);
                return type.GetDeclaringType().IsNil ? reader.GetString(type.Namespace) + "." + reader.GetString(type.Name) :
                    FullName(reader, type.GetDeclaringType()) + "+" + reader.GetString(type.Name);
            }
            if (handle.Kind == HandleKind.TypeReference)
            {
                var type = reader.GetTypeReference((TypeReferenceHandle)handle);
                return type.ResolutionScope.Kind == HandleKind.TypeReference ? FullName(reader, type.ResolutionScope) + "+" + reader.GetString(type.Name) :
                    reader.GetString(type.Namespace) + "." + reader.GetString(type.Name);
            }
            throw new InvalidDataException("Unsupported type handle: " + handle.Kind);
        }

        private static string Signature(MethodSignature<string> signature, int? header = null, IEnumerable<string> parameterTypes = null,
            string returnType = null)
            => $"{header ?? signature.Header.RawValue}|{signature.GenericParameterCount}|{signature.RequiredParameterCount}|{returnType ?? signature.ReturnType}|" +
                string.Join(",", parameterTypes ?? signature.ParameterTypes);

        private sealed record EnumUse(string Namespace, string Owner, string Member, string Enum, string Native, string EnumNamespace = null)
        {
            internal string Site => Namespace + "." + Owner + "::" + Member;
            internal string OldType => (EnumNamespace ?? Namespace) + "." + Enum + new string('*', Native.Length - Native.TrimEnd('*').Length);
        }

        private sealed record HandleUse(string Namespace, string Method, string Member, string Type, string Native)
        {
            internal string Site => Namespace + "." + Method + "::" + Member;
            internal string OldType => Namespace + "." + Type;
        }

        private sealed record LifecycleTransfer(string Namespace, string Type, string Method, string Member, string Cleanup, bool Synthetic = false)
        {
            internal string Site => Namespace + ".Apis." + Method + "::" + Member;
            internal string TypeSite => Namespace + "." + Type;
        }

        private static Image Open(string variable) => new Image(Environment.GetEnvironmentVariable(variable));

        private static MetadataReaderProvider CreateClosureFixture(string mutation)
        {
            var metadata = new MetadataBuilder();
            metadata.AddModule(0, metadata.GetOrAddString("Fixture.winmd"), metadata.GetOrAddGuid(Guid.NewGuid()), default, default);
            metadata.AddAssembly(metadata.GetOrAddString("Fixture"), new Version(1, 0), default, default, 0, AssemblyHashAlgorithm.None);
            var runtime = metadata.AddAssemblyReference(metadata.GetOrAddString("System.Runtime"), new Version(8, 0), default, default, 0, default);
            if (mutation == "self-assembly-reference")
                metadata.AddAssemblyReference(metadata.GetOrAddString("Fixture"), new Version(1, 0), default, default, 0, default);
            var attributeBase = metadata.AddTypeReference(runtime, metadata.GetOrAddString("System"), metadata.GetOrAddString("Attribute"));
            metadata.AddTypeDefinition(TypeAttributes.NotPublic, default, metadata.GetOrAddString("<Module>"), default,
                MetadataTokens.FieldDefinitionHandle(1), MetadataTokens.MethodDefinitionHandle(1));
            metadata.AddTypeDefinition(TypeAttributes.Public, metadata.GetOrAddString(MetadataNamespace),
                metadata.GetOrAddString(mutation == "missing-type" ? "OtherAttribute" : "ProbeAttribute"), attributeBase,
                MetadataTokens.FieldDefinitionHandle(1), MetadataTokens.MethodDefinitionHandle(1));
            var signature = new BlobBuilder();
            new BlobEncoder(signature).MethodSignature(isInstanceMethod: mutation != "missing-instance-bit").Parameters(1, result => result.Void(),
                parameters => parameters.AddParameter().Type().Int32());
            metadata.AddMethodDefinition(MethodAttributes.Public | MethodAttributes.SpecialName | MethodAttributes.RTSpecialName,
                MethodImplAttributes.Runtime, metadata.GetOrAddString(".ctor"), metadata.GetOrAddBlob(signature), -1,
                MetadataTokens.ParameterHandle(1));
            metadata.AddParameter(0, metadata.GetOrAddString("value"), 1);
            var sample = metadata.AddTypeDefinition(TypeAttributes.Public, metadata.GetOrAddString("Pilot"), metadata.GetOrAddString("Sample"),
                default, MetadataTokens.FieldDefinitionHandle(1), MetadataTokens.MethodDefinitionHandle(2));
            var attribute = metadata.AddTypeReference(mutation == "external-local-type" ? runtime : MetadataTokens.EntityHandle(1), metadata.GetOrAddString(MetadataNamespace),
                metadata.GetOrAddString("ProbeAttribute"));
            var referenceSignature = new BlobBuilder();
            new BlobEncoder(referenceSignature).MethodSignature(isInstanceMethod: true).Parameters(1, result => result.Void(), parameters =>
            {
                var parameter = parameters.AddParameter().Type();
                if (mutation == "missing-constructor") parameter.String();
                else parameter.Int32();
            });
            var constructor = metadata.AddMemberReference(attribute, metadata.GetOrAddString(".ctor"), metadata.GetOrAddBlob(referenceSignature));
            var value = new BlobBuilder();
            value.WriteUInt16(1);
            if (mutation == "missing-constructor") value.WriteSerializedString("x");
            else value.WriteInt32(3);
            value.WriteUInt16(0);
            metadata.AddCustomAttribute(sample, constructor, metadata.GetOrAddBlob(value));
            var image = new BlobBuilder();
            new MetadataRootBuilder(metadata).Serialize(image, 0, 0);
            return MetadataReaderProvider.FromMetadataImage(image.ToImmutableArray());
        }

        private sealed class Image : IDisposable
        {
            private readonly Stream stream;
            private readonly PEReader pe;
            internal Image(string path)
            {
                this.stream = File.OpenRead(path);
                this.pe = new PEReader(this.stream);
                Reader = this.pe.GetMetadataReader(MetadataReaderOptions.None);
            }
            internal MetadataReader Reader { get; }
            public void Dispose() { this.pe.Dispose(); this.stream.Dispose(); }
        }

        private sealed class SignatureNames : ISignatureTypeProvider<string, object>
        {
            public string GetArrayType(string elementType, ArrayShape shape)
                => elementType + "[" + shape.Rank + ";" + string.Join(",", shape.Sizes) + ";" + string.Join(",", shape.LowerBounds) + "]";
            public string GetByReferenceType(string elementType) => elementType + "&";
            public string GetFunctionPointerType(MethodSignature<string> signature) => "fnptr:" + Signature(signature);
            public string GetGenericInstantiation(string genericType, ImmutableArray<string> typeArguments) => genericType + "<" + string.Join(",", typeArguments) + ">";
            public string GetGenericMethodParameter(object context, int index) => "!!" + index;
            public string GetGenericTypeParameter(object context, int index) => "!" + index;
            public string GetModifiedType(string modifier, string type, bool required) => type + (required ? " modreq(" : " modopt(") + modifier + ")";
            public string GetPinnedType(string elementType) => elementType + " pinned";
            public string GetPointerType(string elementType) => elementType + "*";
            public string GetPrimitiveType(PrimitiveTypeCode type) => type.ToString();
            public string GetSZArrayType(string elementType) => elementType + "[]";
            public string GetTypeFromDefinition(MetadataReader reader, TypeDefinitionHandle handle, byte kind) => FullName(reader, handle);
            public string GetTypeFromReference(MetadataReader reader, TypeReferenceHandle handle, byte kind) => FullName(reader, handle);
            public string GetTypeFromSpecification(MetadataReader reader, object context, TypeSpecificationHandle handle, byte kind)
                => reader.GetTypeSpecification(handle).DecodeSignature(this, context);
        }
    }

    public sealed class MigrationFactAttribute : FactAttribute
    {
        public MigrationFactAttribute(string additionalFixture = null)
        {
            if (Environment.GetEnvironmentVariable("WINHTTP_MIGRATION_OLD") == null ||
                Environment.GetEnvironmentVariable("WINHTTP_MIGRATION_NEW") == null ||
                Environment.GetEnvironmentVariable("WINHTTP_MIGRATION_TOOLING_CONTROL") == null)
                Skip = "Set WINHTTP_MIGRATION_OLD, WINHTTP_MIGRATION_NEW and WINHTTP_MIGRATION_TOOLING_CONTROL to the pinned full-image fixtures.";
            else if (additionalFixture != null && Environment.GetEnvironmentVariable(additionalFixture) == null)
                Skip = "Set " + additionalFixture + " to the pinned full-image fixture.";
        }
    }

    public sealed class MigrationTheoryAttribute : TheoryAttribute
    {
        public MigrationTheoryAttribute()
        {
            if (Environment.GetEnvironmentVariable("WINHTTP_MIGRATION_OLD") == null ||
                Environment.GetEnvironmentVariable("WINHTTP_MIGRATION_NEW") == null ||
                Environment.GetEnvironmentVariable("WINHTTP_MIGRATION_TOOLING_CONTROL") == null)
                Skip = "Set WINHTTP_MIGRATION_OLD, WINHTTP_MIGRATION_NEW and WINHTTP_MIGRATION_TOOLING_CONTROL to the pinned full-image fixtures.";
        }
    }
}
