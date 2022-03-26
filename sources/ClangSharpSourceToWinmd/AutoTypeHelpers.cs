using System.Collections.Generic;
using System.IO;
using System.Linq;
using Newtonsoft.Json;

namespace ClangSharpSourceToWinmd
{
    public class AutoTypeHelpers
    {
        public static IEnumerable<AutoType> GetAutoTypesFromFiles(IEnumerable<string> filePaths)
        {
            var settings = new JsonSerializerSettings { NullValueHandling = NullValueHandling.Ignore };
            return filePaths?.SelectMany(filePath => JsonConvert.DeserializeObject<AutoType[]>(File.ReadAllText(filePath), settings));
        }
    }
}
