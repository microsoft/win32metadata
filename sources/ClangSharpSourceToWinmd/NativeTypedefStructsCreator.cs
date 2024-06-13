using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace ClangSharpSourceToWinmd
{
    public static class NativeTypedefStructsCreator
    {
        public static void WriteToStream(Dictionary<string, string> apiNamesToNamespaces, IEnumerable<AutoType> items, Stream output)
        {
            Dictionary<string, string> autotypesToNamespaces = new Dictionary<string, string>();
            string currentNamespace = null;

            using var writer = new StreamWriter(output, leaveOpen: true);
            writer.Write(
@"using System;
using Windows.Win32.Foundation.Metadata;

");

            foreach (AutoType item in items.OrderBy(a => a.Namespace))
            {
                string safety = item.ValueType.Contains("*") ? "unsafe " : string.Empty;
                var valueType = item.ValueType;
                if (valueType == "DECLARE_HANDLE")
                {
                    safety = "unsafe ";
                    valueType = "void*";
                    item.NativeTypedef = true;
                }
                else if (valueType == "AllJoynHandle")
                {
                    valueType = "IntPtr";
                    item.NativeTypedef = true;
                }
                else if (valueType == "DECLARE_OPAQUE_KEY")
                {
                    valueType = "long";
                    item.NativeTypedef = true;
                }
                else if (valueType.StartsWith("typedef struct"))
                {
                    valueType = "IntPtr";
                    item.NativeTypedef = true;
                }

                if (!string.IsNullOrEmpty(item.CloseApi))
                {
                    if (!apiNamesToNamespaces.TryGetValue(item.CloseApi, out var apiNamespace))
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
$@"    [{(item.NativeTypedef ? "NativeTypedef" : "MetadataTypedef")}]
    public {safety}struct {item.Name}
    {{
        public {valueType} Value;
    }}
");

                autotypesToNamespaces.Add(item.Name, item.Namespace);
            }

            if (currentNamespace != null)
            {
                writer.WriteLine("}");
            }

            // Enforce that all CloseApi relationships exist in the same namespace.
            var closeApiNamespaceMismatches = items.Where(a => !string.IsNullOrEmpty(a.CloseApi) && autotypesToNamespaces[a.Name] != apiNamesToNamespaces[a.CloseApi]);
            if (closeApiNamespaceMismatches.Any())
            {
                throw new System.InvalidOperationException($"{string.Join(", ", closeApiNamespaceMismatches.Select((a, i) => a.Name))} not in the same namespace as CloseApi. CloseApi relationships must exist in the same namespace.");
            }

            // Enforce that all AlsoUsableFor relationships exist in the same namespace.
            var alsoUsableForNamespaceMismatches = items.Where(a => !string.IsNullOrEmpty(a.AlsoUsableFor) && autotypesToNamespaces[a.Name] != autotypesToNamespaces[a.AlsoUsableFor]);
            if (alsoUsableForNamespaceMismatches.Any())
            {
                throw new System.InvalidOperationException($"{string.Join(", ", alsoUsableForNamespaceMismatches.Select((a, i) => a.Name))} not in the same namespace as AlsoUsableFor. AlsoUsableFor relationships must exist in the same namespace.");
            }
        }
    }
}
