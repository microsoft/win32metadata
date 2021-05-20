using System;
using System.Collections.Generic;
using System.IO;

namespace MetadataUtils
{
    public class ConstantWriter : IDisposable
    {
        private string path;
        private string @namespace;
        private string headerText;
        private StreamWriter writer;
        private Dictionary<string, string> namesToValues = new Dictionary<string, string>();
        private Dictionary<string, string> withAttributes;

        public ConstantWriter(string path, string @namespace, string sourceHeaderText, Dictionary<string, string> withAttributes)
        {
            this.path = path;
            this.@namespace = @namespace;
            this.headerText = sourceHeaderText;
            this.withAttributes = withAttributes;

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

        public void AddPropKey(string name, string args)
        {
            if (this.namesToValues.ContainsKey(name))
            {
                return;
            }

            this.namesToValues[name] = args;

            this.Writer.WriteLine(
$@"        [PropertyKey({args})]
        public static readonly PROPERTYKEY {name};");

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

        public void AddValue(string type, string name, string valueText)
        {
            this.namesToValues[name] = valueText;

            if (this.withAttributes.TryGetValue(name, out var extraAttributes))
            {
                this.Writer.WriteLine(
$"        [{extraAttributes}]");
            }

            this.Writer.WriteLine(
$"        public const {type} {name} = {valueText};");

            this.Writer.WriteLine();
        }

        public static string FixIntValueText(bool forceUnsigned, ref string type, string valueText)
        {
            if (valueText.Length > 0 && char.IsLetter(valueText[0]))
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

            bool signed = false;
            bool is64Bit = false;

            if (valueText.EndsWith("UL") || valueText.EndsWith("ul"))
            {
                signed = false;
                valueText = valueText.Substring(0, valueText.Length - 2);
            }
            else if (valueText.EndsWith('L') || valueText.EndsWith('l'))
            {
                signed = true;
                valueText = valueText.Substring(0, valueText.Length - 1);
            }

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

        public void AddInt(string forceType, string nativeTypeName, string name, string valueText)
        {
            if (this.namesToValues.ContainsKey(name))
            {
                return;
            }

            string type = null;
            if (nativeTypeName == "HRESULT" || nativeTypeName == "LPCWSTR" || nativeTypeName == "HWND")
            {
                type = "int";
            }

            bool forceUnsigned = forceType == "uint" || forceType == "ulong";
            valueText = FixIntValueText(forceUnsigned, ref type, valueText);

            if (nativeTypeName != null)
            {
                this.Writer.WriteLine(
$"        [NativeTypeName(\"{nativeTypeName}\")]");
            }

            string finalType = forceType != null ? forceType : type;

            this.AddValue(finalType, name, valueText);
        }

        private void EnsureStarted()
        {
            if (this.writer == null)
            {
                this.writer = new StreamWriter(this.path);
                this.writer.WriteLine(
@$"{this.headerText}

namespace {this.@namespace}
{{
    public static partial class Apis
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
