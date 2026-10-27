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

        public bool PreflightOnly { get; set; }

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
            var validation = new MetadataUtils.GenerationValidation();
            string report = Path.Combine(Path.GetDirectoryName(this.ScraperFunctionPointerFixupsRsp), "function-pointer-preparation-diagnostics.json");
            Directory.CreateDirectory(Path.GetDirectoryName(report));
            File.Delete(report);

            foreach (var fileItem in this.FunctionPointerFixups)
            {
                string fixupsFileName = fileItem.ItemSpec;
                if (!File.Exists(fixupsFileName))
                {
                    validation.Add(new InvalidDataException("Missing function-pointer fixups input."),
                        "WMG004", "PrepSettingsForFunctionPointerFixups", fixupsFileName);
                    continue;
                }

                FunctionPointerFixup[] functionFixups;
                try
                {
                    functionFixups = Newtonsoft.Json.JsonConvert.DeserializeObject<FunctionPointerFixup[]>(File.ReadAllText(fixupsFileName));
                    if (functionFixups == null || Array.Exists(functionFixups, fixup => fixup == null))
                        throw new Newtonsoft.Json.JsonSerializationException("Expected an array of non-null function-pointer fixups.");
                }
                catch (Newtonsoft.Json.JsonException error)
                {
                    validation.Add(error, "WMG004", "PrepSettingsForFunctionPointerFixups", fixupsFileName);
                    continue;
                }
                foreach (var functionFixup in functionFixups)
                {
                    if (string.IsNullOrWhiteSpace(functionFixup.name))
                    {
                        validation.Add(new InvalidDataException("Function-pointer fixups require a name."),
                            "WMG004", "PrepSettingsForFunctionPointerFixups", fixupsFileName);
                        continue;
                    }
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
            if (validation.HasErrors)
            {
                File.Delete(this.ScraperFunctionPointerFixupsRsp);
                File.Delete(this.EmitterFunctionPointerFixupsRsp);
                validation.Block("ScrapeHeaders;ScrapeConstants;EmitWinmd;default tests", "valid function-pointer settings");
                validation.WriteReport(report);
                this.Log.LogError(validation.Format());
                return false;
            }
            if (this.PreflightOnly)
                return true;
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
