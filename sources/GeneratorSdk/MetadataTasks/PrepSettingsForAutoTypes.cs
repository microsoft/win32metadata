using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
using Microsoft.Build.Framework;
using Microsoft.Build.Utilities;

namespace MetadataTasks
{
    public class PrepSettingsForAutoTypes : Task
    {
        [Required]
        public ITaskItem[] AutoTypes { get; set; }

        public string ScraperAutoTypesRsp { get; set; }

        public bool PreflightOnly { get; set; }

        public override bool Execute()
        {
#if DEBUG
            if (System.Environment.GetEnvironmentVariable("DEBUG_PREP_AUTO_TYPES_TASK") == "1")
            {
                System.Diagnostics.Debugger.Launch();
            }
#endif

            HashSet<string> typesToExclude = new HashSet<string>();
            StringBuilder remapSection = new StringBuilder();
            var validation = new MetadataUtils.GenerationValidation();
            string report = Path.Combine(Path.GetDirectoryName(this.ScraperAutoTypesRsp), "auto-types-preparation-diagnostics.json");
            Directory.CreateDirectory(Path.GetDirectoryName(report));
            File.Delete(report);
            foreach (var fileItem in this.AutoTypes)
            {
                string autoTypesFileName = fileItem.ItemSpec;
                if (!File.Exists(autoTypesFileName))
                {
                    if (string.Equals(fileItem.GetMetadata("IsImplicitDefault"), "true", StringComparison.OrdinalIgnoreCase))
                        continue;
                    validation.Add(new InvalidDataException("Missing auto-types input."),
                        "WMG004", "PrepSettingsForAutoTypes", autoTypesFileName);
                    continue;
                }

                AutoType[] autoTypes;
                try
                {
                    autoTypes = Newtonsoft.Json.JsonConvert.DeserializeObject<AutoType[]>(File.ReadAllText(autoTypesFileName));
                    if (autoTypes == null || Array.Exists(autoTypes, type => type == null))
                        throw new Newtonsoft.Json.JsonSerializationException("Expected an array of non-null auto-type declarations.");
                }
                catch (Newtonsoft.Json.JsonException error)
                {
                    validation.Add(error, "WMG004", "PrepSettingsForAutoTypes", autoTypesFileName);
                    continue;
                }
                foreach (var autoType in autoTypes)
                {
                    var type = autoType.ValueType;
                    if (string.IsNullOrWhiteSpace(type) || string.IsNullOrWhiteSpace(autoType.Name))
                    {
                        validation.Add(new InvalidDataException("Auto-type declarations require Name and ValueType."),
                            "WMG004", "PrepSettingsForAutoTypes", autoTypesFileName, autoType.Name);
                        continue;
                    }
                    if (type == "DECLARE_HANDLE" || type == "DECLARE_OPAQUE_KEY")
                    {
                        var typeName = autoType.Name;
                        var handleStructName = typeName + "__";
                        var nativeType = type == "DECLARE_HANDLE" ? "IntPtr" : "long";
                        typesToExclude.Add(handleStructName);

                        remapSection.AppendLine($"{typeName}={nativeType}");
                        remapSection.AppendLine($"P{typeName}={typeName}*");
                        remapSection.AppendLine($"LP{typeName}={typeName}*");
                        remapSection.AppendLine($"{handleStructName}*={typeName}");
                    }
                    else if (type == "AllJoynHandle")
                    {
                        var typeName = autoType.Name;
                        var handleStructName = "_" + typeName + "_handle";
                        typesToExclude.Add(handleStructName);

                        remapSection.AppendLine($"{typeName}=IntPtr");
                        remapSection.AppendLine($"{handleStructName}*={typeName}");
                    }
                    else if (type.StartsWith("typedef struct"))
                    {
                        var typeName = autoType.Name;
                        var handleStructName = type[15..];
                        typesToExclude.Add(handleStructName);

                        if (typeName != handleStructName && !remapSection.ToString().Contains($"{handleStructName}=IntPtr"))
                        {
                            remapSection.AppendLine($"{handleStructName}=IntPtr");
                            remapSection.AppendLine($"P{typeName}={typeName}*");
                        }
                    }
                }
            }

            Directory.CreateDirectory(Path.GetDirectoryName(this.ScraperAutoTypesRsp));
            if (validation.HasErrors)
            {
                File.Delete(this.ScraperAutoTypesRsp);
                validation.Block("ScrapeHeaders;ScrapeConstants;EmitWinmd;default tests", "valid auto-type settings");
                validation.WriteReport(report);
                this.Log.LogError(validation.Format());
                return false;
            }
            if (this.PreflightOnly)
                return true;
            using StreamWriter writer = new StreamWriter(this.ScraperAutoTypesRsp);
            if (remapSection.Length != 0)
            {
                writer.WriteLine("--remap");
                writer.Write(remapSection.ToString());
            }

            if (typesToExclude.Count != 0)
            {
                writer.WriteLine("--exclude");
                foreach (var item in typesToExclude)
                {
                    writer.WriteLine(item);
                }
            }

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

        private class AutoType
        {
            public string Namespace { get; set; }
            public string Name { get; set; }
            public string ValueType { get; set; }
            public string CloseApi { get; set; }
            public string AlsoUsableFor { get; set; }
        }
    }
}
