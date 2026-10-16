using System;
using System.Collections.Generic;
using System.Linq;
using System.Text.RegularExpressions;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;

namespace Win32MetadataScraper
{
    internal sealed record HeaderAnnotation(string Name, IReadOnlyList<string> Arguments)
    {
        internal const string ExpandedRaiiName = "__win32metadata_RAIIFree_expanded";

        private static readonly HashSet<string> Names = new(StringComparer.Ordinal)
        {
            "SetLastError", "ImportLibrary", "SupportedOSPlatform", "PreserveResult",
            "RAIIFree", "Retained", "ContainsInteriorPointers", "RetVal",
            "AlsoUsableFor", "AssociatedEnum", "AssociatedConstant", ExpandedRaiiName,
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
            int end = payload.IndexOfAny(new[] { '(', '=', ' ', '\t', '\r', '\n' });
            return Names.Contains(end < 0 ? payload : payload[..end]);
        }

        internal static HeaderAnnotation Parse(string payload)
        {
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
                case ExpandedRaiiName:
                    minimum = 1;
                    maximum = int.MaxValue;
                    break;
                case "ImportLibrary":
                case "SupportedOSPlatform":
                case "AlsoUsableFor":
                case "AssociatedEnum":
                case "AssociatedConstant":
                    minimum = maximum = 1;
                    break;
                default:
                    minimum = maximum = 0;
                    break;
            }

            if (valued != (minimum != 0) || arguments.Count < minimum || arguments.Count > maximum)
            {
                throw new FormatException($"Annotation '{name}' expects " +
                    (minimum == 0 ? "no value or parentheses." : minimum == maximum ? "one value." : "a cleanup name and optional invalid values."));
            }

            if (name == "SupportedOSPlatform")
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
            }
            else if (name is "RAIIFree" or "AlsoUsableFor" or "AssociatedEnum" or "AssociatedConstant")
            {
                if (!Regex.IsMatch(arguments[0], @"^[A-Za-z_]\w*(?:(?:::|\.)[A-Za-z_]\w*)*$"))
                {
                    throw new FormatException($"Annotation '{name}' requires a native declaration name, not '{arguments[0]}'.");
                }
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
