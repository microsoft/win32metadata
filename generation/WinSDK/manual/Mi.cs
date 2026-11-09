using System;
using System.Runtime.InteropServices;
using Windows.Win32.Foundation.Metadata;

namespace Windows.Win32.System.Wmi 
{
    public static unsafe partial class Apis 
    {
        public const uint MI_FLAG_ANY = (1|2|4|8|16|32|64);
        public const uint MI_FLAG_VERSION = (1<<26|1<<27|1<<28);
        public const uint MI_FLAG_ADOPT = unchecked((uint)(1 << 31));
    }

    // Named signatures for the anonymous function pointers in mi.h.

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate void MI_SessionFT_Close_CompletionCallback(
        [In, Optional] void* completionContext);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_OperationCallback_PromptUserResult(
        [In] MI_Operation* operation,
        MI_OperationCallback_ResponseType response);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_OperationCallback_WriteErrorResult(
        [In] MI_Operation* operation,
        MI_OperationCallback_ResponseType response);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_OperationCallback_ResultAcknowledgement(
        [In] MI_Operation* operation);

    // MI_ServerFT

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_ServerFT_GetVersion(
        [NativeTypeName("MI_Uint32*")] uint* version);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_ServerFT_GetSystemName(
        [NativeTypeName("const MI_Char**")] char** systemName);

    // MI_FilterFT

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_FilterFT_Evaluate(
        [NativeTypeName("const MI_Filter*"), In] MI_Filter* self,
        [NativeTypeName("const MI_Instance*"), In] MI_Instance* instance,
        [NativeTypeName("MI_Boolean*"), Out] byte* result);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_FilterFT_GetExpression(
        [NativeTypeName("const MI_Filter*"), In] MI_Filter* self,
        [NativeTypeName("const MI_Char**"), Out] char** queryLang,
        [NativeTypeName("const MI_Char**"), Out] char** queryExpr);

    // MI_PropertySetFT

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_PropertySetFT_GetElementCount(
        [NativeTypeName("const MI_PropertySet*"), In] MI_PropertySet* self,
        [NativeTypeName("MI_Uint32*"), Out] uint* count);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_PropertySetFT_ContainsElement(
        [NativeTypeName("const MI_PropertySet*"), In] MI_PropertySet* self,
        [NativeTypeName("const MI_Char*"), In] char* name,
        [NativeTypeName("MI_Boolean*"), Out] byte* flag);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_PropertySetFT_AddElement(
        [In, Out] MI_PropertySet* self,
        [NativeTypeName("const MI_Char*"), In] char* name);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_PropertySetFT_GetElementAt(
        [NativeTypeName("const MI_PropertySet*"), In] MI_PropertySet* self,
        [NativeTypeName("MI_Uint32")] uint index,
        [NativeTypeName("const MI_Char**"), Out] char** name);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_PropertySetFT_Clear(
        [In, Out] MI_PropertySet* self);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_PropertySetFT_Destruct(
        [In, Out] MI_PropertySet* self);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_PropertySetFT_Delete(
        [In, Out] MI_PropertySet* self);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_PropertySetFT_Clone(
        [NativeTypeName("const MI_PropertySet*"), In] MI_PropertySet* self,
        [Out] MI_PropertySet** newPropertySet);

    // MI_InstanceFT

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_InstanceFT_Clone(
        [NativeTypeName("const MI_Instance*"), In] MI_Instance* self,
        [Out] MI_Instance** newInstance);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_InstanceFT_Destruct(
        [In, Out] MI_Instance* self);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_InstanceFT_Delete(
        [In, Out] MI_Instance* self);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_InstanceFT_IsA(
        [NativeTypeName("const MI_Instance*"), In] MI_Instance* self,
        [NativeTypeName("const MI_ClassDecl*"), In] MI_ClassDecl* classDecl,
        [NativeTypeName("MI_Boolean*"), Out] byte* flag);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_InstanceFT_GetClassName(
        [NativeTypeName("const MI_Instance*"), In] MI_Instance* self,
        [NativeTypeName("const MI_Char**"), Out] char** className);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_InstanceFT_SetNameSpace(
        [In, Out] MI_Instance* self,
        [NativeTypeName("const MI_Char*"), In] char* nameSpace);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_InstanceFT_GetNameSpace(
        [NativeTypeName("const MI_Instance*"), In] MI_Instance* self,
        [NativeTypeName("const MI_Char**"), Out] char** nameSpace);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_InstanceFT_GetElementCount(
        [NativeTypeName("const MI_Instance*"), In] MI_Instance* self,
        [NativeTypeName("MI_Uint32*"), Out] uint* count);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_InstanceFT_AddElement(
        [In, Out] MI_Instance* self,
        [NativeTypeName("const MI_Char*"), In] char* name,
        [NativeTypeName("const MI_Value*"), In, Optional] MI_Value* value,
        MI_Type @type,
        [NativeTypeName("MI_Uint32")] uint flags);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_InstanceFT_SetElement(
        [In, Out] MI_Instance* self,
        [NativeTypeName("const MI_Char*"), In] char* name,
        [NativeTypeName("const MI_Value*"), In, Optional] MI_Value* value,
        MI_Type @type,
        [NativeTypeName("MI_Uint32")] uint flags);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_InstanceFT_SetElementAt(
        [In, Out] MI_Instance* self,
        [NativeTypeName("MI_Uint32")] uint index,
        [NativeTypeName("const MI_Value*"), In, Optional] MI_Value* value,
        MI_Type @type,
        [NativeTypeName("MI_Uint32")] uint flags);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_InstanceFT_GetElement(
        [NativeTypeName("const MI_Instance*"), In] MI_Instance* self,
        [NativeTypeName("const MI_Char*"), In] char* name,
        [Out, Optional] MI_Value* value,
        [Out, Optional] MI_Type* @type,
        [NativeTypeName("MI_Uint32*"), Out, Optional] uint* flags,
        [NativeTypeName("MI_Uint32*"), Out, Optional] uint* index);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_InstanceFT_GetElementAt(
        [NativeTypeName("const MI_Instance*"), In] MI_Instance* self,
        [NativeTypeName("MI_Uint32")] uint index,
        [NativeTypeName("const MI_Char**"), Out] char** name,
        [Out, Optional] MI_Value* value,
        [Out, Optional] MI_Type* @type,
        [NativeTypeName("MI_Uint32*"), Out, Optional] uint* flags);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_InstanceFT_ClearElement(
        [In, Out] MI_Instance* self,
        [NativeTypeName("const MI_Char*"), In] char* name);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_InstanceFT_ClearElementAt(
        [In, Out] MI_Instance* self,
        [NativeTypeName("MI_Uint32")] uint index);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_InstanceFT_GetServerName(
        [NativeTypeName("const MI_Instance*"), In] MI_Instance* self,
        [NativeTypeName("const MI_Char**"), Out] char** name);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_InstanceFT_SetServerName(
        [In, Out] MI_Instance* self,
        [NativeTypeName("const MI_Char*"), In] char* name);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_InstanceFT_GetClass(
        [NativeTypeName("const MI_Instance*"), In] MI_Instance* self,
        [Out] MI_Class** instanceClass);

    // MI_InstanceExFT

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_InstanceExFT_Normalize(
        [In, Out] MI_Instance** self);

    // MI_ContextFT

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_ContextFT_PostResult(
        [In] MI_Context* context,
        MI_Result result);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_ContextFT_PostInstance(
        [In] MI_Context* context,
        [NativeTypeName("const MI_Instance*"), In] MI_Instance* instance);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_ContextFT_PostIndication(
        [In] MI_Context* context,
        [NativeTypeName("const MI_Instance*"), In] MI_Instance* indication,
        [NativeTypeName("MI_Uint32")] uint subscriptionIDCount,
        [NativeTypeName("const MI_Char*"), In, Optional] char* bookmark);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_ContextFT_ConstructInstance(
        [In] MI_Context* context,
        [NativeTypeName("const MI_ClassDecl*"), In] MI_ClassDecl* classDecl,
        [Out] MI_Instance* instance);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_ContextFT_ConstructParameters(
        [In] MI_Context* context,
        [NativeTypeName("const MI_MethodDecl*"), In] MI_MethodDecl* methodDecl,
        [Out] MI_Instance* instance);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_ContextFT_NewInstance(
        [In] MI_Context* context,
        [NativeTypeName("const MI_ClassDecl*"), In] MI_ClassDecl* classDecl,
        [Out] MI_Instance** instance);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_ContextFT_NewDynamicInstance(
        [In] MI_Context* context,
        [NativeTypeName("const MI_Char*"), In, NotNullTerminated] char* className,
        [NativeTypeName("MI_Uint32")] uint flags,
        [Out] MI_Instance** instance);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_ContextFT_NewParameters(
        [In] MI_Context* context,
        [NativeTypeName("const MI_MethodDecl*"), In] MI_MethodDecl* methodDecl,
        [Out] MI_Instance** instance);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_ContextFT_Canceled(
        [NativeTypeName("const MI_Context*"), In] MI_Context* context,
        [NativeTypeName("MI_Boolean*"), Out] byte* flag);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_ContextFT_GetLocale(
        [NativeTypeName("const MI_Context*"), In] MI_Context* context,
        MI_LocaleType localeType,
        [NativeTypeName("MI_Char*"), Out, NativeArrayInfo(CountConst = 128)] char* locale);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_ContextFT_RegisterCancel(
        [In] MI_Context* context,
        [In] MI_CancelCallback callback,
        [In, Optional] void* callbackData);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_ContextFT_RequestUnload(
        [In] MI_Context* context);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_ContextFT_RefuseUnload(
        [In] MI_Context* context);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_ContextFT_GetLocalSession(
        [NativeTypeName("const MI_Context*"), In] MI_Context* context,
        [Out] MI_Session* session);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_ContextFT_SetStringOption(
        [In] MI_Context* context,
        [NativeTypeName("const MI_Char*"), In] char* name,
        [NativeTypeName("const MI_Char*"), In] char* value);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_ContextFT_GetStringOption(
        [In] MI_Context* context,
        [NativeTypeName("const MI_Char*"), In] char* name,
        [NativeTypeName("const MI_Char**"), Out] char** value);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_ContextFT_GetNumberOption(
        [In] MI_Context* context,
        [NativeTypeName("const MI_Char*"), In] char* name,
        [NativeTypeName("MI_Uint32*"), Out, Optional] uint* value);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_ContextFT_GetCustomOption(
        [In] MI_Context* context,
        [NativeTypeName("const MI_Char*"), In] char* name,
        [Out, Optional] MI_Type* valueType,
        [Out, Optional] MI_Value* value);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_ContextFT_GetCustomOptionCount(
        [In] MI_Context* context,
        [NativeTypeName("MI_Uint32*"), Out, Optional] uint* count);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_ContextFT_GetCustomOptionAt(
        [In] MI_Context* context,
        [NativeTypeName("MI_Uint32"), In] uint index,
        [NativeTypeName("const MI_Char**"), Out, Optional] char** name,
        [Out, Optional] MI_Type* valueType,
        [Out, Optional] MI_Value* value);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_ContextFT_WriteMessage(
        [In] MI_Context* context,
        [NativeTypeName("MI_Uint32")] uint channel,
        [NativeTypeName("const MI_Char*"), In] char* message);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_ContextFT_WriteProgress(
        [In] MI_Context* context,
        [NativeTypeName("const MI_Char*"), In] char* activity,
        [NativeTypeName("const MI_Char*"), In] char* currentOperation,
        [NativeTypeName("const MI_Char*"), In] char* statusDescription,
        [NativeTypeName("MI_Uint32")] uint percentComplete,
        [NativeTypeName("MI_Uint32")] uint secondsRemaining);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_ContextFT_WriteStreamParameter(
        [In] MI_Context* context,
        [NativeTypeName("const MI_Char*"), In] char* name,
        [NativeTypeName("const MI_Value*"), In] MI_Value* value,
        [In] MI_Type @type,
        [NativeTypeName("MI_Uint32"), In] uint flags);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_ContextFT_WriteCimError(
        [In] MI_Context* context,
        [NativeTypeName("const MI_Instance*"), In] MI_Instance* error,
        [NativeTypeName("MI_Boolean*"), Out] byte* flag);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_ContextFT_PromptUser(
        [In] MI_Context* context,
        [NativeTypeName("const MI_Char*"), In] char* message,
        MI_PromptType promptType,
        [NativeTypeName("MI_Boolean*"), Out] byte* result);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_ContextFT_ShouldProcess(
        [In] MI_Context* context,
        [NativeTypeName("const MI_Char*"), In] char* target,
        [NativeTypeName("const MI_Char*"), In] char* action,
        [NativeTypeName("MI_Boolean*"), Out] byte* result);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_ContextFT_ShouldContinue(
        [In] MI_Context* context,
        [NativeTypeName("const MI_Char*"), In] char* message,
        [NativeTypeName("MI_Boolean*"), Out] byte* result);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_ContextFT_PostError(
        [In] MI_Context* context,
        [NativeTypeName("MI_Uint32")] uint resultCode,
        [NativeTypeName("const MI_Char*"), In] char* resultType,
        [NativeTypeName("const MI_Char*"), In] char* errorMessage);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_ContextFT_PostCimError(
        [In] MI_Context* context,
        [NativeTypeName("const MI_Instance*"), In] MI_Instance* error);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_ContextFT_WriteError(
        [In] MI_Context* context,
        [NativeTypeName("MI_Uint32")] uint resultCode,
        [NativeTypeName("const MI_Char*"), In] char* resultType,
        [NativeTypeName("const MI_Char*"), In] char* errorMessage,
        [NativeTypeName("MI_Boolean*"), Out] byte* flag);

    // MI_QualifierSetFT

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_QualifierSetFT_GetQualifierCount(
        [NativeTypeName("const MI_QualifierSet*"), In] MI_QualifierSet* self,
        [NativeTypeName("MI_Uint32*"), Out] uint* count);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_QualifierSetFT_GetQualifierAt(
        [NativeTypeName("const MI_QualifierSet*"), In] MI_QualifierSet* self,
        [NativeTypeName("MI_Uint32")] uint index,
        [NativeTypeName("const MI_Char**"), Out] char** name,
        [Out] MI_Type* qualifierType,
        [NativeTypeName("MI_Uint32*"), Out] uint* qualifierFlags,
        [Out] MI_Value* qualifierValue);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_QualifierSetFT_GetQualifier(
        [NativeTypeName("const MI_QualifierSet*"), In] MI_QualifierSet* self,
        [NativeTypeName("const MI_Char*"), In] char* name,
        [Out] MI_Type* qualifierType,
        [NativeTypeName("MI_Uint32*"), Out] uint* qualifierFlags,
        [Out] MI_Value* qualifierValue,
        [NativeTypeName("MI_Uint32*"), Out] uint* index);

    // MI_ParameterSetFT

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_ParameterSetFT_GetMethodReturnType(
        [NativeTypeName("const MI_ParameterSet*"), In] MI_ParameterSet* self,
        [Out] MI_Type* returnType,
        [Out] MI_QualifierSet* qualifierSet);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_ParameterSetFT_GetParameterCount(
        [NativeTypeName("const MI_ParameterSet*"), In] MI_ParameterSet* self,
        [NativeTypeName("MI_Uint32*"), Out] uint* count);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_ParameterSetFT_GetParameterAt(
        [NativeTypeName("const MI_ParameterSet*"), In] MI_ParameterSet* self,
        [NativeTypeName("MI_Uint32")] uint index,
        [NativeTypeName("const MI_Char**"), Out] char** name,
        MI_Type* parameterType,
        [NativeTypeName("MI_Char**"), Out, Optional] char** referenceClass,
        [Out] MI_QualifierSet* qualifierSet);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_ParameterSetFT_GetParameter(
        [NativeTypeName("const MI_ParameterSet*"), In] MI_ParameterSet* self,
        [NativeTypeName("const MI_Char*"), In] char* name,
        [Out] MI_Type* parameterType,
        [NativeTypeName("MI_Char**"), Out, Optional] char** referenceClass,
        [Out] MI_QualifierSet* qualifierSet,
        [NativeTypeName("MI_Uint32*"), Out] uint* index);

    // MI_ClassFT

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_ClassFT_GetClassName(
        [NativeTypeName("const MI_Class*"), In] MI_Class* self,
        [NativeTypeName("const MI_Char**"), Out] char** className);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_ClassFT_GetNameSpace(
        [NativeTypeName("const MI_Class*"), In] MI_Class* self,
        [NativeTypeName("const MI_Char**"), Out] char** nameSpace);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_ClassFT_GetServerName(
        [NativeTypeName("const MI_Class*"), In] MI_Class* self,
        [NativeTypeName("const MI_Char**"), Out] char** serverName);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_ClassFT_GetElementCount(
        [NativeTypeName("const MI_Class*"), In] MI_Class* self,
        [NativeTypeName("MI_Uint32*"), Out] uint* count);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_ClassFT_GetElement(
        [NativeTypeName("const MI_Class*"), In] MI_Class* self,
        [NativeTypeName("const MI_Char*"), In] char* name,
        [Out, Optional] MI_Value* value,
        [NativeTypeName("MI_Boolean*"), Out, Optional] byte* valueExists,
        [Out, Optional] MI_Type* @type,
        [NativeTypeName("MI_Char**"), Out, Optional] char** referenceClass,
        [Out, Optional] MI_QualifierSet* qualifierSet,
        [NativeTypeName("MI_Uint32*"), Out, Optional] uint* flags,
        [NativeTypeName("MI_Uint32*"), Out, Optional] uint* index);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_ClassFT_GetElementAt(
        [NativeTypeName("const MI_Class*"), In] MI_Class* self,
        [NativeTypeName("MI_Uint32")] uint index,
        [NativeTypeName("const MI_Char**"), Out, Optional] char** name,
        [Out, Optional] MI_Value* value,
        [NativeTypeName("MI_Boolean*"), Out, Optional] byte* valueExists,
        [Out, Optional] MI_Type* @type,
        [NativeTypeName("MI_Char**"), Out, Optional] char** referenceClass,
        [Out, Optional] MI_QualifierSet* qualifierSet,
        [NativeTypeName("MI_Uint32*"), Out, Optional] uint* flags);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_ClassFT_GetClassQualifierSet(
        [NativeTypeName("const MI_Class*"), In] MI_Class* self,
        [Out, Optional] MI_QualifierSet* qualifierSet);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_ClassFT_GetMethodCount(
        [NativeTypeName("const MI_Class*"), In] MI_Class* self,
        [NativeTypeName("MI_Uint32*"), Out] uint* count);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_ClassFT_GetMethodAt(
        [NativeTypeName("const MI_Class*"), In] MI_Class* self,
        [NativeTypeName("MI_Uint32")] uint index,
        [NativeTypeName("const MI_Char**"), Out] char** name,
        [Out, Optional] MI_QualifierSet* qualifierSet,
        [Out, Optional] MI_ParameterSet* parameterSet);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_ClassFT_GetMethod(
        [NativeTypeName("const MI_Class*"), In] MI_Class* self,
        [NativeTypeName("const MI_Char*"), In] char* name,
        [Out, Optional] MI_QualifierSet* qualifierSet,
        [Out, Optional] MI_ParameterSet* parameterSet,
        [NativeTypeName("MI_Uint32*"), Out, Optional] uint* index);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_ClassFT_GetParentClassName(
        [NativeTypeName("const MI_Class*"), In] MI_Class* self,
        [NativeTypeName("const MI_Char**"), Out] char** name);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_ClassFT_GetParentClass(
        [NativeTypeName("const MI_Class*"), In] MI_Class* self,
        [Out] MI_Class** parentClass);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_ClassFT_Delete(
        [In, Out] MI_Class* self);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_ClassFT_Clone(
        [NativeTypeName("const MI_Class*"), In] MI_Class* self,
        [Out] MI_Class** newClass);

    // MI_SessionCallbacks

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate void MI_SessionCallbacks_writeMessage(
        [In] MI_Application* application,
        [In, Optional] void* callbackContext,
        [NativeTypeName("MI_Uint32")] uint channel,
        [NativeTypeName("const MI_Char*"), In] char* message);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate void MI_SessionCallbacks_writeError(
        [In] MI_Application* application,
        [In, Optional] void* callbackContext,
        [In] MI_Instance* instance);

    // MI_SubscriptionDeliveryOptionsFT

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_SubscriptionDeliveryOptionsFT_SetString(
        [In, Out] MI_SubscriptionDeliveryOptions* options,
        [NativeTypeName("const MI_Char*"), In] char* optionName,
        [NativeTypeName("const MI_Char*"), In] char* value,
        [NativeTypeName("MI_Uint32")] uint flags);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_SubscriptionDeliveryOptionsFT_SetNumber(
        [In, Out] MI_SubscriptionDeliveryOptions* options,
        [NativeTypeName("const MI_Char*"), In] char* optionName,
        [NativeTypeName("MI_Uint32"), In] uint value,
        [NativeTypeName("MI_Uint32")] uint flags);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_SubscriptionDeliveryOptionsFT_SetDateTime(
        [In, Out] MI_SubscriptionDeliveryOptions* options,
        [NativeTypeName("const MI_Char*"), In] char* optionName,
        [NativeTypeName("const MI_Datetime*"), In] MI_Datetime* value,
        [NativeTypeName("MI_Uint32")] uint flags);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_SubscriptionDeliveryOptionsFT_SetInterval(
        [In, Out] MI_SubscriptionDeliveryOptions* options,
        [NativeTypeName("const MI_Char*"), In] char* optionName,
        [NativeTypeName("const MI_Interval*"), In] MI_Interval* value,
        [NativeTypeName("MI_Uint32")] uint flags);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_SubscriptionDeliveryOptionsFT_AddCredentials(
        [In, Out] MI_SubscriptionDeliveryOptions* options,
        [NativeTypeName("const MI_Char*"), In] char* optionName,
        [NativeTypeName("const MI_UserCredentials*"), In] MI_UserCredentials* credentials,
        [NativeTypeName("MI_Uint32")] uint flags);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_SubscriptionDeliveryOptionsFT_Delete(
        [In, Out] MI_SubscriptionDeliveryOptions* self);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_SubscriptionDeliveryOptionsFT_GetString(
        [In] MI_SubscriptionDeliveryOptions* options,
        [NativeTypeName("const MI_Char*"), In] char* optionName,
        [NativeTypeName("const MI_Char**"), Out] char** value,
        [NativeTypeName("MI_Uint32*"), Out, Optional] uint* index,
        [NativeTypeName("MI_Uint32*"), Out, Optional] uint* flags);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_SubscriptionDeliveryOptionsFT_GetNumber(
        [In] MI_SubscriptionDeliveryOptions* options,
        [NativeTypeName("const MI_Char*"), In] char* optionName,
        [NativeTypeName("MI_Uint32*"), Out] uint* value,
        [NativeTypeName("MI_Uint32*"), Out, Optional] uint* index,
        [NativeTypeName("MI_Uint32*"), Out, Optional] uint* flags);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_SubscriptionDeliveryOptionsFT_GetDateTime(
        [In] MI_SubscriptionDeliveryOptions* options,
        [NativeTypeName("const MI_Char*"), In] char* optionName,
        [Out] MI_Datetime* value,
        [NativeTypeName("MI_Uint32*"), Out, Optional] uint* index,
        [NativeTypeName("MI_Uint32*"), Out, Optional] uint* flags);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_SubscriptionDeliveryOptionsFT_GetInterval(
        [In] MI_SubscriptionDeliveryOptions* options,
        [NativeTypeName("const MI_Char*"), In] char* optionName,
        [Out] MI_Interval* value,
        [NativeTypeName("MI_Uint32*"), Out, Optional] uint* index,
        [NativeTypeName("MI_Uint32*"), Out, Optional] uint* flags);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_SubscriptionDeliveryOptionsFT_GetOptionCount(
        [In] MI_SubscriptionDeliveryOptions* options,
        [NativeTypeName("MI_Uint32*"), Out, Optional] uint* count);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_SubscriptionDeliveryOptionsFT_GetOptionAt(
        [In] MI_SubscriptionDeliveryOptions* options,
        [NativeTypeName("MI_Uint32")] uint index,
        [NativeTypeName("const MI_Char**"), Out] char** optionName,
        [Out] MI_Value* value,
        [Out] MI_Type* @type,
        [NativeTypeName("MI_Uint32*"), Out, Optional] uint* flags);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_SubscriptionDeliveryOptionsFT_GetOption(
        [In] MI_SubscriptionDeliveryOptions* options,
        [NativeTypeName("const MI_Char*"), In] char* optionName,
        [Out] MI_Value* value,
        [Out] MI_Type* @type,
        [NativeTypeName("MI_Uint32*"), Out, Optional] uint* index,
        [NativeTypeName("MI_Uint32*"), Out, Optional] uint* flags);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_SubscriptionDeliveryOptionsFT_GetCredentialsCount(
        [In] MI_SubscriptionDeliveryOptions* options,
        [NativeTypeName("MI_Uint32*"), Out] uint* count);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_SubscriptionDeliveryOptionsFT_GetCredentialsAt(
        [In] MI_SubscriptionDeliveryOptions* options,
        [NativeTypeName("MI_Uint32")] uint index,
        [NativeTypeName("const MI_Char**"), Out] char** optionName,
        [Out] MI_UserCredentials* credentials,
        [NativeTypeName("MI_Uint32*"), Out, Optional] uint* flags);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_SubscriptionDeliveryOptionsFT_GetCredentialsPasswordAt(
        [In] MI_SubscriptionDeliveryOptions* options,
        [NativeTypeName("MI_Uint32")] uint index,
        [NativeTypeName("const MI_Char**"), Out] char** optionName,
        [NativeTypeName("MI_Char*"), Out, Optional, NativeArrayInfo(CountParamIndex = 4), NotNullTerminated] char* password,
        [NativeTypeName("MI_Uint32"), In] uint bufferLength,
        [NativeTypeName("MI_Uint32*"), Out] uint* passwordLength,
        [NativeTypeName("MI_Uint32*"), Out, Optional] uint* flags);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_SubscriptionDeliveryOptionsFT_Clone(
        [NativeTypeName("const MI_SubscriptionDeliveryOptions*"), In] MI_SubscriptionDeliveryOptions* self,
        [Out] MI_SubscriptionDeliveryOptions* newSubscriptionDeliveryOptions);

    // MI_SerializerFT

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_SerializerFT_Close(
        [In, Out] MI_Serializer* serializer);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_SerializerFT_SerializeClass(
        [In, Out] MI_Serializer* serializer,
        [NativeTypeName("MI_Uint32")] uint flags,
        [NativeTypeName("const MI_Class*"), In] MI_Class* classObject,
        [NativeTypeName("MI_Uint8*"), Out, MemorySize(BytesParamIndex = 4)] byte* clientBuffer,
        [NativeTypeName("MI_Uint32")] uint clientBufferLength,
        [NativeTypeName("MI_Uint32*"), In, Out] uint* clientBufferNeeded);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_SerializerFT_SerializeInstance(
        [In, Out] MI_Serializer* serializer,
        [NativeTypeName("MI_Uint32")] uint flags,
        [NativeTypeName("const MI_Instance*"), In] MI_Instance* instanceObject,
        [NativeTypeName("MI_Uint8*"), Out, MemorySize(BytesParamIndex = 4)] byte* clientBuffer,
        [NativeTypeName("MI_Uint32")] uint clientBufferLength,
        [NativeTypeName("MI_Uint32*"), In, Out] uint* clientBufferNeeded);

    // MI_DeserializerFT

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_DeserializerFT_Close(
        [In, Out] MI_Deserializer* deserializer);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_DeserializerFT_DeserializeClass(
        [In, Out] MI_Deserializer* deserializer,
        [NativeTypeName("MI_Uint32")] uint flags,
        [NativeTypeName("MI_Uint8*"), In, NativeArrayInfo(CountParamIndex = 3)] byte* serializedBuffer,
        [NativeTypeName("MI_Uint32")] uint serializedBufferLength,
        [In, Optional] MI_Class* parentClass,
        [NativeTypeName("const MI_Char*"), In, Optional] char* serverName,
        [NativeTypeName("const MI_Char*"), In, Optional] char* namespaceName,
        [In, Optional] MI_Deserializer_ClassObjectNeeded classObjectNeeded,
        [In, Optional] void* classObjectNeededContext,
        [NativeTypeName("MI_Uint32*"), Out, Optional] uint* serializedBufferRead,
        [Out, Optional] MI_Class** classObject,
        [Out, Optional] MI_Instance** cimErrorDetails);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_DeserializerFT_Class_GetClassName(
        [In, Out] MI_Deserializer* deserializer,
        [NativeTypeName("MI_Uint8*"), In, NativeArrayInfo(CountParamIndex = 2)] byte* serializedBuffer,
        [NativeTypeName("MI_Uint32")] uint serializedBufferLength,
        [NativeTypeName("MI_Char*"), Out, Optional, NativeArrayInfo(CountParamIndex = 4), NotNullTerminated] char* className,
        [NativeTypeName("MI_Uint32*"), In, Out] uint* classNameLength,
        [Out, Optional] MI_Instance** cimErrorDetails);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_DeserializerFT_Class_GetParentClassName(
        [In, Out] MI_Deserializer* deserializer,
        [NativeTypeName("MI_Uint8*"), In, NativeArrayInfo(CountParamIndex = 2)] byte* serializedBuffer,
        [NativeTypeName("MI_Uint32")] uint serializedBufferLength,
        [NativeTypeName("MI_Char*"), Out, Optional, NativeArrayInfo(CountParamIndex = 4), NotNullTerminated] char* parentClassName,
        [NativeTypeName("MI_Uint32*"), In, Out] uint* parentClassNameLength,
        [Out, Optional] MI_Instance** cimErrorDetails);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_DeserializerFT_DeserializeInstance(
        [In, Out] MI_Deserializer* deserializer,
        [NativeTypeName("MI_Uint32")] uint flags,
        [NativeTypeName("MI_Uint8*"), In, NativeArrayInfo(CountParamIndex = 3)] byte* serializedBuffer,
        [NativeTypeName("MI_Uint32")] uint serializedBufferLength,
        [In, Optional, NativeArrayInfo(CountParamIndex = 5)] MI_Class** classObjects,
        [NativeTypeName("MI_Uint32")] uint numberClassObjects,
        [In, Optional] MI_Deserializer_ClassObjectNeeded classObjectNeeded,
        [In, Optional] void* classObjectNeededContext,
        [NativeTypeName("MI_Uint32*"), Out, Optional] uint* serializedBufferRead,
        [Out, Optional] MI_Instance** instanceObject,
        [Out, Optional] MI_Instance** cimErrorDetails);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_DeserializerFT_Instance_GetClassName(
        [In, Out] MI_Deserializer* deserializer,
        [NativeTypeName("MI_Uint8*"), In, NativeArrayInfo(CountParamIndex = 2)] byte* serializedBuffer,
        [NativeTypeName("MI_Uint32")] uint serializedBufferLength,
        [NativeTypeName("MI_Char*"), Out, Optional, NativeArrayInfo(CountParamIndex = 4), NotNullTerminated] char* className,
        [NativeTypeName("MI_Uint32*"), In, Out] uint* classNameLength,
        [Out, Optional] MI_Instance** cimErrorDetails);

    // MI_ApplicationFT

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_ApplicationFT_Close(
        [In, Out] MI_Application* application);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_ApplicationFT_NewSession(
        [In] MI_Application* application,
        [NativeTypeName("const MI_Char*"), In, Optional] char* protocol,
        [NativeTypeName("const MI_Char*"), In, Optional] char* destination,
        [In, Optional] MI_DestinationOptions* options,
        [In, Optional] MI_SessionCallbacks* callbacks,
        [Out, Optional] MI_Instance** extendedError,
        [Out] MI_Session* session);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_ApplicationFT_NewHostedProvider(
        [In] MI_Application* application,
        [NativeTypeName("const MI_Char*"), In] char* namespaceName,
        [NativeTypeName("const MI_Char*"), In] char* providerName,
        [In] MI_MainFunction mi_Main,
        [Out, Optional] MI_Instance** extendedError,
        [Out] MI_HostedProvider* provider);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_ApplicationFT_NewInstance(
        [In] MI_Application* application,
        [NativeTypeName("const MI_Char*"), In] char* className,
        [NativeTypeName("const MI_ClassDecl*"), In, Optional] MI_ClassDecl* classRTTI,
        [Out] MI_Instance** instance);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_ApplicationFT_NewDestinationOptions(
        [In] MI_Application* application,
        [Out] MI_DestinationOptions* options);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_ApplicationFT_NewOperationOptions(
        [In] MI_Application* application,
        [NativeTypeName("MI_Boolean"), In] byte customOptionsMustUnderstand,
        [Out] MI_OperationOptions* options);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_ApplicationFT_NewSubscriptionDeliveryOptions(
        [In] MI_Application* application,
        [In] MI_SubscriptionDeliveryType deliveryType,
        [Out] MI_SubscriptionDeliveryOptions* deliveryOptions);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_ApplicationFT_NewSerializer(
        [In, Out] MI_Application* application,
        [NativeTypeName("MI_Uint32")] uint flags,
        [NativeTypeName("MI_Char*"), In] char* format,
        [Out] MI_Serializer* serializer);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_ApplicationFT_NewDeserializer(
        [In, Out] MI_Application* application,
        [NativeTypeName("MI_Uint32")] uint flags,
        [NativeTypeName("MI_Char*"), In] char* format,
        [Out] MI_Deserializer* deserializer);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_ApplicationFT_NewInstanceFromClass(
        [In] MI_Application* application,
        [NativeTypeName("const MI_Char*"), In] char* className,
        [NativeTypeName("const MI_Class*"), In, Optional] MI_Class* classObject,
        [Out] MI_Instance** instance);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_ApplicationFT_NewClass(
        [In] MI_Application* application,
        [NativeTypeName("const MI_ClassDecl*"), In] MI_ClassDecl* classDecl,
        [NativeTypeName("const MI_Char*"), In, Optional] char* namespaceName,
        [NativeTypeName("const MI_Char*"), In, Optional] char* serverName,
        [Out] MI_Class** classObject);

    // MI_HostedProviderFT

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_HostedProviderFT_Close(
        [In, Out] MI_HostedProvider* hostedProvider);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_HostedProviderFT_GetApplication(
        [In] MI_HostedProvider* hostedProvider,
        [Out] MI_Application* application);

    // MI_SessionFT

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_SessionFT_Close(
        [In, Out] MI_Session* session,
        [In, Optional] void* completionContext,
        [In, Optional] MI_SessionFT_Close_CompletionCallback completionCallback);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_SessionFT_GetApplication(
        [In] MI_Session* session,
        [Out] MI_Application* application);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate void MI_SessionFT_GetInstance(
        [In] MI_Session* session,
        [NativeTypeName("MI_Uint32")] uint flags,
        [In, Optional] MI_OperationOptions* options,
        [NativeTypeName("const MI_Char*"), In, Optional] char* namespaceName,
        [NativeTypeName("const MI_Instance*"), In] MI_Instance* inboundInstance,
        [In, Optional] MI_OperationCallbacks* callbacks,
        [Out] MI_Operation* operation);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate void MI_SessionFT_ModifyInstance(
        [In] MI_Session* session,
        [NativeTypeName("MI_Uint32")] uint flags,
        [In, Optional] MI_OperationOptions* options,
        [NativeTypeName("const MI_Char*"), In, Optional] char* namespaceName,
        [NativeTypeName("const MI_Instance*"), In] MI_Instance* inboundInstance,
        [In, Optional] MI_OperationCallbacks* callbacks,
        [Out] MI_Operation* operation);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate void MI_SessionFT_CreateInstance(
        [In] MI_Session* session,
        [NativeTypeName("MI_Uint32")] uint flags,
        [In, Optional] MI_OperationOptions* options,
        [NativeTypeName("const MI_Char*"), In, Optional] char* namespaceName,
        [NativeTypeName("const MI_Instance*"), In] MI_Instance* inboundInstance,
        [In, Optional] MI_OperationCallbacks* callbacks,
        [Out] MI_Operation* operation);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate void MI_SessionFT_DeleteInstance(
        [In] MI_Session* session,
        [NativeTypeName("MI_Uint32")] uint flags,
        [In, Optional] MI_OperationOptions* options,
        [NativeTypeName("const MI_Char*"), In, Optional] char* namespaceName,
        [NativeTypeName("const MI_Instance*"), In] MI_Instance* inboundInstance,
        [In, Optional] MI_OperationCallbacks* callbacks,
        [Out] MI_Operation* operation);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate void MI_SessionFT_Invoke(
        [In] MI_Session* session,
        [NativeTypeName("MI_Uint32")] uint flags,
        [In, Optional] MI_OperationOptions* options,
        [NativeTypeName("const MI_Char*"), In, Optional] char* namespaceName,
        [NativeTypeName("const MI_Char*"), In, Optional] char* className,
        [NativeTypeName("const MI_Char*"), In] char* methodName,
        [NativeTypeName("const MI_Instance*"), In, Optional] MI_Instance* inboundInstance,
        [NativeTypeName("const MI_Instance*"), In, Optional] MI_Instance* inboundProperties,
        [In, Optional] MI_OperationCallbacks* callbacks,
        [Out] MI_Operation* operation);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate void MI_SessionFT_EnumerateInstances(
        [In] MI_Session* session,
        [NativeTypeName("MI_Uint32")] uint flags,
        [In, Optional] MI_OperationOptions* options,
        [NativeTypeName("const MI_Char*"), In, Optional] char* namespaceName,
        [NativeTypeName("const MI_Char*"), In, Optional] char* className,
        [NativeTypeName("MI_Boolean")] byte keysOnly,
        [In, Optional] MI_OperationCallbacks* callbacks,
        [Out] MI_Operation* operation);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate void MI_SessionFT_QueryInstances(
        [In] MI_Session* session,
        [NativeTypeName("MI_Uint32")] uint flags,
        [In, Optional] MI_OperationOptions* options,
        [NativeTypeName("const MI_Char*"), In, Optional] char* namespaceName,
        [NativeTypeName("const MI_Char*"), In, Optional] char* queryDialect,
        [NativeTypeName("const MI_Char*"), In, Optional] char* queryExpression,
        [In, Optional] MI_OperationCallbacks* callbacks,
        [Out] MI_Operation* operation);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate void MI_SessionFT_AssociatorInstances(
        [In] MI_Session* session,
        [NativeTypeName("MI_Uint32")] uint flags,
        [In, Optional] MI_OperationOptions* options,
        [NativeTypeName("const MI_Char*"), In, Optional] char* namespaceName,
        [NativeTypeName("const MI_Instance*"), In] MI_Instance* instanceKeys,
        [NativeTypeName("const MI_Char*"), In, Optional] char* assocClass,
        [NativeTypeName("const MI_Char*"), In, Optional] char* resultClass,
        [NativeTypeName("const MI_Char*"), In, Optional] char* role,
        [NativeTypeName("const MI_Char*"), In, Optional] char* resultRole,
        [NativeTypeName("MI_Boolean")] byte keysOnly,
        [In, Optional] MI_OperationCallbacks* callbacks,
        [Out] MI_Operation* operation);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate void MI_SessionFT_ReferenceInstances(
        [In] MI_Session* session,
        [NativeTypeName("MI_Uint32")] uint flags,
        [In, Optional] MI_OperationOptions* options,
        [NativeTypeName("const MI_Char*"), In, Optional] char* namespaceName,
        [NativeTypeName("const MI_Instance*"), In] MI_Instance* instanceKeys,
        [NativeTypeName("const MI_Char*"), In, Optional] char* resultClass,
        [NativeTypeName("const MI_Char*"), In, Optional] char* role,
        [NativeTypeName("MI_Boolean")] byte keysOnly,
        [In, Optional] MI_OperationCallbacks* callbacks,
        [Out] MI_Operation* operation);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate void MI_SessionFT_Subscribe(
        [In] MI_Session* session,
        [NativeTypeName("MI_Uint32")] uint flags,
        [In, Optional] MI_OperationOptions* options,
        [NativeTypeName("const MI_Char*"), In, Optional] char* namespaceName,
        [NativeTypeName("const MI_Char*"), In, Optional] char* queryDialect,
        [NativeTypeName("const MI_Char*"), In, Optional] char* queryExpression,
        [NativeTypeName("const MI_SubscriptionDeliveryOptions*"), In, Optional] MI_SubscriptionDeliveryOptions* deliverOptions,
        [In, Optional] MI_OperationCallbacks* callbacks,
        [Out] MI_Operation* operation);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate void MI_SessionFT_GetClass(
        [In] MI_Session* session,
        [NativeTypeName("MI_Uint32")] uint flags,
        [In, Optional] MI_OperationOptions* options,
        [NativeTypeName("const MI_Char*"), In, Optional] char* namespaceName,
        [NativeTypeName("const MI_Char*"), In, Optional] char* className,
        [In, Optional] MI_OperationCallbacks* callbacks,
        [Out] MI_Operation* operation);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate void MI_SessionFT_EnumerateClasses(
        [In] MI_Session* session,
        [NativeTypeName("MI_Uint32")] uint flags,
        [In, Optional] MI_OperationOptions* options,
        [NativeTypeName("const MI_Char*"), In, Optional] char* namespaceName,
        [NativeTypeName("const MI_Char*"), In, Optional] char* className,
        [NativeTypeName("MI_Boolean")] byte classNamesOnly,
        [In, Optional] MI_OperationCallbacks* callbacks,
        [Out] MI_Operation* operation);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate void MI_SessionFT_TestConnection(
        [In] MI_Session* session,
        [NativeTypeName("MI_Uint32")] uint flags,
        [In, Optional] MI_OperationCallbacks* callbacks,
        [Out] MI_Operation* operation);

    // MI_OperationFT

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_OperationFT_Close(
        [In, Out] MI_Operation* operation);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_OperationFT_Cancel(
        [In, Out] MI_Operation* operation,
        MI_CancellationReason reason);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_OperationFT_GetSession(
        [In] MI_Operation* operation,
        [Out] MI_Session* session);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_OperationFT_GetInstance(
        [In] MI_Operation* operation,
        [NativeTypeName("const MI_Instance**"), Out] MI_Instance** instance,
        [NativeTypeName("MI_Boolean*"), Out, Optional] byte* moreResults,
        [Out, Optional] MI_Result* result,
        [NativeTypeName("const MI_Char**"), Out, Optional] char** errorMessage,
        [NativeTypeName("const MI_Instance**"), Out, Optional] MI_Instance** completionDetails);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_OperationFT_GetIndication(
        [In] MI_Operation* operation,
        [NativeTypeName("const MI_Instance**"), Out] MI_Instance** instance,
        [NativeTypeName("const MI_Char**"), Out, Optional] char** bookmark,
        [NativeTypeName("const MI_Char**"), Out, Optional] char** machineID,
        [NativeTypeName("MI_Boolean*"), Out, Optional] byte* moreResults,
        [Out, Optional] MI_Result* result,
        [NativeTypeName("const MI_Char**"), Out, Optional] char** errorMessage,
        [NativeTypeName("const MI_Instance**"), Out, Optional] MI_Instance** completionDetails);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_OperationFT_GetClass(
        [In] MI_Operation* operation,
        [NativeTypeName("const MI_Class**"), Out] MI_Class** classResult,
        [NativeTypeName("MI_Boolean*"), Out, Optional] byte* moreResults,
        [Out, Optional] MI_Result* result,
        [NativeTypeName("const MI_Char**"), Out, Optional] char** errorMessage,
        [NativeTypeName("const MI_Instance**"), Out, Optional] MI_Instance** completionDetails);

    // MI_DestinationOptionsFT

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate void MI_DestinationOptionsFT_Delete(
        [In, Out] MI_DestinationOptions* options);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_DestinationOptionsFT_SetString(
        [In, Out] MI_DestinationOptions* options,
        [NativeTypeName("const MI_Char*"), In] char* optionName,
        [NativeTypeName("const MI_Char*"), In] char* value,
        [NativeTypeName("MI_Uint32")] uint flags);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_DestinationOptionsFT_SetNumber(
        [In, Out] MI_DestinationOptions* options,
        [NativeTypeName("const MI_Char*"), In] char* optionName,
        [NativeTypeName("MI_Uint32"), In] uint value,
        [NativeTypeName("MI_Uint32")] uint flags);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_DestinationOptionsFT_AddCredentials(
        [In, Out] MI_DestinationOptions* options,
        [NativeTypeName("const MI_Char*"), In] char* optionName,
        [NativeTypeName("const MI_UserCredentials*"), In] MI_UserCredentials* credentials,
        [NativeTypeName("MI_Uint32")] uint flags);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_DestinationOptionsFT_GetString(
        [In] MI_DestinationOptions* options,
        [NativeTypeName("const MI_Char*"), In] char* optionName,
        [NativeTypeName("const MI_Char**"), Out] char** value,
        [NativeTypeName("MI_Uint32*"), Out, Optional] uint* index,
        [NativeTypeName("MI_Uint32*"), Out, Optional] uint* flags);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_DestinationOptionsFT_GetNumber(
        [In] MI_DestinationOptions* options,
        [NativeTypeName("const MI_Char*"), In] char* optionName,
        [NativeTypeName("MI_Uint32*"), Out] uint* value,
        [NativeTypeName("MI_Uint32*"), Out, Optional] uint* index,
        [NativeTypeName("MI_Uint32*"), Out, Optional] uint* flags);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_DestinationOptionsFT_GetOptionCount(
        [In] MI_DestinationOptions* options,
        [NativeTypeName("MI_Uint32*"), Out] uint* count);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_DestinationOptionsFT_GetOptionAt(
        [In] MI_DestinationOptions* options,
        [NativeTypeName("MI_Uint32")] uint index,
        [NativeTypeName("const MI_Char**"), Out] char** optionName,
        [Out] MI_Value* value,
        [Out] MI_Type* @type,
        [NativeTypeName("MI_Uint32*"), Out, Optional] uint* flags);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_DestinationOptionsFT_GetOption(
        [In] MI_DestinationOptions* options,
        [NativeTypeName("const MI_Char*"), In] char* optionName,
        [Out] MI_Value* value,
        [Out] MI_Type* @type,
        [NativeTypeName("MI_Uint32*"), Out, Optional] uint* index,
        [NativeTypeName("MI_Uint32*"), Out, Optional] uint* flags);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_DestinationOptionsFT_GetCredentialsCount(
        [In] MI_DestinationOptions* options,
        [NativeTypeName("MI_Uint32*"), Out] uint* count);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_DestinationOptionsFT_GetCredentialsAt(
        [In] MI_DestinationOptions* options,
        [NativeTypeName("MI_Uint32")] uint index,
        [NativeTypeName("const MI_Char**"), Out] char** optionName,
        [Out] MI_UserCredentials* credentials,
        [NativeTypeName("MI_Uint32*"), Out, Optional] uint* flags);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_DestinationOptionsFT_GetCredentialsPasswordAt(
        [In] MI_DestinationOptions* options,
        [NativeTypeName("MI_Uint32")] uint index,
        [NativeTypeName("const MI_Char**"), Out] char** optionName,
        [NativeTypeName("MI_Char*"), Out, Optional, NativeArrayInfo(CountParamIndex = 4), NotNullTerminated] char* password,
        [NativeTypeName("MI_Uint32"), In] uint bufferLength,
        [NativeTypeName("MI_Uint32*"), Out] uint* passwordLength,
        [NativeTypeName("MI_Uint32*"), Out, Optional] uint* flags);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_DestinationOptionsFT_Clone(
        [NativeTypeName("const MI_DestinationOptions*"), In] MI_DestinationOptions* self,
        [Out] MI_DestinationOptions* newDestinationOptions);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_DestinationOptionsFT_SetInterval(
        [In, Out] MI_DestinationOptions* options,
        [NativeTypeName("const MI_Char*"), In] char* optionName,
        [NativeTypeName("const MI_Interval*"), In] MI_Interval* value,
        [NativeTypeName("MI_Uint32")] uint flags);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_DestinationOptionsFT_GetInterval(
        [In] MI_DestinationOptions* options,
        [NativeTypeName("const MI_Char*"), In] char* optionName,
        [Out] MI_Interval* value,
        [NativeTypeName("MI_Uint32*"), Out, Optional] uint* index,
        [NativeTypeName("MI_Uint32*"), Out, Optional] uint* flags);

    // MI_OperationOptionsFT

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate void MI_OperationOptionsFT_Delete(
        [In, Out] MI_OperationOptions* options);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_OperationOptionsFT_SetString(
        [In, Out] MI_OperationOptions* options,
        [NativeTypeName("const MI_Char*"), In] char* optionName,
        [NativeTypeName("const MI_Char*"), In] char* value,
        [NativeTypeName("MI_Uint32")] uint flags);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_OperationOptionsFT_SetNumber(
        [In, Out] MI_OperationOptions* options,
        [NativeTypeName("const MI_Char*"), In] char* optionName,
        [NativeTypeName("MI_Uint32"), In] uint value,
        [NativeTypeName("MI_Uint32")] uint flags);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_OperationOptionsFT_SetCustomOption(
        [In, Out] MI_OperationOptions* options,
        [NativeTypeName("const MI_Char*"), In] char* optionName,
        [In] MI_Type valueType,
        [NativeTypeName("const MI_Value*"), In] MI_Value* value,
        [NativeTypeName("MI_Boolean")] byte mustComply,
        [NativeTypeName("MI_Uint32")] uint flags);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_OperationOptionsFT_GetString(
        [In] MI_OperationOptions* options,
        [NativeTypeName("const MI_Char*"), In] char* optionName,
        [NativeTypeName("const MI_Char**"), Out] char** value,
        [NativeTypeName("MI_Uint32*"), Out, Optional] uint* index,
        [NativeTypeName("MI_Uint32*"), Out, Optional] uint* flags);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_OperationOptionsFT_GetNumber(
        [In] MI_OperationOptions* options,
        [NativeTypeName("const MI_Char*"), In] char* optionName,
        [NativeTypeName("MI_Uint32*"), Out] uint* value,
        [NativeTypeName("MI_Uint32*"), Out, Optional] uint* index,
        [NativeTypeName("MI_Uint32*"), Out, Optional] uint* flags);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_OperationOptionsFT_GetOptionCount(
        [In] MI_OperationOptions* options,
        [NativeTypeName("MI_Uint32*"), Out] uint* count);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_OperationOptionsFT_GetOptionAt(
        [In] MI_OperationOptions* options,
        [NativeTypeName("MI_Uint32")] uint index,
        [NativeTypeName("const MI_Char**"), Out] char** optionName,
        [Out] MI_Value* value,
        [Out] MI_Type* @type,
        [NativeTypeName("MI_Uint32*"), Out, Optional] uint* flags);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_OperationOptionsFT_GetOption(
        [In] MI_OperationOptions* options,
        [NativeTypeName("const MI_Char*"), In] char* optionName,
        [Out] MI_Value* value,
        [Out] MI_Type* @type,
        [NativeTypeName("MI_Uint32*"), Out, Optional] uint* index,
        [NativeTypeName("MI_Uint32*"), Out, Optional] uint* flags);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_OperationOptionsFT_GetEnabledChannels(
        [In] MI_OperationOptions* options,
        [NativeTypeName("const MI_Char*"), In] char* optionName,
        [NativeTypeName("MI_Uint32*"), Out, Optional, NativeArrayInfo(CountParamIndex = 3)] uint* channels,
        [NativeTypeName("MI_Uint32"), In] uint bufferLength,
        [NativeTypeName("MI_Uint32*"), Out] uint* channelCount,
        [NativeTypeName("MI_Uint32*"), Out, Optional] uint* flags);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_OperationOptionsFT_Clone(
        [NativeTypeName("const MI_OperationOptions*"), In] MI_OperationOptions* self,
        [Out] MI_OperationOptions* newOperationOptions);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_OperationOptionsFT_SetInterval(
        [In, Out] MI_OperationOptions* options,
        [NativeTypeName("const MI_Char*"), In] char* optionName,
        [NativeTypeName("const MI_Interval*"), In] MI_Interval* value,
        [NativeTypeName("MI_Uint32")] uint flags);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_OperationOptionsFT_GetInterval(
        [In] MI_OperationOptions* options,
        [NativeTypeName("const MI_Char*"), In] char* optionName,
        [Out] MI_Interval* value,
        [NativeTypeName("MI_Uint32*"), Out, Optional] uint* index,
        [NativeTypeName("MI_Uint32*"), Out, Optional] uint* flags);

    // MI_UtilitiesFT

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_ErrorCategory MI_UtilitiesFT_MapErrorToMiErrorCategory(
        [NativeTypeName("MI_Char*"), In] char* errorType,
        [NativeTypeName("MI_Uint32")] uint error);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate MI_Result MI_UtilitiesFT_CimErrorFromErrorCode(
        [NativeTypeName("MI_Uint32")] uint error,
        [NativeTypeName("const MI_Char*"), In] char* errorType,
        [NativeTypeName("const MI_Char*"), In] char* errorMessage,
        [Out] MI_Instance** cimError);
}
