# powerbase.h migration proof

This is a **single-header** migration experiment, not a full-SDK equivalence claim.
It deliberately starts from tooling commit
`b7ead1e6847d4c81f8e5b8b14a51350055f0d31a`, not the unverified aggregate header
patch series. No legacy metadata sidecar is an input to generation.

**Current result: not equivalent.** [REPORT.md](REPORT.md) separates completed
native/transport evidence, all five function comparisons, and the remaining
logical-contract blockers. Canonical generation and source provenance now pass.
The commands below reproduce gates; they are not
a statement that the final gate currently passes.

## Pinned inputs

| Input | Identity |
| --- | --- |
| Published reference | `Microsoft.Windows.SDK.Win32Metadata` `70.0.11-preview`, `Windows.Win32.winmd` |
| Reference SHA-256 | `6AEC29BE3359468D9EBA03C3AE932591B39960F1812B6D25D33C0D9F14A6D665` |
| Selected SDK and import-library packages | `Microsoft.Windows.SDK.CPP` and `.x64`, `10.0.26100.7705` |
| SDK header directory | `c\Include\10.0.26100.0` |
| Unmodified `powerbase.h` SHA-256 | `66082F57FF576850899FA3DEB4779C0B762163A70946D0BE4DF78F3A2A506FB2` |
| libclang | `22.1.8`, LLVM commit `ca7933e47d3a3451d81e72ac174dcb5aa28b59d1` |
| Rust dependencies | Exact, identical revisions for all three crates in `tools\rust\Cargo.toml` and `Cargo.lock`; recorded again in each manifest |

The reference is a published **legacy** WinMD. A freshly generated Rust control
is never substituted for it. `Generate-PowerbaseEvidence.ps1` checks the two
artifact hashes above, refuses to reuse an evidence directory, and rejects
unrecorded local Cargo path overrides.

## Scope and ownership

The native header contains five functions and two typedef declarators, no native
enum declarations, no exported data variables, and no API value macros:

| Native declaration | Required contract |
| --- | --- |
| `CallNtPowerInformation` | Original `NTSTATUS` spelling (SDK temporarily defines it as `LONG`); native `PVOID` buffers; optional input/output **byte** extents from parameters 2 and 4 |
| `GetPwrCapabilities` | `BOOLEAN`, output `PSYSTEM_POWER_CAPABILITIES`, last-error capture |
| `PowerDeterminePlatformRoleEx` | `POWER_PLATFORM_ROLE` return; unchanged `ULONG Version` with `POWER_PLATFORM_ROLE_VERSION` association |
| `PowerRegisterSuspendResumeNotification` | Unchanged `DWORD` return and flags, `HANDLE` recipient, `PHPOWERNOTIFY` output; associations and producer-specific cleanup |
| `PowerUnregisterSuspendResumeNotification` | Unchanged `DWORD` return and `_Inout_ HPOWERNOTIFY` parameter; no ownership on the input |
| `HPOWERNOTIFY` | Existing `PVOID` alias, not a new API-specific handle |
| `PHPOWERNOTIFY` | Existing pointer-to-`HPOWERNOTIFY` alias, not an additional pointer layer |

In the ordinary `windows.h`-first translation unit, `winuser.h` has already
defined the two typedefs under `_HPOWERNOTIFY_DEF_`. They are therefore native
dependencies, not declarations newly emitted from `powerbase.h`. The native test
also uses `NOUSER` plus `WIN32_LEAN_AND_MEAN` to exercise the valid header-first
configuration in which `powerbase.h` itself declares them.

The initial scoped Rust control emits exactly these seven dependency definitions:
`BATTERY_REPORTING_SCALE`, `HANDLE`, `HPOWERNOTIFY`,
`POWER_INFORMATION_LEVEL`, `POWER_PLATFORM_ROLE`, `SYSTEM_POWER_CAPABILITIES`,
and `SYSTEM_POWER_STATE`. Their full fields and enum members are part of the
evidence, not additional header-owned APIs. The native closure has 21 declaration
instances, including intermediate aliases and repeated compatible typedefs;
the snapshot retains each defining header and the exact alias chain.

The consolidated patch adds only these guarded metadata groups:

| Group | Member | Value and native provenance |
| --- | --- | --- |
| `POWER_PLATFORM_ROLE_VERSION` | `POWER_PLATFORM_ROLE_CURRENT_VERSION` | `winnt.h`'s `POWER_PLATFORM_ROLE_VERSION`: 2 for Windows 8+, otherwise 1 |
| `POWER_PLATFORM_ROLE_VERSION` | `POWER_PLATFORM_ROLE_V1` | 1, `winnt.h` |
| `POWER_PLATFORM_ROLE_VERSION` | `POWER_PLATFORM_ROLE_V2` | 2, `winnt.h` |
| `REGISTER_NOTIFICATION_FLAGS` (flags) | `DEVICE_NOTIFY_SERVICE_HANDLE` | 1, `winuser.h` |
| `REGISTER_NOTIFICATION_FLAGS` (flags) | `DEVICE_NOTIFY_CALLBACK` | 2, `powrprof.h` |
| `REGISTER_NOTIFICATION_FLAGS` (flags) | `DEVICE_NOTIFY_WINDOW_HANDLE` | 0, `winuser.h` |
| `REGISTER_NOTIFICATION_FLAGS` (flags) | `DEVICE_NOTIFY_ALL_INTERFACE_CLASSES` | 4, `winuser.h` |

These are synthetic groups required by the legacy obligations, **not claims that
the underlying native constants originate in this header**. The original macros
are restored after the enum declarations. The broad shared flags group does not
override the API documentation: `PowerRegisterSuspendResumeNotification` requires
`DEVICE_NOTIFY_CALLBACK`.

## Generate and inspect

The complete reproducible gate is:

```powershell
.\scripts\Test-PowerbasePilot.ps1 -EvidenceDirectory C:\evidence\powerbase-run
```

It generates both variants, verifies native contracts and source ownership, writes
the raw and effective comparisons, and exercises the negative controls. It
preserves all evidence and returns a failure if logical differences remain; a
successful transport test cannot turn that failure into a passing equivalence
claim. The manifest distinguishes verification errors from fully collected
evidence that still contains logical differences.

For individual steps, generate from this repository's isolated worktree, after
restoring its pinned SDK packages:

```powershell
.\scripts\Generate-PowerbaseEvidence.ps1 -EvidenceDirectory C:\evidence\powerbase-run
```

The directory must not already exist. Generation preserves a reference copy,
control and candidate WinMDs for x64/x86/ARM64 and the merged output, intermediate
RDL, command arrays and working directories, logs, input and output hashes,
package identities, tool executable, patch, SAL shim, vocabulary, and Cargo pins.
It applies, reverses, and reapplies the patch and checks exact restored bytes.
Use `-ResourceDirectory` to reuse known clang resource headers; their complete
file hashes are recorded. `-ReferenceEvidence` preserves an independent
configuration/provenance ledger without using it as generator input.
The namespace is read from the existing Power partition's `--namespace` setting,
recorded with that file's hash, and supplied to both variants. This imports only
the supported namespace input policy, not legacy semantic sidecars.

**Provisional selector:** the pinned wrapper's default scope includes all
`shared`/`um` declarations. The pilot explicitly passes the nonmatching path
segment `__powerbase_pilot_no_directory_scope__` together with
`--scope-header powerbase`. Passing an empty scope is *not* equivalent: an
experimental empty-scope run emitted thousands of unrelated types and constants
and was rejected. The runner enumerates all declarations in every RDL pass,
requires the exact header-owned roots, and links each emitted definition to a
defining-source declaration reached by the native or annotation dependency
graph. The observed seven-definition control closure is not a cap on legitimate
source-backed dependencies introduced by corrected annotations. Raw annotation
bindings with no source declaration remain explicit. A supported header-only
selector belongs in the base tooling, not another pilot implementation.
Macro-derived typedef references use actual Clang expansion/definition tokens,
an included typedef declaration, and identical canonical return/underlying
types. Their source bindings are a separate ledger; they do not turn every
declaration in the defining header into a pilot-owned symbol.

Native comparison uses the same libclang binary as generation:

```powershell
.\scripts\Test-PowerbaseNative.ps1 `
  -SdkInclude <SDK-c\Include\10.0.26100.0> `
  -CandidateInclude C:\evidence\powerbase-run\candidate\headers\um `
  -Libclang <pinned-libclang.dll> `
  -ResourceDirectory <manifest.resourceDirectory> `
  -OutputDirectory C:\evidence\powerbase-run\native
```

The native probe records declaration spelling **and** canonical types,
pointer shapes, parameter order, calling conventions, typedef targets, enum
values, record sizes/alignment/field offsets, diagnostics, and actual included
files. It compares every original header declaration and its native type closure
in C, C++, and metadata-enabled C++, on three architectures and both ownership
contexts. It excludes only source relocation and annotation transport from the
native equality check. Added declarations must be exactly the two guarded enum
groups, and only in metadata mode. Compile-time assertions also verify all
existing function signatures, pointer aliases, and restored macro values/types.

`tests\PowerbasePilot\Test-NativeNegative.ps1` changes only the `Version` parameter
from `ULONG` to `ULONGLONG` in an isolated generated header. It requires rejection
by the declaration-comparison gate; a compiler error or an unrelated failure is
not accepted as a passing negative test.

## Metadata gates

Build the repository reader, then export all relevant raw facts and evaluate
effective contracts separately:

```powershell
dotnet build sources\WinmdUtils\WinmdUtils.csproj -c Release
.\scripts\Compare-PowerbaseEvidence.ps1 -EvidenceDirectory C:\evidence\powerbase-run
.\scripts\Test-PowerbaseLogical.ps1 -EvidenceDirectory C:\evidence\powerbase-run -RequireEquivalent
.\tests\PowerbasePilot\Test-MetadataNegative.ps1 -EvidenceDirectory C:\evidence\powerbase-run
```

`Compare-PowerbaseEvidence.ps1` preserves all decoded metadata facts. Its readable
`comparison\REPORT.md` covers all header roots, aliases, groups, and proposed
members, and `DEPENDENCIES.md` lists every dependency field and enum member.
`symbols\*.json` contains exact three-way per-symbol facts and differences.
The complete per-architecture snapshots/diffs preserve raw namespace, attributes,
custom modifiers, reference scopes, and evidence blobs/tokens.

Raw serialization equality is **not** logical equivalence. The separate logical
gate excludes documentation, assembly identity, forensic encoding, and
`BeforeFieldInit` from native behavior. It records namespace pairings and requires
compatible schemas; unresolved types remain failures. Its enum consumer resolves
the association to an actual enum, verifies primitive storage, and compares every
member/value/type and flags/scoped meaning before treating a native integer plus
association as equivalent to legacy enum typing. It never ignores native typedef,
width, constness, lifecycle, optionality, OS, or byte-count differences.

The metadata negative test actually regenerates isolated mutated headers: remove
the `Version` enum association, change its input-buffer count index, and replace a
byte count with an element count. Every case must compile successfully, then fail
both its precise contract assertion and the general semantic comparer. A failure
to generate is not a successful negative test.

## Differences must remain visible

Successful compilation and native equality do not prove published metadata
equivalence. Preserve the original unannotated control when repairing the
consumer, then regenerate **both** control and candidate with the new pin.
Parameter flags, byte counts versus element counts, enum relationships, public
namespaces, dependencies, imports, error semantics, and ownership must all remain
in the semantic evidence.

The legacy configuration assigns a type-wide
`UnregisterPowerSettingNotification` closer to `HPOWERNOTIFY`. That cannot safely
be copied to this producer. The documented closer for this registration is
`PowerUnregisterSuspendResumeNotification`, and the patch places that fact only
on the producing output. This difference must be reported against the actual
reference metadata, not silently called normalization. No undocumented invalid
handle values are added.

Official contracts:
[registration](https://learn.microsoft.com/en-us/windows/win32/api/powerbase/nf-powerbase-powerregistersuspendresumenotification),
[matching unregistration](https://learn.microsoft.com/en-us/windows/win32/api/powerbase/nf-powerbase-powerunregistersuspendresumenotification),
[different power-setting registration family](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-unregisterpowersettingnotification),
[last-error behavior](https://learn.microsoft.com/en-us/windows/win32/api/powerbase/nf-powerbase-getpwrcapabilities).
