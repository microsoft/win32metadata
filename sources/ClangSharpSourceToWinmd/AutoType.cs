using Newtonsoft.Json;

namespace ClangSharpSourceToWinmd
{
    public class AutoType
    {
        public string Namespace { get; set; }
        public string Name { get; set; }
        public string ValueType { get; set; }
        public string CloseApi { get; set; }
        public string AlsoUsableFor { get; set; }
        public long[] InvalidHandleValues { get; set; }
    }
}
