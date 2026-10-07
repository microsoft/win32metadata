# Producer adoption ledger

Core extraction, RDL, and metadata algorithms belong in windows-rs. This repository
owns dependency adoption, SDK input configuration, annotation capture, and packaging.

`Cargo.toml` and `Cargo.lock` currently pin all four git dependencies to
[`f62037957d26e2300e17ada4c5ca9a8f8a9d3b50`](https://github.com/jevansaks/windows-rs/commit/f62037957d26e2300e17ada4c5ca9a8f8a9d3b50),
published in `jevansaks/windows-rs`. It directly follows the previously adopted
`0a4d025f87a301eecf0eb9dce8bce8ae9e811eb9`, whose parent is the pipeline baseline
`a71662f435eaf24dde7346b684cb4cffc64ca376`. This ledger does not claim that every
historical fork change has been upstreamed.

| Dependency | Role |
| --- | --- |
| `windows-clang` | Native declarations, annotation facts, and RDL emission. |
| `windows-rdl` | RDL compilation and WinMD-to-RDL emission. |
| `windows-metadata` | Metadata identities, reading, writing, and merging. |
| `windows-default` | Reference metadata; follows the same exact producer revision. |

## SAL capture integration

**Upstream issue:** not applicable; this is our SDK capture/include configuration.

**Implementation:** `generation\WinSDK\AdditionalHeaders\win32metadata_sal.h`
loads `specstrings.h` before overriding SAL macros. It preserves strict mode and
captures `_Frees_ptr_`, `_Frees_ptr_opt_`, `_Post_`, and `_NullNull_terminated_`
verbatim. `scrape.rs::build_inputs` keeps the forced SAL implementation headers
dependency-only for focused/custom inputs, as aggregate generation already does.
Their internal configuration constants must not become public API.

**Portable repro and verification:** `tests\fixtures\sal_capture.cpp` covers two
SAL header sources and three include orders. `tests\fixtures\sal_capture_native.cpp`
uses the actual SDK declarations for `DuplicateHandle`, `LocalFree`, and
`GetVolumePathNamesForVolumeNameW`. From the repository root:

```powershell
dotnet restore .\BuildTools\BuildTools.proj
cargo test --manifest-path .\tools\rust\Cargo.toml sdk_sal_capture_ -- --nocapture
.\scripts\Test-GeneratorSdkPackage.ps1
```

The tests use the SDK versions in `eng\Versions.props` and pinned libclang 22.1.8.
They check extracted facts, physical WinMD direction/optional/count attributes,
native alias chains, and binary/single-NUL negative controls. The package test
checks the unchanged API golden and offline generation.

**Adoption:** consumer integration on the producer revision above. Optional-free
capture preserves Optional; it does not infer cleanup ownership or a SafeHandle.
The separate producer fix below supplies double-NUL emission.

**Removal condition:** replace the bridge only when native annotation extraction
passes these same gates without it, including the absence of support-header APIs.

## Local producer fixes

Both defects below were independently reproduced on public windows-rs
`143aa57cf5c96c140c69758948b46eb9a2d8ede7`. Their local fixes were introduced in
`0a4d025` and remain in the current adoption; no core implementation is duplicated
in this repository.

| Upstream issue and standalone repro | Local fix | Verification | Removal condition |
| --- | --- | --- | --- |
| [microsoft/windows-rs#5041](https://github.com/microsoft/windows-rs/issues/5041) | Preserve enclosing TypeRef identity through RDL, metadata copy/merge/remap, and bindgen. | Producer `nested_roundtrip` and `inline_nested_identity` gates; consumer `tests\fixtures\nested_identity.rdl` through compile/cached merge/recompile. | Adopt an upstream revision containing the fix; retain these regressions. |
| [microsoft/windows-rs#5042](https://github.com/microsoft/windows-rs/issues/5042) | Carry captured `_NullNull_terminated_` from parameter facts through RDL to `NullNullTerminatedAttribute`, without changing pointer/string types. | Producer `captured_double_null_sal_remains_distinct`; consumer synthetic and actual SDK SAL gates above. | Adopt an upstream revision containing the fix; retain double-NUL and negative controls. |

The issues contain minimal standalone repros. From a windows-rs checkout at the
adopted revision, run the committed producer regressions:

```powershell
cargo test -p test_metadata --test nested_roundtrip --quiet
cargo test -p test_bindgen --test bindgen inline_nested_identity --quiet
cargo test -p windows-clang --test annotations captured_double_null_sal_remains_distinct --quiet
```

The consumer nested-identity gate is:

```powershell
cargo test --release --manifest-path .\tools\rust\Cargo.toml compiled_and_merged_nested_references_keep_enclosing_identity
```

Two unrelated full `test_rdl` failures and three full `test_bindgen` failures also
reproduce on the unchanged `a716` baseline. They are not fixes or passing gates
claimed by this adoption.

## Partitioned NLS adoption gate

**Upstream issue:** not filed. This defect was demonstrated on the local pipeline
base `0a4d025`; public-upstream reproduction is not claimed.

**Local fix and adoption:** producer `f62037957d26e2300e17ada4c5ca9a8f8a9d3b50`
excludes namespace containers from emitted-symbol collision indexing, scoping,
and mutation. Source `Windows`/`ABI` ancestry remains intact without broadening
root eligibility or disabling genuine emitted-symbol disambiguation. The fix
lives entirely in windows-rs; this repository changes the dependency pin and
adds integration coverage, not a planner workaround.

The opt-in `sdk_partitioned_nls_preserves_enum_contracts` integration test uses
a repaired SDK header cohort without modifying it. It extracts the real
WinNls, StringApiSet, DateTimeApi, and DXGI declarations, applies their logical
header owners through the production `HeaderPartitionPlan` wrapper, and supplies
nonempty default WinRT references. A focused by-header test or an empty reference
map does not cover the same namespace eligibility path.

Provide a generated `generation\WinSDK` directory containing the populated NLS
vocabularies and a new output directory whose parent already exists:

```powershell
$env:WIN32METADATA_NLS_INPUT_ROOT = (Resolve-Path .\cohort\generation\WinSDK).Path
$env:WIN32METADATA_NLS_OUTPUT_ROOT = Join-Path $PWD "obj\nls-partitioned-check"
cargo test --release --locked --manifest-path .\tools\rust\Cargo.toml `
    sdk_partitioned_nls_preserves_enum_contracts -- --ignored --nocapture
```

The test retains input, native-member, RDL, and WinMD evidence. It requires nine
NLS definitions, 41 source-valued members, 19 associations resolving to those
definitions, three CSTR fields owned by `COMPARESTRING_RESULT`, and the
independently owned DXGI vocabulary. Existing evidence directories are rejected
rather than overwritten. This bounded integration gate is not a full SDK run
or a substitute for the producer's generic collision/eligibility regressions.

The producer's `crates\libs\clang\tests\header_partitions.rs` regressions cover
nonempty WinRT references, independent reopened Windows/ABI namespaces, real
same-leaf symbol collisions and bound TypeRefs, namespace/symbol coexistence,
signed-versus-unsigned macro consumption, and rejected native-namespace controls:

```powershell
cargo test -p windows-clang --test header_partitions `
    namespace_containers_do_not_enter_partition_symbol_collisions -- --nocapture
cargo test -p windows-clang --test header_partitions --quiet
```

**Removal condition:** adopt an upstream revision containing equivalent generic
namespace-container handling, keeping both the producer controls and the
real-header integration gate. The producer's full `windows-clang` suite is also
required; passing focused emission alone is insufficient.

## Native `flag_enum` regression

**Upstream issue:** <https://github.com/microsoft/windows-rs/issues/5047>.

The self-contained `tests\fixtures\flag_enum.cpp` pairs an enum with actual
`[[clang::flag_enum]]` syntax and an otherwise equivalent plain enum. The
`scrape::tests::clang_flag_enum_preserves_flags_attribute` test checks the native
Clang cursor, production extraction and RDL emission, then compiled WinMD.
It requires `System.FlagsAttribute` only on the annotated enum while preserving
both enums' unsigned 32-bit backing types and member values.

**Known failure:** with producer
`f62037957d26e2300e17ada4c5ca9a8f8a9d3b50` and pinned libclang 22.1.8, Clang
recognizes `CXCursor_FlagEnum` only on the annotated enum, but extraction loses
the marker before the snapshot. Neither the emitted RDL nor the WinMD retains
flags. The plain-enum, backing-type, and member-value controls pass. No local
producer patch, dependency change, or product workaround is applied for this
issue.

The desired C++ assertion is explicitly ignored in normal runs pending an adopted
upstream fix; invoking it explicitly **fails**, rather than accepting missing flags:

```powershell
cargo test --release --locked --manifest-path .\tools\rust\Cargo.toml `
    clang_flag_enum_preserves_flags_attribute -- --ignored --nocapture
```

The test prints its evidence directory and retains the fixture, extracted facts,
RDL, WinMD, and observations. Optionally set `WIN32METADATA_FLAGS_OUTPUT_ROOT` to
a new directory whose parent already exists; existing directories are rejected.
The enabled downstream control verifies that explicit RDL `#[flags]` already
produces `System.FlagsAttribute`, without marking a plain enum:

```powershell
cargo test --release --locked --manifest-path .\tools\rust\Cargo.toml `
    rdl_flags_attribute_preserves_plain_enum_control
```

**Removal condition:** remove the ignore when an adopted producer revision passes
the unchanged C++ regression, retaining both the annotated/plain native controls
and the enabled direct-RDL control.
