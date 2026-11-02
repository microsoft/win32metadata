using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Reflection.Metadata;
using System.Reflection.PortableExecutable;
using MetadataUtils;
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
    }
}
