using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace ClangSharpSourceToWinmd
{
    public static class NativeTypedefStructsCreator
    {
        public static void CreateNativeTypedefsSourceFile(Dictionary<string, string> methodNamesToNamespaces, IEnumerable<string> autoTypesFiles, string outputFile)
        {
            if (autoTypesFiles == null)
            {
                return;
            }

            IEnumerable<AutoType> items = GetAutoTypesFromFiles(autoTypesFiles);
            if (!items.Any())
            {
                return;
            }

            if (!Directory.Exists(Path.GetDirectoryName(outputFile)))
            {
                Directory.CreateDirectory(Path.GetDirectoryName(outputFile));
            }

            using (var writer = new StreamWriter(outputFile))
            {
                writer.Write(
@"using System;
using Windows.Win32.Interop;

");
                string currentNamespace = null;
                foreach (AutoType item in items.OrderBy(a => a.Namespace))
                {
                    string safety = item.ValueType.Contains("*") ? "unsafe " : string.Empty;
                    var valueType = item.ValueType;
                    if (valueType == "DECLARE_HANDLE" || valueType == "AllJoynHandle")
                    {
                        valueType = "IntPtr";
                    }

                    if (!string.IsNullOrEmpty(item.CloseApi))
                    {
                        if (!methodNamesToNamespaces.TryGetValue(item.CloseApi, out var apiNamespace))
                        {
                            throw new System.InvalidOperationException($"The API {item.CloseApi} was not found in the .cs files. The auto type {item.Name} needs to be given an explicit namespace.");
                        }

                        if (string.IsNullOrEmpty(item.Namespace))
                        {
                            if (apiNamespace.Contains(';'))
                            {
                                throw new System.InvalidOperationException($"The API {item.CloseApi} has multiple namespaces: {apiNamespace}. The auto type {item.Name} needs to be given an explicit namespace.");
                            }
                            else
                            {
                                item.Namespace = apiNamespace;
                            }
                        }
                    }

                    if (string.IsNullOrEmpty(item.Namespace))
                    {
                        throw new System.InvalidOperationException($"Autotype {item.Name} needs a namespace to be specified.");
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

        private static IEnumerable<AutoType> GetAutoTypesFromFiles(IEnumerable<string> fileNames)
        {
            IEnumerable<AutoType> ret = System.Array.Empty<AutoType>();
            foreach (var fileName in fileNames)
            {
                ret = ret.Concat(Newtonsoft.Json.JsonConvert.DeserializeObject<AutoType[]>(File.ReadAllText(fileName)));
            }

            return ret;
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
