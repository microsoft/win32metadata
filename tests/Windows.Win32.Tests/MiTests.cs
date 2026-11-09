using System.Linq;
using ICSharpCode.Decompiler.TypeSystem;
using MetadataUtils;
using Xunit;

namespace Windows.Win32.Tests
{
    public class MiTests
    {
        private readonly ITypeDefinition[] types;

        public MiTests()
        {
            var typeSystem = DecompilerUtils.LoadDecompilerTypeSystem(TestCommon.TestUtils.Win32WinmdPath);
            this.types = DecompilerUtils.GetSelfDefinedWinmdToplevelTypes(typeSystem)
                .Where(type => type.Namespace == "Windows.Win32.System.Wmi")
                .ToArray();
        }

        [Theory]
        [InlineData("MI_ServerFT", 2)]
        [InlineData("MI_FilterFT", 2)]
        [InlineData("MI_PropertySetFT", 8)]
        [InlineData("MI_InstanceFT", 18)]
        [InlineData("MI_InstanceExFT", 1)]
        [InlineData("MI_ContextFT", 30)]
        [InlineData("MI_QualifierSetFT", 3)]
        [InlineData("MI_ParameterSetFT", 4)]
        [InlineData("MI_ClassFT", 14)]
        [InlineData("MI_SubscriptionDeliveryOptionsFT", 17)]
        [InlineData("MI_SerializerFT", 3)]
        [InlineData("MI_DeserializerFT", 6)]
        [InlineData("MI_ApplicationFT", 11)]
        [InlineData("MI_HostedProviderFT", 2)]
        [InlineData("MI_SessionFT", 15)]
        [InlineData("MI_OperationFT", 6)]
        [InlineData("MI_DestinationOptionsFT", 15)]
        [InlineData("MI_OperationOptionsFT", 13)]
        [InlineData("MI_UtilitiesFT", 2)]
        public void FunctionTableMembersAreDelegates(string name, int expectedCount)
        {
            var fields = this.GetType(name).Fields.Where(field => field.Name != "parent").ToArray();
            Assert.Equal(expectedCount, fields.Length);
            Assert.All(fields, field => Assert.Equal(TypeKind.Delegate, field.Type.Kind));
        }

        [Theory]
        [InlineData("writeMessage")]
        [InlineData("writeError")]
        public void SessionCallbacksAreDelegates(string fieldName)
        {
            var field = this.GetType("MI_SessionCallbacks").Fields.Single(field => field.Name == fieldName);
            Assert.Equal(TypeKind.Delegate, field.Type.Kind);
        }

        [Theory]
        [InlineData("MI_SessionFT_Close", "completionCallback")]
        [InlineData("MI_OperationCallback_PromptUser", "promptUserResult")]
        [InlineData("MI_OperationCallback_WriteError", "writeErrorResult")]
        [InlineData("MI_OperationCallback_Instance", "resultAcknowledgement")]
        [InlineData("MI_OperationCallback_StreamedParameter", "resultAcknowledgement")]
        [InlineData("MI_OperationCallback_Indication", "resultAcknowledgement")]
        [InlineData("MI_OperationCallback_Class", "resultAcknowledgement")]
        public void NestedCallbacksAreDelegates(string name, string parameterName)
        {
            var parameter = this.GetInvoke(name).Parameters.Single(parameter => parameter.Name == parameterName);
            Assert.Equal(TypeKind.Delegate, parameter.Type.Kind);
        }

        [Fact]
        public void NewSessionPreservesItsNativeSignature()
        {
            var invoke = this.GetInvoke("MI_ApplicationFT_NewSession");
            Assert.Equal("MI_Result", invoke.ReturnType.Name);
            Assert.Equal(
                new[] { "MI_Application*", "Char*", "Char*", "MI_DestinationOptions*", "MI_SessionCallbacks*", "MI_Instance**", "MI_Session*" },
                invoke.Parameters.Select(parameter => parameter.Type.Name));
        }

        [Fact]
        public void EnumerateInstancesPreservesItsVoidReturnAndByteBoolean()
        {
            var invoke = this.GetInvoke("MI_SessionFT_EnumerateInstances");
            Assert.Equal(KnownTypeCode.Void, invoke.ReturnType.GetDefinition().KnownTypeCode);
            Assert.Equal(8, invoke.Parameters.Count);
            Assert.Equal(KnownTypeCode.Byte, invoke.Parameters[5].Type.GetDefinition().KnownTypeCode);
            Assert.Equal("MI_Operation*", invoke.Parameters[7].Type.Name);
        }

        private ITypeDefinition GetType(string name) => this.types.Single(type => type.Name == name);

        private IMethod GetInvoke(string name) => this.GetType(name).Methods.Single(method => method.Name == "Invoke");
    }
}
