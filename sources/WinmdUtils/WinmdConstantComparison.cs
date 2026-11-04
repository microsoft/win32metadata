using System;
using System.Globalization;
using System.Reflection;
using System.Reflection.Metadata;
using System.Text.Json;

namespace WinmdUtilsProgram
{
    internal static class WinmdConstantComparison
    {
        internal static void Compare(
            string name,
            string declaredType1, MetadataReader reader1, FieldDefinitionHandle handle1,
            string declaredType2, MetadataReader reader2, FieldDefinitionHandle handle2,
            Action<string> report)
        {
            // ReflectionName preserves the declared name even for unresolved architecture-specific types.
            if (declaredType1 != declaredType2)
                report($"{name}...{declaredType1} => {declaredType2}");

            var field1 = reader1.GetFieldDefinition(handle1);
            var field2 = reader2.GetFieldDefinition(handle2);
            bool literal1 = (field1.Attributes & FieldAttributes.Literal) != 0;
            bool literal2 = (field2.Attributes & FieldAttributes.Literal) != 0;
            if (literal1 != literal2)
                report($"{name} : literal...{literal1} => {literal2}");

            var constant1 = Read(reader1, field1.GetDefaultValue());
            var constant2 = Read(reader2, field2.GetDefaultValue());
            if (literal1 && constant1 == null)
                report($"winmd1: {name} is literal without a Constant row");
            if (literal2 && constant2 == null)
                report($"winmd2: {name} is literal without a Constant row");
            if ((constant1 == null) != (constant2 == null))
                report($"{name} : Constant row...{(constant1 == null ? "missing" : "present")} => {(constant2 == null ? "missing" : "present")}");
            if (constant1 == null || constant2 == null)
                return;

            if (constant1.TypeCode != constant2.TypeCode)
                report($"{name} : ConstantTypeCode...{constant1.TypeCode} => {constant2.TypeCode}");
            if (constant1.Bytes != constant2.Bytes)
                report($"{name} : constant bytes...{constant1.Bytes} => {constant2.Bytes}");
            if (constant1.Error != null)
                report($"winmd1: {name} constant decoding unresolved: {constant1.Error}");
            if (constant2.Error != null)
                report($"winmd2: {name} constant decoding unresolved: {constant2.Error}");
            if (constant1.Error == null && constant2.Error == null && constant1.Value != constant2.Value)
                report($"winmd1: {name} = {constant1.Value}, winmd2 = {constant2.Value}");
        }

        private static ConstantData Read(MetadataReader reader, ConstantHandle handle)
        {
            if (handle.IsNil)
                return null;
            var constant = reader.GetConstant(handle);
            string bytes = Convert.ToHexString(reader.GetBlobBytes(constant.Value));
            try
            {
                var blob = reader.GetBlobReader(constant.Value);
                object value = blob.ReadConstant(constant.TypeCode);
                string text = value switch
                {
                    null => "null",
                    string s => JsonSerializer.Serialize(s),
                    char c => $"U+{(int)c:X4}",
                    float f => f.ToString("R", CultureInfo.InvariantCulture),
                    double d => d.ToString("R", CultureInfo.InvariantCulture),
                    IFormattable formattable => formattable.ToString(null, CultureInfo.InvariantCulture),
                    _ => value.ToString(),
                };
                return new ConstantData(constant.TypeCode, bytes, text, null);
            }
            catch (Exception ex) when (ex is BadImageFormatException || ex is ArgumentOutOfRangeException)
            {
                return new ConstantData(constant.TypeCode, bytes, null, ex.GetType().Name);
            }
        }

        private sealed record ConstantData(ConstantTypeCode TypeCode, string Bytes, string Value, string Error);
    }
}
