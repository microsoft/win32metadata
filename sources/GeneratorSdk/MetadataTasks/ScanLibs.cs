using System.Collections.Generic;
using System.IO;
using System.Text;
using Microsoft.Build.Framework;
using Microsoft.Build.Utilities;
using MetadataUtils;

namespace MetadataTasks
{
    public class ScanLibs : Task
    {
        public ITaskItem[] Libs { get; set; }

        [Required]
        public string LibToolsBinDir { get; set; }

        [Required]
        public string WithLibsRsp { get; set; }

        [Required]
        public string MSBuildProjectDirectory { get; set; }

        // Optional. Receives "--importEntryPoint" mappings for imports the DLL exports by ordinal only.
        public string ImportEntryPointsRsp { get; set; }

        // Directories searched for the DLLs the import libraries refer to. An import library marks an export as
        // ordinal-type both for NONAME exports and for named exports that were given an explicit ordinal, so the
        // DLL's export table decides: "#ordinal" is used only when the DLL does not export the name.
        public ITaskItem[] DllSearchPaths { get; set; }

        // Opt in to the build process's Windows system directory after explicit search paths.
        // Its DLLs reflect the host OS and process architecture, not necessarily the target SDK.
        public bool ProbeSystemDlls { get; set; }

        // When true, imports the import library marks ordinal-type are emitted as "#ordinal" even if the DLL
        // can't be found to confirm it. Defaults to false, which keeps the by-name import in that case.
        public bool TrustImportLibOrdinals { get; set; }

        // Set to false to always emit imports by name.
        public bool PreserveOrdinalImports { get; set; } = true;

        public override bool Execute()
        {
#if DEBUG
            if (System.Environment.GetEnvironmentVariable("DEBUG_SCAN_LIBS_TASK") == "1")
            {
                System.Diagnostics.Debugger.Launch();
            }
#endif

            string[] libFiles = this.GetLibs();
            var functionNames = new HashSet<string>(System.StringComparer.OrdinalIgnoreCase);
            StringBuilder libLines = new StringBuilder();
            StringBuilder entryPointLines = new StringBuilder();
            var exportsByDll = new Dictionary<string, (HashSet<string> Names, HashSet<ushort> Ordinals)>(System.StringComparer.OrdinalIgnoreCase);
            foreach (var lib in libFiles)
            {
                var importInfos = LibScraper.GetImportInfos(lib);
                foreach (var importInfo in importInfos)
                {
                    string procName = importInfo.ProcName;
                    if (!functionNames.Contains(procName))
                    {
                        if (libLines.Length == 0)
                        {
                            libLines.AppendLine("--with-librarypath");
                        }

                        var dllName = Path.GetFileNameWithoutExtension(importInfo.Dll);

                        libLines.AppendLine($"{procName}={dllName}");
                        functionNames.Add(procName);

                        if (this.PreserveOrdinalImports && importInfo.Ordinal.HasValue && this.IsOrdinalOnly(importInfo, exportsByDll))
                        {
                            if (entryPointLines.Length == 0)
                            {
                                entryPointLines.AppendLine("--importEntryPoint");
                            }

                            entryPointLines.AppendLine($"{procName}={importInfo.EntryPoint}");
                        }
                    }
                }
            }

            if (libLines.Length != 0)
            {
                var dir = Path.GetDirectoryName(this.WithLibsRsp);
                Directory.CreateDirectory(dir);

                File.WriteAllText(this.WithLibsRsp, libLines.ToString());
            }
            else
            {
                if (File.Exists(this.WithLibsRsp))
                {
                    File.Delete(this.WithLibsRsp);
                }
            }

            if (!string.IsNullOrEmpty(this.ImportEntryPointsRsp))
            {
                if (entryPointLines.Length != 0)
                {
                    Directory.CreateDirectory(Path.GetDirectoryName(this.ImportEntryPointsRsp));
                    File.WriteAllText(this.ImportEntryPointsRsp, entryPointLines.ToString());
                }
                else if (File.Exists(this.ImportEntryPointsRsp))
                {
                    File.Delete(this.ImportEntryPointsRsp);
                }
            }

            return true;
        }

        private bool IsOrdinalOnly(ImportInfo importInfo, Dictionary<string, (HashSet<string> Names, HashSet<ushort> Ordinals)> exportsByDll)
        {
            if (!exportsByDll.TryGetValue(importInfo.Dll, out var exports))
            {
                exports = this.FindExports(importInfo.Dll);
                exportsByDll[importInfo.Dll] = exports;
            }

            return exports.Names == null ? this.TrustImportLibOrdinals :
                !exports.Names.Contains(importInfo.ProcName) && exports.Ordinals.Contains(importInfo.Ordinal.Value);
        }

        private (HashSet<string> Names, HashSet<ushort> Ordinals) FindExports(string dllName)
        {
            if (this.DllSearchPaths != null)
            {
                foreach (ITaskItem item in this.DllSearchPaths)
                {
                    string dir = Path.IsPathRooted(item.ItemSpec) ? item.ItemSpec : Path.Combine(this.MSBuildProjectDirectory, item.ItemSpec);
                    string path = Path.Combine(dir, dllName);
                    if (File.Exists(path))
                    {
                        return (DllExports.GetNamedExports(path), DllExports.GetOrdinalOnlyExports(path));
                    }
                }
            }

            if (this.ProbeSystemDlls && System.OperatingSystem.IsWindows())
            {
                string path = Path.Combine(System.Environment.SystemDirectory, dllName);
                if (File.Exists(path))
                {
                    this.Log.LogMessage(MessageImportance.Low, $"Checking host system DLL exports: {path}");
                    return (DllExports.GetNamedExports(path), DllExports.GetOrdinalOnlyExports(path));
                }
            }

            return (null, null);
        }

        private string[] GetLibs()
        {
            var ret = new List<string>();
            if (this.Libs != null)
            {
                foreach (ITaskItem libItem in this.Libs)
                {
                    var libPath = libItem.ItemSpec;
                    if (!Path.IsPathRooted(libPath))
                    {
                        libPath = Path.Combine(this.MSBuildProjectDirectory, libPath);
                    }

                    ret.Add(libPath);
                }
            }

            return ret.ToArray();
        }
    }
}
