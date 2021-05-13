using System.Collections.Generic;
using System.Linq;
using System.Text.RegularExpressions;

namespace MetadataUtils
{
    public class WildcardDictionary
    {
        private Dictionary<string, string> items;
        private List<WildcardInfo> wildcards = new List<WildcardInfo>();

        public WildcardDictionary(Dictionary<string, string> items)
        {
            this.items = new Dictionary<string, string>(items);
            foreach (var item in this.items.Where(i => i.Key.Contains('*')))
            {
                wildcards.Add(new WildcardInfo(item.Key, item.Value));
            }
        }

        public bool TryGetValue(string key, out string value)
        {
            bool found = false;

            if (!this.items.TryGetValue(key, out value))
            {
                foreach (var wc in wildcards)
                {
                    if (wc.IsMatch(key))
                    {
                        value = wc.Value;
                        return true;
                    }
                }
            }
            else
            {
                found = true;
            }

            return found;
        }

        private class WildcardInfo
        {
            private Regex regx;

            public WildcardInfo(string key, string value)
            {
                string fixedKey = key.Replace("*", ".*");
                string pattern = $"^{fixedKey}";

                this.regx = new Regex(pattern);
                this.Value = value;
            }

            public bool IsMatch(string text)
            {
                return this.regx.IsMatch(text);
            }

            public string Value { get; private set; }
        }
    }
}
