using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Reflection.Metadata;
using System.Reflection.Metadata.Ecma335;
using System.Reflection.PortableExecutable;
using ICSharpCode.Decompiler.TypeSystem;
using Xunit;

namespace MetadataUtils.Tests
{
    public class TypeDuplicateValidatorTests
    {
        [Fact]
        public void EquivalentDefinitionsCollideAcrossNamespacesWithoutNameDerivedAttributesPartitioningThem()
        {
            Check(f =>
            {
                foreach (string ns in new[] { "Z", "A" })
                {
                    var type = f.Type(ns);
                    f.Field(8);
                    f.Attribute(type, "NativeTypedef");
                    f.Attribute(type, "Documentation", ns + " docs");
                    f.Attribute(type, "NativeTypeName", ns + "::Handle");
                }
            }, types =>
            {
                var duplicate = Assert.Single(TypeDuplicateValidator.FindDuplicates(types));
                Assert.Equal("Handle", duplicate.Name);
                Assert.Equal(new[] { "A.Handle", "Z.Handle" }, duplicate.Owners);
                Assert.Equal(Architecture.All, duplicate.Architectures);
                Assert.Single(duplicate.Collisions);
                var reversed = Assert.Single(TypeDuplicateValidator.FindDuplicates(types.Reverse()));
                Assert.Equal(duplicate.Owners, reversed.Owners);
                Assert.Equal(duplicate.Collisions, reversed.Collisions);
            });
        }

        [Theory]
        [InlineData(8, 9)] // int32 / uint32
        [InlineData(4, 5)] // int8 / uint8
        [InlineData(6, 9)] // int16 / uint32 (the display signature provider aliases these)
        [InlineData(24, 25)] // native int / native uint
        public void StorageTypesAreNotMemberNames(byte first, byte second)
        {
            Check(f =>
            {
                f.Type("A");
                f.Field(first);
                f.Type("B");
                f.Field(second);
            }, NoDuplicates);
        }

        [Theory]
        [InlineData(0, 0, "First", "Second", false)]
        [InlineData(1, 1, "First", "Second", false)]
        [InlineData(1, 2, "First", "First", false)]
        [InlineData(1, 1, "First", "First", true)]
        public void ReferencedTypeNamespacesAndPointerDepthRemainSignificant(int firstDepth, int secondDepth, string firstNs, string secondNs, bool duplicate)
        {
            Check(f =>
            {
                foreach (string ns in new[] { "First", "Second" })
                {
                    f.Type(ns, "Pointee");
                    f.Field(8);
                }

                f.Type("A");
                f.ReferenceField(f.Reference(firstNs, "Pointee"), firstDepth);
                f.Type("B");
                f.ReferenceField(f.Reference(secondNs, "Pointee"), secondDepth);
            }, types => Assert.Equal(duplicate ? 1 : 0,
                TypeDuplicateValidator.FindDuplicates(types.Where(t => t.Name == "Handle")).Count));
        }

        [Fact]
        public void MixedThreeOwnerGroupReportsOnlyTheTwoMatchingDefinitions()
        {
            Check(f =>
            {
                f.Type("C");
                f.Field(9);
                f.Type("B");
                f.Field(8);
                f.Type("A");
                f.Field(8);
            }, types => Assert.Equal(new[] { "A.Handle", "B.Handle" },
                Assert.Single(TypeDuplicateValidator.FindDuplicates(types)).Owners));
        }

        [Theory]
        [InlineData("CloseFirst", "CloseSecond", false)]
        [InlineData("Close", "Close", true)]
        public void CleanupFunctionNamesAreSemantic(string first, string second, bool duplicate)
        {
            Check(f =>
            {
                var a = f.Type("A");
                f.Field(24);
                f.Attribute(a, "RAIIFree", first);
                var b = f.Type("B");
                f.Field(24);
                f.Attribute(b, "RAIIFree", second);
            }, types => Assert.Equal(duplicate ? 1 : 0, TypeDuplicateValidator.FindDuplicates(types).Count));
        }

        [Theory]
        [InlineData("first.dll", "Close", "second.dll", "Close", false)]
        [InlineData("first.dll", "Close", "first.dll", "OtherClose", false)]
        [InlineData("first.dll", "Close", "FIRST.DLL", "Close", true)]
        [InlineData("first.dll", "Close", null, null, true)]
        [InlineData(null, null, null, null, true)]
        [InlineData("", "Close", "other.dll", "Close", true)]
        [InlineData("first.dll", "", "other.dll", "Close", true)]
        public void SameNamedCleanupResolvesToNamespaceLocalNativeProviderNotOwnerName(
            string firstDll, string firstEntry, string secondDll, string secondEntry, bool duplicate)
        {
            Check(f =>
            {
                foreach (var item in new[] { ("A", firstDll, firstEntry), ("B", secondDll, secondEntry) })
                {
                    var type = f.Type(item.Item1);
                    f.Field(24);
                    f.Attribute(type, "RAIIFree", "Close");
                    if (item.Item2 != null)
                    {
                        f.Api(item.Item1, "Close", item.Item2, item.Item3);
                    }
                }
            }, types => Assert.Equal(duplicate ? 1 : 0, TypeDuplicateValidator.FindDuplicates(types).Count));
        }

        [Fact]
        public void AmbiguousCleanupProvidersAndUnrelatedImportsDoNotProveDistinctIdentity()
        {
            Check(f =>
            {
                foreach (string ns in new[] { "A", "B" })
                {
                    var type = f.Type(ns);
                    f.Field(24);
                    f.Attribute(type, "RAIIFree", "Close");
                }

                f.Api("A", "Close", "first.dll", "Close");
                f.Api("A", "Close", "other.dll", "Close");
                f.Api("B", "Close", "second.dll", "Close");
                f.Api("Other", "Close", "third.dll", "Close");
            }, types => Assert.Single(TypeDuplicateValidator.FindDuplicates(types)));
        }

        [Fact]
        public void ThreeOwnerProviderGroupReportsOnlyTheTwoMatchingNativeDomains()
        {
            Check(f =>
            {
                foreach (string ns in new[] { "A", "B", "C" })
                {
                    var type = f.Type(ns);
                    f.Field(24);
                    f.Attribute(type, "RAIIFree", "Close");
                    f.Api(ns, "Close", ns == "C" ? "other.dll" : "same.dll", "Close");
                }
            }, types => Assert.Equal(new[] { "A.Handle", "B.Handle" },
                Assert.Single(TypeDuplicateValidator.FindDuplicates(types)).Owners));
        }

        [Fact]
        public void UnknownProviderDoesNotHideCollisionsOrAssertThatKnownDistinctProvidersMatch()
        {
            Check(f =>
            {
                foreach (string ns in new[] { "A", "B", "C" })
                {
                    var type = f.Type(ns);
                    f.Field(24);
                    f.Attribute(type, "RAIIFree", "Close");
                    if (ns != "B")
                    {
                        f.Api(ns, "Close", ns + ".dll", "Close");
                    }
                }
            }, types =>
            {
                var duplicate = Assert.Single(TypeDuplicateValidator.FindDuplicates(types));
                Assert.Equal(new[] { "A.Handle", "B.Handle", "C.Handle" }, duplicate.Owners);
                Assert.Equal(new[]
                {
                    new DuplicateTypeCollision("A.Handle", "B.Handle", Architecture.All),
                    new DuplicateTypeCollision("B.Handle", "C.Handle", Architecture.All),
                }, duplicate.Collisions);
            });
        }

        [Fact]
        public void ProviderBindingUsesOnlyTheOverlappingArchitecture()
        {
            Check(f =>
            {
                foreach (string ns in new[] { "A", "B" })
                {
                    var type = f.Type(ns);
                    f.Field(24);
                    f.Attribute(type, "RAIIFree", "Close");
                }

                f.Attribute(f.Api("A", "Close", "same.dll", "Close"), "SupportedArchitecture", 2);
                f.Attribute(f.Api("A", "Close", "first.dll", "Close"), "SupportedArchitecture", 5);
                f.Attribute(f.Api("B", "Close", "same.dll", "Close"), "SupportedArchitecture", 2);
                f.Attribute(f.Api("B", "Close", "second.dll", "Close"), "SupportedArchitecture", 5);
            }, types => Assert.Equal(Architecture.X64,
                Assert.Single(TypeDuplicateValidator.FindDuplicates(types)).Architectures));
        }

        [Theory]
        [InlineData(1, 6, 0)]
        [InlineData(3, 6, 2)]
        [InlineData(7, 1, 1)]
        [InlineData(0, 7, 0)]
        public void PhysicalAvailabilityUsesOverlapNotExactArchitectureMask(int first, int second, int overlap)
        {
            Check(f =>
            {
                foreach (var item in new[] { ("A", first), ("B", second) })
                {
                    var type = f.Type(item.Item1);
                    f.Field(8);
                    f.Attribute(type, "SupportedArchitecture", item.Item2);
                }
            }, types =>
            {
                var result = TypeDuplicateValidator.FindDuplicates(types);
                if (overlap == 0)
                {
                    Assert.Empty(result);
                }
                else
                {
                    Assert.Equal((Architecture)overlap, Assert.Single(result).Architectures);
                }
            });
        }

        [Fact]
        public void SameOwnerPhysicalVariantsAreNotCollapsed()
        {
            Check(f =>
            {
                foreach (int mask in new[] { 1, 6, 2 })
                {
                    var type = f.Type("A");
                    f.Field(8);
                    f.Attribute(type, "SupportedArchitecture", mask);
                }
            }, types =>
            {
                var duplicate = Assert.Single(TypeDuplicateValidator.FindDuplicates(types));
                Assert.Equal(new[] { "A.Handle", "A.Handle" }, duplicate.Owners);
                Assert.Equal(Architecture.X64, duplicate.Architectures);
            });
        }

        [Fact]
        public void MemberAvailabilityIsComparedOnEachArchitecture()
        {
            Check(f =>
            {
                f.Type("A");
                f.Field(8);
                f.Attribute(f.Field(8, "Extra"), "SupportedArchitecture", 1);
                f.Type("B");
                f.Field(8);
            }, types => Assert.Equal(Architecture.X64 | Architecture.Arm64,
                Assert.Single(TypeDuplicateValidator.FindDuplicates(types)).Architectures));
        }

        [Fact]
        public void OverlapChainsPreserveTheActualCollidingPairs()
        {
            Check(f =>
            {
                foreach (var item in new[] { ("A", 1), ("B", 7), ("C", 2) })
                {
                    var type = f.Type(item.Item1);
                    f.Field(8);
                    f.Attribute(type, "SupportedArchitecture", item.Item2);
                }
            }, types =>
            {
                var duplicate = Assert.Single(TypeDuplicateValidator.FindDuplicates(types));
                Assert.Equal(new[]
                {
                    new DuplicateTypeCollision("A.Handle", "B.Handle", Architecture.X86),
                    new DuplicateTypeCollision("B.Handle", "C.Handle", Architecture.X64),
                }, duplicate.Collisions);
            });
        }

        [Theory]
        [InlineData("layout")]
        [InlineData("packing")]
        [InlineData("size")]
        [InlineData("offset")]
        [InlineData("static")]
        [InlineData("semantic")]
        [InlineData("marshal")]
        public void LayoutAndNativeSemanticPropertiesAreSignificant(string difference)
        {
            Check(f =>
            {
                for (int index = 0; index < 2; index++)
                {
                    var type = f.Type(index == 0 ? "A" : "B", layout:
                        difference == "layout" && index == 1 ? TypeAttributes.SequentialLayout : TypeAttributes.ExplicitLayout);
                    var field = f.Field(8, attributes: FieldAttributes.Public |
                        (difference == "static" && index == 1 ? FieldAttributes.Static : 0));
                    f.Metadata.AddFieldLayout(field, difference == "offset" ? index * 4 : 0);
                    f.Metadata.AddTypeLayout(type, (ushort)(difference == "packing" ? 1 << index : 1),
                        (uint)(difference == "size" ? 4 + index * 4 : 8));
                    if (difference == "semantic")
                    {
                        f.Attribute(type, "InvalidHandleValue", index);
                    }

                    if (difference == "marshal")
                    {
                        f.Metadata.AddMarshallingDescriptor(field, f.Metadata.GetOrAddBlob(new byte[] { (byte)(index == 0 ? 7 : 9) }));
                    }
                }
            }, NoDuplicates);
        }

        [Theory]
        [InlineData("Class", false)]
        [InlineData("Class", true)]
        [InlineData("Delegate", false)]
        [InlineData("Delegate", true)]
        [InlineData("Interface", false)]
        [InlineData("Interface", true)]
        public void OrdinaryMethodAndDelegateSignaturesAreCompared(string kind, bool same)
        {
            Check(f =>
            {
                f.Type("A", kind: kind);
                f.Method("Invoke", 8, 8);
                f.Type("B", kind: kind);
                f.Method("Invoke", 8, same ? (byte)8 : (byte)9);
            }, types => Assert.Equal(same ? 1 : 0, TypeDuplicateValidator.FindDuplicates(types).Count));
        }

        [Fact]
        public void MethodReturnTypesAreCompared()
        {
            Check(f =>
            {
                f.Type("A", kind: "Class");
                f.Method("Method", 8);
                f.Type("B", kind: "Class");
                f.Method("Method", 9);
            }, NoDuplicates);
        }

        [Theory]
        [InlineData(false)]
        [InlineData(true)]
        public void ParameterFlagsButNotParameterNamesAreSemantic(bool differentFlags)
        {
            Check(f =>
            {
                foreach (string ns in new[] { "A", "B" })
                {
                    f.Type(ns, kind: "Delegate");
                    f.Method("Invoke", 1, 24);
                    f.Metadata.AddParameter(differentFlags && ns == "B" ? ParameterAttributes.Out : ParameterAttributes.In,
                        f.Metadata.GetOrAddString(ns + "Parameter"), 1);
                }
            }, types => Assert.Equal(differentFlags ? 0 : 1, TypeDuplicateValidator.FindDuplicates(types).Count));
        }

        [Fact]
        public void FunctionPointerCallingConventionIsPartOfStorage()
        {
            Check(f =>
            {
                foreach (var item in new[] { ("A", (byte)1), ("B", (byte)2) })
                {
                    f.Type(item.Item1);
                    f.Metadata.AddFieldDefinition(FieldAttributes.Public, f.Metadata.GetOrAddString("Value"),
                        f.Metadata.GetOrAddBlob(new byte[] { 6, 0x1b, item.Item2, 0, 1 }));
                }
            }, NoDuplicates);
        }

        [Fact]
        public void SelfReferencesDoNotPartitionOtherwiseEquivalentTypesByOwnNamespace()
        {
            Check(f =>
            {
                foreach (string ns in new[] { "A", "B" })
                {
                    f.Type(ns);
                    f.ReferenceField(f.Reference(ns, "Handle"), 1);
                }
            }, types => Assert.Single(TypeDuplicateValidator.FindDuplicates(types)));
        }

        [Theory]
        [InlineData(1, true)]
        [InlineData(2, false)]
        public void EnumValuesAndUnderlyingStorageAreComparedWithoutOwnNamespacePartition(int secondValue, bool duplicate)
        {
            Check(f =>
            {
                foreach (var item in new[] { ("A", 1), ("B", secondValue) })
                {
                    var type = f.Type(item.Item1, kind: "Enum");
                    f.Field(8, "value__", FieldAttributes.Public | FieldAttributes.SpecialName | FieldAttributes.RTSpecialName);
                    var field = f.ReferenceField(type, 0, "One",
                        FieldAttributes.Public | FieldAttributes.Static | FieldAttributes.Literal);
                    f.Metadata.AddConstant(field, item.Item2);
                }
            }, types => Assert.Equal(duplicate ? 1 : 0, TypeDuplicateValidator.FindDuplicates(types).Count));
        }

        [Theory]
        [InlineData("attribute")]
        [InlineData("field")]
        [InlineData("method")]
        public void UndecodableMetadataFailsExplicitlyInsteadOfDroppingSemanticEvidence(string malformed)
        {
            Check(f =>
            {
                var type = f.Type("A");
                if (malformed == "field")
                {
                    f.Metadata.AddFieldDefinition(FieldAttributes.Public, f.Metadata.GetOrAddString("Value"),
                        f.Metadata.GetOrAddBlob(new byte[] { 6, 255 }));
                }
                else
                {
                    f.Field(8);
                }

                if (malformed == "attribute")
                {
                    f.Attribute(type, "RAIIFree", "Close", malformed: true);
                }
                else if (malformed == "method")
                {
                    f.Metadata.AddMethodDefinition(MethodAttributes.Public, MethodImplAttributes.Runtime,
                        f.Metadata.GetOrAddString("Method"), f.Metadata.GetOrAddBlob(new byte[] { 0x20, 1 }),
                        0, MetadataTokens.ParameterHandle(1));
                }

                f.Type("B");
                f.Field(8);
            }, types => Assert.Throws<BadImageFormatException>(() => TypeDuplicateValidator.FindDuplicates(types)));
        }

        private static void NoDuplicates(ITypeDefinition[] types) => Assert.Empty(TypeDuplicateValidator.FindDuplicates(types));

        private static void Check(Action<Fixture> configure, Action<ITypeDefinition[]> assert)
        {
            var fixture = new Fixture();
            configure(fixture);
            var image = new BlobBuilder();
            new ManagedPEBuilder(
                new PEHeaderBuilder(imageCharacteristics: Characteristics.ExecutableImage | Characteristics.Dll),
                new MetadataRootBuilder(fixture.Metadata), new BlobBuilder(), flags: CorFlags.ILOnly).Serialize(image);
            string path = Path.GetFullPath($"duplicate-type-{Guid.NewGuid():N}.winmd");
            try
            {
                File.WriteAllBytes(path, image.ToArray());
                var system = DecompilerTypeSystemUtils.CreateTypeSystemFromFile(path);
                using (system.MainModule.PEFile)
                {
                    assert(system.MainModule.TopLevelTypeDefinitions.Where(t => t.Name != "<Module>").ToArray());
                }
            }
            finally
            {
                File.Delete(path);
            }
        }

        private sealed class Fixture
        {
            private readonly AssemblyReferenceHandle system;
            private readonly AssemblyReferenceHandle contracts;
            internal MetadataBuilder Metadata { get; } = new();

            internal Fixture()
            {
                Metadata.AddModule(0, Metadata.GetOrAddString("Fixture"), Metadata.GetOrAddGuid(Guid.NewGuid()), default, default);
                Metadata.AddAssembly(Metadata.GetOrAddString("Fixture"), new Version(1, 0), default, default, 0, AssemblyHashAlgorithm.None);
                system = Metadata.AddAssemblyReference(Metadata.GetOrAddString("System.Runtime"), new Version(10, 0), default, default, 0, default);
                contracts = Metadata.AddAssemblyReference(Metadata.GetOrAddString("Attribute.Contracts"), new Version(1, 0), default, default, 0, default);
                Metadata.AddTypeDefinition(TypeAttributes.NotPublic, default, Metadata.GetOrAddString("<Module>"), default,
                    MetadataTokens.FieldDefinitionHandle(1), MetadataTokens.MethodDefinitionHandle(1));
            }

            internal TypeDefinitionHandle Type(string ns, string name = "Handle",
                TypeAttributes layout = TypeAttributes.SequentialLayout, string kind = "Struct")
            {
                string baseName = kind switch { "Struct" => "ValueType", "Delegate" => "MulticastDelegate", "Enum" => "Enum", _ => "Object" };
                var baseType = Metadata.AddTypeReference(system, Metadata.GetOrAddString("System"), Metadata.GetOrAddString(baseName));
                return Metadata.AddTypeDefinition(TypeAttributes.Public | layout |
                    (kind == "Interface" ? TypeAttributes.Interface | TypeAttributes.Abstract : TypeAttributes.Sealed),
                    Metadata.GetOrAddString(ns), Metadata.GetOrAddString(name), kind == "Interface" ? default : baseType,
                    MetadataTokens.FieldDefinitionHandle(Metadata.GetRowCount(TableIndex.Field) + 1),
                    MetadataTokens.MethodDefinitionHandle(Metadata.GetRowCount(TableIndex.MethodDef) + 1));
            }

            internal TypeReferenceHandle Reference(string ns, string name) => Metadata.AddTypeReference(
                MetadataTokens.EntityHandle(0x00000001), Metadata.GetOrAddString(ns), Metadata.GetOrAddString(name));

            internal FieldDefinitionHandle Field(byte primitive, string name = "Value", FieldAttributes attributes = FieldAttributes.Public)
                => Metadata.AddFieldDefinition(attributes, Metadata.GetOrAddString(name), Metadata.GetOrAddBlob(new byte[] { 6, primitive }));

            internal FieldDefinitionHandle ReferenceField(EntityHandle reference, int depth, string name = "Value",
                FieldAttributes attributes = FieldAttributes.Public)
            {
                var blob = new BlobBuilder();
                var type = new BlobEncoder(blob).FieldSignature();
                for (int index = 0; index < depth; index++)
                {
                    type = type.Pointer();
                }

                type.Type(reference, isValueType: true);
                return Metadata.AddFieldDefinition(attributes, Metadata.GetOrAddString(name), Metadata.GetOrAddBlob(blob));
            }

            internal MethodDefinitionHandle Method(string name, byte returnType, params byte[] parameters)
                => Metadata.AddMethodDefinition(MethodAttributes.Public | MethodAttributes.Virtual | MethodAttributes.NewSlot,
                    MethodImplAttributes.Runtime, Metadata.GetOrAddString(name),
                    Metadata.GetOrAddBlob(new byte[] { 0x20, (byte)parameters.Length, returnType }.Concat(parameters).ToArray()),
                    0, MetadataTokens.ParameterHandle(Metadata.GetRowCount(TableIndex.Param) + 1));

            internal MethodDefinitionHandle Api(string ns, string name, string dll, string entryPoint)
            {
                Type(ns, "Apis", kind: "Class");
                var method = Metadata.AddMethodDefinition(MethodAttributes.Public | MethodAttributes.Static | MethodAttributes.PinvokeImpl,
                    MethodImplAttributes.PreserveSig, Metadata.GetOrAddString(name),
                    Metadata.GetOrAddBlob(new byte[] { 0, 1, 1, 24 }), 0,
                    MetadataTokens.ParameterHandle(Metadata.GetRowCount(TableIndex.Param) + 1));
                Metadata.AddMethodImport(method, MethodImportAttributes.CallingConventionWinApi,
                    Metadata.GetOrAddString(entryPoint), Metadata.AddModuleReference(Metadata.GetOrAddString(dll)));
                return method;
            }

            internal void Attribute(EntityHandle owner, string name, object argument = null, bool malformed = false)
            {
                var type = Metadata.AddTypeReference(contracts, Metadata.GetOrAddString("Windows.Win32.Foundation.Metadata"),
                    Metadata.GetOrAddString(name + "Attribute"));
                var signature = argument == null ? new byte[] { 0x20, 0, 1 } :
                    new byte[] { 0x20, 1, 1, argument is string ? (byte)14 : (byte)8 };
                var ctor = Metadata.AddMemberReference(type, Metadata.GetOrAddString(".ctor"), Metadata.GetOrAddBlob(signature));
                var value = new BlobBuilder();
                value.WriteUInt16(malformed ? (ushort)0 : (ushort)1);
                if (argument is string text)
                {
                    value.WriteSerializedString(text);
                }
                else if (argument is int number)
                {
                    value.WriteInt32(number);
                }

                value.WriteUInt16(0);
                Metadata.AddCustomAttribute(owner, ctor, Metadata.GetOrAddBlob(value));
            }
        }
    }
}
