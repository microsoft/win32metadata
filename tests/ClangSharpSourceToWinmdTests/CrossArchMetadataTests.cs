using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Reflection.Metadata;
using System.Reflection.PortableExecutable;
using ClangSharpSourceToWinmd;
using MetadataUtils;
using Microsoft.CodeAnalysis;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace ClangSharpSourceToWinmdTests
{
    [TestClass]
    public class CrossArchMetadataTests
    {
        [TestMethod]
        public void EmitEnums_ArchitectureVariants_KeepNativeNamesValuesAndFlags()
        {
            using var fixture = new MetadataFixture();
            string winmd = fixture.Generate(
                string.Empty,
                "public enum Register { X64Register = 1 }",
                "public enum Register { Arm64Register = 2 }",
                new[] { "Register" });
            using var stream = File.OpenRead(winmd);
            using var pe = new PEReader(stream);
            MetadataReader reader = pe.GetMetadataReader(MetadataReaderOptions.None);
            TypeDefinition[] definitions = reader.TypeDefinitions
                .Select(reader.GetTypeDefinition)
                .Where(type => reader.GetString(type.Namespace) == "Test")
                .ToArray();
            Assert.AreEqual(2, definitions.Length);

            var architectures = new HashSet<Architecture>();
            foreach (TypeDefinition type in definitions)
            {
                Assert.AreEqual("Register", reader.GetString(type.Name));
                CustomAttribute[] attributes = type.GetCustomAttributes().Select(reader.GetCustomAttribute).ToArray();
                Assert.IsTrue(attributes.Any(attribute => GetAttributeName(reader, attribute) == "FlagsAttribute"));
                CustomAttribute architectureAttribute = attributes.Single(attribute => GetAttributeName(reader, attribute) == "SupportedArchitectureAttribute");
                BlobReader value = reader.GetBlobReader(architectureAttribute.Value);
                Assert.AreEqual(1, value.ReadUInt16());
                Architecture architecture = (Architecture)value.ReadInt32();
                architectures.Add(architecture);

                FieldDefinition member = type.GetFields().Select(reader.GetFieldDefinition)
                    .Single(field => reader.GetString(field.Name) != "value__");
                string expectedName = architecture == Architecture.X64 ? "X64Register" : "Arm64Register";
                int expectedValue = architecture == Architecture.X64 ? 1 : 2;
                Assert.AreEqual(expectedName, reader.GetString(member.Name));
                Constant constant = reader.GetConstant(member.GetDefaultValue());
                Assert.AreEqual(expectedValue, reader.GetBlobReader(constant.Value).ReadInt32());
            }

            CollectionAssert.AreEquivalent(new[] { Architecture.X64, Architecture.Arm64 }, architectures.ToArray());
        }

        [DataTestMethod]
        [DataRow(Architecture.X64, Architecture.Arm64, false)]
        [DataRow(Architecture.X64, Architecture.X64, true)]
        [DataRow(Architecture.All, Architecture.Arm64, true)]
        [DataRow(Architecture.X64 | Architecture.Arm64, Architecture.Arm64, true)]
        public void DuplicateConstants_RequireOverlappingArchitectures(Architecture first, Architecture second, bool expectDuplicate)
        {
            using var fixture = new MetadataFixture();
            string winmd = fixture.Generate(
                GetSource(Architecture.X86),
                GetSource(Architecture.X64),
                GetSource(Architecture.Arm64));

            AssertToolExitCode("showDuplicateConstants", winmd, expectDuplicate ? -1 : 0);

            string GetSource(Architecture architecture)
            {
                return (first.HasFlag(architecture) ? "public enum First { Shared = 1 }" : string.Empty) +
                    (second.HasFlag(architecture) ? "public enum Second { Shared = 2 }" : string.Empty);
            }
        }

        [TestMethod]
        public void DumpEnums_ArchitectureVariants_IncludeEachDefinition()
        {
            using var fixture = new MetadataFixture();
            string winmd = fixture.Generate(
                string.Empty,
                "public enum Register { X64Register = 1 }",
                "public enum Register { Arm64Register = 2 }");

            string output = AssertToolExitCode("dump", winmd, 0);

            StringAssert.Contains(output, "Architecture.X64");
            StringAssert.Contains(output, "Architecture.Arm64");
            StringAssert.Contains(output, "X64Register = 1");
            StringAssert.Contains(output, "Arm64Register = 2");
            Assert.IsFalse(output.Contains("ERROR decompiling"));
        }

        [DataTestMethod]
        [DataRow(false)]
        [DataRow(true)]
        public void BrokenArchTypes_InspectMatchingVariantWithoutHidingInvalidReferences(bool invalidReference)
        {
            using var fixture = new MetadataFixture();
            string x64FieldType = invalidReference ? "Arm64Only" : "RegisterValue";
            string winmd = fixture.Generate(
                string.Empty,
                "public struct X64Only { public int Value; }" +
                "public struct RegisterValue { public X64Only Value; }" +
                $"public struct X64Owner {{ public {x64FieldType} Value; }}",
                "public struct Arm64Only { public int Value; }" +
                "public struct RegisterValue { public Arm64Only Value; }" +
                "public struct Arm64Owner { public RegisterValue Value; }");

            AssertToolExitCode("showBrokenArchTypes", winmd, invalidReference ? -1 : 0);
        }

        private static string GetAttributeName(MetadataReader reader, CustomAttribute attribute)
        {
            EntityHandle parent = attribute.Constructor.Kind == HandleKind.MemberReference
                ? reader.GetMemberReference((MemberReferenceHandle)attribute.Constructor).Parent
                : reader.GetMethodDefinition((MethodDefinitionHandle)attribute.Constructor).GetDeclaringType();
            return parent.Kind == HandleKind.TypeDefinition
                ? reader.GetString(reader.GetTypeDefinition((TypeDefinitionHandle)parent).Name)
                : reader.GetString(reader.GetTypeReference((TypeReferenceHandle)parent).Name);
        }

        private static string AssertToolExitCode(string command, string winmd, int expected)
        {
            using var process = new Process();
            process.StartInfo = new ProcessStartInfo("dotnet")
            {
                UseShellExecute = false,
                RedirectStandardOutput = true,
                RedirectStandardError = true,
            };
            process.StartInfo.ArgumentList.Add(Path.Combine(AppContext.BaseDirectory, "WinmdUtils.dll"));
            process.StartInfo.ArgumentList.Add(command);
            process.StartInfo.ArgumentList.Add("--winmd");
            process.StartInfo.ArgumentList.Add(winmd);
            process.Start();
            string output = process.StandardOutput.ReadToEnd();
            string error = process.StandardError.ReadToEnd();
            process.WaitForExit();

            Assert.AreEqual(expected, process.ExitCode, output + error);
            return output;
        }

        private sealed class MetadataFixture : IDisposable
        {
            private readonly string directory = Path.Combine(Path.GetTempPath(), "Win32MetadataTests-" + Guid.NewGuid().ToString("N"));

            public MetadataFixture()
            {
                Directory.CreateDirectory(this.directory);
                File.WriteAllText(Path.Combine(this.directory, "Attributes.manual.cs"), @"
using System;
namespace Windows.Win32.Foundation.Metadata
{
    [Flags]
    public enum Architecture { None = 0, X86 = 1, X64 = 2, Arm64 = 4, All = 7 }
    public class SupportedArchitectureAttribute : Attribute
    {
        public SupportedArchitectureAttribute(Architecture architecture) { }
    }
}");
            }

            public string Generate(string x86, string x64, string arm64, IEnumerable<string>? flags = null)
            {
                foreach (var source in new[] { ("x86", x86), ("x64", x64), ("arm64", arm64) })
                {
                    string architectureDirectory = Path.Combine(this.directory, source.Item1);
                    Directory.CreateDirectory(architectureDirectory);
                    File.WriteAllText(
                        Path.Combine(architectureDirectory, "Test.cs"),
                        "using System; using Windows.Win32.Foundation.Metadata; namespace Test { " + source.Item2 + " }");
                }

                var compilation = ClangSharpSourceCompilation.Create(
                    this.directory,
                    "crossarch",
                    new Dictionary<string, string>(),
                    new Dictionary<string, Dictionary<string, string>>(),
                    flags ?? Array.Empty<string>(),
                    new Dictionary<string, string>(),
                    new Dictionary<string, string>(),
                    new HashSet<string>(),
                    Array.Empty<string>(),
                    new Dictionary<string, string>(),
                    new Dictionary<string, string>());
                Diagnostic[] errors = compilation.GetDiagnostics()
                    .Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error).ToArray();
                Assert.AreEqual(0, errors.Length, string.Join(Environment.NewLine, errors.Select(error => error.ToString())));

                string output = Path.Combine(this.directory, "Test.winmd");
                ClangSharpSourceWinmdGenerator generator = ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(
                    compilation,
                    new Dictionary<string, string>(),
                    new HashSet<string>(),
                    new HashSet<string>(),
                    new Version(1, 0, 0, 0),
                    output);
                Assert.IsTrue(generator.WroteWinmd, string.Join(Environment.NewLine, generator.GetDiagnostics()));
                return output;
            }

            public void Dispose()
            {
                Directory.Delete(this.directory, true);
            }
        }
    }
}
