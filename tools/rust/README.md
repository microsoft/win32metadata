# win32metadata-tools

A command-line front end over the pinned windows-rs producer revision, providing
`windows-clang`, `windows-rdl`, and `windows-metadata`.

The production `scrape --win32-sdk` path reads the pinned raw Windows SDK headers and
constructs the producer-supported aggregate plus satellite inputs. Logical authority adds
two `PSAPI_VERSION` compile variants and an independent WinHTTP context; it never expands
into one input per partition. `--partition-policy-root` routes physical header provenance through the checked-in
logical partition policies. Every physical owner is qualified to its assigned aggregate,
satellite, PSAPI, or WinHTTP input, so the same header included elsewhere remains dependency
closure rather than becoming a public root. x64, x86, and arm64 are extracted and compiled
in parallel by default, then their WinMDs are merged into one output.
`--architecture-jobs` can lower concurrent workloads. Focused partition translation units remain
available for package fixtures and inner-loop debugging.

WinHTTP uses the existing `WinHttp/main.cpp` compile environment in the fifth authority
input, while WinInet and Winineti remain in the aggregate. Their incompatible
`_INTERNET_SCHEME_` and `_URL_COMPONENTS_` provider guards must not share a preprocessing
context: parsing either provider first suppresses declarations from the other. The
separate snapshots preserve native values, record identities, and provider-local references
without guard manipulation, aliases, or namespace changes. Explicit raw SDK mode retains
its original two-input behavior.

In logical authority mode, explicitly traversed headers retain their assigned namespaces.
Required dependency types from other headers use the default `Windows.Win32` namespace
instead of inheriting a referring partition's namespace. This includes exact dependencies
declared in C++ namespaces such as `DirectX`; it does not select unrelated declarations
from those headers. Explicit namespace routes still take precedence, and missing or
ambiguous declarations remain errors. Forward-declared non-UUID C++ classes, such as the
GLU opaque types, use named empty records just like incomplete structs. Pointers and
typedef aliases preserve that identity; no complete layout is inferred, and by-value
use remains an error.

Explicitly owned, selected native entry points can retain their C++ namespace
identity during header planning. Their required non-POD class dependencies may
expose public native data fields when there are no bases or virtual behavior.
This is not general C++ class import: ordinary unselected classes remain
unsupported, nontrivial by-value uses are rejected, and methods, constructors,
destructors, and lifetime behavior are not projected.

An explicitly annotated class definition can instead request pointer-only nominal
identity: `class _Win32_NativeOpaque_ NativeClass { ... };`. The capture header emits
the valueless `win32metadata:native_opaque` marker only for metadata generation
with Clang; native metadata-off builds are unchanged. The producer retains an
empty named pointee through pointers, references, and pointer typedefs without
projecting fields, methods, bases, layout, inheritance, or lifetime behavior.
Every by-value use is an error. The marker is valid only on a named non-COM C++ class
definition, not a forward declaration, struct, union, template, typedef, function,
or parameter. Unmarked classes keep their existing projection.

Exact declaration matching includes the translation unit. An included-only declaration
is not rewritten to another header's scoped alias merely because that alias is the only
owned variant in its input. For example, a satellite `GetQueuedCompletionStatus` keeps
its original inline pointer parameter even when the aggregate owns separate IIS and
MSXML `PULONG_PTR` aliases; no extra default nominal alias is introduced.

Equivalent declarations claimed by different logical partitions coalesce when their
resolved namespace and effective emitted semantics agree, including annotations,
UUID/flags handling, and the symbol's actual import library. Unrelated policy-map
entries do not create a conflict. A stable policy/source route supplies the output
bucket, independent of declaration order; genuinely conflicting claims still report
every owner.

Only the exact typedef declaration retained by dependency closure contributes a
canonical alias route. Projected-away roots do not create conflicts or redirect raw
pointers through another owner's alias. Thus Backup's `PSID` remains a direct void
pointer while TBS retains its own `PVOID` and the `TBS_HCONTEXT` alias relationship.

Canonical raw-pointer declarations retain their exact nominal identity when a selected
pointer typedef refers through them or a selected use crosses a mutable/const boundary.
Thus TBS's `PTBS_HCONTEXT` retains its pointer to `PVOID` without introducing a Backup
`PVOID`. ClrProfiling and WinRT.Metadata each retain their authored `PCCOR_SIGNATURE`;
an outer mutable pointer still refers to that const-pointer alias rather than an
unrepresentable mixed raw-pointer chain. Representable same-mutability function and
field chains keep their existing raw projection unless a selected function also reaches
a named callback that directly uses the exact alias. This preserves the shared `LPVOID`
identity in `CallEnclave`, its output pointer, and `PENCLAVE_ROUTINE` without letting
unrelated rooted callbacks retain aliases. Unselected functions do not force alias
retention merely because their declarations came from a traversed header.

Independently declared roots retain an identity in each explicitly assigned namespace.
Exact declaration references preserve each API family's aliases, record fields, and
signatures, including WinHTTP/WinINet handles and Direct2D record aliases. Duplicate
GUID declarations retain their values in both namespaces. Each declaration identity
must resolve to one namespace: conflicting claims on a single declaration still fail
rather than choosing an arbitrary owner. Legacy partitioned behavior is unchanged.

Macro-produced declarations use expansion provenance for routing, so separate
`C_ASSERT` expansions can retain one array alias per namespace without mistaking their
shared macro definition for one declaration assigned conflicting owners.

Emitted type references still resolve by declaration spelling, and qualify only when
the retained routes agree on one namespace. Included-only `DECLARE_HANDLE` aliases,
such as `HWND`, `HDC`, and `HBITMAP`, therefore remain qualified to the default namespace
in foreign record fields and signatures.

`DEFINE_DEVPROPKEY` and `DEFINE_PROPERTYKEY` constants use their planned record
identity, including declaration remaps and explicit or default namespace routes,
just like ordinary type references. Their GUID and property ID values remain
unchanged; required key records from unlisted headers stay dependency-only.

The independent `AVIIF_LIST` and `AVIIF_KEYFRAME` definitions likewise remain in both
DirectShow and Multimedia. `NOAVIFMT` still prevents duplicate AVI records, but does
not guard these two earlier literal definitions in `Vfw.h`.

For an exact SDK `DECLARE_HANDLE` expansion whose verified private dummy record is
explicitly excluded, header planning retains the public handle as a named `*mut void`
typedef. Aliases and pointer depth remain intact; nonexcluded and legacy handle output
is unchanged. No cleanup or invalid-handle annotations are inferred from the declaration.

Canonical string-pointer aliases retain their resolved namespace, including aliases reached
through ANSI or Unicode `TCHAR` typedefs. When references do not supply the canonical alias,
required dependency closure emits it locally; cross-namespace uses are qualified.
Collision planning also follows exact same-input typedef chains before deciding that
declarations differ. The SDK's `typedef LONG NTSTATUS` and `typedef long NTSTATUS`
are equivalent even when explicit header ownership requires separate namespaces.
References from an explicitly suppressed declaration can retain the existing preferred
owner only when every retained variant is equivalent. This preserves the Kernel
exclusion and Foundation constant references to WindowsProgramming's `NTSTATUS`,
while Display keeps its own identity. Missing aliases do not acquire invented routes;
genuinely different types still require separate collision handling.

Clustering records with multiple concrete bases are projected directly from their SDK
definitions. Their former `MsCs` exclusions only prevented duplicate definitions alongside
legacy manual C# replacements; those exclusions and replacements are no longer needed.
Explicit exclusions otherwise remain hard constraints, including for required dependencies.
Likewise, `DWRITE_FONT_AXIS_TAG` and `JsRuntimeVersion` are emitted from their SDK enum
definitions instead of excluding them in favor of removed manual C# enums. The remaining
Js constant exclusions and the selected non-edge header mode are unchanged.

DirectDraw likewise emits the native `MDL` record and `PMDL` pointer alias from
`dxmini.h`, including the named alias in `DDTRANSFERININFO.lpDestMDL`. The former
`_MDL=DDMDL` / `PMDL=DDMDL*` pair was a C# projection substitution, not a native
declaration rename. Partition `--remap` targets must be declaration identifiers;
type expressions now fail policy validation before SDK extraction rather than
becoming invalid RDL declaration names.

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

Gdiplus no longer excludes `PathData`. The original GDI+ integration
(`b9994fad7ab7f7849d48ecb31ae7559daaae1a16`) paired that exclusion with a
manual `autoTypes.json` `PathData = IntPtr` typedef. That replacement is no
longer present; the selected API now requires the SDK's actual data layout
instead. This changes only that exclusion and the reviewed authority digest,
not header roots, include environments, or namespace routes. It does not
restore the synthetic typedef or infer C++ lifetime management.

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
| `compile` | Generated RDL -> WinMD without repeating SDK extraction. |
| `merge-arch` | Matching cached per-architecture RDL/WinMD pairs -> merged RDL and WinMD. |
| `roundtrip` | WinMD -> RDL -> WinMD fidelity harness (`scripts\Test-WindowsRdlRoundTrip.ps1`). |
| `libclang` | Resolve, load, and report the pinned libclang. |

## Inner loop

From the repository root:

```powershell
.\scripts\Generate-WindowsRsWinmd.ps1
```

By default this uses the pinned `Microsoft.Windows.SDK.CPP` packages and logical
partition authority, and generates `bin\Windows.Win32.winmd` for x64, x86, and arm64.
Pass `-Architecture x64` for a single-architecture run. Passing `-Partition
Foundation,Bluetooth` selects focused legacy partition inputs instead of the production
header manifest. Production extraction uses aggregate + satellite, two PSAPI variants,
and the independent WinHTTP context, not one translation unit per partition.
`-UsePartitionAuthority` remains accepted explicitly. `-RawSdk` (or
`-UsePartitionAuthority:$false`) selects the raw
NuGet SDK manifest without checked-in header preparation or logical authority.

The production MSBuild path is:

```powershell
.\scripts\BuildMetadataBin.ps1
```

Both scripts prepare `generation\WinSDK\obj\RecompiledIdlHeaders` from the checked-in
pristine `RecompiledIdlHeaders` mirror and apply sorted `patches\post-midl\*.patch`
files exactly once. There is no MIDL rewrite. The prepared tree **replaces** the first
include root; the remaining five roots, canonical authorities, namespace routes and
native library selection are unchanged. Zero patches are recorded explicitly: a base
branch without the annotation corpus is not evidence that the child branch's patches
were applied.

A per-tree lock covers preparation, all architecture workers, and native completion.
Repository clean uses that lock too. Source, patch, recipe and prepared-file hashes
allow reuse only when inputs and outputs still match; changed/added/removed patches
or mutated/extra output files cause a fresh copy. Files outside the named generated
header tree are not touched by preparation. Do not run the legacy MIDL preparer
concurrently with generation.

`BuildMetadataBin.ps1 -arch x64` writes `bin\Windows.Win32.x64.winmd`;
`Generate-WindowsRsWinmd.ps1 -Architecture x64` still defaults to
`bin\Windows.Win32.winmd` and is **x64-only**, not cross-architecture evidence.
`BuildMetadataBin.ps1 -RawSdk`, or direct MSBuild with
`-p:WinmdUsePartitionAuthority=false`, preserves the explicit raw mode.
Direct `dotnet build generation\WinSDK -t:EmitWinmd` also defaults to root
`bin\Windows.Win32.winmd`, not a project-local bin directory.

Preparation records hashes and patch count in `obj\windows-rs-headers.json`.
Successful generation writes `<output>.provenance.json`, binding the preparation,
native executable, actual arguments and generated image. Check it without repairing
stale inputs:

```powershell
.\scripts\Prepare-WindowsRsHeaders.ps1 -VerifyOutput .\bin\Windows.Win32.winmd
.\scripts\Test-WindowsRsHeaders.ps1
```

The fixture test reads real x64/x86/arm64 WinMD output after changing a header patch,
and covers stale trees, patch errors, quoting, native failure/cancellation, and
concurrent preparation/clean. Generic packaged SDK consumers keep direct native-tool
execution and need neither Git nor repository patches after restore. Repository builds
still use local Cargo with `--locked`; installing a NuGet tool package does not update
the repository's Cargo pin or supply a missing header patch corpus.

Prerequisites are PowerShell 7, Git, the .NET SDK from `global.json`, Rust from
`rust-toolchain.toml`, and the restored packages pinned by `eng\Versions.props`.
The tool builder stages pinned libclang 22.1.8 and its matching resource headers.
`BuildMetadataBin.ps1` installs/restores repository build tools (including pinned nbgv);
the lightweight Generate script expects nbgv available and restores SDK references
when needed.

CI builds this prepared authority path and retains strict metadata TRX results.
The existing `-AllowKnownGeneratorGaps` option is a raw-era exact **nine failure
fingerprints plus four passes**, not a strict product pass; CI no longer applies it
automatically. Changed output requires native/architecture evidence and real fixes or
reviewed expectation decisions, not widening that allowance. The separately recorded
Rust 103/104 authority-count discrepancy and held DXC ownership conflict are unchanged
by build wiring.

### Duplicate-type diagnostics

The companion `WinmdUtils showDuplicateTypes --winmd <path>` command reports
structural/native-semantic duplicate **candidates**, not proof that native declarations
may be merged. Same-leaf names generate candidates; field and method signatures,
referenced type identities, layout, ABI properties, constants, and native attributes
determine whether they collide on overlapping architectures. Disjoint architecture
variants do not collide. A type's own namespace does not make this comparison vacuous.

Distinct resolved `RAIIFree` cleanup providers can distinguish otherwise matching
definitions. Missing, incomplete, or ambiguous provider bindings remain conservative
duplicate candidates; a namespace or usage site alone is not provider-identity proof.
Diagnostics list full owner names and the overlapping architectures. For groups where
not every owner collides with every other owner, explicit collision pairs identify the
actual conflicts. A nonzero exit code still fails the strict integrity check.

### Duplicate-constant diagnostics

`WinmdUtils showDuplicateConstants --winmd <path>` groups native identifiers using
ordinal, case-sensitive names and preserves their spelling in diagnostics.
Case-distinct names remain separate; equal values do not exempt exact-name collisions.

For backward compatibility, `--allowItem` matches the diagnostic name after
current-culture `ToUpper()` against the existing exact, case-sensitive token set.
For example, under `en-US`, a duplicate named `NativeConstant` still requires
`--allowItem NATIVECONSTANT`, not `--allowItem NativeConstant`. This does not add
invariant normalization, ignore-case matching, token migration, or new allowances.

### Merging cached architectures

Keep each architecture's generated RDL with its matching WinMD. Supply x64 first
as the canonical partition source, followed by the other architectures:

```powershell
.\bin\GeneratorSdk\tools\win-x64\win32metadata-tools.exe merge-arch `
    --arch x64 --rdl .\cache\x64\rdl --winmd .\cache\x64\Windows.Win32.winmd `
    --arch x86 --rdl .\cache\x86\rdl --winmd .\cache\x86\Windows.Win32.winmd `
    --arch arm64 --rdl .\cache\arm64\rdl --winmd .\cache\arm64\Windows.Win32.winmd `
    --namespace Windows.Win32 --assembly-name Windows.Win32 `
    --output-rdl .\merged\rdl --output-winmd .\merged\Windows.Win32.winmd
```

Both output paths must be fresh and separate from the inputs; the output WinMD
must not be inside the RDL output directory. The merger preserves architecture
availability and differing definitions. RDL partition ownership uses qualified
namespace/item identities across the root namespace and all descendants, so
equal short names in different namespaces do not overwrite one another. Input
order determines the first owner; paths within each input are sorted.

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
| `--architecture-jobs <count>` | Positive maximum for concurrent architecture workers. Defaults to `3`. |
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
the SDK headers. The SAL bridge loads the SDK's `specstrings.h` rewrites before applying
capture overrides, without disabling strict mode. Focused inputs keep those implementation
headers dependency-only so their configuration constants do not become public API.
Optional-free capture retains Optional, not an inferred cleanup contract.

See the [producer adoption ledger](ADOPTION.md) for upstream issues, exact pins,
portable regressions, local core fixes, and retirement conditions.

**`--lib`** recovers symbol-to-DLL mappings from import libraries. Resolution is
first-wins. Supplying import libraries also filters out functions that have neither an
exported symbol nor an explicit import-library annotation.
In `--win32-sdk` mode, only the curated `win32_headers::IMPORT_LIBS` list is read,
not every library in the directory. This includes `gdiplus.lib`, so supported
GDI+ entry points are selected even from unannotated SDK headers. Declarations
without an import mapping or explicit import annotation remain unselected.

**`--arch`** may be repeated. Each architecture is extracted and compiled independently,
then the WinMDs are merged so architecture-specific declarations are tagged. The first
requested architecture remains canonical regardless of worker count.

**`--architecture-jobs`** bounds each complete extraction/planning/emission/compilation
worker, not just emission after all snapshots have been captured. The default remains
three; `--architecture-jobs 1` explicitly selects sequential architecture processing.
`BuildMetadataBin.ps1` and `Generate-WindowsRsWinmd.ps1` expose `-ArchitectureJobs`;
MSBuild/packaged SDK consumers use `WinmdArchitectureJobs`. None of these settings
changes the selected architectures, include roots, namespace authority or native inputs.
Normal generation provenance records the worker option in the native argument list.
Normal authority planning consumes the extracted snapshot without making a full initial
clone. Other borrowed snapshots are released before compilation; consuming legacy paths
retain their existing ownership behavior.

The limit reduces overlapping live workloads, not a guaranteed byte ceiling: libclang
and allocator retention can still affect process memory. Small serial/parallel fixtures
check all three per-architecture images and merged bytes; they do not establish a full-SDK
memory bound or diagnose an earlier allocation/stack-overflow failure. The PR validation
job allows 360 minutes; this checkpoint does not shorten that timeout.
The opt-in native byte-parity test requires the complete staged resource tree:

```powershell
.\scripts\Build-Win32MetadataTools.ps1
$env:CLANG_RESOURCE_DIR = "$PWD\bin\GeneratorSdk\tools\win-x64\clang-resource\22.1.8"
cargo test --release --locked --manifest-path .\tools\rust\Cargo.toml `
    architecture_jobs_keep_three_architecture_native_output_identical -- --ignored
.\scripts\Test-WindowsRsHeaders.ps1
```

Compilation and cached architecture merging atomically reserve distinct staging directories.
Process-local counters and collision retries prevent workers compiling the same assembly
from sharing temporary files or deleting each other's output; wall-clock timestamps are
not used as uniqueness guarantees.

The parser uses C++20 with Microsoft extensions, output is partitioned by defining header,
and the bundled Windows metadata supplies framework and external Win32 reference types
during RDL emission.

## libclang

The tool pins libclang **22.1.8**. The packaged SDK places `libclang.dll` and its
matching resource headers beside the executable under
`clang-resource\22.1.8`. Consumer generation resolves those files package-locally
and never clones LLVM. Standalone development builds may still restore the pinned
`libclang.runtime.win-<arch>` NuGet package for the DLL; stage the tool with
`scripts\Build-Win32MetadataTools.ps1` before multi-architecture generation or
the checked-in SDK regression tests. The x86 GDI+ regression validates and uses
the same staged resource tree without changing process-wide environment variables.

```powershell
cargo run --quiet --locked --manifest-path tools\rust\Cargo.toml -- libclang
```
