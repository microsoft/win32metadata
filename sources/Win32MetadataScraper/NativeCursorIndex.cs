using System;
using System.Collections.Generic;
using ClangSharp;
using ClangSharp.Interop;
using MetadataUtils;

namespace Win32MetadataScraper
{
    internal sealed class NativeCursorIndex
    {
        private readonly Dictionary<CXCursor, CXCursor> parents = new();
        private readonly Dictionary<CXCursor, Cursor> resolved = new();

        internal unsafe NativeCursorIndex(Decl root, Func<CXCursor, bool> include = null, bool reverseTraversal = true)
        {
            using var timing = GenerationTiming.BeginSpan("native-declarations.index");
            var cursors = new List<CXCursor>();
            var pending = new Stack<(CXCursor Cursor, CXCursor Parent)>();
            pending.Push((root.Handle, default));
            resolved.Add(root.Handle, root);
            while (pending.TryPop(out var item))
            {
                if (!parents.TryAdd(item.Cursor, item.Parent))
                    continue;
                cursors.Add(item.Cursor);
                var children = new List<CXCursor>();
                item.Cursor.VisitChildren((child, _, _) =>
                {
                    if (include?.Invoke(child) ?? child.IsDeclaration)
                        children.Add(child);
                    return CXChildVisitResult.CXChildVisit_Continue;
                }, default);
                if (!reverseTraversal)
                    children.Reverse();
                foreach (var child in children)
                    pending.Push((child, item.Cursor));
            }
            Cursors = cursors.ToArray();
            timing?.SetCounter("cursorCount", Cursors.Count);
        }

        internal IReadOnlyList<CXCursor> Cursors { get; }

        internal Cursor GetCursor(CXCursor cursor)
        {
            if (!parents.ContainsKey(cursor))
                throw new ArgumentException("The cursor is outside this native traversal.", nameof(cursor));
            var path = new Stack<CXCursor>();
            var current = cursor;
            while (!resolved.ContainsKey(current))
            {
                path.Push(current);
                current = parents[current];
            }
            var result = resolved[current];
            while (path.TryPop(out var next))
            {
                if (!resolved.TryGetValue(next, out var child))
                {
                    foreach (var candidate in result.CursorChildren)
                        resolved.TryAdd(candidate.Handle, candidate);
                    if (!resolved.TryGetValue(next, out child))
                        throw new InvalidOperationException("A native cursor is missing from its recorded parent's children.");
                }
                result = child;
            }
            return result;
        }
    }
}
