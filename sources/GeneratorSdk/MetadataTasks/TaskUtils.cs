using System;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using Microsoft.Build.Framework;
using Microsoft.Build.Utilities;

namespace MetadataTasks
{
    internal static class TaskUtils
    {
        public static bool IsUpToDate(string file, DateTime checkFileTime)
        {
            if (File.Exists(file))
            {
                DateTime fileTime = File.GetLastWriteTimeUtc(file);
                if (fileTime.CompareTo(checkFileTime) > 0)
                {
                    return false;
                }
            }

            return true;
        }

        public static bool IsUpToDate(string file, string checkFile)
        {
            if (!File.Exists(checkFile))
            {
                return false;
            }

            if (File.Exists(file))
            {
                DateTime checkFileTime = File.GetLastWriteTimeUtc(checkFile);
                DateTime fileTime = File.GetLastWriteTimeUtc(file);
                if (fileTime.CompareTo(checkFileTime) > 0)
                {
                    return false;
                }
            }

            return true;
        }

        public static bool IsUpToDate(IEnumerable<string> files, string checkFile)
        {
            if (!File.Exists(checkFile))
            {
                return false;
            }

            DateTime checkFileTime = File.GetLastWriteTimeUtc(checkFile);
            return files.All(file => TaskUtils.IsUpToDate(file, checkFileTime));
        }

        public static void FilterRspFile(string inputFile, StreamWriter writer, HashSet<string> switchesSet)
        {
            bool inValidSection = false;

            foreach (var line in File.ReadAllLines(inputFile))
            {
                if (line.StartsWith("--"))
                {
                    inValidSection = switchesSet.Contains(line.Trim());
                }

                if (inValidSection)
                {
                    writer.WriteLine(line);
                }
            }
        }

        public static void FilterRspFiles(IEnumerable<string> inputFiles, string outputFile, IEnumerable<string> validSwitches)
        {
            if (File.Exists(outputFile))
            {
                File.Delete(outputFile);
            }

            if (inputFiles == null || !inputFiles.Any())
            {
                return;
            }

            var switchesSet = new HashSet<string>(validSwitches, System.StringComparer.OrdinalIgnoreCase);

            using var writer = new StreamWriter(outputFile);

            foreach (string file in inputFiles)
            {
                FilterRspFile(file, writer, switchesSet);
            }
        }

        public static void AppendRspFileIfNotNull(this CommandLineBuilder builder, string rspPath)
        {
            if (!string.IsNullOrEmpty(rspPath) && File.Exists(rspPath))
            {
                AppendRspFile(builder, rspPath);
            }
        }

        public static void AppendRspFile(this CommandLineBuilder builder, string rspPath)
        {
            string arg = $"\"@{rspPath}\"";
            builder.AppendSwitch(arg);
        }

        public static string GetFullPath(string path, string rootDir)
        {
            if (!Path.IsPathRooted(path))
            {
                path = Path.Combine(rootDir, path);
            }

            return path;
        }

        public static IEnumerable<string> GetFullPaths(IEnumerable<ITaskItem> items, string rootDir)
        {
            if (items != null)
            {
                foreach (ITaskItem item in items)
                {
                    yield return GetFullPath(item.ItemSpec, rootDir);
                }
            }
        }

        public static IEnumerable<string> GetFilesFromMetadata(this ITaskItem item, string name, string root)
        {
            string[] items = item.GetMetadata(name).Split(';', System.StringSplitOptions.RemoveEmptyEntries);
            for (int i = 0; i < items.Length; i++)
            {
                if (!Path.IsPathRooted(items[i]))
                {
                    items[i] = Path.Combine(root, items[i]);
                }
            }

            return items;
        }

        public static bool CallPowershellScript(string scriptPath, string args, TaskLoggingHelper log, out string scriptOutput)
        {
            string scriptArgs = $"-Command \"& {{Set-ExecutionPolicy -Scope Process -ExecutionPolicy Unrestricted; & '{scriptPath}' {args}}}\"";

            int ret = TaskUtils.ExecuteCmd("powershell.exe", scriptArgs, out scriptOutput, log);
            if (ret != 0)
            {
                string fileName = Path.GetFileName(scriptPath);
                log.LogError($"{fileName} failed: {scriptOutput}");
                return false;
            }

            return true;
        }

        public static bool EnsureClangSharpInstalled(string scriptsDir, TaskLoggingHelper log)
        {
            string scriptPath = Path.Combine(scriptsDir, "InstallTools.ps1");
            return CallPowershellScript(scriptPath, string.Empty, log, out _);
        }

        public static string GetVcDirPath(string scriptsDir, TaskLoggingHelper log)
        {
            string scriptPath = Path.Combine(scriptsDir, "GetVcDirPath.ps1");
            CallPowershellScript(scriptPath, "x86 x86", log, out var scriptOutput);

            return scriptOutput;
        }

        public static int ExecuteCmd(string cmd, string args, out string output, out string error, TaskLoggingHelper log, string extraPath = null)
        {
            output = null;

            log.LogMessage(MessageImportance.Low, $"Calling: {cmd} {args}");

            using Process process = new Process();
            process.StartInfo.CreateNoWindow = true;
            process.StartInfo.UseShellExecute = false;
            process.StartInfo.RedirectStandardOutput = true;

            if (extraPath != null)
            {
                StringDictionary env = process.StartInfo.EnvironmentVariables;
                env["PATH"] = env["PATH"] + ";" + extraPath;
            }

            StringBuilder errorText = new StringBuilder();
            process.StartInfo.RedirectStandardError = true;
            process.ErrorDataReceived +=
                new DataReceivedEventHandler((sender, e) => { errorText.AppendLine(e.Data); });

            process.StartInfo.FileName = cmd;
            process.StartInfo.Arguments = args;
            process.Start();

            process.BeginErrorReadLine();
            output = process.StandardOutput.ReadToEnd();
            process.WaitForExit();

            error = errorText.ToString();

            return process.ExitCode;
        }

        public static int ExecuteCmd(string cmd, string args, out string output, TaskLoggingHelper log, string extraPath = null)
        {
            string fullOutput;
            int ret = ExecuteCmd(cmd, args, out fullOutput, out var error, log, extraPath);
            fullOutput += error;

            output = fullOutput;

            return ret;
        }
    }
}
