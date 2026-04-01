using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Runtime.InteropServices;
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
        private static bool s_nativeLibsLoaded;
        private static readonly object s_lock = new();

        /// <summary>
        /// Ensures libclang and libClangSharp native libraries are loaded.
        /// Uses the ClangSharp tool store if available, otherwise relies on NuGet runtime assets.
        /// </summary>
        public static void EnsureNativeLibsLoaded()
        {
            lock (s_lock)
            {
                if (s_nativeLibsLoaded) return;

                // Try the dotnet tool store first (same as ScrapeHeaders.cs)
                string userProfile = Environment.GetFolderPath(Environment.SpecialFolder.UserProfile);
                string storeRoot = Path.Combine(userProfile, ".dotnet", "tools", ".store", "clangsharppinvokegenerator");
                if (Directory.Exists(storeRoot))
                {
                    var found = Directory.GetFiles(storeRoot, "libclang.dll", SearchOption.AllDirectories);
                    if (found.Length > 0)
                    {
                        string toolDir = Path.GetDirectoryName(found[0]);
                        NativeLibrary.Load(Path.Combine(toolDir, "libclang.dll"));
                        NativeLibrary.Load(Path.Combine(toolDir, "libClangSharp.dll"));
                        s_nativeLibsLoaded = true;
                        return;
                    }
                }

                // Fall back to NuGet runtime assets (should be in the output directory)
                s_nativeLibsLoaded = true; // let it fail naturally if not found
            }
        }

        /// <summary>
        /// Parses a C header snippet and returns the AST discovery results.
        /// </summary>
        /// <param name="headerContent">The C/C++ header content to parse.</param>
        /// <returns>Discovery results with tag-typedef and fn-ptr relationships.</returns>
        public static DiscoveryResult ParseAndDiscover(string headerContent)
        {
            EnsureNativeLibsLoaded();

            string tempDir = Path.Combine(Path.GetTempPath(), $"scraper-test-{Guid.NewGuid():N}");
            Directory.CreateDirectory(tempDir);

            try
            {
                string headerFile = Path.Combine(tempDir, "test.h");
                string sourceFile = Path.Combine(tempDir, "test.cpp");

                File.WriteAllText(headerFile, headerContent);
                File.WriteAllText(sourceFile, "#include \"test.h\"\n");

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
            return RemapDiscovery.FilterTagRemaps(resolved, configuredRemaps);
        }

        /// <summary>
        /// Convenience: parse, discover, and resolve function pointer fixups.
        /// </summary>
        public static ResolvedRemaps ParseAndResolveFnPtrFixups(string headerContent)
        {
            var discovery = ParseAndDiscover(headerContent);
            return RemapDiscovery.ResolveFunctionPointerFixups(
                discovery.FnProtoTypedefNames, discovery.FnProtoToPointerTypedefs);
        }
    }
}
