use super::*;
use windows_metadata::{HasAttributes, Type, Value};

#[test]
#[ignore = "requires normally prepared current SDK headers and a fresh WIN32METADATA_COM_OUTPUT_ROOT"]
fn sdk_independent_com_provider_contexts_x64() {
    ensure_libclang();
    let output = PathBuf::from(
        std::env::var_os("WIN32METADATA_COM_OUTPUT_ROOT")
            .expect("set a fresh COM provider evidence directory"),
    );
    std::fs::create_dir(&output).unwrap();
    let win_sdk = checked_in_win_sdk();
    let prepared = win_sdk.join("obj").join("RecompiledIdlHeaders");
    assert!(prepared.join("um").join("txdtc.h").is_file());
    let options = Options {
        win32_sdk: true,
        partition_policy_root: Some(win_sdk.join("Partitions")),
        namespace_routes: Some(win_sdk.join("requiredNamespacesForNames.rsp")),
        includes: vec![
            prepared,
            win_sdk.join("AdditionalHeaders").join("cpdk"),
            win_sdk.join("AdditionalHeaders"),
            win_sdk.join("Partitions").join("Com.StructuredStorage"),
            win_sdk.join("inc"),
            sdk_header_root(),
        ],
        ..Default::default()
    };
    assert_eq!(options.includes.len(), 6);
    let include_dirs = include_dirs(&options).unwrap();
    let traversal = crate::partition::load_traversal_policy(
        options.partition_policy_root.as_ref().unwrap(),
        &include_dirs,
    )
    .unwrap();
    validate_aggregate_compile_environment(&traversal).unwrap();
    let headers = convert_header_partition_policy(&traversal).unwrap();
    let ScrapeInputs::Common(inputs) =
        build_inputs(&options, &include_dirs, &[], Some(&traversal)).unwrap()
    else {
        panic!("expected production authority inputs");
    };
    assert_eq!(inputs.len(), 8);
    let raw = Options {
        win32_sdk: true,
        ..Default::default()
    };
    let ScrapeInputs::Common(raw_inputs) = build_inputs(&raw, &include_dirs, &[], None).unwrap()
    else {
        panic!("expected raw SDK common inputs");
    };
    assert_eq!(raw_inputs.len(), 2);
    let inputs = inputs
        .into_iter()
        .filter(|input| {
            [AGGREGATE_INPUT, DTC_INPUT, MMC_INPUT, WINSYNC_INPUT].contains(&input.name.as_str())
        })
        .map(|mut input| {
            if input.name == AGGREGATE_INPUT {
                input.source = crate::aggregate::main_prelude(WIN32_SDK_PRELUDE);
                crate::aggregate::append_input_ime(&mut input.source);
                input.source.push_str(
                    "\n#include <ks.h>\n#include <ksmedia.h>\n\
                     #include <strmif.h>\n#include <tuner.h>\n\
                     #include <commctrl.h>\n#include <commoncontrols.h>\n\
                     #include <mshtml.h>\n",
                );
            }
            std::fs::write(output.join(&input.name), &input.source).unwrap();
            input
        })
        .collect::<Vec<_>>();
    assert_eq!(inputs.len(), 4);
    let providers: [(&str, &str, &str, &str, &str, &[&str]); 8] = [
        (
            DTC_INPUT,
            "txdtc.h",
            "Windows.Win32.System.DistributedTransactionCoordinator",
            "IResourceManager",
            "13741d21-87eb-11ce-8081-0080c758527e",
            &[
                "Enlist",
                "Reenlist",
                "ReenlistmentComplete",
                "GetDistributedTransactionManager",
            ],
        ),
        (
            MMC_INPUT,
            "mmc.h",
            "Windows.Win32.System.Mmc",
            "IComponent",
            "43136eb2-d36c-11cf-adbc-00aa00a80033",
            &[
                "Initialize",
                "Notify",
                "Destroy",
                "QueryDataObject",
                "GetResultViewType",
                "GetDisplayInfo",
                "CompareObjects",
            ],
        ),
        (
            MMC_INPUT,
            "mmc.h",
            "Windows.Win32.System.Mmc",
            "IImageList",
            "43136eb8-d36c-11cf-adbc-00aa00a80033",
            &["ImageListSetIcon", "ImageListSetStrip"],
        ),
        (
            WINSYNC_INPUT,
            "winsync.h",
            "Windows.Win32.System.WindowsSync",
            "IRangeException",
            "75ae8777-6848-49f7-956c-a3a92f5096e8",
            &["GetClosedRangeStart", "GetClosedRangeEnd", "GetClockVector"],
        ),
        (
            AGGREGATE_INPUT,
            "strmif.h",
            "Windows.Win32.Media.DirectShow",
            "IResourceManager",
            "56a868ac-0ad4-11ce-b03a-0020af0ba770",
            &[
                "Register",
                "RegisterGroup",
                "RequestResource",
                "NotifyAcquire",
                "NotifyRelease",
                "CancelRequest",
                "SetFocus",
                "ReleaseFocus",
            ],
        ),
        (
            AGGREGATE_INPUT,
            "tuner.h",
            "Windows.Win32.Media.DirectShow.Tv",
            "IComponent",
            "1a5576fc-0e19-11d3-9d8e-00c04f72d980",
            &[
                "get_Type",
                "put_Type",
                "get_DescLangID",
                "put_DescLangID",
                "get_Status",
                "put_Status",
                "get_Description",
                "put_Description",
                "Clone",
            ],
        ),
        (
            AGGREGATE_INPUT,
            "commoncontrols.h",
            "Windows.Win32.UI.Controls",
            "IImageList",
            "46eb5926-582e-4017-9fdf-e8998daa0950",
            &[
                "Add",
                "ReplaceIcon",
                "SetOverlayImage",
                "Replace",
                "AddMasked",
                "Draw",
                "Remove",
                "GetIcon",
                "GetImageInfo",
                "Copy",
                "Merge",
                "Clone",
                "GetImageRect",
                "GetIconSize",
                "SetIconSize",
                "GetImageCount",
                "SetImageCount",
                "SetBkColor",
                "GetBkColor",
                "BeginDrag",
                "EndDrag",
                "DragEnter",
                "DragLeave",
                "DragMove",
                "SetDragCursorImage",
                "DragShowNolock",
                "GetDragImage",
                "GetItemFlags",
                "GetOverlayImage",
            ],
        ),
        (
            AGGREGATE_INPUT,
            "mshtml.h",
            "Windows.Win32.Web.MsHtml",
            "IRangeException",
            "3051072d-98b5-11cf-bb82-00aa00bdce0b",
            &["put_code", "get_code", "get_message"],
        ),
    ];
    let references = MetadataReferences::new([windows_metadata::reader::File::new(
        windows_default::WINRT.to_vec(),
    )
    .unwrap()]);
    let no_functions = BTreeSet::new();
    let mut emit = EmitOptions::new(DEFAULT_NAMESPACE, references.types());
    emit.functions = Some(&no_functions);
    let routes =
        crate::namespace_routes::NamespaceRoutes::load(options.namespace_routes.as_ref().unwrap())
            .unwrap();
    let authorities = routes.authorities();
    let mut dispatch_report = String::new();
    for name in ["LPDISPATCH", "IDispatch"] {
        dispatch_report.push_str(&format!(
            "Required route for {name}: exact={:?}, prefixes={:?}\n",
            routes.exact.get(name),
            routes
                .prefixes
                .iter()
                .filter(|(prefix, _)| name.starts_with(prefix.as_str()))
                .collect::<Vec<_>>()
        ));
    }
    let root_plan = build_authority_root_plan(&traversal).unwrap();
    for partition in &traversal.partitions {
        let mut record = |path: &Path, canonical_path, inventory_path: &str| {
            if !["oaidl.h", "oleauto.h"].iter().any(|header| {
                source_file_name(&path.to_string_lossy()).eq_ignore_ascii_case(header)
            }) {
                return;
            }
            let input =
                logical_policy_input(&root_plan, &partition.identity, canonical_path).unwrap();
            dispatch_report.push_str(&format!(
                "header={inventory_path}, path={}, input={input}, owner={}, namespace={}, policy={:#?}\n",
                path.display(),
                partition.identity,
                emitted_partition_namespace(partition),
                partition.policy
            ));
        };
        for root in &partition.roots {
            match root {
                crate::partition::TraversalRoot::File(root) => {
                    record(&root.path, &root.canonical_path, &root.inventory_path);
                }
                crate::partition::TraversalRoot::Directory(root) => {
                    for file in &root.files {
                        record(&file.path, &file.canonical_path, &file.inventory_path);
                    }
                }
                crate::partition::TraversalRoot::Missing(_)
                | crate::partition::TraversalRoot::Unsupported(_) => {
                    unreachable!("validated traversal policy is clean");
                }
            }
        }
    }
    let args = checked_in_clang_args(&include_dirs);
    std::fs::write(output.join("arguments.txt"), args.join("\n")).unwrap();
    eprintln!("COM provider control: extracting x64");
    let snapshot =
        windows_clang::extract(inputs, &args.iter().map(String::as_str).collect::<Vec<_>>())
            .unwrap();
    std::fs::write(
        output.join("included-files.txt"),
        format!("{:#?}", snapshot.included_files()),
    )
    .unwrap();
    let dispatch_facts = snapshot
        .facts()
        .iter()
        .filter(|fact| ["LPDISPATCH", "IDispatch"].contains(&fact.name.as_str()))
        .map(|fact| {
            (
                fact,
                snapshot
                    .annotations()
                    .get(&AnnotationTarget::Declaration(fact.origin.clone())),
            )
        })
        .collect::<Vec<_>>();
    dispatch_report.push_str(&format!("\nCaptured declarations: {dispatch_facts:#?}\n"));
    std::fs::write(output.join("lpdispatch-preservation.txt"), &dispatch_report).unwrap();
    let facts = snapshot
        .facts()
        .iter()
        .filter(|fact| {
            providers
                .iter()
                .any(|(_, _, _, name, _, _)| fact.name == *name)
                || [
                    "IResourceManager2",
                    "IResourceManagerFactory",
                    "IComponent2",
                    "IConsole",
                    "IEnumRangeExceptions",
                ]
                .contains(&fact.name.as_str())
        })
        .collect::<Vec<_>>();
    std::fs::write(output.join("provider-facts.txt"), format!("{facts:#?}")).unwrap();
    for (input, header, _, name, guid, names) in providers {
        let found = snapshot
            .facts()
            .iter()
            .filter(|fact| {
                fact.origin.tu == input
                    && fact.name == name
                    && fact.definition
                    && matches!(fact.data, FactData::Interface { .. })
            })
            .collect::<Vec<_>>();
        let [fact] = found.as_slice() else {
            panic!("expected exactly one x64 {input} {name}: {found:#?}");
        };
        assert!(source_file_name(&fact.spelling.file).eq_ignore_ascii_case(header));
        let FactData::Interface {
            guid: actual,
            methods,
            ..
        } = &fact.data
        else {
            unreachable!()
        };
        assert_eq!(actual.as_deref(), Some(guid), "x64 {name}");
        assert_eq!(
            methods
                .iter()
                .map(|method| method.name.as_str())
                .collect::<Vec<_>>(),
            names,
            "x64 {name}",
        );
    }
    eprintln!("COM provider control: eight x64 native bodies verified; planning");
    let partitions = match plan_header_partitions(&snapshot, &headers, &authorities, &emit, "x64") {
        Ok(partitions) => partitions,
        Err(error) => {
            std::fs::write(output.join("planning-error.txt"), &error).unwrap();
            panic!("COM provider control: x64 planning failed: {error}");
        }
    };
    for (partition, rdl) in &partitions {
        for (line, text) in rdl.lines().enumerate() {
            if text.contains("LPDISPATCH") {
                dispatch_report.push_str(&format!(
                    "RDL {}:{}: {text}\n",
                    partition.namespace,
                    line + 1
                ));
            }
        }
    }
    std::fs::write(output.join("lpdispatch-preservation.txt"), &dispatch_report).unwrap();
    for (namespace, derived, base) in [
        (
            "Windows.Win32.System.DistributedTransactionCoordinator",
            "IResourceManager2",
            "IResourceManager",
        ),
        ("Windows.Win32.System.Mmc", "IComponent2", "IComponent"),
    ] {
        let rdl = partitions
            .iter()
            .filter(|(partition, _)| partition.namespace == namespace)
            .map(|(_, rdl)| rdl.as_str())
            .collect::<String>();
        assert!(
            rdl.contains(&format!("interface {derived}: {base}")),
            "{namespace}: {rdl}"
        );
    }
    let rdl = output.join("rdl");
    std::fs::create_dir(&rdl).unwrap();
    write_partitioned_rdl(&rdl, partitions).unwrap();
    let image = output.join("Providers.winmd");
    compile_inputs(&[rdl], &[], DEFAULT_NAMESPACE, None, &image).unwrap();
    let index = Index::read(&image).unwrap();
    for name in ["LPDISPATCH", "IDispatch"] {
        let namespaces = index
            .iter()
            .filter(|(_, candidate, _)| *candidate == name)
            .map(|(namespace, _, _)| namespace)
            .collect::<Vec<_>>();
        dispatch_report.push_str(&format!("\nPhysical {name} namespaces: {namespaces:?}\n"));
        for namespace in namespaces {
            let definition = index.expect(namespace, name);
            let fields = definition
                .fields()
                .map(|field| (field.name(), field.ty()))
                .collect::<Vec<_>>();
            dispatch_report.push_str(&format!("{namespace}.{name} fields: {fields:#?}\n"));
        }
    }
    for (namespace, name) in [
        ("Windows.Win32.Media.DirectShow.Tv", "IComponent"),
        ("Windows.Win32.Web.MsHtml", "IRangeException"),
    ] {
        let bases = index
            .expect(namespace, name)
            .interface_impls()
            .map(|implementation| implementation.interface(&[]))
            .collect::<Vec<_>>();
        dispatch_report.push_str(&format!("{namespace}.{name} physical bases: {bases:#?}\n"));
    }
    std::fs::write(output.join("lpdispatch-preservation.txt"), &dispatch_report).unwrap();
    for (_, _, namespace, name, guid, methods) in providers {
        assert_eq!(
            index
                .iter()
                .filter(|(ns, n, _)| *ns == namespace && *n == name)
                .count(),
            1
        );
        let record = index.expect(namespace, name);
        let hex = guid.replace('-', "");
        let mut expected = vec![
            Value::U32(u32::from_str_radix(&hex[..8], 16).unwrap()),
            Value::U16(u16::from_str_radix(&hex[8..12], 16).unwrap()),
            Value::U16(u16::from_str_radix(&hex[12..16], 16).unwrap()),
        ];
        expected.extend(
            (16..32)
                .step_by(2)
                .map(|offset| Value::U8(u8::from_str_radix(&hex[offset..offset + 2], 16).unwrap())),
        );
        assert_eq!(
            record
                .find_attribute("GuidAttribute")
                .unwrap()
                .value()
                .into_iter()
                .map(|(_, value)| value)
                .collect::<Vec<_>>(),
            expected
        );
        assert_eq!(
            record
                .methods()
                .map(|method| method.name())
                .collect::<Vec<_>>(),
            methods
        );
    }
    for (namespace, derived, base) in [
        (
            "Windows.Win32.System.DistributedTransactionCoordinator",
            "IResourceManager2",
            "IResourceManager",
        ),
        ("Windows.Win32.System.Mmc", "IComponent2", "IComponent"),
    ] {
        assert_eq!(
            index
                .expect(namespace, derived)
                .interface_impls()
                .map(|implementation| implementation.interface(&[]))
                .collect::<Vec<_>>(),
            [Type::class_named(namespace, base)],
            "x64: {namespace}.{derived} physical base"
        );
    }
    for (namespace, owner, method, parameter, target) in [
        (
            "Windows.Win32.System.DistributedTransactionCoordinator",
            "IResourceManagerFactory",
            "Create",
            3,
            "IResourceManager",
        ),
        (
            "Windows.Win32.System.Mmc",
            "IConsole",
            "QueryScopeImageList",
            0,
            "IImageList",
        ),
        (
            "Windows.Win32.System.Mmc",
            "IConsole",
            "QueryResultImageList",
            0,
            "IImageList",
        ),
        (
            "Windows.Win32.System.WindowsSync",
            "IEnumRangeExceptions",
            "Next",
            1,
            "IRangeException",
        ),
    ] {
        let definition = index.expect(namespace, owner);
        let method = definition
            .methods()
            .find(|candidate| candidate.name() == method)
            .unwrap();
        assert_eq!(
            method.signature(&[]).types[parameter],
            Type::PtrMut(Box::new(Type::class_named(namespace, target)), 1),
            "x64 {namespace}.{owner}.{}",
            method.name(),
        );
    }
    eprintln!("COM provider control: x64 physical readback passed");
}
