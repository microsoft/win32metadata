using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
using Dia2Lib;

namespace VtablesFromPdb
{
    class Program
    {
        private enum BasicType
        {
            btNoType = 0,
            btVoid = 1,
            btChar = 2,
            btWChar = 3,
            btInt = 6,
            btUInt = 7,
            btFloat = 8,
            btBCD = 9,
            btBool = 10,
            btLong = 13,
            btULong = 14,
            btCurrency = 25,
            btDate = 26,
            btVariant = 27,
            btComplex = 28,
            btBit = 29,
            btBSTR = 30,
            btHresult = 31,
            btChar16 = 32,  // char16_t
            btChar32 = 33,  // char32_t
            btChar8 = 34,  // char8_t
        }

        static void Main(string[] args)
        {
            if (args.Length != 2)
            {
                Console.WriteLine("Expected: <pdb file name> <output json name>");
            }

            string pdbFileName = args[0];
            string jsonFileName = args[1];

            IDiaDataSource dia = new DiaSource();

            dia.loadDataFromPdb(pdbFileName);
            dia.openSession(out IDiaSession session);

            session.globalScope.findChildren(SymTagEnum.SymTagUDT, null, 0, out var symbols);

            List<InterfaceInfo> interfaceInfos = new List<InterfaceInfo>();

            foreach (IDiaSymbol type in symbols)
            {
                if (!type.name.StartsWith('I'))
                {
                    continue;
                }

                System.Diagnostics.Debug.WriteLine(type.name);

                List<string> functions = new List<string>();

                type.findChildren(SymTagEnum.SymTagNull, null, 0, out IDiaEnumSymbols members);
                foreach (IDiaSymbol member in members)
                {
                    var memberTag = (SymTagEnum)member.symTag;

                    if (memberTag == SymTagEnum.SymTagFunction && member.@virtual == 1)
                    {
                        StringBuilder methodText = new StringBuilder();

                        IDiaSymbol funcType = member.type;
                        IDiaSymbol returnType = funcType.type;

                        AppendType(returnType, methodText);

                        methodText.Append($" {member.name}(");
                        funcType.findChildren(SymTagEnum.SymTagNull, null, 0, out IDiaEnumSymbols parameters);

                        bool first = true;
                        foreach (IDiaSymbol p in parameters)
                        {
                            if (first)
                            {
                                first = false;
                            }
                            else
                            {
                                methodText.Append(", ");
                            }

                            AppendType(p.type, methodText);
                        }

                        methodText.Append(')');
                        functions.Add(methodText.ToString());
                    }
                }

                if (functions.Count != 0)
                {
                    InterfaceInfo info = new InterfaceInfo() { Name = type.name, Methods = functions.ToArray() };
                    interfaceInfos.Add(info);
                }
            }

            var interfacesText = Newtonsoft.Json.JsonConvert.SerializeObject(interfaceInfos, formatting: Newtonsoft.Json.Formatting.Indented);
            File.WriteAllText(jsonFileName, interfacesText);
        }

        private static readonly string[] baseTypes = new string[]
        {
          "<NoType>",                         // btNoType = 0,
          "void",                             // btVoid = 1,
          "Byte",                             // btChar = 2,
          "UShort",                          // btWChar = 3,
          "SByte",
          "Byte",
          "Int",                              // btInt = 6,
          "UInt",                     // btUInt = 7,
          "Single",                            // btFloat = 8,
          "<BCD>",                            // btBCD = 9,
          "bool",                             // btBool = 10,
          "Short",
          "UShort",
          "Int",                             // btLong = 13,
          "UInt",                    // btULong = 14,
          "SByte",
          "Short",
          "Int",
          "Long",
          "__int128",
          "Byte",
          "UShort",
          "UInt",
          "ULong",
          "unsigned __int128",
          "<currency>",                       // btCurrency = 25,
          "<date>",                           // btDate = 26,
          "VARIANT",                          // btVariant = 27,
          "<complex>",                        // btComplex = 28,
          "<bit>",                            // btBit = 29,
          "BSTR",                             // btBSTR = 30,
          "HRESULT",                          // btHresult = 31
          "UShort",                         // btChar16 = 32
          "char32_t",                          // btChar32 = 33
          "Byte",                          // btChar8  = 34
        };

        private static void AppendType(IDiaSymbol type, StringBuilder output)
        {
            SymTagEnum tag = (SymTagEnum)type.symTag;
            var length = type.length;

            switch (tag)
            {
                case SymTagEnum.SymTagUDT:
                case SymTagEnum.SymTagEnum:
                    {
                        var name = type.name;
                        if (name == "_GUID")
                        {
                            name = "Guid";
                        }

                        output.Append(name);
                        break;
                    }

                case SymTagEnum.SymTagPointerType:
                    {
                        var baseType = type.type;
                        AppendType(baseType, output);
                        output.Append('*');
                        break;
                    }

                case SymTagEnum.SymTagBaseType:
                    {
                        BasicType basicType = (BasicType)type.baseType;
                        switch (basicType)
                        {
                            case BasicType.btUInt:
                            case BasicType.btInt:
                                if (basicType == BasicType.btUInt)
                                {
                                    output.Append('U');
                                }

                                switch (length)
                                {
                                    case 1:
                                        output.Append("Byte");
                                        break;

                                    case 2:
                                        output.Append("Short");
                                        break;

                                    case 4:
                                        output.Append("Int");
                                        break;

                                    case 8:
                                        output.Append("Long");
                                        break;

                                    default:
                                        throw new NotSupportedException();
                                }

                                break;

                            case BasicType.btFloat:
                                switch (length)
                                {
                                    case 4:
                                        output.Append("Single");
                                        break;

                                    case 8:
                                        output.Append("Double");
                                        break;

                                    default:
                                        throw new NotSupportedException();
                                }

                                break;

                            default:
                                output.Append(baseTypes[(int)basicType]);
                                break;
                        }

                        break;
                    }

                default:
                    throw new NotSupportedException();
            }
        }

        private class InterfaceInfo
        {
            public string Name { get; set; }
            public string[] Methods { get; set; }
        }
    }


}
