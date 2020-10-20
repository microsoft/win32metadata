using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;

namespace Microsoft.Windows.Sdk.CsWin32
{
    public class CsWin32Projector
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
            marshalAsAttrText = null;
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

                            //marshalAsAttrText = $"[MarshalAsAttribute(UnmanagedType.{unmanaged}, ArraySubType = {arraySubTypeText}, SizeParamIndex = {sizeParamIndex})]";
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

        private void VisitType(Type type, int indent = 0)
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
                this.VisitDelegate(type, indent);
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
                    this.VisitType(type, 0);
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
                        System.Console.WriteLine("Error: could not find RIAA close function: {closeFunc}");
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
                this.VisitMethod(methodInfo.Name, methodInfo, intro, indent);
            }
        }

        private void VisitMethod(string name, MethodInfo methodInfo, string intro, int indent)
        {
            string indentText = GetIndent(indent);

            var retParam = methodInfo.ReturnParameter;
            var retType = FixTypeName(retParam.CustomAttributes, retParam.ParameterType.Name);
            this.writer.Write($"{indentText}{intro} {retType} {name}(");
            var parameters = methodInfo.GetParameters();
            for (int i = 0; i < parameters.Length; i++)
            {
                var param = parameters[i];
                var paramType = FixTypeName(param.CustomAttributes, param.ParameterType.Name);
                var paramName = FixParamOrFieldName(param.Name);

                GetMarshalAsInfo(param.CustomAttributes, false, ref paramType, out string marshalAsAttrText);

                if (marshalAsAttrText != null)
                {
                    this.writer.Write(marshalAsAttrText);
                }

                bool canUseRefOrOut = true;
                if (paramType.StartsWith("void*") || paramType == "IntPtr" || paramType.Contains("[]"))
                {
                    canUseRefOrOut = false;
                }

                if (canUseRefOrOut)
                {
                    string refOrOut = null;
                    if (!param.IsIn && param.IsOut && !param.IsOptional)
                    {
                        refOrOut = "out";
                    }
                    else if (param.IsIn && param.IsOut && !param.IsOptional)
                    {
                        refOrOut = "ref";
                    }

                    if (refOrOut != null)
                    {
                        paramType = RemovePointer(paramType);
                        this.writer.Write($"{refOrOut} ");
                    }
                }

                this.writer.Write($"{paramType} {paramName}");
                if (i != parameters.Length - 1)
                {
                    this.writer.Write(", ");
                }
            }

            this.writer.WriteLine(");");
        }

        private void VisitDelegate(Type type, int indent)
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
            string intro = $"public unsafe delegate";
            this.VisitMethod(type.Name, invokeMethod, intro, indent);
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
            if (marshalAsAttrText != null)
            {
                this.writer.WriteLine($"{indentText}{marshalAsAttrText}");
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

            var name = type.Name;
            if (name == "LDT_ENTRY")
            {
                name = "LDT_ENTRY";
            }

            this.writer.Write(
$@"{indentText}public unsafe struct {name}
{indentText}{{
");

            var fields = type.GetFields();
            foreach (var field in fields)
            {
                this.VisitField(field, indent + 1);
            }

            foreach (var nestedType in type.GetNestedTypes())
            {
                this.VisitType(nestedType, indent + 1);
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
