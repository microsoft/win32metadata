//! Command-line front end for the pinned windows-rs metadata crates.

mod args;
mod catch;
mod libclang;
mod roundtrip;
mod scrape;

use std::env;

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
        Some("roundtrip") => roundtrip::run(args.collect()),
        Some("scrape") => scrape::run(args.collect()),
        Some("libclang") => libclang::run(args.collect()),
        Some("help") | Some("--help") | Some("-h") | None => {
            print_help();
            Ok(())
        }
        Some(command) => Err(format!("unknown command `{command}`\n\n{}", help_text())),
    }
}

fn print_help() {
    println!("{}", help_text());
    println!();
    println!("{}", scrape::help_text());
    println!();
    println!("{}", roundtrip::help_text());
}

fn help_text() -> &'static str {
    "Usage:
  win32metadata-tools <command> [options]

Commands:
  scrape      Partition main.cpp files -> WinMD, via windows-clang and windows-rdl.
  roundtrip   Round-trip a WinMD through RDL back into a WinMD.
  libclang    Resolve and report the pinned libclang.

Run `win32metadata-tools <command> --help` for command options."
}
