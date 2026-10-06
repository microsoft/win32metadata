# Producer adoption ledger

Core extraction, RDL, and metadata algorithms belong in windows-rs. This repository
owns dependency adoption, SDK input configuration, annotation capture, and packaging.

`Cargo.toml` and `Cargo.lock` currently pin all four git dependencies to
[`a71662f435eaf24dde7346b684cb4cffc64ca376`](https://github.com/jevansaks/windows-rs/commit/a71662f435eaf24dde7346b684cb4cffc64ca376).
This is the existing pipeline fork baseline, not an assertion that every historical
fork change has been upstreamed.

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
Double-NUL capture alone is not double-NUL emission; that requires the core fix below.

**Removal condition:** replace the bridge only when native annotation extraction
passes these same gates without it, including the absence of support-header APIs.

## Pending core adoption

Both defects were independently reproduced on public windows-rs
`143aa57cf5c96c140c69758948b46eb9a2d8ede7`. The current pin above does **not**
include their fixes. No core implementation is duplicated in this repository.

| Upstream issue and standalone repro | Required local fix | Adoption status | Removal condition |
| --- | --- | --- | --- |
| [microsoft/windows-rs#5041](https://github.com/microsoft/windows-rs/issues/5041), runnable nested-record fixture in the issue | Preserve enclosing TypeRef identity during RDL compilation and supported metadata copy/merge/roundtrip paths. | Awaiting the verified producer commit; not adopted. | Adopt an upstream revision containing the fix and retain nested-reference/roundtrip regressions. |
| [microsoft/windows-rs#5042](https://github.com/microsoft/windows-rs/issues/5042), runnable captured-annotation fixture in the issue | Carry captured `_NullNull_terminated_` from parameter facts through RDL to `NullNullTerminatedAttribute`, without changing string/pointer types. | Awaiting the verified producer commit; not adopted. | Adopt an upstream revision containing the fix and retain double-NUL and negative-control regressions. |
