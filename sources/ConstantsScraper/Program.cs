using System.Collections.Generic;
using System.CommandLine;
using System.CommandLine.Invocation;
using System.IO;

namespace ConstantsScraperApp
{
    public static class Program
    {
        static int Main(string[] args)
        {
            var rootCommand = new RootCommand("Scrape traversed headers for constants.")
            {
                new Option<string>(new[] { "--repoRoot" }, "The location of the repo.") { IsRequired = true },
                new Option<string>(new[] { "--headerTextFile" }, "The text file to use as the intro text for written constants source files."),
                new Option(new string[] { "--exclude" }, "A constant to exclude.")
                {
                    Argument = new Argument("<value>")
                    {
                        ArgumentType = typeof(string),
                        Arity = ArgumentArity.OneOrMore,
                    }
                },
                new Option(new string[] { "--requiredNamespaceForName", "-n" }, "The required namespace for a named item.")
                {
                    Argument = new Argument("<name>=<value>")
                    {
                        ArgumentType = typeof(string),
                        Arity = ArgumentArity.OneOrMore,
                    }
                },
                new Option(new string[] { "--rename", "-m" }, "Rename an enum.")
                {
                    Argument = new Argument("<name>=<value>")
                    {
                        ArgumentType = typeof(string),
                        Arity = ArgumentArity.OneOrMore,
                    }
                },
                new Option(new string[] { "--remap", "-r" }, "A field or parameter that should get remapped to a certain type.")
                {
                    Argument = new Argument("<name>=<value>")
                    {
                        ArgumentType = typeof(string),
                        Arity = ArgumentArity.OneOrMore,
                    }
                },
                new Option(new string[] { "--with-type", "-t" }, "For a type for a constant.")
                {
                    Argument = new Argument("<name>=<value>")
                    {
                        ArgumentType = typeof(string),
                        Arity = ArgumentArity.OneOrMore,
                    }
                },
                new Option(new string[] { "--enumsJson" }, "A json file with enum information.")
                {
                    Argument = new Argument("<value>")
                    {
                        ArgumentType = typeof(string),
                        Arity = ArgumentArity.OneOrMore,
                    }
                }
            };

            rootCommand.Handler = CommandHandler.Create(typeof(Program).GetMethod(nameof(Run)));

            return rootCommand.Invoke(args);
        }

        public static int Run(InvocationContext context)
        {
            string repoRoot = context.ParseResult.ValueForOption<string>("repoRoot");
            var excludeItems = context.ParseResult.ValueForOption<string[]>("exclude");
            var enumJsonFiles = context.ParseResult.ValueForOption<string[]>("enumsJson");
            var headerTextFile = context.ParseResult.ValueForOption<string>("headerTextFile");
            var requiredNamespaceValuePairs = context.ParseResult.ValueForOption<string[]>("requiredNamespaceForName");
            var renamedNameValuePairs = context.ParseResult.ValueForOption<string[]>("rename");
            var remappedNameValuePairs = context.ParseResult.ValueForOption<string[]>("remap");
            var withTypeValuePairs = context.ParseResult.ValueForOption<string[]>("with-type");

            var exclusionNamesToPartitions = ConvertExclusionsToDictionary(excludeItems);
            var requiredNamespaces = ConvertValuePairsToDictionary(requiredNamespaceValuePairs);
            var remaps = ConvertValuePairsToDictionary(remappedNameValuePairs);
            var renames = ConvertValuePairsToDictionary(renamedNameValuePairs);
            var withTypes = ConvertValuePairsToDictionary(withTypeValuePairs);

            var headerText = !string.IsNullOrEmpty(headerTextFile) ? File.ReadAllText(headerTextFile) : string.Empty;

            try
            {
                PartitionUtilsLib.ConstantsScraper.ScrapeConstants(repoRoot, enumJsonFiles, headerText, exclusionNamesToPartitions, requiredNamespaces, remaps, withTypes, renames);
            }
            catch (System.Exception e)
            {
                context.Console.Out.Write($"Failed to scrape constants:\r\n{e.Message}\r\n");
                return -1;
            }

            return 0;
        }

        private static Dictionary<string, string> ConvertValuePairsToDictionary(string[] items)
        {
            Dictionary<string, string> ret = new Dictionary<string, string>();

            if (items != null)
            {
                foreach (var item in items)
                {
                    if (string.IsNullOrEmpty(item))
                    {
                        continue;
                    }

                    int firstEqual = item.IndexOf('=');
                    if (firstEqual != -1)
                    {
                        string name = item.Substring(0, firstEqual);
                        string value = item.Substring(firstEqual + 1);
                        ret[name] = value;
                    }
                }
            }

            return ret;
        }

        private static Dictionary<string, string> ConvertExclusionsToDictionary(string[] items)
        {
            Dictionary<string, string> ret = new Dictionary<string, string>();

            if (items != null)
            {
                foreach (var item in items)
                {
                    if (string.IsNullOrEmpty(item))
                    {
                        continue;
                    }

                    string[] parts = item.Split(',');
                    string name = parts[0];
                    string namespaces = parts.Length > 1 ? parts[1] : null;
                    ret[name] = namespaces;
                }
            }

            return ret;
        }
    }
}
