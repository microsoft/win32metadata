# WinMD generator performance comparison

This branch provides a reproducible comparison between the legacy C#/Clang
header scraper and the initial Rust/windows-clang pipeline:

```powershell
.\scripts\Benchmark-WinmdGenerators.ps1
```

If application-control policy only trusts an existing build location, pass it
explicitly:

```powershell
.\scripts\Benchmark-WinmdGenerators.ps1 `
  -RustExecutable C:\repos\win32metadata\tools\rust\target\release\win32metadata-tools.exe
```

The benchmark builds tooling before timing, then processes the same five
partitions for x64, x86, and ARM64:

- Audio
- Direct3D9
- Mf
- Shell
- WinSock

These partitions were selected because the legacy pipeline does not list them
in `ExcludeFromCrossarch`; both implementations therefore parse all three
architectures.

## Reproduced measurement

The automated benchmark on a 16-logical-processor Windows machine produced:

| Pipeline | Wall time | Peak process tree | Peak single process |
| --- | ---: | ---: | ---: |
| Legacy `ScrapeHeaders` | 37.6 seconds | 5.57 GB | 0.64 GB |
| Rust scrape, RDL compile, and WinMD merge | 231.8 seconds | 3.00 GB | 2.87 GB |

The Rust path was 6.2 times the legacy header-scrape time. Earlier manual runs
measured 32.3 seconds and 221.7 seconds respectively, so the automated results
are consistent with normal run-to-run variation. A legacy run that also
scraped constants reached the emitter after 47.1 seconds, but a five-partition
legacy project cannot complete emission because global `autoTypes.json`
entries require APIs outside this subset.

The comparison is therefore not a perfect stage-for-stage benchmark: the Rust
command includes RDL compilation and architecture merging because it has no
scrape-only entry point. It is still representative of the user-visible inner
loop and establishes a substantial performance gap.

## Current scheduling behavior

The legacy `ScrapeHeaders` task expands partition and architecture combinations
and uses `Parallel.ForEach` with a processor-count-sized concurrency limit. For
this sample it can schedule 15 independent jobs across 16 logical processors.

The win32metadata Rust wrapper currently loops through x64, x86, and ARM64
sequentially. Within each architecture, windows-clang also parses input
translation units sequentially. The upstream windows-clang scrape API can
parallelize architectures, but does not yet provide bounded per-partition
parallelism.

The five-partition legacy run has the higher aggregate working set because it
runs 15 compiler processes concurrently, but each process remains below
0.7 GB. Rust retains the translation units in one process: it already reaches
2.87 GB for five partitions. During the full 321-partition run, that process
reached approximately 23 GB working set for a single architecture and took
67.9 minutes before failing on an unrelated Clang `__bf16` intrinsic
declaration.

Parallelizing architectures without first controlling retained
per-architecture state risks multiplying that large working set.

## Recommended follow-up

1. Add timing and memory telemetry around each architecture and partition.
2. Reduce retained libclang translation-unit state before increasing
   concurrency.
3. Add bounded partition-level workers in windows-clang.
4. Then evaluate architecture-level parallelism in the win32metadata wrapper.
