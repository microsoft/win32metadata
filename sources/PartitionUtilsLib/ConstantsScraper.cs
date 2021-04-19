using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;

namespace PartitionUtilsLib
{
    public static class ConstantsScraper
    {
        public static ScraperResults ScrapeConstants(
            string generationDir,
            string externalPackageDir,
            string outputNamespace,
            string[] enumJsonFiles,
            string constantsHeaderText,
            Dictionary<string, string> exclusionNamesToPartitions,
            Dictionary<string, string> requiredNamespaces,
            Dictionary<string, string> remaps,
            Dictionary<string, string> withTypes,
            Dictionary<string, string> renames,
            Dictionary<string, string> withAttributes)
        {
            using ConstantsScraperImpl imp = new ConstantsScraperImpl();
            return imp.ScrapeConstants(
                generationDir,
                externalPackageDir,
                outputNamespace,
                enumJsonFiles,
                constantsHeaderText,
                exclusionNamesToPartitions,
                requiredNamespaces,
                remaps,
                withTypes,
                renames,
                withAttributes);
        }

        private class ConstantsScraperImpl : IDisposable
        {
            private static readonly Regex DefineRegex =
                new Regex(
                    @"^#define\s+([A-Z][\dA-Za-z_]+)\s+(.+)");

            private static readonly Regex DefineConstantRegex =
                new Regex(
                    @"^((_HRESULT_TYPEDEF_|_NDIS_ERROR_TYPEDEF_)\(((?:0x)?[\da-f]+L?)\)|(\(HRESULT\)((?:0x)?[\da-f]+L?))|(-?\d+\.\d+(?:e\+\d+)?f?)|((?:0x[\da-f]+|\-?\d+)(?:UL|L)?)|((\d+)\s*(<<\s*\d+))|(MAKEINTRESOURCE\(\s*(\-?\d+)\s*\))|(\(HWND\)(-?\d+))|([a-z0-9_]+\s*\+\s*(\d+|0x[0-de-f]+)))$", RegexOptions.IgnoreCase);

            private static readonly Regex DefineGuidConstRegex =
                new Regex(
                    @"^\s*(DEFINE_GUID|DEFINE_DEVPROPKEY|DEFINE_KNOWN_FOLDER)\s*\((.*)");

            private static readonly Regex DefineEnumFlagsRegex =
                new Regex(
                    @"^\s*DEFINE_ENUM_FLAG_OPERATORS\(\s*(\S+)\s*\)\s*\;\s*$");

            private static readonly Regex NamePartsRegex = new Regex(@"[A-Z]+[a-z]*");

            private static readonly Regex ContainsLowerCase = new Regex(@"[a-z]+");

            private Dictionary<string, EnumWriter> namespacesToEnumWriters = new Dictionary<string, EnumWriter>();
            private Dictionary<string, ConstantWriter> namespacesToConstantWriters = new Dictionary<string, ConstantWriter>();
            private WildcardDictionary requiredNamespaces;
            private Dictionary<string, string> writtenConstants = new Dictionary<string, string>();
            private string generationDir;
            private string externalPackageDir;
            private string outputNamespace;

            private List<EnumObject> enumObjectsFromJsons;
            private Dictionary<string, string> withTypes;
            private Dictionary<string, string> withAttributes;

            private Dictionary<string, List<EnumObject>> enumMemberNameToEnumObj;
            private Dictionary<string, string> exclusionNamesToPartitions;

            private string constantsHeaderText;
            private string enumFlagsFixupFileName;

            private List<string> output = new List<string>();
            private List<string> suggestedEnumRenames = new List<string>();

            public ConstantsScraperImpl()
            {
            }

            public ScraperResults ScrapeConstants(
                string generationDir,
                string externalPackageDir,
                string outputNamespace,
                string[] enumJsonFiles,
                string constantsHeaderText,
                Dictionary<string, string> exclusionNamesToPartitions,
                Dictionary<string, string> requiredNamespaces,
                Dictionary<string, string> remaps,
                Dictionary<string, string> withTypes,
                Dictionary<string, string> renames,
                Dictionary<string, string> withAttributes)
            {
                this.requiredNamespaces = new WildcardDictionary(requiredNamespaces);
                this.withTypes = withTypes;
                this.exclusionNamesToPartitions = exclusionNamesToPartitions;
                this.constantsHeaderText = constantsHeaderText;
                this.withAttributes = withAttributes;

                this.generationDir = Path.GetFullPath(generationDir);
                this.externalPackageDir = Path.GetFullPath(externalPackageDir);
                this.outputNamespace = outputNamespace;

                this.InitEnumFlagsFixupFile();

                this.LoadEnumObjectsFromJsonFiles(enumJsonFiles);

                this.ScrapeConstantsFromTraversedFiles();

                this.WriteEnumsAndRemaps(remaps);

                return new ScraperResults(this.output);
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

            private static List<EnumObject> LoadEnumsFromSourceFiles(string sourcesDir, string outputNamespace)
            {
                List<EnumObject> enumObjects = new List<EnumObject>();

                if (Directory.Exists(sourcesDir))
                {
                    var sourceFiles = Directory.GetFiles(sourcesDir, "*.cs").AsEnumerable();

                    if (!string.IsNullOrEmpty(outputNamespace))
                    {
                        sourceFiles = sourceFiles.Where(f => f.Contains($@"\{outputNamespace}.", StringComparison.OrdinalIgnoreCase));
                    }

                    foreach (var file in sourceFiles)
                    {
                        enumObjects.AddRange(EnumObject.LoadFromFile(file));
                    }
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

            private void InitEnumFlagsFixupFile()
            {
                string generatedToken = this.outputNamespace ?? "generated";
                this.enumFlagsFixupFileName = Path.Combine(generationDir, $@"emitter\enumsMakeFlags.{generatedToken}.rsp");
                if (File.Exists(this.enumFlagsFixupFileName))
                {
                    File.Delete(this.enumFlagsFixupFileName);
                }

                File.AppendAllText(this.enumFlagsFixupFileName, "--enum-Make-Flags\r\n");
            }

            private void LoadMemberNameToEnumObjMap(List<EnumObject> enumObjects)
            {
                this.enumMemberNameToEnumObj = new Dictionary<string, List<EnumObject>>();
                foreach (var obj in enumObjects)
                {
                    foreach (var member in obj.members)
                    {
                        if (StringComparer.OrdinalIgnoreCase.Equals(member.name, "None"))
                        {
                            continue;
                        }

                        if (!this.enumMemberNameToEnumObj.TryGetValue(member.name, out var objList))
                        {
                            objList = new List<EnumObject>();
                            this.enumMemberNameToEnumObj[member.name] = objList;
                        }

                        objList.Add(obj);
                    }
                }
            }

            private List<EnumObject> LoadEnumsFromJsonFiles(string[] enumJsonFiles)
            {
                List<EnumObject> enumObjects = new List<EnumObject>();

                if (enumJsonFiles != null)
                {
                    foreach (var enumJsonFile in enumJsonFiles)
                    {
                        enumObjects.AddRange(EnumObject.LoadFromFile(enumJsonFile));
                    }
                }

                return enumObjects;
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
            
            private void AddConstantGuid(string defineGuidKeyword, string originalNamespace, string line, string partitionName)
            {
                int firstComma = line.IndexOf(',');
                string name = line.Substring(0, firstComma).Trim();
                if (this.writtenConstants.ContainsKey(name))
                {
                    return;
                }

                if (this.ShouldExclude(name, partitionName))
                {
                    return;
                }

                string args = line.Substring(firstComma + 1).Trim();
                int closeParen = args.IndexOf(')');
                args = args.Substring(0, closeParen);

                var writer = this.GetConstantWriter(originalNamespace, name);

                if (defineGuidKeyword == "DEFINE_DEVPROPKEY")
                {
                    writer.AddPropKey(name, args);
                }
                else
                {
                    writer.AddGuid(name, args);
                }

                this.writtenConstants[name] = args;
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
                    string partConstantsFile = Path.Combine(generationDir, $@"emitter\generated\{foundNamespace}.constants.cs");
                    if (File.Exists(partConstantsFile))
                    {
                        File.Delete(partConstantsFile);
                    }

                    constantWriter = new ConstantWriter(partConstantsFile, foundNamespace, this.constantsHeaderText, this.withAttributes);
                    this.namespacesToConstantWriters.Add(foundNamespace, constantWriter);
                }

                return constantWriter;
            }

            private HashSet<string> GetManualEnumMemberNames()
            {
                string manualSourceFiles = Path.Combine(generationDir, $@"emitter\manual");
                List<EnumObject> enumObjectsFromManualSources = LoadEnumsFromSourceFiles(manualSourceFiles, this.outputNamespace);
                HashSet<string> manualEnumMemberNames = new HashSet<string>();
                foreach (var obj in enumObjectsFromManualSources)
                {
                    foreach (var member in obj.members)
                    {
                        manualEnumMemberNames.Add(member.name);
                    }
                }

                return manualEnumMemberNames;
            }

            private void LoadEnumObjectsFromJsonFiles(string[] enumJsonFiles)
            {
                // Load the enums scraped from the docs
                this.enumObjectsFromJsons = LoadEnumsFromJsonFiles(enumJsonFiles);

                // Load a map from member names to enum obj
                LoadMemberNameToEnumObjMap(enumObjectsFromJsons);
            }

            private bool ShouldExclude(string constName, string currentPartitionName)
            {
                // If it's in the exclusion list see if we should ignore it based on the
                // current partition
                if (this.exclusionNamesToPartitions.TryGetValue(constName, out var partitions))
                {
                    if (partitions == null)
                    {
                        return true;
                    }

                    string[] parts = partitions.Split(';');
                    foreach (var part in parts)
                    {
                        if (StringComparer.OrdinalIgnoreCase.Equals(part, currentPartitionName))
                        {
                            return true;
                        }
                    }
                }

                return false;
            }

            private void ScrapeConstantsFromTraversedFiles()
            {
                var autoReplacements = GetAutoValueReplacements();

                RepoInfo repoInfo = new RepoInfo(generationDir);

                HashSet<string> manualEnumMemberNames = GetManualEnumMemberNames();

                // For each partition, scrape the constants
                foreach (var partInfo in repoInfo.GetPartitionInfos())
                {
                    string currentNamespace = partInfo.Namespace;

                    // For each traversed header, scrape the constants
                    foreach (var header in partInfo.GetTraverseHeaders(true, this.externalPackageDir))
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
                        bool processingGuidMultiLine = false;
                        string defineGuidKeyword = null;
                        foreach (string currentLine in File.ReadAllLines(header))
                        {
                            string line = continuation == null ? currentLine : continuation + currentLine;
                            if (line.EndsWith("\\"))
                            {
                                continuation = line.Substring(0, line.Length - 1);
                                continue;
                            }

                            if (processingGuidMultiLine)
                            {
                                continuation = StripComments(line).Trim();
                                if (continuation.EndsWith(';'))
                                {
                                    processingGuidMultiLine = false;
                                    this.AddConstantGuid(defineGuidKeyword, currentNamespace, continuation, partInfo.Name);
                                    continuation = null;
                                }

                                continue;
                            }

                            continuation = null;

                            var defineGuidMatch = DefineGuidConstRegex.Match(line);
                            if (defineGuidMatch.Success)
                            {
                                defineGuidKeyword = defineGuidMatch.Groups[1].Value;
                                line = defineGuidMatch.Groups[2].Value;
                                line = StripComments(line).Trim();
                                if (line.EndsWith(';'))
                                {
                                    this.AddConstantGuid(defineGuidKeyword, currentNamespace, line, partInfo.Name);
                                }
                                else
                                {
                                    continuation = line;
                                    processingGuidMultiLine = true;
                                }

                                continue;
                            }

                            var defineMatch = DefineRegex.Match(line);

                            // Skip if not #define ...
                            if (!defineMatch.Success)
                            {
                                this.TryScrapingEnumFlags(line);
                                continue;
                            }

                            string name = defineMatch.Groups[1].Value;

                            if (this.ShouldExclude(name, partInfo.Name))
                            {
                                continue;
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
                                // (IDENT_FOO + 4)
                                else if (match.Groups[15].Success)
                                {
                                    valueText = match.Groups[15].Value;
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
                            if (this.enumMemberNameToEnumObj.TryGetValue(name, out var enumObjList))
                            {
                                foreach (var enumObj in enumObjList)
                                {
                                    enumObj.AddIfNotSet(name, valueText);
                                    updatedEnum = true;
                                }
                            }

                            if (autoPopulateReg != null && nativeTypeName == null)
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
                                            if (!this.enumMemberNameToEnumObj.TryGetValue(name, out var list))
                                            {
                                                list = new List<EnumObject>();
                                                this.enumMemberNameToEnumObj.Add(name, list);
                                            }

                                            list.Add(foundObjEnum);

                                            break;
                                        }
                                    }
                                }
                            }

                            // If we haven't used the member to update an enum, skip it...
                            // ...unless it's an HRESULT. Always emit them as constants too
                            if (match.Success && (!updatedEnum || nativeTypeName != null))
                            {
                                // Only add the constant if it's not part of a manual enum
                                if (!manualEnumMemberNames.Contains(name))
                                {
                                    this.AddConstantInteger(currentNamespace, nativeTypeName, name, valueText);
                                }
                            }
                        }
                    }
                }
            }

            private void TryScrapingEnumFlags(string line)
            {
                var match = DefineEnumFlagsRegex.Match(line);
                if (match.Success)
                {
                    var enumName = match.Groups[1].Value;
                    File.AppendAllText(this.enumFlagsFixupFileName, $"{enumName}\r\n");
                }
            }

            private void AddEnumWarningAndSuggestedMapping(string message, EnumObject enumObject)
            {
                this.output.Add(message);
                StringBuilder suggestedName = new StringBuilder();
                foreach (var match in NamePartsRegex.Matches(enumObject.name))
                {
                    if (suggestedName.Length != 0)
                    {
                        suggestedName.Append('_');
                    }

                    suggestedName.Append(match.ToString().ToUpperInvariant());
                }

                if (suggestedName.Length != 0)
                {
                    this.suggestedEnumRenames.Add($"{enumObject.name}={suggestedName}");
                }
            }

            private void WriteEnumsAndRemaps(
                Dictionary<string, string> remaps)
            {
                // Output the enums and the rsp entries that map parameters and fields to use
                // enum names
                var enumRemapsFileName = Path.Combine(generationDir, $@"emitter\generated\enumsRemap.rsp");

                using StreamWriter enumRemapsWriter = new StreamWriter(enumRemapsFileName);
                enumRemapsWriter.WriteLine("--remap");

                // For each enum object...
                foreach (var obj in this.enumObjectsFromJsons)
                {
                    string foundNamespace = obj.@namespace;
                    List<string> remapsToAdd = new List<string>();
                    int remapCount = 0;
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
                        if (string.IsNullOrEmpty(foundNamespace))
                        {
                            requiredNamespaces.TryGetValue(lookupNameForNamespace, out foundNamespace);
                        }

                        // If we don't already have a remap entry for this param or field, add one
                        if (!remaps.TryGetValue(remapName, out string remapValue))
                        {
                            remapsToAdd.Add(remapName);
                            remapCount++;
                        }
                        else
                        {
                            // If the existing remap wants to use this enum, keep track
                            // so that we write the enum
                            if (remapValue == obj.name)
                            {
                                remapCount++;
                            }
                        }
                    }

                    if (foundNamespace == null)
                    {
                        foundNamespace = "Windows.Win32.SystemServices";
                    }

                    bool addedEnum = false;

                    // If the enum doesn't have any remaps and isn't
                    // an auto-populate, go to next object
                    bool shouldWriteEnum = (remapCount != 0 || obj.autoPopulate != null);

                    if (!shouldWriteEnum)
                    {
                        continue;
                    }

                    // Lookup the enum writer in the cache or add it if we can't find it
                    if (!namespacesToEnumWriters.TryGetValue(foundNamespace, out var enumWriter))
                    {
                        string fixedNamespaceName = foundNamespace.Replace("Windows.Win32.", string.Empty);
                        string enumFile = Path.Combine(generationDir, $@"emitter\generated\{fixedNamespaceName}.enums.cs");
                        if (File.Exists(enumFile))
                        {
                            File.Delete(enumFile);
                        }

                        enumWriter = new EnumWriter(enumFile, foundNamespace, this.constantsHeaderText);
                        namespacesToEnumWriters.Add(foundNamespace, enumWriter);
                    }

                    if (obj.name != null)
                    {
                        if (this.writtenConstants.ContainsKey(obj.name))
                        {
                            throw new InvalidOperationException($"Tried to add enum {obj.name} but a constant with the same name already exists.");
                        }

                        addedEnum = enumWriter.AddEnum(obj);
                        if (addedEnum)
                        {
                            if (ContainsLowerCase.IsMatch(obj.name))
                            {
                                this.AddEnumWarningAndSuggestedMapping(
                                    $"Warning: {obj.name} enum contains lower case. Consider giving it an intentional name in the enums json file.",
                                    obj);
                            }
                        }
                    }

                    if (addedEnum || obj.addUsesTo != null)
                    {
                        var enumName = obj.name ?? obj.addUsesTo;
                        foreach (var remap in remapsToAdd)
                        {
                            enumRemapsWriter.WriteLine($"{remap}={enumName}");

                            remaps.TryAdd(remap, enumName);
                        }
                    }
                }

                if (this.suggestedEnumRenames.Count != 0)
                {
                    this.output.Add("Suggested enum names:");
                    this.output.AddRange(this.suggestedEnumRenames);
                    this.suggestedEnumRenames.Clear();
                }
            }
        }
    }

    public class ScraperResults
    {
        public ScraperResults(IEnumerable<string> results)
        {
            this.Output = results;
        }

        public IEnumerable<string> Output { get; }
    }
}
