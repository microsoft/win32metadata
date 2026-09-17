//! `compile`: generated RDL inputs -> one WinMD.

use std::ffi::OsString;
use std::path::PathBuf;

use windows_metadata::reader::Index;
use windows_rdl::reader;

use crate::args::{Args, required, set_once};

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

    let output = options.output.as_ref().expect("validated by `parse`");
    if let Some(parent) = output.parent() {
        std::fs::create_dir_all(parent)
            .map_err(|error| format!("failed to create `{}`: {error}", parent.display()))?;
    }

    let mut compiler = reader();
    for input in &options.inputs {
        compiler.input(input);
    }
    compiler
        .input_text(windows_rdl::WIN32_METADATA_RDL)
        .reference_default()
        .references(&options.references)
        .assembly_name(assembly_name(options)?)
        .output(output);
    if let Some(version) = options.assembly_version {
        compiler.assembly_version(version);
    }
    compiler
        .write()
        .map_err(|error| format!("failed to compile `{}`: {error}", output.display()))?;

    let index = Index::read(output).ok_or_else(|| {
        format!(
            "`{}` was written but could not be read back as metadata",
            output.display()
        )
    })?;
    println!(
        "Compiled {} RDL input(s) into {} metadata item(s): {}",
        options.inputs.len(),
        index.iter_items().count(),
        output.display()
    );
    Ok(())
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
}
