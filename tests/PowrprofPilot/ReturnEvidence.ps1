# Comparison evidence only. Production generation never reads this file.
[ordered]@{
    symbol='PowerReplaceDefaultPowerSchemes'
    url='https://learn.microsoft.com/en-us/windows/win32/api/powrprof/nf-powrprof-powerreplacedefaultpowerschemes'
    retrieved='2026-09-18'
    documentCommit='9267262487657894a8af112d7165006fed5035a7'
    section='Return value'
    quote='Returns ERROR_SUCCESS (zero) if the call was successful, and a nonzero value if the call failed.'
    inference='The documented ERROR_SUCCESS zero-success/nonzero-failure convention supports a Windows error association; it does not assert an exhaustive set of possible return values.'
}
foreach($symbol in @('PowerReadDCValueIndex','PowerReadACDefaultIndex','PowerReadDCDefaultIndex',
    'PowerWriteACDefaultIndex','PowerWriteDCDefaultIndex')){
    [ordered]@{
        symbol=$symbol
        url="https://learn.microsoft.com/en-us/windows/win32/api/powrprof/nf-powrprof-$($symbol.ToLowerInvariant())"
        retrieved='2026-09-18'
        documentCommit='1dd8e193c3021a3ff39c5f80644df3fdc538c835'
        section='Return value'
        quote='Returns ERROR_SUCCESS (zero) if the call was successful, and a nonzero value if the call failed.'
        inference='The documented ERROR_SUCCESS zero-success/nonzero-failure convention supports a Windows error association; it does not assert an exhaustive set of possible return values.'
    }
}
