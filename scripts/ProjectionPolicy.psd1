@{
    Id = 'win32-projection'
    Version = '1.0.0'
    Approval = @{
        Id = 'user-2026-09-18T14:00:44-07:00'
        Timestamp = '2026-09-18T14:00:44-07:00'
        RelayedBy = '86e8578e-2ddd-45d2-886f-16252f02ec2c'
        Scope = 'Comparison only; no native rewrites or third-party projection implementation claim.'
        Decision = 'Actual SDK GUID and System.Guid are projection-equivalent; same-level Const PWSTR and PCWSTR are equivalent; source-backed REGSAM is an expected native typedef improvement over UInt32.'
    }
    Rules = @{
        Guid = @{ Id = 'sdk-guid-system-guid/v1'; Classification = 'projection-equivalent' }
        ConstString = @{ Id = 'utf16-const-pwstr-pcwstr/v1'; Classification = 'projection-equivalent' }
        Regsam = @{ Id = 'native-regsam-uint32/v1'; Classification = 'expected-improvement' }
    }
}
