# Auto-Derive Typedef-Tag Remappings from ClangSharp's AST

*Created: March 2026*
*Branch: user/jevansaks/shift-left-metadata*

---

## Problem Statement

`scraper.settings.rsp` contains ~12,700 `--remap` entries that tell ClangSharp to
rename C/C++ tag names to their typedef names in generated C# output. For example:

```
--remap
_BLUETOOTH_ADDRESS=BLUETOOTH_ADDRESS
tagDEC=DECIMAL
_RTL_BARRIER=SYNCHRONIZATION_BARRIER
__MIDL___MIDL_itf_foo_0001=RealTypeName
```

These are manually maintained. When the Windows SDK adds new types, someone must
manually add corresponding remap entries. If they don't, types appear in the winmd
with internal names like `_FOO` instead of their public typedef name `FOO`.

A previous attempt used a text-based regex scanner to parse raw SDK headers. This
fundamentally failed because it can't handle macro-expanded names (e.g.,
`VK_TO_WCHARS1` is produced by `##` token-pasting — it never appears literally in
the header source).

## Solution: CLI with `log-potential-typedef-remappings`

ClangSharp already runs libclang on every SDK partition during the scraping phase.
libclang fully preprocesses macros and builds a complete AST. The
`log-potential-typedef-remappings` config option (already enabled in
`baseSettings.rsp`) causes ClangSharp to output `Info: Potential remap: X=Y`
lines for every typedef-tag relationship it discovers that isn't already
configured via `--remap`.

### Key Discovery

The in-process library approach (loading ClangSharp assemblies via reflection,
reading `_allValidNameRemappings` from the PInvokeGenerator instance) was
replaced with a simpler CLI-based approach. The `log-potential-typedef-remappings`
config option provides the same remap discovery through CLI output parsing, with
the critical advantage of **process isolation** — each partition runs in its own
`dotnet` process, eliminating concerns about:
- Shared libclang state across threads
- Memory pressure from accumulating CXIndex instances
- File contention from multiple PInvokeGenerator instances in one process
- Thread safety of libclang with concurrent CXIndex usage

### Architecture

```
┌─────────────────────────────────────────────────────────────────┐
│  ScrapeHeaders.ProcessPartition (per partition, parallel)       │
│                                                                 │
│  1. Build RSP files + CommandLineBuilder args                   │
│  2. dotnet "ClangSharpPInvokeGenerator.dll" @rsp1 @rsp2 ...    │
│     └─ Each partition runs in its own process                   │
│     └─ libclang parses headers (macros expanded)                │
│     └─ Discovers typedef-tag relationships                      │
│     └─ Generates C# output                                      │
│     └─ Outputs "Info: Potential remap: X=Y" for NEW remaps      │
│  3. Parse CLI output for potential remap lines                  │
│  4. Collect into suggestedRemaps (thread-safe with lock)        │
└─────────────────────────────────────────────────────────────────┘
                              │
                              ▼
              suggestedRemaps: Dictionary<string, string>
              (merged across all partitions)
                              │
                              ▼
         WriteAutoRemapsRsp() in Execute()
              → scraper.autoRemaps.generated.rsp
              (consumed on subsequent builds via @(ScraperRsp))
```

### Implementation Details

**File:** `sources/GeneratorSdk/MetadataTasks/ScrapeHeaders.cs`

**CLI invocation:** Each partition runs ClangSharp in its own `dotnet` process
via `TaskUtils.ExecuteCmd("dotnet", "<ClangSharpPInvokeGenerator.dll> @rsp")`.
This ensures complete process isolation — no shared libclang, no shared state.

**Remap discovery:** The `log-potential-typedef-remappings` config option
(in `baseSettings.rsp`) causes ClangSharp to output potential remaps as
`Info: Potential remap: X=Y` lines. `ProcessPartition` parses these from the
CLI output and collects them in the thread-safe `suggestedRemaps` dictionary.

**Auto-rsp writing:** After all partitions complete, `WriteAutoRemapsRsp()`:
1. Reads existing auto remaps from previous builds (accumulates over time)
2. Merges newly discovered remaps from the current build
3. Writes all entries to `$(GeneratedDir)/scraper.autoRemaps.generated.rsp`
4. Logs summary statistics

**Build integration:** The auto-generated rsp is included in `@(ScraperRsp)`
in `sdk.targets` with `Condition="Exists(...)"`:
- First build: file doesn't exist → not consumed → remaps discovered and written
- Subsequent builds: file consumed → remaps applied → only NEW remaps logged
- Auto rsp appears BEFORE `scraper.settings.rsp` so manual overrides take priority

**RSP parsing:** The method `ParseRspFile` reads `.rsp` files into a
`Dictionary<string, List<string>>` mapping switch names (`--remap`, `--exclude`,
etc.) to their values.

### Current Status (March 2026)

| Aspect | Status |
|--------|--------|
| CLI invocation | ✅ All partitions run in separate processes (process isolated) |
| Config parsing | ✅ All RSP settings parsed correctly |
| Code generation | ✅ 393/393 partitions produce correct C# output |
| Remap discovery | ✅ Potential remaps collected from CLI output via `log-potential-typedef-remappings` |
| Auto-rsp writing | ✅ Discovered remaps written to `scraper.autoRemaps.generated.rsp` |
| Build integration | ✅ Auto-rsp included in `@(ScraperRsp)` with bootstrap support |
| End-to-end build | ✅ Full build succeeds, winmd generated |
| Winmd comparison | ⚠️ Not yet compared byte-for-byte against published baseline |
| Manual rsp cleanup | ❌ Auto-derivable entries not yet removed from `scraper.settings.rsp` |

---

## Next Steps

### ✅ Step 1: Process isolation (completed)

Replaced the in-process library approach (reflection, IL emission, shared libclang)
with CLI-only invocation. Each partition now runs in its own `dotnet` process.
This eliminates thread safety, memory pressure, and file contention concerns.

### ✅ Step 2: Write auto-derived remaps to generated .rsp (completed)

`WriteAutoRemapsRsp()` writes discovered remaps to:

```
$(GeneratedDir)/scraper.autoRemaps.generated.rsp
```

This file is included in `@(ScraperRsp)` in `sdk.targets` with
`Condition="Exists(...)"`. On the first build, remaps are discovered and written.
On subsequent builds, the auto-generated file is consumed alongside the manual
file. The auto-rsp appears before `scraper.settings.rsp` so manual overrides
take priority.

### Step 3: Validate output equivalence

Compare the winmd generated on this branch against the CLI-generated baseline
(origin/main) to confirm equivalence.

```powershell
# Generate baseline with CLI (revert to origin/main, build)
# Then generate with this branch, build
# Compare the two winmd files
```

If there are differences, investigate whether they're benign (timestamps, ordering)
or indicate a generation bug.

### Step 4: Analyze manual vs auto-discovered remaps

To identify which entries in `scraper.settings.rsp --remap` are auto-derivable:

1. Run a build — `log-potential-typedef-remappings` outputs NEW potential remaps
   (types not yet in `--remap`)
2. To find which EXISTING manual entries are auto-derivable: run a build with
   the `--remap` entries temporarily removed. The potential remaps output will
   show all auto-discoverable typedef-tag relationships.
3. Entries in `scraper.settings.rsp` that appear in the auto-discovery output
   (same key=value) are auto-derivable and can be removed.
4. Entries NOT in auto-discovery are semantic overrides and must stay.

### Step 5: Remove auto-derivable entries from scraper.settings.rsp

Once validated, remove the auto-derivable entries from `scraper.settings.rsp
--remap`. Keep only:
- Semantic renames (tag→different_public_name)
- Type alias remaps (DWORD_PTR=UIntPtr, LRESULT=IntPtr, etc.)
- Identity remaps for disambiguation

---

## Technical Notes

### Remap discovery flow

1. `baseSettings.rsp` has `log-potential-typedef-remappings` in its `--config` section
2. ClangSharp CLI outputs `Info: Potential remap: X=Y` for discovered typedef-tag
   relationships that aren't already in `--remap`
3. `ProcessPartition` parses these lines with regex and adds to `suggestedRemaps`
4. After all partitions, `WriteAutoRemapsRsp` merges new + existing and writes to rsp
5. On next build, `sdk.targets` includes the auto rsp in `@(ScraperRsp)` via
   `Condition="Exists(...)"`

### Auto-rsp accumulation

The auto-rsp file accumulates across builds:
- Build 1: Many potential remaps discovered → written to auto rsp
- Build 2: Auto rsp consumed → those remaps now configured → only truly NEW remaps
  output → merged with existing auto rsp
- This ensures the auto rsp grows as the SDK adds new types

### Manual override priority

In `sdk.targets`, the auto rsp appears BEFORE `scraper.settings.rsp` in the
`@(ScraperRsp)` item group. When RSP files are processed, later entries override
earlier ones for the same key. This means if both files have `_FOO=...`, the
manual file's value wins.

### Files modified

| File | Change |
|------|--------|
| `sources/GeneratorSdk/MetadataTasks/ScrapeHeaders.cs` | Removed ~300 lines of library invocation code (reflection, IL emission, assembly loading). Added `WriteAutoRemapsRsp()` and `ParseRspFile()` utilities. |
| `sources/GeneratorSdk/sdk/sdk.targets` | Added `ScraperAutoRemapsRsp` property and included in `@(ScraperRsp)` with bootstrap support |
