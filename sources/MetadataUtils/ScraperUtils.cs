//#define MakeSingleThreaded

using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;

namespace MetadataUtils
{
    public static class ScraperUtils
    {
        [Flags]
        public enum NameOptions
        {
            None = 0,
            Structs = 1,
            Enums = 2,
            Delegates = 4,
            Methods = 8,
            All = Structs | Enums | Delegates | Methods
        }

        public static Dictionary<string, string> GetNameToNamespaceMap(string sourceDirectory)
        {
            return GetNameToNamespaceMap(sourceDirectory, NameOptions.All);
        }

        public static Dictionary<string, string> GetNameToNamespaceMap(IEnumerable<string> sourceFiles)
        {
            return GetNameToNamespaceMap(sourceFiles, NameOptions.All);
        }

        public static Dictionary<string, string> GetNameToNamespaceMap(IEnumerable<string> sourceFiles, NameOptions nameOptions)
        {
            var maps = new List<List<(string Name, string Namespace, NativeRecordSource Source)>>();
            System.Threading.Tasks.ParallelOptions opt = new System.Threading.Tasks.ParallelOptions() { MaxDegreeOfParallelism = Environment.ProcessorCount * 2 };

#if MakeSingleThreaded
            opt.MaxDegreeOfParallelism = 1;
#endif

            System.Threading.Tasks.Parallel.ForEach(sourceFiles, opt, (sourceFile) =>
            {
                string fileToRead = Path.GetFullPath(sourceFile);
                SyntaxTree tree = CSharpSyntaxTree.ParseText(File.ReadAllText(fileToRead), null, fileToRead);
                var map = NameToNamespaceFinder.GetNamesToNamespaces(tree, nameOptions);

                lock (maps)
                {
                    maps.Add(map);
                }
            });

            Dictionary<string, string> ret = new Dictionary<string, string>();

            foreach (var group in maps.SelectMany(map => map).GroupBy(item => item.Name, StringComparer.Ordinal))
            {
                var first = group.First().Source;
                var candidates = group.AsEnumerable();
                if (first != null && group.All(item => NativeRecordSourceProvenance.SameDeclaration(first, item.Source)) &&
                    group.Any(item => item.Source.TraversedHeader))
                    candidates = group.Where(item => item.Source.TraversedHeader);
                ret.Add(group.Key, string.Join(";", candidates.Select(item => item.Namespace)
                    .Distinct(StringComparer.Ordinal).OrderBy(ns => ns, StringComparer.Ordinal)));
            }

            return ret;
        }

        public static Dictionary<string, string> GetNameToNamespaceMap(string sourceDirectory, NameOptions nameOptions)
        {
            IEnumerable<string> sourceFiles = Directory.GetFiles(sourceDirectory, "*.cs", SearchOption.AllDirectories).Where(f => IsValidCsSourceFile(f));
            return GetNameToNamespaceMap(sourceFiles, nameOptions);
        }

        public static Dictionary<string, string> GetConstants(string scraperOutputDir) =>
            GetConstants(scraperOutputDir, out _);

        public static Dictionary<string, string> GetConstants(string scraperOutputDir, out HashSet<string> mutableGlobals)
        {
            Dictionary<string, string> namesAndTypes = new();
            var mutableNames = new HashSet<string>(StringComparer.Ordinal);

            System.Threading.Tasks.ParallelOptions opt = new System.Threading.Tasks.ParallelOptions() { MaxDegreeOfParallelism = Environment.ProcessorCount * 2 };

            IEnumerable<string> allFiles = Directory.GetFiles(scraperOutputDir, "*.cs", SearchOption.AllDirectories);

#if MakeSingleThreaded
            opt.MaxDegreeOfParallelism = 1;
#endif

            System.Threading.Tasks.Parallel.ForEach(allFiles.Where(f => IsValidCsSourceFile(f)), opt, (sourceFile) =>
            {
                string fileToRead = Path.GetFullPath(sourceFile);
                SyntaxTree tree = CSharpSyntaxTree.ParseText(File.ReadAllText(fileToRead), null, fileToRead);
                var currentMutableNames = new HashSet<string>(StringComparer.Ordinal);
                Dictionary<string, string> currentNamesAndTypes = ConstantsFinder.GetConstantsNamesAndTypes(tree, currentMutableNames);

                lock (namesAndTypes)
                {
                    foreach (var item in currentNamesAndTypes)
                    {
                        namesAndTypes[item.Key] = item.Value;
                    }
                    mutableNames.UnionWith(currentMutableNames);
                }
            });

            mutableGlobals = mutableNames;
            return namesAndTypes;
        }

        private static bool IsValidCsSourceFile(string fileName)
        {
            if (fileName.EndsWith(".modified.cs") || fileName.EndsWith(".enums.cs") || fileName.EndsWith(".constants.cs") ||
                NativeConstantValues.IsGeneratedSource(fileName))
            {
                return false;
            }

            return true;
        }

        private class ConstantsFinder
        {
            public static Dictionary<string, string> GetConstantsNamesAndTypes(SyntaxTree tree, HashSet<string> mutableGlobals)
            {
                Dictionary<string, string> constantsNamesAndTypes = new();

                new TreeWalker(tree, constantsNamesAndTypes, mutableGlobals);

                return constantsNamesAndTypes;
            }

            private class TreeWalker : CSharpSyntaxWalker
            {
                Dictionary<string, string> constantsNamesAndTypes;
                private readonly HashSet<string> mutableGlobals;

                public TreeWalker(SyntaxTree tree, Dictionary<string, string> constantsNamesAndTypes, HashSet<string> mutableGlobals)
                {
                    this.constantsNamesAndTypes = constantsNamesAndTypes;
                    this.mutableGlobals = mutableGlobals;
                    this.Visit(tree.GetRoot());
                }

                public override void VisitClassDeclaration(ClassDeclarationSyntax node)
                {
                    if (node.Identifier.Text == "Apis")
                    {
                        foreach (FieldDeclarationSyntax field in node.Members.Where(m => m is FieldDeclarationSyntax))
                        {
                            if (field.Modifiers.Any(SyntaxKind.ConstKeyword) ||
                                field.Modifiers.Any(SyntaxKind.StaticKeyword))
                            {
                                this.AddNameToMap(field);
                            }
                        }
                    }

                    // Don't process the node as we don't need anything else
                }

                private void AddNameToMap(FieldDeclarationSyntax node)
                {
                    string name = SyntaxUtils.GetFullName(node, false);

                    if (!string.IsNullOrEmpty(name))
                    {
                        if (!this.constantsNamesAndTypes.ContainsKey(name))
                        {
                            var typeName = node.Declaration.Type.ToString();
                            this.constantsNamesAndTypes.Add(name, typeName);
                        }
                        if (!node.Modifiers.Any(SyntaxKind.ConstKeyword) && !node.Modifiers.Any(SyntaxKind.ReadOnlyKeyword))
                            this.mutableGlobals.Add(name);
                    }
                }
            }
        }

        private class NameToNamespaceFinder
        {
            public static List<(string Name, string Namespace, NativeRecordSource Source)> GetNamesToNamespaces(
                SyntaxTree tree, NameOptions nameOptions)
            {
                var namesToNamespaces = new List<(string Name, string Namespace, NativeRecordSource Source)>();

                new TreeWalker(tree, namesToNamespaces, nameOptions);

                return namesToNamespaces;
            }

            private class TreeWalker : CSharpSyntaxWalker
            {
                private List<(string Name, string Namespace, NativeRecordSource Source)> namesToNamespaces;
                private NameOptions nameOptions;

                public TreeWalker(SyntaxTree tree,
                    List<(string Name, string Namespace, NativeRecordSource Source)> namesToNamespaces, NameOptions nameOptions)
                {
                    this.nameOptions = nameOptions;
                    this.namesToNamespaces = namesToNamespaces;
                    this.Visit(tree.GetRoot());
                }

                public override void VisitEnumDeclaration(EnumDeclarationSyntax node)
                {
                    if (this.nameOptions.HasFlag(NameOptions.Enums))
                    {
                        this.AddNameToMap(node);
                    }

                    // Don't process the node as we don't need anything else
                }

                public override void VisitClassDeclaration(ClassDeclarationSyntax node)
                {
                    if (this.nameOptions.HasFlag(NameOptions.Methods))
                    {
                        if (node.Identifier.Text == "Apis")
                        {
                            foreach (MethodDeclarationSyntax method in node.Members.Where(m => m is MethodDeclarationSyntax))
                            {
                                this.AddNameToMap(method);
                            }
                        }
                    }

                    // Don't process the node as we don't need anything else
                }

                public override void VisitDelegateDeclaration(DelegateDeclarationSyntax node)
                {
                    if (this.nameOptions.HasFlag(NameOptions.Delegates))
                    {
                        this.AddNameToMap(node);
                    }

                    // Don't process the node as we don't need anything else
                }

                public override void VisitStructDeclaration(StructDeclarationSyntax node)
                {
                    if (this.nameOptions.HasFlag(NameOptions.Structs))
                    {
                        if (!SyntaxUtils.IsEmptyStruct(node))
                        {
                            this.AddNameToMap(node);
                        }
                    }

                    // Don't process the node as we don't want nested structs
                }

                private void AddNameToMap(SyntaxNode node)
                {
                    string name = SyntaxUtils.GetFullName(node, false);
                    string ns = SyntaxUtils.GetEnclosingNamespace(node);

                    if (!string.IsNullOrEmpty(name) && !string.IsNullOrEmpty(ns))
                    {
                        var source = node is StructDeclarationSyntax record
                            ? NativeRecordSourceProvenance.Read(record) ?? NativeTypedefSourceProvenance.Read(record) : null;
                        this.namesToNamespaces.Add((name, ns, source));
                    }
                }
            }
        }
    }
}
