# Bounded COM projection-policy adapter

This prerequisite adds **COM member context**, not a new semantic exception.
It reuses `win32-projection` policy `1.0.0` and its three unchanged proof helpers.
The five files committed in `c8502d3f9b6f08ef7eda7e5b93f847df7d1815e7`,
the earlier Powerbase/Powrprof sources, and their frozen evidence are unchanged.
Only the GUID rule has actual COM positive coverage in this bounded experiment;
the const-string and REGSAM helpers remain available but have no eligible direct
wmcontainer uses in the discovered method set.

## Actual results

Discovery intersects candidate interface methods with the original native
capture's **source-owned wmcontainer declarations**. It finds these five
GUID-bearing methods, not transitive methods from every included header:

| Actual method | Result on each of x64, x86, ARM64 and merged |
| --- | --- |
| `IMFASFMutualExclusion.GetType` | Native COM context verified; one `sdk-guid-system-guid/v1` parameter explanation; return and interface differences remain |
| `IMFASFMutualExclusion.SetType` | Native `const GUID &` is explicitly unsupported; no reference-to-pointer coercion |
| `IMFASFStreamConfig.GetStreamType` | `IMFAttributes` inheritance is outside the direct-IUnknown adapter |
| `IMFASFStreamConfig.GetPayloadExtension` | Same unsupported inheritance; no count/optionality normalization |
| `IMFASFStreamConfig.AddPayloadExtension` | Same unsupported inheritance; no by-value GUID claim |

Across **20 actual reference/candidate comparisons**, there are **four validated
method contexts and four explained GUID parameter paths**. There are **zero
fully equivalent methods**: all 20 retain review-required method/context
obligations. Sixteen have unsupported-context rejections. These are distinct
from the four successful parameter proofs.

The successful `GetType` explanation addresses only
`/parameters/0/contract/type/element/name`. Its remaining method difference is
the reference's in-image `Windows.Win32.Foundation.HRESULT` versus the
candidate's unresolved external `Windows.Foundation.HResult`. The adapter does
not bless that return representation. Interface raw differences retain the IID
attribute provider/schema and missing minimum-OS metadata. Equal IID **values**
establish COM identity; they do not erase those attribute/provider differences.
Exact raw/effective diffs, rejection reasons, binding issues, and interface
diffs are retained for every method. No other interface/member obligations are
closed.

**59 boundary tests pass.** They include an actual `GetType` parameter proof
that must retain the return residual, two real unsupported-context cases, and
56 deliberate negative/preservation cases. Cases cover wrong GUID identity,
layout/member/array/field flags/source/runtime assembly, missing or ambiguous
interfaces/methods, reordered slots, IID/base identity, explicit `This`,
native/metadata conventions, nonvirtual/static/variadic members, indirection,
const/count/direction/optionality/lifetime/closer changes, missing associations,
corrupted provenance, and return shape. An unrelated difference may coexist
with the narrowly valid GUID explanation, but must remain unresolved.

## Reusable API and evidence

```powershell
. .\scripts\Compare-ComProjectionPolicy.ps1
$result = Compare-ComProjectionPolicy `
  -OldSnapshot $publishedReference `
  -NewSnapshot $candidate `
  -InterfaceName 'Windows.Win32.Media.MediaFoundation.IMFASFMutualExclusion' `
  -MethodName 'GetType' `
  -Evidence $context
```

The adapter selects exact interface and method rows itself; callers do not
rename a Winapi method or invent an import. Missing/duplicate identities reject.
Its version is `com-method-context/v1`; it retains the existing policy version,
user approval, rule IDs, exact explained paths, full definition/source evidence,
IID, member, native slot, and residuals.

`$context` extends `New-ProjectionPolicyEvidence`'s schema with:

- `comCpp`: `{ path, sha256 }` for a `native-com-context/v1` capture of the actual
  C++ interfaces, bases, pure-virtual member order, prototypes and convention.
- `comVtable`: `{ path, sha256 }` for the same TU/provider with the original
  `CINTERFACE` arguments, recording explicit `This`, function-pointer signatures,
  field offsets and complete vtable order.
- `sources`: retained original interface/base source bytes in addition to the
  SDK GUID/alias source ledger. Source locators are verified against those bytes.

The ordinary native capture supplies independent SDK GUID/layout facts to the
unchanged lower proof routines. COM context cross-checks C++ methods against
the explicit C vtable, the exact reference/candidate member order, the native
interface IID, and real IUnknown's IID/three-slot prefix. It verifies native
HRESULT return width/signature but **does not normalize metadata returns**.

V1 is deliberately limited to non-overloaded, pure-virtual, direct-IUnknown
interfaces and imported-free instance metadata methods. It requires source
direction/optionality evidence and rejects unsupported native references,
other inheritance, missing definitions and unproven shapes. This is not an
all-COM, callback, field, or complete-header comparer. Return and dependency
obligations remain separate even when a parameter rule succeeds.

## Reproduction and immutable provenance

```powershell
.\tests\ComProjectionPolicy\Replay-ComProjectionPolicy.ps1 `
  -OriginalEvidenceDirectory C:\Users\jevansa\.copilot\session-state\4f30d598-bde6-4b6e-8f3e-3936a7fb2010\files\wmcontainer-three-arch-r4 `
  -OutputDirectory <fresh-directory>
```

Original manifest SHA-256:
`0B85C3F8C0C566315E419E0F7E94C4294912E27019EFC2A201232B9762444568`.
All **168 original artifacts and four original test-source fingerprints**
remain unchanged. The eight actual candidate/control images and their decoded
snapshots are verified; no metadata is regenerated or rewritten.

The original captures did not contain C++ methods/bases or decoded vtable
function signatures. The new owned `ComNativeProbe.cs` therefore makes **six
native-only captures** using the original TU bytes, exact per-architecture
arguments, selected generated IDL provider, candidate header, and pinned
libclang. The copied TU is byte-identical to the original TU; its source path
relocation is recorded. Merged reuse of the x64 native context is gated on
actual candidate WinMD byte identity.

The published reference is `70.0.11-preview`, SHA-256
`6AEC29BE3359468D9EBA03C3AE932591B39960F1812B6D25D33C0D9F14A6D665`.
The existing `WinmdUtils contracts` reader decodes the exact discovered
interface roots into a **new** reference snapshot. Its binary hash and full
command are recorded. No legacy JSON or baseline data feeds generation.

Final evidence:

```text
C:\Users\jevansa\.copilot\session-state\ac7b652c-c8c0-40c2-8251-946330986647\files\com-projection-v1-final
```

Final manifest SHA-256:
`C846E429D3A3AAC7052904FCA43E35547608D680C7FDAB565F8F94DC5CCFE0F4`.
It records 46 artifact hashes, eight executed-source hashes, ten explicitly
frozen prior source hashes, eight original image/decode pairs, reference
provenance, native-only commands, source/provider identities, and all outcomes.
`comparison\discovery.json`, the four `*-methods.json` files and
`tests\checks.json` are the detailed evidence.

The discovery and `run1` directories are diagnostic only. The first native
probe required support for declarations nested in `extern "C"`; the initial
runner was corrected to separate source-owned interfaces from transitive
ones and preserve its caller's evidence-directory parameter. Only `final` is
the verified result. No policy/source exceptions were introduced for those
harness corrections.
