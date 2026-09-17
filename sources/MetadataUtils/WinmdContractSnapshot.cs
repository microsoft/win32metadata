using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Reflection.Metadata;
using System.Reflection.Metadata.Ecma335;
using System.Reflection.PortableExecutable;
using System.Security.Cryptography;
using Newtonsoft.Json;
using Newtonsoft.Json.Linq;
using static MetadataUtils.ContractTypeProvider;

namespace MetadataUtils
{
    /// <summary>
    /// Metadata-level API contracts, without WinRT projections or C# display lowering.
    /// Properties called "evidence" are forensic data, not semantic comparison input.
    /// </summary>
    public sealed class WinmdContractSnapshot
    {
        public const int SchemaVersion = 1;

        private readonly MetadataReader reader;
        private readonly ContractTypeProvider provider;
        private readonly Dictionary<TypeDefinitionHandle, JObject> types = new Dictionary<TypeDefinitionHandle, JObject>();
        private readonly Dictionary<EntityHandle, string> selections = new Dictionary<EntityHandle, string>();
        private readonly Dictionary<string, List<TypeDefinitionHandle>> typeNames;
        private readonly Queue<TypeDefinitionHandle> pending = new Queue<TypeDefinitionHandle>();
        private readonly HashSet<TypeDefinitionHandle> expanded = new HashSet<TypeDefinitionHandle>();

        private WinmdContractSnapshot(MetadataReader reader)
        {
            this.reader = reader;
            provider = new ContractTypeProvider(reader);
            typeNames = reader.TypeDefinitions.GroupBy(h => FullName(reader, h), StringComparer.Ordinal)
                .ToDictionary(g => g.Key, g => g.ToList(), StringComparer.Ordinal);
        }

        /// <summary>Read a complete image. Roots are exact, case-sensitive short or qualified declaration names.</summary>
        public static JObject Read(string path, IEnumerable<string> roots = null) => Read(File.ReadAllBytes(path), roots);

        /// <summary>The byte-array overload also supports isolated metadata-builder regression fixtures.</summary>
        public static JObject Read(byte[] image, IEnumerable<string> roots = null)
        {
            using var stream = new MemoryStream(image, writable: false);
            using var pe = new PEReader(stream);
            if (!pe.HasMetadata)
            {
                throw new BadImageFormatException("The input has no CLI metadata.");
            }

            var reader = pe.GetMetadataReader(MetadataReaderOptions.None);
            var snapshot = new WinmdContractSnapshot(reader).Create(roots);
            snapshot.AddFirst(new JProperty("source", Object("sha256", Convert.ToHexString(SHA256.HashData(image)),
                "length", image.Length, "metadataVersion", reader.MetadataVersion)));
            snapshot.AddFirst(new JProperty("schemaVersion", SchemaVersion));
            return snapshot;
        }

        /// <summary>Strip only designated forensic evidence and source identity; no namespace or attribute filtering.</summary>
        public static JToken SemanticFacts(JToken snapshot)
        {
            ValidateSnapshot(snapshot);
            var clone = (JObject)snapshot.DeepClone();
            clone.Remove("source");
            RemoveEvidence(clone);
            return clone;
        }

        /// <summary>Exact differences as JSON-pointer paths and first/second values (including presence).</summary>
        public static JObject Compare(JObject first, JObject second)
        {
            var differences = new JArray();
            Differences(SemanticFacts(first), SemanticFacts(second), "", differences);
            return Object("schemaVersion", SchemaVersion, "equal", differences.Count == 0,
                "firstMissingRoots", first["missingRoots"], "secondMissingRoots", second["missingRoots"], "differences", differences);
        }

        private static void ValidateSnapshot(JToken snapshot)
        {
            if (!(snapshot is JObject) || snapshot["schemaVersion"]?.Type != JTokenType.Integer ||
                (long)snapshot["schemaVersion"] != SchemaVersion)
            {
                throw new InvalidDataException("Unsupported or missing contract snapshot schemaVersion.");
            }

            if (!(snapshot["source"] is JObject) || !(snapshot["module"] is JObject) ||
                !(snapshot["assembly"] is JObject || snapshot["assembly"]?.Type == JTokenType.Null) ||
                !(snapshot["declarations"] is JArray) || !(snapshot["roots"] is JArray) ||
                !(snapshot["missingRoots"] is JArray) ||
                !new[] { "all", "roots" }.Contains((string)snapshot["selectionMode"]))
            {
                throw new InvalidDataException("Incomplete contract snapshot header or inventories.");
            }

            foreach (var root in snapshot["roots"])
            {
                if (!(root is JObject) || root["query"]?.Type != JTokenType.String || !(root["matches"] is JArray))
                {
                    throw new InvalidDataException("Invalid contract root inventory.");
                }
            }

            foreach (var type in snapshot["declarations"])
            {
                if (!(type is JObject) || (string)type["kind"] != "type" || type["qualifiedName"]?.Type != JTokenType.String ||
                    !(type["fields"] is JArray) || !(type["methods"] is JArray) ||
                    !(type["properties"] is JArray) || !(type["events"] is JArray))
                {
                    throw new InvalidDataException("Invalid contract type declaration.");
                }
            }
        }

        private JObject Create(IEnumerable<string> roots)
        {
            // These are not type/member contracts and cannot be represented faithfully
            // by this schema. Refuse them rather than silently implying full coverage.
            foreach (var table in new[] { TableIndex.ExportedType, TableIndex.File, TableIndex.ManifestResource })
            {
                if (reader.GetTableRowCount(table) != 0)
                {
                    throw new NotSupportedException($"Contract snapshots do not support nonempty {table} tables.");
                }
            }

            string[] queries = (roots ?? Array.Empty<string>()).Distinct(StringComparer.Ordinal).OrderBy(s => s, StringComparer.Ordinal).ToArray();
            if (queries.Any(string.IsNullOrWhiteSpace))
            {
                throw new ArgumentException("Roots must not be empty.", nameof(roots));
            }

            var rootMatches = new JArray();
            var missingRoots = new JArray();
            foreach (string query in queries)
            {
                var matches = new JArray();
                foreach (var typeHandle in reader.TypeDefinitions)
                {
                    var type = reader.GetTypeDefinition(typeHandle);
                    if (Matches(query, typeHandle, reader.GetString(type.Name), isType: true))
                    {
                        SelectType(typeHandle, "root");
                        matches.Add(Identity(typeHandle));
                    }

                    foreach (var handle in type.GetMethods())
                    {
                        if (Matches(query, typeHandle, reader.GetString(reader.GetMethodDefinition(handle).Name)))
                        {
                            SelectMember(typeHandle, handle);
                            var match = Identity(handle);
                            var method = reader.GetMethodDefinition(handle);
                            match.Add("signature", provider.MethodSignature(method.Signature));
                            match.Add("customAttributes", Attributes(method.GetCustomAttributes()));
                            matches.Add(match);
                        }
                    }

                    foreach (var handle in type.GetFields())
                    {
                        if (Matches(query, typeHandle, reader.GetString(reader.GetFieldDefinition(handle).Name)))
                        {
                            SelectMember(typeHandle, handle);
                            matches.Add(Identity(handle));
                        }
                    }

                    foreach (var handle in type.GetProperties())
                    {
                        if (Matches(query, typeHandle, reader.GetString(reader.GetPropertyDefinition(handle).Name)))
                        {
                            SelectMember(typeHandle, handle);
                            matches.Add(Identity(handle, typeHandle));
                        }
                    }

                    foreach (var handle in type.GetEvents())
                    {
                        if (Matches(query, typeHandle, reader.GetString(reader.GetEventDefinition(handle).Name)))
                        {
                            SelectMember(typeHandle, handle);
                            matches.Add(Identity(handle, typeHandle));
                        }
                    }
                }

                rootMatches.Add(Object("query", query, "matches", Sort(matches)));
                if (matches.Count == 0)
                {
                    missingRoots.Add(query);
                }
            }

            if (queries.Length == 0)
            {
                foreach (var handle in reader.TypeDefinitions)
                {
                    SelectType(handle, "owned");
                }
            }

            var assembly = ReadAssembly();
            var module = reader.GetModuleDefinition();
            var moduleFacts = Object("name", reader.GetString(module.Name),
                "customAttributes", Attributes(module.GetCustomAttributes()),
                "evidence", Object("mvid", reader.GetGuid(module.Mvid), "generation", module.Generation,
                    "generationId", module.GenerationId.IsNil ? null : reader.GetGuid(module.GenerationId),
                    "baseGenerationId", module.BaseGenerationId.IsNil ? null : reader.GetGuid(module.BaseGenerationId)));
            if (assembly != null)
            {
                AddDependencies(assembly);
            }

            AddDependencies(moduleFacts);

            if (queries.Length > 0)
            {
                // First inspect root members and their declaring type's contract, not
                // the entire Apis class (which would pull in unrelated headers).
                foreach (var handle in selections.Keys.Where(h => h.Kind == HandleKind.TypeDefinition).Select(h => (TypeDefinitionHandle)h).ToArray())
                {
                    var facts = ReadType(handle, full: selections[handle] != "context");
                    types[handle] = facts;
                    AddDependencies(facts);
                }
            }

            while (pending.Count > 0)
            {
                var handle = pending.Dequeue();
                if (!expanded.Add(handle))
                {
                    continue;
                }

                var facts = ReadType(handle, full: true);
                types[handle] = facts;
                AddDependencies(facts);
                var type = reader.GetTypeDefinition(handle);
                foreach (var nested in type.GetNestedTypes())
                {
                    SelectType(nested, selections[handle] == "dependency" ? "dependency" : "owned");
                }

                if (type.IsNested)
                {
                    var declaring = type.GetDeclaringType();
                    if (!selections.ContainsKey(declaring))
                    {
                        selections[declaring] = "context";
                        var parentFacts = ReadType(declaring, full: false);
                        types[declaring] = parentFacts;
                        AddDependencies(parentFacts);
                    }
                }
            }

            var declarations = new JArray();
            foreach (var entry in types)
            {
                // A later root or dependency may have upgraded a previously selected context.
                entry.Value["designation"] = selections[entry.Key];
                declarations.Add(entry.Value);
            }

            return Object("assembly", assembly, "module", moduleFacts,
                "selectionMode", queries.Length == 0 ? "all" : "roots",
                "roots", rootMatches, "missingRoots", missingRoots, "declarations", Sort(declarations));
        }

        private bool Matches(string query, TypeDefinitionHandle owner, string name, bool isType = false)
        {
            string fullName = FullName(reader, owner);
            string ns = reader.GetString(reader.GetTypeDefinition(owner).Namespace);
            return query == name || query == (isType ? fullName : fullName + "." + name) ||
                (!isType && query == Qualify(ns, name));
        }

        private void SelectMember(TypeDefinitionHandle type, EntityHandle member, string designation = "root")
        {
            if (member.IsNil)
            {
                return;
            }

            if (!selections.TryGetValue(member, out var current) || current != "root")
            {
                selections[member] = designation;
            }

            if (!selections.ContainsKey(type))
            {
                selections[type] = "context";
            }

            if (member.Kind == HandleKind.PropertyDefinition)
            {
                var accessors = reader.GetPropertyDefinition((PropertyDefinitionHandle)member).GetAccessors();
                SelectMember(type, accessors.Getter, "owned");
                SelectMember(type, accessors.Setter, "owned");
                foreach (var accessor in accessors.Others)
                {
                    SelectMember(type, accessor, "owned");
                }
            }
            else if (member.Kind == HandleKind.EventDefinition)
            {
                var accessors = reader.GetEventDefinition((EventDefinitionHandle)member).GetAccessors();
                SelectMember(type, accessors.Adder, "owned");
                SelectMember(type, accessors.Remover, "owned");
                SelectMember(type, accessors.Raiser, "owned");
                foreach (var accessor in accessors.Others)
                {
                    SelectMember(type, accessor, "owned");
                }
            }
        }

        private void SelectType(TypeDefinitionHandle type, string designation)
        {
            if (!selections.TryGetValue(type, out string current) || current == "context")
            {
                selections[type] = designation;
                pending.Enqueue(type);
            }
            else if ((designation == "root" && current != "root") || (designation == "owned" && current == "dependency"))
            {
                selections[type] = designation;
                if (expanded.Remove(type))
                {
                    pending.Enqueue(type);
                }
            }
        }

        private JObject ReadAssembly()
        {
            if (!reader.IsAssembly)
            {
                return null;
            }

            var assembly = reader.GetAssemblyDefinition();
            return Object("name", reader.GetString(assembly.Name), "version", assembly.Version.ToString(),
                "culture", reader.GetString(assembly.Culture), "flags", (int)assembly.Flags,
                "hashAlgorithm", (int)assembly.HashAlgorithm, "publicKey", Convert.ToHexString(reader.GetBlobBytes(assembly.PublicKey)),
                "customAttributes", Attributes(assembly.GetCustomAttributes()),
                "security", Security(assembly.GetDeclarativeSecurityAttributes()));
        }

        private JObject ReadType(TypeDefinitionHandle handle, bool full)
        {
            var type = reader.GetTypeDefinition(handle);
            var result = Identity(handle);
            result.Add("designation", selections[handle]);
            result.Add("attributes", Flags(type.Attributes));
            result.Add("baseType", provider.Type(type.BaseType));
            var layout = type.GetLayout();
            result.Add("layout", Object("isDefault", layout.IsDefault, "packingSize", layout.PackingSize, "size", layout.Size));
            result.Add("declaringType", type.IsNested ? FullName(reader, type.GetDeclaringType()) : null);
            result.Add("customAttributes", Attributes(type.GetCustomAttributes()));
            result.Add("security", Security(type.GetDeclarativeSecurityAttributes()));
            result.Add("genericParameters", GenericParameters(type.GetGenericParameters()));
            result.Add("interfaces", new JArray(type.GetInterfaceImplementations().Select(h =>
            {
                var implementation = reader.GetInterfaceImplementation(h);
                return Object("type", provider.Type(implementation.Interface),
                    "customAttributes", Attributes(implementation.GetCustomAttributes()), "evidence", Evidence(h));
            })));
            result.Add("methodImplementations", Sort(new JArray(type.GetMethodImplementations().Select(h =>
            {
                var implementation = reader.GetMethodImplementation(h);
                return Object("body", MethodReference(implementation.MethodBody), "declaration", MethodReference(implementation.MethodDeclaration),
                    "customAttributes", Attributes(implementation.GetCustomAttributes()), "evidence", Evidence(h));
            }))));
            result.Add("fields", new JArray(type.GetFields().Where(h => full || selections.ContainsKey(h)).Select(h => ReadField(h, handle))));
            var methodHandles = type.GetMethods().Where(h => full || selections.ContainsKey(h)).ToArray();
            var methods = new JArray(methodHandles.Select(h => ReadMethod(h, handle)));
            bool vtableOrdered = (type.Attributes & TypeAttributes.Interface) != 0 ||
                methodHandles.Any(h => (reader.GetMethodDefinition(h).Attributes & MethodAttributes.Virtual) != 0);
            result.Add("methods", vtableOrdered ? methods : Sort(methods));
            result.Add("properties", Sort(new JArray(type.GetProperties().Where(h => full || selections.ContainsKey(h)).Select(h => ReadProperty(h, handle)))));
            result.Add("events", Sort(new JArray(type.GetEvents().Where(h => full || selections.ContainsKey(h)).Select(h => ReadEvent(h, handle)))));
            return result;
        }

        private string MemberDesignation(EntityHandle member, TypeDefinitionHandle owner)
            => selections.TryGetValue(member, out string designation) ? designation : selections[owner] == "dependency" ? "dependency" : "owned";

        private JObject ReadField(FieldDefinitionHandle handle, TypeDefinitionHandle owner)
        {
            var field = reader.GetFieldDefinition(handle);
            if (field.GetRelativeVirtualAddress() != 0)
            {
                throw new NotSupportedException($"Field RVA data is not supported: {FullName(reader, owner)}.{reader.GetString(field.Name)}.");
            }

            var result = Identity(handle);
            result.Add("designation", MemberDesignation(handle, owner));
            result.Add("attributes", Flags(field.Attributes));
            result.Add("type", provider.FieldSignature(field.Signature));
            result.Add("offset", field.GetOffset());
            result.Add("constant", Constant(field.GetDefaultValue()));
            result.Add("marshalling", ContractMarshalling.Read(reader, field.GetMarshallingDescriptor()));
            result.Add("customAttributes", Attributes(field.GetCustomAttributes()));
            ((JObject)result["evidence"]).Add("signature", Blob(field.Signature));
            return result;
        }

        private JObject ReadMethod(MethodDefinitionHandle handle, TypeDefinitionHandle owner)
        {
            var method = reader.GetMethodDefinition(handle);
            var result = Identity(handle);
            result.Add("designation", MemberDesignation(handle, owner));
            result.Add("attributes", Flags(method.Attributes));
            result.Add("implementationAttributes", Flags(method.ImplAttributes));
            result.Add("signature", provider.MethodSignature(method.Signature));
            result.Add("genericParameters", GenericParameters(method.GetGenericParameters()));
            result.Add("customAttributes", Attributes(method.GetCustomAttributes()));
            result.Add("security", Security(method.GetDeclarativeSecurityAttributes()));
            var parameters = new JArray();
            var sequences = new HashSet<int>();
            foreach (var parameterHandle in method.GetParameters())
            {
                var parameter = reader.GetParameter(parameterHandle);
                if (!sequences.Add(parameter.SequenceNumber) || parameter.SequenceNumber > ((JArray)result["signature"]["parameterTypes"]).Count)
                {
                    throw new BadImageFormatException($"Invalid parameter sequence in {result["qualifiedName"]}.");
                }

                parameters.Add(Object("sequence", parameter.SequenceNumber, "name", reader.GetString(parameter.Name),
                    "attributes", Flags(parameter.Attributes), "constant", Constant(parameter.GetDefaultValue()),
                    "marshalling", ContractMarshalling.Read(reader, parameter.GetMarshallingDescriptor()),
                    "customAttributes", Attributes(parameter.GetCustomAttributes()), "evidence", Evidence(parameterHandle)));
            }

            result.Add("parameters", parameters);
            var import = method.GetImport();
            result.Add("import", import.Module.IsNil ? null : Object("module", reader.GetString(reader.GetModuleReference(import.Module).Name),
                "name", reader.GetString(import.Name), "attributes", Flags(import.Attributes)));
            ((JObject)result["evidence"]).Add("signature", Blob(method.Signature));
            ((JObject)result["evidence"]).Add("relativeVirtualAddress", method.RelativeVirtualAddress);
            return result;
        }

        private JObject ReadProperty(PropertyDefinitionHandle handle, TypeDefinitionHandle owner)
        {
            var property = reader.GetPropertyDefinition(handle);
            var result = Identity(handle, owner);
            result.Add("designation", MemberDesignation(handle, owner));
            result.Add("attributes", Flags(property.Attributes));
            result.Add("signature", provider.MethodSignature(property.Signature, property: true));
            result.Add("constant", Constant(property.GetDefaultValue()));
            result.Add("customAttributes", Attributes(property.GetCustomAttributes()));
            var accessors = property.GetAccessors();
            result.Add("accessors", Object("getter", MethodReference(accessors.Getter), "setter", MethodReference(accessors.Setter),
                "others", Sort(new JArray(accessors.Others.Select(h => MethodReference(h))))));
            ((JObject)result["evidence"]).Add("signature", Blob(property.Signature));
            return result;
        }

        private JObject ReadEvent(EventDefinitionHandle handle, TypeDefinitionHandle owner)
        {
            var definition = reader.GetEventDefinition(handle);
            var result = Identity(handle, owner);
            result.Add("designation", MemberDesignation(handle, owner));
            result.Add("attributes", Flags(definition.Attributes));
            result.Add("type", provider.Type(definition.Type));
            result.Add("customAttributes", Attributes(definition.GetCustomAttributes()));
            var accessors = definition.GetAccessors();
            result.Add("accessors", Object("adder", MethodReference(accessors.Adder), "remover", MethodReference(accessors.Remover),
                "raiser", MethodReference(accessors.Raiser), "others", Sort(new JArray(accessors.Others.Select(h => MethodReference(h))))));
            return result;
        }

        private JArray GenericParameters(GenericParameterHandleCollection handles)
        {
            return new JArray(handles.Select(h =>
            {
                var parameter = reader.GetGenericParameter(h);
                return Object("index", parameter.Index, "name", reader.GetString(parameter.Name), "attributes", Flags(parameter.Attributes),
                    "customAttributes", Attributes(parameter.GetCustomAttributes()), "constraints", Sort(new JArray(parameter.GetConstraints().Select(c =>
                    {
                        var constraint = reader.GetGenericParameterConstraint(c);
                        return Object("type", provider.Type(constraint.Type), "customAttributes", Attributes(constraint.GetCustomAttributes()),
                            "evidence", Evidence(c));
                    }))), "evidence", Evidence(h));
            }));
        }

        private JObject Constant(ConstantHandle handle)
        {
            if (handle.IsNil)
            {
                return null;
            }

            var constant = reader.GetConstant(handle);
            var blob = reader.GetBlobReader(constant.Value);
            object value = blob.ReadConstant(constant.TypeCode);
            End(blob, "constant");
            return Object("typeCode", constant.TypeCode.ToString(), "value", Value(value),
                "evidence", Object("token", MetadataTokens.GetToken(handle), "blob", Blob(constant.Value)));
        }

        private JArray Attributes(CustomAttributeHandleCollection handles)
        {
            var attributes = new JArray();
            foreach (var handle in handles)
            {
                var attribute = reader.GetCustomAttribute(handle);
                var constructor = MethodReference(attribute.Constructor);
                if ((string)constructor["name"] != ".ctor" || !(bool)constructor["signature"]["hasThis"] ||
                    (int)constructor["signature"]["genericParameterCount"] != 0 ||
                    (string)constructor["signature"]["returnType"]?["name"] != "Void")
                {
                    throw new BadImageFormatException("Custom attribute constructor is not .ctor.");
                }

                JObject decoded = ContractAttributeDecoder.Read(reader, provider, attribute.Value, constructor);
                decoded.Add("evidence", Object("token", MetadataTokens.GetToken(handle), "blob", Blob(attribute.Value)));
                attributes.Add(decoded);
            }

            return Sort(attributes);
        }

        private JArray Security(DeclarativeSecurityAttributeHandleCollection handles)
        {
            return Sort(new JArray(handles.Select(h =>
            {
                var permission = reader.GetDeclarativeSecurityAttribute(h);
                return Object("action", Flags(permission.Action),
                    "permissions", ContractAttributeDecoder.ReadPermissionSet(reader, provider, permission.PermissionSet),
                    "customAttributes", Attributes(reader.GetCustomAttributes(h)),
                    "evidence", Object("token", MetadataTokens.GetToken(h), "blob", Blob(permission.PermissionSet)));
            })));
        }

        private JObject MethodReference(EntityHandle handle)
        {
            if (handle.IsNil)
            {
                return null;
            }

            if (handle.Kind == HandleKind.MethodDefinition)
            {
                var method = reader.GetMethodDefinition((MethodDefinitionHandle)handle);
                return Object("declaringType", provider.Type(method.GetDeclaringType()), "name", reader.GetString(method.Name),
                    "signature", provider.MethodSignature(method.Signature));
            }

            if (handle.Kind == HandleKind.MemberReference)
            {
                var member = reader.GetMemberReference((MemberReferenceHandle)handle);
                return Object("declaringType", provider.Type(member.Parent), "name", reader.GetString(member.Name),
                    "signature", provider.MethodSignature(member.Signature));
            }

            throw new BadImageFormatException($"Unsupported method reference {handle.Kind}.");
        }

        private JObject Identity(EntityHandle handle, TypeDefinitionHandle owner = default)
        {
            string name;
            string kind;
            switch (handle.Kind)
            {
                case HandleKind.TypeDefinition:
                    owner = (TypeDefinitionHandle)handle;
                    name = reader.GetString(reader.GetTypeDefinition(owner).Name);
                    kind = "type";
                    break;
                case HandleKind.MethodDefinition:
                    var method = reader.GetMethodDefinition((MethodDefinitionHandle)handle);
                    owner = method.GetDeclaringType();
                    name = reader.GetString(method.Name);
                    kind = "method";
                    break;
                case HandleKind.FieldDefinition:
                    var field = reader.GetFieldDefinition((FieldDefinitionHandle)handle);
                    owner = field.GetDeclaringType();
                    name = reader.GetString(field.Name);
                    kind = "field";
                    break;
                case HandleKind.PropertyDefinition:
                    name = reader.GetString(reader.GetPropertyDefinition((PropertyDefinitionHandle)handle).Name);
                    kind = "property";
                    break;
                case HandleKind.EventDefinition:
                    name = reader.GetString(reader.GetEventDefinition((EventDefinitionHandle)handle).Name);
                    kind = "event";
                    break;
                default:
                    throw new BadImageFormatException($"Unsupported declaration identity {handle.Kind}.");
            }

            string ns = reader.GetString(reader.GetTypeDefinition(owner).Namespace);
            string fullName = FullName(reader, owner);
            var result = Object("kind", kind, "namespace", ns, "name", name,
                "qualifiedName", kind == "type" ? fullName : fullName + "." + name, "evidence", Evidence(handle));
            return result;
        }

        private void AddDependencies(JToken facts)
        {
            foreach (var item in ((JContainer)facts).DescendantsAndSelf().OfType<JObject>())
            {
                string kind = (string)item["kind"];
                string name = null;
                if (kind == "type" && item["fullName"] != null && item["scope"]?.Type == JTokenType.Null)
                {
                    name = (string)item["fullName"];
                }
                else if (kind == "serializedType")
                {
                    foreach (string serializedName in provider.LocalSerializedTypes((string)item["name"]))
                    {
                        AddTypeDependencies(serializedName);
                    }
                }

                if (name != null)
                {
                    AddTypeDependencies(name);
                }

                // AssociatedEnum uses a string, not an ECMA type reference. Resolve
                // every exact local match, including architecture-specific definitions.
                string attributeName = (string)item["constructor"]?["declaringType"]?["fullName"];
                if (attributeName == "Windows.Win32.Foundation.Metadata.AssociatedEnumAttribute" ||
                    attributeName == "Windows.Win32.Metadata.AssociatedEnumAttribute")
                {
                    string enumName = (string)item["fixedArguments"]?[0]?["value"];
                    if (enumName != null)
                    {
                        foreach (var pair in typeNames.Where(p => p.Key == enumName || p.Key.EndsWith("." + enumName, StringComparison.Ordinal)))
                        {
                            foreach (var definition in pair.Value)
                            {
                                SelectType(definition, "dependency");
                            }
                        }
                    }
                }
            }
        }

        private void AddTypeDependencies(string name)
        {
            if (typeNames.TryGetValue(name, out var definitions))
            {
                foreach (var definition in definitions)
                {
                    SelectType(definition, "dependency");
                }
            }
        }

        private string Blob(BlobHandle handle) => Convert.ToHexString(reader.GetBlobBytes(handle));

        private static JObject Evidence(EntityHandle handle) => Object("token", MetadataTokens.GetToken(handle));

        private static JObject Flags<T>(T value) where T : Enum => Object("value", Convert.ToInt64(value), "names", value.ToString());

        internal static JArray Sort(JArray array) => new JArray(array.OrderBy(CanonicalKey, StringComparer.Ordinal));

        private static string CanonicalKey(JToken value)
        {
            var clone = value.DeepClone();
            RemoveEvidence(clone);
            return clone.ToString(Formatting.None);
        }

        private static void RemoveEvidence(JToken token)
        {
            if (token is JObject obj)
            {
                obj.Remove("evidence");
                foreach (var property in obj.Properties())
                {
                    RemoveEvidence(property.Value);
                }
            }
            else if (token is JArray array)
            {
                foreach (var item in array)
                {
                    RemoveEvidence(item);
                }
            }
        }

        private static void Differences(JToken first, JToken second, string path, JArray result)
        {
            if (JToken.DeepEquals(first, second))
            {
                return;
            }

            if (first is JObject a && second is JObject b)
            {
                foreach (string name in a.Properties().Select(p => p.Name).Union(b.Properties().Select(p => p.Name)).OrderBy(s => s, StringComparer.Ordinal))
                {
                    Differences(a[name], b[name], path + "/" + name.Replace("~", "~0").Replace("/", "~1"), result);
                }
            }
            else if (first is JArray x && second is JArray y)
            {
                for (int i = 0; i < Math.Max(x.Count, y.Count); i++)
                {
                    Differences(i < x.Count ? x[i] : null, i < y.Count ? y[i] : null, path + "/" + i, result);
                }
            }
            else
            {
                result.Add(Object("path", path, "firstPresent", first != null, "secondPresent", second != null,
                    "first", first, "second", second));
            }
        }
    }
}
