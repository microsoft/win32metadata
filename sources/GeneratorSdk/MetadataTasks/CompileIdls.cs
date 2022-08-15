using System.Collections.Generic;
using System.IO;
using System.Text;
using System.Text.RegularExpressions;
using Microsoft.Build.Framework;
using Microsoft.Build.Utilities;

namespace MetadataTasks
{
    public class CompileIdls : Task
    {
        public ITaskItem[] Idls
        {
            get;
            set;
        }

        [Required]
        public string ObjDir
        {
            get; set;
        }

        [Required]
        public string CompiledHeadersDir
        {
            get; set;
        }

        [Required]
        public string ScriptsDir
        {
            get; set;
        }

        [Required]
        public string SdkIncRoot
        {
            get; set;
        }

        [Required]
        public string SdkBinDir
        {
            get; set;
        }

        [Required]
        public string MSBuildProjectDirectory
        {
            get; set;
        }

        public string AdditionalIncludes
        {
            get; set;
        }

        public override bool Execute()
        {
#if DEBUG
            if (System.Environment.GetEnvironmentVariable("DEBUG_COMPILE_IDLS_TASK") == "1")
            {
                System.Diagnostics.Debugger.Launch();
            }
#endif

            string[] idls = this.GetIdls();
            if (idls.Length == 0)
            {
                return true;
            }

            Directory.CreateDirectory(this.ObjDir);
            Directory.CreateDirectory(this.CompiledHeadersDir);

            string vcPath = TaskUtils.GetVcDirPath(this.ScriptsDir, this.Log);
            if (string.IsNullOrEmpty(vcPath))
            {
                return false;
            }

            vcPath = vcPath.Trim();

            string scriptPath = Path.Combine(this.ScriptsDir, "ConvertMidlAttributesToSalAnnotations.ps1");
            string midlPath = Path.Combine(this.SdkBinDir, "x86", "midl.exe");
            string umDir = Path.Combine(this.SdkIncRoot, "um");
            string sharedDir = Path.Combine(this.SdkIncRoot, "shared");
            string winrtDir = Path.Combine(this.SdkIncRoot, "winrt");
            string commonMidlArgs = $"/out \"{this.ObjDir}\" /no_warn /DUNICODE /D_UNICODE /DWINVER=0x0A00 -D_APISET_MINWIN_VERSION=0x010F /DNTDDI_VERSION=0x0A00000B /DBUILD_UMS_ENABLED=0 /DBUILD_WOW64_ENABLED=0 /DBUILD_ARM64X_ENABLED=0 /DEXECUTABLE_WRITES_SUPPORT=0 -D_USE_DECLSPECS_FOR_SAL=1 -D_CONTROL_FLOW_GUARD_SVCTAB=1  /Di386 /D_X86_ /D_WCHAR_T_DEFINED /no_stamp /nologo  /no_settings_comment /lcid 1033 -sal /win32 -target NT100 /Zp8 /I\"{umDir}\" /I\"{sharedDir}\" /I\"{winrtDir}\"";

            if (!string.IsNullOrEmpty(this.AdditionalIncludes))
            {
                commonMidlArgs += $" /I\"{this.AdditionalIncludes}\"";
            }

            foreach (var idl in idls)
            {
                string fixedIdlFile = Path.Combine(this.ObjDir, Path.GetFileName(idl));
                string scriptArgs = $"-inputFileName '{idl}' -outputFileName '{fixedIdlFile}'";
                if (File.Exists(fixedIdlFile))
                {
                    File.Delete(fixedIdlFile);
                }

                if (!TaskUtils.CallPowershellScript(scriptPath, scriptArgs, this.Log, out _))
                {
                    return false;
                }

                string compiledHeader = Path.Combine(this.CompiledHeadersDir, Path.ChangeExtension(Path.GetFileName(idl), ".h"));
                string midlArgs = $"\"{fixedIdlFile}\" /header \"{compiledHeader}\" {commonMidlArgs}";
                int ret = TaskUtils.ExecuteCmd(midlPath, midlArgs, out var midlOutput, this.Log, vcPath);
                if (ret != 0)
                {
                    this.Log.LogError($"midl.exe failed: {midlOutput}");
                    return false;
                }

                this.Log.LogMessage(midlOutput);
            }

            return true;
        }

        private string[] GetIdls()
        {
            List<string> ret = new List<string>();
            if (this.Idls != null)
            {
                foreach (var item in this.Idls)
                {
                    var path = item.ItemSpec;
                    if (!Path.IsPathRooted(path))
                    {
                        path = Path.Combine(this.MSBuildProjectDirectory, path);
                    }

                    ret.Add(path);
                }
            }

            return ret.ToArray();
        }
    }
}
