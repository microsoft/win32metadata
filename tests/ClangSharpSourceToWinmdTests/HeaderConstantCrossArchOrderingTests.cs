using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection.Metadata;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace ClangSharpSourceToWinmdTests
{
    public partial class HeaderConstantCrossArchTests
    {
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
