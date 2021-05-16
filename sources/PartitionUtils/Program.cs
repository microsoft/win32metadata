using System;
using System.Collections.Generic;
using System.CommandLine;
using System.CommandLine.Invocation;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text.RegularExpressions;
using CsvHelper;
using CsvHelper.Configuration;
using Newtonsoft.Json;
using MetadataUtils;

namespace PartitionUtils
{
    class Program
    {
        static int Main(string[] args)
        {
            var showErrorsCommand = new Command("showErrors", "Show partitioning errors.")
            {
                new Option<string>(new[] { "--repoRoot" }, "The location of the repo.") { IsRequired = true },
            };

            showErrorsCommand.Handler = CommandHandler.Create<string>(ShowErrors);

            var showNonTraversedCommand = new Command("showNonTraversed", "Show headers that were visited but not part of any partition traverse list.")
            {
                new Option<string>(new[] { "--repoRoot" }, "The location of the repo.") { IsRequired = true },
            };

            showNonTraversedCommand.Handler = CommandHandler.Create<string>(ShowNonTraversedHeaders);

            var addTraverseHeadersWithCsvCommand = new Command("addTraverseHeadersWithCsv", "Use CSV to add headers to partition traverse lists.")
            {
                new Option<string>(new[] { "--repoRoot" }, "The location of the repo.") { IsRequired = true },
                new Option<string>(new[] { "--csv" }, "The path to the input CSV.") { IsRequired = true },
                new Option<string>(new[] { "--outputCsv" }, "The path to the output CSV."),
            };

            addTraverseHeadersWithCsvCommand.Handler = CommandHandler.Create<string, string, string>(AddTraverseHeadersWithCsv);

            var ensurePartitionsUseNamespaceCommand = new Command("ensurePartitionsUseNamespace", "Update any partition settings that don't use a namespace.")
            {
                new Option<string>(new[] { "--repoRoot" }, "The location of the repo.") { IsRequired = true },
            };

            ensurePartitionsUseNamespaceCommand.Handler = CommandHandler.Create<string>(EnsurePartitionsUseNamespace);

            var normalizeEnumJsonCommand = new Command("normalizeEnumJson", "Normalize json enum files.")
            {
                new Option<string>(new[] { "--repoRoot" }, "The location of the repo.") { IsRequired = true },
                new Option(new[] { "--jsonInputFile" }, "The location of the json input file.") 
                {
                    Argument = new Argument("<file>")
                    {
                        ArgumentType = typeof(string),
                        Arity = ArgumentArity.OneOrMore,
                    }
                },
                new Option<string>(new[] { "--jsonOutputFile" }, "The location of the json output file.") { IsRequired = true },
                new Option(new string[] { "--rename" }, "Rename an enum.")
                {
                    Argument = new Argument("<name>=<value>")
                    {
                        ArgumentType = typeof(string),
                        Arity = ArgumentArity.OneOrMore,
                    }
                },
                new Option(new string[] { "--exclude" }, "Exclude an enum.")
                {
                    Argument = new Argument("<name>")
                    {
                        ArgumentType = typeof(string),
                        Arity = ArgumentArity.OneOrMore,
                    }
                },
            };

            normalizeEnumJsonCommand.Handler = CommandHandler.Create<string, string[], string, string[], string[]>(NormalizeEnumJson);

            var simplifyRequiredNamespacesForNamesCommand = new Command("simplifyRequiredNamespacesForNames", "Simplify simplifyRequiredNamespacesForNames.rsp.")
            {
                new Option<string>(new[] { "--repoRoot" }, "The location of the repo.") { IsRequired = true },
                new Option<string>(new[] { "--apiCsv" }, "The path to the api csv.") { IsRequired = true },
                new Option<string>(new[] { "--input" }, "The path to the input requiredNamespacesForNames.rsp.") { IsRequired = true },
                new Option<string>(new[] { "--output" }, "The path to the output requiredNamespacesForNames.rsp."),
            };

            simplifyRequiredNamespacesForNamesCommand.Handler = CommandHandler.Create<string, string, string, string>(SimplifyRequiredNamespacesForNames);

            var rootCommand = new RootCommand("Win32metadata partitioning utils")
            {
                showErrorsCommand,
                showNonTraversedCommand,
                addTraverseHeadersWithCsvCommand,
                ensurePartitionsUseNamespaceCommand,
                normalizeEnumJsonCommand,
                simplifyRequiredNamespacesForNamesCommand
            };

            return rootCommand.Invoke(args);
        }

        private class PartitionAndHeader
        {
            public PartitionAndHeader(string partitionName, string header)
            {
                this.PartitionName = partitionName;
                this.Header = header;
            }

            public string PartitionName { get; }
            public string Header { get;  }
        }

        private static IEnumerable<PartitionAndHeader> GetVisitedHeadersWithPartNamesNotInTraverseList(RepoInfo repoInfo)
        {
            string[] headersToIgnore = new string[]
            {
                "/shared/concurrencysal.h", "/shared/SpecStrings.h", "/shared/DriverSpecs.h", "/shared/kernelspecs.h", "/shared/guiddef.h",
                "/shared/basetsd.h", "/shared/ktmtypes.h", "/um/ddkernel.h", "/um/dmemmgr.h"
            };
            HashSet<string> ignoreHeaders = new HashSet<string>(headersToIgnore, StringComparer.OrdinalIgnoreCase);
            HashSet<string> traverseHeaders = new HashSet<string>(StringComparer.OrdinalIgnoreCase);

            var partInfos = repoInfo.GetPartitionInfos().ToList();
            foreach (var partInfo in partInfos)
            {
                string genOutputFile = partInfo.GetGenerationOutputFile("x64");
                if (!File.Exists(genOutputFile))
                {
                    Console.WriteLine($"Error: {genOutputFile} does not exist. Make sure to run:\r\n.\\scripts\\GenerateMetadataSourceForPartition.ps1 -partitionName {partInfo.Name}");
                    yield break;
                }

                foreach (var header in partInfo.GetTraverseHeaders(true, "x64"))
                {
                    traverseHeaders.Add(header);
                }
            }

            foreach (var partInfo in partInfos)
            {
                foreach (var header in partInfo.GetVisitedHeaders("x64"))
                {
                    if (header.StartsWith("/winrt/") || ignoreHeaders.Contains(header) || traverseHeaders.Contains(header))
                    {
                        continue;
                    }

                    yield return new PartitionAndHeader(partInfo.Name, header);
                }
            }
        }

        private static IEnumerable<string> GetVisitedHeadersNotInTraverseList(RepoInfo repoInfo)
        {
            HashSet<string> outputtedHeaders = new HashSet<string>(StringComparer.OrdinalIgnoreCase);
            foreach (var partAndHeader in GetVisitedHeadersWithPartNamesNotInTraverseList(repoInfo))
            {
                if (!outputtedHeaders.Contains(partAndHeader.Header))
                {
                    outputtedHeaders.Add(partAndHeader.Header);
                    yield return partAndHeader.Header;
                }
            }
        }

        public static int NormalizeEnumJson(string repoRoot, string[] jsonInputFile, string jsonOutputFile, string[] rename, string[] exclude)
        {
            var renames = CommandLineUtils.ConvertValuePairsToDictionary(rename);

            HashSet<string> excludes = new HashSet<string>(exclude);
            List<EnumObject> enumObjects = new List<EnumObject>();

            foreach (var inputFile in jsonInputFile)
            {
                enumObjects.AddRange(EnumObject.LoadFromFile(inputFile));
            }

            var newObjects = EnumObjectUtils.NormalizeEnumObjects(repoRoot, enumObjects, renames, excludes).ToArray();

            JsonSerializerSettings jsonSerializerSettings = new JsonSerializerSettings();
            jsonSerializerSettings.NullValueHandling = NullValueHandling.Ignore;
            jsonSerializerSettings.DefaultValueHandling = DefaultValueHandling.Ignore;

            var jsonText = JsonConvert.SerializeObject(newObjects, Formatting.Indented, jsonSerializerSettings);
            File.WriteAllText(jsonOutputFile, jsonText);

            Regex containsLowerCase = new Regex(@"[a-z]+");

            foreach (var obj in newObjects)
            {
                if (obj.name != null && containsLowerCase.IsMatch(obj.name))
                {
                    Console.WriteLine($"Warning: {obj.name} enum contains lower case. Add a better name or exclude it.");
                    Console.Write("  Members: ");
                    foreach (var member in obj.members.Take(3))
                    {
                        Console.Write(member.name);
                        Console.Write(' ');
                    }

                    Console.WriteLine();
                }
            }

            return 0;
        }

        public static int SimplifyRequiredNamespacesForNames(string repoRoot, string apiCsv, string input, string output)
        {
            RepoInfo repoInfo = new RepoInfo(repoRoot);
            Dictionary<string, string> headerToNamespace = new Dictionary<string, string>(StringComparer.OrdinalIgnoreCase);
            foreach (var part in repoInfo.GetPartitionInfos())
            {
                foreach (var header in part.GetTraverseHeaders(true, "x64"))
                {
                    string fileName = Path.GetFileName(header);
                    headerToNamespace[fileName] = part.Namespace;
                }
            }

            CsvConfiguration config = new CsvConfiguration(CultureInfo.InvariantCulture);
            config.Delimiter = ",";
            config.HasHeaderRecord = true;

            Dictionary<string, string> nameToNamespace = new Dictionary<string, string>();

            using (var reader = new StreamReader(apiCsv))
            using (var csvReader = new CsvReader(reader, config))
            {
                var anonymousTypeDefinition = new
                {
                    Name = string.Empty,
                    Title = string.Empty,
                    Header = string.Empty,
                    TechRoot = string.Empty
                };

                foreach (var record in csvReader.GetRecords(anonymousTypeDefinition))
                {
                    if (!string.IsNullOrEmpty(record.Header) && !string.IsNullOrEmpty(record.Title))
                    {
                        if (headerToNamespace.TryGetValue(record.Header, out var namespaceName))
                        {
                            nameToNamespace[record.Title] = namespaceName;
                        }
                    }
                }
            }

            // Load up all the names along with their final value. This
            // will get rid of duplicates and take the final one
            Dictionary<string, string> namesAndValues = new Dictionary<string, string>();
            foreach (var line in File.ReadAllLines(input))
            {
                string[] parts = line.Split('=');
                if (parts.Length == 2)
                {
                    string name = parts[0];
                    string ns = parts[1];
                    namesAndValues[name] = ns;
                }
            }

            string emitterGeneratedDir = Path.Combine(repoRoot, $@"generation\emitter\generated\x64");
            var scrapedNamesToNamespaces = ScraperUtils.GetNameToNamespaceMap(emitterGeneratedDir);

            using (StreamWriter writer = new StreamWriter(output))
            {
                writer.WriteLine("--requiredNamespaceForName");
                foreach (var line in File.ReadAllLines(input))
                {
                    string[] parts = line.Split('=');
                    if (parts.Length == 2)
                    {
                        string name = parts[0];
                        string ns = parts[1];

                        // Skip if we never scanned it
                        if (!scrapedNamesToNamespaces.ContainsKey(name))
                        {
                            continue;
                        }

                        // If this isn't the one that has the final value, skip it
                        if (namesAndValues[name] != ns)
                        {
                            continue;
                        }

                        // Skip if this line is redundant, because the name is in the correct namespace
                        // based on the header
                        if (nameToNamespace.TryGetValue(name, out var headerNamespace))
                        {
                            if (ns == headerNamespace)
                            {
                                continue;
                            }

                            Console.WriteLine($"Keeping override: {line} (header goes into {headerNamespace})");
                        }

                        writer.WriteLine(line);
                    }
                }
            }

            return 0;
        }

        public static int AddTraverseHeadersWithCsv(string repoRoot, string csv, string outputCsv)
        {
            Dictionary<string, HashSet<string>> headersToTechRoots = new Dictionary<string, HashSet<string>>(StringComparer.OrdinalIgnoreCase);
            CsvConfiguration config = new CsvConfiguration(CultureInfo.InvariantCulture);
            config.Delimiter = ",";
            config.HasHeaderRecord = true;

            using (var reader = new StreamReader(csv))
            using (var csvReader = new CsvReader(reader, config))
            {
                var anonymousTypeDefinition = new
                {
                    Name = string.Empty,
                    Header = string.Empty,
                    Include = string.Empty,
                    Lib = string.Empty,
                    TechRoot = string.Empty
                };

                foreach (var record in csvReader.GetRecords(anonymousTypeDefinition))
                {
                    if (!headersToTechRoots.TryGetValue(record.Header, out var techRootSet))
                    {
                        if (string.IsNullOrEmpty(record.TechRoot))
                        {
                            continue;
                        }

                        techRootSet = new HashSet<string>(StringComparer.OrdinalIgnoreCase);
                        headersToTechRoots[record.Header] = techRootSet;
                    }

                    if (!techRootSet.Contains(record.TechRoot))
                    {
                        techRootSet.Add(record.TechRoot);
                    }
                }
            }

            RepoInfo repoInfo = new RepoInfo(repoRoot);
            using StreamWriter streamWriter = outputCsv != null ? new StreamWriter(outputCsv) : null;
            streamWriter?.WriteLine("Name,Header,Include,Lib,TechRoot");

            HashSet<string> fixedHeaders = new HashSet<string>(StringComparer.OrdinalIgnoreCase);
            foreach (var partitionAndHeader in GetVisitedHeadersWithPartNamesNotInTraverseList(repoInfo))
            {
                var headerName = Path.GetFileName(partitionAndHeader.Header);
                if (fixedHeaders.Contains(headerName))
                {
                    continue;
                }

                if (!headersToTechRoots.TryGetValue(headerName, out var techRoots))
                {
                    Console.WriteLine($"{partitionAndHeader.Header} not listed in CSV with a tech root, but visited by {partitionAndHeader.PartitionName}");
                    streamWriter?.WriteLine($",{headerName},,,{partitionAndHeader.PartitionName}");
                }
                else
                {
                    if (techRoots.Count > 1)
                    {
                        Console.Write($"More than one tech root specified in CSV for {partitionAndHeader.Header}: ");
                        Console.Write(techRoots.First());
                        foreach (var techRoot in techRoots.Skip(1))
                        {
                            Console.Write($", {techRoot}");
                        }

                        Console.WriteLine();

                        if (streamWriter != null)
                        {
                            foreach (var techRoot in techRoots)
                            {
                                streamWriter.WriteLine($",{headerName},,,{techRoot}");
                            }
                        }
                    }
                    else
                    {
                        string partName = techRoots.First();
                        Console.WriteLine($"Adding {partitionAndHeader.Header} to partition {partName}");
                        repoInfo.AddTraverseHeader(partitionAndHeader.Header, partName);

                        fixedHeaders.Add(headerName);
                    }
                }
            }

            return 0;
        }

        public static void EnsurePartitionsUseNamespace(string repoRoot)
        {
            RepoInfo repoInfo = new RepoInfo(repoRoot);

            Console.WriteLine("Ensuring all partition settings files specify a namespace.");
            foreach (var partInfo in repoInfo.GetPartitionInfos())
            {
                partInfo.EnsureSettingsUsingNamspace();
            }

            Console.WriteLine("Updating the file used to start off every generated .cs file.");
            repoInfo.UpdateGeneratedSourceHeader();
        }

        public static void ShowNonTraversedHeaders(string repoRoot)
        {
            RepoInfo repoInfo = new RepoInfo(repoRoot);

            Console.WriteLine("Visited headers that are not in any partition's traverse list:");
            foreach (var header in GetVisitedHeadersNotInTraverseList(repoInfo))
            {
                Console.WriteLine($"  {header}");
            }
        }

        public static void ShowErrors(string repoRoot)
        {
            repoRoot = Path.GetFullPath(repoRoot);

            RepoInfo repoInfo = new RepoInfo(repoRoot);
            Dictionary<string, List<PartitionInfo>> traverseHeadersToParts = new Dictionary<string, List<PartitionInfo>>(StringComparer.OrdinalIgnoreCase);

            foreach (var partInfo in repoInfo.GetPartitionInfos())
            {
                foreach (var header in partInfo.GetTraverseHeaders(true, "x64"))
                {
                    if (!traverseHeadersToParts.TryGetValue(header, out var partitionInfos))
                    {
                        partitionInfos = new List<PartitionInfo>();
                        traverseHeadersToParts[header] = partitionInfos;
                    }

                    partitionInfos.Add(partInfo);
                }
            }

            Console.WriteLine("Traverse headers that show up in multiple settings files:");
            foreach (var item in traverseHeadersToParts)
            {
                if (item.Value.Count > 1)
                {
                    Console.WriteLine(item.Key);
                    foreach (var partInfo in item.Value)
                    {
                        Console.WriteLine($"  {partInfo.SettingsFile}");
                    }

                    Console.WriteLine();
                }
            }
        }
    }
}
