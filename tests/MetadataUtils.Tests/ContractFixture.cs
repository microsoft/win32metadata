using System;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Reflection.Metadata;
using System.Reflection.Metadata.Ecma335;
using System.Reflection.PortableExecutable;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Xunit;

namespace MetadataUtils.Tests
{
    internal static class ContractFixture
    {
        internal const string Source = @"
using System;
using System.Runtime.InteropServices;
using Windows.Win32.Foundation.Metadata;

namespace Windows.Win32.Foundation.Metadata
{
    [AttributeUsage(AttributeTargets.All, AllowMultiple = true)]
    public sealed class AssociatedEnumAttribute : Attribute { public AssociatedEnumAttribute(string name) {} }
    public sealed class MemorySizeAttribute : Attribute { public short BytesParamIndex; }
    public sealed class NativeArrayInfoAttribute : Attribute { public short CountParamIndex; }
    public sealed class NativeTypeNameAttribute : Attribute { public NativeTypeNameAttribute(string name) {} }
    public sealed class RAIIFreeAttribute : Attribute { public RAIIFreeAttribute(string name) {} }
    public sealed class SupportedOSPlatformAttribute : Attribute { public SupportedOSPlatformAttribute(string name) {} }
    [AttributeUsage(AttributeTargets.All, AllowMultiple = true)]
    public sealed class ValuesAttribute : Attribute
    {
        public ValuesAttribute(sbyte signed, ushort unsigned, object boxed, Type type, Register enumeration) {}
        public int[] Numbers;
        public string Text { get; set; }
        public Type[] Types;
        public object[] Objects;
    }
    public enum Register : uint { Zero, Max = uint.MaxValue }
}
namespace Demo
{
    public enum REGISTER_NOTIFICATION_FLAGS : uint { None = 0, Max = uint.MaxValue }
    [RAIIFree(""Release"")]
    public struct Handle { public IntPtr Value; }
    public struct Unused { public int NeverSelected; }
    [StructLayout(LayoutKind.Explicit, Pack = 2, Size = 64)]
    public unsafe struct Buffer
    {
        [FieldOffset(0)] public short Signed;
        [FieldOffset(2)] public sbyte Tiny;
        [FieldOffset(4)] public volatile int Modified;
        [FieldOffset(8)] public Inner Nested;
        [FieldOffset(16), MarshalAs(UnmanagedType.ByValArray, SizeConst = 3, ArraySubType = UnmanagedType.U2)]
        public ushort[] Values;
        [FieldOffset(24)] public delegate* unmanaged[Cdecl]<short, sbyte*, uint> Callback;
        [FieldOffset(32)] public int[,] Matrix;
        public struct Inner { public Handle Handle; }
    }
    public static unsafe class Apis
    {
        [SupportedOSPlatform(""windows8.0"")]
        [Values(-2, 65535, (byte)7, typeof(Buffer), Register.Max, Numbers = new[] { 3, 1 },
            Text = null, Types = new[] { typeof(Handle), typeof(int) }, Objects = new object[] { ""x"", 8 })]
        [DllImport(""POWRPROF.dll"", EntryPoint = ""NativeCall"", ExactSpelling = true, SetLastError = true,
            CallingConvention = CallingConvention.StdCall, CharSet = CharSet.Unicode, BestFitMapping = false,
            ThrowOnUnmappableChar = true)]
        [return: NativeTypeName(""DWORD"")]
        public static extern uint Call(
            [In, Optional, MemorySize(BytesParamIndex = 2), AssociatedEnum(""REGISTER_NOTIFICATION_FLAGS""),
             AssociatedEnum(""REGISTER_NOTIFICATION_FLAGS""), NativeTypeName(""DWORD"")] uint flags,
            Handle** buffer,
            [In, Out, MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 0, SizeConst = 2, ArraySubType = UnmanagedType.U1)] byte[] bytes);
        public static void Ignore(Unused unused) {}
        public const ulong Huge = ulong.MaxValue;
        public const short Signed = -3;
        public const char Character = '\uffff';
        public const float NegativeZero = -0.0f;
    }
    public interface IFirst { void Z(); void A(); }
    public class Generic<T> : IFirst where T : class, new()
    {
        public T Value;
        public Generic<T> Recursive;
        public U Convert<U>(T value) where U : IDisposable { return default(U); }
        public ref readonly int RefReturn(ref int value) => ref value;
        public int Property { get; set; }
        public event Action Event;
        void IFirst.Z() {}
        void IFirst.A() {}
    }
}";

        internal static byte[] Compile(string source = Source)
        {
            var compilation = CSharpCompilation.Create("ContractFixture",
                new[] { CSharpSyntaxTree.ParseText(source, new CSharpParseOptions(LanguageVersion.CSharp9)) },
                new[] { MetadataReference.CreateFromFile(typeof(object).Assembly.Location) },
                new CSharpCompilationOptions(OutputKind.DynamicallyLinkedLibrary, allowUnsafe: true,
                    optimizationLevel: OptimizationLevel.Release, deterministic: true));
            using var stream = new MemoryStream();
            var emit = compilation.Emit(stream);
            Assert.True(emit.Success, string.Join(Environment.NewLine, emit.Diagnostics));
            return stream.ToArray();
        }

        internal static byte[] Build(Action<MetadataBuilder, FixtureHandles> customize = null, bool relocateTokens = false, int variants = 1)
        {
            var metadata = new MetadataBuilder();
            metadata.AddModule(0, metadata.GetOrAddString("ContractFixture.dll"), metadata.GetOrAddGuid(Guid.NewGuid()), default, default);
            metadata.AddAssembly(metadata.GetOrAddString("ContractFixture"), new Version(1, 0, 0, 0), default, default, 0, AssemblyHashAlgorithm.None);
            var assembly = metadata.AddAssemblyReference(metadata.GetOrAddString("mscorlib"), new Version(4, 0, 0, 0), default, default, 0, default);
            if (relocateTokens)
            {
                metadata.AddTypeReference(assembly, metadata.GetOrAddString("Ignored"), metadata.GetOrAddString("Unused"));
            }

            var objectType = metadata.AddTypeReference(assembly, metadata.GetOrAddString("System"), metadata.GetOrAddString("Object"));
            var tagType = metadata.AddTypeReference(assembly, metadata.GetOrAddString("Demo"), metadata.GetOrAddString("TagAttribute"));
            var tagConstructor = metadata.AddMemberReference(tagType, metadata.GetOrAddString(".ctor"), metadata.GetOrAddBlob(new byte[] { 0x20, 1, 1, 8 }));
            var module = metadata.AddModuleReference(metadata.GetOrAddString("Exact.DLL"));
            metadata.AddTypeDefinition(TypeAttributes.NotPublic, default, metadata.GetOrAddString("<Module>"), default,
                MetadataTokens.FieldDefinitionHandle(1), MetadataTokens.MethodDefinitionHandle(1));
            if (relocateTokens)
            {
                metadata.AddTypeDefinition(TypeAttributes.Public, metadata.GetOrAddString("Ignored"), metadata.GetOrAddString("Unused"),
                    objectType, MetadataTokens.FieldDefinitionHandle(1), MetadataTokens.MethodDefinitionHandle(1));
                metadata.AddMethodDefinition(MethodAttributes.Public | MethodAttributes.Static, MethodImplAttributes.Runtime,
                    metadata.GetOrAddString("Unused"), metadata.GetOrAddBlob(new byte[] { 0, 0, 1 }), 0, MetadataTokens.ParameterHandle(1));
                metadata.AddParameter(ParameterAttributes.None, default, 0);
            }

            for (int i = 0; i < variants; i++)
            {
                int firstMethod = metadata.GetRowCount(TableIndex.MethodDef) + 1;
                int firstParameter = metadata.GetRowCount(TableIndex.Param) + 1;
                var type = metadata.AddTypeDefinition(TypeAttributes.Public | TypeAttributes.Abstract | TypeAttributes.Sealed,
                    metadata.GetOrAddString("Demo"), metadata.GetOrAddString("Apis"), objectType,
                    MetadataTokens.FieldDefinitionHandle(1), MetadataTokens.MethodDefinitionHandle(firstMethod));
                var signature = new BlobBuilder();
                new BlobEncoder(signature).MethodSignature().Parameters(1, r => r.Type().UInt32(),
                    p => p.AddParameter().Type().Type(objectType, isValueType: false));
                var method = metadata.AddMethodDefinition(MethodAttributes.Public | MethodAttributes.Static | MethodAttributes.PinvokeImpl,
                    MethodImplAttributes.PreserveSig, metadata.GetOrAddString("Call"), metadata.GetOrAddBlob(signature), 0,
                    MetadataTokens.ParameterHandle(firstParameter));
                metadata.AddMethodImport(method, MethodImportAttributes.ExactSpelling | MethodImportAttributes.SetLastError |
                    MethodImportAttributes.CallingConventionStdCall, metadata.GetOrAddString("CallNative"), module);
                var returnParameter = metadata.AddParameter(ParameterAttributes.Retval, default, 0);
                var parameter = metadata.AddParameter(ParameterAttributes.In | ParameterAttributes.Optional, metadata.GetOrAddString("value"), 1);
                metadata.AddCustomAttribute(type, tagConstructor, metadata.GetOrAddBlob(AttributeBlob(i)));
                var handles = new FixtureHandles { Type = type, Method = method, Return = returnParameter, Parameter = parameter, TagConstructor = tagConstructor };
                customize?.Invoke(metadata, handles);
                if (variants > 1)
                {
                    metadata.AddMethodDefinition(MethodAttributes.Public | MethodAttributes.Static | MethodAttributes.PinvokeImpl,
                        MethodImplAttributes.PreserveSig, metadata.GetOrAddString("Call"),
                        metadata.GetOrAddBlob(new byte[] { 0, 0, 1 }), 0, MetadataTokens.ParameterHandle(firstParameter + 2));
                }
            }

            var pe = new ManagedPEBuilder(PEHeaderBuilder.CreateLibraryHeader(), new MetadataRootBuilder(metadata), new BlobBuilder(),
                flags: CorFlags.ILOnly);
            var image = new BlobBuilder();
            pe.Serialize(image);
            return image.ToArray();
        }

        internal static byte[] AttributeBlob(int argument = 1, Action<BlobBuilder> suffix = null)
        {
            var blob = new BlobBuilder();
            blob.WriteUInt16(1);
            blob.WriteInt32(argument);
            if (suffix == null)
            {
                blob.WriteUInt16(0);
            }
            else
            {
                suffix(blob);
            }

            return blob.ToArray();
        }

        internal sealed class FixtureHandles
        {
            internal TypeDefinitionHandle Type;
            internal MethodDefinitionHandle Method;
            internal ParameterHandle Return;
            internal ParameterHandle Parameter;
            internal MemberReferenceHandle TagConstructor;
        }
    }
}
