using System;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Reflection.Metadata;
using System.Reflection.Metadata.Ecma335;
using Newtonsoft.Json;
using Newtonsoft.Json.Linq;
using Xunit;

namespace MetadataUtils.Tests
{
    public class WinmdContractSnapshotTests
    {
        private static readonly Lazy<byte[]> Fixture = new Lazy<byte[]>(() => ContractFixture.Compile());

        [Fact]
        public void RootClosureIncludesLocalTypesNestedFieldsAttributeTypesAndAssociatedEnumsOnly()
        {
            var snapshot = Read("Call");
            Assert.Empty((JArray)snapshot["missingRoots"]);
            Assert.Equal("roots", snapshot["selectionMode"]);
            var api = Type(snapshot, "Demo.Apis");
            Assert.Equal("context", api["designation"]);
            Assert.Single((JArray)api["methods"]);
            Assert.Empty((JArray)api["fields"]);
            Assert.Equal("root", Method(snapshot)["designation"]);
            Assert.Equal("dependency", Type(snapshot, "Demo.Buffer")["designation"]);
            Assert.Equal("dependency", Type(snapshot, "Demo.Buffer+Inner")["designation"]);
            Assert.Equal("dependency", Type(snapshot, "Demo.Handle")["designation"]);
            Assert.Equal("dependency", Type(snapshot, "Demo.REGISTER_NOTIFICATION_FLAGS")["designation"]);
            Assert.Equal("dependency", Type(snapshot, "Windows.Win32.Foundation.Metadata.MemorySizeAttribute")["designation"]);
            Assert.DoesNotContain(Types(snapshot), t => (string)t["qualifiedName"] == "Demo.Unused");
        }

        [Theory]
        [InlineData("Windows.Win32.Foundation.Metadata")]
        [InlineData("Windows.Win32.Metadata")]
        public void AssociatedEnumClosureRecognizesBothProducerNamespacesWithoutRenamingThem(string attributeNamespace)
        {
            var image = ContractFixture.Compile(ContractFixture.Source.Replace("Windows.Win32.Foundation.Metadata", attributeNamespace));
            var snapshot = WinmdContractSnapshot.Read(image, new[] { "Call" });
            Assert.Equal("dependency", Type(snapshot, "Demo.REGISTER_NOTIFICATION_FLAGS")["designation"]);
            var attributes = Method(snapshot)["parameters"][1]["customAttributes"]
                .Where(a => AttributeName(a) == "AssociatedEnumAttribute").ToArray();
            Assert.Equal(2, attributes.Length);
            Assert.All(attributes, a => Assert.Equal(attributeNamespace + ".AssociatedEnumAttribute",
                (string)a["constructor"]["declaringType"]["fullName"]));
        }

        [Fact]
        public void AllModeAndTypeRootsInventoryAllMembersWithoutDroppingConstants()
        {
            var all = Read();
            Assert.Equal("all", all["selectionMode"]);
            Assert.NotNull(Type(all, "<Module>"));
            Assert.NotNull(Type(all, "Demo.Unused"));
            var fields = (JArray)Type(all, "Demo.Apis")["fields"];
            Assert.Equal(ulong.MaxValue, (ulong)fields.Single(f => (string)f["name"] == "Huge")["constant"]["value"]);
            Assert.Equal("UInt64", fields.Single(f => (string)f["name"] == "Huge")["constant"]["typeCode"]);
            Assert.Equal(-3, (int)fields.Single(f => (string)f["name"] == "Signed")["constant"]["value"]);
            Assert.Equal(65535, (int)fields.Single(f => (string)f["name"] == "Character")["constant"]["value"]);
            Assert.Equal("80000000", fields.Single(f => (string)f["name"] == "NegativeZero")["constant"]["value"]["bits"]);

            var rooted = Read("Demo.Buffer");
            Assert.Equal("root", Type(rooted, "Demo.Buffer")["designation"]);
            Assert.Equal("owned", Type(rooted, "Demo.Buffer+Inner")["designation"]);
            Assert.All(Type(rooted, "Demo.Buffer")["fields"], f => Assert.Equal("owned", f["designation"]));
        }

        [Fact]
        public void RootDiscoveryIsExactAndReturnsEveryOverloadAndArchitectureVariant()
        {
            var image = ContractFixture.Build(variants: 2);
            foreach (string query in new[] { "Call", "Demo.Call", "Demo.Apis.Call" })
            {
                var snapshot = WinmdContractSnapshot.Read(image, new[] { query });
                Assert.Equal(4, ((JArray)snapshot["roots"][0]["matches"]).Count);
                Assert.Equal(2, Types(snapshot).Count(t => (string)t["qualifiedName"] == "Demo.Apis"));
                Assert.Equal(4, Types(snapshot).SelectMany(t => t["methods"]).Count(m => (string)m["designation"] == "root"));
                Assert.All(snapshot["roots"][0]["matches"], m => Assert.NotNull(m["signature"]));
            }

            var missing = WinmdContractSnapshot.Read(image, new[] { "call", "Cal", "Other.Apis.Call", "PHPOWERNOTIFY" });
            Assert.Equal(4, ((JArray)missing["missingRoots"]).Count);
            Assert.Empty((JArray)missing["declarations"]);
            Assert.All(missing["roots"], r => Assert.Empty((JArray)r["matches"]));
        }

        [Fact]
        public void NamespacesAreNeverNormalizedAndRootNamespaceQualificationIsExact()
        {
            var first = Read("Call");
            var second = WinmdContractSnapshot.Read(ContractFixture.Compile(ContractFixture.Source.Replace("namespace Demo", "namespace Windows.Win32")), new[] { "Call" });
            Assert.False((bool)WinmdContractSnapshot.Compare(first, second)["equal"]);
            Assert.Equal("Windows.Win32", Method(second)["namespace"]);
            Assert.NotEmpty((JArray)WinmdContractSnapshot.Read(Fixture.Value, new[] { "Windows.Win32.Call" })["missingRoots"]);
        }

        [Fact]
        public void MethodFactsPreserveImportsFlagsReturnRowsParametersAndDuplicateAttributes()
        {
            var method = Method(Read("Call"));
            Assert.Equal("POWRPROF.dll", method["import"]["module"]);
            Assert.Equal("NativeCall", method["import"]["name"]);
            string flags = (string)method["import"]["attributes"]["names"];
            Assert.Contains("SetLastError", flags);
            Assert.Contains("ExactSpelling", flags);
            Assert.Contains("CallingConventionStdCall", flags);
            Assert.Contains("CharSetUnicode", flags);
            Assert.Contains("PreserveSig", (string)method["implementationAttributes"]["names"]);
            Assert.Equal("UInt32", method["signature"]["returnType"]["name"]);
            var parameters = (JArray)method["parameters"];
            Assert.Equal(new[] { 0, 1, 2, 3 }, parameters.Select(p => (int)p["sequence"]).ToArray());
            Assert.Equal("", parameters[0]["name"]);
            Assert.Equal("DWORD", parameters[0]["customAttributes"][0]["fixedArguments"][0]["value"]);
            Assert.Contains("Optional", (string)parameters[1]["attributes"]["names"]);
            Assert.Equal(2, parameters[1]["customAttributes"].Count(a => AttributeName(a) == "AssociatedEnumAttribute"));
            var memory = parameters[1]["customAttributes"].Single(a => AttributeName(a) == "MemorySizeAttribute");
            Assert.Equal("BytesParamIndex", memory["namedArguments"][0]["name"]);
            Assert.Equal("Int16", memory["namedArguments"][0]["type"]["name"]);
            Assert.Equal(2, (int)memory["namedArguments"][0]["value"]);
            Assert.Equal(0, (int)parameters[3]["marshalling"]["sizeParameterIndex"]);
            Assert.Equal(2, (int)parameters[3]["marshalling"]["size"]);
            Assert.NotEmpty((string)parameters[3]["marshalling"]["descriptor"]);
            Assert.Contains(method["customAttributes"], a => AttributeName(a) == "SupportedOSPlatformAttribute");
        }

        [Fact]
        public void TypeSignaturesPreserveSignednessPointersArraysModifiersAndFunctionPointers()
        {
            var snapshot = Read("Call");
            var fields = (JArray)Type(snapshot, "Demo.Buffer")["fields"];
            Assert.Equal(new[] { "Signed", "Tiny", "Modified", "Nested", "Values", "Callback", "Matrix" },
                fields.Select(f => (string)f["name"]).ToArray());
            Assert.Equal("Int16", fields[0]["type"]["name"]);
            Assert.Equal("SByte", fields[1]["type"]["name"]);
            Assert.Equal("modified", fields[2]["type"]["kind"]);
            Assert.True((bool)fields[2]["type"]["required"]);
            Assert.Equal("System.Runtime.CompilerServices.IsVolatile", fields[2]["type"]["modifier"]["fullName"]);
            Assert.Equal("szArray", fields[4]["type"]["kind"]);
            Assert.Equal(3, (int)fields[4]["marshalling"]["size"]);
            Assert.Equal("functionPointer", fields[5]["type"]["kind"]);
            Assert.Equal("CDecl", fields[5]["type"]["signature"]["callingConvention"]);
            Assert.Equal("Int16", fields[5]["type"]["signature"]["parameterTypes"][0]["name"]);
            Assert.Equal("pointer", fields[5]["type"]["signature"]["parameterTypes"][1]["kind"]);
            Assert.Equal("array", fields[6]["type"]["kind"]);
            Assert.Equal(2, (int)fields[6]["type"]["rank"]);
            Assert.Equal("pointer", Method(snapshot)["signature"]["parameterTypes"][1]["kind"]);
            Assert.Equal("pointer", Method(snapshot)["signature"]["parameterTypes"][1]["elementType"]["kind"]);
            Assert.Equal(2, (int)Type(snapshot, "Demo.Buffer")["layout"]["packingSize"]);
            Assert.Equal(64, (int)Type(snapshot, "Demo.Buffer")["layout"]["size"]);
            Assert.Equal(24, (int)fields[5]["offset"]);
        }

        [Fact]
        public void AttributeDecoderPreservesTypedScalarsBoxingTypeValuesEnumsArraysAndNulls()
        {
            var attribute = Method(Read("Call"))["customAttributes"].Single(a => AttributeName(a) == "ValuesAttribute");
            var args = (JArray)attribute["fixedArguments"];
            Assert.Equal("SByte", args[0]["type"]["name"]);
            Assert.Equal(-2, (int)args[0]["value"]);
            Assert.Equal(65535, (int)args[1]["value"]);
            Assert.Equal("Object", args[2]["type"]["name"]);
            Assert.Equal("Byte", args[2]["value"]["type"]["name"]);
            Assert.Equal(7, (int)args[2]["value"]["value"]);
            Assert.Equal("Demo.Buffer", args[3]["value"]["name"]);
            Assert.Equal(uint.MaxValue, (uint)args[4]["value"]);
            var named = (JArray)attribute["namedArguments"];
            Assert.Equal(new[] { 3, 1 }, named.Single(a => (string)a["name"] == "Numbers")["value"].Select(a => (int)a["value"]).ToArray());
            Assert.Equal(JTokenType.Null, named.Single(a => (string)a["name"] == "Text")["value"].Type);
            Assert.Equal("property", named.Single(a => (string)a["name"] == "Text")["kind"]);
            Assert.Equal("field", named.Single(a => (string)a["name"] == "Numbers")["kind"]);
            Assert.Equal("Demo.Handle", named.Single(a => (string)a["name"] == "Types")["value"][0]["value"]["name"]);
            Assert.Equal("x", named.Single(a => (string)a["name"] == "Objects")["value"][0]["value"]["value"]);
        }

        [Theory]
        [InlineData("AssociatedEnum(\"REGISTER_NOTIFICATION_FLAGS\"),", "", "customAttributes")]
        [InlineData("BytesParamIndex = 2", "BytesParamIndex = 1", "namedArguments")]
        [InlineData("MemorySize(BytesParamIndex = 2)", "NativeArrayInfo(CountParamIndex = 2)", "customAttributes")]
        [InlineData("] uint flags", "] REGISTER_NOTIFICATION_FLAGS flags", "signature")]
        [InlineData("SetLastError = true", "SetLastError = false", "import")]
        [InlineData("ExactSpelling = true", "ExactSpelling = false", "import")]
        [InlineData("In, Optional, MemorySize", "In, MemorySize", "parameters")]
        [InlineData("NativeTypeName(\"DWORD\")", "NativeTypeName(\"ULONG\")", "customAttributes")]
        [InlineData("CallingConvention.StdCall", "CallingConvention.Cdecl", "import")]
        [InlineData("EntryPoint = \"NativeCall\"", "EntryPoint = \"nativecall\"", "import")]
        [InlineData("Pack = 2", "Pack = 4", "layout")]
        [InlineData("sbyte Tiny", "byte Tiny", "type")]
        public void SemanticComparisonDetectsContractChanges(string from, string to, string expectedPathPart)
        {
            string changed = ContractFixture.Source.Replace(from, to);
            Assert.NotEqual(ContractFixture.Source, changed);
            var comparison = WinmdContractSnapshot.Compare(Read("Call"), WinmdContractSnapshot.Read(ContractFixture.Compile(changed), new[] { "Call" }));
            Assert.False((bool)comparison["equal"]);
            Assert.Contains(comparison["differences"], d => ((string)d["path"]).Contains(expectedPathPart, StringComparison.Ordinal));
        }

        [Fact]
        public void TokenBlobMvidAndSourceChangesAreEvidenceNotSemanticDifferences()
        {
            var first = WinmdContractSnapshot.Read(ContractFixture.Build(), new[] { "Call" });
            var second = WinmdContractSnapshot.Read(ContractFixture.Build(relocateTokens: true), new[] { "Call" });
            Assert.NotEqual(first["source"]["sha256"], second["source"]["sha256"]);
            Assert.NotEqual(Method(first)["evidence"]["signature"], Method(second)["evidence"]["signature"]);
            Assert.NotEqual(Method(first)["parameters"][1]["evidence"]["token"], Method(second)["parameters"][1]["evidence"]["token"]);
            Assert.True((bool)WinmdContractSnapshot.Compare(first, second)["equal"]);
        }

        [Theory]
        [InlineData("ContractFixture", 1, true)]
        [InlineData("ContractFixture", 2, false)]
        [InlineData("OtherFixture", 1, false)]
        public void AssemblyScopedReferencesResolveLocallyOnlyForTheSameIdentity(string assemblyName, int majorVersion, bool isLocal)
        {
            var image = ContractFixture.Build((m, h) =>
            {
                var self = m.AddAssemblyReference(m.GetOrAddString(assemblyName), new Version(majorVersion, 0, 0, 0), default, default, 0, default);
                var dependency = m.AddTypeReference(self, m.GetOrAddString("Demo"), m.GetOrAddString("Dependency"));
                var signature = new BlobBuilder();
                new BlobEncoder(signature).MethodSignature().Parameters(0, r => r.Type().Type(dependency, isValueType: false), p => { });
                m.AddMethodDefinition(MethodAttributes.Public | MethodAttributes.Static, MethodImplAttributes.Runtime,
                    m.GetOrAddString("WithDependency"), m.GetOrAddBlob(signature), 0,
                    MetadataTokens.ParameterHandle(m.GetRowCount(TableIndex.Param) + 1));
                m.AddTypeDefinition(TypeAttributes.Public, m.GetOrAddString("Demo"), m.GetOrAddString("Dependency"), default,
                    MetadataTokens.FieldDefinitionHandle(1), MetadataTokens.MethodDefinitionHandle(m.GetRowCount(TableIndex.MethodDef) + 1));
            });
            var snapshot = WinmdContractSnapshot.Read(image, new[] { "WithDependency" });
            Assert.Equal(isLocal, Types(snapshot).Any(t => (string)t["qualifiedName"] == "Demo.Dependency"));
            if (isLocal)
            {
                Assert.Equal("dependency", Type(snapshot, "Demo.Dependency")["designation"]);
            }

            var returnType = Type(snapshot, "Demo.Apis")["methods"][0]["signature"]["returnType"];
            Assert.Equal("Demo.Dependency", returnType["fullName"]);
            Assert.Equal(isLocal ? JTokenType.Null : JTokenType.Object, returnType["scope"].Type);
            Assert.Equal(assemblyName, returnType["evidence"]["resolutionScope"]["identity"]["name"]);
        }

        [Fact]
        public void DuplicateAttributesAndDuplicateNamedArgumentsAreNotCollapsed()
        {
            byte[] Build(int count) => ContractFixture.Build((metadata, handles) =>
            {
                var value = metadata.GetOrAddBlob(ContractFixture.AttributeBlob(suffix: b =>
                {
                    b.WriteUInt16(2);
                    for (int i = 0; i < 2; i++)
                    {
                        b.WriteByte(0x53);
                        b.WriteByte(0x08);
                        b.WriteSerializedString("Count");
                        b.WriteInt32(i);
                    }
                }));
                for (int i = 0; i < count; i++)
                {
                    metadata.AddCustomAttribute(handles.Parameter, handles.TagConstructor, value);
                }
            });
            var first = WinmdContractSnapshot.Read(Build(2), new[] { "Call" });
            var attrs = (JArray)Method(first)["parameters"][1]["customAttributes"];
            Assert.Equal(2, attrs.Count);
            Assert.Equal(new[] { 0, 1 }, attrs[0]["namedArguments"].Select(a => (int)a["value"]).ToArray());
            Assert.False((bool)WinmdContractSnapshot.Compare(first, WinmdContractSnapshot.Read(Build(1), new[] { "Call" }))["equal"]);
        }

        [Fact]
        public void SortingIsDeterministicButFieldParameterAndVtableOrderArePreserved()
        {
            var image = Fixture.Value;
            Assert.Equal(WinmdContractSnapshot.Read(image, new[] { "Call", "Buffer" }).ToString(Formatting.None),
                WinmdContractSnapshot.Read(image, new[] { "Buffer", "Call", "Call" }).ToString(Formatting.None));
            var first = Read("Demo.IFirst");
            Assert.Equal(new[] { "Z", "A" }, Type(first, "Demo.IFirst")["methods"].Select(m => (string)m["name"]).ToArray());
            var second = (JObject)first.DeepClone();
            var methods = (JArray)Type(second, "Demo.IFirst")["methods"];
            methods.Replace(new JArray(methods.Reverse().ToArray()));
            Assert.False((bool)WinmdContractSnapshot.Compare(first, second)["equal"]);
        }

        [Fact]
        public void NonVirtualMethodRowOrderDoesNotCreateSemanticDifferences()
        {
            byte[] Build(string[] names) => ContractFixture.Build((m, h) =>
            {
                foreach (string name in names)
                {
                    m.AddMethodDefinition(MethodAttributes.Public | MethodAttributes.Static, MethodImplAttributes.Runtime,
                        m.GetOrAddString(name), m.GetOrAddBlob(new byte[] { 0, 0, 1 }), 0,
                        MetadataTokens.ParameterHandle(m.GetRowCount(TableIndex.Param) + 1));
                }
            });
            var first = WinmdContractSnapshot.Read(Build(new[] { "Z", "A" }), new[] { "Demo.Apis" });
            var second = WinmdContractSnapshot.Read(Build(new[] { "A", "Z" }), new[] { "Demo.Apis" });
            Assert.Equal(new[] { "A", "Call", "Z" }, Type(first, "Demo.Apis")["methods"].Select(m => (string)m["name"]).ToArray());
            Assert.True((bool)WinmdContractSnapshot.Compare(first, second)["equal"]);
        }

        [Fact]
        public void PropertiesEventsGenericsConstraintsAndMethodImplementationsSurvive()
        {
            var snapshot = Read("Demo.Generic`1");
            var type = Type(snapshot, "Demo.Generic`1");
            Assert.Equal("T", type["genericParameters"][0]["name"]);
            Assert.Contains("ReferenceTypeConstraint", (string)type["genericParameters"][0]["attributes"]["names"]);
            Assert.Single((JArray)type["properties"]);
            Assert.Single((JArray)type["events"]);
            Assert.NotNull(type["properties"][0]["accessors"]["getter"]);
            Assert.NotNull(type["events"][0]["accessors"]["adder"]);
            Assert.Equal(2, ((JArray)type["methodImplementations"]).Count);
            var method = type["methods"].Single(m => (string)m["name"] == "Convert");
            Assert.Equal(1, (int)method["signature"]["genericParameterCount"]);
            Assert.Equal("genericMethodParameter", method["signature"]["returnType"]["kind"]);
            Assert.Equal("genericTypeParameter", method["signature"]["parameterTypes"][0]["kind"]);
            Assert.Equal("System.IDisposable", method["genericParameters"][0]["constraints"][0]["type"]["fullName"]);
            Assert.Equal("genericInstantiation", type["fields"].Single(f => (string)f["name"] == "Recursive")["type"]["kind"]);
            var refReturn = type["methods"].Single(m => (string)m["name"] == "RefReturn");
            Assert.Equal("byReference", refReturn["signature"]["parameterTypes"][0]["kind"]);
            Assert.Equal("modified", refReturn["signature"]["returnType"]["kind"]);
            Assert.NotEmpty((JArray)snapshot["assembly"]["security"]);
        }

        [Fact]
        public void SerializedGenericArrayTypeArgumentsParticipateInClosure()
        {
            var image = ContractFixture.Compile(ContractFixture.Source.Replace("typeof(Buffer), Register.Max",
                "typeof(Generic<Unused>[]), Register.Max").Replace("public struct Unused", "public class Unused"));
            var snapshot = WinmdContractSnapshot.Read(image, new[] { "Call" });
            Assert.Equal("dependency", Type(snapshot, "Demo.Generic`1")["designation"]);
            Assert.Equal("dependency", Type(snapshot, "Demo.Unused")["designation"]);
        }

        [Theory]
        [InlineData("Property", "get_Property", "set_Property")]
        [InlineData("Event", "add_Event", "remove_Event")]
        public void PropertyAndEventRootsIncludeTheirAccessorContracts(string root, string first, string second)
        {
            var snapshot = Read(root);
            var methods = Type(snapshot, "Demo.Generic`1")["methods"];
            Assert.Contains(methods, m => (string)m["name"] == first && (string)m["designation"] == "owned");
            Assert.Contains(methods, m => (string)m["name"] == second && (string)m["designation"] == "owned");
        }

        [Fact]
        public void ArrayShapesOptionalModifiersAndVarargsFunctionPointerSignaturesSurvive()
        {
            var image = ContractFixture.Build((m, h) =>
            {
                var signature = new BlobBuilder();
                signature.WriteBytes(new byte[] { 0x06, 0x14, 0x06 });
                signature.WriteCompressedInteger(2);
                signature.WriteCompressedInteger(1);
                signature.WriteCompressedInteger(5);
                signature.WriteCompressedInteger(2);
                signature.WriteCompressedSignedInteger(-2);
                signature.WriteCompressedSignedInteger(3);
                m.AddFieldDefinition(FieldAttributes.Public, m.GetOrAddString("Bounded"), m.GetOrAddBlob(signature));
                var reference = m.AddAssemblyReference(m.GetOrAddString("External"), new Version(1, 0), default, default, 0, default);
                var modifier = m.AddTypeReference(reference, m.GetOrAddString("Demo"), m.GetOrAddString("Modifier"));
                signature = new BlobBuilder();
                signature.WriteBytes(new byte[] { 0x06, 0x20 });
                signature.WriteCompressedInteger((MetadataTokens.GetRowNumber(modifier) << 2) | 1);
                signature.WriteBytes(new byte[] { 0x1b, 0x05, 0x02, 0x09, 0x06, 0x41, 0x0f, 0x05 });
                m.AddFieldDefinition(FieldAttributes.Public, m.GetOrAddString("Callback"), m.GetOrAddBlob(signature));
            });
            var fields = Type(WinmdContractSnapshot.Read(image), "Demo.Apis")["fields"];
            Assert.Equal(new[] { 5 }, fields[0]["type"]["sizes"].Values<int>().ToArray());
            Assert.Equal(new[] { -2, 3 }, fields[0]["type"]["lowerBounds"].Values<int>().ToArray());
            Assert.Equal("modified", fields[1]["type"]["kind"]);
            Assert.False((bool)fields[1]["type"]["required"]);
            var function = fields[1]["type"]["elementType"]["signature"];
            Assert.Equal("VarArgs", function["callingConvention"]);
            Assert.Equal(1, (int)function["requiredParameterCount"]);
            Assert.Equal(2, ((JArray)function["parameterTypes"]).Count);
        }

        [Fact]
        public void ExternalEnumUnderlyingTypesAreNeverGuessedFromTheirNames()
        {
            var image = ContractFixture.Build((m, h) =>
            {
                var reference = m.AddAssemblyReference(m.GetOrAddString("External"), new Version(1, 0), default, default, 0, default);
                var enumeration = m.AddTypeReference(reference, m.GetOrAddString("Demo"), m.GetOrAddString("UnknownEnum"));
                var signature = new BlobBuilder();
                signature.WriteBytes(new byte[] { 0x20, 0x01, 0x01, 0x11 });
                signature.WriteCompressedInteger((MetadataTokens.GetRowNumber(enumeration) << 2) | 1);
                var constructor = m.AddMemberReference(enumeration, m.GetOrAddString(".ctor"), m.GetOrAddBlob(signature));
                m.AddCustomAttribute(h.Parameter, constructor, m.GetOrAddBlob(ContractFixture.AttributeBlob()));
            });
            var exception = Assert.Throws<NotSupportedException>(() => WinmdContractSnapshot.Read(image, new[] { "Call" }));
            Assert.Contains("UnknownEnum", exception.Message);
        }

        [Fact]
        public void TruncatedAndTrailingSignatureBlobsFail()
        {
            foreach (byte[] signature in new[] { new byte[] { 0x06 }, new byte[] { 0x06, 0x08, 0xff } })
            {
                var image = ContractFixture.Build((m, h) => m.AddFieldDefinition(FieldAttributes.Public, m.GetOrAddString("Bad"), m.GetOrAddBlob(signature)));
                Assert.Throws<BadImageFormatException>(() => WinmdContractSnapshot.Read(image));
            }
        }

        [Fact]
        public void InputDirectionDoesNotImplyConstButAnEncodedConstModifierIsCompared()
        {
            byte[] Build(bool isConst) => ContractFixture.Build((m, h) =>
            {
                var modifier = m.AddTypeReference(default, m.GetOrAddString("System.Runtime.CompilerServices"), m.GetOrAddString("IsConst"));
                var signature = new BlobBuilder();
                signature.WriteBytes(new byte[] { 0, 1, 1 });
                if (isConst)
                {
                    signature.WriteByte(0x1f);
                    signature.WriteCompressedInteger((MetadataTokens.GetRowNumber(modifier) << 2) | 1);
                }

                signature.WriteBytes(new byte[] { 0x0f, 1 });
                m.AddMethodDefinition(MethodAttributes.Public | MethodAttributes.Static, MethodImplAttributes.Runtime,
                    m.GetOrAddString("Buffer"), m.GetOrAddBlob(signature), 0,
                    MetadataTokens.ParameterHandle(m.GetRowCount(TableIndex.Param) + 1));
                m.AddParameter(ParameterAttributes.In | ParameterAttributes.Optional, m.GetOrAddString("InputBuffer"), 1);
            });
            var mutable = WinmdContractSnapshot.Read(Build(false), new[] { "Buffer" });
            var qualified = WinmdContractSnapshot.Read(Build(true), new[] { "Buffer" });
            var original = Type(mutable, "Demo.Apis")["methods"][0];
            var changed = Type(qualified, "Demo.Apis")["methods"][0];
            Assert.Equal("pointer", original["signature"]["parameterTypes"][0]["kind"]);
            Assert.Equal("modified", changed["signature"]["parameterTypes"][0]["kind"]);
            Assert.True((bool)changed["signature"]["parameterTypes"][0]["required"]);
            Assert.Equal("System.Runtime.CompilerServices.IsConst", changed["signature"]["parameterTypes"][0]["modifier"]["fullName"]);
            Assert.Equal(original["parameters"][0]["attributes"], changed["parameters"][0]["attributes"]);
            Assert.Empty((JArray)changed["parameters"][0]["customAttributes"]);
            Assert.False((bool)WinmdContractSnapshot.Compare(mutable, qualified)["equal"]);
        }

        [Fact]
        public void ComparisonRejectsIncompleteSnapshotsAndReportsMissingRoots()
        {
            var incomplete = new JObject { ["schemaVersion"] = WinmdContractSnapshot.SchemaVersion };
            Assert.Throws<InvalidDataException>(() => WinmdContractSnapshot.Compare(incomplete, incomplete));
            var missing = Read("NeverEmitted");
            var comparison = WinmdContractSnapshot.Compare(missing, missing);
            Assert.Equal("NeverEmitted", comparison["firstMissingRoots"][0]);
            Assert.Equal("NeverEmitted", comparison["secondMissingRoots"][0]);
        }

        [Theory]
        [InlineData("0000010000000000")]
        [InlineData("0100010000000000FF")]
        [InlineData("01000100000001005208015800000000")]
        public void MalformedAttributeBlobsFailInsteadOfBeingDropped(string hex)
        {
            var image = ContractFixture.Build((m, h) => m.AddCustomAttribute(h.Parameter, h.TagConstructor, m.GetOrAddBlob(Convert.FromHexString(hex))));
            Assert.Throws<BadImageFormatException>(() => WinmdContractSnapshot.Read(image, new[] { "Call" }));
        }

        [Theory]
        [InlineData("07FF")]
        [InlineData("2A0780")]
        public void MalformedMarshallingFailsInsteadOfBeingIgnored(string hex)
        {
            var image = ContractFixture.Build((m, h) => m.AddMarshallingDescriptor(h.Parameter, m.GetOrAddBlob(Convert.FromHexString(hex))));
            Assert.Throws<BadImageFormatException>(() => WinmdContractSnapshot.Read(image, new[] { "Call" }));
        }

        [Fact]
        public void UnsupportedMarshallingAndNonMetadataFilesFailExplicitly()
        {
            var image = ContractFixture.Build((m, h) => m.AddMarshallingDescriptor(h.Parameter, m.GetOrAddBlob(new byte[] { 0xff })));
            Assert.Throws<NotSupportedException>(() => WinmdContractSnapshot.Read(image, new[] { "Call" }));
            Assert.Throws<BadImageFormatException>(() => WinmdContractSnapshot.Read(new byte[] { 1, 2, 3 }));
            Assert.Throws<ArgumentException>(() => WinmdContractSnapshot.Read(Fixture.Value, new[] { "" }));
            Assert.Throws<InvalidDataException>(() => WinmdContractSnapshot.Compare(new JObject(), new JObject()));
        }

        private static JObject Read(params string[] roots) => WinmdContractSnapshot.Read(Fixture.Value, roots);
        private static JObject[] Types(JObject snapshot) => snapshot["declarations"].Cast<JObject>().ToArray();
        private static JObject Type(JObject snapshot, string name) => Types(snapshot).Single(t => (string)t["qualifiedName"] == name);
        private static JObject Method(JObject snapshot) => Types(snapshot).SelectMany(t => t["methods"]).Cast<JObject>().Single(m => (string)m["name"] == "Call");
        private static string AttributeName(JToken attribute) => (string)attribute["constructor"]["declaringType"]["name"];
    }
}
