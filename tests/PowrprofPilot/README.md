# powrprof.h proof

This experiment is confined to the selected SDK's **powrprof.h**, not the Power
partition or functions declared by included `powerbase.h` / `powersetting.h`.
The earlier Powerbase proof and its committed patch are separate.

The selected `Microsoft.Windows.SDK.CPP` / `.CPP.x64` packages are
`10.0.26100.7705`. The repository header and package header have SHA-256
`2075A213F792A8206C510E26D94A81FF4E1A59F0168A3FD900822D14E863CEB1`.
Comparison uses the published `Microsoft.Windows.SDK.Win32Metadata`
`70.0.11-preview`, not a newly generated control.

```powershell
.\scripts\Test-PowrprofPilot.ps1 `
  -EvidenceDirectory C:\evidence\powrprof-fresh `
  -ResourceDirectory <pinned-clang-resource-directory> `
  -ToolPath <verified-owner-win32metadata-tools.exe> `
  -ToolSha256 <binary-sha256> `
  -ToolSourceCommit <integrated-owner-commit> `
  -DocumentationEvidence <retained-documentation-evidence.json> `
  -PowerbaseEvidenceDirectory <immutable-composed-a7f78d9-final-evidence>
```

The directory must be new. The runner records full SDK import-library inputs,
exact command arrays, hashes, source inventory and compiler-evaluated macro
types/values. It verifies patch apply/reverse/reapply, all direct C/C++ declarations
with metadata off/on across x64/x86/ARM64, actual emitted roots and shared
definitions, and four generated negative controls. It never calls the Windows
power APIs or executes cross-target binaries.

`Get-PowrprofInventory.ps1` reads pinned legacy settings only for a one-time
migration ledger. The production scrapes consume only SDK headers, the single
consolidated `powrprof.h.win32metadata.patch`, and import libraries. Generated
Foundation `WIN32_ERROR` and Registry `REG_SAM_FLAGS` headers are explicit
source-backed dependency **bridges**, not other API pilots or completed shipped
SDK-header migration. Their generation does not consume legacy JSON/WinMD.

The native inventory distinguishes 108 direct AST declarations (73 functions,
nine record tags, one enum tag, 25 typedef declarators including five callback
aliases), 64 record fields, 29 native enum members, and 29 public macros.
Tags and typedef aliases are not counted as distinct runtime API types. Native
macro signedness/width is evaluated independently of the enum value probe.

`comparison\REPORT.md` and `all-direct-symbols.json` enumerate every direct
declaration/member/macro. Raw snapshots and per-architecture function/type
differences are retained separately. Callback `Invoke` contracts are compared,
not merely delegate flags. Complete decoded enum member contracts are hashed
for compact per-use comparisons; the original complete tables remain in the raw
snapshots. A raw disagreement never disappears just because an improvement is
accepted with independent native/documentation evidence.

The runner does not treat successful compilation as complete equivalence.
Conditional allocation, unsupported annotation transport, availability ambiguity,
and unknown dependency semantics remain explicit review requirements in the
report. No unconditional cleanup may be attached to caller-supplied GUID storage,
and no DWORD return is assumed to be an error code merely because of its type.

Expected improvements are distinct from equality. The generic classifier
replays the actual previous Powerbase registration/unregistration contracts
without changing that proof. It requires independently retained source/document
excerpts, genuine handle identity, native pointer width/depth and calling
convention, exact producer-specific cleanup, and resolved metadata definitions.
The Powrprof report applies it to the documentation-backed
`ReadGlobalPwrPolicy` direction correction. Separately reported improvements
include source-backed constant signedness, documented type availability, and
documented Windows error-status return enrichment with a complete in-image enum.

Const encoding equivalence is restricted to an independently proven single
native const-pointee pointer: legacy `ConstAttribute` versus required `IsConst`
on that same pointer. Pointee identity remains compared. SAL `_In_` does not
justify inventing native const, and GUID/System.Guid identity is not normalized
by name. Raw attribute implementations and current-use policy restrictions
remain visible.
