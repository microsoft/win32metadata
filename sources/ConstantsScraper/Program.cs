using System.Collections.Generic;
using System.CommandLine;
using System.CommandLine.Invocation;
using System.IO;
using MetadataUtils;

namespace ConstantsScraperApp
{
    public static class Program
    {
        static int Main(string[] args)
        {
            var rootCommand = new RootCommand("Scrape traversed headers for constants.")
            {
                new Option<string>(new[] { "--repoRoot" }, "The location of the repo.") { IsRequired = true },
                new Option<string>(new[] { "--arch" }, () => { return "x64"; }, "The CPU architecture."),
                new Option<string>(new[] { "--headerTextFile" }, "The text file to use as the intro text for written constants source files."),
                new Option<string>("--exclude", "A constant to exclude.", ArgumentArity.OneOrMore),
                new Option<string>("--requiredNamespaceForName", "The required namespace for a named item.", ArgumentArity.OneOrMore),
                new Option<string>("--rename", "Rename an enum.", ArgumentArity.OneOrMore),
                new Option<string>("--with-attribute", "Add an attribute to a constant.", ArgumentArity.OneOrMore),
                new Option<string>("--remap", "A field or parameter that should get remapped to a certain type.", ArgumentArity.OneOrMore),
                new Option<string>("--with-type", "For a type for a constant.", ArgumentArity.OneOrMore),
                new Option<string>("--enumsJson", "A json file with enum information.", ArgumentArity.OneOrMore)
            };

            rootCommand.Handler = CommandHandler.Create<InvocationContext>(Run);
            return rootCommand.Invoke(args);
        }

        public static int Run(InvocationContext context)
        {
            string repoRoot = context.ParseResult.ValueForOption<string>("--repoRoot");
            string arch = context.ParseResult.ValueForOption<string>("--arch");
            var excludeItems = context.ParseResult.ValueForOption<string[]>("--exclude");
            var enumJsonFiles = context.ParseResult.ValueForOption<string[]>("--enumsJson");
            var headerTextFile = context.ParseResult.ValueForOption<string>("--headerTextFile");
            var requiredNamespaceValuePairs = context.ParseResult.ValueForOption<string[]>("--requiredNamespaceForName");
            var remappedNameValuePairs = context.ParseResult.ValueForOption<string[]>("--remap");
            var withTypeValuePairs = context.ParseResult.ValueForOption<string[]>("--with-type");
            var withAttributeValuePairs = context.ParseResult.ValueForOption<string[]>("--with-attribute");

            var exclusionNames = new HashSet<string>(excludeItems ?? (new string[0]));
            var requiredNamespaces = ConvertValuePairsToDictionary(requiredNamespaceValuePairs);
            var remaps = ConvertValuePairsToDictionary(remappedNameValuePairs);
            var withTypes = ConvertValuePairsToDictionary(withTypeValuePairs);
            var withAttributes = ConvertValuePairsToDictionary(withAttributeValuePairs);

            var headerText = !string.IsNullOrEmpty(headerTextFile) ? File.ReadAllText(headerTextFile) : string.Empty;

            // Always exclude this
            exclusionNames.Add("__cplusplus");

            ScraperResults results;
            try
            {
                results = 
                    ConstantsScraper.ScrapeConstants(
                        repoRoot, arch, enumJsonFiles, headerText, exclusionNames, requiredNamespaces, remaps, withTypes, withAttributes);
            }
            catch (System.Exception e)
            {
                context.Console.Out.Write($"Failed to scrape constants:\r\n{e.Message}\r\n{e.StackTrace}");
                return -1;
            }

            foreach (var item in results.Output)
            {
                context.Console.Out.Write(item);
                context.Console.Out.Write("\r\n");
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
    }
}
