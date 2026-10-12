using System;
using System.Collections.Generic;
using System.Linq;
using ICSharpCode.Decompiler.TypeSystem;
using ICSharpCode.Decompiler.TypeSystem.Implementation;

namespace MetadataUtils
{
    public sealed record ArchitectureDiagnostic(
        string Owner, string ReferencedType, Architecture Required, Architecture Supported);

    public static class ArchitectureValidator
    {
        private const string AttributeName = "Windows.Win32.Foundation.Metadata.SupportedArchitectureAttribute";

        public static IReadOnlyList<ArchitectureDiagnostic> FindMismatches(IEnumerable<ITypeDefinition> definitions)
        {
            var roots = definitions.ToList();
            var variants = roots.SelectMany(t => GetVariants(t, Architecture.All))
                .GroupBy(v => v.Definition.FullName)
                .ToDictionary(g => g.Key, g => g.ToList(), StringComparer.Ordinal);
            var diagnostics = new List<ArchitectureDiagnostic>();

            foreach (var root in roots)
            {
                if (DeclaredArchitectures(root) is Architecture architecture)
                {
                    Check(root, root, architecture, new(ReferenceEqualityComparer.Instance), variants, diagnostics);
                }

                if (root.Kind == TypeKind.Class && root.Name == "Apis")
                {
                    foreach (var method in root.Methods.Where(m => m.IsStatic))
                    {
                        if (DeclaredArchitectures(method) is not Architecture methodArchitectures)
                        {
                            continue;
                        }

                        var required = methodArchitectures & (DeclaredArchitectures(root) ?? Architecture.All);
                        Dictionary<ITypeDefinition, Architecture> visited = new(ReferenceEqualityComparer.Instance);
                        Check(method, method.ReturnType, required, visited, variants, diagnostics);
                        foreach (var parameter in method.Parameters)
                        {
                            Check(method, parameter.Type, required, visited, variants, diagnostics);
                        }
                    }
                }
            }

            return diagnostics;
        }

        private static Architecture? DeclaredArchitectures(IEntity entity)
        {
            var attribute = entity.GetAttributes().SingleOrDefault(a => a.AttributeType.FullName == AttributeName);
            return attribute == null ? null : (Architecture)attribute.FixedArguments[0].Value;
        }

        internal static Architecture EffectiveArchitectures(IEntity entity)
        {
            var supported = DeclaredArchitectures(entity) ?? Architecture.All;
            for (var parent = entity.DeclaringTypeDefinition; parent != null; parent = parent.DeclaringTypeDefinition)
            {
                supported &= DeclaredArchitectures(parent) ?? Architecture.All;
            }

            return supported;
        }

        private static IEnumerable<TypeVariant> GetVariants(ITypeDefinition type, Architecture parent)
        {
            var supported = parent & (DeclaredArchitectures(type) ?? Architecture.All);
            yield return new(type, supported);
            foreach (var nested in type.NestedTypes)
            {
                foreach (var variant in GetVariants(nested, supported))
                {
                    yield return variant;
                }
            }
        }

        private static void Check(
            IEntity owner,
            IType reference,
            Architecture required,
            Dictionary<ITypeDefinition, Architecture> visited,
            Dictionary<string, List<TypeVariant>> variants,
            List<ArchitectureDiagnostic> diagnostics)
        {
            if (required == Architecture.None)
            {
                return;
            }

            var type = reference;
            while (true)
            {
                IType element = type switch
                {
                    ArrayType array => array.ElementType,
                    PointerType pointer => pointer.ElementType,
                    ByReferenceType byReference => byReference.ElementType,
                    ModifiedType modified => modified.ElementType,
                    _ => null,
                };
                if (element == null)
                {
                    break;
                }

                type = element;
            }

            if (!variants.TryGetValue(type.FullName, out var candidates))
            {
                return;
            }

            var supported = candidates.Aggregate(Architecture.None, (mask, candidate) => mask | candidate.Architectures);
            if ((supported & required) != required)
            {
                diagnostics.Add(new(owner.FullName, reference.FullName, required, supported));
            }

            // A resolved TypeRef can point at any same-name row. Traverse the physical
            // definitions valid for this use, not that unfiltered row's fields.
            foreach (var candidate in candidates)
            {
                var definition = candidate.Definition;
                var active = required & candidate.Architectures;
                visited.TryGetValue(definition, out var checkedArchitectures);
                active &= ~checkedArchitectures;
                if (active == Architecture.None)
                {
                    continue;
                }

                visited[definition] = checkedArchitectures | active;
                if (definition.Kind == TypeKind.Struct)
                {
                    foreach (var field in definition.Fields)
                    {
                        var fieldArchitectures = active & (DeclaredArchitectures(field) ?? Architecture.All);
                        Check(owner, field.Type, fieldArchitectures, visited, variants, diagnostics);
                    }
                }
                else if (definition.Kind == TypeKind.Delegate)
                {
                    var invoke = definition.Methods.Single(m => m.Name == "Invoke");
                    Check(owner, invoke.ReturnType, active, visited, variants, diagnostics);
                    foreach (var parameter in invoke.Parameters)
                    {
                        Check(owner, parameter.Type, active, visited, variants, diagnostics);
                    }
                }
            }
        }

        private sealed record TypeVariant(ITypeDefinition Definition, Architecture Architectures);
    }
}
