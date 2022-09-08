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
#if DEBUG
            if (System.Environment.GetEnvironmentVariable("DEBUG_CONSTANTS_SCRAPER") == "1")
            {
                System.Diagnostics.Debugger.Launch();
            }
#endif
            var rootCommand = new RootCommand("Scrape traversed headers for constants.")
            {
                new Option<string>(new[] { "--defaultNamespace" }, "Default namespace to use for constants."),
                new Option<string>(new[] { "--scraperOutputDir" }, "Output directory for scraping.") { IsRequired = true },
                new Option<string>(new[] { "--headerTextFile" }, "The text file to use as the intro text for written constants source files."),
                new Option<string>("--exclude", "A constant to exclude.", ArgumentArity.OneOrMore),
                new Option<string>("--requiredNamespaceForName", "The required namespace for a named item.", ArgumentArity.OneOrMore),
                new Option<string>("--traversedFileToNamespace", "A traversed file and its namespace.", ArgumentArity.OneOrMore),
                new Option<string>("--with-attribute", "Add an attribute to a constant.", ArgumentArity.OneOrMore),
                new Option<string>("--memberRemap", "A field or parameter that should get remapped to a certain type.", ArgumentArity.OneOrMore),
                new Option<string>("--with-type", "Use a type for a constant.", ArgumentArity.OneOrMore),
                new Option<string>("--enumsJson", "A json file with enum information.", ArgumentArity.OneOrMore)
            };

            rootCommand.Handler = CommandHandler.Create<InvocationContext>(Run);
            return rootCommand.Invoke(args);
        }

        public static int Run(InvocationContext context)
        {
            string defaultNamespace = context.ParseResult.ValueForOption<string>("--defaultNamespace");
            string scraperOutputDir = context.ParseResult.ValueForOption<string>("--scraperOutputDir");
            var excludeItems = context.ParseResult.ValueForOption<string[]>("--exclude");
            var enumJsonFiles = context.ParseResult.ValueForOption<string[]>("--enumsJson");
            var headerTextFile = context.ParseResult.ValueForOption<string>("--headerTextFile");
            var requiredNamespaceValuePairs = context.ParseResult.ValueForOption<string[]>("--requiredNamespaceForName");
            var traversedHeaderToNamespaceValuePairs = context.ParseResult.ValueForOption<string[]>("--traversedFileToNamespace");
            var remappedNameValuePairs = context.ParseResult.ValueForOption<string[]>("--memberRemap");
            var withTypeValuePairs = context.ParseResult.ValueForOption<string[]>("--with-type");
            var withAttributeValuePairs = context.ParseResult.ValueForOption<string[]>("--with-attribute");

            var exclusionNames = new HashSet<string>(excludeItems ?? (new string[0]));
            Dictionary<string, string> traversedHeadersToNamespaces = ConvertValuePairsToDictionary(traversedHeaderToNamespaceValuePairs);
            Dictionary<string, string> requiredNamespaces = ConvertValuePairsToDictionary(requiredNamespaceValuePairs);
            Dictionary<string, string> remaps = ConvertValuePairsToDictionary(remappedNameValuePairs);
            Dictionary<string, string> withTypes = ConvertValuePairsToDictionary(withTypeValuePairs);
            Dictionary<string, string> withAttributes = ConvertValuePairsToDictionary(withAttributeValuePairs);

            var headerText = !string.IsNullOrEmpty(headerTextFile) ? File.ReadAllText(headerTextFile) : string.Empty;

            // Always exclude this
            exclusionNames.Add("__cplusplus");

            ScraperResults results;
            try
            {
                results =
                    ConstantsScraper.ScrapeConstants(
                        enumJsonFiles, defaultNamespace, scraperOutputDir, headerText, exclusionNames, traversedHeadersToNamespaces, requiredNamespaces, remaps, withTypes, withAttributes);
            }
            catch (System.Exception e)
            {
                context.Console.Error.Write($"Failed to scrape constants:\r\n{e.Message}\r\n{e.StackTrace}");
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
