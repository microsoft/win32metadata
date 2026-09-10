# Windows-rs Pipeline Wrapper Plan

## Goal

Make `win32metadata` and the reusable `Microsoft.Windows.WinmdGenerator` SDK thin
orchestration layers over the public `windows-clang`, `windows-rdl`, and
`windows-metadata` Rust libraries.

The annotation specification is being reviewed separately and is a prerequisite
for enabling annotated SDK header patches in the shipping pipeline.

## Acceptance principles

- Prefer a small, working pipeline over compatibility with legacy configuration.
- Accept that the first generated WinMD will differ. Measure and refine it after
  the complete path works.
- Invoke Rust through versioned command-line tools. Do not create a C ABI or
  duplicate the Rust APIs in C#.
- Keep generated RDL under `obj` initially. Committing RDL can be evaluated
  separately after pipeline equivalence is established.
- Pin windows-rs crate versions and provision dependencies through approved
  repository feeds and build images.
- Treat SDK headers, import libraries, and the shift-left annotation vocabulary
  as the metadata source. Do not carry forward API-specific RSP or JSON sidecars.

## Proposed architecture

The first implementation is one Rust command:

```text
partition main.cpp files + SDK include root + SDK import libraries
    -> windows-clang
    -> generated RDL under obj
    -> windows-rdl/windows-metadata
    -> output WinMD
```

Its required inputs are intentionally limited to the selected partitions, SDK
locations, target architectures, and output path. Existing scraper/emitter RSP
files and JSON metadata databases are not inputs.

## PR stack

### PR 0: Annotation specification

Already in review. Land the stable annotation vocabulary before enabling patched
headers in the shipping generator.

### PR 1: Minimal windows-rs generator

- Add a pinned Rust executable using `windows-clang`, `windows-rdl`, and
  `windows-metadata`.
- Accept one or more existing partition `main.cpp` files.
- Locate declarations through the supplied SDK include root and recover imports
  from the supplied SDK library root.
- Generate RDL as an untracked intermediate and emit a WinMD.
- Add one inner-loop script that restores/builds prerequisites and produces the
  WinMD from a selected partition set.

The PR is complete when the inner loop produces a WinMD from representative
partitions. API equivalence is explicitly deferred.

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

- windows-clang's libclang version and dependency provisioning must comply with
  repository build policy.
- Some declarations currently depend on information not yet present in headers.
  Those become annotation or windows-rs tooling follow-ups rather than inputs to
  this first wrapper.

## Current work

PR 1 is active. The pinned `windows-rdl` wrapper successfully round-tripped the
released `Windows.Win32.winmd`, and the rebuilt WinMD passes the existing
duplicate-type, duplicate-import, duplicate-constant, empty-delegate,
pointer-to-delegate, architecture, and namespace-cycle checks. The active work
is the direct partition-to-WinMD command.

The direct command now produces x64, x86, and arm64 WinMD output from a selected
partition set. Two upstream/tooling follow-ups were exposed:

- `HtmlHelp` reaches `_com_ptr_t<FontEvents>` through `infotech.h` and MSVC
  `comdef.h`; windows-clang 0.100.0 currently treats that helper type as
  unhandled.
- Architecture merge currently duplicates architecture-dependent constants in
  the flat `Windows.Win32.Apis` container.
