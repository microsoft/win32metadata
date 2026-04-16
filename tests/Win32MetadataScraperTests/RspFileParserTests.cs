using System;
using System.Collections.Generic;
using System.IO;
using System.Reflection;
using Win32MetadataScraper;
using Xunit;

namespace Win32MetadataScraperTests
{
    public class RspFileParserTests
    {
        [Fact]
        public void ParseRspFile_IgnoresHashCommentLines()
        {
            string tempFile = Path.GetTempFileName();

            try
            {
                File.WriteAllText(tempFile, @"
--remap
# Compatibility pin
DxcBuffer=DxcBuffer

--exclude
# Preserve the baseline public name
PEXCEPTION_ROUTINE
");

                var settings = new Dictionary<string, List<string>>(StringComparer.OrdinalIgnoreCase);
                InvokeParseRspFile(tempFile, settings);

                Assert.Collection(
                    settings["--remap"],
                    item => Assert.Equal("DxcBuffer=DxcBuffer", item));
                Assert.Collection(
                    settings["--exclude"],
                    item => Assert.Equal("PEXCEPTION_ROUTINE", item));
            }
            finally
            {
                File.Delete(tempFile);
            }
        }

        private static void InvokeParseRspFile(string path, Dictionary<string, List<string>> settings)
        {
            MethodInfo parseRspFile = typeof(RemapDiscovery).Assembly.GetType("Program", throwOnError: true)!
                .GetMethod("ParseRspFile", BindingFlags.Static | BindingFlags.NonPublic)!;

            parseRspFile.Invoke(null, new object[] { path, settings });
        }
    }
}
