using Microsoft.CodeAnalysis;

namespace ClangSharpSourceToWinmd
{
    public class GeneratorDiagnostic
    {
        public GeneratorDiagnostic(string message, DiagnosticSeverity severity)
        {
            this.Message = message;
            this.Severity = severity;
        }

        public override string ToString() => $"{this.Severity}: {this.Message}";

        public string Message { get; }

        public DiagnosticSeverity Severity { get; }
    }
}
