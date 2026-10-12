using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Reflection.Metadata;
using System.Reflection.PortableExecutable;
using MetadataUtils;
using TestCommon;
using Xunit;

namespace Windows.Win32.Tests
{
    public class CallbackContractTests
    {
        private const string Foundation = "Windows.Win32.Foundation.";
        private const string Identity = "Windows.Win32.Security.Authentication.Identity.";
        private const string Services = "Windows.Win32.System.SystemServices.";
        private const string Programming = "Windows.Win32.System.WindowsProgramming.";
        private const string InternetExplorer = "Windows.Win32.Web.InternetExplorer.";
        private const string Audio = "Windows.Win32.Media.Audio.";
        private const string Rras = "Windows.Win32.NetworkManagement.Rras.";
        private const string WinInet = "Windows.Win32.Networking.WinInet.";
        private const string Installer = "Windows.Win32.System.ApplicationInstallationAndServicing.";
        private const string Rpc = "Windows.Win32.System.Rpc.";
        private const string Const = " modreq(System.Runtime.CompilerServices.IsConst)";

        private static readonly RawSignatureProvider Provider = new RawSignatureProvider();

        // These are exact native contracts, not a waiver for all zero-argument delegates.
        // Sources: winsplp.h, NTSecPKG.h, memoryapi.h, TimeProv.h and IEProcess.h.
        private static readonly IReadOnlyDictionary<string, CallbackSignature> ParameterlessCallbacks =
            new Dictionary<string, CallbackSignature>(StringComparer.Ordinal)
            {
                ["Windows.Win32.Graphics.Printing.PRINTPROVIDOR_fpCanShutdown"] = Signature("Int32", 2),
                [Identity + "LSA_IMPERSONATE_CLIENT"] = Signature(Programming + "NTSTATUS", 1),
                [Identity + "LSA_UNLOAD_PACKAGE"] = Signature(Programming + "NTSTATUS", 1),
                ["Windows.Win32.System.Memory.BAD_MEMORY_CALLBACK_ROUTINE"] = Signature("Void", 1),
                ["Windows.Win32.System.Time.AlertSamplesAvailFunc"] = Signature("Windows.Foundation.HResult", 1),
                [InternetExplorer + "IE80TabWindowExports_TLSFreeImmutableTabData"] = Signature("Void", 1),
                [InternetExplorer + "IE80TabWindowExports_TLSGetImmutableTabData"] =
                    Signature(InternetExplorer + "TLS_IMMUTABLE_TABDATA*", 1),
                [InternetExplorer + "IEGetProcessModule_t"] = Signature(Foundation + "HMODULE", 2),
                // IEProcess.h declares this unadorned function pointer as cdecl, not WINAPI.
                [InternetExplorer + "IEGetTabWindowExports_t"] =
                    Signature(InternetExplorer + "IE80TabWindowExports*" + Const, 2),
            };

        // Preserve the complete target signature as well as the extra field pointer.
        // Sources: MSAcm.h, RtmV2.h, WinInet.h, Msi.h, rpcdcep.h and NTSecPKG.h.
        private static readonly IReadOnlyDictionary<string, CallbackSignature> CallbackSignatures =
            new Dictionary<string, CallbackSignature>(StringComparer.Ordinal)
            {
                [Audio + "ACMDRIVERPROC"] = Signature(Foundation + "LRESULT", 1,
                    "UIntPtr", Audio + "HACMDRIVERID", "UInt32", Foundation + "LPARAM", Foundation + "LPARAM"),
                [Rras + "_ENTITY_METHOD"] = Signature("Void", 1,
                    Rras + "RTM_ENTITY_HANDLE", Rras + "RTM_ENTITY_HANDLE",
                    Rras + "RTM_ENTITY_METHOD_INPUT*", Rras + "RTM_ENTITY_METHOD_OUTPUT*"),
                [Rras + "_EVENT_CALLBACK"] = Signature("UInt32", 1,
                    Rras + "RTM_ENTITY_HANDLE", Rras + "RTM_EVENT_TYPE", Services + "PVOID", Services + "PVOID"),
                [WinInet + "INTERNET_STATUS_CALLBACK"] = Signature("Void", 1,
                    WinInet + "HINTERNET", "UIntPtr", "UInt32", Foundation + "LPVOID", "UInt32"),
                [Installer + "INSTALLUI_HANDLER_RECORD"] = Signature("Int32", 1,
                    Foundation + "LPVOID", "UInt32", Installer + "MSIHANDLE"),
                [Rpc + "RPC_DISPATCH_FUNCTION"] = Signature("Void", 1, Rpc + "PRPC_MESSAGE"),
                [Identity + "PLSA_REDIRECTED_LOGON_CALLBACK"] = Signature(Programming + "NTSTATUS", 1,
                    Services + "HANDLE", Services + "PVOID", "UInt32", Services + "PVOID*", "UInt32*"),
                [Identity + "PLSA_REDIRECTED_LOGON_CLEANUP_CALLBACK"] = Signature("Void", 1, Services + "HANDLE"),
                [Identity + "SpGetRemoteCredGuardLogonBufferFn"] = Signature(Programming + "NTSTATUS", 1,
                    Identity + "LSA_SEC_HANDLE", Identity + "LSA_SEC_HANDLE", Programming + "UNICODE_STRING*" + Const,
                    Services + "PHANDLE", Identity + "PLSA_REDIRECTED_LOGON_CALLBACK*",
                    Identity + "PLSA_REDIRECTED_LOGON_CLEANUP_CALLBACK*", Foundation + "PULONG", Services + "PVOID*"),
                [Identity + "SpGetRemoteCredGuardSupplementalCredsFn"] = Signature(Programming + "NTSTATUS", 1,
                    Identity + "LSA_SEC_HANDLE", Programming + "UNICODE_STRING*" + Const,
                    Services + "PHANDLE", Identity + "PLSA_REDIRECTED_LOGON_CALLBACK*",
                    Identity + "PLSA_REDIRECTED_LOGON_CLEANUP_CALLBACK*", Foundation + "PULONG", Services + "PVOID*"),
            };

        private static readonly IReadOnlyDictionary<string, FieldContract> Fields =
            new Dictionary<string, FieldContract>(StringComparer.Ordinal)
            {
                [Audio + "LPACMDRIVERPROC.Value"] = new FieldContract(Audio + "ACMDRIVERPROC", 1),
                [Rras + "PRTM_ENTITY_EXPORT_METHOD.Value"] = new FieldContract(Rras + "_ENTITY_METHOD", 1),
                [Rras + "PRTM_EVENT_CALLBACK.Value"] = new FieldContract(Rras + "_EVENT_CALLBACK", 1),
                [WinInet + "LPINTERNET_STATUS_CALLBACK.Value"] = new FieldContract(WinInet + "INTERNET_STATUS_CALLBACK", 1),
                [Installer + "PINSTALLUI_HANDLER_RECORD.Value"] = new FieldContract(Installer + "INSTALLUI_HANDLER_RECORD", 1),
                [Rpc + "RPC_DISPATCH_TABLE.DispatchTable"] = new FieldContract(Rpc + "RPC_DISPATCH_FUNCTION", 1),
                [Identity + "SECPKG_REDIRECTED_LOGON_BUFFER.Callback"] =
                    new FieldContract(Identity + "PLSA_REDIRECTED_LOGON_CALLBACK", 0),
                [Identity + "SECPKG_REDIRECTED_LOGON_BUFFER.CleanupCallback"] =
                    new FieldContract(Identity + "PLSA_REDIRECTED_LOGON_CLEANUP_CALLBACK", 0),
                // Neighboring direct-delegate field controls from NTSecPKG.h.
                [Identity + "SECPKG_REDIRECTED_LOGON_BUFFER.Init"] =
                    new FieldContract(Identity + "PLSA_REDIRECTED_LOGON_INIT", 0),
                [Identity + "SECPKG_REDIRECTED_LOGON_BUFFER.GetLogonCreds"] =
                    new FieldContract(Identity + "PLSA_REDIRECTED_LOGON_GET_LOGON_CREDS", 0),
                [Identity + "SECPKG_REDIRECTED_LOGON_BUFFER.GetSupplementalCreds"] =
                    new FieldContract(Identity + "PLSA_REDIRECTED_LOGON_GET_SUPP_CREDS", 0),
                [Identity + "SECPKG_REDIRECTED_LOGON_BUFFER.GetRedirectedLogonSid"] =
                    new FieldContract(Identity + "PLSA_REDIRECTED_LOGON_GET_SID", 0),
            };

        private static readonly IReadOnlyDictionary<string, OutputContract> Outputs =
            new Dictionary<string, OutputContract>(StringComparer.Ordinal)
            {
                [Identity + "SpGetRemoteCredGuardLogonBufferFn.Callback"] =
                    new OutputContract(5, Identity + "PLSA_REDIRECTED_LOGON_CALLBACK"),
                [Identity + "SpGetRemoteCredGuardLogonBufferFn.CleanupCallback"] =
                    new OutputContract(6, Identity + "PLSA_REDIRECTED_LOGON_CLEANUP_CALLBACK"),
                [Identity + "SpGetRemoteCredGuardSupplementalCredsFn.Callback"] =
                    new OutputContract(4, Identity + "PLSA_REDIRECTED_LOGON_CALLBACK"),
                [Identity + "SpGetRemoteCredGuardSupplementalCredsFn.CleanupCallback"] =
                    new OutputContract(5, Identity + "PLSA_REDIRECTED_LOGON_CLEANUP_CALLBACK"),
            };

        public static IEnumerable<object[]> NativeContracts =>
            ParameterlessCallbacks.Keys.Concat(Fields.Keys).Concat(Outputs.Keys)
                .Select(name => new object[] { name });

        [Theory]
        [MemberData(nameof(NativeContracts))]
        public void CallbackMatchesNativeContract(string contractName) =>
            AssertNativeContract(TestUtils.Win32WinmdPath, contractName);

        // An explicit image/reader lets forensic runs exercise the same assertions without
        // replacing the normal build output or projecting synthetic delegate constructors.
        internal static void AssertNativeContract(string imagePath, string contractName)
        {
            using var stream = File.OpenRead(imagePath);
            using var image = new PEReader(stream);
            AssertNativeContract(image.GetMetadataReader(MetadataReaderOptions.None), contractName);
        }

        internal static void AssertNativeContract(MetadataReader reader, string contractName)
        {
            Assert.Equal(MetadataReaderOptions.None, reader.Options);
            if (ParameterlessCallbacks.TryGetValue(contractName, out var callback))
            {
                AssertCallback(reader, contractName, callback);
                return;
            }

            int separator = contractName.LastIndexOf('.');
            string owner = contractName.Substring(0, separator);
            string member = contractName.Substring(separator + 1);
            if (Fields.TryGetValue(contractName, out var fieldContract))
            {
                AssertTargetCallback(reader, fieldContract.Target);
                foreach (var definition in GetDefinitions(reader, owner))
                {
                    var field = Assert.Single(definition.GetFields().Select(reader.GetFieldDefinition)
                        .Where(candidate => reader.GetString(candidate.Name) == member));
                    AssertCallbackDepth(contractName, fieldContract.Target, fieldContract.ExtraPointers,
                        field.DecodeSignature(Provider, null));
                }

                return;
            }

            Assert.True(Outputs.TryGetValue(contractName, out var output), $"Unknown callback contract: {contractName}");
            AssertTargetCallback(reader, output.Target);
            foreach (var definition in GetDefinitions(reader, owner))
            {
                var invoke = GetInvoke(reader, definition);
                var signature = invoke.DecodeSignature(Provider, null);
                var parameter = Assert.Single(invoke.GetParameters().Select(reader.GetParameter)
                    .Where(candidate => candidate.SequenceNumber == output.Sequence));
                Assert.Equal(member, reader.GetString(parameter.Name));
                Assert.Equal(ParameterAttributes.Out, parameter.Attributes);
                Assert.True(signature.ParameterTypes.Length >= output.Sequence, $"{contractName}: missing signature slot.");
                // Check this slot first so CleanupCallback has its own independently failing regression.
                AssertCallbackDepth(contractName, output.Target, 1, signature.ParameterTypes[output.Sequence - 1]);
                AssertSignature(reader, definition, CallbackSignatures[owner]);
            }
        }

        private static void AssertCallbackDepth(string site, string target, int extraPointers, string actual)
        {
            string expected = target + new string('*', extraPointers);
            // A named delegate already represents the first native function pointer.
            Assert.True(expected == actual,
                $"{site}: expected {expected} (native pointer depth {1 + extraPointers}), " +
                $"found {actual} (native pointer depth {1 + actual.Count(character => character == '*')}).");
        }

        private static void AssertTargetCallback(MetadataReader reader, string target)
        {
            if (CallbackSignatures.TryGetValue(target, out var signature))
            {
                AssertCallback(reader, target, signature);
            }
            else
            {
                // The adjacent controls pin direct-delegate field identity, not unsealed delegate bodies.
                foreach (var definition in GetDefinitions(reader, target))
                {
                    GetInvoke(reader, definition);
                }
            }
        }

        private static void AssertCallback(MetadataReader reader, string name, CallbackSignature expected)
        {
            foreach (var definition in GetDefinitions(reader, name))
            {
                AssertSignature(reader, definition, expected);
            }
        }

        private static void AssertSignature(MetadataReader reader, TypeDefinition definition, CallbackSignature expected)
        {
            var invoke = GetInvoke(reader, definition);
            var signature = invoke.DecodeSignature(Provider, null);
            Assert.Equal(expected.ReturnType, signature.ReturnType);
            Assert.Equal(expected.Parameters, signature.ParameterTypes.ToArray());
            Assert.Equal(expected.Parameters.Length, signature.RequiredParameterCount);
            Assert.Equal(0, signature.GenericParameterCount);
            Assert.Equal(SignatureCallingConvention.Default, signature.Header.CallingConvention);

            var parameters = invoke.GetParameters().Select(reader.GetParameter)
                .Where(parameter => parameter.SequenceNumber > 0).OrderBy(parameter => parameter.SequenceNumber).ToArray();
            Assert.Equal(Enumerable.Range(1, expected.Parameters.Length), parameters.Select(parameter => parameter.SequenceNumber));

            var conventionAttribute = Assert.Single(definition.GetCustomAttributes().Select(reader.GetCustomAttribute)
                .Where(attribute => GetAttributeType(reader, attribute) ==
                    "System.Runtime.InteropServices.UnmanagedFunctionPointerAttribute"));
            var blob = reader.GetBlobReader(conventionAttribute.Value);
            Assert.Equal((ushort)1, blob.ReadUInt16());
            Assert.Equal(expected.Convention, blob.ReadInt32());
            Assert.Equal((ushort)0, blob.ReadUInt16());
            Assert.Equal(0, blob.RemainingBytes);
        }

        private static MethodDefinition GetInvoke(MetadataReader reader, TypeDefinition definition)
        {
            Assert.Equal("System.MulticastDelegate", Provider.GetTypeFromHandle(reader, null, definition.BaseType));
            return Assert.Single(definition.GetMethods().Select(reader.GetMethodDefinition)
                .Where(method => reader.GetString(method.Name) == "Invoke"));
        }

        private static TypeDefinition[] GetDefinitions(MetadataReader reader, string fullName)
        {
            var definitions = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Where(type => !type.IsNested && $"{reader.GetString(type.Namespace)}.{reader.GetString(type.Name)}" == fullName)
                .ToArray();
            Assert.True(definitions.Length > 0, $"Missing physical callback contract type: {fullName}");
            return definitions;
        }

        private static string GetAttributeType(MetadataReader reader, CustomAttribute attribute)
        {
            EntityHandle type;
            if (attribute.Constructor.Kind == HandleKind.MemberReference)
            {
                type = reader.GetMemberReference((MemberReferenceHandle)attribute.Constructor).Parent;
            }
            else
            {
                Assert.Equal(HandleKind.MethodDefinition, attribute.Constructor.Kind);
                type = reader.GetMethodDefinition((MethodDefinitionHandle)attribute.Constructor).GetDeclaringType();
            }

            return Provider.GetTypeFromHandle(reader, null, type);
        }

        private static CallbackSignature Signature(string returnType, int convention, params string[] parameters) =>
            new CallbackSignature(returnType, convention, parameters);

        private sealed record CallbackSignature(string ReturnType, int Convention, string[] Parameters);
        private sealed record FieldContract(string Target, int ExtraPointers);
        private sealed record OutputContract(int Sequence, string Target);

        private sealed class RawSignatureProvider : GenericSignatureTypeProvider
        {
            public override string GetPrimitiveType(PrimitiveTypeCode typeCode) => typeCode.ToString();

            public override string GetTypeFromReference(MetadataReader reader, TypeReferenceHandle handle, byte rawTypeKind = 0)
            {
                var reference = reader.GetTypeReference(handle);
                return $"{reader.GetString(reference.Namespace)}.{reader.GetString(reference.Name)}";
            }
        }
    }
}
