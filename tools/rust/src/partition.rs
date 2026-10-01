use std::path::{Path, PathBuf};

#[cfg(test)]
use std::collections::{BTreeMap, BTreeSet};

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

    pub fn namespace(&self) -> Result<&str, String> {
        let values = self.values("--namespace").collect::<Vec<_>>();
        match values.as_slice() {
            [namespace] if !namespace.is_empty() => Ok(namespace),
            [] => Err(format!("partition `{}` has no --namespace", self.name)),
            _ => Err(format!(
                "partition `{}` must have exactly one --namespace value",
                self.name
            )),
        }
    }

    pub fn values<'a>(&'a self, name: &'a str) -> impl Iterator<Item = &'a str> + 'a {
        self.settings
            .iter()
            .filter(move |setting| setting.name == name)
            .flat_map(|setting| setting.values.iter().map(String::as_str))
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
                resolve_include_root(relative, include_dirs).ok_or_else(|| {
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
    partition.namespace()?;
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
    partitions
        .iter()
        .map(|partition| partition.namespace().map(str::to_string))
        .collect()
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
        .map(|partition| Ok((partition.input_name()?, partition.namespace()?.to_string())))
        .collect()
}

#[cfg(test)]
pub fn root_namespace_conflicts(
    partitions: &[Partition],
) -> Result<BTreeMap<String, BTreeSet<String>>, String> {
    let mut owners = BTreeMap::<String, BTreeSet<String>>::new();
    for partition in partitions {
        let namespace = partition.namespace()?.to_string();
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

fn resolve_include_root(relative: &str, include_dirs: &[PathBuf]) -> Option<PathBuf> {
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
            return Some(candidate);
        }
    }
    None
}

fn is_sdk_scope(value: &str) -> bool {
    ["shared", "um", "ucrt", "winrt"]
        .iter()
        .any(|scope| value.eq_ignore_ascii_case(scope))
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
                partition_dir.join("manual.h"),
            ]
        );
        assert!(roots.directories.is_empty());
        std::fs::remove_dir_all(root).unwrap();
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
            1574
        );
        assert_eq!(
            partitions
                .iter()
                .flat_map(Partition::include_roots)
                .map(|root| root.replace('\\', "/").to_ascii_lowercase())
                .collect::<BTreeSet<_>>()
                .len(),
            1565
        );

        let counts = option_counts(&partitions);
        assert_eq!(counts["--namespace"], 321);
        assert_eq!(counts["--traverse"], 321);
        assert_eq!(counts["--exclude"], 106);
        assert_eq!(counts["--remap"], 13);
        assert_eq!(counts["--with-attribute"], 23);
        assert_eq!(counts["--with-librarypath"], 6);
        assert_eq!(counts["--with-type"], 52);

        let conflicts = root_namespace_conflicts(&partitions).unwrap();
        assert_eq!(
            conflicts.keys().map(String::as_str).collect::<Vec<_>>(),
            [
                "shared/ntddstor.h",
                "shared/uuids.h",
                "um/audioendpoints.h",
                "um/dxcore.h",
                "um/dxcore_interface.h",
                "um/endpointvolume.h",
                "um/idispids.h",
            ]
        );
        assert_eq!(input_namespaces(&partitions).unwrap().len(), 321);
    }
}
