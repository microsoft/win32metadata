//! `compile`: generated RDL inputs -> one WinMD.

use std::ffi::OsString;
use std::path::PathBuf;

use windows_metadata::reader::Index;
use windows_rdl::reader;

use crate::args::{Args, required, set_once};

pub(crate) const METADATA_RDL: &str = include_str!("metadata.rdl");

#[derive(Default, Debug)]
struct Options {
    help: bool,
    inputs: Vec<PathBuf>,
    references: Vec<PathBuf>,
    assembly_name: Option<String>,
    assembly_version: Option<[u16; 4]>,
    output: Option<PathBuf>,
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
            "--input" => options.inputs.push(args.os_path(&option)?),
            "--reference" => options.references.push(args.os_path(&option)?),
            "--assembly-name" => {
                set_once(&mut options.assembly_name, args.value(&option)?, &option)?
            }
            "--assembly-version" => set_once(
                &mut options.assembly_version,
                parse_version(&args.value(&option)?)?,
                &option,
            )?,
            "--output" => set_once(&mut options.output, args.os_path(&option)?, &option)?,
            _ => {
                return Err(format!(
                    "unknown compile option `{option}`\n\n{}",
                    help_text()
                ));
            }
        }
    }

    if options.inputs.is_empty() {
        return Err("at least one `--input <generated.rdl-or-dir>` is required".to_string());
    }
    required(options.output.as_ref(), "--output")?;
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

    options.inputs.iter_mut().try_for_each(one)?;
    options.references.iter_mut().try_for_each(one)?;
    if let Some(output) = &mut options.output {
        one(output)?;
    }
    Ok(())
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

fn execute(options: &Options) -> Result<(), String> {
    for input in &options.inputs {
        if !input.exists() {
            return Err(format!("`--input {}` does not exist", input.display()));
        }
    }
    for reference in &options.references {
        if !reference.is_file() {
            return Err(format!(
                "`--reference {}` is not a file",
                reference.display()
            ));
        }
    }

    compile_inputs(
        &options.inputs,
        &options.references,
        assembly_name(options)?,
        options.assembly_version,
        options.output.as_ref().expect("validated by `parse`"),
    )
}

pub(crate) fn compile_inputs(
    inputs: &[PathBuf],
    references: &[PathBuf],
    assembly_name: &str,
    assembly_version: Option<[u16; 4]>,
    output: &std::path::Path,
) -> Result<(), String> {
    let started = std::time::Instant::now();
    let parent = output.parent().unwrap_or_else(|| std::path::Path::new("."));
    let staging = crate::staging::create_directory(parent, ".win32metadata")?;
    let staged = staging.join(format!("{assembly_name}.winmd"));

    let result: Result<(), String> = (|| {
        let mut compiler = reader();
        for input in inputs {
            compiler.input(input);
        }
        compiler
            .input_text(METADATA_RDL)
            .reference_default()
            .references(references)
            .output(&staged)
            .write()
            .map_err(|error| format!("failed to compile `{}`: {error}", output.display()))?;

        if let Some(version) = assembly_version {
            patch_assembly_version(&staged, version)?;
        }

        std::fs::copy(&staged, output)
            .map(|_| ())
            .map_err(|error| format!("failed to write `{}`: {error}", output.display()))?;
        Ok(())
    })();
    std::fs::remove_dir_all(&staging).ok();
    result?;

    let index = Index::read(output).ok_or_else(|| {
        format!(
            "`{}` was written but could not be read back as metadata",
            output.display()
        )
    })?;
    println!(
        "Compiled {} RDL input(s) into {} metadata item(s) in {:.2}s: {}",
        inputs.len(),
        index.iter_items().count(),
        started.elapsed().as_secs_f32(),
        output.display()
    );
    Ok(())
}

pub(crate) fn patch_assembly_version(
    path: &std::path::Path,
    version: [u16; 4],
) -> Result<(), String> {
    const DEFAULT_ASSEMBLY_ROW_PREFIX: [u8; 12] = [
        0x04, 0x80, 0x00, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00,
    ];

    let mut bytes = std::fs::read(path)
        .map_err(|error| format!("failed to read `{}`: {error}", path.display()))?;
    let matches = bytes
        .windows(DEFAULT_ASSEMBLY_ROW_PREFIX.len())
        .enumerate()
        .filter_map(|(index, candidate)| {
            (candidate == DEFAULT_ASSEMBLY_ROW_PREFIX).then_some(index)
        })
        .collect::<Vec<_>>();
    let [offset] = matches.as_slice() else {
        return Err(format!(
            "could not uniquely locate the metadata assembly row in `{}`",
            path.display()
        ));
    };
    for (index, value) in version.into_iter().enumerate() {
        let start = offset + 4 + index * 2;
        bytes[start..start + 2].copy_from_slice(&value.to_le_bytes());
    }
    std::fs::write(path, bytes)
        .map_err(|error| format!("failed to update `{}`: {error}", path.display()))
}

pub fn help_text() -> &'static str {
    "Usage:
  win32metadata-tools compile \\
    --input <generated.rdl-or-dir>... \\
    [--reference <reference.winmd>]... \\
    [--assembly-name <name>] \\
    [--assembly-version <A.B.C.D>] \\
    --output <output.winmd>

  --input       Generated RDL file or directory. Repeatable; all inputs are compiled
                into the same output metadata assembly.
  --reference   Additional WinMD used only to resolve external types. Repeatable.
  --assembly-name
                Output assembly name. Defaults to the --output file stem.
  --assembly-version
                Four-part numeric output assembly version. Defaults to 255.255.255.255.
  --output      WinMD to write.

The canonical metadata attribute vocabulary is injected automatically. Inputs remain
source-generated RDL; this command does not accept semantic JSON or metadata sidecars."
}

#[cfg(test)]
mod tests {
    use super::*;

    fn parse_args(args: &[&str]) -> Result<Options, String> {
        parse(Args::new(args.iter().map(OsString::from).collect()))
    }

    #[test]
    fn multiple_inputs_and_identity_parse() {
        let options = parse_args(&[
            "--input",
            "foundation",
            "--input",
            "power",
            "--reference",
            "external.winmd",
            "--assembly-name",
            "Windows.Win32",
            "--assembly-version",
            "1.2.3.4",
            "--output",
            "combined.winmd",
        ])
        .unwrap();

        assert_eq!(options.inputs.len(), 2);
        assert_eq!(options.references.len(), 1);
        assert_eq!(assembly_name(&options).unwrap(), "Windows.Win32");
        assert_eq!(options.assembly_version, Some([1, 2, 3, 4]));
    }

    #[test]
    fn inputs_and_output_are_required() {
        assert!(
            parse_args(&["--output", "out.winmd"])
                .unwrap_err()
                .contains("--input")
        );
        assert!(
            parse_args(&["--input", "input.rdl"])
                .unwrap_err()
                .contains("--output")
        );
    }

    #[test]
    fn compiles_multiple_namespace_roots() {
        let root = std::env::temp_dir().join(format!(
            "win32metadata-tools-compile-{}",
            std::process::id()
        ));
        std::fs::create_dir_all(&root).unwrap();
        let foundation = root.join("foundation.rdl");
        let power = root.join("power.rdl");
        let output = root.join("combined.winmd");

        std::fs::write(
            &foundation,
            r#"
#[win32]
mod Windows {
    mod Win32 {
        mod Foundation {
            #[repr(u32)]
            enum WIN32_ERROR {
                ERROR_SUCCESS = 0,
            }
        }
    }
}
"#,
        )
        .unwrap();
        std::fs::write(
            &power,
            r#"
#[win32]
mod Windows {
    mod Win32 {
        mod System {
            mod Power {
                #[repr(u32)]
                enum POWER_PLATFORM_ROLE_VERSION {
                    POWER_PLATFORM_ROLE_V1 = 1,
                }
            }
        }
    }
}
"#,
        )
        .unwrap();

        let options = Options {
            inputs: vec![foundation, power],
            assembly_name: Some("Windows.Win32".to_string()),
            output: Some(output.clone()),
            ..Default::default()
        };
        execute(&options).unwrap();

        let index = Index::read(&output).unwrap();
        index.expect("Windows.Win32.Foundation", "WIN32_ERROR");
        index.expect("Windows.Win32.System.Power", "POWER_PLATFORM_ROLE_VERSION");
        std::fs::remove_dir_all(&root).ok();
    }

    #[test]
    fn rdl_flags_attribute_preserves_plain_enum_control() {
        use windows_metadata::HasAttributes;

        let root =
            crate::staging::create_directory(&std::env::temp_dir(), "rdl-flags-control").unwrap();
        let input = root.join("flags.rdl");
        let output = root.join("FlagsControl.winmd");
        std::fs::write(
            &input,
            r#"
#[win32]
mod Test {
    mod FlagsControl {
        #[repr(u32)]
        #[flags]
        enum Annotated {
            None = 0,
            Read = 1,
            Write = 2,
            All = 3,
        }
        #[repr(u32)]
        enum Plain {
            None = 0,
            Read = 1,
            Write = 2,
            All = 3,
        }
    }
}
"#,
        )
        .unwrap();
        compile_inputs(&[input], &[], "FlagsControl", None, &output).unwrap();
        let index = Index::read(&output).unwrap();
        let annotated = index.expect("Test.FlagsControl", "Annotated");
        let attribute = annotated.find_attribute("FlagsAttribute").unwrap();
        assert_eq!(attribute.namespace(), "System");
        assert!(
            !index
                .expect("Test.FlagsControl", "Plain")
                .has_attribute("FlagsAttribute")
        );
        std::fs::remove_dir_all(root).unwrap();
    }

    #[test]
    fn concurrent_same_assembly_compiles_keep_outputs_isolated() {
        const WORKERS: usize = 4;
        let root = crate::staging::create_directory(
            &std::env::temp_dir(),
            "win32metadata-parallel-compile",
        )
        .unwrap();
        let barrier = std::sync::Barrier::new(WORKERS);
        std::thread::scope(|scope| {
            let workers = (0..WORKERS)
                .map(|worker| {
                    let root = &root;
                    let barrier = &barrier;
                    scope.spawn(move || {
                        let input = root.join(format!("input-{worker}.rdl"));
                        let output = root.join(format!("output-{worker}.winmd"));
                        std::fs::write(
                            &input,
                            format!("#[win32]\nmod Sample {{ const OWNER: u32 = {worker}; }}"),
                        )
                        .unwrap();
                        barrier.wait();
                        compile_inputs(
                            std::slice::from_ref(&input),
                            &[],
                            "Sample.Shared",
                            Some([1, 2, 3, 4]),
                            &output,
                        )
                        .unwrap();
                        let index = Index::read(&output).unwrap();
                        let windows_metadata::reader::Item::Const(field) =
                            index.expect_item("Sample", "OWNER")
                        else {
                            panic!("missing worker identity");
                        };
                        assert_eq!(
                            field.constant().unwrap().value(),
                            windows_metadata::Value::U32(worker.try_into().unwrap())
                        );
                        (input, output)
                    })
                })
                .collect::<Vec<_>>();
            for worker in workers {
                let (input, output) = worker.join().unwrap();
                let sequential = output.with_extension("sequential.winmd");
                compile_inputs(
                    &[input],
                    &[],
                    "Sample.Shared",
                    Some([1, 2, 3, 4]),
                    &sequential,
                )
                .unwrap();
                assert_eq!(
                    std::fs::read(output).unwrap(),
                    std::fs::read(sequential).unwrap()
                );
            }
        });
        assert!(std::fs::read_dir(&root).unwrap().all(|entry| {
            !entry
                .unwrap()
                .file_name()
                .to_string_lossy()
                .starts_with(".win32metadata-")
        }));
        std::fs::remove_dir_all(root).unwrap();
    }
}
