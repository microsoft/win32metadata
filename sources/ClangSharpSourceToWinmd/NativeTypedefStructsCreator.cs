using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace ClangSharpSourceToWinmd
{
    public static class NativeTypedefStructsCreator
    {
        public static void WriteToStream(Dictionary<string, string> methodNamesToNamespaces, IEnumerable<AutoType> items, Stream output)
        {
            using var writer = new StreamWriter(output, leaveOpen: true);
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
                else if (valueType == "DECLARE_OPAQUE_KEY")
                {
                    valueType = "long";
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

                if (item.InvalidHandleValues != null)
                {
                    foreach (var invalidHandle in item.InvalidHandleValues)
                    {
                        writer.WriteLine($"    [InvalidHandleValue({invalidHandle})]");
                    }
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
}
