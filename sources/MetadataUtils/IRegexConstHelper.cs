namespace MetadataUtils
{
    public interface IRegexConstHelper
    {
        bool TryProcessingLine(string originalNamespace, string constName, string value);
    }
}