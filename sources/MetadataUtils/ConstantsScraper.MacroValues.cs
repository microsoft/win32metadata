using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text.RegularExpressions;
using Microsoft.CodeAnalysis.CSharp;

namespace MetadataUtils
{
    public static partial class ConstantsScraper
    {
        private static readonly Regex MacroDefinitionRegex =
            new Regex(@"^\s*#\s*define\s+([_A-Za-z][\dA-Za-z_]*)(?:\([^)]*\))?(?:\s+(.*))?$");
        private static readonly Regex LeadingMacroReferenceRegex =
            new Regex(@"^\s*\(*\s*([_A-Za-z][\dA-Za-z_]*)(?:\s*\(|\s*\)*\s*$)");
        private static readonly Regex IntegerLiteralRegex =
            new Regex(@"\A(?<sign>[+-]?)\s*(?<digits>0x[\da-f]+|0b[01]+|\d+)(?<suffix>ull|llu|ul|lu|ll|u|l|ui64|i64)?\z",
                RegexOptions.IgnoreCase);
        private static readonly Regex SimpleCastRegex =
            new Regex(@"\A\(\s*(?<type>[_A-Za-z][\w: ]*(?:\s*\*)*)\s*\)\s*(?<value>.+)\z");
        private static readonly Regex SimpleCallRegex =
            new Regex(@"\A(?<name>[_A-Za-z]\w*)\s*\(\s*(?<value>.+)\s*\)\z");
        private static readonly HashSet<string> DeclarationKeywords = new HashSet<string>(
            ("extern namespace typedef using struct union enum class template public protected private " +
             "static inline constexpr consteval constinit virtual friend explicit export register thread_local " +
             "const volatile restrict __restrict __restrict__ void int short long signed unsigned char " +
             "float double bool wchar_t char16_t char32_t __int8 __int16 __int32 __int64 __ptr32 __ptr64 " +
             "__cdecl __stdcall __fastcall __thiscall __vectorcall __clrcall __unaligned __declspec " +
             "__attribute__ _Pragma asm __asm __asm__ static_assert _Static_assert do return break continue goto case default").Split(' '),
            StringComparer.Ordinal);
        private static readonly HashSet<string> FunctionalCastKeywords = new HashSet<string>(
            ("int short long signed unsigned char float double bool wchar_t char16_t char32_t " +
             "__int8 __int16 __int32 __int64").Split(' '), StringComparer.Ordinal);

        public static string[] ScanConstantMacroNames(IEnumerable<string> headers, IEnumerable<string> includeDirectories)
        {
            string[] roots = includeDirectories.Where(directory => !string.IsNullOrEmpty(directory))
                .Distinct(StringComparer.OrdinalIgnoreCase).ToArray();
            return headers.SelectMany(header => Path.IsPathRooted(header) ? new[] { header } :
                    roots.Select(directory => Path.Combine(directory, header)).Prepend(header))
                .Where(File.Exists).Select(Path.GetFullPath).Distinct(StringComparer.OrdinalIgnoreCase)
                .SelectMany(header => ReadConstantMacroNames(File.ReadLines(header)))
                .Distinct(StringComparer.Ordinal).OrderBy(name => name, StringComparer.Ordinal).ToArray();
        }

        public static IEnumerable<string> ReadConstantMacroNames(IEnumerable<string> lines)
        {
            string continuation = null;
            bool inComment = false;
            foreach (string currentLine in lines)
            {
                string line = continuation == null ? currentLine : continuation + currentLine;
                if (line.EndsWith("\\", StringComparison.Ordinal))
                {
                    continuation = line.Substring(0, line.Length - 1);
                    continue;
                }
                continuation = null;
                foreach (string name in ReadLine(RemoveComments(line, ref inComment)))
                    yield return name;
            }
            if (continuation != null)
                foreach (string name in ReadLine(RemoveComments(continuation, ref inComment)))
                    yield return name;

            static IEnumerable<string> ReadLine(string line)
            {
                Match definition = MacroDefinitionRegex.Match(line);
                if (!definition.Success)
                    yield break;
                yield return definition.Groups[1].Value;
                Match reference = LeadingMacroReferenceRegex.Match(definition.Groups[2].Value);
                if (reference.Success)
                    yield return reference.Groups[1].Value;
            }
        }

        public static string GetNonValueMacroReason(string value)
        {
            value = StripMacroParentheses(value);
            if (value.Length == 0)
                return "empty macro replacement";
            Match first = Regex.Match(value, @"\A([_A-Za-z]\w*)\b");
            if (first.Success && DeclarationKeywords.Contains(first.Value))
            {
                string rest = value.Substring(first.Length).TrimStart();
                if (!FunctionalCastKeywords.Contains(first.Value) || !rest.StartsWith("(", StringComparison.Ordinal))
                    return "declaration or statement fragment";
            }
            int parentheses = 0;
            int braces = 0;
            char quote = '\0';
            for (int index = 0; index < value.Length; index++)
            {
                char character = value[index];
                if (quote != '\0')
                {
                    if (character == '\\')
                        index++;
                    else if (character == quote)
                        quote = '\0';
                    continue;
                }
                if (character is '"' or '\'')
                    quote = character;
                else if (character == '(')
                    parentheses++;
                else if (character == ')')
                    parentheses--;
                else if (character == '{')
                    braces++;
                else if (character == '}' && --braces < 0)
                    return "unmatched scope-closing fragment";
                else if (character == ';' && parentheses <= 0 && braces == 0)
                    return "declaration or statement fragment";
            }
            return null;
        }

        public static string GetWholeMacroInvocation(string value)
        {
            value = StripMacroParentheses(value);
            Match match = SimpleCallRegex.Match(value);
            if (!match.Success)
                return null;
            string arguments = value.Substring(value.IndexOf('('));
            return StripMacroParentheses(arguments) != arguments ? match.Groups["name"].Value : null;
        }

        public static bool TryReadSimpleMacroValue(string value, bool cplusplus, bool windowsTarget,
            Func<string, string> storageOfType, Func<string, string> directCastWrapper,
            out SimpleMacroValue result)
        {
            result = null;
            value = StripMacroParentheses(value);
            if (GetNonValueMacroReason(value) != null)
                return false;
            if (windowsTarget && TryReadIntegerLiteral(value, out result))
                return true;
            if (cplusplus && value is "true" or "false")
            {
                result = new SimpleMacroValue("Integer", "bool", "bool", value);
                return true;
            }
            if (ConstantsScraperImpl.TryTranslateStringConstant(value, "", "", out string expression,
                out bool utf16, rejectUnsupported: false))
            {
                result = new SimpleMacroValue("String", null, "string", expression);
                return true;
            }
            string legacyValue = Regex.Replace(value, @"\A(-)\s+", "$1");
            Match legacy = ConstantsScraperImpl.DefineConstantRegex.Match(legacyValue);
            if (legacy.Success && legacy.Groups[6].Success)
            {
                result = new SimpleMacroValue("Floating", legacyValue.EndsWith("f", StringComparison.OrdinalIgnoreCase) ?
                    "float" : "double", null, legacyValue);
                return true;
            }
            if (legacy.Success && (legacy.Groups[25].Success || legacy.Groups[31].Success))
            {
                result = new SimpleMacroValue("Guid", "GUID", null, value);
                return true;
            }
            Match cast = SimpleCastRegex.Match(value);
            string castType = cast.Success ? Regex.Replace(cast.Groups["type"].Value.Trim(), @"\s+", " ") : null;
            string operand = cast.Success ? cast.Groups["value"].Value : null;
            if (castType == null)
            {
                Match call = SimpleCallRegex.Match(value);
                if (call.Success)
                {
                    castType = directCastWrapper(call.Groups["name"].Value);
                    operand = call.Groups["value"].Value;
                }
            }
            if (castType == null || !windowsTarget || !TryReadIntegerLiteral(StripMacroParentheses(operand), out var integer))
                return false;
            castType = CanonicalBuiltinType(castType);
            string storage = storageOfType(castType);
            if (storage == null)
                return false;
            result = storage == "pointer"
                ? new SimpleMacroValue("Pointer", castType, null, integer.Value)
                : ConvertSimpleInteger(integer, castType, storage);
            return result != null;
        }

        private static string CanonicalBuiltinType(string type) => type switch
        {
            "signed" or "signed int" => "int",
            "unsigned" => "unsigned int",
            "short int" or "signed short" or "signed short int" => "short",
            "unsigned short int" => "unsigned short",
            "long int" or "signed long" or "signed long int" => "long",
            "unsigned long int" => "unsigned long",
            "long long int" or "signed long long" or "signed long long int" => "long long",
            "unsigned long long int" => "unsigned long long",
            _ => type,
        };

        public static string StripMacroParentheses(string value)
        {
            value = value.Trim();
            while (value.Length >= 2 && value[0] == '(' && value[value.Length - 1] == ')')
            {
                int depth = 0;
                bool enclosing = true;
                char quote = '\0';
                for (int index = 0; index < value.Length; index++)
                {
                    char character = value[index];
                    if (quote != '\0')
                    {
                        if (character == '\\')
                            index++;
                        else if (character == quote)
                            quote = '\0';
                        continue;
                    }
                    if (character is '"' or '\'')
                        quote = character;
                    else if (character == '(')
                        depth++;
                    else if (character == ')' && --depth == 0 && index != value.Length - 1)
                    {
                        enclosing = false;
                        break;
                    }
                }
                if (!enclosing || depth != 0)
                    break;
                value = value.Substring(1, value.Length - 2).Trim();
            }
            return value;
        }

        private static bool TryReadIntegerLiteral(string value, out SimpleMacroValue result)
        {
            result = null;
            Match match = IntegerLiteralRegex.Match(value);
            if (!match.Success)
                return false;
            string digits = match.Groups["digits"].Value;
            string suffix = ConstantWriter.GetIntegerLiteralSuffix(value, nativeSuffixes: true);
            if (suffix.Contains("lL", StringComparison.Ordinal) || suffix.Contains("Ll", StringComparison.Ordinal))
                return false;
            bool hex = digits.StartsWith("0x", StringComparison.OrdinalIgnoreCase);
            bool binary = digits.StartsWith("0b", StringComparison.OrdinalIgnoreCase);
            bool octal = !hex && !binary && digits.Length > 1 && digits[0] == '0';
            ulong magnitude;
            try
            {
                magnitude = hex ? ulong.Parse(digits.Substring(2), NumberStyles.AllowHexSpecifier, CultureInfo.InvariantCulture) :
                    binary ? Convert.ToUInt64(digits.Substring(2), 2) :
                    octal ? Convert.ToUInt64(digits, 8) : ulong.Parse(digits, CultureInfo.InvariantCulture);
            }
            catch (Exception exception) when (exception is FormatException or OverflowException)
            {
                return false;
            }
            bool unsigned = suffix.IndexOf('u', StringComparison.OrdinalIgnoreCase) >= 0;
            int width = suffix.EndsWith("i64", StringComparison.OrdinalIgnoreCase) ||
                suffix.IndexOf("ll", StringComparison.OrdinalIgnoreCase) >= 0 ? 64 : 32;
            bool hasLong = suffix.IndexOf('l', StringComparison.OrdinalIgnoreCase) >= 0;
            string native = width == 64 ? "long long" : hasLong ? "long" : "int";
            if (!unsigned && magnitude > (ulong)(width == 32 ? int.MaxValue : long.MaxValue))
            {
                if ((hex || binary || octal) && magnitude <= (width == 32 ? uint.MaxValue : ulong.MaxValue))
                    unsigned = true;
                else
                {
                    width = 64;
                    native = "long long";
                    if (magnitude > long.MaxValue)
                    {
                        if (!hex && !binary && !octal)
                            return false;
                        unsigned = true;
                    }
                }
            }
            if (unsigned && width == 32 && magnitude > uint.MaxValue)
            {
                width = 64;
                native = "long long";
            }
            string storage = unsigned ? width == 32 ? "uint" : "ulong" : width == 32 ? "int" : "long";
            ulong bits = match.Groups["sign"].Value == "-" ? unchecked(0UL - magnitude) : magnitude;
            result = FromBits(bits, (unsigned ? "unsigned " : "") + native, storage);
            return true;
        }

        private static SimpleMacroValue ConvertSimpleInteger(SimpleMacroValue value, string nativeType, string storage)
        {
            if (storage is not ("sbyte" or "byte" or "short" or "ushort" or "int" or "uint" or "long" or "ulong" or "char" or "bool"))
                return null;
            string number = value.Value.TrimEnd('U', 'L');
            ulong bits = value.StorageType is "uint" or "ulong" ?
                ulong.Parse(number, CultureInfo.InvariantCulture) : unchecked((ulong)long.Parse(number, CultureInfo.InvariantCulture));
            return FromBits(bits, nativeType, storage);
        }

        private static SimpleMacroValue FromBits(ulong bits, string nativeType, string storage)
        {
            string number = storage switch
            {
                "sbyte" => unchecked((sbyte)bits).ToString(CultureInfo.InvariantCulture),
                "byte" => unchecked((byte)bits).ToString(CultureInfo.InvariantCulture),
                "short" => unchecked((short)bits).ToString(CultureInfo.InvariantCulture),
                "ushort" => unchecked((ushort)bits).ToString(CultureInfo.InvariantCulture),
                "int" => unchecked((int)bits).ToString(CultureInfo.InvariantCulture),
                "uint" => unchecked((uint)bits).ToString(CultureInfo.InvariantCulture) + "U",
                "long" => unchecked((long)bits).ToString(CultureInfo.InvariantCulture) + "L",
                "ulong" => bits.ToString(CultureInfo.InvariantCulture) + "UL",
                "bool" => bits == 0 ? "false" : "true",
                "char" => SymbolDisplay.FormatLiteral(unchecked((char)bits), quote: true),
                _ => throw new InvalidOperationException($"Unsupported simple constant storage '{storage}'."),
            };
            return new SimpleMacroValue("Integer", nativeType, storage, number);
        }
    }

    public sealed record SimpleMacroValue(string Kind, string NativeType, string StorageType, string Value);
}
