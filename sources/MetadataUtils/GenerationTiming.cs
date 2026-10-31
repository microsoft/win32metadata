using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text.Json;
using System.Threading;

namespace MetadataUtils
{
    public static class GenerationTiming
    {
        public const string EnvironmentVariable = "WIN32METADATA_TIMING_DIRECTORY";
        private static readonly AsyncLocal<Session> current = new();

        public static Session StartFromEnvironment(string tool)
        {
            string directory = Environment.GetEnvironmentVariable(EnvironmentVariable);
            if (string.IsNullOrEmpty(directory))
                return null;
            if (string.IsNullOrWhiteSpace(directory) || !Path.IsPathFullyQualified(directory) ||
                directory.StartsWith(@"\\", StringComparison.Ordinal))
                throw new ArgumentException($"{EnvironmentVariable} must name an absolute local output directory.");
            if (string.IsNullOrEmpty(tool) || tool.Any(character =>
                !char.IsAsciiLetterOrDigit(character) && character is not '-' and not '_'))
                throw new ArgumentException("A timing tool name must contain only ASCII letters, digits, '-' or '_'.", nameof(tool));
            if (current.Value != null)
                throw new InvalidOperationException("A generation timing session is already active in this execution context.");

            var session = new Session(tool, directory);
            current.Value = session;
            return session;
        }

        public static Span BeginSpan(string name) => current.Value?.BeginSpan(name);

        public static void SetContext(string name, string value) => current.Value?.Context.Add(name, value);

        public sealed class Session : IDisposable
        {
            private readonly string tool;
            private readonly DateTime startedUtc = DateTime.UtcNow;
            private readonly Process process;
            private readonly FileStream output;
            private readonly long epoch;
            private readonly List<Span> spans = new();
            private readonly Span root;
            private Span activeSpan;
            private int? exitCode;
            private bool disposed;

            internal Dictionary<string, string> Context { get; } = new(StringComparer.Ordinal);
            internal long CpuTicks => process.TotalProcessorTime.Ticks;
            internal long Epoch => epoch;
            internal Span ActiveSpan { get => activeSpan; set => activeSpan = value; }
            public string OutputPath { get; }

            internal Session(string tool, string directory)
            {
                this.tool = tool;
                Directory.CreateDirectory(directory);
                OutputPath = Path.Combine(directory,
                    $"{tool}-{Environment.ProcessId}-{Guid.NewGuid():N}.timing.json");
                process = Process.GetCurrentProcess();
                try
                {
                    output = new FileStream(OutputPath, FileMode.CreateNew, FileAccess.Write, FileShare.Read);
                    epoch = Stopwatch.GetTimestamp();
                    root = BeginSpan(tool);
                }
                catch
                {
                    output?.Dispose();
                    process.Dispose();
                    throw;
                }
            }

            public void Complete(int result) => exitCode = result;

            internal Span BeginSpan(string name)
            {
                if (disposed)
                    throw new ObjectDisposedException(nameof(Session));
                var span = new Span(this, activeSpan, spans.Count + 1, name);
                spans.Add(span);
                activeSpan = span;
                return span;
            }

            public void Dispose()
            {
                if (disposed)
                    return;
                try
                {
                    if (activeSpan != root || current.Value != this)
                        throw new InvalidOperationException("Generation timing spans must close in their original nested order.");
                    root.Dispose();
                    JsonSerializer.Serialize(output, new
                    {
                        schemaVersion = 1,
                        tool,
                        processId = Environment.ProcessId,
                        startedUtc,
                        exitCode,
                        context = Context,
                        cpuScope = "all-process-threads",
                        spans = spans.Select(span => span.Data).ToArray(),
                    }, new JsonSerializerOptions
                    {
                        PropertyNamingPolicy = JsonNamingPolicy.CamelCase,
                        WriteIndented = true,
                    });
                    output.Flush();
                }
                finally
                {
                    disposed = true;
                    current.Value = null;
                    output.Dispose();
                    process.Dispose();
                }
            }
        }

        public sealed class Span : IDisposable
        {
            private readonly Session owner;
            private readonly Span parent;
            private readonly long started;
            private readonly long cpuStarted;
            private long childWallTicks;
            private long childCpuTicks;
            private bool disposed;
            internal SpanData Data { get; }

            internal Span(Session owner, Span parent, int id, string name)
            {
                this.owner = owner;
                this.parent = parent;
                started = Stopwatch.GetTimestamp();
                cpuStarted = owner.CpuTicks;
                Data = new SpanData
                {
                    Id = id,
                    ParentId = parent?.Data.Id,
                    Name = name,
                    StartedMilliseconds = Milliseconds(started - owner.Epoch),
                };
            }

            public void SetCounter(string name, long value)
            {
                if (value < 0)
                    throw new ArgumentOutOfRangeException(nameof(value), "Timing counters must be nonnegative.");
                if (disposed)
                    throw new ObjectDisposedException(nameof(Span));
                Data.Counters[name] = value;
            }

            public void Dispose()
            {
                if (disposed)
                    return;
                if (owner.ActiveSpan != this)
                    throw new InvalidOperationException("Generation timing spans must close in their original nested order.");
                long cpuTicks = owner.CpuTicks - cpuStarted;
                long wallTicks = Stopwatch.GetTimestamp() - started;
                Data.WallMilliseconds = Milliseconds(wallTicks);
                Data.ProcessCpuMilliseconds = TimeSpan.FromTicks(cpuTicks).TotalMilliseconds;
                Data.ChildWallMilliseconds = Milliseconds(childWallTicks);
                Data.SelfWallMilliseconds = Milliseconds(wallTicks - childWallTicks);
                Data.SelfProcessCpuMilliseconds = TimeSpan.FromTicks(cpuTicks - childCpuTicks).TotalMilliseconds;
                if (parent != null)
                {
                    parent.childWallTicks += wallTicks;
                    parent.childCpuTicks += cpuTicks;
                }
                owner.ActiveSpan = parent;
                disposed = true;
            }

            private static double Milliseconds(long ticks) => ticks * 1000.0 / Stopwatch.Frequency;
        }

        internal sealed class SpanData
        {
            public int Id { get; init; }
            public int? ParentId { get; init; }
            public string Name { get; init; }
            public double StartedMilliseconds { get; init; }
            public double WallMilliseconds { get; set; }
            public double ProcessCpuMilliseconds { get; set; }
            public double ChildWallMilliseconds { get; set; }
            public double SelfWallMilliseconds { get; set; }
            public double SelfProcessCpuMilliseconds { get; set; }
            public Dictionary<string, long> Counters { get; } = new(StringComparer.Ordinal);
        }
    }
}
