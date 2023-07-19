using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.IO.Abstractions;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;

namespace MetadataUtils
{
    public static class ConstantsScraper
    {
        public static ScraperResults ScrapeConstants(
            string[] enumJsonFiles,
            string defaultNamespace,
            string scraperOutputDir,
            string constantsHeaderText,
            HashSet<string> exclusionNames,
            Dictionary<string, string> traversedHeaderToNamespaceMap,
            Dictionary<string, string> requiredNamespaces,
            Dictionary<string, string> remaps,
            Dictionary<string, string> withTypes,
            Dictionary<string, string> withAttributes)
        {
            using ConstantsScraperImpl imp = new ConstantsScraperImpl();
            return imp.ScrapeConstants(enumJsonFiles, defaultNamespace, scraperOutputDir, constantsHeaderText, exclusionNames, traversedHeaderToNamespaceMap, requiredNamespaces, remaps, withTypes, withAttributes);
        }

        private class ConstantsScraperImpl : IDisposable
        {
            private static readonly Regex DefineRegex =
                new Regex(
                    @"^\s*#\s*define\s+([_A-Za-z][\dA-Za-z_]+)\s+(.+)");

            private static readonly Regex DefineConstantRegex =
                new Regex(
                    @"^((_HRESULT_TYPEDEF_|_NDIS_ERROR_TYPEDEF_)\(((?:0x)?[\da-f]+L?)\)|(\(HRESULT\)((?:0x)?[\da-f]+L?))|(-?\d+\.\d+(?:e\+\d+)?f?)|((?:0x[\da-f]+|\-?\d+)(?:UL|L)?)|((\d+)\s*(<<\s*\d+))|(MAKEINTRESOURCE[AW]{0,1}\(\s*(\-?\d+)\s*\))|(\(HWND\)(-?\d+))|([a-z0-9_]+U?\s*[\+\-]\s*(\d+|0x[0-de-f]+)U?)|(\(NTSTATUS\)((?:0x)?[\da-f]+L?))|(\s*\(DWORD\)\s*\(?\s*-1(L|\b)\s*\)?)|(\(DWORD\)((?:0x)?[\da-f]+L?))|(\(BCRYPT_ALG_HANDLE\)\s*((?:0x)?[\da-f]+L?))|(\{\s*(?:(?:0x)?[\da-f]{4,8}L?,?\s*){3}\s*\{\s*(?:(?:0x)?[\da-f]{1,2}L?,?\s*){8}\s*\}\s*\})|(HIDP_ERROR_CODES\((.*),(.*)\))|(MAKEDIPROP\(\s*(\d+)\s*\))|(\{\s*(?:(?:0x)?[\da-f]{4,8}L?,?\s*){3}\s*(?:(?:0x)?[\da-f]{1,2}L?,?\s*){8}\s*\})|([a-z0-9_]+))$", RegexOptions.IgnoreCase);

            private static readonly Regex DefineGuidConstRegex =
                new Regex(
                    @"^\s*(DEFINE_GUID|DEFINE_DEVPROPKEY|DEFINE_PROPERTYKEY|DEFINE_KNOWN_FOLDER|OUR_GUID_ENTRY)\s*\((.*)");

            private static readonly Regex DefineAviGuidConstRegex =
                new Regex(
                    @"^\s*(DEFINE_AVIGUID)\s*\(\s*(.*),\s*(.*),\s*(.*),\s*(.*)\s*\);");

            private static readonly Regex DefineMediaTypeGuidConstRegex =
                new Regex(
                    @"^\s*(DEFINE_MEDIATYPE_GUID)\s*\(\s*(\S+),\s*(\S+)\s*\);");

            private static readonly Regex FccRegex =
                new Regex(
                    @"FCC\(\'(.{4})\'\)");

            private static readonly Regex DefineEnumFlagsRegex =
                new Regex(
                    @"^\s*DEFINE_ENUM_FLAG_OPERATORS\(\s*(\S+)\s*\)\s*\;?\s*$");

            private static readonly Regex CtlCodeRegex =
                new Regex(
                    @"^\s*CTL_CODE\((.+)\)");

            private static readonly Regex HidUsageRegex =
                new Regex(
                    @"^\s*\(USAGE\)\s*(0x[\da-f]+)", RegexOptions.IgnoreCase);

            private static readonly Regex MakeHresultRegex =
                new Regex(
                    @"^\s*(?:MAKE_HRESULT|MAKE_SCODE)\((.+)\)");

            private static readonly Regex IntCastToLpcstrRegex =
                new Regex(
                    @"^\s*\((LPCSTR|LPCWSTR)\)\s*(\d+)");

            private static readonly Regex NamePartsRegex = new Regex(@"[A-Z]+[a-z]*");

            private static readonly Regex ContainsLowerCase = new Regex(@"[a-z]+");

            private Dictionary<string, EnumWriter> namespacesToEnumWriters = new();
            private Dictionary<string, IConstantWriter> namespacesToConstantWriters = new();
            private WildcardDictionary requiredNamespaces;
            private Dictionary<string, string> scannedNamesToNamespaces;
            private Dictionary<string, string> writtenConstants;

            private List<EnumObject> enumObjectsFromJsons = new();
            private Dictionary<string, string> withTypes;
            private Dictionary<string, string> withAttributes;

            private Dictionary<string, List<EnumObject>> enumMemberNameToEnumObj;
            private HashSet<string> exclusionNames = new();

            private string scraperOutputDir;
            private string constantsHeaderText;
            private string enumFlagsFixupFileName;
            private string defaultNamespace;

            private List<string> output = new List<string>();
            private List<string> suggestedEnumRenames = new List<string>();

            // TODO: These could come from a file so we can edit a .json file instead
            // of the code
            private static readonly RegexConstMaker[] regexConstMakers = new RegexConstMaker[]
            {
                new RegexConstMaker() { Pattern = @"_WSAIO\((.+),(.+)\)", ConstType = "uint", OutputFormat = "(IOC_VOID|({0})|({1}))" },
                new RegexConstMaker() { Pattern = @"_WSAIOR\((.+),(.+)\)", ConstType = "uint", OutputFormat = "(IOC_OUT|({0})|({1}))" },
                new RegexConstMaker() { Pattern = @"_WSAIOW\((.+),(.+)\)", ConstType = "uint", OutputFormat = "(IOC_IN|({0})|({1}))" },
                new RegexConstMaker() { Pattern = @"_WSAIORW\((.+),(.+)\)", ConstType = "uint", OutputFormat = "(IOC_INOUT|({0})|({1}))" },
            };

            private IRegexConstHelper regexConstHelper;

            internal IFileSystem _fileSystem { get; set; } = new FileSystem();

            public ConstantsScraperImpl()
            {
            }

            public ScraperResults ScrapeConstants(
                string[] enumJsonFiles,
                string defaultNamespace,
                string scraperOutputDir,
                string constantsHeaderText,
                HashSet<string> exclusionNames,
                Dictionary<string, string> traversedHeaderToNamespaceMap,
                Dictionary<string, string> requiredNamespaces,
                Dictionary<string, string> remaps,
                Dictionary<string, string> withTypes,
                Dictionary<string, string> withAttributes)
            {
                this.requiredNamespaces = new WildcardDictionary(requiredNamespaces);
                this.withTypes = withTypes;
                this.exclusionNames = exclusionNames;
                this.constantsHeaderText = constantsHeaderText;
                this.withAttributes = withAttributes;
                this.scraperOutputDir = scraperOutputDir;
                this.defaultNamespace = defaultNamespace;

                this.regexConstHelper = new RegexConstHelper(regexConstMakers, this);

                this.scannedNamesToNamespaces = ScraperUtils.GetNameToNamespaceMap(scraperOutputDir);

                this.writtenConstants = ScraperUtils.GetConstants(scraperOutputDir);

                this.CleanExistingFiles();

                this.LoadEnumObjectsFromJsonFiles(enumJsonFiles);

                this.ScrapeConstantsFromTraversedFiles(traversedHeaderToNamespaceMap);

                this.WriteEnumsAndRemaps(remaps);

                return new ScraperResults(this.output);
            }

            public void Dispose()
            {
                foreach (EnumWriter enumWriter in this.namespacesToEnumWriters.Values)
                {
                    enumWriter.Dispose();
                }

                this.namespacesToEnumWriters.Clear();

                foreach (ConstantWriter constantWriter in this.namespacesToConstantWriters.Values)
                {
                    constantWriter.Dispose();
                }

                this.namespacesToConstantWriters.Clear();
            }

            private static Dictionary<string, string> GetAutoValueReplacements()
            {
                Dictionary<string, string> ret = new Dictionary<string, string>();
                ret["TRUE"] = "1";
                ret["FALSE"] = "0";

                return ret;
            }

            private static List<EnumObject> LoadEnumsFromSourceFiles(IEnumerable<string> fileNames)
            {
                List<EnumObject> enumObjects = new List<EnumObject>();

                foreach (var file in fileNames)
                {
                    enumObjects.AddRange(EnumObject.LoadFromFile(file));
                }

                return enumObjects;
            }

            private static string StripComments(string rawValue)
            {
                bool inQuote = false;
                for (int i = 0; i <= rawValue.Length - 2; i++)
                {
                    if (rawValue[i] == '\"')
                    {
                        inQuote = !inQuote;
                    }

                    if (!inQuote && rawValue[i] == '/' && (rawValue[i + 1] == '/' || rawValue[i + 1] == '*' ))
                    {
                        return rawValue.Substring(0, i).Trim();
                    }
                }

                return rawValue;
            }

            private void CleanExistingFiles()
            {
                foreach (string file in Directory.GetFiles(this.scraperOutputDir).Where(f => f.EndsWith(".enums.cs") || f.EndsWith(".constants.cs")))
                {
                    this._fileSystem.File.Delete(file);
                }
            }

            private void InitEnumFlagsFixupFile()
            {
                if (this.enumFlagsFixupFileName == null)
                {
                    this.enumFlagsFixupFileName = Path.Combine(this.scraperOutputDir, "enumsMakeFlags.generated.rsp");
                    if (this._fileSystem.File.Exists(this.enumFlagsFixupFileName))
                    {
                        this._fileSystem.File.Delete(this.enumFlagsFixupFileName);
                    }

                    this._fileSystem.File.AppendAllText(this.enumFlagsFixupFileName, "--enumMakeFlags\r\n");
                }
            }

            private void LoadMemberNameToEnumObjMap(List<EnumObject> enumObjects)
            {
                this.enumMemberNameToEnumObj = new Dictionary<string, List<EnumObject>>();
                foreach (EnumObject obj in enumObjects)
                {
                    foreach (EnumObject.Member member in obj.members)
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

                if (string.IsNullOrEmpty(forceType))
                {
                    var wildCards = this.withTypes.Where(p => p.Key.EndsWith("*"));

                    foreach (var wildCard in wildCards)
                    {
                        if (name.StartsWith(wildCard.Key.Replace("*", "")))
                        {
                            forceType = wildCard.Value;

                            break;
                        }
                    }
                }

                return forceType;
            }

            private void AddMakeHresultConstant(string originalNamespace, string name, string severity, string facility, string code)
            {
                string valueText = $"unchecked((int)(({severity}) << 31) | (((int)({facility})) << 16) | (int)({code}))";
                this.AddConstantInteger(originalNamespace, "HRESULT", name, valueText);
            }

            private void AddCtlCodeConstant(string originalNamespace, string name, string deviceType, string function, string method, string access)
            {
                if (this.writtenConstants.ContainsKey(name))
                {
                    return;
                }

                var writer = this.GetConstantWriter(originalNamespace, name);

                function = function.Replace("SCMBUS_FUNCTION(", "(IOCTL_SCMBUS_DEVICE_FUNCTION_BASE + ");
                function = function.Replace("SCM_LOGICAL_DEVICE_FUNCTION(", "(IOCTL_SCM_LOGICAL_DEVICE_FUNCTION_BASE + ");
                function = function.Replace("SCM_PHYSICAL_DEVICE_FUNCTION(", "(IOCTL_SCM_PHYSICAL_DEVICE_FUNCTION_BASE + ");

                writer.AddValue("uint", name, $"(({deviceType}) << 16) | (uint)(((int)({access})) << 14) | (({function}) << 2) | ({method})");

                this.writtenConstants.Add(name, "uint");
            }

            private void AddConstantValue(string originalNamespace, string type, string name, string valueText, string context = "")
            {
                if (this.writtenConstants.ContainsKey(name))
                {
                    return;
                }

                var writer = this.GetConstantWriter(originalNamespace, name);
                writer.AddValue(type, name, valueText, context);

                this.writtenConstants.Add(name, type);
            }
            
            private void AddConstantGuid(string defineGuidKeyword, string originalNamespace, string line)
            {
                int firstComma = line.IndexOf(',');
                string name = line.Substring(0, firstComma).Trim();
                if (this.writtenConstants.ContainsKey(name))
                {
                    return;
                }

                if (this.ShouldExclude(name))
                {
                    return;
                }

                string args = line.Substring(firstComma + 1).Trim();
                int closeParen = args.IndexOf(')');
                args = args.Substring(0, closeParen);
                args = this.GetCanonicalGuidConstantIntegerArgs(args);

                var writer = this.GetConstantWriter(originalNamespace, name);

                if (defineGuidKeyword == "DEFINE_DEVPROPKEY" || defineGuidKeyword == "DEFINE_PROPERTYKEY")
                {
                    string structType = defineGuidKeyword == "DEFINE_DEVPROPKEY" ? "DEVPROPKEY" : "PROPERTYKEY";

                    var guidParts = args[..args.LastIndexOf(',')].Split(", ");
                    for (int i = 0; i < guidParts.Length; i++)
                    {
                        guidParts[i] = Convert.ToUInt32(guidParts[i].Trim(), 16).ToString();
                    }

                    var fmtid = $"{{{string.Join(", ", guidParts)}}}";
                    var pid = args[(args.LastIndexOf(',') + 1)..].Trim();
                    pid = pid.StartsWith("0x", StringComparison.InvariantCultureIgnoreCase) ? Convert.ToUInt32(pid, 16).ToString() : pid;

                    writer.AddPropKey(structType, name, $"\"{fmtid}, {pid}\"");
                }
                else
                {
                    writer.AddGuid(name, args);
                }

                this.writtenConstants.Add(name, "Guid");
            }

            private string GetCanonicalGuidConstantIntegerArgs(string args)
            {
                return Regex.Replace(args, "\\s*'(.*?)'\\s*", m =>
                    $"0x{Convert.ToHexString(Encoding.ASCII.GetBytes(m.Groups[1].Value))}", RegexOptions.IgnoreCase);
            }

            private void AddConstantInteger(string originalNamespace, string nativeTypeName, string name, string valueText)
            {
                if (this.writtenConstants.ContainsKey(name))
                {
                    return;
                }

                string forcedType = nativeTypeName != null ? null : this.GetForcedTypeForName(name);

                var writer = this.GetConstantWriter(originalNamespace, name);
                writer.AddInt(forcedType, nativeTypeName, name, valueText, out var finalType);

                this.writtenConstants.Add(name, finalType);
            }

            private void AddConstantShort(string originalNamespace, string nativeTypeName, string name, string valueText)
            {
                if (this.writtenConstants.ContainsKey(name))
                {
                    return;
                }

                var writer = this.GetConstantWriter(originalNamespace, name);
                writer.AddShort(nativeTypeName, name, valueText, out var finalType);
                this.writtenConstants.Add(name, finalType);
            }

            private IConstantWriter GetConstantWriter(string originalNamespace, string name)
            {
                string foundNamespace = originalNamespace;

                string newNamespace = this.LookupNamespaceForName(name);
                if (!string.IsNullOrEmpty(newNamespace))
                {
                    foundNamespace = newNamespace;
                }

                if (!this.namespacesToConstantWriters.TryGetValue(foundNamespace, out IConstantWriter constantWriter))
                {
                    string partConstantsFile = Path.Combine(this.scraperOutputDir, $@"{foundNamespace}.constants.cs");
                    if (this._fileSystem.File.Exists(partConstantsFile))
                    {
                        this._fileSystem.File.Delete(partConstantsFile);
                    }

                    var fileStream = this._fileSystem.File.OpenWrite(partConstantsFile);
                    constantWriter = new ConstantWriter(fileStream, foundNamespace, this.constantsHeaderText, this.withAttributes);
                    this.namespacesToConstantWriters.Add(foundNamespace, constantWriter);
                }

                return constantWriter;
            }

            private HashSet<string> GetManualEnumMemberNames()
            {
                List<EnumObject> enumObjectsFromManualSources = LoadEnumsFromSourceFiles(this._fileSystem.Directory.GetFiles(this.scraperOutputDir, "*.manual.cs"));
                HashSet<string> manualEnumMemberNames = new HashSet<string>();
                foreach (EnumObject obj in enumObjectsFromManualSources)
                {
                    foreach (EnumObject.Member member in obj.members)
                    {
                        manualEnumMemberNames.Add(member.name);
                    }
                }

                return manualEnumMemberNames;
            }

            private void LoadEnumObjectsFromJsonFiles(string[] enumJsonFiles)
            {
                // Load the enums scraped from the docs
                this.enumObjectsFromJsons = this.LoadEnumsFromJsonFiles(enumJsonFiles);

                // Load a map from member names to enum obj
                this.LoadMemberNameToEnumObjMap(this.enumObjectsFromJsons);
            }

            private bool ShouldExclude(string constName)
            {
                return this.exclusionNames.Contains(constName);
            }

            private void ScrapeConstantsFromTraversedFiles(Dictionary<string, string> traversedFileMap)
            {
                Dictionary<string, string> autoReplacements = GetAutoValueReplacements();

                HashSet<string> manualEnumMemberNames = this.GetManualEnumMemberNames();

                // For each traversed header, scrape the constants
                foreach (KeyValuePair<string, string> item in traversedFileMap)
                {
                    var header = item.Key;
                    var currentNamespace = item.Value;

                    if (!this._fileSystem.File.Exists(header))
                    {
                        continue;
                    }

                    string currentHeaderName = Path.GetFileName(header).ToLowerInvariant();

                    var autoEnumObjsForCurrentHeader =
                        this.enumObjectsFromJsons
                            .Where(
                                e => e.autoPopulate != null &&
                                !string.IsNullOrEmpty(e.autoPopulate.filter) &&
                                e.autoPopulate.header.ToLowerInvariant() == currentHeaderName)
                            .ToArray();
                    Regex autoPopulateReg = null;

                    if (autoEnumObjsForCurrentHeader.Length != 0)
                    {
                        StringBuilder autoPopulateRegexPattern = new StringBuilder();
                        foreach (EnumObject autoEnumObj in autoEnumObjsForCurrentHeader)
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
                    string defineRegexContinuation = null;
                    bool processingGuidMultiLine = false;
                    string defineGuidKeyword = null;
                    foreach (string currentLine in this._fileSystem.File.ReadAllLines(header))
                    {
                        string fixedCurrentLine = currentLine;

                        if (continuation != null && continuation.EndsWith('"') && currentLine.StartsWith('"'))
                        {
                            continuation = continuation.Substring(0, continuation.Length - 1);
                            fixedCurrentLine = currentLine.Substring(1);
                        }

                        string line = continuation == null ? fixedCurrentLine : continuation + fixedCurrentLine;
                        if (line.EndsWith("\\"))
                        {
                            continuation = line.Substring(0, line.Length - 1);
                            continue;
                        }

                        if (processingGuidMultiLine)
                        {
                            continuation = StripComments(line).Trim();
                            if (continuation.EndsWith(';') || continuation.EndsWith(')'))
                            {
                                processingGuidMultiLine = false;
                                this.AddConstantGuid(defineGuidKeyword, currentNamespace, continuation);
                                continuation = null;
                            }

                            continue;
                        }

                        continuation = null;

                        Match defineGuidMatch = DefineGuidConstRegex.Match(line);
                        if (defineGuidMatch.Success)
                        {
                            defineGuidKeyword = defineGuidMatch.Groups[1].Value;
                            line = defineGuidMatch.Groups[2].Value;
                            line = StripComments(line).Trim();
                            if (line.EndsWith(';'))
                            {
                                this.AddConstantGuid(defineGuidKeyword, currentNamespace, line);
                            }
                            else
                            {
                                continuation = line;
                                processingGuidMultiLine = true;
                            }

                            continue;
                        }

                        Match defineAviGuidMatch = DefineAviGuidConstRegex.Match(line);
                        if (defineAviGuidMatch.Success)
                        {
                            defineGuidKeyword = defineAviGuidMatch.Groups[1].Value;
                            var guidName = defineAviGuidMatch.Groups[2].Value;
                            var l = defineAviGuidMatch.Groups[3].Value;
                            var w1 = defineAviGuidMatch.Groups[4].Value;
                            var w2 = defineAviGuidMatch.Groups[5].Value;
                            var defineGuidLine = $"{guidName}, {l}, {w1}, {w2}, 0xC0,0,0,0,0,0,0,0x46)";
                            this.AddConstantGuid(defineGuidKeyword, currentNamespace, defineGuidLine);
                            continue;
                        }

                        Match defineMediaTypeGuidMatch = DefineMediaTypeGuidConstRegex.Match(line);
                        if (defineMediaTypeGuidMatch.Success)
                        {
                            defineGuidKeyword = defineMediaTypeGuidMatch.Groups[1].Value;
                            var guidName = defineMediaTypeGuidMatch.Groups[2].Value;
                            var value = defineMediaTypeGuidMatch.Groups[3].Value;
                            var fccMatch = FccRegex.Match(value);
                            if (fccMatch.Success)
                            {
                                var fccValue = fccMatch.Groups[1].Value.ToArray();
                                uint convertedValue =
                                    (uint)(fccValue[0]) |
                                    (uint)(fccValue[1] << 8) |
                                    (uint)(fccValue[2] << 16) |
                                    (uint)(fccValue[3] << 24);
                                value = $"0x{convertedValue:x}";
                            }

                            var defineGuidLine = $"{guidName}, {value}, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71)";
                            this.AddConstantGuid(defineGuidKeyword, currentNamespace, defineGuidLine);
                            continue;
                        }

                        line = defineRegexContinuation == null ? line : defineRegexContinuation + line;
                        if (line.EndsWith("\\"))
                        {
                            defineRegexContinuation = line.Substring(0, line.Length - 1);
                            continue;
                        }
                        else
                        {
                            defineRegexContinuation = null;
                        }

                        Match defineMatch = DefineRegex.Match(line);

                        // Skip if not #define ...
                        if (!defineMatch.Success)
                        {
                            this.TryScrapingEnumFlags(line);
                            continue;
                        }

                        string name = defineMatch.Groups[1].Value;
                        if (this.ShouldExclude(name))
                        {
                            continue;
                        }

#if DEBUG
                        if (name == "SOME_CONST_NAME")
                        {
                        }
#endif

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

                        Match ctlCodeMatch = CtlCodeRegex.Match(fixedRawValue);
                        if (ctlCodeMatch.Success)
                        {
                            var parts = ctlCodeMatch.Groups[1].Value.Split(',');
                            if (parts.Length == 4)
                            {
                                this.AddCtlCodeConstant(currentNamespace, name, parts[0].Trim(), parts[1].Trim(), parts[2].Trim(), parts[3].Trim());
                                continue;
                            }
                        }

                        Match usageMatch = HidUsageRegex.Match(fixedRawValue);
                        if (usageMatch.Success)
                        {
                            this.AddConstantValue(currentNamespace, "ushort", name, usageMatch.Groups[1].Value);
                            continue;
                        }

                        if (fixedRawValue.StartsWith("AUDCLNT_ERR("))
                        {
                            fixedRawValue = fixedRawValue.Replace("AUDCLNT_ERR(", "MAKE_HRESULT(SEVERITY_ERROR, FACILITY_AUDCLNT, ");
                        }
                        else if (fixedRawValue.StartsWith("AUDCLNT_SUCCESS("))
                        {
                            fixedRawValue = fixedRawValue.Replace("AUDCLNT_SUCCESS(", "MAKE_HRESULT(SEVERITY_SUCCESS, FACILITY_AUDCLNT, ");
                        }

                        Match makeHresultMatch = MakeHresultRegex.Match(fixedRawValue);
                        if (makeHresultMatch.Success)
                        {
                            var parts = makeHresultMatch.Groups[1].Value.Split(',');
                            if (parts.Length == 3)
                            {
                                this.AddMakeHresultConstant(currentNamespace, name, parts[0].Trim(), parts[1].Trim(), parts[2].Trim());
                                continue;
                            }
                        }

                        Match intCastToLpcstrMatch = IntCastToLpcstrRegex.Match(fixedRawValue);
                        if (intCastToLpcstrMatch.Success)
                        {
                            var nativeStrType = intCastToLpcstrMatch.Groups[1].Value;
                            var value = intCastToLpcstrMatch.Groups[2].Value;
                            this.AddConstantInteger(currentNamespace, nativeStrType, name, value);
                            continue;
                        }

                        if (this.regexConstHelper.TryProcessingLine(currentNamespace, name, fixedRawValue))
                        {
                            continue;
                        }

                        // See if matches one of our well known constants formats
                        Match match = DefineConstantRegex.Match(fixedRawValue);
                        string valueText;
                        string nativeTypeName = null;
                        string matchedConstantType = null;
                        bool matchedToOtherName = false;

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
                            // MAKEINTRESOURCE(-4), MAKEINTRESOURCEA(-1), MAKEINTRESOURCEW(42)
                            else if (!string.IsNullOrEmpty(match.Groups[11].Value))
                            {
                                if (match.Groups[11].Value.StartsWith("MAKEINTRESOURCEA"))
                                {
                                    nativeTypeName = "LPCSTR";
                                }
                                else
                                {
                                    nativeTypeName = "LPCWSTR";
                                }
                                valueText = match.Groups[12].Value;
                                this.AddConstantShort(currentNamespace, nativeTypeName, name, valueText);
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
                            // (IDENT_FOO +/- 4)
                            else if (match.Groups[15].Success)
                            {
                                valueText = match.Groups[15].Value;
                            }
                            // (NTSTATUS)0x00000000L
                            else if (match.Groups[17].Success)
                            {
                                nativeTypeName = "NTSTATUS";
                                valueText = match.Groups[18].Value;
                            }
                            // (DWORD)-1
                            else if (match.Groups[20].Success)
                            {
                                nativeTypeName = "DWORD";
                                valueText = "0xFFFFFFFF";
                            }
                            // (DWORD)0xFFFFFFFF
                            else if (match.Groups[21].Success)
                            {
                                nativeTypeName = "DWORD";
                                valueText = match.Groups[22].Value;
                            }
                            // (BCRYPT_ALG_HANDLE) 0x000001a1
                            else if (match.Groups[23].Success)
                            {
                                nativeTypeName = "BCRYPT_ALG_HANDLE";
                                valueText = match.Groups[24].Value;
                            }
                            // {0xb5367df0,0xcbac,0x11cf,{0x95,0xca,0x00,0x80,0x5f,0x48,0xa1,0x92}}
                            else if (match.Groups[25].Success)
                            {
                                valueText = match.Groups[25].Value.Replace("{", "").Replace("}", "").Replace(" ", "");

                                var defineGuidLine = $"{name}, {valueText})";
                                this.AddConstantGuid("", currentNamespace, defineGuidLine);

                                continue;
                            }
                            // HIDP_ERROR_CODES(0x0,0)
                            else if (match.Groups[26].Success)
                            {
                                nativeTypeName = "NTSTATUS";

                                var SEV = int.Parse(match.Groups[27].Value.Replace("0x", String.Empty), NumberStyles.HexNumber);
                                var CODE = int.Parse(match.Groups[28].Value.Replace("0x", String.Empty), NumberStyles.HexNumber);
                                valueText = $"(({SEV} << 28) | (0x11 << 16) | ({CODE}))";
                                this.AddConstantInteger(currentNamespace, nativeTypeName, name, valueText);

                                continue;
                            }
                            // MAKEDIPROP(1)
                            else if (match.Groups[29].Success)
                            {
                                var value = Convert.ToUInt32(match.Groups[30].Value).ToString("X2");
                                var defineGuidLine = $"{name}, 0x00000000L, 0x0000, 0x0000, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x{value})";
                                this.AddConstantGuid("MAKEDIPROP", currentNamespace, defineGuidLine);

                                continue;
                            }
                            // { 0x35378EAC, 0x683F, 0x11D2, 0xA8, 0x9A, 0x00, 0xC0, 0x4F, 0xBB, 0xCF, 0xA2 }
                            else if (match.Groups[31].Success)
                            {
                                valueText = match.Groups[31].Value.Replace("{", "").Replace("}", "").Replace(" ", "");

                                var defineGuidLine = $"{name}, {valueText})";
                                this.AddConstantGuid("", currentNamespace, defineGuidLine);

                                continue;
                            }
                            // SOME_OTHER_CONSTANT
                            else if (match.Groups[32].Success)
                            {
                                string otherName = match.Groups[32].Value;

                                matchedToOtherName = true;

                                // Only use a constant as the value if we have seen the constant before
                                // and we know its type
                                if (this.writtenConstants.TryGetValue(otherName, out var otherType))
                                {
                                    // Skip guids for now
                                    if (otherType != "Guid")
                                    {
                                        matchedConstantType = otherType;
                                    }
                                }

                                // If we didn't match it to another constant, keep going as we may be setting an enum
                                valueText = otherName;
                            }
                            else
                            {
                                continue;
                            }
                        }
                        else
                        {
                            valueText = rawValue;

                            if (valueText.StartsWith("__TEXT("))
                            {
                                valueText = valueText.Substring(2);
                            }

                            bool isUtf16 = false;
                            if (valueText.StartsWith("TEXT("))
                            {
                                isUtf16 = true;
                                valueText = valueText.Substring("TEXT(".Length);
                                if (valueText.EndsWith(')'))
                                {
                                    valueText = valueText.Substring(0, valueText.Length - 1);
                                }
                            }
                            else if (valueText.StartsWith("L\""))
                            {
                                isUtf16 = true;
                                valueText = valueText.Substring(1);
                            }

                            // Strings can't be part of enums so go ahead and add the constant directly
                            if (valueText.StartsWith('"'))
                            {
                                this.AddConstantValue(currentNamespace, "string", name, valueText, isUtf16 ? "utf-16" : "ansi");
                                continue;
                            }

                            valueText = valueText.Replace("(DWORD)", "(uint)");
                            valueText = valueText.Replace("(ULONG)", "(uint)");
                        }

                        bool updatedEnum = false;

                        // If we see the member is part of an enum, update the member value
                        if (this.enumMemberNameToEnumObj.TryGetValue(name, out var enumObjList))
                        {
                            foreach (EnumObject enumObj in enumObjList)
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
                                        EnumObject foundObjEnum = autoEnumObjsForCurrentHeader[i - 1];
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
                                if (matchedConstantType != null)
                                {
                                    this.AddConstantValue(currentNamespace, matchedConstantType, name, valueText);
                                }
                                else
                                {
                                    // Only add as an int if it didn't match some other constant/enum name
                                    if (!matchedToOtherName)
                                    {
                                        this.AddConstantInteger(currentNamespace, nativeTypeName, name, valueText);
                                    }
                                }
                            }
                        }
                    }
                }
            }

            private void TryScrapingEnumFlags(string line)
            {
                Match match = DefineEnumFlagsRegex.Match(line);
                if (match.Success)
                {
                    var enumName = match.Groups[1].Value;

                    this.InitEnumFlagsFixupFile();
                    this._fileSystem.File.AppendAllText(this.enumFlagsFixupFileName, $"{enumName}\r\n");
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

            private string LookupNamespaceForName(string name)
            {
                if (!this.requiredNamespaces.TryGetValue(name, out var foundNamespace))
                {
                    this.scannedNamesToNamespaces.TryGetValue(name, out foundNamespace);
                }

                // If it contains more than one, just return null
                if (foundNamespace != null && foundNamespace.Contains(';'))
                {
                    foundNamespace = null;
                }

                return foundNamespace;
            }

            private void WriteEnumsAndRemaps(
                Dictionary<string, string> remaps)
            {
                // Output the enums and the rsp entries that map parameters and fields to use
                // enum names
                var enumRemapsFileName = Path.Combine(this.scraperOutputDir, "enumsRemap.rsp");

                bool linesAdded = false;
                using (StreamWriter enumRemapsWriter = new StreamWriter(enumRemapsFileName))
                {
                    enumRemapsWriter.WriteLine("--memberRemap");

                    // For each enum object...
                    foreach (EnumObject obj in this.enumObjectsFromJsons)
                    {
                        string foundNamespace = obj.@namespace;
                        List<string> remapsToAdd = new List<string>();
                        int remapCount = 0;
                        // For each use in an enum...
                        foreach (EnumObject.Use use in obj.uses)
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
                                foundNamespace = this.LookupNamespaceForName(lookupNameForNamespace);
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
                            foundNamespace = "Windows.Win32.System.SystemServices";
                        }

                        bool addedEnum = false;

                        // If the enum doesn't have any remaps and isn't
                        // an auto-populate and has no values, go to next object
                        bool shouldWriteEnum =
                            remapCount != 0 ||
                            obj.autoPopulate != null ||
                            (obj.members != null && obj.members.Any(m => m.value != null));

                        if (!shouldWriteEnum)
                        {
                            continue;
                        }

                        // Lookup the enum writer in the cache or add it if we can't find it
                        if (!this.namespacesToEnumWriters.TryGetValue(foundNamespace, out var enumWriter))
                        {
                            string fixedNamespaceName = foundNamespace.Replace("Windows.Win32.", string.Empty);
                            string enumFile = Path.Combine(this.scraperOutputDir, $"{fixedNamespaceName}.enums.cs");
                            if (this._fileSystem.File.Exists(enumFile))
                            {
                                this._fileSystem.File.Delete(enumFile);
                            }

                            enumWriter = new EnumWriter(enumFile, foundNamespace, this.constantsHeaderText);
                            this.namespacesToEnumWriters.Add(foundNamespace, enumWriter);
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
                                linesAdded = true;
                                enumRemapsWriter.WriteLine($"{remap}={enumName}");

                                remaps.TryAdd(remap, enumName);
                            }
                        }
                    }
                }

                if (!linesAdded)
                {
                    this._fileSystem.File.Delete(enumRemapsFileName);
                }

                if (this.suggestedEnumRenames.Count != 0)
                {
                    this.output.Add("Suggested enum names:");
                    this.output.AddRange(this.suggestedEnumRenames);
                    this.suggestedEnumRenames.Clear();
                }
            }

            private class RegexConstMaker
            {
                public string Pattern { get; set; }
                public string OutputFormat { get; set; }
                public string ConstType { get; set; }
            }

            private class RegexConstHelper : IRegexConstHelper
            {
                private ConstantsScraperImpl owner;
                private List<RegexConstMakerProcessor> processors = new List<RegexConstMakerProcessor>();

                public RegexConstHelper(RegexConstMaker[] regexConstMakers, ConstantsScraperImpl owner)
                {
                    this.owner = owner;
                    foreach (var maker in regexConstMakers)
                    {
                        this.processors.Add(new RegexConstMakerProcessor(maker));
                    }
                }

                public bool TryProcessingLine(string originalNamespace, string constName, string value)
                {
                    foreach (var processor in this.processors)
                    {
                        if (processor.TryProcessingItem(this.owner, originalNamespace, constName, value))
                        {
                            return true;
                        }
                    }

                    return false;
                }

                private class RegexConstMakerProcessor
                {
                    private Regex regex;
                    private RegexConstMaker maker;

                    public RegexConstMakerProcessor(RegexConstMaker maker)
                    {
                        this.regex = new Regex(maker.Pattern);
                        this.maker = maker;
                    }

                    public bool TryProcessingItem(ConstantsScraperImpl scraper, string originalNamespace, string constName, string value)
                    {
                        var match = this.regex.Match(value);
                        if (match.Success)
                        {
                            List<string> items = new List<string>();
                            for (int i = 1; i < match.Groups.Count; i++)
                            {
                                items.Add(match.Groups[i].Value);
                            }

                            string finalValue = string.Format(this.maker.OutputFormat, items.ToArray());
                            scraper.AddConstantValue(originalNamespace, this.maker.ConstType, constName, finalValue);
                            return true;
                        }

                        return false;
                    }
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
