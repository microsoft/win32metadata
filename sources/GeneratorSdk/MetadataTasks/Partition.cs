using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using Microsoft.Build.Framework;

namespace MetadataTasks
{
    public class Partition
    {
        private readonly ITaskItem item;
        private string root;
        private string sdkIncRoot;
        private string fullPath;

        private string ns;
        private string[] traverseFiles;
        private object syncLock = new object();

        private Partition(ITaskItem item, string root, string sdkIncRoot)
        {
            this.item = item;
            this.root = root;
            this.sdkIncRoot = sdkIncRoot;
        }

        public ITaskItem TaskItem => this.item;

        public bool ForceOutOfDate { get; set; }

        public string Name
        {
            get
            {
                var ret = this.item.GetMetadata("Name");
                if (string.IsNullOrEmpty(ret))
                {
                    ret = this.Namespace;
                }

                return ret;
            }
        }

        public bool ExcludeFromCrossarch
        {
            get
            {
                var propValue = this.item.GetMetadata("ExcludeFromCrossarch");
                if (!string.IsNullOrEmpty(propValue))
                {
                    return propValue == "true" || propValue == "1";
                }

                return false;
            }
        }

        public string Namespace
        {
            get
            {
                if (this.ns == null)
                {
                    var ns = this.item.GetMetadata("Namespace");
                    if (string.IsNullOrEmpty(ns))
                    {
                        ns = this.GetSettingsValues("--namespace").Single();
                    }

                    lock (this.syncLock)
                    {
                        this.ns = ns;
                    }
                }

                return this.ns;
            }
        }

        public string FullPath
        {
            get
            {
                if (this.fullPath == null)
                {
                    var path = TaskUtils.GetFullPath(this.item.ItemSpec, this.root);
                    lock (this.syncLock)
                    {
                        this.fullPath = path;
                    }
                }

                return this.fullPath;
            }
        }

        public IEnumerable<string> AllFiles
        {
            get
            {
                List<string> files = new List<string>();
                files.Add(this.FullPath);

                var settingsFile = this.SettingsFile;
                if (settingsFile != null)
                {
                    files.Add(settingsFile);
                }

                return files.Concat(this.TraverseFiles);
            }
        }

        public string SettingsFile
        {
            get
            {
                var ret = Path.Combine(Path.GetDirectoryName(this.FullPath), "settings.rsp");
                return File.Exists(ret) ? ret : null;
            }
        }

        public IEnumerable<string> TraverseFiles
        {
            get
            {
                if (this.traverseFiles == null)
                {
                    var files = new List<string>(this.item.GetFilesFromMetadata("TraverseFiles", this.root));

                    string settingsFile = this.SettingsFile;
                    if (settingsFile != null)
                    {
                        foreach (var traverseLine in RspReader.GetSettingsValues(settingsFile, "--traverse"))
                        {
                            var fixedLine = traverseLine.Replace("<IncludeRoot>", this.sdkIncRoot);
                            fixedLine = fixedLine.Replace("<PartitionDir>", Path.GetDirectoryName(this.FullPath));
                            files.Add(fixedLine);
                        }
                    }

                    lock (this.syncLock)
                    {
                        this.traverseFiles = files.ToArray();
                    }
                }

                return this.traverseFiles;
            }
        }

        public static Partition FromTaskItem(ITaskItem item, string root, string sdkIncRoot)
        {
            return new Partition(item, root, sdkIncRoot);
        }

        public static IEnumerable<Partition> FromTaskItems(IEnumerable<ITaskItem> items, string root, string sdkIncRoot)
        {
            foreach (ITaskItem item in items)
            {
                yield return FromTaskItem(item, root, sdkIncRoot);
            }
        }

        public override string ToString()
        {
            return this.Name;
        }

        public override int GetHashCode()
        {
            return this.Name.GetHashCode(StringComparison.OrdinalIgnoreCase);
        }

        public bool IsUpToDate(string markerFile)
        {
            return !this.ForceOutOfDate && TaskUtils.IsUpToDate(this.AllFiles, markerFile);
        }

        private IEnumerable<string> GetSettingsValues(string name)
        {
            string settingsFile = Path.Combine(Path.GetDirectoryName(this.FullPath), "settings.rsp");
            if (File.Exists(settingsFile))
            {
                return RspReader.GetSettingsValues(settingsFile, name);
            }

            return Array.Empty<string>();
        }
    }
}
