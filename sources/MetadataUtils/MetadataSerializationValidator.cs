using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Reflection.Metadata;
using System.Reflection.Metadata.Ecma335;

namespace MetadataUtils
{
    public sealed record MetadataSerializationDiagnostic(int Token, string Owner, string Message);

    public static class MetadataSerializationValidator
    {
        public static IReadOnlyList<MetadataSerializationDiagnostic> FindMissingFieldLayouts(MetadataReader reader)
        {
            var diagnostics = new List<MetadataSerializationDiagnostic>();
            foreach (var handle in reader.TypeDefinitions)
            {
                var type = reader.GetTypeDefinition(handle);
                if ((type.Attributes & TypeAttributes.LayoutMask) != TypeAttributes.ExplicitLayout)
                {
                    continue;
                }

                foreach (var fieldHandle in type.GetFields())
                {
                    var field = reader.GetFieldDefinition(fieldHandle);
                    if ((field.Attributes & FieldAttributes.Static) == 0 && field.GetOffset() < 0)
                    {
                        var identity = DefinitionIdentity(reader, handle);
                        diagnostics.Add(new(
                            MetadataTokens.GetToken(fieldHandle),
                            $"{Display(identity)}.{reader.GetString(field.Name)}",
                            "Instance field of an ExplicitLayout type has no FieldLayout row."));
                    }
                }
            }

            return diagnostics;
        }

        public static IReadOnlyList<MetadataSerializationDiagnostic> FindUnresolvedLocalTypeReferences(MetadataReader reader)
        {
            var definitions = reader.TypeDefinitions
                .Select(handle => DefinitionIdentity(reader, handle))
                .ToHashSet();
            var diagnostics = new List<MetadataSerializationDiagnostic>();
            foreach (var handle in reader.TypeReferences)
            {
                var names = new Stack<string>();
                var visited = new HashSet<TypeReferenceHandle>();
                var current = handle;
                while (true)
                {
                    if (!visited.Add(current))
                    {
                        diagnostics.Add(new(
                            MetadataTokens.GetToken(handle),
                            reader.GetString(reader.GetTypeReference(handle).Name),
                            "TypeRef resolution scope contains a cycle."));
                        break;
                    }

                    var reference = reader.GetTypeReference(current);
                    names.Push(reader.GetString(reference.Name));
                    var scope = reference.ResolutionScope;
                    if (scope.Kind == HandleKind.TypeReference)
                    {
                        current = (TypeReferenceHandle)scope;
                        continue;
                    }

                    // Assembly/module references and null (ExportedType) scopes are not local definitions.
                    if (scope.Kind == HandleKind.ModuleDefinition && !scope.IsNil)
                    {
                        var identity = (reader.GetString(reference.Namespace), string.Join('\0', names));
                        if (!definitions.Contains(identity))
                        {
                            diagnostics.Add(new(
                                MetadataTokens.GetToken(handle),
                                Display(identity),
                                "Module-scoped TypeRef has no matching local TypeDef, including its declaring-type chain."));
                        }
                    }

                    break;
                }
            }

            return diagnostics;
        }

        private static (string Namespace, string Names) DefinitionIdentity(MetadataReader reader, TypeDefinitionHandle handle)
        {
            var names = new Stack<string>();
            var visited = new HashSet<TypeDefinitionHandle>();
            while (true)
            {
                if (!visited.Add(handle))
                {
                    throw new BadImageFormatException("TypeDef declaring-type chain contains a cycle.");
                }

                var definition = reader.GetTypeDefinition(handle);
                names.Push(reader.GetString(definition.Name));
                var parent = definition.GetDeclaringType();
                if (parent.IsNil)
                {
                    return (reader.GetString(definition.Namespace), string.Join('\0', names));
                }

                handle = parent;
            }
        }

        private static string Display((string Namespace, string Names) identity)
        {
            string prefix = identity.Namespace.Length == 0 ? string.Empty : identity.Namespace + ".";
            return prefix + identity.Names.Replace('\0', '+');
        }
    }
}
