using System;
using System.IO;
using System.Linq;
using System.Reflection.Metadata;
using System.Reflection.PortableExecutable;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace ClangSharpSourceToWinmdTests
{
    [TestClass]
    public class DeterministicWinmdTests
    {
        private const string Source = "public enum Register { Value = 1 }";

        [TestMethod]
        public void Generate_SameInput_ProducesIdenticalBytes()
        {
            // Each call uses its own source directory, compilation and generator instance,
            // so only the input content and the module file name are shared.
            byte[] first = Generate(Source);
            byte[] second = Generate(Source);

            CollectionAssert.AreEqual(first, second, "Two builds of the same input should be byte-identical.");
        }

        [TestMethod]
        public void Generate_DerivesMvidAndTimestampFromContent()
        {
            byte[] winmd = Generate(Source);
            using var pe = new PEReader(new MemoryStream(winmd));

            Assert.AreNotEqual(Guid.Empty, GetMvid(pe), "The reserved MVID slot should be filled in.");

            // A deterministic PE stores part of the content hash, with the high bit set, in place of
            // the wall-clock timestamp, and advertises that with a Reproducible debug entry.
            Assert.IsTrue(pe.PEHeaders.CoffHeader.TimeDateStamp < 0, "The timestamp should be derived from the content.");
            Assert.IsTrue(
                pe.ReadDebugDirectory().Any(entry => entry.Type == DebugDirectoryEntryType.Reproducible),
                "A deterministic PE should carry a Reproducible debug directory entry.");
        }

        [TestMethod]
        public void Generate_ChangedInput_ChangesMvid()
        {
            byte[] original = Generate(Source);
            byte[] changedConstant = Generate("public enum Register { Value = 2 }");
            byte[] changedType = Generate(Source + " public struct Extra { public int Field; }");

            Guid originalMvid = GetMvid(original);
            Assert.AreNotEqual(originalMvid, GetMvid(changedConstant), "Changing a constant should change the MVID.");
            Assert.AreNotEqual(originalMvid, GetMvid(changedType), "Adding a type should change the MVID.");
        }

        private static byte[] Generate(string source)
        {
            using var fixture = new CrossArchMetadataTests.MetadataFixture();
            return File.ReadAllBytes(fixture.Generate(source, source, source));
        }

        private static Guid GetMvid(byte[] winmd)
        {
            using var pe = new PEReader(new MemoryStream(winmd));
            return GetMvid(pe);
        }

        private static Guid GetMvid(PEReader pe)
        {
            MetadataReader reader = pe.GetMetadataReader();
            return reader.GetGuid(reader.GetModuleDefinition().Mvid);
        }
    }
}
