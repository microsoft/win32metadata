#nullable enable
using System;
using System.Linq;
using System.Text.RegularExpressions;

namespace MetadataUtils
{
    public static partial class ConstantsScraper
    {
        internal static readonly Regex DefineConstantRegex =
            new Regex(
                @"^((_HRESULT_TYPEDEF_|_NDIS_ERROR_TYPEDEF_)\(((?:0x)?[\da-f]+L?)\)|(\(HRESULT\)((?:0x)?[\da-f]+L?))|(-?\d+\.\d+(?:e\+\d+)?f?)|((?:0x[\da-f]+|\-?\d+)(?:UL|L)?)|((\d+)\s*(<<\s*\d+))|(MAKEINTRESOURCE[AW]{0,1}\(\s*(\-?\d+)\s*\))|(\(HWND\)(-?\d+|(?:0x)?[\da-f]+))|([a-z0-9_]+U?\s*[\+\-]\s*(\d+|0x[0-de-f]+)U?)|(\(NTSTATUS\)((?:0x)?[\da-f]+L?))|(\s*\(DWORD\)\s*\(?\s*-1(L|\b)\s*\)?)|(\(DWORD\)((?:0x)?[\da-f]+L?))|(\(BCRYPT_ALG_HANDLE\)\s*((?:0x)?[\da-f]+L?))|(\{\s*(?:(?:0x)?[\da-f]{4,8}L?,?\s*){3}\s*\{\s*(?:(?:0x)?[\da-f]{1,2}L?,?\s*){8}\s*\}\s*\})|(HIDP_ERROR_CODES\((.*),(.*)\))|(MAKEDIPROP\(\s*(\d+)\s*\))|(\{\s*(?:(?:0x)?[\da-f]{4,8}L?,?\s*){3}\s*(?:(?:0x)?[\da-f]{1,2}L?,?\s*){8}\s*\})|(\(UCHAR\)\s*((?:0x)?\d+))|(\(UCHAR\)\s*(-\d+))|(\(BYTE\)((?:0x)?[\da-f]+L?))|(0x[\da-f]+\s*<<\s*\d+)||(0x[\da-f]+ui64\s*<<\s*\d+)|([a-z0-9_]+))$", RegexOptions.IgnoreCase);

        internal static string? LegacyNativeTypeName(string value)
        {
            var match = DefineConstantRegex.Match(value);
            if (match.Groups[2].Value == "_HRESULT_TYPEDEF_" || match.Groups[5].Success)
                return "HRESULT";
            if (match.Groups[11].Success)
                return match.Groups[11].Value.StartsWith("MAKEINTRESOURCEA", StringComparison.Ordinal) ? "LPCSTR" : "LPCWSTR";
            if (match.Groups[13].Success)
                return "HWND";
            if (match.Groups[17].Success || match.Groups[26].Success)
                return "NTSTATUS";
            if (match.Groups[20].Success || match.Groups[21].Success)
                return "DWORD";
            if (match.Groups[23].Success)
                return "BCRYPT_ALG_HANDLE";
            return null;
        }

        internal static bool LegacyEnumAutoPopulationValue(string expression)
        {
            string value = StripComments(expression.Trim());
            if (value.StartsWith('(') && value.EndsWith(')'))
                value = value.Substring(1, value.Length - 2).Trim();
            var match = DefineConstantRegex.Match(value);
            return LegacyNativeTypeName(value) == null &&
                !new[] { 6, 25, 29, 31, 32, 34, 36, 38, 39 }.Any(group => match.Groups[group].Success) &&
                !Regex.IsMatch(value, @"^(CTL_CODE\(|\(USAGE\)\s*0x|AUDCLNT_ERR\(|AUDCLNT_SUCCESS\(|MAKE_HRESULT\(|MAKE_SCODE\(|\((LPCSTR|LPCWSTR)\)\s*\d+|_WSAIO(R|W|RW)?\()");
        }

        private static string StripComments(string rawValue)
        {
            bool inQuote = false;
            for (int i = 0; i <= rawValue.Length - 2; i++)
            {
                if (rawValue[i] == '\"')
                    inQuote = !inQuote;
                if (!inQuote && rawValue[i] == '/')
                {
                    if (rawValue[i + 1] == '/')
                        return rawValue.Substring(0, i).Trim();
                    if (rawValue[i + 1] == '*')
                    {
                        if (rawValue.LastIndexOf("*/", StringComparison.Ordinal) == -1)
                            return rawValue.Substring(0, i).Trim();
                        return rawValue.Substring(0, i).Trim() +
                            rawValue.Substring(rawValue.LastIndexOf("*/", StringComparison.Ordinal) + 2).Trim();
                    }
                }
            }
            return rawValue;
        }

        private static string RemoveComments(string line, ref bool inComment)
        {
            var text = new System.Text.StringBuilder(line.Length);
            char quote = '\0';
            for (int index = 0; index < line.Length; index++)
            {
                char character = line[index];
                if (inComment)
                {
                    if (character == '*' && index + 1 < line.Length && line[index + 1] == '/')
                    {
                        inComment = false;
                        index++;
                    }
                    continue;
                }
                if (quote != '\0')
                {
                    text.Append(character);
                    if (character == '\\' && index + 1 < line.Length)
                        text.Append(line[++index]);
                    else if (character == quote)
                        quote = '\0';
                    continue;
                }
                if (character is '"' or '\'')
                    quote = character;
                if (character == '/' && index + 1 < line.Length)
                {
                    if (line[index + 1] == '/')
                        break;
                    if (line[index + 1] == '*')
                    {
                        inComment = true;
                        text.Append(' ');
                        index++;
                        continue;
                    }
                }
                text.Append(character);
            }
            return text.ToString();
        }
    }
}
