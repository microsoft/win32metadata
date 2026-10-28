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
