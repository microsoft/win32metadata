"""Inventory authored annotation inputs without scraping, compiling, or preparing the SDK."""

import argparse
import csv
import hashlib
import json
import os
import re
import shutil
import subprocess
import tempfile
from collections import Counter, defaultdict
from pathlib import Path
from xml.etree import ElementTree


HEADER_EXTENSIONS = {".h", ".hpp", ".hxx"}
IDL_EXTENSIONS = {".idl", ".odl"}
COHORT_SEED = "2978a7fe20df7cceb156a519c0215fae89d6ce5f"
PILOT = "4d276d050137a8239ba24c17de797128bd887ae6"
PUBLISHED = "9a1fd6f8526403ae3dff806c7345bd82a38c382a"
RECIPE = r"generation\WinSDK\patches\SdkHeaders.json"
COMMENT = re.compile(r"/\*.*?\*/|//[^\r\n]*", re.S)
SOURCE_BLOCKED = {
    r"um\iwscapi.h", r"um\winsatcominterfacei.h", r"um\locationapi.h",
    r"um\wcndevice.h", r"um\identityprovider.h", r"um\identitystore.h",
    r"um\rendezvoussession.h",
}
DEVICE_RESERVED = {
    r"um\cfgmgr32.h", r"um\newdev.h", r"um\winusb.h", r"um\swdevice.h",
}
TOKEN = re.compile(r"\b[A-Za-z_][A-Za-z_0-9]*\b")
MACRO = re.compile(r"\b_Win32_[A-Za-z_0-9]+_\b")
GENERATED = re.compile(r"File created by MIDL compiler|ALWAYS GENERATED file|automatically generated from [^\r\n]*\.idl", re.I)


def text(path):
    data = Path(path).read_bytes()
    if data.startswith((b"\xff\xfe", b"\xfe\xff")):
        return data.decode("utf-16")
    return data.decode("utf-8-sig", errors="surrogateescape")


def git(repo, *args):
    return subprocess.check_output(
        ["git", "-C", str(repo), "--no-pager", *args], encoding="utf-8"
    ).strip()


def git_text(repo, ref, path):
    return git(repo, "show", f"{ref}:{path.replace(chr(92), '/')}")


def relative(path, root):
    return str(path.relative_to(root)).replace("/", "\\")


def rsp_entries(content):
    # Same section boundaries as MetadataTasks.RspReader; the scraper trims rows
    # and ignores leading '#' comments in Program.ParseRspFile.
    section = None
    for number, raw in enumerate(content.splitlines(), 1):
        line = raw.strip()
        if not line or line.startswith("#"):
            continue
        if line.startswith("--"):
            section = line
        elif line.startswith("@"):
            raise ValueError(f"Nested response file needs explicit inventory support: {line}")
        elif section:
            yield section, number, line


def recipe_at(repo, ref):
    return json.loads(git_text(repo, ref, RECIPE))


def config_snapshot(repo, ref=None):
    if ref:
        names = git(repo, "ls-tree", "-r", "--name-only", ref, "--", "generation/WinSDK").splitlines()
        names = [
            name for name in names
            if name.endswith(".rsp") or name in {
                "generation/WinSDK/enums.json", "generation/WinSDK/autoTypes.json",
                "generation/WinSDK/functionPointerFixups.json",
            }
        ]
        request = "".join(f"{ref}:{name}\n" for name in names).encode()
        output = subprocess.run(
            ["git", "-C", str(repo), "cat-file", "--batch"],
            input=request, stdout=subprocess.PIPE, check=True,
        ).stdout
        result, position = {}, 0
        for name in names:
            end = output.index(b"\n", position)
            header = output[position:end].split()
            if len(header) != 3 or header[1] != b"blob":
                raise ValueError(f"Missing configuration blob: {ref}:{name}")
            size = int(header[2])
            result[name.replace("/", "\\")] = output[end + 1:end + 1 + size].decode("utf-8-sig")
            position = end + size + 2
        if position != len(output):
            raise ValueError("Unexpected trailing Git batch data")
        return result
    project = repo / "generation" / "WinSDK"
    paths = list(project.glob("*.rsp")) + list((project / "Partitions").rglob("*.rsp"))
    paths += [project / name for name in ("enums.json", "autoTypes.json", "functionPointerFixups.json")]
    return {relative(path, repo): text(path) for path in sorted(paths)}


def classify_rsp(path, section, value, enum_names):
    filename = Path(path).name.lower()
    if filename == "documentationmappings.rsp":
        return "documentation-tooling", "derived"
    if filename == "libmappings.rsp":
        return "sdk-import-library-scan", "derived"
    if filename == "requirednamespacesfornames.rsp" or section in {"--namespace", "--with-namespace"}:
        return "namespace-resolution", "global/parser"
    if section in {"--config", "--traverse", "--std", "--additional", "--include-directory",
                   "--file", "--headerFile", "--output", "--with-using", "--typeImport"}:
        return "tooling-configuration", "global/parser"
    if section in {"--remap", "--exclude", "--exclude-auto-remap", "--preserve-auto-fnptr-level",
                   "--reducePointerLevel"}:
        return "parser-name-type-pointer-fix", "global/parser"
    if section == "--with-librarypath":
        return "manual-import-review", "review"
    if section == "--with-setlasterror":
        return "setLastError", "authored"
    if section == "--enumAddition":
        return "enum-member-addition", "authored"
    if section == "--enumMakeFlags":
        return "enum-flags", "authored"
    if section in {"--memberRemap", "--with-attribute"}:
        if re.search(r"\bAgile\b", value.split("=", 1)[-1]):
            return "agile-intentional-removal-pending", "intentional-removal"
        if "AssociatedEnum(" in value:
            return "associated-enum-use", "authored"
        if "SupportedOSPlatform(" in value:
            return "supportedOS", "authored"
        rhs = value.split("=", 1)[-1]
        if rhs in enum_names:
            return "direct-enum-use", "authored"
        if section == "--memberRemap" and not rhs.startswith("["):
            return "member-type-override-review", "review"
        if filename == "constantsscraper.settings.rsp" and "NativeTypeName(" in value:
            return "constant-native-type-recovery", "global/parser"
        return "declaration-attribute-override", "authored"
    if section == "--with-type":
        rhs = value.split("=", 1)[-1]
        if rhs in enum_names:
            return "direct-enum-use", "authored"
        return "native-type-override-review", "review"
    return "unclassified-response-option", "unknown"


def configuration_facts(files, known_enum_names=()):
    enums_path = r"generation\WinSDK\enums.json"
    auto_path = r"generation\WinSDK\autoTypes.json"
    callback_path = r"generation\WinSDK\functionPointerFixups.json"
    enums = json.loads(files[enums_path])["items"]
    enum_names = {item.get("name") or item["addUsesTo"] for item in enums} | set(known_enum_names)
    facts, sections = [], []

    def add(path, locator, category, treatment, symbol, value, **extra):
        facts.append({
            "source": path, "locator": locator, "category": category,
            "treatment": treatment, "symbol": symbol, "value": value, **extra,
        })

    for path, content in sorted(files.items()):
        if not path.endswith(".rsp"):
            continue
        groups = defaultdict(list)
        for section, line, value in rsp_entries(content):
            groups[section].append(value)
            category, treatment = classify_rsp(path, section, value, enum_names)
            if treatment not in {"derived", "global/parser"} or category == "parser-name-type-pointer-fix":
                add(path, f"line:{line}", category, treatment, value.split("=", 1)[0], value)
        for section, values in groups.items():
            sections.append({
                "source": path, "section": section, "rows": len(values),
                "distinctRows": len(set(values)), "duplicateRows": len(values) - len(set(values)),
                "treatments": dict(Counter(classify_rsp(path, section, value, enum_names)[1] for value in values)),
            })
    for index, item in enumerate(enums):
        name = item.get("name") or item["addUsesTo"]
        pointer = f"/items/{index}"
        hints = []
        populate = item.get("autoPopulate")
        if isinstance(populate, dict) and populate.get("header"):
            hints.append(populate["header"].lower())
        if "name" in item:
            add(enums_path, pointer, "synthetic-enum-definition", "authored", name, {
                key: value for key, value in item.items() if key not in {"members", "uses"}
            }, headerHints=hints)
        for member_index, member in enumerate(item.get("members", [])):
            add(enums_path, f"{pointer}/members/{member_index}", "synthetic-enum-explicit-member",
                "authored", member["name"], member, enum=name, headerHints=hints)
        for use_index, use in enumerate(item.get("uses", [])):
            owner = use.get("interface") or use.get("struct") or use.get("method", "")
            parts = [owner]
            if use.get("interface") and use.get("method"):
                parts.append(use["method"])
            parts.append(use.get("parameter") or use.get("field", ""))
            add(enums_path, f"{pointer}/uses/{use_index}", "direct-enum-use", "authored",
                "::".join(part for part in parts if part), name)
    auto_types = json.loads(files[auto_path])
    for index, item in enumerate(auto_types):
        for key in ("CloseApi", "InvalidHandleValues", "AlsoUsableFor"):
            if key in item:
                add(auto_path, f"/{index}/{key}", {
                    "CloseApi": "cleanup-api", "InvalidHandleValues": "invalid-handle-values",
                    "AlsoUsableFor": "also-usable-for",
                }[key], "authored", item["Name"], item[key])
    callbacks = json.loads(files[callback_path])
    for index, item in enumerate(callbacks):
        add(callback_path, f"/{index}", "callback-parser-fix", "global/parser", item["name"], item)
    summary = {
        "categories": dict(Counter(fact["category"] for fact in facts)),
        "responseSections": sections, "enumConfigurationObjects": len(enums),
        "enumDefinitions": sum("name" in item for item in enums),
        "enumUseExtensionObjects": sum("addUsesTo" in item for item in enums),
        "enumExplicitMembers": sum(len(item.get("members", [])) for item in enums),
        "enumAutoPopulateDefinitions": sum(bool(item.get("autoPopulate")) for item in enums),
        "enumAutoPopulatedActualMemberCount": None,
        "enumDirectUses": sum(len(item.get("uses", [])) for item in enums),
        "autoTypeProjectionObjects": len(auto_types), "callbackParserFixObjects": len(callbacks),
    }
    return facts, summary


def fact_key(fact):
    return (fact["source"], fact["category"], fact["symbol"],
            json.dumps(fact["value"], sort_keys=True, separators=(",", ":")))


def header_origin(header, content, idls):
    generated = bool(GENERATED.search(content[:12000])) or (header.startswith("winrt\\") and bool(idls))
    return {
        "source": COMMENT.sub("", content), "generated": generated,
        "originals": idls if generated else [header],
        "ownershipBasis": "generated-header-matching-idl-input" if generated and idls else (
            "generated-header-original-unavailable" if generated else (
                "native-header-with-idl-sibling-not-assumed-generated" if idls else "native-header-input"
            )
        ),
    }


def removed_facts(before, after):
    remaining = Counter(fact_key(fact) for fact in after)
    removed = []
    for fact in before:
        key = fact_key(fact)
        if remaining[key]:
            remaining[key] -= 1
        else:
            removed.append(dict(fact))
    return removed


def patch_inventory(project, recipe, repo=None, ref=None):
    patches = []
    for name in recipe["patches"]:
        content = git_text(repo, ref, relative(project / "patches" / name, repo)) if ref else text(project / "patches" / name)
        targets = re.findall(r"(?m)^\+\+\+ b/([^\r\n]+)", content)
        if len(targets) != 1:
            raise ValueError(f"A coverage patch must identify one original: {name}")
        target = targets[0].removeprefix("generation/WinSDK/RecompiledIdlHeaders/").replace("/", "\\").lower()
        added = "\n".join(line[1:] for line in content.splitlines() if line.startswith("+") and not line.startswith("+++"))
        context = "\n".join(line[1:] for line in content.splitlines() if line.startswith(("+", " ")))
        macros = Counter(MACRO.findall(added))
        patches.append({
            "patch": name, "original": target,
            "annotationMacroOccurrences": dict(sorted(macros.items())),
            "authoredAnnotationSource": any(macro not in {
                "_Win32_AnnotateInterface_", "_Win32_AnnotateMethod_",
            } for macro in macros),
            "_context": context,
        })
    return patches


def apply_progress(repo, sdk, patches, scratch, source_ref=None):
    rows = []
    with tempfile.TemporaryDirectory(prefix="sdk-patch-check-", dir=scratch) as temporary:
        destination = Path(temporary)
        for patch in patches:
            original = patch["original"]
            source = sdk / original
            row = {"patch": patch["patch"], "original": original}
            if not source.is_file():
                rows.append({**row, "status": "missing-selected-sdk-original"})
                continue
            target = destination / original
            target.parent.mkdir(parents=True, exist_ok=True)
            shutil.copyfile(source, target)
            before = target.read_bytes()
            arguments = [
                "git", "-c", "core.whitespace=blank-at-eol,blank-at-eof,space-before-tab,cr-at-eol",
                "-C", str(repo), "apply", "--unsafe-paths", "-p1",
                f"--directory={destination}", "--whitespace=error-all",
            ]
            if source_ref:
                path = destination / "patch-inputs" / patch["patch"]
                path.parent.mkdir(parents=True, exist_ok=True)
                path.write_bytes(subprocess.check_output([
                    "git", "-C", str(repo), "show",
                    f"{source_ref}:generation/WinSDK/patches/{patch['patch'].replace(chr(92), '/')}",
                ]))
            else:
                path = repo / "generation" / "WinSDK" / "patches" / patch["patch"]
            path = str(path)
            check = subprocess.run([*arguments, "--check", "--", path], capture_output=True, text=True)
            if check.returncode:
                rows.append({**row, "status": "strict-apply-failed", "error": check.stderr.strip()})
                continue
            applied = subprocess.run([*arguments, "--", path], capture_output=True, text=True)
            if applied.returncode:
                raise RuntimeError(f"Patch changed between check and apply: {path}\n{applied.stderr}")
            rows.append({**row, "status": "applied-nontrivial" if before != target.read_bytes() else "no-op"})
    return rows


def update_source_receipts(report, campaign, repo, sdk, scratch):
    scoreboard = report["sourceProgressScoreboard"]
    baseline_checked = scoreboard["strictlyAppliedNativeHeaderCount"] is not None
    if campaign.get("sourceReceipts") and not baseline_checked:
        raise ValueError("Source receipt totals require a strictly applied baseline")
    receipts = []
    originals = {item["original"]: item["kind"] for item in report["selectedSdkOriginals"]}
    overlays = set(report.get("selectedProviderOverlayOriginals", []))
    for receipt in campaign.get("sourceReceipts", []):
        revision = git(repo, "rev-parse", f"{receipt['revision']}^{{commit}}")
        recipe = recipe_at(repo, revision)
        if recipe["sdkPackageVersion"] != report["snapshot"]["sdkPackageVersion"]:
            raise ValueError(f"Source receipt selects a different SDK: {revision}")
        requested = {original.replace("/", "\\").lower() for original in receipt["originals"]}
        if len(requested) != len(receipt["originals"]):
            raise ValueError(f"Duplicate source receipt original: {revision}")
        if requested - set(originals) or requested & overlays:
            raise ValueError(f"Receipt has unbound selected-source owners: {revision}")
        selected = {**recipe, "patches": [
            name for name in recipe["patches"]
            if name.removesuffix(".patch").replace("/", "\\").lower() in requested
        ]}
        patches = patch_inventory(repo / "generation" / "WinSDK", selected, repo, revision)
        if {patch["original"] for patch in patches} != requested:
            raise ValueError(f"Receipt originals do not match committed recipe patches: {revision}")
        for patch in patches:
            if Path(patch["original"]).suffix.lower() in HEADER_EXTENSIONS and originals[patch["original"]] != "native-header":
                raise ValueError(f"A generated header is not an authored original: {patch['original']}")
        receipts.append({
            **receipt, "revision": revision,
            "strictApplyRows": apply_progress(repo, sdk, patches, scratch, revision),
        })
    native = set(scoreboard["strictlyAppliedNativeHeaderPaths"])
    idls = set(scoreboard["strictlyAppliedOriginalIdlPaths"])
    for receipt in receipts:
        for row in receipt["strictApplyRows"]:
            if row["status"] == "applied-nontrivial":
                (native if originals[row["original"]] == "native-header" else idls).add(row["original"])
    exclusions = {}
    for item in campaign.get("goalExcludedNativeHeaders", []):
        original = item["original"].replace("/", "\\").lower()
        if original not in native or original in exclusions or not item.get("reason"):
            raise ValueError(f"Invalid or duplicate header-goal exclusion: {original}")
        exclusions[original] = {**item, "original": original}
    eligible_native = native - {r"shared\sal.h"} - set(exclusions)
    scoreboard.update({
        "laterSourceConversionsReportedByCoordinator": campaign.get("laterSourceReports"),
        "sourceReceipts": receipts,
        "receiptStrictApplyStatusCounts": dict(Counter(
            row["status"] for receipt in receipts for row in receipt["strictApplyRows"]
        )),
        "committedStrictlyAppliedNativeHeaderPaths": sorted(native),
        "committedStrictlyAppliedNativeHeaderCount": len(native) if baseline_checked else None,
        "committedNonBootstrapNativeHeaderCount": len(native - {r"shared\sal.h"}) if baseline_checked else None,
        "goalEligibleCommittedNativeHeaderPaths": sorted(eligible_native),
        "goalEligibleCommittedNativeHeaderCount": len(eligible_native) if baseline_checked else None,
        "goalExcludedNativeHeaders": list(exclusions.values()),
        "newNativeHeaderPathsBeyondSnapshot": sorted(native - set(scoreboard["strictlyAppliedNativeHeaderPaths"])),
        "committedStrictlyAppliedOriginalIdlPaths": sorted(idls),
        "committedStrictlyAppliedOriginalIdlCount": len(idls) if baseline_checked else None,
        "reportedProductionGates": campaign.get("reportedProductionGates", []),
        "receiptQualification": "Strict original patch application, not compilation or whole-header/partition qualification. Revised original paths count once.",
    })
    if campaign.get("currentIntegratedRevision"):
        revision = git(repo, "rev-parse", f"{campaign['currentIntegratedRevision']}^{{commit}}")
        if recipe_at(repo, revision)["sdkPackageVersion"] != report["snapshot"]["sdkPackageVersion"]:
            raise ValueError("Integrated configuration selects a different SDK; regenerate source ownership")
        facts, summary = configuration_facts(config_snapshot(repo, revision), {
            fact["symbol"] for fact in report["retainedFacts"] if fact["category"] == "synthetic-enum-definition"
        })
        scoreboard["latestIntegratedConfiguration"] = {
            "revision": revision,
            "basis": "Exact shared-Git configuration inventory, not a new SDK declaration-binding or qualification pass.",
            "retainedCategories": summary["categories"],
            "retainedTreatments": dict(Counter(fact["treatment"] for fact in facts)),
            "removedSinceSourceSnapshot": dict(Counter(
                fact["category"] for fact in removed_facts(report["retainedFacts"], facts)
            )),
            "remainingFactsNotInSnapshot": len(removed_facts(facts, report["retainedFacts"])),
            "declarationOwnershipAtRevision": "Not re-established; the full inventory and owner-map coordinates remain pinned to sourceSnapshot.",
        }


def work_queue(report, campaign):
    grouped = defaultdict(list)
    owner_candidates = defaultdict(set)
    excluded = set(report["excludedOriginals"]) | set(report.get("selectedProviderOverlayOriginals", []))
    for fact in report["retainedFacts"]:
        if fact["treatment"] != "authored" or fact["ownershipStatus"] != "unique-original-candidate":
            continue
        original = fact["originalCandidates"][0]
        if original not in excluded:
            grouped[original].append({
                key: fact[key] for key in ("source", "locator", "category", "symbol")
            })
            owner_candidates[original].update(fact["partitionCandidates"])
    ready = {owner["original"]: owner for owner in report["readyOriginalOwners"]}
    by_original = {item["original"]: item for item in report["selectedSdkOriginals"]}
    namespace = {item["name"]: item["namespace"] for item in report["partitions"]}
    reserved = {}
    for role, originals in campaign.get("reservedOriginals", {}).items():
        for original in originals:
            original = original.replace("/", "\\").lower()
            if original in reserved:
                raise ValueError(f"Original has multiple reservations: {original}")
            reserved[original] = role
    outputs = defaultdict(list)
    for header in report["generatedSdkHeaders"]:
        for original in header["originalCandidates"]:
            outputs[original].append(header["header"])
    roles = defaultdict(list)
    for original, facts in sorted(grouped.items()):
        source = by_original[original]
        owners = ready.get(original, {}).get("partitionCandidates", sorted(owner_candidates[original]))
        namespaces = [value for owner in owners for value in namespace.get(owner, [])]
        if original in reserved:
            role = reserved[original]
        elif source["kind"] == "IDL/ODL":
            role = "interop"
        elif original in ready and any(value.startswith((
            "Windows.Win32.Devices", "Windows.Win32.Graphics.Printing", "Windows.Win32.Graphics.Imaging",
            "Windows.Win32.Media.Audio", "Windows.Win32.Media.Multimedia",
        )) for value in namespaces):
            role = "device-next"
        elif original in ready and any(owner == "NetMgmt" for owner in owners):
            role = "dhcp-next"
        elif original in ready and any(owner in {
            "Dhcp", "NetMgmt", "WinSock", "WinInet", "WinHttp", "HttpServer", "Ldap", "Ndis", "NWifi",
            "WindowsFilteringPlatform", "WindowsFirewall", "WebDav", "Wnet", "Rpc", "Nla",
        } for owner in owners) or (original in ready and any(
            value.startswith("Windows.Win32.Network") for value in namespaces
        )):
            role = "network-next"
        elif original in ready:
            role = "system-next"
        else:
            role = "bulk"
        roles[role].append({
            "original": original, "kind": source["kind"], "partitionCandidates": owners,
            "remainingCategories": dict(Counter(fact["category"] for fact in facts)),
            "factReferences": facts,
            "generatedHeaderPaths": sorted(outputs[original]),
            "generatedHeaderMappingBasis": "shipped generated header to same-stem original IDL; no fresh MIDL output claim",
            "ownershipEvidence": "native-declarator-candidate" if original in ready else "unique-source-candidate-needs-AST-binding",
            "nativeMapperEligible": source["kind"] == "native-header" and any(
                fact["category"] in {"supportedOS", "setLastError"} for fact in facts
            ),
        })
    batches = []
    for role, originals in sorted(roles.items()):
        originals.sort(key=lambda item: (-len(item["factReferences"]), item["original"]))
        for start in range(0, len(originals), 25):
            session = campaign.get("workerSessions", {}).get(role)
            batches.append({
                "id": f"{role}-{start // 25 + 1:03d}", "suggestedRole": role,
                "state": "reserved" if session else "unclaimed",
                "assignedSessionId": session,
                "originals": originals[start:start + 25],
                "originalPaths": [item["original"] for item in originals[start:start + 25]],
                "partitionCandidates": sorted({
                    owner for item in originals[start:start + 25] for owner in item["partitionCandidates"]
                }),
            })
    return {
        "schemaVersion": 1, "kind": "single-writer-sdk-annotation-work-queue",
        "sourceSnapshot": report["snapshot"], "inventoryPath": report["snapshot"]["inventoryPath"],
        "singleWriterSession": campaign.get("singleWriterSession"),
        "singleWriterWorkspaceSessionId": campaign.get("singleWriterWorkspaceSessionId"),
        "claimProtocol": "Workers request exact batch IDs/paths from the single writer before new authoring. Existing in-flight claims take precedence; unclaimed suggested roles are not authorization to overlap. Report committed SHA, exact changed originals, and actual strict-apply/generated-output evidence.",
        "deadlineUtc": campaign.get("deadlineUtc"), "targetUniquePatchedHeaderOwners": campaign.get("target"),
        "countsBySuggestedRole": {role: len(originals) for role, originals in sorted(roles.items())},
        "nativeMapper": campaign.get("nativeMapper"),
        "originalIdlAuthoring": campaign.get("originalIdlAuthoring"),
        "deferredSelectedProviderOverlayOriginals": report.get("selectedProviderOverlayOriginals", []),
        "unknownOrAmbiguousFactReferences": [{
            key: fact[key] for key in ("source", "locator", "category", "symbol", "ownershipStatus")
        } for fact in report["retainedFacts"]
            if fact["treatment"] == "authored" and fact["ownershipStatus"] != "unique-original-candidate"],
        "batches": batches,
    }


def idl_owner_map(report, queue, sdk):
    owners = []
    for batch in queue["batches"]:
        for item in batch["originals"]:
            if item["kind"] != "IDL/ODL":
                continue
            facts = [
                fact for fact in report["retainedFacts"]
                if fact["ownershipStatus"] == "unique-original-candidate"
                and fact["originalCandidates"] == [item["original"]]
                and fact["category"] in {"supportedOS", "setLastError"}
            ]
            owners.append({
                "original": item["original"],
                "sourceSha256": hashlib.sha256((sdk / item["original"]).read_bytes()).hexdigest().upper(),
                "generatedHeaders": item["generatedHeaderPaths"],
                "partitionCandidates": item["partitionCandidates"],
                "facts": facts,
                "remainingNonFloorFactReferences": [
                    fact for fact in item["factReferences"]
                    if fact["category"] not in {"supportedOS", "setLastError"}
                ],
                "assignedSessionId": batch["assignedSessionId"],
                "batchId": batch["id"],
            })
    return {"schemaVersion": 1, "sourceSnapshot": report["snapshot"], "owners": owners}


def native_owner_map(report, queue):
    originals = {
        item["original"]: item for batch in queue["batches"] for item in batch["originals"]
        if item["kind"] == "native-header"
    }
    grouped = defaultdict(lambda: {"supportedOS": [], "setLastError": []})
    for fact in report["retainedFacts"]:
        if fact["category"] not in {"supportedOS", "setLastError"} or fact["ownershipStatus"] != "unique-original-candidate":
            continue
        original = fact["originalCandidates"][0]
        if original in originals:
            grouped[original][fact["category"]].append({
                "symbol": fact["symbol"], "value": fact["value"], "source": fact["source"],
                "line": int(fact["locator"].removeprefix("line:")),
            })
    return {
        "schemaVersion": 1, "snapshot": report["snapshot"],
        "candidateOnly": True,
        "ownershipEvidence": "Existing inventory source candidates, not AST admission; the native writer must retain every unbound/unsupported fact.",
        "readyOriginalOwners": [{
            "original": original, "partitionCandidates": originals[original]["partitionCandidates"], **values,
        } for original, values in sorted(grouped.items())],
    }


def selected_overlay_originals(originals, overlay_files):
    targets = {
        ("shared\\" if Path(name).stem == "dxgiformat" else "um\\") + name.lower()
        for name in overlay_files
    }
    return sorted(set(originals) & targets)


def update_generated_observations(report, observations, repo, goal_excluded_headers=()):
    score = report["sourceProgressScoreboard"]
    selected = {
        item["original"] for item in report["selectedSdkOriginals"] if item["kind"] == "native-header"
    } | {item["header"] for item in report["generatedSdkHeaders"]}
    actual = set()
    receipts = []
    for observation in observations:
        receipt = json.loads(text(observation)) if isinstance(observation, str) else observation
        revision = git(repo, "rev-parse", f"{receipt['sourceCommit']}^{{commit}}")
        recipe = recipe_at(repo, revision)
        if recipe["sdkPackageVersion"] != report["snapshot"]["sdkPackageVersion"]:
            raise ValueError("Generated observations select a different SDK")
        outputs = {item["path"].replace("/", "\\").lower(): item for item in recipe["midl"]["outputs"]}
        seen = set()
        for item in receipt["outputs"]:
            header = item["path"].replace("/", "\\").lower()
            original = item["original"].replace("/", "\\").lower()
            if header in seen or header not in selected or header not in outputs:
                raise ValueError(f"Generated observation has a duplicate or unbound header: {header}")
            if outputs[header]["source"].lower() != original or original not in score["committedStrictlyAppliedOriginalIdlPaths"]:
                raise ValueError(f"Generated observation lacks a strictly applied original: {header}")
            if item["authoredCarrierCount"] <= 0 or not item["sourcePatchEvidence"]:
                raise ValueError(f"Generated observation has no authored semantic change: {header}")
            if item["beforeSha256"].lower() == item["afterSha256"].lower():
                raise ValueError(f"Unchanged generated bytes cannot receive credit: {header}")
            if not all(re.fullmatch("[0-9A-Fa-f]{64}", item[key]) for key in ("beforeSha256", "afterSha256")):
                raise ValueError(f"Invalid generated observation hashes: {header}")
            seen.add(header)
        if receipt["count"] != len(seen):
            raise ValueError("Generated observation count does not match its named outputs")
        actual.update(seen)
        receipts.append({"evidencePath": observation if isinstance(observation, str) else None, **receipt})
    exclusions = {}
    for item in goal_excluded_headers:
        header = item["header"].replace("/", "\\").lower()
        if header not in actual or header in exclusions or not item.get("reason"):
            raise ValueError(f"Invalid or duplicate generated header-goal exclusion: {header}")
        exclusions[header] = {**item, "header": header}
    eligible_generated = actual - set(exclusions)
    score["generatedOutputObservations"] = receipts
    score["actuallyAffectedGeneratedHeaderPaths"] = sorted(actual) if receipts else None
    score["actuallyAffectedGeneratedHeaderCount"] = len(actual) if receipts else None
    score["goalExcludedGeneratedHeaders"] = list(exclusions.values())
    score["goalEligibleObservedGeneratedHeaderPaths"] = sorted(eligible_generated) if receipts else None
    score["goalEligibleObservedGeneratedHeaderCount"] = len(eligible_generated) if receipts else None
    score["generatedOutputMeasurementComplete"] = False
    score["generatedOutputUnknownReason"] = (
        "Only named, hash-different, semantically changed outputs from producer receipts count; other outputs remain unmeasured."
        if receipts else "This inventory does not run MIDL; recipe output edges are not changed-output evidence."
    )
    native = set(score["goalEligibleCommittedNativeHeaderPaths"])
    score["eligiblePatchedHeaderPathsKnown"] = sorted(native | eligible_generated)
    score["eligiblePatchedHeaderCountKnown"] = len(native | eligible_generated) if score["committedNonBootstrapNativeHeaderCount"] is not None else None
    score["generatedEvidenceScope"] = "Producer-observed prepared bytes/carriers, checked against shared-Git output ownership and inventory strict original applications; not a fresh MIDL run or full qualification."


def write_operational_outputs(report, campaign, args, sdk):
    if args.queue_output:
        queue = work_queue(report, campaign)
        queue["sourceReceipts"] = report["sourceProgressScoreboard"].get("sourceReceipts", [])
        if args.native_owner_output:
            args.native_owner_output.parent.mkdir(parents=True, exist_ok=True)
            args.native_owner_output.write_text(
                json.dumps(native_owner_map(report, queue), separators=(",", ":")) + "\n", encoding="utf-8"
            )
            queue["nativeOwnerMapPath"] = str(args.native_owner_output.resolve())
        if args.idl_owner_output:
            queue["originalIdlOwnerMapPath"] = str(args.idl_owner_output.resolve())
        args.queue_output.parent.mkdir(parents=True, exist_ok=True)
        args.queue_output.write_text(json.dumps(queue, indent=2) + "\n", encoding="utf-8")
        if args.idl_owner_output:
            args.idl_owner_output.parent.mkdir(parents=True, exist_ok=True)
            args.idl_owner_output.write_text(
                json.dumps(idl_owner_map(report, queue, sdk), separators=(",", ":")) + "\n", encoding="utf-8"
            )
    if args.scoreboard_output:
        args.scoreboard_output.parent.mkdir(parents=True, exist_ok=True)
        args.scoreboard_output.write_text(
            json.dumps(report["sourceProgressScoreboard"], indent=2) + "\n", encoding="utf-8"
        )


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--output", type=Path, required=True)
    parser.add_argument("--ledger", type=Path)
    parser.add_argument("--refresh", action="store_true",
                        help="Refresh reservations and strict committed-source receipts from the existing output inventory")
    parser.add_argument("--sdk-package-root", type=Path)
    parser.add_argument("--early", action="store_true", help="Only emit the quickly usable native OS/error owner map")
    parser.add_argument("--baseline-ref", help="Sidecar-difference baseline; defaults to the merge base with main")
    parser.add_argument("--queue-output", type=Path)
    parser.add_argument("--native-owner-output", type=Path, help="Expanded existing-input native OS/error candidate map")
    parser.add_argument("--idl-owner-output", type=Path, help="Normalized original-IDL input for the reserved source writer")
    parser.add_argument("--scoreboard-output", type=Path)
    parser.add_argument("--strict-apply", action="store_true",
                        help="Strictly apply each active patch to small private copies of its actual selected-SDK input")
    parser.add_argument("--campaign", type=Path, help="Session-local worker reservations and deadline, never inferred from source")
    args = parser.parse_args()
    if (args.idl_owner_output or args.native_owner_output) and not args.queue_output:
        parser.error("Owner-map outputs require --queue-output")
    if not args.refresh and not args.ledger:
        parser.error("--ledger is required for a fresh inventory")
    campaign = json.loads(text(args.campaign)) if args.campaign else {}
    args.output.parent.mkdir(parents=True, exist_ok=True)
    repo = Path(__file__).resolve().parent.parent
    project = repo / "generation" / "WinSDK"
    recipe = json.loads(text(project / "patches" / "SdkHeaders.json"))
    packages = ElementTree.parse(repo / "BuildTools" / "BuildTools.proj")
    version = next(
        item.attrib["Version"] for item in packages.iter("PackageReference")
        if item.attrib.get("Include") == "Microsoft.Windows.SDK.CPP"
    )
    if version != recipe["sdkPackageVersion"]:
        raise ValueError("BuildTools and the header recipe select different SDK packages")
    cache = Path(os.environ.get("NUGET_PACKAGES", str(Path.home() / ".nuget" / "packages")))
    package = args.sdk_package_root or cache / "microsoft.windows.sdk.cpp" / version
    include_versions = sorted((package / "c" / "include").iterdir())
    if len(include_versions) != 1:
        raise ValueError("Pass an SDK package containing exactly one include-version directory")
    sdk = include_versions[0]
    if args.refresh:
        report = json.loads(text(args.output))
        if report["snapshot"]["configurationGitTree"] != git(repo, "rev-parse", "HEAD:generation/WinSDK"):
            raise ValueError("Production tree changed; regenerate the inventory before refreshing it")
        if git(repo, "diff", "--name-only", "HEAD", "--", "generation/WinSDK"):
            raise ValueError("Production inputs are dirty; a frozen inventory cannot refresh their coverage")
        if report["snapshot"]["sdkPackageVersion"] != version or report["snapshot"]["sdkIncludeVersion"] != sdk.name:
            raise ValueError("Selected SDK changed; regenerate the inventory before refreshing it")
        if not report["sourceProgressScoreboard"]["committedPatchInputs"]:
            raise ValueError("A dirty-input inventory cannot supply committed baseline counts")
        if campaign.get("sourceReceipts") and not report["sourceProgressScoreboard"]["strictApplyRows"]:
            raise ValueError("Committed source receipts require a strictly applied baseline inventory")
        report["selectedProviderOverlayOriginals"] = selected_overlay_originals(
            [item["original"] for item in report["selectedSdkOriginals"]],
            report["additionalSelectedSourceProviders"][0]["publicIncludeFiles"],
        )
        report["scope"]["selectedProviderOverlayOriginalsDeferred"] = len(report["selectedProviderOverlayOriginals"])
        update_source_receipts(report, campaign, repo, sdk, args.output.parent)
        update_generated_observations(
            report, campaign.get("generatedOutputObservations", []), repo,
            campaign.get("goalExcludedGeneratedHeaders", []),
        )
        write_operational_outputs(report, campaign, args, sdk)
        args.output.write_text(json.dumps(report, separators=(",", ":")) + "\n", encoding="utf-8")
        print(json.dumps({
            "output": str(args.output),
            "committedNonBootstrapNativeHeaders": report["sourceProgressScoreboard"]["committedNonBootstrapNativeHeaderCount"],
            "goalEligibleNativeHeaders": report["sourceProgressScoreboard"]["goalEligibleCommittedNativeHeaderCount"],
            "observedGeneratedHeaders": report["sourceProgressScoreboard"]["actuallyAffectedGeneratedHeaderCount"],
            "goalEligibleObservedGeneratedHeaders": report["sourceProgressScoreboard"]["goalEligibleObservedGeneratedHeaderCount"],
            "eligiblePatchedHeadersKnown": report["sourceProgressScoreboard"]["eligiblePatchedHeaderCountKnown"],
            "newNativeHeadersBeyondSnapshot": len(report["sourceProgressScoreboard"]["newNativeHeaderPathsBeyondSnapshot"]),
            "receiptStrictApplyStatusCounts": report["sourceProgressScoreboard"]["receiptStrictApplyStatusCounts"],
            "scopeRescanned": False,
        }, indent=2))
        return
    ledger = json.loads(text(args.ledger))
    sdk_files = {
        relative(path, sdk).lower(): path
        for root in ("um", "shared", "winrt", "ucrt")
        for path in (sdk / root).rglob("*") if path.is_file()
    }
    sdk_headers = {key: path for key, path in sdk_files.items() if path.suffix.lower() in HEADER_EXTENSIONS}
    sdk_idls = {key: path for key, path in sdk_files.items() if path.suffix.lower() in IDL_EXTENSIONS}
    headers_by_name = defaultdict(list)
    for key, path in sdk_headers.items():
        headers_by_name[path.name.lower()].append(key)
    source_cache = {}

    def source_info(key):
        if key not in source_cache:
            path = sdk_headers[key]
            source = text(path)
            stem = str(Path(key).with_suffix("")).lower()
            idls = [stem + ext for ext in (".idl", ".odl") if stem + ext in sdk_idls]
            source_cache[key] = header_origin(key, source, idls)
        return source_cache[key]

    header_partitions = defaultdict(set)
    partitions = []
    for main_cpp in sorted((project / "Partitions").rglob("main.cpp")):
        name = main_cpp.parent.name
        settings = main_cpp.parent / "settings.rsp"
        entries = list(rsp_entries(text(settings))) if settings.exists() else []
        headers = [
            value[len("<IncludeRoot>"):].lstrip("\\/").replace("/", "\\").lower()
            for section, _, value in entries
            if section == "--traverse" and value.startswith("<IncludeRoot>")
        ]
        for header in headers:
            header_partitions[header].add(name)
        partitions.append({
            "name": name, "traverseHeaders": headers,
            "namespace": [value for section, _, value in entries if section == "--namespace"],
            "annotationParserOptIn": any(
                section == "--config" and value == "parse-win32-annotations"
                for section, _, value in entries
            ),
        })

    seed, pilot = recipe_at(repo, COHORT_SEED), recipe_at(repo, PILOT)
    cohort = sorted({
        path[:-len(".patch")].lower()
        for path in seed["patches"] if path not in pilot["patches"]
    })
    if len(cohort) != ledger["coverage"]["targetOriginalArtifactsInThisLedger"]:
        raise ValueError("Original-source cohort does not reconcile with the frozen ledger")
    covered = {path[:-len(".patch")].lower() for path in recipe["patches"]}
    covered.update(cohort)
    covered.update(path["source"].lower() for path in recipe.get("midl", {}).get("outputs", []))
    drafts = {path.lower() for path in ledger["coverage"]["remainingOriginalHeaderDrafts"]}
    doc_headers = defaultdict(set)
    with (repo / "scripts" / "ApiInfo.csv").open(encoding="utf-8-sig", newline="") as stream:
        for row in csv.DictReader(stream):
            for name in (row["Name"], row["Title"]):
                if name:
                    doc_headers[name].add(row["Header"].lower())

    facts = []
    ready = defaultdict(lambda: {"supportedOS": [], "setLastError": []})
    for filename, category in (("supportedOS.rsp", "supportedOS"), ("WithSetLastError.rsp", "setLastError")):
        for section, line, value in rsp_entries(text(project / filename)):
            symbol = value.split("=", 1)[0]
            probe = symbol.split("::", 1)[0]
            candidates = set()
            for header in doc_headers.get(probe, ()):
                for key in headers_by_name.get(header, ()):
                    info = source_info(key)
                    if re.search(rf"\b{re.escape(probe)}\b", info["source"]):
                        candidates.add(key)
            declarations = []
            for key in sorted(candidates):
                info = source_info(key)
                if info["generated"]:
                    continue
                if "declaratorSource" not in info:
                    info["declaratorSource"] = re.sub(
                        r"(?m)^\s*#\s*define[^\r\n]*(?:\\\r?\n[^\r\n]*)*", "", info["source"]
                    )
                source = info["declaratorSource"]
                if re.search(rf"\b{re.escape(probe)}\s*\(", source):
                    declarations.append(key)
            status = "unknown"
            if len(declarations) > 1:
                status = "ambiguous-original-declaration-candidate"
            elif len(declarations) == 1:
                status = "unambiguous-original-declaration-candidate"
                if declarations[0] in covered or declarations[0] in drafts:
                    status = "already-covered-or-assigned-original"
                else:
                    ready[declarations[0]][category].append({
                        "symbol": symbol, "line": line, "value": value,
                    })
            elif candidates:
                status = "generated-header-or-non-function-needs-original-owner-review"
            facts.append({
                "source": f"generation\\WinSDK\\{filename}", "section": section,
                "line": line, "category": category, "symbol": symbol, "value": value,
                "headerCandidates": sorted(candidates), "nativeDeclarationCandidates": declarations,
                "partitionCandidates": sorted(set().union(*(header_partitions[key] for key in candidates))),
                "status": status,
            })

    mirror_files = [path for path in (project / "RecompiledIdlHeaders").rglob("*") if path.is_file()]
    report = {
        "schemaVersion": 1, "kind": "sdk-annotation-coverage-inventory",
        "snapshot": {
            "acceptedLocalHead": git(repo, "rev-parse", "HEAD"), "publishedTree": PUBLISHED,
            "sdkPackageVersion": version, "sdkIncludeVersion": sdk.name,
            "sdkPackageRoot": str(package), "ledger": str(args.ledger),
            "frozenQualification": ledger["qualification"]["path"],
        },
        "definitions": {
            "phase": "early-supportedOS-and-setLastError-owner-map",
            "retainedRows": "Configuration rows, not a count of unique unmigrated APIs.",
            "candidate": "Documentation header hint plus literal symbol/declarator occurrence; not AST ownership or annotation qualification.",
            "ready": "One native selected-SDK header declaration candidate, excluding all existing original patches/cohort sources and the 14 assigned tail headers.",
            "unknown": "No unique original declaration established; never counted as no migration needed.",
            "partitionCounts": "Static configured traversal ownership, not fresh compilation or conversion evidence.",
        },
        "scope": {
            "partitions": len(partitions), "selectedSdkFiles": len(sdk_files),
            "selectedSdkHeaderFamilyFiles": len(sdk_headers), "selectedSdkIdlOdlInputs": len(sdk_idls),
            "mirrorFiles": len(mirror_files),
            "mirrorHeaders": sum(path.suffix.lower() == ".h" for path in mirror_files),
            "mirrorIdls": sum(path.suffix.lower() == ".idl" for path in mirror_files),
        },
        "originalSourceQualification": {
            "counts": ledger["coverage"], "cohortSeed": COHORT_SEED, "pilot": PILOT,
            "cohortOriginals": cohort, "isEntireAuthoredMigrationScope": False,
            "scope": "Frozen local original-source qualification only; not current-head/full-SDK verification.",
        },
        "currentRetainedOSAndErrorRows": dict(Counter(fact["category"] for fact in facts)),
        "mappingStatusCounts": dict(Counter(fact["status"] for fact in facts)),
        "excludedOriginals": sorted(covered | drafts),
        "readyOriginalOwners": [
            {"original": header, "partitionCandidates": sorted(header_partitions[header]),
             "reservedForDeviceWorker": header in DEVICE_RESERVED, **values}
            for header, values in sorted(
                ready.items(), key=lambda item: (-sum(len(values) for values in item[1].values()), item[0])
            )
        ],
        "partitions": partitions, "retainedOSAndErrorFacts": facts,
    }
    if not args.early:
        baseline = args.baseline_ref or git(repo, "merge-base", "HEAD", "main")
        current_facts, current_summary = configuration_facts(config_snapshot(repo))
        baseline_facts, baseline_summary = configuration_facts(config_snapshot(repo, baseline))
        published_facts, published_summary = configuration_facts(config_snapshot(repo, PUBLISHED))
        removed = removed_facts(baseline_facts, current_facts)
        patches = patch_inventory(project, recipe)
        midl_outputs = defaultdict(list)
        for output in recipe.get("midl", {}).get("outputs", []):
            midl_outputs[output["source"].lower()].append(output["path"].lower())
        all_targets = {
            fact["symbol"].split("::", 1)[0]
            for fact in current_facts + removed
            if re.fullmatch(r"[A-Za-z_][A-Za-z_0-9]*", fact["symbol"].split("::", 1)[0])
        }
        token_headers = defaultdict(set)
        for header in sorted(sdk_headers):
            info = source_info(header)
            for token in all_targets.intersection(TOKEN.findall(info["source"])):
                token_headers[token].add(header)
        early_by_key = {(fact["source"], fact["value"]): fact for fact in facts}
        patch_by_header = defaultdict(list)
        for patch in patches:
            physical = midl_outputs[patch["original"]] or [patch["original"]]
            patch["physicalHeaders"] = physical
            patch["partitionCandidates"] = sorted(set().union(*(header_partitions[header] for header in physical)))
            for header in physical:
                patch_by_header[header].append(patch)
        mapping_cache = {}

        def map_fact(fact):
            probe = fact["symbol"].split("::", 1)[0]
            hints = tuple(fact.get("headerHints", []))
            cache_key = (probe, hints)
            if cache_key not in mapping_cache:
                candidates = set()
                for hint in set(doc_headers.get(probe, ())) | set(hints):
                    candidates.update(headers_by_name.get(hint, ()))
                references = token_headers.get(probe, set())
                hinted = candidates & references
                if hinted:
                    candidates = hinted
                elif not hints:
                    candidates = set(references)
                originals = set()
                unavailable = []
                for header in candidates:
                    originals.update(source_info(header)["originals"])
                    if not source_info(header)["originals"]:
                        unavailable.append(header)
                mapping_cache[cache_key] = {
                    "headerCandidates": sorted(candidates), "originalCandidates": sorted(originals),
                    "unavailableOriginalHeaders": sorted(unavailable),
                    "partitionCandidates": sorted(set().union(*(header_partitions[header] for header in candidates))),
                    "ownershipStatus": "unique-original-candidate" if len(originals) == 1 and not unavailable else (
                        "ambiguous-original-candidates" if originals else "unknown-original"
                    ),
                }
            fact.update(mapping_cache[cache_key])
            early = early_by_key.get((fact["source"], fact["value"])) if isinstance(fact["value"], str) else None
            if early:
                fact["nativeDeclarationCandidates"] = early["nativeDeclarationCandidates"]

        for fact in current_facts + removed:
            map_fact(fact)
        macro_kinds = {
            "supportedOS": "_Win32_SupportedOS_", "setLastError": "_Win32_SetLastError_",
            "associated-enum-use": "_Win32_AssociatedEnum_",
            "cleanup-api": "_Win32_RAIIFree_", "invalid-handle-values": "_Win32_RAIIFree_",
            "also-usable-for": "_Win32_AlsoUsableFor_", "enum-flags": "_Win32_FlagsEnum_",
            "synthetic-enum-definition": ("_Win32_Enum_", "_Win32_FlagsEnum_"),
            "synthetic-enum-explicit-member": ("_Win32_Enum_", "_Win32_FlagsEnum_"),
        }
        for fact in removed:
            backing = []
            probe = fact["symbol"].split("::", 1)[0]
            kind = macro_kinds.get(fact["category"])
            for header in fact["headerCandidates"]:
                for patch in patch_by_header[header]:
                    if kind and any(macro.startswith(kind) for macro in patch["annotationMacroOccurrences"]):
                        if re.search(rf"\b{re.escape(probe)}\b", patch["_context"]):
                            backing.append(patch["patch"])
            fact["headerBackingCandidatePatches"] = sorted(set(backing))
            fact["removalStatus"] = "source-owner-and-annotation-kind-match" if backing else "removed-without-exact-site-proof"
        authored = [fact for fact in current_facts if fact["treatment"] == "authored"]
        incidence, removed_incidence = defaultdict(list), defaultdict(list)
        original_incidence = defaultdict(list)
        for fact in authored:
            for owner in fact["partitionCandidates"]:
                incidence[owner].append(fact)
            for original in fact["originalCandidates"]:
                original_incidence[original].append(fact)
        for fact in removed:
            if fact["treatment"] == "authored":
                for owner in fact["partitionCandidates"]:
                    removed_incidence[owner].append(fact)
        for partition in partitions:
            name = partition["name"]
            own_patches = [patch for patch in patches if name in patch["partitionCandidates"] and patch["authoredAnnotationSource"]]
            missing = sorted(set(partition["traverseHeaders"]) & SOURCE_BLOCKED)
            partition.update({
                "sourceConversionState": "source-converted-with-explicit-residuals" if own_patches else (
                    "unconverted" if incidence[name] else (
                        "missing-source/global-tooling-exception" if missing else "unknown-no-mapped-authored-input"
                    )
                ),
                "sourceAnnotationOriginals": sorted({patch["original"] for patch in own_patches}),
                "remainingAuthoredFactIncidences": len(incidence[name]),
                "remainingFactCategories": dict(Counter(fact["category"] for fact in incidence[name])),
                "removedAuthoredFactIncidences": len(removed_incidence[name]),
                "missingOriginalHeaders": missing,
                "fullyVerifiedWholePartitionAtSnapshot": False,
                "noAuthoredMigrationNeeded": None,
            })
        sdk_originals = set(sdk_idls)
        generated_known, generated_missing, native_headers = [], [], []
        for header in sorted(sdk_headers):
            info = source_info(header)
            if info["generated"]:
                (generated_known if info["originals"] else generated_missing).append(header)
            else:
                native_headers.append(header)
                sdk_originals.add(header)
        source_rows = [{
            "original": original, "kind": "IDL/ODL" if Path(original).suffix.lower() in IDL_EXTENSIONS else "native-header",
            "remainingAuthoredFactCandidateIncidences": len(original_incidence[original]),
            "remainingFactCategories": dict(Counter(fact["category"] for fact in original_incidence[original])),
            "inHistorical50": original in cohort,
            "hasActivePatch": any(patch["original"] == original for patch in patches),
            "frozenOriginalSourceQualified": original in set(cohort) - drafts,
            "wholeOriginalSidecarFreeProven": None,
            "sourceConversionState": "source-converted-with-explicit-residuals" if any(
                patch["original"] == original and patch["authoredAnnotationSource"] for patch in patches
            ) else (
                "patched-native-transport-or-bootstrap-needs-review" if any(
                    patch["original"] == original for patch in patches
                ) else ("unconverted" if original_incidence[original] else "unknown-no-mapped-authored-input")
            ),
            "noAuthoredMigrationNeeded": None,
        } for original in sorted(sdk_originals)]
        manual = []
        for path in sorted((project / "manual").glob("*.cs")):
            content = text(path)
            manual.append({
                "source": relative(path, repo),
                "treatment": "metadata-attribute-schema" if path.name == "Metadata.cs" else "manual-API-source-review",
                "attributeSyntaxOccurrences": dict(Counter(re.findall(r"\[\s*(\w+)(?=[(\],])", content))),
                "semanticFactCount": None,
            })
        derived_imports = {
            value.split("=", 1)[0]: value.split("=", 1)[-1]
            for _, _, value in rsp_entries(text(project / "libMappings.rsp"))
        }
        for fact in current_facts:
            if fact["category"] == "manual-import-review":
                symbol, value = fact["value"].split("=", 1)
                derived = derived_imports.get(symbol)
                fact["derivedImportComparison"] = "no-exact-derived-symbol" if derived is None else (
                    "same-as-derived" if derived.lower().removesuffix(".dll") == value.lower().removesuffix(".dll")
                    else "differs-from-derived"
                )
        report["definitions"].update({
            "phase": "full-static-input-inventory",
            "factUnit": "One RSP row, enum definition, explicit enum member, enum use, or autoType semantic property. Counts are configuration units, not unique APIs; duplicate RSP rules are retained.",
            "enumUse": "enums.json uses and direct member type substitutions are direct enum uses, not AssociatedEnum attributes.",
            "macroOccurrence": "An authored patch token occurrence, not an expanded declaration fact or accepted conversion.",
            "sourceConverted": "An active authored original-source annotation patch intersects the configured physical owner. This records partial/source conversion with explicit residuals, not a majority or sidecar-free assertion.",
            "fullyVerified": "Whole-partition acceptance at this exact snapshot. Frozen original-artifact receipts do not establish this; no whole-SDK producer was run here.",
            "sourceOwnership": "Unique/ambiguous original candidates use native token references plus documentation hints. They are not AST declaration proofs. Missing and unknown sources remain explicit.",
            "removed": "Absent from the named sidecar baseline. An owner/annotation-kind match is a backing candidate, not exact target/payload or qualification proof.",
            "globalParser": "Configuration class, not a waiver that every API-scoped parser correction is correct. Manual import/type overrides stay review candidates.",
            "knownOriginalUniverse": "All shipped IDL/ODL plus native header-family files in selected SDK um/shared/winrt/ucrt; a generated header is not counted again as an authored original. Same-stem IDL resolution is explicit inference. Includes auxiliary/untraversed originals, not just emitted API owners.",
        })
        report["snapshot"]["sidecarComparisonBaseline"] = baseline
        report["scope"].update({
            "knownSelectedSdkOriginalInputs": len(sdk_originals),
            "nativeSelectedSdkHeaderInputs": len(native_headers),
            "generatedSdkHeadersWithSameStemIdl": len(generated_known),
            "generatedSdkHeadersWithoutLocatedOriginal": len(generated_missing),
            "unresolvedGeneratedHeaderOriginSlots": len(generated_missing),
            "unknownDistinctGeneratedOriginalOwnerCount": None,
            "provenNoAuthoredMigrationNeededOriginalCount": None,
            "originalsWithoutMappedAuthoredRows": sum(not original_incidence[original] for original in sdk_originals),
            "partitionsWithNoMappedAuthoredRows": sum(not incidence[partition["name"]] for partition in partitions),
            "activePatchFiles": len(patches), "admittedMirrorFiles": len(recipe["headers"]),
            "recipeClosurePartitions": len(recipe["partitions"]),
        })
        report["configuration"] = current_summary
        report["configuration"]["baseline"] = baseline_summary
        report["configuration"]["publishedTree"] = published_summary
        report["configuration"]["manualImportReviewComparisons"] = dict(Counter(
            fact["derivedImportComparison"] for fact in current_facts if "derivedImportComparison" in fact
        ))
        report["configuration"]["retainedAuthoredRowsAndJsonFacts"] = len(authored)
        report["configuration"]["unknownOrAmbiguousAuthoredOriginalCandidates"] = sum(
            fact["ownershipStatus"] != "unique-original-candidate" for fact in authored
        )
        report["configuration"]["authoredFactsWithoutAnyPartitionCandidate"] = sum(
            not fact["partitionCandidates"] for fact in authored
        )
        report["retainedFacts"] = current_facts
        del report["retainedOSAndErrorFacts"]
        report["removedSidecarFacts"] = removed
        report["removedSidecarSummary"] = {
            "categories": dict(Counter(fact["category"] for fact in removed)),
            "sourceOwnerAndAnnotationKindCandidates": sum(bool(fact["headerBackingCandidatePatches"]) for fact in removed),
            "exactSiteAndPayloadProvenByThisStaticReport": 0,
        }
        report["selectedSdkOriginals"] = source_rows
        report["generatedSdkHeaders"] = [{
            "header": header, "originalCandidates": source_info(header)["originals"],
            "ownershipBasis": source_info(header)["ownershipBasis"],
        } for header in sorted(generated_known + generated_missing)]
        report["selectedSdkFilesAbsentFromMirror"] = sorted(
            key for key in sdk_files if not (project / "RecompiledIdlHeaders" / key).is_file()
        )
        report["mirrorFilesNotInSelectedSdk"] = sorted(
            relative(path, project / "RecompiledIdlHeaders").lower()
            for path in mirror_files if relative(path, project / "RecompiledIdlHeaders").lower() not in sdk_files
        )
        report["manualSources"] = manual
        report["missingOriginalSourceMigrations"] = {
            "headers": sorted(SOURCE_BLOCKED), "preservedLegacyFacts": 30,
            "state": "missing-source/global-tooling-exception",
            "availability": 26, "associatedEnumUses": 3, "enumFlags": 1,
            "basis": "Frozen ledger and docs/header-annotation-migration-playbook.md original-source request inventory; IDL filename probes are not invented original filenames.",
        }
        report["intentionalRemovals"] = {
            "policy": "Agile is intentionally jettisoned, not migrated into headers.",
            "stillConfiguredRules": [fact for fact in current_facts if fact["treatment"] == "intentional-removal"],
            "removedRules": [fact for fact in removed if fact["treatment"] == "intentional-removal"],
        }
        report["partitionStateCounts"] = dict(Counter(partition["sourceConversionState"] for partition in partitions))
        report["omittedFromHistorical50"] = {
            "remainingOriginalCandidates": sorted({
                original for fact in authored for original in fact["originalCandidates"] if original not in cohort
            }),
            "partitionCandidatesWithRemainingFacts": sorted(
                name for name, rows in incidence.items() if rows and not any(
                    original in cohort for partition in partitions if partition["name"] == name
                    for original in partition["sourceAnnotationOriginals"]
                )
            ),
            "remainingCategories": dict(Counter(
                fact["category"] for fact in authored
                if not fact["originalCandidates"] or any(original not in cohort for original in fact["originalCandidates"])
            )),
            "manualApiSourceFiles": sum(item["treatment"] == "manual-API-source-review" for item in manual),
            "manualSemanticFactCount": None,
        }
        report["activePatches"] = [{key: value for key, value in patch.items() if key != "_context"} for patch in patches]
        report["originalSourceQualification"]["qualifiedCohortOriginals"] = sorted(set(cohort) - drafts)
        report["originalSourceQualification"]["unqualifiedCohortDrafts"] = sorted(drafts)
        report["originalSourceQualification"]["pilotOriginalsOutside50"] = sorted({
            path[:-len(".patch")].lower() for path in pilot["patches"]
        })
        report["readyOriginalOwners"] = [
            owner for owner in report["readyOriginalOwners"] if not owner["reservedForDeviceWorker"]
        ]
        report["deviceReservedOriginals"] = sorted(DEVICE_RESERVED)
        d3d_version = next(
            item.attrib["Version"] for item in packages.iter("PackageReference")
            if item.attrib.get("Include") == "Microsoft.Direct3D.D3D12"
        )
        d3d_include = cache / "microsoft.direct3d.d3d12" / d3d_version / "build" / "native" / "include"
        overlay_files = sorted(path.name.lower() for path in d3d_include.iterdir() if path.is_file())
        report["selectedProviderOverlayOriginals"] = selected_overlay_originals(sdk_originals, overlay_files)
        report["additionalSelectedSourceProviders"] = [{
            "package": "Microsoft.Direct3D.D3D12", "version": d3d_version,
            "publicIncludeFiles": overlay_files,
            "bindingStatus": "selected package overlays need provider-specific source binding; excluded from source queue",
        }]
        report["scope"]["exactAllSelectedProviderOriginalCount"] = None
        report["scope"]["knownOriginalCountProvider"] = f"Microsoft.Windows.SDK.CPP {version}"
        report["scope"]["selectedProviderOverlayOriginalsDeferred"] = len(report["selectedProviderOverlayOriginals"])
        report["snapshot"]["inventoryPath"] = str(args.output.resolve())
        report["snapshot"]["configurationGitTree"] = git(repo, "rev-parse", "HEAD:generation/WinSDK")
        report["snapshot"]["uncommittedProductionPaths"] = git(
            repo, "diff", "--name-only", "HEAD", "--", "generation/WinSDK"
        ).splitlines()
        progress = apply_progress(repo, sdk, patches, args.output.parent) if args.strict_apply else []
        native = sorted({
            item["original"] for item in progress
            if item["status"] == "applied-nontrivial" and Path(item["original"]).suffix.lower() in HEADER_EXTENSIONS
        })
        idls = sorted({
            item["original"] for item in progress
            if item["status"] == "applied-nontrivial" and Path(item["original"]).suffix.lower() in IDL_EXTENSIONS
        })
        report["sourceProgressScoreboard"] = {
            "schemaVersion": 1, "kind": "sdk-annotation-source-progress",
            "sourceSnapshot": report["snapshot"],
            "deadlineUtc": campaign.get("deadlineUtc"), "requestedUniquePatchedHeaderOwners": campaign.get("target"),
            "countingRule": "Unique selected-SDK header-family paths with committed nontrivial patches actually applied under strict git-apply checking; no copies, parser opt-ins, architectures, IDL filenames, or inferred generated outputs added to the header total. Bootstrap/parser-only paths are separately identified.",
            "committedPatchInputs": not report["snapshot"]["uncommittedProductionPaths"],
            "strictApplyStatusCounts": dict(Counter(item["status"] for item in progress)),
            "strictlyAppliedNativeHeaderPaths": native,
            "strictlyAppliedNativeHeaderCount": len(native) if args.strict_apply else None,
            "strictlyAppliedOriginalIdlPaths": idls,
            "strictlyAppliedOriginalIdlCount": len(idls) if args.strict_apply else None,
            "bootstrapOnlyHeaderPaths": [path for path in native if path == r"shared\sal.h"],
            "nonBootstrapPatchedNativeHeaderCount": len([path for path in native if path != r"shared\sal.h"]) if args.strict_apply else None,
            "nativeHeaderPathsWithoutNewAnnotationMacro": [
                patch["original"] for patch in patches
                if not patch["authoredAnnotationSource"] and Path(patch["original"]).suffix.lower() in HEADER_EXTENSIONS
            ],
            "generatedHeaderPathsWithPatchedOwningIdl": sorted({
                header for original in idls for header in midl_outputs[original]
            }),
            "actuallyAffectedGeneratedHeaderPaths": None,
            "actuallyAffectedGeneratedHeaderCount": None,
            "generatedOutputUnknownReason": "This inventory does not run MIDL. An output-to-IDL recipe edge is not proof that a generated header changed.",
            "original50FrozenQualified": ledger["coverage"]["qualifiedOriginalArtifactsNow"],
            "laterSourceConversionsReportedByCoordinator": campaign.get("laterSourceReports"),
            "partitionConversionStates": report["partitionStateCounts"],
            "strictApplyRows": progress,
        }
        if campaign.get("sourceReceipts") and not args.strict_apply:
            raise ValueError("Committed source receipts require --strict-apply for a fresh inventory")
        update_source_receipts(report, campaign, repo, sdk, args.output.parent)
        update_generated_observations(
            report, campaign.get("generatedOutputObservations", []), repo,
            campaign.get("goalExcludedGeneratedHeaders", []),
        )
        write_operational_outputs(report, campaign, args, sdk)
    elif args.queue_output or args.scoreboard_output or args.strict_apply:
        raise ValueError("Queue, scoreboard, and strict application require the full inventory")
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(report, ensure_ascii=True, separators=(",", ":")) + "\n", encoding="utf-8")
    print(json.dumps({
        "output": str(args.output), "scope": report["scope"],
        "mappingStatusCounts": report["mappingStatusCounts"],
        "readyOriginalOwners": len(report["readyOriginalOwners"]),
        "readyFactRows": sum(
            len(owner["supportedOS"]) + len(owner["setLastError"]) for owner in report["readyOriginalOwners"]
        ),
        "scoreboard": report.get("sourceProgressScoreboard", {}).get("strictApplyStatusCounts"),
    }, indent=2))


if __name__ == "__main__":
    main()
