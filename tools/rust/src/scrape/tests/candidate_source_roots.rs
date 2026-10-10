use super::*;

#[test]
fn candidate_original_main_roots_preserve_native_source_observations() {
    check_original_main_roots(false);
}

#[test]
fn candidate_original_main_roots_preserve_authored_const_double() {
    check_original_main_roots(true);
}

fn check_original_main_roots(with_constants: bool) {
    ensure_libclang();
    let root = scratch(if with_constants {
        "candidate-original-main-constants"
    } else {
        "candidate-original-main-roots"
    });
    let mut originals = Vec::new();
    let mut headers = Vec::new();
    let mut wrapper = String::new();
    for (name, value) in [("First", 11), ("Second", 23)] {
        let header = root.join(format!("{name}.h"));
        std::fs::write(&header, format!("struct {name}Record {{ int field; }};\n")).unwrap();
        let authored = if with_constants {
            format!("const double {name}Authored = {name}_MAIN_VALUE;\n")
        } else {
            String::new()
        };
        let source = format!(
            "#define {name}_MAIN_VALUE {value}\n\
             #include \"{name}.h\"\n\
             {authored}\
             extern \"C\" int __stdcall {name}Callable(const {name}Record *value);\n"
        );
        let main = root.join(format!("{name}-main.cpp"));
        std::fs::write(&main, &source).unwrap();
        let main = path_arg(&main, "original main").unwrap();
        let header = path_arg(&header, "traverse header").unwrap();
        originals.push(Input::new(&main, source).with_roots([header.clone()]));
        headers.push(header);
        wrapper.push_str(&format!("#include \"{main}\"\n"));
    }
    let args = ["-x", "c++", "--target=x86_64-pc-windows-msvc"];
    let split = windows_clang::extract(originals.clone(), &args).unwrap();
    for (name, value) in [("First", 11.0_f64), ("Second", 23.0_f64)]
        .into_iter()
        .filter(|_| with_constants)
    {
        let authored = split
            .constants()
            .iter()
            .find(|constant| constant.name == format!("{name}Authored"))
            .expect("tracked producer must extract the original const double");
        assert_eq!(
            authored.ty,
            windows_clang::TypeRef::Scalar(windows_clang::Scalar::F64)
        );
        assert_eq!(authored.value, windows_clang::Value::F64(value.to_bits()));
    }
    let wrapper_name = path_arg(&root.join("folded.cpp"), "wrapper").unwrap();
    let folded_input = Input::new(&wrapper_name, &wrapper).with_roots(
        originals
            .iter()
            .flat_map(|input| input.roots.iter().cloned()),
    );
    assert!(folded_input.roots.contains(&folded_input.name));
    for original in &originals {
        assert!(original.roots.is_subset(&folded_input.roots));
    }
    let folded = windows_clang::extract([folded_input], &args).unwrap();
    let report = native_contract::compare(&[&split], &folded);
    assert!(report.missing.is_empty(), "{report:#?}");
    assert!(report.changed.is_empty(), "{report:#?}");
    assert!(report.extras.is_empty(), "{report:#?}");
    // The tracked producer has no Fact for these const VarDecl origins; keep the gate closed.
    let mut expected_incomplete = Vec::new();
    if with_constants {
        for (label, snapshot) in [("original", &split), ("folded", &folded)] {
            for name in ["FirstAuthored", "SecondAuthored"] {
                let constant = snapshot
                    .constants()
                    .iter()
                    .find(|constant| constant.name == name)
                    .unwrap();
                assert!(
                    !snapshot
                        .facts()
                        .iter()
                        .any(|fact| fact.origin == constant.root)
                );
                expected_incomplete.push(format!(
                    "{label}: unresolved native Origin {:?}",
                    constant.root
                ));
            }
        }
    }
    assert_eq!(report.incomplete, expected_incomplete);
    assert_eq!(report.retained(), !with_constants);
    println!(
        "with original main roots: retained={} missing={} changed={} extras={} incomplete={}",
        report.retained.len(),
        report.missing.len(),
        report.changed.len(),
        report.extras.len(),
        report.incomplete.len(),
    );
    for (name, value) in [("First", 11), ("Second", 23)] {
        let original = split
            .facts()
            .iter()
            .find(|fact| fact.name == format!("{name}_MAIN_VALUE"))
            .unwrap();
        let actual = folded
            .facts()
            .iter()
            .find(|fact| fact.name == original.name && fact.spelling == original.spelling)
            .unwrap();
        assert!(original.root && original.main_file);
        assert!(actual.root && !actual.main_file);
        assert_eq!(actual.expansion, original.expansion);
        let FactData::Macro {
            function_like,
            tokens,
        } = &actual.data
        else {
            panic!("original-main macro must retain its complete native payload: {actual:#?}");
        };
        assert!(!function_like);
        assert_eq!(tokens, &[value.to_string()]);
        if with_constants {
            let authored = folded
                .constants()
                .iter()
                .find(|constant| constant.name == format!("{name}Authored"))
                .unwrap();
            let original_authored = split
                .constants()
                .iter()
                .find(|constant| {
                    constant.name == authored.name && constant.spelling == authored.spelling
                })
                .unwrap();
            assert_eq!(authored.ty, original_authored.ty);
            assert_eq!(authored.value, original_authored.value);
            assert_eq!(
                authored.value,
                windows_clang::Value::F64(f64::from(value).to_bits())
            );
        }
        let callable = folded
            .facts()
            .iter()
            .find(|fact| fact.name == format!("{name}Callable"))
            .unwrap();
        let FactData::Function { params, result, .. } = &callable.data else {
            panic!("external declaration must retain its native signature: {callable:#?}");
        };
        assert_eq!(params.len(), 1);
        assert_eq!(
            *result,
            windows_clang::TypeRef::Scalar(windows_clang::Scalar::I32)
        );
        assert!(matches!(
            params[0].ty,
            windows_clang::TypeRef::Pointer { mutable: false, .. }
        ));
    }
    let without_original_roots = windows_clang::extract(
        [Input::new(&wrapper_name, &wrapper).with_roots(headers)],
        &args,
    )
    .unwrap();
    let report = native_contract::compare(&[&split], &without_original_roots);
    assert!(
        !report.retained(),
        "wrapper root alone must not replace original roots"
    );
    assert!(!report.missing.is_empty(), "{report:#?}");
    for original in split.constants() {
        assert!(!without_original_roots.constants().iter().any(|actual| {
            actual.spelling == original.spelling && actual.name == original.name
        }));
    }
    println!(
        "without original main roots: retained={} missing={} changed={} extras={} incomplete={}",
        report.retained.len(),
        report.missing.len(),
        report.changed.len(),
        report.extras.len(),
        report.incomplete.len(),
    );
    for original in split
        .facts()
        .iter()
        .filter(|fact| matches!(fact.data, FactData::Macro { .. }) && fact.main_file)
    {
        let actual = without_original_roots
            .facts()
            .iter()
            .find(|fact| fact.spelling == original.spelling && fact.name == original.name)
            .unwrap();
        assert!(!actual.root && !actual.main_file);
        assert_eq!(actual.data, FactData::None);
    }
    std::fs::remove_dir_all(root).unwrap();
}
