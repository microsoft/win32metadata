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
    "FC2A550DAEABA781521A9A6AA1FEFA5FE4E164EF6C2A173C9D052F315C4F05A7";
const WIN32_SDK_PRELUDE: &str = "#define SECURITY_WIN32\n#define WIN32_NO_STATUS\n#include <winsock2.h>\n#include <windows.h>\n#undef WIN32_NO_STATUS\n#include <ntstatus.h>\n";
const GUID_RESET: &str =
    "\n#undef INITGUID\n#include <guiddef.h>\n#include <devpropdef.h>\n#include <propkeydef.h>\n";

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
    policy_exclusions: BTreeSet<String>,
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
    owning_inputs: Vec<String>,
}

#[derive(Clone, Copy, Debug, Eq, Ord, PartialEq, PartialOrd)]
enum AuthorityInput {
    Aggregate,
    Satellite,
    PsApiV1,
    PsApiV2,
}

impl AuthorityInput {
    fn name(self) -> &'static str {
        match self {
            Self::Aggregate => AGGREGATE_INPUT,
            Self::Satellite => SATELLITE_INPUT,
            Self::PsApiV1 => PSAPI_V1_INPUT,
            Self::PsApiV2 => PSAPI_V2_INPUT,
        }
    }
}

#[derive(Clone, Copy, Debug, Eq, PartialEq)]
enum AuthorityIncludeRole {
    OwnedRoot,
    DependencyOnly,
}

#[derive(Clone, Debug, Eq, PartialEq)]
struct AuthorityIncludeSite {
    role: AuthorityIncludeRole,
    review_reason: &'static str,
}

#[derive(Clone, Debug)]
struct AuthorityPhysicalRoot {
    path: PathBuf,
    label: String,
    owned_inputs: BTreeSet<AuthorityInput>,
}

#[derive(Clone, Debug)]
struct AuthorityRootPlan {
    roots: BTreeMap<crate::partition::WindowsPathIdentity, AuthorityPhysicalRoot>,
    owner_inputs: BTreeMap<(String, crate::partition::WindowsPathIdentity), AuthorityInput>,
}

#[derive(Clone, Debug)]
struct AuthoritySourcePlan {
    roots: AuthorityRootPlan,
    sources: BTreeMap<AuthorityInput, String>,
    include_sites:
        BTreeMap<(crate::partition::WindowsPathIdentity, AuthorityInput), AuthorityIncludeSite>,
}

#[derive(Clone, Copy)]
struct SharedRootOwnerInput {
    path: &'static str,
    partition: &'static str,
    input: AuthorityInput,
}

// Keep the seven non-PSAPI overlap decisions isolated until the grouped legacy-owner
// audit can update this exact surface.
const SHARED_ROOT_OWNER_INPUTS: &[SharedRootOwnerInput] = &[
    SharedRootOwnerInput {
        path: "shared/ntddstor.h",
        partition: "Ioctl",
        input: AuthorityInput::Satellite,
    },
    SharedRootOwnerInput {
        path: "shared/uuids.h",
        partition: "Mf",
        input: AuthorityInput::Aggregate,
    },
    SharedRootOwnerInput {
        path: "um/audioendpoints.h",
        partition: "Audio",
        input: AuthorityInput::Satellite,
    },
    SharedRootOwnerInput {
        path: "um/audioendpoints.h",
        partition: "Audio.Endpoints",
        input: AuthorityInput::Satellite,
    },
    SharedRootOwnerInput {
        path: "um/dxcore.h",
        partition: "DXCore",
        input: AuthorityInput::Aggregate,
    },
    SharedRootOwnerInput {
        path: "um/dxcore_interface.h",
        partition: "DXCore",
        input: AuthorityInput::Aggregate,
    },
    SharedRootOwnerInput {
        path: "um/endpointvolume.h",
        partition: "Audio",
        input: AuthorityInput::Satellite,
    },
    SharedRootOwnerInput {
        path: "um/endpointvolume.h",
        partition: "Audio.Endpoints",
        input: AuthorityInput::Satellite,
    },
    SharedRootOwnerInput {
        path: "um/idispids.h",
        partition: "InternetExplorer",
        input: AuthorityInput::Aggregate,
    },
];

struct HeaderPolicyOverrideContract {
    path: &'static str,
    default_partition: &'static str,
    overrides: &'static [(&'static str, &'static str)],
    excluded_names: &'static [&'static str],
}

const HEADER_POLICY_OVERRIDE_CONTRACTS: &[HeaderPolicyOverrideContract] = &[
    HeaderPolicyOverrideContract {
        path: "shared/ntddstor.h",
        default_partition: "Ioctl",
        overrides: &[("STORAGE_BUS_TYPE", "Fs")],
        excluded_names: &[],
    },
    HeaderPolicyOverrideContract {
        path: "um/audioendpoints.h",
        default_partition: "Audio.Endpoints",
        overrides: &[("ENDPOINT_FORMAT_RESET_MIX_ONLY", "Audio")],
        excluded_names: &[],
    },
    HeaderPolicyOverrideContract {
        path: "um/endpointvolume.h",
        default_partition: "Audio.Endpoints",
        overrides: &[
            ("AUDIO_VOLUME_NOTIFICATION_DATA", "Audio"),
            ("ENDPOINT_HARDWARE_SUPPORT_VOLUME", "Audio"),
            ("ENDPOINT_HARDWARE_SUPPORT_MUTE", "Audio"),
            ("ENDPOINT_HARDWARE_SUPPORT_METER", "Audio"),
        ],
        excluded_names: &[],
    },
    HeaderPolicyOverrideContract {
        path: "um/mmdeviceapi.h",
        default_partition: "Audio",
        overrides: &[],
        excluded_names: &["E_NOTFOUND"],
    },
    HeaderPolicyOverrideContract {
        path: "um/devicetopology.h",
        default_partition: "Audio",
        overrides: &[],
        excluded_names: &["E_NOTFOUND"],
    },
    HeaderPolicyOverrideContract {
        path: "um/xamlOM.h",
        default_partition: "Xaml_Diagnostics",
        overrides: &[],
        excluded_names: &["E_NOTFOUND"],
    },
    HeaderPolicyOverrideContract {
        path: "um/winineti.h",
        default_partition: "WinInet",
        overrides: &[],
        excluded_names: &["PFN_DIAL_HANDLER"],
    },
];

const AGGREGATE_TRANSITIVE_ROOTS: &[(&str, &str)] = &[
    ("gdiplusenums.h", "um/gdiplusenums.h"),
    ("gdiplustypes.h", "um/gdiplustypes.h"),
    ("gdiplusinit.h", "um/gdiplusinit.h"),
    ("gdipluscolor.h", "um/gdipluscolor.h"),
    ("gdipluscolormatrix.h", "um/gdipluscolormatrix.h"),
    ("gdiplusgpstubs.h", "um/gdiplusgpstubs.h"),
    ("gdiplusimaging.h", "um/gdiplusimaging.h"),
    ("gdiplusmetaheader.h", "um/gdiplusmetaheader.h"),
    ("gdipluspixelformats.h", "um/gdipluspixelformats.h"),
    ("gdipluseffects.h", "um/gdipluseffects.h"),
    ("gdiplusflat.h", "um/gdiplusflat.h"),
    ("gdiplusmem.h", "um/gdiplusmem.h"),
    ("devpkey.h", "shared/devpkey.h"),
    ("ksuuids.h", "shared/ksuuids.h"),
    ("ntddscsi.h", "shared/ntddscsi.h"),
    ("uuids.h", "shared/uuids.h"),
    ("verrsrc.h", "um/verrsrc.h"),
];

const REENTRANT_AUTHORITY_HEADERS: &[&str] =
    &["devpropdef.h", "guiddef.h", "propkeydef.h", "winddi.h"];

const COVERAGE_UNPRODUCTIVE_ALLOWLIST: &[(&str, &str, bool, &str)] = &[
    (
        "shared/ksuuids.h",
        AGGREGATE_INPUT,
        true,
        "uuids.h includes this GUID catalog first, so its constants are materialized with the parent catalog's provenance",
    ),
    (
        "shared/transportsettingcommon.h",
        AGGREGATE_INPUT,
        true,
        "mstcpip.h materializes TRANSPORT_SETTING_ID under the shared include guard before this direct visit",
    ),
    (
        "um/asptlb.h",
        AGGREGATE_INPUT,
        false,
        "the legacy IIS source omits asptlb.h; its generic COM coclass names conflict with other aggregate UUID declarations",
    ),
    (
        "um/cellularapi_oem.h",
        AGGREGATE_INPUT,
        false,
        "the pinned SDK omits imported RilAPITypes.h; the legacy source also skips this header",
    ),
    (
        "um/chakrart.h",
        AGGREGATE_INPUT,
        false,
        "the legacy Js source excludes chakrart.h because it is incompatible with the jsrt9.h mode",
    ),
    (
        "um/d3d9helper.h",
        AGGREGATE_INPUT,
        true,
        "d3d9.h materializes the Direct3D 9 surface under the shared _D3D9_H_ guard before this direct visit",
    ),
    (
        "um/icodecapi.h",
        AGGREGATE_INPUT,
        false,
        "the legacy Media Foundation source excludes icodecapi.h and uses codecapi.h for this surface",
    ),
    (
        "um/iiswebsocket.h",
        AGGREGATE_INPUT,
        false,
        "iiswebsocket.h requires the excluded httpserv.h C++ server implementation surface",
    ),
    (
        "um/mapiunicodehelp.h",
        AGGREGATE_INPUT,
        false,
        "the legacy MAPI source excludes inline Unicode helper implementations from metadata",
    ),
    (
        "um/mpeg2error.h",
        AGGREGATE_INPUT,
        true,
        "its HRESULT constants are materialized, but constant ownership follows the HRESULT root fact before spelling fallback",
    ),
    (
        "um/msoav.h",
        AGGREGATE_INPUT,
        false,
        "the legacy Internet Explorer source excludes msoav.h because the SDK omits MSOAPI_",
    ),
    (
        "um/mshtmlc.h",
        AGGREGATE_INPUT,
        true,
        "Mshtml.h materializes this declaration surface under the shared __mshtml_h__ guard before this direct visit",
    ),
    (
        "um/faxcom.h",
        AGGREGATE_INPUT,
        false,
        "the legacy Fax source excludes faxcom.h because FaxServer has a conflicting UUID in faxcomex.h",
    ),
    (
        "um/msp.h",
        AGGREGATE_INPUT,
        false,
        "the legacy Tapi3 source excludes the MSP implementation surface",
    ),
    (
        "um/mspaddr.h",
        AGGREGATE_INPUT,
        false,
        "the legacy Tapi3 source excludes ATL MSP class implementations",
    ),
    (
        "um/mspcall.h",
        AGGREGATE_INPUT,
        false,
        "the legacy Tapi3 source excludes ATL MSP class implementations",
    ),
    (
        "um/mspstrm.h",
        AGGREGATE_INPUT,
        false,
        "the legacy Tapi3 source excludes ATL MSP class implementations",
    ),
    (
        "um/ntlsa.h",
        AGGREGATE_INPUT,
        false,
        "ntlsa.h duplicates the NTSecAPI security closure used by the aggregate source",
    ),
    (
        "um/oledbguid.h",
        SATELLITE_INPUT,
        false,
        "the legacy Search source excludes oledbguid.h because it duplicates oledb.h declarations",
    ),
    (
        "um/ole.h",
        AGGREGATE_INPUT,
        false,
        "the OLE1 header conflicts with the aggregate OLE2 declaration surface",
    ),
    (
        "um/pbdaerrors.h",
        AGGREGATE_INPUT,
        true,
        "its HRESULT constants are materialized, but constant ownership follows the HRESULT root fact before spelling fallback",
    ),
    (
        "um/routprot.h",
        AGGREGATE_INPUT,
        false,
        "the legacy routing sources exclude routprot.h because its SDK closure is incomplete",
    ),
    (
        "um/rpcproxy.h",
        AGGREGATE_INPUT,
        false,
        "the legacy RPC source intentionally excludes C-only proxy implementation metadata",
    ),
    (
        "um/rtlsupportapi.h",
        AGGREGATE_INPUT,
        true,
        "winnt.h materializes the RTL support APIs from its integrated section before this direct visit",
    ),
    (
        "um/tapi3cc.h",
        AGGREGATE_INPUT,
        false,
        "the legacy Tapi3 source excludes duplicate call-center declarations",
    ),
    (
        "um/termmgr.h",
        AGGREGATE_INPUT,
        false,
        "the legacy Tapi3 source intentionally excludes terminal manager implementation metadata",
    ),
    (
        "um/tune.h",
        AGGREGATE_INPUT,
        false,
        "the legacy MsTv source excludes C++ tuning-model helper classes",
    ),
    (
        "um/tvratings_enum.h",
        AGGREGATE_INPUT,
        false,
        "the legacy MsTv source excludes duplicate TV rating declarations",
    ),
    (
        "um/vdshwprv.h",
        AGGREGATE_INPUT,
        false,
        "the legacy VDS source documents that vdshwprv.h cannot be combined with vds.h",
    ),
    (
        "um/wab.h",
        AGGREGATE_INPUT,
        true,
        "wab.h is an umbrella whose owned child headers carry the Address Book declarations",
    ),
    (
        "um/wiamindr.h",
        AGGREGATE_INPUT,
        true,
        "wiamindr.h only selects the productive NTDDI-specific wiamindr_lh.h declaration header",
    ),
    (
        "um/winenclave.h",
        AGGREGATE_INPUT,
        false,
        "winenclave.h rejects translation units that include windows.h",
    ),
    (
        "um/winsock.h",
        AGGREGATE_INPUT,
        true,
        "the aggregate prelude's winsock2.h sets the shared Winsock guard and materializes the compatible Winsock surface",
    ),
    (
        "um/wmsysprf.h",
        AGGREGATE_INPUT,
        true,
        "its profile GUIDs are materialized, but constant ownership follows the GUID root fact before spelling fallback",
    ),
    (
        "um/wsdapi.h",
        AGGREGATE_INPUT,
        true,
        "wsdapi.h is an umbrella whose owned child headers carry the Web Services on Devices declarations",
    ),
];

fn is_intentionally_unvisited_root(label: &str, input: AuthorityInput) -> bool {
    COVERAGE_UNPRODUCTIVE_ALLOWLIST
        .iter()
        .any(|(root, owner, expected_visit, _)| {
            !expected_visit
                && label.eq_ignore_ascii_case(root)
                && input.name().eq_ignore_ascii_case(owner)
        })
}

const PSAPI_V1_SYNTHESIZED_CONSTANTS: &[&str] = &[
    "LIST_MODULES_DEFAULT",
    "LIST_MODULES_32BIT",
    "LIST_MODULES_64BIT",
    "LIST_MODULES_ALL",
];

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

    fn policy_exclusions(&self) -> BTreeSet<String> {
        match self {
            Self::Common(_) => BTreeSet::new(),
            Self::Partitioned(inputs) => inputs
                .iter()
                .flat_map(|input| input.roots.values())
                .flat_map(|root| root.exclusions.iter().cloned())
                .collect(),
        }
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

fn source_include_name(line: &str) -> Option<&str> {
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

fn source_file_name(path: &str) -> &str {
    path.rsplit(['/', '\\']).next().unwrap_or(path)
}

fn resolve_source_header(header: &str, include_dirs: &[PathBuf]) -> Option<PathBuf> {
    let path = Path::new(header);
    if path.is_absolute() && path.is_file() {
        return Some(path.to_path_buf());
    }
    include_dirs
        .iter()
        .map(|directory| directory.join(path))
        .find(|candidate| candidate.is_file())
}

fn shared_root_owner_input(
    partition: &str,
    inventory_path: &str,
) -> Result<Option<AuthorityInput>, String> {
    let matching_path = SHARED_ROOT_OWNER_INPUTS
        .iter()
        .filter(|entry| entry.path.eq_ignore_ascii_case(inventory_path))
        .collect::<Vec<_>>();
    if matching_path.is_empty() {
        return Ok(None);
    }
    matching_path
        .into_iter()
        .find(|entry| entry.partition.eq_ignore_ascii_case(partition))
        .map(|entry| Some(entry.input))
        .ok_or_else(|| {
            format!(
                "shared authority root `{inventory_path}` has no reviewed input assignment for `{partition}`"
            )
        })
}

fn authority_owner_input(
    partition: &str,
    path: &Path,
    inventory_path: &str,
) -> Result<AuthorityInput, String> {
    match partition {
        "PsApi1" => return Ok(AuthorityInput::PsApiV1),
        "PsApi2" => return Ok(AuthorityInput::PsApiV2),
        _ => {}
    }
    if let Some(input) = shared_root_owner_input(partition, inventory_path)? {
        return Ok(input);
    }
    Ok(
        if crate::aggregate::uses_satellite_environment(partition)
            || crate::aggregate::is_authority_satellite_header(path)
        {
            AuthorityInput::Satellite
        } else {
            AuthorityInput::Aggregate
        },
    )
}

fn build_authority_root_plan(
    traversal: &crate::partition::TraversalPolicy,
) -> Result<AuthorityRootPlan, String> {
    let mut result = AuthorityRootPlan {
        roots: BTreeMap::new(),
        owner_inputs: BTreeMap::new(),
    };

    for partition in &traversal.partitions {
        let mut add = |path: &Path,
                       canonical_path: &crate::partition::WindowsPathIdentity,
                       inventory_path: &str|
         -> Result<(), String> {
            let input = authority_owner_input(&partition.identity, path, inventory_path)?;
            let root = result
                .roots
                .entry(canonical_path.clone())
                .or_insert_with(|| AuthorityPhysicalRoot {
                    path: path.to_path_buf(),
                    label: inventory_path.to_string(),
                    owned_inputs: BTreeSet::new(),
                });
            if root.label != inventory_path {
                return Err(format!(
                    "canonical authority root `{canonical_path}` has conflicting labels `{}` and `{inventory_path}`",
                    root.label
                ));
            }
            root.owned_inputs.insert(input);
            if let Some(existing) = result
                .owner_inputs
                .insert((partition.identity.clone(), canonical_path.clone()), input)
                && existing != input
            {
                return Err(format!(
                    "logical owner `{}` selected both `{}` and `{}` for `{inventory_path}`",
                    partition.identity,
                    existing.name(),
                    input.name()
                ));
            }
            Ok(())
        };

        for root in &partition.roots {
            match root {
                crate::partition::TraversalRoot::File(root) => {
                    add(&root.path, &root.canonical_path, &root.inventory_path)?
                }
                crate::partition::TraversalRoot::Directory(root) => {
                    for file in &root.files {
                        add(&file.path, &file.canonical_path, &file.inventory_path)?;
                    }
                }
                crate::partition::TraversalRoot::Missing(_)
                | crate::partition::TraversalRoot::Unsupported(_) => {
                    unreachable!("validated traversal policy is clean")
                }
            }
        }
    }

    let expected = traversal.canonical_physical_files().len();
    if result.roots.len() != expected {
        return Err(format!(
            "authority root plan contains {} physical roots; expected {expected}",
            result.roots.len()
        ));
    }
    for root in result.roots.values() {
        let expected_inputs = if root.label.eq_ignore_ascii_case("um/psapi.h") {
            BTreeSet::from([AuthorityInput::PsApiV1, AuthorityInput::PsApiV2])
        } else {
            let [input] = root.owned_inputs.iter().copied().collect::<Vec<_>>()[..] else {
                return Err(format!(
                    "ordinary authority root `{}` selected multiple owning inputs: {:?}",
                    root.label, root.owned_inputs
                ));
            };
            BTreeSet::from([input])
        };
        if root.owned_inputs != expected_inputs {
            return Err(format!(
                "authority root `{}` selected owning inputs {:?}; expected {:?}",
                root.label, root.owned_inputs, expected_inputs
            ));
        }
    }
    Ok(result)
}

fn absolutize_authority_source(
    source: &str,
    include_dirs: &[PathBuf],
) -> Result<(String, BTreeMap<String, usize>), String> {
    let mut result = String::new();
    let mut includes = BTreeMap::new();
    for line in source.lines() {
        if let Some(header) = source_include_name(line)
            && let Some(path) = resolve_source_header(header, include_dirs)
        {
            let path = path_arg(&path, "--include")?;
            let normalized = normalize_audit_path(&path);
            let count = includes.entry(normalized).or_insert(0);
            let reentrant = REENTRANT_AUTHORITY_HEADERS
                .iter()
                .any(|candidate| source_file_name(&path).eq_ignore_ascii_case(candidate));
            if *count == 0 || reentrant {
                result.push_str(&format!("#include \"{path}\"\n"));
            }
            *count += 1;
        } else {
            result.push_str(line);
            result.push('\n');
        }
    }
    Ok((result, includes))
}

fn append_authority_root(
    source: &mut String,
    path: &Path,
    input: AuthorityInput,
) -> Result<(), String> {
    let path = path_arg(path, "--partition-policy-root")?;
    if source_file_name(&path).eq_ignore_ascii_case("cellularapi_oem.h") {
        source.push_str(&format!(
            "\n#if __has_include(\"RilAPITypes.h\")\n#include \"{path}\"\n#endif\n"
        ));
    } else if source_file_name(&path).eq_ignore_ascii_case("x3daudio.h") {
        source.push_str(&format!(
            "\n#pragma push_macro(\"_XM_NO_INTRINSICS_\")\n\
             #undef _XM_NO_INTRINSICS_\n\
             #define _XM_NO_INTRINSICS_\n\
             #include \"{path}\"\n\
             #pragma pop_macro(\"_XM_NO_INTRINSICS_\")\n"
        ));
    } else {
        source.push_str(&format!("\n#include \"{path}\"\n"));
    }
    if matches!(input, AuthorityInput::Aggregate | AuthorityInput::Satellite) {
        source.push_str(GUID_RESET);
    }
    Ok(())
}

fn authority_owning_inputs_by_path(
    roots: &AuthorityRootPlan,
) -> Result<BTreeMap<String, AuthorityInput>, String> {
    let mut result = BTreeMap::new();
    for root in roots.roots.values() {
        let [input] = root.owned_inputs.iter().copied().collect::<Vec<_>>()[..] else {
            continue;
        };
        let path = path_arg(&root.path, "--partition-policy-root")?;
        result.insert(normalize_audit_path(&path), input);
    }
    Ok(result)
}

fn authority_root_for_source_header<'a>(
    roots: &'a AuthorityRootPlan,
    header: &str,
    resolved: Option<&Path>,
) -> Option<&'a AuthorityPhysicalRoot> {
    if let Some(resolved) = resolved {
        let resolved = normalize_audit_path(resolved.to_string_lossy().as_ref());
        if let Some(root) = roots
            .roots
            .values()
            .find(|root| normalize_audit_path(root.path.to_string_lossy().as_ref()) == resolved)
        {
            return Some(root);
        }
    }

    let header = normalize_audit_path(header);
    let mut matches = roots.roots.values().filter(|root| {
        let label = normalize_audit_path(&root.label);
        label == header
            || label
                .strip_suffix(&header)
                .is_some_and(|prefix| prefix.ends_with('/'))
    });
    let root = matches.next()?;
    matches.next().is_none().then_some(root)
}

fn append_partition_source_headers(
    aggregate: &mut String,
    satellite: &mut String,
    traversal: &crate::partition::TraversalPolicy,
    roots: &AuthorityRootPlan,
    include_dirs: &[PathBuf],
) -> Result<(), String> {
    let owning_inputs = authority_owning_inputs_by_path(roots)?;
    for partition in &traversal.partitions {
        if ["Kernel", "PsApi1", "PsApi2", "Threading"]
            .iter()
            .any(|candidate| partition.identity.eq_ignore_ascii_case(candidate))
        {
            continue;
        }
        let source = std::fs::read_to_string(&partition.input).map_err(|error| {
            format!(
                "failed to read compile environment `{}`: {error}",
                partition.input.display()
            )
        })?;
        for header in source.lines().filter_map(source_include_name) {
            if ["intrinfix.h", "windows.fixed.h"]
                .iter()
                .any(|candidate| source_file_name(header).eq_ignore_ascii_case(candidate))
                || REENTRANT_AUTHORITY_HEADERS
                    .iter()
                    .any(|candidate| source_file_name(header).eq_ignore_ascii_case(candidate))
            {
                continue;
            }
            let resolved = resolve_source_header(header, include_dirs).or_else(|| {
                partition
                    .input
                    .parent()
                    .map(|directory| directory.join(header))
                    .filter(|candidate| candidate.is_file())
            });
            let root = authority_root_for_source_header(roots, header, resolved.as_deref());
            let path = root
                .map(|root| path_arg(&root.path, "--partition-policy-root"))
                .or_else(|| resolved.as_deref().map(|path| path_arg(path, "--include")))
                .transpose()?;
            let default_input = if crate::aggregate::uses_satellite_environment(&partition.identity)
                || crate::aggregate::is_authority_satellite_header(Path::new(header))
            {
                AuthorityInput::Satellite
            } else {
                AuthorityInput::Aggregate
            };
            let input = root
                .and_then(|root| root.owned_inputs.iter().copied().next())
                .or_else(|| {
                    path.as_deref()
                        .and_then(|path| owning_inputs.get(&normalize_audit_path(path)))
                        .copied()
                })
                .unwrap_or(default_input);
            let include = path.as_deref().unwrap_or(header);
            if root.is_some_and(|root| is_intentionally_unvisited_root(&root.label, input)) {
                continue;
            }
            if input == AuthorityInput::Aggregate
                && AGGREGATE_TRANSITIVE_ROOTS
                    .iter()
                    .any(|(candidate, _)| source_file_name(include).eq_ignore_ascii_case(candidate))
            {
                continue;
            }
            match input {
                AuthorityInput::Aggregate => {
                    aggregate.push_str(&format!("\n#include \"{include}\"{GUID_RESET}"));
                }
                AuthorityInput::Satellite => {
                    satellite.push_str(&format!("\n#include \"{include}\"{GUID_RESET}"));
                }
                AuthorityInput::PsApiV1 | AuthorityInput::PsApiV2 => {}
            }
        }
    }
    aggregate.push('\n');
    satellite.push('\n');
    Ok(())
}

fn append_authority_manifest(
    aggregate: &mut String,
    satellite: &mut String,
    roots: &AuthorityRootPlan,
    include_dirs: &[PathBuf],
) -> Result<(), String> {
    // Canonical roots scope extraction; source inclusion still follows the curated SDK manifest.
    let owning_inputs = authority_owning_inputs_by_path(roots)?;

    for header in crate::win32_headers::HEADERS {
        if header.eq_ignore_ascii_case("psapi.h") {
            continue;
        }
        if AGGREGATE_TRANSITIVE_ROOTS
            .iter()
            .any(|(candidate, _)| header.eq_ignore_ascii_case(candidate))
        {
            continue;
        }
        let resolved = resolve_source_header(header, include_dirs)
            .ok_or_else(|| format!("authority manifest header `{header}` was not found"))?;
        let root = authority_root_for_source_header(roots, header, Some(&resolved));
        let path = root
            .map(|root| path_arg(&root.path, "--partition-policy-root"))
            .unwrap_or_else(|| path_arg(&resolved, "--include"))?;
        let input = root
            .and_then(|root| root.owned_inputs.iter().copied().next())
            .or_else(|| owning_inputs.get(&normalize_audit_path(&path)).copied())
            .unwrap_or_else(|| {
                if crate::aggregate::is_authority_satellite_header(Path::new(header)) {
                    AuthorityInput::Satellite
                } else {
                    AuthorityInput::Aggregate
                }
            });
        if input == AuthorityInput::Satellite {
            satellite.push_str(&format!("\n#include \"{path}\"{GUID_RESET}"));
        } else {
            aggregate.push_str(&format!("\n#include \"{path}\"{GUID_RESET}"));
        }
    }
    for header in crate::win32_headers::SATELLITE_HEADERS {
        let resolved = resolve_source_header(header, include_dirs)
            .ok_or_else(|| format!("authority manifest header `{header}` was not found"))?;
        let root = authority_root_for_source_header(roots, header, Some(&resolved));
        let path = root
            .map(|root| path_arg(&root.path, "--partition-policy-root"))
            .unwrap_or_else(|| path_arg(&resolved, "--include"))?;
        satellite.push_str(&format!("\n#include \"{path}\"{GUID_RESET}"));
    }
    aggregate.push('\n');
    satellite.push('\n');
    Ok(())
}

fn build_authority_source_plan(
    traversal: &crate::partition::TraversalPolicy,
    include_dirs: &[PathBuf],
) -> Result<AuthoritySourcePlan, String> {
    let roots = build_authority_root_plan(traversal)?;
    let structured_storage = logical_partition(traversal, "Com.StructuredStorage")?;
    let structured_storage_header = structured_storage
        .roots
        .iter()
        .find_map(|root| match root {
            crate::partition::TraversalRoot::File(root)
                if root.requested.replace('\\', "/") == "<PartitionDir>/manual.h" =>
            {
                Some(&root.path)
            }
            _ => None,
        })
        .ok_or_else(|| {
            "logical partition `Com.StructuredStorage` did not contain `<PartitionDir>/manual.h`"
                .to_string()
        })?;
    let threading_input = &logical_partition(traversal, "Threading")?.input;
    let kernel_header = logical_partition(traversal, "Kernel")?
        .roots
        .iter()
        .find_map(|root| match root {
            crate::partition::TraversalRoot::File(root) => Some(&root.path),
            _ => None,
        })
        .ok_or_else(|| "logical partition `Kernel` did not contain ntdef.h".to_string())?;
    let mut aggregate =
        crate::aggregate::main_prefix(WIN32_SDK_PRELUDE, structured_storage_header)?;
    aggregate.push_str(GUID_RESET);
    let mut satellite = format!(
        "{}{GUID_RESET}",
        crate::aggregate::satellite_source(WIN32_SDK_PRELUDE)
    );
    append_partition_source_headers(
        &mut aggregate,
        &mut satellite,
        traversal,
        &roots,
        include_dirs,
    )?;
    append_authority_manifest(&mut aggregate, &mut satellite, &roots, include_dirs)?;
    let cellular_header = roots
        .roots
        .values()
        .find(|root| root.label.eq_ignore_ascii_case("um/cellularapi_oem.h"))
        .ok_or_else(|| {
            "canonical traversal roots did not contain `um/cellularapi_oem.h`".to_string()
        })?;
    append_authority_root(
        &mut aggregate,
        &cellular_header.path,
        AuthorityInput::Aggregate,
    )?;
    let raw_sources = [
        (AuthorityInput::Aggregate, aggregate),
        (AuthorityInput::Satellite, satellite),
        (
            AuthorityInput::PsApiV1,
            crate::aggregate::psapi_source(WIN32_SDK_PRELUDE, 1),
        ),
        (
            AuthorityInput::PsApiV2,
            crate::aggregate::psapi_source(WIN32_SDK_PRELUDE, 2),
        ),
    ];
    let mut sources = BTreeMap::new();
    let mut included = BTreeMap::<AuthorityInput, BTreeSet<String>>::new();
    let mut transitively_materialized = BTreeSet::new();
    let mut deferred_materialized = BTreeSet::new();
    for (input, source) in raw_sources {
        let (source, paths) = absolutize_authority_source(&source, include_dirs)?;
        included.insert(input, paths.into_keys().collect());
        sources.insert(input, source);
    }
    for (header, _) in AGGREGATE_TRANSITIVE_ROOTS {
        let path = resolve_source_header(header, include_dirs).ok_or_else(|| {
            format!("reviewed aggregate transitive root `{header}` was not found")
        })?;
        let normalized = normalize_audit_path(&path_arg(&path, "--include")?);
        included
            .get_mut(&AuthorityInput::Aggregate)
            .expect("aggregate authority source exists")
            .insert(normalized.clone());
        transitively_materialized.insert((AuthorityInput::Aggregate, normalized));
    }
    for path in [threading_input, kernel_header] {
        let normalized = normalize_audit_path(&path_arg(path, "--partition-policy-root")?);
        included
            .get_mut(&AuthorityInput::Aggregate)
            .expect("aggregate authority source exists")
            .insert(normalized.clone());
        deferred_materialized.insert((AuthorityInput::Aggregate, normalized));
    }

    let mut ordered_roots = roots.roots.iter().collect::<Vec<_>>();
    ordered_roots.sort_by(|left, right| {
        left.1
            .label
            .to_ascii_lowercase()
            .cmp(&right.1.label.to_ascii_lowercase())
            .then_with(|| left.1.label.cmp(&right.1.label))
    });
    for (_, root) in ordered_roots {
        let normalized =
            normalize_audit_path(path_arg(&root.path, "--partition-policy-root")?.as_str());
        for input in &root.owned_inputs {
            if is_intentionally_unvisited_root(&root.label, *input) {
                continue;
            }
            let paths = included
                .get_mut(input)
                .expect("all authority inputs have generated sources");
            if paths.insert(normalized.clone()) {
                append_authority_root(
                    sources
                        .get_mut(input)
                        .expect("all authority inputs have generated sources"),
                    &root.path,
                    *input,
                )?;
            }
        }
    }
    crate::aggregate::append_threading_input(
        sources
            .get_mut(&AuthorityInput::Aggregate)
            .expect("aggregate authority source exists"),
        threading_input,
    )?;
    crate::aggregate::append_kernel_input(
        sources
            .get_mut(&AuthorityInput::Aggregate)
            .expect("aggregate authority source exists"),
        kernel_header,
    )?;

    let path_to_identity = roots
        .roots
        .iter()
        .map(|(identity, root)| {
            (
                normalize_audit_path(root.path.to_string_lossy().as_ref()),
                identity.clone(),
            )
        })
        .collect::<BTreeMap<_, _>>();
    let mut include_sites = BTreeMap::new();
    for (input, paths) in &included {
        for path in paths {
            let Some(identity) = path_to_identity.get(path) else {
                continue;
            };
            let root = roots
                .roots
                .get(identity)
                .expect("canonical authority identity exists");
            let role = if root.owned_inputs.contains(input) {
                AuthorityIncludeRole::OwnedRoot
            } else {
                AuthorityIncludeRole::DependencyOnly
            };
            include_sites.insert(
                (identity.clone(), *input),
                AuthorityIncludeSite {
                    role,
                    review_reason: match (
                        role,
                        transitively_materialized.contains(&(*input, path.clone())),
                        deferred_materialized.contains(&(*input, path.clone())),
                    ) {
                        (AuthorityIncludeRole::OwnedRoot, true, false) => {
                            "reviewed transitive aggregate umbrella ownership"
                        }
                        (AuthorityIncludeRole::OwnedRoot, false, true) => {
                            "reviewed deferred aggregate root ownership"
                        }
                        (AuthorityIncludeRole::OwnedRoot, false, false) => {
                            "canonical traversal ownership"
                        }
                        (AuthorityIncludeRole::OwnedRoot, true, true) => {
                            unreachable!("authority root cannot be both transitive and deferred")
                        }
                        (AuthorityIncludeRole::DependencyOnly, _, _) => {
                            "reviewed aggregate compile-environment dependency"
                        }
                    },
                },
            );
        }
    }
    Ok(AuthoritySourcePlan {
        roots,
        sources,
        include_sites,
    })
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
    let mut policy_exclusions = inputs.policy_exclusions();
    if let Some(logical) = &logical_partitions {
        policy_exclusions.extend(
            logical
                .traversal
                .partitions
                .iter()
                .flat_map(|partition| partition.policy.exclusions.iter().cloned()),
        );
        policy_exclusions.extend(
            HEADER_POLICY_OVERRIDE_CONTRACTS
                .iter()
                .flat_map(|contract| contract.excluded_names.iter().copied())
                .map(str::to_string),
        );
    }
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
        policy_exclusions,
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
    let root_plan = build_authority_root_plan(traversal)?;
    for partition in &traversal.partitions {
        let root_partition = convert_root_partition(partition);
        let mut add = |path: &Path,
                       canonical_path: &crate::partition::WindowsPathIdentity,
                       inventory_path: &str|
         -> Result<(), String> {
            let input = logical_policy_input(&root_plan, &partition.identity, canonical_path)?;
            let header = path_arg(path, "--partition-policy-root")?;
            if let Some(contract) = HEADER_POLICY_OVERRIDE_CONTRACTS
                .iter()
                .find(|contract| contract.path.eq_ignore_ascii_case(inventory_path))
            {
                if !partition
                    .identity
                    .eq_ignore_ascii_case(contract.default_partition)
                {
                    if contract
                        .overrides
                        .iter()
                        .any(|(_, owner)| owner.eq_ignore_ascii_case(&partition.identity))
                    {
                        return Ok(());
                    }
                    return Err(format!(
                        "shared authority root `{inventory_path}` has unexpected logical owner `{}`",
                        partition.identity
                    ));
                }
                add_header_partition_owner(
                    &mut result,
                    input,
                    header.clone(),
                    root_partition.clone(),
                );
                for name in contract.excluded_names {
                    result.add_traversed_header_override_for_input(
                        input,
                        header.clone(),
                        *name,
                        root_partition.clone().with_exclusion(*name),
                    );
                }
                for (name, owner) in contract.overrides {
                    result.add_traversed_header_override_for_input(
                        input,
                        header.clone(),
                        *name,
                        convert_root_partition(logical_partition(traversal, owner)?),
                    );
                }
                return Ok(());
            }
            add_header_partition_owner(&mut result, input, header, root_partition.clone());
            Ok(())
        };
        for root in &partition.roots {
            match root {
                crate::partition::TraversalRoot::File(root) => {
                    add(&root.path, &root.canonical_path, &root.inventory_path)?
                }
                crate::partition::TraversalRoot::Directory(root) => {
                    for file in &root.files {
                        add(&file.path, &file.canonical_path, &file.inventory_path)?;
                    }
                }
                crate::partition::TraversalRoot::Missing(_)
                | crate::partition::TraversalRoot::Unsupported(_) => {
                    unreachable!("validated traversal policy is clean")
                }
            }
        }
    }
    let psapi = logical_partition(traversal, "PsApi1")?
        .roots
        .iter()
        .find_map(|root| match root {
            crate::partition::TraversalRoot::File(root) => Some(&root.path),
            _ => None,
        })
        .ok_or_else(|| "logical partition `PsApi1` did not contain psapi.h".to_string())?;
    let psapi = path_arg(psapi, "--partition-policy-root")?;
    let psapi_v1 = convert_root_partition(logical_partition(traversal, "PsApi1")?);
    for name in PSAPI_V1_SYNTHESIZED_CONSTANTS {
        for input in [PSAPI_V1_INPUT, PSAPI_V2_INPUT] {
            result.add_traversed_header_override_for_input(
                input,
                psapi.clone(),
                *name,
                psapi_v1.clone(),
            );
        }
    }
    Ok(result)
}

fn logical_policy_input(
    root_plan: &AuthorityRootPlan,
    identity: &str,
    canonical_path: &crate::partition::WindowsPathIdentity,
) -> Result<&'static str, String> {
    root_plan
        .owner_inputs
        .get(&(identity.to_string(), canonical_path.clone()))
        .copied()
        .map(AuthorityInput::name)
        .ok_or_else(|| {
            format!("logical owner `{identity}` has no input assignment for `{canonical_path}`")
        })
}

fn add_header_partition_owner(
    policy: &mut HeaderPartitionPolicy,
    input: &str,
    header: String,
    partition: RootPartition,
) {
    policy.add_traversed_header_for_input(input, header, partition);
}

// OLD 71 emitted the sole numeric logical namespace into its valid parent namespace.
const LEGACY_EMISSION_NAMESPACE_OVERRIDES: &[(&str, &str, &str)] = &[(
    "Devices.1394",
    "Windows.Win32.Devices.1394",
    "Windows.Win32.Devices",
)];

fn emitted_partition_namespace<'a>(partition: &'a crate::partition::LogicalPartition) -> &'a str {
    LEGACY_EMISSION_NAMESPACE_OVERRIDES
        .iter()
        .find(|(identity, logical, _)| {
            partition.identity == *identity && partition.policy.namespace == *logical
        })
        .map(|(_, _, emitted)| *emitted)
        .unwrap_or(&partition.policy.namespace)
}

fn convert_root_partition(partition: &crate::partition::LogicalPartition) -> RootPartition {
    let policy = &partition.policy;
    let mut result = RootPartition::new(
        partition.identity.clone(),
        emitted_partition_namespace(partition),
    );
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
    let plan = build_authority_root_plan(traversal)?;
    let mut roots = plan
        .roots
        .into_values()
        .map(|root| {
            Ok(CoverageRoot {
                configured: path_arg(&root.path, "--partition-policy-root")?,
                label: root.label,
                owning_inputs: root
                    .owned_inputs
                    .into_iter()
                    .map(AuthorityInput::name)
                    .map(str::to_string)
                    .collect(),
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

    if let Some(traversal) = traversal {
        let plan = build_authority_source_plan(traversal, include_dirs)?;
        if plan.include_sites.is_empty()
            || plan
                .include_sites
                .values()
                .any(|site| site.review_reason.is_empty())
        {
            return Err("aggregate authority include-site audit was incomplete".to_string());
        }
        let excluded_roots = crate::win32_headers::EXCLUDE_HEADERS
            .iter()
            .filter_map(|header| resolve_header(header, include_dirs))
            .map(|path| path_arg(&path, "--include"))
            .collect::<Result<Vec<_>, _>>()?;
        let mut inputs = Vec::with_capacity(4);
        for input in [
            AuthorityInput::Aggregate,
            AuthorityInput::Satellite,
            AuthorityInput::PsApiV1,
            AuthorityInput::PsApiV2,
        ] {
            let mut physical = plan
                .roots
                .roots
                .values()
                .filter(|root| root.owned_inputs.contains(&input))
                .collect::<Vec<_>>();
            physical.sort_by(|left, right| {
                left.label
                    .to_ascii_lowercase()
                    .cmp(&right.label.to_ascii_lowercase())
                    .then_with(|| left.label.cmp(&right.label))
            });
            let roots = physical
                .iter()
                .map(|root| path_arg(&root.path, "--partition-policy-root"))
                .collect::<Result<Vec<_>, _>>()?;
            let source = plan
                .sources
                .get(&input)
                .cloned()
                .expect("all authority inputs have generated sources");
            let mut value = Input::new(input.name(), source).with_roots(roots);
            if input == AuthorityInput::Aggregate {
                value = value.with_excluded_roots(excluded_roots.iter().cloned());
            }
            inputs.push(value);
        }
        if inputs.len() != 4 {
            return Err(format!(
                "the aggregate authority plan must produce 4 inputs, but produced {}",
                inputs.len()
            ));
        }
        return Ok(ScrapeInputs::Common(inputs));
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
    if inputs.len() != 2 {
        return Err(format!(
            "the Win32 SDK manifest must produce 2 inputs, but produced {}",
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

    let configuration = timed_phase("build-configuration", "all", || {
        build_configuration(options)
    })?;

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

fn implicit_selected_functions(
    snapshot: &windows_clang::Snapshot,
    excluded_functions: &BTreeSet<String>,
    libraries: &BTreeMap<String, String>,
    has_import_annotation: impl Fn(&windows_clang::Fact) -> bool,
) -> BTreeSet<String> {
    snapshot
        .facts()
        .iter()
        .filter(|fact| fact.root && !excluded_functions.contains(&fact.name))
        .filter_map(|fact| {
            let FactData::Function { link_name, .. } = &fact.data else {
                return None;
            };
            (libraries.contains_key(link_name) || has_import_annotation(fact))
                .then(|| link_name.clone())
        })
        .collect()
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
        let mut excluded_functions = configuration.exclusions.excluded_functions().clone();
        excluded_functions.extend(configuration.policy_exclusions.iter().cloned());
        Some(implicit_selected_functions(
            &snapshot,
            &excluded_functions,
            &libraries,
            has_import_annotation,
        ))
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

fn timed_phase<T>(
    phase: &str,
    arch: &str,
    operation: impl FnOnce() -> Result<T, String>,
) -> Result<T, String> {
    let started = std::time::Instant::now();
    let result = operation();
    if std::env::var_os("WINDOWS_CLANG_TIMINGS").is_some() {
        eprintln!(
            "win32metadata-tools timing phase={phase} arch={arch} status={} elapsed_ms={:.3}",
            if result.is_ok() { "ok" } else { "error" },
            started.elapsed().as_secs_f64() * 1000.0
        );
    }
    result
}

fn plan_header_partitions(
    snapshot: &windows_clang::Snapshot,
    policy: &HeaderPartitionPolicy,
    authorities: &NamespaceAuthorities,
    emit: &EmitOptions<'_>,
    arch: &str,
) -> Result<BTreeMap<RdlPartition, String>, String> {
    let plan = timed_phase("header-ownership", arch, || {
        snapshot
            .plan_header_partitions(policy, authorities)
            .map_err(|error| format!("failed to plan {arch} metadata: {error}"))
    })?;
    timed_phase("header-emission", arch, || {
        plan.emit_with_options(emit)
            .map_err(|error| format!("failed to emit {arch} partitioned metadata: {error}"))
    })
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
    let mut visited = BTreeSet::new();
    let mut dependency_visits = BTreeSet::new();
    for included in snapshot.included_files() {
        let Some(root) = matching_coverage_root(roots, &included.path) else {
            continue;
        };
        if let Some(input) = root
            .owning_inputs
            .iter()
            .find(|input| input.eq_ignore_ascii_case(&included.input))
        {
            visited.insert((root.label.clone(), input.clone()));
        } else {
            dependency_visits.insert((root.label.clone(), included.input.clone()));
        }
    }

    let mut productive = BTreeSet::new();
    for fact in snapshot.facts() {
        if let Some(root) = fact_coverage_root(roots, fact) {
            if let Some(input) = root
                .owning_inputs
                .iter()
                .find(|input| input.eq_ignore_ascii_case(&fact.origin.tu))
            {
                productive.insert((root.label.clone(), input.clone()));
            }
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
            let input = facts_by_origin
                .get(&constant.root)
                .map(|fact| fact.origin.tu.as_str());
            if let Some(input) = input
                && let Some(input) = root
                    .owning_inputs
                    .iter()
                    .find(|owner| owner.eq_ignore_ascii_case(input))
            {
                productive.insert((root.label.clone(), input.clone()));
            }
        }
    }

    let (report, failures) =
        extraction_coverage_report(roots, &visited, &productive, &dependency_visits);
    if let Some(parent) = path.parent() {
        std::fs::create_dir_all(parent)
            .map_err(|error| format!("failed to create `{}`: {error}", parent.display()))?;
    }
    std::fs::write(path, report)
        .map_err(|error| format!("failed to write `{}`: {error}", path.display()))?;
    if failures.is_empty() {
        Ok(())
    } else {
        Err(format!(
            "extraction coverage found {} issue(s):\n{}",
            failures.len(),
            failures.join("\n")
        ))
    }
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

fn extraction_coverage_report(
    roots: &[CoverageRoot],
    visited: &BTreeSet<(String, String)>,
    productive: &BTreeSet<(String, String)>,
    dependency_visits: &BTreeSet<(String, String)>,
) -> (String, Vec<String>) {
    let mut pairs = roots
        .iter()
        .flat_map(|root| {
            root.owning_inputs
                .iter()
                .map(|input| (root.label.clone(), input.clone()))
        })
        .collect::<Vec<_>>();
    pairs.sort();
    let unvisited = pairs
        .iter()
        .filter(|pair| !visited.contains(*pair))
        .cloned()
        .collect::<Vec<_>>();
    let zero_fact = pairs
        .iter()
        .filter(|pair| visited.contains(*pair) && !productive.contains(*pair))
        .cloned()
        .collect::<Vec<_>>();
    let applicable_allowlist = COVERAGE_UNPRODUCTIVE_ALLOWLIST
        .iter()
        .filter(|(root, input, _, _)| pairs.contains(&((*root).to_string(), (*input).to_string())))
        .collect::<Vec<_>>();
    let allowlisted = applicable_allowlist
        .iter()
        .map(|(root, input, _, _)| ((*root).to_string(), (*input).to_string()))
        .collect::<BTreeSet<_>>();
    let mut failures = unvisited
        .iter()
        .filter(|pair| !allowlisted.contains(*pair))
        .map(|(root, input)| format!("unvisited\t{input}\t{root}"))
        .collect::<Vec<_>>();
    failures.extend(
        zero_fact
            .iter()
            .filter(|pair| !allowlisted.contains(*pair))
            .map(|(root, input)| format!("uncategorized-zero-fact\t{input}\t{root}")),
    );
    failures.extend(
        applicable_allowlist
            .iter()
            .filter(|(root, input, expected_visit, _)| {
                let pair = ((*root).to_string(), (*input).to_string());
                productive.contains(&pair) || visited.contains(&pair) != *expected_visit
            })
            .map(|(root, input, _, _)| format!("stale-unproductive-allowlist\t{input}\t{root}")),
    );
    let categorized = pairs
        .iter()
        .filter(|pair| allowlisted.contains(*pair) && !productive.contains(*pair))
        .count();
    let uncategorized = unvisited
        .iter()
        .chain(zero_fact.iter())
        .filter(|pair| !allowlisted.contains(*pair))
        .count();

    let mut lines = vec![
        "version\t2".to_string(),
        format!("summary\tcanonical_roots\t{}", roots.len()),
        format!("summary\towning_root_pairs\t{}", pairs.len()),
        format!(
            "summary\tvisited_root_pairs\t{}",
            pairs.len().saturating_sub(unvisited.len())
        ),
        format!("summary\tproductive_root_pairs\t{}", productive.len()),
        format!("summary\tunvisited_root_pairs\t{}", unvisited.len()),
        format!("summary\tvisited_zero_fact_pairs\t{}", zero_fact.len()),
        format!("summary\tcategorized_unproductive_pairs\t{categorized}"),
        format!("summary\tuncategorized_unproductive_pairs\t{uncategorized}"),
        format!(
            "summary\tdependency_only_visits\t{}",
            dependency_visits.len()
        ),
    ];
    for (root, input) in &pairs {
        let visit = if visited.contains(&(root.clone(), input.clone())) {
            "visited"
        } else {
            "unvisited"
        };
        let facts = if productive.contains(&(root.clone(), input.clone())) {
            "productive"
        } else if allowlisted.contains(&(root.clone(), input.clone())) {
            "categorized-unproductive"
        } else {
            "uncategorized-zero-fact"
        };
        lines.push(format!("root\t{input}\t{visit}\t{facts}\t{root}"));
    }
    lines.extend(
        dependency_visits
            .iter()
            .map(|(root, input)| format!("dependency\t{input}\t{root}")),
    );
    lines.extend(
        applicable_allowlist
            .iter()
            .map(|(root, input, expected_visit, reason)| {
                let expected_visit = if *expected_visit {
                    "visited"
                } else {
                    "unvisited"
                };
                format!("allowlist\t{input}\t{root}\t{expected_visit}\t{reason}")
            }),
    );
    lines.push(String::new());
    (lines.join("\n"), failures)
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

    fn checked_in_clang_args(include_dirs: &[PathBuf]) -> Vec<String> {
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
        for directory in include_dirs {
            args.extend([
                "-isystem".to_string(),
                path_arg(directory, "--include").unwrap(),
            ]);
        }
        args.push("--target=x86_64-pc-windows-msvc".to_string());
        args
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
    fn implicit_library_selection_omits_excluded_functions() {
        ensure_libclang();
        let root = scratch("implicit-library-selection");
        let header = root.join("selection.h");
        std::fs::write(
            &header,
            "extern \"C\" int Kept(void);\nextern \"C\" int Excluded(void);\n",
        )
        .unwrap();
        let header_arg = path_arg(&header, "--include").unwrap();
        let snapshot = windows_clang::extract(
            [
                Input::new(AGGREGATE_INPUT, format!("#include \"{header_arg}\"\n"))
                    .with_roots([header_arg]),
            ],
            &["-x", "c++", "--target=x86_64-pc-windows-msvc"],
        )
        .unwrap();
        let libraries = BTreeMap::from([
            ("Excluded".to_string(), "test.dll".to_string()),
            ("Kept".to_string(), "test.dll".to_string()),
        ]);
        let excluded = BTreeSet::from(["Excluded".to_string()]);

        assert_eq!(
            implicit_selected_functions(&snapshot, &excluded, &libraries, |_| false),
            BTreeSet::from(["Kept".to_string()])
        );
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
        let source_plan = build_authority_source_plan(&traversal, &include_dirs).unwrap();
        assert_eq!(source_plan.roots.roots.len(), 1559);
        assert!(
            source_plan
                .include_sites
                .values()
                .any(|site| site.role == AuthorityIncludeRole::OwnedRoot)
        );
        assert!(
            source_plan
                .include_sites
                .values()
                .any(|site| site.role == AuthorityIncludeRole::DependencyOnly)
        );
        assert!(
            source_plan
                .include_sites
                .values()
                .all(|site| { !site.review_reason.is_empty() })
        );
        let site = |label: &str, input: AuthorityInput| {
            let identity = source_plan
                .roots
                .roots
                .iter()
                .find(|(_, root)| root.label.eq_ignore_ascii_case(label))
                .map(|(identity, _)| identity.clone())
                .unwrap();
            source_plan.include_sites.get(&(identity, input))
        };
        assert_eq!(
            site("um/avifmt.h", AuthorityInput::Aggregate).unwrap().role,
            AuthorityIncludeRole::OwnedRoot
        );
        assert_eq!(
            site("um/avifmt.h", AuthorityInput::Satellite).unwrap().role,
            AuthorityIncludeRole::DependencyOnly
        );
        for label in [
            "um/ddraw.h",
            "um/ddrawi.h",
            "um/ddrawint.h",
            "um/ddkernel.h",
            "um/dvp.h",
        ] {
            assert_eq!(
                site(label, AuthorityInput::Satellite).unwrap().role,
                AuthorityIncludeRole::OwnedRoot
            );
            assert_eq!(
                site(label, AuthorityInput::Aggregate).unwrap().role,
                AuthorityIncludeRole::DependencyOnly
            );
        }
        for label in ["um/dxcore.h", "um/dxcore_interface.h"] {
            assert_eq!(
                site(label, AuthorityInput::Aggregate).unwrap().role,
                AuthorityIncludeRole::OwnedRoot
            );
            assert!(site(label, AuthorityInput::Satellite).is_none());
        }
        for (header, inventory_label) in AGGREGATE_TRANSITIVE_ROOTS {
            let transitive = site(inventory_label, AuthorityInput::Aggregate).unwrap();
            assert_eq!(transitive.role, AuthorityIncludeRole::OwnedRoot);
            assert_eq!(
                transitive.review_reason,
                "reviewed transitive aggregate umbrella ownership"
            );
            let expected_direct_dependencies =
                usize::from(["gdipluseffects.h", "uuids.h"].contains(header));
            let suffix = format!("/{}\"", header.to_ascii_lowercase());
            assert_eq!(
                source_plan
                    .sources
                    .get(&AuthorityInput::Aggregate)
                    .unwrap()
                    .to_ascii_lowercase()
                    .matches(&suffix)
                    .count(),
                expected_direct_dependencies,
                "{header} used an unexpected direct include count"
            );
        }
        let aggregate_source = source_plan.sources.get(&AuthorityInput::Aggregate).unwrap();
        let satellite_source = source_plan.sources.get(&AuthorityInput::Satellite).unwrap();
        let include_suffix = |name: &str| format!("/{}\"", name.to_ascii_lowercase());
        let aggregate_lower = aggregate_source.to_ascii_lowercase();
        let satellite_lower = satellite_source.to_ascii_lowercase();
        assert!(
            aggregate_lower
                .find(&include_suffix("shellscalingapi.h"))
                .unwrap()
                < aggregate_lower.find(&include_suffix("tlhelp32.h")).unwrap()
        );
        assert!(!aggregate_lower.contains(&include_suffix("psapi.h")));
        assert!(!satellite_lower.contains(&include_suffix("psapi.h")));
        for header in ["ImageHlp.h", "cardmod.h", "infocard.h"] {
            let suffix = include_suffix(header);
            assert!(!aggregate_lower.contains(&suffix), "{header}");
            assert!(satellite_lower.contains(&suffix), "{header}");
        }
        for header in ["AudioAPOTypes.h", "p2p.h", "SpOrder.h"] {
            let suffix = include_suffix(header);
            assert!(aggregate_lower.contains(&suffix), "{header}");
            assert!(!satellite_lower.contains(&suffix), "{header}");
        }
        for header in ["sql.h", "sqlext.h"] {
            let suffix = include_suffix(header);
            assert!(!aggregate_lower.contains(&suffix), "{header}");
            assert!(satellite_lower.contains(&suffix), "{header}");
        }
        for header in [
            "chakrart.h",
            "msoav.h",
            "rpcproxy.h",
            "tune.h",
            "vdshwprv.h",
        ] {
            let suffix = include_suffix(header);
            assert!(!aggregate_lower.contains(&suffix), "{header}");
            assert!(!satellite_lower.contains(&suffix), "{header}");
        }
        assert!(
            aggregate_lower.find(&include_suffix("uuids.h")).unwrap()
                < aggregate_lower.find(&include_suffix("avifmt.h")).unwrap()
        );
        for label in ["partition/threading/main.cpp", "shared/ntdef.h"] {
            let deferred = site(label, AuthorityInput::Aggregate).unwrap();
            assert_eq!(deferred.role, AuthorityIncludeRole::OwnedRoot);
            assert_eq!(
                deferred.review_reason,
                "reviewed deferred aggregate root ownership"
            );
        }
        let threading = aggregate_source
            .find("Partitions/Threading/main.cpp")
            .unwrap();
        let kernel = aggregate_source
            .find("RecompiledIdlHeaders/shared/ntdef.h")
            .unwrap();
        assert!(threading < kernel);
        assert_eq!(
            aggregate_source.rfind("#include").unwrap(),
            aggregate_source[..kernel].rfind("#include").unwrap()
        );
        assert_eq!(
            satellite_lower.matches(&include_suffix("winddi.h")).count(),
            4,
            "bounded USERMODE_DRIVER reinclusions must be preserved"
        );

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
        assert_eq!(traversal.file_root_count(), 1565);
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
        let root_plan = build_authority_root_plan(&traversal).unwrap();
        let direct_draw = logical_partition(&traversal, "DirectDraw").unwrap();
        let direct_draw_roots = direct_draw
            .roots
            .iter()
            .flat_map(|root| match root {
                crate::partition::TraversalRoot::File(root) => vec![&root.path],
                crate::partition::TraversalRoot::Directory(root) => {
                    root.files.iter().map(|file| &file.path).collect()
                }
                crate::partition::TraversalRoot::Missing(_)
                | crate::partition::TraversalRoot::Unsupported(_) => {
                    panic!("checked-in traversal policy was not clean")
                }
            })
            .collect::<Vec<_>>();
        assert_eq!(direct_draw_roots.len(), 7);
        assert!(direct_draw_roots.iter().all(|path| {
            let partition = logical_partition(&traversal, "DirectDraw").unwrap();
            let canonical = partition
                .roots
                .iter()
                .find_map(|root| match root {
                    crate::partition::TraversalRoot::File(root) if &root.path == *path => {
                        Some(&root.canonical_path)
                    }
                    _ => None,
                })
                .unwrap();
            logical_policy_input(&root_plan, "DirectDraw", canonical).unwrap() == SATELLITE_INPUT
        }));
        let usb = traversal
            .canonical_physical_files()
            .into_iter()
            .find(|(canonical, _)| canonical.as_str().ends_with("/shared/usb.h"))
            .map(|(_, path)| path)
            .expect("checked-in traversal policy did not contain shared/usb.h");
        let avifmt = traversal
            .canonical_physical_files()
            .into_iter()
            .find(|(canonical, _)| canonical.as_str().ends_with("/um/avifmt.h"))
            .map(|(_, path)| path)
            .expect("checked-in traversal policy did not contain um/avifmt.h");
        let physical_input = |path: &Path| {
            root_plan
                .roots
                .values()
                .find(|root| root.path == path)
                .and_then(|root| root.owned_inputs.iter().next())
                .copied()
                .unwrap()
        };
        assert_eq!(physical_input(&usb), AuthorityInput::Aggregate);
        assert_eq!(physical_input(&avifmt), AuthorityInput::Aggregate);
        for partition in &traversal.partitions {
            for root in &partition.roots {
                let files = match root {
                    crate::partition::TraversalRoot::File(root) => {
                        vec![(&root.path, &root.canonical_path)]
                    }
                    crate::partition::TraversalRoot::Directory(root) => root
                        .files
                        .iter()
                        .map(|file| (&file.path, &file.canonical_path))
                        .collect(),
                    crate::partition::TraversalRoot::Missing(_)
                    | crate::partition::TraversalRoot::Unsupported(_) => {
                        panic!("checked-in traversal policy was not clean")
                    }
                };
                for (path, canonical_path) in files {
                    let input =
                        logical_policy_input(&root_plan, &partition.identity, canonical_path)
                            .unwrap();
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
            let satellite = physical_input(&path) == AuthorityInput::Satellite;
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
        assert_eq!(satellite_roots, 156);
        let usb = path_arg(&usb, "--partition-policy-root").unwrap();
        assert!(authority[0].roots.contains(&usb));
        assert!(!authority[1].roots.contains(&usb));
        let avifmt = path_arg(&avifmt, "--partition-policy-root").unwrap();
        assert!(authority[0].roots.contains(&avifmt));
        assert!(!authority[1].roots.contains(&avifmt));

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
        for (input, version) in [(&authority[2], 1), (&authority[3], 2)] {
            let define = input
                .source
                .find(&format!("#define PSAPI_VERSION {version}"))
                .unwrap();
            let include = input
                .source
                .to_ascii_lowercase()
                .find("/psapi.h\"")
                .unwrap();
            assert!(define < include);
        }
        let satellite = &authority[1].source;
        let satellite_lower = satellite.to_ascii_lowercase();
        let mmreg = satellite_lower.find("/mmreg.h\"").unwrap();
        let avifmt = satellite_lower.find("/avifmt.h\"").unwrap();
        let no_avifmt = satellite.find("#define NOAVIFMT").unwrap();
        let vfw = satellite_lower.find("/vfw.h\"").unwrap();
        let restore_avifmt = satellite.find("#undef NOAVIFMT").unwrap();
        assert!(mmreg < avifmt && avifmt < no_avifmt && no_avifmt < vfw && vfw < restore_avifmt);
        assert_eq!(satellite_lower.matches("/vfw.h\"").count(), 1);
        for header in ["ntddcdvd.h", "tbs.h"] {
            let resolved = resolve(header);
            assert!(
                authority[1].roots.contains(&resolved),
                "{header} was not isolated in the satellite input"
            );
            assert!(!authority[0].roots.contains(&resolved));
        }
        for header in [
            "ntdddisk.h",
            "ntddchgr.h",
            "Windows.Media.SpeechRecognition.h",
        ] {
            let resolved = resolve(header);
            assert!(
                !authority
                    .iter()
                    .any(|input| input.roots.contains(&resolved))
            );
        }
        let search = logical_partition(&traversal, "Search").unwrap();
        for root in &search.roots {
            let crate::partition::TraversalRoot::File(root) = root else {
                panic!("Search unexpectedly contains a directory root");
            };
            let root = path_arg(&root.path, "--partition-policy-root").unwrap();
            assert!(authority[1].roots.contains(&root));
            assert!(!authority[0].roots.contains(&root));
        }
        assert!(authority[1].source.contains("/query.h\""));
        assert!(!authority[0].source.contains("/query.h\""));
        let cellular = resolve("cellularapi_oem.h");
        assert!(authority[0].roots.contains(&cellular));
        assert!(!authority[1].roots.contains(&cellular));
        assert!(
            authority[0]
                .source
                .contains("#if __has_include(\"RilAPITypes.h\")")
        );
        assert_eq!(
            COVERAGE_UNPRODUCTIVE_ALLOWLIST
                .iter()
                .map(|(root, _, _, _)| *root)
                .collect::<Vec<_>>(),
            [
                "shared/ksuuids.h",
                "shared/transportsettingcommon.h",
                "um/asptlb.h",
                "um/cellularapi_oem.h",
                "um/chakrart.h",
                "um/d3d9helper.h",
                "um/icodecapi.h",
                "um/iiswebsocket.h",
                "um/mapiunicodehelp.h",
                "um/mpeg2error.h",
                "um/msoav.h",
                "um/mshtmlc.h",
                "um/faxcom.h",
                "um/msp.h",
                "um/mspaddr.h",
                "um/mspcall.h",
                "um/mspstrm.h",
                "um/ntlsa.h",
                "um/oledbguid.h",
                "um/ole.h",
                "um/pbdaerrors.h",
                "um/routprot.h",
                "um/rpcproxy.h",
                "um/rtlsupportapi.h",
                "um/tapi3cc.h",
                "um/termmgr.h",
                "um/tune.h",
                "um/tvratings_enum.h",
                "um/vdshwprv.h",
                "um/wab.h",
                "um/wiamindr.h",
                "um/winenclave.h",
                "um/winsock.h",
                "um/wmsysprf.h",
                "um/wsdapi.h",
            ]
        );
        assert_eq!(
            COVERAGE_UNPRODUCTIVE_ALLOWLIST
                .iter()
                .filter(|(_, _, expected_visit, _)| *expected_visit)
                .map(|(root, _, _, _)| *root)
                .collect::<Vec<_>>(),
            [
                "shared/ksuuids.h",
                "shared/transportsettingcommon.h",
                "um/d3d9helper.h",
                "um/mpeg2error.h",
                "um/mshtmlc.h",
                "um/pbdaerrors.h",
                "um/rtlsupportapi.h",
                "um/wab.h",
                "um/wiamindr.h",
                "um/winsock.h",
                "um/wmsysprf.h",
                "um/wsdapi.h",
            ]
        );
        assert_eq!(
            COVERAGE_UNPRODUCTIVE_ALLOWLIST
                .iter()
                .filter(|(_, _, expected_visit, _)| !*expected_visit)
                .count(),
            23
        );
        for (label, input, expected_visit, reason) in COVERAGE_UNPRODUCTIVE_ALLOWLIST {
            assert!(!reason.is_empty(), "{label}");
            let root = source_plan
                .roots
                .roots
                .values()
                .find(|root| root.label.eq_ignore_ascii_case(label))
                .unwrap();
            assert!(
                root.owned_inputs
                    .iter()
                    .any(|owner| owner.name().eq_ignore_ascii_case(input)),
                "{label}"
            );
            let input = [
                AuthorityInput::Aggregate,
                AuthorityInput::Satellite,
                AuthorityInput::PsApiV1,
                AuthorityInput::PsApiV2,
            ]
            .into_iter()
            .find(|candidate| candidate.name().eq_ignore_ascii_case(input))
            .unwrap();
            assert_eq!(
                !*expected_visit,
                is_intentionally_unvisited_root(label, input),
                "{label}"
            );
        }
    }

    #[test]
    fn checked_in_authority_compile_environment_sources_parse() {
        ensure_libclang();
        let win_sdk = checked_in_win_sdk();
        let include_dirs = checked_in_include_dirs(&win_sdk);
        let traversal = checked_in_traversal_policy();
        let plan = build_authority_source_plan(&traversal, &include_dirs).unwrap();
        let args = checked_in_clang_args(&include_dirs);
        let args = args.iter().map(String::as_str).collect::<Vec<_>>();

        for input in [AuthorityInput::Aggregate, AuthorityInput::Satellite] {
            let name = input.name();
            let source = plan.sources.get(&input).unwrap().clone();
            let snapshot = windows_clang::extract([Input::new(name, source)], &args)
                .unwrap_or_else(|error| panic!("{name}: {error}"));
            let expected: &[&str] = if name == AGGREGATE_INPUT {
                &["MPEG2StreamType", "ADDRALIAS"]
            } else {
                &["_CONSOLECONTROL", "IWordBreaker", "TPM_DEVICE_INFO"]
            };
            for expected in expected.iter().copied() {
                assert!(
                    snapshot.facts().iter().any(|fact| fact.name == expected),
                    "{name} did not preserve `{expected}` through its isolated source block"
                );
            }
            let expected_scoped_enums: &[(&str, &str)] = if name == AGGREGATE_INPUT {
                &[("__MIDL___MIDL_itf_devicetopology_0000_0000_0013", "Network")]
            } else {
                &[
                    ("__MIDL___MIDL_itf_devicetopology_0000_0000_0013", "Network"),
                    ("JsDebugReadMemoryFlags", "None"),
                    ("_PaddingMode", "None"),
                ]
            };
            for (enum_name, variant_name) in expected_scoped_enums {
                let fact = snapshot
                    .facts()
                    .iter()
                    .find(|fact| fact.name == *enum_name)
                    .unwrap_or_else(|| panic!("{name} did not preserve enum `{enum_name}`"));
                let FactData::Enum {
                    variants, scoped, ..
                } = &fact.data
                else {
                    panic!("{name} did not preserve `{enum_name}` as an enum");
                };
                assert!(*scoped, "{name} did not scope `{enum_name}`");
                assert!(
                    variants.iter().any(|variant| variant.name == *variant_name),
                    "{name} did not preserve `{enum_name}.{variant_name}`"
                );
            }
            let expected_aliases: &[&str] = if name == AGGREGATE_INPUT {
                &["ConnectorType"]
            } else {
                &["ConnectorType", "PaddingMode"]
            };
            for alias in expected_aliases {
                assert!(
                    snapshot
                        .facts()
                        .iter()
                        .any(|fact| fact.name == *alias
                            && matches!(fact.data, FactData::Typedef { .. })),
                    "{name} did not preserve typedef `{alias}`"
                );
            }
        }
    }

    #[test]
    fn checked_in_authority_scoped_enums_preserve_focused_header_behavior() {
        ensure_libclang();
        let win_sdk = checked_in_win_sdk();
        let include_dirs = checked_in_include_dirs(&win_sdk);
        let args = checked_in_clang_args(&include_dirs);
        let args = args.iter().map(String::as_str).collect::<Vec<_>>();
        let resolve = |header: &str| {
            include_dirs
                .iter()
                .map(|directory| directory.join(header))
                .find(|path| path.is_file())
                .unwrap()
        };

        for (input, header, source_prefix, enum_name, variant_name, alias) in [
            (
                "focused-infocard.cpp",
                "infocard.h",
                "",
                "_PaddingMode",
                "None",
                Some("PaddingMode"),
            ),
            (
                "focused-jscript9diag.cpp",
                "jscript9diag.h",
                "",
                "JsDebugReadMemoryFlags",
                "None",
                None,
            ),
            (
                "focused-devicetopology.cpp",
                "devicetopology.h",
                "#include <ks.h>\n#define _KS_\n",
                "__MIDL___MIDL_itf_devicetopology_0000_0000_0013",
                "Network",
                Some("ConnectorType"),
            ),
        ] {
            let root = resolve(header);
            let source = format!("{WIN32_SDK_PRELUDE}{source_prefix}#include <{header}>\n");
            assert!(!source.contains("WIN32METADATA_AGGREGATE_ROUTING"));
            let snapshot = windows_clang::extract(
                [Input::new(input, source).with_roots([path_arg(&root, "--include").unwrap()])],
                &args,
            )
            .unwrap_or_else(|error| panic!("{input}: {error}"));
            let fact = snapshot
                .facts()
                .iter()
                .find(|fact| fact.name == enum_name)
                .unwrap_or_else(|| panic!("{input} did not preserve enum `{enum_name}`"));
            let FactData::Enum {
                variants, scoped, ..
            } = &fact.data
            else {
                panic!("{input} did not preserve `{enum_name}` as an enum");
            };
            assert!(!scoped, "{input} unexpectedly scoped `{enum_name}`");
            assert!(
                variants.iter().any(|variant| variant.name == variant_name),
                "{input} did not preserve `{enum_name}.{variant_name}`"
            );
            if let Some(alias) = alias {
                assert!(
                    snapshot
                        .facts()
                        .iter()
                        .any(|fact| fact.name == alias
                            && matches!(fact.data, FactData::Typedef { .. })),
                    "{input} did not preserve typedef `{alias}`"
                );
            }
        }
    }

    #[test]
    fn checked_in_avi_headers_preserve_old_71_surface_without_duplicate_owners() {
        ensure_libclang();
        let win_sdk = checked_in_win_sdk();
        let include_dirs = checked_in_include_dirs(&win_sdk);
        let find_header = |name: &str| {
            include_dirs
                .iter()
                .map(|directory| directory.join(name))
                .find(|path| path.is_file())
                .unwrap()
        };
        let avifmt = find_header("avifmt.h");
        let vfw = find_header("Vfw.h");
        let windef = find_header("windef.h");
        let wingdi = find_header("wingdi.h");
        let guiddef = find_header("guiddef.h");
        let prelude = "#define SECURITY_WIN32\n#define WIN32_NO_STATUS\n#include <winsock2.h>\n#include <windows.h>\n#undef WIN32_NO_STATUS\n#include <ntstatus.h>\n";
        let main_source = format!("{prelude}\n#include <mmreg.h>\n#include <avifmt.h>\n");
        let satellite_source = format!(
            "{prelude}\n#include <mmreg.h>\n#include <avifmt.h>\n\
             #define NOAVIFMT\n#include <vfw.h>\n#undef NOAVIFMT\n"
        );

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
        let snapshot = windows_clang::extract(
            [
                Input::new(AGGREGATE_INPUT, main_source).with_roots(
                    [&avifmt, &windef, &wingdi, &guiddef]
                        .map(|path| path_arg(path, "--include").unwrap()),
                ),
                Input::new(SATELLITE_INPUT, satellite_source).with_roots([path_arg(
                    &vfw,
                    "--include",
                )
                .unwrap()]),
            ],
            &args,
        )
        .unwrap();

        const OLD_71_AVI_CONSTANTS: &[&str] = &[
            "AVI_HEADERSIZE",
            "AVIF_COPYRIGHTED",
            "AVIF_HASINDEX",
            "AVIF_ISINTERLEAVED",
            "AVIF_MUSTUSEINDEX",
            "AVIF_WASCAPTUREFILE",
            "AVIIF_COMPUSE",
            "AVIIF_FIRSTPART",
            "AVIIF_KEYFRAME",
            "AVIIF_LASTPART",
            "AVIIF_LIST",
            "AVIIF_NOTIME",
            "AVISF_DISABLED",
            "AVISF_VIDEO_PALCHANGES",
        ];
        const SHARED_AVI_CONSTANTS: &[&str] = &[
            "AVI_HEADERSIZE",
            "AVIF_COPYRIGHTED",
            "AVIF_HASINDEX",
            "AVIF_ISINTERLEAVED",
            "AVIF_MUSTUSEINDEX",
            "AVIF_WASCAPTUREFILE",
            "AVIIF_COMPUSE",
            "AVIIF_FIRSTPART",
            "AVIIF_KEYFRAME",
            "AVIIF_LASTPART",
            "AVIIF_LIST",
            "AVIIF_MIDPART",
            "AVIIF_NOTIME",
            "AVISF_DISABLED",
            "AVISF_VIDEO_PALCHANGES",
            "ckidAVIMAINHDR",
            "ckidAVINEWINDEX",
            "ckidAVIPADDING",
            "ckidSTREAMFORMAT",
            "ckidSTREAMHANDLERDATA",
            "ckidSTREAMHEADER",
            "ckidSTREAMNAME",
            "cktypeDIBbits",
            "cktypeDIBcompressed",
            "cktypePALchange",
            "cktypeWAVEbytes",
            "formtypeAVI",
            "listtypeAVIHEADER",
            "listtypeAVIMOVIE",
            "listtypeAVIRECORD",
            "listtypeSTREAMHEADER",
            "streamtypeAUDIO",
            "streamtypeMIDI",
            "streamtypeTEXT",
            "streamtypeVIDEO",
        ];
        const AVI_RECORDS: &[&str] = &[
            "MainAVIHeader",
            "AVIStreamHeader",
            "AVIINDEXENTRY",
            "AVIPALCHANGE",
        ];
        const AVI_DEPENDENCY_TYPES: &[&str] =
            &["tagRECT", "RECT", "tagPALETTEENTRY", "PALETTEENTRY"];

        let traversal = checked_in_traversal_policy();
        let policy = HeaderPartitionPolicy::new()
            .with_traversed_header_for_input(
                AGGREGATE_INPUT,
                path_arg(&avifmt, "--include").unwrap(),
                convert_root_partition(logical_partition(&traversal, "Media.DShow").unwrap()),
            )
            .with_traversed_header_for_input(
                SATELLITE_INPUT,
                path_arg(&vfw, "--include").unwrap(),
                convert_root_partition(logical_partition(&traversal, "Multimedia").unwrap()),
            )
            .with_traversed_header_for_input(
                AGGREGATE_INPUT,
                path_arg(&windef, "--include").unwrap(),
                convert_root_partition(logical_partition(&traversal, "Foundation").unwrap()),
            )
            .with_traversed_header_for_input(
                AGGREGATE_INPUT,
                path_arg(&wingdi, "--include").unwrap(),
                convert_root_partition(logical_partition(&traversal, "Gdi").unwrap()),
            )
            .with_traversed_header_for_input(
                AGGREGATE_INPUT,
                path_arg(&guiddef, "--include").unwrap(),
                convert_root_partition(logical_partition(&traversal, "Com").unwrap()),
            );
        let references = BTreeMap::new();
        let selected_functions = BTreeSet::from(["AVIFileInit".to_string()]);
        let selected_types = AVI_RECORDS
            .iter()
            .chain(AVI_DEPENDENCY_TYPES)
            .copied()
            .collect::<BTreeSet<_>>();
        let excluded_types = snapshot
            .facts()
            .iter()
            .filter(|fact| !matches!(fact.data, FactData::Function { .. }))
            .filter(|fact| !selected_types.contains(fact.name.as_str()))
            .map(|fact| fact.name.clone())
            .collect::<BTreeSet<_>>();
        let selected_constants = SHARED_AVI_CONSTANTS
            .iter()
            .copied()
            .collect::<BTreeSet<_>>();
        let excluded_constants = snapshot
            .constants()
            .iter()
            .filter(|constant| !selected_constants.contains(constant.name.as_str()))
            .map(|constant| constant.name.clone())
            .collect::<BTreeSet<_>>();
        let mut emit = EmitOptions::new(DEFAULT_NAMESPACE, &references);
        emit.library = Some("");
        emit.functions = Some(&selected_functions);
        emit.excluded_types = Some(&excluded_types);
        emit.excluded_constants = Some(&excluded_constants);
        let authorities = crate::namespace_routes::NamespaceRoutes::load(
            &win_sdk.join("requiredNamespacesForNames.rsp"),
        )
        .unwrap()
        .authorities();
        let partitions =
            plan_header_partitions(&snapshot, &policy, &authorities, &emit, "x64").unwrap();
        let direct_show = partitions
            .iter()
            .find(|(partition, _)| partition.partition == "Media.DShow")
            .unwrap()
            .1;
        let multimedia = partitions
            .iter()
            .find(|(partition, _)| partition.partition == "Multimedia")
            .unwrap()
            .1;

        let mut unexpected_constants = Vec::new();
        for name in SHARED_AVI_CONSTANTS {
            let declaration = format!("const {name}");
            let count = partitions
                .values()
                .map(|rdl| rdl.matches(&declaration).count())
                .sum::<usize>();
            if !OLD_71_AVI_CONSTANTS.contains(name) && count != 0 {
                unexpected_constants.push((*name, count));
            }
            assert!(!multimedia.contains(&declaration), "{multimedia}");
        }
        assert!(
            unexpected_constants.is_empty(),
            "OLD 71-absent AVI constants were emitted: {unexpected_constants:?}"
        );
        for name in OLD_71_AVI_CONSTANTS {
            let declaration = format!("const {name}");
            assert_eq!(
                direct_show.matches(&declaration).count(),
                1,
                "{direct_show}"
            );
        }
        for name in AVI_RECORDS {
            assert!(direct_show.contains(name), "{direct_show}");
            assert!(!multimedia.contains(name), "{multimedia}");
        }
        assert!(multimedia.contains("fn AVIFileInit("), "{multimedia}");
        assert!(!direct_show.contains("fn AVIFileInit("), "{direct_show}");
    }

    #[test]
    fn multimedia_legacy_order_deduplicates_ictype_constants() {
        ensure_libclang();
        let win_sdk = checked_in_win_sdk();
        let include_dirs = checked_in_include_dirs(&win_sdk);
        let find_header = |name: &str| {
            include_dirs
                .iter()
                .map(|directory| directory.join(name))
                .find(|path| path.is_file())
                .unwrap()
        };
        let mmreg = find_header("mmreg.h");
        let vfw = find_header("Vfw.h");
        let prelude = "#define SECURITY_WIN32\n#define WIN32_NO_STATUS\n#include <winsock2.h>\n#include <windows.h>\n#undef WIN32_NO_STATUS\n#include <ntstatus.h>\n";
        let args = checked_in_clang_args(&include_dirs);
        let args = args.iter().map(String::as_str).collect::<Vec<_>>();
        let snapshot = windows_clang::extract(
            [
                Input::new(AGGREGATE_INPUT, format!("{prelude}\n#include <mmreg.h>\n"))
                    .with_roots([path_arg(&mmreg, "--include").unwrap()]),
                Input::new(
                    SATELLITE_INPUT,
                    format!("{prelude}\n#include <mmreg.h>\n#include <Vfw.h>\n"),
                )
                .with_roots([path_arg(&vfw, "--include").unwrap()]),
            ],
            &args,
        )
        .unwrap();
        let owner = RootPartition::new("Multimedia", "Windows.Win32.Media.Multimedia");
        let policy = HeaderPartitionPolicy::new()
            .with_traversed_header_for_input(
                AGGREGATE_INPUT,
                path_arg(&mmreg, "--include").unwrap(),
                owner.clone(),
            )
            .with_traversed_header_for_input(
                SATELLITE_INPUT,
                path_arg(&vfw, "--include").unwrap(),
                owner,
            );
        let references = BTreeMap::new();
        let excluded_types = snapshot
            .facts()
            .iter()
            .filter(|fact| !matches!(fact.data, FactData::Function { .. }))
            .map(|fact| fact.name.clone())
            .collect::<BTreeSet<_>>();
        let excluded_functions = snapshot
            .facts()
            .iter()
            .filter(|fact| matches!(fact.data, FactData::Function { .. }))
            .map(|fact| fact.name.clone())
            .collect::<BTreeSet<_>>();
        let excluded_constants = snapshot
            .constants()
            .iter()
            .filter(|constant| !["ICTYPE_AUDIO", "ICTYPE_VIDEO"].contains(&constant.name.as_str()))
            .map(|constant| constant.name.clone())
            .collect::<BTreeSet<_>>();
        let mut emit = EmitOptions::new(DEFAULT_NAMESPACE, &references);
        emit.library = Some("");
        emit.excluded_types = Some(&excluded_types);
        emit.excluded_functions = Some(&excluded_functions);
        emit.excluded_constants = Some(&excluded_constants);
        let output = plan_header_partitions(
            &snapshot,
            &policy,
            &NamespaceAuthorities::new(),
            &emit,
            "x64",
        )
        .unwrap()
        .into_values()
        .collect::<String>();

        assert_eq!(output.matches("const ICTYPE_AUDIO").count(), 1, "{output}");
        assert_eq!(output.matches("const ICTYPE_VIDEO").count(), 1, "{output}");
    }

    #[test]
    fn checked_in_shared_header_overrides_match_legacy_owners() {
        ensure_libclang();
        let win_sdk = checked_in_win_sdk();
        let root = scratch("shared-header-overrides");
        let shared = root.join("shared");
        let um = root.join("um");
        std::fs::create_dir_all(&shared).unwrap();
        std::fs::create_dir_all(&um).unwrap();
        let write = |directory: &Path, name: &str, contents: &str| {
            let path = directory.join(name);
            std::fs::write(&path, contents).unwrap();
            path
        };
        let ntddstor = write(
            &shared,
            "ntddstor.h",
            "enum STORAGE_BUS_TYPE { BusTypeUnknown };\n\
             enum STORAGE_PROPERTY_ID { StorageDeviceProperty };\n",
        );
        let audioendpoints = write(
            &um,
            "audioendpoints.h",
            "struct IAudioEndpointFormatControl { int value; };\n\
             #define ENDPOINT_FORMAT_RESET_MIX_ONLY 1\n",
        );
        let endpointvolume = write(
            &um,
            "endpointvolume.h",
            "struct AUDIO_VOLUME_NOTIFICATION_DATA { int value; };\n\
             struct IAudioEndpointVolume { int value; };\n\
             #define ENDPOINT_HARDWARE_SUPPORT_VOLUME 1\n\
             #define ENDPOINT_HARDWARE_SUPPORT_MUTE 2\n\
             #define ENDPOINT_HARDWARE_SUPPORT_METER 4\n",
        );
        let uuids = write(&shared, "uuids.h", "#define MEDIATYPE_Video 1\n");
        let olectl = write(
            &um,
            "olectl.h",
            "#define DISPID_READYSTATE 1\n\
             #define DISPID_READYSTATECHANGE 2\n\
             #define DISPID_AMBIENT_TRANSFERPRIORITY 3\n\
             #define DISPID_AMBIENT_CODEPAGE 4\n\
             #define DISPID_AMBIENT_CHARSET 5\n",
        );
        let idispids = write(
            &um,
            "idispids.h",
            "#define DISPID_READYSTATE 1\n\
             #define DISPID_READYSTATECHANGE 2\n\
             #define DISPID_AMBIENT_TRANSFERPRIORITY 3\n\
             #define DISPID_AMBIENT_CODEPAGE 4\n\
             #define DISPID_AMBIENT_CHARSET 5\n\
             #define DISPID_AMBIENT_OFFLINEIFNOTCONNECTED 6\n\
             #define DISPID_AMBIENT_SILENT 7\n",
        );
        let infotech = write(&um, "infotech.h", "#define E_NOTFOUND 0x8000100D\n");
        let mmdeviceapi = write(&um, "mmdeviceapi.h", "#define E_NOTFOUND 0x80070490\n");
        let devicetopology = write(&um, "devicetopology.h", "#define E_NOTFOUND 0x80070490\n");
        let xamlom = write(&um, "xamlOM.h", "#define E_NOTFOUND 0x80070490\n");
        let dxcore = write(
            &um,
            "dxcore.h",
            "struct IDXCoreAdapterFactory { int value; };\n\
             extern \"C\" int DXCoreCreateAdapterFactory();\n",
        );
        let dxcore_interface = write(
            &um,
            "dxcore_interface.h",
            "struct IDXCoreAdapter { int value; };\n",
        );
        let include =
            |path: &Path| format!("#include \"{}\"\n", path_arg(path, "--include").unwrap());
        let aggregate_source = format!(
            "{}{}{}{}{}{}{}{}",
            include(&audioendpoints),
            include(&uuids),
            include(&olectl),
            include(&idispids),
            include(&infotech),
            include(&mmdeviceapi),
            include(&dxcore),
            include(&dxcore_interface),
        );
        let satellite_source = format!(
            "{}{}{}{}",
            include(&ntddstor),
            include(&endpointvolume),
            include(&devicetopology),
            include(&xamlom),
        );
        let snapshot = windows_clang::extract(
            [
                Input::new(AGGREGATE_INPUT, aggregate_source).with_roots(
                    [
                        &audioendpoints,
                        &uuids,
                        &olectl,
                        &idispids,
                        &infotech,
                        &mmdeviceapi,
                        &dxcore,
                        &dxcore_interface,
                    ]
                    .map(|path| path_arg(path, "--include").unwrap()),
                ),
                Input::new(SATELLITE_INPUT, satellite_source).with_roots(
                    [&ntddstor, &endpointvolume, &devicetopology, &xamlom]
                        .map(|path| path_arg(path, "--include").unwrap()),
                ),
            ],
            &["-x", "c++", "--target=x86_64-pc-windows-msvc"],
        )
        .unwrap();
        let traversal = checked_in_traversal_policy();
        let owner =
            |identity| convert_root_partition(logical_partition(&traversal, identity).unwrap());
        let header = |path: &Path| path_arg(path, "--partition-policy-root").unwrap();
        let mut policy = HeaderPartitionPolicy::new()
            .with_traversed_header_for_input(SATELLITE_INPUT, header(&ntddstor), owner("Ioctl"))
            .with_traversed_header_override_for_input(
                SATELLITE_INPUT,
                header(&ntddstor),
                "STORAGE_BUS_TYPE",
                owner("Fs"),
            )
            .with_traversed_header_for_input(
                AGGREGATE_INPUT,
                header(&audioendpoints),
                owner("Audio.Endpoints"),
            )
            .with_traversed_header_override_for_input(
                AGGREGATE_INPUT,
                header(&audioendpoints),
                "ENDPOINT_FORMAT_RESET_MIX_ONLY",
                owner("Audio"),
            )
            .with_traversed_header_for_input(
                SATELLITE_INPUT,
                header(&endpointvolume),
                owner("Audio.Endpoints"),
            );
        for name in [
            "AUDIO_VOLUME_NOTIFICATION_DATA",
            "ENDPOINT_HARDWARE_SUPPORT_VOLUME",
            "ENDPOINT_HARDWARE_SUPPORT_MUTE",
            "ENDPOINT_HARDWARE_SUPPORT_METER",
        ] {
            policy.add_traversed_header_override_for_input(
                SATELLITE_INPUT,
                header(&endpointvolume),
                name,
                owner("Audio"),
            );
        }
        for (path, identity) in [
            (&uuids, "Mf"),
            (&olectl, "ComOle"),
            (&idispids, "InternetExplorer"),
            (&infotech, "HtmlHelp"),
            (&dxcore, "DXCore"),
            (&dxcore_interface, "DXCore"),
        ] {
            policy.add_traversed_header_for_input(AGGREGATE_INPUT, header(path), owner(identity));
        }
        for (path, identity) in [
            (&mmdeviceapi, "Audio"),
            (&devicetopology, "Audio"),
            (&xamlom, "Xaml_Diagnostics"),
        ] {
            let input = if path == &mmdeviceapi {
                AGGREGATE_INPUT
            } else {
                SATELLITE_INPUT
            };
            policy.add_traversed_header_for_input(input, header(path), owner(identity));
            policy.add_traversed_header_override_for_input(
                input,
                header(path),
                "E_NOTFOUND",
                owner(identity).with_exclusion("E_NOTFOUND"),
            );
        }
        let references = BTreeMap::new();
        let mut emit = EmitOptions::new(DEFAULT_NAMESPACE, &references);
        emit.library = Some("");
        let authorities = crate::namespace_routes::NamespaceRoutes::load(
            &win_sdk.join("requiredNamespacesForNames.rsp"),
        )
        .unwrap()
        .authorities();
        let partitions =
            plan_header_partitions(&snapshot, &policy, &authorities, &emit, "x64").unwrap();
        let namespace_output = |namespace: &str| {
            partitions
                .iter()
                .filter(|(partition, _)| partition.namespace == namespace)
                .map(|(_, rdl)| rdl.as_str())
                .collect::<String>()
        };

        let file_system = namespace_output("Windows.Win32.Storage.FileSystem");
        let ioctl = namespace_output("Windows.Win32.System.Ioctl");
        assert!(file_system.contains("STORAGE_BUS_TYPE"), "{file_system}");
        assert!(!ioctl.contains("STORAGE_BUS_TYPE"), "{ioctl}");
        assert!(ioctl.contains("STORAGE_PROPERTY_ID"), "{ioctl}");

        let audio = namespace_output("Windows.Win32.Media.Audio");
        let endpoints = namespace_output("Windows.Win32.Media.Audio.Endpoints");
        assert!(
            audio.contains("const ENDPOINT_FORMAT_RESET_MIX_ONLY"),
            "{audio}"
        );
        assert!(
            endpoints.contains("IAudioEndpointFormatControl"),
            "{endpoints}"
        );
        assert!(audio.contains("AUDIO_VOLUME_NOTIFICATION_DATA"), "{audio}");
        for name in [
            "ENDPOINT_HARDWARE_SUPPORT_VOLUME",
            "ENDPOINT_HARDWARE_SUPPORT_MUTE",
            "ENDPOINT_HARDWARE_SUPPORT_METER",
        ] {
            assert!(audio.contains(&format!("const {name}")), "{audio}");
        }
        assert!(endpoints.contains("IAudioEndpointVolume"), "{endpoints}");

        let media_foundation = namespace_output("Windows.Win32.Media.MediaFoundation");
        assert!(
            media_foundation.contains("MEDIATYPE_Video"),
            "{media_foundation}"
        );
        let media = namespace_output("Windows.Win32.Media");
        assert!(!media.contains("MEDIATYPE_Video"), "{media}");

        let internet_explorer = namespace_output("Windows.Win32.Web.InternetExplorer");
        for name in [
            "DISPID_AMBIENT_OFFLINEIFNOTCONNECTED",
            "DISPID_AMBIENT_SILENT",
        ] {
            assert!(
                internet_explorer.contains(&format!("const {name}")),
                "{internet_explorer}"
            );
        }
        for name in [
            "DISPID_READYSTATE",
            "DISPID_READYSTATECHANGE",
            "DISPID_AMBIENT_TRANSFERPRIORITY",
            "DISPID_AMBIENT_CODEPAGE",
            "DISPID_AMBIENT_CHARSET",
        ] {
            assert!(
                !internet_explorer.contains(&format!("const {name}")),
                "{internet_explorer}"
            );
        }
        let ole = namespace_output("Windows.Win32.System.Ole");
        assert!(ole.contains("const DISPID_READYSTATE"), "{ole}");

        let html_help = namespace_output("Windows.Win32.Data.HtmlHelp");
        assert!(html_help.contains("const E_NOTFOUND"), "{html_help}");
        assert!(!audio.contains("const E_NOTFOUND"), "{audio}");
        let xaml_diagnostics = namespace_output("Windows.Win32.UI.Xaml.Diagnostics");
        assert!(
            !xaml_diagnostics.contains("const E_NOTFOUND"),
            "{xaml_diagnostics}"
        );
        assert_eq!(
            partitions
                .values()
                .map(|rdl| rdl.matches("const E_NOTFOUND").count())
                .sum::<usize>(),
            1
        );

        let dxcore_output = namespace_output("Windows.Win32.Graphics.DXCore");
        assert!(
            dxcore_output.contains("IDXCoreAdapterFactory"),
            "{dxcore_output}"
        );
        assert!(
            dxcore_output.contains("fn DXCoreCreateAdapterFactory("),
            "{dxcore_output}"
        );
        let display = namespace_output("Windows.Win32.Devices.Display");
        assert!(!display.contains("IDXCoreAdapterFactory"), "{display}");
        assert!(!display.contains("DXCoreCreateAdapterFactory"), "{display}");
    }

    #[test]
    fn checked_in_first_include_macros_materialize_expected_declarations() {
        ensure_libclang();
        let win_sdk = checked_in_win_sdk();
        let include_dirs = checked_in_include_dirs(&win_sdk);
        let find_header = |name: &str| {
            include_dirs
                .iter()
                .map(|directory| directory.join(name))
                .find(|path| path.is_file())
                .unwrap_or_else(|| panic!("missing checked-in header `{name}`"))
        };
        let winconp = find_header("winconp.h");
        let consoleapis = find_header("consoleapis.h");
        let wsman = find_header("wsman.h");
        let gdipluseffects = find_header("gdipluseffects.h");
        let source = format!(
            "#define FE_IME\n\
             #define DEFINE_CONSOLEV2_PROPERTIES\n\
             #define WSMAN_API_VERSION_1_1\n\
             #define GDIPVER 0x0110\n\
             {WIN32_SDK_PRELUDE}\n\
             #include <propkeydef.h>\n\
             #include <wincon.h>\n\
             #include <winconp.h>\n\
             #include <consoleapi.h>\n\
             #include <consoleapi2.h>\n\
             #include <consoleapi3.h>\n\
             #include <consoleapis.h>\n\
             #include <wincontypes.h>\n\
             #undef DEFINE_CONSOLEV2_PROPERTIES\n\
             #undef FE_IME\n\
             #include <wsman.h>\n\
             #undef WSMAN_API_VERSION_1_1\n\
             #include <gdiplus.h>\n\
             #undef GDIPVER\n"
        );
        let args = checked_in_clang_args(&include_dirs);
        let args = args.iter().map(String::as_str).collect::<Vec<_>>();
        let snapshot = windows_clang::extract(
            [Input::new(AGGREGATE_INPUT, source).with_roots(
                [&winconp, &consoleapis, &wsman, &gdipluseffects]
                    .map(|path| path_arg(path, "--include").unwrap()),
            )],
            &args,
        )
        .unwrap();
        let names = snapshot
            .facts()
            .iter()
            .map(|fact| fact.name.as_str())
            .collect::<BTreeSet<_>>();
        for name in [
            "RegisterConsoleIME",
            "UnregisterConsoleIME",
            "ConsoleControl",
            "WSMAN_CONNECT_DATA",
            "WSManCreateShellEx",
            "WSManDisconnectShell",
            "GdipCreateEffect",
        ] {
            assert!(names.contains(name), "missing `{name}`");
        }
    }

    #[test]
    fn checked_in_kernel_root_materializes_after_user_mode_headers() {
        ensure_libclang();
        let win_sdk = checked_in_win_sdk();
        let include_dirs = checked_in_include_dirs(&win_sdk);
        let ntdef = include_dirs
            .iter()
            .map(|directory| directory.join("ntdef.h"))
            .find(|path| path.is_file())
            .expect("missing checked-in ntdef.h");
        let mut source = format!(
            "{WIN32_SDK_PRELUDE}\n\
             #define PIO_APC_ROUTINE_DEFINED\n\
             #include <winternl.h>\n\
             #undef PIO_APC_ROUTINE_DEFINED\n\
             #define _NTDEF_\n"
        );
        crate::aggregate::append_kernel_input(&mut source, &ntdef).unwrap();
        let args = checked_in_clang_args(&include_dirs);
        let args = args.iter().map(String::as_str).collect::<Vec<_>>();
        let snapshot = windows_clang::extract(
            [Input::new(AGGREGATE_INPUT, source)
                .with_roots([path_arg(&ntdef, "--include").unwrap()])],
            &args,
        )
        .unwrap();
        let ntdef = path_arg(&ntdef, "--include").unwrap();
        let names = snapshot
            .facts()
            .iter()
            .filter(|fact| {
                source_path_matches(&ntdef, &fact.expansion.file)
                    || source_path_matches(&ntdef, &fact.spelling.file)
            })
            .map(|fact| fact.name.as_str())
            .collect::<BTreeSet<_>>();
        for name in ["KIRQL", "NT_PRODUCT_TYPE"] {
            assert!(names.contains(name), "missing `{name}` from ntdef.h");
        }
        for duplicate in ["PROCESSOR_NUMBER", "GROUP_AFFINITY"] {
            assert!(
                !names.contains(duplicate),
                "ntdef.h retained winnt-shared duplicate `{duplicate}`"
            );
        }

        let traversal = checked_in_traversal_policy();
        let mut policy = HeaderPartitionPolicy::new().with_traversed_header_for_input(
            AGGREGATE_INPUT,
            ntdef.clone(),
            convert_root_partition(logical_partition(&traversal, "Kernel").unwrap()),
        );
        let dependency = RootPartition::new("Dependency", "Windows.Win32.Foundation");
        let dependency_headers = snapshot
            .facts()
            .iter()
            .map(|fact| fact.spelling.file.as_str())
            .chain(
                snapshot
                    .constants()
                    .iter()
                    .map(|constant| constant.spelling.file.as_str()),
            )
            .filter(|path| !source_path_matches(&ntdef, path))
            .filter(|path| Path::new(path).is_file())
            .collect::<BTreeSet<_>>();
        for header in dependency_headers {
            policy.add_traversed_header_for_input(
                AGGREGATE_INPUT,
                header.to_string(),
                dependency.clone(),
            );
        }
        let references = MetadataReferences::new([windows_metadata::reader::File::new(
            windows_default::WINRT.to_vec(),
        )
        .unwrap()]);
        let mut emit = EmitOptions::new(DEFAULT_NAMESPACE, references.types());
        emit.library = Some("");
        let partitions = plan_header_partitions(
            &snapshot,
            &policy,
            &NamespaceAuthorities::new(),
            &emit,
            "x64",
        )
        .unwrap();
        let kernel = partitions
            .iter()
            .find(|(partition, _)| partition.partition == "Kernel")
            .unwrap()
            .1;
        for declaration in ["type KIRQL", "enum NT_PRODUCT_TYPE"] {
            assert!(
                kernel.contains(declaration),
                "Kernel output did not contain `{declaration}`:\n{kernel}"
            );
        }
        for duplicate in ["PROCESSOR_NUMBER", "GROUP_AFFINITY"] {
            assert!(
                !kernel.contains(duplicate),
                "Kernel output retained duplicate `{duplicate}`:\n{kernel}"
            );
        }
    }

    #[test]
    fn checked_in_historical_computed_constants_still_emit() {
        ensure_libclang();
        let win_sdk = checked_in_win_sdk();
        let include_dirs = checked_in_include_dirs(&win_sdk);
        let find_header = |name: &str| {
            include_dirs
                .iter()
                .map(|directory| directory.join(name))
                .find(|path| path.is_file())
                .unwrap_or_else(|| panic!("missing checked-in header `{name}`"))
        };
        let winnt = find_header("winnt.h");
        let mmddk = find_header("mmddk.h");
        let mciapi = find_header("mciapi.h");
        let source = format!(
            "#define MMNOJOYDEV\n{WIN32_SDK_PRELUDE}\n\
             #include <mmddk.h>\n\
             #include <mciapi.h>\n\
             #undef MMNOJOYDEV\n"
        );
        let args = checked_in_clang_args(&include_dirs);
        let args = args.iter().map(String::as_str).collect::<Vec<_>>();
        let snapshot = windows_clang::extract(
            [Input::new(SATELLITE_INPUT, source).with_roots(
                [&winnt, &mmddk, &mciapi].map(|path| path_arg(path, "--include").unwrap()),
            )],
            &args,
        )
        .unwrap();
        let selected = BTreeSet::from([
            "WAVE_FORMAT_PCM_S",
            "MCIERR_INVALID_DEVICE_ID",
            "TOKEN_ALL_ACCESS",
            "KEY_ALL_ACCESS",
            "PROCESS_ALL_ACCESS",
        ]);
        let traversal = checked_in_traversal_policy();
        let header = |path: &Path| path_arg(path, "--partition-policy-root").unwrap();
        let policy = HeaderPartitionPolicy::new()
            .with_traversed_header_for_input(
                SATELLITE_INPUT,
                header(&winnt),
                convert_root_partition(logical_partition(&traversal, "Foundation").unwrap()),
            )
            .with_traversed_header_for_input(
                SATELLITE_INPUT,
                header(&mmddk),
                convert_root_partition(logical_partition(&traversal, "Multimedia").unwrap()),
            )
            .with_traversed_header_for_input(
                SATELLITE_INPUT,
                header(&mciapi),
                convert_root_partition(logical_partition(&traversal, "Multimedia").unwrap()),
            );
        let excluded_types = snapshot
            .facts()
            .iter()
            .map(|fact| fact.name.clone())
            .collect::<BTreeSet<_>>();
        let excluded_constants = snapshot
            .constants()
            .iter()
            .filter(|constant| !selected.contains(constant.name.as_str()))
            .map(|constant| constant.name.clone())
            .collect::<BTreeSet<_>>();
        let references = BTreeMap::new();
        let functions = BTreeSet::new();
        let mut emit = EmitOptions::new(DEFAULT_NAMESPACE, &references);
        emit.library = Some("");
        emit.functions = Some(&functions);
        emit.excluded_types = Some(&excluded_types);
        emit.excluded_constants = Some(&excluded_constants);
        let authorities = crate::namespace_routes::NamespaceRoutes::load(
            &win_sdk.join("requiredNamespacesForNames.rsp"),
        )
        .unwrap()
        .authorities();
        let output = plan_header_partitions(&snapshot, &policy, &authorities, &emit, "x64")
            .unwrap()
            .into_values()
            .collect::<String>();
        for name in selected {
            assert_eq!(
                output.matches(&format!("const {name}")).count(),
                1,
                "{output}"
            );
        }
    }

    #[test]
    fn checked_in_wininet_duplicate_callback_uses_public_header_owner() {
        ensure_libclang();
        let win_sdk = checked_in_win_sdk();
        let include_dirs = checked_in_include_dirs(&win_sdk);
        let traversal = checked_in_traversal_policy();
        let partition = logical_partition(&traversal, "WinInet").unwrap();
        let root = |label: &str| {
            partition
                .roots
                .iter()
                .find_map(|root| match root {
                    crate::partition::TraversalRoot::File(root)
                        if root.inventory_path.eq_ignore_ascii_case(label) =>
                    {
                        Some(&root.path)
                    }
                    _ => None,
                })
                .unwrap_or_else(|| panic!("WinInet did not contain `{label}`"))
        };
        let public = path_arg(root("um/wininet.h"), "--partition-policy-root").unwrap();
        let internal = path_arg(root("um/winineti.h"), "--partition-policy-root").unwrap();
        let source =
            format!("{WIN32_SDK_PRELUDE}\n#include \"{public}\"\n#include \"{internal}\"\n");
        let args = checked_in_clang_args(&include_dirs);
        let args = args.iter().map(String::as_str).collect::<Vec<_>>();
        let snapshot = windows_clang::extract(
            [Input::new(AGGREGATE_INPUT, source).with_roots([public.clone(), internal.clone()])],
            &args,
        )
        .unwrap();
        let owner = convert_root_partition(partition);
        let mut policy = HeaderPartitionPolicy::new()
            .with_traversed_header_for_input(AGGREGATE_INPUT, public.clone(), owner.clone())
            .with_traversed_header_for_input(AGGREGATE_INPUT, internal.clone(), owner.clone())
            .with_traversed_header_override_for_input(
                AGGREGATE_INPUT,
                internal.clone(),
                "PFN_DIAL_HANDLER",
                owner.with_exclusion("PFN_DIAL_HANDLER"),
            );
        let dependency = RootPartition::new("Dependency", "Windows.Win32.Foundation");
        let dependency_headers = snapshot
            .facts()
            .iter()
            .map(|fact| fact.spelling.file.as_str())
            .chain(
                snapshot
                    .constants()
                    .iter()
                    .map(|constant| constant.spelling.file.as_str()),
            )
            .filter(|path| {
                !source_path_matches(&public, path) && !source_path_matches(&internal, path)
            })
            .filter(|path| Path::new(path).is_file())
            .collect::<BTreeSet<_>>();
        for dependency_header in dependency_headers {
            policy.add_traversed_header_for_input(
                AGGREGATE_INPUT,
                dependency_header.to_string(),
                dependency.clone(),
            );
        }
        let references = MetadataReferences::new([windows_metadata::reader::File::new(
            windows_default::WINRT.to_vec(),
        )
        .unwrap()]);
        let excluded_types = snapshot
            .facts()
            .iter()
            .filter(|fact| fact.name != "PFN_DIAL_HANDLER")
            .map(|fact| fact.name.clone())
            .collect::<BTreeSet<_>>();
        let excluded_constants = snapshot
            .constants()
            .iter()
            .map(|constant| constant.name.clone())
            .collect::<BTreeSet<_>>();
        let functions = BTreeSet::new();
        let mut emit = EmitOptions::new(DEFAULT_NAMESPACE, references.types());
        emit.library = Some("");
        emit.functions = Some(&functions);
        emit.excluded_types = Some(&excluded_types);
        emit.excluded_constants = Some(&excluded_constants);
        let partitions = plan_header_partitions(
            &snapshot,
            &policy,
            &NamespaceAuthorities::new(),
            &emit,
            "x64",
        )
        .unwrap();
        let output = partitions
            .iter()
            .filter(|(emitted, _)| emitted.namespace == "Windows.Win32.Networking.WinInet")
            .map(|(_, rdl)| rdl.as_str())
            .collect::<String>();
        assert_eq!(
            output.matches("extern fn PFN_DIAL_HANDLER").count(),
            1,
            "{output}"
        );
    }

    #[test]
    fn checked_in_numeric_logical_namespace_matches_old_71_emission() {
        ensure_libclang();
        let win_sdk = checked_in_win_sdk();
        let include_dirs = checked_in_include_dirs(&win_sdk);
        let traversal = checked_in_traversal_policy();
        let partition = logical_partition(&traversal, "Devices.1394").unwrap();
        let [crate::partition::TraversalRoot::File(root)] = partition.roots.as_slice() else {
            panic!("Devices.1394 did not have one physical file root");
        };
        let header = path_arg(&root.path, "--partition-policy-root").unwrap();
        let source = format!("{WIN32_SDK_PRELUDE}\n#include \"{header}\"\n");
        let args = checked_in_clang_args(&include_dirs);
        let args = args.iter().map(String::as_str).collect::<Vec<_>>();
        let snapshot = windows_clang::extract(
            [Input::new(AGGREGATE_INPUT, source).with_roots([header.clone()])],
            &args,
        )
        .unwrap();
        let mut policy = HeaderPartitionPolicy::new().with_traversed_header_for_input(
            AGGREGATE_INPUT,
            header.clone(),
            convert_root_partition(partition),
        );
        let dependency = RootPartition::new("Dependency", "Windows.Win32.Foundation");
        let dependency_headers = snapshot
            .facts()
            .iter()
            .map(|fact| fact.spelling.file.as_str())
            .chain(
                snapshot
                    .constants()
                    .iter()
                    .map(|constant| constant.spelling.file.as_str()),
            )
            .filter(|path| !source_path_matches(&header, path))
            .filter(|path| Path::new(path).is_file())
            .collect::<BTreeSet<_>>();
        for dependency_header in dependency_headers {
            policy.add_traversed_header_for_input(
                AGGREGATE_INPUT,
                dependency_header.to_string(),
                dependency.clone(),
            );
        }
        let references = MetadataReferences::new([windows_metadata::reader::File::new(
            windows_default::WINRT.to_vec(),
        )
        .unwrap()]);
        let mut emit = EmitOptions::new(DEFAULT_NAMESPACE, references.types());
        emit.library = Some("");
        let partitions = plan_header_partitions(
            &snapshot,
            &policy,
            &NamespaceAuthorities::new(),
            &emit,
            "x64",
        )
        .unwrap();
        let (emitted, rdl) = partitions
            .iter()
            .find(|(emitted, _)| emitted.partition == "Devices.1394")
            .unwrap();
        assert_eq!(emitted.partition, "Devices.1394");
        assert_eq!(emitted.namespace, "Windows.Win32.Devices");
        for name in ["IEEE1394_VDEV_PNP_REQUEST", "IEEE1394_API_REQUEST"] {
            assert!(rdl.contains(name), "{rdl}");
        }
    }

    #[test]
    fn checked_in_logical_policy_conversion_preserves_every_owner_setting() {
        let traversal = checked_in_traversal_policy();
        assert_eq!(
            traversal
                .partitions
                .iter()
                .filter_map(|partition| {
                    let emitted = emitted_partition_namespace(partition);
                    (emitted != partition.policy.namespace.as_str()).then_some((
                        partition.identity.as_str(),
                        partition.policy.namespace.as_str(),
                        emitted,
                    ))
                })
                .collect::<Vec<_>>(),
            [(
                "Devices.1394",
                "Windows.Win32.Devices.1394",
                "Windows.Win32.Devices",
            )]
        );
        let headers = convert_header_partition_policy(&traversal).unwrap();
        let root_plan = build_authority_root_plan(&traversal).unwrap();
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
            let mut add = |path: &Path,
                           canonical_path: &crate::partition::WindowsPathIdentity,
                           inventory_path: &str| {
                let header = path_arg(path, "--partition-policy-root").unwrap();
                let input =
                    logical_policy_input(&root_plan, &partition.identity, canonical_path).unwrap();
                if let Some(contract) = HEADER_POLICY_OVERRIDE_CONTRACTS
                    .iter()
                    .find(|contract| contract.path.eq_ignore_ascii_case(inventory_path))
                {
                    if partition.identity == contract.default_partition {
                        expected.add_traversed_header_for_input(
                            input,
                            header.clone(),
                            owner.clone(),
                        );
                        for name in contract.excluded_names {
                            expected.add_traversed_header_override_for_input(
                                input,
                                header.clone(),
                                *name,
                                owner.clone().with_exclusion(*name),
                            );
                        }
                        for (name, override_owner) in contract.overrides {
                            expected.add_traversed_header_override_for_input(
                                input,
                                header.clone(),
                                *name,
                                convert_root_partition(
                                    logical_partition(&traversal, override_owner).unwrap(),
                                ),
                            );
                        }
                    }
                } else {
                    expected.add_traversed_header_for_input(input, header, owner.clone());
                }
            };
            for root in &partition.roots {
                match root {
                    crate::partition::TraversalRoot::File(root) => {
                        add(&root.path, &root.canonical_path, &root.inventory_path)
                    }
                    crate::partition::TraversalRoot::Directory(root) => {
                        for file in &root.files {
                            add(&file.path, &file.canonical_path, &file.inventory_path);
                        }
                    }
                    crate::partition::TraversalRoot::Missing(_)
                    | crate::partition::TraversalRoot::Unsupported(_) => {
                        panic!("checked-in traversal policy was not clean")
                    }
                }
            }
        }
        let psapi = logical_partition(&traversal, "PsApi1")
            .unwrap()
            .roots
            .iter()
            .find_map(|root| match root {
                crate::partition::TraversalRoot::File(root) => Some(&root.path),
                _ => None,
            })
            .unwrap();
        let psapi = path_arg(psapi, "--partition-policy-root").unwrap();
        let psapi_owner = convert_root_partition(logical_partition(&traversal, "PsApi1").unwrap());
        for name in PSAPI_V1_SYNTHESIZED_CONSTANTS {
            for input in [PSAPI_V1_INPUT, PSAPI_V2_INPUT] {
                expected.add_traversed_header_override_for_input(
                    input,
                    psapi.clone(),
                    *name,
                    psapi_owner.clone(),
                );
            }
        }
        assert_eq!(headers, expected);
    }

    #[test]
    fn checked_in_x3daudio_policy_preserves_sdk_surface() {
        let traversal = checked_in_traversal_policy();
        let xaudio2 = logical_partition(&traversal, "Xaudio2").unwrap();
        assert!(xaudio2.roots.iter().any(|root| {
            matches!(
                root,
                crate::partition::TraversalRoot::File(root)
                    if root.inventory_path.eq_ignore_ascii_case("um/x3daudio.h")
            )
        }));
        assert_eq!(
            xaudio2.policy.exclusions,
            BTreeSet::from(["CXAPOBase".to_string()])
        );
    }

    #[test]
    fn checked_in_x3daudio_emits_required_dependencies_in_default_namespace() {
        ensure_libclang();
        let win_sdk = checked_in_win_sdk();
        let include_dirs = checked_in_include_dirs(&win_sdk);
        let x3daudio = include_dirs
            .iter()
            .map(|directory| directory.join("x3daudio.h"))
            .find(|path| path.is_file())
            .unwrap();
        let args = checked_in_clang_args(&include_dirs);
        let args = args.iter().map(String::as_str).collect::<Vec<_>>();
        let header = path_arg(&x3daudio, "--include").unwrap();
        let snapshot = windows_clang::extract(
            [Input::new(
                AGGREGATE_INPUT,
                format!("#define _XM_NO_INTRINSICS_\n{WIN32_SDK_PRELUDE}\n#include <x3daudio.h>\n"),
            )
            .with_roots([header.clone()])],
            &args,
        )
        .unwrap();
        let traversal = checked_in_traversal_policy();
        let policy = HeaderPartitionPolicy::new().with_traversed_header_for_input(
            AGGREGATE_INPUT,
            header,
            convert_root_partition(logical_partition(&traversal, "Xaudio2").unwrap()),
        );
        let references = MetadataReferences::new([windows_metadata::reader::File::new(
            windows_default::WINRT.to_vec(),
        )
        .unwrap()]);
        assert!(!references.types().is_empty());
        let mut emit = EmitOptions::new(DEFAULT_NAMESPACE, references.types());
        emit.library = Some("");
        let partitions = plan_header_partitions(
            &snapshot,
            &policy,
            &NamespaceAuthorities::new(),
            &emit,
            "x64",
        )
        .unwrap();
        let xaudio2 = partitions
            .iter()
            .filter(|(partition, _)| partition.namespace == "Windows.Win32.Media.Audio.XAudio2")
            .map(|(_, rdl)| rdl.as_str())
            .collect::<String>();
        let dependencies = partitions
            .iter()
            .filter(|(partition, _)| partition.namespace == DEFAULT_NAMESPACE)
            .map(|(_, rdl)| rdl.as_str())
            .collect::<String>();

        for name in [
            "X3DAUDIO_HANDLE_BYTESIZE",
            "X3DAUDIO_PI",
            "X3DAUDIO_2PI",
            "X3DAUDIO_SPEED_OF_SOUND",
            "X3DAUDIO_CALCULATE_MATRIX",
            "X3DAUDIO_CALCULATE_DELAY",
            "X3DAUDIO_CALCULATE_LPF_DIRECT",
            "X3DAUDIO_CALCULATE_LPF_REVERB",
            "X3DAUDIO_CALCULATE_REVERB",
            "X3DAUDIO_CALCULATE_DOPPLER",
            "X3DAUDIO_CALCULATE_EMITTER_ANGLE",
            "X3DAUDIO_CALCULATE_ZEROCENTER",
            "X3DAUDIO_CALCULATE_REDIRECT_TO_LFE",
        ] {
            assert!(xaudio2.contains(&format!("const {name}")), "{xaudio2}");
        }
        for name in [
            "X3DAUDIO_VECTOR",
            "X3DAUDIO_DISTANCE_CURVE_POINT",
            "X3DAUDIO_DISTANCE_CURVE",
            "X3DAUDIO_CONE",
            "X3DAUDIO_LISTENER",
            "X3DAUDIO_EMITTER",
            "X3DAUDIO_DSP_SETTINGS",
            "X3DAudioInitialize",
            "X3DAudioCalculate",
        ] {
            assert!(xaudio2.contains(name), "{xaudio2}");
        }
        assert!(dependencies.contains("struct XMFLOAT3"), "{dependencies}");
        assert!(!xaudio2.contains("struct XMFLOAT3"), "{xaudio2}");
        for unrelated in ["struct XMFLOAT2", "struct XMFLOAT4", "fn XMVector"] {
            assert!(
                partitions.values().all(|rdl| !rdl.contains(unrelated)),
                "unrelated DirectXMath declaration `{unrelated}` was emitted"
            );
        }

        let root = scratch("x3daudio-default-namespace");
        let rdl_dir = root.join("rdl");
        std::fs::create_dir_all(&rdl_dir).unwrap();
        write_partitioned_rdl(&rdl_dir, partitions).unwrap();
        let winmd = root.join("X3DAudio.winmd");
        compile_inputs(&[rdl_dir], &[], "X3DAudio", None, &winmd).unwrap();
        let index = Index::read(&winmd).unwrap();
        index.expect(DEFAULT_NAMESPACE, "XMFLOAT3");
        index.expect("Windows.Win32.Media.Audio.XAudio2", "X3DAUDIO_LISTENER");
        index.expect("Windows.Win32.Media.Audio.XAudio2", "X3DAUDIO_EMITTER");
        std::fs::remove_dir_all(&root).unwrap();
    }

    #[test]
    fn checked_in_webauthn_verification_request_emits_reference_member() {
        use windows_metadata::Type;

        ensure_libclang();
        let win_sdk = checked_in_win_sdk();
        let include_dirs = checked_in_include_dirs(&win_sdk);
        let traversal = checked_in_traversal_policy();
        let partition = logical_partition(&traversal, "WebAuthn").unwrap();
        let headers = partition
            .roots
            .iter()
            .map(|root| match root {
                crate::partition::TraversalRoot::File(root) => {
                    path_arg(&root.path, "--include").unwrap()
                }
                _ => panic!("unexpected non-file WebAuthn traversal root"),
            })
            .collect::<Vec<_>>();
        let source = format!(
            "{WIN32_SDK_PRELUDE}\n\
             #include <webauthn.h>\n\
             #include <webauthnplugin.h>\n\
             #include <pluginauthenticator.h>\n"
        );
        let args = checked_in_clang_args(&include_dirs);
        let args = args.iter().map(String::as_str).collect::<Vec<_>>();
        let snapshot = windows_clang::extract(
            [Input::new(AGGREGATE_INPUT, source).with_roots(headers.clone())],
            &args,
        )
        .unwrap();
        let request = snapshot
            .facts()
            .iter()
            .find(|fact| fact.name == "_WEBAUTHN_PLUGIN_USER_VERIFICATION_REQUEST")
            .unwrap();
        let FactData::Record { fields, .. } = &request.data else {
            panic!(
                "verification request was not extracted as a record: {:?}",
                request.data
            );
        };
        assert_eq!(
            fields
                .iter()
                .map(|field| (field.offset, field.size, field.align))
                .collect::<Vec<_>>(),
            [(0, 8, 8), (64, 8, 8), (128, 8, 8), (192, 8, 8)]
        );

        let mut policy = HeaderPartitionPolicy::new();
        for header in headers {
            policy.add_traversed_header_for_input(
                AGGREGATE_INPUT,
                header,
                convert_root_partition(partition),
            );
        }
        let references = MetadataReferences::new([windows_metadata::reader::File::new(
            windows_default::WINRT.to_vec(),
        )
        .unwrap()]);
        let mut emit = EmitOptions::new(DEFAULT_NAMESPACE, references.types());
        emit.library = Some("");
        let partitions = plan_header_partitions(
            &snapshot,
            &policy,
            &NamespaceAuthorities::new(),
            &emit,
            "x64",
        )
        .unwrap();
        let root = scratch("webauthn-reference-member");
        let rdl_dir = root.join("rdl");
        std::fs::create_dir_all(&rdl_dir).unwrap();
        write_partitioned_rdl(&rdl_dir, partitions).unwrap();
        let winmd = root.join("WebAuthn.winmd");
        compile_inputs(&[rdl_dir], &[], "WebAuthn", None, &winmd).unwrap();
        let index = Index::read(&winmd).unwrap();
        let request = index
            .types()
            .find(|ty| {
                ty.namespace() == "Windows.Win32.Security.Authentication.WebAuthn"
                    && ty.name() == "WEBAUTHN_PLUGIN_USER_VERIFICATION_REQUEST"
            })
            .unwrap();
        assert_eq!(
            request
                .fields()
                .map(|field| field.name().to_string())
                .collect::<Vec<_>>(),
            [
                "hwnd",
                "rguidTransactionId",
                "pwszUsername",
                "pwszDisplayHint"
            ]
        );
        assert_eq!(
            request
                .fields()
                .find(|field| field.name() == "rguidTransactionId")
                .unwrap()
                .ty(),
            Type::PtrConst(Box::new(Type::value_named(DEFAULT_NAMESPACE, "GUID")), 1)
        );
        let options = index.expect(
            "Windows.Win32.Security.Authentication.WebAuthn",
            "WEBAUTHN_AUTHENTICATOR_GET_ASSERTION_OPTIONS",
        );
        assert_eq!(
            options
                .fields()
                .find(|field| field.name() == "ppwszCredentialHints")
                .unwrap()
                .ty(),
            Type::PtrMut(Box::new(Type::value_named(DEFAULT_NAMESPACE, "PCWSTR")), 1)
        );
        assert_eq!(
            index.expect(DEFAULT_NAMESPACE, "PCWSTR").underlying_type(),
            Some(Type::PtrConst(Box::new(Type::U16), 1))
        );
        std::fs::remove_dir_all(&root).unwrap();
    }

    #[test]
    fn checked_in_glu_opaque_classes_emit_with_pointer_apis() {
        use windows_metadata::Type;

        ensure_libclang();
        let win_sdk = checked_in_win_sdk();
        let include_dirs = checked_in_include_dirs(&win_sdk);
        let traversal = checked_in_traversal_policy();
        let partition = logical_partition(&traversal, "OpenGL").unwrap();
        let headers = partition
            .roots
            .iter()
            .map(|root| match root {
                crate::partition::TraversalRoot::File(root) => {
                    path_arg(&root.path, "--include").unwrap()
                }
                _ => panic!("unexpected non-file OpenGL traversal root"),
            })
            .collect::<Vec<_>>();
        let args = checked_in_clang_args(&include_dirs);
        let args = args.iter().map(String::as_str).collect::<Vec<_>>();
        let snapshot = windows_clang::extract(
            [Input::new(
                AGGREGATE_INPUT,
                format!("{WIN32_SDK_PRELUDE}\n#include <GL/gl.h>\n#include <GL/glu.h>\n"),
            )
            .with_roots(headers.clone())],
            &args,
        )
        .unwrap();
        let mut policy = HeaderPartitionPolicy::new();
        for header in headers {
            policy.add_traversed_header_for_input(
                AGGREGATE_INPUT,
                header,
                convert_root_partition(partition),
            );
        }
        let references = MetadataReferences::new([windows_metadata::reader::File::new(
            windows_default::WINRT.to_vec(),
        )
        .unwrap()]);
        let mut emit = EmitOptions::new(DEFAULT_NAMESPACE, references.types());
        emit.library = Some("");
        let partitions = plan_header_partitions(
            &snapshot,
            &policy,
            &NamespaceAuthorities::new(),
            &emit,
            "x64",
        )
        .unwrap();
        let root = scratch("glu-opaque-classes");
        let rdl_dir = root.join("rdl");
        std::fs::create_dir_all(&rdl_dir).unwrap();
        write_partitioned_rdl(&rdl_dir, partitions).unwrap();
        let winmd = root.join("OpenGL.winmd");
        compile_inputs(&[rdl_dir], &[], "OpenGL", None, &winmd).unwrap();
        let index = Index::read(&winmd).unwrap();
        let namespace = "Windows.Win32.Graphics.OpenGL";
        for (name, create, delete) in [
            ("GLUnurbs", "gluNewNurbsRenderer", "gluDeleteNurbsRenderer"),
            ("GLUquadric", "gluNewQuadric", "gluDeleteQuadric"),
            ("GLUtesselator", "gluNewTess", "gluDeleteTess"),
        ] {
            assert_eq!(index.expect(namespace, name).fields().count(), 0, "{name}");
            let pointer = Type::PtrMut(Box::new(Type::value_named(namespace, name)), 1);
            let Item::Fn(create) = index.expect_item(namespace, create) else {
                panic!("missing creation function `{create}`");
            };
            let signature = create.signature(&[]);
            assert_eq!(signature.return_type, pointer, "{name}");
            assert!(signature.types.is_empty(), "{name}");
            let Item::Fn(delete) = index.expect_item(namespace, delete) else {
                panic!("missing deletion function `{delete}`");
            };
            let signature = delete.signature(&[]);
            assert_eq!(signature.return_type, Type::Void, "{name}");
            assert_eq!(signature.types, [pointer], "{name}");
        }
        for (alias, name) in [
            ("GLUnurbsObj", "GLUnurbs"),
            ("GLUquadricObj", "GLUquadric"),
            ("GLUtesselatorObj", "GLUtesselator"),
            ("GLUtriangulatorObj", "GLUtesselator"),
        ] {
            assert_eq!(
                index.expect(namespace, alias).underlying_type(),
                Some(Type::value_named(namespace, name)),
                "{alias}"
            );
        }
        std::fs::remove_dir_all(&root).unwrap();
    }

    #[test]
    fn checked_in_clustering_records_emit_native_multiple_inheritance() {
        use windows_metadata::Type;

        ensure_libclang();
        let win_sdk = checked_in_win_sdk();
        let include_dirs = checked_in_include_dirs(&win_sdk);
        let traversal = checked_in_traversal_policy();
        let partition = logical_partition(&traversal, "MsCs").unwrap();
        let headers = partition
            .roots
            .iter()
            .map(|root| match root {
                crate::partition::TraversalRoot::File(root) => {
                    path_arg(&root.path, "--include").unwrap()
                }
                _ => panic!("unexpected non-file MsCs traversal root"),
            })
            .collect::<Vec<_>>();
        let args = checked_in_clang_args(&include_dirs);
        let args = args.iter().map(String::as_str).collect::<Vec<_>>();
        let snapshot = windows_clang::extract(
            [Input::new(
                AGGREGATE_INPUT,
                format!(
                    "{WIN32_SDK_PRELUDE}\n\
                     #define QCC_OS_GROUP_WINDOWS\n\
                     #include <resapi.h>\n\
                     #include <smbclnt.h>\n\
                     #include <cluadmex.h>\n\
                     #include <msclus.h>\n"
                ),
            )
            .with_roots(headers.clone())],
            &args,
        )
        .unwrap();
        let mut policy = HeaderPartitionPolicy::new();
        for header in headers {
            policy.add_traversed_header_for_input(
                AGGREGATE_INPUT,
                header,
                convert_root_partition(partition),
            );
        }
        let references = MetadataReferences::new([windows_metadata::reader::File::new(
            windows_default::WINRT.to_vec(),
        )
        .unwrap()]);
        let mut emit = EmitOptions::new(DEFAULT_NAMESPACE, references.types());
        emit.library = Some("");
        let partitions = plan_header_partitions(
            &snapshot,
            &policy,
            &NamespaceAuthorities::new(),
            &emit,
            "x64",
        )
        .unwrap();
        let root = scratch("clustering-native-inheritance");
        let rdl_dir = root.join("rdl");
        std::fs::create_dir_all(&rdl_dir).unwrap();
        write_partitioned_rdl(&rdl_dir, partitions).unwrap();
        let winmd = root.join("Clustering.winmd");
        compile_inputs(&[rdl_dir], &[], "Clustering", None, &winmd).unwrap();
        let index = Index::read(&winmd).unwrap();
        let namespace = "Windows.Win32.Networking.Clustering";
        for (name, base, base2) in [
            (
                "CLUSPROP_RESOURCE_CLASS_INFO",
                "CLUSPROP_VALUE",
                "CLUS_RESOURCE_CLASS_INFO",
            ),
            (
                "CLUSTER_SHARED_VOLUME_RENAME_INPUT",
                "CLUSTER_SHARED_VOLUME_RENAME_INPUT_VOLUME",
                "CLUSTER_SHARED_VOLUME_RENAME_INPUT_NAME",
            ),
            (
                "CLUSTER_SHARED_VOLUME_RENAME_GUID_INPUT",
                "CLUSTER_SHARED_VOLUME_RENAME_INPUT_VOLUME",
                "CLUSTER_SHARED_VOLUME_RENAME_INPUT_GUID_NAME",
            ),
            (
                "CLUSPROP_PARTITION_INFO",
                "CLUSPROP_VALUE",
                "CLUS_PARTITION_INFO",
            ),
            (
                "CLUSPROP_PARTITION_INFO_EX",
                "CLUSPROP_VALUE",
                "CLUS_PARTITION_INFO_EX",
            ),
            (
                "CLUSPROP_PARTITION_INFO_EX2",
                "CLUSPROP_PARTITION_INFO_EX",
                "CLUS_PARTITION_INFO_EX2",
            ),
            ("CLUSPROP_FTSET_INFO", "CLUSPROP_VALUE", "CLUS_FTSET_INFO"),
            (
                "CLUSPROP_SCSI_ADDRESS",
                "CLUSPROP_VALUE",
                "CLUS_SCSI_ADDRESS",
            ),
        ] {
            assert_eq!(
                index
                    .expect(namespace, name)
                    .fields()
                    .map(|field| (field.name(), field.ty()))
                    .collect::<Vec<_>>(),
                [
                    ("Base", Type::value_named(namespace, base)),
                    ("Base2", Type::value_named(namespace, base2)),
                ],
                "{name}"
            );
            assert_eq!(
                index
                    .expect(namespace, &format!("P{name}"))
                    .underlying_type(),
                Some(Type::PtrMut(
                    Box::new(Type::value_named(namespace, name)),
                    1
                )),
                "{name}"
            );
        }
        let buffer = index.expect(namespace, "CLUSPROP_BUFFER_HELPER");
        for (field, alias) in [
            ("pResourceClassInfoValue", "PCLUSPROP_RESOURCE_CLASS_INFO"),
            ("pScsiAddressValue", "PCLUSPROP_SCSI_ADDRESS"),
            ("pPartitionInfoValue", "PCLUSPROP_PARTITION_INFO"),
            ("pPartitionInfoValueEx", "PCLUSPROP_PARTITION_INFO_EX"),
            ("pPartitionInfoValueEx2", "PCLUSPROP_PARTITION_INFO_EX2"),
        ] {
            assert_eq!(
                buffer
                    .fields()
                    .find(|candidate| candidate.name() == field)
                    .unwrap()
                    .ty(),
                Type::value_named(namespace, alias),
                "{field}"
            );
        }
        assert_eq!(
            index
                .expect(namespace, "CLUSTER_BATCH_COMMAND")
                .fields()
                .find(|field| field.name() == "wzName")
                .unwrap()
                .ty(),
            Type::value_named(DEFAULT_NAMESPACE, "PCWSTR")
        );
        assert_eq!(
            index.expect(DEFAULT_NAMESPACE, "PCWSTR").underlying_type(),
            Some(Type::PtrConst(Box::new(Type::U16), 1))
        );
        for (name, provider_parameter) in [
            ("OpenClusterCryptProvider", 1),
            ("OpenClusterCryptProviderEx", 2),
            ("POPEN_CLUSTER_CRYPT_PROVIDER", 1),
            ("POPEN_CLUSTER_CRYPT_PROVIDEREX", 2),
        ] {
            let method = match index.expect_item(namespace, name) {
                Item::Fn(method) => method,
                Item::Type(delegate) => delegate
                    .methods()
                    .find(|method| method.name() == "Invoke")
                    .unwrap(),
                _ => panic!("missing function or callback `{name}`"),
            };
            assert_eq!(
                method.signature(&[]).types[provider_parameter],
                Type::value_named(DEFAULT_NAMESPACE, "PCSTR"),
                "{name}"
            );
        }
        index.expect(DEFAULT_NAMESPACE, "PCSTR");
        std::fs::remove_dir_all(&root).unwrap();
    }

    #[test]
    fn checked_in_compression_handles_preserve_public_pointer_abi() {
        use windows_metadata::Type;

        ensure_libclang();
        let win_sdk = checked_in_win_sdk();
        let include_dirs = checked_in_include_dirs(&win_sdk);
        let traversal = checked_in_traversal_policy();
        let partition = logical_partition(&traversal, "CmpApi").unwrap();
        let [crate::partition::TraversalRoot::File(root)] = partition.roots.as_slice() else {
            panic!("CmpApi did not have one physical file root");
        };
        let header = path_arg(&root.path, "--include").unwrap();
        let args = checked_in_clang_args(&include_dirs);
        let args = args.iter().map(String::as_str).collect::<Vec<_>>();
        let snapshot = windows_clang::extract(
            [Input::new(
                AGGREGATE_INPUT,
                format!("{WIN32_SDK_PRELUDE}\n#include <compressapi.h>\n"),
            )
            .with_roots([header.clone()])],
            &args,
        )
        .unwrap();
        let policy = HeaderPartitionPolicy::new().with_traversed_header_for_input(
            AGGREGATE_INPUT,
            header,
            convert_root_partition(partition),
        );
        let references = MetadataReferences::new([windows_metadata::reader::File::new(
            windows_default::WINRT.to_vec(),
        )
        .unwrap()]);
        let mut emit = EmitOptions::new(DEFAULT_NAMESPACE, references.types());
        emit.library = Some("");
        let partitions = plan_header_partitions(
            &snapshot,
            &policy,
            &NamespaceAuthorities::new(),
            &emit,
            "x64",
        )
        .unwrap();
        let root = scratch("compression-handle-abi");
        let rdl_dir = root.join("rdl");
        std::fs::create_dir_all(&rdl_dir).unwrap();
        write_partitioned_rdl(&rdl_dir, partitions).unwrap();
        let winmd = root.join("Compression.winmd");
        compile_inputs(&[rdl_dir], &[], "Compression", None, &winmd).unwrap();
        let index = Index::read(&winmd).unwrap();
        let namespace = "Windows.Win32.Storage.Compression";
        let handle = Type::value_named(namespace, "COMPRESSOR_HANDLE");
        assert_eq!(
            index
                .expect(namespace, "COMPRESSOR_HANDLE")
                .underlying_type(),
            Some(Type::PtrMut(Box::new(Type::Void), 1))
        );
        assert_eq!(
            index
                .expect(namespace, "DECOMPRESSOR_HANDLE")
                .underlying_type(),
            Some(handle.clone())
        );
        for name in ["PCOMPRESSOR_HANDLE", "PDECOMPRESSOR_HANDLE"] {
            assert_eq!(
                index.expect(namespace, name).underlying_type(),
                Some(Type::PtrMut(Box::new(handle.clone()), 1)),
                "{name}"
            );
        }
        for (name, parameter, alias) in [
            ("CreateCompressor", 2, "PCOMPRESSOR_HANDLE"),
            ("CreateDecompressor", 2, "PDECOMPRESSOR_HANDLE"),
            ("Compress", 0, "COMPRESSOR_HANDLE"),
            ("Decompress", 0, "DECOMPRESSOR_HANDLE"),
            ("CloseCompressor", 0, "COMPRESSOR_HANDLE"),
            ("CloseDecompressor", 0, "DECOMPRESSOR_HANDLE"),
        ] {
            let Item::Fn(method) = index.expect_item(namespace, name) else {
                panic!("missing function `{name}`");
            };
            assert_eq!(
                method.signature(&[]).types[parameter],
                Type::value_named(namespace, alias),
                "{name}"
            );
        }
        assert!(!index.types().any(|ty| ty.name() == "COMPRESSOR_HANDLE__"));
        std::fs::remove_dir_all(&root).unwrap();
    }

    #[test]
    fn checked_in_directwrite_font_axis_tags_emit_from_sdk() {
        use windows_metadata::Type;

        ensure_libclang();
        let win_sdk = checked_in_win_sdk();
        let include_dirs = checked_in_include_dirs(&win_sdk);
        let traversal = checked_in_traversal_policy();
        let partition = logical_partition(&traversal, "DirectWrite").unwrap();
        let headers = partition
            .roots
            .iter()
            .map(|root| match root {
                crate::partition::TraversalRoot::File(root) => {
                    path_arg(&root.path, "--include").unwrap()
                }
                _ => panic!("unexpected non-file DirectWrite traversal root"),
            })
            .collect::<Vec<_>>();
        let args = checked_in_clang_args(&include_dirs);
        let args = args.iter().map(String::as_str).collect::<Vec<_>>();
        let snapshot = windows_clang::extract(
            [Input::new(
                AGGREGATE_INPUT,
                format!(
                    "{WIN32_SDK_PRELUDE}\n\
                     #include <dcommon.h>\n\
                     #include <dwrite.h>\n\
                     #include <dwrite_1.h>\n\
                     #include <dwrite_3.h>\n\
                     #include <dwrite_2.h>\n"
                ),
            )
            .with_roots(headers.clone())],
            &args,
        )
        .unwrap();
        let mut policy = HeaderPartitionPolicy::new();
        for header in headers {
            policy.add_traversed_header_for_input(
                AGGREGATE_INPUT,
                header,
                convert_root_partition(partition),
            );
        }
        let references = MetadataReferences::new([windows_metadata::reader::File::new(
            windows_default::WINRT.to_vec(),
        )
        .unwrap()]);
        let mut emit = EmitOptions::new(DEFAULT_NAMESPACE, references.types());
        emit.library = Some("");
        let partitions = plan_header_partitions(
            &snapshot,
            &policy,
            &NamespaceAuthorities::new(),
            &emit,
            "x64",
        )
        .unwrap();
        let expected = [
            ("DWRITE_FONT_AXIS_TAG_WEIGHT", *b"wght"),
            ("DWRITE_FONT_AXIS_TAG_WIDTH", *b"wdth"),
            ("DWRITE_FONT_AXIS_TAG_SLANT", *b"slnt"),
            ("DWRITE_FONT_AXIS_TAG_OPTICAL_SIZE", *b"opsz"),
            ("DWRITE_FONT_AXIS_TAG_ITALIC", *b"ital"),
        ];
        for (name, tag) in expected {
            let declaration = format!("{name} = {}", u32::from_le_bytes(tag));
            assert!(
                partitions.values().any(|rdl| rdl.contains(&declaration)),
                "missing native tag value `{declaration}`"
            );
        }
        let root = scratch("directwrite-native-font-axis-tags");
        let rdl_dir = root.join("rdl");
        std::fs::create_dir_all(&rdl_dir).unwrap();
        write_partitioned_rdl(&rdl_dir, partitions).unwrap();
        let winmd = root.join("DirectWrite.winmd");
        compile_inputs(&[rdl_dir], &[], "DirectWrite", None, &winmd).unwrap();
        let index = Index::read(&winmd).unwrap();
        let namespace = "Windows.Win32.Graphics.DirectWrite";
        let tags = index.expect(namespace, "DWRITE_FONT_AXIS_TAG");
        assert_eq!(tags.underlying_type(), Some(Type::U32));
        for (name, _) in expected {
            assert!(tags.fields().any(|field| field.name() == name), "{name}");
        }
        for name in ["DWRITE_FONT_AXIS_VALUE", "DWRITE_FONT_AXIS_RANGE"] {
            assert_eq!(
                index
                    .expect(namespace, name)
                    .fields()
                    .find(|field| field.name() == "axisTag")
                    .unwrap()
                    .ty(),
                Type::value_named(namespace, "DWRITE_FONT_AXIS_TAG"),
                "{name}"
            );
        }
        std::fs::remove_dir_all(&root).unwrap();
    }

    #[test]
    fn checked_in_js_runtime_version_emits_from_sdk() {
        use windows_metadata::Type;

        ensure_libclang();
        let win_sdk = checked_in_win_sdk();
        let include_dirs = checked_in_include_dirs(&win_sdk);
        let traversal = checked_in_traversal_policy();
        let partition = logical_partition(&traversal, "Js").unwrap();
        let headers = partition
            .roots
            .iter()
            .map(|root| match root {
                crate::partition::TraversalRoot::File(root) => {
                    path_arg(&root.path, "--include").unwrap()
                }
                _ => panic!("unexpected non-file Js traversal root"),
            })
            .collect::<Vec<_>>();
        let args = checked_in_clang_args(&include_dirs);
        let args = args.iter().map(String::as_str).collect::<Vec<_>>();
        let snapshot = windows_clang::extract(
            [Input::new(
                AGGREGATE_INPUT,
                format!("{WIN32_SDK_PRELUDE}\n#include <jsrt.h>\n#include <jsrt9.h>\n"),
            )
            .with_roots(headers.clone())],
            &args,
        )
        .unwrap();
        let mut policy = HeaderPartitionPolicy::new();
        for header in headers {
            policy.add_traversed_header_for_input(
                AGGREGATE_INPUT,
                header,
                convert_root_partition(partition),
            );
        }
        let references = MetadataReferences::new([windows_metadata::reader::File::new(
            windows_default::WINRT.to_vec(),
        )
        .unwrap()]);
        let mut emit = EmitOptions::new(DEFAULT_NAMESPACE, references.types());
        emit.library = Some("");
        let partitions = plan_header_partitions(
            &snapshot,
            &policy,
            &NamespaceAuthorities::new(),
            &emit,
            "x64",
        )
        .unwrap();
        let root = scratch("js-native-runtime-version");
        let rdl_dir = root.join("rdl");
        std::fs::create_dir_all(&rdl_dir).unwrap();
        write_partitioned_rdl(&rdl_dir, partitions).unwrap();
        let winmd = root.join("Js.winmd");
        compile_inputs(&[rdl_dir], &[], "Js", None, &winmd).unwrap();
        let index = Index::read(&winmd).unwrap();
        let namespace = "Windows.Win32.System.Js";
        let version = index.expect(namespace, "JsRuntimeVersion");
        assert_eq!(version.underlying_type(), Some(Type::I32));
        for name in ["JsRuntimeVersion10", "JsRuntimeVersion11"] {
            assert!(version.fields().any(|field| field.name() == name), "{name}");
        }
        let Item::Fn(create) = index.expect_item(namespace, "JsCreateRuntime") else {
            panic!("missing JsCreateRuntime");
        };
        assert_eq!(
            create.signature(&[]).types[1],
            Type::value_named(namespace, "JsRuntimeVersion")
        );
        std::fs::remove_dir_all(&root).unwrap();
    }

    #[test]
    fn checked_in_com_context_interfaces_survive_early_includes() {
        ensure_libclang();
        let win_sdk = checked_in_win_sdk();
        let include_dirs = checked_in_include_dirs(&win_sdk);
        let objidlbase = include_dirs
            .iter()
            .map(|directory| directory.join("objidlbase.h"))
            .find(|path| path.is_file())
            .unwrap();
        let mut source = crate::aggregate::main_prefix(
            WIN32_SDK_PRELUDE,
            &win_sdk.join("Partitions/Com.StructuredStorage/manual.h"),
        )
        .unwrap();
        let end = source
            .find("#pragma pop_macro(\"NONAMELESSUNION\")")
            .unwrap()
            + "#pragma pop_macro(\"NONAMELESSUNION\")".len();
        source.truncate(end);
        let header = path_arg(&objidlbase, "--include").unwrap();
        let args = checked_in_clang_args(&include_dirs);
        let args = args.iter().map(String::as_str).collect::<Vec<_>>();
        let snapshot = windows_clang::extract(
            [Input::new(AGGREGATE_INPUT, source).with_roots([header.clone()])],
            &args,
        )
        .unwrap();
        let traversal = checked_in_traversal_policy();
        let policy = HeaderPartitionPolicy::new().with_traversed_header_for_input(
            AGGREGATE_INPUT,
            header,
            convert_root_partition(logical_partition(&traversal, "Com").unwrap()),
        );
        let references = MetadataReferences::new([windows_metadata::reader::File::new(
            windows_default::WINRT.to_vec(),
        )
        .unwrap()]);
        let mut emit = EmitOptions::new(DEFAULT_NAMESPACE, references.types());
        emit.library = Some("");
        let partitions = plan_header_partitions(
            &snapshot,
            &policy,
            &NamespaceAuthorities::new(),
            &emit,
            "x64",
        )
        .unwrap();
        let root = scratch("com-context-first-include");
        let rdl_dir = root.join("rdl");
        std::fs::create_dir_all(&rdl_dir).unwrap();
        write_partitioned_rdl(&rdl_dir, partitions).unwrap();
        let winmd = root.join("ComContext.winmd");
        compile_inputs(&[rdl_dir], &[], "ComContext", None, &winmd).unwrap();
        let index = Index::read(&winmd).unwrap();
        for (name, methods) in [
            (
                "IContext",
                &[
                    "SetProperty",
                    "RemoveProperty",
                    "GetProperty",
                    "EnumContextProps",
                ][..],
            ),
            (
                "IEnumContextProps",
                &["Next", "Skip", "Reset", "Clone", "Count"][..],
            ),
        ] {
            let interface = index.expect("Windows.Win32.System.Com", name);
            assert_eq!(
                interface
                    .methods()
                    .map(|method| method.name())
                    .collect::<Vec<_>>(),
                methods,
                "{name} must retain its full interface definition and method order"
            );
        }
        std::fs::remove_dir_all(&root).unwrap();
    }

    #[test]
    fn checked_in_ssl_callback_emits_native_array_parameter() {
        use windows_metadata::Type;

        ensure_libclang();
        let win_sdk = checked_in_win_sdk();
        let include_dirs = checked_in_include_dirs(&win_sdk);
        let sslprovider = include_dirs
            .iter()
            .map(|directory| directory.join("sslprovider.h"))
            .find(|path| path.is_file())
            .unwrap();
        let header = path_arg(&sslprovider, "--include").unwrap();
        let args = checked_in_clang_args(&include_dirs);
        let args = args.iter().map(String::as_str).collect::<Vec<_>>();
        let snapshot = windows_clang::extract(
            [Input::new(
                SATELLITE_INPUT,
                format!(
                    "{WIN32_SDK_PRELUDE}\n\
                     #include <bcrypt.h>\n\
                     #include <ncrypt.h>\n\
                     #include <sslprovider.h>\n"
                ),
            )
            .with_roots([header.clone()])],
            &args,
        )
        .unwrap();
        let traversal = checked_in_traversal_policy();
        let policy = HeaderPartitionPolicy::new().with_traversed_header_for_input(
            SATELLITE_INPUT,
            header,
            convert_root_partition(logical_partition(&traversal, "Security.Cryptography").unwrap()),
        );
        let references = MetadataReferences::new([windows_metadata::reader::File::new(
            windows_default::WINRT.to_vec(),
        )
        .unwrap()]);
        let mut emit = EmitOptions::new(DEFAULT_NAMESPACE, references.types());
        emit.library = Some("");
        let partitions = plan_header_partitions(
            &snapshot,
            &policy,
            &NamespaceAuthorities::new(),
            &emit,
            "x64",
        )
        .unwrap();
        let root = scratch("ssl-native-callback");
        let rdl_dir = root.join("rdl");
        std::fs::create_dir_all(&rdl_dir).unwrap();
        write_partitioned_rdl(&rdl_dir, partitions).unwrap();
        let winmd = root.join("SslProvider.winmd");
        compile_inputs(&[rdl_dir], &[], "SslProvider", None, &winmd).unwrap();
        let index = Index::read(&winmd).unwrap();
        let namespace = "Windows.Win32.Security.Cryptography";
        let callback = index.expect(namespace, "SslGetCipherSuitePRFHashAlgorithmFn");
        let invoke = callback
            .methods()
            .find(|method| method.name() == "Invoke")
            .unwrap();
        let signature = invoke.signature(&[]);
        assert_eq!(signature.types.len(), 6);
        assert_eq!(signature.types[4], Type::PtrMut(Box::new(Type::U16), 1));
        assert_eq!(
            index
                .expect(namespace, "NCRYPT_SSL_FUNCTION_TABLE")
                .fields()
                .find(|field| field.name() == "GetCipherSuitePRFHashAlgorithm")
                .unwrap()
                .ty(),
            Type::class_named(namespace, "SslGetCipherSuitePRFHashAlgorithmFn")
        );
        let Item::Fn(function) = index.expect_item(namespace, "SslGetCipherSuitePRFHashAlgorithm")
        else {
            panic!("missing SslGetCipherSuitePRFHashAlgorithm");
        };
        assert_eq!(function.signature(&[]).types, signature.types);
        assert_eq!(function.signature(&[]).return_type, signature.return_type);
        std::fs::remove_dir_all(&root).unwrap();
    }

    #[test]
    fn checked_in_ro_registration_cookie_preserves_native_pointer() {
        use windows_metadata::Type;

        with_checked_in_header_group(
            "ro-registration-cookie",
            AGGREGATE_INPUT,
            "#include <roapi.h>\n",
            &[("WinRT", &["roapi.h"])],
            &[
                "RoRegisterActivationFactories",
                "RoRevokeActivationFactories",
            ],
            |index| {
                let namespace = "Windows.Win32.System.WinRT";
                let record = "_RO_REGISTRATION_COOKIE";
                assert_eq!(index.expect(namespace, record).fields().count(), 0);
                assert_eq!(
                    index
                        .expect(namespace, "RO_REGISTRATION_COOKIE")
                        .underlying_type(),
                    Some(Type::PtrMut(
                        Box::new(Type::value_named(namespace, record)),
                        1
                    ))
                );
                for (name, parameter, ty) in [
                    (
                        "RoRegisterActivationFactories",
                        3,
                        Type::PtrMut(
                            Box::new(Type::value_named(namespace, "RO_REGISTRATION_COOKIE")),
                            1,
                        ),
                    ),
                    (
                        "RoRevokeActivationFactories",
                        0,
                        Type::value_named(namespace, "RO_REGISTRATION_COOKIE"),
                    ),
                ] {
                    let Item::Fn(method) = index.expect_item(namespace, name) else {
                        panic!("missing {name}");
                    };
                    assert_eq!(method.signature(&[]).types[parameter], ty, "{name}");
                }
            },
        );
    }

    #[test]
    fn checked_in_rpc_context_preserves_native_record_and_pointer() {
        use windows_metadata::Type;

        with_checked_in_header_group(
            "rpc-native-context",
            AGGREGATE_INPUT,
            "#include <rpc.h>\n#include <rpcndr.h>\n",
            &[("Rpc", &["rpcndr.h"])],
            &["NDRSContextMarshall", "NDRSContextUnmarshall"],
            |index| {
                let namespace = "Windows.Win32.System.Rpc";
                let record = index.expect(namespace, "_NDR_SCONTEXT");
                assert_eq!(
                    record
                        .fields()
                        .map(|field| field.name())
                        .collect::<Vec<_>>(),
                    ["pad", "userContext"]
                );
                assert_eq!(
                    record
                        .fields()
                        .find(|field| field.name() == "userContext")
                        .unwrap()
                        .ty(),
                    Type::PtrMut(Box::new(Type::Void), 1)
                );
                assert_eq!(
                    index.expect(namespace, "NDR_SCONTEXT").underlying_type(),
                    Some(Type::PtrMut(
                        Box::new(Type::value_named(namespace, "_NDR_SCONTEXT")),
                        1,
                    ))
                );
                let Item::Fn(marshal) = index.expect_item(namespace, "NDRSContextMarshall") else {
                    panic!("missing NDRSContextMarshall");
                };
                assert_eq!(
                    marshal.signature(&[]).types[0],
                    Type::value_named(namespace, "NDR_SCONTEXT")
                );
                let Item::Fn(unmarshal) = index.expect_item(namespace, "NDRSContextUnmarshall")
                else {
                    panic!("missing NDRSContextUnmarshall");
                };
                assert_eq!(
                    unmarshal.signature(&[]).return_type,
                    Type::value_named(namespace, "NDR_SCONTEXT")
                );
            },
        );
    }

    #[test]
    fn checked_in_winnt_retains_required_list_and_activation_types() {
        use windows_metadata::Type;

        with_checked_in_header_group(
            "winnt-required-records",
            AGGREGATE_INPUT,
            "#include <winnt.h>\n#include <threadpoolapiset.h>\n",
            &[
                ("Backup", &["winnt.h"]),
                ("Threading", &["threadpoolapiset.h"]),
            ],
            &[
                "CreateThreadpoolIo",
                "CreateThreadpoolTimer",
                "CreateThreadpoolWait",
                "CreateThreadpoolWork",
                "TrySubmitThreadpoolCallback",
            ],
            |index| {
                let namespace = "Windows.Win32.System.SystemServices";
                for (name, field_type) in [("LIST_ENTRY32", Type::U32), ("LIST_ENTRY64", Type::U64)]
                {
                    let record = index.expect(namespace, name);
                    assert_eq!(
                        record
                            .fields()
                            .map(|field| (field.name(), field.ty()))
                            .collect::<Vec<_>>(),
                        [("Flink", field_type.clone()), ("Blink", field_type)]
                    );
                    assert_eq!(
                        index
                            .expect(namespace, &format!("P{name}"))
                            .underlying_type(),
                        Some(Type::PtrMut(
                            Box::new(Type::value_named(namespace, name)),
                            1
                        ))
                    );
                }
                assert_eq!(
                    index
                        .expect(namespace, "_ACTIVATION_CONTEXT")
                        .fields()
                        .count(),
                    0
                );
                let environment = index.expect(namespace, "TP_CALLBACK_ENVIRON_V3");
                assert_eq!(
                    environment
                        .fields()
                        .find(|field| field.name() == "ActivationContext")
                        .unwrap()
                        .ty(),
                    Type::PtrMut(
                        Box::new(Type::value_named(namespace, "_ACTIVATION_CONTEXT")),
                        1
                    )
                );
            },
        );
    }

    #[test]
    fn checked_in_enclave_retains_required_callback_aliases() {
        use windows_metadata::Type;

        with_checked_in_header_group(
            "enclave-required-callback",
            AGGREGATE_INPUT,
            "#include <minwinbase.h>\n#include <enclaveapi.h>\n",
            &[("Base", &["minwinbase.h"]), ("Enclave", &["enclaveapi.h"])],
            &["CallEnclave"],
            |index| {
                let namespace = "Windows.Win32.System.SystemServices";
                let callback = index.expect(namespace, "PENCLAVE_ROUTINE");
                let invoke = callback
                    .methods()
                    .find(|method| method.name() == "Invoke")
                    .unwrap();
                assert_eq!(
                    index.expect(DEFAULT_NAMESPACE, "LPVOID").underlying_type(),
                    Some(Type::PtrMut(Box::new(Type::Void), 1))
                );
                assert_eq!(
                    invoke.signature(&[]).types,
                    [Type::value_named(DEFAULT_NAMESPACE, "LPVOID")]
                );
                assert_eq!(
                    invoke.signature(&[]).return_type,
                    Type::value_named(DEFAULT_NAMESPACE, "LPVOID")
                );
                assert_eq!(
                    index
                        .expect(namespace, "LPENCLAVE_ROUTINE")
                        .underlying_type(),
                    Some(Type::class_named(namespace, "PENCLAVE_ROUTINE"))
                );
                let Item::Fn(call) =
                    index.expect_item("Windows.Win32.System.Environment", "CallEnclave")
                else {
                    panic!("missing CallEnclave");
                };
                assert_eq!(
                    call.signature(&[]).types[0],
                    Type::value_named(namespace, "LPENCLAVE_ROUTINE")
                );
            },
        );
    }

    #[test]
    fn checked_in_sti_preserves_distinct_incomplete_alias_identity() {
        use windows_metadata::Type;

        with_checked_in_header_group(
            "sti-incomplete-alias",
            AGGREGATE_INPUT,
            "#include <sti.h>\n",
            &[("ImagingDevice", &["sti.h"])],
            &[],
            |index| {
                let namespace = "Windows.Win32.Devices.Fax";
                assert_eq!(index.expect(namespace, "IStiDeviceW").fields().count(), 0);
                assert_eq!(
                    index.expect(namespace, "PSTIDEVICEW").underlying_type(),
                    Some(Type::PtrMut(
                        Box::new(Type::value_named(namespace, "IStiDeviceW")),
                        1
                    ))
                );
                let device = index.expect(namespace, "IStiDevice");
                assert!(
                    device
                        .methods()
                        .any(|method| method.name() == "GetCapabilities")
                );
                assert!(
                    device
                        .methods()
                        .any(|method| method.name() == "GetLastErrorInfo")
                );
            },
        );
    }

    #[test]
    fn checked_in_debug_search_records_preserve_com_methods() {
        use windows_metadata::Type;

        with_checked_in_header_group(
            "debug-native-search-records",
            SATELLITE_INPUT,
            "#include <dbgeng.h>\n#include <DbgModel.h>\n",
            &[("Debug.Extensions", &["DbgModel.h"])],
            &[],
            |index| {
                let namespace = "Windows.Win32.System.Diagnostics.Debug.Extensions";
                assert_eq!(
                    index
                        .expect(namespace, "SymbolSearchInfo")
                        .fields()
                        .map(|field| (field.name(), field.ty()))
                        .collect::<Vec<_>>(),
                    [
                        ("HeaderSize", Type::U32),
                        ("InfoSize", Type::U32),
                        ("SearchOptions", Type::U32)
                    ]
                );
                assert_eq!(
                    index
                        .expect(namespace, "TypeSearchInfo")
                        .fields()
                        .find(|field| field.name() == "Base")
                        .unwrap()
                        .ty(),
                    Type::value_named(namespace, "SymbolSearchInfo")
                );
                let interface = index.expect(namespace, "IDebugHostSymbol2");
                let method = interface
                    .methods()
                    .find(|method| method.name() == "EnumerateChildrenEx")
                    .unwrap();
                assert_eq!(
                    method.signature(&[]).types[2],
                    Type::PtrMut(
                        Box::new(Type::value_named(namespace, "SymbolSearchInfo")),
                        1
                    )
                );
                assert_eq!(
                    interface
                        .methods()
                        .map(|method| method.name())
                        .collect::<Vec<_>>(),
                    ["EnumerateChildrenEx", "GetLanguage"]
                );
                assert_eq!(
                    index
                        .expect(namespace, "IDebugHostSymbol3")
                        .methods()
                        .map(|method| method.name())
                        .collect::<Vec<_>>(),
                    ["GetCompilerInformation"]
                );
            },
        );
    }

    #[test]
    fn checked_in_ntstatus_constants_resolve_native_owner_types() {
        use windows_metadata::Type;

        let win_sdk = checked_in_win_sdk();
        let ntdef = win_sdk
            .join("RecompiledIdlHeaders")
            .join("shared")
            .join("ntdef.h");
        let mut source = String::from(
            "#define PIO_APC_ROUTINE_DEFINED\n\
             #include <winternl.h>\n\
             #undef PIO_APC_ROUTINE_DEFINED\n\
             #include <winddi.h>\n\
             #define _NTDEF_\n",
        );
        crate::aggregate::append_kernel_input(&mut source, &ntdef).unwrap();
        with_checked_in_header_group(
            "ntstatus-native-owners",
            AGGREGATE_INPUT,
            &source,
            &[
                ("Foundation", &["ntstatus.h"]),
                ("WinProg", &["winternl.h"]),
                ("Display", &["winddi.h"]),
                ("Kernel", &["ntdef.h"]),
            ],
            &[],
            |index| {
                let namespace = "Windows.Win32.System.WindowsProgramming";
                assert_eq!(
                    index.expect(namespace, "NTSTATUS").underlying_type(),
                    Some(Type::I32)
                );
                for name in ["STATUS_SUCCESS", "STATUS_ACCESS_DENIED", "DBG_CONTINUE"] {
                    let Item::Const(field) = index.expect_item("Windows.Win32.Foundation", name)
                    else {
                        panic!("missing {name}");
                    };
                    assert_eq!(
                        field.ty(),
                        Type::value_named(namespace, "NTSTATUS"),
                        "{name}"
                    );
                }
            },
        );
    }

    fn with_checked_in_header_group(
        tag: &str,
        input: &str,
        includes: &str,
        groups: &[(&str, &[&str])],
        functions: &[&str],
        check: impl FnOnce(&Index),
    ) {
        ensure_libclang();
        let win_sdk = checked_in_win_sdk();
        let include_dirs = checked_in_include_dirs(&win_sdk);
        let traversal = checked_in_traversal_policy();
        let mut policy = HeaderPartitionPolicy::new();
        let mut roots = Vec::new();
        for (partition, headers) in groups {
            for name in *headers {
                let header = include_dirs
                    .iter()
                    .map(|directory| directory.join(name))
                    .find(|path| path.is_file())
                    .unwrap_or_else(|| panic!("missing checked-in header `{name}`"));
                let header = path_arg(&header, "--include").unwrap();
                policy.add_traversed_header_for_input(
                    input,
                    header.clone(),
                    convert_root_partition(logical_partition(&traversal, partition).unwrap()),
                );
                roots.push(header);
            }
        }
        let args = checked_in_clang_args(&include_dirs);
        let args = args.iter().map(String::as_str).collect::<Vec<_>>();
        let snapshot = windows_clang::extract(
            [Input::new(input, format!("{WIN32_SDK_PRELUDE}\n{includes}")).with_roots(roots)],
            &args,
        )
        .unwrap();
        let references = MetadataReferences::new([windows_metadata::reader::File::new(
            windows_default::WINRT.to_vec(),
        )
        .unwrap()]);
        let mut emit = EmitOptions::new(DEFAULT_NAMESPACE, references.types());
        emit.library = Some("");
        let functions = functions
            .iter()
            .map(|name| name.to_string())
            .collect::<BTreeSet<_>>();
        emit.functions = Some(&functions);
        let partitions = plan_header_partitions(
            &snapshot,
            &policy,
            &NamespaceAuthorities::new(),
            &emit,
            "x64",
        )
        .unwrap();
        let root = scratch(tag);
        let rdl_dir = root.join("rdl");
        std::fs::create_dir_all(&rdl_dir).unwrap();
        write_partitioned_rdl(&rdl_dir, partitions).unwrap();
        let winmd = root.join("HeaderGroup.winmd");
        compile_inputs(&[rdl_dir], &[], "HeaderGroup", None, &winmd).unwrap();
        check(&Index::read(&winmd).unwrap());
        std::fs::remove_dir_all(&root).unwrap();
    }

    #[test]
    fn aggregate_dependencies_report_independent_blockers_together() {
        ensure_libclang();
        let root = scratch("aggregate-dependency-blockers");
        let dependencies = root.join("dependencies.h");
        let public = root.join("public.h");
        std::fs::write(
            &dependencies,
            "class HiddenA { int secret; };\n\
             class HiddenB { int secret; };\n\
             struct Intermediate { HiddenA value; };\n",
        )
        .unwrap();
        std::fs::write(
            &public,
            "#include \"dependencies.h\"\n\
             struct PublicA { Intermediate first; HiddenB second; };\n\
             struct PublicB { Intermediate shared; };\n",
        )
        .unwrap();
        let public = path_arg(&public, "--include").unwrap();
        let snapshot = windows_clang::extract(
            [
                Input::new(AGGREGATE_INPUT, format!("#include \"{public}\"\n"))
                    .with_roots([public.clone()]),
            ],
            &["-x", "c++", "--target=x86_64-pc-windows-msvc"],
        )
        .unwrap();
        let policy = HeaderPartitionPolicy::new().with_traversed_header_for_input(
            AGGREGATE_INPUT,
            public,
            RootPartition::new("Public", "Windows.Win32.Public"),
        );
        let references = MetadataReferences::new([windows_metadata::reader::File::new(
            windows_default::WINRT.to_vec(),
        )
        .unwrap()]);
        let error = plan_header_partitions(
            &snapshot,
            &policy,
            &NamespaceAuthorities::new(),
            &EmitOptions::new(DEFAULT_NAMESPACE, references.types()),
            "x64",
        )
        .unwrap_err();
        for expected in [
            "HiddenA",
            "HiddenB",
            "PublicA",
            "PublicB",
            "selected_roots=2",
            "processed_unique_dependencies=3",
            "resolved_dependencies=1",
            "unique_blockers=2",
        ] {
            assert!(error.contains(expected), "missing `{expected}`:\n{error}");
        }
        std::fs::remove_dir_all(&root).unwrap();
    }

    #[test]
    fn checked_in_ftp_uuid_records_retain_data_layout() {
        use windows_metadata::reader::HasAttributes;

        ensure_libclang();
        let win_sdk = checked_in_win_sdk();
        let include_dirs = checked_in_include_dirs(&win_sdk);
        let header = include_dirs
            .iter()
            .map(|directory| directory.join("ftpext.h"))
            .find(|path| path.is_file())
            .unwrap();
        let header = path_arg(&header, "--include").unwrap();
        let args = checked_in_clang_args(&include_dirs);
        let args = args.iter().map(String::as_str).collect::<Vec<_>>();
        let snapshot = windows_clang::extract(
            [Input::new(
                AGGREGATE_INPUT,
                format!("{WIN32_SDK_PRELUDE}\n#include <ftpext.h>\n"),
            )
            .with_roots([header.clone()])],
            &args,
        )
        .unwrap();
        let records = [
            ("CONFIGURATION_ENTRY", 2),
            ("LOGGING_PARAMETERS", 18),
            ("PRE_PROCESS_PARAMETERS", 13),
            ("POST_PROCESS_PARAMETERS", 20),
        ];
        for (name, expected_fields) in records {
            let fact = snapshot
                .facts()
                .iter()
                .find(|fact| fact.name == name && fact.definition)
                .unwrap();
            let FactData::Record { fields, .. } = &fact.data else {
                panic!(
                    "UUID data record `{name}` was misclassified: {:?}",
                    fact.data
                );
            };
            assert_eq!(fields.len(), expected_fields, "{name}");
        }

        let traversal = checked_in_traversal_policy();
        let policy = HeaderPartitionPolicy::new().with_traversed_header_for_input(
            AGGREGATE_INPUT,
            header,
            convert_root_partition(logical_partition(&traversal, "Iis").unwrap()),
        );
        let references = MetadataReferences::new([windows_metadata::reader::File::new(
            windows_default::WINRT.to_vec(),
        )
        .unwrap()]);
        let mut emit = EmitOptions::new(DEFAULT_NAMESPACE, references.types());
        emit.library = Some("");
        let partitions = plan_header_partitions(
            &snapshot,
            &policy,
            &NamespaceAuthorities::new(),
            &emit,
            "x64",
        )
        .unwrap();
        let root = scratch("ftp-uuid-data-records");
        let rdl_dir = root.join("rdl");
        std::fs::create_dir_all(&rdl_dir).unwrap();
        write_partitioned_rdl(&rdl_dir, partitions).unwrap();
        let winmd = root.join("Ftp.winmd");
        compile_inputs(&[rdl_dir], &[], "Ftp", None, &winmd).unwrap();
        let index = Index::read(&winmd).unwrap();
        for (name, expected_fields) in records {
            let record = index.expect("Windows.Win32.System.Iis", name);
            assert_eq!(record.fields().count(), expected_fields, "{name}");
            let guid = record.find_attribute("GuidAttribute").unwrap();
            assert_eq!(guid.namespace(), "Windows.Foundation.Metadata", "{name}");
            assert_eq!(guid.value().len(), 11, "{name}");
        }
        for interface in [
            "IFtpPreprocessProvider",
            "AsyncIFtpPreprocessProvider",
            "IFtpPostprocessProvider",
            "AsyncIFtpPostprocessProvider",
        ] {
            index.expect("Windows.Win32.System.Iis", interface);
        }
        std::fs::remove_dir_all(&root).unwrap();
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
        let root_plan = build_authority_root_plan(&traversal).unwrap();

        assert_eq!(v1_root.canonical_path, v2_root.canonical_path);
        assert!(v1_root.canonical_path.as_str().ends_with("/um/psapi.h"));
        assert_eq!(
            logical_policy_input(&root_plan, "PsApi1", &v1_root.canonical_path).unwrap(),
            PSAPI_V1_INPUT
        );
        assert_eq!(
            logical_policy_input(&root_plan, "PsApi2", &v2_root.canonical_path).unwrap(),
            PSAPI_V2_INPUT
        );
        assert_eq!(
            authority_owner_input(
                "Ioctl",
                Path::new("C:/sdk/shared/ntddstor.h"),
                "shared/ntddstor.h",
            )
            .unwrap(),
            AuthorityInput::Satellite
        );
        assert_eq!(
            authority_owner_input(
                "Foundation",
                Path::new("C:/sdk/um/winuser.h"),
                "um/winuser.h",
            )
            .unwrap(),
            AuthorityInput::Aggregate
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
                PSAPI_V1_INPUT,
                header.clone(),
                RootPartition::new("PsApi1", "Windows.Win32.System.ProcessStatus"),
            )
            .with_traversed_header_for_input(
                PSAPI_V2_INPUT,
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
                owning_inputs: Vec::new(),
            },
            CoverageRoot {
                configured: path_arg(&public, "--include").unwrap(),
                label: "public.h".to_string(),
                owning_inputs: Vec::new(),
            },
        ];
        assert_eq!(fact_coverage_root(&roots, fact).unwrap().label, "public.h");
        std::fs::remove_dir_all(root).unwrap();
    }

    #[test]
    fn extraction_coverage_report_is_input_qualified_and_stable() {
        let roots = vec![
            CoverageRoot {
                configured: "C:/sdk/shared/a.h".to_string(),
                label: "shared/a.h".to_string(),
                owning_inputs: vec![AGGREGATE_INPUT.to_string()],
            },
            CoverageRoot {
                configured: "C:/sdk/um/b.h".to_string(),
                label: "um/b.h".to_string(),
                owning_inputs: vec![AGGREGATE_INPUT.to_string()],
            },
            CoverageRoot {
                configured: "C:/sdk/um/c.h".to_string(),
                label: "um/c.h".to_string(),
                owning_inputs: vec![SATELLITE_INPUT.to_string()],
            },
        ];
        let visited = BTreeSet::from([
            ("shared/a.h".to_string(), AGGREGATE_INPUT.to_string()),
            ("um/b.h".to_string(), AGGREGATE_INPUT.to_string()),
        ]);
        let productive = BTreeSet::from([("um/b.h".to_string(), AGGREGATE_INPUT.to_string())]);
        let dependencies = BTreeSet::from([("um/c.h".to_string(), AGGREGATE_INPUT.to_string())]);
        let (report, failures) =
            extraction_coverage_report(&roots, &visited, &productive, &dependencies);
        assert_eq!(
            (report.clone(), failures.clone()),
            extraction_coverage_report(&roots, &visited, &productive, &dependencies)
        );
        assert_eq!(
            report,
            "version\t2\n\
             summary\tcanonical_roots\t3\n\
             summary\towning_root_pairs\t3\n\
             summary\tvisited_root_pairs\t2\n\
             summary\tproductive_root_pairs\t1\n\
             summary\tunvisited_root_pairs\t1\n\
             summary\tvisited_zero_fact_pairs\t1\n\
             summary\tcategorized_unproductive_pairs\t0\n\
             summary\tuncategorized_unproductive_pairs\t2\n\
             summary\tdependency_only_visits\t1\n\
             root\twin32metadata-aggregate.cpp\tvisited\tuncategorized-zero-fact\tshared/a.h\n\
             root\twin32metadata-aggregate.cpp\tvisited\tproductive\tum/b.h\n\
             root\twin32metadata-satellites.cpp\tunvisited\tuncategorized-zero-fact\tum/c.h\n\
             dependency\twin32metadata-aggregate.cpp\tum/c.h\n"
        );
        assert_eq!(
            failures,
            [
                "unvisited\twin32metadata-satellites.cpp\tum/c.h",
                "uncategorized-zero-fact\twin32metadata-aggregate.cpp\tshared/a.h",
            ]
        );
    }

    #[test]
    fn extraction_coverage_uses_clang_visits_per_owning_input() {
        ensure_libclang();
        let root = scratch("coverage-inclusions");
        let aggregate_only = root.join("aggregate-only.h");
        let satellite_owned = root.join("satellite-owned.h");
        let skipped = root.join("skipped.h");
        for path in [&aggregate_only, &satellite_owned, &skipped] {
            std::fs::write(path, "#pragma once\n").unwrap();
        }
        let include =
            |path: &Path| format!("#include \"{}\"\n", path_arg(path, "--include").unwrap());
        let aggregate_source = format!(
            "{}{}#if 0\n{}#endif\n",
            include(&aggregate_only),
            include(&satellite_owned),
            include(&skipped)
        );
        let snapshot = windows_clang::extract(
            [
                Input::new(AGGREGATE_INPUT, aggregate_source).with_roots([path_arg(
                    &aggregate_only,
                    "--include",
                )
                .unwrap()]),
                Input::new(SATELLITE_INPUT, include(&satellite_owned)).with_roots([path_arg(
                    &satellite_owned,
                    "--include",
                )
                .unwrap()]),
            ],
            &["-x", "c++", "--target=x86_64-pc-windows-msvc"],
        )
        .unwrap();
        let roots = vec![
            CoverageRoot {
                configured: path_arg(&aggregate_only, "--include").unwrap(),
                label: "aggregate-only.h".to_string(),
                owning_inputs: vec![AGGREGATE_INPUT.to_string()],
            },
            CoverageRoot {
                configured: path_arg(&satellite_owned, "--include").unwrap(),
                label: "satellite-owned.h".to_string(),
                owning_inputs: vec![SATELLITE_INPUT.to_string()],
            },
            CoverageRoot {
                configured: path_arg(&skipped, "--include").unwrap(),
                label: "skipped.h".to_string(),
                owning_inputs: vec![AGGREGATE_INPUT.to_string()],
            },
        ];
        let report = root.join("coverage.tsv");
        let error = write_extraction_coverage(&snapshot, &roots, &report).unwrap_err();
        assert!(error.contains("found 3 issue(s)"), "{error}");
        assert!(
            error.contains("unvisited\twin32metadata-aggregate.cpp\tskipped.h"),
            "{error}"
        );
        let report = std::fs::read_to_string(&report).unwrap();
        assert!(report.contains(
            "root\twin32metadata-aggregate.cpp\tvisited\tuncategorized-zero-fact\taggregate-only.h"
        ));
        assert!(report.contains(
            "root\twin32metadata-satellites.cpp\tvisited\tuncategorized-zero-fact\tsatellite-owned.h"
        ));
        assert!(report.contains(
            "root\twin32metadata-aggregate.cpp\tunvisited\tuncategorized-zero-fact\tskipped.h"
        ));
        assert!(report.contains("dependency\twin32metadata-aggregate.cpp\tsatellite-owned.h"));
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
