using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection.Metadata;
using System.Reflection.PortableExecutable;
using System.Text;
using System.Threading.Tasks;
using ICSharpCode.Decompiler;
using ICSharpCode.Decompiler.Metadata;
using ICSharpCode.Decompiler.TypeSystem;

namespace MetadataUtils
{
    public static class DecompilerUtils
    {
        public static DecompilerTypeSystem LoadDecompilerTypeSystem(string winmdFileName)
        {
            DecompilerSettings settings = new DecompilerSettings() { ThrowOnAssemblyResolveErrors = false };
            return CreateTypeSystemFromFile(winmdFileName, settings);
        }

        public static IEnumerable<ITypeDefinition> GetSelfDefinedWinmdToplevelTypes(DecompilerTypeSystem winmd)
        {
            return winmd.GetTopLevelTypeDefinitions().Where(
                type => type.ParentModule == winmd.MainModule && type.FullName != "<Module>");
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

        private static DecompilerTypeSystem CreateTypeSystemFromFile(string fileName, DecompilerSettings settings)
        {
            settings.LoadInMemory = true;
            var file = LoadPEFile(fileName, settings);
            var resolver = new UniversalAssemblyResolver(fileName, settings.ThrowOnAssemblyResolveErrors, file.DetectTargetFrameworkId());
            return new DecompilerTypeSystem(file, resolver);
        }
    }
}
