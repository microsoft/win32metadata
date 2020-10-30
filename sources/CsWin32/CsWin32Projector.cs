using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Text;

namespace Microsoft.Windows.Sdk.CsWin32
{
    public static class TypeExtensions
    {
        public static IEnumerable<FieldInfo> GetConstants(this Type type)
        {
            var fieldInfos = type.GetFields(BindingFlags.Public | BindingFlags.Static | BindingFlags.FlattenHierarchy);

            return fieldInfos.Where(fi => fi.IsLiteral && !fi.IsInitOnly);
        }

        public static IEnumerable<FieldInfo> GetReadonlyStatics(this Type type)
        {
            var fieldInfos = type.GetFields(BindingFlags.Public | BindingFlags.Static | BindingFlags.FlattenHierarchy);

            return fieldInfos.Where(fi => !fi.IsLiteral && fi.IsInitOnly);
        }
    }

    public unsafe class CsWin32Projector
    {
        private StreamWriter writer;
        private Dictionary<string, string> riaaMappings = new Dictionary<string, string>();
        private HashSet<string> csKeywords = new HashSet<string>();
        private Type riaaFreeAttributeType;
        private Assembly metadataAssembly;

        private CsWin32Projector()
        {
            this.LoadKeywords();
        }

        public static void CreateProjectedSourceFromMetadata(string metadata, string riaMappingsFileName, string outputDir)
        {
            var proj = new CsWin32Projector();
            proj.CreateProjectedSourceFromMetadataImpl(metadata, riaMappingsFileName, outputDir);
        }

        private static string GetIndent(int indent)
        {
            const string Indent = "    ";
            string ret = Indent;
            for (int i = 0; i < indent; i++)
            {
                ret += Indent;
            }

            return ret;
        }

        private static void GetMarshalAsInfo(IEnumerable<CustomAttributeData> customAttributes, bool forStruct, ref string typeName, out string marshalAsAttrText)
        {
            var marshalAsAttr = customAttributes.FirstOrDefault(c => c.AttributeType == typeof(MarshalAsAttribute));
            marshalAsAttrText = string.Empty;
            if (marshalAsAttr != null)
            {
                var unmanagedTypeArg = marshalAsAttr.ConstructorArguments.FirstOrDefault(a => a.ArgumentType.Name == "UnmanagedType");
                if (unmanagedTypeArg != null)
                {
                    UnmanagedType unmanaged = (UnmanagedType)unmanagedTypeArg.Value;

                    if (!forStruct)
                    {
                        if (unmanaged == UnmanagedType.LPStr || unmanaged == UnmanagedType.LPWStr)
                        {
                            typeName = "string";
                            marshalAsAttrText = $"[MarshalAsAttribute(UnmanagedType.{unmanaged})]";
                        }
                        else if (unmanaged == UnmanagedType.LPArray)
                        {
                            var arraySubType = (UnmanagedType)marshalAsAttr.NamedArguments.Where(arg => arg.MemberName == "ArraySubType").First().TypedValue.Value;
                            short sizeParamIndex = (short)marshalAsAttr.NamedArguments.Where(arg => arg.MemberName == "SizeParamIndex").First().TypedValue.Value;
                            if (arraySubType == UnmanagedType.LPWStr)
                            {
                                typeName = typeName.Replace("UInt16", "char");
                                arraySubType = 0;
                            }
                            else if (arraySubType == UnmanagedType.LPStr)
                            {
                                arraySubType = 0;
                            }

                            if (!typeName.StartsWith("void") && !typeName.Contains("**"))
                            {
                                int starIndex = typeName.IndexOf('*');
                                if (starIndex != -1)
                                {
                                    var fixedName = typeName.Substring(0, starIndex) + "[]";
                                    if (starIndex != typeName.Length - 1)
                                    {
                                        fixedName += typeName.Substring(starIndex + 1);
                                    }

                                    typeName = fixedName;
                                }
                            }

                            string arraySubTypeText;
                            if (int.TryParse(arraySubType.ToString(), out _))
                            {
                                arraySubTypeText = $"(UnmanagedType){arraySubType}";
                            }
                            else
                            {
                                arraySubTypeText = $"UnmanagedType.{arraySubType}";
                            }

                            marshalAsAttrText = $"[MarshalAsAttribute(UnmanagedType.{unmanaged}, SizeParamIndex = {sizeParamIndex})]";
                        }
                    }
                    else
                    {
                        if (unmanaged == UnmanagedType.LPWStr)
                        {
                            typeName = "char*";
                        }
                        else if (unmanaged == UnmanagedType.LPStr)
                        {
                            typeName = "sbyte*";
                        }
                    }
                }
            }
        }

        private static string RemovePointer(string type)
        {
            if (type.EndsWith('*'))
            {
                return type.Substring(0, type.Length - 1);
            }

            return type;
        }

        private static bool HasComOutPtrs(MethodInfo methodInfo)
        {
            foreach (var param in methodInfo.GetParameters())
            {
                if (param.CustomAttributes.Any(c => c.AttributeType.Name == "ComOutPtrAttribute"))
                {
                    return true;
                }
            }

            return false;
        }

        private static bool HasVtbl(Type type)
        {
            if (type == null)
            {
                return false;
            }

            return type.GetField("lpVtbl") != null;
        }

        private string FixParamOrFieldName(string name)
        {
            if (this.csKeywords.Contains(name))
            {
                return "@" + name;
            }

            return name;
        }

        private void LoadKeywords()
        {
            string[] keywords = new string[] { "event", "string", "in", "out", "object", "internal", "override", "decimal", "base", "ref" };
            foreach (var keyword in keywords)
            {
                csKeywords.Add(keyword);
            }
        }

        private void LoadRiaaMappings(string fileName)
        {
            foreach (string line in File.ReadAllLines(fileName))
            {
                string[] items = line.Split('=');
                this.riaaMappings[items[0]] = items[1];
            }
        }

        private void VisitType(Type type, Type context, int indent = 0)
        {
            if (type.IsEnum)
            {
                this.VisitEnum(type);
            }
            else if (type.BaseType == typeof(System.ValueType))
            {
                this.VisitStruct(type, indent);
            }
            else if (type.BaseType == typeof(System.MulticastDelegate))
            {
                this.VisitDelegate(type, context, indent);
            }
            else if (type.BaseType == typeof(System.Attribute))
            {
                return;
            }
            else if (type.IsClass)
            {
                this.VisitClass(type, indent);
            }
            else
            {

            }
        }

        private void VisitConstant(FieldInfo fieldInfo, int indent)
        {
            string indentText = GetIndent(indent);

            this.writer.WriteLine();

            var value = fieldInfo.GetRawConstantValue();
            this.writer.Write($"{indentText}public const {fieldInfo.FieldType.Name} {fieldInfo.Name} = ");
            this.VisitStaticOrConstValue(value, fieldInfo);

            this.writer.WriteLine($";");
        }

        private void VisitStaticOrConstValue(object valueObject, FieldInfo fieldInfo)
        {
            string fieldTypeName = FixTypeName(null, fieldInfo.FieldType.Name);

            if (fieldInfo.FieldType == typeof(Guid))
            {
                this.writer.Write($"new Guid(\"{valueObject}\")");
            }
            else if (fieldInfo.FieldType == typeof(string))
            {
                this.writer.Write($"\"{valueObject}\"");
            }
            else
            {
                if (valueObject is System.Reflection.Pointer)
                {
                    void* pValue = System.Reflection.Pointer.Unbox(valueObject);
                    if (pValue == null)
                    {
                        this.writer.Write("null");
                    }
                    else
                    {
                        IntPtr temp = new IntPtr(pValue);
                        this.writer.Write(temp.ToString());
                    }
                }
                else
                {
                    var fields = valueObject.GetType().GetFields().Where(f => !f.IsStatic).ToArray();
                    if (fields.Length != 0)
                    {
                        this.writer.Write($" new {fieldTypeName} {{ ");
                        bool first = true;
                        foreach (var field in fields)
                        {
                            if (!first)
                            {
                                this.writer.Write(", ");
                            }

                            var fieldValue = field.GetValue(valueObject);
                            this.writer.Write($"{field.Name} = ");
                            this.VisitStaticOrConstValue(fieldValue, field);
                            first = false;
                        }

                        this.writer.Write(" }");
                    }
                    else
                    {
                        var fieldType = fieldInfo.FieldType;
                        if (fieldType.IsEnum)
                        {
                            this.writer.Write($"({fieldTypeName})({valueObject})");
                        }
                        else if (fieldType.IsValueType && !fieldType.IsPrimitive)
                        {
                            this.writer.Write($"new {fieldTypeName}()");
                        }
                        else
                        {
                            this.writer.Write(valueObject.ToString());
                            if (fieldTypeName == "Single")
                            {
                                this.writer.Write("F");
                            }
                        }
                    }
                }
            }
        }

        private void VisitReadonlyStatic(FieldInfo fieldInfo, int indent)
        {
            string indentText = GetIndent(indent);
            string fieldType = FixTypeName(null, fieldInfo.FieldType.Name);
            this.writer.WriteLine();
            this.writer.Write($"{indentText}public static readonly {fieldType} {fieldInfo.Name} = ");

            var value = fieldInfo.GetValue(null);
            this.VisitStaticOrConstValue(value, fieldInfo);

            this.writer.WriteLine($";");
        }

        private void VisitClass(Type type, int indent)
        {
            string indentText = GetIndent(indent);
            this.writer.Write(
@$"
{indentText}public static unsafe partial class {type.Name}
{indentText}{{");

            foreach (var method in type.GetMethods())
            {
                this.VisitClassMethod(method, indent + 1);
            }

            foreach (var constant in type.GetConstants())
            {
                this.VisitConstant(constant, indent + 1);
            }

            foreach (var item in type.GetReadonlyStatics())
            {
                this.VisitReadonlyStatic(item, indent + 1);
            }

            this.writer.WriteLine(
@$"{indentText}}}");
        }

        private void CreateProjectedSourceFromMetadataImpl(string metadata, string riaMappingsFileName, string outputDir)
        {
            this.LoadRiaaMappings(riaMappingsFileName);

            var outputFileName = Path.Combine(outputDir, "ProjectedWin32.cs");
            using (this.writer = new StreamWriter(outputFileName))
            {
                this.writer.Write(
@"// Copyright © Microsoft
using System;
using System.Runtime.InteropServices;

namespace Microsoft.Windows.Win32
{
");

                this.metadataAssembly = Assembly.LoadFile(metadata);
                this.riaaFreeAttributeType = this.metadataAssembly.GetType("Microsoft.Windows.Sdk.RIAAFreeAttribute");

                foreach (var type in this.metadataAssembly.GetExportedTypes())
                {
                    this.VisitType(type, null, 0);
                }

                this.writer.Write(
@"
}
");
            }

            this.WriteRiaaClasses(outputDir);
        }

        private void WriteRiaaClasses(string outputDir)
        {
            var apis = this.metadataAssembly.GetType("Microsoft.Windows.Sdk.Apis");

            var outputFileName = Path.Combine(outputDir, "RiaaSafeHandles.cs");
            using (var streamWriter = new StreamWriter(outputFileName))
            {
                streamWriter.Write(
@"// Copyright © Microsoft
using System;
using System.Runtime.CompilerServices;
using System.Runtime.ConstrainedExecution;
using System.Runtime.InteropServices;
using System.Security.Permissions;
using Microsoft.Win32.SafeHandles;

namespace Microsoft.Windows.Win32
{
");

                foreach (var mapping in this.riaaMappings)
                {
                    string closeFunc = mapping.Key;
                    string className = mapping.Value;
                    var methodInfo = apis.GetMethod(closeFunc);
                    if (methodInfo == null)
                    {
                        System.Console.WriteLine($"Error: could not find RIAA close function: {closeFunc}");
                        continue;
                    }

                    string cleanup;

                    if (methodInfo.ReturnType.Name.ToLowerInvariant() == "void")
                    {
                        cleanup =
$@"            
            Apis.{closeFunc}(this.handle);
            return true;";
                    }
                    else
                    {
                        cleanup =
$@"            
            return Apis.{closeFunc}(this.handle) != 0;";
                    }

                    // TODO: Cheating! Find a way to pass this in via attributes or something else
                    if (closeFunc == "ClosePrivateNamespace")
                    {
                        cleanup =
$@"            
            return Apis.{closeFunc}(this.handle, 1) != 0;";
                    }

                    streamWriter.Write(
@$"
    [SecurityPermission(SecurityAction.InheritanceDemand, UnmanagedCode = true)]
    [SecurityPermission(SecurityAction.Demand, UnmanagedCode = true)]
    public class {className} : SafeHandleZeroOrMinusOneIsInvalid
    {{
        private {className}() : base(true)
        {{
        }}

        [ReliabilityContract(Consistency.WillNotCorruptState, Cer.MayFail)]
        protected override bool ReleaseHandle()
        {{{cleanup}
        }}
    }}
");
                }

                streamWriter.Write(
@"
}
");
            }
        }

        private CharSet GetCharSetFromParams(MethodInfo methodInfo)
        {
            foreach (var param in methodInfo.GetParameters())
            {
                var marshalAsAttr = param.CustomAttributes.FirstOrDefault(c => c.AttributeType == typeof(MarshalAsAttribute));
                if (marshalAsAttr != null)
                {
                    var unmanagedTypeArg = marshalAsAttr.ConstructorArguments.FirstOrDefault(a => a.ArgumentType.Name == "UnmanagedType");
                    if (unmanagedTypeArg != null)
                    {
                        UnmanagedType unmanagedType = (UnmanagedType)unmanagedTypeArg.Value;
                        if (unmanagedType == UnmanagedType.LPStr)
                        {
                            return CharSet.Ansi;
                        }
                        else if (unmanagedType == UnmanagedType.LPWStr)
                        {
                            return CharSet.Unicode;
                        }
                        else if (unmanagedType == UnmanagedType.LPArray)
                        {
                            var arraySubType = (UnmanagedType)marshalAsAttr.NamedArguments.Where(arg => arg.MemberName == "ArraySubType").First().TypedValue.Value;
                            if (arraySubType == UnmanagedType.LPStr)
                            {
                                return CharSet.Ansi;
                            }
                            else if (arraySubType == UnmanagedType.LPWStr)
                            {
                                return CharSet.Unicode;
                            }
                        }
                    }
                }
            }

            return CharSet.None;
        }

        private void VisitClassMethod(MethodInfo methodInfo, int indent)
        {
            var dllImportAttr = methodInfo.CustomAttributes.FirstOrDefault(c => c.AttributeType == typeof(DllImportAttribute));
            if (dllImportAttr != null)
            {
                this.writer.WriteLine();
                string indentText = GetIndent(indent);

                var dllName = dllImportAttr.ConstructorArguments[0].Value.ToString();
                var entryPoint = dllImportAttr.NamedArguments.Where(arg => arg.MemberName == "EntryPoint").First().TypedValue.Value.ToString();
                var charSet = (System.Runtime.InteropServices.CharSet)dllImportAttr.NamedArguments.Where(arg => arg.MemberName == "CharSet").First().TypedValue.Value;
                if (charSet == CharSet.None)
                {
                    charSet = GetCharSetFromParams(methodInfo);
                }

                var exactSpelling = dllImportAttr.NamedArguments.Where(arg => arg.MemberName == "ExactSpelling").First().TypedValue.Value.ToString().ToLowerInvariant();
                var setLastError = dllImportAttr.NamedArguments.Where(arg => arg.MemberName == "SetLastError").First().TypedValue.Value.ToString().ToLowerInvariant();
                string dllImportAttrText = $"[DllImport(\"{dllName}\", EntryPoint = \"{entryPoint}\", CharSet = CharSet.{charSet}, ExactSpelling = {exactSpelling}, SetLastError = {setLastError})]";

                this.writer.WriteLine($"{indentText}{dllImportAttrText}");

                string intro = $"public static extern";
                this.VisitMethod(methodInfo.Name, methodInfo, intro, indent, out var functionEmitInfo);

                if (HasComOutPtrs(methodInfo))
                {
                    this.writer.WriteLine();
                    this.EmitFunctionCall(methodInfo.Name, functionEmitInfo, "public static", indent, null);
                }
            }
        }

        private void EmitFunctionCall(string name, FunctionEmitInfo functionEmitInfo, string intro, int indent, string vtblInterfaceName)
        {
            bool usesGenericType = functionEmitInfo.Params.Any(p => p.FriendlyType.Contains("<T>"));
            bool fixupNeeded = functionEmitInfo.FixupNeeded;

            string indentText = GetIndent(indent);
            string paramsTxt = functionEmitInfo.EmitParamsForSignature(true, true);
            if (name == "GetType" && (vtblInterfaceName != null && functionEmitInfo.Params.Count == 1))
            {
                intro = $"{intro} new";
            }

            string returnType = functionEmitInfo.ReturnType;
            if (fixupNeeded)
            {
                returnType = RemovePointer(returnType);
            }

            this.writer.Write($"{indentText}{intro} {returnType} {name}");
            if (usesGenericType)
            {
                this.writer.Write("<T>");
            }

            this.writer.Write($"({paramsTxt})");
            if (usesGenericType)
            {
                this.writer.Write("  where T : unmanaged");
            }
            this.writer.WriteLine();

            this.writer.WriteLine($"{indentText}{{");

            string indentText1 = GetIndent(indent + 1);
            bool returnNeeded = functionEmitInfo.ReturnType != "void";
            string retEQ = string.Empty;
            if (returnNeeded)
            {
                this.writer.WriteLine($"{indentText1}{returnType} __result__;");
                retEQ = "__result__ = ";
                if (fixupNeeded)
                {
                    retEQ += "*";
                }
            }

            var comParams = functionEmitInfo.Params.Where(p => p.IsComPtr);
            foreach (var comParam in comParams)
            {
                this.writer.WriteLine($"{indentText1}{comParam.Type} {comParam.Name}Raw;");
            }

            if (vtblInterfaceName != null)
            {
                this.writer.WriteLine($"{indentText1}fixed ({vtblInterfaceName}* pThis = &this)");
                this.writer.WriteLine($"{indentText1}{{");

                string indentText2 = GetIndent(indent + 2);
                string paramText = functionEmitInfo.EmitParamsForCall(true);
                this.writer.WriteLine($"{indentText2}{retEQ}Marshal.GetDelegateForFunctionPointer<_{name}>(lpVtbl->{name})({paramText});");
                this.writer.WriteLine($"{indentText1}}}");
            }
            else
            {
                string paramText = functionEmitInfo.EmitParamsForCall(true);
                this.writer.WriteLine($"{indentText1}{retEQ}{name}({paramText});");
            }

            foreach (var comParam in comParams)
            {
                this.writer.WriteLine($"{indentText1}{comParam.Name} = new {comParam.FriendlyType}({comParam.Name}Raw);");
            }

            if (returnNeeded)
            {
                this.writer.WriteLine($"{indentText1}return __result__;");
            }

            this.writer.WriteLine($"{indentText}}}");
        }

        private void EmitVtblCall(string name, FunctionEmitInfo functionEmitInfo, int indent)
        {
            string fixedName = name.Substring(1);

            if (fixedName == "GetCPUDescriptorHandleForHeapStart")
            {
            }

            string interfaceName = RemovePointer(functionEmitInfo.Params[0].Type);

            this.writer.WriteLine();
            this.EmitFunctionCall(fixedName, functionEmitInfo, "public", indent, interfaceName);
        }

        private class FunctionEmitInfo
        {
            public string ReturnType { get; set; }

            public List<ParameterEmitInfo> Params { get; set; }

            public string EmitParamsForSignature(bool useFriendlyTypes, bool skipThis)
            {
                StringBuilder ret = new StringBuilder();
                bool first = true;
                int paramCount = this.Params.Count;
                if (useFriendlyTypes && this.FixupNeeded)
                {
                    paramCount--;
                }

                for (int i = 0; i < paramCount; i++)
                {
                    var param = this.Params[i];

                    if (!first)
                    {
                        ret.Append(", ");
                    }

                    if (skipThis && param.Name == "pThis")
                    {
                        continue;
                    }

                    string paramType = useFriendlyTypes ? param.FriendlyType : param.Type;
                    ret.Append($"{param.Attributes}{param.RefOrOut}{paramType} {param.Name}");
                    first = false;
                }

                return ret.ToString();
            }

            public string EmitParamsForCall(bool useFriendlyTypes)
            {
                StringBuilder ret = new StringBuilder();
                bool first = true;
                bool fixupNeeded = this.FixupNeeded;
                for (int i = 0; i < this.Params.Count; i++)
                {
                    var param = this.Params[i];
                    if (!first)
                    {
                        ret.Append(", ");
                    }

                    string suffix = string.Empty;
                    if (param.IsComPtr)
                    {
                        suffix = "Raw";
                    }

                    string paramName = param.Name;
                    if (fixupNeeded && i == this.Params.Count - 1)
                    {
                        paramName = "&__result__";
                    }

                    ret.Append($"{param.RefOrOut}{paramName}{suffix}");
                    first = false;
                }

                return ret.ToString();
            }

            public bool FixupNeeded
            {
                get
                {
                    bool fixupNeeded = false;
                    var lastParam = this.Params.LastOrDefault();
                    if (lastParam != null)
                    {
                        fixupNeeded = lastParam.Name == "_result" && lastParam.Type == this.ReturnType && lastParam.Type.EndsWith("*");
                    }

                    if (fixupNeeded)
                    {
                    }

                    return fixupNeeded;
                }
            }
        }

        private class ParameterEmitInfo
        {
            public string Name { get; set; }
            public string Attributes { get; set; }
            public string RefOrOut { get; set; }
            public string Type { get; set; }
            public string FriendlyType
            {
                get
                {
                    if (!this.IsComPtr)
                    {
                        return this.Type;
                    }

                    if (this.Type == "void*")
                    {
                        return "ComPtr<T>";
                    }
                    else
                    {
                        string interfaceType = RemovePointer(this.Type);
                        return $"ComPtr<{interfaceType}>";
                    }
                }
            }

            public bool IsComPtr { get; set; }
        }

        private ParameterEmitInfo GetParameterEmitInfo(ParameterInfo param)
        {
            var paramType = FixTypeName(param.CustomAttributes, param.ParameterType.Name);
            var paramName = FixParamOrFieldName(param.Name);

            GetMarshalAsInfo(param.CustomAttributes, false, ref paramType, out string marshalAsAttrText);

            bool canUseRefOrOut = true;
            bool isComOutPtr = param.CustomAttributes.Any(c => c.AttributeType.Name == "ComOutPtrAttribute");

            if (paramType == "void*" ||
                paramType == "IntPtr" ||
                paramType.Contains("[]"))
            {
                canUseRefOrOut = false;
            }

            string refOrOut = string.Empty;
            if (canUseRefOrOut)
            {
                if ((!param.IsIn && param.IsOut && !param.IsOptional) || isComOutPtr)
                {
                    refOrOut = "out ";
                }
                else if (param.IsIn && param.IsOut && !param.IsOptional)
                {
                    refOrOut = "ref ";
                }

                if (!string.IsNullOrEmpty(refOrOut))
                {
                    paramType = RemovePointer(paramType);
                }
            }

            // Pointer types can't have marshal as
            if (paramType.Contains("*"))
            {
                marshalAsAttrText = string.Empty;
            }

            return new ParameterEmitInfo() { Attributes = marshalAsAttrText, IsComPtr = isComOutPtr, Name = paramName, Type = paramType, RefOrOut = refOrOut };
        }

        private List<ParameterEmitInfo> GetMethodParamEmitInfos(MethodInfo methodInfo)
        {
            List<ParameterEmitInfo> paramInfos = new List<ParameterEmitInfo>();
            foreach (var param in methodInfo.GetParameters())
            {
                paramInfos.Add(GetParameterEmitInfo(param));
            }

            return paramInfos;
        }

        private FunctionEmitInfo GetMethodEmitInfo(MethodInfo methodInfo)
        {
            var retParam = methodInfo.ReturnParameter;
            var retType = FixTypeName(retParam.CustomAttributes, retParam.ParameterType.Name);
            FunctionEmitInfo ret = new FunctionEmitInfo() { ReturnType = retType };
            ret.Params = GetMethodParamEmitInfos(methodInfo);

            return ret;
        }

        private void VisitMethod(string name, MethodInfo methodInfo, string intro, int indent, out FunctionEmitInfo emitInfo)
        {
            emitInfo = GetMethodEmitInfo(methodInfo);

            if (name == "GetType" && methodInfo.GetParameters().Length == 0)
            {
                intro = $"{intro} new";
            }

            string indentText = GetIndent(indent);
            string paramsTxt = emitInfo.EmitParamsForSignature(false, false);
            this.writer.WriteLine($"{indentText}{intro} {emitInfo.ReturnType} {name}({paramsTxt});");
        }

        private void VisitDelegate(Type type, Type context, int indent)
        {
            if (indent == 0 && type.IsNested)
            {
                return;
            }

            this.writer.WriteLine();

            string indentText = GetIndent(indent);

            var unmanagedFuncPtrAttr = type.CustomAttributes.FirstOrDefault(c => c.AttributeType == typeof(UnmanagedFunctionPointerAttribute));
            if (unmanagedFuncPtrAttr != null)
            {
                var callingConvArg = unmanagedFuncPtrAttr.ConstructorArguments.FirstOrDefault(a => a.ArgumentType.Name == "CallingConvention");
                if (callingConvArg != null)
                {
                    CallingConvention callingConv = (CallingConvention)callingConvArg.Value;

                    this.writer.WriteLine($"{indentText}[UnmanagedFunctionPointer(CallingConvention.{callingConv})]");
                }
            }

            var invokeMethod = type.GetMethod("Invoke");
            string intro = context == null ? $"public unsafe delegate" : "public delegate";
            this.VisitMethod(type.Name, invokeMethod, intro, indent, out var functionEmitInfo);

            if (HasVtbl(context))
            {
                this.EmitVtblCall(type.Name, functionEmitInfo, indent);
            }
        }

        private string FixTypeName(IEnumerable<CustomAttributeData> attributes, string name)
        {
            string ret = name.Replace("Microsoft.Windows.Sdk.", string.Empty);
            int plus = name.IndexOf('+');
            if (plus != -1)
            {
                name = name.Substring(plus + 1);
            }

            int starIndex = name.IndexOf('*');
            string baseName = name;
            string suffix = string.Empty;
            if (starIndex != -1)
            {
                baseName = name.Substring(0, starIndex);
                suffix = name.Substring(starIndex);
            }

            if (baseName == "Void")
            {
                baseName = "void";
            }

            if (attributes != null)
            {
                var riaaFreeAttrData = attributes.FirstOrDefault(data => data.AttributeType == this.riaaFreeAttributeType);
                if (riaaFreeAttrData != null)
                {
                    var riaaFunction = riaaFreeAttrData.ConstructorArguments[0].Value.ToString();
                    if (!this.riaaMappings.TryGetValue(riaaFunction, out string safeHandleClassName))
                    {
                        System.Console.WriteLine($"Error: no mapping found for RIAA fuction {riaaFunction}.");
                    }
                    else
                    {
                        baseName = safeHandleClassName;
                    }
                }
            }

            string finalName = baseName + suffix;
            return finalName;
        }

        private void VisitField(FieldInfo field, int indent)
        {
            string indentText = GetIndent(indent);
            var fixedBufferAttr = field.CustomAttributes.FirstOrDefault(c => c.AttributeType == typeof(System.Runtime.CompilerServices.FixedBufferAttribute));
            string typeName;
            string fieldName = FixParamOrFieldName(field.Name);

            var fieldOffsetAttr = field.CustomAttributes.FirstOrDefault(c => c.AttributeType == typeof(FieldOffsetAttribute));
            if (fieldOffsetAttr != null)
            {
                var count = fieldOffsetAttr.ConstructorArguments[0].Value;
                this.writer.WriteLine($"{indentText}[FieldOffset({count})]");
            }

            if (fixedBufferAttr != null)
            {
                var bufferType = fixedBufferAttr.ConstructorArguments[0].Value;
                var count = fixedBufferAttr.ConstructorArguments[1].Value;
                typeName = $"fixed {bufferType}";
                fieldName = $"{fieldName}[{count}]";
            }
            else
            {
                typeName = FixTypeName(field.CustomAttributes, field.FieldType.Name);
            }

            GetMarshalAsInfo(field.CustomAttributes, true, ref typeName, out string marshalAsAttrText);
            if (!string.IsNullOrEmpty(marshalAsAttrText))
            {
                this.writer.WriteLine($"{indentText}{marshalAsAttrText}");
            }

            if (fieldName == "GetType")
            {
                typeName = $"new {typeName}";
            }

            this.writer.WriteLine(
$@"{indentText}public {typeName} {fieldName};");
        }

        private void VisitStruct(Type type, int indent = 0)
        {
            if (indent == 0 && type.IsNested)
            {
                return;
            }

            bool compilerGenerated = type.CustomAttributes.Any(attr => attr.AttributeType == typeof(CompilerGeneratedAttribute));
            if (compilerGenerated)
            {
                return;
            }

            this.writer.WriteLine();

            string indentText = GetIndent(indent);
            if (type.Attributes.HasFlag(TypeAttributes.ExplicitLayout))
            {
                this.writer.WriteLine(
$"{indentText}[StructLayout(LayoutKind.Explicit)]");
            }

            var guidAttrData = type.CustomAttributes.FirstOrDefault(c => c.AttributeType == typeof(GuidAttribute));
            if (guidAttrData != null)
            {
                var guid = guidAttrData.ConstructorArguments[0].Value.ToString();
                this.writer.WriteLine(
$"{indentText}[Guid(\"{guid}\")]");
            }

            var name = type.Name;

            this.writer.Write(
$@"{indentText}public unsafe partial struct {name}
{indentText}{{
");

            var fields = type.GetFields();
            foreach (var field in fields)
            {
                this.VisitField(field, indent + 1);
            }

            foreach (var nestedType in type.GetNestedTypes())
            {
                this.VisitType(nestedType, type, indent + 1);
            }

            this.writer.WriteLine(
$"{indentText}}}");
        }

        private void VisitEnum(Type type)
        {
            var flagsAttr = type.GetCustomAttribute(typeof(FlagsAttribute));
            var fields = type.GetFields();
            var typeField = fields.First(f => f.Name == "value__");
            this.writer.WriteLine();

            if (flagsAttr != null)
            {
                this.writer.WriteLine(
"    [Flags]");
            }

            this.writer.Write(
$@"    public enum {type.Name} : {typeField.FieldType.FullName}
    {{
");

            foreach (var field in fields.Where(f => f.IsLiteral))
            {
                var val = field.GetRawConstantValue();
                this.writer.WriteLine(
$@"        {field.Name} = {val},");
            }

            this.writer.WriteLine(
"    }");
        }
    }
}
