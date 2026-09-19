//! Minimal positional option reader shared by the commands.

use std::ffi::OsString;
use std::path::PathBuf;

/// Sequential reader over the raw command-line tail of a single command.
pub struct Args {
    args: Vec<OsString>,
    index: usize,
}

impl Args {
    pub fn new(args: Vec<OsString>) -> Self {
        Self { args, index: 0 }
    }

    /// Returns the next option name, or `None` at the end of the argument list.
    pub fn next_option(&mut self) -> Result<Option<String>, String> {
        let Some(value) = self.args.get(self.index) else {
            return Ok(None);
        };
        self.index += 1;
        match value.to_str() {
            Some(value) => Ok(Some(value.to_string())),
            None => Err(format!(
                "option `{}` is not valid Unicode",
                value.to_string_lossy()
            )),
        }
    }

    /// Consumes the value that follows `option` and requires it to be Unicode.
    pub fn value(&mut self, option: &str) -> Result<String, String> {
        let value = self
            .args
            .get(self.index)
            .ok_or_else(|| format!("missing value for `{option}`"))?;
        self.index += 1;
        value
            .to_str()
            .map(str::to_string)
            .ok_or_else(|| format!("value for `{option}` is not valid Unicode"))
    }

    /// Consumes the value that follows `option` as a path, preserving non-Unicode paths.
    pub fn os_path(&mut self, option: &str) -> Result<PathBuf, String> {
        let value = self
            .args
            .get(self.index)
            .ok_or_else(|| format!("missing value for `{option}`"))?;
        self.index += 1;
        Ok(PathBuf::from(value))
    }

    /// Consumes the value that follows `option` as a path that must be Unicode.
    ///
    /// libclang and the RDL emitter only accept UTF-8 paths, so anything handed to them
    /// is validated here rather than failing later with an opaque message.
    pub fn path(&mut self, option: &str) -> Result<PathBuf, String> {
        Ok(PathBuf::from(self.value(option)?))
    }
}

pub fn set_once<T>(destination: &mut Option<T>, value: T, option: &str) -> Result<(), String> {
    if destination.replace(value).is_some() {
        Err(format!("`{option}` may only be specified once"))
    } else {
        Ok(())
    }
}

pub fn required<T>(value: Option<T>, option: &str) -> Result<T, String> {
    value.ok_or_else(|| format!("required option `{option}` was not provided"))
}
