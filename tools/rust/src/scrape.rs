//! `scrape`: Windows SDK headers or focused partition inputs -> WinMD.
//!
//! The production path uses the pinned producer's aggregate + satellite header manifest.
//! Logical authority adds only the two required PSAPI compile variants. Focused partition
//! translation units remain available for package fixtures and inner-loop debugging. No path
//! uses generated RSP, JSON, or extraction-checkpoint sidecars.

use std::collections::{BTreeMap, BTreeSet, HashMap};
use std::ffi::OsString;
use std::path::{Path, PathBuf};

use windows_clang::{
    Annotation, AnnotationTarget, EmitOptions, FactData, HeaderPartitionPolicy, Input,
    MetadataReferences, NamespaceAuthorities, PartitionedInput, RdlPartition, RootPartition,
};
use windows_metadata::reader::{Index, Item};
use windows_rdl::ArchInput;

use crate::args::{Args, required, set_once};
use crate::compile::compile_inputs;
use crate::libclang;
use crate::merge_arch::merge_architecture_rdl;

const DEFAULT_NAMESPACE: &str = "Windows.Win32";
const ANNOTATION_HEADER: &str = "win32metadata_annotations.h";
const SAL_HEADER: &str = "win32metadata_sal.h";
const AGGREGATE_INPUT: &str = "win32metadata-aggregate.cpp";
const SATELLITE_INPUT: &str = "win32metadata-satellites.cpp";
const PSAPI_V1_INPUT: &str = "win32metadata-psapi-v1.cpp";
const PSAPI_V2_INPUT: &str = "win32metadata-psapi-v2.cpp";
const CANONICAL_AUTHORITY_SHA256: &str =
    "395FAD2C5729FF81F35311F9D591CA05B9EF4FDCE96173FAB9BBCAF8AFB7E811";

#[derive(Clone, Debug)]
struct Arch {
    name: String,
    triple: String,
    bits: i32,
    defines: Vec<String>,
}

impl Arch {
    fn known(name: &str) -> Option<Self> {
        let (triple, bits) = match name {
            "x64" => ("x86_64-pc-windows-msvc", 2),
            "arm64" => ("aarch64-pc-windows-msvc", 4),
            "x86" => ("i686-pc-windows-msvc", 1),
            _ => return None,
        };
        Some(Self {
            name: name.to_string(),
            triple: triple.to_string(),
            bits,
            defines: Vec::new(),
        })
    }
}

/// Parse the SDK headers as C++ so `extern "C"`, `__declspec`, and SAL are understood.
/// `-ferror-limit=0` keeps clang from dropping later declarations after a tolerated error.
const CLANG_ARGS: [&str; 9] = [
    "-x",
    "c++",
    "-std=c++20",
    "-fms-compatibility",
    "-fms-extensions",
    "-ferror-limit=0",
    "-Wno-pragma-once-outside-header",
    "-DWIN32METADATA=1",
    "-D_COM_NO_STANDARD_GUIDS_=1",
];

/// Header directory segments whose declarations are emitted unconditionally. Anything else
/// a partition pulls in is emitted only when a declaration in scope references it.
const DEFAULT_SCOPES: [&str; 2] = ["shared", "um"];

/// SDK include-root layout. A `--include` directory containing any of these is expanded
/// into them, so the SDK root can be named once.
const SDK_INCLUDE_SUBDIRS: [&[&str]; 5] =
    [&["shared"], &["um"], &["um", "cpdk"], &["ucrt"], &["winrt"]];

#[derive(Default, Debug)]
pub struct Options {
    pub help: bool,
    partitions: Vec<PathBuf>,
    partition_roots: Vec<PathBuf>,
    partition_policy_root: Option<PathBuf>,
    includes: Vec<PathBuf>,
    libs: Vec<PathBuf>,
    archs: Vec<String>,
    scopes: Vec<String>,
    scope_headers: Vec<String>,
    namespace_routes: Option<PathBuf>,
    symbols: Vec<String>,
    constants: Vec<String>,
    win32_sdk: bool,
    namespace: Option<String>,
    assembly_name: Option<String>,
    assembly_version: Option<[u16; 4]>,
    extraction_coverage: Option<PathBuf>,
    output: Option<PathBuf>,
    obj: Option<PathBuf>,
}

pub fn run(args: Vec<OsString>) -> Result<(), String> {
    let mut options = parse(Args::new(args))?;
    if options.help {
        println!("{}", help_text());
        return Ok(());
    }
    absolutize(&mut options)?;
    execute(&options)
}

pub fn parse(mut args: Args) -> Result<Options, String> {
    let mut options = Options::default();

    while let Some(option) = args.next_option()? {
        match option.as_str() {
            "--help" | "-h" => {
                options.help = true;
                return Ok(options);
            }
            "--partition" => options.partitions.push(args.path(&option)?),
            "--partition-root" => options.partition_roots.push(args.path(&option)?),
            "--partition-policy-root" => set_once(
                &mut options.partition_policy_root,
                args.path(&option)?,
                &option,
            )?,
            "--include" => options.includes.push(args.path(&option)?),
            "--lib" => options.libs.push(args.path(&option)?),
            "--arch" => options.archs.push(args.value(&option)?),
            "--scope" => options.scopes.push(args.value(&option)?),
            "--scope-header" => options.scope_headers.push(args.value(&option)?),
            "--namespace-routes" => {
                set_once(&mut options.namespace_routes, args.path(&option)?, &option)?
            }
            "--symbol" => options.symbols.push(args.value(&option)?),
            "--constant" => options.constants.push(args.value(&option)?),
            "--win32-sdk" => options.win32_sdk = true,
            "--namespace" => set_once(&mut options.namespace, args.value(&option)?, &option)?,
            "--assembly-name" => {
                set_once(&mut options.assembly_name, args.value(&option)?, &option)?
            }
            "--assembly-version" => set_once(
                &mut options.assembly_version,
                parse_version(&args.value(&option)?)?,
                &option,
            )?,
            "--extraction-coverage" => set_once(
                &mut options.extraction_coverage,
                args.path(&option)?,
                &option,
            )?,
            "--output" => set_once(&mut options.output, args.path(&option)?, &option)?,
            "--obj" => set_once(&mut options.obj, args.path(&option)?, &option)?,
            _ => {
                return Err(format!(
                    "unknown scrape option `{option}`\n\n{}",
                    help_text()
                ));
            }
        }
    }

    fn parse_version(value: &str) -> Result<[u16; 4], String> {
        let parts = value
            .split('.')
            .map(|part| {
                part.parse::<u16>()
                    .map_err(|_| format!("invalid `--assembly-version {value}`; expected A.B.C.D"))
            })
            .collect::<Result<Vec<_>, _>>()?;

        parts
            .try_into()
            .map_err(|_| format!("invalid `--assembly-version {value}`; expected A.B.C.D"))
    }

    validate(&options)?;
    Ok(options)
}

fn validate(options: &Options) -> Result<(), String> {
    if !options.win32_sdk
        && options.partitions.is_empty()
        && options.partition_roots.is_empty()
        && options.partition_policy_root.is_none()
    {
        return Err(
            "at least one `--partition <main.cpp>`, `--partition-root <dir>`, `--partition-policy-root <dir>`, or `--win32-sdk` is required".to_string(),
        );
    }
    if options.namespace_routes.is_some()
        && options.partitions.is_empty()
        && options.partition_roots.is_empty()
        && options.partition_policy_root.is_none()
    {
        return Err(
            "`--namespace-routes` requires `--partition`, `--partition-root`, or `--partition-policy-root`"
                .to_string(),
        );
    }
    if options.partition_policy_root.is_some() && !options.win32_sdk {
        return Err("`--partition-policy-root` requires `--win32-sdk`".to_string());
    }
    if options.partition_policy_root.is_some()
        && (!options.partitions.is_empty() || !options.partition_roots.is_empty())
    {
        return Err(
            "`--partition-policy-root` cannot be combined with `--partition` or `--partition-root`"
                .to_string(),
        );
    }
    if options.partition_policy_root.is_some()
        && options
            .namespace
            .as_deref()
            .is_some_and(|value| value != DEFAULT_NAMESPACE)
    {
        return Err(format!(
            "`--partition-policy-root` requires `--namespace {DEFAULT_NAMESPACE}`"
        ));
    }
    if options.includes.is_empty() {
        return Err("at least one `--include <dir>` is required".to_string());
    }
    for name in &options.archs {
        if Arch::known(name).is_none() {
            return Err(format!(
                "unknown `--arch {name}`; supported architectures are x64, arm64, x86"
            ));
        }
    }
    if options.extraction_coverage.is_some() {
        if options.partition_policy_root.is_none() {
            return Err("`--extraction-coverage` requires `--partition-policy-root`".to_string());
        }
        if options.output.is_some() {
            return Err("`--extraction-coverage` cannot be combined with `--output`".to_string());
        }
        if options.assembly_name.is_some() || options.assembly_version.is_some() {
            return Err(
                "`--extraction-coverage` cannot be combined with assembly output options"
                    .to_string(),
            );
        }
        if !options.libs.is_empty() {
            return Err(
                "`--extraction-coverage` cannot be combined with import libraries".to_string(),
            );
        }
        if !options.symbols.is_empty() || !options.constants.is_empty() {
            return Err(
                "`--extraction-coverage` cannot be combined with focused symbol or constant selection"
                    .to_string(),
            );
        }
        if archs(options) != ["x64".to_string()] {
            return Err("`--extraction-coverage` requires exactly `--arch x64`".to_string());
        }
    } else {
        required(options.output.as_ref(), "--output")?;
    }

    if !options.symbols.is_empty() && !options.constants.is_empty() {
        return Err("`--symbol` and `--constant` cannot be combined".to_string());
    }

    Ok(())
}

/// Requested architectures, defaulting to a single x64 pass.
fn archs(options: &Options) -> Vec<String> {
    if options.archs.is_empty() {
        vec!["x64".to_string()]
    } else {
        options.archs.clone()
    }
}

fn scopes(options: &Options) -> Vec<&str> {
    if options.scopes.is_empty() {
        DEFAULT_SCOPES.to_vec()
    } else {
        options.scopes.iter().map(String::as_str).collect()
    }
}

fn namespace(options: &Options) -> &str {
    options.namespace.as_deref().unwrap_or(DEFAULT_NAMESPACE)
}

fn scope_header_suffixes(options: &Options) -> impl Iterator<Item = String> + '_ {
    options.scope_headers.iter().map(|header| {
        if Path::new(header).extension().is_some() {
            header.clone()
        } else {
            format!("{header}.h")
        }
    })
}

fn assembly_name(options: &Options) -> Result<&str, String> {
    if let Some(name) = &options.assembly_name {
        return Ok(name);
    }

    options
        .output
        .as_ref()
        .and_then(|path| path.file_stem())
        .and_then(|name| name.to_str())
        .ok_or_else(|| "could not derive the assembly name from `--output`".to_string())
}

/// Object directory for the intermediate RDL and per-architecture WinMDs.
fn obj_dir(options: &Options) -> PathBuf {
    options.obj.clone().unwrap_or_else(|| {
        options
            .output
            .as_ref()
            .or(options.extraction_coverage.as_ref())
            .expect("validated by `validate`")
            .parent()
            .unwrap_or_else(|| Path::new("."))
            .to_path_buf()
    })
}

/// Resolves every path option against the current directory up front.
fn absolutize(options: &mut Options) -> Result<(), String> {
    fn one(path: &mut PathBuf) -> Result<(), String> {
        *path = std::path::absolute(&*path)
            .map_err(|error| format!("failed to resolve `{}`: {error}", path.display()))?;
        Ok(())
    }

    options.partitions.iter_mut().try_for_each(one)?;
    options.partition_roots.iter_mut().try_for_each(one)?;
    if let Some(path) = &mut options.partition_policy_root {
        one(path)?;
    }
    options.includes.iter_mut().try_for_each(one)?;
    options.libs.iter_mut().try_for_each(one)?;
    for path in [
        options.namespace_routes.as_mut(),
        options.extraction_coverage.as_mut(),
        options.output.as_mut(),
        options.obj.as_mut(),
    ]
    .into_iter()
    .flatten()
    {
        one(path)?;
    }
    expand_partition_roots(options)?;
    Ok(())
}

fn expand_partition_roots(options: &mut Options) -> Result<(), String> {
    for root in &options.partition_roots {
        if !root.is_dir() {
            return Err(format!(
                "`--partition-root {}` is not a directory",
                root.display()
            ));
        }

        let mut partitions = std::fs::read_dir(root)
            .map_err(|error| format!("failed to read `{}`: {error}", root.display()))?
            .filter_map(Result::ok)
            .map(|entry| entry.path().join("main.cpp"))
            .filter(|path| path.is_file())
            .collect::<Vec<_>>();
        partitions.sort();
        if partitions.is_empty() {
            return Err(format!(
                "`--partition-root {}` contains no immediate partition directories with main.cpp",
                root.display()
            ));
        }
        options.partitions.extend(partitions);
    }
    Ok(())
}

/// Expands an SDK include root into its canonical SDK subdirectories.
///
/// A directory with none of them - a repository-local header directory, for example - is
/// used as-is, so both kinds of root are named the same way on the command line.
fn include_dirs(options: &Options) -> Result<Vec<PathBuf>, String> {
    let mut dirs = Vec::new();

    for include in &options.includes {
        if !include.is_dir() {
            return Err(format!(
                "`--include {}` is not a directory",
                include.display()
            ));
        }

        let expanded: Vec<PathBuf> = SDK_INCLUDE_SUBDIRS
            .iter()
            .map(|segments| {
                segments
                    .iter()
                    .fold(include.clone(), |path, segment| path.join(segment))
            })
            .filter(|path| path.is_dir())
            .collect();

        if expanded.is_empty() {
            dirs.push(include.clone());
        } else {
            dirs.extend(expanded);
        }
    }

    Ok(dirs)
}

/// Expands import-library directories into their `.lib` files, in a deterministic order.
///
/// Symbol -> DLL resolution is first-wins, so a directory is sorted by name and a file named
/// directly on the command line keeps its position.
fn lib_files(options: &Options) -> Result<Vec<PathBuf>, String> {
    if options.win32_sdk {
        if options.libs.is_empty() {
            return Err("`--win32-sdk` requires an SDK import-library directory".to_string());
        }

        return crate::win32_headers::IMPORT_LIBS
            .iter()
            .map(|name| {
                options
                    .libs
                    .iter()
                    .find_map(|path| {
                        if path.is_dir() {
                            let candidate = path.join(name);
                            candidate.is_file().then_some(candidate)
                        } else if path.is_file()
                            && path
                                .file_name()
                                .is_some_and(|file| file.eq_ignore_ascii_case(name))
                        {
                            Some(path.clone())
                        } else {
                            None
                        }
                    })
                    .ok_or_else(|| {
                        format!(
                            "pinned producer import library `{name}` was not found in any `--lib` location"
                        )
                    })
            })
            .collect();
    }

    let mut files = Vec::new();

    for lib in &options.libs {
        if lib.is_file() {
            files.push(lib.clone());
            continue;
        }
        if !lib.is_dir() {
            return Err(format!(
                "`--lib {}` is not a file or directory",
                lib.display()
            ));
        }

        let mut found: Vec<PathBuf> = std::fs::read_dir(lib)
            .map_err(|error| format!("failed to read `{}`: {error}", lib.display()))?
            .filter_map(Result::ok)
            .map(|entry| entry.path())
            .filter(|path| {
                path.is_file()
                    && path
                        .extension()
                        .is_some_and(|ext| ext.eq_ignore_ascii_case("lib"))
            })
            .collect();
        found.sort();

        if found.is_empty() {
            return Err(format!(
                "`--lib {}` contains no `.lib` files",
                lib.display()
            ));
        }
        files.extend(found);
    }

    Ok(files)
}

/// libclang only accepts UTF-8 paths; normalize separators so includes resolve.
fn path_arg(path: &Path, option: &str) -> Result<String, String> {
    path.to_str()
        .map(|value| value.replace('\\', "/"))
        .ok_or_else(|| format!("`{option}` path is not valid Unicode: {}", path.display()))
}

struct ScrapeConfiguration {
    inputs: ScrapeInputs,
    logical_partitions: Option<LogicalPartitionConfiguration>,
    namespace_routes: Option<crate::namespace_routes::NamespaceRoutes>,
    args: Vec<String>,
    libraries: LibraryMap,
    references: MetadataReferences,
    exclusions: MetadataReferences,
    annotation_header: String,
    sal_header: String,
    has_import_libraries: bool,
}

struct LogicalPartitionConfiguration {
    traversal: crate::partition::TraversalPolicy,
    headers: HeaderPartitionPolicy,
    coverage_roots: Vec<CoverageRoot>,
}

#[derive(Clone, Debug, Eq, PartialEq)]
struct CoverageRoot {
    configured: String,
    label: String,
}

#[derive(Clone)]
enum ScrapeInputs {
    Common(Vec<Input>),
    Partitioned(Vec<PartitionedInput>),
}

impl ScrapeInputs {
    fn len(&self) -> usize {
        match self {
            Self::Common(inputs) => inputs.len(),
            Self::Partitioned(inputs) => inputs.len(),
        }
    }

    fn extract(&self, args: &[&str]) -> Result<windows_clang::Snapshot, windows_clang::Error> {
        match self {
            Self::Common(inputs) => windows_clang::extract(inputs.clone(), args),
            Self::Partitioned(inputs) => windows_clang::extract_partitioned(inputs.clone(), args),
        }
    }

    fn partitioned(&self) -> bool {
        matches!(self, Self::Partitioned(_))
    }
}

#[derive(Default)]
struct LibraryMap(HashMap<String, String>);

impl LibraryMap {
    fn import_library(&mut self, path: &Path) -> Result<(), String> {
        let bytes = std::fs::read(path)
            .map_err(|error| format!("failed to read `{}`: {error}", path.display()))?;
        for import in windows_rdl::implib::read(&bytes).map_err(|error| error.to_string())? {
            self.0.entry(import.symbol).or_insert(import.dll);
        }
        Ok(())
    }

    fn resolved_library(&self, symbol: &str) -> Option<&str> {
        self.0.get(symbol).map(String::as_str)
    }

    fn set_library(&mut self, symbol: &str, library: &str) {
        self.0.insert(symbol.to_string(), library.to_string());
    }
}

fn apply_library_overrides(libraries: &mut LibraryMap) -> Result<(), String> {
    for entry in crate::win32_headers::LIBRARY_OVERRIDES {
        let actual = libraries.resolved_library(entry.symbol);
        if actual != entry.sdk_library {
            return Err(format!(
                "SDK library mapping for `{}` changed: expected {:?}, found {:?}",
                entry.symbol, entry.sdk_library, actual
            ));
        }
    }
    for entry in crate::win32_headers::LIBRARY_OVERRIDES {
        libraries.set_library(entry.symbol, entry.corrected_library);
    }
    Ok(())
}

fn build_configuration(options: &Options) -> Result<ScrapeConfiguration, String> {
    let include_dirs = include_dirs(options)?;
    let required_header = |name: &str| {
        include_dirs
            .iter()
            .map(|directory| directory.join(name))
            .find(|path| path.is_file())
            .ok_or_else(|| format!("`{name}` was not found in any `--include` directory"))
            .and_then(|path| path_arg(&path, "--include"))
    };
    let annotation_header = required_header(ANNOTATION_HEADER)?;
    let sal_header = required_header(SAL_HEADER)?;

    let root_dirs = include_dirs
        .iter()
        .filter(|directory| {
            directory
                .file_name()
                .and_then(|name| name.to_str())
                .is_some_and(|name| {
                    scopes(options)
                        .iter()
                        .any(|scope| name.eq_ignore_ascii_case(scope))
                })
        })
        .map(|directory| path_arg(directory, "--include"))
        .collect::<Result<Vec<_>, _>>()?;
    let logical_partitions = options
        .partition_policy_root
        .as_deref()
        .map(|root| -> Result<LogicalPartitionConfiguration, String> {
            let traversal = crate::partition::load_traversal_policy(root, &include_dirs)?;
            traversal.audit.ensure_clean()?;
            validate_aggregate_compile_environment(&traversal)?;
            let headers = convert_header_partition_policy(&traversal)?;
            let coverage_roots = coverage_roots(&traversal)?;
            Ok(LogicalPartitionConfiguration {
                traversal,
                headers,
                coverage_roots,
            })
        })
        .transpose()?;
    let inputs = build_inputs(
        options,
        &include_dirs,
        &root_dirs,
        logical_partitions.as_ref().map(|policy| &policy.traversal),
    )?;
    let namespace_routes = options
        .namespace_routes
        .as_deref()
        .map(crate::namespace_routes::NamespaceRoutes::load)
        .transpose()?;
    let mut args = CLANG_ARGS
        .iter()
        .map(|argument| argument.to_string())
        .collect::<Vec<_>>();
    args.extend(["-include".to_string(), sal_header.clone()]);
    args.extend(["-include".to_string(), annotation_header.clone()]);
    for directory in &include_dirs {
        args.extend(["-isystem".to_string(), path_arg(directory, "--include")?]);
    }

    let libs = if options.extraction_coverage.is_some() {
        Vec::new()
    } else {
        lib_files(options)?
    };
    let mut libraries = LibraryMap::default();
    for lib in &libs {
        libraries.import_library(lib)?;
    }
    if options.win32_sdk && options.extraction_coverage.is_none() {
        apply_library_overrides(&mut libraries)?;
    }

    let winrt_reference =
        || windows_metadata::reader::File::new(windows_default::WINRT.to_vec()).unwrap();
    let win32_reference =
        || windows_metadata::reader::File::new(windows_default::WIN32.to_vec()).unwrap();
    let generating_win32 = namespace(options) == DEFAULT_NAMESPACE;
    let references = if generating_win32 {
        MetadataReferences::new([winrt_reference()])
    } else {
        MetadataReferences::new([winrt_reference(), win32_reference()])
    };
    let exclusions = if generating_win32 {
        MetadataReferences::new(std::iter::empty::<windows_metadata::reader::File>())
    } else {
        MetadataReferences::new([winrt_reference(), win32_reference()])
    };

    Ok(ScrapeConfiguration {
        inputs,
        logical_partitions,
        namespace_routes,
        args,
        libraries,
        references,
        exclusions,
        annotation_header,
        sal_header,
        has_import_libraries: !libs.is_empty(),
    })
}

fn validate_aggregate_compile_environment(
    traversal: &crate::partition::TraversalPolicy,
) -> Result<(), String> {
    let actual = traversal.canonical_inventory_sha256();
    if actual != CANONICAL_AUTHORITY_SHA256 {
        return Err(format!(
            "logical partition inventory digest changed: expected {CANONICAL_AUTHORITY_SHA256}, found {actual}; classify the policy and compile-environment changes before aggregate extraction"
        ));
    }
    for exception in &traversal.compile_environment_exceptions {
        if exception
            .standard
            .as_deref()
            .is_some_and(|value| value != "c++20")
        {
            return Err(format!(
                "partition `{}` requires unsupported aggregate language standard `{}`",
                exception.partition,
                exception.standard.as_deref().unwrap()
            ));
        }
        if !exception.include_directories.is_empty() && exception.partition != "DXCore" {
            return Err(format!(
                "partition `{}` requires aggregate include-directory handling that has not been classified",
                exception.partition
            ));
        }
        for root in &exception.partition_local_roots {
            let supported = matches!(
                (exception.partition.as_str(), root.as_str()),
                ("Com.StructuredStorage", "<PartitionDir>/manual.h")
                    | ("Threading", "<PartitionDir>/main.cpp")
            );
            if !supported {
                return Err(format!(
                    "partition `{}` requires unclassified aggregate-local root `{root}`",
                    exception.partition
                ));
            }
        }
    }
    Ok(())
}

fn convert_header_partition_policy(
    traversal: &crate::partition::TraversalPolicy,
) -> Result<HeaderPartitionPolicy, String> {
    let mut result = HeaderPartitionPolicy::new();
    let satellite_roots = authority_satellite_root_keys(traversal);
    for partition in &traversal.partitions {
        let root_partition = convert_root_partition(partition);
        for root in &partition.roots {
            match root {
                crate::partition::TraversalRoot::File(root) => add_header_partition_owner(
                    &mut result,
                    logical_policy_input(&partition.identity, &root.path, &satellite_roots),
                    path_arg(&root.path, "--partition-policy-root")?,
                    root_partition.clone(),
                ),
                crate::partition::TraversalRoot::Directory(root) => {
                    for file in &root.files {
                        add_header_partition_owner(
                            &mut result,
                            logical_policy_input(&partition.identity, &file.path, &satellite_roots),
                            path_arg(&file.path, "--partition-policy-root")?,
                            root_partition.clone(),
                        );
                    }
                }
                crate::partition::TraversalRoot::Missing(_)
                | crate::partition::TraversalRoot::Unsupported(_) => {
                    unreachable!("validated traversal policy is clean")
                }
            }
        }
    }
    Ok(result)
}

fn authority_satellite_root_keys(
    traversal: &crate::partition::TraversalPolicy,
) -> BTreeSet<String> {
    let mut result = traversal
        .canonical_physical_files()
        .into_values()
        .filter(|path| crate::aggregate::is_authority_satellite_header(path))
        .map(|path| normalize_audit_path(path.to_string_lossy().as_ref()))
        .collect::<BTreeSet<_>>();
    for partition in &traversal.partitions {
        if !crate::aggregate::uses_satellite_environment(&partition.identity) {
            continue;
        }
        for root in &partition.roots {
            match root {
                crate::partition::TraversalRoot::File(root) => {
                    result.insert(normalize_audit_path(root.path.to_string_lossy().as_ref()));
                }
                crate::partition::TraversalRoot::Directory(root) => {
                    result.extend(
                        root.files
                            .iter()
                            .map(|file| normalize_audit_path(file.path.to_string_lossy().as_ref())),
                    );
                }
                crate::partition::TraversalRoot::Missing(_)
                | crate::partition::TraversalRoot::Unsupported(_) => {
                    unreachable!("validated traversal policy is clean")
                }
            }
        }
    }
    result
}

fn logical_policy_input(
    identity: &str,
    path: &Path,
    satellite_roots: &BTreeSet<String>,
) -> &'static str {
    match identity {
        "PsApi1" => PSAPI_V1_INPUT,
        "PsApi2" => PSAPI_V2_INPUT,
        _ if satellite_roots.contains(&normalize_audit_path(path.to_string_lossy().as_ref())) => {
            SATELLITE_INPUT
        }
        _ => AGGREGATE_INPUT,
    }
}

fn add_header_partition_owner(
    policy: &mut HeaderPartitionPolicy,
    input: &str,
    header: String,
    partition: RootPartition,
) {
    policy.add_traversed_header_for_input(input, header, partition);
}

fn convert_root_partition(partition: &crate::partition::LogicalPartition) -> RootPartition {
    let policy = &partition.policy;
    let mut result = RootPartition::new(partition.identity.clone(), policy.namespace.clone());
    for (source, target) in &policy.remaps {
        result = result.with_remap(source.clone(), target.clone());
    }
    for exclusion in &policy.exclusions {
        result = result.with_exclusion(exclusion.clone());
    }
    for (function, library) in &policy.libraries {
        result = result.with_library(function.clone(), library.clone());
    }
    for (name, override_type) in &policy.type_overrides {
        match override_type {
            crate::partition::TypeOverride::U32 => {
                result = result.with_u32_type(name.clone());
            }
        }
    }
    for (name, attributes) in &policy.attributes {
        for attribute in attributes {
            match attribute {
                crate::partition::ForcedAttribute::Flags => {
                    result = result.with_flags(name.clone());
                }
            }
        }
    }
    for name in &policy.preserve_auto_fnptr_level {
        result = result.with_preserved_auto_function_pointer_level(name.clone());
    }
    if policy.exclude_empty_records {
        result = result.exclude_empty_records();
    }
    result
}

fn logical_partition<'a>(
    traversal: &'a crate::partition::TraversalPolicy,
    identity: &str,
) -> Result<&'a crate::partition::LogicalPartition, String> {
    traversal
        .partitions
        .iter()
        .find(|partition| partition.identity == identity)
        .ok_or_else(|| format!("logical partition `{identity}` was not found"))
}

fn coverage_roots(
    traversal: &crate::partition::TraversalPolicy,
) -> Result<Vec<CoverageRoot>, String> {
    let mut physical = BTreeMap::new();
    for root in traversal
        .partitions
        .iter()
        .flat_map(|partition| &partition.roots)
    {
        let files = match root {
            crate::partition::TraversalRoot::File(root) => {
                vec![(&root.path, &root.canonical_path, &root.inventory_path)]
            }
            crate::partition::TraversalRoot::Directory(root) => root
                .files
                .iter()
                .map(|file| (&file.path, &file.canonical_path, &file.inventory_path))
                .collect(),
            crate::partition::TraversalRoot::Missing(_)
            | crate::partition::TraversalRoot::Unsupported(_) => {
                unreachable!("validated traversal policy is clean")
            }
        };
        for (path, identity, inventory_path) in files {
            if let Some((_, existing)) = physical.get(identity) {
                if existing != inventory_path {
                    return Err(format!(
                        "canonical traversal root `{identity}` has conflicting inventory paths `{existing}` and `{inventory_path}`"
                    ));
                }
            } else {
                physical.insert(identity.clone(), (path.clone(), inventory_path.to_string()));
            }
        }
    }
    let mut roots = physical
        .into_values()
        .map(|(path, label)| {
            Ok(CoverageRoot {
                configured: path_arg(&path, "--partition-policy-root")?,
                label,
            })
        })
        .collect::<Result<Vec<_>, String>>()?;
    roots.sort_by(|left, right| left.label.cmp(&right.label));
    if let Some(pair) = roots.windows(2).find(|pair| pair[0].label == pair[1].label) {
        return Err(format!(
            "canonical traversal roots `{}` and `{}` have the same stable coverage label `{}`",
            pair[0].configured, pair[1].configured, pair[0].label
        ));
    }
    Ok(roots)
}

fn build_inputs(
    options: &Options,
    include_dirs: &[PathBuf],
    root_dirs: &[String],
    traversal: Option<&crate::partition::TraversalPolicy>,
) -> Result<ScrapeInputs, String> {
    const PRELUDE: &str = "#define SECURITY_WIN32\n#define WIN32_NO_STATUS\n#include <winsock2.h>\n#include <windows.h>\n#undef WIN32_NO_STATUS\n#include <ntstatus.h>\n";
    const GUID_RESET: &str = "\n#undef INITGUID\n#include <guiddef.h>\n";

    fn include_name(line: &str) -> Option<&str> {
        let include = line.trim().strip_prefix("#include")?.trim();
        let closing = match include.as_bytes().first()? {
            b'<' => b'>',
            b'"' => b'"',
            _ => return None,
        };
        let end = include.as_bytes()[1..]
            .iter()
            .position(|candidate| *candidate == closing)?
            + 2;
        Some(&include[1..end - 1])
    }

    fn file_name(header: &str) -> &str {
        header.rsplit(['/', '\\']).next().unwrap()
    }

    fn resolve_header(header: &str, include_dirs: &[PathBuf]) -> Option<PathBuf> {
        include_dirs
            .iter()
            .map(|directory| directory.join(header))
            .find(|path| path.is_file())
    }

    fn resolve_partition_include_directory(
        value: &str,
        include_dirs: &[PathBuf],
    ) -> Result<String, String> {
        let normalized = value.replace('\\', "/");
        if let Some(relative) = normalized.strip_prefix("<RepoRoot>/") {
            return path_arg(
                &Path::new(env!("CARGO_MANIFEST_DIR"))
                    .join("..")
                    .join("..")
                    .join(relative),
                "--include-directory",
            );
        }
        if let Some(relative) = normalized.strip_prefix("<IncludeRoot>/") {
            let relative = relative.to_ascii_lowercase();
            return include_dirs
                .iter()
                .find(|directory| {
                    directory
                        .to_string_lossy()
                        .replace('\\', "/")
                        .to_ascii_lowercase()
                        .ends_with(&format!("/{relative}"))
                })
                .map(|directory| path_arg(directory, "--include-directory"))
                .transpose()?
                .ok_or_else(|| {
                    format!("partition include directory `{value}` was not found in SDK includes")
                });
        }
        path_arg(Path::new(value), "--include-directory")
    }

    if !options.partitions.is_empty() {
        let authority_partitions = options
            .partitions
            .iter()
            .filter(|partition| {
                partition
                    .parent()
                    .is_some_and(|directory| directory.join("settings.rsp").is_file())
            })
            .map(|partition| crate::partition::load_main(partition))
            .collect::<Result<Vec<_>, _>>()?;
        if !authority_partitions.is_empty() {
            if authority_partitions.len() != options.partitions.len() {
                return Err(
                    "partition-authority inputs with settings.rsp cannot be mixed with custom translation units"
                        .to_string(),
                );
            }
            crate::partition::validate_resolved_root_ownership(
                &authority_partitions,
                include_dirs,
            )?;
        }

        let mut common = Vec::new();
        let mut partitioned = Vec::new();
        for partition in &options.partitions {
            if partition
                .parent()
                .is_some_and(|directory| directory.join("settings.rsp").is_file())
            {
                let partition = crate::partition::load_main(partition)?;
                let resolved = partition.resolve_roots(include_dirs)?;
                let roots = resolved
                    .files
                    .iter()
                    .map(|path| path_arg(path, "--include"))
                    .collect::<Result<Vec<_>, _>>()?;
                let partition_root_dirs = resolved
                    .directories
                    .iter()
                    .map(|path| path_arg(path, "--include"))
                    .collect::<Result<Vec<_>, _>>()?;
                let input_name = partition.input_name()?;
                let policy = partition.policy()?;
                let namespace = policy.namespace;
                let identity = partition.name.clone();
                let mut root_partition = RootPartition::new(identity.clone(), namespace.clone());
                for (source, target) in policy.remaps {
                    root_partition = root_partition.with_remap(source, target);
                }
                for exclusion in policy.exclusions {
                    root_partition = root_partition.with_exclusion(exclusion);
                }
                for (function, library) in policy.libraries {
                    root_partition = root_partition.with_library(function, library);
                }
                for (name, override_type) in policy.type_overrides {
                    match override_type {
                        crate::partition::TypeOverride::U32 => {
                            root_partition = root_partition.with_u32_type(name);
                        }
                    }
                }
                for (name, attributes) in policy.attributes {
                    for attribute in attributes {
                        match attribute {
                            crate::partition::ForcedAttribute::Flags => {
                                root_partition = root_partition.with_flags(name.clone());
                            }
                        }
                    }
                }
                for name in policy.preserve_auto_fnptr_level {
                    root_partition =
                        root_partition.with_preserved_auto_function_pointer_level(name);
                }
                if policy.exclude_empty_records {
                    root_partition = root_partition.exclude_empty_records();
                }
                let standard = policy.standard;
                let include_directories = policy
                    .include_directories
                    .iter()
                    .map(|value| resolve_partition_include_directory(value, include_dirs))
                    .collect::<Result<Vec<_>, _>>()?;
                let _legacy_output = policy.legacy_output;
                let input = Input::new(input_name, partition.source)
                    .with_roots(roots)
                    .with_root_dirs(partition_root_dirs);
                let mut input = input.partitioned(identity.clone());
                if standard.as_deref() == Some("c++20") {
                    input = input.with_cpp20();
                }
                for directory in include_directories {
                    input = input.with_include_directory(directory);
                }
                let mut owner_roots = resolved.files;
                for directory in resolved.directories {
                    collect_files(&directory, &mut owner_roots)?;
                }
                owner_roots.sort();
                owner_roots.dedup();
                for root in owner_roots {
                    input = input
                        .with_root_partition(path_arg(&root, "--include")?, root_partition.clone());
                }
                partitioned.push(input);
                continue;
            }

            let source = std::fs::read_to_string(partition).map_err(|error| {
                format!(
                    "failed to read `--partition {}`: {error}",
                    partition.display()
                )
            })?;
            let roots = source
                .lines()
                .filter_map(include_name)
                .filter(|header| {
                    ![ANNOTATION_HEADER, SAL_HEADER]
                        .iter()
                        .any(|forced| file_name(header).eq_ignore_ascii_case(forced))
                })
                .filter_map(|header| resolve_header(header, include_dirs))
                .map(|path| path_arg(&path, "--include"))
                .collect::<Result<Vec<_>, _>>()?;
            common.push(
                Input::new(path_arg(partition, "--partition")?, source)
                    .with_roots(roots)
                    .with_root_dirs(root_dirs.iter().cloned())
                    .with_root_suffixes(scope_header_suffixes(options)),
            );
        }
        return match (common.is_empty(), partitioned.is_empty()) {
            (false, false) => Err(
                "partition-authority inputs with settings.rsp cannot be mixed with custom translation units"
                    .to_string(),
            ),
            (false, true) => Ok(ScrapeInputs::Common(common)),
            (true, false) => Ok(ScrapeInputs::Partitioned(partitioned)),
            (true, true) => unreachable!("validated non-empty partitions"),
        };
    }

    let headers = crate::win32_headers::HEADERS
        .iter()
        .chain(crate::win32_headers::SATELLITE_HEADERS)
        .map(|header| header.to_string())
        .collect::<Vec<_>>();

    let excluded_roots = crate::win32_headers::EXCLUDE_HEADERS
        .iter()
        .filter_map(|header| resolve_header(header, include_dirs))
        .map(|path| path_arg(&path, "--include"))
        .collect::<Result<Vec<_>, _>>()?;
    let prelude = if namespace(options) == DEFAULT_NAMESPACE {
        PRELUDE
    } else {
        ""
    };

    let has_device_topology = headers.iter().any(|header| {
        file_name(header).eq_ignore_ascii_case("devicetopology.h")
            && crate::win32_headers::SATELLITE_HEADERS
                .iter()
                .any(|candidate| file_name(header).eq_ignore_ascii_case(candidate))
    });
    let authority_satellite_roots = traversal
        .map(authority_satellite_root_keys)
        .unwrap_or_default();
    let mut main_source = if let Some(traversal) = traversal {
        let structured_storage = logical_partition(traversal, "Com.StructuredStorage")?;
        let structured_storage_header = structured_storage
            .roots
            .iter()
            .find_map(|root| match root {
                crate::partition::TraversalRoot::File(root)
                    if root.requested.replace('\\', "/")
                        == "<PartitionDir>/manual.h" =>
                {
                    Some(root)
                }
                _ => None,
            })
            .ok_or_else(|| {
                "logical partition `Com.StructuredStorage` did not contain `<PartitionDir>/manual.h`"
                    .to_string()
            })?;
        crate::aggregate::main_prefix(prelude, &structured_storage_header.path)?
    } else {
        prelude.to_string()
    };
    if has_device_topology {
        main_source.push_str("\n#include <ks.h>");
    }
    let mut satellite_source = if traversal.is_some() {
        format!(
            "{}{GUID_RESET}",
            crate::aggregate::satellite_source(prelude)
        )
    } else {
        format!("{prelude}{GUID_RESET}")
    };
    let mut main_roots = Vec::new();
    let mut satellite_roots = Vec::new();
    let mut psapi_root = None;
    let mut main_count = 0usize;
    let mut satellite_count = 0usize;
    for header in headers {
        if traversal.is_some() && file_name(&header).eq_ignore_ascii_case("psapi.h") {
            continue;
        }
        let path = resolve_header(&header, include_dirs).ok_or_else(|| {
            format!("header `{header}` was not found in any `--include` directory")
        })?;
        let root = path_arg(&path, "--include")?;
        let satellite = crate::win32_headers::SATELLITE_HEADERS
            .iter()
            .any(|candidate| file_name(&header).eq_ignore_ascii_case(candidate))
            || authority_satellite_roots
                .contains(&normalize_audit_path(path.to_string_lossy().as_ref()));
        if satellite {
            if file_name(&header).eq_ignore_ascii_case("devicetopology.h") {
                satellite_source.push_str("\n#include <ks.h>\n#define _KS_");
            }
            satellite_source.push_str(&format!("\n#include <{header}>"));
            satellite_source.push_str(GUID_RESET);
            satellite_roots.push(root);
            satellite_count += 1;
        } else {
            main_source.push_str(&format!("\n#include <{header}>"));
            main_roots.push(root);
            main_count += 1;
        }
    }
    if let Some(traversal) = traversal {
        for path in traversal.canonical_physical_files().into_values() {
            let root = path_arg(&path, "--partition-policy-root")?;
            if crate::aggregate::is_psapi_header(&path) {
                psapi_root = Some(root);
            } else if authority_satellite_roots
                .contains(&normalize_audit_path(path.to_string_lossy().as_ref()))
            {
                satellite_roots.push(root);
            } else {
                main_roots.push(root);
            }
        }
        crate::aggregate::append_threading_input(
            &mut main_source,
            &logical_partition(traversal, "Threading")?.input,
        )?;
        for roots in [&mut main_roots, &mut satellite_roots] {
            let mut unique = BTreeMap::new();
            for root in roots.drain(..) {
                unique.insert(normalize_audit_path(&root), root);
            }
            roots.extend(unique.into_values());
        }
    }

    let mut inputs = Vec::with_capacity(2);
    if main_count != 0 {
        inputs.push(
            Input::new(AGGREGATE_INPUT, main_source)
                .with_roots(main_roots)
                .with_root_dirs(root_dirs.iter().cloned())
                .with_root_suffixes(scope_header_suffixes(options))
                .with_excluded_roots(excluded_roots.iter().cloned()),
        );
    }
    if satellite_count != 0 {
        inputs.push(Input::new(SATELLITE_INPUT, satellite_source).with_roots(satellite_roots));
    }
    if traversal.is_some() {
        let psapi_root = psapi_root.ok_or_else(|| {
            "logical partition policy did not contain the shared Psapi.h root".to_string()
        })?;
        for (version, name) in [(1, PSAPI_V1_INPUT), (2, PSAPI_V2_INPUT)] {
            inputs.push(
                Input::new(name, crate::aggregate::psapi_source(prelude, version))
                    .with_roots([psapi_root.clone()]),
            );
        }
    }
    let expected_inputs = if traversal.is_some() { 4 } else { 2 };
    if inputs.len() != expected_inputs {
        return Err(format!(
            "the Win32 SDK manifest must produce {expected_inputs} input(s), but produced {}",
            inputs.len(),
        ));
    }
    Ok(ScrapeInputs::Common(inputs))
}

fn collect_files(directory: &Path, files: &mut Vec<PathBuf>) -> Result<(), String> {
    let mut entries = std::fs::read_dir(directory)
        .map_err(|error| format!("failed to read `{}`: {error}", directory.display()))?
        .map(|entry| {
            entry
                .map(|entry| entry.path())
                .map_err(|error| format!("failed to read `{}`: {error}", directory.display()))
        })
        .collect::<Result<Vec<_>, _>>()?;
    entries.sort();
    for path in entries {
        if path.is_dir() {
            collect_files(&path, files)?;
        } else if path.is_file() {
            files.push(path);
        }
    }
    Ok(())
}

fn execute(options: &Options) -> Result<(), String> {
    let provisioned = libclang::provision(None, true)?;
    println!("Using {provisioned}");

    let obj = obj_dir(options);
    let rdl_dir = obj.join("rdl");
    let arch_names = archs(options);

    let configuration = build_configuration(options)?;

    println!(
        "Scraping {} as {} translation unit(s) for {} into {}",
        configuration.logical_partitions.as_ref().map_or_else(
            || format!("{} partition(s)", options.partitions.len()),
            |policy| format!("{} logical partition(s)", policy.traversal.partitions.len())
        ),
        configuration.inputs.len(),
        arch_names.join(", "),
        rdl_dir.display()
    );
    println!(
        "Using annotation contract {} and SAL contract {}",
        configuration.annotation_header, configuration.sal_header
    );

    let resource_dir = if arch_names.len() > 1 {
        Some(libclang::clang_resource_dir(&obj)?)
    } else {
        None
    };

    let merged = std::thread::scope(|scope| {
        let handles = arch_names
            .iter()
            .enumerate()
            .map(|(index, name)| {
                let configuration = &configuration;
                let resource_dir = resource_dir.as_deref();
                let rdl_dir = &rdl_dir;
                let obj = &obj;
                scope.spawn(move || -> Result<Option<ArchInput>, String> {
                    let arch = arch(name)?;
                    let arch_rdl_dir = if index == 0 {
                        rdl_dir.clone()
                    } else {
                        obj.join(name)
                    };
                    let arch_winmd = obj.join(format!("Windows.Win32.{name}.winmd"));
                    if scrape_arch(
                        configuration,
                        &arch,
                        resource_dir,
                        &arch_rdl_dir,
                        &arch_winmd,
                        options,
                    )? {
                        return Ok(None);
                    }
                    Ok(Some(ArchInput {
                        rdl_dir: arch_rdl_dir,
                        winmd: arch_winmd,
                        bits: arch.bits,
                    }))
                })
            })
            .collect::<Vec<_>>();
        handles
            .into_iter()
            .map(|handle| {
                handle
                    .join()
                    .map_err(|_| "architecture scrape worker panicked".to_string())?
            })
            .collect::<Result<Vec<_>, String>>()
    })?
    .into_iter()
    .flatten()
    .collect::<Vec<_>>();

    if merged.is_empty() {
        if let Some(path) = &options.extraction_coverage {
            println!("Extraction coverage: {}", path.display());
        } else {
            println!("Fact audit completed before RDL planning");
        }
        return Ok(());
    }

    let output = options.output.as_ref().expect("validated by `validate`");
    if merged.len() > 1 {
        // Merge the per-architecture binaries directly, then decompile that authoritative
        // result back into the defining-header partitions for inspection and caching.
        merge_architecture_rdl(
            &merged,
            namespace(options),
            &rdl_dir,
            output,
            assembly_name(options)?,
            options.assembly_version,
        )?;
    } else {
        copy(&merged[0].winmd, output)?;
    }

    println!("RDL: {}", rdl_dir.display());
    println!("WinMD: {}", output.display());
    println!("{}", summarize(output)?);
    Ok(())
}

fn arch(name: &str) -> Result<Arch, String> {
    Arch::known(name)
        .ok_or_else(|| format!("unknown architecture `{name}`; expected x64, arm64, or x86"))
}

/// Scrapes one architecture into its own RDL directory and compiles those partitions.
fn scrape_arch(
    configuration: &ScrapeConfiguration,
    arch: &Arch,
    resource_dir: Option<&str>,
    rdl_dir: &Path,
    winmd: &Path,
    options: &Options,
) -> Result<bool, String> {
    if options.extraction_coverage.is_none() {
        clear_rdl_dir(rdl_dir)?;
    }

    let mut owned_args = configuration.args.clone();
    owned_args.push(format!("--target={}", arch.triple));
    owned_args.extend(arch.defines.iter().cloned());
    if arch.name != "x64"
        && let Some(dir) = resource_dir
    {
        owned_args.extend(["-resource-dir".to_string(), dir.to_string()]);
    }
    let args = owned_args.iter().map(String::as_str).collect::<Vec<_>>();

    let started = std::time::Instant::now();
    let snapshot = configuration
        .inputs
        .extract(&args)
        .map_err(|error| format!("failed to extract {} metadata: {error}", arch.name))?;
    println!(
        "Extracted {} facts for {} in {:.2}s",
        snapshot.facts().len(),
        arch.name,
        started.elapsed().as_secs_f32()
    );
    if let Some(path) = &options.extraction_coverage {
        let logical = configuration
            .logical_partitions
            .as_ref()
            .expect("validated extraction coverage mode");
        write_extraction_coverage(&snapshot, &logical.coverage_roots, path)?;
        return Ok(true);
    }
    if let Some(path) = std::env::var_os("WIN32METADATA_FACT_AUDIT") {
        write_fact_audit(&snapshot, &PathBuf::from(path), &arch.name)?;
        if std::env::var_os("WIN32METADATA_FACT_AUDIT_ONLY").is_some() {
            return Ok(true);
        }
    }

    if std::env::var_os("WINDOWS_CLANG_DIAGNOSTICS").is_some() {
        for (fact, reason) in snapshot.unsupported().filter(|(fact, _)| fact.root) {
            eprintln!("unsupported {}: {reason}", fact.name);
        }
    }

    let mut links_by_name = BTreeMap::<&str, BTreeSet<&str>>::new();
    for fact in snapshot.facts().iter().filter(|fact| fact.root) {
        if let FactData::Function { link_name, .. } = &fact.data {
            links_by_name
                .entry(&fact.name)
                .or_default()
                .insert(link_name);
        }
    }
    let resolve_library = |name: &str, link_name: &str| {
        configuration
            .libraries
            .resolved_library(link_name)
            .or_else(|| {
                links_by_name
                    .get(name)
                    .is_some_and(|links| links.len() == 1)
                    .then(|| configuration.libraries.resolved_library(name))
                    .flatten()
            })
    };
    let libraries = snapshot
        .facts()
        .iter()
        .filter(|fact| fact.root)
        .filter_map(|fact| {
            let FactData::Function { link_name, .. } = &fact.data else {
                return None;
            };
            resolve_library(&fact.name, link_name)
                .map(|library| (link_name.clone(), library.to_string()))
        })
        .collect::<BTreeMap<_, _>>();

    let has_import_annotation = |fact: &windows_clang::Fact| {
        snapshot
            .annotations()
            .get(&AnnotationTarget::Declaration(fact.origin.clone()))
            .is_some_and(|annotations| {
                annotations
                    .iter()
                    .any(|annotation| matches!(annotation, Annotation::ImportLibrary(_)))
            })
    };
    let requested_symbols = options
        .symbols
        .iter()
        .map(String::as_str)
        .collect::<BTreeSet<_>>();
    let selected_functions = if !requested_symbols.is_empty() {
        let mut found = BTreeSet::new();
        let mut links = BTreeSet::new();
        for fact in snapshot.facts().iter().filter(|fact| fact.root) {
            if let FactData::Function { link_name, .. } = &fact.data
                && requested_symbols.contains(fact.name.as_str())
            {
                found.insert(fact.name.as_str());
                links.insert(link_name.clone());
            }
        }
        if let Some(missing) = requested_symbols
            .iter()
            .find(|name| !found.contains(**name))
        {
            return Err(format!("selected function `{missing}` was not found"));
        }
        Some(links)
    } else if configuration.has_import_libraries {
        Some(
            snapshot
                .facts()
                .iter()
                .filter(|fact| fact.root)
                .filter_map(|fact| {
                    let FactData::Function { link_name, .. } = &fact.data else {
                        return None;
                    };
                    (libraries.contains_key(link_name) || has_import_annotation(fact))
                        .then(|| link_name.clone())
                })
                .collect(),
        )
    } else {
        None
    };

    let mut excluded_types = configuration.exclusions.excluded_types().clone();
    let mut excluded_functions = configuration.exclusions.excluded_functions().clone();
    let mut excluded_constants = configuration.exclusions.excluded_constants().clone();
    if !options.symbols.is_empty() || !options.constants.is_empty() {
        excluded_types.extend(
            snapshot
                .facts()
                .iter()
                .filter(|fact| fact.root && !matches!(fact.data, FactData::Function { .. }))
                .map(|fact| fact.name.clone()),
        );
        excluded_constants.extend(
            snapshot
                .constants()
                .iter()
                .map(|constant| constant.name.clone()),
        );
    }
    if !options.constants.is_empty() {
        excluded_functions.extend(
            snapshot
                .facts()
                .iter()
                .filter(|fact| fact.root && matches!(fact.data, FactData::Function { .. }))
                .map(|fact| fact.name.clone()),
        );
        let selected = options.constants.iter().collect::<BTreeSet<_>>();
        let found = snapshot
            .constants()
            .iter()
            .filter(|constant| selected.contains(&constant.name))
            .map(|constant| constant.name.as_str())
            .collect::<BTreeSet<_>>();
        if let Some(missing) = selected.iter().find(|name| !found.contains(name.as_str())) {
            return Err(format!("selected constant `{missing}` was not found"));
        }
        for name in &options.constants {
            excluded_constants.remove(name);
        }
    }

    let mut emit = EmitOptions::new(namespace(options), configuration.references.types());
    emit.libraries = Some(&libraries);
    emit.library = (!configuration.has_import_libraries).then_some("");
    emit.excluded_types = Some(&excluded_types);
    emit.excluded_functions = Some(&excluded_functions);
    emit.excluded_constants = Some(&excluded_constants);
    emit.functions = selected_functions.as_ref();
    if let Some(logical) = &configuration.logical_partitions {
        let authorities = configuration
            .namespace_routes
            .as_ref()
            .map(crate::namespace_routes::NamespaceRoutes::authorities)
            .unwrap_or_default();
        let partitions =
            plan_header_partitions(&snapshot, &logical.headers, &authorities, &emit, &arch.name)?;
        write_partitioned_rdl(rdl_dir, partitions)?;
    } else if configuration.inputs.partitioned() {
        let partitions = if let Some(routes) = &configuration.namespace_routes {
            snapshot.emit_partitioned_with_options_and_authorities(&emit, &routes.authorities())
        } else {
            snapshot.emit_partitioned_with_options(&emit)
        }
        .map_err(|error| format!("failed to plan {} metadata: {error}", arch.name))?;
        write_partitioned_rdl(rdl_dir, partitions)?;
    } else {
        let partitions = snapshot
            .emit_by_header_with_options(&emit)
            .map_err(|error| format!("failed to plan {} metadata: {error}", arch.name))?;
        let mut stems = BTreeSet::new();
        for (header, rdl) in partitions {
            let stem = Path::new(&header)
                .file_stem()
                .and_then(|stem| stem.to_str())
                .ok_or_else(|| format!("invalid defining header `{header}`"))?
                .to_ascii_lowercase();
            if !stems.insert(stem.clone()) {
                return Err(format!(
                    "multiple defining headers map to RDL partition `{stem}.rdl`"
                ));
            }
            std::fs::write(rdl_dir.join(format!("{stem}.rdl")), rdl)
                .map_err(|error| format!("failed to write `{stem}.rdl`: {error}"))?;
        }
    }

    compile(rdl_dir, winmd, options)?;
    Ok(false)
}

fn plan_header_partitions(
    snapshot: &windows_clang::Snapshot,
    policy: &HeaderPartitionPolicy,
    authorities: &NamespaceAuthorities,
    emit: &EmitOptions<'_>,
    arch: &str,
) -> Result<BTreeMap<RdlPartition, String>, String> {
    let plan = snapshot
        .plan_header_partitions(policy, authorities)
        .map_err(|error| format!("failed to plan {arch} metadata: {error}"))?;
    plan.emit_with_options(emit)
        .map_err(|error| format!("failed to audit {arch} metadata: {error}"))
}

fn write_partitioned_rdl(
    rdl_dir: &Path,
    partitions: BTreeMap<RdlPartition, String>,
) -> Result<(), String> {
    for (index, (partition, rdl)) in partitions.into_iter().enumerate() {
        let stem = partition
            .partition
            .chars()
            .map(|value| {
                if value.is_ascii_alphanumeric() {
                    value.to_ascii_lowercase()
                } else {
                    '_'
                }
            })
            .collect::<String>();
        let file = format!("{stem}-{index:04}.rdl");
        std::fs::write(rdl_dir.join(&file), rdl)
            .map_err(|error| format!("failed to write `{file}`: {error}"))?;
    }
    Ok(())
}

fn write_extraction_coverage(
    snapshot: &windows_clang::Snapshot,
    roots: &[CoverageRoot],
    path: &Path,
) -> Result<(), String> {
    let mut observed = BTreeSet::new();
    for fact in snapshot.facts() {
        if let Some(root) = fact_coverage_root(roots, fact) {
            observed.insert(root.label.as_str());
        }
    }

    let facts_by_origin = snapshot
        .facts()
        .iter()
        .map(|fact| (fact.origin.clone(), fact))
        .collect::<HashMap<_, _>>();
    for constant in snapshot.constants() {
        let root = facts_by_origin
            .get(&constant.root)
            .and_then(|fact| fact_coverage_root(roots, fact))
            .or_else(|| matching_coverage_root(roots, &constant.spelling.file));
        if let Some(root) = root {
            observed.insert(root.label.as_str());
        }
    }

    let report = extraction_coverage_report(roots, &observed);
    if let Some(parent) = path.parent() {
        std::fs::create_dir_all(parent)
            .map_err(|error| format!("failed to create `{}`: {error}", parent.display()))?;
    }
    std::fs::write(path, report)
        .map_err(|error| format!("failed to write `{}`: {error}", path.display()))
}

fn fact_coverage_root<'a>(
    roots: &'a [CoverageRoot],
    fact: &windows_clang::Fact,
) -> Option<&'a CoverageRoot> {
    matching_coverage_root(roots, &fact.expansion.file).or_else(|| {
        (fact.expansion.file != fact.spelling.file)
            .then(|| matching_coverage_root(roots, &fact.spelling.file))
            .flatten()
    })
}

fn matching_coverage_root<'a>(
    roots: &'a [CoverageRoot],
    extracted: &str,
) -> Option<&'a CoverageRoot> {
    let extracted = normalize_audit_path(extracted);
    if let Some(root) = roots
        .iter()
        .find(|root| normalize_audit_path(&root.configured) == extracted)
    {
        return Some(root);
    }
    let mut matches = roots
        .iter()
        .filter(|root| source_path_matches(&root.configured, &extracted));
    let root = matches.next()?;
    matches.next().is_none().then_some(root)
}

fn source_path_matches(configured: &str, extracted: &str) -> bool {
    let configured = normalize_audit_path(configured);
    let extracted = normalize_audit_path(extracted);
    configured == extracted
        || extracted
            .strip_suffix(&configured)
            .is_some_and(|prefix| prefix.ends_with('/'))
        || configured
            .strip_suffix(&extracted)
            .is_some_and(|prefix| prefix.ends_with('/'))
}

fn extraction_coverage_report(roots: &[CoverageRoot], observed: &BTreeSet<&str>) -> String {
    let unobserved = roots
        .iter()
        .filter(|root| !observed.contains(root.label.as_str()))
        .collect::<Vec<_>>();
    let mut lines = vec![
        "version\t1".to_string(),
        format!("summary\tcanonical_roots\t{}", roots.len()),
        format!(
            "summary\tobserved_roots\t{}",
            roots.len().saturating_sub(unobserved.len())
        ),
        format!("summary\tunobserved_roots\t{}", unobserved.len()),
    ];
    lines.extend(
        unobserved
            .into_iter()
            .map(|root| format!("unobserved\tuncategorized\t{}", root.label)),
    );
    lines.push(String::new());
    lines.join("\n")
}

fn write_fact_audit(
    snapshot: &windows_clang::Snapshot,
    path: &Path,
    arch: &str,
) -> Result<(), String> {
    let path = path.with_extension(format!("{arch}.tsv"));
    let roots = std::env::var_os("WIN32METADATA_FACT_AUDIT_ROOTS")
        .map(PathBuf::from)
        .map(|path| {
            std::fs::read_to_string(&path)
                .map_err(|error| format!("failed to read `{}`: {error}", path.display()))
        })
        .transpose()?
        .map(|source| {
            source
                .lines()
                .map(normalize_audit_path)
                .filter(|line| !line.is_empty())
                .collect::<Vec<_>>()
        });
    if let Some(parent) = path.parent() {
        std::fs::create_dir_all(parent)
            .map_err(|error| format!("failed to create `{}`: {error}", parent.display()))?;
    }
    let mut lines = Vec::new();
    for fact in snapshot
        .facts()
        .iter()
        .filter(|fact| roots.is_some() || fact.root)
    {
        if !audit_root_matches(&fact.spelling.file, roots.as_deref()) {
            continue;
        }
        let annotations = snapshot
            .annotations()
            .get(&AnnotationTarget::Declaration(fact.origin.clone()));
        lines.push(format!(
            "fact\t{}\t{:?}\t{}\t{:?}\t{:?}",
            fact.spelling.file, fact.kind, fact.name, fact.data, annotations
        ));
    }
    for constant in snapshot.constants() {
        if !audit_root_matches(&constant.spelling.file, roots.as_deref()) {
            continue;
        }
        lines.push(format!(
            "constant\t{}\tConstant\t{}\t{:?}\t{:?}",
            constant.spelling.file, constant.name, constant.ty, constant.value
        ));
    }
    lines.sort();
    std::fs::write(&path, lines.join("\n"))
        .map_err(|error| format!("failed to write `{}`: {error}", path.display()))
}

fn normalize_audit_path(path: &str) -> String {
    path.trim()
        .replace('\\', "/")
        .trim_start_matches('/')
        .to_ascii_lowercase()
}

fn audit_root_matches(path: &str, roots: Option<&[String]>) -> bool {
    roots.is_none_or(|roots| {
        let path = normalize_audit_path(path);
        roots
            .iter()
            .any(|root| path == *root || path.ends_with(&format!("/{root}")))
    })
}

/// Compiles a directory of RDL partitions into a WinMD.
///
/// Emit the metadata-only pseudo-attribute vocabulary into the output while the bundled
/// references resolve framework and external Win32 types used by generated declarations.
fn compile(rdl_dir: &Path, winmd: &Path, options: &Options) -> Result<(), String> {
    compile_inputs(
        &[rdl_dir.to_path_buf()],
        &[],
        assembly_name(options)?,
        options.assembly_version,
        winmd,
    )
}

fn copy(from: &Path, to: &Path) -> Result<(), String> {
    if let Some(parent) = to.parent() {
        std::fs::create_dir_all(parent)
            .map_err(|error| format!("failed to create `{}`: {error}", parent.display()))?;
    }
    std::fs::copy(from, to)
        .map(|_| ())
        .map_err(|error| format!("failed to write `{}`: {error}", to.display()))
}

/// Removes stale partitions so a rerun cannot leave output from a previous scrape behind.
fn clear_rdl_dir(rdl_dir: &Path) -> Result<(), String> {
    std::fs::create_dir_all(rdl_dir)
        .map_err(|error| format!("failed to create `{}`: {error}", rdl_dir.display()))?;

    for entry in std::fs::read_dir(rdl_dir)
        .map_err(|error| format!("failed to read `{}`: {error}", rdl_dir.display()))?
    {
        let path = entry
            .map_err(|error| format!("failed to read `{}`: {error}", rdl_dir.display()))?
            .path();
        if path.extension().is_some_and(|ext| ext == "rdl") {
            std::fs::remove_file(&path)
                .map_err(|error| format!("failed to remove `{}`: {error}", path.display()))?;
        }
    }
    Ok(())
}

/// Reads the emitted WinMD back so a run reports what it actually produced.
fn summarize(winmd: &Path) -> Result<String, String> {
    let index = Index::read(winmd).ok_or_else(|| {
        format!(
            "`{}` was written but could not be read back as metadata",
            winmd.display()
        )
    })?;

    let mut namespaces = BTreeSet::new();
    let mut counts = [0usize; 3];
    for (namespace, _, item) in index.iter_items() {
        namespaces.insert(namespace);
        match item {
            Item::Type(_) => counts[0] += 1,
            Item::Fn(_) => counts[1] += 1,
            Item::Const(_) => counts[2] += 1,
        }
    }

    Ok(format!(
        "Metadata: {} namespace(s), {} type(s), {} function(s), {} constant(s)",
        namespaces.len(),
        counts[0],
        counts[1],
        counts[2]
    ))
}

pub fn help_text() -> &'static str {
    "Usage:
  win32metadata-tools scrape \\
    [--partition <main.cpp>]... \\
    [--partition-root <dir>]... \\
    [--partition-policy-root <dir>] \\
    --include <dir>... \\
    [--lib <dir-or-file>]... \\
    [--arch <x64|arm64|x86>]... \\
    [--scope <path-segment>]... \\
    [--scope-header <header>]... \
    [--namespace-routes <routes.rsp>] \\
    [--symbol <name>]... \\
    [--constant <name>]... \\
    [--win32-sdk] \\
    [--namespace <root>] \\
    [--assembly-name <name>] \\
    [--assembly-version <A.B.C.D>] \\
    [--extraction-coverage <report.tsv> | --output <output.winmd>] \\
    [--obj <dir>]

  --partition   Partition translation unit to scrape. Repeatable.
  --partition-root
                Directory whose immediate child directories contain partition main.cpp
                translation units. Repeatable.
  --partition-policy-root
                Directory of logical WinSDK partitions whose settings.rsp traversal policy
                routes one aggregate + satellite extraction plus the two required PSAPI
                variants. Requires --win32-sdk and cannot be combined with focused inputs.
  --include     Header root. An SDK root is expanded into its shared/um/um\\cpdk/ucrt/winrt
                subdirectories; any other directory is used as-is. Repeatable.
  --lib         SDK import-library directory or file, read for symbol -> DLL mappings.
                Repeatable. Without it, functions carry no import library.
  --arch        Architecture to scrape. Repeatable. Defaults to x64. The first is
                canonical; the rest are merged into it.
  --scope       Header path segment whose declarations are emitted unconditionally.
                Repeatable. Defaults to shared and um.
  --scope-header
                Header stem whose declarations are emitted unconditionally. Repeatable.
  --namespace-routes
                Strict native-name to namespace routes for partitioned Windows SDK emission.
  --symbol      Exact source function to emit. Repeatable. When present, functions not
                named here and unrelated declarations are omitted.
  --constant    Exact source-owned loose constant to emit. Repeatable. When present,
                functions, types, and unselected constants are omitted.
  --win32-sdk   Use the pinned producer's aggregate + satellite Windows SDK header
                manifest instead of partition translation units.
  --namespace   Root namespace for emitted declarations. Defaults to Windows.Win32.
  --assembly-name
                Output assembly name. Defaults to the --output file stem.
  --assembly-version
                Four-part numeric output assembly version. Defaults to 255.255.255.255.
  --extraction-coverage
                Write a deterministic x64 canonical-root provenance report and stop after
                extraction, without import libraries, RDL planning, or WinMD compilation.
  --output      WinMD to write.
  --obj         Intermediate directory for the generated RDL and per-architecture
                WinMDs. Defaults to the directory of --output.

Without --partition-policy-root, declarations are partitioned by defining header. Logical
partition authority is read directly from checked-in settings.rsp files; there are no generated
RSP, JSON, or extraction-checkpoint inputs."
}

#[cfg(test)]
mod tests {
    use super::*;
    use std::sync::OnceLock;

    fn parse_args(args: &[&str]) -> Result<Options, String> {
        parse(Args::new(args.iter().map(OsString::from).collect()))
    }

    fn minimal() -> Vec<&'static str> {
        vec![
            "--partition",
            "Partitions/Foundation/main.cpp",
            "--include",
            "RecompiledIdlHeaders",
            "--output",
            "obj/Windows.Win32.winmd",
        ]
    }

    fn parse_with(extra: &[&str]) -> Result<Options, String> {
        let mut args = minimal();
        args.extend_from_slice(extra);
        parse_args(&args)
    }

    fn authority_args() -> Vec<&'static str> {
        vec![
            "--win32-sdk",
            "--partition-policy-root",
            "Partitions",
            "--include",
            "RecompiledIdlHeaders",
            "--output",
            "obj/Windows.Win32.winmd",
        ]
    }

    fn checked_in_win_sdk() -> PathBuf {
        Path::new(env!("CARGO_MANIFEST_DIR"))
            .join("..")
            .join("..")
            .join("generation")
            .join("WinSDK")
    }

    fn checked_in_include_dirs(win_sdk: &Path) -> Vec<PathBuf> {
        let recompiled = win_sdk.join("RecompiledIdlHeaders");
        vec![
            recompiled.join("shared"),
            recompiled.join("um"),
            recompiled.join("ucrt"),
            recompiled.join("winrt"),
            win_sdk.join("AdditionalHeaders").join("cpdk"),
            win_sdk.join("AdditionalHeaders"),
            win_sdk.join("Partitions").join("Com.StructuredStorage"),
            win_sdk.join("inc"),
        ]
    }

    fn checked_in_traversal_policy() -> crate::partition::TraversalPolicy {
        let win_sdk = checked_in_win_sdk();
        crate::partition::load_traversal_policy(
            &win_sdk.join("Partitions"),
            &checked_in_include_dirs(&win_sdk),
        )
        .unwrap()
    }

    fn ensure_libclang() {
        static LIBCLANG: OnceLock<Result<(), String>> = OnceLock::new();
        LIBCLANG
            .get_or_init(|| libclang::provision(None, true).map(|_| ()))
            .as_ref()
            .unwrap();
    }

    fn scratch(name: &str) -> PathBuf {
        let path =
            std::env::temp_dir().join(format!("win32metadata-tools-{name}-{}", std::process::id()));
        std::fs::remove_dir_all(&path).ok();
        std::fs::create_dir_all(&path).unwrap();
        path
    }

    fn aggregate_snapshot(root: &Path, headers: &[&Path]) -> windows_clang::Snapshot {
        ensure_libclang();
        let source = headers
            .iter()
            .map(|header| format!("#include \"{}\"\n", header.to_string_lossy()))
            .collect::<String>();
        windows_clang::extract(
            [Input::new("aggregate.cpp", source)
                .with_root_dirs([path_arg(root, "--include").unwrap()])],
            &["-x", "c++", "--target=x86_64-pc-windows-msvc"],
        )
        .unwrap()
    }

    #[test]
    fn minimal_command_line_parses() {
        let options = parse_with(&[]).unwrap();
        assert_eq!(options.partitions.len(), 1);
        assert_eq!(options.includes.len(), 1);
        assert!(options.libs.is_empty());
        assert_eq!(archs(&options), vec!["x64".to_string()]);
        assert_eq!(scopes(&options), vec!["shared", "um"]);
        assert_eq!(namespace(&options), "Windows.Win32");
        assert_eq!(assembly_name(&options).unwrap(), "Windows.Win32");
    }

    #[test]
    fn partitions_are_required() {
        let error = parse_args(&["--include", "inc", "--output", "obj/out.winmd"]).unwrap_err();
        assert!(error.contains("--partition"), "{error}");
    }

    #[test]
    fn partition_roots_satisfy_required_input() {
        let options = parse_args(&[
            "--partition-root",
            "Partitions",
            "--include",
            "inc",
            "--output",
            "obj/out.winmd",
        ])
        .unwrap();
        assert_eq!(options.partition_roots, vec![PathBuf::from("Partitions")]);
    }

    #[test]
    fn aggregate_partition_policy_mode_parses_without_partitioned_inputs() {
        let options = parse_args(&authority_args()).unwrap();
        assert!(options.win32_sdk);
        assert_eq!(
            options.partition_policy_root,
            Some(PathBuf::from("Partitions"))
        );
        assert!(options.partitions.is_empty());
        assert!(options.partition_roots.is_empty());
    }

    #[test]
    fn aggregate_partition_policy_mode_validates_mutual_exclusions() {
        let error = parse_args(&[
            "--partition-policy-root",
            "Partitions",
            "--include",
            "inc",
            "--output",
            "obj/out.winmd",
        ])
        .unwrap_err();
        assert!(error.contains("requires `--win32-sdk`"), "{error}");

        let mut args = authority_args();
        args.extend(["--partition", "Partitions/Foundation/main.cpp"]);
        let error = parse_args(&args).unwrap_err();
        assert!(error.contains("cannot be combined"), "{error}");

        let mut args = authority_args();
        args.extend(["--namespace", "Contoso.Api"]);
        let error = parse_args(&args).unwrap_err();
        assert!(error.contains("Windows.Win32"), "{error}");
    }

    #[test]
    fn extraction_coverage_is_x64_authority_only_and_has_no_winmd_output() {
        let options = parse_args(&[
            "--win32-sdk",
            "--partition-policy-root",
            "Partitions",
            "--include",
            "inc",
            "--extraction-coverage",
            "obj/coverage.tsv",
        ])
        .unwrap();
        assert_eq!(
            options.extraction_coverage,
            Some(PathBuf::from("obj/coverage.tsv"))
        );
        assert!(options.output.is_none());
        assert_eq!(archs(&options), ["x64".to_string()]);
        assert!(options.libs.is_empty());

        let error = parse_args(&[
            "--win32-sdk",
            "--include",
            "inc",
            "--extraction-coverage",
            "obj/coverage.tsv",
        ])
        .unwrap_err();
        assert!(
            error.contains("requires `--partition-policy-root`"),
            "{error}"
        );

        let error = parse_args(&[
            "--win32-sdk",
            "--partition-policy-root",
            "Partitions",
            "--include",
            "inc",
            "--arch",
            "arm64",
            "--extraction-coverage",
            "obj/coverage.tsv",
        ])
        .unwrap_err();
        assert!(error.contains("exactly `--arch x64`"), "{error}");

        let mut args = authority_args();
        args.extend(["--extraction-coverage", "obj/coverage.tsv"]);
        let error = parse_args(&args).unwrap_err();
        assert!(
            error.contains("cannot be combined with `--output`"),
            "{error}"
        );

        let error = parse_args(&[
            "--win32-sdk",
            "--partition-policy-root",
            "Partitions",
            "--include",
            "inc",
            "--lib",
            "um/x64",
            "--extraction-coverage",
            "obj/coverage.tsv",
        ])
        .unwrap_err();
        assert!(error.contains("import libraries"), "{error}");
    }

    #[test]
    fn namespace_routes_are_typed_path_input() {
        let options =
            parse_with(&["--namespace-routes", "requiredNamespacesForNames.rsp"]).unwrap();
        assert_eq!(
            options.namespace_routes,
            Some(PathBuf::from("requiredNamespacesForNames.rsp"))
        );
    }

    #[test]
    fn namespace_routes_require_logical_or_partitioned_inputs() {
        let error = parse_args(&[
            "--win32-sdk",
            "--namespace-routes",
            "requiredNamespacesForNames.rsp",
            "--include",
            "inc",
            "--output",
            "obj/out.winmd",
        ])
        .unwrap_err();
        assert!(error.contains("--partition"), "{error}");
    }

    #[test]
    fn win32_sdk_manifest_satisfies_required_input() {
        let options = parse_args(&[
            "--win32-sdk",
            "--include",
            "inc",
            "--output",
            "obj/out.winmd",
        ])
        .unwrap();
        assert!(options.win32_sdk);
        assert!(options.partitions.is_empty());
    }

    #[test]
    fn includes_are_required() {
        let error =
            parse_args(&["--partition", "main.cpp", "--output", "obj/out.winmd"]).unwrap_err();
        assert!(error.contains("--include"), "{error}");
    }

    #[test]
    fn output_is_required() {
        let error = parse_args(&["--partition", "main.cpp", "--include", "inc"]).unwrap_err();
        assert!(error.contains("--output"), "{error}");
    }

    #[test]
    fn unknown_architectures_are_rejected() {
        let error = parse_with(&["--arch", "mips"]).unwrap_err();
        assert!(error.contains("x64, arm64, x86"), "{error}");
    }

    #[test]
    fn architectures_keep_their_order_with_the_first_canonical() {
        let options = parse_with(&["--arch", "arm64", "--arch", "x86"]).unwrap();
        assert_eq!(
            archs(&options),
            vec!["arm64".to_string(), "x86".to_string()]
        );
        assert_eq!(arch("arm64").unwrap().triple, "aarch64-pc-windows-msvc");
        assert_eq!(arch("arm64").unwrap().bits, 4);
        assert_eq!(arch("x86").unwrap().bits, 1);
    }

    #[test]
    fn obj_defaults_to_the_output_directory() {
        let options = parse_with(&[]).unwrap();
        assert_eq!(obj_dir(&options), PathBuf::from("obj"));

        let options = parse_with(&["--obj", "obj/scratch"]).unwrap();
        assert_eq!(obj_dir(&options), PathBuf::from("obj/scratch"));
    }

    #[test]
    fn sdk_roots_include_cpdk_without_flattening_other_nested_directories() {
        let root = std::env::temp_dir().join(format!(
            "win32metadata-tools-includes-{}",
            std::process::id()
        ));
        std::fs::remove_dir_all(&root).ok();
        for path in [
            root.join("shared"),
            root.join("um"),
            root.join("um").join("cpdk"),
            root.join("um").join("unrelated"),
            root.join("ucrt"),
            root.join("winrt"),
        ] {
            std::fs::create_dir_all(path).unwrap();
        }

        let options = Options {
            includes: vec![root.clone()],
            ..Default::default()
        };
        assert_eq!(
            include_dirs(&options).unwrap(),
            [
                root.join("shared"),
                root.join("um"),
                root.join("um").join("cpdk"),
                root.join("ucrt"),
                root.join("winrt"),
            ]
        );
        std::fs::remove_dir_all(root).ok();
    }

    #[test]
    fn checked_in_authority_uses_bounded_inputs_and_supplies_every_canonical_root() {
        let win_sdk = checked_in_win_sdk();
        let include_dirs = checked_in_include_dirs(&win_sdk);
        let traversal = checked_in_traversal_policy();
        let options = Options {
            win32_sdk: true,
            ..Default::default()
        };
        let root_dirs = include_dirs
            .iter()
            .filter(|path| {
                path.file_name()
                    .and_then(|name| name.to_str())
                    .is_some_and(|name| ["shared", "um"].contains(&name))
            })
            .map(|path| path_arg(path, "--include").unwrap())
            .collect::<Vec<_>>();

        let ScrapeInputs::Common(authority) =
            build_inputs(&options, &include_dirs, &root_dirs, Some(&traversal)).unwrap()
        else {
            panic!("aggregate authority unexpectedly created PartitionedInput values");
        };
        assert_eq!(authority.len(), 4);
        assert_eq!(
            authority
                .iter()
                .map(|input| input.name.as_str())
                .collect::<Vec<_>>(),
            [
                AGGREGATE_INPUT,
                SATELLITE_INPUT,
                PSAPI_V1_INPUT,
                PSAPI_V2_INPUT
            ]
        );
        assert_eq!(traversal.partitions.len(), 321);
        assert_eq!(traversal.canonical_physical_files().len(), 1559);
        assert_eq!(traversal.file_root_count(), 1570);
        assert_eq!(traversal.directory_root_count(), 0);
        let coverage = coverage_roots(&traversal).unwrap();
        assert_eq!(coverage.len(), 1559);
        let coverage_labels = coverage
            .iter()
            .map(|root| root.label.as_str())
            .collect::<BTreeSet<_>>();
        assert_eq!(coverage_labels.len(), 1559);
        assert!(coverage_labels.contains("um/psapi.h"));
        assert!(coverage_labels.contains("partition/com.structuredstorage/manual.h"));
        assert!(coverage_labels.contains("partition/threading/main.cpp"));
        let satellite_root_keys = authority_satellite_root_keys(&traversal);
        for partition in &traversal.partitions {
            for root in &partition.roots {
                let files = match root {
                    crate::partition::TraversalRoot::File(root) => vec![&root.path],
                    crate::partition::TraversalRoot::Directory(root) => {
                        root.files.iter().map(|file| &file.path).collect()
                    }
                    crate::partition::TraversalRoot::Missing(_)
                    | crate::partition::TraversalRoot::Unsupported(_) => {
                        panic!("checked-in traversal policy was not clean")
                    }
                };
                for path in files {
                    let input =
                        logical_policy_input(&partition.identity, path, &satellite_root_keys);
                    let configured = path_arg(path, "--partition-policy-root").unwrap();
                    assert!(
                        authority
                            .iter()
                            .find(|candidate| candidate.name == input)
                            .unwrap()
                            .roots
                            .contains(&configured),
                        "logical owner `{}` selected input `{input}` without root `{configured}`",
                        partition.identity
                    );
                }
            }
        }

        let mut satellite_roots = 0usize;
        for path in traversal.canonical_physical_files().into_values() {
            let root = path_arg(&path, "--partition-policy-root").unwrap();
            let supplied = authority
                .iter()
                .enumerate()
                .filter(|(_, input)| input.roots.contains(&root))
                .map(|(index, _)| index)
                .collect::<Vec<_>>();
            let psapi = crate::aggregate::is_psapi_header(&path);
            let occurrences = authority
                .iter()
                .flat_map(|input| &input.roots)
                .filter(|candidate| candidate.eq_ignore_ascii_case(&root))
                .count();
            assert_eq!(
                supplied.len(),
                if psapi { 2 } else { 1 },
                "root `{root}` used an unexpected number of inputs"
            );
            assert_eq!(
                occurrences,
                supplied.len(),
                "root `{root}` was repeated within an input"
            );
            let satellite = satellite_root_keys
                .contains(&normalize_audit_path(path.to_string_lossy().as_ref()));
            if psapi {
                assert_eq!(supplied, [2, 3], "root `{root}` used wrong PSAPI inputs");
            } else {
                assert_eq!(
                    supplied[0] == 1,
                    satellite,
                    "root `{root}` used wrong input"
                );
            }
            satellite_roots += usize::from(satellite);
        }
        assert_eq!(satellite_roots, 43);

        let ScrapeInputs::Common(normal) =
            build_inputs(&options, &include_dirs, &root_dirs, None).unwrap()
        else {
            panic!("normal SDK manifest unexpectedly created partitioned inputs");
        };
        assert_eq!(normal.len(), 2);
        assert_eq!(
            normal[0].roots.len(),
            crate::win32_headers::HEADERS.len() + 1
        );
        assert_eq!(
            normal[1].roots.len(),
            crate::win32_headers::SATELLITE_HEADERS.len() + 1
        );
        let resolve = |header: &str| {
            include_dirs
                .iter()
                .map(|directory| directory.join(header))
                .find(|path| path.is_file())
                .and_then(|path| path_arg(&path, "--include").ok())
                .unwrap()
        };
        assert!(
            normal[0]
                .roots
                .contains(&resolve(crate::win32_headers::HEADERS[0]))
        );
        assert!(
            normal[1]
                .roots
                .contains(&resolve(crate::win32_headers::SATELLITE_HEADERS[0]))
        );
        assert!(
            !normal[0]
                .source
                .contains("CERT_CHAIN_PARA_HAS_EXTRA_FIELDS")
        );
        assert!(
            authority[0]
                .source
                .contains("CERT_CHAIN_PARA_HAS_EXTRA_FIELDS")
        );
        assert!(
            authority[0]
                .source
                .contains("Partitions/Com.StructuredStorage/manual.h")
        );
        assert!(
            authority[0]
                .source
                .contains("Partitions/Threading/main.cpp")
        );
        assert!(
            authority[2]
                .source
                .contains("#define PSAPI_VERSION 1\n#include <psapi.h>")
        );
        assert!(
            authority[3]
                .source
                .contains("#define PSAPI_VERSION 2\n#include <psapi.h>")
        );
    }

    #[test]
    fn checked_in_authority_compile_sources_parse_collision_groups() {
        ensure_libclang();
        let win_sdk = checked_in_win_sdk();
        let include_dirs = checked_in_include_dirs(&win_sdk);
        let prelude = "#define SECURITY_WIN32\n#define WIN32_NO_STATUS\n#include <winsock2.h>\n#include <windows.h>\n#undef WIN32_NO_STATUS\n#include <ntstatus.h>\n";
        let mut main_source = crate::aggregate::main_prefix(
            prelude,
            &win_sdk
                .join("Partitions")
                .join("Com.StructuredStorage")
                .join("manual.h"),
        )
        .unwrap();
        crate::aggregate::append_threading_input(
            &mut main_source,
            &win_sdk
                .join("Partitions")
                .join("Threading")
                .join("main.cpp"),
        )
        .unwrap();
        let mut satellite_source = crate::aggregate::satellite_source(prelude);
        satellite_source.push_str("\n#include <vfw.h>\n#include <xamlOM.h>\n");

        let mut args = CLANG_ARGS
            .iter()
            .map(|argument| argument.to_string())
            .collect::<Vec<_>>();
        for header in [SAL_HEADER, ANNOTATION_HEADER] {
            let header = include_dirs
                .iter()
                .map(|directory| directory.join(header))
                .find(|path| path.is_file())
                .unwrap();
            args.extend([
                "-include".to_string(),
                path_arg(&header, "--include").unwrap(),
            ]);
        }
        for directory in &include_dirs {
            args.extend([
                "-isystem".to_string(),
                path_arg(directory, "--include").unwrap(),
            ]);
        }
        args.push("--target=x86_64-pc-windows-msvc".to_string());
        let args = args.iter().map(String::as_str).collect::<Vec<_>>();
        windows_clang::extract(
            [
                Input::new(AGGREGATE_INPUT, main_source),
                Input::new(SATELLITE_INPUT, satellite_source),
            ],
            &args,
        )
        .unwrap();
    }

    #[test]
    fn checked_in_logical_policy_conversion_preserves_every_owner_setting() {
        let traversal = checked_in_traversal_policy();
        let headers = convert_header_partition_policy(&traversal).unwrap();
        let satellite_root_keys = authority_satellite_root_keys(&traversal);
        assert_eq!(headers.traversed_headers().count(), 0);
        assert_eq!(headers.traversed_header_paths().count(), 1560);
        assert_eq!(
            headers
                .traversed_header_paths()
                .collect::<BTreeSet<_>>()
                .len(),
            1559
        );
        let mut expected = HeaderPartitionPolicy::new();
        for partition in &traversal.partitions {
            let owner = convert_root_partition(partition);
            let mut add = |path: &Path| {
                let header = path_arg(path, "--partition-policy-root").unwrap();
                let input = logical_policy_input(&partition.identity, path, &satellite_root_keys);
                expected.add_traversed_header_for_input(input, header, owner.clone());
            };
            for root in &partition.roots {
                match root {
                    crate::partition::TraversalRoot::File(root) => add(&root.path),
                    crate::partition::TraversalRoot::Directory(root) => {
                        for file in &root.files {
                            add(&file.path);
                        }
                    }
                    crate::partition::TraversalRoot::Missing(_)
                    | crate::partition::TraversalRoot::Unsupported(_) => {
                        panic!("checked-in traversal policy was not clean")
                    }
                }
            }
        }
        assert_eq!(headers, expected);
    }

    #[test]
    fn checked_in_psapi_variants_share_one_header_with_exact_distinct_policies() {
        let traversal = checked_in_traversal_policy();
        let v1 = logical_partition(&traversal, "PsApi1").unwrap();
        let v2 = logical_partition(&traversal, "PsApi2").unwrap();
        fn root(
            partition: &crate::partition::LogicalPartition,
        ) -> &crate::partition::ResolvedTraversalRoot {
            let [crate::partition::TraversalRoot::File(root)] = partition.roots.as_slice() else {
                panic!("{} did not have one physical file root", partition.identity);
            };
            root
        }
        let v1_root = root(v1);
        let v2_root = root(v2);
        let mut satellite_root_keys = authority_satellite_root_keys(&traversal);
        satellite_root_keys.insert(normalize_audit_path("C:/sdk/shared/ntddstor.h"));

        assert_eq!(v1_root.canonical_path, v2_root.canonical_path);
        assert!(v1_root.canonical_path.as_str().ends_with("/um/psapi.h"));
        assert_eq!(
            logical_policy_input("PsApi1", &v1_root.path, &satellite_root_keys),
            PSAPI_V1_INPUT
        );
        assert_eq!(
            logical_policy_input("PsApi2", &v2_root.path, &satellite_root_keys),
            PSAPI_V2_INPUT
        );
        assert_eq!(
            logical_policy_input(
                "Ioctl",
                Path::new("C:/sdk/shared/ntddstor.h"),
                &satellite_root_keys
            ),
            SATELLITE_INPUT
        );
        assert_eq!(
            logical_policy_input(
                "Foundation",
                Path::new("C:/sdk/um/winuser.h"),
                &satellite_root_keys
            ),
            AGGREGATE_INPUT
        );
        let psapi_version = |partition: &crate::partition::LogicalPartition| {
            partition
                .compile_environment
                .defines
                .iter()
                .find(|define| define.name == "PSAPI_VERSION")
                .map(|define| define.value.clone())
        };
        assert_eq!(psapi_version(v1), Some("1".to_string()));
        assert_eq!(psapi_version(v2), Some("2".to_string()));
        let headers = convert_header_partition_policy(&traversal).unwrap();
        let psapi = path_arg(&v1_root.path, "--partition-policy-root").unwrap();
        assert_eq!(
            headers
                .traversed_header_paths()
                .filter(|header| header.eq_ignore_ascii_case(&psapi))
                .count(),
            2
        );
        assert_eq!(v1.policy.namespace, "Windows.Win32.System.ProcessStatus");
        assert_eq!(v2.policy.namespace, v1.policy.namespace);
        assert!(v1.policy.exclusions.is_empty());
        assert_eq!(
            v2.policy.exclusions,
            BTreeSet::from([
                "PENUM_PAGE_FILE_CALLBACKA".to_string(),
                "PENUM_PAGE_FILE_CALLBACKW".to_string(),
                "_ENUM_PAGE_FILE_INFORMATION".to_string(),
                "_MODULEINFO".to_string(),
                "_PERFORMANCE_INFORMATION".to_string(),
                "_PROCESS_MEMORY_COUNTERS".to_string(),
                "_PROCESS_MEMORY_COUNTERS_EX".to_string(),
                "_PROCESS_MEMORY_COUNTERS_EX2".to_string(),
                "_PSAPI_WORKING_SET_BLOCK".to_string(),
                "_PSAPI_WORKING_SET_EX_BLOCK".to_string(),
                "_PSAPI_WORKING_SET_EX_INFORMATION".to_string(),
                "_PSAPI_WORKING_SET_INFORMATION".to_string(),
                "_PSAPI_WS_WATCH_INFORMATION".to_string(),
                "_PSAPI_WS_WATCH_INFORMATION_EX".to_string(),
            ])
        );
    }

    #[test]
    fn checked_in_compile_environment_inventory_is_fully_classified() {
        let traversal = checked_in_traversal_policy();
        assert_eq!(
            traversal.canonical_inventory_sha256(),
            CANONICAL_AUTHORITY_SHA256
        );
        assert_eq!(traversal.compile_environment_exceptions.len(), 66);
        validate_aggregate_compile_environment(&traversal).unwrap();
        assert_eq!(
            traversal
                .compile_environment_exceptions
                .iter()
                .filter(|exception| exception.standard.is_some())
                .count(),
            2
        );
        assert_eq!(
            traversal
                .compile_environment_exceptions
                .iter()
                .filter(|exception| !exception.include_directories.is_empty())
                .count(),
            1
        );
        assert_eq!(
            traversal
                .compile_environment_exceptions
                .iter()
                .flat_map(|exception| exception.partition_local_roots.iter())
                .count(),
            2
        );
        let nonordinary = traversal
            .compile_environment_exceptions
            .iter()
            .filter(|exception| exception.has_nonordinary_main_source)
            .collect::<Vec<_>>();
        assert_eq!(nonordinary.len(), 62);
    }

    #[test]
    fn aggregate_authority_rejects_unreviewed_inventory_changes() {
        let traversal = crate::partition::TraversalPolicy {
            partitions: Vec::new(),
            audit: Default::default(),
            compile_environment_exceptions: vec![crate::partition::CompileEnvironmentException {
                partition: "Future.SpecialCase".to_string(),
                standard: None,
                include_directories: Vec::new(),
                partition_local_roots: Vec::new(),
                defines: Vec::new(),
                source_sha256: String::new(),
                has_nonordinary_main_source: true,
            }],
        };
        let error = validate_aggregate_compile_environment(&traversal).unwrap_err();
        assert!(error.contains("inventory digest changed"), "{error}");
        assert!(error.contains("classify"), "{error}");
    }

    #[test]
    fn custom_translation_units_are_not_rewritten() {
        let root = std::env::temp_dir().join(format!(
            "win32metadata-tools-aggregate-inputs-{}",
            std::process::id()
        ));
        std::fs::remove_dir_all(&root).ok();
        std::fs::create_dir_all(&root).unwrap();
        let first = root.join("first.cpp");
        let second = root.join("second.cpp");
        let first_source =
            "#define FEATURE 1\n#include <first.h>\ntypedef int DIRECT_DECLARATION;\n";
        let second_source = "#define SATELLITE_HEADER <ntddstor.h>\n#include SATELLITE_HEADER\n";
        std::fs::write(&first, first_source).unwrap();
        std::fs::write(&second, second_source).unwrap();
        std::fs::write(root.join("first.h"), "#pragma once\n").unwrap();
        std::fs::write(root.join("ntddstor.h"), "#pragma once\n").unwrap();

        let options = Options {
            partitions: vec![first, second],
            ..Default::default()
        };
        let inputs = build_inputs(&options, &[root.clone()], &[], None).unwrap();
        let ScrapeInputs::Common(inputs) = inputs else {
            panic!("custom translation units unexpectedly used partition authority");
        };
        assert_eq!(inputs[0].source, first_source);
        assert_eq!(inputs[1].source, second_source);
        assert!(inputs[0].source.contains("#include <first.h>"));
        assert!(inputs[0].source.contains("DIRECT_DECLARATION"));
        assert!(inputs[1].source.contains("#include SATELLITE_HEADER"));
        std::fs::remove_dir_all(root).ok();
    }

    #[test]
    fn partition_settings_create_tagged_namespace_inputs() {
        let root = std::env::temp_dir().join(format!(
            "win32metadata-tools-partitioned-inputs-{}",
            std::process::id()
        ));
        std::fs::remove_dir_all(&root).ok();
        let partition = root.join("Test");
        let shared = root.join("sdk").join("shared");
        std::fs::create_dir_all(&partition).unwrap();
        std::fs::create_dir_all(&shared).unwrap();
        let main = partition.join("main.cpp");
        std::fs::write(&main, "typedef unsigned VALUE;\n").unwrap();
        std::fs::write(
            partition.join("settings.rsp"),
            "--exclude\nVALUE\n--remap\nOLD=NEW\n--with-librarypath\nGetValue=test.dll\n--with-type\nVALUE=uint\n--with-attribute\nVALUE=Flags\n--preserve-auto-fnptr-level\nCALLBACK\n--config\nexclude-empty-records\n--std\nc++20\n--include-directory\n<IncludeRoot>/shared\n--traverse\n<PartitionDir>/main.cpp\n--namespace\nExample.Test\n",
        )
        .unwrap();

        let options = Options {
            partitions: vec![main.clone()],
            ..Default::default()
        };
        let inputs = build_inputs(&options, &[shared.clone()], &[], None).unwrap();
        let ScrapeInputs::Partitioned(inputs) = inputs else {
            panic!("partition settings did not enable partition authority");
        };
        assert_eq!(inputs.len(), 1);
        assert_eq!(inputs[0].identity, "Test");
        let main = main.to_string_lossy().replace('\\', "/");
        assert_eq!(inputs[0].roots[&main].partition, "Test");
        assert_eq!(inputs[0].roots[&main].namespace, "Example.Test");
        assert_eq!(
            inputs[0].roots[&main].exclusions,
            BTreeSet::from(["VALUE".to_string()])
        );
        assert_eq!(inputs[0].roots[&main].remaps["OLD"], "NEW");
        assert_eq!(inputs[0].roots[&main].libraries["GetValue"], "test.dll");
        assert!(inputs[0].roots[&main].u32_types.contains("VALUE"));
        assert!(inputs[0].roots[&main].flags.contains("VALUE"));
        assert!(
            inputs[0].roots[&main]
                .preserved_auto_function_pointer_levels
                .contains("CALLBACK")
        );
        assert!(inputs[0].roots[&main].exclude_empty_records);
        assert!(inputs[0].arguments.contains(&"-std=c++20".to_string()));
        assert!(inputs[0].arguments.contains(&format!(
            "-I{}",
            shared.to_string_lossy().replace('\\', "/")
        )));
        std::fs::remove_dir_all(root).unwrap();
    }

    #[test]
    fn legacy_partitioned_extraction_and_emission_remain_unchanged() {
        ensure_libclang();
        let root = scratch("legacy-partitioned-emission");
        let partition = root.join("Test");
        std::fs::create_dir_all(&partition).unwrap();
        let main = partition.join("main.cpp");
        std::fs::write(
            &main,
            "typedef unsigned VALUE;\n\
             extern \"C\" int Keep(void);\n\
             extern \"C\" int Drop(void);\n",
        )
        .unwrap();
        std::fs::write(
            partition.join("settings.rsp"),
            "--exclude\nDrop\n--with-type\nVALUE=uint\n--traverse\n<PartitionDir>/main.cpp\n--namespace\nExample.Test\n",
        )
        .unwrap();
        let options = Options {
            partitions: vec![main],
            ..Default::default()
        };
        let inputs = build_inputs(&options, &[root.clone()], &[], None).unwrap();
        assert!(inputs.partitioned());
        let snapshot = inputs
            .extract(&["-x", "c++", "--target=x86_64-pc-windows-msvc"])
            .unwrap();
        let references = BTreeMap::new();
        let mut emit = EmitOptions::new("Example", &references);
        emit.library = Some("");
        let partitions = snapshot.emit_partitioned_with_options(&emit).unwrap();
        assert_eq!(partitions.len(), 1);
        let (partition, rdl) = partitions.first_key_value().unwrap();
        assert_eq!(partition.partition, "Test");
        assert_eq!(partition.namespace, "Example.Test");
        assert!(rdl.contains("type VALUE = u32"), "{rdl}");
        assert!(rdl.contains("fn Keep() -> i32"), "{rdl}");
        assert!(!rdl.contains("fn Drop()"), "{rdl}");
        std::fs::remove_dir_all(root).unwrap();
    }

    #[test]
    fn partition_settings_keep_duplicate_function_libraries_owner_scoped() {
        let root = std::env::temp_dir().join(format!(
            "win32metadata-tools-partitioned-libraries-{}",
            std::process::id()
        ));
        std::fs::remove_dir_all(&root).ok();
        let partitions = [("Audio", "DSOUND.dll"), ("Tbs", "tbs.dll")];
        let mut mains = Vec::new();
        for (name, library) in partitions {
            let directory = root.join(name);
            std::fs::create_dir_all(&directory).unwrap();
            let main = directory.join("main.cpp");
            std::fs::write(&main, "void GetDeviceID(void);\n").unwrap();
            std::fs::write(
                directory.join("settings.rsp"),
                format!(
                    "--with-librarypath\nGetDeviceID={library}\n--traverse\n<PartitionDir>/main.cpp\n--namespace\nExample.{name}\n"
                ),
            )
            .unwrap();
            mains.push(main);
        }

        let options = Options {
            partitions: mains,
            ..Default::default()
        };
        let ScrapeInputs::Partitioned(inputs) =
            build_inputs(&options, &[root.clone()], &[], None).unwrap()
        else {
            panic!("partition settings did not enable partition authority");
        };
        assert_eq!(inputs.len(), 2);
        for input in inputs {
            let main = input.input.name.clone();
            let expected = match input.identity.as_str() {
                "Audio" => "DSOUND.dll",
                "Tbs" => "tbs.dll",
                identity => panic!("unexpected partition `{identity}`"),
            };
            assert_eq!(input.roots[&main].libraries["GetDeviceID"], expected);
        }
        std::fs::remove_dir_all(root).unwrap();
    }

    #[test]
    fn psapi_input_qualification_routes_same_header_compile_variants() {
        ensure_libclang();
        let root = scratch("psapi-input-qualification");
        let header = root.join("psapi.h");
        std::fs::write(
            &header,
            "#if PSAPI_VERSION == 1\n\
             extern \"C\" int EnumProcesses(void);\n\
             extern \"C\" int SharedProcessStatus(void);\n\
             #elif PSAPI_VERSION == 2\n\
             extern \"C\" int K32EnumProcesses(void);\n\
             extern \"C\" int SharedProcessStatus(void);\n\
             #endif\n",
        )
        .unwrap();
        let header = path_arg(&header, "--include").unwrap();
        let source = |version| format!("#define PSAPI_VERSION {version}\n#include \"{header}\"\n");
        let satellite_roots = BTreeSet::new();
        let snapshot = windows_clang::extract(
            [
                Input::new(PSAPI_V1_INPUT, source(1)).with_roots([header.clone()]),
                Input::new(PSAPI_V2_INPUT, source(2)).with_roots([header.clone()]),
            ],
            &["-x", "c++", "--target=x86_64-pc-windows-msvc"],
        )
        .unwrap();
        let policy = HeaderPartitionPolicy::new()
            .with_traversed_header_for_input(
                logical_policy_input("PsApi1", Path::new("psapi.h"), &satellite_roots),
                header.clone(),
                RootPartition::new("PsApi1", "Windows.Win32.System.ProcessStatus"),
            )
            .with_traversed_header_for_input(
                logical_policy_input("PsApi2", Path::new("psapi.h"), &satellite_roots),
                header,
                RootPartition::new("PsApi2", "Windows.Win32.System.ProcessStatus")
                    .with_exclusion("SharedProcessStatus"),
            );
        let references = BTreeMap::new();
        let mut emit = EmitOptions::new(DEFAULT_NAMESPACE, &references);
        emit.library = Some("");
        let partitions = plan_header_partitions(
            &snapshot,
            &policy,
            &NamespaceAuthorities::new(),
            &emit,
            "x64",
        )
        .unwrap();
        let v1 = partitions
            .iter()
            .find(|(partition, _)| partition.partition == "PsApi1")
            .unwrap()
            .1;
        let v2 = partitions
            .iter()
            .find(|(partition, _)| partition.partition == "PsApi2")
            .unwrap()
            .1;
        assert!(v1.contains("fn EnumProcesses() -> i32"), "{v1}");
        assert!(v1.contains("fn SharedProcessStatus() -> i32"), "{v1}");
        assert!(!v1.contains("K32EnumProcesses"), "{v1}");
        assert!(v2.contains("fn K32EnumProcesses() -> i32"), "{v2}");
        assert!(!v2.contains("SharedProcessStatus"), "{v2}");
        assert!(!v2.contains("fn EnumProcesses()"), "{v2}");
        std::fs::remove_dir_all(root).unwrap();
    }

    #[test]
    fn checked_in_psapi_variants_emit_expected_focused_names() {
        ensure_libclang();
        let win_sdk = checked_in_win_sdk();
        let include_dirs = checked_in_include_dirs(&win_sdk);
        let traversal = checked_in_traversal_policy();
        let root_dirs = include_dirs
            .iter()
            .filter(|path| {
                path.file_name()
                    .and_then(|name| name.to_str())
                    .is_some_and(|name| ["shared", "um"].contains(&name))
            })
            .map(|path| path_arg(path, "--include").unwrap())
            .collect::<Vec<_>>();
        let options = Options {
            win32_sdk: true,
            ..Default::default()
        };
        let ScrapeInputs::Common(inputs) =
            build_inputs(&options, &include_dirs, &root_dirs, Some(&traversal)).unwrap()
        else {
            panic!("aggregate authority unexpectedly created PartitionedInput values");
        };
        let psapi_inputs = inputs
            .into_iter()
            .filter(|input| [PSAPI_V1_INPUT, PSAPI_V2_INPUT].contains(&input.name.as_str()))
            .collect::<Vec<_>>();
        assert_eq!(psapi_inputs.len(), 2);

        let mut args = CLANG_ARGS
            .iter()
            .map(|argument| argument.to_string())
            .collect::<Vec<_>>();
        for header in [SAL_HEADER, ANNOTATION_HEADER] {
            let header = include_dirs
                .iter()
                .map(|directory| directory.join(header))
                .find(|path| path.is_file())
                .unwrap();
            args.extend([
                "-include".to_string(),
                path_arg(&header, "--include").unwrap(),
            ]);
        }
        for directory in &include_dirs {
            args.extend([
                "-isystem".to_string(),
                path_arg(directory, "--include").unwrap(),
            ]);
        }
        args.push("--target=x86_64-pc-windows-msvc".to_string());
        let args = args.iter().map(String::as_str).collect::<Vec<_>>();
        let snapshot = windows_clang::extract(psapi_inputs, &args).unwrap();
        let references = BTreeMap::new();
        let selected =
            BTreeSet::from(["EnumProcesses".to_string(), "K32EnumProcesses".to_string()]);
        let mut emit = EmitOptions::new(DEFAULT_NAMESPACE, &references);
        emit.library = Some("");
        emit.functions = Some(&selected);
        let authorities = crate::namespace_routes::NamespaceRoutes::load(
            &win_sdk.join("requiredNamespacesForNames.rsp"),
        )
        .unwrap()
        .authorities();
        let partitions = plan_header_partitions(
            &snapshot,
            &convert_header_partition_policy(&traversal).unwrap(),
            &authorities,
            &emit,
            "x64",
        )
        .unwrap();
        let v1 = partitions
            .iter()
            .find(|(partition, _)| partition.partition == "PsApi1")
            .unwrap()
            .1;
        let v2 = partitions
            .iter()
            .find(|(partition, _)| partition.partition == "PsApi2")
            .unwrap()
            .1;
        assert!(v1.contains("fn EnumProcesses("), "{v1}");
        assert!(!v1.contains("K32EnumProcesses"), "{v1}");
        assert!(v2.contains("fn K32EnumProcesses("), "{v2}");
        assert!(!v2.contains("fn EnumProcesses("), "{v2}");
    }

    #[test]
    fn aggregate_plan_uses_exact_and_wildcard_authorities_and_keeps_focused_emission() {
        let root = scratch("logical-authorities");
        let shared = root.join("shared.h");
        std::fs::write(
            &shared,
            "typedef unsigned FIRST_VALUE;\n\
             typedef unsigned SECOND_VALUE;\n\
             extern \"C\" int Keep(void);\n\
             extern \"C\" int Drop(void);\n",
        )
        .unwrap();
        let snapshot = aggregate_snapshot(&root, &[&shared]);
        let first = RootPartition::new("first", "Windows.Win32.First");
        let second = RootPartition::new("second", "Windows.Win32.Second");
        let policy = HeaderPartitionPolicy::new()
            .with_traversed_header(path_arg(&shared, "--include").unwrap(), first)
            .with_traversed_header(path_arg(&shared, "--include").unwrap(), second);
        let routes = crate::namespace_routes::NamespaceRoutes::parse(
            "--requiredNamespaceForName\n\
             FIRST_*=Windows.Win32.First\n\
             SECOND_VALUE=Windows.Win32.Second\n\
             Keep=Windows.Win32.Second\n\
             Drop=Windows.Win32.Second\n",
        )
        .unwrap();
        let references = BTreeMap::new();
        let selected = BTreeSet::from(["Keep".to_string()]);
        let mut emit = EmitOptions::new(DEFAULT_NAMESPACE, &references);
        emit.library = Some("");
        emit.functions = Some(&selected);
        let partitions =
            plan_header_partitions(&snapshot, &policy, &routes.authorities(), &emit, "x64")
                .unwrap();
        let first = partitions
            .iter()
            .find(|(partition, _)| partition.namespace == "Windows.Win32.First")
            .unwrap()
            .1;
        let second = partitions
            .iter()
            .find(|(partition, _)| partition.namespace == "Windows.Win32.Second")
            .unwrap()
            .1;

        assert!(first.contains("type FIRST_VALUE = u32"), "{first}");
        assert!(second.contains("type SECOND_VALUE = u32"), "{second}");
        assert!(second.contains("fn Keep() -> i32"), "{second}");
        assert!(!second.contains("fn Drop()"), "{second}");
        std::fs::remove_dir_all(root).unwrap();
    }

    #[test]
    fn aggregate_plan_reports_every_conflict_before_emission() {
        let root = scratch("logical-audit");
        let shared = root.join("shared.h");
        std::fs::write(
            &shared,
            "typedef unsigned FIRST_CONFLICT;\n\
             typedef unsigned SECOND_CONFLICT;\n",
        )
        .unwrap();
        let snapshot = aggregate_snapshot(&root, &[&shared]);
        let policy = HeaderPartitionPolicy::new()
            .with_traversed_header(
                path_arg(&shared, "--include").unwrap(),
                RootPartition::new("first", "Windows.Win32.First"),
            )
            .with_traversed_header(
                path_arg(&shared, "--include").unwrap(),
                RootPartition::new("second", "Windows.Win32.Second"),
            );
        let references = BTreeMap::new();
        let error = plan_header_partitions(
            &snapshot,
            &policy,
            &NamespaceAuthorities::new(),
            &EmitOptions::new(DEFAULT_NAMESPACE, &references),
            "x64",
        )
        .unwrap_err();

        assert!(error.contains("found 2 conflict(s)"), "{error}");
        assert!(error.contains("FIRST_CONFLICT"), "{error}");
        assert!(error.contains("SECOND_CONFLICT"), "{error}");
        std::fs::remove_dir_all(root).unwrap();
    }

    #[test]
    fn coverage_provenance_prefers_expansion_then_spelling() {
        let root = scratch("coverage-provenance");
        let macros = root.join("macros.h");
        let public = root.join("public.h");
        std::fs::write(
            &macros,
            "#define DECLARE_VALUE typedef unsigned EXPANDED_VALUE\n",
        )
        .unwrap();
        std::fs::write(
            &public,
            format!(
                "#include \"{}\"\nDECLARE_VALUE;\n",
                macros.to_string_lossy()
            ),
        )
        .unwrap();
        let snapshot = aggregate_snapshot(&root, &[&public]);
        let fact = snapshot
            .facts()
            .iter()
            .find(|fact| fact.name == "EXPANDED_VALUE")
            .unwrap();
        let roots = [
            CoverageRoot {
                configured: path_arg(&macros, "--include").unwrap(),
                label: "macros.h".to_string(),
            },
            CoverageRoot {
                configured: path_arg(&public, "--include").unwrap(),
                label: "public.h".to_string(),
            },
        ];
        assert_eq!(fact_coverage_root(&roots, fact).unwrap().label, "public.h");
        std::fs::remove_dir_all(root).unwrap();
    }

    #[test]
    fn extraction_coverage_report_is_stable_and_non_failing() {
        let roots = vec![
            CoverageRoot {
                configured: "C:/sdk/shared/a.h".to_string(),
                label: "shared/a.h".to_string(),
            },
            CoverageRoot {
                configured: "C:/sdk/um/b.h".to_string(),
                label: "um/b.h".to_string(),
            },
            CoverageRoot {
                configured: "C:/sdk/um/c.h".to_string(),
                label: "um/c.h".to_string(),
            },
        ];
        let observed = BTreeSet::from(["um/b.h"]);
        let report = extraction_coverage_report(&roots, &observed);
        assert_eq!(report, extraction_coverage_report(&roots, &observed));
        assert_eq!(
            report,
            "version\t1\n\
             summary\tcanonical_roots\t3\n\
             summary\tobserved_roots\t1\n\
             summary\tunobserved_roots\t2\n\
             unobserved\tuncategorized\tshared/a.h\n\
             unobserved\tuncategorized\tum/c.h\n"
        );
    }

    #[test]
    fn fact_audit_roots_match_windows_paths_by_normalized_suffix() {
        let roots = vec!["um/audioendpoints.h".to_string()];
        assert!(audit_root_matches(
            r"C:\sdk\Include\um\AudioEndpoints.h",
            Some(&roots)
        ));
        assert!(!audit_root_matches(
            r"C:\sdk\Include\shared\AudioEndpoints.h",
            Some(&roots)
        ));
        assert!(audit_root_matches("anything.h", None));
    }

    #[test]
    fn repeated_single_valued_options_are_rejected() {
        let error = parse_with(&["--output", "other.winmd"]).unwrap_err();
        assert!(error.contains("only be specified once"), "{error}");
    }

    #[test]
    fn output_identity_and_scope_parse() {
        let options = parse_with(&[
            "--scope",
            "sample",
            "--scope-header",
            "SampleApi",
            "--symbol",
            "GetSample",
            "--symbol",
            "SetSample",
            "--namespace",
            "Contoso.Api",
            "--assembly-name",
            "Contoso.Metadata",
            "--assembly-version",
            "1.2.3.4",
        ])
        .unwrap();
        assert_eq!(scopes(&options), vec!["sample"]);
        assert_eq!(options.scope_headers, vec!["SampleApi"]);
        assert_eq!(
            scope_header_suffixes(&options).collect::<Vec<_>>(),
            vec!["SampleApi.h"]
        );
        assert_eq!(options.symbols, vec!["GetSample", "SetSample"]);
        assert_eq!(namespace(&options), "Contoso.Api");
        assert_eq!(assembly_name(&options).unwrap(), "Contoso.Metadata");
        assert_eq!(options.assembly_version, Some([1, 2, 3, 4]));
    }

    #[test]
    fn invalid_assembly_versions_are_rejected() {
        for value in ["1.2.3", "1.2.3.4.5", "1.2.x.4", "65536.2.3.4"] {
            let error = parse_with(&["--assembly-version", value]).unwrap_err();
            assert!(error.contains("expected A.B.C.D"), "{error}");
        }
    }

    #[test]
    fn symbol_and_constant_selection_are_mutually_exclusive() {
        let error =
            parse_with(&["--symbol", "GetSample", "--constant", "ERROR_SAMPLE"]).unwrap_err();
        assert!(
            error.contains("`--symbol` and `--constant` cannot be combined"),
            "{error}"
        );
    }

    #[test]
    fn repeated_constants_parse() {
        let options = parse_with(&["--constant", "ERROR_ONE", "--constant", "ERROR_TWO"]).unwrap();
        assert_eq!(options.constants, vec!["ERROR_ONE", "ERROR_TWO"]);
    }

    #[test]
    fn unknown_options_report_usage() {
        let error = parse_with(&["--unknown"]).unwrap_err();
        assert!(
            error.contains("unknown scrape option `--unknown`"),
            "{error}"
        );
    }

    #[test]
    fn help_short_circuits_validation() {
        assert!(parse_args(&["--help"]).unwrap().help);
    }

    #[test]
    fn sdk_include_roots_expand_and_other_directories_do_not() {
        let root = std::env::temp_dir().join(format!("win32md-include-{}", std::process::id()));
        let sdk = root.join("sdk");
        let plain = root.join("inc");
        for dir in ["shared", "um", "ucrt"] {
            std::fs::create_dir_all(sdk.join(dir)).unwrap();
        }
        std::fs::create_dir_all(&plain).unwrap();

        let options = Options {
            includes: vec![sdk.clone(), plain.clone()],
            ..Default::default()
        };

        assert_eq!(
            include_dirs(&options).unwrap(),
            vec![sdk.join("shared"), sdk.join("um"), sdk.join("ucrt"), plain]
        );

        std::fs::remove_dir_all(&root).ok();
    }

    #[test]
    fn missing_include_directories_are_reported() {
        let options = Options {
            includes: vec![PathBuf::from("does-not-exist-9f3a")],
            ..Default::default()
        };
        let error = include_dirs(&options).unwrap_err();
        assert!(error.contains("is not a directory"), "{error}");
    }

    #[test]
    fn lib_directories_expand_to_sorted_lib_files() {
        let root = std::env::temp_dir().join(format!("win32md-lib-{}", std::process::id()));
        std::fs::create_dir_all(&root).unwrap();
        for name in ["kernel32.lib", "advapi32.lib", "notes.txt"] {
            std::fs::write(root.join(name), b"").unwrap();
        }

        let options = Options {
            libs: vec![root.clone()],
            ..Default::default()
        };

        assert_eq!(
            lib_files(&options).unwrap(),
            vec![root.join("advapi32.lib"), root.join("kernel32.lib")]
        );

        std::fs::remove_dir_all(&root).ok();
    }
}
