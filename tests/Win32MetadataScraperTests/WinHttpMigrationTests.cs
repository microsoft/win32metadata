using System;
using System.Collections.Generic;
using System.Collections.Immutable;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Reflection.Metadata;
using System.Reflection.Metadata.Ecma335;
using System.Reflection.PortableExecutable;
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
            }).ToArray();
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
        };
        private static readonly string[] AdditionalLogicalEnums =
        {
            "VERIFIER_ENUM_RESOURCE_FLAGS", "ENUM_PROCESS_MODULES_EX_FLAGS", "MW_FILTERMODE",
            "CREATE_TOOLHELP_SNAPSHOT_FLAGS", "HEAPENTRY32_FLAGS",
            "XINPUT_VIRTUAL_KEY", "BATTERY_TYPE", "BATTERY_LEVEL", "BATTERY_DEVTYPE",
            "XINPUT_DEVTYPE", "XINPUT_DEVSUBTYPE", "XINPUT_CAPABILITIES_FLAGS",
            "XINPUT_GAMEPAD_BUTTON_FLAGS", "XINPUT_KEYSTROKE_FLAGS", "XINPUT_FLAG",
        };

        public WinHttpMigrationTests(ITestOutputHelper output) => this.output = output;

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
            int unchanged = 0;
            foreach (var entry in before)
            {
                string expected = SnapshotType(control.Reader, entry.Value, normalizeReviewedChanges: true,
                    usedEnumSites: used, usedRetvalSites: usedRetvals);
                string actual = SnapshotType(current.Reader, after[entry.Key]);
                Assert.True(expected == actual, $"Unexpected physical metadata change in {entry.Key}.\nExpected:\n{expected}\nActual:\n{actual}");
                unchanged += SnapshotType(control.Reader, entry.Value) == actual ? 1 : 0;
            }
            Assert.Equal(ReviewedEnumUses.Select(value => value.Site).OrderBy(value => value), used.OrderBy(value => value));
            Assert.Equal(NativeRetvalUses.Select(value => $"{value.Namespace}.{value.Owner}.{value.Method}.{value.Parameter}")
                .OrderBy(value => value), usedRetvals.OrderBy(value => value));
            this.output.WriteLine($"All {before.Count} physical types graded: {unchanged} unchanged; " +
                $"{used.Count} exact native-type/AssociatedEnum sites and {usedRetvals.Count} native MIDL retval sites normalized.");
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
                "Wcm", "InputRadial", "WinContacts", "WinLocation" })
                Assert.Contains("parse-win32-annotations", File.ReadAllText(Path.Combine(project, "Partitions", partition, "settings.rsp")));
            Assert.DoesNotContain("--with-librarypath", File.ReadAllText(Path.Combine(project, "Partitions", "Wsl", "settings.rsp")));
            foreach (string partition in new[] { "PsApi2" })
                Assert.DoesNotContain("parse-win32-annotations", File.ReadAllText(Path.Combine(project, "Partitions", partition, "settings.rsp")));
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

        internal static string SnapshotType(MetadataReader reader, TypeDefinition type, bool correctConstructorInstanceBits = false,
            bool normalizeReviewedChanges = false, ISet<string> usedEnumSites = null, ISet<string> usedRetvalSites = null)
        {
            string Attributes(CustomAttributeHandleCollection values, string associatedEnum = null, bool nativeRetval = false)
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
                var parameterEnums = new Dictionary<int, string>();
                foreach (var use in uses.Where(value => typeName == "Apis" && value.Owner == methodName))
                {
                    var parameter = parameters.Single(value => reader.GetString(value.Name) == use.Member);
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
                rows.Add($"M|{methodName}|{method.Attributes}|{method.ImplAttributes}|{Signature(signature, header, parameterTypes)}|" +
                    $"{Import(reader, method)}|{Attributes(method.GetCustomAttributes())}");
                foreach (var parameter in parameters)
                {
                    string parameterName = reader.GetString(parameter.Name);
                    bool nativeRetval = normalizeReviewedChanges && NativeRetvalUses.Contains((ns, typeName, methodName, parameterName));
                    if (nativeRetval)
                        usedRetvalSites?.Add($"{ns}.{typeName}.{methodName}.{parameterName}");
                    string attributes = Attributes(parameter.GetCustomAttributes(), parameterEnums.GetValueOrDefault(parameter.SequenceNumber), nativeRetval);
                    rows.Add($"P|{parameter.SequenceNumber}|{reader.GetString(parameter.Name)}|{parameter.Attributes}|" +
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

        private static TypeDefinition Type(MetadataReader reader, string name, int architecture)
            => reader.TypeDefinitions.Select(reader.GetTypeDefinition).Single(type => reader.GetString(type.Namespace) == WinHttpNamespace &&
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

        private static string Signature(MethodSignature<string> signature, int? header = null, IEnumerable<string> parameterTypes = null)
            => $"{header ?? signature.Header.RawValue}|{signature.GenericParameterCount}|{signature.RequiredParameterCount}|{signature.ReturnType}|" +
                string.Join(",", parameterTypes ?? signature.ParameterTypes);

        private sealed record EnumUse(string Namespace, string Owner, string Member, string Enum, string Native)
        {
            internal string Site => Namespace + "." + Owner + "::" + Member;
            internal string OldType => Namespace + "." + Enum + new string('*', Native.Length - Native.TrimEnd('*').Length);
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
        public MigrationFactAttribute()
        {
            if (Environment.GetEnvironmentVariable("WINHTTP_MIGRATION_OLD") == null ||
                Environment.GetEnvironmentVariable("WINHTTP_MIGRATION_NEW") == null ||
                Environment.GetEnvironmentVariable("WINHTTP_MIGRATION_TOOLING_CONTROL") == null)
                Skip = "Set WINHTTP_MIGRATION_OLD, WINHTTP_MIGRATION_NEW and WINHTTP_MIGRATION_TOOLING_CONTROL to the pinned full-image fixtures.";
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
