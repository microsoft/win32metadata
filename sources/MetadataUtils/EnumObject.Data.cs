#nullable enable
using System.Collections.Generic;

namespace MetadataUtils
{
    public partial class EnumObject
    {
        public string? @namespace { get; set; }
        public string? type { get; set; }
        public bool finished { get; set; }
        public string? name { get; set; }
        public string? addUsesTo { get; set; }
        public bool flags { get; set; }
        public AutoPopulate? autoPopulate { get; set; }
        public List<Member> members { get; } = new List<Member>();
        public List<Use> uses { get; } = new List<Use>();

        public class AutoPopulate
        {
            public string? filter { get; set; }
            public string? header { get; set; }
        }

        public class Member
        {
            public string? name { get; set; }
            public string? value { get; set; }

            public override string ToString()
            {
                if (this.value == null)
                {
                    return $"{this.name} = null";
                }

                return $"{this.name} = {this.value}";
            }
        }

        public class Use
        {
            public string? @interface { get; set; }
            public string? method { get; set; }
            public string? parameter { get; set; }
            public string? @struct { get; set; }
            public string? field { get; set; }

            public override string ToString()
            {
                if (this.method != null)
                {
                    if (this.@interface != null)
                    {
                        return $"{this.@interface}::{this.method}::{this.parameter}";
                    }

                    return $"{this.method}::{this.parameter}";
                }

                return $"{this.@struct}::{this.field}";
            }
        }
    }
}
