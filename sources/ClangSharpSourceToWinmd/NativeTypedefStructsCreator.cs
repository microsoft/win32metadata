using System.Collections.Generic;
using System.IO;

namespace ClangSharpSourceToWinmd
{
    public static class NativeTypedefStructsCreator
    {
        public static void CreateNativeTypedefsSourceFile(IEnumerable<string> items, string outputFile)
        {
            List<string> sortedItems = new List<string>(items);
            sortedItems.Sort();

            using (StreamWriter writer = new StreamWriter(outputFile))
            {
                writer.Write(
@"using System;
using Windows.Win32.Interop;

");
                string currentNamespace = null;
                foreach (var item in sortedItems)
                {
                    string[] parts = item.Split(',');
                    string itemNamespace = parts[0];
                    string itemName = parts[1];
                    string valueType = parts[2];
                    string closeApi = parts.Length > 3 ? parts[3] : null;

                    if (itemNamespace != currentNamespace)
                    {
                        if (currentNamespace != null)
                        {
                            writer.WriteLine("}");
                        }

                        currentNamespace = itemNamespace;
                        writer.WriteLine(
$@"namespace {currentNamespace}
{{");
                    }

                    if (!string.IsNullOrEmpty(closeApi))
                    {
                        writer.WriteLine($"    [RAIIFree(\"{closeApi}\")]");
                    }

                    writer.WriteLine(
$@"    [NativeTypedef]    
    public struct {itemName}
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
}
