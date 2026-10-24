using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection.Metadata;
using System.Security.Cryptography;
using System.Text;
using MetadataTasks;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using Xunit;
using Xunit.Abstractions;

namespace Win32MetadataScraperTests
{
    public class SdkComponentMigrationTests
    {
        private static readonly Dictionary<string, string> Namespaces = new()
        {
            ["DirectML"] = "Windows.Win32.AI.MachineLearning.DirectML",
            ["Dedup"] = "Windows.Win32.Storage.DataDeduplication",
            ["RemoteAssist"] = "Windows.Win32.System.RemoteAssistance",
            ["Wsb"] = "Windows.Win32.System.ServerBackup",
        };
        private static readonly (string Target, string OS)[] Floors =
        {
            ("DMLCreateDevice", "windows10.0.10240"),
            ("IDedupBackupSupport", "windowsserver2012"),
            ("IDedupReadFileCallback", "windowsserver2012"),
            ("DRendezvousSessionEvents", "windows6.0.6000"),
            ("IRendezvousApplication", "windows6.0.6000"),
            ("IRendezvousSession", "windows6.0.6000"),
            ("IWsbApplicationAsync", "windowsserver2008"),
            ("IWsbApplicationBackupSupport", "windowsserver2008"),
            ("IWsbApplicationRestoreSupport", "windowsserver2008"),
            ("DeregisterOnlineBackupFromWindowsServerBackup", "windowsserver2012"),
            ("RegisterOnlineBackupWithWindowsServerBackup", "windowsserver2012"),
            ("UpdateOBStatusInWindowsServerBackup", "windowsserver2012"),
        };
        private static readonly Dictionary<string, string> NativeRetvals = new()
        {
            ["get_State"] = "pSessionState",
            ["get_RemoteUser"] = "bstrUserName",
            ["get_Flags"] = "pFlags",
        };
        private static readonly string[] SharedRpcFloors =
        {
            "BSTR_UserSize64", "BSTR_UserMarshal64", "BSTR_UserUnmarshal64", "BSTR_UserFree64",
            "VARIANT_UserSize64", "VARIANT_UserMarshal64", "VARIANT_UserUnmarshal64", "VARIANT_UserFree64",
        };
        private readonly ITestOutputHelper output;

        public SdkComponentMigrationTests(ITestOutputHelper output) => this.output = output;

        [HeaderMigrationDataFact]
        public void AvailableSourceFloorsAndDeferredRendezvousFactsKeepExactAccounting()
        {
            string sdk = Path.Combine(WinHttpMigrationTests.RepositoryRoot, "generation", "WinSDK");
            string sidecar = File.ReadAllText(Path.Combine(sdk, "supportedOS.rsp"));
            foreach (var fact in Floors)
                Assert.DoesNotContain(fact.Target + "=SupportedOSPlatform(", sidecar);
            foreach (string partition in Namespaces.Keys)
                HeaderMigrationAssertions.AssertAnnotationReaderEnabled(partition);
            Assert.Matches(@"_Win32_SupportedOS_10240_\s+STDAPI\s+DMLCreateDevice",
                HeaderMigrationAssertions.PatchedSource(@"um\DirectML.h"));
            foreach (string name in new[] { "IDedupBackupSupport", "IDedupReadFileCallback" })
                HeaderMigrationAssertions.AssertCommentFact(@"um\ddpbackup.idl", "interface", name,
                    "SupportedOSPlatform(\"windowsserver2012\")");
            foreach (string name in new[] { "IWsbApplicationAsync", "IWsbApplicationBackupSupport", "IWsbApplicationRestoreSupport" })
                HeaderMigrationAssertions.AssertCommentFact(@"um\wsbapp.idl", "interface", name,
                    "SupportedOSPlatform(\"windowsserver2008\")");
            foreach (var fact in Floors.Skip(9))
                Assert.Matches(@"_Win32_SupportedOS_Server2012_\s+HRESULT\s+WINAPI\s+" + fact.Target,
                    HeaderMigrationAssertions.PatchedSource(@"um\wsbonline.h"));
            Assert.Contains("_DEDUP_SET_PARAM_TYPE=DEDUP_SET_PARAM_TYPE",
                File.ReadAllText(Path.Combine(sdk, "scraper.settings.rsp")));
            Assert.DoesNotContain("--nativeFieldArrayInfo", File.ReadAllText(Path.Combine(sdk, "emitter.settings.rsp")));
            using var deferred = WinHttpMigrationTests.ReadSourceBlockedInventory();
            WinHttpMigrationTests.AssertSourceBlockedInventory(deferred.RootElement);
            var rendezvous = Assert.Single(deferred.RootElement.GetProperty("headers").EnumerateArray()
                .Where(header => header.GetProperty("path").GetString() == @"um\rendezvoussession.h"));
            Assert.Equal(Floors.Skip(3).Take(3).Select(fact => fact.Target + "=" + fact.OS)
                    .OrderBy(value => value, StringComparer.Ordinal),
                rendezvous.GetProperty("facts").EnumerateArray()
                    .Select(fact => fact.GetProperty("target").GetString() + "=" + fact.GetProperty("value").GetString())
                    .OrderBy(value => value, StringComparer.Ordinal));
        }

        [ComponentMigrationTheory]
        [InlineData("x86")]
        [InlineData("x64")]
        [InlineData("arm64")]
        public void PreparedSourcesHaveExactlyTheOwnedAndRetainedSharedFloors(string architecture)
        {
            var actual = new List<string>();
            foreach (string partition in Namespaces.Keys)
            {
                var root = CSharpSyntaxTree.ParseText(File.ReadAllText(Source("new-all-arch", architecture, partition))).GetRoot();
                foreach (var attribute in root.DescendantNodes().OfType<AttributeSyntax>()
                    .Where(attribute => ShortName(attribute.Name.ToString()) == "SupportedOSPlatform"))
                {
                    string name = attribute.Parent.Parent switch
                    {
                        MethodDeclarationSyntax method => method.Identifier.ValueText,
                        StructDeclarationSyntax type => type.Identifier.ValueText,
                        FieldDeclarationSyntax field => ((StructDeclarationSyntax)field.Parent).Identifier.ValueText +
                            "::" + Assert.Single(field.Declaration.Variables).Identifier.ValueText,
                        _ => throw new InvalidOperationException("An OS floor reached an unreviewed declaration target."),
                    };
                    string os = ((LiteralExpressionSyntax)Assert.Single(attribute.ArgumentList.Arguments).Expression).Token.ValueText;
                    actual.Add(name + "=" + os);
                }
                foreach (var method in root.DescendantNodes().OfType<MethodDeclarationSyntax>()
                    .Where(method => Floors.Skip(9).Any(fact => fact.Target == method.Identifier.ValueText)))
                {
                    var import = Assert.Single(method.AttributeLists.SelectMany(list => list.Attributes)
                        .Where(attribute => ShortName(attribute.Name.ToString()) == "DllImport"));
                    Assert.Equal("", ((LiteralExpressionSyntax)import.ArgumentList.Arguments[0].Expression).Token.ValueText);
                }
            }
            var expected = Floors.Select(fact => fact.Target + "=" + fact.OS)
                .Concat(SharedRpcFloors.Concat(SharedRpcFloors.Take(4)).Select(name => name + "=windows5.1.2600"))
                .Concat(new[]
                {
                    "DML_LOCAL_RESPONSE_NORMALIZATION_OPERATOR_DESC::LocalSize=windows5.1.2600",
                    "DML_LOCAL_RESPONSE_NORMALIZATION_GRAD_OPERATOR_DESC::LocalSize=windows5.1.2600",
                });
            Assert.Equal(expected.OrderBy(value => value), actual.OrderBy(value => value));
            this.output.WriteLine($"{architecture}: exactly 12 owned source floors; the three unmapped Wsb imports remain unmapped.");
        }

        [ComponentMigrationTheory]
        [InlineData("x86")]
        [InlineData("x64")]
        [InlineData("arm64")]
        public void ComponentEmissionPreservesRelocatedMetadataAndCapturesOnlyThreeNativeRetvals(string architecture)
        {
            using var legacy = EmitSelected("legacy-all-arch", architecture);
            using var activated = EmitSelected("activation-all-arch", architecture);
            using var current = EmitSelected("new-all-arch", architecture);
            var namespaces = new[] { legacy.Reader, activated.Reader, current.Reader }
                .SelectMany(reader => reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                    .Select(type => reader.GetString(type.Namespace)))
                .Where(ns => !string.IsNullOrEmpty(ns)).Distinct(StringComparer.Ordinal).OrderBy(ns => ns, StringComparer.Ordinal);
            foreach (string ns in namespaces)
            {
                var before = WinHttpMigrationTests.SnapshotNamespace(legacy.Reader, ns);
                var control = WinHttpMigrationTests.SnapshotNamespace(activated.Reader, ns);
                var after = WinHttpMigrationTests.SnapshotNamespace(current.Reader, ns);
                Assert.NotEmpty(before);
                Assert.Equal(control, after);
                string owner = Namespaces["RemoteAssist"] + ".IRendezvousSession\n";
                Assert.Equal(before.Select(snapshot => snapshot.StartsWith(owner, StringComparison.Ordinal)
                    ? AddExactNativeRetvals(snapshot) : snapshot), control);
                this.output.WriteLine($"{architecture}/{ns}: {after.Length} component physical types; activation=prepared SHA256 " +
                    Convert.ToHexString(SHA256.HashData(Encoding.UTF8.GetBytes(string.Join("\n", after)))));
            }

            var floors = new List<string>();
            var imports = new List<string>();
            foreach (var type in current.Reader.TypeDefinitions.Select(current.Reader.GetTypeDefinition))
            {
                if (!Namespaces.Values.Contains(current.Reader.GetString(type.Namespace)))
                    continue;
                foreach (string os in ReadOS(current.Reader, type.GetCustomAttributes()))
                    floors.Add(current.Reader.GetString(type.Name) + "=" + os);
                foreach (var method in type.GetMethods().Select(current.Reader.GetMethodDefinition))
                {
                    string name = current.Reader.GetString(method.Name);
                    foreach (string os in ReadOS(current.Reader, method.GetCustomAttributes()))
                        floors.Add(name + "=" + os);
                    var import = method.GetImport();
                    if (!import.Module.IsNil)
                        imports.Add(name + "=" + current.Reader.GetString(current.Reader.GetModuleReference(import.Module).Name) +
                            ":" + current.Reader.GetString(import.Name));
                    Assert.DoesNotContain(Floors.Skip(9), fact => fact.Target == name);
                }
            }
            Assert.Equal(Floors.Take(9).Select(fact => fact.Target + "=" + fact.OS).OrderBy(value => value),
                floors.OrderBy(value => value));
            Assert.Equal(new[] { "DMLCreateDevice=DirectML.dll:DMLCreateDevice", "DMLCreateDevice1=DirectML.dll:DMLCreateDevice1" },
                imports.OrderBy(value => value));
        }

        [ComponentMigrationTheory]
        [InlineData("x86")]
        [InlineData("x64")]
        [InlineData("arm64")]
        public void SameInputRepeatedScrapePreservesSourcesAndDiscoveryBytes(string architecture)
        {
            foreach (string partition in Namespaces.Keys)
            {
                Assert.Equal(File.ReadAllBytes(Source("new-all-arch", architecture, partition)),
                    File.ReadAllBytes(Source("repeat-all-arch", architecture, partition)));
                string relative = Path.Combine("obj", "scratch", architecture, partition + ".remaps");
                Assert.Equal(File.ReadAllBytes(Path.Combine(ArtifactRoot, "new-all-arch", relative)),
                    File.ReadAllBytes(Path.Combine(ArtifactRoot, "repeat-all-arch", relative)));
            }
            foreach (string name in new[] { "scraper.autoRemaps.generated.rsp", "emitter.autoFnPtr.crossarch.generated.rsp" })
            {
                Assert.Equal(File.ReadAllBytes(Path.Combine(ArtifactRoot, "new-all-arch", "obj", "generated", name)),
                    File.ReadAllBytes(Path.Combine(ArtifactRoot, "repeat-all-arch", "obj", "generated", name)));
            }
        }

        private static string ArtifactRoot => Environment.GetEnvironmentVariable("SDK_COMPONENT_MIGRATION_ROOT")
            ?? throw new InvalidOperationException("SDK_COMPONENT_MIGRATION_ROOT was not supplied.");

        private static string Source(string leg, string architecture, string partition)
            => Path.Combine(ArtifactRoot, leg, "obj", "generated", architecture, partition + ".cs");

        private static HeaderAnnotationWinmdTests.MetadataImage EmitSelected(string leg, string architecture)
        {
            string directory = Path.Combine(ArtifactRoot, "component-emitter", leg, architecture);
            Directory.CreateDirectory(directory);
            foreach (string partition in Namespaces.Keys)
                File.Copy(Source(leg, architecture, partition), Path.Combine(directory, partition + ".cs"), overwrite: true);
            var reductions = File.ReadLines(Path.Combine(ArtifactRoot, leg, "obj", "generated",
                "emitter.autoFnPtr.crossarch.generated.rsp")).Where(line => !line.StartsWith("--", StringComparison.Ordinal))
                .Where(line => !string.IsNullOrWhiteSpace(line)).ToHashSet(StringComparer.Ordinal);
            var requiredNamespaces = RspReader.GetSettingsValues(Path.Combine(WinHttpMigrationTests.RepositoryRoot,
                    "generation", "WinSDK", "requiredNamespacesForNames.rsp"), "--requiredNamespaceForName")
                .Where(line => !line.StartsWith("#", StringComparison.Ordinal))
                .Select(line => line.Split('=', 2)).ToDictionary(parts => parts[0], parts => parts[1], StringComparer.Ordinal);
            // Frozen OLD supplies external types only; these are bounded component images, not full-SDK acceptance.
            return HeaderAnnotationWinmdTests.Emit(directory, architecture, reductions,
                references: new[] { Environment.GetEnvironmentVariable("WINHTTP_MIGRATION_OLD") },
                requiredNamespaces: requiredNamespaces);
        }

        private static string AddExactNativeRetvals(string snapshot)
        {
            const string attribute = "Windows.Win32.Foundation.Metadata.RetValAttribute:01000000";
            var rows = snapshot.Split('\n');
            string method = null;
            var used = new HashSet<string>(StringComparer.Ordinal);
            for (int i = 0; i < rows.Length; i++)
            {
                var fields = rows[i].Split('|');
                if (fields[0] == "M")
                    method = fields[1];
                if (fields[0] != "P" || method == null || !NativeRetvals.TryGetValue(method, out string parameter) ||
                    fields[2] != parameter)
                    continue;
                Assert.Equal("1", fields[1]);
                var attributes = fields[5].Split(',', StringSplitOptions.RemoveEmptyEntries);
                Assert.DoesNotContain(attribute, attributes);
                fields[5] = string.Join(",", attributes.Append(attribute).OrderBy(value => value, StringComparer.Ordinal));
                rows[i] = string.Join("|", fields);
                Assert.True(used.Add(method));
            }
            Assert.Equal(NativeRetvals.Keys.OrderBy(value => value), used.OrderBy(value => value));
            return string.Join("\n", rows);
        }

        private static IEnumerable<string> ReadOS(MetadataReader reader, CustomAttributeHandleCollection attributes)
        {
            foreach (var handle in attributes)
            {
                var attribute = reader.GetCustomAttribute(handle);
                var constructor = attribute.Constructor;
                var owner = constructor.Kind == HandleKind.MemberReference
                    ? reader.GetMemberReference((MemberReferenceHandle)constructor).Parent
                    : reader.GetMethodDefinition((MethodDefinitionHandle)constructor).GetDeclaringType();
                string name = owner.Kind == HandleKind.TypeReference
                    ? reader.GetString(reader.GetTypeReference((TypeReferenceHandle)owner).Name)
                    : reader.GetString(reader.GetTypeDefinition((TypeDefinitionHandle)owner).Name);
                if (name != "SupportedOSPlatformAttribute")
                    continue;
                var blob = reader.GetBlobReader(attribute.Value);
                Assert.Equal(1, blob.ReadUInt16());
                string os = blob.ReadSerializedString();
                Assert.Equal(0, blob.ReadUInt16());
                Assert.Equal(0, blob.RemainingBytes);
                yield return os;
            }
        }

        private static string ShortName(string name)
            => name.Split('.').Last().Replace("Attribute", "", StringComparison.Ordinal);
    }

    public sealed class ComponentMigrationTheoryAttribute : HeaderMigrationDataTheoryAttribute
    {
        public ComponentMigrationTheoryAttribute()
        {
            if (Skip != null)
                return;
            if (Environment.GetEnvironmentVariable("SDK_COMPONENT_MIGRATION_ROOT") == null ||
                Environment.GetEnvironmentVariable("WINHTTP_MIGRATION_OLD") == null)
                Skip = "Set SDK_COMPONENT_MIGRATION_ROOT and WINHTTP_MIGRATION_OLD to the immutable bounded migration evidence.";
        }
    }
}
