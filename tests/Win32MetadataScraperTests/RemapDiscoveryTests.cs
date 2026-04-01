using System.Collections.Generic;
using Xunit;

namespace Win32MetadataScraperTests
{
    /// <summary>
    /// Tests for tag-typedef remap discovery heuristics.
    /// Each test uses a minimal C header snippet that mirrors a real SDK pattern.
    /// </summary>
    public class TagTypedefDiscoveryTests
    {
        // ── Simple tag-typedef patterns ──────────────────────────────────────

        [Fact]
        public void UnderscoreUppercase_DiscoversSingleTypedef()
        {
            // Pattern: typedef struct _FOO { ... } FOO;
            // e.g., typedef struct _RECT { LONG left; ... } RECT;
            var remaps = HeaderSnippetParser.ParseAndResolveTagRemaps(@"
                typedef struct _RECT {
                    long left;
                    long top;
                    long right;
                    long bottom;
                } RECT;
            ");

            Assert.True(remaps.ContainsKey("_RECT"));
            Assert.Equal("RECT", remaps["_RECT"]);
        }

        [Fact]
        public void UnderscoreLowercase_DiscoversSingleTypedef()
        {
            // Pattern: typedef struct _cpinfo { ... } CPINFO;
            // Real SDK: winnls.h — _cpinfo → CPINFO
            var remaps = HeaderSnippetParser.ParseAndResolveTagRemaps(@"
                typedef struct _cpinfo {
                    unsigned int MaxCharSize;
                    unsigned char DefaultChar[2];
                    unsigned char LeadByte[12];
                } CPINFO;
            ");

            Assert.True(remaps.ContainsKey("_cpinfo"));
            Assert.Equal("CPINFO", remaps["_cpinfo"]);
        }

        [Fact]
        public void TagPrefix_DiscoversSingleTypedef()
        {
            // Pattern: typedef struct tagFOO { ... } FOO;
            // Real SDK: wingdi.h — tagBITMAP → BITMAP
            var remaps = HeaderSnippetParser.ParseAndResolveTagRemaps(@"
                typedef struct tagBITMAP {
                    int bmType;
                    int bmWidth;
                    int bmHeight;
                } BITMAP;
            ");

            Assert.True(remaps.ContainsKey("tagBITMAP"));
            Assert.Equal("BITMAP", remaps["tagBITMAP"]);
        }

        [Fact]
        public void LowercaseTag_DiscoversSingleTypedef()
        {
            // Pattern: typedef struct waveformat_tag { ... } WAVEFORMAT;
            // Real SDK: mmreg.h — waveformat_tag → WAVEFORMAT
            var remaps = HeaderSnippetParser.ParseAndResolveTagRemaps(@"
                typedef struct waveformat_tag {
                    unsigned short wFormatTag;
                    unsigned short nChannels;
                    unsigned long  nSamplesPerSec;
                } WAVEFORMAT;
            ");

            Assert.True(remaps.ContainsKey("waveformat_tag"));
            Assert.Equal("WAVEFORMAT", remaps["waveformat_tag"]);
        }

        [Fact]
        public void TrailingUnderscore_DiscoversSingleTypedef()
        {
            // Pattern: typedef struct FOO_ { ... } FOO;
            // Real SDK: CONFIG_CI_PROV_INFO_ → CONFIG_CI_PROV_INFO
            var remaps = HeaderSnippetParser.ParseAndResolveTagRemaps(@"
                typedef struct CONFIG_CI_PROV_INFO_ {
                    unsigned long cbSize;
                } CONFIG_CI_PROV_INFO;
            ");

            Assert.True(remaps.ContainsKey("CONFIG_CI_PROV_INFO_"));
            Assert.Equal("CONFIG_CI_PROV_INFO", remaps["CONFIG_CI_PROV_INFO_"]);
        }

        [Fact]
        public void EnumTypedef_DiscoveredCorrectly()
        {
            // Pattern: typedef enum _FOO { ... } FOO;
            var remaps = HeaderSnippetParser.ParseAndResolveTagRemaps(@"
                typedef enum _PROCESS_DPI_AWARENESS {
                    PROCESS_DPI_UNAWARE = 0,
                    PROCESS_SYSTEM_DPI_AWARE = 1,
                    PROCESS_PER_MONITOR_DPI_AWARE = 2
                } PROCESS_DPI_AWARENESS;
            ");

            Assert.True(remaps.ContainsKey("_PROCESS_DPI_AWARENESS"));
            Assert.Equal("PROCESS_DPI_AWARENESS", remaps["_PROCESS_DPI_AWARENESS"]);
        }

        // ── Multi-typedef disambiguation ─────────────────────────────────────

        [Fact]
        public void MultipleTypedefs_DisambiguatesByStrippingPrefix()
        {
            // Pattern: struct _FOO has both FOO and PFOO typedefs
            // Should pick FOO (stripped _ prefix), not PFOO
            // Real SDK: winnt.h — many types have both direct and pointer typedefs
            var remaps = HeaderSnippetParser.ParseAndResolveTagRemaps(@"
                typedef struct _SECURITY_ATTRIBUTES {
                    unsigned long nLength;
                    void* lpSecurityDescriptor;
                    int bInheritHandle;
                } SECURITY_ATTRIBUTES, *PSECURITY_ATTRIBUTES, *LPSECURITY_ATTRIBUTES;
            ");

            Assert.True(remaps.ContainsKey("_SECURITY_ATTRIBUTES"));
            Assert.Equal("SECURITY_ATTRIBUTES", remaps["_SECURITY_ATTRIBUTES"]);
        }

        [Fact]
        public void MultipleTypedefs_DisambiguatesByCaseInsensitiveMatch()
        {
            // Pattern from in6addr.h: struct in6_addr has typedefs IN6_ADDR and IPv6Addr.
            // The disambiguator should pick IN6_ADDR (case-insensitive match of tag name).
            var files = new Dictionary<string, string>
            {
                ["test.h"] = @"
                    typedef struct in6_addr {
                        unsigned char Byte[16];
                    } IN6_ADDR;
                    typedef struct in6_addr IPv6Addr;
                "
            };

            var discovery = HeaderSnippetParser.ParseAndDiscover(files, "#include \"test.h\"\n");
            var resolved = Win32MetadataScraper.RemapDiscovery.ResolveTagRemaps(
                discovery.TagToTypedefs, new Dictionary<string, string>());

            Assert.True(resolved.ContainsKey("in6_addr"));
            Assert.Equal("IN6_ADDR", resolved["in6_addr"]);
        }

        [Fact]
        public void AmbiguousTypedefs_SkippedWithoutManualHint()
        {
            // When a tag has multiple typedefs and none is the "stripped" version,
            // the heuristic should skip it (conservative)
            var remaps = HeaderSnippetParser.ParseAndResolveTagRemaps(@"
                typedef struct _AMBIGUOUS {
                    int x;
                } ALPHA_NAME, BETA_NAME;
            ");

            // Neither ALPHA_NAME nor BETA_NAME matches _AMBIGUOUS stripped
            Assert.False(remaps.ContainsKey("_AMBIGUOUS"));
        }

        [Fact]
        public void AmbiguousTypedefs_ResolvedByManualHint()
        {
            // When manual config specifies which typedef to use for an ambiguous tag,
            // the heuristic should use that
            var configured = new Dictionary<string, string>
            {
                ["_IMAGE_RUNTIME_FUNCTION_ENTRY"] = "IMAGE_RUNTIME_FUNCTION_ENTRY"
            };

            var remaps = HeaderSnippetParser.ParseAndResolveTagRemaps(@"
                typedef struct _IMAGE_RUNTIME_FUNCTION_ENTRY {
                    unsigned long BeginAddress;
                    unsigned long EndAddress;
                    unsigned long UnwindInfoAddress;
                } IMAGE_RUNTIME_FUNCTION_ENTRY, IMAGE_IA64_RUNTIME_FUNCTION_ENTRY;
            ", configured);

            Assert.True(remaps.ContainsKey("_IMAGE_RUNTIME_FUNCTION_ENTRY"));
            Assert.Equal("IMAGE_RUNTIME_FUNCTION_ENTRY", remaps["_IMAGE_RUNTIME_FUNCTION_ENTRY"]);
        }

        // ── Semantic override protection ─────────────────────────────────────

        [Fact]
        public void SemanticOverride_ManualWins()
        {
            // When manual remap maps to a C# primitive (e.g., _LARGE_INTEGER=long),
            // auto-discovery finds the C typedef but the manual override takes priority
            var configured = new Dictionary<string, string>
            {
                ["_LARGE_INTEGER"] = "long"
            };

            var remaps = HeaderSnippetParser.ParseAndResolveTagRemaps(@"
                typedef union _LARGE_INTEGER {
                    struct {
                        unsigned long LowPart;
                        long HighPart;
                    };
                    long long QuadPart;
                } LARGE_INTEGER;
            ", configured);

            // Auto-discovers _LARGE_INTEGER=LARGE_INTEGER, but filter skips it
            // because configured says _LARGE_INTEGER=long (different value)
            Assert.False(remaps.ContainsKey("_LARGE_INTEGER"));
        }

        // ── C++ namespace types skipped ──────────────────────────────────────

        [Fact]
        public void CppNamespaceTypes_NotRemapped()
        {
            // Types inside C++ namespaces (like Gdiplus::Status) should not be
            // auto-remapped — PInvokeGenerator handles these internally.
            // Pattern from gdiplusenums.h / gdiplusgpstubs.h
            var remaps = HeaderSnippetParser.ParseAndResolveTagRemaps(@"
                namespace Gdiplus {
                    enum Status { Ok = 0, GenericError = 1 };
                    typedef Status GpStatus;
                    enum FillMode { FillModeAlternate = 0 };
                    typedef FillMode GpFillMode;
                }
            ");

            Assert.False(remaps.ContainsKey("Status"));
            Assert.False(remaps.ContainsKey("Gdiplus::Status"));
            Assert.False(remaps.ContainsKey("FillMode"));
            Assert.False(remaps.ContainsKey("Gdiplus::FillMode"));
        }

        // ── Built-in type filtering ──────────────────────────────────────────

        [Fact]
        public void BuiltinTypes_NotRemapped()
        {
            var remaps = HeaderSnippetParser.ParseAndResolveTagRemaps(@"
                typedef struct _GUID {
                    unsigned long  Data1;
                    unsigned short Data2;
                    unsigned short Data3;
                    unsigned char  Data4[8];
                } GUID;
            ");

            // _GUID is a built-in default that should be filtered out
            Assert.False(remaps.ContainsKey("_GUID"));
        }

        // ── Identity remap filtering ─────────────────────────────────────────

        [Fact]
        public void IdentityRemap_Filtered()
        {
            // When tag name equals typedef name, no remap needed
            var discovery = HeaderSnippetParser.ParseAndDiscover(@"
                typedef struct ALREADY_NAMED {
                    int x;
                } ALREADY_NAMED;
            ");

            // The tag and typedef are the same — should not appear in remaps
            var resolved = Win32MetadataScraper.RemapDiscovery.ResolveTagRemaps(
                discovery.TagToTypedefs, new Dictionary<string, string>());
            Assert.False(resolved.ContainsKey("ALREADY_NAMED"));
        }

        [Fact]
        public void SuffixAdding_Filtered()
        {
            // When the typedef adds a suffix to the tag name (e.g., GLUnurbs→GLUnurbsObj),
            // the tag name is the canonical name used in function signatures.
            // The remap should be filtered out.
            var remaps = HeaderSnippetParser.ParseAndResolveTagRemaps(@"
                typedef struct GLUnurbs GLUnurbsObj;
            ");

            Assert.False(remaps.ContainsKey("GLUnurbs"));
        }

        // ── Transitive include discovery ─────────────────────────────────────

        [Fact]
        public void TransitiveInclude_TypedefDiscoveredAcrossHeaders()
        {
            // Pattern from in6addr.h / ws2ipdef.h:
            // Header A defines: typedef struct in6_addr { ... } IN6_ADDR;
            // Header B includes Header A and uses: struct in6_addr *addr;
            // Main.cpp includes Header B.
            // The typedef should be discovered even though it's in a transitively
            // included header, not the directly included one.
            var files = new Dictionary<string, string>
            {
                ["inner.h"] = @"
                    typedef struct in6_addr {
                        unsigned char Byte[16];
                    } IN6_ADDR;
                ",
                ["outer.h"] = @"
                    #include ""inner.h""
                    typedef struct _SOME_STRUCT {
                        struct in6_addr addr;
                    } SOME_STRUCT;
                "
            };

            var discovery = HeaderSnippetParser.ParseAndDiscover(files, "#include \"outer.h\"\n");
            var resolved = Win32MetadataScraper.RemapDiscovery.ResolveTagRemaps(
                discovery.TagToTypedefs, new Dictionary<string, string>());
            var filtered = Win32MetadataScraper.RemapDiscovery.FilterTagRemaps(
                resolved, new Dictionary<string, string>());

            Assert.True(filtered.ContainsKey("in6_addr"), 
                "in6_addr remap should be discovered from transitively included header");
            Assert.Equal("IN6_ADDR", filtered["in6_addr"]);
        }

        [Fact]
        public void TransitiveInclude_WithIncludeGuardStillDiscovered()
        {
            // Reproduce the in6addr.h pattern: the typedef is guarded by
            // #ifndef s6_addr, and s6_addr is #defined WITHIN the same header
            // after the typedef. The typedef should still be visible.
            var files = new Dictionary<string, string>
            {
                ["guarded.h"] = @"
                    #ifndef s6_addr
                    #pragma once
                    typedef struct in6_addr {
                        union {
                            unsigned char Byte[16];
                            unsigned short Word[8];
                        } u;
                    } IN6_ADDR;
                    #define s6_addr u.Byte
                    #endif
                ",
                ["consumer.h"] = @"
                    #include ""guarded.h""
                    typedef struct _USES_ADDR {
                        struct in6_addr addr;
                    } USES_ADDR;
                "
            };

            var discovery = HeaderSnippetParser.ParseAndDiscover(files, "#include \"consumer.h\"\n");
            var resolved = Win32MetadataScraper.RemapDiscovery.ResolveTagRemaps(
                discovery.TagToTypedefs, new Dictionary<string, string>());
            var filtered = Win32MetadataScraper.RemapDiscovery.FilterTagRemaps(
                resolved, new Dictionary<string, string>());

            Assert.True(filtered.ContainsKey("in6_addr"),
                "in6_addr remap should be discovered even with include guard");
        }

        [Fact]
        public void TransitiveInclude_MultipleTypedefsSameTag()
        {
            // Pattern: struct has both IN6_ADDR and *PIN6_ADDR typedefs.
            // Multiple typedefs for same tag — disambiguator should pick IN6_ADDR.
            var files = new Dictionary<string, string>
            {
                ["types.h"] = @"
                    typedef struct in6_addr {
                        unsigned char Byte[16];
                    } IN6_ADDR, *PIN6_ADDR;
                ",
                ["user.h"] = @"
                    #include ""types.h""
                    void do_something(IN6_ADDR* addr);
                "
            };

            var discovery = HeaderSnippetParser.ParseAndDiscover(files, "#include \"user.h\"\n");

            // Should find in6_addr with multiple typedefs
            Assert.True(discovery.TagToTypedefs.ContainsKey("in6_addr"));

            var resolved = Win32MetadataScraper.RemapDiscovery.ResolveTagRemaps(
                discovery.TagToTypedefs, new Dictionary<string, string>());
            var filtered = Win32MetadataScraper.RemapDiscovery.FilterTagRemaps(
                resolved, new Dictionary<string, string>());

            // Should pick IN6_ADDR (not PIN6_ADDR) since it strips the prefix
            Assert.True(filtered.ContainsKey("in6_addr"));
            Assert.Equal("IN6_ADDR", filtered["in6_addr"]);
        }
    }

    /// <summary>
    /// Tests for function pointer typedef pair discovery.
    /// </summary>
    public class FunctionPointerDiscoveryTests
    {
        // ── Two-step function pointer pattern ────────────────────────────────

        [Fact]
        public void TwoStepFnPtr_PrototypeAndPointerTypedef()
        {
            // Pattern from mmiscapi2.h:
            //   typedef void (CALLBACK TIMECALLBACK)(UINT, UINT, ...);
            //   typedef TIMECALLBACK *LPTIMECALLBACK;
            // Simplified for standalone compilation:
            var result = HeaderSnippetParser.ParseAndResolveFnPtrFixups(@"
                typedef void TIMECALLBACK(unsigned int uTimerID, unsigned int uMsg);
                typedef TIMECALLBACK *LPTIMECALLBACK;
            ");

            Assert.True(result.FnPtrRemaps.ContainsKey("TIMECALLBACK"));
            Assert.Equal("LPTIMECALLBACK", result.FnPtrRemaps["TIMECALLBACK"]);
            Assert.Contains("LPTIMECALLBACK", result.FnPtrExcludes);
            Assert.Contains("LPTIMECALLBACK", result.ReducePointerLevel);
        }

        [Fact]
        public void TwoStepFnPtr_PPrefix()
        {
            // Pattern from winnt.h:
            //   typedef VOID TP_WORK_CALLBACK(PTP_CALLBACK_INSTANCE, PVOID, PTP_WORK);
            //   typedef TP_WORK_CALLBACK *PTP_WORK_CALLBACK;
            var result = HeaderSnippetParser.ParseAndResolveFnPtrFixups(@"
                typedef void TP_WORK_CALLBACK(void* Instance, void* Context, void* Work);
                typedef TP_WORK_CALLBACK *PTP_WORK_CALLBACK;
            ");

            Assert.True(result.FnPtrRemaps.ContainsKey("TP_WORK_CALLBACK"));
            Assert.Equal("PTP_WORK_CALLBACK", result.FnPtrRemaps["TP_WORK_CALLBACK"]);
        }

        [Fact]
        public void TwoStepFnPtr_PFNPrefix()
        {
            // Pattern: typedef RPCNOTIFICATION_ROUTINE *PFN_RPCNOTIFICATION_ROUTINE;
            var result = HeaderSnippetParser.ParseAndResolveFnPtrFixups(@"
                typedef void RPCNOTIFICATION_ROUTINE(void* pAsync, void* Context, int Event);
                typedef RPCNOTIFICATION_ROUTINE *PFN_RPCNOTIFICATION_ROUTINE;
            ");

            Assert.True(result.FnPtrRemaps.ContainsKey("RPCNOTIFICATION_ROUTINE"));
            Assert.Equal("PFN_RPCNOTIFICATION_ROUTINE", result.FnPtrRemaps["RPCNOTIFICATION_ROUTINE"]);
        }

        // ── Direct pointer-to-function typedef ───────────────────────────────

        [Fact]
        public void DirectFnPtr_NoPrototypeSeparation()
        {
            // Pattern from commdlg.h:
            //   typedef unsigned int (*LPOFNHOOKPROC)(void*, unsigned int, ...);
            // No separate prototype typedef — just the pointer typedef directly
            var result = HeaderSnippetParser.ParseAndResolveFnPtrFixups(@"
                typedef unsigned int (*LPOFNHOOKPROC)(void* hdlg, unsigned int msg, void* wParam, void* lParam);
            ");

            // Should be recognized as a function pointer typedef
            var discovery = HeaderSnippetParser.ParseAndDiscover(@"
                typedef unsigned int (*LPOFNHOOKPROC)(void* hdlg, unsigned int msg, void* wParam, void* lParam);
            ");
            Assert.Contains("LPOFNHOOKPROC", discovery.FnProtoTypedefNames);

            // But no pair to resolve — no remap generated
            Assert.Empty(result.FnPtrRemaps);
        }

        // ── Calling convention (AttributedType) ──────────────────────────────

        [Fact]
        public void FnPtr_WithCallingConvention()
        {
            // Pattern: typedef void (__stdcall CALLBACK_FN)(int x);
            //          typedef CALLBACK_FN *PCALLBACK_FN;
            // The __stdcall creates an AttributedType wrapper
            var result = HeaderSnippetParser.ParseAndResolveFnPtrFixups(@"
                typedef void (__stdcall CALLBACK_FN)(int x);
                typedef CALLBACK_FN *PCALLBACK_FN;
            ");

            Assert.True(result.FnPtrRemaps.ContainsKey("CALLBACK_FN"));
            Assert.Equal("PCALLBACK_FN", result.FnPtrRemaps["CALLBACK_FN"]);
        }

        // ── Non-standard naming skipped ──────────────────────────────────────

        [Fact]
        public void FnPtr_NonStandardPointerName_Skipped()
        {
            // When the pointer typedef doesn't start with P/LP/PFN,
            // the heuristic should skip it (conservative)
            var result = HeaderSnippetParser.ParseAndResolveFnPtrFixups(@"
                typedef void MY_CALLBACK(int x);
                typedef MY_CALLBACK *MY_CALLBACK_HANDLER;
            ");

            // MY_CALLBACK_HANDLER doesn't start with P/LP/PFN — skipped
            Assert.Empty(result.FnPtrRemaps);
        }

        // ── Typedef-to-typedef alias pattern ─────────────────────────────────

        [Fact]
        public void FnPtr_TypedefAlias()
        {
            // Pattern from minwinbase.h:
            //   typedef DWORD (*PTHREAD_START_ROUTINE)(LPVOID);
            //   typedef PTHREAD_START_ROUTINE LPTHREAD_START_ROUTINE;
            // PTHREAD_START_ROUTINE is already a function pointer (not a prototype)
            // LPTHREAD_START_ROUTINE is a typedef alias (not a pointer-to-typedef)
            var discovery = HeaderSnippetParser.ParseAndDiscover(@"
                typedef unsigned long (*PTHREAD_START_ROUTINE)(void* lpThreadParameter);
                typedef PTHREAD_START_ROUTINE LPTHREAD_START_ROUTINE;
            ");

            // PTHREAD_START_ROUTINE is a fn ptr typedef
            Assert.Contains("PTHREAD_START_ROUTINE", discovery.FnProtoTypedefNames);
            // LPTHREAD_START_ROUTINE references PTHREAD_START_ROUTINE
            Assert.True(discovery.FnProtoToPointerTypedefs.ContainsKey("PTHREAD_START_ROUTINE"));
            Assert.Contains("LPTHREAD_START_ROUTINE", discovery.FnProtoToPointerTypedefs["PTHREAD_START_ROUTINE"]);
        }

        // ── Ambiguous pointer targets skipped ────────────────────────────────

        [Fact]
        public void FnPtr_AlreadyPointer_AliasRemappedToPointerName()
        {
            // Pattern from winnt.h:
            //   typedef DWORD (*PEXCEPTION_ROUTINE)(...);   // already a fn pointer
            //   typedef PEXCEPTION_ROUTINE EXCEPTION_ROUTINE;  // non-pointer alias
            // The alias (EXCEPTION_ROUTINE, no P/LP prefix) should be remapped TO
            // the pointer name (PEXCEPTION_ROUTINE), not the other way around.
            var result = HeaderSnippetParser.ParseAndResolveFnPtrFixups(@"
                typedef unsigned long (*PEXCEPTION_ROUTINE)(void* EstablisherFrame, unsigned long long DispatcherContext);
                typedef PEXCEPTION_ROUTINE EXCEPTION_ROUTINE;
            ");

            // The remap should be alias→pointer, not pointer→alias
            Assert.True(result.FnPtrRemaps.ContainsKey("EXCEPTION_ROUTINE"));
            Assert.Equal("PEXCEPTION_ROUTINE", result.FnPtrRemaps["EXCEPTION_ROUTINE"]);
            Assert.Contains("PEXCEPTION_ROUTINE", result.FnPtrExcludes);
        }

        [Fact]
        public void FnPtr_BothHavePointerPrefix_Skipped()
        {
            // When both names have P/LP prefixes, we can't determine the direction
            // by naming convention alone — skip (leave for manual fixups).
            var result = HeaderSnippetParser.ParseAndResolveFnPtrFixups(@"
                typedef unsigned long (*LPTHREAD_START_ROUTINE)(void* lpThreadParameter);
                typedef LPTHREAD_START_ROUTINE PTHREAD_START_ROUTINE;
            ");

            Assert.Empty(result.FnPtrRemaps);
        }

        [Fact]
        public void FnPtr_MultiplePointerNames_Skipped()
        {
            // If a prototype has multiple pointer aliases, skip (ambiguous)
            var result = HeaderSnippetParser.ParseAndResolveFnPtrFixups(@"
                typedef void MY_FUNC(int x);
                typedef MY_FUNC *PMY_FUNC;
                typedef MY_FUNC *LPMY_FUNC;
            ");

            // Two pointer aliases — ambiguous, should skip
            Assert.Empty(result.FnPtrRemaps);
        }
    }

    /// <summary>
    /// Tests for the UnwrapType helper that peels sugar types.
    /// </summary>
    public class UnwrapTypeTests
    {
        [Fact]
        public void ElaboratedType_UnwrappedCorrectly()
        {
            // typedef struct _FOO { int x; } FOO; creates ElaboratedType → RecordType
            var discovery = HeaderSnippetParser.ParseAndDiscover(@"
                typedef struct _FOO { int x; } FOO;
            ");

            Assert.True(discovery.TagToTypedefs.ContainsKey("_FOO"));
        }

        [Fact]
        public void AttributedType_UnwrappedForFnPtr()
        {
            // __stdcall creates AttributedType wrapping FunctionProtoType
            var discovery = HeaderSnippetParser.ParseAndDiscover(@"
                typedef void (__stdcall MY_CALLBACK)(int x);
            ");

            Assert.Contains("MY_CALLBACK", discovery.FnProtoTypedefNames);
        }
    }
}
