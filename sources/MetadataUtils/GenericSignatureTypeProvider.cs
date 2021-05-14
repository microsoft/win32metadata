using System;
using System.Collections.Immutable;
using System.Reflection.Metadata;
using System.Text;

namespace MetadataUtils
{
    public class GenericContext
    {
        public GenericContext(ImmutableArray<string> typeParameters, ImmutableArray<string> methodParameters)
        {
            MethodParameters = methodParameters;
            TypeParameters = typeParameters;
        }

        public ImmutableArray<string> MethodParameters { get; }
        public ImmutableArray<string> TypeParameters { get; }
    }

    public class GenericSignatureTypeProvider : ISignatureTypeProvider<string, GenericContext>
    {
        public virtual string GetPrimitiveType(PrimitiveTypeCode typeCode)
        {
            switch (typeCode)
            {
                case PrimitiveTypeCode.Boolean:
                    return "bool";

                case PrimitiveTypeCode.Byte:
                    return "byte";

                case PrimitiveTypeCode.Char:
                    return "char";

                case PrimitiveTypeCode.Double:
                    return "double";

                case PrimitiveTypeCode.Int16:
                    return "uint";

                case PrimitiveTypeCode.Int32:
                    return "int";

                case PrimitiveTypeCode.Int64:
                    return "long";

                case PrimitiveTypeCode.IntPtr:
                    return "IntPtr";

                case PrimitiveTypeCode.Object:
                    return "object";

                case PrimitiveTypeCode.SByte:
                    return "byte";

                case PrimitiveTypeCode.Single:
                    return "float";

                case PrimitiveTypeCode.String:
                    return "string";

                case PrimitiveTypeCode.TypedReference:
                    return "typedref";

                case PrimitiveTypeCode.UInt16:
                    return "ushort";

                case PrimitiveTypeCode.UInt32:
                    return "uint";

                case PrimitiveTypeCode.UInt64:
                    return "ulong";

                case PrimitiveTypeCode.UIntPtr:
                    return "UIntPtr";

                case PrimitiveTypeCode.Void:
                    return "void";

                default:
                    throw new ArgumentOutOfRangeException(nameof(typeCode));
            }
        }

        public virtual string GetTypeFromDefinition(MetadataReader reader, TypeDefinitionHandle handle, byte rawTypeKind = 0)
        {
            TypeDefinition definition = reader.GetTypeDefinition(handle);

            string name = definition.Namespace.IsNil
                ? reader.GetString(definition.Name)
                : reader.GetString(definition.Namespace) + "." + reader.GetString(definition.Name);

            if (definition.IsNested)
            {
                TypeDefinitionHandle declaringTypeHandle = definition.GetDeclaringType();
                return GetTypeFromDefinition(reader, declaringTypeHandle, 0) + "/" + name;
            }

            return name;
        }

        public virtual string GetTypeFromReference(MetadataReader reader, TypeReferenceHandle handle, byte rawTypeKind = 0)
        {
            TypeReference reference = reader.GetTypeReference(handle);
            Handle scope = reference.ResolutionScope;

            string name = reference.Namespace.IsNil
                ? reader.GetString(reference.Name)
                : reader.GetString(reference.Namespace) + "." + reader.GetString(reference.Name);

            switch (scope.Kind)
            {
                case HandleKind.ModuleReference:
                    return "[.module  " + reader.GetString(reader.GetModuleReference((ModuleReferenceHandle)scope).Name) + "]" + name;

                case HandleKind.AssemblyReference:
                    var assemblyReferenceHandle = (AssemblyReferenceHandle)scope;
                    var assemblyReference = reader.GetAssemblyReference(assemblyReferenceHandle);
                    return "[" + reader.GetString(assemblyReference.Name) + "]" + name;

                case HandleKind.TypeReference:
                    return GetTypeFromReference(reader, (TypeReferenceHandle)scope) + "/" + name;

                default:
                    return name;
            }
        }

        public virtual string GetTypeFromSpecification(MetadataReader reader, GenericContext genericContext, TypeSpecificationHandle handle, byte rawTypeKind = 0)
        {
            return reader.GetTypeSpecification(handle).DecodeSignature(this, genericContext);
        }

        public virtual string GetSZArrayType(string elementType)
        {
            return elementType + "[]";
        }

        public virtual string GetPointerType(string elementType)
        {
            return elementType + "*";
        }

        public virtual string GetByReferenceType(string elementType)
        {
            return elementType + "&";
        }

        public virtual string GetGenericMethodParameter(GenericContext genericContext, int index)
        {
            return "!!" + (genericContext == null ? index.ToString() : genericContext.MethodParameters[index]);
        }

        public virtual string GetGenericTypeParameter(GenericContext genericContext, int index)
        {
            return "!" + (genericContext == null ? index.ToString() : genericContext.TypeParameters[index]);
        }

        public virtual string GetPinnedType(string elementType)
        {
            return elementType + " pinned";
        }

        public virtual string GetGenericInstance(string genericType, ImmutableArray<string> typeArguments)
        {
            return genericType + "<" + string.Join(",", typeArguments) + ">";
        }

        public virtual string GetArrayType(string elementType, ArrayShape shape)
        {
            var builder = new StringBuilder();

            builder.Append(elementType);
            builder.Append('[');

            for (int i = 0; i < shape.Rank; i++)
            {
                int lowerBound = 0;

                if (i < shape.LowerBounds.Length)
                {
                    lowerBound = shape.LowerBounds[i];
                    builder.Append(lowerBound);
                }

                builder.Append("...");

                if (i < shape.Sizes.Length)
                {
                    builder.Append(lowerBound + shape.Sizes[i] - 1);
                }

                if (i < shape.Rank - 1)
                {
                    builder.Append(',');
                }
            }

            builder.Append(']');
            return builder.ToString();
        }

        public virtual string GetTypeFromHandle(MetadataReader reader, GenericContext genericContext, EntityHandle handle)
        {
            switch (handle.Kind)
            {
                case HandleKind.TypeDefinition:
                    return GetTypeFromDefinition(reader, (TypeDefinitionHandle)handle);

                case HandleKind.TypeReference:
                    return GetTypeFromReference(reader, (TypeReferenceHandle)handle);

                case HandleKind.TypeSpecification:
                    return GetTypeFromSpecification(reader, genericContext, (TypeSpecificationHandle)handle);

                default:
                    throw new ArgumentOutOfRangeException(nameof(handle));
            }
        }

        public virtual string GetModifiedType(string modifierType, string unmodifiedType, bool isRequired)
        {
            return unmodifiedType + (isRequired ? " modreq(" : " modopt(") + modifierType + ")";
        }

        public virtual string GetFunctionPointerType(MethodSignature<string> signature)
        {
            ImmutableArray<string> parameterTypes = signature.ParameterTypes;

            int requiredParameterCount = signature.RequiredParameterCount;

            var builder = new StringBuilder();
            builder.Append("method ");
            builder.Append(signature.ReturnType);
            builder.Append(" *(");

            int i;
            for (i = 0; i < requiredParameterCount; i++)
            {
                builder.Append(parameterTypes[i]);
                if (i < parameterTypes.Length - 1)
                {
                    builder.Append(", ");
                }
            }

            if (i < parameterTypes.Length)
            {
                builder.Append("..., ");
                for (; i < parameterTypes.Length; i++)
                {
                    builder.Append(parameterTypes[i]);
                    if (i < parameterTypes.Length - 1)
                    {
                        builder.Append(", ");
                    }
                }
            }

            builder.Append(')');
            return builder.ToString();
        }

        public string GetGenericInstantiation(string genericType, ImmutableArray<string> typeArguments)
        {
            throw new NotImplementedException();
        }
    }
}