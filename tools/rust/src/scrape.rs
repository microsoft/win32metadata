//! `scrape`: Windows SDK headers or focused partition inputs -> WinMD.
//!
//! The production path uses the pinned producer's aggregate + satellite header manifest.
//! Focused partition translation units remain available for package fixtures and inner-loop
//! debugging. Neither path requires RSP or JSON metadata sidecars.

use std::collections::{BTreeMap, BTreeSet, HashMap};
use std::ffi::OsString;
use std::path::{Path, PathBuf};

use windows_clang::{
    Annotation, AnnotationTarget, EmitOptions, FactData, Input, MetadataReferences,
    PartitionedInput,
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
    includes: Vec<PathBuf>,
    libs: Vec<PathBuf>,
    archs: Vec<String>,
    scopes: Vec<String>,
    scope_headers: Vec<String>,
    symbols: Vec<String>,
    constants: Vec<String>,
    win32_sdk: bool,
    namespace: Option<String>,
    assembly_name: Option<String>,
    assembly_version: Option<[u16; 4]>,
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
            "--include" => options.includes.push(args.path(&option)?),
            "--lib" => options.libs.push(args.path(&option)?),
            "--arch" => options.archs.push(args.value(&option)?),
            "--scope" => options.scopes.push(args.value(&option)?),
            "--scope-header" => options.scope_headers.push(args.value(&option)?),
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
    if !options.win32_sdk && options.partitions.is_empty() && options.partition_roots.is_empty() {
        return Err(
            "at least one `--partition <main.cpp>`, `--partition-root <dir>`, or `--win32-sdk` is required"
                .to_string(),
        );
    }
    if options.includes.is_empty() {
        return Err("at least one `--include <dir>` is required".to_string());
    }
    required(options.output.as_ref(), "--output")?;

    if !options.symbols.is_empty() && !options.constants.is_empty() {
        return Err("`--symbol` and `--constant` cannot be combined".to_string());
    }

    for name in &options.archs {
        if Arch::known(name).is_none() {
            return Err(format!(
                "unknown `--arch {name}`; supported architectures are x64, arm64, x86"
            ));
        }
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
    let output = options.output.as_ref().expect("validated by `validate`");
    options.obj.clone().unwrap_or_else(|| {
        output
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
    options.includes.iter_mut().try_for_each(one)?;
    options.libs.iter_mut().try_for_each(one)?;
    for path in [options.output.as_mut(), options.obj.as_mut()]
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
    args: Vec<String>,
    libraries: LibraryMap,
    references: MetadataReferences,
    exclusions: MetadataReferences,
    annotation_header: String,
    sal_header: String,
    has_import_libraries: bool,
    partition_exclusions: BTreeSet<String>,
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
    let inputs = build_inputs(options, &include_dirs, &root_dirs)?;
    let partition_exclusions = partition_setting_values(options, "--exclude")?;

    let mut args = CLANG_ARGS
        .iter()
        .map(|argument| argument.to_string())
        .collect::<Vec<_>>();
    args.extend(["-include".to_string(), sal_header.clone()]);
    args.extend(["-include".to_string(), annotation_header.clone()]);
    for directory in &include_dirs {
        args.extend(["-isystem".to_string(), path_arg(directory, "--include")?]);
    }

    let libs = lib_files(options)?;
    let mut libraries = LibraryMap::default();
    for lib in &libs {
        libraries.import_library(lib)?;
    }
    if options.win32_sdk {
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
        args,
        libraries,
        references,
        exclusions,
        annotation_header,
        sal_header,
        has_import_libraries: !libs.is_empty(),
        partition_exclusions,
    })
}

fn partition_setting_values(options: &Options, name: &str) -> Result<BTreeSet<String>, String> {
    let mut result = BTreeSet::new();
    for main in &options.partitions {
        if main
            .parent()
            .is_some_and(|directory| directory.join("settings.rsp").is_file())
        {
            let partition = crate::partition::load_main(main)?;
            result.extend(partition.values(name).map(str::to_string));
        }
    }
    Ok(result)
}

fn build_inputs(
    options: &Options,
    include_dirs: &[PathBuf],
    root_dirs: &[String],
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

    if !options.partitions.is_empty() {
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
                let namespace = partition.namespace()?.to_string();
                let identity = partition.name;
                let input = Input::new(input_name, partition.source)
                    .with_roots(roots)
                    .with_root_dirs(partition_root_dirs);
                let mut input = input.partitioned(identity.clone());
                let mut owner_roots = resolved.files;
                for directory in resolved.directories {
                    collect_files(&directory, &mut owner_roots)?;
                }
                owner_roots.sort();
                owner_roots.dedup();
                for root in owner_roots {
                    input = input.with_root(
                        path_arg(&root, "--include")?,
                        identity.clone(),
                        namespace.clone(),
                    );
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
    let mut main_source = prelude.to_string();
    if has_device_topology {
        main_source.push_str("\n#include <ks.h>");
    }
    let mut satellite_source = format!("{prelude}{GUID_RESET}");
    let mut main_roots = Vec::new();
    let mut satellite_roots = Vec::new();
    let mut main_count = 0usize;
    let mut satellite_count = 0usize;
    for header in headers {
        let path = resolve_header(&header, include_dirs).ok_or_else(|| {
            format!("header `{header}` was not found in any `--include` directory")
        })?;
        let root = path_arg(&path, "--include")?;
        let satellite = crate::win32_headers::SATELLITE_HEADERS
            .iter()
            .any(|candidate| file_name(&header).eq_ignore_ascii_case(candidate));
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

    let mut inputs = Vec::with_capacity(2);
    if main_count != 0 {
        inputs.push(
            Input::new("win32metadata-aggregate.cpp", main_source)
                .with_roots(main_roots)
                .with_root_dirs(root_dirs.iter().cloned())
                .with_root_suffixes(scope_header_suffixes(options))
                .with_excluded_roots(excluded_roots.iter().cloned()),
        );
    }
    if satellite_count != 0 {
        inputs.push(
            Input::new("win32metadata-satellites.cpp", satellite_source)
                .with_roots(satellite_roots),
        );
    }
    if inputs.len() != 2 {
        return Err(format!(
            "the Win32 SDK manifest must produce one aggregate and one satellite input, but produced {}",
            inputs.len()
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

    let output = options.output.as_ref().expect("validated by `validate`");
    let obj = obj_dir(options);
    let rdl_dir = obj.join("rdl");
    let arch_names = archs(options);

    let configuration = build_configuration(options)?;

    println!(
        "Scraping {} partition(s) as {} translation unit(s) for {} into {}",
        options.partitions.len(),
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
        println!("Fact audit completed before RDL planning");
        return Ok(());
    }

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
    clear_rdl_dir(rdl_dir)?;

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
    excluded_types.extend(configuration.partition_exclusions.iter().cloned());
    excluded_functions.extend(configuration.partition_exclusions.iter().cloned());
    excluded_constants.extend(configuration.partition_exclusions.iter().cloned());
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
    if configuration.inputs.partitioned() {
        let partitions = snapshot
            .emit_partitioned_with_options(&emit)
            .map_err(|error| format!("failed to plan {} metadata: {error}", arch.name))?;
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
    --partition <main.cpp>... \\
    [--partition-root <dir>]... \\
    --include <dir>... \\
    [--lib <dir-or-file>]... \\
    [--arch <x64|arm64|x86>]... \\
    [--scope <path-segment>]... \\
    [--scope-header <header>]... \
    [--symbol <name>]... \\
    [--constant <name>]... \\
    [--win32-sdk] \\
    [--namespace <root>] \\
    [--assembly-name <name>] \\
    [--assembly-version <A.B.C.D>] \\
    --output <output.winmd> \\
    [--obj <dir>]

  --partition   Partition translation unit to scrape. Repeatable.
  --partition-root
                Directory whose immediate child directories contain partition main.cpp
                translation units. Repeatable.
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
  --output      WinMD to write.
  --obj         Intermediate directory for the generated RDL and per-architecture
                WinMDs. Defaults to the directory of --output.

Declarations are partitioned by defining header. There are no RSP or JSON inputs."
}

#[cfg(test)]
mod tests {
    use super::*;

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
        let inputs = build_inputs(&options, &[root.clone()], &[]).unwrap();
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
        std::fs::create_dir_all(&partition).unwrap();
        let main = partition.join("main.cpp");
        std::fs::write(&main, "typedef unsigned VALUE;\n").unwrap();
        std::fs::write(
            partition.join("settings.rsp"),
            "--exclude\nVALUE\n--traverse\n<PartitionDir>/main.cpp\n--namespace\nExample.Test\n",
        )
        .unwrap();

        let options = Options {
            partitions: vec![main.clone()],
            ..Default::default()
        };
        let inputs = build_inputs(&options, &[root.clone()], &[]).unwrap();
        let ScrapeInputs::Partitioned(inputs) = inputs else {
            panic!("partition settings did not enable partition authority");
        };
        assert_eq!(inputs.len(), 1);
        assert_eq!(inputs[0].identity, "Test");
        let main = main.to_string_lossy().replace('\\', "/");
        assert_eq!(inputs[0].roots[&main].partition, "Test");
        assert_eq!(inputs[0].roots[&main].namespace, "Example.Test");
        assert_eq!(
            partition_setting_values(&options, "--exclude").unwrap(),
            BTreeSet::from(["VALUE".to_string()])
        );
        std::fs::remove_dir_all(root).unwrap();
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
