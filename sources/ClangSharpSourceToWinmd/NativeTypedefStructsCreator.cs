using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using CsvHelper.Configuration;

namespace ClangSharpSourceToWinmd
{
    public static class NativeTypedefStructsCreator
    {
        public static void CreateNativeTypedefsSourceFile(IEnumerable<string> items, string outputFile)
        {
            if (items == null)
            {
                return;
            }

            if (!Directory.Exists(Path.GetDirectoryName(outputFile)))
            {
                Directory.CreateDirectory(Path.GetDirectoryName(outputFile));
            }

            CsvConfiguration config = new CsvConfiguration(CultureInfo.InvariantCulture) { MissingFieldFound = null };
            using (StringReader stringReader = new StringReader(ConvertLinesToCsvString(items)))
            using (CsvHelper.CsvReader reader = new CsvHelper.CsvReader(stringReader, config))
            using (StreamWriter writer = new StreamWriter(outputFile))
            {
                writer.Write(
@"using System;
using Windows.Win32.Interop;

");
                string currentNamespace = null;
                foreach (var item in reader.GetRecords<AutoType>().OrderBy(a => a.Namespace))
                {
                    string safety = item.ValueType.Contains("*") ? "unsafe " : string.Empty;
                    var valueType = item.ValueType;
                    if (valueType == "DECLARE_HANDLE" || valueType == "AllJoynHandle")
                    {
                        valueType = "IntPtr";
                    }

                    if (item.Namespace != currentNamespace)
                    {
                        if (currentNamespace != null)
                        {
                            writer.WriteLine("}");
                        }

                        currentNamespace = item.Namespace;
                        writer.WriteLine(
$@"namespace {currentNamespace}
{{");
                    }

                    if (!string.IsNullOrEmpty(item.CloseApi))
                    {
                        writer.WriteLine($"    [RAIIFree(\"{item.CloseApi}\")]");
                    }

                    if (!string.IsNullOrEmpty(item.AlsoUsableFor))
                    {
                        writer.WriteLine($"    [AlsoUsableFor(\"{item.AlsoUsableFor}\")]");
                    }

                    writer.WriteLine(
$@"    [NativeTypedef]    
    public {safety}struct {item.Name}
    {{
        public {valueType} Value;
    }}
");
                }

                if (currentNamespace != null)
                {
                    writer.WriteLine("}");
                }
            }
        }

        private static string ConvertLinesToCsvString(IEnumerable<string> items)
        {
            StringWriter writer = new StringWriter();
            writer.WriteLine("Namespace,Name,ValueType,CloseApi,AlsoUsableFor");
            foreach (var line in items)
            {
                writer.WriteLine(line);
            }

            return writer.ToString();
        }

        private class AutoType
        {
            public string Namespace { get; set; }
            public string Name { get; set; }
            public string ValueType { get; set; }
            public string CloseApi { get; set; }
            public string AlsoUsableFor { get; set; }
        }
    }
}
