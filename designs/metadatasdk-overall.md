# Win32 Metadata SDK Overview

## Goal

Provide the public surface area of the Win32 SDK in a language-agnostic format that can be projected into other languages such as Rust or modern C++.

## Motivation

The public API surface area of Win32 is described with C/C++ headers. These are not easily parseable for those who want to make an interop layer from different languages to Win32 APIs. As other languages gain in popularity, we would like to meet developers where they're at and provide a way for them to make use of Win32 APIs in languages other than C/C++. Once we are able to describe the Win32 API surface in metadata, we can create language projections so developers can call Win32 APIs from those languages.

## Metadata Requirements
### Types
#### Basic Types
- Int8/16/32/64 signed unsigned
- float/double
- Boolean types: Could be a type or an annotation on a type, but an annotation would preserve the ABI (signed/unsigned/size) and let the language projection use whatever type it wants for boolean types.
- Cross-arch pointer sizes
- size_t
#### Callbacks
- Function Pointers
#### Structs
- Packing
- Bit fields
- Per-arch definitions
- Unions
- Nested structs
#### Values
- Enums
- Flags
- Constants
#### Complex types
- HANDLE or other Win32 resources – groups like resources together, indicates how to close them, what value to use for invalid
- Buffers
- Strings – utf8, mbcs, ascii, utf16, hstring
- GUID
#### COM Interfaces
- Could be out of scope for v1, but some flat Win32 APIs use them as parameters
#### API usage patterns
- Double-call allocate / fill
- Inline funtions - could be useful for language projections, but how would you describe these in metadata?

## Metadata Formats

### ECMA-335

One proposal is to use [ECMA-335](http://www.ecma-international.org/publications/standards/Ecma-335.htm), which is the metadata format used for .NET binaries.

#### Pros
- This format is currently used for WinRT metadata (.winmd files) and is already consumed by [C++/WinRT](https://github.com/Microsoft/cppwinrt) and [Rust WinRT](https://github.com/Microsoft/cppwinrt) in order to project WinRT APIs. These two projects already have tooling to parse and consume ECMA-335 binaries, so consuming ECMA-335 metadata for Win32 APIs should be less work than using a completely new format.
- Managed code was originally designed to work well with Win32 interop, so most of the Win32 concepts we need expressed in metadata should already exist.
- It is trivial to write C# code that uses reflection to examine the metadata from a C# binary.

#### Cons
- ECMA-335 can't express all C constructs, such as bit fields or anonymous structs. We could use attributes on structs and struct fields to express them, but it does seem like a bit of an ugly way to do things. The language projection would then need to parse the attributes to figure out what is really meant instead of the data being directly available in the metadata.

### Json

#### Pros
- Json is easily consumable from many existing languages. Tool writers could use the library of their choice to walk the Win32 metadata emitted by our tool.

#### Cons
- Our existing language projections already understand ECMA-335, so more new code would need to be written for json metadata than would be needed for ECMA-335.

## Pieces Needed

### Scraper
A tool that can accurately scrape Win32 C/C++ headers for the information needed to construct language-agnostic metadata. It should be able to capture:

- API functions and which DLL exports each function
- structs, including unions and embedded structs, packing information, and bit fields
- Function pointers for APIs that use callback semantics
- enums
- In/out/optional semantics for each parameter

### Metadata emitter
The emitter will take the output of the scraper and emit metadata. Currently there is information we need emitted that isn't in the current Win32 headers. This could be added to the headers in the future, but for now the emitter will need additional input:

- Which functions call `SetLastError`.
- Which parameters and fields that represent Win32 resources (e.g. handles and GDI objects) are logically grouped together and which Win32 function can be called to release them (e.g. file handles vs. registry handles vs. GDI objects).
- Many functions use a non-enum type, like a DWORD, and then use many #define statements to describe the possible values that function can recognize for tht parameter.

### Language projections

We will need individual tools that turn the ABI represented in metadata into language-specific projections.

- Modern C++ -- someone might ask, why would you need this when you can just use the C-style APIs? This projection could use RAII types for Win32 resources (e.g. handles and GDI objects). It could also potentially use exceptions by interpreting the C-style return codes.
- Rust
- C# -- we would expect this to use SafeHandle abstractions for Win32 resources (e.g. handles and GDI objects), string objects for strings instead of char*/wchar*, etc.