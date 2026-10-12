using System;
using System.Collections.Generic;
using System.Collections.Immutable;
using System.Globalization;
using System.Linq;
using System.Reflection.Metadata;
using ICSharpCode.Decompiler.TypeSystem;

namespace MetadataUtils
{
    public sealed record DuplicateTypeCollision(string FirstOwner, string SecondOwner, Architecture Architectures);

    public sealed record DuplicateTypeDiagnostic(
        string Name, IReadOnlyList<string> Owners, Architecture Architectures,
        IReadOnlyList<DuplicateTypeCollision> Collisions);

    public static class TypeDuplicateValidator
    {
        private const string MetadataNamespace = "Windows.Win32.Foundation.Metadata.";
        private static readonly Architecture[] Architectures = { Architecture.X86, Architecture.X64, Architecture.Arm64 };

        /// <summary>
        /// Finds same-name structural/native-semantic collisions on overlapping architectures.
        /// Include namespace-local Apis definitions to resolve RAIIFree providers. Absent or
        /// ambiguous provider metadata is not evidence that otherwise matching types differ.
        /// These diagnostics do not establish that native identities can safely be merged.
        /// </summary>
        public static IReadOnlyList<DuplicateTypeDiagnostic> FindDuplicates(IEnumerable<ITypeDefinition> definitions)
        {
            var types = definitions.ToArray();
            var diagnostics = new List<DuplicateTypeDiagnostic>();
            foreach (var candidates in types.Where(t => t.Name != "<Module>" && !(t.Kind == TypeKind.Class && t.Name == "Apis"))
                .GroupBy(t => t.Name, StringComparer.Ordinal).OrderBy(g => g.Key, StringComparer.Ordinal))
            {
                var group = candidates.OrderBy(t => t.FullName, StringComparer.Ordinal)
                    .ThenBy(t => System.Reflection.Metadata.Ecma335.MetadataTokens.GetToken(t.MetadataToken)).ToArray();
                if (group.Length < 2)
                {
                    continue;
                }

                var edges = new Dictionary<(int First, int Second), Architecture>();
                foreach (var architecture in Architectures)
                {
                    var shapes = group.Select((type, index) => (Type: type, Index: index))
                        .Where(t => IsAvailable(t.Type, architecture))
                        .Select(t => (t.Index, Shape: new Shape(t.Type, architecture, types)))
                        .GroupBy(t => t.Shape.Identity, StringComparer.Ordinal);
                    foreach (var matching in shapes)
                    {
                        var entries = matching.ToArray();
                        for (int i = 0; i < entries.Length; i++)
                        {
                            for (int j = i + 1; j < entries.Length; j++)
                            {
                                if (!entries[i].Shape.HasDistinctProviders(entries[j].Shape))
                                {
                                    var edge = (entries[i].Index, entries[j].Index);
                                    edges.TryGetValue(edge, out var overlap);
                                    edges[edge] = overlap | architecture;
                                }
                            }
                        }
                    }
                }

                // Connected groups retain every collision without claiming that all pairs
                // overlap (or that an unresolved cleanup provider proves equivalence).
                var remaining = edges.Keys.SelectMany(e => new[] { e.First, e.Second }).ToHashSet();
                while (remaining.Count != 0)
                {
                    var component = new HashSet<int> { remaining.Min() };
                    var pending = new Queue<int>(component);
                    while (pending.Count != 0)
                    {
                        int current = pending.Dequeue();
                        foreach (var edge in edges.Keys.Where(e => e.First == current || e.Second == current))
                        {
                            int other = edge.First == current ? edge.Second : edge.First;
                            if (component.Add(other))
                            {
                                pending.Enqueue(other);
                            }
                        }
                    }

                    remaining.ExceptWith(component);
                    var collisions = edges.Where(e => component.Contains(e.Key.First))
                        .OrderBy(e => e.Key.First).ThenBy(e => e.Key.Second)
                        .Select(e => new DuplicateTypeCollision(
                            group[e.Key.First].FullName, group[e.Key.Second].FullName, e.Value)).ToArray();
                    diagnostics.Add(new(candidates.Key,
                        component.OrderBy(i => i).Select(i => group[i].FullName).ToArray(),
                        collisions.Aggregate(Architecture.None, (mask, collision) => mask | collision.Architectures),
                        collisions));
                }
            }

            return diagnostics;
        }

        private static bool IsAvailable(IEntity entity, Architecture architecture)
        {
            ValidateAttributes(entity.GetAttributes(), entity.FullName);
            return (ArchitectureValidator.EffectiveArchitectures(entity) & architecture) != Architecture.None;
        }

        private static void ValidateAttributes(IEnumerable<IAttribute> attributes, string owner)
        {
            foreach (var attribute in attributes)
            {
                if (attribute.HasDecodeErrors)
                {
                    throw new BadImageFormatException($"Cannot compare {owner}: undecodable {attribute.AttributeType.FullName}.");
                }
            }
        }

        private static string Key(params object[] values) => string.Concat(values.Select(value =>
        {
            var text = Convert.ToString(value, CultureInfo.InvariantCulture) ?? "";
            return text.Length.ToString(CultureInfo.InvariantCulture) + ":" + text;
        }));

        private sealed class Shape
        {
            private readonly ITypeDefinition root;
            private readonly Architecture architecture;
            private readonly ITypeDefinition[] definitions;
            private readonly MetadataModule module;
            private readonly MetadataReader reader;
            private readonly SignatureProvider signatures;
            private readonly Dictionary<string, string> providers = new(StringComparer.Ordinal);

            internal Shape(ITypeDefinition root, Architecture architecture, ITypeDefinition[] definitions)
            {
                this.root = root;
                this.architecture = architecture;
                this.definitions = definitions;
                module = root.ParentModule as MetadataModule
                    ?? throw new ArgumentException($"A metadata-backed definition is required for {root.FullName}.");
                reader = module.PEFile.Metadata;
                signatures = new SignatureProvider(root.FullName);
                try
                {
                    Identity = Type(root, "");
                }
                catch (BadImageFormatException error)
                {
                    throw new BadImageFormatException($"Cannot compare {root.FullName}: {error.Message}", error);
                }
            }

            internal string Identity { get; }

            internal bool HasDistinctProviders(Shape other) => providers.Any(pair =>
                pair.Value != null && other.providers.TryGetValue(pair.Key, out var value) &&
                value != null && value != pair.Value);

            private string Type(ITypeDefinition type, string path)
            {
                var row = reader.GetTypeDefinition((TypeDefinitionHandle)type.MetadataToken);
                var layout = row.GetLayout();
                return Key(row.Attributes, layout.PackingSize, layout.Size,
                    row.BaseType.IsNil ? "" : signatures.GetTypeFromHandle(reader, null, row.BaseType),
                    Key(row.GetInterfaceImplementations().Select(h =>
                        signatures.GetTypeFromHandle(reader, null, reader.GetInterfaceImplementation(h).Interface))
                        .OrderBy(s => s, StringComparer.Ordinal).ToArray()),
                    Attributes(type.GetAttributes(), path, type.Namespace),
                    Key(row.GetFields().Where(h => IsAvailable(module.GetDefinition(h), architecture))
                        .Select(h => Field(h, path, type.Namespace)).ToArray()),
                    Key(row.GetMethods().Where(h => IsAvailable(module.GetDefinition(h), architecture))
                        .Select(h => Method(h, path, type.Namespace)).ToArray()),
                    Key(row.GetProperties().Where(h => IsAvailable(module.GetDefinition(h), architecture)).Select(h =>
                    {
                        var property = reader.GetPropertyDefinition(h);
                        return Key(reader.GetString(property.Name), property.Attributes,
                            SignatureProvider.MethodKey(property.DecodeSignature(signatures, null)),
                            Constant(property.GetDefaultValue()),
                            Attributes(module.GetDefinition(h).GetAttributes(), path + "/property/" + reader.GetString(property.Name), type.Namespace));
                    }).ToArray()),
                    Key(row.GetEvents().Where(h => IsAvailable(module.GetDefinition(h), architecture)).Select(h =>
                    {
                        var ev = reader.GetEventDefinition(h);
                        return Key(reader.GetString(ev.Name), ev.Attributes,
                            signatures.GetTypeFromHandle(reader, null, ev.Type),
                            Attributes(module.GetDefinition(h).GetAttributes(), path + "/event/" + reader.GetString(ev.Name), type.Namespace));
                    }).ToArray()),
                    Key(type.NestedTypes.Where(t => IsAvailable(t, architecture))
                        .Select(t => Key(t.Name, Type(t, path + "/" + t.Name))).ToArray()),
                    GenericParameters(row.GetGenericParameters()));
            }

            private string Field(FieldDefinitionHandle handle, string path, string ns)
            {
                var field = reader.GetFieldDefinition(handle);
                string name = reader.GetString(field.Name);
                return Key(name, field.Attributes, field.DecodeSignature(signatures, null), field.GetOffset(),
                    Constant(field.GetDefaultValue()), Blob(field.GetMarshallingDescriptor()),
                    Attributes(module.GetDefinition(handle).GetAttributes(), path + "/field/" + name, ns));
            }

            private string Method(MethodDefinitionHandle handle, string path, string ns)
            {
                var method = reader.GetMethodDefinition(handle);
                var definition = module.GetDefinition(handle);
                var signature = method.DecodeSignature(signatures, null);
                string name = reader.GetString(method.Name);
                string location = path + "/method/" + Key(name, SignatureProvider.MethodKey(signature));
                var rows = new Dictionary<int, Parameter>();
                foreach (var h in method.GetParameters())
                {
                    var parameter = reader.GetParameter(h);
                    if (parameter.SequenceNumber > signature.ParameterTypes.Length ||
                        !rows.TryAdd(parameter.SequenceNumber, parameter))
                    {
                        throw new BadImageFormatException($"Invalid parameter sequence in {definition.FullName}.");
                    }
                }

                return Key(name, method.Attributes, method.ImplAttributes, SignatureProvider.MethodKey(signature),
                    Attributes(definition.GetAttributes(), location, ns), Import(method),
                    Key(Enumerable.Range(0, signature.ParameterTypes.Length + 1).Select(index =>
                    {
                        var attributes = index == 0 ? definition.GetReturnTypeAttributes() : definition.Parameters[index - 1].GetAttributes();
                        string semantic = Attributes(attributes, location + "/parameter/" + index, ns);
                        return rows.TryGetValue(index, out var parameter)
                            ? Key(parameter.Attributes, Constant(parameter.GetDefaultValue()), Blob(parameter.GetMarshallingDescriptor()), semantic)
                            : Key(System.Reflection.ParameterAttributes.None, "", "", semantic);
                    }).ToArray()),
                    GenericParameters(method.GetGenericParameters()));
            }

            private string GenericParameters(GenericParameterHandleCollection handles) => Key(handles.Select(handle =>
            {
                var parameter = reader.GetGenericParameter(handle);
                return Key(parameter.Index, parameter.Attributes, Key(parameter.GetConstraints().Select(h =>
                    signatures.GetTypeFromHandle(reader, null, reader.GetGenericParameterConstraint(h).Type))
                    .OrderBy(s => s, StringComparer.Ordinal).ToArray()));
            }).ToArray());

            private string Constant(ConstantHandle handle)
            {
                if (handle.IsNil)
                {
                    return "";
                }

                var constant = reader.GetConstant(handle);
                return Key(constant.TypeCode, Blob(constant.Value));
            }

            private string Blob(BlobHandle handle) => handle.IsNil ? "" : Convert.ToHexString(reader.GetBlobBytes(handle));

            private string Attributes(IEnumerable<IAttribute> attributes, string path, string ns)
            {
                var items = attributes.ToArray();
                ValidateAttributes(items, root.FullName + path);
                return Key(items.Where(a => a.AttributeType.FullName is not
                    (MetadataNamespace + "SupportedArchitectureAttribute") and not
                    (MetadataNamespace + "DocumentationAttribute") and not
                    (MetadataNamespace + "NativeTypeNameAttribute") and not
                    "System.Runtime.Versioning.SupportedOSPlatformAttribute")
                    .Select(attribute =>
                    {
                        string name = attribute.AttributeType.FullName;
                        if (name == MetadataNamespace + "RAIIFreeAttribute")
                        {
                            if (attribute.FixedArguments.Length != 1 || attribute.FixedArguments[0].Value is not string free)
                            {
                                throw new BadImageFormatException($"Invalid RAIIFree on {root.FullName}{path}.");
                            }

                            providers[Key(path, free)] = CleanupProvider(ns, free);
                        }

                        return Key(name,
                            Key(attribute.FixedArguments.Select(a => Key(a.Type.ReflectionName, Value(a.Value))).ToArray()),
                            Key(attribute.NamedArguments.Select(a => Key(a.Kind, a.Name, a.Type.ReflectionName, Value(a.Value)))
                                .OrderBy(s => s, StringComparer.Ordinal).ToArray()));
                    }).OrderBy(s => s, StringComparer.Ordinal).ToArray());
            }

            private static string Value(object value) => value switch
            {
                null => Key("", ""),
                ImmutableArray<CustomAttributeTypedArgument<IType>> array =>
                    Key(array.Select(a => Key(a.Type.ReflectionName, Value(a.Value))).ToArray()),
                IType type => type.ReflectionName,
                _ => Key(value.GetType().FullName, value),
            };

            private string CleanupProvider(string ns, string free)
            {
                // projections.md defines a namespace-local API reference, not a namespace
                // identity for the handle itself. Missing/ambiguous bindings prove nothing.
                var methods = definitions.Where(t => t.ParentModule == root.ParentModule &&
                    t.Kind == TypeKind.Class && t.Name == "Apis" && t.Namespace == ns && IsAvailable(t, architecture))
                    .SelectMany(t => t.Methods).Where(m => m.Name == free && m.IsStatic && IsAvailable(m, architecture)).ToArray();
                var imports = methods.Select(m => Import(reader.GetMethodDefinition((MethodDefinitionHandle)m.MetadataToken), providerOnly: true))
                    .Distinct(StringComparer.Ordinal).ToArray();
                return imports.Length == 1 && imports[0] != "" ? imports[0] : null;
            }

            private string Import(MethodDefinition method, bool providerOnly = false)
            {
                var import = method.GetImport();
                if (import.Module.IsNil)
                {
                    return "";
                }

                string dll = reader.GetString(reader.GetModuleReference(import.Module).Name);
                string entryPoint = reader.GetString(import.Name);
                return providerOnly && (dll.Length == 0 || entryPoint.Length == 0) ? "" :
                    Key(dll.ToUpperInvariant(), entryPoint, providerOnly ? "" : import.Attributes);
            }
        }

        private sealed class SignatureProvider : GenericSignatureTypeProvider
        {
            private readonly string owner;
            private readonly HashSet<EntityHandle> resolving = new();

            internal SignatureProvider(string owner) => this.owner = owner;

            public override string GetPrimitiveType(PrimitiveTypeCode typeCode) => typeCode.ToString();

            public override string GetFunctionPointerType(MethodSignature<string> signature) => MethodKey(signature);

            internal static string MethodKey(MethodSignature<string> signature) =>
                Key(signature.Header.RawValue, signature.GenericParameterCount, signature.RequiredParameterCount,
                    signature.ReturnType, Key(signature.ParameterTypes.ToArray()));

            public override string GetTypeFromDefinition(MetadataReader reader, TypeDefinitionHandle handle, byte rawTypeKind = 0)
                => Key(rawTypeKind, LocalName(DefinitionName(reader, handle)));

            public override string GetTypeFromReference(MetadataReader reader, TypeReferenceHandle handle, byte rawTypeKind = 0)
                => Key(rawTypeKind, ReferenceName(reader, handle));

            public override string GetTypeFromSpecification(MetadataReader reader, GenericContext context, TypeSpecificationHandle handle, byte rawTypeKind = 0)
            {
                if (!resolving.Add(handle))
                {
                    throw new BadImageFormatException("Cyclic type specification.");
                }

                try
                {
                    return base.GetTypeFromSpecification(reader, context, handle, rawTypeKind);
                }
                finally
                {
                    resolving.Remove(handle);
                }
            }

            private string ReferenceName(MetadataReader reader, TypeReferenceHandle handle)
            {
                if (!resolving.Add(handle))
                {
                    throw new BadImageFormatException("Cyclic type reference.");
                }

                try
                {
                    var reference = reader.GetTypeReference(handle);
                    string ns = reader.GetString(reference.Namespace);
                    string name = (ns.Length == 0 ? "" : ns + ".") + reader.GetString(reference.Name);
                    return reference.ResolutionScope.Kind switch
                    {
                        HandleKind.ModuleDefinition => LocalName(name),
                        HandleKind.TypeReference => ReferenceName(reader, (TypeReferenceHandle)reference.ResolutionScope) + "+" + name,
                        HandleKind.AssemblyReference => Key(reader.GetAssemblyReference((AssemblyReferenceHandle)reference.ResolutionScope).GetAssemblyName().FullName, name),
                        HandleKind.ModuleReference => Key(reader.GetString(reader.GetModuleReference((ModuleReferenceHandle)reference.ResolutionScope).Name), name),
                        _ => throw new BadImageFormatException("Unsupported type reference scope."),
                    };
                }
                finally
                {
                    resolving.Remove(handle);
                }
            }

            private static string DefinitionName(MetadataReader reader, TypeDefinitionHandle handle)
            {
                var type = reader.GetTypeDefinition(handle);
                string name = reader.GetString(type.Name);
                if (type.IsNested)
                {
                    return DefinitionName(reader, type.GetDeclaringType()) + "+" + name;
                }

                string ns = reader.GetString(type.Namespace);
                return (ns.Length == 0 ? "" : ns + ".") + name;
            }

            // Self references (not other same-leaf references) must not partition
            // equivalent definitions by their own namespace, including enum literals.
            private string LocalName(string name) => name == owner ? "$self" :
                name.StartsWith(owner + "+", StringComparison.Ordinal) ? "$self" + name.Substring(owner.Length) : name;
        }
    }
}
