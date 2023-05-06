// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

namespace ScrapeDocs;

using System;
using System.Collections.Concurrent;
using System.Collections.Generic;
using System.Diagnostics;
using System.Diagnostics.CodeAnalysis;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.Json;
using System.Text.RegularExpressions;
using System.Threading;
using MessagePack;
using Microsoft.Windows.SDK.Win32Docs;
using YamlDotNet.Core;
using YamlDotNet.RepresentationModel;

/// <summary>
/// Program entrypoint class.
/// </summary>
internal class Program
{
    private static readonly Regex FileNamePattern = new(@"^\w\w-\w+-([\w\-]+)$", RegexOptions.Compiled);
    private static readonly Regex TitlePattern = new(@"([^\s\(]+)", RegexOptions.Compiled);
    private static readonly Regex ParametersHeaderPattern = new(@"^## Parameters", RegexOptions.Compiled);
    private static readonly Regex ParameterHeaderPattern = new(@"^### -param (\w+)", RegexOptions.Compiled);
    private static readonly Regex MembersHeaderPattern = new(@"^## Members", RegexOptions.Compiled);
    private static readonly Regex FieldHeaderPattern = new(@"^### -field (?:\w+\.)*(\w+)", RegexOptions.Compiled);
    private static readonly Regex ParameterMemberPattern = new(@"^([\*{1,2}`])(\w+)\1", RegexOptions.Compiled);
    private static readonly Regex ReturnHeaderPattern = new(@"^## (-returns|Return [vV]alues?)", RegexOptions.Compiled);
    private static readonly Regex RemarksHeaderPattern = new(@"^## (-remarks|Remarks)", RegexOptions.Compiled);
    private static readonly Regex InlineCodeTag = new(@"\<code\>(.*)\</code\>", RegexOptions.Compiled);
    private static readonly Regex EnumNameCell = new(@"\<td[^\>]*\>\<a id=""([^""]+)""", RegexOptions.Compiled);
    private static readonly Regex EnumOrdinalValue = new(@"\<dt\>([\dxa-f]+)\<\/dt\>", RegexOptions.Compiled | RegexOptions.IgnoreCase);
    private static readonly Regex ExcludePattern = new(@"^</?d[ltd]>");

    private static readonly Dictionary<string, string> BaseUris = new()
    {
        { @"/ext/Console-Docs/docs", @"https://docs.microsoft.com/windows/console/" },
        { @"/ext/sdk-api/sdk-api-src/content", @"https://docs.microsoft.com/windows/win32/api/" },
        { @"/ext/Virtualization-Documentation", @"https://docs.microsoft.com/" },
        { @"/ext/win32/desktop-src", @"https://docs.microsoft.com/windows/win32/" },
    };

    private static readonly string ExcludedContentPattern = @"(ADSchema|CIMWin32Prov|DMWmiBridgeProv|gdiplus|HyperV_v2|Midl|SecAuthZ|TermServ|WmiCoreProv|WmiSdk|index\.md|TOC\.md)";

    private readonly string contentBasePaths;
    private readonly string outputPath;
    private readonly string documentationMappingsRsp;

    private Program(string contentBasePaths, string outputPath)
    {
        this.contentBasePaths = contentBasePaths;
        this.outputPath = outputPath;
        this.documentationMappingsRsp = Path.Combine(Path.GetDirectoryName(this.outputPath)!, "documentationMappings.rsp").Replace("\\", "/");
    }

    private bool EmitEnums { get; set; }

    private static int Main(string[] args)
    {
        using var cts = new CancellationTokenSource();
        Console.CancelKeyPress += (s, e) =>
        {
            Console.WriteLine("Canceling...");
            cts.Cancel();
            e.Cancel = true;
        };

        if (args.Length < 2)
        {
            Console.Error.WriteLine("USAGE: {0} <path-to-docs> <path-to-output-pack> [enums]");
            return 1;
        }

        string contentBasePaths = args[0];
        string outputPath = args[1];
        bool emitEnums = args.Length > 2 && args[2] == "enums";

        try
        {
            new Program(contentBasePaths, outputPath) { EmitEnums = true }.Worker(cts.Token);
        }
        catch (OperationCanceledException ex) when (ex.CancellationToken == cts.Token)
        {
            return 2;
        }

        return 0;
    }

    private void Worker(CancellationToken cancellationToken)
    {
        Console.WriteLine("Enumerating documents to be parsed...");
        var paths = new List<string>();
        foreach (var path in this.contentBasePaths.Split(';'))
        {
            paths.AddRange(Directory.GetFiles(path, "*.md", SearchOption.AllDirectories).
                           Where(p => !Regex.IsMatch(p, ExcludedContentPattern, RegexOptions.IgnoreCase)));
        }

        Console.WriteLine("Parsing documents...");

        var timer = Stopwatch.StartNew();
        var parsedNodes = from path in paths.AsParallel()
                          let parseResults = this.ParseDocFile(path)
                          where parseResults is not null
                          from result in parseResults
                          select (Path: path, result.ApiName, result.Docs, result.EnumsByParameter, result.EnumsByField);
        var results = new ConcurrentDictionary<string, ApiDetails>();
        var parameterEnums = new ConcurrentDictionary<(string MethodName, string ParameterName, string HelpLink), DocEnum>();
        var fieldEnums = new ConcurrentDictionary<(string StructName, string FieldName, string HelpLink), DocEnum>();

        if (Debugger.IsAttached)
        {
            parsedNodes = parsedNodes.WithDegreeOfParallelism(1); // improve debuggability
        }

        parsedNodes.
        WithCancellation<(string Path, string ApiName, ApiDetails Docs, IReadOnlyDictionary<string, DocEnum> EnumsByParameter, IReadOnlyDictionary<string, DocEnum> EnumsByField)>(cancellationToken).
        ForAll(result =>
        {
            results.TryAdd(result.ApiName, result.Docs);
            foreach (var e in result.EnumsByParameter)
            {
                if (result.Docs.HelpLink is not null)
                {
                    parameterEnums.TryAdd((result.ApiName, e.Key, result.Docs.HelpLink.AbsoluteUri), e.Value);
                }
            }

            foreach (var e in result.EnumsByField)
            {
                if (result.Docs.HelpLink is not null)
                {
                    fieldEnums.TryAdd((result.ApiName, e.Key, result.Docs.HelpLink.AbsoluteUri), e.Value);
                }
            }
        });

        if (paths.Count == 0)
        {
            Console.Error.WriteLine("No documents found to parse.");
        }
        else
        {
            Console.WriteLine("Parsed {2} documents in {0} ({1} per document)", timer.Elapsed, timer.Elapsed / paths.Count, paths.Count);
            Console.WriteLine($"Found {parameterEnums.Count + fieldEnums.Count} enums.");
        }

        Console.WriteLine("Analyzing and naming enums and collecting docs on their members...");
        var sortedResultsWithoutEnums = new SortedDictionary<string, ApiDetails>(results);
        int constantsCount = this.AnalyzeEnums(results, parameterEnums, fieldEnums);
        var sortedResultsWithEnums = new SortedDictionary<string, ApiDetails>(results);
        Console.WriteLine($"Found docs for {constantsCount} constants.");

        Console.WriteLine("Writing results to \"{0}\" and \"{1}\"", this.outputPath, this.documentationMappingsRsp);

        Directory.CreateDirectory(Path.GetDirectoryName(this.outputPath)!);
        using var outputFileStream = File.OpenWrite(this.outputPath);
        MessagePackSerializer.Serialize(outputFileStream, sortedResultsWithEnums, MessagePackSerializerOptions.Standard, CancellationToken.None);

        var documentationMappingsBuilder = new StringBuilder();
        documentationMappingsBuilder.AppendLine("--memberRemap");

        foreach (var api in sortedResultsWithoutEnums)
        {
            documentationMappingsBuilder.AppendLine($"{api.Key.Replace(".", "::")}=[Documentation(\"{api.Value.HelpLink}\")]");
        }

        File.WriteAllText(this.documentationMappingsRsp, documentationMappingsBuilder.ToString());
    }

    private List<(string ApiName, ApiDetails Docs, IReadOnlyDictionary<string, DocEnum> EnumsByParameter, IReadOnlyDictionary<string, DocEnum> EnumsByField)> ParseDocFile(string filePath)
    {
        try
        {
            ApiDetails apiDetails = new();
            var enumsByParameter = new Dictionary<string, DocEnum>();
            var enumsByField = new Dictionary<string, DocEnum>();

            string? line;

            using StreamReader mdFileReader = File.OpenText(filePath);
            using var markdownToYamlReader = new YamlSectionReader(mdFileReader);
            var yamlBuilder = new StringBuilder();
            try
            {
                while ((line = markdownToYamlReader.ReadLine()) is not null)
                {
                    yamlBuilder.AppendLine(line);
                }
            }
            catch (InvalidOperationException)
            {
                Debug.WriteLine("WARNING: Skipping content without YAML headers {0}", filePath);
                return null!;
            }

            var yaml = new YamlStream();
            try
            {
                yaml.Load(new StringReader(yamlBuilder.ToString()));
            }
            catch (YamlException ex)
            {
                Debug.WriteLine("YAML parsing error in \"{0}\": {1}", filePath, ex.Message);
                return null!;
            }

            var yamlRootNode = (YamlMappingNode)yaml.Documents[0].RootNode;

            if (!yamlRootNode.Children.Any(c =>
            (c.Key.ToString() == "ms.topic" && c.Value.ToString().ToLower() == "reference") ||
            (c.Key.ToString() == "topic_type" && (c.Value as YamlSequenceNode)!.Children.Any(i => i.ToString().ToLower() == "apiref"))))
            {
                Debug.WriteLine("WARNING: Skipping non-reference content {0}", filePath);
                return null!;
            }

            YamlSequenceNode apiNames = null!;
            if (yamlRootNode.Children.ContainsKey("api_name") && yamlRootNode.Children["api_name"] is YamlSequenceNode node)
            {
                apiNames = node;
            }
            else
            {
                Debug.WriteLine("WARNING: Could not find api_name node in: {0}", filePath);
            }

            // Populate ApiName.
            string? apiName = null;

            if (yamlRootNode.Children.ContainsKey("title"))
            {
                apiName = TitlePattern.Match(yamlRootNode.Children["title"].ToString()).Groups[1].Value.Replace("::", ".");
            }
            else if (yamlRootNode.Children.ContainsKey("comtitle"))
            {
                apiName = TitlePattern.Match(yamlRootNode.Children["comtitle"].ToString()).Groups[1].Value.Replace("::", ".");
            }

            apiName = apiName!.Replace("\\", string.Empty);

            // Populate HelpLink.
            foreach (var baseUri in BaseUris.Keys)
            {
                if (filePath.Replace("\\", "/").Contains(baseUri))
                {
                    apiDetails.HelpLink = new Uri(BaseUris[baseUri] + filePath[(filePath.IndexOf(baseUri) + baseUri.Length + 1)..(filePath.Length - 3)].Replace("\\", "/"));

                    break;
                }
            }

            // Populate Description.
            var description = yamlRootNode.Children.FirstOrDefault(n => n.Key is YamlScalarNode { Value: "description" }).Value as YamlScalarNode;
            apiDetails.Description = description?.Value;

            // Populate Parameters, Fields, ReturnValue, and Remarks.
            var docBuilder = new StringBuilder();
            line = mdFileReader.ReadLine();
            while (line is not null)
            {
                if (ParametersHeaderPattern.Match(line) is Match { Success: true } parametersMatch)
                {
                    ParseSection(parametersMatch, apiDetails.Parameters, lookForParameterEnums: true);
                }
                else if (ParameterHeaderPattern.Match(line) is Match { Success: true } parameterMatch)
                {
                    ParseSection(parameterMatch, apiDetails.Parameters, lookForParameterEnums: true);
                }
                else if (MembersHeaderPattern.Match(line) is Match { Success: true } membersMatch)
                {
                    ParseSection(membersMatch, apiDetails.Fields, lookForParameterEnums: true);
                }
                else if (FieldHeaderPattern.Match(line) is Match { Success: true } fieldMatch)
                {
                    ParseSection(fieldMatch, apiDetails.Fields, lookForFieldEnums: true);
                }
                else if (RemarksHeaderPattern.Match(line) is Match { Success: true } remarksMatch)
                {
                    ParseTextSection(out string remarks);
                    apiDetails.Remarks = remarks;
                }
                else if (ReturnHeaderPattern.Match(line) is Match { Success: true } returnMatch)
                {
                    ParseTextSection(out string returnValue);
                    apiDetails.ReturnValue = returnValue;
                }
                else
                {
                    line = mdFileReader.ReadLine();
                }
            }

            var result = new List<(string ApiName, ApiDetails Docs, IReadOnlyDictionary<string, DocEnum> EnumsByParameter, IReadOnlyDictionary<string, DocEnum> EnumsByField)>();
            if (apiNames is not null)
            {
                var firstMethodName = apiNames.Children.Cast<YamlScalarNode>().FirstOrDefault()?.Value;

                if (firstMethodName == apiName)
                {
                    // If api_names includes variants of the base API, create mappings for each.
                    // Example: ext/win32/desktop-src/printdocs/addprinter.md
                    foreach (var methodName in apiNames.Children.Cast<YamlScalarNode>())
                    {
                        var fixedMethodName = methodName.Value!.StartsWith("_") ? methodName.Value![1..] : methodName.Value!;

                        result.Add((fixedMethodName, apiDetails, enumsByParameter, enumsByField));
                    }
                }
                else
                {
                    // If api_names doesn't include the base API, create a mapping just for the base API.
                    // Example: ext/win32/desktop-src/Controls/em-getfileline.md
                    result.Add((apiName!, apiDetails, enumsByParameter, enumsByField));
                }
            }
            else
            {
                result.Add((apiName!, apiDetails, enumsByParameter, enumsByField));
            }

            return result;

            void ParseSection(Match match, IDictionary<string, string> receivingMap, bool lookForParameterEnums = false, bool lookForFieldEnums = false)
            {
                if (match.Value == "## Parameters" || match.Value == "## Members")
                {
                    string sectionName = string.Empty;
                    while ((line = mdFileReader.ReadLine()) is not null)
                    {
                        if (line.StartsWith('#'))
                        {
                            break;
                        }

                        if (ExcludePattern.IsMatch(line))
                        {
                            continue;
                        }

                        if (ParameterMemberPattern.Match(line) is Match { Success: true } parameterMemberMatch)
                        {
                            if (!string.IsNullOrEmpty(sectionName))
                            {
                                receivingMap.TryAdd(sectionName, docBuilder.ToString().Trim());
                                docBuilder.Clear();
                            }

                            sectionName = parameterMemberMatch.Groups[2].Value;

                            continue;
                        }

                        line = FixLine(line);
                        docBuilder.AppendLine(line);
                    }

                    if (!string.IsNullOrEmpty(sectionName))
                    {
                        receivingMap.TryAdd(sectionName, docBuilder.ToString().Trim());
                        docBuilder.Clear();
                    }
                }
                else
                {
                    string sectionName = match.Groups[1].Value;
                    bool foundEnum = false;
                    bool foundEnumIsFlags = false;
                    while ((line = mdFileReader.ReadLine()) is not null)
                    {
                        if (line.StartsWith('#'))
                        {
                            break;
                        }

                        if (lookForParameterEnums || lookForFieldEnums)
                        {
                            if (foundEnum)
                            {
                                if (line == "<table>")
                                {
                                    IReadOnlyDictionary<string, (ulong? Value, string? Doc)> enumNamesAndDocs = ParseEnumTable();
                                    if (enumNamesAndDocs.Count > 0)
                                    {
                                        var enums = lookForParameterEnums ? enumsByParameter : enumsByField;
                                        if (!enums.ContainsKey(sectionName))
                                        {
                                            enums.Add(sectionName, new DocEnum(foundEnumIsFlags, enumNamesAndDocs));
                                        }
                                    }

                                    lookForParameterEnums = false;
                                    lookForFieldEnums = false;
                                }
                            }
                            else
                            {
                                foundEnum = line.Contains("of the following values", StringComparison.OrdinalIgnoreCase);
                                foundEnumIsFlags = line.Contains("combination of", StringComparison.OrdinalIgnoreCase)
                                    || line.Contains("zero or more of", StringComparison.OrdinalIgnoreCase)
                                    || line.Contains("one or both of", StringComparison.OrdinalIgnoreCase)
                                    || line.Contains("one or more of", StringComparison.OrdinalIgnoreCase);
                            }
                        }

                        if (!foundEnum)
                        {
                            line = FixLine(line);
                            docBuilder.AppendLine(line);
                        }
                    }

                    receivingMap.TryAdd(sectionName, docBuilder.ToString().Trim());
                    docBuilder.Clear();
                }
            }

            void ParseTextSection(out string text)
            {
                while ((line = mdFileReader.ReadLine()) is not null)
                {
                    if (line.StartsWith('#'))
                    {
                        break;
                    }

                    line = FixLine(line);
                    docBuilder.AppendLine(line);
                }

                text = docBuilder.ToString().Trim();

                docBuilder.Clear();
            }

            IReadOnlyDictionary<string, (ulong? Value, string? Doc)> ParseEnumTable()
            {
                var enums = new Dictionary<string, (ulong? Value, string? Doc)>();
                int state = 0;
                const int StateReadingHeader = 0;
                const int StateReadingName = 1;
                const int StateLookingForDetail = 2;
                const int StateReadingDocColumn = 3;
                string? enumName = null;
                ulong? enumValue = null;
                var docsBuilder = new StringBuilder();
                while ((line = mdFileReader.ReadLine()) is not null)
                {
                    if (line == "</table>")
                    {
                        break;
                    }

                    switch (state)
                    {
                        case StateReadingHeader:
                            // Reading TR header
                            if (line == "</tr>")
                            {
                                state = StateReadingName;
                            }

                            break;

                        case StateReadingName:
                            // Reading an enum row's name column.
                            Match m = EnumNameCell.Match(line);
                            if (m.Success)
                            {
                                enumName = m.Groups[1].Value;
                                if (enumName == "0")
                                {
                                    enumName = "None";
                                    enumValue = 0;
                                }

                                state = StateLookingForDetail;
                            }

                            break;

                        case StateLookingForDetail:
                            // Looking for an enum row's doc column.
                            m = EnumOrdinalValue.Match(line);
                            if (m.Success)
                            {
                                string value = m.Groups[1].Value;
                                bool hex = value.StartsWith("0x", StringComparison.OrdinalIgnoreCase);
                                if (hex)
                                {
                                    value = value[2..];
                                }

                                enumValue = ulong.Parse(value, hex ? NumberStyles.HexNumber : NumberStyles.Integer, CultureInfo.InvariantCulture);
                            }
                            else if (line.StartsWith("<td", StringComparison.OrdinalIgnoreCase))
                            {
                                state = StateReadingDocColumn;
                            }
                            else if (line.Contains("</tr>", StringComparison.OrdinalIgnoreCase))
                            {
                                // The row ended before we found the doc column.
                                state = StateReadingName;
                                enums.Add(enumName!, (enumValue, null));
                                enumName = null;
                                enumValue = null;
                            }

                            break;

                        case StateReadingDocColumn:
                            // Reading the enum row's doc column.
                            if (line.StartsWith("</td>", StringComparison.OrdinalIgnoreCase))
                            {
                                state = StateReadingName;

                                // Some docs are invalid in documenting the same enum multiple times.
                                if (!enums.ContainsKey(enumName!))
                                {
                                    enums.Add(enumName!, (enumValue, docsBuilder.ToString().Trim()));
                                }

                                enumName = null;
                                enumValue = null;
                                docsBuilder.Clear();
                                break;
                            }

                            docsBuilder.AppendLine(FixLine(line));
                            break;
                    }
                }

                return enums;
            }

            static string FixLine(string line)
            {
                line = line.Replace("href=\"/", "href=\"https://docs.microsoft.com/");
                line = InlineCodeTag.Replace(line, match => $"<c>{match.Groups[1].Value}</c>");
                return line;
            }
        }
        catch (Exception ex)
        {
            throw new ApplicationException($"Failed parsing \"{filePath}\".", ex);
        }
    }

    private int AnalyzeEnums(ConcurrentDictionary<string, ApiDetails> results, ConcurrentDictionary<(string MethodName, string ParameterName, string HelpLink), DocEnum> parameterEnums, ConcurrentDictionary<(string MethodName, string ParameterName, string HelpLink), DocEnum> fieldEnums)
    {
        var uniqueEnums = new Dictionary<DocEnum, List<(string MethodOrStructName, string ParameterOrFieldName, string HelpLink, bool IsMethod)>>();
        var constantsDocs = new Dictionary<string, List<(string MethodOrStructName, string HelpLink, string Doc)>>();

        void Collect(ConcurrentDictionary<(string MethodName, string ParameterName, string HelpLink), DocEnum> enums, bool isMethod)
        {
            foreach (var item in enums)
            {
                if (!uniqueEnums.TryGetValue(item.Value, out List<(string MethodName, string ParameterName, string HelpLink, bool IsMethod)>? list))
                {
                    uniqueEnums.Add(item.Value, list = new());
                }

                list.Add((item.Key.MethodName, item.Key.ParameterName, item.Key.HelpLink, isMethod));

                foreach (KeyValuePair<string, (ulong? Value, string? Doc)> enumValue in item.Value.Members)
                {
                    if (enumValue.Value.Doc is not null)
                    {
                        if (!constantsDocs.TryGetValue(enumValue.Key, out List<(string MethodName, string HelpLink, string Doc)>? values))
                        {
                            constantsDocs.Add(enumValue.Key, values = new());
                        }

                        values.Add((item.Key.MethodName, item.Key.HelpLink, enumValue.Value.Doc));
                    }
                }
            }
        }

        Collect(parameterEnums, isMethod: true);
        Collect(fieldEnums, isMethod: false);

        foreach (var item in constantsDocs)
        {
            // Sort by API name to make results more deterministic.
            item.Value.Sort();

            var docNode = new ApiDetails
            {
                Description = item.Value[0].Doc,
            };

            // If the documentation varies across methods, just link to each document.
            bool differenceDetected = false;
            for (int i = 1; i < item.Value.Count; i++)
            {
                if (item.Value[i].Doc != docNode.Description)
                {
                    differenceDetected = true;
                    break;
                }
            }

            if (differenceDetected)
            {
                docNode.Description = "Documentation varies per use. Refer to each: " + string.Join(", ", item.Value.Select(v => @$"<see href=""{v.HelpLink}"">{v.MethodOrStructName}</see>")) + ".";
            }
            else
            {
                docNode.HelpLink = new Uri(item.Value[0].HelpLink);
            }

            results.TryAdd(item.Key, docNode);
        }

        if (this.EmitEnums)
        {
            string enumDirectory = Path.GetDirectoryName(this.outputPath) ?? throw new InvalidOperationException("Unable to determine where to write enums.");
            Directory.CreateDirectory(enumDirectory);
            using var enumsJsonStream = File.OpenWrite(Path.Combine(enumDirectory, "enums.json"));
            using var writer = new Utf8JsonWriter(enumsJsonStream, new JsonWriterOptions { Indented = true });
            writer.WriteStartArray();

            foreach (KeyValuePair<DocEnum, List<(string MethodName, string ParameterName, string HelpLink, bool IsMethod)>> item in uniqueEnums)
            {
                writer.WriteStartObject();

                if (item.Key.GetRecommendedName(item.Value) is string enumName)
                {
                    writer.WriteString("name", enumName);
                }

                writer.WriteBoolean("flags", item.Key.IsFlags);

                writer.WritePropertyName("members");
                writer.WriteStartArray();
                foreach (var member in item.Key.Members)
                {
                    writer.WriteStartObject();
                    writer.WriteString("name", member.Key);
                    if (member.Value.Value is ulong value)
                    {
                        writer.WriteString("value", value.ToString(CultureInfo.InvariantCulture));
                    }

                    writer.WriteEndObject();
                }

                writer.WriteEndArray();

                writer.WritePropertyName("uses");
                writer.WriteStartArray();
                foreach (var (methodName, parameterName, helpLink, isMethod) in item.Value)
                {
                    writer.WriteStartObject();

                    int periodIndex = methodName.IndexOf('.', StringComparison.Ordinal);
                    string? iface = periodIndex >= 0 ? methodName[..periodIndex] : null;
                    string name = periodIndex >= 0 ? methodName[(periodIndex + 1)..] : methodName;

                    if (iface is not null)
                    {
                        writer.WriteString("interface", iface);
                    }

                    writer.WriteString(isMethod ? "method" : "struct", name);
                    writer.WriteString(isMethod ? "parameter" : "field", parameterName);

                    writer.WriteEndObject();
                }

                writer.WriteEndArray();
                writer.WriteEndObject();
            }

            writer.WriteEndArray();
        }

        return constantsDocs.Count;
    }

    private class YamlSectionReader : TextReader
    {
        private readonly StreamReader fileReader;
        private bool firstLineRead;
        private bool lastLineRead;

        internal YamlSectionReader(StreamReader fileReader)
        {
            this.fileReader = fileReader;
        }

        public override string? ReadLine()
        {
            if (this.lastLineRead)
            {
                return null;
            }

            if (!this.firstLineRead)
            {
                Expect("---", this.fileReader.ReadLine());
                this.firstLineRead = true;
            }

            string? line = this.fileReader.ReadLine();
            if (line == "---")
            {
                this.lastLineRead = true;
                return null;
            }

            return line;
        }

        protected override void Dispose(bool disposing)
        {
            if (disposing)
            {
                this.fileReader.Dispose();
            }

            base.Dispose(disposing);
        }

        private static void Expect(string? expected, string? actual)
        {
            if (expected != actual)
            {
                throw new InvalidOperationException($"Expected: \"{expected}\" but read: \"{actual}\".");
            }
        }
    }
}
