# Producer adoption ledger

Core extraction, RDL, and metadata algorithms belong in windows-rs. This repository
owns dependency adoption, SDK input configuration, annotation capture, and packaging.

`Cargo.toml` and `Cargo.lock` currently pin all four git dependencies to
[`7f3e04f7cfeb2c31eea00f2330b0159572644828`](https://github.com/jevansaks/windows-rs/commit/7f3e04f7cfeb2c31eea00f2330b0159572644828),
published in `jevansaks/windows-rs`. It directly follows the native Flags fix
`0680de9b2b53985fd031b155cbc2c66c357ed10f`, which follows the previously adopted
`f62037957d26e2300e17ada4c5ca9a8f8a9d3b50` namespace-container fix, which follows
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

The test retains input, native-member, Flags, RDL, and WinMD evidence. It requires
nine NLS definitions, 41 source-valued members, 19 associations resolving to those
definitions, three CSTR fields owned by `COMPARESTRING_RESULT`, four native
Flags enums, five plain enums, and the independently owned DXGI vocabulary.
Existing evidence directories are rejected
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

## Native `flag_enum` adoption

**Upstream issue:** <https://github.com/microsoft/windows-rs/issues/5047>.

The self-contained `tests\fixtures\flag_enum.cpp` pairs an enum with actual
`[[clang::flag_enum]]` syntax and an otherwise equivalent plain enum. The
`scrape::tests::clang_flag_enum_preserves_flags_attribute` test checks the native
Clang cursor, production extraction and RDL emission, then compiled WinMD.
It requires `System.FlagsAttribute` only on the annotated enum while preserving
both enums' unsigned 32-bit backing types and member values.

**Known failure before adoption:** with producer
`f62037957d26e2300e17ada4c5ca9a8f8a9d3b50` and pinned libclang 22.1.8, Clang
recognizes `CXCursor_FlagEnum` only on the annotated enum, but extraction loses
the marker before the snapshot. Neither the emitted RDL nor the WinMD retains
flags. The plain-enum, backing-type, and member-value controls pass.

**Local workaround and adoption:** producer
`0680de9b2b53985fd031b155cbc2c66c357ed10f` records the native attribute as private
Snapshot source metadata keyed by the enum's `Origin`. Emission then uses the
existing RDL `#[flags]` and `System.FlagsAttribute` support. The public
`FactData` API is unchanged. The fix lives entirely in windows-rs; this repository
adopts its exact dependency revision rather than reparsing headers, inferring
flags from values, or maintaining a production enum-name list.

Source attributes preserve the declared representation, including signed
32-bit enums with negative values. The existing `DEFINE_ENUM_FLAG_OPERATORS`
and `RootPartition::with_flags` paths retain their established same-width
unsigned projection. The producer regressions distinguish these policies and
cover high-bit/all-bit values, plain enums, and same-leaf names under different
namespace owners with nonempty WinRT references.

The previously ignored desired C++ regression is enabled in normal runs:

```powershell
cargo test --release --locked --manifest-path .\tools\rust\Cargo.toml `
    clang_flag_enum_preserves_flags_attribute -- --nocapture
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

From the adopted windows-rs checkout, run the source-attribute and existing-path
controls:

```powershell
cargo test -p windows-clang --test header_partitions `
    clang_flag_enum_preserves_partition_ownership_and_representation -- --nocapture
cargo test -p windows-clang --test checkpoint6 enum_flag_macro_controls_projection --quiet
cargo test -p windows-clang --test partitioned owner_flags_force_unsigned_flag_enum_projection --quiet
cargo test -p windows-clang --test language_features preserves_cpp_types_and_declaration_attributes --quiet
```

**Removal condition:** replace the local producer workaround with an adopted
upstream revision that passes the unchanged C++ regression, direct-RDL control,
producer representation/ownership controls, and the real-header NLS gate above.
Keep these tests enabled; removing the fork pin alone is not evidence that the
source marker survives.

## Converging RetVal source annotations

**Upstream issue:** not filed. The duplicate was reproduced on the adopted fork
`0680de9b2b53985fd031b155cbc2c66c357ed10f`; a public-upstream repro is not claimed.

**Source and impact:** MIDL `[retval]` comments and converted `_Out_retval_`
annotations can independently mark the same parameter. Previously both markers
were emitted, producing two identical `#[retval]` entries in RDL and two physical
`RetValAttribute` instances. This is duplicate emission, not a disagreement about
the native output contract or a reason to change a signature.

**Local fix and adoption:** producer
[`7f3e04f7cfeb2c31eea00f2330b0159572644828`](https://github.com/jevansaks/windows-rs/commit/7f3e04f7cfeb2c31eea00f2330b0159572644828)
coalesces only those two RetVal sources during parameter-attribute emission.
Both source channels remain represented in the snapshot. No global annotation
deduplication, header rewrite, or wrapper implementation is introduced.

**Standalone repro and verification:** `tests\fixtures\retval_sources.cpp` uses
the checked-in capture headers and four COM property methods: both channels,
MIDL-only, annotation-only, and an ordinary output. The consumer regression checks
exact RDL and physical WinMD counts of 1/1/1/0, all output directions, and retained
`SpecialName`. Set `WIN32METADATA_RETVAL_OUTPUT_ROOT` to a fresh output directory
to retain the fixture, RDL, WinMD, and observations.

```powershell
cargo test --release --locked --manifest-path .\tools\rust\Cargo.toml `
    retval_source_channels_emit_one_attribute -- --nocapture
```

The producer also checks both extracted source channels explicitly:

```powershell
cargo test -p windows-clang --test annotations duplicate_retval_sources_emit_one_attribute -- --nocapture
```

**Removal condition:** adopt upstream handling that passes the unchanged
dual-channel, single-channel, and ordinary-output controls, preserving native
signatures and other attributes. Retain the regression when retiring the fork
patch.
