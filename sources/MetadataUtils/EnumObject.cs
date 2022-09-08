using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;

namespace MetadataUtils
{
    public class EnumObject
    {
        public static IEnumerable<EnumObject> LoadFromFile(string fileName)
        {
            string ext = Path.GetExtension(fileName);
            if (ext == ".cs")
            {
                return EnumObjFromCSharpDeserializer.DeserializeObjects(fileName);
            }
            else if (ext == ".json")
            {
                return Newtonsoft.Json.JsonConvert.DeserializeObject<JsonWrapper>(File.ReadAllText(fileName)).items;
            }
            else
            {
                throw new ArgumentException();
            }
        }

        public string @namespace { get; set; }
        public string type { get; set; }
        public bool finished { get; set; }
        public string name { get; set; }
        public string addUsesTo { get; set; }
        public bool flags { get; set; }
        public AutoPopulate autoPopulate { get; set; }
        public List<Member> members { get; } = new List<Member>();
        public List<Use> uses { get; } = new List<Use>();

        public override string ToString()
        {
            if (this.@namespace != null)
            {
                return $"{this.@namespace}.{this.name}";
            }
            else
            {
                if (this.name != null)
                {
                    return this.name;
                }
                else
                {
                    return $"first member : {this.members[0]}";
                }
            }
        }

        public class AutoPopulate
        {
            public string filter { get; set; }
            public string header { get; set; }
        }


        public class Member
        {
            public string name { get; set; }
            public string value { get; set; }

            public override string ToString()
            {
                if (this.value == null)
                {
                    return $"{this.name} = null";
                }
                else
                {
                    return $"{this.name} = {this.value}";
                }
            }
        }

        public class Use
        {
            public string @interface { get; set; }
            public string method { get; set; }
            public string parameter { get; set; }
            public string @struct { get; set; }
            public string field { get; set; }

            public override string ToString()
            {
                if (this.method != null)
                {
                    if (this.@interface != null)
                    {
                        return $"{this.@interface}::{this.method}::{this.parameter}";
                    }
                    else
                    {
                        return $"{this.method}::{this.parameter}";
                    }
                }
                else
                {
                    return $"{this.@struct}::{this.field}";
                }
            }
        }

        private static class EnumObjFromCSharpDeserializer
        {
            public static IEnumerable<EnumObject> DeserializeObjects(string sourceFile)
            {
                TreeWalker walker = new TreeWalker();
                return walker.GetEnumObjects(sourceFile);
            }

            private class TreeWalker : CSharpSyntaxWalker
            {
                private string currentNamespace;
                private List<EnumObject> enumObjects = new List<EnumObject>();

                public IEnumerable<EnumObject> GetEnumObjects(string fileName)
                {
                    var tree = CSharpSyntaxTree.ParseText(File.ReadAllText(fileName), null, fileName);
                    this.Visit(tree.GetRoot());

                    return this.enumObjects;
                }

                public override void VisitNamespaceDeclaration(NamespaceDeclarationSyntax node)
                {
                    this.currentNamespace = node.Name.ToString();

                    base.VisitNamespaceDeclaration(node);
                }

                public override void VisitEnumDeclaration(EnumDeclarationSyntax node)
                {
                    base.VisitEnumDeclaration(node);

                    EnumObject enumObject = new EnumObject();
                    enumObject.@namespace = this.currentNamespace;
                    enumObject.name = node.Identifier.ValueText;
                    enumObject.flags = node.AttributeLists.Any(list => list.Attributes.Any(attr => attr.Name.ToString().StartsWith("Flags")));
                    enumObject.FromCSharp = true;

                    foreach (EnumMemberDeclarationSyntax member in node.Members)
                    {
                        EnumObject.Member m = new EnumObject.Member();
                        m.name = member.Identifier.ValueText;

                        if (member.EqualsValue != null)
                        {
                            m.value = member.EqualsValue.Value.ToString();
                        }

                        enumObject.members.Add(m);
                    }

                    this.enumObjects.Add(enumObject);
                }
            }
        }

        private class JsonWrapper
        {
            public EnumObject[] items { get; set; }
        }

        public void AddUse(Use use)
        {
            var foundUse = this.uses.FirstOrDefault(u => u.ToString() == use.ToString());
            if (foundUse == null)
            {
                Use newUse = new Use() { field = use.field, @interface = use.@interface, method = use.method, parameter = use.parameter, @struct = use.@struct };
                this.uses.Add(newUse);
            }
        }

        private void AddMember(string name, string valueText)
        {
            this.members.Add(new Member() { name = name, value = valueText });
        }

        public void AddIfNotSet(string name, string valueText)
        {
            var member = this.members.FirstOrDefault(m => m.name == name);
            if (member == null)
            {
                this.AddMember(name, valueText);
            }
            else
            {
                if (string.IsNullOrEmpty(member.value))
                {
                    member.value = valueText;
                }
            }
        }

        public void AddOrUpdateMember(string name, string valueText)
        {
            if (!this.UpdateMember(name, valueText))
            {
                this.AddMember(name, valueText);
            }
        }

        [Newtonsoft.Json.JsonIgnore]
        public bool CanOverrideValue => this.autoPopulate == null;

        [Newtonsoft.Json.JsonIgnore]
        public bool FromCSharp { get; set; }

        public bool UpdateMember(string name, string valueText)
        {
            if (this.finished || string.IsNullOrEmpty(valueText))
            {
                return true;
            }

            for (int i = 0; i < this.members.Count; i++)
            {
                if (this.members[i].name == name)
                {
                    if (this.CanOverrideValue || string.IsNullOrEmpty(this.members[i].value))
                    {
                        this.members[i].value = valueText;
                    }

                    return true;
                }
            }

            return false;
        }
    }
}
