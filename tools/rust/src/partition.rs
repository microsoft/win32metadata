use sha2::{Digest, Sha256};
use std::collections::{BTreeMap, BTreeSet};
use std::path::{Path, PathBuf};

struct ApprovedRootConflict {
    path: &'static str,
    owners: &'static [ApprovedRootOwner],
}

struct ApprovedRootOwner {
    partition: &'static str,
    namespace: &'static str,
    policy_sha256: &'static str,
    compile_environment_sha256: &'static str,
    compile_variant: Option<&'static str>,
}

const APPROVED_MULTI_PARTITION_ROOTS: [ApprovedRootConflict; 8] = [
    ApprovedRootConflict {
        path: "shared/ntddstor.h",
        owners: &[
            ApprovedRootOwner {
                partition: "Fs",
                namespace: "Windows.Win32.Storage.FileSystem",
                policy_sha256: "96BD798C3FF920EA63F5D91B808EF73FD396F77E803FFB0B7C15565E4A4BC5C2",
                compile_environment_sha256: "B412202E85E2D7D29DBF2284B54A9BD2C7BC87AC1FFF7452C3EAA9170997349B",
                compile_variant: None,
            },
            ApprovedRootOwner {
                partition: "Ioctl",
                namespace: "Windows.Win32.System.Ioctl",
                policy_sha256: "4965447C9B1330BD33560DCD4E1006E6C3DEF5247CDE286E7502167CF2CE6B65",
                compile_environment_sha256: "39ED17C05B01796D2F30B589912214F212F2FBB401D0D4A460396D648FC9A799",
                compile_variant: None,
            },
        ],
    },
    ApprovedRootConflict {
        path: "shared/uuids.h",
        owners: &[
            ApprovedRootOwner {
                partition: "Media",
                namespace: "Windows.Win32.Media",
                policy_sha256: "2C765F19CEACC913D53DA028BF52A6176C333039EDD8C9F7D401ACD70460A314",
                compile_environment_sha256: "8F76592C5D98BED573DD87DA26157B524D258B8477340C15E1CE8EFD31411C77",
                compile_variant: None,
            },
            ApprovedRootOwner {
                partition: "Mf",
                namespace: "Windows.Win32.Media.MediaFoundation",
                policy_sha256: "7F91F6AF054A4F4BB60510C9FF57E14CF871E3800985C7B38D0D283414A14574",
                compile_environment_sha256: "93E81862C5BE2A2ACE94949CD57BE6D0EFD5E185F8F9D49DCB650D91CC8D690A",
                compile_variant: None,
            },
        ],
    },
    ApprovedRootConflict {
        path: "um/audioendpoints.h",
        owners: &[
            ApprovedRootOwner {
                partition: "Audio",
                namespace: "Windows.Win32.Media.Audio",
                policy_sha256: "5BEDDA0121A46E1F0C36C746A86DC0D7F6432233958170DC3F2314A33FDE0650",
                compile_environment_sha256: "A49DB8DFF1118F23836531A07BE33CDECBF75B99BDD6B6C591001E83AB125428",
                compile_variant: None,
            },
            ApprovedRootOwner {
                partition: "Audio.Endpoints",
                namespace: "Windows.Win32.Media.Audio.Endpoints",
                policy_sha256: "72DBA8685DCAC68BD917608E2162467423053CB94743E48E124A09AFA61E0D2A",
                compile_environment_sha256: "B29ED46475C7A51BAD52270F15B0A3CB80C45523BBE5A02B87C7C06BB1BDB06F",
                compile_variant: None,
            },
        ],
    },
    ApprovedRootConflict {
        path: "um/dxcore.h",
        owners: &[
            ApprovedRootOwner {
                partition: "DXCore",
                namespace: "Windows.Win32.Graphics.DXCore",
                policy_sha256: "D9B5FE6AEE501FDDE09C539C1AB8BACD62E4ADB76E5E316850735EABAF2CB8B0",
                compile_environment_sha256: "33EBEF8E597894B8D20C8F7A5B37215AD1C22D2B28BD2FBE4CCAEFFC513C0DA3",
                compile_variant: None,
            },
            ApprovedRootOwner {
                partition: "Display",
                namespace: "Windows.Win32.Devices.Display",
                policy_sha256: "10B4E11B8F730850C8244DD072B83D9CC5AEA168D62E3CF6DBE9B898912FFCFC",
                compile_environment_sha256: "8C4678D75B12047FBEC9F9E14A62702CEAC11A56117A784C92ADD44E0E4771EF",
                compile_variant: None,
            },
        ],
    },
    ApprovedRootConflict {
        path: "um/dxcore_interface.h",
        owners: &[
            ApprovedRootOwner {
                partition: "DXCore",
                namespace: "Windows.Win32.Graphics.DXCore",
                policy_sha256: "D9B5FE6AEE501FDDE09C539C1AB8BACD62E4ADB76E5E316850735EABAF2CB8B0",
                compile_environment_sha256: "33EBEF8E597894B8D20C8F7A5B37215AD1C22D2B28BD2FBE4CCAEFFC513C0DA3",
                compile_variant: None,
            },
            ApprovedRootOwner {
                partition: "Display",
                namespace: "Windows.Win32.Devices.Display",
                policy_sha256: "10B4E11B8F730850C8244DD072B83D9CC5AEA168D62E3CF6DBE9B898912FFCFC",
                compile_environment_sha256: "8C4678D75B12047FBEC9F9E14A62702CEAC11A56117A784C92ADD44E0E4771EF",
                compile_variant: None,
            },
        ],
    },
    ApprovedRootConflict {
        path: "um/endpointvolume.h",
        owners: &[
            ApprovedRootOwner {
                partition: "Audio",
                namespace: "Windows.Win32.Media.Audio",
                policy_sha256: "5BEDDA0121A46E1F0C36C746A86DC0D7F6432233958170DC3F2314A33FDE0650",
                compile_environment_sha256: "A49DB8DFF1118F23836531A07BE33CDECBF75B99BDD6B6C591001E83AB125428",
                compile_variant: None,
            },
            ApprovedRootOwner {
                partition: "Audio.Endpoints",
                namespace: "Windows.Win32.Media.Audio.Endpoints",
                policy_sha256: "72DBA8685DCAC68BD917608E2162467423053CB94743E48E124A09AFA61E0D2A",
                compile_environment_sha256: "B29ED46475C7A51BAD52270F15B0A3CB80C45523BBE5A02B87C7C06BB1BDB06F",
                compile_variant: None,
            },
        ],
    },
    ApprovedRootConflict {
        path: "um/idispids.h",
        owners: &[
            ApprovedRootOwner {
                partition: "ComOle",
                namespace: "Windows.Win32.System.Ole",
                policy_sha256: "4D7E5BEC36147C749680010F5D66185EF907B42CB44443A38ABBC6E1F6A3BB63",
                compile_environment_sha256: "8B2AB405FD8C915084D6CCA63462A742E872FB957452238A57EFFF2227CB2965",
                compile_variant: None,
            },
            ApprovedRootOwner {
                partition: "InternetExplorer",
                namespace: "Windows.Win32.Web.InternetExplorer",
                policy_sha256: "376283B3E68EC9672FD5A153B22A459B8E01A210580372206EA5CAAF406DB4C6",
                compile_environment_sha256: "913FFB704A8188E556B8000DA6899F20D8C1BF94272BBBC573E13F0AF687260B",
                compile_variant: None,
            },
        ],
    },
    ApprovedRootConflict {
        path: "um/psapi.h",
        owners: &[
            ApprovedRootOwner {
                partition: "PsApi1",
                namespace: "Windows.Win32.System.ProcessStatus",
                policy_sha256: "BF3F6B6F6F12C06D1C950C7AAF71F0EB9B17C45421F197483549E82820661E6B",
                compile_environment_sha256: "0CF65D917FA3BCE0C60CA6D771FC65FDE698F45171A1EB30416BBD527AEDB69D",
                compile_variant: Some("PSAPI_VERSION=1"),
            },
            ApprovedRootOwner {
                partition: "PsApi2",
                namespace: "Windows.Win32.System.ProcessStatus",
                policy_sha256: "7C266AD373480557E79B83510BC08F92D3A98BDDF170D6FD0CA11EA5A4C2B14E",
                compile_environment_sha256: "55B418833573FBED308811D234FAB775292BF5A0DB653AF4930A3777EB321AD0",
                compile_variant: Some("PSAPI_VERSION=2"),
            },
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

#[derive(Clone, Debug, Eq, Ord, PartialEq, PartialOrd)]
pub struct WindowsPathIdentity(String);

impl WindowsPathIdentity {
    #[allow(dead_code)]
    pub fn as_str(&self) -> &str {
        &self.0
    }
}

impl std::fmt::Display for WindowsPathIdentity {
    fn fmt(&self, formatter: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        self.0.fmt(formatter)
    }
}

#[derive(Clone, Debug, Eq, PartialEq)]
pub struct SdkScopeResolution {
    pub requested: Option<String>,
    pub actual: Option<String>,
}

impl SdkScopeResolution {
    fn fallback(&self) -> Option<(&str, &str)> {
        match (&self.requested, &self.actual) {
            (Some(requested), Some(actual)) if !requested.eq_ignore_ascii_case(actual) => {
                Some((requested, actual))
            }
            _ => None,
        }
    }
}

#[derive(Clone, Debug, Eq, PartialEq)]
pub struct ResolvedTraversalRoot {
    pub requested: String,
    pub path: PathBuf,
    pub canonical_path: WindowsPathIdentity,
    pub inventory_path: String,
    pub sdk_scope: Option<SdkScopeResolution>,
}

#[derive(Clone, Debug, Eq, PartialEq)]
pub struct PhysicalFile {
    pub path: PathBuf,
    pub canonical_path: WindowsPathIdentity,
    pub inventory_path: String,
}

#[derive(Clone, Debug, Eq, PartialEq)]
pub struct ResolvedDirectoryRoot {
    pub root: ResolvedTraversalRoot,
    pub files: Vec<PhysicalFile>,
}

#[derive(Clone, Debug, Eq, PartialEq)]
pub struct MissingTraversalRoot {
    pub requested: String,
    pub path: Option<PathBuf>,
    pub requested_sdk_scope: Option<String>,
}

#[derive(Clone, Debug, Eq, PartialEq)]
pub struct UnsupportedTraversalRoot {
    pub requested: String,
}

#[derive(Clone, Debug, Eq, PartialEq)]
pub enum TraversalRoot {
    File(ResolvedTraversalRoot),
    Directory(ResolvedDirectoryRoot),
    Missing(MissingTraversalRoot),
    Unsupported(UnsupportedTraversalRoot),
}

impl TraversalRoot {
    pub fn requested(&self) -> &str {
        match self {
            Self::File(root) => &root.requested,
            Self::Directory(root) => &root.root.requested,
            Self::Missing(root) => &root.requested,
            Self::Unsupported(root) => &root.requested,
        }
    }
}

#[derive(Clone, Debug, Eq, PartialEq)]
pub struct LogicalPartition {
    pub identity: String,
    pub directory: PathBuf,
    pub input: PathBuf,
    pub source: String,
    pub policy: PartitionPolicy,
    pub compile_environment: CompileEnvironmentIdentity,
    pub roots: Vec<TraversalRoot>,
}

#[derive(Clone, Copy, Debug, Eq, Ord, PartialEq, PartialOrd)]
pub enum DuplicateRootKind {
    Exact,
    CaseOrSeparatorOnly,
}

#[derive(Clone, Debug, Eq, PartialEq)]
pub struct DuplicateTraversalRoot {
    pub partition: String,
    pub kind: DuplicateRootKind,
    pub spellings: Vec<String>,
}

#[derive(Clone, Debug, Eq, PartialEq)]
pub struct MissingRootAudit {
    pub partition: String,
    pub root: MissingTraversalRoot,
}

#[derive(Clone, Debug, Eq, PartialEq)]
pub struct UnsupportedRootAudit {
    pub partition: String,
    pub root: UnsupportedTraversalRoot,
}

#[derive(Clone, Debug, Eq, PartialEq)]
pub struct SdkScopeFallback {
    pub partition: String,
    pub namespace: String,
    pub requested: String,
    pub path: PathBuf,
    pub requested_scope: String,
    pub actual_scope: String,
    pub explicitly_paired: bool,
}

#[derive(Clone, Debug, Eq, PartialEq)]
pub struct PhysicalRootOwner {
    pub partition: String,
    pub namespace: String,
    pub requested_roots: Vec<String>,
    pub policy: PartitionPolicy,
    pub policy_sha256: String,
    pub compile_environment: CompileEnvironmentIdentity,
    pub compile_environment_sha256: String,
    pub compile_variant: Option<String>,
}

#[derive(Clone, Copy, Debug, Eq, Ord, PartialEq, PartialOrd)]
pub enum PhysicalRootOverlapKind {
    ApprovedCrossNamespace,
    ApprovedCompileVariants,
    Unapproved,
}

#[derive(Clone, Debug, Eq, PartialEq)]
pub struct PhysicalRootOverlap {
    pub path: PathBuf,
    pub canonical_path: WindowsPathIdentity,
    pub inventory_path: String,
    pub owners: Vec<PhysicalRootOwner>,
    pub kind: PhysicalRootOverlapKind,
}

#[derive(Clone, Debug, Default, Eq, PartialEq)]
pub struct TraversalPolicyAudit {
    pub missing_roots: Vec<MissingRootAudit>,
    pub unsupported_roots: Vec<UnsupportedRootAudit>,
    pub duplicate_roots: Vec<DuplicateTraversalRoot>,
    pub sdk_scope_fallbacks: Vec<SdkScopeFallback>,
    pub physical_overlaps: Vec<PhysicalRootOverlap>,
}

#[derive(Clone, Debug, Eq, PartialEq)]
pub struct CompileEnvironmentException {
    pub partition: String,
    pub standard: Option<String>,
    pub include_directories: Vec<String>,
    pub partition_local_roots: Vec<String>,
    pub defines: Vec<SourceDefine>,
    pub source_sha256: String,
    pub has_nonordinary_main_source: bool,
}

#[derive(Clone, Debug, Eq, Ord, PartialEq, PartialOrd)]
pub struct SourceDefine {
    // Ordered textual definition; source_sha256 retains surrounding #undef and conditional context.
    pub name: String,
    pub value: String,
}

#[derive(Clone, Debug, Eq, PartialEq)]
pub struct CompileEnvironmentIdentity {
    pub standard: Option<String>,
    pub include_directories: Vec<String>,
    pub partition_local_roots: Vec<String>,
    pub defines: Vec<SourceDefine>,
    pub source_sha256: String,
}

#[derive(Clone, Debug, Eq, PartialEq)]
pub struct TraversalPolicy {
    pub partitions: Vec<LogicalPartition>,
    pub audit: TraversalPolicyAudit,
    pub compile_environment_exceptions: Vec<CompileEnvironmentException>,
}

#[derive(Clone, Debug)]
struct ResolvedRootClaim {
    partition: String,
    namespace: String,
    requested: String,
    path: PathBuf,
    canonical_path: WindowsPathIdentity,
    inventory_path: String,
    policy: PartitionPolicy,
    compile_environment: CompileEnvironmentIdentity,
    scope_fallback: bool,
}

#[derive(Debug)]
struct IncludeRootResolution {
    path: PathBuf,
    inventory_path: String,
    sdk_scope: SdkScopeResolution,
}

#[derive(Debug)]
struct PendingScopeFallback {
    partition: String,
    namespace: String,
    requested: String,
    path: PathBuf,
    requested_scope: String,
    actual_scope: String,
    physical_paths: Vec<WindowsPathIdentity>,
}

#[derive(Clone, Debug)]
struct RootOwnerClaims {
    namespace: String,
    requested_roots: BTreeSet<String>,
    policy: PartitionPolicy,
    compile_environment: CompileEnvironmentIdentity,
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

impl CompileEnvironmentIdentity {
    pub fn sha256(&self) -> String {
        compile_environment_sha256(self)
    }
}

impl PartitionPolicy {
    pub fn sha256(&self) -> String {
        partition_policy_sha256(self)
    }
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
        for requested in self.traverse() {
            match resolve_traversal_root(self, requested, include_dirs)? {
                TraversalRoot::File(root) => result.files.push(root.path),
                TraversalRoot::Directory(root) => result.directories.push(root.root.path),
                TraversalRoot::Missing(root) => {
                    return match root.path {
                        Some(path) => Err(format!(
                            "partition `{}` root `{requested}` resolved to missing path `{}`",
                            self.name,
                            path.display()
                        )),
                        None => Err(format!(
                            "partition `{}` root `{requested}` was not found in the configured include directories",
                            self.name
                        )),
                    };
                }
                TraversalRoot::Unsupported(_) => {
                    return Err(format!(
                        "partition `{}` has unsupported --traverse value `{requested}`",
                        self.name
                    ));
                }
            }
        }
        Ok(result)
    }
}

#[allow(dead_code)]
impl TraversalPolicy {
    pub fn canonical_physical_files(&self) -> BTreeMap<WindowsPathIdentity, PathBuf> {
        let mut result = BTreeMap::new();
        for root in self
            .partitions
            .iter()
            .flat_map(|partition| partition.roots.iter())
        {
            match root {
                TraversalRoot::File(root) => {
                    result
                        .entry(root.canonical_path.clone())
                        .or_insert_with(|| root.path.clone());
                }
                TraversalRoot::Directory(root) => {
                    for file in &root.files {
                        result
                            .entry(file.canonical_path.clone())
                            .or_insert_with(|| file.path.clone());
                    }
                }
                TraversalRoot::Missing(_) | TraversalRoot::Unsupported(_) => {}
            }
        }
        result
    }

    pub fn file_root_count(&self) -> usize {
        self.partitions
            .iter()
            .flat_map(|partition| partition.roots.iter())
            .filter(|root| matches!(root, TraversalRoot::File(_)))
            .count()
    }

    pub fn directory_root_count(&self) -> usize {
        self.partitions
            .iter()
            .flat_map(|partition| partition.roots.iter())
            .filter(|root| matches!(root, TraversalRoot::Directory(_)))
            .count()
    }

    pub fn canonical_inventory_sha256(&self) -> String {
        struct Entry<'a> {
            physical_path: &'a str,
            requested_root: &'a str,
            partition: &'a str,
            namespace: &'a str,
            policy: &'a PartitionPolicy,
            compile_environment: &'a CompileEnvironmentIdentity,
        }

        let mut entries = Vec::new();
        for partition in &self.partitions {
            for root in &partition.roots {
                let requested_root = root.requested();
                match root {
                    TraversalRoot::File(root) => entries.push(Entry {
                        physical_path: &root.inventory_path,
                        requested_root,
                        partition: &partition.identity,
                        namespace: &partition.policy.namespace,
                        policy: &partition.policy,
                        compile_environment: &partition.compile_environment,
                    }),
                    TraversalRoot::Directory(root) => {
                        entries.extend(root.files.iter().map(|file| Entry {
                            physical_path: &file.inventory_path,
                            requested_root,
                            partition: &partition.identity,
                            namespace: &partition.policy.namespace,
                            policy: &partition.policy,
                            compile_environment: &partition.compile_environment,
                        }));
                    }
                    TraversalRoot::Missing(_) | TraversalRoot::Unsupported(_) => {}
                }
            }
        }
        entries.sort_by(|left, right| {
            compare_case_insensitive(left.physical_path, right.physical_path)
                .then_with(|| compare_case_insensitive(left.requested_root, right.requested_root))
                .then_with(|| compare_case_insensitive(left.partition, right.partition))
                .then_with(|| compare_case_insensitive(left.namespace, right.namespace))
        });

        let mut hasher = StableHasher::new("win32metadata traversal inventory v1");
        hasher.usize(entries.len());
        for entry in entries {
            hasher.string(entry.physical_path);
            hasher.string(entry.requested_root);
            hasher.string(entry.partition);
            hasher.string(entry.namespace);
            hash_partition_policy(&mut hasher, entry.policy);
            hash_compile_environment(&mut hasher, entry.compile_environment);
        }
        hasher.finish()
    }
}

#[allow(dead_code)]
impl TraversalPolicyAudit {
    pub fn is_clean(&self) -> bool {
        self.missing_roots.is_empty()
            && self.unsupported_roots.is_empty()
            && self.duplicate_roots.is_empty()
            && self
                .sdk_scope_fallbacks
                .iter()
                .all(|fallback| fallback.explicitly_paired)
            && self
                .physical_overlaps
                .iter()
                .all(|overlap| overlap.kind != PhysicalRootOverlapKind::Unapproved)
    }

    pub fn ensure_clean(&self) -> Result<(), String> {
        let mut errors = Vec::new();
        for missing in &self.missing_roots {
            errors.push(match &missing.root.path {
                Some(path) => format!(
                    "partition `{}` root `{}` resolved to missing path `{}`",
                    missing.partition,
                    missing.root.requested,
                    path.display()
                ),
                None => format!(
                    "partition `{}` root `{}` was not found in the configured include directories",
                    missing.partition, missing.root.requested
                ),
            });
        }
        for unsupported in &self.unsupported_roots {
            errors.push(format!(
                "partition `{}` has unsupported --traverse value `{}`",
                unsupported.partition, unsupported.root.requested
            ));
        }
        for duplicate in &self.duplicate_roots {
            let description = match duplicate.kind {
                DuplicateRootKind::Exact => "duplicate root",
                DuplicateRootKind::CaseOrSeparatorOnly => "case- or separator-only duplicate roots",
            };
            errors.push(format!(
                "partition `{}` has {description}: {}",
                duplicate.partition,
                duplicate
                    .spellings
                    .iter()
                    .map(|root| format!("`{root}`"))
                    .collect::<Vec<_>>()
                    .join(", ")
            ));
        }
        for fallback in self
            .sdk_scope_fallbacks
            .iter()
            .filter(|fallback| !fallback.explicitly_paired)
        {
            errors.push(format!(
                "partition `{}` root `{}` requested SDK scope `{}` but resolved under `{}` to `{}` without explicitly rooting that physical header",
                fallback.partition,
                fallback.requested,
                fallback.requested_scope,
                fallback.actual_scope,
                fallback.path.display()
            ));
        }
        for overlap in self
            .physical_overlaps
            .iter()
            .filter(|overlap| overlap.kind == PhysicalRootOverlapKind::Unapproved)
        {
            let owners = overlap
                .owners
                .iter()
                .map(|owner| {
                    let variant = owner
                        .compile_variant
                        .as_deref()
                        .map(|variant| format!(", variant {variant}"))
                        .unwrap_or_default();
                    format!(
                        "{} ({}, policy {}, compile {}{}) via {}",
                        owner.partition,
                        owner.namespace,
                        owner.policy_sha256,
                        owner.compile_environment_sha256,
                        variant,
                        owner
                            .requested_roots
                            .iter()
                            .map(|root| format!("`{root}`"))
                            .collect::<Vec<_>>()
                            .join(", ")
                    )
                })
                .collect::<Vec<_>>()
                .join("; ");
            errors.push(format!(
                "physical root `{}` (`{}`) has owners or compile variants outside the approved exact contract: {owners}",
                overlap.path.display(),
                overlap.inventory_path
            ));
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
}

#[allow(dead_code)]
pub fn load_traversal_policy(
    partition_root: &Path,
    include_dirs: &[PathBuf],
) -> Result<TraversalPolicy, String> {
    compile_traversal_policy(&load_active(partition_root)?, include_dirs)
}

pub fn compile_traversal_policy(
    partitions: &[Partition],
    include_dirs: &[PathBuf],
) -> Result<TraversalPolicy, String> {
    let mut logical_partitions = Vec::new();
    let mut audit = TraversalPolicyAudit::default();
    let mut claims = Vec::<ResolvedRootClaim>::new();
    let mut pending_fallbacks = Vec::<PendingScopeFallback>::new();
    let mut compile_environment_exceptions = Vec::new();

    for partition in partitions {
        let policy = partition.policy()?;
        let partition_local_roots = partition
            .traverse()
            .filter(|requested| partition_relative(requested).is_some())
            .map(str::to_string)
            .collect::<Vec<_>>();
        let compile_environment =
            compile_environment_identity(partition, &policy, partition_local_roots.clone());
        let mut requested_roots = BTreeMap::<String, Vec<String>>::new();
        let mut roots = Vec::new();
        for requested in partition.traverse() {
            requested_roots
                .entry(normalize_path_identity(requested))
                .or_default()
                .push(requested.to_string());

            let root = resolve_traversal_root(partition, requested, include_dirs)?;
            match &root {
                TraversalRoot::File(root) => {
                    record_root_claim(
                        &mut claims,
                        partition,
                        &policy.namespace,
                        &policy,
                        &compile_environment,
                        root,
                        &root.path,
                        &root.canonical_path,
                        &root.inventory_path,
                    );
                    record_scope_fallback(
                        &mut pending_fallbacks,
                        partition,
                        &policy.namespace,
                        root,
                        vec![root.canonical_path.clone()],
                    );
                }
                TraversalRoot::Directory(directory) => {
                    for file in &directory.files {
                        record_root_claim(
                            &mut claims,
                            partition,
                            &policy.namespace,
                            &policy,
                            &compile_environment,
                            &directory.root,
                            &file.path,
                            &file.canonical_path,
                            &file.inventory_path,
                        );
                    }
                    record_scope_fallback(
                        &mut pending_fallbacks,
                        partition,
                        &policy.namespace,
                        &directory.root,
                        directory
                            .files
                            .iter()
                            .map(|file| file.canonical_path.clone())
                            .collect(),
                    );
                }
                TraversalRoot::Missing(root) => {
                    audit.missing_roots.push(MissingRootAudit {
                        partition: partition.name.clone(),
                        root: root.clone(),
                    });
                }
                TraversalRoot::Unsupported(root) => {
                    audit.unsupported_roots.push(UnsupportedRootAudit {
                        partition: partition.name.clone(),
                        root: root.clone(),
                    });
                }
            }
            roots.push(root);
        }

        for spellings in requested_roots
            .into_values()
            .filter(|roots| roots.len() > 1)
        {
            let unique = spellings.iter().collect::<BTreeSet<_>>();
            let kind = if unique.len() == 1 {
                DuplicateRootKind::Exact
            } else {
                DuplicateRootKind::CaseOrSeparatorOnly
            };
            let mut spellings = unique.into_iter().cloned().collect::<Vec<_>>();
            sort_strings_case_insensitive(&mut spellings);
            audit.duplicate_roots.push(DuplicateTraversalRoot {
                partition: partition.name.clone(),
                kind,
                spellings,
            });
        }

        let has_nonordinary_main_source =
            has_nonordinary_main_source(&partition.source, &compile_environment.defines);
        if policy.standard.is_some()
            || !policy.include_directories.is_empty()
            || !partition_local_roots.is_empty()
            || has_nonordinary_main_source
        {
            compile_environment_exceptions.push(CompileEnvironmentException {
                partition: partition.name.clone(),
                standard: policy.standard.clone(),
                include_directories: policy.include_directories.clone(),
                partition_local_roots,
                defines: compile_environment.defines.clone(),
                source_sha256: compile_environment.source_sha256.clone(),
                has_nonordinary_main_source,
            });
        }

        logical_partitions.push(LogicalPartition {
            identity: partition.name.clone(),
            directory: partition.directory.clone(),
            input: partition.directory.join("main.cpp"),
            source: partition.source.clone(),
            policy,
            compile_environment,
            roots,
        });
    }

    logical_partitions
        .sort_by(|left, right| compare_case_insensitive(&left.identity, &right.identity));
    compile_environment_exceptions
        .sort_by(|left, right| compare_case_insensitive(&left.partition, &right.partition));
    audit.missing_roots.sort_by(|left, right| {
        compare_case_insensitive(&left.partition, &right.partition)
            .then_with(|| compare_case_insensitive(&left.root.requested, &right.root.requested))
    });
    audit.unsupported_roots.sort_by(|left, right| {
        compare_case_insensitive(&left.partition, &right.partition)
            .then_with(|| compare_case_insensitive(&left.root.requested, &right.root.requested))
    });
    audit.duplicate_roots.sort_by(|left, right| {
        compare_case_insensitive(&left.partition, &right.partition)
            .then_with(|| left.kind.cmp(&right.kind))
            .then_with(|| left.spellings.cmp(&right.spellings))
    });

    let mut claims_by_path = BTreeMap::<WindowsPathIdentity, Vec<ResolvedRootClaim>>::new();
    for claim in claims {
        claims_by_path
            .entry(claim.canonical_path.clone())
            .or_default()
            .push(claim);
    }

    for pending in pending_fallbacks {
        let explicitly_paired = !pending.physical_paths.is_empty()
            && pending.physical_paths.iter().all(|path| {
                claims_by_path.get(path).is_some_and(|claims| {
                    claims
                        .iter()
                        .any(|claim| claim.partition == pending.partition && !claim.scope_fallback)
                })
            });
        audit.sdk_scope_fallbacks.push(SdkScopeFallback {
            partition: pending.partition,
            namespace: pending.namespace,
            requested: pending.requested,
            path: pending.path,
            requested_scope: pending.requested_scope,
            actual_scope: pending.actual_scope,
            explicitly_paired,
        });
    }
    audit.sdk_scope_fallbacks.sort_by(|left, right| {
        compare_case_insensitive(&left.partition, &right.partition)
            .then_with(|| compare_case_insensitive(&left.requested, &right.requested))
    });

    for (canonical_path, mut path_claims) in claims_by_path {
        path_claims.sort_by(|left, right| {
            compare_case_insensitive(&left.partition, &right.partition)
                .then_with(|| compare_case_insensitive(&left.namespace, &right.namespace))
                .then_with(|| compare_case_insensitive(&left.requested, &right.requested))
        });
        let mut owner_requests = BTreeMap::<String, RootOwnerClaims>::new();
        for claim in &path_claims {
            owner_requests
                .entry(claim.partition.clone())
                .and_modify(|owner| {
                    owner.requested_roots.insert(claim.requested.clone());
                })
                .or_insert_with(|| RootOwnerClaims {
                    namespace: claim.namespace.clone(),
                    requested_roots: BTreeSet::from([claim.requested.clone()]),
                    policy: claim.policy.clone(),
                    compile_environment: claim.compile_environment.clone(),
                });
        }
        if owner_requests.len() < 2 {
            continue;
        }

        let owners = owner_requests
            .into_iter()
            .map(|(partition, owner)| PhysicalRootOwner {
                partition,
                namespace: owner.namespace,
                requested_roots: owner.requested_roots.into_iter().collect(),
                policy_sha256: owner.policy.sha256(),
                compile_environment_sha256: owner.compile_environment.sha256(),
                compile_variant: compile_variant(&owner.compile_environment),
                policy: owner.policy,
                compile_environment: owner.compile_environment,
            })
            .collect::<Vec<_>>();
        let approved = APPROVED_MULTI_PARTITION_ROOTS.iter().find_map(|approved| {
            path_claims
                .iter()
                .find(|claim| path_matches_contract(&claim.inventory_path, approved.path))
                .map(|claim| (approved, claim.inventory_path.clone()))
        });
        let (kind, inventory_path) = if let Some((approved, inventory_path)) = approved {
            if owners_match_contract(&owners, approved.owners) {
                if approved
                    .owners
                    .iter()
                    .any(|owner| owner.compile_variant.is_some())
                {
                    (
                        PhysicalRootOverlapKind::ApprovedCompileVariants,
                        inventory_path,
                    )
                } else {
                    (
                        PhysicalRootOverlapKind::ApprovedCrossNamespace,
                        inventory_path,
                    )
                }
            } else {
                (PhysicalRootOverlapKind::Unapproved, inventory_path)
            }
        } else {
            (
                PhysicalRootOverlapKind::Unapproved,
                path_claims[0].inventory_path.clone(),
            )
        };
        audit.physical_overlaps.push(PhysicalRootOverlap {
            path: path_claims[0].path.clone(),
            canonical_path,
            inventory_path,
            owners,
            kind,
        });
    }
    audit
        .physical_overlaps
        .sort_by(|left, right| left.canonical_path.cmp(&right.canonical_path));

    Ok(TraversalPolicy {
        partitions: logical_partitions,
        audit,
        compile_environment_exceptions,
    })
}

pub fn validate_resolved_root_ownership(
    partitions: &[Partition],
    include_dirs: &[PathBuf],
) -> Result<(), String> {
    compile_traversal_policy(partitions, include_dirs)?
        .audit
        .ensure_clean()
}

#[allow(dead_code)]
pub fn load_active(root: &Path) -> Result<Vec<Partition>, String> {
    let mut directories = std::fs::read_dir(root)
        .map_err(|error| format!("failed to read `{}`: {error}", root.display()))?
        .map(|entry| {
            entry
                .map(|entry| entry.path())
                .map_err(|error| format!("failed to read `{}`: {error}", root.display()))
        })
        .collect::<Result<Vec<_>, _>>()?;
    sort_paths_case_insensitive(&mut directories);

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

fn resolve_traversal_root(
    partition: &Partition,
    requested: &str,
    include_dirs: &[PathBuf],
) -> Result<TraversalRoot, String> {
    let (path, inventory_path, sdk_scope) = if let Some(relative) = partition_relative(requested) {
        (
            partition.directory.join(relative),
            join_inventory_path(
                &format!(
                    "partition/{}",
                    partition.name.replace('\\', "/").to_ascii_lowercase()
                ),
                relative,
            ),
            None,
        )
    } else if let Some(relative) = include_relative(requested) {
        let Some(resolution) = resolve_include_root(relative, include_dirs) else {
            return Ok(TraversalRoot::Missing(MissingTraversalRoot {
                requested: requested.to_string(),
                path: None,
                requested_sdk_scope: requested_sdk_scope(relative).map(str::to_string),
            }));
        };
        (
            resolution.path,
            resolution.inventory_path,
            Some(resolution.sdk_scope),
        )
    } else {
        return Ok(TraversalRoot::Unsupported(UnsupportedTraversalRoot {
            requested: requested.to_string(),
        }));
    };

    if path.is_file() {
        Ok(TraversalRoot::File(ResolvedTraversalRoot {
            requested: requested.to_string(),
            canonical_path: windows_path_identity(&path)?,
            path,
            inventory_path,
            sdk_scope,
        }))
    } else if path.is_dir() {
        let canonical_path = windows_path_identity(&path)?;
        let mut paths = Vec::new();
        collect_root_files(&path, &mut paths)?;
        let directory_path = path.clone();
        let mut files = paths
            .into_iter()
            .map(|file_path| {
                let relative = file_path
                    .strip_prefix(&directory_path)
                    .unwrap_or(Path::new(""));
                Ok(PhysicalFile {
                    canonical_path: windows_path_identity(&file_path)?,
                    inventory_path: join_inventory_path(&inventory_path, relative),
                    path: file_path,
                })
            })
            .collect::<Result<Vec<_>, String>>()?;
        files.sort_by(|left, right| {
            left.canonical_path
                .cmp(&right.canonical_path)
                .then_with(|| left.path.cmp(&right.path))
        });
        files.dedup_by(|left, right| left.canonical_path == right.canonical_path);
        Ok(TraversalRoot::Directory(ResolvedDirectoryRoot {
            root: ResolvedTraversalRoot {
                requested: requested.to_string(),
                path,
                canonical_path,
                inventory_path,
                sdk_scope,
            },
            files,
        }))
    } else {
        let requested_sdk_scope = sdk_scope.as_ref().and_then(|scope| scope.requested.clone());
        Ok(TraversalRoot::Missing(MissingTraversalRoot {
            requested: requested.to_string(),
            path: Some(path),
            requested_sdk_scope,
        }))
    }
}

fn record_root_claim(
    claims: &mut Vec<ResolvedRootClaim>,
    partition: &Partition,
    namespace: &str,
    policy: &PartitionPolicy,
    compile_environment: &CompileEnvironmentIdentity,
    root: &ResolvedTraversalRoot,
    path: &Path,
    canonical_path: &WindowsPathIdentity,
    inventory_path: &str,
) {
    claims.push(ResolvedRootClaim {
        partition: partition.name.clone(),
        namespace: namespace.to_string(),
        requested: root.requested.clone(),
        path: path.to_path_buf(),
        canonical_path: canonical_path.clone(),
        inventory_path: inventory_path.to_string(),
        policy: policy.clone(),
        compile_environment: compile_environment.clone(),
        scope_fallback: root
            .sdk_scope
            .as_ref()
            .is_some_and(|scope| scope.fallback().is_some()),
    });
}

fn record_scope_fallback(
    fallbacks: &mut Vec<PendingScopeFallback>,
    partition: &Partition,
    namespace: &str,
    root: &ResolvedTraversalRoot,
    physical_paths: Vec<WindowsPathIdentity>,
) {
    let Some((requested_scope, actual_scope)) = root
        .sdk_scope
        .as_ref()
        .and_then(SdkScopeResolution::fallback)
    else {
        return;
    };
    fallbacks.push(PendingScopeFallback {
        partition: partition.name.clone(),
        namespace: namespace.to_string(),
        requested: root.requested.clone(),
        path: root.path.clone(),
        requested_scope: requested_scope.to_string(),
        actual_scope: actual_scope.to_string(),
        physical_paths,
    });
}

fn resolve_include_root(relative: &str, include_dirs: &[PathBuf]) -> Option<IncludeRootResolution> {
    let relative = relative.replace('\\', "/").trim_matches('/').to_string();
    if let Some(scope) = sdk_scope(&relative) {
        return include_dirs.iter().find_map(|directory| {
            let directory_scope = directory
                .file_name()
                .and_then(|name| name.to_str())
                .unwrap_or_default();
            directory_scope
                .eq_ignore_ascii_case(scope)
                .then(|| IncludeRootResolution {
                    path: directory.clone(),
                    inventory_path: scope.to_string(),
                    sdk_scope: SdkScopeResolution {
                        requested: Some(scope.to_string()),
                        actual: Some(scope.to_string()),
                    },
                })
        });
    }
    let (scope, scoped_relative) = relative.split_once('/').unwrap_or(("", &relative));
    let requested_scope = sdk_scope(scope).map(str::to_string);
    for directory in include_dirs {
        let directory_scope = directory
            .file_name()
            .and_then(|name| name.to_str())
            .unwrap_or_default();
        let (candidate, actual_scope) = if directory_scope.eq_ignore_ascii_case(scope) {
            (
                directory.join(scoped_relative),
                sdk_scope(directory_scope).map(str::to_string),
            )
        } else if is_sdk_scope(directory_scope) {
            continue;
        } else {
            let scoped = directory.join(&relative);
            if scoped.exists() {
                (scoped, requested_scope.clone())
            } else {
                (directory.join(scoped_relative), None)
            }
        };
        if candidate.exists() {
            return Some(IncludeRootResolution {
                inventory_path: include_inventory_path(directory, &candidate, include_dirs),
                path: candidate,
                sdk_scope: SdkScopeResolution {
                    requested: requested_scope,
                    actual: actual_scope,
                },
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
        Some(IncludeRootResolution {
            inventory_path: include_inventory_path(directory, &candidate, include_dirs),
            path: candidate,
            sdk_scope: SdkScopeResolution {
                requested: requested_scope.clone(),
                actual: sdk_scope(actual_scope).map(str::to_string),
            },
        })
    })
}

fn sdk_scope(value: &str) -> Option<&'static str> {
    ["shared", "um", "ucrt", "winrt"]
        .into_iter()
        .find(|scope| value.eq_ignore_ascii_case(scope))
}

fn requested_sdk_scope(value: &str) -> Option<&'static str> {
    let normalized = value.replace('\\', "/");
    let scope = normalized.split('/').next().unwrap_or_default();
    sdk_scope(scope)
}

fn is_sdk_scope(value: &str) -> bool {
    sdk_scope(value).is_some()
}

fn include_inventory_path(directory: &Path, candidate: &Path, include_dirs: &[PathBuf]) -> String {
    let base = directory
        .file_name()
        .and_then(|name| name.to_str())
        .unwrap_or("include")
        .to_ascii_lowercase();
    let matching = include_dirs
        .iter()
        .filter(|include| {
            include
                .file_name()
                .and_then(|name| name.to_str())
                .is_some_and(|name| name.eq_ignore_ascii_case(&base))
        })
        .collect::<Vec<_>>();
    let label = if matching.len() > 1 {
        let ordinal = matching
            .iter()
            .position(|include| *include == &directory)
            .unwrap_or_default()
            + 1;
        if ordinal == 1 {
            base
        } else {
            format!("{base}#{ordinal}")
        }
    } else {
        base
    };
    join_inventory_path(
        &label,
        candidate.strip_prefix(directory).unwrap_or(Path::new("")),
    )
}

fn join_inventory_path(base: &str, relative: impl AsRef<Path>) -> String {
    let relative = relative
        .as_ref()
        .to_string_lossy()
        .replace('\\', "/")
        .trim_matches('/')
        .to_ascii_lowercase();
    if relative.is_empty() {
        base.to_ascii_lowercase()
    } else {
        format!(
            "{}/{relative}",
            base.trim_end_matches('/').to_ascii_lowercase()
        )
    }
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
    sort_paths_case_insensitive(&mut entries);
    for entry in entries {
        if entry.is_dir() {
            collect_root_files(&entry, files)?;
        } else if entry.is_file() {
            files.push(entry);
        }
    }
    Ok(())
}

fn windows_path_identity(path: &Path) -> Result<WindowsPathIdentity, String> {
    std::fs::canonicalize(path)
        .map_err(|error| format!("failed to canonicalize root `{}`: {error}", path.display()))
        .map(|path| {
            WindowsPathIdentity(
                path.to_string_lossy()
                    .replace('\\', "/")
                    .to_ascii_lowercase(),
            )
        })
}

fn partition_relative(value: &str) -> Option<&str> {
    virtual_root_relative(value, "<PartitionDir>")
}

fn include_relative(value: &str) -> Option<&str> {
    virtual_root_relative(value, "<IncludeRoot>")
}

fn virtual_root_relative<'a>(value: &'a str, root: &str) -> Option<&'a str> {
    let prefix = value.get(..root.len())?;
    if !prefix.eq_ignore_ascii_case(root) {
        return None;
    }
    let suffix = value.get(root.len()..)?;
    suffix
        .strip_prefix('/')
        .or_else(|| suffix.strip_prefix('\\'))
}

fn path_matches_contract(path: &str, contract: &str) -> bool {
    path.eq_ignore_ascii_case(contract)
}

fn normalize_path_identity(path: &str) -> String {
    path.trim().replace('\\', "/").to_ascii_lowercase()
}

fn compare_case_insensitive(left: &str, right: &str) -> std::cmp::Ordering {
    left.to_ascii_lowercase()
        .cmp(&right.to_ascii_lowercase())
        .then_with(|| left.cmp(right))
}

fn sort_strings_case_insensitive(values: &mut [String]) {
    values.sort_by(|left, right| compare_case_insensitive(left, right));
}

fn sort_paths_case_insensitive(paths: &mut [PathBuf]) {
    paths.sort_by(|left, right| {
        compare_case_insensitive(
            &left.to_string_lossy().replace('\\', "/"),
            &right.to_string_lossy().replace('\\', "/"),
        )
    });
}

struct StableHasher(Sha256);

impl StableHasher {
    fn new(domain: &str) -> Self {
        let mut result = Self(Sha256::new());
        result.string(domain);
        result
    }

    fn string(&mut self, value: &str) {
        self.0.update((value.len() as u64).to_le_bytes());
        self.0.update(value.as_bytes());
    }

    fn bool(&mut self, value: bool) {
        self.0.update([u8::from(value)]);
    }

    fn usize(&mut self, value: usize) {
        self.0.update((value as u64).to_le_bytes());
    }

    fn option_string(&mut self, value: Option<&str>) {
        self.bool(value.is_some());
        if let Some(value) = value {
            self.string(value);
        }
    }

    fn finish(self) -> String {
        format!("{:X}", self.0.finalize())
    }
}

fn partition_policy_sha256(policy: &PartitionPolicy) -> String {
    let mut hasher = StableHasher::new("win32metadata partition policy v1");
    hash_partition_policy(&mut hasher, policy);
    hasher.finish()
}

fn hash_partition_policy(hasher: &mut StableHasher, policy: &PartitionPolicy) {
    hasher.string(&policy.namespace);
    hasher.usize(policy.exclusions.len());
    for exclusion in &policy.exclusions {
        hasher.string(exclusion);
    }
    hasher.usize(policy.remaps.len());
    for (source, target) in &policy.remaps {
        hasher.string(source);
        hasher.string(target);
    }
    hasher.usize(policy.type_overrides.len());
    for (name, override_type) in &policy.type_overrides {
        hasher.string(name);
        hasher.string(match override_type {
            TypeOverride::U32 => "u32",
        });
    }
    hasher.usize(policy.attributes.len());
    for (name, attributes) in &policy.attributes {
        hasher.string(name);
        hasher.usize(attributes.len());
        for attribute in attributes {
            hasher.string(match attribute {
                ForcedAttribute::Flags => "flags",
            });
        }
    }
    hasher.usize(policy.libraries.len());
    for (function, library) in &policy.libraries {
        hasher.string(function);
        hasher.string(library);
    }
    hasher.usize(policy.preserve_auto_fnptr_level.len());
    for name in &policy.preserve_auto_fnptr_level {
        hasher.string(name);
    }
    hasher.bool(policy.exclude_empty_records);
    hasher.option_string(policy.standard.as_deref());
    hasher.usize(policy.include_directories.len());
    for directory in &policy.include_directories {
        hasher.string(directory);
    }
    hasher.option_string(policy.legacy_output.as_deref());
}

fn compile_environment_sha256(environment: &CompileEnvironmentIdentity) -> String {
    let mut hasher = StableHasher::new("win32metadata compile environment v1");
    hash_compile_environment(&mut hasher, environment);
    hasher.finish()
}

fn hash_compile_environment(hasher: &mut StableHasher, environment: &CompileEnvironmentIdentity) {
    hasher.option_string(environment.standard.as_deref());
    hasher.usize(environment.include_directories.len());
    for directory in &environment.include_directories {
        hasher.string(directory);
    }
    hasher.usize(environment.partition_local_roots.len());
    for root in &environment.partition_local_roots {
        hasher.string(root);
    }
    hasher.usize(environment.defines.len());
    for define in &environment.defines {
        hasher.string(&define.name);
        hasher.string(&define.value);
    }
    hasher.string(&environment.source_sha256);
}

fn compile_environment_identity(
    partition: &Partition,
    policy: &PartitionPolicy,
    partition_local_roots: Vec<String>,
) -> CompileEnvironmentIdentity {
    CompileEnvironmentIdentity {
        standard: policy.standard.clone(),
        include_directories: policy.include_directories.clone(),
        partition_local_roots,
        defines: source_defines(&partition.source),
        source_sha256: source_sha256(&partition.source),
    }
}

fn source_sha256(source: &str) -> String {
    let normalized = normalize_source(source);
    format!("{:X}", Sha256::digest(normalized.as_bytes()))
}

fn normalize_source(source: &str) -> String {
    source
        .trim_start_matches('\u{feff}')
        .replace("\r\n", "\n")
        .replace('\r', "\n")
}

fn source_defines(source: &str) -> Vec<SourceDefine> {
    let source = normalize_source(source);
    let lines = source.lines().collect::<Vec<_>>();
    let mut result = Vec::new();
    let mut index = 0;
    while index < lines.len() {
        let line = lines[index].trim_start();
        let Some(directive) = line.strip_prefix('#') else {
            index += 1;
            continue;
        };
        let directive = directive.trim_start();
        let Some(first) = directive.strip_prefix("define") else {
            index += 1;
            continue;
        };
        if first
            .chars()
            .next()
            .is_some_and(|character| !character.is_whitespace())
        {
            index += 1;
            continue;
        }

        let mut definition = first.trim_start().to_string();
        while definition.trim_end().ends_with('\\') && index + 1 < lines.len() {
            index += 1;
            definition.push('\n');
            definition.push_str(lines[index].trim());
        }
        let mut in_block_comment = false;
        definition = definition
            .lines()
            .map(|line| strip_comments(line, &mut in_block_comment))
            .collect::<Vec<_>>()
            .join("\n")
            .trim()
            .to_string();
        if !definition.is_empty() {
            let identifier_end = definition
                .find(|character: char| !(character.is_ascii_alphanumeric() || character == '_'))
                .unwrap_or(definition.len());
            let split = if definition[identifier_end..].starts_with('(') {
                definition[identifier_end..]
                    .find(')')
                    .map(|end| identifier_end + end + 1)
                    .unwrap_or(definition.len())
            } else {
                definition
                    .find(char::is_whitespace)
                    .unwrap_or(definition.len())
            };
            result.push(SourceDefine {
                name: definition[..split].to_string(),
                value: definition[split..].trim().to_string(),
            });
        }
        index += 1;
    }
    result
}

fn is_boilerplate_define(define: &SourceDefine) -> bool {
    // These shared legacy prelude defines remain in compile identity but do not alone make an
    // otherwise ordinary include-only main.cpp an exception.
    ["SECURITY_WIN32", "QCC_OS_GROUP_WINDOWS"]
        .iter()
        .any(|name| define.name.eq_ignore_ascii_case(name))
}

fn compile_variant(environment: &CompileEnvironmentIdentity) -> Option<String> {
    environment
        .defines
        .iter()
        .find(|define| define.name.eq_ignore_ascii_case("PSAPI_VERSION"))
        .map(|define| format!("PSAPI_VERSION={}", define.value))
}

fn owners_match_contract(observed: &[PhysicalRootOwner], expected: &[ApprovedRootOwner]) -> bool {
    observed.len() == expected.len()
        && expected.iter().all(|expected| {
            observed.iter().any(|observed| {
                observed.partition == expected.partition
                    && observed.namespace == expected.namespace
                    && observed.policy_sha256 == expected.policy_sha256
                    && observed.compile_environment_sha256 == expected.compile_environment_sha256
                    && observed.compile_variant.as_deref() == expected.compile_variant
            })
        })
}

fn has_nonordinary_main_source(source: &str, defines: &[SourceDefine]) -> bool {
    if defines.iter().any(|define| !is_boilerplate_define(define)) {
        return true;
    }
    let mut in_block_comment = false;
    let mut continued_directive = false;
    for raw in source.lines() {
        let line = strip_comments(raw, &mut in_block_comment);
        let line = line.trim();
        if line.is_empty() {
            continue;
        }
        if continued_directive {
            continued_directive = line.ends_with('\\');
            continue;
        }
        if is_preprocessor_directive(line, "include") || is_preprocessor_directive(line, "define") {
            continued_directive = line.ends_with('\\');
            continue;
        }
        return true;
    }
    false
}

fn strip_comments(line: &str, in_block_comment: &mut bool) -> String {
    let mut remaining = line;
    let mut result = String::new();
    loop {
        if *in_block_comment {
            let Some(end) = remaining.find("*/") else {
                return result;
            };
            remaining = &remaining[end + 2..];
            *in_block_comment = false;
            continue;
        }
        let line_comment = remaining.find("//");
        let block_comment = remaining.find("/*");
        match (line_comment, block_comment) {
            (Some(line), Some(block)) if line < block => {
                result.push_str(&remaining[..line]);
                return result;
            }
            (_, Some(block)) => {
                result.push_str(&remaining[..block]);
                remaining = &remaining[block + 2..];
                *in_block_comment = true;
            }
            (Some(line), None) => {
                result.push_str(&remaining[..line]);
                return result;
            }
            (None, None) => {
                result.push_str(remaining);
                return result;
            }
        }
    }
}

fn is_preprocessor_directive(line: &str, expected: &str) -> bool {
    let Some(directive) = line.strip_prefix('#') else {
        return false;
    };
    let directive = directive.trim_start();
    let Some(rest) = directive.strip_prefix(expected) else {
        return false;
    };
    rest.is_empty()
        || rest.chars().next().is_some_and(|character| {
            character.is_whitespace() || character == '<' || character == '"'
        })
}

#[cfg(test)]
mod tests {
    use super::*;
    use sha2::Digest;

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
        let policy = compile_traversal_policy(&[partition], &[shared.clone(), um.clone()]).unwrap();
        assert_eq!(
            policy.audit.sdk_scope_fallbacks,
            [SdkScopeFallback {
                partition: "Direct2D".to_string(),
                namespace: "Windows.Win32.Graphics.Direct2D".to_string(),
                requested: "<IncludeRoot>/um/dciddi.h".to_string(),
                path: shared.join("dciddi.h"),
                requested_scope: "um".to_string(),
                actual_scope: "shared".to_string(),
                explicitly_paired: false,
            }]
        );
        let error = policy.audit.ensure_clean().unwrap_err();
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
        let policy = compile_traversal_policy(&[partition], &[shared.clone(), um.clone()]).unwrap();
        assert!(policy.audit.is_clean());
        assert_eq!(policy.audit.sdk_scope_fallbacks.len(), 1);
        assert!(policy.audit.sdk_scope_fallbacks[0].explicitly_paired);
        policy.audit.ensure_clean().unwrap();
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
        assert!(
            error.contains("outside the approved exact contract"),
            "{error}"
        );
        assert!(error.contains("Windows.Win32.First"), "{error}");
        assert!(error.contains("Windows.Win32.Second"), "{error}");
        std::fs::remove_dir_all(root).unwrap();
    }

    #[test]
    fn root_preflight_rejects_unapproved_same_namespace_owners() {
        let root = std::env::temp_dir().join(format!(
            "win32metadata-partition-same-namespace-{}",
            std::process::id()
        ));
        std::fs::remove_dir_all(&root).ok();
        let shared = root.join("shared");
        std::fs::create_dir_all(&shared).unwrap();
        std::fs::write(shared.join("same.h"), "").unwrap();
        let partitions = vec![
            test_partition(
                &root,
                "First",
                "Windows.Win32.Same",
                &["<IncludeRoot>/shared/same.h"],
            ),
            test_partition(
                &root,
                "Second",
                "Windows.Win32.Same",
                &["<IncludeRoot>/shared/same.h"],
            ),
        ];
        let error = validate_resolved_root_ownership(&partitions, &[shared]).unwrap_err();
        assert!(
            error.contains("outside the approved exact contract"),
            "{error}"
        );
        assert!(error.contains("Windows.Win32.Same"), "{error}");
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
        assert!(
            error.contains("outside the approved exact contract"),
            "{error}"
        );
        assert!(error.contains("Windows.Win32.Unexpected"), "{error}");
        std::fs::remove_dir_all(root).unwrap();
    }

    #[test]
    fn checked_in_psapi_contract_rejects_compile_environment_or_policy_changes() {
        let win_sdk = checked_in_win_sdk();
        let include_dirs = checked_in_include_dirs(&win_sdk);
        let partitions = load_active(&win_sdk.join("Partitions")).unwrap();

        let mut changed_environment = partitions.clone();
        let psapi1 = changed_environment
            .iter_mut()
            .find(|partition| partition.name == "PsApi1")
            .unwrap();
        let original_source = psapi1.source.clone();
        psapi1.source = psapi1
            .source
            .replace("#define PSAPI_VERSION 1", "#define PSAPI_VERSION 3");
        assert_ne!(psapi1.source, original_source);
        let error =
            validate_resolved_root_ownership(&changed_environment, &include_dirs).unwrap_err();
        assert!(error.contains("um/psapi.h"), "{error}");
        assert!(error.contains("PsApi1"), "{error}");
        assert!(
            error.contains("outside the approved exact contract"),
            "{error}"
        );

        let mut changed_policy = partitions;
        let psapi2 = changed_policy
            .iter_mut()
            .find(|partition| partition.name == "PsApi2")
            .unwrap();
        psapi2
            .settings
            .iter_mut()
            .find(|setting| setting.name == "--exclude")
            .unwrap()
            .values
            .push("Synthetic.Policy.Change".to_string());
        let error = validate_resolved_root_ownership(&changed_policy, &include_dirs).unwrap_err();
        assert!(error.contains("um/psapi.h"), "{error}");
        assert!(error.contains("PsApi2"), "{error}");
        assert!(
            error.contains("outside the approved exact contract"),
            "{error}"
        );
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

    #[test]
    fn root_audit_reports_all_missing_unsupported_and_duplicate_roots() {
        let root = std::env::temp_dir().join(format!(
            "win32metadata-partition-audit-all-{}",
            std::process::id()
        ));
        std::fs::remove_dir_all(&root).ok();
        let shared = root.join("shared");
        std::fs::create_dir_all(&shared).unwrap();
        std::fs::write(shared.join("case.h"), "").unwrap();
        std::fs::write(shared.join("duplicate.h"), "").unwrap();

        let partition = test_partition(
            &root,
            "Audit",
            "Windows.Win32.Audit",
            &[
                "<IncludeRoot>/shared/case.h",
                "<IncludeRoot>/SHARED/case.h",
                "<IncludeRoot>/shared/duplicate.h",
                "<IncludeRoot>/shared/duplicate.h",
                "<IncludeRoot>/shared/missing.h",
                "<Unsupported>/shared/other.h",
            ],
        );
        let policy = compile_traversal_policy(&[partition], &[shared]).unwrap();
        assert_eq!(policy.audit.missing_roots.len(), 1);
        assert_eq!(policy.audit.unsupported_roots.len(), 1);
        assert_eq!(
            policy
                .audit
                .duplicate_roots
                .iter()
                .map(|duplicate| duplicate.kind)
                .collect::<Vec<_>>(),
            [
                DuplicateRootKind::Exact,
                DuplicateRootKind::CaseOrSeparatorOnly
            ]
        );
        let error = policy.audit.ensure_clean().unwrap_err();
        assert!(error.contains("missing.h"), "{error}");
        assert!(error.contains("<Unsupported>/shared/other.h"), "{error}");
        assert!(error.contains("has duplicate root"), "{error}");
        assert!(
            error.contains("case- or separator-only duplicate roots"),
            "{error}"
        );
        std::fs::remove_dir_all(root).unwrap();
    }

    #[test]
    fn directory_roots_expand_to_canonical_files_deterministically() {
        let root = std::env::temp_dir().join(format!(
            "win32metadata-partition-directory-root-{}",
            std::process::id()
        ));
        std::fs::remove_dir_all(&root).ok();
        let shared = root.join("shared");
        let headers = shared.join("headers");
        let nested = headers.join("nested");
        std::fs::create_dir_all(&nested).unwrap();
        std::fs::write(headers.join("b.h"), "").unwrap();
        std::fs::write(headers.join("A.h"), "").unwrap();
        std::fs::write(nested.join("c.h"), "").unwrap();

        let partition = test_partition(
            &root,
            "Directory",
            "Windows.Win32.Directory",
            &["<IncludeRoot>/shared/headers"],
        );
        let policy = compile_traversal_policy(&[partition], &[shared]).unwrap();
        assert_eq!(policy.file_root_count(), 0);
        assert_eq!(policy.directory_root_count(), 1);
        assert_eq!(policy.canonical_physical_files().len(), 3);
        let TraversalRoot::Directory(directory) = &policy.partitions[0].roots[0] else {
            panic!("directory root was not retained as a directory");
        };
        assert_eq!(
            directory
                .files
                .iter()
                .map(|file| {
                    file.path
                        .strip_prefix(&headers)
                        .unwrap()
                        .to_string_lossy()
                        .replace('\\', "/")
                })
                .collect::<Vec<_>>(),
            ["A.h", "b.h", "nested/c.h"]
        );
        std::fs::remove_dir_all(root).unwrap();
    }

    #[test]
    fn exact_sdk_scope_directory_roots_resolve_with_case_and_slash_variants() {
        let root = std::env::temp_dir().join(format!(
            "win32metadata-partition-scope-directory-{}",
            std::process::id()
        ));
        std::fs::remove_dir_all(&root).ok();
        let shared = root.join("shared");
        std::fs::create_dir_all(&shared).unwrap();
        std::fs::write(shared.join("root.h"), "").unwrap();

        for requested in [
            "<IncludeRoot>/shared",
            r"<IncludeRoot>\SHARED",
            "<includeroot>/Shared/",
        ] {
            let partition =
                test_partition(&root, "Directory", "Windows.Win32.Directory", &[requested]);
            let roots = partition
                .resolve_roots(std::slice::from_ref(&shared))
                .unwrap();
            assert!(roots.files.is_empty());
            assert_eq!(roots.directories, [shared.clone()]);

            let policy =
                compile_traversal_policy(&[partition], std::slice::from_ref(&shared)).unwrap();
            let TraversalRoot::Directory(directory) = &policy.partitions[0].roots[0] else {
                panic!("exact SDK scope did not resolve as a directory");
            };
            assert_eq!(directory.root.path, shared);
            assert_eq!(directory.root.inventory_path, "shared");
            assert_eq!(directory.files[0].inventory_path, "shared/root.h");
        }
        std::fs::remove_dir_all(root).unwrap();
    }

    #[test]
    fn compiled_policy_order_is_independent_of_partition_input_order() {
        let root = std::env::temp_dir().join(format!(
            "win32metadata-partition-determinism-{}",
            std::process::id()
        ));
        std::fs::remove_dir_all(&root).ok();
        let shared = root.join("shared");
        std::fs::create_dir_all(&shared).unwrap();
        std::fs::write(shared.join("a.h"), "").unwrap();
        std::fs::write(shared.join("b.h"), "").unwrap();
        let first = test_partition(
            &root,
            "First",
            "Windows.Win32.First",
            &["<IncludeRoot>/shared/a.h"],
        );
        let second = test_partition(
            &root,
            "Second",
            "Windows.Win32.Second",
            &["<IncludeRoot>/shared/b.h"],
        );

        let forward =
            compile_traversal_policy(&[first.clone(), second.clone()], &[shared.clone()]).unwrap();
        let reverse = compile_traversal_policy(&[second, first], &[shared]).unwrap();
        assert_eq!(forward, reverse);
        std::fs::remove_dir_all(root).unwrap();
    }

    #[test]
    fn canonical_inventory_digest_tracks_ownership_and_policy_not_checkout_paths() {
        fn create_inventory(
            root: &Path,
            swap_owners: bool,
            add_exclusion: bool,
        ) -> TraversalPolicy {
            let shared = root.join("shared");
            std::fs::create_dir_all(&shared).unwrap();
            std::fs::write(shared.join("a.h"), "").unwrap();
            std::fs::write(shared.join("b.h"), "").unwrap();
            let (first_root, second_root) = if swap_owners {
                ("<IncludeRoot>/shared/b.h", "<IncludeRoot>/shared/a.h")
            } else {
                ("<IncludeRoot>/shared/a.h", "<IncludeRoot>/shared/b.h")
            };
            let mut first = test_partition(root, "First", "Windows.Win32.First", &[first_root]);
            if add_exclusion {
                first.settings.push(Setting {
                    name: "--exclude".to_string(),
                    values: vec!["ChangedPolicy".to_string()],
                });
            }
            let second = test_partition(root, "Second", "Windows.Win32.Second", &[second_root]);
            compile_traversal_policy(&[first, second], &[shared]).unwrap()
        }

        let first_root = std::env::temp_dir().join(format!(
            "win32metadata-partition-digest-first-{}",
            std::process::id()
        ));
        let second_root = std::env::temp_dir().join(format!(
            "win32metadata-partition-digest-second-{}",
            std::process::id()
        ));
        std::fs::remove_dir_all(&first_root).ok();
        std::fs::remove_dir_all(&second_root).ok();

        let baseline = create_inventory(&first_root, false, false);
        let relocated = create_inventory(&second_root, false, false);
        let swapped = create_inventory(&first_root, true, false);
        let changed_policy = create_inventory(&first_root, false, true);
        assert_eq!(
            baseline.canonical_inventory_sha256(),
            relocated.canonical_inventory_sha256()
        );
        assert_ne!(
            baseline.canonical_inventory_sha256(),
            swapped.canonical_inventory_sha256()
        );
        assert_ne!(
            baseline.canonical_inventory_sha256(),
            changed_policy.canonical_inventory_sha256()
        );

        std::fs::remove_dir_all(first_root).unwrap();
        std::fs::remove_dir_all(second_root).unwrap();
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

    fn checked_in_win_sdk() -> PathBuf {
        Path::new(env!("CARGO_MANIFEST_DIR"))
            .join("..")
            .join("..")
            .join("generation")
            .join("WinSDK")
    }

    fn checked_in_include_dirs(win_sdk: &Path) -> Vec<PathBuf> {
        let recompiled = win_sdk.join("RecompiledIdlHeaders");
        vec![
            recompiled.join("shared"),
            recompiled.join("um"),
            recompiled.join("ucrt"),
            recompiled.join("winrt"),
            win_sdk.join("AdditionalHeaders").join("cpdk"),
            win_sdk.join("AdditionalHeaders"),
            win_sdk.join("Partitions").join("Com.StructuredStorage"),
            win_sdk.join("inc"),
        ]
    }

    fn checked_in_traversal_policy() -> TraversalPolicy {
        let win_sdk = checked_in_win_sdk();
        load_traversal_policy(
            &win_sdk.join("Partitions"),
            &checked_in_include_dirs(&win_sdk),
        )
        .unwrap()
    }

    #[test]
    fn checked_in_partition_authority_is_complete() {
        let root = checked_in_win_sdk().join("Partitions");
        let partitions = load_active(&root).unwrap();
        assert_eq!(partitions.len(), 321);
        assert_eq!(
            format!(
                "{:X}",
                sha2::Sha256::digest(
                    partitions
                        .iter()
                        .map(|partition| partition.name.as_str())
                        .collect::<Vec<_>>()
                        .join("\n")
                        .as_bytes()
                )
            ),
            "798D67C1B5C4A73185B992B10BF729962B3B4CBB2AD7FAF06A325128C3333397"
        );
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
            APPROVED_MULTI_PARTITION_ROOTS
                .iter()
                .take(7)
                .map(|approved| approved.path)
                .collect::<Vec<_>>()
        );
        assert_eq!(input_namespaces(&partitions).unwrap().len(), 321);
    }

    #[test]
    fn checked_in_traversal_policy_is_clean_and_canonical() {
        let policy = checked_in_traversal_policy();
        assert_eq!(
            policy.canonical_inventory_sha256(),
            "395FAD2C5729FF81F35311F9D591CA05B9EF4FDCE96173FAB9BBCAF8AFB7E811"
        );
        assert_eq!(policy.partitions.len(), 321);
        assert_eq!(
            policy
                .partitions
                .iter()
                .map(|partition| partition.roots.len())
                .sum::<usize>(),
            1570
        );
        assert_eq!(policy.file_root_count(), 1570);
        assert_eq!(policy.directory_root_count(), 0);
        assert_eq!(policy.canonical_physical_files().len(), 1559);
        assert!(policy.audit.missing_roots.is_empty());
        assert!(policy.audit.unsupported_roots.is_empty());
        assert!(policy.audit.duplicate_roots.is_empty());
        assert_eq!(
            policy
                .audit
                .sdk_scope_fallbacks
                .iter()
                .map(|fallback| (
                    fallback.partition.as_str(),
                    fallback.requested.as_str(),
                    fallback.requested_scope.as_str(),
                    fallback.actual_scope.as_str(),
                    fallback.explicitly_paired,
                ))
                .collect::<Vec<_>>(),
            [
                ("Buses", "<IncludeRoot>/um/usb.h", "um", "shared", true),
                (
                    "WindowsFilteringPlatform",
                    "<IncludeRoot>/um/fwpmtypes.h",
                    "um",
                    "shared",
                    true
                ),
                (
                    "WindowsFilteringPlatform",
                    "<IncludeRoot>/um/fwptypes.h",
                    "um",
                    "shared",
                    true
                ),
            ]
        );
        assert!(policy.audit.is_clean());
        policy.audit.ensure_clean().unwrap();
    }

    #[test]
    fn lower_priority_duplicate_include_roots_do_not_change_inventory_identity() {
        let win_sdk = checked_in_win_sdk();
        let partition_root = win_sdk.join("Partitions");
        let baseline =
            load_traversal_policy(&partition_root, &checked_in_include_dirs(&win_sdk)).unwrap();
        let duplicate_root = std::env::temp_dir().join(format!(
            "win32metadata-partition-duplicate-includes-{}",
            std::process::id()
        ));
        std::fs::remove_dir_all(&duplicate_root).ok();
        let mut include_dirs = checked_in_include_dirs(&win_sdk);
        for name in ["shared", "um", "ucrt", "winrt", "cpdk"] {
            let directory = duplicate_root.join(name);
            std::fs::create_dir_all(&directory).unwrap();
            include_dirs.push(directory);
        }

        let with_duplicates = load_traversal_policy(&partition_root, &include_dirs).unwrap();
        with_duplicates.audit.ensure_clean().unwrap();
        assert_eq!(
            with_duplicates.canonical_inventory_sha256(),
            baseline.canonical_inventory_sha256()
        );
        assert_eq!(
            with_duplicates.audit.physical_overlaps,
            baseline.audit.physical_overlaps
        );

        std::fs::remove_dir_all(duplicate_root).unwrap();
    }

    #[test]
    fn checked_in_multi_partition_owner_contract_is_exact() {
        let policy = checked_in_traversal_policy();
        let cross_namespace = policy
            .audit
            .physical_overlaps
            .iter()
            .filter(|overlap| overlap.kind == PhysicalRootOverlapKind::ApprovedCrossNamespace)
            .map(|overlap| {
                let contract = APPROVED_MULTI_PARTITION_ROOTS
                    .iter()
                    .find(|contract| path_matches_contract(&overlap.inventory_path, contract.path))
                    .unwrap();
                (
                    contract.path,
                    overlap
                        .owners
                        .iter()
                        .map(|owner| (owner.partition.as_str(), owner.namespace.as_str()))
                        .collect::<Vec<_>>(),
                )
            })
            .collect::<Vec<_>>();
        assert_eq!(
            cross_namespace,
            [
                (
                    "shared/ntddstor.h",
                    vec![
                        ("Fs", "Windows.Win32.Storage.FileSystem"),
                        ("Ioctl", "Windows.Win32.System.Ioctl"),
                    ],
                ),
                (
                    "shared/uuids.h",
                    vec![
                        ("Media", "Windows.Win32.Media"),
                        ("Mf", "Windows.Win32.Media.MediaFoundation"),
                    ],
                ),
                (
                    "um/audioendpoints.h",
                    vec![
                        ("Audio", "Windows.Win32.Media.Audio"),
                        ("Audio.Endpoints", "Windows.Win32.Media.Audio.Endpoints",),
                    ],
                ),
                (
                    "um/dxcore.h",
                    vec![
                        ("DXCore", "Windows.Win32.Graphics.DXCore"),
                        ("Display", "Windows.Win32.Devices.Display"),
                    ],
                ),
                (
                    "um/dxcore_interface.h",
                    vec![
                        ("DXCore", "Windows.Win32.Graphics.DXCore"),
                        ("Display", "Windows.Win32.Devices.Display"),
                    ],
                ),
                (
                    "um/endpointvolume.h",
                    vec![
                        ("Audio", "Windows.Win32.Media.Audio"),
                        ("Audio.Endpoints", "Windows.Win32.Media.Audio.Endpoints",),
                    ],
                ),
                (
                    "um/idispids.h",
                    vec![
                        ("ComOle", "Windows.Win32.System.Ole"),
                        ("InternetExplorer", "Windows.Win32.Web.InternetExplorer",),
                    ],
                ),
            ]
        );

        let compile_variants = policy
            .audit
            .physical_overlaps
            .iter()
            .filter(|overlap| overlap.kind == PhysicalRootOverlapKind::ApprovedCompileVariants)
            .collect::<Vec<_>>();
        assert_eq!(compile_variants.len(), 1);
        assert_eq!(compile_variants[0].inventory_path, "um/psapi.h");
        assert_eq!(
            compile_variants[0]
                .owners
                .iter()
                .map(|owner| (
                    owner.partition.as_str(),
                    owner.namespace.as_str(),
                    owner.compile_variant.as_deref()
                ))
                .collect::<Vec<_>>(),
            [
                (
                    "PsApi1",
                    "Windows.Win32.System.ProcessStatus",
                    Some("PSAPI_VERSION=1")
                ),
                (
                    "PsApi2",
                    "Windows.Win32.System.ProcessStatus",
                    Some("PSAPI_VERSION=2")
                ),
            ]
        );
        assert_eq!(policy.audit.physical_overlaps.len(), 8);
    }

    #[test]
    fn checked_in_compile_environment_exception_inventory_is_exact() {
        let policy = checked_in_traversal_policy();
        assert_eq!(
            policy
                .compile_environment_exceptions
                .iter()
                .map(|exception| exception.partition.as_str())
                .collect::<Vec<_>>(),
            [
                "ActiveDirectory",
                "Authorization.UI",
                "Certificates",
                "Cloudapi",
                "Com",
                "Com.Events",
                "Com.StructuredStorage",
                "ComOle",
                "Console",
                "Cos",
                "Debug",
                "Debug.ActiveScript",
                "Debug.WebApp",
                "DevInst",
                "Direct3D",
                "Direct3D10",
                "Direct3D11",
                "Direct3D11on12",
                "Direct3D9on12",
                "Display",
                "DXCore",
                "Fax",
                "Gdiplus",
                "HtmlHelp",
                "HttpServer",
                "Identity",
                "Iis",
                "Input.Ime",
                "InternetExplorer",
                "IO",
                "IpHlp",
                "Kernel",
                "Media.DShow",
                "Media.KernelStreaming",
                "Mf",
                "MsChap",
                "MsCs",
                "Multimedia",
                "Ndf",
                "Printing",
                "PsApi1",
                "PsApi2",
                "RRas",
                "Search",
                "SecBitomet",
                "Security",
                "Security.AppLocker",
                "Security.ConfigurationSnapin",
                "Security.Cryptography",
                "Security.Cryptography.Catalog",
                "Security.Cryptography.Sip",
                "Security.Cryptography.UI",
                "Security.DiagnosticDataQuery",
                "Security.DirectoryServices",
                "Security.LicenseProtection",
                "Security.Tpm",
                "Security.WinTrust",
                "Security.WinWlx",
                "Speech",
                "Tapi3",
                "Threading",
                "WinContacts",
                "WinLocation",
                "WinProg",
                "WinRm",
                "WpdSdk",
            ]
        );
        assert_eq!(policy.compile_environment_exceptions.len(), 66);
        assert_eq!(
            policy
                .compile_environment_exceptions
                .iter()
                .filter_map(|exception| {
                    exception
                        .standard
                        .as_deref()
                        .map(|standard| (exception.partition.as_str(), standard))
                })
                .collect::<Vec<_>>(),
            [("Media.DShow", "c++20"), ("Mf", "c++20")]
        );
        assert_eq!(
            policy
                .compile_environment_exceptions
                .iter()
                .filter(|exception| !exception.include_directories.is_empty())
                .map(|exception| (
                    exception.partition.clone(),
                    exception.include_directories.clone()
                ))
                .collect::<Vec<_>>(),
            [(
                "DXCore".to_string(),
                vec![
                    r"<RepoRoot>\generation\scraper".to_string(),
                    "<IncludeRoot>/shared".to_string(),
                    "<IncludeRoot>/um".to_string(),
                    "<IncludeRoot>/winrt".to_string(),
                ]
            )]
        );
        assert_eq!(
            policy
                .compile_environment_exceptions
                .iter()
                .filter(|exception| !exception.partition_local_roots.is_empty())
                .map(|exception| (
                    exception.partition.clone(),
                    exception.partition_local_roots.clone()
                ))
                .collect::<Vec<_>>(),
            [
                (
                    "Com.StructuredStorage".to_string(),
                    vec!["<PartitionDir>/manual.h".to_string()]
                ),
                (
                    "Threading".to_string(),
                    vec!["<PartitionDir>/main.cpp".to_string()]
                ),
            ]
        );
        assert_eq!(
            policy
                .compile_environment_exceptions
                .iter()
                .filter(|exception| !exception.has_nonordinary_main_source)
                .map(|exception| exception.partition.as_str())
                .collect::<Vec<_>>(),
            ["Com.StructuredStorage", "DXCore", "Media.DShow", "Mf",]
        );
        let defines = |name: &str| {
            policy
                .compile_environment_exceptions
                .iter()
                .find(|exception| exception.partition == name)
                .unwrap()
                .defines
                .iter()
                .filter(|define| !is_boilerplate_define(define))
                .cloned()
                .collect::<Vec<_>>()
        };
        assert_eq!(
            defines("PsApi1"),
            [SourceDefine {
                name: "PSAPI_VERSION".to_string(),
                value: "1".to_string(),
            }]
        );
        assert_eq!(
            defines("PsApi2"),
            [SourceDefine {
                name: "PSAPI_VERSION".to_string(),
                value: "2".to_string(),
            }]
        );
    }

    #[test]
    fn every_checked_in_partition_root_resolves() {
        let win_sdk = checked_in_win_sdk();
        let include_dirs = checked_in_include_dirs(&win_sdk);
        let partitions = load_active(&win_sdk.join("Partitions")).unwrap();
        for partition in &partitions {
            partition.resolve_roots(&include_dirs).unwrap();
        }
        validate_resolved_root_ownership(&partitions, &include_dirs).unwrap();
    }
}
