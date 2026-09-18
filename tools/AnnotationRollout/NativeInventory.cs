using System.Runtime.InteropServices;
using System.Text.Json;

namespace AnnotationRollout;

internal sealed record NativeSymbol(
    string Id, string NativeIdentity, string Usr, string Name, string Kind, string Header, string Source, uint Line, uint Column,
    string Parent, string Signature, string Architecture, string Partition, string Fingerprint,
    string ConditionContext, string[] Families, string State, Dictionary<string, object> Facts);

internal static class NativeInventory
{
    [StructLayout(LayoutKind.Sequential)]
    private struct Cursor { public uint Kind; public int XData; public IntPtr Data0, Data1, Data2; }
    [StructLayout(LayoutKind.Sequential)]
    private struct ClangType { public uint Kind; public IntPtr Data0, Data1; }
    [StructLayout(LayoutKind.Sequential)]
    private struct ClangString { public IntPtr Data; public uint Flags; }
    [StructLayout(LayoutKind.Sequential)]
    private struct Location { public IntPtr Data0, Data1; public uint Data2; }
    [StructLayout(LayoutKind.Sequential)]
    private struct Range { public IntPtr Data0, Data1; public uint Begin, End; }
    [StructLayout(LayoutKind.Sequential)]
    private struct Token { public uint Data0, Data1, Data2, Data3; public IntPtr Pointer; }
    [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
    private delegate uint Visitor(Cursor cursor, Cursor parent, IntPtr data);
    [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
    private delegate void InclusionVisitor(IntPtr file, IntPtr stack, uint length, IntPtr data);

    private const string Library = "libclang.dll";
    private static string? loadedLibrary;
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern IntPtr clang_createIndex(int exclude, int diagnostics);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern void clang_disposeIndex(IntPtr index);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern IntPtr clang_parseTranslationUnit(IntPtr index, [MarshalAs(UnmanagedType.LPUTF8Str)] string file, IntPtr args, int count, IntPtr unsaved, uint unsavedCount, uint flags);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern void clang_disposeTranslationUnit(IntPtr tu);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern Cursor clang_getTranslationUnitCursor(IntPtr tu);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern uint clang_visitChildren(Cursor cursor, Visitor visitor, IntPtr data);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern ClangString clang_getCursorSpelling(Cursor cursor);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern ClangString clang_getCursorUSR(Cursor cursor);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern ClangString clang_getCursorKindSpelling(uint kind);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern Location clang_getCursorLocation(Cursor cursor);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern Range clang_getCursorExtent(Cursor cursor);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern void clang_tokenize(IntPtr tu, Range range, out IntPtr tokens, out uint count);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern ClangString clang_getTokenSpelling(IntPtr tu, Token token);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern void clang_disposeTokens(IntPtr tu, IntPtr tokens, uint count);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern void clang_getExpansionLocation(Location location, out IntPtr file, out uint line, out uint column, out uint offset);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern ClangString clang_getFileName(IntPtr file);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern ClangType clang_getCursorType(Cursor cursor);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern ClangType clang_getCanonicalType(ClangType type);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern ClangString clang_getTypeSpelling(ClangType type);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern ClangType clang_getTypedefDeclUnderlyingType(Cursor cursor);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern ClangType clang_getEnumDeclIntegerType(Cursor cursor);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern ClangType clang_getResultType(ClangType type);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern int clang_getNumArgTypes(ClangType type);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern ClangType clang_getArgType(ClangType type, uint index);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern uint clang_getFunctionTypeCallingConv(ClangType type);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern long clang_getEnumConstantDeclValue(Cursor cursor);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern ulong clang_getEnumConstantDeclUnsignedValue(Cursor cursor);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern long clang_Type_getSizeOf(ClangType type);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern long clang_Type_getAlignOf(ClangType type);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern long clang_Cursor_getOffsetOfField(Cursor cursor);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern int clang_getFieldDeclBitWidth(Cursor cursor);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern Cursor clang_getTypeDeclaration(ClangType type);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern ClangType clang_getPointeeType(ClangType type);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern ClangType clang_getArrayElementType(ClangType type);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern long clang_getArraySize(ClangType type);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern uint clang_isConstQualifiedType(ClangType type);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern uint clang_isVolatileQualifiedType(ClangType type);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern uint clang_isCursorDefinition(Cursor cursor);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern uint clang_getNumDiagnostics(IntPtr tu);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern IntPtr clang_getDiagnostic(IntPtr tu, uint index);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern uint clang_getDiagnosticSeverity(IntPtr diagnostic);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern ClangString clang_formatDiagnostic(IntPtr diagnostic, uint options);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern void clang_disposeDiagnostic(IntPtr diagnostic);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern IntPtr clang_getCString(ClangString value);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern void clang_disposeString(ClangString value);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern ClangString clang_getClangVersion();
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern void clang_getInclusions(IntPtr tu, InclusionVisitor visitor, IntPtr data);

    private static string Text(ClangString value)
    {
        try { return Marshal.PtrToStringUTF8(clang_getCString(value)) ?? ""; }
        finally { clang_disposeString(value); }
    }

    private static List<Cursor> Children(Cursor cursor)
    {
        var children = new List<Cursor>();
        Visitor visitor = (child, _, _) => { children.Add(child); return 1; };
        clang_visitChildren(cursor, visitor, IntPtr.Zero);
        GC.KeepAlive(visitor);
        return children;
    }

    private static (string Path, uint Line, uint Column) Source(Cursor cursor)
    {
        clang_getExpansionLocation(clang_getCursorLocation(cursor), out var file, out var line, out var column, out _);
        return (file == IntPtr.Zero ? "" : Text(clang_getFileName(file)).Replace('/', '\\'), line, column);
    }

    private static Dictionary<string, object> TypeFacts(ClangType type, int depth = 0)
    {
        Data.Require(depth < 128, "Native type nesting exceeds supported limit.");
        var declaration = clang_getTypeDeclaration(type);
        var result = new Dictionary<string, object>
        {
            ["spelling"] = Text(clang_getTypeSpelling(type)),
            ["canonical"] = Text(clang_getTypeSpelling(clang_getCanonicalType(type))),
            ["size"] = clang_Type_getSizeOf(type),
            ["alignment"] = clang_Type_getAlignOf(type),
            ["const"] = clang_isConstQualifiedType(type) != 0,
            ["volatile"] = clang_isVolatileQualifiedType(type) != 0,
            ["declarationUsr"] = Text(clang_getCursorUSR(declaration)),
            ["declarationSource"] = Source(declaration).Path
        };
        var pointee = clang_getPointeeType(type);
        if (pointee.Kind != 0) result["pointee"] = TypeFacts(pointee, depth + 1);
        var element = clang_getArrayElementType(type);
        if (element.Kind != 0)
        {
            result["element"] = TypeFacts(element, depth + 1);
            result["arraySize"] = clang_getArraySize(type);
        }
        int count = clang_getNumArgTypes(type);
        if (count >= 0)
        {
            result["callingConvention"] = clang_getFunctionTypeCallingConv(type);
            result["return"] = TypeFacts(clang_getResultType(type), depth + 1);
            result["parameters"] = Enumerable.Range(0, count).Select(i => TypeFacts(clang_getArgType(type, (uint)i), depth + 1)).ToArray();
        }
        return result;
    }

    private static string[] Tokens(IntPtr tu, Cursor cursor)
    {
        clang_tokenize(tu, clang_getCursorExtent(cursor), out var tokens, out var count);
        try
        {
            return Enumerable.Range(0, checked((int)count)).Select(i =>
                Text(clang_getTokenSpelling(tu, Marshal.PtrToStructure<Token>(IntPtr.Add(tokens, i * Marshal.SizeOf<Token>()))))).ToArray();
        }
        finally { clang_disposeTokens(tu, tokens, count); }
    }

    internal static string[] Arguments(Ledger ledger, string architecture)
    {
        var target = architecture switch
        {
            "x64" => "x86_64-pc-windows-msvc",
            "x86" => "i686-pc-windows-msvc",
            "arm64" => "aarch64-pc-windows-msvc",
            _ => throw new InvalidDataException("Unsupported architecture.")
        };
        return [$"--target={target}", "-x", "c++", "-std=c++17", "-fms-compatibility", "-ferror-limit=0",
            "-Wno-pragma-once-outside-header", "-DWIN32METADATA=1", "-D_COM_NO_STANDARD_GUIDS_=1",
            "-resource-dir", Directory.GetParent(ledger.ResourceDirectory)!.FullName,
            .. Census.IncludeDirectories(ledger).SelectMany(d => new[] { "-isystem", d })];
    }

    internal static string CaptureFingerprint(Ledger ledger, Partition partition, string architecture, IEnumerable<FileFact> dependencies) =>
        Data.Identity(partition.Id, architecture, Data.Hash(partition.Path), ledger.Libclang!.Sha256,
            Data.Hash(Path.Combine(ledger.Repository, @"tools\AnnotationRollout\NativeInventory.cs")),
            Data.Hash(Path.Combine(ledger.Repository, @"tools\AnnotationRollout\Model.cs")),
            string.Join("\n", Arguments(ledger, architecture)),
            string.Join("\n", Census.IncludeDirectories(ledger).SelectMany(d =>
                Directory.EnumerateFiles(d, "*", SearchOption.AllDirectories).Order(StringComparer.Ordinal))),
            string.Join("\n", dependencies.OrderBy(d => d.Path, StringComparer.Ordinal).Select(d => d.Path + "\t" + d.Sha256)));

    internal static bool IsCurrent(Ledger ledger, Partition partition, string architecture, CaptureFact capture)
    {
        if (capture.Dependencies.Any(d => !File.Exists(d.Path) || Data.Hash(d.Path) != d.Sha256)) return false;
        return CaptureFingerprint(ledger, partition, architecture, capture.Dependencies) == capture.Fingerprint;
    }

    internal static CaptureFact Capture(Ledger ledger, Partition partition, string architecture, string directory)
    {
        var library = ledger.Libclang!.Path;
        if (loadedLibrary == null)
        {
            NativeLibrary.SetDllImportResolver(typeof(NativeInventory).Assembly,
                (name, _, _) => name == Library ? NativeLibrary.Load(library) : IntPtr.Zero);
            loadedLibrary = library;
        }
        Data.Require(loadedLibrary == library, "Cannot switch pinned compiler within a process.");
        Data.Require(!Directory.Exists(directory), "Capture evidence already exists.");
        Directory.CreateDirectory(directory);
        var arguments = Arguments(ledger, architecture);
        var headerPaths = ledger.Headers.ToDictionary(h => Census.Key(h.Path), h => h.Id);
        var resourcePaths = ledger.Inputs.Where(i => i.Role == "compiler-resource").Select(i => Census.Key(i.Path)).ToHashSet();
        var symbolsFile = Path.Combine(directory, "symbols.jsonl");
        var manifestFile = Path.Combine(directory, "capture.json");
        var diagnostics = new List<object>();
        var included = new HashSet<string>(StringComparer.OrdinalIgnoreCase);
        var unknownSources = new HashSet<string>(StringComparer.OrdinalIgnoreCase);
        bool errors = false;
        long symbolCount = 0, obligationCount = 0;
        string captureFingerprint = "";
        FileFact[] dependencies = [];
        var identities = new HashSet<string>();
        var index = clang_createIndex(0, 0);
        Data.Require(index != IntPtr.Zero, "libclang index allocation failed.");
        IntPtr tu = IntPtr.Zero;
        using var output = new StreamWriter(symbolsFile, false, new System.Text.UTF8Encoding(false));
        var compact = new JsonSerializerOptions(Data.Json) { WriteIndented = false };
        void WriteSymbol(Cursor cursor, string parent, string? syntheticKind = null, ClangType? syntheticType = null)
        {
            var source = Source(cursor);
            if (source.Path.Length == 0) return;
            var key = Census.Key(source.Path);
            if (!headerPaths.TryGetValue(key, out var header))
            {
                if (!resourcePaths.Contains(key) && key != Census.Key(partition.Path)) unknownSources.Add(source.Path);
                return;
            }
            var kind = syntheticKind ?? Text(clang_getCursorKindSpelling(cursor.Kind));
            var name = syntheticKind ?? Text(clang_getCursorSpelling(cursor));
            var usr = Text(clang_getCursorUSR(cursor));
            var type = syntheticType ?? clang_getCursorType(cursor);
            var signature = Text(clang_getTypeSpelling(type));
            var nativeIdentity = Data.Identity(header, cursor.Kind == 501 ? name : usr, kind, name, parent, signature, architecture);
            var id = Data.Identity(header, usr, kind, name, parent, signature,
                source.Line.ToString(), source.Column.ToString(), architecture, partition.Id);
            if (!identities.Add(id)) return; // A cursor can be exposed more than once; retain distinct declaration sites.
            var facts = new Dictionary<string, object> { ["type"] = TypeFacts(type), ["definition"] = clang_isCursorDefinition(cursor) != 0 };
            if (syntheticKind == null)
            {
                facts["annotations"] = Children(cursor).Where(c => c.Kind is >= 400 and < 500)
                    .Select(c => new { kind = Text(clang_getCursorKindSpelling(c.Kind)), spelling = Text(clang_getCursorSpelling(c)) }).ToArray();
                if (cursor.Kind is 20 or 36) facts["underlyingType"] = TypeFacts(clang_getTypedefDeclUnderlyingType(cursor));
                if (cursor.Kind == 5) facts["underlyingType"] = TypeFacts(clang_getEnumDeclIntegerType(cursor));
                if (cursor.Kind == 6)
                {
                    facts["offsetBits"] = clang_Cursor_getOffsetOfField(cursor);
                    facts["bitWidth"] = clang_getFieldDeclBitWidth(cursor);
                }
                if (cursor.Kind == 7)
                {
                    facts["signedValue"] = clang_getEnumConstantDeclValue(cursor);
                    facts["unsignedValue"] = clang_getEnumConstantDeclUnsignedValue(cursor);
                }
                if (cursor.Kind is 501 or 10) facts["tokens"] = Tokens(tu, cursor);
            }
            var families = Vocabulary.FamiliesFor(kind);
            var symbol = new NativeSymbol(id, nativeIdentity, usr, name, kind, header, source.Path, source.Line, source.Column,
                parent, signature, architecture, partition.Id, captureFingerprint,
                "canonical TU active branch; source conditional directives require separate reconciliation",
                families, "pending", facts);
            output.WriteLine(JsonSerializer.Serialize(symbol, compact));
            symbolCount++;
            obligationCount += families.Length;
        }
        try
        {
            var strings = arguments.Select(Marshal.StringToCoTaskMemUTF8).ToArray();
            var argv = Marshal.AllocHGlobal(IntPtr.Size * strings.Length);
            try
            {
                Marshal.Copy(strings, 0, argv, strings.Length);
                tu = clang_parseTranslationUnit(index, partition.Path, argv, strings.Length, IntPtr.Zero, 0, 1);
            }
            finally
            {
                Marshal.FreeHGlobal(argv);
                foreach (var value in strings) Marshal.FreeCoTaskMem(value);
            }
            Data.Require(tu != IntPtr.Zero, "libclang parse failed.");
            for (uint i = 0; i < clang_getNumDiagnostics(tu); i++)
            {
                var diagnostic = clang_getDiagnostic(tu, i);
                try
                {
                    var severity = clang_getDiagnosticSeverity(diagnostic);
                    errors |= severity >= 3;
                    diagnostics.Add(new { severity, text = Text(clang_formatDiagnostic(diagnostic, 0x3f)) });
                }
                finally { clang_disposeDiagnostic(diagnostic); }
            }
            InclusionVisitor visitor = (file, _, _, _) => included.Add(Text(clang_getFileName(file)).Replace('/', '\\'));
            clang_getInclusions(tu, visitor, IntPtr.Zero);
            GC.KeepAlive(visitor);
            dependencies = included.Order(StringComparer.Ordinal).Select(FileFact.Capture).ToArray();
            captureFingerprint = CaptureFingerprint(ledger, partition, architecture, dependencies);
            var queue = new Queue<(Cursor Cursor, string Parent)>();
            foreach (var cursor in Children(clang_getTranslationUnitCursor(tu))) queue.Enqueue((cursor, ""));
            while (queue.TryDequeue(out var entry))
            {
                var (cursor, parent) = entry;
                if (cursor.Kind == 501 || cursor.Kind is >= 1 and <= 39 || cursor.Kind == 44)
                    WriteSymbol(cursor, parent);
                if (cursor.Kind is 8 or 21 or 24 or 25 or 26)
                    WriteSymbol(cursor, Text(clang_getCursorUSR(cursor)), "Return", clang_getResultType(clang_getCursorType(cursor)));
                if (cursor.Kind is >= 1 and <= 39 || cursor.Kind == 300)
                {
                    var owner = Text(clang_getCursorUSR(cursor));
                    if (owner.Length == 0) owner = parent + "/" + Text(clang_getCursorSpelling(cursor));
                    foreach (var child in Children(cursor))
                        if (child.Kind is >= 1 and <= 49 || child.Kind == 300) queue.Enqueue((child, owner));
                }
            }
        }
        finally
        {
            output.Flush();
            output.Dispose();
            errors |= unknownSources.Count > 0;
            Data.Write(manifestFile, new
            {
                schemaVersion = 1,
                fingerprint = captureFingerprint,
                sourceUniverseFingerprint = ledger.Fingerprint,
                partition = partition.Id,
                architecture,
                command = new { library, entryPoint = "clang_parseTranslationUnit", translationUnit = FileFact.Capture(partition.Path), arguments, flags = 1 },
                compiler = Text(clang_getClangVersion()),
                hasErrors = errors,
                diagnostics,
                unknownSources,
                includedFiles = dependencies,
                symbols = FileFact.Capture(symbolsFile),
                symbolCount,
                obligationCount,
                scope = "All active source declarations, members, parameters, returns and macro definitions; not semantic acceptance."
            });
            if (tu != IntPtr.Zero) clang_disposeTranslationUnit(tu);
            clang_disposeIndex(index);
        }
        return new(FileFact.Capture(manifestFile), FileFact.Capture(symbolsFile), symbolCount, obligationCount,
            captureFingerprint, errors, included.Where(p => headerPaths.ContainsKey(Census.Key(p))).Select(p => headerPaths[Census.Key(p)]).Order(StringComparer.Ordinal).ToArray(),
            dependencies);
    }
}
