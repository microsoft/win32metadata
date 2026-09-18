# Approved projection policy replay

This is a new comparison policy, not a revision of the historical proof.
`REPORT.md`, commit `4eb2583e06e41560a05a048c1dabb05c230ea32c`, and
`final-f320e134-r3` retain their original 23 equal / 2 improved-only / 48 review
method result. No header, generated metadata, or original evidence is rewritten.

## Version and approval

`scripts\ProjectionPolicy.psd1` declares policy `win32-projection` version
`1.0.0`, approved by the user on **2026-09-18 at 14:00:44 -07:00**, relayed by
coordinator session `86e8578e-2ddd-45d2-886f-16252f02ec2c`.
Each use retains that approval, rule ID, exact explained JSON paths, native AST
capture hash, source locations/bytes, and relevant complete metadata definitions.

| Rule ID | Disposition | Required evidence |
| --- | --- | --- |
| `sdk-guid-system-guid/v1` | Projection-equivalent | Runtime `System.Guid` identity; actual SDK `GUID` / `_GUID` from `guiddef.h`; all four fields, offsets, 16-byte size and alignment; identical pointer/array shape and native ABI |
| `utf16-const-pwstr-pcwstr/v1` | Projection-equivalent | One same-level `ConstAttribute` on `PWSTR`; actual `PCWSTR` wrapper with required pointee const; source-backed null-terminated WCHAR pointer aliases and 16-bit WCHAR |
| `native-regsam-uint32/v1` | Expected improvement | Scalar UInt32 and actual native REGSAM; SDK REGSAM -> ACCESS_MASK -> DWORD -> unsigned long declarations; emitted REGSAM -> ACCESS_MASK -> UInt32 wrappers |

The first two are user-approved projection contracts, **not raw equality or a
claim that a particular third-party projection implements them**. REGSAM
remains a native-identity improvement, not a synthetic enum association.
Unrelated attributes, SAL directions, optionality, buffer counts, ownership,
closers, widths, conventions and layouts are not explained by these rules.
Missing definitions, corrupt source provenance and cyclic aliases fail closed.

## Reusable entry points

Dot-source `scripts\Compare-ProjectionPolicy.ps1` alongside the existing
effective-contract reader:

- `New-ProjectionPolicyEvidence` retains a hash-pinned independent native
  capture and source bytes. Supply the capture hash from the generation
  manifest, selected SDK root/version, architecture and a new output directory.
- `Compare-ProjectionPolicy` accepts the before/after `Effective-Method`
  contracts, corresponding **raw** method rows and snapshots, native evidence,
  and the effective reader's `ValidationIssues`. It returns every difference,
  separate explanations/explained paths, residuals, rejection reasons and
  disposition. It does not modify inputs.
- `Get-ProjectionGuidProof`, `Get-ProjectionStringProof` and
  `Get-ProjectionRegsamProof` are the bounded type/slot proof routines. Their
  native facts must be independently captured, not derived from candidate
  metadata. The current method adapter handles imported Winapi functions;
  it does not close COM, callback, field or entire-header obligations.

The adapter consumes previously verified same-level const-encoding
normalization. Its raw method rows still identify the original qualified
metadata types. Previous approved improvements are combined by the replay
caller, not swallowed by a blanket equivalence result.

```powershell
.\scripts\Replay-PowrprofProjectionPolicy.ps1 `
  -OriginalEvidenceDirectory <immutable-final-f320e134-r3> `
  -OutputDirectory <new-policy-evidence-directory>
```

The runner pins the original manifest, verifies all original artifact hashes
and actual image identities, then recomputes all 73 methods on x64, x86, ARM64
and merged images. Recomputed raw and effective differences must match the
original ones exactly before any new rule is applied. Merged use of the x64
native capture additionally requires byte-identical original candidate images.
The new manifest binds unchanged images to the exact new policy, implementation
files and boundary results. No compilation or metadata generation is involved.

## Method dispositions

Each architecture has the same result, without changing a raw or effective
difference from the original proof:

| Disposition | Methods per image |
| --- | ---: |
| Equal under the existing comparison rules, no new policy needed | 23 |
| Projection-equivalent under the newly approved policy | 37 |
| Expected improvement, including mixed projection/improvement cases | 13 |
| Unexplained or rejected method contracts | 0 |
| **Total** | **73** |

The 13 improved methods comprise the two earlier improved-only methods, nine
methods whose approved status-return improvements now coexist with explained
GUID identities, and the two REGSAM methods. All **48** previously residual
methods receive an explicit disposition, not a blanket ignore rule.

Per image there are **90 GUID uses, four const-string uses, and two REGSAM uses**.
Every occurrence has a separate rule ID, source/definition proof, and explained
paths in the per-method report. Raw metadata token/namespace/schema differences
remain available in `rawDifferences`; rule paths address `effectiveDifferences`.

The comparison tests comprise **six positive cases using actual decoded method
contracts and 66 deliberately mutated negative cases**. They cover pointer and
array shape, native/member width and alignment, runtime/native type identity,
const level and UTF-16 storage, complete scalar aliases, missing references and
associations, source hashes, calling convention, added slot/type properties,
and unrelated SAL/count/ownership/error/availability changes. These are
comparison-boundary tests, not newly compiled header mutations.
The existing **126 native-improvement tests** are rerun unchanged.

The verified replay evidence directory is:

```text
C:\Users\jevansa\.copilot\session-state\ac7b652c-c8c0-40c2-8251-946330986647\files\powrprof\projection-policy-v1-final-r2
```

Its `manifest.json` SHA-256 is
`21A6964C761417FCB032269A943B81012C352E95BAEA2B15C5CB001CDB934135`.
The manifest retains 36 new artifact hashes, nine executed implementation hashes,
all 16 original decoded-image identities, the reference identity, and the
original manifest pin. All 341 original artifact hashes remained unchanged.
The initial `run1` is diagnostic evidence; `final` was stopped before completion
to correct a PowerShell dictionary-grouping error in rule-use summaries.
Only `final-r2` is the verified handoff.

## Other obligations remain separate

The 157 non-method ledger rows are preserved without reclassification. They
include 94 equal, 36 expected improvements, 14 review-required rows and 13 source
additions requiring review. Tags and typedef declarations remain distinct
source rows, not duplicate runtime-type claims. Original per-architecture
dependency/type reports remain authoritative unchanged evidence.

Neither closing the 48 method residuals nor replaying 292 method comparisons
proves whole-header or whole-SDK completion. Rollout and its broader obligation
ledger belong to the integration session.
