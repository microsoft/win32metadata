using System;
using System.Diagnostics;
using System.IO;
using System.Reflection;
using Xunit.Abstractions;

namespace TestCommon
{
    public static class TestUtils
    {
        public static string GetAssetFile(string fileName)
        {
            return Path.Combine(GetAssetDir(), fileName);
        }

        public static string GetAssetDir()
        {
            return Path.Combine(BinPath, "assets");
        }

        public static string Win32WinmdPath => Path.GetFullPath(Path.Combine(BinPath, @"..\..\windows.win32.winmd"));

        public static string BinPath => Path.GetDirectoryName(Assembly.GetExecutingAssembly().Location);

        public static int ExecuteCmd(string cmd, string args, out string output, ITestOutputHelper logger)
        {
            output = null;

            logger.WriteLine($"Calling: {cmd} {args}");

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

