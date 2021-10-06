using System.Collections.Generic;
using System.IO;
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

        public static IEnumerable<object[]> GetExpectedImportInfos()
        {
            foreach (var libPath in Directory.GetFiles(TestUtils.GetAssetDir(), "*.lib", SearchOption.AllDirectories))
            {
                string expectedInfosFile = Path.Combine(TestUtils.GetAssetDir(), Path.GetFileNameWithoutExtension(libPath) + ".txt");
                List<ImportInfo> infos = new List<ImportInfo>();
                foreach (var line in File.ReadAllLines(expectedInfosFile))
                {
                    var parts = line.Split('=');
                    infos.Add(new ImportInfo(parts[1], parts[0]));
                }

                yield return new object[] { libPath, infos };
            }
        }
    }
}
