use std::env;
use std::path::PathBuf;

use windows_rdl::{reader, writer};

fn main() {
    if let Err(error) = run() {
        eprintln!("error: {error}");
        std::process::exit(1);
    }
}

fn run() -> Result<(), String> {
    let mut args = env::args_os();
    let _program = args.next();

    match args
        .next()
        .and_then(|value| value.into_string().ok())
        .as_deref()
    {
        Some("roundtrip") => roundtrip(args.collect()),
        Some("help") | Some("--help") | Some("-h") | None => {
            print_help();
            Ok(())
        }
        Some(command) => Err(format!("unknown command `{command}`\n\n{}", help_text())),
    }
}

fn roundtrip(args: Vec<std::ffi::OsString>) -> Result<(), String> {
    let mut input = None;
    let mut rdl_output = None;
    let mut winmd_output = None;
    let mut references = Vec::new();
    let mut index = 0;

    while index < args.len() {
        let option = args[index]
            .to_str()
            .ok_or_else(|| "arguments must be valid Unicode".to_string())?;
        index += 1;

        let value = match option {
            "--input" | "--rdl-output" | "--winmd-output" | "--reference" => {
                let value = args
                    .get(index)
                    .ok_or_else(|| format!("missing value for `{option}`"))?;
                index += 1;
                PathBuf::from(value)
            }
            "--help" | "-h" => {
                print_help();
                return Ok(());
            }
            _ => return Err(format!("unknown roundtrip option `{option}`")),
        };

        match option {
            "--input" => set_once(&mut input, value, option)?,
            "--rdl-output" => set_once(&mut rdl_output, value, option)?,
            "--winmd-output" => set_once(&mut winmd_output, value, option)?,
            "--reference" => references.push(value),
            _ => unreachable!(),
        }
    }

    let input = required(input, "--input")?;
    let rdl_output = required(rdl_output, "--rdl-output")?;
    let winmd_output = required(winmd_output, "--winmd-output")?;

    writer()
        .input(&input)
        .output(&rdl_output)
        .write()
        .map_err(|error| format!("failed to write RDL: {error}"))?;

    let mut compiler = reader();
    compiler.input(&rdl_output).output(&winmd_output);
    compiler.references(&references);
    compiler
        .write()
        .map_err(|error| format!("failed to rebuild WinMD: {error}"))?;

    println!(
        "Round-tripped {} through {} to {}",
        input.display(),
        rdl_output.display(),
        winmd_output.display()
    );
    Ok(())
}

fn set_once(destination: &mut Option<PathBuf>, value: PathBuf, option: &str) -> Result<(), String> {
    if destination.replace(value).is_some() {
        Err(format!("`{option}` may only be specified once"))
    } else {
        Ok(())
    }
}

fn required(value: Option<PathBuf>, option: &str) -> Result<PathBuf, String> {
    value.ok_or_else(|| format!("required option `{option}` was not provided"))
}

fn print_help() {
    println!("{}", help_text());
}

fn help_text() -> &'static str {
    "Usage:
  win32metadata-tools roundtrip \
    --input <input.winmd> \
    --rdl-output <output.rdl> \
    --winmd-output <output.winmd> \
    [--reference <reference.winmd>]..."
}
