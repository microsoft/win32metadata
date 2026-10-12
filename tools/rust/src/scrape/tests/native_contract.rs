//! Root-observation proof gate, not an emission or dependency-closure authority.

use super::*;
use std::cell::Cell;
use windows_clang::{Fact, FactKind, Location, Origin, Snapshot, TypeRef, Value};

type DeclarationKey<'a> = (&'a str, &'a str, &'a Location);

thread_local! {
    static LOOKUP_BUILDS: Cell<usize> = const { Cell::new(0) };
}

#[derive(Debug)]
struct NativeLookup<'a> {
    by_origin: BTreeMap<&'a Origin, &'a Fact>,
    by_declaration: BTreeMap<DeclarationKey<'a>, Vec<&'a Fact>>,
    indexed_facts: usize,
    inspected_candidates: Cell<usize>,
}

impl<'a> NativeLookup<'a> {
    fn new(facts: &'a [Fact]) -> Result<Self, String> {
        LOOKUP_BUILDS.with(|count| count.set(count.get() + 1));
        let mut lookup = Self {
            by_origin: BTreeMap::new(),
            by_declaration: BTreeMap::new(),
            indexed_facts: 0,
            inspected_candidates: Cell::new(0),
        };
        for fact in facts {
            lookup.indexed_facts += 1;
            if lookup.by_origin.insert(&fact.origin, fact).is_some() {
                return Err(format!("duplicate native Origin {:?}", fact.origin));
            }
            lookup
                .by_declaration
                .entry((&fact.origin.tu, &fact.name, &fact.spelling))
                .or_default()
                .push(fact);
        }
        Ok(lookup)
    }

    fn candidates<'b>(
        &'b self,
        origin: &'b Origin,
        name: &'b str,
        declaration: &'b Location,
    ) -> impl Iterator<Item = &'a Fact> + 'b {
        self.by_declaration
            .get(&(origin.tu.as_str(), name, declaration))
            .into_iter()
            .flatten()
            .copied()
            .inspect(|_| {
                self.inspected_candidates
                    .set(self.inspected_candidates.get() + 1);
            })
    }
}

#[derive(Clone, Debug, Eq, Ord, PartialEq, PartialOrd)]
pub(crate) struct Physical {
    spelling: Location,
    expansion: Location,
    kind: FactKind,
    name: String,
    definition: bool,
    parent: Option<Box<Physical>>,
}

#[derive(Clone, Debug, Eq, Ord, PartialEq, PartialOrd)]
enum Route {
    Declaration,
    Return,
    Parameter(usize),
    Field(usize),
    NestedField(Vec<usize>),
    Variant(usize),
    Method(usize),
    MethodReturn(usize),
    MethodParameter(usize, usize),
}

fn annotation_route(target: &AnnotationTarget) -> (&Origin, Route) {
    match target {
        AnnotationTarget::Declaration(origin) => (origin, Route::Declaration),
        AnnotationTarget::Return(origin) => (origin, Route::Return),
        AnnotationTarget::Parameter { declaration, index } => {
            (declaration, Route::Parameter(*index))
        }
        AnnotationTarget::Field { declaration, index } => (declaration, Route::Field(*index)),
        AnnotationTarget::NestedField { declaration, path } => {
            (declaration, Route::NestedField(path.clone()))
        }
        AnnotationTarget::Variant { declaration, index } => (declaration, Route::Variant(*index)),
        AnnotationTarget::Method { declaration, index } => (declaration, Route::Method(*index)),
        AnnotationTarget::MethodReturn { declaration, index } => {
            (declaration, Route::MethodReturn(*index))
        }
        AnnotationTarget::MethodParameter {
            declaration,
            method,
            parameter,
        } => (declaration, Route::MethodParameter(*method, *parameter)),
    }
}

fn physical(
    origin: &Origin,
    lookup: &NativeLookup<'_>,
    active: &mut BTreeSet<Origin>,
) -> Result<Physical, String> {
    let fact = lookup
        .by_origin
        .get(origin)
        .ok_or_else(|| format!("unresolved native Origin {origin:?}"))?;
    if !active.insert(origin.clone()) {
        return Err(format!("cyclic native parent {origin:?}"));
    }
    let parent = fact
        .parent
        .as_ref()
        .map(|parent| physical(parent, lookup, active).map(Box::new))
        .transpose()?;
    active.remove(origin);
    Ok(Physical {
        spelling: fact.spelling.clone(),
        expansion: fact.expansion.clone(),
        kind: fact.kind,
        name: fact.name.clone(),
        definition: fact.definition,
        parent,
    })
}

#[derive(Clone, Debug, Eq, Ord, PartialEq, PartialOrd)]
enum Identity {
    Declaration(Physical),
    Annotation(Physical, Route),
    Constant {
        spelling: Location,
        name: String,
        root: Physical,
        definition: Physical,
    },
}

#[derive(Clone, Debug, Eq, PartialEq)]
enum Payload {
    Annotation(Vec<Annotation>),
    Declaration {
        data: FactData,
        system: bool,
        annotations: BTreeMap<Route, Vec<Annotation>>,
    },
    Constant {
        ty: TypeRef,
        value: Value,
    },
}

#[derive(Clone, Debug)]
pub(crate) struct Observation {
    identity: Identity,
    pub original_origin: Origin,
    payload: Payload,
}

#[derive(Debug, Default)]
pub(crate) struct ContractReport {
    pub missing: Vec<Observation>,
    pub changed: Vec<(Observation, Vec<Observation>)>,
    pub retained: Vec<(Observation, Vec<Observation>)>,
    pub extras: Vec<Observation>,
    pub incomplete: Vec<String>,
}

impl ContractReport {
    pub fn retained(&self) -> bool {
        self.missing.is_empty() && self.changed.is_empty() && self.incomplete.is_empty()
    }
}

fn check_type(ty: &TypeRef, origin: &Origin, lookup: &NativeLookup<'_>) -> Result<(), String> {
    match ty {
        TypeRef::Named { name, declaration }
        | TypeRef::Generic {
            name, declaration, ..
        } => {
            let matches = lookup
                .candidates(origin, name, declaration)
                .collect::<Vec<_>>();
            if matches.is_empty() {
                return Err(format!(
                    "unresolved native reference {origin:?}: {name} at {declaration:?}"
                ));
            }
            let identities = matches
                .iter()
                .map(|fact| physical(&fact.origin, lookup, &mut BTreeSet::new()))
                .collect::<Result<BTreeSet<_>, _>>()?;
            if identities.len() != 1 || matches.iter().any(|fact| fact.data != matches[0].data) {
                return Err(format!(
                    "ambiguous native reference {origin:?}: {name} at {declaration:?}; alternatives {matches:#?}"
                ));
            }
            if let TypeRef::Generic { args, .. } = ty {
                for arg in args {
                    check_type(arg, origin, lookup)?;
                }
            }
        }
        TypeRef::Pointer { target, .. }
        | TypeRef::Reference { target, .. }
        | TypeRef::Array { target, .. } => check_type(target, origin, lookup)?,
        TypeRef::FunctionPointer { params, result, .. } => {
            for param in params {
                check_type(param, origin, lookup)?;
            }
            check_type(result, origin, lookup)?;
        }
        TypeRef::InlineRecord(record) => {
            if let Some(base) = &record.base {
                check_type(base, origin, lookup)?;
            }
            for field in &record.fields {
                check_type(&field.ty, origin, lookup)?;
            }
        }
        TypeRef::Void
        | TypeRef::String
        | TypeRef::Object
        | TypeRef::Scalar(_)
        | TypeRef::OpaquePointer { .. } => {}
    }
    Ok(())
}

fn check_data(fact: &Fact, lookup: &NativeLookup<'_>) -> Result<(), String> {
    let check = |ty: &TypeRef| check_type(ty, &fact.origin, lookup);
    match &fact.data {
        FactData::Function { params, result, .. } | FactData::Callback { params, result, .. } => {
            for param in params {
                check(&param.ty)?;
            }
            check(result)?;
        }
        FactData::Record { base, fields, .. } => {
            if let Some(base) = base {
                check(base)?;
            }
            for field in fields {
                check(&field.ty)?;
            }
        }
        FactData::Interface { base, methods, .. } => {
            if let Some(base) = base {
                check(base)?;
            }
            for method in methods {
                for param in &method.params {
                    check(&param.ty)?;
                }
                check(&method.result)?;
            }
        }
        FactData::Typedef { target } => check(target)?,
        FactData::Unsupported { reason } => {
            return Err(format!(
                "unsupported native body {:?}: {reason}",
                fact.origin
            ));
        }
        FactData::None if fact.kind != FactKind::Namespace && fact.definition => {
            return Err(format!(
                "unknown native body {:?}: {:?}",
                fact.origin, fact.spelling
            ));
        }
        _ => {}
    }
    Ok(())
}

fn inventory(snapshot: &Snapshot) -> (Vec<Observation>, Vec<String>) {
    let mut incomplete = Vec::new();
    let lookup = match NativeLookup::new(snapshot.facts()) {
        Ok(lookup) => lookup,
        Err(error) => return (Vec::new(), vec![error]),
    };
    let mut observations = Vec::new();
    let mut sites = BTreeMap::<Origin, BTreeMap<Route, Vec<Annotation>>>::new();
    for (target, annotations) in snapshot.annotations() {
        let (origin, route) = annotation_route(target);
        match physical(origin, &lookup, &mut BTreeSet::new()) {
            Ok(identity) => observations.push(Observation {
                identity: Identity::Annotation(identity, route.clone()),
                original_origin: origin.clone(),
                payload: Payload::Annotation(annotations.clone()),
            }),
            Err(error) => incomplete.push(error),
        }
        sites
            .entry(origin.clone())
            .or_default()
            .insert(route, annotations.clone());
    }
    for fact in snapshot.facts().iter().filter(|fact| fact.root) {
        if let Err(error) = check_data(fact, &lookup) {
            incomplete.push(error);
        }
        let identity = match physical(&fact.origin, &lookup, &mut BTreeSet::new()) {
            Ok(identity) => identity,
            Err(error) => {
                incomplete.push(error);
                continue;
            }
        };
        observations.push(Observation {
            identity: Identity::Declaration(identity),
            original_origin: fact.origin.clone(),
            payload: Payload::Declaration {
                data: fact.data.clone(),
                system: fact.system,
                annotations: sites.get(&fact.origin).cloned().unwrap_or_default(),
            },
        });
    }
    for constant in snapshot.constants() {
        if let Err(error) = check_type(&constant.ty, &constant.root, &lookup) {
            incomplete.push(error);
        }
        let identities = physical(&constant.root, &lookup, &mut BTreeSet::new()).and_then(|root| {
            physical(&constant.definition, &lookup, &mut BTreeSet::new())
                .map(|definition| (root, definition))
        });
        let (root, definition) = match identities {
            Ok(identities) => identities,
            Err(error) => {
                incomplete.push(error);
                continue;
            }
        };
        observations.push(Observation {
            identity: Identity::Constant {
                spelling: constant.spelling.clone(),
                name: constant.name.clone(),
                root,
                definition,
            },
            original_origin: constant.root.clone(),
            payload: Payload::Constant {
                ty: constant.ty.clone(),
                value: constant.value.clone(),
            },
        });
    }
    (observations, incomplete)
}

/// Keep every original observation and every folded alternative; never choose a body winner.
pub(crate) fn compare(originals: &[&Snapshot], folded: &Snapshot) -> ContractReport {
    let mut report = ContractReport::default();
    let mut expected = Vec::new();
    for snapshot in originals {
        let (observations, incomplete) = inventory(snapshot);
        expected.extend(observations);
        report.incomplete.extend(
            incomplete
                .into_iter()
                .map(|error| format!("original: {error}")),
        );
    }
    let (actual, incomplete) = inventory(folded);
    report.incomplete.extend(
        incomplete
            .into_iter()
            .map(|error| format!("folded: {error}")),
    );
    let expected_keys = expected
        .iter()
        .map(|observation| &observation.identity)
        .collect::<BTreeSet<_>>();
    let mut actual_by_identity = BTreeMap::<&Identity, Vec<&Observation>>::new();
    for observation in &actual {
        actual_by_identity
            .entry(&observation.identity)
            .or_default()
            .push(observation);
    }
    for observation in &expected {
        let alternatives = actual_by_identity
            .get(&observation.identity)
            .into_iter()
            .flatten()
            .map(|actual| (*actual).clone())
            .collect::<Vec<_>>();
        if alternatives.is_empty() {
            report.missing.push(observation.clone());
        } else if alternatives
            .iter()
            .any(|actual| actual.payload != observation.payload)
        {
            report.changed.push((observation.clone(), alternatives));
        } else {
            report.retained.push((observation.clone(), alternatives));
        }
    }
    report.extras = actual
        .into_iter()
        .filter(|actual| !expected_keys.contains(&actual.identity))
        .collect();
    report
}

struct Fixture {
    root: PathBuf,
    headers: Vec<String>,
    sources: Vec<String>,
}

impl Fixture {
    fn new(label: &str, headers: &[(&str, &str)], sources: &[&str]) -> Self {
        ensure_libclang();
        let root = scratch(label);
        let headers = headers
            .iter()
            .map(|(name, source)| {
                let path = root.join(name);
                std::fs::write(&path, source).unwrap();
                path_arg(&path, "fixture header").unwrap()
            })
            .collect();
        let sources = sources
            .iter()
            .enumerate()
            .map(|(index, source)| {
                let path = root.join(format!("original-{index}.cpp"));
                std::fs::write(&path, source).unwrap();
                path_arg(&path, "original TU").unwrap()
            })
            .collect();
        Self {
            root,
            headers,
            sources,
        }
    }

    fn extract(&self, order: &[usize], defines: &[&str], folded: bool) -> Snapshot {
        let wrapper = |index: usize| format!("#include \"{}\"\n", self.sources[index]);
        let inputs = if folded {
            vec![
                Input::new(
                    path_arg(&self.root.join("folded.cpp"), "folded TU").unwrap(),
                    order
                        .iter()
                        .map(|index| wrapper(*index))
                        .collect::<String>(),
                )
                .with_roots(self.headers.clone()),
            ]
        } else {
            order
                .iter()
                .map(|index| {
                    Input::new(
                        self.sources[*index].clone(),
                        std::fs::read_to_string(&self.sources[*index]).unwrap(),
                    )
                    .with_roots(self.headers.clone())
                })
                .collect()
        };
        let include = format!("-I{}", self.root.display());
        let mut args = vec!["-x", "c++", "--target=x86_64-pc-windows-msvc", &include];
        args.extend_from_slice(defines);
        windows_clang::extract(inputs, &args).unwrap()
    }
}

impl Drop for Fixture {
    fn drop(&mut self) {
        std::fs::remove_dir_all(&self.root).unwrap();
    }
}

#[test]
fn native_contract_shared_physical_roots_ignore_only_origin_ordinals() {
    let fixture = Fixture::new(
        "native-contract-shared",
        &[(
            "shared.h",
            "#pragma once\nnamespace Owner { struct Shared { int field; }; }\n",
        )],
        &["#include \"shared.h\"\n", "#include \"shared.h\"\n"],
    );
    let split = fixture.extract(&[0, 1], &[], false);
    let folded = fixture.extract(&[0, 1], &[], true);
    let report = compare(&[&split], &folded);
    assert!(report.retained(), "{report:#?}");
    let (originals, incomplete) = inventory(&split);
    assert!(incomplete.is_empty());
    assert!(originals.iter().any(|left| originals.iter().any(|right| {
        left.identity == right.identity && left.original_origin.tu != right.original_origin.tu
    })));
}

#[test]
fn native_contract_partial_guard_loss_rejects_both_orders() {
    let fixture = Fixture::new(
        "native-contract-guards",
        &[
            (
                "first.h",
                "struct FirstVisible { int x; };\n#ifndef COLLISION\n#define COLLISION\nstruct FirstLost { int x; };\n#endif\n",
            ),
            (
                "second.h",
                "struct SecondVisible { int x; };\n#ifndef COLLISION\n#define COLLISION\nstruct SecondLost { int x; };\n#endif\n",
            ),
        ],
        &["#include \"first.h\"\n", "#include \"second.h\"\n"],
    );
    let split = fixture.extract(&[0, 1], &[], false);
    for order in [[0, 1], [1, 0]] {
        let folded = fixture.extract(&order, &[], true);
        assert!(fixture.headers.iter().all(|path| {
            folded
                .facts()
                .iter()
                .any(|fact| fact.root && fact.spelling.file == *path)
        }));
        let report = compare(&[&split], &folded);
        assert!(!report.retained());
        assert!(
            report
                .missing
                .iter()
                .any(|observation| match &observation.identity {
                    Identity::Declaration(physical) => physical.name.ends_with("Lost"),
                    _ => false,
                }),
            "{report:#?}"
        );
    }
}

#[test]
fn native_contract_changed_native_payload_and_extra_inventory() {
    let fixture = Fixture::new(
        "native-contract-payload",
        &[(
            "payload.h",
            "#ifndef COUNT\n#define COUNT 3\n#endif\n#ifndef PACK\n#define PACK 8\n#endif\n#ifndef TYPE\n#define TYPE int\n#endif\n#pragma pack(push, PACK)\nstruct Packed { char c; TYPE data[COUNT]; };\n#pragma pack(pop)\nenum NativeValue : unsigned { Value = COUNT };\n#define NATIVE_COUNT COUNT\nextern \"C\" TYPE Signature(TYPE *p);\n#ifdef EXTRA\nstruct Added { int x; };\n#endif\n",
        )],
        &["#include \"payload.h\"\n"],
    );
    let split = fixture.extract(&[0], &[], false);
    for defines in [&["-DCOUNT=7"][..], &["-DPACK=1"][..], &["-DTYPE=short"][..]] {
        let folded = fixture.extract(&[0], defines, true);
        let report = compare(&[&split], &folded);
        assert!(!report.retained());
        assert!(!report.changed.is_empty(), "{report:#?}");
    }
    let folded = fixture.extract(&[0], &["-DEXTRA=1"], true);
    let report = compare(&[&split], &folded);
    assert!(report.retained(), "{report:#?}");
    assert!(!report.extras.is_empty());
}

#[test]
fn native_contract_distinct_physical_same_name_is_not_coalesced() {
    let fixture = Fixture::new(
        "native-contract-distinct",
        &[
            (
                "first.h",
                "#ifndef SHARED\n#define SHARED\nstruct Same { int value; };\n#endif\n",
            ),
            (
                "second.h",
                "#ifndef SHARED\n#define SHARED\nstruct Same { int value; };\n#endif\n",
            ),
        ],
        &["#include \"first.h\"\n", "#include \"second.h\"\n"],
    );
    let split = fixture.extract(&[0, 1], &[], false);
    let folded = fixture.extract(&[0, 1], &[], true);
    let report = compare(&[&split], &folded);
    assert!(
        report
            .missing
            .iter()
            .any(|observation| match &observation.identity {
                Identity::Declaration(physical) => physical.name == "Same",
                _ => false,
            }),
        "{report:#?}"
    );
}

#[test]
fn native_contract_unresolved_parent_is_not_lexical_fallback() {
    let origin = Origin {
        tu: "original.cpp".into(),
        local: 1,
    };
    assert!(
        physical(
            &origin,
            &NativeLookup::new(&[]).unwrap(),
            &mut BTreeSet::new()
        )
        .unwrap_err()
        .contains("unresolved native Origin")
    );
}

#[test]
fn native_contract_compiler_annotation_routes_and_raw_counts() {
    let fixture = Fixture::new(
        "native-contract-annotations",
        &[(
            "annotations.h",
            r#"
#ifndef META
#define META __attribute__((annotate("win32metadata:associated_enum=Tags")))
#endif
#ifndef COUNTED
#define COUNTED __attribute__((annotate("_In_reads_(count)")))
#endif
#define DECL __attribute__((annotate("win32metadata:preserve_result")))
enum Tags { First META = 1 };
struct Routes { META int field; struct { META int nested; }; };
typedef int (*Callback)(META int *value);
struct __declspec(uuid("01234567-89AB-CDEF-0123-456789ABCDEF")) Interface {
    virtual DECL META int Method(META int *value) = 0;
};
extern "C" DECL META int Function(META COUNTED const int *value, int count);
"#,
        )],
        &["#include \"annotations.h\"\n"],
    );
    let split = fixture.extract(&[0], &[], false);
    let folded = fixture.extract(&[0], &[], true);
    let report = compare(&[&split], &folded);
    assert!(report.retained(), "{report:#?}");
    let routes = split
        .annotations()
        .keys()
        .map(|target| annotation_route(target).1)
        .collect::<BTreeSet<_>>();
    println!("Native annotation routes: {routes:#?}");
    assert_eq!(
        routes.len(),
        9,
        "all native annotation routes must be observed"
    );
    assert!(routes.contains(&Route::Declaration));
    assert!(routes.contains(&Route::Return));
    assert!(routes.contains(&Route::Parameter(0)));
    assert!(routes.contains(&Route::Field(0)));
    assert!(routes.contains(&Route::Variant(0)));
    assert!(routes.contains(&Route::MethodParameter(0, 0)));
    assert!(routes.contains(&Route::NestedField(vec![1, 0])));
    assert!(routes.contains(&Route::Method(0)));
    assert!(routes.contains(&Route::MethodReturn(0)));
    let function = split
        .facts()
        .iter()
        .find(|fact| fact.name == "Function")
        .unwrap();
    let FactData::Function { params, .. } = &function.data else {
        panic!("native Function");
    };
    assert!(params[0].annotation.input);
    assert!(params[0].annotation.size.is_some());
    for defines in [
        &["-DMETA="][..],
        &["-DCOUNTED=__attribute__((annotate(\"_In_reads_bytes_(count)\")))"][..],
        &["-DCOUNTED=__attribute__((annotate(\"_In_reads_(9)\")))"][..],
    ] {
        let changed = fixture.extract(&[0], defines, true);
        let report = compare(&[&split], &changed);
        assert!(!report.retained(), "{report:#?}");
        assert!(
            !report.changed.is_empty() || !report.missing.is_empty(),
            "{report:#?}"
        );
    }
}

#[test]
fn native_contract_conflicting_physical_alternatives_never_choose_a_winner() {
    let fixture = Fixture::new(
        "native-contract-alternatives",
        &[("shared.h", "#pragma once\nenum Shared { Value = COUNT };\n")],
        &[
            "#define COUNT 1\n#include \"shared.h\"\n",
            "#define COUNT 2\n#include \"shared.h\"\n",
        ],
    );
    let split = fixture.extract(&[0, 1], &[], false);
    for order in [[0, 1], [1, 0]] {
        let folded = fixture.extract(&order, &[], true);
        let report = compare(&[&split], &folded);
        assert!(!report.retained(), "{report:#?}");
        assert!(!report.changed.is_empty(), "{report:#?}");
        assert!(
            report
                .changed
                .iter()
                .all(|(_, alternatives)| !alternatives.is_empty())
        );
    }
    let report = compare(&[&split], &split);
    assert!(
        !report.retained(),
        "a folded matching body must not hide its conflicting alternative"
    );
    assert!(
        report
            .changed
            .iter()
            .any(|(_, alternatives)| alternatives.len() == 2),
        "{report:#?}"
    );
}

#[test]
fn native_contract_every_annotation_target_preserves_exact_route() {
    let origin = Origin {
        tu: "original.cpp".into(),
        local: 8,
    };
    let targets = [
        AnnotationTarget::Declaration(origin.clone()),
        AnnotationTarget::Return(origin.clone()),
        AnnotationTarget::Parameter {
            declaration: origin.clone(),
            index: 2,
        },
        AnnotationTarget::Field {
            declaration: origin.clone(),
            index: 3,
        },
        AnnotationTarget::NestedField {
            declaration: origin.clone(),
            path: vec![3, 1, 2],
        },
        AnnotationTarget::Variant {
            declaration: origin.clone(),
            index: 4,
        },
        AnnotationTarget::Method {
            declaration: origin.clone(),
            index: 5,
        },
        AnnotationTarget::MethodReturn {
            declaration: origin.clone(),
            index: 5,
        },
        AnnotationTarget::MethodParameter {
            declaration: origin.clone(),
            method: 5,
            parameter: 2,
        },
    ];
    let routes = targets
        .iter()
        .map(|target| {
            let (owner, route) = annotation_route(target);
            assert_eq!(owner, &origin);
            route
        })
        .collect::<BTreeSet<_>>();
    assert_eq!(routes.len(), 9);
    assert!(routes.contains(&Route::NestedField(vec![3, 1, 2])));
    assert!(routes.contains(&Route::MethodParameter(5, 2)));
}

#[test]
fn native_contract_unknown_bodies_and_unresolvable_references_fail_closed() {
    let origin = Origin {
        tu: "original.cpp".into(),
        local: 1,
    };
    let fact = Fact {
        origin: origin.clone(),
        parent: Some(Origin {
            tu: origin.tu.clone(),
            local: 99,
        }),
        kind: FactKind::Struct,
        name: "Unknown".into(),
        spelling: Location {
            file: "physical.h".into(),
            offset: 42,
        },
        expansion: Location {
            file: "physical.h".into(),
            offset: 42,
        },
        definition: true,
        main_file: false,
        root: true,
        system: false,
        data: FactData::None,
    };
    assert!(
        check_data(
            &fact,
            &NativeLookup::new(std::slice::from_ref(&fact)).unwrap()
        )
        .unwrap_err()
        .contains("unknown native body")
    );
    assert!(
        physical(
            &origin,
            &NativeLookup::new(std::slice::from_ref(&fact)).unwrap(),
            &mut BTreeSet::new()
        )
        .unwrap_err()
        .contains("unresolved native Origin")
    );
    let reference = TypeRef::Named {
        name: "Unknown".into(),
        declaration: Location {
            file: "other.h".into(),
            offset: 42,
        },
    };
    assert!(
        check_type(
            &reference,
            &origin,
            &NativeLookup::new(std::slice::from_ref(&fact)).unwrap()
        )
        .unwrap_err()
        .contains("unresolved native reference")
    );
}

fn lookup_fact(tu: &str, local: u32, name: &str, offset: u32) -> Fact {
    let location = Location {
        file: "physical.h".into(),
        offset,
    };
    Fact {
        origin: Origin {
            tu: tu.into(),
            local,
        },
        parent: None,
        kind: FactKind::Typedef,
        name: name.into(),
        spelling: location.clone(),
        expansion: location,
        definition: true,
        main_file: false,
        root: true,
        system: false,
        data: FactData::Typedef {
            target: TypeRef::Scalar(windows_clang::Scalar::I32),
        },
    }
}

#[test]
fn native_contract_lookup_inspections_ignore_unrelated_fact_count() {
    for unrelated in [0, 20_000] {
        for conflicting in [false, true] {
            let first = lookup_fact("original.cpp", 1, "Target", 42);
            let mut second = lookup_fact("original.cpp", 2, "Target", 42);
            if conflicting {
                second.data = FactData::Typedef {
                    target: TypeRef::Scalar(windows_clang::Scalar::I64),
                };
            }
            let origin = first.origin.clone();
            let named = TypeRef::Named {
                name: first.name.clone(),
                declaration: first.spelling.clone(),
            };
            let generic = TypeRef::Generic {
                name: first.name.clone(),
                declaration: first.spelling.clone(),
                args: vec![TypeRef::Scalar(windows_clang::Scalar::U32)],
            };
            let mut facts = vec![first, second];
            for index in 0..unrelated {
                facts.push(lookup_fact(
                    if index % 3 == 0 {
                        "foreign.cpp"
                    } else {
                        "original.cpp"
                    },
                    index + 100,
                    if index % 3 == 1 { "Other" } else { "Target" },
                    if index % 3 == 2 { index + 100 } else { 42 },
                ));
            }
            let previous_builds = LOOKUP_BUILDS.with(Cell::get);
            let lookup = NativeLookup::new(&facts).unwrap();
            assert_eq!(lookup.indexed_facts, unrelated as usize + 2);
            assert_eq!(lookup.inspected_candidates.get(), 0);
            for index in 0..256 {
                let result = check_type(
                    if index % 2 == 0 { &named } else { &generic },
                    &origin,
                    &lookup,
                );
                if conflicting {
                    assert!(result.unwrap_err().contains("ambiguous native reference"));
                } else {
                    result.unwrap();
                }
            }
            assert_eq!(lookup.inspected_candidates.get(), 512);
            assert_eq!(lookup.indexed_facts, unrelated as usize + 2);
            let builds = LOOKUP_BUILDS.with(Cell::get) - previous_builds;
            assert_eq!(builds, 1);
            println!(
                "lookup cardinality: unrelated={unrelated} conflicting={conflicting} index_builds={builds} indexed_facts={} lookups=256 inspected_candidates={}",
                lookup.indexed_facts,
                lookup.inspected_candidates.get(),
            );
        }
    }
}

#[test]
fn native_contract_lookup_keeps_inputs_locations_and_parent_alternatives_exact() {
    let first = lookup_fact("original.cpp", 1, "Target", 42);
    let mut foreign = lookup_fact("foreign.cpp", 1, "Target", 42);
    foreign.data = FactData::Typedef {
        target: TypeRef::Scalar(windows_clang::Scalar::I64),
    };
    let reference = TypeRef::Named {
        name: first.name.clone(),
        declaration: first.spelling.clone(),
    };
    let inputs = [first.clone(), foreign.clone()];
    let lookup = NativeLookup::new(&inputs).unwrap();
    check_type(&reference, &first.origin, &lookup).unwrap();
    check_type(&reference, &foreign.origin, &lookup).unwrap();
    assert_eq!(lookup.inspected_candidates.get(), 2);
    let missing = TypeRef::Named {
        name: first.name.clone(),
        declaration: Location {
            file: first.spelling.file.clone(),
            offset: 43,
        },
    };
    assert!(
        check_type(&missing, &first.origin, &lookup)
            .unwrap_err()
            .contains("unresolved native reference")
    );
    let other_input = Origin {
        tu: "missing.cpp".into(),
        local: 1,
    };
    assert!(
        check_type(&reference, &other_input, &lookup)
            .unwrap_err()
            .contains("unresolved native reference")
    );
    assert_eq!(lookup.inspected_candidates.get(), 2);

    let mut left_parent = lookup_fact("original.cpp", 3, "Left", 10);
    left_parent.kind = FactKind::Namespace;
    left_parent.data = FactData::None;
    let mut right_parent = lookup_fact("original.cpp", 4, "Right", 20);
    right_parent.kind = FactKind::Namespace;
    right_parent.data = FactData::None;
    let mut left = first.clone();
    left.parent = Some(left_parent.origin.clone());
    let mut right = first.clone();
    right.origin.local = 2;
    right.parent = Some(right_parent.origin.clone());
    let facts = [left, right, left_parent, right_parent];
    let lookup = NativeLookup::new(&facts).unwrap();
    let error = check_type(&reference, &first.origin, &lookup).unwrap_err();
    assert!(error.contains("ambiguous native reference"));
    assert!(
        error.contains("local: 3") && error.contains("local: 4"),
        "{error}"
    );
    assert_eq!(lookup.inspected_candidates.get(), 2);
    assert_eq!(lookup.indexed_facts, 4);

    let mut missing_parent = first.clone();
    missing_parent.parent = Some(Origin {
        tu: first.origin.tu.clone(),
        local: 99,
    });
    let facts = [missing_parent];
    let lookup = NativeLookup::new(&facts).unwrap();
    assert!(
        check_type(&reference, &first.origin, &lookup)
            .unwrap_err()
            .contains("unresolved native Origin")
    );
    let mut cycle = first.clone();
    cycle.parent = Some(cycle.origin.clone());
    let facts = [cycle];
    let lookup = NativeLookup::new(&facts).unwrap();
    assert!(
        check_type(&reference, &first.origin, &lookup)
            .unwrap_err()
            .contains("cyclic native parent")
    );
    let duplicate = [first.clone(), first];
    assert!(
        NativeLookup::new(&duplicate)
            .unwrap_err()
            .contains("duplicate native Origin")
    );
}
