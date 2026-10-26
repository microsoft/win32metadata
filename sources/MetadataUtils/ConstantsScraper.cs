using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.IO.Abstractions;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Text.Json;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;

namespace MetadataUtils
{
    public static partial class ConstantsScraper
    {
        private static readonly Regex DefineRegex =
            new Regex(@"^\s*#\s*define\s+([_A-Za-z][\dA-Za-z_]*)(?:\s+(.*))?$");

        public static string[] ScanObjectLikeMacroNames(IEnumerable<string> headers, IEnumerable<string> includeDirectories)
        {
            string[] roots = includeDirectories.Where(directory => !string.IsNullOrEmpty(directory))
                .Distinct(StringComparer.OrdinalIgnoreCase).ToArray();
            return headers.SelectMany(header => Path.IsPathRooted(header) ? new[] { header } :
                    roots.Select(directory => Path.Combine(directory, header)).Prepend(header))
                .Where(File.Exists).Select(Path.GetFullPath).Distinct(StringComparer.OrdinalIgnoreCase)
                .SelectMany(header => ReadObjectLikeMacroNames(File.ReadLines(header)))
                .Distinct(StringComparer.Ordinal).OrderBy(name => name, StringComparer.Ordinal).ToArray();
        }

        public static IEnumerable<string> ReadObjectLikeMacroNames(IEnumerable<string> lines)
        {
            string continuation = null;
            bool inComment = false;
            foreach (string currentLine in lines)
            {
                string line = continuation == null ? currentLine : continuation + currentLine;
                if (line.EndsWith("\\", StringComparison.Ordinal))
                {
                    continuation = line.Substring(0, line.Length - 1);
                    continue;
                }
                continuation = null;
                line = RemoveComments(line, ref inComment);
                Match match = DefineRegex.Match(line);
                if (match.Success)
                    yield return match.Groups[1].Value;
            }
            if (continuation != null)
            {
                Match match = DefineRegex.Match(RemoveComments(continuation, ref inComment));
                if (match.Success)
                    yield return match.Groups[1].Value;
            }
        }

        private static string RemoveComments(string line, ref bool inComment)
        {
            var text = new StringBuilder(line.Length);
            char quote = '\0';
            for (int index = 0; index < line.Length; index++)
            {
                char character = line[index];
                if (inComment)
                {
                    if (character == '*' && index + 1 < line.Length && line[index + 1] == '/')
                    {
                        inComment = false;
                        index++;
                    }
                    continue;
                }
                if (quote != '\0')
                {
                    text.Append(character);
                    if (character == '\\' && index + 1 < line.Length)
                        text.Append(line[++index]);
                    else if (character == quote)
                        quote = '\0';
                    continue;
                }
                if (character is '"' or '\'')
                    quote = character;
                if (character == '/' && index + 1 < line.Length)
                {
                    if (line[index + 1] == '/')
                        break;
                    if (line[index + 1] == '*')
                    {
                        inComment = true;
                        text.Append(' ');
                        index++;
                        continue;
                    }
                }
                text.Append(character);
            }
            return text.ToString();
        }

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
            Dictionary<string, string> withAttributes) =>
            ScrapeConstants(enumJsonFiles, defaultNamespace, scraperOutputDir, constantsHeaderText, exclusionNames,
                traversedHeaderToNamespaceMap, requiredNamespaces, remaps, withTypes, withAttributes, null);

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
            Dictionary<string, string> withAttributes,
            ConstantSelectionOptions selection)
        {
            using var timing = GenerationTiming.BeginSpan("constants.aggregate");
            using ConstantsScraperImpl imp = new ConstantsScraperImpl();
            return imp.ScrapeConstants(enumJsonFiles, defaultNamespace, scraperOutputDir, constantsHeaderText, exclusionNames, traversedHeaderToNamespaceMap, requiredNamespaces, remaps, withTypes, withAttributes, selection);
        }

        private class ConstantsScraperImpl : IDisposable
        {
            internal static readonly Regex DefineConstantRegex =
                new Regex(
                    @"^((_HRESULT_TYPEDEF_|_NDIS_ERROR_TYPEDEF_)\(((?:0x)?[\da-f]+L?)\)|(\(HRESULT\)((?:0x)?[\da-f]+L?))|(-?\d+\.\d+(?:e\+\d+)?f?)|((?:0x[\da-f]+|\-?\d+)(?:UL|L)?)|((\d+)\s*(<<\s*\d+))|(MAKEINTRESOURCE[AW]{0,1}\(\s*(\-?\d+)\s*\))|(\(HWND\)(-?\d+|(?:0x)?[\da-f]+))|([a-z0-9_]+U?\s*[\+\-]\s*(\d+|0x[0-de-f]+)U?)|(\(NTSTATUS\)((?:0x)?[\da-f]+L?))|(\s*\(DWORD\)\s*\(?\s*-1(L|\b)\s*\)?)|(\(DWORD\)((?:0x)?[\da-f]+L?))|(\(BCRYPT_ALG_HANDLE\)\s*((?:0x)?[\da-f]+L?))|(\{\s*(?:(?:0x)?[\da-f]{4,8}L?,?\s*){3}\s*\{\s*(?:(?:0x)?[\da-f]{1,2}L?,?\s*){8}\s*\}\s*\})|(HIDP_ERROR_CODES\((.*),(.*)\))|(MAKEDIPROP\(\s*(\d+)\s*\))|(\{\s*(?:(?:0x)?[\da-f]{4,8}L?,?\s*){3}\s*(?:(?:0x)?[\da-f]{1,2}L?,?\s*){8}\s*\})|(\(UCHAR\)\s*((?:0x)?\d+))|(\(UCHAR\)\s*(-\d+))|(\(BYTE\)((?:0x)?[\da-f]+L?))|(0x[\da-f]+\s*<<\s*\d+)||(0x[\da-f]+ui64\s*<<\s*\d+)|([a-z0-9_]+))$", RegexOptions.IgnoreCase);

            private static readonly Regex DefineGuidConstRegex =
                new Regex(
                    @"^\s*(DEFINE_GUID|DEFINE_DEVPROPKEY|DEFINE_PROPERTYKEY|DEFINE_KNOWN_FOLDER|OUR_GUID_ENTRY)\s*\((.*)");

            private static readonly Regex DefineAviGuidConstRegex =
                new Regex(
                    @"^\s*(DEFINE_AVIGUID)\s*\(\s*(.*),\s*(.*),\s*(.*),\s*(.*)\s*\);");

            private static readonly Regex DefineMediaTypeGuidConstRegex =
                new Regex(
                    @"^\s*(DEFINE_MEDIATYPE_GUID)\s*\(\s*(\S+),\s*(\S+)\s*\);");

            private static readonly Regex DefinePciRootBusDevPkeyRegex =
                new Regex(
                    @"^\s*(DEFINE_PCI_ROOT_BUS_DEVPKEY)\s*\(\s*(.*),\s*(.*)\s*\);");

            private static readonly Regex DefinePciDeviceDevPkeyRegex =
                new Regex(
                    @"^\s*(DEFINE_PCI_DEVICE_DEVPKEY)\s*\(\s*(.*),\s*(.*)\s*\);");

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

            private const string StringLiteralPattern = @"(?<wide>L)?(?<literal>""(?:\\.|[^""\\])*"")";
            private static readonly Regex StringTermRegex = new Regex(
                @"\G\s*(?:(?<wrapper>TEXT|__TEXT|_T)\s*\(\s*" + StringLiteralPattern +
                @"\s*\)|(?<wrapper>TEXT|_T)\s*\(\s*(?<name>[A-Za-z_]\w*)\s*\)|" +
                StringLiteralPattern + @"|(?<name>[A-Za-z_]\w*))");
            private static readonly HashSet<string> CppKeywords = new HashSet<string>(
                ("alignas alignof and and_eq asm auto bitand bitor bool break case catch char " +
                 "char8_t char16_t char32_t class co_await co_return co_yield compl concept const " +
                 "consteval constexpr constinit const_cast continue decltype default delete do " +
                 "double dynamic_cast else enum explicit export extern false float for friend " +
                 "goto if inline int long mutable namespace new noexcept not not_eq nullptr " +
                 "operator or or_eq private protected public register reinterpret_cast requires " +
                 "return short signed sizeof static static_assert static_cast struct switch " +
                 "template this thread_local throw true try typedef typeid typename union " +
                 "unsigned using virtual void volatile wchar_t while xor xor_eq").Split(' '),
                StringComparer.Ordinal);

            private Dictionary<string, EnumWriter> namespacesToEnumWriters = new();
            private Dictionary<string, IConstantWriter> namespacesToConstantWriters = new();
            private WildcardDictionary requiredNamespaces;
            private Dictionary<string, string> scannedNamesToNamespaces;
            private Dictionary<string, string> writtenConstants;
            private Dictionary<string, string[]> sourceConstantTypes = new(StringComparer.Ordinal);
            private Dictionary<string, ProtectedConstant[]> sourceConstants = new(StringComparer.Ordinal);
            private Dictionary<string, NativeDependency[]> nativeDependencies = new(StringComparer.Ordinal);
            private readonly List<object> legacyDependencyPolicies = new();
            private object nativeConstantReport;
            private string legacyHeader;
            private int legacyLine;
            private HashSet<string> mutableGlobalNames = new(StringComparer.Ordinal);
            private HashSet<string> headerEnumMemberNames = new(StringComparer.Ordinal);
            private Dictionary<string, string> scrapedConstantNamespaces = new(StringComparer.Ordinal);
            private readonly HashSet<string> nativeIntegerHeaders = new(StringComparer.OrdinalIgnoreCase);
            private readonly HashSet<string> nativeIntegerNames = new(StringComparer.Ordinal);
            private readonly HashSet<string> nativePointerNames = new(StringComparer.Ordinal);
            private bool usesNativeIntegers;
            private ConstantSelectionOptions selection = new();
            private Dictionary<string, int> headerPriorities = new(StringComparer.OrdinalIgnoreCase);
            private Dictionary<string, int> headerTraversal = new(StringComparer.OrdinalIgnoreCase);
            private string conflictReport;

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
                Dictionary<string, string> withAttributes,
                ConstantSelectionOptions selection = null)
            {
                using var inputTiming = GenerationTiming.BeginSpan("constants.load-existing-source");
                inputTiming?.SetCounter("traversedHeaderCount", traversedHeaderToNamespaceMap.Count);
                this.requiredNamespaces = new WildcardDictionary(requiredNamespaces);
                this.withTypes = withTypes;
                this.exclusionNames = exclusionNames;
                this.constantsHeaderText = constantsHeaderText;
                this.withAttributes = withAttributes;
                this.scraperOutputDir = scraperOutputDir;
                this.defaultNamespace = defaultNamespace;
                this.selection = selection ?? new ConstantSelectionOptions();
                this.PrepareHeaderPriority(traversedHeaderToNamespaceMap);

                this.regexConstHelper = new RegexConstHelper(regexConstMakers, this);

                this.scannedNamesToNamespaces = ScraperUtils.GetNameToNamespaceMap(scraperOutputDir);

                this.writtenConstants = ScraperUtils.GetConstants(scraperOutputDir, out this.mutableGlobalNames);
                this.headerEnumMemberNames = this.GetHeaderEnumMemberNames();

                this.CleanExistingFiles();

                this.LoadEnumObjectsFromJsonFiles(enumJsonFiles);
                inputTiming?.Dispose();

                this.WriteNativeConstants(traversedHeaderToNamespaceMap);
                try
                {
                    this.ScrapeConstantsFromTraversedFiles(traversedHeaderToNamespaceMap);
                }
                catch (InvalidDataException error)
                {
                    this.WriteRejectedConstantReport(error.Message);
                    throw;
                }
                if (this.nativeConstantReport != null)
                {
                    using var reportTiming = GenerationTiming.BeginSpan("constants.write-conflict-report");
                    this._fileSystem.File.WriteAllText(this.conflictReport, JsonSerializer.Serialize(
                        this.nativeConstantReport, new JsonSerializerOptions { WriteIndented = true }));
                }

                this.WriteEnumsAndRemaps(remaps);

                return new ScraperResults(this.output, this.conflictReport);
            }

            public void Dispose()
            {
                using var timing = GenerationTiming.BeginSpan("constants.flush-csharp-writers");
                timing?.SetCounter("enumWriterCount", this.namespacesToEnumWriters.Count);
                timing?.SetCounter("constantWriterCount", this.namespacesToConstantWriters.Count);
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

                    if (!inQuote && rawValue[i] == '/')
                    {
                        if (rawValue[i + 1] == '/')
                        {
                            // Remove trailing line comments.
                            return rawValue.Substring(0, i).Trim();
                        }
                        else if (rawValue[i + 1] == '*')
                        {
                            if (rawValue.LastIndexOf("*/") == -1)
                            {
                                // Remove trailing block comments that aren't closed.
                                return rawValue.Substring(0, i).Trim();
                            }
                            else
                            {
                                // Remove inline block comments that are closed.
                                return rawValue.Substring(0, i).Trim() + rawValue.Substring(rawValue.LastIndexOf("*/") + 2).Trim();
                            }
                        }
                    }
                }

                return rawValue;
            }

            private void CleanExistingFiles()
            {
                foreach (string file in this._fileSystem.Directory.GetFiles(this.scraperOutputDir,
                    "NativeConstants.*.header-types.cs", SearchOption.AllDirectories))
                    this._fileSystem.File.Delete(file);
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
                if (this.usesNativeIntegers || this.writtenConstants.ContainsKey(name) || this.sourceConstantTypes.ContainsKey(name))
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
                if (this.writtenConstants.ContainsKey(name) || this.sourceConstantTypes.ContainsKey(name) || this.usesNativeIntegers &&
                    type is "bool" or "char" or "sbyte" or "byte" or "short" or "ushort" or "int" or "uint" or "long" or "ulong")
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
                if (this.writtenConstants.ContainsKey(name) || this.sourceConstantTypes.ContainsKey(name) ||
                    this.usesNativeIntegers && !this.nativePointerNames.Contains(name))
                {
                    return;
                }

                string forcedType = nativeTypeName != null ? null : this.GetForcedTypeForName(name);
                string dependencyType = null;
                bool nativeDependency = nativeTypeName == null && this.TryGetNativeDependencyType(name, out dependencyType);
                if (nativeDependency)
                    forcedType = dependencyType;

                var writer = this.GetConstantWriter(originalNamespace, name);
                writer.AddInt(forcedType, nativeTypeName, name, valueText, out var finalType);

                this.writtenConstants.Add(name, finalType);
                if (nativeDependency)
                    this.RecordNativeDependencyPolicy(name, name, finalType, valueText);
            }

            private void AddConstantShort(string originalNamespace, string nativeTypeName, string name, string valueText)
            {
                if (this.writtenConstants.ContainsKey(name) || this.sourceConstantTypes.ContainsKey(name) ||
                    this.usesNativeIntegers && !this.nativePointerNames.Contains(name))
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
                this.scrapedConstantNamespaces[name] = foundNamespace;

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

            private HashSet<string> GetHeaderEnumMemberNames()
            {
                var files = this._fileSystem.Directory.GetFiles(this.scraperOutputDir, "*header-types.cs", SearchOption.AllDirectories)
                    .Where(file => Path.GetFileName(file) == "header-types.cs" || file.EndsWith(".header-types.cs", StringComparison.Ordinal));
                var members = new HashSet<string>(StringComparer.Ordinal);
                foreach (var group in LoadEnumsFromSourceFiles(files))
                {
                    string groupNamespace = this.LookupNamespaceForName(group.name) ?? group.@namespace;
                    foreach (var member in group.members)
                        members.Add($"{groupNamespace}.{member.name}");
                }
                return members;
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

            private void PrepareHeaderPriority(Dictionary<string, string> traversedFileMap)
            {
                this.headerTraversal = traversedFileMap.Keys.Select((header, index) => (Header: Path.GetFullPath(header), index))
                    .ToDictionary(value => value.Header, value => value.index, StringComparer.OrdinalIgnoreCase);
                if (this.selection.HeaderPriority.Count != 0 && string.IsNullOrWhiteSpace(this.selection.SdkRoot))
                    throw new ArgumentException("Header priority requires an explicit SDK include root.");
                var seen = new HashSet<string>(StringComparer.OrdinalIgnoreCase);
                for (int i = 0; i < this.selection.HeaderPriority.Count; i++)
                {
                    string relative = this.selection.HeaderPriority[i].Replace(Path.AltDirectorySeparatorChar, Path.DirectorySeparatorChar);
                    if (string.IsNullOrWhiteSpace(relative) || Path.IsPathRooted(relative) ||
                        relative.Split(Path.DirectorySeparatorChar).Any(part => part is "" or "." or "..") || !seen.Add(relative))
                        throw new ArgumentException($"Invalid or repeated SDK-root-relative priority header '{relative}'.");
                    string full = Path.GetFullPath(Path.Combine(this.selection.SdkRoot, relative));
                    this.headerPriorities.Add(full, i);
                }
            }

            private IEnumerable<KeyValuePair<string, string>> OrderedHeaders(Dictionary<string, string> headers) =>
                headers.OrderBy(pair => this.headerPriorities.GetValueOrDefault(Path.GetFullPath(pair.Key), int.MaxValue));

            private sealed record NativeInput(string Path, NativeConstantValues Values, int Order);
            private sealed record NativeCandidate(
                NativeInput Input, NativeConstantValue Value, string Header, string Namespace, int HeaderPriority, int TraversalOrder);
            private sealed record ProtectedConstant(
                string Name, string Namespace, string Owner, string Source, Architecture Architecture, string StorageType,
                string Expression, NativeConstantGroupSource Proof, string DeclaredName, string SourceKind);
            private sealed record NativeDependency(NativeCandidate Candidate, ProtectedConstant Owner);

            private void WriteNativeConstants(Dictionary<string, string> traversedFileMap)
            {
                try
                {
                    this.WriteNativeConstantsCore(traversedFileMap);
                }
                catch (InvalidDataException error)
                {
                    this.WriteRejectedConstantReport(error.Message);
                    throw;
                }
                catch (JsonException error)
                {
                    this.WriteRejectedConstantReport(error.Message);
                    throw;
                }
            }

            private void WriteRejectedConstantReport(string error)
            {
                using var timing = GenerationTiming.BeginSpan("constants.write-rejection-report");
                this.conflictReport = Path.Combine(this.scraperOutputDir, "native-constant-conflicts.json");
                this._fileSystem.File.WriteAllText(this.conflictReport, JsonSerializer.Serialize(new
                {
                    Version = 1, Status = "rejected", Error = error, this.selection.SdkRoot,
                    this.selection.HeaderPriority, this.selection.NativeInputs,
                    RawInputs = this._fileSystem.Directory.GetFiles(this.scraperOutputDir,
                        "*.native-constants.json", SearchOption.AllDirectories).Select(path => new
                        {
                            Path = path, Contents = this._fileSystem.File.ReadAllText(path),
                        }).ToArray(),
                }, new JsonSerializerOptions { WriteIndented = true }));
            }

            private void WriteNativeConstantsCore(Dictionary<string, string> traversedFileMap)
            {
                using var timing = GenerationTiming.BeginSpan("constants.native-inputs");
                using var loadTiming = GenerationTiming.BeginSpan("constants.load-native-facts");
                var headers = traversedFileMap.ToDictionary(pair => Path.GetFullPath(pair.Key), pair => pair.Value,
                    StringComparer.OrdinalIgnoreCase);
                string[] discovered = this._fileSystem.Directory.GetFiles(this.scraperOutputDir,
                    "*.native-constants.json", SearchOption.AllDirectories);
                string[] paths = this.selection.NativeInputs.Count == 0 ? discovered :
                    this.selection.NativeInputs.Select(Path.GetFullPath).ToArray();
                if (paths.Distinct(StringComparer.OrdinalIgnoreCase).Count() != paths.Length ||
                    !paths.ToHashSet(StringComparer.OrdinalIgnoreCase).SetEquals(discovered.Select(Path.GetFullPath)))
                    throw new InvalidDataException("The native constant input plan must name every current input exactly once.");
                var inputs = paths.Select((path, index) => new NativeInput(path,
                    JsonSerializer.Deserialize<NativeConstantValues>(this._fileSystem.File.ReadAllText(path)) ??
                        throw new InvalidDataException($"Invalid native constants file '{path}'."), index)).ToArray();
                foreach (var input in inputs)
                {
                    if (input.Values.Architecture is not (Architecture.X86 or Architecture.X64 or Architecture.Arm64))
                        throw new InvalidDataException($"Invalid native constant architecture '{input.Values.Architecture}'.");
                    if (input.Values.Headers == null || input.Values.Constants == null ||
                        input.Values.Issues == null || input.Values.Groups == null)
                        throw new InvalidDataException($"Missing native constant input collections in '{input.Path}'.");
                    this.nativeIntegerHeaders.UnionWith(input.Values.Headers.Select(header => ResolveHeader(input, header)));
                    this.nativePointerNames.UnionWith(input.Values.Issues.Where(issue => issue.Reason == "pointer constant").Select(issue => issue.Name));
                }
                loadTiming?.SetCounter("inputCount", inputs.Length);
                loadTiming?.SetCounter("acceptedFactCount", inputs.Sum(input => (long)input.Values.Constants.Count));
                loadTiming?.SetCounter("rejectedFactCount", inputs.Sum(input => (long)input.Values.Issues.Count));
                loadTiming?.Dispose();
                if (inputs.Length == 0 &&
                    !this._fileSystem.Directory.GetFiles(this.scraperOutputDir, "*header-types.cs", SearchOption.AllDirectories)
                        .Where(file => Path.GetFileName(file) == "header-types.cs" ||
                            file.EndsWith(".header-types.cs", StringComparison.Ordinal))
                        .Any(file => this._fileSystem.File.ReadAllText(file)
                            .StartsWith(HeaderTypesSourceFamily.SuccessMarker, StringComparison.Ordinal)))
                    return;
                using var ownersTiming = GenerationTiming.BeginSpan("constants.load-source-owners");
                var protectedConstants = new List<ProtectedConstant>();
                var missingProofs = new List<string>();
                foreach (string file in this._fileSystem.Directory.GetFiles(this.scraperOutputDir, "*.cs", SearchOption.AllDirectories)
                    .Where(file => !NativeConstantValues.IsGeneratedSource(file) &&
                        !file.EndsWith(".modified.cs", StringComparison.Ordinal) &&
                        !file.EndsWith(".constants.cs", StringComparison.Ordinal) &&
                        !file.EndsWith(".enums.cs", StringComparison.Ordinal)))
                {
                    var architecture = Path.GetDirectoryName(file).Split(Path.DirectorySeparatorChar, Path.AltDirectorySeparatorChar)
                        .Select(part => part switch
                        {
                            "x86" => Architecture.X86, "x64" => Architecture.X64, "arm64" => Architecture.Arm64,
                            _ => Architecture.None,
                        }).LastOrDefault(value => value != Architecture.None);
                    if (architecture == Architecture.None)
                        architecture = Architecture.All;
                    string text = this._fileSystem.File.ReadAllText(file);
                    var root = SyntaxFactory.ParseCompilationUnit(text);
                    bool headerSource = Path.GetFileName(file) == "header-types.cs" ||
                        file.EndsWith(".header-types.cs", StringComparison.Ordinal);
                    foreach (var group in root.DescendantNodes().OfType<EnumDeclarationSyntax>().Where(group =>
                        group.Parent is BaseNamespaceDeclarationSyntax or CompilationUnitSyntax))
                    {
                        var proof = NativeConstantGroupProvenance.Read(group);
                        string originalNamespace = NamespaceOf(group);
                        if (proof != null && (proof.Group.Namespace != originalNamespace ||
                            !architecture.HasFlag(proof.Architecture) ||
                            (headerSource ? proof.Group.Kind != "LogicalGroup" ||
                                !text.StartsWith(HeaderTypesSourceFamily.SuccessMarker, StringComparison.Ordinal) :
                                proof.Group.Kind != "NativeEnum")))
                            throw new InvalidDataException($"Native constant group producer/namespace/target drift in '{file}'.");
                        if (group.AttributeLists.SelectMany(list => list.Attributes).Any(attribute =>
                            attribute.Name.ToString().Split('.').Last() is "ScopedEnum" or "ScopedEnumAttribute"))
                            continue;
                        if (headerSource && proof == null)
                            missingProofs.Add(file);
                        string ns = this.LookupNamespaceForName(group.Identifier.ValueText) ?? originalNamespace;
                        foreach (var member in group.Members)
                            protectedConstants.Add(new ProtectedConstant(member.Identifier.ValueText, ns, group.Identifier.ValueText,
                                file, architecture, group.BaseList?.Types.Single().Type.ToString() ?? "int",
                                member.EqualsValue?.Value.ToString(), proof, member.Identifier.ValueText,
                                headerSource ? "logical-header-group" : "ordinary-unscoped-enum"));
                    }
                    foreach (var field in root.DescendantNodes().OfType<FieldDeclarationSyntax>().Where(field =>
                        field.Parent is ClassDeclarationSyntax type && type.Identifier.ValueText == "Apis" &&
                        (field.Modifiers.Any(SyntaxKind.ConstKeyword) ||
                            field.Modifiers.ToString() == "public static readonly" &&
                            field.Declaration.Type.ToString() != "Guid" &&
                            field.Declaration.Variables.First().Identifier.ValueText.StartsWith("__forceconst__", StringComparison.Ordinal))))
                        foreach (var variable in field.Declaration.Variables)
                        {
                            string declaredName = variable.Identifier.ValueText;
                            string name = NativeMemberNameProvenance.GetProjectedFieldName(field, declaredName);
                            if (name.StartsWith("__forceconst__", StringComparison.Ordinal))
                                name = name.Substring("__forceconst__".Length);
                            string ns = this.LookupNamespaceForName(declaredName) ?? NamespaceOf(field);
                            protectedConstants.Add(new ProtectedConstant(name, ns, "Apis", file, architecture,
                                field.Declaration.Type.ToString(), variable.Initializer?.Value.ToString(), null,
                                declaredName, "apis-constant"));
                        }
                }
                this.sourceConstants = protectedConstants.GroupBy(value => value.Name, StringComparer.Ordinal)
                    .ToDictionary(group => group.Key, group => group.ToArray(), StringComparer.Ordinal);
                this.sourceConstantTypes = this.sourceConstants.ToDictionary(pair => pair.Key,
                    pair => pair.Value.Select(GetSourceDependencyStorageType).Distinct(StringComparer.Ordinal).ToArray(),
                    StringComparer.Ordinal);
                ownersTiming?.SetCounter("protectedConstantCount", protectedConstants.Count);
                ownersTiming?.Dispose();
                if (inputs.Length == 0)
                    return;
                using var resolutionTiming = GenerationTiming.BeginSpan("constants.resolve-ownership-types-aliases");
                var protectionsByName = protectedConstants.ToLookup(value => value.Name, StringComparer.Ordinal);
                var proofSources = protectedConstants.Where(value => value.Proof != null)
                    .ToLookup(value => value.Proof, value => value.Source);
                var proofIds = proofSources.Select((value, index) => (value.Key, index))
                    .ToDictionary(value => value.Key, value => value.index);
                var inputsBySource = inputs.ToLookup(input => (input.Values.Architecture, input.Values.SourceFile));
                var bindingCache = new Dictionary<(NativeInput Input, NativeConstantGroupSource Proof),
                    ILookup<string, NativeConstantBinding>>();
                var boundProtections = new Dictionary<(Architecture Target, string Kind, string NativeName), HashSet<ProtectedConstant>>();
                foreach (var protection in protectedConstants.Where(value => value.Proof != null))
                    foreach (var input in inputs.Where(input => protection.Architecture.HasFlag(input.Values.Architecture) &&
                        input.Values.SourceFile == protection.Proof.SourceFile))
                        foreach (var binding in CompilerBindings(input, protection).Where(binding => binding.Kind != "Expression"))
                        {
                            var key = (input.Values.Architecture, binding.Kind, binding.NativeName);
                            if (!boundProtections.TryGetValue(key, out var owners))
                                boundProtections.Add(key, owners = new());
                            owners.Add(protection);
                        }
                var candidates = new List<NativeCandidate>();
                foreach (var input in inputs)
                    foreach (var value in input.Values.Constants)
                    {
                        string header = ResolveHeader(input, value.Header);
                        if (!headers.TryGetValue(header, out string ns) ||
                            this.ShouldExclude(value.NativeName) || this.ShouldExclude(value.Name))
                            continue;
                        this.nativeIntegerNames.Add(value.NativeName);
                        if (value.AliasTarget != null && (value.AliasTarget.Kind != "CXCursor_EnumConstantDecl" ||
                            string.IsNullOrEmpty(value.AliasTarget.NativeName) ||
                            string.IsNullOrEmpty(value.AliasTarget.Header) || value.AliasTarget.Line == 0 ||
                            value.AliasTarget.Column == 0 || value.AliasTarget.HeaderHash?.Length != 64 ||
                            !value.AliasTarget.HeaderHash.All(Uri.IsHexDigit) ||
                            value.AliasTarget.NativeType != value.NativeType ||
                            value.AliasTarget.StorageType != value.StorageType || value.AliasTarget.Value != value.Value ||
                            string.IsNullOrEmpty(input.Values.SourceFile) || input.Values.SourceHash?.Length != 64 ||
                            !input.Values.SourceHash.All(Uri.IsHexDigit)))
                            throw new InvalidDataException($"Invalid compiler-bound native alias in '{input.Path}'.");
                        ns = this.LookupNamespaceForName(value.Name) ?? ns;
                        candidates.Add(new NativeCandidate(input, value, header, ns,
                            this.headerPriorities.GetValueOrDefault(header, int.MaxValue), this.headerTraversal[header]));
                    }
                var constants = new Dictionary<(Architecture Architecture, string Namespace, string Name), NativeConstantValue>();
                var decisions = new List<object>();
                var nativeDependencies = new List<NativeDependency>();
                foreach (var group in candidates.GroupBy(candidate => (candidate.Input.Values.Architecture, candidate.Value.Name)))
                {
                    var ordered = group.OrderBy(candidate => candidate.HeaderPriority).ThenBy(candidate => candidate.TraversalOrder)
                        .ThenBy(candidate => candidate.Value.Line).ThenBy(candidate => candidate.Value.Column)
                        .ThenBy(candidate => candidate.Input.Order).ToArray();
                    var protections = protectionsByName[group.Key.Name].Where(value =>
                            value.Architecture.HasFlag(group.Key.Architecture))
                        .Concat(ordered.SelectMany(candidate => NativeOwners(candidate))
                            .Where(protection => ordered.Any(candidate => IsCompilerBound(candidate, protection))))
                        .Distinct().ToArray();
                    var ownership = ordered.Distinct().ToDictionary(candidate => candidate,
                        candidate => protections.Where(protection => IsCompilerBound(candidate, protection)).ToArray());
                    foreach (var candidate in ordered)
                        foreach (var owner in ownership[candidate].Where(owner =>
                            owner.SourceKind == "logical-header-group" && owner.Name != candidate.Value.NativeName &&
                            CompilerBindings(candidate.Input, owner).Length == 1 &&
                            IsCompilerBound(candidate, owner, alias: false)))
                            nativeDependencies.Add(new NativeDependency(candidate, owner));
                    var selected = protections.Length == 0 ? ordered[0] : null;
                    if (selected != null)
                        constants.Add((group.Key.Architecture, selected.Namespace, selected.Value.Name), selected.Value);
                    var boundDefinitions = protections.Where(protection => protection.Proof != null)
                        .SelectMany(protection => inputsBySource[(group.Key.Architecture, protection.Proof.SourceFile)]
                            .SelectMany(input => CompilerBindings(input, protection)
                                .Select(binding => new { Protection = protection, Input = input, Binding = binding,
                                    Header = ResolveHeader(input, binding.Header) }))).Distinct().ToArray();
                    bool typeValueConflict = ordered.Select(candidate =>
                        (candidate.Value.NativeType, candidate.Value.StorageType, candidate.Value.Value))
                        .Concat(boundDefinitions.Select(definition =>
                            (definition.Binding.NativeType, definition.Binding.StorageType, definition.Binding.Value)))
                        .Concat(ordered.Where(candidate => candidate.Value.AliasTarget != null).Select(candidate =>
                            (candidate.Value.AliasTarget.NativeType, candidate.Value.AliasTarget.StorageType, candidate.Value.AliasTarget.Value)))
                        .Distinct().Count() > 1;
                    bool projectedTypeConflict = protections.Any(protection => protection.Owner == "Apis" &&
                        ordered.Any(candidate => IsIntegralType(protection.StorageType) &&
                            protection.StorageType != candidate.Value.StorageType));
                    bool distinctDefinitions = ordered.Select(candidate =>
                        (Kind: "Macro", candidate.Value.NativeName, candidate.Header, candidate.Value.Line, candidate.Value.Column))
                        .Concat(boundDefinitions.Select(definition =>
                            (definition.Binding.Kind, definition.Binding.NativeName, definition.Header, definition.Binding.Line, definition.Binding.Column))).Distinct().Count() > 1;
                    bool unrelatedProtection = protections.Length != 0 && ordered.Any(candidate => ownership[candidate].Length == 0);
                    string reason = protections.Length != 0 ? "protected-source-declaration" :
                        ordered[0].HeaderPriority != int.MaxValue ? "explicit-sdk-header-priority" : "first-header-traversal-and-native-location";
                    if (ordered.Length > 1 || protections.Length != 0 || ordered.Any(candidate => candidate.Value.AliasTarget != null))
                        decisions.Add(new
                        {
                            Name = group.Key.Name, Target = group.Key.Architecture.ToString(), Reason = reason,
                            TypeValueConflict = typeValueConflict, DistinctNativeDefinitions = distinctDefinitions,
                            ProjectedTypeConflict = projectedTypeConflict,
                            UnrelatedProtectedDefinition = unrelatedProtection,
                            Selected = selected == null ? null : Describe(selected, "selected", reason),
                            Protected = protections.Select(value => new
                            {
                                value.Name, value.DeclaredName, value.SourceKind, value.Namespace, value.Owner, Source = value.Source, value.StorageType,
                                Value = value.Expression, Target = group.Key.Architecture.ToString(),
                                Provenance = value.Proof == null ? (int?)null : proofIds[value.Proof],
                                NativeBindings = boundDefinitions.Where(definition => definition.Protection == value)
                                    .Select(definition => new { NativeInput = definition.Input.Path, definition.Binding }).ToArray(),
                                Disposition = "selected-authoritative-source", Reason = "protected-source-declaration",
                            }).ToArray(),
                            Candidates = ordered.Select(candidate => Describe(candidate,
                                candidate == selected ? "selected" : ownership[candidate].Length == 0 ? "discarded-by-policy" :
                                    ownership[candidate].Any(protection => IsCompilerBound(candidate, protection, alias: true)) ?
                                        "compiler-bound-native-alias" : "compiler-bound-group-consumption",
                                ownership[candidate].Length == 0 ? reason :
                                    ownership[candidate].Any(protection => IsCompilerBound(candidate, protection, alias: true)) ?
                                        "exact-native-alias-and-published-name-collision" : "exact-native-member-binding")).ToArray(),
                        });
                    if (typeValueConflict || projectedTypeConflict || distinctDefinitions || unrelatedProtection)
                        this.output.Add($"warning WMC001: Constant '{group.Key.Name}' on {group.Key.Architecture}: " +
                            $"{(typeValueConflict ? "TYPE/VALUE CONFLICT; " : "")}" +
                            $"{(projectedTypeConflict ? "PROJECTED TYPE CONFLICT; " : "")}{reason}; " +
                            $"selected {(selected == null ? string.Join(", ", protections.Select(value => value.Namespace + "." + value.Owner)) : selected.Header)}. " +
                            $"All {ordered.Length} native candidates are retained in native-constant-conflicts.json.");
                }
                foreach (var constant in constants)
                    if (this.sourceConstantTypes.TryGetValue(constant.Key.Name, out var types))
                        this.sourceConstantTypes[constant.Key.Name] = types.Append(constant.Value.StorageType)
                            .Distinct(StringComparer.Ordinal).ToArray();
                var nativeSelections = constants.ToLookup(value => value.Key.Name, StringComparer.Ordinal);
                this.nativeDependencies = nativeDependencies.GroupBy(value => value.Candidate.Value.NativeName, StringComparer.Ordinal)
                    .ToDictionary(group => group.Key, group => group.Distinct().ToArray(), StringComparer.Ordinal);
                this.conflictReport = Path.Combine(this.scraperOutputDir, "native-constant-conflicts.json");
                this.nativeConstantReport = new
                {
                    Version = 1, Status = "completed", SdkRoot = this.selection.SdkRoot, NameComparison = "Ordinal",
                    PublishedAliasCollisionComparison = "OrdinalIgnoreCaseAfterExactNativeBinding",
                    HeaderPriority = this.selection.HeaderPriority.Select((header, rank) => new
                    {
                        Header = header, Rank = rank,
                        Applicable = this.headerTraversal.ContainsKey(Path.GetFullPath(Path.Combine(this.selection.SdkRoot, header))),
                    }).ToArray(),
                    NativeInputs = inputs.Select(input => new { input.Path, input.Order, input.Values.BindingSource,
                        input.Values.SourceFile, input.Values.SourceHash, Target = input.Values.Architecture.ToString(),
                        input.Values.Issues, input.Values.Groups }).ToArray(),
                    SourceGroups = proofIds.Select(pair => new { Id = pair.Value,
                        Sources = proofSources[pair.Key].Distinct().ToArray(), Provenance = pair.Key }).ToArray(),
                    SourceDependencies = protectedConstants.GroupBy(value => value.Name, StringComparer.Ordinal).Select(group => new
                    {
                        Name = group.Key, StorageTypes = this.sourceConstantTypes[group.Key],
                        Reason = group.Any(value => GetSourceDependencyStorageType(value) != value.StorageType) ?
                            "compiler-bound-logical-member-primitive-storage-not-native-consumption" :
                            "authoritative-managed-declaration-storage-not-native-consumption",
                        Declarations = group.Select(value => new
                        {
                            value.Name, value.DeclaredName, value.SourceKind, value.Namespace, value.Owner, value.Source,
                            Target = value.Architecture.ToString(), value.StorageType, Value = value.Expression,
                            DependencyStorageType = GetSourceDependencyStorageType(value),
                            Provenance = value.Proof == null ? (int?)null : proofIds[value.Proof],
                        }).ToArray(),
                        NativeSelections = nativeSelections[group.Key].Select(value => new
                        {
                            Target = value.Key.Architecture.ToString(), value.Key.Namespace, value.Value.StorageType,
                        }).ToArray(),
                    }).ToArray(),
                    NativeDependencies = this.nativeDependencies.Select(pair => new
                    {
                        NativeName = pair.Key,
                        StorageTypes = pair.Value.Select(value => value.Candidate.Value.StorageType).Distinct(StringComparer.Ordinal).ToArray(),
                        Reason = "compiler-bound-consumed-macro-primitive-for-legacy-dependencies",
                        Definitions = pair.Value.Select(value => new
                        {
                            Candidate = Describe(value.Candidate, "compiler-bound-group-consumption", "exact-native-member-binding"),
                            value.Owner.Name, value.Owner.DeclaredName, value.Owner.Namespace, value.Owner.Owner,
                            value.Owner.Source, value.Owner.StorageType,
                            Provenance = proofIds[value.Owner.Proof],
                        }).ToArray(),
                    }).ToArray(),
                    LegacyDependencyPolicies = this.legacyDependencyPolicies,
                    MissingGroupProvenance = missingProofs.Distinct().ToArray(), Decisions = decisions,
                };
                resolutionTiming?.SetCounter("candidateCount", candidates.Count);
                resolutionTiming?.SetCounter("selectedCount", constants.Count);
                resolutionTiming?.SetCounter("decisionCount", decisions.Count);
                resolutionTiming?.SetCounter("nativeDependencyCount", nativeDependencies.Count);
                resolutionTiming?.Dispose();
                using var outputTiming = GenerationTiming.BeginSpan("constants.write-native-csharp");
                outputTiming?.SetCounter("constantCount", constants.Count);
                string[] namespaces = constants.Keys.Select(key => key.Namespace).Distinct(StringComparer.Ordinal)
                    .OrderBy(value => value, StringComparer.Ordinal).ToArray();
                foreach (var architecture in inputs.Select(input => input.Values.Architecture).Distinct())
                    foreach (string ns in namespaces)
                    {
                        string directory = Path.Combine(this.scraperOutputDir, architecture.ToString().ToLowerInvariant());
                        this._fileSystem.Directory.CreateDirectory(directory);
                        string path = Path.Combine(directory, $"NativeConstants.{ns}.header-types.cs");
                        using var stream = this._fileSystem.File.OpenWrite(path);
                        byte[] marker = Encoding.UTF8.GetBytes(HeaderTypesSourceFamily.SuccessMarker + Environment.NewLine);
                        stream.Write(marker, 0, marker.Length);
                        using var writer = new ConstantWriter(stream, ns, this.constantsHeaderText, this.withAttributes);
                        foreach (var pair in constants.Where(pair => pair.Key.Architecture == architecture && pair.Key.Namespace == ns)
                            .OrderBy(pair => pair.Key.Name, StringComparer.Ordinal))
                        {
                            writer.AddNativeInteger(pair.Value);
                            this.writtenConstants.TryAdd(pair.Value.Name, pair.Value.StorageType);
                            this.scrapedConstantNamespaces[pair.Value.Name] = ns;
                        }
                    }
                this.output.Add($"Wrote {constants.Count} native integer constants from {inputs.Length} header compilations.");

                string ResolveHeader(NativeInput input, string header)
                {
                    string full = Path.GetFullPath(header);
                    if (headers.ContainsKey(full))
                        return full;
                    string originalDirectory = input.Values.BindingSource.EndsWith(".cs", StringComparison.Ordinal)
                        ? Path.GetDirectoryName(input.Values.BindingSource) : input.Values.BindingSource;
                    string relative = Path.GetRelativePath(originalDirectory, full);
                    if (Path.IsPathRooted(relative))
                        return full;
                    string relocated = Path.GetFullPath(Path.Combine(Path.GetDirectoryName(input.Path), relative));
                    return headers.ContainsKey(relocated) ? relocated : full;
                }

                bool IsCompilerBound(NativeCandidate candidate, ProtectedConstant protection, bool? alias = null)
                {
                    if (alias == null)
                        return IsCompilerBound(candidate, protection, alias: false) || IsCompilerBound(candidate, protection, alias: true);
                    var target = alias.Value ? candidate.Value.AliasTarget : new NativeConstantBinding("Macro", candidate.Value.NativeName,
                        candidate.Value.Header, candidate.Value.Line, candidate.Value.Column, candidate.Value.HeaderHash,
                        candidate.Value.NativeType, candidate.Value.StorageType, candidate.Value.Value);
                    if (target == null)
                        return false;
                    var definitions = CompilerBindings(candidate.Input, protection).Where(binding => binding.Kind == target.Kind &&
                        binding.NativeName == target.NativeName).ToArray();
                    var bindings = definitions.Where(binding =>
                        string.Equals(ResolveHeader(candidate.Input, binding.Header), ResolveHeader(candidate.Input, target.Header), StringComparison.OrdinalIgnoreCase) &&
                        binding.Line == target.Line && binding.Column == target.Column).ToArray();
                    if (alias.Value && definitions.Length != 0 && bindings.Length == 0)
                        throw new InvalidDataException($"Native constant alias definition location drift for '{candidate.Value.NativeName}' in '{candidate.Input.Path}'.");
                    if (bindings.Any(binding => binding.HeaderHash != target.HeaderHash))
                        throw new InvalidDataException($"Native constant definition hash drift for '{candidate.Value.NativeName}' in '{candidate.Input.Path}'.");
                    bool bound = bindings.Any(binding => binding.NativeType == target.NativeType &&
                        binding.StorageType == target.StorageType && binding.Value == target.Value);
                    if (alias.Value && bindings.Length != 0 && !bound)
                        throw new InvalidDataException($"Native constant alias binding drift for '{candidate.Value.NativeName}' in '{candidate.Input.Path}'.");
                    // Match the existing publication gate only after exact case-sensitive native binding.
                    return bound && (!alias.Value ||
                        string.Equals(candidate.Value.Name, protection.Name, StringComparison.OrdinalIgnoreCase));
                }

                IEnumerable<ProtectedConstant> NativeOwners(NativeCandidate candidate)
                {
                    if (boundProtections.TryGetValue((candidate.Input.Values.Architecture, "Macro", candidate.Value.NativeName),
                        out var macros))
                        foreach (var protection in macros)
                            yield return protection;
                    var target = candidate.Value.AliasTarget;
                    if (target != null && boundProtections.TryGetValue(
                        (candidate.Input.Values.Architecture, target.Kind, target.NativeName), out var aliases))
                        foreach (var protection in aliases)
                            yield return protection;
                }

                static bool IsIntegralType(string type) => type is "bool" or "char" or "sbyte" or "byte" or
                    "short" or "ushort" or "int" or "uint" or "long" or "ulong";

                NativeConstantBinding[] CompilerBindings(NativeInput input, ProtectedConstant protection)
                {
                    var proof = protection.Proof;
                    if (proof == null || proof.SourceFile != input.Values.SourceFile)
                        return Array.Empty<NativeConstantBinding>();
                    if (!bindingCache.TryGetValue((input, proof), out var bindings))
                    {
                        if (proof.SourceHash != input.Values.SourceHash)
                            throw new InvalidDataException($"Native constant source-family hash drift in '{input.Path}'.");
                        var groups = input.Values.Groups.Where(value => value.NativeName == proof.Group.NativeName &&
                            value.Name == proof.Group.Name && value.Namespace == proof.Group.Namespace).ToArray();
                        if (groups.Length != 0)
                        {
                            if (groups.Length != 1 || groups[0].Kind != proof.Group.Kind || groups[0].StorageType != proof.Group.StorageType ||
                                !string.Equals(ResolveHeader(input, groups[0].Header),
                                    ResolveHeader(input, proof.Group.Header), StringComparison.OrdinalIgnoreCase) ||
                                groups[0].Line != proof.Group.Line ||
                                !groups[0].Members.Select(value => (value.Name, value.Expression))
                                    .SequenceEqual(proof.Group.Members.Select(value => (value.Name, value.Expression))))
                                throw new InvalidDataException($"Native constant group declaration/target drift for '{proof.Group.Name}' in '{input.Path}'.");
                            if (input.Values.Architecture == proof.Architecture &&
                                JsonSerializer.Serialize(groups[0]) != JsonSerializer.Serialize(proof.Group))
                                throw new InvalidDataException($"Native constant group binding drift for '{proof.Group.Name}' in '{input.Path}'.");
                        }
                        bindings = groups.SelectMany(group => group.Members)
                            .SelectMany(member => member.Bindings.Select(binding => (member.Name, Binding: binding)))
                            .ToLookup(value => value.Name, value => value.Binding, StringComparer.Ordinal);
                        bindingCache.Add((input, proof), bindings);
                    }
                    return bindings[protection.Name].ToArray();
                }

                object Describe(NativeCandidate candidate, string disposition, string reason) => new
                {
                    candidate.Value.Name, candidate.Namespace, Kind = "Macro", candidate.Value.NativeName,
                    candidate.Value.NativeType, candidate.Value.StorageType, candidate.Value.Value,
                    candidate.Value.AliasTarget,
                    RawHeader = candidate.Value.Header, ResolvedHeader = candidate.Header,
                    SdkRelativeHeader = string.IsNullOrEmpty(this.selection.SdkRoot) ? null :
                        Path.GetRelativePath(Path.GetFullPath(this.selection.SdkRoot), candidate.Header),
                    candidate.Value.Line, candidate.Value.Column, candidate.Value.HeaderHash,
                    Target = candidate.Input.Values.Architecture.ToString(), candidate.Input.Values.BindingSource,
                    NativeInput = candidate.Input.Path, InputOrder = candidate.Input.Order,
                    HeaderPriority = candidate.HeaderPriority == int.MaxValue ? (int?)null : candidate.HeaderPriority,
                    candidate.TraversalOrder, Disposition = disposition, Reason = reason,
                };

                static string NamespaceOf(SyntaxNode node) => string.Join(".", node.Ancestors()
                    .OfType<BaseNamespaceDeclarationSyntax>().Reverse().Select(parent => parent.Name.ToString()));
            }

            internal static bool TryTranslateStringConstant(
                string value, string name, string header, out string expression, out bool isUtf16,
                bool rejectUnsupported = true)
            {
                expression = null;
                isUtf16 = false;
                if (!value.Contains('"') && !value.Contains("TEXT") && !value.Contains("_T"))
                    return false;
                value = value.Trim();
                var terms = new List<string>();
                bool hasStringTerm = false;
                int position = 0;
                while (position < value.Length)
                {
                    Match term = StringTermRegex.Match(value, position);
                    if (!term.Success)
                    {
                        if (hasStringTerm && rejectUnsupported)
                            throw new InvalidOperationException(
                                $"Unsupported string expression for '{name}' in '{header}': {value}");
                        return false;
                    }
                    isUtf16 |= term.Groups["wide"].Success || term.Groups["wrapper"].Success;
                    hasStringTerm |= term.Groups["literal"].Success || term.Groups["wrapper"].Success;
                    if (term.Groups["literal"].Success)
                    {
                        terms.Add(term.Groups["literal"].Value);
                    }
                    else
                    {
                        string identifier = term.Groups["name"].Value;
                        if (CppKeywords.Contains(identifier))
                            return false;
                        if (SyntaxFacts.GetKeywordKind(identifier) != SyntaxKind.None)
                            identifier = "@" + identifier;
                        // Unlike native adjacent strings, C# string + number would silently format the number.
                        terms.Add("(string)" + identifier);
                    }
                    position += term.Length;
                }
                if (!hasStringTerm)
                    return false;
                expression = string.Join(" + ", terms);
                return true;
            }

            private void ScrapeConstantsFromTraversedFiles(Dictionary<string, string> traversedFileMap)
            {
                using var timing = GenerationTiming.BeginSpan("constants.legacy-text-and-streaming-csharp");
                int readHeaders = 0;
                long readLines = 0;
                Dictionary<string, string> autoReplacements = GetAutoValueReplacements();

                HashSet<string> manualEnumMemberNames = this.GetManualEnumMemberNames();
                var pendingAliases = new List<(string Namespace, string Name, string Target, bool NativeIntegers, string Header, int Line)>();

                // For each traversed header, scrape the constants
                foreach (KeyValuePair<string, string> item in this.OrderedHeaders(traversedFileMap))
                {
                    var header = item.Key;
                    this.legacyHeader = header;
                    this.legacyLine = 0;
                    var currentNamespace = item.Value;
                    this.usesNativeIntegers = this.nativeIntegerHeaders.Contains(Path.GetFullPath(header));

                    if (!this._fileSystem.File.Exists(header))
                    {
                        continue;
                    }
                    readHeaders++;

                    string currentHeaderName = Path.GetFileName(header).ToLowerInvariant();

                    var autoEnumObjsForCurrentHeader =
                        this.enumObjectsFromJsons
                            .Where(
                                e => e.autoPopulate != null &&
                                !string.IsNullOrEmpty(e.autoPopulate.filter) &&
                                e.autoPopulate.header.ToLowerInvariant().Split(';').Contains(currentHeaderName))
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
                        this.legacyLine++;
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

                        Match definePciRootBusDevPkeyRegexMatch = DefinePciRootBusDevPkeyRegex.Match(line);
                        if (definePciRootBusDevPkeyRegexMatch.Success)
                        {
                            defineGuidKeyword = "DEFINE_DEVPROPKEY";
                            var guidName = definePciRootBusDevPkeyRegexMatch.Groups[2].Value;
                            var pid = definePciRootBusDevPkeyRegexMatch.Groups[3].Value;
                            var defineGuidLine = $"{guidName}, 0xd817fc28, 0x793e, 0x4b9e, 0x99, 0x70, 0x46, 0x9d, 0x8b, 0xe6, 0x30, 0x73, {pid})";
                            this.AddConstantGuid(defineGuidKeyword, currentNamespace, defineGuidLine);
                            continue;
                        }

                        Match definePciDeviceDevPkeyRegexMatch = DefinePciDeviceDevPkeyRegex.Match(line);
                        if (definePciDeviceDevPkeyRegexMatch.Success)
                        {
                            defineGuidKeyword = "DEFINE_DEVPROPKEY";
                            var guidName = definePciDeviceDevPkeyRegexMatch.Groups[2].Value;
                            var pid = definePciDeviceDevPkeyRegexMatch.Groups[3].Value;
                            var defineGuidLine = $"{guidName}, 0x3ab22e31, 0x8264, 0x4b4e, 0x9a, 0xf5, 0xa8, 0xd2, 0xd8, 0xe3, 0x3e, 0x62, {pid})";
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
                        if (!defineMatch.Success || defineMatch.Groups[2].Value.Length == 0)
                        {
                            this.TryScrapingEnumFlags(line);
                            continue;
                        }

                        string name = defineMatch.Groups[1].Value;
                        if (this.ShouldExclude(name))
                        {
                            continue;
                        }
                        if (this.usesNativeIntegers && this.nativeIntegerNames.Contains(name))
                            continue;

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

                        if (TryTranslateStringConstant(fixedRawValue, name, header, out string stringExpression, out bool isUtf16))
                        {
                            this.AddConstantValue(currentNamespace, "string", name, stringExpression, isUtf16 ? "utf-16" : "ansi");
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
                            // (UCHAR) 123
                            else if (match.Groups[32].Success)
                            {
                                this.AddConstantValue(currentNamespace, "ushort", name, match.Groups[33].Value);
                                continue;
                            }
                            // (UCHAR) -42
                            else if (match.Groups[34].Success)
                            {
                                this.AddConstantValue(currentNamespace, "ushort", name, $"unchecked((ushort){match.Groups[35].Value})");
                                continue;
                            }
                            // (BYTE) 0x42
                            else if (match.Groups[36].Success)
                            {
                                this.AddConstantValue(currentNamespace, "byte", name, match.Groups[37].Value);
                                continue;
                            }
                            // 0x........ << ..
                            else if (match.Groups[38].Success)
                            {
                                this.AddConstantValue(currentNamespace, "uint", name, match.Groups[38].Value);
                                continue;
                            }
                            // 0x........ui64 << ..
                            else if (match.Groups[39].Success)
                            {
                                this.AddConstantValue(currentNamespace, "ulong", name, match.Groups[39].Value.Replace("ui64", "UL"));
                                continue;
                            }
                            // SOME_OTHER_CONSTANT
                            else if (match.Groups[40].Success)
                            {
                                string otherName = match.Groups[40].Value;

                                if (this.mutableGlobalNames.Contains(otherName))
                                {
                                    this.output.Add($"warning: Macro '{name}' in '{item.Key}' refers to mutable global " +
                                        $"'{otherName}', not a metadata constant.");
                                    continue;
                                }

                                matchedToOtherName = true;

                                // Only use a constant as the value if we have seen the constant before
                                // and we know its type
                                if (this.TryGetConstantDependencyType(otherName, out var otherType))
                                {
                                    // Skip guids for now
                                    if (otherType != "Guid")
                                    {
                                        // A later legacy definition can still supply this name's value.
                                        if (!this.nativeDependencies.ContainsKey(otherName) ||
                                            this.sourceConstants.ContainsKey(otherName) || this.writtenConstants.ContainsKey(otherName))
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
                                    this.AddConstantValue(currentNamespace, matchedConstantType, name,
                                        this.GetConstantDependencyExpression(currentNamespace, name, valueText, matchedConstantType));
                                }
                                else if (matchedToOtherName)
                                {
                                    pendingAliases.Add((currentNamespace, name, valueText, this.usesNativeIntegers, header, this.legacyLine));
                                }
                                else
                                {
                                    this.AddConstantInteger(currentNamespace, nativeTypeName, name, valueText);
                                }
                            }
                        }

                    }
                    readLines += this.legacyLine;
                }

                // Preserve resolvable native definitions before processing deferred aliases.
                timing?.SetCounter("readHeaderCount", readHeaders);
                timing?.SetCounter("readLineCount", readLines);
                timing?.SetCounter("pendingAliasCount", pendingAliases.Count);
                timing?.Dispose();
                using var aliasesTiming = GenerationTiming.BeginSpan("constants.resolve-legacy-aliases");
                bool resolvedAlias;
                do
                {
                    resolvedAlias = false;
                    for (int i = 0; i < pendingAliases.Count; i++)
                    {
                        var alias = pendingAliases[i];
                        this.usesNativeIntegers = alias.NativeIntegers;
                        this.legacyHeader = alias.Header;
                        this.legacyLine = alias.Line;
                        if (this.writtenConstants.ContainsKey(alias.Name))
                        {
                            pendingAliases.RemoveAt(i--);
                        }
                        else if (this.TryGetConstantDependencyType(alias.Target, out var type) && type != "Guid")
                        {
                            this.AddConstantValue(alias.Namespace, type, alias.Name,
                                this.GetConstantDependencyExpression(alias.Namespace, alias.Name, alias.Target, type));
                            pendingAliases.RemoveAt(i--);
                            resolvedAlias = true;
                        }
                    }
                }
                while (resolvedAlias);
                aliasesTiming?.SetCounter("unresolvedAliasCount", pendingAliases.Count);
            }

            private static string GetSourceDependencyStorageType(ProtectedConstant declaration)
            {
                if (declaration.SourceKind == "logical-header-group" && declaration.Proof != null)
                {
                    var bindings = declaration.Proof.Group.Members.Single(member =>
                        member.Name == declaration.DeclaredName).Bindings;
                    if (bindings.Length == 1 && bindings[0].Kind != "Expression")
                        return bindings[0].StorageType;
                }
                return declaration.StorageType;
            }

            private bool TryGetConstantDependencyType(string name, out string type)
            {
                if (this.sourceConstantTypes.TryGetValue(name, out var types))
                {
                    if (types.Length != 1)
                        throw new InvalidDataException($"Constant alias target '{name}' has conflicting authoritative storage types: {string.Join(", ", types)}.");
                    type = types[0];
                    return true;
                }
                return this.TryGetNativeDependencyType(name, out type) || this.writtenConstants.TryGetValue(name, out type);
            }

            private bool TryGetNativeDependencyType(string name, out string type)
            {
                type = null;
                if (!this.nativeDependencies.TryGetValue(name, out var dependencies))
                    return false;
                var types = dependencies.Select(value => value.Candidate.Value.StorageType).Distinct(StringComparer.Ordinal).ToArray();
                if (types.Length != 1)
                    throw new InvalidDataException($"Constant alias target '{name}' has conflicting compiler primitive storage types: {string.Join(", ", types)}.");
                type = types[0];
                return true;
            }

            private void RecordNativeDependencyPolicy(string name, string target, string type, string expression)
            {
                this.legacyDependencyPolicies.Add(new
                {
                    Name = name, NativeName = target, Header = this.legacyHeader, Line = this.legacyLine,
                    StorageType = type, Expression = expression,
                    Reason = "retained-compiler-primitive-storage-not-legacy-native-binding-or-value-equivalence",
                });
            }

            private string GetConstantDependencyExpression(string ns, string name, string target, string type)
            {
                if (!this.sourceConstants.TryGetValue(target, out var declarations))
                {
                    if (!this.nativeDependencies.TryGetValue(target, out var dependencies))
                        return target;
                    this.RecordNativeDependencyPolicy(name, target, type, target);
                    if (this.writtenConstants.ContainsKey(target))
                        return target;
                    declarations = dependencies.Select(value => value.Owner).ToArray();
                }
                var owners = declarations.Select(value =>
                    (value.Namespace, value.Owner, value.DeclaredName, value.SourceKind, value.StorageType)).Distinct().ToArray();
                if (owners.Length != 1)
                    throw new InvalidDataException($"Constant alias target '{target}' has conflicting authoritative source owners.");
                var owner = owners[0];
                if (owner.Namespace == (this.LookupNamespaceForName(name) ?? ns) &&
                    owner.SourceKind != "ordinary-unscoped-enum" && owner.DeclaredName == target && owner.StorageType == type)
                    return target;
                string prefix = string.IsNullOrEmpty(owner.Namespace) ? "global::" : "global::" + owner.Namespace + ".";
                return $"unchecked(({type}){prefix}{Identifier(owner.Owner)}.{Identifier(owner.DeclaredName)})";

                static string Identifier(string identifier) =>
                    SyntaxFacts.GetKeywordKind(identifier) == SyntaxKind.None ? identifier : "@" + identifier;
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
                using var timing = GenerationTiming.BeginSpan("constants.write-enums-remaps");
                timing?.SetCounter("enumObjectCount", this.enumObjectsFromJsons.Count);
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
                            // The emitter removes the loose copy of a producer-owned logical enum member.
                            if (this.writtenConstants.ContainsKey(obj.name) &&
                                !(this.scrapedConstantNamespaces.TryGetValue(obj.name, out var constantNamespace) &&
                                  this.headerEnumMemberNames.Contains($"{constantNamespace}.{obj.name}")))
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
        public ScraperResults(IEnumerable<string> results) : this(results, null)
        {
        }

        public ScraperResults(IEnumerable<string> results, string conflictReport)
        {
            this.Output = results;
            this.ConflictReport = conflictReport;
        }

        public IEnumerable<string> Output { get; }
        public string ConflictReport { get; }
    }
}
