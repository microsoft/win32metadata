# Windows-rs Pipeline Wrapper Plan

## Goal

Make `win32metadata` and the reusable `Microsoft.Windows.WinmdGenerator` SDK thin
orchestration layers over the public `windows-clang`, `windows-rdl`, and
`windows-metadata` Rust libraries. Preserve the existing Win32 metadata contract,
partition namespaces, diagnostics, and downstream MSBuild entry points while
removing duplicate scraper and emitter implementations.

The annotation specification is being reviewed separately and is a prerequisite
for enabling annotated SDK header patches in the shipping pipeline.

## Acceptance principles

- Preserve the existing public WinMD API surface and partition namespace layout
  unless a reviewed delta is explicitly accepted.
- Keep the MSBuild targets and properties used by `win32metadata`,
  `wdkmetadata`, and external WinmdGenerator consumers.
- Invoke Rust through versioned command-line tools. Do not create a C ABI or
  duplicate the Rust APIs in C#.
- Keep generated RDL under `obj` initially. Committing RDL can be evaluated
  separately after pipeline equivalence is established.
- Pin windows-rs crate versions and provision dependencies through approved
  repository feeds and build images.
- Introduce the new path behind explicit properties until aggregate WinMD
  validation is complete.

## Proposed architecture

The existing MSBuild SDK remains the public wrapper:

1. `ScrapeHeaders` invokes a small Rust executable backed by `windows-clang`.
2. Header output is RDL, partitioned by defining SDK header.
3. `ScrapeConstants` remains unchanged until windows-clang macro parity is
   measured.
4. `EmitWinmd` invokes a small Rust executable backed by `windows-rdl` and
   `windows-metadata`.
5. Cross-architecture merge and namespace routing use
   `windows-metadata` rather than the current Roslyn syntax-tree merger.

The first implementation uses one Rust package with focused commands so Cargo
dependency compilation and packaging are shared.

## PR stack

### PR 0: Annotation specification

Already in review. Land the stable annotation vocabulary before enabling patched
headers in the shipping generator.

### PR 1A: RDL fidelity harness

- Add a pinned Rust wrapper package.
- Add a non-shipping WinMD -> RDL -> WinMD round-trip command.
- Measure unsupported or normalized metadata forms with existing integrity tests
  and API-diff tooling.
- Produce the namespace/type routing data needed by later stages.

This PR changes no shipping output.

### PR 1B: Import-library wrapper

- Replace the duplicate COFF import-library reader with `windows-rdl::implib`.
- Compare generated function-to-library mappings with the existing output.
- Keep the current MSBuild task contract.

### PR 1C: Emitter and architecture merge

- Compile generated RDL with `windows-rdl`.
- Merge x86, x64, and arm64 metadata with `windows-metadata`.
- Reproduce current namespace routing and assembly identity.
- Enable with an opt-in MSBuild property and retain the legacy emitter.

### PR 1D: Header scraper pilot

- Add `windows-clang` and approved libclang provisioning.
- Scrape one representative partition through the Rust wrapper.
- Map existing partition include/traversal configuration to public
  windows-clang filters and scopes.
- Upstream missing general-purpose capabilities to windows-rs rather than
  reimplementing its parser.

### PR 1E: Scraper rollout

- Expand the Rust scraper across all partitions and architectures.
- Remove the legacy ClangSharp and Roslyn implementation after equivalence.
- Preserve targeted partition builds and MSBuild-formatted diagnostics.

### PR 1F: Constants and remaining utilities

- Evaluate windows-clang macro output against `ConstantsScraper`.
- Replace only after parity is demonstrated.
- Move remaining metadata inspection to `windows-metadata::reader` where useful.

### PR 2.x: SDK header patches by partition

- Generate one cumulative patch per header.
- Group patch artifacts into reviewable partition or closely related partition
  families.
- Base each PR on the landed wrapper pipeline and annotation specification.
- Require clean patch replay and targeted partition generation.

Headers shared by multiple partitions must have a single owning PR. Later PRs
depend on that owner rather than duplicating the patch.

### PR 3: Aggregate WinMD convergence

- Build PR 1 and every PR 2.x together.
- Compare against the released WinMD with integrity tests and API diff.
- Classify every delta as intended, normalization-only, tooling defect,
  annotation-spec defect, or header-patch defect.
- Iterate in the owning PR until no unexplained deltas remain.
- Merge partition PRs only after the aggregate result is accepted.

## Known gaps to resolve

- Existing `--remap`, `--with-type`, and traversal behavior do not have direct
  public windows-clang equivalents.
- Current partition namespaces must be reconstructed using namespace routing.
- RDL has documented normalization and lossless-round-trip limits, especially
  unspecified parameter direction and attributes on void return rows.
- windows-clang's libclang version and dependency provisioning must comply with
  repository build policy.
- Downstream WinmdGenerator consumers require compatibility validation, not only
  successful Win32 generation.

## Current work

PR 1A is the active slice. Its round-trip result will determine the concrete
compatibility backlog before the shipping emitter or scraper is changed.

The initial wrapper compiles successfully with Rust 1.96. Local execution is
currently blocked by Windows Defender classifying the newly built unsigned Rust
executable as potentially unwanted software. The same command must be exercised
on an approved CI image or after the binary is approved; this does not affect
the existing shipping pipeline.
