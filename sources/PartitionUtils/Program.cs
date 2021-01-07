using System;
using System.Collections.Generic;
using System.CommandLine;
using System.CommandLine.Invocation;
using System.Globalization;
using System.IO;
using System.Linq;
using CsvHelper;
using CsvHelper.Configuration;

namespace PartitionUtils
{
    class Program
    {
        static int Main(string[] args)
        {
            var showErrorsCommand = new Command("showErrors", "Show partitioning errors.")
            {
                new Option<string>(new[] { "--repoRoot" }, "The location of the repo.") { IsRequired = true },
                new Option<string>(new[] { "--artifactsDir" }, "The location of the output artifacts."),
            };

            showErrorsCommand.Handler = CommandHandler.Create<string, string>(ShowErrors);

            var showNonTraversedCommand = new Command("showNonTraversed", "Show headers that were visited but not part of any partition traverse list.")
            {
                new Option<string>(new[] { "--repoRoot" }, "The location of the repo.") { IsRequired = true },
                new Option<string>(new[] { "--artifactsDir" }, "The location of the output artifacts."),
                //new Option<string>(new[] { "--version" }, getDefaultValue: () => "10.0.19041.5", "The WinSDK NuGet package version to use."),
            };

            showNonTraversedCommand.Handler = CommandHandler.Create<string, string>(ShowNonTraversedHeaders);

            var addTraverseHeadersWithCsvCommand = new Command("addTraverseHeadersWithCsv", "Use CSV to add headers to partition traverse lists.")
            {
                new Option<string>(new[] { "--repoRoot" }, "The location of the repo.") { IsRequired = true },
                new Option<string>(new[] { "--artifactsDir" }, "The location of the output artifacts."),
                new Option<string>(new[] { "--csv" }, "The path to the input CSV.") { IsRequired = true },
                new Option<string>(new[] { "--outputCsv" }, "The path to the output CSV."),
            };

            addTraverseHeadersWithCsvCommand.Handler = CommandHandler.Create<string, string, string, string>(AddTraverseHeadersWithCsv);

            var ensurePartitionsUseNamespaceCommand = new Command("ensurePartitionsUseNamespace", "Update any partition settings that don't use a namespace.")
            {
                new Option<string>(new[] { "--repoRoot" }, "The location of the repo.") { IsRequired = true },
                new Option<string>(new[] { "--artifactsDir" }, "The location of the output artifacts."),
            };

            ensurePartitionsUseNamespaceCommand.Handler = CommandHandler.Create<string, string>(EnsurePartitionsUseNamespace);

            var rootCommand = new RootCommand("Win32metadata partitioning utils")
            {
                showErrorsCommand,
                showNonTraversedCommand,
                addTraverseHeadersWithCsvCommand,
                ensurePartitionsUseNamespaceCommand
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
                if (!File.Exists(partInfo.GenerationOutputFile))
                {
                    Console.WriteLine($"Error: {partInfo.GenerationOutputFile} does not exist. Make sure to run:\r\n.\\scripts\\GenerateMetadataSourceForPartition.ps1 -partitionName {partInfo.Name}");
                    yield break;
                }

                foreach (var header in partInfo.TraverseHeaders)
                {
                    traverseHeaders.Add(header);
                }
            }

            foreach (var partInfo in partInfos)
            {
                foreach (var header in partInfo.VisitedHeaders)
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

        public static int AddTraverseHeadersWithCsv(string repoRoot, string artifactsDir, string csv, string outputCsv)
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

            RepoInfo repoInfo = new RepoInfo(repoRoot, artifactsDir);
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

        public static void EnsurePartitionsUseNamespace(string repoRoot, string artifactsDir)
        {
            RepoInfo repoInfo = new RepoInfo(repoRoot, artifactsDir);

            Console.WriteLine("Ensuring all partition settings files specify a namespace.");
            foreach (var partInfo in repoInfo.GetPartitionInfos())
            {
                partInfo.EnsureSettingsUsingNamspace();
            }

            Console.WriteLine("Updating the file used to start off every generated .cs file.");
            repoInfo.UpdateGeneratedSourceHeader();
        }

        public static void ShowNonTraversedHeaders(string repoRoot, string artifactsDir)
        {
            RepoInfo repoInfo = new RepoInfo(repoRoot, artifactsDir);

            Console.WriteLine("Visited headers that are not in any partition's traverse list:");
            foreach (var header in GetVisitedHeadersNotInTraverseList(repoInfo))
            {
                Console.WriteLine($"  {header}");
            }
        }

        public static void ShowErrors(string repoRoot, string artifactsDir)
        {
            repoRoot = Path.GetFullPath(repoRoot);

            if (artifactsDir == null)
            {
                artifactsDir = Path.Combine(repoRoot, "artifacts");
            }

            RepoInfo repoInfo = new RepoInfo(repoRoot, artifactsDir);
            Dictionary<string, List<PartitionInfo>> traverseHeadersToParts = new Dictionary<string, List<PartitionInfo>>(StringComparer.OrdinalIgnoreCase);

            foreach (var partInfo in repoInfo.GetPartitionInfos())
            {
                foreach (var header in partInfo.TraverseHeaders)
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
