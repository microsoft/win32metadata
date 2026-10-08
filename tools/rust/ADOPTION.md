# Producer adoption ledger

Core extraction, RDL, and metadata algorithms belong in windows-rs. This repository
owns dependency adoption, SDK input configuration, annotation capture, and packaging.

`Cargo.toml` and `Cargo.lock` currently pin all four git dependencies to
[`af9baa81465036b8c64fb52c68226c4cc3f76c3e`](https://github.com/jevansaks/windows-rs/commit/af9baa81465036b8c64fb52c68226c4cc3f76c3e),
published in `jevansaks/windows-rs`. Its native Color identity correction follows
`2ee8ba6bb766a5a9b919f7b73222e6e01b981968`, whose source-identified interface,
provider-IID, and macro-probe corrections follow `0138a2079ecce580789a072b52ea6f25df77a937`,
whose retained-pointer SAL direction correction
follows `60b728861e6f6a0f25a52012934ca81041e710c8`, whose cross-input associated-enum ownership
correction follows `6f9dcaef699630aacbae363b7f9766afc84b2d41`, whose explicitly terminated named-scalar
correction follows `ab1e9593dd421d3aa0d6a3710557b7789199d004`, whose redeclaration correction follows the
native-opaque capability `1dd86adb880fb4b1dc4ebe5f0dd2f6dc45b75355` and AssociatedEnum
closure revision `15ba1b7f96c770b9d425ebca00a3a73f74bb004e`, whose fixes follow
the RetVal fix `7f3e04f7cfeb2c31eea00f2330b0159572644828` and native Flags fix
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

## Native embedded storage and external identity

**Upstream issue:** not filed; this corrects the local pipeline producer.

Producer `af9baa81` keeps an unsupported native declaration's exact identity from
falling back to an unrelated external type with the same leaf name. In particular,
native GDI+ `Color` must not become WinRT `Windows.UI.Color`. Explicitly qualified
WinRT Color references remain external.

In selected header-partition dependency closure, uniformly protected storage with
no bases or virtual methods can be retained as a native record when embedded in
another record. Direct `Color` by-value ABI and transitive outer `ColorMap`
by-value ABI remain rejected. The producer's physical x86/x64 fixtures retain local
ARGB/Color/ColorMap identities, fields and layout alongside the explicit WinRT
control. This is not a general relaxation for C++ class ABI or proof of actual SDK
Color output; that requires the coalesced normal product image.

The checked-in GDI+ import fixture now stages only the admitted
`_Win32_NativeOpaque_` annotation on `GdiplusMatrix.h`, using a test-only Clang
VFS overlay that preserves the original logical header path. Normalized source
hashes bind both the pristine and annotated headers; the SDK mirror is unchanged.
The bare-header negative must still reject unsupported native `Matrix` rather
than falling back to a same-leaf reference.

The positive retains all 629 import-backed functions, native calling conventions,
parameter counts and geometry checks on x64 and x86. It additionally binds the
included opaque class definition, traversed forward declaration and `GpMatrix`
typedef by canonical locations, translation unit and native namespace parent.
Physical metadata must contain one empty nominal `Matrix`, with `GpMatrix` and
both creation/deletion pointer signatures reaching that emitted type. Under the
fixture's unchanged 321 policies and namespace authorities, the included-only
definition uses the default `Windows.Win32` namespace; that is a current-policy
assertion, not an OLD namespace compatibility claim or a new routing rule.

**Removal condition:** adopt an upstream revision preserving exact native/external
identity, embedded-only storage eligibility and the direct/transitive ABI negatives.

## Source-identified interfaces and bounded macro probes

**Upstream issue:** not filed; these correct the local pipeline producer.

The coalesced `2ee8ba6b` revision retains identified native-namespaced interfaces
as public roots in explicit header partition planning. Original source names and
translation-unit identity survive collision scoping so provider-local interfaces
keep their own IID values and methods. Unrelated same-spelling IID constants
remain independent; shared GUIDs do not merge distinct interfaces. Legacy
emission behavior is unchanged.

Producer regressions
`identified_native_namespaced_interfaces_remain_public_roots` and
`colliding_identified_native_interfaces_retain_provider_iids` in
`crates/libs/clang/tests/header_partitions.rs` check RDL and physical metadata,
including methods, inheritance, GUIDs, nonempty references and negative controls.
Consumer SAL and independent WinHTTP/WinInet controls remain separate.

Macro evaluation now requires a complete initializer expression and localizes
probe diagnostics to affected declaration ranges. Previously accepted diagnostics
are matched by message and location, not ignored indiscriminately. Unlocalized
cascades still use isolation. In the producer's fixed 2,050-candidate mixed fixture,
the earlier `e3b63cb0` used one synthetic translation unit but admitted two partial
constants; `2a7a7ef` used 2,186 translation units and recovered no values;
`2ee8ba6b` uses one translation unit, no retries, and preserves the 2,040 correct
survivors. These are bounded fixture measurements, not full-SDK timing claims.

This revision also contains the typed COFF contract reader and its machine,
malformed-input and anonymous/BigObj handling. The consumer still uses the legacy
library transport and leaves `EmitOptions::native_imports` unset. Enabling typed
contracts, ordinal/name modes and per-architecture machine filtering is a
separate behavior checkpoint; pinning this revision does not recover imports by
itself.

```powershell
cargo test --release --locked --manifest-path .\tools\rust\Cargo.toml -- `
    --skip checked_in_authority_compile_environment_sources_parse
.\scripts\Test-GeneratorSdkPackage.ps1
```

Two existing producer `test_rdl` parameter-roundtrip failures remain tracked.
Neither this adoption nor passing consumer/package controls waives those failures
or establishes a clean full three-architecture strict product build.

**Removal condition:** adopt an upstream revision preserving source-identified
interfaces, provider-local IID identity, complete macro expressions and bounded
mixed-cohort recovery, with the existing physical metadata controls.

## Explicit direction on retained canonical pointer aliases

**Upstream issue:** not filed; this corrects the local pipeline producer.

Producer `0138a207` reasons about the final planned projection, including the exact
retained declaration, when deciding whether pointer syntax already carries output
direction. A retained named `PVOID` or `LPVOID` needs an explicit RDL `#[out]`;
treating its source spelling as an emitted `*mut void` incorrectly defaults the
physical parameter to Input. Direct canonical `*mut void` behavior is unchanged.
The SDK SAL capture header, namespace policies and cleanup annotations are unchanged.

The producer's `retained_canonical_pointer_output_sal_preserves_direction`
regression uses actual `_Out_writes_bytes_to_` / `_Out_opt_` spellings in a synthetic
HeaderPartitionPlan fixture, with fact, RDL and physical WinMD assertions. The
existing consumer `sdk_sal_capture_preserves_parameter_contracts` fixture additionally
checks both retained aliases, byte-count relationships, optional output counts,
explicit Input controls and the existing direct-pointer controls across two SAL
header sources and three include orders. On `60b`, physical
`CaptureNamedLpvoidOutput` incorrectly has `ParamAttributes(1)` (Input), not
`ParamAttributes(2)` (Output).

```powershell
cargo test --release --locked --manifest-path .\tools\rust\Cargo.toml `
    sdk_sal_capture_ -- --nocapture
.\scripts\Test-GeneratorSdkPackage.ps1
```

This adoption is separate from normal-build wiring at consumer `2fc829493f`.
That wiring's fixtures and package were tested on `60b`. The prior actual SDK
ReadProcessMemory first-loss evidence and these source-spelling fixtures are
distinct; neither fixture is a new full SDK image or closure of other metadata
integrity diagnostics.

**Removal condition:** adopt an upstream revision preserving explicit direction
on the same planned named aliases, retaining the physical metadata controls.

## Cross-input associated-enum ownership

**Upstream issue:** not filed; this corrects the local pipeline planner.

Producer `60b728861e6f6a0f25a52012934ca81041e710c8` keeps a compatible enum
provider's existing traversed ownership when an annotated consumer is extracted
in another translation unit. Dependency copies must not acquire a competing
consumer-header route. For a dependency-only enum with an explicit namespace
authority, unrelated partition settings must not create a false conflict.
Different physical providers, incompatible declarations, and genuine competing
ownership remain errors.

Provider compatibility preserves the declared enum representation. Clang's
signed `i64` constant slot can contain either `-2147483648` or `2147483648` for
the same unsigned 32-bit `0x80000000` member. The producer compares such values
using the existing representation-width emission rule, not signed-value equality
or a name-based exception. Signed representations and differing member values
remain distinct.

The opt-in `sdk_partitioned_associated_enum_routes_across_inputs` regression
uses three focused translation units over unchanged SDK headers. It separates
direct enum providers from annotated consumer headers and gives the two VARENUM
consumers separate inputs. It retains the checked-in logical owner policies,
namespace authorities, production function-selection exclusions and import
annotations, and nonempty WinRT references. Both the original 180-library map
and the supplemented 247-library map are tested against the **same snapshot**,
through `HeaderPartitionPlan::emit_with_options`, not just initial planning.

On `6f9dcaef`, both maps reproduce the same seven ownership ambiguities. Adding
the supplemental archives is therefore not required to expose these failures
in this real-header topology. Successful emission must preserve all seven
physical definitions, native member values and widths, five Flags/two plain
enums, consumer associations and unique routes. A deliberately conflicting
provider owner must still be rejected. Raw source facts remain separate from
representation-aware expected metadata values.

The normal SDK-free
`identical_associated_enums_from_different_headers_remain_ambiguous` control
uses byte-identical enum headers with equal extracted representations and member
values at different physical paths. Their competing ownership must remain one
explicit ambiguity; equal values must not turn them into the same provider.

```powershell
$env:WIN32METADATA_ENUM_ROUTES_INPUT_ROOT = (Resolve-Path .\cohort\generation\WinSDK).Path
$env:WIN32METADATA_ENUM_ROUTES_OUTPUT_ROOT = Join-Path $PWD "obj\enum-routes-check"
cargo test --release --locked --manifest-path .\tools\rust\Cargo.toml `
    sdk_partitioned_associated_enum_routes_across_inputs -- --ignored --nocapture
```

Use a new evidence directory whose parent exists. This regression is not a full
SDK extraction or a replacement for the producer's signedness, source identity,
exclusion, authority, and genuine-conflict negative tests.

**Removal condition:** adopt an upstream revision with equivalent generic
cross-input ownership and authority behavior while retaining these regressions.

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

For native metadata-off builds, the annotation header supplies `_Out_retval_`
and `_COM_Outptr_retval_` only when the SDK has not defined them, using `_Out_`
and `_COM_Outptr_` respectively. Existing SDK definitions are preserved; strict
metadata-on capture overrides remain unchanged.
`retval_capture_supports_native_off_headers` covers missing and existing macros.

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

## Cross-input AssociatedEnum dependency closure

**Upstream issue:** not filed. This was reproduced on the local pipeline fork;
public-upstream reproduction is not claimed.

**Source and impact:** the production Debug authority traverses `ImageHlp.h`.
Compatible declarations parsed from dependency-only `DbgHelp.h` in another
translation unit carry AssociatedEnum annotations and enum providers. Before
adoption, the 13 physical field/parameter association strings survived while
all eight referenced vocabulary definitions were absent.

**Local fix and adoption:** producer
[`15ba1b7f96c770b9d425ebca00a3a73f74bb004e`](https://github.com/jevansaks/windows-rs/commit/15ba1b7f96c770b9d425ebca00a3a73f74bb004e)
uses compatible annotated redeclarations across extraction inputs to retain
enum or typedef-to-enum providers. Dependency-only providers inherit the
resolved declaration owner; independently traversed providers retain their
routes. Existing exclusions, namespace authorities, remaps, Flags policy,
selected-function filtering, and conflict diagnostics still apply. Unrelated
included declarations do not become roots. This repository adds no closure
algorithm or header workaround.

The intermediate `49d1d4d86a0d9471d1f9c2b49923054849bc4a21` handled only
same-input providers and is not a sufficient adoption pin.

**Consumer verification:** the opt-in Debug regression reads the frozen
`Partitions\Debug\main.cpp` and its actual traversal settings. Only `ImageHlp.h`
is rooted in its public input; a separate input includes canonical `DbgHelp.h`
without rooting its declarations. One combined snapshot uses the production
header planner, native import-library selection, and nonempty WinRT references.
It requires eight physical Debug enums, their source member values and u32
widths, 13 bound associations, three Flags enums, and five plain enums:

```powershell
$env:WIN32METADATA_DEBUG_INPUT_ROOT = (Resolve-Path .\cohort\generation\WinSDK).Path
$env:WIN32METADATA_DEBUG_OUTPUT_ROOT = Join-Path $PWD "obj\debug-partitioned-check"
cargo test --release --locked --manifest-path .\tools\rust\Cargo.toml `
    sdk_partitioned_debug_retains_associated_enum_dependencies -- --ignored --nocapture
```

The fresh evidence directory retains both input texts, arguments, native enum
members, RDL, WinMD, and association readback. This is not a full SDK run.

Producer `header_partitions` regressions additionally cover duplicate cross-input
providers, field/parameter slots, signed plain enums, high-bit native Flags,
unrelated included-only negatives, selection, same-leaf distinct routes,
exclusions, authorities, remaps, forced Flags, and deterministic conflicts:

```powershell
cargo test -p windows-clang --test header_partitions associated_enum -- --nocapture
cargo test -p windows-clang --test header_partitions --quiet
cargo test -p windows-clang --quiet
```

**Removal condition:** adopt upstream closure handling passing the unchanged
producer ownership/eligibility controls and this cross-input native-header
regression. Do not remove the fork fix based on same-input or focused by-header
emission alone.

## Explicit pointer-only native class identity

**Upstream issue:** not filed. This is an explicitly opted-in local producer
capability, not a claim that arbitrary C++ class projection is now supported.

**Source and impact:** defined GDI+ implementation classes previously projected
as `void` even when the native APIs use distinct class pointers. The SDK bridge
now exposes `_Win32_NativeOpaque_`, placed after `class` and before the name on a
named non-COM class definition. It carries the valueless
`win32metadata:native_opaque` annotation only under Clang metadata generation.
Native metadata-off builds retain their original definitions and ABI.

**Local fix and adoption:** producer
[`ab1e9593dd421d3aa0d6a3710557b7789199d004`](https://github.com/jevansaks/windows-rs/commit/ab1e9593dd421d3aa0d6a3710557b7789199d004)
includes the capability introduced in
[`1dd86adb880fb4b1dc4ebe5f0dd2f6dc45b75355`](https://github.com/jevansaks/windows-rs/commit/1dd86adb880fb4b1dc4ebe5f0dd2f6dc45b75355)
to retain an empty nominal pointee through pointer, reference, and typedef paths.
It emits no class fields, methods, bases, layout, or native inheritance.
Unmarked implementation classes keep their existing projection. Marked by-value
uses fail preflight, including parameters, returns, containing fields, and arrays.
Forward declarations, structs, unions, templates, typedefs, functions, parameters,
COM classes, and markers with a payload are not valid annotation targets.
The wrapper does not reparse or special-case class names.

Clang can propagate a definition's marker onto a later unannotated redeclaration.
Revision `1dd86adb` rejected that valid source before RDL in actual GDI+ headers.
The adopted correction resolves the definition and accepts such a copied
attribute only when its original expansion lies inside that definition's source
extent. An explicitly annotated forward declaration remains invalid.

**Capture and regression:** `tests\fixtures\native_opaque.cpp` compares marked
base/derived classes with an equivalent unmarked virtual class and includes a
later unannotated redeclaration that reproduces the `1dd86adb` failure. The test checks
metadata-off native layout/inheritance assertions, empty physical TypeDefs,
constness and pointer depth, the plain void control, and four explicit by-value
rejections. Set `WIN32METADATA_OPAQUE_OUTPUT_ROOT` to a fresh evidence directory.

```powershell
cargo test --release --locked --manifest-path .\tools\rust\Cargo.toml `
    native_opaque_class_annotations_preserve_pointer_identity -- --nocapture
```

The opt-in real-header GDI+ gate reuses the existing production aggregate prefix,
12 traversal roots, nonempty WinRT references, and native library selection.
It retains the 629 import-backed functions, calling conventions, and geometry
layout/alias checks, then checks 22 nominal definitions and eight native pointer
slots. `GpMatrix` is verified against the actual emitted `Matrix` definition,
not assumed historical alias spelling.

```powershell
$env:WIN32METADATA_GDIPLUS_INPUT_ROOT = (Resolve-Path .\cohort\generation\WinSDK).Path
$env:WIN32METADATA_GDIPLUS_OUTPUT_ROOT = Join-Path $PWD "obj\gdiplus-opaque-check"
cargo test --release --locked --manifest-path .\tools\rust\Cargo.toml `
    sdk_partitioned_gdiplus_preserves_native_opaque_pointers -- --ignored --nocapture
```

This gate requires the marked native class definitions and the new capture
header. When comparing raw and patched cohorts, both arms must receive identical
capture-support bytes; that tooling-support delta is separate from the native
header annotations. Existing unmarked x64/x86 GDI+ tests remain unchanged in
their expected projection.

**Removal condition:** replace the fork implementation only with a producer
that passes these capture/native-header tests and the producer's `opaque_classes`
target, ownership, same-leaf namespace, pointer-typedef, callback, and by-value
controls. Preserve explicit opt-in and rejection semantics.

## Terminated native wide-string aliases

**Upstream issue:** not filed. This was reproduced on the local producer
`ab1e9593dd421d3aa0d6a3710557b7789199d004`.

**Source contract and first loss:** `_In_z_ const WCHAR*` already preserves
`input` and `null_terminated` in extracted facts. The native typedef has the
same 16-bit character type as `wchar_t`; capture is not missing an encoding
annotation. The old producer selected `PCWSTR` for a terminated direct scalar
pointer, but did not apply its existing named-scalar canonicalization to
`WCHAR` in that selector. Later fallback emitted the named case as `*const u16`.

**Local fix and adoption:** producer
[`6f9dcaef699630aacbae363b7f9766afc84b2d41`](https://github.com/jevansaks/windows-rs/commit/6f9dcaef699630aacbae363b7f9766afc84b2d41)
reuses that canonicalization only inside the existing explicit-null-termination
selector. It does not infer strings from
unannotated numeric pointers, change native declarations, or add capture
vocabulary, API-name special cases, or a wrapper-side type mapping.

**Regression:** `tests\fixtures\wide_z.cpp` compares terminated `WCHAR` and
direct `wchar_t` pointers with unterminated `WCHAR` and numeric `unsigned short`
controls. The production planner, with nonempty WinRT references, must emit
physical `PCWSTR` for the first two and retain const 16-bit pointers for the
other two. Input direction and native character width remain unchanged.
Set `WIN32METADATA_WIDE_Z_OUTPUT_ROOT` to a fresh evidence directory to retain
the facts, RDL, and WinMD.

```powershell
cargo test --release --locked --manifest-path .\tools\rust\Cargo.toml `
    named_wide_z_annotations_preserve_string_identity -- --nocapture
```

The opt-in real-header gate below reuses the GDI+ opaque-pointer gate's single
extraction and all its import, geometry, and nominal-type controls. It also
requires physical `PCWSTR` inputs for `GdipCreateBitmapFromFile` and
`GdipCreateBitmapFromFileICM`. Supply the same input/output variables as the
opaque-pointer gate, with a cohort containing the two `_In_z_` corrections:

```powershell
cargo test --release --locked --manifest-path .\tools\rust\Cargo.toml `
    sdk_partitioned_gdiplus_preserves_wide_filenames -- --ignored --nocapture
```

**Removal condition:** retain these regressions when adopting an upstream
revision with equivalent explicitly terminated named-scalar string selection.

## Native SDK import-library inputs

`--win32-sdk` appends `win32_headers::PARTITION_IMPORT_LIBS` after the unchanged
producer import list. The supplement contains explicit native SDK archives,
not function-to-DLL overrides or an enumeration of every library in a directory.
Existing first-wins resolutions and library-override preconditions are retained.
Archives exposing ambiguous provider entrypoints are not added merely because
some of their exports match missing SDK declarations.

The current import reader returns short-import symbol/DLL strings without
preserving ordinal or name-transformation semantics. An ordinal import's symbol
string does not establish that the DLL exports that name. Archive admission
therefore also checks the raw native import headers for every newly emitted
function; archives causing unsupported by-name emissions remain outside the
supplement. This change does not repair ordinal-import transport in the producer.

The normal tests compare every existing native symbol/DLL resolution, check
all newly resolved symbols for competing DLL providers, and reject missing
required archives and accidental discovery of unlisted files. Selection is
independent of the target architecture: it uses the supplied native import
corpus. The existing SDK pipeline supplies the pinned x64 import corpus for
all targets. This is not a claim about availability of archives in other SDK
architecture packages.

The opt-in `sdk_partitioned_required_libraries_restore_native_imports` gate
uses frozen partition inputs, the production header planner, and nonempty WinRT
references. Its test-only TSV contains five tab-separated columns: partition
owner, header path relative to `generation\WinSDK`, namespace, function name,
and native DLL. The inventory does not drive production selection.

```powershell
$env:WIN32METADATA_IMPORTS_INPUT_ROOT = (Resolve-Path .\cohort\generation\WinSDK).Path
$env:WIN32METADATA_IMPORTS_EXPECTED = (Resolve-Path .\native-import-expectations.tsv).Path
$env:WIN32METADATA_IMPORTS_OUTPUT_ROOT = Join-Path $PWD "obj\native-import-check"
cargo test --release --locked --manifest-path .\tools\rust\Cargo.toml `
    sdk_partitioned_required_libraries_restore_native_imports -- --ignored --nocapture
```

It retains the complete new-provider multimap, native facts, baseline/candidate
RDL and WinMD, and every newly emitted import, including functions outside the
requested inventory. A legitimately empty baseline plan is recorded explicitly.
The checks preserve existing import names, conventions, signatures, method and
parameter attributes, and verify new imports against their native declarations
and providers. Representative signed, unsigned, and pointer-width controls cover
TAPI, cluster resource utilities, and iSCSI.

**Removal condition:** a future producer list may absorb these archives only
while preserving the tested resolution order, conflict checks, and native
header emission contracts.
