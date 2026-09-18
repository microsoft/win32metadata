using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;

public static class ComProjectionNativeProbe
{
    [StructLayout(LayoutKind.Sequential)] private struct Cursor { public uint Kind; public int XData; public IntPtr Data0, Data1, Data2; }
    [StructLayout(LayoutKind.Sequential)] private struct NativeType { public uint Kind; public IntPtr Data0, Data1; }
    [StructLayout(LayoutKind.Sequential)] private struct NativeString { public IntPtr Data; public uint Flags; }
    [StructLayout(LayoutKind.Sequential)] private struct Location { public IntPtr Data0, Data1; public uint Data2; }
    [StructLayout(LayoutKind.Sequential)] private struct Range { public IntPtr Data0, Data1; public uint Begin, End; }
    [UnmanagedFunctionPointer(CallingConvention.Cdecl)] private delegate uint Visitor(Cursor cursor, Cursor parent, IntPtr data);
    private const string Library = "libclang.dll";
    private static string loadedLibrary;
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern IntPtr clang_createIndex(int exclude, int diagnostics);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern void clang_disposeIndex(IntPtr index);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern IntPtr clang_parseTranslationUnit(IntPtr index, [MarshalAs(UnmanagedType.LPUTF8Str)] string file, IntPtr args, int count, IntPtr unsaved, uint unsavedCount, uint flags);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern void clang_disposeTranslationUnit(IntPtr tu);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern Cursor clang_getTranslationUnitCursor(IntPtr tu);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern uint clang_visitChildren(Cursor cursor, Visitor visitor, IntPtr data);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern NativeString clang_getCursorSpelling(Cursor cursor);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern NativeString clang_getCursorUSR(Cursor cursor);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern uint clang_isCursorDefinition(Cursor cursor);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern Location clang_getCursorLocation(Cursor cursor);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern Range clang_getCursorExtent(Cursor cursor);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern Location clang_getRangeStart(Range range);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern Location clang_getRangeEnd(Range range);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern void clang_getExpansionLocation(Location location, out IntPtr file, out uint line, out uint column, out uint offset);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern NativeString clang_getFileName(IntPtr file);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern NativeType clang_getCursorType(Cursor cursor);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern NativeType clang_getCanonicalType(NativeType type);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern NativeString clang_getTypeSpelling(NativeType type);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern NativeString clang_getTypeKindSpelling(uint kind);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern long clang_Type_getSizeOf(NativeType type);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern long clang_Type_getAlignOf(NativeType type);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern NativeType clang_getPointeeType(NativeType type);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern NativeType clang_getResultType(NativeType type);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern uint clang_getFunctionTypeCallingConv(NativeType type);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern uint clang_isFunctionTypeVariadic(NativeType type);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern int clang_getNumArgTypes(NativeType type);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern NativeType clang_getArgType(NativeType type, uint index);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern uint clang_CXXMethod_isVirtual(Cursor cursor);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern uint clang_CXXMethod_isPureVirtual(Cursor cursor);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern uint clang_CXXMethod_isStatic(Cursor cursor);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern uint clang_CXXMethod_isConst(Cursor cursor);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern uint clang_getCXXAccessSpecifier(Cursor cursor);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern long clang_Cursor_getOffsetOfField(Cursor cursor);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern uint clang_getNumDiagnostics(IntPtr tu);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern IntPtr clang_getDiagnostic(IntPtr tu, uint index);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern uint clang_getDiagnosticSeverity(IntPtr diagnostic);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern NativeString clang_formatDiagnostic(IntPtr diagnostic, uint options);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern void clang_disposeDiagnostic(IntPtr diagnostic);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern IntPtr clang_getCString(NativeString value);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern void clang_disposeString(NativeString value);
    [DllImport(Library, CallingConvention = CallingConvention.Cdecl)] private static extern NativeString clang_getClangVersion();

    private static string Text(NativeString value)
    {
        try { return Marshal.PtrToStringUTF8(clang_getCString(value)) ?? ""; }
        finally { clang_disposeString(value); }
    }
    private static List<Cursor> Children(Cursor cursor)
    {
        var children = new List<Cursor>();
        Visitor visitor = (child, parent, data) => { children.Add(child); return 1; };
        clang_visitChildren(cursor, visitor, IntPtr.Zero);
        GC.KeepAlive(visitor);
        return children;
    }
    private static IEnumerable<Cursor> Declarations(Cursor cursor)
    {
        foreach (var child in Children(cursor))
        {
            yield return child;
            if (child.Kind == 1 || child.Kind == 22 || child.Kind == 23)
                foreach (var nested in Declarations(child)) yield return nested;
        }
    }
    private static Dictionary<string, object> Source(Location location)
    {
        clang_getExpansionLocation(location, out var file, out var line, out var column, out var offset);
        return new Dictionary<string, object> { ["file"] = file == IntPtr.Zero ? "" : Text(clang_getFileName(file)).Replace('/', '\\'),
            ["line"] = line, ["column"] = column, ["offset"] = offset };
    }
    private static Dictionary<string, object> Type(NativeType type)
    {
        var canonical = clang_getCanonicalType(type);
        return new Dictionary<string, object> { ["spelling"] = Text(clang_getTypeSpelling(type)),
            ["canonical"] = Text(clang_getTypeSpelling(canonical)), ["kind"] = Text(clang_getTypeKindSpelling(canonical.Kind)),
            ["size"] = clang_Type_getSizeOf(type), ["alignment"] = clang_Type_getAlignOf(type) };
    }
    private static Dictionary<string, object> Facts(Cursor cursor)
    {
        var type = clang_getCursorType(cursor);
        var extent = clang_getCursorExtent(cursor);
        var children = Children(cursor);
        var facts = new Dictionary<string, object> { ["name"] = Text(clang_getCursorSpelling(cursor)),
            ["usr"] = Text(clang_getCursorUSR(cursor)), ["source"] = Source(clang_getCursorLocation(cursor)),
            ["extentStart"] = Source(clang_getRangeStart(extent)), ["extentEnd"] = Source(clang_getRangeEnd(extent)),
            ["type"] = Type(type) };
        if (cursor.Kind == 21 || cursor.Kind == 6)
        {
            var function = cursor.Kind == 6 ? clang_getPointeeType(clang_getCanonicalType(type)) : type;
            int count = clang_getNumArgTypes(function);
            if (count >= 0)
            {
                facts["returnType"] = Type(clang_getResultType(function));
                facts["callingConvention"] = clang_getFunctionTypeCallingConv(function);
                facts["variadic"] = clang_isFunctionTypeVariadic(function) != 0;
                facts["parameterTypes"] = Enumerable.Range(0, count).Select(i => Type(clang_getArgType(function, (uint)i))).ToArray();
                facts["parameters"] = children.Where(c => c.Kind == 10).Select(Facts).ToArray();
            }
        }
        if (cursor.Kind == 21)
        {
            facts["virtual"] = clang_CXXMethod_isVirtual(cursor) != 0;
            facts["pure"] = clang_CXXMethod_isPureVirtual(cursor) != 0;
            facts["static"] = clang_CXXMethod_isStatic(cursor) != 0;
            facts["const"] = clang_CXXMethod_isConst(cursor) != 0;
            facts["access"] = clang_getCXXAccessSpecifier(cursor);
        }
        if (cursor.Kind == 6) facts["offsetBits"] = clang_Cursor_getOffsetOfField(cursor);
        if (cursor.Kind == 2 || cursor.Kind == 4)
        {
            facts["bases"] = children.Where(c => c.Kind == 44).Select(Facts).ToArray();
            facts["methods"] = children.Where(c => c.Kind == 21).Select(Facts).ToArray();
            facts["fields"] = children.Where(c => c.Kind == 6).Select(Facts).ToArray();
        }
        return facts;
    }
    public static object Capture(string library, string file, string[] arguments, string[] names)
    {
        library = Path.GetFullPath(library);
        if (loadedLibrary == null)
        {
            NativeLibrary.SetDllImportResolver(typeof(ComProjectionNativeProbe).Assembly,
                (name, assembly, searchPath) => name == Library ? NativeLibrary.Load(library) : IntPtr.Zero);
            loadedLibrary = library;
        }
        else if (!string.Equals(library, loadedLibrary, StringComparison.OrdinalIgnoreCase))
            throw new InvalidOperationException("Cannot change libclang within the same process.");
        var index = clang_createIndex(0, 0);
        if (index == IntPtr.Zero) throw new InvalidOperationException("Index creation failed.");
        IntPtr tu = IntPtr.Zero;
        var strings = arguments.Select(Marshal.StringToCoTaskMemUTF8).ToArray();
        var argv = Marshal.AllocHGlobal(IntPtr.Size * strings.Length);
        try
        {
            Marshal.Copy(strings, 0, argv, strings.Length);
            tu = clang_parseTranslationUnit(index, file, argv, strings.Length, IntPtr.Zero, 0, 0);
            if (tu == IntPtr.Zero) throw new InvalidOperationException("Native-only COM parse failed.");
            var diagnostics = new List<object>();
            bool errors = false;
            for (uint i = 0; i < clang_getNumDiagnostics(tu); i++)
            {
                var diagnostic = clang_getDiagnostic(tu, i);
                try
                {
                    uint severity = clang_getDiagnosticSeverity(diagnostic);
                    errors |= severity >= 3;
                    diagnostics.Add(new { severity, text = Text(clang_formatDiagnostic(diagnostic, 0)) });
                }
                finally { clang_disposeDiagnostic(diagnostic); }
            }
            var selected = new HashSet<string>(names, StringComparer.Ordinal);
            var declarations = Declarations(clang_getTranslationUnitCursor(tu))
                .Where(c => (c.Kind == 2 || c.Kind == 4) && clang_isCursorDefinition(c) != 0 && selected.Contains(Text(clang_getCursorSpelling(c))))
                .Select(Facts).ToArray();
            return new Dictionary<string, object> { ["schema"] = "native-com-context/v1", ["compiler"] = Text(clang_getClangVersion()),
                ["file"] = file, ["arguments"] = arguments, ["selectedNames"] = names, ["hasErrors"] = errors,
                ["diagnostics"] = diagnostics.ToArray(), ["declarations"] = declarations };
        }
        finally
        {
            if (tu != IntPtr.Zero) clang_disposeTranslationUnit(tu);
            clang_disposeIndex(index);
            Marshal.FreeHGlobal(argv);
            foreach (var value in strings) Marshal.FreeCoTaskMem(value);
        }
    }
}
