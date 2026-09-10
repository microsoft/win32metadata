//! `scrape`: partition `main.cpp` files -> WinMD, using windows-clang and windows-rdl.
//!
//! This is the minimal alternate pipeline. Its inputs are the existing partition translation
//! units, the SDK header roots, optionally the SDK import-library root, and the target
//! architectures. Everything else - the flat `Windows.Win32` root namespace, the clang
//! language settings, the reachability scope, and the intermediate RDL - is fixed and lands
//! under the object directory. There are no RSP or JSON sidecars.

use std::ffi::OsString;
use std::path::{Path, PathBuf};

use windows_clang::{Arch, Clang, clang};
use windows_metadata::reader::{Index, Item};
use windows_rdl::{ArchInput, merge_arch_rdl, reader};

use crate::args::{Args, required, set_once};
use crate::catch::catch;
use crate::libclang;

/// Flat root namespace every partition emits into; the defining header chooses the `.rdl`.
const ROOT: &str = "Windows.Win32";

/// Parse the SDK headers as C++ so `extern "C"`, `__declspec`, and SAL are understood.
/// `-ferror-limit=0` keeps clang from dropping later declarations after a tolerated error.
const CLANG_ARGS: [&str; 6] = [
    "-x",
    "c++",
    "-std=c++17",
    "-ferror-limit=0",
    "-Wno-pragma-once-outside-header",
    "-DWIN32METADATA=1",
];

/// Header directory segments whose declarations are emitted unconditionally. Anything else
/// a partition pulls in is emitted only when a declaration in scope references it.
const SCOPE: [&str; 2] = ["shared", "um"];

/// SDK include-root layout. A `--include` directory containing any of these is expanded
/// into them, so the SDK root can be named once.
const SDK_INCLUDE_SUBDIRS: [&str; 4] = ["shared", "um", "ucrt", "winrt"];

#[derive(Default, Debug)]
pub struct Options {
    pub help: bool,
    partitions: Vec<PathBuf>,
    includes: Vec<PathBuf>,
    libs: Vec<PathBuf>,
    archs: Vec<String>,
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
            "--include" => options.includes.push(args.path(&option)?),
            "--lib" => options.libs.push(args.path(&option)?),
            "--arch" => options.archs.push(args.value(&option)?),
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

    validate(&options)?;
    Ok(options)
}

fn validate(options: &Options) -> Result<(), String> {
    if options.partitions.is_empty() {
        return Err("at least one `--partition <main.cpp>` is required".to_string());
    }
    if options.includes.is_empty() {
        return Err("at least one `--include <dir>` is required".to_string());
    }
    required(options.output.as_ref(), "--output")?;

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
    options.includes.iter_mut().try_for_each(one)?;
    options.libs.iter_mut().try_for_each(one)?;
    for path in [options.output.as_mut(), options.obj.as_mut()]
        .into_iter()
        .flatten()
    {
        one(path)?;
    }
    Ok(())
}

/// Expands an SDK include root into its `shared`/`um`/`ucrt`/`winrt` subdirectories.
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
            .map(|name| include.join(name))
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

/// Builds the architecture-invariant parse: language settings, SDK includes, reachability
/// scope, partition sources, and the symbol -> DLL mappings recovered from import libraries.
fn build_clang(options: &Options) -> Result<Clang, String> {
    let mut builder = clang();
    builder.args(CLANG_ARGS);

    for dir in include_dirs(options)? {
        builder.args(["-isystem", &path_arg(&dir, "--include")?]);
    }

    for partition in &options.partitions {
        let source = std::fs::read_to_string(partition).map_err(|error| {
            format!(
                "failed to read `--partition {}`: {error}",
                partition.display()
            )
        })?;
        builder.input_text(&source);
    }

    let libs = lib_files(options)?;
    for lib in &libs {
        builder
            .import_library(lib)
            .map_err(|error| format!("failed to read `{}`: {error}", lib.display()))?;
    }
    if !libs.is_empty() {
        // Only meaningful with import-library coverage; without it every function would go.
        builder.drop_lib_less();
    }

    builder.scopes(SCOPE);
    builder.namespace(ROOT);
    Ok(builder)
}

fn execute(options: &Options) -> Result<(), String> {
    let provisioned = libclang::provision(None, true)?;
    println!("Using {provisioned}");

    let output = options.output.as_ref().expect("validated by `validate`");
    let obj = obj_dir(options);
    let rdl_dir = obj.join("rdl");
    let arch_names = archs(options);

    let builder = build_clang(options)?;

    println!(
        "Scraping {} partition(s) for {} into {}",
        options.partitions.len(),
        arch_names.join(", "),
        rdl_dir.display()
    );

    // Non-canonical architectures need version-matched clang resource headers, which
    // `windows-clang` caches at the relative path `target/windows-clang`. Move into the
    // object directory so the cache lands there; every path option is already absolute.
    if arch_names.len() > 1 && std::env::var_os("CLANG_RESOURCE_DIR").is_none() {
        std::fs::create_dir_all(&obj)
            .map_err(|error| format!("failed to create `{}`: {error}", obj.display()))?;
        std::env::set_current_dir(&obj)
            .map_err(|error| format!("failed to enter `{}`: {error}", obj.display()))?;
    }

    let canonical = arch(&arch_names[0])?;
    let resource_dir = if arch_names.len() > 1 {
        Some(catch(
            "failed to fetch the clang resource headers",
            windows_clang::clang_resource_dir,
        )?)
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
            &builder,
            &arch,
            resource_dir
                .as_deref()
                .filter(|_| arch.bits != canonical.bits),
            &arch_rdl_dir,
            &arch_winmd,
        )?;

        merged.push(ArchInput {
            rdl_dir: arch_rdl_dir,
            winmd: arch_winmd,
            bits: arch.bits,
        });
    }

    if merged.len() > 1 {
        // Fold the per-architecture surfaces back into the defining-header partitions so
        // symbols that exist on only some architectures are tagged, then rebuild.
        merge_arch_rdl(&merged, None, &rdl_dir)
            .map_err(|error| format!("failed to merge architectures: {error}"))?;
        compile(&rdl_dir, output)?;
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
    builder: &Clang,
    arch: &Arch,
    resource_dir: Option<&str>,
    rdl_dir: &Path,
    winmd: &Path,
) -> Result<(), String> {
    clear_rdl_dir(rdl_dir)?;

    let mut builder = builder.clone();
    builder.target(&arch.triple).output(rdl_dir);
    if let Some(dir) = resource_dir {
        builder.args(["-resource-dir", dir]);
    }

    catch("the header scrape panicked", || builder.write_by_header())?
        .map_err(|error| format!("failed to generate RDL in `{}`: {error}", rdl_dir.display()))?;

    compile(rdl_dir, winmd)
}

/// Compiles a directory of RDL partitions into a WinMD.
///
/// The bundled Windows metadata supplies what headers cannot: the `Windows.Win32.Metadata`
/// pseudo-attribute vocabulary and the system types the emitted RDL refers to.
fn compile(rdl_dir: &Path, winmd: &Path) -> Result<(), String> {
    if let Some(parent) = winmd.parent() {
        std::fs::create_dir_all(parent)
            .map_err(|error| format!("failed to create `{}`: {error}", parent.display()))?;
    }

    reader()
        .input(rdl_dir)
        .reference_default()
        .output(winmd)
        .write()
        .map_err(|error| format!("failed to compile `{}`: {error}", winmd.display()))
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
    --include <dir>... \\
    [--lib <dir-or-file>]... \\
    [--arch <x64|arm64|x86>]... \\
    --output <output.winmd> \\
    [--obj <dir>]

  --partition   Partition translation unit to scrape. Repeatable.
  --include     Header root. An SDK root is expanded into its shared/um/ucrt/winrt
                subdirectories; any other directory is used as-is. Repeatable.
  --lib         SDK import-library directory or file, read for symbol -> DLL mappings.
                Repeatable. Without it, functions carry no import library.
  --arch        Architecture to scrape. Repeatable. Defaults to x64. The first is
                canonical; the rest are merged into it.
  --output      WinMD to write.
  --obj         Intermediate directory for the generated RDL and per-architecture
                WinMDs. Defaults to the directory of --output.

All declarations are emitted into the flat `Windows.Win32` namespace, partitioned by
defining header. There are no RSP or JSON inputs."
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
    }

    #[test]
    fn partitions_are_required() {
        let error = parse_args(&["--include", "inc", "--output", "obj/out.winmd"]).unwrap_err();
        assert!(error.contains("--partition"), "{error}");
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
    fn repeated_single_valued_options_are_rejected() {
        let error = parse_with(&["--output", "other.winmd"]).unwrap_err();
        assert!(error.contains("only be specified once"), "{error}");
    }

    #[test]
    fn unknown_options_report_usage() {
        let error = parse_with(&["--namespace", "Windows.Win32"]).unwrap_err();
        assert!(
            error.contains("unknown scrape option `--namespace`"),
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
