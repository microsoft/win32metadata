using System;
using System.Collections.Generic;
using System.IO;
using System.Reflection.Metadata;
using System.Reflection.PortableExecutable;
using System.Threading.Tasks;
using ICSharpCode.Decompiler.Metadata;

namespace MetadataUtils
{
    public sealed class WinmdAssemblyResolver : IAssemblyResolver, IDisposable
    {
        private readonly string directory;
        private readonly UniversalAssemblyResolver fallback;
        private readonly Dictionary<string, PEFile> files = new Dictionary<string, PEFile>(StringComparer.OrdinalIgnoreCase);

        public WinmdAssemblyResolver(string primaryPath, string targetFramework)
        {
            this.directory = Path.GetDirectoryName(primaryPath);
            this.fallback = new UniversalAssemblyResolver(primaryPath, false, targetFramework);
        }

        public PEFile Resolve(IAssemblyReference reference)
        {
            if (!reference.Name.EndsWith(".winmd", StringComparison.OrdinalIgnoreCase))
            {
                return this.fallback.Resolve(reference);
            }

            if (Path.GetFileName(reference.Name) != reference.Name)
            {
                throw new InvalidOperationException($"Invalid metadata identity '{reference.Name}'.");
            }

            string path = Path.Combine(this.directory, reference.Name);
            if (!this.files.TryGetValue(path, out var file))
            {
                file = new PEFile(path, PEStreamOptions.PrefetchEntireImage, MetadataReaderOptions.None);
                this.files.Add(path, file);
            }

            var definition = file.Metadata.GetAssemblyDefinition();
            if (file.Metadata.GetString(definition.Name) != reference.Name || definition.Version != reference.Version ||
                file.Metadata.GetString(definition.Culture) != (reference.Culture ?? string.Empty) ||
                !file.Metadata.GetBlobBytes(definition.PublicKey).AsSpan().SequenceEqual(reference.PublicKeyToken ?? Array.Empty<byte>()))
            {
                throw new InvalidOperationException($"Referenced metadata identity mismatch: '{path}'.");
            }

            return file;
        }

        public PEFile ResolveModule(PEFile mainModule, string moduleName) => this.fallback.ResolveModule(mainModule, moduleName);

        public Task<PEFile> ResolveAsync(IAssemblyReference reference) => Task.FromResult(this.Resolve(reference));

        public Task<PEFile> ResolveModuleAsync(PEFile mainModule, string moduleName) => Task.FromResult(this.ResolveModule(mainModule, moduleName));

        public void Dispose()
        {
            foreach (var file in this.files.Values)
            {
                file.Dispose();
            }
        }
    }
}
