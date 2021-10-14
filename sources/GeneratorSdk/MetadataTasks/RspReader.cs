using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace MetadataTasks
{
    public static class RspReader
    {
        public static IEnumerable<string> GetSettingsValues(string settingsFile, string settingsName)
        {
            bool inSettingsName = false;
            foreach (string line in File.ReadAllLines(settingsFile))
            {
                if (line.StartsWith("--"))
                {
                    inSettingsName = line == settingsName;
                    continue;
                }

                if (inSettingsName && !string.IsNullOrEmpty(line))
                {
                    yield return line;
                }
            }
        }
    }
}
