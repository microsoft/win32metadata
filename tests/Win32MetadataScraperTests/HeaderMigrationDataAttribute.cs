using System;
using System.IO;
using System.Linq;
using Xunit;

namespace Win32MetadataScraperTests
{
    public class HeaderMigrationDataFactAttribute : FactAttribute
    {
        public HeaderMigrationDataFactAttribute()
        {
            if (!File.Exists(HeaderMigrationAssertions.RecipePath))
                Skip = HeaderMigrationAssertions.MissingDataReason;
        }
    }

    public class HeaderMigrationDataTheoryAttribute : TheoryAttribute
    {
        public HeaderMigrationDataTheoryAttribute(params string[] requiredFixtures)
        {
            if (!File.Exists(HeaderMigrationAssertions.RecipePath))
                Skip = HeaderMigrationAssertions.MissingDataReason;
            else if (requiredFixtures.Any(name => Environment.GetEnvironmentVariable(name) == null))
                Skip = "Set " + string.Join(", ", requiredFixtures) + " to the pinned metadata fixtures.";
        }
    }
}
