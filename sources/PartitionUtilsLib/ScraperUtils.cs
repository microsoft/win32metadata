//#define MakeSingleThreaded

using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;

namespace PartitionUtilsLib
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

        private static bool IsValidCsSourceFile(string fileName)
        {
            if (fileName.EndsWith("modified.cs") || fileName.EndsWith("enums.cs") || fileName.EndsWith("constants.cs"))
            {
                return false;
            }

            return true;
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

