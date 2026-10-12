use std::path::{Path, PathBuf};
use std::sync::atomic::{AtomicU64, Ordering};

static NEXT_ID: AtomicU64 = AtomicU64::new(0);

pub(crate) fn create_directory(parent: &Path, prefix: &str) -> Result<PathBuf, String> {
    create_directory_with_counter(parent, prefix, &NEXT_ID)
}

fn create_directory_with_counter(
    parent: &Path,
    prefix: &str,
    counter: &AtomicU64,
) -> Result<PathBuf, String> {
    std::fs::create_dir_all(parent)
        .map_err(|error| format!("failed to create `{}`: {error}", parent.display()))?;
    loop {
        let id = counter.fetch_add(1, Ordering::Relaxed);
        let path = parent.join(format!("{prefix}-{}-{id}", std::process::id()));
        match std::fs::create_dir(&path) {
            Ok(()) => return Ok(path),
            Err(error) if error.kind() == std::io::ErrorKind::AlreadyExists => {}
            Err(error) => {
                return Err(format!("failed to create `{}`: {error}", path.display()));
            }
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use std::collections::BTreeSet;
    use std::sync::Barrier;

    #[test]
    fn claims_skip_existing_files_and_directories() {
        let root =
            create_directory(&std::env::temp_dir(), "win32metadata-staging-existing").unwrap();
        let prefix = format!(".win32metadata-{}", std::process::id());
        let file = root.join(format!("{prefix}-0"));
        std::fs::write(&file, "existing file").unwrap();
        let directory = root.join(format!("{prefix}-1"));
        std::fs::create_dir(&directory).unwrap();
        std::fs::write(directory.join("owner"), "existing directory").unwrap();

        let claimed =
            create_directory_with_counter(&root, ".win32metadata", &AtomicU64::new(0)).unwrap();
        assert_eq!(claimed, root.join(format!("{prefix}-2")));
        std::fs::remove_dir_all(claimed).unwrap();
        assert_eq!(std::fs::read_to_string(file).unwrap(), "existing file");
        assert_eq!(
            std::fs::read_to_string(directory.join("owner")).unwrap(),
            "existing directory"
        );
        std::fs::remove_dir_all(root).unwrap();
    }

    #[test]
    fn concurrent_colliding_claims_keep_distinct_owners() {
        const WORKERS: usize = 16;
        let root =
            create_directory(&std::env::temp_dir(), "win32metadata-staging-concurrent").unwrap();
        let barrier = Barrier::new(WORKERS);
        let claims = std::thread::scope(|scope| {
            let workers = (0..WORKERS)
                .map(|worker| {
                    let root = &root;
                    let barrier = &barrier;
                    scope.spawn(move || {
                        barrier.wait();
                        let claimed = create_directory_with_counter(
                            root,
                            ".win32metadata",
                            &AtomicU64::new(0),
                        )
                        .unwrap();
                        std::fs::write(claimed.join("owner"), worker.to_string()).unwrap();
                        (claimed, worker)
                    })
                })
                .collect::<Vec<_>>();
            workers
                .into_iter()
                .map(|worker| worker.join().unwrap())
                .collect::<Vec<_>>()
        });
        assert_eq!(
            claims
                .iter()
                .map(|(path, _)| path)
                .collect::<BTreeSet<_>>()
                .len(),
            WORKERS
        );
        for (path, worker) in claims {
            assert_eq!(
                std::fs::read_to_string(path.join("owner")).unwrap(),
                worker.to_string()
            );
        }
        std::fs::remove_dir_all(root).unwrap();
    }

    #[test]
    fn noncollision_errors_are_reported() {
        let root = create_directory(&std::env::temp_dir(), "win32metadata-staging-error").unwrap();
        let file = root.join("not-a-directory");
        std::fs::write(&file, "").unwrap();
        let error = create_directory(&file, ".win32metadata").unwrap_err();
        assert!(error.contains("failed to create"), "{error}");
        assert!(error.contains("not-a-directory"), "{error}");
        std::fs::remove_dir_all(root).unwrap();
    }
}
