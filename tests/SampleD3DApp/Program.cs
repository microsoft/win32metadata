using System;
using System.Linq;
using static Microsoft.Windows.Win32.Apis;

namespace SampleD3DApp
{
    class Program
    {
        internal static bool Matches(string arg, params string[] keywords)
        {
            return keywords.Any((keyword) => ((arg.Length == keyword.Length) && arg.Equals(keyword, StringComparison.OrdinalIgnoreCase))
                                          || (((arg.Length - 1) == keyword.Length) && ((arg[0] == '-') || (arg[0] == '/')) && (string.Compare(arg, 1, keyword, 0, keyword.Length, StringComparison.OrdinalIgnoreCase) == 0)));
        }

        static void Main(string[] args)
        {
            //HelloWindow12 sample = new HelloWindow12(800, 600, "Hello World Sample");
            HelloTriangle12 sample = new HelloTriangle12(800, 600, "Hello Triangle Sample");
            Win32Application.Run(sample, SW_SHOWDEFAULT);
        }
    }
}
