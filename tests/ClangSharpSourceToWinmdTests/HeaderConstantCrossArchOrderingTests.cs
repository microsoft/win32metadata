using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection.Metadata;
using System.Text.Json;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace ClangSharpSourceToWinmdTests
{
    public partial class HeaderConstantCrossArchTests
    {
        [DataTestMethod]
        [DataRow("int", "0x80040200U", ConstantTypeCode.Int32, "00020480")]
        [DataRow("uint", "0x80040200U", ConstantTypeCode.UInt32, "00020480")]
        [DataRow("long", "0x8000000000000000UL", ConstantTypeCode.Int64, "0000000000000080")]
        [DataRow("ulong", "0x8000000000000000UL", ConstantTypeCode.UInt64, "0000000000000080")]
        public void NativeTypedefConstantsKeepTheirNativeTypeAndStorage(
            string storage, string value, ConstantTypeCode code, string bits)
        {
            foreach (bool repeatedProviders in new[] { false, true })
            {
                var inputs = new Dictionary<string, string>
                {
                    ["provider.header-types.cs"] = "namespace Test { [NativeTypedef] " +
                        "public partial struct STATUS { public " + storage + " Value; } }",
                    ["constants.cs"] = Source("[NativeTypeName(\"const STATUS\")] public const STATUS ORIGINAL=" +
                        "unchecked((STATUS)" + value + "); public const " + storage + " ALIAS=(" + storage + ")ORIGINAL;"),
                };
                if (repeatedProviders)
                {
                    inputs["backing.header-types.cs"] = "namespace Test { [NativeTypedef] " +
                        "public partial struct BASE { public " + storage + " Value; } " +
                        "[NativeTypedef] public partial struct CHAIN { public BASE Value; } }";
                    inputs["other.header-types.cs"] = "namespace Test { [NativeTypedef] " +
                        "public partial struct STATUS { public CHAIN Value; } }";
                    inputs["autotypes.cs"] = inputs["provider.header-types.cs"];
                    inputs["consumer.cs"] = "using System.Runtime.InteropServices; namespace Test { " +
                        "public struct BUFFER { public STATUS Value; } public static partial class Apis { " +
                        "[DllImport(\"native\")] public static extern STATUS RoundTrip(STATUS value); } }";
                }
                Emit(inputs, fields =>
                {
                    var original = fields.Single(field => field.Name == "ORIGINAL");
                    StringAssert.StartsWith(original.Signature, "0611");
                    Assert.AreEqual(code, original.ConstantType);
                    Assert.AreEqual(bits, original.ValueBits);
                    Assert.IsNull(original.Architectures);
                    var alias = fields.Single(field => field.Name == "ALIAS");
                    Assert.AreEqual(code, alias.ConstantType);
                    Assert.AreEqual(bits, alias.ValueBits);
                    Assert.IsNull(alias.Architectures);
                    Assert.IsFalse(alias.Signature.StartsWith("0611", StringComparison.Ordinal));
                }, inspectImage: image =>
                {
                    if (!repeatedProviders)
                        return;
                    using var stream = image.OpenRead();
                    using var pe = new System.Reflection.PortableExecutable.PEReader(stream);
                    var reader = pe.GetMetadataReader();
                    var types = reader.TypeDefinitions.ToDictionary(
                        handle => reader.GetString(reader.GetTypeDefinition(handle).Name));
                    foreach (string name in new[] { "STATUS", "BASE" })
                    {
                        var type = reader.GetTypeDefinition(types[name]);
                        Assert.AreEqual("Test", reader.GetString(type.Namespace));
                        var field = reader.GetFieldDefinition(type.GetFields().Single());
                        CollectionAssert.AreEqual(new byte[] { 0x06, code switch
                        {
                            ConstantTypeCode.Int32 => 0x08,
                            ConstantTypeCode.UInt32 => 0x09,
                            ConstantTypeCode.Int64 => 0x0a,
                            _ => 0x0b,
                        } }, reader.GetBlobBytes(field.Signature));
                    }
                    foreach (var pair in new[] { (Owner: "CHAIN", Value: "BASE"), (Owner: "BUFFER", Value: "STATUS") })
                    {
                        var field = reader.GetFieldDefinition(reader.GetTypeDefinition(types[pair.Owner]).GetFields().Single());
                        var signature = reader.GetBlobReader(field.Signature);
                        Assert.AreEqual(0x06, (int)signature.ReadByte());
                        AssertNominal(ref signature, pair.Value);
                        Assert.AreEqual(0, signature.RemainingBytes);
                    }
                    var method = reader.GetMethodDefinition(reader.GetTypeDefinition(types["Apis"]).GetMethods()
                        .Single(handle => reader.GetString(reader.GetMethodDefinition(handle).Name) == "RoundTrip"));
                    var methodSignature = reader.GetBlobReader(method.Signature);
                    Assert.AreEqual(0, (int)methodSignature.ReadByte());
                    Assert.AreEqual(1, methodSignature.ReadCompressedInteger());
                    AssertNominal(ref methodSignature, "STATUS");
                    AssertNominal(ref methodSignature, "STATUS");
                    Assert.AreEqual(0, methodSignature.RemainingBytes);

                    void AssertNominal(ref BlobReader signature, string name)
                    {
                        Assert.AreEqual(0x11, (int)signature.ReadByte());
                        Assert.AreEqual(System.Reflection.Metadata.Ecma335.MetadataTokens.GetRowNumber(types[name]) << 2,
                            signature.ReadCompressedInteger());
                    }
                });
            }
        }

        [TestMethod]
        public void NativeTypedefConstantVariantsKeepActualProfileValues()
        {
            var inputs = new Dictionary<string, string>();
            foreach (string architecture in Architectures)
            {
                inputs[Path.Combine(architecture, "provider.header-types.cs")] =
                    "namespace Test { [NativeTypedef] public partial struct STATUS { public int Value; } }";
                inputs[Path.Combine(architecture, "constants.cs")] =
                    Source("[NativeTypeName(\"const STATUS\")] public const STATUS ORIGINAL=unchecked((STATUS)" +
                        (architecture == "x86" ? "0x80040200U" : "0U") + ");");
            }
            Emit(inputs, fields =>
            {
                var variants = fields.OrderBy(field => field.Architectures).ToArray();
                Assert.AreEqual(2, variants.Length);
                CollectionAssert.AreEqual(new int?[] { 1, 6 }, variants.Select(field => field.Architectures).ToArray());
                CollectionAssert.AreEqual(new[] { "00020480", "00000000" }, variants.Select(field => field.ValueBits).ToArray());
                Assert.IsTrue(variants.All(field => field.Signature.StartsWith("0611", StringComparison.Ordinal) &&
                    field.ConstantType == ConstantTypeCode.Int32));
            });
        }

        [DataTestMethod]
        [DataRow("int", "0x80040200U", ConstantTypeCode.Int32, "00020480")]
        [DataRow("uint", "0x80040200U", ConstantTypeCode.UInt32, "00020480")]
        [DataRow("long", "0x8000000000000000UL", ConstantTypeCode.Int64, "0000000000000080")]
        [DataRow("ulong", "0x8000000000000000UL", ConstantTypeCode.UInt64, "0000000000000080")]
        public void NativeTypedefCastsInEnumInitializersKeepTheirNumericStorage(
            string storage, string value, ConstantTypeCode code, string bits)
        {
            Emit(new Dictionary<string, string>
            {
                ["provider.header-types.cs"] = "namespace Test { [NativeTypedef] " +
                    "public partial struct STATUS { public " + storage + " Value; } }",
                ["enum.cs"] = "namespace Test { public enum Result : " + storage +
                    " { ERROR = unchecked((" + storage + ")((STATUS)(" + value + "))) } }",
                ["consumer.cs"] = Source("public const " + storage + " VALUE=(" + storage + ")Result.ERROR;"),
            }, fields =>
            {
                var field = fields.Single();
                Assert.AreEqual(code, field.ConstantType);
                Assert.AreEqual(bits, field.ValueBits);
                Assert.IsNull(field.Architectures);
            });
        }

        [DataTestMethod]
        [DataRow(false)]
        [DataRow(true)]
        public void NativeTypedefConstantLoweringDoesNotHideInvalidConversions(bool nativeTypedef)
        {
            var error = Assert.ThrowsException<InvalidOperationException>(() => Emit(new Dictionary<string, string>
            {
                ["provider.header-types.cs"] = "namespace Test { " + (nativeTypedef ? "[NativeTypedef] " : "") +
                    "public partial struct STATUS { public int Value; } }",
                ["constants.cs"] = Source("[NativeTypeName(\"const STATUS\")] public const STATUS ORIGINAL=(STATUS)0x80040200U;"),
            }, _ => { }));
            StringAssert.Contains(error.Message, "CSSW003");
            StringAssert.Contains(error.Message, "ORIGINAL");
            if (nativeTypedef)
            {
                foreach (string conflictingStorage in new[] { "uint", "long", "double" })
                {
                    Emit(new Dictionary<string, string>
                    {
                        ["provider.header-types.cs"] = "namespace Test { [NativeTypedef] " +
                            "public partial struct STATUS { public int Value; } " +
                            "[NativeTypedef] public partial struct BASE { public " + conflictingStorage + " Value; } }",
                        ["other.header-types.cs"] = "namespace Test { [NativeTypedef] " +
                            "public partial struct STATUS { public BASE Value; } }",
                        ["autotypes.cs"] = "namespace Test { [NativeTypedef] " +
                            "public partial struct STATUS { public int Value; } }",
                        ["constants.cs"] = Source("[NativeTypeName(\"const STATUS\")] public const STATUS ORIGINAL=(STATUS)1;"),
                    }, fields =>
                    {
                        var field = fields.Single();
                        Assert.AreEqual("ORIGINAL", field.Name);
                        Assert.AreEqual(ConstantTypeCode.Int32, field.ConstantType);
                        Assert.AreEqual("01000000", field.ValueBits);
                        StringAssert.StartsWith(field.Signature, "0611");
                    }, inspectImage: image =>
                    {
                        using var report = JsonDocument.Parse(File.ReadAllText(
                            Path.Combine(image.DirectoryName!, "generation-diagnostics.json")));
                        Assert.AreEqual("completed-with-diagnostics", report.RootElement.GetProperty("Status").GetString());
                        Assert.AreEqual(0, report.RootElement.GetProperty("BlockedStages").GetArrayLength());
                        var diagnostics = report.RootElement.GetProperty("Errors").EnumerateArray().ToArray();
                        Assert.IsTrue(diagnostics.Length > 0);
                        foreach (var diagnostic in diagnostics)
                        {
                            Assert.AreEqual("CSSW005", diagnostic.GetProperty("Code").GetString());
                            Assert.IsFalse(diagnostic.GetProperty("BlocksEmission").GetBoolean());
                            StringAssert.Contains(diagnostic.GetProperty("Message").GetString(), "Conflicting native typedef Value storage types");
                            StringAssert.Contains(diagnostic.GetProperty("SelectedInput").GetString(), "autotypes");
                        }
                    });
                }
            }
        }

        [DataTestMethod]
        [DataRow(false)]
        [DataRow(true)]
        public void RoutedEnumMembersRemoveOnlyTheirOriginalLooseCopies(bool headerGroup)
        {
            Emit(new Dictionary<string, string>
            {
                [headerGroup ? "provider.header-types.cs" : "provider.cs"] =
                    "namespace Native { public enum Resource:uint { RAW=7 } }",
                ["constants.cs"] = Source("public const uint RAW=7U;", "Native"),
                ["consumer.cs"] = "using static Native.Apis; using static Canonical.Resource;" +
                    Source("public const uint COUNT=" + (headerGroup ? "RAW" : "(uint)RAW") + "+1U;", "Consumers"),
            }, fields =>
            {
                var field = fields.Single();
                Assert.AreEqual("COUNT", field.Name);
                Assert.AreEqual("Consumers", field.Namespace);
                Assert.AreEqual("0609", field.Signature);
                Assert.AreEqual(ConstantTypeCode.UInt32, field.ConstantType);
                Assert.AreEqual("08000000", field.ValueBits);
            }, new Dictionary<string, string> { ["Resource"] = "Canonical" });
        }

        [DataTestMethod]
        [DataRow(false, "int", "(uint)global::Native.D3DRESOURCETYPE.D3DRTYPE_INDEXBUFFER+1U", "08000000")]
        [DataRow(true, "uint", "D3DRTYPE_INDEXBUFFER+1U", "08000000")]
        [DataRow(false, "int", "(uint)global::Native.D3DRESOURCETYPE.D3DRTYPE_INDEXBUFFER*2U", "0E000000")]
        [DataRow(true, "uint", "D3DRTYPE_INDEXBUFFER<<1", "0E000000")]
        [DataRow(false, "int", "(uint)global::Native.D3DRESOURCETYPE.D3DRTYPE_INDEXBUFFER|8U", "0F000000")]
        [DataRow(true, "uint", "D3DRTYPE_INDEXBUFFER|8U", "0F000000")]
        [DataRow(true, "uint", "global::Native.D3DRESOURCETYPE.D3DRTYPE_INDEXBUFFER*2", "0E000000")]
        public void NativeAndLogicalEnumExpressionsKeepScalarStorage(
            bool headerGroup, string storage, string expression, string bits)
        {
            Emit(new Dictionary<string, string>
            {
                [headerGroup ? "provider.header-types.cs" : "provider.cs"] =
                    "namespace Native { public enum D3DRESOURCETYPE:" + storage + " { D3DRTYPE_INDEXBUFFER=7 } }",
                ["consumer.cs"] = Source("public const uint COUNT=" + expression + ";", "Consumers"),
            }, fields =>
            {
                var field = fields.Single();
                Assert.AreEqual("COUNT", field.Name);
                Assert.AreEqual("Consumers", field.Namespace);
                Assert.IsNull(field.Architectures);
                Assert.AreEqual(ConstantTypeCode.UInt32, field.ConstantType);
                Assert.AreEqual("0609", field.Signature);
                Assert.AreEqual(bits, field.ValueBits);
            });
        }

        [DataTestMethod]
        [DataRow("long", "-1L", "(long)global::Native.Resource.RAW*2L", ConstantTypeCode.Int64, "060A", "FEFFFFFFFFFFFFFF")]
        [DataRow("ulong", "9223372036854775808UL", "(ulong)global::Native.Resource.RAW|1UL", ConstantTypeCode.UInt64, "060B", "0100000000000080")]
        public void NativeEnumExpressionsKeepUnderlyingOperandStorage(
            string storage, string value, string expression, ConstantTypeCode code, string signature, string bits)
        {
            Emit(new Dictionary<string, string>
            {
                ["provider.cs"] = "namespace Native { public enum Resource:" + storage + " { RAW=" + value + " } }",
                ["consumer.cs"] = Source("public const " + storage + " COUNT=" + expression + ";", "Consumers"),
            }, fields =>
            {
                var field = fields.Single();
                Assert.AreEqual(code, field.ConstantType);
                Assert.AreEqual(signature, field.Signature);
                Assert.AreEqual(bits, field.ValueBits);
                Assert.IsNull(field.Architectures);
            });
        }

        [TestMethod]
        public void NativeEnumScalarAliasesUseTheirActualMember()
        {
            Emit(new Dictionary<string, string>
            {
                ["provider.cs"] = "namespace Native { public enum Resource { RAW=7 } }",
                ["consumer.cs"] = Source("public const uint COUNT=(uint)global::Native.Resource.RAW;", "Consumers"),
            }, fields =>
            {
                var field = fields.Single();
                Assert.AreEqual("0609", field.Signature);
                Assert.AreEqual(ConstantTypeCode.UInt32, field.ConstantType);
                Assert.AreEqual("07000000", field.ValueBits);
            });
        }

        [TestMethod]
        public void CrossNamespacePrimitiveExpressionsUseAllActualProviders()
        {
            Emit(new Dictionary<string, string>
            {
                ["left.cs"] = Source("public const uint LEFT=1U;", "Left"),
                ["right.cs"] = Source("public const uint RIGHT=2U;", "Right"),
                ["consumer.cs"] = Source("public const uint COUNT=(LEFT|RIGHT)+1U;", "Consumers"),
            }, fields =>
            {
                Assert.AreEqual(3, fields.Length);
                var field = fields.Single(field => field.Name == "COUNT");
                Assert.AreEqual("Consumers", field.Namespace);
                Assert.AreEqual("0609", field.Signature);
                Assert.AreEqual("04000000", field.ValueBits);
            });
        }

        [DataTestMethod]
        [DataRow(false)]
        [DataRow(true)]
        public void LogicalGroupExpressionsDoNotChooseBetweenAmbiguousProviders(bool primitiveProvider)
        {
            var error = Assert.ThrowsException<InvalidOperationException>(() => Emit(new Dictionary<string, string>
            {
                ["provider.header-types.cs"] = "namespace Native { public enum Resource { RAW=7 } }",
                ["other.header-types.cs"] = primitiveProvider ? Source("public const uint RAW=9U;", "Other") :
                    "namespace Other { public enum Resource { RAW=9 } }",
                ["consumer.cs"] = Source("public const uint COUNT=RAW+1;", "Consumers"),
            }, _ => { }));
            StringAssert.Contains(error.Message, "CSSW003");
            StringAssert.Contains(error.Message, "COUNT");
        }

        [TestMethod]
        public void NativeEnumExpressionsPreserveAnExistingLocalBinding()
        {
            Emit(new Dictionary<string, string>
            {
                ["provider.cs"] = "namespace Native { public enum Resource { RAW=7 } }",
                ["consumer.cs"] = Source("public const uint RAW=2U; public const uint COUNT=RAW+1U;", "Consumers"),
            }, fields =>
            {
                Assert.AreEqual(2, fields.Length);
                Assert.AreEqual("03000000", fields.Single(field => field.Name == "COUNT").ValueBits);
            });
        }

        [DataTestMethod]
        [DataRow(false)]
        [DataRow(true)]
        public void NativeEnumMembersDoNotRemoveConstantsFromAnotherScope(bool nestedType)
        {
            Emit(new Dictionary<string, string>
            {
                ["provider.cs"] = nestedType
                    ? "namespace Test { public struct Owner { public enum Resource { RAW=7 } } }"
                    : "namespace Native; public enum Resource { RAW=7 }",
                ["consumer.cs"] = Source("public const uint RAW=2U; public const uint COUNT=RAW+1U;"),
            }, fields =>
            {
                Assert.AreEqual(2, fields.Length);
                Assert.AreEqual("02000000", fields.Single(field => field.Name == "RAW").ValueBits);
                Assert.AreEqual("03000000", fields.Single(field => field.Name == "COUNT").ValueBits);
            });
        }

        [TestMethod]
        public void NativeEnumExpressionsBindBeforeCrossArchComposition()
        {
            var inputs = new Dictionary<string, string>();
            foreach (string architecture in Architectures)
            {
                inputs[Path.Combine(architecture, "provider.cs")] =
                    "namespace Native { public enum Resource { RAW=" + (architecture == "x86" ? "7" : "8") + " } }";
                inputs[Path.Combine(architecture, "consumer.cs")] =
                    Source("public const uint COUNT=(uint)global::Native.Resource.RAW+1U;", "Consumers");
            }
            Emit(inputs, fields =>
            {
                Assert.AreEqual(2, fields.Length);
                var variants = fields.OrderBy(field => field.Architectures).ToArray();
                CollectionAssert.AreEqual(new int?[] { 1, 6 }, variants.Select(field => field.Architectures).ToArray());
                CollectionAssert.AreEqual(new[] { "08000000", "09000000" }, variants.Select(field => field.ValueBits).ToArray());
                Assert.IsTrue(variants.All(field => field.Signature == "0609" &&
                    field.ConstantType == ConstantTypeCode.UInt32));
            });
        }

        [TestMethod]
        public void NativeEnumExpressionsDoNotHideCommonSourceValueVariation()
        {
            var inputs = Architectures.ToDictionary(architecture => Path.Combine(architecture, "provider.cs"), architecture =>
                "namespace Native { public enum Resource { RAW=" + (architecture == "x86" ? "7" : "8") + " } }");
            inputs.Add("consumer.cs", Source("public const uint COUNT=(uint)global::Native.Resource.RAW+1U;", "Consumers"));
            var error = Assert.ThrowsException<InvalidOperationException>(() => Emit(inputs, _ => { }));
            StringAssert.Contains(error.Message, "CSSW003");
            StringAssert.Contains(error.Message, "architecture-dependent storage or value");
        }

        [TestMethod]
        public void NativeEnumExpressionsDoNotHideConstantOverflow()
        {
            var error = Assert.ThrowsException<InvalidOperationException>(() => Emit(new Dictionary<string, string>
            {
                ["provider.cs"] = "namespace Native { public enum Resource:uint { RAW=uint.MaxValue } }",
                ["consumer.cs"] = Source("public const uint COUNT=(uint)global::Native.Resource.RAW+1U;", "Consumers"),
            }, _ => { }));
            StringAssert.Contains(error.Message, "CSSW003");
            StringAssert.Contains(error.Message, "COUNT");
        }

        [TestMethod]
        public void NativeEnumExpressionsPreserveExplicitUncheckedArithmetic()
        {
            Emit(new Dictionary<string, string>
            {
                ["provider.cs"] = "namespace Native { public enum Resource:uint { RAW=uint.MaxValue } }",
                ["consumer.cs"] = Source("public const uint COUNT=unchecked((uint)global::Native.Resource.RAW+1U);", "Consumers"),
            }, fields =>
            {
                var field = fields.Single();
                Assert.AreEqual("0609", field.Signature);
                Assert.AreEqual("00000000", field.ValueBits);
            });
        }

        [TestMethod]
        public void NativeEnumExpressionsDoNotReplaceMissingQualifiedMembers()
        {
            var error = Assert.ThrowsException<InvalidOperationException>(() => Emit(new Dictionary<string, string>
            {
                ["provider.cs"] = "namespace Native { public enum Resource { RAW=7 } }",
                ["other.cs"] = "namespace Other { public enum Resource { MISSING=9 } }",
                ["consumer.cs"] = Source("public const uint COUNT=global::Native.Resource.MISSING+1;", "Consumers"),
            }, _ => { }));
            StringAssert.Contains(error.Message, "CSSW003");
            StringAssert.Contains(error.Message, "COUNT");
        }

        [DataTestMethod]
        [DataRow("RAW")]
        [DataRow("RAW+1")]
        [DataRow("global::Native.Resource.RAW")]
        public void OrdinaryEnumConstantsRequireValidCSharpBindingAndConversion(string expression)
        {
            var error = Assert.ThrowsException<InvalidOperationException>(() => Emit(new Dictionary<string, string>
            {
                ["provider.cs"] = "namespace Native { public enum Resource { RAW=7 } }",
                ["consumer.cs"] = Source("public const uint COUNT=" + expression + ";", "Consumers"),
            }, _ => { }));
            StringAssert.Contains(error.Message, "CSSW003");
            StringAssert.Contains(error.Message, "COUNT");
        }

        [DataTestMethod]
        [DataRow("uint", "1U", ConstantTypeCode.UInt32, "0609", "01000000")]
        [DataRow("int", "-1", ConstantTypeCode.Int32, "0608", "FFFFFFFF")]
        [DataRow("string", "\"native\"", ConstantTypeCode.String, "060E", "6E0061007400690076006500")]
        public void CrossNamespacePrimitiveAliasesKeepActualProviderStorageAndValues(
            string storage, string value, ConstantTypeCode code, string signature, string bits)
        {
            Emit(new Dictionary<string, string>
            {
                ["provider.cs"] = Source($"public const {storage} VALUE={value};", "Providers"),
                ["consumer.cs"] = Source($"public const {storage} FIRST=VALUE;", "Consumers"),
                ["chain.cs"] = Source($"public const {storage} SECOND=(FIRST);", "Chained"),
            }, fields =>
            {
                Assert.AreEqual(3, fields.Length);
                foreach (var field in fields)
                {
                    Assert.IsNull(field.Architectures);
                    Assert.AreEqual(code, field.ConstantType);
                    Assert.AreEqual(signature, field.Signature);
                    Assert.AreEqual(bits, field.ValueBits);
                }
                Assert.AreEqual("Providers", fields.Single(field => field.Name == "VALUE").Namespace);
                Assert.AreEqual("Consumers", fields.Single(field => field.Name == "FIRST").Namespace);
                Assert.AreEqual("Chained", fields.Single(field => field.Name == "SECOND").Namespace);
            });
        }

        [TestMethod]
        public void CrossNamespaceAliasesDoNotChooseBetweenAmbiguousProviders()
        {
            var error = Assert.ThrowsException<InvalidOperationException>(() => Emit(new Dictionary<string, string>
            {
                ["first.cs"] = Source("public const uint VALUE=1U;", "First"),
                ["second.cs"] = Source("public const uint VALUE=2U;", "Second"),
                ["consumer.cs"] = Source("public const uint ALIAS=VALUE;", "Consumers"),
            }, _ => { }));
            StringAssert.Contains(error.Message, "CSSW003");
            StringAssert.Contains(error.Message, "ALIAS");
        }

        [TestMethod]
        public void CrossNamespaceAliasesPreserveAnExistingLocalBinding()
        {
            Emit(new Dictionary<string, string>
            {
                ["provider.cs"] = Source("public const uint VALUE=2U;", "Providers"),
                ["consumer.cs"] = Source("public const uint VALUE=1U; public const uint ALIAS=VALUE;", "Consumers"),
            }, fields =>
            {
                Assert.AreEqual(3, fields.Length);
                Assert.AreEqual("01000000", fields.Single(field => field.Name == "ALIAS").ValueBits);
                Assert.AreEqual("02000000", fields.Single(field => field.Namespace == "Providers").ValueBits);
            });
        }

        [TestMethod]
        public void CrossNamespaceAliasesUseTheirActualNativeProfile()
        {
            var inputs = new Dictionary<string, string>();
            foreach (string architecture in Architectures)
            {
                inputs[Path.Combine(architecture, "provider.cs")] =
                    Source("public const uint VALUE=" + (architecture == "x86" ? "1U;" : "2U;"), "Providers");
                inputs[Path.Combine(architecture, "consumer.cs")] =
                    Source("public const uint ALIAS=VALUE;", "Consumers");
            }
            Emit(inputs, fields =>
            {
                Assert.AreEqual(4, fields.Length);
                foreach (string name in new[] { "VALUE", "ALIAS" })
                {
                    var variants = fields.Where(field => field.Name == name).OrderBy(field => field.Architectures).ToArray();
                    CollectionAssert.AreEqual(new int?[] { 1, 6 }, variants.Select(field => field.Architectures).ToArray());
                    CollectionAssert.AreEqual(new[] { "01000000", "02000000" }, variants.Select(field => field.ValueBits).ToArray());
                    Assert.IsTrue(variants.All(field => field.Signature == "0609" &&
                        field.ConstantType == ConstantTypeCode.UInt32));
                }
            });
        }

        [TestMethod]
        public void CrossNamespaceAliasesDoNotHideCommonSourceValueVariation()
        {
            var inputs = Architectures.ToDictionary(architecture => Path.Combine(architecture, "provider.cs"), architecture =>
                Source("public const uint VALUE=" + (architecture == "x86" ? "1U;" : "2U;"), "Providers"));
            inputs.Add("consumer.cs", Source("public const uint ALIAS=VALUE;", "Consumers"));
            var error = Assert.ThrowsException<InvalidOperationException>(() => Emit(inputs, _ => { }));
            StringAssert.Contains(error.Message, "CSSW003");
            StringAssert.Contains(error.Message, "architecture-dependent storage or value");
        }

        [TestMethod]
        public void CrossNamespaceAliasesDoNotHideConstantOverflow()
        {
            var error = Assert.ThrowsException<InvalidOperationException>(() => Emit(new Dictionary<string, string>
            {
                ["provider.cs"] = Source("public const uint VALUE=65536U;", "Providers"),
                ["consumer.cs"] = Source("public const ushort ALIAS=VALUE;", "Consumers"),
            }, _ => { }));
            StringAssert.Contains(error.Message, "CSSW003");
            StringAssert.Contains(error.Message, "ALIAS");
        }

        [TestMethod]
        public void ReviewPrimitiveAliasesLowerBeforeCommonProfileQualification()
        {
            Emit(new Dictionary<string, string>
            {
                ["provider.header-types.cs"] = "namespace Test { public enum G:uint { RAW=1 } }",
                ["constants.cs"] = Source("public const uint RAW=1U; public const uint Alias=RAW;"),
            }, fields =>
            {
                var alias = fields.Single();
                Assert.AreEqual("Alias", alias.Name);
                Assert.IsNull(alias.Architectures);
                Assert.AreEqual("0609", alias.Signature);
                Assert.AreEqual(ConstantTypeCode.UInt32, alias.ConstantType);
                Assert.AreEqual("01000000", alias.ValueBits);
            });
        }

        [TestMethod]
        public void ReviewPrimitiveAliasesLowerInTheirOriginalProfiles()
        {
            var inputs = new Dictionary<string, string>();
            foreach (string architecture in Architectures)
            {
                string value = architecture == "x86" ? "1" : "2";
                inputs[Path.Combine(architecture, "provider.header-types.cs")] =
                    "namespace Test { public enum G:uint { RAW=" + value + " } }";
                inputs[Path.Combine(architecture, "constants.cs")] = Source(
                    "public const uint RAW=" + value + "U; public const uint Alias=RAW; public const uint Next=Alias+1U;");
            }
            Emit(inputs, fields =>
            {
                Assert.AreEqual(4, fields.Length);
                foreach (var (name, bits) in new[]
                {
                    ("Alias", new[] { "01000000", "02000000" }),
                    ("Next", new[] { "02000000", "03000000" }),
                })
                {
                    var variants = fields.Where(field => field.Name == name).OrderBy(field => field.Architectures).ToArray();
                    CollectionAssert.AreEqual(new int?[] { 1, 6 }, variants.Select(field => field.Architectures).ToArray());
                    CollectionAssert.AreEqual(bits, variants.Select(field => field.ValueBits).ToArray());
                    Assert.IsTrue(variants.All(field => field.Signature == "0609" && field.ConstantType == ConstantTypeCode.UInt32));
                }
            });
        }

        [DataTestMethod]
        [DataRow("uint", "ulong")]
        [DataRow("int", "uint")]
        public void ReviewEnumStorageVariationFailsBeforeComposition(string x86Storage, string otherStorage)
        {
            var error = Assert.ThrowsException<InvalidOperationException>(() => Emit(
                Architectures.ToDictionary(architecture => Path.Combine(architecture, "Bindings.cs"), architecture =>
                    "namespace Test { public enum E:" + (architecture == "x86" ? x86Storage : otherStorage) +
                    " { Zero=0 } }" + Source("public const E EXTRA=E.Zero;")), _ => { }));
            StringAssert.Contains(error.Message, "CSSW003");
            StringAssert.Contains(error.Message, "E");
            StringAssert.Contains(error.Message, "underlying storage");
        }

        [DataTestMethod]
        [DataRow("int", ConstantTypeCode.Int32, "00000000")]
        [DataRow("uint", ConstantTypeCode.UInt32, "00000000")]
        [DataRow("long", ConstantTypeCode.Int64, "0000000000000000")]
        [DataRow("ulong", ConstantTypeCode.UInt64, "0000000000000000")]
        public void ReviewInvariantEnumConstantsRemainSupported(string storage, ConstantTypeCode code, string bits)
        {
            Emit(Architectures.ToDictionary(architecture => Path.Combine(architecture, "Bindings.cs"), _ =>
                "namespace Test { public enum E:" + storage + " { Zero=0 } }" +
                Source("public const E EXTRA=E.Zero;")), fields =>
            {
                var field = fields.Single();
                Assert.AreEqual("EXTRA", field.Name);
                Assert.IsNull(field.Architectures);
                Assert.AreEqual(code, field.ConstantType);
                Assert.AreEqual(bits, field.ValueBits);
                StringAssert.StartsWith(field.Signature, "0611");
            });
        }

        [DataTestMethod]
        [DataRow(false)]
        [DataRow(true)]
        public void ReviewLimitedEnumConstantsStillCheckEveryAvailableEnumDefinition(bool only64Bit)
        {
            var error = Assert.ThrowsException<InvalidOperationException>(() => Emit(
                Architectures.ToDictionary(architecture => Path.Combine(architecture, "Bindings.cs"), architecture =>
                    "namespace Test { public enum E:" + (architecture == "x86" ? "uint" : "ulong") +
                    " { Zero=0 } }" + ((architecture != "x86") == only64Bit ? Source("public const E EXTRA=E.Zero;") : "")),
                _ => { }));
            StringAssert.Contains(error.Message, "CSSW003");
            StringAssert.Contains(error.Message, "underlying storage");
        }

        [TestMethod]
        public void ReviewUnusedVaryingEnumStorageDoesNotRejectPrimitiveConstants()
        {
            Emit(Architectures.ToDictionary(architecture => Path.Combine(architecture, "Bindings.cs"), architecture =>
                "namespace Test { public enum E:" + (architecture == "x86" ? "uint" : "ulong") +
                " { Zero=0 } }" + Source("public const uint EXTRA=1U;")), fields =>
            {
                var field = fields.Single();
                Assert.AreEqual("EXTRA", field.Name);
                Assert.IsNull(field.Architectures);
                Assert.AreEqual(ConstantTypeCode.UInt32, field.ConstantType);
                Assert.AreEqual("01000000", field.ValueBits);
            });
        }

        [TestMethod]
        public void ReviewDistinctEnumIdentitiesMayHaveDifferentInvariantStorage()
        {
            const string definitions = "namespace First { public enum E:uint { Zero=0 } }" +
                "namespace Second { public enum E:ulong { Zero=0 } }";
            Emit(Architectures.ToDictionary(architecture => Path.Combine(architecture, "Bindings.cs"), _ => definitions +
                Source("public const First.E A=First.E.Zero; public const Second.E B=Second.E.Zero;")), fields =>
            {
                Assert.AreEqual(2, fields.Length);
                Assert.IsTrue(fields.All(field => field.Architectures == null));
                Assert.AreEqual(ConstantTypeCode.UInt32, fields.Single(field => field.Name == "A").ConstantType);
                Assert.AreEqual(ConstantTypeCode.UInt64, fields.Single(field => field.Name == "B").ConstantType);
            });
        }
    }
}
