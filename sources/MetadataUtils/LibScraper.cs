using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;

namespace MetadataUtils
{
    public class ImportInfo
    {
        public ImportInfo(string dll, string procName)
        {
            this.Dll = dll;
            this.ProcName = procName;
        }

        public string Dll { get; }
        public string ProcName { get; }

        public override bool Equals(object obj)
        {
            if (obj is ImportInfo other)
            {
                return this.Dll == other.Dll && this.ProcName == other.ProcName;
            }

            return false;
        }

        public override string ToString()
        {
            return $"{this.ProcName}={this.Dll}";
        }

        public override int GetHashCode()
        {
            return this.ToString().GetHashCode(StringComparison.OrdinalIgnoreCase);
        }
    }

    public static class LibScraper
    {
        private static readonly byte[] expectedLibHeader = ASCIIEncoding.ASCII.GetBytes("!<arch>\n");

        public static IEnumerable<ImportInfo> GetImportInfos(string libPath)
        {
            using FileStream libStream = new FileStream(libPath, FileMode.Open, FileAccess.Read);
            using BinaryReader libReader = new BinaryReader(libStream);

            byte[] libHeader = libReader.ReadBytes(expectedLibHeader.Length);
            if (!libHeader.SequenceEqual(expectedLibHeader))
            {
                throw new InvalidOperationException($"{libPath} is not a valid .lib.");
            }

            long nextArchPos = libStream.Position;
            
            while (libStream.Position != libStream.Length)
            {
                libStream.Position = nextArchPos;

                // Make sure it starts on an even boundary
                if ((libStream.Position % 2) == 1)
                {
                    libStream.Position += 1;
                }

                byte[] headerBytes = libReader.ReadBytes(Marshal.SizeOf(typeof(ArchiveHeader)));
                ArchiveHeader header = GetStructFromBytes<ArchiveHeader>(headerBytes);
                if (!header.IsValid)
                {
                    yield break;
                }

                nextArchPos = libStream.Position + header.ArchiveSize;

                string name = header.Name;

                // We don't need these archives
                if (name == "/" || name == "//")
                {
                    continue;
                }

                if (header.ArchiveSize < Marshal.SizeOf(typeof(ImportHeader)))
                {
                    continue;
                }

                byte[] importHeaderBytes = libReader.ReadBytes(Marshal.SizeOf(typeof(ImportHeader)));
                ImportHeader importHeader = GetStructFromBytes<ImportHeader>(importHeaderBytes);

                // Is this really an import header?
                if (importHeader.sig1 != 0 || importHeader.sig2 != 0xFFFF)
                {
                    continue;
                }

                // Make sure it's a code import
                if (importHeader.ImportType != ImportType.Code)
                {
                    continue;
                }

                string symbolName = ReadNullTermString(libReader);
                string dllName = ReadNullTermString(libReader);
                string procName = symbolName;

                // If it's x86, try to undecorate it
                if (importHeader.MachineType == MachineType.X86)
                {
                    if (procName.StartsWith('_'))
                    {
                        procName = procName.Substring(1);

                        int atIndex = procName.IndexOf('@');
                        if (atIndex != -1)
                        {
                            procName = procName.Substring(0, atIndex);
                        }
                    }
                }

                yield return new ImportInfo(dllName, procName);
            }
        }

        private enum ImportType
        {
            Code,
            Data,
            Const
        }

        private enum MachineType : ushort
        {
            X86 = 0x014c,
            X64 = 0x8664,
            Arm64 = 0xAA64
        }

        private enum NameType
        {
            Ordinal,
            Name,
            NoPrefix,
            Undecorate
        }

        private static string ReadNullTermString(BinaryReader reader)
        {
            StringBuilder ret = new StringBuilder();

            char current;
            while ((current = (char)reader.ReadByte()) != 0)
            {
                ret.Append(current);
            }

            return ret.ToString();
        }

        [StructLayout(LayoutKind.Sequential, Pack = 1, CharSet = CharSet.Ansi)]
        private unsafe struct ImportHeader
        {
            public ushort sig1;
            public ushort sig2;
            public ushort version;
            public ushort machine;
            public uint timestamp;
            public uint stringsSize;
            public ushort ordinalHint;
            public ushort type;

            public ImportType ImportType => (ImportType)(this.type & 0x3);
            public NameType NameType => (NameType)((this.type & 0x1c) >> 2);
            public MachineType MachineType => (MachineType)this.machine;
        }

        [StructLayout(LayoutKind.Sequential, Pack = 1, CharSet = CharSet.Ansi)]
        private unsafe struct ArchiveHeader
        {
            private const int NameLength = 16;
            private const int SizeLength = 10;

            public fixed byte name[NameLength];
            public fixed byte date[12];
            public fixed byte userId[6];
            public fixed byte groupId[6];
            public fixed byte mode[8];
            public fixed byte size[SizeLength];
            public fixed byte end[2];

            public string Name
            {
                get
                {
                    fixed (byte* pName = this.name)
                    {
                        return ReadString(pName, NameLength);
                    }
                }
            }

            public int ArchiveSize
            {
                get
                {
                    fixed (byte* pSize = this.size)
                    {
                        string textSize = ReadString(pSize, SizeLength);
                        return int.Parse(textSize);
                    }
                }
            }

            public bool IsValid
            {
                get
                {
                    return this.end[0] == 0x60 && this.end[1] == 0xa;
                }
            }

            private static string ReadString(byte* data, int maxLength)
            {
                StringBuilder ret = new StringBuilder();
                for (int i = 0; i < maxLength; i++)
                {
                    byte current = data[i];
#pragma warning disable CA1508
                    if (current == 0x20)
#pragma warning restore CA1508
                    {
                        break;
                    }

                    ret.Append((char)current);
                }

                return ret.ToString();
            }
        }

        /// <summary>
        /// Converts a byte array to a struct.
        /// </summary>
        /// <typeparam name="T">Type of the structure.</typeparam>
        /// <param name="buffer">byte array that will be converted.</param>
        /// <returns>Structure of type T</returns>
        private static T GetStructFromBytes<T>(byte[] buffer)
        {
            GCHandle handle = GCHandle.Alloc(buffer, GCHandleType.Pinned);

            try
            {
                return (T)Marshal.PtrToStructure(handle.AddrOfPinnedObject(), typeof(T));
            }
            finally
            {
                handle.Free();
            }
        }
    }
}
