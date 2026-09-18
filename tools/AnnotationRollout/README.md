# SDK annotation rollout bootstrap

This is the restartable **inventory/controller bootstrap**, not a full-SDK
conversion or a passing semantic report. It does not modify SDK headers or use
legacy facts as production generator inputs. The cumulative draft is #2349,
based on `user/jevansa/windows-rs-pipeline-wrapper` (#2303).

The current project selects `Partitions\**\main.cpp`: 321 translation units.
The initial lexer found 1,397 distinct direct include spellings and resolved
1,358 distinct source headers against the pinned SDK, partition-local headers,
and current local include roots. One compiler-resource include is classified
separately; 41 unresolved direct include occurrences remain explicit. The source
catalog contains 7,897 header/IDL/provider alternatives; **that catalog
is not the conversion denominator**. It includes 4,581 selected-SDK source
records, 3,285 repository MIDL/compatibility alternatives, 27 additional headers,
three include helpers, and one partition-local header. Unrelated SDK/CRT/WinRT catalog records are not
implicitly selected for migration.

`selection` distinguishes `direct-root`, observed `transitive`, and
`catalog-only` records. Compiler resource headers are recorded separately.
Native captures enlarge the observed consumer closure; they do not prove that
every condition, generated declaration, or reference/legacy obligation has
been reconciled. Owner assignment is a deterministic queue owner; metadata
namespace and shared-definition ownership remain explicit semantic obligations.

## Entry points

The controller is a dependency-free .NET 10 application (apart from the
repository's existing build/versioning infrastructure):

```powershell
dotnet run --project tools\AnnotationRollout -c Release -- self-test

.\scripts\Invoke-AnnotationRollout.ps1 bootstrap `
    -StateDirectory <new-state-directory> `
    -EvidenceDirectory <new-immutable-evidence-directory> `
    -ToolPath <pinned-win32metadata-tools.exe> `
    -ResourceDirectory <libclang-22.1.8-resource-include-directory>

.\scripts\Invoke-AnnotationRollout.ps1 discover -StateDirectory <state> -Limit 1
.\scripts\Invoke-AnnotationRollout.ps1 verify -StateDirectory <state>
.\scripts\Invoke-AnnotationRollout.ps1 status -StateDirectory <state>
.\scripts\Invoke-AnnotationRollout.ps1 export -StateDirectory <state> -OutputDirectory <ledger-export>
```

The `ResourceDirectory` is the **include** directory, as in the immutable pilot.
The controller supplies its parent as clang's `-resource-dir`. It uses the
exact target triple, eight wrapper arguments, and include order; it does not
invent WINVER, NTDDI_VERSION, UNICODE, or packing defines.

State is local to the worktree named in the manifest. A replacement worktree
must bootstrap its own state, not continue commands against another writer's
repository path. Exported ledger references preserve the original evidence.
No historical acceptance status is imported.

## Checkpoints and failure handling

`current.json` is an atomically replaced pointer to a hashed immutable
`checkpoint-<sequence>-<unique-id>.json`. A checkpoint contains its journal,
manifest, input hashes, complete catalog, partition/header ledgers, active
process identity, exact next item, and capture references. The companion
`dashboard.md` is a replaceable readable view, not authoritative state.
OS-held exclusive file sharing prevents duplicate writers; an abandoned lock
file is harmless. A partial unpublished snapshot is never loaded and does not
block the next checkpoint.

`resume` checks PID **and process start time**, refuses a live worker, and
records an interrupted worker as blocked. It never labels partial evidence as
success. `retry -Partition <name> -Reason <concrete-investigation>` records an
explicit reason before allowing an identical retry fingerprint. A failing
partition does not prevent selection of other ready work.

Selection is deterministic: the known unsafe `wmcontainer.h` donor area,
shared Foundation/Registry roots, consumer fan-out, then ordinal partition
name. Each discovery invocation runs at most 16 partitions, sequentially
across x64, x86, and ARM64, checkpointing every architecture. It never starts
an aggregate SDK generation.

Changes to source inputs invalidate acceptance. `refresh -EvidenceDirectory
<fresh-directory>` recomputes the canonical census and reuses native captures
only when their own TU, architecture/arguments, compiler/scanner, include search
universe and transitive source hashes match. A comparer/policy-only edit does
not require a new native capture. Old outputs and failures are never deleted.

## Symbol and obligation evidence

Each capture retains `capture.json` and `symbols.jsonl`. Rows include native
USR/identity, declaration occurrence, signature, owner source/location,
parent/member path, architecture/TU context, recursive pointer/array/const
types, callback signatures, layout/bitfield facts, enum values, annotations,
and macro/parameter tokens. Native identity and declaration occurrence are
separate: redeclarations must not disappear through name-only deduplication.
Every row has explicit pending semantic-family obligations. Counts are
**TU/architecture occurrences**, not deduplicated full-SDK symbol coverage.

The current scanner inventories active canonical conditions. Source conditional
directives and pending `availability-condition` obligations remain in the
ledger; unvisited branches are not declared covered. Empty captures, unknown
source files, compiler errors, missing architectures, changed evidence,
duplicate ledger identities, and inconsistent row counts cannot be accepted.

`accept -Disposition <file>` is fail-closed scaffolding for future verified
per-header reconciliation. It requires every discovered symbol/family
disposition, all consumer/architecture captures, nine gates on x64/x86/ARM64
and merged metadata, actual mutation controls, hashed evidence, and exact
approved policy rules explaining every retained raw difference. It cannot
close an empty inventory or accept a compile-only result. Pins currently
contain **no registered policy rules**: the separately owned approved-policy
implementation must be integrated explicitly.

## Remaining integration work

The bootstrap is deliberately not a claim that the first implementation
milestone's complete semantic universe has already been discovered:

- Resolve missing direct roots against current generation's additional,
  external-package, MIDL and compatibility sources without silently restoring
  obsolete APIs.
- Complete the partition/architecture discovery sweep and reconcile public
  closure, alternate conditions, MIDL, and native source ownership.
- Decode/reconcile the pinned published reference and the 406 retained audit
  inputs (405 legacy source files plus the reference). Capturing legacy files
  is not per-entry semantic mapping.
- Implement/cache partition control/candidate WinMD/RDL generation and
  comparison. The present cache is for **native discovery**, not generated
  metadata. Policy-only changes must replay immutable metadata comparisons.
- Supply real semantic gate adapters and per-symbol expected/actual contracts,
  shared-definition composition, negative controls, and residual-gap ledgers.
  No header has received a terminal disposition from this bootstrap.

One cumulative best-effort conversion sweep precedes the final user review.
Residual gaps/additions/differences stay OPEN rather than being normalized away.
Large evidence and checkpoints remain outside Git; checked-in compact ledgers
are snapshots with hashes/references, not replacements for that evidence.

## First real discovery checkpoint

The bounded `Mf` smoke retained 157,181 x64, 156,633 x86 and 156,679 ARM64
declaration-context rows, with 2,029,978 / 2,023,075 / 2,023,621 **pending**
symbol/family checks respectively. These include transitive source facts and
macro definitions, not just public APIs; they are not a full-SDK unique-symbol
denominator or evidence of conversion. The observed selection is 1,418 source
records: 1,358 direct roots plus 60 additional observed transitive records.

All three captures are correctly **blocked**: raw SDK `dxva9typ.h:266` produces
six constant-expression diagnostics, and implicit MSVC 14.51.36231 headers
were discovered outside the registered provider catalog. The exact compiler
arguments, included-file hashes, diagnostics and partial symbol inventories
remain in the capture manifests. Neither issue is silently normalized or
treated as a tooling defect without source-materialization triage.

The next deterministic discovery item is Foundation. No further item was
started by the bootstrap owner. The replacement integration owner should
materialize the intended source providers before a broad sweep:

```powershell
# Existing repository pipeline; inspect dependencies first. This generates
# an OBJ overlay, recompiles MIDL and applies pre-/post-MIDL patches.
.\scripts\RecompileIdlFilesForScraping.ps1
```

The bootstrap's raw selected-SDK control does **not** stand in for that
post-MIDL candidate. The existing pipeline also restores selected historical
compatibility/WinHv headers; those choices require explicit current-scope
reconciliation, not inherited completeness. The native controller currently
has no prepared-overlay CLI option. Adding provider selection/materialization,
pinning implicit compiler support inputs, and then generating cached
control/candidate metadata are remaining integration tasks.
