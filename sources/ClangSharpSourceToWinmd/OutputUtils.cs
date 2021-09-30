using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ClangSharpSourceToWinmd
{
    public static class OutputUtils
    {
        public static string FormatTimespan(TimeSpan timeSpan) => timeSpan.ToString(@"hh\:mm\:ss\.ff");
    }
}
