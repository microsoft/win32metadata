using System;
using System.Collections.Generic;
using System.IO;
using System.Reflection.PortableExecutable;
using System.Text;

namespace MetadataUtils
{
    public static class DllExports
    {
        /// <summary>
        /// Gets the names a DLL exports by name (the export name table). Ordinal-only (NONAME) exports are not included.
        /// </summary>
        public static HashSet<string> GetNamedExports(string dllPath)
        {
            var names = new HashSet<string>(StringComparer.Ordinal);

            byte[] image = File.ReadAllBytes(dllPath);
            using var stream = new MemoryStream(image);
            using var pe = new PEReader(stream);
            PEHeader header = pe.PEHeaders.PEHeader;
            if (header == null || header.ExportTableDirectory.Size == 0)
            {
                return names;
            }

            int exportDir = RvaToOffset(pe.PEHeaders, header.ExportTableDirectory.RelativeVirtualAddress);
            int numberOfNames = BitConverter.ToInt32(image, exportDir + 24);
            if (numberOfNames == 0)
            {
                return names;
            }

            int namesTable = RvaToOffset(pe.PEHeaders, BitConverter.ToInt32(image, exportDir + 32));

            for (int i = 0; i < numberOfNames; i++)
            {
                int nameOffset = RvaToOffset(pe.PEHeaders, BitConverter.ToInt32(image, namesTable + (i * 4)));
                int end = nameOffset;
                while (image[end] != 0)
                {
                    end++;
                }

                names.Add(Encoding.ASCII.GetString(image, nameOffset, end - nameOffset));
            }

            return names;
        }

        /// <summary>
        /// Gets the populated export ordinals that have no name in the DLL's export table.
        /// </summary>
        public static HashSet<ushort> GetOrdinalOnlyExports(string dllPath)
        {
            var ordinals = new HashSet<ushort>();
            byte[] image = File.ReadAllBytes(dllPath);
            using var stream = new MemoryStream(image);
            using var pe = new PEReader(stream);
            PEHeader header = pe.PEHeaders.PEHeader;
            if (header == null || header.ExportTableDirectory.Size == 0)
            {
                return ordinals;
            }

            int exportDir = RvaToOffset(pe.PEHeaders, header.ExportTableDirectory.RelativeVirtualAddress);
            uint ordinalBase = BitConverter.ToUInt32(image, exportDir + 16);
            int numberOfFunctions = BitConverter.ToInt32(image, exportDir + 20);
            int numberOfNames = BitConverter.ToInt32(image, exportDir + 24);
            if (numberOfFunctions == 0)
            {
                return ordinals;
            }

            int functionsTable = RvaToOffset(pe.PEHeaders, BitConverter.ToInt32(image, exportDir + 28));
            var namedIndexes = new HashSet<ushort>();
            if (numberOfNames != 0)
            {
                int nameOrdinalsTable = RvaToOffset(pe.PEHeaders, BitConverter.ToInt32(image, exportDir + 36));
                for (int i = 0; i < numberOfNames; i++)
                {
                    namedIndexes.Add(BitConverter.ToUInt16(image, nameOrdinalsTable + (i * 2)));
                }
            }

            for (int i = 0; i < numberOfFunctions && ordinalBase + (uint)i <= ushort.MaxValue; i++)
            {
                if (!namedIndexes.Contains((ushort)i) && BitConverter.ToInt32(image, functionsTable + (i * 4)) != 0)
                {
                    ordinals.Add((ushort)(ordinalBase + (uint)i));
                }
            }

            return ordinals;
        }

        private static int RvaToOffset(PEHeaders headers, int rva)
        {
            foreach (SectionHeader section in headers.SectionHeaders)
            {
                if (rva >= section.VirtualAddress && rva < section.VirtualAddress + Math.Max(section.VirtualSize, section.SizeOfRawData))
                {
                    return rva - section.VirtualAddress + section.PointerToRawData;
                }
            }

            throw new InvalidDataException($"RVA 0x{rva:x} is not within any section.");
        }
    }
}
