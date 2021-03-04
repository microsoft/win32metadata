using System;

namespace Windows.Win32.WindowsDeploymentServices
{
    public enum PFN_WdsCliCallback_dwMessageIdFlags
    {
        WDS_CLI_MSG_START = 0,
        WDS_CLI_MSG_COMPLETE = 1,
        WDS_CLI_MSG_PROGRESS = 2,
        WDS_CLI_MSG_TEXT = 3
    }
}