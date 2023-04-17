namespace MetadataUtils
{
    public interface IConstantWriter
    {
        void AddGuid(string name, string args);
        void AddInt(string forceType, string nativeTypeName, string name, string valueText, out string finalType);
        void AddShort(string nativeTypeName, string name, string valueText, out string finalType);
        void AddPropKey(string structType, string name, string args);
        void AddValue(string type, string name, string valueText, string context = "");
        void Dispose();
    }
}
