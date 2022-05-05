using System;
using System.Collections.Generic;
using System.Linq;
using ICSharpCode.Decompiler.TypeSystem;

namespace MetadataUtils
{
    public static class ExtensionClass
    {
        // Extension method to append the element
        public static T[] Append<T>(this T[] array, T item)
        {
            List<T> list = new List<T>(array);
            list.Add(item);

            return list.ToArray();
        }
    }

    public static class NamespaceDependencyUtil
    {
        public static IEnumerable<DependenciesInNamespace> GetNamespaceDependencies(string winmdFileName)
        {
            GetNamespaceDependenciesImpl impl = new();
            return impl.GetNamespaceDependencies(winmdFileName);
        }

        public static Dictionary<string, IEnumerable<string>> GetNamespaceToDependencyNamespaces(string winmdFileName)
        {
            Dictionary<string, IEnumerable<string>> namespaceToDepends = new();

            foreach (var dependsInNamespace in GetNamespaceDependencies(winmdFileName))
            {
                namespaceToDepends.Add(dependsInNamespace.Namespace, dependsInNamespace.GetDependenciesByNamespace().Select(p => p.Key));
            }

            return namespaceToDepends;
        }

        private class GetNamespaceDependenciesImpl
        {
            private Dictionary<string, DependenciesInNamespace> namespacesToDepends = new();

            public IEnumerable<DependenciesInNamespace> GetNamespaceDependencies(string winmdFileName)
            {
                DecompilerTypeSystem winmd1 = DecompilerTypeSystemUtils.CreateTypeSystemFromFile(winmdFileName);

                foreach (var type1 in winmd1.GetTopLevelTypeDefinitions())
                {
                    if (type1.FullName == "<Module>")
                    {
                        continue;
                    }

                    if (type1.ParentModule != winmd1.MainModule)
                    {
                        continue;
                    }

                    var typeNamespace = type1.Namespace;
                    if (!this.namespacesToDepends.TryGetValue(typeNamespace, out var depends))
                    {
                        depends = new(typeNamespace);
                        this.namespacesToDepends[typeNamespace] = depends;
                    }

                    if (type1.Kind == TypeKind.Struct)
                    {
                        foreach (var field in type1.GetFields())
                        {
                            string broughtInBy = $"{type1.Name}.{field.Name}";
                            this.AddTypeDependency(type1, depends, broughtInBy, field.Type);
                        }
                    }
                    else if (type1.Kind == TypeKind.Class && type1.Name == "Apis")
                    {
                        foreach (var method in type1.GetMethods().Where(m => m.IsStatic && m.DeclaringType == type1))
                        {
                            string returnBroughtInBy = $"{method.Name}::return";
                            this.AddTypeDependency(type1, depends, returnBroughtInBy, method.ReturnType);

                            foreach (var p in method.Parameters)
                            {
                                string paramBroughtInBy = $"{method.Name}(...{p.Name}...)";
                                this.AddTypeDependency(type1, depends, paramBroughtInBy, p.Type);
                            }
                        }
                    }
                    else if (type1.Kind == TypeKind.Interface)
                    {
                        foreach (var directBaseType in type1.DirectBaseTypes)
                        {
                            if (directBaseType.FullName == "System.Object")
                            {
                                continue;
                            }

                            string inheritBroughtInBy = $"{type1.Name} inherits";
                            this.AddTypeDependency(type1, depends, inheritBroughtInBy, directBaseType);
                        }

                        foreach (var method in type1.GetMethods().Where(m => m.DeclaringType == type1))
                        {
                            string returnBroughtInBy = $"{type1.Name}::{method.Name}::return";
                            this.AddTypeDependency(type1, depends, returnBroughtInBy, method.ReturnType);

                            foreach (var p in method.Parameters)
                            {
                                string paramBroughtInBy = $"{type1.Name}::{method.Name}(...{p.Name}...)";
                                this.AddTypeDependency(type1, depends, paramBroughtInBy, p.Type);
                            }
                        }
                    }
                }

                var finalDepends = this.namespacesToDepends.Values.OrderBy(d => d.Namespace);

                Dictionary<string, IEnumerable<string>> namespaceToDepends = new();

                foreach (var dependsInNamespace in finalDepends)
                {
                    namespaceToDepends.Add(dependsInNamespace.Namespace, dependsInNamespace.GetDependenciesByNamespace().Select(p => p.Key));
                }

                foreach (var dependsInNamespace in finalDepends)
                {
                    dependsInNamespace.LoadAllDependendencyNamespaces(namespaceToDepends);
                }

                return finalDepends;
            }

            private void AddTypeDependency(ITypeDefinition ownerType, DependenciesInNamespace depends, string broughtInBy, IType memberType)
            {
                var currentType = memberType;
                while (currentType.Kind == TypeKind.Array)
                {
                    ArrayType arrayType = (ArrayType)currentType;
                    currentType = arrayType.ElementType;
                }

                while (currentType.Kind == TypeKind.Pointer)
                {
                    PointerType pointerType = (PointerType)currentType;
                    currentType = pointerType.ElementType;
                }

                if (currentType is IEntity entity)
                {
                    if (entity.ParentModule != ownerType.ParentModule)
                    {
                        return;
                    }

                    var fieldNamespace = memberType.Namespace;
                    if (fieldNamespace != ownerType.Namespace)
                    {
                        depends.AddTypeDependency(broughtInBy, currentType);
                    }
                }
            }
        }
    }

    public class DependenciesInNamespace
    {
        private Dictionary<string, Dictionary<IType, Dependency>> namespacesToDepends = new();
        private string[] allDependencyNamespaces;
        private string[] cyclicalDependencyNamespaces;

        public DependenciesInNamespace(string ns)
        {
            this.Namespace = ns;
        }

        public string Namespace { get; }

        public IEnumerable<KeyValuePair<string, IEnumerable<Dependency>>> GetDependenciesByNamespace()
        {
            foreach (var pair in this.namespacesToDepends.OrderBy(p => p.Key))
            {
                yield return new KeyValuePair<string, IEnumerable<Dependency>>(pair.Key, pair.Value.Values);
            }
        }

        public IEnumerable<string> AllDependencyNamespaces => this.allDependencyNamespaces;
        public IEnumerable<string> CyclicalDependencyNamespaces => this.cyclicalDependencyNamespaces;

        internal void AddTypeDependency(string broughtInBy, IType type)
        {
            string typeNamespace = type.Namespace;
            if (!this.namespacesToDepends.TryGetValue(typeNamespace, out var dependsHash))
            {
                dependsHash = new();
                this.namespacesToDepends[typeNamespace] = dependsHash;
            }

            if (!dependsHash.TryGetValue(type, out var dependency))
            {
                dependency = new Dependency(type);
                dependsHash.Add(type, dependency);
            }

            dependency.AddBroughtInBy(broughtInBy);
        }

        internal void LoadAllDependendencyNamespaces(Dictionary<string, IEnumerable<string>> namespaceToDepends)
        {
            HashSet<string> dependencyNamespaces = new();
            List<string> cyclicalDepends = new List<string>();

            foreach (var directNamespace in this.namespacesToDepends.Keys)
            {
                VisitNamespace(directNamespace, dependencyNamespaces, cyclicalDepends);
            }

            void VisitNamespace(string ns, HashSet<string> dependencyNamespaces, List<string> cyclicalDepends)
            {
                if (!dependencyNamespaces.Contains(ns))
                {
                    dependencyNamespaces.Add(ns);

                    foreach (var dependNamespace in namespaceToDepends[ns])
                    {
                        if (dependNamespace == this.Namespace)
                        {
                            cyclicalDepends.Add(ns);
                        }
                        else
                        {
                            VisitNamespace(dependNamespace, dependencyNamespaces, cyclicalDepends);
                        }
                    }
                }
            }

            this.allDependencyNamespaces = dependencyNamespaces.ToArray();
            this.cyclicalDependencyNamespaces = cyclicalDepends.ToArray();
        }
    }

    public class Dependency
    {
        private readonly List<string> broughtInBy = new List<string>();

        public Dependency(IType type)
        {
            this.Type = type;
        }

        public IEnumerable<string> BroughtInBy => this.broughtInBy;

        public void AddBroughtInBy(string name) => this.broughtInBy.Add(name);

        public IType Type { get; }
    }
}
