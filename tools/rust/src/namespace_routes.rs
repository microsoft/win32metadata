use std::collections::BTreeMap;
use std::path::Path;

#[cfg(test)]
use std::collections::BTreeSet;

#[derive(Clone, Debug, Eq, PartialEq)]
pub struct NamespaceRoutes {
    pub exact: BTreeMap<String, String>,
    pub prefixes: BTreeMap<String, String>,
}

impl NamespaceRoutes {
    pub fn load(path: &Path) -> Result<Self, String> {
        let source = std::fs::read_to_string(path)
            .map_err(|error| format!("failed to read `{}`: {error}", path.display()))?;
        Self::parse(&source)
            .map_err(|error| format!("failed to parse `{}`: {error}", path.display()))
    }

    pub fn parse(source: &str) -> Result<Self, String> {
        let mut exact = BTreeMap::new();
        let mut prefixes = BTreeMap::new();
        let mut saw_option = false;

        for (index, raw) in source.lines().enumerate() {
            let line = raw.trim_end_matches('\r').trim_start_matches('\u{feff}');
            if line.is_empty() || line.starts_with('#') {
                continue;
            }
            if line.starts_with("--") {
                if line != "--requiredNamespaceForName"
                    || saw_option
                    || !exact.is_empty()
                    || !prefixes.is_empty()
                {
                    return Err(format!("line {} has unexpected option `{line}`", index + 1));
                }
                saw_option = true;
                continue;
            }

            let (name, namespace) = line.split_once('=').ok_or_else(|| {
                format!(
                    "line {} must have the form NAME=Windows.Win32.Namespace",
                    index + 1
                )
            })?;
            if name.is_empty()
                || name.chars().any(char::is_whitespace)
                || !valid_namespace(namespace)
            {
                return Err(format!("line {} has invalid route `{line}`", index + 1));
            }

            let target = if let Some(prefix) = name.strip_suffix('*') {
                if prefix.is_empty() || prefix.contains('*') {
                    return Err(format!(
                        "line {} has unsupported wildcard route `{line}`; only a trailing `*` is allowed",
                        index + 1
                    ));
                }
                (&mut prefixes, prefix)
            } else {
                if name.contains('*') {
                    return Err(format!(
                        "line {} has unsupported wildcard route `{line}`; only a trailing `*` is allowed",
                        index + 1
                    ));
                }
                (&mut exact, name)
            };

            if let Some(previous) = target.0.insert(target.1.to_string(), namespace.to_string()) {
                return Err(format!(
                    "line {} duplicates route `{}` previously targeting `{previous}`",
                    index + 1,
                    name
                ));
            }
        }

        if !saw_option {
            return Err("missing `--requiredNamespaceForName` option".to_string());
        }

        Ok(Self { exact, prefixes })
    }

    #[cfg(test)]
    pub fn target_namespaces(&self) -> BTreeSet<&str> {
        self.exact
            .values()
            .chain(self.prefixes.values())
            .map(String::as_str)
            .collect()
    }

    pub fn authorities(&self) -> windows_clang::NamespaceAuthorities {
        let mut authorities = windows_clang::NamespaceAuthorities::new();
        for (name, namespace) in &self.exact {
            authorities = authorities.with_exact(name, namespace);
        }
        for (prefix, namespace) in &self.prefixes {
            authorities = authorities.with_wildcard(format!("{prefix}*"), namespace);
        }
        authorities
    }
}

pub(crate) fn valid_identifier(identifier: &str) -> bool {
    let mut chars = identifier.chars();
    chars
        .next()
        .is_some_and(|first| first.is_ascii_alphabetic() || first == '_')
        && chars.all(|value| value.is_ascii_alphanumeric() || value == '_')
}

fn valid_namespace(namespace: &str) -> bool {
    namespace.starts_with("Windows.Win32.") && namespace.split('.').all(valid_identifier)
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn parses_exact_and_prefix_routes_strictly() {
        let routes = NamespaceRoutes::parse(
            "--requiredNamespaceForName\n\
             # region test\n\
             IKsControl=Windows.Win32.Media.KernelStreaming\n\
             PROCESS_CREATION_*=Windows.Win32.System.Threading\n",
        )
        .unwrap();
        assert_eq!(
            routes.exact["IKsControl"],
            "Windows.Win32.Media.KernelStreaming"
        );
        assert_eq!(
            routes.prefixes["PROCESS_CREATION_"],
            "Windows.Win32.System.Threading"
        );

        assert!(
            NamespaceRoutes::parse("--requiredNamespaceForName\nA*B=Windows.Win32.Test\n").is_err()
        );
        assert!(
            NamespaceRoutes::parse(
                "--requiredNamespaceForName\nA=Windows.Win32.Test\nA=Windows.Win32.Other\n"
            )
            .is_err()
        );
        assert!(NamespaceRoutes::parse("--requiredNamespaceForName\nA=Contoso.Test\n").is_err());
        assert!(
            NamespaceRoutes::parse(
                "--requiredNamespaceForName\nA=Windows.Win32.Invalid-Namespace\n"
            )
            .is_err()
        );
        assert!(
            NamespaceRoutes::parse("--requiredNamespaceForName\nInvalid Name=Windows.Win32.Test\n")
                .is_err()
        );
    }

    #[test]
    fn checked_in_routes_match_the_legacy_contract() {
        let path = Path::new(env!("CARGO_MANIFEST_DIR"))
            .join("..")
            .join("..")
            .join("generation")
            .join("WinSDK")
            .join("requiredNamespacesForNames.rsp");
        let routes = NamespaceRoutes::load(&path).unwrap();
        assert_eq!(routes.exact.len(), 2445);
        assert_eq!(routes.prefixes.len(), 7);
        assert_eq!(routes.target_namespaces().len(), 82);
        assert_eq!(
            routes.exact["IKsControl"],
            "Windows.Win32.Media.KernelStreaming"
        );
        assert_eq!(routes.exact["GetDpiForMonitor"], "Windows.Win32.UI.HiDpi");
        assert_eq!(
            routes.prefixes["PROCESS_CREATION_"],
            "Windows.Win32.System.Threading"
        );
    }
}
