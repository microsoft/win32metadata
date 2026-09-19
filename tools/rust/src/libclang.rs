//! Pinned libclang provisioning with actionable errors.
//!
//! `windows_clang::ensure_libclang` resolves (and, if needed, downloads) the pinned
//! `libclang.runtime.win-<arch>` NuGet package unless `LIBCLANG_PATH` is already set. It
//! panics on failure, so everything here funnels through [`crate::catch::catch`] and adds
//! the remediation steps a build engineer needs.

use std::ffi::OsString;
use std::path::{Path, PathBuf};

use crate::args::Args;
use crate::catch::catch;

/// Where the loaded `libclang.dll` came from.
#[derive(Clone, Copy, PartialEq, Eq, Debug)]
pub enum Source {
    /// Explicit `--libclang-path`.
    Option,
    /// Pre-existing `LIBCLANG_PATH` in the environment.
    Environment,
    /// The pinned `libclang.runtime.win-<arch>` NuGet package.
    Pinned,
}

impl Source {
    fn describe(self) -> &'static str {
        match self {
            Self::Option => "--libclang-path",
            Self::Environment => "LIBCLANG_PATH",
            Self::Pinned => "pinned libclang.runtime.win-<arch> NuGet package",
        }
    }
}

/// A libclang installation that has been located and (optionally) version-checked.
pub struct Provisioned {
    pub directory: PathBuf,
    pub version: String,
    pub source: Source,
}

impl std::fmt::Display for Provisioned {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(
            f,
            "libclang {} from {} ({})",
            self.version,
            self.directory.display(),
            self.source.describe()
        )
    }
}

/// The libclang version `windows-clang` is built and tested against.
pub fn pinned_version() -> &'static str {
    windows_clang::LIBCLANG_VERSION
}

/// Locates libclang, points `LIBCLANG_PATH` at it, and reports what was loaded.
///
/// `explicit` wins over an inherited `LIBCLANG_PATH`; when neither is present the pinned
/// NuGet package is restored on demand. `verify` rejects a library whose reported version
/// is not the pinned one.
pub fn provision(explicit: Option<&Path>, verify: bool) -> Result<Provisioned, String> {
    let pinned = pinned_version();

    let (directory, source) = match explicit {
        Some(directory) => {
            if !directory.join("libclang.dll").is_file() {
                return Err(format!(
                    "`--libclang-path {}` does not contain `libclang.dll`.\n\
                     Point it at the directory holding a libclang {pinned} build, or omit the \
                     option to restore the pinned `libclang.runtime.win-<arch>` NuGet package.",
                    directory.display()
                ));
            }
            set_libclang_path(directory);
            (directory.to_path_buf(), Source::Option)
        }
        None => match std::env::var_os("LIBCLANG_PATH") {
            Some(existing) => (PathBuf::from(existing), Source::Environment),
            None => {
                let directory = catch(
                    &format!("failed to provision the pinned libclang {pinned}"),
                    windows_clang::libclang_dir,
                )
                .map_err(|error| {
                    format!(
                        "{error}\n\
                         Restore it manually and set `LIBCLANG_PATH` (or pass \
                         `--libclang-path`):\n  \
                         nuget install libclang.runtime.win-x64 -Version {pinned}\n\
                         The automatic restore uses `curl` and `tar` from System32 against \
                         nuget.org; both must be reachable."
                    )
                })?;
                set_libclang_path(&directory);
                (directory, Source::Pinned)
            }
        },
    };

    let version = catch("failed to load libclang", windows_clang::clang_version)
        .and_then(|result| result.map_err(|error| format!("failed to load libclang: {error}")))
        .map_err(|error| {
            format!(
                "{error}\n\
                 `{}` must contain a loadable libclang {pinned} build.",
                directory.display()
            )
        })?;

    if verify {
        catch(
            "libclang version check failed",
            windows_clang::assert_libclang_version,
        )?;
    }

    Ok(Provisioned {
        directory,
        version,
        source,
    })
}

fn set_libclang_path(directory: &Path) {
    // SAFETY: called from `main` before any libclang load or scrape worker is spawned.
    unsafe {
        std::env::set_var("LIBCLANG_PATH", directory);
    }
}

/// `libclang` command: resolve, load, and report the pinned libclang.
pub fn run(args: Vec<OsString>) -> Result<(), String> {
    let mut args = Args::new(args);
    let mut path = None;
    let mut verify = true;

    while let Some(option) = args.next_option()? {
        match option.as_str() {
            "--libclang-path" => path = Some(args.path(&option)?),
            "--no-version-check" => verify = false,
            "--help" | "-h" => {
                println!("{}", help_text());
                return Ok(());
            }
            _ => {
                return Err(format!(
                    "unknown libclang option `{option}`\n\n{}",
                    help_text()
                ));
            }
        }
    }

    let provisioned = provision(path.as_deref(), verify)?;
    println!("Pinned version: {}", pinned_version());
    println!("Loaded version: {}", provisioned.version);
    println!("Directory:      {}", provisioned.directory.display());
    println!("Source:         {}", provisioned.source.describe());
    Ok(())
}

fn help_text() -> &'static str {
    "Usage:
  win32metadata-tools libclang [--libclang-path <dir>] [--no-version-check]

Resolves the pinned libclang, loads it, and prints the version and directory.
Restores the `libclang.runtime.win-<arch>` NuGet package on demand unless
`LIBCLANG_PATH` is already set."
}
