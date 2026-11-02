import hashlib
import importlib.util
import json
import subprocess
import tempfile
import unittest
from pathlib import Path
from unittest.mock import patch


SPEC = importlib.util.spec_from_file_location(
    "sdk_coverage", Path(__file__).resolve().parents[2] / "scripts" / "Get-SdkAnnotationCoverage.py"
)
coverage = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(coverage)


def fact(symbol, original, category="supportedOS", line=7, treatment="authored"):
    return {
        "source": r"generation\WinSDK\supportedOS.rsp",
        "locator": f"line:{line}", "category": category, "treatment": treatment,
        "symbol": symbol, "value": f'{symbol}=SupportedOSPlatform("windows6.0.6000")',
        "originalCandidates": [original], "partitionCandidates": ["Core"],
        "ownershipStatus": "unique-original-candidate",
    }


def report_fixture():
    originals = [r"um\a.h", r"um\b.h", r"um\example.idl"]
    return {
        "snapshot": {
            "inventoryPath": "inventory.json", "sdkPackageVersion": "test-sdk",
            "sdkPackageRoot": r"C:\fixture-sdk", "sdkIncludeVersion": "test-include",
        },
        "excludedOriginals": [r"um\excluded.h"],
        "readyOriginalOwners": [
            {"original": original, "partitionCandidates": ["Core"]} for original in originals[:2]
        ],
        "selectedSdkOriginals": [
            {"original": original, "kind": "native-header" if original.endswith(".h") else "IDL/ODL"}
            for original in originals
        ],
        "partitions": [{"name": "Core", "namespace": ["Windows.Win32.System"]}],
        "generatedSdkHeaders": [{"header": r"um\example.h", "originalCandidates": [originals[2]]}],
        "retainedFacts": [fact(f"Api{index}", original) for index, original in enumerate(originals)],
    }


class SourceBlockedAccountingTests(unittest.TestCase):
    def inventory(self):
        return json.loads((Path(__file__).parent / "SourceBlockedMetadata.json").read_text())

    def test_every_historical_unit_is_deferred_without_a_preservation_claim(self):
        result = coverage.source_blocked_accounting(self.inventory(), "10.0.28000.2705")
        self.assertEqual(result["deferredLegacyFacts"], 30)
        self.assertEqual(result["availability"], 26)
        self.assertEqual(result["associatedEnumUses"], 3)
        self.assertEqual(result["enumFlags"], 1)
        self.assertNotIn("preservedLegacyFacts", result)
        self.assertFalse(result["currentPreservationClaimed"])
        self.assertEqual(result["currentProjectionState"], "unqualified")
        self.assertEqual(len(result["facts"]), 30)
        self.assertTrue(all(fact["currentPhysicalProjection"] is None for fact in result["facts"]))
        flags = [fact for fact in result["facts"] if fact["category"] == "enum-flags"]
        self.assertEqual([(fact["target"], fact["value"]) for fact in flags], [("IdentityUpdateEvent", "Flags")])

    def test_missing_changed_or_falsely_covered_units_cannot_turn_green(self):
        for mutation in (
            "missing", "duplicate", "value", "flags", "covered", "preserved",
            "available-source", "extra-coverage-claim", "owner", "source-hash",
        ):
            with self.subTest(mutation=mutation):
                inventory = self.inventory()
                header = inventory["headers"][0]
                facts = header["facts"]
                if mutation == "missing":
                    facts.pop(0)
                elif mutation == "duplicate":
                    facts.append(facts[0].copy())
                elif mutation == "value":
                    facts[0]["value"] = "windows10.0"
                elif mutation == "flags":
                    header["facts"] = [fact for fact in facts if fact["category"] != "enum-flags"]
                elif mutation == "covered":
                    inventory["migrationState"] = "covered"
                elif mutation == "preserved":
                    inventory["currentProjectionState"] = "preserved"
                elif mutation == "available-source":
                    inventory["sourceState"] = "original-available"
                elif mutation == "extra-coverage-claim":
                    inventory["preservedLegacyFacts"] = 30
                elif mutation == "owner":
                    header["path"] = r"um\unrelated.h"
                elif mutation == "source-hash":
                    header["sha256"] = "0" * 64
                with self.assertRaisesRegex(ValueError, "Source-blocked"):
                    coverage.source_blocked_accounting(inventory, "10.0.28000.2705")

    def test_another_selected_sdk_requires_a_fresh_source_disposition(self):
        with self.assertRaisesRegex(ValueError, "selected SDK"):
            coverage.source_blocked_accounting(self.inventory(), "10.0.26100.7705")

    def test_refresh_replaces_the_old_preservation_claim_without_rescanning_sources(self):
        report = report_fixture()
        report["snapshot"].update({
            "configurationGitTree": "frozen-tree", "sdkPackageVersion": "10.0.28000.2705",
            "sdkIncludeVersion": "10.0.28000.0",
        })
        report["scope"] = {}
        report["additionalSelectedSourceProviders"] = [{"publicIncludeFiles": []}]
        report["sourceProgressScoreboard"] = {
            "committedPatchInputs": True, "strictApplyRows": [],
            "committedNonBootstrapNativeHeaderCount": 0, "goalEligibleCommittedNativeHeaderCount": 0,
            "actuallyAffectedGeneratedHeaderCount": None, "goalEligibleObservedGeneratedHeaderCount": None,
            "eligiblePatchedHeaderCountKnown": None, "newNativeHeaderPathsBeyondSnapshot": [],
            "receiptStrictApplyStatusCounts": {},
        }
        report["missingOriginalSourceMigrations"] = {"preservedLegacyFacts": 30}
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            (root / "c" / "include" / "10.0.28000.0").mkdir(parents=True)
            output = root / "inventory.json"
            output.write_text(json.dumps(report), encoding="utf-8")
            with (
                patch("sys.argv", ["coverage", "--refresh", "--output", str(output),
                                   "--sdk-package-root", str(root)]),
                patch.object(coverage, "git", side_effect=lambda repo, *args:
                             "" if args[0] == "diff" else "frozen-tree"),
                patch.object(coverage, "update_source_receipts"),
                patch.object(coverage, "update_generated_observations"),
                patch.object(coverage, "write_operational_outputs"),
                patch("builtins.print"),
            ):
                coverage.main()
            refreshed = json.loads(output.read_text(encoding="utf-8"))
        self.assertEqual(refreshed["missingOriginalSourceMigrations"],
                         coverage.source_blocked_accounting(self.inventory(), "10.0.28000.2705"))


class ConfigurationTests(unittest.TestCase):
    def test_response_sections_keep_exact_lines_and_duplicate_rules(self):
        entries = list(coverage.rsp_entries(
            "# comment\n --with-setlasterror \n Api \n\nApi\n--memberRemap\nS::value=FLAGS\n"
        ))
        self.assertEqual(entries, [
            ("--with-setlasterror", 3, "Api"),
            ("--with-setlasterror", 5, "Api"),
            ("--memberRemap", 7, "S::value=FLAGS"),
        ])

    def test_nested_response_is_not_silently_ignored(self):
        with self.assertRaisesRegex(ValueError, "Nested response"):
            list(coverage.rsp_entries("--config\n@other.rsp\n"))

    def test_enum_extensions_are_uses_not_definitions_or_associations(self):
        files = {
            r"generation\WinSDK\enums.json": json.dumps({"items": [
                {"name": "FLAGS", "members": [{"name": "FLAG_A", "value": "1"}],
                 "uses": [{"method": "Api", "parameter": "flags"}]},
                {"addUsesTo": "FLAGS", "uses": [{"struct": "S", "field": "flags"}]},
            ]}),
            r"generation\WinSDK\autoTypes.json": "[]",
            r"generation\WinSDK\functionPointerFixups.json": "[]",
            r"generation\WinSDK\emitter.settings.rsp":
                '--memberRemap\nS::other=FLAGS\nS::related=[AssociatedEnum("FLAGS")]\n',
        }
        facts, summary = coverage.configuration_facts(files)
        self.assertEqual(summary["enumConfigurationObjects"], 2)
        self.assertEqual(summary["enumDefinitions"], 1)
        self.assertEqual(summary["enumUseExtensionObjects"], 1)
        self.assertEqual(summary["enumExplicitMembers"], 1)
        self.assertEqual(summary["categories"]["direct-enum-use"], 3)
        self.assertEqual(summary["categories"]["associated-enum-use"], 1)

    def test_removing_synthetic_definition_does_not_hide_its_remaining_direct_uses(self):
        files = {
            r"generation\WinSDK\enums.json": '{"items":[]}',
            r"generation\WinSDK\autoTypes.json": "[]",
            r"generation\WinSDK\functionPointerFixups.json": "[]",
            r"generation\WinSDK\emitter.settings.rsp": "--memberRemap\nS::flags=FLAGS\n",
        }
        _, summary = coverage.configuration_facts(files, {"FLAGS"})
        self.assertEqual(summary["categories"]["direct-enum-use"], 1)
        self.assertNotIn("member-type-override-review", summary["categories"])

    def test_agile_and_binding_overrides_do_not_become_completed_migrations(self):
        self.assertEqual(
            coverage.classify_rsp("settings.rsp", "--memberRemap", "I=[Agile]", set()),
            ("agile-intentional-removal-pending", "intentional-removal"),
        )
        self.assertEqual(
            coverage.classify_rsp("settings.rsp", "--with-librarypath", "Api=example.dll", set()),
            ("manual-import-review", "review"),
        )

    def test_removals_are_a_multiset_not_a_set(self):
        item = fact("Api", r"um\a.h")
        removed = coverage.removed_facts([item, {**item, "locator": "line:8"}], [item])
        self.assertEqual(len(removed), 1)
        self.assertEqual(removed[0]["locator"], "line:8")

    def test_native_header_with_idl_sibling_stays_native(self):
        result = coverage.header_origin(r"um\wincrypt.h", "int NativeApi(void);", [r"um\wincrypt.idl"])
        self.assertFalse(result["generated"])
        self.assertEqual(result["originals"], [r"um\wincrypt.h"])

    def test_missing_generated_original_does_not_become_a_native_owner(self):
        result = coverage.header_origin(r"um\missing.h", "/* File created by MIDL compiler */", [])
        self.assertTrue(result["generated"])
        self.assertEqual(result["originals"], [])
        self.assertEqual(result["ownershipBasis"], "generated-header-original-unavailable")

    def test_d3d_dxgi_overlay_is_shared_not_um(self):
        result = coverage.selected_overlay_originals(
            [r"um\d3d12.idl", r"shared\dxgiformat.h", r"um\dxgiformat.h"],
            ["d3d12.idl", "dxgiformat.h"],
        )
        self.assertEqual(result, [r"shared\dxgiformat.h", r"um\d3d12.idl"])


class QueueTests(unittest.TestCase):
    def test_original_locks_are_disjoint_and_exclusions_remain_unknown(self):
        report = report_fixture()
        report["retainedFacts"].append(fact("Excluded", r"um\excluded.h"))
        report["retainedFacts"].append({
            **fact("Ambiguous", r"um\a.h"), "ownershipStatus": "ambiguous-original-candidates",
        })
        campaign = {
            "workerSessions": {"dhcp-next": "dhcp-worker", "system-next": "system-worker", "interop": "idl-worker"},
            "reservedOriginals": {"dhcp-next": [r"um\a.h"]},
        }
        queue = coverage.work_queue(report, campaign)
        paths = [original for batch in queue["batches"] for original in batch["originalPaths"]]
        self.assertEqual(len(paths), len(set(paths)))
        self.assertEqual(set(paths), {r"um\a.h", r"um\b.h", r"um\example.idl"})
        dhcp = next(batch for batch in queue["batches"] if batch["suggestedRole"] == "dhcp-next")
        self.assertEqual(dhcp["assignedSessionId"], "dhcp-worker")
        self.assertEqual(dhcp["originalPaths"], [r"um\a.h"])
        self.assertEqual(dhcp["partitionCandidates"], ["Core"])
        idl = next(batch for batch in queue["batches"] if batch["suggestedRole"] == "interop")
        self.assertEqual(idl["originals"][0]["generatedHeaderPaths"], [r"um\example.h"])
        self.assertFalse(idl["originals"][0]["nativeMapperEligible"])
        self.assertEqual(len(queue["unknownOrAmbiguousFactReferences"]), 1)

    def test_duplicate_reservations_are_case_insensitively_rejected(self):
        with self.assertRaisesRegex(ValueError, "multiple reservations"):
            coverage.work_queue(report_fixture(), {
                "reservedOriginals": {"first": [r"um\a.h"], "second": [r"UM\A.H"]},
            })

    def test_provider_overlays_are_deferred_not_assigned(self):
        report = report_fixture()
        report["selectedProviderOverlayOriginals"] = [r"um\a.h"]
        queue = coverage.work_queue(report, {})
        self.assertNotIn(r"um\a.h", [path for batch in queue["batches"] for path in batch["originalPaths"]])

    def test_continuations_are_bounded_to_twenty_five_originals(self):
        report = report_fixture()
        for index in range(24):
            original = rf"um\extra{index:02d}.h"
            report["selectedSdkOriginals"].append({"original": original, "kind": "native-header"})
            report["readyOriginalOwners"].append({"original": original, "partitionCandidates": ["Core"]})
            report["retainedFacts"].append(fact(f"Extra{index}", original))
        native = [
            batch for batch in coverage.work_queue(report, {})["batches"]
            if batch["suggestedRole"] == "system-next"
        ]
        self.assertEqual([len(batch["originalPaths"]) for batch in native], [25, 1])

    def test_expanded_native_map_preserves_rows_but_does_not_claim_ast_admission(self):
        report = report_fixture()
        report["readyOriginalOwners"] = []
        queue = coverage.work_queue(report, {})
        result = coverage.native_owner_map(report, queue)
        self.assertTrue(result["candidateOnly"])
        self.assertEqual(result["snapshot"]["sdkPackageVersion"], "test-sdk")
        self.assertEqual(result["snapshot"]["sdkPackageRoot"], r"C:\fixture-sdk")
        self.assertEqual(result["snapshot"]["sdkIncludeVersion"], "test-include")
        self.assertEqual(len(result["readyOriginalOwners"]), 2)
        self.assertEqual(result["readyOriginalOwners"][0]["supportedOS"][0]["line"], 7)
        self.assertTrue(all(owner["original"].endswith(".h") for owner in result["readyOriginalOwners"]))

    def test_idl_map_hashes_actual_original_and_keeps_nonfloor_residuals(self):
        report = report_fixture()
        report["retainedFacts"].append(fact("FLAG_A", r"um\example.idl", "synthetic-enum-explicit-member"))
        queue = coverage.work_queue(report, {"workerSessions": {"interop": "idl-worker"}})
        with tempfile.TemporaryDirectory() as temporary:
            sdk = Path(temporary)
            source = sdk / r"um\example.idl"
            source.parent.mkdir(parents=True)
            source.write_bytes(b"interface Example : IUnknown {};\r\n")
            result = coverage.idl_owner_map(report, queue, sdk)["owners"]
            self.assertEqual(len(result), 1)
            self.assertEqual(result[0]["sourceSha256"], hashlib.sha256(source.read_bytes()).hexdigest().upper())
            self.assertEqual(result[0]["generatedHeaders"], [r"um\example.h"])
            self.assertEqual(len(result[0]["facts"]), 1)
            self.assertEqual(len(result[0]["remainingNonFloorFactReferences"]), 1)
            self.assertEqual(result[0]["assignedSessionId"], "idl-worker")


class ProgressTests(unittest.TestCase):
    def generated_fixture(self):
        report = report_fixture()
        report["sourceProgressScoreboard"] = {
            "committedStrictlyAppliedNativeHeaderPaths": [r"um\a.h"],
            "committedNonBootstrapNativeHeaderCount": 1,
            "goalEligibleCommittedNativeHeaderPaths": [r"um\a.h"],
            "committedStrictlyAppliedOriginalIdlPaths": [r"um\example.idl"],
        }
        receipt = {
            "sourceCommit": "a" * 40, "count": 1, "outputs": [{
                "path": r"um\example.h", "original": r"um\example.idl",
                "beforeSha256": "0" * 64, "afterSha256": "1" * 64,
                "authoredCarrierCount": 2, "sourcePatchEvidence": ["+_Win32_AnnotateInterface_(Example, OS)"],
            }],
        }
        recipe = {"sdkPackageVersion": "test-sdk", "midl": {"outputs": [
            {"path": r"um\example.h", "source": r"um\example.idl"},
        ]}}
        return report, receipt, recipe

    def test_recipe_edges_alone_get_no_generated_header_credit(self):
        report, _, _ = self.generated_fixture()
        coverage.update_generated_observations(report, [], Path("."))
        self.assertIsNone(report["sourceProgressScoreboard"]["actuallyAffectedGeneratedHeaderCount"])
        self.assertEqual(report["sourceProgressScoreboard"]["eligiblePatchedHeaderCountKnown"], 1)

    def test_named_semantic_generated_changes_deduplicate_and_exclude_idl_filenames(self):
        report, receipt, recipe = self.generated_fixture()
        with patch.object(coverage, "git", return_value="a" * 40), \
                patch.object(coverage, "recipe_at", return_value=recipe):
            coverage.update_generated_observations(report, [receipt, receipt], Path("."))
        score = report["sourceProgressScoreboard"]
        self.assertEqual(score["actuallyAffectedGeneratedHeaderCount"], 1)
        self.assertEqual(score["eligiblePatchedHeaderCountKnown"], 2)
        self.assertEqual(score["eligiblePatchedHeaderPathsKnown"], [r"um\a.h", r"um\example.h"])
        self.assertFalse(score["generatedOutputMeasurementComplete"])

    def test_held_generated_output_keeps_measurement_but_not_goal_credit(self):
        report, receipt, recipe = self.generated_fixture()
        exclusions = [{"header": "UM/EXAMPLE.H", "reason": "No live normal-source emission route."}]
        with patch.object(coverage, "git", return_value="a" * 40), \
                patch.object(coverage, "recipe_at", return_value=recipe):
            coverage.update_generated_observations(report, [receipt, receipt], Path("."), exclusions)
        score = report["sourceProgressScoreboard"]
        self.assertEqual(score["actuallyAffectedGeneratedHeaderCount"], 1)
        self.assertEqual(score["goalEligibleObservedGeneratedHeaderCount"], 0)
        self.assertEqual(score["goalEligibleObservedGeneratedHeaderPaths"], [])
        self.assertEqual(score["eligiblePatchedHeaderCountKnown"], 1)
        self.assertEqual(score["eligiblePatchedHeaderPathsKnown"], [r"um\a.h"])
        self.assertEqual(score["goalExcludedGeneratedHeaders"], [
            {"header": r"um\example.h", "reason": "No live normal-source emission route."},
        ])

    def test_generated_goal_holds_require_observed_headers_and_reasons(self):
        valid = {"header": r"um\example.h", "reason": "Emission ownership is unknown."}
        for exclusions in (
            [{"header": r"um\unknown.h", "reason": "Not an observed output."}],
            [{"header": r"um\example.h"}],
            [valid, {**valid, "header": "UM/EXAMPLE.H"}],
        ):
            with self.subTest(exclusions=exclusions):
                report, receipt, recipe = self.generated_fixture()
                with patch.object(coverage, "git", return_value="a" * 40), \
                        patch.object(coverage, "recipe_at", return_value=recipe), \
                        self.assertRaisesRegex(ValueError, "generated header-goal exclusion"):
                    coverage.update_generated_observations(report, [receipt], Path("."), exclusions)

    def test_generated_copies_and_format_only_outputs_are_rejected(self):
        for key, value in (("afterSha256", "0" * 64), ("authoredCarrierCount", 0)):
            with self.subTest(key=key):
                report, receipt, recipe = self.generated_fixture()
                receipt["outputs"][0][key] = value
                with patch.object(coverage, "git", return_value="a" * 40), \
                        patch.object(coverage, "recipe_at", return_value=recipe), \
                        self.assertRaises(ValueError):
                    coverage.update_generated_observations(report, [receipt], Path("."))

    def test_generated_header_needs_a_strictly_applied_source_not_just_a_commit(self):
        report, receipt, recipe = self.generated_fixture()
        report["sourceProgressScoreboard"]["committedStrictlyAppliedOriginalIdlPaths"] = []
        with patch.object(coverage, "git", return_value="a" * 40), \
                patch.object(coverage, "recipe_at", return_value=recipe), \
                self.assertRaisesRegex(ValueError, "strictly applied original"):
            coverage.update_generated_observations(report, [receipt], Path("."))

    def test_strict_application_changes_only_private_copies(self):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            repo, sdk, scratch = root / "repo", root / "sdk", root / "scratch"
            repo.mkdir()
            scratch.mkdir()
            subprocess.run(["git", "init", "--quiet", str(repo)], check=True)
            original = sdk / r"um\a.h"
            original.parent.mkdir(parents=True)
            original.write_bytes(b"int before;\n")
            patch_file = repo / "generation" / "WinSDK" / "patches" / r"um\a.h.patch"
            patch_file.parent.mkdir(parents=True)
            patch_file.write_bytes(
                b"diff --git a/um/a.h b/um/a.h\n--- a/um/a.h\n+++ b/um/a.h\n"
                b"@@ -1 +1 @@\n-int before;\n+int after;\n"
            )
            rows = coverage.apply_progress(
                repo, sdk, [{"patch": r"um\a.h.patch", "original": r"um\a.h"}], scratch
            )
            self.assertEqual(rows[0]["status"], "applied-nontrivial")
            self.assertEqual(original.read_bytes(), b"int before;\n")
            self.assertEqual(list(scratch.iterdir()), [])

    def test_missing_source_does_not_count_as_a_patch(self):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            rows = coverage.apply_progress(
                root, root, [{"patch": "missing.patch", "original": r"um\missing.h"}], root
            )
            self.assertEqual(rows[0]["status"], "missing-selected-sdk-original")

    def test_first_line_crlf_preserves_canonical_strict_whitespace_rules(self):
        for first, accepted in (
            (b"#include <sal.h>", True), (b"#include <sal.h> ", False),
            (b"#include <sal.h>\t", False), (b" \t#include <sal.h>", False),
        ):
            with self.subTest(first=first), tempfile.TemporaryDirectory() as temporary:
                root = Path(temporary)
                repo, sdk, scratch = root / "repo", root / "sdk", root / "scratch"
                repo.mkdir()
                scratch.mkdir()
                subprocess.run(["git", "init", "--quiet", str(repo)], check=True)
                original = sdk / r"um\a.idl"
                original.parent.mkdir(parents=True)
                original.write_bytes(b"interface Example;\r\n")
                patch_file = repo / "generation" / "WinSDK" / "patches" / r"um\a.idl.patch"
                patch_file.parent.mkdir(parents=True)
                patch_file.write_bytes(
                    b"diff --git a/um/a.idl b/um/a.idl\n--- a/um/a.idl\n+++ b/um/a.idl\n"
                    b"@@ -1 +1,2 @@\n+" + first + b"\r\n interface Example;\r\n"
                )
                rows = coverage.apply_progress(
                    repo, sdk, [{"patch": r"um\a.idl.patch", "original": r"um\a.idl"}], scratch
                )
                self.assertEqual(rows[0]["status"], "applied-nontrivial" if accepted else "strict-apply-failed")
                self.assertEqual(original.read_bytes(), b"interface Example;\r\n")
                self.assertEqual(list(scratch.iterdir()), [])

    def test_revised_headers_deduplicate_against_baseline_and_other_receipts(self):
        report = report_fixture()
        report["sourceProgressScoreboard"] = {
            "strictlyAppliedNativeHeaderPaths": [r"um\a.h", r"shared\sal.h"],
            "strictlyAppliedNativeHeaderCount": 2,
            "strictlyAppliedOriginalIdlPaths": [],
        }
        campaign = {"sourceReceipts": [
            {"revision": "first", "originals": [r"um\a.h", r"um\b.h"]},
            {"revision": "second", "originals": [r"um\a.h", r"um\b.h"]},
        ]}
        campaign["goalExcludedNativeHeaders"] = [
            {"original": r"um\b.h", "reason": "Only partial prefixes; no complete converted fact."}
        ]
        campaign["reportedProductionGates"] = [{"partition": "Core", "state": "Parser opt-in is missing."}]
        patches = [{"patch": original + ".patch", "original": original} for original in (r"um\a.h", r"um\b.h")]
        rows = [{"original": item["original"], "status": "applied-nontrivial"} for item in patches]
        recipe = {"sdkPackageVersion": "test-sdk", "patches": [item["patch"] for item in patches]}
        with patch.object(coverage, "git", return_value="a" * 40), \
                patch.object(coverage, "recipe_at", return_value=recipe), \
                patch.object(coverage, "patch_inventory", return_value=patches), \
                patch.object(coverage, "apply_progress", return_value=rows):
            coverage.update_source_receipts(report, campaign, Path("."), Path("."), Path("."))
        score = report["sourceProgressScoreboard"]
        self.assertEqual(score["committedStrictlyAppliedNativeHeaderCount"], 3)
        self.assertEqual(score["committedNonBootstrapNativeHeaderCount"], 2)
        self.assertEqual(score["goalEligibleCommittedNativeHeaderCount"], 1)
        self.assertEqual(score["goalEligibleCommittedNativeHeaderPaths"], [r"um\a.h"])
        self.assertEqual(score["newNativeHeaderPathsBeyondSnapshot"], [r"um\b.h"])
        self.assertEqual(score["reportedProductionGates"], campaign["reportedProductionGates"])

    def test_unmeasured_baseline_is_null_not_zero(self):
        report = report_fixture()
        report["sourceProgressScoreboard"] = {
            "strictlyAppliedNativeHeaderPaths": [], "strictlyAppliedNativeHeaderCount": None,
            "strictlyAppliedOriginalIdlPaths": [],
        }
        coverage.update_source_receipts(report, {}, Path("."), Path("."), Path("."))
        self.assertIsNone(report["sourceProgressScoreboard"]["committedNonBootstrapNativeHeaderCount"])
        with self.assertRaisesRegex(ValueError, "strictly applied baseline"):
            coverage.update_source_receipts(
                report, {"sourceReceipts": [{"revision": "unverified"}]}, Path("."), Path("."), Path(".")
            )


if __name__ == "__main__":
    unittest.main()
