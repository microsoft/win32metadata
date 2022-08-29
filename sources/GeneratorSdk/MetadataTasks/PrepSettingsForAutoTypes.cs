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
            foreach (var fileItem in this.AutoTypes)
            {
                string autoTypesFileName = fileItem.ItemSpec;
                if (!File.Exists(autoTypesFileName))
                {
                    continue;
                }

                var autoTypes = Newtonsoft.Json.JsonConvert.DeserializeObject<AutoType[]>(File.ReadAllText(autoTypesFileName));
                foreach (var autoType in autoTypes)
                {
                    var type = autoType.ValueType;
                    if (type == "DECLARE_HANDLE" || type == "DECLARE_OPAQUE_KEY")
                    {
                        var typeName = autoType.Name;
                        var handleStructName = typeName + "__";
                        var nativeType = type == "DECLARE_HANDLE" ? "IntPtr" : "long";
                        typesToExclude.Add(handleStructName);

                        remapSection.AppendLine($"{typeName}={nativeType}");
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
                }
            }

            Directory.CreateDirectory(Path.GetDirectoryName(this.ScraperAutoTypesRsp));
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
