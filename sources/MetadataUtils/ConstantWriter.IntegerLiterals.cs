#nullable enable
using System;
using System.Text.RegularExpressions;

namespace MetadataUtils
{
    public partial class ConstantWriter
    {
        public static string FixIntValueText(bool forceUnsigned, ref string? type, string valueText)
        {
            if (valueText.Length > 0 && (char.IsLetter(valueText[0]) || valueText[0] == '_'))
            {
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
    }
}
