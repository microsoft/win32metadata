using Microsoft.Build.Framework;
using Microsoft.Build.Utilities;

namespace MetadataTasks
{
    public class SelectNativeConstantToolchainHeaders : Task
    {
        [Required]
        public string ScriptsDir { get; set; }

        [Output]
        public string[] ToolchainIncludeRoots { get; set; }

        public override bool Execute()
        {
            if (!TaskUtils.TrySelectNativeConstantToolchainHeaders(this.ScriptsDir, this.ToolchainIncludeRoots,
                this.Log, out var roots))
                return false;
            this.ToolchainIncludeRoots = roots;
            return true;
        }
    }
}
