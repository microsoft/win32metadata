use std::collections::{BTreeMap, BTreeSet};
use std::path::{Path, PathBuf};

struct ApprovedRootConflict {
    path: &'static str,
    owners: &'static [(&'static str, &'static str)],
}

const APPROVED_CROSS_NAMESPACE_ROOTS: [ApprovedRootConflict; 7] = [
    ApprovedRootConflict {
        path: "shared/ntddstor.h",
        owners: &[
            ("Fs", "Windows.Win32.Storage.FileSystem"),
            ("Ioctl", "Windows.Win32.System.Ioctl"),
        ],
    },
    ApprovedRootConflict {
        path: "shared/uuids.h",
        owners: &[
            ("Media", "Windows.Win32.Media"),
            ("Mf", "Windows.Win32.Media.MediaFoundation"),
        ],
    },
    ApprovedRootConflict {
        path: "um/audioendpoints.h",
        owners: &[
            ("Audio", "Windows.Win32.Media.Audio"),
            ("Audio.Endpoints", "Windows.Win32.Media.Audio.Endpoints"),
        ],
    },
    ApprovedRootConflict {
        path: "um/dxcore.h",
        owners: &[
            ("DXCore", "Windows.Win32.Graphics.DXCore"),
            ("Display", "Windows.Win32.Devices.Display"),
        ],
    },
    ApprovedRootConflict {
        path: "um/dxcore_interface.h",
        owners: &[
            ("DXCore", "Windows.Win32.Graphics.DXCore"),
            ("Display", "Windows.Win32.Devices.Display"),
        ],
    },
    ApprovedRootConflict {
        path: "um/endpointvolume.h",
        owners: &[
            ("Audio", "Windows.Win32.Media.Audio"),
            ("Audio.Endpoints", "Windows.Win32.Media.Audio.Endpoints"),
        ],
    },
    ApprovedRootConflict {
        path: "um/idispids.h",
        owners: &[
            ("ComOle", "Windows.Win32.System.Ole"),
            ("InternetExplorer", "Windows.Win32.Web.InternetExplorer"),
        ],
    },
];

#[derive(Clone, Debug, Eq, PartialEq)]
pub struct Setting {
    pub name: String,
    pub values: Vec<String>,
}

#[derive(Clone, Debug)]
pub struct Partition {
    pub name: String,
    pub directory: PathBuf,
    pub source: String,
    pub settings: Vec<Setting>,
}

#[derive(Debug, Default, Eq, PartialEq)]
pub struct ResolvedRoots {
    pub files: Vec<PathBuf>,
    pub directories: Vec<PathBuf>,
}

#[derive(Clone, Debug)]
struct ResolvedRootClaim {
    partition: String,
    namespace: String,
    requested: String,
    path: PathBuf,
    scope_fallback: Option<(String, String)>,
}

#[derive(Debug)]
struct IncludeRootResolution {
    path: PathBuf,
    scope_fallback: Option<(String, String)>,
}

#[derive(Clone, Copy, Debug, Eq, Ord, PartialEq, PartialOrd)]
pub enum TypeOverride {
    U32,
}

#[derive(Clone, Copy, Debug, Eq, Ord, PartialEq, PartialOrd)]
pub enum ForcedAttribute {
    Flags,
}

#[derive(Clone, Debug, Eq, PartialEq)]
pub struct PartitionPolicy {
    pub namespace: String,
    pub exclusions: BTreeSet<String>,
    pub remaps: BTreeMap<String, String>,
    pub type_overrides: BTreeMap<String, TypeOverride>,
    pub attributes: BTreeMap<String, BTreeSet<ForcedAttribute>>,
    pub libraries: BTreeMap<String, String>,
    pub preserve_auto_fnptr_level: BTreeSet<String>,
    pub exclude_empty_records: bool,
    pub standard: Option<String>,
    pub include_directories: Vec<String>,
    pub legacy_output: Option<String>,
}

impl Partition {
    pub fn input_name(&self) -> Result<String, String> {
        self.directory
            .join("main.cpp")
            .to_str()
            .map(|path| path.replace('\\', "/"))
            .ok_or_else(|| {
                format!(
                    "partition `{}` main.cpp path is not valid Unicode",
                    self.name
                )
            })
    }

    #[cfg(test)]
    pub fn namespace(&self) -> Result<String, String> {
        Ok(self.policy()?.namespace)
    }

    pub fn values<'a>(&'a self, name: &'a str) -> impl Iterator<Item = &'a str> + 'a {
        self.settings
            .iter()
            .filter(move |setting| setting.name == name)
            .flat_map(|setting| setting.values.iter().map(String::as_str))
    }

    pub fn key_value_pairs(&self, name: &str) -> Result<BTreeMap<String, String>, String> {
        let mut result = BTreeMap::new();
        for value in self.values(name) {
            let (source, target) = value.split_once('=').ok_or_else(|| {
                format!(
                    "partition `{}` setting `{name}` value `{value}` must contain `=`",
                    self.name
                )
            })?;
            if source.is_empty() || target.is_empty() {
                return Err(format!(
                    "partition `{}` setting `{name}` value `{value}` must have non-empty source and target",
                    self.name
                ));
            }
            result.insert(source.to_string(), target.to_string());
        }
        Ok(result)
    }

    pub fn policy(&self) -> Result<PartitionPolicy, String> {
        const SUPPORTED: [&str; 12] = [
            "--config",
            "--exclude",
            "--include-directory",
            "--namespace",
            "--output",
            "--preserve-auto-fnptr-level",
            "--remap",
            "--std",
            "--traverse",
            "--with-attribute",
            "--with-librarypath",
            "--with-type",
        ];
        for setting in &self.settings {
            if !SUPPORTED.contains(&setting.name.as_str()) {
                return Err(format!(
                    "partition `{}` has unsupported setting `{}`",
                    self.name, setting.name
                ));
            }
        }

        let namespaces = self.values("--namespace").collect::<Vec<_>>();
        let namespace = match namespaces.as_slice() {
            [namespace] if !namespace.is_empty() => (*namespace).to_string(),
            [] => return Err(format!("partition `{}` has no --namespace", self.name)),
            _ => {
                return Err(format!(
                    "partition `{}` must have exactly one --namespace value",
                    self.name
                ));
            }
        };

        let mut exclude_empty_records = false;
        for value in self.values("--config") {
            match value {
                "exclude-empty-records" => exclude_empty_records = true,
                _ => {
                    return Err(format!(
                        "partition `{}` has unsupported --config value `{value}`",
                        self.name
                    ));
                }
            }
        }

        let standards = self.values("--std").collect::<Vec<_>>();
        let standard = match standards.as_slice() {
            [] => None,
            ["c++20"] => Some("c++20".to_string()),
            [value] => {
                return Err(format!(
                    "partition `{}` has unsupported --std value `{value}`",
                    self.name
                ));
            }
            _ => {
                return Err(format!(
                    "partition `{}` must have at most one --std value",
                    self.name
                ));
            }
        };

        let mut type_overrides = BTreeMap::new();
        for (name, value) in self.key_value_pairs("--with-type")? {
            let ty = match value.as_str() {
                "uint" => TypeOverride::U32,
                _ => {
                    return Err(format!(
                        "partition `{}` has unsupported --with-type value `{name}={value}`",
                        self.name
                    ));
                }
            };
            type_overrides.insert(name, ty);
        }

        let mut attributes = BTreeMap::<String, BTreeSet<ForcedAttribute>>::new();
        for value in self.values("--with-attribute") {
            let (name, value) = value.split_once('=').ok_or_else(|| {
                format!(
                    "partition `{}` setting `--with-attribute` value `{value}` must contain `=`",
                    self.name
                )
            })?;
            let attribute = match value {
                "Flags" => ForcedAttribute::Flags,
                _ => {
                    return Err(format!(
                        "partition `{}` has unsupported --with-attribute value `{name}={value}`",
                        self.name
                    ));
                }
            };
            attributes
                .entry(name.to_string())
                .or_default()
                .insert(attribute);
        }

        let outputs = self.values("--output").collect::<Vec<_>>();
        let legacy_output = match outputs.as_slice() {
            [] => None,
            [r"<GeneratedSourceDir>\<PartitionName>.cs"] => {
                Some(r"<GeneratedSourceDir>\<PartitionName>.cs".to_string())
            }
            [value] => {
                return Err(format!(
                    "partition `{}` has unsupported legacy --output value `{value}`",
                    self.name
                ));
            }
            _ => {
                return Err(format!(
                    "partition `{}` must have at most one --output value",
                    self.name
                ));
            }
        };

        Ok(PartitionPolicy {
            namespace,
            exclusions: self.values("--exclude").map(str::to_string).collect(),
            remaps: self.key_value_pairs("--remap")?,
            type_overrides,
            attributes,
            libraries: self.key_value_pairs("--with-librarypath")?,
            preserve_auto_fnptr_level: self
                .values("--preserve-auto-fnptr-level")
                .map(str::to_string)
                .collect(),
            exclude_empty_records,
            standard,
            include_directories: self
                .values("--include-directory")
                .map(str::to_string)
                .collect(),
            legacy_output,
        })
    }

    pub fn traverse(&self) -> impl Iterator<Item = &str> {
        self.values("--traverse")
    }

    #[cfg(test)]
    pub fn include_roots(&self) -> impl Iterator<Item = &str> {
        self.traverse()
            .filter_map(|value| value.strip_prefix("<IncludeRoot>"))
    }

    #[cfg(test)]
    pub fn normalized_include_roots(&self) -> impl Iterator<Item = String> + '_ {
        self.include_roots()
            .filter(|root| Path::new(root).extension().is_some())
            .map(normalize_path)
    }

    pub fn resolve_roots(&self, include_dirs: &[PathBuf]) -> Result<ResolvedRoots, String> {
        let mut result = ResolvedRoots::default();
        for value in self.traverse() {
            let path = if let Some(relative) = value.strip_prefix("<PartitionDir>/") {
                self.directory.join(relative)
            } else if let Some(relative) = value.strip_prefix("<IncludeRoot>/") {
                resolve_include_root(relative, include_dirs)
                    .map(|resolution| resolution.path)
                    .ok_or_else(|| {
                        format!(
                            "partition `{}` root `{value}` was not found in the configured include directories",
                            self.name
                        )
                    })?
            } else {
                return Err(format!(
                    "partition `{}` has unsupported --traverse value `{value}`",
                    self.name
                ));
            };
            if path.is_file() {
                result.files.push(path);
            } else if path.is_dir() {
                result.directories.push(path);
            } else {
                return Err(format!(
                    "partition `{}` root `{value}` resolved to missing path `{}`",
                    self.name,
                    path.display()
                ));
            }
        }
        Ok(result)
    }
}

pub fn validate_resolved_root_ownership(
    partitions: &[Partition],
    include_dirs: &[PathBuf],
) -> Result<(), String> {
    let mut claims = Vec::<ResolvedRootClaim>::new();
    let mut requested_roots = BTreeMap::<(String, String), Vec<String>>::new();
    for partition in partitions {
        let namespace = partition.policy()?.namespace;
        for requested in partition.traverse() {
            requested_roots
                .entry((partition.name.clone(), normalize_path_identity(requested)))
                .or_default()
                .push(requested.to_string());
            let (path, scope_fallback) = if let Some(relative) =
                requested.strip_prefix("<PartitionDir>/")
            {
                (partition.directory.join(relative), None)
            } else if let Some(relative) = requested.strip_prefix("<IncludeRoot>/") {
                let resolution =
                        resolve_include_root(relative, include_dirs).ok_or_else(|| {
                            format!(
                                "partition `{}` root `{requested}` was not found in the configured include directories",
                                partition.name
                            )
                        })?;
                (resolution.path, resolution.scope_fallback)
            } else {
                return Err(format!(
                    "partition `{}` has unsupported --traverse value `{requested}`",
                    partition.name
                ));
            };

            let mut paths = Vec::new();
            if path.is_file() {
                paths.push(path);
            } else if path.is_dir() {
                collect_root_files(&path, &mut paths)?;
            } else {
                return Err(format!(
                    "partition `{}` root `{requested}` resolved to missing path `{}`",
                    partition.name,
                    path.display()
                ));
            }
            paths.sort();
            paths.dedup();
            claims.extend(paths.into_iter().map(|path| ResolvedRootClaim {
                partition: partition.name.clone(),
                namespace: namespace.clone(),
                requested: requested.to_string(),
                path,
                scope_fallback: scope_fallback.clone(),
            }));
        }
    }

    let mut errors = Vec::new();
    for ((partition, _), roots) in requested_roots {
        if roots.len() > 1 {
            let spellings = roots.iter().collect::<BTreeSet<_>>();
            let description = if spellings.len() == 1 {
                "duplicate root"
            } else {
                "case- or separator-only duplicate roots"
            };
            errors.push(format!(
                "partition `{partition}` has {description}: {}",
                spellings
                    .into_iter()
                    .map(|root| format!("`{root}`"))
                    .collect::<Vec<_>>()
                    .join(", ")
            ));
        }
    }

    let mut claims_by_path = BTreeMap::<String, Vec<ResolvedRootClaim>>::new();
    for claim in claims {
        claims_by_path
            .entry(normalized_physical_path(&claim.path)?)
            .or_default()
            .push(claim);
    }

    for (path, claims) in claims_by_path {
        for claim in claims.iter().filter(|claim| claim.scope_fallback.is_some()) {
            let paired = claims.iter().any(|candidate| {
                candidate.partition == claim.partition && candidate.scope_fallback.is_none()
            });
            if !paired {
                let (requested_scope, actual_scope) =
                    claim.scope_fallback.as_ref().expect("filtered fallback");
                errors.push(format!(
                    "partition `{}` root `{}` requested SDK scope `{requested_scope}` but resolved under `{actual_scope}` to `{}` without explicitly rooting that physical header",
                    claim.partition,
                    claim.requested,
                    claim.path.display()
                ));
            }
        }

        let namespaces = claims
            .iter()
            .map(|claim| claim.namespace.as_str())
            .collect::<BTreeSet<_>>();
        let observed_owners = claims
            .iter()
            .map(|claim| (claim.partition.as_str(), claim.namespace.as_str()))
            .collect::<BTreeSet<_>>();
        let allowed = APPROVED_CROSS_NAMESPACE_ROOTS
            .iter()
            .find(|approved| {
                path == approved.path || path.ends_with(&format!("/{}", approved.path))
            })
            .is_some_and(|approved| {
                observed_owners == approved.owners.iter().copied().collect::<BTreeSet<_>>()
            });
        if namespaces.len() > 1 && !allowed {
            let owners = claims
                .iter()
                .map(|claim| {
                    format!(
                        "{} ({}) via {}",
                        claim.partition, claim.namespace, claim.requested
                    )
                })
                .collect::<BTreeSet<_>>()
                .into_iter()
                .collect::<Vec<_>>()
                .join("; ");
            errors.push(format!(
                "physical root `{}` is claimed by multiple namespaces: {owners}",
                claims[0].path.display()
            ));
        }
    }

    errors.sort();
    errors.dedup();
    if errors.is_empty() {
        Ok(())
    } else {
        Err(format!(
            "partition root ownership preflight failed:\n{}",
            errors
                .into_iter()
                .map(|error| format!("- {error}"))
                .collect::<Vec<_>>()
                .join("\n")
        ))
    }
}

#[cfg(test)]
pub fn load_active(root: &Path) -> Result<Vec<Partition>, String> {
    let mut directories = std::fs::read_dir(root)
        .map_err(|error| format!("failed to read `{}`: {error}", root.display()))?
        .map(|entry| {
            entry
                .map(|entry| entry.path())
                .map_err(|error| format!("failed to read `{}`: {error}", root.display()))
        })
        .collect::<Result<Vec<_>, _>>()?;
    directories.sort_by(|left, right| {
        left.file_name()
            .map(|name| name.to_string_lossy().to_ascii_lowercase())
            .cmp(
                &right
                    .file_name()
                    .map(|name| name.to_string_lossy().to_ascii_lowercase()),
            )
    });

    directories
        .into_iter()
        .filter(|directory| directory.join("main.cpp").is_file())
        .map(load_directory)
        .collect()
}

pub fn load_main(main: &Path) -> Result<Partition, String> {
    if main.file_name().and_then(|name| name.to_str()) != Some("main.cpp") {
        return Err(format!(
            "partition input must be named `main.cpp`: `{}`",
            main.display()
        ));
    }
    let directory = main.parent().ok_or_else(|| {
        format!(
            "partition input has no parent directory: `{}`",
            main.display()
        )
    })?;
    load_directory(directory.to_path_buf())
}

fn load_directory(directory: PathBuf) -> Result<Partition, String> {
    let name = directory
        .file_name()
        .and_then(|name| name.to_str())
        .ok_or_else(|| format!("invalid partition directory `{}`", directory.display()))?
        .to_string();
    let main = directory.join("main.cpp");
    let settings = directory.join("settings.rsp");
    let source = std::fs::read_to_string(&main)
        .map_err(|error| format!("failed to read `{}`: {error}", main.display()))?;
    let settings_source = std::fs::read_to_string(&settings)
        .map_err(|error| format!("failed to read `{}`: {error}", settings.display()))?;
    let settings = parse_settings(&settings_source)
        .map_err(|error| format!("failed to parse `{}`: {error}", settings.display()))?;
    let partition = Partition {
        name,
        directory,
        source,
        settings,
    };
    partition.policy()?;
    if partition.traverse().next().is_none() {
        return Err(format!(
            "partition `{}` has no --traverse values",
            partition.name
        ));
    }
    Ok(partition)
}

pub fn parse_settings(source: &str) -> Result<Vec<Setting>, String> {
    let mut result = Vec::<Setting>::new();
    for (index, raw) in source.lines().enumerate() {
        let line = raw.trim_end_matches('\r').trim_start_matches('\u{feff}');
        if line.starts_with("--") {
            result.push(Setting {
                name: line.to_string(),
                values: Vec::new(),
            });
        } else if let Some(setting) = result.last_mut() {
            if !line.is_empty() {
                setting.values.push(line.to_string());
            }
        } else if !line.is_empty() {
            return Err(format!(
                "line {} appears before a settings block: `{line}`",
                index + 1
            ));
        }
    }
    Ok(result)
}

#[cfg(test)]
pub fn namespaces(partitions: &[Partition]) -> Result<BTreeSet<String>, String> {
    partitions.iter().map(Partition::namespace).collect()
}

#[cfg(test)]
pub fn option_counts(partitions: &[Partition]) -> BTreeMap<String, usize> {
    let mut result = BTreeMap::new();
    for setting in partitions
        .iter()
        .flat_map(|partition| partition.settings.iter())
    {
        *result.entry(setting.name.clone()).or_default() += 1;
    }
    result
}

#[cfg(test)]
pub fn input_namespaces(partitions: &[Partition]) -> Result<BTreeMap<String, String>, String> {
    partitions
        .iter()
        .map(|partition| Ok((partition.input_name()?, partition.namespace()?)))
        .collect()
}

#[cfg(test)]
pub fn root_namespace_conflicts(
    partitions: &[Partition],
) -> Result<BTreeMap<String, BTreeSet<String>>, String> {
    let mut owners = BTreeMap::<String, BTreeSet<String>>::new();
    for partition in partitions {
        let namespace = partition.namespace()?;
        for root in partition.normalized_include_roots() {
            owners.entry(root).or_default().insert(namespace.clone());
        }
    }
    owners.retain(|_, namespaces| namespaces.len() > 1);
    Ok(owners)
}

#[cfg(test)]
fn normalize_path(path: &str) -> String {
    path.trim()
        .replace('\\', "/")
        .trim_start_matches('/')
        .to_ascii_lowercase()
}

fn resolve_include_root(relative: &str, include_dirs: &[PathBuf]) -> Option<IncludeRootResolution> {
    let relative = relative.replace('\\', "/");
    let (scope, scoped_relative) = relative.split_once('/').unwrap_or(("", &relative));
    for directory in include_dirs {
        let directory_scope = directory
            .file_name()
            .and_then(|name| name.to_str())
            .unwrap_or_default();
        let candidate = if directory_scope.eq_ignore_ascii_case(scope) {
            directory.join(scoped_relative)
        } else if is_sdk_scope(directory_scope) {
            continue;
        } else {
            let scoped = directory.join(&relative);
            if scoped.exists() {
                scoped
            } else {
                directory.join(scoped_relative)
            }
        };
        if candidate.exists() {
            return Some(IncludeRootResolution {
                path: candidate,
                scope_fallback: None,
            });
        }
    }
    include_dirs.iter().find_map(|directory| {
        let candidate = directory.join(scoped_relative);
        if !candidate.exists() {
            return None;
        }
        let actual_scope = directory
            .file_name()
            .and_then(|name| name.to_str())
            .unwrap_or_default();
        let scope_fallback = (is_sdk_scope(scope)
            && is_sdk_scope(actual_scope)
            && !scope.eq_ignore_ascii_case(actual_scope))
        .then(|| (scope.to_string(), actual_scope.to_string()));
        Some(IncludeRootResolution {
            path: candidate,
            scope_fallback,
        })
    })
}

fn is_sdk_scope(value: &str) -> bool {
    ["shared", "um", "ucrt", "winrt"]
        .iter()
        .any(|scope| value.eq_ignore_ascii_case(scope))
}

fn collect_root_files(directory: &Path, files: &mut Vec<PathBuf>) -> Result<(), String> {
    let mut entries = std::fs::read_dir(directory)
        .map_err(|error| {
            format!(
                "failed to read root directory `{}`: {error}",
                directory.display()
            )
        })?
        .map(|entry| {
            entry.map(|entry| entry.path()).map_err(|error| {
                format!(
                    "failed to read root directory `{}`: {error}",
                    directory.display()
                )
            })
        })
        .collect::<Result<Vec<_>, _>>()?;
    entries.sort();
    for entry in entries {
        if entry.is_dir() {
            collect_root_files(&entry, files)?;
        } else if entry.is_file() {
            files.push(entry);
        }
    }
    Ok(())
}

fn normalized_physical_path(path: &Path) -> Result<String, String> {
    std::fs::canonicalize(path)
        .map_err(|error| format!("failed to canonicalize root `{}`: {error}", path.display()))
        .map(|path| {
            path.to_string_lossy()
                .replace('\\', "/")
                .to_ascii_lowercase()
        })
}

fn normalize_path_identity(path: &str) -> String {
    path.trim().replace('\\', "/").to_ascii_lowercase()
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn settings_preserve_order_and_all_option_values() {
        let settings = parse_settings(
            "\u{feff}--exclude\r\nOne\r\nTwo\r\n--traverse\r\n<IncludeRoot>/um/a.h\r\n\
             --namespace\r\nWindows.Win32.Test\r\n--with-type\r\nTYPE_A\r\n",
        )
        .unwrap();
        assert_eq!(
            settings,
            [
                Setting {
                    name: "--exclude".to_string(),
                    values: vec!["One".to_string(), "Two".to_string()],
                },
                Setting {
                    name: "--traverse".to_string(),
                    values: vec!["<IncludeRoot>/um/a.h".to_string()],
                },
                Setting {
                    name: "--namespace".to_string(),
                    values: vec!["Windows.Win32.Test".to_string()],
                },
                Setting {
                    name: "--with-type".to_string(),
                    values: vec!["TYPE_A".to_string()],
                },
            ]
        );
    }

    #[test]
    fn repeated_blocks_preserve_their_position() {
        let settings = parse_settings("--exclude\nA\n--traverse\na.h\n--exclude\nB\n").unwrap();
        assert_eq!(settings.len(), 3);
        assert_eq!(settings[0].name, "--exclude");
        assert_eq!(settings[1].name, "--traverse");
        assert_eq!(settings[2].values, ["B"]);
    }

    #[test]
    fn key_value_pairs_apply_later_overrides() {
        let partition = Partition {
            name: "Test".to_string(),
            directory: PathBuf::new(),
            source: String::new(),
            settings: parse_settings("--remap\nA=B\n--remap\nA=C\nD=E\n").unwrap(),
        };
        assert_eq!(
            partition.key_value_pairs("--remap").unwrap(),
            BTreeMap::from([
                ("A".to_string(), "C".to_string()),
                ("D".to_string(), "E".to_string()),
            ])
        );
    }

    #[test]
    fn policy_rejects_unknown_switches_and_values() {
        let partition = Partition {
            name: "Test".to_string(),
            directory: PathBuf::new(),
            source: String::new(),
            settings: parse_settings(
                "--namespace\nWindows.Win32.Test\n--traverse\n<IncludeRoot>/um/test.h\n\
                 --with-type\nVALUE=ushort\n",
            )
            .unwrap(),
        };
        assert_eq!(
            partition.policy().unwrap_err(),
            "partition `Test` has unsupported --with-type value `VALUE=ushort`"
        );

        let partition = Partition {
            settings: parse_settings(
                "--namespace\nWindows.Win32.Test\n--traverse\n<IncludeRoot>/um/test.h\n\
                 --unknown\nvalue\n",
            )
            .unwrap(),
            ..partition
        };
        assert_eq!(
            partition.policy().unwrap_err(),
            "partition `Test` has unsupported setting `--unknown`"
        );

        let partition = Partition {
            settings: parse_settings(
                "--namespace\nWindows.Win32.Test\n--traverse\n<IncludeRoot>/um/test.h\n\
                 --output\nother.cs\n",
            )
            .unwrap(),
            ..partition
        };
        assert_eq!(
            partition.policy().unwrap_err(),
            "partition `Test` has unsupported legacy --output value `other.cs`"
        );
    }

    #[test]
    fn loads_a_partition_from_its_main_translation_unit() {
        let main = Path::new(env!("CARGO_MANIFEST_DIR"))
            .join("..")
            .join("..")
            .join("generation")
            .join("WinSDK")
            .join("Partitions")
            .join("Audio")
            .join("main.cpp");
        let partition = load_main(&main).unwrap();
        assert_eq!(partition.name, "Audio");
        assert_eq!(partition.namespace().unwrap(), "Windows.Win32.Media.Audio");
        assert!(partition.source.contains("#include <audioclient.h>"));
    }

    #[test]
    fn resolves_scoped_custom_and_partition_roots_in_precedence_order() {
        let root = std::env::temp_dir().join(format!(
            "win32metadata-partition-roots-{}",
            std::process::id()
        ));
        std::fs::remove_dir_all(&root).ok();
        let custom = root.join("cpdk");
        let shared = root.join("shared");
        let um = root.join("um");
        let partition_dir = root.join("Partition");
        for directory in [&custom, &shared, &um, &partition_dir] {
            std::fs::create_dir_all(directory).unwrap();
        }
        std::fs::write(custom.join("provider.h"), "").unwrap();
        std::fs::write(shared.join("status.h"), "").unwrap();
        std::fs::write(shared.join("shared-only.h"), "").unwrap();
        std::fs::write(um.join("status.h"), "").unwrap();
        std::fs::write(partition_dir.join("manual.h"), "").unwrap();

        let partition = Partition {
            name: "Test".to_string(),
            directory: partition_dir.clone(),
            source: String::new(),
            settings: vec![Setting {
                name: "--traverse".to_string(),
                values: vec![
                    "<IncludeRoot>/um/provider.h".to_string(),
                    "<IncludeRoot>/shared/status.h".to_string(),
                    "<IncludeRoot>/um/shared-only.h".to_string(),
                    "<PartitionDir>/manual.h".to_string(),
                ],
            }],
        };
        let roots = partition
            .resolve_roots(&[custom.clone(), shared.clone(), um])
            .unwrap();
        assert_eq!(
            roots.files,
            [
                custom.join("provider.h"),
                shared.join("status.h"),
                shared.join("shared-only.h"),
                partition_dir.join("manual.h"),
            ]
        );
        assert!(roots.directories.is_empty());
        std::fs::remove_dir_all(root).unwrap();
    }

    #[test]
    fn root_preflight_rejects_unpaired_sdk_scope_fallback() {
        let root = std::env::temp_dir().join(format!(
            "win32metadata-partition-preflight-fallback-{}",
            std::process::id()
        ));
        std::fs::remove_dir_all(&root).ok();
        let shared = root.join("shared");
        let um = root.join("um");
        std::fs::create_dir_all(&shared).unwrap();
        std::fs::create_dir_all(&um).unwrap();
        std::fs::write(shared.join("dciddi.h"), "").unwrap();

        let partition = test_partition(
            &root,
            "Direct2D",
            "Windows.Win32.Graphics.Direct2D",
            &["<IncludeRoot>/um/dciddi.h"],
        );
        let error = validate_resolved_root_ownership(&[partition], &[shared, um]).unwrap_err();
        assert!(
            error.contains("requested SDK scope `um` but resolved under `shared`"),
            "{error}"
        );
        std::fs::remove_dir_all(root).unwrap();
    }

    #[test]
    fn root_preflight_accepts_explicitly_paired_sdk_scope_fallback() {
        let root = std::env::temp_dir().join(format!(
            "win32metadata-partition-preflight-paired-{}",
            std::process::id()
        ));
        std::fs::remove_dir_all(&root).ok();
        let shared = root.join("shared");
        let um = root.join("um");
        std::fs::create_dir_all(&shared).unwrap();
        std::fs::create_dir_all(&um).unwrap();
        std::fs::write(shared.join("usb.h"), "").unwrap();

        let partition = test_partition(
            &root,
            "Buses",
            "Windows.Win32.Devices.Usb",
            &["<IncludeRoot>/shared/usb.h", "<IncludeRoot>/um/usb.h"],
        );
        validate_resolved_root_ownership(&[partition], &[shared, um]).unwrap();
        std::fs::remove_dir_all(root).unwrap();
    }

    #[test]
    fn root_preflight_rejects_unapproved_cross_namespace_owner() {
        let root = std::env::temp_dir().join(format!(
            "win32metadata-partition-preflight-owner-{}",
            std::process::id()
        ));
        std::fs::remove_dir_all(&root).ok();
        let shared = root.join("shared");
        std::fs::create_dir_all(&shared).unwrap();
        std::fs::write(shared.join("collision.h"), "").unwrap();

        let partitions = [
            test_partition(
                &root,
                "First",
                "Windows.Win32.First",
                &["<IncludeRoot>/shared/collision.h"],
            ),
            test_partition(
                &root,
                "Second",
                "Windows.Win32.Second",
                &["<IncludeRoot>/shared/collision.h"],
            ),
        ];
        let error = validate_resolved_root_ownership(&partitions, &[shared]).unwrap_err();
        assert!(error.contains("claimed by multiple namespaces"), "{error}");
        assert!(error.contains("Windows.Win32.First"), "{error}");
        assert!(error.contains("Windows.Win32.Second"), "{error}");
        std::fs::remove_dir_all(root).unwrap();
    }

    #[test]
    fn root_preflight_rejects_expansion_of_an_approved_owner_set() {
        let root = std::env::temp_dir().join(format!(
            "win32metadata-partition-preflight-expanded-owner-{}",
            std::process::id()
        ));
        std::fs::remove_dir_all(&root).ok();
        let shared = root.join("shared");
        std::fs::create_dir_all(&shared).unwrap();
        std::fs::write(shared.join("ntddstor.h"), "").unwrap();

        let partitions = [
            test_partition(
                &root,
                "Fs",
                "Windows.Win32.Storage.FileSystem",
                &["<IncludeRoot>/shared/ntddstor.h"],
            ),
            test_partition(
                &root,
                "Ioctl",
                "Windows.Win32.System.Ioctl",
                &["<IncludeRoot>/shared/ntddstor.h"],
            ),
            test_partition(
                &root,
                "Unexpected",
                "Windows.Win32.Unexpected",
                &["<IncludeRoot>/shared/ntddstor.h"],
            ),
        ];
        let error = validate_resolved_root_ownership(&partitions, &[shared]).unwrap_err();
        assert!(error.contains("claimed by multiple namespaces"), "{error}");
        assert!(error.contains("Windows.Win32.Unexpected"), "{error}");
        std::fs::remove_dir_all(root).unwrap();
    }

    #[test]
    fn root_preflight_rejects_duplicate_partition_roots() {
        let root = std::env::temp_dir().join(format!(
            "win32metadata-partition-preflight-duplicate-{}",
            std::process::id()
        ));
        std::fs::remove_dir_all(&root).ok();
        let shared = root.join("shared");
        std::fs::create_dir_all(&shared).unwrap();
        std::fs::write(shared.join("duplicate.h"), "").unwrap();

        let partition = test_partition(
            &root,
            "Duplicate",
            "Windows.Win32.Duplicate",
            &[
                "<IncludeRoot>/shared/duplicate.h",
                "<IncludeRoot>/shared/duplicate.h",
            ],
        );
        let error = validate_resolved_root_ownership(&[partition], &[shared]).unwrap_err();
        assert!(error.contains("has duplicate root"), "{error}");
        std::fs::remove_dir_all(root).unwrap();
    }

    fn test_partition(root: &Path, name: &str, namespace: &str, roots: &[&str]) -> Partition {
        Partition {
            name: name.to_string(),
            directory: root.join(name),
            source: String::new(),
            settings: vec![
                Setting {
                    name: "--traverse".to_string(),
                    values: roots.iter().map(|root| (*root).to_string()).collect(),
                },
                Setting {
                    name: "--namespace".to_string(),
                    values: vec![namespace.to_string()],
                },
            ],
        }
    }

    #[test]
    fn checked_in_partition_authority_is_complete() {
        let root = Path::new(env!("CARGO_MANIFEST_DIR"))
            .join("..")
            .join("..")
            .join("generation")
            .join("WinSDK")
            .join("Partitions");
        let partitions = load_active(&root).unwrap();
        assert_eq!(partitions.len(), 321);
        assert_eq!(namespaces(&partitions).unwrap().len(), 306);
        assert_eq!(
            partitions
                .iter()
                .map(|partition| partition.include_roots().count())
                .sum::<usize>(),
            1568
        );
        assert_eq!(
            partitions
                .iter()
                .flat_map(Partition::include_roots)
                .map(|root| root.replace('\\', "/").to_ascii_lowercase())
                .collect::<BTreeSet<_>>()
                .len(),
            1560
        );
        assert_eq!(
            partitions
                .iter()
                .filter(|partition| {
                    partition.include_roots().any(|root| {
                        let root = root.replace('\\', "/").to_ascii_lowercase();
                        root.ends_with("/shared/dciddi.h") || root.ends_with("/um/dciddi.h")
                    })
                })
                .map(|partition| partition.name.as_str())
                .collect::<Vec<_>>(),
            ["WinProg"]
        );

        let counts = option_counts(&partitions);
        assert_eq!(counts["--namespace"], 321);
        assert_eq!(counts["--traverse"], 321);
        assert_eq!(counts["--exclude"], 106);
        assert_eq!(counts["--remap"], 13);
        assert_eq!(counts["--with-attribute"], 23);
        assert_eq!(counts["--with-librarypath"], 6);
        assert_eq!(counts["--with-type"], 52);

        let policies = partitions
            .iter()
            .map(Partition::policy)
            .collect::<Result<Vec<_>, _>>()
            .unwrap();
        assert_eq!(
            policies
                .iter()
                .map(|policy| policy.exclusions.len())
                .sum::<usize>(),
            562
        );
        assert_eq!(
            partitions
                .iter()
                .map(|partition| partition.values("--exclude").count())
                .sum::<usize>(),
            563
        );
        assert_eq!(
            policies
                .iter()
                .map(|policy| policy.remaps.len())
                .sum::<usize>(),
            188
        );
        assert_eq!(
            policies
                .iter()
                .map(|policy| policy.type_overrides.len())
                .sum::<usize>(),
            74
        );
        assert_eq!(
            policies
                .iter()
                .map(|policy| { policy.attributes.values().map(BTreeSet::len).sum::<usize>() })
                .sum::<usize>(),
            29
        );
        assert_eq!(
            policies
                .iter()
                .map(|policy| policy.libraries.len())
                .sum::<usize>(),
            13
        );
        assert_eq!(
            policies
                .iter()
                .map(|policy| policy.preserve_auto_fnptr_level.len())
                .sum::<usize>(),
            2
        );
        assert_eq!(
            policies
                .iter()
                .filter(|policy| policy.exclude_empty_records)
                .count(),
            3
        );
        assert_eq!(
            policies
                .iter()
                .filter(|policy| policy.standard.as_deref() == Some("c++20"))
                .count(),
            2
        );
        assert_eq!(
            policies
                .iter()
                .map(|policy| policy.include_directories.len())
                .sum::<usize>(),
            4
        );
        assert_eq!(
            policies
                .iter()
                .filter(|policy| policy.legacy_output.is_some())
                .count(),
            1
        );

        let policy = |name: &str| {
            partitions
                .iter()
                .find(|partition| partition.name == name)
                .unwrap()
                .policy()
                .unwrap()
        };
        assert_eq!(
            policy("Security.Cryptography").remaps["_PIN_INFO"],
            "PIN_INFO"
        );
        assert_eq!(
            policy("Audio.DirectSound").libraries["GetDeviceID"],
            "DSOUND.dll"
        );
        assert_eq!(policy("Tbs").libraries["GetDeviceID"], "tbs.dll");
        assert_eq!(
            policy("Direct3D9").type_overrides["D3DFORMAT"],
            TypeOverride::U32
        );
        assert!(
            policy("Direct3D11").attributes["D3D11_CREATE_DEVICE_FLAG"]
                .contains(&ForcedAttribute::Flags)
        );
        assert!(
            policy("Identity")
                .preserve_auto_fnptr_level
                .contains("PLSA_REDIRECTED_LOGON_CALLBACK")
        );

        let conflicts = root_namespace_conflicts(&partitions).unwrap();
        assert_eq!(
            conflicts.keys().map(String::as_str).collect::<Vec<_>>(),
            APPROVED_CROSS_NAMESPACE_ROOTS
                .iter()
                .map(|approved| approved.path)
                .collect::<Vec<_>>()
        );
        assert_eq!(input_namespaces(&partitions).unwrap().len(), 321);
    }

    #[test]
    fn every_checked_in_partition_root_resolves() {
        let win_sdk = Path::new(env!("CARGO_MANIFEST_DIR"))
            .join("..")
            .join("..")
            .join("generation")
            .join("WinSDK");
        let recompiled = win_sdk.join("RecompiledIdlHeaders");
        let include_dirs = [
            recompiled.join("shared"),
            recompiled.join("um"),
            recompiled.join("ucrt"),
            recompiled.join("winrt"),
            win_sdk.join("AdditionalHeaders").join("cpdk"),
            win_sdk.join("AdditionalHeaders"),
            win_sdk.join("Partitions").join("Com.StructuredStorage"),
            win_sdk.join("inc"),
        ];
        let partitions = load_active(&win_sdk.join("Partitions")).unwrap();
        for partition in &partitions {
            partition.resolve_roots(&include_dirs).unwrap();
        }
        validate_resolved_root_ownership(&partitions, &include_dirs).unwrap();
    }
}
