using System;
using System.Linq;
using ClangSharpSourceToWinmd;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace ClangSharpSourceToWinmdTests
{
    [TestClass]
    public class ShadowedTypeNameQualifierTests
    {
        [TestMethod]
        public void QualifyShadowedTypeNames_TypeNamedAfterNamespace_IsReferenceableFromOtherNamespace()
        {
            CSharpCompilation compilation = CreateCompilation(@"
using System;
using Test.Public;

namespace Test.Public
{
    public partial struct Windows
    {
        public int Count;
    }
}

namespace Windows.Win32.Foundation
{
    public partial struct HWND
    {
        public IntPtr Value;
    }
}

namespace Test.Internal
{
    public unsafe partial struct Shell
    {
        public Windows* ActiveWindow;

        public Windows[] AllWindows;

        public Windows.Win32.Foundation.HWND Handle;

        public static Windows* GetWindows(Windows** windows, delegate* unmanaged<Windows*, int> callback) => null;
    }
}");

            Assert.AreEqual("CS0118", GetErrors(compilation).Select(error => error.Id).FirstOrDefault());

            compilation = ShadowedTypeNameQualifier.QualifyShadowedTypeNames(compilation);

            Diagnostic[] errors = GetErrors(compilation);
            Assert.AreEqual(0, errors.Length, string.Join(Environment.NewLine, errors.Select(error => error.ToString())));
        }

        [TestMethod]
        public void QualifyShadowedTypeNames_LeavesNamespaceReferencesAlone()
        {
            const string Source = @"
using System;
using Test.Public;
using Windows.Win32.Foundation;

namespace Test.Public
{
    public partial struct Windows
    {
        public int Count;
    }
}

namespace Windows.Win32.Foundation
{
    public partial struct HWND
    {
        public IntPtr Value;
    }
}

namespace Test.Internal
{
    public partial struct Shell
    {
        public Windows.Win32.Foundation.HWND Handle;

        public HWND OtherHandle;
    }
}";

            CSharpCompilation compilation = CreateCompilation(Source);

            Assert.AreEqual(0, GetErrors(compilation).Length);

            compilation = ShadowedTypeNameQualifier.QualifyShadowedTypeNames(compilation);

            Assert.AreEqual(Source, compilation.SyntaxTrees.Single().ToString());
        }

        [TestMethod]
        public void QualifyShadowedTypeNames_AmbiguousShadowedNameIsLeftAlone()
        {
            const string Source = @"
using System;

namespace Test.Public
{
    public partial struct Windows
    {
        public int Count;
    }
}

namespace Test.Internal
{
    public partial struct Windows
    {
        public int Count;
    }
}

namespace Windows.Win32.Foundation
{
    public partial struct HWND
    {
        public IntPtr Value;
    }
}";

            CSharpCompilation compilation = CreateCompilation(Source);

            compilation = ShadowedTypeNameQualifier.QualifyShadowedTypeNames(compilation);

            Assert.AreEqual(Source, compilation.SyntaxTrees.Single().ToString());
        }

        private static CSharpCompilation CreateCompilation(string source)
        {
            return CSharpCompilation.Create(
                "ShadowedTypeNameTest",
                new[] { CSharpSyntaxTree.ParseText(source) },
                new[] { MetadataReference.CreateFromFile(typeof(object).Assembly.Location) },
                new CSharpCompilationOptions(OutputKind.DynamicallyLinkedLibrary, allowUnsafe: true));
        }

        private static Diagnostic[] GetErrors(CSharpCompilation compilation)
        {
            return compilation.GetDiagnostics()
                .Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error)
                .ToArray();
        }
    }
}
