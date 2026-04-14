# Auto Type Remappings: second opinion

*Based on source inspection only. No build or test execution.*

## Bottom line

The overall direction is right. Replacing log/regex-driven suggestion handling with
AST-based, single-pass discovery is much more aligned with the long-term goal of
zero manual remaps than the current "notice it later and hand-edit rsp/json" flow.

My main concern is not the architecture. It is that the current branch is already
narrower than the existing suggestion/fixup behavior in a few important places, and
those narrower choices make it easier to "give up" and keep a manual tail alive.

The biggest behavioral differences I see are:

1. `ResolveTagRemaps` does **not** yet mirror all of ClangSharp's current
   recommended-remapping heuristics.
2. `ResolveFunctionPointerFixups` intentionally stops at the
   **bare-function + pointer-alias** pattern and explicitly skips
   **already-pointer typedef aliases**. That is the biggest place where the current
   implementation is normalizing a permanent manual/annotation tail.
3. Cross-partition misses are only warnings today, while the generated
   auto-remap rsp can eventually mask the missing-header relationship instead of
   forcing the include/annotation fix.

## What already looks good

- `sources\Win32MetadataScraper\Program.cs` is using the right shape:
  parse once, discover from AST, merge with configured remaps, then call
  `PInvokeGenerator.GenerateBindings` on the same translation unit.
- `sources\Win32MetadataScraper\RemapDiscovery.cs` is correctly based on
  structural AST relationships instead of raw text scanning.
- Walking both `Decls` and `CursorChildren` to catch transitive includes is
  directionally aligned with how ClangSharp's generator sees the world.
- Writing header provenance into the sidecar file and using it in
  `ScrapeHeaders.CheckCrossPartitionRemapConsistency()` is a strong idea.

Those are all improvements over the existing repo flow.

## Comparison with the existing suggestion / fixup mechanisms

| Area | Existing behavior | Current branch behavior | Why it matters |
| --- | --- | --- | --- |
| Tag remap suggestions | Upstream `PInvokeGenerator` collects valid typedef/tag relationships during traversal and emits diagnostics like `Potential missing remapping ... Recommended remapping: 'X=Y'`. The repo test path is `tests\Windows.Win32.Tests\IntegrityTests.cs::NoSuggestedRemappings` + `sources\WinmdUtils\Program.cs::ShowSuggestedRemappings`. | `sources\Win32MetadataScraper\RemapDiscovery.cs::ResolveTagRemaps` auto-applies discovered remaps before generation. | Good direction, but the new resolver should stay behaviorally close to the existing recommendation heuristics before it declares a case unsupported. |
| Tag remap heuristics | Upstream recommendation logic currently prefers: single match, strip leading `_`, strip leading `tag`, strip trailing `_`, strip trailing `tag`, then uppercase-name match (see upstream `PInvokeGenerator.cs` diagnostic block around `GetFoundRemappingString`). | Current resolver prefers: configured manual hint, strip leading `_`, strip leading `tag` (only when followed by uppercase), then case-insensitive exact-name match. | This is a real mismatch. Some cases ClangSharp would recommend can now be skipped by the new resolver, which makes the branch look "more hopeless" than the existing signal. |
| Traversal / reachability | Existing suggested-remapping test is based on generator output captured under `obj\scratch`, so it reflects what the generator actually traversed. | The new walker pulls relationships directly from the AST and also reaches transitive includes via `CursorChildren`. | This is a good improvement, but it also means the generated auto-remap rsp can paper over missing per-partition visibility if the consistency check stays warning-only. |
| Function-pointer fixup suggestions | The repo's current fixup path is manual: `generation\WinSDK\functionPointerFixups.json` -> `sources\GeneratorSdk\MetadataTasks\PrepSettingsForFunctionPointerFixups.cs` -> scraper `--exclude/--remap` + emitter `--reducePointerLevel`. Remaining problems are surfaced by `tests\Windows.Win32.Tests\IntegrityTests.cs::NoInvalidPointersToDelegates` + `sources\WinmdUtils\Program.cs::ShowPointersToDelegates`. | `sources\Win32MetadataScraper\RemapDiscovery.cs::ResolveFunctionPointerFixups` auto-discovers only the bare-function + pointer-alias case and explicitly skips already-pointer alias cases. | This is the largest behavior fork. If the zero-manual goal includes those already-pointer alias cases, the current implementation has chosen to stop short. |
| Suggestion plumbing | `ShowSuggestedRemappings` looks for `Recommended remapping:` in scratch output, which matches the current upstream generator diagnostics. | `sources\GeneratorSdk\MetadataTasks\ScrapeHeaders.cs` still parses `Info: Potential remap: ...` into `suggestedRemaps`. | This looks stale. It is probably not the authoritative signal anymore and may confuse anyone comparing old vs new behavior from task logs alone. |

## The most important gap: already-pointer typedef aliases

This is the place where I would push back hardest if the goal is eventually zero
manual remaps/fixups.

Current behavior in the branch:

- `sources\Win32MetadataScraper\RemapDiscovery.cs::ResolveFunctionPointerFixups`
  generates fixups only for:

  ```c
  typedef void CALLBACK_NAME(...);
  typedef CALLBACK_NAME *LPCALLBACK_NAME;
  ```

- The same method explicitly chooses **not** to generate fixups for:

  ```c
  typedef DWORD (*PFOO)(...);
  typedef PFOO LPFOO;
  ```

- `tests\Win32MetadataScraperTests\RemapDiscoveryTests.cs` now contains tests that
  codify that choice (`FnPtr_AlreadyPointer_NoFixupGenerated`,
  `FnPtr_BothHavePointerPrefix_NoFixupForAlreadyPointer`, etc.).

But the existing repo behavior still has live manual entries for exactly that class
of case in `generation\WinSDK\functionPointerFixups.json`, including
`PTHREAD_START_ROUTINE` / `LPTHREAD_START_ROUTINE`,
`INTERNET_STATUS_CALLBACK` / `LPINTERNET_STATUS_CALLBACK`, and the older
`alreadyPointer: true` entries.

That does **not** automatically mean the new branch is wrong. It does mean the
branch has made a policy choice:

- either "these cases should remain manual forever",
- or "these cases should become annotation-driven later",
- or "these cases are actually unnecessary once the rest of the pipeline changes".

Right now the code and tests are taking option 1 by default, and that is the part I
would challenge. If the real goal is zero manual fixups, then these cases need a
deliberate strategy instead of being defined as out-of-scope.

## What I think the agent should preserve from the existing system

The existing system is weak in implementation details, but it has two valuable
properties that the new work should preserve:

1. **It surfaces unresolved cases instead of silently swallowing them.**
   - Tag remaps: `NoSuggestedRemappings`
   - Fn ptr issues: `NoInvalidPointersToDelegates`

2. **It does not pretend every unresolved case is the same kind of problem.**
   There are at least three buckets:
   - structural, unambiguous header relationships -> should be auto-derived
   - structural but ambiguous / canonical-name choice required -> should become
     annotation-driven
   - semantic/public-name overrides -> should stay explicit and separate from
     "discoverable from headers" logic

That three-bucket model is the piece I would keep front-and-center.

## Specific feedback to the implementing agent

### 1. Match ClangSharp's recommendation heuristics before giving up

Before treating a tag as "not auto-derivable", I would make the new resolver at
least as capable as the current ClangSharp recommendation path.

Today the branch already handles some of the common cases, but it does **not**
currently mirror all of the upstream recommendation heuristics:

- leading `_`
- leading `tag`
- trailing `_`
- trailing `tag`
- uppercase canonicalization

If ClangSharp would currently recommend a remap from the same typedef set, the new
AST-based resolver should usually do the same thing instead of skipping and inviting
someone to add a mapping back by hand.

### 2. Do not let "already-pointer aliases" become a permanent manual bucket by accident

If the plan is zero manual fixups, then
`typedef PFOO LPFOO`-style cases need an answer.

I would not accept "both names are valid aliases, so skip" as the final behavior
unless the repo consciously decides that those cases are **not** supposed to be
canonicalized.

Better options:

- keep a temporary heuristic fallback for canonical-name selection,
- or emit an explicit "needs annotation" artifact for these cases,
- or define a header annotation that picks the public alias.

What I would avoid is:

- changing tests so "we do nothing here" becomes the expected steady state,
- then using that as justification for keeping the remaining json entries forever.

### 3. Separate "discoverability" from "policy"

The AST can tell you that two names are related. It cannot always tell you which one
the metadata surface should prefer.

That distinction matters:

- **discoverability** -> inferred from typedef/tag/function-pointer structure
- **policy** -> which alias is canonical in emitted metadata

For ambiguous-but-related cases, the next step should be annotation or a dedicated
policy mechanism, not a hand-edited remap file.

### 4. Make skipped/ambiguous cases first-class outputs

Right now the branch is strongest where it can fully auto-resolve, and much weaker
where it cannot.

I would strongly prefer a machine-readable output for:

- ambiguous tag remaps
- already-pointer alias pairs with no canonical-name decision
- cross-partition visibility misses

That gives the team a clean path:

1. auto-derive when possible
2. annotate headers when needed
3. only keep manual rsp/json as temporary compatibility data

Without that output, the natural human fallback is to add mappings back manually.

### 5. Tighten the cross-partition story

`sources\GeneratorSdk\MetadataTasks\ScrapeHeaders.cs::CheckCrossPartitionRemapConsistency`
is useful, but warning-only is probably too soft for the stated goal.

My concern is not just the warning level. It is that the generated auto-remap rsp is
global, so one partition's discovery can eventually hide another partition's missing
include. That is convenient for bootstrapping, but it is weaker than the desired
"discoverable from headers themselves" invariant.

If the real invariant matters, I would eventually either:

- promote these inconsistencies to a failure,
- or emit a dedicated artifact that must go to zero,
- or otherwise ensure the generated global remap file does not become a substitute
  for the missing include/annotation fix.

### 6. Keep semantic overrides out of the structural-remap success metric

Some remaining manual mappings are not "failed typedef discovery". They are a
different category:

- primitive coercions
- public API naming decisions
- MIDL-friendly names
- other semantic overrides

Those should not be used as evidence that structural auto-remapping has failed.
They either need a separate explicit mechanism or future annotations with different
semantics.

## The policy I would recommend

If I were guiding the implementation, I would formalize the end state like this:

1. **Structural and unambiguous**
   - auto-derive from AST
   - auto-apply before generation

2. **Structural but ambiguous**
   - emit a deterministic "needs annotation" signal
   - do not silently skip
   - do not solve by reintroducing manual rsp/json unless absolutely necessary

3. **Semantic overrides**
   - keep them in a separate, explicit mechanism
   - do not mix them into the structural auto-remap success metric

That keeps the implementation aligned with the stated goal and avoids the "we lost
hope, so we added another manual mapping" pattern.

## Short version to tell the other agent

The architecture is good. The current risk is behavioral drift, not the idea.

Specifically:

- make `ResolveTagRemaps` at least as smart as ClangSharp's current recommended
  remapping heuristics before you declare a case unsupported;
- do not normalize `typedef PFOO LPFOO`-style cases as "manual forever" unless that
  is an intentional policy decision;
- when the AST proves a relationship but not the canonical alias, treat that as an
  **annotation problem**, not as a reason to add manual mappings back;
- keep cross-partition misses visible enough that generated global remaps do not
  hide them.
