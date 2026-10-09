use super::*;
use sha2::{Digest, Sha256};
use windows_metadata::{ParamAttributes, Type};

const HEADERS: [(&str, &str, &str); 2] = [
    ("synchapi.h", "Threading", "Windows.Win32.System.Threading"),
    (
        "fileapi.h",
        "FileSystem",
        "Windows.Win32.Storage.FileSystem",
    ),
];

#[test]
#[ignore = "requires pinned SDK caches, matching Clang resources, and a fresh WIN32METADATA_FOLDING_OUTPUT"]
fn sdk_split_and_folded_x64() {
    ensure_libclang();
    let output = PathBuf::from(
        std::env::var_os("WIN32METADATA_FOLDING_OUTPUT")
            .expect("set a fresh WIN32METADATA_FOLDING_OUTPUT directory"),
    );
    std::fs::create_dir(&output).unwrap();
    let sdk = sdk_header_root();
    let includes = include_dirs(&Options {
        includes: vec![
            checked_in_win_sdk().join("AdditionalHeaders"),
            checked_in_win_sdk().join("inc"),
            sdk.clone(),
        ],
        ..Default::default()
    })
    .unwrap();
    let mut args = checked_in_clang_args(&includes);
    args.extend([
        "-resource-dir".to_string(),
        libclang::clang_resource_dir(&output).unwrap(),
    ]);
    std::fs::write(output.join("arguments.txt"), args.join("\n")).unwrap();
    let lib = sdk_package_root("microsoft.windows.sdk.cpp.x64")
        .join("c")
        .join("um")
        .join("x64")
        .join("kernel32.lib");
    let mut native_libraries = LibraryMap::default();
    native_libraries.import_library(&lib).unwrap();
    let mut inputs_manifest = format!(
        "producer\t90fede97db840d543635ceeddd018bfdeef023f1\nsdk\t{}\nlib\t{}\t{:X}\n",
        sdk.display(),
        lib.display(),
        Sha256::digest(std::fs::read(&lib).unwrap()),
    );
    for (header, _, namespace) in HEADERS {
        let path = sdk.join("um").join(header);
        inputs_manifest.push_str(&format!(
            "root\t{}\t{}\t{:X}\n",
            path.display(),
            namespace,
            Sha256::digest(std::fs::read(&path).unwrap()),
        ));
    }
    std::fs::write(output.join("inputs.tsv"), inputs_manifest).unwrap();
    let args = args.iter().map(String::as_str).collect::<Vec<_>>();
    let native_probe = "#include <windows.h>\n\
        static_assert(__is_same(decltype(&ReadFile), BOOL (WINAPI *)(HANDLE, LPVOID, DWORD, LPDWORD, LPOVERLAPPED)));\n\
        static_assert(__is_same(LPVOID, void *));\n";
    std::fs::write(output.join("native-probe.cpp"), native_probe).unwrap();
    windows_clang::extract([Input::new("native-probe.cpp", native_probe)], &args).unwrap();
    let mut inventories = Vec::new();
    let mut readfile_signatures = Vec::new();
    for folded in [false, true] {
        let label = if folded { "folded" } else { "split" };
        let root = output.join(label);
        std::fs::create_dir(&root).unwrap();
        let mut policy = HeaderPartitionPolicy::new();
        let mut inputs = Vec::new();
        let mut folded_roots = Vec::new();
        for (number, (header, partition, namespace)) in HEADERS.into_iter().enumerate() {
            let path = path_arg(&sdk.join("um").join(header), "SDK header").unwrap();
            let input = if folded {
                "folded.cpp".to_string()
            } else {
                format!("split-{number}.cpp")
            };
            policy.add_traversed_header_for_input(
                &input,
                path.clone(),
                RootPartition::new(partition, namespace),
            );
            if folded {
                folded_roots.push(path);
            } else {
                inputs.push(Input::new(input, "#include <windows.h>\n").with_roots([path]));
            }
        }
        if folded {
            inputs
                .push(Input::new("folded.cpp", "#include <windows.h>\n").with_roots(folded_roots));
        }
        for input in &inputs {
            std::fs::write(root.join(&input.name), &input.source).unwrap();
        }
        let snapshot = windows_clang::extract(inputs, &args).unwrap();
        let native_contracts = snapshot
            .facts()
            .iter()
            .filter(|fact| ["ReadFile", "LPVOID"].contains(&fact.name.as_str()))
            .collect::<Vec<_>>();
        std::fs::write(
            root.join("native-contracts.txt"),
            format!("{native_contracts:#?}"),
        )
        .unwrap();
        let libraries = snapshot
            .facts()
            .iter()
            .filter_map(|fact| {
                let FactData::Function { link_name, .. } = &fact.data else {
                    return None;
                };
                native_libraries
                    .resolved_library(link_name)
                    .map(|dll| (link_name.clone(), dll.to_string()))
            })
            .collect::<BTreeMap<_, _>>();
        let selected =
            implicit_selected_functions(&snapshot, &BTreeSet::new(), &libraries, |_| false);
        assert!(
            selected.contains("ReadFile"),
            "missing native root ReadFile"
        );
        std::fs::write(
            root.join("selected.txt"),
            selected.iter().cloned().collect::<Vec<_>>().join("\n"),
        )
        .unwrap();
        let references = MetadataReferences::new([windows_metadata::reader::File::new(
            windows_default::WINRT.to_vec(),
        )
        .unwrap()]);
        let mut emit = EmitOptions::new(DEFAULT_NAMESPACE, references.types());
        emit.functions = Some(&selected);
        emit.libraries = Some(&libraries);
        let partitions = plan_header_partitions(
            &snapshot,
            &policy,
            &NamespaceAuthorities::new(),
            &emit,
            "x64",
        )
        .unwrap();
        let rdl = root.join("rdl");
        std::fs::create_dir(&rdl).unwrap();
        write_partitioned_rdl(&rdl, partitions).unwrap();
        let image = root.join("SdkFolding.winmd");
        compile_inputs(&[rdl], &[], "SdkFolding", None, &image).unwrap();
        let index = Index::read(&image).unwrap();
        let fact = snapshot
            .facts()
            .iter()
            .find(|fact| fact.root && fact.name == "ReadFile")
            .unwrap();
        assert!(source_path_matches(
            &path_arg(&sdk.join("um").join("fileapi.h"), "SDK header").unwrap(),
            &fact.spelling.file,
        ));
        let FactData::Function {
            link_name,
            convention,
            params,
            ..
        } = &fact.data
        else {
            panic!("ReadFile is not a native function");
        };
        let native_buffer = &params[1];
        assert_eq!(native_buffer.name, "lpBuffer");
        let windows_clang::TypeRef::Named { name, declaration } = &native_buffer.ty else {
            panic!("ReadFile.lpBuffer must reference its SDK typedef");
        };
        assert_eq!(name, "LPVOID");
        let alias = snapshot
            .facts()
            .iter()
            .find(|alias| {
                alias.name == *name
                    && alias.origin.tu == fact.origin.tu
                    && alias.spelling == *declaration
            })
            .expect("exact same-TU native LPVOID declaration");
        assert!(source_path_matches(
            &path_arg(&sdk.join("shared").join("minwindef.h"), "SDK typedef").unwrap(),
            &alias.spelling.file,
        ));
        let FactData::Typedef {
            target:
                windows_clang::TypeRef::Pointer {
                    mutable: true,
                    target,
                },
        } = &alias.data
        else {
            panic!("the SDK's LPVOID must be a mutable pointer");
        };
        assert!(matches!(target.as_ref(), windows_clang::TypeRef::Void));
        assert_eq!(
            (
                native_buffer.annotation.input,
                native_buffer.annotation.output,
                native_buffer.annotation.optional
            ),
            (false, true, true),
            "compiler-observed ReadFile.lpBuffer direction via the existing SAL capture bridge",
        );
        let Item::Fn(method) = index.expect_item("Windows.Win32.Storage.FileSystem", "ReadFile")
        else {
            panic!("missing emitted ReadFile");
        };
        let signature = method.signature(&[]);
        assert_eq!(signature.return_type, Type::I32);
        assert_eq!(signature.types.len(), params.len());
        let rows = method.params_by_sequence(signature.types.len()).unwrap();
        let buffer = rows.params()[1].unwrap();
        assert_eq!(buffer.name(), native_buffer.name);
        for (flag, observed) in [
            (ParamAttributes::In, native_buffer.annotation.input),
            (ParamAttributes::Out, native_buffer.annotation.output),
            (ParamAttributes::Optional, native_buffer.annotation.optional),
        ] {
            assert_eq!(
                buffer.flags().contains(flag),
                observed,
                "{label}: physical lpBuffer flags"
            );
        }
        let import = method.impl_map().unwrap();
        assert_eq!(import.import_name(), link_name);
        assert_eq!(
            import.import_scope().name().to_ascii_lowercase(),
            native_libraries
                .resolved_library(link_name)
                .unwrap()
                .to_ascii_lowercase(),
        );
        assert_eq!(
            method.calling_convention(),
            match convention {
                windows_clang::CallingConvention::Platform => "system",
                windows_clang::CallingConvention::C => "C",
            },
        );
        // RDL can omit #[out] for raw pointers even when the physical parameter has Out.
        std::fs::write(
            root.join("readfile-contract.txt"),
            format!(
                "compiler_observed_typedef_source\t{:?}\ncompiler_observed_direction\t{:?}\nemitted_signature\t{:?}\nemitted_buffer_flags\t{:?}\n",
                declaration, native_buffer.annotation, signature, buffer.flags(),
            ),
        ).unwrap();
        readfile_signatures.push((signature.return_type, signature.types));
        let inventory = root.join("inventory.rdl");
        windows_rdl::writer()
            .input(&image)
            .output(&inventory)
            .write()
            .unwrap();
        let inventory = std::fs::read_to_string(&inventory).unwrap();
        let readfile_lines = inventory
            .lines()
            .filter(|line| line.contains("extern fn ReadFile("))
            .collect::<Vec<_>>()
            .join("\n");
        std::fs::write(root.join("readfile-rdl.txt"), readfile_lines).unwrap();
        inventories.push(inventory);
        std::fs::write(
            root.join("winmd-sha256.txt"),
            format!("{:X}\n", Sha256::digest(std::fs::read(&image).unwrap())),
        )
        .unwrap();
    }
    assert_eq!(
        readfile_signatures[0], readfile_signatures[1],
        "ReadFile's physical signature must not depend on TU grouping; inspect readfile-contract.txt and readfile-rdl.txt"
    );
    assert!(
        inventories[0] == inventories[1],
        "complete WinMD-derived RDL inventories differ; inspect split/folded inventory.rdl"
    );
}
