using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
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

        public override bool Execute()
        {
#if DEBUG
            if (System.Environment.GetEnvironmentVariable("DEBUG_SCAN_LIBS_TASK") == "1")
            {
                System.Diagnostics.Debugger.Launch();
            }
#endif

            string[] libFiles = this.GetLibs();
            var validation = new GenerationValidation();
            string report = Path.Combine(Path.GetDirectoryName(this.WithLibsRsp), "library-input-diagnostics.json");
            Directory.CreateDirectory(Path.GetDirectoryName(report));
            File.Delete(report);
            var functionNames = new HashSet<string>(System.StringComparer.OrdinalIgnoreCase);
            StringBuilder libLines = new StringBuilder();
            foreach (var lib in libFiles)
            {
                ImportInfo[] importInfos;
                try
                {
                    using (var stream = File.OpenRead(lib))
                    {
                        byte[] signature = new byte[8];
                        stream.ReadExactly(signature);
                        if (!signature.SequenceEqual(Encoding.ASCII.GetBytes("!<arch>\n")))
                            throw new InvalidDataException("Input is not a valid .lib archive.");
                    }
                    importInfos = LibScraper.GetImportInfos(lib).ToArray();
                }
                catch (Exception error) when (error is FileNotFoundException or DirectoryNotFoundException or
                    InvalidDataException or EndOfStreamException or FormatException or OverflowException)
                {
                    validation.Add(error, "WMG004", "PrepareWithLibsRsp", lib);
                    continue;
                }
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
                    }
                }
            }

            if (validation.HasErrors)
            {
                File.Delete(this.WithLibsRsp);
                validation.Block("ScrapeHeaders;ScrapeConstants;EmitWinmd;default tests", "valid import-library inputs");
                validation.WriteReport(report);
                this.Log.LogError(validation.Format());
                return false;
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

            return true;
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
