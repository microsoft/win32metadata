using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Reflection.Emit;
using System.Reflection.Metadata;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Text.Json;
using ClangSharpSourceToWinmd;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using Xunit;

namespace Win32MetadataScraperTests
{
    public class WdsPackingLayoutTests
    {
        private const string Namespace = "Windows.Win32.System.DeploymentServices.";
        private static readonly string[] OuterNames =
        {
            "PXE_DHCP_OPTION", "PXE_DHCPV6_MESSAGE_HEADER", "PXE_DHCPV6_MESSAGE", "PXE_DHCPV6_RELAY_MESSAGE",
        };
        private static readonly string[] ClosureNames = OuterNames.Append("PXE_DHCPV6_OPTION").ToArray();

        [NativeMigrationTheory("WDS_PACKING_LAYOUT_ROOT")]
        [InlineData("x86")]
        [InlineData("x64")]
        [InlineData("arm64")]
        public void FourWdsOuterRecordsKeepCompleteNativeAndManagedLayoutWithoutPackingOverrides(string architecture)
        {
            string root = Environment.GetEnvironmentVariable("WDS_PACKING_LAYOUT_ROOT");
            string previous = Path.Combine(Path.GetDirectoryName(root), "dhcp-existing-nonfloor-05");
            using var native = JsonDocument.Parse(File.ReadAllText(Path.Combine(root, "native-layout-" + architecture + ".json")));
            Assert.True(native.RootElement.GetProperty("originalAndCandidateIdentical").GetBoolean());
            Assert.Equal(architecture == "x86" ? 4 : 8, native.RootElement.GetProperty("pointerSize").GetInt32());
            using var baseline = JsonDocument.Parse(File.ReadAllText(Path.Combine(previous, "frozen-baseline-types.json")));
            string baselinePath = baseline.RootElement.GetProperty("path").GetString();
            using var accepted = new HeaderAnnotationWinmdTests.MetadataImage(baselinePath);
            string directory = Path.Combine(root, "physical", architecture, Guid.NewGuid().ToString("N"));
            string sourcePath = Path.Combine(previous, "scrape-" + architecture, "generated", architecture, "Wds.cs");
            var source = CSharpSyntaxTree.ParseText(File.ReadAllText(sourcePath)).GetCompilationUnitRoot();
            var namespaces = source.Members.OfType<NamespaceDeclarationSyntax>().Select(ns =>
                ns.WithMembers(SyntaxFactory.List<MemberDeclarationSyntax>(ns.Members.OfType<StructDeclarationSyntax>()
                    .Where(type => ClosureNames.Contains(type.Identifier.ValueText)))))
                .Where(ns => ns.Members.Count != 0).ToArray();
            Assert.Equal(ClosureNames.OrderBy(value => value), namespaces.SelectMany(ns => ns.Members)
                .OfType<StructDeclarationSyntax>().Select(type => type.Identifier.ValueText).OrderBy(value => value));
            var bounded = source.WithMembers(SyntaxFactory.List<MemberDeclarationSyntax>(namespaces));
            var control = Emit("legacy", OuterNames.ToDictionary(name => name,
                _ => "[StructLayout(LayoutKind.Sequential, Pack = 1)]"));
            var candidate = Emit("candidate", new Dictionary<string, string>());
            using var oldImage = control.Image;
            using var newImage = candidate.Image;
            var wrapperModule = AssemblyBuilder.DefineDynamicAssembly(
                new AssemblyName("WdsPackingWitness" + Guid.NewGuid().ToString("N")), AssemblyBuilderAccess.RunAndCollect)
                .DefineDynamicModule("Witnesses");
            var wrappers = new Dictionary<(Type, bool), Type>();
            var observed = new Dictionary<string, object>();
            var measured = new Dictionary<string, Dictionary<string, object>>();
            foreach (string name in ClosureNames)
            {
                var oldType = Find(oldImage.Reader, name);
                var newType = Find(newImage.Reader, name);
                var acceptedType = Find(accepted.Reader, name);
                Assert.Equal(OuterNames.Contains(name) ? 0 : 1, newType.GetLayout().PackingSize);
                Assert.Equal(1, oldType.GetLayout().PackingSize);
                Assert.Equal(acceptedType.Attributes, oldType.Attributes);
                Assert.Equal(acceptedType.GetLayout().PackingSize, oldType.GetLayout().PackingSize);
                Assert.Equal(acceptedType.GetLayout().Size, oldType.GetLayout().Size);
                var oldRows = WinHttpMigrationTests.SnapshotType(oldImage.Reader, oldType).Split('\n');
                var newRows = WinHttpMigrationTests.SnapshotType(newImage.Reader, newType).Split('\n');
                var header = oldRows[1].Split('|');
                header[2] = newType.GetLayout().PackingSize.ToString();
                oldRows[1] = string.Join("|", header);
                Assert.Equal(oldRows, newRows);
                var oldFields = oldType.GetFields().Select(oldImage.Reader.GetFieldDefinition).ToArray();
                var newFields = newType.GetFields().Select(newImage.Reader.GetFieldDefinition).ToArray();
                var acceptedFields = acceptedType.GetFields().Select(accepted.Reader.GetFieldDefinition).ToArray();
                Assert.Equal(acceptedFields.Length, oldFields.Length);
                var oldClr = control.Clr.GetType(Namespace + name, throwOnError: true);
                var newClr = candidate.Clr.GetType(Namespace + name, throwOnError: true);
                Assert.Equal(oldType.GetLayout().PackingSize, oldClr.StructLayoutAttribute.Pack);
                Assert.Equal(newType.GetLayout().PackingSize, newClr.StructLayoutAttribute.Pack);
                Assert.Equal(oldFields.Length, oldClr.GetFields(BindingFlags.Public | BindingFlags.Instance).Length);
                Assert.Equal(newFields.Length, newClr.GetFields(BindingFlags.Public | BindingFlags.Instance).Length);
                var shapes = new Dictionary<string, object>();
                for (int index = 0; index < oldFields.Length; ++index)
                {
                    string fieldName = oldImage.Reader.GetString(oldFields[index].Name);
                    Assert.Equal(fieldName, accepted.Reader.GetString(acceptedFields[index].Name));
                    Assert.Equal(acceptedFields[index].Attributes, oldFields[index].Attributes);
                    Assert.Equal(acceptedFields[index].GetOffset(), oldFields[index].GetOffset());
                    var oldShape = Shape(oldImage.Reader, oldFields[index]);
                    var newShape = Shape(newImage.Reader, newFields[index]);
                    Assert.Equal(Shape(accepted.Reader, acceptedFields[index]), oldShape);
                    Assert.Equal(oldShape, newShape);
                    Assert.Equal(oldShape, ClrShape(oldClr.GetField(fieldName)));
                    Assert.Equal(newShape, ClrShape(newClr.GetField(fieldName)));
                    shapes.Add(fieldName, new
                    {
                        oldShape.Atom,
                        oldShape.Rank,
                        oldShape.Extent,
                        arrayLowerBound = oldShape.Rank == 0 ? (int?)null : 0,
                        acceptedSignatureBlob = Convert.ToHexString(accepted.Reader.GetBlobBytes(acceptedFields[index].Signature)),
                        controlSignatureBlob = Convert.ToHexString(oldImage.Reader.GetBlobBytes(oldFields[index].Signature)),
                        candidateSignatureBlob = Convert.ToHexString(newImage.Reader.GetBlobBytes(newFields[index].Signature)),
                    });
                }
                var oldLayout = Measure(oldClr);
                var newLayout = Measure(newClr);
                var expected = native.RootElement.GetProperty("types").GetProperty(Namespace + name);
                AssertNative(expected, oldLayout);
                AssertNative(expected, newLayout);
                measured[name] = newLayout;
                observed[Namespace + name] = new
                {
                    oldPacking = oldType.GetLayout().PackingSize,
                    candidatePacking = newType.GetLayout().PackingSize,
                    fieldSignaturesAndFixedArrayBoundsUnchanged = shapes,
                    oldLayout,
                    candidateLayout = newLayout,
                };
            }
            var nestedOffsets = new List<int>();
            foreach (string name in new[] { "PXE_DHCPV6_MESSAGE", "PXE_DHCPV6_RELAY_MESSAGE" })
            {
                var outer = (Dictionary<string, object>)measured[name]["fields"];
                var options = (Dictionary<string, object>)outer["Options"];
                var inner = (Dictionary<string, object>)measured["PXE_DHCPV6_OPTION"]["fields"];
                foreach (string field in new[] { "OptionCode", "DataLength", "Data" })
                    nestedOffsets.Add((int)options["offset"] + (int)((Dictionary<string, object>)inner[field])["offset"]);
            }
            Assert.Equal(native.RootElement.GetProperty("nestedOptionOffsets").EnumerateArray()
                .Select(value => value.GetInt32()), nestedOffsets);
            File.WriteAllText(Path.Combine(directory, "observed.json"), JsonSerializer.Serialize(new
            {
                architecture,
                scope = "Only four WDS outer packing rows and the actual nested PXE_DHCPV6_OPTION dependency.",
                records = observed,
                nestedOptionOffsets = nestedOffsets,
                managedWitnessHost = RuntimeInformation.ProcessArchitecture.ToString(),
                pointerFreeTransitiveClosure = true,
                acceptedPhysicalLayoutsAndAllFieldSignaturesMatched = true,
                legacyControlIsBoundedAndDoesNotIncludeDocumentationInputs = true,
                runtimeLayoutSource = "Actual normal generated C# through the existing production cleaner/compiler; no synthetic replacement field types.",
                physicalSource = "The same production compilation emitted through ClangSharpSourceWinmdGenerator.",
                nativePath = Path.Combine(root, "native-layout-" + architecture + ".json"),
                controlPath = control.Path,
                candidatePath = candidate.Path,
                sourcePath,
                baselinePath,
                noNativeSourceChangeOrHeaderCredit = true,
                nativeFieldArrayInferenceEnabled = false,
            }, new JsonSerializerOptions { WriteIndented = true }));

            (HeaderAnnotationWinmdTests.MetadataImage Image, Assembly Clr, string Path) Emit(
                string label, Dictionary<string, string> remaps)
            {
                string output = Path.Combine(directory, label);
                Directory.CreateDirectory(output);
                File.WriteAllText(Path.Combine(output, "Wds.cs"), bounded.NormalizeWhitespace().ToFullString());
                File.Copy(Path.Combine(AppContext.BaseDirectory, "assets", "Metadata.cs"), Path.Combine(output, "Metadata.manual.cs"));
                var compilation = ClangSharpSourceCompilation.Create(output, architecture, remaps,
                    new Dictionary<string, Dictionary<string, string>>(), Array.Empty<string>(),
                    new Dictionary<string, string>(), new Dictionary<string, string>(), new HashSet<string>(),
                    new[] { baselinePath }, new Dictionary<string, string>(), new Dictionary<string, string>(),
                    nativeFieldArrayInfo: false);
                Assert.Empty(compilation.GetDiagnostics().Where(value => value.Severity == DiagnosticSeverity.Error));
                string path = Path.Combine(output, "Test.winmd");
                var generator = ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(compilation,
                    new Dictionary<string, string>(), new HashSet<string>(), new HashSet<string>(), new Version(1, 0), path);
                Assert.True(generator.WroteWinmd, string.Join(Environment.NewLine, generator.GetDiagnostics()));
                using var bytes = new MemoryStream();
                var clr = compilation.CSharpCompilation.WithOptions(
                    compilation.CSharpCompilation.Options.WithPlatform(Platform.AnyCpu)).Emit(bytes);
                Assert.True(clr.Success, string.Join(Environment.NewLine, clr.Diagnostics));
                File.WriteAllBytes(Path.Combine(output, "RuntimeLayout.dll"), bytes.ToArray());
                return (new HeaderAnnotationWinmdTests.MetadataImage(path), Assembly.Load(bytes.ToArray()), path);
            }

            Type Wrapper(Type value, bool pair)
            {
                if (wrappers.TryGetValue((value, pair), out var found))
                    return found;
                var builder = wrapperModule.DefineType("Witness" + Guid.NewGuid().ToString("N"),
                    TypeAttributes.Public | TypeAttributes.SequentialLayout | TypeAttributes.Sealed, typeof(ValueType));
                builder.DefineField("Before", pair ? value : typeof(byte), FieldAttributes.Public);
                builder.DefineField("Value", value, FieldAttributes.Public);
                if (!pair)
                    builder.DefineField("After", typeof(byte), FieldAttributes.Public);
                return wrappers[(value, pair)] = builder.CreateType();
            }

            int Alignment(Type type) => (int)Marshal.OffsetOf(Wrapper(type, false), "Value");
            int Stride(Type type) => (int)Marshal.OffsetOf(Wrapper(type, true), "Value");

            Dictionary<string, object> Measure(Type type)
            {
                var fields = new Dictionary<string, object>();
                foreach (var field in type.GetFields(BindingFlags.Public | BindingFlags.Instance))
                {
                    var shape = ClrShape(field);
                    Type element = shape.Atom == "Byte" ? typeof(byte) : shape.Atom == "UInt16" ? typeof(ushort) :
                        type.Assembly.GetType(shape.Atom, throwOnError: true);
                    fields.Add(field.Name, new Dictionary<string, object>
                    {
                        ["offset"] = (int)Marshal.OffsetOf(type, field.Name),
                        ["size"] = Marshal.SizeOf(field.FieldType),
                        ["alignment"] = Alignment(field.FieldType),
                        ["rank"] = shape.Rank,
                        ["extent"] = shape.Extent,
                        ["elementStride"] = Stride(element),
                    });
                }
                Type wrapper = Wrapper(type, false);
                return new Dictionary<string, object>
                {
                    ["size"] = Marshal.SizeOf(type),
                    ["alignment"] = Alignment(type),
                    ["arrayStride"] = Stride(type),
                    ["embeddedValueOffset"] = (int)Marshal.OffsetOf(wrapper, "Value"),
                    ["embeddedSuffixOffset"] = (int)Marshal.OffsetOf(wrapper, "After"),
                    ["embeddedSize"] = Marshal.SizeOf(wrapper),
                    ["embeddedAlignment"] = Alignment(wrapper),
                    ["fields"] = fields,
                };
            }
        }

        private sealed record FieldShape(string Atom, int Rank = 0, int Extent = 0);

        private static TypeDefinition Find(MetadataReader reader, string name)
        {
            var type = reader.TypeDefinitions.Select(reader.GetTypeDefinition).Single(type => reader.GetString(type.Name) == name);
            Assert.Equal(Namespace.TrimEnd('.'), reader.GetString(type.Namespace));
            return type;
        }

        private static FieldShape Shape(MetadataReader reader, FieldDefinition field)
        {
            var blob = reader.GetBlobReader(field.Signature);
            Assert.Equal(SignatureKind.Field, blob.ReadSignatureHeader().Kind);
            var atomReader = blob;
            var code = blob.ReadSignatureTypeCode();
            bool array = code == SignatureTypeCode.Array;
            if (array)
            {
                atomReader = blob;
                code = blob.ReadSignatureTypeCode();
            }
            string atom;
            if (code is SignatureTypeCode.Byte or SignatureTypeCode.UInt16)
                atom = code.ToString();
            else
            {
                Assert.Equal(SignatureTypeCode.TypeHandle, code);
                Assert.Equal(0x11, atomReader.ReadByte());
                var handle = blob.ReadTypeHandle();
                atom = handle.Kind == HandleKind.TypeDefinition
                    ? reader.GetString(reader.GetTypeDefinition((TypeDefinitionHandle)handle).Namespace) + "." +
                        reader.GetString(reader.GetTypeDefinition((TypeDefinitionHandle)handle).Name)
                    : reader.GetString(reader.GetTypeReference((TypeReferenceHandle)handle).Namespace) + "." +
                        reader.GetString(reader.GetTypeReference((TypeReferenceHandle)handle).Name);
                Assert.Equal(Namespace + "PXE_DHCPV6_OPTION", atom);
            }
            int extent = 0;
            if (array)
            {
                Assert.Equal(1, blob.ReadCompressedInteger());
                Assert.Equal(1, blob.ReadCompressedInteger());
                extent = blob.ReadCompressedInteger();
                Assert.True(extent is 1 or 16);
                Assert.Equal(1, blob.ReadCompressedInteger());
                Assert.Equal(0, blob.ReadCompressedSignedInteger());
            }
            Assert.Equal(0, blob.RemainingBytes);
            return new FieldShape(atom, array ? 1 : 0, extent);
        }

        private static FieldShape ClrShape(FieldInfo field)
        {
            var fixedBuffer = field.GetCustomAttribute<FixedBufferAttribute>();
            if (fixedBuffer != null)
            {
                Assert.Equal(typeof(byte), fixedBuffer.ElementType);
                return new FieldShape("Byte", 1, fixedBuffer.Length);
            }
            if (field.FieldType == typeof(byte))
                return new FieldShape("Byte");
            if (field.FieldType == typeof(ushort))
                return new FieldShape("UInt16");
            Assert.Equal("_Options_e__FixedBuffer", field.FieldType.Name);
            var element = Assert.Single(field.FieldType.GetFields(BindingFlags.Public | BindingFlags.Instance));
            Assert.Equal("e0", element.Name);
            Assert.Equal(Namespace + "PXE_DHCPV6_OPTION", element.FieldType.FullName);
            return new FieldShape(element.FieldType.FullName, 1, 1);
        }

        private static void AssertNative(JsonElement expected, Dictionary<string, object> actual)
        {
            Assert.Equal(expected.EnumerateObject().Select(value => value.Name).OrderBy(value => value),
                actual.Keys.OrderBy(value => value));
            foreach (var property in expected.EnumerateObject())
            {
                if (property.Value.ValueKind == JsonValueKind.Object)
                    AssertNative(property.Value, (Dictionary<string, object>)actual[property.Name]);
                else
                    Assert.Equal(property.Value.GetInt32(), actual[property.Name]);
            }
        }
    }
}
