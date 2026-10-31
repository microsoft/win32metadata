using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace ClangSharpSourceToWinmdTests
{
    public partial class HeaderConstantCrossArchTests
    {
        [TestMethod]
        public void ReviewCommonGenuineSuffixNamesRemainUnchanged()
        {
            Emit(new Dictionary<string, string>
            {
                ["common.cs"] = Source("public const uint EXTRA=3U; public const uint EXTRA____1=7U; public const uint EXTRA____2=9U;"),
            }, fields =>
            {
                CollectionAssert.AreEquivalent(new[] { "EXTRA", "EXTRA____1", "EXTRA____2" },
                    fields.Select(field => field.Name).ToArray());
                Assert.IsTrue(fields.All(field => field.Architectures == null));
                Assert.AreEqual("07000000", fields.Single(field => field.Name == "EXTRA____1").ValueBits);
                Assert.AreEqual("09000000", fields.Single(field => field.Name == "EXTRA____2").ValueBits);
            });
        }

        [TestMethod]
        public void ReviewAuthoredArchitectureDoesNotImplyAnInternalRename()
        {
            Emit(new Dictionary<string, string>
            {
                ["common.cs"] = Source("[SupportedArchitecture(Architecture.X86)] public const uint EXTRA____1=7U;" +
                    "[SupportedArchitecture(Architecture.X64|Architecture.Arm64)] public const uint EXTRA____2=9U;"),
            }, fields =>
            {
                CollectionAssert.AreEquivalent(new[] { "EXTRA____1", "EXTRA____2" }, fields.Select(field => field.Name).ToArray());
                Assert.AreEqual(1, fields.Single(field => field.Name == "EXTRA____1").Architectures);
                Assert.AreEqual(6, fields.Single(field => field.Name == "EXTRA____2").Architectures);
            });
        }

        [TestMethod]
        public void ReviewVariantNamesAvoidGenuineMemberCollisions()
        {
            Emit(Architectures.ToDictionary(architecture => architecture, architecture => Source(
                "public const uint EXTRA=" + (architecture == "x86" ? "1" : "2") +
                "U; public const uint EXTRA____1=7U; public const uint EXTRA____1_1=8U; public const uint EXTRA____2=9U;")), fields =>
            {
                Assert.AreEqual(5, fields.Length);
                foreach (var (name, bits) in new[] { ("EXTRA____1", "07000000"), ("EXTRA____1_1", "08000000"), ("EXTRA____2", "09000000") })
                {
                    var field = fields.Single(field => field.Name == name);
                    Assert.IsNull(field.Architectures);
                    Assert.AreEqual(bits, field.ValueBits);
                }
                var extras = fields.Where(field => field.Name == "EXTRA").OrderBy(field => field.Architectures).ToArray();
                CollectionAssert.AreEqual(new int?[] { 1, 6 }, extras.Select(field => field.Architectures).ToArray());
                CollectionAssert.AreEqual(new[] { "01000000", "02000000" }, extras.Select(field => field.ValueBits).ToArray());
            });
        }

        [DataTestMethod]
        [DataRow(false)]
        [DataRow(true)]
        public void ReviewDependentConstantsBindInTheirOwnProfileBeforeIdenticalFileElimination(bool separateFiles)
        {
            var inputs = new Dictionary<string, string>();
            foreach (string architecture in Architectures)
            {
                string first = "public const uint A=" + (architecture == "x86" ? "1" : "2") + "U;";
                const string second = "public const uint B=A+1U;";
                inputs[Path.Combine(architecture, "Bindings.cs")] = Source(first + (separateFiles ? "" : second));
                if (separateFiles)
                    inputs[Path.Combine(architecture, "Bindings.header-types.cs")] = Source(second);
            }
            Emit(inputs, fields =>
            {
                Assert.AreEqual(4, fields.Length);
                foreach (var (name, values) in new[]
                {
                    ("A", new[] { "01000000", "02000000" }),
                    ("B", new[] { "02000000", "03000000" }),
                })
                {
                    var variants = fields.Where(field => field.Name == name).OrderBy(field => field.Architectures).ToArray();
                    CollectionAssert.AreEqual(new int?[] { 1, 6 }, variants.Select(field => field.Architectures).ToArray());
                    CollectionAssert.AreEqual(values, variants.Select(field => field.ValueBits).ToArray());
                }
            });
        }

        [TestMethod]
        public void ReviewDependentUncheckedValuesRetainTheirNativeStorageBits()
        {
            Emit(Architectures.ToDictionary(architecture => architecture, architecture => Source(
                "public const int A=" + (architecture == "x86" ? "2147483647" : "1") +
                "; public const int B=unchecked(A+1);")), fields =>
            {
                var values = fields.Where(field => field.Name == "B").OrderBy(field => field.Architectures).ToArray();
                CollectionAssert.AreEqual(new int?[] { 1, 6 }, values.Select(field => field.Architectures).ToArray());
                CollectionAssert.AreEqual(new[] { "00000080", "02000000" }, values.Select(field => field.ValueBits).ToArray());
                Assert.IsTrue(values.All(field => field.Signature == "0608"));
            });
        }

        [DataTestMethod]
        [DataRow("checked(A+1)")]
        [DataRow("UNRESOLVED+1")]
        [DataRow("B+1")]
        public void ReviewUnqualifiedOrInvalidDependenciesFailClosed(string initializer)
        {
            var error = Assert.ThrowsException<InvalidOperationException>(() => Emit(
                Architectures.ToDictionary(architecture => architecture, architecture => Source(
                    "public const int A=" + (architecture == "x86" ? "2147483647" : "1") +
                    "; public const int B=" + initializer + ";")), _ => Assert.Fail("No physical image may be emitted.")));
            StringAssert.Contains(error.Message, "CSSW003");
            StringAssert.Contains(error.Message, "B");
        }

        [TestMethod]
        public void ReviewCommonDependencyOnDifferentProfilesFailsClosed()
        {
            var inputs = Architectures.ToDictionary(architecture => architecture, architecture =>
                Source("public const uint A=" + (architecture == "x86" ? "1" : "2") + "U;"));
            inputs["common.cs"] = Source("public const uint B=A+1U;");
            var error = Assert.ThrowsException<InvalidOperationException>(() => Emit(inputs, _ => Assert.Fail("No arbitrary common value.")));
            StringAssert.Contains(error.Message, "CSSW003");
            StringAssert.Contains(error.Message, "common source constant");
        }

        [TestMethod]
        public void ReviewAliasStorageIsQualifiedBeforeGrouping()
        {
            Emit(Architectures.ToDictionary(architecture => architecture, architecture =>
                "using WORD=System." + (architecture == "x86" ? "Int32" : "UInt32") + ";" +
                Source("public const WORD EXTRA=0;")), fields =>
            {
                Assert.AreEqual(2, fields.Length);
                var variants = fields.OrderBy(field => field.Architectures).ToArray();
                CollectionAssert.AreEqual(new int?[] { 1, 6 }, variants.Select(field => field.Architectures).ToArray());
                CollectionAssert.AreEqual(new[] { "0608", "0609" }, variants.Select(field => field.Signature).ToArray());
                Assert.IsTrue(fields.All(field => field.Name == "EXTRA" && field.ValueBits == "00000000"));
            });
        }

        [TestMethod]
        public void ReviewFloatingConstantsRetainTheirExactStorageBits()
        {
            Emit(Architectures.ToDictionary(architecture => architecture, architecture =>
                Source("public const float F=" + (architecture == "x86" ? "-0.0F" : "1.25F") +
                    "; public const double D=" + (architecture == "x86" ? "-0.0D" : "1.25D") + ";")), fields =>
            {
                foreach (var (name, signature, bits) in new[]
                {
                    ("F", "060C", new[] { "00000080", "0000A03F" }),
                    ("D", "060D", new[] { "0000000000000080", "000000000000F43F" }),
                })
                {
                    var variants = fields.Where(field => field.Name == name).OrderBy(field => field.Architectures).ToArray();
                    CollectionAssert.AreEqual(new int?[] { 1, 6 }, variants.Select(field => field.Architectures).ToArray());
                    CollectionAssert.AreEqual(bits, variants.Select(field => field.ValueBits).ToArray());
                    Assert.IsTrue(variants.All(field => field.Signature == signature));
                }
            });
        }
    }
}
