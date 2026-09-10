# win32metadata-tools

A command-line front end over the pinned windows-rs metadata crates (`windows-clang`,
`windows-rdl`, `windows-metadata`, all `=0.100.0`).

`scrape` is the minimal alternate pipeline: partition `main.cpp` files plus the SDK header
root in, one WinMD out. It has no RSP or JSON inputs, and it does not carry forward the
switches of the existing scraper/emitter. The intermediate RDL is written under the object
directory.

```text
partition main.cpp + SDK include root [+ SDK lib root]
    -> windows-clang -> RDL under obj -> windows-rdl -> WinMD
```

## Commands

| Command | Purpose |
| --- | --- |
| `scrape` | Partition translation units -> WinMD. |
| `roundtrip` | WinMD -> RDL -> WinMD fidelity harness (`scripts\Test-WindowsRdlRoundTrip.ps1`). |
| `libclang` | Resolve, load, and report the pinned libclang. |

## Inner loop

From the repository root:

```powershell
.\scripts\Generate-WindowsRsWinmd.ps1 -Partition Foundation,Bluetooth,Bits
```

This resolves the repository's patched SDK-header copy and restored SDK import
libraries automatically. The direct tool invocation is:

```powershell
cargo run --quiet --locked --manifest-path tools\rust\Cargo.toml -- scrape `
  --partition generation\WinSDK\Partitions\Foundation\main.cpp `
  --include generation\WinSDK\inc `
  --include generation\WinSDK\RecompiledIdlHeaders `
  --output obj\windows-clang\Windows.Win32.winmd
```

```text
Scraping 1 partition(s) for x64 into C:\repos\win32metadata\obj\windows-clang\rdl
RDL: C:\repos\win32metadata\obj\windows-clang\rdl
WinMD: C:\repos\win32metadata\obj\windows-clang\Windows.Win32.winmd
Metadata: 4029 type(s), 4170 function(s), 22171 constant(s)
```

Roughly 15 seconds from a clean object directory.

## Options

| Option | Meaning |
| --- | --- |
| `--partition <path>` | Partition translation unit. Repeatable. |
| `--include <dir>` | Header root. Repeatable, searched in the order given. |
| `--lib <dir-or-file>` | SDK import-library directory or file. Repeatable. |
| `--arch <x64\|arm64\|x86>` | Repeatable. Defaults to `x64`. |
| `--output <path>` | WinMD to write. |
| `--obj <dir>` | Intermediate directory. Defaults to the directory of `--output`. |

**`--include` order matters.** Directories are passed to clang in the order given, so the
repository's `generation\WinSDK\inc` must precede the SDK root for its `sal.h` to win. An
include directory containing `shared`, `um`, `ucrt`, or `winrt` is expanded into those
subdirectories, so an SDK root is named once.

**`--lib`** recovers the symbol -> DLL mapping that headers do not carry. Without it every
function records an empty library. A directory is expanded into its `.lib` files sorted by
name; resolution is first-wins. Supplying import libraries also drops functions that no
library exports.

**`--arch`** may be repeated. The first architecture is canonical and writes the RDL
partitions; the rest are scraped to per-architecture WinMDs in the object directory and
folded back in, so symbols present on only some architectures are tagged. A
non-canonical architecture needs version-matched clang resource headers, which are fetched
once into `<obj>\target\windows-clang`.

Everything else is fixed: the flat `Windows.Win32` root namespace partitioned by defining
header, `-x c++ -std=c++17 -ferror-limit=0 -Wno-pragma-once-outside-header
-DWIN32METADATA=1`, a `shared`/`um` reachability scope, and the bundled Windows metadata
as the reference that supplies the `Windows.Win32.Metadata` attribute vocabulary during
the RDL compile.

## libclang

`windows-clang` pins libclang **22.1.8**. It is taken from `LIBCLANG_PATH` when set,
otherwise the `libclang.runtime.win-<arch>` NuGet package is restored on demand into the
NuGet global cache using `curl` and `tar` from `System32`. The loaded version is checked
against the pinned one, and every failure reports the manual `nuget install` fallback.

```powershell
cargo run --quiet --locked --manifest-path tools\rust\Cargo.toml -- libclang
```

## Known gaps

- **SAL.** `generation\WinSDK\inc\sal.h` is written for ClangSharp. `windows-clang` reads
  either portable `annotate` stubs or SDK SAL attribute tokens, so annotation fidelity under
  this shim is unverified and is expected to move with the annotation specification.
- **HtmlHelp.** `infotech.h` includes MSVC `comdef.h`, whose
  `_com_ptr_t<FontEvents>` helper currently reaches an unhandled windows-clang type path.
  This requires an upstream parser fix or a tighter out-of-scope helper filter.
- **Architecture-dependent constants.** Multi-architecture generation succeeds, but
  `windows-rdl` 0.100.0 currently leaves duplicate constants such as `CONTEXT_ALL` and
  `MAXUINT_PTR` in the flat `Windows.Win32.Apis` container. The architecture merge needs
  to coalesce or tag those fields before the full WinMD passes the duplicate-constant gate.
- **API equivalence.** The generated WinMD is not yet compared against the released
  metadata; that is deliberately deferred.
