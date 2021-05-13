using System.Diagnostics;
using Microsoft.Build.Framework;
using Microsoft.Build.Utilities;

namespace MetadataTasks
{
    internal static class TaskUtils
    {
        public static int ExecuteCmd(string cmd, string args, out string output, TaskLoggingHelper log)
        {
            output = null;

            log.LogMessage(MessageImportance.Low, $"Calling: {cmd} {args}");

            using Process process = new Process();
            process.StartInfo.CreateNoWindow = true;
            process.StartInfo.UseShellExecute = false;
            process.StartInfo.RedirectStandardOutput = true;

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
