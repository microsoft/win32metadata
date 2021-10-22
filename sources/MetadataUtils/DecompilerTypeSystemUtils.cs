using System.IO;
using System.Reflection.Metadata;
using System.Reflection.PortableExecutable;
using ICSharpCode.Decompiler;
using ICSharpCode.Decompiler.Metadata;
using ICSharpCode.Decompiler.TypeSystem;

namespace MetadataUtils
{
    public static class DecompilerTypeSystemUtils
    {
        public static DecompilerTypeSystem CreateTypeSystemFromFile(string fileName)
        {
            return CreateTypeSystemFromFile(fileName, new DecompilerSettings() { ThrowOnAssemblyResolveErrors = false });
        }

        public static DecompilerTypeSystem CreateTypeSystemFromFile(string fileName, DecompilerSettings settings)
        {
            settings.LoadInMemory = true;
            var file = LoadPEFile(fileName, settings);
            var resolver = new UniversalAssemblyResolver(fileName, settings.ThrowOnAssemblyResolveErrors, file.DetectTargetFrameworkId());
            return new DecompilerTypeSystem(file, resolver);
        }

        private static PEFile LoadPEFile(string fileName, DecompilerSettings settings)
        {
            settings.LoadInMemory = true;
            return new PEFile(
                fileName,
                new FileStream(fileName, FileMode.Open, FileAccess.Read),
                streamOptions: PEStreamOptions.PrefetchEntireImage,
                metadataOptions: settings.ApplyWindowsRuntimeProjections ? MetadataReaderOptions.ApplyWindowsRuntimeProjections : MetadataReaderOptions.None
            );
        }
    }
}
