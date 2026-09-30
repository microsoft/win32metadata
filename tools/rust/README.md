# win32metadata-tools

A command-line front end over the pinned windows-rs producer revision, providing
`windows-clang`, `windows-rdl`, and `windows-metadata`.

The production `scrape --win32-sdk` path reads the pinned raw Windows SDK headers and
constructs the producer-supported aggregate plus satellite inputs: two translation units
per architecture. x64, x86, and arm64 extraction runs in parallel, then the per-architecture
WinMDs are merged into one output. Focused partition translation units remain available for
package fixtures and inner-loop debugging.

```text
raw SDK headers + import libraries + annotation contracts
    -> aggregate/satellite Input
    -> windows-clang Snapshot
    -> emit_by_header_with_options
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
header manifest.

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
| `--output <path>` | WinMD to write. |
| `--obj <dir>` | Intermediate directory. Defaults to the output directory. |

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

The tool pins libclang **22.1.8**. It uses `LIBCLANG_PATH` when set; otherwise the
`libclang.runtime.win-<arch>` NuGet package is restored on demand into the NuGet global
cache. Matching clang resource headers are cached under
`<obj>\clang-resource\22.1.8`. The loaded libclang version is verified before extraction.

```powershell
cargo run --quiet --locked --manifest-path tools\rust\Cargo.toml -- libclang
```
