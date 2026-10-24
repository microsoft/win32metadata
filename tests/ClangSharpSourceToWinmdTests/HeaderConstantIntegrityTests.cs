using System;
using System.Collections.Generic;
using System.CommandLine.IO;
using System.Linq;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace ClangSharpSourceToWinmdTests
{
    public partial class HeaderConstantCrossArchTests
    {
        [TestMethod]
        public void IntegrityAcceptsDisjointArchitectureVariantsOfOneConstant()
        {
            Emit(Architectures.ToDictionary(architecture => architecture, architecture =>
                Source("public const uint EXTRA=" + (architecture == "x86" ? "1" : "2") + "U;")),
                fields => Assert.AreEqual(2, fields.Length), inspectImage: image =>
                {
                    var console = new TestConsole();
                    Assert.AreEqual(0, WinmdUtilsProgram.Program.ShowDuplicateConstants(image, Array.Empty<string>(), console),
                        console.Out.ToString());
                });
        }

        [DataTestMethod]
        [DataRow(false, false)]
        [DataRow(false, true)]
        [DataRow(true, false)]
        [DataRow(true, true)]
        public void IntegrityChecksDifferentConstantOwnersOrSpellingsOnOverlappingArchitectures(bool differentOwner, bool overlappingArchitectures)
        {
            string otherArchitecture = overlappingArchitectures ? "X86" : "Arm64";
            string declarations = differentOwner
                ? Source("[SupportedArchitecture(Architecture.X86)] public const uint EXTRA=1U;", "First") +
                    Source("[SupportedArchitecture(Architecture." + otherArchitecture + ")] public const uint EXTRA=2U;", "Second")
                : Source("[SupportedArchitecture(Architecture.X86)] public const uint EXTRA=1U;" +
                    "[SupportedArchitecture(Architecture." + otherArchitecture + ")] public const uint extra=2U;");
            Emit(new Dictionary<string, string> { ["common.cs"] = declarations }, _ => { }, inspectImage: image =>
            {
                var console = new TestConsole();
                Assert.AreEqual(overlappingArchitectures ? -1 : 0,
                    WinmdUtilsProgram.Program.ShowDuplicateConstants(image, Array.Empty<string>(), console),
                    console.Out.ToString());
                if (overlappingArchitectures)
                    StringAssert.Contains(console.Out.ToString(), "EXTRA");
            });
        }

        [TestMethod]
        public void IntegrityFollowsTheMatchingArchitectureOfAReferencedRecord()
        {
            Emit(new Dictionary<string, string>
            {
                ["x86"] = Source(""),
                ["x64"] = @"namespace Test
                {
                    public partial struct Value { public X64Only X64Native; }
                    public struct X64Only { public int Number; }
                    public struct Consumer { public Value Native; }
                }",
                ["arm64"] = @"namespace Test
                {
                    public partial struct Value { public Arm64Only Arm64Native; }
                    public struct Arm64Only { public int Number; }
                    public struct Consumer { public Value Native; }
                }",
            }, _ => { }, inspectImage: image =>
            {
                var console = new TestConsole();
                Assert.AreEqual(0, WinmdUtilsProgram.Program.ShowBrokenArchTypes(image, console), console.Out.ToString());
            });
        }

        [TestMethod]
        public void IntegrityRejectsAnUnavailableNestedArchitectureType()
        {
            Emit(new Dictionary<string, string>
            {
                ["common.cs"] = @"namespace Test
                {
                    [SupportedArchitecture(Architecture.X64)] public struct X64Only { public int Number; }
                    [SupportedArchitecture(Architecture.Arm64)] public struct Value { public X64Only Native; }
                    [SupportedArchitecture(Architecture.Arm64)] public struct Consumer { public Value Native; }
                }",
            }, _ => { }, inspectImage: image =>
            {
                var console = new TestConsole();
                Assert.AreEqual(-1, WinmdUtilsProgram.Program.ShowBrokenArchTypes(image, console), console.Out.ToString());
                StringAssert.Contains(console.Out.ToString(), "Test.X64Only");
            });
        }

        [DataTestMethod]
        [DataRow(false)]
        [DataRow(true)]
        public void IntegrityRejectsUnavailableMethodParameterAndReturnTypes(bool returnType)
        {
            string method = returnType ? "X64Only Method()" : "void Method(X64Only value)";
            Emit(new Dictionary<string, string>
            {
                ["common.cs"] = @"using System.Runtime.InteropServices;
                using Architecture = Windows.Win32.Foundation.Metadata.Architecture;
                namespace Test
                {
                    [SupportedArchitecture(Architecture.X64)] public struct X64Only { public int Number; }
                    public static class Apis
                    {
                        [DllImport(""fixture.dll"")]
                        [SupportedArchitecture(Architecture.Arm64)] public static extern " + method + @";
                    }
                }",
            }, _ => { }, inspectImage: image =>
            {
                var console = new TestConsole();
                Assert.AreEqual(-1, WinmdUtilsProgram.Program.ShowBrokenArchTypes(image, console), console.Out.ToString());
                StringAssert.Contains(console.Out.ToString(), "Test.Apis.Method");
                StringAssert.Contains(console.Out.ToString(), "Test.X64Only");
            });
        }

        [TestMethod]
        public void IntegrityRejectsAnUnavailableDelegateReturnType()
        {
            Emit(new Dictionary<string, string>
            {
                ["common.cs"] = @"namespace Test
                {
                    [SupportedArchitecture(Architecture.X64)] public struct X64Only { public int Number; }
                    [SupportedArchitecture(Architecture.Arm64)] public delegate X64Only Callback();
                }",
            }, _ => { }, inspectImage: image =>
            {
                var console = new TestConsole();
                Assert.AreEqual(-1, WinmdUtilsProgram.Program.ShowBrokenArchTypes(image, console), console.Out.ToString());
                StringAssert.Contains(console.Out.ToString(), "Test.X64Only");
            });
        }

        [TestMethod]
        public void IntegrityTerminatesForRecursiveDelegateSignatures()
        {
            Emit(new Dictionary<string, string>
            {
                ["common.cs"] = @"namespace Test
                {
                    [SupportedArchitecture(Architecture.Arm64)] public delegate Callback Callback(Callback next);
                }",
            }, _ => { }, inspectImage: image =>
            {
                var console = new TestConsole();
                Assert.AreEqual(0, WinmdUtilsProgram.Program.ShowBrokenArchTypes(image, console), console.Out.ToString());
            });
        }
    }
}
