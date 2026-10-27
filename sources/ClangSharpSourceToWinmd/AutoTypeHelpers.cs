using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using Newtonsoft.Json;
using MetadataUtils;

namespace ClangSharpSourceToWinmd
{
    public class AutoTypeHelpers
    {
        public static IEnumerable<AutoType> GetAutoTypesFromFiles(IEnumerable<string> filePaths)
        {
            var validation = new GenerationValidation();
            var result = GetAutoTypesWithDiagnostics(filePaths, validation);
            validation.ThrowIfAny();
            return result;
        }

        internal static AutoType[] GetAutoTypesWithDiagnostics(IEnumerable<string> filePaths, GenerationValidation validation)
        {
            if (filePaths == null)
                return null;
            var settings = new JsonSerializerSettings { NullValueHandling = NullValueHandling.Ignore };
            var types = new List<AutoType>();
            foreach (string filePath in filePaths)
            {
                try
                {
                    var input = JsonConvert.DeserializeObject<AutoType[]>(File.ReadAllText(filePath), settings);
                    if (input == null || input.Any(type => type == null))
                        throw new JsonSerializationException("An auto-types input must contain an array of non-null declarations.");
                    foreach (var type in input)
                        type.InputPath = filePath;
                    types.AddRange(input);
                }
                catch (JsonException error)
                {
                    validation.Add(error, "CSSW006", "emitter.auto-type-input", filePath);
                }
            }
            return types.ToArray();
        }
    }
}
