#nullable enable

using System;
using System.Collections.Immutable;
using System.Linq;
using System.Reflection;
using System.Reflection.Metadata;
using Xunit;

namespace Win32MetadataTestCases
{
    internal static class NativeContractPhysicalAssertions
    {
        internal static void AssertNativeHeaders(MetadataReader reader)
        {
            var imported = Method(reader, "Apis", "Imported");
            var import = imported.GetImport();
            Assert.Equal("header.dll", reader.GetString(reader.GetModuleReference(import.Module).Name));
            Assert.True(import.Attributes.HasFlag(MethodImportAttributes.SetLastError));
            Assert.True(imported.Attributes.HasFlag(MethodAttributes.Static));
            Assert.False(imported.DecodeSignature(new SignatureNames(), null).Header.IsInstance);
            StringAttribute(reader, imported.GetCustomAttributes(), "SupportedOSPlatformAttribute", "windows10.0.10240");
            var parameters = imported.GetParameters().Select(reader.GetParameter).ToArray();
            Assert.True(parameters[0].Attributes.HasFlag(ParameterAttributes.In));
            HasAttribute(reader, parameters[0].GetCustomAttributes(), "RetainedAttribute");
            Assert.True(parameters[1].Attributes.HasFlag(ParameterAttributes.Out));
            Assert.True(parameters[1].Attributes.HasFlag(ParameterAttributes.Optional));
            HasAttribute(reader, parameters[1].GetCustomAttributes(), "ContainsInteriorPointersAttribute");
            HasAttribute(reader, parameters[1].GetCustomAttributes(), "MemorySizeAttribute");
            var open = Method(reader, "Apis", "OpenThing");
            var result = open.GetParameters().Select(reader.GetParameter).Single(parameter => parameter.SequenceNumber == 0);
            StringAttribute(reader, result.GetCustomAttributes(), "RAIIFreeAttribute", "CloseThing");
            Assert.Equal(new long[] { 0, -1 }, InvalidValues(reader, result.GetCustomAttributes()));
            Absent(reader, open.GetCustomAttributes(), "RAIIFreeAttribute");
            var create = Method(reader, "Apis", "CreateThing");
            var output = create.GetParameters().Select(reader.GetParameter).Single(parameter => parameter.SequenceNumber == 1);
            Assert.True(output.Attributes.HasFlag(ParameterAttributes.Out));
            StringAttribute(reader, output.GetCustomAttributes(), "RAIIFreeAttribute", "CloseThing");
            Assert.Equal(new long[] { 0 }, InvalidValues(reader, output.GetCustomAttributes()));
            Assert.True(Method(reader, "Apis", "ExactResult").ImplAttributes.HasFlag(MethodImplAttributes.PreserveSig));
            var retval = Method(reader, "Apis", "Retval").GetParameters().Select(reader.GetParameter).Single();
            HasAttribute(reader, retval.GetCustomAttributes(), "RetValAttribute");
            Assert.True(retval.Attributes.HasFlag(ParameterAttributes.Out));
            var midlRetval = Method(reader, "Apis", "MidlRetval").GetParameters().Select(reader.GetParameter).Single();
            HasAttribute(reader, midlRetval.GetCustomAttributes(), "RetValAttribute");
            Assert.True(midlRetval.Attributes.HasFlag(ParameterAttributes.Out));
            var associated = Method(reader, "Apis", "AssociatedReturn").GetParameters().Select(reader.GetParameter)
                .Single(parameter => parameter.SequenceNumber == 0);
            StringAttribute(reader, associated.GetCustomAttributes(), "AssociatedEnumAttribute", "Options");
            var optionParameter = Method(reader, "Apis", "ReadOption").GetParameters().Select(reader.GetParameter).Single();
            StringAttribute(reader, optionParameter.GetCustomAttributes(), "AssociatedEnumAttribute", "Options");
            var record = Type(reader, "DESCRIPTION");
            StringAttribute(reader, record.GetCustomAttributes(), "SupportedOSPlatformAttribute", "windows10.0.10240");
            var flags = record.GetFields().Select(reader.GetFieldDefinition).Single(field => reader.GetString(field.Name) == "flags");
            StringAttribute(reader, flags.GetCustomAttributes(), "AssociatedEnumAttribute", "Options");
            var options = Type(reader, "Options");
            StringAttribute(reader, options.GetCustomAttributes(), "SupportedOSPlatformAttribute", "windows10.0.10240");
            Assert.Equal(2, options.GetCustomAttributes().Count(handle => AttributeName(reader, handle) == "AssociatedConstantAttribute"));
            var scoped = Type(reader, "ScopedOptions");
            HasAttribute(reader, scoped.GetCustomAttributes(), "ScopedEnumAttribute");
            HasAttribute(reader, scoped.GetCustomAttributes(), "FlagsAttribute");
            var token = Type(reader, "TOKEN");
            HasAttribute(reader, token.GetCustomAttributes(), "NativeTypedefAttribute");
            StringAttribute(reader, token.GetCustomAttributes(), "AlsoUsableForAttribute", "OTHER_TOKEN");
            StringAttribute(reader, token.GetCustomAttributes(), "SupportedOSPlatformAttribute", "windows6.1");
            var tokenSignature = Method(reader, "Apis", "UseToken").DecodeSignature(new SignatureNames(), null);
            Assert.Equal("TOKEN", tokenSignature.ReturnType);
            Assert.Equal(new[] { "TOKEN", "TOKEN*" }, tokenSignature.ParameterTypes);
            var callback = Type(reader, "PFN_ALIAS");
            StringAttribute(reader, callback.GetCustomAttributes(), "SupportedOSPlatformAttribute", "windows6.1");
            var invoke = Method(reader, "PFN_ALIAS", "Invoke");
            Assert.Equal(new[] { "context", "count" }, invoke.GetParameters().Select(reader.GetParameter)
                .Select(parameter => reader.GetString(parameter.Name)));
            Assert.Equal(new[] { "Void*", "UInt32" }, invoke.DecodeSignature(new SignatureNames(), null).ParameterTypes);
            HasAttribute(reader, invoke.GetParameters().Select(reader.GetParameter).First().GetCustomAttributes(), "RetainedAttribute");
            var com = Type(reader, "IHeaderSample");
            Assert.True(com.Attributes.HasFlag(TypeAttributes.Interface));
            Assert.Equal(new[] { "Exact", "Produce", "Buffer" }, com.GetMethods().Select(reader.GetMethodDefinition)
                .Select(method => reader.GetString(method.Name)));
            var exact = Method(reader, "IHeaderSample", "Exact");
            Assert.True(exact.ImplAttributes.HasFlag(MethodImplAttributes.PreserveSig));
            StringAttribute(reader, exact.GetCustomAttributes(), "SupportedOSPlatformAttribute", "windows6.1");
            var produced = Method(reader, "IHeaderSample", "Produce").GetParameters().Select(reader.GetParameter)
                .Single(parameter => parameter.SequenceNumber == 0);
            StringAttribute(reader, produced.GetCustomAttributes(), "RAIIFreeAttribute", "CloseThing");
            Assert.Equal(new long[] { 0, -1 }, InvalidValues(reader, produced.GetCustomAttributes()));
            var buffer = Method(reader, "IHeaderSample", "Buffer").GetParameters().Select(reader.GetParameter)
                .Single(parameter => parameter.SequenceNumber == 1);
            HasAttribute(reader, buffer.GetCustomAttributes(), "ContainsInteriorPointersAttribute");
            Assert.True(buffer.Attributes.HasFlag(ParameterAttributes.Out));
            AssertMetadataClosure(reader);
        }

        internal static void AssertMetadataClosure(MetadataReader reader)
        {
            var localTypes = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Select(type => reader.GetString(type.Namespace) + "." + reader.GetString(type.Name)).ToHashSet();
            foreach (var handle in reader.TypeReferences)
            {
                var type = reader.GetTypeReference(handle);
                Assert.False(type.ResolutionScope.IsNil);
                if (type.ResolutionScope.Kind == HandleKind.ModuleDefinition)
                    Assert.Contains(reader.GetString(type.Namespace) + "." + reader.GetString(type.Name), localTypes);
            }
            foreach (var handle in reader.CustomAttributes)
            {
                Assert.DoesNotContain(AttributeName(reader, handle),
                    new[] { "NativeAnnotationAttribute", "SourceLocationAttribute", "CppAttributeList" });
                var constructor = reader.GetCustomAttribute(handle).Constructor;
                if (constructor.Kind != HandleKind.MemberReference)
                    continue;
                var reference = reader.GetMemberReference((MemberReferenceHandle)constructor);
                if (reference.Parent.Kind != HandleKind.TypeReference)
                    continue;
                var type = reader.GetTypeReference((TypeReferenceHandle)reference.Parent);
                if (type.ResolutionScope.Kind != HandleKind.ModuleDefinition)
                    continue;
                string fullName = reader.GetString(type.Namespace) + "." + reader.GetString(type.Name);
                var definition = reader.TypeDefinitions.Select(reader.GetTypeDefinition).Single(candidate =>
                    reader.GetString(candidate.Namespace) + "." + reader.GetString(candidate.Name) == fullName);
                var provider = new SignatureNames(qualifiedNames: true);
                var expected = reference.DecodeMethodSignature(provider, null);
                Assert.True(expected.Header.IsInstance);
                var actual = Assert.Single(definition.GetMethods().Select(reader.GetMethodDefinition)
                    .Where(method => reader.GetString(method.Name) == ".ctor")
                    .Select(method => (Method: method, Signature: method.DecodeSignature(provider, null)))
                    .Where(candidate => candidate.Signature.Header.RawValue == expected.Header.RawValue &&
                        candidate.Signature.GenericParameterCount == expected.GenericParameterCount &&
                        candidate.Signature.RequiredParameterCount == expected.RequiredParameterCount &&
                        candidate.Signature.ReturnType == expected.ReturnType &&
                        candidate.Signature.ParameterTypes.SequenceEqual(expected.ParameterTypes)));
                Assert.False(actual.Method.Attributes.HasFlag(MethodAttributes.Static));
                Assert.True(actual.Method.Attributes.HasFlag(MethodAttributes.SpecialName | MethodAttributes.RTSpecialName));
            }
        }

        private static TypeDefinition Type(MetadataReader reader, string name)
            => reader.TypeDefinitions.Select(reader.GetTypeDefinition).Single(type => reader.GetString(type.Name) == name);

        private static MethodDefinition Method(MetadataReader reader, string type, string name)
            => Type(reader, type).GetMethods().Select(reader.GetMethodDefinition).Single(method => reader.GetString(method.Name) == name);

        private static string AttributeName(MetadataReader reader, CustomAttributeHandle handle)
        {
            var constructor = reader.GetCustomAttribute(handle).Constructor;
            var type = constructor.Kind == HandleKind.MethodDefinition
                ? reader.GetMethodDefinition((MethodDefinitionHandle)constructor).GetDeclaringType()
                : reader.GetMemberReference((MemberReferenceHandle)constructor).Parent;
            return type.Kind == HandleKind.TypeDefinition
                ? reader.GetString(reader.GetTypeDefinition((TypeDefinitionHandle)type).Name)
                : reader.GetString(reader.GetTypeReference((TypeReferenceHandle)type).Name);
        }

        private static void HasAttribute(MetadataReader reader, CustomAttributeHandleCollection attributes, string name)
        {
            var handle = attributes.Single(handle => AttributeName(reader, handle) == name);
            AssertAttributeIdentity(reader, handle, name);
        }

        private static void Absent(MetadataReader reader, CustomAttributeHandleCollection attributes, string name)
            => Assert.DoesNotContain(attributes, handle => AttributeName(reader, handle) == name);

        private static void StringAttribute(MetadataReader reader, CustomAttributeHandleCollection attributes, string name, string expected)
        {
            var handle = attributes.Single(handle => AttributeName(reader, handle) == name);
            AssertAttributeIdentity(reader, handle, name);
            var attribute = reader.GetCustomAttribute(handle);
            var blob = reader.GetBlobReader(attribute.Value);
            Assert.Equal(1, blob.ReadUInt16());
            Assert.Equal(expected, blob.ReadSerializedString());
            Assert.Equal(0, blob.ReadUInt16());
            Assert.Equal(0, blob.RemainingBytes);
        }

        private static long[] InvalidValues(MetadataReader reader, CustomAttributeHandleCollection attributes)
            => attributes.Where(handle => AttributeName(reader, handle) == "InvalidHandleValueAttribute")
                .Select(handle =>
                {
                    AssertAttributeIdentity(reader, handle, "InvalidHandleValueAttribute");
                    var blob = reader.GetBlobReader(reader.GetCustomAttribute(handle).Value);
                    Assert.Equal(1, blob.ReadUInt16());
                    long value = blob.ReadInt64();
                    Assert.Equal(0, blob.ReadUInt16());
                    Assert.Equal(0, blob.RemainingBytes);
                    return value;
                }).ToArray();

        private static void AssertAttributeIdentity(MetadataReader reader, CustomAttributeHandle handle, string name)
        {
            var constructor = reader.GetCustomAttribute(handle).Constructor;
            EntityHandle type;
            if (constructor.Kind == HandleKind.MethodDefinition)
            {
                var method = reader.GetMethodDefinition((MethodDefinitionHandle)constructor);
                Assert.Equal(".ctor", reader.GetString(method.Name));
                type = method.GetDeclaringType();
            }
            else
            {
                Assert.Equal(HandleKind.MemberReference, constructor.Kind);
                var method = reader.GetMemberReference((MemberReferenceHandle)constructor);
                Assert.Equal(".ctor", reader.GetString(method.Name));
                type = method.Parent;
            }
            string expectedNamespace = name == "FlagsAttribute" ? "System" : "Windows.Win32.Foundation.Metadata";
            if (type.Kind == HandleKind.TypeDefinition)
            {
                var definition = reader.GetTypeDefinition((TypeDefinitionHandle)type);
                Assert.Equal(expectedNamespace, reader.GetString(definition.Namespace));
                Assert.Equal(name, reader.GetString(definition.Name));
            }
            else
            {
                Assert.Equal(HandleKind.TypeReference, type.Kind);
                var reference = reader.GetTypeReference((TypeReferenceHandle)type);
                Assert.Equal(expectedNamespace, reader.GetString(reference.Namespace));
                Assert.Equal(name, reader.GetString(reference.Name));
                Assert.Equal(name == "FlagsAttribute" ? HandleKind.AssemblyReference : HandleKind.ModuleDefinition,
                    reference.ResolutionScope.Kind);
            }
        }

        private sealed class SignatureNames : ISignatureTypeProvider<string, object?>
        {
            private readonly bool qualifiedNames;
            internal SignatureNames(bool qualifiedNames = false) => this.qualifiedNames = qualifiedNames;
            public string GetArrayType(string element, ArrayShape shape) => element + "[]";
            public string GetByReferenceType(string element) => element + "&";
            public string GetFunctionPointerType(MethodSignature<string> signature) => "fnptr";
            public string GetGenericInstantiation(string type, ImmutableArray<string> arguments) => type;
            public string GetGenericMethodParameter(object? context, int index) => "!!" + index;
            public string GetGenericTypeParameter(object? context, int index) => "!" + index;
            public string GetModifiedType(string modifier, string type, bool required) => type;
            public string GetPinnedType(string element) => element;
            public string GetPointerType(string element) => element + "*";
            public string GetPrimitiveType(PrimitiveTypeCode type) => type.ToString();
            public string GetSZArrayType(string element) => element + "[]";
            public string GetTypeFromDefinition(MetadataReader reader, TypeDefinitionHandle handle, byte kind)
            {
                var type = reader.GetTypeDefinition(handle);
                return Name(reader, type.Namespace, type.Name);
            }
            public string GetTypeFromReference(MetadataReader reader, TypeReferenceHandle handle, byte kind)
            {
                var type = reader.GetTypeReference(handle);
                return Name(reader, type.Namespace, type.Name);
            }
            public string GetTypeFromSpecification(MetadataReader reader, object? context, TypeSpecificationHandle handle, byte kind)
                => reader.GetTypeSpecification(handle).DecodeSignature(this, context);
            private string Name(MetadataReader reader, StringHandle ns, StringHandle name)
                => qualifiedNames ? reader.GetString(ns) + "." + reader.GetString(name) : reader.GetString(name);
        }
    }
}
