using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using Microsoft.CodeAnalysis.CSharp;

namespace ClangSharpSourceToWinmd
{
    public sealed class NamespaceOutputs
    {
        private readonly Dictionary<string, string> routes = new Dictionary<string, string>(StringComparer.Ordinal);

        public NamespaceOutputs(string primaryOutput, IEnumerable<string> namespaceOutputs)
        {
            this.PrimaryOutput = ValidatePath(primaryOutput);
            var identities = new Dictionary<string, string>(StringComparer.OrdinalIgnoreCase)
            {
                [Path.GetFileName(this.PrimaryOutput)] = this.PrimaryOutput
            };

            foreach (string mapping in namespaceOutputs ?? Enumerable.Empty<string>())
            {
                int separator = mapping.IndexOf('=');
                if (separator <= 0 || separator == mapping.Length - 1)
                {
                    throw new ArgumentException($"Invalid namespace output '{mapping}'; expected Namespace=Output.winmd.");
                }

                string ns = mapping.Substring(0, separator);
                if (ns.Split('.').Any(part => !SyntaxFacts.IsValidIdentifier(part)))
                {
                    throw new ArgumentException($"Invalid namespace '{ns}'.");
                }

                string output = ValidatePath(mapping.Substring(separator + 1));
                string identity = Path.GetFileName(output);
                if (StringComparer.OrdinalIgnoreCase.Equals(output, this.PrimaryOutput))
                {
                    throw new ArgumentException($"Namespace '{ns}' must select an additional output, not the primary output.");
                }

                if (identities.TryGetValue(identity, out string existing))
                {
                    if (!StringComparer.OrdinalIgnoreCase.Equals(existing, output))
                    {
                        throw new ArgumentException($"Output identity '{identity}' is assigned to multiple paths.");
                    }

                    output = existing;
                }

                foreach (var route in this.routes)
                {
                    if (Matches(ns, route.Key) || Matches(route.Key, ns))
                    {
                        throw new ArgumentException($"Overlapping namespace outputs '{ns}' and '{route.Key}'.");
                    }
                }

                identities[identity] = output;
                this.routes.Add(ns, output);
            }

            this.OutputPaths = new[] { this.PrimaryOutput }.Concat(this.routes.Values.Distinct(StringComparer.OrdinalIgnoreCase).OrderBy(p => p, StringComparer.Ordinal)).ToArray();
        }

        public string PrimaryOutput { get; }

        public IReadOnlyList<string> OutputPaths { get; }

        public string GetOutput(string ns) =>
            this.routes.FirstOrDefault(route => Matches(ns, route.Key)).Value ?? this.PrimaryOutput;

        private static bool Matches(string ns, string prefix) =>
            ns == prefix || ns.StartsWith(prefix + ".", StringComparison.Ordinal);

        private static string ValidatePath(string path)
        {
            if (string.IsNullOrWhiteSpace(path) || path.IndexOfAny(Path.GetInvalidPathChars()) >= 0)
            {
                throw new ArgumentException($"Invalid output path '{path}'.");
            }

            string fullPath = Path.GetFullPath(path);
            string name = Path.GetFileName(fullPath);
            if (!name.EndsWith(".winmd", StringComparison.OrdinalIgnoreCase) ||
                name.Length == ".winmd".Length || name.IndexOfAny(Path.GetInvalidFileNameChars()) >= 0 ||
                name.IndexOfAny(new[] { ',', '=', ';', '|', '<', '>' }) >= 0)
            {
                throw new ArgumentException($"Invalid output identity '{name}'; expected a .winmd file name.");
            }

            return fullPath;
        }
    }
}
