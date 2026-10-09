using System;
using System.Collections.Generic;
using System.Linq;
using ICSharpCode.Decompiler.TypeSystem;

namespace MetadataUtils
{
    public sealed record DuplicateConstantDiagnostic(string Name, IReadOnlyList<string> Owners);

    public static class ConstantValidator
    {
        public static IReadOnlyList<DuplicateConstantDiagnostic> FindDuplicates(IEnumerable<ITypeDefinition> definitions)
        {
            var names = new Dictionary<string, List<Occurrence>>(StringComparer.Ordinal);
            foreach (var type in definitions)
            {
                if (type.Kind == TypeKind.Enum &&
                    type.GetAttributes().Any(a => a.AttributeType.Name == "ScopedEnumAttribute"))
                {
                    continue;
                }

                // Empty GUID-tagged structs represent constants too.
                if (type.Kind == TypeKind.Struct &&
                    type.GetAttributes().Any(a => a.AttributeType.Name == "GuidAttribute") &&
                    !type.Fields.Any())
                {
                    Add(type.Name, type.FullName, ArchitectureValidator.EffectiveArchitectures(type));
                }

                if (type.Kind == TypeKind.Enum || (type.Kind == TypeKind.Class && type.Name == "Apis"))
                {
                    foreach (var field in type.Fields)
                    {
                        if (field.Name != "value__")
                        {
                            Add(field.Name, type.FullName, ArchitectureValidator.EffectiveArchitectures(field));
                        }
                    }
                }
            }

            var diagnostics = new List<DuplicateConstantDiagnostic>();
            foreach (var pair in names)
            {
                var owners = new List<string>();
                for (int i = 0; i < pair.Value.Count; i++)
                {
                    for (int j = 0; j < pair.Value.Count; j++)
                    {
                        if (i != j && (pair.Value[i].Architectures & pair.Value[j].Architectures) != Architecture.None)
                        {
                            owners.Add(pair.Value[i].Owner);
                            break;
                        }
                    }
                }

                if (owners.Count > 1)
                {
                    owners.Sort();
                    diagnostics.Add(new(pair.Key, owners));
                }
            }

            return diagnostics;

            void Add(string name, string owner, Architecture architectures)
            {
                if (!names.TryGetValue(name, out var occurrences))
                {
                    occurrences = new();
                    names.Add(name, occurrences);
                }

                occurrences.Add(new(owner, architectures));
            }
        }

        private sealed record Occurrence(string Owner, Architecture Architectures);
    }
}
