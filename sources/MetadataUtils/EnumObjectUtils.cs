using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text.RegularExpressions;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;

namespace MetadataUtils
{
    public static class EnumObjectUtils
    {
        private static readonly Regex CamelCaseWordsRegex = new Regex(@"[A-Z][a-z]*");

        public static IEnumerable<EnumObject> NormalizeEnumObjects(
            string generatedSourcesDir, IEnumerable<EnumObject> objects, Dictionary<string, string> renames, HashSet<string> excludes)
        {
            return NormalizeEnumObjects(generatedSourcesDir, objects, renames, excludes, null);
        }

        public static IEnumerable<EnumObject> NormalizeEnumObjects(
            string repoRoot, IEnumerable<EnumObject> objects, Dictionary<string, string> renames, HashSet<string> excludes, Dictionary<string, EnumObject> newToOldEnumObjMap)
        {
            EnumObjectNormalizer normalizer = new EnumObjectNormalizer();
            return normalizer.NormalizeEnumObjects(repoRoot, objects, renames, excludes, newToOldEnumObjMap);
        }

        private class EnumObjectNormalizer
        {
            private Dictionary<string, EnumObject> enumMemberNameToEnumObj = new Dictionary<string, EnumObject>();

            private bool TryMergingWithExistingObject(EnumObject enumObject)
            {
                if (enumObject.finished)
                {
                    return false;
                }

                bool merged = false;
                foreach (var member in enumObject.members)
                {
                    if (this.enumMemberNameToEnumObj.TryGetValue(member.name, out var matchedObj))
                    {
                        merged = this.MergeObjIntoOther(enumObject, matchedObj);
                        if (merged)
                        {
                            break;
                        }
                    }
                }

                foreach (var use in enumObject.uses)
                {
                    if (this.enumMemberNameToEnumObj.TryGetValue(use.ToString(), out var matchedObj))
                    {
                        merged = this.MergeObjIntoOther(enumObject, matchedObj);
                        if (merged)
                        {
                            break;
                        }
                    }
                }

                return merged;
            }

            private bool MergeObjIntoOther(EnumObject src, EnumObject dest)
            {
                // If the dest is from C# code, make src point to dest. In effect,
                // it will give its uses to the C# version
                if (dest.FromCSharp)
                {
                    src.name = null;
                    src.members.Clear();
                    src.addUsesTo = dest.name;
                    return true;
                }

                // Don't mess with an object that was declared to be finished in the json
                if (src.finished)
                {
                    return false;
                }

                foreach (var m in src.members)
                {
                    if (StringComparer.OrdinalIgnoreCase.Equals(m.name, "None"))
                    {
                        continue;
                    }

                    dest.AddIfNotSet(m.name, m.value);
                    if (this.enumMemberNameToEnumObj.TryGetValue(m.name, out var memberOwner))
                    {
                        if (memberOwner != dest && memberOwner != src)
                        {
                            this.enumMemberNameToEnumObj[m.name] = dest;
                            this.MergeObjIntoOther(memberOwner, dest);
                        }
                    }

                    this.enumMemberNameToEnumObj[m.name] = dest;
                }

                foreach (var u in src.uses)
                {
                    dest.AddUse(u);
                }

                return true;
            }

            public IEnumerable<EnumObject> NormalizeEnumObjects(
                string repoRoot, IEnumerable<EnumObject> objects, Dictionary<string, string> renames, HashSet<string> excludes, Dictionary<string, EnumObject> newToOldEnumObjMap)
            {
                string generatedSourcesDir = Path.Combine(repoRoot, "generation\\emitter\\generated");
                string manualSourcesDir = Path.Combine(repoRoot, "generation\\emitter\\manual");

                this.LoadEnumsFromSourcesFiles(generatedSourcesDir);
                this.LoadEnumsFromSourcesFiles(manualSourcesDir);

                Dictionary<string, string> namesToTypes = GetFullNamesToTypes(generatedSourcesDir);

                Dictionary<string, int> names = new Dictionary<string, int>();

                foreach (var obj in objects)
                {
                    if (obj.name != null && excludes.Contains(obj.name))
                    {
                        continue;
                    }

                    if (obj.name != null && renames.TryGetValue(obj.name, out var newName))
                    {
                        obj.name = newName;
                    }

                    if (excludes.Contains(obj.name))
                    {
                        continue;
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
                    // If the name changed, keep track of it in a map
                    else if (fixedObj.name != obj.name)
                    {
                        if (newToOldEnumObjMap != null)
                        {
                            newToOldEnumObjMap[fixedObj.name] = obj;
                        }
                    }

                    if (names.TryGetValue(currentName, out int nameCount))
                    {
                        nameCount++;
                        fixedObj.name += $"_{nameCount}";
                    }

                    if (excludes.Contains(fixedObj.name))
                    {
                        continue;
                    }

                    if (this.TryMergingWithExistingObject(fixedObj))
                    {
                        // Don't throw it away if it's pointing to a C# version
                        if (fixedObj.addUsesTo != null)
                        {
                            yield return fixedObj;
                        }

                        continue;
                    }
                    
                    this.LoadObjMembersIntoMap(fixedObj);

                    names[currentName] = nameCount;

                    yield return fixedObj;
                }
            }

            private void LoadEnumsFromSourcesFiles(string sourcesDir)
            {
                foreach (var file in Directory.GetFiles(sourcesDir, "*.cs").Where(f => !f.EndsWith(".enums.cs") && !f.EndsWith(".constants.cs")))
                {
                    foreach (var enumObj in EnumObject.LoadFromFile(file))
                    {
                        this.LoadObjMembersIntoMap(enumObj);
                    }
                }
            }

            private void LoadObjMembersIntoMap(EnumObject obj)
            {
                foreach (var member in obj.members)
                {
                    if (StringComparer.OrdinalIgnoreCase.Equals(member.name, "None"))
                    {
                        continue;
                    }

                    if (!this.enumMemberNameToEnumObj.ContainsKey(member.name))
                    {
                        this.enumMemberNameToEnumObj[member.name] = obj;
                    }
                }

                foreach (var use in obj.uses)
                {
                    if (!this.enumMemberNameToEnumObj.ContainsKey(use.ToString()))
                    {
                        this.enumMemberNameToEnumObj[use.ToString()] = obj;
                    }
                }
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

        private static Dictionary<string, string> GetFullNamesToTypes(string generatedSourcesDir)
        {
            //string sourceDirectory = Path.Combine(repoRoot, $@"generation\emitter");
            var sourceFiles = Directory.GetFiles(generatedSourcesDir, "*.cs", SearchOption.AllDirectories).Where(f => !f.EndsWith("modified.cs"));

            Dictionary<string, string> ret = new Dictionary<string, string>(StringComparer.OrdinalIgnoreCase);

            foreach (var fileName in sourceFiles)
            {
                var tree = CSharpSyntaxTree.ParseText(File.ReadAllText(fileName), null, fileName);
                SyntaxWalkerForFullNamesAndTypes syntaxWalkerForFullNamesAndTypes = new SyntaxWalkerForFullNamesAndTypes(ret);
                syntaxWalkerForFullNamesAndTypes.ProcessTree(tree);
            }

            return ret;
        }

        private class SyntaxWalkerForFullNamesAndTypes : CSharpSyntaxWalker
        {
            private static readonly Regex ValidTypeRegex = new Regex(@"^(uint|int|ulong|long|short|ushort)\**$");

            private Dictionary<string, string> map;

            public SyntaxWalkerForFullNamesAndTypes(Dictionary<string, string> map)
            {
                this.map = map;
            }

            public void ProcessTree(SyntaxTree tree)
            {
                this.Visit(tree.GetRoot());
            }

            public override void VisitParameter(ParameterSyntax node)
            {
                base.VisitParameter(node);

                string fullName = SyntaxUtils.GetFullName(node);
                string type = node.Type.ToString();

                this.CacheInfo(node.AttributeLists, fullName, type);
            }

            private void CacheInfo(SyntaxList<AttributeListSyntax> attributeLists, string fullName, string type)
            {
                string nativeType = SyntaxUtils.GetNativeTypeNameFromAttributesLists(attributeLists);

                // Don't ever map enums onto strings.
                // We may need to make this more intelligent if we find we're stomping on types
                // we don't want to change
                if (nativeType != null && nativeType.Contains("STR"))
                {
                    return;
                }

                this.CacheInfo(fullName, type);

                if (ValidTypeRegex.IsMatch(type))
                {
                    this.map[fullName] = type;
                }
            }

            private void CacheInfo(string fullName, string type)
            {
                if (ValidTypeRegex.IsMatch(type))
                {
                    this.map[fullName] = type;
                }
            }

            public override void VisitDelegateDeclaration(DelegateDeclarationSyntax node)
            {
                base.VisitDelegateDeclaration(node);

                string fullName = SyntaxUtils.GetFullName(node) + "::return";
                string type = node.ReturnType.ToString();

                this.CacheInfo(fullName, type);
            }

            public override void VisitMethodDeclaration(MethodDeclarationSyntax node)
            {
                base.VisitMethodDeclaration(node);

                string fullName = SyntaxUtils.GetFullName(node) + "::return";
                string type = node.ReturnType.ToString();

                this.CacheInfo(fullName, type);
            }

            public override void VisitFieldDeclaration(FieldDeclarationSyntax node)
            {
                if (!(node.Parent is StructDeclarationSyntax))
                {
                    return;
                }

                base.VisitFieldDeclaration(node);

                var variable = node.Declaration.Variables.First();
                string type = node.Declaration.Type.ToString();

                string fullName = SyntaxUtils.GetFullName(variable);

                this.CacheInfo(node.AttributeLists, fullName, type);
            }
        }
    }
}
