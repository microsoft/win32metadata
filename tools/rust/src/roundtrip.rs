//! `roundtrip`: WinMD -> RDL -> WinMD fidelity harness.

use std::ffi::OsString;
use std::path::PathBuf;

use windows_rdl::{reader, writer};

use crate::args::{Args, required, set_once};

pub fn run(args: Vec<OsString>) -> Result<(), String> {
    let mut args = Args::new(args);
    let mut input = None;
    let mut rdl_output = None;
    let mut winmd_output = None;
    let mut references = Vec::new();
    let mut reference_default = false;

    while let Some(option) = args.next_option()? {
        match option.as_str() {
            "--reference-default" => reference_default = true,
            "--input" => set_once(&mut input, args.os_path(&option)?, &option)?,
            "--rdl-output" => set_once(&mut rdl_output, args.os_path(&option)?, &option)?,
            "--winmd-output" => set_once(&mut winmd_output, args.os_path(&option)?, &option)?,
            "--reference" => references.push(args.os_path(&option)?),
            "--help" | "-h" => {
                println!("{}", help_text());
                return Ok(());
            }
            _ => {
                return Err(format!(
                    "unknown roundtrip option `{option}`\n\n{}",
                    help_text()
                ));
            }
        }
    }

    let input: PathBuf = required(input, "--input")?;
    let rdl_output: PathBuf = required(rdl_output, "--rdl-output")?;
    let winmd_output: PathBuf = required(winmd_output, "--winmd-output")?;

    writer()
        .input(&input)
        .output(&rdl_output)
        .write()
        .map_err(|error| format!("failed to write RDL: {error}"))?;

    let mut compiler = reader();
    compiler.input(&rdl_output).output(&winmd_output);
    compiler.references(&references);
    if reference_default {
        compiler.reference_default();
    }
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

pub fn help_text() -> &'static str {
    "Usage:
  win32metadata-tools roundtrip \\
    --input <input.winmd> \\
    --rdl-output <output.rdl> \\
    --winmd-output <output.winmd> \\
    [--reference-default] \\
    [--reference <reference.winmd>]..."
}
