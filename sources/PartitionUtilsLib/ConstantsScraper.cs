using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;

namespace PartitionUtilsLib
{
    public static class ConstantsScraper
    {
        public static void ScrapeConstants(
            string repoRoot,
            string[] enumJsonFiles,
            Dictionary<string, string> exclusionNamesToPartitions,
            Dictionary<string, string> requiredNamespaces,
            Dictionary<string, string> remaps,
            Dictionary<string, string> withTypes,
            Dictionary<string, string> renames)
        {
            using ConstantsScraperImpl imp = new ConstantsScraperImpl();
            imp.ScrapeConstants(repoRoot, enumJsonFiles, exclusionNamesToPartitions, requiredNamespaces, remaps, withTypes, renames);
        }

        private class ConstantsScraperImpl : IDisposable
        {
            private static readonly Regex DefineRegex =
                new Regex(
                    @"^#define\s+([A-Z][\dA-Z_]+)\s+(.+)");

            private static readonly Regex DefineConstantRegex =
                new Regex(
                    @"^((_HRESULT_TYPEDEF_|_NDIS_ERROR_TYPEDEF_)\(((?:0x)?[\da-f]+L?)\)|(\(HRESULT\)((?:0x)?[\da-f]+L?))|(-?\d+\.\d+(?:e\+\d+)?f?)|((?:0x[\da-f]+|\-?\d+)(?:UL|L)?)|((\d+)\s*(<<\s*\d+))|(MAKEINTRESOURCE\(\s*(\-?\d+)\s*\))|(\(HWND\)(-?\d+)))$", RegexOptions.IgnoreCase);

            private Dictionary<string, EnumWriter> namespacesToEnumWriters = new Dictionary<string, EnumWriter>();
            private Dictionary<string, ConstantWriter> namespacesToConstantWriters = new Dictionary<string, ConstantWriter>();
            private WildcardDictionary requiredNamespaces;
            private Dictionary<string, string> writtenConstants = new Dictionary<string, string>();
            private string repoRoot;

            private List<EnumObject> enumObjectsFromJsons;
            private Dictionary<string, string> withTypes;

            private Dictionary<string, List<EnumObject>> enumMemberNameToEnumObj;

            public ConstantsScraperImpl()
            {
            }

            public void ScrapeConstants(
                string repoRoot,
                string[] enumJsonFiles,
                Dictionary<string, string> exclusionNamesToPartitions,
                Dictionary<string, string> requiredNamespaces,
                Dictionary<string, string> remaps,
                Dictionary<string, string> withTypes,
                Dictionary<string, string> renames)
            {
                this.requiredNamespaces = new WildcardDictionary(requiredNamespaces);
                this.withTypes = withTypes;

                this.repoRoot = Path.GetFullPath(repoRoot);

                this.LoadEnumObjectsFromJsonFiles(enumJsonFiles);

                this.ScrapeConstantsFromTraversedFiles(exclusionNamesToPartitions);

                this.WriteEnumsAndRemaps(remaps, renames);
            }

            public void Dispose()
            {
                foreach (var enumWriter in namespacesToEnumWriters.Values)
                {
                    enumWriter.Dispose();
                }

                namespacesToEnumWriters.Clear();

                foreach (var constantWriter in namespacesToConstantWriters.Values)
                {
                    constantWriter.Dispose();
                }

                namespacesToConstantWriters.Clear();
            }

            private static Dictionary<string, string> GetAutoValueReplacements()
            {
                Dictionary<string, string> ret = new Dictionary<string, string>();
                ret["TRUE"] = "1";
                ret["FALSE"] = "0";
                ret["( (DWORD) (-1) )"] = "0xFFFFFFFF";

                return ret;
            }

            private static void MergeObjIntoOther(EnumObject src, EnumObject dest, Dictionary<string, List<EnumObject>> memberMap)
            {
                foreach (var m in src.members)
                {
                    if (StringComparer.OrdinalIgnoreCase.Equals(m.name, "None"))
                    {
                        continue;
                    }

                    dest.AddIfNotSet(m.name, m.value);
                    if (!memberMap.TryGetValue(m.name, out var oList))
                    {
                        oList = new List<EnumObject>();
                        oList.Add(dest);
                    }
                    else
                    {
                        if (oList.Contains(src))
                        {
                            oList.Remove(src);
                        }

                        if (!oList.Contains(dest))
                        {
                            oList.Add(dest);
                        }
                    }
                }

                foreach (var u in src.uses)
                {
                    dest.AddUse(u);
                }
            }

            private static Dictionary<string, List<EnumObject>> LoadMemberNameToEnumObjMap(List<EnumObject> enumObjects)
            {
                Dictionary<string, List<EnumObject>> enumMemberNameToEnumObj = new Dictionary<string, List<EnumObject>>();
                foreach (var obj in enumObjects)
                {
                    foreach (var member in obj.members)
                    {
                        if (StringComparer.OrdinalIgnoreCase.Equals(member.name, "None"))
                        {
                            continue;
                        }

                        if (!enumMemberNameToEnumObj.TryGetValue(member.name, out var objList))
                        {
                            objList = new List<EnumObject>();
                            enumMemberNameToEnumObj[member.name] = objList;
                            objList.Add(obj);
                        }
                        else
                        {
                            var mergingTo = objList[0];
                            MergeObjIntoOther(obj, mergingTo, enumMemberNameToEnumObj);
                        }
                    }
                }

                return enumMemberNameToEnumObj;
            }

            private static List<EnumObject> LoadEnumsFromJsonFiles(string[] enumJsonFiles)
            {
                List<EnumObject> enumObjects = new List<EnumObject>();

                if (enumJsonFiles != null)
                {
                    foreach (var enumJsonFile in enumJsonFiles)
                    {
                        enumObjects.AddRange(EnumObjectUtils.NormalizeEnumObjects(EnumObject.LoadFromFile(enumJsonFile)));
                    }
                }

                return enumObjects;
            }

            private static List<EnumObject> LoadEnumsFromSourceFiles(string sourcesDir)
            {
                List<EnumObject> enumObjects = new List<EnumObject>();
                foreach (var file in Directory.GetFiles(sourcesDir, "*.cs"))
                {
                    enumObjects.AddRange(EnumObject.LoadFromFile(file));
                }

                return enumObjects;
            }

            private static string StripComments(string rawValue)
            {
                int commentIndex = rawValue.IndexOf("//");
                if (commentIndex != -1)
                {
                    rawValue = rawValue.Substring(0, commentIndex).Trim();
                }

                commentIndex = rawValue.IndexOf("/*");
                if (commentIndex != -1)
                {
                    rawValue = rawValue.Substring(0, commentIndex).Trim();
                }

                return rawValue;
            }

            private string GetForcedTypeForName(string name)
            {
                // Make all error codes uint to match GetLastError even though they're defined as signed
                // in winerror.h
                if (name.StartsWith("ERROR_"))
                {
                    return "uint";
                }

                this.withTypes.TryGetValue(name, out string forceType);

                return forceType;
            }

            private void AddConstantValue(string originalNamespace, string type, string name, string valueText)
            {
                if (this.writtenConstants.ContainsKey(name))
                {
                    return;
                }

                var writer = this.GetConstantWriter(originalNamespace, name);
                writer.AddValue(type, name, valueText);

                this.writtenConstants[name] = valueText;
            }

            private void AddConstantInteger(string originalNamespace, string nativeTypeName, string name, string valueText)
            {
                if (this.writtenConstants.ContainsKey(name))
                {
                    return;
                }

                string forcedType = nativeTypeName != null ? null : this.GetForcedTypeForName(name);

                var writer = this.GetConstantWriter(originalNamespace, name);
                writer.AddInt(forcedType, nativeTypeName, name, valueText);

                this.writtenConstants[name] = valueText;
            }

            private ConstantWriter GetConstantWriter(string originalNamespace, string name)
            {
                string foundNamespace = originalNamespace;
                if (this.requiredNamespaces.TryGetValue(name, out var newNamspace))
                {
                    foundNamespace = newNamspace;
                }

                if (!this.namespacesToConstantWriters.TryGetValue(foundNamespace, out var constantWriter))
                {
                    string partConstantsFile = Path.Combine(repoRoot, $@"generation\emitter\generated\{foundNamespace}.constants.cs");
                    if (File.Exists(partConstantsFile))
                    {
                        File.Delete(partConstantsFile);
                    }

                    constantWriter = new ConstantWriter(partConstantsFile, foundNamespace);
                    this.namespacesToConstantWriters.Add(foundNamespace, constantWriter);
                }

                return constantWriter;
            }

            private HashSet<string> GetManualEnumNames()
            {
                string manualSourceFiles = Path.Combine(repoRoot, $@"generation\emitter\manual");
                List<EnumObject> enumObjectsFromManualSources = LoadEnumsFromSourceFiles(manualSourceFiles);
                HashSet<string> manualEnumNames = new HashSet<string>();
                foreach (var obj in enumObjectsFromManualSources)
                {
                    manualEnumNames.Add(obj.name);
                }

                return manualEnumNames;
            }

            private void LoadEnumObjectsFromJsonFiles(string[] enumJsonFiles)
            {
                // Load the enums scraped from the docs
                this.enumObjectsFromJsons = LoadEnumsFromJsonFiles(enumJsonFiles);

                // Load a map from member names to enum obj
                // This will merge up and objects that share the same members
                this.enumMemberNameToEnumObj = LoadMemberNameToEnumObjMap(enumObjectsFromJsons);
            }

            private void ScrapeConstantsFromTraversedFiles(
                Dictionary<string, string> exclusionNamesToPartitions)
            {
                var autoReplacements = GetAutoValueReplacements();

                RepoInfo repoInfo = new RepoInfo(repoRoot);

                // For each partition, scrape the constants
                foreach (var partInfo in repoInfo.GetPartitionInfos())
                {
                    // File path to constants for the partition
                    string partConstantsFile = Path.Combine(repoRoot, $@"generation\emitter\generated\{partInfo.Name}.constants.cs");
                    if (File.Exists(partConstantsFile))
                    {
                        File.Delete(partConstantsFile);
                    }

                    string currentNamespace = partInfo.Namespace;

                    // For each traversed header, scrape the constants
                    foreach (var header in partInfo.GetTraverseHeaders(true))
                    {
                        if (!File.Exists(header))
                        {
                            continue;
                        }

                        string currentHeaderName = Path.GetFileName(header).ToLowerInvariant();

                        List<EnumObject> autoEnumObjsForCurrentHeader =
                            new List<EnumObject>(enumObjectsFromJsons.Where(e => e.autoPopulate != null && e.autoPopulate.header.ToLowerInvariant() == currentHeaderName));
                        Regex autoPopulateReg = null;

                        if (autoEnumObjsForCurrentHeader.Count != 0)
                        {
                            StringBuilder autoPopulateRegexPattern = new StringBuilder();
                            foreach (var autoEnumObj in autoEnumObjsForCurrentHeader)
                            {
                                if (autoPopulateRegexPattern.Length != 0)
                                {
                                    autoPopulateRegexPattern.Append('|');
                                }

                                autoPopulateRegexPattern.Append($"(^{autoEnumObj.autoPopulate.filter})");
                            }

                            autoPopulateReg = new Regex(autoPopulateRegexPattern.ToString());
                        }

                        string continuation = null;
                        foreach (string currentLine in File.ReadAllLines(header))
                        {
                            string line = continuation == null ? currentLine : continuation + currentLine;
                            if (line.EndsWith("\\"))
                            {
                                continuation = line.Substring(0, line.Length - 1);
                                continue;
                            }

                            continuation = null;

                            var defineMatch = DefineRegex.Match(line);

                            // Skip if not #define ...
                            if (!defineMatch.Success)
                            {
                                continue;
                            }

                            string name = defineMatch.Groups[1].Value;

                            // If it's in the exclusion list see if we should ignore it based on the
                            // current partition
                            if (exclusionNamesToPartitions.TryGetValue(name, out var partitions))
                            {
                                bool shouldIgnore = partitions == null;
                                if (!shouldIgnore)
                                {
                                    string[] parts = partitions.Split(';');
                                    foreach (var part in parts)
                                    {
                                        if (StringComparer.OrdinalIgnoreCase.Equals(part, partInfo.Name))
                                        {
                                            shouldIgnore = true;
                                        }
                                    }
                                }

                                if (shouldIgnore)
                                {
                                    continue;
                                }
                            }

                            // Get rid of trailing comments
                            string rawValue = StripComments(defineMatch.Groups[2].Value.Trim());

                            if (autoReplacements.TryGetValue(rawValue, out var updatedRawValue))
                            {
                                rawValue = updatedRawValue;
                            }

                            string fixedRawValue = rawValue;
                            // Get rid of enclosing parens. Makes it easier to parse with regex
                            if (fixedRawValue.StartsWith('(') && fixedRawValue.EndsWith(')'))
                            {
                                fixedRawValue = fixedRawValue.Substring(1, rawValue.Length - 2).Trim();
                            }

                            // See if matches one of our well known constants formats
                            var match = DefineConstantRegex.Match(fixedRawValue);
                            string valueText;
                            string nativeTypeName = null;

                            if (match.Success)
                            {
                                // #define E_UNEXPECTED _HRESULT_TYPEDEF_(0x8000FFFF)
                                if (!string.IsNullOrEmpty(match.Groups[2].Value))
                                {
                                    if (match.Groups[2].Value == "_HRESULT_TYPEDEF_")
                                    {
                                        nativeTypeName = "HRESULT";
                                    }

                                    valueText = match.Groups[3].Value;
                                }
                                // #define E_UNEXPECTED ((HRESULT)0x8000FFFF)
                                else if (!string.IsNullOrEmpty(match.Groups[5].Value))
                                {
                                    nativeTypeName = "HRESULT";
                                    valueText = match.Groups[5].Value;
                                }
                                // #define DXGI_RESOURCE_PRIORITY_MINIMUM	( 0x28000000 )
                                else if (!string.IsNullOrEmpty(match.Groups[7].Value))
                                {
                                    valueText = match.Groups[7].Value;
                                }
                                // 1.0, -2.0f
                                else if (!string.IsNullOrEmpty(match.Groups[6].Value))
                                {
                                    valueText = match.Groups[6].Value;
                                    string type = valueText.EndsWith('f') ? "float" : "double";
                                    this.AddConstantValue(currentNamespace, type, name, valueText);
                                    continue;
                                }
                                // 1 << 5
                                else if (!string.IsNullOrEmpty(match.Groups[8].Value))
                                {
                                    string part1 = match.Groups[9].Value + "u";
                                    string part2 = match.Groups[10].Value;
                                    valueText = part1 + part2;
                                }
                                // MAKEINTRESOURCE(-4)
                                else if (!string.IsNullOrEmpty(match.Groups[11].Value))
                                {
                                    nativeTypeName = "LPCWSTR";
                                    valueText = match.Groups[12].Value;
                                    this.AddConstantInteger(currentNamespace, nativeTypeName, name, valueText);
                                    continue;
                                }
                                // (HWND)-4
                                else if (!string.IsNullOrEmpty(match.Groups[13].Value))
                                {
                                    nativeTypeName = "HWND";
                                    valueText = match.Groups[14].Value;
                                    this.AddConstantInteger(currentNamespace, nativeTypeName, name, valueText);
                                    continue;
                                }
                                else
                                {
                                    continue;
                                }
                            }
                            else
                            {
                                valueText = rawValue;

                                // Don't do anything with strings. They can't be part of enums
                                if (valueText.StartsWith('"') || valueText.StartsWith("L\"") || valueText.StartsWith("__TEXT"))
                                {
                                    continue;
                                }

                                valueText = valueText.Replace("(DWORD)", "(uint)");
                            }

                            bool updatedEnum = false;

                            // If we see the member is part of an enum, update the member value
                            if (enumMemberNameToEnumObj.TryGetValue(name, out var enumObjList))
                            {
                                foreach (var enumObj in enumObjList)
                                {
                                    enumObj.AddIfNotSet(name, valueText);
                                    updatedEnum = true;
                                }
                            }

                            if (autoPopulateReg != null)
                            {
                                Match autoPopulate = autoPopulateReg.Match(name);
                                if (autoPopulate.Success)
                                {
                                    for (int i = 1; i < autoPopulate.Groups.Count; i++)
                                    {
                                        if (!string.IsNullOrEmpty(autoPopulate.Groups[i].Value))
                                        {
                                            var foundObjEnum = autoEnumObjsForCurrentHeader[i - 1];
                                            foundObjEnum.AddIfNotSet(name, valueText);
                                            updatedEnum = true;
                                            if (!enumMemberNameToEnumObj.TryGetValue(name, out var list))
                                            {
                                                list = new List<EnumObject>();
                                                enumMemberNameToEnumObj.Add(name, list);
                                                list.Add(foundObjEnum);
                                            }
                                            else
                                            {
                                                var needMerging = list.Where(o => o != foundObjEnum).ToArray();
                                                foreach (var src in needMerging)
                                                {
                                                    MergeObjIntoOther(src, foundObjEnum, enumMemberNameToEnumObj);
                                                }

                                                list.Clear();
                                                list.Add(foundObjEnum);
                                            }

                                            break;
                                        }
                                    }
                                }
                            }

                            // If we haven't used the member to update an enum, skip it...
                            // ...unless it's an HRESULT or error code. Always emit them as constants too
                            if (match.Success && (!updatedEnum || nativeTypeName != null || name.StartsWith("ERROR_")))
                            {
                                this.AddConstantInteger(currentNamespace, nativeTypeName, name, valueText);
                            }
                        }
                    }
                }
            }

            private void WriteEnumsAndRemaps(
                Dictionary<string, string> remaps,
                Dictionary<string, string> renames)
            {
                // Output the enums and the rsp entries that map parameters and fields to use
                // enum names
                var enumRemapsFileName = Path.Combine(repoRoot, $@"generation\emitter\generated\enumsRemap.rsp");

                using StreamWriter enumRemapsWriter = new StreamWriter(enumRemapsFileName);
                enumRemapsWriter.WriteLine("--remap");

                HashSet<string> manualEnumNames = GetManualEnumNames();

                // For each enum object...
                foreach (var obj in enumObjectsFromJsons)
                {
                    if (renames.TryGetValue(obj.name, out var newName))
                    {
                        obj.name = newName;
                    }

                    // Skip if no members
                    if (obj.members.Count == 0)
                    {
                        continue;
                    }

                    string foundNamespace = null;
                    List<string> remapsToAdd = new List<string>();

                    // For each use in an enum...
                    foreach (var use in obj.uses)
                    {
                        string lookupNameForNamespace;
                        string remapName = use.ToString();

                        // lookupNameForNamespace = the name to use to lookup the namespace
                        // remapName = used in .rsp to map a param or field to use the enum
                        if (use.@interface != null)
                        {
                            lookupNameForNamespace = use.@interface;
                        }
                        else if (use.method != null)
                        {
                            lookupNameForNamespace = use.method;
                        }
                        else
                        {
                            lookupNameForNamespace = use.@struct;
                        }

                        // If we haven't found a namespace yet, try to look it up
                        if (foundNamespace == null)
                        {
                            requiredNamespaces.TryGetValue(lookupNameForNamespace, out foundNamespace);
                        }

                        // If we don't already have a remap entry for this param or field, add one
                        if (!remaps.ContainsKey(remapName))
                        {
                            remapsToAdd.Add(remapName);
                        }
                    }

                    if (foundNamespace == null)
                    {
                        foundNamespace = "Windows.Win32.SystemServices";
                    }

                    // If the enum name didn't already exist in the manual enums, and (if the enum has uses or 
                    // is an auto-populate), write the enum
                    bool shouldWriteEnum =
                        !manualEnumNames.Contains(obj.name) && (remapsToAdd.Count != 0 || obj.autoPopulate != null);

                    if (!shouldWriteEnum)
                    {
                        continue;
                    }

                    // Lookup the enum writer in the cache or add it if we can't find it
                    if (!namespacesToEnumWriters.TryGetValue(foundNamespace, out var enumWriter))
                    {
                        string fixedNamespaceName = foundNamespace.Replace("Windows.Win32.", string.Empty);
                        string enumFile = Path.Combine(repoRoot, $@"generation\emitter\generated\{fixedNamespaceName}.enums.cs");
                        if (File.Exists(enumFile))
                        {
                            File.Delete(enumFile);
                        }

                        enumWriter = new EnumWriter(enumFile, foundNamespace);
                        namespacesToEnumWriters.Add(foundNamespace, enumWriter);
                    }

                    EnumObject objectForRemap = obj;
                    if (obj.autoPopulate == null)
                    {
                        foreach (var member in obj.members)
                        {
                            if (enumMemberNameToEnumObj.TryGetValue(member.name, out var list))
                            {
                                objectForRemap = list.Where(e => e.autoPopulate != null).FirstOrDefault();
                                if (objectForRemap == null)
                                {
                                    objectForRemap = list.Where(e => e.members.Any(m => m.value != null)).FirstOrDefault();
                                    if (objectForRemap == null)
                                    {
                                        objectForRemap = obj;
                                    }
                                }

                                break;
                            }
                        }
                    }

                    bool addedEnum = false;
                    bool convergedToOtherObj = obj != objectForRemap;

                    if (!convergedToOtherObj)
                    {
                        addedEnum = enumWriter.AddEnum(obj);
                    }

                    if (addedEnum || convergedToOtherObj)
                    {
                        foreach (var remap in remapsToAdd)
                        {
                            enumRemapsWriter.WriteLine($"{remap}={objectForRemap.name}");

                            remaps.TryAdd(remap, objectForRemap.name);
                        }
                    }
                }
            }
        }
    }
}
