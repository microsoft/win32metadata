# Shift-left annotation Ralph-loop runlog

## 2026-09-15 - partition 001 ActiveDirectory

- Verified parent PR #2303 head `7fecfb51`.
- Generated deterministic ordinal partition order from the 321 partition
  directories selected by `Windows.Win32.proj`; order 001 is ActiveDirectory.
- Replayed the annotation parser onto the current windows-rs pipeline line and
  pinned commit `181e339d7`.
- Added approved annotation vocabulary and 11 consolidated ActiveDirectory
  header patches plus the shared vocabulary patch.
- Verified all 12 patch artifacts reverse-apply and that SDK ingestion applies
  all 12 successfully.
- Verified the merged windows-rs `windows-clang` and `windows-rdl` libraries
  compile. The executable regression tests and targeted generation are blocked
  by Windows Defender OS error 225 before process startup.
- Stopped before partition 002.
