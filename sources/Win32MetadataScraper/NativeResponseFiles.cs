#nullable enable

using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace Win32MetadataScraper
{
    public static class NativeResponseFiles
    {
        private static readonly Dictionary<string, string> Aliases = new(StringComparer.Ordinal)
        {
            ["-a"] = "--additional",
            ["-c"] = "--config",
            ["-e"] = "--exclude",
            ["-f"] = "--file",
            ["-hf"] = "--headerFile",
            ["--header-file"] = "--headerFile",
            ["-I"] = "--include-directory",
            ["-x"] = "--language",
            ["-l"] = "--libraryPath",
            ["--library-path"] = "--libraryPath",
            ["-m"] = "--methodClassName",
            ["--method-class-name"] = "--methodClassName",
            ["-n"] = "--namespace",
            ["-o"] = "--output",
            ["-r"] = "--remap",
            ["-std"] = "--std",
            ["-t"] = "--traverse",
            ["-wa"] = "--with-attribute",
            ["-wcc"] = "--with-callconv",
            ["-wlb"] = "--with-librarypath",
            ["--with-library-path"] = "--with-librarypath",
            ["-wsle"] = "--with-setlasterror",
            ["--with-set-last-error"] = "--with-setlasterror",
            ["-wsgct"] = "--with-suppressgctransition",
            ["--with-suppress-gc-transition"] = "--with-suppressgctransition",
            ["-wt"] = "--with-type",
            ["-wu"] = "--with-using",
        };

        private static readonly HashSet<string> Supported = new(StringComparer.OrdinalIgnoreCase)
        {
            "--additional", "--auto-remaps-file", "--config", "--constant-names-file",
            "--declaration-map", "--declaration-map-symbol", "--exclude", "--exclude-auto-remap",
            "--file", "--headerFile", "--include-directory", "--language", "--libraryPath",
            "--methodClassName", "--namespace", "--output", "--preserve-auto-fnptr-level",
            "--remap", "--std", "--traverse", "--with-attribute", "--with-callconv",
            "--with-librarypath", "--with-setlasterror", "--with-suppressgctransition",
            "--with-type", "--with-using",
        };

        public static bool IsSupported(string option) => Supported.Contains(option);

        public static void Read(string path, Dictionary<string, List<string>> settings, Action<string>? visited = null)
            => Read(path, settings, visited, new HashSet<string>(StringComparer.OrdinalIgnoreCase));

        private static void Read(string path, Dictionary<string, List<string>> settings,
            Action<string>? visited, HashSet<string> active)
        {
            path = Path.GetFullPath(path);
            if (!File.Exists(path))
                throw new FileNotFoundException($"Response file not found: '{path}'.", path);
            if (!active.Add(path))
                throw new InvalidDataException($"Response-file inclusion cycle: '{path}'.");
            try
            {
                visited?.Invoke(path);
                string? currentSwitch = null;
                foreach (string rawLine in File.ReadLines(path))
                {
                    string line = rawLine.Trim();
                    if (line.Length == 0 || line.StartsWith("#", StringComparison.Ordinal))
                        continue;
                    if (line.StartsWith("@", StringComparison.Ordinal))
                        Read(line.Substring(1).Trim('"'), settings, visited, active);
                    else if (TryParseOption(line, out string option, out string? inlineValue))
                    {
                        currentSwitch = option;
                        if (!settings.ContainsKey(currentSwitch))
                            settings[currentSwitch] = new List<string>();
                        if (!string.IsNullOrEmpty(inlineValue))
                            settings[currentSwitch].Add(inlineValue);
                    }
                    else if (currentSwitch != null)
                        settings[currentSwitch].Add(line);
                }
            }
            finally
            {
                active.Remove(path);
            }
        }

        public static string[] BuildClangArgs(Dictionary<string, List<string>> settings)
        {
            string language = settings.GetValueOrDefault("--language")?.LastOrDefault() ?? "c++";
            string standard = settings.GetValueOrDefault("--std")?.LastOrDefault() ?? "c++17";
            var arguments = new List<string> { $"--language={language}", $"--std={standard}", "-Wno-pragma-once-outside-header" };
            if (settings.TryGetValue("--include-directory", out var includes))
                arguments.AddRange(includes.Select(directory => "--include-directory=" + directory));
            if (settings.TryGetValue("--additional", out var additional))
                arguments.AddRange(additional);
            return arguments.ToArray();
        }

        public static string[] EnableHeaderAnnotations(string[] arguments)
        {
            if (arguments.Contains("-w", StringComparer.Ordinal))
                throw new InvalidDataException("-w suppresses ignored metadata attribute diagnostics and cannot be used with " +
                    "parse-win32-annotations. Use specific -Wno- options for native warnings.");
            return arguments.Concat(new[]
            {
                "-DWIN32METADATA",
                "-D_WIN32META_ANNOTATION_(...)=_Pragma(\"clang diagnostic push\") " +
                    "_Pragma(\"clang diagnostic error \\\"-Wignored-attributes\\\"\") " +
                    "__attribute__((annotate(\"Win32Metadata.\" __VA_ARGS__))) " +
                    "_Pragma(\"clang diagnostic pop\")",
            }).ToArray();
        }

        private static bool TryParseOption(string line, out string option, out string? inlineValue)
        {
            option = "";
            inlineValue = null;
            int separator = line.IndexOf('=');
            string candidate = separator >= 0 ? line.Substring(0, separator) : line;
            if (!candidate.StartsWith("--", StringComparison.Ordinal) && !Aliases.ContainsKey(candidate))
                return false;
            option = Aliases.GetValueOrDefault(candidate) ?? candidate;
            if (separator >= 0 && separator < line.Length - 1)
                inlineValue = line.Substring(separator + 1);
            return true;
        }
    }
}
