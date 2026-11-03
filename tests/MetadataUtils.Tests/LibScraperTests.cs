using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using TestCommon;
using Xunit;

namespace MetadataUtils.Tests
{
    public class LibScraperTests
    {
        [Theory]
        [MemberData(nameof(GetExpectedImportInfos))]
        public void Returns_Expected_Infos(string libPath, IEnumerable<ImportInfo> expectedImportInfos)
        {
            var infos = LibScraper.GetImportInfos(libPath);
            Assert.Equal(expectedImportInfos, infos);
        }

        [Fact]
        public void OrdinalOnlyExport_KeepsNameAndReportsOrdinalEntryPoint()
        {
            foreach (string arch in new[] { "x86", "x64", "arm64" })
            {
                var infos = LibScraper.GetImportInfos(Path.Combine(TestUtils.GetAssetDir(), arch, "ordinalfixture.lib")).ToDictionary(i => i.ProcName);

                Assert.Equal(3, infos.Count);

                // The lib records an ordinal for any export that has one; whether the DLL also exports the name is a separate question.
                Assert.Null(infos["FixtureByName"].Ordinal);
                Assert.Equal("FixtureByName", infos["FixtureByName"].EntryPoint);

                Assert.Equal((ushort)9, infos["FixtureNamedWithOrdinal"].Ordinal);

                Assert.Equal((ushort)7, infos["FixtureByOrdinal"].Ordinal);
                Assert.Equal("#7", infos["FixtureByOrdinal"].EntryPoint);
            }
        }

        [Fact]
        public void NamedImport_WithNonZeroHint_IsNotTreatedAsOrdinal()
        {
            const ushort NameType = 1 << 2; // IMPORT_OBJECT_NAME
            string libPath = Path.Combine(Path.GetTempPath(), $"namedhint-{Guid.NewGuid():N}.lib");
            try
            {
                File.WriteAllBytes(libPath, BuildImportLib("NamedWithHint", "fixture.dll", hint: 42, type: NameType));

                ImportInfo info = Assert.Single(LibScraper.GetImportInfos(libPath));
                Assert.Equal("NamedWithHint", info.ProcName);
                Assert.Null(info.Ordinal);
                Assert.Equal("NamedWithHint", info.EntryPoint);
            }
            finally
            {
                File.Delete(libPath);
            }
        }

        private static byte[] BuildImportLib(string symbol, string dll, ushort hint, ushort type)
        {
            byte[] strings = System.Text.Encoding.ASCII.GetBytes(symbol + "\0" + dll + "\0");

            using var member = new MemoryStream();
            using (var w = new BinaryWriter(member, System.Text.Encoding.ASCII, leaveOpen: true))
            {
                w.Write((ushort)0);
                w.Write((ushort)0xFFFF);
                w.Write((ushort)0);
                w.Write((ushort)0x8664);
                w.Write(0u);
                w.Write((uint)strings.Length);
                w.Write(hint);
                w.Write(type);
                w.Write(strings);
            }

            using var lib = new MemoryStream();
            byte[] signature = System.Text.Encoding.ASCII.GetBytes("!<arch>\n");
            lib.Write(signature, 0, signature.Length);

            string header = "fixture/".PadRight(16) + "0".PadRight(12) + "0".PadRight(6) + "0".PadRight(6) + "0".PadRight(8) + member.Length.ToString().PadRight(10) + "`\n";
            byte[] headerBytes = System.Text.Encoding.ASCII.GetBytes(header);
            lib.Write(headerBytes, 0, headerBytes.Length);
            member.WriteTo(lib);
            return lib.ToArray();
        }

        public static IEnumerable<object[]> GetExpectedImportInfos()
        {
            foreach (var libPath in Directory.GetFiles(TestUtils.GetAssetDir(), "*.lib", SearchOption.AllDirectories))
            {
                string expectedInfosFile = Path.Combine(TestUtils.GetAssetDir(), Path.GetFileNameWithoutExtension(libPath) + ".txt");
                List<ImportInfo> infos = new List<ImportInfo>();
                foreach (var line in File.ReadAllLines(expectedInfosFile))
                {
                    if (string.IsNullOrWhiteSpace(line))
                    {
                        continue;
                    }

                    // Format: name=dll, or name=dll#ordinal for an ordinal-only export.
                    var parts = line.Split('=');
                    var dllParts = parts[1].Split('#');
                    ushort? ordinal = dllParts.Length > 1 ? ushort.Parse(dllParts[1]) : null;
                    infos.Add(new ImportInfo(dllParts[0], parts[0], ordinal));
                }

                yield return new object[] { libPath, infos };
            }
        }
    }
}
