using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Reflection.Metadata;
using System.Reflection.Metadata.Ecma335;
using System.Reflection.PortableExecutable;
using Xunit;

namespace MetadataUtils.Tests
{
    public class WinmdParameterTests
    {
        [Theory]
        [InlineData("Delegate")]
        [InlineData("Class")]
        [InlineData("Interface")]
        public void AbsentParameterRowsUseUnnamedUnattributedSlots(string kind)
        {
            WithImage(kind, new[] { 1, 2 }, Array.Empty<ParameterRow>(), types =>
            {
                var parameters = Parameters(types).ToArray();
                Assert.Equal(2, parameters.Length);
                Assert.All(parameters, parameter =>
                {
                    Assert.Equal(string.Empty, parameter.Name);
                    Assert.Equal(ParameterAttributes.None, parameter.Attributes);
                });
                var findings = Pointers(types);
                Assert.Equal(new[] { 1, 2 }, findings.Select(finding => finding.ParameterSequence.Value));
                Assert.Equal(new[] { "Test.Callback*", "Test.Callback**" }, findings.Select(finding => finding.Type));
            });
        }

        [Theory]
        [InlineData("Delegate")]
        [InlineData("Class")]
        [InlineData("Interface")]
        public void SparseRowsPreservePositionsAndUnnamedOutputFlags(string kind)
        {
            WithImage(kind, new[] { 1, 1, 1, 1, 0 }, new[]
            {
                new ParameterRow(2, "Input", ParameterAttributes.In),
                new ParameterRow(4, "", ParameterAttributes.Out),
            }, types =>
            {
                var parameters = Parameters(types).ToArray();
                Assert.Equal(new[] { "", "Input", "", "", "" }, parameters.Select(parameter => parameter.Name));
                Assert.Equal(new[]
                {
                    ParameterAttributes.None, ParameterAttributes.In, ParameterAttributes.None,
                    ParameterAttributes.Out, ParameterAttributes.None,
                }, parameters.Select(parameter => parameter.Attributes));
                Assert.Equal(new[] { 1, 2, 3 }, Pointers(types).Select(finding => finding.ParameterSequence.Value));
            });
        }

        [Theory]
        [InlineData("Delegate")]
        [InlineData("Class")]
        [InlineData("Interface")]
        public void UnnamedOutputRowsNormalizeOnlyTheirOwnSinglePointerLayer(string kind)
        {
            WithImage(kind, new[] { 1, 2, 1 }, new[]
            {
                new ParameterRow(1, "", ParameterAttributes.Out),
                new ParameterRow(2, "", ParameterAttributes.In | ParameterAttributes.Out),
                new ParameterRow(3, "Input", ParameterAttributes.In),
            }, types =>
            {
                var parameters = Parameters(types).ToArray();
                Assert.Equal(ParameterAttributes.Out, parameters[0].Attributes);
                Assert.Equal(ParameterAttributes.In | ParameterAttributes.Out, parameters[1].Attributes);
                var findings = Pointers(types);
                Assert.Equal(new[] { 2, 3 }, findings.Select(finding => finding.ParameterSequence.Value));
                Assert.Equal(new[] { "", "Input" }, findings.Select(finding => finding.ParameterName));
                Assert.Equal(new[] { "Test.Callback**", "Test.Callback*" }, findings.Select(finding => finding.Type));
            });
        }

        [Theory]
        [InlineData("Delegate")]
        [InlineData("Class")]
        [InlineData("Interface")]
        public void NamedReturnRowsDoNotSupplyArgumentNamesOrOutputFlags(string kind)
        {
            WithImage(kind, new[] { 1 }, new[]
            {
                new ParameterRow(0, "Result", ParameterAttributes.Out),
            }, types =>
            {
                var parameter = Assert.Single(Parameters(types));
                Assert.Equal("", parameter.Name);
                Assert.Equal(ParameterAttributes.None, parameter.Attributes);
                var finding = Assert.Single(Pointers(types));
                Assert.Equal(1, finding.ParameterSequence);
                Assert.Equal("Test.Callback*", finding.Type);
            });
        }

        [Theory]
        [InlineData("Delegate")]
        [InlineData("Class")]
        [InlineData("Interface")]
        public void ReturnOnlyMetadataHasZeroArgumentArity(string kind)
        {
            WithImage(kind, Array.Empty<int>(), new[]
            {
                new ParameterRow(0, "Result", ParameterAttributes.Out),
            }, types =>
            {
                Assert.Empty(Parameters(types));
                Assert.Empty(Pointers(types));
                if (kind == "Delegate")
                {
                    Assert.Contains(DelegateValidator.FindEmptyDelegates(types, Array.Empty<string>()),
                        type => type.Name == "Owner");
                }
            });
        }

        [Theory]
        [InlineData("Delegate", 0)]
        [InlineData("Delegate", 1)]
        [InlineData("Class", 0)]
        [InlineData("Class", 1)]
        [InlineData("Interface", 0)]
        [InlineData("Interface", 1)]
        public void DuplicateSequencesFailExplicitlyIncludingReturnRows(string kind, int sequence)
        {
            var error = Assert.Throws<BadImageFormatException>(() => WithImage(kind, new[] { 1 }, new[]
            {
                new ParameterRow(sequence, "First", ParameterAttributes.In),
                new ParameterRow(sequence, "Second", ParameterAttributes.Out),
            }, types => Pointers(types)));
            Assert.Contains($"duplicate parameter sequence {sequence}", error.Message);
            Assert.Contains("0x06000002", error.Message);
        }

        [Theory]
        [InlineData("Delegate")]
        [InlineData("Class")]
        [InlineData("Interface")]
        public void SequencesBeyondSignatureArityFailExplicitly(string kind)
        {
            var error = Assert.Throws<BadImageFormatException>(() => WithImage(kind, new[] { 1 }, new[]
            {
                new ParameterRow(2, "BeyondArity", ParameterAttributes.Out),
            }, types => Pointers(types)));
            Assert.Contains("parameter sequence 2 exceeds signature arity 1", error.Message);
            Assert.Contains("0x06000002", error.Message);
        }

        private static DelegatePointerInfo[] Pointers(TypeInfo[] types) =>
            DelegateValidator.FindPointersToDelegates(types, Array.Empty<string>()).ToArray();

        private static IEnumerable<ParameterInfo> Parameters(TypeInfo[] types)
        {
            var owner = Assert.Single(types.Where(type => type.Name == "Owner"));
            return owner switch
            {
                DelegateTypeInfo callback => callback.Parameters,
                ClassInfo type => Assert.Single(type.Methods).Parameters,
                InterfaceInfo type => Assert.Single(type.Methods).Parameters,
                _ => throw new InvalidOperationException("Unexpected fixture owner."),
            };
        }

        private static void WithImage(string kind, int[] pointerDepths, ParameterRow[] rows, Action<TypeInfo[]> assert)
        {
            var metadata = new MetadataBuilder();
            metadata.AddModule(0, metadata.GetOrAddString("Fixture"), metadata.GetOrAddGuid(Guid.NewGuid()), default, default);
            metadata.AddAssembly(metadata.GetOrAddString("Fixture"), new Version(1, 0), default, default, 0, AssemblyHashAlgorithm.None);
            var system = metadata.AddAssemblyReference(
                metadata.GetOrAddString("System.Runtime"), new Version(10, 0), default, default, 0, default);
            var multicast = metadata.AddTypeReference(
                system, metadata.GetOrAddString("System"), metadata.GetOrAddString("MulticastDelegate"));
            var objectType = metadata.AddTypeReference(
                system, metadata.GetOrAddString("System"), metadata.GetOrAddString("Object"));
            metadata.AddTypeDefinition(TypeAttributes.NotPublic, default, metadata.GetOrAddString("<Module>"), default,
                MetadataTokens.FieldDefinitionHandle(1), MetadataTokens.MethodDefinitionHandle(1));
            var callback = metadata.AddTypeDefinition(
                TypeAttributes.Public | TypeAttributes.Sealed, metadata.GetOrAddString("Test"),
                metadata.GetOrAddString("Callback"), multicast,
                MetadataTokens.FieldDefinitionHandle(1), MetadataTokens.MethodDefinitionHandle(1));
            metadata.AddMethodDefinition(
                MethodAttributes.Public | MethodAttributes.Virtual | MethodAttributes.NewSlot,
                MethodImplAttributes.Runtime, metadata.GetOrAddString("Invoke"),
                metadata.GetOrAddBlob(new byte[] { 0x20, 0, 1 }), 0, MetadataTokens.ParameterHandle(1));

            var attributes = TypeAttributes.Public |
                (kind == "Delegate" ? TypeAttributes.Sealed : TypeAttributes.Abstract);
            if (kind == "Interface")
            {
                attributes |= TypeAttributes.Interface;
            }

            metadata.AddTypeDefinition(attributes, metadata.GetOrAddString("Test"), metadata.GetOrAddString("Owner"),
                kind == "Delegate" ? multicast : kind == "Class" ? objectType : default,
                MetadataTokens.FieldDefinitionHandle(1), MetadataTokens.MethodDefinitionHandle(2));
            var signature = new BlobBuilder();
            new BlobEncoder(signature).MethodSignature(isInstanceMethod: true).Parameters(pointerDepths.Length,
                result => result.Type().Int32(), parameters =>
                {
                    foreach (int depth in pointerDepths)
                    {
                        var parameter = parameters.AddParameter().Type();
                        for (int index = 0; index < depth; index++)
                        {
                            parameter = parameter.Pointer();
                        }

                        parameter.Type(callback, isValueType: false);
                    }
                });
            metadata.AddMethodDefinition(
                MethodAttributes.Public | MethodAttributes.Virtual | MethodAttributes.NewSlot |
                    (kind == "Delegate" ? 0 : MethodAttributes.Abstract),
                kind == "Delegate" ? MethodImplAttributes.Runtime : MethodImplAttributes.IL,
                metadata.GetOrAddString(kind == "Delegate" ? "Invoke" : "Method"),
                metadata.GetOrAddBlob(signature), 0, MetadataTokens.ParameterHandle(1));
            foreach (var row in rows)
            {
                metadata.AddParameter(row.Attributes, metadata.GetOrAddString(row.Name), row.Sequence);
            }

            var image = new BlobBuilder();
            new ManagedPEBuilder(
                new PEHeaderBuilder(imageCharacteristics: Characteristics.ExecutableImage | Characteristics.Dll),
                new MetadataRootBuilder(metadata), new BlobBuilder(), flags: CorFlags.ILOnly).Serialize(image);
            string path = Path.Combine(Path.GetTempPath(), $"{Guid.NewGuid():N}.winmd");
            try
            {
                File.WriteAllBytes(path, image.ToArray());
                using var reader = WinmdUtils.LoadFromFile(path, MetadataReaderOptions.None);
                assert(reader.GetTypes(new List<WinmdUtils> { reader }).ToArray());
            }
            finally
            {
                File.Delete(path);
            }
        }

        private sealed record ParameterRow(int Sequence, string Name, ParameterAttributes Attributes);
    }
}
