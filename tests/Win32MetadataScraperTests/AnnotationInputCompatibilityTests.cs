using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using MetadataTasks;
using Xunit;

namespace Win32MetadataScraperTests
{
    public class AnnotationInputCompatibilityTests
    {
        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc")]
        [InlineData("x64", "x86_64-pc-windows-msvc")]
        [InlineData("arm64", "aarch64-pc-windows-msvc")]
        public void LegacyHeaderAndMixedInputsPreserveTheSamePhysicalContract(string architecture, string target)
        {
            var snapshots = new Dictionary<string, string[]>(StringComparer.Ordinal);
            foreach (var input in new[]
            {
                (Name: "legacy-reader-off", HeaderFloor: false, HeaderOnly: false, ReaderEnabled: false),
                (Name: "legacy-reader-on", HeaderFloor: false, HeaderOnly: false, ReaderEnabled: true),
                (Name: "header", HeaderFloor: true, HeaderOnly: true, ReaderEnabled: true),
                (Name: "mixed", HeaderFloor: true, HeaderOnly: false, ReaderEnabled: true),
            })
            {
                string declarations = "extern \"C\" {\n" +
                    (input.HeaderFloor ? "_Win32_SupportedOS_Windows7_ " : "") +
                    (input.HeaderOnly ? "_Win32_SetLastError_ " : "") +
                    "int __stdcall ReadValue(_In_opt_ " + (input.HeaderOnly ? "_Win32_Reserved_ " : "") +
                    "void* reserved);\n}";
                using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, declarations,
                    annotationsEnabled: input.ReaderEnabled,
                    extraSettings: input.HeaderOnly ? "" : "--with-setlasterror\nReadValue\n",
                    directoryRoot: Path.Combine(Directory.GetCurrentDirectory(), "artifacts", "annotation-input-compatibility"));
                string sidecar = Path.Combine(fixture.DirectoryPath, "legacy.emitter.rsp");
                File.WriteAllText(sidecar, "--memberRemap\n" +
                    (input.HeaderFloor ? "" : "ReadValue=[SupportedOSPlatform(\"windows6.1\")]\n") +
                    (input.HeaderOnly ? "" : "ReadValue::reserved=[Reserved]\n"));
                var remaps = RspReader.GetSettingsValues(sidecar, "--memberRemap")
                    .Select(line => line.Split('=', 2))
                    .ToDictionary(parts => parts[0], parts => parts[1], StringComparer.Ordinal);

                Assert.True(fixture.Run() == 0, input.Name + ": " + fixture.Diagnostics);
                using var image = HeaderAnnotationWinmdTests.Emit(fixture.DirectoryPath, architecture, memberRemaps: remaps);
                var reader = image.Reader;
                var api = Assert.Single(reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                    .Where(type => reader.GetString(type.Namespace) == "Test" && reader.GetString(type.Name) == "Apis"));
                var method = reader.GetMethodDefinition(Assert.Single(api.GetMethods()));
                Assert.Equal("ReadValue", reader.GetString(method.Name));
                var signature = method.DecodeSignature(new HeaderAnnotationWinmdTests.SignatureNames(), null);
                Assert.Equal("Int32", signature.ReturnType);
                Assert.Equal(new[] { "Void*" }, signature.ParameterTypes);
                var import = method.GetImport();
                Assert.Equal("scan.dll", reader.GetString(reader.GetModuleReference(import.Module).Name));
                Assert.Equal("ReadValue", reader.GetString(import.Name));
                Assert.True(import.Attributes.HasFlag(MethodImportAttributes.SetLastError));
                var floor = reader.GetCustomAttribute(Assert.Single(method.GetCustomAttributes()
                    .Where(handle => HeaderAnnotationWinmdTests.AttributeName(reader, handle) == "SupportedOSPlatformAttribute")));
                var blob = reader.GetBlobReader(floor.Value);
                Assert.Equal(1, blob.ReadUInt16());
                Assert.Equal("windows6.1", blob.ReadSerializedString());
                Assert.Equal(0, blob.ReadUInt16());
                Assert.Equal(0, blob.RemainingBytes);
                var parameter = reader.GetParameter(Assert.Single(method.GetParameters()));
                Assert.Equal("reserved", reader.GetString(parameter.Name));
                Assert.Equal(1, parameter.SequenceNumber);
                Assert.Equal(ParameterAttributes.In | ParameterAttributes.Optional, parameter.Attributes);
                Assert.Single(parameter.GetCustomAttributes().Where(handle =>
                    HeaderAnnotationWinmdTests.AttributeName(reader, handle) == "ReservedAttribute"));
                WinHttpMigrationTests.AssertClosure(reader);
                snapshots.Add(input.Name, WinHttpMigrationTests.SnapshotNamespace(reader, "Test"));
            }

            Assert.NotEmpty(snapshots["legacy-reader-off"]);
            foreach (string name in new[] { "legacy-reader-on", "header", "mixed" })
                Assert.Equal(snapshots["legacy-reader-off"], snapshots[name]);
        }
    }
}
