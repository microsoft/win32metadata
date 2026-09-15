# ActiveDirectory partition 001

- **Order:** 001 of 321
- **Parent:** #2303 (`user/jevansa/windows-rs-pipeline-wrapper`, `7fecfb51`)
- **Branch:** `jevansaks-annotations-001-first-partition`
- **Direct headers:** 16
- **Inherited headers:** `intrinfix.h`, `winsock2.h`, `winternl.h`,
  `ntsecapi.h`, `shlobj_core.h`

## Result

This checkpoint is **blocked**. The SDK patch ingestion path applies all 12
consolidated patch artifacts successfully, and the merged windows-rs libraries
compile, but Windows Defender prevents both debug and release
`win32metadata-tools.exe` binaries from starting with OS error 225. Therefore no
header is classified as `matched` or `accepted-normalized`; compilation alone is
not sufficient.

## Header status

| Header | Patch | Classification |
| --- | --- | --- |
| `AdsHlp.h` | consolidated | blocked |
| `ADSIid.h` | none | blocked |
| `AdsProp.h` | consolidated | blocked |
| `Adssts.h` | none | blocked |
| `CmnQuery.h` | consolidated | blocked |
| `DSAdmin.h` | consolidated | blocked |
| `DSClient.h` | consolidated | blocked |
| `DsGetDC.h` | consolidated | blocked |
| `dsparse.h` | consolidated | blocked |
| `DSQuery.h` | none | blocked |
| `DSRole.h` | consolidated | blocked |
| `Iads.h` | consolidated | blocked |
| `NtDsAPI.h` | consolidated | blocked |
| `NtDsBMsg.h` | none | blocked |
| `ObjSel.h` | consolidated | blocked |
| `Schedule.h` | none | blocked |

## Patch organization

There is exactly one `.win32metadata.patch` file for each changed SDK header.
The shared annotation vocabulary also has one consolidated patch. No header is
split into overlapping or sequential patches.

## Architecture validation

| Architecture | Result |
| --- | --- |
| x64 | blocked before process startup by Windows Defender, OS error 225 |
| x86 | not runnable for the same blocker |
| arm64 | not runnable for the same blocker |

## Action required

Run the targeted ActiveDirectory generation and comparison in approved CI or an
environment where the repository-built Rust executable is allowed:

```powershell
.\scripts\Generate-WindowsRsWinmd.ps1 -Partition ActiveDirectory -Architecture x64
.\scripts\Generate-WindowsRsWinmd.ps1 -Partition ActiveDirectory -Architecture x86
.\scripts\Generate-WindowsRsWinmd.ps1 -Partition ActiveDirectory -Architecture arm64
```

Then replace each blocked header classification with `matched`,
`accepted-normalized`, or a header-specific actionable blocker.
