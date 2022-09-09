//#define MakeSingleThreaded
//#define ShowMemoryInfo

using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using MetadataUtils;

namespace ClangSharpSourceToWinmd
{
    public class ClangSharpSourceCompilation
    {
        private CSharpCompilation compilation;
        private Dictionary<string, string> typeImports;

        private ClangSharpSourceCompilation(CSharpCompilation compilation, Dictionary<string, string> typeImports)
        {
            this.compilation = compilation;
            this.typeImports = typeImports;
        }

        public CSharpCompilation CSharpCompilation => this.compilation;

        internal static void ShowMemory()
        {
#if ShowMemoryInfo
            MEMORYSTATUSEX mem = new MEMORYSTATUSEX();
            if (GlobalMemoryStatusEx(mem))
            {
                double max = ConvertToGB(mem.ullTotalPhys);
                double avail = ConvertToGB(mem.ullAvailPhys);
                Console.WriteLine($"RAM avail = {avail}, load = {mem.dwMemoryLoad}");
            }

            static double ConvertToGB(ulong val)
            {
                return (double)val / (1024 * 1024 * 1024);
            }
#endif
        }

        private static void WriteTree(SyntaxTree tree, string fileName)
        {
            var dir = Path.GetDirectoryName(fileName);
            if (!Directory.Exists(dir))
            {
                Directory.CreateDirectory(dir);
            }

            using (StreamWriter writer = File.CreateText(fileName))
            {
                tree.GetText().Write(writer);
            }
        }

        private static SyntaxTree ReadTree(string fileName)
        {
            return CSharpSyntaxTree.ParseText(File.ReadAllText(fileName), null, fileName);
        }

        private static IEnumerable<SyntaxTree> FilesToTrees(IEnumerable<string> files)
        {
            foreach (string file in files)
            {
                yield return ReadTree(file);
            }
        }

        private static Windows.Win32.Interop.Architecture GetArchitectureForFileName(string fileName)
        {
            string potentialArch = Path.GetFileName(Path.GetDirectoryName(fileName));

            switch (potentialArch)
            {
                case "x64":
                    return Windows.Win32.Interop.Architecture.X64;

                case "x86":
                    return Windows.Win32.Interop.Architecture.X86;

                case "arm64":
                    return Windows.Win32.Interop.Architecture.Arm64;

                default:
                    return Windows.Win32.Interop.Architecture.None;
            }
        }

        private static CrossArchSyntaxMap LoadCrossArchMapFromFiles(IEnumerable<string> files, System.Threading.Tasks.ParallelOptions parallelOptions)
        {
            CrossArchSyntaxMap crossArchSyntaxMap = new CrossArchSyntaxMap();

            var nonx86Files = files.Where(f => GetArchitectureForFileName(f) == Windows.Win32.Interop.Architecture.X64 || GetArchitectureForFileName(f) == Windows.Win32.Interop.Architecture.Arm64);
            var x86Files = files.Where(f => GetArchitectureForFileName(f) == Windows.Win32.Interop.Architecture.X86);

            // Add non-x86 first so that x86 has a chance to see if it can merge structs not marked
            // with 4-byte packing with 64-bit versions that are marked. The default packing is 4
            // for x86 so we can merge these types of structs
            System.Threading.Tasks.Parallel.ForEach(FilesToTrees(nonx86Files), parallelOptions, (tree) =>
            {
                crossArchSyntaxMap.AddTree(tree);
            });

            System.Threading.Tasks.Parallel.ForEach(FilesToTrees(x86Files), parallelOptions, (tree) =>
            {
                crossArchSyntaxMap.AddTree(tree);
            });

            return crossArchSyntaxMap;
        }

        private static string GetPartitionNameFromFileName(string fileName)
        {
            return Path.GetFileName(fileName).Replace(".modified.cs", string.Empty);
        }

        public static ClangSharpSourceCompilation Create(
            string sourceDirectory,
            string arch,
            string interopFileName,
            Dictionary<string, string> remaps,
            Dictionary<string, Dictionary<string, string>> enumAdditions,
            IEnumerable<string> enumsMakeFlags,
            Dictionary<string, string> typeImports,
            Dictionary<string, string> requiredNamespaces,
            HashSet<string> reducePointerLevels,
            IEnumerable<string> addedRefs,
            Dictionary<string, string> staticLibs)
        {
            sourceDirectory = Path.GetFullPath(sourceDirectory);

            string topObjDir = Path.Combine(sourceDirectory, $"obj");
            if (Directory.Exists(topObjDir))
            {
                Directory.Delete(topObjDir, true);
            }

            string objDir = Path.Combine(topObjDir, arch);
            Directory.CreateDirectory(objDir);

            var netstandardPath = FindNetstandardDllPath();
            if (!File.Exists(netstandardPath))
            {
                throw new FileNotFoundException("Failed to find the netstandard DLL.");
            }

            List<MetadataReference> refs = new List<MetadataReference>();
            refs.Add(MetadataReference.CreateFromFile(interopFileName));
            refs.Add(MetadataReference.CreateFromFile(netstandardPath));

            if (addedRefs != null)
            {
                foreach (var r in addedRefs)
                {
                    refs.Add(MetadataReference.CreateFromFile(r));
                }
            }

            TreeInfoFinder infoFinder = new TreeInfoFinder();

            List<string> modifiedFiles = new List<string>();
            var sourceFiles = Directory.GetFiles(sourceDirectory, "*.cs", SearchOption.AllDirectories).Where(f => IsValidCsSourceFile(f, arch));
            System.Threading.Tasks.ParallelOptions opt = new System.Threading.Tasks.ParallelOptions();

#if MakeSingleThreaded
            opt.MaxDegreeOfParallelism = 1;
#endif

            foreach (string file in sourceFiles)
            {
                // Turn c:\dir\generated\foo.cs into c:\dir\generated\obj\foo.modified.cs

                string modifiedFile = Path.ChangeExtension(file, ".modified.cs");
                string fileWithSubDir = modifiedFile.Substring(sourceDirectory.Length);
                if (fileWithSubDir.StartsWith('\\'))
                {
                    fileWithSubDir = fileWithSubDir.Substring(1);
                }

                modifiedFile = Path.Combine(objDir, fileWithSubDir);

                var dir = Path.GetDirectoryName(modifiedFile);
                if (!Directory.Exists(dir))
                {
                    Directory.CreateDirectory(dir);
                }

                File.Copy(file, modifiedFile, true);
                modifiedFiles.Add(modifiedFile);
            }

            System.Diagnostics.Stopwatch watch = System.Diagnostics.Stopwatch.StartNew();

            Console.WriteLine($"  Moving names to correct namespaces...");
            System.Threading.Tasks.Parallel.ForEach(modifiedFiles, opt, (treeFile) =>
            {
                if (!treeFile.EndsWith(".manual.cs"))
                {
                    var tree = ReadTree(treeFile);
                    tree = NamesToCorrectNamespacesMover.MoveNamesToCorrectNamespaces(tree, requiredNamespaces);

                    infoFinder.AnalyzeTree(tree);

                    WriteTree(tree, treeFile);
                }
            });

            var elapsed = watch.Elapsed;
            Console.WriteLine($"  {OutputUtils.FormatTimespan(elapsed)}");

            ShowMemory();

            Console.WriteLine($"  Cleaning syntax trees...");

            watch.Restart();

            HashSet<string> enumsMakeFlagsHashSet = enumsMakeFlags != null ? new HashSet<string>(enumsMakeFlags) : new HashSet<string>();
            System.Threading.Tasks.Parallel.ForEach(FilesToTrees(modifiedFiles), opt, (tree) =>
            {
                var cleanedTree = MetadataSyntaxTreeCleaner.CleanSyntaxTree(tree, remaps, enumAdditions, enumsMakeFlagsHashSet, requiredNamespaces, staticLibs, infoFinder.EmptyStructs, infoFinder.EnumMemberNames, tree.FilePath);
                WriteTree(cleanedTree, cleanedTree.FilePath);
            });

            Console.WriteLine($"  {OutputUtils.FormatTimespan(watch.Elapsed)}");
            ShowMemory();

            if (arch == "crossarch")
            {
                List<string> partitionsNotNeedingCrossarch = new List<string>();

                Console.WriteLine($"  Merging cross-arch items...");
                watch.Restart();

                List<string> filesToMerge = new List<string>();
                foreach (string x86FileName in modifiedFiles.Where(f => GetArchitectureForFileName(f) == Windows.Win32.Interop.Architecture.X86))
                {
                    string x64FileName = x86FileName.Replace(@"\x86\", @"\x64\", StringComparison.OrdinalIgnoreCase);
                    string arm64FileName = x86FileName.Replace(@"\x86\", @"\arm64\", StringComparison.OrdinalIgnoreCase);

                    if (File.Exists(x64FileName) && File.Exists(arm64FileName))
                    {
                        string x86Content = File.ReadAllText(x86FileName);
                        if (x86Content == File.ReadAllText(x64FileName) && x86Content == File.ReadAllText(arm64FileName))
                        {
                            var parititionName = GetPartitionNameFromFileName(x86FileName);

                            File.Delete(x64FileName);
                            File.Delete(arm64FileName);

                            partitionsNotNeedingCrossarch.Add(GetPartitionNameFromFileName(x86FileName));
                        }
                        else
                        {
                            filesToMerge.Add(x64FileName);
                            filesToMerge.Add(x86FileName);
                            filesToMerge.Add(arm64FileName);
                        }
                    }
                }

                CrossArchSyntaxMap crossArchSyntaxMap = LoadCrossArchMapFromFiles(filesToMerge, opt);
                HashSet<string> nonX86TreesUsedForX86 = crossArchSyntaxMap.Get64BitTreesUsedForX86();

                CrossArchTreeMerger crossArchTreeMerger = new CrossArchTreeMerger(crossArchSyntaxMap);
                System.Threading.Tasks.Parallel.ForEach(FilesToTrees(filesToMerge.Where(f => GetArchitectureForFileName(f) == Windows.Win32.Interop.Architecture.X86)), opt, (x86Tree) =>
                {
                    string x64FileName = x86Tree.FilePath.Replace(@"\x86\", @"\x64\", StringComparison.OrdinalIgnoreCase);
                    string arm64FileName = x86Tree.FilePath.Replace(@"\x86\", @"\arm64\", StringComparison.OrdinalIgnoreCase);

                    var parititionName = GetPartitionNameFromFileName(x86Tree.FilePath);

                    var fixed86Tree = crossArchTreeMerger.ProcessTree(x86Tree, out _);
                    var fixed64Tree = crossArchTreeMerger.ProcessTree(ReadTree(x64FileName), out bool x64Contributed);
                    var fixedArm64Tree = crossArchTreeMerger.ProcessTree(ReadTree(arm64FileName), out bool arm64Contributed);

                    x64Contributed |= nonX86TreesUsedForX86.Contains(x64FileName);
                    arm64Contributed |= nonX86TreesUsedForX86.Contains(arm64FileName);

                    if (!x64Contributed && SyntaxUtils.IsTreeEmpty(fixed64Tree) &&
                         !arm64Contributed && SyntaxUtils.IsTreeEmpty(fixedArm64Tree))
                    {
                        File.Delete(x64FileName);
                        File.Delete(arm64FileName);

                        partitionsNotNeedingCrossarch.Add(GetPartitionNameFromFileName(parititionName));
                    }
                    else
                    {
                        WriteTree(fixed64Tree, fixed64Tree.FilePath);
                        WriteTree(fixedArm64Tree, fixedArm64Tree.FilePath);
                    }

                    WriteTree(fixed86Tree, fixed86Tree.FilePath);
                });

                if (partitionsNotNeedingCrossarch.Count != 0)
                {
                    string partInfo = string.Join(';', partitionsNotNeedingCrossarch.ToArray().OrderBy(s => s));

                    Console.WriteLine($"ClangSharpSourceToWinmd : warning CSSW001: Partitions detected with no cross-arch differences: {partInfo}");
                }

                Console.WriteLine($"  {OutputUtils.FormatTimespan(watch.Elapsed)}");
                ShowMemory();
            }

            Console.WriteLine($"  Creating C# compilation on processed syntax trees...");
            watch.Restart();

            CSharpCompilationOptions compilationOptions = new CSharpCompilationOptions(OutputKind.WindowsRuntimeMetadata, allowUnsafe: true);
            var comp =
                CSharpCompilation.Create(
                    null,
                    FilesToTrees(modifiedFiles.Where(f => File.Exists(f))),
                    refs,
                    compilationOptions);

            Console.WriteLine($"  {OutputUtils.FormatTimespan(watch.Elapsed)}");
            ShowMemory();

            return new ClangSharpSourceCompilation(comp, typeImports);
        }

        public ReadOnlyCollection<Diagnostic> GetDiagnostics()
        {
            List<Diagnostic> diags = new List<Diagnostic>();
            var culture = new System.Globalization.CultureInfo("en-US");

            foreach (var diag in this.compilation.GetDeclarationDiagnostics())
            {
                if (diag.Severity == DiagnosticSeverity.Warning)
                {
                    continue;
                }

                // CS0208: Cannot take the address of, get the size of, or declare a pointer to a managed type
                // We can do this in metadata, so it's OK
                // CS0558: Operator, which we don't emit
                // CS0562: Operator, which we don't emit
                // CS0590: Operator, which we don't emit
                // CS0568: Ctor on structs, which we don't emit
                // CS0592: FieldOffset on a property which we don't emit
                // CS1745: Cannot specify default parameter value in conjunction with DefaultParameterAttribute or OptionalAttribute
                // CS0111: Operator
                if (diag.Id == "CS0208" || diag.Id == "CS0558" || diag.Id == "CS0562" || diag.Id == "CS0590" || diag.Id == "CS0568" || diag.Id == "CS0592" || diag.Id == "CS1745" ||
                    diag.Id == "CS0111")
                {
                    continue;
                }

                // CS0029: Cannot implicitly convert type 'string' to 'string[]'
                // Problem with ClangSharp that emits WCHAR Bar[] = "foo" into string[] Bar = "foo"
                // We work around this in the emitter
                if (diag.Id == "CS0029" && diag.ToString().Contains("'string' to 'string[]'"))
                {
                    continue;
                }

                // Symbol not found. See if it's in the type import list
                if (diag.Id == "CS0246")
                {
                    var symbolNameRegx = new System.Text.RegularExpressions.Regex(@"The type or namespace name '(\w+)'");
                    var match = symbolNameRegx.Match(diag.GetMessage(culture));
                    if (match.Success)
                    {
                        var symbolName = match.Groups[1].Value;
                        if (this.typeImports.ContainsKey(symbolName) || this.typeImports.ContainsKey($"{symbolName}(interface)"))
                        {
                            continue;
                        }
                    }
                }

                diags.Add(diag);
            }

            return diags.AsReadOnly();
        }

        private static bool IsValidCsSourceFile(string fileName, string arch)
        {
            if (fileName.EndsWith(".modified.cs"))
            {
                return false;
            }

            string potentialArch = Path.GetFileName(Path.GetDirectoryName(fileName));
            if (potentialArch == "x86" || potentialArch == "x64" || potentialArch == "arm64")
            {
                if (arch == "crossarch")
                {
                    return true;
                }
                else
                {
                    return arch == potentialArch;
                }
            }

            return true;
        }

        private static string FindNetstandardDllPath()
        {
            // Is there a better way to find this?
            string progFiles = Environment.GetFolderPath(Environment.SpecialFolder.ProgramFiles);
            return Path.Combine(progFiles, @"dotnet\packs\NETStandard.Library.Ref\2.1.0\ref\netstandard2.1\netstandard.dll");
        }

#if ShowMemoryInfo
        [StructLayout(LayoutKind.Sequential, CharSet = CharSet.Auto)]
        private class MEMORYSTATUSEX
        {
            public uint dwLength;
            public uint dwMemoryLoad;
            public ulong ullTotalPhys;
            public ulong ullAvailPhys;
            public ulong ullTotalPageFile;
            public ulong ullAvailPageFile;
            public ulong ullTotalVirtual;
            public ulong ullAvailVirtual;
            public ulong ullAvailExtendedVirtual;
            public MEMORYSTATUSEX()
            {
                this.dwLength = (uint)Marshal.SizeOf(typeof(MEMORYSTATUSEX));
            }
        }

        [return: MarshalAs(UnmanagedType.Bool)]
        [DllImport("kernel32.dll", CharSet = CharSet.Auto, SetLastError = true)]
        static extern bool GlobalMemoryStatusEx([In, Out] MEMORYSTATUSEX lpBuffer);
#endif

        private class TreeInfoFinder : CSharpSyntaxWalker
        {
            public TreeInfoFinder()
            {
            }

            public HashSet<string> EmptyStructs { get; } = new HashSet<string>();

            public HashSet<string> EnumMemberNames { get; } = new HashSet<string>();


            public void AnalyzeTree(SyntaxTree tree)
            {
                this.Visit(tree.GetRoot());
            }

            public override void VisitEnumMemberDeclaration(EnumMemberDeclarationSyntax node)
            {
                lock (this.EnumMemberNames)
                {
                    this.EnumMemberNames.Add(node.Identifier.ValueText);
                }

                base.VisitEnumMemberDeclaration(node);
            }

            public override void VisitStructDeclaration(StructDeclarationSyntax node)
            {
                if (!SyntaxUtils.IsEmptyStruct(node))
                {
                    lock (this.EmptyStructs)
                    {
                        this.EmptyStructs.Add(node.Identifier.ValueText);
                    }
                }
            }
        }
    }
}
