using System;
using System.Collections.Generic;
using System.CommandLine;
using System.CommandLine.Invocation;
using System.IO;

namespace WinmdUtils
{
    class Program
    {
        static int Main(string[] args)
        {
            var showMissingImportsCommand = new Command("showMissingImports", "Show missing imports between two winmd files.")
            {
                new Option(new[] { "--first" }, "The first winmd.") { Argument = new Argument<FileInfo>().ExistingOnly(), IsRequired = true },
                new Option(new[] { "--second" }, "The second winmd.") { Argument = new Argument<FileInfo>().ExistingOnly(), IsRequired = true },
                new Option(new[] { "--exclusions" }, "Exclusions files.") { Argument = new Argument<string>(), IsRequired = false },
            };

            showMissingImportsCommand.Handler = CommandHandler.Create<FileInfo, FileInfo, string, IConsole>(ShowMissingImports);

            var showDuplicateImports = new Command("showDuplicateImports", "Show duplicate imports in a single winmd files.")
            {
                new Option(new[] { "--winmd" }, "The winmd to inspect.") { Argument = new Argument<FileInfo>().ExistingOnly(), IsRequired = true },
            };

            showDuplicateImports.Handler = CommandHandler.Create<FileInfo, IConsole>(ShowDuplicateImports);

            var showDuplicateTypes = new Command("showDuplicateTypes", "Show duplicate types in a single winmd files.")
            {
                new Option(new[] { "--winmd" }, "The winmd to inspect.") { Argument = new Argument<FileInfo>().ExistingOnly(), IsRequired = true },
            };

            showDuplicateTypes.Handler = CommandHandler.Create<FileInfo, IConsole>(ShowDuplicateTypes);

            var rootCommand = new RootCommand("Win32metadata winmd utils")
            {
                showMissingImportsCommand,
                showDuplicateImports,
                showDuplicateTypes
            };

            return rootCommand.Invoke(args);
        }

        public static int ShowDuplicateTypes(FileInfo winmd, IConsole console)
        {
            using WinmdUtils w1 = WinmdUtils.LoadFromFile(winmd.FullName);
            Dictionary<string, List<string>> nameToTypes = new Dictionary<string, List<string>>();
            foreach (var type in w1.GetTypes())
            {
                if (!nameToTypes.TryGetValue(type.Name, out var structs))
                {
                    structs = new List<string>();
                    nameToTypes[type.Name] = structs;
                }

                structs.Add(type.Namespace);
            }

            bool dupsFound = false;
            foreach (var pair in nameToTypes)
            {
                if (pair.Value.Count > 1)
                {
                    if (dupsFound == false)
                    {
                        dupsFound = true;
                        console.Out.Write("Duplicate types detected:\r\n");
                    }

                    pair.Value.Sort();

                    console.Out.Write($"{pair.Key}\r\n");
                    foreach (var type in pair.Value)
                    {
                        console.Out.Write($"  {type}\r\n");
                    }
                }
            }

            if (!dupsFound)
            {
                console.Out.Write("No duplicate types found.\r\n");
            }

            return dupsFound ? -1 : 0;
        }

        public static int ShowDuplicateImports(FileInfo winmd, IConsole console)
        {
            using WinmdUtils w1 = WinmdUtils.LoadFromFile(winmd.FullName);
            Dictionary<string, List<string>> nameToImports = new Dictionary<string, List<string>>();
            foreach (var imp in w1.GetDllImports())
            {
                if (!nameToImports.TryGetValue(imp.Name, out var imports))
                {
                    imports = new List<string>();
                    nameToImports[imp.Name] = imports;
                }

                imports.Add(imp.DeclaringType);
            }

            bool dupsFound = false;
            foreach (var pair in nameToImports)
            {
                if (pair.Value.Count > 1)
                {
                    if (dupsFound == false)
                    {
                        dupsFound = true;
                        console.Out.Write("Duplicated imports detected:\r\n");
                    }

                    pair.Value.Sort();

                    console.Out.Write($"{pair.Key}\r\n");
                    foreach (var imp in pair.Value)
                    {
                        console.Out.Write($"  {imp}\r\n");
                    }
                }
            }

            if (!dupsFound)
            {
                console.Out.Write("No duplicate types found.\r\n");
            }

            return dupsFound ? -1 : 0;
        }

        public static int ShowMissingImports(FileInfo first, FileInfo second, string exclusions, IConsole console)
        {
            int ret = 0;

            using WinmdUtils w1 = WinmdUtils.LoadFromFile(first.FullName);
            HashSet<string> remainingImports = new HashSet<string>();
            foreach (var imp in w1.GetDllImports())
            {
                remainingImports.Add(imp.Name.ToString());
            }

            using WinmdUtils w2 = WinmdUtils.LoadFromFile(second.FullName);
            foreach (var imp in w2.GetDllImports())
            {
                var text = imp.Name.ToString();
                if (remainingImports.Contains(text))                                
                {
                    remainingImports.Remove(text);
                }
            }

            foreach (var imp in remainingImports)
            {
                if (ret == 0)
                {
                    console.Out.Write("Missing imports detected:\r\n");
                    ret = -1;
                }

                console.Out.Write($"{imp}\r\n");
            }
            
            if (ret == 0)
            {
                console.Out.Write("No missing imports found.\r\n");
            }

            return ret;
        }
    }
}
