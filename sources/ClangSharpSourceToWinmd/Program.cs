using System;
using System.Collections.Generic;
using System.IO;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;

namespace ClangSharpSourceToWinmd
{
    class Program
    {
        private static string FindNetstandardDllPath()
        {
            // Is there a better way to find this?
            string progFiles = Environment.GetFolderPath(Environment.SpecialFolder.ProgramFiles);
            return Path.Combine(progFiles, @"dotnet\packs\NETStandard.Library.Ref\2.1.0\ref\netstandard2.1\netstandard.dll");
        }

        static void Main(string[] args)
        {
            string sourceDirectory = args[0];
            string interopFileName = args[1];
            string outputFileName = args[2];

            Version assemblyVersion = new Version(1, 0, 0, 0);
            if (args.Length >= 4)
            {
                // Get rid of any trailing sem ver data
                string version = args[3].Split('-')[0];
                assemblyVersion = Version.Parse(version);
            }

            var netstandardPath = FindNetstandardDllPath();

            List<MetadataReference> refs = new List<MetadataReference>();
            refs.Add(MetadataReference.CreateFromFile(interopFileName));
            refs.Add(MetadataReference.CreateFromFile(netstandardPath));

            List<SyntaxTree> syntaxTrees = new List<SyntaxTree>();
            foreach (var sourceFile in Directory.GetFiles(sourceDirectory, "*.cs", SearchOption.AllDirectories))
            {
                if (sourceFile.Contains("\\obj\\") || sourceFile.Contains("\\bin\\"))
                {
                    continue;
                }

                Console.WriteLine($"Compiling {sourceFile}...");
                syntaxTrees.Add(CSharpSyntaxTree.ParseText(File.ReadAllText(sourceFile)));
            }

            var comp =
                CSharpCompilation.Create(Path.GetFileName(outputFileName)).
                    AddReferences(refs).
                    AddSyntaxTrees(syntaxTrees);

            Console.WriteLine($"Emitting {outputFileName}...");
            ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(comp, assemblyVersion, outputFileName);
        }
    }
}
