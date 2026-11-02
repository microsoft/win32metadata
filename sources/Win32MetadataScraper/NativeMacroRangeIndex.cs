using System;
using System.Collections.Generic;
using System.Linq;

namespace Win32MetadataScraper
{
    internal sealed class NativeMacroRangeIndex
    {
        private readonly (string File, uint Start, uint End)[] ranges;
        private readonly int[] ordered;
        private readonly uint[] maximumEnds;

        internal NativeMacroRangeIndex(IEnumerable<(string File, uint Start, uint End)> ranges)
        {
            this.ranges = ranges.ToArray();
            ordered = Enumerable.Range(0, this.ranges.Length).OrderBy(index => this.ranges[index].Start).ToArray();
            maximumEnds = new uint[ordered.Length];
            Build(0, ordered.Length);
        }

        internal (int Start, int End) FindEnclosing(
            (string File, uint Offset) originalStart, (string File, uint Offset) originalEnd,
            uint attributeStart, uint attributeEnd)
        {
            int start = -1, end = -1;
            Visit(0, ordered.Length, originalStart, extendStart: true);
            Visit(0, ordered.Length, originalEnd, extendStart: false);
            return (start, end);

            void Visit(int first, int last, (string File, uint Offset) point, bool extendStart)
            {
                if (first == last)
                    return;
                int middle = first + ((last - first) / 2);
                if (maximumEnds[middle] <= point.Offset)
                    return;
                Visit(first, middle, point, extendStart);
                int index = ordered[middle];
                var range = ranges[index];
                if (range.Start > point.Offset)
                    return;
                if (range.End > point.Offset &&
                    range.Start >= attributeStart && range.End <= attributeEnd &&
                    (range.Start > attributeStart || range.End < attributeEnd) &&
                    string.Equals(range.File, point.File, StringComparison.OrdinalIgnoreCase))
                {
                    if (extendStart && range.Start < originalStart.Offset &&
                        (start < 0 || range.Start < ranges[start].Start ||
                            (range.Start == ranges[start].Start && index < start)))
                        start = index;
                    if (!extendStart &&
                        (end < 0 || range.End > ranges[end].End ||
                            (range.End == ranges[end].End && index < end)))
                        end = index;
                }
                Visit(middle + 1, last, point, extendStart);
            }
        }

        private uint Build(int first, int last)
        {
            if (first == last)
                return 0;
            int middle = first + ((last - first) / 2);
            return maximumEnds[middle] = Math.Max(ranges[ordered[middle]].End,
                Math.Max(Build(first, middle), Build(middle + 1, last)));
        }
    }
}
