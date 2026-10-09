//! Pinned libclang provisioning with actionable errors.
//!
//! `windows_clang::ensure_libclang` resolves (and, if needed, downloads) the pinned
//! `libclang.runtime.win-<arch>` NuGet package unless `LIBCLANG_PATH` is already set. It
//! panics on failure, so everything here funnels through [`crate::catch::catch`] and adds
//! the remediation steps a build engineer needs.

use std::ffi::OsString;
use std::fs;
use std::path::{Path, PathBuf};

use clang_sys::{clang_getCString, clang_getClangVersion, load};
use sha2::{Digest, Sha256};

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
    "22.1.8"
}

const RESOURCE_COMMIT: &str = "ca7933e47d3a3451d81e72ac174dcb5aa28b59d1";
const RESOURCE_MANIFEST: &str = include_str!("clang-resource-manifest.tsv");

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
                    || libclang_dir(pinned),
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

    let version = catch("failed to load libclang", clang_version)
        .and_then(|result| result.map_err(|error| format!("failed to load libclang: {error}")))
        .map_err(|error| {
            format!(
                "{error}\n\
                 `{}` must contain a loadable libclang {pinned} build.",
                directory.display()
            )
        })?;

    if verify {
        if !version_is_pinned(&version, pinned) {
            return Err(format!(
                "libclang version mismatch: expected {pinned}, loaded `{version}`"
            ));
        }
    }

    Ok(Provisioned {
        directory,
        version,
        source,
    })
}

fn libclang_dir(version: &str) -> PathBuf {
    let (id, rid) = if cfg!(target_arch = "x86_64") {
        ("libclang.runtime.win-x64", "win-x64")
    } else if cfg!(target_arch = "aarch64") {
        ("libclang.runtime.win-arm64", "win-arm64")
    } else {
        panic!(
            "automatic libclang provisioning supports only x64 and arm64 hosts; set LIBCLANG_PATH"
        );
    };
    let native = nuget_package(id, version)
        .join("runtimes")
        .join(rid)
        .join("native");
    assert!(
        native.join("libclang.dll").is_file(),
        "`{}` is missing libclang.dll",
        native.display()
    );
    native
}

fn clang_version() -> Result<String, String> {
    load().map_err(|error| format!("failed to load libclang: {error}"))?;
    let version = unsafe { clang_getClangVersion() };
    let value = unsafe { std::ffi::CStr::from_ptr(clang_getCString(version)) }
        .to_string_lossy()
        .into_owned();
    unsafe {
        clang_sys::clang_disposeString(version);
    }
    Ok(value)
}

fn version_is_pinned(reported: &str, pinned: &str) -> bool {
    reported.match_indices(pinned).any(|(index, _)| {
        let before = reported[..index]
            .chars()
            .next_back()
            .is_none_or(|character| !character.is_ascii_digit() && character != '.');
        let after = reported[index + pinned.len()..]
            .chars()
            .next()
            .is_none_or(|character| !character.is_ascii_digit() && character != '.');
        before && after
    })
}

pub fn clang_resource_dir(cache_root: &Path) -> Result<String, String> {
    let relative = Path::new("clang-resource").join(pinned_version());
    let mut candidates = Vec::<(&str, PathBuf)>::new();
    if let Some(directory) = std::env::var_os("LIBCLANG_PATH") {
        candidates.push(("LIBCLANG_PATH", PathBuf::from(directory).join(&relative)));
    }
    if let Ok(executable) = std::env::current_exe()
        && let Some(directory) = executable.parent()
    {
        candidates.push(("generator executable", directory.join(&relative)));
    }
    if let Some(directory) = std::env::var_os("CLANG_RESOURCE_DIR") {
        candidates.push(("CLANG_RESOURCE_DIR", PathBuf::from(directory)));
    }
    candidates.push(("object cache", cache_root.join(&relative)));

    let mut invalid = Vec::new();
    for (source, candidate) in candidates {
        let root = if candidate.file_name().is_some_and(|name| name == "include") {
            candidate.parent().map(Path::to_path_buf)
        } else {
            Some(candidate.clone())
        };
        let Some(root) = root else {
            continue;
        };
        if !root.exists() {
            continue;
        }
        match validate_resource_tree(&root, RESOURCE_MANIFEST) {
            Ok(()) => return Ok(root.to_string_lossy().replace('\\', "/")),
            Err(error) => invalid.push(format!("{source} `{}`: {error}", root.display())),
        }
    }

    let invalid = if invalid.is_empty() {
        String::new()
    } else {
        format!("\nRejected resource trees:\n  {}", invalid.join("\n  "))
    };
    Err(format!(
        "The complete Clang {} resource tree from llvm-project {} was not found beside \
         libclang.dll or the generator executable. Restore or rebuild \
         Microsoft.Windows.WinmdGenerator; generation never downloads headers.{invalid}",
        pinned_version(),
        RESOURCE_COMMIT,
    ))
}

fn validate_resource_tree(root: &Path, manifest: &str) -> Result<(), String> {
    let expected_preamble = format!(
        "# version\t{}\n# llvm-project-commit\t{}\n# sha256\tsize\tpath\n",
        pinned_version(),
        RESOURCE_COMMIT
    );
    if !manifest
        .replace("\r\n", "\n")
        .starts_with(&expected_preamble)
    {
        return Err(
            "pinned manifest metadata does not match the configured version and commit".to_string(),
        );
    }

    let packaged_manifest = fs::read_to_string(root.join("manifest.tsv"))
        .map_err(|error| format!("missing or unreadable manifest.tsv: {error}"))?;
    if packaged_manifest != manifest {
        return Err("manifest.tsv does not match the pinned manifest".to_string());
    }

    let mut expected = std::collections::BTreeMap::new();
    for line in manifest.lines().skip(3) {
        let mut fields = line.splitn(3, '\t');
        let hash = fields.next().unwrap_or_default();
        let size = fields
            .next()
            .ok_or_else(|| format!("invalid pinned manifest entry `{line}`"))?
            .parse::<u64>()
            .map_err(|error| format!("invalid size in pinned manifest entry `{line}`: {error}"))?;
        let path = fields
            .next()
            .ok_or_else(|| format!("invalid pinned manifest entry `{line}`"))?;
        expected.insert(path.to_string(), (hash.to_string(), size));
    }

    let mut actual = Vec::new();
    collect_resource_files(root, root, &mut actual)?;
    actual.sort();
    actual.retain(|path| path != "manifest.tsv");
    let expected_paths = expected.keys().cloned().collect::<Vec<_>>();
    if actual != expected_paths {
        return Err(format!(
            "file set differs from the pinned manifest (expected {}, found {})",
            expected_paths.len(),
            actual.len()
        ));
    }

    for (relative, (expected_hash, expected_size)) in expected {
        let path = root.join(relative.replace('/', std::path::MAIN_SEPARATOR_STR));
        let bytes = fs::read(&path)
            .map_err(|error| format!("failed to read `{}`: {error}", path.display()))?;
        if bytes.len() as u64 != expected_size {
            return Err(format!(
                "`{}` has size {}; expected {expected_size}",
                path.display(),
                bytes.len()
            ));
        }
        let actual_hash = format!("{:X}", Sha256::digest(&bytes));
        if actual_hash != expected_hash {
            return Err(format!(
                "`{}` has SHA-256 {actual_hash}; expected {expected_hash}",
                path.display()
            ));
        }
    }
    Ok(())
}

fn collect_resource_files(
    root: &Path,
    directory: &Path,
    files: &mut Vec<String>,
) -> Result<(), String> {
    for entry in fs::read_dir(directory)
        .map_err(|error| format!("failed to enumerate `{}`: {error}", directory.display()))?
    {
        let entry = entry.map_err(|error| {
            format!(
                "failed to enumerate an entry under `{}`: {error}",
                directory.display()
            )
        })?;
        let path = entry.path();
        if path.is_dir() {
            collect_resource_files(root, &path, files)?;
        } else if path.is_file() {
            files.push(
                path.strip_prefix(root)
                    .map_err(|error| format!("failed to relativize `{}`: {error}", path.display()))?
                    .to_string_lossy()
                    .replace('\\', "/"),
            );
        }
    }
    Ok(())
}

fn nuget_package(id: &str, version: &str) -> PathBuf {
    let root = std::env::var_os("NUGET_PACKAGES").map_or_else(
        || {
            PathBuf::from(
                std::env::var_os("USERPROFILE").expect("NUGET_PACKAGES or USERPROFILE must be set"),
            )
            .join(".nuget")
            .join("packages")
        },
        PathBuf::from,
    );
    let package = root.join(id).join(version);
    if package.is_dir() {
        return package;
    }

    std::fs::create_dir_all(&package)
        .unwrap_or_else(|error| panic!("failed to create `{}`: {error}", package.display()));
    let archive = std::env::temp_dir().join(format!(
        "{}-{}-{id}.{version}.nupkg",
        std::process::id(),
        std::time::SystemTime::now()
            .duration_since(std::time::UNIX_EPOCH)
            .map_or(0, |duration| duration.as_nanos())
    ));
    let url = format!("https://www.nuget.org/api/v2/package/{id}/{version}");
    let download = system_tool("curl.exe")
        .args(["-sSL", &url, "-o"])
        .arg(&archive)
        .status()
        .unwrap_or_else(|error| panic!("failed to download `{id}` {version}: {error}"));
    assert!(download.success(), "failed to download {url}");
    let extract = system_tool("tar.exe")
        .arg("-xf")
        .arg(&archive)
        .arg("-C")
        .arg(&package)
        .status()
        .unwrap_or_else(|error| panic!("failed to extract `{id}` {version}: {error}"));
    std::fs::remove_file(&archive).ok();
    assert!(
        extract.success(),
        "failed to extract `{id}` {version} into `{}`",
        package.display()
    );
    package
}

fn system_tool(name: &str) -> std::process::Command {
    let system32 = std::env::var_os("SystemRoot")
        .map(|root| Path::new(&root).join("System32").join(name))
        .filter(|path| path.is_file());
    std::process::Command::new(system32.unwrap_or_else(|| PathBuf::from(name)))
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

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn resource_tree_requires_every_manifest_file_and_hash() {
        let root = std::env::temp_dir().join(format!(
            "win32metadata-libclang-resource-{}",
            std::process::id()
        ));
        std::fs::remove_dir_all(&root).ok();
        std::fs::create_dir_all(root.join("include")).unwrap();
        std::fs::write(root.join("include").join("intrin.h"), "test").unwrap();
        let hash = format!("{:X}", Sha256::digest(b"test"));
        let manifest = format!(
            "# version\t22.1.8\n# llvm-project-commit\t{RESOURCE_COMMIT}\n# sha256\tsize\tpath\n{hash}\t4\tinclude/intrin.h\n"
        );
        std::fs::write(root.join("manifest.tsv"), &manifest).unwrap();

        assert_eq!(validate_resource_tree(&root, &manifest), Ok(()));
        std::fs::write(root.join("include").join("intrin.h"), "wrong").unwrap();
        assert!(validate_resource_tree(&root, &manifest).is_err());

        std::fs::remove_dir_all(root).ok();
    }
}
