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
using Xunit;
using Xunit.Abstractions;
using Xunit.Sdk;

namespace Win32MetadataScraperTests
{
    public class WinHttpMigrationTests
    {
        internal const string WinHttpNamespace = "Windows.Win32.Networking.WinHttp";
        private const string MetadataNamespace = "Windows.Win32.Foundation.Metadata";
        private const string WNetNamespace = "Windows.Win32.NetworkManagement.WNet";
        private const string DhcpNamespace = "Windows.Win32.NetworkManagement.Dhcp";
        private const string RestartManagerNamespace = "Windows.Win32.System.RestartManager";
        private readonly ITestOutputHelper output;
        private static readonly SignatureNames Signatures = new SignatureNames();
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
                "return", "WIN32_ERROR", "UInt32", "Windows.Win32.Foundation"))).ToArray();
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
        private static readonly string[] AdditionalOwnedMethods =
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
        };
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
            foreach (string patch in recipe.RootElement.GetProperty("patches").EnumerateArray().Select(value => value.GetString()))
                Assert.DoesNotContain("_Windows_SupportedOS_", File.ReadAllText(Path.Combine(root, patch)));
        }

        [MigrationFact]
        public void CompleteNewImageClosesConstructorsAndFrozenOldDefectIsExplicit()
        {
            using var old = Open("WINHTTP_MIGRATION_OLD");
            using var current = Open("WINHTTP_MIGRATION_NEW");
            Assert.Equal(37314, old.Reader.TypeDefinitions.Count);
            Assert.Equal(old.Reader.TypeDefinitions.Count, current.Reader.TypeDefinitions.Count);
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
        public void FrozenInputToolingControlChangesOnlyMissingConstructorInstanceBits()
        {
            using var old = Open("WINHTTP_MIGRATION_OLD");
            using var control = Open("WINHTTP_MIGRATION_TOOLING_CONTROL");
            Assert.Equal(old.Reader.TypeDefinitions.Count, control.Reader.TypeDefinitions.Count);
            AssertClosure(control.Reader);
            var before = Types(old.Reader);
            var after = Types(control.Reader);
            Assert.Equal(before.Keys.OrderBy(value => value), after.Keys.OrderBy(value => value));
            int corrected = 0, constructors = 0;
            foreach (var entry in before)
            {
                var original = SnapshotType(old.Reader, entry.Value);
                var expected = SnapshotType(old.Reader, entry.Value, correctConstructorInstanceBits: true);
                Assert.Equal(expected, SnapshotType(control.Reader, after[entry.Key]));
                corrected += original == expected ? 0 : 1;
                constructors += entry.Value.GetMethods().Select(old.Reader.GetMethodDefinition).Count(method =>
                    old.Reader.GetString(method.Name) == ".ctor" && !method.Attributes.HasFlag(MethodAttributes.Static) &&
                    !method.DecodeSignature(Signatures, null).Header.IsInstance);
            }
            Assert.Equal(39, constructors);
            Assert.Equal(39, corrected);
            this.output.WriteLine($"Frozen-input tooling control: {constructors} constructor rows in {corrected} types gain HASTHIS; all other type snapshots are identical.");
        }

        [MigrationFact]
        public void EveryPhysicalTypeHasOnlyReviewedHeaderChanges()
        {
            using var control = Open("WINHTTP_MIGRATION_TOOLING_CONTROL");
            using var current = Open("WINHTTP_MIGRATION_NEW");
            var before = Types(control.Reader);
            var after = Types(current.Reader);
            Assert.Equal(before.Keys.OrderBy(value => value), after.Keys.OrderBy(value => value));
            var used = new HashSet<string>(StringComparer.Ordinal);
            var usedRetvals = new HashSet<string>(StringComparer.Ordinal);
            var usedPreservedResults = new HashSet<string>(StringComparer.Ordinal);
            var usedNativeDirections = new HashSet<string>(StringComparer.Ordinal);
            int unchanged = 0;
            foreach (var entry in before)
            {
                string expected = SnapshotType(control.Reader, entry.Value, normalizeReviewedChanges: true,
                    usedEnumSites: used, usedRetvalSites: usedRetvals, usedPreservedResultSites: usedPreservedResults,
                    usedNativeDirectionSites: usedNativeDirections);
                string actual = SnapshotType(current.Reader, after[entry.Key]);
                Assert.True(expected == actual, $"Unexpected physical metadata change in {entry.Key}.\nExpected:\n{expected}\nActual:\n{actual}");
                unchanged += SnapshotType(control.Reader, entry.Value) == actual ? 1 : 0;
            }
            Assert.Equal(ReviewedEnumUses.Select(value => value.Site).OrderBy(value => value), used.OrderBy(value => value));
            Assert.Equal(NativeRetvalUses.Select(value => $"{value.Namespace}.{value.Owner}.{value.Method}.{value.Parameter}")
                .OrderBy(value => value), usedRetvals.OrderBy(value => value));
            Assert.Equal(new[] { $"{ReviewedPreservedResult.Namespace}.{ReviewedPreservedResult.Owner}.{ReviewedPreservedResult.Method}" },
                usedPreservedResults.OrderBy(value => value));
            Assert.Equal(NativeDirectionUses.Select(value => $"{value.Namespace}.{value.Owner}.{value.Method}.{value.Parameter}")
                .OrderBy(value => value), usedNativeDirections.OrderBy(value => value));
            this.output.WriteLine($"All {before.Count} physical types graded: {unchanged} unchanged; " +
                $"{used.Count} exact native-type/AssociatedEnum sites, {usedRetvals.Count} native MIDL retval sites " +
                $"{usedPreservedResults.Count} reviewed preserved-result site and {usedNativeDirections.Count} exact native SAL direction site normalized.");
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
                Assert.Equal(SnapshotType(old.Reader, Type(old.Reader, name, architecture)),
                    SnapshotType(current.Reader, Type(current.Reader, name, architecture)));
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
            string patch = File.ReadAllText(Path.Combine(project, "patches", "post-midl", "um", "restartmanager.annotations.patch"));
            Assert.Single(patch.Split('\n').Where(line => line.TrimEnd('\r') == "+_Win32_SupportedOS_BEGIN_(WindowsVista)"));
            Assert.Single(patch.Split('\n').Where(line => line.TrimEnd('\r') == "+_Win32_SupportedOS_END_()"));
            Assert.DoesNotContain("_Win32_DllImport_", patch);
            Assert.DoesNotContain("_Win32_ImportLibrary_", patch);
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
        public void ScopedSupportedOSPreservesEveryAcceptedPhysicalType()
        {
            string path = Environment.GetEnvironmentVariable("WINHTTP_MIGRATION_ACCEPTED");
            Assert.Equal("A0C321735141D55C98BCD7D048F822AAA0DA1D9434309ABA1782F79C220773BB",
                Convert.ToHexString(SHA256.HashData(File.ReadAllBytes(path))));
            using var accepted = Open("WINHTTP_MIGRATION_ACCEPTED");
            using var current = Open("WINHTTP_MIGRATION_NEW");
            AssertEveryPhysicalTypeUnchanged(accepted.Reader, current.Reader, "accepted B9");
        }

        [MigrationFact("WINHTTP_MIGRATION_DIRECT_CONTROL")]
        public void ScopedSupportedOSPreservesEveryMatchedDirectPhysicalType()
        {
            string path = Environment.GetEnvironmentVariable("WINHTTP_MIGRATION_DIRECT_CONTROL");
            Assert.Equal("AA7B0D71E535787D2A5B623F8B144AEDCF66A464F1E769C7ADC56CF83EA2EE43",
                Convert.ToHexString(SHA256.HashData(File.ReadAllBytes(path))));
            using var direct = Open("WINHTTP_MIGRATION_DIRECT_CONTROL");
            using var current = Open("WINHTTP_MIGRATION_NEW");
            AssertEveryPhysicalTypeUnchanged(direct.Reader, current.Reader, "matched canonical-direct control");
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
            using var recipe = JsonDocument.Parse(File.ReadAllText(Path.Combine(root, "generation", "WinSDK", "patches", "SdkHeaders.json")));
            var patches = recipe.RootElement.GetProperty("patches").EnumerateArray().Select(value => value.GetString())
                .Where(path => Path.GetFileName(path).StartsWith("winhttp.", StringComparison.Ordinal)).ToArray();
            Assert.Equal(6, patches.Length);
            foreach (string patch in patches)
                Assert.DoesNotContain("_Win32_ImportLibrary_", File.ReadAllText(Path.Combine(root, "generation", "WinSDK", "patches", patch)));
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
        public void AdditionalEmittedOwnersHaveNoAuthoredSemanticFallback()
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
                    string target = line.Split('=')[0].Split(new[] { "::" }, StringSplitOptions.None)[0];
                    Assert.DoesNotContain(target, AdditionalOwnedMethods);
                    Assert.DoesNotContain(target, AdditionalLogicalEnums);
                    Assert.DoesNotContain(target, AdditionalOwnedTypes);
                }
            }
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
                    $"Scoped SupportedOS changed {baseline} metadata in {entry.Key}.\nExpected:\n{expected}\nActual:\n{actual}");
            }
            this.output.WriteLine($"All {before.Count} {baseline} physical types unchanged; no scope-adoption normalization or allowances.");
        }

        internal static string SnapshotType(MetadataReader reader, TypeDefinition type, bool correctConstructorInstanceBits = false,
            bool normalizeReviewedChanges = false, ISet<string> usedEnumSites = null, ISet<string> usedRetvalSites = null,
            ISet<string> usedPreservedResultSites = null, ISet<string> usedNativeDirectionSites = null)
        {
            string Attributes(CustomAttributeHandleCollection values, string associatedEnum = null, bool nativeRetval = false,
                bool preservedResult = false)
            {
                var attributes = values.Select(handle => AttributeTypeName(reader, handle) + ":" +
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
                return string.Join(",", attributes.OrderBy(value => value, StringComparer.Ordinal));
            }
            string Blob(BlobHandle blob) => blob.IsNil ? "" : Convert.ToHexString(reader.GetBlobBytes(blob));
            string ns = reader.GetString(type.Namespace);
            string typeName = reader.GetString(type.Name);
            var uses = normalizeReviewedChanges ? ReviewedEnumUses.Where(value => value.Namespace == ns).ToArray() : Array.Empty<EnumUse>();
            var rows = new List<string>
            {
                reader.GetString(type.Namespace) + "." + reader.GetString(type.Name),
                $"{type.Attributes}|{FullName(reader, type.BaseType)}|{type.GetLayout().PackingSize}|{type.GetLayout().Size}|{Attributes(type.GetCustomAttributes())}",
            };
            IEnumerable<FieldDefinitionHandle> fields = type.GetFields();
            if (typeName == "Apis" && fields.All(handle =>
                reader.GetFieldDefinition(handle).Attributes.HasFlag(FieldAttributes.Static | FieldAttributes.Literal)))
            {
                fields = fields.OrderBy(handle => reader.GetString(reader.GetFieldDefinition(handle).Name), StringComparer.Ordinal);
            }
            foreach (var handle in fields)
            {
                var field = reader.GetFieldDefinition(handle);
                string name = reader.GetString(field.Name);
                string fieldType = field.DecodeSignature(Signatures, null);
                var use = uses.SingleOrDefault(value => value.Owner == typeName && value.Member == name);
                if (use != null)
                {
                    Assert.Equal(use.OldType, fieldType);
                    fieldType = use.Native;
                    usedEnumSites?.Add(use.Site);
                }
                string constant = field.GetDefaultValue().IsNil ? "" :
                    reader.GetConstant(field.GetDefaultValue()).TypeCode + ":" + Blob(reader.GetConstant(field.GetDefaultValue()).Value);
                rows.Add($"F|{name}|{field.Attributes}|{fieldType}|{field.GetOffset()}|" +
                    $"{constant}|{Blob(field.GetMarshallingDescriptor())}|{Attributes(field.GetCustomAttributes(), use?.Enum)}");
            }
            foreach (var handle in type.GetMethods())
            {
                var method = reader.GetMethodDefinition(handle);
                var signature = method.DecodeSignature(Signatures, null);
                string methodName = reader.GetString(method.Name);
                var parameters = method.GetParameters().Select(reader.GetParameter).ToArray();
                var parameterTypes = signature.ParameterTypes.ToArray();
                string returnType = signature.ReturnType;
                var parameterEnums = new Dictionary<int, string>();
                foreach (var use in uses.Where(value => typeName == "Apis" && value.Owner == methodName))
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
                rows.Add($"M|{methodName}|{method.Attributes}|{implementation}|{Signature(signature, header, parameterTypes, returnType)}|" +
                    $"{Import(reader, method)}|{Attributes(method.GetCustomAttributes(), preservedResult: preservedResult)}");
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
                    string attributes = Attributes(parameter.GetCustomAttributes(), parameterEnums.GetValueOrDefault(parameter.SequenceNumber), nativeRetval);
                    rows.Add($"P|{parameter.SequenceNumber}|{reader.GetString(parameter.Name)}|{parameterAttributes}|" +
                        $"{Blob(parameter.GetMarshallingDescriptor())}|{attributes}");
                }
            }
            return string.Join("\n", rows);
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
