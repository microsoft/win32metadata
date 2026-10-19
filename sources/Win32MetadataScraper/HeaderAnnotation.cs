using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text.RegularExpressions;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;

namespace Win32MetadataScraper
{
    internal sealed record HeaderAnnotation(string Name, IReadOnlyList<string> Arguments)
    {
        internal const string OwnerPrefix = "Win32Metadata.";

        private static readonly HashSet<string> Names = new(StringComparer.Ordinal)
        {
            "SetLastError", "ImportLibrary", "SupportedOSPlatform", "PreserveResult",
            "RAIIFree", "Retained", "ContainsInteriorPointers", "RetVal", "Reserved",
            "AlsoUsableFor", "AssociatedEnum", "AssociatedConstant", "Enum", "FlagsEnum",
            "Optional", "ComOutPtr",
        };

        private static readonly HashSet<string> SupportedVersions = new(StringComparer.Ordinal)
        {
            "windows5.0", "windows5.1.2600", "windows6.0.6000", "windows6.1", "windows8.0", "windows8.1",
            "windows10.0.10240", "windows10.0.10586", "windows10.0.14393", "windows10.0.15063",
            "windows10.0.16299", "windows10.0.17134", "windows10.0.17763", "windows10.0.18362",
            "windows10.0.19041", "windowsserver2000", "windowsserver2003", "windowsserver2008",
            "windowsserver2012", "windowsserver2016",
        };

        internal static bool IsKnownPayload(string payload)
        {
            if (payload.StartsWith(OwnerPrefix, StringComparison.Ordinal))
                return true;
            int end = payload.IndexOfAny(new[] { '(', '=', ' ', '\t', '\r', '\n' });
            return Names.Contains(end < 0 ? payload : payload[..end]);
        }

        internal static string RemoveOwnerPrefix(string payload)
            => payload.StartsWith(OwnerPrefix, StringComparison.Ordinal) ? payload[OwnerPrefix.Length..] : payload;

        internal static HeaderAnnotation Parse(string payload)
        {
            payload = RemoveOwnerPrefix(payload);
            int open = payload.IndexOf('(');
            string name = (open < 0 ? payload : payload[..open]).Trim();
            if (!Names.Contains(name))
            {
                throw new FormatException($"Unknown Win32 metadata annotation '{name}'.");
            }

            bool valued = open >= 0;
            var arguments = valued && payload.EndsWith(")", StringComparison.Ordinal)
                ? SplitArguments(payload[(open + 1)..^1])
                : new List<string>();
            if (valued && !payload.EndsWith(")", StringComparison.Ordinal))
            {
                throw new FormatException($"Malformed annotation '{payload}'.");
            }

            int minimum, maximum;
            switch (name)
            {
                case "RAIIFree":
                case "Enum":
                case "FlagsEnum":
                    minimum = 1;
                    maximum = int.MaxValue;
                    break;
                case "ImportLibrary":
                    minimum = 1;
                    maximum = 2;
                    break;
                case "SupportedOSPlatform":
                case "AlsoUsableFor":
                case "AssociatedEnum":
                case "AssociatedConstant":
                case "Optional":
                case "ComOutPtr":
                    minimum = maximum = 1;
                    break;
                default:
                    minimum = maximum = 0;
                    break;
            }

            if (valued != (minimum != 0) || arguments.Count < minimum || arguments.Count > maximum)
            {
                throw new FormatException($"Annotation '{name}' expects " +
                    (minimum == 0 ? "no value or parentheses." : minimum == maximum ? "one value." :
                    name is "Enum" or "FlagsEnum" ? "one or more member names." :
                    name == "ImportLibrary" ? "a module and an optional import entry point." :
                    "a cleanup name and optional invalid values."));
            }

            if (name is "Optional" or "ComOutPtr")
            {
                if (arguments[0] is not "true" and not "false")
                    throw new FormatException($"Annotation '{name}' requires exactly true or false.");
            }
            else if (name == "SupportedOSPlatform")
            {
                string version = ReadString(arguments[0], requireQuotes: true);
                if (!SupportedVersions.Contains(version))
                {
                    throw new FormatException($"Unsupported OS annotation version '{version}'; use a reviewed _Win32_SupportedOS_*_ macro.");
                }
            }
            else if (name == "ImportLibrary")
            {
                string module = ReadString(arguments[0]);
                if (module.Length == 0 || module.Any(character => char.IsControl(character) || character is '/' or '\\'))
                {
                    throw new FormatException($"Invalid import module '{module}'.");
                }
                if (arguments.Count == 2)
                {
                    string entryPoint = ReadString(arguments[1], requireQuotes: true);
                    if (entryPoint.Length == 0 || entryPoint.Any(char.IsControl))
                        throw new FormatException("An import entry point must be a nonempty export name or ordinal.");
                    if (entryPoint[0] == '#' && (!ushort.TryParse(entryPoint.AsSpan(1),
                        NumberStyles.None, CultureInfo.InvariantCulture, out ushort ordinal) || ordinal == 0))
                        throw new FormatException("An import ordinal must be between 1 and 65535.");
                }
            }
            else if (name is "RAIIFree" or "AlsoUsableFor" or "AssociatedEnum" or "AssociatedConstant")
            {
                if (!Regex.IsMatch(arguments[0], @"^[A-Za-z_]\w*(?:(?:::|\.)[A-Za-z_]\w*)*$"))
                {
                    throw new FormatException($"Annotation '{name}' requires a native declaration name, not '{arguments[0]}'.");
                }
            }
            else if (name is "Enum" or "FlagsEnum")
            {
                if (arguments.Any(argument => !Regex.IsMatch(argument, @"^[A-Za-z_]\w*$")) ||
                    arguments.Distinct(StringComparer.Ordinal).Count() != arguments.Count)
                    throw new FormatException("Enum groups require distinct member identifiers.");
            }

            return new HeaderAnnotation(name, arguments);
        }

        internal static string Quote(string value) => SyntaxFactory.Literal(value).ToString();

        internal static string ReadString(string value, bool requireQuotes = false)
        {
            value = value.Trim();
            if (value.StartsWith("\"", StringComparison.Ordinal))
            {
                if (SyntaxFactory.ParseExpression(value) is not LiteralExpressionSyntax literal ||
                    !literal.IsKind(SyntaxKind.StringLiteralExpression) || literal.ContainsDiagnostics)
                {
                    throw new FormatException($"Invalid string value '{value}'.");
                }
                return literal.Token.ValueText;
            }
            if (requireQuotes || value.Contains('"'))
            {
                throw new FormatException($"Expected a quoted string, not '{value}'.");
            }
            return value;
        }

        private static List<string> SplitArguments(string text)
            => SplitDelimited(text, ',');

        internal static List<string> SplitAttributeTransport(string text)
            => SplitDelimited(text, '^');

        private static List<string> SplitDelimited(string text, char delimiter)
        {
            List<string> result = new();
            var brackets = new Stack<char>();
            int start = 0;
            char quote = '\0';
            bool escaped = false;
            for (int i = 0; i < text.Length; i++)
            {
                char character = text[i];
                if (quote != '\0')
                {
                    if (escaped)
                        escaped = false;
                    else if (character == '\\')
                        escaped = true;
                    else if (character == quote)
                        quote = '\0';
                }
                else if (character is '"' or '\'')
                    quote = character;
                else if (character is '(' or '[' or '{')
                    brackets.Push(character);
                else if (character is ')' or ']' or '}')
                {
                    char expected = character == ')' ? '(' : character == ']' ? '[' : '{';
                    if (brackets.Count == 0 || brackets.Pop() != expected)
                        throw new FormatException($"Unbalanced annotation arguments '{text}'.");
                }
                else if (character == delimiter && brackets.Count == 0)
                {
                    AddArgument(text[start..i]);
                    start = i + 1;
                }
            }
            if (brackets.Count != 0 || quote != '\0')
                throw new FormatException($"Unbalanced annotation arguments '{text}'.");
            if (text.Length != 0)
                AddArgument(text[start..]);
            return result;

            void AddArgument(string argument)
            {
                argument = argument.Trim();
                if (argument.Length == 0)
                    throw new FormatException($"Empty annotation argument in '{text}'.");
                result.Add(argument);
            }
        }
    }

    internal sealed class HeaderAnnotationException : Exception
    {
        internal HeaderAnnotationException(string location, string message)
            : base($"{location}: error WMA001: {message}")
        {
        }
    }
}
