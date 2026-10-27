using System.Collections.Generic;
using System.IO;
using System.Linq;
using MetadataUtils;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;

namespace ClangSharpSourceToWinmd
{
    public static class NativeTypedefStructsCreator
    {
        public static void WriteToStream(Dictionary<string, string> apiNamesToNamespaces, IEnumerable<AutoType> items, Stream output)
        {
            items = items.ToArray();
            var validation = new GenerationValidation();
            Validate(apiNamesToNamespaces, items, validation);
            validation.ThrowIfAny();
            Dictionary<string, string> autotypesToNamespaces = new Dictionary<string, string>();
            string currentNamespace = null;

            using var writer = new StreamWriter(output, leaveOpen: true);
            writer.Write(
@"using System;
using Windows.Win32.Foundation.Metadata;

");

            foreach (AutoType item in items.OrderBy(a => a.Namespace))
            {
                bool explicitWrapperIntent = item.NativeTypedef;
                bool nativeTypedef = item.NativeTypedef;
                string safety = item.ValueType.Contains("*") ? "unsafe " : string.Empty;
                var valueType = item.ValueType;
                if (valueType == "DECLARE_HANDLE")
                {
                    safety = "unsafe ";
                    valueType = "void*";
                    nativeTypedef = true;
                }
                else if (valueType == "AllJoynHandle")
                {
                    valueType = "IntPtr";
                    nativeTypedef = true;
                }
                else if (valueType == "DECLARE_OPAQUE_KEY")
                {
                    valueType = "long";
                    nativeTypedef = true;
                }
                else if (valueType.StartsWith("typedef struct"))
                {
                    valueType = "IntPtr";
                    nativeTypedef = true;
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

                if (item.ValueType == "DECLARE_HANDLE")
                {
                    var declaration = (StructDeclarationSyntax)SyntaxFactory.ParseMemberDeclaration(
                        $"public unsafe struct {item.Name} {{ public void* Value; }}");
                    var proven = NativeHandleSourceProvenance.AttachRetainedDeclareHandle(declaration, item.Name);
                    writer.WriteLine("    " + proven.GetLeadingTrivia().ToFullString().Trim());
                }
                else if (explicitWrapperIntent &&
                    NativeHandleSourceProvenance.TryParseRetainedOpaqueStructFactory(item.ValueType, out string nativeTag))
                {
                    var declaration = (StructDeclarationSyntax)SyntaxFactory.ParseMemberDeclaration(
                        $"public struct {item.Name} {{ public IntPtr Value; }}");
                    var proven = NativeHandleSourceProvenance.AttachRetainedOpaqueStructPointer(
                        declaration, item.Name, nativeTag, explicitWrapperIntent);
                    writer.WriteLine("    " + proven.GetLeadingTrivia().ToFullString().Trim());
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
$@"    [{(nativeTypedef ? "NativeTypedef" : "MetadataTypedef")}]
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

        internal static void Validate(Dictionary<string, string> apiNamesToNamespaces, IEnumerable<AutoType> items,
            GenerationValidation validation)
        {
            var namespaces = new Dictionary<string, string>(System.StringComparer.Ordinal);
            var declarations = items?.ToArray() ?? System.Array.Empty<AutoType>();
            foreach (var item in declarations)
            {
                if (item == null || string.IsNullOrWhiteSpace(item.Name) || string.IsNullOrWhiteSpace(item.ValueType))
                {
                    Record(item, "An auto type requires nonempty Name and ValueType.");
                    continue;
                }
                string ns = item.Namespace;
                if (!string.IsNullOrEmpty(item.CloseApi))
                {
                    if (!apiNamesToNamespaces.TryGetValue(item.CloseApi, out string apiNamespace))
                        Record(item, $"The API {item.CloseApi} was not found in the .cs files. The auto type {item.Name} needs to be given an explicit namespace.");
                    else if (string.IsNullOrEmpty(ns))
                    {
                        if (apiNamespace.Contains(';'))
                            Record(item, $"The API {item.CloseApi} has multiple namespaces: {apiNamespace}. The auto type {item.Name} needs to be given an explicit namespace.");
                        else
                            ns = apiNamespace;
                    }
                    else if (ns != apiNamespace)
                        Record(item, $"{item.Name} not in the same namespace as CloseApi. CloseApi relationships must exist in the same namespace.");
                }
                if (string.IsNullOrEmpty(ns))
                    Record(item, $"Autotype {item.Name} needs a namespace to be specified.");
                if (!namespaces.TryAdd(item.Name, ns))
                    Record(item, $"Multiple auto type declarations use the name '{item.Name}'.");
            }
            foreach (var item in declarations.Where(item => item != null && !string.IsNullOrEmpty(item.Name) &&
                !string.IsNullOrEmpty(item.AlsoUsableFor)))
            {
                if (!namespaces.TryGetValue(item.AlsoUsableFor, out string targetNamespace))
                    Record(item, $"Auto type '{item.Name}' refers to missing AlsoUsableFor type '{item.AlsoUsableFor}'.");
                else if (namespaces.GetValueOrDefault(item.Name) != targetNamespace)
                    Record(item, $"{item.Name} not in the same namespace as AlsoUsableFor. AlsoUsableFor relationships must exist in the same namespace.");
            }

            void Record(AutoType item, string message) => validation.Add(new System.InvalidOperationException(message),
                "CSSW006", "emitter.auto-type-validation", item?.InputPath, item?.Name);
        }
    }
}
