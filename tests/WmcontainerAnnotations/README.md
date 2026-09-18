# wmcontainer.h association preflight

This bounded regression replaces the unsafe historical donor approach with
`_Win32_AssociatedEnum_(ASF_STATUSFLAGS)` on the unchanged `DWORD*`
`IMFASFSplitter::GetNextSample.pdwStatusFlags` parameter. The consolidated
post-MIDL patch covers both C++ and C vtable declarations. It does not move,
redeclare, resize, or change the existing enum.

This is **not complete wmcontainer.h, Mf, or full-SDK equivalence**. Other direct
declarations, reference/legacy obligations, availability, ownership, and shared
dependencies remain open in the rollout. No published-reference difference is
accepted by this preflight.

## Source provider

The selected SDK's original header has unconverted MIDL comments, so a production
post-MIDL patch must not be applied directly to that file. The test converts the
selected `wmcontainer.idl` with the repository's existing SAL converter and
regenerates that one header with the production MIDL options. It records the
raw header, IDL, converter, 24 processed MIDL inputs, MIDL/preprocessor tools and
generated header separately.

Control and candidate use that identical generated provider and include chain;
only the candidate receives the patch. Imported dependency headers remain the
stock selected SDK for this isolated preflight. This is not a substitute for
the full production materialization of the Mf partition. Generic prepared
provider selection is tracked by the rollout controller.

## Reproduce

Build `sources\WinmdUtils`, then supply the immutable generator executable and
matching clang resource directory from the pinned pilot manifest:

```powershell
.\tests\WmcontainerAnnotations\Test-WmcontainerAnnotations.ps1 `
    -EvidenceDirectory <fresh-directory> `
    -ToolPath <pinned-win32metadata-tools.exe> `
    -ResourceDirectory <libclang-22.1.8-resource-include-directory>
```

Use `-Architecture x64` during editing. The default checks x64, x86, ARM64 and
merged metadata. It never generates the full SDK.

The verified `wmcontainer-three-arch-r4` evidence under integration session
`4f30d598-bde6-4b6e-8f3e-3936a7fb2010\files` contains:

- 30 native checks across control/candidate, three architectures, C, C++,
  C-vtable, metadata C++, and metadata C-vtable configurations.
- Four candidate decoded WinMD checks retaining an **Out UInt32 pointer** and
  binding the association to the actual two-member native enum.
- Complete raw control/candidate contract diffs: exactly one added association
  attribute in each image, with no unrelated contract changes.
- A compiled unannotated control rejected for its missing association, and a
  native `DWORD*` to `ULONGLONG*` mutation rejected by the signature assertion.
- Exact patch reversal/reapplication and whole-header source preservation:
  removing only the two annotations and vocabulary include restores the
  generated header byte-for-byte. Enum position and every other declaration
  remain unchanged.

The manifest SHA-256 is
`0B85C3F8C0C566315E419E0F7E94C4294912E27019EFC2A201232B9762444568`.
Its 168 artifact hashes and four executed test-source hashes were verified
after collection. Earlier failed provider/setup attempts remain separate,
unpromoted evidence.

Source contracts:
[GetNextSample](https://learn.microsoft.com/en-us/windows/win32/api/wmcontainer/nf-wmcontainer-imfasfsplitter-getnextsample)
and [ASF_STATUSFLAGS](https://learn.microsoft.com/en-us/windows/win32/api/wmcontainer/ne-wmcontainer-asf_statusflags).
