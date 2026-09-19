//! Panic-to-error adapter.
//!
//! `windows-clang` reports provisioning and scrape failures by panicking (`assert!` in
//! `provision`, `unwrap_or_else(|e| panic!(..))` in `scrape`). A command-line tool should
//! surface those as diagnostics, not as a Rust backtrace, so every call into those entry
//! points is wrapped here.

use std::panic::{AssertUnwindSafe, catch_unwind};

/// Runs `body`, converting a panic into an error prefixed with `context`.
pub fn catch<T>(context: &str, body: impl FnOnce() -> T) -> Result<T, String> {
    let previous = std::panic::take_hook();
    std::panic::set_hook(Box::new(|_| {}));
    let result = catch_unwind(AssertUnwindSafe(body));
    std::panic::set_hook(previous);

    result.map_err(|payload| {
        let message = if let Some(value) = payload.downcast_ref::<&str>() {
            (*value).to_string()
        } else if let Some(value) = payload.downcast_ref::<String>() {
            value.clone()
        } else {
            "the operation panicked without a message".to_string()
        };
        format!("{context}: {message}")
    })
}
