using System;
using System.IO;

namespace Microsoft.Windows.Sdk.CsWin32
{
    class Program
    {
        static int Main(string[] args)
        {
            if (args.Length != 3)
            {
                PrintUsage();
                return 1;
            }

            string metadataDll = args[0];
            if (!File.Exists(metadataDll))
            {
                Console.WriteLine($"{metadataDll} does not exist.");
                return 1;
            }

            string riaMappingsFileName = args[1];

            string outputDir = args[2];
            if (!Directory.Exists(outputDir))
            {
                Directory.CreateDirectory(outputDir);
                return 1;
            }

            CsWin32Projector.CreateProjectedSourceFromMetadata(metadataDll, riaMappingsFileName, outputDir);

            return 0;
        }

        private static void PrintUsage()
        {
            Console.WriteLine("Usage: cswin32 <metadataDll> <riaMappingsFileName> <outputDir>");
        }
    }
}
