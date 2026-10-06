# Producer adoption ledger

Core extraction, RDL, and metadata algorithms belong in windows-rs. This repository
owns dependency adoption, SDK input configuration, annotation capture, and packaging.

`Cargo.toml` and `Cargo.lock` currently pin all four git dependencies to
[`0a4d025f87a301eecf0eb9dce8bce8ae9e811eb9`](https://github.com/jevansaks/windows-rs/commit/0a4d025f87a301eecf0eb9dce8bce8ae9e811eb9),
published in `jevansaks/windows-rs`. Its parent is the existing pipeline baseline
`a71662f435eaf24dde7346b684cb4cffc64ca376`; this ledger does not claim that every
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

Both defects were independently reproduced on public windows-rs
`143aa57cf5c96c140c69758948b46eb9a2d8ede7`. Both local fixes are in the exact
adoption commit above; no core implementation is duplicated in this repository.

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
