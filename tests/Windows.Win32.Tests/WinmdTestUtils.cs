using System.Collections.Generic;
using System.Linq;
using System.Text;
using ICSharpCode.Decompiler.TypeSystem;
using MetadataUtils;

namespace Windows.Win32.Tests
{
    public static class WinmdTestUtils
    {
        public static InterfaceInfo GetInterfaceInfo(DecompilerTypeSystem typeSystem, string typeName)
        {
            var type = DecompilerUtils.GetSelfDefinedWinmdToplevelTypes(typeSystem).Where(t => t.Kind == TypeKind.Interface && t.Name == typeName).Single();
            InterfaceInfo ret = new InterfaceInfo() { Name = type.Name };
            List<string> protoTypes = new List<string>();
            foreach (IMethod method in type.Methods)
            {
                protoTypes.Add(GetMethodPrototype(method));
            }

            ret.Methods = protoTypes.ToArray();

            return ret;
        }

        public static string GetMethodPrototype(IMethod method)
        {
            StringBuilder ret = new StringBuilder();
            ret.AppendFormat($"{method.ReturnType.Name} {method.Name}(");

            bool first = true;
            foreach (var p in method.Parameters)
            {
                if (!first)
                {
                    ret.Append(", ");
                }
                else
                {
                    first = false;
                }

                ret.Append(p.Type.Name);
            }

            ret.Append(')');

            return ret.ToString();
        }
    }
}
