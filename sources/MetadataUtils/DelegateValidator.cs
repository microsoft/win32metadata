using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Reflection.Metadata;

namespace MetadataUtils
{
    public static class DelegateValidator
    {
        public static IEnumerable<DelegateTypeInfo> FindEmptyDelegates(
            IEnumerable<TypeInfo> types, IEnumerable<string> allowItems)
        {
            var allowTable = new HashSet<string>(allowItems, StringComparer.Ordinal);
            return types.OfType<DelegateTypeInfo>().Where(type =>
                type.MethodSignature.ParameterTypes.Length == 0 &&
                !allowTable.Contains(type.Name) &&
                !allowTable.Contains($"{type.Namespace}.{type.Name}"));
        }

        public static IEnumerable<DelegatePointerInfo> FindPointersToDelegates(
            IEnumerable<TypeInfo> types, IEnumerable<string> allowItems)
        {
            var allTypes = types.ToArray();
            var delegateNames = new HashSet<string>(
                allTypes.OfType<DelegateTypeInfo>().Select(type => $"{type.Namespace}.{type.Name}"),
                StringComparer.Ordinal);
            var allowTable = new HashSet<string>(allowItems, StringComparer.Ordinal);

            foreach (var type in allTypes)
            {
                foreach (var pointer in FindPointers(delegateNames, type))
                {
                    // Existing method/delegate entries allow the whole signature, not a leaf name.
                    if (!allowTable.Contains(pointer.Name))
                    {
                        yield return pointer;
                    }
                }
            }
        }

        private static bool IsPointerToDelegate(HashSet<string> delegateNames, string type)
        {
            int starIndex = type.IndexOf('*');
            return starIndex >= 0 && delegateNames.Contains(type.Substring(0, starIndex));
        }

        private static IEnumerable<DelegatePointerInfo> FindParameterPointers(
            HashSet<string> delegateNames, string name, MethodSignature<string> signature,
            IEnumerable<ParameterInfo> parameterInfos)
        {
            var parameters = parameterInfos.ToArray();
            if (parameters.Length != signature.ParameterTypes.Length)
            {
                throw new InvalidOperationException($"Parameter information does not match the signature for {name}.");
            }

            for (int i = 0; i < signature.ParameterTypes.Length; i++)
            {
                string type = signature.ParameterTypes[i];
                string typeToTest = type;
                if (parameters[i].Attributes.HasFlag(ParameterAttributes.Out) && typeToTest.EndsWith('*'))
                {
                    // An output slot accounts for exactly one pointer layer.
                    typeToTest = typeToTest.Substring(0, typeToTest.Length - 1);
                }

                if (IsPointerToDelegate(delegateNames, typeToTest))
                {
                    yield return new DelegatePointerInfo(name, type, parameters[i].Name, i + 1);
                }
            }
        }

        private static IEnumerable<DelegatePointerInfo> FindPointers(HashSet<string> delegateNames, TypeInfo type)
        {
            string name = $"{type.Namespace}.{type.Name}";
            if (type is StructInfo structInfo)
            {
                foreach (var field in structInfo.Fields)
                {
                    if (IsPointerToDelegate(delegateNames, field.Type))
                    {
                        yield return new DelegatePointerInfo($"{name}.{field.Name}", field.Type);
                    }
                }
            }
            else
            {
                IEnumerable<MethodInfo> methods;
                if (type is DelegateTypeInfo delegateInfo)
                {
                    foreach (var pointer in FindParameterPointers(
                        delegateNames, name, delegateInfo.MethodSignature, delegateInfo.Parameters))
                    {
                        yield return pointer;
                    }

                    yield break;
                }
                else if (type is InterfaceInfo interfaceInfo)
                {
                    methods = interfaceInfo.Methods;
                }
                else if (type is ClassInfo classInfo)
                {
                    methods = classInfo.Methods;
                }
                else
                {
                    yield break;
                }

                foreach (var method in methods)
                {
                    foreach (var pointer in FindParameterPointers(
                        delegateNames, $"{name}.{method.Name}", method.MethodSignature, method.Parameters))
                    {
                        yield return pointer;
                    }
                }
            }
        }
    }

    public sealed class DelegatePointerInfo
    {
        public DelegatePointerInfo(string name, string type, string parameterName = null, int? parameterSequence = null)
        {
            this.Name = name;
            this.Type = type;
            this.ParameterName = parameterName;
            this.ParameterSequence = parameterSequence;
        }

        public string Name { get; }
        public string Type { get; }
        public string ParameterName { get; }
        public int? ParameterSequence { get; }
    }
}
