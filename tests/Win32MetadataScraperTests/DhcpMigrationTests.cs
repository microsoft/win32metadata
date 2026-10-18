using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection.Metadata;
using System.Reflection.PortableExecutable;
using System.Text.RegularExpressions;
using Xunit;

namespace Win32MetadataScraperTests
{
    public class DhcpMigrationTests
    {
        private const string Namespace = "Windows.Win32.NetworkManagement.Dhcp";
        // Native SAL names NumElements; replacing this legacy index needs scoped field-array inference.
        private const string HeldArray = "DHCP_IP_ARRAY::Elements=[NativeArrayInfo(CountParamIndex=0)]";

        internal static IEnumerable<(string Header, string OS, string[] Functions)> HeaderContracts()
        {
            yield return ("DhcpCSdk.h", "windows5.0", Words(@"
DhcpCApiInitialize DhcpCApiCleanup DhcpRequestParams DhcpUndoRequestParams
DhcpRegisterParamChange DhcpDeRegisterParamChange DhcpRemoveDNSRegistrations"));
            yield return ("Dhcpv6cSdk.h", "windows6.0.6000", Words(@"
Dhcpv6CApiInitialize Dhcpv6CApiCleanup Dhcpv6RequestParams Dhcpv6RequestPrefix
Dhcpv6RenewPrefix Dhcpv6ReleasePrefix"));
            yield return ("dhcpsapi.h", "windowsserver2000", Words(@"
DhcpCreateSubnet DhcpSetSubnetInfo DhcpGetSubnetInfo DhcpEnumSubnets
DhcpEnumSubnetElements DhcpDeleteSubnet DhcpGetOptionValue DhcpCreateClientInfo
DhcpSetClientInfo DhcpGetClientInfo DhcpDeleteClientInfo DhcpEnumSubnetClients
DhcpRpcFreeMemory DhcpGetVersion DhcpEnumSubnetElementsV4 DhcpSetOptionValueV5
DhcpRemoveOptionValueV5 DhcpEnumServers DhcpAddServer DhcpDeleteServer
DhcpGetServerBindingInfo DhcpSetServerBindingInfo DhcpAddSubnetElementV5
DhcpEnumSubnetElementsV5 DhcpRemoveSubnetElementV5 DhcpDsInit DhcpDsCleanup
DhcpServerRedoAuthorization"));
            yield return ("dhcpsapi.h", "windowsserver2008", Words(@"
DhcpAddFilterV4 DhcpDeleteFilterV4 DhcpSetFilterV4 DhcpGetFilterV4 DhcpEnumFilterV4
DhcpAddSubnetElement DhcpRemoveSubnetElement DhcpCreateOption DhcpSetOptionInfo
DhcpGetOptionInfo DhcpEnumOptions DhcpRemoveOption DhcpSetOptionValue
DhcpSetOptionValues DhcpEnumOptionValues DhcpRemoveOptionValue
DhcpCreateClientInfoVQ DhcpSetClientInfoVQ DhcpGetClientInfoVQ DhcpEnumSubnetClientsVQ
DhcpEnumSubnetClientsFilterStatusInfo DhcpGetClientOptions DhcpServerSetConfig
DhcpServerGetConfig DhcpScanDatabase DhcpAddSubnetElementV4 DhcpRemoveSubnetElementV4
DhcpCreateClientInfoV4 DhcpSetClientInfoV4 DhcpGetClientInfoV4 DhcpEnumSubnetClientsV4
DhcpServerSetConfigV4 DhcpServerGetConfigV4 DhcpSetSuperScopeV4 DhcpDeleteSuperScopeV4
DhcpGetSuperScopeInfoV4 DhcpEnumSubnetClientsV5 DhcpCreateOptionV5 DhcpSetOptionInfoV5
DhcpGetOptionInfoV5 DhcpEnumOptionsV5 DhcpRemoveOptionV5 DhcpSetOptionValuesV5
DhcpGetOptionValueV5 DhcpGetOptionValueV6 DhcpEnumOptionValuesV5 DhcpCreateClass
DhcpModifyClass DhcpDeleteClass DhcpGetClassInfo DhcpEnumClasses DhcpGetAllOptions
DhcpGetAllOptionsV6 DhcpGetAllOptionValues DhcpGetAllOptionValuesV6 DhcpCreateOptionV6
DhcpRemoveOptionV6 DhcpEnumOptionsV6 DhcpRemoveOptionValueV6 DhcpGetOptionInfoV6
DhcpSetOptionInfoV6 DhcpSetOptionValueV6 DhcpGetSubnetInfoVQ DhcpCreateSubnetVQ
DhcpSetSubnetInfoVQ DhcpEnumOptionValuesV6 DhcpSetThreadOptions DhcpGetThreadOptions
DhcpServerQueryAttribute DhcpServerQueryAttributes DhcpAuditLogSetParams
DhcpAuditLogGetParams DhcpServerQueryDnsRegCredentials DhcpServerSetDnsRegCredentialsV5
DhcpServerBackupDatabase DhcpServerRestoreDatabase DhcpServerSetConfigVQ
DhcpServerGetConfigVQ DhcpGetServerSpecificStrings DhcpCreateSubnetV6 DhcpDeleteSubnetV6
DhcpEnumSubnetsV6 DhcpAddSubnetElementV6 DhcpRemoveSubnetElementV6 DhcpEnumSubnetElementsV6
DhcpGetSubnetInfoV6 DhcpEnumSubnetClientsV6 DhcpServerGetConfigV6 DhcpServerSetConfigV6
DhcpSetSubnetInfoV6 DhcpGetMibInfoV6 DhcpGetServerBindingInfoV6 DhcpSetServerBindingInfoV6
DhcpSetClientInfoV6 DhcpGetClientInfoV6 DhcpDeleteClientInfoV6 DhcpCreateClassV6
DhcpModifyClassV6 DhcpDeleteClassV6 DhcpEnumClassesV6 DhcpSetSubnetDelayOffer
DhcpGetSubnetDelayOffer DhcpGetMibInfoV5"));
            yield return ("dhcpsapi.h", "windowsserver2012", Words(@"
DhcpV4EnumSubnetReservations DhcpV4GetOptionValue DhcpV4SetOptionValue
DhcpV4SetOptionValues DhcpV4RemoveOptionValue DhcpV4GetAllOptionValues
DhcpV4FailoverCreateRelationship DhcpV4FailoverSetRelationship DhcpV4FailoverDeleteRelationship
DhcpV4FailoverGetRelationship DhcpV4FailoverEnumRelationship DhcpV4FailoverAddScopeToRelationship
DhcpV4FailoverDeleteScopeFromRelationship DhcpV4FailoverGetScopeRelationship
DhcpV4FailoverGetScopeStatistics DhcpV4FailoverGetClientInfo DhcpV4FailoverGetSystemTime
DhcpV4FailoverGetAddressStatus DhcpV4FailoverTriggerAddrAllocation DhcpHlprCreateV4Policy
DhcpHlprAddV4PolicyExpr DhcpHlprAddV4PolicyCondition DhcpHlprAddV4PolicyRange
DhcpHlprResetV4PolicyExpr DhcpHlprModifyV4PolicyExpr DhcpHlprFreeV4Policy
DhcpHlprIsV4PolicySingleUC DhcpV4QueryPolicyEnforcement DhcpV4SetPolicyEnforcement
DhcpHlprIsV4PolicyWellFormed DhcpHlprIsV4PolicyValid DhcpV4CreatePolicy DhcpV4GetPolicy
DhcpV4SetPolicy DhcpV4DeletePolicy DhcpV4EnumPolicies DhcpV4AddPolicyRange
DhcpV4RemovePolicyRange DhcpV6SetStatelessStoreParams DhcpV6GetStatelessStoreParams
DhcpV6GetStatelessStatistics DhcpV4CreateClientInfo DhcpV4EnumSubnetClients
DhcpV4GetClientInfo DhcpV6CreateClientInfo DhcpV4GetFreeIPAddress DhcpV6GetFreeIPAddress"));
        }

        [Fact]
        public void OriginalHeaderPatchesCarryEveryFloorAndKeepOnlyTheExplicitArrayResidual()
        {
            string sdk = Path.Combine(WinHttpMigrationTests.RepositoryRoot, "generation", "WinSDK");
            var contracts = HeaderContracts().ToArray();
            Assert.Equal(191, contracts.Sum(contract => contract.Functions.Length));
            Assert.Equal(191, contracts.SelectMany(contract => contract.Functions).Distinct(StringComparer.Ordinal).Count());
            foreach (var header in contracts.GroupBy(contract => contract.Header))
            {
                string patch = File.ReadAllText(Path.Combine(sdk, "patches", "um", header.Key + ".patch"));
                Assert.DoesNotContain("_Win32_SupportedOS_BEGIN_", patch);
                Assert.DoesNotContain("_Win32_SupportedOS_END_", patch);
                Assert.Equal(header.Sum(contract => contract.Functions.Length),
                    Regex.Matches(patch, @"(?m)^\+_Win32_SupportedOS_\w+_\r?$").Count);
            }
            var platforms = File.ReadLines(Path.Combine(sdk, "supportedOS.rsp"))
                .Select(line => line.Split('=')[0]).ToHashSet(StringComparer.Ordinal);
            foreach (string function in contracts.SelectMany(contract => contract.Functions))
                Assert.DoesNotContain(function, platforms);
            Assert.Equal(1, File.ReadAllText(Path.Combine(sdk, "Partitions", "Dhcp", "settings.rsp"))
                .Split("parse-win32-annotations").Length - 1);
            string emitter = File.ReadAllText(Path.Combine(sdk, "emitter.settings.rsp"));
            Assert.Single(emitter.Split(new[] { '\r', '\n' }, StringSplitOptions.RemoveEmptyEntries)
                .Where(line => line == HeldArray));
            Assert.DoesNotContain("--nativeFieldArrayInfo", emitter);
        }

        [MigrationFact]
        public void WholeDhcpMetadataPreservesEveryPhysicalContractAndAll191SourceFloors()
        {
            using var beforeStream = File.OpenRead(Environment.GetEnvironmentVariable("WINHTTP_MIGRATION_OLD"));
            using var afterStream = File.OpenRead(Environment.GetEnvironmentVariable("WINHTTP_MIGRATION_NEW"));
            using var beforeImage = new PEReader(beforeStream);
            using var afterImage = new PEReader(afterStream);
            var before = beforeImage.GetMetadataReader();
            var after = afterImage.GetMetadataReader();
            Assert.Equal(WinHttpMigrationTests.SnapshotNamespace(before, Namespace),
                WinHttpMigrationTests.SnapshotNamespace(after, Namespace));
            var expected = HeaderContracts().SelectMany(contract => contract.Functions
                .Select(name => (Name: name, contract.OS))).ToDictionary(contract => contract.Name, contract => contract.OS);
            var methods = after.TypeDefinitions.Select(after.GetTypeDefinition)
                .Where(type => after.GetString(type.Namespace) == Namespace && after.GetString(type.Name) == "Apis")
                .SelectMany(type => type.GetMethods()).Select(after.GetMethodDefinition).ToArray();
            Assert.Equal(210, methods.Select(method => after.GetString(method.Name)).Distinct(StringComparer.Ordinal).Count());
            var observed = new HashSet<string>(StringComparer.Ordinal);
            foreach (var method in methods)
            {
                string name = after.GetString(method.Name);
                var floors = method.GetCustomAttributes().Select(after.GetCustomAttribute).Where(attribute =>
                {
                    var constructor = attribute.Constructor;
                    var parent = constructor.Kind == HandleKind.MethodDefinition
                        ? after.GetMethodDefinition((MethodDefinitionHandle)constructor).GetDeclaringType()
                        : after.GetMemberReference((MemberReferenceHandle)constructor).Parent;
                    string attributeName = parent.Kind switch
                    {
                        HandleKind.TypeDefinition => after.GetString(after.GetTypeDefinition((TypeDefinitionHandle)parent).Name),
                        HandleKind.TypeReference => after.GetString(after.GetTypeReference((TypeReferenceHandle)parent).Name),
                        _ => throw new InvalidOperationException("Unsupported custom attribute owner."),
                    };
                    return attributeName == "SupportedOSPlatformAttribute";
                }).ToArray();
                if (!expected.TryGetValue(name, out string os))
                {
                    Assert.Empty(floors);
                    continue;
                }
                var blob = after.GetBlobReader(Assert.Single(floors).Value);
                Assert.Equal(1, blob.ReadUInt16());
                Assert.Equal(os, blob.ReadSerializedString());
                Assert.Equal(0, blob.ReadUInt16());
                Assert.Equal(0, blob.RemainingBytes);
                observed.Add(name);
            }
            Assert.Equal(expected.Keys.OrderBy(name => name, StringComparer.Ordinal),
                observed.OrderBy(name => name, StringComparer.Ordinal));
        }

        private static string[] Words(string value)
            => value.Split(new[] { ' ', '\r', '\n' }, StringSplitOptions.RemoveEmptyEntries);
    }
}
