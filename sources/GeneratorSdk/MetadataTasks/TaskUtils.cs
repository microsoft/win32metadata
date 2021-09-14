using System.Diagnostics;
using System.IO;
using Microsoft.Build.Framework;
using Microsoft.Build.Utilities;

namespace MetadataTasks
{
    internal static class TaskUtils
    {
        public static string GetVcDirPath(string scriptsDir, TaskLoggingHelper log)
        {
            string scriptPath = Path.Combine(scriptsDir, "GetVcDirPath.ps1");
            string scriptArgs = $"-File \"{scriptPath}\" x86 x86";

            int ret = TaskUtils.ExecuteCmd("powershell.exe", scriptArgs, out var scriptOutput, log);
            if (ret != 0)
            {
                log.LogError($"GetVcDirPath.ps1 failed: {scriptOutput}");
                return null;
            }

            return scriptOutput;
        }

        public static int ExecuteCmd(string cmd, string args, out string output, TaskLoggingHelper log, string extraPath = null)
        {
            output = null;

            log.LogMessage(MessageImportance.Low, $"Calling: {cmd} {args}");

            using Process process = new Process();
            process.StartInfo.CreateNoWindow = true;
            process.StartInfo.UseShellExecute = false;
            process.StartInfo.RedirectStandardOutput = true;

            if (extraPath != null)
            {
                var env = process.StartInfo.EnvironmentVariables;
                env["PATH"] = env["PATH"] + ";" + extraPath;
            }

            string errorText = null;
            process.StartInfo.RedirectStandardError = true;
            process.ErrorDataReceived +=
                new DataReceivedEventHandler((sender, e) => { errorText += e.Data; });

            process.StartInfo.FileName = cmd;
            process.StartInfo.Arguments = args;
            process.Start();

            process.BeginErrorReadLine();
            output = process.StandardOutput.ReadToEnd();
            process.WaitForExit();
            output += errorText;

            return process.ExitCode;
        }
    }
}
