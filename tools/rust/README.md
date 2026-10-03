# win32metadata-tools

A command-line front end over the pinned windows-rs producer revision, providing
`windows-clang`, `windows-rdl`, and `windows-metadata`.

The production `scrape --win32-sdk` path reads the pinned raw Windows SDK headers and
constructs the producer-supported aggregate plus satellite inputs. Logical authority adds
only the two required `PSAPI_VERSION` compile variants; it never expands into one input per
partition. `--partition-policy-root` routes physical header provenance through the checked-in
logical partition policies. Every physical owner is qualified to its assigned aggregate,
satellite, or PSAPI input, so the same header included elsewhere remains dependency closure
rather than becoming a public root. x64, x86, and arm64 extraction runs in parallel, then the
per-architecture WinMDs are merged into one output. Focused partition translation units remain
available for package fixtures and inner-loop debugging.

In logical authority mode, explicitly traversed headers retain their assigned namespaces.
Required dependency types from other headers use the default `Windows.Win32` namespace
instead of inheriting a referring partition's namespace. This includes exact dependencies
declared in C++ namespaces such as `DirectX`; it does not select unrelated declarations
from those headers. Explicit namespace routes still take precedence, and missing or
ambiguous declarations remain errors. Forward-declared non-UUID C++ classes, such as the
GLU opaque types, use named empty records just like incomplete structs. Pointers and
typedef aliases preserve that identity; no complete layout is inferred, and by-value
use remains an error.

For an exact SDK `DECLARE_HANDLE` expansion whose verified private dummy record is
explicitly excluded, header planning retains the public handle as a named `*mut void`
typedef. Aliases and pointer depth remain intact; nonexcluded and legacy handle output
is unchanged. No cleanup or invalid-handle annotations are inferred from the declaration.

Canonical string-pointer aliases retain their resolved namespace, including aliases reached
through ANSI or Unicode `TCHAR` typedefs. When references do not supply the canonical alias,
required dependency closure emits it locally; cross-namespace uses are qualified.
Collision planning also follows exact same-input typedef chains before deciding that
declarations differ. The SDK's `typedef LONG NTSTATUS` and `typedef long NTSTATUS`
therefore retain the same existing public owner; an equivalent extra spelling must
not create a scoped identity that breaks the Kernel exclusion or constant references.
Genuinely different types still require separate collision handling.

Clustering records with multiple concrete bases are projected directly from their SDK
definitions. Their former `MsCs` exclusions only prevented duplicate definitions alongside
legacy manual C# replacements; those exclusions and replacements are no longer needed.
Explicit exclusions otherwise remain hard constraints, including for required dependencies.
Likewise, `DWRITE_FONT_AXIS_TAG` and `JsRuntimeVersion` are emitted from their SDK enum
definitions instead of excluding them in favor of removed manual C# enums. The remaining
Js constant exclusions and the selected non-edge header mode are unchanged.

The aggregate defines `USE_COM_CONTEXT_DEF` before its first include, as the
focused Com input does. Defining it only around later COM includes is too late
when an earlier dependency has already guarded `objidlbase.h`; the complete
`IContext` and `IEnumContextProps` interfaces must remain visible.

Required SDK records, delegates, and pointer aliases are not replaced by the
removed C# generator's remaps or manual declarations. The reviewed policy
restorations include `LIST_ENTRY32/64`, the enclave callback aliases,
`NDR_SCONTEXT`, `RO_REGISTRATION_COOKIE`, and
`SslGetCipherSuitePRFHashAlgorithmFn`. Backup no longer excludes all empty
records: required incomplete pointees such as `_ACTIVATION_CONTEXT` retain a
named opaque identity without an invented layout. The SDK's incomplete
`IStiDeviceW` and its `PSTIDEVICEW` pointer remain distinct from the complete
`IStiDevice` interface rather than silently redirecting the alias.
`SymbolSearchInfo` and `TypeSearchInfo` use their native data layout and base;
`EnumerateChildrenEx` remains in the COM interface hierarchy, not removed from
the vtable. Focused regressions compile the header-defined types and selected
API signatures to WinMD and read back these distinctions.

Header-plan dependency failures are reported together, with the selected roots that
reach each blocker. With `WINDOWS_CLANG_TIMINGS=1`, `phase=plan-dependencies` reports
selected roots, processed unique dependencies, resolved dependencies, and unique blockers.
These are dependency-closure counts, not an overall completion percentage: children of
missing, ambiguous, or unsupported types cannot be inspected, and later layout, ownership,
routing, and RDL validation may still fail. A blocked plan never emits partial RDL.
After dependency closure succeeds, required owner-excluded types are also reported as a
deterministic batch with selected-root referrers, rather than one failure per full run.

The same timing flag reports consumer configuration, header ownership, and header emission
durations, including failed phases. Header emission includes the producer's root and
dependency planning times; do not add those nested timings to it when computing totals.

Authority mode validates the canonical ownership/policy/compile-environment inventory digest
before extraction. Compile-environment identity alone does not create another translation unit;
PSAPI remains the only proven incompatible same-header compile variant.

```text
raw SDK headers + import libraries + annotation contracts
    -> aggregate/satellite Input
    -> windows-clang Snapshot
    -> optional HeaderPartitionPolicy audit
    -> emit by physical header or logical partition
    -> per-architecture RDL/WinMD
    -> merged WinMD
```

## Commands

| Command | Purpose |
| --- | --- |
| `scrape` | SDK headers or focused partition translation units -> WinMD. |
| `roundtrip` | WinMD -> RDL -> WinMD fidelity harness (`scripts\Test-WindowsRdlRoundTrip.ps1`). |
| `libclang` | Resolve, load, and report the pinned libclang. |

## Inner loop

From the repository root:

```powershell
.\scripts\Generate-WindowsRsWinmd.ps1
```

By default this restores the pinned `Microsoft.Windows.SDK.CPP` packages, reads the raw
`10.0.28000.0` headers, and generates `bin\Windows.Win32.winmd` for x64, x86, and arm64.
Pass `-Architecture x64` for a single-architecture run. Passing `-Partition
Foundation,Bluetooth` selects focused legacy partition inputs instead of the production
header manifest. `-UsePartitionAuthority` selects aggregate extraction with checked-in
logical ownership and two focused PSAPI variants; it does not create one translation unit
per partition.

The production MSBuild path is:

```powershell
.\scripts\BuildMetadataBin.ps1
```

## Options

| Option | Meaning |
| --- | --- |
| `--win32-sdk` | Use the pinned aggregate + satellite Windows SDK header manifest. |
| `--partition <path>` | Focused partition translation unit. Repeatable. |
| `--partition-root <path>` | Directory of partition subdirectories containing `main.cpp`. Repeatable. |
| `--partition-policy-root <path>` | Route aggregate extraction with the logical policies under this partition root. |
| `--include <dir>` | Header root. Repeatable, searched in order. |
| `--lib <dir-or-file>` | SDK import-library directory or file. Repeatable. |
| `--arch <x64\|arm64\|x86>` | Repeatable. Defaults to `x64`. |
| `--scope <segment>` | Header directory segment emitted unconditionally. Repeatable. |
| `--scope-header <header>` | Header name emitted unconditionally. Repeatable. |
| `--symbol <name>` | Emit a focused function and its dependencies. Repeatable. |
| `--constant <name>` | Emit a focused constant. Repeatable. |
| `--namespace <name>` | Root namespace. Defaults to `Windows.Win32`. |
| `--assembly-name <name>` | Assembly identity. Defaults to the output file stem. |
| `--assembly-version <A.B.C.D>` | Four-part assembly version. |
| `--extraction-coverage <path>` | x64-only canonical traversal-root provenance report; stops before RDL/WinMD. |
| `--output <path>` | WinMD to write. |
| `--obj <dir>` | Intermediate directory. Defaults to the output directory. |

Extraction coverage does not read import libraries. Its versioned TSV contains canonical,
observed, and unobserved counts followed by every unobserved root as
`unobserved<TAB>uncategorized<TAB><stable-root>`; an unobserved root is evidence to classify,
not an automatic failure.

**`--include` order matters.** Directories are passed to clang in the order given. An
include directory containing `shared`, `um`, `um\cpdk`, `ucrt`, or `winrt` is expanded
into those subdirectories, so an SDK root is named once.

`win32metadata_sal.h` and `win32metadata_annotations.h` are force-included for every input,
and `WIN32METADATA=1` is defined. This captures the annotation contracts without modifying
the SDK headers.

**`--lib`** recovers symbol-to-DLL mappings from import libraries. Resolution is
first-wins. Supplying import libraries also filters out functions that have neither an
exported symbol nor an explicit import-library annotation.

**`--arch`** may be repeated. Each architecture is extracted and compiled independently;
multi-architecture runs execute those workers in parallel and merge their WinMDs so
architecture-specific declarations are tagged.

The parser uses C++20 with Microsoft extensions, output is partitioned by defining header,
and the bundled Windows metadata supplies framework and external Win32 reference types
during RDL emission.

## libclang

The tool pins libclang **22.1.8**. The packaged SDK places `libclang.dll` and its
matching resource headers beside the executable under
`clang-resource\22.1.8`. Consumer generation resolves those files package-locally
and never clones LLVM. Standalone development builds may still restore the pinned
`libclang.runtime.win-<arch>` NuGet package for the DLL; stage the tool with
`scripts\Build-Win32MetadataTools.ps1` before multi-architecture generation.

```powershell
cargo run --quiet --locked --manifest-path tools\rust\Cargo.toml -- libclang
```
