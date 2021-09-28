using System.Collections.Generic;
using System.IO;
using ICSharpCode.Decompiler.TypeSystem;
using MetadataUtils;
using Xunit;

namespace Windows.Win32.Tests
{
    public class InterfaceTests
    {
        private DecompilerTypeSystem typeSystem;

        public InterfaceTests()
        {
            this.typeSystem = DecompilerUtils.LoadDecompilerTypeSystem(TestCommon.TestUtils.Win32WinmdPath);
        }

        [Theory]
        [MemberData(nameof(GetInterfaceData))]
        public void Interface_Layouts_Correct(InterfaceInfo info)
        {
            var winmdInterface = WinmdTestUtils.GetInterfaceInfo(this.typeSystem, info.Name);
            var jsonText = Newtonsoft.Json.JsonConvert.SerializeObject(winmdInterface, formatting: Newtonsoft.Json.Formatting.Indented);
            System.Diagnostics.Debug.WriteLine($"Read {info.Name} from winmd as:\n{jsonText}");

            Assert.Equal(info.Name, winmdInterface.Name);
            Assert.Equal(info.Methods.Length, winmdInterface.Methods.Length);

            for (int i = 0; i < winmdInterface.Methods.Length; i++)
            {
                Assert.Equal(info.Methods[i], winmdInterface.Methods[i]);
            }
        }

        public static IEnumerable<object[]> GetInterfaceData()
        {
            var jsonPath = TestCommon.TestUtils.GetAssetFile("InterfacesToVerify.json");
            var interfaceItems = Newtonsoft.Json.JsonConvert.DeserializeObject<InterfaceInfo[]>(File.ReadAllText(jsonPath));
            foreach (var item in interfaceItems)
            {
                yield return new object[] { item };
            }
        }
    }
}
