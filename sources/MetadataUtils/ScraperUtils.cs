//#define MakeSingleThreaded

using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;

namespace MetadataUtils
{
    public static class ScraperUtils
    {
        public static Dictionary<string, string> GetNameToNamespaceMap(string sourceDirectory)
        {
            List<Dictionary<string, string>> maps = new List<Dictionary<string, string>>();

            var sourceFiles = Directory.GetFiles(sourceDirectory, "*.cs", SearchOption.AllDirectories).Where(f => IsValidCsSourceFile(f));
            System.Threading.Tasks.ParallelOptions opt = new System.Threading.Tasks.ParallelOptions() { MaxDegreeOfParallelism = Environment.ProcessorCount * 2 };

#if MakeSingleThreaded
            opt.MaxDegreeOfParallelism = 1;
#endif

            System.Threading.Tasks.Parallel.ForEach(sourceFiles, opt, (sourceFile) =>
            {
                string fileToRead = Path.GetFullPath(sourceFile);
                var tree = CSharpSyntaxTree.ParseText(File.ReadAllText(fileToRead), null, fileToRead);
                var map = NameToNamespaceFinder.GetNamesToNamespaces(tree);

                lock (maps)
                {
                    maps.Add(map);
                }
            });

            Dictionary<string, string> ret = new Dictionary<string, string>();

            foreach (var map in maps)
            {
                foreach (var pair in map)
                {
                    if (ret.TryGetValue(pair.Key, out var currentValue))
                    {
                        if (!currentValue.Contains(pair.Value))
                        {
                            currentValue += $";{pair.Value}";
                        }
                    }
                    else
                    {
                        currentValue = pair.Value;
                    }

                    ret[pair.Key] = currentValue;
                }
            }

            return ret;
        }

        public static HashSet<string> GetConstants(string sourceDirectory)
        {
            HashSet<string> names = new HashSet<string>();

            var sourceFiles = Directory.GetFiles(sourceDirectory, "*.cs", SearchOption.AllDirectories).Where(f => IsValidCsSourceFile(f));
            System.Threading.Tasks.ParallelOptions opt = new System.Threading.Tasks.ParallelOptions() { MaxDegreeOfParallelism = Environment.ProcessorCount * 2 };

#if MakeSingleThreaded
            opt.MaxDegreeOfParallelism = 1;
#endif

            System.Threading.Tasks.Parallel.ForEach(sourceFiles, opt, (sourceFile) =>
            {
                string fileToRead = Path.GetFullPath(sourceFile);
                var tree = CSharpSyntaxTree.ParseText(File.ReadAllText(fileToRead), null, fileToRead);
                var currentNames = ConstantsFinder.GetConstantsNames(tree);

                lock (names)
                {
                    names.UnionWith(currentNames);
                }
            });

            return names;
        }

        private static bool IsValidCsSourceFile(string fileName)
        {
            if (fileName.EndsWith("modified.cs") || fileName.EndsWith("enums.cs") || fileName.EndsWith("constants.cs"))
            {
                return false;
            }

            return true;
        }

        private class ConstantsFinder
        {
            public static HashSet<string> GetConstantsNames(SyntaxTree tree)
            {
                HashSet<string> constantsNames = new HashSet<string>();

                new TreeWalker(tree, constantsNames);

                return constantsNames;
            }

            private class TreeWalker : CSharpSyntaxWalker
            {
                private HashSet<string> constantsNames;

                public TreeWalker(SyntaxTree tree, HashSet<string> constantsNames)
                {
                    this.constantsNames = constantsNames;
                    this.Visit(tree.GetRoot());
                }

                public override void VisitClassDeclaration(ClassDeclarationSyntax node)
                {
                    if (node.Identifier.Text == "Apis")
                    {
                        foreach (FieldDeclarationSyntax field in node.Members.Where(m => m is FieldDeclarationSyntax))
                        {
                            string mods = field.Modifiers.ToString();
                            
                            if (mods.Contains("const") || mods.Contains("static readonly"))
                            {
                                this.AddNameToMap(field);
                            }
                        }
                    }

                    // Don't process the node as we don't need anything else
                }

                private void AddNameToMap(SyntaxNode node)
                {
                    string name = SyntaxUtils.GetFullName(node, false);

                    if (!string.IsNullOrEmpty(name))
                    {
                        if (!this.constantsNames.Contains(name))
                        {
                            this.constantsNames.Add(name);
                        }
                    }
                }
            }
        }

        private class NameToNamespaceFinder
        {
            public static Dictionary<string, string> GetNamesToNamespaces(SyntaxTree tree)
            {
                Dictionary<string, string> namesToNamespaces = new Dictionary<string, string>();

                new TreeWalker(tree, namesToNamespaces);

                return namesToNamespaces;
            }

            private class TreeWalker : CSharpSyntaxWalker
            {
                private Dictionary<string, string> namesToNamespaces;

                public TreeWalker(SyntaxTree tree, Dictionary<string, string> namesToNamespaces)
                {
                    this.namesToNamespaces = namesToNamespaces;
                    this.Visit(tree.GetRoot());
                }

                public override void VisitEnumDeclaration(EnumDeclarationSyntax node)
                {
                    this.AddNameToMap(node);

                    // Don't process the node as we don't need anything else
                }

                public override void VisitClassDeclaration(ClassDeclarationSyntax node)
                {
                    if (node.Identifier.Text == "Apis")
                    {
                        foreach (MethodDeclarationSyntax method in node.Members.Where(m => m is MethodDeclarationSyntax))
                        {
                            this.AddNameToMap(method);
                        }
                    }

                    // Don't process the node as we don't need anything else
                }

                public override void VisitDelegateDeclaration(DelegateDeclarationSyntax node)
                {
                    this.AddNameToMap(node);

                    // Don't process the node as we don't need anything else
                }

                public override void VisitStructDeclaration(StructDeclarationSyntax node)
                {
                    if (!SyntaxUtils.IsEmptyStruct(node))
                    {
                        this.AddNameToMap(node);
                    }

                    // Don't process the node as we don't want nested structs
                }

                private void AddNameToMap(SyntaxNode node)
                {
                    string name = SyntaxUtils.GetFullName(node, false);
                    string ns = SyntaxUtils.GetEnclosingNamespace(node);

                    if (!string.IsNullOrEmpty(name) && !string.IsNullOrEmpty(ns))
                    {
                        if (!this.namesToNamespaces.ContainsKey(name))
                        {
                            this.namesToNamespaces.Add(name, ns);
                        }
                    }
                }
            }
        }
    }
}

