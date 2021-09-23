using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
using Microsoft.Build.Framework;
using Microsoft.Build.Utilities;

namespace MetadataTasks
{
    public class PrepSettingsForFunctionPointerFixups : Task
    {
        [Required]
        public ITaskItem[] FunctionPointerFixups { get; set; }

        public string ScraperFunctionPointerFixupsRsp { get; set; }

        public string EmitterFunctionPointerFixupsRsp { get; set; }

        public override bool Execute()
        {
#if DEBUG
            if (System.Environment.GetEnvironmentVariable("DEBUG_PREP_FUNCTION_POINTER_FIXUPS_TASK") == "1")
            {
                System.Diagnostics.Debugger.Launch();
            }
#endif
            StringBuilder emitterRspReducePointerLevelSection = new();
            StringBuilder scraperRspRemapSection = new();
            StringBuilder scraperRspExcludeSection = new();

            foreach (var fileItem in this.FunctionPointerFixups)
            {
                string fixupsFileName = fileItem.ItemSpec;
                if (!File.Exists(fixupsFileName))
                {
                    continue;
                }

                var functionFixups = Newtonsoft.Json.JsonConvert.DeserializeObject<FunctionPointerFixup[]>(File.ReadAllText(fixupsFileName));
                foreach (var functionFixup in functionFixups)
                {
                    bool origDeclIsPointer = functionFixup.alreadyPointer;

                    if (!string.IsNullOrEmpty(functionFixup.pointerType))
                    {
                        scraperRspExcludeSection.AppendLine(functionFixup.pointerType);
                        scraperRspRemapSection.AppendLine($"{functionFixup.name}={functionFixup.pointerType}");

                        if (!origDeclIsPointer)
                        {
                            emitterRspReducePointerLevelSection.AppendLine(functionFixup.pointerType);
                        }
                    }
                    else
                    {
                        if (!origDeclIsPointer)
                        {
                            emitterRspReducePointerLevelSection.AppendLine(functionFixup.name);
                        }
                    }
                }
            }

            Directory.CreateDirectory(Path.GetDirectoryName(this.ScraperFunctionPointerFixupsRsp));
            using StreamWriter outputScraperRspWriter = new StreamWriter(this.ScraperFunctionPointerFixupsRsp);
            AppendSectionToWriter(outputScraperRspWriter, scraperRspExcludeSection, "--exclude");
            AppendSectionToWriter(outputScraperRspWriter, scraperRspRemapSection, "--remap");

            Directory.CreateDirectory(Path.GetDirectoryName(this.EmitterFunctionPointerFixupsRsp));
            using StreamWriter outputEmitterRspWriter = new StreamWriter(this.EmitterFunctionPointerFixupsRsp);
            AppendSectionToWriter(outputEmitterRspWriter, emitterRspReducePointerLevelSection, "--reducePointerLevel");

            return true;
        }

        private static void AppendSectionToWriter(StreamWriter writer, StringBuilder section, string sectionSwitch)
        {
            if (section.Length != 0)
            {
                writer.WriteLine(sectionSwitch);
                writer.Write(section.ToString());
            }
        }

        private class FunctionPointerFixup
        {
            public bool alreadyPointer { get; set; }
            public string pointerType { get; set; }
            public string name { get; set; }
        }
    }
}
