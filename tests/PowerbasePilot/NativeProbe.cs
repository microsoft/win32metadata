using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;

// Uses the same pinned libclang as generation; it never executes a Windows API.
public static class PowerbaseNativeProbe
{
    [StructLayout(LayoutKind.Sequential)]
    private struct Cursor
    {
        public uint Kind;
        public int XData;
        public IntPtr Data0, Data1, Data2;
    }

    [StructLayout(LayoutKind.Sequential)]
    private struct NativeType
    {
        public uint Kind;
        public IntPtr Data0, Data1;
    }

    [StructLayout(LayoutKind.Sequential)]
    private struct NativeString
    {
        public IntPtr Data;
        public uint Flags;
    }

    [StructLayout(LayoutKind.Sequential)]
    private struct Location
    {
        public IntPtr Data0, Data1;
        public uint Data2;
    }

    [StructLayout(LayoutKind.Sequential)]
    private struct SourceRange
    {
        public IntPtr Data0, Data1;
        public uint Begin, End;
    }

    [StructLayout(LayoutKind.Sequential)]
    private struct Token
    {
        public uint Data0, Data1, Data2, Data3;
        public IntPtr Pointer;
    }

    [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
    private delegate uint Visitor(Cursor cursor, Cursor parent, IntPtr data);
    [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
    private delegate void InclusionVisitor(IntPtr file, IntPtr stack, uint length, IntPtr data);

    private const string Library = "libclang.dll";
    private static string loadedLibrary;
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern IntPtr clang_createIndex(int exclude, int diagnostics);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern void clang_disposeIndex(IntPtr index);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern IntPtr clang_parseTranslationUnit(IntPtr index, [MarshalAs(UnmanagedType.LPUTF8Str)] string file, IntPtr args, int count, IntPtr unsaved, uint unsavedCount, uint flags);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern void clang_disposeTranslationUnit(IntPtr tu);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern Cursor clang_getTranslationUnitCursor(IntPtr tu);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern uint clang_visitChildren(Cursor cursor, Visitor visitor, IntPtr data);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern NativeString clang_getCursorSpelling(Cursor cursor);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern NativeString clang_getCursorKindSpelling(uint kind);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern Location clang_getCursorLocation(Cursor cursor);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern SourceRange clang_getCursorExtent(Cursor cursor);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern Location clang_getRangeStart(SourceRange range);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern Cursor clang_getCursorReferenced(Cursor cursor);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern void clang_tokenize(IntPtr tu, SourceRange range, out IntPtr tokens, out uint count);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern NativeString clang_getTokenSpelling(IntPtr tu, Token token);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern void clang_disposeTokens(IntPtr tu, IntPtr tokens, uint count);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern void clang_getExpansionLocation(Location location, out IntPtr file, out uint line, out uint column, out uint offset);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern NativeString clang_getFileName(IntPtr file);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern NativeType clang_getCursorType(Cursor cursor);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern NativeType clang_getCanonicalType(NativeType type);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern NativeString clang_getTypeSpelling(NativeType type);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern NativeType clang_getTypedefDeclUnderlyingType(Cursor cursor);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern NativeType clang_getEnumDeclIntegerType(Cursor cursor);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern NativeType clang_getResultType(NativeType type);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern uint clang_getFunctionTypeCallingConv(NativeType type);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern int clang_Cursor_getNumArguments(Cursor cursor);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern Cursor clang_Cursor_getArgument(Cursor cursor, uint index);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern long clang_getEnumConstantDeclValue(Cursor cursor);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern ulong clang_getEnumConstantDeclUnsignedValue(Cursor cursor);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern long clang_Type_getSizeOf(NativeType type);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern long clang_Type_getAlignOf(NativeType type);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern long clang_Cursor_getOffsetOfField(Cursor cursor);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern int clang_getFieldDeclBitWidth(Cursor cursor);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern Cursor clang_getTypeDeclaration(NativeType type);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern NativeType clang_getPointeeType(NativeType type);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern NativeType clang_getArrayElementType(NativeType type);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern uint clang_getNumDiagnostics(IntPtr tu);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern IntPtr clang_getDiagnostic(IntPtr tu, uint index);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern uint clang_getDiagnosticSeverity(IntPtr diagnostic);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern NativeString clang_formatDiagnostic(IntPtr diagnostic, uint options);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern void clang_disposeDiagnostic(IntPtr diagnostic);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern IntPtr clang_getCString(NativeString value);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern void clang_disposeString(NativeString value);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern NativeString clang_getClangVersion();
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern void clang_getInclusions(IntPtr tu, InclusionVisitor visitor, IntPtr data);

    private static string Text(NativeString value)
    {
        try { return Marshal.PtrToStringUTF8(clang_getCString(value)) ?? ""; }
        finally { clang_disposeString(value); }
    }

    private static List<Cursor> Children(Cursor cursor)
    {
        var result = new List<Cursor>();
        Visitor visit = (child, parent, data) => { result.Add(child); return 1; };
        clang_visitChildren(cursor, visit, IntPtr.Zero);
        GC.KeepAlive(visit);
        return result;
    }

    private static Dictionary<string, object> Source(Cursor cursor)
    {
        return Source(clang_getCursorLocation(cursor));
    }

    private static Dictionary<string, object> Source(Location location)
    {
        clang_getExpansionLocation(location, out var file, out var line, out var column, out var offset);
        return new Dictionary<string, object> {
            ["file"] = file == IntPtr.Zero ? "" : Text(clang_getFileName(file)).Replace('/', '\\'),
            ["line"] = line, ["column"] = column, ["offset"] = offset
        };
    }

    private static string[] Tokens(IntPtr tu, Cursor cursor)
    {
        clang_tokenize(tu, clang_getCursorExtent(cursor), out var tokens, out var count);
        try
        {
            var result = new string[count];
            for (int i = 0; i < count; i++)
                result[i] = Text(clang_getTokenSpelling(tu, Marshal.PtrToStructure<Token>(IntPtr.Add(tokens, i * Marshal.SizeOf<Token>()))));
            return result;
        }
        finally { clang_disposeTokens(tu, tokens, count); }
    }

    private static Dictionary<string, object> TypeFacts(NativeType type)
    {
        return new Dictionary<string, object> {
            ["spelling"] = Text(clang_getTypeSpelling(type)),
            ["canonical"] = Text(clang_getTypeSpelling(clang_getCanonicalType(type))),
            ["size"] = clang_Type_getSizeOf(type),
            ["alignment"] = clang_Type_getAlignOf(type)
        };
    }

    private static Dictionary<string, object> Facts(Cursor cursor)
    {
        var type = clang_getCursorType(cursor);
        var result = new Dictionary<string, object> {
            ["kind"] = Text(clang_getCursorKindSpelling(cursor.Kind)),
            ["name"] = Text(clang_getCursorSpelling(cursor)),
            ["source"] = Source(cursor),
            ["type"] = TypeFacts(type),
            ["annotations"] = Children(cursor).Where(c => c.Kind == 406).Select(c => Text(clang_getCursorSpelling(c))).ToArray()
        };
        if (cursor.Kind == 8)
        {
            result["returnType"] = TypeFacts(clang_getResultType(type));
            result["callingConvention"] = clang_getFunctionTypeCallingConv(type);
            int count = clang_Cursor_getNumArguments(cursor);
            result["parameters"] = Enumerable.Range(0, count).Select(i => Facts(clang_Cursor_getArgument(cursor, (uint)i))).ToArray();
        }
        else if (cursor.Kind == 20)
        {
            result["underlyingType"] = TypeFacts(clang_getTypedefDeclUnderlyingType(cursor));
        }
        else if (cursor.Kind == 5)
        {
            result["underlyingType"] = TypeFacts(clang_getEnumDeclIntegerType(cursor));
            result["members"] = Children(cursor).Where(c => c.Kind == 7).Select(Facts).ToArray();
        }
        else if (cursor.Kind == 7)
        {
            result["signedValue"] = clang_getEnumConstantDeclValue(cursor);
            result["unsignedValue"] = clang_getEnumConstantDeclUnsignedValue(cursor);
        }
        else if (cursor.Kind == 2 || cursor.Kind == 3)
        {
            result["fields"] = Children(cursor).Where(c => c.Kind == 6).Select(Facts).ToArray();
        }
        else if (cursor.Kind == 6)
        {
            result["offsetBits"] = clang_Cursor_getOffsetOfField(cursor);
            result["bitWidth"] = clang_getFieldDeclBitWidth(cursor);
        }
        return result;
    }

    private static string Identity(Cursor cursor)
    {
        return cursor.Kind + ":" + Source(cursor)["file"] + ":" + Text(clang_getCursorSpelling(cursor));
    }

    public static object Capture(string library, string file, string header, string[] args)
    {
        library = Path.GetFullPath(library);
        if (loadedLibrary == null)
        {
            NativeLibrary.SetDllImportResolver(typeof(PowerbaseNativeProbe).Assembly,
                (name, assembly, searchPath) => name == Library ? NativeLibrary.Load(library) : IntPtr.Zero);
            loadedLibrary = library;
        }
        else if (!string.Equals(loadedLibrary, library, StringComparison.OrdinalIgnoreCase))
        {
            throw new InvalidOperationException("A different libclang is already loaded in this process.");
        }
        return Capture(file, header, args);
    }

    public static object Capture(string file, string header, string[] args)
    {
        var index = clang_createIndex(0, 0);
        if (index == IntPtr.Zero) throw new InvalidOperationException("libclang index creation failed");
        IntPtr tu = IntPtr.Zero;
        try
        {
            var strings = args.Select(Marshal.StringToCoTaskMemUTF8).ToArray();
            var arguments = Marshal.AllocHGlobal(IntPtr.Size * strings.Length);
            try
            {
                Marshal.Copy(strings, 0, arguments, strings.Length);
                tu = clang_parseTranslationUnit(index, file, arguments, args.Length, IntPtr.Zero, 0, 1);
            }
            finally
            {
                Marshal.FreeHGlobal(arguments);
                foreach (var value in strings) Marshal.FreeCoTaskMem(value);
            }
            if (tu == IntPtr.Zero) throw new InvalidOperationException("libclang parse failed: " + file);
            var diagnostics = new List<object>();
            bool errors = false;
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
            var roots = new List<Cursor>();
            var declarations = new List<Cursor>();
            var macroExpansions = new List<Cursor>();
            var pending = new Queue<Cursor>(Children(clang_getTranslationUnitCursor(tu)));
            while (pending.Count != 0)
            {
                var cursor = pending.Dequeue();
                if (cursor.Kind == 502)
                {
                    var source = (string)Source(cursor)["file"];
                    if (source.Length != 0 && string.Equals(Path.GetFullPath(source), Path.GetFullPath(header), StringComparison.OrdinalIgnoreCase))
                        macroExpansions.Add(cursor);
                }
                else if (cursor.Kind == 22 || cursor.Kind == 23 || cursor.Kind == 1 || cursor.Kind == 300)
                {
                    foreach (var child in Children(cursor)) pending.Enqueue(child);
                }
                else if (new uint[] { 2, 3, 5, 8, 9, 20 }.Contains(cursor.Kind))
                {
                    declarations.Add(cursor);
                    var source = (string)Source(cursor)["file"];
                    if (source.Length != 0 && string.Equals(Path.GetFullPath(source), Path.GetFullPath(header), StringComparison.OrdinalIgnoreCase))
                        roots.Add(cursor);
                }
            }
            var seen = new HashSet<string>(roots.Select(Identity), StringComparer.Ordinal);
            var dependencies = new List<Cursor>();
            var dependencyTarget = dependencies;
            var work = new Queue<Cursor>(roots);
            Action<NativeType> addType = null;
            addType = type => {
                if (type.Kind == 0) return;
                var declaration = clang_getTypeDeclaration(type);
                if (new uint[] { 2, 3, 5, 20 }.Contains(declaration.Kind) && seen.Add(Identity(declaration)))
                {
                    dependencyTarget.Add(declaration);
                    work.Enqueue(declaration);
                }
                var pointer = clang_getPointeeType(type);
                if (pointer.Kind != 0) addType(pointer);
                var element = clang_getArrayElementType(type);
                if (element.Kind != 0) addType(element);
            };
            Action drain = () => {
                while (work.Count != 0)
                {
                    var cursor = work.Dequeue();
                    addType(clang_getCursorType(cursor));
                    if (cursor.Kind == 20) addType(clang_getTypedefDeclUnderlyingType(cursor));
                    if (cursor.Kind == 8)
                    {
                        addType(clang_getResultType(clang_getCursorType(cursor)));
                        for (int i = 0; i < clang_Cursor_getNumArguments(cursor); i++)
                            addType(clang_getCursorType(clang_Cursor_getArgument(cursor, (uint)i)));
                    }
                    if (cursor.Kind == 2 || cursor.Kind == 3)
                        foreach (var field in Children(cursor).Where(c => c.Kind == 6)) addType(clang_getCursorType(field));
                }
            };
            drain();
            var macroDependencies = new List<Cursor>();
            var macroBindings = new List<object>();
            foreach (var function in roots.Where(c => c.Kind == 8))
            {
                var functionSource = Source(function);
                var beginning = Source(clang_getRangeStart(clang_getCursorExtent(function)));
                var returnType = clang_getResultType(clang_getCursorType(function));
                var returnSpelling = Text(clang_getTypeSpelling(returnType));
                var returnCanonical = Text(clang_getTypeSpelling(clang_getCanonicalType(returnType)));
                foreach (var expansion in macroExpansions)
                {
                    var location = Source(expansion);
                    if (!Equals(location["file"], functionSource["file"]) ||
                        (uint)location["offset"] < (uint)beginning["offset"] ||
                        (uint)location["offset"] >= (uint)functionSource["offset"]) continue;
                    var definition = clang_getCursorReferenced(expansion);
                    if (definition.Kind != 501) continue;
                    var tokens = Tokens(tu, definition);
                    if (tokens.Length != 2 || tokens[1] != returnSpelling) continue;
                    var matches = declarations.Where(c => c.Kind == 20 &&
                        Text(clang_getCursorSpelling(c)) == tokens[0] &&
                        Text(clang_getTypeSpelling(clang_getCanonicalType(clang_getTypedefDeclUnderlyingType(c)))) == returnCanonical).ToArray();
                    if (matches.Length == 0) continue;
                    macroBindings.Add(new {
                        owner = Text(clang_getCursorSpelling(function)), use = "return",
                        expansion = location, macroDefinition = Source(definition), macroTokens = tokens,
                        nativeReturnType = TypeFacts(returnType), definitions = matches.Select(Facts).ToArray()
                    });
                    foreach (var match in matches)
                        if (seen.Add(Identity(match))) macroDependencies.Add(match);
                }
            }
            var annotationDependencies = new List<Cursor>();
            dependencyTarget = annotationDependencies;
            var bindings = new List<object>();
            Action<Cursor> scan = null;
            scan = cursor => {
                foreach (var child in Children(cursor))
                {
                    if (child.Kind == 406)
                    {
                        const string prefix = "win32metadata:associated_enum=";
                        var spelling = Text(clang_getCursorSpelling(child));
                        if (!spelling.StartsWith(prefix, StringComparison.Ordinal)) continue;
                        var target = spelling.Substring(prefix.Length);
                        var matches = declarations.Where(c => c.Kind == 5 && Text(clang_getCursorSpelling(c)) == target).ToArray();
                        bindings.Add(new { owner = Text(clang_getCursorSpelling(cursor)), source = Source(cursor),
                            target, definitions = matches.Select(c => Source(c)).ToArray() });
                        foreach (var match in matches)
                        {
                            if (seen.Add(Identity(match)))
                            {
                                annotationDependencies.Add(match);
                                work.Enqueue(match);
                            }
                        }
                    }
                    else if (child.Kind == 6 || child.Kind == 10) scan(child);
                }
            };
            foreach (var cursor in roots.Concat(dependencies)) scan(cursor);
            drain();
            var includedFiles = new HashSet<string>(StringComparer.OrdinalIgnoreCase);
            InclusionVisitor inclusion = (included, stack, length, data) => {
                includedFiles.Add(Text(clang_getFileName(included)).Replace('/', '\\'));
            };
            clang_getInclusions(tu, inclusion, IntPtr.Zero);
            GC.KeepAlive(inclusion);
            return new {
                compiler = Text(clang_getClangVersion()), file, header, arguments = args,
                hasErrors = errors, diagnostics, includedFiles = includedFiles.OrderBy(p => p, StringComparer.Ordinal).ToArray(),
                ownedDeclarations = roots.OrderBy(Identity, StringComparer.Ordinal).Select(Facts).ToArray(),
                dependencyDeclarations = dependencies.OrderBy(Identity, StringComparer.Ordinal).Select(Facts).ToArray(),
                annotationDependencyDeclarations = annotationDependencies.OrderBy(Identity, StringComparer.Ordinal).Select(Facts).ToArray(),
                macroDerivedDependencyDeclarations = macroDependencies.OrderBy(Identity, StringComparer.Ordinal).Select(Facts).ToArray(),
                macroTypedefSourceBindings = macroBindings,
                associatedEnumSourceBindings = bindings
            };
        }
        finally
        {
            if (tu != IntPtr.Zero) clang_disposeTranslationUnit(tu);
            clang_disposeIndex(index);
        }
    }
}
