//! `merge-arch`: cached per-architecture RDL and WinMD pairs -> merged RDL and WinMD.

use std::collections::HashSet;
use std::ffi::OsString;
use std::path::{Path, PathBuf};

use windows_clang::Arch;
use windows_rdl::{ArchInput, merge_arch_rdl};

use crate::args::{Args, required, set_once};
use crate::compile::compile_inputs;

const DEFAULT_NAMESPACE: &str = "Windows.Win32";

#[derive(Default, Debug)]
struct Input {
    arch: String,
    rdl_dir: Option<PathBuf>,
    winmd: Option<PathBuf>,
}

#[derive(Default, Debug)]
struct Options {
    help: bool,
    inputs: Vec<Input>,
    namespace: Option<String>,
    assembly_name: Option<String>,
    assembly_version: Option<[u16; 4]>,
    output_rdl: Option<PathBuf>,
    output_winmd: Option<PathBuf>,
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

fn parse(mut args: Args) -> Result<Options, String> {
    let mut options = Options::default();

    while let Some(option) = args.next_option()? {
        match option.as_str() {
            "--help" | "-h" => {
                options.help = true;
                return Ok(options);
            }
            "--arch" => {
                if options
                    .inputs
                    .last()
                    .is_some_and(|input| input.rdl_dir.is_none() || input.winmd.is_none())
                {
                    return Err(
                        "each `--arch` must be followed by one `--rdl` and one `--winmd`"
                            .to_string(),
                    );
                }
                options.inputs.push(Input {
                    arch: args.value(&option)?,
                    ..Default::default()
                });
            }
            "--rdl" => {
                let input = options
                    .inputs
                    .last_mut()
                    .ok_or_else(|| "`--rdl` must follow an `--arch`".to_string())?;
                set_once(&mut input.rdl_dir, args.os_path(&option)?, &option)?;
            }
            "--winmd" => {
                let input = options
                    .inputs
                    .last_mut()
                    .ok_or_else(|| "`--winmd` must follow an `--arch`".to_string())?;
                set_once(&mut input.winmd, args.os_path(&option)?, &option)?;
            }
            "--namespace" => set_once(&mut options.namespace, args.value(&option)?, &option)?,
            "--assembly-name" => {
                set_once(&mut options.assembly_name, args.value(&option)?, &option)?
            }
            "--assembly-version" => set_once(
                &mut options.assembly_version,
                parse_version(&args.value(&option)?)?,
                &option,
            )?,
            "--output-rdl" => set_once(&mut options.output_rdl, args.os_path(&option)?, &option)?,
            "--output-winmd" => {
                set_once(&mut options.output_winmd, args.os_path(&option)?, &option)?
            }
            _ => {
                return Err(format!(
                    "unknown merge-arch option `{option}`\n\n{}",
                    help_text()
                ));
            }
        }
    }

    if options
        .inputs
        .last()
        .is_some_and(|input| input.rdl_dir.is_none() || input.winmd.is_none())
    {
        return Err("each `--arch` must be followed by one `--rdl` and one `--winmd`".to_string());
    }
    if options.inputs.len() < 2 {
        return Err("at least two architecture input pairs are required".to_string());
    }
    required(options.output_rdl.as_ref(), "--output-rdl")?;
    required(options.output_winmd.as_ref(), "--output-winmd")?;
    Ok(options)
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

fn absolutize(options: &mut Options) -> Result<(), String> {
    fn one(path: &mut PathBuf) -> Result<(), String> {
        *path = std::path::absolute(&*path)
            .map_err(|error| format!("failed to resolve `{}`: {error}", path.display()))?;
        Ok(())
    }

    for input in &mut options.inputs {
        one(input.rdl_dir.as_mut().expect("validated by `parse`"))?;
        one(input.winmd.as_mut().expect("validated by `parse`"))?;
    }
    one(options.output_rdl.as_mut().expect("validated by `parse`"))?;
    one(options.output_winmd.as_mut().expect("validated by `parse`"))?;
    Ok(())
}

fn assembly_name(options: &Options) -> Result<&str, String> {
    if let Some(name) = &options.assembly_name {
        return Ok(name);
    }

    options
        .output_winmd
        .as_ref()
        .and_then(|path| path.file_stem())
        .and_then(|name| name.to_str())
        .ok_or_else(|| "could not derive the assembly name from `--output-winmd`".to_string())
}

fn execute(options: &Options) -> Result<(), String> {
    let output_rdl = options.output_rdl.as_ref().expect("validated by `parse`");
    let output_winmd = options.output_winmd.as_ref().expect("validated by `parse`");
    if output_rdl.exists() {
        return Err(format!(
            "`--output-rdl {}` already exists; a fresh output path is required",
            output_rdl.display()
        ));
    }
    if output_winmd.exists() {
        return Err(format!(
            "`--output-winmd {}` already exists; a fresh output path is required",
            output_winmd.display()
        ));
    }

    let mut names = HashSet::new();
    let mut inputs = Vec::with_capacity(options.inputs.len());
    for input in &options.inputs {
        let arch = Arch::known(&input.arch).ok_or_else(|| {
            format!(
                "unknown architecture `{}`; expected x64, arm64, or x86",
                input.arch
            )
        })?;
        if !names.insert(input.arch.as_str()) {
            return Err(format!("duplicate architecture `{}`", input.arch));
        }

        let rdl_dir = input.rdl_dir.as_ref().expect("validated by `parse`");
        let winmd = input.winmd.as_ref().expect("validated by `parse`");
        if !rdl_dir.is_dir() {
            return Err(format!("`--rdl {}` is not a directory", rdl_dir.display()));
        }
        if !winmd.is_file() {
            return Err(format!("`--winmd {}` is not a file", winmd.display()));
        }
        reject_output_overlap(rdl_dir, output_rdl, "--output-rdl")?;
        reject_output_overlap(rdl_dir, output_winmd, "--output-winmd")?;
        reject_output_alias(winmd, output_rdl, "--output-rdl")?;
        reject_output_alias(winmd, output_winmd, "--output-winmd")?;
        inputs.push(ArchInput {
            rdl_dir: rdl_dir.clone(),
            winmd: winmd.clone(),
            bits: arch.bits,
        });
    }
    if !names.contains("x64") {
        return Err(
            "an `x64` input pair is required as the canonical partition source".to_string(),
        );
    }

    std::fs::create_dir_all(output_rdl).map_err(|error| {
        format!(
            "failed to create fresh output RDL directory `{}`: {error}",
            output_rdl.display()
        )
    })?;
    merge_arch_rdl(
        &inputs,
        None,
        options.namespace.as_deref().unwrap_or(DEFAULT_NAMESPACE),
        output_rdl,
    )
    .map_err(|error| format!("failed to merge architectures: {error}"))?;

    compile_inputs(
        std::slice::from_ref(output_rdl),
        &[],
        assembly_name(options)?,
        options.assembly_version,
        output_winmd,
    )?;
    println!("Merged RDL: {}", output_rdl.display());
    println!("Merged WinMD: {}", output_winmd.display());
    Ok(())
}

fn reject_output_alias(input: &Path, output: &Path, option: &str) -> Result<(), String> {
    if input == output {
        Err(format!(
            "`{option} {}` must be separate from all cached inputs",
            output.display()
        ))
    } else {
        Ok(())
    }
}

fn reject_output_overlap(input_dir: &Path, output: &Path, option: &str) -> Result<(), String> {
    if output.starts_with(input_dir) {
        Err(format!(
            "`{option} {}` must not be inside cached input directory `{}`",
            output.display(),
            input_dir.display()
        ))
    } else {
        Ok(())
    }
}

pub fn help_text() -> &'static str {
    "Usage:
  win32metadata-tools merge-arch \\
    --arch x64 --rdl <x64-rdl-dir> --winmd <x64.winmd> \\
    --arch x86 --rdl <x86-rdl-dir> --winmd <x86.winmd> \\
    [--arch arm64 --rdl <arm64-rdl-dir> --winmd <arm64.winmd>] \\
    [--namespace <root-namespace>] \\
    [--assembly-name <name>] \\
    [--assembly-version <A.B.C.D>] \\
    --output-rdl <fresh-rdl-dir> \\
    --output-winmd <fresh.winmd>

Each architecture must provide a matching generated RDL directory and compiled WinMD.
At least two unique architectures, including x64, are required. Cached inputs are read-only;
both output paths must be new. The command only merges and compiles existing artifacts."
}

#[cfg(test)]
mod tests {
    use super::*;

    fn parse_args(args: &[&str]) -> Result<Options, String> {
        parse(Args::new(args.iter().map(OsString::from).collect()))
    }

    #[test]
    fn parses_grouped_inputs_and_identity() {
        let options = parse_args(&[
            "--arch",
            "x64",
            "--rdl",
            "x64",
            "--winmd",
            "x64.winmd",
            "--arch",
            "arm64",
            "--rdl",
            "arm64",
            "--winmd",
            "arm64.winmd",
            "--namespace",
            "Test",
            "--assembly-name",
            "Test.Metadata",
            "--assembly-version",
            "1.2.3.4",
            "--output-rdl",
            "merged",
            "--output-winmd",
            "merged.winmd",
        ])
        .unwrap();

        assert_eq!(options.inputs.len(), 2);
        assert_eq!(options.namespace.as_deref(), Some("Test"));
        assert_eq!(options.assembly_name.as_deref(), Some("Test.Metadata"));
        assert_eq!(options.assembly_version, Some([1, 2, 3, 4]));
    }

    #[test]
    fn rejects_incomplete_or_single_input() {
        assert!(
            parse_args(&[
                "--arch",
                "x64",
                "--rdl",
                "x64",
                "--output-rdl",
                "merged",
                "--output-winmd",
                "merged.winmd",
            ])
            .unwrap_err()
            .contains("one `--rdl` and one `--winmd`")
        );
        assert!(
            parse_args(&[
                "--arch",
                "x64",
                "--rdl",
                "x64",
                "--winmd",
                "x64.winmd",
                "--output-rdl",
                "merged",
                "--output-winmd",
                "merged.winmd",
            ])
            .unwrap_err()
            .contains("at least two")
        );
    }

    #[test]
    fn merges_architecture_varying_cached_inputs() {
        let root = std::env::temp_dir().join(format!(
            "win32metadata-tools-merge-arch-{}",
            std::process::id()
        ));
        std::fs::remove_dir_all(&root).ok();
        std::fs::create_dir_all(&root).unwrap();

        let x64_rdl = root.join("x64");
        let x86_rdl = root.join("x86");
        std::fs::create_dir_all(&x64_rdl).unwrap();
        std::fs::create_dir_all(&x86_rdl).unwrap();
        std::fs::write(
            x64_rdl.join("Test.rdl"),
            "#[win32] mod Test { const COMMON: i32 = 1; const X64_ONLY: i32 = 2; }",
        )
        .unwrap();
        std::fs::write(
            x86_rdl.join("Test.rdl"),
            "#[win32] mod Test { const COMMON: i32 = 1; const X86_ONLY: i32 = 3; }",
        )
        .unwrap();
        let x64_winmd = root.join("x64.winmd");
        let x86_winmd = root.join("x86.winmd");
        compile_inputs(
            std::slice::from_ref(&x64_rdl),
            &[],
            "Test.Metadata",
            None,
            &x64_winmd,
        )
        .unwrap();
        compile_inputs(
            std::slice::from_ref(&x86_rdl),
            &[],
            "Test.Metadata",
            None,
            &x86_winmd,
        )
        .unwrap();

        let output_rdl = root.join("merged");
        let output_winmd = root.join("merged.winmd");
        execute(&Options {
            inputs: vec![
                Input {
                    arch: "x64".to_string(),
                    rdl_dir: Some(x64_rdl.clone()),
                    winmd: Some(x64_winmd.clone()),
                },
                Input {
                    arch: "x86".to_string(),
                    rdl_dir: Some(x86_rdl.clone()),
                    winmd: Some(x86_winmd.clone()),
                },
            ],
            namespace: Some("Test".to_string()),
            assembly_name: Some("Test.Metadata".to_string()),
            output_rdl: Some(output_rdl.clone()),
            output_winmd: Some(output_winmd.clone()),
            ..Default::default()
        })
        .unwrap();

        let rdl = std::fs::read_to_string(output_rdl.join("Test.rdl")).unwrap();
        assert!(rdl.contains("#[arch(X64)]"));
        assert!(rdl.contains("#[arch(X86)]"));
        assert!(windows_metadata::reader::Index::read(&output_winmd).is_some());
        assert!(x64_rdl.join("Test.rdl").is_file());
        assert!(x86_rdl.join("Test.rdl").is_file());
        std::fs::remove_dir_all(&root).ok();
    }
}
