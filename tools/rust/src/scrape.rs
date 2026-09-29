//! `scrape`: partition `main.cpp` files -> WinMD, using windows-clang and windows-rdl.
//!
//! This is the minimal alternate pipeline. Its inputs are the existing partition translation
//! units, the SDK header roots, optionally the SDK import-library root, and the target
//! architectures. The root namespace, reachability scope, assembly identity, clang language
//! settings, and intermediate RDL have simple defaults and require no RSP or JSON sidecars.

use std::collections::{BTreeMap, BTreeSet, HashMap};
use std::ffi::OsString;
use std::path::{Path, PathBuf};

use windows_clang::{
    Annotation, AnnotationTarget, EmitOptions, FactData, Input, MetadataReferences,
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
    if options.partitions.is_empty() && options.partition_roots.is_empty() {
        return Err(
            "at least one `--partition <main.cpp>` or `--partition-root <dir>` is required"
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

/// Requested architectures, defaulting to a single x64 pass. The first is canonical: it
/// writes the RDL partitions the other architectures are merged into.
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
///
/// A multi-architecture scrape moves the process working directory (see [`execute`]) so the
/// clang resource-header cache `windows-clang` keeps at the relative path `target/windows-clang`
/// lands in the object directory instead of the repository root.
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
    inputs: Vec<Input>,
    args: Vec<String>,
    libraries: LibraryMap,
    references: MetadataReferences,
    exclusions: MetadataReferences,
    annotation_header: String,
    sal_header: String,
    has_import_libraries: bool,
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
    let inputs = build_inputs(options, &root_dirs)?;

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
    })
}

fn build_inputs(options: &Options, root_dirs: &[String]) -> Result<Vec<Input>, String> {
    const AGGREGATE_INPUTS: usize = 16;
    const PRELUDE: &str = "#define SECURITY_WIN32\n#define QCC_OS_GROUP_WINDOWS\n#define WIN32_NO_STATUS\n#include <winsock2.h>\n#include <windows.h>\n#undef WIN32_NO_STATUS\n#include <ntstatus.h>\n";
    const GUID_RESET: &str = "\n#undef INITGUID\n#include <guiddef.h>\n";
    const COMMON_DEFINES: [&str; 2] = ["#define SECURITY_WIN32", "#define QCC_OS_GROUP_WINDOWS"];
    const SATELLITE_HEADERS: [&str; 14] = [
        "ntddstor.h",
        "ntddcdrm.h",
        "ntddtape.h",
        "ntddser.h",
        "ntddkbd.h",
        "ntddmou.h",
        "usbiodef.h",
        "poclass.h",
        "batclass.h",
        "hidclass.h",
        "winternl.h",
        "endpointvolume.h",
        "devicetopology.h",
        "winioctl.h",
    ];
    const ISOLATED_HEADERS: [&str; 16] = [
        "commdlg.h",
        "ddrawint.h",
        "dvp.h",
        "exposeenums2managed.h",
        "ksmedia.h",
        "madcapcl.h",
        "mapi.h",
        "mscoree.h",
        "sdoias.h",
        "tbs.h",
        "vdshwprv.h",
        "wabdefs.h",
        "wdbgexts.h",
        "winenclave.h",
        "winsock.h",
        "xamlom.h",
    ];

    fn include_key(line: &str) -> Option<&str> {
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
        Some(&include[..end])
    }

    fn include_name(include: &str) -> &str {
        include[1..include.len() - 1]
            .rsplit(['/', '\\'])
            .next()
            .unwrap()
    }

    let mut groups = BTreeMap::<String, Vec<(PathBuf, String)>>::new();
    let mut aggregate = Vec::new();
    for partition in &options.partitions {
        let source = std::fs::read_to_string(partition).map_err(|error| {
            format!(
                "failed to read `--partition {}`: {error}",
                partition.display()
            )
        })?;
        let context = source
            .lines()
            .map(str::trim)
            .filter(|line| !line.is_empty())
            .filter(|line| !line.starts_with("//"))
            .filter(|line| !line.starts_with("#include"))
            .filter(|line| !COMMON_DEFINES.iter().any(|define| line.starts_with(define)))
            .collect::<Vec<_>>()
            .join("\n");
        let includes = source.lines().filter_map(include_key).collect::<Vec<_>>();
        let isolated = includes.iter().any(|include| {
            ISOLATED_HEADERS
                .iter()
                .any(|header| include_name(include).eq_ignore_ascii_case(header))
        });
        if context.is_empty() && !isolated {
            aggregate.push((partition.clone(), source));
            continue;
        }
        let key = if isolated {
            format!("__isolated__{}", partition.display())
        } else {
            context
        };
        groups
            .entry(key)
            .or_default()
            .push((partition.clone(), source));
    }

    let make_input = |name: String, source: String| {
        Input::new(name, source)
            .with_root_dirs(root_dirs.iter().cloned())
            .with_root_suffixes(scope_header_suffixes(options))
    };
    let prelude = if namespace(options) == DEFAULT_NAMESPACE {
        PRELUDE
    } else {
        ""
    };
    let mut inputs = Vec::with_capacity(groups.len() + AGGREGATE_INPUTS + 1);
    let mut satellite_source = format!("{prelude}{GUID_RESET}");
    let mut satellite_includes = BTreeSet::new();
    let aggregate_chunk_size = aggregate
        .len()
        .div_ceil(AGGREGATE_INPUTS)
        .max(16)
        .min(aggregate.len().max(1));
    for (chunk_index, chunk) in aggregate.chunks(aggregate_chunk_size).enumerate() {
        let mut main_source = prelude.to_string();
        let mut main_includes = BTreeSet::new();
        for (path, content) in chunk {
            main_source.push_str(&format!("\n// {}\n", path.display()));
            for line in content.lines() {
                let Some(include) = include_key(line) else {
                    continue;
                };
                let satellite = SATELLITE_HEADERS
                    .iter()
                    .any(|header| include_name(include).eq_ignore_ascii_case(header));
                if satellite {
                    if satellite_includes.insert(include.to_string()) {
                        satellite_source.push_str(line.trim());
                        satellite_source.push_str(GUID_RESET);
                    }
                } else if main_includes.insert(include.to_string()) {
                    main_source.push_str(line.trim());
                    main_source.push('\n');
                }
            }
        }
        if !main_includes.is_empty() {
            inputs.push(make_input(
                format!("win32metadata-aggregate-{chunk_index}.cpp"),
                main_source,
            ));
        }
    }
    if !satellite_includes.is_empty() {
        inputs.push(make_input(
            "win32metadata-satellites.cpp".to_string(),
            satellite_source,
        ));
    }

    for (index, (_context, sources)) in groups.into_iter().enumerate() {
        let mut source = String::new();
        let mut includes = BTreeSet::new();
        for (source_index, (path, content)) in sources.into_iter().enumerate() {
            source.push_str(&format!("\n// {}\n", path.display()));
            if source_index == 0 {
                source.push_str(&content);
                includes.extend(content.lines().filter_map(include_key).map(str::to_string));
            } else {
                for line in content.lines() {
                    if let Some(include) = include_key(line)
                        && includes.insert(include.to_string())
                    {
                        source.push_str(line.trim());
                        source.push('\n');
                    }
                }
            }
        }
        inputs.push(make_input(
            format!("win32metadata-group-{index}.cpp"),
            source,
        ));
    }
    Ok(inputs)
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

    let canonical = arch(&arch_names[0])?;
    let resource_dir = if arch_names.len() > 1 {
        Some(libclang::clang_resource_dir(&obj)?)
    } else {
        None
    };

    let mut merged = Vec::new();
    for (index, name) in arch_names.iter().enumerate() {
        let arch = arch(name)?;
        // The canonical architecture writes the RDL partitions the others merge into.
        let arch_rdl_dir = if index == 0 {
            rdl_dir.clone()
        } else {
            obj.join(name)
        };
        let arch_winmd = obj.join(format!("Windows.Win32.{name}.winmd"));

        scrape_arch(
            &configuration,
            &arch,
            resource_dir
                .as_deref()
                .filter(|_| arch.bits != canonical.bits),
            &arch_rdl_dir,
            &arch_winmd,
            options,
        )?;

        merged.push(ArchInput {
            rdl_dir: arch_rdl_dir,
            winmd: arch_winmd,
            bits: arch.bits,
        });
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
) -> Result<(), String> {
    clear_rdl_dir(rdl_dir)?;

    let mut owned_args = configuration.args.clone();
    owned_args.push(format!("--target={}", arch.triple));
    owned_args.extend(arch.defines.iter().cloned());
    if let Some(dir) = resource_dir {
        owned_args.extend(["-resource-dir".to_string(), dir.to_string()]);
    }
    let args = owned_args.iter().map(String::as_str).collect::<Vec<_>>();

    let started = std::time::Instant::now();
    let snapshot = windows_clang::extract(configuration.inputs.clone(), &args)
        .map_err(|error| format!("failed to extract {} metadata: {error}", arch.name))?;
    println!(
        "Extracted {} facts for {} in {:.2}s",
        snapshot.facts().len(),
        arch.name,
        started.elapsed().as_secs_f32()
    );

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

    compile(rdl_dir, winmd, options)
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

    let mut counts = [0usize; 3];
    for (_, _, item) in index.iter_items() {
        match item {
            Item::Type(_) => counts[0] += 1,
            Item::Fn(_) => counts[1] += 1,
            Item::Const(_) => counts[2] += 1,
        }
    }

    Ok(format!(
        "Metadata: {} type(s), {} function(s), {} constant(s)",
        counts[0], counts[1], counts[2]
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
