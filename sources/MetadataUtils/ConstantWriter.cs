using System;
using System.Collections.Generic;
using System.IO;
using System.Text.RegularExpressions;

namespace MetadataUtils
{
    public class ConstantWriter : IDisposable, IConstantWriter
    {
        private Stream outputStream;
        private string @namespace;
        private string headerText;
        private string className;
        private StreamWriter writer;
        private Dictionary<string, string> namesToValues = new Dictionary<string, string>();
        private Dictionary<string, string> withAttributes;

        public ConstantWriter(Stream outputStream, string @namespace, string sourceHeaderText, Dictionary<string, string> withAttributes, string className = "Apis")
        {
            sourceHeaderText ??= string.Empty;

            this.outputStream = outputStream;
            this.@namespace = @namespace;
            this.headerText = sourceHeaderText;
            this.withAttributes = withAttributes;
            this.className = className;

            this.namesToValues["TRUE"] = "1";
            this.namesToValues["FALSE"] = "0";
        }

        private StreamWriter Writer
        {
            get
            {
                if (this.writer == null)
                {
                    this.EnsureStarted();
                }

                return this.writer;
            }
        }

        public void AddPropKey(string structType, string name, string args)
        {
            if (this.namesToValues.ContainsKey(name))
            {
                return;
            }

            this.namesToValues[name] = args;

            this.Writer.WriteLine(
$@"        [Constant({args})]
        public static readonly {structType} {name};");

            this.Writer.WriteLine();
        }

        public void AddGuid(string name, string args)
        {
            if (this.namesToValues.ContainsKey(name))
            {
                return;
            }

            this.namesToValues[name] = args;

            this.Writer.WriteLine(
$@"        public static readonly Guid {name}__scanned__ = new Guid({args});");

            this.Writer.WriteLine();
        }

        public void AddValue(string type, string name, string valueText, string context = "")
        {
            this.namesToValues[name] = valueText;

            if (this.withAttributes.TryGetValue(name, out var extraAttributes))
            {
                this.Writer.WriteLine(
$"        [{extraAttributes}]");
            }

            if (type == "string" && context == "ansi")
            {
                this.Writer.WriteLine(
$"        [NativeEncoding(\"{context}\")]");
            }

            this.Writer.WriteLine(
$"        public const {type} {name} = {valueText};");

            this.Writer.WriteLine();
        }

        public void AddNativeInteger(NativeConstantValue value)
        {
            string name = Microsoft.CodeAnalysis.CSharp.SyntaxFacts.GetKeywordKind(value.Name) ==
                Microsoft.CodeAnalysis.CSharp.SyntaxKind.None ? value.Name : "@" + value.Name;
            this.Writer.WriteLine($"        [NativeTypeName({Microsoft.CodeAnalysis.CSharp.SymbolDisplay.FormatLiteral(value.NativeType, true)})]");
            this.AddValue(value.StorageType, name, value.Value);
        }

        public static string FixIntValueText(bool forceUnsigned, ref string type, string valueText)
        {
            if (valueText.Length > 0 && (char.IsLetter(valueText[0]) || valueText[0] == '_'))
            {
                // This means our value is probably using an enum or some other expresssion,
                // so don't mess with the valueText

                // Set the type to something
                if (type != "int")
                {
                    type = "uint";
                }

                return valueText;
            }

            string suffix = GetIntegerLiteralSuffix(valueText);
            bool signed = suffix.Length != 0 && !suffix.StartsWith("u", StringComparison.OrdinalIgnoreCase);
            bool is64Bit = suffix.Contains("ll", StringComparison.OrdinalIgnoreCase) ||
                suffix.EndsWith("i64", StringComparison.OrdinalIgnoreCase);
            valueText = valueText.Substring(0, valueText.Length - suffix.Length);

            if (valueText.StartsWith('-'))
            {
                signed = true;
            }

            if (type == "int" || type == "long")
            {
                signed = true;
            }

            if (forceUnsigned)
            {
                signed = false;
            }

            if (valueText.StartsWith("0x"))
            {
                bool uncheckedNeeded;

                if (valueText.Length > 10)
                {
                    ulong value = ulong.Parse(valueText.Substring(2), System.Globalization.NumberStyles.HexNumber);
                    is64Bit = true;
                    uncheckedNeeded = signed && value > long.MaxValue;
                }
                else
                {
                    uint value = uint.Parse(valueText.Substring(2), System.Globalization.NumberStyles.HexNumber);
                    uncheckedNeeded = signed && value > int.MaxValue;
                }

                if (uncheckedNeeded)
                {
                    valueText = $"unchecked((int){valueText})";
                }
            }

            var unsignedOverflowRegex = new Regex(@"^\d+U\s*[\+\-]");
            if (unsignedOverflowRegex.IsMatch(valueText))
            {
                valueText = $"unchecked((uint){valueText})";
            }

            if (!is64Bit)
            {
                type = signed ? "int" : "uint";
            }
            else
            {
                type = signed ? "long" : "ulong";
            }

            return valueText;
        }

        internal static string GetIntegerLiteralSuffix(string valueText, bool nativeSuffixes = false)
        {
            if (nativeSuffixes)
                foreach (string suffix in new[] { "LLU", "LU" })
                    if (valueText.EndsWith(suffix, StringComparison.OrdinalIgnoreCase))
                        return valueText.Substring(valueText.Length - suffix.Length);
            foreach (string suffix in new[] { "ULL", "UL", "U", "LL", "L", "ui64", "i64" })
                if (valueText.EndsWith(suffix, StringComparison.OrdinalIgnoreCase))
                    return valueText.Substring(valueText.Length - suffix.Length);
            return "";
        }

        public void AddShort(string nativeTypeName, string name, string valueText, out string finalType)
        {
            if (nativeTypeName == "LPCWSTR" || nativeTypeName == "LPCSTR")
            {
                finalType = "ushort";
                if (valueText.StartsWith("-"))
                {
                    valueText = $"unchecked((ushort) {valueText})";
                }
            }
            else
            {
                finalType = "short";
            }

            if (!string.IsNullOrWhiteSpace(nativeTypeName))
            {
                this.Writer.WriteLine($"[NativeTypeName(\"{nativeTypeName}\")]");
            }

            this.AddValue(finalType, name, valueText);
        }

        public void AddInt(string forceType, string nativeTypeName, string name, string valueText, out string finalType)
        {
            finalType = null;

            if (this.namesToValues.ContainsKey(name))
            {
                return;
            }

            string type = null;
            if (nativeTypeName == "HRESULT" || nativeTypeName == "NTSTATUS" || nativeTypeName == "LPCWSTR" || nativeTypeName == "LPCSTR" || nativeTypeName == "HWND")
            {
                type = "int";
            }
            else if (nativeTypeName == "DWORD")
            {
                forceType = "uint";
            }

            bool forceUnsigned = forceType == "uint" || forceType == "ulong";
            valueText = FixIntValueText(forceUnsigned, ref type, valueText);

            if (nativeTypeName != null)
            {
                this.Writer.WriteLine(
$"        [NativeTypeName(\"{nativeTypeName}\")]");
            }

            finalType = forceType != null ? forceType : type;

            this.AddValue(finalType, name, valueText);
        }

        private void EnsureStarted()
        {
            if (this.writer == null)
            {
                this.writer = new StreamWriter(this.outputStream);
                this.writer.WriteLine(
@$"{this.headerText}
namespace {this.@namespace}
{{
    public static partial class {this.className}
    {{");
            }
        }

        public void Dispose()
        {
            if (this.writer != null)
            {
                this.writer.WriteLine(
@"    }
}");
                this.writer.Close();
                this.writer.Dispose();
                this.writer = null;
            }
        }
    }
}
