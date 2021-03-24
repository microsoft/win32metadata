using System.Collections.Generic;
using System.Linq;
using System.Text.RegularExpressions;

namespace PartitionUtilsLib
{
    public static class EnumObjectUtils
    {
        private static readonly Regex CamelCaseWordsRegex = new Regex(@"[A-Z][a-z]*");

        public static IEnumerable<EnumObject> NormalizeEnumObjects(Dictionary<string, string> namesToTypes, IEnumerable<EnumObject> objects, Dictionary<string, string> renames)
        {
            Dictionary<string, int> names = new Dictionary<string, int>();
            foreach (var obj in objects)
            {
                if (obj.name != null && renames.TryGetValue(obj.name, out var newName))
                {
                    obj.name = newName;
                }

                // Weed out enums that are based on error codes
                if (obj.members.Count > 0)
                {
                    string firstName = obj.members[0].name;
                    if (firstName == "TRUE" || firstName == "S_OK" || firstName.StartsWith("ERROR_"))
                    {
                        continue;
                    }
                }

                bool hadUses = obj.uses.Count != 0;

                // Weed out uses that aren't in our list of uses that reference members 
                // that don't exist or use types that can't be enums
                foreach (var use in obj.uses.ToArray())
                {
                    string useName = use.ToString();
                    if (!namesToTypes.ContainsKey(useName))
                    {
                        obj.uses.Remove(use);
                    }
                }

                // If there are no more uses, get rid of the enum
                if (hadUses && obj.uses.Count == 0)
                {
                    continue;
                }

                var fixedObj = Normalize(obj);
                string currentName = fixedObj.name;
                if (renames.TryGetValue(currentName, out newName))
                {
                    fixedObj.name = newName;
                    currentName = newName;
                }

                if (names.TryGetValue(currentName, out int nameCount))
                {
                    nameCount++;
                    fixedObj.name += $"_{nameCount}";
                }

                names[currentName] = nameCount;

                yield return fixedObj;
            }
        }

        public static EnumObject Normalize(EnumObject enumObject)
        {
            EnumObject fixedObject = Newtonsoft.Json.JsonConvert.DeserializeObject<EnumObject>(Newtonsoft.Json.JsonConvert.SerializeObject(enumObject));

            if (fixedObject.name != null && fixedObject.name.Contains('.'))
            {
                fixedObject.name = fixedObject.name.Replace('.', '_');
            }

            var firstUse = fixedObject.uses.FirstOrDefault();
            if (firstUse == null)
            {
                return fixedObject;
            }

            if (fixedObject.name == null || !fixedObject.name.Contains('_'))
            {
                List<string> namesToMatch = new List<string>();
                const int MaxToCheck = 4;
                for (int i = 0; i < fixedObject.uses.Count; i++)
                {
                    var use = fixedObject.uses[i];
                    if (use.method != null)
                    {
                        namesToMatch.Add(use.method);
                        if (namesToMatch.Count == MaxToCheck)
                        {
                            break;
                        }
                    }
                }

                string varName = firstUse.method != null ? firstUse.parameter : firstUse.field;
                string matchedName = GetCommonCamelCaseName(namesToMatch.ToArray());
                if (string.IsNullOrEmpty(matchedName))
                {
                    matchedName = firstUse.method != null ? firstUse.method : firstUse.@struct;
                }

                fixedObject.name = $"{matchedName}_{varName}";
            }

            foreach (var member in fixedObject.members)
            {
                if (int.TryParse(member.name, out var value))
                {
                    string name = firstUse.parameter != null ? firstUse.parameter : firstUse.field;
                    member.value = member.name;
                    member.name = $"{name}{value}";
                }
            }

            return fixedObject;
        }

        private static string GetCommonCamelCaseName(string[] names)
        {
            if (names.Length == 0)
            {
                return null;
            }

            if (names.Length == 1)
            {
                return names[0];
            }

            List<string> matchingParts = new List<string>();

            matchingParts.AddRange(GetCamelCaseParts(names[0]));
            for (int i = 1; i < names.Length; i++)
            {
                string[] currentParts = GetCamelCaseParts(names[i]);
                if (matchingParts.Count > currentParts.Length)
                {
                    matchingParts.RemoveRange(currentParts.Length, matchingParts.Count - currentParts.Length);
                }

                for (int partIndex = 0; partIndex < currentParts.Length && partIndex < matchingParts.Count; partIndex++)
                {
                    if (matchingParts[partIndex] != currentParts[partIndex])
                    {
                        matchingParts.RemoveRange(partIndex, matchingParts.Count - partIndex);
                        break;
                    }
                }
            }

            return string.Join(string.Empty, matchingParts.ToArray());
        }

        private static string[] GetCamelCaseParts(string name)
        {
            List<string> parts = new List<string>();
            foreach (Match match in CamelCaseWordsRegex.Matches(name))
            {
                parts.Add(match.Groups[0].Value);
            }

            return parts.ToArray();
        }
    }
}
