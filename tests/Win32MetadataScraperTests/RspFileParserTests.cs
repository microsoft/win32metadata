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

        [Fact]
        public void NormalizeGeneratedSource_RemovesInvalidAnonymousRecordSuffix()
        {
            const string source = "public _Anonymous-1_e__Struct* Options;";

            string normalized = InvokeNormalizeGeneratedSource(source, "Dhcp.cs");

            Assert.Equal("public _Anonymous_e__Struct* Options;", normalized);
        }

        [Fact]
        public void NormalizeGeneratedSource_PreservesSystemMonitorLibId()
        {
            const string source = "public static readonly Guid LIBID_SystemMonitor = new Guid(0xC4D2D8E0, 0xD1DD, 0x11CE, 0x94, 0x0F, 0x00, 0x80, 0x29, 0x00, 0x43, 0x47);";

            string normalized = InvokeNormalizeGeneratedSource(source, "Perf.cs");

            Assert.Equal("public static readonly Guid LIBID_SystemMonitor = new Guid(0x1B773E42, 0x2509, 0x11CF, 0x94, 0x2F, 0x00, 0x80, 0x29, 0x00, 0x43, 0x47);", normalized);
        }

        [Fact]
        public void NormalizeGeneratedSource_PreservesAnonymousRecordNames()
        {
            const string source = "public _Level_e__Struct[] Level; public _LookupTable_e__Union[] LookupTable;";

            string normalized = InvokeNormalizeGeneratedSource(source, "Display.cs");

            Assert.Equal("public _Anonymous_e__Struct[] Level; public _Anonymous_e__Union[] LookupTable;", normalized);
        }

        private static void InvokeParseRspFile(string path, Dictionary<string, List<string>> settings)
        {
            MethodInfo parseRspFile = typeof(RemapDiscovery).Assembly.GetType("Program", throwOnError: true)!
                .GetMethod("ParseRspFile", BindingFlags.Static | BindingFlags.NonPublic)!;

            parseRspFile.Invoke(null, new object[] { path, settings });
        }

        private static string InvokeNormalizeGeneratedSource(string source, string outputPath)
        {
            MethodInfo normalizeGeneratedSource = typeof(RemapDiscovery).Assembly.GetType("Program", throwOnError: true)!
                .GetMethod("NormalizeGeneratedSource", BindingFlags.Static | BindingFlags.NonPublic)!;

            return (string)normalizeGeneratedSource.Invoke(null, new object[] { source, outputPath })!;
        }
    }
}
