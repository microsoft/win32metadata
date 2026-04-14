using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using ClangSharp;
using ClangSharp.Interop;
using Win32MetadataScraper;

namespace Win32MetadataScraperTests
{
    /// <summary>
    /// Parses a C/C++ header snippet using ClangSharp and returns the AST discovery results.
    /// Handles temp file creation/cleanup and native library loading.
    /// </summary>
    public static class HeaderSnippetParser
    {

        /// <summary>
        /// Ensures native libraries are available. With RuntimeIdentifiers set in the
        /// project, the .NET host resolves libclang/libClangSharp from the NuGet cache
        /// at execution time — no manual loading needed.
        /// </summary>
        public static void EnsureNativeLibsLoaded()
        {
            // Native libs are resolved automatically by the .NET host via deps.json
            // and the NuGet runtime package graph. No manual loading required.
        }

        /// <summary>
        /// Parses a C header snippet and returns the AST discovery results.
        /// </summary>
        public static DiscoveryResult ParseAndDiscover(string headerContent)
        {
            return ParseAndDiscover(new Dictionary<string, string> { ["test.h"] = headerContent }, "#include \"test.h\"\n");
        }

        /// <summary>
        /// Parses multiple header files with a custom main source and returns discovery results.
        /// </summary>
        public static DiscoveryResult ParseAndDiscover(Dictionary<string, string> files, string mainSource)
        {
            EnsureNativeLibsLoaded();

            string tempDir = Path.Combine(Path.GetTempPath(), $"scraper-test-{Guid.NewGuid():N}");
            Directory.CreateDirectory(tempDir);

            try
            {
                foreach (var kv in files)
                    File.WriteAllText(Path.Combine(tempDir, kv.Key), kv.Value);

                string sourceFile = Path.Combine(tempDir, "test.cpp");
                File.WriteAllText(sourceFile, mainSource);

                var clangArgs = new string[]
                {
                    "--language=c++",
                    "--std=c++17",
                    $"--include-directory={tempDir}",
                    "-Wno-pragma-once-outside-header"
                };

                var flags = CXTranslationUnit_Flags.CXTranslationUnit_IncludeAttributedTypes
                          | CXTranslationUnit_Flags.CXTranslationUnit_VisitImplicitAttributes;

                using var index = CXIndex.Create(excludeDeclarationsFromPch: false, displayDiagnostics: false);
                var error = CXTranslationUnit.TryParse(
                    index, sourceFile, clangArgs, ReadOnlySpan<CXUnsavedFile>.Empty, flags, out var handle);

                if (error != CXErrorCode.CXError_Success)
                    throw new InvalidOperationException($"Failed to parse: {error}");

                // Check for fatal errors
                for (uint i = 0; i < handle.NumDiagnostics; i++)
                {
                    using var diag = handle.GetDiagnostic(i);
                    if (diag.Severity == CXDiagnosticSeverity.CXDiagnostic_Error ||
                        diag.Severity == CXDiagnosticSeverity.CXDiagnostic_Fatal)
                    {
                        throw new InvalidOperationException(
                            $"Parse error: {diag.Format(CXDiagnostic.DefaultDisplayOptions)}");
                    }
                }

                using var tu = TranslationUnit.GetOrCreate(handle);
                Debug.Assert(tu is not null);

                return RemapDiscovery.WalkTranslationUnit(tu.TranslationUnitDecl);
            }
            finally
            {
                try { Directory.Delete(tempDir, true); } catch { }
            }
        }

        /// <summary>
        /// Convenience: parse, discover, resolve tag remaps, and filter — all in one call.
        /// Returns the final auto-remap dictionary.
        /// </summary>
        public static Dictionary<string, string> ParseAndResolveTagRemaps(
            string headerContent,
            Dictionary<string, string> configuredRemaps = null)
        {
            configuredRemaps ??= new Dictionary<string, string>();
            var discovery = ParseAndDiscover(headerContent);
            var resolved = RemapDiscovery.ResolveTagRemaps(discovery.TagToTypedefs, configuredRemaps);
            return RemapDiscovery.FilterTagRemaps(resolved, configuredRemaps, discovery.EnumTags);
        }

        /// <summary>
        /// Convenience: parse, discover, and resolve function pointer fixups.
        /// </summary>
        public static ResolvedRemaps ParseAndResolveFnPtrFixups(
            string headerContent,
            IEnumerable<string> configuredExcludes = null)
        {
            var discovery = ParseAndDiscover(headerContent);
            var excludeSet = configuredExcludes is null
                ? null
                : new HashSet<string>(configuredExcludes, StringComparer.Ordinal);
            return RemapDiscovery.ResolveFunctionPointerFixups(discovery, excludeSet);
        }
    }
}
